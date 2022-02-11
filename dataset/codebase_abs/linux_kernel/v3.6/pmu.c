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
T_3 F_3 ( struct V_1 * V_2 , T_2 V_8 , T_3 V_9 , T_3 V_10 )
{
F_4 ( V_2 , F_5 ( struct V_11 , V_12 ) , ~ 0 , V_8 ) ;
return F_4 ( V_2 , F_5 ( struct V_11 , V_13 ) ,
V_9 , V_10 ) ;
}
T_3 F_6 ( struct V_1 * V_2 , T_2 V_8 , T_3 V_9 , T_3 V_10 )
{
F_4 ( V_2 , F_5 ( struct V_11 , V_14 ) , ~ 0 , V_8 ) ;
return F_4 ( V_2 , F_5 ( struct V_11 , V_15 ) ,
V_9 , V_10 ) ;
}
T_3 F_7 ( struct V_1 * V_2 , T_2 V_8 , T_3 V_9 , T_3 V_10 )
{
F_4 ( V_2 , F_5 ( struct V_11 , V_16 ) , ~ 0 , V_8 ) ;
return F_4 ( V_2 , F_5 ( struct V_11 , V_17 ) ,
V_9 , V_10 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_5 ( struct V_11 , V_18 ) ,
V_19 , V_19 ) ;
}
T_3 F_9 ( struct V_1 * V_2 )
{
T_3 clock = V_20 ;
if ( ! ( F_10 ( V_2 ) & V_21 ) )
return clock ;
switch ( F_2 ( V_2 ) ) {
case V_5 :
case V_6 :
case V_7 :
clock = 20000 * 1000 ;
break;
default:
break;
}
return clock ;
}
T_3 F_11 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_12 ( V_2 , struct V_22 , V_24 ) ;
struct V_25 * V_26 ;
T_3 V_27 ;
if ( F_13 ( V_2 ) < 10 )
return 0 ;
V_26 = V_23 -> V_28 -> V_29 . V_26 ;
if ( F_14 ( V_26 , F_15 ( V_30 ) ) & V_31 ) {
T_3 V_32 , V_33 ;
F_16 ( V_26 , F_15 ( V_34 ) ,
1U << V_35 ) ;
F_17 ( 1000 ) ;
V_32 = F_14 ( V_26 , F_15 ( V_34 ) ) &
V_36 ;
F_16 ( V_26 , F_15 ( V_34 ) , 0 ) ;
V_33 = ( V_32 * V_37 ) / 4 ;
V_27 = ( V_33 + 50000 ) / 100000 * 100 ;
} else
V_27 = 0 ;
return V_27 ;
}
