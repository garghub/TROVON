T_1 __weak F_1 ( void )
{
T_2 V_1 ;
if ( ! F_2 () )
return 0 ;
if ( ! ( F_3 () & V_2 ) )
return 0 ;
V_1 = F_4 () ;
if ( V_1 & V_3 )
return V_1 & V_4 ;
V_1 = F_5 () ;
F_6 ( V_1 | V_3 ) ;
return V_1 ;
}
int F_7 ( void )
{
T_1 V_5 ;
V_5 = F_1 () ;
if ( ! V_5 )
return - V_6 ;
V_7 = F_8 ( V_5 , 0x8000 ) ;
if ( ! V_7 )
return - V_8 ;
return 0 ;
}
