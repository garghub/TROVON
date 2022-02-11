static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 * V_4 ;
F_4 ( 0 , L_1 ) ;
V_4 = F_5 ( sizeof( T_1 ) , V_5 ) ;
if ( ! V_4 ) {
return - V_6 ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_7 = V_4 ;
V_4 -> V_8 = NULL ;
V_2 -> V_9 |= V_10 | V_11 ;
return F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_8 = ( ( T_1 * ) V_2 -> V_7 ) -> V_8 ;
F_4 ( 0 , L_2 , V_2 ) ;
if ( V_2 == NULL ) {
F_4 ( 0 , L_3 ) ;
return;
}
if ( V_8 ) {
F_8 ( V_8 ) ;
}
F_9 ( V_2 ) ;
F_10 ( V_8 ) ;
}
int F_11 ( struct V_1 * V_2 , void * V_13 )
{
return F_12 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
F_13 ( & V_2 -> V_8 , L_4 , V_2 ) ;
V_14 = F_14 ( V_2 , F_11 , NULL ) ;
if ( V_14 ) {
F_15 ( V_15 L_5 ) ;
return - V_16 ;
}
V_14 = F_16 ( V_2 ) ;
if ( V_14 ) {
F_15 ( V_15 L_6 ) ;
goto V_17;
}
( ( T_1 * ) V_2 -> V_7 ) -> V_8 = F_17 ( V_2 ,
& F_1 ) ;
if ( ( ( T_1 * ) V_2 -> V_7 ) -> V_8 == NULL ) {
F_15 ( V_15 L_7 ) ;
goto V_17;
}
return 0 ;
V_17:
F_18 ( V_2 ) ;
return - V_16 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_4 ( 0 , L_8 , V_2 ) ;
F_19 ( ( T_1 * ) V_2 -> V_7 ) ;
F_9 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_8 = ( ( T_1 * ) V_2 -> V_7 ) -> V_8 ;
F_4 ( 1 , L_9 , V_18 ) ;
if ( V_2 -> V_19 )
F_21 ( V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_2 F_23 ( void )
{
F_4 ( 0 , L_10 ) ;
return F_24 ( & V_20 ) ;
}
static void T_3 F_25 ( void )
{
F_4 ( 0 , L_11 ) ;
F_26 ( & V_20 ) ;
}
