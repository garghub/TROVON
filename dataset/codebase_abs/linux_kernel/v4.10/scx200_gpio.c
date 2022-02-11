static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned V_3 = F_2 ( V_1 ) ;
V_2 -> V_4 = & V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
return F_3 ( V_1 , V_2 ) ;
}
static int F_4 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_8 ;
T_2 V_9 ;
if ( ! F_6 () ) {
F_7 (KERN_ERR DRVNAME L_1 ) ;
return - V_10 ;
}
V_11 = F_8 ( V_12 , 0 ) ;
if ( ! V_11 )
return - V_13 ;
V_8 = F_9 ( V_11 ) ;
if ( V_8 )
goto V_14;
V_5 . V_15 = & V_11 -> V_15 ;
if ( V_16 ) {
V_9 = F_10 ( V_16 , 0 ) ;
V_8 = F_11 ( V_9 , V_6 , L_2 ) ;
} else {
V_8 = F_12 ( & V_9 , 0 , V_6 , L_2 ) ;
V_16 = F_13 ( V_9 ) ;
}
if ( V_8 < 0 ) {
F_14 ( & V_11 -> V_15 , L_3 , V_8 ) ;
goto V_17;
}
F_15 ( & V_18 , & V_19 ) ;
F_16 ( & V_18 , V_9 , V_6 ) ;
return 0 ;
V_17:
F_17 ( V_11 ) ;
V_14:
F_18 ( V_11 ) ;
return V_8 ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_18 ) ;
F_21 ( F_10 ( V_16 , 0 ) , V_6 ) ;
F_22 ( V_11 ) ;
}
