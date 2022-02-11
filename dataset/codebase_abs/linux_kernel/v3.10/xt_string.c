static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
bool V_10 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_10 = V_6 -> V_11 . V_12 . V_13 & V_14 ;
return ( F_2 ( (struct V_1 * ) V_2 , V_6 -> V_15 ,
V_6 -> V_16 , V_6 -> V_17 , & V_9 )
!= V_18 ) ^ V_10 ;
}
static int F_3 ( const struct V_19 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_20 * V_21 ;
int V_13 = V_22 ;
if ( V_6 -> V_15 > V_6 -> V_16 )
return - V_23 ;
if ( V_6 -> V_24 [ V_25 - 1 ] != '\0' )
return - V_23 ;
if ( V_6 -> V_26 > V_27 )
return - V_23 ;
if ( V_6 -> V_11 . V_12 . V_13 &
~ ( V_28 | V_14 ) )
return - V_23 ;
if ( V_6 -> V_11 . V_12 . V_13 & V_28 )
V_13 |= V_29 ;
V_21 = F_4 ( V_6 -> V_24 , V_6 -> V_30 , V_6 -> V_26 ,
V_31 , V_13 ) ;
if ( F_5 ( V_21 ) )
return F_6 ( V_21 ) ;
V_6 -> V_17 = V_21 ;
return 0 ;
}
static void F_7 ( const struct V_32 * V_4 )
{
F_8 ( F_9 ( V_4 -> V_7 ) -> V_17 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_33 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_33 ) ;
}
