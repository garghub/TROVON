unsigned long F_1 ( const unsigned long * V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
unsigned long V_4 ;
V_3 = V_2 / V_5 ;
if ( V_2 & ( V_5 - 1 ) ) {
V_4 = ( V_1 [ V_3 ] & ( ~ 0UL >> ( V_5
- ( V_2 & ( V_5 - 1 ) ) ) ) ) ;
if ( V_4 )
goto V_6;
}
while ( V_3 ) {
V_4 = V_1 [ -- V_3 ] ;
if ( V_4 ) {
V_6:
return V_3 * V_5 + F_2 ( V_4 ) ;
}
}
return V_2 ;
}
