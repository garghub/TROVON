int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
switch ( V_4 ) {
case V_9 :
F_2 ( V_10 , 1 , L_1 ) ;
F_3 ( V_6 , 13 , 1 ) ;
F_3 ( V_6 , 14 , 0 ) ;
break;
case V_11 :
F_2 ( V_10 , 1 , L_2 ) ;
F_3 ( V_6 , 13 , 1 ) ;
F_3 ( V_6 , 14 , 1 ) ;
break;
case V_12 :
F_2 ( V_10 , 1 , L_3 ) ;
break;
default:
F_2 ( V_10 , 1 , L_4 , ( V_13 ) V_4 ) ;
return - V_14 ;
}
F_4 ( 0x00 , V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_6 -> V_17 ;
int V_18 = 0 ;
V_18 = F_6 ( V_6 , V_19 ) ;
if ( V_18 == 0 ) {
F_7 ( V_6 ) ;
F_8 ( 250 ) ;
F_2 ( V_10 , 1 , L_5 ) ;
V_2 = F_9 ( V_20 , & V_21 , V_17 ) ;
if ( V_2 ) {
F_2 ( V_10 , 1 ,
L_6 ,
V_21 . V_22 ) ;
} else {
return - 1 ;
}
} else {
F_2 ( V_10 , 1 , L_7 ,
V_17 -> V_23 ,
V_18 ) ;
return - V_24 ;
}
V_6 -> V_2 = V_2 ;
F_2 ( V_10 , 1 , L_8 ) ;
return 0 ;
}
