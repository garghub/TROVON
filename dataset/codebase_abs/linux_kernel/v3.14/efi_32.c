void F_1 ( void ) {}
void F_2 ( void ) {}
void T_1 F_3 ( T_2 * V_1 )
{
F_4 ( V_1 ) ;
}
void T_1 F_5 ( T_2 * V_1 ) {}
void T_1 F_6 ( T_3 V_2 , T_4 V_3 ) {}
void F_7 ( void )
{
struct V_4 V_5 ;
F_8 ( V_6 ) ;
F_9 ( V_7 ) ;
F_10 () ;
V_5 . V_8 = F_11 ( F_12 ( 0 ) ) ;
V_5 . V_9 = V_10 - 1 ;
F_13 ( & V_5 ) ;
}
void F_14 ( void )
{
struct V_4 V_5 ;
V_5 . V_8 = ( unsigned long ) F_12 ( 0 ) ;
V_5 . V_9 = V_10 - 1 ;
F_13 ( & V_5 ) ;
F_9 ( V_11 ) ;
F_10 () ;
F_15 ( V_6 ) ;
}
void T_1 F_16 ( void )
{
if ( V_12 & V_13 )
F_17 () ;
}
