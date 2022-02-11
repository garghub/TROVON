static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_4 = NULL ;
V_2 -> V_5 |= V_6 | V_7 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_4 ;
if ( V_9 )
F_6 ( V_9 ) ;
F_7 ( V_2 ) ;
F_8 ( V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_10 )
{
return F_10 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 ;
F_11 ( & V_2 -> V_9 , L_1 , V_2 ) ;
V_11 = F_12 ( V_2 , F_9 , NULL ) ;
if ( V_11 ) {
F_13 ( & V_2 -> V_9 , L_2 ) ;
return - V_12 ;
}
V_11 = F_14 ( V_2 ) ;
if ( V_11 ) {
F_13 ( & V_2 -> V_9 , L_3 ) ;
goto V_13;
}
V_2 -> V_4 = F_15 ( V_2 , & F_1 ) ;
if ( ! V_2 -> V_4 ) {
F_13 ( & V_2 -> V_9 , L_4 ) ;
goto V_13;
}
return 0 ;
V_13:
F_7 ( V_2 ) ;
return - V_12 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_4 ;
if ( V_2 -> V_14 )
F_17 ( V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_15 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_15 ) ;
}
