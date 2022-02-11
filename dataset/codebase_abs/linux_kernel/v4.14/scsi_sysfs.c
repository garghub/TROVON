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
static const char * F_4 ( unsigned char V_2 )
{
int V_3 ;
char * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_9 ) ; V_3 ++ ) {
if ( V_9 [ V_3 ] . V_6 == V_2 ) {
V_4 = V_9 [ V_3 ] . V_4 ;
break;
}
}
return V_4 ;
}
static int F_5 ( unsigned long long * V_10 , char * V_11 )
{
char * V_12 ;
if ( strcmp ( V_11 , L_1 ) == 0 ) {
* V_10 = V_13 ;
} else {
* V_10 = F_6 ( V_11 , & V_12 , 0 ) ;
if ( * V_12 != '\0' )
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_14 * V_15 , const char * V_16 )
{
char V_17 [ 15 ] , V_18 [ 15 ] , V_19 [ 17 ] , V_20 ;
unsigned long long V_21 , V_22 , V_23 ;
int V_24 ;
V_24 = sscanf ( V_16 , L_2 , V_17 , V_18 , V_19 , & V_20 ) ;
if ( V_24 != 3 )
return - V_25 ;
if ( F_5 ( & V_21 , V_17 ) )
return - V_25 ;
if ( F_5 ( & V_22 , V_18 ) )
return - V_25 ;
if ( F_5 ( & V_23 , V_19 ) )
return - V_25 ;
if ( V_15 -> V_26 -> V_27 )
V_24 = V_15 -> V_26 -> V_27 ( V_15 , V_21 , V_22 , V_23 ) ;
else
V_24 = F_8 ( V_15 , V_21 , V_22 , V_23 ,
V_28 ) ;
return V_24 ;
}
static T_1
F_9 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
int V_24 ;
V_24 = F_7 ( V_15 , V_33 ) ;
if ( V_24 == 0 )
V_24 = V_34 ;
return V_24 ;
}
static T_1
F_11 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
int V_3 ;
struct V_14 * V_15 = F_10 ( V_30 ) ;
enum V_7 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
const int V_35 = strlen ( V_8 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_8 [ V_3 ] . V_4 , V_33 , V_35 ) == 0 &&
V_33 [ V_35 ] == '\n' ) {
V_2 = V_8 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_25 ;
if ( F_12 ( V_15 , V_2 ) )
return - V_25 ;
return V_34 ;
}
static T_1
F_13 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
const char * V_4 = F_3 ( V_15 -> V_36 ) ;
if ( ! V_4 )
return - V_25 ;
return snprintf ( V_33 , 20 , L_3 , V_4 ) ;
}
static T_1
F_14 ( unsigned int V_37 , char * V_33 )
{
T_1 V_35 = 0 ;
if ( V_37 & V_38 )
V_35 = sprintf ( V_33 , L_4 , L_5 ) ;
if ( V_37 & V_39 )
V_35 += sprintf ( V_33 + V_35 , L_6 , V_35 ? L_7 : L_8 , L_9 ) ;
V_35 += sprintf ( V_33 + V_35 , L_10 ) ;
return V_35 ;
}
static T_1
F_15 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
unsigned int V_40 = V_15 -> V_41 -> V_40 ;
if ( V_40 == V_42 )
V_40 = V_38 ;
return F_14 ( V_40 , V_33 ) ;
}
static T_1
F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
if ( V_15 -> V_43 == V_42 )
return snprintf ( V_33 , 20 , L_11 ) ;
else
return F_14 ( V_15 -> V_43 , V_33 ) ;
}
static int F_17 ( const char * V_16 )
{
if ( F_18 ( V_16 , L_12 ) )
return V_44 ;
else if ( F_18 ( V_16 , L_13 ) )
return V_45 ;
else
return 0 ;
}
static T_1
F_19 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
struct V_46 * V_47 = V_15 -> V_41 ;
int V_48 = - V_25 ;
int type ;
type = F_17 ( V_33 ) ;
if ( ! type )
goto V_49;
if ( V_47 -> V_50 )
V_48 = V_47 -> V_50 ( V_15 , type ) ;
else
V_48 = - V_51 ;
V_49:
if ( V_48 == 0 )
V_48 = V_34 ;
return V_48 ;
}
static T_1
F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
if ( V_15 -> V_52 == - 1 )
return snprintf ( V_33 , strlen ( L_14 ) + 2 , L_15 ) ;
return sprintf ( V_33 , L_16 , V_15 -> V_52 / V_53 ) ;
}
static T_1
F_21 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
int V_48 = - V_25 ;
unsigned long V_54 , V_55 ;
if ( V_15 -> V_26 &&
( V_15 -> V_26 -> V_56 ||
! V_15 -> V_41 -> V_57 ) )
return V_48 ;
if ( ! strncmp ( V_33 , L_14 , strlen ( L_14 ) ) )
V_54 = - 1 ;
else {
V_48 = F_22 ( V_33 , 10 , & V_54 ) ;
if ( V_48 )
return V_48 ;
if ( V_54 * V_53 > V_58 )
return - V_25 ;
}
F_23 ( V_15 -> V_59 , V_55 ) ;
if ( F_24 ( V_15 ) )
V_48 = - V_60 ;
else {
if ( V_54 == - 1 )
V_15 -> V_52 = - 1 ;
else
V_15 -> V_52 = V_54 * V_53 ;
V_48 = V_34 ;
}
F_25 ( V_15 -> V_59 , V_55 ) ;
return V_48 ;
}
static T_1
F_26 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_15 -> V_61 ) ) ;
}
static void F_28 ( struct V_29 * V_62 )
{
struct V_63 * V_64 ;
V_64 = F_29 ( V_62 ) ;
F_30 ( & V_64 -> V_65 ) ;
}
static void F_31 ( struct V_66 * V_67 )
{
struct V_63 * V_64 ;
struct V_29 * V_68 ;
struct V_69 * V_70 , * V_71 ;
struct V_72 * V_73 = NULL , * V_74 = NULL ;
unsigned long V_55 ;
V_64 = F_32 ( V_67 , struct V_63 , V_75 . V_67 ) ;
F_33 ( V_64 ) ;
V_68 = V_64 -> V_65 . V_68 ;
F_23 ( V_64 -> V_76 -> V_59 , V_55 ) ;
F_34 ( & V_64 -> V_77 ) ;
F_34 ( & V_64 -> V_78 ) ;
F_34 ( & V_64 -> V_79 ) ;
F_25 ( V_64 -> V_76 -> V_59 , V_55 ) ;
F_35 ( & V_64 -> V_80 ) ;
F_36 (this, tmp, &sdev->event_list) {
struct V_81 * V_82 ;
V_82 = F_37 ( V_70 , struct V_81 , V_83 ) ;
F_34 ( & V_82 -> V_83 ) ;
F_38 ( V_82 ) ;
}
F_39 ( V_64 -> V_84 ) ;
V_64 -> V_84 = NULL ;
F_40 ( & V_64 -> V_85 ) ;
F_41 ( V_64 -> V_73 , V_73 ,
F_42 ( & V_64 -> V_85 ) ) ;
F_41 ( V_64 -> V_74 , V_74 ,
F_42 ( & V_64 -> V_85 ) ) ;
F_43 ( & V_64 -> V_85 ) ;
if ( V_74 )
F_44 ( V_74 , V_86 ) ;
if ( V_73 )
F_44 ( V_73 , V_86 ) ;
F_38 ( V_64 -> V_87 ) ;
F_38 ( V_64 ) ;
if ( V_68 )
F_30 ( V_68 ) ;
}
static void F_45 ( struct V_29 * V_30 )
{
struct V_63 * V_88 = F_46 ( V_30 ) ;
F_47 ( F_31 ,
& V_88 -> V_75 ) ;
}
static int F_48 ( struct V_29 * V_30 , struct V_89 * V_90 )
{
struct V_63 * V_88 ;
if ( V_30 -> type != & V_91 )
return 0 ;
V_88 = F_46 ( V_30 ) ;
if ( V_88 -> V_92 )
return 0 ;
return ( V_88 -> V_93 == V_94 ) ? 1 : 0 ;
}
static int F_49 ( struct V_29 * V_30 , struct V_95 * V_96 )
{
struct V_63 * V_64 ;
if ( V_30 -> type != & V_91 )
return 0 ;
V_64 = F_46 ( V_30 ) ;
F_50 ( V_96 , L_18 V_97 , V_64 -> type ) ;
return 0 ;
}
int F_51 ( void )
{
int error ;
error = F_52 ( & V_98 ) ;
if ( ! error ) {
error = F_53 ( & V_99 ) ;
if ( error )
F_54 ( & V_98 ) ;
}
return error ;
}
void F_55 ( void )
{
F_56 ( & V_99 ) ;
F_54 ( & V_98 ) ;
}
static T_1
F_57 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_64 -> V_100 ) ) ;
}
static T_1
F_58 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_64 -> V_101 ) ) ;
}
static T_1
F_59 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_63 * V_64 ;
V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , V_64 -> V_84 -> V_102 / V_53 ) ;
}
static T_1
F_60 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_63 * V_64 ;
int V_103 ;
V_64 = F_46 ( V_30 ) ;
sscanf ( V_33 , L_17 , & V_103 ) ;
F_61 ( V_64 -> V_84 , V_103 * V_53 ) ;
return V_34 ;
}
static T_1
F_62 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_63 * V_64 ;
V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_16 , V_64 -> V_104 / V_53 ) ;
}
static T_1
F_63 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_63 * V_64 ;
unsigned int V_104 ;
int V_105 ;
if ( ! F_64 ( V_106 ) )
return - V_107 ;
V_64 = F_46 ( V_30 ) ;
V_105 = F_65 ( V_33 , 10 , & V_104 ) ;
if ( V_105 )
return V_105 ;
V_64 -> V_104 = V_104 * V_53 ;
return V_34 ;
}
static T_1
F_66 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
F_67 ( V_30 ) ;
return V_34 ;
}
static T_1
F_68 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
if ( F_69 ( V_30 , V_32 ) )
F_70 ( F_46 ( V_30 ) ) ;
return V_34 ;
}
static T_1
F_71 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
int V_3 , V_48 ;
struct V_63 * V_64 = F_46 ( V_30 ) ;
enum V_1 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
const int V_35 = strlen ( V_5 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_5 [ V_3 ] . V_4 , V_33 , V_35 ) == 0 &&
V_33 [ V_35 ] == '\n' ) {
V_2 = V_5 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_25 ;
F_40 ( & V_64 -> V_108 ) ;
V_48 = F_72 ( V_64 , V_2 ) ;
F_43 ( & V_64 -> V_108 ) ;
return V_48 == 0 ? V_34 : - V_25 ;
}
static T_1
F_73 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
const char * V_4 = F_1 ( V_64 -> V_109 ) ;
if ( ! V_4 )
return - V_25 ;
return snprintf ( V_33 , 20 , L_3 , V_4 ) ;
}
static T_1
F_74 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
const char * V_4 = L_19 ;
if ( V_64 -> V_110 )
V_4 = L_20 ;
return snprintf ( V_33 , 20 , L_3 , V_4 ) ;
}
static T_1
F_75 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( ! V_64 -> V_111 )
return - V_25 ;
F_76 ( V_112 , V_64 ,
L_21 ) ;
return V_34 ;
}
static T_1 F_77 ( struct V_113 * V_114 , struct V_115 * V_116 ,
struct V_117 * V_118 ,
char * V_33 , T_3 V_119 , T_2 V_34 )
{
struct V_29 * V_30 = F_32 ( V_116 , struct V_29 , V_116 ) ;
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( ! V_64 -> V_87 )
return - V_25 ;
return F_78 ( V_33 , V_34 , & V_119 , V_64 -> V_87 ,
V_64 -> V_120 ) ;
}
static T_1
F_79 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
return snprintf ( V_33 , 20 , L_17 , ( int ) sizeof( V_121 ) * 8 ) ;
}
static T_1
F_80 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_63 * V_64 ;
V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , V_97 L_10 , V_64 -> type ) ;
}
static T_1
F_81 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
int V_122 , V_123 ;
struct V_63 * V_64 = F_46 ( V_30 ) ;
struct V_46 * V_47 = V_64 -> V_76 -> V_41 ;
if ( ! V_47 -> V_124 )
return - V_25 ;
V_122 = F_82 ( V_33 , NULL , 0 ) ;
if ( V_122 < 1 || V_122 > V_64 -> V_76 -> V_125 )
return - V_25 ;
V_123 = V_47 -> V_124 ( V_64 , V_122 ) ;
if ( V_123 < 0 )
return V_123 ;
V_64 -> V_126 = V_64 -> V_127 ;
return V_34 ;
}
static T_1
F_83 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
T_1 V_34 ;
V_34 = F_84 ( V_64 , V_33 , V_128 ) ;
if ( V_34 > 0 ) {
V_33 [ V_34 ] = '\n' ;
V_34 ++ ;
}
return V_34 ;
}
static T_1
F_85 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( ! V_64 -> V_129 )
return snprintf ( V_33 , 20 , L_22 ) ;
return snprintf ( V_33 , 20 , L_3 , V_64 -> V_129 -> V_4 ) ;
}
static T_1
F_86 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
int V_105 = - V_25 ;
if ( V_64 -> V_109 == V_130 ||
V_64 -> V_109 == V_131 )
return - V_132 ;
if ( ! V_64 -> V_129 ) {
V_105 = F_87 ( V_64 -> V_84 , V_33 ) ;
} else if ( ! strncmp ( V_33 , L_23 , 8 ) ) {
if ( V_64 -> V_129 -> V_133 )
V_105 = V_64 -> V_129 -> V_133 ( V_64 , NULL , NULL ) ;
else
V_105 = 0 ;
} else if ( ! strncmp ( V_33 , L_24 , 6 ) ) {
F_76 ( V_134 , V_64 ,
L_25 ,
V_64 -> V_129 -> V_4 ) ;
V_105 = - V_25 ;
}
return V_105 < 0 ? V_105 : V_34 ;
}
static T_1
F_88 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
unsigned char V_135 ;
const char * V_136 ;
if ( ! V_64 -> V_129 )
return - V_25 ;
V_135 = ( V_64 -> V_135 & V_137 ) ;
V_136 = F_4 ( V_135 ) ;
return sprintf ( V_33 , L_3 ,
V_136 ? V_136 : L_26 ) ;
}
static T_1
F_89 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( ! V_64 -> V_129 )
return - V_25 ;
if ( V_64 -> V_135 & V_138 )
return sprintf ( V_33 , L_27 ) ;
else
return sprintf ( V_33 , L_28 ) ;
}
static T_1
F_90 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_63 * V_64 ;
V_64 = F_46 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_16 ,
F_91 ( V_64 -> V_139 ) ) ;
}
static T_1
F_92 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_63 * V_64 = F_46 ( V_30 ) ;
unsigned int V_140 ;
if ( F_65 ( V_33 , 10 , & V_140 ) )
return - V_25 ;
V_64 -> V_139 = F_93 ( V_140 ) ;
return V_34 ;
}
static T_4 F_94 ( struct V_115 * V_116 ,
struct V_141 * V_32 , int V_3 )
{
struct V_29 * V_30 = F_32 ( V_116 , struct V_29 , V_116 ) ;
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( V_32 == & V_142 . V_32 &&
! V_64 -> V_76 -> V_41 -> V_124 )
return V_143 ;
if ( V_32 == & V_144 . V_32 &&
! V_64 -> V_76 -> V_41 -> V_124 )
return 0 ;
#ifdef F_95
if ( V_32 == & V_145 . V_32 &&
! V_64 -> V_129 )
return 0 ;
if ( V_32 == & V_146 . V_32 &&
! V_64 -> V_129 )
return 0 ;
#endif
return V_32 -> V_37 ;
}
static T_4 F_96 ( struct V_115 * V_116 ,
struct V_117 * V_32 , int V_3 )
{
struct V_29 * V_30 = F_32 ( V_116 , struct V_29 , V_116 ) ;
struct V_63 * V_64 = F_46 ( V_30 ) ;
if ( V_32 == & V_147 && ! V_64 -> V_73 )
return 0 ;
if ( V_32 == & V_148 && ! V_64 -> V_74 )
return 0 ;
return V_143 ;
}
static int F_97 ( struct V_149 * V_150 )
{
int error ;
if ( V_150 -> V_2 != V_151 )
return 0 ;
error = F_98 ( & V_150 -> V_30 ) ;
if ( error ) {
F_99 ( & V_150 -> V_30 , L_29 , error ) ;
return error ;
}
F_100 ( & V_150 -> V_30 ) ;
V_150 -> V_2 = V_152 ;
F_101 ( & V_150 -> V_30 ) ;
F_102 ( & V_150 -> V_30 ) ;
F_103 ( & V_150 -> V_30 ) ;
return 0 ;
}
int F_104 ( struct V_63 * V_64 )
{
int error , V_3 ;
struct V_84 * V_153 = V_64 -> V_84 ;
struct V_149 * V_150 = V_64 -> V_154 ;
error = F_97 ( V_150 ) ;
if ( error )
return error ;
F_105 ( & V_150 -> V_30 ) ;
F_103 ( & V_64 -> V_65 ) ;
F_106 ( V_150 ) ;
F_101 ( & V_64 -> V_65 ) ;
F_107 ( & V_64 -> V_65 ) ;
F_102 ( & V_64 -> V_65 ) ;
F_108 ( V_150 ) ;
F_109 ( V_64 ) ;
error = F_110 ( V_64 ) ;
if ( error )
F_76 ( V_112 , V_64 ,
L_30 , error ) ;
error = F_98 ( & V_64 -> V_65 ) ;
if ( error ) {
F_76 ( V_112 , V_64 ,
L_31 , error ) ;
F_111 ( V_64 ) ;
return error ;
}
F_103 ( & V_64 -> V_155 ) ;
error = F_98 ( & V_64 -> V_155 ) ;
if ( error ) {
F_76 ( V_112 , V_64 ,
L_32 , error ) ;
F_111 ( V_64 ) ;
F_112 ( & V_64 -> V_65 ) ;
return error ;
}
F_100 ( & V_64 -> V_65 ) ;
V_64 -> V_156 = 1 ;
error = F_113 ( V_153 , & V_64 -> V_65 , NULL , NULL ) ;
if ( error )
F_76 ( V_112 , V_64 ,
L_33 , error ) ;
if ( V_64 -> V_76 -> V_41 -> V_157 ) {
for ( V_3 = 0 ; V_64 -> V_76 -> V_41 -> V_157 [ V_3 ] ; V_3 ++ ) {
error = F_114 ( & V_64 -> V_65 ,
V_64 -> V_76 -> V_41 -> V_157 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_115 ( V_64 ) ;
return error ;
}
void F_116 ( struct V_63 * V_64 )
{
struct V_29 * V_30 = & V_64 -> V_65 ;
int V_24 ;
if ( V_64 -> V_109 == V_131 )
return;
if ( V_64 -> V_156 ) {
F_40 ( & V_64 -> V_108 ) ;
V_24 = F_72 ( V_64 , V_130 ) ;
if ( V_24 != 0 ) {
V_24 = F_72 ( V_64 , V_131 ) ;
if ( V_24 == 0 )
F_117 ( V_64 ) ;
}
F_43 ( & V_64 -> V_108 ) ;
if ( V_24 != 0 )
return;
F_118 ( V_64 -> V_84 ) ;
F_119 ( & V_64 -> V_155 ) ;
F_120 ( V_30 ) ;
F_111 ( V_64 ) ;
F_112 ( V_30 ) ;
} else
F_30 ( & V_64 -> V_155 ) ;
F_40 ( & V_64 -> V_108 ) ;
F_72 ( V_64 , V_131 ) ;
F_43 ( & V_64 -> V_108 ) ;
F_121 ( V_64 -> V_84 ) ;
F_35 ( & V_64 -> V_158 ) ;
if ( V_64 -> V_76 -> V_41 -> V_159 )
V_64 -> V_76 -> V_41 -> V_159 ( V_64 ) ;
F_122 ( V_30 ) ;
F_123 ( V_149 ( V_64 ) ) ;
F_30 ( V_30 ) ;
}
void F_70 ( struct V_63 * V_64 )
{
struct V_14 * V_15 = V_64 -> V_76 ;
F_40 ( & V_15 -> V_160 ) ;
F_116 ( V_64 ) ;
F_43 ( & V_15 -> V_160 ) ;
}
static void F_124 ( struct V_149 * V_150 )
{
struct V_14 * V_15 = F_125 ( V_150 -> V_30 . V_68 ) ;
unsigned long V_55 ;
struct V_63 * V_64 ;
F_23 ( V_15 -> V_59 , V_55 ) ;
V_161:
F_126 (sdev, &shost->__devices, siblings) {
if ( V_64 -> V_21 != V_150 -> V_21 ||
V_64 -> V_22 != V_150 -> V_22 ||
! F_127 ( & V_64 -> V_65 ) )
continue;
F_25 ( V_15 -> V_59 , V_55 ) ;
F_70 ( V_64 ) ;
F_30 ( & V_64 -> V_65 ) ;
F_23 ( V_15 -> V_59 , V_55 ) ;
goto V_161;
}
F_25 ( V_15 -> V_59 , V_55 ) ;
}
void F_128 ( struct V_29 * V_30 )
{
struct V_14 * V_15 = F_125 ( V_30 -> V_68 ) ;
struct V_149 * V_150 ;
unsigned long V_55 ;
V_161:
F_23 ( V_15 -> V_59 , V_55 ) ;
F_126 (starget, &shost->__targets, siblings) {
if ( V_150 -> V_2 == V_162 ||
V_150 -> V_2 == V_163 ||
V_150 -> V_2 == V_164 )
continue;
if ( V_150 -> V_30 . V_68 == V_30 || & V_150 -> V_30 == V_30 ) {
F_129 ( & V_150 -> V_165 ) ;
if ( V_150 -> V_2 == V_151 )
V_150 -> V_2 = V_164 ;
else
V_150 -> V_2 = V_163 ;
F_25 ( V_15 -> V_59 , V_55 ) ;
F_124 ( V_150 ) ;
F_123 ( V_150 ) ;
goto V_161;
}
}
F_25 ( V_15 -> V_59 , V_55 ) ;
}
int F_130 ( struct V_89 * V_166 )
{
V_166 -> V_167 = & V_98 ;
return F_131 ( V_166 ) ;
}
int F_132 ( struct V_168 * V_169 )
{
V_169 -> V_170 = & V_99 ;
return F_133 ( V_169 ) ;
}
int F_134 ( struct V_14 * V_15 )
{
int error , V_3 ;
if ( V_15 -> V_41 -> V_171 ) {
for ( V_3 = 0 ; V_15 -> V_41 -> V_171 [ V_3 ] ; V_3 ++ ) {
error = F_114 ( & V_15 -> V_172 ,
V_15 -> V_41 -> V_171 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_135 ( & V_15 -> V_173 ) ;
F_105 ( & V_15 -> V_173 ) ;
return 0 ;
}
void F_136 ( struct V_63 * V_64 )
{
unsigned long V_55 ;
struct V_14 * V_15 = V_64 -> V_76 ;
struct V_149 * V_150 = V_64 -> V_154 ;
F_137 ( & V_64 -> V_65 ) ;
V_64 -> V_65 . V_167 = & V_98 ;
V_64 -> V_65 . type = & V_91 ;
F_138 ( & V_64 -> V_65 , L_34 ,
V_64 -> V_76 -> V_174 , V_64 -> V_21 , V_64 -> V_22 , V_64 -> V_23 ) ;
F_137 ( & V_64 -> V_155 ) ;
V_64 -> V_155 . V_68 = F_127 ( & V_64 -> V_65 ) ;
V_64 -> V_155 . V_170 = & V_99 ;
F_138 ( & V_64 -> V_155 , L_34 ,
V_64 -> V_76 -> V_174 , V_64 -> V_21 , V_64 -> V_22 , V_64 -> V_23 ) ;
V_64 -> V_175 = V_150 -> V_175 ;
if ( V_64 -> V_175 <= V_176 &&
V_64 -> V_175 != V_177 &&
! V_15 -> V_178 )
V_64 -> V_179 = 1 ;
F_139 ( & V_64 -> V_65 ) ;
F_23 ( V_15 -> V_59 , V_55 ) ;
F_140 ( & V_64 -> V_78 , & V_150 -> V_180 ) ;
F_140 ( & V_64 -> V_77 , & V_15 -> V_181 ) ;
F_25 ( V_15 -> V_59 , V_55 ) ;
F_129 ( & V_150 -> V_165 ) ;
}
int F_141 ( const struct V_29 * V_30 )
{
return V_30 -> type == & V_91 ;
}
