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
V_13 = 1 ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
V_13 = 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
if ( V_13 ) {
F_9 ( V_6 L_3 ) ;
return - V_12 ;
}
F_14 ( V_7 , 1 ) ;
F_14 ( V_8 , 1 ) ;
V_11 = 1 ;
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
F_14 ( V_7 , 0 ) ;
F_14 ( V_8 , 0 ) ;
V_11 = 0 ;
}
static void T_1 F_16 ( void )
{
F_3 ( & V_14 ) ;
}
static inline void T_1 F_16 ( void ) { return; }
static void T_1 F_17 ( void )
{
F_3 ( & V_15 ) ;
}
static inline void T_1 F_17 ( void ) { return; }
static int F_18 ( struct V_16 * V_17 ,
unsigned V_18 , unsigned V_19 )
{
F_19 ( V_20 ) ;
V_21 . V_17 = V_20 [ 0 ] . V_17 ;
#if F_20 ( V_22 ) || F_20 ( V_23 )
V_24 [ 2 ] . V_18 = V_18 + V_25 + 1 ;
#endif
return 0 ;
}
static int T_1 F_21 ( void )
{
F_22 ( L_4 , & V_26 ) ;
F_23 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
F_1 () ;
F_25 ( V_27 ,
F_8 ( V_27 ) ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
F_27 () ;
F_28 ( V_28 ,
V_28 ) ;
}
static void T_1 F_29 ( void )
{
int V_29 ;
F_30 ( V_30 , V_31 ) ;
F_21 () ;
F_31 ( & V_32 ) ;
F_32 () ;
F_33 ( 0 , V_33 ,
F_8 ( V_33 ) ) ;
F_34 ( NULL ) ;
F_35 ( & V_34 ) ;
F_24 () ;
F_1 () ;
F_4 () ;
F_6 () ;
F_16 () ;
F_17 () ;
F_36 ( L_5 , V_35 ) ;
F_36 ( L_6 , V_35 ) ;
V_29 = F_37 ( V_36 , V_37 ,
L_7 ) ;
if ( V_29 == 0 ) {
F_10 ( V_36 , 0 ) ;
F_14 ( V_36 , 0 ) ;
F_38 ( 10 ) ;
F_14 ( V_36 , 1 ) ;
} else {
F_9 ( V_6 L_8
L_9 ) ;
}
V_29 = F_7 ( V_38 , F_8 ( V_38 ) ) ;
if ( V_29 ) {
F_39 ( L_10 , V_39 ) ;
} else {
F_10 ( V_40 , 0 ) ;
F_10 ( V_41 , 0 ) ;
F_14 ( V_41 , 0 ) ;
F_40 ( 6 ) ;
F_14 ( V_41 , 1 ) ;
}
V_29 = F_37 ( V_42 , V_37 ,
L_11 ) ;
if ( V_29 == 0 )
F_10 ( V_42 , 0 ) ;
else
F_9 ( V_6 L_8
L_12 ) ;
}
