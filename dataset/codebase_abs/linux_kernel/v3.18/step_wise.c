static unsigned long F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_8 ;
unsigned long V_9 ;
V_7 -> V_10 -> V_11 ( V_7 , & V_8 ) ;
V_9 = V_2 -> V_12 ;
F_2 ( & V_7 -> V_13 , L_1 , V_8 ) ;
switch ( V_4 ) {
case V_14 :
if ( V_5 ) {
V_9 = V_8 < V_2 -> V_15 ?
( V_8 + 1 ) : V_2 -> V_15 ;
if ( V_9 < V_2 -> V_16 )
V_9 = V_2 -> V_16 ;
}
break;
case V_17 :
if ( V_5 )
V_9 = V_2 -> V_15 ;
break;
case V_18 :
if ( V_8 <= V_2 -> V_16 ) {
if ( ! V_5 )
V_9 = V_19 ;
} else {
V_9 = V_8 - 1 ;
if ( V_9 > V_2 -> V_15 )
V_9 = V_2 -> V_15 ;
}
break;
case V_20 :
if ( V_8 == V_2 -> V_16 ) {
if ( ! V_5 )
V_9 = V_19 ;
} else
V_9 = V_2 -> V_16 ;
break;
default:
break;
}
return V_9 ;
}
static void F_3 ( struct V_21 * V_22 ,
enum V_23 type , int V_24 )
{
if ( type == V_25 || type == V_26 )
V_22 -> V_27 += V_24 ;
}
static void F_4 ( struct V_21 * V_22 , int V_28 )
{
long V_29 ;
enum V_23 V_30 ;
enum V_3 V_4 ;
struct V_1 * V_2 ;
bool V_5 = false ;
int V_31 ;
if ( V_28 == V_26 ) {
V_29 = V_22 -> V_32 ;
V_30 = V_26 ;
} else {
V_22 -> V_10 -> V_33 ( V_22 , V_28 , & V_29 ) ;
V_22 -> V_10 -> V_34 ( V_22 , V_28 , & V_30 ) ;
}
V_4 = F_5 ( V_22 , V_28 ) ;
if ( V_22 -> V_35 >= V_29 ) {
V_5 = true ;
F_6 ( V_22 , V_28 , V_30 ) ;
}
F_2 ( & V_22 -> V_13 , L_2 ,
V_28 , V_30 , V_29 , V_4 , V_5 ) ;
F_7 ( & V_22 -> V_36 ) ;
F_8 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_28 != V_28 )
continue;
V_31 = V_2 -> V_12 ;
V_2 -> V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
F_2 ( & V_2 -> V_7 -> V_13 , L_3 ,
V_31 , ( int ) V_2 -> V_12 ) ;
if ( V_31 == V_2 -> V_12 )
continue;
if ( V_31 == V_19 &&
V_2 -> V_12 != V_19 )
F_3 ( V_22 , V_30 , 1 ) ;
else if ( V_31 != V_19 &&
V_2 -> V_12 == V_19 )
F_3 ( V_22 , V_30 , - 1 ) ;
V_2 -> V_7 -> V_37 = false ;
}
F_9 ( & V_22 -> V_36 ) ;
}
static int F_10 ( struct V_21 * V_22 , int V_28 )
{
struct V_1 * V_2 ;
F_4 ( V_22 , V_28 ) ;
if ( V_22 -> V_32 )
F_4 ( V_22 , V_26 ) ;
F_7 ( & V_22 -> V_36 ) ;
F_8 (instance, &tz->thermal_instances, tz_node)
F_11 ( V_2 -> V_7 ) ;
F_9 ( & V_22 -> V_36 ) ;
return 0 ;
}
int F_12 ( void )
{
return F_13 ( & V_38 ) ;
}
void F_14 ( void )
{
F_15 ( & V_38 ) ;
}
