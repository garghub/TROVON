static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_2 ( & V_2 ) ;
}
static void T_1 F_3 ( void ) {}
static void T_1 F_4 ( void )
{
F_5 ( & V_3 ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_6 ( void )
{
F_2 ( & V_4 ) ;
}
static inline void F_6 ( void ) {}
static void T_1 F_7 ( void )
{
F_2 ( & V_5 ) ;
}
static inline void F_7 ( void ) {}
static int F_8 ( struct V_6 * V_7 )
{
V_8 = V_9 | V_10 | V_11 | V_12 ;
return 0 ;
}
static void T_1 F_9 ( void )
{
F_10 ( & V_13 ) ;
}
static inline void F_9 ( void ) {}
static void F_11 ( int V_14 )
{
if ( V_14 == V_15 )
V_8 = V_10 | V_16 ;
else if ( V_14 == V_17 )
V_8 = V_10 ;
}
static void T_1 F_12 ( void )
{
F_13 ( & V_18 ) ;
F_2 ( & V_19 ) ;
}
static inline void F_12 ( void ) {}
static void T_1 F_14 ( void )
{
F_2 ( & V_20 ) ;
}
static inline void F_14 ( void ) {}
static void T_1 F_15 ( void )
{
F_16 ( & V_21 ) ;
F_2 ( & V_22 ) ;
}
static inline void F_15 ( void ) {}
static void T_1 F_17 ( void )
{
F_18 ( 0 , F_19 ( V_23 ) ) ;
}
static inline void F_17 ( void ) {}
static void F_20 ( int V_24 , struct V_25 * V_26 )
{
F_21 ( V_27 , V_24 ) ;
}
static void T_1 F_22 ( void )
{
int V_28 ;
V_28 = F_23 ( V_27 , L_1 ) ;
if ( V_28 ) {
F_24 ( L_2 ) ;
goto V_29;
}
V_28 = F_25 ( V_27 , 1 ) ;
if ( V_28 ) {
F_24 ( L_3 ) ;
goto V_30;
}
V_31 . V_32 = F_20 ;
F_26 ( NULL , & V_31 ) ;
return;
V_30:
F_27 ( V_27 ) ;
V_29:
return;
}
static inline void F_22 ( void ) {}
static void T_1 F_28 ( void )
{
F_2 ( & V_33 ) ;
}
static inline void F_28 ( void ) {}
static void T_1 F_29 ( void )
{
F_18 ( 1 , F_19 ( V_34 ) ) ;
}
static inline void F_29 ( void ) {}
static void T_1 F_30 ( void )
{
F_31 ( F_19 ( V_35 ) ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_34 ( NULL ) ;
F_35 ( NULL ) ;
F_36 ( NULL ) ;
F_29 () ;
F_22 () ;
F_4 () ;
F_1 () ;
F_3 () ;
F_7 () ;
F_6 () ;
F_9 () ;
F_12 () ;
F_14 () ;
F_15 () ;
F_17 () ;
F_28 () ;
}
