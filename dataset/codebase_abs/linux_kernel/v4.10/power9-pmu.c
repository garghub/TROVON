static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = 0 ;
if ( V_1 & V_3 )
return V_2 ;
if ( V_1 & V_4 )
return - 1 ;
if ( V_1 & V_5 )
return - 1 ;
if ( V_1 & V_6 )
return - 1 ;
if ( V_1 & V_7 ) {
V_2 |= V_8 ;
return V_2 ;
}
return - 1 ;
}
static void F_2 ( T_1 V_2 )
{
F_3 ( V_9 , ( F_4 ( V_9 ) | V_2 ) ) ;
}
static int T_2 F_5 ( void )
{
int V_10 = 0 ;
if ( ! V_11 -> V_12 ||
strcmp ( V_11 -> V_12 , L_1 ) )
return - V_13 ;
if ( F_6 ( V_14 ) ) {
V_10 = F_7 ( & V_15 ) ;
} else {
V_10 = F_7 ( & V_16 ) ;
}
if ( V_10 )
return V_10 ;
V_11 -> V_17 |= V_18 ;
return 0 ;
}
