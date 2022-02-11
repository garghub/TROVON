static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
F_2 ( V_14 , V_4 -> V_15 -> V_16 ) ;
switch ( V_8 -> V_11 & V_17 ) {
case 0x00d : F_3 ( V_18 ) ; break;
case 0x024 : F_3 ( V_19 ) ; break;
case 0x025 : F_3 ( V_20 ) ; break;
case 0x046 : F_3 ( V_21 ) ; break;
case 0x047 : F_3 ( V_22 ) ; break;
case 0x048 : F_3 ( V_21 ) ; break;
case 0x049 : F_3 ( V_23 ) ; break;
case 0x04a : F_3 ( V_24 ) ; break;
case 0x05a : F_3 ( V_25 ) ; break;
case 0x05b : F_3 ( V_26 ) ; break;
case 0x05c : F_3 ( V_27 ) ; break;
case 0x05d : F_3 ( V_28 ) ; break;
case 0x05e : F_3 ( V_29 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_30 )
{
if ( ! ( V_2 -> V_31 & V_32 ) || ! V_6 -> V_33 )
return 0 ;
if ( ( V_8 -> V_11 & V_12 ) == V_34 &&
( V_8 -> V_11 & 0xff ) == 0x82 ) {
struct V_35 * V_15 = V_6 -> V_33 -> V_15 ;
F_5 ( V_15 , V_8 -> type , V_8 -> V_36 , 1 ) ;
F_6 ( V_15 ) ;
F_5 ( V_15 , V_8 -> type , V_8 -> V_36 , 0 ) ;
F_6 ( V_15 ) ;
return 1 ;
}
return 0 ;
}
