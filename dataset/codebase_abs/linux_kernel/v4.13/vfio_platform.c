static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ ) {
struct V_1 * V_10 = & V_6 -> V_1 [ V_8 ] ;
if ( F_2 ( V_10 ) & ( V_11 | V_12 ) ) {
if ( ! V_4 )
return V_10 ;
V_4 -- ;
}
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 , int V_8 )
{
struct V_5 * V_13 = (struct V_5 * ) V_3 -> V_7 ;
return F_4 ( V_13 , V_8 ) ;
}
static int F_5 ( struct V_5 * V_13 )
{
struct V_2 * V_3 ;
int V_14 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
return - V_16 ;
V_3 -> V_7 = ( void * ) V_13 ;
V_3 -> V_17 = V_13 -> V_17 ;
V_3 -> V_18 = V_19 ;
V_3 -> V_20 = F_1 ;
V_3 -> V_21 = F_3 ;
V_3 -> V_22 = V_23 ;
V_3 -> V_24 = V_24 ;
V_14 = F_7 ( V_3 , & V_13 -> V_6 ) ;
if ( V_14 )
F_8 ( V_3 ) ;
return V_14 ;
}
static int F_9 ( struct V_5 * V_13 )
{
struct V_2 * V_3 ;
V_3 = F_10 ( & V_13 -> V_6 ) ;
if ( V_3 ) {
F_8 ( V_3 ) ;
return 0 ;
}
return - V_25 ;
}
