static void T_1 F_1 ( void )
{
if ( F_2 () )
V_1 . V_2 =
V_3 ;
if ( F_3 () )
V_1 . V_2 =
V_4 ;
else
V_1 . V_2 =
V_5 ;
F_4 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static int F_5 ( struct V_6 * V_7 )
{
V_8 = V_9 | V_10 | V_11 | V_12 ;
return 0 ;
}
static void T_1 F_6 ( void )
{
if ( F_2 () )
V_13 . V_14 |= V_15 ;
F_7 ( & V_13 ) ;
}
static inline void F_6 ( void ) {}
static void T_1 F_8 ( void )
{
F_9 ( NULL ) ;
F_10 ( 0 , F_11 ( V_16 ) ) ;
}
static inline void F_8 ( void ) {}
void T_1 F_12 ( void )
{
F_13 ( NULL ) ;
F_14 ( NULL ) ;
F_15 ( NULL ) ;
F_1 () ;
F_6 () ;
F_8 () ;
}
