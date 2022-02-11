void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( 0 , 0 , 0 ) ;
F_4 ( 0 ) ;
}
static void T_1 F_5 ( void )
{
F_1 () ;
F_3 ( V_1 , 1 , V_2 | V_3
| V_4 | V_5
| V_6 | V_7 ) ;
}
static void T_1 F_6 ( void )
{
F_1 () ;
F_3 ( V_1 , 1 , V_2 | V_3
| V_4 | V_5
| V_6 | V_7 ) ;
F_3 ( V_8 , 2 , V_2 | V_3 ) ;
F_3 ( V_9 , 3 , V_2 | V_3 ) ;
F_3 ( V_10 , 5 , 0 ) ;
F_3 ( V_11 , 6 , 0 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( 0 , 3 , & V_12 ) ;
F_9 ( & V_13 ) ;
}
void F_10 ( void )
{
F_11 ( V_14 . V_15 , 1 ) ;
F_12 ( V_14 . V_15 , 1 ) ;
F_13 ( & V_16 ) ;
}
void T_1 F_14 ( void )
{
F_15 () ;
F_7 () ;
#if F_16 ( V_17 ) || F_16 ( V_18 )
F_17 ( 0 , & V_19 ) ;
#else
F_18 ( 0 , & V_19 ) ;
#endif
F_10 () ;
}
static void T_1 F_19 ( void )
{
F_14 () ;
F_20 ( & V_20 ) ;
F_21 ( & V_21 ) ;
F_22 ( & V_22 ) ;
F_23 ( NULL , 0 ) ;
F_24 ( V_23 , F_25 ( V_23 ) ) ;
F_26 ( V_24 , F_25 ( V_24 ) ) ;
}
static void T_1 F_27 ( void )
{
F_14 () ;
F_20 ( & V_20 ) ;
F_21 ( & V_25 ) ;
F_22 ( & V_22 ) ;
F_23 ( NULL , 0 ) ;
F_26 ( V_26 , F_25 ( V_26 ) ) ;
}
