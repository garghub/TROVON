static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = V_6 -> V_9 & - 16 ;
if ( V_8 == V_10 )
V_2 -> V_11 = V_6 -> V_11 ;
else if ( V_8 == V_12 )
V_2 -> V_11 |= V_6 -> V_11 ;
else if ( V_8 == V_13 )
V_2 -> V_11 &= V_6 -> V_11 ;
else
V_2 -> V_11 ^= V_6 -> V_11 ;
return V_6 -> V_9 | ~ V_14 ;
}
static int F_2 ( const struct V_15 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_16 ;
V_16 = V_6 -> V_9 | ~ V_14 ;
if ( V_17 && V_16 == V_18 )
return - V_19 ;
if ( V_16 < - V_20 || V_16 >= 0 )
return - V_19 ;
V_16 = V_6 -> V_9 & ~ V_14 ;
if ( V_16 != V_10 && V_16 != V_12 &&
V_16 != V_13 && V_16 != V_21 )
return - V_19 ;
return 0 ;
}
static void F_3 ( void * V_22 , const void * V_23 )
{
const struct V_24 * V_25 = V_23 ;
struct V_5 * V_26 = V_22 ;
V_26 -> V_11 = V_25 -> V_11 ;
V_26 -> V_9 = V_25 -> V_9 ;
}
static int F_4 ( void T_1 * V_22 , const void * V_23 )
{
struct V_24 T_1 * V_25 = V_22 ;
const struct V_5 * V_26 = V_23 ;
if ( F_5 ( V_26 -> V_11 , & V_25 -> V_11 ) ||
F_5 ( V_26 -> V_9 , & V_25 -> V_9 ) )
return - V_27 ;
return 0 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_28 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_28 ) ;
}
