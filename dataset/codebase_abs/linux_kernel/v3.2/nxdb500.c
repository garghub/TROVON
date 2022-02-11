static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 . V_6 = 5 ;
V_4 -> V_5 . V_7 = 0 ;
return F_2 ( V_2 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
V_2 -> V_2 . V_4 . V_5 . V_6 = 5 ;
V_2 -> V_2 . V_4 . V_5 . V_7 = 0 ;
V_8 = F_4 ( V_9 ) ;
F_5 ( V_8 , V_9 ) ;
F_5 ( 3 , V_10 ) ;
V_8 = F_4 ( V_11 ) ;
F_5 ( V_8 | 1 , V_11 ) ;
V_8 = F_4 ( V_12 ) ;
F_5 ( V_8 | 1 , V_12 ) ;
return F_6 ( V_2 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( & V_13 , & V_14 ) ;
F_9 ( V_15 , F_10 ( V_15 ) ) ;
}
