PROJECT(Transform)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LIB_VERSION "1.1")
SET(LIB transform)

SET(SWF1_SRCS
    src/FSActionObject.cpp
    src/FSAction.cpp
    src/FSBitmapFill.cpp
    src/FSBounds.cpp
    src/FSButton.cpp
    src/FSCharacter.cpp
    src/FSColor.cpp
    src/FSColorTransform.cpp
    src/FSCoordTransform.cpp
    src/FSCurve.cpp
    src/FSDefineButton.cpp
    src/FSDefineFont.cpp
    src/FSDefineJPEGImage.cpp
    src/FSDefineObject.cpp
    src/FSDefineShape.cpp
    src/FSDefineSound.cpp
    src/FSDefineText.cpp
    src/FSDoAction.cpp
    src/FSEnvelope.cpp
    src/FSFillStyle.cpp
    src/FSFontInfo.cpp
    src/FSGetUrl.cpp
    src/FSGotoFrame.cpp
    src/FSGradient.cpp
    src/FSGradientFill.cpp
    src/FSInputStream.cpp
    src/FSJPEGEncodingTable.cpp
    src/FSLine.cpp
    src/FSLineStyle.cpp
    src/FSMovie.cpp
    src/FSMovieEvent.cpp
    src/FSMovieObject.cpp
    src/FSOutputStream.cpp
    src/FSPlaceObject.cpp
    src/FSRemoveObject.cpp
    src/FSSetBackgroundColor.cpp
    src/FSShape.cpp
    src/FSShapeObject.cpp
    src/FSShapeStyle.cpp
    src/FSShowFrame.cpp
    src/FSSolidFill.cpp
    src/FSSolidLine.cpp
    src/FSSound.cpp
    src/FSSoundStreamBlock.cpp
    src/FSSoundStreamHead.cpp
    src/FSStartSound.cpp
    src/FSStream.cpp
    src/FSString.cpp
    src/FSText.cpp
    src/FSTransform.cpp
    src/FSUnknownAction.cpp
    src/FSUnknownObject.cpp
    src/FSValue.cpp)
    
SET(SWF1_HDRS
    src/FSActionObject.h
    src/FSAction.h
    src/FSBitmapFill.h
    src/FSBounds.h
    src/FSButton.h
    src/FSCharacter.h
    src/FSColor.h
    src/FSColorTransform.h
    src/FSCoordTransform.h
    src/FSCurve.h
    src/FSDefineButton.h
    src/FSDefineFont.h
    src/FSDefineJPEGImage.h
    src/FSDefineObject.h
    src/FSDefineShape.h
    src/FSDefineSound.h
    src/FSDefineText.h
    src/FSDoAction.h
    src/FSEnvelope.h
    src/FSException.h
    src/FSFillStyle.h
    src/FSFontInfo.h
    src/FSGetUrl.h
    src/FSGotoFrame.h
    src/FSGradient.h
    src/FSGradientFill.h
    src/FSInputStream.h
    src/FSJPEGEncodingTable.h
    src/FSLine.h
    src/FSLineStyle.h
    src/FSMovie.h
    src/FSMovieEvent.h
    src/FSMovieObject.h
    src/FSOutputStream.h
    src/FSPlaceObject.h
    src/FSRemoveObject.h
    src/FSSetBackgroundColor.h
    src/FSShape.h
    src/FSShapeObject.h
    src/FSShapeStyle.h
    src/FSShowFrame.h
    src/FSSolidFill.h
    src/FSSolidLine.h
    src/FSSound.h
    src/FSSoundStreamBlock.h
    src/FSSoundStreamHead.h
    src/FSStartSound.h
    src/FSStream.h
    src/FSString.h
    src/FSText.h
    src/FSTransform.h
    src/FSUnknownAction.h
    src/FSUnknownObject.h
    src/FSValue.h
    src/FSVector.h)

