static void T_1
F_1 ( void )
{
F_2 () ;
F_3 () ;
}
static int
F_4 ( void )
{
return ! F_5 ( V_1 ) ;
}
static T_2
F_6 ( int V_2 , void * V_3 )
{
if ( F_5 ( V_4 ) ) {
F_7 ( V_5 L_1 ) ;
F_8 ( F_9 ( V_4 ) ,
V_6 ) ;
} else {
F_7 ( V_5 L_2 ) ;
F_8 ( F_9 ( V_4 ) ,
V_7 ) ;
}
return V_8 ;
}
static void T_1
F_10 ( int V_9 )
{
if ( V_9 )
F_11 ( 0x8000 , V_10 ) ;
else {
F_11 ( 0x00f5 , V_10 ) ;
F_11 ( 0x00a0 , V_10 ) ;
}
}
static void T_1
F_12 ( int V_11 )
{
if ( V_11 ) {
F_13 ( 1 , 1 ) ;
} else {
if ( F_14 ( V_12 , L_3 ) < 0 ) {
F_7 ( V_13 L_4 ) ;
return;
}
F_15 ( V_12 ) ;
if ( F_14 ( V_4 , L_5 ) < 0 ) {
F_7 ( V_13
L_6 ) ;
return;
}
F_15 ( V_4 ) ;
if ( F_16 ( F_9 ( V_4 ) ,
F_6 , V_14 ,
L_7 , 0 ) )
F_7 ( V_13
L_8 ) ;
F_6 ( F_9 ( V_4 ) , 0 ) ;
}
}
static void T_1
F_17 ( void )
{
F_18 ( V_15 ) ;
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_18 ( V_19 ) ;
F_18 ( V_20 ) ;
F_12 ( 1 ) ;
F_10 ( 0 ) ;
V_21 = V_22 ;
V_23 = F_19 ( V_22 ) ;
F_20 ( V_24 , F_19 ( V_24 ) ) ;
F_21 ( V_25 ,
F_19 ( V_25 ) ) ;
F_22 ( & V_26 ) ;
F_23 () ;
F_24 ( 1 , 100 , NULL , 0 ) ;
F_12 ( 0 ) ;
}
static void T_1
F_25 ( void )
{
F_26 () ;
}
