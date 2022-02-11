void F_1 ( void * V_1 , T_1 V_2 )
{
unsigned char * V_3 = V_1 ;
T_1 V_4 = V_2 ;
while( V_4 -- )
{
* ( V_3 ++ ) = V_5 ;
V_5 += ( 17 + ( unsigned char ) ( ( unsigned long ) V_3 & 0xF ) ) ;
}
if( memchr ( V_1 , V_5 , V_2 ) )
V_5 += 63 ;
}
