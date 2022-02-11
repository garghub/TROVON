void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_5 . V_6 ;
V_4 -> V_7 = V_2 -> V_7 . V_6 ;
V_4 -> V_8 = V_2 -> V_8 . V_6 ;
V_4 -> V_9 = V_2 -> V_9 . V_6 ;
V_4 -> V_10 = V_2 -> V_10 . V_6 ;
V_4 -> V_11 = V_2 -> V_11 . V_6 ;
V_4 -> V_12 = V_2 -> V_12 . V_6 ;
V_4 -> V_13 = V_2 -> V_13 . V_6 ;
V_4 -> V_14 = V_2 -> V_14 . V_6 ;
V_4 -> V_15 = V_2 -> V_15 ;
}
int F_2 ( const struct V_16 * V_17 ,
struct V_3 * V_4 , unsigned int V_18 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_17 , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
