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
if ( ! strncmp ( V_15 , L_3 , sizeof( L_3 ) ) )
V_25 = V_17 -> V_20 -> V_29 ( V_17 , V_27 ) ;
else if ( ! strncmp ( V_15 , L_4 , sizeof( L_4 ) ) )
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
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
int V_33 , V_19 ;
long V_18 ;
if ( ! V_17 -> V_20 -> V_40 )
return - V_22 ;
if ( ! sscanf ( V_14 -> V_14 . V_35 , L_11 , & V_33 ) )
return - V_31 ;
V_19 = V_17 -> V_20 -> V_40 ( V_17 , V_33 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_16 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
struct V_41 * V_42 = NULL ;
int V_43 ;
if ( ! sscanf ( V_15 , L_12 , & V_43 ) )
return - V_31 ;
if ( V_43 && V_43 < 1000 )
return - V_31 ;
if ( V_43 && ! V_17 -> V_44 ) {
F_4 ( & V_45 ) ;
F_17 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_13 , V_42 -> type ,
sizeof( L_13 ) ) )
F_18 ( V_17 ,
V_46 ,
V_42 ) ;
}
F_6 ( & V_45 ) ;
if ( ! V_17 -> V_47 )
V_17 -> V_47 = 1000 ;
} else if ( ! V_43 && V_17 -> V_44 ) {
F_4 ( & V_45 ) ;
F_17 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_13 , V_42 -> type ,
sizeof( L_13 ) ) )
F_19 ( V_17 ,
V_46 ,
V_42 ) ;
}
F_6 ( & V_45 ) ;
V_17 -> V_47 = 0 ;
}
V_17 -> V_48 = 1 ;
V_17 -> V_49 = 1 ;
V_17 -> V_44 = V_43 ;
F_20 ( V_17 ) ;
return V_28 ;
}
static T_1
F_21 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_10 ( V_12 ) ;
return sprintf ( V_15 , L_12 , V_17 -> V_44 ) ;
}
static T_1
F_22 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_41 * V_42 = F_23 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_42 -> type ) ;
}
static T_1
F_24 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_41 * V_42 = F_23 ( V_12 ) ;
unsigned long V_43 ;
int V_19 ;
V_19 = V_42 -> V_20 -> V_50 ( V_42 , & V_43 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_43 ) ;
}
static T_1
F_25 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_41 * V_42 = F_23 ( V_12 ) ;
unsigned long V_43 ;
int V_19 ;
V_19 = V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_43 ) ;
}
static T_1
F_26 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_28 )
{
struct V_41 * V_42 = F_23 ( V_12 ) ;
unsigned long V_43 ;
int V_25 ;
if ( ! sscanf ( V_15 , L_2 , & V_43 ) )
return - V_31 ;
if ( ( long ) V_43 < 0 )
return - V_31 ;
V_25 = V_42 -> V_20 -> V_52 ( V_42 , V_43 ) ;
if ( V_25 )
return V_25 ;
return V_28 ;
}
static T_1
F_27 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_53 * V_54 ;
V_54 =
F_28 ( V_14 , struct V_53 , V_14 ) ;
if ( V_54 -> V_33 == V_46 )
return sprintf ( V_15 , L_14 ) ;
else
return sprintf ( V_15 , L_12 , V_54 -> V_33 ) ;
}
static T_1
F_29 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
struct V_55 * V_56 = F_30 ( V_12 ) ;
return sprintf ( V_15 , L_1 , V_56 -> type ) ;
}
static T_1
F_31 ( struct V_11 * V_12 , struct V_13 * V_14 , char * V_15 )
{
long V_18 ;
int V_19 ;
struct V_57 * V_58
= F_28 ( V_14 , struct V_57 , V_14 ) ;
struct V_16 * V_17
= F_28 ( V_58 , struct V_16 ,
V_59 ) ;
V_19 = V_17 -> V_20 -> V_21 ( V_17 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static T_1
F_32 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_57 * V_58
= F_28 ( V_14 , struct V_57 , V_14 ) ;
struct V_16 * V_17
= F_28 ( V_58 , struct V_16 ,
V_60 ) ;
long V_18 ;
int V_19 ;
V_19 = V_17 -> V_20 -> V_40 ( V_17 , 0 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static int
F_33 ( struct V_16 * V_17 )
{
struct V_55 * V_56 ;
int V_61 = 1 ;
int V_25 ;
F_4 ( & V_45 ) ;
F_17 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_56 -> type , V_17 -> type ) ) {
V_61 = 0 ;
F_6 ( & V_45 ) ;
goto V_62;
}
F_6 ( & V_45 ) ;
V_56 = F_34 ( sizeof( struct V_55 ) , V_7 ) ;
if ( ! V_56 )
return - V_8 ;
F_35 ( & V_56 -> V_63 ) ;
F_36 ( V_56 -> type , V_17 -> type , V_64 ) ;
V_56 -> V_11 = F_37 ( NULL ) ;
if ( F_38 ( V_56 -> V_11 ) ) {
V_25 = F_39 ( V_56 -> V_11 ) ;
goto V_65;
}
F_40 ( V_56 -> V_11 , V_56 ) ;
V_25 = F_41 ( V_56 -> V_11 , & V_66 ) ;
if ( V_25 )
goto V_65;
V_62:
V_17 -> V_56 = V_56 ;
V_56 -> V_28 ++ ;
snprintf ( V_17 -> V_59 . V_35 , V_64 ,
L_15 , V_56 -> V_28 ) ;
V_17 -> V_59 . V_14 . V_14 . V_35 = V_17 -> V_59 . V_35 ;
V_17 -> V_59 . V_14 . V_14 . V_24 = 0444 ;
V_17 -> V_59 . V_14 . V_67 = F_31 ;
F_42 ( & V_17 -> V_59 . V_14 . V_14 ) ;
V_25 = F_41 ( V_56 -> V_11 , & V_17 -> V_59 . V_14 ) ;
if ( V_25 )
goto V_68;
if ( V_17 -> V_20 -> V_69 ) {
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_69 ( V_17 , & V_18 ) ) {
snprintf ( V_17 -> V_60 . V_35 , V_64 ,
L_16 , V_56 -> V_28 ) ;
V_17 -> V_60 . V_14 . V_14 . V_35 = V_17 -> V_60 . V_35 ;
V_17 -> V_60 . V_14 . V_14 . V_24 = 0444 ;
V_17 -> V_60 . V_14 . V_67 = F_32 ;
F_42 ( & V_17 -> V_60 . V_14 . V_14 ) ;
V_25 = F_41 ( V_56 -> V_11 ,
& V_17 -> V_60 . V_14 ) ;
if ( V_25 )
goto V_70;
}
}
F_4 ( & V_45 ) ;
if ( V_61 )
F_43 ( & V_56 -> V_71 , & V_72 ) ;
F_43 ( & V_17 -> V_73 , & V_56 -> V_63 ) ;
F_6 ( & V_45 ) ;
return 0 ;
V_70:
F_44 ( V_56 -> V_11 , & V_17 -> V_59 . V_14 ) ;
V_68:
if ( V_61 ) {
F_44 ( V_56 -> V_11 , & V_66 ) ;
F_45 ( V_56 -> V_11 ) ;
}
V_65:
if ( V_61 )
F_46 ( V_56 ) ;
return V_25 ;
}
static void
F_47 ( struct V_16 * V_17 )
{
struct V_55 * V_56 = V_17 -> V_56 ;
V_17 -> V_56 = NULL ;
F_44 ( V_56 -> V_11 , & V_17 -> V_59 . V_14 ) ;
if ( V_17 -> V_20 -> V_69 )
F_44 ( V_56 -> V_11 , & V_17 -> V_60 . V_14 ) ;
F_4 ( & V_45 ) ;
F_48 ( & V_17 -> V_73 ) ;
if ( ! F_49 ( & V_56 -> V_63 ) ) {
F_6 ( & V_45 ) ;
return;
}
F_48 ( & V_56 -> V_71 ) ;
F_6 ( & V_45 ) ;
F_44 ( V_56 -> V_11 , & V_66 ) ;
F_45 ( V_56 -> V_11 ) ;
F_46 ( V_56 ) ;
}
static int
F_33 ( struct V_16 * V_17 )
{
return 0 ;
}
static void
F_47 ( struct V_16 * V_17 )
{
}
static void F_50 ( struct V_16 * V_17 ,
int V_74 )
{
F_51 ( & ( V_17 -> V_75 ) ) ;
if ( ! V_74 )
return;
if ( V_74 > 1000 )
F_52 ( & ( V_17 -> V_75 ) ,
F_53 ( F_54 ( V_74 ) ) ) ;
else
F_52 ( & ( V_17 -> V_75 ) ,
F_54 ( V_74 ) ) ;
}
static void F_55 ( struct V_16 * V_17 ,
int V_76 , int V_77 , int V_33 )
{
int V_78 = 0 ;
struct V_53 * V_54 ;
struct V_41 * V_42 ;
long V_43 , V_79 ;
if ( V_76 >= V_77 ) {
V_17 -> V_80 = true ;
V_78 = ( V_17 -> V_48 * ( V_76 - V_17 -> V_81 ) ) +
( V_17 -> V_49 * ( V_76 - V_77 ) ) ;
if ( V_78 > 0 ) {
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_33 )
continue;
V_42 = V_54 -> V_42 ;
V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
V_42 -> V_20 -> V_50 ( V_42 , & V_79 ) ;
if ( V_43 ++ < V_79 )
V_42 -> V_20 -> V_52 ( V_42 , V_43 ) ;
}
} else if ( V_78 < 0 ) {
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_33 )
continue;
V_42 = V_54 -> V_42 ;
V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
V_42 -> V_20 -> V_50 ( V_42 , & V_79 ) ;
if ( V_43 > 0 )
V_42 -> V_20 -> V_52 ( V_42 , -- V_43 ) ;
}
}
return;
}
F_17 (instance, &tz->cooling_devices, node) {
if ( V_54 -> V_33 != V_33 )
continue;
V_42 = V_54 -> V_42 ;
V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
V_42 -> V_20 -> V_50 ( V_42 , & V_79 ) ;
if ( V_43 > 0 )
V_42 -> V_20 -> V_52 ( V_42 , -- V_43 ) ;
if ( V_43 == 0 )
V_17 -> V_80 = false ;
}
}
static void F_56 ( struct V_82 * V_83 )
{
struct V_16 * V_17 = F_28 ( V_83 , struct
V_16 ,
V_75 . V_83 ) ;
F_20 ( V_17 ) ;
}
int F_18 ( struct V_16 * V_17 ,
int V_33 ,
struct V_41 * V_42 )
{
struct V_53 * V_12 ;
struct V_53 * V_84 ;
struct V_16 * V_85 ;
struct V_41 * V_86 ;
int V_25 ;
if ( V_33 >= V_17 -> V_87 || ( V_33 < 0 && V_33 != V_46 ) )
return - V_31 ;
F_17 (pos1, &thermal_tz_list, node) {
if ( V_85 == V_17 )
break;
}
F_17 (pos2, &thermal_cdev_list, node) {
if ( V_86 == V_42 )
break;
}
if ( V_17 != V_85 || V_42 != V_86 )
return - V_31 ;
V_12 =
F_34 ( sizeof( struct V_53 ) , V_7 ) ;
if ( ! V_12 )
return - V_8 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_42 = V_42 ;
V_12 -> V_33 = V_33 ;
V_25 = F_1 ( & V_17 -> V_1 , & V_17 -> V_3 , & V_12 -> V_4 ) ;
if ( V_25 )
goto V_65;
sprintf ( V_12 -> V_35 , L_17 , V_12 -> V_4 ) ;
V_25 =
F_57 ( & V_17 -> V_11 . V_88 , & V_42 -> V_11 . V_88 , V_12 -> V_35 ) ;
if ( V_25 )
goto F_7;
sprintf ( V_12 -> V_89 , L_18 , V_12 -> V_4 ) ;
F_42 ( & V_12 -> V_14 . V_14 ) ;
V_12 -> V_14 . V_14 . V_35 = V_12 -> V_89 ;
V_12 -> V_14 . V_14 . V_24 = 0444 ;
V_12 -> V_14 . V_67 = F_27 ;
V_25 = F_41 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
if ( V_25 )
goto V_90;
F_4 ( & V_17 -> V_3 ) ;
F_17 (pos, &tz->cooling_devices, node)
if ( V_84 -> V_17 == V_17 && V_84 -> V_33 == V_33 && V_84 -> V_42 == V_42 ) {
V_25 = - V_91 ;
break;
}
if ( ! V_25 )
F_43 ( & V_12 -> V_71 , & V_17 -> V_92 ) ;
F_6 ( & V_17 -> V_3 ) ;
if ( ! V_25 )
return 0 ;
F_44 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
V_90:
F_58 ( & V_17 -> V_11 . V_88 , V_12 -> V_35 ) ;
F_7:
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_12 -> V_4 ) ;
V_65:
F_46 ( V_12 ) ;
return V_25 ;
}
int F_19 ( struct V_16 * V_17 ,
int V_33 ,
struct V_41 * V_42 )
{
struct V_53 * V_84 , * V_93 ;
F_4 ( & V_17 -> V_3 ) ;
F_59 (pos, next, &tz->cooling_devices, node) {
if ( V_84 -> V_17 == V_17 && V_84 -> V_33 == V_33 && V_84 -> V_42 == V_42 ) {
F_48 ( & V_84 -> V_71 ) ;
F_6 ( & V_17 -> V_3 ) ;
goto V_94;
}
}
F_6 ( & V_17 -> V_3 ) ;
return - V_95 ;
V_94:
F_44 ( & V_17 -> V_11 , & V_84 -> V_14 ) ;
F_58 ( & V_17 -> V_11 . V_88 , V_84 -> V_35 ) ;
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_84 -> V_4 ) ;
F_46 ( V_84 ) ;
return 0 ;
}
static void F_60 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
struct V_41 * V_42 ;
if ( ! strncmp ( F_61 ( V_12 ) , L_19 , sizeof "thermal_zone" - 1 ) ) {
V_17 = F_10 ( V_12 ) ;
F_46 ( V_17 ) ;
} else {
V_42 = F_23 ( V_12 ) ;
F_46 ( V_42 ) ;
}
}
struct V_41 * F_62 (
char * type , void * V_96 , const struct V_97 * V_20 )
{
struct V_41 * V_42 ;
struct V_16 * V_84 ;
int V_25 ;
if ( strlen ( type ) >= V_64 )
return F_63 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_50 || ! V_20 -> V_51 ||
! V_20 -> V_52 )
return F_63 ( - V_31 ) ;
V_42 = F_34 ( sizeof( struct V_41 ) , V_7 ) ;
if ( ! V_42 )
return F_63 ( - V_8 ) ;
V_25 = F_1 ( & V_98 , & V_99 , & V_42 -> V_4 ) ;
if ( V_25 ) {
F_46 ( V_42 ) ;
return F_63 ( V_25 ) ;
}
strcpy ( V_42 -> type , type ) ;
V_42 -> V_20 = V_20 ;
V_42 -> V_11 . V_100 = & V_101 ;
V_42 -> V_96 = V_96 ;
F_64 ( & V_42 -> V_11 , L_20 , V_42 -> V_4 ) ;
V_25 = F_65 ( & V_42 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_98 , & V_99 , V_42 -> V_4 ) ;
F_46 ( V_42 ) ;
return F_63 ( V_25 ) ;
}
if ( type ) {
V_25 = F_41 ( & V_42 -> V_11 , & V_102 ) ;
if ( V_25 )
goto V_103;
}
V_25 = F_41 ( & V_42 -> V_11 , & V_104 ) ;
if ( V_25 )
goto V_103;
V_25 = F_41 ( & V_42 -> V_11 , & V_105 ) ;
if ( V_25 )
goto V_103;
F_4 ( & V_45 ) ;
F_66 ( & V_42 -> V_71 , & V_106 ) ;
F_17 (pos, &thermal_tz_list, node) {
if ( ! V_84 -> V_20 -> V_107 )
continue;
V_25 = V_84 -> V_20 -> V_107 ( V_84 , V_42 ) ;
if ( V_25 )
break;
}
F_6 ( & V_45 ) ;
if ( ! V_25 )
return V_42 ;
V_103:
F_7 ( & V_98 , & V_99 , V_42 -> V_4 ) ;
F_67 ( & V_42 -> V_11 ) ;
return F_63 ( V_25 ) ;
}
void F_68 ( struct
V_41
* V_42 )
{
struct V_16 * V_17 ;
struct V_41 * V_84 = NULL ;
if ( ! V_42 )
return;
F_4 ( & V_45 ) ;
F_17 (pos, &thermal_cdev_list, node)
if ( V_84 == V_42 )
break;
if ( V_84 != V_42 ) {
F_6 ( & V_45 ) ;
return;
}
F_48 ( & V_42 -> V_71 ) ;
F_17 (tz, &thermal_tz_list, node) {
if ( ! V_17 -> V_20 -> V_94 )
continue;
V_17 -> V_20 -> V_94 ( V_17 , V_42 ) ;
}
F_6 ( & V_45 ) ;
if ( V_42 -> type [ 0 ] )
F_44 ( & V_42 -> V_11 , & V_102 ) ;
F_44 ( & V_42 -> V_11 , & V_104 ) ;
F_44 ( & V_42 -> V_11 , & V_105 ) ;
F_7 ( & V_98 , & V_99 , V_42 -> V_4 ) ;
F_67 ( & V_42 -> V_11 ) ;
return;
}
void F_20 ( struct V_16 * V_17 )
{
int V_28 , V_19 = 0 ;
long V_76 , V_77 ;
enum V_32 V_108 ;
struct V_53 * V_54 ;
struct V_41 * V_42 ;
F_4 ( & V_17 -> V_3 ) ;
if ( V_17 -> V_20 -> V_21 ( V_17 , & V_76 ) ) {
F_69 (KERN_WARNING PREFIX L_21
L_12 , tz->id) ;
goto V_109;
}
for ( V_28 = 0 ; V_28 < V_17 -> V_87 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_108 ) ;
V_17 -> V_20 -> V_40 ( V_17 , V_28 , & V_77 ) ;
switch ( V_108 ) {
case V_36 :
if ( V_76 >= V_77 ) {
if ( V_17 -> V_20 -> V_110 )
V_19 = V_17 -> V_20 -> V_110 ( V_17 , V_28 ,
V_108 ) ;
if ( ! V_19 ) {
F_69 ( V_111
L_22 ,
V_76 / 1000 ) ;
F_70 ( true ) ;
}
}
break;
case V_37 :
if ( V_76 >= V_77 )
if ( V_17 -> V_20 -> V_110 )
V_17 -> V_20 -> V_110 ( V_17 , V_28 , V_108 ) ;
break;
case V_39 :
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_28 )
continue;
V_42 = V_54 -> V_42 ;
if ( V_76 >= V_77 )
V_42 -> V_20 -> V_52 ( V_42 , 1 ) ;
else
V_42 -> V_20 -> V_52 ( V_42 , 0 ) ;
}
break;
case V_38 :
if ( V_76 >= V_77 || V_17 -> V_80 )
F_55 ( V_17 , V_76 ,
V_77 , V_28 ) ;
break;
}
}
if ( V_17 -> V_44 )
F_55 ( V_17 , V_76 , V_17 -> V_44 ,
V_46 ) ;
V_17 -> V_81 = V_76 ;
V_109:
if ( V_17 -> V_80 )
F_50 ( V_17 , V_17 -> V_47 ) ;
else if ( V_17 -> V_112 )
F_50 ( V_17 , V_17 -> V_112 ) ;
else
F_50 ( V_17 , 0 ) ;
F_6 ( & V_17 -> V_3 ) ;
}
struct V_16 * F_71 ( char * type ,
int V_87 , void * V_96 ,
const struct V_113 * V_20 ,
int V_48 , int V_49 , int V_47 , int V_112 )
{
struct V_16 * V_17 ;
struct V_41 * V_84 ;
enum V_32 V_108 ;
int V_25 ;
int V_28 ;
int V_80 = 0 ;
if ( strlen ( type ) >= V_64 )
return F_63 ( - V_31 ) ;
if ( V_87 > V_114 || V_87 < 0 )
return F_63 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_21 )
return F_63 ( - V_31 ) ;
V_17 = F_34 ( sizeof( struct V_16 ) , V_7 ) ;
if ( ! V_17 )
return F_63 ( - V_8 ) ;
F_35 ( & V_17 -> V_92 ) ;
F_72 ( & V_17 -> V_1 ) ;
F_73 ( & V_17 -> V_3 ) ;
V_25 = F_1 ( & V_115 , & V_99 , & V_17 -> V_4 ) ;
if ( V_25 ) {
F_46 ( V_17 ) ;
return F_63 ( V_25 ) ;
}
strcpy ( V_17 -> type , type ) ;
V_17 -> V_20 = V_20 ;
V_17 -> V_11 . V_100 = & V_101 ;
V_17 -> V_96 = V_96 ;
V_17 -> V_87 = V_87 ;
V_17 -> V_48 = V_48 ;
V_17 -> V_49 = V_49 ;
V_17 -> V_47 = V_47 ;
V_17 -> V_112 = V_112 ;
F_64 ( & V_17 -> V_11 , L_23 , V_17 -> V_4 ) ;
V_25 = F_65 ( & V_17 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_115 , & V_99 , V_17 -> V_4 ) ;
F_46 ( V_17 ) ;
return F_63 ( V_25 ) ;
}
if ( type ) {
V_25 = F_41 ( & V_17 -> V_11 , & V_116 ) ;
if ( V_25 )
goto V_103;
}
V_25 = F_41 ( & V_17 -> V_11 , & V_117 ) ;
if ( V_25 )
goto V_103;
if ( V_20 -> V_26 ) {
V_25 = F_41 ( & V_17 -> V_11 , & V_118 ) ;
if ( V_25 )
goto V_103;
}
for ( V_28 = 0 ; V_28 < V_87 ; V_28 ++ ) {
F_74 ( & V_17 -> V_11 , V_28 , V_25 ) ;
if ( V_25 )
goto V_103;
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_108 ) ;
if ( V_108 == V_38 )
V_80 = 1 ;
}
if ( ! V_80 )
V_25 = F_41 ( & V_17 -> V_11 ,
& V_119 ) ;
if ( V_25 )
goto V_103;
V_25 = F_33 ( V_17 ) ;
if ( V_25 )
goto V_103;
F_4 ( & V_45 ) ;
F_43 ( & V_17 -> V_71 , & V_120 ) ;
if ( V_20 -> V_107 )
F_17 (pos, &thermal_cdev_list, node) {
V_25 = V_20 -> V_107 ( V_17 , V_84 ) ;
if ( V_25 )
break;
}
F_6 ( & V_45 ) ;
F_75 ( & ( V_17 -> V_75 ) , F_56 ) ;
F_20 ( V_17 ) ;
if ( ! V_25 )
return V_17 ;
V_103:
F_7 ( & V_115 , & V_99 , V_17 -> V_4 ) ;
F_67 ( & V_17 -> V_11 ) ;
return F_63 ( V_25 ) ;
}
void F_76 ( struct V_16 * V_17 )
{
struct V_41 * V_42 ;
struct V_16 * V_84 = NULL ;
int V_28 ;
if ( ! V_17 )
return;
F_4 ( & V_45 ) ;
F_17 (pos, &thermal_tz_list, node)
if ( V_84 == V_17 )
break;
if ( V_84 != V_17 ) {
F_6 ( & V_45 ) ;
return;
}
F_48 ( & V_17 -> V_71 ) ;
if ( V_17 -> V_20 -> V_94 )
F_17 (cdev, &thermal_cdev_list, node)
V_17 -> V_20 -> V_94 ( V_17 , V_42 ) ;
F_6 ( & V_45 ) ;
F_50 ( V_17 , 0 ) ;
if ( V_17 -> type [ 0 ] )
F_44 ( & V_17 -> V_11 , & V_116 ) ;
F_44 ( & V_17 -> V_11 , & V_117 ) ;
if ( V_17 -> V_20 -> V_26 )
F_44 ( & V_17 -> V_11 , & V_118 ) ;
for ( V_28 = 0 ; V_28 < V_17 -> V_87 ; V_28 ++ )
F_77 ( & V_17 -> V_11 , V_28 ) ;
F_47 ( V_17 ) ;
F_7 ( & V_115 , & V_99 , V_17 -> V_4 ) ;
F_78 ( & V_17 -> V_1 ) ;
F_79 ( & V_17 -> V_3 ) ;
F_67 ( & V_17 -> V_11 ) ;
return;
}
int F_80 ( T_3 V_121 , enum V_122 V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_14 ;
struct V_127 * V_128 ;
void * V_129 ;
int V_130 ;
int V_25 ;
V_130 = F_81 ( sizeof( struct V_127 ) ) + \
F_81 ( 0 ) ;
V_125 = F_82 ( V_130 , V_131 ) ;
if ( ! V_125 )
return - V_8 ;
V_129 = F_83 ( V_125 , 0 , V_132 ++ ,
& V_133 , 0 ,
V_134 ) ;
if ( ! V_129 ) {
F_84 ( V_125 ) ;
return - V_8 ;
}
V_14 = F_85 ( V_125 , V_135 , \
sizeof( struct V_127 ) ) ;
if ( ! V_14 ) {
F_84 ( V_125 ) ;
return - V_31 ;
}
V_128 = F_86 ( V_14 ) ;
if ( ! V_128 ) {
F_84 ( V_125 ) ;
return - V_31 ;
}
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
V_128 -> V_121 = V_121 ;
V_128 -> V_123 = V_123 ;
V_25 = F_87 ( V_125 , V_129 ) ;
if ( V_25 < 0 ) {
F_84 ( V_125 ) ;
return V_25 ;
}
V_25 = F_88 ( V_125 , 0 , V_136 . V_4 , V_131 ) ;
if ( V_25 )
F_69 ( V_137 L_24 , V_25 ) ;
return V_25 ;
}
static int F_89 ( void )
{
int V_25 ;
V_25 = F_90 ( & V_133 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_91 ( & V_133 ,
& V_136 ) ;
if ( V_25 )
F_92 ( & V_133 ) ;
return V_25 ;
}
static void F_93 ( void )
{
F_92 ( & V_133 ) ;
}
static inline int F_89 ( void ) { return 0 ; }
static inline void F_93 ( void ) {}
static int T_4 F_94 ( void )
{
int V_25 = 0 ;
V_25 = F_95 ( & V_101 ) ;
if ( V_25 ) {
F_78 ( & V_115 ) ;
F_78 ( & V_98 ) ;
F_79 ( & V_99 ) ;
F_79 ( & V_45 ) ;
}
V_25 = F_89 () ;
return V_25 ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_101 ) ;
F_78 ( & V_115 ) ;
F_78 ( & V_98 ) ;
F_79 ( & V_99 ) ;
F_79 ( & V_45 ) ;
F_93 () ;
}
