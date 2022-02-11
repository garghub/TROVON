static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
bool V_11 = V_6 -> V_12 & V_13 ;
F_2 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_15 >= V_2 -> V_16 ) {
V_9 -> V_15 -= V_2 -> V_16 ;
V_11 = ! V_11 ;
} else {
V_9 -> V_15 = 0 ;
}
F_3 ( & V_9 -> V_14 ) ;
return V_11 ;
}
static int F_4 ( const struct V_17 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_12 & ~ V_18 )
return - V_19 ;
V_6 -> V_10 = F_5 ( sizeof( * V_6 -> V_10 ) , V_20 ) ;
if ( V_6 -> V_10 == NULL )
return - V_21 ;
F_6 ( & V_6 -> V_10 -> V_14 ) ;
V_6 -> V_10 -> V_15 = V_6 -> V_15 ;
return 0 ;
}
static void F_7 ( const struct V_22 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_8 ( V_6 -> V_10 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_23 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_23 ) ;
}