SET(SWF5_SRCS ${SWF1_SRCS}
    src/FSBoolean.cpp
    src/FSInteger.cpp
    src/FSDouble.cpp
    src/FSButtonColorTransform.cpp
    src/FSButtonSound.cpp
    src/FSDefineImage.cpp
    src/FSDefineJPEGImage2.cpp
    src/FSDefineShape2.cpp
    src/FSProtect.cpp
    src/FSButtonEvent.cpp
    src/FSDefineButton2.cpp
    src/FSDefineFont2.cpp
    src/FSDefineImage2.cpp
    src/FSDefineJPEGImage3.cpp
    src/FSDefineMorphShape.cpp
    src/FSDefineMovieClip.cpp
    src/FSDefineShape3.cpp
    src/FSDefineText2.cpp
    src/FSEnableDebugger.cpp
    src/FSFrameLabel.cpp
    src/FSFree.cpp
    src/FSGotoLabel.cpp
    src/FSKerning.cpp
    src/FSMorphBitmapFill.cpp
    src/FSMorphGradient.cpp
    src/FSMorphGradientFill.cpp
    src/FSMorphSolidFill.cpp
    src/FSMorphSolidLine.cpp
    src/FSPlaceObject2.cpp
    src/FSQuicktimeMovie.cpp
    src/FSRemoveObject2.cpp
    src/FSSetTarget.cpp
    src/FSSoundStreamHead2.cpp
    src/FSWaitForFrame.cpp
    src/FSCall.cpp
    src/FSDefineTextField.cpp
    src/FSGetUrl2.cpp
    src/FSGotoFrame2.cpp
    src/FSIf.cpp
    src/FSJump.cpp
    src/FSPathsArePostscript.cpp
    src/FSPointer.cpp
    src/FSPush.cpp
    src/FSSerialNumber.cpp
    src/FSWaitForFrame2.cpp
    src/FSClipEvent.cpp
    src/FSExport.cpp
    src/FSImport.cpp
    src/FSNewFunction.cpp
    src/FSNull.cpp
    src/FSRegisterCopy.cpp
    src/FSRegisterIndex.cpp
    src/FSTable.cpp
    src/FSTableIndex.cpp
    src/FSVoid.cpp
    src/FSWith.cpp)

SET(SWF5_HDRS ${SWF1_HDRS}
    src/FSBoolean.h
    src/FSInteger.h
    src/FSDouble.h
    src/FSButtonColorTransform.h
    src/FSButtonSound.h
    src/FSDefineImage.h
    src/FSDefineJPEGImage2.h
    src/FSDefineShape2.h
    src/FSProtect.h
    src/FSButtonEvent.h
    src/FSDefineButton2.h
    src/FSDefineFont2.h
    src/FSDefineImage2.h
    src/FSDefineJPEGImage3.h
    src/FSDefineMorphShape.h
    src/FSDefineMovieClip.h
    src/FSDefineShape3.h
    src/FSDefineText2.h
    src/FSEnableDebugger.h
    src/FSFrameLabel.h
    src/FSFree.h
    src/FSGotoLabel.h
    src/FSKerning.h
    src/FSMorphBitmapFill.h
    src/FSMorphGradient.h
    src/FSMorphGradientFill.h
    src/FSMorphSolidFill.h
    src/FSMorphSolidLine.h
    src/FSPlaceObject2.h
    src/FSQuicktimeMovie.h
    src/FSRemoveObject2.h
    src/FSSetTarget.h
    src/FSSoundStreamHead2.h
    src/FSWaitForFrame.h
    src/FSCall.h
    src/FSDefineTextField.h
    src/FSGetUrl2.h
    src/FSGotoFrame2.h
    src/FSIf.h
    src/FSJump.h
    src/FSPathsArePostscript.h
    src/FSPointer.h
    src/FSPush.h
    src/FSSerialNumber.h
    src/FSWaitForFrame2.h
    src/FSClipEvent.h
    src/FSExport.h
    src/FSImport.h
    src/FSNewFunction.h
    src/FSNull.h
    src/FSRegisterCopy.h
    src/FSRegisterIndex.h
    src/FSTable.h
    src/FSTableIndex.h
    src/FSVoid.h
    src/FSWith.h)

