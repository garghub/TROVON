unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < 8 )
* ( volatile unsigned char * ) ( V_4 + 1 ) &= ~ ( 1 << V_3 ) ;
else
* ( volatile unsigned char * ) ( V_5 + 1 ) &= ~ ( 1 << ( V_3 - 8 ) ) ;
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < 8 )
* ( volatile unsigned char * ) ( V_4 + 1 ) |= ( 1 << V_3 ) ;
else
* ( volatile unsigned char * ) ( V_5 + 1 ) |= ( 1 << ( V_3 - 8 ) ) ;
}
void F_3 ( struct V_1 * V_2 )
{
* ( volatile unsigned char * ) ( V_4 ) = 0x20 ;
* ( volatile unsigned char * ) ( V_5 ) = 0x20 ;
}
void T_1 F_4 ( void )
{
F_5 ( V_6 + 96 , 16 ) ;
F_6 ( & V_7 , V_8 ,
V_9 , 16 ) ;
}
