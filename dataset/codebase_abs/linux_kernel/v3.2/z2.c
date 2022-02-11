static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_2 ( & V_2 [ 0 ] ) ;
F_2 ( & V_2 [ 1 ] ) ;
}
static inline void F_3 ( void ) {}
static void T_1 F_4 ( void )
{
F_5 ( NULL , & V_3 ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_6 ( void )
{
F_7 ( & V_4 ) ;
}
static inline void F_6 ( void ) {}
static void T_1 F_8 ( void )
{
F_2 ( & V_5 ) ;
}
static inline void F_8 ( void ) {}
static void T_1 F_9 ( void )
{
F_10 ( & V_6 ) ;
}
static inline void F_9 ( void ) {}
static void T_1 F_11 ( void )
{
F_2 ( & V_7 ) ;
}
static inline void F_11 ( void ) {}
static void T_1 F_12 ( void )
{
F_13 ( NULL ) ;
F_14 ( 0 , F_15 ( V_8 ) ) ;
}
static inline void F_12 ( void ) {}
static int F_16 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
V_11 = F_17 ( V_12 , L_1 ) ;
if ( V_11 )
goto V_13;
V_11 = F_18 ( V_12 , 1 ) ;
if ( V_11 )
goto V_14;
F_19 ( 180 ) ;
V_10 -> V_15 = 16 ;
V_10 -> V_16 = V_17 ,
F_20 ( V_10 ) ;
return 0 ;
V_14:
F_21 ( V_12 ) ;
V_13:
return V_11 ;
}
static int F_22 ( struct V_9 * V_10 )
{
F_23 ( V_12 , 0 ) ;
F_21 ( V_12 ) ;
return 0 ;
}
static void T_1 F_24 ( void )
{
F_25 ( 1 , & V_18 ) ;
F_25 ( 2 , & V_19 ) ;
F_26 ( V_20 , F_27 ( V_20 ) ) ;
}
static inline void F_24 ( void ) {}
static void T_1 F_28 ( void )
{
F_29 ( NULL ) ;
F_14 ( 1 , F_15 ( V_21 ) ) ;
}
static inline void F_28 ( void ) {}
static void F_30 ( void )
{
V_22 = 0x0 ;
F_31 () ;
F_32 ( V_23 ) ;
F_33 ( V_24 ) ;
}
static void T_1 F_34 ( void )
{
F_35 ( F_15 ( V_25 ) ) ;
F_36 ( NULL ) ;
F_37 ( NULL ) ;
F_38 ( NULL ) ;
F_4 () ;
F_6 () ;
F_9 () ;
F_12 () ;
F_24 () ;
F_1 () ;
F_3 () ;
F_8 () ;
F_11 () ;
F_28 () ;
V_26 = F_30 ;
}
