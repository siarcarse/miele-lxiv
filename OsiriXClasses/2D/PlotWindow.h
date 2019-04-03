//
//  ©Alex Bettarini -- all rights reserved
//  License GPLv3.0 -- see License File
//
//  At the end of 2014 the project was forked from OsiriX to become Miele-LXIV
//  The original header follows:
/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/

#import <AppKit/AppKit.h>
#import "ROI.h"
#import "PlotView.h"

/** \brief  Window Controller for Plot */

@interface PlotWindow : NSWindowController {
	
	ROI						*curROI;
	
	float					*data, maxValue, minValue;
	long					dataSize;
	
	IBOutlet PlotView		*plot;
	IBOutlet NSTextField	*maxX, *minY, *maxY, *sizeT;
}

- (id) initWithROI: (ROI*) iroi;
- (ROI*) curROI;
@end
