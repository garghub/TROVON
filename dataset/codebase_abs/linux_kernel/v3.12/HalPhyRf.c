void F_1 ( struct V_1 * V_2 )
{
}
T_1 F_2 ( T_1 V_3 )
{
T_1 V_4 [ V_5 ] = {
1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 ,
36 , 38 , 40 , 42 , 44 , 46 , 48 , 50 , 52 , 54 , 56 , 58 , 60 , 62 , 64 ,
100 , 102 , 104 , 106 , 108 , 110 , 112 , 114 , 116 , 118 , 120 , 122 ,
124 , 126 , 128 , 130 , 132 , 134 , 136 , 138 , 140 , 149 , 151 , 153 ,
155 , 157 , 159 , 161 , 163 , 165
} ;
T_1 V_6 = V_3 ;
if ( V_3 > 14 ) {
for ( V_6 = 14 ; V_6 < sizeof( V_4 ) ; V_6 ++ ) {
if ( V_4 [ V_6 ] == V_3 )
return V_6 - 13 ;
}
}
return 0 ;
}
