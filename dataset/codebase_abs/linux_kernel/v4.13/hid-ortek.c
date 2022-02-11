static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 56 && V_3 [ 54 ] == 0x25 && V_3 [ 55 ] == 0x01 ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x92 ;
} else if ( * V_4 >= 54 && V_3 [ 52 ] == 0x25 && V_3 [ 53 ] == 0x01 ) {
F_2 ( V_2 , L_2 ) ;
V_3 [ 53 ] = 0x65 ;
}
return V_3 ;
}
