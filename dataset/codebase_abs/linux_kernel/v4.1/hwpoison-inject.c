static int F_1 ( void * V_1 , T_1 V_2 )
{
unsigned long V_3 = V_2 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
int V_7 ;
if ( ! F_2 ( V_8 ) )
return - V_9 ;
if ( ! F_3 ( V_3 ) )
return - V_10 ;
V_5 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_5 ) ;
if ( ! F_6 ( V_6 ) )
return 0 ;
if ( ! V_11 )
goto V_12;
if ( ! F_7 ( V_6 ) && ! F_8 ( V_5 ) )
F_9 ( V_6 , 0 ) ;
if ( ! F_7 ( V_6 ) && ! F_8 ( V_5 ) )
goto V_13;
F_10 ( V_6 ) ;
V_7 = F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
if ( V_7 )
goto V_13;
V_12:
F_13 ( L_1 , V_3 ) ;
return F_14 ( V_3 , 18 , V_14 ) ;
V_13:
F_15 ( V_6 ) ;
return 0 ;
}
static int F_16 ( void * V_1 , T_1 V_2 )
{
if ( ! F_2 ( V_8 ) )
return - V_9 ;
return F_17 ( V_2 ) ;
}
static void F_18 ( void )
{
F_19 ( V_15 ) ;
}
static int F_20 ( void )
{
struct V_16 * V_16 ;
V_15 = F_21 ( L_2 , NULL ) ;
if ( V_15 == NULL )
return - V_17 ;
V_16 = F_22 ( L_3 , 0200 , V_15 ,
NULL , & V_18 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_22 ( L_4 , 0200 , V_15 ,
NULL , & V_20 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_23 ( L_5 , 0600 ,
V_15 , & V_11 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_23 ( L_6 , 0600 ,
V_15 , & V_21 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_23 ( L_7 , 0600 ,
V_15 , & V_22 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_24 ( L_8 , 0600 ,
V_15 , & V_23 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_24 ( L_9 , 0600 ,
V_15 , & V_24 ) ;
if ( ! V_16 )
goto V_19;
#ifdef F_25
V_16 = F_24 ( L_10 , 0600 ,
V_15 , & V_25 ) ;
if ( ! V_16 )
goto V_19;
#endif
return 0 ;
V_19:
F_18 () ;
return - V_17 ;
}
