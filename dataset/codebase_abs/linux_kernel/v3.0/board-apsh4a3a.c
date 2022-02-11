static int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
static int F_4 ( void )
{
struct V_2 * V_2 ;
int V_3 ;
V_2 = F_5 ( NULL , L_1 ) ;
if ( ! V_2 || F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
V_3 = F_8 ( V_2 , 33333000 ) ;
F_9 ( V_2 ) ;
return V_3 ;
}
static void T_1 F_10 ( char * * V_4 )
{
F_11 ( V_5 L_2 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( V_6 ) ;
}
static int F_14 ( void )
{
int V_7 = 0 ;
V_7 &= ~ V_8 ;
V_7 &= ~ V_9 ;
V_7 &= ~ V_10 ;
V_7 &= ~ V_11 ;
V_7 |= V_12 ;
V_7 &= ~ V_13 ;
V_7 |= V_14 ;
V_7 |= V_15 ;
V_7 |= V_16 ;
V_7 |= V_17 ;
V_7 |= V_18 ;
V_7 |= V_19 ;
V_7 |= V_20 ;
V_7 &= ~ V_21 ;
V_7 |= V_22 ;
return V_7 ;
}
