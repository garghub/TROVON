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
if ( V_14 ) {
F_11 ( V_10 L_3 ) ;
return - V_11 ;
}
F_12 ( V_15 , 0 ) ;
V_9 = 1 ;
return 0 ;
}
static void F_15 ( struct V_7 * V_8 )
{
F_12 ( V_15 , 1 ) ;
V_9 = 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_17 ( struct V_7 * V_8 )
{
}
static void T_1 F_18 ( void )
{
int V_16 ;
F_19 ( V_17 ,
F_3 ( V_17 ) ) ;
V_16 = F_20 ( V_18 ,
F_3 ( V_18 ) ) ;
if ( V_16 ) {
F_9 ( L_4 ) ;
return;
}
F_21 ( V_12 , 0 ) ;
F_21 ( V_13 , 0 ) ;
F_21 ( V_15 , 0 ) ;
F_22 ( 50 ) ;
F_12 ( V_12 , 1 ) ;
V_16 = F_23 ( & V_19 ) ;
if ( V_16 ) {
F_9 ( L_5 ) ;
F_24 ( V_18 , F_3 ( V_18 ) ) ;
}
}
static void T_1 F_25 ( void )
{
int V_16 ;
V_16 = F_26 ( V_20 ,
V_21 , L_6 ) ;
if ( V_16 ) {
F_9 ( L_7 , V_16 ) ;
} else {
F_27 ( 10 ) ;
F_12 ( V_20 , 1 ) ;
F_22 ( 1 ) ;
}
F_28 ( & V_22 ) ;
}
static int F_29 ( struct V_23 * V_24 , unsigned V_25 ,
unsigned V_26 )
{
int V_27 = V_25 + 2 ;
if ( F_26 ( V_27 , V_28 , L_8 ) == 0 ) {
F_21 ( V_27 , 0 ) ;
F_27 ( 10 ) ;
F_30 ( V_27 , 0 ) ;
F_27 ( 10 ) ;
F_30 ( V_27 , 1 ) ;
} else {
F_9 ( L_9 ) ;
}
V_29 [ 0 ] . V_30 = V_25 + 0 ;
F_31 ( V_29 ) ;
return 0 ;
}
static void T_1 F_32 ( void )
{
F_33 ( & V_31 , V_32 ,
V_33 |
V_34 ) ;
F_34 ( L_10 , & V_31 ) ;
}
static void T_1 F_35 ( int V_35 )
{
F_36 ( L_11 , V_35 ) ;
F_36 ( L_12 , V_35 ) ;
F_36 ( L_13 , V_35 ) ;
F_36 ( L_14 , V_35 ) ;
F_36 ( L_15 , V_35 ) ;
F_36 ( L_16 , V_35 ) ;
}
static void T_1 F_37 ( void )
{
int V_35 = V_36 | V_37 ;
F_36 ( L_17 , V_35 ) ;
F_36 ( L_18 , V_35 ) ;
F_36 ( L_19 , V_35 ) ;
F_36 ( L_20 , V_35 ) ;
F_36 ( L_21 , V_35 ) ;
F_36 ( L_22 , V_35 ) ;
F_35 ( V_35 ) ;
}
static void T_1 F_38 ( void )
{
int V_35 = V_38 | V_37 ;
F_36 ( L_23 , V_35 ) ;
F_36 ( L_24 , V_35 ) ;
F_36 ( L_25 , V_35 ) ;
F_36 ( L_26 , V_35 ) ;
F_36 ( L_27 , V_35 ) ;
F_36 ( L_28 , V_35 ) ;
F_35 ( V_35 ) ;
}
static inline void F_37 ( void ) {}
static inline void F_38 ( void ) {}
static void T_1 F_39 ( void )
{
V_39 = V_40 ;
V_41 = F_3 ( V_40 ) ;
F_40 ( V_42 , V_43 ) ;
F_41 () ;
F_42 ( V_44 ,
V_44 ) ;
F_43 ( V_29 ) ;
F_32 () ;
F_44 ( 1 , V_45 , 0 , NULL ) ;
F_1 () ;
F_5 () ;
F_18 () ;
F_45 ( NULL ) ;
F_25 () ;
}
static void T_1 F_46 ( void )
{
F_39 () ;
F_37 () ;
F_7 () ;
}
static void T_1 F_47 ( void )
{
F_39 () ;
F_38 () ;
}
