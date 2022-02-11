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
if ( strncmp ( V_11 , L_1 , 20 ) == 0 ) {
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
V_24 = F_8 ( V_15 , V_21 , V_22 , V_23 , 1 ) ;
return V_24 ;
}
static T_1
F_9 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
int V_24 ;
V_24 = F_7 ( V_15 , V_32 ) ;
if ( V_24 == 0 )
V_24 = V_33 ;
return V_24 ;
}
static T_1
F_11 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
int V_3 ;
struct V_14 * V_15 = F_10 ( V_29 ) ;
enum V_7 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
const int V_34 = strlen ( V_8 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_8 [ V_3 ] . V_4 , V_32 , V_34 ) == 0 &&
V_32 [ V_34 ] == '\n' ) {
V_2 = V_8 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_25 ;
if ( F_12 ( V_15 , V_2 ) )
return - V_25 ;
return V_33 ;
}
static T_1
F_13 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
const char * V_4 = F_3 ( V_15 -> V_35 ) ;
if ( ! V_4 )
return - V_25 ;
return snprintf ( V_32 , 20 , L_3 , V_4 ) ;
}
static T_1
F_14 ( unsigned int V_36 , char * V_32 )
{
T_1 V_34 = 0 ;
if ( V_36 & V_37 )
V_34 = sprintf ( V_32 , L_4 , L_5 ) ;
if ( V_36 & V_38 )
V_34 += sprintf ( V_32 + V_34 , L_6 , V_34 ? L_7 : L_8 , L_9 ) ;
V_34 += sprintf ( V_32 + V_34 , L_10 ) ;
return V_34 ;
}
static T_1
F_15 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
unsigned int V_39 = V_15 -> V_40 -> V_39 ;
if ( V_39 == V_41 )
V_39 = V_37 ;
return F_14 ( V_39 , V_32 ) ;
}
static T_1
F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
if ( V_15 -> V_42 == V_41 )
return snprintf ( V_32 , 20 , L_11 ) ;
else
return F_14 ( V_15 -> V_42 , V_32 ) ;
}
static int F_17 ( const char * V_16 )
{
if ( F_18 ( V_16 , L_12 ) )
return V_43 ;
else if ( F_18 ( V_16 , L_13 ) )
return V_44 ;
else
return 0 ;
}
static T_1
F_19 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
struct V_45 * V_46 = V_15 -> V_40 ;
int V_47 = - V_25 ;
int type ;
type = F_17 ( V_32 ) ;
if ( ! type )
goto V_48;
if ( V_46 -> V_49 )
V_47 = V_46 -> V_49 ( V_15 , type ) ;
V_48:
if ( V_47 == 0 )
V_47 = V_33 ;
return V_47 ;
}
static T_1
F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
if ( V_15 -> V_50 == - 1 )
return snprintf ( V_32 , strlen ( L_14 ) + 2 , L_15 ) ;
return sprintf ( V_32 , L_16 , V_15 -> V_50 / V_51 ) ;
}
static T_1
F_21 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
int V_47 = - V_25 ;
unsigned long V_52 , V_53 ;
if ( V_15 -> V_26 &&
( V_15 -> V_26 -> V_54 ||
! V_15 -> V_40 -> V_55 ) )
return V_47 ;
if ( ! strncmp ( V_32 , L_14 , strlen ( L_14 ) ) )
V_52 = - 1 ;
else {
V_47 = F_22 ( V_32 , 10 , & V_52 ) ;
if ( V_47 )
return V_47 ;
if ( V_52 * V_51 > V_56 )
return - V_25 ;
}
F_23 ( V_15 -> V_57 , V_53 ) ;
if ( F_24 ( V_15 ) )
V_47 = - V_58 ;
else {
if ( V_52 == - 1 )
V_15 -> V_50 = - 1 ;
else
V_15 -> V_50 = V_52 * V_51 ;
V_47 = V_33 ;
}
F_25 ( V_15 -> V_57 , V_53 ) ;
return V_47 ;
}
static T_1
F_26 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_14 * V_15 = F_10 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_17 , F_27 ( & V_15 -> V_59 ) ) ;
}
static void F_28 ( struct V_28 * V_60 )
{
struct V_61 * V_62 ;
V_62 = F_29 ( V_60 ) ;
F_30 ( & V_62 -> V_63 ) ;
}
static void F_31 ( struct V_64 * V_65 )
{
struct V_61 * V_62 ;
struct V_28 * V_66 ;
struct V_67 * V_68 , * V_69 ;
unsigned long V_53 ;
V_62 = F_32 ( V_65 , struct V_61 , V_70 . V_65 ) ;
F_33 ( V_62 ) ;
V_66 = V_62 -> V_63 . V_66 ;
F_23 ( V_62 -> V_71 -> V_57 , V_53 ) ;
F_34 ( & V_62 -> V_72 ) ;
F_34 ( & V_62 -> V_73 ) ;
F_34 ( & V_62 -> V_74 ) ;
F_25 ( V_62 -> V_71 -> V_57 , V_53 ) ;
F_35 ( & V_62 -> V_75 ) ;
F_36 (this, tmp, &sdev->event_list) {
struct V_76 * V_77 ;
V_77 = F_37 ( V_68 , struct V_76 , V_78 ) ;
F_34 ( & V_77 -> V_78 ) ;
F_38 ( V_77 ) ;
}
F_39 ( V_62 -> V_79 ) ;
V_62 -> V_79 = NULL ;
F_38 ( V_62 -> V_80 ) ;
F_38 ( V_62 -> V_81 ) ;
F_38 ( V_62 -> V_82 ) ;
F_38 ( V_62 ) ;
if ( V_66 )
F_30 ( V_66 ) ;
}
static void F_40 ( struct V_28 * V_29 )
{
struct V_61 * V_83 = F_41 ( V_29 ) ;
F_42 ( F_31 ,
& V_83 -> V_70 ) ;
}
static int F_43 ( struct V_28 * V_29 , struct V_84 * V_85 )
{
struct V_61 * V_83 ;
if ( V_29 -> type != & V_86 )
return 0 ;
V_83 = F_41 ( V_29 ) ;
if ( V_83 -> V_87 )
return 0 ;
return ( V_83 -> V_88 == V_89 ) ? 1 : 0 ;
}
static int F_44 ( struct V_28 * V_29 , struct V_90 * V_91 )
{
struct V_61 * V_62 ;
if ( V_29 -> type != & V_86 )
return 0 ;
V_62 = F_41 ( V_29 ) ;
F_45 ( V_91 , L_18 V_92 , V_62 -> type ) ;
return 0 ;
}
int F_46 ( void )
{
int error ;
error = F_47 ( & V_93 ) ;
if ( ! error ) {
error = F_48 ( & V_94 ) ;
if ( error )
F_49 ( & V_93 ) ;
}
return error ;
}
void F_50 ( void )
{
F_51 ( & V_94 ) ;
F_49 ( & V_93 ) ;
}
static T_1
F_52 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_17 , F_27 ( & V_62 -> V_95 ) ) ;
}
static T_1
F_53 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_17 , F_27 ( & V_62 -> V_96 ) ) ;
}
static T_1
F_54 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_61 * V_62 ;
V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_17 , V_62 -> V_79 -> V_97 / V_51 ) ;
}
static T_1
F_55 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_61 * V_62 ;
int V_98 ;
V_62 = F_41 ( V_29 ) ;
sscanf ( V_32 , L_17 , & V_98 ) ;
F_56 ( V_62 -> V_79 , V_98 * V_51 ) ;
return V_33 ;
}
static T_1
F_57 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_61 * V_62 ;
V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_16 , V_62 -> V_99 / V_51 ) ;
}
static T_1
F_58 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_61 * V_62 ;
unsigned int V_99 ;
int V_100 ;
if ( ! F_59 ( V_101 ) )
return - V_102 ;
V_62 = F_41 ( V_29 ) ;
V_100 = F_60 ( V_32 , 10 , & V_99 ) ;
if ( V_100 )
return V_100 ;
V_62 -> V_99 = V_99 * V_51 ;
return V_33 ;
}
static T_1
F_61 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
F_62 ( V_29 ) ;
return V_33 ;
}
static T_1
F_63 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
if ( F_64 ( V_29 , V_31 ) )
F_65 ( F_41 ( V_29 ) ) ;
return V_33 ;
}
static T_1
F_66 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
int V_3 ;
struct V_61 * V_62 = F_41 ( V_29 ) ;
enum V_1 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
const int V_34 = strlen ( V_5 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_5 [ V_3 ] . V_4 , V_32 , V_34 ) == 0 &&
V_32 [ V_34 ] == '\n' ) {
V_2 = V_5 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_25 ;
if ( F_67 ( V_62 , V_2 ) )
return - V_25 ;
return V_33 ;
}
static T_1
F_68 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
const char * V_4 = F_1 ( V_62 -> V_103 ) ;
if ( ! V_4 )
return - V_25 ;
return snprintf ( V_32 , 20 , L_3 , V_4 ) ;
}
static T_1
F_69 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
const char * V_4 = L_19 ;
if ( V_62 -> V_104 )
V_4 = L_20 ;
return snprintf ( V_32 , 20 , L_3 , V_4 ) ;
}
static T_1
F_70 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( ! V_62 -> V_105 )
return - V_25 ;
F_71 ( V_106 , V_62 ,
L_21 ) ;
return V_33 ;
}
static T_1 F_72 ( struct V_107 * V_108 , struct V_109 * V_110 ,
struct V_111 * V_112 ,
char * V_32 , T_3 V_113 , T_2 V_33 )
{
struct V_28 * V_29 = F_32 ( V_110 , struct V_28 , V_110 ) ;
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( ! V_62 -> V_82 )
return - V_25 ;
return F_73 ( V_32 , V_33 , & V_113 , V_62 -> V_82 ,
V_62 -> V_114 ) ;
}
static T_1
F_74 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
return snprintf ( V_32 , 20 , L_17 , ( int ) sizeof( V_115 ) * 8 ) ;
}
static T_1
F_75 ( struct V_28 * V_29 , struct V_30 * V_31 , char * V_32 )
{
struct V_61 * V_62 ;
V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , V_92 L_10 , V_62 -> type ) ;
}
static T_1
F_76 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
int V_116 , V_117 ;
struct V_61 * V_62 = F_41 ( V_29 ) ;
struct V_45 * V_46 = V_62 -> V_71 -> V_40 ;
if ( ! V_46 -> V_118 )
return - V_25 ;
V_116 = F_77 ( V_32 , NULL , 0 ) ;
if ( V_116 < 1 || V_116 > V_62 -> V_71 -> V_119 )
return - V_25 ;
V_117 = V_46 -> V_118 ( V_62 , V_116 ) ;
if ( V_117 < 0 )
return V_117 ;
V_62 -> V_120 = V_62 -> V_121 ;
return V_33 ;
}
static T_1
F_78 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
T_1 V_33 ;
V_33 = F_79 ( V_62 , V_32 , V_122 ) ;
if ( V_33 > 0 ) {
V_32 [ V_33 ] = '\n' ;
V_33 ++ ;
}
return V_33 ;
}
static T_1
F_80 ( struct V_28 * V_29 , struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( ! V_62 -> V_123 )
return snprintf ( V_32 , 20 , L_22 ) ;
return snprintf ( V_32 , 20 , L_3 , V_62 -> V_123 -> V_4 ) ;
}
static T_1
F_81 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
int V_100 = - V_25 ;
if ( V_62 -> V_103 == V_124 ||
V_62 -> V_103 == V_125 )
return - V_126 ;
if ( ! V_62 -> V_123 ) {
V_100 = F_82 ( V_62 -> V_79 , V_32 ) ;
} else if ( ! strncmp ( V_32 , L_23 , 8 ) ) {
if ( V_62 -> V_123 -> V_127 )
V_100 = V_62 -> V_123 -> V_127 ( V_62 , NULL , NULL ) ;
else
V_100 = 0 ;
} else if ( ! strncmp ( V_32 , L_24 , 6 ) ) {
F_71 ( V_128 , V_62 ,
L_25 ,
V_62 -> V_123 -> V_4 ) ;
V_100 = - V_25 ;
}
return V_100 < 0 ? V_100 : V_33 ;
}
static T_1
F_83 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
unsigned char V_129 ;
const char * V_130 ;
if ( ! V_62 -> V_123 )
return - V_25 ;
V_129 = ( V_62 -> V_129 & V_131 ) ;
V_130 = F_4 ( V_129 ) ;
return sprintf ( V_32 , L_3 ,
V_130 ? V_130 : L_26 ) ;
}
static T_1
F_84 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( ! V_62 -> V_123 )
return - V_25 ;
if ( V_62 -> V_129 & V_132 )
return sprintf ( V_32 , L_27 ) ;
else
return sprintf ( V_32 , L_28 ) ;
}
static T_1
F_85 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_61 * V_62 ;
V_62 = F_41 ( V_29 ) ;
return snprintf ( V_32 , 20 , L_16 ,
F_86 ( V_62 -> V_133 ) ) ;
}
static T_1
F_87 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_61 * V_62 = F_41 ( V_29 ) ;
unsigned int V_134 ;
if ( F_60 ( V_32 , 10 , & V_134 ) )
return - V_25 ;
V_62 -> V_133 = F_88 ( V_134 ) ;
return V_33 ;
}
static T_4 F_89 ( struct V_109 * V_110 ,
struct V_135 * V_31 , int V_3 )
{
struct V_28 * V_29 = F_32 ( V_110 , struct V_28 , V_110 ) ;
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( V_31 == & V_136 . V_31 &&
! V_62 -> V_71 -> V_40 -> V_118 )
return V_137 ;
if ( V_31 == & V_138 . V_31 &&
! V_62 -> V_71 -> V_40 -> V_118 )
return 0 ;
#ifdef F_90
if ( V_31 == & V_139 . V_31 &&
! V_62 -> V_123 )
return 0 ;
if ( V_31 == & V_140 . V_31 &&
! V_62 -> V_123 )
return 0 ;
#endif
return V_31 -> V_36 ;
}
static T_4 F_91 ( struct V_109 * V_110 ,
struct V_111 * V_31 , int V_3 )
{
struct V_28 * V_29 = F_32 ( V_110 , struct V_28 , V_110 ) ;
struct V_61 * V_62 = F_41 ( V_29 ) ;
if ( V_31 == & V_141 && ! V_62 -> V_81 )
return 0 ;
if ( V_31 == & V_142 && ! V_62 -> V_80 )
return 0 ;
return V_137 ;
}
static int F_92 ( struct V_143 * V_144 )
{
int error ;
if ( V_144 -> V_2 != V_145 )
return 0 ;
error = F_93 ( & V_144 -> V_29 ) ;
if ( error ) {
F_94 ( & V_144 -> V_29 , L_29 , error ) ;
return error ;
}
F_95 ( & V_144 -> V_29 ) ;
V_144 -> V_2 = V_146 ;
F_96 ( & V_144 -> V_29 ) ;
F_97 ( & V_144 -> V_29 ) ;
F_98 ( & V_144 -> V_29 ) ;
return 0 ;
}
int F_99 ( struct V_61 * V_62 )
{
int error , V_3 ;
struct V_79 * V_147 = V_62 -> V_79 ;
struct V_143 * V_144 = V_62 -> V_148 ;
error = F_67 ( V_62 , V_149 ) ;
if ( error )
return error ;
error = F_92 ( V_144 ) ;
if ( error )
return error ;
F_100 ( & V_144 -> V_29 ) ;
F_98 ( & V_62 -> V_63 ) ;
F_101 ( V_144 ) ;
F_96 ( & V_62 -> V_63 ) ;
F_102 ( & V_62 -> V_63 ) ;
F_97 ( & V_62 -> V_63 ) ;
F_103 ( V_144 ) ;
F_104 ( V_62 ) ;
error = F_105 ( V_62 ) ;
if ( error )
F_71 ( V_106 , V_62 ,
L_30 , error ) ;
error = F_93 ( & V_62 -> V_63 ) ;
if ( error ) {
F_71 ( V_106 , V_62 ,
L_31 , error ) ;
F_106 ( V_62 ) ;
return error ;
}
F_98 ( & V_62 -> V_150 ) ;
error = F_93 ( & V_62 -> V_150 ) ;
if ( error ) {
F_71 ( V_106 , V_62 ,
L_32 , error ) ;
F_106 ( V_62 ) ;
F_107 ( & V_62 -> V_63 ) ;
return error ;
}
F_95 ( & V_62 -> V_63 ) ;
V_62 -> V_151 = 1 ;
error = F_108 ( V_147 , & V_62 -> V_63 , NULL , NULL ) ;
if ( error )
F_71 ( V_106 , V_62 ,
L_33 , error ) ;
if ( V_62 -> V_71 -> V_40 -> V_152 ) {
for ( V_3 = 0 ; V_62 -> V_71 -> V_40 -> V_152 [ V_3 ] ; V_3 ++ ) {
error = F_109 ( & V_62 -> V_63 ,
V_62 -> V_71 -> V_40 -> V_152 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_110 ( V_62 ) ;
return error ;
}
void F_111 ( struct V_61 * V_62 )
{
struct V_28 * V_29 = & V_62 -> V_63 ;
if ( V_62 -> V_103 == V_125 )
return;
if ( V_62 -> V_151 ) {
if ( F_67 ( V_62 , V_124 ) != 0 )
return;
F_112 ( V_62 -> V_79 ) ;
F_113 ( & V_62 -> V_150 ) ;
F_114 ( V_29 ) ;
F_106 ( V_62 ) ;
F_107 ( V_29 ) ;
} else
F_30 ( & V_62 -> V_150 ) ;
F_67 ( V_62 , V_125 ) ;
F_115 ( V_62 -> V_79 ) ;
F_35 ( & V_62 -> V_153 ) ;
if ( V_62 -> V_71 -> V_40 -> V_154 )
V_62 -> V_71 -> V_40 -> V_154 ( V_62 ) ;
F_116 ( V_29 ) ;
F_117 ( V_143 ( V_62 ) ) ;
F_30 ( V_29 ) ;
}
void F_65 ( struct V_61 * V_62 )
{
struct V_14 * V_15 = V_62 -> V_71 ;
F_118 ( & V_15 -> V_155 ) ;
F_111 ( V_62 ) ;
F_119 ( & V_15 -> V_155 ) ;
}
static void F_120 ( struct V_143 * V_144 )
{
struct V_14 * V_15 = F_121 ( V_144 -> V_29 . V_66 ) ;
unsigned long V_53 ;
struct V_61 * V_62 ;
F_23 ( V_15 -> V_57 , V_53 ) ;
V_156:
F_122 (sdev, &shost->__devices, siblings) {
if ( V_62 -> V_21 != V_144 -> V_21 ||
V_62 -> V_22 != V_144 -> V_22 ||
F_123 ( V_62 ) )
continue;
F_25 ( V_15 -> V_57 , V_53 ) ;
F_65 ( V_62 ) ;
F_124 ( V_62 ) ;
F_23 ( V_15 -> V_57 , V_53 ) ;
goto V_156;
}
F_25 ( V_15 -> V_57 , V_53 ) ;
}
void F_125 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = F_121 ( V_29 -> V_66 ) ;
struct V_143 * V_144 , * V_157 = NULL ;
unsigned long V_53 ;
V_156:
F_23 ( V_15 -> V_57 , V_53 ) ;
F_122 (starget, &shost->__targets, siblings) {
if ( V_144 -> V_2 == V_158 ||
V_144 == V_157 )
continue;
if ( V_144 -> V_29 . V_66 == V_29 || & V_144 -> V_29 == V_29 ) {
F_126 ( & V_144 -> V_159 ) ;
V_157 = V_144 ;
F_25 ( V_15 -> V_57 , V_53 ) ;
F_120 ( V_144 ) ;
F_117 ( V_144 ) ;
goto V_156;
}
}
F_25 ( V_15 -> V_57 , V_53 ) ;
}
int F_127 ( struct V_84 * V_160 )
{
V_160 -> V_161 = & V_93 ;
return F_128 ( V_160 ) ;
}
int F_129 ( struct V_162 * V_163 )
{
V_163 -> V_164 = & V_94 ;
return F_130 ( V_163 ) ;
}
int F_131 ( struct V_14 * V_15 )
{
int error , V_3 ;
if ( V_15 -> V_40 -> V_165 ) {
for ( V_3 = 0 ; V_15 -> V_40 -> V_165 [ V_3 ] ; V_3 ++ ) {
error = F_109 ( & V_15 -> V_166 ,
V_15 -> V_40 -> V_165 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_132 ( & V_15 -> V_167 ) ;
F_100 ( & V_15 -> V_167 ) ;
return 0 ;
}
void F_133 ( struct V_61 * V_62 )
{
unsigned long V_53 ;
struct V_14 * V_15 = V_62 -> V_71 ;
struct V_143 * V_144 = V_62 -> V_148 ;
F_134 ( & V_62 -> V_63 ) ;
V_62 -> V_63 . V_161 = & V_93 ;
V_62 -> V_63 . type = & V_86 ;
F_135 ( & V_62 -> V_63 , L_34 ,
V_62 -> V_71 -> V_168 , V_62 -> V_21 , V_62 -> V_22 , V_62 -> V_23 ) ;
F_134 ( & V_62 -> V_150 ) ;
V_62 -> V_150 . V_66 = F_136 ( & V_62 -> V_63 ) ;
V_62 -> V_150 . V_164 = & V_94 ;
F_135 ( & V_62 -> V_150 , L_34 ,
V_62 -> V_71 -> V_168 , V_62 -> V_21 , V_62 -> V_22 , V_62 -> V_23 ) ;
V_62 -> V_169 = V_144 -> V_169 ;
if ( V_62 -> V_169 <= V_170 &&
V_62 -> V_169 != V_171 &&
! V_15 -> V_172 )
V_62 -> V_173 = 1 ;
F_137 ( & V_62 -> V_63 ) ;
F_23 ( V_15 -> V_57 , V_53 ) ;
F_138 ( & V_62 -> V_73 , & V_144 -> V_174 ) ;
F_138 ( & V_62 -> V_72 , & V_15 -> V_175 ) ;
F_25 ( V_15 -> V_57 , V_53 ) ;
F_126 ( & V_144 -> V_159 ) ;
}
int F_139 ( const struct V_28 * V_29 )
{
return V_29 -> type == & V_86 ;
}
