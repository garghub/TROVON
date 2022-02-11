static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 ,
V_4 ) ;
return V_3 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 ,
V_4 ) ;
int V_6 ;
V_6 = F_4 ( V_3 -> V_7 , 1 ) ;
if ( ! V_6 )
V_3 -> V_5 = 1 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 ,
V_4 ) ;
int V_6 ;
V_6 = F_4 ( V_3 -> V_7 , 0 ) ;
if ( ! V_6 )
V_3 -> V_5 = 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_7 ( V_9 -> V_10 . V_11 ) ;
struct V_3 * V_12 ;
V_12 = F_8 ( & V_9 -> V_10 , sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_12 -> V_10 = & V_9 -> V_10 ;
V_12 -> V_7 = V_7 ;
V_12 -> V_4 . V_15 = & V_16 ;
V_12 -> V_17 = F_9 ( & V_9 -> V_10 , & V_12 -> V_4 ) ;
if ( F_10 ( V_12 -> V_17 ) )
return F_11 ( V_12 -> V_17 ) ;
F_12 ( V_9 , V_12 ) ;
return 0 ;
}
