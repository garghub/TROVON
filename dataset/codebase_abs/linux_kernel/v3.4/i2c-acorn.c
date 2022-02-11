static void F_1 ( void * V_1 , int V_2 )
{
T_1 V_3 = F_2 ( V_4 ) & ~ ( V_5 | V_6 ) ;
T_1 V_7 = V_8 ;
if ( V_2 )
V_7 |= V_5 ;
else
V_7 &= ~ V_5 ;
V_8 = V_7 ;
F_3 ( V_3 | V_7 , V_4 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
T_1 V_3 = F_2 ( V_4 ) & ~ ( V_5 | V_6 ) ;
T_1 V_7 = V_8 ;
if ( V_2 )
V_7 |= V_6 ;
else
V_7 &= ~ V_6 ;
V_8 = V_7 ;
F_3 ( V_3 | V_7 , V_4 ) ;
}
static int F_5 ( void * V_1 )
{
return ( F_2 ( V_4 ) & V_5 ) != 0 ;
}
static int F_6 ( void * V_1 )
{
return ( F_2 ( V_4 ) & V_6 ) != 0 ;
}
static int T_2 F_7 ( void )
{
V_8 = V_9 | V_5 | V_6 ;
return F_8 ( & V_10 ) ;
}
