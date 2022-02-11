int
F_1 ( unsigned int V_1 , unsigned int V_2 )
{
T_1 V_3 = 0xf ;
if ( ! V_1 )
V_3 = 9 ;
V_4 &= ~ ( V_3 << ( ( 7 - V_1 ) << 2 ) ) ;
V_4 |= ( V_2 & 0xf ) << ( ( 7 - V_1 ) << 2 ) ;
#ifdef F_2
F_3 ( L_1 , V_5 , V_1 , V_2 , V_4 ) ;
#endif
return 0 ;
}
