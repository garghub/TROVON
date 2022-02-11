static void T_1 * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
default:
case V_4 : return ( void T_1 * ) V_5 ;
case V_6 : return ( void T_1 * ) V_7 ;
case V_8 : return ( void T_1 * ) V_9 ;
}
}
static int F_2 ( struct V_1 * V_2 , unsigned V_10 )
{
void T_1 * V_11 = F_1 ( V_2 ) ;
return ! ! ( F_3 ( V_11 ) & ( 1u << V_10 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_10 , int V_12 )
{
void T_1 * V_11 = F_1 ( V_2 ) ;
if ( V_12 )
F_5 ( V_11 , ( 1u << V_10 ) ) ;
else
F_6 ( V_11 , ( 1u << V_10 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_10 )
{
void T_1 * V_11 = F_1 ( V_2 ) ;
F_8 ( V_11 , F_9 ( V_11 ) & ~ ( 1u << V_10 ) ) ;
F_10 ( V_11 , F_11 ( V_11 ) | ( 1u << V_10 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_10 , int V_12 )
{
void T_1 * V_11 = F_1 ( V_2 ) ;
F_10 ( V_11 , F_11 ( V_11 ) & ~ ( 1u << V_10 ) ) ;
F_4 ( V_11 , V_10 , V_12 ) ;
F_8 ( V_11 , F_9 ( V_11 ) | ( 1u << V_10 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_10 )
{
return F_14 ( V_2 -> V_3 + V_10 , V_2 -> V_13 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_10 )
{
return F_16 ( V_2 -> V_3 + V_10 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_14 ) |
F_18 ( & V_15 ) |
F_18 ( & V_16 ) ;
}
