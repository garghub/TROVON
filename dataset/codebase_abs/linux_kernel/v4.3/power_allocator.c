static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 * V_2 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( V_1 << V_3 , V_2 ) ;
}
static T_2 F_4 ( struct V_4 * V_5 )
{
T_2 V_6 = 0 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_5 (instance, &tz->thermal_instances, tz_node) {
struct V_12 * V_13 = V_8 -> V_13 ;
T_2 V_14 ;
if ( V_8 -> V_15 != V_10 -> V_16 )
continue;
if ( F_6 ( V_13 , V_5 , & V_14 ) )
continue;
V_6 += V_14 ;
}
return V_6 ;
}
static void F_7 ( struct V_4 * V_5 ,
T_2 V_6 , int V_17 ,
int V_18 , bool V_19 )
{
int V_20 ;
int V_21 ;
T_2 V_22 ;
V_20 = V_5 -> V_23 -> V_24 ( V_5 , V_17 , & V_21 ) ;
if ( V_20 )
V_21 = 0 ;
V_22 = V_18 - V_21 ;
if ( ! V_22 )
return;
if ( ! V_5 -> V_25 -> V_26 || V_19 )
V_5 -> V_25 -> V_26 = F_8 ( V_6 ) /
V_22 ;
if ( ! V_5 -> V_25 -> V_27 || V_19 )
V_5 -> V_25 -> V_27 = F_8 ( 2 * V_6 ) /
V_22 ;
if ( ! V_5 -> V_25 -> V_28 || V_19 )
V_5 -> V_25 -> V_28 = F_8 ( 10 ) / 1000 ;
}
static T_2 F_9 ( struct V_4 * V_5 ,
int V_29 ,
int V_18 ,
T_2 V_30 )
{
T_1 V_31 , V_32 , V_33 , V_34 ;
T_3 V_35 , V_36 ;
T_2 V_6 ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_36 = F_8 ( V_30 ) ;
if ( V_5 -> V_25 -> V_6 ) {
V_6 = V_5 -> V_25 -> V_6 ;
} else {
V_6 = F_4 ( V_5 ) ;
F_7 ( V_5 , V_6 ,
V_10 -> V_17 , V_18 ,
true ) ;
}
V_35 = V_18 - V_29 ;
V_35 = F_8 ( V_35 ) ;
V_31 = F_1 ( V_35 < 0 ? V_5 -> V_25 -> V_26 : V_5 -> V_25 -> V_27 , V_35 ) ;
V_32 = F_1 ( V_5 -> V_25 -> V_28 , V_10 -> V_37 ) ;
if ( V_35 < F_8 ( V_5 -> V_25 -> V_38 ) ) {
T_1 V_39 = V_32 + F_1 ( V_5 -> V_25 -> V_28 , V_35 ) ;
if ( F_10 ( V_39 ) < V_36 ) {
V_32 = V_39 ;
V_10 -> V_37 += V_35 ;
}
}
V_33 = F_1 ( V_5 -> V_25 -> V_40 , V_35 - V_10 -> V_41 ) ;
V_33 = F_2 ( V_33 , V_5 -> V_42 ) ;
V_10 -> V_41 = V_35 ;
V_34 = V_31 + V_32 + V_33 ;
V_34 = V_6 + F_11 ( V_34 ) ;
V_34 = F_12 ( V_34 , ( T_1 ) 0 , ( T_1 ) V_30 ) ;
F_13 ( V_5 , F_11 ( V_35 ) ,
F_11 ( V_10 -> V_37 ) ,
F_11 ( V_31 ) , F_11 ( V_32 ) ,
F_11 ( V_33 ) , V_34 ) ;
return V_34 ;
}
static void F_14 ( T_2 * V_43 , T_2 * V_44 , int V_45 ,
T_2 V_46 , T_2 V_34 ,
T_2 * V_47 , T_2 * V_48 )
{
T_2 V_49 , V_50 ;
int V_32 ;
if ( ! V_46 )
V_46 = 1 ;
V_50 = 0 ;
V_49 = 0 ;
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ ) {
T_4 V_51 = V_43 [ V_32 ] * V_34 ;
V_47 [ V_32 ] = F_15 ( V_51 ,
V_46 ) ;
if ( V_47 [ V_32 ] > V_44 [ V_32 ] ) {
V_49 += V_47 [ V_32 ] - V_44 [ V_32 ] ;
V_47 [ V_32 ] = V_44 [ V_32 ] ;
}
V_48 [ V_32 ] = V_44 [ V_32 ] - V_47 [ V_32 ] ;
V_50 += V_48 [ V_32 ] ;
}
if ( ! V_49 )
return;
V_49 = F_16 ( V_49 , V_50 ) ;
if ( V_50 > 0 )
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ )
V_47 [ V_32 ] += ( V_48 [ V_32 ] *
V_49 ) / V_50 ;
}
static int F_17 ( struct V_4 * V_5 ,
int V_29 ,
int V_18 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
T_2 * V_43 , * V_44 , * V_47 , * V_48 ;
T_2 * V_52 ;
T_2 V_46 , V_30 , V_53 ;
T_2 V_54 , V_34 ;
int V_32 , V_45 , V_55 , V_20 = 0 ;
int V_16 = V_10 -> V_16 ;
F_18 ( & V_5 -> V_56 ) ;
V_45 = 0 ;
V_55 = 0 ;
F_5 (instance, &tz->thermal_instances, tz_node) {
if ( ( V_8 -> V_15 == V_16 ) &&
F_19 ( V_8 -> V_13 ) ) {
V_45 ++ ;
V_55 += V_8 -> V_57 ;
}
}
if ( ! V_45 ) {
V_20 = - V_58 ;
goto V_59;
}
F_20 ( sizeof( * V_43 ) != sizeof( * V_44 ) ) ;
F_20 ( sizeof( * V_43 ) != sizeof( * V_47 ) ) ;
F_20 ( sizeof( * V_43 ) != sizeof( * V_48 ) ) ;
F_20 ( sizeof( * V_43 ) != sizeof( * V_52 ) ) ;
V_43 = F_21 ( V_45 * 5 , sizeof( * V_43 ) , V_60 ) ;
if ( ! V_43 ) {
V_20 = - V_61 ;
goto V_59;
}
V_44 = & V_43 [ V_45 ] ;
V_47 = & V_43 [ 2 * V_45 ] ;
V_48 = & V_43 [ 3 * V_45 ] ;
V_52 = & V_43 [ 4 * V_45 ] ;
V_32 = 0 ;
V_53 = 0 ;
V_46 = 0 ;
V_30 = 0 ;
F_5 (instance, &tz->thermal_instances, tz_node) {
int V_57 ;
struct V_12 * V_13 = V_8 -> V_13 ;
if ( V_8 -> V_15 != V_16 )
continue;
if ( ! F_19 ( V_13 ) )
continue;
if ( V_13 -> V_23 -> V_62 ( V_13 , V_5 , & V_43 [ V_32 ] ) )
continue;
if ( ! V_55 )
V_57 = 1 << V_3 ;
else
V_57 = V_8 -> V_57 ;
V_52 [ V_32 ] = F_11 ( V_57 * V_43 [ V_32 ] ) ;
if ( F_22 ( V_13 , V_5 , & V_44 [ V_32 ] ) )
continue;
V_46 += V_43 [ V_32 ] ;
V_30 += V_44 [ V_32 ] ;
V_53 += V_52 [ V_32 ] ;
V_32 ++ ;
}
V_34 = F_9 ( V_5 , V_29 , V_18 ,
V_30 ) ;
F_14 ( V_52 , V_44 , V_45 ,
V_53 , V_34 , V_47 ,
V_48 ) ;
V_54 = 0 ;
V_32 = 0 ;
F_5 (instance, &tz->thermal_instances, tz_node) {
if ( V_8 -> V_15 != V_16 )
continue;
if ( ! F_19 ( V_8 -> V_13 ) )
continue;
F_23 ( V_8 -> V_13 , V_8 ,
V_47 [ V_32 ] ) ;
V_54 += V_47 [ V_32 ] ;
V_32 ++ ;
}
F_24 ( V_5 , V_43 , V_46 ,
V_47 , V_54 ,
V_45 , V_34 ,
V_30 , V_29 ,
V_18 - V_29 ) ;
F_25 ( V_43 ) ;
V_59:
F_26 ( & V_5 -> V_56 ) ;
return V_20 ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
int V_32 , V_63 , V_64 ;
bool V_65 ;
V_65 = false ;
V_63 = V_66 ;
V_64 = V_66 ;
for ( V_32 = 0 ; V_32 < V_5 -> V_67 ; V_32 ++ ) {
enum V_68 type ;
int V_20 ;
V_20 = V_5 -> V_23 -> V_69 ( V_5 , V_32 , & type ) ;
if ( V_20 ) {
F_28 ( & V_5 -> V_70 ,
L_1 , V_32 ,
V_20 ) ;
continue;
}
if ( type == V_71 ) {
if ( ! V_65 ) {
V_10 -> V_17 = V_32 ;
V_65 = true ;
} else {
V_64 = V_32 ;
}
} else if ( type == V_72 ) {
V_63 = V_32 ;
} else {
break;
}
}
if ( V_64 != V_66 ) {
V_10 -> V_16 = V_64 ;
} else if ( V_65 ) {
V_10 -> V_16 = V_10 -> V_17 ;
V_10 -> V_17 = V_66 ;
} else {
V_10 -> V_17 = V_66 ;
V_10 -> V_16 = V_63 ;
}
}
static void F_29 ( struct V_9 * V_10 )
{
V_10 -> V_37 = 0 ;
V_10 -> V_41 = 0 ;
}
static void F_30 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_5 (instance, &tz->thermal_instances, tz_node) {
if ( ( V_8 -> V_15 != V_10 -> V_16 ) ||
( ! F_19 ( V_8 -> V_13 ) ) )
continue;
V_8 -> V_73 = 0 ;
V_8 -> V_13 -> V_74 = false ;
F_31 ( V_8 -> V_13 ) ;
}
}
static int F_32 ( struct V_4 * V_5 )
{
int V_20 ;
struct V_9 * V_10 ;
int V_18 ;
V_10 = F_33 ( sizeof( * V_10 ) , V_60 ) ;
if ( ! V_10 )
return - V_61 ;
if ( ! V_5 -> V_25 ) {
V_5 -> V_25 = F_33 ( sizeof( * V_5 -> V_25 ) , V_60 ) ;
if ( ! V_5 -> V_25 ) {
V_20 = - V_61 ;
goto V_75;
}
V_10 -> V_76 = true ;
}
if ( ! V_5 -> V_25 -> V_6 )
F_28 ( & V_5 -> V_70 , L_2 ) ;
F_27 ( V_5 , V_10 ) ;
if ( V_5 -> V_67 > 0 ) {
V_20 = V_5 -> V_23 -> V_24 ( V_5 ,
V_10 -> V_16 ,
& V_18 ) ;
if ( ! V_20 )
F_7 ( V_5 , V_5 -> V_25 -> V_6 ,
V_10 -> V_17 ,
V_18 , false ) ;
}
F_29 ( V_10 ) ;
V_5 -> V_11 = V_10 ;
return 0 ;
V_75:
F_25 ( V_10 ) ;
return V_20 ;
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_35 ( & V_5 -> V_70 , L_3 , V_5 -> V_77 ) ;
if ( V_10 -> V_76 ) {
F_25 ( V_5 -> V_25 ) ;
V_5 -> V_25 = NULL ;
}
F_25 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
static int F_36 ( struct V_4 * V_5 , int V_15 )
{
int V_20 ;
int V_21 , V_18 , V_29 ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_15 != V_10 -> V_16 )
return 0 ;
V_20 = F_37 ( V_5 , & V_29 ) ;
if ( V_20 ) {
F_28 ( & V_5 -> V_70 , L_4 , V_20 ) ;
return V_20 ;
}
V_20 = V_5 -> V_23 -> V_24 ( V_5 , V_10 -> V_17 ,
& V_21 ) ;
if ( ! V_20 && ( V_29 < V_21 ) ) {
V_5 -> V_78 = 0 ;
F_29 ( V_10 ) ;
F_30 ( V_5 ) ;
return 0 ;
}
V_5 -> V_78 = 1 ;
V_20 = V_5 -> V_23 -> V_24 ( V_5 , V_10 -> V_16 ,
& V_18 ) ;
if ( V_20 ) {
F_28 ( & V_5 -> V_70 ,
L_5 ,
V_20 ) ;
return V_20 ;
}
return F_17 ( V_5 , V_29 , V_18 ) ;
}
int F_38 ( void )
{
return F_39 ( & V_79 ) ;
}
void F_40 ( void )
{
F_41 ( & V_79 ) ;
}
