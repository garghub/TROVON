static bool F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return false ;
return F_3 ( V_3 ) < V_5 -> V_6 && F_4 ( V_3 , V_5 -> V_7 ) ;
}
static bool
F_5 ( const struct V_8 * V_9 , struct V_10 * V_11 )
{
const struct V_12 * V_13 = V_11 -> V_14 ;
enum V_15 V_16 ;
struct V_1 * V_2 ;
bool V_17 = V_13 -> V_18 & V_19 ;
V_2 = F_6 ( V_9 , & V_16 ) ;
if ( V_2 == NULL || F_7 ( V_2 ) )
return V_17 ;
if ( V_13 -> V_18 & V_20 )
return ( F_8 ( V_2 , V_13 -> V_3 ) == 0 ) ^ V_17 ;
return F_1 ( V_2 , V_13 -> V_3 ) ^ V_17 ;
}
static int F_9 ( const struct V_21 * V_11 )
{
const int V_18 = V_19 |
V_20 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_22 ;
if ( V_13 -> V_18 & ~ V_18 ) {
F_10 ( L_1 , V_13 -> V_18 ) ;
return - V_23 ;
}
V_22 = F_11 ( V_11 -> V_24 ) ;
if ( V_22 < 0 ) {
F_12 ( L_2 ,
V_11 -> V_24 ) ;
return V_22 ;
}
V_22 = F_13 ( V_11 -> V_25 , V_13 -> V_3 ) ;
if ( V_22 < 0 )
F_14 ( V_11 -> V_24 ) ;
return V_22 ;
}
static void F_15 ( const struct V_26 * V_11 )
{
F_16 ( V_11 -> V_25 ) ;
F_14 ( V_11 -> V_24 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_27 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_27 ) ;
}
