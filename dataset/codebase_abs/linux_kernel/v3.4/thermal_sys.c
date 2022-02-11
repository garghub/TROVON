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
struct V_59 * V_60
= F_28 ( V_58 , struct V_59 ,
V_61 ) ;
struct V_16 * V_17 = V_60 -> V_17 ;
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
struct V_59 * V_60
= F_28 ( V_58 , struct V_59 ,
V_62 ) ;
struct V_16 * V_17 = V_60 -> V_17 ;
long V_18 ;
int V_19 ;
V_19 = V_17 -> V_20 -> V_40 ( V_17 , 0 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return sprintf ( V_15 , L_2 , V_18 ) ;
}
static struct V_55 *
F_33 ( const struct V_16 * V_17 )
{
struct V_55 * V_56 ;
F_4 ( & V_45 ) ;
F_17 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_56 -> type , V_17 -> type ) ) {
F_6 ( & V_45 ) ;
return V_56 ;
}
F_6 ( & V_45 ) ;
return NULL ;
}
static struct V_59 *
F_34 ( const struct V_55 * V_56 ,
const struct V_16 * V_17 )
{
struct V_59 * V_60 ;
F_4 ( & V_45 ) ;
F_17 (temp, &hwmon->tz_list, hwmon_node)
if ( V_60 -> V_17 == V_17 ) {
F_6 ( & V_45 ) ;
return V_60 ;
}
F_6 ( & V_45 ) ;
return NULL ;
}
static int
F_35 ( struct V_16 * V_17 )
{
struct V_55 * V_56 ;
struct V_59 * V_60 ;
int V_63 = 1 ;
int V_25 ;
V_56 = F_33 ( V_17 ) ;
if ( V_56 ) {
V_63 = 0 ;
goto V_64;
}
V_56 = F_36 ( sizeof( struct V_55 ) , V_7 ) ;
if ( ! V_56 )
return - V_8 ;
F_37 ( & V_56 -> V_65 ) ;
F_38 ( V_56 -> type , V_17 -> type , V_66 ) ;
V_56 -> V_11 = F_39 ( NULL ) ;
if ( F_40 ( V_56 -> V_11 ) ) {
V_25 = F_41 ( V_56 -> V_11 ) ;
goto V_67;
}
F_42 ( V_56 -> V_11 , V_56 ) ;
V_25 = F_43 ( V_56 -> V_11 , & V_68 ) ;
if ( V_25 )
goto V_67;
V_64:
V_60 = F_36 ( sizeof( struct V_59 ) , V_7 ) ;
if ( ! V_60 ) {
V_25 = - V_8 ;
goto V_69;
}
V_60 -> V_17 = V_17 ;
V_56 -> V_28 ++ ;
snprintf ( V_60 -> V_61 . V_35 , V_66 ,
L_15 , V_56 -> V_28 ) ;
V_60 -> V_61 . V_14 . V_14 . V_35 = V_60 -> V_61 . V_35 ;
V_60 -> V_61 . V_14 . V_14 . V_24 = 0444 ;
V_60 -> V_61 . V_14 . V_70 = F_31 ;
F_44 ( & V_60 -> V_61 . V_14 . V_14 ) ;
V_25 = F_43 ( V_56 -> V_11 , & V_60 -> V_61 . V_14 ) ;
if ( V_25 )
goto V_71;
if ( V_17 -> V_20 -> V_72 ) {
unsigned long V_18 ;
if ( ! V_17 -> V_20 -> V_72 ( V_17 , & V_18 ) ) {
snprintf ( V_60 -> V_62 . V_35 , V_66 ,
L_16 , V_56 -> V_28 ) ;
V_60 -> V_62 . V_14 . V_14 . V_35 = V_60 -> V_62 . V_35 ;
V_60 -> V_62 . V_14 . V_14 . V_24 = 0444 ;
V_60 -> V_62 . V_14 . V_70 = F_32 ;
F_44 ( & V_60 -> V_62 . V_14 . V_14 ) ;
V_25 = F_43 ( V_56 -> V_11 ,
& V_60 -> V_62 . V_14 ) ;
if ( V_25 )
goto V_73;
}
}
F_4 ( & V_45 ) ;
if ( V_63 )
F_45 ( & V_56 -> V_74 , & V_75 ) ;
F_45 ( & V_60 -> V_76 , & V_56 -> V_65 ) ;
F_6 ( & V_45 ) ;
return 0 ;
V_73:
F_46 ( V_56 -> V_11 , & V_60 -> V_61 . V_14 ) ;
V_71:
F_47 ( V_60 ) ;
V_69:
if ( V_63 ) {
F_46 ( V_56 -> V_11 , & V_68 ) ;
F_48 ( V_56 -> V_11 ) ;
}
V_67:
if ( V_63 )
F_47 ( V_56 ) ;
return V_25 ;
}
static void
F_49 ( struct V_16 * V_17 )
{
struct V_55 * V_56 ;
struct V_59 * V_60 ;
V_56 = F_33 ( V_17 ) ;
if ( F_2 ( ! V_56 ) ) {
F_50 ( & V_17 -> V_11 , L_17 ) ;
return;
}
V_60 = F_34 ( V_56 , V_17 ) ;
if ( F_2 ( ! V_60 ) ) {
F_50 ( & V_17 -> V_11 , L_18 ) ;
return;
}
F_46 ( V_56 -> V_11 , & V_60 -> V_61 . V_14 ) ;
if ( V_17 -> V_20 -> V_72 )
F_46 ( V_56 -> V_11 , & V_60 -> V_62 . V_14 ) ;
F_4 ( & V_45 ) ;
F_51 ( & V_60 -> V_76 ) ;
F_47 ( V_60 ) ;
if ( ! F_52 ( & V_56 -> V_65 ) ) {
F_6 ( & V_45 ) ;
return;
}
F_51 ( & V_56 -> V_74 ) ;
F_6 ( & V_45 ) ;
F_46 ( V_56 -> V_11 , & V_68 ) ;
F_48 ( V_56 -> V_11 ) ;
F_47 ( V_56 ) ;
}
static int
F_35 ( struct V_16 * V_17 )
{
return 0 ;
}
static void
F_49 ( struct V_16 * V_17 )
{
}
static void F_53 ( struct V_16 * V_17 ,
int V_77 )
{
F_54 ( & ( V_17 -> V_78 ) ) ;
if ( ! V_77 )
return;
if ( V_77 > 1000 )
F_55 ( V_79 , & ( V_17 -> V_78 ) ,
F_56 ( F_57 ( V_77 ) ) ) ;
else
F_55 ( V_79 , & ( V_17 -> V_78 ) ,
F_57 ( V_77 ) ) ;
}
static void F_58 ( struct V_16 * V_17 ,
int V_60 , int V_80 , int V_33 )
{
int V_81 = 0 ;
struct V_53 * V_54 ;
struct V_41 * V_42 ;
long V_43 , V_82 ;
if ( V_60 >= V_80 ) {
V_17 -> V_83 = true ;
V_81 = ( V_17 -> V_48 * ( V_60 - V_17 -> V_84 ) ) +
( V_17 -> V_49 * ( V_60 - V_80 ) ) ;
if ( V_81 > 0 ) {
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_33 )
continue;
V_42 = V_54 -> V_42 ;
V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
V_42 -> V_20 -> V_50 ( V_42 , & V_82 ) ;
if ( V_43 ++ < V_82 )
V_42 -> V_20 -> V_52 ( V_42 , V_43 ) ;
}
} else if ( V_81 < 0 ) {
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_33 )
continue;
V_42 = V_54 -> V_42 ;
V_42 -> V_20 -> V_51 ( V_42 , & V_43 ) ;
V_42 -> V_20 -> V_50 ( V_42 , & V_82 ) ;
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
V_42 -> V_20 -> V_50 ( V_42 , & V_82 ) ;
if ( V_43 > 0 )
V_42 -> V_20 -> V_52 ( V_42 , -- V_43 ) ;
if ( V_43 == 0 )
V_17 -> V_83 = false ;
}
}
static void F_59 ( struct V_85 * V_86 )
{
struct V_16 * V_17 = F_28 ( V_86 , struct
V_16 ,
V_78 . V_86 ) ;
F_20 ( V_17 ) ;
}
int F_18 ( struct V_16 * V_17 ,
int V_33 ,
struct V_41 * V_42 )
{
struct V_53 * V_12 ;
struct V_53 * V_87 ;
struct V_16 * V_88 ;
struct V_41 * V_89 ;
int V_25 ;
if ( V_33 >= V_17 -> V_90 || ( V_33 < 0 && V_33 != V_46 ) )
return - V_31 ;
F_17 (pos1, &thermal_tz_list, node) {
if ( V_88 == V_17 )
break;
}
F_17 (pos2, &thermal_cdev_list, node) {
if ( V_89 == V_42 )
break;
}
if ( V_17 != V_88 || V_42 != V_89 )
return - V_31 ;
V_12 =
F_36 ( sizeof( struct V_53 ) , V_7 ) ;
if ( ! V_12 )
return - V_8 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_42 = V_42 ;
V_12 -> V_33 = V_33 ;
V_25 = F_1 ( & V_17 -> V_1 , & V_17 -> V_3 , & V_12 -> V_4 ) ;
if ( V_25 )
goto V_67;
sprintf ( V_12 -> V_35 , L_19 , V_12 -> V_4 ) ;
V_25 =
F_60 ( & V_17 -> V_11 . V_91 , & V_42 -> V_11 . V_91 , V_12 -> V_35 ) ;
if ( V_25 )
goto F_7;
sprintf ( V_12 -> V_92 , L_20 , V_12 -> V_4 ) ;
F_44 ( & V_12 -> V_14 . V_14 ) ;
V_12 -> V_14 . V_14 . V_35 = V_12 -> V_92 ;
V_12 -> V_14 . V_14 . V_24 = 0444 ;
V_12 -> V_14 . V_70 = F_27 ;
V_25 = F_43 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
if ( V_25 )
goto V_93;
F_4 ( & V_17 -> V_3 ) ;
F_17 (pos, &tz->cooling_devices, node)
if ( V_87 -> V_17 == V_17 && V_87 -> V_33 == V_33 && V_87 -> V_42 == V_42 ) {
V_25 = - V_94 ;
break;
}
if ( ! V_25 )
F_45 ( & V_12 -> V_74 , & V_17 -> V_95 ) ;
F_6 ( & V_17 -> V_3 ) ;
if ( ! V_25 )
return 0 ;
F_46 ( & V_17 -> V_11 , & V_12 -> V_14 ) ;
V_93:
F_61 ( & V_17 -> V_11 . V_91 , V_12 -> V_35 ) ;
F_7:
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_12 -> V_4 ) ;
V_67:
F_47 ( V_12 ) ;
return V_25 ;
}
int F_19 ( struct V_16 * V_17 ,
int V_33 ,
struct V_41 * V_42 )
{
struct V_53 * V_87 , * V_96 ;
F_4 ( & V_17 -> V_3 ) ;
F_62 (pos, next, &tz->cooling_devices, node) {
if ( V_87 -> V_17 == V_17 && V_87 -> V_33 == V_33 && V_87 -> V_42 == V_42 ) {
F_51 ( & V_87 -> V_74 ) ;
F_6 ( & V_17 -> V_3 ) ;
goto V_97;
}
}
F_6 ( & V_17 -> V_3 ) ;
return - V_98 ;
V_97:
F_46 ( & V_17 -> V_11 , & V_87 -> V_14 ) ;
F_61 ( & V_17 -> V_11 . V_91 , V_87 -> V_35 ) ;
F_7 ( & V_17 -> V_1 , & V_17 -> V_3 , V_87 -> V_4 ) ;
F_47 ( V_87 ) ;
return 0 ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
struct V_41 * V_42 ;
if ( ! strncmp ( F_64 ( V_12 ) , L_21 ,
sizeof( L_21 ) - 1 ) ) {
V_17 = F_10 ( V_12 ) ;
F_47 ( V_17 ) ;
} else {
V_42 = F_23 ( V_12 ) ;
F_47 ( V_42 ) ;
}
}
struct V_41 *
F_65 ( char * type , void * V_99 ,
const struct V_100 * V_20 )
{
struct V_41 * V_42 ;
struct V_16 * V_87 ;
int V_25 ;
if ( strlen ( type ) >= V_66 )
return F_66 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_50 || ! V_20 -> V_51 ||
! V_20 -> V_52 )
return F_66 ( - V_31 ) ;
V_42 = F_36 ( sizeof( struct V_41 ) , V_7 ) ;
if ( ! V_42 )
return F_66 ( - V_8 ) ;
V_25 = F_1 ( & V_101 , & V_102 , & V_42 -> V_4 ) ;
if ( V_25 ) {
F_47 ( V_42 ) ;
return F_66 ( V_25 ) ;
}
strcpy ( V_42 -> type , type ) ;
V_42 -> V_20 = V_20 ;
V_42 -> V_11 . V_103 = & V_104 ;
V_42 -> V_99 = V_99 ;
F_67 ( & V_42 -> V_11 , L_22 , V_42 -> V_4 ) ;
V_25 = F_68 ( & V_42 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_101 , & V_102 , V_42 -> V_4 ) ;
F_47 ( V_42 ) ;
return F_66 ( V_25 ) ;
}
if ( type ) {
V_25 = F_43 ( & V_42 -> V_11 , & V_105 ) ;
if ( V_25 )
goto V_106;
}
V_25 = F_43 ( & V_42 -> V_11 , & V_107 ) ;
if ( V_25 )
goto V_106;
V_25 = F_43 ( & V_42 -> V_11 , & V_108 ) ;
if ( V_25 )
goto V_106;
F_4 ( & V_45 ) ;
F_69 ( & V_42 -> V_74 , & V_109 ) ;
F_17 (pos, &thermal_tz_list, node) {
if ( ! V_87 -> V_20 -> V_110 )
continue;
V_25 = V_87 -> V_20 -> V_110 ( V_87 , V_42 ) ;
if ( V_25 )
break;
}
F_6 ( & V_45 ) ;
if ( ! V_25 )
return V_42 ;
V_106:
F_7 ( & V_101 , & V_102 , V_42 -> V_4 ) ;
F_70 ( & V_42 -> V_11 ) ;
return F_66 ( V_25 ) ;
}
void F_71 ( struct
V_41
* V_42 )
{
struct V_16 * V_17 ;
struct V_41 * V_87 = NULL ;
if ( ! V_42 )
return;
F_4 ( & V_45 ) ;
F_17 (pos, &thermal_cdev_list, node)
if ( V_87 == V_42 )
break;
if ( V_87 != V_42 ) {
F_6 ( & V_45 ) ;
return;
}
F_51 ( & V_42 -> V_74 ) ;
F_17 (tz, &thermal_tz_list, node) {
if ( ! V_17 -> V_20 -> V_97 )
continue;
V_17 -> V_20 -> V_97 ( V_17 , V_42 ) ;
}
F_6 ( & V_45 ) ;
if ( V_42 -> type [ 0 ] )
F_46 ( & V_42 -> V_11 , & V_105 ) ;
F_46 ( & V_42 -> V_11 , & V_107 ) ;
F_46 ( & V_42 -> V_11 , & V_108 ) ;
F_7 ( & V_101 , & V_102 , V_42 -> V_4 ) ;
F_70 ( & V_42 -> V_11 ) ;
return;
}
void F_20 ( struct V_16 * V_17 )
{
int V_28 , V_19 = 0 ;
long V_60 , V_80 ;
enum V_32 V_111 ;
struct V_53 * V_54 ;
struct V_41 * V_42 ;
F_4 ( & V_17 -> V_3 ) ;
if ( V_17 -> V_20 -> V_21 ( V_17 , & V_60 ) ) {
F_72 ( L_23 , V_17 -> V_4 ) ;
goto V_112;
}
for ( V_28 = 0 ; V_28 < V_17 -> V_90 ; V_28 ++ ) {
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_111 ) ;
V_17 -> V_20 -> V_40 ( V_17 , V_28 , & V_80 ) ;
switch ( V_111 ) {
case V_36 :
if ( V_60 >= V_80 ) {
if ( V_17 -> V_20 -> V_113 )
V_19 = V_17 -> V_20 -> V_113 ( V_17 , V_28 ,
V_111 ) ;
if ( ! V_19 ) {
F_73 ( L_24 ,
V_60 / 1000 ) ;
F_74 ( true ) ;
}
}
break;
case V_37 :
if ( V_60 >= V_80 )
if ( V_17 -> V_20 -> V_113 )
V_17 -> V_20 -> V_113 ( V_17 , V_28 , V_111 ) ;
break;
case V_39 :
F_17 (instance, &tz->cooling_devices,
node) {
if ( V_54 -> V_33 != V_28 )
continue;
V_42 = V_54 -> V_42 ;
if ( V_60 >= V_80 )
V_42 -> V_20 -> V_52 ( V_42 , 1 ) ;
else
V_42 -> V_20 -> V_52 ( V_42 , 0 ) ;
}
break;
case V_38 :
if ( V_60 >= V_80 || V_17 -> V_83 )
F_58 ( V_17 , V_60 ,
V_80 , V_28 ) ;
break;
}
}
if ( V_17 -> V_44 )
F_58 ( V_17 , V_60 , V_17 -> V_44 ,
V_46 ) ;
V_17 -> V_84 = V_60 ;
V_112:
if ( V_17 -> V_83 )
F_53 ( V_17 , V_17 -> V_47 ) ;
else if ( V_17 -> V_114 )
F_53 ( V_17 , V_17 -> V_114 ) ;
else
F_53 ( V_17 , 0 ) ;
F_6 ( & V_17 -> V_3 ) ;
}
struct V_16 * F_75 ( char * type ,
int V_90 , void * V_99 ,
const struct V_115 * V_20 ,
int V_48 , int V_49 , int V_47 , int V_114 )
{
struct V_16 * V_17 ;
struct V_41 * V_87 ;
enum V_32 V_111 ;
int V_25 ;
int V_28 ;
int V_83 = 0 ;
if ( strlen ( type ) >= V_66 )
return F_66 ( - V_31 ) ;
if ( V_90 > V_116 || V_90 < 0 )
return F_66 ( - V_31 ) ;
if ( ! V_20 || ! V_20 -> V_21 )
return F_66 ( - V_31 ) ;
V_17 = F_36 ( sizeof( struct V_16 ) , V_7 ) ;
if ( ! V_17 )
return F_66 ( - V_8 ) ;
F_37 ( & V_17 -> V_95 ) ;
F_76 ( & V_17 -> V_1 ) ;
F_77 ( & V_17 -> V_3 ) ;
V_25 = F_1 ( & V_117 , & V_102 , & V_17 -> V_4 ) ;
if ( V_25 ) {
F_47 ( V_17 ) ;
return F_66 ( V_25 ) ;
}
strcpy ( V_17 -> type , type ) ;
V_17 -> V_20 = V_20 ;
V_17 -> V_11 . V_103 = & V_104 ;
V_17 -> V_99 = V_99 ;
V_17 -> V_90 = V_90 ;
V_17 -> V_48 = V_48 ;
V_17 -> V_49 = V_49 ;
V_17 -> V_47 = V_47 ;
V_17 -> V_114 = V_114 ;
F_67 ( & V_17 -> V_11 , L_25 , V_17 -> V_4 ) ;
V_25 = F_68 ( & V_17 -> V_11 ) ;
if ( V_25 ) {
F_7 ( & V_117 , & V_102 , V_17 -> V_4 ) ;
F_47 ( V_17 ) ;
return F_66 ( V_25 ) ;
}
if ( type ) {
V_25 = F_43 ( & V_17 -> V_11 , & V_118 ) ;
if ( V_25 )
goto V_106;
}
V_25 = F_43 ( & V_17 -> V_11 , & V_119 ) ;
if ( V_25 )
goto V_106;
if ( V_20 -> V_26 ) {
V_25 = F_43 ( & V_17 -> V_11 , & V_120 ) ;
if ( V_25 )
goto V_106;
}
for ( V_28 = 0 ; V_28 < V_90 ; V_28 ++ ) {
V_25 = F_43 ( & V_17 -> V_11 ,
& V_121 [ V_28 * 2 ] ) ;
if ( V_25 )
break;
V_25 = F_43 ( & V_17 -> V_11 ,
& V_121 [ V_28 * 2 + 1 ] ) ;
if ( V_25 )
goto V_106;
V_17 -> V_20 -> V_34 ( V_17 , V_28 , & V_111 ) ;
if ( V_111 == V_38 )
V_83 = 1 ;
}
if ( ! V_83 )
V_25 = F_43 ( & V_17 -> V_11 ,
& V_122 ) ;
if ( V_25 )
goto V_106;
V_25 = F_35 ( V_17 ) ;
if ( V_25 )
goto V_106;
F_4 ( & V_45 ) ;
F_45 ( & V_17 -> V_74 , & V_123 ) ;
if ( V_20 -> V_110 )
F_17 (pos, &thermal_cdev_list, node) {
V_25 = V_20 -> V_110 ( V_17 , V_87 ) ;
if ( V_25 )
break;
}
F_6 ( & V_45 ) ;
F_78 ( & ( V_17 -> V_78 ) , F_59 ) ;
F_20 ( V_17 ) ;
if ( ! V_25 )
return V_17 ;
V_106:
F_7 ( & V_117 , & V_102 , V_17 -> V_4 ) ;
F_70 ( & V_17 -> V_11 ) ;
return F_66 ( V_25 ) ;
}
void F_79 ( struct V_16 * V_17 )
{
struct V_41 * V_42 ;
struct V_16 * V_87 = NULL ;
int V_28 ;
if ( ! V_17 )
return;
F_4 ( & V_45 ) ;
F_17 (pos, &thermal_tz_list, node)
if ( V_87 == V_17 )
break;
if ( V_87 != V_17 ) {
F_6 ( & V_45 ) ;
return;
}
F_51 ( & V_17 -> V_74 ) ;
if ( V_17 -> V_20 -> V_97 )
F_17 (cdev, &thermal_cdev_list, node)
V_17 -> V_20 -> V_97 ( V_17 , V_42 ) ;
F_6 ( & V_45 ) ;
F_53 ( V_17 , 0 ) ;
if ( V_17 -> type [ 0 ] )
F_46 ( & V_17 -> V_11 , & V_118 ) ;
F_46 ( & V_17 -> V_11 , & V_119 ) ;
if ( V_17 -> V_20 -> V_26 )
F_46 ( & V_17 -> V_11 , & V_120 ) ;
for ( V_28 = 0 ; V_28 < V_17 -> V_90 ; V_28 ++ ) {
F_46 ( & V_17 -> V_11 ,
& V_121 [ V_28 * 2 ] ) ;
F_46 ( & V_17 -> V_11 ,
& V_121 [ V_28 * 2 + 1 ] ) ;
}
F_49 ( V_17 ) ;
F_7 ( & V_117 , & V_102 , V_17 -> V_4 ) ;
F_80 ( & V_17 -> V_1 ) ;
F_81 ( & V_17 -> V_3 ) ;
F_70 ( & V_17 -> V_11 ) ;
return;
}
int F_82 ( T_3 V_124 , enum V_125 V_126 )
{
struct V_127 * V_128 ;
struct V_129 * V_14 ;
struct V_130 * V_131 ;
void * V_132 ;
int V_133 ;
int V_25 ;
static unsigned int V_134 ;
V_133 = F_83 ( sizeof( struct V_130 ) ) +
F_83 ( 0 ) ;
V_128 = F_84 ( V_133 , V_135 ) ;
if ( ! V_128 )
return - V_8 ;
V_132 = F_85 ( V_128 , 0 , V_134 ++ ,
& V_136 , 0 ,
V_137 ) ;
if ( ! V_132 ) {
F_86 ( V_128 ) ;
return - V_8 ;
}
V_14 = F_87 ( V_128 , V_138 ,
sizeof( struct V_130 ) ) ;
if ( ! V_14 ) {
F_86 ( V_128 ) ;
return - V_31 ;
}
V_131 = F_88 ( V_14 ) ;
if ( ! V_131 ) {
F_86 ( V_128 ) ;
return - V_31 ;
}
memset ( V_131 , 0 , sizeof( struct V_130 ) ) ;
V_131 -> V_124 = V_124 ;
V_131 -> V_126 = V_126 ;
V_25 = F_89 ( V_128 , V_132 ) ;
if ( V_25 < 0 ) {
F_86 ( V_128 ) ;
return V_25 ;
}
V_25 = F_90 ( V_128 , 0 , V_139 . V_4 , V_135 ) ;
if ( V_25 )
F_91 ( L_26 , V_25 ) ;
return V_25 ;
}
static int F_92 ( void )
{
int V_25 ;
V_25 = F_93 ( & V_136 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_94 ( & V_136 ,
& V_139 ) ;
if ( V_25 )
F_95 ( & V_136 ) ;
return V_25 ;
}
static void F_96 ( void )
{
F_95 ( & V_136 ) ;
}
static inline int F_92 ( void ) { return 0 ; }
static inline void F_96 ( void ) {}
static int T_4 F_97 ( void )
{
int V_25 = 0 ;
V_25 = F_98 ( & V_104 ) ;
if ( V_25 ) {
F_80 ( & V_117 ) ;
F_80 ( & V_101 ) ;
F_81 ( & V_102 ) ;
F_81 ( & V_45 ) ;
}
V_25 = F_92 () ;
return V_25 ;
}
static void T_5 F_99 ( void )
{
F_100 ( & V_104 ) ;
F_80 ( & V_117 ) ;
F_80 ( & V_101 ) ;
F_81 ( & V_102 ) ;
F_81 ( & V_45 ) ;
F_96 () ;
}
