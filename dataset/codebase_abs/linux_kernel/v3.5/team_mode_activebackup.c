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
V_8 = F_2 ( V_1 ( V_2 ) -> V_8 ) ;
if ( F_4 ( ! V_8 ) )
goto V_11;
V_7 -> V_12 = V_8 -> V_12 ;
if ( F_5 ( V_7 ) )
return false ;
return true ;
V_11:
F_6 ( V_7 ) ;
return false ;
}
static void F_7 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
if ( V_1 ( V_2 ) -> V_8 == V_5 )
F_8 ( V_1 ( V_2 ) -> V_8 , NULL ) ;
}
static int F_9 ( struct V_2 * V_2 , struct V_13 * V_14 )
{
if ( V_1 ( V_2 ) -> V_8 )
V_14 -> V_15 . V_16 = V_1 ( V_2 ) -> V_8 -> V_12 -> V_17 ;
else
V_14 -> V_15 . V_16 = 0 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_2 , struct V_13 * V_14 )
{
struct V_4 * V_5 ;
F_11 (port, &team->port_list, list) {
if ( V_5 -> V_12 -> V_17 == V_14 -> V_15 . V_16 ) {
F_12 ( V_1 ( V_2 ) -> V_8 , V_5 ) ;
return 0 ;
}
}
return - V_18 ;
}
static int F_13 ( struct V_2 * V_2 )
{
return F_14 ( V_2 , V_19 , F_15 ( V_19 ) ) ;
}
static void F_16 ( struct V_2 * V_2 )
{
F_17 ( V_2 , V_19 , F_15 ( V_19 ) ) ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_20 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_20 ) ;
}
