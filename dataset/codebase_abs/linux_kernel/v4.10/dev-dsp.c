int T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_1 * V_3 ;
T_2 V_4 ;
V_4 = F_2 ( F_3 ( V_2 -> V_5 - 1 ) ) ;
V_4 &= V_6 ;
V_7 [ 0 ] . V_8 = V_4 ;
V_7 [ 0 ] . V_9 = V_4 + 0xFFFFFFF ;
V_7 [ 1 ] . V_8 = V_2 -> V_10 ;
V_3 = V_11 . V_12 . V_13 ;
memcpy ( V_3 , V_2 , sizeof ( * V_2 ) ) ;
return F_4 ( & V_11 ) ;
}
