int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 >= 0 )
return V_5 ;
V_5 = V_4 ;
V_5 -- ;
if ( V_3 == F_3 ( 23 ) ) {
V_5 = ( V_5 + 0 + V_3 ) % 4 ;
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
return V_5 ;
}
