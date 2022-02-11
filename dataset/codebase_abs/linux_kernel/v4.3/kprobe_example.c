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
#ifdef F_6
F_3 ( V_5 L_7
L_8 ,
V_2 -> V_6 , V_4 -> V_13 , V_4 -> V_14 ) ;
#endif
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_8 )
{
#ifdef F_2
F_3 ( V_5 L_9 ,
V_2 -> V_6 , V_4 -> V_8 ) ;
#endif
#ifdef F_4
F_3 ( V_5 L_10 ,
V_2 -> V_6 , V_4 -> V_10 ) ;
#endif
#ifdef F_5
F_3 ( V_5 L_11 ,
V_2 -> V_6 , V_4 -> V_12 ) ;
#endif
#ifdef F_6
F_3 ( V_5 L_12 ,
V_2 -> V_6 , V_4 -> V_14 ) ;
#endif
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_15 )
{
F_3 ( V_5 L_13 ,
V_2 -> V_6 , V_15 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_16 ;
V_17 . V_18 = F_1 ;
V_17 . V_19 = F_7 ;
V_17 . V_20 = F_8 ;
V_16 = F_10 ( & V_17 ) ;
if ( V_16 < 0 ) {
F_3 ( V_5 L_14 , V_16 ) ;
return V_16 ;
}
F_3 ( V_5 L_15 , V_17 . V_6 ) ;
return 0 ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_17 ) ;
F_3 ( V_5 L_16 , V_17 . V_6 ) ;
}
