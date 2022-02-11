void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( V_1 , V_3 ) ;
* ( volatile unsigned char * ) ( V_4 ) = 0x20 ;
* ( volatile unsigned char * ) ( V_5 ) = 0x20 ;
}
int F_3 ( unsigned int V_1 )
{
if ( V_1 < 8 )
* ( volatile unsigned char * ) ( V_4 + 1 ) &= ~ ( 1 << V_1 ) ;
else
* ( volatile unsigned char * ) ( V_5 + 1 ) &= ~ ( 1 << ( V_1 - 8 ) ) ;
return 0 ;
}
void F_4 ( unsigned int V_1 )
{
if ( V_1 < 8 )
* ( volatile unsigned char * ) ( V_4 + 1 ) |= ( 1 << V_1 ) ;
else
* ( volatile unsigned char * ) ( V_5 + 1 ) |= ( 1 << ( V_1 - 8 ) ) ;
}
void T_1 F_5 ( void )
{
F_6 ( V_6 + 96 , 16 , F_1 ) ;
F_7 ( & V_7 , V_8 , 16 ) ;
}
