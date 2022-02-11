static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (pos, &thermal_governor_list, governor_list)
if ( ! F_3 ( V_2 , V_3 -> V_2 , V_4 ) )
return V_3 ;
return NULL ;
}
int F_4 ( struct V_1 * V_5 )
{
int V_6 ;
const char * V_2 ;
struct V_7 * V_3 ;
if ( ! V_5 )
return - V_8 ;
F_5 ( & V_9 ) ;
V_6 = - V_10 ;
if ( F_1 ( V_5 -> V_2 ) == NULL ) {
V_6 = 0 ;
F_6 ( & V_5 -> V_11 , & V_12 ) ;
}
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( V_3 -> V_5 )
continue;
if ( V_3 -> V_14 )
V_2 = V_3 -> V_14 -> V_15 ;
else
V_2 = V_16 ;
if ( ! F_3 ( V_2 , V_5 -> V_2 , V_4 ) )
V_3 -> V_5 = V_5 ;
}
F_7 ( & V_13 ) ;
F_7 ( & V_9 ) ;
return V_6 ;
}
void F_8 ( struct V_1 * V_5 )
{
struct V_7 * V_3 ;
if ( ! V_5 )
return;
F_5 ( & V_9 ) ;
if ( F_1 ( V_5 -> V_2 ) == NULL )
goto exit;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! F_3 ( V_3 -> V_5 -> V_2 , V_5 -> V_2 ,
V_4 ) )
V_3 -> V_5 = NULL ;
}
F_7 ( & V_13 ) ;
F_9 ( & V_5 -> V_11 ) ;
exit:
F_7 ( & V_9 ) ;
return;
}
static int F_10 ( struct V_17 * V_17 , struct V_18 * V_19 , int * V_20 )
{
int V_6 ;
V_21:
if ( F_11 ( F_12 ( V_17 , V_22 ) == 0 ) )
return - V_23 ;
if ( V_19 )
F_5 ( V_19 ) ;
V_6 = F_13 ( V_17 , NULL , V_20 ) ;
if ( V_19 )
F_7 ( V_19 ) ;
if ( F_11 ( V_6 == - V_24 ) )
goto V_21;
else if ( F_11 ( V_6 ) )
return V_6 ;
* V_20 = * V_20 & V_25 ;
return 0 ;
}
static void F_14 ( struct V_17 * V_17 , struct V_18 * V_19 , int V_20 )
{
if ( V_19 )
F_5 ( V_19 ) ;
F_15 ( V_17 , V_20 ) ;
if ( V_19 )
F_7 ( V_19 ) ;
}
int F_16 ( struct V_7 * V_26 , int V_27 )
{
enum V_28 V_29 ;
if ( ! V_26 -> V_30 -> V_31 || V_26 -> V_30 -> V_31 ( V_26 , V_27 , & V_29 ) ) {
if ( V_26 -> V_32 > V_26 -> V_33 )
V_29 = V_34 ;
else if ( V_26 -> V_32 < V_26 -> V_33 )
V_29 = V_35 ;
else
V_29 = V_36 ;
}
return V_29 ;
}
struct V_37 * F_17 ( struct V_7 * V_26 ,
struct V_38 * V_39 , int V_27 )
{
struct V_37 * V_3 = NULL ;
struct V_37 * V_40 = NULL ;
F_5 ( & V_26 -> V_19 ) ;
F_5 ( & V_39 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_26 == V_26 && V_3 -> V_27 == V_27 && V_3 -> V_39 == V_39 ) {
V_40 = V_3 ;
break;
}
}
F_7 ( & V_39 -> V_19 ) ;
F_7 ( & V_26 -> V_19 ) ;
return V_40 ;
}
static void F_18 ( struct V_7 * V_26 ,
struct V_38 * V_39 , int V_41 )
{
F_19 ( & V_26 -> V_42 , L_1 ,
V_26 -> type , V_39 -> type , V_41 ) ;
}
static void F_20 ( struct V_7 * V_26 , int V_43 ,
struct V_38 * V_39 )
{
int V_44 , V_41 ;
for ( V_44 = 0 ; V_44 < V_26 -> V_45 ; V_44 ++ ) {
if ( V_43 & ( 1 << V_44 ) ) {
V_41 = F_21 ( V_26 , V_44 , V_39 ,
V_46 , V_46 ) ;
if ( V_41 )
F_18 ( V_26 , V_39 , V_41 ) ;
}
}
}
static void F_22 ( struct V_7 * V_26 , int V_43 ,
struct V_38 * V_39 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_26 -> V_45 ; V_44 ++ )
if ( V_43 & ( 1 << V_44 ) )
F_23 ( V_26 , V_44 , V_39 ) ;
}
static void F_24 ( struct V_38 * V_39 )
{
int V_44 , V_41 ;
const struct V_47 * V_14 ;
struct V_7 * V_3 = NULL ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_14 && ! V_3 -> V_30 -> V_48 )
continue;
if ( ! V_3 -> V_14 && V_3 -> V_30 -> V_48 ) {
V_41 = V_3 -> V_30 -> V_48 ( V_3 , V_39 ) ;
if ( V_41 )
F_18 ( V_3 , V_39 , V_41 ) ;
}
V_14 = V_3 -> V_14 ;
if ( ! V_14 || ! V_14 -> V_49 )
continue;
for ( V_44 = 0 ; V_44 < V_14 -> V_50 ; V_44 ++ ) {
if ( V_14 -> V_49 [ V_44 ] . V_39 || ! V_14 -> V_49 [ V_44 ] . V_51 )
continue;
if ( V_14 -> V_49 [ V_44 ] . V_51 ( V_3 , V_39 ) )
continue;
V_14 -> V_49 [ V_44 ] . V_39 = V_39 ;
F_20 ( V_3 , V_14 -> V_49 [ V_44 ] . V_52 , V_39 ) ;
}
}
F_7 ( & V_13 ) ;
}
static void F_25 ( struct V_7 * V_26 )
{
int V_44 , V_41 ;
struct V_38 * V_3 = NULL ;
const struct V_47 * V_14 = V_26 -> V_14 ;
if ( ! V_14 && ! V_26 -> V_30 -> V_48 )
return;
F_5 ( & V_13 ) ;
if ( ! V_14 && V_26 -> V_30 -> V_48 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_41 = V_26 -> V_30 -> V_48 ( V_26 , V_3 ) ;
if ( V_41 )
F_18 ( V_26 , V_3 , V_41 ) ;
}
goto exit;
}
if ( ! V_14 || ! V_14 -> V_49 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_44 = 0 ; V_44 < V_14 -> V_50 ; V_44 ++ ) {
if ( V_14 -> V_49 [ V_44 ] . V_39 || ! V_14 -> V_49 [ V_44 ] . V_51 )
continue;
if ( V_14 -> V_49 [ V_44 ] . V_51 ( V_26 , V_3 ) )
continue;
V_14 -> V_49 [ V_44 ] . V_39 = V_3 ;
F_20 ( V_26 , V_14 -> V_49 [ V_44 ] . V_52 , V_3 ) ;
}
}
exit:
F_7 ( & V_13 ) ;
}
static void F_26 ( struct V_7 * V_26 ,
int V_53 )
{
if ( V_53 > 1000 )
F_27 ( V_54 , & V_26 -> V_55 ,
F_28 ( F_29 ( V_53 ) ) ) ;
else if ( V_53 )
F_27 ( V_54 , & V_26 -> V_55 ,
F_29 ( V_53 ) ) ;
else
F_30 ( & V_26 -> V_55 ) ;
}
static void F_31 ( struct V_7 * V_26 )
{
F_5 ( & V_26 -> V_19 ) ;
if ( V_26 -> V_56 )
F_26 ( V_26 , V_26 -> V_57 ) ;
else if ( V_26 -> V_58 )
F_26 ( V_26 , V_26 -> V_58 ) ;
else
F_26 ( V_26 , 0 ) ;
F_7 ( & V_26 -> V_19 ) ;
}
static void F_32 ( struct V_7 * V_26 ,
int V_27 , enum V_59 V_60 )
{
if ( V_26 -> V_5 )
V_26 -> V_5 -> V_61 ( V_26 , V_27 ) ;
}
static void F_33 ( struct V_7 * V_26 ,
int V_27 , enum V_59 V_60 )
{
long V_62 ;
V_26 -> V_30 -> V_63 ( V_26 , V_27 , & V_62 ) ;
if ( V_26 -> V_32 < V_62 )
return;
if ( V_26 -> V_30 -> V_64 )
V_26 -> V_30 -> V_64 ( V_26 , V_27 , V_60 ) ;
if ( V_60 == V_65 ) {
F_34 ( L_2 ,
V_26 -> V_32 / 1000 ) ;
F_35 ( true ) ;
}
}
static void F_36 ( struct V_7 * V_26 , int V_27 )
{
enum V_59 type ;
V_26 -> V_30 -> V_66 ( V_26 , V_27 , & type ) ;
if ( type == V_65 || type == V_67 )
F_33 ( V_26 , V_27 , type ) ;
else
F_32 ( V_26 , V_27 , type ) ;
F_31 ( V_26 ) ;
}
static void F_37 ( struct V_7 * V_26 )
{
long V_68 ;
int V_41 ;
F_5 ( & V_26 -> V_19 ) ;
V_41 = V_26 -> V_30 -> V_69 ( V_26 , & V_68 ) ;
if ( V_41 ) {
F_38 ( L_3 , V_26 -> V_20 ) ;
goto exit;
}
V_26 -> V_33 = V_26 -> V_32 ;
V_26 -> V_32 = V_68 ;
exit:
F_7 ( & V_26 -> V_19 ) ;
}
void F_39 ( struct V_7 * V_26 )
{
int V_70 ;
F_37 ( V_26 ) ;
for ( V_70 = 0 ; V_70 < V_26 -> V_45 ; V_70 ++ )
F_36 ( V_26 , V_70 ) ;
}
static void F_40 ( struct V_71 * V_72 )
{
struct V_7 * V_26 = F_41 ( V_72 , struct
V_7 ,
V_55 . V_72 ) ;
F_39 ( V_26 ) ;
}
static T_1
F_42 ( struct V_42 * V_73 , struct V_74 * V_75 , char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
return sprintf ( V_76 , L_4 , V_26 -> type ) ;
}
static T_1
F_44 ( struct V_42 * V_73 , struct V_74 * V_75 , char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
long V_32 ;
int V_41 ;
if ( ! V_26 -> V_30 -> V_69 )
return - V_77 ;
V_41 = V_26 -> V_30 -> V_69 ( V_26 , & V_32 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_32 ) ;
}
static T_1
F_45 ( struct V_42 * V_73 , struct V_74 * V_75 , char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
enum V_78 V_79 ;
int V_80 ;
if ( ! V_26 -> V_30 -> V_81 )
return - V_77 ;
V_80 = V_26 -> V_30 -> V_81 ( V_26 , & V_79 ) ;
if ( V_80 )
return V_80 ;
return sprintf ( V_76 , L_4 , V_79 == V_82 ? L_6
: L_7 ) ;
}
static T_1
F_46 ( struct V_42 * V_73 , struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
int V_80 ;
if ( ! V_26 -> V_30 -> V_83 )
return - V_77 ;
if ( ! strncmp ( V_76 , L_6 , sizeof( L_6 ) - 1 ) )
V_80 = V_26 -> V_30 -> V_83 ( V_26 , V_82 ) ;
else if ( ! strncmp ( V_76 , L_7 , sizeof( L_7 ) - 1 ) )
V_80 = V_26 -> V_30 -> V_83 ( V_26 , V_84 ) ;
else
V_80 = - V_8 ;
if ( V_80 )
return V_80 ;
return V_70 ;
}
static T_1
F_47 ( struct V_42 * V_73 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
enum V_59 type ;
int V_27 , V_80 ;
if ( ! V_26 -> V_30 -> V_66 )
return - V_77 ;
if ( ! sscanf ( V_75 -> V_75 . V_2 , L_8 , & V_27 ) )
return - V_8 ;
V_80 = V_26 -> V_30 -> V_66 ( V_26 , V_27 , & type ) ;
if ( V_80 )
return V_80 ;
switch ( type ) {
case V_65 :
return sprintf ( V_76 , L_9 ) ;
case V_67 :
return sprintf ( V_76 , L_10 ) ;
case V_85 :
return sprintf ( V_76 , L_11 ) ;
case V_86 :
return sprintf ( V_76 , L_12 ) ;
default:
return sprintf ( V_76 , L_13 ) ;
}
}
static T_1
F_48 ( struct V_42 * V_73 , struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
int V_27 , V_41 ;
unsigned long V_32 ;
if ( ! V_26 -> V_30 -> V_87 )
return - V_77 ;
if ( ! sscanf ( V_75 -> V_75 . V_2 , L_14 , & V_27 ) )
return - V_8 ;
if ( F_49 ( V_76 , 10 , & V_32 ) )
return - V_8 ;
V_41 = V_26 -> V_30 -> V_87 ( V_26 , V_27 , V_32 ) ;
return V_41 ? V_41 : V_70 ;
}
static T_1
F_50 ( struct V_42 * V_73 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
int V_27 , V_41 ;
long V_32 ;
if ( ! V_26 -> V_30 -> V_63 )
return - V_77 ;
if ( ! sscanf ( V_75 -> V_75 . V_2 , L_14 , & V_27 ) )
return - V_8 ;
V_41 = V_26 -> V_30 -> V_63 ( V_26 , V_27 , & V_32 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_32 ) ;
}
static T_1
F_51 ( struct V_42 * V_73 , struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
int V_27 , V_41 ;
unsigned long V_32 ;
if ( ! V_26 -> V_30 -> V_88 )
return - V_77 ;
if ( ! sscanf ( V_75 -> V_75 . V_2 , L_15 , & V_27 ) )
return - V_8 ;
if ( F_49 ( V_76 , 10 , & V_32 ) )
return - V_8 ;
V_41 = V_26 -> V_30 -> V_88 ( V_26 , V_27 , V_32 ) ;
return V_41 ? V_41 : V_70 ;
}
static T_1
F_52 ( struct V_42 * V_73 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
int V_27 , V_41 ;
unsigned long V_32 ;
if ( ! V_26 -> V_30 -> V_89 )
return - V_77 ;
if ( ! sscanf ( V_75 -> V_75 . V_2 , L_15 , & V_27 ) )
return - V_8 ;
V_41 = V_26 -> V_30 -> V_89 ( V_26 , V_27 , & V_32 ) ;
return V_41 ? V_41 : sprintf ( V_76 , L_5 , V_32 ) ;
}
static T_1
F_53 ( struct V_42 * V_73 , struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
struct V_38 * V_39 = NULL ;
int V_90 ;
if ( ! sscanf ( V_76 , L_16 , & V_90 ) )
return - V_8 ;
if ( V_90 && V_90 < 1000 )
return - V_8 ;
if ( V_90 && ! V_26 -> V_91 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_39 -> type ,
sizeof( L_17 ) ) )
F_21 ( V_26 ,
V_92 , V_39 ,
V_46 ,
V_46 ) ;
}
F_7 ( & V_13 ) ;
if ( ! V_26 -> V_57 )
V_26 -> V_57 = 1000 ;
} else if ( ! V_90 && V_26 -> V_91 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_39 -> type ,
sizeof( L_17 ) ) )
F_23 ( V_26 ,
V_92 ,
V_39 ) ;
}
F_7 ( & V_13 ) ;
V_26 -> V_57 = 0 ;
}
V_26 -> V_91 = V_90 ;
F_39 ( V_26 ) ;
return V_70 ;
}
static T_1
F_54 ( struct V_42 * V_73 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
return sprintf ( V_76 , L_16 , V_26 -> V_91 ) ;
}
static T_1
F_55 ( struct V_42 * V_73 , struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
int V_41 = - V_8 ;
struct V_7 * V_26 = F_43 ( V_73 ) ;
struct V_1 * V_93 ;
F_5 ( & V_9 ) ;
V_93 = F_1 ( V_76 ) ;
if ( ! V_93 )
goto exit;
V_26 -> V_5 = V_93 ;
V_41 = V_70 ;
exit:
F_7 ( & V_9 ) ;
return V_41 ;
}
static T_1
F_56 ( struct V_42 * V_73 , struct V_74 * V_94 , char * V_76 )
{
struct V_7 * V_26 = F_43 ( V_73 ) ;
return sprintf ( V_76 , L_4 , V_26 -> V_5 -> V_2 ) ;
}
static T_1
F_57 ( struct V_42 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_38 * V_39 = F_58 ( V_73 ) ;
return sprintf ( V_76 , L_4 , V_39 -> type ) ;
}
static T_1
F_59 ( struct V_42 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_38 * V_39 = F_58 ( V_73 ) ;
unsigned long V_90 ;
int V_41 ;
V_41 = V_39 -> V_30 -> V_95 ( V_39 , & V_90 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_90 ) ;
}
static T_1
F_60 ( struct V_42 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_38 * V_39 = F_58 ( V_73 ) ;
unsigned long V_90 ;
int V_41 ;
V_41 = V_39 -> V_30 -> V_96 ( V_39 , & V_90 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_90 ) ;
}
static T_1
F_61 ( struct V_42 * V_73 ,
struct V_74 * V_75 ,
const char * V_76 , T_2 V_70 )
{
struct V_38 * V_39 = F_58 ( V_73 ) ;
unsigned long V_90 ;
int V_80 ;
if ( ! sscanf ( V_76 , L_5 , & V_90 ) )
return - V_8 ;
if ( ( long ) V_90 < 0 )
return - V_8 ;
V_80 = V_39 -> V_30 -> V_97 ( V_39 , V_90 ) ;
if ( V_80 )
return V_80 ;
return V_70 ;
}
static T_1
F_62 ( struct V_42 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_37 * V_98 ;
V_98 =
F_41 ( V_75 , struct V_37 , V_75 ) ;
if ( V_98 -> V_27 == V_92 )
return sprintf ( V_76 , L_18 ) ;
else
return sprintf ( V_76 , L_16 , V_98 -> V_27 ) ;
}
static T_1
F_63 ( struct V_42 * V_73 , struct V_74 * V_75 , char * V_76 )
{
struct V_99 * V_100 = F_64 ( V_73 ) ;
return sprintf ( V_76 , L_4 , V_100 -> type ) ;
}
static T_1
F_65 ( struct V_42 * V_73 , struct V_74 * V_75 , char * V_76 )
{
long V_32 ;
int V_41 ;
struct V_101 * V_102
= F_41 ( V_75 , struct V_101 , V_75 ) ;
struct V_103 * V_68
= F_41 ( V_102 , struct V_103 ,
V_104 ) ;
struct V_7 * V_26 = V_68 -> V_26 ;
V_41 = V_26 -> V_30 -> V_69 ( V_26 , & V_32 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_32 ) ;
}
static T_1
F_66 ( struct V_42 * V_73 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_101 * V_102
= F_41 ( V_75 , struct V_101 , V_75 ) ;
struct V_103 * V_68
= F_41 ( V_102 , struct V_103 ,
V_105 ) ;
struct V_7 * V_26 = V_68 -> V_26 ;
long V_32 ;
int V_41 ;
V_41 = V_26 -> V_30 -> V_63 ( V_26 , 0 , & V_32 ) ;
if ( V_41 )
return V_41 ;
return sprintf ( V_76 , L_5 , V_32 ) ;
}
static struct V_99 *
F_67 ( const struct V_7 * V_26 )
{
struct V_99 * V_100 ;
F_5 ( & V_13 ) ;
F_2 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_100 -> type , V_26 -> type ) ) {
F_7 ( & V_13 ) ;
return V_100 ;
}
F_7 ( & V_13 ) ;
return NULL ;
}
static struct V_103 *
F_68 ( const struct V_99 * V_100 ,
const struct V_7 * V_26 )
{
struct V_103 * V_68 ;
F_5 ( & V_13 ) ;
F_2 (temp, &hwmon->tz_list, hwmon_node)
if ( V_68 -> V_26 == V_26 ) {
F_7 ( & V_13 ) ;
return V_68 ;
}
F_7 ( & V_13 ) ;
return NULL ;
}
static int
F_69 ( struct V_7 * V_26 )
{
struct V_99 * V_100 ;
struct V_103 * V_68 ;
int V_106 = 1 ;
int V_80 ;
V_100 = F_67 ( V_26 ) ;
if ( V_100 ) {
V_106 = 0 ;
goto V_107;
}
V_100 = F_70 ( sizeof( struct V_99 ) , V_22 ) ;
if ( ! V_100 )
return - V_23 ;
F_71 ( & V_100 -> V_108 ) ;
F_72 ( V_100 -> type , V_26 -> type , V_4 ) ;
V_100 -> V_42 = F_73 ( NULL ) ;
if ( F_74 ( V_100 -> V_42 ) ) {
V_80 = F_75 ( V_100 -> V_42 ) ;
goto V_109;
}
F_76 ( V_100 -> V_42 , V_100 ) ;
V_80 = F_77 ( V_100 -> V_42 , & V_110 ) ;
if ( V_80 )
goto V_109;
V_107:
V_68 = F_70 ( sizeof( struct V_103 ) , V_22 ) ;
if ( ! V_68 ) {
V_80 = - V_23 ;
goto V_111;
}
V_68 -> V_26 = V_26 ;
V_100 -> V_70 ++ ;
snprintf ( V_68 -> V_104 . V_2 , sizeof( V_68 -> V_104 . V_2 ) ,
L_19 , V_100 -> V_70 ) ;
V_68 -> V_104 . V_75 . V_75 . V_2 = V_68 -> V_104 . V_2 ;
V_68 -> V_104 . V_75 . V_75 . V_79 = 0444 ;
V_68 -> V_104 . V_75 . V_112 = F_65 ;
F_78 ( & V_68 -> V_104 . V_75 . V_75 ) ;
V_80 = F_77 ( V_100 -> V_42 , & V_68 -> V_104 . V_75 ) ;
if ( V_80 )
goto V_113;
if ( V_26 -> V_30 -> V_114 ) {
unsigned long V_32 ;
if ( ! V_26 -> V_30 -> V_114 ( V_26 , & V_32 ) ) {
snprintf ( V_68 -> V_105 . V_2 ,
sizeof( V_68 -> V_105 . V_2 ) ,
L_20 , V_100 -> V_70 ) ;
V_68 -> V_105 . V_75 . V_75 . V_2 = V_68 -> V_105 . V_2 ;
V_68 -> V_105 . V_75 . V_75 . V_79 = 0444 ;
V_68 -> V_105 . V_75 . V_112 = F_66 ;
F_78 ( & V_68 -> V_105 . V_75 . V_75 ) ;
V_80 = F_77 ( V_100 -> V_42 ,
& V_68 -> V_105 . V_75 ) ;
if ( V_80 )
goto V_115;
}
}
F_5 ( & V_13 ) ;
if ( V_106 )
F_79 ( & V_100 -> V_116 , & V_117 ) ;
F_79 ( & V_68 -> V_118 , & V_100 -> V_108 ) ;
F_7 ( & V_13 ) ;
return 0 ;
V_115:
F_80 ( V_100 -> V_42 , & V_68 -> V_104 . V_75 ) ;
V_113:
F_81 ( V_68 ) ;
V_111:
if ( V_106 ) {
F_80 ( V_100 -> V_42 , & V_110 ) ;
F_82 ( V_100 -> V_42 ) ;
}
V_109:
if ( V_106 )
F_81 ( V_100 ) ;
return V_80 ;
}
static void
F_83 ( struct V_7 * V_26 )
{
struct V_99 * V_100 ;
struct V_103 * V_68 ;
V_100 = F_67 ( V_26 ) ;
if ( F_11 ( ! V_100 ) ) {
F_84 ( & V_26 -> V_42 , L_21 ) ;
return;
}
V_68 = F_68 ( V_100 , V_26 ) ;
if ( F_11 ( ! V_68 ) ) {
F_84 ( & V_26 -> V_42 , L_22 ) ;
return;
}
F_80 ( V_100 -> V_42 , & V_68 -> V_104 . V_75 ) ;
if ( V_26 -> V_30 -> V_114 )
F_80 ( V_100 -> V_42 , & V_68 -> V_105 . V_75 ) ;
F_5 ( & V_13 ) ;
F_9 ( & V_68 -> V_118 ) ;
F_81 ( V_68 ) ;
if ( ! F_85 ( & V_100 -> V_108 ) ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_100 -> V_116 ) ;
F_7 ( & V_13 ) ;
F_80 ( V_100 -> V_42 , & V_110 ) ;
F_82 ( V_100 -> V_42 ) ;
F_81 ( V_100 ) ;
}
static int
F_69 ( struct V_7 * V_26 )
{
return 0 ;
}
static void
F_83 ( struct V_7 * V_26 )
{
}
int F_21 ( struct V_7 * V_26 ,
int V_27 ,
struct V_38 * V_39 ,
unsigned long V_119 , unsigned long V_120 )
{
struct V_37 * V_73 ;
struct V_37 * V_3 ;
struct V_7 * V_121 ;
struct V_38 * V_122 ;
unsigned long V_123 ;
int V_80 ;
if ( V_27 >= V_26 -> V_45 || ( V_27 < 0 && V_27 != V_92 ) )
return - V_8 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_121 == V_26 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_122 == V_39 )
break;
}
if ( V_26 != V_121 || V_39 != V_122 )
return - V_8 ;
V_39 -> V_30 -> V_95 ( V_39 , & V_123 ) ;
V_120 = V_120 == V_46 ? 0 : V_120 ;
V_119 = V_119 == V_46 ? V_123 : V_119 ;
if ( V_120 > V_119 || V_119 > V_123 )
return - V_8 ;
V_73 =
F_70 ( sizeof( struct V_37 ) , V_22 ) ;
if ( ! V_73 )
return - V_23 ;
V_73 -> V_26 = V_26 ;
V_73 -> V_39 = V_39 ;
V_73 -> V_27 = V_27 ;
V_73 -> V_119 = V_119 ;
V_73 -> V_120 = V_120 ;
V_73 -> V_124 = V_125 ;
V_80 = F_10 ( & V_26 -> V_17 , & V_26 -> V_19 , & V_73 -> V_20 ) ;
if ( V_80 )
goto V_109;
sprintf ( V_73 -> V_2 , L_23 , V_73 -> V_20 ) ;
V_80 =
F_86 ( & V_26 -> V_42 . V_126 , & V_39 -> V_42 . V_126 , V_73 -> V_2 ) ;
if ( V_80 )
goto F_14;
sprintf ( V_73 -> V_127 , L_24 , V_73 -> V_20 ) ;
F_78 ( & V_73 -> V_75 . V_75 ) ;
V_73 -> V_75 . V_75 . V_2 = V_73 -> V_127 ;
V_73 -> V_75 . V_75 . V_79 = 0444 ;
V_73 -> V_75 . V_112 = F_62 ;
V_80 = F_77 ( & V_26 -> V_42 , & V_73 -> V_75 ) ;
if ( V_80 )
goto V_128;
F_5 ( & V_26 -> V_19 ) ;
F_5 ( & V_39 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_26 == V_26 && V_3 -> V_27 == V_27 && V_3 -> V_39 == V_39 ) {
V_80 = - V_129 ;
break;
}
if ( ! V_80 ) {
F_79 ( & V_73 -> V_130 , & V_26 -> V_131 ) ;
F_79 ( & V_73 -> V_132 , & V_39 -> V_131 ) ;
}
F_7 ( & V_39 -> V_19 ) ;
F_7 ( & V_26 -> V_19 ) ;
if ( ! V_80 )
return 0 ;
F_80 ( & V_26 -> V_42 , & V_73 -> V_75 ) ;
V_128:
F_87 ( & V_26 -> V_42 . V_126 , V_73 -> V_2 ) ;
F_14:
F_14 ( & V_26 -> V_17 , & V_26 -> V_19 , V_73 -> V_20 ) ;
V_109:
F_81 ( V_73 ) ;
return V_80 ;
}
int F_23 ( struct V_7 * V_26 ,
int V_27 ,
struct V_38 * V_39 )
{
struct V_37 * V_3 , * V_133 ;
F_5 ( & V_26 -> V_19 ) ;
F_5 ( & V_39 -> V_19 ) ;
F_88 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_26 == V_26 && V_3 -> V_27 == V_27 && V_3 -> V_39 == V_39 ) {
F_9 ( & V_3 -> V_130 ) ;
F_9 ( & V_3 -> V_132 ) ;
F_7 ( & V_39 -> V_19 ) ;
F_7 ( & V_26 -> V_19 ) ;
goto V_134;
}
}
F_7 ( & V_39 -> V_19 ) ;
F_7 ( & V_26 -> V_19 ) ;
return - V_135 ;
V_134:
F_80 ( & V_26 -> V_42 , & V_3 -> V_75 ) ;
F_87 ( & V_26 -> V_42 . V_126 , V_3 -> V_2 ) ;
F_14 ( & V_26 -> V_17 , & V_26 -> V_19 , V_3 -> V_20 ) ;
F_81 ( V_3 ) ;
return 0 ;
}
static void F_89 ( struct V_42 * V_73 )
{
struct V_7 * V_26 ;
struct V_38 * V_39 ;
if ( ! strncmp ( F_90 ( V_73 ) , L_25 ,
sizeof( L_25 ) - 1 ) ) {
V_26 = F_43 ( V_73 ) ;
F_81 ( V_26 ) ;
} else {
V_39 = F_58 ( V_73 ) ;
F_81 ( V_39 ) ;
}
}
struct V_38 *
F_91 ( char * type , void * V_136 ,
const struct V_137 * V_30 )
{
struct V_38 * V_39 ;
int V_80 ;
if ( type && strlen ( type ) >= V_4 )
return F_92 ( - V_8 ) ;
if ( ! V_30 || ! V_30 -> V_95 || ! V_30 -> V_96 ||
! V_30 -> V_97 )
return F_92 ( - V_8 ) ;
V_39 = F_70 ( sizeof( struct V_38 ) , V_22 ) ;
if ( ! V_39 )
return F_92 ( - V_23 ) ;
V_80 = F_10 ( & V_138 , & V_139 , & V_39 -> V_20 ) ;
if ( V_80 ) {
F_81 ( V_39 ) ;
return F_92 ( V_80 ) ;
}
strcpy ( V_39 -> type , type ? : L_26 ) ;
F_93 ( & V_39 -> V_19 ) ;
F_71 ( & V_39 -> V_131 ) ;
V_39 -> V_30 = V_30 ;
V_39 -> V_140 = true ;
V_39 -> V_42 . V_141 = & V_142 ;
V_39 -> V_136 = V_136 ;
F_94 ( & V_39 -> V_42 , L_27 , V_39 -> V_20 ) ;
V_80 = F_95 ( & V_39 -> V_42 ) ;
if ( V_80 ) {
F_14 ( & V_138 , & V_139 , V_39 -> V_20 ) ;
F_81 ( V_39 ) ;
return F_92 ( V_80 ) ;
}
if ( type ) {
V_80 = F_77 ( & V_39 -> V_42 , & V_143 ) ;
if ( V_80 )
goto V_144;
}
V_80 = F_77 ( & V_39 -> V_42 , & V_145 ) ;
if ( V_80 )
goto V_144;
V_80 = F_77 ( & V_39 -> V_42 , & V_146 ) ;
if ( V_80 )
goto V_144;
F_5 ( & V_13 ) ;
F_6 ( & V_39 -> V_116 , & V_147 ) ;
F_7 ( & V_13 ) ;
F_24 ( V_39 ) ;
return V_39 ;
V_144:
F_14 ( & V_138 , & V_139 , V_39 -> V_20 ) ;
F_96 ( & V_39 -> V_42 ) ;
return F_92 ( V_80 ) ;
}
void F_97 ( struct V_38 * V_39 )
{
int V_44 ;
const struct V_47 * V_14 ;
struct V_7 * V_26 ;
struct V_38 * V_3 = NULL ;
if ( ! V_39 )
return;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_39 )
break;
if ( V_3 != V_39 ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_39 -> V_116 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_26 -> V_30 -> V_134 ) {
V_26 -> V_30 -> V_134 ( V_26 , V_39 ) ;
continue;
}
if ( ! V_26 -> V_14 || ! V_26 -> V_14 -> V_49 )
continue;
V_14 = V_26 -> V_14 ;
for ( V_44 = 0 ; V_44 < V_14 -> V_50 ; V_44 ++ ) {
if ( V_14 -> V_49 [ V_44 ] . V_39 == V_39 ) {
F_22 ( V_26 , V_14 -> V_49 [ V_44 ] . V_52 , V_39 ) ;
V_14 -> V_49 [ V_44 ] . V_39 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
if ( V_39 -> type [ 0 ] )
F_80 ( & V_39 -> V_42 , & V_143 ) ;
F_80 ( & V_39 -> V_42 , & V_145 ) ;
F_80 ( & V_39 -> V_42 , & V_146 ) ;
F_14 ( & V_138 , & V_139 , V_39 -> V_20 ) ;
F_96 ( & V_39 -> V_42 ) ;
return;
}
void F_98 ( struct V_38 * V_39 )
{
struct V_37 * V_98 ;
unsigned long V_124 = 0 ;
if ( V_39 -> V_140 )
return;
F_5 ( & V_39 -> V_19 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
if ( V_98 -> V_124 == V_125 )
continue;
if ( V_98 -> V_124 > V_124 )
V_124 = V_98 -> V_124 ;
}
F_7 ( & V_39 -> V_19 ) ;
V_39 -> V_30 -> V_97 ( V_39 , V_124 ) ;
V_39 -> V_140 = true ;
}
void F_99 ( struct V_7 * V_26 , int V_27 )
{
F_36 ( V_26 , V_27 ) ;
}
static int F_100 ( struct V_7 * V_26 , int V_43 )
{
int V_148 ;
int V_149 = sizeof( struct V_150 ) * V_26 -> V_45 ;
V_26 -> V_151 = F_70 ( V_149 , V_22 ) ;
if ( ! V_26 -> V_151 )
return - V_23 ;
V_26 -> V_152 = F_70 ( V_149 , V_22 ) ;
if ( ! V_26 -> V_152 ) {
F_81 ( V_26 -> V_151 ) ;
return - V_23 ;
}
if ( V_26 -> V_30 -> V_89 ) {
V_26 -> V_153 = F_70 ( V_149 , V_22 ) ;
if ( ! V_26 -> V_153 ) {
F_81 ( V_26 -> V_151 ) ;
F_81 ( V_26 -> V_152 ) ;
return - V_23 ;
}
}
for ( V_148 = 0 ; V_148 < V_26 -> V_45 ; V_148 ++ ) {
snprintf ( V_26 -> V_151 [ V_148 ] . V_2 , V_4 ,
L_8 , V_148 ) ;
F_78 ( & V_26 -> V_151 [ V_148 ] . V_75 . V_75 ) ;
V_26 -> V_151 [ V_148 ] . V_75 . V_75 . V_2 =
V_26 -> V_151 [ V_148 ] . V_2 ;
V_26 -> V_151 [ V_148 ] . V_75 . V_75 . V_79 = V_154 ;
V_26 -> V_151 [ V_148 ] . V_75 . V_112 = F_47 ;
F_77 ( & V_26 -> V_42 ,
& V_26 -> V_151 [ V_148 ] . V_75 ) ;
snprintf ( V_26 -> V_152 [ V_148 ] . V_2 , V_4 ,
L_14 , V_148 ) ;
F_78 ( & V_26 -> V_152 [ V_148 ] . V_75 . V_75 ) ;
V_26 -> V_152 [ V_148 ] . V_75 . V_75 . V_2 =
V_26 -> V_152 [ V_148 ] . V_2 ;
V_26 -> V_152 [ V_148 ] . V_75 . V_75 . V_79 = V_154 ;
V_26 -> V_152 [ V_148 ] . V_75 . V_112 = F_50 ;
if ( V_43 & ( 1 << V_148 ) ) {
V_26 -> V_152 [ V_148 ] . V_75 . V_75 . V_79 |= V_155 ;
V_26 -> V_152 [ V_148 ] . V_75 . V_156 =
F_48 ;
}
F_77 ( & V_26 -> V_42 ,
& V_26 -> V_152 [ V_148 ] . V_75 ) ;
if ( ! V_26 -> V_30 -> V_89 )
continue;
snprintf ( V_26 -> V_153 [ V_148 ] . V_2 , V_4 ,
L_15 , V_148 ) ;
F_78 ( & V_26 -> V_153 [ V_148 ] . V_75 . V_75 ) ;
V_26 -> V_153 [ V_148 ] . V_75 . V_75 . V_2 =
V_26 -> V_153 [ V_148 ] . V_2 ;
V_26 -> V_153 [ V_148 ] . V_75 . V_75 . V_79 = V_154 ;
V_26 -> V_153 [ V_148 ] . V_75 . V_112 = F_52 ;
if ( V_26 -> V_30 -> V_88 ) {
V_26 -> V_153 [ V_148 ] . V_75 . V_75 . V_79 |= V_155 ;
V_26 -> V_153 [ V_148 ] . V_75 . V_156 =
F_51 ;
}
F_77 ( & V_26 -> V_42 ,
& V_26 -> V_153 [ V_148 ] . V_75 ) ;
}
return 0 ;
}
static void F_101 ( struct V_7 * V_26 )
{
int V_148 ;
for ( V_148 = 0 ; V_148 < V_26 -> V_45 ; V_148 ++ ) {
F_80 ( & V_26 -> V_42 ,
& V_26 -> V_151 [ V_148 ] . V_75 ) ;
F_80 ( & V_26 -> V_42 ,
& V_26 -> V_152 [ V_148 ] . V_75 ) ;
if ( V_26 -> V_30 -> V_89 )
F_80 ( & V_26 -> V_42 ,
& V_26 -> V_153 [ V_148 ] . V_75 ) ;
}
F_81 ( V_26 -> V_151 ) ;
F_81 ( V_26 -> V_152 ) ;
F_81 ( V_26 -> V_153 ) ;
}
struct V_7 * F_102 ( const char * type ,
int V_45 , int V_43 , void * V_136 ,
const struct V_157 * V_30 ,
const struct V_47 * V_14 ,
int V_57 , int V_58 )
{
struct V_7 * V_26 ;
enum V_59 V_60 ;
int V_80 ;
int V_70 ;
int V_56 = 0 ;
if ( type && strlen ( type ) >= V_4 )
return F_92 ( - V_8 ) ;
if ( V_45 > V_158 || V_45 < 0 || V_43 > > V_45 )
return F_92 ( - V_8 ) ;
if ( ! V_30 || ! V_30 -> V_69 )
return F_92 ( - V_8 ) ;
V_26 = F_70 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_26 )
return F_92 ( - V_23 ) ;
F_71 ( & V_26 -> V_131 ) ;
F_103 ( & V_26 -> V_17 ) ;
F_93 ( & V_26 -> V_19 ) ;
V_80 = F_10 ( & V_159 , & V_139 , & V_26 -> V_20 ) ;
if ( V_80 ) {
F_81 ( V_26 ) ;
return F_92 ( V_80 ) ;
}
strcpy ( V_26 -> type , type ? : L_26 ) ;
V_26 -> V_30 = V_30 ;
V_26 -> V_14 = V_14 ;
V_26 -> V_42 . V_141 = & V_142 ;
V_26 -> V_136 = V_136 ;
V_26 -> V_45 = V_45 ;
V_26 -> V_57 = V_57 ;
V_26 -> V_58 = V_58 ;
F_94 ( & V_26 -> V_42 , L_28 , V_26 -> V_20 ) ;
V_80 = F_95 ( & V_26 -> V_42 ) ;
if ( V_80 ) {
F_14 ( & V_159 , & V_139 , V_26 -> V_20 ) ;
F_81 ( V_26 ) ;
return F_92 ( V_80 ) ;
}
if ( type ) {
V_80 = F_77 ( & V_26 -> V_42 , & V_160 ) ;
if ( V_80 )
goto V_144;
}
V_80 = F_77 ( & V_26 -> V_42 , & V_161 ) ;
if ( V_80 )
goto V_144;
if ( V_30 -> V_81 ) {
V_80 = F_77 ( & V_26 -> V_42 , & V_162 ) ;
if ( V_80 )
goto V_144;
}
V_80 = F_100 ( V_26 , V_43 ) ;
if ( V_80 )
goto V_144;
for ( V_70 = 0 ; V_70 < V_45 ; V_70 ++ ) {
V_26 -> V_30 -> V_66 ( V_26 , V_70 , & V_60 ) ;
if ( V_60 == V_85 )
V_56 = 1 ;
}
if ( ! V_56 ) {
V_80 = F_77 ( & V_26 -> V_42 , & V_163 ) ;
if ( V_80 )
goto V_144;
}
V_80 = F_77 ( & V_26 -> V_42 , & V_164 ) ;
if ( V_80 )
goto V_144;
F_5 ( & V_9 ) ;
if ( V_26 -> V_14 )
V_26 -> V_5 = F_1 ( V_26 -> V_14 -> V_15 ) ;
else
V_26 -> V_5 = F_1 ( V_16 ) ;
F_7 ( & V_9 ) ;
V_80 = F_69 ( V_26 ) ;
if ( V_80 )
goto V_144;
F_5 ( & V_13 ) ;
F_79 ( & V_26 -> V_116 , & V_165 ) ;
F_7 ( & V_13 ) ;
F_25 ( V_26 ) ;
F_104 ( & ( V_26 -> V_55 ) , F_40 ) ;
F_39 ( V_26 ) ;
if ( ! V_80 )
return V_26 ;
V_144:
F_14 ( & V_159 , & V_139 , V_26 -> V_20 ) ;
F_96 ( & V_26 -> V_42 ) ;
return F_92 ( V_80 ) ;
}
void F_105 ( struct V_7 * V_26 )
{
int V_44 ;
const struct V_47 * V_14 ;
struct V_38 * V_39 ;
struct V_7 * V_3 = NULL ;
if ( ! V_26 )
return;
V_14 = V_26 -> V_14 ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( V_3 == V_26 )
break;
if ( V_3 != V_26 ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_26 -> V_116 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_26 -> V_30 -> V_134 ) {
V_26 -> V_30 -> V_134 ( V_26 , V_39 ) ;
continue;
}
if ( ! V_14 || ! V_14 -> V_49 )
break;
for ( V_44 = 0 ; V_44 < V_14 -> V_50 ; V_44 ++ ) {
if ( V_14 -> V_49 [ V_44 ] . V_39 == V_39 ) {
F_22 ( V_26 , V_14 -> V_49 [ V_44 ] . V_52 , V_39 ) ;
V_14 -> V_49 [ V_44 ] . V_39 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
F_26 ( V_26 , 0 ) ;
if ( V_26 -> type [ 0 ] )
F_80 ( & V_26 -> V_42 , & V_160 ) ;
F_80 ( & V_26 -> V_42 , & V_161 ) ;
if ( V_26 -> V_30 -> V_81 )
F_80 ( & V_26 -> V_42 , & V_162 ) ;
F_80 ( & V_26 -> V_42 , & V_164 ) ;
F_101 ( V_26 ) ;
V_26 -> V_5 = NULL ;
F_83 ( V_26 ) ;
F_14 ( & V_159 , & V_139 , V_26 -> V_20 ) ;
F_106 ( & V_26 -> V_17 ) ;
F_107 ( & V_26 -> V_19 ) ;
F_96 ( & V_26 -> V_42 ) ;
return;
}
int F_108 ( T_3 V_166 , enum V_167 V_168 )
{
struct V_169 * V_170 ;
struct V_171 * V_75 ;
struct V_172 * V_173 ;
void * V_174 ;
int V_149 ;
int V_80 ;
static unsigned int V_175 ;
V_149 = F_109 ( sizeof( struct V_172 ) ) +
F_109 ( 0 ) ;
V_170 = F_110 ( V_149 , V_176 ) ;
if ( ! V_170 )
return - V_23 ;
V_174 = F_111 ( V_170 , 0 , V_175 ++ ,
& V_177 , 0 ,
V_178 ) ;
if ( ! V_174 ) {
F_112 ( V_170 ) ;
return - V_23 ;
}
V_75 = F_113 ( V_170 , V_179 ,
sizeof( struct V_172 ) ) ;
if ( ! V_75 ) {
F_112 ( V_170 ) ;
return - V_8 ;
}
V_173 = F_114 ( V_75 ) ;
if ( ! V_173 ) {
F_112 ( V_170 ) ;
return - V_8 ;
}
memset ( V_173 , 0 , sizeof( struct V_172 ) ) ;
V_173 -> V_166 = V_166 ;
V_173 -> V_168 = V_168 ;
V_80 = F_115 ( V_170 , V_174 ) ;
if ( V_80 < 0 ) {
F_112 ( V_170 ) ;
return V_80 ;
}
V_80 = F_116 ( V_170 , 0 , V_180 . V_20 , V_176 ) ;
if ( V_80 )
F_117 ( L_29 , V_80 ) ;
return V_80 ;
}
static int F_118 ( void )
{
int V_80 ;
V_80 = F_119 ( & V_177 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_120 ( & V_177 ,
& V_180 ) ;
if ( V_80 )
F_121 ( & V_177 ) ;
return V_80 ;
}
static void F_122 ( void )
{
F_121 ( & V_177 ) ;
}
static inline int F_118 ( void ) { return 0 ; }
static inline void F_122 ( void ) {}
static int T_4 F_123 ( void )
{
int V_80 = 0 ;
V_80 = F_124 ( & V_142 ) ;
if ( V_80 ) {
F_106 ( & V_159 ) ;
F_106 ( & V_138 ) ;
F_107 ( & V_139 ) ;
F_107 ( & V_13 ) ;
}
V_80 = F_118 () ;
return V_80 ;
}
static void T_5 F_125 ( void )
{
F_126 ( & V_142 ) ;
F_106 ( & V_159 ) ;
F_106 ( & V_138 ) ;
F_107 ( & V_139 ) ;
F_107 ( & V_13 ) ;
F_122 () ;
}
