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
if ( F_7 ( V_5 , F_8 ( V_5 ) ) ) {
F_9 ( V_6 L_1 ) ;
return;
}
F_10 ( V_7 , 0 ) ;
F_10 ( V_8 , 0 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
if ( V_11 ) {
F_9 ( V_6 L_2 ) ;
return - V_12 ;
}
F_12 ( V_7 , 1 ) ;
F_12 ( V_8 , 1 ) ;
V_13 = 1 ;
return 0 ;
}
static void F_13 ( struct V_9 * V_10 )
{
F_12 ( V_7 , 0 ) ;
F_12 ( V_8 , 0 ) ;
V_13 = 0 ;
}
static void T_1 F_14 ( void )
{
F_3 ( & V_14 ) ;
}
static inline void T_1 F_14 ( void ) { return; }
static void T_1 F_15 ( void )
{
F_3 ( & V_15 ) ;
}
static inline void T_1 F_15 ( void ) { return; }
static int F_16 ( struct V_16 * V_17 ,
unsigned V_18 , unsigned V_19 )
{
#if F_17 ( V_20 ) || F_17 ( V_21 )
V_22 [ 2 ] . V_18 = V_18 + V_23 + 1 ;
#endif
return 0 ;
}
static int T_1 F_18 ( void )
{
F_19 ( & V_24 ,
V_25 | V_26 ,
V_27 | V_28 ) ;
V_24 . V_29 -> V_30 . V_31 = L_3 ;
F_20 ( L_4 , & V_24 ) ;
F_21 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
F_1 () ;
F_23 ( V_32 ,
F_8 ( V_32 ) ) ;
return 0 ;
}
static void T_1 F_24 ( void )
{
int V_33 ;
F_25 ( 0 , V_34 , F_8 ( V_34 ) ) ;
F_26 ( V_35 , V_36 ) ;
F_18 () ;
F_27 ( V_37 ) ;
F_28 ( & V_38 ) ;
F_29 () ;
F_30 ( V_39 ,
V_39 ) ;
F_31 ( V_40 ,
F_8 ( V_40 ) , V_41 , 0 , NULL ) ;
F_32 ( L_5 , 0 , L_6 ) ;
F_33 ( NULL ) ;
F_34 ( & V_42 ) ;
F_22 () ;
F_4 () ;
F_6 () ;
F_14 () ;
F_15 () ;
F_35 ( L_7 , NULL ) ;
F_36 ( L_8 , V_43 ) ;
F_36 ( L_9 , V_43 ) ;
V_33 = F_37 ( V_44 , V_45 ,
L_10 ) ;
if ( V_33 == 0 ) {
F_10 ( V_44 , 0 ) ;
F_12 ( V_44 , 0 ) ;
F_38 ( 10 ) ;
F_12 ( V_44 , 1 ) ;
} else {
F_39 ( L_11 ) ;
}
V_33 = F_7 ( V_46 , F_8 ( V_46 ) ) ;
if ( V_33 ) {
F_39 ( L_12 , V_47 ) ;
} else {
F_10 ( V_48 , 0 ) ;
F_10 ( V_49 , 0 ) ;
F_12 ( V_49 , 0 ) ;
F_40 ( 6 ) ;
F_12 ( V_49 , 1 ) ;
}
V_33 = F_37 ( V_50 , V_45 ,
L_13 ) ;
if ( V_33 == 0 )
F_10 ( V_50 , 0 ) ;
else
F_39 ( L_14 ) ;
}
