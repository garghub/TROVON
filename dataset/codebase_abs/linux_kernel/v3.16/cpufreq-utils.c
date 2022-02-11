void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
V_5 = ( V_2 -> V_7 . V_8 / 100 ) * ( V_4 -> V_5 / 10 ) ;
V_5 = F_2 ( V_5 , ( 1000 * 1000 ) ) ;
V_5 = ( 1 << 11 ) + 1 - V_5 ;
F_3 ( L_1 , V_9 , V_5 ) ;
V_6 = F_4 ( V_10 ) ;
V_6 &= ~ ( ( 1 << 12 ) - 1 ) ;
V_6 |= V_5 ;
F_5 ( V_6 , V_10 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( ! F_7 ( V_2 -> V_11 ) )
F_8 ( V_2 -> V_11 , V_2 -> V_12 . V_13 ) ;
}
