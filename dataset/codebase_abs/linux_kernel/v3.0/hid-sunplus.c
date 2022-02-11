static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 107 && V_3 [ 104 ] == 0x26 && V_3 [ 105 ] == 0x80 &&
V_3 [ 106 ] == 0x03 ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 105 ] = V_3 [ 110 ] = 0x03 ;
V_3 [ 106 ] = V_3 [ 111 ] = 0x21 ;
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
case 0x2003 : F_4 ( V_17 ) ; break;
case 0x2103 : F_4 ( V_18 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int T_2 F_5 ( void )
{
return F_6 ( & V_19 ) ;
}
static void T_3 F_7 ( void )
{
F_8 ( & V_19 ) ;
}
