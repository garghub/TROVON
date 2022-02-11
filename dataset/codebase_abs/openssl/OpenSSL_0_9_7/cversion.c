const char * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return V_3 ;
if ( V_1 == V_4 )
{
#ifdef F_2
static char V_5 [ sizeof( F_2 ) + 11 ] ;
sprintf ( V_5 , L_1 , F_2 ) ;
return ( V_5 ) ;
#else
return ( L_2 ) ;
#endif
}
if ( V_1 == V_6 )
{
#ifdef F_3
static char V_5 [ sizeof( F_3 ) + 11 ] ;
sprintf ( V_5 , L_3 , F_3 ) ;
return ( V_5 ) ;
#else
return ( L_4 ) ;
#endif
}
if ( V_1 == V_7 )
{
#ifdef F_4
static char V_5 [ sizeof( F_4 ) + 11 ] ;
sprintf ( V_5 , L_5 , F_4 ) ;
return ( V_5 ) ;
#else
return ( L_6 ) ;
#endif
}
if ( V_1 == V_8 )
{
#ifdef F_5
return L_7 F_5 L_8 ;
#else
return L_9 ;
#endif
}
return ( L_10 ) ;
}
unsigned long F_6 ( void )
{
return ( V_9 ) ;
}
