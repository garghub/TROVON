static T_1 F_1 ( T_1 V_1 )
{
T_2 V_2 = ( T_2 ) V_1 ;
T_1 V_3 ;
if ( V_2 >= V_4 )
return 0 ;
V_3 = V_5 ;
if ( V_2 >= 76 && V_2 <= 81 ) {
V_3 |= V_6 ;
V_3 |= V_1 &
( V_7 | V_8 ) ;
} else if ( V_1 &
( V_7 | V_8 ) ) {
return 0 ;
}
return V_3 ;
}
static int F_2 ( void )
{
if ( ! V_9 -> V_10 )
return - V_11 ;
if ( ! strcmp ( V_9 -> V_10 , L_1 ) )
V_4 = 256 ;
else if ( strcmp ( V_9 -> V_10 , L_2 ) )
return - V_11 ;
return F_3 ( & V_12 ) ;
}
