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
if ( F_31 ( & V_30 ) < 0 )
F_32 ( L_9 ) ;
}
static inline void F_30 ( void ) {}
static void T_1 F_33 ( void )
{
F_34 ( & V_31 , V_32 ,
V_33 |
V_34 ) ;
F_35 ( L_10 , & V_31 ) ;
F_36 ( 3 , 400 , NULL , 0 ) ;
}
static void T_1 F_37 ( int V_35 )
{
F_38 ( L_11 , V_35 ) ;
F_38 ( L_12 , V_35 ) ;
F_38 ( L_13 , V_35 ) ;
F_38 ( L_14 , V_35 ) ;
F_38 ( L_15 , V_35 ) ;
F_38 ( L_16 , V_35 ) ;
}
static void T_1 F_39 ( void )
{
int V_35 = V_36 | V_37 ;
F_38 ( L_17 , V_35 ) ;
F_38 ( L_18 , V_35 ) ;
F_38 ( L_19 , V_35 ) ;
F_38 ( L_20 , V_35 ) ;
F_38 ( L_21 , V_35 ) ;
F_38 ( L_22 , V_35 ) ;
F_37 ( V_35 ) ;
}
static void T_1 F_40 ( void )
{
int V_35 = V_38 | V_37 ;
F_38 ( L_23 , V_35 ) ;
F_38 ( L_24 , V_35 ) ;
F_38 ( L_25 , V_35 ) ;
F_38 ( L_26 , V_35 ) ;
F_38 ( L_27 , V_35 ) ;
F_38 ( L_28 , V_35 ) ;
F_37 ( V_35 ) ;
}
static inline void F_39 ( void ) {}
static inline void F_40 ( void ) {}
static void T_1 F_41 ( void )
{
F_42 ( V_39 , V_40 ) ;
F_43 () ;
F_44 ( V_41 ,
V_41 ) ;
F_45 ( V_28 ) ;
F_33 () ;
F_46 ( 1 , V_42 , 0 , NULL ) ;
F_1 () ;
F_5 () ;
F_16 () ;
F_47 ( L_29 , NULL ) ;
F_48 ( L_30 , 0 , L_31 ) ;
F_49 ( NULL ) ;
F_23 () ;
F_30 () ;
}
static void T_1 F_50 ( void )
{
F_41 () ;
F_39 () ;
F_7 () ;
}
static void T_1 F_51 ( void )
{
F_41 () ;
F_40 () ;
}
