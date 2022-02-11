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
if ( V_15 -> V_51 == - 1 )
return snprintf ( V_33 , strlen ( L_14 ) + 2 , L_15 ) ;
return sprintf ( V_33 , L_16 , V_15 -> V_51 / V_52 ) ;
}
static T_1
F_21 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
int V_48 = - V_25 ;
unsigned long V_53 , V_54 ;
if ( V_15 -> V_26 &&
( V_15 -> V_26 -> V_55 ||
! V_15 -> V_41 -> V_56 ) )
return V_48 ;
if ( ! strncmp ( V_33 , L_14 , strlen ( L_14 ) ) )
V_53 = - 1 ;
else {
V_48 = F_22 ( V_33 , 10 , & V_53 ) ;
if ( V_48 )
return V_48 ;
if ( V_53 * V_52 > V_57 )
return - V_25 ;
}
F_23 ( V_15 -> V_58 , V_54 ) ;
if ( F_24 ( V_15 ) )
V_48 = - V_59 ;
else {
if ( V_53 == - 1 )
V_15 -> V_51 = - 1 ;
else
V_15 -> V_51 = V_53 * V_52 ;
V_48 = V_34 ;
}
F_25 ( V_15 -> V_58 , V_54 ) ;
return V_48 ;
}
static T_1
F_26 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_14 * V_15 = F_10 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_15 -> V_60 ) ) ;
}
static void F_28 ( struct V_29 * V_61 )
{
struct V_62 * V_63 ;
V_63 = F_29 ( V_61 ) ;
F_30 ( & V_63 -> V_64 ) ;
}
static void F_31 ( struct V_65 * V_66 )
{
struct V_62 * V_63 ;
struct V_29 * V_67 ;
struct V_68 * V_69 , * V_70 ;
unsigned long V_54 ;
V_63 = F_32 ( V_66 , struct V_62 , V_71 . V_66 ) ;
F_33 ( V_63 ) ;
V_67 = V_63 -> V_64 . V_67 ;
F_23 ( V_63 -> V_72 -> V_58 , V_54 ) ;
F_34 ( & V_63 -> V_73 ) ;
F_34 ( & V_63 -> V_74 ) ;
F_34 ( & V_63 -> V_75 ) ;
F_25 ( V_63 -> V_72 -> V_58 , V_54 ) ;
F_35 ( & V_63 -> V_76 ) ;
F_36 (this, tmp, &sdev->event_list) {
struct V_77 * V_78 ;
V_78 = F_37 ( V_69 , struct V_77 , V_79 ) ;
F_34 ( & V_78 -> V_79 ) ;
F_38 ( V_78 ) ;
}
F_39 ( V_63 -> V_80 ) ;
V_63 -> V_80 = NULL ;
F_38 ( V_63 -> V_81 ) ;
F_38 ( V_63 -> V_82 ) ;
F_38 ( V_63 -> V_83 ) ;
F_38 ( V_63 ) ;
if ( V_67 )
F_30 ( V_67 ) ;
}
static void F_40 ( struct V_29 * V_30 )
{
struct V_62 * V_84 = F_41 ( V_30 ) ;
F_42 ( F_31 ,
& V_84 -> V_71 ) ;
}
static int F_43 ( struct V_29 * V_30 , struct V_85 * V_86 )
{
struct V_62 * V_84 ;
if ( V_30 -> type != & V_87 )
return 0 ;
V_84 = F_41 ( V_30 ) ;
if ( V_84 -> V_88 )
return 0 ;
return ( V_84 -> V_89 == V_90 ) ? 1 : 0 ;
}
static int F_44 ( struct V_29 * V_30 , struct V_91 * V_92 )
{
struct V_62 * V_63 ;
if ( V_30 -> type != & V_87 )
return 0 ;
V_63 = F_41 ( V_30 ) ;
F_45 ( V_92 , L_18 V_93 , V_63 -> type ) ;
return 0 ;
}
int F_46 ( void )
{
int error ;
error = F_47 ( & V_94 ) ;
if ( ! error ) {
error = F_48 ( & V_95 ) ;
if ( error )
F_49 ( & V_94 ) ;
}
return error ;
}
void F_50 ( void )
{
F_51 ( & V_95 ) ;
F_49 ( & V_94 ) ;
}
static T_1
F_52 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_63 -> V_96 ) ) ;
}
static T_1
F_53 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , F_27 ( & V_63 -> V_97 ) ) ;
}
static T_1
F_54 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_62 * V_63 ;
V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_17 , V_63 -> V_80 -> V_98 / V_52 ) ;
}
static T_1
F_55 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_62 * V_63 ;
int V_99 ;
V_63 = F_41 ( V_30 ) ;
sscanf ( V_33 , L_17 , & V_99 ) ;
F_56 ( V_63 -> V_80 , V_99 * V_52 ) ;
return V_34 ;
}
static T_1
F_57 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_62 * V_63 ;
V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_16 , V_63 -> V_100 / V_52 ) ;
}
static T_1
F_58 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_62 * V_63 ;
unsigned int V_100 ;
int V_101 ;
if ( ! F_59 ( V_102 ) )
return - V_103 ;
V_63 = F_41 ( V_30 ) ;
V_101 = F_60 ( V_33 , 10 , & V_100 ) ;
if ( V_101 )
return V_101 ;
V_63 -> V_100 = V_100 * V_52 ;
return V_34 ;
}
static T_1
F_61 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
F_62 ( V_30 ) ;
return V_34 ;
}
static T_1
F_63 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
if ( F_64 ( V_30 , V_32 ) )
F_65 ( F_41 ( V_30 ) ) ;
return V_34 ;
}
static T_1
F_66 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
int V_3 ;
struct V_62 * V_63 = F_41 ( V_30 ) ;
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
if ( F_67 ( V_63 , V_2 ) )
return - V_25 ;
return V_34 ;
}
static T_1
F_68 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
const char * V_4 = F_1 ( V_63 -> V_104 ) ;
if ( ! V_4 )
return - V_25 ;
return snprintf ( V_33 , 20 , L_3 , V_4 ) ;
}
static T_1
F_69 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
const char * V_4 = L_19 ;
if ( V_63 -> V_105 )
V_4 = L_20 ;
return snprintf ( V_33 , 20 , L_3 , V_4 ) ;
}
static T_1
F_70 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( ! V_63 -> V_106 )
return - V_25 ;
F_71 ( V_107 , V_63 ,
L_21 ) ;
return V_34 ;
}
static T_1 F_72 ( struct V_108 * V_109 , struct V_110 * V_111 ,
struct V_112 * V_113 ,
char * V_33 , T_3 V_114 , T_2 V_34 )
{
struct V_29 * V_30 = F_32 ( V_111 , struct V_29 , V_111 ) ;
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( ! V_63 -> V_83 )
return - V_25 ;
return F_73 ( V_33 , V_34 , & V_114 , V_63 -> V_83 ,
V_63 -> V_115 ) ;
}
static T_1
F_74 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
return snprintf ( V_33 , 20 , L_17 , ( int ) sizeof( V_116 ) * 8 ) ;
}
static T_1
F_75 ( struct V_29 * V_30 , struct V_31 * V_32 , char * V_33 )
{
struct V_62 * V_63 ;
V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , V_93 L_10 , V_63 -> type ) ;
}
static T_1
F_76 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
int V_117 , V_118 ;
struct V_62 * V_63 = F_41 ( V_30 ) ;
struct V_46 * V_47 = V_63 -> V_72 -> V_41 ;
if ( ! V_47 -> V_119 )
return - V_25 ;
V_117 = F_77 ( V_33 , NULL , 0 ) ;
if ( V_117 < 1 || V_117 > V_63 -> V_72 -> V_120 )
return - V_25 ;
V_118 = V_47 -> V_119 ( V_63 , V_117 ) ;
if ( V_118 < 0 )
return V_118 ;
V_63 -> V_121 = V_63 -> V_122 ;
return V_34 ;
}
static T_1
F_78 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
T_1 V_34 ;
V_34 = F_79 ( V_63 , V_33 , V_123 ) ;
if ( V_34 > 0 ) {
V_33 [ V_34 ] = '\n' ;
V_34 ++ ;
}
return V_34 ;
}
static T_1
F_80 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( ! V_63 -> V_124 )
return snprintf ( V_33 , 20 , L_22 ) ;
return snprintf ( V_33 , 20 , L_3 , V_63 -> V_124 -> V_4 ) ;
}
static T_1
F_81 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
int V_101 = - V_25 ;
if ( V_63 -> V_104 == V_125 ||
V_63 -> V_104 == V_126 )
return - V_127 ;
if ( ! V_63 -> V_124 ) {
V_101 = F_82 ( V_63 -> V_80 , V_33 ) ;
} else if ( ! strncmp ( V_33 , L_23 , 8 ) ) {
if ( V_63 -> V_124 -> V_128 )
V_101 = V_63 -> V_124 -> V_128 ( V_63 , NULL , NULL ) ;
else
V_101 = 0 ;
} else if ( ! strncmp ( V_33 , L_24 , 6 ) ) {
F_71 ( V_129 , V_63 ,
L_25 ,
V_63 -> V_124 -> V_4 ) ;
V_101 = - V_25 ;
}
return V_101 < 0 ? V_101 : V_34 ;
}
static T_1
F_83 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
unsigned char V_130 ;
const char * V_131 ;
if ( ! V_63 -> V_124 )
return - V_25 ;
V_130 = ( V_63 -> V_130 & V_132 ) ;
V_131 = F_4 ( V_130 ) ;
return sprintf ( V_33 , L_3 ,
V_131 ? V_131 : L_26 ) ;
}
static T_1
F_84 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( ! V_63 -> V_124 )
return - V_25 ;
if ( V_63 -> V_130 & V_133 )
return sprintf ( V_33 , L_27 ) ;
else
return sprintf ( V_33 , L_28 ) ;
}
static T_1
F_85 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_62 * V_63 ;
V_63 = F_41 ( V_30 ) ;
return snprintf ( V_33 , 20 , L_16 ,
F_86 ( V_63 -> V_134 ) ) ;
}
static T_1
F_87 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_62 * V_63 = F_41 ( V_30 ) ;
unsigned int V_135 ;
if ( F_60 ( V_33 , 10 , & V_135 ) )
return - V_25 ;
V_63 -> V_134 = F_88 ( V_135 ) ;
return V_34 ;
}
static T_4 F_89 ( struct V_110 * V_111 ,
struct V_136 * V_32 , int V_3 )
{
struct V_29 * V_30 = F_32 ( V_111 , struct V_29 , V_111 ) ;
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( V_32 == & V_137 . V_32 &&
! V_63 -> V_72 -> V_41 -> V_119 )
return V_138 ;
if ( V_32 == & V_139 . V_32 &&
! V_63 -> V_72 -> V_41 -> V_119 )
return 0 ;
#ifdef F_90
if ( V_32 == & V_140 . V_32 &&
! V_63 -> V_124 )
return 0 ;
if ( V_32 == & V_141 . V_32 &&
! V_63 -> V_124 )
return 0 ;
#endif
return V_32 -> V_37 ;
}
static T_4 F_91 ( struct V_110 * V_111 ,
struct V_112 * V_32 , int V_3 )
{
struct V_29 * V_30 = F_32 ( V_111 , struct V_29 , V_111 ) ;
struct V_62 * V_63 = F_41 ( V_30 ) ;
if ( V_32 == & V_142 && ! V_63 -> V_82 )
return 0 ;
if ( V_32 == & V_143 && ! V_63 -> V_81 )
return 0 ;
return V_138 ;
}
static int F_92 ( struct V_144 * V_145 )
{
int error ;
if ( V_145 -> V_2 != V_146 )
return 0 ;
error = F_93 ( & V_145 -> V_30 ) ;
if ( error ) {
F_94 ( & V_145 -> V_30 , L_29 , error ) ;
return error ;
}
F_95 ( & V_145 -> V_30 ) ;
V_145 -> V_2 = V_147 ;
F_96 ( & V_145 -> V_30 ) ;
F_97 ( & V_145 -> V_30 ) ;
F_98 ( & V_145 -> V_30 ) ;
return 0 ;
}
int F_99 ( struct V_62 * V_63 )
{
int error , V_3 ;
struct V_80 * V_148 = V_63 -> V_80 ;
struct V_144 * V_145 = V_63 -> V_149 ;
error = F_67 ( V_63 , V_150 ) ;
if ( error )
return error ;
error = F_92 ( V_145 ) ;
if ( error )
return error ;
F_100 ( & V_145 -> V_30 ) ;
F_98 ( & V_63 -> V_64 ) ;
F_101 ( V_145 ) ;
F_96 ( & V_63 -> V_64 ) ;
F_102 ( & V_63 -> V_64 ) ;
F_97 ( & V_63 -> V_64 ) ;
F_103 ( V_145 ) ;
F_104 ( V_63 ) ;
error = F_105 ( V_63 ) ;
if ( error )
F_71 ( V_107 , V_63 ,
L_30 , error ) ;
error = F_93 ( & V_63 -> V_64 ) ;
if ( error ) {
F_71 ( V_107 , V_63 ,
L_31 , error ) ;
F_106 ( V_63 ) ;
return error ;
}
F_98 ( & V_63 -> V_151 ) ;
error = F_93 ( & V_63 -> V_151 ) ;
if ( error ) {
F_71 ( V_107 , V_63 ,
L_32 , error ) ;
F_106 ( V_63 ) ;
F_107 ( & V_63 -> V_64 ) ;
return error ;
}
F_95 ( & V_63 -> V_64 ) ;
V_63 -> V_152 = 1 ;
error = F_108 ( V_148 , & V_63 -> V_64 , NULL , NULL ) ;
if ( error )
F_71 ( V_107 , V_63 ,
L_33 , error ) ;
if ( V_63 -> V_72 -> V_41 -> V_153 ) {
for ( V_3 = 0 ; V_63 -> V_72 -> V_41 -> V_153 [ V_3 ] ; V_3 ++ ) {
error = F_109 ( & V_63 -> V_64 ,
V_63 -> V_72 -> V_41 -> V_153 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_110 ( V_63 ) ;
return error ;
}
void F_111 ( struct V_62 * V_63 )
{
struct V_29 * V_30 = & V_63 -> V_64 ;
if ( V_63 -> V_104 == V_126 )
return;
if ( V_63 -> V_152 ) {
if ( F_67 ( V_63 , V_125 ) != 0 )
return;
F_112 ( V_63 -> V_80 ) ;
F_113 ( & V_63 -> V_151 ) ;
F_114 ( V_30 ) ;
F_106 ( V_63 ) ;
F_107 ( V_30 ) ;
} else
F_30 ( & V_63 -> V_151 ) ;
F_67 ( V_63 , V_126 ) ;
F_115 ( V_63 -> V_80 ) ;
F_35 ( & V_63 -> V_154 ) ;
if ( V_63 -> V_72 -> V_41 -> V_155 )
V_63 -> V_72 -> V_41 -> V_155 ( V_63 ) ;
F_116 ( V_30 ) ;
F_117 ( V_144 ( V_63 ) ) ;
F_30 ( V_30 ) ;
}
void F_65 ( struct V_62 * V_63 )
{
struct V_14 * V_15 = V_63 -> V_72 ;
F_118 ( & V_15 -> V_156 ) ;
F_111 ( V_63 ) ;
F_119 ( & V_15 -> V_156 ) ;
}
static void F_120 ( struct V_144 * V_145 )
{
struct V_14 * V_15 = F_121 ( V_145 -> V_30 . V_67 ) ;
unsigned long V_54 ;
struct V_62 * V_63 ;
F_23 ( V_15 -> V_58 , V_54 ) ;
V_157:
F_122 (sdev, &shost->__devices, siblings) {
if ( V_63 -> V_21 != V_145 -> V_21 ||
V_63 -> V_22 != V_145 -> V_22 ||
F_123 ( V_63 ) )
continue;
F_25 ( V_15 -> V_58 , V_54 ) ;
F_65 ( V_63 ) ;
F_124 ( V_63 ) ;
F_23 ( V_15 -> V_58 , V_54 ) ;
goto V_157;
}
F_25 ( V_15 -> V_58 , V_54 ) ;
}
void F_125 ( struct V_29 * V_30 )
{
struct V_14 * V_15 = F_121 ( V_30 -> V_67 ) ;
struct V_144 * V_145 ;
unsigned long V_54 ;
V_157:
F_23 ( V_15 -> V_58 , V_54 ) ;
F_122 (starget, &shost->__targets, siblings) {
if ( V_145 -> V_2 == V_158 ||
V_145 -> V_2 == V_159 )
continue;
if ( V_145 -> V_30 . V_67 == V_30 || & V_145 -> V_30 == V_30 ) {
F_126 ( & V_145 -> V_160 ) ;
V_145 -> V_2 = V_159 ;
F_25 ( V_15 -> V_58 , V_54 ) ;
F_120 ( V_145 ) ;
F_117 ( V_145 ) ;
goto V_157;
}
}
F_25 ( V_15 -> V_58 , V_54 ) ;
}
int F_127 ( struct V_85 * V_161 )
{
V_161 -> V_162 = & V_94 ;
return F_128 ( V_161 ) ;
}
int F_129 ( struct V_163 * V_164 )
{
V_164 -> V_165 = & V_95 ;
return F_130 ( V_164 ) ;
}
int F_131 ( struct V_14 * V_15 )
{
int error , V_3 ;
if ( V_15 -> V_41 -> V_166 ) {
for ( V_3 = 0 ; V_15 -> V_41 -> V_166 [ V_3 ] ; V_3 ++ ) {
error = F_109 ( & V_15 -> V_167 ,
V_15 -> V_41 -> V_166 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_132 ( & V_15 -> V_168 ) ;
F_100 ( & V_15 -> V_168 ) ;
return 0 ;
}
void F_133 ( struct V_62 * V_63 )
{
unsigned long V_54 ;
struct V_14 * V_15 = V_63 -> V_72 ;
struct V_144 * V_145 = V_63 -> V_149 ;
F_134 ( & V_63 -> V_64 ) ;
V_63 -> V_64 . V_162 = & V_94 ;
V_63 -> V_64 . type = & V_87 ;
F_135 ( & V_63 -> V_64 , L_34 ,
V_63 -> V_72 -> V_169 , V_63 -> V_21 , V_63 -> V_22 , V_63 -> V_23 ) ;
F_134 ( & V_63 -> V_151 ) ;
V_63 -> V_151 . V_67 = F_136 ( & V_63 -> V_64 ) ;
V_63 -> V_151 . V_165 = & V_95 ;
F_135 ( & V_63 -> V_151 , L_34 ,
V_63 -> V_72 -> V_169 , V_63 -> V_21 , V_63 -> V_22 , V_63 -> V_23 ) ;
V_63 -> V_170 = V_145 -> V_170 ;
if ( V_63 -> V_170 <= V_171 &&
V_63 -> V_170 != V_172 &&
! V_15 -> V_173 )
V_63 -> V_174 = 1 ;
F_137 ( & V_63 -> V_64 ) ;
F_23 ( V_15 -> V_58 , V_54 ) ;
F_138 ( & V_63 -> V_74 , & V_145 -> V_175 ) ;
F_138 ( & V_63 -> V_73 , & V_15 -> V_176 ) ;
F_25 ( V_15 -> V_58 , V_54 ) ;
F_126 ( & V_145 -> V_160 ) ;
}
int F_139 ( const struct V_29 * V_30 )
{
return V_30 -> type == & V_87 ;
}
