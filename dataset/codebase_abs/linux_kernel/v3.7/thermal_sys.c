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
V_49 , V_45 ,
V_50 ,
V_50 ) ;
}
F_6 ( & V_48 ) ;
if ( ! V_17 -> V_51 )
V_17 -> V_51 = 1000 ;
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
V_17 -> V_51 = 0 ;
}
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
V_19 = V_45 -> V_20 -> V_52 ( V_45 , & V_46 ) ;
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
V_19 = V_45 -> V_20 -> V_53 ( V_45 , & V_46 ) ;
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
V_25 = V_45 -> V_20 -> V_54 ( V_45 , V_46 ) ;
if ( V_25 )
return V_25 ;
return V_28 ;
}
static T_1
F_31 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_55 * V_56 ;
V_56 =
F_32 ( V_14 , struct V_55 , V_14 ) ;
if ( V_56 -> V_33 == V_49 )
return sprintf ( V_15 , L_15 ) ;
else
return sprintf ( V_15 , L_13 , V_56 -> V_33 ) ;
}
static T_1
F_33 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_57 * V_58 = F_34 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_58 -> type ) ;
}
static T_1
F_35 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
long V_18 ;
int V_19 ;
struct V_59 * V_60
= F_32 ( V_14 , struct V_59 , V_14 ) ;
struct V_61 * V_62
= F_32 ( V_60 , struct V_61 ,
V_63 ) ;
struct V_16 * V_17 = V_62 -> V_17 ;
V_19 = V_17 -> V_20 -> V_21 ( V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_36 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_59 * V_60
= F_32 ( V_14 , struct V_59 , V_14 ) ;
struct V_61 * V_62
= F_32 ( V_60 , struct V_61 ,
V_64 ) ;
struct V_16 * V_17 = V_62 -> V_17 ;
long V_18 ;
int V_19 ;
V_19 = V_17 -> V_20 -> V_41 ( V_17 , 0 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static struct V_57 *
F_37 ( const struct V_16 * V_17 )
{
struct V_57 * V_58 ;
F_4 ( & V_48 ) ;
F_21 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_58 -> type , V_17 -> type ) ) {
F_6 ( & V_48 ) ;
return V_58 ;
}
F_6 ( & V_48 ) ;
return NULL ;
}
static struct V_61 *
F_38 ( const struct V_57 * V_58 ,
const struct V_16 * V_17 )
{
struct V_61 * V_62 ;
F_4 ( & V_48 ) ;
F_21 (temp, &hwmon->tz_list, hwmon_node)
if ( V_62 -> V_17 == V_17 ) {
F_6 ( & V_48 ) ;
return V_62 ;
}
F_6 ( & V_48 ) ;
return NULL ;
}
static int
F_39 ( struct V_16 * V_17 )
{
struct V_57 * V_58 ;
struct V_61 * V_62 ;
int V_65 = 1 ;
int V_25 ;
V_58 = F_37 ( V_17 ) ;
if ( V_58 ) {
V_65 = 0 ;
goto V_66;
}
V_58 = F_40 ( sizeof( struct V_57 ) , V_7 ) ;
if ( ! V_58 )
return - V_8 ;
F_41 ( & V_58 -> V_67 ) ;
F_42 ( V_58 -> type , V_17 -> type , V_68 ) ;
V_58 -> V_11 = F_43 ( NULL ) ;
if ( F_44 ( V_58 -> V_11 ) ) {
V_25 = F_45 ( V_58 -> V_11 ) ;
goto V_69;
}
F_46 ( V_58 -> V_11 , V_58 ) ;
V_25 = F_47 ( V_58 -> V_11 , & V_70 ) ;
if ( V_25 )
goto V_69;
V_66:
V_62 = F_40 ( sizeof( struct V_61 ) , V_7 ) ;
if ( ! V_62 ) {
V_25 = - V_8 ;
goto V_71;
}
V_62 -> V_17 = V_17 ;
V_58 -> V_28 ++ ;
snprintf ( V_62 -> V_63 . V_35 , sizeof( V_62 -> V_63 . V_35 ) ,
L_16 , V_58 -> V_28 ) ;
V_62 -> V_63 . V_14 . V_14 . V_35 = V_62 -> V_63 . V_35 ;
V_62 -> V_63 . V_14 . V_14 . V_24 = 0444 ;
V_62 -> V_63 . V_14 . V_72 = F_35 ;
F_48 ( & V_62 -> V_63 . V_14 . V_14 ) ;
V_25 = F_47 ( V_58 -> V_11 , & V_62 -> V_63 . V_14 ) ;
if ( V_25 )
goto V_73;
if ( V_17 -> V_20 -> V_74 ) {
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_74 ( V_17 , & V_18 ) ) {
snprintf ( V_62 -> V_64 . V_35 ,
sizeof( V_62 -> V_64 . V_35 ) ,
L_17 , V_58 -> V_28 ) ;
V_62 -> V_64 . V_14 . V_14 . V_35 = V_62 -> V_64 . V_35 ;
V_62 -> V_64 . V_14 . V_14 . V_24 = 0444 ;
V_62 -> V_64 . V_14 . V_72 = F_36 ;
F_48 ( & V_62 -> V_64 . V_14 . V_14 ) ;
V_25 = F_47 ( V_58 -> V_11 ,
& V_62 -> V_64 . V_14 ) ;
if ( V_25 )
goto V_75;
}
}
F_4 ( & V_48 ) ;
if ( V_65 )
F_49 ( & V_58 -> V_76 , & V_77 ) ;
F_49 ( & V_62 -> V_78 , & V_58 -> V_67 ) ;
F_6 ( & V_48 ) ;
return 0 ;
V_75:
F_50 ( V_58 -> V_11 , & V_62 -> V_63 . V_14 ) ;
V_73:
F_51 ( V_62 ) ;
V_71:
if ( V_65 ) {
F_50 ( V_58 -> V_11 , & V_70 ) ;
F_52 ( V_58 -> V_11 ) ;
}
V_69:
if ( V_65 )
F_51 ( V_58 ) ;
return V_25 ;
}
static void
F_53 ( struct V_16 * V_17 )
{
struct V_57 * V_58 ;
struct V_61 * V_62 ;
V_58 = F_37 ( V_17 ) ;
if ( F_2 ( ! V_58 ) ) {
F_54 ( & V_17 -> V_11 , L_18 ) ;
return;
}
V_62 = F_38 ( V_58 , V_17 ) ;
if ( F_2 ( ! V_62 ) ) {
F_54 ( & V_17 -> V_11 , L_19 ) ;
return;
}
F_50 ( V_58 -> V_11 , & V_62 -> V_63 . V_14 ) ;
if ( V_17 -> V_20 -> V_74 )
F_50 ( V_58 -> V_11 , & V_62 -> V_64 . V_14 ) ;
F_4 ( & V_48 ) ;
F_55 ( & V_62 -> V_78 ) ;
F_51 ( V_62 ) ;
if ( ! F_56 ( & V_58 -> V_67 ) ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_58 -> V_76 ) ;
F_6 ( & V_48 ) ;
F_50 ( V_58 -> V_11 , & V_70 ) ;
F_52 ( V_58 -> V_11 ) ;
F_51 ( V_58 ) ;
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
int V_79 )
{
if ( V_79 > 1000 )
F_58 ( V_80 , & V_17 -> V_81 ,
F_59 ( F_60 ( V_79 ) ) ) ;
else if ( V_79 )
F_58 ( V_80 , & V_17 -> V_81 ,
F_60 ( V_79 ) ) ;
else
F_61 ( & V_17 -> V_81 ) ;
}
static void F_62 ( struct V_82 * V_83 )
{
struct V_16 * V_17 = F_32 ( V_83 , struct
V_16 ,
V_81 . V_83 ) ;
F_24 ( V_17 ) ;
}
int F_22 ( struct V_16 * V_17 ,
int V_33 ,
struct V_44 * V_45 ,
unsigned long V_84 , unsigned long V_85 )
{
struct V_55 * V_12 ;
struct V_55 * V_86 ;
struct V_16 * V_87 ;
struct V_44 * V_88 ;
unsigned long V_89 ;
int V_25 ;
if ( V_33 >= V_17 -> V_90 || ( V_33 < 0 && V_33 != V_49 ) )
return - V_31 ;
F_21 (pos1, &thermal_tz_list, node) {
if ( V_87 == V_17 )
break;
}
F_21 (pos2, &thermal_cdev_list, node) {
if ( V_88 == V_45 )
break;
}
if ( V_17 != V_87 || V_45 != V_88 )
return - V_31 ;
V_45 -> V_20 -> V_52 ( V_45 , & V_89 ) ;
V_85 = V_85 == V_50 ? 0 : V_85 ;
V_84 = V_84 == V_50 ? V_89 : V_84 ;
if ( V_85 > V_84 || V_84 > V_89 )
return - V_31 ;
V_12 =
F_40 ( sizeof( struct V_55 ) , V_7 ) ;
if ( ! V_12 )
return - V_8 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_45 = V_45 ;
V_12 -> V_33 = V_33 ;
V_12 -> V_84 = V_84 ;
V_12 -> V_85 = V_85 ;
V_12 -> V_91 = V_92 ;
V_25 = F_1 ( & V_17 -> V_1 , & V_17 -> V_3 , & V_12 -> V_4 ) ;
if ( V_25 )
goto V_69;
sprintf ( V_12 -> V_35 , L_20 , V_12 -> V_4 ) ;
V_25 =
F_63 ( & V_17 -> V_11 . V_93 , & V_45 -> V_11 . V_93 , V_12 -> V_35 ) ;
if ( V_25 )
goto F_7;
sprintf ( V_12 -> V_94 , L_21 , V_12 -> V_4 ) ;
F_48 ( & V_12 -> V_14 . V_14 ) ;
V_12 -> V_14 . V_14 . V_35 = V_12 -> V_94 ;
V_12 -> V_14 . V_14 . V_24 = 0444 ;
V_12 -> V_14 . V_72 = F_31 ;
V_25 = F_47 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
if ( V_25 )
goto V_95;
F_4 ( & V_17 -> V_3 ) ;
F_4 ( & V_45 -> V_3 ) ;
F_21 (pos, &tz->thermal_instances, tz_node)
if ( V_86 -> V_17 == V_17 && V_86 -> V_33 == V_33 && V_86 -> V_45 == V_45 ) {
V_25 = - V_96 ;
break;
}
if ( ! V_25 ) {
F_49 ( & V_12 -> V_97 , & V_17 -> V_98 ) ;
F_49 ( & V_12 -> V_99 , & V_45 -> V_98 ) ;
}
F_6 ( & V_45 -> V_3 ) ;
F_6 ( & V_17 -> V_3 ) ;
if ( ! V_25 )
return 0 ;
F_50 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
V_95:
F_64 ( & V_17 -> V_11 . V_93 , V_12 -> V_35 ) ;
F_7:
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_12 -> V_4 ) ;
V_69:
F_51 ( V_12 ) ;
return V_25 ;
}
int F_23 ( struct V_16 * V_17 ,
int V_33 ,
struct V_44 * V_45 )
{
struct V_55 * V_86 , * V_100 ;
F_4 ( & V_17 -> V_3 ) ;
F_4 ( & V_45 -> V_3 ) ;
F_65 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_86 -> V_17 == V_17 && V_86 -> V_33 == V_33 && V_86 -> V_45 == V_45 ) {
F_55 ( & V_86 -> V_97 ) ;
F_55 ( & V_86 -> V_99 ) ;
F_6 ( & V_45 -> V_3 ) ;
F_6 ( & V_17 -> V_3 ) ;
goto V_101;
}
}
F_6 ( & V_45 -> V_3 ) ;
F_6 ( & V_17 -> V_3 ) ;
return - V_102 ;
V_101:
F_50 ( & V_17 -> V_11 , & V_86 -> V_14 ) ;
F_64 ( & V_17 -> V_11 . V_93 , V_86 -> V_35 ) ;
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_86 -> V_4 ) ;
F_51 ( V_86 ) ;
return 0 ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
struct V_44 * V_45 ;
if ( ! strncmp ( F_67 ( V_12 ) , L_22 ,
sizeof( L_22 ) - 1 ) ) {
V_17 = F_10 ( V_12 ) ;
F_51 ( V_17 ) ;
} else {
V_45 = F_27 ( V_12 ) ;
F_51 ( V_45 ) ;
}
}
struct V_44 *
F_68 ( char * type , void * V_103 ,
const struct V_104 * V_20 )
{
struct V_44 * V_45 ;
struct V_16 * V_86 ;
int V_25 ;
if ( type && strlen ( type ) >= V_68 )
return F_69 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_52 || ! V_20 -> V_53 ||
! V_20 -> V_54 )
return F_69 ( - V_31 ) ;
V_45 = F_40 ( sizeof( struct V_44 ) , V_7 ) ;
if ( ! V_45 )
return F_69 ( - V_8 ) ;
V_25 = F_1 ( & V_105 , & V_106 , & V_45 -> V_4 ) ;
if ( V_25 ) {
F_51 ( V_45 ) ;
return F_69 ( V_25 ) ;
}
strcpy ( V_45 -> type , type ? : L_23 ) ;
F_70 ( & V_45 -> V_3 ) ;
F_41 ( & V_45 -> V_98 ) ;
V_45 -> V_20 = V_20 ;
V_45 -> V_107 = true ;
V_45 -> V_11 . V_108 = & V_109 ;
V_45 -> V_103 = V_103 ;
F_71 ( & V_45 -> V_11 , L_24 , V_45 -> V_4 ) ;
V_25 = F_72 ( & V_45 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_105 , & V_106 , V_45 -> V_4 ) ;
F_51 ( V_45 ) ;
return F_69 ( V_25 ) ;
}
if ( type ) {
V_25 = F_47 ( & V_45 -> V_11 , & V_110 ) ;
if ( V_25 )
goto V_111;
}
V_25 = F_47 ( & V_45 -> V_11 , & V_112 ) ;
if ( V_25 )
goto V_111;
V_25 = F_47 ( & V_45 -> V_11 , & V_113 ) ;
if ( V_25 )
goto V_111;
F_4 ( & V_48 ) ;
F_73 ( & V_45 -> V_76 , & V_114 ) ;
F_21 (pos, &thermal_tz_list, node) {
if ( ! V_86 -> V_20 -> V_115 )
continue;
V_25 = V_86 -> V_20 -> V_115 ( V_86 , V_45 ) ;
if ( V_25 )
break;
}
F_6 ( & V_48 ) ;
if ( ! V_25 )
return V_45 ;
V_111:
F_7 ( & V_105 , & V_106 , V_45 -> V_4 ) ;
F_74 ( & V_45 -> V_11 ) ;
return F_69 ( V_25 ) ;
}
void F_75 ( struct
V_44
* V_45 )
{
struct V_16 * V_17 ;
struct V_44 * V_86 = NULL ;
if ( ! V_45 )
return;
F_4 ( & V_48 ) ;
F_21 (pos, &thermal_cdev_list, node)
if ( V_86 == V_45 )
break;
if ( V_86 != V_45 ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_45 -> V_76 ) ;
F_21 (tz, &thermal_tz_list, node) {
if ( ! V_17 -> V_20 -> V_101 )
continue;
V_17 -> V_20 -> V_101 ( V_17 , V_45 ) ;
}
F_6 ( & V_48 ) ;
if ( V_45 -> type [ 0 ] )
F_50 ( & V_45 -> V_11 , & V_110 ) ;
F_50 ( & V_45 -> V_11 , & V_112 ) ;
F_50 ( & V_45 -> V_11 , & V_113 ) ;
F_7 ( & V_105 , & V_106 , V_45 -> V_4 ) ;
F_74 ( & V_45 -> V_11 ) ;
return;
}
static void F_76 ( struct V_44 * V_45 )
{
struct V_55 * V_56 ;
unsigned long V_91 = 0 ;
if ( V_45 -> V_107 )
return;
F_4 ( & V_45 -> V_3 ) ;
F_21 (instance, &cdev->thermal_instances, cdev_node) {
if ( V_56 -> V_91 == V_92 )
continue;
if ( V_56 -> V_91 > V_91 )
V_91 = V_56 -> V_91 ;
}
F_6 ( & V_45 -> V_3 ) ;
V_45 -> V_20 -> V_54 ( V_45 , V_91 ) ;
V_45 -> V_107 = true ;
}
static void F_77 ( struct V_16 * V_17 )
{
struct V_55 * V_56 ;
F_21 (instance, &tz->thermal_instances, tz_node)
F_76 ( V_56 -> V_45 ) ;
}
static void F_78 ( struct V_16 * V_17 ,
int V_33 , long V_62 )
{
struct V_55 * V_56 ;
struct V_44 * V_45 = NULL ;
unsigned long V_116 , V_89 ;
long V_117 ;
enum V_32 V_118 ;
enum V_119 V_120 ;
if ( V_33 == V_49 ) {
V_117 = V_17 -> V_47 ;
V_118 = V_49 ;
} else {
V_17 -> V_20 -> V_41 ( V_17 , V_33 , & V_117 ) ;
V_17 -> V_20 -> V_34 ( V_17 , V_33 , & V_118 ) ;
}
if ( ! V_17 -> V_20 -> V_121 || V_17 -> V_20 -> V_121 ( V_17 , V_33 , & V_120 ) ) {
if ( V_17 -> V_18 > V_17 -> V_122 )
V_120 = V_123 ;
else if ( V_17 -> V_18 < V_17 -> V_122 )
V_120 = V_124 ;
else
V_120 = V_125 ;
}
if ( V_62 >= V_117 ) {
F_21 (instance, &tz->thermal_instances, tz_node) {
if ( V_56 -> V_33 != V_33 )
continue;
V_45 = V_56 -> V_45 ;
V_45 -> V_20 -> V_53 ( V_45 , & V_116 ) ;
V_45 -> V_20 -> V_52 ( V_45 , & V_89 ) ;
if ( V_120 == V_123 ) {
V_116 = V_116 < V_56 -> V_84 ?
( V_116 + 1 ) : V_56 -> V_84 ;
} else if ( V_120 == V_124 ) {
V_116 = V_116 > V_56 -> V_85 ?
( V_116 - 1 ) : V_56 -> V_85 ;
}
if ( ( V_118 == V_38 ||
V_118 == V_49 ) &&
V_56 -> V_91 == V_92 )
V_17 -> V_126 ++ ;
V_56 -> V_91 = V_116 ;
V_45 -> V_107 = false ;
}
} else {
F_21 (instance, &tz->thermal_instances, tz_node) {
if ( V_56 -> V_33 != V_33 )
continue;
if ( V_56 -> V_91 == V_92 )
continue;
V_45 = V_56 -> V_45 ;
V_45 -> V_20 -> V_53 ( V_45 , & V_116 ) ;
V_116 = V_116 > V_56 -> V_85 ?
( V_116 - 1 ) : V_92 ;
if ( ( V_118 == V_38 ||
V_118 == V_49 ) &&
V_116 == V_92 )
V_17 -> V_126 -- ;
V_56 -> V_91 = V_116 ;
V_45 -> V_107 = false ;
}
}
return;
}
void F_24 ( struct V_16 * V_17 )
{
int V_28 , V_19 = 0 ;
long V_62 , V_117 ;
enum V_32 V_118 ;
F_4 ( & V_17 -> V_3 ) ;
if ( V_17 -> V_20 -> V_21 ( V_17 , & V_62 ) ) {
F_79 ( L_25 , V_17 -> V_4 ) ;
goto V_127;
}
V_17 -> V_122 = V_17 -> V_18 ;
V_17 -> V_18 = V_62 ;
for ( V_28 = 0 ; V_28 < V_17 -> V_90 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_118 ) ;
V_17 -> V_20 -> V_41 ( V_17 , V_28 , & V_117 ) ;
switch ( V_118 ) {
case V_36 :
if ( V_62 >= V_117 ) {
if ( V_17 -> V_20 -> V_128 )
V_19 = V_17 -> V_20 -> V_128 ( V_17 , V_28 ,
V_118 ) ;
if ( ! V_19 ) {
F_80 ( L_26 ,
V_62 / 1000 ) ;
F_81 ( true ) ;
}
}
break;
case V_37 :
if ( V_62 >= V_117 )
if ( V_17 -> V_20 -> V_128 )
V_17 -> V_20 -> V_128 ( V_17 , V_28 , V_118 ) ;
break;
case V_39 :
F_78 ( V_17 , V_28 , V_62 ) ;
break;
case V_38 :
if ( V_62 >= V_117 || V_17 -> V_126 )
F_78 ( V_17 , V_28 , V_62 ) ;
break;
}
}
if ( V_17 -> V_47 )
F_78 ( V_17 , V_49 , V_62 ) ;
F_77 ( V_17 ) ;
V_127:
if ( V_17 -> V_126 )
F_57 ( V_17 , V_17 -> V_51 ) ;
else if ( V_17 -> V_129 )
F_57 ( V_17 , V_17 -> V_129 ) ;
else
F_57 ( V_17 , 0 ) ;
F_6 ( & V_17 -> V_3 ) ;
}
static int F_82 ( struct V_16 * V_17 , int V_130 )
{
int V_131 ;
int V_132 = sizeof( struct V_133 ) * V_17 -> V_90 ;
V_17 -> V_134 = F_40 ( V_132 , V_7 ) ;
if ( ! V_17 -> V_134 )
return - V_8 ;
V_17 -> V_135 = F_40 ( V_132 , V_7 ) ;
if ( ! V_17 -> V_135 ) {
F_51 ( V_17 -> V_134 ) ;
return - V_8 ;
}
if ( V_17 -> V_20 -> V_43 ) {
V_17 -> V_136 = F_40 ( V_132 , V_7 ) ;
if ( ! V_17 -> V_136 ) {
F_51 ( V_17 -> V_134 ) ;
F_51 ( V_17 -> V_135 ) ;
return - V_8 ;
}
}
for ( V_131 = 0 ; V_131 < V_17 -> V_90 ; V_131 ++ ) {
snprintf ( V_17 -> V_134 [ V_131 ] . V_35 , V_68 ,
L_5 , V_131 ) ;
F_48 ( & V_17 -> V_134 [ V_131 ] . V_14 . V_14 ) ;
V_17 -> V_134 [ V_131 ] . V_14 . V_14 . V_35 =
V_17 -> V_134 [ V_131 ] . V_35 ;
V_17 -> V_134 [ V_131 ] . V_14 . V_14 . V_24 = V_137 ;
V_17 -> V_134 [ V_131 ] . V_14 . V_72 = F_14 ;
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_134 [ V_131 ] . V_14 ) ;
snprintf ( V_17 -> V_135 [ V_131 ] . V_35 , V_68 ,
L_11 , V_131 ) ;
F_48 ( & V_17 -> V_135 [ V_131 ] . V_14 . V_14 ) ;
V_17 -> V_135 [ V_131 ] . V_14 . V_14 . V_35 =
V_17 -> V_135 [ V_131 ] . V_35 ;
V_17 -> V_135 [ V_131 ] . V_14 . V_14 . V_24 = V_137 ;
V_17 -> V_135 [ V_131 ] . V_14 . V_72 = F_17 ;
if ( V_130 & ( 1 << V_131 ) ) {
V_17 -> V_135 [ V_131 ] . V_14 . V_14 . V_24 |= V_138 ;
V_17 -> V_135 [ V_131 ] . V_14 . V_139 =
F_15 ;
}
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_135 [ V_131 ] . V_14 ) ;
if ( ! V_17 -> V_20 -> V_43 )
continue;
snprintf ( V_17 -> V_136 [ V_131 ] . V_35 , V_68 ,
L_12 , V_131 ) ;
F_48 ( & V_17 -> V_136 [ V_131 ] . V_14 . V_14 ) ;
V_17 -> V_136 [ V_131 ] . V_14 . V_14 . V_35 =
V_17 -> V_136 [ V_131 ] . V_35 ;
V_17 -> V_136 [ V_131 ] . V_14 . V_14 . V_24 = V_137 ;
V_17 -> V_136 [ V_131 ] . V_14 . V_72 = F_19 ;
if ( V_17 -> V_20 -> V_42 ) {
V_17 -> V_136 [ V_131 ] . V_14 . V_14 . V_24 |= V_138 ;
V_17 -> V_136 [ V_131 ] . V_14 . V_139 =
F_18 ;
}
F_47 ( & V_17 -> V_11 ,
& V_17 -> V_136 [ V_131 ] . V_14 ) ;
}
return 0 ;
}
static void F_83 ( struct V_16 * V_17 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_17 -> V_90 ; V_131 ++ ) {
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_134 [ V_131 ] . V_14 ) ;
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_135 [ V_131 ] . V_14 ) ;
if ( V_17 -> V_20 -> V_43 )
F_50 ( & V_17 -> V_11 ,
& V_17 -> V_136 [ V_131 ] . V_14 ) ;
}
F_51 ( V_17 -> V_134 ) ;
F_51 ( V_17 -> V_135 ) ;
F_51 ( V_17 -> V_136 ) ;
}
struct V_16 * F_84 ( const char * type ,
int V_90 , int V_130 , void * V_103 ,
const struct V_140 * V_20 ,
int V_51 , int V_129 )
{
struct V_16 * V_17 ;
struct V_44 * V_86 ;
enum V_32 V_118 ;
int V_25 ;
int V_28 ;
int V_126 = 0 ;
if ( type && strlen ( type ) >= V_68 )
return F_69 ( - V_31 ) ;
if ( V_90 > V_141 || V_90 < 0 || V_130 > > V_90 )
return F_69 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_21 )
return F_69 ( - V_31 ) ;
V_17 = F_40 ( sizeof( struct V_16 ) , V_7 ) ;
if ( ! V_17 )
return F_69 ( - V_8 ) ;
F_41 ( & V_17 -> V_98 ) ;
F_85 ( & V_17 -> V_1 ) ;
F_70 ( & V_17 -> V_3 ) ;
V_25 = F_1 ( & V_142 , & V_106 , & V_17 -> V_4 ) ;
if ( V_25 ) {
F_51 ( V_17 ) ;
return F_69 ( V_25 ) ;
}
strcpy ( V_17 -> type , type ? : L_23 ) ;
V_17 -> V_20 = V_20 ;
V_17 -> V_11 . V_108 = & V_109 ;
V_17 -> V_103 = V_103 ;
V_17 -> V_90 = V_90 ;
V_17 -> V_51 = V_51 ;
V_17 -> V_129 = V_129 ;
F_71 ( & V_17 -> V_11 , L_27 , V_17 -> V_4 ) ;
V_25 = F_72 ( & V_17 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_142 , & V_106 , V_17 -> V_4 ) ;
F_51 ( V_17 ) ;
return F_69 ( V_25 ) ;
}
if ( type ) {
V_25 = F_47 ( & V_17 -> V_11 , & V_143 ) ;
if ( V_25 )
goto V_111;
}
V_25 = F_47 ( & V_17 -> V_11 , & V_144 ) ;
if ( V_25 )
goto V_111;
if ( V_20 -> V_26 ) {
V_25 = F_47 ( & V_17 -> V_11 , & V_145 ) ;
if ( V_25 )
goto V_111;
}
V_25 = F_82 ( V_17 , V_130 ) ;
if ( V_25 )
goto V_111;
for ( V_28 = 0 ; V_28 < V_90 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_118 ) ;
if ( V_118 == V_38 )
V_126 = 1 ;
}
if ( ! V_126 )
V_25 = F_47 ( & V_17 -> V_11 ,
& V_146 ) ;
if ( V_25 )
goto V_111;
V_25 = F_39 ( V_17 ) ;
if ( V_25 )
goto V_111;
F_4 ( & V_48 ) ;
F_49 ( & V_17 -> V_76 , & V_147 ) ;
if ( V_20 -> V_115 )
F_21 (pos, &thermal_cdev_list, node) {
V_25 = V_20 -> V_115 ( V_17 , V_86 ) ;
if ( V_25 )
break;
}
F_6 ( & V_48 ) ;
F_86 ( & ( V_17 -> V_81 ) , F_62 ) ;
F_24 ( V_17 ) ;
if ( ! V_25 )
return V_17 ;
V_111:
F_7 ( & V_142 , & V_106 , V_17 -> V_4 ) ;
F_74 ( & V_17 -> V_11 ) ;
return F_69 ( V_25 ) ;
}
void F_87 ( struct V_16 * V_17 )
{
struct V_44 * V_45 ;
struct V_16 * V_86 = NULL ;
if ( ! V_17 )
return;
F_4 ( & V_48 ) ;
F_21 (pos, &thermal_tz_list, node)
if ( V_86 == V_17 )
break;
if ( V_86 != V_17 ) {
F_6 ( & V_48 ) ;
return;
}
F_55 ( & V_17 -> V_76 ) ;
if ( V_17 -> V_20 -> V_101 )
F_21 (cdev, &thermal_cdev_list, node)
V_17 -> V_20 -> V_101 ( V_17 , V_45 ) ;
F_6 ( & V_48 ) ;
F_57 ( V_17 , 0 ) ;
if ( V_17 -> type [ 0 ] )
F_50 ( & V_17 -> V_11 , & V_143 ) ;
F_50 ( & V_17 -> V_11 , & V_144 ) ;
if ( V_17 -> V_20 -> V_26 )
F_50 ( & V_17 -> V_11 , & V_145 ) ;
F_83 ( V_17 ) ;
F_53 ( V_17 ) ;
F_7 ( & V_142 , & V_106 , V_17 -> V_4 ) ;
F_88 ( & V_17 -> V_1 ) ;
F_89 ( & V_17 -> V_3 ) ;
F_74 ( & V_17 -> V_11 ) ;
return;
}
int F_90 ( T_3 V_148 , enum V_149 V_150 )
{
struct V_151 * V_152 ;
struct V_153 * V_14 ;
struct V_154 * V_155 ;
void * V_156 ;
int V_132 ;
int V_25 ;
static unsigned int V_157 ;
V_132 = F_91 ( sizeof( struct V_154 ) ) +
F_91 ( 0 ) ;
V_152 = F_92 ( V_132 , V_158 ) ;
if ( ! V_152 )
return - V_8 ;
V_156 = F_93 ( V_152 , 0 , V_157 ++ ,
& V_159 , 0 ,
V_160 ) ;
if ( ! V_156 ) {
F_94 ( V_152 ) ;
return - V_8 ;
}
V_14 = F_95 ( V_152 , V_161 ,
sizeof( struct V_154 ) ) ;
if ( ! V_14 ) {
F_94 ( V_152 ) ;
return - V_31 ;
}
V_155 = F_96 ( V_14 ) ;
if ( ! V_155 ) {
F_94 ( V_152 ) ;
return - V_31 ;
}
memset ( V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 -> V_148 = V_148 ;
V_155 -> V_150 = V_150 ;
V_25 = F_97 ( V_152 , V_156 ) ;
if ( V_25 < 0 ) {
F_94 ( V_152 ) ;
return V_25 ;
}
V_25 = F_98 ( V_152 , 0 , V_162 . V_4 , V_158 ) ;
if ( V_25 )
F_99 ( L_28 , V_25 ) ;
return V_25 ;
}
static int F_100 ( void )
{
int V_25 ;
V_25 = F_101 ( & V_159 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_102 ( & V_159 ,
& V_162 ) ;
if ( V_25 )
F_103 ( & V_159 ) ;
return V_25 ;
}
static void F_104 ( void )
{
F_103 ( & V_159 ) ;
}
static inline int F_100 ( void ) { return 0 ; }
static inline void F_104 ( void ) {}
static int T_4 F_105 ( void )
{
int V_25 = 0 ;
V_25 = F_106 ( & V_109 ) ;
if ( V_25 ) {
F_88 ( & V_142 ) ;
F_88 ( & V_105 ) ;
F_89 ( & V_106 ) ;
F_89 ( & V_48 ) ;
}
V_25 = F_100 () ;
return V_25 ;
}
static void T_5 F_107 ( void )
{
F_108 ( & V_109 ) ;
F_88 ( & V_142 ) ;
F_88 ( & V_105 ) ;
F_89 ( & V_106 ) ;
F_89 ( & V_48 ) ;
F_104 () ;
}
