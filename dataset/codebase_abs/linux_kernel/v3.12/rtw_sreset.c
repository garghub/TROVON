void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 = false ;
V_6 -> V_10 = V_11 ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
V_6 -> V_9 = false ;
V_6 -> V_10 = V_11 ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = 0 ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
T_1 V_14 = V_11 ;
T_2 V_15 = 0 ;
if ( V_6 -> V_9 )
return V_14 ;
V_15 = F_6 ( V_2 , V_16 ) ;
if ( V_15 == 0xeaeaeaea ) {
V_6 -> V_10 = V_17 ;
} else if ( V_15 != 0 ) {
F_7 ( L_1 , V_15 ) ;
V_6 -> V_10 = V_18 ;
}
if ( V_11 != V_6 -> V_10 ) {
F_7 ( L_2 , V_19 , V_6 -> V_10 ) ;
V_14 = ( V_6 -> V_10 & ( ~ ( V_20 | V_21 ) ) ) ;
}
F_7 ( L_3 , V_19 , V_14 ) ;
V_6 -> V_10 = V_11 ;
return V_14 ;
}
void F_8 ( struct V_1 * V_2 , T_2 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_7 . V_10 = V_14 ;
}
