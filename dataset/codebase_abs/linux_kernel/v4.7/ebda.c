void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
if ( ! V_3 . V_4 . V_5 )
return;
V_1 = * ( unsigned short * ) F_2 ( V_6 ) ;
V_1 <<= 10 ;
V_2 = F_3 () ;
if ( V_2 < V_7 )
V_2 = V_8 ;
if ( V_1 < V_7 )
V_1 = V_8 ;
V_1 = F_4 ( V_1 , V_2 ) ;
V_1 = F_4 ( V_1 , V_8 ) ;
F_5 ( V_1 , 0x100000 - V_1 ) ;
}
