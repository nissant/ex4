/*
Authors			- Eli Slavutsky (308882992) & Nisan Tagar (302344031)
Project Name	- Ex4
Description		- Connect 4 - A Server/Client game With human or file mode players
				- Socket Module provided by OSP course materials with minimal modifications
*/
// Includes --------------------------------------------------------------------
#include <winsock2.h>
#include <stdio.h>
#include <string.h>

#ifndef SOCKET_SEND_RECV_TOOLS_H
#define SOCKET_SEND_RECV_TOOLS_H

// Defines ---------------------------------------------------------------------
#define MAX_MSG_SIZE 100
// Global Variables ------------------------------------------------------------
	

#pragma comment(lib, "ws2_32.lib")

// Function Declarations -------------------------------------------------------

typedef enum { TRNS_FAILED, TRNS_DISCONNECTED, TRNS_SUCCEEDED } TransferResult_t;

/**
 * SendBuffer() uses a socket to send a buffer.
 *
 * Accepts:
 * -------
 * Buffer - the buffer containing the data to be sent.
 * BytesToSend - the number of bytes from the Buffer to send.
 * sd - the socket used for communication.
 *
 * Returns:
 * -------
 * TRNS_SUCCEEDED - if sending succeeded
 * TRNS_FAILED - otherwise
 */
TransferResult_t SendBuffer( const char* Buffer, int BytesToSend, SOCKET sd );

/**
 * SendString() uses a socket to send a string.
 * Str - the string to send. 
 * sd - the socket used for communication.
 */ 
TransferResult_t SendString( const char *Str, SOCKET sd );

/**
 * Accepts:
 * -------
 * ReceiveBuffer() uses a socket to receive a buffer.
 * OutputBuffer - pointer to a buffer into which data will be written
 * OutputBufferSize - size in bytes of Output Buffer
 * BytesReceivedPtr - output parameter. if function returns TRNS_SUCCEEDED, then this 
 *					  will point at an int containing the number of bytes received.
 * sd - the socket used for communication.
 *
 * Returns:
 * -------
 * TRNS_SUCCEEDED - if receiving succeeded
 * TRNS_DISCONNECTED - if the socket was disconnected
 * TRNS_FAILED - otherwise
 */ 
TransferResult_t ReceiveBuffer( char* OutputBuffer, int RemainingBytesToReceive, SOCKET sd );

/**
 * ReceiveString() uses a socket to receive a string, and stores it in dynamic memory.
 * 
 * Accepts:
 * -------
 * OutputStrPtr - a pointer to a char-pointer that is initialized to NULL, as in:
 *
 *		char *Buffer = NULL;
 *		ReceiveString( &Buffer, ___ );
 *
 * a dynamically allocated string will be created, and (*OutputStrPtr) will point to it.
 * 
 * sd - the socket used for communication.
 * 
 * Returns:
 * -------
 * TRNS_SUCCEEDED - if receiving and memory allocation succeeded
 * TRNS_DISCONNECTED - if the socket was disconnected
 * TRNS_FAILED - otherwise
 */ 
TransferResult_t ReceiveString( char* OutputStr, SOCKET sd );


/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

#endif // SOCKET_SEND_RECV_TOOLS_H