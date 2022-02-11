static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = NULL ;
F_2 () ;
V_2 = F_3 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
goto V_8;
V_2 -> V_9 = F_4 ( V_7 , L_1 ) ;
V_2 -> V_10 = F_4 ( V_7 , L_2 , V_11 ) ;
V_2 -> V_12 = F_4 ( V_7 , L_2 , V_13 ) ;
V_4 = F_5 ( V_2 ) ;
if ( F_6 ( V_4 ) ) {
F_7 ( V_2 -> V_9 ) ;
F_7 ( V_2 -> V_10 ) ;
F_7 ( V_2 -> V_12 ) ;
F_7 ( V_2 ) ;
goto V_8;
}
V_6 = F_8 ( V_4 ) ;
V_8:
F_9 ( NULL , V_14 ,
V_15 , V_6 ) ;
}
static void T_1 F_10 ( void )
{
#ifdef F_11
int V_16 ;
V_16 = F_12 ( true , true ) ;
if ( V_16 )
F_13 ( L_3 , V_16 ) ;
#endif
}
static void T_1 F_14 ( void )
{
#ifdef F_11
int V_16 ;
V_16 = F_15 () ;
if ( V_16 )
F_13 ( L_4 , V_16 ) ;
#endif
}
static void T_1 F_16 ( void )
{
if ( F_17 ( V_17 ) )
F_18 () ;
}
static void T_1 F_19 ( void )
{
int V_18 ;
F_20 () ;
for ( V_18 = 0 ; V_18 < F_21 ( V_19 ) ; V_18 ++ ) {
if ( F_22 ( V_19 [ V_18 ] . V_20 ) ) {
V_19 [ V_18 ] . F_23 () ;
break;
}
}
}
