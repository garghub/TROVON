static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 == 137 && V_3 [ 20 ] == 0x09 && V_3 [ 21 ] == 0x33
&& V_3 [ 94 ] == 0x81 && V_3 [ 95 ] == 0x03
&& V_3 [ 110 ] == 0x81 && V_3 [ 111 ] == 0x03 ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 20 ] = 0x15 ;
V_3 [ 21 ] = 0x00 ;
V_3 [ 95 ] = 0x02 ;
V_3 [ 111 ] = 0x02 ;
}
return V_3 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_5 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_5 ) ;
}
