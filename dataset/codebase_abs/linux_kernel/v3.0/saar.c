static void F_1 ( int V_1 , struct V_2 * V_3 )
{
static int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_3 , struct V_5 , V_3 ) ;
int V_7 ;
if ( ! V_4 ) {
V_7 = F_3 ( V_8 , L_1 ) ;
if ( V_7 ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_8 , 0 ) ;
V_4 = 1 ;
}
if ( V_1 ) {
F_6 ( V_8 , 0 ) ; F_7 ( 100 ) ;
F_6 ( V_8 , 1 ) ; F_7 ( 10 ) ;
F_8 ( V_6 , F_9 ( V_9 ) ) ;
F_8 ( V_6 , F_9 ( V_10 ) ) ;
} else {
F_8 ( V_6 , F_9 ( V_11 ) ) ;
F_8 ( V_6 , F_9 ( V_12 ) ) ;
}
V_7 = F_10 ( V_6 ) ;
if ( V_7 )
F_4 ( L_3 , V_13 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
F_8 ( V_6 , F_9 ( V_14 ) ) ;
F_10 ( V_6 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( NULL , & V_15 ) ;
}
static inline void F_12 ( void ) {}
static void T_1 F_14 ( void )
{
F_15 ( NULL ) ;
F_16 ( 0 , F_9 ( V_16 ) ) ;
}
static inline void F_14 ( void ) {}
static void T_1 F_17 ( void )
{
F_18 ( & V_17 ) ;
}
static void T_1 F_17 ( void ) {}
static void T_1 F_19 ( void )
{
F_20 ( F_9 ( V_18 ) ) ;
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_18 ( & V_19 ) ;
F_17 () ;
F_14 () ;
F_12 () ;
}
