// Copyright 2008 Isis Innovation Limited
#include "System.h"
#include "OpenGL.h"
#include <gvars3/instances.h>
#include <stdlib.h>
#include "ATANCamera.h"
#include "MapMaker.h"
#include "Tracker.h"
#include "ARDriver.h"
#include "MapViewer.h"

using namespace CVD;
using namespace std;
using namespace GVars3;


System::System()
{
  
	ImageRef s(640, 480);
	
  mimFrameBW.resize(s);
  mimFrameRGB.resize(s);
  // First, check if the camera is calibrated.
  // If not, we need to run the calibration widget.
  Vector<NUMTRACKERCAMPARAMETERS> vTest;
  
  vTest = GV3::get<Vector<NUMTRACKERCAMPARAMETERS> >("Camera.Parameters", ATANCamera::mvDefaultParams, HIDDEN);
  mpCamera = new ATANCamera("Camera");
  Vector<2> v2;
  if(v2==v2) ;
  if(vTest == ATANCamera::mvDefaultParams)
    {
      cout << endl;
      cout << "! Camera.Parameters is not set, need to run the CameraCalibrator tool" << endl;
      cout << "  and/or put the Camera.Parameters= line into the appropriate .cfg file." << endl;
      exit(1);
    }
  
  mpMap = new Map;
  mpMapMaker = new MapMaker(*mpMap, *mpCamera);
  mpTracker = new Tracker(s, *mpCamera, *mpMap, *mpMapMaker);
 // mpARDriver = new ARDriver(*mpCamera, s, mGLWindow);
 // mpMapViewer = new MapViewer(*mpMap, mGLWindow);
    
  mbDone = false;
};

std::string System::doOneFrame(unsigned char *bwImage,uint hnd)
{
//gvar3<int> gvnDrawMap("DrawMap", 0, HIDDEN|SILENT), gvnDrawAR("DrawAR", 0, HIDDEN|SILENT);

      
      // We use two versions of each video frame:
      // One black and white (for processing by the tracker etc)
      // and one RGB, for drawing.

      // Grab new video frame...
   //   mVideoSource.GetAndFillFrameBWandRGB(mimFrameBW, mimFrameRGB);
	
	mimFrameBW.copy_from(BasicImage<byte>(bwImage,ImageRef(640,480)));
	
	
	
	static bool bFirstFrame = true;
      if(bFirstFrame)
	{
	 // mpARDriver->Init();
	  bFirstFrame = false;
	}
      
    /*  mGLWindow.SetupViewport();
      mGLWindow.SetupVideoOrtho();
      mGLWindow.SetupVideoRasterPosAndZoom();*/
      
      if(!mpMap->IsGood())
	//mpARDriver->Reset();
   //    bool bDrawMap = mpMap->IsGood() && *gvnDrawMap;
    //  bool bDrawAR = mpMap->IsGood() && *gvnDrawAR;
	
	
      mpTracker->TrackFrame(mimFrameBW,hnd, true);
      /*
      if(bDrawMap)
	mpMapViewer->DrawMap(mpTracker->GetCurrentPose());
      else if(bDrawAR)
	mpARDriver->Render(mimFrameRGB, mpTracker->GetCurrentPose());*/


      string sCaption;
     /* if(bDrawMap)
	sCaption = mpMapViewer->GetMessageForUser();
      else*/
	sCaption = mpTracker->GetMessageForUser();
    return sCaption;
}





