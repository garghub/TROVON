T_1 F_1 ( T_1 V_1 )
{
T_2 V_2 ;
T_1 V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_1 == V_5 [ V_2 ] . V_1 ) {
V_3 = V_5 [ V_2 ] . V_6 ;
break;
}
}
if ( V_2 == V_4 )
V_3 = 2412 ;
return V_3 ;
}
T_1 F_2 ( T_1 V_3 )
{
T_2 V_2 ;
T_1 V_7 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_3 == V_5 [ V_2 ] . V_6 ) {
V_7 = V_5 [ V_2 ] . V_1 ;
break;
}
}
if ( V_2 == V_4 )
V_7 = 1 ;
return V_7 ;
}
