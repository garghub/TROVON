int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 = NULL ;
F_2 ( V_11 > 0 ) ;
F_2 ( V_2 != NULL ) ;
F_2 ( V_6 != NULL ) ;
* V_2 = NULL ;
if ( ( 0 < V_6 -> V_12 ) &&
( V_6 -> V_12 <= V_13 ) )
V_7 = 0 ;
else if ( V_6 -> V_12 == 0 )
V_7 = - V_14 ;
else
V_7 = - V_15 ;
if ( V_6 -> V_16 == 0 )
V_7 = - V_14 ;
if ( ! V_7 ) {
V_7 = F_3 ( V_4 , & V_8 ) ;
if ( ! V_7 && V_8 != NULL )
V_7 = - V_17 ;
}
if ( ! V_7 ) {
struct V_18 * V_19 ;
F_4 ( V_4 , & V_19 ) ;
V_7 = (* V_19 -> F_1 ) ( & V_8 , V_4 ,
V_6 ) ;
if ( ! V_7 ) {
V_10 = (struct V_9 * ) V_8 ;
V_10 -> V_19 = V_19 ;
* V_2 = V_8 ;
}
}
F_5 ( V_7 || V_10 ) ;
return V_7 ;
}
int F_6 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
struct V_18 * V_19 ;
int V_7 ;
F_2 ( V_11 > 0 ) ;
if ( V_10 ) {
V_19 = V_10 -> V_19 ;
V_7 = (* V_19 -> F_6 ) ( V_8 ) ;
} else {
V_7 = - V_20 ;
}
return V_7 ;
}
void F_7 ( void )
{
F_2 ( V_11 > 0 ) ;
V_11 -- ;
F_5 ( V_11 >= 0 ) ;
}
bool F_8 ( void )
{
bool V_21 = true ;
F_2 ( V_11 >= 0 ) ;
if ( V_21 )
V_11 ++ ;
F_5 ( ( V_21 && ( V_11 > 0 ) ) || ( ! V_21 && ( V_11 >= 0 ) ) ) ;
return V_21 ;
}
