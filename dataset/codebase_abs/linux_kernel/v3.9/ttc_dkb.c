static void F_1 ( int V_1 )
{
int V_2 ;
T_1 V_3 = F_2 ( V_4 ) ;
if ( V_1 ) {
V_2 = F_3 ( V_3 , L_1 ) ;
if ( V_2 ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_3 , 0 ) ;
F_6 ( 100 ) ;
F_7 ( V_3 , 1 ) ;
F_8 ( V_3 ) ;
} else {
V_2 = F_3 ( V_3 , L_1 ) ;
if ( V_2 ) {
F_4 ( L_3 ) ;
return;
}
F_7 ( V_3 , 0 ) ;
F_8 ( V_3 ) ;
}
}
static void T_2 F_9 ( void )
{
F_10 ( & V_5 ,
& V_6 , sizeof( V_6 ) ) ;
F_11 ( V_7 , F_12 ( V_7 ) ) ;
F_10 ( & V_8 ,
& V_9 , sizeof( V_9 ) ) ;
F_10 ( & V_10 ,
& V_11 , sizeof( V_11 ) ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( F_15 ( V_12 ) ) ;
F_16 ( 1 ) ;
#ifdef F_17
F_18 ( & V_13 ) ;
#endif
F_19 ( 0 , NULL , F_15 ( V_14 ) ) ;
F_20 ( F_15 ( V_15 ) ) ;
#ifdef F_21
V_16 . V_17 . V_18 = & V_19 ;
F_22 ( & V_16 ) ;
#endif
#ifdef F_23
V_20 . V_17 . V_18 = & V_19 ;
F_22 ( & V_20 ) ;
#endif
#ifdef F_24
V_21 . V_17 . V_18 = & V_19 ;
F_22 ( & V_21 ) ;
#endif
#ifdef F_25
F_9 () ;
#endif
}
