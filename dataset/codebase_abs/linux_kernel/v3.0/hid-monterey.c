static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 30 && V_3 [ 29 ] == 0x05 && V_3 [ 30 ] == 0x09 ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 30 ] = 0x0c ;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
if ( ( V_10 -> V_13 & V_14 ) != V_15 )
return 0 ;
switch ( V_10 -> V_13 & V_16 ) {
case 0x156 : F_4 ( V_17 ) ; break;
case 0x157 : F_4 ( V_18 ) ; break;
case 0x158 : F_4 ( V_19 ) ; break;
case 0x15c : F_4 ( V_20 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_21 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_21 ) ;
}
