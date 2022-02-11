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
struct V_27 * V_27 ;
V_27 = F_26 ( NULL , L_9 , NULL , V_28 ,
48000000 ) ;
F_27 ( V_27 , NULL , L_10 ) ;
F_2 ( 2 , V_29 ,
F_3 ( V_29 ) ) ;
if ( F_28 ( & V_30 ) < 0 )
F_29 ( L_11 ) ;
}
static inline void F_25 ( void ) {}
static void T_1 F_30 ( void )
{
F_31 ( & V_31 , V_32 ,
V_33 |
V_34 ) ;
F_32 ( L_12 , & V_31 ) ;
F_33 ( 3 , 400 , NULL , 0 ) ;
}
static void T_1 F_34 ( int V_35 )
{
F_35 ( L_13 , V_35 ) ;
F_35 ( L_14 , V_35 ) ;
F_35 ( L_15 , V_35 ) ;
F_35 ( L_16 , V_35 ) ;
F_35 ( L_17 , V_35 ) ;
F_35 ( L_18 , V_35 ) ;
}
static void T_1 F_36 ( void )
{
int V_35 = V_36 | V_37 ;
F_35 ( L_19 , V_35 ) ;
F_35 ( L_20 , V_35 ) ;
F_35 ( L_21 , V_35 ) ;
F_35 ( L_22 , V_35 ) ;
F_35 ( L_23 , V_35 ) ;
F_35 ( L_24 , V_35 ) ;
F_34 ( V_35 ) ;
}
static void T_1 F_37 ( void )
{
int V_35 = V_38 | V_37 ;
F_35 ( L_25 , V_35 ) ;
F_35 ( L_26 , V_35 ) ;
F_35 ( L_27 , V_35 ) ;
F_35 ( L_28 , V_35 ) ;
F_35 ( L_29 , V_35 ) ;
F_35 ( L_30 , V_35 ) ;
F_34 ( V_35 ) ;
}
static inline void F_36 ( void ) {}
static inline void F_37 ( void ) {}
static void T_1 F_38 ( void )
{
F_39 ( V_39 , V_40 ) ;
F_40 () ;
F_41 ( V_41 ,
V_41 ) ;
F_42 ( V_25 ) ;
F_30 () ;
F_43 ( 1 , V_42 , 0 , NULL ) ;
F_1 () ;
F_5 () ;
F_10 () ;
F_44 ( L_31 , NULL ) ;
F_45 ( L_32 , 0 , L_33 ) ;
F_46 ( NULL ) ;
F_17 () ;
F_25 () ;
}
static void T_1 F_47 ( void )
{
F_38 () ;
F_36 () ;
F_7 () ;
}
static void T_1 F_48 ( void )
{
F_38 () ;
F_37 () ;
}
