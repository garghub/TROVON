static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_4 ) ;
F_3 ( V_4 -> V_5 , 1 ) ;
F_4 ( 300 ) ;
F_3 ( V_4 -> V_6 , 1 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_4 ) ;
F_3 ( V_4 -> V_6 , 0 ) ;
F_3 ( V_4 -> V_5 , 0 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
V_4 = F_7 ( V_10 , sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_4 -> V_6 = F_8 ( V_10 , L_1 , V_13 ) ;
if ( F_9 ( V_4 -> V_6 ) )
return F_10 ( V_4 -> V_6 ) ;
V_4 -> V_5 = F_8 ( V_10 , L_2 , V_13 ) ;
if ( F_9 ( V_4 -> V_5 ) )
return F_10 ( V_4 -> V_5 ) ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . V_14 = & V_15 ;
V_4 -> V_4 . V_16 = V_17 ;
F_11 ( V_8 , V_4 ) ;
return F_12 ( & V_4 -> V_4 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_14 ( V_8 ) ;
F_15 ( & V_4 -> V_4 ) ;
return 0 ;
}
