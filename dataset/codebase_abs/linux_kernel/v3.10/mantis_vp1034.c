int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
switch ( V_3 ) {
case V_8 :
F_2 ( V_9 , 1 , L_1 ) ;
F_3 ( V_5 , 13 , 1 ) ;
F_3 ( V_5 , 14 , 0 ) ;
break;
case V_10 :
F_2 ( V_9 , 1 , L_2 ) ;
F_3 ( V_5 , 13 , 1 ) ;
F_3 ( V_5 , 14 , 1 ) ;
break;
case V_11 :
F_2 ( V_9 , 1 , L_3 ) ;
break;
default:
F_2 ( V_9 , 1 , L_4 , ( V_12 ) V_3 ) ;
return - V_13 ;
}
F_4 ( 0x00 , V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_5 -> V_16 ;
int V_17 = 0 ;
V_17 = F_6 ( V_5 , V_18 ) ;
if ( V_17 == 0 ) {
F_7 ( V_5 ) ;
F_8 ( 250 ) ;
F_2 ( V_9 , 1 , L_5 ) ;
V_2 = F_9 ( V_19 , & V_20 , V_16 ) ;
if ( V_2 ) {
F_2 ( V_9 , 1 ,
L_6 ,
V_20 . V_21 ) ;
} else {
return - 1 ;
}
} else {
F_2 ( V_9 , 1 , L_7 ,
V_16 -> V_22 ,
V_17 ) ;
return - V_23 ;
}
V_5 -> V_2 = V_2 ;
F_2 ( V_9 , 1 , L_8 ) ;
return 0 ;
}
