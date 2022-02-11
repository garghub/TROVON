void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 . V_5 ;
const T_1 V_9 = F_2 ( V_2 ) ;
const T_1 V_10 = 0x01010101 * V_3 ;
if ( V_2 -> V_11 . V_12 & 1 )
F_3 ( V_5 , 0x61c110 + V_9 , 0x0f0f0f0f , V_10 ) ;
else
F_3 ( V_5 , 0x61c12c + V_9 , 0x0f0f0f0f , V_10 ) ;
}
int
F_4 ( struct V_13 * V_6 , int V_14 )
{
return F_5 ( & V_15 , V_6 , V_14 ) ;
}
