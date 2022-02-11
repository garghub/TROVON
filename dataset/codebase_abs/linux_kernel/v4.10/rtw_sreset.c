void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_6 ;
V_4 -> V_7 = V_8 ;
}
T_1 F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_6 ;
T_1 V_9 = V_8 ;
T_2 V_10 = 0 ;
V_10 = F_3 ( V_2 , V_11 ) ;
if ( V_10 == 0xeaeaeaea ) {
V_4 -> V_7 = V_12 ;
} else if ( V_10 != 0 ) {
F_4 ( L_1 , V_10 ) ;
V_4 -> V_7 = V_13 ;
}
if ( V_8 != V_4 -> V_7 ) {
F_4 ( L_2 , V_14 , V_4 -> V_7 ) ;
V_9 = V_4 -> V_7 & ( ~ ( V_15 | V_16 ) ) ;
}
F_4 ( L_3 , V_14 , V_9 ) ;
V_4 -> V_7 = V_8 ;
return V_9 ;
}
void F_5 ( struct V_1 * V_2 , T_2 V_9 )
{
V_2 -> V_5 -> V_6 . V_7 = V_9 ;
}
