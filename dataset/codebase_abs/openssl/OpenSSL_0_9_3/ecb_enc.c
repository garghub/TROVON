const char * F_1 ( void )
{
static int V_1 = 1 ;
static char V_2 [ 32 ] ;
if ( V_1 )
{
const char * V_3 , * V_4 , * V_5 , * V_6 ;
#ifdef F_2
V_3 = L_1 ;
#else
V_3 = L_2 ;
#endif
#if F_3 ( V_7 ) || F_3 ( V_8 )
#ifdef V_7
V_5 = L_3 ;
#endif
#ifdef V_8
V_5 = L_4 ;
#endif
#else
V_5 = L_5 ;
#endif
#ifdef F_4
V_4 = L_6 ;
#else
V_4 = L_7 ;
#endif
if ( sizeof( V_9 ) != sizeof( long ) )
V_6 = L_8 ;
else
V_6 = L_9 ;
sprintf ( V_2 , L_10 , V_3 , V_5 , V_4 , V_6 ) ;
V_1 = 0 ;
}
return ( V_2 ) ;
}
void F_5 ( T_1 * V_10 , T_2 * V_11 ,
T_3 V_12 ,
int V_13 )
{
register V_9 V_14 ;
V_9 V_15 [ 2 ] ;
const unsigned char * V_16 = & ( * V_10 ) [ 0 ] ;
unsigned char * V_17 = & ( * V_11 ) [ 0 ] ;
F_6 ( V_16 , V_14 ) ; V_15 [ 0 ] = V_14 ;
F_6 ( V_16 , V_14 ) ; V_15 [ 1 ] = V_14 ;
F_7 ( V_15 , V_12 , V_13 ) ;
V_14 = V_15 [ 0 ] ; F_8 ( V_14 , V_17 ) ;
V_14 = V_15 [ 1 ] ; F_8 ( V_14 , V_17 ) ;
V_14 = V_15 [ 0 ] = V_15 [ 1 ] = 0 ;
}
