static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_3 ) ;
}
static inline void T_1 F_1 ( void ) {}
static void T_1 F_6 ( void )
{
F_3 ( F_4 ( V_4 ) ) ;
}
static inline void F_6 ( void ) {}
static inline void T_1 F_7 ( void )
{
if ( ! F_8 () )
return;
F_3 ( F_4 ( V_5 ) ) ;
F_9 ( NULL ) ;
}
static inline void F_7 ( void ) {}
void T_1 F_10 ( void )
{
F_1 () ;
F_11 () ;
F_6 () ;
F_12 ( F_13 ( V_6 ) ) ;
F_7 () ;
F_3 ( F_4 ( V_7 ) ) ;
F_14 () ;
}
