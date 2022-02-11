static void T_1 F_1 ( void )
{
F_2 ( 0 , V_1 ,
F_3 ( V_1 ) ) ;
F_2 ( 1 , V_2 ,
F_3 ( V_2 ) ) ;
F_4 ( & V_3 ) ;
F_4 ( & V_4 ) ;
}
static inline void T_1 F_1 ( void ) { return; }
static void T_1 F_5 ( void )
{
F_6 ( & V_5 ) ;
}
static inline void F_5 ( void ) {}
static void T_1 F_7 ( void )
{
if ( F_8 ( & V_6 , NULL ) < 0 )
F_9 ( L_1 ) ;
}
static inline void F_7 ( void ) {}
static void T_1 F_10 ( void )
{
int V_7 ;
F_11 ( V_8 ,
F_3 ( V_8 ) ) ;
V_7 = F_12 ( V_9 , V_10 ,
L_2 ) ;
if ( V_7 ) {
F_9 ( L_3 ) ;
return;
}
F_13 ( 50 ) ;
F_14 ( V_9 , 1 ) ;
V_7 = F_15 ( & V_11 ) ;
if ( V_7 ) {
F_9 ( L_4 ) ;
F_16 ( V_9 ) ;
}
F_6 ( & V_12 ) ;
F_6 ( & V_13 ) ;
F_6 ( & V_14 ) ;
F_6 ( & V_15 ) ;
}
static void T_1 F_17 ( void )
{
int V_7 ;
V_7 = F_12 ( V_16 ,
V_10 , L_5 ) ;
if ( V_7 ) {
F_9 ( L_6 , V_7 ) ;
} else {
F_18 ( 10 ) ;
F_14 ( V_16 , 1 ) ;
F_13 ( 1 ) ;
}
F_19 ( V_17 , F_3 ( V_17 ) ) ;
F_20 ( & V_18 ) ;
}
static int F_21 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_22 )
{
int V_23 = V_21 + 2 ;
if ( F_12 ( V_23 , V_24 , L_7 ) == 0 ) {
F_22 ( V_23 , 0 ) ;
F_18 ( 10 ) ;
F_23 ( V_23 , 0 ) ;
F_18 ( 10 ) ;
F_23 ( V_23 , 1 ) ;
} else {
F_9 ( L_8 ) ;
}
V_25 [ 0 ] . V_26 = V_21 + 0 ;
F_24 ( V_25 ) ;
return 0 ;
}
static void T_1 F_25 ( void )
{
if ( F_26 ( & V_27 ) < 0 )
F_27 ( L_9 ) ;
}
static inline void F_25 ( void ) {}
static void T_1 F_28 ( void )
{
F_29 ( & V_28 , V_29 ,
V_30 |
V_31 ) ;
F_30 ( L_10 , & V_28 ) ;
F_31 ( 3 , 400 , NULL , 0 ) ;
}
static void T_1 F_32 ( int V_32 )
{
F_33 ( L_11 , V_32 ) ;
F_33 ( L_12 , V_32 ) ;
F_33 ( L_13 , V_32 ) ;
F_33 ( L_14 , V_32 ) ;
F_33 ( L_15 , V_32 ) ;
F_33 ( L_16 , V_32 ) ;
}
static void T_1 F_34 ( void )
{
int V_32 = V_33 | V_34 ;
F_33 ( L_17 , V_32 ) ;
F_33 ( L_18 , V_32 ) ;
F_33 ( L_19 , V_32 ) ;
F_33 ( L_20 , V_32 ) ;
F_33 ( L_21 , V_32 ) ;
F_33 ( L_22 , V_32 ) ;
F_32 ( V_32 ) ;
}
static void T_1 F_35 ( void )
{
int V_32 = V_35 | V_34 ;
F_33 ( L_23 , V_32 ) ;
F_33 ( L_24 , V_32 ) ;
F_33 ( L_25 , V_32 ) ;
F_33 ( L_26 , V_32 ) ;
F_33 ( L_27 , V_32 ) ;
F_33 ( L_28 , V_32 ) ;
F_32 ( V_32 ) ;
}
static inline void F_34 ( void ) {}
static inline void F_35 ( void ) {}
static void T_1 F_36 ( void )
{
F_37 ( V_36 , V_37 ) ;
F_38 () ;
F_39 ( V_38 ,
V_38 ) ;
F_40 ( V_25 ) ;
F_28 () ;
F_41 ( 1 , V_39 , 0 , NULL ) ;
F_1 () ;
F_5 () ;
F_10 () ;
F_42 ( L_29 , NULL ) ;
F_43 ( L_30 , 0 , L_31 ) ;
F_44 ( NULL ) ;
F_17 () ;
F_25 () ;
}
static void T_1 F_45 ( void )
{
F_36 () ;
F_34 () ;
F_7 () ;
}
static void T_1 F_46 ( void )
{
F_36 () ;
F_35 () ;
}
