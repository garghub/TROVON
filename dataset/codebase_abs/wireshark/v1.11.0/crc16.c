static T_1 F_1 ( const T_2 * V_1 , T_3 V_2 ,
T_1 V_3 , const T_3 V_4 [] )
{
T_3 V_5 = ( T_3 ) V_3 ;
while( V_2 -- != 0 )
V_5 = V_4 [ ( ( V_5 >> 8 ) ^ * V_1 ++ ) & 0xff ] ^ ( V_5 << 8 ) ;
return ( T_1 ) V_5 ;
}
static T_1 F_2 ( const T_2 * V_1 , T_3 V_2 ,
T_1 V_3 , const T_3 V_4 [] )
{
T_3 V_5 = ( T_3 ) V_3 ;
while( V_2 -- != 0 )
V_5 = V_4 [ ( V_5 ^ * V_1 ++ ) & 0xff ] ^ ( V_5 >> 8 ) ;
return ( T_1 ) V_5 ;
}
T_1 F_3 ( const T_2 * V_1 , T_3 V_2 )
{
return F_2 ( V_1 , V_2 , V_6 , V_7 )
^ V_8 ;
}
T_1 F_4 ( const T_2 * V_1 , T_3 V_2 )
{
return F_1 ( V_1 , V_2 , V_6 , V_9 ) ;
}
T_1 F_5 ( const T_2 * V_1 , T_3 V_2 , T_1 V_10 )
{
return F_2 ( V_1 , V_2 , V_10 , V_7 )
^ V_8 ;
}
T_1 F_6 ( const T_2 * V_1 , T_4 V_2 , T_1 V_10 )
{
return F_1 ( V_1 , V_2 , V_10 , V_11 ) ;
}
T_1 F_7 ( const T_2 * V_1 , T_4 V_2 , T_1 V_10 )
{
return F_1 ( V_1 , V_2 , V_10 , V_12 ) ;
}
