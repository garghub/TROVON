int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 -> V_8 . V_9 . V_5 ;
const T_1 V_10 = V_2 -> V_6 . V_11 * 0x800 ;
const T_1 V_12 = 0x01010101 * V_3 ;
if ( V_2 -> V_6 . V_13 . V_14 . V_15 & 1 )
F_2 ( V_5 , 0x61c110 + V_10 , 0x0f0f0f0f , V_12 ) ;
else
F_2 ( V_5 , 0x61c12c + V_10 , 0x0f0f0f0f , V_12 ) ;
return 0 ;
}
int
F_3 ( struct V_16 * V_7 , int V_17 ,
struct V_18 * V_19 , struct V_20 * * V_21 )
{
return F_4 ( & V_22 , V_7 , V_17 , V_19 , V_21 ) ;
}
