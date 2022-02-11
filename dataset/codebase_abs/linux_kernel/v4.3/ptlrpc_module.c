static int T_1 F_1 ( void )
{
int V_1 , V_2 = 0 ;
F_2 () ;
#if V_3
F_3 ( & V_4 ) ;
#endif
F_4 ( & V_5 ) ;
F_4 ( & V_6 ) ;
F_4 ( & V_7 ) ;
F_5 () ;
V_1 = F_6 () ;
if ( V_1 )
return V_1 ;
V_1 = F_7 () ;
if ( V_1 )
return V_1 ;
V_2 = 1 ;
V_1 = F_8 () ;
if ( V_1 )
goto V_8;
V_2 = 2 ;
V_1 = F_9 () ;
if ( V_1 )
goto V_8;
V_2 = 3 ;
V_1 = F_10 () ;
if ( V_1 )
goto V_8;
V_2 = 4 ;
V_9 = V_10 ;
V_1 = F_11 () ;
if ( V_1 )
goto V_8;
V_2 = 5 ;
V_1 = F_12 () ;
if ( V_1 )
goto V_8;
V_2 = 6 ;
V_1 = F_13 () ;
if ( V_1 )
goto V_8;
V_2 = 7 ;
V_1 = F_14 () ;
if ( V_1 )
goto V_8;
V_2 = 8 ;
V_1 = F_15 () ;
if ( V_1 )
goto V_8;
return 0 ;
V_8:
switch ( V_2 ) {
case 8 :
F_16 () ;
case 7 :
F_17 () ;
case 6 :
F_18 () ;
case 5 :
F_19 () ;
case 4 :
F_20 () ;
case 3 :
F_21 () ;
case 2 :
F_22 () ;
case 1 :
F_23 () ;
F_24 () ;
default: ;
}
return V_1 ;
}
static void T_2 F_25 ( void )
{
F_26 () ;
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_20 () ;
}
