static T_1 F_1 ( T_1 * V_1 , T_2 V_2 , T_1 V_3 , const T_1 V_4 [] )
{
T_1 V_5 ;
V_5 = V_3 ;
while( V_2 -- > 0 )
V_5 = V_4 [ ( T_1 ) ( * V_1 ++ ) ^ V_5 ] ;
return V_5 ;
}
T_1 F_2 ( T_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , V_6 ) ;
}
T_1 F_3 ( T_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
T_1 V_5 = V_3 ;
while ( V_2 -- > 0 )
{
V_5 = V_7 [ ( V_5 ^ * V_1 ++ ) ] ;
}
return ( V_5 ) ;
}
T_1 F_4 ( T_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
T_1 V_5 = V_3 ;
while ( V_2 -- > 0 )
{
V_5 = V_8 [ ( V_5 ^ * V_1 ++ ) ] ;
}
return ( V_5 ) ;
}
