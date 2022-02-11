T_1 T_2 F_1 ( void )
{
T_1 clock ;
F_2 () ;
clock = F_3 () ;
F_4 () ;
return clock ;
}
T_1 T_2 F_5 ( void )
{
return F_6 () ;
}
T_1 T_2 F_7 ( void )
{
return F_8 ( V_1 - V_2 ) ;
}
T_1 T_2 F_9 ( void )
{
unsigned long V_3 ;
int V_4 ;
T_1 V_5 ;
F_10 ( V_3 ) ;
V_4 = F_11 () ;
V_5 = F_12 ( V_4 ) ;
if ( F_13 ( F_14 () ) )
goto V_6;
F_15 ( & V_7 . V_8 ) ;
if ( ( V_9 ) ( V_5 - V_7 . V_10 ) < 0 )
V_5 = V_7 . V_10 + 1 ;
V_7 . V_10 = V_5 ;
F_16 ( & V_7 . V_8 ) ;
V_6:
F_17 ( V_3 ) ;
return V_5 ;
}
T_1 T_2 F_18 ( void )
{
return F_19 ( 1 , & V_11 ) ;
}
