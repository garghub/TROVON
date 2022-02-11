T_1 F_1 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 , T_3 V_4 ) {
T_3 V_5 = 0xFF ;
T_3 V_6 = 0 ;
while ( V_2 -- ) {
V_6 = V_5 ^ F_2 ( V_1 , V_3 ) ;
V_3 ++ ;
V_5 = V_7 [ V_6 ] ;
}
V_5 = V_7 [ V_5 ^ V_4 ] ;
if ( V_5 == 0xCF ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_3 F_3 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 ) {
T_3 V_5 = 0x00 ;
T_3 V_6 = 0 ;
while ( V_2 -- ) {
V_6 = V_5 ^ F_2 ( V_1 , V_3 ) ;
V_3 ++ ;
V_5 = V_7 [ V_6 ] ;
}
return V_5 ;
}
