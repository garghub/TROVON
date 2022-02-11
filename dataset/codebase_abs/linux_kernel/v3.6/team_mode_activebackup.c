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
if ( V_1 ( V_2 ) -> V_8 == V_5 )
F_9 ( V_1 ( V_2 ) -> V_8 , NULL ) ;
}
static int F_10 ( struct V_2 * V_2 , struct V_12 * V_13 )
{
struct V_4 * V_8 ;
V_8 = F_11 ( V_1 ( V_2 ) -> V_8 ,
F_12 ( & V_2 -> V_14 ) ) ;
if ( V_8 )
V_13 -> V_15 . V_16 = V_8 -> V_17 -> V_18 ;
else
V_13 -> V_15 . V_16 = 0 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 , struct V_12 * V_13 )
{
struct V_4 * V_5 ;
F_14 (port, &team->port_list, list) {
if ( V_5 -> V_17 -> V_18 == V_13 -> V_15 . V_16 ) {
F_15 ( V_1 ( V_2 ) -> V_8 , V_5 ) ;
return 0 ;
}
}
return - V_19 ;
}
static int F_16 ( struct V_2 * V_2 )
{
return F_17 ( V_2 , V_20 , F_18 ( V_20 ) ) ;
}
static void F_19 ( struct V_2 * V_2 )
{
F_20 ( V_2 , V_20 , F_18 ( V_20 ) ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_21 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_21 ) ;
}
