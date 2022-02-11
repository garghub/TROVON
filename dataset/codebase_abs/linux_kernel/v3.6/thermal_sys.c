static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int * V_4 )
{
int V_5 ;
V_6:
if ( F_2 ( F_3 ( V_1 , V_7 ) == 0 ) )
return - V_8 ;
if ( V_3 )
F_4 ( V_3 ) ;
V_5 = F_5 ( V_1 , NULL , V_4 ) ;
if ( V_3 )
F_6 ( V_3 ) ;
if ( F_2 ( V_5 == - V_9 ) )
goto V_6;
else if ( F_2 ( V_5 ) )
return V_5 ;
* V_4 = * V_4 & V_10 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 )
{
if ( V_3 )
F_4 ( V_3 ) ;
F_8 ( V_1 , V_4 ) ;
if ( V_3 )
F_6 ( V_3 ) ;
}
static T_1
F_9 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_17 -> type ) ;
}
static T_1
F_11 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
long V_18 ;
int V_19 ;
if ( ! V_17 -> V_20 -> V_21 )
return - V_22 ;
V_19 = V_17 -> V_20 -> V_21 ( V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_12 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
enum V_23 V_24 ;
int V_25 ;
if ( ! V_17 -> V_20 -> V_26 )
return - V_22 ;
V_25 = V_17 -> V_20 -> V_26 ( V_17 , & V_24 ) ;
if ( V_25 )
return V_25 ;
return sprintf ( V_15 , L_1 , V_24 == V_27 ? L_3
: L_4 ) ;
}
static T_1
F_13 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_25 ;
if ( ! V_17 -> V_20 -> V_29 )
return - V_22 ;
if ( ! strncmp ( V_15 , L_3 , sizeof( L_3 ) - 1 ) )
V_25 = V_17 -> V_20 -> V_29 ( V_17 , V_27 ) ;
else if ( ! strncmp ( V_15 , L_4 , sizeof( L_4 ) - 1 ) )
V_25 = V_17 -> V_20 -> V_29 ( V_17 , V_30 ) ;
else
V_25 = - V_31 ;
if ( V_25 )
return V_25 ;
return V_28 ;
}
static T_1
F_14 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
enum V_32 type ;
int V_33 , V_25 ;
if ( ! V_17 -> V_20 -> V_34 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_5 , & V_33 ) )
return - V_31 ;
V_25 = V_17 -> V_20 -> V_34 ( V_17 , V_33 , & type ) ;
if ( V_25 )
return V_25 ;
switch ( type ) {
case V_36 :
return sprintf ( V_15 , L_6 ) ;
case V_37 :
return sprintf ( V_15 , L_7 ) ;
case V_38 :
return sprintf ( V_15 , L_8 ) ;
case V_39 :
return sprintf ( V_15 , L_9 ) ;
default:
return sprintf ( V_15 , L_10 ) ;
}
}
static T_1
F_15 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_33 , V_19 ;
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_40 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_11 , & V_33 ) )
return - V_31 ;
if ( F_16 ( V_15 , 10 , & V_18 ) )
return - V_31 ;
V_19 = V_17 -> V_20 -> V_40 ( V_17 , V_33 , V_18 ) ;
return V_19 ? V_19 : V_28 ;
}
static T_1
F_17 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_33 , V_19 ;
long V_18 ;
if ( ! V_17 -> V_20 -> V_41 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_11 , & V_33 ) )
return - V_31 ;
V_19 = V_17 -> V_20 -> V_41 ( V_17 , V_33 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_18 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_33 , V_19 ;
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_42 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_12 , & V_33 ) )
return - V_31 ;
if ( F_16 ( V_15 , 10 , & V_18 ) )
return - V_31 ;
V_19 = V_17 -> V_20 -> V_42 ( V_17 , V_33 , V_18 ) ;
return V_19 ? V_19 : V_28 ;
}
static T_1
F_19 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_33 , V_19 ;
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_43 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_12 , & V_33 ) )
return - V_31 ;
V_19 = V_17 -> V_20 -> V_43 ( V_17 , V_33 , & V_18 ) ;
return V_19 ? V_19 : sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_20 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
struct V_44 * V_45 = NULL ;
int V_46 ;
if ( ! sscanf ( V_15 , L_13 , & V_46 ) )
return - V_31 ;
if ( V_46 && V_46 < 1000 )
return - V_31 ;
if ( V_46 && ! V_17 -> V_47 ) {
F_4 ( & V_48 ) ;
F_21 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_14 , V_45 -> type ,
sizeof( L_14 ) ) )
F_22 ( V_17 ,
V_49 ,
V_45 ) ;
}
F_6 ( & V_48 ) ;
if ( ! V_17 -> V_50 )
V_17 -> V_50 = 1000 ;
} else if ( ! V_46 && V_17 -> V_47 ) {
F_4 ( & V_48 ) ;
F_21 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_14 , V_45 -> type ,
sizeof( L_14 ) ) )
F_23 ( V_17 ,
V_49 ,
V_45 ) ;
}
F_6 ( & V_48 ) ;
V_17 -> V_50 = 0 ;
}
V_17 -> V_51 = 1 ;
V_17 -> V_52 = 1 ;
V_17 -> V_47 = V_46 ;
F_24 ( V_17 ) ;
return V_28 ;
}
static T_1
F_25 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
return sprintf ( V_15 , L_13 , V_17 -> V_47 ) ;
}
static T_1
F_26 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_44 * V_45 = F_27 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_45 -> type ) ;
}
static T_1
F_28 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_44 * V_45 = F_27 ( V_12 ) ;
unsigned long V_46 ;
int V_19 ;
V_19 = V_45 -> V_20 -> V_53 ( V_45 , & V_46 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_46 ) ;
}
static T_1
F_29 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_44 * V_45 = F_27 ( V_12 ) ;
unsigned long V_46 ;
int V_19 ;
V_19 = V_45 -> V_20 -> V_54 ( V_45 , & V_46 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_46 ) ;
}
static T_1
F_30 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_44 * V_45 = F_27 ( V_12 ) ;
unsigned long V_46 ;
int V_25 ;
if ( ! sscanf ( V_15 , L_2 , & V_46 ) )
return - V_31 ;
if ( ( long ) V_46 < 0 )
return - V_31 ;
V_25 = V_45 -> V_20 -> V_55 ( V_45 , V_46 ) ;
if ( V_25 )
return V_25 ;
return V_28 ;
}
static T_1
F_31 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_56 * V_57 ;
V_57 =
F_32 ( V_14 , struct V_56 , V_14 ) ;
if ( V_57 -> V_33 == V_49 )
return sprintf ( V_15 , L_15 ) ;
else
return sprintf ( V_15 , L_13 , V_57 -> V_33 ) ;
}
static T_1
F_33 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_58 * V_59 = F_34 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_59 -> type ) ;
}
static T_1
F_35 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
long V_18 ;
int V_19 ;
struct V_60 * V_61
= F_32 ( V_14 , struct V_60 , V_14 ) ;
struct V_62 * V_63
= F_32 ( V_61 , struct V_62 ,
V_64 ) ;
struct V_16 * V_17 = V_63 -> V_17 ;
V_19 = V_17 -> V_20 -> V_21 ( V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_36 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_60 * V_61
= F_32 ( V_14 , struct V_60 , V_14 ) ;
struct V_62 * V_63
= F_32 ( V_61 , struct V_62 ,
V_65 ) ;
struct V_16 * V_17 = V_63 -> V_17 ;
long V_18 ;
int V_19 ;
V_19 = V_17 -> V_20 -> V_41 ( V_17 , 0 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static struct V_58 *
F_37 ( const struct V_16 * V_17 )
{
struct V_58 * V_59 ;
F_4 ( & V_48 ) ;
F_21 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_59 -> type , V_17 -> type ) ) {
F_6 ( & V_48 ) ;
return V_59 ;
}
F_6 ( & V_48 ) ;
return NULL ;
}
static struct V_62 *
F_38 ( const struct V_58 * V_59 ,
const struct V_16 * V_17 )
{
struct V_62 * V_63 ;
F_4 ( & V_48 ) ;
F_21 (temp, &hwmon->tz_list, hwmon_node)
if ( V_63 -> V_17 == V_17 ) {
F_6 ( & V_48 ) ;
return V_63 ;
}
F_6 ( & V_48 ) ;
return NULL ;
}
static int
F_39 ( struct V_16 * V_17 )
{
struct V_58 * V_59 ;
struct V_62 * V_63 ;
int V_66 = 1 ;
int V_25 ;
V_59 = F_37 ( V_17 ) ;
if ( V_59 ) {
V_66 = 0 ;
goto V_67;
}
V_59 = F_40 ( sizeof( struct V_58 ) , V_7 ) ;
if ( ! V_59 )
return - V_8 ;
F_41 ( & V_59 -> V_68 ) ;
F_42 ( V_59 -> type , V_17 -> type , V_69 ) ;
V_59 -> V_11 = F_43 ( NULL ) ;
if ( F_44 ( V_59 -> V_11 ) ) {
V_25 = F_45 ( V_59 -> V_11 ) ;
goto V_70;
}
F_46 ( V_59 -> V_11 , V_59 ) ;
V_25 = F_47 ( V_59 -> V_11 , & V_71 ) ;
if ( V_25 )
goto V_70;
V_67:
V_63 = F_40 ( sizeof( struct V_62 ) , V_7 ) ;
if ( ! V_63 ) {
V_25 = - V_8 ;
goto V_72;
}
V_63 -> V_17 = V_17 ;
V_59 -> V_28 ++ ;
snprintf ( V_63 -> V_64 . V_35 , V_69 ,
L_16 , V_59 -> V_28 ) ;
V_63 -> V_64 . V_14 . V_14 . V_35 = V_63 -> V_64 . V_35 ;
V_63 -> V_64 . V_14 . V_14 . V_24 = 0444 ;
V_63 -> V_64 . V_14 . V_73 = F_35 ;
F_48 ( & V_63 -> V_64 . V_14 . V_14 ) ;
V_25 = F_47 ( V_59 -> V_11 , & V_63 -> V_64 . V_14 ) ;
if ( V_25 )
goto V_74;
if ( V_17 -> V_20 -> V_75 ) {
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_75 ( V_17 , & V_18 ) ) {
snprintf ( V_63 -> V_65 . V_35 , V_69 ,
L_17 , V_59 -> V_28 ) ;
V_63 -> V_65 . V_14 . V_14 . V_35 = V_63 -> V_65 . V_35 ;
V_63 -> V_65 . V_14 . V_14 . V_24 = 0444 ;
V_63 -> V_65 . V_14 . V_73 = F_36 ;
F_48 ( & V_63 -> V_65 . V_14 . V_14 ) ;
V_25 = F_47 ( V_59 -> V_11 ,
& V_63 -> V_65 . V_14 ) ;
if ( V_25 )
goto V_76;
}
}
F_4 ( & V_48 ) ;
if ( V_66 )
F_49 ( & V_59 -> V_77 , & V_78 ) ;
F_49 ( & V_63 -> V_79 , & V_59 -> V_68 ) ;
F_6 ( & V_48 ) ;
return 0 ;
V_76:
F_50 ( V_59 -> V_11 , & V_63 -> V_64 . V_14 ) ;
V_74:
F_51 ( V_63 ) ;
V_72:
if ( V_66 ) {
F_50 ( V_59 -> V_11 , & V_71 ) ;
F_52 ( V_59 -> V_11 ) ;
}
V_70:
if ( V_66 )
F_51 ( V_59 ) ;
return V_25 ;
}
static void
F_53 ( struct V_16 * V_17 )
{
struct V_58 * V_59 ;
struct V_62 * V_63 ;
V_59 = F_37 ( V_17 ) ;
if ( F_2 ( ! V_59 ) ) {
F_54 ( & V_17 -> V_11 , L_18 ) ;
return;
}
V_63 = F_38 ( V_59 , V_17 ) ;
if ( F_2 ( ! V_63 ) ) {
F_54 ( & V_17 -> V_11 , L_19 ) ;
return;
}
F_50 ( V_59 -> V_11 , & V_63 -> V_64 . V_14 ) ;
if ( V_17 -> V_20 -> V_75 )
F_50 ( V_59 -> V_11 , & V_63 -> V_65 . V_14 ) ;
F_4 ( & V_48 ) ;
F_55 ( & V_63 -> V_79 ) ;
F_51 ( V_63 ) ;
if ( ! F_56 ( & V_59 -> V_68 ) ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_59 -> V_77 ) ;
F_6 ( & V_48 ) ;
F_50 ( V_59 -> V_11 , & V_71 ) ;
F_52 ( V_59 -> V_11 ) ;
F_51 ( V_59 ) ;
}
static int
F_39 ( struct V_16 * V_17 )
{
return 0 ;
}
static void
F_53 ( struct V_16 * V_17 )
{
}
static void F_57 ( struct V_16 * V_17 ,
int V_80 )
{
F_58 ( & ( V_17 -> V_81 ) ) ;
if ( ! V_80 )
return;
if ( V_80 > 1000 )
F_59 ( V_82 , & ( V_17 -> V_81 ) ,
F_60 ( F_61 ( V_80 ) ) ) ;
else
F_59 ( V_82 , & ( V_17 -> V_81 ) ,
F_61 ( V_80 ) ) ;
}
static void F_62 ( struct V_16 * V_17 ,
int V_63 , int V_83 , int V_33 )
{
int V_84 = 0 ;
struct V_56 * V_57 ;
struct V_44 * V_45 ;
long V_46 , V_85 ;
if ( V_63 >= V_83 ) {
V_17 -> V_86 = true ;
V_84 = ( V_17 -> V_51 * ( V_63 - V_17 -> V_87 ) ) +
( V_17 -> V_52 * ( V_63 - V_83 ) ) ;
if ( V_84 > 0 ) {
F_21 (instance, &tz->cooling_devices,
node) {
if ( V_57 -> V_33 != V_33 )
continue;
V_45 = V_57 -> V_45 ;
V_45 -> V_20 -> V_54 ( V_45 , & V_46 ) ;
V_45 -> V_20 -> V_53 ( V_45 , & V_85 ) ;
if ( V_46 ++ < V_85 )
V_45 -> V_20 -> V_55 ( V_45 , V_46 ) ;
}
} else if ( V_84 < 0 ) {
F_21 (instance, &tz->cooling_devices,
node) {
if ( V_57 -> V_33 != V_33 )
continue;
V_45 = V_57 -> V_45 ;
V_45 -> V_20 -> V_54 ( V_45 , & V_46 ) ;
V_45 -> V_20 -> V_53 ( V_45 , & V_85 ) ;
if ( V_46 > 0 )
V_45 -> V_20 -> V_55 ( V_45 , -- V_46 ) ;
}
}
return;
}
F_21 (instance, &tz->cooling_devices, node) {
if ( V_57 -> V_33 != V_33 )
continue;
V_45 = V_57 -> V_45 ;
V_45 -> V_20 -> V_54 ( V_45 , & V_46 ) ;
V_45 -> V_20 -> V_53 ( V_45 , & V_85 ) ;
if ( V_46 > 0 )
V_45 -> V_20 -> V_55 ( V_45 , -- V_46 ) ;
if ( V_46 == 0 )
V_17 -> V_86 = false ;
}
}
static void F_63 ( struct V_88 * V_89 )
{
struct V_16 * V_17 = F_32 ( V_89 , struct
V_16 ,
V_81 . V_89 ) ;
F_24 ( V_17 ) ;
}
int F_22 ( struct V_16 * V_17 ,
int V_33 ,
struct V_44 * V_45 )
{
struct V_56 * V_12 ;
struct V_56 * V_90 ;
struct V_16 * V_91 ;
struct V_44 * V_92 ;
int V_25 ;
if ( V_33 >= V_17 -> V_93 || ( V_33 < 0 && V_33 != V_49 ) )
return - V_31 ;
F_21 (pos1, &thermal_tz_list, node) {
if ( V_91 == V_17 )
break;
}
F_21 (pos2, &thermal_cdev_list, node) {
if ( V_92 == V_45 )
break;
}
if ( V_17 != V_91 || V_45 != V_92 )
return - V_31 ;
V_12 =
F_40 ( sizeof( struct V_56 ) , V_7 ) ;
if ( ! V_12 )
return - V_8 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_45 = V_45 ;
V_12 -> V_33 = V_33 ;
V_25 = F_1 ( & V_17 -> V_1 , & V_17 -> V_3 , & V_12 -> V_4 ) ;
if ( V_25 )
goto V_70;
sprintf ( V_12 -> V_35 , L_20 , V_12 -> V_4 ) ;
V_25 =
F_64 ( & V_17 -> V_11 . V_94 , & V_45 -> V_11 . V_94 , V_12 -> V_35 ) ;
if ( V_25 )
goto F_7;
sprintf ( V_12 -> V_95 , L_21 , V_12 -> V_4 ) ;
F_48 ( & V_12 -> V_14 . V_14 ) ;
V_12 -> V_14 . V_14 . V_35 = V_12 -> V_95 ;
V_12 -> V_14 . V_14 . V_24 = 0444 ;
V_12 -> V_14 . V_73 = F_31 ;
V_25 = F_47 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
if ( V_25 )
goto V_96;
F_4 ( & V_17 -> V_3 ) ;
F_21 (pos, &tz->cooling_devices, node)
if ( V_90 -> V_17 == V_17 && V_90 -> V_33 == V_33 && V_90 -> V_45 == V_45 ) {
V_25 = - V_97 ;
break;
}
if ( ! V_25 )
F_49 ( & V_12 -> V_77 , & V_17 -> V_98 ) ;
F_6 ( & V_17 -> V_3 ) ;
if ( ! V_25 )
return 0 ;
F_50 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
V_96:
F_65 ( & V_17 -> V_11 . V_94 , V_12 -> V_35 ) ;
F_7:
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_12 -> V_4 ) ;
V_70:
F_51 ( V_12 ) ;
return V_25 ;
}
int F_23 ( struct V_16 * V_17 ,
int V_33 ,
struct V_44 * V_45 )
{
struct V_56 * V_90 , * V_99 ;
F_4 ( & V_17 -> V_3 ) ;
F_66 (pos, next, &tz->cooling_devices, node) {
if ( V_90 -> V_17 == V_17 && V_90 -> V_33 == V_33 && V_90 -> V_45 == V_45 ) {
F_55 ( & V_90 -> V_77 ) ;
F_6 ( & V_17 -> V_3 ) ;
goto V_100;
}
}
F_6 ( & V_17 -> V_3 ) ;
return - V_101 ;
V_100:
F_50 ( & V_17 -> V_11 , & V_90 -> V_14 ) ;
F_65 ( & V_17 -> V_11 . V_94 , V_90 -> V_35 ) ;
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_90 -> V_4 ) ;
F_51 ( V_90 ) ;
return 0 ;
}
static void F_67 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
struct V_44 * V_45 ;
if ( ! strncmp ( F_68 ( V_12 ) , L_22 ,
sizeof( L_22 ) - 1 ) ) {
V_17 = F_10 ( V_12 ) ;
F_51 ( V_17 ) ;
} else {
V_45 = F_27 ( V_12 ) ;
F_51 ( V_45 ) ;
}
}
struct V_44 *
F_69 ( char * type , void * V_102 ,
const struct V_103 * V_20 )
{
struct V_44 * V_45 ;
struct V_16 * V_90 ;
int V_25 ;
if ( strlen ( type ) >= V_69 )
return F_70 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_53 || ! V_20 -> V_54 ||
! V_20 -> V_55 )
return F_70 ( - V_31 ) ;
V_45 = F_40 ( sizeof( struct V_44 ) , V_7 ) ;
if ( ! V_45 )
return F_70 ( - V_8 ) ;
V_25 = F_1 ( & V_104 , & V_105 , & V_45 -> V_4 ) ;
if ( V_25 ) {
F_51 ( V_45 ) ;
return F_70 ( V_25 ) ;
}
strcpy ( V_45 -> type , type ) ;
V_45 -> V_20 = V_20 ;
V_45 -> V_11 . V_106 = & V_107 ;
V_45 -> V_102 = V_102 ;
F_71 ( & V_45 -> V_11 , L_23 , V_45 -> V_4 ) ;
V_25 = F_72 ( & V_45 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_104 , & V_105 , V_45 -> V_4 ) ;
F_51 ( V_45 ) ;
return F_70 ( V_25 ) ;
}
if ( type ) {
V_25 = F_47 ( & V_45 -> V_11 , & V_108 ) ;
if ( V_25 )
goto V_109;
}
V_25 = F_47 ( & V_45 -> V_11 , & V_110 ) ;
if ( V_25 )
goto V_109;
V_25 = F_47 ( & V_45 -> V_11 , & V_111 ) ;
if ( V_25 )
goto V_109;
F_4 ( & V_48 ) ;
F_73 ( & V_45 -> V_77 , & V_112 ) ;
F_21 (pos, &thermal_tz_list, node) {
if ( ! V_90 -> V_20 -> V_113 )
continue;
V_25 = V_90 -> V_20 -> V_113 ( V_90 , V_45 ) ;
if ( V_25 )
break;
}
F_6 ( & V_48 ) ;
if ( ! V_25 )
return V_45 ;
V_109:
F_7 ( & V_104 , & V_105 , V_45 -> V_4 ) ;
F_74 ( & V_45 -> V_11 ) ;
return F_70 ( V_25 ) ;
}
void F_75 ( struct
V_44
* V_45 )
{
struct V_16 * V_17 ;
struct V_44 * V_90 = NULL ;
if ( ! V_45 )
return;
F_4 ( & V_48 ) ;
F_21 (pos, &thermal_cdev_list, node)
if ( V_90 == V_45 )
break;
if ( V_90 != V_45 ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_45 -> V_77 ) ;
F_21 (tz, &thermal_tz_list, node) {
if ( ! V_17 -> V_20 -> V_100 )
continue;
V_17 -> V_20 -> V_100 ( V_17 , V_45 ) ;
}
F_6 ( & V_48 ) ;
if ( V_45 -> type [ 0 ] )
F_50 ( & V_45 -> V_11 , & V_108 ) ;
F_50 ( & V_45 -> V_11 , & V_110 ) ;
F_50 ( & V_45 -> V_11 , & V_111 ) ;
F_7 ( & V_104 , & V_105 , V_45 -> V_4 ) ;
F_74 ( & V_45 -> V_11 ) ;
return;
}
void F_24 ( struct V_16 * V_17 )
{
int V_28 , V_19 = 0 ;
long V_63 , V_83 ;
enum V_32 V_114 ;
struct V_56 * V_57 ;
struct V_44 * V_45 ;
F_4 ( & V_17 -> V_3 ) ;
if ( V_17 -> V_20 -> V_21 ( V_17 , & V_63 ) ) {
F_76 ( L_24 , V_17 -> V_4 ) ;
goto V_115;
}
for ( V_28 = 0 ; V_28 < V_17 -> V_93 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_114 ) ;
V_17 -> V_20 -> V_41 ( V_17 , V_28 , & V_83 ) ;
switch ( V_114 ) {
case V_36 :
if ( V_63 >= V_83 ) {
if ( V_17 -> V_20 -> V_116 )
V_19 = V_17 -> V_20 -> V_116 ( V_17 , V_28 ,
V_114 ) ;
if ( ! V_19 ) {
F_77 ( L_25 ,
V_63 / 1000 ) ;
F_78 ( true ) ;
}
}
break;
case V_37 :
if ( V_63 >= V_83 )
if ( V_17 -> V_20 -> V_116 )
V_17 -> V_20 -> V_116 ( V_17 , V_28 , V_114 ) ;
break;
case V_39 :
F_21 (instance, &tz->cooling_devices,
node) {
if ( V_57 -> V_33 != V_28 )
continue;
V_45 = V_57 -> V_45 ;
if ( V_63 >= V_83 )
V_45 -> V_20 -> V_55 ( V_45 , 1 ) ;
else
V_45 -> V_20 -> V_55 ( V_45 , 0 ) ;
}
break;
case V_38 :
if ( V_63 >= V_83 || V_17 -> V_86 )
F_62 ( V_17 , V_63 ,
V_83 , V_28 ) ;
break;
}
}
if ( V_17 -> V_47 )
F_62 ( V_17 , V_63 , V_17 -> V_47 ,
V_49 ) ;
V_17 -> V_87 = V_63 ;
V_115:
if ( V_17 -> V_86 )
F_57 ( V_17 , V_17 -> V_50 ) ;
else if ( V_17 -> V_117 )
F_57 ( V_17 , V_17 -> V_117 ) ;
else
F_57 ( V_17 , 0 ) ;
F_6 ( & V_17 -> V_3 ) ;
}
static int F_79 ( struct V_16 * V_17 , int V_118 )
{
int V_119 ;
int V_120 = sizeof( struct V_121 ) * V_17 -> V_93 ;
V_17 -> V_122 = F_40 ( V_120 , V_7 ) ;
if ( ! V_17 -> V_122 )
return - V_8 ;
V_17 -> V_123 = F_40 ( V_120 , V_7 ) ;
if ( ! V_17 -> V_123 ) {
F_51 ( V_17 -> V_122 ) ;
return - V_8 ;
}
if ( V_17 -> V_20 -> V_43 ) {
V_17 -> V_124 = F_40 ( V_120 , V_7 ) ;
if ( ! V_17 -> V_124 ) {
F_51 ( V_17 -> V_122 ) ;
F_51 ( V_17 -> V_123 ) ;
return - V_8 ;
}
}
for ( V_119 = 0 ; V_119 < V_17 -> V_93 ; V_119 ++ ) {
snprintf ( V_17 -> V_122 [ V_119 ] . V_35 , V_69 ,
L_5 , V_119 ) ;
F_48 ( & V_17 -> V_122 [ V_119 ] . V_14 . V_14 ) ;
V_17 -> V_122 [ V_119 ] . V_14 . V_14 . V_35 =
V_17 -> V_122 [ V_119 ] . V_35 ;
V_17 -> V_122 [ V_119 ] . V_14 . V_14 . V_24 = V_125 ;
V_17 -> V_122 [ V_119 ] . V_14 . V_73 = F_14 ;
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_122 [ V_119 ] . V_14 ) ;
snprintf ( V_17 -> V_123 [ V_119 ] . V_35 , V_69 ,
L_11 , V_119 ) ;
F_48 ( & V_17 -> V_123 [ V_119 ] . V_14 . V_14 ) ;
V_17 -> V_123 [ V_119 ] . V_14 . V_14 . V_35 =
V_17 -> V_123 [ V_119 ] . V_35 ;
V_17 -> V_123 [ V_119 ] . V_14 . V_14 . V_24 = V_125 ;
V_17 -> V_123 [ V_119 ] . V_14 . V_73 = F_17 ;
if ( V_118 & ( 1 << V_119 ) ) {
V_17 -> V_123 [ V_119 ] . V_14 . V_14 . V_24 |= V_126 ;
V_17 -> V_123 [ V_119 ] . V_14 . V_127 =
F_15 ;
}
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_123 [ V_119 ] . V_14 ) ;
if ( ! V_17 -> V_20 -> V_43 )
continue;
snprintf ( V_17 -> V_124 [ V_119 ] . V_35 , V_69 ,
L_12 , V_119 ) ;
F_48 ( & V_17 -> V_124 [ V_119 ] . V_14 . V_14 ) ;
V_17 -> V_124 [ V_119 ] . V_14 . V_14 . V_35 =
V_17 -> V_124 [ V_119 ] . V_35 ;
V_17 -> V_124 [ V_119 ] . V_14 . V_14 . V_24 = V_125 ;
V_17 -> V_124 [ V_119 ] . V_14 . V_73 = F_19 ;
if ( V_17 -> V_20 -> V_42 ) {
V_17 -> V_124 [ V_119 ] . V_14 . V_14 . V_24 |= V_126 ;
V_17 -> V_124 [ V_119 ] . V_14 . V_127 =
F_18 ;
}
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_124 [ V_119 ] . V_14 ) ;
}
return 0 ;
}
static void F_80 ( struct V_16 * V_17 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_17 -> V_93 ; V_119 ++ ) {
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_122 [ V_119 ] . V_14 ) ;
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_123 [ V_119 ] . V_14 ) ;
if ( V_17 -> V_20 -> V_43 )
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_124 [ V_119 ] . V_14 ) ;
}
F_51 ( V_17 -> V_122 ) ;
F_51 ( V_17 -> V_123 ) ;
F_51 ( V_17 -> V_124 ) ;
}
struct V_16 * F_81 ( const char * type ,
int V_93 , int V_118 , void * V_102 ,
const struct V_128 * V_20 ,
int V_51 , int V_52 , int V_50 , int V_117 )
{
struct V_16 * V_17 ;
struct V_44 * V_90 ;
enum V_32 V_114 ;
int V_25 ;
int V_28 ;
int V_86 = 0 ;
if ( strlen ( type ) >= V_69 )
return F_70 ( - V_31 ) ;
if ( V_93 > V_129 || V_93 < 0 || V_118 > > V_93 )
return F_70 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_21 )
return F_70 ( - V_31 ) ;
V_17 = F_40 ( sizeof( struct V_16 ) , V_7 ) ;
if ( ! V_17 )
return F_70 ( - V_8 ) ;
F_41 ( & V_17 -> V_98 ) ;
F_82 ( & V_17 -> V_1 ) ;
F_83 ( & V_17 -> V_3 ) ;
V_25 = F_1 ( & V_130 , & V_105 , & V_17 -> V_4 ) ;
if ( V_25 ) {
F_51 ( V_17 ) ;
return F_70 ( V_25 ) ;
}
strcpy ( V_17 -> type , type ) ;
V_17 -> V_20 = V_20 ;
V_17 -> V_11 . V_106 = & V_107 ;
V_17 -> V_102 = V_102 ;
V_17 -> V_93 = V_93 ;
V_17 -> V_51 = V_51 ;
V_17 -> V_52 = V_52 ;
V_17 -> V_50 = V_50 ;
V_17 -> V_117 = V_117 ;
F_71 ( & V_17 -> V_11 , L_26 , V_17 -> V_4 ) ;
V_25 = F_72 ( & V_17 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_130 , & V_105 , V_17 -> V_4 ) ;
F_51 ( V_17 ) ;
return F_70 ( V_25 ) ;
}
if ( type ) {
V_25 = F_47 ( & V_17 -> V_11 , & V_131 ) ;
if ( V_25 )
goto V_109;
}
V_25 = F_47 ( & V_17 -> V_11 , & V_132 ) ;
if ( V_25 )
goto V_109;
if ( V_20 -> V_26 ) {
V_25 = F_47 ( & V_17 -> V_11 , & V_133 ) ;
if ( V_25 )
goto V_109;
}
V_25 = F_79 ( V_17 , V_118 ) ;
if ( V_25 )
goto V_109;
for ( V_28 = 0 ; V_28 < V_93 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_114 ) ;
if ( V_114 == V_38 )
V_86 = 1 ;
}
if ( ! V_86 )
V_25 = F_47 ( & V_17 -> V_11 ,
& V_134 ) ;
if ( V_25 )
goto V_109;
V_25 = F_39 ( V_17 ) ;
if ( V_25 )
goto V_109;
F_4 ( & V_48 ) ;
F_49 ( & V_17 -> V_77 , & V_135 ) ;
if ( V_20 -> V_113 )
F_21 (pos, &thermal_cdev_list, node) {
V_25 = V_20 -> V_113 ( V_17 , V_90 ) ;
if ( V_25 )
break;
}
F_6 ( & V_48 ) ;
F_84 ( & ( V_17 -> V_81 ) , F_63 ) ;
F_24 ( V_17 ) ;
if ( ! V_25 )
return V_17 ;
V_109:
F_7 ( & V_130 , & V_105 , V_17 -> V_4 ) ;
F_74 ( & V_17 -> V_11 ) ;
return F_70 ( V_25 ) ;
}
void F_85 ( struct V_16 * V_17 )
{
struct V_44 * V_45 ;
struct V_16 * V_90 = NULL ;
if ( ! V_17 )
return;
F_4 ( & V_48 ) ;
F_21 (pos, &thermal_tz_list, node)
if ( V_90 == V_17 )
break;
if ( V_90 != V_17 ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_17 -> V_77 ) ;
if ( V_17 -> V_20 -> V_100 )
F_21 (cdev, &thermal_cdev_list, node)
V_17 -> V_20 -> V_100 ( V_17 , V_45 ) ;
F_6 ( & V_48 ) ;
F_57 ( V_17 , 0 ) ;
if ( V_17 -> type [ 0 ] )
F_50 ( & V_17 -> V_11 , & V_131 ) ;
F_50 ( & V_17 -> V_11 , & V_132 ) ;
if ( V_17 -> V_20 -> V_26 )
F_50 ( & V_17 -> V_11 , & V_133 ) ;
F_80 ( V_17 ) ;
F_53 ( V_17 ) ;
F_7 ( & V_130 , & V_105 , V_17 -> V_4 ) ;
F_86 ( & V_17 -> V_1 ) ;
F_87 ( & V_17 -> V_3 ) ;
F_74 ( & V_17 -> V_11 ) ;
return;
}
int F_88 ( T_3 V_136 , enum V_137 V_138 )
{
struct V_139 * V_140 ;
struct V_141 * V_14 ;
struct V_142 * V_143 ;
void * V_144 ;
int V_120 ;
int V_25 ;
static unsigned int V_145 ;
V_120 = F_89 ( sizeof( struct V_142 ) ) +
F_89 ( 0 ) ;
V_140 = F_90 ( V_120 , V_146 ) ;
if ( ! V_140 )
return - V_8 ;
V_144 = F_91 ( V_140 , 0 , V_145 ++ ,
& V_147 , 0 ,
V_148 ) ;
if ( ! V_144 ) {
F_92 ( V_140 ) ;
return - V_8 ;
}
V_14 = F_93 ( V_140 , V_149 ,
sizeof( struct V_142 ) ) ;
if ( ! V_14 ) {
F_92 ( V_140 ) ;
return - V_31 ;
}
V_143 = F_94 ( V_14 ) ;
if ( ! V_143 ) {
F_92 ( V_140 ) ;
return - V_31 ;
}
memset ( V_143 , 0 , sizeof( struct V_142 ) ) ;
V_143 -> V_136 = V_136 ;
V_143 -> V_138 = V_138 ;
V_25 = F_95 ( V_140 , V_144 ) ;
if ( V_25 < 0 ) {
F_92 ( V_140 ) ;
return V_25 ;
}
V_25 = F_96 ( V_140 , 0 , V_150 . V_4 , V_146 ) ;
if ( V_25 )
F_97 ( L_27 , V_25 ) ;
return V_25 ;
}
static int F_98 ( void )
{
int V_25 ;
V_25 = F_99 ( & V_147 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_100 ( & V_147 ,
& V_150 ) ;
if ( V_25 )
F_101 ( & V_147 ) ;
return V_25 ;
}
static void F_102 ( void )
{
F_101 ( & V_147 ) ;
}
static inline int F_98 ( void ) { return 0 ; }
static inline void F_102 ( void ) {}
static int T_4 F_103 ( void )
{
int V_25 = 0 ;
V_25 = F_104 ( & V_107 ) ;
if ( V_25 ) {
F_86 ( & V_130 ) ;
F_86 ( & V_104 ) ;
F_87 ( & V_105 ) ;
F_87 ( & V_48 ) ;
}
V_25 = F_98 () ;
return V_25 ;
}
static void T_5 F_105 ( void )
{
F_106 ( & V_107 ) ;
F_86 ( & V_130 ) ;
F_86 ( & V_104 ) ;
F_87 ( & V_105 ) ;
F_87 ( & V_48 ) ;
F_102 () ;
}
