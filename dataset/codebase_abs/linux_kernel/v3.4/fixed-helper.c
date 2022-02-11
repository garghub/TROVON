static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
F_3 ( V_4 ) ;
}
struct V_6 * F_4 ( int V_7 ,
struct V_8 * V_9 , int V_10 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_12 . V_13 = L_1 ;
V_4 -> V_12 . V_14 = 0 ;
V_4 -> V_12 . V_15 = - V_16 ;
V_4 -> V_12 . V_17 = 1 ;
V_4 -> V_12 . V_18 = & V_4 -> V_18 ;
V_4 -> V_18 . V_19 . V_20 = 1 ;
V_4 -> V_18 . V_21 = V_9 ;
V_4 -> V_18 . V_22 = V_10 ;
V_4 -> V_5 . V_23 = L_2 ;
V_4 -> V_5 . V_7 = V_7 ;
V_4 -> V_5 . V_2 . V_24 = & V_4 -> V_12 ;
V_4 -> V_5 . V_2 . V_25 = F_1 ;
F_6 ( & V_4 -> V_5 ) ;
return & V_4 -> V_5 ;
}
