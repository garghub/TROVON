static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_4 ( & V_2 ) ;
}
static inline void F_3 ( void ) {}
static int F_5 ( struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_6 ( V_6 , L_1 ) ;
if ( V_5 )
goto V_7;
V_5 = F_7 ( V_6 , 1 ) ;
if ( V_5 )
goto V_8;
return 0 ;
V_8:
F_8 ( V_6 ) ;
V_7:
return V_5 ;
}
static int F_9 ( struct V_3 * V_4 , int V_9 )
{
F_10 ( V_6 , V_9 ) ;
return V_9 ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_8 ( V_6 ) ;
}
static void T_1 F_12 ( void )
{
F_4 ( & V_10 ) ;
}
static inline void F_12 ( void ) {}
static void T_1 F_13 ( void )
{
F_14 ( & V_11 ) ;
}
static inline void F_13 ( void ) {}
static void T_1 F_15 ( void )
{
F_4 ( & V_12 ) ;
}
static inline void F_15 ( void ) {}
static void T_1 F_16 ( void )
{
F_4 ( & V_13 ) ;
}
static inline void F_16 ( void ) {}
static void T_1 F_17 ( void )
{
F_18 ( NULL ) ;
F_4 ( & V_14 ) ;
}
static inline void F_17 ( void ) {}
static void T_1 F_19 ( void )
{
F_4 ( & V_15 ) ;
}
static inline void F_19 ( void ) {}
static void T_1 F_20 ( void )
{
F_4 ( & V_16 ) ;
}
static inline void F_20 ( void ) {}
static void T_1 F_21 ( void )
{
F_22 ( NULL , & V_17 ) ;
}
static inline void F_21 ( void ) {}
static void T_1 F_23 ( void )
{
F_24 ( F_25 ( V_18 ) ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
F_28 ( NULL ) ;
F_29 ( NULL ) ;
F_1 () ;
F_3 () ;
F_12 () ;
F_13 () ;
F_15 () ;
F_16 () ;
F_17 () ;
F_20 () ;
F_21 () ;
F_19 () ;
}
