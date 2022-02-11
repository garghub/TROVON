static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + V_7 - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static void F_2 ( void )
{
F_3 ( V_8 ) ;
F_4 () ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 ;
if ( V_13 . V_14 )
V_12 -> V_15 = V_16 |
V_17 ;
V_12 -> V_18 = ! V_19 ;
V_12 -> V_20 = 0 ;
if ( ! ( V_21 && V_22 . V_23 . V_24 ) )
V_12 -> V_25 = V_26 ;
if ( F_6 ( V_10 ) ) {
V_12 -> V_27 = 1 ;
if ( F_7 ( & V_28 ) && ! V_29 )
V_12 -> V_30 = 1 ;
}
if ( F_8 ( & V_28 ) )
return F_9 ( V_10 , F_10 ( V_10 ) ) ;
return F_11 ( V_10 , V_8 -> V_31 ) ;
}
static inline int F_12 ( struct V_9 * V_10 )
{
if ( F_13 ( V_10 , V_32 , V_33 ) ||
F_13 ( V_10 , V_32 , V_34 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_35 * T_1 V_36 ,
union V_37 * V_38 ,
struct V_39 * T_2 V_36 ,
struct V_40 * V_40 V_36 )
{
if ( F_15 ( & V_22 . V_23 , V_38 , V_38 -> V_41 . V_42 ) < 0 ) {
F_16 ( L_1 ) ;
return - 1 ;
}
V_22 . V_43 += V_38 -> V_41 . V_42 ;
return 0 ;
}
static int F_17 ( T_3 V_44 , T_3 type )
{
return F_18 ( NULL , V_44 , type ,
F_14 ,
NULL ) ;
}
static int
F_19 ( struct V_9 * V_45 , T_4 V_46 , T_4 V_47 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = F_20 ( V_45 , V_46 , V_47 ) ;
return F_21 ( NULL , V_46 , V_47 , V_51 -> V_52 , V_49 ,
F_14 , NULL ) ;
}
static int F_22 ( struct V_9 * V_45 )
{
int V_53 = F_23 ( V_8 -> V_31 ) ;
int V_54 , V_46 , V_47 ;
if ( F_8 ( & V_28 ) )
V_54 = F_24 ( V_45 ) ;
else
V_54 = 1 ;
if ( ! V_45 -> V_55 )
return - V_56 ;
if ( V_45 -> V_57 )
V_53 = 1 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
struct V_48 * V_49 ;
V_49 = F_25 ( V_45 -> V_58 , V_46 , V_47 ) ;
if ( F_26 ( V_45 , V_46 , V_47 , V_49 ) ) {
V_45 -> V_58 -> V_59 = - 1 ;
F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_60 = 0 ;
F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_61 = 0 ;
return - 1 ;
}
if ( V_21 ) {
if ( F_19 ( V_45 , V_46 , V_47 , V_49 ) ) {
F_16 ( L_2 ) ;
return - 1 ;
}
}
if ( V_62 > 1 ) {
fprintf ( V_13 . V_63 ,
L_3 V_64 L_4 V_64 L_4 V_64 L_5 ,
F_27 ( V_45 ) ,
V_46 ,
V_49 -> V_65 , V_49 -> V_60 , V_49 -> V_61 ) ;
}
}
}
return 0 ;
}
static void F_28 ( void )
{
struct V_9 * V_45 ;
int V_66 ;
F_29 (evsel_list, counter) {
V_66 = F_22 ( V_45 ) ;
if ( V_66 )
F_30 ( L_6 , V_45 -> V_67 ) ;
if ( V_66 == 0 && F_31 ( & V_13 , V_45 ) )
F_32 ( L_7 , V_45 -> V_67 ) ;
}
}
static void F_33 ( void )
{
struct V_1 V_68 , V_69 ;
F_28 () ;
F_34 ( V_70 , & V_68 ) ;
F_1 ( & V_69 , & V_68 , & V_71 ) ;
if ( V_21 ) {
if ( F_35 ( V_69 . V_5 * V_7 + V_69 . V_6 , V_72 ) )
F_16 ( L_8 ) ;
}
F_36 ( & V_69 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_29 )
F_38 ( V_29 * V_73 ) ;
if ( ! F_7 ( & V_28 ) || V_29 )
F_39 ( V_8 ) ;
}
static void F_40 ( void )
{
if ( ! F_7 ( & V_28 ) )
F_41 ( V_8 ) ;
}
static void F_42 ( int T_5 V_36 , T_6 * V_74 ,
void * T_7 V_36 )
{
V_75 = V_74 -> V_76 . V_77 ;
}
static bool F_43 ( struct V_9 * V_45 )
{
return V_45 -> V_78 && * V_45 -> V_78 ;
}
static bool F_44 ( struct V_9 * V_45 )
{
return V_45 -> V_14 != 1 ;
}
static int F_45 ( bool V_24 )
{
struct V_9 * V_45 ;
int V_79 ;
if ( V_24 ) {
V_79 = F_46 ( NULL , V_22 . V_80 ,
F_14 ) ;
if ( V_79 < 0 ) {
F_16 ( L_9 ) ;
return V_79 ;
}
}
F_29 (evsel_list, counter) {
if ( ! V_45 -> V_55 )
continue;
if ( F_43 ( V_45 ) ) {
V_79 = F_47 ( NULL , V_45 , F_14 ) ;
if ( V_79 < 0 ) {
F_16 ( L_10 ) ;
return V_79 ;
}
}
if ( F_44 ( V_45 ) ) {
V_79 = F_48 ( NULL , V_45 , F_14 ) ;
if ( V_79 < 0 ) {
F_16 ( L_11 ) ;
return V_79 ;
}
}
if ( V_45 -> V_81 ) {
V_79 = F_49 ( NULL , V_45 , F_14 ) ;
if ( V_79 < 0 ) {
F_16 ( L_11 ) ;
return V_79 ;
}
}
if ( V_24 ) {
V_79 = F_50 ( NULL , V_45 , F_14 ) ;
if ( V_79 < 0 ) {
F_16 ( L_12 ) ;
return V_79 ;
}
}
}
V_79 = F_51 ( NULL , V_8 -> V_31 ,
F_14 ,
NULL ) ;
if ( V_79 < 0 ) {
F_16 ( L_13 ) ;
return V_79 ;
}
V_79 = F_52 ( NULL , V_8 -> V_82 ,
F_14 , NULL ) ;
if ( V_79 < 0 ) {
F_16 ( L_13 ) ;
return V_79 ;
}
V_79 = F_53 ( NULL , & V_13 ,
F_14 , NULL ) ;
if ( V_79 < 0 ) {
F_16 ( L_14 ) ;
return V_79 ;
}
return 0 ;
}
static int F_54 ( struct V_9 * V_45 ,
struct V_83 * V_82 ,
struct V_84 * V_31 )
{
int V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < V_82 -> V_85 ; V_46 ++ ) {
for ( V_47 = 0 ; V_47 < V_31 -> V_85 ; V_47 ++ ) {
int V_86 = F_55 ( V_45 , V_46 , V_47 ) ;
if ( F_56 ( V_8 , V_45 ,
V_46 , V_47 , V_86 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_9 * V_45 )
{
struct V_83 * V_82 = V_45 -> V_82 ;
struct V_84 * V_31 = V_45 -> V_31 ;
if ( F_58 ( V_45 , V_82 -> V_85 , V_31 -> V_85 ) )
return - V_87 ;
return F_54 ( V_45 , V_82 , V_31 ) ;
}
static int F_59 ( int V_88 , const char * * V_89 )
{
int V_90 = V_13 . V_90 ;
char V_91 [ V_92 ] ;
unsigned long long V_93 , V_94 ;
struct V_9 * V_45 ;
struct V_1 V_68 ;
T_8 V_95 ;
int V_96 = 0 ;
const bool V_97 = ( V_88 > 0 ) ;
bool V_24 = V_21 ? V_22 . V_23 . V_24 : false ;
struct V_98 * V_99 ;
if ( V_90 ) {
V_68 . V_5 = V_90 / V_73 ;
V_68 . V_6 = ( V_90 % V_73 ) * V_100 ;
} else {
V_68 . V_5 = 1 ;
V_68 . V_6 = 0 ;
}
if ( V_97 ) {
if ( F_60 ( V_8 , & V_28 , V_89 , V_24 ,
F_42 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_101 = V_8 -> V_102 . V_103 ;
}
if ( V_104 )
F_61 ( V_8 ) ;
F_29 (evsel_list, counter) {
V_105:
if ( F_5 ( V_45 ) < 0 ) {
if ( V_106 == V_107 || V_106 == V_108 ||
V_106 == V_56 || V_106 == V_109 ||
V_106 == V_110 ) {
if ( V_62 > 0 )
F_62 ( L_16 ,
F_27 ( V_45 ) ) ;
V_45 -> V_55 = false ;
if ( ( V_45 -> V_111 != V_45 ) ||
! ( V_45 -> V_111 -> V_112 > 1 ) )
continue;
} else if ( F_63 ( V_45 , V_106 , V_91 , sizeof( V_91 ) ) ) {
if ( V_62 > 0 )
F_62 ( L_17 , V_91 ) ;
goto V_105;
}
F_64 ( V_45 , & V_28 ,
V_106 , V_91 , sizeof( V_91 ) ) ;
F_65 ( L_17 , V_91 ) ;
if ( V_101 != - 1 )
F_66 ( V_101 , V_113 ) ;
return - 1 ;
}
V_45 -> V_55 = true ;
V_95 = strlen ( V_45 -> V_78 ) ;
if ( V_95 > V_114 )
V_114 = V_95 ;
if ( V_21 && F_57 ( V_45 ) )
return - 1 ;
}
if ( F_67 ( V_8 , & V_45 ) ) {
error ( L_18 ,
V_45 -> V_115 , F_27 ( V_45 ) , V_106 ,
F_68 ( V_106 , V_91 , sizeof( V_91 ) ) ) ;
return - 1 ;
}
if ( F_69 ( V_8 , & V_45 , & V_99 ) ) {
error ( L_19 ,
V_99 -> V_65 . V_116 , F_27 ( V_45 ) , V_106 ,
F_68 ( V_106 , V_91 , sizeof( V_91 ) ) ) ;
return - 1 ;
}
if ( V_21 ) {
int V_79 , V_86 = F_70 ( & V_22 . V_23 ) ;
if ( V_24 ) {
V_79 = F_71 ( F_70 ( & V_22 . V_23 ) ) ;
} else {
V_79 = F_72 ( V_22 . V_80 , V_8 ,
V_86 , false ) ;
}
if ( V_79 < 0 )
return V_79 ;
V_79 = F_45 ( V_24 ) ;
if ( V_79 < 0 )
return V_79 ;
}
V_93 = F_73 () ;
F_34 ( V_70 , & V_71 ) ;
if ( V_97 ) {
F_74 ( V_8 ) ;
F_37 () ;
if ( V_90 ) {
while ( ! F_75 ( V_101 , & V_96 , V_117 ) ) {
F_76 ( & V_68 , NULL ) ;
F_33 () ;
}
}
F_77 ( & V_96 ) ;
if ( V_75 ) {
const char * V_118 = F_68 ( V_75 , V_91 , sizeof( V_91 ) ) ;
F_16 ( L_20 , V_118 ) ;
return - 1 ;
}
if ( F_78 ( V_96 ) )
F_79 ( F_80 ( V_96 ) , V_89 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_119 ) {
F_76 ( & V_68 , NULL ) ;
if ( V_90 )
F_33 () ;
}
}
F_40 () ;
V_94 = F_73 () ;
F_81 ( & V_120 , V_94 - V_93 ) ;
F_28 () ;
F_82 ( V_8 ) ;
return F_83 ( V_96 ) ;
}
static int F_84 ( int V_88 , const char * * V_89 )
{
int V_66 ;
if ( V_121 ) {
V_66 = system ( V_121 ) ;
if ( V_66 )
return V_66 ;
}
if ( V_122 )
F_85 () ;
V_66 = F_59 ( V_88 , V_89 ) ;
if ( V_66 )
return V_66 ;
if ( V_123 ) {
V_66 = system ( V_123 ) ;
if ( V_66 )
return V_66 ;
}
return V_66 ;
}
static void F_86 ( T_3 V_61 , T_3 V_60 )
{
if ( V_124 ) {
fprintf ( V_13 . V_63 , L_21 V_64 L_22 ,
V_125 ,
V_61 ,
V_125 ,
V_60 ? 100.0 * V_61 / V_60 : 100.0 ) ;
} else if ( V_61 != V_60 ) {
fprintf ( V_13 . V_63 , L_23 , 100.0 * V_61 / V_60 ) ;
}
}
static void F_87 ( double V_126 , double V_127 )
{
double V_128 = F_88 ( V_126 , V_127 ) ;
if ( V_124 )
fprintf ( V_13 . V_63 , L_24 , V_125 , V_128 ) ;
else if ( V_128 )
fprintf ( V_13 . V_63 , L_25 , V_128 ) ;
}
static void F_89 ( struct V_9 * V_10 , double V_127 )
{
struct V_129 * V_130 ;
if ( V_131 == 1 )
return;
V_130 = V_10 -> V_132 ;
F_87 ( F_90 ( & V_130 -> V_133 [ 0 ] ) , V_127 ) ;
}
static void F_91 ( struct V_9 * V_10 , int V_52 , int V_85 )
{
switch ( V_13 . V_134 ) {
case V_135 :
fprintf ( V_13 . V_63 , L_26 ,
F_92 ( V_52 ) ,
V_124 ? 0 : - 8 ,
F_93 ( V_52 ) ,
V_125 ,
V_124 ? 0 : 4 ,
V_85 ,
V_125 ) ;
break;
case V_136 :
fprintf ( V_13 . V_63 , L_27 ,
V_124 ? 0 : - 5 ,
V_52 ,
V_125 ,
V_124 ? 0 : 4 ,
V_85 ,
V_125 ) ;
break;
case V_137 :
fprintf ( V_13 . V_63 , L_28 ,
V_124 ? 0 : - 4 ,
F_10 ( V_10 ) -> V_138 [ V_52 ] , V_125 ) ;
break;
case V_139 :
fprintf ( V_13 . V_63 , L_29 ,
V_124 ? 0 : 16 ,
F_94 ( V_10 -> V_31 , V_52 ) ,
V_124 ? 0 : - 8 ,
F_95 ( V_10 -> V_31 , V_52 ) ,
V_125 ) ;
break;
case V_140 :
case V_141 :
default:
break;
}
}
static void F_96 ( void * V_142 )
{
struct V_143 * V_144 = V_142 ;
V_144 -> V_145 = true ;
}
static void F_97 ( struct V_143 * V_144 )
{
fputc ( '\n' , V_144 -> V_146 ) ;
fputs ( V_144 -> V_147 , V_144 -> V_146 ) ;
F_91 ( V_144 -> V_10 , V_144 -> V_52 , V_144 -> V_85 ) ;
if ( V_13 . V_134 == V_137 )
fprintf ( V_144 -> V_146 , L_30 ) ;
fprintf ( V_144 -> V_146 , L_31 ) ;
}
static void F_98 ( void * V_142 , const char * V_148 , const char * V_149 ,
const char * V_78 , double V_65 )
{
struct V_143 * V_144 = V_142 ;
T_9 * V_150 = V_144 -> V_146 ;
int V_151 ;
bool V_145 = V_144 -> V_145 ;
V_144 -> V_145 = false ;
if ( V_78 == NULL || V_149 == NULL ) {
fprintf ( V_150 , L_32 , V_152 , L_33 ) ;
return;
}
if ( V_145 )
F_97 ( V_144 ) ;
V_151 = fprintf ( V_150 , L_34 ) ;
if ( V_148 )
V_151 += F_99 ( V_150 , V_148 , V_149 , V_65 ) ;
else
V_151 += fprintf ( V_150 , V_149 , V_65 ) ;
fprintf ( V_150 , L_35 , V_152 - V_151 - 1 , V_78 ) ;
}
static void F_100 ( void * V_142 )
{
struct V_143 * V_144 = V_142 ;
int V_153 ;
fputc ( '\n' , V_144 -> V_146 ) ;
if ( V_144 -> V_147 )
fprintf ( V_144 -> V_146 , L_36 , V_144 -> V_147 , V_125 ) ;
F_91 ( V_144 -> V_10 , V_144 -> V_52 , V_144 -> V_85 ) ;
for ( V_153 = 0 ; V_153 < V_144 -> V_154 ; V_153 ++ )
fputs ( V_125 , V_144 -> V_146 ) ;
}
static void F_101 ( void * V_142 ,
const char * V_148 V_36 ,
const char * V_149 , const char * V_78 , double V_65 )
{
struct V_143 * V_144 = V_142 ;
T_9 * V_150 = V_144 -> V_146 ;
char V_155 [ 64 ] , * V_156 , * V_157 ;
if ( V_78 == NULL || V_149 == NULL ) {
fprintf ( V_150 , L_37 , V_125 , V_125 , V_125 , V_125 ) ;
return;
}
snprintf ( V_155 , sizeof( V_155 ) , V_149 , V_65 ) ;
V_157 = V_156 = F_102 ( V_155 ) ;
while ( isdigit ( * V_157 ) || * V_157 == '.' )
V_157 ++ ;
* V_157 = 0 ;
while ( isspace ( * V_78 ) )
V_78 ++ ;
fprintf ( V_150 , L_37 , V_125 , V_156 , V_125 , V_78 ) ;
}
static bool F_103 ( const char * V_78 )
{
if ( ! V_78 )
return false ;
if ( strstr ( V_78 , L_38 ) ||
strstr ( V_78 , L_39 ) ||
strstr ( V_78 , L_40 ) ||
strstr ( V_78 , L_41 ) )
return false ;
return true ;
}
static const char * F_104 ( char * V_155 , struct V_9 * V_10 ,
const char * V_78 )
{
if ( ! strncmp ( V_78 , L_42 , 6 ) ) {
snprintf ( V_155 , 1024 , L_43 , F_27 ( V_10 ) ,
V_78 ) ;
return V_155 ;
}
return V_78 ;
}
static void F_105 ( void * V_142 , const char * V_148 , const char * V_149 ,
const char * V_78 , double V_65 )
{
struct V_143 * V_144 = V_142 ;
T_9 * V_150 = V_144 -> V_146 ;
int V_151 ;
char V_155 [ 1024 ] ;
unsigned V_158 = V_159 ;
if ( ! F_103 ( V_78 ) )
return;
V_78 = F_104 ( V_155 , V_144 -> V_10 , V_78 ) ;
if ( V_148 )
V_151 = F_99 ( V_150 , V_148 , V_149 , V_65 ) ;
else
V_151 = fprintf ( V_150 , V_149 , V_65 ) ;
if ( V_151 > V_159 )
V_151 = V_159 ;
if ( V_158 < strlen ( V_78 ) )
V_158 = strlen ( V_78 ) + 1 ;
fprintf ( V_150 , L_44 , V_158 - V_151 , L_33 ) ;
}
static void F_106 ( void * V_142 , const char * V_148 V_36 ,
const char * V_149 ,
const char * V_78 , double V_65 )
{
struct V_143 * V_144 = V_142 ;
T_9 * V_150 = V_144 -> V_146 ;
char V_155 [ 64 ] , * V_156 , * V_157 ;
char V_160 [ 1024 ] ;
if ( ! F_103 ( V_78 ) )
return;
V_78 = F_104 ( V_160 , V_144 -> V_10 , V_78 ) ;
snprintf ( V_155 , sizeof V_155 , V_149 , V_65 ) ;
V_157 = V_156 = F_102 ( V_155 ) ;
while ( isdigit ( * V_157 ) || * V_157 == '.' )
V_157 ++ ;
* V_157 = 0 ;
fprintf ( V_150 , L_36 , V_156 , V_125 ) ;
}
static void F_107 ( void * V_142 V_36 )
{
}
static void F_108 ( void * V_142 , const char * V_148 V_36 ,
const char * V_149 V_36 ,
const char * V_78 , double V_65 V_36 )
{
struct V_143 * V_144 = V_142 ;
char V_160 [ 1024 ] ;
if ( ! F_103 ( V_78 ) )
return;
V_78 = F_104 ( V_160 , V_144 -> V_10 , V_78 ) ;
if ( V_124 )
fprintf ( V_144 -> V_146 , L_36 , V_78 , V_125 ) ;
else
fprintf ( V_144 -> V_146 , L_45 , V_159 , V_78 ) ;
}
static void F_109 ( int V_52 , int V_85 , struct V_9 * V_10 , double V_127 )
{
T_9 * V_63 = V_13 . V_63 ;
double V_161 = V_127 / V_100 ;
const char * V_162 , * V_163 ;
char V_67 [ 25 ] ;
V_162 = V_124 ? L_46 : L_47 ;
V_163 = V_124 ? L_48 : L_49 ;
F_91 ( V_10 , V_52 , V_85 ) ;
F_110 ( V_67 , sizeof( V_67 ) , L_36 ,
F_27 ( V_10 ) , V_124 ? L_33 : L_50 ) ;
fprintf ( V_63 , V_162 , V_161 , V_125 ) ;
if ( V_124 )
fprintf ( V_63 , L_36 , V_10 -> V_78 , V_125 ) ;
else
fprintf ( V_63 , L_51 , V_114 , V_10 -> V_78 , V_125 ) ;
fprintf ( V_63 , V_163 , V_67 ) ;
if ( V_10 -> V_164 )
fprintf ( V_63 , L_36 , V_125 , V_10 -> V_164 -> V_67 ) ;
}
static int F_111 ( struct V_9 * V_10 , int V_52 )
{
int V_153 ;
if ( ! V_165 )
return 0 ;
if ( V_13 . V_134 == V_137 )
return V_52 ;
if ( V_13 . V_134 == V_140 )
return 0 ;
for ( V_153 = 0 ; V_153 < F_24 ( V_10 ) ; V_153 ++ ) {
int V_166 = F_10 ( V_10 ) -> V_138 [ V_153 ] ;
if ( V_165 ( V_8 -> V_82 , V_166 ) == V_52 )
return V_166 ;
}
return 0 ;
}
static void F_112 ( int V_52 , int V_85 , struct V_9 * V_10 , double V_127 )
{
T_9 * V_63 = V_13 . V_63 ;
double V_167 = V_10 -> V_14 ;
const char * V_149 ;
if ( V_124 ) {
V_149 = floor ( V_167 ) != V_167 ? L_52 : L_53 ;
} else {
if ( V_168 )
V_149 = floor ( V_167 ) != V_167 ? L_54 : L_55 ;
else
V_149 = floor ( V_167 ) != V_167 ? L_56 : L_57 ;
}
F_91 ( V_10 , V_52 , V_85 ) ;
fprintf ( V_63 , V_149 , V_127 , V_125 ) ;
if ( V_10 -> V_78 )
fprintf ( V_63 , L_51 ,
V_124 ? 0 : V_114 ,
V_10 -> V_78 , V_125 ) ;
fprintf ( V_63 , L_32 , V_124 ? 0 : 25 , F_27 ( V_10 ) ) ;
if ( V_10 -> V_164 )
fprintf ( V_63 , L_36 , V_125 , V_10 -> V_164 -> V_67 ) ;
}
static void F_113 ( int V_52 , int V_85 , struct V_9 * V_45 , double V_169 ,
char * V_147 , T_3 V_61 , T_3 V_60 , double V_170 )
{
struct V_171 V_150 ;
struct V_143 V_144 = {
. V_146 = V_13 . V_63 ,
. V_147 = V_147 ? V_147 : L_33 ,
. V_52 = V_52 ,
. V_85 = V_85 ,
. V_10 = V_45 ,
} ;
T_10 V_172 = F_98 ;
void (* F_114)( void * );
if ( V_173 ) {
F_114 = F_107 ;
if ( V_124 )
V_172 = F_106 ;
else
V_172 = F_105 ;
} else
F_114 = F_96 ;
if ( V_124 && ! V_173 ) {
static int V_174 [] = {
[ V_140 ] = 0 ,
[ V_139 ] = 1 ,
[ V_137 ] = 1 ,
[ V_136 ] = 2 ,
[ V_135 ] = 2 ,
} ;
V_172 = F_101 ;
F_114 = F_100 ;
V_144 . V_154 = 3 ;
V_144 . V_154 += V_174 [ V_13 . V_134 ] ;
if ( V_45 -> V_164 )
V_144 . V_154 ++ ;
}
if ( V_61 == 0 || V_60 == 0 || V_45 -> V_58 -> V_59 == - 1 ) {
if ( V_173 ) {
V_172 ( & V_144 , NULL , L_33 , L_33 , 0 ) ;
return;
}
F_91 ( V_45 , V_52 , V_85 ) ;
fprintf ( V_13 . V_63 , L_58 ,
V_124 ? 0 : 18 ,
V_45 -> V_55 ? V_175 : V_176 ,
V_125 ) ;
if ( V_45 -> V_55 )
V_177 = 1 ;
fprintf ( V_13 . V_63 , L_51 ,
V_124 ? 0 : V_114 ,
V_45 -> V_78 , V_125 ) ;
fprintf ( V_13 . V_63 , L_44 ,
V_124 ? 0 : - 25 ,
F_27 ( V_45 ) ) ;
if ( V_45 -> V_164 )
fprintf ( V_13 . V_63 , L_36 ,
V_125 , V_45 -> V_164 -> V_67 ) ;
if ( ! V_124 )
V_172 ( & V_144 , NULL , NULL , L_33 , 0 ) ;
F_89 ( V_45 , V_170 ) ;
F_86 ( V_61 , V_60 ) ;
if ( V_124 )
V_172 ( & V_144 , NULL , NULL , L_33 , 0 ) ;
return;
}
if ( V_173 )
;
else if ( F_12 ( V_45 ) )
F_109 ( V_52 , V_85 , V_45 , V_169 ) ;
else
F_112 ( V_52 , V_85 , V_45 , V_169 ) ;
V_150 . V_178 = V_172 ;
V_150 . V_179 = F_114 ;
V_150 . V_142 = & V_144 ;
V_150 . V_180 = false ;
if ( V_124 && ! V_173 ) {
F_89 ( V_45 , V_170 ) ;
F_86 ( V_61 , V_60 ) ;
}
F_115 ( V_45 , V_169 ,
F_111 ( V_45 , V_52 ) ,
& V_150 ) ;
if ( ! V_124 && ! V_173 ) {
F_89 ( V_45 , V_170 ) ;
F_86 ( V_61 , V_60 ) ;
}
}
static void F_116 ( void )
{
int V_46 , V_181 , V_52 , V_182 ;
T_3 V_65 ;
struct V_9 * V_45 ;
for ( V_182 = 0 ; V_182 < V_183 -> V_85 ; V_182 ++ ) {
V_52 = V_183 -> V_138 [ V_182 ] ;
F_29 (evsel_list, counter) {
V_65 = 0 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_181 = V_165 ( V_8 -> V_82 , V_46 ) ;
if ( V_181 != V_52 )
continue;
V_65 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_65 ;
}
V_65 = V_65 * V_45 -> V_14 ;
F_117 ( V_45 , & V_65 ,
F_111 ( V_45 , V_52 ) ) ;
}
}
}
static void F_118 ( struct V_9 * V_45 ,
void (* F_119)( struct V_9 * V_45 , void * V_184 ,
bool V_185 ) ,
void * V_184 )
{
struct V_9 * V_186 ;
V_186 = F_120 ( V_45 , & ( V_8 -> V_187 ) , V_188 ) ;
F_121 (alias, &evsel_list->entries, node) {
if ( strcmp ( F_27 ( V_186 ) , F_27 ( V_45 ) ) ||
V_186 -> V_14 != V_45 -> V_14 ||
V_186 -> V_164 != V_45 -> V_164 ||
strcmp ( V_186 -> V_78 , V_45 -> V_78 ) ||
F_12 ( V_186 ) != F_12 ( V_45 ) )
break;
V_186 -> V_189 = true ;
F_119 ( V_186 , V_184 , false ) ;
}
}
static bool F_122 ( struct V_9 * V_45 ,
void (* F_119)( struct V_9 * V_45 , void * V_184 ,
bool V_185 ) ,
void * V_184 )
{
if ( V_45 -> V_189 )
return false ;
F_119 ( V_45 , V_184 , true ) ;
if ( ! V_190 )
F_118 ( V_45 , F_119 , V_184 ) ;
return true ;
}
static void F_123 ( struct V_9 * V_45 , void * V_184 , bool V_185 )
{
struct V_191 * V_192 = V_184 ;
int V_46 , V_181 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
struct V_48 * V_58 ;
V_181 = V_165 ( F_10 ( V_45 ) , V_46 ) ;
if ( V_181 != V_192 -> V_52 )
continue;
if ( V_185 )
V_192 -> V_85 ++ ;
V_58 = F_25 ( V_45 -> V_58 , V_46 , 0 ) ;
if ( V_58 -> V_60 == 0 || V_58 -> V_61 == 0 ||
V_45 -> V_58 -> V_59 == - 1 ) {
V_192 -> V_60 = 0 ;
V_192 -> V_61 = 0 ;
break;
}
V_192 -> V_65 += V_58 -> V_65 ;
V_192 -> V_60 += V_58 -> V_60 ;
V_192 -> V_61 += V_58 -> V_61 ;
}
}
static void F_124 ( char * V_147 )
{
T_9 * V_63 = V_13 . V_63 ;
struct V_9 * V_45 ;
int V_182 , V_52 , V_85 ;
double V_169 ;
T_3 V_60 , V_61 , V_65 ;
bool V_185 ;
if ( ! ( V_183 || V_165 ) )
return;
F_116 () ;
for ( V_182 = 0 ; V_182 < V_183 -> V_85 ; V_182 ++ ) {
struct V_191 V_192 ;
if ( V_147 && V_173 )
fprintf ( V_63 , L_48 , V_147 ) ;
V_192 . V_52 = V_52 = V_183 -> V_138 [ V_182 ] ;
V_185 = true ;
F_29 (evsel_list, counter) {
V_192 . V_65 = V_192 . V_60 = V_192 . V_61 = 0 ;
V_192 . V_85 = 0 ;
if ( ! F_122 ( V_45 , F_123 , & V_192 ) )
continue;
V_85 = V_192 . V_85 ;
V_60 = V_192 . V_60 ;
V_61 = V_192 . V_61 ;
V_65 = V_192 . V_65 ;
if ( V_185 && V_173 ) {
V_185 = false ;
F_91 ( V_45 , V_52 , V_85 ) ;
}
if ( V_147 && ! V_173 )
fprintf ( V_63 , L_48 , V_147 ) ;
V_169 = V_65 * V_45 -> V_14 ;
F_113 ( V_52 , V_85 , V_45 , V_169 , V_147 , V_61 , V_60 , 1.0 ) ;
if ( ! V_173 )
fputc ( '\n' , V_63 ) ;
}
if ( V_173 )
fputc ( '\n' , V_63 ) ;
}
}
static void F_125 ( struct V_9 * V_45 , char * V_147 )
{
T_9 * V_63 = V_13 . V_63 ;
int V_53 = F_23 ( V_45 -> V_31 ) ;
int V_54 = F_126 ( V_45 -> V_82 ) ;
int V_46 , V_47 ;
double V_169 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
T_3 V_60 = 0 , V_61 = 0 , V_65 = 0 ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
V_65 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_65 ;
V_60 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_60 ;
V_61 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_61 ;
}
if ( V_147 )
fprintf ( V_63 , L_48 , V_147 ) ;
V_169 = V_65 * V_45 -> V_14 ;
F_113 ( V_47 , 0 , V_45 , V_169 , V_147 , V_61 , V_60 , 1.0 ) ;
fputc ( '\n' , V_63 ) ;
}
}
static void F_127 ( struct V_9 * V_45 , void * V_184 ,
bool V_185 V_36 )
{
struct V_193 * V_194 = V_184 ;
struct V_129 * V_130 = V_45 -> V_132 ;
V_194 -> V_127 += F_128 ( & V_130 -> V_133 [ 0 ] ) ;
V_194 -> V_195 += F_128 ( & V_130 -> V_133 [ 1 ] ) ;
V_194 -> V_196 += F_128 ( & V_130 -> V_133 [ 2 ] ) ;
}
static void F_129 ( struct V_9 * V_45 , char * V_147 )
{
T_9 * V_63 = V_13 . V_63 ;
double V_169 ;
struct V_193 V_194 = { . V_127 = 0.0 } ;
if ( ! F_122 ( V_45 , F_127 , & V_194 ) )
return;
if ( V_147 && ! V_173 )
fprintf ( V_63 , L_48 , V_147 ) ;
V_169 = V_194 . V_127 * V_45 -> V_14 ;
F_113 ( - 1 , 0 , V_45 , V_169 , V_147 , V_194 . V_196 , V_194 . V_195 , V_194 . V_127 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_5 ) ;
}
static void F_130 ( struct V_9 * V_45 , void * V_184 ,
bool V_185 V_36 )
{
struct V_191 * V_192 = V_184 ;
V_192 -> V_65 += F_25 ( V_45 -> V_58 , V_192 -> V_46 , 0 ) -> V_65 ;
V_192 -> V_60 += F_25 ( V_45 -> V_58 , V_192 -> V_46 , 0 ) -> V_60 ;
V_192 -> V_61 += F_25 ( V_45 -> V_58 , V_192 -> V_46 , 0 ) -> V_61 ;
}
static void F_131 ( struct V_9 * V_45 , char * V_147 )
{
T_9 * V_63 = V_13 . V_63 ;
T_3 V_60 , V_61 , V_65 ;
double V_169 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
struct V_191 V_192 = { . V_46 = V_46 } ;
if ( ! F_122 ( V_45 , F_130 , & V_192 ) )
return;
V_65 = V_192 . V_65 ;
V_60 = V_192 . V_60 ;
V_61 = V_192 . V_61 ;
if ( V_147 )
fprintf ( V_63 , L_48 , V_147 ) ;
V_169 = V_65 * V_45 -> V_14 ;
F_113 ( V_46 , 0 , V_45 , V_169 , V_147 , V_61 , V_60 , 1.0 ) ;
fputc ( '\n' , V_63 ) ;
}
}
static void F_132 ( char * V_147 )
{
int V_46 ;
int V_197 = 0 ;
struct V_9 * V_45 ;
T_3 V_60 , V_61 , V_65 ;
double V_169 ;
V_197 = V_8 -> V_82 -> V_85 ;
for ( V_46 = 0 ; V_46 < V_197 ; V_46 ++ ) {
bool V_185 = true ;
if ( V_147 )
fputs ( V_147 , V_13 . V_63 ) ;
F_29 (evsel_list, counter) {
if ( V_185 ) {
F_91 ( V_45 , V_46 , 0 ) ;
V_185 = false ;
}
V_65 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_65 ;
V_60 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_60 ;
V_61 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_61 ;
V_169 = V_65 * V_45 -> V_14 ;
F_113 ( V_46 , 0 , V_45 , V_169 , V_147 , V_61 , V_60 , 1.0 ) ;
}
fputc ( '\n' , V_13 . V_63 ) ;
}
}
static void F_133 ( const char * V_147 , bool V_198 )
{
struct V_171 V_150 ;
struct V_9 * V_45 ;
struct V_143 V_144 = {
. V_146 = V_13 . V_63
} ;
if ( V_147 )
fprintf ( V_13 . V_63 , L_48 , V_147 ) ;
if ( ! V_124 && ! V_198 )
fprintf ( V_13 . V_63 , L_44 ,
V_199 [ V_13 . V_134 ] , L_33 ) ;
if ( V_124 ) {
if ( V_13 . V_90 )
fputs ( L_59 , V_13 . V_63 ) ;
fputs ( V_200 [ V_13 . V_134 ] ,
V_13 . V_63 ) ;
}
F_29 (evsel_list, counter) {
V_144 . V_10 = V_45 ;
V_150 . V_142 = & V_144 ;
V_150 . V_178 = F_108 ;
V_150 . V_179 = F_107 ;
V_150 . V_180 = true ;
V_144 . V_10 = V_45 ;
F_115 ( V_45 , 0 ,
0 ,
& V_150 ) ;
}
fputc ( '\n' , V_13 . V_63 ) ;
}
static void F_134 ( char * V_147 , struct V_1 * V_68 )
{
T_9 * V_63 = V_13 . V_63 ;
static int V_201 ;
sprintf ( V_147 , L_60 , V_68 -> V_5 , V_68 -> V_6 , V_125 ) ;
if ( V_201 == 0 && ! V_124 ) {
switch ( V_13 . V_134 ) {
case V_136 :
fprintf ( V_63 , L_61 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_62 , V_114 , L_63 ) ;
break;
case V_135 :
fprintf ( V_63 , L_64 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_62 , V_114 , L_63 ) ;
break;
case V_137 :
fprintf ( V_63 , L_65 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_66 , V_114 , L_63 ) ;
break;
case V_139 :
fprintf ( V_63 , L_67 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_68 , V_114 , L_63 ) ;
break;
case V_140 :
default:
fprintf ( V_63 , L_69 ) ;
if ( ! V_173 )
fprintf ( V_63 , L_62 , V_114 , L_63 ) ;
case V_141 :
break;
}
}
if ( V_201 == 0 && V_173 )
F_133 ( L_70 , true ) ;
if ( ++ V_201 == 25 )
V_201 = 0 ;
}
static void F_135 ( int V_88 , const char * * V_89 )
{
T_9 * V_63 = V_13 . V_63 ;
int V_153 ;
fflush ( stdout ) ;
if ( ! V_124 ) {
fprintf ( V_63 , L_5 ) ;
fprintf ( V_63 , L_71 ) ;
if ( V_28 . V_57 )
fprintf ( V_63 , L_72 ) ;
else if ( V_28 . V_202 )
fprintf ( V_63 , L_73 , V_28 . V_202 ) ;
else if ( ! F_136 ( & V_28 ) ) {
fprintf ( V_63 , L_74 , V_89 ? V_89 [ 0 ] : L_75 ) ;
for ( V_153 = 1 ; V_89 && ( V_153 < V_88 ) ; V_153 ++ )
fprintf ( V_63 , L_76 , V_89 [ V_153 ] ) ;
} else if ( V_28 . V_103 )
fprintf ( V_63 , L_77 , V_28 . V_103 ) ;
else
fprintf ( V_63 , L_78 , V_28 . V_203 ) ;
fprintf ( V_63 , L_79 ) ;
if ( V_131 > 1 )
fprintf ( V_63 , L_80 , V_131 ) ;
fprintf ( V_63 , L_81 ) ;
}
}
static void F_137 ( void )
{
T_9 * V_63 = V_13 . V_63 ;
int V_151 ;
if ( ! V_204 )
fprintf ( V_63 , L_5 ) ;
fprintf ( V_63 , L_82 ,
F_128 ( & V_120 ) / V_7 ) ;
if ( V_131 > 1 ) {
fprintf ( V_63 , L_83 ) ;
F_87 ( F_90 ( & V_120 ) ,
F_128 ( & V_120 ) ) ;
}
fprintf ( V_63 , L_84 ) ;
if ( V_177 &&
F_138 ( L_85 , & V_151 ) >= 0 &&
V_151 > 0 )
fprintf ( V_63 ,
L_86
L_87
L_88
L_89 ) ;
}
static void F_36 ( struct V_1 * V_68 , int V_88 , const char * * V_89 )
{
int V_90 = V_13 . V_90 ;
struct V_9 * V_45 ;
char V_155 [ 64 ] , * V_147 = NULL ;
if ( V_21 && V_22 . V_23 . V_24 )
return;
if ( V_90 )
F_134 ( V_147 = V_155 , V_68 ) ;
else
F_135 ( V_88 , V_89 ) ;
if ( V_173 ) {
static int V_205 ;
if ( V_205 == 0 && ! V_90 )
F_133 ( V_147 , false ) ;
if ( V_205 ++ == 25 )
V_205 = 0 ;
if ( V_13 . V_134 == V_140 && V_147 )
fprintf ( V_13 . V_63 , L_48 , V_147 ) ;
}
switch ( V_13 . V_134 ) {
case V_135 :
case V_136 :
F_124 ( V_147 ) ;
break;
case V_139 :
F_29 (evsel_list, counter)
F_125 ( V_45 , V_147 ) ;
break;
case V_140 :
F_29 (evsel_list, counter)
F_129 ( V_45 , V_147 ) ;
if ( V_173 )
fputc ( '\n' , V_13 . V_63 ) ;
break;
case V_137 :
if ( V_173 )
F_132 ( V_147 ) ;
else {
F_29 (evsel_list, counter)
F_131 ( V_45 , V_147 ) ;
}
break;
case V_141 :
default:
break;
}
if ( ! V_90 && ! V_124 )
F_137 () ;
fflush ( V_13 . V_63 ) ;
}
static void F_139 ( int T_5 )
{
if ( ( V_101 == - 1 ) || V_13 . V_90 )
V_119 = 1 ;
V_206 = T_5 ;
V_101 = - 1 ;
}
static void F_140 ( void )
{
T_11 V_207 , V_208 ;
F_141 ( & V_207 ) ;
F_142 ( & V_207 , V_209 ) ;
F_143 ( V_210 , & V_207 , & V_208 ) ;
if ( V_101 != - 1 )
F_66 ( V_101 , V_113 ) ;
F_143 ( V_211 , & V_208 , NULL ) ;
if ( V_206 == - 1 )
return;
signal ( V_206 , V_212 ) ;
F_66 ( F_144 () , V_206 ) ;
}
static int F_145 ( const struct V_213 * T_12 V_36 ,
const char * V_182 V_36 , int V_214 )
{
V_215 = V_214 ? 0 : 1 ;
return 0 ;
}
static int F_146 ( const struct V_213 * T_12 V_36 ,
const char * V_182 V_36 , int V_214 )
{
V_216 = true ;
V_173 = ! V_214 ;
return 0 ;
}
static int F_147 ( struct V_83 * V_138 , int V_46 )
{
return F_148 ( V_138 , V_46 , NULL ) ;
}
static int F_149 ( struct V_83 * V_138 , int V_46 )
{
return F_150 ( V_138 , V_46 , NULL ) ;
}
static int F_151 ( struct V_83 * V_138 )
{
int V_153 , V_217 = - 1 ;
for ( V_153 = 0 ; V_153 < V_138 -> V_85 ; V_153 ++ ) {
if ( V_138 -> V_138 [ V_153 ] > V_217 )
V_217 = V_138 -> V_138 [ V_153 ] ;
}
return V_217 ;
}
static int F_152 ( T_13 V_218 , struct V_83 * V_138 , int V_219 )
{
int V_46 ;
if ( V_219 >= V_138 -> V_85 )
return - 1 ;
V_46 = V_138 -> V_138 [ V_219 ] ;
if ( V_220 -> V_138 [ V_46 ] == - 1 )
V_220 -> V_138 [ V_46 ] = V_218 ( V_138 , V_219 ) ;
return V_220 -> V_138 [ V_46 ] ;
}
static int F_153 ( struct V_83 * V_138 , int V_219 )
{
return F_152 ( F_147 , V_138 , V_219 ) ;
}
static int F_154 ( struct V_83 * V_138 , int V_219 )
{
return F_152 ( F_149 , V_138 , V_219 ) ;
}
static int F_155 ( void )
{
int V_85 ;
switch ( V_13 . V_134 ) {
case V_136 :
if ( F_156 ( V_8 -> V_82 , & V_183 ) ) {
perror ( L_90 ) ;
return - 1 ;
}
V_165 = F_153 ;
break;
case V_135 :
if ( F_157 ( V_8 -> V_82 , & V_183 ) ) {
perror ( L_91 ) ;
return - 1 ;
}
V_165 = F_154 ;
break;
case V_137 :
case V_140 :
case V_139 :
case V_141 :
default:
break;
}
V_85 = F_151 ( V_8 -> V_82 ) ;
V_220 = F_158 ( V_85 + 1 ) ;
return V_220 ? 0 : - V_87 ;
}
static void F_159 ( void )
{
F_160 ( V_183 ) ;
F_160 ( V_220 ) ;
V_183 = NULL ;
V_220 = NULL ;
}
static inline int F_161 ( struct V_221 * V_222 , struct V_83 * V_138 , int V_219 )
{
int V_46 ;
if ( V_219 > V_138 -> V_85 )
return - 1 ;
V_46 = V_138 -> V_138 [ V_219 ] ;
if ( V_46 >= V_222 -> V_223 )
return - 1 ;
return V_46 ;
}
static int F_162 ( struct V_83 * V_138 , int V_219 , void * V_184 )
{
struct V_221 * V_222 = V_184 ;
int V_46 = F_161 ( V_222 , V_138 , V_219 ) ;
return V_46 == - 1 ? - 1 : V_222 -> V_46 [ V_46 ] . V_224 ;
}
static int F_163 ( struct V_83 * V_138 , int V_219 , void * V_184 )
{
struct V_221 * V_222 = V_184 ;
int V_225 = - 1 , V_46 = F_161 ( V_222 , V_138 , V_219 ) ;
if ( V_46 != - 1 ) {
int V_224 = V_222 -> V_46 [ V_46 ] . V_224 ;
V_225 = ( V_224 << 16 ) | ( V_222 -> V_46 [ V_46 ] . V_226 & 0xffff ) ;
}
return V_225 ;
}
static int F_164 ( struct V_221 * V_222 , struct V_83 * V_82 ,
struct V_83 * * V_227 )
{
return F_165 ( V_82 , V_227 , F_162 , V_222 ) ;
}
static int F_166 ( struct V_221 * V_222 , struct V_83 * V_82 ,
struct V_83 * * V_228 )
{
return F_165 ( V_82 , V_228 , F_163 , V_222 ) ;
}
static int F_167 ( struct V_83 * V_138 , int V_219 )
{
return F_162 ( V_138 , V_219 , & V_22 . V_80 -> V_41 . V_222 ) ;
}
static int F_168 ( struct V_83 * V_138 , int V_219 )
{
return F_163 ( V_138 , V_219 , & V_22 . V_80 -> V_41 . V_222 ) ;
}
static int F_169 ( struct V_22 * V_229 )
{
struct V_221 * V_222 = & V_229 -> V_80 -> V_41 . V_222 ;
switch ( V_13 . V_134 ) {
case V_136 :
if ( F_164 ( V_222 , V_8 -> V_82 , & V_183 ) ) {
perror ( L_90 ) ;
return - 1 ;
}
V_165 = F_167 ;
break;
case V_135 :
if ( F_166 ( V_222 , V_8 -> V_82 , & V_183 ) ) {
perror ( L_91 ) ;
return - 1 ;
}
V_165 = F_168 ;
break;
case V_137 :
case V_140 :
case V_139 :
case V_141 :
default:
break;
}
return 0 ;
}
static int F_170 ( const char * * V_12 , char * * V_230 , bool V_231 )
{
int V_232 = 0 ;
int V_153 ;
int V_233 = 0 ;
char * V_182 ;
for ( V_153 = 0 ; V_12 [ V_153 ] ; V_153 ++ ) {
if ( F_171 ( L_92 , V_12 [ V_153 ] ) ) {
V_233 += strlen ( V_12 [ V_153 ] ) + 1 ;
V_12 [ V_153 - V_232 ] = V_12 [ V_153 ] ;
} else
V_232 ++ ;
}
V_12 [ V_153 - V_232 ] = NULL ;
* V_230 = malloc ( V_233 + 1 + 2 ) ;
if ( ! * V_230 )
return - 1 ;
V_182 = * V_230 ;
if ( V_153 - V_232 == 0 ) {
* V_182 = 0 ;
return 0 ;
}
if ( V_231 )
* V_182 ++ = '{' ;
for ( V_153 = 0 ; V_12 [ V_153 ] ; V_153 ++ ) {
strcpy ( V_182 , V_12 [ V_153 ] ) ;
V_182 += strlen ( V_182 ) ;
* V_182 ++ = ',' ;
}
if ( V_231 ) {
V_182 [ - 1 ] = '}' ;
* V_182 = 0 ;
} else
V_182 [ - 1 ] = 0 ;
return 0 ;
}
__weak bool F_172 ( bool * V_234 )
{
* V_234 = false ;
return false ;
}
__weak void F_173 ( void )
{
}
static int F_174 ( void )
{
int V_79 ;
struct V_11 V_235 [] = {
{ . type = V_236 , . V_237 = V_238 } ,
{ . type = V_236 , . V_237 = V_239 } ,
{ . type = V_236 , . V_237 = V_240 } ,
{ . type = V_236 , . V_237 = V_241 } ,
{ . type = V_242 , . V_237 = V_243 } ,
} ;
struct V_11 V_244 [] = {
{ . type = V_242 , . V_237 = V_245 } ,
} ;
struct V_11 V_246 [] = {
{ . type = V_242 , . V_237 = V_247 } ,
} ;
struct V_11 V_248 [] = {
{ . type = V_242 , . V_237 = V_249 } ,
{ . type = V_242 , . V_237 = V_250 } ,
{ . type = V_242 , . V_237 = V_251 } ,
} ;
struct V_11 V_252 [] = {
{ . type = V_253 ,
. V_237 =
V_254 << 0 |
( V_255 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_254 << 0 |
( V_255 << 8 ) |
( V_257 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_258 << 0 |
( V_255 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_258 << 0 |
( V_255 << 8 ) |
( V_257 << 16 ) } ,
} ;
struct V_11 V_259 [] = {
{ . type = V_253 ,
. V_237 =
V_260 << 0 |
( V_255 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_260 << 0 |
( V_255 << 8 ) |
( V_257 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_261 << 0 |
( V_255 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_261 << 0 |
( V_255 << 8 ) |
( V_257 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_262 << 0 |
( V_255 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_262 << 0 |
( V_255 << 8 ) |
( V_257 << 16 ) } ,
} ;
struct V_11 V_263 [] = {
{ . type = V_253 ,
. V_237 =
V_254 << 0 |
( V_264 << 8 ) |
( V_256 << 16 ) } ,
{ . type = V_253 ,
. V_237 =
V_254 << 0 |
( V_264 << 8 ) |
( V_257 << 16 ) } ,
} ;
if ( V_204 )
return 0 ;
if ( V_265 ) {
if ( F_171 ( L_92 , L_93 ) &&
F_171 ( L_92 , L_94 ) )
V_79 = F_175 ( V_8 , V_266 , NULL ) ;
else
V_79 = F_175 ( V_8 , V_267 , NULL ) ;
if ( V_79 ) {
fprintf ( V_268 , L_95 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_269 ) {
char * V_230 = NULL ;
bool V_234 = false ;
if ( V_13 . V_134 != V_140 &&
V_13 . V_134 != V_135 ) {
F_16 ( L_96 ) ;
return - 1 ;
}
V_13 . V_134 = V_135 ;
if ( V_270 || ! F_8 ( & V_28 ) ) {
F_16 ( L_97 ) ;
return - 1 ;
}
if ( ! V_216 )
V_173 = true ;
if ( F_170 ( V_271 , & V_230 ,
F_172 ( & V_234 ) ) < 0 ) {
F_16 ( L_98 ) ;
return - 1 ;
}
if ( V_271 [ 0 ] && V_230 ) {
if ( V_234 )
F_173 () ;
V_79 = F_175 ( V_8 , V_230 , NULL ) ;
if ( V_79 ) {
fprintf ( V_268 ,
L_99 ,
V_230 , V_79 ) ;
free ( V_230 ) ;
return - 1 ;
}
} else {
fprintf ( V_268 , L_100 ) ;
return - 1 ;
}
free ( V_230 ) ;
}
if ( ! V_8 -> V_272 ) {
if ( F_8 ( & V_28 ) )
V_235 [ 0 ] . V_237 = V_273 ;
if ( F_176 ( V_8 , V_235 ) < 0 )
return - 1 ;
if ( F_171 ( L_92 , L_101 ) ) {
if ( F_176 ( V_8 ,
V_244 ) < 0 )
return - 1 ;
}
if ( F_171 ( L_92 , L_102 ) ) {
if ( F_176 ( V_8 ,
V_246 ) < 0 )
return - 1 ;
}
if ( F_176 ( V_8 , V_248 ) < 0 )
return - 1 ;
}
if ( V_274 < 1 )
return 0 ;
if ( F_176 ( V_8 , V_252 ) < 0 )
return - 1 ;
if ( V_274 < 2 )
return 0 ;
if ( F_176 ( V_8 , V_259 ) < 0 )
return - 1 ;
if ( V_274 < 3 )
return 0 ;
return F_176 ( V_8 , V_263 ) ;
}
static void F_177 ( struct V_275 * V_80 )
{
int V_276 ;
for ( V_276 = V_277 ; V_276 < V_278 ; V_276 ++ )
F_178 ( & V_80 -> V_41 , V_276 ) ;
F_179 ( & V_80 -> V_41 , V_279 ) ;
F_179 ( & V_80 -> V_41 , V_280 ) ;
F_179 ( & V_80 -> V_41 , V_281 ) ;
F_179 ( & V_80 -> V_41 , V_282 ) ;
}
static int F_180 ( int V_88 , const char * * V_89 )
{
struct V_275 * V_80 ;
struct V_283 * V_23 = & V_22 . V_23 ;
V_88 = F_181 ( V_88 , V_89 , V_284 , V_285 ,
V_286 ) ;
if ( V_287 )
V_23 -> V_288 = V_287 ;
if ( V_131 != 1 || V_289 ) {
F_16 ( L_103 ) ;
return - 1 ;
}
V_80 = F_182 ( V_23 , false , NULL ) ;
if ( V_80 == NULL ) {
F_16 ( L_104 ) ;
return - 1 ;
}
F_177 ( V_80 ) ;
V_80 -> V_290 = V_8 ;
V_22 . V_80 = V_80 ;
V_22 . V_291 = true ;
return V_88 ;
}
static int F_183 ( struct V_35 * T_1 V_36 ,
union V_37 * V_38 ,
struct V_275 * V_80 )
{
struct V_292 * V_293 = & V_38 -> V_293 ;
struct V_9 * V_45 ;
struct V_1 V_294 , * V_68 = NULL ;
const char * * V_89 = V_80 -> V_41 . V_222 . V_295 ;
int V_88 = V_80 -> V_41 . V_222 . V_296 ;
F_29 (evsel_list, counter)
F_31 ( & V_13 , V_45 ) ;
if ( V_293 -> type == V_297 )
F_81 ( & V_120 , V_293 -> time ) ;
if ( V_13 . V_90 && V_293 -> time ) {
V_294 . V_5 = V_293 -> time / V_7 ;
V_294 . V_6 = V_293 -> time % V_7 ;
V_68 = & V_294 ;
}
F_36 ( V_68 , V_88 , V_89 ) ;
return 0 ;
}
static
int F_184 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_275 * V_80 V_36 )
{
struct V_22 * V_229 = F_185 ( T_1 , struct V_22 , T_1 ) ;
F_186 ( & V_13 , & V_38 -> V_13 ) ;
if ( F_187 ( V_229 -> V_82 ) ) {
if ( V_229 -> V_134 != V_141 )
F_32 ( L_105 ) ;
return 0 ;
}
if ( V_229 -> V_134 != V_141 )
V_13 . V_134 = V_229 -> V_134 ;
if ( V_22 . V_23 . V_24 )
F_155 () ;
else
F_169 ( V_229 ) ;
return 0 ;
}
static int F_188 ( struct V_22 * V_229 )
{
if ( ! V_229 -> V_82 || ! V_229 -> V_31 )
return 0 ;
if ( F_189 ( V_229 -> V_298 , L_106 ) )
return - V_107 ;
F_190 ( V_8 , V_229 -> V_82 , V_229 -> V_31 ) ;
if ( F_191 ( V_8 , true ) )
return - V_87 ;
V_229 -> V_298 = true ;
return 0 ;
}
static
int F_192 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_275 * V_80 V_36 )
{
struct V_22 * V_229 = F_185 ( T_1 , struct V_22 , T_1 ) ;
if ( V_229 -> V_31 ) {
F_32 ( L_107 ) ;
return 0 ;
}
V_229 -> V_31 = F_193 ( & V_38 -> V_84 ) ;
if ( ! V_229 -> V_31 )
return - V_87 ;
return F_188 ( V_229 ) ;
}
static
int F_194 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_275 * V_80 V_36 )
{
struct V_22 * V_229 = F_185 ( T_1 , struct V_22 , T_1 ) ;
struct V_83 * V_82 ;
if ( V_229 -> V_82 ) {
F_32 ( L_108 ) ;
return 0 ;
}
V_82 = F_195 ( & V_38 -> V_83 . V_184 ) ;
if ( ! V_82 )
return - V_87 ;
V_229 -> V_82 = V_82 ;
return F_188 ( V_229 ) ;
}
static int F_196 ( int V_88 , const char * * V_89 )
{
struct V_275 * V_80 ;
const struct V_213 V_299 [] = {
F_197 ( 'i' , L_109 , & V_300 , L_110 , L_111 ) ,
F_198 ( 0 , L_112 , & V_22 . V_134 ,
L_113 , V_136 ) ,
F_198 ( 0 , L_114 , & V_22 . V_134 ,
L_115 , V_135 ) ,
F_198 ( 'A' , L_116 , & V_22 . V_134 ,
L_117 , V_137 ) ,
F_199 ()
} ;
struct V_301 V_229 ;
int V_66 ;
V_88 = F_181 ( V_88 , V_89 , V_299 , V_302 , 0 ) ;
if ( ! V_300 || ! strlen ( V_300 ) ) {
if ( ! F_200 ( V_303 , & V_229 ) && F_201 ( V_229 . V_304 ) )
V_300 = L_118 ;
else
V_300 = L_119 ;
}
V_22 . V_23 . V_288 = V_300 ;
V_22 . V_23 . V_305 = V_306 ;
V_80 = F_182 ( & V_22 . V_23 , false , & V_22 . T_1 ) ;
if ( V_80 == NULL )
return - 1 ;
V_22 . V_80 = V_80 ;
V_13 . V_63 = V_268 ;
V_8 = V_80 -> V_290 ;
V_66 = F_202 ( V_80 ) ;
if ( V_66 )
return V_66 ;
F_203 ( V_80 ) ;
return 0 ;
}
static void F_204 ( int V_97 )
{
if ( ! F_7 ( & V_28 ) )
return;
if ( ! V_97 )
V_28 . V_57 = true ;
else {
struct V_9 * V_45 ;
F_29 (evsel_list, counter) {
if ( ! V_45 -> V_57 )
return;
}
if ( V_8 -> V_272 )
V_28 . V_57 = true ;
}
}
int F_205 ( int V_88 , const char * * V_89 )
{
const char * const V_307 [] = {
L_120 ,
NULL
} ;
int V_96 = - V_107 , V_308 ;
const char * V_305 ;
T_9 * V_63 = V_268 ;
unsigned int V_90 ;
const char * const V_309 [] = { L_121 , L_122 } ;
setlocale ( V_310 , L_33 ) ;
V_8 = F_206 () ;
if ( V_8 == NULL )
return - V_87 ;
F_207 () ;
V_88 = F_208 ( V_88 , V_89 , V_284 , V_309 ,
( const char * * ) V_307 ,
V_286 ) ;
F_209 ( V_8 ) ;
F_210 () ;
if ( V_125 ) {
V_124 = true ;
if ( ! strcmp ( V_125 , L_123 ) )
V_125 = L_124 ;
} else
V_125 = V_311 ;
if ( V_88 && ! strncmp ( V_89 [ 0 ] , L_125 , 3 ) ) {
V_88 = F_180 ( V_88 , V_89 ) ;
if ( V_88 < 0 )
return - 1 ;
} else if ( V_88 && ! strncmp ( V_89 [ 0 ] , L_126 , 3 ) )
return F_196 ( V_88 , V_89 ) ;
V_90 = V_13 . V_90 ;
if ( ! V_21 && V_287 && strcmp ( V_287 , L_118 ) )
V_63 = NULL ;
if ( V_287 && V_312 ) {
fprintf ( V_268 , L_127 ) ;
F_211 ( V_307 , V_284 , L_128 , 1 ) ;
F_211 ( NULL , V_284 , L_129 , 0 ) ;
goto V_150;
}
if ( V_173 && V_13 . V_134 == V_139 ) {
fprintf ( V_268 , L_130 ) ;
goto V_150;
}
if ( V_173 && V_131 > 1 ) {
fprintf ( V_268 , L_131 ) ;
goto V_150;
}
if ( V_312 < 0 ) {
fprintf ( V_268 , L_132 ) ;
F_211 ( V_307 , V_284 , L_129 , 0 ) ;
goto V_150;
}
if ( ! V_63 ) {
struct V_1 V_44 ;
V_305 = V_313 ? L_133 : L_134 ;
V_63 = fopen ( V_287 , V_305 ) ;
if ( ! V_63 ) {
perror ( L_135 ) ;
return - 1 ;
}
F_34 ( V_314 , & V_44 ) ;
fprintf ( V_63 , L_136 , ctime ( & V_44 . V_5 ) ) ;
} else if ( V_312 > 0 ) {
V_305 = V_313 ? L_133 : L_134 ;
V_63 = fdopen ( V_312 , V_305 ) ;
if ( ! V_63 ) {
perror ( L_137 ) ;
return - V_106 ;
}
}
V_13 . V_63 = V_63 ;
if ( V_124 ) {
if ( V_215 == 1 ) {
fprintf ( V_268 , L_138 ) ;
F_211 ( V_307 , V_284 , L_139 , 1 ) ;
F_211 ( NULL , V_284 , L_140 , 1 ) ;
goto V_150;
} else
V_168 = false ;
} else if ( V_215 == 0 )
V_168 = false ;
F_204 ( V_88 ) ;
if ( V_131 < 0 ) {
F_16 ( L_141 ) ;
F_211 ( V_307 , V_284 , L_142 , 1 ) ;
goto V_150;
} else if ( V_131 == 0 ) {
V_289 = true ;
V_131 = 1 ;
}
if ( ( V_13 . V_134 == V_139 ) && ! F_136 ( & V_28 ) ) {
fprintf ( V_268 , L_143
L_144 ) ;
F_211 ( NULL , V_284 , L_145 , 1 ) ;
F_211 ( NULL , V_284 , L_146 , 1 ) ;
goto V_150;
}
if ( ( ( V_13 . V_134 != V_140 &&
V_13 . V_134 != V_139 ) || V_270 ) &&
! F_8 ( & V_28 ) ) {
fprintf ( V_268 , L_147
L_148 ) ;
F_211 ( V_307 , V_284 , L_149 , 1 ) ;
F_211 ( NULL , V_284 , L_150 , 1 ) ;
F_211 ( NULL , V_284 , L_133 , 1 ) ;
goto V_150;
}
if ( F_174 () )
goto V_150;
F_212 ( & V_28 ) ;
if ( F_213 ( V_8 , & V_28 ) < 0 ) {
if ( F_136 ( & V_28 ) ) {
F_16 ( L_151 ) ;
F_211 ( V_307 , V_284 , L_145 , 1 ) ;
F_211 ( NULL , V_284 , L_146 , 1 ) ;
} else if ( F_8 ( & V_28 ) ) {
perror ( L_152 ) ;
F_211 ( V_307 , V_284 , L_153 , 1 ) ;
F_211 ( NULL , V_284 , L_133 , 1 ) ;
}
goto V_150;
}
if ( V_13 . V_134 == V_139 )
F_214 ( V_8 -> V_31 ) ;
if ( V_90 && V_90 < 100 ) {
if ( V_90 < 10 ) {
F_16 ( L_154 ) ;
F_211 ( V_307 , V_284 , L_155 , 1 ) ;
goto V_150;
} else
F_32 ( L_156
L_157
L_158 ) ;
}
if ( F_191 ( V_8 , V_90 ) )
goto V_150;
if ( F_155 () )
goto V_150;
atexit ( F_140 ) ;
if ( ! V_289 )
signal ( V_315 , F_139 ) ;
signal ( V_209 , F_139 ) ;
signal ( V_316 , F_139 ) ;
signal ( V_317 , F_139 ) ;
V_96 = 0 ;
for ( V_308 = 0 ; V_289 || V_308 < V_131 ; V_308 ++ ) {
if ( V_131 != 1 && V_62 > 0 )
fprintf ( V_63 , L_159 ,
V_308 + 1 ) ;
V_96 = F_84 ( V_88 , V_89 ) ;
if ( V_289 && V_96 != - 1 ) {
F_36 ( NULL , V_88 , V_89 ) ;
F_2 () ;
}
}
if ( ! V_289 && V_96 != - 1 && ! V_90 )
F_36 ( NULL , V_88 , V_89 ) ;
if ( V_21 ) {
int V_86 = F_70 ( & V_22 . V_23 ) ;
int V_79 = F_215 ( ( void * ) & V_22 ,
F_14 ,
& V_22 . V_80 -> V_318 . V_319 ) ;
if ( V_79 ) {
F_32 ( L_160
L_161 ) ;
}
if ( ! V_90 ) {
if ( F_35 ( V_120 . V_217 , V_320 ) )
F_16 ( L_8 ) ;
}
if ( ! V_22 . V_23 . V_24 ) {
V_22 . V_80 -> V_41 . V_321 += V_22 . V_43 ;
F_72 ( V_22 . V_80 , V_8 , V_86 , true ) ;
}
F_203 ( V_22 . V_80 ) ;
}
F_159 () ;
F_216 ( V_8 ) ;
V_150:
F_217 ( V_8 ) ;
return V_96 ;
}
