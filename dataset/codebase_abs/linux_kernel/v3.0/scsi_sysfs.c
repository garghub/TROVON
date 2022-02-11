const char * F_1 ( enum V_1 V_2 )
{
int V_3 ;
char * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_6 == V_2 ) {
V_4 = V_5 [ V_3 ] . V_4 ;
break;
}
}
return V_4 ;
}
const char * F_3 ( enum V_7 V_2 )
{
int V_3 ;
char * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
if ( V_8 [ V_3 ] . V_6 == V_2 ) {
V_4 = V_8 [ V_3 ] . V_4 ;
break;
}
}
return V_4 ;
}
static int F_4 ( unsigned int * V_9 , char * V_10 )
{
char * V_11 ;
if ( strncmp ( V_10 , L_1 , 20 ) == 0 ) {
* V_9 = V_12 ;
} else {
* V_9 = F_5 ( V_10 , & V_11 , 0 ) ;
if ( * V_11 != '\0' )
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_13 * V_14 , const char * V_15 )
{
char V_16 [ 15 ] , V_17 [ 15 ] , V_18 [ 15 ] , V_19 ;
unsigned int V_20 , V_21 , V_22 ;
int V_23 ;
V_23 = sscanf ( V_15 , L_2 , V_16 , V_17 , V_18 , & V_19 ) ;
if ( V_23 != 3 )
return - V_24 ;
if ( F_4 ( & V_20 , V_16 ) )
return - V_24 ;
if ( F_4 ( & V_21 , V_17 ) )
return - V_24 ;
if ( F_4 ( & V_22 , V_18 ) )
return - V_24 ;
if ( V_14 -> V_25 -> V_26 )
V_23 = V_14 -> V_25 -> V_26 ( V_14 , V_20 , V_21 , V_22 ) ;
else
V_23 = F_7 ( V_14 , V_20 , V_21 , V_22 , 1 ) ;
return V_23 ;
}
static T_1
F_8 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
int V_23 ;
V_23 = F_6 ( V_14 , V_31 ) ;
if ( V_23 == 0 )
V_23 = V_32 ;
return V_23 ;
}
static T_1
F_10 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_13 * V_14 = F_9 ( V_28 ) ;
enum V_7 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
const int V_33 = strlen ( V_8 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_8 [ V_3 ] . V_4 , V_31 , V_33 ) == 0 &&
V_31 [ V_33 ] == '\n' ) {
V_2 = V_8 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_24 ;
if ( F_11 ( V_14 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_12 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
const char * V_4 = F_3 ( V_14 -> V_34 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_13 ( unsigned int V_35 , char * V_31 )
{
T_1 V_33 = 0 ;
if ( V_35 & V_36 )
V_33 = sprintf ( V_31 , L_4 , L_5 ) ;
if ( V_35 & V_37 )
V_33 += sprintf ( V_31 + V_33 , L_6 , V_33 ? L_7 : L_8 , L_9 ) ;
V_33 += sprintf ( V_31 + V_33 , L_10 ) ;
return V_33 ;
}
static T_1
F_14 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
unsigned int V_38 = V_14 -> V_39 -> V_38 ;
if ( V_38 == V_40 )
V_38 = V_36 ;
return F_13 ( V_38 , V_31 ) ;
}
static T_1
F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
if ( V_14 -> V_41 == V_40 )
return snprintf ( V_31 , 20 , L_11 ) ;
else
return F_13 ( V_14 -> V_41 , V_31 ) ;
}
static void F_16 ( struct V_27 * V_42 )
{
struct V_43 * V_44 ;
V_44 = F_17 ( V_42 ) ;
F_18 ( & V_44 -> V_45 ) ;
}
static void F_19 ( struct V_46 * V_47 )
{
struct V_43 * V_44 ;
struct V_27 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 , * V_53 ;
unsigned long V_54 ;
V_44 = F_20 ( V_47 , struct V_43 , V_55 . V_47 ) ;
V_48 = V_44 -> V_45 . V_48 ;
V_50 = F_21 ( V_48 ) ;
F_22 ( V_44 -> V_56 -> V_57 , V_54 ) ;
V_50 -> V_58 ++ ;
F_23 ( & V_44 -> V_59 ) ;
F_23 ( & V_44 -> V_60 ) ;
F_23 ( & V_44 -> V_61 ) ;
F_24 ( V_44 -> V_56 -> V_57 , V_54 ) ;
F_25 ( & V_44 -> V_62 ) ;
F_26 (this, tmp, &sdev->event_list) {
struct V_63 * V_64 ;
V_64 = F_27 ( V_52 , struct V_63 , V_65 ) ;
F_23 ( & V_64 -> V_65 ) ;
F_28 ( V_64 ) ;
}
F_29 ( V_44 -> V_66 ) ;
V_44 -> V_66 = NULL ;
F_30 ( V_49 ( V_44 ) ) ;
F_28 ( V_44 -> V_67 ) ;
F_28 ( V_44 ) ;
if ( V_48 )
F_18 ( V_48 ) ;
}
static void F_31 ( struct V_27 * V_28 )
{
struct V_43 * V_68 = F_32 ( V_28 ) ;
F_33 ( F_19 ,
& V_68 -> V_55 ) ;
}
static int F_34 ( struct V_27 * V_28 , struct V_69 * V_70 )
{
struct V_43 * V_68 ;
if ( V_28 -> type != & V_71 )
return 0 ;
V_68 = F_32 ( V_28 ) ;
if ( V_68 -> V_72 )
return 0 ;
return ( V_68 -> V_73 == V_74 ) ? 1 : 0 ;
}
static int F_35 ( struct V_27 * V_28 , struct V_75 * V_76 )
{
struct V_43 * V_44 ;
if ( V_28 -> type != & V_71 )
return 0 ;
V_44 = F_32 ( V_28 ) ;
F_36 ( V_76 , L_12 V_77 , V_44 -> type ) ;
return 0 ;
}
int F_37 ( void )
{
int error ;
error = F_38 ( & V_78 ) ;
if ( ! error ) {
error = F_39 ( & V_79 ) ;
if ( error )
F_40 ( & V_78 ) ;
}
return error ;
}
void F_41 ( void )
{
F_42 ( & V_79 ) ;
F_40 ( & V_78 ) ;
}
static T_1
F_43 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_43 * V_44 ;
V_44 = F_32 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_13 , V_44 -> V_66 -> V_80 / V_81 ) ;
}
static T_1
F_44 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_43 * V_44 ;
int V_82 ;
V_44 = F_32 ( V_28 ) ;
sscanf ( V_31 , L_13 , & V_82 ) ;
F_45 ( V_44 -> V_66 , V_82 * V_81 ) ;
return V_32 ;
}
static T_1
F_46 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_47 ( V_28 ) ;
return V_32 ;
}
static void F_48 ( struct V_27 * V_28 )
{
F_49 ( F_32 ( V_28 ) ) ;
}
static T_1
F_50 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_83 ;
V_83 = F_51 ( V_28 , F_48 ) ;
if ( V_83 )
V_32 = V_83 ;
return V_32 ;
}
static T_1
F_52 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_43 * V_44 = F_32 ( V_28 ) ;
enum V_1 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
const int V_33 = strlen ( V_5 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_5 [ V_3 ] . V_4 , V_31 , V_33 ) == 0 &&
V_31 [ V_33 ] == '\n' ) {
V_2 = V_5 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_24 ;
if ( F_53 ( V_44 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_54 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_43 * V_44 = F_32 ( V_28 ) ;
const char * V_4 = F_1 ( V_44 -> V_84 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_55 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_43 * V_44 = F_32 ( V_28 ) ;
const char * V_4 = L_14 ;
if ( V_44 -> V_85 )
V_4 = L_15 ;
else if ( V_44 -> V_86 )
V_4 = L_16 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_56 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
return snprintf ( V_31 , 20 , L_13 , ( int ) sizeof( V_87 ) * 8 ) ;
}
static T_1
F_57 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_43 * V_44 ;
V_44 = F_32 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_77 L_10 , V_44 -> type ) ;
}
static T_1
F_58 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_88 , V_89 ;
struct V_43 * V_44 = F_32 ( V_28 ) ;
struct V_90 * V_91 = V_44 -> V_56 -> V_39 ;
if ( ! V_91 -> V_92 )
return - V_24 ;
V_88 = F_5 ( V_31 , NULL , 0 ) ;
if ( V_88 < 1 )
return - V_24 ;
V_89 = V_91 -> V_92 ( V_44 , V_88 ,
V_93 ) ;
if ( V_89 < 0 )
return V_89 ;
V_44 -> V_94 = V_44 -> V_95 ;
return V_32 ;
}
static T_1
F_59 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_43 * V_44 ;
V_44 = F_32 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 ,
F_60 ( V_44 -> V_96 ) ) ;
}
static T_1
F_61 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_43 * V_44 = F_32 ( V_28 ) ;
unsigned long V_97 ;
if ( F_62 ( V_31 , 10 , & V_97 ) )
return - V_24 ;
V_44 -> V_96 = F_63 ( V_97 ) ;
return V_97 ;
}
static T_1
F_64 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_43 * V_44 = F_32 ( V_28 ) ;
struct V_90 * V_91 = V_44 -> V_56 -> V_39 ;
int V_98 = 0 , V_89 ;
int V_99 = F_65 ( V_44 ) ;
if ( ! V_44 -> V_100 || ! V_91 -> V_101 )
return - V_24 ;
if ( strncmp ( V_31 , L_15 , 7 ) == 0 )
V_98 = V_102 ;
else if ( strncmp ( V_31 , L_16 , 6 ) == 0 )
V_98 = V_103 ;
else if ( strncmp ( V_31 , L_14 , 4 ) != 0 )
return - V_24 ;
if ( V_98 == V_99 )
return V_32 ;
V_89 = V_91 -> V_101 ( V_44 , V_98 ) ;
if ( V_89 < 0 )
return V_89 ;
return V_32 ;
}
static int F_66 ( struct V_49 * V_50 )
{
int error ;
if ( V_50 -> V_2 != V_104 )
return 0 ;
error = F_67 ( & V_50 -> V_28 ) ;
if ( error ) {
F_68 ( & V_50 -> V_28 , L_18 , error ) ;
return error ;
}
F_69 ( & V_50 -> V_28 ) ;
V_50 -> V_2 = V_105 ;
F_70 ( & V_50 -> V_28 ) ;
F_71 ( & V_50 -> V_28 ) ;
F_72 ( & V_50 -> V_28 ) ;
return 0 ;
}
int F_73 ( struct V_43 * V_44 )
{
int error , V_3 ;
struct V_66 * V_106 = V_44 -> V_66 ;
struct V_49 * V_50 = V_44 -> V_107 ;
error = F_53 ( V_44 , V_108 ) ;
if ( error )
return error ;
error = F_66 ( V_50 ) ;
if ( error )
return error ;
F_74 ( & V_50 -> V_28 ) ;
F_72 ( & V_44 -> V_45 ) ;
F_75 ( V_50 ) ;
F_70 ( & V_44 -> V_45 ) ;
F_76 ( & V_44 -> V_45 ) ;
F_71 ( & V_44 -> V_45 ) ;
F_77 ( V_50 ) ;
F_78 ( V_44 ) ;
error = F_67 ( & V_44 -> V_45 ) ;
if ( error ) {
F_79 ( V_109 , V_44 ,
L_19 , error ) ;
return error ;
}
F_72 ( & V_44 -> V_110 ) ;
error = F_67 ( & V_44 -> V_110 ) ;
if ( error ) {
F_79 ( V_109 , V_44 ,
L_20 , error ) ;
F_80 ( & V_44 -> V_45 ) ;
return error ;
}
F_69 ( & V_44 -> V_45 ) ;
V_44 -> V_111 = 1 ;
if ( V_44 -> V_56 -> V_39 -> V_92 ) {
error = F_81 ( & V_44 -> V_45 ,
& V_112 ) ;
error = F_81 ( & V_44 -> V_45 ,
& V_113 ) ;
}
else
error = F_81 ( & V_44 -> V_45 , & V_114 ) ;
if ( error )
return error ;
if ( V_44 -> V_56 -> V_39 -> V_101 )
error = F_81 ( & V_44 -> V_45 , & V_115 ) ;
else
error = F_81 ( & V_44 -> V_45 , & V_116 ) ;
if ( error )
return error ;
error = F_82 ( V_106 , & V_44 -> V_45 , NULL , NULL ) ;
if ( error )
F_79 ( V_109 , V_44 ,
L_21 , error ) ;
if ( V_44 -> V_56 -> V_39 -> V_117 ) {
for ( V_3 = 0 ; V_44 -> V_56 -> V_39 -> V_117 [ V_3 ] ; V_3 ++ ) {
error = F_81 ( & V_44 -> V_45 ,
V_44 -> V_56 -> V_39 -> V_117 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_83 ( struct V_43 * V_44 )
{
struct V_27 * V_28 = & V_44 -> V_45 ;
if ( V_44 -> V_111 ) {
if ( F_53 ( V_44 , V_118 ) != 0 )
return;
F_84 ( V_44 -> V_66 ) ;
F_85 ( & V_44 -> V_110 ) ;
F_86 ( V_28 ) ;
F_80 ( V_28 ) ;
} else
F_18 ( & V_44 -> V_110 ) ;
F_53 ( V_44 , V_119 ) ;
if ( V_44 -> V_56 -> V_39 -> V_120 )
V_44 -> V_56 -> V_39 -> V_120 ( V_44 ) ;
F_87 ( V_28 ) ;
V_44 -> V_66 -> V_121 = NULL ;
F_88 ( V_44 -> V_66 ) ;
F_18 ( V_28 ) ;
}
void F_49 ( struct V_43 * V_44 )
{
struct V_13 * V_14 = V_44 -> V_56 ;
F_89 ( & V_14 -> V_122 ) ;
F_83 ( V_44 ) ;
F_90 ( & V_14 -> V_122 ) ;
}
static void F_91 ( struct V_49 * V_50 )
{
struct V_13 * V_14 = F_92 ( V_50 -> V_28 . V_48 ) ;
unsigned long V_54 ;
struct V_43 * V_44 ;
F_22 ( V_14 -> V_57 , V_54 ) ;
V_50 -> V_58 ++ ;
V_123:
F_93 (sdev, &shost->__devices, siblings) {
if ( V_44 -> V_20 != V_50 -> V_20 ||
V_44 -> V_21 != V_50 -> V_21 ||
F_94 ( V_44 ) )
continue;
F_24 ( V_14 -> V_57 , V_54 ) ;
F_49 ( V_44 ) ;
F_95 ( V_44 ) ;
F_22 ( V_14 -> V_57 , V_54 ) ;
goto V_123;
}
F_24 ( V_14 -> V_57 , V_54 ) ;
F_30 ( V_50 ) ;
}
static int F_96 ( struct V_27 * V_28 , void * V_124 )
{
if ( F_97 ( V_28 ) )
F_91 ( F_21 ( V_28 ) ) ;
return 0 ;
}
void F_98 ( struct V_27 * V_28 )
{
if ( F_97 ( V_28 ) ) {
F_91 ( F_21 ( V_28 ) ) ;
return;
}
F_99 ( V_28 ) ;
F_100 ( V_28 , NULL , F_96 ) ;
F_18 ( V_28 ) ;
}
int F_101 ( struct V_69 * V_125 )
{
V_125 -> V_126 = & V_78 ;
return F_102 ( V_125 ) ;
}
int F_103 ( struct V_127 * V_128 )
{
V_128 -> V_129 = & V_79 ;
return F_104 ( V_128 ) ;
}
int F_105 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_130 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_130 [ V_3 ] ; V_3 ++ ) {
error = F_81 ( & V_14 -> V_131 ,
V_14 -> V_39 -> V_130 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_106 ( & V_14 -> V_132 ) ;
F_74 ( & V_14 -> V_132 ) ;
return 0 ;
}
void F_107 ( struct V_43 * V_44 )
{
unsigned long V_54 ;
struct V_13 * V_14 = V_44 -> V_56 ;
struct V_49 * V_50 = V_44 -> V_107 ;
F_108 ( & V_44 -> V_45 ) ;
V_44 -> V_45 . V_126 = & V_78 ;
V_44 -> V_45 . type = & V_71 ;
F_109 ( & V_44 -> V_45 , L_22 ,
V_44 -> V_56 -> V_133 , V_44 -> V_20 , V_44 -> V_21 , V_44 -> V_22 ) ;
F_108 ( & V_44 -> V_110 ) ;
V_44 -> V_110 . V_48 = F_99 ( & V_44 -> V_45 ) ;
V_44 -> V_110 . V_129 = & V_79 ;
F_109 ( & V_44 -> V_110 , L_22 ,
V_44 -> V_56 -> V_133 , V_44 -> V_20 , V_44 -> V_21 , V_44 -> V_22 ) ;
V_44 -> V_134 = V_50 -> V_134 ;
F_110 ( & V_44 -> V_45 ) ;
F_22 ( V_14 -> V_57 , V_54 ) ;
F_111 ( & V_44 -> V_60 , & V_50 -> V_135 ) ;
F_111 ( & V_44 -> V_59 , & V_14 -> V_136 ) ;
F_24 ( V_14 -> V_57 , V_54 ) ;
}
int F_112 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_71 ;
}
