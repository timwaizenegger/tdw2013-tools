# -*- coding: utf-8 -*-

try: paraview.simple
except: from paraview.simple import *
import sys
import os
paraview.simple._DisableFirstRenderCameraReset()

os.system('clear') 

# Getting the desired color for the video
print("******------ Hallo! ------******")
print
print("		1 - Blue     | Blau")
print("		2 - Pink     | Rose")
print("		3 - White    | Weiß")
print("		4 - Yellow   | Gelb")
print("		5 - Grey     | Grau")
print("		6 - Green    | Grün")
print("		7 - Red      | Rot")
print
print('Choose the color | wählen Sie die Farbe: ')

try:
	colorForeground = sys.stdin.read(1)
except IOError: pass


# Reading the pvd file

lens_immiscible_pvd = PVDReader( FileName='/home/miller/Gtestes/ewoms/test/implicit/lens_immiscible.pvd' )

AnimationScene1 = GetAnimationScene()
AnimationScene1.EndTime = 30000.0
AnimationScene1.PlayMode = 'Snap To TimeSteps'

RenderView1 = GetRenderView()
RenderView1.CenterAxesVisibility = 0
RenderView1.OrientationAxesVisibility = 0

DataRepresentation1 = Show()
DataRepresentation1.ScaleFactor = 0.6000000000000001
DataRepresentation1.ScalarOpacityUnitDistance = 0.42170783541970913
DataRepresentation1.SelectionPointFieldDataArrayName = 'pressure_w'
DataRepresentation1.EdgeColor = [0.0, 0.0, 0.5000076295109483]

a1_pressure_w_PVLookupTable = GetLookupTableForArray( "pressure_w", 1, NanColor=[0.25, 0.0, 0.0], RGBPoints=[100000.0, 0.23, 0.299, 0.754, 100000.0, 0.706, 0.016, 0.15], VectorMode='Magnitude', ColorSpace='Diverging', ScalarRangeInitialized=1.0 )

a1_pressure_w_PiecewiseFunction = CreatePiecewiseFunction( Points=[0.0, 0.0, 0.5, 0.0, 1.0, 1.0, 0.5, 0.0] )

a1_relativePerm_n_PVLookupTable = GetLookupTableForArray( "relativePerm_n", 1, NanColor=[0.25, 0.0, 0.0], RGBPoints=[0.0, 0.23, 0.299, 0.754, 0.0, 0.706, 0.016, 0.15], VectorMode='Magnitude', ColorSpace='Diverging', ScalarRangeInitialized=1.0 )

a1_relativePerm_n_PiecewiseFunction = CreatePiecewiseFunction( Points=[0.0, 0.0, 0.5, 0.0, 1.0, 1.0, 0.5, 0.0] )

AnimationScene1.AnimationTime = 250.0

RenderView1.CacheKey = 250.0
RenderView1.CameraPosition = [3.0, 2.0, 13.930780379920632]
RenderView1.CameraClippingRange = [13.791472576121425, 14.139742085619442]
RenderView1.ViewTime = 250.0
RenderView1.UseCache = 1
RenderView1.CameraFocalPoint = [3.0, 2.0, 0.0]
RenderView1.CameraParallelScale = 3.605551275463989
RenderView1.CenterOfRotation = [3.0, 2.0, 0.0]

DataRepresentation1.ScalarOpacityFunction = a1_pressure_w_PiecewiseFunction
DataRepresentation1.ColorArrayName = 'pressure_w'
DataRepresentation1.LookupTable = a1_pressure_w_PVLookupTable

AnimationScene1.AnimationTime = 30000.0

RenderView1.ViewTime = 30000.0
RenderView1.CacheKey = 30000.0
RenderView1.UseCache = 1

RenderView1.UseCache = 0

DataRepresentation1.ScalarOpacityFunction = a1_relativePerm_n_PiecewiseFunction
DataRepresentation1.ColorArrayName = 'relativePerm_n'
DataRepresentation1.LookupTable = a1_relativePerm_n_PVLookupTable

def case_1():  #blue
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.008921490050852299, 0.3058823529411765, 0.7450980392156863, 1.0]
def case_2():  #pink
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.007870649918913841, 0.9294117647058824, 0.5607843137254902, 1.0]
def case_3():  #white
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.16862745098039217, 0.007870649918913841, 1.0, 1.0, 1.0]
def case_4():  #Yellow
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.007870649918913841, 0.9882352941176471, 0.9764705882352941, 0.20784313725490197]
def case_5():  #grey
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.007870649918913841, 0.8509803921568627, 0.8196078431372549, 0.8784313725490196]
def case_6():  #green
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.007870649918913841, 0.43529411764705883, 1.0, 0.12941176470588237]
def case_7():  #red
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 1.0, 1.0, 1.0, 0.007870649918913841, 0.8823529411764706, 0.24313725490196078, 0.11372549019607843]
def case_default():
    a1_relativePerm_n_PVLookupTable.RGBPoints = [0.0, 0.0, 0.0, 0.0, 0.008921490050852299, 0.3058823529411765, 0.7450980392156863, 1.0]


dict = {'1' : case_1, '2' : case_2, '3' : case_3, '4' : case_4, '5' : case_5, '6' : case_6, '7' : case_7}

#implementation of switch-case in python
def switch(x):
    try:
	a1_relativePerm_n_PVLookupTable.ColorSpace='RGB'
        dict[x]()
    except:
        case_default()

try:
	print colorForeground
	switch(colorForeground)
except:
	case_default()
print
print('Generating video...')


WriteAnimation('/home/miller/annn.avi', Magnification=1, Quality=2, FrameRate=4.000000)

Render()

os.system('clear') 

