/**
 * @file protocol.c
 * @author Shreyas CS
 * @brief This is containing definitions of all functions.
 * @version 0.1
 * @date 2024-08-05
 * 
 */
/*******************************************************************************************/
#include"protocol.h"
/**
 * @brief it is a input header data in Network Order.
 * 
 */
char header_pkt[] = "\x0C\x21\x00\x00\x01\x00\x02\x00\x00\x12\x34";
void main()
{
    /*
 * @brief *v is a variable created for protocol_head structure
 * 
 */
Protocol_head v;
/**
 * @brief var1 var2 var3 are variables used to store different parts of version
 * 
 */

UINT16 ver1,ver2,ver3;

get_protocol_version(header_pkt,&ver1,&ver2,&ver3);
v.version1=ver1;
v.version2=ver2;
v.version3=ver3;

v.ID=get_packet_id(header_pkt);//assiging the extracted packed id to structure member
v.payload_size=get_payload_length(header_pkt);//assiging the extracted payload size to structure member
v.type=header_pkt[6];//assiging 1 byte protocol type to structure member
printf("Version 1     :%d\nVersion 2     :%d\nVersion 3     :%d\nPayload length:%d\nType          :%d\nID            :0X%x\n",v.version1,v.version2,v.version3,v.payload_size,v.type,v.ID);
}
/**************************************************************************************************/
 /**
     * @brief this function is used to calculate 4 bytes packet id from bytes 7 to 10 of packet header
     * 
     */
UINT32 get_packet_id(char * header_pkt)
{
   
    UINT32 res=(header_pkt[7] << 24) | (header_pkt[8] << 16) | (header_pkt[9] << 8) | header_pkt[10];
    return res;
}

/*********************************************************************************************/
/**
     * @brief this function is used to calculate 4 bytes payload length from bytes 2 to 5 of packet header
     * 
     */
UINT32 get_payload_length(char *header_pkt)
{
    
    UINT32 res=(header_pkt[2] << 24) | (header_pkt[3] << 16) | (header_pkt[4] << 8) | header_pkt[5];
    return res;
}
/**************************************************************************************************/
/**
     * @brief this function is used to calculate all 3 parts of protocol version
     * 
     */
void get_protocol_version(char *header_pkt,UINT16 *ver1,UINT16 *ver2,UINT16 *ver3)
{
UCHAR8 temp;
*ver1=header_pkt[1]&0xf;
temp=header_pkt[0]&0x03;
*ver2=(header_pkt[1]>>4 & 0xf)|temp<<2;
*ver3=header_pkt[0]>>2 &0x3f;
}
/****************************************************************************************************/