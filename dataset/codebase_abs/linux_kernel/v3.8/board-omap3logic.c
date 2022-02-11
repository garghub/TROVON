static int T_1 F_1 ( void )
{
F_2 ( L_1 , & V_1 ) ;
return 0 ;
}
static void T_1 F_3 ( void )
{
if ( F_4 () ) {
V_2 [ 0 ] . V_3 = V_4 ;
V_2 [ 0 ] . V_5 = V_6 ;
F_5 ( L_2 , V_7 ) ;
F_5 ( L_3 , V_7 ) ;
} else if ( F_6 () ) {
V_2 [ 0 ] . V_3 = V_8 ;
F_5 ( L_4 , V_7 ) ;
} else {
F_7 ( V_9 L_5 , V_10 ) ;
return;
}
F_8 ( V_2 ) ;
}
static void F_9 ( void )
{
T_2 V_11 = V_12 ;
T_3 V_13 ;
if ( F_6 () )
{
V_13 = F_10 ( V_11 ) ;
V_13 &= ~ V_14 ;
F_11 ( V_13 , V_11 ) ;
F_12 ( 100 ) ;
V_13 |= V_15 ;
V_13 |= V_14 ;
F_11 ( V_13 | 0x300 , V_11 ) ;
}
}
static inline void T_1 F_13 ( void )
{
if ( F_4 () ) {
V_16 . V_17 =
V_18 ;
F_5 ( L_6 , V_19 ) ;
} else if ( F_6 () ) {
V_16 . V_17 = V_20 ;
F_5 ( L_7 , V_19 ) ;
} else {
F_7 ( V_9 L_5 , V_10 ) ;
return;
}
F_14 ( & V_16 ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( 0 , V_21 , F_17 ( V_21 ) ) ;
F_18 ( V_22 , V_23 ) ;
F_9 () ;
F_1 () ;
F_19 () ;
F_20 ( NULL , NULL ) ;
F_3 () ;
F_13 () ;
F_21 ( NULL ) ;
F_5 ( L_8 , V_7 ) ;
F_5 ( L_9 , V_7 ) ;
}
