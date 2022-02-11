static int T_1 F_1 ( unsigned long V_1 )
{
unsigned int V_2 = F_2 () ;
unsigned int V_3 = F_3 ( V_2 , 1 ) ;
unsigned int V_4 = F_3 ( V_2 , 0 ) ;
F_4 ( V_4 , V_3 , V_5 ) ;
F_5 () ;
return 1 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 , int V_10 )
{
F_7 () ;
F_8 ( 0 , F_1 ) ;
F_9 () ;
F_10 () ;
return V_10 ;
}
static int T_2 F_11 ( struct V_8 * V_9 , int V_11 )
{
struct V_12 * V_12 ;
int V_4 ;
V_12 = F_12 ( F_13 () , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
F_14 (cpu)
if ( F_15 ( V_4 ) == V_11 )
F_16 ( V_4 , V_12 ) ;
V_9 -> V_12 = V_12 ;
return 0 ;
}
static int T_2 F_17 ( void )
{
int V_15 ;
struct V_16 * V_17 = F_18 ( L_1 ) ;
if ( ! V_17 )
return - V_18 ;
if ( ! F_19 ( V_19 , V_17 ) )
return - V_18 ;
if ( ! F_20 () )
return - V_20 ;
V_15 = F_11 ( & V_21 ,
V_22 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_23 , V_24 ) ;
if ( V_15 )
goto V_25;
V_15 = F_21 ( & V_23 , V_26 , 1 ) ;
if ( V_15 < 0 )
goto V_27;
V_15 = F_21 ( & V_21 ,
V_26 , 1 ) ;
if ( V_15 < 0 )
goto V_27;
V_15 = F_22 ( & V_21 , NULL ) ;
if ( V_15 )
goto V_27;
V_15 = F_22 ( & V_23 , NULL ) ;
if ( V_15 )
goto V_28;
return 0 ;
V_28:
F_23 ( & V_21 ) ;
V_27:
F_24 ( V_23 . V_12 ) ;
V_25:
F_24 ( V_21 . V_12 ) ;
return V_15 ;
}
