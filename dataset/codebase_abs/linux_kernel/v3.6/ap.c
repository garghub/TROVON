static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
F_2 ( V_6 ) ;
if ( ! V_2 -> V_9 -> V_10 )
return - V_11 ;
if ( V_4 -> V_7 -> V_12 != V_13 &&
V_4 -> V_7 -> V_12 != V_14 )
return - V_11 ;
if ( ! V_6 -> V_15 )
return - V_16 ;
V_8 = V_2 -> V_9 -> V_10 ( & V_2 -> V_17 , V_4 ) ;
if ( ! V_8 ) {
V_6 -> V_15 = 0 ;
V_6 -> V_18 = NULL ;
}
return V_8 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
F_4 ( V_6 ) ;
V_8 = F_1 ( V_2 , V_4 ) ;
F_5 ( V_6 ) ;
return V_8 ;
}
