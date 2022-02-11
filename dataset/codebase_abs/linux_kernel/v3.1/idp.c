static void F_1 ( int V_1 )
{
if ( V_1 ) {
V_2 |= ( 1 << 1 ) ;
} else {
V_2 &= ~ ( 1 << 1 ) ;
}
}
static void F_2 ( int V_1 )
{
if ( V_1 ) {
V_2 |= ( 1 << 2 ) ;
} else {
V_2 &= ~ ( 1 << 2 ) ;
}
}
static void F_3 ( int V_1 , struct V_3 * V_4 )
{
if ( V_1 ) {
V_2 |= ( 1 << 0 ) ;
} else {
V_2 &= ~ ( 1 << 0 ) ;
}
F_2 ( V_1 ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( L_1 ) ;
F_6 ( F_7 ( V_5 ) ) ;
F_8 ( NULL ) ;
F_9 ( NULL ) ;
F_10 ( NULL ) ;
F_11 ( & V_6 ) ;
F_12 ( NULL , & V_7 ) ;
F_13 ( & V_8 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 ( V_9 , F_17 ( V_9 ) ) ;
}
