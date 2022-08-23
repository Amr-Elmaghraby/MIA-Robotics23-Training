# Importing libraries
import cv2        
import numpy as np  
import matplotlib.pyplot as plt 

# Creating shape class 
class shape:
    # Creating instructor
    def __init__(self) -> None:
        pass

    # Creating fn taking gray and rgb_img from main
    def getshape(self,gray,rgb_img):
        # Creating threshold of gray image
        _, threshold= cv2.threshold(gray,240,255,cv2.THRESH_BINARY)
        # Creating Contours for shapes
        contours,_ = cv2.findContours(threshold,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
        # Looping to get the shapes and naming them
        for c in contours:
            # Getting area of contours to neglect the contour of the whole image 
            # and the two lines and if there is any errors in readings
            cArea=cv2.contourArea(c)
            if (cArea<200 or cArea>50000):
               continue
            # Aprroximating the shape
            app=cv2.approxPolyDP(c,0.01 * cv2.arcLength(c,True),True)
            # Getting the boundingRect to type shape name 
            (x,y,w,h)=cv2.boundingRect(app)
            # Putting shape name at the top of it
            if (len(app)== 3):
                # Changing y to edit the text on traingle
                y=y+10
                cv2.putText(rgb_img,'Triangle',(x,y),
                    cv2.FONT_HERSHEY_SIMPLEX,0.8,(0,0,0),2)
            elif (len(app)== 4):
                if((1.1>float(w)/h>0.8)):
                    # This if is special for the green square in the img2 to edit its x,y
                    if(w==226):
                        x=x+70
                        y=y+50
                    cv2.putText(rgb_img,'Square',(x,y),
                    cv2.FONT_HERSHEY_SIMPLEX,0.8,(0,0,0),2)
                else:
                    #editting x of the rectangulars
                    x=x-20
                    cv2.putText(rgb_img,'Rectangle',(x,y),
                    cv2.FONT_HERSHEY_SIMPLEX,0.8,(0,0,0),2)
            else :
                # Changing x to edit text on circle
                x=x+60
                cv2.putText(rgb_img,'circle',(x,y),
                cv2.FONT_HERSHEY_SIMPLEX,0.8,(0,0,0),2)



    # fn for detecting direction of the road
    def Lines(self,rgb_img):
        #Setting lower and upper values for detecting the lines
        lower=np.array([40,40,40],dtype=np.uint8)
        upper=np.array([50,50,50],dtype=np.uint8)
        Lines=cv2.inRange(rgb_img,lower,upper)
        # Creating Contours to detect the lines to know the directions
        contL, _ = cv2.findContours(
            Lines, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        # Getting x,y,w,h of the two lines
        (xi,yi,wi,hi)=cv2.boundingRect(contL[0])
        (xv,yv,wv,hv)=cv2.boundingRect(contL[1])
        # Checking if the line with the bigger x is bigger at width 
        #then its right direction
        if(xi>xv and wi>wv):
            cv2.putText(rgb_img, 'Right', (600,65 ),
                        cv2.FONT_HERSHEY_SIMPLEX, 2.5, (100, 60,0), 6)
        # IF the line with the small x is higher at width then its left direction               
        elif(xi<xv and wi>wv):
            cv2.putText(rgb_img, 'Left', (500, 80),
                    cv2.FONT_HERSHEY_SIMPLEX, 2.5, (100, 130,120), 6)
        # Both have the same width then its straight
        else:
            cv2.putText(rgb_img, 'Straight', (310, 50),
                            cv2.FONT_HERSHEY_SIMPLEX, 1.5, (40, 40,100), 6)


        











    
