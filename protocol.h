#include<stdio.h>
#pragma pack(1)
#define UINT16 unsigned short int  
#define UINT32 unsigned int 
#define UCHAR8 unsigned char  
typedef struct prot_head
{
    UINT16 version1 : 4;
    UINT16 version2 : 6;
    UINT16 version3 : 6;
    UINT32 payload_size;
    UCHAR8 type;
    UINT32 ID;
}Protocol_head;
UINT32 get_packet_id(char *header_pkt);
UINT32 get_payload_length(char *header_pkt);
void get_protocol_version(char *header_pkt,UINT16 *ver1,UINT16 *ver2,UINT16 *ver3);