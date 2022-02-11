static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static struct V_4 * F_1 ( struct V_2 * V_2 ,
struct V_4 * V_5 )
{
struct V_4 * V_6 ;
if ( F_2 ( V_5 ) )
return V_5 ;
V_6 = V_5 ;
F_3 (cur, &team->port_list, list)
if ( F_2 ( V_5 ) )
return V_6 ;
F_4 (cur, &team->port_list, list) {
if ( V_6 == V_5 )
break;
if ( F_2 ( V_5 ) )
return V_6 ;
}
return NULL ;
}
static bool F_5 ( struct V_2 * V_2 , struct V_7 * V_8 )
{
struct V_4 * V_5 ;
int V_9 ;
V_9 = V_1 ( V_2 ) -> V_10 ++ % V_2 -> V_11 ;
V_5 = F_6 ( V_2 , V_9 ) ;
V_5 = F_1 ( V_2 , V_5 ) ;
if ( F_7 ( ! V_5 ) )
goto V_12;
if ( F_8 ( V_2 , V_5 , V_8 ) )
return false ;
return true ;
V_12:
F_9 ( V_8 ) ;
return false ;
}
static int F_10 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
return F_11 ( V_5 ) ;
}
static void F_12 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
F_11 ( V_5 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_13 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_13 ) ;
}
