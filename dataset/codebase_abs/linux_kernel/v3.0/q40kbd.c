static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_5 & F_3 ( V_6 ) )
F_4 ( V_7 , F_3 ( V_8 ) , 0 ) ;
F_5 ( - 1 , V_9 ) ;
F_6 ( & V_4 , V_3 ) ;
return V_10 ;
}
static void F_7 ( void )
{
int V_11 = 100 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
while ( V_11 -- && ( V_5 & F_3 ( V_6 ) ) )
F_3 ( V_8 ) ;
F_6 ( & V_4 , V_3 ) ;
}
static int F_8 ( struct V_12 * V_13 )
{
F_7 () ;
if ( F_9 ( V_14 , F_1 , 0 , L_1 , NULL ) ) {
F_10 ( V_15 L_2 , V_14 ) ;
return - V_16 ;
}
F_5 ( - 1 , V_9 ) ;
F_5 ( 1 , V_17 ) ;
return 0 ;
}
static void F_11 ( struct V_12 * V_13 )
{
F_5 ( 0 , V_17 ) ;
F_5 ( - 1 , V_9 ) ;
F_12 ( V_14 , NULL ) ;
F_7 () ;
}
static int T_2 F_13 ( struct V_18 * V_19 )
{
V_7 = F_14 ( sizeof( struct V_12 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
V_7 -> V_22 . type = V_23 ;
V_7 -> V_24 = F_8 ;
V_7 -> V_25 = F_11 ;
V_7 -> V_19 . V_26 = & V_19 -> V_19 ;
F_15 ( V_7 -> V_27 , L_3 , sizeof( V_7 -> V_27 ) ) ;
F_15 ( V_7 -> V_28 , L_4 , sizeof( V_7 -> V_28 ) ) ;
F_16 ( V_7 ) ;
F_10 ( V_29 L_5 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_18 * V_19 )
{
F_18 ( V_7 ) ;
return 0 ;
}
static int T_4 F_19 ( void )
{
int error ;
if ( ! V_30 )
return - V_31 ;
error = F_20 ( & V_32 ) ;
if ( error )
return error ;
V_33 = F_21 ( L_1 , - 1 ) ;
if ( ! V_33 )
goto V_34;
error = F_22 ( V_33 ) ;
if ( error )
goto V_35;
return 0 ;
V_35:
F_23 ( V_33 ) ;
V_34:
F_24 ( & V_32 ) ;
return error ;
}
static void T_5 F_25 ( void )
{
F_26 ( V_33 ) ;
F_24 ( & V_32 ) ;
}
