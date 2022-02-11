static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_4 , V_7 ) ;
return V_6 ;
}
static int F_3 ( struct V_8 * V_9 )
{
int V_6 = - V_10 ;
const struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_12 = V_9 -> V_12 ;
if ( ! V_12 ) {
F_4 ( & V_9 -> V_15 , L_1 ) ;
return - V_16 ;
}
V_14 = (struct V_13 * ) V_12 -> V_17 ;
V_18 = F_5 ( L_2 , V_14 -> V_19 ) ;
if ( ! V_18 )
goto V_20;
V_21 . V_22 = V_14 -> V_5 ;
V_23 . V_24 = V_14 -> V_25 ;
F_6 ( V_18 , & V_23 ) ;
V_6 = F_7 ( V_18 ) ;
if ( V_6 )
F_8 ( V_18 ) ;
V_20:
return V_6 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_10 ( V_18 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_26 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_26 ) ;
}
