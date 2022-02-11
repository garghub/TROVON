static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_9 . V_10 ;
if ( V_8 -> V_11 ) {
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_11 = 0 ;
}
V_8 -> V_12 ++ ;
V_8 -> V_13 += V_6 -> V_14 . V_15 ;
V_8 -> V_16 = V_8 -> V_13 / V_8 -> V_12 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_8 * V_8 ;
if ( V_4 == NULL || V_2 == NULL )
return;
V_6 = & V_4 -> V_7 ;
V_8 = & V_2 -> V_9 . V_17 ;
if ( V_8 -> V_11 ) {
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_11 = 0 ;
}
V_8 -> V_12 ++ ;
V_8 -> V_13 += V_6 -> V_14 . V_18 ;
V_8 -> V_16 = V_8 -> V_13 / V_8 -> V_12 ;
}
void F_3 ( struct V_1 * V_2 , void * V_4 )
{
struct V_3 * V_19 = V_4 ;
F_1 ( V_2 , V_19 ) ;
F_2 ( V_2 , V_19 ) ;
}
