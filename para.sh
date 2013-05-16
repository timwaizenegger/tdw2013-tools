#!/bin/bash

>>> from paraview.simple import *
# Load the state
>>> servermanager.LoadState("/home/miller/Gtestes/ewoms/lens_immiscible.pvd")
# Make sure that the view in the state is the active one so we don't have to refer to it by name.
>>> SetActiveView(GetRenderView())
# Now render and save.
>>> Render()
>>> WriteImage("/home/miller/image.png")
