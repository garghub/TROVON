struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_3 , V_4 ) ;
if ( F_3 ( V_6 ) )
return NULL ;
else
return F_4 ( & V_6 -> V_7 ) ;
}
int F_5 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_10 * args )
{
int V_11 = F_6 ( args -> V_12 * args -> V_13 , 8 ) ;
struct V_1 * V_14 = NULL ;
int V_15 ;
if ( args -> V_16 < V_11 )
args -> V_16 = V_11 ;
if ( args -> V_4 < args -> V_16 * args -> V_17 )
args -> V_4 = args -> V_16 * args -> V_17 ;
V_14 = F_1 ( V_3 , F_7 ( args -> V_4 , V_18 ) ) ;
if ( ! V_14 )
return - V_19 ;
V_15 = F_8 ( V_9 , & V_14 -> V_7 . V_7 , & args -> V_20 ) ;
F_9 ( & V_14 -> V_7 . V_7 ) ;
return V_15 ;
}
