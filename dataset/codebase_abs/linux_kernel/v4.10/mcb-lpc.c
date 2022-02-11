static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
int V_6 = 0 ;
V_5 = F_2 ( & V_2 -> V_7 , sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
V_5 -> V_10 = F_3 ( V_2 , V_11 , 0 ) ;
if ( ! V_5 -> V_10 ) {
F_4 ( & V_2 -> V_7 , L_1 ) ;
return - V_12 ;
}
V_4 = F_5 ( & V_2 -> V_7 , V_5 -> V_10 -> V_13 ,
F_6 ( V_5 -> V_10 ) ,
V_14 ) ;
if ( ! V_4 ) {
F_4 ( & V_2 -> V_7 , L_2 ) ;
return - V_15 ;
}
V_5 -> V_16 = F_7 ( & V_2 -> V_7 , V_5 -> V_10 -> V_13 ,
F_6 ( V_5 -> V_10 ) ) ;
if ( ! V_5 -> V_16 ) {
F_4 ( & V_2 -> V_7 , L_3 ) ;
return - V_9 ;
}
F_8 ( V_2 , V_5 ) ;
V_5 -> V_17 = F_9 ( & V_2 -> V_7 ) ;
if ( F_10 ( V_5 -> V_17 ) )
return F_11 ( V_5 -> V_17 ) ;
V_6 = F_12 ( V_5 -> V_17 , V_5 -> V_10 -> V_13 , V_5 -> V_16 ) ;
if ( V_6 < 0 ) {
F_13 ( V_5 -> V_17 ) ;
return V_6 ;
}
F_14 ( & V_2 -> V_7 , L_4 , V_6 ) ;
F_15 ( V_5 -> V_17 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_17 ( V_2 ) ;
F_13 ( V_5 -> V_17 ) ;
return 0 ;
}
static int F_18 ( const struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
int V_6 ;
V_21 = F_19 ( L_5 , - 1 ) ;
if ( ! V_21 )
return - V_9 ;
V_6 = F_20 ( V_21 , V_4 , 1 ) ;
if ( V_6 )
goto V_22;
V_6 = F_21 ( V_21 ) ;
if ( V_6 )
goto V_22;
return 0 ;
V_22:
F_22 ( V_21 ) ;
return V_6 ;
}
static int T_1 F_23 ( void )
{
if ( ! F_24 ( V_23 ) )
return - V_12 ;
return F_25 ( & V_24 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( V_21 ) ;
F_28 ( & V_24 ) ;
}
