static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = F_2 ( V_4 , struct V_5 , V_4 ) ;
T_1 V_7 = V_6 -> V_8 ;
if ( V_2 & V_9 )
V_7 |= V_10 ;
if ( V_2 & V_11 )
V_7 |= V_12 ;
if ( V_2 & V_13 )
V_7 |= V_14 ;
F_3 ( V_7 , V_6 -> V_4 . V_15 ) ;
}
static struct V_3 * F_4 ( void )
{
struct V_5 * V_6 = F_5 ( sizeof( * V_6 ) , V_16 ) ;
return V_6 ? & V_6 -> V_4 : NULL ;
}
static int F_6 ( struct V_3 * V_4 , T_2 V_17 )
{
F_7 ( V_17 , V_4 , F_1 ) ;
return 0 ;
}
static T_2 F_8 ( struct V_3 * V_4 )
{
if ( F_9 ( V_4 -> V_15 ) & V_18 )
return V_19 ;
return V_20 ;
}
static T_2 F_10 ( struct V_3 * V_4 )
{
return ( F_9 ( V_4 -> V_15 ) & V_21 ) ? 0 : 0xffff ;
}
static int F_11 ( struct V_3 * V_4 , bool V_22 , int V_23 )
{
struct V_5 * V_6 = F_2 ( V_4 , struct V_5 , V_4 ) ;
if ( V_22 )
V_23 = 0 ;
V_6 -> V_8 = ( V_23 & 1 ) + ( ( V_23 & 2 ) << 1 ) ;
F_12 ( V_6 -> V_8 , V_4 -> V_15 ) ;
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_24 . V_25 , V_26 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_24 . V_25 ) ;
}
