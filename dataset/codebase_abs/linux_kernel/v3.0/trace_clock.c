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
unsigned long V_1 ;
int V_2 ;
T_1 V_3 ;
F_8 ( V_1 ) ;
V_2 = F_9 () ;
V_3 = F_10 ( V_2 ) ;
if ( F_11 ( F_12 () ) )
goto V_4;
F_13 ( & V_5 . V_6 ) ;
if ( ( V_7 ) ( V_3 - V_5 . V_8 ) < 0 )
V_3 = V_5 . V_8 + 1 ;
V_5 . V_8 = V_3 ;
F_14 ( & V_5 . V_6 ) ;
V_4:
F_15 ( V_1 ) ;
return V_3 ;
}
