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
static int F_4 ( unsigned long long * V_9 , char * V_10 )
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
char V_16 [ 15 ] , V_17 [ 15 ] , V_18 [ 17 ] , V_19 ;
unsigned long long V_20 , V_21 , V_22 ;
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
static int F_16 ( const char * V_15 )
{
if ( F_17 ( V_15 , L_12 ) )
return V_42 ;
else if ( F_17 ( V_15 , L_13 ) )
return V_43 ;
else
return 0 ;
}
static T_1
F_18 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
struct V_44 * V_45 = V_14 -> V_39 ;
int V_46 = - V_24 ;
int type ;
type = F_16 ( V_31 ) ;
if ( ! type )
goto V_47;
if ( V_45 -> V_48 )
V_46 = V_45 -> V_48 ( V_14 , type ) ;
V_47:
if ( V_46 == 0 )
V_46 = V_32 ;
return V_46 ;
}
static T_1
F_19 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
if ( V_14 -> V_49 == - 1 )
return snprintf ( V_31 , strlen ( L_14 ) + 2 , L_15 ) ;
return sprintf ( V_31 , L_16 , V_14 -> V_49 / V_50 ) ;
}
static T_1
F_20 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
int V_46 = - V_24 ;
unsigned long V_51 , V_52 ;
if ( V_14 -> V_25 &&
( V_14 -> V_25 -> V_53 ||
! V_14 -> V_39 -> V_54 ) )
return V_46 ;
if ( ! strncmp ( V_31 , L_14 , strlen ( L_14 ) ) )
V_51 = - 1 ;
else {
V_46 = F_21 ( V_31 , 10 , & V_51 ) ;
if ( V_46 )
return V_46 ;
if ( V_51 * V_50 > V_55 )
return - V_24 ;
}
F_22 ( V_14 -> V_56 , V_52 ) ;
if ( F_23 ( V_14 ) )
V_46 = - V_57 ;
else {
if ( V_51 == - 1 )
V_14 -> V_49 = - 1 ;
else
V_14 -> V_49 = V_51 * V_50 ;
V_46 = V_32 ;
}
F_24 ( V_14 -> V_56 , V_52 ) ;
return V_46 ;
}
static T_1
F_25 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , F_26 ( & V_14 -> V_58 ) ) ;
}
static void F_27 ( struct V_27 * V_59 )
{
struct V_60 * V_61 ;
V_61 = F_28 ( V_59 ) ;
F_29 ( & V_61 -> V_62 ) ;
}
static void F_30 ( struct V_63 * V_64 )
{
struct V_60 * V_61 ;
struct V_27 * V_65 ;
struct V_66 * V_67 , * V_68 ;
unsigned long V_52 ;
V_61 = F_31 ( V_64 , struct V_60 , V_69 . V_64 ) ;
V_65 = V_61 -> V_62 . V_65 ;
F_22 ( V_61 -> V_70 -> V_56 , V_52 ) ;
F_32 ( & V_61 -> V_71 ) ;
F_32 ( & V_61 -> V_72 ) ;
F_32 ( & V_61 -> V_73 ) ;
F_24 ( V_61 -> V_70 -> V_56 , V_52 ) ;
F_33 ( & V_61 -> V_74 ) ;
F_34 (this, tmp, &sdev->event_list) {
struct V_75 * V_76 ;
V_76 = F_35 ( V_67 , struct V_75 , V_77 ) ;
F_32 ( & V_76 -> V_77 ) ;
F_36 ( V_76 ) ;
}
F_37 ( V_61 -> V_78 ) ;
V_61 -> V_78 = NULL ;
F_36 ( V_61 -> V_79 ) ;
F_36 ( V_61 -> V_80 ) ;
F_36 ( V_61 -> V_81 ) ;
F_36 ( V_61 ) ;
if ( V_65 )
F_29 ( V_65 ) ;
}
static void F_38 ( struct V_27 * V_28 )
{
struct V_60 * V_82 = F_39 ( V_28 ) ;
F_40 ( F_30 ,
& V_82 -> V_69 ) ;
}
static int F_41 ( struct V_27 * V_28 , struct V_83 * V_84 )
{
struct V_60 * V_82 ;
if ( V_28 -> type != & V_85 )
return 0 ;
V_82 = F_39 ( V_28 ) ;
if ( V_82 -> V_86 )
return 0 ;
return ( V_82 -> V_87 == V_88 ) ? 1 : 0 ;
}
static int F_42 ( struct V_27 * V_28 , struct V_89 * V_90 )
{
struct V_60 * V_61 ;
if ( V_28 -> type != & V_85 )
return 0 ;
V_61 = F_39 ( V_28 ) ;
F_43 ( V_90 , L_18 V_91 , V_61 -> type ) ;
return 0 ;
}
int F_44 ( void )
{
int error ;
error = F_45 ( & V_92 ) ;
if ( ! error ) {
error = F_46 ( & V_93 ) ;
if ( error )
F_47 ( & V_92 ) ;
}
return error ;
}
void F_48 ( void )
{
F_49 ( & V_93 ) ;
F_47 ( & V_92 ) ;
}
static T_1
F_50 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , F_26 ( & V_61 -> V_94 ) ) ;
}
static T_1
F_51 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , F_26 ( & V_61 -> V_95 ) ) ;
}
static T_1
F_52 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , V_61 -> V_78 -> V_96 / V_50 ) ;
}
static T_1
F_53 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 ;
int V_97 ;
V_61 = F_39 ( V_28 ) ;
sscanf ( V_31 , L_17 , & V_97 ) ;
F_54 ( V_61 -> V_78 , V_97 * V_50 ) ;
return V_32 ;
}
static T_1
F_55 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_61 -> V_98 / V_50 ) ;
}
static T_1
F_56 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 ;
unsigned int V_98 ;
int V_99 ;
if ( ! F_57 ( V_100 ) )
return - V_101 ;
V_61 = F_39 ( V_28 ) ;
V_99 = F_58 ( V_31 , 10 , & V_98 ) ;
if ( V_99 )
return V_99 ;
V_61 -> V_98 = V_98 * V_50 ;
return V_32 ;
}
static T_1
F_59 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_60 ( V_28 ) ;
return V_32 ;
}
static T_1
F_61 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
if ( F_62 ( V_28 , V_30 ) )
F_63 ( F_39 ( V_28 ) ) ;
return V_32 ;
}
static T_1
F_64 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_60 * V_61 = F_39 ( V_28 ) ;
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
if ( F_65 ( V_61 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_66 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
const char * V_4 = F_1 ( V_61 -> V_102 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_67 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
const char * V_4 = L_19 ;
if ( V_61 -> V_103 )
V_4 = L_20 ;
else if ( V_61 -> V_104 )
V_4 = L_21 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_68 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
struct V_44 * V_45 = V_61 -> V_70 -> V_39 ;
int V_105 = 0 , V_106 ;
int V_107 = F_69 ( V_61 ) ;
if ( ! V_61 -> V_108 || ! V_45 -> V_109 )
return - V_24 ;
if ( strncmp ( V_31 , L_20 , 7 ) == 0 )
V_105 = V_110 ;
else if ( strncmp ( V_31 , L_21 , 6 ) == 0 )
V_105 = V_111 ;
else if ( strncmp ( V_31 , L_19 , 4 ) != 0 )
return - V_24 ;
if ( V_105 == V_107 )
return V_32 ;
V_106 = V_45 -> V_109 ( V_61 , V_105 ) ;
if ( V_106 < 0 )
return V_106 ;
return V_32 ;
}
static T_1
F_70 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
return snprintf ( V_31 , 20 , L_17 , ( int ) sizeof( V_112 ) * 8 ) ;
}
static T_1
F_71 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_91 L_10 , V_61 -> type ) ;
}
static T_1
F_72 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_113 , V_106 ;
struct V_60 * V_61 = F_39 ( V_28 ) ;
struct V_44 * V_45 = V_61 -> V_70 -> V_39 ;
if ( ! V_45 -> V_114 )
return - V_24 ;
V_113 = F_73 ( V_31 , NULL , 0 ) ;
if ( V_113 < 1 )
return - V_24 ;
V_106 = V_45 -> V_114 ( V_61 , V_113 ,
V_115 ) ;
if ( V_106 < 0 )
return V_106 ;
V_61 -> V_116 = V_61 -> V_117 ;
return V_32 ;
}
static T_1
F_74 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_75 ( V_61 -> V_118 ) ) ;
}
static T_1
F_76 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 = F_39 ( V_28 ) ;
unsigned int V_119 ;
if ( F_58 ( V_31 , 10 , & V_119 ) )
return - V_24 ;
V_61 -> V_118 = F_77 ( V_119 ) ;
return V_119 ;
}
static T_3 F_78 ( struct V_120 * V_121 ,
struct V_122 * V_30 , int V_3 )
{
struct V_27 * V_28 = F_31 ( V_121 , struct V_27 , V_121 ) ;
struct V_60 * V_61 = F_39 ( V_28 ) ;
if ( V_30 == & V_123 . V_30 &&
! V_61 -> V_70 -> V_39 -> V_114 )
return V_124 ;
if ( V_30 == & V_125 . V_30 &&
! V_61 -> V_70 -> V_39 -> V_114 )
return 0 ;
if ( V_30 == & V_126 . V_30 &&
! V_61 -> V_70 -> V_39 -> V_109 )
return V_124 ;
return V_30 -> V_35 ;
}
static int F_79 ( struct V_127 * V_128 )
{
int error ;
if ( V_128 -> V_2 != V_129 )
return 0 ;
error = F_80 ( & V_128 -> V_28 ) ;
if ( error ) {
F_81 ( & V_128 -> V_28 , L_22 , error ) ;
return error ;
}
F_82 ( & V_128 -> V_28 ) ;
V_128 -> V_2 = V_130 ;
F_83 ( & V_128 -> V_28 ) ;
F_84 ( & V_128 -> V_28 ) ;
F_85 ( & V_128 -> V_28 ) ;
return 0 ;
}
int F_86 ( struct V_60 * V_61 )
{
int error , V_3 ;
struct V_78 * V_131 = V_61 -> V_78 ;
struct V_127 * V_128 = V_61 -> V_132 ;
error = F_65 ( V_61 , V_133 ) ;
if ( error )
return error ;
error = F_79 ( V_128 ) ;
if ( error )
return error ;
F_87 ( & V_128 -> V_28 ) ;
F_85 ( & V_61 -> V_62 ) ;
F_88 ( V_128 ) ;
F_83 ( & V_61 -> V_62 ) ;
F_89 ( & V_61 -> V_62 ) ;
F_84 ( & V_61 -> V_62 ) ;
F_90 ( V_128 ) ;
F_91 ( V_61 ) ;
error = F_80 ( & V_61 -> V_62 ) ;
if ( error ) {
F_92 ( V_134 , V_61 ,
L_23 , error ) ;
return error ;
}
F_85 ( & V_61 -> V_135 ) ;
error = F_80 ( & V_61 -> V_135 ) ;
if ( error ) {
F_92 ( V_134 , V_61 ,
L_24 , error ) ;
F_93 ( & V_61 -> V_62 ) ;
return error ;
}
F_82 ( & V_61 -> V_62 ) ;
V_61 -> V_136 = 1 ;
error = F_94 ( V_131 , & V_61 -> V_62 , NULL , NULL ) ;
if ( error )
F_92 ( V_134 , V_61 ,
L_25 , error ) ;
if ( V_61 -> V_70 -> V_39 -> V_137 ) {
for ( V_3 = 0 ; V_61 -> V_70 -> V_39 -> V_137 [ V_3 ] ; V_3 ++ ) {
error = F_95 ( & V_61 -> V_62 ,
V_61 -> V_70 -> V_39 -> V_137 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_96 ( struct V_60 * V_61 )
{
struct V_27 * V_28 = & V_61 -> V_62 ;
if ( V_61 -> V_136 ) {
if ( F_65 ( V_61 , V_138 ) != 0 )
return;
F_97 ( V_61 -> V_78 ) ;
F_98 ( & V_61 -> V_135 ) ;
F_99 ( V_28 ) ;
F_93 ( V_28 ) ;
} else
F_29 ( & V_61 -> V_135 ) ;
F_65 ( V_61 , V_139 ) ;
F_100 ( V_61 -> V_78 ) ;
F_33 ( & V_61 -> V_140 ) ;
if ( V_61 -> V_70 -> V_39 -> V_141 )
V_61 -> V_70 -> V_39 -> V_141 ( V_61 ) ;
F_101 ( V_28 ) ;
F_102 ( V_127 ( V_61 ) ) ;
F_29 ( V_28 ) ;
}
void F_63 ( struct V_60 * V_61 )
{
struct V_13 * V_14 = V_61 -> V_70 ;
F_103 ( & V_14 -> V_142 ) ;
F_96 ( V_61 ) ;
F_104 ( & V_14 -> V_142 ) ;
}
static void F_105 ( struct V_127 * V_128 )
{
struct V_13 * V_14 = F_106 ( V_128 -> V_28 . V_65 ) ;
unsigned long V_52 ;
struct V_60 * V_61 ;
F_22 ( V_14 -> V_56 , V_52 ) ;
V_143:
F_107 (sdev, &shost->__devices, siblings) {
if ( V_61 -> V_20 != V_128 -> V_20 ||
V_61 -> V_21 != V_128 -> V_21 ||
F_108 ( V_61 ) )
continue;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_63 ( V_61 ) ;
F_109 ( V_61 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
goto V_143;
}
F_24 ( V_14 -> V_56 , V_52 ) ;
}
void F_110 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_106 ( V_28 -> V_65 ) ;
struct V_127 * V_128 , * V_11 = NULL ;
unsigned long V_52 ;
F_22 ( V_14 -> V_56 , V_52 ) ;
F_107 (starget, &shost->__targets, siblings) {
if ( V_128 -> V_2 == V_144 )
continue;
if ( V_128 -> V_28 . V_65 == V_28 || & V_128 -> V_28 == V_28 ) {
F_111 ( & V_128 -> V_145 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
if ( V_11 )
F_102 ( V_11 ) ;
V_11 = V_128 ;
F_105 ( V_128 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
}
}
F_24 ( V_14 -> V_56 , V_52 ) ;
if ( V_11 )
F_102 ( V_11 ) ;
}
int F_112 ( struct V_83 * V_146 )
{
V_146 -> V_147 = & V_92 ;
return F_113 ( V_146 ) ;
}
int F_114 ( struct V_148 * V_149 )
{
V_149 -> V_150 = & V_93 ;
return F_115 ( V_149 ) ;
}
int F_116 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_151 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_151 [ V_3 ] ; V_3 ++ ) {
error = F_95 ( & V_14 -> V_152 ,
V_14 -> V_39 -> V_151 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_117 ( & V_14 -> V_153 ) ;
F_87 ( & V_14 -> V_153 ) ;
return 0 ;
}
void F_118 ( struct V_60 * V_61 )
{
unsigned long V_52 ;
struct V_13 * V_14 = V_61 -> V_70 ;
struct V_127 * V_128 = V_61 -> V_132 ;
F_119 ( & V_61 -> V_62 ) ;
V_61 -> V_62 . V_147 = & V_92 ;
V_61 -> V_62 . type = & V_85 ;
F_120 ( & V_61 -> V_62 , L_26 ,
V_61 -> V_70 -> V_154 , V_61 -> V_20 , V_61 -> V_21 , V_61 -> V_22 ) ;
F_119 ( & V_61 -> V_135 ) ;
V_61 -> V_135 . V_65 = F_121 ( & V_61 -> V_62 ) ;
V_61 -> V_135 . V_150 = & V_93 ;
F_120 ( & V_61 -> V_135 , L_26 ,
V_61 -> V_70 -> V_154 , V_61 -> V_20 , V_61 -> V_21 , V_61 -> V_22 ) ;
V_61 -> V_155 = V_128 -> V_155 ;
F_122 ( & V_61 -> V_62 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
F_123 ( & V_61 -> V_72 , & V_128 -> V_156 ) ;
F_123 ( & V_61 -> V_71 , & V_14 -> V_157 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_111 ( & V_128 -> V_145 ) ;
}
int F_124 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_85 ;
}
