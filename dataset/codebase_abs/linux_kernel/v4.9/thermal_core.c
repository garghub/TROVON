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
if ( F_38 ( V_30 , & V_7 -> V_73 ) )
return;
V_7 -> V_34 -> V_74 ( V_7 , V_30 , & type ) ;
if ( type == V_72 || type == V_75 )
F_33 ( V_7 , V_30 , type ) ;
else
F_32 ( V_7 , V_30 , type ) ;
F_31 ( V_7 ) ;
}
int F_39 ( struct V_6 * V_7 , int * V_76 )
{
int V_13 = - V_16 ;
int V_77 ;
int V_78 = V_79 ;
enum V_66 type ;
if ( ! V_7 || F_40 ( V_7 ) || ! V_7 -> V_34 -> V_80 )
goto exit;
F_7 ( & V_7 -> V_27 ) ;
V_13 = V_7 -> V_34 -> V_80 ( V_7 , V_76 ) ;
if ( F_41 ( V_81 ) && V_7 -> V_33 ) {
for ( V_77 = 0 ; V_77 < V_7 -> V_49 ; V_77 ++ ) {
V_13 = V_7 -> V_34 -> V_74 ( V_7 , V_77 , & type ) ;
if ( ! V_13 && type == V_72 ) {
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_77 ,
& V_78 ) ;
break;
}
}
if ( ! V_13 && * V_76 < V_78 )
* V_76 = V_7 -> V_33 ;
}
F_9 ( & V_7 -> V_27 ) ;
exit:
return V_13 ;
}
void F_42 ( struct V_6 * V_7 )
{
int V_82 = - V_79 ;
int V_83 = V_79 ;
int V_69 , V_84 ;
int V_48 , V_13 ;
F_7 ( & V_7 -> V_27 ) ;
if ( ! V_7 -> V_34 -> V_85 || ! V_7 -> V_34 -> V_86 )
goto exit;
for ( V_48 = 0 ; V_48 < V_7 -> V_49 ; V_48 ++ ) {
int V_87 ;
V_7 -> V_34 -> V_70 ( V_7 , V_48 , & V_69 ) ;
V_7 -> V_34 -> V_86 ( V_7 , V_48 , & V_84 ) ;
V_87 = V_69 - V_84 ;
if ( V_87 < V_7 -> V_36 && V_87 > V_82 )
V_82 = V_87 ;
if ( V_69 > V_7 -> V_36 && V_69 < V_83 )
V_83 = V_69 ;
}
if ( V_7 -> V_88 == V_82 && V_7 -> V_89 == V_83 )
goto exit;
V_7 -> V_88 = V_82 ;
V_7 -> V_89 = V_83 ;
F_43 ( & V_7 -> V_11 ,
L_5 , V_82 , V_83 ) ;
V_13 = V_7 -> V_34 -> V_85 ( V_7 , V_82 , V_83 ) ;
if ( V_13 )
F_4 ( & V_7 -> V_11 , L_6 , V_13 ) ;
exit:
F_9 ( & V_7 -> V_27 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
int V_76 , V_13 ;
V_13 = F_39 ( V_7 , & V_76 ) ;
if ( V_13 ) {
if ( V_13 != - V_90 )
F_45 ( & V_7 -> V_11 ,
L_7 ,
V_13 ) ;
return;
}
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_37 = V_7 -> V_36 ;
V_7 -> V_36 = V_76 ;
F_9 ( & V_7 -> V_27 ) ;
F_46 ( V_7 ) ;
if ( V_7 -> V_37 == V_91 )
F_43 ( & V_7 -> V_11 , L_8 ,
V_7 -> V_36 ) ;
else
F_43 ( & V_7 -> V_11 , L_9 ,
V_7 -> V_37 , V_7 -> V_36 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_41 * V_3 ;
V_7 -> V_36 = V_91 ;
V_7 -> V_63 = 0 ;
F_2 (pos, &tz->thermal_instances, tz_node)
V_3 -> V_92 = false ;
}
void F_48 ( struct V_6 * V_7 ,
enum V_93 V_94 )
{
int V_77 ;
if ( F_49 ( & V_95 ) )
return;
if ( ! V_7 -> V_34 -> V_80 )
return;
F_44 ( V_7 ) ;
F_42 ( V_7 ) ;
V_7 -> V_96 = V_94 ;
for ( V_77 = 0 ; V_77 < V_7 -> V_49 ; V_77 ++ )
F_37 ( V_7 , V_77 ) ;
}
static void F_50 ( struct V_97 * V_98 )
{
struct V_6 * V_7 = F_51 ( V_98 , struct
V_6 ,
V_62 . V_98 ) ;
F_48 ( V_7 , V_99 ) ;
}
static T_1
F_52 ( struct V_11 * V_100 , struct V_101 * V_102 , char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
return sprintf ( V_103 , L_10 , V_7 -> type ) ;
}
static T_1
F_54 ( struct V_11 * V_100 , struct V_101 * V_102 , char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_36 , V_13 ;
V_13 = F_39 ( V_7 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_103 , L_11 , V_36 ) ;
}
static T_1
F_55 ( struct V_11 * V_100 , struct V_101 * V_102 , char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
enum V_104 V_105 ;
int V_106 ;
if ( ! V_7 -> V_34 -> V_107 )
return - V_108 ;
V_106 = V_7 -> V_34 -> V_107 ( V_7 , & V_105 ) ;
if ( V_106 )
return V_106 ;
return sprintf ( V_103 , L_10 , V_105 == V_109 ? L_12
: L_13 ) ;
}
static T_1
F_56 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_106 ;
if ( ! V_7 -> V_34 -> V_110 )
return - V_108 ;
if ( ! strncmp ( V_103 , L_12 , sizeof( L_12 ) - 1 ) )
V_106 = V_7 -> V_34 -> V_110 ( V_7 , V_109 ) ;
else if ( ! strncmp ( V_103 , L_13 , sizeof( L_13 ) - 1 ) )
V_106 = V_7 -> V_34 -> V_110 ( V_7 , V_111 ) ;
else
V_106 = - V_16 ;
if ( V_106 )
return V_106 ;
return V_77 ;
}
static T_1
F_57 ( struct V_11 * V_100 , struct V_101 * V_102 ,
char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
enum V_66 type ;
int V_30 , V_106 ;
if ( ! V_7 -> V_34 -> V_74 )
return - V_108 ;
if ( ! sscanf ( V_102 -> V_102 . V_2 , L_14 , & V_30 ) )
return - V_16 ;
V_106 = V_7 -> V_34 -> V_74 ( V_7 , V_30 , & type ) ;
if ( V_106 )
return V_106 ;
switch ( type ) {
case V_72 :
return sprintf ( V_103 , L_15 ) ;
case V_75 :
return sprintf ( V_103 , L_16 ) ;
case V_112 :
return sprintf ( V_103 , L_17 ) ;
case V_113 :
return sprintf ( V_103 , L_18 ) ;
default:
return sprintf ( V_103 , L_19 ) ;
}
}
static T_1
F_58 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_114 )
return - V_108 ;
if ( ! sscanf ( V_102 -> V_102 . V_2 , L_20 , & V_30 ) )
return - V_16 ;
if ( F_59 ( V_103 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_114 ( V_7 , V_30 , V_36 ) ;
if ( V_13 )
return V_13 ;
F_48 ( V_7 , V_99 ) ;
return V_77 ;
}
static T_1
F_60 ( struct V_11 * V_100 , struct V_101 * V_102 ,
char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_70 )
return - V_108 ;
if ( ! sscanf ( V_102 -> V_102 . V_2 , L_20 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_30 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_103 , L_11 , V_36 ) ;
}
static T_1
F_61 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_115 )
return - V_108 ;
if ( ! sscanf ( V_102 -> V_102 . V_2 , L_21 , & V_30 ) )
return - V_16 ;
if ( F_59 ( V_103 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_115 ( V_7 , V_30 , V_36 ) ;
if ( ! V_13 )
F_42 ( V_7 ) ;
return V_13 ? V_13 : V_77 ;
}
static T_1
F_62 ( struct V_11 * V_100 , struct V_101 * V_102 ,
char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_86 )
return - V_108 ;
if ( ! sscanf ( V_102 -> V_102 . V_2 , L_21 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_86 ( V_7 , V_30 , & V_36 ) ;
return V_13 ? V_13 : sprintf ( V_103 , L_11 , V_36 ) ;
}
static T_1
F_63 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
struct V_42 * V_43 = NULL ;
int V_116 ;
if ( ! sscanf ( V_103 , L_11 , & V_116 ) )
return - V_16 ;
if ( V_116 && V_116 < 1000 )
return - V_16 ;
if ( V_116 && ! V_7 -> V_117 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_22 , V_43 -> type ,
sizeof( L_22 ) ) )
F_21 ( V_7 ,
V_118 , V_43 ,
V_52 ,
V_52 ,
V_119 ) ;
}
F_9 ( & V_22 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = 1000 ;
} else if ( ! V_116 && V_7 -> V_117 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_22 , V_43 -> type ,
sizeof( L_22 ) ) )
F_23 ( V_7 ,
V_118 ,
V_43 ) ;
}
F_9 ( & V_22 ) ;
V_7 -> V_64 = 0 ;
}
V_7 -> V_117 = V_116 ;
F_48 ( V_7 , V_99 ) ;
return V_77 ;
}
static T_1
F_64 ( struct V_11 * V_100 , struct V_101 * V_102 ,
char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
return sprintf ( V_103 , L_11 , V_7 -> V_117 ) ;
}
static T_1
F_65 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
int V_13 = - V_16 ;
struct V_6 * V_7 = F_53 ( V_100 ) ;
struct V_1 * V_120 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_23 , V_103 ) ;
F_7 ( & V_17 ) ;
F_7 ( & V_7 -> V_27 ) ;
V_120 = F_1 ( F_66 ( V_2 ) ) ;
if ( ! V_120 )
goto exit;
V_13 = F_5 ( V_7 , V_120 ) ;
if ( ! V_13 )
V_13 = V_77 ;
exit:
F_9 ( & V_7 -> V_27 ) ;
F_9 ( & V_17 ) ;
return V_13 ;
}
static T_1
F_67 ( struct V_11 * V_100 , struct V_101 * V_121 , char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
return sprintf ( V_103 , L_10 , V_7 -> V_9 -> V_2 ) ;
}
static T_1
F_68 ( struct V_11 * V_100 , struct V_101 * V_121 ,
char * V_103 )
{
struct V_1 * V_3 ;
T_1 V_77 = 0 ;
T_1 V_122 = V_123 ;
F_7 ( & V_17 ) ;
F_2 (pos, &thermal_governor_list, governor_list) {
V_122 = V_123 - V_77 ;
V_77 += F_69 ( V_103 + V_77 , V_122 , L_24 , V_3 -> V_2 ) ;
}
V_77 += F_69 ( V_103 + V_77 , V_122 , L_25 ) ;
F_9 ( & V_17 ) ;
return V_77 ;
}
static T_1
F_70 ( struct V_11 * V_100 , struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
int V_13 = 0 ;
int V_36 ;
if ( F_59 ( V_103 , 10 , & V_36 ) )
return - V_16 ;
if ( ! V_7 -> V_34 -> V_124 ) {
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_33 = V_36 ;
F_9 ( & V_7 -> V_27 ) ;
} else {
V_13 = V_7 -> V_34 -> V_124 ( V_7 , V_36 ) ;
}
if ( ! V_13 )
F_48 ( V_7 , V_99 ) ;
return V_13 ? V_13 : V_77 ;
}
static T_1
F_71 ( struct V_11 * V_100 , struct V_101 * V_121 ,
char * V_103 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
if ( V_7 -> V_23 )
return sprintf ( V_103 , L_26 , V_7 -> V_23 -> V_125 ) ;
else
return - V_126 ;
}
static T_1
F_72 ( struct V_11 * V_100 , struct V_101 * V_121 ,
const char * V_103 , T_2 V_77 )
{
struct V_6 * V_7 = F_53 ( V_100 ) ;
T_3 V_125 ;
if ( ! V_7 -> V_23 )
return - V_126 ;
if ( F_73 ( V_103 , 10 , & V_125 ) )
return - V_16 ;
V_7 -> V_23 -> V_125 = V_125 ;
return V_77 ;
}
static int F_74 ( struct V_11 * V_100 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_75 ( V_127 ) ; V_48 ++ ) {
int V_13 ;
struct V_101 * V_128 = V_127 [ V_48 ] ;
V_13 = F_76 ( V_100 , V_128 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_77 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_129 )
{
if ( ! F_78 ( V_43 ) )
return - V_16 ;
return V_43 -> V_34 -> V_130 ( V_43 , V_7 , 0 , V_129 ) ;
}
int F_79 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_131 )
{
unsigned long V_132 ;
int V_13 ;
if ( ! F_78 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_133 ( V_43 , & V_132 ) ;
if ( V_13 )
return V_13 ;
return V_43 -> V_34 -> V_130 ( V_43 , V_7 , V_132 , V_131 ) ;
}
int F_80 ( struct V_42 * V_43 ,
struct V_41 * V_134 , T_3 V_135 )
{
unsigned long V_116 ;
int V_13 ;
if ( ! F_78 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_136 ( V_43 , V_134 -> V_7 , V_135 , & V_116 ) ;
if ( V_13 )
return V_13 ;
V_134 -> V_137 = V_116 ;
F_7 ( & V_43 -> V_27 ) ;
V_43 -> V_138 = false ;
F_9 ( & V_43 -> V_27 ) ;
F_81 ( V_43 ) ;
return 0 ;
}
static T_1
F_82 ( struct V_11 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_42 * V_43 = F_83 ( V_100 ) ;
return sprintf ( V_103 , L_10 , V_43 -> type ) ;
}
static T_1
F_84 ( struct V_11 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_42 * V_43 = F_83 ( V_100 ) ;
unsigned long V_116 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_133 ( V_43 , & V_116 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_103 , L_27 , V_116 ) ;
}
static T_1
F_85 ( struct V_11 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_42 * V_43 = F_83 ( V_100 ) ;
unsigned long V_116 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_139 ( V_43 , & V_116 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_103 , L_27 , V_116 ) ;
}
static T_1
F_86 ( struct V_11 * V_100 ,
struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_42 * V_43 = F_83 ( V_100 ) ;
unsigned long V_116 ;
int V_106 ;
if ( ! sscanf ( V_103 , L_27 , & V_116 ) )
return - V_16 ;
if ( ( long ) V_116 < 0 )
return - V_16 ;
V_106 = V_43 -> V_34 -> V_140 ( V_43 , V_116 ) ;
if ( V_106 )
return V_106 ;
return V_77 ;
}
static T_1
F_87 ( struct V_11 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_41 * V_134 ;
V_134 =
F_51 ( V_102 , struct V_41 , V_102 ) ;
if ( V_134 -> V_30 == V_118 )
return sprintf ( V_103 , L_28 ) ;
else
return sprintf ( V_103 , L_11 , V_134 -> V_30 ) ;
}
static T_1
F_88 ( struct V_11 * V_100 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_41 * V_134 ;
V_134 = F_51 ( V_102 , struct V_41 , V_141 ) ;
return sprintf ( V_103 , L_11 , V_134 -> V_47 ) ;
}
static T_1
F_89 ( struct V_11 * V_100 ,
struct V_101 * V_102 ,
const char * V_103 , T_2 V_77 )
{
struct V_41 * V_134 ;
int V_13 , V_47 ;
V_13 = F_59 ( V_103 , 0 , & V_47 ) ;
if ( V_13 )
return V_13 ;
V_134 = F_51 ( V_102 , struct V_41 , V_141 ) ;
V_134 -> V_47 = V_47 ;
return V_77 ;
}
int F_21 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 ,
unsigned long V_50 , unsigned long V_51 ,
unsigned int V_47 )
{
struct V_41 * V_100 ;
struct V_41 * V_3 ;
struct V_6 * V_142 ;
struct V_42 * V_143 ;
unsigned long V_132 ;
int V_106 , V_13 ;
if ( V_30 >= V_7 -> V_49 || ( V_30 < 0 && V_30 != V_118 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_142 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_143 == V_43 )
break;
}
if ( V_7 != V_142 || V_43 != V_143 )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_133 ( V_43 , & V_132 ) ;
if ( V_13 )
return V_13 ;
V_51 = V_51 == V_52 ? 0 : V_51 ;
V_50 = V_50 == V_52 ? V_132 : V_50 ;
if ( V_51 > V_50 || V_50 > V_132 )
return - V_16 ;
V_100 =
F_90 ( sizeof( struct V_41 ) , V_29 ) ;
if ( ! V_100 )
return - V_144 ;
V_100 -> V_7 = V_7 ;
V_100 -> V_43 = V_43 ;
V_100 -> V_30 = V_30 ;
V_100 -> V_50 = V_50 ;
V_100 -> V_51 = V_51 ;
V_100 -> V_137 = V_145 ;
V_100 -> V_47 = V_47 ;
V_106 = F_12 ( & V_7 -> V_25 , & V_7 -> V_27 , & V_100 -> V_28 ) ;
if ( V_106 )
goto V_146;
sprintf ( V_100 -> V_2 , L_29 , V_100 -> V_28 ) ;
V_106 =
F_91 ( & V_7 -> V_11 . V_147 , & V_43 -> V_11 . V_147 , V_100 -> V_2 ) ;
if ( V_106 )
goto F_15;
sprintf ( V_100 -> V_148 , L_30 , V_100 -> V_28 ) ;
F_92 ( & V_100 -> V_102 . V_102 ) ;
V_100 -> V_102 . V_102 . V_2 = V_100 -> V_148 ;
V_100 -> V_102 . V_102 . V_105 = 0444 ;
V_100 -> V_102 . V_149 = F_87 ;
V_106 = F_76 ( & V_7 -> V_11 , & V_100 -> V_102 ) ;
if ( V_106 )
goto V_150;
sprintf ( V_100 -> V_151 , L_31 , V_100 -> V_28 ) ;
F_92 ( & V_100 -> V_141 . V_102 ) ;
V_100 -> V_141 . V_102 . V_2 = V_100 -> V_151 ;
V_100 -> V_141 . V_102 . V_105 = V_152 | V_153 ;
V_100 -> V_141 . V_149 = F_88 ;
V_100 -> V_141 . V_154 = F_89 ;
V_106 = F_76 ( & V_7 -> V_11 , & V_100 -> V_141 ) ;
if ( V_106 )
goto V_155;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
V_106 = - V_156 ;
break;
}
if ( ! V_106 ) {
F_93 ( & V_100 -> V_157 , & V_7 -> V_158 ) ;
F_93 ( & V_100 -> V_159 , & V_43 -> V_158 ) ;
F_94 ( & V_7 -> V_160 , 1 ) ;
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
if ( ! V_106 )
return 0 ;
F_95 ( & V_7 -> V_11 , & V_100 -> V_141 ) ;
V_155:
F_95 ( & V_7 -> V_11 , & V_100 -> V_102 ) ;
V_150:
F_96 ( & V_7 -> V_11 . V_147 , V_100 -> V_2 ) ;
F_15:
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_100 -> V_28 ) ;
V_146:
F_97 ( V_100 ) ;
return V_106 ;
}
int F_23 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 )
{
struct V_41 * V_3 , * V_161 ;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_98 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
F_11 ( & V_3 -> V_157 ) ;
F_11 ( & V_3 -> V_159 ) ;
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
goto V_162;
}
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
return - V_163 ;
V_162:
F_95 ( & V_7 -> V_11 , & V_3 -> V_141 ) ;
F_95 ( & V_7 -> V_11 , & V_3 -> V_102 ) ;
F_96 ( & V_7 -> V_11 . V_147 , V_3 -> V_2 ) ;
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_3 -> V_28 ) ;
F_97 ( V_3 ) ;
return 0 ;
}
static void F_99 ( struct V_11 * V_100 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( ! strncmp ( F_100 ( V_100 ) , L_32 ,
sizeof( L_32 ) - 1 ) ) {
V_7 = F_53 ( V_100 ) ;
F_97 ( V_7 ) ;
} else if( ! strncmp ( F_100 ( V_100 ) , L_33 ,
sizeof( L_33 ) - 1 ) ) {
V_43 = F_83 ( V_100 ) ;
F_97 ( V_43 ) ;
}
}
static struct V_42 *
F_101 ( struct V_164 * V_165 ,
char * type , void * V_166 ,
const struct V_167 * V_34 )
{
struct V_42 * V_43 ;
struct V_6 * V_3 = NULL ;
int V_106 ;
if ( type && strlen ( type ) >= V_5 )
return F_102 ( - V_16 ) ;
if ( ! V_34 || ! V_34 -> V_133 || ! V_34 -> V_139 ||
! V_34 -> V_140 )
return F_102 ( - V_16 ) ;
V_43 = F_90 ( sizeof( struct V_42 ) , V_29 ) ;
if ( ! V_43 )
return F_102 ( - V_144 ) ;
V_106 = F_12 ( & V_168 , & V_169 , & V_43 -> V_28 ) ;
if ( V_106 ) {
F_97 ( V_43 ) ;
return F_102 ( V_106 ) ;
}
F_103 ( V_43 -> type , type ? : L_34 , sizeof( V_43 -> type ) ) ;
F_104 ( & V_43 -> V_27 ) ;
F_105 ( & V_43 -> V_158 ) ;
V_43 -> V_165 = V_165 ;
V_43 -> V_34 = V_34 ;
V_43 -> V_138 = false ;
V_43 -> V_11 . V_170 = & V_171 ;
V_43 -> V_11 . V_172 = V_173 ;
V_43 -> V_166 = V_166 ;
F_106 ( & V_43 -> V_11 , L_35 , V_43 -> V_28 ) ;
V_106 = F_107 ( & V_43 -> V_11 ) ;
if ( V_106 ) {
F_15 ( & V_168 , & V_169 , V_43 -> V_28 ) ;
F_97 ( V_43 ) ;
return F_102 ( V_106 ) ;
}
F_7 ( & V_22 ) ;
F_8 ( & V_43 -> V_174 , & V_175 ) ;
F_9 ( & V_22 ) ;
F_24 ( V_43 ) ;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( F_108 ( & V_3 -> V_160 , 1 , 0 ) )
F_48 ( V_3 ,
V_99 ) ;
F_9 ( & V_22 ) ;
return V_43 ;
}
struct V_42 *
F_109 ( char * type , void * V_166 ,
const struct V_167 * V_34 )
{
return F_101 ( NULL , type , V_166 , V_34 ) ;
}
struct V_42 *
F_110 ( struct V_164 * V_165 ,
char * type , void * V_166 ,
const struct V_167 * V_34 )
{
return F_101 ( V_165 , type , V_166 , V_34 ) ;
}
void F_111 ( struct V_42 * V_43 )
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
F_11 ( & V_43 -> V_174 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_34 -> V_162 ) {
V_7 -> V_34 -> V_162 ( V_7 , V_43 ) ;
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
F_95 ( & V_43 -> V_11 , & V_176 ) ;
F_95 ( & V_43 -> V_11 , & V_177 ) ;
F_95 ( & V_43 -> V_11 , & V_178 ) ;
F_15 ( & V_168 , & V_169 , V_43 -> V_28 ) ;
F_112 ( & V_43 -> V_11 ) ;
return;
}
void F_81 ( struct V_42 * V_43 )
{
struct V_41 * V_134 ;
unsigned long V_137 = 0 ;
F_7 ( & V_43 -> V_27 ) ;
if ( V_43 -> V_138 ) {
F_9 ( & V_43 -> V_27 ) ;
return;
}
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_43 ( & V_43 -> V_11 , L_36 ,
V_134 -> V_7 -> V_28 , V_134 -> V_137 ) ;
if ( V_134 -> V_137 == V_145 )
continue;
if ( V_134 -> V_137 > V_137 )
V_137 = V_134 -> V_137 ;
}
V_43 -> V_34 -> V_140 ( V_43 , V_137 ) ;
V_43 -> V_138 = true ;
F_9 ( & V_43 -> V_27 ) ;
F_113 ( V_43 , V_137 ) ;
F_43 ( & V_43 -> V_11 , L_37 , V_137 ) ;
}
void F_114 ( struct V_6 * V_7 , int V_30 )
{
F_37 ( V_7 , V_30 ) ;
}
static int F_115 ( struct V_6 * V_7 , int V_45 )
{
int V_179 ;
int V_122 = sizeof( struct V_180 ) * V_7 -> V_49 ;
V_7 -> V_181 = F_90 ( V_122 , V_29 ) ;
if ( ! V_7 -> V_181 )
return - V_144 ;
V_7 -> V_182 = F_90 ( V_122 , V_29 ) ;
if ( ! V_7 -> V_182 ) {
F_97 ( V_7 -> V_181 ) ;
return - V_144 ;
}
if ( V_7 -> V_34 -> V_86 ) {
V_7 -> V_183 = F_90 ( V_122 , V_29 ) ;
if ( ! V_7 -> V_183 ) {
F_97 ( V_7 -> V_181 ) ;
F_97 ( V_7 -> V_182 ) ;
return - V_144 ;
}
}
for ( V_179 = 0 ; V_179 < V_7 -> V_49 ; V_179 ++ ) {
snprintf ( V_7 -> V_181 [ V_179 ] . V_2 , V_5 ,
L_14 , V_179 ) ;
F_92 ( & V_7 -> V_181 [ V_179 ] . V_102 . V_102 ) ;
V_7 -> V_181 [ V_179 ] . V_102 . V_102 . V_2 =
V_7 -> V_181 [ V_179 ] . V_2 ;
V_7 -> V_181 [ V_179 ] . V_102 . V_102 . V_105 = V_153 ;
V_7 -> V_181 [ V_179 ] . V_102 . V_149 = F_57 ;
F_76 ( & V_7 -> V_11 ,
& V_7 -> V_181 [ V_179 ] . V_102 ) ;
snprintf ( V_7 -> V_182 [ V_179 ] . V_2 , V_5 ,
L_20 , V_179 ) ;
F_92 ( & V_7 -> V_182 [ V_179 ] . V_102 . V_102 ) ;
V_7 -> V_182 [ V_179 ] . V_102 . V_102 . V_2 =
V_7 -> V_182 [ V_179 ] . V_2 ;
V_7 -> V_182 [ V_179 ] . V_102 . V_102 . V_105 = V_153 ;
V_7 -> V_182 [ V_179 ] . V_102 . V_149 = F_60 ;
if ( F_41 ( V_184 ) &&
V_45 & ( 1 << V_179 ) ) {
V_7 -> V_182 [ V_179 ] . V_102 . V_102 . V_105 |= V_152 ;
V_7 -> V_182 [ V_179 ] . V_102 . V_154 =
F_58 ;
}
F_76 ( & V_7 -> V_11 ,
& V_7 -> V_182 [ V_179 ] . V_102 ) ;
if ( ! V_7 -> V_34 -> V_86 )
continue;
snprintf ( V_7 -> V_183 [ V_179 ] . V_2 , V_5 ,
L_21 , V_179 ) ;
F_92 ( & V_7 -> V_183 [ V_179 ] . V_102 . V_102 ) ;
V_7 -> V_183 [ V_179 ] . V_102 . V_102 . V_2 =
V_7 -> V_183 [ V_179 ] . V_2 ;
V_7 -> V_183 [ V_179 ] . V_102 . V_102 . V_105 = V_153 ;
V_7 -> V_183 [ V_179 ] . V_102 . V_149 = F_62 ;
if ( V_7 -> V_34 -> V_115 ) {
V_7 -> V_183 [ V_179 ] . V_102 . V_102 . V_105 |= V_152 ;
V_7 -> V_183 [ V_179 ] . V_102 . V_154 =
F_61 ;
}
F_76 ( & V_7 -> V_11 ,
& V_7 -> V_183 [ V_179 ] . V_102 ) ;
}
return 0 ;
}
static void F_116 ( struct V_6 * V_7 )
{
int V_179 ;
for ( V_179 = 0 ; V_179 < V_7 -> V_49 ; V_179 ++ ) {
F_95 ( & V_7 -> V_11 ,
& V_7 -> V_181 [ V_179 ] . V_102 ) ;
F_95 ( & V_7 -> V_11 ,
& V_7 -> V_182 [ V_179 ] . V_102 ) ;
if ( V_7 -> V_34 -> V_86 )
F_95 ( & V_7 -> V_11 ,
& V_7 -> V_183 [ V_179 ] . V_102 ) ;
}
F_97 ( V_7 -> V_181 ) ;
F_97 ( V_7 -> V_182 ) ;
F_97 ( V_7 -> V_183 ) ;
}
struct V_6 * F_117 ( const char * type ,
int V_49 , int V_45 , void * V_166 ,
struct V_185 * V_34 ,
struct V_53 * V_23 ,
int V_64 , int V_65 )
{
struct V_6 * V_7 ;
enum V_66 V_67 ;
int V_69 ;
int V_106 ;
int V_77 ;
int V_63 = 0 ;
struct V_1 * V_9 ;
if ( type && strlen ( type ) >= V_5 )
return F_102 ( - V_16 ) ;
if ( V_49 > V_186 || V_49 < 0 || V_45 > > V_49 )
return F_102 ( - V_16 ) ;
if ( ! V_34 )
return F_102 ( - V_16 ) ;
if ( V_49 > 0 && ( ! V_34 -> V_74 || ! V_34 -> V_70 ) )
return F_102 ( - V_16 ) ;
V_7 = F_90 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return F_102 ( - V_144 ) ;
F_105 ( & V_7 -> V_158 ) ;
F_118 ( & V_7 -> V_25 ) ;
F_104 ( & V_7 -> V_27 ) ;
V_106 = F_12 ( & V_187 , & V_169 , & V_7 -> V_28 ) ;
if ( V_106 ) {
F_97 ( V_7 ) ;
return F_102 ( V_106 ) ;
}
F_103 ( V_7 -> type , type ? : L_34 , sizeof( V_7 -> type ) ) ;
V_7 -> V_34 = V_34 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_11 . V_170 = & V_171 ;
V_7 -> V_166 = V_166 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_65 = V_65 ;
F_94 ( & V_7 -> V_160 , 1 ) ;
F_106 ( & V_7 -> V_11 , L_38 , V_7 -> V_28 ) ;
V_106 = F_107 ( & V_7 -> V_11 ) ;
if ( V_106 ) {
F_15 ( & V_187 , & V_169 , V_7 -> V_28 ) ;
F_97 ( V_7 ) ;
return F_102 ( V_106 ) ;
}
if ( type ) {
V_106 = F_76 ( & V_7 -> V_11 , & V_188 ) ;
if ( V_106 )
goto V_189;
}
V_106 = F_76 ( & V_7 -> V_11 , & V_190 ) ;
if ( V_106 )
goto V_189;
if ( V_34 -> V_107 ) {
V_106 = F_76 ( & V_7 -> V_11 , & V_191 ) ;
if ( V_106 )
goto V_189;
}
V_106 = F_115 ( V_7 , V_45 ) ;
if ( V_106 )
goto V_189;
for ( V_77 = 0 ; V_77 < V_49 ; V_77 ++ ) {
if ( V_7 -> V_34 -> V_74 ( V_7 , V_77 , & V_67 ) )
F_119 ( V_77 , & V_7 -> V_73 ) ;
if ( V_67 == V_112 )
V_63 = 1 ;
if ( V_7 -> V_34 -> V_70 ( V_7 , V_77 , & V_69 ) )
F_119 ( V_77 , & V_7 -> V_73 ) ;
if ( V_69 == 0 )
F_119 ( V_77 , & V_7 -> V_73 ) ;
}
if ( ! V_63 ) {
V_106 = F_76 ( & V_7 -> V_11 , & V_192 ) ;
if ( V_106 )
goto V_189;
}
if ( F_41 ( V_81 ) ) {
V_106 = F_76 ( & V_7 -> V_11 , & V_193 ) ;
if ( V_106 )
goto V_189;
}
V_106 = F_76 ( & V_7 -> V_11 , & V_194 ) ;
if ( V_106 )
goto V_189;
V_106 = F_74 ( & V_7 -> V_11 ) ;
if ( V_106 )
goto V_189;
V_106 = F_76 ( & V_7 -> V_11 , & V_195 ) ;
if ( V_106 )
goto V_189;
F_7 ( & V_17 ) ;
if ( V_7 -> V_23 )
V_9 = F_1 ( V_7 -> V_23 -> V_24 ) ;
else
V_9 = V_4 ;
V_106 = F_5 ( V_7 , V_9 ) ;
if ( V_106 ) {
F_9 ( & V_17 ) ;
goto V_189;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_23 || ! V_7 -> V_23 -> V_196 ) {
V_106 = F_120 ( V_7 ) ;
if ( V_106 )
goto V_189;
}
F_7 ( & V_22 ) ;
F_93 ( & V_7 -> V_174 , & V_197 ) ;
F_9 ( & V_22 ) ;
F_25 ( V_7 ) ;
F_121 ( & ( V_7 -> V_62 ) , F_50 ) ;
F_47 ( V_7 ) ;
if ( F_108 ( & V_7 -> V_160 , 1 , 0 ) )
F_48 ( V_7 , V_99 ) ;
return V_7 ;
V_189:
F_15 ( & V_187 , & V_169 , V_7 -> V_28 ) ;
F_112 ( & V_7 -> V_11 ) ;
return F_102 ( V_106 ) ;
}
void F_122 ( struct V_6 * V_7 )
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
F_11 ( & V_7 -> V_174 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_34 -> V_162 ) {
V_7 -> V_34 -> V_162 ( V_7 , V_43 ) ;
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
F_95 ( & V_7 -> V_11 , & V_188 ) ;
F_95 ( & V_7 -> V_11 , & V_190 ) ;
if ( V_7 -> V_34 -> V_107 )
F_95 ( & V_7 -> V_11 , & V_191 ) ;
F_95 ( & V_7 -> V_11 , & V_194 ) ;
F_95 ( & V_7 -> V_11 , & V_195 ) ;
F_116 ( V_7 ) ;
F_5 ( V_7 , NULL ) ;
F_123 ( V_7 ) ;
F_15 ( & V_187 , & V_169 , V_7 -> V_28 ) ;
F_124 ( & V_7 -> V_25 ) ;
F_125 ( & V_7 -> V_27 ) ;
F_112 ( & V_7 -> V_11 ) ;
return;
}
struct V_6 * F_126 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_198 = F_102 ( - V_16 ) ;
unsigned int V_199 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_199 ++ ;
V_198 = V_3 ;
}
F_9 ( & V_22 ) ;
if ( V_199 == 0 )
V_198 = F_102 ( - V_163 ) ;
else if ( V_199 > 1 )
V_198 = F_102 ( - V_156 ) ;
exit:
return V_198 ;
}
int F_127 ( struct V_6 * V_7 )
{
if ( V_7 && V_7 -> V_23 )
return V_7 -> V_23 -> V_200 ;
return 1 ;
}
int F_128 ( struct V_6 * V_7 )
{
if ( V_7 && V_7 -> V_23 )
return V_7 -> V_23 -> V_201 ;
return 0 ;
}
int F_129 ( struct V_6 * V_7 ,
enum V_202 V_94 )
{
struct V_203 * V_204 ;
struct V_205 * V_102 ;
struct V_206 * V_207 ;
void * V_208 ;
int V_122 ;
int V_106 ;
static unsigned int V_209 ;
if ( ! V_7 )
return - V_16 ;
V_122 = F_130 ( sizeof( struct V_206 ) ) +
F_130 ( 0 ) ;
V_204 = F_131 ( V_122 , V_210 ) ;
if ( ! V_204 )
return - V_144 ;
V_208 = F_132 ( V_204 , 0 , V_209 ++ ,
& V_211 , 0 ,
V_212 ) ;
if ( ! V_208 ) {
F_133 ( V_204 ) ;
return - V_144 ;
}
V_102 = F_134 ( V_204 , V_213 ,
sizeof( struct V_206 ) ) ;
if ( ! V_102 ) {
F_133 ( V_204 ) ;
return - V_16 ;
}
V_207 = F_135 ( V_102 ) ;
if ( ! V_207 ) {
F_133 ( V_204 ) ;
return - V_16 ;
}
memset ( V_207 , 0 , sizeof( struct V_206 ) ) ;
V_207 -> V_214 = V_7 -> V_28 ;
V_207 -> V_94 = V_94 ;
F_136 ( V_204 , V_208 ) ;
V_106 = F_137 ( & V_211 , V_204 , 0 ,
0 , V_210 ) ;
if ( V_106 )
F_4 ( & V_7 -> V_11 , L_39 , V_106 ) ;
return V_106 ;
}
static int F_138 ( void )
{
return F_139 ( & V_211 ) ;
}
static void F_140 ( void )
{
F_141 ( & V_211 ) ;
}
static inline int F_138 ( void ) { return 0 ; }
static inline void F_140 ( void ) {}
static int T_4 F_142 ( void )
{
int V_106 ;
V_106 = F_143 () ;
if ( V_106 )
return V_106 ;
V_106 = F_144 () ;
if ( V_106 )
return V_106 ;
V_106 = F_145 () ;
if ( V_106 )
return V_106 ;
V_106 = F_146 () ;
if ( V_106 )
return V_106 ;
return F_147 () ;
}
static void F_148 ( void )
{
F_149 () ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
}
static int F_154 ( struct V_215 * V_216 ,
unsigned long V_105 , void * V_217 )
{
struct V_6 * V_7 ;
switch ( V_105 ) {
case V_218 :
case V_219 :
case V_220 :
F_94 ( & V_95 , 1 ) ;
break;
case V_221 :
case V_222 :
case V_223 :
F_94 ( & V_95 , 0 ) ;
F_2 (tz, &thermal_tz_list, node) {
F_47 ( V_7 ) ;
F_48 ( V_7 ,
V_99 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int T_4 F_155 ( void )
{
int V_106 ;
V_106 = F_142 () ;
if ( V_106 )
goto error;
V_106 = F_156 ( & V_171 ) ;
if ( V_106 )
goto V_224;
V_106 = F_138 () ;
if ( V_106 )
goto V_225;
V_106 = F_157 () ;
if ( V_106 )
goto V_226;
V_106 = F_158 ( & V_227 ) ;
if ( V_106 )
F_159 ( L_40 ,
V_106 ) ;
return 0 ;
V_226:
F_140 () ;
V_225:
F_160 ( & V_171 ) ;
V_224:
F_148 () ;
error:
F_124 ( & V_187 ) ;
F_124 ( & V_168 ) ;
F_125 ( & V_169 ) ;
F_125 ( & V_22 ) ;
F_125 ( & V_17 ) ;
return V_106 ;
}
static void T_5 F_161 ( void )
{
F_162 ( & V_227 ) ;
F_163 () ;
F_140 () ;
F_160 ( & V_171 ) ;
F_148 () ;
F_124 ( & V_187 ) ;
F_124 ( & V_168 ) ;
F_125 ( & V_169 ) ;
F_125 ( & V_22 ) ;
F_125 ( & V_17 ) ;
}
