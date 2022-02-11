int F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 , bool V_4 )
{
T_2 V_5 ;
bool V_6 ;
int V_7 ;
V_5 = F_2 ( V_1 + V_8 ) ;
V_6 = V_5 & V_3 ;
if ( V_6 == V_4 )
return 0 ;
if ( V_4 )
V_5 |= V_2 ;
else
V_5 &= ~ V_2 ;
F_3 ( V_5 , V_1 + V_8 ) ;
for ( V_7 = 5000 ; V_7 > 0 ; V_7 -= 50 ) {
V_5 = F_2 ( V_1 + V_8 ) ;
if ( ( V_5 & V_3 ) == ( V_4 ? V_3 : 0 ) )
break;
F_4 ( 50 ) ;
}
if ( V_7 <= 0 )
return - V_9 ;
F_4 ( 10 ) ;
return 0 ;
}
