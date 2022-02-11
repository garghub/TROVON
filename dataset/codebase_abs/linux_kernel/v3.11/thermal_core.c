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
struct V_36 * V_37 )
{
int V_41 , V_21 ;
for ( V_41 = 0 ; V_41 < V_23 -> V_42 ; V_41 ++ ) {
if ( V_40 & ( 1 << V_41 ) ) {
V_21 = F_20 ( V_23 , V_41 , V_37 ,
V_43 , V_43 ) ;
if ( V_21 )
F_17 ( V_23 , V_37 , V_21 ) ;
}
}
}
static void F_21 ( struct V_7 * V_23 , int V_40 ,
struct V_36 * V_37 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_23 -> V_42 ; V_41 ++ )
if ( V_40 & ( 1 << V_41 ) )
F_22 ( V_23 , V_41 , V_37 ) ;
}
static void F_23 ( struct V_36 * V_37 )
{
int V_41 , V_21 ;
const struct V_44 * V_14 ;
struct V_7 * V_3 = NULL ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_14 && ! V_3 -> V_28 -> V_45 )
continue;
if ( ! V_3 -> V_14 && V_3 -> V_28 -> V_45 ) {
V_21 = V_3 -> V_28 -> V_45 ( V_3 , V_37 ) ;
if ( V_21 )
F_17 ( V_3 , V_37 , V_21 ) ;
}
V_14 = V_3 -> V_14 ;
if ( ! V_14 || ! V_14 -> V_46 )
continue;
for ( V_41 = 0 ; V_41 < V_14 -> V_47 ; V_41 ++ ) {
if ( V_14 -> V_46 [ V_41 ] . V_37 || ! V_14 -> V_46 [ V_41 ] . V_48 )
continue;
if ( V_14 -> V_46 [ V_41 ] . V_48 ( V_3 , V_37 ) )
continue;
V_14 -> V_46 [ V_41 ] . V_37 = V_37 ;
F_19 ( V_3 , V_14 -> V_46 [ V_41 ] . V_49 , V_37 ) ;
}
}
F_7 ( & V_13 ) ;
}
static void F_24 ( struct V_7 * V_23 )
{
int V_41 , V_21 ;
struct V_36 * V_3 = NULL ;
const struct V_44 * V_14 = V_23 -> V_14 ;
if ( ! V_14 && ! V_23 -> V_28 -> V_45 )
return;
F_5 ( & V_13 ) ;
if ( ! V_14 && V_23 -> V_28 -> V_45 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_21 = V_23 -> V_28 -> V_45 ( V_23 , V_3 ) ;
if ( V_21 )
F_17 ( V_23 , V_3 , V_21 ) ;
}
goto exit;
}
if ( ! V_14 || ! V_14 -> V_46 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_41 = 0 ; V_41 < V_14 -> V_47 ; V_41 ++ ) {
if ( V_14 -> V_46 [ V_41 ] . V_37 || ! V_14 -> V_46 [ V_41 ] . V_48 )
continue;
if ( V_14 -> V_46 [ V_41 ] . V_48 ( V_23 , V_3 ) )
continue;
V_14 -> V_46 [ V_41 ] . V_37 = V_3 ;
F_19 ( V_23 , V_14 -> V_46 [ V_41 ] . V_49 , V_3 ) ;
}
}
exit:
F_7 ( & V_13 ) ;
}
static void F_25 ( struct V_7 * V_23 ,
int V_50 )
{
if ( V_50 > 1000 )
F_26 ( V_51 , & V_23 -> V_52 ,
F_27 ( F_28 ( V_50 ) ) ) ;
else if ( V_50 )
F_26 ( V_51 , & V_23 -> V_52 ,
F_28 ( V_50 ) ) ;
else
F_29 ( & V_23 -> V_52 ) ;
}
static void F_30 ( struct V_7 * V_23 )
{
F_5 ( & V_23 -> V_19 ) ;
if ( V_23 -> V_53 )
F_25 ( V_23 , V_23 -> V_54 ) ;
else if ( V_23 -> V_55 )
F_25 ( V_23 , V_23 -> V_55 ) ;
else
F_25 ( V_23 , 0 ) ;
F_7 ( & V_23 -> V_19 ) ;
}
static void F_31 ( struct V_7 * V_23 ,
int V_24 , enum V_56 V_57 )
{
if ( V_23 -> V_5 )
V_23 -> V_5 -> V_58 ( V_23 , V_24 ) ;
}
static void F_32 ( struct V_7 * V_23 ,
int V_24 , enum V_56 V_57 )
{
long V_59 ;
V_23 -> V_28 -> V_60 ( V_23 , V_24 , & V_59 ) ;
if ( V_23 -> V_30 < V_59 )
return;
if ( V_23 -> V_28 -> V_61 )
V_23 -> V_28 -> V_61 ( V_23 , V_24 , V_57 ) ;
if ( V_57 == V_62 ) {
F_33 ( & V_23 -> V_39 ,
L_2 ,
V_23 -> V_30 / 1000 ) ;
F_34 ( true ) ;
}
}
static void F_35 ( struct V_7 * V_23 , int V_24 )
{
enum V_56 type ;
V_23 -> V_28 -> V_63 ( V_23 , V_24 , & type ) ;
if ( type == V_62 || type == V_64 )
F_32 ( V_23 , V_24 , type ) ;
else
F_31 ( V_23 , V_24 , type ) ;
F_30 ( V_23 ) ;
}
int F_36 ( struct V_7 * V_23 , unsigned long * V_65 )
{
int V_21 = - V_8 ;
#ifdef F_37
int V_66 ;
unsigned long V_67 = - 1UL ;
enum V_56 type ;
#endif
if ( ! V_23 || F_38 ( V_23 ) )
goto exit;
F_5 ( & V_23 -> V_19 ) ;
V_21 = V_23 -> V_28 -> V_68 ( V_23 , V_65 ) ;
#ifdef F_37
if ( ! V_23 -> V_27 )
goto V_69;
for ( V_66 = 0 ; V_66 < V_23 -> V_42 ; V_66 ++ ) {
V_21 = V_23 -> V_28 -> V_63 ( V_23 , V_66 , & type ) ;
if ( ! V_21 && type == V_62 ) {
V_21 = V_23 -> V_28 -> V_60 ( V_23 , V_66 , & V_67 ) ;
break;
}
}
if ( V_21 )
goto V_69;
if ( * V_65 < V_67 )
* V_65 = V_23 -> V_27 ;
V_69:
#endif
F_7 ( & V_23 -> V_19 ) ;
exit:
return V_21 ;
}
static void F_39 ( struct V_7 * V_23 )
{
long V_65 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_65 ) ;
if ( V_21 ) {
F_40 ( & V_23 -> V_39 , L_3 ,
V_23 -> V_20 ) ;
return;
}
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_31 = V_23 -> V_30 ;
V_23 -> V_30 = V_65 ;
F_7 ( & V_23 -> V_19 ) ;
}
void F_41 ( struct V_7 * V_23 )
{
int V_66 ;
F_39 ( V_23 ) ;
for ( V_66 = 0 ; V_66 < V_23 -> V_42 ; V_66 ++ )
F_35 ( V_23 , V_66 ) ;
}
static void F_42 ( struct V_70 * V_71 )
{
struct V_7 * V_23 = F_43 ( V_71 , struct
V_7 ,
V_52 . V_71 ) ;
F_41 ( V_23 ) ;
}
static T_1
F_44 ( struct V_39 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_23 -> type ) ;
}
static T_1
F_46 ( struct V_39 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
long V_30 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_30 ) ;
}
static T_1
F_47 ( struct V_39 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
enum V_76 V_77 ;
int V_78 ;
if ( ! V_23 -> V_28 -> V_79 )
return - V_80 ;
V_78 = V_23 -> V_28 -> V_79 ( V_23 , & V_77 ) ;
if ( V_78 )
return V_78 ;
return sprintf ( V_75 , L_4 , V_77 == V_81 ? L_6
: L_7 ) ;
}
static T_1
F_48 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_78 ;
if ( ! V_23 -> V_28 -> V_82 )
return - V_80 ;
if ( ! strncmp ( V_75 , L_6 , sizeof( L_6 ) - 1 ) )
V_78 = V_23 -> V_28 -> V_82 ( V_23 , V_81 ) ;
else if ( ! strncmp ( V_75 , L_7 , sizeof( L_7 ) - 1 ) )
V_78 = V_23 -> V_28 -> V_82 ( V_23 , V_83 ) ;
else
V_78 = - V_8 ;
if ( V_78 )
return V_78 ;
return V_66 ;
}
static T_1
F_49 ( struct V_39 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
enum V_56 type ;
int V_24 , V_78 ;
if ( ! V_23 -> V_28 -> V_63 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_8 , & V_24 ) )
return - V_8 ;
V_78 = V_23 -> V_28 -> V_63 ( V_23 , V_24 , & type ) ;
if ( V_78 )
return V_78 ;
switch ( type ) {
case V_62 :
return sprintf ( V_75 , L_9 ) ;
case V_64 :
return sprintf ( V_75 , L_10 ) ;
case V_84 :
return sprintf ( V_75 , L_11 ) ;
case V_85 :
return sprintf ( V_75 , L_12 ) ;
default:
return sprintf ( V_75 , L_13 ) ;
}
}
static T_1
F_50 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_86 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
if ( F_51 ( V_75 , 10 , & V_30 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_86 ( V_23 , V_24 , V_30 ) ;
return V_21 ? V_21 : V_66 ;
}
static T_1
F_52 ( struct V_39 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_24 , V_21 ;
long V_30 ;
if ( ! V_23 -> V_28 -> V_60 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_60 ( V_23 , V_24 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_30 ) ;
}
static T_1
F_53 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_87 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
if ( F_51 ( V_75 , 10 , & V_30 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_87 ( V_23 , V_24 , V_30 ) ;
return V_21 ? V_21 : V_66 ;
}
static T_1
F_54 ( struct V_39 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_88 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_28 -> V_88 ( V_23 , V_24 , & V_30 ) ;
return V_21 ? V_21 : sprintf ( V_75 , L_5 , V_30 ) ;
}
static T_1
F_55 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
struct V_36 * V_37 = NULL ;
int V_89 ;
if ( ! sscanf ( V_75 , L_16 , & V_89 ) )
return - V_8 ;
if ( V_89 && V_89 < 1000 )
return - V_8 ;
if ( V_89 && ! V_23 -> V_90 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_37 -> type ,
sizeof( L_17 ) ) )
F_20 ( V_23 ,
V_91 , V_37 ,
V_43 ,
V_43 ) ;
}
F_7 ( & V_13 ) ;
if ( ! V_23 -> V_54 )
V_23 -> V_54 = 1000 ;
} else if ( ! V_89 && V_23 -> V_90 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_37 -> type ,
sizeof( L_17 ) ) )
F_22 ( V_23 ,
V_91 ,
V_37 ) ;
}
F_7 ( & V_13 ) ;
V_23 -> V_54 = 0 ;
}
V_23 -> V_90 = V_89 ;
F_41 ( V_23 ) ;
return V_66 ;
}
static T_1
F_56 ( struct V_39 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
return sprintf ( V_75 , L_16 , V_23 -> V_90 ) ;
}
static T_1
F_57 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
int V_21 = - V_8 ;
struct V_7 * V_23 = F_45 ( V_72 ) ;
struct V_1 * V_92 ;
char V_2 [ V_4 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_18 , V_75 ) ;
F_5 ( & V_9 ) ;
V_92 = F_1 ( F_58 ( V_2 ) ) ;
if ( ! V_92 )
goto exit;
V_23 -> V_5 = V_92 ;
V_21 = V_66 ;
exit:
F_7 ( & V_9 ) ;
return V_21 ;
}
static T_1
F_59 ( struct V_39 * V_72 , struct V_73 * V_93 , char * V_75 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_23 -> V_5 -> V_2 ) ;
}
static T_1
F_60 ( struct V_39 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_7 * V_23 = F_45 ( V_72 ) ;
int V_21 = 0 ;
unsigned long V_30 ;
if ( F_51 ( V_75 , 10 , & V_30 ) )
return - V_8 ;
if ( ! V_23 -> V_28 -> V_94 ) {
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_27 = V_30 ;
F_7 ( & V_23 -> V_19 ) ;
} else {
V_21 = V_23 -> V_28 -> V_94 ( V_23 , V_30 ) ;
}
return V_21 ? V_21 : V_66 ;
}
static T_1
F_61 ( struct V_39 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_36 * V_37 = F_62 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_37 -> type ) ;
}
static T_1
F_63 ( struct V_39 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_36 * V_37 = F_62 ( V_72 ) ;
unsigned long V_89 ;
int V_21 ;
V_21 = V_37 -> V_28 -> V_95 ( V_37 , & V_89 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_89 ) ;
}
static T_1
F_64 ( struct V_39 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_36 * V_37 = F_62 ( V_72 ) ;
unsigned long V_89 ;
int V_21 ;
V_21 = V_37 -> V_28 -> V_96 ( V_37 , & V_89 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_89 ) ;
}
static T_1
F_65 ( struct V_39 * V_72 ,
struct V_73 * V_74 ,
const char * V_75 , T_2 V_66 )
{
struct V_36 * V_37 = F_62 ( V_72 ) ;
unsigned long V_89 ;
int V_78 ;
if ( ! sscanf ( V_75 , L_5 , & V_89 ) )
return - V_8 ;
if ( ( long ) V_89 < 0 )
return - V_8 ;
V_78 = V_37 -> V_28 -> V_97 ( V_37 , V_89 ) ;
if ( V_78 )
return V_78 ;
return V_66 ;
}
static T_1
F_66 ( struct V_39 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_35 * V_98 ;
V_98 =
F_43 ( V_74 , struct V_35 , V_74 ) ;
if ( V_98 -> V_24 == V_91 )
return sprintf ( V_75 , L_19 ) ;
else
return sprintf ( V_75 , L_16 , V_98 -> V_24 ) ;
}
static T_1
F_67 ( struct V_39 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_99 * V_100 = F_68 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_100 -> type ) ;
}
static T_1
F_69 ( struct V_39 * V_72 , struct V_73 * V_74 , char * V_75 )
{
long V_30 ;
int V_21 ;
struct V_101 * V_102
= F_43 ( V_74 , struct V_101 , V_74 ) ;
struct V_103 * V_65
= F_43 ( V_102 , struct V_103 ,
V_104 ) ;
struct V_7 * V_23 = V_65 -> V_23 ;
V_21 = F_36 ( V_23 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_30 ) ;
}
static T_1
F_70 ( struct V_39 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_101 * V_102
= F_43 ( V_74 , struct V_101 , V_74 ) ;
struct V_103 * V_65
= F_43 ( V_102 , struct V_103 ,
V_105 ) ;
struct V_7 * V_23 = V_65 -> V_23 ;
long V_30 ;
int V_21 ;
V_21 = V_23 -> V_28 -> V_60 ( V_23 , 0 , & V_30 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_30 ) ;
}
static struct V_99 *
F_71 ( const struct V_7 * V_23 )
{
struct V_99 * V_100 ;
F_5 ( & V_13 ) ;
F_2 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_100 -> type , V_23 -> type ) ) {
F_7 ( & V_13 ) ;
return V_100 ;
}
F_7 ( & V_13 ) ;
return NULL ;
}
static struct V_103 *
F_72 ( const struct V_99 * V_100 ,
const struct V_7 * V_23 )
{
struct V_103 * V_65 ;
F_5 ( & V_13 ) ;
F_2 (temp, &hwmon->tz_list, hwmon_node)
if ( V_65 -> V_23 == V_23 ) {
F_7 ( & V_13 ) ;
return V_65 ;
}
F_7 ( & V_13 ) ;
return NULL ;
}
static int
F_73 ( struct V_7 * V_23 )
{
struct V_99 * V_100 ;
struct V_103 * V_65 ;
int V_106 = 1 ;
int V_78 ;
V_100 = F_71 ( V_23 ) ;
if ( V_100 ) {
V_106 = 0 ;
goto V_107;
}
V_100 = F_74 ( sizeof( struct V_99 ) , V_22 ) ;
if ( ! V_100 )
return - V_108 ;
F_75 ( & V_100 -> V_109 ) ;
F_76 ( V_100 -> type , V_23 -> type , V_4 ) ;
V_100 -> V_39 = F_77 ( NULL ) ;
if ( F_38 ( V_100 -> V_39 ) ) {
V_78 = F_78 ( V_100 -> V_39 ) ;
goto V_110;
}
F_79 ( V_100 -> V_39 , V_100 ) ;
V_78 = F_80 ( V_100 -> V_39 , & V_111 ) ;
if ( V_78 )
goto V_110;
V_107:
V_65 = F_74 ( sizeof( struct V_103 ) , V_22 ) ;
if ( ! V_65 ) {
V_78 = - V_108 ;
goto V_112;
}
V_65 -> V_23 = V_23 ;
V_100 -> V_66 ++ ;
snprintf ( V_65 -> V_104 . V_2 , sizeof( V_65 -> V_104 . V_2 ) ,
L_20 , V_100 -> V_66 ) ;
V_65 -> V_104 . V_74 . V_74 . V_2 = V_65 -> V_104 . V_2 ;
V_65 -> V_104 . V_74 . V_74 . V_77 = 0444 ;
V_65 -> V_104 . V_74 . V_113 = F_69 ;
F_81 ( & V_65 -> V_104 . V_74 . V_74 ) ;
V_78 = F_80 ( V_100 -> V_39 , & V_65 -> V_104 . V_74 ) ;
if ( V_78 )
goto V_114;
if ( V_23 -> V_28 -> V_115 ) {
unsigned long V_30 ;
if ( ! V_23 -> V_28 -> V_115 ( V_23 , & V_30 ) ) {
snprintf ( V_65 -> V_105 . V_2 ,
sizeof( V_65 -> V_105 . V_2 ) ,
L_21 , V_100 -> V_66 ) ;
V_65 -> V_105 . V_74 . V_74 . V_2 = V_65 -> V_105 . V_2 ;
V_65 -> V_105 . V_74 . V_74 . V_77 = 0444 ;
V_65 -> V_105 . V_74 . V_113 = F_70 ;
F_81 ( & V_65 -> V_105 . V_74 . V_74 ) ;
V_78 = F_80 ( V_100 -> V_39 ,
& V_65 -> V_105 . V_74 ) ;
if ( V_78 )
goto V_116;
}
}
F_5 ( & V_13 ) ;
if ( V_106 )
F_82 ( & V_100 -> V_117 , & V_118 ) ;
F_82 ( & V_65 -> V_119 , & V_100 -> V_109 ) ;
F_7 ( & V_13 ) ;
return 0 ;
V_116:
F_83 ( V_100 -> V_39 , & V_65 -> V_104 . V_74 ) ;
V_114:
F_84 ( V_65 ) ;
V_112:
if ( V_106 ) {
F_83 ( V_100 -> V_39 , & V_111 ) ;
F_85 ( V_100 -> V_39 ) ;
}
V_110:
if ( V_106 )
F_84 ( V_100 ) ;
return V_78 ;
}
static void
F_86 ( struct V_7 * V_23 )
{
struct V_99 * V_100 ;
struct V_103 * V_65 ;
V_100 = F_71 ( V_23 ) ;
if ( F_12 ( ! V_100 ) ) {
F_87 ( & V_23 -> V_39 , L_22 ) ;
return;
}
V_65 = F_72 ( V_100 , V_23 ) ;
if ( F_12 ( ! V_65 ) ) {
F_87 ( & V_23 -> V_39 , L_23 ) ;
return;
}
F_83 ( V_100 -> V_39 , & V_65 -> V_104 . V_74 ) ;
if ( V_23 -> V_28 -> V_115 )
F_83 ( V_100 -> V_39 , & V_65 -> V_105 . V_74 ) ;
F_5 ( & V_13 ) ;
F_9 ( & V_65 -> V_119 ) ;
F_84 ( V_65 ) ;
if ( ! F_88 ( & V_100 -> V_109 ) ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_100 -> V_117 ) ;
F_7 ( & V_13 ) ;
F_83 ( V_100 -> V_39 , & V_111 ) ;
F_85 ( V_100 -> V_39 ) ;
F_84 ( V_100 ) ;
}
static int
F_73 ( struct V_7 * V_23 )
{
return 0 ;
}
static void
F_86 ( struct V_7 * V_23 )
{
}
int F_20 ( struct V_7 * V_23 ,
int V_24 ,
struct V_36 * V_37 ,
unsigned long V_120 , unsigned long V_121 )
{
struct V_35 * V_72 ;
struct V_35 * V_3 ;
struct V_7 * V_122 ;
struct V_36 * V_123 ;
unsigned long V_124 ;
int V_78 ;
if ( V_24 >= V_23 -> V_42 || ( V_24 < 0 && V_24 != V_91 ) )
return - V_8 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_122 == V_23 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_123 == V_37 )
break;
}
if ( V_23 != V_122 || V_37 != V_123 )
return - V_8 ;
V_37 -> V_28 -> V_95 ( V_37 , & V_124 ) ;
V_121 = V_121 == V_43 ? 0 : V_121 ;
V_120 = V_120 == V_43 ? V_124 : V_120 ;
if ( V_121 > V_120 || V_120 > V_124 )
return - V_8 ;
V_72 =
F_74 ( sizeof( struct V_35 ) , V_22 ) ;
if ( ! V_72 )
return - V_108 ;
V_72 -> V_23 = V_23 ;
V_72 -> V_37 = V_37 ;
V_72 -> V_24 = V_24 ;
V_72 -> V_120 = V_120 ;
V_72 -> V_121 = V_121 ;
V_72 -> V_125 = V_126 ;
V_78 = F_10 ( & V_23 -> V_17 , & V_23 -> V_19 , & V_72 -> V_20 ) ;
if ( V_78 )
goto V_110;
sprintf ( V_72 -> V_2 , L_24 , V_72 -> V_20 ) ;
V_78 =
F_89 ( & V_23 -> V_39 . V_127 , & V_37 -> V_39 . V_127 , V_72 -> V_2 ) ;
if ( V_78 )
goto F_13;
sprintf ( V_72 -> V_128 , L_25 , V_72 -> V_20 ) ;
F_81 ( & V_72 -> V_74 . V_74 ) ;
V_72 -> V_74 . V_74 . V_2 = V_72 -> V_128 ;
V_72 -> V_74 . V_74 . V_77 = 0444 ;
V_72 -> V_74 . V_113 = F_66 ;
V_78 = F_80 ( & V_23 -> V_39 , & V_72 -> V_74 ) ;
if ( V_78 )
goto V_129;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_37 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_37 == V_37 ) {
V_78 = - V_130 ;
break;
}
if ( ! V_78 ) {
F_82 ( & V_72 -> V_131 , & V_23 -> V_132 ) ;
F_82 ( & V_72 -> V_133 , & V_37 -> V_132 ) ;
}
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
if ( ! V_78 )
return 0 ;
F_83 ( & V_23 -> V_39 , & V_72 -> V_74 ) ;
V_129:
F_90 ( & V_23 -> V_39 . V_127 , V_72 -> V_2 ) ;
F_13:
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_72 -> V_20 ) ;
V_110:
F_84 ( V_72 ) ;
return V_78 ;
}
int F_22 ( struct V_7 * V_23 ,
int V_24 ,
struct V_36 * V_37 )
{
struct V_35 * V_3 , * V_134 ;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_37 -> V_19 ) ;
F_91 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_37 == V_37 ) {
F_9 ( & V_3 -> V_131 ) ;
F_9 ( & V_3 -> V_133 ) ;
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
goto V_135;
}
}
F_7 ( & V_37 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
return - V_136 ;
V_135:
F_83 ( & V_23 -> V_39 , & V_3 -> V_74 ) ;
F_90 ( & V_23 -> V_39 . V_127 , V_3 -> V_2 ) ;
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_3 -> V_20 ) ;
F_84 ( V_3 ) ;
return 0 ;
}
static void F_92 ( struct V_39 * V_72 )
{
struct V_7 * V_23 ;
struct V_36 * V_37 ;
if ( ! strncmp ( F_93 ( V_72 ) , L_26 ,
sizeof( L_26 ) - 1 ) ) {
V_23 = F_45 ( V_72 ) ;
F_84 ( V_23 ) ;
} else {
V_37 = F_62 ( V_72 ) ;
F_84 ( V_37 ) ;
}
}
struct V_36 *
F_94 ( char * type , void * V_137 ,
const struct V_138 * V_28 )
{
struct V_36 * V_37 ;
int V_78 ;
if ( type && strlen ( type ) >= V_4 )
return F_95 ( - V_8 ) ;
if ( ! V_28 || ! V_28 -> V_95 || ! V_28 -> V_96 ||
! V_28 -> V_97 )
return F_95 ( - V_8 ) ;
V_37 = F_74 ( sizeof( struct V_36 ) , V_22 ) ;
if ( ! V_37 )
return F_95 ( - V_108 ) ;
V_78 = F_10 ( & V_139 , & V_140 , & V_37 -> V_20 ) ;
if ( V_78 ) {
F_84 ( V_37 ) ;
return F_95 ( V_78 ) ;
}
F_76 ( V_37 -> type , type ? : L_27 , sizeof( V_37 -> type ) ) ;
F_96 ( & V_37 -> V_19 ) ;
F_75 ( & V_37 -> V_132 ) ;
V_37 -> V_28 = V_28 ;
V_37 -> V_141 = true ;
V_37 -> V_39 . V_142 = & V_143 ;
V_37 -> V_137 = V_137 ;
F_97 ( & V_37 -> V_39 , L_28 , V_37 -> V_20 ) ;
V_78 = F_98 ( & V_37 -> V_39 ) ;
if ( V_78 ) {
F_13 ( & V_139 , & V_140 , V_37 -> V_20 ) ;
F_84 ( V_37 ) ;
return F_95 ( V_78 ) ;
}
if ( type ) {
V_78 = F_80 ( & V_37 -> V_39 , & V_144 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_80 ( & V_37 -> V_39 , & V_146 ) ;
if ( V_78 )
goto V_145;
V_78 = F_80 ( & V_37 -> V_39 , & V_147 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_13 ) ;
F_6 ( & V_37 -> V_117 , & V_148 ) ;
F_7 ( & V_13 ) ;
F_23 ( V_37 ) ;
return V_37 ;
V_145:
F_13 ( & V_139 , & V_140 , V_37 -> V_20 ) ;
F_99 ( & V_37 -> V_39 ) ;
return F_95 ( V_78 ) ;
}
void F_100 ( struct V_36 * V_37 )
{
int V_41 ;
const struct V_44 * V_14 ;
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
F_9 ( & V_37 -> V_117 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_23 -> V_28 -> V_135 ) {
V_23 -> V_28 -> V_135 ( V_23 , V_37 ) ;
continue;
}
if ( ! V_23 -> V_14 || ! V_23 -> V_14 -> V_46 )
continue;
V_14 = V_23 -> V_14 ;
for ( V_41 = 0 ; V_41 < V_14 -> V_47 ; V_41 ++ ) {
if ( V_14 -> V_46 [ V_41 ] . V_37 == V_37 ) {
F_21 ( V_23 , V_14 -> V_46 [ V_41 ] . V_49 , V_37 ) ;
V_14 -> V_46 [ V_41 ] . V_37 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
if ( V_37 -> type [ 0 ] )
F_83 ( & V_37 -> V_39 , & V_144 ) ;
F_83 ( & V_37 -> V_39 , & V_146 ) ;
F_83 ( & V_37 -> V_39 , & V_147 ) ;
F_13 ( & V_139 , & V_140 , V_37 -> V_20 ) ;
F_99 ( & V_37 -> V_39 ) ;
return;
}
void F_101 ( struct V_36 * V_37 )
{
struct V_35 * V_98 ;
unsigned long V_125 = 0 ;
if ( V_37 -> V_141 )
return;
F_5 ( & V_37 -> V_19 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
if ( V_98 -> V_125 == V_126 )
continue;
if ( V_98 -> V_125 > V_125 )
V_125 = V_98 -> V_125 ;
}
F_7 ( & V_37 -> V_19 ) ;
V_37 -> V_28 -> V_97 ( V_37 , V_125 ) ;
V_37 -> V_141 = true ;
}
void F_102 ( struct V_7 * V_23 , int V_24 )
{
F_35 ( V_23 , V_24 ) ;
}
static int F_103 ( struct V_7 * V_23 , int V_40 )
{
int V_149 ;
int V_150 = sizeof( struct V_151 ) * V_23 -> V_42 ;
V_23 -> V_152 = F_74 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_152 )
return - V_108 ;
V_23 -> V_153 = F_74 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_153 ) {
F_84 ( V_23 -> V_152 ) ;
return - V_108 ;
}
if ( V_23 -> V_28 -> V_88 ) {
V_23 -> V_154 = F_74 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_154 ) {
F_84 ( V_23 -> V_152 ) ;
F_84 ( V_23 -> V_153 ) ;
return - V_108 ;
}
}
for ( V_149 = 0 ; V_149 < V_23 -> V_42 ; V_149 ++ ) {
snprintf ( V_23 -> V_152 [ V_149 ] . V_2 , V_4 ,
L_8 , V_149 ) ;
F_81 ( & V_23 -> V_152 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_152 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_152 [ V_149 ] . V_2 ;
V_23 -> V_152 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_152 [ V_149 ] . V_74 . V_113 = F_49 ;
F_80 ( & V_23 -> V_39 ,
& V_23 -> V_152 [ V_149 ] . V_74 ) ;
snprintf ( V_23 -> V_153 [ V_149 ] . V_2 , V_4 ,
L_14 , V_149 ) ;
F_81 ( & V_23 -> V_153 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_153 [ V_149 ] . V_2 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_113 = F_52 ;
if ( V_40 & ( 1 << V_149 ) ) {
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_77 |= V_156 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_157 =
F_50 ;
}
F_80 ( & V_23 -> V_39 ,
& V_23 -> V_153 [ V_149 ] . V_74 ) ;
if ( ! V_23 -> V_28 -> V_88 )
continue;
snprintf ( V_23 -> V_154 [ V_149 ] . V_2 , V_4 ,
L_15 , V_149 ) ;
F_81 ( & V_23 -> V_154 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_154 [ V_149 ] . V_2 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_113 = F_54 ;
if ( V_23 -> V_28 -> V_87 ) {
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_77 |= V_156 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_157 =
F_53 ;
}
F_80 ( & V_23 -> V_39 ,
& V_23 -> V_154 [ V_149 ] . V_74 ) ;
}
return 0 ;
}
static void F_104 ( struct V_7 * V_23 )
{
int V_149 ;
for ( V_149 = 0 ; V_149 < V_23 -> V_42 ; V_149 ++ ) {
F_83 ( & V_23 -> V_39 ,
& V_23 -> V_152 [ V_149 ] . V_74 ) ;
F_83 ( & V_23 -> V_39 ,
& V_23 -> V_153 [ V_149 ] . V_74 ) ;
if ( V_23 -> V_28 -> V_88 )
F_83 ( & V_23 -> V_39 ,
& V_23 -> V_154 [ V_149 ] . V_74 ) ;
}
F_84 ( V_23 -> V_152 ) ;
F_84 ( V_23 -> V_153 ) ;
F_84 ( V_23 -> V_154 ) ;
}
struct V_7 * F_105 ( const char * type ,
int V_42 , int V_40 , void * V_137 ,
const struct V_158 * V_28 ,
const struct V_44 * V_14 ,
int V_54 , int V_55 )
{
struct V_7 * V_23 ;
enum V_56 V_57 ;
int V_78 ;
int V_66 ;
int V_53 = 0 ;
if ( type && strlen ( type ) >= V_4 )
return F_95 ( - V_8 ) ;
if ( V_42 > V_159 || V_42 < 0 || V_40 > > V_42 )
return F_95 ( - V_8 ) ;
if ( ! V_28 || ! V_28 -> V_68 )
return F_95 ( - V_8 ) ;
if ( V_42 > 0 && ( ! V_28 -> V_63 || ! V_28 -> V_60 ) )
return F_95 ( - V_8 ) ;
V_23 = F_74 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_23 )
return F_95 ( - V_108 ) ;
F_75 ( & V_23 -> V_132 ) ;
F_106 ( & V_23 -> V_17 ) ;
F_96 ( & V_23 -> V_19 ) ;
V_78 = F_10 ( & V_160 , & V_140 , & V_23 -> V_20 ) ;
if ( V_78 ) {
F_84 ( V_23 ) ;
return F_95 ( V_78 ) ;
}
F_76 ( V_23 -> type , type ? : L_27 , sizeof( V_23 -> type ) ) ;
V_23 -> V_28 = V_28 ;
V_23 -> V_14 = V_14 ;
V_23 -> V_39 . V_142 = & V_143 ;
V_23 -> V_137 = V_137 ;
V_23 -> V_42 = V_42 ;
V_23 -> V_54 = V_54 ;
V_23 -> V_55 = V_55 ;
F_97 ( & V_23 -> V_39 , L_29 , V_23 -> V_20 ) ;
V_78 = F_98 ( & V_23 -> V_39 ) ;
if ( V_78 ) {
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_84 ( V_23 ) ;
return F_95 ( V_78 ) ;
}
if ( type ) {
V_78 = F_80 ( & V_23 -> V_39 , & V_161 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_80 ( & V_23 -> V_39 , & V_162 ) ;
if ( V_78 )
goto V_145;
if ( V_28 -> V_79 ) {
V_78 = F_80 ( & V_23 -> V_39 , & V_163 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_103 ( V_23 , V_40 ) ;
if ( V_78 )
goto V_145;
for ( V_66 = 0 ; V_66 < V_42 ; V_66 ++ ) {
V_23 -> V_28 -> V_63 ( V_23 , V_66 , & V_57 ) ;
if ( V_57 == V_84 )
V_53 = 1 ;
}
if ( ! V_53 ) {
V_78 = F_80 ( & V_23 -> V_39 , & V_164 ) ;
if ( V_78 )
goto V_145;
}
#ifdef F_37
V_78 = F_80 ( & V_23 -> V_39 , & V_165 ) ;
if ( V_78 )
goto V_145;
#endif
V_78 = F_80 ( & V_23 -> V_39 , & V_166 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_9 ) ;
if ( V_23 -> V_14 )
V_23 -> V_5 = F_1 ( V_23 -> V_14 -> V_15 ) ;
else
V_23 -> V_5 = F_1 ( V_16 ) ;
F_7 ( & V_9 ) ;
V_78 = F_73 ( V_23 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_13 ) ;
F_82 ( & V_23 -> V_117 , & V_167 ) ;
F_7 ( & V_13 ) ;
F_24 ( V_23 ) ;
F_107 ( & ( V_23 -> V_52 ) , F_42 ) ;
F_41 ( V_23 ) ;
if ( ! V_78 )
return V_23 ;
V_145:
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_99 ( & V_23 -> V_39 ) ;
return F_95 ( V_78 ) ;
}
void F_108 ( struct V_7 * V_23 )
{
int V_41 ;
const struct V_44 * V_14 ;
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
F_9 ( & V_23 -> V_117 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( V_23 -> V_28 -> V_135 ) {
V_23 -> V_28 -> V_135 ( V_23 , V_37 ) ;
continue;
}
if ( ! V_14 || ! V_14 -> V_46 )
break;
for ( V_41 = 0 ; V_41 < V_14 -> V_47 ; V_41 ++ ) {
if ( V_14 -> V_46 [ V_41 ] . V_37 == V_37 ) {
F_21 ( V_23 , V_14 -> V_46 [ V_41 ] . V_49 , V_37 ) ;
V_14 -> V_46 [ V_41 ] . V_37 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
F_25 ( V_23 , 0 ) ;
if ( V_23 -> type [ 0 ] )
F_83 ( & V_23 -> V_39 , & V_161 ) ;
F_83 ( & V_23 -> V_39 , & V_162 ) ;
if ( V_23 -> V_28 -> V_79 )
F_83 ( & V_23 -> V_39 , & V_163 ) ;
F_83 ( & V_23 -> V_39 , & V_166 ) ;
F_104 ( V_23 ) ;
V_23 -> V_5 = NULL ;
F_86 ( V_23 ) ;
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_109 ( & V_23 -> V_17 ) ;
F_110 ( & V_23 -> V_19 ) ;
F_99 ( & V_23 -> V_39 ) ;
return;
}
struct V_7 * F_111 ( const char * V_2 )
{
struct V_7 * V_3 = NULL , * V_168 = F_95 ( - V_8 ) ;
unsigned int V_169 = 0 ;
if ( ! V_2 )
goto exit;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node)
if ( ! F_3 ( V_2 , V_3 -> type , V_4 ) ) {
V_169 ++ ;
V_168 = V_3 ;
}
F_7 ( & V_13 ) ;
if ( V_169 == 0 )
V_168 = F_95 ( - V_136 ) ;
else if ( V_169 > 1 )
V_168 = F_95 ( - V_130 ) ;
exit:
return V_168 ;
}
int F_112 ( struct V_7 * V_23 ,
enum V_170 V_171 )
{
struct V_172 * V_173 ;
struct V_174 * V_74 ;
struct V_175 * V_176 ;
void * V_177 ;
int V_150 ;
int V_78 ;
static unsigned int V_178 ;
if ( ! V_23 )
return - V_8 ;
V_150 = F_113 ( sizeof( struct V_175 ) ) +
F_113 ( 0 ) ;
V_173 = F_114 ( V_150 , V_179 ) ;
if ( ! V_173 )
return - V_108 ;
V_177 = F_115 ( V_173 , 0 , V_178 ++ ,
& V_180 , 0 ,
V_181 ) ;
if ( ! V_177 ) {
F_116 ( V_173 ) ;
return - V_108 ;
}
V_74 = F_117 ( V_173 , V_182 ,
sizeof( struct V_175 ) ) ;
if ( ! V_74 ) {
F_116 ( V_173 ) ;
return - V_8 ;
}
V_176 = F_118 ( V_74 ) ;
if ( ! V_176 ) {
F_116 ( V_173 ) ;
return - V_8 ;
}
memset ( V_176 , 0 , sizeof( struct V_175 ) ) ;
V_176 -> V_183 = V_23 -> V_20 ;
V_176 -> V_171 = V_171 ;
V_78 = F_119 ( V_173 , V_177 ) ;
if ( V_78 < 0 ) {
F_116 ( V_173 ) ;
return V_78 ;
}
V_78 = F_120 ( V_173 , 0 , V_184 . V_20 , V_179 ) ;
if ( V_78 )
F_18 ( & V_23 -> V_39 , L_30 , V_78 ) ;
return V_78 ;
}
static int F_121 ( void )
{
int V_78 ;
V_78 = F_122 ( & V_180 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_123 ( & V_180 ,
& V_184 ) ;
if ( V_78 )
F_124 ( & V_180 ) ;
return V_78 ;
}
static void F_125 ( void )
{
F_124 ( & V_180 ) ;
}
static inline int F_121 ( void ) { return 0 ; }
static inline void F_125 ( void ) {}
static int T_3 F_126 ( void )
{
int V_78 ;
V_78 = F_127 () ;
if ( V_78 )
return V_78 ;
V_78 = F_128 () ;
if ( V_78 )
return V_78 ;
return F_129 () ;
}
static void F_130 ( void )
{
F_131 () ;
F_132 () ;
F_133 () ;
}
static int T_3 F_134 ( void )
{
int V_78 ;
V_78 = F_126 () ;
if ( V_78 )
goto error;
V_78 = F_135 ( & V_143 ) ;
if ( V_78 )
goto V_185;
V_78 = F_121 () ;
if ( V_78 )
goto V_186;
return 0 ;
V_185:
F_130 () ;
V_186:
F_136 ( & V_143 ) ;
error:
F_109 ( & V_160 ) ;
F_109 ( & V_139 ) ;
F_110 ( & V_140 ) ;
F_110 ( & V_13 ) ;
F_110 ( & V_9 ) ;
return V_78 ;
}
static void T_4 F_137 ( void )
{
F_125 () ;
F_136 ( & V_143 ) ;
F_130 () ;
F_109 ( & V_160 ) ;
F_109 ( & V_139 ) ;
F_110 ( & V_140 ) ;
F_110 ( & V_13 ) ;
F_110 ( & V_9 ) ;
}
