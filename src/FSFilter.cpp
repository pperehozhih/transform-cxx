#include "FSFilter.h"

#include "FSMovie.h"
#include "FSInputStream.h"
#include "FSOutputStream.h"
#include <stdio.h>

namespace transform
{
   FSFilter* FSFilter::createFilter(FSInputStream* aStream) {
      int type = aStream->read(transform::FSStream::UnsignedWord, 8);
      switch (type) {
         case DropShadowFilter:
            return new FSFilterDropShadowFilter(aStream);
         case BlurFilter:
            return new FSFilterBlurFilter(aStream);
         case GlowFilter:
            return new FSFilterGlowFilter(aStream);
         default:
#pragma message "Need create exception class"
            throw "Unknown filter";
            break;
      }
   }
   float FSFilter::readFixed32(FSInputStream* aStream) {
      int i1 = aStream->read(transform::FSStream::UnsignedWord, 16);
      int i2 = aStream->read(transform::FSStream::UnsignedWord, 16);
      char tmp[256];
      sprintf(tmp, "%d.%d", i1, i2);
      return atof(tmp);
   }

   float FSFilter::readFixed16(FSInputStream* aStream) {
      int i1 = aStream->read(transform::FSStream::UnsignedWord, 8);
      int i2 = aStream->read(transform::FSStream::UnsignedWord, 8);
      char tmp[256];
      sprintf(tmp, "%d.%d", i1, i2);
      return atof(tmp);
   }
   FSFilterDropShadowFilter::FSFilterDropShadowFilter(FSInputStream* aStream):transform::FSFilter(DropShadowFilter) {
      decodeFromStream(aStream);
   }
   int FSFilterDropShadowFilter::lengthInStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }

   void FSFilterDropShadowFilter::encodeToStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }

   void FSFilterDropShadowFilter::decodeFromStream(FSInputStream* aStream) {
      m_color.r = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.g = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.b = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.a = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_blurX = readFixed32(aStream);
      m_blurY = readFixed32(aStream);
      m_angle = readFixed32(aStream);
      m_distance = readFixed32(aStream);
      m_strength = readFixed16(aStream);
      m_innerShadow = aStream->read(transform::FSStream::UnsignedBit, 1) != 0 ? true : false;
      m_knockout = aStream->read(transform::FSStream::UnsignedBit, 1) != 0 ? true : false;
      m_compositeSource = aStream->read(transform::FSStream::UnsignedBit, 1) != 0 ? true : false;
      m_passes[0] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[1] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[2] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[3] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[4] = aStream->read(FSStream::UnsignedBit, 1);
   }

   FSFilterGlowFilter::FSFilterGlowFilter(FSInputStream* aStream):transform::FSFilter(GlowFilter) {
      decodeFromStream(aStream);
   }

   int FSFilterGlowFilter::lengthInStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }

   void FSFilterGlowFilter::encodeToStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }

   void FSFilterGlowFilter::decodeFromStream(FSInputStream* aStream) {
      m_color.r = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.g = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.b = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_color.a = aStream->read(transform::FSStream::UnsignedWord, 8);
      m_blurX = readFixed32(aStream);
      m_blurY = readFixed32(aStream);
      m_strength = readFixed16(aStream);
      m_inner_glow = aStream->read(FSStream::UnsignedBit, 1);
      m_knockout = aStream->read(FSStream::UnsignedBit, 1);
      m_composite_source = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[0] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[1] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[2] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[3] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[4] = aStream->read(FSStream::UnsignedBit, 1);
   }

   FSFilterBlurFilter::FSFilterBlurFilter(FSInputStream* aStream):transform::FSFilter(BlurFilter) {
      decodeFromStream(aStream);
   }

   int FSFilterBlurFilter::lengthInStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }
   
   void FSFilterBlurFilter::encodeToStream(FSOutputStream* aStream) {
      throw "Not impliment method";
   }
   
   void FSFilterBlurFilter::decodeFromStream(FSInputStream* aStream) {
      m_blurX = readFixed32(aStream);
      m_blurY = readFixed32(aStream);
      m_passes[0] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[1] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[2] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[3] = aStream->read(FSStream::UnsignedBit, 1);
      m_passes[4] = aStream->read(FSStream::UnsignedBit, 1);
      m_reserved[0] = aStream->read(FSStream::UnsignedBit, 1);
      m_reserved[1] = aStream->read(FSStream::UnsignedBit, 1);
      m_reserved[2] = aStream->read(FSStream::UnsignedBit, 1);
   }
}
