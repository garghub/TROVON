static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( T_1 ) , V_5 ) ;
if ( ! V_3 )
return - V_6 ;
V_2 -> V_7 = V_3 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_8 )
{
F_2 ( & V_8 -> V_4 , L_2 ) ;
F_6 ( V_8 ) ;
if ( ( ( T_1 * ) V_8 -> V_7 ) -> V_9 ) {
F_7 ( ( ( T_1 * ) V_8 -> V_7 ) -> V_9 , 0 ) ;
}
( ( T_1 * ) V_8 -> V_7 ) -> V_9 = NULL ;
F_8 ( V_8 -> V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_10 )
{
if ( V_2 -> V_11 == 0 )
return - V_12 ;
return F_10 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_8 )
{
T_1 * V_4 ;
int V_13 ;
V_4 = V_8 -> V_7 ;
F_2 ( & V_8 -> V_4 , L_3 ) ;
V_8 -> V_14 |= V_15 | V_16 |
V_17 | V_18 ;
V_13 = F_11 ( V_8 , F_9 , NULL ) ;
if ( V_13 )
goto V_19;
if ( ! V_8 -> V_20 )
goto V_19;
V_13 = F_12 ( V_8 ) ;
if ( V_13 )
goto V_19;
( ( T_1 * ) V_8 -> V_7 ) -> V_9 =
F_13 ( V_8 -> V_20 ,
V_8 -> V_21 [ 0 ] -> V_22 , 1 , & V_8 -> V_4 ) ;
if ( ! ( ( T_1 * ) V_8 -> V_7 ) -> V_9 )
goto V_19;
return 0 ;
V_19:
F_6 ( V_8 ) ;
return - V_23 ;
}
static void F_6 ( struct V_1 * V_8 )
{
F_2 ( & V_8 -> V_4 , L_4 ) ;
F_14 ( V_8 ) ;
}
static int F_15 ( struct V_1 * V_8 )
{
T_1 * V_3 = V_8 -> V_7 ;
F_16 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_8 )
{
T_1 * V_3 = V_8 -> V_7 ;
if ( V_8 -> V_24 ) {
F_18 ( V_3 -> V_9 ) ;
F_19 ( V_3 -> V_9 ) ;
}
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_25 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_25 ) ;
}
