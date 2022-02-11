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
int V_21 ;
if ( V_19 )
F_5 ( V_19 ) ;
V_21 = F_11 ( V_17 , NULL , 0 , 0 , V_22 ) ;
if ( V_19 )
F_7 ( V_19 ) ;
if ( F_12 ( V_21 < 0 ) )
return V_21 ;
* V_20 = V_21 ;
return 0 ;
}
static void F_13 ( struct V_17 * V_17 , struct V_18 * V_19 , int V_20 )
{
if ( V_19 )
F_5 ( V_19 ) ;
F_14 ( V_17 , V_20 ) ;
if ( V_19 )
F_7 ( V_19 ) ;
}
int F_15 ( struct V_7 * V_23 , int V_24 )
{
enum V_25 V_26 ;
if ( V_23 -> V_27 || ! V_23 -> V_28 -> V_29 ||
V_23 -> V_28 -> V_29 ( V_23 , V_24 , & V_26 ) ) {
if ( V_23 -> V_30 > V_23 -> V_31 )
V_26 = V_32 ;
else if ( V_23 -> V_30 < V_23 -> V_31 )
V_26 = V_33 ;
else
V_26 = V_34 ;
}
return V_26 ;
}
struct V_35 * F_16 ( struct V_7 * V_23 ,
struct V_36 * V_37 , int V_24 )
{
struct V_35 * V_3 = NULL ;
struct V_35 * V_38 = NULL ;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_37 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_37 == V_37 ) {
V_38 = V_3 ;
break;
}
}
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
return V_38 ;
}
static void F_17 ( struct V_7 * V_23 ,
struct V_36 * V_37 , int V_21 )
{
F_18 ( & V_23 -> V_39 , L_1 ,
V_23 -> type , V_37 -> type , V_21 ) ;
}
static void F_19 ( struct V_7 * V_23 , int V_40 ,
struct V_36 * V_37 ,
unsigned long * V_41 )
{
int V_42 , V_21 ;
for ( V_42 = 0 ; V_42 < V_23 -> V_43 ; V_42 ++ ) {
if ( V_40 & ( 1 << V_42 ) ) {
unsigned long V_44 , V_45 ;
V_44 = V_46 ;
V_45 = V_46 ;
if ( V_41 ) {
V_45 = V_41 [ V_42 * 2 ] ;
V_44 = V_41 [ V_42 * 2 + 1 ] ;
}
V_21 = F_20 ( V_23 , V_42 , V_37 ,
V_44 , V_45 ) ;
if ( V_21 )
F_17 ( V_23 , V_37 , V_21 ) ;
}
}
}
static void F_21 ( struct V_7 * V_23 , int V_40 ,
struct V_36 * V_37 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_23 -> V_43 ; V_42 ++ )
if ( V_40 & ( 1 << V_42 ) )
F_22 ( V_23 , V_42 , V_37 ) ;
}
static void F_23 ( struct V_36 * V_37 )
{
int V_42 , V_21 ;
const struct V_47 * V_14 ;
struct V_7 * V_3 = NULL ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_14 && ! V_3 -> V_28 -> V_48 )
continue;
if ( V_3 -> V_28 -> V_48 ) {
V_21 = V_3 -> V_28 -> V_48 ( V_3 , V_37 ) ;
if ( V_21 )
F_17 ( V_3 , V_37 , V_21 ) ;
continue;
}
V_14 = V_3 -> V_14 ;
if ( ! V_14 || ! V_14 -> V_49 )
continue;
for ( V_42 = 0 ; V_42 < V_14 -> V_50 ; V_42 ++ ) {
if ( V_14 -> V_49 [ V_42 ] . V_37 || ! V_14 -> V_49 [ V_42 ] . V_51 )
continue;
if ( V_14 -> V_49 [ V_42 ] . V_51 ( V_3 , V_37 ) )
continue;
V_14 -> V_49 [ V_42 ] . V_37 = V_37 ;
F_19 ( V_3 , V_14 -> V_49 [ V_42 ] . V_52 , V_37 ,
V_14 -> V_49 [ V_42 ] . V_53 ) ;
}
}
F_7 ( & V_13 ) ;
}
static void F_24 ( struct V_7 * V_23 )
{
int V_42 , V_21 ;
struct V_36 * V_3 = NULL ;
const struct V_47 * V_14 = V_23 -> V_14 ;
if ( ! V_14 && ! V_23 -> V_28 -> V_48 )
return;
F_5 ( & V_13 ) ;
if ( V_23 -> V_28 -> V_48 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_21 = V_23 -> V_28 -> V_48 ( V_23 , V_3 ) ;
if ( V_21 )
F_17 ( V_23 , V_3 , V_21 ) ;
}
goto exit;
}
if ( ! V_14 || ! V_14 -> V_49 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_42 = 0 ; V_42 < V_14 -> V_50 ; V_42 ++ ) {
if ( V_14 -> V_49 [ V_42 ] . V_37 || ! V_14 -> V_49 [ V_42 ] . V_51 )
continue;
if ( V_14 -> V_49 [ V_42 ] . V_51 ( V_23 , V_3 ) )
continue;
V_14 -> V_49 [ V_42 ] . V_37 = V_3 ;
F_19 ( V_23 , V_14 -> V_49 [ V_42 ] . V_52 , V_3 ,
V_14 -> V_49 [ V_42 ] . V_53 ) ;
}
}
exit:
F_7 ( & V_13 ) ;
}
static void F_25 ( struct V_7 * V_23 ,
int V_54 )
{
if ( V_54 > 1000 )
F_26 ( V_55 , & V_23 -> V_56 ,
F_27 ( F_28 ( V_54 ) ) ) ;
else if ( V_54 )
F_26 ( V_55 , & V_23 -> V_56 ,
F_28 ( V_54 ) ) ;
else
F_29 ( & V_23 -> V_56 ) ;
}
static void F_30 ( struct V_7 * V_23 )
{
F_5 ( & V_23 -> V_19 ) ;
if ( V_23 -> V_57 )
F_25 ( V_23 , V_23 -> V_58 ) ;
else if ( V_23 -> V_59 )
F_25 ( V_23 , V_23 -> V_59 ) ;
else
F_25 ( V_23 , 0 ) ;
F_7 ( & V_23 -> V_19 ) ;
}
static void F_31 ( struct V_7 * V_23 ,
int V_24 , enum V_60 V_61 )
{
if ( V_23 -> V_5 )
V_23 -> V_5 -> V_62 ( V_23 , V_24 ) ;
}
static void F_32 ( struct V_7 * V_23 ,
int V_24 , enum V_60 V_61 )
{
long V_63 ;
V_23 -> V_28 -> V_64 ( V_23 , V_24 , & V_63 ) ;
if ( V_23 -> V_30 < V_63 )
return;
if ( V_23 -> V_28 -> V_65 )
V_23 -> V_28 -> V_65 ( V_23 , V_24 , V_61 ) ;
if ( V_61 == V_66 ) {
F_33 ( & V_23 -> V_39 ,
L_2 ,
V_23 -> V_30 / 1000 ) ;
F_34 ( true ) ;
}
}
static void F_35 ( struct V_7 * V_23 , int V_24 )
{
enum V_60 type ;
V_23 -> V_28 -> V_67 ( V_23 , V_24 , & type ) ;
if ( type == V_66 || type == V_68 )
F_32 ( V_23 , V_24 , type ) ;
else
F_31 ( V_23 , V_24 , type ) ;
F_30 ( V_23 ) ;
}
int F_36 ( struct V_7 * V_23 , unsigned long * V_69 )
{
int V_21 = - V_8 ;
#ifdef F_37
int V_70 ;
unsigned long V_71 = - 1UL ;
enum V_60 type ;
#endif
if ( ! V_23 || F_38 ( V_23 ) )
goto exit;
F_5 ( & V_23 -> V_19 ) ;
V_21 = V_23 -> V_28 -> V_72 ( V_23 , V_69 ) ;
#ifdef F_37
if ( ! V_23 -> V_27 )
goto V_73;
for ( V_70 = 0 ; V_70 < V_23 -> V_43 ; V_70 ++ ) {
V_21 = V_23 -> V_28 -> V_67 ( V_23 , V_70 , & type ) ;
if ( ! V_21 && type == V_66 ) {
V_21 = V_23 -> V_28 -> V_64 ( V_23 , V_70 , & V_71 ) ;
break;
}
}
if ( V_21 )
goto V_73;
if ( * V_69 < V_71 )
* V_69 = V_23 -> V_27 ;
V_73:
#endif
F_7 ( & V_23 -> V_19 ) ;
exit:
return V_21 ;
}
static void F_39 ( struct V_7 * V_23 )
{
long V_69 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_69 ) ;
if ( V_21 ) {
F_40 ( & V_23 -> V_39 , L_3 ,
V_23 -> V_20 ) ;
return;
}
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_31 = V_23 -> V_30 ;
V_23 -> V_30 = V_69 ;
F_7 ( & V_23 -> V_19 ) ;
}
void F_41 ( struct V_7 * V_23 )
{
int V_70 ;
F_39 ( V_23 ) ;
for ( V_70 = 0 ; V_70 < V_23 -> V_43 ; V_70 ++ )
F_35 ( V_23 , V_70 ) ;
}
static void F_42 ( struct V_74 * V_75 )
{
struct V_7 * V_23 = F_43 ( V_75 , struct
V_7 ,
V_56 . V_75 ) ;
F_41 ( V_23 ) ;
}
static T_1
F_44 ( struct V_39 * V_76 , struct V_77 * V_78 , char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
return sprintf ( V_79 , L_4 , V_23 -> type ) ;
}
static T_1
F_46 ( struct V_39 * V_76 , struct V_77 * V_78 , char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
long V_30 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_79 , L_5 , V_30 ) ;
}
static T_1
F_47 ( struct V_39 * V_76 , struct V_77 * V_78 , char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
enum V_80 V_81 ;
int V_82 ;
if ( ! V_23 -> V_28 -> V_83 )
return - V_84 ;
V_82 = V_23 -> V_28 -> V_83 ( V_23 , & V_81 ) ;
if ( V_82 )
return V_82 ;
return sprintf ( V_79 , L_4 , V_81 == V_85 ? L_6
: L_7 ) ;
}
static T_1
F_48 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_82 ;
if ( ! V_23 -> V_28 -> V_86 )
return - V_84 ;
if ( ! strncmp ( V_79 , L_6 , sizeof( L_6 ) - 1 ) )
V_82 = V_23 -> V_28 -> V_86 ( V_23 , V_85 ) ;
else if ( ! strncmp ( V_79 , L_7 , sizeof( L_7 ) - 1 ) )
V_82 = V_23 -> V_28 -> V_86 ( V_23 , V_87 ) ;
else
V_82 = - V_8 ;
if ( V_82 )
return V_82 ;
return V_70 ;
}
static T_1
F_49 ( struct V_39 * V_76 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
enum V_60 type ;
int V_24 , V_82 ;
if ( ! V_23 -> V_28 -> V_67 )
return - V_84 ;
if ( ! sscanf ( V_78 -> V_78 . V_2 , L_8 , & V_24 ) )
return - V_8 ;
V_82 = V_23 -> V_28 -> V_67 ( V_23 , V_24 , & type ) ;
if ( V_82 )
return V_82 ;
switch ( type ) {
case V_66 :
return sprintf ( V_79 , L_9 ) ;
case V_68 :
return sprintf ( V_79 , L_10 ) ;
case V_88 :
return sprintf ( V_79 , L_11 ) ;
case V_89 :
return sprintf ( V_79 , L_12 ) ;
default:
return sprintf ( V_79 , L_13 ) ;
}
}
static T_1
F_50 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_90 )
return - V_84 ;
if ( ! sscanf ( V_78 -> V_78 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
if ( F_51 ( V_79 , 10 , & V_30 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_90 ( V_23 , V_24 , V_30 ) ;
return V_21 ? V_21 : V_70 ;
}
static T_1
F_52 ( struct V_39 * V_76 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_24 , V_21 ;
long V_30 ;
if ( ! V_23 -> V_28 -> V_64 )
return - V_84 ;
if ( ! sscanf ( V_78 -> V_78 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_64 ( V_23 , V_24 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_79 , L_5 , V_30 ) ;
}
static T_1
F_53 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_91 )
return - V_84 ;
if ( ! sscanf ( V_78 -> V_78 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
if ( F_51 ( V_79 , 10 , & V_30 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_91 ( V_23 , V_24 , V_30 ) ;
return V_21 ? V_21 : V_70 ;
}
static T_1
F_54 ( struct V_39 * V_76 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_92 )
return - V_84 ;
if ( ! sscanf ( V_78 -> V_78 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_92 ( V_23 , V_24 , & V_30 ) ;
return V_21 ? V_21 : sprintf ( V_79 , L_5 , V_30 ) ;
}
static T_1
F_55 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
struct V_36 * V_37 = NULL ;
int V_93 ;
if ( ! sscanf ( V_79 , L_16 , & V_93 ) )
return - V_8 ;
if ( V_93 && V_93 < 1000 )
return - V_8 ;
if ( V_93 && ! V_23 -> V_94 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_37 -> type ,
sizeof( L_17 ) ) )
F_20 ( V_23 ,
V_95 , V_37 ,
V_46 ,
V_46 ) ;
}
F_7 ( & V_13 ) ;
if ( ! V_23 -> V_58 )
V_23 -> V_58 = 1000 ;
} else if ( ! V_93 && V_23 -> V_94 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_37 -> type ,
sizeof( L_17 ) ) )
F_22 ( V_23 ,
V_95 ,
V_37 ) ;
}
F_7 ( & V_13 ) ;
V_23 -> V_58 = 0 ;
}
V_23 -> V_94 = V_93 ;
F_41 ( V_23 ) ;
return V_70 ;
}
static T_1
F_56 ( struct V_39 * V_76 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
return sprintf ( V_79 , L_16 , V_23 -> V_94 ) ;
}
static T_1
F_57 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
int V_21 = - V_8 ;
struct V_7 * V_23 = F_45 ( V_76 ) ;
struct V_1 * V_96 ;
char V_2 [ V_4 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_18 , V_79 ) ;
F_5 ( & V_9 ) ;
V_96 = F_1 ( F_58 ( V_2 ) ) ;
if ( ! V_96 )
goto exit;
V_23 -> V_5 = V_96 ;
V_21 = V_70 ;
exit:
F_7 ( & V_9 ) ;
return V_21 ;
}
static T_1
F_59 ( struct V_39 * V_76 , struct V_77 * V_97 , char * V_79 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
return sprintf ( V_79 , L_4 , V_23 -> V_5 -> V_2 ) ;
}
static T_1
F_60 ( struct V_39 * V_76 , struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_7 * V_23 = F_45 ( V_76 ) ;
int V_21 = 0 ;
unsigned long V_30 ;
if ( F_51 ( V_79 , 10 , & V_30 ) )
return - V_8 ;
if ( ! V_23 -> V_28 -> V_98 ) {
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_27 = V_30 ;
F_7 ( & V_23 -> V_19 ) ;
} else {
V_21 = V_23 -> V_28 -> V_98 ( V_23 , V_30 ) ;
}
return V_21 ? V_21 : V_70 ;
}
static T_1
F_61 ( struct V_39 * V_76 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_36 * V_37 = F_62 ( V_76 ) ;
return sprintf ( V_79 , L_4 , V_37 -> type ) ;
}
static T_1
F_63 ( struct V_39 * V_76 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_36 * V_37 = F_62 ( V_76 ) ;
unsigned long V_93 ;
int V_21 ;
V_21 = V_37 -> V_28 -> V_99 ( V_37 , & V_93 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_79 , L_5 , V_93 ) ;
}
static T_1
F_64 ( struct V_39 * V_76 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_36 * V_37 = F_62 ( V_76 ) ;
unsigned long V_93 ;
int V_21 ;
V_21 = V_37 -> V_28 -> V_100 ( V_37 , & V_93 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_79 , L_5 , V_93 ) ;
}
static T_1
F_65 ( struct V_39 * V_76 ,
struct V_77 * V_78 ,
const char * V_79 , T_2 V_70 )
{
struct V_36 * V_37 = F_62 ( V_76 ) ;
unsigned long V_93 ;
int V_82 ;
if ( ! sscanf ( V_79 , L_5 , & V_93 ) )
return - V_8 ;
if ( ( long ) V_93 < 0 )
return - V_8 ;
V_82 = V_37 -> V_28 -> V_101 ( V_37 , V_93 ) ;
if ( V_82 )
return V_82 ;
return V_70 ;
}
static T_1
F_66 ( struct V_39 * V_76 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_35 * V_102 ;
V_102 =
F_43 ( V_78 , struct V_35 , V_78 ) ;
if ( V_102 -> V_24 == V_95 )
return sprintf ( V_79 , L_19 ) ;
else
return sprintf ( V_79 , L_16 , V_102 -> V_24 ) ;
}
int F_20 ( struct V_7 * V_23 ,
int V_24 ,
struct V_36 * V_37 ,
unsigned long V_44 , unsigned long V_45 )
{
struct V_35 * V_76 ;
struct V_35 * V_3 ;
struct V_7 * V_103 ;
struct V_36 * V_104 ;
unsigned long V_105 ;
int V_82 ;
if ( V_24 >= V_23 -> V_43 || ( V_24 < 0 && V_24 != V_95 ) )
return - V_8 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_103 == V_23 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_104 == V_37 )
break;
}
if ( V_23 != V_103 || V_37 != V_104 )
return - V_8 ;
V_37 -> V_28 -> V_99 ( V_37 , & V_105 ) ;
V_45 = V_45 == V_46 ? 0 : V_45 ;
V_44 = V_44 == V_46 ? V_105 : V_44 ;
if ( V_45 > V_44 || V_44 > V_105 )
return - V_8 ;
V_76 =
F_67 ( sizeof( struct V_35 ) , V_22 ) ;
if ( ! V_76 )
return - V_106 ;
V_76 -> V_23 = V_23 ;
V_76 -> V_37 = V_37 ;
V_76 -> V_24 = V_24 ;
V_76 -> V_44 = V_44 ;
V_76 -> V_45 = V_45 ;
V_76 -> V_107 = V_108 ;
V_82 = F_10 ( & V_23 -> V_17 , & V_23 -> V_19 , & V_76 -> V_20 ) ;
if ( V_82 )
goto V_109;
sprintf ( V_76 -> V_2 , L_20 , V_76 -> V_20 ) ;
V_82 =
F_68 ( & V_23 -> V_39 . V_110 , & V_37 -> V_39 . V_110 , V_76 -> V_2 ) ;
if ( V_82 )
goto F_13;
sprintf ( V_76 -> V_111 , L_21 , V_76 -> V_20 ) ;
F_69 ( & V_76 -> V_78 . V_78 ) ;
V_76 -> V_78 . V_78 . V_2 = V_76 -> V_111 ;
V_76 -> V_78 . V_78 . V_81 = 0444 ;
V_76 -> V_78 . V_112 = F_66 ;
V_82 = F_70 ( & V_23 -> V_39 , & V_76 -> V_78 ) ;
if ( V_82 )
goto V_113;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_37 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_37 == V_37 ) {
V_82 = - V_114 ;
break;
}
if ( ! V_82 ) {
F_71 ( & V_76 -> V_115 , & V_23 -> V_116 ) ;
F_71 ( & V_76 -> V_117 , & V_37 -> V_116 ) ;
}
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
if ( ! V_82 )
return 0 ;
F_72 ( & V_23 -> V_39 , & V_76 -> V_78 ) ;
V_113:
F_73 ( & V_23 -> V_39 . V_110 , V_76 -> V_2 ) ;
F_13:
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_76 -> V_20 ) ;
V_109:
F_74 ( V_76 ) ;
return V_82 ;
}
int F_22 ( struct V_7 * V_23 ,
int V_24 ,
struct V_36 * V_37 )
{
struct V_35 * V_3 , * V_118 ;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_37 -> V_19 ) ;
F_75 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_37 == V_37 ) {
F_9 ( & V_3 -> V_115 ) ;
F_9 ( & V_3 -> V_117 ) ;
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
goto V_119;
}
}
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
return - V_120 ;
V_119:
F_72 ( & V_23 -> V_39 , & V_3 -> V_78 ) ;
F_73 ( & V_23 -> V_39 . V_110 , V_3 -> V_2 ) ;
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_3 -> V_20 ) ;
F_74 ( V_3 ) ;
return 0 ;
}
static void F_76 ( struct V_39 * V_76 )
{
struct V_7 * V_23 ;
struct V_36 * V_37 ;
if ( ! strncmp ( F_77 ( V_76 ) , L_22 ,
sizeof( L_22 ) - 1 ) ) {
V_23 = F_45 ( V_76 ) ;
F_74 ( V_23 ) ;
} else if( ! strncmp ( F_77 ( V_76 ) , L_23 ,
sizeof( L_23 ) - 1 ) ) {
V_37 = F_62 ( V_76 ) ;
F_74 ( V_37 ) ;
}
}
struct V_36 *
F_78 ( char * type , void * V_121 ,
const struct V_122 * V_28 )
{
struct V_36 * V_37 ;
int V_82 ;
if ( type && strlen ( type ) >= V_4 )
return F_79 ( - V_8 ) ;
if ( ! V_28 || ! V_28 -> V_99 || ! V_28 -> V_100 ||
! V_28 -> V_101 )
return F_79 ( - V_8 ) ;
V_37 = F_67 ( sizeof( struct V_36 ) , V_22 ) ;
if ( ! V_37 )
return F_79 ( - V_106 ) ;
V_82 = F_10 ( & V_123 , & V_124 , & V_37 -> V_20 ) ;
if ( V_82 ) {
F_74 ( V_37 ) ;
return F_79 ( V_82 ) ;
}
F_80 ( V_37 -> type , type ? : L_24 , sizeof( V_37 -> type ) ) ;
F_81 ( & V_37 -> V_19 ) ;
F_82 ( & V_37 -> V_116 ) ;
V_37 -> V_28 = V_28 ;
V_37 -> V_125 = true ;
V_37 -> V_39 . V_126 = & V_127 ;
V_37 -> V_121 = V_121 ;
F_83 ( & V_37 -> V_39 , L_25 , V_37 -> V_20 ) ;
V_82 = F_84 ( & V_37 -> V_39 ) ;
if ( V_82 ) {
F_13 ( & V_123 , & V_124 , V_37 -> V_20 ) ;
F_74 ( V_37 ) ;
return F_79 ( V_82 ) ;
}
if ( type ) {
V_82 = F_70 ( & V_37 -> V_39 , & V_128 ) ;
if ( V_82 )
goto V_129;
}
V_82 = F_70 ( & V_37 -> V_39 , & V_130 ) ;
if ( V_82 )
goto V_129;
V_82 = F_70 ( & V_37 -> V_39 , & V_131 ) ;
if ( V_82 )
goto V_129;
F_5 ( & V_13 ) ;
F_6 ( & V_37 -> V_132 , & V_133 ) ;
F_7 ( & V_13 ) ;
F_23 ( V_37 ) ;
return V_37 ;
V_129:
F_13 ( & V_123 , & V_124 , V_37 -> V_20 ) ;
F_85 ( & V_37 -> V_39 ) ;
return F_79 ( V_82 ) ;
}
void F_86 ( struct V_36 * V_37 )
{
int V_42 ;
const struct V_47 * V_14 ;
struct V_7 * V_23 ;
struct V_36 * V_3 = NULL ;
if ( ! V_37 )
return;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_37 )
break;
if ( V_3 != V_37 ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_37 -> V_132 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_23 -> V_28 -> V_119 ) {
V_23 -> V_28 -> V_119 ( V_23 , V_37 ) ;
continue;
}
if ( ! V_23 -> V_14 || ! V_23 -> V_14 -> V_49 )
continue;
V_14 = V_23 -> V_14 ;
for ( V_42 = 0 ; V_42 < V_14 -> V_50 ; V_42 ++ ) {
if ( V_14 -> V_49 [ V_42 ] . V_37 == V_37 ) {
F_21 ( V_23 , V_14 -> V_49 [ V_42 ] . V_52 , V_37 ) ;
V_14 -> V_49 [ V_42 ] . V_37 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
if ( V_37 -> type [ 0 ] )
F_72 ( & V_37 -> V_39 , & V_128 ) ;
F_72 ( & V_37 -> V_39 , & V_130 ) ;
F_72 ( & V_37 -> V_39 , & V_131 ) ;
F_13 ( & V_123 , & V_124 , V_37 -> V_20 ) ;
F_85 ( & V_37 -> V_39 ) ;
return;
}
void F_87 ( struct V_36 * V_37 )
{
struct V_35 * V_102 ;
unsigned long V_107 = 0 ;
if ( V_37 -> V_125 )
return;
F_5 ( & V_37 -> V_19 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
if ( V_102 -> V_107 == V_108 )
continue;
if ( V_102 -> V_107 > V_107 )
V_107 = V_102 -> V_107 ;
}
F_7 ( & V_37 -> V_19 ) ;
V_37 -> V_28 -> V_101 ( V_37 , V_107 ) ;
V_37 -> V_125 = true ;
}
void F_88 ( struct V_7 * V_23 , int V_24 )
{
F_35 ( V_23 , V_24 ) ;
}
static int F_89 ( struct V_7 * V_23 , int V_40 )
{
int V_134 ;
int V_135 = sizeof( struct V_136 ) * V_23 -> V_43 ;
V_23 -> V_137 = F_67 ( V_135 , V_22 ) ;
if ( ! V_23 -> V_137 )
return - V_106 ;
V_23 -> V_138 = F_67 ( V_135 , V_22 ) ;
if ( ! V_23 -> V_138 ) {
F_74 ( V_23 -> V_137 ) ;
return - V_106 ;
}
if ( V_23 -> V_28 -> V_92 ) {
V_23 -> V_139 = F_67 ( V_135 , V_22 ) ;
if ( ! V_23 -> V_139 ) {
F_74 ( V_23 -> V_137 ) ;
F_74 ( V_23 -> V_138 ) ;
return - V_106 ;
}
}
for ( V_134 = 0 ; V_134 < V_23 -> V_43 ; V_134 ++ ) {
snprintf ( V_23 -> V_137 [ V_134 ] . V_2 , V_4 ,
L_8 , V_134 ) ;
F_69 ( & V_23 -> V_137 [ V_134 ] . V_78 . V_78 ) ;
V_23 -> V_137 [ V_134 ] . V_78 . V_78 . V_2 =
V_23 -> V_137 [ V_134 ] . V_2 ;
V_23 -> V_137 [ V_134 ] . V_78 . V_78 . V_81 = V_140 ;
V_23 -> V_137 [ V_134 ] . V_78 . V_112 = F_49 ;
F_70 ( & V_23 -> V_39 ,
& V_23 -> V_137 [ V_134 ] . V_78 ) ;
snprintf ( V_23 -> V_138 [ V_134 ] . V_2 , V_4 ,
L_14 , V_134 ) ;
F_69 ( & V_23 -> V_138 [ V_134 ] . V_78 . V_78 ) ;
V_23 -> V_138 [ V_134 ] . V_78 . V_78 . V_2 =
V_23 -> V_138 [ V_134 ] . V_2 ;
V_23 -> V_138 [ V_134 ] . V_78 . V_78 . V_81 = V_140 ;
V_23 -> V_138 [ V_134 ] . V_78 . V_112 = F_52 ;
if ( V_40 & ( 1 << V_134 ) ) {
V_23 -> V_138 [ V_134 ] . V_78 . V_78 . V_81 |= V_141 ;
V_23 -> V_138 [ V_134 ] . V_78 . V_142 =
F_50 ;
}
F_70 ( & V_23 -> V_39 ,
& V_23 -> V_138 [ V_134 ] . V_78 ) ;
if ( ! V_23 -> V_28 -> V_92 )
continue;
snprintf ( V_23 -> V_139 [ V_134 ] . V_2 , V_4 ,
L_15 , V_134 ) ;
F_69 ( & V_23 -> V_139 [ V_134 ] . V_78 . V_78 ) ;
V_23 -> V_139 [ V_134 ] . V_78 . V_78 . V_2 =
V_23 -> V_139 [ V_134 ] . V_2 ;
V_23 -> V_139 [ V_134 ] . V_78 . V_78 . V_81 = V_140 ;
V_23 -> V_139 [ V_134 ] . V_78 . V_112 = F_54 ;
if ( V_23 -> V_28 -> V_91 ) {
V_23 -> V_139 [ V_134 ] . V_78 . V_78 . V_81 |= V_141 ;
V_23 -> V_139 [ V_134 ] . V_78 . V_142 =
F_53 ;
}
F_70 ( & V_23 -> V_39 ,
& V_23 -> V_139 [ V_134 ] . V_78 ) ;
}
return 0 ;
}
static void F_90 ( struct V_7 * V_23 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_23 -> V_43 ; V_134 ++ ) {
F_72 ( & V_23 -> V_39 ,
& V_23 -> V_137 [ V_134 ] . V_78 ) ;
F_72 ( & V_23 -> V_39 ,
& V_23 -> V_138 [ V_134 ] . V_78 ) ;
if ( V_23 -> V_28 -> V_92 )
F_72 ( & V_23 -> V_39 ,
& V_23 -> V_139 [ V_134 ] . V_78 ) ;
}
F_74 ( V_23 -> V_137 ) ;
F_74 ( V_23 -> V_138 ) ;
F_74 ( V_23 -> V_139 ) ;
}
struct V_7 * F_91 ( const char * type ,
int V_43 , int V_40 , void * V_121 ,
const struct V_143 * V_28 ,
const struct V_47 * V_14 ,
int V_58 , int V_59 )
{
struct V_7 * V_23 ;
enum V_60 V_61 ;
int V_82 ;
int V_70 ;
int V_57 = 0 ;
if ( type && strlen ( type ) >= V_4 )
return F_79 ( - V_8 ) ;
if ( V_43 > V_144 || V_43 < 0 || V_40 > > V_43 )
return F_79 ( - V_8 ) ;
if ( ! V_28 || ! V_28 -> V_72 )
return F_79 ( - V_8 ) ;
if ( V_43 > 0 && ( ! V_28 -> V_67 || ! V_28 -> V_64 ) )
return F_79 ( - V_8 ) ;
V_23 = F_67 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_23 )
return F_79 ( - V_106 ) ;
F_82 ( & V_23 -> V_116 ) ;
F_92 ( & V_23 -> V_17 ) ;
F_81 ( & V_23 -> V_19 ) ;
V_82 = F_10 ( & V_145 , & V_124 , & V_23 -> V_20 ) ;
if ( V_82 ) {
F_74 ( V_23 ) ;
return F_79 ( V_82 ) ;
}
F_80 ( V_23 -> type , type ? : L_24 , sizeof( V_23 -> type ) ) ;
V_23 -> V_28 = V_28 ;
V_23 -> V_14 = V_14 ;
V_23 -> V_39 . V_126 = & V_127 ;
V_23 -> V_121 = V_121 ;
V_23 -> V_43 = V_43 ;
V_23 -> V_58 = V_58 ;
V_23 -> V_59 = V_59 ;
F_83 ( & V_23 -> V_39 , L_26 , V_23 -> V_20 ) ;
V_82 = F_84 ( & V_23 -> V_39 ) ;
if ( V_82 ) {
F_13 ( & V_145 , & V_124 , V_23 -> V_20 ) ;
F_74 ( V_23 ) ;
return F_79 ( V_82 ) ;
}
if ( type ) {
V_82 = F_70 ( & V_23 -> V_39 , & V_146 ) ;
if ( V_82 )
goto V_129;
}
V_82 = F_70 ( & V_23 -> V_39 , & V_147 ) ;
if ( V_82 )
goto V_129;
if ( V_28 -> V_83 ) {
V_82 = F_70 ( & V_23 -> V_39 , & V_148 ) ;
if ( V_82 )
goto V_129;
}
V_82 = F_89 ( V_23 , V_40 ) ;
if ( V_82 )
goto V_129;
for ( V_70 = 0 ; V_70 < V_43 ; V_70 ++ ) {
V_23 -> V_28 -> V_67 ( V_23 , V_70 , & V_61 ) ;
if ( V_61 == V_88 )
V_57 = 1 ;
}
if ( ! V_57 ) {
V_82 = F_70 ( & V_23 -> V_39 , & V_149 ) ;
if ( V_82 )
goto V_129;
}
#ifdef F_37
V_82 = F_70 ( & V_23 -> V_39 , & V_150 ) ;
if ( V_82 )
goto V_129;
#endif
V_82 = F_70 ( & V_23 -> V_39 , & V_151 ) ;
if ( V_82 )
goto V_129;
F_5 ( & V_9 ) ;
if ( V_23 -> V_14 )
V_23 -> V_5 = F_1 ( V_23 -> V_14 -> V_15 ) ;
else
V_23 -> V_5 = F_1 ( V_16 ) ;
F_7 ( & V_9 ) ;
if ( ! V_23 -> V_14 || ! V_23 -> V_14 -> V_152 ) {
V_82 = F_93 ( V_23 ) ;
if ( V_82 )
goto V_129;
}
F_5 ( & V_13 ) ;
F_71 ( & V_23 -> V_132 , & V_153 ) ;
F_7 ( & V_13 ) ;
F_24 ( V_23 ) ;
F_94 ( & ( V_23 -> V_56 ) , F_42 ) ;
F_41 ( V_23 ) ;
if ( ! V_82 )
return V_23 ;
V_129:
F_13 ( & V_145 , & V_124 , V_23 -> V_20 ) ;
F_85 ( & V_23 -> V_39 ) ;
return F_79 ( V_82 ) ;
}
void F_95 ( struct V_7 * V_23 )
{
int V_42 ;
const struct V_47 * V_14 ;
struct V_36 * V_37 ;
struct V_7 * V_3 = NULL ;
if ( ! V_23 )
return;
V_14 = V_23 -> V_14 ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( V_3 == V_23 )
break;
if ( V_3 != V_23 ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_23 -> V_132 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_23 -> V_28 -> V_119 ) {
V_23 -> V_28 -> V_119 ( V_23 , V_37 ) ;
continue;
}
if ( ! V_14 || ! V_14 -> V_49 )
break;
for ( V_42 = 0 ; V_42 < V_14 -> V_50 ; V_42 ++ ) {
if ( V_14 -> V_49 [ V_42 ] . V_37 == V_37 ) {
F_21 ( V_23 , V_14 -> V_49 [ V_42 ] . V_52 , V_37 ) ;
V_14 -> V_49 [ V_42 ] . V_37 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
F_25 ( V_23 , 0 ) ;
if ( V_23 -> type [ 0 ] )
F_72 ( & V_23 -> V_39 , & V_146 ) ;
F_72 ( & V_23 -> V_39 , & V_147 ) ;
if ( V_23 -> V_28 -> V_83 )
F_72 ( & V_23 -> V_39 , & V_148 ) ;
F_72 ( & V_23 -> V_39 , & V_151 ) ;
F_90 ( V_23 ) ;
V_23 -> V_5 = NULL ;
F_96 ( V_23 ) ;
F_13 ( & V_145 , & V_124 , V_23 -> V_20 ) ;
F_97 ( & V_23 -> V_17 ) ;
F_98 ( & V_23 -> V_19 ) ;
F_85 ( & V_23 -> V_39 ) ;
return;
}
struct V_7 * F_99 ( const char * V_2 )
{
struct V_7 * V_3 = NULL , * V_154 = F_79 ( - V_8 ) ;
unsigned int V_155 = 0 ;
if ( ! V_2 )
goto exit;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! F_3 ( V_2 , V_3 -> type , V_4 ) ) {
V_155 ++ ;
V_154 = V_3 ;
}
F_7 ( & V_13 ) ;
if ( V_155 == 0 )
V_154 = F_79 ( - V_120 ) ;
else if ( V_155 > 1 )
V_154 = F_79 ( - V_114 ) ;
exit:
return V_154 ;
}
int F_100 ( struct V_7 * V_23 ,
enum V_156 V_157 )
{
struct V_158 * V_159 ;
struct V_160 * V_78 ;
struct V_161 * V_162 ;
void * V_163 ;
int V_135 ;
int V_82 ;
static unsigned int V_164 ;
if ( ! V_23 )
return - V_8 ;
V_135 = F_101 ( sizeof( struct V_161 ) ) +
F_101 ( 0 ) ;
V_159 = F_102 ( V_135 , V_165 ) ;
if ( ! V_159 )
return - V_106 ;
V_163 = F_103 ( V_159 , 0 , V_164 ++ ,
& V_166 , 0 ,
V_167 ) ;
if ( ! V_163 ) {
F_104 ( V_159 ) ;
return - V_106 ;
}
V_78 = F_105 ( V_159 , V_168 ,
sizeof( struct V_161 ) ) ;
if ( ! V_78 ) {
F_104 ( V_159 ) ;
return - V_8 ;
}
V_162 = F_106 ( V_78 ) ;
if ( ! V_162 ) {
F_104 ( V_159 ) ;
return - V_8 ;
}
memset ( V_162 , 0 , sizeof( struct V_161 ) ) ;
V_162 -> V_169 = V_23 -> V_20 ;
V_162 -> V_157 = V_157 ;
V_82 = F_107 ( V_159 , V_163 ) ;
if ( V_82 < 0 ) {
F_104 ( V_159 ) ;
return V_82 ;
}
V_82 = F_108 ( & V_166 , V_159 , 0 ,
0 , V_165 ) ;
if ( V_82 )
F_18 ( & V_23 -> V_39 , L_27 , V_82 ) ;
return V_82 ;
}
static int F_109 ( void )
{
return F_110 ( & V_166 ) ;
}
static void F_111 ( void )
{
F_112 ( & V_166 ) ;
}
static inline int F_109 ( void ) { return 0 ; }
static inline void F_111 ( void ) {}
static int T_3 F_113 ( void )
{
int V_82 ;
V_82 = F_114 () ;
if ( V_82 )
return V_82 ;
V_82 = F_115 () ;
if ( V_82 )
return V_82 ;
return F_116 () ;
}
static void F_117 ( void )
{
F_118 () ;
F_119 () ;
F_120 () ;
}
static int T_3 F_121 ( void )
{
int V_82 ;
V_82 = F_113 () ;
if ( V_82 )
goto error;
V_82 = F_122 ( & V_127 ) ;
if ( V_82 )
goto V_170;
V_82 = F_109 () ;
if ( V_82 )
goto V_171;
return 0 ;
V_170:
F_117 () ;
V_171:
F_123 ( & V_127 ) ;
error:
F_97 ( & V_145 ) ;
F_97 ( & V_123 ) ;
F_98 ( & V_124 ) ;
F_98 ( & V_13 ) ;
F_98 ( & V_9 ) ;
return V_82 ;
}
static void T_4 F_124 ( void )
{
F_111 () ;
F_123 ( & V_127 ) ;
F_117 () ;
F_97 ( & V_145 ) ;
F_97 ( & V_123 ) ;
F_98 ( & V_124 ) ;
F_98 ( & V_13 ) ;
F_98 ( & V_9 ) ;
}
