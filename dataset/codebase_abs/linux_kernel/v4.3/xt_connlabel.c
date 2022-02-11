static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
struct V_10 * V_11 ;
bool V_12 = V_6 -> V_13 & V_14 ;
V_11 = F_2 ( V_2 , & V_9 ) ;
if ( V_11 == NULL || F_3 ( V_11 ) )
return V_12 ;
if ( V_6 -> V_13 & V_15 )
return ( F_4 ( V_11 , V_6 -> V_16 ) == 0 ) ^ V_12 ;
return F_5 ( V_11 , V_6 -> V_16 ) ^ V_12 ;
}
static int F_6 ( const struct V_17 * V_4 )
{
const int V_13 = V_14 |
V_15 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_18 ;
if ( V_6 -> V_13 & ~ V_13 ) {
F_7 ( L_1 , V_6 -> V_13 ) ;
return - V_19 ;
}
V_18 = F_8 ( V_4 -> V_20 ) ;
if ( V_18 < 0 ) {
F_9 ( L_2 ,
V_4 -> V_20 ) ;
return V_18 ;
}
V_18 = F_10 ( V_4 -> V_21 , V_6 -> V_16 + 1 ) ;
if ( V_18 < 0 )
F_11 ( V_4 -> V_20 ) ;
return V_18 ;
}
static void F_12 ( const struct V_22 * V_4 )
{
F_13 ( V_4 -> V_21 ) ;
F_11 ( V_4 -> V_20 ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_23 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_23 ) ;
}
