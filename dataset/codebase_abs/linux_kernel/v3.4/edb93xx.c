static void T_1 F_1 ( void )
{
if ( F_2 () || F_3 () ||
F_4 () ) {
F_5 ( 4 , V_1 , V_2 ) ;
} else {
F_5 ( 2 , V_1 , V_3 ) ;
}
}
static void T_1 F_6 ( void )
{
if ( F_7 () || F_8 () ||
F_9 () ) {
F_10 ( & V_4 ,
V_5 ,
F_11 ( V_5 ) ) ;
} else if ( F_2 () || F_3 () ||
F_4 () ) {
F_10 ( & V_4 ,
V_6 ,
F_11 ( V_6 ) ) ;
}
}
static int F_12 ( struct V_7 * V_8 )
{
return F_13 ( V_9 ,
V_10 , V_8 -> V_11 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
F_15 ( V_9 ) ;
}
static void F_16 ( struct V_7 * V_8 , int V_12 )
{
F_17 ( V_9 , V_12 ) ;
}
static void T_1 F_18 ( void )
{
if ( F_19 () || F_20 () )
V_13 . V_14 = V_15 ;
else if ( F_7 () || F_8 () )
V_13 . V_14 = F_21 ( 2 ) ;
else if ( F_9 () )
V_13 . V_14 = V_16 ;
F_22 ( & V_17 , V_18 ,
F_11 ( V_18 ) ) ;
}
static int T_1 F_23 ( void )
{
return ( F_19 () || F_20 () ||
F_7 () || F_8 () ||
F_9 () ) ;
}
static void T_1 F_24 ( void )
{
if ( F_23 () ) {
F_25 () ;
F_26 ( & V_19 ) ;
}
}
static void T_1 F_27 ( void )
{
if ( F_19 () ||
F_20 () || F_7 () ) {
F_28 ( 0 , 1 ) ;
} else if ( F_2 () || F_8 () ) {
F_28 ( 1 , 0 ) ;
} else {
F_28 ( 1 , 1 ) ;
}
}
static int T_1 F_29 ( void )
{
return F_2 () || F_8 () ||
F_3 () || F_4 () ||
F_9 () ;
}
static void T_1 F_30 ( void )
{
if ( ! F_29 () )
return;
if ( F_8 () || F_9 () )
V_20 . V_21 |= V_22 ;
else
V_20 . V_21 |= V_23 ;
F_31 ( & V_20 ) ;
}
static void T_1 F_32 ( void )
{
F_33 () ;
F_1 () ;
F_34 ( & V_24 , 1 ) ;
F_6 () ;
F_18 () ;
F_24 () ;
F_27 () ;
F_30 () ;
}
