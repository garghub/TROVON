static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 ) ;
if ( ! ( V_2 & F_3 ( V_3 ) ) )
return;
V_2 &= ~ F_4 ( V_4 + V_5 - 1 ,
V_4 ) ;
V_2 |= 17 << V_4 ;
V_2 &= ~ F_3 ( V_3 ) ;
F_5 ( V_2 , V_1 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
void T_1 * V_1 ;
T_2 V_2 ;
V_9 = F_7 ( V_7 , V_10 , 0 ) ;
V_1 = F_8 ( & V_7 -> V_11 , V_9 ) ;
if ( F_9 ( V_1 ) )
return F_10 ( V_1 ) ;
V_2 = F_2 ( V_1 + V_12 ) ;
V_2 &= ( F_3 ( 16 ) & F_3 ( 18 ) ) ;
F_5 ( V_2 , V_1 + V_12 ) ;
F_1 ( V_1 + V_13 ) ;
F_1 ( V_1 + V_14 ) ;
return F_11 ( V_7 -> V_11 . V_15 , V_1 , & V_16 ) ;
}
