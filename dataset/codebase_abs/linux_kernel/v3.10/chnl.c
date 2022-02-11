int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 = NULL ;
* V_2 = NULL ;
if ( ( 0 < V_6 -> V_11 ) &&
( V_6 -> V_11 <= V_12 ) )
V_7 = 0 ;
else if ( V_6 -> V_11 == 0 )
V_7 = - V_13 ;
else
V_7 = - V_14 ;
if ( V_6 -> V_15 == 0 )
V_7 = - V_13 ;
if ( ! V_7 ) {
V_7 = F_2 ( V_4 , & V_8 ) ;
if ( ! V_7 && V_8 != NULL )
V_7 = - V_16 ;
}
if ( ! V_7 ) {
struct V_17 * V_18 ;
F_3 ( V_4 , & V_18 ) ;
V_7 = (* V_18 -> F_1 ) ( & V_8 , V_4 ,
V_6 ) ;
if ( ! V_7 ) {
V_10 = (struct V_9 * ) V_8 ;
V_10 -> V_18 = V_18 ;
* V_2 = V_8 ;
}
}
return V_7 ;
}
int F_4 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
struct V_17 * V_18 ;
int V_7 ;
if ( V_10 ) {
V_18 = V_10 -> V_18 ;
V_7 = (* V_18 -> F_4 ) ( V_8 ) ;
} else {
V_7 = - V_19 ;
}
return V_7 ;
}
