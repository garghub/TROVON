static void F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 . V_8 . V_9 ;
struct V_10 * V_10 = & V_2 -> V_11 . V_12 ;
{
if ( V_10 -> V_13 ) {
V_10 -> V_14 = 0 ;
V_10 -> V_15 = 0 ;
V_10 -> V_13 = 0 ;
}
V_10 -> V_14 ++ ;
V_10 -> V_15 += V_6 -> V_16 . V_17 ;
V_10 -> V_18 = V_10 -> V_15 / V_10 -> V_14 ;
}
}
static void F_2 ( struct V_1 * V_2 , union V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_10 * V_10 ;
if ( V_4 == NULL || V_2 == NULL )
return;
V_6 = & V_4 -> V_7 . V_8 . V_9 ;
V_10 = & V_2 -> V_11 . V_19 ;
if ( V_10 -> V_13 ) {
V_10 -> V_14 = 0 ;
V_10 -> V_15 = 0 ;
V_10 -> V_13 = 0 ;
}
V_10 -> V_14 ++ ;
V_10 -> V_15 += V_6 -> V_16 . V_20 ;
V_10 -> V_18 = V_10 -> V_15 / V_10 -> V_14 ;
}
void F_3 ( struct V_1 * V_2 , void * V_4 )
{
union V_3 * V_21 = (union V_3 * ) V_4 ;
F_1 ( V_2 , V_21 ) ;
F_2 ( V_2 , V_21 ) ;
#ifdef F_4
F_5 ( V_2 , V_4 ) ;
#endif
}
