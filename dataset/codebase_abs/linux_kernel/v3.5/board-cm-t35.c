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
if ( F_8 ( & V_6 ) < 0 )
F_9 ( L_1 ) ;
}
static inline void F_7 ( void ) {}
static int F_10 ( struct V_7 * V_8 )
{
if ( V_9 ) {
F_11 ( V_10 L_2 ) ;
return - V_11 ;
}
F_12 ( V_12 , 1 ) ;
F_12 ( V_13 , 1 ) ;
V_14 = 1 ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
V_14 = 0 ;
F_12 ( V_13 , 0 ) ;
F_12 ( V_12 , 0 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_15 ( struct V_7 * V_8 )
{
}
static void T_1 F_16 ( void )
{
int V_15 ;
F_17 ( V_16 ,
F_3 ( V_16 ) ) ;
V_15 = F_18 ( V_17 ,
F_3 ( V_17 ) ) ;
if ( V_15 ) {
F_9 ( L_3 ) ;
return;
}
F_19 ( V_12 , 0 ) ;
F_19 ( V_13 , 0 ) ;
F_20 ( 50 ) ;
F_12 ( V_12 , 1 ) ;
V_15 = F_21 ( & V_18 ) ;
if ( V_15 ) {
F_9 ( L_4 ) ;
F_22 ( V_17 , F_3 ( V_17 ) ) ;
}
}
static void T_1 F_23 ( void )
{
int V_15 ;
V_15 = F_24 ( V_19 ,
V_20 , L_5 ) ;
if ( V_15 ) {
F_9 ( L_6 , V_15 ) ;
} else {
F_25 ( 10 ) ;
F_12 ( V_19 , 1 ) ;
F_20 ( 1 ) ;
}
F_26 ( & V_21 ) ;
}
static int F_27 ( struct V_22 * V_23 , unsigned V_24 ,
unsigned V_25 )
{
int V_26 = V_24 + 2 ;
if ( F_24 ( V_26 , V_27 , L_7 ) == 0 ) {
F_19 ( V_26 , 0 ) ;
F_25 ( 10 ) ;
F_28 ( V_26 , 0 ) ;
F_25 ( 10 ) ;
F_28 ( V_26 , 1 ) ;
} else {
F_9 ( L_8 ) ;
}
V_28 [ 0 ] . V_29 = V_24 + 0 ;
F_29 ( V_28 ) ;
return 0 ;
}
static void T_1 F_30 ( void )
{
F_31 ( & V_30 , V_31 ,
V_32 |
V_33 ) ;
F_32 ( L_9 , & V_30 ) ;
}
static void T_1 F_33 ( int V_34 )
{
F_34 ( L_10 , V_34 ) ;
F_34 ( L_11 , V_34 ) ;
F_34 ( L_12 , V_34 ) ;
F_34 ( L_13 , V_34 ) ;
F_34 ( L_14 , V_34 ) ;
F_34 ( L_15 , V_34 ) ;
}
static void T_1 F_35 ( void )
{
int V_34 = V_35 | V_36 ;
F_34 ( L_16 , V_34 ) ;
F_34 ( L_17 , V_34 ) ;
F_34 ( L_18 , V_34 ) ;
F_34 ( L_19 , V_34 ) ;
F_34 ( L_20 , V_34 ) ;
F_34 ( L_21 , V_34 ) ;
F_33 ( V_34 ) ;
}
static void T_1 F_36 ( void )
{
int V_34 = V_37 | V_36 ;
F_34 ( L_22 , V_34 ) ;
F_34 ( L_23 , V_34 ) ;
F_34 ( L_24 , V_34 ) ;
F_34 ( L_25 , V_34 ) ;
F_34 ( L_26 , V_34 ) ;
F_34 ( L_27 , V_34 ) ;
F_33 ( V_34 ) ;
}
static inline void F_35 ( void ) {}
static inline void F_36 ( void ) {}
static void T_1 F_37 ( void )
{
V_38 = V_39 ;
V_40 = F_3 ( V_39 ) ;
F_38 ( V_41 , V_42 ) ;
F_39 () ;
F_40 ( V_43 ,
V_43 ) ;
F_41 ( V_28 ) ;
F_30 () ;
F_42 ( 1 , V_44 , 0 , NULL ) ;
F_1 () ;
F_5 () ;
F_16 () ;
F_43 ( NULL ) ;
F_23 () ;
}
static void T_1 F_44 ( void )
{
F_37 () ;
F_35 () ;
F_7 () ;
}
static void T_1 F_45 ( void )
{
F_37 () ;
F_36 () ;
}
