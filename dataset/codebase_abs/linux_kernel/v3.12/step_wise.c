static unsigned long F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_8 ;
unsigned long V_9 ;
V_7 -> V_10 -> V_11 ( V_7 , & V_8 ) ;
V_9 = V_2 -> V_12 ;
switch ( V_4 ) {
case V_13 :
if ( V_5 ) {
V_9 = V_8 < V_2 -> V_14 ?
( V_8 + 1 ) : V_2 -> V_14 ;
if ( V_9 < V_2 -> V_15 )
V_9 = V_2 -> V_15 ;
}
break;
case V_16 :
if ( V_5 )
V_9 = V_2 -> V_14 ;
break;
case V_17 :
if ( V_8 == V_2 -> V_15 ) {
if ( ! V_5 )
V_9 = V_18 ;
} else {
V_9 = V_8 - 1 ;
if ( V_9 > V_2 -> V_14 )
V_9 = V_2 -> V_14 ;
}
break;
case V_19 :
if ( V_8 == V_2 -> V_15 ) {
if ( ! V_5 )
V_9 = V_18 ;
} else
V_9 = V_2 -> V_15 ;
break;
default:
break;
}
return V_9 ;
}
static void F_2 ( struct V_20 * V_21 ,
enum V_22 type , int V_23 )
{
if ( type == V_24 || type == V_25 )
V_21 -> V_26 += V_23 ;
}
static void F_3 ( struct V_20 * V_21 , int V_27 )
{
long V_28 ;
enum V_22 V_29 ;
enum V_3 V_4 ;
struct V_1 * V_2 ;
bool V_5 = false ;
int V_30 ;
if ( V_27 == V_25 ) {
V_28 = V_21 -> V_31 ;
V_29 = V_25 ;
} else {
V_21 -> V_10 -> V_32 ( V_21 , V_27 , & V_28 ) ;
V_21 -> V_10 -> V_33 ( V_21 , V_27 , & V_29 ) ;
}
V_4 = F_4 ( V_21 , V_27 ) ;
if ( V_21 -> V_34 >= V_28 )
V_5 = true ;
F_5 ( & V_21 -> V_35 ) ;
F_6 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_27 != V_27 )
continue;
V_30 = V_2 -> V_12 ;
V_2 -> V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_30 == V_2 -> V_12 )
continue;
if ( V_30 == V_18 &&
V_2 -> V_12 != V_18 )
F_2 ( V_21 , V_29 , 1 ) ;
else if ( V_30 != V_18 &&
V_2 -> V_12 == V_18 )
F_2 ( V_21 , V_29 , - 1 ) ;
V_2 -> V_7 -> V_36 = false ;
}
F_7 ( & V_21 -> V_35 ) ;
}
static int F_8 ( struct V_20 * V_21 , int V_27 )
{
struct V_1 * V_2 ;
F_3 ( V_21 , V_27 ) ;
if ( V_21 -> V_31 )
F_3 ( V_21 , V_25 ) ;
F_5 ( & V_21 -> V_35 ) ;
F_6 (instance, &tz->thermal_instances, tz_node)
F_9 ( V_2 -> V_7 ) ;
F_7 ( & V_21 -> V_35 ) ;
return 0 ;
}
int F_10 ( void )
{
return F_11 ( & V_37 ) ;
}
void F_12 ( void )
{
F_13 ( & V_37 ) ;
}
