static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
F_2 ( V_14 , V_4 -> V_15 -> V_16 ) ;
switch ( V_8 -> V_11 & V_17 ) {
case 0xff01 : F_3 ( V_18 ) ; break;
case 0xff02 : F_3 ( V_19 ) ; break;
case 0xff03 : F_3 ( V_20 ) ; break;
case 0xff04 : F_3 ( V_21 ) ; break;
case 0xff05 : F_3 ( V_22 ) ; break;
case 0xff06 : F_3 ( V_23 ) ; break;
case 0xff07 : F_3 ( V_24 ) ; break;
case 0xff08 : F_3 ( V_25 ) ; break;
case 0xff09 : F_3 ( V_26 ) ; break;
case 0xff0a : F_3 ( V_27 ) ; break;
case 0xff0b : F_3 ( V_28 ) ; break;
case 0x00f1 : F_3 ( V_29 ) ; break;
case 0x00f2 : F_3 ( V_30 ) ; break;
case 0x00f3 : F_3 ( V_31 ) ; break;
case 0x00f4 : F_3 ( V_32 ) ; break;
case 0x00f7 : F_3 ( V_33 ) ; break;
case 0x00f8 : F_3 ( V_34 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static T_1 * F_4 ( struct V_1 * V_2 , T_1 * V_35 ,
unsigned int * V_36 )
{
struct V_37 * V_38 = F_5 ( V_2 -> V_39 . V_40 ) ;
if ( V_38 -> V_41 -> V_42 . V_43 == 1 ) {
switch ( V_2 -> V_44 ) {
case V_45 :
if ( * V_36 >= 128 && V_35 [ 64 ] == 0xff && V_35 [ 65 ] == 0x7f
&& V_35 [ 69 ] == 0xff && V_35 [ 70 ] == 0x7f ) {
F_6 ( V_2 , L_1 ) ;
V_35 [ 65 ] = V_35 [ 70 ] = 0x2f ;
}
break;
}
}
return V_35 ;
}
