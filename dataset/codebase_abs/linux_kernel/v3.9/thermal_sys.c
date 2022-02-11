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
if ( ! V_23 -> V_27 -> V_28 || V_23 -> V_27 -> V_28 ( V_23 , V_24 , & V_26 ) ) {
if ( V_23 -> V_29 > V_23 -> V_30 )
V_26 = V_31 ;
else if ( V_23 -> V_29 < V_23 -> V_30 )
V_26 = V_32 ;
else
V_26 = V_33 ;
}
return V_26 ;
}
struct V_34 * F_16 ( struct V_7 * V_23 ,
struct V_35 * V_36 , int V_24 )
{
struct V_34 * V_3 = NULL ;
struct V_34 * V_37 = NULL ;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_36 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_36 == V_36 ) {
V_37 = V_3 ;
break;
}
}
F_7 ( & V_36 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
return V_37 ;
}
static void F_17 ( struct V_7 * V_23 ,
struct V_35 * V_36 , int V_21 )
{
F_18 ( & V_23 -> V_38 , L_1 ,
V_23 -> type , V_36 -> type , V_21 ) ;
}
static void F_19 ( struct V_7 * V_23 , int V_39 ,
struct V_35 * V_36 )
{
int V_40 , V_21 ;
for ( V_40 = 0 ; V_40 < V_23 -> V_41 ; V_40 ++ ) {
if ( V_39 & ( 1 << V_40 ) ) {
V_21 = F_20 ( V_23 , V_40 , V_36 ,
V_42 , V_42 ) ;
if ( V_21 )
F_17 ( V_23 , V_36 , V_21 ) ;
}
}
}
static void F_21 ( struct V_7 * V_23 , int V_39 ,
struct V_35 * V_36 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_23 -> V_41 ; V_40 ++ )
if ( V_39 & ( 1 << V_40 ) )
F_22 ( V_23 , V_40 , V_36 ) ;
}
static void F_23 ( struct V_35 * V_36 )
{
int V_40 , V_21 ;
const struct V_43 * V_14 ;
struct V_7 * V_3 = NULL ;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_tz_list, node) {
if ( ! V_3 -> V_14 && ! V_3 -> V_27 -> V_44 )
continue;
if ( ! V_3 -> V_14 && V_3 -> V_27 -> V_44 ) {
V_21 = V_3 -> V_27 -> V_44 ( V_3 , V_36 ) ;
if ( V_21 )
F_17 ( V_3 , V_36 , V_21 ) ;
}
V_14 = V_3 -> V_14 ;
if ( ! V_14 || ! V_14 -> V_45 )
continue;
for ( V_40 = 0 ; V_40 < V_14 -> V_46 ; V_40 ++ ) {
if ( V_14 -> V_45 [ V_40 ] . V_36 || ! V_14 -> V_45 [ V_40 ] . V_47 )
continue;
if ( V_14 -> V_45 [ V_40 ] . V_47 ( V_3 , V_36 ) )
continue;
V_14 -> V_45 [ V_40 ] . V_36 = V_36 ;
F_19 ( V_3 , V_14 -> V_45 [ V_40 ] . V_48 , V_36 ) ;
}
}
F_7 ( & V_13 ) ;
}
static void F_24 ( struct V_7 * V_23 )
{
int V_40 , V_21 ;
struct V_35 * V_3 = NULL ;
const struct V_43 * V_14 = V_23 -> V_14 ;
if ( ! V_14 && ! V_23 -> V_27 -> V_44 )
return;
F_5 ( & V_13 ) ;
if ( ! V_14 && V_23 -> V_27 -> V_44 ) {
F_2 (pos, &thermal_cdev_list, node) {
V_21 = V_23 -> V_27 -> V_44 ( V_23 , V_3 ) ;
if ( V_21 )
F_17 ( V_23 , V_3 , V_21 ) ;
}
goto exit;
}
if ( ! V_14 || ! V_14 -> V_45 )
goto exit;
F_2 (pos, &thermal_cdev_list, node) {
for ( V_40 = 0 ; V_40 < V_14 -> V_46 ; V_40 ++ ) {
if ( V_14 -> V_45 [ V_40 ] . V_36 || ! V_14 -> V_45 [ V_40 ] . V_47 )
continue;
if ( V_14 -> V_45 [ V_40 ] . V_47 ( V_23 , V_3 ) )
continue;
V_14 -> V_45 [ V_40 ] . V_36 = V_3 ;
F_19 ( V_23 , V_14 -> V_45 [ V_40 ] . V_48 , V_3 ) ;
}
}
exit:
F_7 ( & V_13 ) ;
}
static void F_25 ( struct V_7 * V_23 ,
int V_49 )
{
if ( V_49 > 1000 )
F_26 ( V_50 , & V_23 -> V_51 ,
F_27 ( F_28 ( V_49 ) ) ) ;
else if ( V_49 )
F_26 ( V_50 , & V_23 -> V_51 ,
F_28 ( V_49 ) ) ;
else
F_29 ( & V_23 -> V_51 ) ;
}
static void F_30 ( struct V_7 * V_23 )
{
F_5 ( & V_23 -> V_19 ) ;
if ( V_23 -> V_52 )
F_25 ( V_23 , V_23 -> V_53 ) ;
else if ( V_23 -> V_54 )
F_25 ( V_23 , V_23 -> V_54 ) ;
else
F_25 ( V_23 , 0 ) ;
F_7 ( & V_23 -> V_19 ) ;
}
static void F_31 ( struct V_7 * V_23 ,
int V_24 , enum V_55 V_56 )
{
if ( V_23 -> V_5 )
V_23 -> V_5 -> V_57 ( V_23 , V_24 ) ;
}
static void F_32 ( struct V_7 * V_23 ,
int V_24 , enum V_55 V_56 )
{
long V_58 ;
V_23 -> V_27 -> V_59 ( V_23 , V_24 , & V_58 ) ;
if ( V_23 -> V_29 < V_58 )
return;
if ( V_23 -> V_27 -> V_60 )
V_23 -> V_27 -> V_60 ( V_23 , V_24 , V_56 ) ;
if ( V_56 == V_61 ) {
F_33 ( & V_23 -> V_38 ,
L_2 ,
V_23 -> V_29 / 1000 ) ;
F_34 ( true ) ;
}
}
static void F_35 ( struct V_7 * V_23 , int V_24 )
{
enum V_55 type ;
V_23 -> V_27 -> V_62 ( V_23 , V_24 , & type ) ;
if ( type == V_61 || type == V_63 )
F_32 ( V_23 , V_24 , type ) ;
else
F_31 ( V_23 , V_24 , type ) ;
F_30 ( V_23 ) ;
}
static int F_36 ( struct V_7 * V_23 ,
unsigned long * V_64 )
{
int V_21 = 0 ;
#ifdef F_37
int V_65 ;
unsigned long V_66 = - 1UL ;
enum V_55 type ;
#endif
F_5 ( & V_23 -> V_19 ) ;
V_21 = V_23 -> V_27 -> V_67 ( V_23 , V_64 ) ;
#ifdef F_37
if ( ! V_23 -> V_68 )
goto V_69;
for ( V_65 = 0 ; V_65 < V_23 -> V_41 ; V_65 ++ ) {
V_21 = V_23 -> V_27 -> V_62 ( V_23 , V_65 , & type ) ;
if ( ! V_21 && type == V_61 ) {
V_21 = V_23 -> V_27 -> V_59 ( V_23 , V_65 , & V_66 ) ;
break;
}
}
if ( V_21 )
goto V_69;
if ( * V_64 < V_66 )
* V_64 = V_23 -> V_68 ;
V_69:
#endif
F_7 ( & V_23 -> V_19 ) ;
return V_21 ;
}
static void F_38 ( struct V_7 * V_23 )
{
long V_64 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_64 ) ;
if ( V_21 ) {
F_39 ( & V_23 -> V_38 , L_3 ,
V_23 -> V_20 ) ;
return;
}
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_30 = V_23 -> V_29 ;
V_23 -> V_29 = V_64 ;
F_7 ( & V_23 -> V_19 ) ;
}
void F_40 ( struct V_7 * V_23 )
{
int V_65 ;
F_38 ( V_23 ) ;
for ( V_65 = 0 ; V_65 < V_23 -> V_41 ; V_65 ++ )
F_35 ( V_23 , V_65 ) ;
}
static void F_41 ( struct V_70 * V_71 )
{
struct V_7 * V_23 = F_42 ( V_71 , struct
V_7 ,
V_51 . V_71 ) ;
F_40 ( V_23 ) ;
}
static T_1
F_43 ( struct V_38 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_23 -> type ) ;
}
static T_1
F_45 ( struct V_38 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
long V_29 ;
int V_21 ;
V_21 = F_36 ( V_23 , & V_29 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_29 ) ;
}
static T_1
F_46 ( struct V_38 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
enum V_76 V_77 ;
int V_78 ;
if ( ! V_23 -> V_27 -> V_79 )
return - V_80 ;
V_78 = V_23 -> V_27 -> V_79 ( V_23 , & V_77 ) ;
if ( V_78 )
return V_78 ;
return sprintf ( V_75 , L_4 , V_77 == V_81 ? L_6
: L_7 ) ;
}
static T_1
F_47 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_78 ;
if ( ! V_23 -> V_27 -> V_82 )
return - V_80 ;
if ( ! strncmp ( V_75 , L_6 , sizeof( L_6 ) - 1 ) )
V_78 = V_23 -> V_27 -> V_82 ( V_23 , V_81 ) ;
else if ( ! strncmp ( V_75 , L_7 , sizeof( L_7 ) - 1 ) )
V_78 = V_23 -> V_27 -> V_82 ( V_23 , V_83 ) ;
else
V_78 = - V_8 ;
if ( V_78 )
return V_78 ;
return V_65 ;
}
static T_1
F_48 ( struct V_38 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
enum V_55 type ;
int V_24 , V_78 ;
if ( ! V_23 -> V_27 -> V_62 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_8 , & V_24 ) )
return - V_8 ;
V_78 = V_23 -> V_27 -> V_62 ( V_23 , V_24 , & type ) ;
if ( V_78 )
return V_78 ;
switch ( type ) {
case V_61 :
return sprintf ( V_75 , L_9 ) ;
case V_63 :
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
F_49 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_29 ;
if ( ! V_23 -> V_27 -> V_86 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
if ( F_50 ( V_75 , 10 , & V_29 ) )
return - V_8 ;
V_21 = V_23 -> V_27 -> V_86 ( V_23 , V_24 , V_29 ) ;
return V_21 ? V_21 : V_65 ;
}
static T_1
F_51 ( struct V_38 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_24 , V_21 ;
long V_29 ;
if ( ! V_23 -> V_27 -> V_59 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_14 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_27 -> V_59 ( V_23 , V_24 , & V_29 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_29 ) ;
}
static T_1
F_52 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_29 ;
if ( ! V_23 -> V_27 -> V_87 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
if ( F_50 ( V_75 , 10 , & V_29 ) )
return - V_8 ;
V_21 = V_23 -> V_27 -> V_87 ( V_23 , V_24 , V_29 ) ;
return V_21 ? V_21 : V_65 ;
}
static T_1
F_53 ( struct V_38 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_24 , V_21 ;
unsigned long V_29 ;
if ( ! V_23 -> V_27 -> V_88 )
return - V_80 ;
if ( ! sscanf ( V_74 -> V_74 . V_2 , L_15 , & V_24 ) )
return - V_8 ;
V_21 = V_23 -> V_27 -> V_88 ( V_23 , V_24 , & V_29 ) ;
return V_21 ? V_21 : sprintf ( V_75 , L_5 , V_29 ) ;
}
static T_1
F_54 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
struct V_35 * V_36 = NULL ;
int V_89 ;
if ( ! sscanf ( V_75 , L_16 , & V_89 ) )
return - V_8 ;
if ( V_89 && V_89 < 1000 )
return - V_8 ;
if ( V_89 && ! V_23 -> V_90 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_36 -> type ,
sizeof( L_17 ) ) )
F_20 ( V_23 ,
V_91 , V_36 ,
V_42 ,
V_42 ) ;
}
F_7 ( & V_13 ) ;
if ( ! V_23 -> V_53 )
V_23 -> V_53 = 1000 ;
} else if ( ! V_89 && V_23 -> V_90 ) {
F_5 ( & V_13 ) ;
F_2 (cdev, &thermal_cdev_list, node) {
if ( ! strncmp ( L_17 , V_36 -> type ,
sizeof( L_17 ) ) )
F_22 ( V_23 ,
V_91 ,
V_36 ) ;
}
F_7 ( & V_13 ) ;
V_23 -> V_53 = 0 ;
}
V_23 -> V_90 = V_89 ;
F_40 ( V_23 ) ;
return V_65 ;
}
static T_1
F_55 ( struct V_38 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
return sprintf ( V_75 , L_16 , V_23 -> V_90 ) ;
}
static T_1
F_56 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
int V_21 = - V_8 ;
struct V_7 * V_23 = F_44 ( V_72 ) ;
struct V_1 * V_92 ;
F_5 ( & V_9 ) ;
V_92 = F_1 ( V_75 ) ;
if ( ! V_92 )
goto exit;
V_23 -> V_5 = V_92 ;
V_21 = V_65 ;
exit:
F_7 ( & V_9 ) ;
return V_21 ;
}
static T_1
F_57 ( struct V_38 * V_72 , struct V_73 * V_93 , char * V_75 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_23 -> V_5 -> V_2 ) ;
}
static T_1
F_58 ( struct V_38 * V_72 , struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_7 * V_23 = F_44 ( V_72 ) ;
int V_21 = 0 ;
unsigned long V_29 ;
if ( F_50 ( V_75 , 10 , & V_29 ) )
return - V_8 ;
if ( ! V_23 -> V_27 -> V_94 ) {
F_5 ( & V_23 -> V_19 ) ;
V_23 -> V_68 = V_29 ;
F_7 ( & V_23 -> V_19 ) ;
} else {
V_21 = V_23 -> V_27 -> V_94 ( V_23 , V_29 ) ;
}
return V_21 ? V_21 : V_65 ;
}
static T_1
F_59 ( struct V_38 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_35 * V_36 = F_60 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_36 -> type ) ;
}
static T_1
F_61 ( struct V_38 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_35 * V_36 = F_60 ( V_72 ) ;
unsigned long V_89 ;
int V_21 ;
V_21 = V_36 -> V_27 -> V_95 ( V_36 , & V_89 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_89 ) ;
}
static T_1
F_62 ( struct V_38 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_35 * V_36 = F_60 ( V_72 ) ;
unsigned long V_89 ;
int V_21 ;
V_21 = V_36 -> V_27 -> V_96 ( V_36 , & V_89 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_89 ) ;
}
static T_1
F_63 ( struct V_38 * V_72 ,
struct V_73 * V_74 ,
const char * V_75 , T_2 V_65 )
{
struct V_35 * V_36 = F_60 ( V_72 ) ;
unsigned long V_89 ;
int V_78 ;
if ( ! sscanf ( V_75 , L_5 , & V_89 ) )
return - V_8 ;
if ( ( long ) V_89 < 0 )
return - V_8 ;
V_78 = V_36 -> V_27 -> V_97 ( V_36 , V_89 ) ;
if ( V_78 )
return V_78 ;
return V_65 ;
}
static T_1
F_64 ( struct V_38 * V_72 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_34 * V_98 ;
V_98 =
F_42 ( V_74 , struct V_34 , V_74 ) ;
if ( V_98 -> V_24 == V_91 )
return sprintf ( V_75 , L_18 ) ;
else
return sprintf ( V_75 , L_16 , V_98 -> V_24 ) ;
}
static T_1
F_65 ( struct V_38 * V_72 , struct V_73 * V_74 , char * V_75 )
{
struct V_99 * V_100 = F_66 ( V_72 ) ;
return sprintf ( V_75 , L_4 , V_100 -> type ) ;
}
static T_1
F_67 ( struct V_38 * V_72 , struct V_73 * V_74 , char * V_75 )
{
long V_29 ;
int V_21 ;
struct V_101 * V_102
= F_42 ( V_74 , struct V_101 , V_74 ) ;
struct V_103 * V_64
= F_42 ( V_102 , struct V_103 ,
V_104 ) ;
struct V_7 * V_23 = V_64 -> V_23 ;
V_21 = F_36 ( V_23 , & V_29 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_29 ) ;
}
static T_1
F_68 ( struct V_38 * V_72 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_101 * V_102
= F_42 ( V_74 , struct V_101 , V_74 ) ;
struct V_103 * V_64
= F_42 ( V_102 , struct V_103 ,
V_105 ) ;
struct V_7 * V_23 = V_64 -> V_23 ;
long V_29 ;
int V_21 ;
V_21 = V_23 -> V_27 -> V_59 ( V_23 , 0 , & V_29 ) ;
if ( V_21 )
return V_21 ;
return sprintf ( V_75 , L_5 , V_29 ) ;
}
static struct V_99 *
F_69 ( const struct V_7 * V_23 )
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
F_70 ( const struct V_99 * V_100 ,
const struct V_7 * V_23 )
{
struct V_103 * V_64 ;
F_5 ( & V_13 ) ;
F_2 (temp, &hwmon->tz_list, hwmon_node)
if ( V_64 -> V_23 == V_23 ) {
F_7 ( & V_13 ) ;
return V_64 ;
}
F_7 ( & V_13 ) ;
return NULL ;
}
static int
F_71 ( struct V_7 * V_23 )
{
struct V_99 * V_100 ;
struct V_103 * V_64 ;
int V_106 = 1 ;
int V_78 ;
V_100 = F_69 ( V_23 ) ;
if ( V_100 ) {
V_106 = 0 ;
goto V_107;
}
V_100 = F_72 ( sizeof( struct V_99 ) , V_22 ) ;
if ( ! V_100 )
return - V_108 ;
F_73 ( & V_100 -> V_109 ) ;
F_74 ( V_100 -> type , V_23 -> type , V_4 ) ;
V_100 -> V_38 = F_75 ( NULL ) ;
if ( F_76 ( V_100 -> V_38 ) ) {
V_78 = F_77 ( V_100 -> V_38 ) ;
goto V_110;
}
F_78 ( V_100 -> V_38 , V_100 ) ;
V_78 = F_79 ( V_100 -> V_38 , & V_111 ) ;
if ( V_78 )
goto V_110;
V_107:
V_64 = F_72 ( sizeof( struct V_103 ) , V_22 ) ;
if ( ! V_64 ) {
V_78 = - V_108 ;
goto V_112;
}
V_64 -> V_23 = V_23 ;
V_100 -> V_65 ++ ;
snprintf ( V_64 -> V_104 . V_2 , sizeof( V_64 -> V_104 . V_2 ) ,
L_19 , V_100 -> V_65 ) ;
V_64 -> V_104 . V_74 . V_74 . V_2 = V_64 -> V_104 . V_2 ;
V_64 -> V_104 . V_74 . V_74 . V_77 = 0444 ;
V_64 -> V_104 . V_74 . V_113 = F_67 ;
F_80 ( & V_64 -> V_104 . V_74 . V_74 ) ;
V_78 = F_79 ( V_100 -> V_38 , & V_64 -> V_104 . V_74 ) ;
if ( V_78 )
goto V_114;
if ( V_23 -> V_27 -> V_115 ) {
unsigned long V_29 ;
if ( ! V_23 -> V_27 -> V_115 ( V_23 , & V_29 ) ) {
snprintf ( V_64 -> V_105 . V_2 ,
sizeof( V_64 -> V_105 . V_2 ) ,
L_20 , V_100 -> V_65 ) ;
V_64 -> V_105 . V_74 . V_74 . V_2 = V_64 -> V_105 . V_2 ;
V_64 -> V_105 . V_74 . V_74 . V_77 = 0444 ;
V_64 -> V_105 . V_74 . V_113 = F_68 ;
F_80 ( & V_64 -> V_105 . V_74 . V_74 ) ;
V_78 = F_79 ( V_100 -> V_38 ,
& V_64 -> V_105 . V_74 ) ;
if ( V_78 )
goto V_116;
}
}
F_5 ( & V_13 ) ;
if ( V_106 )
F_81 ( & V_100 -> V_117 , & V_118 ) ;
F_81 ( & V_64 -> V_119 , & V_100 -> V_109 ) ;
F_7 ( & V_13 ) ;
return 0 ;
V_116:
F_82 ( V_100 -> V_38 , & V_64 -> V_104 . V_74 ) ;
V_114:
F_83 ( V_64 ) ;
V_112:
if ( V_106 ) {
F_82 ( V_100 -> V_38 , & V_111 ) ;
F_84 ( V_100 -> V_38 ) ;
}
V_110:
if ( V_106 )
F_83 ( V_100 ) ;
return V_78 ;
}
static void
F_85 ( struct V_7 * V_23 )
{
struct V_99 * V_100 ;
struct V_103 * V_64 ;
V_100 = F_69 ( V_23 ) ;
if ( F_12 ( ! V_100 ) ) {
F_86 ( & V_23 -> V_38 , L_21 ) ;
return;
}
V_64 = F_70 ( V_100 , V_23 ) ;
if ( F_12 ( ! V_64 ) ) {
F_86 ( & V_23 -> V_38 , L_22 ) ;
return;
}
F_82 ( V_100 -> V_38 , & V_64 -> V_104 . V_74 ) ;
if ( V_23 -> V_27 -> V_115 )
F_82 ( V_100 -> V_38 , & V_64 -> V_105 . V_74 ) ;
F_5 ( & V_13 ) ;
F_9 ( & V_64 -> V_119 ) ;
F_83 ( V_64 ) ;
if ( ! F_87 ( & V_100 -> V_109 ) ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_100 -> V_117 ) ;
F_7 ( & V_13 ) ;
F_82 ( V_100 -> V_38 , & V_111 ) ;
F_84 ( V_100 -> V_38 ) ;
F_83 ( V_100 ) ;
}
static int
F_71 ( struct V_7 * V_23 )
{
return 0 ;
}
static void
F_85 ( struct V_7 * V_23 )
{
}
int F_20 ( struct V_7 * V_23 ,
int V_24 ,
struct V_35 * V_36 ,
unsigned long V_120 , unsigned long V_121 )
{
struct V_34 * V_72 ;
struct V_34 * V_3 ;
struct V_7 * V_122 ;
struct V_35 * V_123 ;
unsigned long V_124 ;
int V_78 ;
if ( V_24 >= V_23 -> V_41 || ( V_24 < 0 && V_24 != V_91 ) )
return - V_8 ;
F_2 (pos1, &thermal_tz_list, node) {
if ( V_122 == V_23 )
break;
}
F_2 (pos2, &thermal_cdev_list, node) {
if ( V_123 == V_36 )
break;
}
if ( V_23 != V_122 || V_36 != V_123 )
return - V_8 ;
V_36 -> V_27 -> V_95 ( V_36 , & V_124 ) ;
V_121 = V_121 == V_42 ? 0 : V_121 ;
V_120 = V_120 == V_42 ? V_124 : V_120 ;
if ( V_121 > V_120 || V_120 > V_124 )
return - V_8 ;
V_72 =
F_72 ( sizeof( struct V_34 ) , V_22 ) ;
if ( ! V_72 )
return - V_108 ;
V_72 -> V_23 = V_23 ;
V_72 -> V_36 = V_36 ;
V_72 -> V_24 = V_24 ;
V_72 -> V_120 = V_120 ;
V_72 -> V_121 = V_121 ;
V_72 -> V_125 = V_126 ;
V_78 = F_10 ( & V_23 -> V_17 , & V_23 -> V_19 , & V_72 -> V_20 ) ;
if ( V_78 )
goto V_110;
sprintf ( V_72 -> V_2 , L_23 , V_72 -> V_20 ) ;
V_78 =
F_88 ( & V_23 -> V_38 . V_127 , & V_36 -> V_38 . V_127 , V_72 -> V_2 ) ;
if ( V_78 )
goto F_13;
sprintf ( V_72 -> V_128 , L_24 , V_72 -> V_20 ) ;
F_80 ( & V_72 -> V_74 . V_74 ) ;
V_72 -> V_74 . V_74 . V_2 = V_72 -> V_128 ;
V_72 -> V_74 . V_74 . V_77 = 0444 ;
V_72 -> V_74 . V_113 = F_64 ;
V_78 = F_79 ( & V_23 -> V_38 , & V_72 -> V_74 ) ;
if ( V_78 )
goto V_129;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_36 -> V_19 ) ;
F_2 (pos, &tz->thermal_instances, tz_node)
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_36 == V_36 ) {
V_78 = - V_130 ;
break;
}
if ( ! V_78 ) {
F_81 ( & V_72 -> V_131 , & V_23 -> V_132 ) ;
F_81 ( & V_72 -> V_133 , & V_36 -> V_132 ) ;
}
F_7 ( & V_36 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
if ( ! V_78 )
return 0 ;
F_82 ( & V_23 -> V_38 , & V_72 -> V_74 ) ;
V_129:
F_89 ( & V_23 -> V_38 . V_127 , V_72 -> V_2 ) ;
F_13:
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_72 -> V_20 ) ;
V_110:
F_83 ( V_72 ) ;
return V_78 ;
}
int F_22 ( struct V_7 * V_23 ,
int V_24 ,
struct V_35 * V_36 )
{
struct V_34 * V_3 , * V_134 ;
F_5 ( & V_23 -> V_19 ) ;
F_5 ( & V_36 -> V_19 ) ;
F_90 (pos, next, &tz->thermal_instances, tz_node) {
if ( V_3 -> V_23 == V_23 && V_3 -> V_24 == V_24 && V_3 -> V_36 == V_36 ) {
F_9 ( & V_3 -> V_131 ) ;
F_9 ( & V_3 -> V_133 ) ;
F_7 ( & V_36 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
goto V_135;
}
}
F_7 ( & V_36 -> V_19 ) ;
F_7 ( & V_23 -> V_19 ) ;
return - V_136 ;
V_135:
F_82 ( & V_23 -> V_38 , & V_3 -> V_74 ) ;
F_89 ( & V_23 -> V_38 . V_127 , V_3 -> V_2 ) ;
F_13 ( & V_23 -> V_17 , & V_23 -> V_19 , V_3 -> V_20 ) ;
F_83 ( V_3 ) ;
return 0 ;
}
static void F_91 ( struct V_38 * V_72 )
{
struct V_7 * V_23 ;
struct V_35 * V_36 ;
if ( ! strncmp ( F_92 ( V_72 ) , L_25 ,
sizeof( L_25 ) - 1 ) ) {
V_23 = F_44 ( V_72 ) ;
F_83 ( V_23 ) ;
} else {
V_36 = F_60 ( V_72 ) ;
F_83 ( V_36 ) ;
}
}
struct V_35 *
F_93 ( char * type , void * V_137 ,
const struct V_138 * V_27 )
{
struct V_35 * V_36 ;
int V_78 ;
if ( type && strlen ( type ) >= V_4 )
return F_94 ( - V_8 ) ;
if ( ! V_27 || ! V_27 -> V_95 || ! V_27 -> V_96 ||
! V_27 -> V_97 )
return F_94 ( - V_8 ) ;
V_36 = F_72 ( sizeof( struct V_35 ) , V_22 ) ;
if ( ! V_36 )
return F_94 ( - V_108 ) ;
V_78 = F_10 ( & V_139 , & V_140 , & V_36 -> V_20 ) ;
if ( V_78 ) {
F_83 ( V_36 ) ;
return F_94 ( V_78 ) ;
}
strcpy ( V_36 -> type , type ? : L_26 ) ;
F_95 ( & V_36 -> V_19 ) ;
F_73 ( & V_36 -> V_132 ) ;
V_36 -> V_27 = V_27 ;
V_36 -> V_141 = true ;
V_36 -> V_38 . V_142 = & V_143 ;
V_36 -> V_137 = V_137 ;
F_96 ( & V_36 -> V_38 , L_27 , V_36 -> V_20 ) ;
V_78 = F_97 ( & V_36 -> V_38 ) ;
if ( V_78 ) {
F_13 ( & V_139 , & V_140 , V_36 -> V_20 ) ;
F_83 ( V_36 ) ;
return F_94 ( V_78 ) ;
}
if ( type ) {
V_78 = F_79 ( & V_36 -> V_38 , & V_144 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_79 ( & V_36 -> V_38 , & V_146 ) ;
if ( V_78 )
goto V_145;
V_78 = F_79 ( & V_36 -> V_38 , & V_147 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_13 ) ;
F_6 ( & V_36 -> V_117 , & V_148 ) ;
F_7 ( & V_13 ) ;
F_23 ( V_36 ) ;
return V_36 ;
V_145:
F_13 ( & V_139 , & V_140 , V_36 -> V_20 ) ;
F_98 ( & V_36 -> V_38 ) ;
return F_94 ( V_78 ) ;
}
void F_99 ( struct V_35 * V_36 )
{
int V_40 ;
const struct V_43 * V_14 ;
struct V_7 * V_23 ;
struct V_35 * V_3 = NULL ;
if ( ! V_36 )
return;
F_5 ( & V_13 ) ;
F_2 (pos, &thermal_cdev_list, node)
if ( V_3 == V_36 )
break;
if ( V_3 != V_36 ) {
F_7 ( & V_13 ) ;
return;
}
F_9 ( & V_36 -> V_117 ) ;
F_2 (tz, &thermal_tz_list, node) {
if ( V_23 -> V_27 -> V_135 ) {
V_23 -> V_27 -> V_135 ( V_23 , V_36 ) ;
continue;
}
if ( ! V_23 -> V_14 || ! V_23 -> V_14 -> V_45 )
continue;
V_14 = V_23 -> V_14 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_46 ; V_40 ++ ) {
if ( V_14 -> V_45 [ V_40 ] . V_36 == V_36 ) {
F_21 ( V_23 , V_14 -> V_45 [ V_40 ] . V_48 , V_36 ) ;
V_14 -> V_45 [ V_40 ] . V_36 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
if ( V_36 -> type [ 0 ] )
F_82 ( & V_36 -> V_38 , & V_144 ) ;
F_82 ( & V_36 -> V_38 , & V_146 ) ;
F_82 ( & V_36 -> V_38 , & V_147 ) ;
F_13 ( & V_139 , & V_140 , V_36 -> V_20 ) ;
F_98 ( & V_36 -> V_38 ) ;
return;
}
void F_100 ( struct V_35 * V_36 )
{
struct V_34 * V_98 ;
unsigned long V_125 = 0 ;
if ( V_36 -> V_141 )
return;
F_5 ( & V_36 -> V_19 ) ;
F_2 (instance, &cdev->thermal_instances, cdev_node) {
if ( V_98 -> V_125 == V_126 )
continue;
if ( V_98 -> V_125 > V_125 )
V_125 = V_98 -> V_125 ;
}
F_7 ( & V_36 -> V_19 ) ;
V_36 -> V_27 -> V_97 ( V_36 , V_125 ) ;
V_36 -> V_141 = true ;
}
void F_101 ( struct V_7 * V_23 , int V_24 )
{
F_35 ( V_23 , V_24 ) ;
}
static int F_102 ( struct V_7 * V_23 , int V_39 )
{
int V_149 ;
int V_150 = sizeof( struct V_151 ) * V_23 -> V_41 ;
V_23 -> V_152 = F_72 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_152 )
return - V_108 ;
V_23 -> V_153 = F_72 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_153 ) {
F_83 ( V_23 -> V_152 ) ;
return - V_108 ;
}
if ( V_23 -> V_27 -> V_88 ) {
V_23 -> V_154 = F_72 ( V_150 , V_22 ) ;
if ( ! V_23 -> V_154 ) {
F_83 ( V_23 -> V_152 ) ;
F_83 ( V_23 -> V_153 ) ;
return - V_108 ;
}
}
for ( V_149 = 0 ; V_149 < V_23 -> V_41 ; V_149 ++ ) {
snprintf ( V_23 -> V_152 [ V_149 ] . V_2 , V_4 ,
L_8 , V_149 ) ;
F_80 ( & V_23 -> V_152 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_152 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_152 [ V_149 ] . V_2 ;
V_23 -> V_152 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_152 [ V_149 ] . V_74 . V_113 = F_48 ;
F_79 ( & V_23 -> V_38 ,
& V_23 -> V_152 [ V_149 ] . V_74 ) ;
snprintf ( V_23 -> V_153 [ V_149 ] . V_2 , V_4 ,
L_14 , V_149 ) ;
F_80 ( & V_23 -> V_153 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_153 [ V_149 ] . V_2 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_113 = F_51 ;
if ( V_39 & ( 1 << V_149 ) ) {
V_23 -> V_153 [ V_149 ] . V_74 . V_74 . V_77 |= V_156 ;
V_23 -> V_153 [ V_149 ] . V_74 . V_157 =
F_49 ;
}
F_79 ( & V_23 -> V_38 ,
& V_23 -> V_153 [ V_149 ] . V_74 ) ;
if ( ! V_23 -> V_27 -> V_88 )
continue;
snprintf ( V_23 -> V_154 [ V_149 ] . V_2 , V_4 ,
L_15 , V_149 ) ;
F_80 ( & V_23 -> V_154 [ V_149 ] . V_74 . V_74 ) ;
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_2 =
V_23 -> V_154 [ V_149 ] . V_2 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_77 = V_155 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_113 = F_53 ;
if ( V_23 -> V_27 -> V_87 ) {
V_23 -> V_154 [ V_149 ] . V_74 . V_74 . V_77 |= V_156 ;
V_23 -> V_154 [ V_149 ] . V_74 . V_157 =
F_52 ;
}
F_79 ( & V_23 -> V_38 ,
& V_23 -> V_154 [ V_149 ] . V_74 ) ;
}
return 0 ;
}
static void F_103 ( struct V_7 * V_23 )
{
int V_149 ;
for ( V_149 = 0 ; V_149 < V_23 -> V_41 ; V_149 ++ ) {
F_82 ( & V_23 -> V_38 ,
& V_23 -> V_152 [ V_149 ] . V_74 ) ;
F_82 ( & V_23 -> V_38 ,
& V_23 -> V_153 [ V_149 ] . V_74 ) ;
if ( V_23 -> V_27 -> V_88 )
F_82 ( & V_23 -> V_38 ,
& V_23 -> V_154 [ V_149 ] . V_74 ) ;
}
F_83 ( V_23 -> V_152 ) ;
F_83 ( V_23 -> V_153 ) ;
F_83 ( V_23 -> V_154 ) ;
}
struct V_7 * F_104 ( const char * type ,
int V_41 , int V_39 , void * V_137 ,
const struct V_158 * V_27 ,
const struct V_43 * V_14 ,
int V_53 , int V_54 )
{
struct V_7 * V_23 ;
enum V_55 V_56 ;
int V_78 ;
int V_65 ;
int V_52 = 0 ;
if ( type && strlen ( type ) >= V_4 )
return F_94 ( - V_8 ) ;
if ( V_41 > V_159 || V_41 < 0 || V_39 > > V_41 )
return F_94 ( - V_8 ) ;
if ( ! V_27 || ! V_27 -> V_67 )
return F_94 ( - V_8 ) ;
if ( V_41 > 0 && ! V_27 -> V_62 )
return F_94 ( - V_8 ) ;
V_23 = F_72 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_23 )
return F_94 ( - V_108 ) ;
F_73 ( & V_23 -> V_132 ) ;
F_105 ( & V_23 -> V_17 ) ;
F_95 ( & V_23 -> V_19 ) ;
V_78 = F_10 ( & V_160 , & V_140 , & V_23 -> V_20 ) ;
if ( V_78 ) {
F_83 ( V_23 ) ;
return F_94 ( V_78 ) ;
}
strcpy ( V_23 -> type , type ? : L_26 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_14 = V_14 ;
V_23 -> V_38 . V_142 = & V_143 ;
V_23 -> V_137 = V_137 ;
V_23 -> V_41 = V_41 ;
V_23 -> V_53 = V_53 ;
V_23 -> V_54 = V_54 ;
F_96 ( & V_23 -> V_38 , L_28 , V_23 -> V_20 ) ;
V_78 = F_97 ( & V_23 -> V_38 ) ;
if ( V_78 ) {
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_83 ( V_23 ) ;
return F_94 ( V_78 ) ;
}
if ( type ) {
V_78 = F_79 ( & V_23 -> V_38 , & V_161 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_79 ( & V_23 -> V_38 , & V_162 ) ;
if ( V_78 )
goto V_145;
if ( V_27 -> V_79 ) {
V_78 = F_79 ( & V_23 -> V_38 , & V_163 ) ;
if ( V_78 )
goto V_145;
}
V_78 = F_102 ( V_23 , V_39 ) ;
if ( V_78 )
goto V_145;
for ( V_65 = 0 ; V_65 < V_41 ; V_65 ++ ) {
V_23 -> V_27 -> V_62 ( V_23 , V_65 , & V_56 ) ;
if ( V_56 == V_84 )
V_52 = 1 ;
}
if ( ! V_52 ) {
V_78 = F_79 ( & V_23 -> V_38 , & V_164 ) ;
if ( V_78 )
goto V_145;
}
#ifdef F_37
V_78 = F_79 ( & V_23 -> V_38 , & V_165 ) ;
if ( V_78 )
goto V_145;
#endif
V_78 = F_79 ( & V_23 -> V_38 , & V_166 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_9 ) ;
if ( V_23 -> V_14 )
V_23 -> V_5 = F_1 ( V_23 -> V_14 -> V_15 ) ;
else
V_23 -> V_5 = F_1 ( V_16 ) ;
F_7 ( & V_9 ) ;
V_78 = F_71 ( V_23 ) ;
if ( V_78 )
goto V_145;
F_5 ( & V_13 ) ;
F_81 ( & V_23 -> V_117 , & V_167 ) ;
F_7 ( & V_13 ) ;
F_24 ( V_23 ) ;
F_106 ( & ( V_23 -> V_51 ) , F_41 ) ;
F_40 ( V_23 ) ;
if ( ! V_78 )
return V_23 ;
V_145:
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_98 ( & V_23 -> V_38 ) ;
return F_94 ( V_78 ) ;
}
void F_107 ( struct V_7 * V_23 )
{
int V_40 ;
const struct V_43 * V_14 ;
struct V_35 * V_36 ;
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
if ( V_23 -> V_27 -> V_135 ) {
V_23 -> V_27 -> V_135 ( V_23 , V_36 ) ;
continue;
}
if ( ! V_14 || ! V_14 -> V_45 )
break;
for ( V_40 = 0 ; V_40 < V_14 -> V_46 ; V_40 ++ ) {
if ( V_14 -> V_45 [ V_40 ] . V_36 == V_36 ) {
F_21 ( V_23 , V_14 -> V_45 [ V_40 ] . V_48 , V_36 ) ;
V_14 -> V_45 [ V_40 ] . V_36 = NULL ;
}
}
}
F_7 ( & V_13 ) ;
F_25 ( V_23 , 0 ) ;
if ( V_23 -> type [ 0 ] )
F_82 ( & V_23 -> V_38 , & V_161 ) ;
F_82 ( & V_23 -> V_38 , & V_162 ) ;
if ( V_23 -> V_27 -> V_79 )
F_82 ( & V_23 -> V_38 , & V_163 ) ;
F_82 ( & V_23 -> V_38 , & V_166 ) ;
F_103 ( V_23 ) ;
V_23 -> V_5 = NULL ;
F_85 ( V_23 ) ;
F_13 ( & V_160 , & V_140 , V_23 -> V_20 ) ;
F_108 ( & V_23 -> V_17 ) ;
F_109 ( & V_23 -> V_19 ) ;
F_98 ( & V_23 -> V_38 ) ;
return;
}
int F_110 ( struct V_7 * V_23 ,
enum V_168 V_169 )
{
struct V_170 * V_171 ;
struct V_172 * V_74 ;
struct V_173 * V_174 ;
void * V_175 ;
int V_150 ;
int V_78 ;
static unsigned int V_176 ;
if ( ! V_23 )
return - V_8 ;
V_150 = F_111 ( sizeof( struct V_173 ) ) +
F_111 ( 0 ) ;
V_171 = F_112 ( V_150 , V_177 ) ;
if ( ! V_171 )
return - V_108 ;
V_175 = F_113 ( V_171 , 0 , V_176 ++ ,
& V_178 , 0 ,
V_179 ) ;
if ( ! V_175 ) {
F_114 ( V_171 ) ;
return - V_108 ;
}
V_74 = F_115 ( V_171 , V_180 ,
sizeof( struct V_173 ) ) ;
if ( ! V_74 ) {
F_114 ( V_171 ) ;
return - V_8 ;
}
V_174 = F_116 ( V_74 ) ;
if ( ! V_174 ) {
F_114 ( V_171 ) ;
return - V_8 ;
}
memset ( V_174 , 0 , sizeof( struct V_173 ) ) ;
V_174 -> V_181 = V_23 -> V_20 ;
V_174 -> V_169 = V_169 ;
V_78 = F_117 ( V_171 , V_175 ) ;
if ( V_78 < 0 ) {
F_114 ( V_171 ) ;
return V_78 ;
}
V_78 = F_118 ( V_171 , 0 , V_182 . V_20 , V_177 ) ;
if ( V_78 )
F_18 ( & V_23 -> V_38 , L_29 , V_78 ) ;
return V_78 ;
}
static int F_119 ( void )
{
int V_78 ;
V_78 = F_120 ( & V_178 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_121 ( & V_178 ,
& V_182 ) ;
if ( V_78 )
F_122 ( & V_178 ) ;
return V_78 ;
}
static void F_123 ( void )
{
F_122 ( & V_178 ) ;
}
static inline int F_119 ( void ) { return 0 ; }
static inline void F_123 ( void ) {}
static int T_3 F_124 ( void )
{
int V_78 = 0 ;
V_78 = F_125 ( & V_143 ) ;
if ( V_78 ) {
F_108 ( & V_160 ) ;
F_108 ( & V_139 ) ;
F_109 ( & V_140 ) ;
F_109 ( & V_13 ) ;
return V_78 ;
}
V_78 = F_119 () ;
return V_78 ;
}
static void T_4 F_126 ( void )
{
F_127 ( & V_143 ) ;
F_108 ( & V_160 ) ;
F_108 ( & V_139 ) ;
F_109 ( & V_140 ) ;
F_109 ( & V_13 ) ;
F_123 () ;
}
