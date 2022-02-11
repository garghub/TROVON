static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
if ( V_4 == 0 )
return & V_6 -> V_8 ;
return NULL ;
}
static int F_2 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
int V_9 = 0 ;
if ( V_4 < V_10 )
V_9 = V_6 -> V_11 [ V_4 ] ;
return V_9 ? V_9 : - V_12 ;
}
static int F_3 ( struct V_5 * V_6 , const struct V_13 * V_14 )
{
struct V_2 * V_3 ;
int V_9 ;
V_3 = F_4 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
return - V_16 ;
V_3 -> V_17 = F_5 ( V_15 , L_1 , V_6 -> V_18 ) ;
if ( ! V_3 -> V_17 ) {
F_6 ( V_3 ) ;
return - V_16 ;
}
V_3 -> V_7 = ( void * ) V_6 ;
V_3 -> V_19 = V_20 ;
V_3 -> V_21 = F_1 ;
V_3 -> V_22 = F_2 ;
V_9 = F_7 ( V_3 , & V_6 -> V_23 ) ;
if ( V_9 ) {
F_6 ( V_3 -> V_17 ) ;
F_6 ( V_3 ) ;
}
return V_9 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_9 ( & V_6 -> V_23 ) ;
if ( V_3 ) {
F_6 ( V_3 -> V_17 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
return - V_24 ;
}
