int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
unsigned char V_5 = V_4 ;
V_5 -- ;
if ( V_3 == F_2 ( 23 ) ) {
V_5 = ( V_5 + 2 ) % 4 ;
} else if ( V_3 == F_2 ( 22 ) ) {
V_5 = ( V_5 + 0 ) % 4 ;
} else {
if ( V_6 & V_7 )
V_5 = ( V_5 + 33 - V_3 ) % 4 ;
else
V_5 = ( V_5 + 3 + V_3 ) % 4 ;
}
V_5 ++ ;
switch ( V_5 ) {
case 1 :
V_5 = V_8 ;
break;
case 2 :
V_5 = V_9 ;
break;
case 3 :
V_5 = V_10 ;
break;
case 4 :
V_5 = V_11 ;
break;
}
if ( V_2 -> V_12 -> V_13 == NULL &&
V_3 == F_2 ( 24 ) )
V_5 = V_14 ;
return V_5 ;
}
