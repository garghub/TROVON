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
F_7 ( V_8 -> V_7 ) ;
}
static int F_8 ( void * V_9 )
{
struct V_1 * V_8 = (struct V_1 * ) V_9 ;
if ( F_9 ( V_8 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_10 )
{
if ( V_2 -> V_11 == 0 )
return - V_12 ;
return F_11 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_8 )
{
T_1 * V_4 ;
int V_13 ;
const struct V_14 * V_15 ;
V_4 = V_8 -> V_7 ;
V_15 = F_12 ( & V_8 -> V_4 ) ;
F_2 ( & V_8 -> V_4 , L_3 ) ;
V_8 -> V_16 |= V_17 | V_18 |
V_19 | V_20 ;
if ( F_13 ( V_8 , F_10 , NULL ) )
goto V_21;
if ( ! V_8 -> V_22 ) {
F_14 ( & V_8 -> V_4 , L_4 ) ;
goto V_21;
}
V_13 = F_15 ( V_8 ) ;
if ( V_13 )
goto V_21;
( ( T_1 * ) V_8 -> V_7 ) -> V_23 =
F_16 ( V_8 -> V_22 ,
V_8 -> V_24 [ 0 ] -> V_25 ,
V_15 ? V_15 -> V_26 : V_27 ,
& V_8 -> V_4 ,
F_8 ,
V_8 ) ;
if ( ! ( ( T_1 * ) V_8 -> V_7 ) -> V_23 )
goto V_21;
return 0 ;
V_21:
F_6 ( V_8 ) ;
return - V_28 ;
}
static void F_6 ( struct V_1 * V_8 )
{
struct V_29 * V_4 = ( ( T_1 * ) V_8 -> V_7 ) -> V_23 ;
F_2 ( & V_8 -> V_4 , L_5 ) ;
if ( V_4 )
F_17 ( V_4 ) ;
( ( T_1 * ) V_8 -> V_7 ) -> V_23 = NULL ;
F_18 ( V_8 ) ;
}
static int F_19 ( struct V_1 * V_8 )
{
T_1 * V_3 = V_8 -> V_7 ;
F_20 ( V_3 -> V_23 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_8 )
{
T_1 * V_3 = V_8 -> V_7 ;
F_22 ( V_3 -> V_23 ) ;
F_23 ( V_3 -> V_23 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_30 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_30 ) ;
}
