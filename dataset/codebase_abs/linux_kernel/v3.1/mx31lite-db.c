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
F_5 ( V_10 ,
V_11 | V_12 | V_13 ) ;
F_5 ( V_14 ,
V_11 | V_12 | V_13 ) ;
F_5 ( V_15 ,
V_11 | V_12 | V_13 ) ;
F_5 ( V_16 ,
V_11 | V_12 | V_13 ) ;
F_5 ( V_17 ,
V_11 | V_12 | V_13 ) ;
F_5 ( V_18 , V_11 ) ;
V_6 = F_6 ( V_7 , L_1 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_9 , L_2 ) ;
if ( V_6 )
goto V_19;
F_7 ( V_7 ) ;
F_7 ( V_9 ) ;
V_6 = F_8 ( F_9 ( V_8 ) , V_4 ,
V_20 | V_21 ,
L_1 , V_5 ) ;
if ( V_6 )
goto V_22;
return 0 ;
V_22:
F_10 ( V_9 ) ;
V_19:
F_10 ( V_7 ) ;
return V_6 ;
}
static void F_11 ( struct V_1 * V_2 , void * V_5 )
{
F_10 ( V_7 ) ;
F_10 ( V_9 ) ;
F_12 ( F_9 ( V_8 ) , V_5 ) ;
}
void T_2 F_13 ( void )
{
F_14 ( V_23 ,
F_15 ( V_23 ) ,
L_3 ) ;
F_16 ( & V_24 ) ;
F_17 ( 0 , & V_25 ) ;
F_18 ( & V_26 ) ;
F_19 ( - 1 , & V_27 ) ;
F_20 ( NULL ) ;
F_21 ( NULL ) ;
}
