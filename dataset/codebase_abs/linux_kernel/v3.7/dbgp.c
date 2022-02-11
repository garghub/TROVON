static int F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
const struct V_4 * V_5 = F_3 ( V_2 ) -> V_6 ;
#endif
struct V_7 V_8 ;
if ( ! F_4 () )
return 0 ;
V_8 . V_3 = V_3 ;
#ifdef F_2
if ( V_5 -> V_9 == & V_10 ) {
const struct V_11 * V_12 = F_5 ( V_5 ) ;
V_8 . V_13 . V_14 . V_15 = F_6 ( V_12 -> V_9 ) ;
V_8 . V_13 . V_14 . V_9 = V_12 -> V_9 -> V_16 ;
V_8 . V_13 . V_14 . V_17 = V_12 -> V_17 ;
V_8 . V_9 = V_18 ;
} else
#endif
V_8 . V_9 = V_19 ;
return F_7 ( V_20 , & V_8 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_21 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_22 ) ;
}
