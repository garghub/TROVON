unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
if ( V_1 == 0 ) {
V_2 = 0 ;
} else if ( V_1 < F_2 ( V_3 ) ) {
V_2 = V_3 [ V_1 ] ;
if ( V_2 == 0 )
goto V_4;
} else {
V_4:
V_2 = V_5 ;
}
return V_2 ;
}
unsigned int F_3 ( unsigned int V_2 )
{
unsigned int V_1 ;
if ( V_2 == 0 ) {
V_1 = 0 ;
} else if ( V_2 < F_2 ( V_6 ) ) {
V_1 = V_6 [ V_2 ] ;
if ( V_1 == 0 )
goto V_4;
} else {
V_4:
V_1 = V_7 ;
}
return V_1 ;
}
