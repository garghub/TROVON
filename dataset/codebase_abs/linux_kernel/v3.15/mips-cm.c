T_1 F_1 ( void )
{
T_2 V_1 = F_2 () ;
T_2 V_2 ;
if ( ! ( V_1 & V_3 ) )
return 0 ;
V_2 = F_3 () ;
return ( V_2 & V_4 ) << ( 36 - 32 ) ;
}
T_1 F_4 ( void )
{
T_2 V_5 ;
V_5 = F_5 () ;
if ( V_5 & V_6 )
return V_5 & V_7 ;
return F_6 () + V_8 ;
}
static void F_7 ( void )
{
unsigned V_9 ;
T_1 V_10 ;
V_9 = ( F_8 () & V_11 ) >>
V_12 ;
if ( V_9 < 6 )
return;
V_10 = F_9 () ;
F_10 ( ( V_10 & V_7 ) != V_10 ) ;
if ( ! V_10 )
return;
F_11 ( V_10 | V_6 ) ;
V_13 = F_12 ( V_10 , V_14 ) ;
}
int F_13 ( void )
{
T_1 V_10 ;
T_2 V_5 ;
V_10 = F_6 () ;
F_10 ( ( V_10 & V_15 ) != V_10 ) ;
if ( ! V_10 )
return - V_16 ;
V_17 = F_12 ( V_10 , V_8 ) ;
if ( ! V_17 )
return - V_18 ;
V_5 = F_14 () ;
if ( ( V_5 & V_15 ) != V_10 ) {
F_15 ( L_1 ,
( unsigned long ) V_10 ) ;
V_17 = NULL ;
return - V_16 ;
}
V_5 &= ~ V_19 ;
V_5 |= V_20 ;
F_16 ( V_5 ) ;
F_17 ( V_21 ) ;
F_18 ( V_22 ) ;
F_19 ( V_21 ) ;
F_20 ( V_22 ) ;
F_21 ( V_21 ) ;
F_22 ( V_22 ) ;
F_23 ( V_21 ) ;
F_24 ( V_22 ) ;
F_7 () ;
return 0 ;
}