SET(SWF6_SRCS ${SWF5_SRCS}
    src/FSDefineVideo.cpp
    src/FSEnableDebugger2.cpp
    src/FSFontInfo2.cpp
    src/FSInitialize.cpp
    src/FSVideoFrame.cpp )

SET(SWF6_HDRS ${SWF5_HDRS}
    src/FSDefineVideo.h
    src/FSEnableDebugger2.h
    src/FSFontInfo2.h
    src/FSInitialize.h
    src/FSVideoFrame.h )

SET(SWF7_SRCS ${SWF6_SRCS}
    src/FSExceptionHandler.cpp
    src/FSLimitScript.cpp
    src/FSNewFunction2.cpp
    src/FSRegisterVariable.cpp
    src/FSTabOrder.cpp)

SET(SWF7_HDRS ${SWF6_HDRS}
    src/FSExceptionHandler.h
    src/FSLimitScript.h
    src/FSNewFunction2.h
    src/FSRegisterVariable.h
    src/FSTabOrder.h
    src/FSPlaceObject3.h
    src/FSFilter.h)

SET(SWF8_SRCS ${SWF7_SRCS}
    src/FSPlaceObject3.cpp
    src/FSFilter.cpp
    src/FSDefineFont3.cpp
    src/FSDefineShape4.cpp)

SET(SWF8_HDRS ${SWF7_HDRS}
    src/FSPlaceObject3.h
    src/FSFilter.h
    src/FSDefineFont3.h
    src/FSDefineShape4.h)

SET(UTIL_SRCS ${SWF8_SRCS}
    src/FSCodec.cpp
    src/FSImageConstructor.cpp
    src/FSShapeConstructor.cpp
    src/FSSoundConstructor.cpp
    src/FSTextConstructor.cpp)

SET(UTIL_HDRS ${SWF8_HDRS}
    src/FSCodec.h
    src/FSImageConstructor.h
    src/FSShapeConstructor.h
    src/FSSoundConstructor.h
    src/FSTextConstructor.h)

# Define the flags for the different editions

SET(SRCS ${UTIL_SRCS})
SET(HDRS ${UTIL_HDRS})

#
# This includes the header files in Visual Studio project files.
#
if(WIN32)
    set(SRCS ${SRCS} ${UTIL_HDRS})
endif(WIN32)

#
# Build the library
#

# Search for zlib. Since zlib can be anywhere on a win32 system the 
# path where it can be found needs to be set directly.

IF(WIN32)
	SET(CMAKE_INCLUDE_PATH C:/MinGW/include ${CMAKE_INCLUDE_PATH})
	SET(CMAKE_LIBRARY_PATH C:/MinGW/lib ${CMAKE_LIBRARY_PATH})
ENDIF(WIN32)

FIND_PACKAGE(ZLIB REQUIRED)

IF (TRANSFORM_BUILD_SHARED)
    ADD_LIBRARY(${LIB}-shared SHARED ${SRCS} ${HDRS})
    TARGET_LINK_LIBRARIES(${LIB}-shared ${ZLIB_LIBRARIES})
    SET_TARGET_PROPERTIES(${LIB}-shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
ENDIF()

# Uncomment the following lines if you want also to build a static library.

ADD_LIBRARY(${LIB} STATIC ${SRCS} ${HDRS})
TARGET_LINK_LIBRARIES(${LIB} ${ZLIB_LIBRARIES})
SET_TARGET_PROPERTIES(${LIB} PROPERTIES CLEAN_DIRECT_OUTPUT 1)

IF (TRANSFORM_BUILD_TEST)
    include_directories(src)

    add_executable(main ${SRCS} ${HDRS} main/main.cpp)
    TARGET_LINK_LIBRARIES(main ${ZLIB_LIBRARIES})
ENDIF()
