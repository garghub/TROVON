static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_3 ( V_2 , L_1 ) ) {
V_7 = - V_8 ;
goto V_9;
}
V_6 = F_4 ( sizeof( struct V_5 ) , V_10 ) ;
if ( ! V_6 ) {
V_7 = - V_11 ;
goto V_12;
}
V_6 -> V_13 = V_2 -> V_13 ;
V_6 -> V_14 = V_15 ;
V_6 -> V_16 = V_2 -> V_16 ;
V_6 -> V_17 = & V_18 ;
V_6 -> V_19 = F_5 ( V_2 , V_20 , V_21 ) ;
if ( ! V_6 -> V_19 ) {
V_7 = - V_22 ;
goto V_23;
}
F_6 ( V_2 , V_6 ) ;
V_7 = F_7 ( V_6 ) ;
if ( V_7 )
goto V_24;
return V_7 ;
V_24:
F_8 ( V_2 , V_6 -> V_19 ) ;
V_23:
F_9 ( V_6 ) ;
V_12:
F_10 ( V_2 ) ;
V_9:
F_11 ( V_2 ) ;
return V_7 ;
}
static void T_2 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
F_14 ( V_6 ) ;
F_6 ( V_2 , NULL ) ;
F_10 ( V_2 ) ;
F_8 ( V_2 , V_6 -> V_19 ) ;
F_9 ( V_6 ) ;
F_11 ( V_2 ) ;
}
static int F_15 ( struct V_25 * V_16 )
{
int V_7 ;
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
V_7 = F_17 ( V_6 ) ;
return V_7 ;
}
static int F_18 ( struct V_25 * V_16 )
{
int V_7 ;
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
V_7 = F_19 ( V_6 ) ;
return V_7 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_26 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_26 ) ;
}
