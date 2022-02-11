static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( V_7 L_1 , V_8 ) ;
F_3 () ;
F_2 ( V_7 L_2 ) ;
}
static int T_1 F_4 ( void )
{
int V_9 ;
struct V_10 V_11 ;
F_5 ( & V_11 ) ;
V_11 . V_12 = F_6 ( V_8 ) ;
V_11 . V_13 = V_14 ;
V_11 . V_15 = V_16 | V_17 ;
V_18 = F_7 ( & V_11 , F_1 , NULL ) ;
if ( F_8 ( ( void V_19 * ) V_18 ) ) {
V_9 = F_9 ( ( void V_19 * ) V_18 ) ;
goto V_20;
}
F_2 ( V_7 L_3 , V_8 ) ;
return 0 ;
V_20:
F_2 ( V_7 L_4 ) ;
return V_9 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_18 ) ;
F_2 ( V_7 L_5 , V_8 ) ;
}
