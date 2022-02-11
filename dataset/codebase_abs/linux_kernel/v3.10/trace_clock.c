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
T_1 V_1 = V_2 - V_3 ;
return ( T_1 ) F_8 ( V_1 ) * 1000ULL ;
}
T_1 T_2 F_9 ( void )
{
unsigned long V_4 ;
int V_5 ;
T_1 V_6 ;
F_10 ( V_4 ) ;
V_5 = F_11 () ;
V_6 = F_12 ( V_5 ) ;
if ( F_13 ( F_14 () ) )
goto V_7;
F_15 ( & V_8 . V_9 ) ;
if ( ( V_10 ) ( V_6 - V_8 . V_11 ) < 0 )
V_6 = V_8 . V_11 + 1 ;
V_8 . V_11 = V_6 ;
F_16 ( & V_8 . V_9 ) ;
V_7:
F_17 ( V_4 ) ;
return V_6 ;
}
T_1 T_2 F_18 ( void )
{
return F_19 ( 1 , & V_12 ) ;
}
