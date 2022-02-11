static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
switch ( V_8 -> V_11 & V_14 ) {
case 0x00d : F_2 ( V_15 ) ; break;
case 0x024 : F_2 ( V_16 ) ; break;
case 0x025 : F_2 ( V_17 ) ; break;
case 0x027 : F_2 ( V_18 ) ; break;
case 0x031 : F_2 ( V_19 ) ; break;
case 0x032 : F_2 ( V_20 ) ; break;
case 0x033 : F_2 ( V_21 ) ; break;
case 0x047 : F_2 ( V_22 ) ; break;
case 0x048 : F_2 ( V_23 ) ; break;
case 0x049 : F_2 ( V_24 ) ; break;
case 0x04a : F_2 ( V_25 ) ; break;
case 0x04b : F_2 ( V_26 ) ; break;
case 0x04c : F_2 ( V_27 ) ; break;
case 0x04d : F_2 ( V_28 ) ; break;
case 0x050 : F_2 ( V_29 ) ; break;
case 0x05a : F_2 ( V_20 ) ; break;
case 0x05b : F_2 ( V_30 ) ; break;
case 0x05c : F_2 ( V_31 ) ; break;
case 0x05d : F_2 ( V_32 ) ; break;
case 0x05e : F_2 ( V_33 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_34 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_34 ) ;
}
