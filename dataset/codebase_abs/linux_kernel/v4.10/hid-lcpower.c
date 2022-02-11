static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
switch ( V_8 -> V_11 & V_14 ) {
case 0x046 : F_2 ( V_15 ) ; break;
case 0x047 : F_2 ( V_16 ) ; break;
case 0x049 : F_2 ( V_17 ) ; break;
case 0x04a : F_2 ( V_18 ) ; break;
case 0x00d : F_2 ( V_19 ) ; break;
case 0x025 : F_2 ( V_20 ) ; break;
case 0x048 : F_2 ( V_21 ) ; break;
case 0x024 : F_2 ( V_22 ) ; break;
default:
return 0 ;
}
return 1 ;
}
