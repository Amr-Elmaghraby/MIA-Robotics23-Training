# Importing libraries
import cv2        
import numpy as np  
import matplotlib.pyplot as plt 

# class for colors
class color:
    # Creating instrutor
    def __init__(self) -> None:
        pass
    # Fn to get the color
    def getcolor(self,rgb_img):
        # Detecting colors
        # Detecting red, green, blue, yellow
        lower=np.array([[50,0,0],                      #lower red
                        [0,50,0],                      #lower green
                        [0,0,50],                      #lower blue
                        [50,50,0],],dtype=np.uint8)    #lower yellow
        upper=np.array([[255,50,50],                   #upper red
                        [50,255,50],                   #upper green
                        [50,50,255],                   #upper blue
                        [255,255,50],],dtype=np.uint8) #upper yellow
        color=np.array(['Red','Green','Blue','Yellow'])   # array to write label with
        # Looping with number of detected colors, Lines color is not included
        for i in range(4):
            # mask to get the each color of the chosen one 
            mask=cv2.inRange(rgb_img,lower[i],upper[i])
            #findContours to get contour of each color
            conColors,_ = cv2.findContours(mask,
                                    cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
            #Looping with number of contours neglecting errors 
            #with limit less than 200 and more than 10000
            for col in (conColors):
                aree=cv2.contourArea(col)
                if (aree<200 or aree>100000):
                    continue
                # finding center point of each shape
                M = cv2.moments(col)
                if M['m00'] != 0.0:
                    x = int(M['m10']/M['m00'])
                    y = int(M['m01']/M['m00'])
                    if(i==0):
                        y=y+15
                # Typing each color with its (i) from the color array
                cv2.putText(rgb_img,color[i], (x, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0,0,0), 2)

