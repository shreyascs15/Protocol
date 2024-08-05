#include"protocol.h"
char header_pkt[] = "\x0C\x21\x00\x00\x01\x00\x02\x00\x00\x12\x34";
void main()
{
Protocol_head v;
UINT16 ver1,ver2,ver3;
get_protocol_version(header_pkt,&ver1,&ver2,&ver3);
v.version1=ver1;
v.version2=ver2;
v.version3=ver3;

v.ID=get_packet_id(header_pkt);
v.payload_size=get_payload_length(header_pkt);
v.type=header_pkt[6];
printf("Version 1     :%d\nVersion 2     :%d\nVersion 3     :%d\nPayload length:%d\nType          :%d\nID            :0X%x\n",v.version1,v.version2,v.version3,v.payload_size,v.type,v.ID);
}

UINT32 get_packet_id(char * header_pkt)
{
    UINT32 res=(header_pkt[7] << 24) | (header_pkt[8] << 16) | (header_pkt[9] << 8) | header_pkt[10];
    return res;
}

UINT32 get_payload_length(char *header_pkt)
{
    UINT32 res=(header_pkt[2] << 24) | (header_pkt[3] << 16) | (header_pkt[4] << 8) | header_pkt[5];
    return res;
}


void get_protocol_version(char *header_pkt,UINT16 *ver1,UINT16 *ver2,UINT16 *ver3)
{
    UCHAR8 temp;
*ver1=header_pkt[1]&0xf;
temp=header_pkt[0]&0x03;
*ver2=(header_pkt[1]>>4 & 0xf)|temp<<2;
*ver3=header_pkt[0]>>2 &0x3f;
}