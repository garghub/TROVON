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
int F_3 ( struct V_1 * V_6 )
{
int V_7 ;
const char * V_2 ;
struct V_8 * V_3 ;
if ( ! V_6 )
return - V_9 ;
F_4 ( & V_10 ) ;
V_7 = - V_11 ;
if ( F_1 ( V_6 -> V_2 ) == NULL ) {
V_7 = 0 ;
F_5 ( & V_6 -> V_12 , & V_13 ) ;
if ( ! V_4 && ! strncmp ( V_6 -> V_2 ,
V_14 , V_5 ) )
V_4 = V_6 ;
}
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( V_3 -> V_6 )
continue;
V_2 = V_3 -> V_16 -> V_17 ;
if ( ! strncasecmp ( V_2 , V_6 -> V_2 , V_5 ) )
V_3 -> V_6 = V_6 ;
}
F_6 ( & V_15 ) ;
F_6 ( & V_10 ) ;
return V_7 ;
}
void F_7 ( struct V_1 * V_6 )
{
struct V_8 * V_3 ;
if ( ! V_6 )
return;
F_4 ( & V_10 ) ;
if ( F_1 ( V_6 -> V_2 ) == NULL )
goto exit;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! strncasecmp ( V_3 -> V_6 -> V_2 , V_6 -> V_2 ,
V_5 ) )
V_3 -> V_6 = NULL ;
}
F_6 ( & V_15 ) ;
F_8 ( & V_6 -> V_12 ) ;
exit:
F_6 ( & V_10 ) ;
return;
}
static int F_9 ( struct V_18 * V_18 , struct V_19 * V_20 , int * V_21 )
{
int V_22 ;
if ( V_20 )
F_4 ( V_20 ) ;
V_22 = F_10 ( V_18 , NULL , 0 , 0 , V_23 ) ;
if ( V_20 )
F_6 ( V_20 ) ;
if ( F_11 ( V_22 < 0 ) )
return V_22 ;
* V_21 = V_22 ;
return 0 ;
}
static void F_12 ( struct V_18 * V_18 , struct V_19 * V_20 , int V_21 )
{
if ( V_20 )
F_4 ( V_20 ) ;
F_13 ( V_18 , V_21 ) ;
if ( V_20 )
F_6 ( V_20 ) ;
}
int F_14 ( struct V_8 * V_24 , int V_25 )
{
enum V_26 V_27 ;
if ( V_24 -> V_28 || ! V_24 -> V_29 -> V_30 ||
V_24 -> V_29 -> V_30 ( V_24 , V_25 , & V_27 ) ) {
if ( V_24 -> V_31 > V_24 -> V_32 )
V_27 = V_33 ;
else if ( V_24 -> V_31 < V_24 -> V_32 )
V_27 = V_34 ;
else
V_27 = V_35 ;
}
return V_27 ;
}
struct V_36 * F_15 ( struct V_8 * V_24 ,
struct V_37 * V_38 , int V_25 )
{
struct V_36 * V_3 = NULL ;
struct V_36 * V_39 = NULL ;
F_4 ( & V_24 -> V_20 ) ;
F_4 ( & V_38 -> V_20 ) ;
F_2 (pos, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_24 == V_24 && V_3 -> V_25 == V_25 && V_3 -> V_38 == V_38 ) {
V_39 = V_3 ;
break;
}
}
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
return V_39 ;
}
static void F_16 ( struct V_8 * V_24 ,
struct V_37 * V_38 , int V_22 )
{
F_17 ( & V_24 -> V_40 , L_1 ,
V_24 -> type , V_38 -> type , V_22 ) ;
}
static void F_18 ( struct V_8 * V_24 , int V_41 ,
struct V_37 * V_38 ,
unsigned long * V_42 )
{
int V_43 , V_22 ;
for ( V_43 = 0 ; V_43 < V_24 -> V_44 ; V_43 ++ ) {
if ( V_41 & ( 1 << V_43 ) ) {
unsigned long V_45 , V_46 ;
V_45 = V_47 ;
V_46 = V_47 ;
if ( V_42 ) {
V_46 = V_42 [ V_43 * 2 ] ;
V_45 = V_42 [ V_43 * 2 + 1 ] ;
}
V_22 = F_19 ( V_24 , V_43 , V_38 ,
V_45 , V_46 ) ;
if ( V_22 )
F_16 ( V_24 , V_38 , V_22 ) ;
}
}
}
static void F_20 ( struct V_8 * V_24 , int V_41 ,
struct V_37 * V_38 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_24 -> V_44 ; V_43 ++ )
if ( V_41 & ( 1 << V_43 ) )
F_21 ( V_24 , V_43 , V_38 ) ;
}
static void F_22 ( struct V_37 * V_38 )
{
int V_43 , V_22 ;
const struct V_48 * V_16 ;
struct V_8 * V_3 = NULL ;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_16 && ! V_3 -> V_29 -> V_49 )
continue;
if ( V_3 -> V_29 -> V_49 ) {
V_22 = V_3 -> V_29 -> V_49 ( V_3 , V_38 ) ;
if ( V_22 )
F_16 ( V_3 , V_38 , V_22 ) ;
continue;
}
V_16 = V_3 -> V_16 ;
if ( ! V_16 || ! V_16 -> V_50 )
continue;
for ( V_43 = 0 ; V_43 < V_16 -> V_51 ; V_43 ++ ) {
if ( V_16 -> V_50 [ V_43 ] . V_38 || ! V_16 -> V_50 [ V_43 ] . V_52 )
continue;
if ( V_16 -> V_50 [ V_43 ] . V_52 ( V_3 , V_38 ) )
continue;
V_16 -> V_50 [ V_43 ] . V_38 = V_38 ;
F_18 ( V_3 , V_16 -> V_50 [ V_43 ] . V_53 , V_38 ,
V_16 -> V_50 [ V_43 ] . V_54 ) ;
}
}
F_6 ( & V_15 ) ;
}
static void F_23 ( struct V_8 * V_24 )
{
int V_43 , V_22 ;
struct V_37 * V_3 = NULL ;
const struct V_48 * V_16 = V_24 -> V_16 ;
if ( ! V_16 && ! V_24 -> V_29 -> V_49 )
return;
F_4 ( & V_15 ) ;
if ( V_24 -> V_29 -> V_49 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_22 = V_24 -> V_29 -> V_49 ( V_24 , V_3 ) ;
if ( V_22 )
F_16 ( V_24 , V_3 , V_22 ) ;
}
goto exit;
}
if ( ! V_16 || ! V_16 -> V_50 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_43 = 0 ; V_43 < V_16 -> V_51 ; V_43 ++ ) {
if ( V_16 -> V_50 [ V_43 ] . V_38 || ! V_16 -> V_50 [ V_43 ] . V_52 )
continue;
if ( V_16 -> V_50 [ V_43 ] . V_52 ( V_24 , V_3 ) )
continue;
V_16 -> V_50 [ V_43 ] . V_38 = V_3 ;
F_18 ( V_24 , V_16 -> V_50 [ V_43 ] . V_53 , V_3 ,
V_16 -> V_50 [ V_43 ] . V_54 ) ;
}
}
exit:
F_6 ( & V_15 ) ;
}
static void F_24 ( struct V_8 * V_24 ,
int V_55 )
{
if ( V_55 > 1000 )
F_25 ( V_56 , & V_24 -> V_57 ,
F_26 ( F_27 ( V_55 ) ) ) ;
else if ( V_55 )
F_25 ( V_56 , & V_24 -> V_57 ,
F_27 ( V_55 ) ) ;
else
F_28 ( & V_24 -> V_57 ) ;
}
static void F_29 ( struct V_8 * V_24 )
{
F_4 ( & V_24 -> V_20 ) ;
if ( V_24 -> V_58 )
F_24 ( V_24 , V_24 -> V_59 ) ;
else if ( V_24 -> V_60 )
F_24 ( V_24 , V_24 -> V_60 ) ;
else
F_24 ( V_24 , 0 ) ;
F_6 ( & V_24 -> V_20 ) ;
}
static void F_30 ( struct V_8 * V_24 ,
int V_25 , enum V_61 V_62 )
{
V_24 -> V_6 ? V_24 -> V_6 -> V_63 ( V_24 , V_25 ) :
V_4 -> V_63 ( V_24 , V_25 ) ;
}
static void F_31 ( struct V_8 * V_24 ,
int V_25 , enum V_61 V_62 )
{
long V_64 ;
V_24 -> V_29 -> V_65 ( V_24 , V_25 , & V_64 ) ;
if ( V_64 <= 0 || V_24 -> V_31 < V_64 )
return;
F_32 ( V_24 , V_25 , V_62 ) ;
if ( V_24 -> V_29 -> V_66 )
V_24 -> V_29 -> V_66 ( V_24 , V_25 , V_62 ) ;
if ( V_62 == V_67 ) {
F_33 ( & V_24 -> V_40 ,
L_2 ,
V_24 -> V_31 / 1000 ) ;
F_34 ( true ) ;
}
}
static void F_35 ( struct V_8 * V_24 , int V_25 )
{
enum V_61 type ;
V_24 -> V_29 -> V_68 ( V_24 , V_25 , & type ) ;
if ( type == V_67 || type == V_69 )
F_31 ( V_24 , V_25 , type ) ;
else
F_30 ( V_24 , V_25 , type ) ;
F_29 ( V_24 ) ;
}
int F_36 ( struct V_8 * V_24 , unsigned long * V_70 )
{
int V_22 = - V_9 ;
#ifdef F_37
int V_71 ;
unsigned long V_72 = - 1UL ;
enum V_61 type ;
#endif
if ( ! V_24 || F_38 ( V_24 ) || ! V_24 -> V_29 -> V_73 )
goto exit;
F_4 ( & V_24 -> V_20 ) ;
V_22 = V_24 -> V_29 -> V_73 ( V_24 , V_70 ) ;
#ifdef F_37
if ( ! V_24 -> V_28 )
goto V_74;
for ( V_71 = 0 ; V_71 < V_24 -> V_44 ; V_71 ++ ) {
V_22 = V_24 -> V_29 -> V_68 ( V_24 , V_71 , & type ) ;
if ( ! V_22 && type == V_67 ) {
V_22 = V_24 -> V_29 -> V_65 ( V_24 , V_71 , & V_72 ) ;
break;
}
}
if ( V_22 )
goto V_74;
if ( * V_70 < V_72 )
* V_70 = V_24 -> V_28 ;
V_74:
#endif
F_6 ( & V_24 -> V_20 ) ;
exit:
return V_22 ;
}
static void F_39 ( struct V_8 * V_24 )
{
long V_70 ;
int V_22 ;
V_22 = F_36 ( V_24 , & V_70 ) ;
if ( V_22 ) {
if ( V_22 != - V_75 )
F_40 ( & V_24 -> V_40 ,
L_3 ,
V_22 ) ;
return;
}
F_4 ( & V_24 -> V_20 ) ;
V_24 -> V_32 = V_24 -> V_31 ;
V_24 -> V_31 = V_70 ;
F_6 ( & V_24 -> V_20 ) ;
F_41 ( V_24 ) ;
F_42 ( & V_24 -> V_40 , L_4 ,
V_24 -> V_32 , V_24 -> V_31 ) ;
}
void F_43 ( struct V_8 * V_24 )
{
int V_71 ;
if ( ! V_24 -> V_29 -> V_73 )
return;
F_39 ( V_24 ) ;
for ( V_71 = 0 ; V_71 < V_24 -> V_44 ; V_71 ++ )
F_35 ( V_24 , V_71 ) ;
}
static void F_44 ( struct V_76 * V_77 )
{
struct V_8 * V_24 = F_45 ( V_77 , struct
V_8 ,
V_57 . V_77 ) ;
F_43 ( V_24 ) ;
}
static T_1
F_46 ( struct V_40 * V_78 , struct V_79 * V_80 , char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
return sprintf ( V_81 , L_5 , V_24 -> type ) ;
}
static T_1
F_48 ( struct V_40 * V_78 , struct V_79 * V_80 , char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
long V_31 ;
int V_22 ;
V_22 = F_36 ( V_24 , & V_31 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_81 , L_6 , V_31 ) ;
}
static T_1
F_49 ( struct V_40 * V_78 , struct V_79 * V_80 , char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
enum V_82 V_83 ;
int V_84 ;
if ( ! V_24 -> V_29 -> V_85 )
return - V_86 ;
V_84 = V_24 -> V_29 -> V_85 ( V_24 , & V_83 ) ;
if ( V_84 )
return V_84 ;
return sprintf ( V_81 , L_5 , V_83 == V_87 ? L_7
: L_8 ) ;
}
static T_1
F_50 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_84 ;
if ( ! V_24 -> V_29 -> V_88 )
return - V_86 ;
if ( ! strncmp ( V_81 , L_7 , sizeof( L_7 ) - 1 ) )
V_84 = V_24 -> V_29 -> V_88 ( V_24 , V_87 ) ;
else if ( ! strncmp ( V_81 , L_8 , sizeof( L_8 ) - 1 ) )
V_84 = V_24 -> V_29 -> V_88 ( V_24 , V_89 ) ;
else
V_84 = - V_9 ;
if ( V_84 )
return V_84 ;
return V_71 ;
}
static T_1
F_51 ( struct V_40 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
enum V_61 type ;
int V_25 , V_84 ;
if ( ! V_24 -> V_29 -> V_68 )
return - V_86 ;
if ( ! sscanf ( V_80 -> V_80 . V_2 , L_9 , & V_25 ) )
return - V_9 ;
V_84 = V_24 -> V_29 -> V_68 ( V_24 , V_25 , & type ) ;
if ( V_84 )
return V_84 ;
switch ( type ) {
case V_67 :
return sprintf ( V_81 , L_10 ) ;
case V_69 :
return sprintf ( V_81 , L_11 ) ;
case V_90 :
return sprintf ( V_81 , L_12 ) ;
case V_91 :
return sprintf ( V_81 , L_13 ) ;
default:
return sprintf ( V_81 , L_14 ) ;
}
}
static T_1
F_52 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_92 )
return - V_86 ;
if ( ! sscanf ( V_80 -> V_80 . V_2 , L_15 , & V_25 ) )
return - V_9 ;
if ( F_53 ( V_81 , 10 , & V_31 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_92 ( V_24 , V_25 , V_31 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_54 ( struct V_40 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_25 , V_22 ;
long V_31 ;
if ( ! V_24 -> V_29 -> V_65 )
return - V_86 ;
if ( ! sscanf ( V_80 -> V_80 . V_2 , L_15 , & V_25 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_65 ( V_24 , V_25 , & V_31 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_81 , L_6 , V_31 ) ;
}
static T_1
F_55 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_93 )
return - V_86 ;
if ( ! sscanf ( V_80 -> V_80 . V_2 , L_16 , & V_25 ) )
return - V_9 ;
if ( F_53 ( V_81 , 10 , & V_31 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_93 ( V_24 , V_25 , V_31 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_56 ( struct V_40 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_94 )
return - V_86 ;
if ( ! sscanf ( V_80 -> V_80 . V_2 , L_16 , & V_25 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_94 ( V_24 , V_25 , & V_31 ) ;
return V_22 ? V_22 : sprintf ( V_81 , L_6 , V_31 ) ;
}
static T_1
F_57 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
struct V_37 * V_38 = NULL ;
int V_95 ;
if ( ! sscanf ( V_81 , L_17 , & V_95 ) )
return - V_9 ;
if ( V_95 && V_95 < 1000 )
return - V_9 ;
if ( V_95 && ! V_24 -> V_96 ) {
F_4 ( & V_15 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_18 , V_38 -> type ,
sizeof( L_18 ) ) )
F_19 ( V_24 ,
V_97 , V_38 ,
V_47 ,
V_47 ) ;
}
F_6 ( & V_15 ) ;
if ( ! V_24 -> V_59 )
V_24 -> V_59 = 1000 ;
} else if ( ! V_95 && V_24 -> V_96 ) {
F_4 ( & V_15 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_18 , V_38 -> type ,
sizeof( L_18 ) ) )
F_21 ( V_24 ,
V_97 ,
V_38 ) ;
}
F_6 ( & V_15 ) ;
V_24 -> V_59 = 0 ;
}
V_24 -> V_96 = V_95 ;
F_43 ( V_24 ) ;
return V_71 ;
}
static T_1
F_58 ( struct V_40 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
return sprintf ( V_81 , L_17 , V_24 -> V_96 ) ;
}
static T_1
F_59 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
int V_22 = - V_9 ;
struct V_8 * V_24 = F_47 ( V_78 ) ;
struct V_1 * V_98 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_19 , V_81 ) ;
F_4 ( & V_10 ) ;
F_4 ( & V_24 -> V_20 ) ;
V_98 = F_1 ( F_60 ( V_2 ) ) ;
if ( ! V_98 )
goto exit;
V_24 -> V_6 = V_98 ;
V_22 = V_71 ;
exit:
F_6 ( & V_24 -> V_20 ) ;
F_6 ( & V_10 ) ;
return V_22 ;
}
static T_1
F_61 ( struct V_40 * V_78 , struct V_79 * V_99 , char * V_81 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
return sprintf ( V_81 , L_5 , V_24 -> V_6 -> V_2 ) ;
}
static T_1
F_62 ( struct V_40 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_78 ) ;
int V_22 = 0 ;
unsigned long V_31 ;
if ( F_53 ( V_81 , 10 , & V_31 ) )
return - V_9 ;
if ( ! V_24 -> V_29 -> V_100 ) {
F_4 ( & V_24 -> V_20 ) ;
V_24 -> V_28 = V_31 ;
F_6 ( & V_24 -> V_20 ) ;
} else {
V_22 = V_24 -> V_29 -> V_100 ( V_24 , V_31 ) ;
}
if ( ! V_22 )
F_43 ( V_24 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_63 ( struct V_40 * V_78 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_37 * V_38 = F_64 ( V_78 ) ;
return sprintf ( V_81 , L_5 , V_38 -> type ) ;
}
static T_1
F_65 ( struct V_40 * V_78 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_37 * V_38 = F_64 ( V_78 ) ;
unsigned long V_95 ;
int V_22 ;
V_22 = V_38 -> V_29 -> V_101 ( V_38 , & V_95 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_81 , L_6 , V_95 ) ;
}
static T_1
F_66 ( struct V_40 * V_78 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_37 * V_38 = F_64 ( V_78 ) ;
unsigned long V_95 ;
int V_22 ;
V_22 = V_38 -> V_29 -> V_102 ( V_38 , & V_95 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_81 , L_6 , V_95 ) ;
}
static T_1
F_67 ( struct V_40 * V_78 ,
struct V_79 * V_80 ,
const char * V_81 , T_2 V_71 )
{
struct V_37 * V_38 = F_64 ( V_78 ) ;
unsigned long V_95 ;
int V_84 ;
if ( ! sscanf ( V_81 , L_6 , & V_95 ) )
return - V_9 ;
if ( ( long ) V_95 < 0 )
return - V_9 ;
V_84 = V_38 -> V_29 -> V_103 ( V_38 , V_95 ) ;
if ( V_84 )
return V_84 ;
return V_71 ;
}
static T_1
F_68 ( struct V_40 * V_78 ,
struct V_79 * V_80 , char * V_81 )
{
struct V_36 * V_104 ;
V_104 =
F_45 ( V_80 , struct V_36 , V_80 ) ;
if ( V_104 -> V_25 == V_97 )
return sprintf ( V_81 , L_20 ) ;
else
return sprintf ( V_81 , L_17 , V_104 -> V_25 ) ;
}
int F_19 ( struct V_8 * V_24 ,
int V_25 ,
struct V_37 * V_38 ,
unsigned long V_45 , unsigned long V_46 )
{
struct V_36 * V_78 ;
struct V_36 * V_3 ;
struct V_8 * V_105 ;
struct V_37 * V_106 ;
unsigned long V_107 ;
int V_84 , V_22 ;
if ( V_25 >= V_24 -> V_44 || ( V_25 < 0 && V_25 != V_97 ) )
return - V_9 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_105 == V_24 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_106 == V_38 )
break;
}
if ( V_24 != V_105 || V_38 != V_106 )
return - V_9 ;
V_22 = V_38 -> V_29 -> V_101 ( V_38 , & V_107 ) ;
if ( V_22 )
return V_22 ;
V_46 = V_46 == V_47 ? 0 : V_46 ;
V_45 = V_45 == V_47 ? V_107 : V_45 ;
if ( V_46 > V_45 || V_45 > V_107 )
return - V_9 ;
V_78 =
F_69 ( sizeof( struct V_36 ) , V_23 ) ;
if ( ! V_78 )
return - V_108 ;
V_78 -> V_24 = V_24 ;
V_78 -> V_38 = V_38 ;
V_78 -> V_25 = V_25 ;
V_78 -> V_45 = V_45 ;
V_78 -> V_46 = V_46 ;
V_78 -> V_109 = V_110 ;
V_84 = F_9 ( & V_24 -> V_18 , & V_24 -> V_20 , & V_78 -> V_21 ) ;
if ( V_84 )
goto V_111;
sprintf ( V_78 -> V_2 , L_21 , V_78 -> V_21 ) ;
V_84 =
F_70 ( & V_24 -> V_40 . V_112 , & V_38 -> V_40 . V_112 , V_78 -> V_2 ) ;
if ( V_84 )
goto F_12;
sprintf ( V_78 -> V_113 , L_22 , V_78 -> V_21 ) ;
F_71 ( & V_78 -> V_80 . V_80 ) ;
V_78 -> V_80 . V_80 . V_2 = V_78 -> V_113 ;
V_78 -> V_80 . V_80 . V_83 = 0444 ;
V_78 -> V_80 . V_114 = F_68 ;
V_84 = F_72 ( & V_24 -> V_40 , & V_78 -> V_80 ) ;
if ( V_84 )
goto V_115;
F_4 ( & V_24 -> V_20 ) ;
F_4 ( & V_38 -> V_20 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_24 == V_24 && V_3 -> V_25 == V_25 && V_3 -> V_38 == V_38 ) {
V_84 = - V_116 ;
break;
}
if ( ! V_84 ) {
F_73 ( & V_78 -> V_117 , & V_24 -> V_118 ) ;
F_73 ( & V_78 -> V_119 , & V_38 -> V_118 ) ;
}
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
if ( ! V_84 )
return 0 ;
F_74 ( & V_24 -> V_40 , & V_78 -> V_80 ) ;
V_115:
F_75 ( & V_24 -> V_40 . V_112 , V_78 -> V_2 ) ;
F_12:
F_12 ( & V_24 -> V_18 , & V_24 -> V_20 , V_78 -> V_21 ) ;
V_111:
F_76 ( V_78 ) ;
return V_84 ;
}
int F_21 ( struct V_8 * V_24 ,
int V_25 ,
struct V_37 * V_38 )
{
struct V_36 * V_3 , * V_120 ;
F_4 ( & V_24 -> V_20 ) ;
F_4 ( & V_38 -> V_20 ) ;
F_77 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_24 == V_24 && V_3 -> V_25 == V_25 && V_3 -> V_38 == V_38 ) {
F_8 ( & V_3 -> V_117 ) ;
F_8 ( & V_3 -> V_119 ) ;
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
goto V_121;
}
}
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
return - V_122 ;
V_121:
F_74 ( & V_24 -> V_40 , & V_3 -> V_80 ) ;
F_75 ( & V_24 -> V_40 . V_112 , V_3 -> V_2 ) ;
F_12 ( & V_24 -> V_18 , & V_24 -> V_20 , V_3 -> V_21 ) ;
F_76 ( V_3 ) ;
return 0 ;
}
static void F_78 ( struct V_40 * V_78 )
{
struct V_8 * V_24 ;
struct V_37 * V_38 ;
if ( ! strncmp ( F_79 ( V_78 ) , L_23 ,
sizeof( L_23 ) - 1 ) ) {
V_24 = F_47 ( V_78 ) ;
F_76 ( V_24 ) ;
} else if( ! strncmp ( F_79 ( V_78 ) , L_24 ,
sizeof( L_24 ) - 1 ) ) {
V_38 = F_64 ( V_78 ) ;
F_76 ( V_38 ) ;
}
}
static struct V_37 *
F_80 ( struct V_123 * V_124 ,
char * type , void * V_125 ,
const struct V_126 * V_29 )
{
struct V_37 * V_38 ;
int V_84 ;
if ( type && strlen ( type ) >= V_5 )
return F_81 ( - V_9 ) ;
if ( ! V_29 || ! V_29 -> V_101 || ! V_29 -> V_102 ||
! V_29 -> V_103 )
return F_81 ( - V_9 ) ;
V_38 = F_69 ( sizeof( struct V_37 ) , V_23 ) ;
if ( ! V_38 )
return F_81 ( - V_108 ) ;
V_84 = F_9 ( & V_127 , & V_128 , & V_38 -> V_21 ) ;
if ( V_84 ) {
F_76 ( V_38 ) ;
return F_81 ( V_84 ) ;
}
F_82 ( V_38 -> type , type ? : L_25 , sizeof( V_38 -> type ) ) ;
F_83 ( & V_38 -> V_20 ) ;
F_84 ( & V_38 -> V_118 ) ;
V_38 -> V_124 = V_124 ;
V_38 -> V_29 = V_29 ;
V_38 -> V_129 = false ;
V_38 -> V_40 . V_130 = & V_131 ;
V_38 -> V_40 . V_132 = V_133 ;
V_38 -> V_125 = V_125 ;
F_85 ( & V_38 -> V_40 , L_26 , V_38 -> V_21 ) ;
V_84 = F_86 ( & V_38 -> V_40 ) ;
if ( V_84 ) {
F_12 ( & V_127 , & V_128 , V_38 -> V_21 ) ;
F_76 ( V_38 ) ;
return F_81 ( V_84 ) ;
}
F_4 ( & V_15 ) ;
F_5 ( & V_38 -> V_134 , & V_135 ) ;
F_6 ( & V_15 ) ;
F_22 ( V_38 ) ;
return V_38 ;
}
struct V_37 *
F_87 ( char * type , void * V_125 ,
const struct V_126 * V_29 )
{
return F_80 ( NULL , type , V_125 , V_29 ) ;
}
struct V_37 *
F_88 ( struct V_123 * V_124 ,
char * type , void * V_125 ,
const struct V_126 * V_29 )
{
return F_80 ( V_124 , type , V_125 , V_29 ) ;
}
void F_89 ( struct V_37 * V_38 )
{
int V_43 ;
const struct V_48 * V_16 ;
struct V_8 * V_24 ;
struct V_37 * V_3 = NULL ;
if ( ! V_38 )
return;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_38 )
break;
if ( V_3 != V_38 ) {
F_6 ( & V_15 ) ;
return;
}
F_8 ( & V_38 -> V_134 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_24 -> V_29 -> V_121 ) {
V_24 -> V_29 -> V_121 ( V_24 , V_38 ) ;
continue;
}
if ( ! V_24 -> V_16 || ! V_24 -> V_16 -> V_50 )
continue;
V_16 = V_24 -> V_16 ;
for ( V_43 = 0 ; V_43 < V_16 -> V_51 ; V_43 ++ ) {
if ( V_16 -> V_50 [ V_43 ] . V_38 == V_38 ) {
F_20 ( V_24 , V_16 -> V_50 [ V_43 ] . V_53 , V_38 ) ;
V_16 -> V_50 [ V_43 ] . V_38 = NULL ;
}
}
}
F_6 ( & V_15 ) ;
if ( V_38 -> type [ 0 ] )
F_74 ( & V_38 -> V_40 , & V_136 ) ;
F_74 ( & V_38 -> V_40 , & V_137 ) ;
F_74 ( & V_38 -> V_40 , & V_138 ) ;
F_12 ( & V_127 , & V_128 , V_38 -> V_21 ) ;
F_90 ( & V_38 -> V_40 ) ;
return;
}
void F_91 ( struct V_37 * V_38 )
{
struct V_36 * V_104 ;
unsigned long V_109 = 0 ;
if ( V_38 -> V_129 )
return;
F_4 ( & V_38 -> V_20 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_42 ( & V_38 -> V_40 , L_27 ,
V_104 -> V_24 -> V_21 , V_104 -> V_109 ) ;
if ( V_104 -> V_109 == V_110 )
continue;
if ( V_104 -> V_109 > V_109 )
V_109 = V_104 -> V_109 ;
}
F_6 ( & V_38 -> V_20 ) ;
V_38 -> V_29 -> V_103 ( V_38 , V_109 ) ;
V_38 -> V_129 = true ;
F_92 ( V_38 , V_109 ) ;
F_42 ( & V_38 -> V_40 , L_28 , V_109 ) ;
}
void F_93 ( struct V_8 * V_24 , int V_25 )
{
F_35 ( V_24 , V_25 ) ;
}
static int F_94 ( struct V_8 * V_24 , int V_41 )
{
int V_139 ;
int V_140 = sizeof( struct V_141 ) * V_24 -> V_44 ;
V_24 -> V_142 = F_69 ( V_140 , V_23 ) ;
if ( ! V_24 -> V_142 )
return - V_108 ;
V_24 -> V_143 = F_69 ( V_140 , V_23 ) ;
if ( ! V_24 -> V_143 ) {
F_76 ( V_24 -> V_142 ) ;
return - V_108 ;
}
if ( V_24 -> V_29 -> V_94 ) {
V_24 -> V_144 = F_69 ( V_140 , V_23 ) ;
if ( ! V_24 -> V_144 ) {
F_76 ( V_24 -> V_142 ) ;
F_76 ( V_24 -> V_143 ) ;
return - V_108 ;
}
}
for ( V_139 = 0 ; V_139 < V_24 -> V_44 ; V_139 ++ ) {
snprintf ( V_24 -> V_142 [ V_139 ] . V_2 , V_5 ,
L_9 , V_139 ) ;
F_71 ( & V_24 -> V_142 [ V_139 ] . V_80 . V_80 ) ;
V_24 -> V_142 [ V_139 ] . V_80 . V_80 . V_2 =
V_24 -> V_142 [ V_139 ] . V_2 ;
V_24 -> V_142 [ V_139 ] . V_80 . V_80 . V_83 = V_145 ;
V_24 -> V_142 [ V_139 ] . V_80 . V_114 = F_51 ;
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_142 [ V_139 ] . V_80 ) ;
snprintf ( V_24 -> V_143 [ V_139 ] . V_2 , V_5 ,
L_15 , V_139 ) ;
F_71 ( & V_24 -> V_143 [ V_139 ] . V_80 . V_80 ) ;
V_24 -> V_143 [ V_139 ] . V_80 . V_80 . V_2 =
V_24 -> V_143 [ V_139 ] . V_2 ;
V_24 -> V_143 [ V_139 ] . V_80 . V_80 . V_83 = V_145 ;
V_24 -> V_143 [ V_139 ] . V_80 . V_114 = F_54 ;
if ( V_41 & ( 1 << V_139 ) ) {
V_24 -> V_143 [ V_139 ] . V_80 . V_80 . V_83 |= V_146 ;
V_24 -> V_143 [ V_139 ] . V_80 . V_147 =
F_52 ;
}
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_143 [ V_139 ] . V_80 ) ;
if ( ! V_24 -> V_29 -> V_94 )
continue;
snprintf ( V_24 -> V_144 [ V_139 ] . V_2 , V_5 ,
L_16 , V_139 ) ;
F_71 ( & V_24 -> V_144 [ V_139 ] . V_80 . V_80 ) ;
V_24 -> V_144 [ V_139 ] . V_80 . V_80 . V_2 =
V_24 -> V_144 [ V_139 ] . V_2 ;
V_24 -> V_144 [ V_139 ] . V_80 . V_80 . V_83 = V_145 ;
V_24 -> V_144 [ V_139 ] . V_80 . V_114 = F_56 ;
if ( V_24 -> V_29 -> V_93 ) {
V_24 -> V_144 [ V_139 ] . V_80 . V_80 . V_83 |= V_146 ;
V_24 -> V_144 [ V_139 ] . V_80 . V_147 =
F_55 ;
}
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_144 [ V_139 ] . V_80 ) ;
}
return 0 ;
}
static void F_95 ( struct V_8 * V_24 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_24 -> V_44 ; V_139 ++ ) {
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_142 [ V_139 ] . V_80 ) ;
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_143 [ V_139 ] . V_80 ) ;
if ( V_24 -> V_29 -> V_94 )
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_144 [ V_139 ] . V_80 ) ;
}
F_76 ( V_24 -> V_142 ) ;
F_76 ( V_24 -> V_143 ) ;
F_76 ( V_24 -> V_144 ) ;
}
struct V_8 * F_96 ( const char * type ,
int V_44 , int V_41 , void * V_125 ,
struct V_148 * V_29 ,
const struct V_48 * V_16 ,
int V_59 , int V_60 )
{
struct V_8 * V_24 ;
enum V_61 V_62 ;
int V_84 ;
int V_71 ;
int V_58 = 0 ;
if ( type && strlen ( type ) >= V_5 )
return F_81 ( - V_9 ) ;
if ( V_44 > V_149 || V_44 < 0 || V_41 > > V_44 )
return F_81 ( - V_9 ) ;
if ( ! V_29 )
return F_81 ( - V_9 ) ;
if ( V_44 > 0 && ( ! V_29 -> V_68 || ! V_29 -> V_65 ) )
return F_81 ( - V_9 ) ;
V_24 = F_69 ( sizeof( struct V_8 ) , V_23 ) ;
if ( ! V_24 )
return F_81 ( - V_108 ) ;
F_84 ( & V_24 -> V_118 ) ;
F_97 ( & V_24 -> V_18 ) ;
F_83 ( & V_24 -> V_20 ) ;
V_84 = F_9 ( & V_150 , & V_128 , & V_24 -> V_21 ) ;
if ( V_84 ) {
F_76 ( V_24 ) ;
return F_81 ( V_84 ) ;
}
F_82 ( V_24 -> type , type ? : L_25 , sizeof( V_24 -> type ) ) ;
V_24 -> V_29 = V_29 ;
V_24 -> V_16 = V_16 ;
V_24 -> V_40 . V_130 = & V_131 ;
V_24 -> V_125 = V_125 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_59 = V_59 ;
V_24 -> V_60 = V_60 ;
F_85 ( & V_24 -> V_40 , L_29 , V_24 -> V_21 ) ;
V_84 = F_86 ( & V_24 -> V_40 ) ;
if ( V_84 ) {
F_12 ( & V_150 , & V_128 , V_24 -> V_21 ) ;
F_76 ( V_24 ) ;
return F_81 ( V_84 ) ;
}
if ( type ) {
V_84 = F_72 ( & V_24 -> V_40 , & V_151 ) ;
if ( V_84 )
goto V_152;
}
V_84 = F_72 ( & V_24 -> V_40 , & V_153 ) ;
if ( V_84 )
goto V_152;
if ( V_29 -> V_85 ) {
V_84 = F_72 ( & V_24 -> V_40 , & V_154 ) ;
if ( V_84 )
goto V_152;
}
V_84 = F_94 ( V_24 , V_41 ) ;
if ( V_84 )
goto V_152;
for ( V_71 = 0 ; V_71 < V_44 ; V_71 ++ ) {
V_24 -> V_29 -> V_68 ( V_24 , V_71 , & V_62 ) ;
if ( V_62 == V_90 )
V_58 = 1 ;
}
if ( ! V_58 ) {
V_84 = F_72 ( & V_24 -> V_40 , & V_155 ) ;
if ( V_84 )
goto V_152;
}
#ifdef F_37
V_84 = F_72 ( & V_24 -> V_40 , & V_156 ) ;
if ( V_84 )
goto V_152;
#endif
V_84 = F_72 ( & V_24 -> V_40 , & V_157 ) ;
if ( V_84 )
goto V_152;
F_4 ( & V_10 ) ;
if ( V_24 -> V_16 )
V_24 -> V_6 = F_1 ( V_24 -> V_16 -> V_17 ) ;
else
V_24 -> V_6 = V_4 ;
F_6 ( & V_10 ) ;
if ( ! V_24 -> V_16 || ! V_24 -> V_16 -> V_158 ) {
V_84 = F_98 ( V_24 ) ;
if ( V_84 )
goto V_152;
}
F_4 ( & V_15 ) ;
F_73 ( & V_24 -> V_134 , & V_159 ) ;
F_6 ( & V_15 ) ;
F_23 ( V_24 ) ;
F_99 ( & ( V_24 -> V_57 ) , F_44 ) ;
if ( ! V_24 -> V_29 -> V_73 )
F_24 ( V_24 , 0 ) ;
F_43 ( V_24 ) ;
return V_24 ;
V_152:
F_12 ( & V_150 , & V_128 , V_24 -> V_21 ) ;
F_90 ( & V_24 -> V_40 ) ;
return F_81 ( V_84 ) ;
}
void F_100 ( struct V_8 * V_24 )
{
int V_43 ;
const struct V_48 * V_16 ;
struct V_37 * V_38 ;
struct V_8 * V_3 = NULL ;
if ( ! V_24 )
return;
V_16 = V_24 -> V_16 ;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( V_3 == V_24 )
break;
if ( V_3 != V_24 ) {
F_6 ( & V_15 ) ;
return;
}
F_8 ( & V_24 -> V_134 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_24 -> V_29 -> V_121 ) {
V_24 -> V_29 -> V_121 ( V_24 , V_38 ) ;
continue;
}
if ( ! V_16 || ! V_16 -> V_50 )
break;
for ( V_43 = 0 ; V_43 < V_16 -> V_51 ; V_43 ++ ) {
if ( V_16 -> V_50 [ V_43 ] . V_38 == V_38 ) {
F_20 ( V_24 , V_16 -> V_50 [ V_43 ] . V_53 , V_38 ) ;
V_16 -> V_50 [ V_43 ] . V_38 = NULL ;
}
}
}
F_6 ( & V_15 ) ;
F_24 ( V_24 , 0 ) ;
if ( V_24 -> type [ 0 ] )
F_74 ( & V_24 -> V_40 , & V_151 ) ;
F_74 ( & V_24 -> V_40 , & V_153 ) ;
if ( V_24 -> V_29 -> V_85 )
F_74 ( & V_24 -> V_40 , & V_154 ) ;
F_74 ( & V_24 -> V_40 , & V_157 ) ;
F_95 ( V_24 ) ;
V_24 -> V_6 = NULL ;
F_101 ( V_24 ) ;
F_12 ( & V_150 , & V_128 , V_24 -> V_21 ) ;
F_102 ( & V_24 -> V_18 ) ;
F_103 ( & V_24 -> V_20 ) ;
F_90 ( & V_24 -> V_40 ) ;
return;
}
struct V_8 * F_104 ( const char * V_2 )
{
struct V_8 * V_3 = NULL , * V_160 = F_81 ( - V_9 ) ;
unsigned int V_161 = 0 ;
if ( ! V_2 )
goto exit;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_161 ++ ;
V_160 = V_3 ;
}
F_6 ( & V_15 ) ;
if ( V_161 == 0 )
V_160 = F_81 ( - V_122 ) ;
else if ( V_161 > 1 )
V_160 = F_81 ( - V_116 ) ;
exit:
return V_160 ;
}
int F_105 ( struct V_8 * V_24 ,
enum V_162 V_163 )
{
struct V_164 * V_165 ;
struct V_166 * V_80 ;
struct V_167 * V_168 ;
void * V_169 ;
int V_140 ;
int V_84 ;
static unsigned int V_170 ;
if ( ! V_24 )
return - V_9 ;
V_140 = F_106 ( sizeof( struct V_167 ) ) +
F_106 ( 0 ) ;
V_165 = F_107 ( V_140 , V_171 ) ;
if ( ! V_165 )
return - V_108 ;
V_169 = F_108 ( V_165 , 0 , V_170 ++ ,
& V_172 , 0 ,
V_173 ) ;
if ( ! V_169 ) {
F_109 ( V_165 ) ;
return - V_108 ;
}
V_80 = F_110 ( V_165 , V_174 ,
sizeof( struct V_167 ) ) ;
if ( ! V_80 ) {
F_109 ( V_165 ) ;
return - V_9 ;
}
V_168 = F_111 ( V_80 ) ;
if ( ! V_168 ) {
F_109 ( V_165 ) ;
return - V_9 ;
}
memset ( V_168 , 0 , sizeof( struct V_167 ) ) ;
V_168 -> V_175 = V_24 -> V_21 ;
V_168 -> V_163 = V_163 ;
F_112 ( V_165 , V_169 ) ;
V_84 = F_113 ( & V_172 , V_165 , 0 ,
0 , V_171 ) ;
if ( V_84 )
F_17 ( & V_24 -> V_40 , L_30 , V_84 ) ;
return V_84 ;
}
static int F_114 ( void )
{
return F_115 ( & V_172 ) ;
}
static void F_116 ( void )
{
F_117 ( & V_172 ) ;
}
static inline int F_114 ( void ) { return 0 ; }
static inline void F_116 ( void ) {}
static int T_3 F_118 ( void )
{
int V_84 ;
V_84 = F_119 () ;
if ( V_84 )
return V_84 ;
V_84 = F_120 () ;
if ( V_84 )
return V_84 ;
V_84 = F_121 () ;
if ( V_84 )
return V_84 ;
return F_122 () ;
}
static void F_123 ( void )
{
F_124 () ;
F_125 () ;
F_126 () ;
F_127 () ;
}
static int T_3 F_128 ( void )
{
int V_84 ;
V_84 = F_118 () ;
if ( V_84 )
goto error;
V_84 = F_129 ( & V_131 ) ;
if ( V_84 )
goto V_176;
V_84 = F_114 () ;
if ( V_84 )
goto V_177;
V_84 = F_130 () ;
if ( V_84 )
goto V_178;
return 0 ;
V_178:
F_116 () ;
V_177:
F_131 ( & V_131 ) ;
V_176:
F_123 () ;
error:
F_102 ( & V_150 ) ;
F_102 ( & V_127 ) ;
F_103 ( & V_128 ) ;
F_103 ( & V_15 ) ;
F_103 ( & V_10 ) ;
return V_84 ;
}
static void T_4 F_132 ( void )
{
F_133 () ;
F_116 () ;
F_131 ( & V_131 ) ;
F_123 () ;
F_102 ( & V_150 ) ;
F_102 ( & V_127 ) ;
F_103 ( & V_128 ) ;
F_103 ( & V_15 ) ;
F_103 ( & V_10 ) ;
}
