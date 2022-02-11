static int F_1 ( void * V_1 , bool V_2 )
{
T_1 V_3 = V_2 ? V_4 : V_5 ;
int V_6 ;
F_2 () ;
V_6 = F_3 ( & V_3 , V_7 ) ;
F_4 () ;
return V_6 ;
}
static int F_5 ( void * V_1 , bool V_2 )
{
T_1 V_8 = V_2 ? V_9 : V_10 ;
T_1 V_11 = V_2 ? V_12 : V_13 ;
F_6 ( V_8 , V_14 ) ;
F_6 ( V_11 , V_15 ) ;
if ( F_7 ( V_14 ) != V_8 || F_7 ( V_15 ) != V_11 )
return - V_16 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
int V_6 ;
const struct V_19 * V_20 =
F_9 ( V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_23 = F_10 ( V_24 , & V_18 -> V_25 ,
V_26 ,
V_20 -> V_27 , NULL ) ;
if ( ! V_23 )
return - V_28 ;
V_6 = F_11 ( V_23 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_12 ( V_23 ) ;
return V_6 ;
}
static int F_13 ( struct V_17 * V_18 )
{
F_14 ( V_23 ) ;
F_12 ( V_23 ) ;
return 0 ;
}
static int T_2 F_15 ( void )
{
int V_6 ;
if ( F_9 ( V_21 ) == NULL )
return - V_30 ;
V_6 = F_16 ( & V_31 ) ;
if ( V_6 )
return V_6 ;
V_32 = F_17 ( V_24 , - 1 ,
NULL , 0 ) ;
if ( F_18 ( V_32 ) ) {
V_6 = F_19 ( V_32 ) ;
goto V_29;
}
return 0 ;
V_29:
F_20 ( & V_31 ) ;
return V_6 ;
}
static void T_3 F_21 ( void )
{
F_22 ( V_32 ) ;
F_20 ( & V_31 ) ;
}
