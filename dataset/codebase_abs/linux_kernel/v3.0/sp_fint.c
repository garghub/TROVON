T_1 F_1 ( int V_1 )
{
unsigned V_2 ;
int V_3 ;
int V_4 ;
V_5 ;
if ( V_1 == 0 )
return F_2 ( 0 ) ;
if ( V_1 == 1 || V_1 == - 1 )
return F_3 ( V_1 < 0 ) ;
if ( V_1 == 10 || V_1 == - 10 )
return F_4 ( V_1 < 0 ) ;
V_4 = ( V_1 < 0 ) ;
if ( V_4 ) {
if ( V_1 == ( 1 << 31 ) )
V_2 = ( ( unsigned ) 1 << 31 ) ;
else
V_2 = - V_1 ;
} else {
V_2 = V_1 ;
}
V_3 = V_6 + 3 ;
if ( V_2 >> ( V_6 + 1 + 3 ) ) {
while ( V_2 >> ( V_6 + 1 + 3 ) ) {
F_5 () ;
}
} else {
while ( ( V_2 >> ( V_6 + 3 ) ) == 0 ) {
V_2 <<= 1 ;
V_3 -- ;
}
}
F_6 ( V_4 , V_3 , V_2 , L_1 , V_1 ) ;
}
T_1 F_7 ( unsigned int V_7 )
{
if ( ( int ) V_7 < 0 )
return F_8 ( F_9 () ,
F_1 ( V_7 & ~ ( 1 << 31 ) ) ) ;
return F_1 ( V_7 ) ;
}
