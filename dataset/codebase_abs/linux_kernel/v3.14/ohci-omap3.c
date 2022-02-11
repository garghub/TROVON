static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
void T_1 * V_9 = NULL ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
if ( F_2 () )
return - V_14 ;
if ( ! V_4 -> V_15 ) {
F_3 ( V_4 , L_1 ) ;
return - V_14 ;
}
V_13 = F_4 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_3 ( V_4 , L_2 ) ;
return - V_14 ;
}
V_11 = F_5 ( V_2 , V_16 , 0 ) ;
if ( ! V_11 ) {
F_3 ( V_4 , L_3 ) ;
return - V_17 ;
}
V_9 = F_6 ( V_11 -> V_18 , F_7 ( V_11 ) ) ;
if ( ! V_9 ) {
F_3 ( V_4 , L_4 ) ;
return - V_17 ;
}
V_12 = F_8 ( V_4 , F_9 ( 32 ) ) ;
if ( V_12 )
goto V_19;
V_12 = - V_14 ;
V_8 = F_10 ( & V_20 , V_4 ,
F_11 ( V_4 ) ) ;
if ( ! V_8 ) {
F_3 ( V_4 , L_5 ) ;
goto V_19;
}
V_8 -> V_21 = V_11 -> V_18 ;
V_8 -> V_22 = F_7 ( V_11 ) ;
V_8 -> V_9 = V_9 ;
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
V_6 = F_14 ( V_8 ) ;
V_6 -> V_23 = V_24 ;
V_12 = F_15 ( V_8 , V_13 , 0 ) ;
if ( V_12 ) {
F_16 ( V_4 , L_6 , V_12 ) ;
goto V_25;
}
F_17 ( V_8 -> V_26 . V_27 ) ;
return 0 ;
V_25:
F_18 ( V_4 ) ;
F_19 ( V_8 ) ;
V_19:
F_20 ( V_9 ) ;
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_7 * V_8 = F_22 ( V_4 ) ;
F_20 ( V_8 -> V_9 ) ;
F_23 ( V_8 ) ;
F_18 ( V_4 ) ;
F_24 ( V_4 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
if ( F_2 () )
return - V_14 ;
F_26 ( L_7 V_28 L_8 , V_29 ) ;
F_27 ( & V_20 , NULL ) ;
return F_28 ( & V_30 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_30 ) ;
}
