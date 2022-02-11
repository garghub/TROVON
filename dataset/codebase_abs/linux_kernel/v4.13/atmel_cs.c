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
F_7 ( V_9 -> V_8 ) ;
}
static int F_8 ( void * V_10 )
{
struct V_1 * V_9 = (struct V_1 * ) V_10 ;
if ( F_9 ( V_9 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_11 )
{
if ( V_2 -> V_12 == 0 )
return - V_13 ;
return F_11 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
struct V_3 * V_5 ;
int V_14 ;
const struct V_15 * V_16 ;
V_5 = V_9 -> V_8 ;
V_16 = F_12 ( & V_9 -> V_5 ) ;
F_2 ( & V_9 -> V_5 , L_3 ) ;
V_9 -> V_17 |= V_18 | V_19 |
V_20 | V_21 ;
if ( F_13 ( V_9 , F_10 , NULL ) )
goto V_22;
if ( ! V_9 -> V_23 ) {
F_14 ( & V_9 -> V_5 , L_4 ) ;
goto V_22;
}
V_14 = F_15 ( V_9 ) ;
if ( V_14 )
goto V_22;
( (struct V_3 * ) V_9 -> V_8 ) -> V_24 =
F_16 ( V_9 -> V_23 ,
V_9 -> V_25 [ 0 ] -> V_26 ,
V_16 ? V_16 -> V_27 : V_28 ,
& V_9 -> V_5 ,
F_8 ,
V_9 ) ;
if ( ! ( (struct V_3 * ) V_9 -> V_8 ) -> V_24 )
goto V_22;
return 0 ;
V_22:
F_6 ( V_9 ) ;
return - V_29 ;
}
static void F_6 ( struct V_1 * V_9 )
{
struct V_30 * V_5 = ( (struct V_3 * ) V_9 -> V_8 ) -> V_24 ;
F_2 ( & V_9 -> V_5 , L_5 ) ;
if ( V_5 )
F_17 ( V_5 ) ;
( (struct V_3 * ) V_9 -> V_8 ) -> V_24 = NULL ;
F_18 ( V_9 ) ;
}
static int F_19 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_8 ;
F_20 ( V_4 -> V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_8 ;
F_22 ( V_4 -> V_24 ) ;
F_23 ( V_4 -> V_24 ) ;
return 0 ;
}
