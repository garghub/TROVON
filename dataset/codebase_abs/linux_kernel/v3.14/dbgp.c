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
if ( F_5 ( V_5 ) ) {
const struct V_9 * V_10 = F_6 ( V_5 ) ;
V_8 . V_11 . V_12 . V_13 = F_7 ( V_10 -> V_14 ) ;
V_8 . V_11 . V_12 . V_14 = V_10 -> V_14 -> V_15 ;
V_8 . V_11 . V_12 . V_16 = V_10 -> V_16 ;
V_8 . V_14 = V_17 ;
} else
#endif
V_8 . V_14 = V_18 ;
return F_8 ( V_19 , & V_8 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_20 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_21 ) ;
}
