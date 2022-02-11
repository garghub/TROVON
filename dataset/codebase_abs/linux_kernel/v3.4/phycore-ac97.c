static int T_1 F_1 ( void )
{
int V_1 ;
if ( F_2 () ) {
F_3 ( V_2 ,
V_3 |
F_4 ( 3 ) |
V_4 |
F_5 ( 3 ) ) ;
F_3 ( 3 ,
V_3 |
F_4 ( 0 ) |
V_5 |
F_5 ( 0 ) ) ;
} else if ( F_6 () ) {
F_7 ( 3 ,
V_6 |
F_8 ( 0 ) |
V_7 ,
F_9 ( 0 ) ) ;
F_7 ( 0 ,
V_6 |
F_10 ( 3 ) |
V_8 ,
F_9 ( 3 ) ) ;
} else {
return 0 ;
}
V_9 = F_11 ( L_1 , - 1 ) ;
if ( ! V_9 )
return - V_10 ;
F_12 ( V_9 , & V_11 ) ;
V_1 = F_13 ( V_9 ) ;
if ( V_1 )
goto V_12;
V_13 = F_11 ( L_2 , - 1 ) ;
if ( ! V_13 ) {
V_1 = - V_10 ;
goto V_14;
}
V_1 = F_13 ( V_13 ) ;
if ( V_1 ) {
F_14 ( V_15 L_3 ) ;
goto V_16;
}
return 0 ;
V_16:
F_15 ( V_13 ) ;
V_14:
F_16 ( V_9 ) ;
V_12:
F_15 ( V_9 ) ;
return V_1 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_13 ) ;
F_18 ( V_9 ) ;
}
