static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 , L_1 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
V_2 -> V_8 = V_4 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_9 )
{
F_2 ( & V_9 -> V_5 , L_2 ) ;
F_6 ( V_9 ) ;
if ( ( (struct V_3 * ) V_9 -> V_8 ) -> V_10 ) {
F_7 ( ( (struct V_3 * ) V_9 -> V_8 ) -> V_10 ,
0 ) ;
}
( (struct V_3 * ) V_9 -> V_8 ) -> V_10 = NULL ;
F_8 ( V_9 -> V_8 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_11 )
{
if ( V_2 -> V_12 == 0 )
return - V_13 ;
return F_10 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
struct V_3 * V_5 ;
int V_14 ;
V_5 = V_9 -> V_8 ;
F_2 ( & V_9 -> V_5 , L_3 ) ;
V_9 -> V_15 |= V_16 | V_17 |
V_18 | V_19 ;
V_14 = F_11 ( V_9 , F_9 , NULL ) ;
if ( V_14 )
goto V_20;
if ( ! V_9 -> V_21 )
goto V_20;
V_14 = F_12 ( V_9 ) ;
if ( V_14 )
goto V_20;
( (struct V_3 * ) V_9 -> V_8 ) -> V_10 =
F_13 ( V_9 -> V_21 ,
V_9 -> V_22 [ 0 ] -> V_23 , 1 , & V_9 -> V_5 ) ;
if ( ! ( (struct V_3 * ) V_9 -> V_8 ) -> V_10 )
goto V_20;
return 0 ;
V_20:
F_6 ( V_9 ) ;
return - V_24 ;
}
static void F_6 ( struct V_1 * V_9 )
{
F_2 ( & V_9 -> V_5 , L_4 ) ;
F_14 ( V_9 ) ;
}
static int F_15 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_8 ;
F_16 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_8 ;
if ( V_9 -> V_25 ) {
F_18 ( V_4 -> V_10 ) ;
F_19 ( V_4 -> V_10 ) ;
}
return 0 ;
}
