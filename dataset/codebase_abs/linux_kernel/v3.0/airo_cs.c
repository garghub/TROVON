static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( T_1 ) , V_5 ) ;
if ( ! V_3 ) {
F_4 ( V_6 L_2 ) ;
return - V_7 ;
}
V_2 -> V_8 = V_3 ;
return F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_9 )
{
F_2 ( & V_9 -> V_4 , L_3 ) ;
F_7 ( V_9 ) ;
if ( ( ( T_1 * ) V_9 -> V_8 ) -> V_10 ) {
F_8 ( ( ( T_1 * ) V_9 -> V_8 ) -> V_10 , 0 ) ;
}
( ( T_1 * ) V_9 -> V_8 ) -> V_10 = NULL ;
F_9 ( V_9 -> V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_11 )
{
if ( V_2 -> V_12 == 0 )
return - V_13 ;
return F_11 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_9 )
{
T_1 * V_4 ;
int V_14 ;
V_4 = V_9 -> V_8 ;
F_2 ( & V_9 -> V_4 , L_4 ) ;
V_9 -> V_15 |= V_16 | V_17 |
V_18 | V_19 ;
V_14 = F_12 ( V_9 , F_10 , NULL ) ;
if ( V_14 )
goto V_20;
if ( ! V_9 -> V_21 )
goto V_20;
V_14 = F_13 ( V_9 ) ;
if ( V_14 )
goto V_20;
( ( T_1 * ) V_9 -> V_8 ) -> V_10 =
F_14 ( V_9 -> V_21 ,
V_9 -> V_22 [ 0 ] -> V_23 , 1 , & V_9 -> V_4 ) ;
if ( ! ( ( T_1 * ) V_9 -> V_8 ) -> V_10 )
goto V_20;
return 0 ;
V_20:
F_7 ( V_9 ) ;
return - V_24 ;
}
static void F_7 ( struct V_1 * V_9 )
{
F_2 ( & V_9 -> V_4 , L_5 ) ;
F_15 ( V_9 ) ;
}
static int F_16 ( struct V_1 * V_9 )
{
T_1 * V_3 = V_9 -> V_8 ;
F_17 ( V_3 -> V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_9 )
{
T_1 * V_3 = V_9 -> V_8 ;
if ( V_9 -> V_25 ) {
F_19 ( V_3 -> V_10 ) ;
F_20 ( V_3 -> V_10 ) ;
}
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_26 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_26 ) ;
}
