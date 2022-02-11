int F_1 ( void )
{
#ifdef F_2
return F_3 () ;
#else
return 0 ;
#endif
}
int F_4 ( int V_1 )
{
#ifdef F_2
return F_5 ( V_1 ) ;
#else
if ( V_1 == 0 )
return 1 ;
F_6 ( V_2 , V_3 ) ;
return 0 ;
#endif
}
