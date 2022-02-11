static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static struct V_4 * F_1 ( struct V_2 * V_2 ,
struct V_4 * V_5 )
{
struct V_4 * V_6 ;
if ( V_5 -> V_7 )
return V_5 ;
V_6 = V_5 ;
F_2 (cur, &team->port_list, list)
if ( V_6 -> V_7 )
return V_6 ;
F_3 (cur, &team->port_list, list) {
if ( V_6 == V_5 )
break;
if ( V_6 -> V_7 )
return V_6 ;
}
return NULL ;
}
static bool F_4 ( struct V_2 * V_2 , struct V_8 * V_9 )
{
struct V_4 * V_5 ;
int V_10 ;
V_10 = V_1 ( V_2 ) -> V_11 ++ % V_2 -> V_12 ;
V_5 = F_5 ( V_2 , V_10 ) ;
V_5 = F_1 ( V_2 , V_5 ) ;
if ( F_6 ( ! V_5 ) )
goto V_13;
V_9 -> V_14 = V_5 -> V_14 ;
if ( F_7 ( V_9 ) )
return false ;
return true ;
V_13:
F_8 ( V_9 ) ;
return false ;
}
static int F_9 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
return F_10 ( V_5 ) ;
}
static void F_11 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_10 ( V_5 ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_15 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_15 ) ;
}
