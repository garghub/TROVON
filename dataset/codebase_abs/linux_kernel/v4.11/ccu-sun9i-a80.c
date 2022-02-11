static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
void T_1 * V_5 ;
T_2 V_6 ;
V_4 = F_2 ( V_2 , V_7 , 0 ) ;
V_5 = F_3 ( & V_2 -> V_8 , V_4 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
V_6 = F_6 ( V_5 + V_9 ) ;
V_6 &= ( F_7 ( 16 ) & F_7 ( 18 ) ) ;
F_8 ( V_6 , V_5 + V_9 ) ;
return F_9 ( V_2 -> V_8 . V_10 , V_5 , & V_11 ) ;
}
