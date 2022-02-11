static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_4 )
{
F_5 ( V_5 , V_4 ) ;
F_5 ( V_6 , V_4 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_3 ( V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_9 ( V_8 , L_1 ) ;
if ( V_7 )
goto V_9;
V_7 = F_10 ( V_8 ) ;
if ( V_7 )
goto V_10;
return 0 ;
V_10:
F_11 ( V_8 ) ;
V_9:
return V_7 ;
}
static int F_12 ( void )
{
return F_13 ( V_8 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( V_8 ) ;
}
static void T_1 F_15 ( void )
{
if ( ! F_9 ( V_11 , L_2 ) ) {
F_16 ( V_11 , 1 ) ;
F_11 ( V_11 ) ;
}
}
static void T_1 F_17 ( void )
{
F_18 ( F_3 ( V_12 ) ) ;
F_19 ( NULL ) ;
F_20 ( NULL ) ;
F_21 ( NULL ) ;
F_22 ( NULL , & V_13 ) ;
F_23 ( & V_14 ) ;
F_15 () ;
F_24 ( & V_15 ) ;
F_25 ( & V_16 ) ;
F_26 ( V_17 , F_27 ( V_17 ) ) ;
}
