static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_4 -> V_5 ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 & V_8 )
V_3 &= ~ ( 1 << V_2 -> V_9 ) ;
else
V_3 |= ( 1 << V_2 -> V_9 ) ;
V_4 -> V_10 ( V_3 , V_2 -> V_6 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_4 -> V_5 ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 & V_8 )
V_3 |= ( 1 << V_2 -> V_9 ) ;
else
V_3 &= ~ ( 1 << V_2 -> V_9 ) ;
V_4 -> V_10 ( V_3 , V_2 -> V_6 ) ;
}
void F_3 ( void )
{
struct V_1 * V_11 ;
F_4 (c, &autoidle_clks, node)
F_1 ( V_11 ) ;
}
void F_5 ( void )
{
struct V_1 * V_11 ;
F_4 (c, &autoidle_clks, node)
F_2 ( V_11 ) ;
}
int T_2 F_6 ( struct V_12 * V_13 )
{
T_1 V_9 ;
struct V_1 * V_2 ;
if ( F_7 ( V_13 , L_1 , & V_9 ) )
return 0 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_16 = V_13 -> V_16 ;
V_2 -> V_6 = F_9 ( V_13 , 0 ) ;
if ( F_10 ( V_2 -> V_6 ) ) {
F_11 ( V_2 ) ;
return - V_17 ;
}
if ( F_12 ( V_13 , L_2 ) )
V_2 -> V_7 |= V_8 ;
F_13 ( & V_2 -> V_13 , & V_18 ) ;
return 0 ;
}
