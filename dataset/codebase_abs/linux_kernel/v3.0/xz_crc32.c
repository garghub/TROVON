T_1 void F_1 ( void )
{
const T_2 V_1 = 0xEDB88320 ;
T_2 V_2 ;
T_2 V_3 ;
T_2 V_4 ;
for ( V_2 = 0 ; V_2 < 256 ; ++ V_2 ) {
V_4 = V_2 ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 )
V_4 = ( V_4 >> 1 ) ^ ( V_1 & ~ ( ( V_4 & 1 ) - 1 ) ) ;
V_5 [ V_2 ] = V_4 ;
}
return;
}
T_1 T_2 F_2 ( const T_3 * V_6 , T_4 V_7 , T_2 V_8 )
{
V_8 = ~ V_8 ;
while ( V_7 != 0 ) {
V_8 = V_5 [ * V_6 ++ ^ ( V_8 & 0xFF ) ] ^ ( V_8 >> 8 ) ;
-- V_7 ;
}
return ~ V_8 ;
}
