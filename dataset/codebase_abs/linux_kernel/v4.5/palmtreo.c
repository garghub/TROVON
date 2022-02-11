static void T_1 F_1 ( void )
{
static struct V_1 * V_2 = & V_3 ;
if ( F_2 () )
V_2 -> V_4 = & V_5 ;
F_3 ( & V_3 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_4 ( void )
{
if ( F_5 () )
F_6 ( & V_6 ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_7 ( void )
{
if ( F_2 () )
V_7 . V_8 . V_9 = & V_10 ;
else if ( F_5 () )
V_7 . V_8 . V_9 = & V_11 ;
F_8 ( & V_7 ) ;
}
static void T_1 F_9 ( void )
{
F_8 ( & V_12 ) ;
}
static inline void F_9 ( void ) {}
static void T_1 F_10 ( void )
{
F_11 ( 0xa0000000 , 0x1000 ) ;
F_11 ( 0xa2000000 , 0x1000 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( F_14 ( V_13 ) ) ;
F_15 ( NULL ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( V_14 ) ;
F_19 ( V_15 , & V_16 ) ;
F_20 ( V_17 , V_18 , 1 ) ;
F_21 ( V_19 ) ;
F_22 ( - 1 , - 1 , - 1 , 95 ) ;
F_23 ( V_15 , - 1 ) ;
F_24 ( V_20 , - 1 ) ;
F_25 () ;
F_1 () ;
F_4 () ;
F_7 () ;
}
void T_1 F_26 ( void )
{
unsigned int V_21 ;
const unsigned long V_22 = V_23 | V_24 ;
V_21 = V_25 ;
if ( F_27 ( V_21 , V_22 , L_1 ) < 0 )
goto V_26;
V_21 = V_27 ;
if ( F_27 ( V_21 , V_22 , L_2 ) < 0 )
goto V_26;
V_21 = V_28 ;
if ( F_27 ( V_21 , V_22 , L_3 ) < 0 )
goto V_26;
F_28 ( V_28 , 0 ) ;
return;
V_26:
F_29 ( L_4 , V_21 ) ;
F_30 ( V_25 ) ;
F_30 ( V_27 ) ;
F_30 ( V_28 ) ;
}
static void T_1 F_31 ( void )
{
F_13 ( F_14 ( V_29 ) ) ;
F_12 () ;
F_26 () ;
F_32 ( V_30 , V_31 ,
V_32 , 0 ) ;
F_9 () ;
}
static void T_1 F_33 ( void )
{
F_13 ( F_14 ( V_33 ) ) ;
F_12 () ;
F_32 ( V_30 , - 1 ,
V_34 , 1 ) ;
}
