const char * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return V_3 ;
if ( V_1 == V_4 ) {
#ifdef F_2
# ifdef F_3
return ( F_2 ) ;
# else
return ( L_1 ) ;
# endif
#else
return ( L_2 ) ;
#endif
}
if ( V_1 == V_5 ) {
#ifdef F_4
return ( F_4 ) ;
#else
return ( L_3 ) ;
#endif
}
if ( V_1 == V_6 ) {
#ifdef F_5
return ( F_5 ) ;
#else
return ( L_4 ) ;
#endif
}
if ( V_1 == V_7 ) {
#ifdef F_6
return L_5 F_6 L_6 ;
#else
return L_7 ;
#endif
}
return ( L_8 ) ;
}
unsigned long F_7 ( void )
{
return ( V_8 ) ;
}
