#pragma once

/*
 *      Copyright (C) 2010-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include <list>

#include "system.h"
#include "DVDAudioCodec.h"
#include "DVDStreamInfo.h"
#include "cores/AudioEngine/Utils/AEAudioFormat.h"

class CDVDAudioCodecPassthroughRaw : public CDVDAudioCodec
{
public:
  CDVDAudioCodecPassthroughRaw();
  virtual ~CDVDAudioCodecPassthroughRaw();

  virtual bool Open(CDVDStreamInfo &hints, CDVDCodecOptions &options);
  virtual void Dispose();
  virtual int  Decode(uint8_t* pData, int iSize);
  virtual void GetData(DVDAudioFrame &frame);
  virtual int  GetData(uint8_t** dst);
  virtual void Reset();
  virtual int  GetChannels               ();
  virtual int  GetEncodedChannels        ();
  virtual CAEChannelInfo GetChannelMap       ();
  virtual int  GetSampleRate             ();
  virtual int  GetEncodedSampleRate      ();
  virtual enum AEDataFormat GetDataFormat();
  virtual bool NeedPassthrough           () { return true;          }
  virtual const char* GetName            () { return "passthroughraw"; }

private:
  CDVDStreamInfo     m_hints;
  uint8_t*           m_buffer;
  int                m_bufferSize;
  int                m_bufferUsed;
  int                m_sampleRate;
  enum AEDataFormat  m_codec;
  unsigned int       m_trueHDoffset;
  unsigned int       m_trueHDpos;
};
