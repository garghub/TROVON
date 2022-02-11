static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_3 ) ;
}
static int F_6 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! F_7 ( V_6 -> V_11 ,
V_12 ) )
return - V_13 ;
V_10 = F_8 ( & V_6 -> V_2 , sizeof( struct V_9 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
V_10 -> V_16 = F_4 ;
V_10 -> V_17 = F_1 ;
V_10 -> V_2 = & V_6 -> V_2 ;
return F_9 ( V_10 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
return F_11 ( & V_6 -> V_2 ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_18 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_18 ) ;
}
