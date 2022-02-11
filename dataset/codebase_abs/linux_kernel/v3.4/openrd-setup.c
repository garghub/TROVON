static int T_1 F_1 ( char * V_1 )
{
V_2 = - V_3 ;
if ( ! V_1 )
return 0 ;
if ( ! strncmp ( V_1 , L_1 , 3 ) ) {
V_2 = 232 ;
} else if ( ! strncmp ( V_1 , L_2 , 3 ) ) {
if ( F_2 () ) {
V_2 = - V_4 ;
return 1 ;
}
V_2 = 485 ;
}
return 1 ;
}
static int T_1 F_3 ( void )
{
F_4 ( V_5 ) ;
if ( F_5 ( 34 , L_3 ) ) {
F_6 ( V_6 L_4
L_5 ) ;
return - V_7 ;
}
if ( F_5 ( 28 , L_6 ) ) {
F_6 ( V_6 L_7
L_8 ) ;
F_7 ( 34 ) ;
return - V_7 ;
}
F_8 ( 34 , 0 ) ;
if ( V_2 == 232 )
F_8 ( 28 , 0 ) ;
else
F_8 ( 28 , 1 ) ;
F_7 ( 34 ) ;
F_7 ( 28 ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_4 ( V_8 ) ;
F_11 () ;
F_12 ( F_13 ( V_9 ) , 25 ) ;
F_14 () ;
if ( F_15 () ) {
V_10 . V_11 = F_16 ( 0 ) ;
V_12 . V_11 = F_16 ( 1 ) ;
}
F_17 ( & V_10 ) ;
if ( ! F_2 () )
F_18 ( & V_12 ) ;
F_19 ( & V_13 ) ;
F_20 () ;
if ( F_21 () || F_15 () ) {
F_22 ( & V_14 ) ;
F_23 ( 0 , V_15 ,
F_24 ( V_15 ) ) ;
F_25 () ;
}
if ( V_2 <= 0 ) {
if ( V_2 < 0 )
F_6 ( V_6 L_9
L_10 ,
V_2 ) ;
if ( F_5 ( 34 , L_3 ) ) {
F_6 ( V_6 L_11
L_12 ) ;
} else {
F_8 ( 34 , 1 ) ;
F_7 ( 34 ) ;
F_26 ( & V_16 ) ;
}
} else {
if ( ! F_3 () )
F_27 () ;
}
}
static int T_1 F_28 ( void )
{
if ( F_2 () ||
F_21 () ||
F_15 () )
F_29 ( V_17 ) ;
return 0 ;
}
