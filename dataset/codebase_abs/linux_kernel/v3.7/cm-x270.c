static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static int F_3 ( struct V_2 * V_3 )
{
int V_4 , V_5 ;
for ( V_4 = 58 ; V_4 <= 77 ; V_4 ++ ) {
V_5 = F_4 ( V_4 , L_1 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_4 ) ;
}
F_6 ( F_7 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
int V_4 ;
F_6 ( F_7 ( V_7 ) ) ;
for ( V_4 = 58 ; V_4 <= 77 ; V_4 ++ )
F_9 ( V_4 ) ;
return 0 ;
}
static void T_1 F_10 ( void )
{
F_2 ( & V_8 ) ;
}
static inline void F_10 ( void ) {}
static void T_1 F_11 ( void )
{
F_12 ( & V_9 ) ;
}
static inline void F_11 ( void ) {}
static void T_1 F_13 ( void )
{
F_14 ( & V_10 ) ;
}
static inline void F_13 ( void ) {}
static int F_15 ( struct V_11 * V_12 )
{
int V_5 = F_4 ( V_13 , L_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_14 , L_3 ) ;
if ( V_5 )
goto V_15;
V_5 = F_16 ( V_14 , 0 ) ;
if ( V_5 )
goto V_15;
F_17 ( 100 ) ;
V_5 = F_16 ( V_13 , 1 ) ;
if ( V_5 )
goto V_15;
F_17 ( 100 ) ;
F_6 ( F_7 ( V_16 ) ) ;
F_18 ( V_14 , 1 ) ;
F_17 ( 100 ) ;
V_12 -> V_17 = 16 ;
F_19 ( V_12 ) ;
return 0 ;
V_15:
F_9 ( V_13 ) ;
return V_5 ;
}
static int F_20 ( struct V_11 * V_12 )
{
F_18 ( V_14 , 0 ) ;
F_9 ( V_14 ) ;
F_9 ( V_13 ) ;
return 0 ;
}
static void T_1 F_21 ( void )
{
F_22 ( 2 , & V_18 ) ;
F_23 ( F_7 ( V_19 ) ) ;
}
static inline void F_21 ( void ) {}
void T_1 F_24 ( void )
{
F_6 ( F_7 ( V_20 ) ) ;
#ifdef F_25
F_26 ( V_21 ) ;
#endif
F_1 () ;
F_13 () ;
F_11 () ;
F_10 () ;
F_21 () ;
}
