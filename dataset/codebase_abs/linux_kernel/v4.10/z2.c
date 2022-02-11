static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_4 ( V_2 , F_5 ( V_2 ) ) ;
F_2 ( & V_3 [ 0 ] ) ;
F_2 ( & V_3 [ 1 ] ) ;
}
static inline void F_3 ( void ) {}
static void T_1 F_6 ( void )
{
F_7 ( NULL , & V_4 ) ;
}
static inline void F_6 ( void ) {}
static void T_1 F_8 ( void )
{
F_9 ( & V_5 ) ;
}
static inline void F_8 ( void ) {}
static void T_1 F_10 ( void )
{
F_2 ( & V_6 ) ;
}
static inline void F_10 ( void ) {}
static void T_1 F_11 ( void )
{
F_12 ( & V_7 ) ;
}
static inline void F_11 ( void ) {}
static void T_1 F_13 ( void )
{
F_2 ( & V_8 ) ;
}
static inline void F_13 ( void ) {}
static void T_1 F_14 ( void )
{
F_15 ( NULL ) ;
F_16 ( 0 , F_17 ( V_9 ) ) ;
}
static inline void F_14 ( void ) {}
static int F_18 ( struct V_10 * V_11 )
{
int V_12 = 0 ;
V_12 = F_19 ( V_13 , L_1 ) ;
if ( V_12 )
goto V_14;
V_12 = F_20 ( V_13 , 1 ) ;
if ( V_12 )
goto V_15;
F_21 ( 180 ) ;
V_11 -> V_16 = 16 ;
V_11 -> V_17 = V_18 ,
F_22 ( V_11 ) ;
return 0 ;
V_15:
F_23 ( V_13 ) ;
V_14:
return V_12 ;
}
static int F_24 ( struct V_10 * V_11 )
{
F_25 ( V_13 , 0 ) ;
F_23 ( V_13 ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
F_27 ( 1 , & V_19 ) ;
F_27 ( 2 , & V_20 ) ;
F_28 ( V_21 , F_5 ( V_21 ) ) ;
}
static inline void F_26 ( void ) {}
static void T_1 F_29 ( void )
{
F_30 ( NULL ) ;
F_16 ( 1 , F_17 ( V_22 ) ) ;
}
static inline void F_29 ( void ) {}
static void F_31 ( void )
{
V_23 = 0x0 ;
F_32 () ;
F_33 ( V_24 ) ;
F_34 ( V_25 ) ;
}
static void T_1 F_35 ( void )
{
F_36 ( F_17 ( V_26 ) ) ;
F_37 ( NULL ) ;
F_38 ( NULL ) ;
F_39 ( NULL ) ;
F_6 () ;
F_8 () ;
F_11 () ;
F_14 () ;
F_26 () ;
F_1 () ;
F_3 () ;
F_10 () ;
F_13 () ;
F_29 () ;
V_27 = F_31 ;
}
