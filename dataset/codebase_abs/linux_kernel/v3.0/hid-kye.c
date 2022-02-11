static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 74 &&
V_3 [ 61 ] == 0x05 && V_3 [ 62 ] == 0x08 &&
V_3 [ 63 ] == 0x19 && V_3 [ 64 ] == 0x08 &&
V_3 [ 65 ] == 0x29 && V_3 [ 66 ] == 0x0f &&
V_3 [ 71 ] == 0x75 && V_3 [ 72 ] == 0x08 &&
V_3 [ 73 ] == 0x95 && V_3 [ 74 ] == 0x01 ) {
F_2 ( V_2 ,
L_1 ) ;
V_3 [ 62 ] = 0x09 ;
V_3 [ 64 ] = 0x04 ;
V_3 [ 66 ] = 0x07 ;
V_3 [ 72 ] = 0x01 ;
V_3 [ 74 ] = 0x08 ;
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
