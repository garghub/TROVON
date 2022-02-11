void F_1 ( void )
{
static int V_1 = 0 ;
if ( V_1 )
return;
V_1 = 1 ;
#ifdef F_2
F_3 ( V_2 , V_3 ) ;
F_4 ( V_4 , V_5 ) ;
F_5 ( V_6 , V_7 ) ;
F_6 () ;
#endif
}
