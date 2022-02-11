static unsigned long F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_7 ;
V_6 -> V_8 -> V_9 ( V_6 , & V_7 ) ;
if ( V_4 == V_10 ) {
V_7 = V_7 < V_2 -> V_11 ?
( V_7 + 1 ) : V_2 -> V_11 ;
} else if ( V_4 == V_12 ) {
V_7 = V_7 > V_2 -> V_13 ?
( V_7 - 1 ) : V_2 -> V_13 ;
}
return V_7 ;
}
static void F_2 ( struct V_14 * V_15 ,
enum V_16 type , int V_17 )
{
if ( type == V_18 || type == V_19 )
V_15 -> V_20 += V_17 ;
}
static void F_3 ( struct V_14 * V_15 ,
int V_21 , enum V_16 V_22 ,
enum V_3 V_4 )
{
struct V_1 * V_2 ;
F_4 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_21 != V_21 )
continue;
V_2 -> V_23 = F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_23 == V_24 )
F_2 ( V_15 , V_22 , 1 ) ;
V_2 -> V_6 -> V_25 = false ;
}
}
static void F_5 ( struct V_14 * V_15 ,
int V_21 , enum V_16 V_22 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
F_4 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_21 != V_21 ||
V_2 -> V_23 == V_24 )
continue;
V_6 = V_2 -> V_6 ;
V_6 -> V_8 -> V_9 ( V_6 , & V_7 ) ;
V_2 -> V_23 = V_7 > V_2 -> V_13 ?
( V_7 - 1 ) : V_24 ;
if ( V_2 -> V_23 == V_24 )
F_2 ( V_15 , V_22 , - 1 ) ;
V_6 -> V_25 = false ;
}
}
static void F_6 ( struct V_14 * V_15 , int V_21 )
{
long V_26 ;
enum V_16 V_22 ;
enum V_3 V_4 ;
if ( V_21 == V_19 ) {
V_26 = V_15 -> V_27 ;
V_22 = V_19 ;
} else {
V_15 -> V_8 -> V_28 ( V_15 , V_21 , & V_26 ) ;
V_15 -> V_8 -> V_29 ( V_15 , V_21 , & V_22 ) ;
}
V_4 = F_7 ( V_15 , V_21 ) ;
F_8 ( & V_15 -> V_30 ) ;
if ( V_15 -> V_31 >= V_26 )
F_3 ( V_15 , V_21 , V_22 , V_4 ) ;
else
F_5 ( V_15 , V_21 , V_22 ) ;
F_9 ( & V_15 -> V_30 ) ;
}
static int F_10 ( struct V_14 * V_15 , int V_21 )
{
struct V_1 * V_2 ;
F_6 ( V_15 , V_21 ) ;
if ( V_15 -> V_27 )
F_6 ( V_15 , V_19 ) ;
F_8 ( & V_15 -> V_30 ) ;
F_4 (instance, &tz->thermal_instances, tz_node)
F_11 ( V_2 -> V_6 ) ;
F_9 ( & V_15 -> V_30 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_32 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_32 ) ;
}
