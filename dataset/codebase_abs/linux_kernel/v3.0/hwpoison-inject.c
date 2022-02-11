static int F_1 ( void * V_1 , T_1 V_2 )
{
unsigned long V_3 = V_2 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
int V_7 ;
if ( ! F_2 ( V_8 ) )
return - V_9 ;
if ( ! V_10 )
goto V_11;
if ( ! F_3 ( V_3 ) )
return - V_12 ;
V_5 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_5 ) ;
if ( ! F_6 ( V_6 ) )
return 0 ;
if ( ! F_7 ( V_5 ) && ! F_8 ( V_5 ) )
F_9 ( V_5 , 0 ) ;
if ( ! F_7 ( V_5 ) && ! F_8 ( V_5 ) )
return 0 ;
F_10 ( V_6 ) ;
V_7 = F_11 ( V_6 ) ;
F_12 ( V_6 ) ;
if ( V_7 )
return 0 ;
V_11:
F_13 ( V_13 L_1 , V_3 ) ;
return F_14 ( V_3 , 18 , V_14 ) ;
}
static int F_15 ( void * V_1 , T_1 V_2 )
{
if ( ! F_2 ( V_8 ) )
return - V_9 ;
return F_16 ( V_2 ) ;
}
static void F_17 ( void )
{
if ( V_15 )
F_18 ( V_15 ) ;
}
static int F_19 ( void )
{
struct V_16 * V_16 ;
V_15 = F_20 ( L_2 , NULL ) ;
if ( V_15 == NULL )
return - V_17 ;
V_16 = F_21 ( L_3 , 0600 , V_15 ,
NULL , & V_18 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_21 ( L_4 , 0600 , V_15 ,
NULL , & V_20 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_22 ( L_5 , 0600 ,
V_15 , & V_10 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_22 ( L_6 , 0600 ,
V_15 , & V_21 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_22 ( L_7 , 0600 ,
V_15 , & V_22 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_23 ( L_8 , 0600 ,
V_15 , & V_23 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_23 ( L_9 , 0600 ,
V_15 , & V_24 ) ;
if ( ! V_16 )
goto V_19;
#ifdef F_24
V_16 = F_23 ( L_10 , 0600 ,
V_15 , & V_25 ) ;
if ( ! V_16 )
goto V_19;
#endif
return 0 ;
V_19:
F_17 () ;
return - V_17 ;
}
