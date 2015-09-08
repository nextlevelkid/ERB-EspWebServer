// AA_Main.h

/*
 * Copyright (c) 2015, Eldon R. Brown - ERB - WA0UWH - eldonb@ebcon.com
 *
 * See my Blog, at: http://WA0UWH.blogspot.com
 *
 * See my Source at GitHub, at: https://github.com/wa0uwh/ERB-EspWebServer
 *
 * All rights reserved. See FULL Copyright in Main or Info Page for Exclusions
 *
 * This Effort was Inspired by work by: Majenko Technologies - 2015 Esp8266 AdvancedWebServer
 *
 * See also Arduino IDE, at: https://github.com/esp8266/Arduino
 */


#ifndef A1MAIN_H
#define A1MAIN_H

#include <pgmspace.h>

    // Page Type being Sent
    enum {
      HOMEPAGE = 0,
      HELPPAGE,
      ADMINPAGE,
      INFOPAGE,
    };
    
    
    // Define Multipliers for Ms Counters
    #define MSECs (1)
    #define SECs (MSECs * 1000)
    #define MINs (SECs * 60)
    #define HRs  (MINs * 60)
    #define DAYs (HRs * 24)
    #define WKs  (DAYs * 7)

    
    // ERB - Force format stings and string constants into FLASH Memory
    #define sF(x) (String) F(x)                // Used as an F() is being used as the first Element of a Multi-Element Expression
    #define FMT(x) strcpy_P(gFmtBuf, PSTR(x))  // Used with printf() for the format string
    // USE WITH CAUTION !
    
    #define VddScaleLo (2900)
    #define VddScaleHi (3700)
    
    #define FreeHeapScaleLo (4000)
    #define FreeHeapScaleHi (20000)


    
    #define DEBUG_MONITOR_REPORT_START() Serial.println ( sF("\nStart ") + String( __func__ )\
            + F(" Build for: ")\
            + String(ipa2str(gServer.client().remoteIP())) +F(" . . ") )

    #define DEBUG_MONITOR_REPORT_END() Serial.println ( sF("  . . Finshed ") + String( __func__ )\
            + F(" Build") )

    #define DEBUG_MONITOR_REPORT_TOTAL() Serial.println( sF("Sent: ") + String(__func__)\
            + F(", URI: ") + gServer.uri()\
            + F(", FreeHeap: ") + String( ESP.getFreeHeap() / 1000.0, 3 )\
            + F(", PageSize: ") + String( sz / 1000.0, 3 )\
            + F(", Hits: ") + String(gHits) + F("\r\n") )

    #define DEBUG_MONITOR_REPORT_ANONYMOUS_FUNCTION() Serial.println( sF("Sent: Data for Query")\
            + F(", URI: ") + gServer.uri()\
            + F(" for: ")\
            + String(ipa2str(gServer.client().remoteIP()) )\
            + F(", Hits: ") + String(gHits) + F("\r\n") )

    // Shorthand for the above
    #define DMRAF() DEBUG_MONITOR_REPORT_ANONYMOUS_FUNCTION()
            
    #define DEBUG_MONITOR_REPORT_ARGS() if ( gServer.args() ) {\
              Serial.println(" Args:");\
              for ( byte i = 0; i < gServer.args(); i++ )\
                  Serial.println( "  " + gServer.argName(i) + "=" + gServer.arg(i) );\
            }




    
    const char COPYRIGHT2[] PROGMEM = R"=====(
     /*
      * Redistribution and use in source and binary forms, with or without modification,
      * are permitted provided that the following conditions are met:
      * 
      * * Redistributions of source code must retain the above copyright notice, this
      *   list of conditions and the following disclaimer.
      *
      * * Redistributions in binary form must reproduce the above copyright notice, this
      *   list of conditions and the following disclaimer in the documentation and/or
      *   other materials provided with the distribution.
      * 
      * * Neither the name of Majenko Technologies nor the names of its
      *   contributors may be used to endorse or promote products derived from
      *   this software without specific prior written permission.
      */
     )=====";

    
    const char COPYRIGHT3[] PROGMEM = R"=====(
     /*
      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND ANY
      * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
      * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
      * SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,INCIDENTAL,
      * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
      * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
      * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
      * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
      */
     )=====";
    
    // This is a 10Kb character Test Pattern, Note: this is "optomized out" if not used, see Info Code Page
    const char TEST_10Kb[] PROGMEM = R"=====(
     /* 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 
      * THIS IS A 1KB TEST BLOCK ---- 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      * 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
      *
      */
     )=====";

#endif

// ###########################################################
// End
