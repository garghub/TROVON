static void F_1 ( void )
{
F_2 ( V_1 , 1 ) ;
}
static void F_3 ( unsigned long V_2 )
{
if ( F_4 ( V_3 ) ) {
if ( V_4 > 0 )
V_4 -- ;
} else {
if ( V_4 == 0 ) {
F_5 () ;
F_6 ( V_5 , 0 ) ;
} else {
V_4 = V_6 ;
}
}
F_7 ( & V_7 , V_8 + F_8 ( 500 ) ) ;
}
static T_1 F_9 ( int V_9 , void * V_10 )
{
F_10 () ;
return V_11 ;
}
static void T_2 F_11 ( void )
{
V_12 = V_13 ;
F_12 () ;
}
static int T_2 F_13 ( void )
{
if ( ! F_14 () )
return 0 ;
F_15 ( V_14 , L_1 ) ;
if ( F_16 ( F_17 ( V_14 ) , & F_9 ,
V_15 , L_2 , NULL ) < 0 ) {
F_18 ( V_16 L_3 ,
F_17 ( V_14 ) ) ;
}
F_15 ( V_3 , L_4 ) ;
F_19 ( V_3 ) ;
F_15 ( V_1 , L_5 ) ;
V_4 = V_6 ;
F_7 ( & V_7 , V_8 + F_8 ( 500 ) ) ;
return 0 ;
}
static void T_2 F_20 ( void )
{
F_21 () ;
* V_17 = 0 ;
V_18 . V_19 = F_22 ( 0 ) ;
V_18 . V_20 =
F_22 ( 0 ) + V_21 - 1 ;
F_23 ( 0 , V_22 ,
F_24 ( V_22 ) ) ;
( void ) F_25 ( & V_23 ) ;
F_26 ( V_24 , F_24 ( V_24 ) ) ;
V_25 = F_1 ;
}
