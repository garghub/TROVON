static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_8 = 0 ;
unsigned long V_9 , V_10 , V_11 ;
V_7 = & V_5 -> V_10 ;
V_9 = F_3 ( V_5 -> V_12 + V_7 -> V_13 ) ;
V_10 = F_4 ( V_7 -> V_14 , V_7 -> V_15 , V_9 ) ;
V_7 = & V_5 -> V_11 ;
V_9 = F_3 ( V_5 -> V_12 + V_7 -> V_13 ) ;
V_11 = F_4 ( V_7 -> V_14 , V_7 -> V_15 , V_9 ) ;
V_8 = ( V_3 * V_16 ) / ( ( V_16 * V_11 ) + V_10 ) ;
return V_8 ;
}
