

#pragma once

// Application Name
#define SZAPPNAME "NSClient++"

// Version
#define SZVERSION "0.1.0 2005-01-23"

// internal name of the service
#define SZSERVICENAME        "NSClient++"

// displayed name of the service
#define SZSERVICEDISPLAYNAME SZSERVICENAME " (Nagios) " SZVERSION

// list of service dependencies - "dep1\0dep2\0\0"
#define SZDEPENDENCIES       ""


// PDH Check interval (Check every x second)
//#define CHECK_INTERVAL		1

// PDH CPU check backlog (x minutes)
//#define BACK_INTERVAL		2000	

// Buffer size of incoming data (noteice this is the maximum request length!)
#define RECV_BUFFER_LEN		1024



