union V_1 F_1 ( T_1 V_2 )
{
T_2 V_3 ;
int V_4 ;
int V_5 ;
F_2 () ;
if ( V_2 == 0 )
return F_3 ( 0 ) ;
if ( V_2 == 1 || V_2 == - 1 )
return F_4 ( V_2 < 0 ) ;
if ( V_2 == 10 || V_2 == - 10 )
return F_5 ( V_2 < 0 ) ;
V_5 = ( V_2 < 0 ) ;
if ( V_5 ) {
if ( V_2 == ( 1ULL << 63 ) )
V_3 = ( 1ULL << 63 ) ;
else
V_3 = - V_2 ;
} else {
V_3 = V_2 ;
}
V_4 = V_6 + 3 ;
if ( V_3 >> ( V_6 + 1 + 3 ) ) {
while ( V_3 >> ( V_6 + 1 + 3 ) ) {
F_6 () ;
}
} else {
while ( ( V_3 >> ( V_6 + 3 ) ) == 0 ) {
V_3 <<= 1 ;
V_4 -- ;
}
}
return F_7 ( V_5 , V_4 , V_3 ) ;
}
