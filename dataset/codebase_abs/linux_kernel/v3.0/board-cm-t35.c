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
static int F_24 ( struct V_18 * V_19 , unsigned V_20 ,
unsigned V_21 )
{
int V_22 = V_20 + 2 ;
if ( F_25 ( V_22 , V_23 , L_6 ) == 0 ) {
F_20 ( V_22 , 0 ) ;
F_26 ( 10 ) ;
F_10 ( V_22 , 0 ) ;
F_26 ( 10 ) ;
F_10 ( V_22 , 1 ) ;
} else {
F_7 ( L_7 ) ;
}
V_24 [ 0 ] . V_25 = V_20 + 0 ;
F_27 ( V_24 ) ;
V_26 . V_19 = V_24 [ 0 ] . V_19 ;
V_27 . V_19 = V_24 [ 0 ] . V_19 ;
return 0 ;
}
static void T_1 F_28 ( void )
{
F_29 ( L_8 , & V_28 ) ;
}
static void T_1 F_30 ( void )
{
F_31 () ;
F_32 ( V_29 ,
V_29 ) ;
}
static void T_1 F_33 ( void )
{
V_30 = V_31 ;
V_32 = F_18 ( V_31 ) ;
F_34 ( V_33 , V_34 ) ;
F_35 () ;
F_28 () ;
F_5 () ;
F_36 ( 1 , V_35 , 0 , NULL ) ;
F_1 () ;
F_3 () ;
F_16 () ;
F_37 ( NULL ) ;
F_38 ( & V_36 ) ;
}
