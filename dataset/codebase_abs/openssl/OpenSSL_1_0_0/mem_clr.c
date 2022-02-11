void F_1 ( void * V_1 , T_1 V_2 )
{
unsigned char * V_3 = V_1 ;
T_1 V_4 = V_2 , V_5 = V_6 ;
while( V_4 -- )
{
* ( V_3 ++ ) = ( unsigned char ) V_5 ;
V_5 += ( 17 + ( ( T_1 ) V_3 & 0xF ) ) ;
}
V_3 = memchr ( V_1 , ( unsigned char ) V_5 , V_2 ) ;
if( V_3 )
V_5 += ( 63 + ( T_1 ) V_3 ) ;
V_6 = ( unsigned char ) V_5 ;
}
