static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = V_6 -> V_7 * 4 ;
F_3 ( V_4 , - V_2 -> V_8 . V_9 ) ;
V_4 -> V_10 = V_4 -> V_11 +
F_4 ( struct V_5 , V_12 ) ;
V_4 -> V_13 = V_4 -> V_11 + V_7 ;
F_5 ( V_4 , V_7 ) ;
memmove ( F_6 ( V_4 ) , V_6 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_7 = V_4 -> V_14 - F_8 ( V_4 ) ;
if ( V_4 -> V_13 != V_4 -> V_11 ) {
memmove ( F_8 ( V_4 ) ,
F_6 ( V_4 ) , V_7 ) ;
V_4 -> V_11 = V_4 -> V_13 ;
}
F_2 ( V_4 ) -> V_15 = F_9 ( V_4 -> V_16 + V_7 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_17 , V_18 ) ;
}
static void T_2 F_13 ( void )
{
int V_19 ;
V_19 = F_14 ( & V_17 , V_18 ) ;
F_15 ( V_19 ) ;
}
