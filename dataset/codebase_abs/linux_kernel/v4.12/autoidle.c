int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_3 -> V_4 && V_3 -> V_4 -> V_5 )
V_3 -> V_4 -> V_5 ( V_3 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_3 -> V_4 && V_3 -> V_4 -> V_6 )
V_3 -> V_4 -> V_6 ( V_3 ) ;
return 0 ;
}
static void F_5 ( struct V_7 * V_1 )
{
T_1 V_8 ;
V_8 = V_9 -> V_10 ( & V_1 -> V_11 ) ;
if ( V_1 -> V_12 & V_13 )
V_8 &= ~ ( 1 << V_1 -> V_14 ) ;
else
V_8 |= ( 1 << V_1 -> V_14 ) ;
V_9 -> V_15 ( V_8 , & V_1 -> V_11 ) ;
}
static void F_6 ( struct V_7 * V_1 )
{
T_1 V_8 ;
V_8 = V_9 -> V_10 ( & V_1 -> V_11 ) ;
if ( V_1 -> V_12 & V_13 )
V_8 |= ( 1 << V_1 -> V_14 ) ;
else
V_8 &= ~ ( 1 << V_1 -> V_14 ) ;
V_9 -> V_15 ( V_8 , & V_1 -> V_11 ) ;
}
static void F_7 ( void )
{
struct V_7 * V_3 ;
F_8 (c, &autoidle_clks, node)
F_5 ( V_3 ) ;
}
static void F_9 ( void )
{
struct V_7 * V_3 ;
F_8 (c, &autoidle_clks, node)
F_6 ( V_3 ) ;
}
int T_2 F_10 ( struct V_16 * V_17 )
{
T_1 V_14 ;
struct V_7 * V_1 ;
int V_18 ;
if ( F_11 ( V_17 , L_1 , & V_14 ) )
return 0 ;
V_1 = F_12 ( sizeof( * V_1 ) , V_19 ) ;
if ( ! V_1 )
return - V_20 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_21 = V_17 -> V_21 ;
V_18 = F_13 ( V_17 , 0 , & V_1 -> V_11 ) ;
if ( V_18 ) {
F_14 ( V_1 ) ;
return V_18 ;
}
if ( F_15 ( V_17 , L_2 ) )
V_1 -> V_12 |= V_13 ;
F_16 ( & V_1 -> V_17 , & V_22 ) ;
return 0 ;
}
void F_17 ( struct V_23 * V_24 )
{
struct V_2 * V_3 ;
if ( F_18 ( V_24 ) & V_25 )
return;
V_3 = F_2 ( V_24 ) ;
F_16 ( & V_3 -> V_17 , & V_26 ) ;
}
int F_19 ( void )
{
struct V_2 * V_3 ;
F_8 (c, &clk_hw_omap_clocks, node)
if ( V_3 -> V_4 && V_3 -> V_4 -> V_6 )
V_3 -> V_4 -> V_6 ( V_3 ) ;
F_7 () ;
return 0 ;
}
int F_20 ( void )
{
struct V_2 * V_3 ;
F_8 (c, &clk_hw_omap_clocks, node)
if ( V_3 -> V_4 && V_3 -> V_4 -> V_5 )
V_3 -> V_4 -> V_5 ( V_3 ) ;
F_9 () ;
return 0 ;
}
