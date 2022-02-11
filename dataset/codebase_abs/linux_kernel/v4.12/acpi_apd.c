static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = F_2 ( - V_6 ) ;
if ( V_4 -> V_7 ) {
V_5 = F_3 ( & V_2 -> V_8 -> V_9 ,
F_4 ( & V_2 -> V_8 -> V_9 ) ,
NULL , 0 , V_4 -> V_7 ) ;
F_5 ( V_5 , NULL , F_4 ( & V_2 -> V_8 -> V_9 ) ) ;
V_2 -> V_5 = V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_10 * V_8 ,
const struct V_11 * V_12 )
{
const struct V_3 * V_4 = ( void * ) V_12 -> V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_4 ) {
V_15 = F_7 ( V_8 , NULL ) ;
return F_8 ( V_15 ) ? F_9 ( V_15 ) : 1 ;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_19 ) {
V_16 = V_4 -> V_19 ( V_2 ) ;
if ( V_16 )
goto V_20;
}
V_8 -> V_13 = V_2 ;
V_15 = F_7 ( V_8 , V_4 -> V_21 ) ;
if ( ! F_8 ( V_15 ) )
return 1 ;
V_16 = F_9 ( V_15 ) ;
V_8 -> V_13 = NULL ;
V_20:
F_11 ( V_2 ) ;
return V_16 ;
}
void T_1 F_12 ( void )
{
F_13 ( & V_22 ) ;
}
