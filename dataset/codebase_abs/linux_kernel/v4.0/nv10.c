void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , struct V_8 * V_9 )
{
V_9 -> V_4 = 0x80000000 | V_4 ;
V_9 -> V_10 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_9 -> V_6 = V_6 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 , struct V_8 * V_9 )
{
V_9 -> V_4 = 0 ;
V_9 -> V_10 = 0 ;
V_9 -> V_6 = 0 ;
V_9 -> V_11 = 0 ;
}
void
F_4 ( struct V_1 * V_2 , int V_3 , struct V_8 * V_9 )
{
F_5 ( V_2 , 0x100244 + ( V_3 * 0x10 ) , V_9 -> V_10 ) ;
F_5 ( V_2 , 0x100248 + ( V_3 * 0x10 ) , V_9 -> V_6 ) ;
F_5 ( V_2 , 0x100240 + ( V_3 * 0x10 ) , V_9 -> V_4 ) ;
F_6 ( V_2 , 0x100240 + ( V_3 * 0x10 ) ) ;
}
