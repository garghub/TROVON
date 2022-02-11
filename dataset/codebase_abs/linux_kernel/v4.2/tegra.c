static void T_1 F_1 ( void )
{
F_2 () ;
F_3 () ;
F_4 () ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
F_7 () ;
}
static void T_1 F_8 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = NULL ;
V_2 = F_9 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
goto V_8;
V_2 -> V_9 = F_10 ( V_7 , L_1 ) ;
V_2 -> V_10 = F_10 ( V_7 , L_2 ,
V_11 . V_10 ) ;
V_2 -> V_12 = F_10 ( V_7 , L_3 , F_11 () ) ;
V_4 = F_12 ( V_2 ) ;
if ( F_13 ( V_4 ) ) {
F_14 ( V_2 -> V_9 ) ;
F_14 ( V_2 -> V_10 ) ;
F_14 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
goto V_8;
}
V_6 = F_15 ( V_4 ) ;
V_8:
F_16 ( NULL , V_13 , NULL , V_6 ) ;
}
static void T_1 F_17 ( void )
{
if ( F_18 ( V_14 ) )
F_19 () ;
}
static void T_1 F_20 ( void )
{
int V_15 ;
F_21 () ;
F_22 () ;
for ( V_15 = 0 ; V_15 < F_23 ( V_16 ) ; V_15 ++ ) {
if ( F_24 ( V_16 [ V_15 ] . V_17 ) ) {
V_16 [ V_15 ] . F_25 () ;
break;
}
}
}
