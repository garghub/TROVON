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
long V_69 ;
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
int F_38 ( struct V_6 * V_7 , unsigned long * V_75 )
{
int V_13 = - V_16 ;
#ifdef F_39
int V_76 ;
unsigned long V_77 = - 1UL ;
enum V_66 type ;
#endif
if ( ! V_7 || F_40 ( V_7 ) || ! V_7 -> V_34 -> V_78 )
goto exit;
F_7 ( & V_7 -> V_27 ) ;
V_13 = V_7 -> V_34 -> V_78 ( V_7 , V_75 ) ;
#ifdef F_39
if ( ! V_7 -> V_33 )
goto V_79;
for ( V_76 = 0 ; V_76 < V_7 -> V_49 ; V_76 ++ ) {
V_13 = V_7 -> V_34 -> V_73 ( V_7 , V_76 , & type ) ;
if ( ! V_13 && type == V_72 ) {
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_76 , & V_77 ) ;
break;
}
}
if ( V_13 )
goto V_79;
if ( * V_75 < V_77 )
* V_75 = V_7 -> V_33 ;
V_79:
#endif
F_9 ( & V_7 -> V_27 ) ;
exit:
return V_13 ;
}
static void F_41 ( struct V_6 * V_7 )
{
long V_75 ;
int V_13 ;
V_13 = F_38 ( V_7 , & V_75 ) ;
if ( V_13 ) {
if ( V_13 != - V_80 )
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
if ( ! V_7 -> V_34 -> V_78 )
return;
F_41 ( V_7 ) ;
for ( V_76 = 0 ; V_76 < V_7 -> V_49 ; V_76 ++ )
F_37 ( V_7 , V_76 ) ;
}
static void F_46 ( struct V_81 * V_82 )
{
struct V_6 * V_7 = F_47 ( V_82 , struct
V_6 ,
V_62 . V_82 ) ;
F_45 ( V_7 ) ;
}
static T_1
F_48 ( struct V_11 * V_83 , struct V_84 * V_85 , char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
return sprintf ( V_86 , L_7 , V_7 -> type ) ;
}
static T_1
F_50 ( struct V_11 * V_83 , struct V_84 * V_85 , char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
long V_36 ;
int V_13 ;
V_13 = F_38 ( V_7 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_86 , L_8 , V_36 ) ;
}
static T_1
F_51 ( struct V_11 * V_83 , struct V_84 * V_85 , char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
enum V_87 V_88 ;
int V_89 ;
if ( ! V_7 -> V_34 -> V_90 )
return - V_91 ;
V_89 = V_7 -> V_34 -> V_90 ( V_7 , & V_88 ) ;
if ( V_89 )
return V_89 ;
return sprintf ( V_86 , L_7 , V_88 == V_92 ? L_9
: L_10 ) ;
}
static T_1
F_52 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_89 ;
if ( ! V_7 -> V_34 -> V_93 )
return - V_91 ;
if ( ! strncmp ( V_86 , L_9 , sizeof( L_9 ) - 1 ) )
V_89 = V_7 -> V_34 -> V_93 ( V_7 , V_92 ) ;
else if ( ! strncmp ( V_86 , L_10 , sizeof( L_10 ) - 1 ) )
V_89 = V_7 -> V_34 -> V_93 ( V_7 , V_94 ) ;
else
V_89 = - V_16 ;
if ( V_89 )
return V_89 ;
return V_76 ;
}
static T_1
F_53 ( struct V_11 * V_83 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
enum V_66 type ;
int V_30 , V_89 ;
if ( ! V_7 -> V_34 -> V_73 )
return - V_91 ;
if ( ! sscanf ( V_85 -> V_85 . V_2 , L_11 , & V_30 ) )
return - V_16 ;
V_89 = V_7 -> V_34 -> V_73 ( V_7 , V_30 , & type ) ;
if ( V_89 )
return V_89 ;
switch ( type ) {
case V_72 :
return sprintf ( V_86 , L_12 ) ;
case V_74 :
return sprintf ( V_86 , L_13 ) ;
case V_95 :
return sprintf ( V_86 , L_14 ) ;
case V_96 :
return sprintf ( V_86 , L_15 ) ;
default:
return sprintf ( V_86 , L_16 ) ;
}
}
static T_1
F_54 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_30 , V_13 ;
unsigned long V_36 ;
if ( ! V_7 -> V_34 -> V_97 )
return - V_91 ;
if ( ! sscanf ( V_85 -> V_85 . V_2 , L_17 , & V_30 ) )
return - V_16 ;
if ( F_55 ( V_86 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_97 ( V_7 , V_30 , V_36 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_56 ( struct V_11 * V_83 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_30 , V_13 ;
long V_36 ;
if ( ! V_7 -> V_34 -> V_70 )
return - V_91 ;
if ( ! sscanf ( V_85 -> V_85 . V_2 , L_17 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_70 ( V_7 , V_30 , & V_36 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_86 , L_8 , V_36 ) ;
}
static T_1
F_57 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_30 , V_13 ;
unsigned long V_36 ;
if ( ! V_7 -> V_34 -> V_98 )
return - V_91 ;
if ( ! sscanf ( V_85 -> V_85 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
if ( F_55 ( V_86 , 10 , & V_36 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_98 ( V_7 , V_30 , V_36 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_58 ( struct V_11 * V_83 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_30 , V_13 ;
unsigned long V_36 ;
if ( ! V_7 -> V_34 -> V_99 )
return - V_91 ;
if ( ! sscanf ( V_85 -> V_85 . V_2 , L_18 , & V_30 ) )
return - V_16 ;
V_13 = V_7 -> V_34 -> V_99 ( V_7 , V_30 , & V_36 ) ;
return V_13 ? V_13 : sprintf ( V_86 , L_8 , V_36 ) ;
}
static T_1
F_59 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
struct V_42 * V_43 = NULL ;
int V_100 ;
if ( ! sscanf ( V_86 , L_19 , & V_100 ) )
return - V_16 ;
if ( V_100 && V_100 < 1000 )
return - V_16 ;
if ( V_100 && ! V_7 -> V_101 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_20 , V_43 -> type ,
sizeof( L_20 ) ) )
F_21 ( V_7 ,
V_102 , V_43 ,
V_52 ,
V_52 ,
V_103 ) ;
}
F_9 ( & V_22 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = 1000 ;
} else if ( ! V_100 && V_7 -> V_101 ) {
F_7 ( & V_22 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_20 , V_43 -> type ,
sizeof( L_20 ) ) )
F_23 ( V_7 ,
V_102 ,
V_43 ) ;
}
F_9 ( & V_22 ) ;
V_7 -> V_64 = 0 ;
}
V_7 -> V_101 = V_100 ;
F_45 ( V_7 ) ;
return V_76 ;
}
static T_1
F_60 ( struct V_11 * V_83 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
return sprintf ( V_86 , L_19 , V_7 -> V_101 ) ;
}
static T_1
F_61 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
int V_13 = - V_16 ;
struct V_6 * V_7 = F_49 ( V_83 ) ;
struct V_1 * V_104 ;
char V_2 [ V_5 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_21 , V_86 ) ;
F_7 ( & V_17 ) ;
F_7 ( & V_7 -> V_27 ) ;
V_104 = F_1 ( F_62 ( V_2 ) ) ;
if ( ! V_104 )
goto exit;
V_13 = F_5 ( V_7 , V_104 ) ;
if ( ! V_13 )
V_13 = V_76 ;
exit:
F_9 ( & V_7 -> V_27 ) ;
F_9 ( & V_17 ) ;
return V_13 ;
}
static T_1
F_63 ( struct V_11 * V_83 , struct V_84 * V_105 , char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
return sprintf ( V_86 , L_7 , V_7 -> V_9 -> V_2 ) ;
}
static T_1
F_64 ( struct V_11 * V_83 , struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
int V_13 = 0 ;
unsigned long V_36 ;
if ( F_55 ( V_86 , 10 , & V_36 ) )
return - V_16 ;
if ( ! V_7 -> V_34 -> V_106 ) {
F_7 ( & V_7 -> V_27 ) ;
V_7 -> V_33 = V_36 ;
F_9 ( & V_7 -> V_27 ) ;
} else {
V_13 = V_7 -> V_34 -> V_106 ( V_7 , V_36 ) ;
}
if ( ! V_13 )
F_45 ( V_7 ) ;
return V_13 ? V_13 : V_76 ;
}
static T_1
F_65 ( struct V_11 * V_83 , struct V_84 * V_105 ,
char * V_86 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
if ( V_7 -> V_23 )
return sprintf ( V_86 , L_22 , V_7 -> V_23 -> V_107 ) ;
else
return - V_108 ;
}
static T_1
F_66 ( struct V_11 * V_83 , struct V_84 * V_105 ,
const char * V_86 , T_2 V_76 )
{
struct V_6 * V_7 = F_49 ( V_83 ) ;
T_3 V_107 ;
if ( ! V_7 -> V_23 )
return - V_108 ;
if ( F_67 ( V_86 , 10 , & V_107 ) )
return - V_16 ;
V_7 -> V_23 -> V_107 = V_107 ;
return V_76 ;
}
static int F_68 ( struct V_11 * V_83 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_69 ( V_109 ) ; V_48 ++ ) {
int V_13 ;
struct V_84 * V_110 = V_109 [ V_48 ] ;
V_13 = F_70 ( V_83 , V_110 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_71 ( struct V_42 * V_43 ,
struct V_6 * V_7 , T_3 * V_111 )
{
if ( ! F_72 ( V_43 ) )
return - V_16 ;
return V_43 -> V_34 -> V_112 ( V_43 , V_7 , 0 , V_111 ) ;
}
int F_73 ( struct V_42 * V_43 ,
struct V_41 * V_113 , T_3 V_114 )
{
unsigned long V_100 ;
int V_13 ;
if ( ! F_72 ( V_43 ) )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_115 ( V_43 , V_113 -> V_7 , V_114 , & V_100 ) ;
if ( V_13 )
return V_13 ;
V_113 -> V_116 = V_100 ;
V_43 -> V_117 = false ;
F_74 ( V_43 ) ;
return 0 ;
}
static T_1
F_75 ( struct V_11 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_42 * V_43 = F_76 ( V_83 ) ;
return sprintf ( V_86 , L_7 , V_43 -> type ) ;
}
static T_1
F_77 ( struct V_11 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_42 * V_43 = F_76 ( V_83 ) ;
unsigned long V_100 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_118 ( V_43 , & V_100 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_86 , L_8 , V_100 ) ;
}
static T_1
F_78 ( struct V_11 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_42 * V_43 = F_76 ( V_83 ) ;
unsigned long V_100 ;
int V_13 ;
V_13 = V_43 -> V_34 -> V_119 ( V_43 , & V_100 ) ;
if ( V_13 )
return V_13 ;
return sprintf ( V_86 , L_8 , V_100 ) ;
}
static T_1
F_79 ( struct V_11 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_42 * V_43 = F_76 ( V_83 ) ;
unsigned long V_100 ;
int V_89 ;
if ( ! sscanf ( V_86 , L_8 , & V_100 ) )
return - V_16 ;
if ( ( long ) V_100 < 0 )
return - V_16 ;
V_89 = V_43 -> V_34 -> V_120 ( V_43 , V_100 ) ;
if ( V_89 )
return V_89 ;
return V_76 ;
}
static T_1
F_80 ( struct V_11 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_41 * V_113 ;
V_113 =
F_47 ( V_85 , struct V_41 , V_85 ) ;
if ( V_113 -> V_30 == V_102 )
return sprintf ( V_86 , L_23 ) ;
else
return sprintf ( V_86 , L_19 , V_113 -> V_30 ) ;
}
static T_1
F_81 ( struct V_11 * V_83 ,
struct V_84 * V_85 , char * V_86 )
{
struct V_41 * V_113 ;
V_113 = F_47 ( V_85 , struct V_41 , V_121 ) ;
return sprintf ( V_86 , L_19 , V_113 -> V_47 ) ;
}
static T_1
F_82 ( struct V_11 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_2 V_76 )
{
struct V_41 * V_113 ;
int V_13 , V_47 ;
V_13 = F_83 ( V_86 , 0 , & V_47 ) ;
if ( V_13 )
return V_13 ;
V_113 = F_47 ( V_85 , struct V_41 , V_121 ) ;
V_113 -> V_47 = V_47 ;
return V_76 ;
}
int F_21 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 ,
unsigned long V_50 , unsigned long V_51 ,
unsigned int V_47 )
{
struct V_41 * V_83 ;
struct V_41 * V_3 ;
struct V_6 * V_122 ;
struct V_42 * V_123 ;
unsigned long V_124 ;
int V_89 , V_13 ;
if ( V_30 >= V_7 -> V_49 || ( V_30 < 0 && V_30 != V_102 ) )
return - V_16 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_122 == V_7 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_123 == V_43 )
break;
}
if ( V_7 != V_122 || V_43 != V_123 )
return - V_16 ;
V_13 = V_43 -> V_34 -> V_118 ( V_43 , & V_124 ) ;
if ( V_13 )
return V_13 ;
V_51 = V_51 == V_52 ? 0 : V_51 ;
V_50 = V_50 == V_52 ? V_124 : V_50 ;
if ( V_51 > V_50 || V_50 > V_124 )
return - V_16 ;
V_83 =
F_84 ( sizeof( struct V_41 ) , V_29 ) ;
if ( ! V_83 )
return - V_125 ;
V_83 -> V_7 = V_7 ;
V_83 -> V_43 = V_43 ;
V_83 -> V_30 = V_30 ;
V_83 -> V_50 = V_50 ;
V_83 -> V_51 = V_51 ;
V_83 -> V_116 = V_126 ;
V_83 -> V_47 = V_47 ;
V_89 = F_12 ( & V_7 -> V_25 , & V_7 -> V_27 , & V_83 -> V_28 ) ;
if ( V_89 )
goto V_127;
sprintf ( V_83 -> V_2 , L_24 , V_83 -> V_28 ) ;
V_89 =
F_85 ( & V_7 -> V_11 . V_128 , & V_43 -> V_11 . V_128 , V_83 -> V_2 ) ;
if ( V_89 )
goto F_15;
sprintf ( V_83 -> V_129 , L_25 , V_83 -> V_28 ) ;
F_86 ( & V_83 -> V_85 . V_85 ) ;
V_83 -> V_85 . V_85 . V_2 = V_83 -> V_129 ;
V_83 -> V_85 . V_85 . V_88 = 0444 ;
V_83 -> V_85 . V_130 = F_80 ;
V_89 = F_70 ( & V_7 -> V_11 , & V_83 -> V_85 ) ;
if ( V_89 )
goto V_131;
sprintf ( V_83 -> V_132 , L_26 , V_83 -> V_28 ) ;
F_86 ( & V_83 -> V_121 . V_85 ) ;
V_83 -> V_121 . V_85 . V_2 = V_83 -> V_132 ;
V_83 -> V_121 . V_85 . V_88 = V_133 | V_134 ;
V_83 -> V_121 . V_130 = F_81 ;
V_83 -> V_121 . V_135 = F_82 ;
V_89 = F_70 ( & V_7 -> V_11 , & V_83 -> V_121 ) ;
if ( V_89 )
goto V_136;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
V_89 = - V_137 ;
break;
}
if ( ! V_89 ) {
F_87 ( & V_83 -> V_138 , & V_7 -> V_139 ) ;
F_87 ( & V_83 -> V_140 , & V_43 -> V_139 ) ;
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
if ( ! V_89 )
return 0 ;
F_88 ( & V_7 -> V_11 , & V_83 -> V_121 ) ;
V_136:
F_88 ( & V_7 -> V_11 , & V_83 -> V_85 ) ;
V_131:
F_89 ( & V_7 -> V_11 . V_128 , V_83 -> V_2 ) ;
F_15:
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_83 -> V_28 ) ;
V_127:
F_90 ( V_83 ) ;
return V_89 ;
}
int F_23 ( struct V_6 * V_7 ,
int V_30 ,
struct V_42 * V_43 )
{
struct V_41 * V_3 , * V_141 ;
F_7 ( & V_7 -> V_27 ) ;
F_7 ( & V_43 -> V_27 ) ;
F_91 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_7 == V_7 && V_3 -> V_30 == V_30 && V_3 -> V_43 == V_43 ) {
F_11 ( & V_3 -> V_138 ) ;
F_11 ( & V_3 -> V_140 ) ;
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
goto V_142;
}
}
F_9 ( & V_43 -> V_27 ) ;
F_9 ( & V_7 -> V_27 ) ;
return - V_143 ;
V_142:
F_88 ( & V_7 -> V_11 , & V_3 -> V_121 ) ;
F_88 ( & V_7 -> V_11 , & V_3 -> V_85 ) ;
F_89 ( & V_7 -> V_11 . V_128 , V_3 -> V_2 ) ;
F_15 ( & V_7 -> V_25 , & V_7 -> V_27 , V_3 -> V_28 ) ;
F_90 ( V_3 ) ;
return 0 ;
}
static void F_92 ( struct V_11 * V_83 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( ! strncmp ( F_93 ( V_83 ) , L_27 ,
sizeof( L_27 ) - 1 ) ) {
V_7 = F_49 ( V_83 ) ;
F_90 ( V_7 ) ;
} else if( ! strncmp ( F_93 ( V_83 ) , L_28 ,
sizeof( L_28 ) - 1 ) ) {
V_43 = F_76 ( V_83 ) ;
F_90 ( V_43 ) ;
}
}
static struct V_42 *
F_94 ( struct V_144 * V_145 ,
char * type , void * V_146 ,
const struct V_147 * V_34 )
{
struct V_42 * V_43 ;
int V_89 ;
if ( type && strlen ( type ) >= V_5 )
return F_95 ( - V_16 ) ;
if ( ! V_34 || ! V_34 -> V_118 || ! V_34 -> V_119 ||
! V_34 -> V_120 )
return F_95 ( - V_16 ) ;
V_43 = F_84 ( sizeof( struct V_42 ) , V_29 ) ;
if ( ! V_43 )
return F_95 ( - V_125 ) ;
V_89 = F_12 ( & V_148 , & V_149 , & V_43 -> V_28 ) ;
if ( V_89 ) {
F_90 ( V_43 ) ;
return F_95 ( V_89 ) ;
}
F_96 ( V_43 -> type , type ? : L_29 , sizeof( V_43 -> type ) ) ;
F_97 ( & V_43 -> V_27 ) ;
F_98 ( & V_43 -> V_139 ) ;
V_43 -> V_145 = V_145 ;
V_43 -> V_34 = V_34 ;
V_43 -> V_117 = false ;
V_43 -> V_11 . V_150 = & V_151 ;
V_43 -> V_11 . V_152 = V_153 ;
V_43 -> V_146 = V_146 ;
F_99 ( & V_43 -> V_11 , L_30 , V_43 -> V_28 ) ;
V_89 = F_100 ( & V_43 -> V_11 ) ;
if ( V_89 ) {
F_15 ( & V_148 , & V_149 , V_43 -> V_28 ) ;
F_90 ( V_43 ) ;
return F_95 ( V_89 ) ;
}
F_7 ( & V_22 ) ;
F_8 ( & V_43 -> V_154 , & V_155 ) ;
F_9 ( & V_22 ) ;
F_24 ( V_43 ) ;
return V_43 ;
}
struct V_42 *
F_101 ( char * type , void * V_146 ,
const struct V_147 * V_34 )
{
return F_94 ( NULL , type , V_146 , V_34 ) ;
}
struct V_42 *
F_102 ( struct V_144 * V_145 ,
char * type , void * V_146 ,
const struct V_147 * V_34 )
{
return F_94 ( V_145 , type , V_146 , V_34 ) ;
}
void F_103 ( struct V_42 * V_43 )
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
F_11 ( & V_43 -> V_154 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_7 -> V_34 -> V_142 ) {
V_7 -> V_34 -> V_142 ( V_7 , V_43 ) ;
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
F_88 ( & V_43 -> V_11 , & V_156 ) ;
F_88 ( & V_43 -> V_11 , & V_157 ) ;
F_88 ( & V_43 -> V_11 , & V_158 ) ;
F_15 ( & V_148 , & V_149 , V_43 -> V_28 ) ;
F_104 ( & V_43 -> V_11 ) ;
return;
}
void F_74 ( struct V_42 * V_43 )
{
struct V_41 * V_113 ;
unsigned long V_116 = 0 ;
if ( V_43 -> V_117 )
return;
F_7 ( & V_43 -> V_27 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
F_44 ( & V_43 -> V_11 , L_31 ,
V_113 -> V_7 -> V_28 , V_113 -> V_116 ) ;
if ( V_113 -> V_116 == V_126 )
continue;
if ( V_113 -> V_116 > V_116 )
V_116 = V_113 -> V_116 ;
}
F_9 ( & V_43 -> V_27 ) ;
V_43 -> V_34 -> V_120 ( V_43 , V_116 ) ;
V_43 -> V_117 = true ;
F_105 ( V_43 , V_116 ) ;
F_44 ( & V_43 -> V_11 , L_32 , V_116 ) ;
}
void F_106 ( struct V_6 * V_7 , int V_30 )
{
F_37 ( V_7 , V_30 ) ;
}
static int F_107 ( struct V_6 * V_7 , int V_45 )
{
int V_159 ;
int V_160 = sizeof( struct V_161 ) * V_7 -> V_49 ;
V_7 -> V_162 = F_84 ( V_160 , V_29 ) ;
if ( ! V_7 -> V_162 )
return - V_125 ;
V_7 -> V_163 = F_84 ( V_160 , V_29 ) ;
if ( ! V_7 -> V_163 ) {
F_90 ( V_7 -> V_162 ) ;
return - V_125 ;
}
if ( V_7 -> V_34 -> V_99 ) {
V_7 -> V_164 = F_84 ( V_160 , V_29 ) ;
if ( ! V_7 -> V_164 ) {
F_90 ( V_7 -> V_162 ) ;
F_90 ( V_7 -> V_163 ) ;
return - V_125 ;
}
}
for ( V_159 = 0 ; V_159 < V_7 -> V_49 ; V_159 ++ ) {
snprintf ( V_7 -> V_162 [ V_159 ] . V_2 , V_5 ,
L_11 , V_159 ) ;
F_86 ( & V_7 -> V_162 [ V_159 ] . V_85 . V_85 ) ;
V_7 -> V_162 [ V_159 ] . V_85 . V_85 . V_2 =
V_7 -> V_162 [ V_159 ] . V_2 ;
V_7 -> V_162 [ V_159 ] . V_85 . V_85 . V_88 = V_134 ;
V_7 -> V_162 [ V_159 ] . V_85 . V_130 = F_53 ;
F_70 ( & V_7 -> V_11 ,
& V_7 -> V_162 [ V_159 ] . V_85 ) ;
snprintf ( V_7 -> V_163 [ V_159 ] . V_2 , V_5 ,
L_17 , V_159 ) ;
F_86 ( & V_7 -> V_163 [ V_159 ] . V_85 . V_85 ) ;
V_7 -> V_163 [ V_159 ] . V_85 . V_85 . V_2 =
V_7 -> V_163 [ V_159 ] . V_2 ;
V_7 -> V_163 [ V_159 ] . V_85 . V_85 . V_88 = V_134 ;
V_7 -> V_163 [ V_159 ] . V_85 . V_130 = F_56 ;
if ( F_108 ( V_165 ) &&
V_45 & ( 1 << V_159 ) ) {
V_7 -> V_163 [ V_159 ] . V_85 . V_85 . V_88 |= V_133 ;
V_7 -> V_163 [ V_159 ] . V_85 . V_135 =
F_54 ;
}
F_70 ( & V_7 -> V_11 ,
& V_7 -> V_163 [ V_159 ] . V_85 ) ;
if ( ! V_7 -> V_34 -> V_99 )
continue;
snprintf ( V_7 -> V_164 [ V_159 ] . V_2 , V_5 ,
L_18 , V_159 ) ;
F_86 ( & V_7 -> V_164 [ V_159 ] . V_85 . V_85 ) ;
V_7 -> V_164 [ V_159 ] . V_85 . V_85 . V_2 =
V_7 -> V_164 [ V_159 ] . V_2 ;
V_7 -> V_164 [ V_159 ] . V_85 . V_85 . V_88 = V_134 ;
V_7 -> V_164 [ V_159 ] . V_85 . V_130 = F_58 ;
if ( V_7 -> V_34 -> V_98 ) {
V_7 -> V_164 [ V_159 ] . V_85 . V_85 . V_88 |= V_133 ;
V_7 -> V_164 [ V_159 ] . V_85 . V_135 =
F_57 ;
}
F_70 ( & V_7 -> V_11 ,
& V_7 -> V_164 [ V_159 ] . V_85 ) ;
}
return 0 ;
}
static void F_109 ( struct V_6 * V_7 )
{
int V_159 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_49 ; V_159 ++ ) {
F_88 ( & V_7 -> V_11 ,
& V_7 -> V_162 [ V_159 ] . V_85 ) ;
F_88 ( & V_7 -> V_11 ,
& V_7 -> V_163 [ V_159 ] . V_85 ) ;
if ( V_7 -> V_34 -> V_99 )
F_88 ( & V_7 -> V_11 ,
& V_7 -> V_164 [ V_159 ] . V_85 ) ;
}
F_90 ( V_7 -> V_162 ) ;
F_90 ( V_7 -> V_163 ) ;
F_90 ( V_7 -> V_164 ) ;
}
struct V_6 * F_110 ( const char * type ,
int V_49 , int V_45 , void * V_146 ,
struct V_166 * V_34 ,
struct V_53 * V_23 ,
int V_64 , int V_65 )
{
struct V_6 * V_7 ;
enum V_66 V_67 ;
int V_89 ;
int V_76 ;
int V_63 = 0 ;
struct V_1 * V_9 ;
if ( type && strlen ( type ) >= V_5 )
return F_95 ( - V_16 ) ;
if ( V_49 > V_167 || V_49 < 0 || V_45 > > V_49 )
return F_95 ( - V_16 ) ;
if ( ! V_34 )
return F_95 ( - V_16 ) ;
if ( V_49 > 0 && ( ! V_34 -> V_73 || ! V_34 -> V_70 ) )
return F_95 ( - V_16 ) ;
V_7 = F_84 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return F_95 ( - V_125 ) ;
F_98 ( & V_7 -> V_139 ) ;
F_111 ( & V_7 -> V_25 ) ;
F_97 ( & V_7 -> V_27 ) ;
V_89 = F_12 ( & V_168 , & V_149 , & V_7 -> V_28 ) ;
if ( V_89 ) {
F_90 ( V_7 ) ;
return F_95 ( V_89 ) ;
}
F_96 ( V_7 -> type , type ? : L_29 , sizeof( V_7 -> type ) ) ;
V_7 -> V_34 = V_34 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_11 . V_150 = & V_151 ;
V_7 -> V_146 = V_146 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_65 = V_65 ;
F_99 ( & V_7 -> V_11 , L_33 , V_7 -> V_28 ) ;
V_89 = F_100 ( & V_7 -> V_11 ) ;
if ( V_89 ) {
F_15 ( & V_168 , & V_149 , V_7 -> V_28 ) ;
F_90 ( V_7 ) ;
return F_95 ( V_89 ) ;
}
if ( type ) {
V_89 = F_70 ( & V_7 -> V_11 , & V_169 ) ;
if ( V_89 )
goto V_170;
}
V_89 = F_70 ( & V_7 -> V_11 , & V_171 ) ;
if ( V_89 )
goto V_170;
if ( V_34 -> V_90 ) {
V_89 = F_70 ( & V_7 -> V_11 , & V_172 ) ;
if ( V_89 )
goto V_170;
}
V_89 = F_107 ( V_7 , V_45 ) ;
if ( V_89 )
goto V_170;
for ( V_76 = 0 ; V_76 < V_49 ; V_76 ++ ) {
V_7 -> V_34 -> V_73 ( V_7 , V_76 , & V_67 ) ;
if ( V_67 == V_95 )
V_63 = 1 ;
}
if ( ! V_63 ) {
V_89 = F_70 ( & V_7 -> V_11 , & V_173 ) ;
if ( V_89 )
goto V_170;
}
#ifdef F_39
V_89 = F_70 ( & V_7 -> V_11 , & V_174 ) ;
if ( V_89 )
goto V_170;
#endif
V_89 = F_70 ( & V_7 -> V_11 , & V_175 ) ;
if ( V_89 )
goto V_170;
V_89 = F_68 ( & V_7 -> V_11 ) ;
if ( V_89 )
goto V_170;
F_7 ( & V_17 ) ;
if ( V_7 -> V_23 )
V_9 = F_1 ( V_7 -> V_23 -> V_24 ) ;
else
V_9 = V_4 ;
V_89 = F_5 ( V_7 , V_9 ) ;
if ( V_89 ) {
F_9 ( & V_17 ) ;
goto V_170;
}
F_9 ( & V_17 ) ;
if ( ! V_7 -> V_23 || ! V_7 -> V_23 -> V_176 ) {
V_89 = F_112 ( V_7 ) ;
if ( V_89 )
goto V_170;
}
F_7 ( & V_22 ) ;
F_87 ( & V_7 -> V_154 , & V_177 ) ;
F_9 ( & V_22 ) ;
F_25 ( V_7 ) ;
F_113 ( & ( V_7 -> V_62 ) , F_46 ) ;
if ( ! V_7 -> V_34 -> V_78 )
F_26 ( V_7 , 0 ) ;
F_45 ( V_7 ) ;
return V_7 ;
V_170:
F_15 ( & V_168 , & V_149 , V_7 -> V_28 ) ;
F_104 ( & V_7 -> V_11 ) ;
return F_95 ( V_89 ) ;
}
void F_114 ( struct V_6 * V_7 )
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
F_11 ( & V_7 -> V_154 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_7 -> V_34 -> V_142 ) {
V_7 -> V_34 -> V_142 ( V_7 , V_43 ) ;
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
F_88 ( & V_7 -> V_11 , & V_169 ) ;
F_88 ( & V_7 -> V_11 , & V_171 ) ;
if ( V_7 -> V_34 -> V_90 )
F_88 ( & V_7 -> V_11 , & V_172 ) ;
F_88 ( & V_7 -> V_11 , & V_175 ) ;
F_109 ( V_7 ) ;
F_5 ( V_7 , NULL ) ;
F_115 ( V_7 ) ;
F_15 ( & V_168 , & V_149 , V_7 -> V_28 ) ;
F_116 ( & V_7 -> V_25 ) ;
F_117 ( & V_7 -> V_27 ) ;
F_104 ( & V_7 -> V_11 ) ;
return;
}
struct V_6 * F_118 ( const char * V_2 )
{
struct V_6 * V_3 = NULL , * V_178 = F_95 ( - V_16 ) ;
unsigned int V_179 = 0 ;
if ( ! V_2 )
goto exit;
F_7 ( & V_22 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! strncasecmp ( V_2 , V_3 -> type , V_5 ) ) {
V_179 ++ ;
V_178 = V_3 ;
}
F_9 ( & V_22 ) ;
if ( V_179 == 0 )
V_178 = F_95 ( - V_143 ) ;
else if ( V_179 > 1 )
V_178 = F_95 ( - V_137 ) ;
exit:
return V_178 ;
}
int F_119 ( struct V_6 * V_7 ,
enum V_180 V_181 )
{
struct V_182 * V_183 ;
struct V_184 * V_85 ;
struct V_185 * V_186 ;
void * V_187 ;
int V_160 ;
int V_89 ;
static unsigned int V_188 ;
if ( ! V_7 )
return - V_16 ;
V_160 = F_120 ( sizeof( struct V_185 ) ) +
F_120 ( 0 ) ;
V_183 = F_121 ( V_160 , V_189 ) ;
if ( ! V_183 )
return - V_125 ;
V_187 = F_122 ( V_183 , 0 , V_188 ++ ,
& V_190 , 0 ,
V_191 ) ;
if ( ! V_187 ) {
F_123 ( V_183 ) ;
return - V_125 ;
}
V_85 = F_124 ( V_183 , V_192 ,
sizeof( struct V_185 ) ) ;
if ( ! V_85 ) {
F_123 ( V_183 ) ;
return - V_16 ;
}
V_186 = F_125 ( V_85 ) ;
if ( ! V_186 ) {
F_123 ( V_183 ) ;
return - V_16 ;
}
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
V_186 -> V_193 = V_7 -> V_28 ;
V_186 -> V_181 = V_181 ;
F_126 ( V_183 , V_187 ) ;
V_89 = F_127 ( & V_190 , V_183 , 0 ,
0 , V_189 ) ;
if ( V_89 )
F_4 ( & V_7 -> V_11 , L_34 , V_89 ) ;
return V_89 ;
}
static int F_128 ( void )
{
return F_129 ( & V_190 ) ;
}
static void F_130 ( void )
{
F_131 ( & V_190 ) ;
}
static inline int F_128 ( void ) { return 0 ; }
static inline void F_130 ( void ) {}
static int T_4 F_132 ( void )
{
int V_89 ;
V_89 = F_133 () ;
if ( V_89 )
return V_89 ;
V_89 = F_134 () ;
if ( V_89 )
return V_89 ;
V_89 = F_135 () ;
if ( V_89 )
return V_89 ;
V_89 = F_136 () ;
if ( V_89 )
return V_89 ;
return F_137 () ;
}
static void F_138 ( void )
{
F_139 () ;
F_140 () ;
F_141 () ;
F_142 () ;
F_143 () ;
}
static int T_4 F_144 ( void )
{
int V_89 ;
V_89 = F_132 () ;
if ( V_89 )
goto error;
V_89 = F_145 ( & V_151 ) ;
if ( V_89 )
goto V_194;
V_89 = F_128 () ;
if ( V_89 )
goto V_195;
V_89 = F_146 () ;
if ( V_89 )
goto V_196;
return 0 ;
V_196:
F_130 () ;
V_195:
F_147 ( & V_151 ) ;
V_194:
F_138 () ;
error:
F_116 ( & V_168 ) ;
F_116 ( & V_148 ) ;
F_117 ( & V_149 ) ;
F_117 ( & V_22 ) ;
F_117 ( & V_17 ) ;
return V_89 ;
}
static void T_5 F_148 ( void )
{
F_149 () ;
F_130 () ;
F_147 ( & V_151 ) ;
F_138 () ;
F_116 ( & V_168 ) ;
F_116 ( & V_148 ) ;
F_117 ( & V_149 ) ;
F_117 ( & V_22 ) ;
F_117 ( & V_17 ) ;
}
