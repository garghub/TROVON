void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
if ( F_2 () )
return;
V_1 = * ( unsigned short * ) F_3 ( V_3 ) ;
V_1 <<= 10 ;
V_2 = F_4 () ;
if ( V_2 < V_4 )
V_2 = V_5 ;
if ( V_1 < V_4 )
V_1 = V_5 ;
V_1 = F_5 ( V_1 , V_2 ) ;
V_1 = F_5 ( V_1 , V_5 ) ;
F_6 ( V_1 , 0x100000 - V_1 ) ;
}
