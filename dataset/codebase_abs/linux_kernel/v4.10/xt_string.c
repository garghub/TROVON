static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
bool V_8 ;
V_8 = V_6 -> V_9 . V_10 . V_11 & V_12 ;
return ( F_2 ( (struct V_1 * ) V_2 , V_6 -> V_13 ,
V_6 -> V_14 , V_6 -> V_15 )
!= V_16 ) ^ V_8 ;
}
static int F_3 ( const struct V_17 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_18 * V_19 ;
int V_11 = V_20 ;
if ( V_6 -> V_13 > V_6 -> V_14 )
return - V_21 ;
if ( V_6 -> V_22 [ V_23 - 1 ] != '\0' )
return - V_21 ;
if ( V_6 -> V_24 > V_25 )
return - V_21 ;
if ( V_6 -> V_9 . V_10 . V_11 &
~ ( V_26 | V_12 ) )
return - V_21 ;
if ( V_6 -> V_9 . V_10 . V_11 & V_26 )
V_11 |= V_27 ;
V_19 = F_4 ( V_6 -> V_22 , V_6 -> V_28 , V_6 -> V_24 ,
V_29 , V_11 ) ;
if ( F_5 ( V_19 ) )
return F_6 ( V_19 ) ;
V_6 -> V_15 = V_19 ;
return 0 ;
}
static void F_7 ( const struct V_30 * V_4 )
{
F_8 ( F_9 ( V_4 -> V_7 ) -> V_15 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_31 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_31 ) ;
}
