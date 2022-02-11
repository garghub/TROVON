static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#ifdef F_2
F_3 ( V_5 L_1
L_2 ,
V_2 -> V_6 , V_4 -> V_7 , V_4 -> V_8 ) ;
#endif
#ifdef F_4
F_3 ( V_5 L_3
L_4 ,
V_2 -> V_6 , V_4 -> V_9 , V_4 -> V_10 ) ;
#endif
#ifdef F_5
F_3 ( V_5 L_5
L_6 ,
V_2 -> V_6 , V_4 -> V_11 , V_4 -> V_12 ) ;
#endif
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_8 )
{
#ifdef F_2
F_3 ( V_5 L_7 ,
V_2 -> V_6 , V_4 -> V_8 ) ;
#endif
#ifdef F_4
F_3 ( V_5 L_8 ,
V_2 -> V_6 , V_4 -> V_10 ) ;
#endif
#ifdef F_5
F_3 ( V_5 L_9 ,
V_2 -> V_6 , V_4 -> V_12 ) ;
#endif
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_13 )
{
F_3 ( V_5 L_10 ,
V_2 -> V_6 , V_13 ) ;
return 0 ;
}
static int T_1 F_8 ( void )
{
int V_14 ;
V_15 . V_16 = F_1 ;
V_15 . V_17 = F_6 ;
V_15 . V_18 = F_7 ;
V_14 = F_9 ( & V_15 ) ;
if ( V_14 < 0 ) {
F_3 ( V_5 L_11 , V_14 ) ;
return V_14 ;
}
F_3 ( V_5 L_12 , V_15 . V_6 ) ;
return 0 ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_15 ) ;
F_3 ( V_5 L_13 , V_15 . V_6 ) ;
}
