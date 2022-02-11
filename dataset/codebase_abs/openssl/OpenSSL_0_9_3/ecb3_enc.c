void F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 V_3 , T_3 V_4 , T_3 V_5 ,
int V_6 )
{
register T_4 V_7 , V_8 ;
T_4 V_9 [ 2 ] ;
const unsigned char * V_10 = & ( * V_1 ) [ 0 ] ;
unsigned char * V_11 = & ( * V_2 ) [ 0 ] ;
F_2 ( V_10 , V_7 ) ;
F_2 ( V_10 , V_8 ) ;
V_9 [ 0 ] = V_7 ;
V_9 [ 1 ] = V_8 ;
if ( V_6 )
F_3 ( V_9 , V_3 , V_4 , V_5 ) ;
else
F_4 ( V_9 , V_3 , V_4 , V_5 ) ;
V_7 = V_9 [ 0 ] ;
V_8 = V_9 [ 1 ] ;
F_5 ( V_7 , V_11 ) ;
F_5 ( V_8 , V_11 ) ;
}
