static unsigned long F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_8 ;
unsigned long V_9 ;
V_7 -> V_10 -> V_11 ( V_7 , & V_8 ) ;
V_9 = V_2 -> V_12 ;
F_2 ( & V_7 -> V_13 , L_1 , V_8 ) ;
if ( ! V_2 -> V_14 ) {
if ( V_5 ) {
V_9 = ( V_8 + 1 ) >= V_2 -> V_15 ?
V_2 -> V_15 :
( ( V_8 + 1 ) < V_2 -> V_16 ?
V_2 -> V_16 : ( V_8 + 1 ) ) ;
} else {
V_9 = V_17 ;
}
return V_9 ;
}
switch ( V_4 ) {
case V_18 :
if ( V_5 ) {
V_9 = V_8 < V_2 -> V_15 ?
( V_8 + 1 ) : V_2 -> V_15 ;
if ( V_9 < V_2 -> V_16 )
V_9 = V_2 -> V_16 ;
}
break;
case V_19 :
if ( V_5 )
V_9 = V_2 -> V_15 ;
break;
case V_20 :
if ( V_8 <= V_2 -> V_16 ) {
if ( ! V_5 )
V_9 = V_17 ;
} else {
V_9 = V_8 - 1 ;
if ( V_9 > V_2 -> V_15 )
V_9 = V_2 -> V_15 ;
}
break;
case V_21 :
if ( V_8 == V_2 -> V_16 ) {
if ( ! V_5 )
V_9 = V_17 ;
} else
V_9 = V_2 -> V_16 ;
break;
default:
break;
}
return V_9 ;
}
static void F_3 ( struct V_22 * V_23 ,
enum V_24 type , int V_25 )
{
if ( type == V_26 || type == V_27 )
V_23 -> V_28 += V_25 ;
}
static void F_4 ( struct V_22 * V_23 , int V_29 )
{
int V_30 ;
enum V_24 V_31 ;
enum V_3 V_4 ;
struct V_1 * V_2 ;
bool V_5 = false ;
int V_32 ;
if ( V_29 == V_27 ) {
V_30 = V_23 -> V_33 ;
V_31 = V_27 ;
} else {
V_23 -> V_10 -> V_34 ( V_23 , V_29 , & V_30 ) ;
V_23 -> V_10 -> V_35 ( V_23 , V_29 , & V_31 ) ;
}
V_4 = F_5 ( V_23 , V_29 ) ;
if ( V_23 -> V_36 >= V_30 ) {
V_5 = true ;
F_6 ( V_23 , V_29 , V_31 ) ;
}
F_2 ( & V_23 -> V_13 , L_2 ,
V_29 , V_31 , V_30 , V_4 , V_5 ) ;
F_7 ( & V_23 -> V_37 ) ;
F_8 (instance, &tz->thermal_instances, tz_node) {
if ( V_2 -> V_29 != V_29 )
continue;
V_32 = V_2 -> V_12 ;
V_2 -> V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
F_2 ( & V_2 -> V_7 -> V_13 , L_3 ,
V_32 , ( int ) V_2 -> V_12 ) ;
if ( V_2 -> V_14 && V_32 == V_2 -> V_12 )
continue;
if ( V_32 == V_17 &&
V_2 -> V_12 != V_17 )
F_3 ( V_23 , V_31 , 1 ) ;
else if ( V_32 != V_17 &&
V_2 -> V_12 == V_17 )
F_3 ( V_23 , V_31 , - 1 ) ;
V_2 -> V_14 = true ;
F_7 ( & V_2 -> V_7 -> V_37 ) ;
V_2 -> V_7 -> V_38 = false ;
F_9 ( & V_2 -> V_7 -> V_37 ) ;
}
F_9 ( & V_23 -> V_37 ) ;
}
static int F_10 ( struct V_22 * V_23 , int V_29 )
{
struct V_1 * V_2 ;
F_4 ( V_23 , V_29 ) ;
if ( V_23 -> V_33 )
F_4 ( V_23 , V_27 ) ;
F_7 ( & V_23 -> V_37 ) ;
F_8 (instance, &tz->thermal_instances, tz_node)
F_11 ( V_2 -> V_7 ) ;
F_9 ( & V_23 -> V_37 ) ;
return 0 ;
}
int F_12 ( void )
{
return F_13 ( & V_39 ) ;
}
void F_14 ( void )
{
F_15 ( & V_39 ) ;
}
