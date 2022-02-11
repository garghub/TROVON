static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
F_2 ( & V_6 ) ;
V_5 = 1 << V_3 ;
V_4 = V_7 ;
V_4 |= V_5 ;
V_7 = V_4 ;
F_3 ( & V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_3 , int V_8 )
{
T_1 V_4 ;
T_1 V_5 ;
F_5 ( V_3 , V_8 ) ;
F_2 ( & V_6 ) ;
V_5 = 1 << V_3 ;
V_4 = V_7 ;
V_4 &= ( ~ V_5 ) ;
V_7 = V_4 ;
F_3 ( & V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_9 ;
T_1 V_5 ;
V_5 = 1 << ( V_3 + V_10 ) ;
F_2 ( & V_6 ) ;
V_9 = V_11 ;
F_3 ( & V_6 ) ;
return ( V_9 & V_5 ) != 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
T_1 V_9 ;
T_1 V_5 ;
V_5 = 1 << V_3 ;
F_2 ( & V_6 ) ;
V_9 = V_11 ;
if ( V_12 )
V_9 |= V_5 ;
else
V_9 &= ( ~ V_5 ) ;
V_11 = V_9 ;
F_3 ( & V_6 ) ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_13 , NULL ) ;
}
