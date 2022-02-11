T_1
F_1 ( const T_2 * V_1 , int V_2 )
{
T_3 V_3 [ 1 ] ;
F_2 ( V_3 [ 0 ] , V_1 , V_2 ) ;
return F_3 ( & V_3 [ 0 ] , 1 ) ;
}
T_1
F_4 ( T_4 * V_4 , int V_5 , int V_2 )
{
T_3 V_3 [ 1 ] ;
F_5 ( V_3 [ 0 ] , V_4 , V_5 , V_2 ) ;
return F_3 ( & V_3 [ 0 ] , 1 ) ;
}
T_1
F_6 ( T_1 V_6 , T_1 V_7 )
{
T_5 V_8 ;
V_8 = V_6 ;
V_8 += F_7 ( V_7 ) ;
V_8 = ( V_8 & 0xFFFF ) + ( V_8 >> 16 ) ;
V_8 = ( V_8 & 0xFFFF ) + ( V_8 >> 16 ) ;
return V_8 ;
}
