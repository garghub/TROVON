static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void F_3 ( void )
{
F_2 ( & V_2 ) ;
}
static inline void F_3 ( void ) {}
static void T_1 F_4 ( void )
{
int V_3 ;
V_3 = F_5 ( V_4 , V_5 ,
L_1 ) ;
if ( V_3 ) {
F_6 ( L_2 , V_3 ) ;
return;
}
F_2 ( & V_6 ) ;
}
static inline void F_4 ( void ) {}
static int T_1 F_7 ( void )
{
int V_3 ;
V_3 = F_5 ( V_7 , V_8 ,
L_3 ) ;
if ( V_3 ) {
F_6 ( L_4 , V_3 ) ;
} else {
F_8 ( 10 ) ;
F_9 ( V_7 , 1 ) ;
F_10 ( 1 ) ;
}
F_11 ( V_9 , F_12 ( V_9 ) ) ;
F_13 ( & V_10 ) ;
return 0 ;
}
static inline int F_7 ( void )
{
return 0 ;
}
static void T_1 F_14 ( void )
{
if ( F_15 ( & V_11 , NULL ) < 0 )
F_6 ( L_5 ) ;
}
static inline void F_14 ( void ) {}
static void T_1 F_16 ( void )
{
F_17 ( V_12 , V_13 ) ;
F_18 () ;
F_19 ( NULL , NULL ) ;
F_1 () ;
F_14 () ;
F_4 () ;
F_7 () ;
F_3 () ;
F_20 ( V_14 , 1 ) ;
F_21 ( V_15 ) ;
}
