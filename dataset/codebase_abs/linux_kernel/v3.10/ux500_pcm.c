static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
T_1 V_11 , V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
F_2 ( V_10 , L_1 , V_17 , V_7 -> V_18 ,
F_3 ( V_5 ) ) ;
V_16 = F_4 ( V_7 , V_5 ) ;
V_14 = V_16 -> V_14 ;
V_12 = V_19 ;
switch ( V_16 -> V_20 ) {
case 32 :
V_11 = V_21 ;
break;
case 16 :
V_11 = V_19 ;
break;
case 8 :
V_11 = V_22 ;
break;
default:
V_11 = V_21 ;
}
if ( V_5 -> V_23 == V_24 ) {
V_14 -> V_25 . V_26 = V_12 ;
V_14 -> V_27 . V_26 = V_11 ;
} else {
V_14 -> V_25 . V_26 = V_11 ;
V_14 -> V_27 . V_26 = V_12 ;
}
return F_5 ( V_28 , V_14 ) ;
}
int F_6 ( struct V_29 * V_30 )
{
int V_31 ;
V_31 = F_7 ( & V_30 -> V_10 ,
& V_32 ,
V_33 |
V_34 |
V_35 ) ;
if ( V_31 < 0 ) {
F_8 ( & V_30 -> V_10 ,
L_2 ,
V_17 , V_30 -> V_36 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
int F_9 ( struct V_29 * V_30 )
{
F_10 ( & V_30 -> V_10 ) ;
return 0 ;
}
