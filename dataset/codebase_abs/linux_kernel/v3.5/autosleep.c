static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 ;
if ( ! F_2 ( & V_3 , true ) )
goto V_5;
F_3 ( & V_6 ) ;
if ( ! F_4 ( V_3 ) ) {
F_5 ( & V_6 ) ;
goto V_5;
}
if ( V_7 == V_8 ) {
F_5 ( & V_6 ) ;
return;
}
if ( V_7 >= V_9 )
F_6 () ;
else
F_7 ( V_7 ) ;
F_5 ( & V_6 ) ;
if ( ! F_2 ( & V_4 , false ) )
goto V_5;
if ( V_4 == V_3 )
F_8 ( V_10 / 2 ) ;
V_5:
F_9 () ;
}
void F_9 ( void )
{
if ( ! F_10 ( & V_11 ) && V_7 > V_8 )
F_11 ( V_12 , & V_11 ) ;
}
T_1 F_12 ( void )
{
return V_7 ;
}
int F_13 ( void )
{
return F_14 ( & V_6 ) ;
}
void F_15 ( void )
{
F_5 ( & V_6 ) ;
}
int F_16 ( T_1 V_13 )
{
#ifndef F_17
if ( V_13 >= V_9 )
return - V_14 ;
#endif
F_18 ( V_15 ) ;
F_3 ( & V_6 ) ;
V_7 = V_13 ;
F_19 ( V_15 ) ;
if ( V_13 > V_8 ) {
F_20 ( true ) ;
F_9 () ;
} else {
F_20 ( false ) ;
}
F_5 ( & V_6 ) ;
return 0 ;
}
int T_2 F_21 ( void )
{
V_15 = F_22 ( L_1 ) ;
if ( ! V_15 )
return - V_16 ;
V_12 = F_23 ( L_1 , 0 ) ;
if ( V_12 )
return 0 ;
F_24 ( V_15 ) ;
return - V_16 ;
}
