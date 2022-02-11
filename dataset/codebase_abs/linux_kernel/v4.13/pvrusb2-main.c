static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
#ifdef F_3
F_4 ( V_2 ) ;
#endif
#ifdef F_5
F_6 ( V_2 , V_3 ) ;
#endif
}
static int F_7 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_5 , V_7 , F_1 ) ;
if ( ! V_2 ) {
F_9 ( V_8 ,
L_1 ) ;
return - V_9 ;
}
F_9 ( V_10 , L_2 , V_2 ) ;
F_10 ( V_5 , V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_12 ( V_5 ) ;
F_9 ( V_10 , L_3 , V_2 ) ;
F_10 ( V_5 , NULL ) ;
F_13 ( V_2 ) ;
F_9 ( V_10 , L_4 , V_2 ) ;
}
static int T_1 F_14 ( void )
{
int V_11 ;
F_9 ( V_10 , L_5 ) ;
V_11 = F_15 () ;
if ( V_11 != 0 ) {
F_9 ( V_10 , L_6 , V_11 ) ;
return V_11 ;
}
#ifdef F_5
V_3 = F_16 () ;
#endif
V_11 = F_17 ( & V_12 ) ;
if ( V_11 == 0 )
F_18 ( V_13 L_7 V_14 L_8
V_15 L_9 ) ;
if ( V_16 )
F_18 ( V_13 L_10 ,
V_16 , V_16 ) ;
F_9 ( V_10 , L_11 ) ;
return V_11 ;
}
static void T_2 F_19 ( void )
{
F_9 ( V_10 , L_12 ) ;
F_20 ( & V_12 ) ;
F_21 () ;
#ifdef F_5
F_22 ( V_3 ) ;
#endif
F_9 ( V_10 , L_13 ) ;
}
