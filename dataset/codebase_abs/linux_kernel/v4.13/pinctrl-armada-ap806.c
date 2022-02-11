static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
const struct V_6 * V_7 =
F_2 ( V_8 , & V_2 -> V_9 ) ;
if ( ! V_7 || ! V_2 -> V_9 . V_10 )
return - V_11 ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = F_3 ( V_14 ) ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = F_3 ( V_17 ) ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_14 [ 0 ] . V_22 ;
V_2 -> V_9 . V_23 = V_4 ;
return F_4 ( V_2 , V_2 -> V_9 . V_10 , 0 ) ;
}
