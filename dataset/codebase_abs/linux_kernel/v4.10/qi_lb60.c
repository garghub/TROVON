static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
int V_9 = ! F_3 ( V_5 ) ;
F_4 ( V_6 -> V_10 , V_9 ) ;
F_4 ( V_6 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_6 * V_6 ;
struct V_14 * V_8 = & V_15 ;
V_6 = F_6 ( & V_13 -> V_16 , sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_10 = F_7 ( & V_13 -> V_16 , L_1 , V_19 ) ;
if ( F_8 ( V_6 -> V_10 ) )
return F_9 ( V_6 -> V_10 ) ;
V_6 -> V_11 = F_7 ( & V_13 -> V_16 , L_2 , V_19 ) ;
if ( F_8 ( V_6 -> V_11 ) )
return F_9 ( V_6 -> V_11 ) ;
V_8 -> V_16 = & V_13 -> V_16 ;
F_10 ( V_8 , V_6 ) ;
return F_11 ( & V_13 -> V_16 , V_8 ) ;
}
