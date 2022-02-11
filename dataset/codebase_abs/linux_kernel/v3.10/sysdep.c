static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
if ( V_2 & V_5 )
return - V_6 ;
V_3 = V_1 -> V_7 ;
if( ! V_3 )
return 1 ;
V_4 = V_8 . V_9 * 60 - F_2 ( V_3 ) -> V_10 ;
if ( V_4 ) {
V_3 -> V_11 . V_12 += V_4 ;
V_3 -> V_13 . V_12 += V_4 ;
V_3 -> V_14 . V_12 += V_4 ;
F_2 ( V_3 ) -> V_10 += V_4 ;
}
return 1 ;
}
