static int F_1 ( unsigned long V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
static int V_5 ;
if ( ! V_5 && V_2 == 0x1406 ) {
V_5 = 1 ;
return 0 ;
}
return 1 ;
}
static void T_1 F_2 ( void )
{
F_3 ( NULL ) ;
F_4 () ;
F_5 () ;
F_6 ( F_7 () ) ;
#ifdef F_8
F_9 ( 0 , ~ 0UL ) ;
#endif
if ( F_10 ( L_1 ) )
F_11 ( 16 + 6 , F_1 , V_6 , 0 ,
L_2 ) ;
}
static void T_1 F_12 ( void )
{
struct V_7 * V_8 ;
T_2 V_9 , V_10 ;
if ( F_13 ( & V_10 , & V_9 ) == 0 && V_9 > V_11 )
return;
F_14 (np, NULL, L_3 ) {
struct V_12 * V_13 ;
V_13 = F_15 ( sizeof( * V_13 ) , V_14 ) ;
V_13 -> V_15 = F_16 ( L_4 , V_14 ) ;
V_13 -> V_16 = sizeof( L_5 ) ;
V_13 -> V_17 = F_16 ( L_5 ,
V_14 ) ;
F_17 ( V_8 , V_13 ) ;
}
return;
}
static void T_1 F_18 ( void )
{
if ( F_10 ( L_6 ) )
F_12 () ;
F_19 ( NULL , V_18 , NULL , NULL ) ;
}
