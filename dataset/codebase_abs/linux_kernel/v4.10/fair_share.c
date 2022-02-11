static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
enum V_5 V_6 ;
if ( V_2 -> V_7 == 0 || ! V_2 -> V_8 -> V_9 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_2 -> V_8 -> V_9 ( V_2 , V_3 , & V_4 ) ;
if ( V_2 -> V_10 < V_4 )
break;
}
if ( V_3 > 0 ) {
V_2 -> V_8 -> V_11 ( V_2 , V_3 - 1 , & V_6 ) ;
F_2 ( V_2 , V_3 - 1 , V_6 ) ;
}
return V_3 ;
}
static long F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_14 , int V_15 )
{
unsigned long V_16 ;
V_13 -> V_8 -> V_17 ( V_13 , & V_16 ) ;
return ( long ) ( V_14 * V_15 * V_16 ) / ( 100 * V_2 -> V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_18 )
{
struct V_19 * V_20 ;
int V_21 = 0 ;
int V_22 = 0 ;
int V_23 = F_1 ( V_2 ) ;
F_5 (instance, &tz->thermal_instances, tz_node) {
if ( V_20 -> V_18 != V_18 )
continue;
V_21 += V_20 -> V_24 ;
V_22 ++ ;
}
F_5 (instance, &tz->thermal_instances, tz_node) {
int V_14 ;
struct V_12 * V_13 = V_20 -> V_13 ;
if ( V_20 -> V_18 != V_18 )
continue;
if ( ! V_21 )
V_14 = 100 / V_22 ;
else
V_14 = ( V_20 -> V_24 * 100 ) / V_21 ;
V_20 -> V_25 = F_3 ( V_2 , V_13 , V_14 ,
V_23 ) ;
F_6 ( & V_20 -> V_13 -> V_26 ) ;
V_20 -> V_13 -> V_27 = false ;
F_7 ( & V_20 -> V_13 -> V_26 ) ;
F_8 ( V_13 ) ;
}
return 0 ;
}
int F_9 ( void )
{
return F_10 ( & V_28 ) ;
}
void F_11 ( void )
{
F_12 ( & V_28 ) ;
}
