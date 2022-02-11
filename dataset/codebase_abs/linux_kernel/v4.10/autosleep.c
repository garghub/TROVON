static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
if ( ! F_2 ( & V_3 , true ) )
goto V_5;
F_3 ( & V_6 ) ;
if ( ! F_4 ( V_3 ) ||
V_7 != V_8 ) {
F_5 ( & V_6 ) ;
goto V_5;
}
if ( V_9 == V_10 ) {
F_5 ( & V_6 ) ;
return;
}
if ( V_9 >= V_11 )
F_6 () ;
else
F_7 ( V_9 ) ;
F_5 ( & V_6 ) ;
if ( ! F_2 ( & V_4 , false ) )
goto V_5;
if ( V_4 == V_3 )
F_8 ( V_12 / 2 ) ;
V_5:
F_9 () ;
}
void F_9 ( void )
{
if ( V_9 > V_10 )
F_10 ( V_13 , & V_14 ) ;
}
T_1 F_11 ( void )
{
return V_9 ;
}
int F_12 ( void )
{
return F_13 ( & V_6 ) ;
}
void F_14 ( void )
{
F_5 ( & V_6 ) ;
}
int F_15 ( T_1 V_15 )
{
#ifndef F_16
if ( V_15 >= V_11 )
return - V_16 ;
#endif
F_17 ( V_17 ) ;
F_3 ( & V_6 ) ;
V_9 = V_15 ;
F_18 ( V_17 ) ;
if ( V_15 > V_10 ) {
F_19 ( true ) ;
F_9 () ;
} else {
F_19 ( false ) ;
}
F_5 ( & V_6 ) ;
return 0 ;
}
int T_2 F_20 ( void )
{
V_17 = F_21 ( L_1 ) ;
if ( ! V_17 )
return - V_18 ;
V_13 = F_22 ( L_1 , 0 ) ;
if ( V_13 )
return 0 ;
F_23 ( V_17 ) ;
return - V_18 ;
}
