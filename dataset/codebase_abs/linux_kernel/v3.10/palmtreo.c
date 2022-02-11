static void T_1 F_1 ( void )
{
static struct V_1 * V_2 = & V_3 ;
if ( F_2 () ) {
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = F_3 ( V_5 ) ;
}
F_4 ( & V_3 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_5 ( void )
{
if ( F_6 () )
F_7 ( & V_7 ) ;
}
static inline void F_5 ( void ) {}
static void T_1 F_8 ( void )
{
if ( F_2 () )
V_8 . V_9 . V_10 = & V_11 ;
else if ( F_6 () )
V_8 . V_9 . V_10 = & V_12 ;
F_9 ( & V_8 ) ;
}
static void T_1 F_10 ( void )
{
F_9 ( & V_13 ) ;
}
static inline void F_10 ( void ) {}
static void T_1 F_11 ( void )
{
F_12 ( 0xa0000000 , 0x1000 ) ;
F_12 ( 0xa2000000 , 0x1000 ) ;
}
static void T_1 F_13 ( void )
{
F_14 ( F_15 ( V_14 ) ) ;
F_16 ( NULL ) ;
F_17 ( NULL ) ;
F_18 ( NULL ) ;
F_19 ( V_15 ) ;
F_20 ( V_16 , & V_17 ) ;
F_21 ( V_18 , V_19 , 1 ) ;
F_22 ( V_20 ) ;
F_23 ( - 1 , - 1 , - 1 , 95 ) ;
F_24 ( V_16 , - 1 ) ;
F_25 ( V_21 , - 1 ) ;
F_26 () ;
F_1 () ;
F_5 () ;
F_8 () ;
}
void T_1 F_27 ( void )
{
unsigned int V_22 ;
const unsigned long V_23 = V_24 | V_25 ;
V_22 = V_26 ;
if ( F_28 ( V_22 , V_23 , L_1 ) < 0 )
goto V_27;
V_22 = V_28 ;
if ( F_28 ( V_22 , V_23 , L_2 ) < 0 )
goto V_27;
V_22 = V_29 ;
if ( F_28 ( V_22 , V_23 , L_3 ) < 0 )
goto V_27;
F_29 ( V_29 , 0 ) ;
return;
V_27:
F_30 ( L_4 , V_22 ) ;
F_31 ( V_26 ) ;
F_31 ( V_28 ) ;
F_31 ( V_29 ) ;
}
static void T_1 F_32 ( void )
{
F_14 ( F_15 ( V_30 ) ) ;
F_13 () ;
F_27 () ;
F_33 ( V_31 , V_32 ,
V_33 , 0 ) ;
F_10 () ;
}
static void T_1 F_34 ( void )
{
F_14 ( F_15 ( V_34 ) ) ;
F_13 () ;
F_33 ( V_31 , - 1 ,
V_35 , 1 ) ;
}
