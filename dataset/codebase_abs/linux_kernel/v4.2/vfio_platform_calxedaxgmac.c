static inline void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 &= ~ ( V_4 | V_5 ) ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_6 ) ;
V_2 &= ~ ( V_7 | V_8 ) ;
F_3 ( V_2 , V_1 + V_6 ) ;
}
int F_4 ( struct V_9 * V_10 )
{
struct V_11 V_12 = V_10 -> V_13 [ 0 ] ;
if ( ! V_12 . V_1 ) {
V_12 . V_1 =
F_5 ( V_12 . V_14 , V_12 . V_15 ) ;
if ( ! V_12 . V_1 )
return - V_16 ;
}
F_3 ( 0 , V_12 . V_1 + V_17 ) ;
F_1 ( V_12 . V_1 ) ;
return 0 ;
}
