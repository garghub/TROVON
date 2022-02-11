static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_12 ) != V_13 )
return 0 ;
switch ( V_8 -> V_11 & V_14 ) {
case 0x230 : F_2 ( V_15 ) ; break;
case 0x231 : F_3 ( V_16 ) ; break;
case 0x232 : F_3 ( V_17 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_18 )
{
if ( ! ( V_2 -> V_19 & V_20 ) || ! V_6 -> V_21 ||
! V_8 -> type )
return 0 ;
if ( V_8 -> type == V_22 && V_8 -> V_23 == V_17 ) {
struct V_24 * V_25 = V_6 -> V_21 -> V_25 ;
F_5 ( V_25 , V_8 -> type , V_16 , - V_18 ) ;
return 1 ;
}
return 0 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_26 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_26 ) ;
}
