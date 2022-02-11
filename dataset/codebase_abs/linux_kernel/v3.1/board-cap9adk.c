static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( V_3 , 1 ) ;
F_5 ( 0 , 0 , 0 ) ;
F_6 ( 0 ) ;
}
static int F_7 ( void )
{
return ! F_8 ( V_4 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_4 , 1 ) ;
F_10 ( V_5 , 1 ) ;
}
static void T_1 F_9 ( void ) {}
static struct V_6 * T_1 F_11 ( int V_7 , int * V_8 )
{
* V_8 = F_12 ( V_9 ) ;
return V_9 ;
}
static void T_1 F_13 ( void )
{
unsigned long V_10 ;
V_10 = F_14 ( V_11 ) ;
F_15 ( V_11 , V_10 | V_12 ) ;
V_13 . V_14 = F_16 () ;
if ( V_13 . V_14 )
V_15 . V_16 |= V_17 ;
else
V_15 . V_16 |= V_18 ;
F_17 ( 3 , & V_15 ) ;
F_18 ( & V_13 ) ;
}
static T_1 void F_19 ( void )
{
unsigned long V_10 ;
V_10 = F_14 ( V_11 ) ;
F_15 ( V_11 , V_10 | V_12 ) ;
F_17 ( 0 , & V_19 ) ;
F_20 ( & V_20 ) ;
}
static void F_21 ( int V_21 )
{
if ( V_21 )
F_22 ( V_22 , 0 ) ;
else
F_22 ( V_22 , 1 ) ;
}
static void T_1 F_23 ( void )
{
F_24 () ;
F_25 ( & V_23 ) ;
F_26 ( & V_24 ) ;
F_27 ( V_25 , F_12 ( V_25 ) ) ;
F_9 () ;
F_28 ( 1 , & V_26 ) ;
F_29 ( & V_27 ) ;
F_13 () ;
F_19 () ;
F_30 ( NULL , 0 ) ;
F_31 ( & V_28 ) ;
F_32 ( & V_29 ) ;
}
