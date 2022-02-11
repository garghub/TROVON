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
static int F_5 ( void )
{
V_3 . V_4 = ( V_5 ) V_6 ;
V_7 = * V_8 ;
V_9 = F_6 ( & V_3 ) ;
return 0 ;
}
static void F_7 ( void )
{
* V_8 = V_7 ;
}
static int T_1 F_8 ( void )
{
if ( F_9 () ) {
F_10 ( & V_10 ) ;
return 0 ;
}
return - V_11 ;
}
static int F_11 ( struct V_12 * V_13 , int V_14 )
{
F_12 ( V_15 , ! V_14 ) ;
F_13 ( 50 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
F_12 ( V_16 , 1 ) ;
F_13 ( 50 ) ;
F_12 ( V_16 , 0 ) ;
F_13 ( 50 ) ;
return 0 ;
}
static inline void T_1 F_15 ( void )
{
int V_17 ;
V_17 = F_16 ( F_17 ( V_18 ) ) ;
if ( ! V_17 )
F_18 ( F_17 ( V_18 ) ) ;
else
F_19 ( V_19 L_1 ) ;
return;
}
static void T_1 F_20 ( void )
{
F_15 () ;
F_21 ( & V_20 ) ;
F_4 ( & V_21 ) ;
F_4 ( & V_22 ) ;
}
static inline void F_20 ( void ) {}
static void T_1 F_22 ( void )
{
F_23 ( F_17 ( V_23 ) ) ;
F_24 ( NULL ) ;
F_25 ( NULL ) ;
F_26 ( NULL ) ;
F_27 ( V_24 , V_25 ,
V_26 , 1 ) ;
F_28 ( - 1 , & V_27 ) ;
F_29 ( V_28 ,
V_29 , 0 ) ;
F_30 ( V_30 ) ;
F_31 ( V_31 , V_32 ,
- 1 , 113 ) ;
F_32 ( - 1 , - 1 ) ;
F_33 ( - 1 , - 1 ) ;
F_34 () ;
F_1 () ;
F_3 () ;
F_20 () ;
}
