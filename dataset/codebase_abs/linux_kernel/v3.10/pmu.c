T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 = V_4 ;
switch ( F_2 ( V_2 ) ) {
case V_5 :
case V_6 :
case V_7 :
V_3 = 3700 ;
break;
default:
break;
}
return ( T_1 ) V_3 ;
}
T_3 F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 , struct V_8 , V_10 ) ;
struct V_11 * V_12 ;
T_3 V_13 ;
if ( F_5 ( V_2 ) < 10 )
return 0 ;
V_12 = V_9 -> V_14 -> V_15 . V_12 ;
if ( F_6 ( V_12 , F_7 ( V_16 ) ) & V_17 ) {
T_3 V_18 , V_19 ;
F_8 ( V_12 , F_7 ( V_20 ) ,
1U << V_21 ) ;
F_9 ( 1000 ) ;
V_18 = F_6 ( V_12 , F_7 ( V_20 ) ) &
V_22 ;
F_8 ( V_12 , F_7 ( V_20 ) , 0 ) ;
V_19 = ( V_18 * V_23 ) / 4 ;
V_13 = ( V_19 + 50000 ) / 100000 * 100 ;
} else
V_13 = 0 ;
return V_13 ;
}
