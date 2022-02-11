unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 V_5 = { 0 , } ;
T_1 * V_6 ;
T_1 * V_7 ;
T_2 V_8 ;
int V_9 ;
if ( V_3 < F_2 ( V_10 ) )
goto V_11;
F_3 (cpu) {
V_6 = ( T_1 * ) & ( F_4 ( V_12 , V_9 ) ) ;
V_7 = ( T_1 * ) & V_5 ;
for ( V_8 = 0 ; V_8 < sizeof( V_5 ) / sizeof( T_1 ) ; V_8 ++ )
* ( V_7 ++ ) += * ( V_6 ++ ) ;
}
F_5 ( V_2 , ( T_1 * ) & V_5 , V_10 ,
F_2 ( V_10 ) ) ;
V_11:
return F_2 ( V_10 ) ;
}
