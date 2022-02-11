static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return - V_6 ;
V_3 -> V_7 = V_2 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 |= V_10 | V_11 ;
V_2 -> V_12 = V_13 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 , L_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_8 ) ;
}
static int F_8 ( struct V_1 * V_7 , void * V_14 )
{
V_7 -> V_15 = 10 ;
V_7 -> V_16 [ 0 ] -> V_17 = 0x10 ;
V_7 -> V_16 [ 0 ] -> V_18 &= ~ V_19 ;
V_7 -> V_16 [ 0 ] -> V_18 |= V_20 ;
return F_9 ( V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
int V_21 ;
char V_22 [ 22 ] ;
struct V_23 * V_24 ;
F_2 ( & V_2 -> V_4 , L_3 ) ;
V_21 = F_10 ( V_2 , F_8 , NULL ) ;
if ( V_21 )
goto V_25;
if ( ! V_2 -> V_26 )
goto V_25;
V_21 = F_11 ( V_2 ) ;
if ( V_21 )
goto V_25;
F_12 ( V_2 -> V_16 [ 0 ] -> V_27 , F_13 ( V_2 -> V_16 [ 0 ] ) ) ;
sprintf ( V_22 , L_4 , ( unsigned int ) V_2 -> V_16 [ 0 ] -> V_27 , V_2 -> V_26 ) ;
F_14 ( V_22 ) ;
V_24 = F_15 ( & V_28 ) ;
if ( ! V_24 ) {
F_16 ( V_29 L_5 ) ;
goto V_25;
}
if ( F_17 ( V_24 , NULL ) )
goto V_25;
F_18 ( V_24 ) ;
V_3 -> V_24 = V_24 ;
return 0 ;
V_25:
F_6 ( V_2 ) ;
return - V_30 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_4 , L_6 ) ;
F_19 ( V_3 -> V_24 ) ;
F_20 ( V_2 ) ;
F_21 ( V_3 -> V_24 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_23 ( NULL ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_31 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_31 ) ;
}
