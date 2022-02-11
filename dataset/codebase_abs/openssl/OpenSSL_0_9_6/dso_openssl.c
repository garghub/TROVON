T_1 * F_1 ( void )
{
#ifdef F_2
return ( F_2 () ) ;
#elif F_3 ( V_1 )
return ( F_4 () ) ;
#elif F_3 ( V_2 )
return ( F_5 () ) ;
#elif F_3 ( V_3 )
return ( F_6 () ) ;
#elif F_3 ( V_4 )
return ( F_7 () ) ;
#else
return ( F_8 () ) ;
#endif
}
