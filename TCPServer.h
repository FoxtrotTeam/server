#pragma once
/*
Директива #define определяет идентификатор 
и последовательность символов, 
которой будет замещаться данный 
идентификатор при его обнаружении в тексте программы. 
Идентификатор также называется именем макроса, 
а процесс замещения называется подстановкой макроса.
*/
#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_TCPSERVER_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_TCPSERVER			107
#define IDI_SMALL				108
#define IDC_TCPSERVER			109
#define IDC_MYICON				2
#define IDC_STATIC				-1
// Next default values for new objects

// Директивы #ifdef и #ifndef выполняют ту же задачу, 
//что и директива #if, если она используется с defined
//Если после #if константное выражение принимает истинное значение, 
//то код между #if и #endif компилируется, в противном случае код пропускается. 

#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif
//Директива #endif используется для обозначения конца блока #if.
