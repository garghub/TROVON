static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
F_3 ( V_4 -> V_6 . V_7 ) ;
F_3 ( V_4 ) ;
}
struct V_8 * F_4 ( int V_9 , const char * V_10 ,
struct V_11 * V_12 , int V_13 , int V_14 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 . V_7 = F_6 ( V_10 , V_15 ) ;
if ( ! V_4 -> V_6 . V_7 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_4 -> V_6 . V_16 = V_14 ;
V_4 -> V_6 . V_17 = - V_18 ;
V_4 -> V_6 . V_19 = 1 ;
V_4 -> V_6 . V_20 = & V_4 -> V_20 ;
V_4 -> V_20 . V_21 . V_22 = 1 ;
V_4 -> V_20 . V_23 = V_12 ;
V_4 -> V_20 . V_24 = V_13 ;
V_4 -> V_5 . V_10 = L_1 ;
V_4 -> V_5 . V_9 = V_9 ;
V_4 -> V_5 . V_2 . V_25 = & V_4 -> V_6 ;
V_4 -> V_5 . V_2 . V_26 = F_1 ;
F_7 ( & V_4 -> V_5 ) ;
return & V_4 -> V_5 ;
}
