static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 ;
int V_5 ;
if ( V_3 -> V_6 & V_7 )
return - V_8 ;
V_4 = V_1 -> V_9 ;
if( ! V_4 )
return 1 ;
V_5 = V_10 . V_11 * 60 - F_2 ( V_4 ) -> V_12 ;
if ( V_5 ) {
V_4 -> V_13 . V_14 += V_5 ;
V_4 -> V_15 . V_14 += V_5 ;
V_4 -> V_16 . V_14 += V_5 ;
F_2 ( V_4 ) -> V_12 += V_5 ;
}
return 1 ;
}
