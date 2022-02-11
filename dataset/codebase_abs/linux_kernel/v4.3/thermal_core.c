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
F_44 ( & V_7 -> V_11 , L_6 ,
V_7 -> V_37 , V_7 -> V_36 ) ;
}
void F_45 ( struct V_6 * V_7 )
{
int V_76 ;
if ( ! V_7 -> V_34 -> V_79 )
return;
F_41 ( V_7 ) ;
for ( V_76 = 0 ; V_76 < V_7 -> V_49 ; V_76 ++ )
F_37 ( V_7 , V_76 ) ;
}
static void F_46 ( struct V_82 * V_83 )
{
struct V_6 * V_7 = F_47 ( V_83 , struct
V_6 ,
V_62 . V_83 ) ;
F_45 ( V_7 ) ;
}
static T_1
F_48 ( struct V_11 * V_84 , struct V_85 * V_86 , char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
return sprintf ( V_87 , L_7 , V_7 -> type ) ;
}
static T_1
F_50 ( struct V_11 * V_84 , struct V_85 * V_86 , char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_36 , V_13 ;
V_13 = F_38 ( V_7 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_87 , L_8 , V_36 ) ;
}
static T_1
F_51 ( struct V_11 * V_84 , struct V_85 * V_86 , char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
enum V_88 V_89 ;
int V_90 ;
if ( ! V_7 -> V_34 -> V_91 )
return - V_92 ;
V_90 = V_7 -> V_34 -> V_91 ( V_7 , & V_89 ) ;
if ( V_90 )
return V_90 ;
return sprintf ( V_87 , L_7 , V_89 == V_93 ? L_9
: L_10 ) ;
}
static T_1
F_52 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_90 ;
if ( ! V_7 -> V_34 -> V_94 )
return - V_92 ;
if ( ! strncmp ( V_87 , L_9 , sizeof( L_9 ) - 1 ) )
V_90 = V_7 -> V_34 -> V_94 ( V_7 , V_93 ) ;
else if ( ! strncmp ( V_87 , L_10 , sizeof( L_10 ) - 1 ) )
V_90 = V_7 -> V_34 -> V_94 ( V_7 , V_95 ) ;
else
V_90 = - V_16 ;
if ( V_90 )
return V_90 ;
return V_76 ;
}
static T_1
F_53 ( struct V_11 * V_84 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
enum V_66 type ;
int V_30 , V_90 ;
if ( ! V_7 -> V_34 -> V_73 )
return - V_92 ;
if ( ! sscanf ( V_86 -> V_86 . V_2 , L_11 , & V_30 ) )
return - V_16 ;
V_90 = V_7 -> V_34 -> V_73 ( V_7 , V_30 , & type ) ;
if ( V_90 )
return V_90 ;
switch ( type ) {
case V_72 :
return sprintf ( V_87 , L_12 ) ;
case V_74 :
return sprintf ( V_87 , L_13 ) ;
case V_96 :
return sprintf ( V_87 , L_14 ) ;
case V_97 :
return sprintf ( V_87 , L_15 ) ;
default:
return sprintf ( V_87 , L_16 ) ;
}
}
static T_1
F_54 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_30 , V_13 ;
unsigned long V_36 ;
if ( ! V_7 -> V_34 -> V_98 )
return - V_92 ;
if ( ! sscanf ( V_86 -> V_86 . V_2 , L_17 , & V_30 ) )
return - V_16 ;
if ( F_55 ( V_87 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_98 ( V_7 , V_30 , V_36 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_56 ( struct V_11 * V_84 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_70 )
return - V_92 ;
if ( ! sscanf ( V_86 -> V_86 . V_2 , L_17 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_30 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_87 , L_8 , V_36 ) ;
}
static T_1
F_57 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_99 )
return - V_92 ;
if ( ! sscanf ( V_86 -> V_86 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
if ( F_58 ( V_87 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_99 ( V_7 , V_30 , V_36 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_59 ( struct V_11 * V_84 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_30 , V_13 ;
int V_36 ;
if ( ! V_7 -> V_34 -> V_100 )
return - V_92 ;
if ( ! sscanf ( V_86 -> V_86 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_100 ( V_7 , V_30 , & V_36 ) ;
return V_13 ? V_13 : sprintf ( V_87 , L_8 , V_36 ) ;
}
static T_1
F_60 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
struct V_42 * V_43 = NULL ;
int V_101 ;
if ( ! sscanf ( V_87 , L_8 , & V_101 ) )
return - V_16 ;
if ( V_101 && V_101 < 1000 )
return - V_16 ;
if ( V_101 && ! V_7 -> V_102 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_19 , V_43 -> type ,
sizeof( L_19 ) ) )
F_21 ( V_7 ,
V_103 , V_43 ,
V_52 ,
V_52 ,
V_104 ) ;
}
F_9 ( & V_22 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = 1000 ;
} else if ( ! V_101 && V_7 -> V_102 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_19 , V_43 -> type ,
sizeof( L_19 ) ) )
F_23 ( V_7 ,
V_103 ,
V_43 ) ;
}
F_9 ( & V_22 ) ;
V_7 -> V_64 = 0 ;
}
V_7 -> V_102 = V_101 ;
F_45 ( V_7 ) ;
return V_76 ;
}
static T_1
F_61 ( struct V_11 * V_84 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
return sprintf ( V_87 , L_8 , V_7 -> V_102 ) ;
}
static T_1
F_62 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
int V_13 = - V_16 ;
struct V_6 * V_7 = F_49 ( V_84 ) ;
struct V_1 * V_105 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_20 , V_87 ) ;
F_7 ( & V_17 ) ;
F_7 ( & V_7 -> V_27 ) ;
V_105 = F_1 ( F_63 ( V_2 ) ) ;
if ( ! V_105 )
goto exit;
V_13 = F_5 ( V_7 , V_105 ) ;
if ( ! V_13 )
V_13 = V_76 ;
exit:
F_9 ( & V_7 -> V_27 ) ;
F_9 ( & V_17 ) ;
return V_13 ;
}
static T_1
F_64 ( struct V_11 * V_84 , struct V_85 * V_106 , char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
return sprintf ( V_87 , L_7 , V_7 -> V_9 -> V_2 ) ;
}
static T_1
F_65 ( struct V_11 * V_84 , struct V_85 * V_106 ,
char * V_87 )
{
struct V_1 * V_3 ;
T_1 V_76 = 0 ;
T_1 V_107 = V_108 ;
F_7 ( & V_17 ) ;
F_2 (pos, &thermal_governor_list, governor_list) {
V_107 = V_108 - V_76 ;
V_76 += F_66 ( V_87 + V_76 , V_107 , L_21 , V_3 -> V_2 ) ;
}
V_76 += F_66 ( V_87 + V_76 , V_107 , L_22 ) ;
F_9 ( & V_17 ) ;
return V_76 ;
}
static T_1
F_67 ( struct V_11 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
int V_13 = 0 ;
unsigned long V_36 ;
if ( F_55 ( V_87 , 10 , & V_36 ) )
return - V_16 ;
if ( ! V_7 -> V_34 -> V_109 ) {
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_33 = V_36 ;
F_9 ( & V_7 -> V_27 ) ;
} else {
V_13 = V_7 -> V_34 -> V_109 ( V_7 , V_36 ) ;
}
if ( ! V_13 )
F_45 ( V_7 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_68 ( struct V_11 * V_84 , struct V_85 * V_106 ,
char * V_87 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
if ( V_7 -> V_23 )
return sprintf ( V_87 , L_23 , V_7 -> V_23 -> V_110 ) ;
else
return - V_111 ;
}
static T_1
F_69 ( struct V_11 * V_84 , struct V_85 * V_106 ,
const char * V_87 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_84 ) ;
T_3 V_110 ;
if ( ! V_7 -> V_23 )
return - V_111 ;
if ( F_70 ( V_87 , 10 , & V_110 ) )
return - V_16 ;
V_7 -> V_23 -> V_110 = V_110 ;
return V_76 ;
}
static int F_71 ( struct V_11 * V_84 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_72 ( V_112 ) ; V_48 ++ ) {
int V_13 ;
struct V_85 * V_113 = V_112 [ V_48 ] ;
V_13 = F_73 ( V_84 , V_113 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_74 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_114 )
{
if ( ! F_75 ( V_43 ) )
return - V_16 ;
return V_43 -> V_34 -> V_115 ( V_43 , V_7 , 0 , V_114 ) ;
}
int F_76 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_116 )
{
unsigned long V_117 ;
int V_13 ;
if ( ! F_75 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_118 ( V_43 , & V_117 ) ;
if ( V_13 )
return V_13 ;
return V_43 -> V_34 -> V_115 ( V_43 , V_7 , V_117 , V_116 ) ;
}
int F_77 ( struct V_42 * V_43 ,
struct V_41 * V_119 , T_3 V_120 )
{
unsigned long V_101 ;
int V_13 ;
if ( ! F_75 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_121 ( V_43 , V_119 -> V_7 , V_120 , & V_101 ) ;
if ( V_13 )
return V_13 ;
V_119 -> V_122 = V_101 ;
V_43 -> V_123 = false ;
F_78 ( V_43 ) ;
return 0 ;
}
static T_1
F_79 ( struct V_11 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_42 * V_43 = F_80 ( V_84 ) ;
return sprintf ( V_87 , L_7 , V_43 -> type ) ;
}
static T_1
F_81 ( struct V_11 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_42 * V_43 = F_80 ( V_84 ) ;
unsigned long V_101 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_118 ( V_43 , & V_101 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_87 , L_24 , V_101 ) ;
}
static T_1
F_82 ( struct V_11 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_42 * V_43 = F_80 ( V_84 ) ;
unsigned long V_101 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_124 ( V_43 , & V_101 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_87 , L_24 , V_101 ) ;
}
static T_1
F_83 ( struct V_11 * V_84 ,
struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_42 * V_43 = F_80 ( V_84 ) ;
unsigned long V_101 ;
int V_90 ;
if ( ! sscanf ( V_87 , L_24 , & V_101 ) )
return - V_16 ;
if ( ( long ) V_101 < 0 )
return - V_16 ;
V_90 = V_43 -> V_34 -> V_125 ( V_43 , V_101 ) ;
if ( V_90 )
return V_90 ;
return V_76 ;
}
static T_1
F_84 ( struct V_11 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_41 * V_119 ;
V_119 =
F_47 ( V_86 , struct V_41 , V_86 ) ;
if ( V_119 -> V_30 == V_103 )
return sprintf ( V_87 , L_25 ) ;
else
return sprintf ( V_87 , L_8 , V_119 -> V_30 ) ;
}
static T_1
F_85 ( struct V_11 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_41 * V_119 ;
V_119 = F_47 ( V_86 , struct V_41 , V_126 ) ;
return sprintf ( V_87 , L_8 , V_119 -> V_47 ) ;
}
static T_1
F_86 ( struct V_11 * V_84 ,
struct V_85 * V_86 ,
const char * V_87 , T_2 V_76 )
{
struct V_41 * V_119 ;
int V_13 , V_47 ;
V_13 = F_58 ( V_87 , 0 , & V_47 ) ;
if ( V_13 )
return V_13 ;
V_119 = F_47 ( V_86 , struct V_41 , V_126 ) ;
V_119 -> V_47 = V_47 ;
return V_76 ;
}
int F_21 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 ,
unsigned long V_50 , unsigned long V_51 ,
unsigned int V_47 )
{
struct V_41 * V_84 ;
struct V_41 * V_3 ;
struct V_6 * V_127 ;
struct V_42 * V_128 ;
unsigned long V_117 ;
int V_90 , V_13 ;
if ( V_30 >= V_7 -> V_49 || ( V_30 < 0 && V_30 != V_103 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_127 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_128 == V_43 )
break;
}
if ( V_7 != V_127 || V_43 != V_128 )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_118 ( V_43 , & V_117 ) ;
if ( V_13 )
return V_13 ;
V_51 = V_51 == V_52 ? 0 : V_51 ;
V_50 = V_50 == V_52 ? V_117 : V_50 ;
if ( V_51 > V_50 || V_50 > V_117 )
return - V_16 ;
V_84 =
F_87 ( sizeof( struct V_41 ) , V_29 ) ;
if ( ! V_84 )
return - V_129 ;
V_84 -> V_7 = V_7 ;
V_84 -> V_43 = V_43 ;
V_84 -> V_30 = V_30 ;
V_84 -> V_50 = V_50 ;
V_84 -> V_51 = V_51 ;
V_84 -> V_122 = V_130 ;
V_84 -> V_47 = V_47 ;
V_90 = F_12 ( & V_7 -> V_25 , & V_7 -> V_27 , & V_84 -> V_28 ) ;
if ( V_90 )
goto V_131;
sprintf ( V_84 -> V_2 , L_26 , V_84 -> V_28 ) ;
V_90 =
F_88 ( & V_7 -> V_11 . V_132 , & V_43 -> V_11 . V_132 , V_84 -> V_2 ) ;
if ( V_90 )
goto F_15;
sprintf ( V_84 -> V_133 , L_27 , V_84 -> V_28 ) ;
F_89 ( & V_84 -> V_86 . V_86 ) ;
V_84 -> V_86 . V_86 . V_2 = V_84 -> V_133 ;
V_84 -> V_86 . V_86 . V_89 = 0444 ;
V_84 -> V_86 . V_134 = F_84 ;
V_90 = F_73 ( & V_7 -> V_11 , & V_84 -> V_86 ) ;
if ( V_90 )
goto V_135;
sprintf ( V_84 -> V_136 , L_28 , V_84 -> V_28 ) ;
F_89 ( & V_84 -> V_126 . V_86 ) ;
V_84 -> V_126 . V_86 . V_2 = V_84 -> V_136 ;
V_84 -> V_126 . V_86 . V_89 = V_137 | V_138 ;
V_84 -> V_126 . V_134 = F_85 ;
V_84 -> V_126 . V_139 = F_86 ;
V_90 = F_73 ( & V_7 -> V_11 , & V_84 -> V_126 ) ;
if ( V_90 )
goto V_140;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
V_90 = - V_141 ;
break;
}
if ( ! V_90 ) {
F_90 ( & V_84 -> V_142 , & V_7 -> V_143 ) ;
F_90 ( & V_84 -> V_144 , & V_43 -> V_143 ) ;
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
if ( ! V_90 )
return 0 ;
F_91 ( & V_7 -> V_11 , & V_84 -> V_126 ) ;
V_140:
F_91 ( & V_7 -> V_11 , & V_84 -> V_86 ) ;
V_135:
F_92 ( & V_7 -> V_11 . V_132 , V_84 -> V_2 ) ;
F_15:
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_84 -> V_28 ) ;
V_131:
F_93 ( V_84 ) ;
return V_90 ;
}
int F_23 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 )
{
struct V_41 * V_3 , * V_145 ;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_94 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
F_11 ( & V_3 -> V_142 ) ;
F_11 ( & V_3 -> V_144 ) ;
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
goto V_146;
}
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
return - V_147 ;
V_146:
F_91 ( & V_7 -> V_11 , & V_3 -> V_126 ) ;
F_91 ( & V_7 -> V_11 , & V_3 -> V_86 ) ;
F_92 ( & V_7 -> V_11 . V_132 , V_3 -> V_2 ) ;
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_3 -> V_28 ) ;
F_93 ( V_3 ) ;
return 0 ;
}
static void F_95 ( struct V_11 * V_84 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( ! strncmp ( F_96 ( V_84 ) , L_29 ,
sizeof( L_29 ) - 1 ) ) {
V_7 = F_49 ( V_84 ) ;
F_93 ( V_7 ) ;
} else if( ! strncmp ( F_96 ( V_84 ) , L_30 ,
sizeof( L_30 ) - 1 ) ) {
V_43 = F_80 ( V_84 ) ;
F_93 ( V_43 ) ;
}
}
static struct V_42 *
F_97 ( struct V_148 * V_149 ,
char * type , void * V_150 ,
const struct V_151 * V_34 )
{
struct V_42 * V_43 ;
int V_90 ;
if ( type && strlen ( type ) >= V_5 )
return F_98 ( - V_16 ) ;
if ( ! V_34 || ! V_34 -> V_118 || ! V_34 -> V_124 ||
! V_34 -> V_125 )
return F_98 ( - V_16 ) ;
V_43 = F_87 ( sizeof( struct V_42 ) , V_29 ) ;
if ( ! V_43 )
return F_98 ( - V_129 ) ;
V_90 = F_12 ( & V_152 , & V_153 , & V_43 -> V_28 ) ;
if ( V_90 ) {
F_93 ( V_43 ) ;
return F_98 ( V_90 ) ;
}
F_99 ( V_43 -> type , type ? : L_31 , sizeof( V_43 -> type ) ) ;
F_100 ( & V_43 -> V_27 ) ;
F_101 ( & V_43 -> V_143 ) ;
V_43 -> V_149 = V_149 ;
V_43 -> V_34 = V_34 ;
V_43 -> V_123 = false ;
V_43 -> V_11 . V_154 = & V_155 ;
V_43 -> V_11 . V_156 = V_157 ;
V_43 -> V_150 = V_150 ;
F_102 ( & V_43 -> V_11 , L_32 , V_43 -> V_28 ) ;
V_90 = F_103 ( & V_43 -> V_11 ) ;
if ( V_90 ) {
F_15 ( & V_152 , & V_153 , V_43 -> V_28 ) ;
F_93 ( V_43 ) ;
return F_98 ( V_90 ) ;
}
F_7 ( & V_22 ) ;
F_8 ( & V_43 -> V_158 , & V_159 ) ;
F_9 ( & V_22 ) ;
F_24 ( V_43 ) ;
return V_43 ;
}
struct V_42 *
F_104 ( char * type , void * V_150 ,
const struct V_151 * V_34 )
{
return F_97 ( NULL , type , V_150 , V_34 ) ;
}
struct V_42 *
F_105 ( struct V_148 * V_149 ,
char * type , void * V_150 ,
const struct V_151 * V_34 )
{
return F_97 ( V_149 , type , V_150 , V_34 ) ;
}
void F_106 ( struct V_42 * V_43 )
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
F_11 ( & V_43 -> V_158 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_34 -> V_146 ) {
V_7 -> V_34 -> V_146 ( V_7 , V_43 ) ;
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
F_91 ( & V_43 -> V_11 , & V_160 ) ;
F_91 ( & V_43 -> V_11 , & V_161 ) ;
F_91 ( & V_43 -> V_11 , & V_162 ) ;
F_15 ( & V_152 , & V_153 , V_43 -> V_28 ) ;
F_107 ( & V_43 -> V_11 ) ;
return;
}
void F_78 ( struct V_42 * V_43 )
{
struct V_41 * V_119 ;
unsigned long V_122 = 0 ;
if ( V_43 -> V_123 )
return;
F_7 ( & V_43 -> V_27 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_44 ( & V_43 -> V_11 , L_33 ,
V_119 -> V_7 -> V_28 , V_119 -> V_122 ) ;
if ( V_119 -> V_122 == V_130 )
continue;
if ( V_119 -> V_122 > V_122 )
V_122 = V_119 -> V_122 ;
}
F_9 ( & V_43 -> V_27 ) ;
V_43 -> V_34 -> V_125 ( V_43 , V_122 ) ;
V_43 -> V_123 = true ;
F_108 ( V_43 , V_122 ) ;
F_44 ( & V_43 -> V_11 , L_34 , V_122 ) ;
}
void F_109 ( struct V_6 * V_7 , int V_30 )
{
F_37 ( V_7 , V_30 ) ;
}
static int F_110 ( struct V_6 * V_7 , int V_45 )
{
int V_163 ;
int V_107 = sizeof( struct V_164 ) * V_7 -> V_49 ;
V_7 -> V_165 = F_87 ( V_107 , V_29 ) ;
if ( ! V_7 -> V_165 )
return - V_129 ;
V_7 -> V_166 = F_87 ( V_107 , V_29 ) ;
if ( ! V_7 -> V_166 ) {
F_93 ( V_7 -> V_165 ) ;
return - V_129 ;
}
if ( V_7 -> V_34 -> V_100 ) {
V_7 -> V_167 = F_87 ( V_107 , V_29 ) ;
if ( ! V_7 -> V_167 ) {
F_93 ( V_7 -> V_165 ) ;
F_93 ( V_7 -> V_166 ) ;
return - V_129 ;
}
}
for ( V_163 = 0 ; V_163 < V_7 -> V_49 ; V_163 ++ ) {
snprintf ( V_7 -> V_165 [ V_163 ] . V_2 , V_5 ,
L_11 , V_163 ) ;
F_89 ( & V_7 -> V_165 [ V_163 ] . V_86 . V_86 ) ;
V_7 -> V_165 [ V_163 ] . V_86 . V_86 . V_2 =
V_7 -> V_165 [ V_163 ] . V_2 ;
V_7 -> V_165 [ V_163 ] . V_86 . V_86 . V_89 = V_138 ;
V_7 -> V_165 [ V_163 ] . V_86 . V_134 = F_53 ;
F_73 ( & V_7 -> V_11 ,
& V_7 -> V_165 [ V_163 ] . V_86 ) ;
snprintf ( V_7 -> V_166 [ V_163 ] . V_2 , V_5 ,
L_17 , V_163 ) ;
F_89 ( & V_7 -> V_166 [ V_163 ] . V_86 . V_86 ) ;
V_7 -> V_166 [ V_163 ] . V_86 . V_86 . V_2 =
V_7 -> V_166 [ V_163 ] . V_2 ;
V_7 -> V_166 [ V_163 ] . V_86 . V_86 . V_89 = V_138 ;
V_7 -> V_166 [ V_163 ] . V_86 . V_134 = F_56 ;
if ( F_40 ( V_168 ) &&
V_45 & ( 1 << V_163 ) ) {
V_7 -> V_166 [ V_163 ] . V_86 . V_86 . V_89 |= V_137 ;
V_7 -> V_166 [ V_163 ] . V_86 . V_139 =
F_54 ;
}
F_73 ( & V_7 -> V_11 ,
& V_7 -> V_166 [ V_163 ] . V_86 ) ;
if ( ! V_7 -> V_34 -> V_100 )
continue;
snprintf ( V_7 -> V_167 [ V_163 ] . V_2 , V_5 ,
L_18 , V_163 ) ;
F_89 ( & V_7 -> V_167 [ V_163 ] . V_86 . V_86 ) ;
V_7 -> V_167 [ V_163 ] . V_86 . V_86 . V_2 =
V_7 -> V_167 [ V_163 ] . V_2 ;
V_7 -> V_167 [ V_163 ] . V_86 . V_86 . V_89 = V_138 ;
V_7 -> V_167 [ V_163 ] . V_86 . V_134 = F_59 ;
if ( V_7 -> V_34 -> V_99 ) {
V_7 -> V_167 [ V_163 ] . V_86 . V_86 . V_89 |= V_137 ;
V_7 -> V_167 [ V_163 ] . V_86 . V_139 =
F_57 ;
}
F_73 ( & V_7 -> V_11 ,
& V_7 -> V_167 [ V_163 ] . V_86 ) ;
}
return 0 ;
}
static void F_111 ( struct V_6 * V_7 )
{
int V_163 ;
for ( V_163 = 0 ; V_163 < V_7 -> V_49 ; V_163 ++ ) {
F_91 ( & V_7 -> V_11 ,
& V_7 -> V_165 [ V_163 ] . V_86 ) ;
F_91 ( & V_7 -> V_11 ,
& V_7 -> V_166 [ V_163 ] . V_86 ) ;
if ( V_7 -> V_34 -> V_100 )
F_91 ( & V_7 -> V_11 ,
& V_7 -> V_167 [ V_163 ] . V_86 ) ;
}
F_93 ( V_7 -> V_165 ) ;
F_93 ( V_7 -> V_166 ) ;
F_93 ( V_7 -> V_167 ) ;
}
struct V_6 * F_112 ( const char * type ,
int V_49 , int V_45 , void * V_150 ,
struct V_169 * V_34 ,
struct V_53 * V_23 ,
int V_64 , int V_65 )
{
struct V_6 * V_7 ;
enum V_66 V_67 ;
int V_90 ;
int V_76 ;
int V_63 = 0 ;
struct V_1 * V_9 ;
if ( type && strlen ( type ) >= V_5 )
return F_98 ( - V_16 ) ;
if ( V_49 > V_170 || V_49 < 0 || V_45 > > V_49 )
return F_98 ( - V_16 ) ;
if ( ! V_34 )
return F_98 ( - V_16 ) ;
if ( V_49 > 0 && ( ! V_34 -> V_73 || ! V_34 -> V_70 ) )
return F_98 ( - V_16 ) ;
V_7 = F_87 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return F_98 ( - V_129 ) ;
F_101 ( & V_7 -> V_143 ) ;
F_113 ( & V_7 -> V_25 ) ;
F_100 ( & V_7 -> V_27 ) ;
V_90 = F_12 ( & V_171 , & V_153 , & V_7 -> V_28 ) ;
if ( V_90 ) {
F_93 ( V_7 ) ;
return F_98 ( V_90 ) ;
}
F_99 ( V_7 -> type , type ? : L_31 , sizeof( V_7 -> type ) ) ;
V_7 -> V_34 = V_34 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_11 . V_154 = & V_155 ;
V_7 -> V_150 = V_150 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_65 = V_65 ;
F_102 ( & V_7 -> V_11 , L_35 , V_7 -> V_28 ) ;
V_90 = F_103 ( & V_7 -> V_11 ) ;
if ( V_90 ) {
F_15 ( & V_171 , & V_153 , V_7 -> V_28 ) ;
F_93 ( V_7 ) ;
return F_98 ( V_90 ) ;
}
if ( type ) {
V_90 = F_73 ( & V_7 -> V_11 , & V_172 ) ;
if ( V_90 )
goto V_173;
}
V_90 = F_73 ( & V_7 -> V_11 , & V_174 ) ;
if ( V_90 )
goto V_173;
if ( V_34 -> V_91 ) {
V_90 = F_73 ( & V_7 -> V_11 , & V_175 ) ;
if ( V_90 )
goto V_173;
}
V_90 = F_110 ( V_7 , V_45 ) ;
if ( V_90 )
goto V_173;
for ( V_76 = 0 ; V_76 < V_49 ; V_76 ++ ) {
V_7 -> V_34 -> V_73 ( V_7 , V_76 , & V_67 ) ;
if ( V_67 == V_96 )
V_63 = 1 ;
}
if ( ! V_63 ) {
V_90 = F_73 ( & V_7 -> V_11 , & V_176 ) ;
if ( V_90 )
goto V_173;
}
if ( F_40 ( V_80 ) ) {
V_90 = F_73 ( & V_7 -> V_11 , & V_177 ) ;
if ( V_90 )
goto V_173;
}
V_90 = F_73 ( & V_7 -> V_11 , & V_178 ) ;
if ( V_90 )
goto V_173;
V_90 = F_71 ( & V_7 -> V_11 ) ;
if ( V_90 )
goto V_173;
V_90 = F_73 ( & V_7 -> V_11 , & V_179 ) ;
if ( V_90 )
goto V_173;
F_7 ( & V_17 ) ;
if ( V_7 -> V_23 )
V_9 = F_1 ( V_7 -> V_23 -> V_24 ) ;
else
V_9 = V_4 ;
V_90 = F_5 ( V_7 , V_9 ) ;
if ( V_90 ) {
F_9 ( & V_17 ) ;
goto V_173;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_23 || ! V_7 -> V_23 -> V_180 ) {
V_90 = F_114 ( V_7 ) ;
if ( V_90 )
goto V_173;
}
F_7 ( & V_22 ) ;
F_90 ( & V_7 -> V_158 , & V_181 ) ;
F_9 ( & V_22 ) ;
F_25 ( V_7 ) ;
F_115 ( & ( V_7 -> V_62 ) , F_46 ) ;
F_45 ( V_7 ) ;
return V_7 ;
V_173:
F_15 ( & V_171 , & V_153 , V_7 -> V_28 ) ;
F_107 ( & V_7 -> V_11 ) ;
return F_98 ( V_90 ) ;
}
void F_116 ( struct V_6 * V_7 )
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
F_11 ( & V_7 -> V_158 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_34 -> V_146 ) {
V_7 -> V_34 -> V_146 ( V_7 , V_43 ) ;
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
F_91 ( & V_7 -> V_11 , & V_172 ) ;
F_91 ( & V_7 -> V_11 , & V_174 ) ;
if ( V_7 -> V_34 -> V_91 )
F_91 ( & V_7 -> V_11 , & V_175 ) ;
F_91 ( & V_7 -> V_11 , & V_178 ) ;
F_91 ( & V_7 -> V_11 , & V_179 ) ;
F_111 ( V_7 ) ;
F_5 ( V_7 , NULL ) ;
F_117 ( V_7 ) ;
F_15 ( & V_171 , & V_153 , V_7 -> V_28 ) ;
F_118 ( & V_7 -> V_25 ) ;
F_119 ( & V_7 -> V_27 ) ;
F_107 ( & V_7 -> V_11 ) ;
return;
}
struct V_6 * F_120 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_182 = F_98 ( - V_16 ) ;
unsigned int V_183 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_183 ++ ;
V_182 = V_3 ;
}
F_9 ( & V_22 ) ;
if ( V_183 == 0 )
V_182 = F_98 ( - V_147 ) ;
else if ( V_183 > 1 )
V_182 = F_98 ( - V_141 ) ;
exit:
return V_182 ;
}
int F_121 ( struct V_6 * V_7 ,
enum V_184 V_185 )
{
struct V_186 * V_187 ;
struct V_188 * V_86 ;
struct V_189 * V_190 ;
void * V_191 ;
int V_107 ;
int V_90 ;
static unsigned int V_192 ;
if ( ! V_7 )
return - V_16 ;
V_107 = F_122 ( sizeof( struct V_189 ) ) +
F_122 ( 0 ) ;
V_187 = F_123 ( V_107 , V_193 ) ;
if ( ! V_187 )
return - V_129 ;
V_191 = F_124 ( V_187 , 0 , V_192 ++ ,
& V_194 , 0 ,
V_195 ) ;
if ( ! V_191 ) {
F_125 ( V_187 ) ;
return - V_129 ;
}
V_86 = F_126 ( V_187 , V_196 ,
sizeof( struct V_189 ) ) ;
if ( ! V_86 ) {
F_125 ( V_187 ) ;
return - V_16 ;
}
V_190 = F_127 ( V_86 ) ;
if ( ! V_190 ) {
F_125 ( V_187 ) ;
return - V_16 ;
}
memset ( V_190 , 0 , sizeof( struct V_189 ) ) ;
V_190 -> V_197 = V_7 -> V_28 ;
V_190 -> V_185 = V_185 ;
F_128 ( V_187 , V_191 ) ;
V_90 = F_129 ( & V_194 , V_187 , 0 ,
0 , V_193 ) ;
if ( V_90 )
F_4 ( & V_7 -> V_11 , L_36 , V_90 ) ;
return V_90 ;
}
static int F_130 ( void )
{
return F_131 ( & V_194 ) ;
}
static void F_132 ( void )
{
F_133 ( & V_194 ) ;
}
static inline int F_130 ( void ) { return 0 ; }
static inline void F_132 ( void ) {}
static int T_4 F_134 ( void )
{
int V_90 ;
V_90 = F_135 () ;
if ( V_90 )
return V_90 ;
V_90 = F_136 () ;
if ( V_90 )
return V_90 ;
V_90 = F_137 () ;
if ( V_90 )
return V_90 ;
V_90 = F_138 () ;
if ( V_90 )
return V_90 ;
return F_139 () ;
}
static void F_140 ( void )
{
F_141 () ;
F_142 () ;
F_143 () ;
F_144 () ;
F_145 () ;
}
static int T_4 F_146 ( void )
{
int V_90 ;
V_90 = F_134 () ;
if ( V_90 )
goto error;
V_90 = F_147 ( & V_155 ) ;
if ( V_90 )
goto V_198;
V_90 = F_130 () ;
if ( V_90 )
goto V_199;
V_90 = F_148 () ;
if ( V_90 )
goto V_200;
return 0 ;
V_200:
F_132 () ;
V_199:
F_149 ( & V_155 ) ;
V_198:
F_140 () ;
error:
F_118 ( & V_171 ) ;
F_118 ( & V_152 ) ;
F_119 ( & V_153 ) ;
F_119 ( & V_22 ) ;
F_119 ( & V_17 ) ;
return V_90 ;
}
static void T_5 F_150 ( void )
{
F_151 () ;
F_132 () ;
F_149 ( & V_155 ) ;
F_140 () ;
F_118 ( & V_171 ) ;
F_118 ( & V_152 ) ;
F_119 ( & V_153 ) ;
F_119 ( & V_22 ) ;
F_119 ( & V_17 ) ;
}
