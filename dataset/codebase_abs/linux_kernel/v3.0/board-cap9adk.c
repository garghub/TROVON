static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( V_3 , 1 ) ;
F_5 ( 0 , 0 , 0 ) ;
F_6 ( 0 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( NULL ) ;
}
static int F_9 ( void )
{
return ! F_10 ( V_4 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( V_4 , 1 ) ;
F_12 ( V_5 , 1 ) ;
}
static void T_1 F_11 ( void ) {}
static struct V_6 * T_1 F_13 ( int V_7 , int * V_8 )
{
* V_8 = F_14 ( V_9 ) ;
return V_9 ;
}
static void T_1 F_15 ( void )
{
unsigned long V_10 ;
V_10 = F_16 ( V_11 ) ;
F_17 ( V_11 , V_10 | V_12 ) ;
V_13 . V_14 = F_18 () ;
if ( V_13 . V_14 )
V_15 . V_16 |= V_17 ;
else
V_15 . V_16 |= V_18 ;
F_19 ( 3 , & V_15 ) ;
F_20 ( & V_13 ) ;
}
static T_1 void F_21 ( void )
{
unsigned long V_10 ;
V_10 = F_16 ( V_11 ) ;
F_17 ( V_11 , V_10 | V_12 ) ;
F_19 ( 0 , & V_19 ) ;
F_22 ( & V_20 ) ;
}
static void F_23 ( int V_21 )
{
if ( V_21 )
F_24 ( V_22 , 0 ) ;
else
F_24 ( V_22 , 1 ) ;
}
static void T_1 F_25 ( void )
{
F_26 () ;
F_27 ( & V_23 ) ;
F_28 ( & V_24 ) ;
F_29 ( V_25 , F_14 ( V_25 ) ) ;
F_11 () ;
F_30 ( 1 , & V_26 ) ;
F_31 ( & V_27 ) ;
F_15 () ;
F_21 () ;
F_32 ( NULL , 0 ) ;
F_33 ( & V_28 ) ;
F_34 ( & V_29 ) ;
}
