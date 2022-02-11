static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_2 ( & V_2 ) ;
}
static inline void F_3 ( void ) {}
static void T_1 F_4 ( void )
{
F_5 ( & V_3 ) ;
F_2 ( & V_4 ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_6 ( void )
{
F_7 ( F_8 ( V_5 ) ) ;
F_1 () ;
F_3 () ;
F_4 () ;
switch ( V_6 ) {
case V_7 :
F_7 ( F_8 (
V_8 ) ) ;
F_9 () ;
break;
case V_9 :
F_7 ( F_8 ( V_10 ) ) ;
F_10 () ;
break;
default:
F_11 ( V_11 L_1 ,
V_6 ) ;
}
F_12 () ;
}
static void T_1 F_13 ( void )
{
V_6 = V_9 ;
F_6 () ;
}
