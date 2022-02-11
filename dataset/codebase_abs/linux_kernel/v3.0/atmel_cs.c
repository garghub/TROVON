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
F_8 ( V_9 -> V_8 ) ;
}
static int F_9 ( void * V_10 )
{
struct V_1 * V_9 = (struct V_1 * ) V_10 ;
if ( F_10 ( V_9 ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_11 )
{
if ( V_2 -> V_12 == 0 )
return - V_13 ;
return F_12 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_9 )
{
T_1 * V_4 ;
int V_14 ;
const struct V_15 * V_16 ;
V_4 = V_9 -> V_8 ;
V_16 = F_13 ( & V_9 -> V_4 ) ;
F_2 ( & V_9 -> V_4 , L_4 ) ;
V_9 -> V_17 |= V_18 | V_19 |
V_20 | V_21 ;
if ( F_14 ( V_9 , F_11 , NULL ) )
goto V_22;
if ( ! V_9 -> V_23 ) {
F_15 ( & V_9 -> V_4 , L_5 ) ;
goto V_22;
}
V_14 = F_16 ( V_9 ) ;
if ( V_14 )
goto V_22;
( ( T_1 * ) V_9 -> V_8 ) -> V_24 =
F_17 ( V_9 -> V_23 ,
V_9 -> V_25 [ 0 ] -> V_26 ,
V_16 ? V_16 -> V_27 : V_28 ,
& V_9 -> V_4 ,
F_9 ,
V_9 ) ;
if ( ! ( ( T_1 * ) V_9 -> V_8 ) -> V_24 )
goto V_22;
return 0 ;
V_22:
F_7 ( V_9 ) ;
return - V_29 ;
}
static void F_7 ( struct V_1 * V_9 )
{
struct V_30 * V_4 = ( ( T_1 * ) V_9 -> V_8 ) -> V_24 ;
F_2 ( & V_9 -> V_4 , L_6 ) ;
if ( V_4 )
F_18 ( V_4 ) ;
( ( T_1 * ) V_9 -> V_8 ) -> V_24 = NULL ;
F_19 ( V_9 ) ;
}
static int F_20 ( struct V_1 * V_9 )
{
T_1 * V_3 = V_9 -> V_8 ;
F_21 ( V_3 -> V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_9 )
{
T_1 * V_3 = V_9 -> V_8 ;
F_23 ( V_3 -> V_24 ) ;
F_24 ( V_3 -> V_24 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_31 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_31 ) ;
}
