const char * F_1 ( void )
{
static int V_1 = 1 ;
static char V_2 [ 32 ] ;
if ( V_1 ) {
const char * V_3 ;
if ( sizeof( V_4 ) != sizeof( long ) )
V_3 = L_1 ;
else
V_3 = L_2 ;
F_2 ( V_2 , sizeof V_2 , L_3 , V_3 ) ;
V_1 = 0 ;
}
return ( V_2 ) ;
}
void F_3 ( T_1 * V_5 , T_2 * V_6 ,
T_3 * V_7 , int V_8 )
{
register V_4 V_9 ;
V_4 V_10 [ 2 ] ;
const unsigned char * V_11 = & ( * V_5 ) [ 0 ] ;
unsigned char * V_12 = & ( * V_6 ) [ 0 ] ;
F_4 ( V_11 , V_9 ) ;
V_10 [ 0 ] = V_9 ;
F_4 ( V_11 , V_9 ) ;
V_10 [ 1 ] = V_9 ;
F_5 ( V_10 , V_7 , V_8 ) ;
V_9 = V_10 [ 0 ] ;
F_6 ( V_9 , V_12 ) ;
V_9 = V_10 [ 1 ] ;
F_6 ( V_9 , V_12 ) ;
V_9 = V_10 [ 0 ] = V_10 [ 1 ] = 0 ;
}
