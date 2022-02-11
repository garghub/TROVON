static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 || ! V_2 [ 0 ] )
return V_4 ;
F_2 (pos, &thermal_governor_list, governor_list)
if ( ! strncasecmp ( V_2 , V_3 -> V_2 , V_5 ) )
return V_3 ;
return NULL ;
}
static void F_3 ( struct V_6 * V_7 ,
const char * V_8 )
{
if ( V_7 -> V_9 && V_7 -> V_9 -> V_10 ) {
if ( V_7 -> V_9 -> V_10 ( V_7 ) ) {
F_4 ( & V_7 -> V_11 ,
L_1 ,
V_8 , V_7 -> V_9 -> V_2 , V_7 -> type ) ;
V_7 -> V_9 = NULL ;
}
}
}
static int F_5 ( struct V_6 * V_7 ,
struct V_1 * V_12 )
{
int V_13 = 0 ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_14 )
V_7 -> V_9 -> V_14 ( V_7 ) ;
if ( V_12 && V_12 -> V_10 ) {
V_13 = V_12 -> V_10 ( V_7 ) ;
if ( V_13 ) {
F_3 ( V_7 , V_12 -> V_2 ) ;
return V_13 ;
}
}
V_7 -> V_9 = V_12 ;
return V_13 ;
}
int F_6 ( struct V_1 * V_9 )
{
int V_15 ;
const char * V_2 ;
struct V_6 * V_3 ;
if ( ! V_9 )
return - V_16 ;
F_7 ( & V_17 ) ;
V_15 = - V_18 ;
if ( F_1 ( V_9 -> V_2 ) == NULL ) {
V_15 = 0 ;
F_8 ( & V_9 -> V_19 , & V_20 ) ;
if ( ! V_4 && ! strncmp ( V_9 -> V_2 ,
V_21 , V_5 ) )
V_4 = V_9 ;
}
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( V_3 -> V_9 )
continue;
V_2 = V_3 -> V_23 -> V_24 ;
if ( ! strncasecmp ( V_2 , V_9 -> V_2 , V_5 ) ) {
int V_13 ;
V_13 = F_5 ( V_3 , V_9 ) ;
if ( V_13 )
F_4 ( & V_3 -> V_11 ,
L_2 ,
V_9 -> V_2 , V_3 -> type , V_13 ) ;
}
}
F_9 ( & V_22 ) ;
F_9 ( & V_17 ) ;
return V_15 ;
}
void F_10 ( struct V_1 * V_9 )
{
struct V_6 * V_3 ;
if ( ! V_9 )
return;
F_7 ( & V_17 ) ;
if ( F_1 ( V_9 -> V_2 ) == NULL )
goto exit;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! strncasecmp ( V_3 -> V_9 -> V_2 , V_9 -> V_2 ,
V_5 ) )
F_5 ( V_3 , NULL ) ;
}
F_9 ( & V_22 ) ;
F_11 ( & V_9 -> V_19 ) ;
exit:
F_9 ( & V_17 ) ;
return;
}
static int F_12 ( struct V_25 * V_25 , struct V_26 * V_27 , int * V_28 )
{
int V_13 ;
if ( V_27 )
F_7 ( V_27 ) ;
V_13 = F_13 ( V_25 , NULL , 0 , 0 , V_29 ) ;
if ( V_27 )
F_9 ( V_27 ) ;
if ( F_14 ( V_13 < 0 ) )
return V_13 ;
* V_28 = V_13 ;
return 0 ;
}
static void F_15 ( struct V_25 * V_25 , struct V_26 * V_27 , int V_28 )
{
if ( V_27 )
F_7 ( V_27 ) ;
F_16 ( V_25 , V_28 ) ;
if ( V_27 )
F_9 ( V_27 ) ;
}
int F_17 ( struct V_6 * V_7 , int V_30 )
{
enum V_31 V_32 ;
if ( V_7 -> V_33 || ! V_7 -> V_34 -> V_35 ||
V_7 -> V_34 -> V_35 ( V_7 , V_30 , & V_32 ) ) {
if ( V_7 -> V_36 > V_7 -> V_37 )
V_32 = V_38 ;
else if ( V_7 -> V_36 < V_7 -> V_37 )
V_32 = V_39 ;
else
V_32 = V_40 ;
}
return V_32 ;
}
struct V_41 * F_18 ( struct V_6 * V_7 ,
struct V_42 * V_43 , int V_30 )
{
struct V_41 * V_3 = NULL ;
struct V_41 * V_44 = NULL ;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_2 (pos, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
V_44 = V_3 ;
break;
}
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
return V_44 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_42 * V_43 , int V_13 )
{
F_4 ( & V_7 -> V_11 , L_3 ,
V_7 -> type , V_43 -> type , V_13 ) ;
}
static void F_20 ( struct V_6 * V_7 , int V_45 ,
struct V_42 * V_43 ,
unsigned long * V_46 ,
unsigned int V_47 )
{
int V_48 , V_13 ;
for ( V_48 = 0 ; V_48 < V_7 -> V_49 ; V_48 ++ ) {
if ( V_45 & ( 1 << V_48 ) ) {
unsigned long V_50 , V_51 ;
V_50 = V_52 ;
V_51 = V_52 ;
if ( V_46 ) {
V_51 = V_46 [ V_48 * 2 ] ;
V_50 = V_46 [ V_48 * 2 + 1 ] ;
}
V_13 = F_21 ( V_7 , V_48 , V_43 ,
V_50 , V_51 ,
V_47 ) ;
if ( V_13 )
F_19 ( V_7 , V_43 , V_13 ) ;
}
}
}
static void F_22 ( struct V_6 * V_7 , int V_45 ,
struct V_42 * V_43 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_7 -> V_49 ; V_48 ++ )
if ( V_45 & ( 1 << V_48 ) )
F_23 ( V_7 , V_48 , V_43 ) ;
}
static void F_24 ( struct V_42 * V_43 )
{
int V_48 , V_13 ;
const struct V_53 * V_23 ;
struct V_6 * V_3 = NULL ;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_23 && ! V_3 -> V_34 -> V_54 )
continue;
if ( V_3 -> V_34 -> V_54 ) {
V_13 = V_3 -> V_34 -> V_54 ( V_3 , V_43 ) ;
if ( V_13 )
F_19 ( V_3 , V_43 , V_13 ) ;
continue;
}
V_23 = V_3 -> V_23 ;
if ( ! V_23 || ! V_23 -> V_55 )
continue;
for ( V_48 = 0 ; V_48 < V_23 -> V_56 ; V_48 ++ ) {
if ( V_23 -> V_55 [ V_48 ] . V_43 || ! V_23 -> V_55 [ V_48 ] . V_57 )
continue;
if ( V_23 -> V_55 [ V_48 ] . V_57 ( V_3 , V_43 ) )
continue;
V_23 -> V_55 [ V_48 ] . V_43 = V_43 ;
F_20 ( V_3 , V_23 -> V_55 [ V_48 ] . V_58 , V_43 ,
V_23 -> V_55 [ V_48 ] . V_59 ,
V_23 -> V_55 [ V_48 ] . V_47 ) ;
}
}
F_9 ( & V_22 ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
int V_48 , V_13 ;
struct V_42 * V_3 = NULL ;
const struct V_53 * V_23 = V_7 -> V_23 ;
if ( ! V_23 && ! V_7 -> V_34 -> V_54 )
return;
F_7 ( & V_22 ) ;
if ( V_7 -> V_34 -> V_54 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_13 = V_7 -> V_34 -> V_54 ( V_7 , V_3 ) ;
if ( V_13 )
F_19 ( V_7 , V_3 , V_13 ) ;
}
goto exit;
}
if ( ! V_23 || ! V_23 -> V_55 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_48 = 0 ; V_48 < V_23 -> V_56 ; V_48 ++ ) {
if ( V_23 -> V_55 [ V_48 ] . V_43 || ! V_23 -> V_55 [ V_48 ] . V_57 )
continue;
if ( V_23 -> V_55 [ V_48 ] . V_57 ( V_7 , V_3 ) )
continue;
V_23 -> V_55 [ V_48 ] . V_43 = V_3 ;
F_20 ( V_7 , V_23 -> V_55 [ V_48 ] . V_58 , V_3 ,
V_23 -> V_55 [ V_48 ] . V_59 ,
V_23 -> V_55 [ V_48 ] . V_47 ) ;
}
}
exit:
F_9 ( & V_22 ) ;
}
static void F_26 ( struct V_6 * V_7 ,
int V_60 )
{
if ( V_60 > 1000 )
F_27 ( V_61 , & V_7 -> V_62 ,
F_28 ( F_29 ( V_60 ) ) ) ;
else if ( V_60 )
F_27 ( V_61 , & V_7 -> V_62 ,
F_29 ( V_60 ) ) ;
else
F_30 ( & V_7 -> V_62 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_27 ) ;
if ( V_7 -> V_63 )
F_26 ( V_7 , V_7 -> V_64 ) ;
else if ( V_7 -> V_65 )
F_26 ( V_7 , V_7 -> V_65 ) ;
else
F_26 ( V_7 , 0 ) ;
F_9 ( & V_7 -> V_27 ) ;
}
static void F_32 ( struct V_6 * V_7 ,
int V_30 , enum V_66 V_67 )
{
V_7 -> V_9 ? V_7 -> V_9 -> V_68 ( V_7 , V_30 ) :
V_4 -> V_68 ( V_7 , V_30 ) ;
}
static void F_33 ( struct V_6 * V_7 ,
int V_30 , enum V_66 V_67 )
{
int V_69 ;
V_7 -> V_34 -> V_70 ( V_7 , V_30 , & V_69 ) ;
if ( V_69 <= 0 || V_7 -> V_36 < V_69 )
return;
F_34 ( V_7 , V_30 , V_67 ) ;
if ( V_7 -> V_34 -> V_71 )
V_7 -> V_34 -> V_71 ( V_7 , V_30 , V_67 ) ;
if ( V_67 == V_72 ) {
F_35 ( & V_7 -> V_11 ,
L_4 ,
V_7 -> V_36 / 1000 ) ;
F_36 ( true ) ;
}
}
static void F_37 ( struct V_6 * V_7 , int V_30 )
{
enum V_66 type ;
V_7 -> V_34 -> V_73 ( V_7 , V_30 , & type ) ;
if ( type == V_72 || type == V_74 )
F_33 ( V_7 , V_30 , type ) ;
else
F_32 ( V_7 , V_30 , type ) ;
F_31 ( V_7 ) ;
}
int F_38 ( struct V_6 * V_7 , int * V_75 )
{
int V_13 = - V_16 ;
int V_76 ;
int V_77 = V_78 ;
enum V_66 type ;
if ( ! V_7 || F_39 ( V_7 ) || ! V_7 -> V_34 -> V_79 )
goto exit;
F_7 ( & V_7 -> V_27 ) ;
V_13 = V_7 -> V_34 -> V_79 ( V_7 , V_75 ) ;
if ( F_40 ( V_80 ) && V_7 -> V_33 ) {
for ( V_76 = 0 ; V_76 < V_7 -> V_49 ; V_76 ++ ) {
V_13 = V_7 -> V_34 -> V_73 ( V_7 , V_76 , & type ) ;
if ( ! V_13 && type == V_72 ) {
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_76 ,
& V_77 ) ;
break;
}
}
if ( ! V_13 && * V_75 < V_77 )
* V_75 = V_7 -> V_33 ;
}
F_9 ( & V_7 -> V_27 ) ;
exit:
return V_13 ;
}
static void F_41 ( struct V_6 * V_7 )
{
int V_75 , V_13 ;
V_13 = F_38 ( V_7 , & V_75 ) ;
if ( V_13 ) {
if ( V_13 != - V_81 )
F_42 ( & V_7 -> V_11 ,
L_5 ,
V_13 ) ;
return;
}
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_37 = V_7 -> V_36 ;
V_7 -> V_36 = V_75 ;
F_9 ( & V_7 -> V_27 ) ;
F_43 ( V_7 ) ;
if ( V_7 -> V_37 == V_82 )
F_44 ( & V_7 -> V_11 , L_6 ,
V_7 -> V_36 ) ;
else
F_44 ( & V_7 -> V_11 , L_7 ,
V_7 -> V_37 , V_7 -> V_36 ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_41 * V_3 ;
V_7 -> V_36 = V_82 ;
V_7 -> V_63 = 0 ;
F_2 (pos, &tz->thermal_instances, tz_node)
V_3 -> V_83 = false ;
}
void F_46 ( struct V_6 * V_7 )
{
int V_76 ;
if ( F_47 ( & V_84 ) )
return;
if ( ! V_7 -> V_34 -> V_79 )
return;
F_41 ( V_7 ) ;
for ( V_76 = 0 ; V_76 < V_7 -> V_49 ; V_76 ++ )
F_37 ( V_7 , V_76 ) ;
}
static void F_48 ( struct V_85 * V_86 )
{
struct V_6 * V_7 = F_49 ( V_86 , struct
V_6 ,
V_62 . V_86 ) ;
F_46 ( V_7 ) ;
}
static T_1
F_50 ( struct V_11 * V_87 , struct V_88 * V_89 , char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
return sprintf ( V_90 , L_8 , V_7 -> type ) ;
}
static T_1
F_52 ( struct V_11 * V_87 , struct V_88 * V_89 , char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_36 , V_13 ;
V_13 = F_38 ( V_7 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_90 , L_9 , V_36 ) ;
}
static T_1
F_53 ( struct V_11 * V_87 , struct V_88 * V_89 , char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
enum V_91 V_92 ;
int V_93 ;
if ( ! V_7 -> V_34 -> V_94 )
return - V_95 ;
V_93 = V_7 -> V_34 -> V_94 ( V_7 , & V_92 ) ;
if ( V_93 )
return V_93 ;
return sprintf ( V_90 , L_8 , V_92 == V_96 ? L_10
: L_11 ) ;
}
static T_1
F_54 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_93 ;
if ( ! V_7 -> V_34 -> V_97 )
return - V_95 ;
if ( ! strncmp ( V_90 , L_10 , sizeof( L_10 ) - 1 ) )
V_93 = V_7 -> V_34 -> V_97 ( V_7 , V_96 ) ;
else if ( ! strncmp ( V_90 , L_11 , sizeof( L_11 ) - 1 ) )
V_93 = V_7 -> V_34 -> V_97 ( V_7 , V_98 ) ;
else
V_93 = - V_16 ;
if ( V_93 )
return V_93 ;
return V_76 ;
}
static T_1
F_55 ( struct V_11 * V_87 , struct V_88 * V_89 ,
char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
enum V_66 type ;
int V_30 , V_93 ;
if ( ! V_7 -> V_34 -> V_73 )
return - V_95 ;
if ( ! sscanf ( V_89 -> V_89 . V_2 , L_12 , & V_30 ) )
return - V_16 ;
V_93 = V_7 -> V_34 -> V_73 ( V_7 , V_30 , & type ) ;
if ( V_93 )
return V_93 ;
switch ( type ) {
case V_72 :
return sprintf ( V_90 , L_13 ) ;
case V_74 :
return sprintf ( V_90 , L_14 ) ;
case V_99 :
return sprintf ( V_90 , L_15 ) ;
case V_100 :
return sprintf ( V_90 , L_16 ) ;
default:
return sprintf ( V_90 , L_17 ) ;
}
}
static T_1
F_56 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_30 , V_13 ;
unsigned long V_36 ;
if ( ! V_7 -> V_34 -> V_101 )
return - V_95 ;
if ( ! sscanf ( V_89 -> V_89 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
if ( F_57 ( V_90 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_101 ( V_7 , V_30 , V_36 ) ;
if ( V_13 )
return V_13 ;
F_46 ( V_7 ) ;
return V_76 ;
}
static T_1
F_58 ( struct V_11 * V_87 , struct V_88 * V_89 ,
char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_70 )
return - V_95 ;
if ( ! sscanf ( V_89 -> V_89 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_30 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_90 , L_9 , V_36 ) ;
}
static T_1
F_59 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_102 )
return - V_95 ;
if ( ! sscanf ( V_89 -> V_89 . V_2 , L_19 , & V_30 ) )
return - V_16 ;
if ( F_60 ( V_90 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_102 ( V_7 , V_30 , V_36 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_61 ( struct V_11 * V_87 , struct V_88 * V_89 ,
char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_103 )
return - V_95 ;
if ( ! sscanf ( V_89 -> V_89 . V_2 , L_19 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_103 ( V_7 , V_30 , & V_36 ) ;
return V_13 ? V_13 : sprintf ( V_90 , L_9 , V_36 ) ;
}
static T_1
F_62 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
struct V_42 * V_43 = NULL ;
int V_104 ;
if ( ! sscanf ( V_90 , L_9 , & V_104 ) )
return - V_16 ;
if ( V_104 && V_104 < 1000 )
return - V_16 ;
if ( V_104 && ! V_7 -> V_105 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_20 , V_43 -> type ,
sizeof( L_20 ) ) )
F_21 ( V_7 ,
V_106 , V_43 ,
V_52 ,
V_52 ,
V_107 ) ;
}
F_9 ( & V_22 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = 1000 ;
} else if ( ! V_104 && V_7 -> V_105 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_20 , V_43 -> type ,
sizeof( L_20 ) ) )
F_23 ( V_7 ,
V_106 ,
V_43 ) ;
}
F_9 ( & V_22 ) ;
V_7 -> V_64 = 0 ;
}
V_7 -> V_105 = V_104 ;
F_46 ( V_7 ) ;
return V_76 ;
}
static T_1
F_63 ( struct V_11 * V_87 , struct V_88 * V_89 ,
char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
return sprintf ( V_90 , L_9 , V_7 -> V_105 ) ;
}
static T_1
F_64 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
int V_13 = - V_16 ;
struct V_6 * V_7 = F_51 ( V_87 ) ;
struct V_1 * V_108 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_21 , V_90 ) ;
F_7 ( & V_17 ) ;
F_7 ( & V_7 -> V_27 ) ;
V_108 = F_1 ( F_65 ( V_2 ) ) ;
if ( ! V_108 )
goto exit;
V_13 = F_5 ( V_7 , V_108 ) ;
if ( ! V_13 )
V_13 = V_76 ;
exit:
F_9 ( & V_7 -> V_27 ) ;
F_9 ( & V_17 ) ;
return V_13 ;
}
static T_1
F_66 ( struct V_11 * V_87 , struct V_88 * V_109 , char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
return sprintf ( V_90 , L_8 , V_7 -> V_9 -> V_2 ) ;
}
static T_1
F_67 ( struct V_11 * V_87 , struct V_88 * V_109 ,
char * V_90 )
{
struct V_1 * V_3 ;
T_1 V_76 = 0 ;
T_1 V_110 = V_111 ;
F_7 ( & V_17 ) ;
F_2 (pos, &thermal_governor_list, governor_list) {
V_110 = V_111 - V_76 ;
V_76 += F_68 ( V_90 + V_76 , V_110 , L_22 , V_3 -> V_2 ) ;
}
V_76 += F_68 ( V_90 + V_76 , V_110 , L_23 ) ;
F_9 ( & V_17 ) ;
return V_76 ;
}
static T_1
F_69 ( struct V_11 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
int V_13 = 0 ;
unsigned long V_36 ;
if ( F_57 ( V_90 , 10 , & V_36 ) )
return - V_16 ;
if ( ! V_7 -> V_34 -> V_112 ) {
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_33 = V_36 ;
F_9 ( & V_7 -> V_27 ) ;
} else {
V_13 = V_7 -> V_34 -> V_112 ( V_7 , V_36 ) ;
}
if ( ! V_13 )
F_46 ( V_7 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_70 ( struct V_11 * V_87 , struct V_88 * V_109 ,
char * V_90 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
if ( V_7 -> V_23 )
return sprintf ( V_90 , L_24 , V_7 -> V_23 -> V_113 ) ;
else
return - V_114 ;
}
static T_1
F_71 ( struct V_11 * V_87 , struct V_88 * V_109 ,
const char * V_90 , T_2 V_76 )
{
struct V_6 * V_7 = F_51 ( V_87 ) ;
T_3 V_113 ;
if ( ! V_7 -> V_23 )
return - V_114 ;
if ( F_72 ( V_90 , 10 , & V_113 ) )
return - V_16 ;
V_7 -> V_23 -> V_113 = V_113 ;
return V_76 ;
}
static int F_73 ( struct V_11 * V_87 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_74 ( V_115 ) ; V_48 ++ ) {
int V_13 ;
struct V_88 * V_116 = V_115 [ V_48 ] ;
V_13 = F_75 ( V_87 , V_116 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_76 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_117 )
{
if ( ! F_77 ( V_43 ) )
return - V_16 ;
return V_43 -> V_34 -> V_118 ( V_43 , V_7 , 0 , V_117 ) ;
}
int F_78 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_119 )
{
unsigned long V_120 ;
int V_13 ;
if ( ! F_77 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_121 ( V_43 , & V_120 ) ;
if ( V_13 )
return V_13 ;
return V_43 -> V_34 -> V_118 ( V_43 , V_7 , V_120 , V_119 ) ;
}
int F_79 ( struct V_42 * V_43 ,
struct V_41 * V_122 , T_3 V_123 )
{
unsigned long V_104 ;
int V_13 ;
if ( ! F_77 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_124 ( V_43 , V_122 -> V_7 , V_123 , & V_104 ) ;
if ( V_13 )
return V_13 ;
V_122 -> V_125 = V_104 ;
V_43 -> V_126 = false ;
F_80 ( V_43 ) ;
return 0 ;
}
static T_1
F_81 ( struct V_11 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_42 * V_43 = F_82 ( V_87 ) ;
return sprintf ( V_90 , L_8 , V_43 -> type ) ;
}
static T_1
F_83 ( struct V_11 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_42 * V_43 = F_82 ( V_87 ) ;
unsigned long V_104 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_121 ( V_43 , & V_104 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_90 , L_25 , V_104 ) ;
}
static T_1
F_84 ( struct V_11 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_42 * V_43 = F_82 ( V_87 ) ;
unsigned long V_104 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_127 ( V_43 , & V_104 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_90 , L_25 , V_104 ) ;
}
static T_1
F_85 ( struct V_11 * V_87 ,
struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_42 * V_43 = F_82 ( V_87 ) ;
unsigned long V_104 ;
int V_93 ;
if ( ! sscanf ( V_90 , L_25 , & V_104 ) )
return - V_16 ;
if ( ( long ) V_104 < 0 )
return - V_16 ;
V_93 = V_43 -> V_34 -> V_128 ( V_43 , V_104 ) ;
if ( V_93 )
return V_93 ;
return V_76 ;
}
static T_1
F_86 ( struct V_11 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_41 * V_122 ;
V_122 =
F_49 ( V_89 , struct V_41 , V_89 ) ;
if ( V_122 -> V_30 == V_106 )
return sprintf ( V_90 , L_26 ) ;
else
return sprintf ( V_90 , L_9 , V_122 -> V_30 ) ;
}
static T_1
F_87 ( struct V_11 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_41 * V_122 ;
V_122 = F_49 ( V_89 , struct V_41 , V_129 ) ;
return sprintf ( V_90 , L_9 , V_122 -> V_47 ) ;
}
static T_1
F_88 ( struct V_11 * V_87 ,
struct V_88 * V_89 ,
const char * V_90 , T_2 V_76 )
{
struct V_41 * V_122 ;
int V_13 , V_47 ;
V_13 = F_60 ( V_90 , 0 , & V_47 ) ;
if ( V_13 )
return V_13 ;
V_122 = F_49 ( V_89 , struct V_41 , V_129 ) ;
V_122 -> V_47 = V_47 ;
return V_76 ;
}
int F_21 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 ,
unsigned long V_50 , unsigned long V_51 ,
unsigned int V_47 )
{
struct V_41 * V_87 ;
struct V_41 * V_3 ;
struct V_6 * V_130 ;
struct V_42 * V_131 ;
unsigned long V_120 ;
int V_93 , V_13 ;
if ( V_30 >= V_7 -> V_49 || ( V_30 < 0 && V_30 != V_106 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_130 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_131 == V_43 )
break;
}
if ( V_7 != V_130 || V_43 != V_131 )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_121 ( V_43 , & V_120 ) ;
if ( V_13 )
return V_13 ;
V_51 = V_51 == V_52 ? 0 : V_51 ;
V_50 = V_50 == V_52 ? V_120 : V_50 ;
if ( V_51 > V_50 || V_50 > V_120 )
return - V_16 ;
V_87 =
F_89 ( sizeof( struct V_41 ) , V_29 ) ;
if ( ! V_87 )
return - V_132 ;
V_87 -> V_7 = V_7 ;
V_87 -> V_43 = V_43 ;
V_87 -> V_30 = V_30 ;
V_87 -> V_50 = V_50 ;
V_87 -> V_51 = V_51 ;
V_87 -> V_125 = V_133 ;
V_87 -> V_47 = V_47 ;
V_93 = F_12 ( & V_7 -> V_25 , & V_7 -> V_27 , & V_87 -> V_28 ) ;
if ( V_93 )
goto V_134;
sprintf ( V_87 -> V_2 , L_27 , V_87 -> V_28 ) ;
V_93 =
F_90 ( & V_7 -> V_11 . V_135 , & V_43 -> V_11 . V_135 , V_87 -> V_2 ) ;
if ( V_93 )
goto F_15;
sprintf ( V_87 -> V_136 , L_28 , V_87 -> V_28 ) ;
F_91 ( & V_87 -> V_89 . V_89 ) ;
V_87 -> V_89 . V_89 . V_2 = V_87 -> V_136 ;
V_87 -> V_89 . V_89 . V_92 = 0444 ;
V_87 -> V_89 . V_137 = F_86 ;
V_93 = F_75 ( & V_7 -> V_11 , & V_87 -> V_89 ) ;
if ( V_93 )
goto V_138;
sprintf ( V_87 -> V_139 , L_29 , V_87 -> V_28 ) ;
F_91 ( & V_87 -> V_129 . V_89 ) ;
V_87 -> V_129 . V_89 . V_2 = V_87 -> V_139 ;
V_87 -> V_129 . V_89 . V_92 = V_140 | V_141 ;
V_87 -> V_129 . V_137 = F_87 ;
V_87 -> V_129 . V_142 = F_88 ;
V_93 = F_75 ( & V_7 -> V_11 , & V_87 -> V_129 ) ;
if ( V_93 )
goto V_143;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
V_93 = - V_144 ;
break;
}
if ( ! V_93 ) {
F_92 ( & V_87 -> V_145 , & V_7 -> V_146 ) ;
F_92 ( & V_87 -> V_147 , & V_43 -> V_146 ) ;
F_93 ( & V_7 -> V_148 , 1 ) ;
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
if ( ! V_93 )
return 0 ;
F_94 ( & V_7 -> V_11 , & V_87 -> V_129 ) ;
V_143:
F_94 ( & V_7 -> V_11 , & V_87 -> V_89 ) ;
V_138:
F_95 ( & V_7 -> V_11 . V_135 , V_87 -> V_2 ) ;
F_15:
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_87 -> V_28 ) ;
V_134:
F_96 ( V_87 ) ;
return V_93 ;
}
int F_23 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 )
{
struct V_41 * V_3 , * V_149 ;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_97 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
F_11 ( & V_3 -> V_145 ) ;
F_11 ( & V_3 -> V_147 ) ;
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
goto V_150;
}
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
return - V_151 ;
V_150:
F_94 ( & V_7 -> V_11 , & V_3 -> V_129 ) ;
F_94 ( & V_7 -> V_11 , & V_3 -> V_89 ) ;
F_95 ( & V_7 -> V_11 . V_135 , V_3 -> V_2 ) ;
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_3 -> V_28 ) ;
F_96 ( V_3 ) ;
return 0 ;
}
static void F_98 ( struct V_11 * V_87 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( ! strncmp ( F_99 ( V_87 ) , L_30 ,
sizeof( L_30 ) - 1 ) ) {
V_7 = F_51 ( V_87 ) ;
F_96 ( V_7 ) ;
} else if( ! strncmp ( F_99 ( V_87 ) , L_31 ,
sizeof( L_31 ) - 1 ) ) {
V_43 = F_82 ( V_87 ) ;
F_96 ( V_43 ) ;
}
}
static struct V_42 *
F_100 ( struct V_152 * V_153 ,
char * type , void * V_154 ,
const struct V_155 * V_34 )
{
struct V_42 * V_43 ;
struct V_6 * V_3 = NULL ;
int V_93 ;
if ( type && strlen ( type ) >= V_5 )
return F_101 ( - V_16 ) ;
if ( ! V_34 || ! V_34 -> V_121 || ! V_34 -> V_127 ||
! V_34 -> V_128 )
return F_101 ( - V_16 ) ;
V_43 = F_89 ( sizeof( struct V_42 ) , V_29 ) ;
if ( ! V_43 )
return F_101 ( - V_132 ) ;
V_93 = F_12 ( & V_156 , & V_157 , & V_43 -> V_28 ) ;
if ( V_93 ) {
F_96 ( V_43 ) ;
return F_101 ( V_93 ) ;
}
F_102 ( V_43 -> type , type ? : L_32 , sizeof( V_43 -> type ) ) ;
F_103 ( & V_43 -> V_27 ) ;
F_104 ( & V_43 -> V_146 ) ;
V_43 -> V_153 = V_153 ;
V_43 -> V_34 = V_34 ;
V_43 -> V_126 = false ;
V_43 -> V_11 . V_158 = & V_159 ;
V_43 -> V_11 . V_160 = V_161 ;
V_43 -> V_154 = V_154 ;
F_105 ( & V_43 -> V_11 , L_33 , V_43 -> V_28 ) ;
V_93 = F_106 ( & V_43 -> V_11 ) ;
if ( V_93 ) {
F_15 ( & V_156 , & V_157 , V_43 -> V_28 ) ;
F_96 ( V_43 ) ;
return F_101 ( V_93 ) ;
}
F_7 ( & V_22 ) ;
F_8 ( & V_43 -> V_162 , & V_163 ) ;
F_9 ( & V_22 ) ;
F_24 ( V_43 ) ;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( F_107 ( & V_3 -> V_148 , 1 , 0 ) )
F_46 ( V_3 ) ;
F_9 ( & V_22 ) ;
return V_43 ;
}
struct V_42 *
F_108 ( char * type , void * V_154 ,
const struct V_155 * V_34 )
{
return F_100 ( NULL , type , V_154 , V_34 ) ;
}
struct V_42 *
F_109 ( struct V_152 * V_153 ,
char * type , void * V_154 ,
const struct V_155 * V_34 )
{
return F_100 ( V_153 , type , V_154 , V_34 ) ;
}
void F_110 ( struct V_42 * V_43 )
{
int V_48 ;
const struct V_53 * V_23 ;
struct V_6 * V_7 ;
struct V_42 * V_3 = NULL ;
if ( ! V_43 )
return;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_43 )
break;
if ( V_3 != V_43 ) {
F_9 ( & V_22 ) ;
return;
}
F_11 ( & V_43 -> V_162 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_34 -> V_150 ) {
V_7 -> V_34 -> V_150 ( V_7 , V_43 ) ;
continue;
}
if ( ! V_7 -> V_23 || ! V_7 -> V_23 -> V_55 )
continue;
V_23 = V_7 -> V_23 ;
for ( V_48 = 0 ; V_48 < V_23 -> V_56 ; V_48 ++ ) {
if ( V_23 -> V_55 [ V_48 ] . V_43 == V_43 ) {
F_22 ( V_7 , V_23 -> V_55 [ V_48 ] . V_58 , V_43 ) ;
V_23 -> V_55 [ V_48 ] . V_43 = NULL ;
}
}
}
F_9 ( & V_22 ) ;
if ( V_43 -> type [ 0 ] )
F_94 ( & V_43 -> V_11 , & V_164 ) ;
F_94 ( & V_43 -> V_11 , & V_165 ) ;
F_94 ( & V_43 -> V_11 , & V_166 ) ;
F_15 ( & V_156 , & V_157 , V_43 -> V_28 ) ;
F_111 ( & V_43 -> V_11 ) ;
return;
}
void F_80 ( struct V_42 * V_43 )
{
struct V_41 * V_122 ;
unsigned long V_125 = 0 ;
if ( V_43 -> V_126 )
return;
F_7 ( & V_43 -> V_27 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_44 ( & V_43 -> V_11 , L_34 ,
V_122 -> V_7 -> V_28 , V_122 -> V_125 ) ;
if ( V_122 -> V_125 == V_133 )
continue;
if ( V_122 -> V_125 > V_125 )
V_125 = V_122 -> V_125 ;
}
F_9 ( & V_43 -> V_27 ) ;
V_43 -> V_34 -> V_128 ( V_43 , V_125 ) ;
V_43 -> V_126 = true ;
F_112 ( V_43 , V_125 ) ;
F_44 ( & V_43 -> V_11 , L_35 , V_125 ) ;
}
void F_113 ( struct V_6 * V_7 , int V_30 )
{
F_37 ( V_7 , V_30 ) ;
}
static int F_114 ( struct V_6 * V_7 , int V_45 )
{
int V_167 ;
int V_110 = sizeof( struct V_168 ) * V_7 -> V_49 ;
V_7 -> V_169 = F_89 ( V_110 , V_29 ) ;
if ( ! V_7 -> V_169 )
return - V_132 ;
V_7 -> V_170 = F_89 ( V_110 , V_29 ) ;
if ( ! V_7 -> V_170 ) {
F_96 ( V_7 -> V_169 ) ;
return - V_132 ;
}
if ( V_7 -> V_34 -> V_103 ) {
V_7 -> V_171 = F_89 ( V_110 , V_29 ) ;
if ( ! V_7 -> V_171 ) {
F_96 ( V_7 -> V_169 ) ;
F_96 ( V_7 -> V_170 ) ;
return - V_132 ;
}
}
for ( V_167 = 0 ; V_167 < V_7 -> V_49 ; V_167 ++ ) {
snprintf ( V_7 -> V_169 [ V_167 ] . V_2 , V_5 ,
L_12 , V_167 ) ;
F_91 ( & V_7 -> V_169 [ V_167 ] . V_89 . V_89 ) ;
V_7 -> V_169 [ V_167 ] . V_89 . V_89 . V_2 =
V_7 -> V_169 [ V_167 ] . V_2 ;
V_7 -> V_169 [ V_167 ] . V_89 . V_89 . V_92 = V_141 ;
V_7 -> V_169 [ V_167 ] . V_89 . V_137 = F_55 ;
F_75 ( & V_7 -> V_11 ,
& V_7 -> V_169 [ V_167 ] . V_89 ) ;
snprintf ( V_7 -> V_170 [ V_167 ] . V_2 , V_5 ,
L_18 , V_167 ) ;
F_91 ( & V_7 -> V_170 [ V_167 ] . V_89 . V_89 ) ;
V_7 -> V_170 [ V_167 ] . V_89 . V_89 . V_2 =
V_7 -> V_170 [ V_167 ] . V_2 ;
V_7 -> V_170 [ V_167 ] . V_89 . V_89 . V_92 = V_141 ;
V_7 -> V_170 [ V_167 ] . V_89 . V_137 = F_58 ;
if ( F_40 ( V_172 ) &&
V_45 & ( 1 << V_167 ) ) {
V_7 -> V_170 [ V_167 ] . V_89 . V_89 . V_92 |= V_140 ;
V_7 -> V_170 [ V_167 ] . V_89 . V_142 =
F_56 ;
}
F_75 ( & V_7 -> V_11 ,
& V_7 -> V_170 [ V_167 ] . V_89 ) ;
if ( ! V_7 -> V_34 -> V_103 )
continue;
snprintf ( V_7 -> V_171 [ V_167 ] . V_2 , V_5 ,
L_19 , V_167 ) ;
F_91 ( & V_7 -> V_171 [ V_167 ] . V_89 . V_89 ) ;
V_7 -> V_171 [ V_167 ] . V_89 . V_89 . V_2 =
V_7 -> V_171 [ V_167 ] . V_2 ;
V_7 -> V_171 [ V_167 ] . V_89 . V_89 . V_92 = V_141 ;
V_7 -> V_171 [ V_167 ] . V_89 . V_137 = F_61 ;
if ( V_7 -> V_34 -> V_102 ) {
V_7 -> V_171 [ V_167 ] . V_89 . V_89 . V_92 |= V_140 ;
V_7 -> V_171 [ V_167 ] . V_89 . V_142 =
F_59 ;
}
F_75 ( & V_7 -> V_11 ,
& V_7 -> V_171 [ V_167 ] . V_89 ) ;
}
return 0 ;
}
static void F_115 ( struct V_6 * V_7 )
{
int V_167 ;
for ( V_167 = 0 ; V_167 < V_7 -> V_49 ; V_167 ++ ) {
F_94 ( & V_7 -> V_11 ,
& V_7 -> V_169 [ V_167 ] . V_89 ) ;
F_94 ( & V_7 -> V_11 ,
& V_7 -> V_170 [ V_167 ] . V_89 ) ;
if ( V_7 -> V_34 -> V_103 )
F_94 ( & V_7 -> V_11 ,
& V_7 -> V_171 [ V_167 ] . V_89 ) ;
}
F_96 ( V_7 -> V_169 ) ;
F_96 ( V_7 -> V_170 ) ;
F_96 ( V_7 -> V_171 ) ;
}
struct V_6 * F_116 ( const char * type ,
int V_49 , int V_45 , void * V_154 ,
struct V_173 * V_34 ,
struct V_53 * V_23 ,
int V_64 , int V_65 )
{
struct V_6 * V_7 ;
enum V_66 V_67 ;
int V_93 ;
int V_76 ;
int V_63 = 0 ;
struct V_1 * V_9 ;
if ( type && strlen ( type ) >= V_5 )
return F_101 ( - V_16 ) ;
if ( V_49 > V_174 || V_49 < 0 || V_45 > > V_49 )
return F_101 ( - V_16 ) ;
if ( ! V_34 )
return F_101 ( - V_16 ) ;
if ( V_49 > 0 && ( ! V_34 -> V_73 || ! V_34 -> V_70 ) )
return F_101 ( - V_16 ) ;
V_7 = F_89 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return F_101 ( - V_132 ) ;
F_104 ( & V_7 -> V_146 ) ;
F_117 ( & V_7 -> V_25 ) ;
F_103 ( & V_7 -> V_27 ) ;
V_93 = F_12 ( & V_175 , & V_157 , & V_7 -> V_28 ) ;
if ( V_93 ) {
F_96 ( V_7 ) ;
return F_101 ( V_93 ) ;
}
F_102 ( V_7 -> type , type ? : L_32 , sizeof( V_7 -> type ) ) ;
V_7 -> V_34 = V_34 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_11 . V_158 = & V_159 ;
V_7 -> V_154 = V_154 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_65 = V_65 ;
F_93 ( & V_7 -> V_148 , 1 ) ;
F_105 ( & V_7 -> V_11 , L_36 , V_7 -> V_28 ) ;
V_93 = F_106 ( & V_7 -> V_11 ) ;
if ( V_93 ) {
F_15 ( & V_175 , & V_157 , V_7 -> V_28 ) ;
F_96 ( V_7 ) ;
return F_101 ( V_93 ) ;
}
if ( type ) {
V_93 = F_75 ( & V_7 -> V_11 , & V_176 ) ;
if ( V_93 )
goto V_177;
}
V_93 = F_75 ( & V_7 -> V_11 , & V_178 ) ;
if ( V_93 )
goto V_177;
if ( V_34 -> V_94 ) {
V_93 = F_75 ( & V_7 -> V_11 , & V_179 ) ;
if ( V_93 )
goto V_177;
}
V_93 = F_114 ( V_7 , V_45 ) ;
if ( V_93 )
goto V_177;
for ( V_76 = 0 ; V_76 < V_49 ; V_76 ++ ) {
V_7 -> V_34 -> V_73 ( V_7 , V_76 , & V_67 ) ;
if ( V_67 == V_99 )
V_63 = 1 ;
}
if ( ! V_63 ) {
V_93 = F_75 ( & V_7 -> V_11 , & V_180 ) ;
if ( V_93 )
goto V_177;
}
if ( F_40 ( V_80 ) ) {
V_93 = F_75 ( & V_7 -> V_11 , & V_181 ) ;
if ( V_93 )
goto V_177;
}
V_93 = F_75 ( & V_7 -> V_11 , & V_182 ) ;
if ( V_93 )
goto V_177;
V_93 = F_73 ( & V_7 -> V_11 ) ;
if ( V_93 )
goto V_177;
V_93 = F_75 ( & V_7 -> V_11 , & V_183 ) ;
if ( V_93 )
goto V_177;
F_7 ( & V_17 ) ;
if ( V_7 -> V_23 )
V_9 = F_1 ( V_7 -> V_23 -> V_24 ) ;
else
V_9 = V_4 ;
V_93 = F_5 ( V_7 , V_9 ) ;
if ( V_93 ) {
F_9 ( & V_17 ) ;
goto V_177;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_23 || ! V_7 -> V_23 -> V_184 ) {
V_93 = F_118 ( V_7 ) ;
if ( V_93 )
goto V_177;
}
F_7 ( & V_22 ) ;
F_92 ( & V_7 -> V_162 , & V_185 ) ;
F_9 ( & V_22 ) ;
F_25 ( V_7 ) ;
F_119 ( & ( V_7 -> V_62 ) , F_48 ) ;
F_45 ( V_7 ) ;
if ( F_107 ( & V_7 -> V_148 , 1 , 0 ) )
F_46 ( V_7 ) ;
return V_7 ;
V_177:
F_15 ( & V_175 , & V_157 , V_7 -> V_28 ) ;
F_111 ( & V_7 -> V_11 ) ;
return F_101 ( V_93 ) ;
}
void F_120 ( struct V_6 * V_7 )
{
int V_48 ;
const struct V_53 * V_23 ;
struct V_42 * V_43 ;
struct V_6 * V_3 = NULL ;
if ( ! V_7 )
return;
V_23 = V_7 -> V_23 ;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( V_3 == V_7 )
break;
if ( V_3 != V_7 ) {
F_9 ( & V_22 ) ;
return;
}
F_11 ( & V_7 -> V_162 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_34 -> V_150 ) {
V_7 -> V_34 -> V_150 ( V_7 , V_43 ) ;
continue;
}
if ( ! V_23 || ! V_23 -> V_55 )
break;
for ( V_48 = 0 ; V_48 < V_23 -> V_56 ; V_48 ++ ) {
if ( V_23 -> V_55 [ V_48 ] . V_43 == V_43 ) {
F_22 ( V_7 , V_23 -> V_55 [ V_48 ] . V_58 , V_43 ) ;
V_23 -> V_55 [ V_48 ] . V_43 = NULL ;
}
}
}
F_9 ( & V_22 ) ;
F_26 ( V_7 , 0 ) ;
if ( V_7 -> type [ 0 ] )
F_94 ( & V_7 -> V_11 , & V_176 ) ;
F_94 ( & V_7 -> V_11 , & V_178 ) ;
if ( V_7 -> V_34 -> V_94 )
F_94 ( & V_7 -> V_11 , & V_179 ) ;
F_94 ( & V_7 -> V_11 , & V_182 ) ;
F_94 ( & V_7 -> V_11 , & V_183 ) ;
F_115 ( V_7 ) ;
F_5 ( V_7 , NULL ) ;
F_121 ( V_7 ) ;
F_15 ( & V_175 , & V_157 , V_7 -> V_28 ) ;
F_122 ( & V_7 -> V_25 ) ;
F_123 ( & V_7 -> V_27 ) ;
F_111 ( & V_7 -> V_11 ) ;
return;
}
struct V_6 * F_124 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_186 = F_101 ( - V_16 ) ;
unsigned int V_187 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_187 ++ ;
V_186 = V_3 ;
}
F_9 ( & V_22 ) ;
if ( V_187 == 0 )
V_186 = F_101 ( - V_151 ) ;
else if ( V_187 > 1 )
V_186 = F_101 ( - V_144 ) ;
exit:
return V_186 ;
}
int F_125 ( struct V_6 * V_7 ,
enum V_188 V_189 )
{
struct V_190 * V_191 ;
struct V_192 * V_89 ;
struct V_193 * V_194 ;
void * V_195 ;
int V_110 ;
int V_93 ;
static unsigned int V_196 ;
if ( ! V_7 )
return - V_16 ;
V_110 = F_126 ( sizeof( struct V_193 ) ) +
F_126 ( 0 ) ;
V_191 = F_127 ( V_110 , V_197 ) ;
if ( ! V_191 )
return - V_132 ;
V_195 = F_128 ( V_191 , 0 , V_196 ++ ,
& V_198 , 0 ,
V_199 ) ;
if ( ! V_195 ) {
F_129 ( V_191 ) ;
return - V_132 ;
}
V_89 = F_130 ( V_191 , V_200 ,
sizeof( struct V_193 ) ) ;
if ( ! V_89 ) {
F_129 ( V_191 ) ;
return - V_16 ;
}
V_194 = F_131 ( V_89 ) ;
if ( ! V_194 ) {
F_129 ( V_191 ) ;
return - V_16 ;
}
memset ( V_194 , 0 , sizeof( struct V_193 ) ) ;
V_194 -> V_201 = V_7 -> V_28 ;
V_194 -> V_189 = V_189 ;
F_132 ( V_191 , V_195 ) ;
V_93 = F_133 ( & V_198 , V_191 , 0 ,
0 , V_197 ) ;
if ( V_93 )
F_4 ( & V_7 -> V_11 , L_37 , V_93 ) ;
return V_93 ;
}
static int F_134 ( void )
{
return F_135 ( & V_198 ) ;
}
static void F_136 ( void )
{
F_137 ( & V_198 ) ;
}
static inline int F_134 ( void ) { return 0 ; }
static inline void F_136 ( void ) {}
static int T_4 F_138 ( void )
{
int V_93 ;
V_93 = F_139 () ;
if ( V_93 )
return V_93 ;
V_93 = F_140 () ;
if ( V_93 )
return V_93 ;
V_93 = F_141 () ;
if ( V_93 )
return V_93 ;
V_93 = F_142 () ;
if ( V_93 )
return V_93 ;
return F_143 () ;
}
static void F_144 ( void )
{
F_145 () ;
F_146 () ;
F_147 () ;
F_148 () ;
F_149 () ;
}
static int F_150 ( struct V_202 * V_203 ,
unsigned long V_92 , void * V_204 )
{
struct V_6 * V_7 ;
switch ( V_92 ) {
case V_205 :
case V_206 :
case V_207 :
F_93 ( & V_84 , 1 ) ;
break;
case V_208 :
case V_209 :
case V_210 :
F_93 ( & V_84 , 0 ) ;
F_2 (tz, &thermal_tz_list, node) {
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int T_4 F_151 ( void )
{
int V_93 ;
V_93 = F_138 () ;
if ( V_93 )
goto error;
V_93 = F_152 ( & V_159 ) ;
if ( V_93 )
goto V_211;
V_93 = F_134 () ;
if ( V_93 )
goto V_212;
V_93 = F_153 () ;
if ( V_93 )
goto V_213;
V_93 = F_154 ( & V_214 ) ;
if ( V_93 )
F_155 ( L_38 ,
V_93 ) ;
return 0 ;
V_213:
F_136 () ;
V_212:
F_156 ( & V_159 ) ;
V_211:
F_144 () ;
error:
F_122 ( & V_175 ) ;
F_122 ( & V_156 ) ;
F_123 ( & V_157 ) ;
F_123 ( & V_22 ) ;
F_123 ( & V_17 ) ;
return V_93 ;
}
static void T_5 F_157 ( void )
{
F_158 ( & V_214 ) ;
F_159 () ;
F_136 () ;
F_156 ( & V_159 ) ;
F_144 () ;
F_122 ( & V_175 ) ;
F_122 ( & V_156 ) ;
F_123 ( & V_157 ) ;
F_123 ( & V_22 ) ;
F_123 ( & V_17 ) ;
}
