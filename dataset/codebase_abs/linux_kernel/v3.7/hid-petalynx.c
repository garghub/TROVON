static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 60 && V_3 [ 39 ] == 0x2a && V_3 [ 40 ] == 0xf5 &&
V_3 [ 41 ] == 0x00 && V_3 [ 59 ] == 0x26 &&
V_3 [ 60 ] == 0xf9 && V_3 [ 61 ] == 0x00 ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 60 ] = 0xfa ;
V_3 [ 40 ] = 0xfa ;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
if ( ( V_10 -> V_13 & V_14 ) == V_15 ) {
switch ( V_10 -> V_13 & V_16 ) {
case 0x05a : F_4 ( V_17 ) ; break;
case 0x05b : F_4 ( V_18 ) ; break;
case 0x05c : F_4 ( V_19 ) ; break;
case 0x05d : F_4 ( V_20 ) ; break;
case 0x05e : F_4 ( V_21 ) ; break;
default:
return 0 ;
}
return 1 ;
}
if ( ( V_10 -> V_13 & V_14 ) == V_22 ) {
switch ( V_10 -> V_13 & V_16 ) {
case 0x0f6 : F_4 ( V_23 ) ; break;
case 0x0fa : F_4 ( V_24 ) ; break;
default:
return 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
int V_27 ;
V_2 -> V_28 |= V_29 ;
V_27 = F_6 ( V_2 ) ;
if ( V_27 ) {
F_7 ( V_2 , L_2 ) ;
goto V_30;
}
V_27 = F_8 ( V_2 , V_31 ) ;
if ( V_27 ) {
F_7 ( V_2 , L_3 ) ;
goto V_30;
}
return 0 ;
V_30:
return V_27 ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_32 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_32 ) ;
}
