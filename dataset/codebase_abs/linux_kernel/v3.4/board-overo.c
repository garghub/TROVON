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
#if F_19 ( V_20 ) || F_19 ( V_21 )
V_22 [ 2 ] . V_18 = V_18 + V_23 + 1 ;
#endif
return 0 ;
}
static int T_1 F_20 ( void )
{
F_21 ( & V_24 ,
V_25 | V_26 ,
V_27 | V_28 ) ;
V_24 . V_29 -> V_30 . V_31 = L_4 ;
F_22 ( L_5 , & V_24 ) ;
F_23 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
F_1 () ;
F_25 ( V_32 ,
F_8 ( V_32 ) ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
int V_33 ;
F_27 ( 0 , V_34 , F_8 ( V_34 ) ) ;
F_28 ( V_35 , V_36 ) ;
F_29 ( V_37 ) ;
F_20 () ;
F_30 ( & V_38 ) ;
F_31 () ;
F_32 ( V_39 ,
V_39 ) ;
F_33 ( 0 , V_40 ,
F_8 ( V_40 ) ) ;
F_34 ( NULL ) ;
F_35 ( & V_41 ) ;
F_24 () ;
F_4 () ;
F_6 () ;
F_16 () ;
F_17 () ;
F_36 ( L_6 , V_42 ) ;
F_36 ( L_7 , V_42 ) ;
V_33 = F_37 ( V_43 , V_44 ,
L_8 ) ;
if ( V_33 == 0 ) {
F_10 ( V_43 , 0 ) ;
F_14 ( V_43 , 0 ) ;
F_38 ( 10 ) ;
F_14 ( V_43 , 1 ) ;
} else {
F_9 ( V_6 L_9
L_10 ) ;
}
V_33 = F_7 ( V_45 , F_8 ( V_45 ) ) ;
if ( V_33 ) {
F_39 ( L_11 , V_46 ) ;
} else {
F_10 ( V_47 , 0 ) ;
F_10 ( V_48 , 0 ) ;
F_14 ( V_48 , 0 ) ;
F_40 ( 6 ) ;
F_14 ( V_48 , 1 ) ;
}
V_33 = F_37 ( V_49 , V_44 ,
L_12 ) ;
if ( V_33 == 0 )
F_10 ( V_49 , 0 ) ;
else
F_9 ( V_6 L_9
L_13 ) ;
}
