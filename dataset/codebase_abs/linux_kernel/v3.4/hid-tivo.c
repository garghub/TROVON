static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
switch ( V_8 -> V_11 & V_12 ) {
case V_13 :
switch ( V_8 -> V_11 & V_14 ) {
case 0x3d : F_2 ( V_15 ) ; break;
case 0x3e : F_2 ( V_16 ) ; break;
case 0x41 : F_2 ( V_17 ) ; break;
case 0x42 : F_2 ( V_18 ) ; break;
default:
return 0 ;
}
break;
case V_19 :
switch ( V_8 -> V_11 & V_14 ) {
case 0x083 : F_2 ( V_20 ) ; break;
case 0x209 : F_2 ( V_21 ) ; break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
return 1 ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_22 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( & V_22 ) ;
}
