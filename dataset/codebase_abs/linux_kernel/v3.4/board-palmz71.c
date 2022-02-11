static int
F_1 ( void )
{
return ! F_2 ( V_1 ) ;
}
static T_1
F_3 ( int V_2 , void * V_3 )
{
if ( F_2 ( V_4 ) ) {
F_4 ( V_5 L_1 ) ;
F_5 ( F_6 ( V_4 ) ,
V_6 ) ;
} else {
F_4 ( V_5 L_2 ) ;
F_5 ( F_6 ( V_4 ) ,
V_7 ) ;
}
return V_8 ;
}
static void T_2
F_7 ( int V_9 )
{
if ( V_9 )
F_8 ( 0x8000 , V_10 ) ;
else {
F_8 ( 0x00f5 , V_10 ) ;
F_8 ( 0x00a0 , V_10 ) ;
}
}
static void T_2
F_9 ( int V_11 )
{
if ( V_11 ) {
F_10 ( 1 , 1 ) ;
} else {
if ( F_11 ( V_12 , L_3 ) < 0 ) {
F_4 ( V_13 L_4 ) ;
return;
}
F_12 ( V_12 ) ;
if ( F_11 ( V_4 , L_5 ) < 0 ) {
F_4 ( V_13
L_6 ) ;
return;
}
F_12 ( V_4 ) ;
if ( F_13 ( F_6 ( V_4 ) ,
F_3 , V_14 ,
L_7 , 0 ) )
F_4 ( V_13
L_8 ) ;
F_3 ( F_6 ( V_4 ) , 0 ) ;
}
}
static void T_2
F_14 ( void )
{
F_15 ( V_15 ) ;
F_15 ( V_16 ) ;
F_15 ( V_17 ) ;
F_15 ( V_18 ) ;
F_15 ( V_19 ) ;
F_15 ( V_20 ) ;
F_9 ( 1 ) ;
F_7 ( 0 ) ;
F_16 ( V_21 , F_17 ( V_21 ) ) ;
V_22 [ 0 ] . V_2 = F_6 ( V_1 ) ;
F_18 ( V_22 ,
F_17 ( V_22 ) ) ;
F_19 ( & V_23 ) ;
F_20 () ;
F_21 ( 1 , 100 , NULL , 0 ) ;
F_9 ( 0 ) ;
F_22 ( & V_24 ) ;
}
