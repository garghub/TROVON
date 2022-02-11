static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
int V_8 ;
T_1 V_9 = V_3 ;
struct V_10 V_11 [] = {
{ . V_12 = 0x50 , . V_13 = 0 , . V_9 = & V_9 , . V_14 = 1 } ,
{ . V_12 = 0x50 , . V_13 = V_15 , . V_9 = V_4 , . V_14 = V_5 } ,
} ;
V_8 = F_2 ( V_7 , V_11 , 2 ) ;
if ( V_8 < 0 ) {
F_3 ( V_16 , 1 , L_1 ,
V_8 , V_4 [ 0 ] , V_4 [ 1 ] ) ;
return V_8 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_17 [ 6 ] = { 0 } ;
V_8 = F_1 ( V_2 , 0x08 , V_17 , 6 ) ;
if ( V_8 < 0 ) {
F_3 ( V_16 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
F_3 ( V_16 , 0 , L_3 , V_17 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 , T_2 V_18 , T_1 V_19 )
{
T_2 V_20 ;
F_3 ( V_21 , 1 , L_4 , V_18 , V_19 ) ;
V_20 = F_6 ( V_22 ) ;
if ( V_19 )
V_2 -> V_23 = V_20 | ( 1 << V_18 ) ;
else
V_2 -> V_23 = V_20 & ( ~ ( 1 << V_18 ) ) ;
F_3 ( V_21 , 1 , L_5 , V_2 -> V_23 ) ;
F_7 ( V_2 -> V_23 , V_22 ) ;
F_7 ( 0x00 , V_24 ) ;
}
int F_8 ( struct V_1 * V_2 , enum F_8 V_25 )
{
T_2 V_3 ;
V_3 = F_6 ( V_26 ) ;
switch ( V_25 ) {
case V_27 :
F_3 ( V_21 , 1 , L_6 ) ;
V_3 &= 0xff - V_28 ;
F_7 ( V_3 , V_26 ) ;
V_3 |= V_28 ;
F_7 ( V_3 , V_26 ) ;
break;
case V_29 :
F_3 ( V_21 , 1 , L_7 ) ;
V_3 |= V_28 ;
F_7 ( V_3 , V_26 ) ;
V_3 &= 0xff - V_28 ;
F_7 ( V_3 , V_26 ) ;
break;
default:
F_3 ( V_16 , 1 , L_8 , V_25 ) ;
return - 1 ;
}
return 0 ;
}
