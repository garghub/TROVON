static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
switch ( V_8 -> V_11 & V_14 ) {
case 0x004 : F_2 ( V_15 ) ; break;
case 0x006 : F_2 ( V_16 ) ; break;
case 0x008 : F_2 ( V_17 ) ; break;
case 0x00c : F_2 ( V_18 ) ; break;
case 0x00e : F_2 ( V_19 ) ; break;
case 0x00f : F_2 ( V_20 ) ; break;
case 0x010 : F_2 ( V_21 ) ; break;
case 0x011 : F_2 ( V_22 ) ; break;
case 0x013 : F_2 ( V_23 ) ; break;
case 0x017 : F_2 ( V_24 ) ; break;
case 0x019 : F_2 ( V_25 ) ; break;
case 0x01d : F_2 ( V_26 ) ; break;
case 0x01e : F_2 ( V_27 ) ; break;
case 0x01f : F_2 ( V_28 ) ; break;
case 0x020 : F_2 ( V_29 ) ; break;
case 0x021 : F_2 ( V_30 ) ; break;
case 0x022 : F_2 ( V_31 ) ; break;
case 0x023 : F_2 ( V_32 ) ; break;
case 0x024 : F_2 ( V_33 ) ; break;
case 0x025 : F_2 ( V_34 ) ; break;
case 0x026 : F_2 ( V_35 ) ; break;
case 0x027 : F_2 ( V_36 ) ; break;
case 0x028 : F_2 ( V_37 ) ; break;
case 0x029 : F_2 ( V_38 ) ; break;
case 0x02b : F_2 ( V_39 ) ; break;
case 0x03f : F_2 ( V_40 ) ; break;
case 0x04a : F_2 ( V_41 ) ; break;
case 0x04b : F_2 ( V_42 ) ; break;
case 0x04d : F_2 ( V_43 ) ; break;
case 0x04e : F_2 ( V_44 ) ; break;
case 0x051 : F_2 ( V_45 ) ; break;
case 0x052 : F_2 ( V_46 ) ; break;
case 0x0e0 :
case 0x0e1 :
case 0x0e2 :
case 0x0e3 :
case 0x0e4 :
case 0x0e5 :
case 0x0e6 :
case 0x0e7 :
default:
return - 1 ;
}
return 1 ;
}
