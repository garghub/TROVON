static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_4 ) ;
T_1 V_7 ;
T_2 V_8 ;
F_3 ( V_6 -> V_2 , V_9 , & V_8 ) ;
V_6 -> V_10 . V_8 = ( T_1 ) V_8 ;
F_4 ( V_11 , L_1 ,
V_6 -> V_10 . V_8 ) ;
F_5 ( V_2 , 0x98 , & V_7 ) ;
V_7 |= V_12 ;
F_6 ( V_2 , 0x98 , V_7 ) ;
V_7 = 0x17 ;
F_6 ( V_2 , 0x70f , V_7 ) ;
}
bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_4 ) ;
T_2 V_13 ;
T_2 V_14 ;
T_1 V_15 ;
T_2 V_16 ;
V_13 = V_2 -> V_17 ;
V_14 = V_2 -> V_18 ;
V_15 = V_2 -> V_19 ;
F_8 ( V_2 , 0x3C , & V_16 ) ;
V_6 -> V_20 = V_6 -> V_21 -> V_22 ;
if ( V_14 == 0x8172 ) {
switch ( V_15 ) {
case V_23 :
F_9 ( & V_2 -> V_4 ,
L_2 ,
V_14 ) ;
V_6 -> V_20 = V_24 ;
break;
case V_25 :
F_9 ( & V_2 -> V_4 ,
L_3 ,
V_14 ) ;
V_6 -> V_20 = V_26 ;
break;
default:
F_9 ( & V_2 -> V_4 ,
L_4 ,
V_2 -> V_17 , V_2 -> V_18 ) ;
V_6 -> V_20 = V_27 ;
return false ;
}
}
if ( V_6 -> V_21 -> V_22 != V_6 -> V_20 ) {
F_9 ( & V_2 -> V_4 ,
L_5 ,
V_6 -> V_21 -> V_22 , V_6 -> V_20 ) ;
F_9 ( & V_2 -> V_4 ,
L_6 ) ;
return false ;
}
F_1 ( V_2 , V_4 ) ;
return true ;
}
