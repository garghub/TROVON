static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_2 ( V_8 L_1 , V_9 ) ;
F_3 () ;
F_2 ( V_8 L_2 ) ;
}
static int T_1 F_4 ( void )
{
int V_10 ;
struct V_11 V_12 ;
F_5 ( & V_12 ) ;
V_12 . V_13 = F_6 ( V_9 ) ;
V_12 . V_14 = V_15 ;
V_12 . V_16 = V_17 | V_18 ;
V_19 = F_7 ( & V_12 , F_1 ) ;
if ( F_8 ( ( void V_20 * ) V_19 ) ) {
V_10 = F_9 ( ( void V_20 * ) V_19 ) ;
goto V_21;
}
F_2 ( V_8 L_3 , V_9 ) ;
return 0 ;
V_21:
F_2 ( V_8 L_4 ) ;
return V_10 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_19 ) ;
F_2 ( V_8 L_5 , V_9 ) ;
}
