/*
 *  FSCall.h
 *  Transform SWF
 *
 * Copyright (c) 2001-2004 Flagstone Software Ltd.. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of Flagstone Software Ltd. nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __FSFilter_h__
#define __FSFilter_h__

#include "FSMovieObject.h"

namespace transform
{
   /**
    * %FSFilter is filter for %FSPlaceObject3
    *
    <table class="datasheet">
    
    <tr><th align="left" colspan="2">Attributes</th></tr>
    
    </table>
    
    */
   class DLL_DECL FSFilter
   {
   public:
      enum FilterType {
         DropShadowFilter = 0,
         BlurFilter,
         GlowFilter,
         BevelFilter,
         GradientGlowFilter,
         ConvolutionFilter,
         ColorMatrixFilter,
         GradientBevelFilter
      };
      /** Constructs an FSFilter object. */
      FSFilter(FilterType type):m_type(type){
      }
      /** Constructs an FSFilter object. */
      FSFilter(){}

      virtual ~FSFilter(){}
      
      virtual FSFilter* clone() const = 0;
      
      virtual const char* className() const = 0;
      
      virtual int lengthInStream(FSOutputStream* aStream) = 0;
      virtual void encodeToStream(FSOutputStream* aStream) = 0;
      virtual void decodeFromStream(FSInputStream* aStream) = 0;
      float readFixed32(FSInputStream* aStream);
      float readFixed16(FSInputStream* aStream);

      static FSFilter* createFilter(FSInputStream* aStream);
      FilterType getType() const {return m_type;}
   protected:
      FilterType m_type;
   };

   class DLL_DECL FSFilterBlurFilter : public FSFilter {
   public:
      FSFilterBlurFilter(FSInputStream* aStream);
      
      /** Constructs an FSFilter object. */
      FSFilterBlurFilter(){}
      
      virtual FSFilter* clone() const{ return new FSFilterBlurFilter(*this); }
      
      virtual const char* className() const { return "BlurFilter"; }
      
      virtual int lengthInStream(FSOutputStream* aStream);
      virtual void encodeToStream(FSOutputStream* aStream);
      virtual void decodeFromStream(FSInputStream* aStream);
      
      float getBlurX() const { return m_blurX; }
      float getBlurY() const { return m_blurY; }
      const char* getPasses() const { return m_passes; }
   private:
      float m_blurX;
      float m_blurY;
      char m_passes[5];
      char m_reserved[3];
   };

   class DLL_DECL FSFilterDropShadowFilter : public FSFilter {
   public:
      struct Color {
         unsigned char r,g,b,a;
      };
      FSFilterDropShadowFilter(FSInputStream* aStream);
      
      /** Constructs an FSFilter object. */
      FSFilterDropShadowFilter(){}

      virtual FSFilter* clone() const{ return new FSFilterDropShadowFilter(*this); }
      
      virtual const char* className() const { return "DropShadowFilter"; }
      
      virtual int lengthInStream(FSOutputStream* aStream);
      virtual void encodeToStream(FSOutputStream* aStream);
      virtual void decodeFromStream(FSInputStream* aStream);
      Color getColor() const { return m_color; }
      float getBlurX() const { return m_blurX; }
      float getBlurY() const { return m_blurY; }
      float getAngle() const { return m_angle; }
      float getDistance() const { return m_distance; }
      float getStrength() const { return m_strength; }
      bool getCompositeSource() const { return m_compositeSource; }
      bool getInnerShadow() const { return m_innerShadow; }
      bool getKnockout() const { return m_knockout; }
   private:
      Color m_color;
      float m_blurX;
      float m_blurY;
      float m_angle;
      float m_distance;
      float m_strength;
      bool  m_innerShadow;
      bool  m_knockout;
      bool  m_compositeSource;
      char  m_passes[5];
   };
   class DLL_DECL FSFilterGlowFilter : public FSFilter {
   public:
      struct Color {
         unsigned char r,g,b,a;
      };
   public:
      FSFilterGlowFilter(FSInputStream* aStream);
      
      /** Constructs an FSFilter object. */
      FSFilterGlowFilter(){}
      
      virtual FSFilter* clone() const{ return new FSFilterGlowFilter(*this); }
      
      virtual const char* className() const { return "GlowFilter"; }
      
      virtual int lengthInStream(FSOutputStream* aStream);
      virtual void encodeToStream(FSOutputStream* aStream);
      virtual void decodeFromStream(FSInputStream* aStream);

      float getBlurX() const { return m_blurX; }
      float getBlurY() const { return m_blurY; }
      const char* getPasses() const { return m_passes; }
      float getStrength() const { return m_strength; }
      unsigned char getInnerGlow() const { return m_inner_glow; }
      unsigned char getKnockout() const { return m_knockout; }
      unsigned char getCompositeSource() const { return m_composite_source; }
      Color getColor() const { return m_color; }
   private:
      Color m_color;
      float m_blurX;
      float m_blurY;
      float m_strength;
      unsigned char m_inner_glow;
      unsigned char m_knockout;
      unsigned char m_composite_source;
      char m_passes[5];
   };
}

#endif
