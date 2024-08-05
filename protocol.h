/**
 * @file protocol.h
 * @author Shreyas CS 
 * @brief It is a headerfile containing declarations of the all functions and stucture
 * @version 0.1
 * @date 2024-08-05
 * 
 * 
 */
#include<stdio.h>
#pragma pack(1)
/**
 * @def UINT16
 * @brief Defines a 16-bit unsigned short integer type
 */
#define UINT16 unsigned short int  
/**
 * @def UINT16
 * @brief Defines a 32-bit unsigned integer type
 */
#define UINT32 unsigned int 
/**
 * @def UINT16
 * @brief Defines a 8-bit unsigned char type
 */
#define UCHAR8 unsigned char

/**
 * @struct Protocol_head
 * @brief This structure represent the protocol header
 * 
 * This structure contains bitfields for version information, payload size,
 * type, and ID of the protocol header
 */
typedef struct prot_head
{
    /**
     * @brief Bitfield for version1 (4 bits)
     */
    UINT16 version1 : 4;
    /**
     * @brief Bitfield for version2 (6 bits)
     */
    UINT16 version2 : 6;
    /**
     * @brief Bitfield for version3 (6 bits)
     */
    UINT16 version3 : 6;
    /**
     * @brief The size of the payload in the protocol
     */
    UINT32 payload_size;
    /**
     * @brief The type of protocol
     */
    UCHAR8 type;
    /**
     * @brief The ID of protocol
     */
    UINT32 ID;
}Protocol_head;

/**
 * @brief This function will extract the packet id from the header data
 * 
 * @param header_pkt Pointer to the header data
 * @return Returns 32 bit unsigned integer Packet ID which is present in the header data
 */
UINT32 get_packet_id(char *header_pkt);
/**
 * @brief This function will extract the payload length from the header data
 * 
 * @param header_pkt Pointer to the header data
 * @return Returns 32 bit unsigned integer payload length which is present in the header data
 */
UINT32 get_payload_length(char *header_pkt);
/**
 * @brief This function will extract the protocol version from the header data
 * 
 * @param header_pkt Pointer to the header data.
 * @param ver1 Pointer to store version 1 (4 bits).
 * @param ver2 Pointer to store version 2 (6 bits).
 * @param ver3 Pointer to store version 3 (6 bits).
 */

void get_protocol_version(char *header_pkt,UINT16 *ver1,UINT16 *ver2,UINT16 *ver3);
