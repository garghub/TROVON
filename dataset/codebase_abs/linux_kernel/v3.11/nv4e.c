static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , & V_12 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_13 . V_14 = V_15 ;
V_10 -> V_13 . V_16 . V_17 = 12 ;
V_10 -> V_13 . V_16 . V_18 = V_19 ;
V_10 -> V_13 . V_16 . V_20 = V_21 ;
V_10 -> V_13 . V_16 . V_22 = V_23 ;
return 0 ;
}
