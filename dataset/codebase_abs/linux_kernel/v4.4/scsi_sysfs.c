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
F_32 ( V_61 ) ;
V_65 = V_61 -> V_62 . V_65 ;
F_22 ( V_61 -> V_70 -> V_56 , V_52 ) ;
F_33 ( & V_61 -> V_71 ) ;
F_33 ( & V_61 -> V_72 ) ;
F_33 ( & V_61 -> V_73 ) ;
F_24 ( V_61 -> V_70 -> V_56 , V_52 ) ;
F_34 ( & V_61 -> V_74 ) ;
F_35 (this, tmp, &sdev->event_list) {
struct V_75 * V_76 ;
V_76 = F_36 ( V_67 , struct V_75 , V_77 ) ;
F_33 ( & V_76 -> V_77 ) ;
F_37 ( V_76 ) ;
}
F_38 ( V_61 -> V_78 ) ;
V_61 -> V_78 = NULL ;
F_37 ( V_61 -> V_79 ) ;
F_37 ( V_61 -> V_80 ) ;
F_37 ( V_61 -> V_81 ) ;
F_37 ( V_61 ) ;
if ( V_65 )
F_29 ( V_65 ) ;
}
static void F_39 ( struct V_27 * V_28 )
{
struct V_60 * V_82 = F_40 ( V_28 ) ;
F_41 ( F_30 ,
& V_82 -> V_69 ) ;
}
static int F_42 ( struct V_27 * V_28 , struct V_83 * V_84 )
{
struct V_60 * V_82 ;
if ( V_28 -> type != & V_85 )
return 0 ;
V_82 = F_40 ( V_28 ) ;
if ( V_82 -> V_86 )
return 0 ;
return ( V_82 -> V_87 == V_88 ) ? 1 : 0 ;
}
static int F_43 ( struct V_27 * V_28 , struct V_89 * V_90 )
{
struct V_60 * V_61 ;
if ( V_28 -> type != & V_85 )
return 0 ;
V_61 = F_40 ( V_28 ) ;
F_44 ( V_90 , L_18 V_91 , V_61 -> type ) ;
return 0 ;
}
int F_45 ( void )
{
int error ;
error = F_46 ( & V_92 ) ;
if ( ! error ) {
error = F_47 ( & V_93 ) ;
if ( error )
F_48 ( & V_92 ) ;
}
return error ;
}
void F_49 ( void )
{
F_50 ( & V_93 ) ;
F_48 ( & V_92 ) ;
}
static T_1
F_51 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , F_26 ( & V_61 -> V_94 ) ) ;
}
static T_1
F_52 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , F_26 ( & V_61 -> V_95 ) ) ;
}
static T_1
F_53 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_17 , V_61 -> V_78 -> V_96 / V_50 ) ;
}
static T_1
F_54 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 ;
int V_97 ;
V_61 = F_40 ( V_28 ) ;
sscanf ( V_31 , L_17 , & V_97 ) ;
F_55 ( V_61 -> V_78 , V_97 * V_50 ) ;
return V_32 ;
}
static T_1
F_56 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_61 -> V_98 / V_50 ) ;
}
static T_1
F_57 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 ;
unsigned int V_98 ;
int V_99 ;
if ( ! F_58 ( V_100 ) )
return - V_101 ;
V_61 = F_40 ( V_28 ) ;
V_99 = F_59 ( V_31 , 10 , & V_98 ) ;
if ( V_99 )
return V_99 ;
V_61 -> V_98 = V_98 * V_50 ;
return V_32 ;
}
static T_1
F_60 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_61 ( V_28 ) ;
return V_32 ;
}
static T_1
F_62 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
if ( F_63 ( V_28 , V_30 ) )
F_64 ( F_40 ( V_28 ) ) ;
return V_32 ;
}
static T_1
F_65 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_60 * V_61 = F_40 ( V_28 ) ;
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
if ( F_66 ( V_61 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_67 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
const char * V_4 = F_1 ( V_61 -> V_102 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_68 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
const char * V_4 = L_19 ;
if ( V_61 -> V_103 )
V_4 = L_20 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_69 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
if ( ! V_61 -> V_104 )
return - V_24 ;
F_70 ( V_105 , V_61 ,
L_21 ) ;
return V_32 ;
}
static T_1 F_71 ( struct V_106 * V_107 , struct V_108 * V_109 ,
struct V_110 * V_111 ,
char * V_31 , T_3 V_112 , T_2 V_32 )
{
struct V_27 * V_28 = F_31 ( V_109 , struct V_27 , V_109 ) ;
struct V_60 * V_61 = F_40 ( V_28 ) ;
if ( ! V_61 -> V_81 )
return - V_24 ;
return F_72 ( V_31 , V_32 , & V_112 , V_61 -> V_81 ,
V_61 -> V_113 ) ;
}
static T_1
F_73 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
return snprintf ( V_31 , 20 , L_17 , ( int ) sizeof( V_114 ) * 8 ) ;
}
static T_1
F_74 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_91 L_10 , V_61 -> type ) ;
}
static T_1
F_75 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_115 , V_116 ;
struct V_60 * V_61 = F_40 ( V_28 ) ;
struct V_44 * V_45 = V_61 -> V_70 -> V_39 ;
if ( ! V_45 -> V_117 )
return - V_24 ;
V_115 = F_76 ( V_31 , NULL , 0 ) ;
if ( V_115 < 1 || V_115 > V_61 -> V_70 -> V_118 )
return - V_24 ;
V_116 = V_45 -> V_117 ( V_61 , V_115 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 -> V_119 = V_61 -> V_120 ;
return V_32 ;
}
static T_1
F_77 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_60 * V_61 ;
V_61 = F_40 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_78 ( V_61 -> V_121 ) ) ;
}
static T_1
F_79 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_60 * V_61 = F_40 ( V_28 ) ;
unsigned int V_122 ;
if ( F_59 ( V_31 , 10 , & V_122 ) )
return - V_24 ;
V_61 -> V_121 = F_80 ( V_122 ) ;
return V_32 ;
}
static T_4 F_81 ( struct V_108 * V_109 ,
struct V_123 * V_30 , int V_3 )
{
struct V_27 * V_28 = F_31 ( V_109 , struct V_27 , V_109 ) ;
struct V_60 * V_61 = F_40 ( V_28 ) ;
if ( V_30 == & V_124 . V_30 &&
! V_61 -> V_70 -> V_39 -> V_117 )
return V_125 ;
if ( V_30 == & V_126 . V_30 &&
! V_61 -> V_70 -> V_39 -> V_117 )
return 0 ;
return V_30 -> V_35 ;
}
static int F_82 ( struct V_127 * V_128 )
{
int error ;
if ( V_128 -> V_2 != V_129 )
return 0 ;
error = F_83 ( & V_128 -> V_28 ) ;
if ( error ) {
F_84 ( & V_128 -> V_28 , L_22 , error ) ;
return error ;
}
F_85 ( & V_128 -> V_28 ) ;
V_128 -> V_2 = V_130 ;
F_86 ( & V_128 -> V_28 ) ;
F_87 ( & V_128 -> V_28 ) ;
F_88 ( & V_128 -> V_28 ) ;
return 0 ;
}
int F_89 ( struct V_60 * V_61 )
{
int error , V_3 ;
struct V_78 * V_131 = V_61 -> V_78 ;
struct V_127 * V_128 = V_61 -> V_132 ;
error = F_66 ( V_61 , V_133 ) ;
if ( error )
return error ;
error = F_82 ( V_128 ) ;
if ( error )
return error ;
F_90 ( & V_128 -> V_28 ) ;
F_88 ( & V_61 -> V_62 ) ;
F_91 ( V_128 ) ;
F_86 ( & V_61 -> V_62 ) ;
F_92 ( & V_61 -> V_62 ) ;
F_87 ( & V_61 -> V_62 ) ;
F_93 ( V_128 ) ;
F_94 ( V_61 ) ;
error = F_83 ( & V_61 -> V_62 ) ;
if ( error ) {
F_70 ( V_105 , V_61 ,
L_23 , error ) ;
return error ;
}
error = F_95 ( V_61 ) ;
if ( error ) {
F_70 ( V_105 , V_61 ,
L_24 , error ) ;
return error ;
}
F_88 ( & V_61 -> V_134 ) ;
error = F_83 ( & V_61 -> V_134 ) ;
if ( error ) {
F_70 ( V_105 , V_61 ,
L_25 , error ) ;
F_96 ( V_61 ) ;
F_97 ( & V_61 -> V_62 ) ;
return error ;
}
F_85 ( & V_61 -> V_62 ) ;
V_61 -> V_135 = 1 ;
error = F_98 ( V_131 , & V_61 -> V_62 , NULL , NULL ) ;
if ( error )
F_70 ( V_105 , V_61 ,
L_26 , error ) ;
if ( V_61 -> V_70 -> V_39 -> V_136 ) {
for ( V_3 = 0 ; V_61 -> V_70 -> V_39 -> V_136 [ V_3 ] ; V_3 ++ ) {
error = F_99 ( & V_61 -> V_62 ,
V_61 -> V_70 -> V_39 -> V_136 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_100 ( V_61 ) ;
return error ;
}
void F_101 ( struct V_60 * V_61 )
{
struct V_27 * V_28 = & V_61 -> V_62 ;
if ( V_61 -> V_102 == V_137 )
return;
if ( V_61 -> V_135 ) {
if ( F_66 ( V_61 , V_138 ) != 0 )
return;
F_102 ( V_61 -> V_78 ) ;
F_103 ( & V_61 -> V_134 ) ;
F_104 ( V_28 ) ;
F_96 ( V_61 ) ;
F_97 ( V_28 ) ;
} else
F_29 ( & V_61 -> V_134 ) ;
F_66 ( V_61 , V_137 ) ;
F_105 ( V_61 -> V_78 ) ;
F_34 ( & V_61 -> V_139 ) ;
if ( V_61 -> V_70 -> V_39 -> V_140 )
V_61 -> V_70 -> V_39 -> V_140 ( V_61 ) ;
F_106 ( V_28 ) ;
F_107 ( V_127 ( V_61 ) ) ;
F_29 ( V_28 ) ;
}
void F_64 ( struct V_60 * V_61 )
{
struct V_13 * V_14 = V_61 -> V_70 ;
F_108 ( & V_14 -> V_141 ) ;
F_101 ( V_61 ) ;
F_109 ( & V_14 -> V_141 ) ;
}
static void F_110 ( struct V_127 * V_128 )
{
struct V_13 * V_14 = F_111 ( V_128 -> V_28 . V_65 ) ;
unsigned long V_52 ;
struct V_60 * V_61 ;
F_22 ( V_14 -> V_56 , V_52 ) ;
V_142:
F_112 (sdev, &shost->__devices, siblings) {
if ( V_61 -> V_20 != V_128 -> V_20 ||
V_61 -> V_21 != V_128 -> V_21 ||
F_113 ( V_61 ) )
continue;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_64 ( V_61 ) ;
F_114 ( V_61 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
goto V_142;
}
F_24 ( V_14 -> V_56 , V_52 ) ;
}
void F_115 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_111 ( V_28 -> V_65 ) ;
struct V_127 * V_128 ;
unsigned long V_52 ;
V_142:
F_22 ( V_14 -> V_56 , V_52 ) ;
F_112 (starget, &shost->__targets, siblings) {
if ( V_128 -> V_2 == V_143 )
continue;
if ( V_128 -> V_28 . V_65 == V_28 || & V_128 -> V_28 == V_28 ) {
F_116 ( & V_128 -> V_144 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_110 ( V_128 ) ;
F_107 ( V_128 ) ;
goto V_142;
}
}
F_24 ( V_14 -> V_56 , V_52 ) ;
}
int F_117 ( struct V_83 * V_145 )
{
V_145 -> V_146 = & V_92 ;
return F_118 ( V_145 ) ;
}
int F_119 ( struct V_147 * V_148 )
{
V_148 -> V_149 = & V_93 ;
return F_120 ( V_148 ) ;
}
int F_121 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_150 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_150 [ V_3 ] ; V_3 ++ ) {
error = F_99 ( & V_14 -> V_151 ,
V_14 -> V_39 -> V_150 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_122 ( & V_14 -> V_152 ) ;
F_90 ( & V_14 -> V_152 ) ;
return 0 ;
}
void F_123 ( struct V_60 * V_61 )
{
unsigned long V_52 ;
struct V_13 * V_14 = V_61 -> V_70 ;
struct V_127 * V_128 = V_61 -> V_132 ;
F_124 ( & V_61 -> V_62 ) ;
V_61 -> V_62 . V_146 = & V_92 ;
V_61 -> V_62 . type = & V_85 ;
F_125 ( & V_61 -> V_62 , L_27 ,
V_61 -> V_70 -> V_153 , V_61 -> V_20 , V_61 -> V_21 , V_61 -> V_22 ) ;
F_124 ( & V_61 -> V_134 ) ;
V_61 -> V_134 . V_65 = F_126 ( & V_61 -> V_62 ) ;
V_61 -> V_134 . V_149 = & V_93 ;
F_125 ( & V_61 -> V_134 , L_27 ,
V_61 -> V_70 -> V_153 , V_61 -> V_20 , V_61 -> V_21 , V_61 -> V_22 ) ;
V_61 -> V_154 = V_128 -> V_154 ;
if ( V_61 -> V_154 <= V_155 &&
V_61 -> V_154 != V_156 &&
! V_14 -> V_157 )
V_61 -> V_158 = 1 ;
F_127 ( & V_61 -> V_62 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
F_128 ( & V_61 -> V_72 , & V_128 -> V_159 ) ;
F_128 ( & V_61 -> V_71 , & V_14 -> V_160 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_116 ( & V_128 -> V_144 ) ;
}
int F_129 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_85 ;
}
