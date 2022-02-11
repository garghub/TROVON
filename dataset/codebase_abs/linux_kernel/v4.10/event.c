int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
bool * V_5 )
{
T_1 V_6 ;
switch ( V_4 ) {
case V_7 :
V_6 = V_8 ;
break;
case V_9 :
V_6 = V_10 ;
break;
default:
return 0 ;
}
return F_2 ( V_2 , V_6 , V_5 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_13 ;
V_13 = F_4 ( V_12 -> V_14 ) ;
V_13 &= ~ ( F_4 ( V_12 -> V_15 ) ) ;
F_5 ( V_16 , L_1 , V_13 ) ;
if ( V_13 & V_17 ) {
F_5 ( V_16 , L_2 ,
V_12 -> V_18 ) ;
if ( V_2 -> V_19 )
F_6 ( V_2 , V_2 -> V_19 ) ;
}
if ( V_13 & V_20 ) {
F_5 ( V_16 ,
L_3 ,
V_12 -> V_18 ) ;
F_7 ( V_2 ) ;
}
if ( V_13 & V_21 )
F_8 ( V_2 ,
V_12 -> V_18 ) ;
if ( V_13 & V_22 )
F_9 ( V_2 ,
V_12 -> V_23 ) ;
if ( V_13 & V_24 )
F_10 ( V_2 , 0xff ) ;
if ( V_13 & V_25 )
F_11 ( V_2 , V_12 -> V_26 ) ;
if ( V_13 & V_27 )
F_12 ( V_2 ,
F_13 ( V_12 -> V_28 ) ,
V_12 -> V_29 ) ;
if ( V_13 & V_30 )
F_14 ( V_2 , 0xff ,
V_12 -> V_31 ) ;
if ( V_13 & V_32 )
F_15 ( V_2 ) ;
if ( V_13 & V_33 )
F_16 ( V_2 ,
F_17 ( V_12 -> V_34 ) ) ;
if ( V_13 & V_35 )
F_18 ( V_2 ,
F_17 ( V_12 -> V_36 ) ) ;
if ( V_13 & V_37 )
F_19 ( V_2 ) ;
return 0 ;
}
