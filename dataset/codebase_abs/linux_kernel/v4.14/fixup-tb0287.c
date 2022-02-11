int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned char V_5 ;
int V_6 = - 1 ;
V_5 = V_2 -> V_5 -> V_7 ;
if ( V_5 == 0 ) {
switch ( V_3 ) {
case 16 :
V_6 = V_8 ;
break;
case 17 :
V_6 = V_9 ;
break;
default:
break;
}
} else if ( V_5 == 1 ) {
switch ( F_2 ( V_2 -> V_10 ) ) {
case 0 :
V_6 = V_11 ;
break;
case 2 :
case 3 :
V_6 = V_12 ;
break;
default:
break;
}
} else if ( V_5 > 1 ) {
V_6 = V_11 ;
}
return V_6 ;
}
int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
