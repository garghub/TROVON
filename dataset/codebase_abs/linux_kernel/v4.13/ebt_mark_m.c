static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & V_9 )
return ! ! ( V_2 -> V_10 & V_6 -> V_11 ) ^ V_6 -> V_12 ;
return ( ( V_2 -> V_10 & V_6 -> V_11 ) == V_6 -> V_10 ) ^ V_6 -> V_12 ;
}
static int F_2 ( const struct V_13 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_8 & ~ V_14 )
return - V_15 ;
if ( ( V_6 -> V_8 & V_9 ) && ( V_6 -> V_8 & V_16 ) )
return - V_15 ;
if ( ! V_6 -> V_8 )
return - V_15 ;
return 0 ;
}
static void F_3 ( void * V_17 , const void * V_18 )
{
const struct V_19 * V_20 = V_18 ;
struct V_5 * V_21 = V_17 ;
V_21 -> V_10 = V_20 -> V_10 ;
V_21 -> V_11 = V_20 -> V_11 ;
V_21 -> V_12 = V_20 -> V_12 ;
V_21 -> V_8 = V_20 -> V_8 ;
}
static int F_4 ( void T_1 * V_17 , const void * V_18 )
{
struct V_19 T_1 * V_20 = V_17 ;
const struct V_5 * V_21 = V_18 ;
if ( F_5 ( V_21 -> V_10 , & V_20 -> V_10 ) ||
F_5 ( V_21 -> V_11 , & V_20 -> V_11 ) ||
F_5 ( V_21 -> V_12 , & V_20 -> V_12 ) ||
F_5 ( V_21 -> V_8 , & V_20 -> V_8 ) )
return - V_22 ;
return 0 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_23 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_23 ) ;
}
