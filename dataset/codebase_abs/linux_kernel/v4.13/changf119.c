static void
F_1 ( struct V_1 * V_2 , int type , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , F_3 ( * V_5 ) , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 . V_11 . V_8 ;
F_4 ( V_8 , 0x610090 , 0x00000001 << V_3 , 0x00000000 << V_3 ) ;
F_5 ( V_8 , 0x61008c , 0x00000001 << V_3 ) ;
}
static void
F_6 ( struct V_1 * V_2 , int V_12 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , F_3 ( * V_5 ) , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 . V_11 . V_8 ;
F_5 ( V_8 , 0x61008c , 0x00000001 << V_3 ) ;
F_4 ( V_8 , 0x610090 , 0x00000001 << V_3 , 0x00000001 << V_3 ) ;
}
