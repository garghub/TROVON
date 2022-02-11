static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_4 , void * V_5 )
{
int V_6 ;
V_7 = F_3 ( V_8 ) ;
V_9 = F_3 ( V_3 ) ;
F_5 ( V_10 , V_11 ) ;
F_5 ( V_12 , V_11 ) ;
F_5 ( V_13 , V_11 ) ;
F_5 ( V_14 , V_11 ) ;
F_5 ( V_15 , V_11 ) ;
F_5 ( V_16 , V_11 ) ;
V_6 = F_6 ( V_7 , L_1 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_9 , L_2 ) ;
if ( V_6 )
goto V_17;
F_7 ( V_7 ) ;
F_7 ( V_9 ) ;
V_6 = F_8 ( F_9 ( F_3 ( V_8 ) ) ,
V_4 , V_18 ,
L_1 , V_5 ) ;
if ( V_6 )
goto V_19;
return 0 ;
V_19:
F_10 ( V_9 ) ;
V_17:
F_10 ( V_7 ) ;
return V_6 ;
}
static void F_11 ( struct V_1 * V_2 , void * V_5 )
{
F_10 ( V_7 ) ;
F_10 ( V_9 ) ;
F_12 ( F_9 ( F_3 ( V_8 ) ) , V_5 ) ;
}
static void T_2 F_13 ( void )
{
if ( F_6 ( V_20 , L_3 ) != 0 ) {
F_14 ( V_21 L_4 ) ;
return;
}
F_15 () ;
F_16 ( & V_22 ) ;
F_17 ( V_20 , 1 ) ;
}
void T_2 F_18 ( void )
{
F_19 ( V_23 ,
F_20 ( V_23 ) ,
L_5 ) ;
F_21 ( 0 , & V_24 ) ;
F_13 () ;
}
