# Importing libraries
import cv2        
import numpy as np  
import matplotlib.pyplot as plt
# Importing shape class
from shape import shape
# Creating shapeObj as object in the shape class 
shapeObj=shape() 
# Importing color class
from color import color
# Creating colorObj as object in the shape class 
colorObj=color() 

#cv2.namedWindow("shape", cv2.WINDOW_NORMAL)
# Reading image
img=cv2.imread('Task Pictures/test3.png')
# Converting image into rgb image
rgb_img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
# Converting image into grayscale
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
# Calling getcolor fn from color class
colorObj.getcolor(rgb_img)
# # Calling getshape fn from shape class
shapeObj.getshape(gray,rgb_img)
# Calling getshape fn from shape class
shapeObj.Lines(rgb_img)

#Plotting rgb_img after adding labels for color, shape and direction
plt.figure(figsize=(10,6))
plt.imshow(rgb_img)
plt.waitforbuttonpress(0)

