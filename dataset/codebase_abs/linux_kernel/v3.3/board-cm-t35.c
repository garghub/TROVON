static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
F_2 ( & V_2 ) ;
}
static inline void T_1 F_1 ( void ) { return; }
static void T_1 F_3 ( void )
{
F_4 ( & V_3 ) ;
}
static inline void F_3 ( void ) {}
static void T_1 F_5 ( void )
{
if ( F_6 ( & V_4 ) < 0 )
F_7 ( L_1 ) ;
}
static inline void F_5 ( void ) {}
static int F_8 ( struct V_5 * V_6 )
{
if ( V_7 ) {
F_9 ( V_8 L_2 ) ;
return - V_9 ;
}
F_10 ( V_10 , 1 ) ;
F_10 ( V_11 , 1 ) ;
V_12 = 1 ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 )
{
V_12 = 0 ;
F_10 ( V_11 , 0 ) ;
F_10 ( V_10 , 0 ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
if ( V_12 ) {
F_9 ( V_8 L_3 ) ;
return - V_9 ;
}
F_10 ( V_13 , 0 ) ;
V_7 = 1 ;
return 0 ;
}
static void F_13 ( struct V_5 * V_6 )
{
F_10 ( V_13 , 1 ) ;
V_7 = 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_15 ( struct V_5 * V_6 )
{
}
static void T_1 F_16 ( void )
{
int V_14 ;
F_17 ( V_15 ,
F_18 ( V_15 ) ) ;
V_14 = F_19 ( V_16 ,
F_18 ( V_16 ) ) ;
if ( V_14 ) {
F_7 ( L_4 ) ;
return;
}
F_20 ( V_10 , 0 ) ;
F_20 ( V_11 , 0 ) ;
F_20 ( V_13 , 0 ) ;
F_21 ( 50 ) ;
F_10 ( V_10 , 1 ) ;
V_14 = F_22 ( & V_17 ) ;
if ( V_14 ) {
F_7 ( L_5 ) ;
F_23 ( V_16 , F_18 ( V_16 ) ) ;
}
}
static void T_1 F_24 ( void )
{
int V_14 ;
V_14 = F_25 ( V_18 ,
V_19 , L_6 ) ;
if ( V_14 ) {
F_7 ( L_7 , V_14 ) ;
} else {
F_26 ( 10 ) ;
F_10 ( V_18 , 1 ) ;
F_21 ( 1 ) ;
}
F_27 ( & V_20 ) ;
}
static int F_28 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_24 )
{
int V_25 = V_23 + 2 ;
if ( F_25 ( V_25 , V_26 , L_8 ) == 0 ) {
F_20 ( V_25 , 0 ) ;
F_26 ( 10 ) ;
F_29 ( V_25 , 0 ) ;
F_26 ( 10 ) ;
F_29 ( V_25 , 1 ) ;
} else {
F_7 ( L_9 ) ;
}
V_27 [ 0 ] . V_28 = V_23 + 0 ;
F_30 ( V_27 ) ;
return 0 ;
}
static void T_1 F_31 ( void )
{
F_32 ( & V_29 , V_30 ,
V_31 |
V_32 ) ;
F_33 ( L_10 , & V_29 ) ;
}
static void T_1 F_34 ( int V_33 )
{
F_35 ( L_11 , V_33 ) ;
F_35 ( L_12 , V_33 ) ;
F_35 ( L_13 , V_33 ) ;
F_35 ( L_14 , V_33 ) ;
F_35 ( L_15 , V_33 ) ;
F_35 ( L_16 , V_33 ) ;
}
static void T_1 F_36 ( void )
{
int V_33 = V_34 | V_35 ;
F_35 ( L_17 , V_33 ) ;
F_35 ( L_18 , V_33 ) ;
F_35 ( L_19 , V_33 ) ;
F_35 ( L_20 , V_33 ) ;
F_35 ( L_21 , V_33 ) ;
F_35 ( L_22 , V_33 ) ;
F_34 ( V_33 ) ;
}
static void T_1 F_37 ( void )
{
int V_33 = V_36 | V_35 ;
F_35 ( L_23 , V_33 ) ;
F_35 ( L_24 , V_33 ) ;
F_35 ( L_25 , V_33 ) ;
F_35 ( L_26 , V_33 ) ;
F_35 ( L_27 , V_33 ) ;
F_35 ( L_28 , V_33 ) ;
F_34 ( V_33 ) ;
}
static inline void F_36 ( void ) {}
static inline void F_37 ( void ) {}
static void T_1 F_38 ( void )
{
V_37 = V_38 ;
V_39 = F_18 ( V_38 ) ;
F_39 ( V_40 , V_41 ) ;
F_40 () ;
F_41 ( V_42 ,
V_42 ) ;
F_31 () ;
F_42 ( 1 , V_43 , 0 , NULL ) ;
F_1 () ;
F_3 () ;
F_16 () ;
F_43 ( NULL ) ;
F_24 () ;
}
static void T_1 F_44 ( void )
{
F_38 () ;
F_36 () ;
F_5 () ;
}
static void T_1 F_45 ( void )
{
F_38 () ;
F_37 () ;
}
