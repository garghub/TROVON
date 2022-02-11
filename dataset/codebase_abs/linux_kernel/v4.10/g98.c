static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_1 V_10 = F_2 ( V_9 , 0x087040 ) & 0x0000ffff ;
T_1 V_11 = F_2 ( V_9 , 0x087040 ) >> 16 ;
T_1 V_12 = ( V_11 & 0x07ff ) << 2 ;
T_1 V_13 = ( V_11 & 0x3800 ) >> 11 ;
T_1 V_14 = F_2 ( V_9 , 0x087044 ) ;
const struct V_15 * V_16 =
F_3 ( V_17 , V_10 ) ;
F_4 ( V_6 , L_1
L_2 , V_10 ,
V_16 ? V_16 -> V_18 : L_3 , V_4 ? V_4 -> V_19 : - 1 ,
V_4 ? V_4 -> V_20 -> V_11 : 0 ,
V_4 ? V_4 -> V_21 . V_22 -> V_18 : L_4 ,
V_13 , V_12 , V_14 ) ;
}
int
F_5 ( struct V_8 * V_9 , int V_23 ,
struct V_24 * * V_25 )
{
return F_6 ( & V_26 , V_9 , V_23 ,
true , 0x087000 , V_25 ) ;
}
