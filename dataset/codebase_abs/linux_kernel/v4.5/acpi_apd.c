static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( - V_6 ) ;
if ( V_4 -> V_7 ) {
V_5 = F_3 ( & V_2 -> V_8 -> V_9 ,
F_4 ( & V_2 -> V_8 -> V_9 ) ,
NULL , V_10 ,
V_4 -> V_7 ) ;
F_5 ( V_5 , NULL , F_4 ( & V_2 -> V_8 -> V_9 ) ) ;
V_2 -> V_5 = V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_8 ,
const struct V_12 * V_13 )
{
const struct V_3 * V_4 = ( void * ) V_13 -> V_14 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_17 ;
if ( ! V_4 ) {
V_16 = F_7 ( V_8 ) ;
return F_8 ( V_16 ) ? F_9 ( V_16 ) : 1 ;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_20 ) {
V_17 = V_4 -> V_20 ( V_2 ) ;
if ( V_17 )
goto V_21;
}
V_8 -> V_14 = V_2 ;
V_16 = F_7 ( V_8 ) ;
if ( ! F_8 ( V_16 ) )
return 1 ;
V_17 = F_9 ( V_16 ) ;
V_8 -> V_14 = NULL ;
V_21:
F_11 ( V_2 ) ;
return V_17 ;
}
void T_1 F_12 ( void )
{
F_13 ( & V_22 ) ;
}
