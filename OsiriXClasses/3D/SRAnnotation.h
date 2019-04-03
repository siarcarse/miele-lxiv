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

#import <Cocoa/Cocoa.h>

#ifdef __cplusplus
#include "dcmtk/dcmsr/dsrdoc.h"
#else
typedef char DSRDocument;
#endif

#import "ROI.h"
#import "DicomImage.h"

@interface SRAnnotation : NSObject
{
	DSRDocument			*document;
	Dicom_Image          *image;
	BOOL				_newSR;
	NSString			*_seriesInstanceUID, *_DICOMSRDescription, *_DICOMSeriesNumber, *_reportURL;
	NSData				*_dataEncapsulated;
	NSDate				*_contentDate;
}

/** Extracts ROI as NSData from a DICOM SR
 * @param path File path
 */
+ (NSData *) roiFromDICOM:(NSString *)path;

/** Creates a DICOM SR from an array of ROIs
 * @param rois Array of ROI to archive
 * @param path Path to file 
 * @param image the image related to the ROI array
 */
+ (NSString*) archiveROIsAsDICOM:(NSArray *)rois toPath:(NSString *)path  forImage:(id)image;


+ (NSString*) getImageRefSOPInstanceUID:(NSString*) path;
+ (NSString*) getReportFilenameFromSR:(NSString*) path;

- (id) initWithROIs:(NSArray *)ROIs  path:(NSString *)path forImage:(NSManagedObject*) im;
- (id) initWithContentsOfFile:(NSString *)path;
- (id) initWithDictionary:(NSDictionary *) dict path:(NSString *) path forImage: (Dicom_Image*) im;
- (id) initWithWindowsState:(NSData *) dict path:(NSString *) path forImage: (Dicom_Image*) im;
- (id) initWithFileReport:(NSString *) file path:(NSString *) path forImage: (Dicom_Image*) im contentDate: (NSDate*) d;
- (id) initWithURLReport:(NSString *) s path:(NSString *) path forImage: (Dicom_Image*) im;
- (void) addROIs:(NSArray *)someROIs;
- (NSArray *) ROIs;
- (BOOL) writeToFileAtPath:(NSString *)path;
- (NSString *) seriesInstanceUID;
- (void) setSeriesInstanceUID: (NSString *)seriesInstanceUID;
- (NSString *) sopInstanceUID;
- (NSString *) sopClassUID;
- (NSString *) seriesDescription;
- (NSString *) seriesNumber;
- (NSData*) dataEncapsulated;
- (NSString*) reportURL;
- (NSDictionary*) annotations;
@end
