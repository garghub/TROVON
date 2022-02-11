static void T_1 F_1 ( void )
{
F_2 ( 1 , V_1 , 0 , NULL ) ;
F_3 ( & V_2 ) ;
}
static inline void T_1 F_1 ( void ) { return; }
static void T_1 F_4 ( void )
{
F_5 ( & V_3 ) ;
F_5 ( & V_4 ) ;
}
static inline void T_1 F_4 ( void ) { return; }
static void T_1 F_6 ( void )
{
F_3 ( & V_5 ) ;
}
static inline void T_1 F_6 ( void ) { return; }
static void T_1 F_7 ( void )
{
F_3 ( & V_6 ) ;
}
static inline void T_1 F_7 ( void ) { return; }
static int F_8 ( struct V_7 * V_8 ,
unsigned V_9 , unsigned V_10 )
{
#if F_9 ( V_11 ) || F_9 ( V_12 )
V_13 [ 2 ] . V_9 = V_9 + V_14 + 1 ;
#endif
return 0 ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_15 ,
V_16 | V_17 ,
V_18 | V_19 ) ;
V_15 . V_20 -> V_21 . V_22 = L_1 ;
F_12 ( L_2 , & V_15 ) ;
F_13 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
F_1 () ;
F_15 ( V_23 ,
F_16 ( V_23 ) ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
int V_24 ;
F_18 ( 0 , V_25 , F_16 ( V_25 ) ) ;
F_19 ( V_26 , V_27 ) ;
F_10 () ;
F_20 ( V_28 ) ;
F_21 ( & V_29 ) ;
F_22 () ;
F_23 ( V_30 ,
V_30 ) ;
F_24 ( V_31 ,
F_16 ( V_31 ) , V_32 , 0 , NULL ) ;
F_25 ( L_3 , 0 , L_4 ) ;
F_26 ( NULL ) ;
F_27 ( V_33 , F_16 ( V_33 ) ) ;
F_28 ( & V_34 ) ;
F_14 () ;
F_4 () ;
F_6 () ;
F_7 () ;
F_29 ( L_5 , NULL ) ;
F_30 ( L_6 , V_35 ) ;
F_30 ( L_7 , V_35 ) ;
V_24 = F_31 ( V_36 , V_37 ,
L_8 ) ;
if ( V_24 == 0 ) {
F_32 ( V_36 , 0 ) ;
F_33 ( V_36 , 0 ) ;
F_34 ( 10 ) ;
F_33 ( V_36 , 1 ) ;
} else {
F_35 ( L_9 ) ;
}
V_24 = F_36 ( V_38 , F_16 ( V_38 ) ) ;
if ( V_24 ) {
F_35 ( L_10 , V_39 ) ;
} else {
F_32 ( V_40 , 0 ) ;
F_32 ( V_41 , 0 ) ;
F_33 ( V_41 , 0 ) ;
F_37 ( 6 ) ;
F_33 ( V_41 , 1 ) ;
}
V_24 = F_31 ( V_42 , V_37 ,
L_11 ) ;
if ( V_24 == 0 )
F_32 ( V_42 , 0 ) ;
else
F_35 ( L_12 ) ;
}
