T_1 F_1 ( const unsigned char * V_1 , T_2 * V_2 ,
long V_3 , T_3 * V_4 ,
T_4 * V_5 )
{
register T_1 V_6 , V_7 , V_8 , V_9 ;
register long V_10 = V_3 ;
T_1 V_11 [ 2 ] ;
unsigned char * V_12 = & ( * V_2 ) [ 0 ] ;
const unsigned char * V_13 = & ( * V_5 ) [ 0 ] ;
F_2 ( V_13 , V_6 ) ;
F_2 ( V_13 , V_7 ) ;
for (; V_10 > 0 ; V_10 -= 8 )
{
if ( V_10 >= 8 )
{
F_2 ( V_1 , V_8 ) ;
F_2 ( V_1 , V_9 ) ;
}
else
F_3 ( V_1 , V_8 , V_9 , V_10 ) ;
V_8 ^= V_6 ; V_11 [ 0 ] = V_8 ;
V_9 ^= V_7 ; V_11 [ 1 ] = V_9 ;
F_4 ( ( T_1 * ) V_11 , V_4 , V_14 ) ;
V_6 = V_11 [ 0 ] ;
V_7 = V_11 [ 1 ] ;
}
if ( V_12 != NULL )
{
F_5 ( V_6 , V_12 ) ;
F_5 ( V_7 , V_12 ) ;
}
V_6 = V_8 = V_9 = V_11 [ 0 ] = V_11 [ 1 ] = 0 ;
return ( V_7 ) ;
}
