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
F_8 ( NULL ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( 3 , & V_12 ) ;
F_11 ( & V_13 ) ;
}
void F_12 ( void )
{
F_13 ( V_14 . V_15 , 1 ) ;
F_14 ( V_14 . V_15 , 1 ) ;
F_15 ( & V_16 ) ;
}
void T_1 F_16 ( void )
{
F_17 () ;
F_9 () ;
#if F_18 ( V_17 ) || F_18 ( V_18 )
F_19 ( 0 , & V_19 ) ;
#else
F_20 ( 0 , & V_19 ) ;
#endif
F_12 () ;
}
static void T_1 F_21 ( void )
{
F_16 () ;
F_22 ( & V_20 ) ;
F_23 ( & V_21 ) ;
F_24 ( & V_22 ) ;
F_25 ( NULL , 0 ) ;
F_26 ( V_23 , F_27 ( V_23 ) ) ;
F_28 ( V_24 , F_27 ( V_24 ) ) ;
}
static void T_1 F_29 ( void )
{
F_16 () ;
F_22 ( & V_20 ) ;
F_23 ( & V_25 ) ;
F_24 ( & V_22 ) ;
F_25 ( NULL , 0 ) ;
F_28 ( V_26 , F_27 ( V_26 ) ) ;
}
