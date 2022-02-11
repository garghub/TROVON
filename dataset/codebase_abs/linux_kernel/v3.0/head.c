void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
if ( F_2 () )
return;
V_1 = * ( unsigned short * ) F_3 ( V_3 ) ;
V_1 <<= 10 ;
V_2 = F_4 () ;
if ( ( V_1 - V_2 ) <= 0x10000 )
V_1 = V_2 ;
if ( ( V_2 == 0 ) && ( V_1 >= 0x9f000 ) )
V_1 = 0x9f000 ;
if ( ( V_1 == 0 ) || ( V_1 >= 0x100000 ) )
V_1 = 0x9f000 ;
F_5 ( V_1 , 0x100000 , L_1 ) ;
}
