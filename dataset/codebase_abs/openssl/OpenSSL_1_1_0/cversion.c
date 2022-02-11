unsigned long F_1 ( void )
{
return V_1 ;
}
const char * F_2 ( int V_2 )
{
if ( V_2 == V_3 )
return V_4 ;
if ( V_2 == V_5 ) {
#ifdef F_3
# ifdef F_4
return ( F_3 ) ;
# else
return ( L_1 ) ;
# endif
#else
return ( L_2 ) ;
#endif
}
if ( V_2 == V_6 ) {
#ifdef F_5
return ( F_5 ) ;
#else
return ( L_3 ) ;
#endif
}
if ( V_2 == V_7 ) {
#ifdef F_6
return ( F_6 ) ;
#else
return ( L_4 ) ;
#endif
}
if ( V_2 == V_8 ) {
#ifdef F_7
return L_5 F_7 L_6 ;
#else
return L_7 ;
#endif
}
if ( V_2 == V_9 ) {
#ifdef F_8
return L_8 F_8 L_6 ;
#else
return L_9 ;
#endif
}
return ( L_10 ) ;
}
