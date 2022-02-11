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
if ( V_24 -> V_31 < V_64 )
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
F_40 ( & V_24 -> V_40 , L_3 ,
V_24 -> V_21 ) ;
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
static void F_44 ( struct V_75 * V_76 )
{
struct V_8 * V_24 = F_45 ( V_76 , struct
V_8 ,
V_57 . V_76 ) ;
F_43 ( V_24 ) ;
}
static T_1
F_46 ( struct V_40 * V_77 , struct V_78 * V_79 , char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
return sprintf ( V_80 , L_5 , V_24 -> type ) ;
}
static T_1
F_48 ( struct V_40 * V_77 , struct V_78 * V_79 , char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
long V_31 ;
int V_22 ;
V_22 = F_36 ( V_24 , & V_31 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_80 , L_6 , V_31 ) ;
}
static T_1
F_49 ( struct V_40 * V_77 , struct V_78 * V_79 , char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
enum V_81 V_82 ;
int V_83 ;
if ( ! V_24 -> V_29 -> V_84 )
return - V_85 ;
V_83 = V_24 -> V_29 -> V_84 ( V_24 , & V_82 ) ;
if ( V_83 )
return V_83 ;
return sprintf ( V_80 , L_5 , V_82 == V_86 ? L_7
: L_8 ) ;
}
static T_1
F_50 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_83 ;
if ( ! V_24 -> V_29 -> V_87 )
return - V_85 ;
if ( ! strncmp ( V_80 , L_7 , sizeof( L_7 ) - 1 ) )
V_83 = V_24 -> V_29 -> V_87 ( V_24 , V_86 ) ;
else if ( ! strncmp ( V_80 , L_8 , sizeof( L_8 ) - 1 ) )
V_83 = V_24 -> V_29 -> V_87 ( V_24 , V_88 ) ;
else
V_83 = - V_9 ;
if ( V_83 )
return V_83 ;
return V_71 ;
}
static T_1
F_51 ( struct V_40 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
enum V_61 type ;
int V_25 , V_83 ;
if ( ! V_24 -> V_29 -> V_68 )
return - V_85 ;
if ( ! sscanf ( V_79 -> V_79 . V_2 , L_9 , & V_25 ) )
return - V_9 ;
V_83 = V_24 -> V_29 -> V_68 ( V_24 , V_25 , & type ) ;
if ( V_83 )
return V_83 ;
switch ( type ) {
case V_67 :
return sprintf ( V_80 , L_10 ) ;
case V_69 :
return sprintf ( V_80 , L_11 ) ;
case V_89 :
return sprintf ( V_80 , L_12 ) ;
case V_90 :
return sprintf ( V_80 , L_13 ) ;
default:
return sprintf ( V_80 , L_14 ) ;
}
}
static T_1
F_52 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_91 )
return - V_85 ;
if ( ! sscanf ( V_79 -> V_79 . V_2 , L_15 , & V_25 ) )
return - V_9 ;
if ( F_53 ( V_80 , 10 , & V_31 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_91 ( V_24 , V_25 , V_31 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_54 ( struct V_40 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_25 , V_22 ;
long V_31 ;
if ( ! V_24 -> V_29 -> V_65 )
return - V_85 ;
if ( ! sscanf ( V_79 -> V_79 . V_2 , L_15 , & V_25 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_65 ( V_24 , V_25 , & V_31 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_80 , L_6 , V_31 ) ;
}
static T_1
F_55 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_92 )
return - V_85 ;
if ( ! sscanf ( V_79 -> V_79 . V_2 , L_16 , & V_25 ) )
return - V_9 ;
if ( F_53 ( V_80 , 10 , & V_31 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_92 ( V_24 , V_25 , V_31 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_56 ( struct V_40 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_25 , V_22 ;
unsigned long V_31 ;
if ( ! V_24 -> V_29 -> V_93 )
return - V_85 ;
if ( ! sscanf ( V_79 -> V_79 . V_2 , L_16 , & V_25 ) )
return - V_9 ;
V_22 = V_24 -> V_29 -> V_93 ( V_24 , V_25 , & V_31 ) ;
return V_22 ? V_22 : sprintf ( V_80 , L_6 , V_31 ) ;
}
static T_1
F_57 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
struct V_37 * V_38 = NULL ;
int V_94 ;
if ( ! sscanf ( V_80 , L_17 , & V_94 ) )
return - V_9 ;
if ( V_94 && V_94 < 1000 )
return - V_9 ;
if ( V_94 && ! V_24 -> V_95 ) {
F_4 ( & V_15 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_18 , V_38 -> type ,
sizeof( L_18 ) ) )
F_19 ( V_24 ,
V_96 , V_38 ,
V_47 ,
V_47 ) ;
}
F_6 ( & V_15 ) ;
if ( ! V_24 -> V_59 )
V_24 -> V_59 = 1000 ;
} else if ( ! V_94 && V_24 -> V_95 ) {
F_4 ( & V_15 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_18 , V_38 -> type ,
sizeof( L_18 ) ) )
F_21 ( V_24 ,
V_96 ,
V_38 ) ;
}
F_6 ( & V_15 ) ;
V_24 -> V_59 = 0 ;
}
V_24 -> V_95 = V_94 ;
F_43 ( V_24 ) ;
return V_71 ;
}
static T_1
F_58 ( struct V_40 * V_77 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
return sprintf ( V_80 , L_17 , V_24 -> V_95 ) ;
}
static T_1
F_59 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
int V_22 = - V_9 ;
struct V_8 * V_24 = F_47 ( V_77 ) ;
struct V_1 * V_97 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_19 , V_80 ) ;
F_4 ( & V_10 ) ;
V_97 = F_1 ( F_60 ( V_2 ) ) ;
if ( ! V_97 )
goto exit;
V_24 -> V_6 = V_97 ;
V_22 = V_71 ;
exit:
F_6 ( & V_10 ) ;
return V_22 ;
}
static T_1
F_61 ( struct V_40 * V_77 , struct V_78 * V_98 , char * V_80 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
return sprintf ( V_80 , L_5 , V_24 -> V_6 -> V_2 ) ;
}
static T_1
F_62 ( struct V_40 * V_77 , struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_8 * V_24 = F_47 ( V_77 ) ;
int V_22 = 0 ;
unsigned long V_31 ;
if ( F_53 ( V_80 , 10 , & V_31 ) )
return - V_9 ;
if ( ! V_24 -> V_29 -> V_99 ) {
F_4 ( & V_24 -> V_20 ) ;
V_24 -> V_28 = V_31 ;
F_6 ( & V_24 -> V_20 ) ;
} else {
V_22 = V_24 -> V_29 -> V_99 ( V_24 , V_31 ) ;
}
if ( ! V_22 )
F_43 ( V_24 ) ;
return V_22 ? V_22 : V_71 ;
}
static T_1
F_63 ( struct V_40 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_37 * V_38 = F_64 ( V_77 ) ;
return sprintf ( V_80 , L_5 , V_38 -> type ) ;
}
static T_1
F_65 ( struct V_40 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_37 * V_38 = F_64 ( V_77 ) ;
unsigned long V_94 ;
int V_22 ;
V_22 = V_38 -> V_29 -> V_100 ( V_38 , & V_94 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_80 , L_6 , V_94 ) ;
}
static T_1
F_66 ( struct V_40 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_37 * V_38 = F_64 ( V_77 ) ;
unsigned long V_94 ;
int V_22 ;
V_22 = V_38 -> V_29 -> V_101 ( V_38 , & V_94 ) ;
if ( V_22 )
return V_22 ;
return sprintf ( V_80 , L_6 , V_94 ) ;
}
static T_1
F_67 ( struct V_40 * V_77 ,
struct V_78 * V_79 ,
const char * V_80 , T_2 V_71 )
{
struct V_37 * V_38 = F_64 ( V_77 ) ;
unsigned long V_94 ;
int V_83 ;
if ( ! sscanf ( V_80 , L_6 , & V_94 ) )
return - V_9 ;
if ( ( long ) V_94 < 0 )
return - V_9 ;
V_83 = V_38 -> V_29 -> V_102 ( V_38 , V_94 ) ;
if ( V_83 )
return V_83 ;
return V_71 ;
}
static T_1
F_68 ( struct V_40 * V_77 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_36 * V_103 ;
V_103 =
F_45 ( V_79 , struct V_36 , V_79 ) ;
if ( V_103 -> V_25 == V_96 )
return sprintf ( V_80 , L_20 ) ;
else
return sprintf ( V_80 , L_17 , V_103 -> V_25 ) ;
}
int F_19 ( struct V_8 * V_24 ,
int V_25 ,
struct V_37 * V_38 ,
unsigned long V_45 , unsigned long V_46 )
{
struct V_36 * V_77 ;
struct V_36 * V_3 ;
struct V_8 * V_104 ;
struct V_37 * V_105 ;
unsigned long V_106 ;
int V_83 ;
if ( V_25 >= V_24 -> V_44 || ( V_25 < 0 && V_25 != V_96 ) )
return - V_9 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_104 == V_24 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_105 == V_38 )
break;
}
if ( V_24 != V_104 || V_38 != V_105 )
return - V_9 ;
V_38 -> V_29 -> V_100 ( V_38 , & V_106 ) ;
V_46 = V_46 == V_47 ? 0 : V_46 ;
V_45 = V_45 == V_47 ? V_106 : V_45 ;
if ( V_46 > V_45 || V_45 > V_106 )
return - V_9 ;
V_77 =
F_69 ( sizeof( struct V_36 ) , V_23 ) ;
if ( ! V_77 )
return - V_107 ;
V_77 -> V_24 = V_24 ;
V_77 -> V_38 = V_38 ;
V_77 -> V_25 = V_25 ;
V_77 -> V_45 = V_45 ;
V_77 -> V_46 = V_46 ;
V_77 -> V_108 = V_109 ;
V_83 = F_9 ( & V_24 -> V_18 , & V_24 -> V_20 , & V_77 -> V_21 ) ;
if ( V_83 )
goto V_110;
sprintf ( V_77 -> V_2 , L_21 , V_77 -> V_21 ) ;
V_83 =
F_70 ( & V_24 -> V_40 . V_111 , & V_38 -> V_40 . V_111 , V_77 -> V_2 ) ;
if ( V_83 )
goto F_12;
sprintf ( V_77 -> V_112 , L_22 , V_77 -> V_21 ) ;
F_71 ( & V_77 -> V_79 . V_79 ) ;
V_77 -> V_79 . V_79 . V_2 = V_77 -> V_112 ;
V_77 -> V_79 . V_79 . V_82 = 0444 ;
V_77 -> V_79 . V_113 = F_68 ;
V_83 = F_72 ( & V_24 -> V_40 , & V_77 -> V_79 ) ;
if ( V_83 )
goto V_114;
F_4 ( & V_24 -> V_20 ) ;
F_4 ( & V_38 -> V_20 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_24 == V_24 && V_3 -> V_25 == V_25 && V_3 -> V_38 == V_38 ) {
V_83 = - V_115 ;
break;
}
if ( ! V_83 ) {
F_73 ( & V_77 -> V_116 , & V_24 -> V_117 ) ;
F_73 ( & V_77 -> V_118 , & V_38 -> V_117 ) ;
}
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
if ( ! V_83 )
return 0 ;
F_74 ( & V_24 -> V_40 , & V_77 -> V_79 ) ;
V_114:
F_75 ( & V_24 -> V_40 . V_111 , V_77 -> V_2 ) ;
F_12:
F_12 ( & V_24 -> V_18 , & V_24 -> V_20 , V_77 -> V_21 ) ;
V_110:
F_76 ( V_77 ) ;
return V_83 ;
}
int F_21 ( struct V_8 * V_24 ,
int V_25 ,
struct V_37 * V_38 )
{
struct V_36 * V_3 , * V_119 ;
F_4 ( & V_24 -> V_20 ) ;
F_4 ( & V_38 -> V_20 ) ;
F_77 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_24 == V_24 && V_3 -> V_25 == V_25 && V_3 -> V_38 == V_38 ) {
F_8 ( & V_3 -> V_116 ) ;
F_8 ( & V_3 -> V_118 ) ;
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
goto V_120;
}
}
F_6 ( & V_38 -> V_20 ) ;
F_6 ( & V_24 -> V_20 ) ;
return - V_121 ;
V_120:
F_74 ( & V_24 -> V_40 , & V_3 -> V_79 ) ;
F_75 ( & V_24 -> V_40 . V_111 , V_3 -> V_2 ) ;
F_12 ( & V_24 -> V_18 , & V_24 -> V_20 , V_3 -> V_21 ) ;
F_76 ( V_3 ) ;
return 0 ;
}
static void F_78 ( struct V_40 * V_77 )
{
struct V_8 * V_24 ;
struct V_37 * V_38 ;
if ( ! strncmp ( F_79 ( V_77 ) , L_23 ,
sizeof( L_23 ) - 1 ) ) {
V_24 = F_47 ( V_77 ) ;
F_76 ( V_24 ) ;
} else if( ! strncmp ( F_79 ( V_77 ) , L_24 ,
sizeof( L_24 ) - 1 ) ) {
V_38 = F_64 ( V_77 ) ;
F_76 ( V_38 ) ;
}
}
static struct V_37 *
F_80 ( struct V_122 * V_123 ,
char * type , void * V_124 ,
const struct V_125 * V_29 )
{
struct V_37 * V_38 ;
int V_83 ;
if ( type && strlen ( type ) >= V_5 )
return F_81 ( - V_9 ) ;
if ( ! V_29 || ! V_29 -> V_100 || ! V_29 -> V_101 ||
! V_29 -> V_102 )
return F_81 ( - V_9 ) ;
V_38 = F_69 ( sizeof( struct V_37 ) , V_23 ) ;
if ( ! V_38 )
return F_81 ( - V_107 ) ;
V_83 = F_9 ( & V_126 , & V_127 , & V_38 -> V_21 ) ;
if ( V_83 ) {
F_76 ( V_38 ) ;
return F_81 ( V_83 ) ;
}
F_82 ( V_38 -> type , type ? : L_25 , sizeof( V_38 -> type ) ) ;
F_83 ( & V_38 -> V_20 ) ;
F_84 ( & V_38 -> V_117 ) ;
V_38 -> V_123 = V_123 ;
V_38 -> V_29 = V_29 ;
V_38 -> V_128 = false ;
V_38 -> V_40 . V_129 = & V_130 ;
V_38 -> V_124 = V_124 ;
F_85 ( & V_38 -> V_40 , L_26 , V_38 -> V_21 ) ;
V_83 = F_86 ( & V_38 -> V_40 ) ;
if ( V_83 ) {
F_12 ( & V_126 , & V_127 , V_38 -> V_21 ) ;
F_76 ( V_38 ) ;
return F_81 ( V_83 ) ;
}
if ( type ) {
V_83 = F_72 ( & V_38 -> V_40 , & V_131 ) ;
if ( V_83 )
goto V_132;
}
V_83 = F_72 ( & V_38 -> V_40 , & V_133 ) ;
if ( V_83 )
goto V_132;
V_83 = F_72 ( & V_38 -> V_40 , & V_134 ) ;
if ( V_83 )
goto V_132;
F_4 ( & V_15 ) ;
F_5 ( & V_38 -> V_135 , & V_136 ) ;
F_6 ( & V_15 ) ;
F_22 ( V_38 ) ;
return V_38 ;
V_132:
F_12 ( & V_126 , & V_127 , V_38 -> V_21 ) ;
F_87 ( & V_38 -> V_40 ) ;
return F_81 ( V_83 ) ;
}
struct V_37 *
F_88 ( char * type , void * V_124 ,
const struct V_125 * V_29 )
{
return F_80 ( NULL , type , V_124 , V_29 ) ;
}
struct V_37 *
F_89 ( struct V_122 * V_123 ,
char * type , void * V_124 ,
const struct V_125 * V_29 )
{
return F_80 ( V_123 , type , V_124 , V_29 ) ;
}
void F_90 ( struct V_37 * V_38 )
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
F_8 ( & V_38 -> V_135 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_24 -> V_29 -> V_120 ) {
V_24 -> V_29 -> V_120 ( V_24 , V_38 ) ;
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
F_74 ( & V_38 -> V_40 , & V_131 ) ;
F_74 ( & V_38 -> V_40 , & V_133 ) ;
F_74 ( & V_38 -> V_40 , & V_134 ) ;
F_12 ( & V_126 , & V_127 , V_38 -> V_21 ) ;
F_87 ( & V_38 -> V_40 ) ;
return;
}
void F_91 ( struct V_37 * V_38 )
{
struct V_36 * V_103 ;
unsigned long V_108 = 0 ;
if ( V_38 -> V_128 )
return;
F_4 ( & V_38 -> V_20 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_42 ( & V_38 -> V_40 , L_27 ,
V_103 -> V_24 -> V_21 , V_103 -> V_108 ) ;
if ( V_103 -> V_108 == V_109 )
continue;
if ( V_103 -> V_108 > V_108 )
V_108 = V_103 -> V_108 ;
}
F_6 ( & V_38 -> V_20 ) ;
V_38 -> V_29 -> V_102 ( V_38 , V_108 ) ;
V_38 -> V_128 = true ;
F_92 ( V_38 , V_108 ) ;
F_42 ( & V_38 -> V_40 , L_28 , V_108 ) ;
}
void F_93 ( struct V_8 * V_24 , int V_25 )
{
F_35 ( V_24 , V_25 ) ;
}
static int F_94 ( struct V_8 * V_24 , int V_41 )
{
int V_137 ;
int V_138 = sizeof( struct V_139 ) * V_24 -> V_44 ;
V_24 -> V_140 = F_69 ( V_138 , V_23 ) ;
if ( ! V_24 -> V_140 )
return - V_107 ;
V_24 -> V_141 = F_69 ( V_138 , V_23 ) ;
if ( ! V_24 -> V_141 ) {
F_76 ( V_24 -> V_140 ) ;
return - V_107 ;
}
if ( V_24 -> V_29 -> V_93 ) {
V_24 -> V_142 = F_69 ( V_138 , V_23 ) ;
if ( ! V_24 -> V_142 ) {
F_76 ( V_24 -> V_140 ) ;
F_76 ( V_24 -> V_141 ) ;
return - V_107 ;
}
}
for ( V_137 = 0 ; V_137 < V_24 -> V_44 ; V_137 ++ ) {
snprintf ( V_24 -> V_140 [ V_137 ] . V_2 , V_5 ,
L_9 , V_137 ) ;
F_71 ( & V_24 -> V_140 [ V_137 ] . V_79 . V_79 ) ;
V_24 -> V_140 [ V_137 ] . V_79 . V_79 . V_2 =
V_24 -> V_140 [ V_137 ] . V_2 ;
V_24 -> V_140 [ V_137 ] . V_79 . V_79 . V_82 = V_143 ;
V_24 -> V_140 [ V_137 ] . V_79 . V_113 = F_51 ;
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_140 [ V_137 ] . V_79 ) ;
snprintf ( V_24 -> V_141 [ V_137 ] . V_2 , V_5 ,
L_15 , V_137 ) ;
F_71 ( & V_24 -> V_141 [ V_137 ] . V_79 . V_79 ) ;
V_24 -> V_141 [ V_137 ] . V_79 . V_79 . V_2 =
V_24 -> V_141 [ V_137 ] . V_2 ;
V_24 -> V_141 [ V_137 ] . V_79 . V_79 . V_82 = V_143 ;
V_24 -> V_141 [ V_137 ] . V_79 . V_113 = F_54 ;
if ( V_41 & ( 1 << V_137 ) ) {
V_24 -> V_141 [ V_137 ] . V_79 . V_79 . V_82 |= V_144 ;
V_24 -> V_141 [ V_137 ] . V_79 . V_145 =
F_52 ;
}
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_141 [ V_137 ] . V_79 ) ;
if ( ! V_24 -> V_29 -> V_93 )
continue;
snprintf ( V_24 -> V_142 [ V_137 ] . V_2 , V_5 ,
L_16 , V_137 ) ;
F_71 ( & V_24 -> V_142 [ V_137 ] . V_79 . V_79 ) ;
V_24 -> V_142 [ V_137 ] . V_79 . V_79 . V_2 =
V_24 -> V_142 [ V_137 ] . V_2 ;
V_24 -> V_142 [ V_137 ] . V_79 . V_79 . V_82 = V_143 ;
V_24 -> V_142 [ V_137 ] . V_79 . V_113 = F_56 ;
if ( V_24 -> V_29 -> V_92 ) {
V_24 -> V_142 [ V_137 ] . V_79 . V_79 . V_82 |= V_144 ;
V_24 -> V_142 [ V_137 ] . V_79 . V_145 =
F_55 ;
}
F_72 ( & V_24 -> V_40 ,
& V_24 -> V_142 [ V_137 ] . V_79 ) ;
}
return 0 ;
}
static void F_95 ( struct V_8 * V_24 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_24 -> V_44 ; V_137 ++ ) {
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_140 [ V_137 ] . V_79 ) ;
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_141 [ V_137 ] . V_79 ) ;
if ( V_24 -> V_29 -> V_93 )
F_74 ( & V_24 -> V_40 ,
& V_24 -> V_142 [ V_137 ] . V_79 ) ;
}
F_76 ( V_24 -> V_140 ) ;
F_76 ( V_24 -> V_141 ) ;
F_76 ( V_24 -> V_142 ) ;
}
struct V_8 * F_96 ( const char * type ,
int V_44 , int V_41 , void * V_124 ,
struct V_146 * V_29 ,
const struct V_48 * V_16 ,
int V_59 , int V_60 )
{
struct V_8 * V_24 ;
enum V_61 V_62 ;
int V_83 ;
int V_71 ;
int V_58 = 0 ;
if ( type && strlen ( type ) >= V_5 )
return F_81 ( - V_9 ) ;
if ( V_44 > V_147 || V_44 < 0 || V_41 > > V_44 )
return F_81 ( - V_9 ) ;
if ( ! V_29 )
return F_81 ( - V_9 ) ;
if ( V_44 > 0 && ( ! V_29 -> V_68 || ! V_29 -> V_65 ) )
return F_81 ( - V_9 ) ;
V_24 = F_69 ( sizeof( struct V_8 ) , V_23 ) ;
if ( ! V_24 )
return F_81 ( - V_107 ) ;
F_84 ( & V_24 -> V_117 ) ;
F_97 ( & V_24 -> V_18 ) ;
F_83 ( & V_24 -> V_20 ) ;
V_83 = F_9 ( & V_148 , & V_127 , & V_24 -> V_21 ) ;
if ( V_83 ) {
F_76 ( V_24 ) ;
return F_81 ( V_83 ) ;
}
F_82 ( V_24 -> type , type ? : L_25 , sizeof( V_24 -> type ) ) ;
V_24 -> V_29 = V_29 ;
V_24 -> V_16 = V_16 ;
V_24 -> V_40 . V_129 = & V_130 ;
V_24 -> V_124 = V_124 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_59 = V_59 ;
V_24 -> V_60 = V_60 ;
F_85 ( & V_24 -> V_40 , L_29 , V_24 -> V_21 ) ;
V_83 = F_86 ( & V_24 -> V_40 ) ;
if ( V_83 ) {
F_12 ( & V_148 , & V_127 , V_24 -> V_21 ) ;
F_76 ( V_24 ) ;
return F_81 ( V_83 ) ;
}
if ( type ) {
V_83 = F_72 ( & V_24 -> V_40 , & V_149 ) ;
if ( V_83 )
goto V_132;
}
V_83 = F_72 ( & V_24 -> V_40 , & V_150 ) ;
if ( V_83 )
goto V_132;
if ( V_29 -> V_84 ) {
V_83 = F_72 ( & V_24 -> V_40 , & V_151 ) ;
if ( V_83 )
goto V_132;
}
V_83 = F_94 ( V_24 , V_41 ) ;
if ( V_83 )
goto V_132;
for ( V_71 = 0 ; V_71 < V_44 ; V_71 ++ ) {
V_24 -> V_29 -> V_68 ( V_24 , V_71 , & V_62 ) ;
if ( V_62 == V_89 )
V_58 = 1 ;
}
if ( ! V_58 ) {
V_83 = F_72 ( & V_24 -> V_40 , & V_152 ) ;
if ( V_83 )
goto V_132;
}
#ifdef F_37
V_83 = F_72 ( & V_24 -> V_40 , & V_153 ) ;
if ( V_83 )
goto V_132;
#endif
V_83 = F_72 ( & V_24 -> V_40 , & V_154 ) ;
if ( V_83 )
goto V_132;
F_4 ( & V_10 ) ;
if ( V_24 -> V_16 )
V_24 -> V_6 = F_1 ( V_24 -> V_16 -> V_17 ) ;
else
V_24 -> V_6 = V_4 ;
F_6 ( & V_10 ) ;
if ( ! V_24 -> V_16 || ! V_24 -> V_16 -> V_155 ) {
V_83 = F_98 ( V_24 ) ;
if ( V_83 )
goto V_132;
}
F_4 ( & V_15 ) ;
F_73 ( & V_24 -> V_135 , & V_156 ) ;
F_6 ( & V_15 ) ;
F_23 ( V_24 ) ;
F_99 ( & ( V_24 -> V_57 ) , F_44 ) ;
if ( ! V_24 -> V_29 -> V_73 )
F_24 ( V_24 , 0 ) ;
F_43 ( V_24 ) ;
return V_24 ;
V_132:
F_12 ( & V_148 , & V_127 , V_24 -> V_21 ) ;
F_87 ( & V_24 -> V_40 ) ;
return F_81 ( V_83 ) ;
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
F_8 ( & V_24 -> V_135 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_24 -> V_29 -> V_120 ) {
V_24 -> V_29 -> V_120 ( V_24 , V_38 ) ;
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
F_74 ( & V_24 -> V_40 , & V_149 ) ;
F_74 ( & V_24 -> V_40 , & V_150 ) ;
if ( V_24 -> V_29 -> V_84 )
F_74 ( & V_24 -> V_40 , & V_151 ) ;
F_74 ( & V_24 -> V_40 , & V_154 ) ;
F_95 ( V_24 ) ;
V_24 -> V_6 = NULL ;
F_101 ( V_24 ) ;
F_12 ( & V_148 , & V_127 , V_24 -> V_21 ) ;
F_102 ( & V_24 -> V_18 ) ;
F_103 ( & V_24 -> V_20 ) ;
F_87 ( & V_24 -> V_40 ) ;
return;
}
struct V_8 * F_104 ( const char * V_2 )
{
struct V_8 * V_3 = NULL , * V_157 = F_81 ( - V_9 ) ;
unsigned int V_158 = 0 ;
if ( ! V_2 )
goto exit;
F_4 ( & V_15 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_158 ++ ;
V_157 = V_3 ;
}
F_6 ( & V_15 ) ;
if ( V_158 == 0 )
V_157 = F_81 ( - V_121 ) ;
else if ( V_158 > 1 )
V_157 = F_81 ( - V_115 ) ;
exit:
return V_157 ;
}
int F_105 ( struct V_8 * V_24 ,
enum V_159 V_160 )
{
struct V_161 * V_162 ;
struct V_163 * V_79 ;
struct V_164 * V_165 ;
void * V_166 ;
int V_138 ;
int V_83 ;
static unsigned int V_167 ;
if ( ! V_24 )
return - V_9 ;
V_138 = F_106 ( sizeof( struct V_164 ) ) +
F_106 ( 0 ) ;
V_162 = F_107 ( V_138 , V_168 ) ;
if ( ! V_162 )
return - V_107 ;
V_166 = F_108 ( V_162 , 0 , V_167 ++ ,
& V_169 , 0 ,
V_170 ) ;
if ( ! V_166 ) {
F_109 ( V_162 ) ;
return - V_107 ;
}
V_79 = F_110 ( V_162 , V_171 ,
sizeof( struct V_164 ) ) ;
if ( ! V_79 ) {
F_109 ( V_162 ) ;
return - V_9 ;
}
V_165 = F_111 ( V_79 ) ;
if ( ! V_165 ) {
F_109 ( V_162 ) ;
return - V_9 ;
}
memset ( V_165 , 0 , sizeof( struct V_164 ) ) ;
V_165 -> V_172 = V_24 -> V_21 ;
V_165 -> V_160 = V_160 ;
V_83 = F_112 ( V_162 , V_166 ) ;
if ( V_83 < 0 ) {
F_109 ( V_162 ) ;
return V_83 ;
}
V_83 = F_113 ( & V_169 , V_162 , 0 ,
0 , V_168 ) ;
if ( V_83 )
F_17 ( & V_24 -> V_40 , L_30 , V_83 ) ;
return V_83 ;
}
static int F_114 ( void )
{
return F_115 ( & V_169 ) ;
}
static void F_116 ( void )
{
F_117 ( & V_169 ) ;
}
static inline int F_114 ( void ) { return 0 ; }
static inline void F_116 ( void ) {}
static int T_3 F_118 ( void )
{
int V_83 ;
V_83 = F_119 () ;
if ( V_83 )
return V_83 ;
V_83 = F_120 () ;
if ( V_83 )
return V_83 ;
V_83 = F_121 () ;
if ( V_83 )
return V_83 ;
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
int V_83 ;
V_83 = F_118 () ;
if ( V_83 )
goto error;
V_83 = F_129 ( & V_130 ) ;
if ( V_83 )
goto V_173;
V_83 = F_114 () ;
if ( V_83 )
goto V_174;
V_83 = F_130 () ;
if ( V_83 )
goto V_175;
return 0 ;
V_175:
F_116 () ;
V_173:
F_123 () ;
V_174:
F_131 ( & V_130 ) ;
error:
F_102 ( & V_148 ) ;
F_102 ( & V_126 ) ;
F_103 ( & V_127 ) ;
F_103 ( & V_15 ) ;
F_103 ( & V_10 ) ;
return V_83 ;
}
static void T_4 F_132 ( void )
{
F_133 () ;
F_116 () ;
F_131 ( & V_130 ) ;
F_123 () ;
F_102 ( & V_148 ) ;
F_102 ( & V_126 ) ;
F_103 ( & V_127 ) ;
F_103 ( & V_15 ) ;
F_103 ( & V_10 ) ;
}
