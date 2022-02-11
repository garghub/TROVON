static void T_1 F_1 ( void )
{
F_2 ( 1 , & V_1 ) ;
F_3 ( F_4 ( V_2 ) ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_5 ( void )
{
F_6 ( & V_3 ) ;
}
static inline void F_5 ( void ) {}
static void T_1 F_7 ( void )
{
F_6 ( & V_4 ) ;
}
static inline void F_7 ( void ) {}
void T_1 F_8 ( void )
{
F_9 ( F_4 ( V_5 ) ) ;
F_1 () ;
F_5 () ;
F_7 () ;
}
