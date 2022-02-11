int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
if ( V_2 -> V_6 -> V_7 == 0 ) {
switch ( V_3 ) {
case 4 : return F_2 ( 0x2a0 ) ;
case 8 : return F_2 ( 0x2a0 ) ;
case 6 : return F_2 ( 0x240 ) ;
default:
F_3 ( V_8 L_1
L_2 , V_3 ) ;
return F_2 ( 0x240 ) ;
}
} else {
switch ( V_4 ) {
case 0 : V_5 = F_2 ( 0x240 ) ; break;
case 1 : V_5 = F_2 ( 0x240 ) ; break;
case 2 : V_5 = F_2 ( 0x240 ) ; break;
case 3 : V_5 = F_2 ( 0x240 ) ; break;
case 4 : V_5 = F_2 ( 0x240 ) ; break;
default: V_5 = - 1 ; break;
}
}
return V_5 ;
}
