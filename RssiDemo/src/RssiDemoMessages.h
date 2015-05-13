/*
 * Copyright (c) 2008 Dimas Abreu Dutra
 * All rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the Stanford University nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DIMAS ABREU
 * DUTRA OR HIS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @author Dimas Abreu Dutra
 */

#ifndef RSSIDEMOMESSAGES_H__
#define RSSIDEMOMESSAGES_H__

enum {
  AM_RSSIMSG = 112
};

//PAYLOAD 32 Bytes
//typedef nx_struct RssiMsg{
//  nx_int16_t rssi;
//  nx_int16_t lqi;
//  nx_int16_t channel;
//  nx_int16_t power;
//  nx_int16_t counter;
//  nx_int64_t fill1;
//  nx_int64_t fill2;
//  nx_int32_t fill3;
//  nx_int16_t fill4;
//} RssiMsg;


//PAYLOAD 112 Bytes
typedef nx_struct RssiMsg{
  nx_int16_t rssi;
  nx_int16_t lqi;
  nx_int16_t channel;
  nx_int16_t power;
  nx_int16_t counter;
  nx_int64_t fill1;
  nx_int64_t fill2;
  nx_int64_t fill3;
  nx_int64_t fill4;
  nx_int64_t fill5;
  nx_int64_t fill6;
  nx_int64_t fill7;
  nx_int64_t fill8;
  nx_int64_t fill9;
  nx_int64_t fill10;
  nx_int64_t fill11;
  nx_int64_t fill12;
  nx_int32_t fill13;
  nx_int16_t fill14;
} RssiMsg;


#endif //RSSIDEMOMESSAGES_H__
