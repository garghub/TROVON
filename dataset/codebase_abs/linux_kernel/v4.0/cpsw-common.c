int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_2 * V_5 )
{
T_3 V_6 ;
T_3 V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 -> V_10 , L_1 ) ;
if ( F_3 ( V_9 ) ) {
if ( F_4 ( V_9 ) == - V_11 )
return 0 ;
return F_4 ( V_9 ) ;
}
F_5 ( V_9 , F_6 ( V_3 , V_4 ) ,
& V_6 ) ;
F_5 ( V_9 , F_7 ( V_3 , V_4 ) ,
& V_7 ) ;
V_5 [ 5 ] = ( V_6 >> 8 ) & 0xff ;
V_5 [ 4 ] = V_6 & 0xff ;
V_5 [ 3 ] = ( V_7 >> 24 ) & 0xff ;
V_5 [ 2 ] = ( V_7 >> 16 ) & 0xff ;
V_5 [ 1 ] = ( V_7 >> 8 ) & 0xff ;
V_5 [ 0 ] = V_7 & 0xff ;
return 0 ;
}
