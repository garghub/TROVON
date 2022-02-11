static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_4 ) ;
T_1 V_7 ;
int V_8 ;
T_1 V_9 ;
V_8 = F_3 ( V_6 -> V_2 , V_10 ) ;
F_4 ( V_6 -> V_2 , V_8 + V_11 , & V_9 ) ;
V_6 -> V_12 . V_9 = V_9 ;
F_5 ( V_13 , L_1 ,
V_6 -> V_12 . V_9 ) ;
F_4 ( V_2 , 0x98 , & V_7 ) ;
V_7 |= V_14 ;
F_6 ( V_2 , 0x98 , V_7 ) ;
V_7 = 0x17 ;
F_6 ( V_2 , 0x70f , V_7 ) ;
}
bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_4 ) ;
T_2 V_15 ;
T_2 V_16 ;
T_1 V_17 ;
T_2 V_18 ;
V_15 = V_2 -> V_19 ;
V_16 = V_2 -> V_20 ;
V_17 = V_2 -> V_21 ;
F_8 ( V_2 , 0x3C , & V_18 ) ;
V_6 -> V_22 = V_6 -> V_23 -> V_24 ;
if ( V_16 == 0x8172 ) {
switch ( V_17 ) {
case V_25 :
F_9 ( V_26 L_2
L_3 , V_16 ) ;
V_6 -> V_22 = V_27 ;
break;
case V_28 :
F_9 ( V_26 L_4
L_3 , V_16 ) ;
V_6 -> V_22 = V_29 ;
break;
default:
F_9 ( V_26 L_5 ,
V_2 -> V_19 , V_2 -> V_20 ) ;
V_6 -> V_22 = V_30 ;
return false ;
}
}
if ( V_6 -> V_23 -> V_24 != V_6 -> V_22 ) {
F_9 ( V_26 L_6 ,
V_6 -> V_23 -> V_24 , V_6 -> V_22 ) ;
F_9 ( V_26 L_7 ) ;
return false ;
}
F_1 ( V_2 , V_4 ) ;
return true ;
}
