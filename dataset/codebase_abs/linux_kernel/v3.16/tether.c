unsigned char F_1 ( unsigned char * V_1 )
{
int V_2 ;
unsigned char V_3 ;
unsigned char V_4 = 0 ;
V_3 = ( unsigned char ) ( F_2 ( V_1 , V_5 ,
0xFFFFFFFFL ) & 0x3F ) ;
for ( V_2 = 0 ; V_2 < ( sizeof( V_3 ) * 8 ) ; V_2 ++ ) {
V_4 <<= 1 ;
if ( V_3 & 0x01 )
V_4 |= 1 ;
V_3 >>= 1 ;
}
return V_4 >> 2 ;
}
bool F_3 ( unsigned char * V_6 , unsigned int V_7 )
{
unsigned long V_8 ;
V_8 = F_4 ( V_6 , V_7 - 4 ) ;
if ( F_5 ( * ( ( unsigned long * ) ( V_6 + V_7 - 4 ) ) ) != V_8 )
return false ;
return true ;
}
