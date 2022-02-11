void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 * V_3 , int V_4 )
{
T_2 V_5 , V_6 [ 2 ] ;
F_2 ( V_1 , V_5 ) ; V_6 [ 0 ] = V_5 ;
F_2 ( V_1 , V_5 ) ; V_6 [ 1 ] = V_5 ;
if ( V_4 )
F_3 ( V_6 , V_3 ) ;
else
F_4 ( V_6 , V_3 ) ;
V_5 = V_6 [ 0 ] ; F_5 ( V_5 , V_2 ) ;
V_5 = V_6 [ 1 ] ; F_5 ( V_5 , V_2 ) ;
V_5 = V_6 [ 0 ] = V_6 [ 1 ] = 0 ;
}
