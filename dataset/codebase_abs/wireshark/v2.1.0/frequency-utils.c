T_1
F_1 ( T_2 V_1 ) {
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 >= V_4 [ V_2 ] . V_5 && V_1 <= V_4 [ V_2 ] . V_6 ) {
return ( ( V_1 - V_4 [ V_2 ] . V_5 ) / V_7 ) + V_4 [ V_2 ] . V_8 ;
}
}
return - 1 ;
}
T_2
F_2 ( T_1 V_9 , T_3 V_10 ) {
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_10 == V_4 [ V_2 ] . V_10 &&
V_9 >= V_4 [ V_2 ] . V_8 && V_9 <= F_3 ( V_4 [ V_2 ] ) ) {
return ( ( V_9 - V_4 [ V_2 ] . V_8 ) * V_7 ) + V_4 [ V_2 ] . V_5 ;
}
}
return 0 ;
}
T_4 *
F_4 ( T_2 V_1 ) {
T_1 V_9 = F_1 ( V_1 ) ;
T_3 V_10 = F_5 ( V_1 ) ;
if ( V_9 < 0 ) {
return F_6 ( L_1 , V_1 ) ;
} else {
return F_6 ( L_2 , V_1 , V_10 ? L_3 : L_4 ,
V_9 ) ;
}
}
