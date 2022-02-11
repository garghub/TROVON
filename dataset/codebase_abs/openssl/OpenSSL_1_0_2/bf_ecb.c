const char * F_1 ( void )
{
#ifdef F_2
return ( L_1 ) ;
#elif F_3 ( V_1 )
return ( L_2 ) ;
#else
return ( L_3 ) ;
#endif
}
void F_4 ( const unsigned char * V_2 , unsigned char * V_3 ,
const T_1 * V_4 , int V_5 )
{
T_2 V_6 , V_7 [ 2 ] ;
F_5 ( V_2 , V_6 ) ;
V_7 [ 0 ] = V_6 ;
F_5 ( V_2 , V_6 ) ;
V_7 [ 1 ] = V_6 ;
if ( V_5 )
F_6 ( V_7 , V_4 ) ;
else
F_7 ( V_7 , V_4 ) ;
V_6 = V_7 [ 0 ] ;
F_8 ( V_6 , V_3 ) ;
V_6 = V_7 [ 1 ] ;
F_8 ( V_6 , V_3 ) ;
V_6 = V_7 [ 0 ] = V_7 [ 1 ] = 0 ;
}
