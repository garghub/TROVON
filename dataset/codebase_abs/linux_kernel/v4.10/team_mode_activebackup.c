static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static T_1 F_1 ( struct V_2 * V_2 , struct V_4 * V_5 ,
struct V_6 * V_7 ) {
struct V_4 * V_8 ;
V_8 = F_2 ( V_1 ( V_2 ) -> V_8 ) ;
if ( V_8 != V_5 )
return V_9 ;
return V_10 ;
}
static bool F_3 ( struct V_2 * V_2 , struct V_6 * V_7 )
{
struct V_4 * V_8 ;
V_8 = F_4 ( V_1 ( V_2 ) -> V_8 ) ;
if ( F_5 ( ! V_8 ) )
goto V_11;
if ( F_6 ( V_2 , V_8 , V_7 ) )
return false ;
return true ;
V_11:
F_7 ( V_7 ) ;
return false ;
}
static void F_8 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_1 ( V_2 ) -> V_8 == V_5 ) {
F_9 ( V_1 ( V_2 ) -> V_8 , NULL ) ;
F_10 ( V_1 ( V_2 ) -> V_12 ) ;
}
}
static int F_11 ( struct V_2 * V_2 ,
struct V_13 * V_14 )
{
V_1 ( V_2 ) -> V_12 = V_14 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_8 ;
V_8 = F_13 ( V_1 ( V_2 ) -> V_8 ,
F_14 ( & V_2 -> V_17 ) ) ;
if ( V_8 )
V_16 -> V_18 . V_19 = V_8 -> V_20 -> V_21 ;
else
V_16 -> V_18 . V_19 = 0 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 ;
F_16 (port, &team->port_list, list) {
if ( V_5 -> V_20 -> V_21 == V_16 -> V_18 . V_19 ) {
F_17 ( V_1 ( V_2 ) -> V_8 , V_5 ) ;
return 0 ;
}
}
return - V_22 ;
}
static int F_18 ( struct V_2 * V_2 )
{
return F_19 ( V_2 , V_23 , F_20 ( V_23 ) ) ;
}
static void F_21 ( struct V_2 * V_2 )
{
F_22 ( V_2 , V_23 , F_20 ( V_23 ) ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_24 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_24 ) ;
}
