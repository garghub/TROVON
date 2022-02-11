static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_8 ;
V_6 = F_2 ( V_4 ) ;
V_8 = V_2 -> type -> V_9 ( V_2 , V_4 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
F_3 ( V_4 , ( V_7 - V_2 -> V_10 . V_11 ) - V_4 -> V_12 ) ;
F_4 ( V_4 , - V_2 -> V_10 . V_11 ) ;
V_4 -> V_13 = V_4 -> V_14 + V_8 ;
F_5 ( V_4 , V_8 ) ;
memmove ( F_2 ( V_4 ) , V_6 , V_8 ) ;
V_2 -> V_15 = F_6 () ;
return 0 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_16 , V_17 ) ;
}
static void T_3 F_9 ( void )
{
int V_18 ;
V_18 = F_10 ( & V_16 , V_17 ) ;
F_11 ( V_18 ) ;
}
