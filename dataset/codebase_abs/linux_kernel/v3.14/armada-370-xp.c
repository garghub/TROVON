static void T_1 F_1 ( void )
{
F_2 () ;
}
static void T_1 F_3 ( void )
{
F_4 ( NULL ) ;
F_5 () ;
F_6 () ;
F_7 ( F_8 () ) ;
#ifdef F_9
F_10 ( 0 , ~ 0UL ) ;
#endif
}
static void T_1 F_11 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 , V_4 ;
if ( F_12 ( & V_4 , & V_3 ) == 0 && V_3 > V_5 )
return;
F_13 (np, NULL, L_1 ) {
struct V_6 * V_7 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_8 ) ;
V_7 -> V_9 = F_15 ( L_2 , V_8 ) ;
V_7 -> V_10 = sizeof( L_3 ) ;
V_7 -> V_11 = F_15 ( L_3 ,
V_8 ) ;
F_16 ( V_2 , V_7 ) ;
}
return;
}
static void T_1 F_17 ( void )
{
if ( F_18 ( L_4 ) )
F_11 () ;
F_19 ( NULL , V_12 , NULL , NULL ) ;
}
