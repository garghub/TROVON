static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 * V_2 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( V_1 << V_3 , V_2 ) ;
}
static T_2 F_4 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned long V_7 ,
T_2 V_8 )
{
T_1 V_9 , V_10 , V_11 , V_12 ;
T_3 V_13 , V_14 ;
struct V_15 * V_16 = V_5 -> V_17 ;
V_14 = F_5 ( V_8 ) ;
V_13 = ( ( T_3 ) V_7 - ( T_3 ) V_6 ) ;
V_13 = F_5 ( V_13 ) ;
V_9 = F_1 ( V_13 < 0 ? V_5 -> V_18 -> V_19 : V_5 -> V_18 -> V_20 , V_13 ) ;
V_10 = F_1 ( V_5 -> V_18 -> V_21 , V_16 -> V_22 ) ;
if ( V_13 < F_5 ( V_5 -> V_18 -> V_23 ) ) {
T_1 V_24 = V_10 + F_1 ( V_5 -> V_18 -> V_21 , V_13 ) ;
if ( F_6 ( V_24 ) < V_14 ) {
V_10 = V_24 ;
V_16 -> V_22 += V_13 ;
}
}
V_11 = F_1 ( V_5 -> V_18 -> V_25 , V_13 - V_16 -> V_26 ) ;
V_11 = F_2 ( V_11 , V_5 -> V_27 ) ;
V_16 -> V_26 = V_13 ;
V_12 = V_9 + V_10 + V_11 ;
V_12 = V_5 -> V_18 -> V_28 + F_7 ( V_12 ) ;
V_12 = F_8 ( V_12 , ( T_1 ) 0 , ( T_1 ) V_8 ) ;
F_9 ( V_5 , F_7 ( V_13 ) ,
F_7 ( V_16 -> V_22 ) ,
F_7 ( V_9 ) , F_7 ( V_10 ) ,
F_7 ( V_11 ) , V_12 ) ;
return V_12 ;
}
static void F_10 ( T_2 * V_29 , T_2 * V_30 , int V_31 ,
T_2 V_32 , T_2 V_12 ,
T_2 * V_33 , T_2 * V_34 )
{
T_2 V_35 , V_36 ;
int V_10 ;
if ( ! V_32 )
V_32 = 1 ;
V_36 = 0 ;
V_35 = 0 ;
for ( V_10 = 0 ; V_10 < V_31 ; V_10 ++ ) {
T_4 V_37 = V_29 [ V_10 ] * V_12 ;
V_33 [ V_10 ] = F_11 ( V_37 ,
V_32 ) ;
if ( V_33 [ V_10 ] > V_30 [ V_10 ] ) {
V_35 += V_33 [ V_10 ] - V_30 [ V_10 ] ;
V_33 [ V_10 ] = V_30 [ V_10 ] ;
}
V_34 [ V_10 ] = V_30 [ V_10 ] - V_33 [ V_10 ] ;
V_36 += V_34 [ V_10 ] ;
}
if ( ! V_35 )
return;
V_35 = F_12 ( V_35 , V_36 ) ;
if ( V_36 > 0 )
for ( V_10 = 0 ; V_10 < V_31 ; V_10 ++ )
V_33 [ V_10 ] += ( V_34 [ V_10 ] *
V_35 ) / V_36 ;
}
static int F_13 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned long V_7 )
{
struct V_38 * V_39 ;
struct V_15 * V_16 = V_5 -> V_17 ;
T_2 * V_29 , * V_30 , * V_33 , * V_34 ;
T_2 * V_40 ;
T_2 V_32 , V_8 , V_41 ;
T_2 V_42 , V_12 ;
int V_10 , V_31 , V_43 , V_44 = 0 ;
int V_45 = V_16 -> V_45 ;
F_14 ( & V_5 -> V_46 ) ;
V_31 = 0 ;
V_43 = 0 ;
F_15 (instance, &tz->thermal_instances, tz_node) {
if ( ( V_39 -> V_47 == V_45 ) &&
F_16 ( V_39 -> V_48 ) ) {
V_31 ++ ;
V_43 += V_39 -> V_49 ;
}
}
F_17 ( sizeof( * V_29 ) != sizeof( * V_30 ) ) ;
F_17 ( sizeof( * V_29 ) != sizeof( * V_33 ) ) ;
F_17 ( sizeof( * V_29 ) != sizeof( * V_34 ) ) ;
F_17 ( sizeof( * V_29 ) != sizeof( * V_40 ) ) ;
V_29 = F_18 ( V_31 * 5 , sizeof( * V_29 ) , V_50 ) ;
if ( ! V_29 ) {
V_44 = - V_51 ;
goto V_52;
}
V_30 = & V_29 [ V_31 ] ;
V_33 = & V_29 [ 2 * V_31 ] ;
V_34 = & V_29 [ 3 * V_31 ] ;
V_40 = & V_29 [ 4 * V_31 ] ;
V_10 = 0 ;
V_41 = 0 ;
V_32 = 0 ;
V_8 = 0 ;
F_15 (instance, &tz->thermal_instances, tz_node) {
int V_49 ;
struct V_53 * V_48 = V_39 -> V_48 ;
if ( V_39 -> V_47 != V_45 )
continue;
if ( ! F_16 ( V_48 ) )
continue;
if ( V_48 -> V_54 -> V_55 ( V_48 , V_5 , & V_29 [ V_10 ] ) )
continue;
if ( ! V_43 )
V_49 = 1 << V_3 ;
else
V_49 = V_39 -> V_49 ;
V_40 [ V_10 ] = F_7 ( V_49 * V_29 [ V_10 ] ) ;
if ( F_19 ( V_48 , V_5 , & V_30 [ V_10 ] ) )
continue;
V_32 += V_29 [ V_10 ] ;
V_8 += V_30 [ V_10 ] ;
V_41 += V_40 [ V_10 ] ;
V_10 ++ ;
}
V_12 = F_4 ( V_5 , V_6 , V_7 ,
V_8 ) ;
F_10 ( V_40 , V_30 , V_31 ,
V_41 , V_12 , V_33 ,
V_34 ) ;
V_42 = 0 ;
V_10 = 0 ;
F_15 (instance, &tz->thermal_instances, tz_node) {
if ( V_39 -> V_47 != V_45 )
continue;
if ( ! F_16 ( V_39 -> V_48 ) )
continue;
F_20 ( V_39 -> V_48 , V_39 ,
V_33 [ V_10 ] ) ;
V_42 += V_33 [ V_10 ] ;
V_10 ++ ;
}
F_21 ( V_5 , V_29 , V_32 ,
V_33 , V_42 ,
V_31 , V_12 ,
V_8 , V_6 ,
( T_3 ) V_7 - ( T_3 ) V_6 ) ;
F_22 ( V_29 ) ;
V_52:
F_23 ( & V_5 -> V_46 ) ;
return V_44 ;
}
static int F_24 ( struct V_4 * V_5 ,
struct V_15 * V_16 )
{
int V_10 , V_44 , V_56 ;
bool V_57 ;
V_57 = false ;
V_56 = - 1 ;
V_44 = - V_58 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_59 ; V_10 ++ ) {
enum V_60 type ;
V_44 = V_5 -> V_54 -> V_61 ( V_5 , V_10 , & type ) ;
if ( V_44 )
return V_44 ;
if ( ! V_57 ) {
if ( type == V_62 ) {
V_16 -> V_63 = V_10 ;
V_57 = true ;
}
} else if ( type == V_62 ) {
V_56 = V_10 ;
} else {
break;
}
}
if ( V_56 != - 1 ) {
V_16 -> V_45 = V_56 ;
V_44 = 0 ;
} else {
V_44 = - V_58 ;
}
return V_44 ;
}
static void F_25 ( struct V_15 * V_16 )
{
V_16 -> V_22 = 0 ;
V_16 -> V_26 = 0 ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_38 * V_39 ;
struct V_15 * V_16 = V_5 -> V_17 ;
F_15 (instance, &tz->thermal_instances, tz_node) {
if ( ( V_39 -> V_47 != V_16 -> V_45 ) ||
( ! F_16 ( V_39 -> V_48 ) ) )
continue;
V_39 -> V_64 = 0 ;
V_39 -> V_48 -> V_65 = false ;
F_27 ( V_39 -> V_48 ) ;
}
}
static int F_28 ( struct V_4 * V_5 )
{
int V_44 ;
struct V_15 * V_16 ;
unsigned long V_66 , V_7 ;
T_2 V_67 ;
if ( ! V_5 -> V_18 || ! V_5 -> V_18 -> V_28 ) {
F_29 ( & V_5 -> V_68 ,
L_1 ) ;
return - V_58 ;
}
V_16 = F_30 ( sizeof( * V_16 ) , V_50 ) ;
if ( ! V_16 )
return - V_51 ;
V_44 = F_24 ( V_5 , V_16 ) ;
if ( V_44 ) {
F_29 ( & V_5 -> V_68 ,
L_2 ,
V_5 -> type ) ;
goto free;
}
V_44 = V_5 -> V_54 -> V_69 ( V_5 , V_16 -> V_63 ,
& V_66 ) ;
if ( V_44 )
goto free;
V_44 = V_5 -> V_54 -> V_69 ( V_5 , V_16 -> V_45 ,
& V_7 ) ;
if ( V_44 )
goto free;
V_67 = V_7 - V_66 ;
V_5 -> V_18 -> V_19 = V_5 -> V_18 -> V_19 ? :
F_5 ( V_5 -> V_18 -> V_28 ) / V_67 ;
V_5 -> V_18 -> V_20 = V_5 -> V_18 -> V_20 ? :
F_5 ( 2 * V_5 -> V_18 -> V_28 ) /
V_67 ;
V_5 -> V_18 -> V_21 = V_5 -> V_18 -> V_21 ? : F_5 ( 10 ) / 1000 ;
F_25 ( V_16 ) ;
V_5 -> V_17 = V_16 ;
return 0 ;
free:
F_22 ( V_16 ) ;
return V_44 ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_32 ( & V_5 -> V_68 , L_3 , V_5 -> V_70 ) ;
F_22 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
}
static int F_33 ( struct V_4 * V_5 , int V_47 )
{
int V_44 ;
unsigned long V_66 , V_7 , V_6 ;
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_47 != V_16 -> V_45 )
return 0 ;
V_44 = F_34 ( V_5 , & V_6 ) ;
if ( V_44 ) {
F_35 ( & V_5 -> V_68 , L_4 , V_44 ) ;
return V_44 ;
}
V_44 = V_5 -> V_54 -> V_69 ( V_5 , V_16 -> V_63 ,
& V_66 ) ;
if ( V_44 ) {
F_35 ( & V_5 -> V_68 ,
L_5 , V_44 ) ;
return V_44 ;
}
if ( V_6 < V_66 ) {
V_5 -> V_71 = 0 ;
F_25 ( V_16 ) ;
F_26 ( V_5 ) ;
return 0 ;
}
V_5 -> V_71 = 1 ;
V_44 = V_5 -> V_54 -> V_69 ( V_5 , V_16 -> V_45 ,
& V_7 ) ;
if ( V_44 ) {
F_35 ( & V_5 -> V_68 ,
L_6 ,
V_44 ) ;
return V_44 ;
}
return F_13 ( V_5 , V_6 , V_7 ) ;
}
int F_36 ( void )
{
return F_37 ( & V_72 ) ;
}
void F_38 ( void )
{
F_39 ( & V_72 ) ;
}
