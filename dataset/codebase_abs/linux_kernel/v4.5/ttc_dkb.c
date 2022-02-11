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
#if F_17 ( V_13 )
F_18 ( & V_14 ) ;
#endif
F_19 ( 0 , NULL , F_15 ( V_15 ) ) ;
F_20 ( & V_16 , & V_17 ,
sizeof( struct V_18 ) ) ;
F_21 ( F_15 ( V_19 ) ) ;
#if F_17 ( V_20 )
V_21 . V_22 . V_23 = & V_24 ;
F_22 ( & V_21 ) ;
#endif
#if F_17 ( V_25 )
V_26 . V_22 . V_23 = & V_24 ;
F_22 ( & V_26 ) ;
#endif
#if F_17 ( V_27 )
V_28 . V_22 . V_23 = & V_24 ;
F_22 ( & V_28 ) ;
#endif
#if F_17 ( V_29 )
F_9 () ;
#endif
}
