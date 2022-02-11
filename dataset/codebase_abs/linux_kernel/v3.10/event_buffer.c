void F_1 ( unsigned long V_1 )
{
if ( ! V_2 ) {
F_2 ( 1 ) ;
return;
}
if ( V_3 == V_4 ) {
F_3 ( & V_5 . V_6 ) ;
return;
}
V_2 [ V_3 ] = V_1 ;
if ( ++ V_3 == V_4 - V_7 ) {
F_4 ( & V_8 , 1 ) ;
F_5 ( & V_9 ) ;
}
}
void F_6 ( void )
{
F_7 ( & V_10 ) ;
F_4 ( & V_8 , 1 ) ;
F_5 ( & V_9 ) ;
F_8 ( & V_10 ) ;
}
int F_9 ( void )
{
unsigned long V_11 ;
F_10 ( & V_12 , V_11 ) ;
V_4 = V_13 ;
V_7 = V_14 ;
F_11 ( & V_12 , V_11 ) ;
if ( V_7 >= V_4 )
return - V_15 ;
V_3 = 0 ;
V_2 = F_12 ( sizeof( unsigned long ) * V_4 ) ;
if ( ! V_2 )
return - V_16 ;
return 0 ;
}
void F_13 ( void )
{
F_7 ( & V_10 ) ;
F_14 ( V_2 ) ;
V_3 = 0 ;
V_2 = NULL ;
F_8 ( & V_10 ) ;
}
static int F_15 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
int V_19 = - V_20 ;
if ( ! F_16 ( V_21 ) )
return - V_20 ;
if ( F_17 ( 0 , & V_22 ) )
return - V_23 ;
V_19 = - V_15 ;
V_18 -> V_24 = F_18 () ;
if ( ! V_18 -> V_24 )
goto V_25;
if ( ( V_19 = F_19 () ) )
goto V_26;
return F_20 ( V_17 , V_18 ) ;
V_26:
F_21 ( V_18 -> V_24 ) ;
V_25:
F_22 ( 0 , & V_22 ) ;
return V_19 ;
}
static int F_23 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
F_24 () ;
F_25 () ;
F_21 ( V_18 -> V_24 ) ;
V_3 = 0 ;
F_4 ( & V_8 , 0 ) ;
F_22 ( 0 , & V_22 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_18 * V_18 , char T_2 * V_27 ,
T_3 V_28 , T_4 * V_29 )
{
int V_30 = - V_15 ;
T_3 const V_31 = V_4 * sizeof( unsigned long ) ;
if ( V_28 != V_31 || * V_29 )
return - V_15 ;
F_27 ( V_9 , F_28 ( & V_8 ) ) ;
if ( F_29 ( V_32 ) )
return - V_33 ;
if ( ! F_28 ( & V_8 ) )
return - V_34 ;
F_7 ( & V_10 ) ;
if ( ! V_2 ) {
V_30 = - V_33 ;
goto V_25;
}
F_4 ( & V_8 , 0 ) ;
V_30 = - V_35 ;
V_28 = V_3 * sizeof( unsigned long ) ;
if ( F_30 ( V_27 , V_2 , V_28 ) )
goto V_25;
V_30 = V_28 ;
V_3 = 0 ;
V_25:
F_8 ( & V_10 ) ;
return V_30 ;
}
