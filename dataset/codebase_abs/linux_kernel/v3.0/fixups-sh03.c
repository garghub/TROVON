int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
if ( V_2 -> V_6 -> V_7 == 0 ) {
switch ( V_3 ) {
case 4 : return 5 ;
case 8 : return 5 ;
case 6 : return 2 ;
default:
F_2 ( V_8 L_1
L_2 , V_3 ) ;
return 2 ;
}
} else {
switch ( V_4 ) {
case 0 : V_5 = 2 ; break;
case 1 : V_5 = 2 ; break;
case 2 : V_5 = 2 ; break;
case 3 : V_5 = 2 ; break;
case 4 : V_5 = 2 ; break;
default: V_5 = - 1 ; break;
}
}
return V_5 ;
}
