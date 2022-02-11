static unsigned long F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_8 ;
V_7 -> V_9 -> V_10 ( V_7 , & V_8 ) ;
switch ( V_4 ) {
case V_11 :
if ( V_5 ) {
V_8 = V_8 < V_2 -> V_12 ?
( V_8 + 1 ) : V_2 -> V_12 ;
if ( V_8 < V_2 -> V_13 )
V_8 = V_2 -> V_13 ;
}
break;
case V_14 :
if ( V_5 )
V_8 = V_2 -> V_12 ;
break;
case V_15 :
if ( V_8 == V_2 -> V_13 ) {
if ( ! V_5 )
V_8 = - 1 ;
} else {
V_8 -= 1 ;
if ( V_8 > V_2 -> V_12 )
V_8 = V_2 -> V_12 ;
}
break;
case V_16 :
if ( V_8 == V_2 -> V_13 ) {
if ( ! V_5 )
V_8 = - 1 ;
} else
V_8 = V_2 -> V_13 ;
break;
default:
break;
}
return V_8 ;
}
static void F_2 ( struct V_17 * V_18 ,
enum V_19 type , int V_20 )
{
if ( type == V_21 || type == V_22 )
V_18 -> V_23 += V_20 ;
}
static void F_3 ( struct V_17 * V_18 , int V_24 )
{
long V_25 ;
enum V_19 V_26 ;
enum V_3 V_4 ;
struct V_1 * V_2 ;
bool V_5 = false ;
int V_27 ;
if ( V_24 == V_22 ) {
V_25 = V_18 -> V_28 ;
V_26 = V_22 ;
} else {
V_18 -> V_9 -> V_29 ( V_18 , V_24 , & V_25 ) ;
V_18 -> V_9 -> V_30 ( V_18 , V_24 , & V_26 ) ;
}
V_4 = F_4 ( V_18 , V_24 ) ;
if ( V_18 -> V_31 >= V_25 )
V_5 = true ;
F_5 ( & V_18 -> V_32 ) ;
F_6 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_24 != V_24 )
continue;
V_27 = V_2 -> V_33 ;
V_2 -> V_33 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_27 == V_34 &&
V_2 -> V_33 != V_34 )
F_2 ( V_18 , V_26 , 1 ) ;
else if ( V_27 != V_34 &&
V_2 -> V_33 == V_34 )
F_2 ( V_18 , V_26 , - 1 ) ;
V_2 -> V_7 -> V_35 = false ;
}
F_7 ( & V_18 -> V_32 ) ;
}
static int F_8 ( struct V_17 * V_18 , int V_24 )
{
struct V_1 * V_2 ;
F_3 ( V_18 , V_24 ) ;
if ( V_18 -> V_28 )
F_3 ( V_18 , V_22 ) ;
F_5 ( & V_18 -> V_32 ) ;
F_6 (instance, &tz->thermal_instances, tz_node)
F_9 ( V_2 -> V_7 ) ;
F_7 ( & V_18 -> V_32 ) ;
return 0 ;
}
int F_10 ( void )
{
return F_11 ( & V_36 ) ;
}
void F_12 ( void )
{
F_13 ( & V_36 ) ;
}
