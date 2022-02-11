static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = & V_5 -> V_8 [ V_3 ] ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + V_7 -> V_10 ) ;
F_5 ( V_10 & ~ V_7 -> V_13 , V_5 -> V_12 + V_7 -> V_10 ) ;
F_6 ( V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = & V_5 -> V_8 [ V_3 ] ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + V_7 -> V_10 ) ;
F_5 ( V_10 | V_7 -> V_13 , V_5 -> V_12 + V_7 -> V_10 ) ;
F_6 ( V_5 -> V_11 , V_9 ) ;
return 0 ;
}
