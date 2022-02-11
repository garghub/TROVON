int F_1 ( struct V_1 * V_2 , int V_3 )
{
enum V_4 V_5 ;
if ( V_2 -> V_6 || ! V_2 -> V_7 -> V_8 ||
V_2 -> V_7 -> V_8 ( V_2 , V_3 , & V_5 ) ) {
if ( V_2 -> V_9 > V_2 -> V_10 )
V_5 = V_11 ;
else if ( V_2 -> V_9 < V_2 -> V_10 )
V_5 = V_12 ;
else
V_5 = V_13 ;
}
return V_5 ;
}
struct V_14 *
F_2 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_3 )
{
struct V_14 * V_17 = NULL ;
struct V_14 * V_18 = NULL ;
F_3 ( & V_2 -> V_19 ) ;
F_3 ( & V_16 -> V_19 ) ;
F_4 (pos, &tz->thermal_instances, tz_node) {
if ( V_17 -> V_2 == V_2 && V_17 -> V_3 == V_3 && V_17 -> V_16 == V_16 ) {
V_18 = V_17 ;
break;
}
}
F_5 ( & V_16 -> V_19 ) ;
F_5 ( & V_2 -> V_19 ) ;
return V_18 ;
}
int F_6 ( struct V_1 * V_2 , int * V_20 )
{
int V_21 = - V_22 ;
int V_23 ;
int V_24 = V_25 ;
enum V_26 type ;
if ( ! V_2 || F_7 ( V_2 ) || ! V_2 -> V_7 -> V_27 )
goto exit;
F_3 ( & V_2 -> V_19 ) ;
V_21 = V_2 -> V_7 -> V_27 ( V_2 , V_20 ) ;
if ( F_8 ( V_28 ) && V_2 -> V_6 ) {
for ( V_23 = 0 ; V_23 < V_2 -> V_29 ; V_23 ++ ) {
V_21 = V_2 -> V_7 -> V_30 ( V_2 , V_23 , & type ) ;
if ( ! V_21 && type == V_31 ) {
V_21 = V_2 -> V_7 -> V_32 ( V_2 , V_23 ,
& V_24 ) ;
break;
}
}
if ( ! V_21 && * V_20 < V_24 )
* V_20 = V_2 -> V_6 ;
}
F_5 ( & V_2 -> V_19 ) ;
exit:
return V_21 ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_33 = - V_25 ;
int V_34 = V_25 ;
int V_35 , V_36 ;
int V_37 , V_21 ;
F_3 ( & V_2 -> V_19 ) ;
if ( ! V_2 -> V_7 -> V_38 || ! V_2 -> V_7 -> V_39 )
goto exit;
for ( V_37 = 0 ; V_37 < V_2 -> V_29 ; V_37 ++ ) {
int V_40 ;
V_2 -> V_7 -> V_32 ( V_2 , V_37 , & V_35 ) ;
V_2 -> V_7 -> V_39 ( V_2 , V_37 , & V_36 ) ;
V_40 = V_35 - V_36 ;
if ( V_40 < V_2 -> V_9 && V_40 > V_33 )
V_33 = V_40 ;
if ( V_35 > V_2 -> V_9 && V_35 < V_34 )
V_34 = V_35 ;
}
if ( V_2 -> V_41 == V_33 && V_2 -> V_42 == V_34 )
goto exit;
V_2 -> V_41 = V_33 ;
V_2 -> V_42 = V_34 ;
F_10 ( & V_2 -> V_43 ,
L_1 , V_33 , V_34 ) ;
V_21 = V_2 -> V_7 -> V_38 ( V_2 , V_33 , V_34 ) ;
if ( V_21 )
F_11 ( & V_2 -> V_43 , L_2 , V_21 ) ;
exit:
F_5 ( & V_2 -> V_19 ) ;
}
void F_12 ( struct V_15 * V_16 )
{
struct V_14 * V_44 ;
unsigned long V_45 = 0 ;
F_3 ( & V_16 -> V_19 ) ;
if ( V_16 -> V_46 ) {
F_5 ( & V_16 -> V_19 ) ;
return;
}
F_4 (instance, &cdev->thermal_instances, cdev_node) {
F_10 ( & V_16 -> V_43 , L_3 ,
V_44 -> V_2 -> V_47 , V_44 -> V_45 ) ;
if ( V_44 -> V_45 == V_48 )
continue;
if ( V_44 -> V_45 > V_45 )
V_45 = V_44 -> V_45 ;
}
V_16 -> V_7 -> V_49 ( V_16 , V_45 ) ;
V_16 -> V_46 = true ;
F_5 ( & V_16 -> V_19 ) ;
F_13 ( V_16 , V_45 ) ;
F_10 ( & V_16 -> V_43 , L_4 , V_45 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_50 )
return V_2 -> V_50 -> V_51 ;
return 1 ;
}
int F_15 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_50 )
return V_2 -> V_50 -> V_52 ;
return 0 ;
}
