int
F_1 ( int V_1 )
{
if ( ( V_1 != 1 ) && ( V_1 != 2 ) )
V_2 &= ~ ( 1 << ( 31 - V_1 ) ) ;
#ifdef F_2
F_3 ( L_1 , V_3 , V_1 , V_2 ) ;
#endif
return 0 ;
}
