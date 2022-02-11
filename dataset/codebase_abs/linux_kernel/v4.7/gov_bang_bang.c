static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 ;
V_2 -> V_8 -> V_9 ( V_2 , V_3 , & V_4 ) ;
if ( ! V_2 -> V_8 -> V_10 ) {
F_2 ( L_1
L_2 , V_2 -> type ) ;
V_5 = 0 ;
} else
V_2 -> V_8 -> V_10 ( V_2 , V_3 , & V_5 ) ;
F_3 ( & V_2 -> V_11 , L_3 ,
V_3 , V_4 , V_2 -> V_12 ,
V_5 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_5 (instance, &tz->thermal_instances, tz_node) {
if ( V_7 -> V_3 != V_3 )
continue;
if ( V_7 -> V_14 == V_15 )
V_7 -> V_14 = 0 ;
if ( V_7 -> V_14 != 0 && V_7 -> V_14 != 1 ) {
F_6 ( L_4 ,
V_7 -> V_16 , V_7 -> V_14 ) ;
V_7 -> V_14 = 1 ;
}
if ( V_7 -> V_14 == 0 && V_2 -> V_12 >= V_4 )
V_7 -> V_14 = 1 ;
else if ( V_7 -> V_14 == 1 &&
V_2 -> V_12 < V_4 - V_5 )
V_7 -> V_14 = 0 ;
F_3 ( & V_7 -> V_17 -> V_11 , L_5 ,
( int ) V_7 -> V_14 ) ;
V_7 -> V_17 -> V_18 = false ;
}
F_7 ( & V_2 -> V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_6 * V_7 ;
F_1 ( V_2 , V_3 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_5 (instance, &tz->thermal_instances, tz_node)
F_9 ( V_7 -> V_17 ) ;
F_7 ( & V_2 -> V_13 ) ;
return 0 ;
}
int F_10 ( void )
{
return F_11 ( & V_19 ) ;
}
void F_12 ( void )
{
F_13 ( & V_19 ) ;
}
