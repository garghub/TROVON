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
T_1 V_19 ;
if ( V_6 -> V_16 > V_20 )
return - V_21 ;
if ( V_6 -> V_13 & ~ V_13 ) {
F_7 ( L_1 , V_6 -> V_13 ) ;
return - V_22 ;
}
V_18 = F_8 ( V_4 -> V_23 ) ;
if ( V_18 < 0 ) {
F_9 ( L_2 ,
V_4 -> V_23 ) ;
return V_18 ;
}
V_4 -> V_24 -> V_11 . V_25 ++ ;
V_19 = F_10 ( V_6 -> V_16 + 1 ) ;
if ( V_19 > V_4 -> V_24 -> V_11 . V_26 )
V_4 -> V_24 -> V_11 . V_26 = V_19 ;
return V_18 ;
}
static void F_11 ( const struct V_27 * V_4 )
{
V_4 -> V_24 -> V_11 . V_25 -- ;
if ( V_4 -> V_24 -> V_11 . V_25 == 0 )
V_4 -> V_24 -> V_11 . V_26 = 0 ;
F_12 ( V_4 -> V_23 ) ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_28 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_28 ) ;
}
