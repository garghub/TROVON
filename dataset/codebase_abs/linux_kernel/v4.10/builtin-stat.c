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
if ( F_26 ( V_45 , V_46 , V_47 , V_49 ) )
return - 1 ;
if ( V_21 ) {
if ( F_19 ( V_45 , V_46 , V_47 , V_49 ) ) {
F_16 ( L_2 ) ;
return - 1 ;
}
}
if ( V_59 > 1 ) {
fprintf ( V_13 . V_60 ,
L_3 V_61 L_4 V_61 L_4 V_61 L_5 ,
F_27 ( V_45 ) ,
V_46 ,
V_49 -> V_62 , V_49 -> V_63 , V_49 -> V_64 ) ;
}
}
}
return 0 ;
}
static void F_28 ( void )
{
struct V_9 * V_45 ;
F_29 (evsel_list, counter) {
if ( F_22 ( V_45 ) )
F_30 ( L_6 , V_45 -> V_65 ) ;
if ( F_31 ( & V_13 , V_45 ) )
F_32 ( L_7 , V_45 -> V_65 ) ;
}
}
static void F_33 ( void )
{
struct V_1 V_66 , V_67 ;
F_28 () ;
F_34 ( V_68 , & V_66 ) ;
F_1 ( & V_67 , & V_66 , & V_69 ) ;
if ( V_21 ) {
if ( F_35 ( V_67 . V_5 * V_7 + V_67 . V_6 , V_70 ) )
F_16 ( L_8 ) ;
}
F_36 ( & V_67 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_29 )
F_38 ( V_29 * V_71 ) ;
if ( ! F_7 ( & V_28 ) || V_29 )
F_39 ( V_8 ) ;
}
static void F_40 ( void )
{
if ( ! F_7 ( & V_28 ) )
F_41 ( V_8 ) ;
}
static void F_42 ( int T_5 V_36 , T_6 * V_72 ,
void * T_7 V_36 )
{
V_73 = V_72 -> V_74 . V_75 ;
}
static bool F_43 ( struct V_9 * V_45 )
{
return V_45 -> V_76 && * V_45 -> V_76 ;
}
static bool F_44 ( struct V_9 * V_45 )
{
return V_45 -> V_14 != 1 ;
}
static int F_45 ( bool V_24 )
{
struct V_9 * V_45 ;
int V_77 ;
if ( V_24 ) {
V_77 = F_46 ( NULL , V_22 . V_78 ,
F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_9 ) ;
return V_77 ;
}
}
F_29 (evsel_list, counter) {
if ( ! V_45 -> V_55 )
continue;
if ( F_43 ( V_45 ) ) {
V_77 = F_47 ( NULL , V_45 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_10 ) ;
return V_77 ;
}
}
if ( F_44 ( V_45 ) ) {
V_77 = F_48 ( NULL , V_45 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_11 ) ;
return V_77 ;
}
}
if ( V_45 -> V_79 ) {
V_77 = F_49 ( NULL , V_45 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_11 ) ;
return V_77 ;
}
}
if ( V_24 ) {
V_77 = F_50 ( NULL , V_45 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_12 ) ;
return V_77 ;
}
}
}
V_77 = F_51 ( NULL , V_8 -> V_31 ,
F_14 ,
NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_13 ) ;
return V_77 ;
}
V_77 = F_52 ( NULL , V_8 -> V_80 ,
F_14 , NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_13 ) ;
return V_77 ;
}
V_77 = F_53 ( NULL , & V_13 ,
F_14 , NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_14 ) ;
return V_77 ;
}
return 0 ;
}
static int F_54 ( struct V_9 * V_45 ,
struct V_81 * V_80 ,
struct V_82 * V_31 )
{
int V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < V_80 -> V_83 ; V_46 ++ ) {
for ( V_47 = 0 ; V_47 < V_31 -> V_83 ; V_47 ++ ) {
int V_84 = F_55 ( V_45 , V_46 , V_47 ) ;
if ( F_56 ( V_8 , V_45 ,
V_46 , V_47 , V_84 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_9 * V_45 )
{
struct V_81 * V_80 = V_45 -> V_80 ;
struct V_82 * V_31 = V_45 -> V_31 ;
if ( F_58 ( V_45 , V_80 -> V_83 , V_31 -> V_83 ) )
return - V_85 ;
return F_54 ( V_45 , V_80 , V_31 ) ;
}
static int F_59 ( int V_86 , const char * * V_87 )
{
int V_88 = V_13 . V_88 ;
char V_89 [ 512 ] ;
unsigned long long V_90 , V_91 ;
struct V_9 * V_45 ;
struct V_1 V_66 ;
T_8 V_92 ;
int V_93 = 0 ;
const bool V_94 = ( V_86 > 0 ) ;
bool V_24 = V_21 ? V_22 . V_23 . V_24 : false ;
struct V_95 * V_96 ;
if ( V_88 ) {
V_66 . V_5 = V_88 / V_71 ;
V_66 . V_6 = ( V_88 % V_71 ) * V_97 ;
} else {
V_66 . V_5 = 1 ;
V_66 . V_6 = 0 ;
}
if ( V_94 ) {
if ( F_60 ( V_8 , & V_28 , V_87 , V_24 ,
F_42 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_98 = V_8 -> V_99 . V_100 ;
}
if ( V_101 )
F_61 ( V_8 ) ;
F_29 (evsel_list, counter) {
V_102:
if ( F_5 ( V_45 ) < 0 ) {
if ( V_103 == V_104 || V_103 == V_105 ||
V_103 == V_56 || V_103 == V_106 ||
V_103 == V_107 ) {
if ( V_59 )
F_62 ( L_16 ,
F_27 ( V_45 ) ) ;
V_45 -> V_55 = false ;
if ( ( V_45 -> V_108 != V_45 ) ||
! ( V_45 -> V_108 -> V_109 > 1 ) )
continue;
} else if ( F_63 ( V_45 , V_103 , V_89 , sizeof( V_89 ) ) ) {
if ( V_59 )
F_62 ( L_17 , V_89 ) ;
goto V_102;
}
F_64 ( V_45 , & V_28 ,
V_103 , V_89 , sizeof( V_89 ) ) ;
F_65 ( L_17 , V_89 ) ;
if ( V_98 != - 1 )
F_66 ( V_98 , V_110 ) ;
return - 1 ;
}
V_45 -> V_55 = true ;
V_92 = strlen ( V_45 -> V_76 ) ;
if ( V_92 > V_111 )
V_111 = V_92 ;
if ( V_21 && F_57 ( V_45 ) )
return - 1 ;
}
if ( F_67 ( V_8 , & V_45 ) ) {
error ( L_18 ,
V_45 -> V_112 , F_27 ( V_45 ) , V_103 ,
F_68 ( V_103 , V_89 , sizeof( V_89 ) ) ) ;
return - 1 ;
}
if ( F_69 ( V_8 , & V_45 , & V_96 ) ) {
error ( L_19 ,
V_96 -> V_62 . V_113 , F_27 ( V_45 ) , V_103 ,
F_68 ( V_103 , V_89 , sizeof( V_89 ) ) ) ;
return - 1 ;
}
if ( V_21 ) {
int V_77 , V_84 = F_70 ( & V_22 . V_23 ) ;
if ( V_24 ) {
V_77 = F_71 ( F_70 ( & V_22 . V_23 ) ) ;
} else {
V_77 = F_72 ( V_22 . V_78 , V_8 ,
V_84 , false ) ;
}
if ( V_77 < 0 )
return V_77 ;
V_77 = F_45 ( V_24 ) ;
if ( V_77 < 0 )
return V_77 ;
}
V_90 = F_73 () ;
F_34 ( V_68 , & V_69 ) ;
if ( V_94 ) {
F_74 ( V_8 ) ;
F_37 () ;
if ( V_88 ) {
while ( ! F_75 ( V_98 , & V_93 , V_114 ) ) {
F_76 ( & V_66 , NULL ) ;
F_33 () ;
}
}
F_77 ( & V_93 ) ;
if ( V_73 ) {
const char * V_115 = F_68 ( V_73 , V_89 , sizeof( V_89 ) ) ;
F_16 ( L_20 , V_115 ) ;
return - 1 ;
}
if ( F_78 ( V_93 ) )
F_79 ( F_80 ( V_93 ) , V_87 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_116 ) {
F_76 ( & V_66 , NULL ) ;
if ( V_88 )
F_33 () ;
}
}
F_40 () ;
V_91 = F_73 () ;
F_81 ( & V_117 , V_91 - V_90 ) ;
F_28 () ;
F_82 ( V_8 ) ;
return F_83 ( V_93 ) ;
}
static int F_84 ( int V_86 , const char * * V_87 )
{
int V_118 ;
if ( V_119 ) {
V_118 = system ( V_119 ) ;
if ( V_118 )
return V_118 ;
}
if ( V_120 )
F_85 () ;
V_118 = F_59 ( V_86 , V_87 ) ;
if ( V_118 )
return V_118 ;
if ( V_121 ) {
V_118 = system ( V_121 ) ;
if ( V_118 )
return V_118 ;
}
return V_118 ;
}
static void F_86 ( T_3 V_64 , T_3 V_63 )
{
if ( V_122 ) {
fprintf ( V_13 . V_60 , L_21 V_61 L_22 ,
V_123 ,
V_64 ,
V_123 ,
V_63 ? 100.0 * V_64 / V_63 : 100.0 ) ;
} else if ( V_64 != V_63 ) {
fprintf ( V_13 . V_60 , L_23 , 100.0 * V_64 / V_63 ) ;
}
}
static void F_87 ( double V_124 , double V_125 )
{
double V_126 = F_88 ( V_124 , V_125 ) ;
if ( V_122 )
fprintf ( V_13 . V_60 , L_24 , V_123 , V_126 ) ;
else if ( V_126 )
fprintf ( V_13 . V_60 , L_25 , V_126 ) ;
}
static void F_89 ( struct V_9 * V_10 , double V_125 )
{
struct V_127 * V_128 ;
if ( V_129 == 1 )
return;
V_128 = V_10 -> V_130 ;
F_87 ( F_90 ( & V_128 -> V_131 [ 0 ] ) , V_125 ) ;
}
static void F_91 ( struct V_9 * V_10 , int V_52 , int V_83 )
{
switch ( V_13 . V_132 ) {
case V_133 :
fprintf ( V_13 . V_60 , L_26 ,
F_92 ( V_52 ) ,
V_122 ? 0 : - 8 ,
F_93 ( V_52 ) ,
V_123 ,
V_122 ? 0 : 4 ,
V_83 ,
V_123 ) ;
break;
case V_134 :
fprintf ( V_13 . V_60 , L_27 ,
V_122 ? 0 : - 5 ,
V_52 ,
V_123 ,
V_122 ? 0 : 4 ,
V_83 ,
V_123 ) ;
break;
case V_135 :
fprintf ( V_13 . V_60 , L_28 ,
V_122 ? 0 : - 4 ,
F_10 ( V_10 ) -> V_136 [ V_52 ] , V_123 ) ;
break;
case V_137 :
fprintf ( V_13 . V_60 , L_29 ,
V_122 ? 0 : 16 ,
F_94 ( V_10 -> V_31 , V_52 ) ,
V_122 ? 0 : - 8 ,
F_95 ( V_10 -> V_31 , V_52 ) ,
V_123 ) ;
break;
case V_138 :
case V_139 :
default:
break;
}
}
static void F_96 ( void * V_140 )
{
struct V_141 * V_142 = V_140 ;
V_142 -> V_143 = true ;
}
static void F_97 ( struct V_141 * V_142 )
{
fputc ( '\n' , V_142 -> V_144 ) ;
fputs ( V_142 -> V_145 , V_142 -> V_144 ) ;
F_91 ( V_142 -> V_10 , V_142 -> V_52 , V_142 -> V_83 ) ;
if ( V_13 . V_132 == V_135 )
fprintf ( V_142 -> V_144 , L_30 ) ;
fprintf ( V_142 -> V_144 , L_31 ) ;
}
static void F_98 ( void * V_140 , const char * V_146 , const char * V_147 ,
const char * V_76 , double V_62 )
{
struct V_141 * V_142 = V_140 ;
T_9 * V_148 = V_142 -> V_144 ;
int V_149 ;
bool V_143 = V_142 -> V_143 ;
V_142 -> V_143 = false ;
if ( V_76 == NULL || V_147 == NULL ) {
fprintf ( V_148 , L_32 , V_150 , L_33 ) ;
return;
}
if ( V_143 )
F_97 ( V_142 ) ;
V_149 = fprintf ( V_148 , L_34 ) ;
if ( V_146 )
V_149 += F_99 ( V_148 , V_146 , V_147 , V_62 ) ;
else
V_149 += fprintf ( V_148 , V_147 , V_62 ) ;
fprintf ( V_148 , L_35 , V_150 - V_149 - 1 , V_76 ) ;
}
static void F_100 ( void * V_140 )
{
struct V_141 * V_142 = V_140 ;
int V_151 ;
fputc ( '\n' , V_142 -> V_144 ) ;
if ( V_142 -> V_145 )
fprintf ( V_142 -> V_144 , L_36 , V_142 -> V_145 , V_123 ) ;
F_91 ( V_142 -> V_10 , V_142 -> V_52 , V_142 -> V_83 ) ;
for ( V_151 = 0 ; V_151 < V_142 -> V_152 ; V_151 ++ )
fputs ( V_123 , V_142 -> V_144 ) ;
}
static void F_101 ( void * V_140 ,
const char * V_146 V_36 ,
const char * V_147 , const char * V_76 , double V_62 )
{
struct V_141 * V_142 = V_140 ;
T_9 * V_148 = V_142 -> V_144 ;
char V_153 [ 64 ] , * V_154 , * V_155 ;
if ( V_76 == NULL || V_147 == NULL ) {
fprintf ( V_148 , L_37 , V_123 , V_123 , V_123 , V_123 ) ;
return;
}
snprintf ( V_153 , sizeof( V_153 ) , V_147 , V_62 ) ;
V_154 = V_153 ;
while ( isspace ( * V_154 ) )
V_154 ++ ;
V_155 = V_154 ;
while ( isdigit ( * V_155 ) || * V_155 == '.' )
V_155 ++ ;
* V_155 = 0 ;
while ( isspace ( * V_76 ) )
V_76 ++ ;
fprintf ( V_148 , L_37 , V_123 , V_154 , V_123 , V_76 ) ;
}
static bool F_102 ( const char * V_76 )
{
if ( ! V_76 )
return false ;
if ( strstr ( V_76 , L_38 ) ||
strstr ( V_76 , L_39 ) ||
strstr ( V_76 , L_40 ) ||
strstr ( V_76 , L_41 ) )
return false ;
return true ;
}
static const char * F_103 ( char * V_153 , struct V_9 * V_10 ,
const char * V_76 )
{
if ( ! strncmp ( V_76 , L_42 , 6 ) ) {
snprintf ( V_153 , 1024 , L_43 , F_27 ( V_10 ) ,
V_76 ) ;
return V_153 ;
}
return V_76 ;
}
static void F_104 ( void * V_140 , const char * V_146 , const char * V_147 ,
const char * V_76 , double V_62 )
{
struct V_141 * V_142 = V_140 ;
T_9 * V_148 = V_142 -> V_144 ;
int V_149 ;
char V_153 [ 1024 ] ;
unsigned V_156 = V_157 ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_153 , V_142 -> V_10 , V_76 ) ;
if ( V_146 )
V_149 = F_99 ( V_148 , V_146 , V_147 , V_62 ) ;
else
V_149 = fprintf ( V_148 , V_147 , V_62 ) ;
if ( V_149 > V_157 )
V_149 = V_157 ;
if ( V_156 < strlen ( V_76 ) )
V_156 = strlen ( V_76 ) + 1 ;
fprintf ( V_148 , L_44 , V_156 - V_149 , L_33 ) ;
}
static void F_105 ( void * V_140 , const char * V_146 V_36 ,
const char * V_147 ,
const char * V_76 , double V_62 )
{
struct V_141 * V_142 = V_140 ;
T_9 * V_148 = V_142 -> V_144 ;
char V_153 [ 64 ] , * V_154 , * V_155 ;
char V_158 [ 1024 ] ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_158 , V_142 -> V_10 , V_76 ) ;
snprintf ( V_153 , sizeof V_153 , V_147 , V_62 ) ;
V_154 = V_153 ;
while ( isspace ( * V_154 ) )
V_154 ++ ;
V_155 = V_154 ;
while ( isdigit ( * V_155 ) || * V_155 == '.' )
V_155 ++ ;
* V_155 = 0 ;
fprintf ( V_148 , L_36 , V_154 , V_123 ) ;
}
static void F_106 ( void * V_140 V_36 )
{
}
static void F_107 ( void * V_140 , const char * V_146 V_36 ,
const char * V_147 V_36 ,
const char * V_76 , double V_62 V_36 )
{
struct V_141 * V_142 = V_140 ;
char V_158 [ 1024 ] ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_158 , V_142 -> V_10 , V_76 ) ;
if ( V_122 )
fprintf ( V_142 -> V_144 , L_36 , V_76 , V_123 ) ;
else
fprintf ( V_142 -> V_144 , L_45 , V_157 , V_76 ) ;
}
static void F_108 ( int V_52 , int V_83 , struct V_9 * V_10 , double V_125 )
{
T_9 * V_60 = V_13 . V_60 ;
double V_159 = V_125 / V_97 ;
const char * V_160 , * V_161 ;
char V_65 [ 25 ] ;
V_160 = V_122 ? L_46 : L_47 ;
V_161 = V_122 ? L_48 : L_49 ;
F_91 ( V_10 , V_52 , V_83 ) ;
F_109 ( V_65 , sizeof( V_65 ) , L_36 ,
F_27 ( V_10 ) , V_122 ? L_33 : L_50 ) ;
fprintf ( V_60 , V_160 , V_159 , V_123 ) ;
if ( V_122 )
fprintf ( V_60 , L_36 , V_10 -> V_76 , V_123 ) ;
else
fprintf ( V_60 , L_51 , V_111 , V_10 -> V_76 , V_123 ) ;
fprintf ( V_60 , V_161 , V_65 ) ;
if ( V_10 -> V_162 )
fprintf ( V_60 , L_36 , V_123 , V_10 -> V_162 -> V_65 ) ;
}
static int F_110 ( struct V_9 * V_10 , int V_52 )
{
int V_151 ;
if ( ! V_163 )
return 0 ;
if ( V_13 . V_132 == V_135 )
return V_52 ;
if ( V_13 . V_132 == V_138 )
return 0 ;
for ( V_151 = 0 ; V_151 < F_24 ( V_10 ) ; V_151 ++ ) {
int V_164 = F_10 ( V_10 ) -> V_136 [ V_151 ] ;
if ( V_163 ( V_8 -> V_80 , V_164 ) == V_52 )
return V_164 ;
}
return 0 ;
}
static void F_111 ( int V_52 , int V_83 , struct V_9 * V_10 , double V_125 )
{
T_9 * V_60 = V_13 . V_60 ;
double V_165 = V_10 -> V_14 ;
const char * V_147 ;
if ( V_122 ) {
V_147 = floor ( V_165 ) != V_165 ? L_52 : L_53 ;
} else {
if ( V_166 )
V_147 = floor ( V_165 ) != V_165 ? L_54 : L_55 ;
else
V_147 = floor ( V_165 ) != V_165 ? L_56 : L_57 ;
}
F_91 ( V_10 , V_52 , V_83 ) ;
fprintf ( V_60 , V_147 , V_125 , V_123 ) ;
if ( V_10 -> V_76 )
fprintf ( V_60 , L_51 ,
V_122 ? 0 : V_111 ,
V_10 -> V_76 , V_123 ) ;
fprintf ( V_60 , L_32 , V_122 ? 0 : 25 , F_27 ( V_10 ) ) ;
if ( V_10 -> V_162 )
fprintf ( V_60 , L_36 , V_123 , V_10 -> V_162 -> V_65 ) ;
}
static void F_112 ( int V_52 , int V_83 , struct V_9 * V_45 , double V_167 ,
char * V_145 , T_3 V_64 , T_3 V_63 , double V_168 )
{
struct V_169 V_148 ;
struct V_141 V_142 = {
. V_144 = V_13 . V_60 ,
. V_145 = V_145 ? V_145 : L_33 ,
. V_52 = V_52 ,
. V_83 = V_83 ,
. V_10 = V_45 ,
} ;
T_10 V_170 = F_98 ;
void (* F_113)( void * );
if ( V_171 ) {
F_113 = F_106 ;
if ( V_122 )
V_170 = F_105 ;
else
V_170 = F_104 ;
} else
F_113 = F_96 ;
if ( V_122 && ! V_171 ) {
static int V_172 [] = {
[ V_138 ] = 0 ,
[ V_137 ] = 1 ,
[ V_135 ] = 1 ,
[ V_134 ] = 2 ,
[ V_133 ] = 2 ,
} ;
V_170 = F_101 ;
F_113 = F_100 ;
V_142 . V_152 = 3 ;
V_142 . V_152 += V_172 [ V_13 . V_132 ] ;
if ( V_45 -> V_162 )
V_142 . V_152 ++ ;
}
if ( V_64 == 0 || V_63 == 0 || V_45 -> V_58 -> V_173 == - 1 ) {
if ( V_171 ) {
V_170 ( & V_142 , NULL , L_33 , L_33 , 0 ) ;
return;
}
F_91 ( V_45 , V_52 , V_83 ) ;
fprintf ( V_13 . V_60 , L_58 ,
V_122 ? 0 : 18 ,
V_45 -> V_55 ? V_174 : V_175 ,
V_123 ) ;
fprintf ( V_13 . V_60 , L_51 ,
V_122 ? 0 : V_111 ,
V_45 -> V_76 , V_123 ) ;
fprintf ( V_13 . V_60 , L_44 ,
V_122 ? 0 : - 25 ,
F_27 ( V_45 ) ) ;
if ( V_45 -> V_162 )
fprintf ( V_13 . V_60 , L_36 ,
V_123 , V_45 -> V_162 -> V_65 ) ;
if ( ! V_122 )
V_170 ( & V_142 , NULL , NULL , L_33 , 0 ) ;
F_89 ( V_45 , V_168 ) ;
F_86 ( V_64 , V_63 ) ;
if ( V_122 )
V_170 ( & V_142 , NULL , NULL , L_33 , 0 ) ;
return;
}
if ( V_171 )
;
else if ( F_12 ( V_45 ) )
F_108 ( V_52 , V_83 , V_45 , V_167 ) ;
else
F_111 ( V_52 , V_83 , V_45 , V_167 ) ;
V_148 . V_176 = V_170 ;
V_148 . V_177 = F_113 ;
V_148 . V_140 = & V_142 ;
if ( V_122 && ! V_171 ) {
F_89 ( V_45 , V_168 ) ;
F_86 ( V_64 , V_63 ) ;
}
F_114 ( V_45 , V_167 ,
F_110 ( V_45 , V_52 ) ,
& V_148 ) ;
if ( ! V_122 && ! V_171 ) {
F_89 ( V_45 , V_168 ) ;
F_86 ( V_64 , V_63 ) ;
}
}
static void F_115 ( void )
{
int V_46 , V_178 , V_52 , V_179 ;
T_3 V_62 ;
struct V_9 * V_45 ;
for ( V_179 = 0 ; V_179 < V_180 -> V_83 ; V_179 ++ ) {
V_52 = V_180 -> V_136 [ V_179 ] ;
F_29 (evsel_list, counter) {
V_62 = 0 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_178 = V_163 ( V_8 -> V_80 , V_46 ) ;
if ( V_178 != V_52 )
continue;
V_62 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
}
V_62 = V_62 * V_45 -> V_14 ;
F_116 ( V_45 , & V_62 ,
F_110 ( V_45 , V_52 ) ) ;
}
}
}
static void F_117 ( char * V_145 )
{
T_9 * V_60 = V_13 . V_60 ;
struct V_9 * V_45 ;
int V_46 , V_179 , V_178 , V_52 , V_83 ;
double V_167 ;
T_3 V_63 , V_64 , V_62 ;
bool V_181 ;
if ( ! ( V_180 || V_163 ) )
return;
F_115 () ;
for ( V_179 = 0 ; V_179 < V_180 -> V_83 ; V_179 ++ ) {
if ( V_145 && V_171 )
fprintf ( V_60 , L_48 , V_145 ) ;
V_52 = V_180 -> V_136 [ V_179 ] ;
V_181 = true ;
F_29 (evsel_list, counter) {
V_62 = V_63 = V_64 = 0 ;
V_83 = 0 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_178 = V_163 ( F_10 ( V_45 ) , V_46 ) ;
if ( V_178 != V_52 )
continue;
V_62 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
V_83 ++ ;
}
if ( V_181 && V_171 ) {
V_181 = false ;
F_91 ( V_45 , V_52 , V_83 ) ;
}
if ( V_145 && ! V_171 )
fprintf ( V_60 , L_48 , V_145 ) ;
V_167 = V_62 * V_45 -> V_14 ;
F_112 ( V_52 , V_83 , V_45 , V_167 , V_145 , V_64 , V_63 , 1.0 ) ;
if ( ! V_171 )
fputc ( '\n' , V_60 ) ;
}
if ( V_171 )
fputc ( '\n' , V_60 ) ;
}
}
static void F_118 ( struct V_9 * V_45 , char * V_145 )
{
T_9 * V_60 = V_13 . V_60 ;
int V_53 = F_23 ( V_45 -> V_31 ) ;
int V_54 = F_119 ( V_45 -> V_80 ) ;
int V_46 , V_47 ;
double V_167 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
T_3 V_63 = 0 , V_64 = 0 , V_62 = 0 ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
V_62 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_62 ;
V_63 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_63 ;
V_64 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_64 ;
}
if ( V_145 )
fprintf ( V_60 , L_48 , V_145 ) ;
V_167 = V_62 * V_45 -> V_14 ;
F_112 ( V_47 , 0 , V_45 , V_167 , V_145 , V_64 , V_63 , 1.0 ) ;
fputc ( '\n' , V_60 ) ;
}
}
static void F_120 ( struct V_9 * V_45 , char * V_145 )
{
T_9 * V_60 = V_13 . V_60 ;
struct V_127 * V_128 = V_45 -> V_130 ;
double V_125 = F_121 ( & V_128 -> V_131 [ 0 ] ) ;
double V_167 ;
double V_182 , V_183 ;
V_182 = F_121 ( & V_128 -> V_131 [ 1 ] ) ;
V_183 = F_121 ( & V_128 -> V_131 [ 2 ] ) ;
if ( V_145 && ! V_171 )
fprintf ( V_60 , L_48 , V_145 ) ;
V_167 = V_125 * V_45 -> V_14 ;
F_112 ( - 1 , 0 , V_45 , V_167 , V_145 , V_183 , V_182 , V_125 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_5 ) ;
}
static void F_122 ( struct V_9 * V_45 , char * V_145 )
{
T_9 * V_60 = V_13 . V_60 ;
T_3 V_63 , V_64 , V_62 ;
double V_167 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_62 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
if ( V_145 )
fprintf ( V_60 , L_48 , V_145 ) ;
V_167 = V_62 * V_45 -> V_14 ;
F_112 ( V_46 , 0 , V_45 , V_167 , V_145 , V_64 , V_63 , 1.0 ) ;
fputc ( '\n' , V_60 ) ;
}
}
static void F_123 ( char * V_145 )
{
int V_46 ;
int V_184 = 0 ;
struct V_9 * V_45 ;
T_3 V_63 , V_64 , V_62 ;
double V_167 ;
V_184 = V_8 -> V_80 -> V_83 ;
for ( V_46 = 0 ; V_46 < V_184 ; V_46 ++ ) {
bool V_181 = true ;
if ( V_145 )
fputs ( V_145 , V_13 . V_60 ) ;
F_29 (evsel_list, counter) {
if ( V_181 ) {
F_91 ( V_45 , V_46 , 0 ) ;
V_181 = false ;
}
V_62 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
V_167 = V_62 * V_45 -> V_14 ;
F_112 ( V_46 , 0 , V_45 , V_167 , V_145 , V_64 , V_63 , 1.0 ) ;
}
fputc ( '\n' , V_13 . V_60 ) ;
}
}
static void F_124 ( const char * V_145 , bool V_185 )
{
struct V_169 V_148 ;
struct V_9 * V_45 ;
struct V_141 V_142 = {
. V_144 = V_13 . V_60
} ;
if ( V_145 )
fprintf ( V_13 . V_60 , L_48 , V_145 ) ;
if ( ! V_122 && ! V_185 )
fprintf ( V_13 . V_60 , L_44 ,
V_186 [ V_13 . V_132 ] , L_33 ) ;
if ( V_122 ) {
if ( V_13 . V_88 )
fputs ( L_59 , V_13 . V_60 ) ;
fputs ( V_187 [ V_13 . V_132 ] ,
V_13 . V_60 ) ;
}
F_29 (evsel_list, counter) {
V_142 . V_10 = V_45 ;
V_148 . V_140 = & V_142 ;
V_148 . V_176 = F_107 ;
V_148 . V_177 = F_106 ;
V_142 . V_10 = V_45 ;
F_114 ( V_45 , 0 ,
0 ,
& V_148 ) ;
}
fputc ( '\n' , V_13 . V_60 ) ;
}
static void F_125 ( char * V_145 , struct V_1 * V_66 )
{
T_9 * V_60 = V_13 . V_60 ;
static int V_188 ;
sprintf ( V_145 , L_60 , V_66 -> V_5 , V_66 -> V_6 , V_123 ) ;
if ( V_188 == 0 && ! V_122 ) {
switch ( V_13 . V_132 ) {
case V_134 :
fprintf ( V_60 , L_61 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_62 , V_111 , L_63 ) ;
break;
case V_133 :
fprintf ( V_60 , L_64 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_62 , V_111 , L_63 ) ;
break;
case V_135 :
fprintf ( V_60 , L_65 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_66 , V_111 , L_63 ) ;
break;
case V_137 :
fprintf ( V_60 , L_67 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_68 , V_111 , L_63 ) ;
break;
case V_138 :
default:
fprintf ( V_60 , L_69 ) ;
if ( ! V_171 )
fprintf ( V_60 , L_62 , V_111 , L_63 ) ;
case V_139 :
break;
}
}
if ( V_188 == 0 && V_171 )
F_124 ( L_70 , true ) ;
if ( ++ V_188 == 25 )
V_188 = 0 ;
}
static void F_126 ( int V_86 , const char * * V_87 )
{
T_9 * V_60 = V_13 . V_60 ;
int V_151 ;
fflush ( stdout ) ;
if ( ! V_122 ) {
fprintf ( V_60 , L_5 ) ;
fprintf ( V_60 , L_71 ) ;
if ( V_28 . V_57 )
fprintf ( V_60 , L_72 ) ;
else if ( V_28 . V_189 )
fprintf ( V_60 , L_73 , V_28 . V_189 ) ;
else if ( ! F_127 ( & V_28 ) ) {
fprintf ( V_60 , L_74 , V_87 ? V_87 [ 0 ] : L_75 ) ;
for ( V_151 = 1 ; V_87 && ( V_151 < V_86 ) ; V_151 ++ )
fprintf ( V_60 , L_76 , V_87 [ V_151 ] ) ;
} else if ( V_28 . V_100 )
fprintf ( V_60 , L_77 , V_28 . V_100 ) ;
else
fprintf ( V_60 , L_78 , V_28 . V_190 ) ;
fprintf ( V_60 , L_79 ) ;
if ( V_129 > 1 )
fprintf ( V_60 , L_80 , V_129 ) ;
fprintf ( V_60 , L_81 ) ;
}
}
static void F_128 ( void )
{
T_9 * V_60 = V_13 . V_60 ;
if ( ! V_191 )
fprintf ( V_60 , L_5 ) ;
fprintf ( V_60 , L_82 ,
F_121 ( & V_117 ) / V_7 ) ;
if ( V_129 > 1 ) {
fprintf ( V_60 , L_83 ) ;
F_87 ( F_90 ( & V_117 ) ,
F_121 ( & V_117 ) ) ;
}
fprintf ( V_60 , L_84 ) ;
}
static void F_36 ( struct V_1 * V_66 , int V_86 , const char * * V_87 )
{
int V_88 = V_13 . V_88 ;
struct V_9 * V_45 ;
char V_153 [ 64 ] , * V_145 = NULL ;
if ( V_21 && V_22 . V_23 . V_24 )
return;
if ( V_88 )
F_125 ( V_145 = V_153 , V_66 ) ;
else
F_126 ( V_86 , V_87 ) ;
if ( V_171 ) {
static int V_192 ;
if ( V_192 == 0 && ! V_88 )
F_124 ( V_145 , false ) ;
if ( V_192 ++ == 25 )
V_192 = 0 ;
if ( V_13 . V_132 == V_138 && V_145 )
fprintf ( V_13 . V_60 , L_48 , V_145 ) ;
}
switch ( V_13 . V_132 ) {
case V_133 :
case V_134 :
F_117 ( V_145 ) ;
break;
case V_137 :
F_29 (evsel_list, counter)
F_118 ( V_45 , V_145 ) ;
break;
case V_138 :
F_29 (evsel_list, counter)
F_120 ( V_45 , V_145 ) ;
if ( V_171 )
fputc ( '\n' , V_13 . V_60 ) ;
break;
case V_135 :
if ( V_171 )
F_123 ( V_145 ) ;
else {
F_29 (evsel_list, counter)
F_122 ( V_45 , V_145 ) ;
}
break;
case V_139 :
default:
break;
}
if ( ! V_88 && ! V_122 )
F_128 () ;
fflush ( V_13 . V_60 ) ;
}
static void F_129 ( int T_5 )
{
if ( ( V_98 == - 1 ) || V_13 . V_88 )
V_116 = 1 ;
V_193 = T_5 ;
V_98 = - 1 ;
}
static void F_130 ( void )
{
T_11 V_194 , V_195 ;
F_131 ( & V_194 ) ;
F_132 ( & V_194 , V_196 ) ;
F_133 ( V_197 , & V_194 , & V_195 ) ;
if ( V_98 != - 1 )
F_66 ( V_98 , V_110 ) ;
F_133 ( V_198 , & V_195 , NULL ) ;
if ( V_193 == - 1 )
return;
signal ( V_193 , V_199 ) ;
F_66 ( F_134 () , V_193 ) ;
}
static int F_135 ( const struct V_200 * T_12 V_36 ,
const char * V_179 V_36 , int V_201 )
{
V_202 = V_201 ? 0 : 1 ;
return 0 ;
}
static int F_136 ( const struct V_200 * T_12 V_36 ,
const char * V_179 V_36 , int V_201 )
{
V_203 = true ;
V_171 = ! V_201 ;
return 0 ;
}
static int F_137 ( struct V_81 * V_136 , int V_46 )
{
return F_138 ( V_136 , V_46 , NULL ) ;
}
static int F_139 ( struct V_81 * V_136 , int V_46 )
{
return F_140 ( V_136 , V_46 , NULL ) ;
}
static int F_141 ( struct V_81 * V_136 )
{
int V_151 , V_204 = - 1 ;
for ( V_151 = 0 ; V_151 < V_136 -> V_83 ; V_151 ++ ) {
if ( V_136 -> V_136 [ V_151 ] > V_204 )
V_204 = V_136 -> V_136 [ V_151 ] ;
}
return V_204 ;
}
static int F_142 ( T_13 V_205 , struct V_81 * V_136 , int V_206 )
{
int V_46 ;
if ( V_206 >= V_136 -> V_83 )
return - 1 ;
V_46 = V_136 -> V_136 [ V_206 ] ;
if ( V_207 -> V_136 [ V_46 ] == - 1 )
V_207 -> V_136 [ V_46 ] = V_205 ( V_136 , V_206 ) ;
return V_207 -> V_136 [ V_46 ] ;
}
static int F_143 ( struct V_81 * V_136 , int V_206 )
{
return F_142 ( F_137 , V_136 , V_206 ) ;
}
static int F_144 ( struct V_81 * V_136 , int V_206 )
{
return F_142 ( F_139 , V_136 , V_206 ) ;
}
static int F_145 ( void )
{
int V_83 ;
switch ( V_13 . V_132 ) {
case V_134 :
if ( F_146 ( V_8 -> V_80 , & V_180 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_163 = F_143 ;
break;
case V_133 :
if ( F_147 ( V_8 -> V_80 , & V_180 ) ) {
perror ( L_86 ) ;
return - 1 ;
}
V_163 = F_144 ;
break;
case V_135 :
case V_138 :
case V_137 :
case V_139 :
default:
break;
}
V_83 = F_141 ( V_8 -> V_80 ) ;
V_207 = F_148 ( V_83 + 1 ) ;
return V_207 ? 0 : - V_85 ;
}
static void F_149 ( void )
{
F_150 ( V_180 ) ;
F_150 ( V_207 ) ;
V_180 = NULL ;
V_207 = NULL ;
}
static inline int F_151 ( struct V_208 * V_209 , struct V_81 * V_136 , int V_206 )
{
int V_46 ;
if ( V_206 > V_136 -> V_83 )
return - 1 ;
V_46 = V_136 -> V_136 [ V_206 ] ;
if ( V_46 >= V_209 -> V_210 )
return - 1 ;
return V_46 ;
}
static int F_152 ( struct V_81 * V_136 , int V_206 , void * V_211 )
{
struct V_208 * V_209 = V_211 ;
int V_46 = F_151 ( V_209 , V_136 , V_206 ) ;
return V_46 == - 1 ? - 1 : V_209 -> V_46 [ V_46 ] . V_212 ;
}
static int F_153 ( struct V_81 * V_136 , int V_206 , void * V_211 )
{
struct V_208 * V_209 = V_211 ;
int V_213 = - 1 , V_46 = F_151 ( V_209 , V_136 , V_206 ) ;
if ( V_46 != - 1 ) {
int V_212 = V_209 -> V_46 [ V_46 ] . V_212 ;
V_213 = ( V_212 << 16 ) | ( V_209 -> V_46 [ V_46 ] . V_214 & 0xffff ) ;
}
return V_213 ;
}
static int F_154 ( struct V_208 * V_209 , struct V_81 * V_80 ,
struct V_81 * * V_215 )
{
return F_155 ( V_80 , V_215 , F_152 , V_209 ) ;
}
static int F_156 ( struct V_208 * V_209 , struct V_81 * V_80 ,
struct V_81 * * V_216 )
{
return F_155 ( V_80 , V_216 , F_153 , V_209 ) ;
}
static int F_157 ( struct V_81 * V_136 , int V_206 )
{
return F_152 ( V_136 , V_206 , & V_22 . V_78 -> V_41 . V_209 ) ;
}
static int F_158 ( struct V_81 * V_136 , int V_206 )
{
return F_153 ( V_136 , V_206 , & V_22 . V_78 -> V_41 . V_209 ) ;
}
static int F_159 ( struct V_22 * V_217 )
{
struct V_208 * V_209 = & V_217 -> V_78 -> V_41 . V_209 ;
switch ( V_13 . V_132 ) {
case V_134 :
if ( F_154 ( V_209 , V_8 -> V_80 , & V_180 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_163 = F_157 ;
break;
case V_133 :
if ( F_156 ( V_209 , V_8 -> V_80 , & V_180 ) ) {
perror ( L_86 ) ;
return - 1 ;
}
V_163 = F_158 ;
break;
case V_135 :
case V_138 :
case V_137 :
case V_139 :
default:
break;
}
return 0 ;
}
static int F_160 ( const char * * V_12 , char * * V_218 , bool V_219 )
{
int V_220 = 0 ;
int V_151 ;
int V_221 = 0 ;
char * V_179 ;
for ( V_151 = 0 ; V_12 [ V_151 ] ; V_151 ++ ) {
if ( F_161 ( L_87 , V_12 [ V_151 ] ) ) {
V_221 += strlen ( V_12 [ V_151 ] ) + 1 ;
V_12 [ V_151 - V_220 ] = V_12 [ V_151 ] ;
} else
V_220 ++ ;
}
V_12 [ V_151 - V_220 ] = NULL ;
* V_218 = malloc ( V_221 + 1 + 2 ) ;
if ( ! * V_218 )
return - 1 ;
V_179 = * V_218 ;
if ( V_151 - V_220 == 0 ) {
* V_179 = 0 ;
return 0 ;
}
if ( V_219 )
* V_179 ++ = '{' ;
for ( V_151 = 0 ; V_12 [ V_151 ] ; V_151 ++ ) {
strcpy ( V_179 , V_12 [ V_151 ] ) ;
V_179 += strlen ( V_179 ) ;
* V_179 ++ = ',' ;
}
if ( V_219 ) {
V_179 [ - 1 ] = '}' ;
* V_179 = 0 ;
} else
V_179 [ - 1 ] = 0 ;
return 0 ;
}
__weak bool F_162 ( bool * V_222 )
{
* V_222 = false ;
return false ;
}
__weak void F_163 ( void )
{
}
static int F_164 ( void )
{
int V_77 ;
struct V_11 V_223 [] = {
{ . type = V_224 , . V_225 = V_226 } ,
{ . type = V_224 , . V_225 = V_227 } ,
{ . type = V_224 , . V_225 = V_228 } ,
{ . type = V_224 , . V_225 = V_229 } ,
{ . type = V_230 , . V_225 = V_231 } ,
} ;
struct V_11 V_232 [] = {
{ . type = V_230 , . V_225 = V_233 } ,
} ;
struct V_11 V_234 [] = {
{ . type = V_230 , . V_225 = V_235 } ,
} ;
struct V_11 V_236 [] = {
{ . type = V_230 , . V_225 = V_237 } ,
{ . type = V_230 , . V_225 = V_238 } ,
{ . type = V_230 , . V_225 = V_239 } ,
} ;
struct V_11 V_240 [] = {
{ . type = V_241 ,
. V_225 =
V_242 << 0 |
( V_243 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_242 << 0 |
( V_243 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_246 << 0 |
( V_243 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_246 << 0 |
( V_243 << 8 ) |
( V_245 << 16 ) } ,
} ;
struct V_11 V_247 [] = {
{ . type = V_241 ,
. V_225 =
V_248 << 0 |
( V_243 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_248 << 0 |
( V_243 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_249 << 0 |
( V_243 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_249 << 0 |
( V_243 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_250 << 0 |
( V_243 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_250 << 0 |
( V_243 << 8 ) |
( V_245 << 16 ) } ,
} ;
struct V_11 V_251 [] = {
{ . type = V_241 ,
. V_225 =
V_242 << 0 |
( V_252 << 8 ) |
( V_244 << 16 ) } ,
{ . type = V_241 ,
. V_225 =
V_242 << 0 |
( V_252 << 8 ) |
( V_245 << 16 ) } ,
} ;
if ( V_191 )
return 0 ;
if ( V_253 ) {
if ( F_161 ( L_87 , L_88 ) &&
F_161 ( L_87 , L_89 ) )
V_77 = F_165 ( V_8 , V_254 , NULL ) ;
else
V_77 = F_165 ( V_8 , V_255 , NULL ) ;
if ( V_77 ) {
fprintf ( V_256 , L_90 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_257 ) {
char * V_218 = NULL ;
bool V_222 = false ;
if ( V_13 . V_132 != V_138 &&
V_13 . V_132 != V_133 ) {
F_16 ( L_91 ) ;
return - 1 ;
}
V_13 . V_132 = V_133 ;
if ( V_258 || ! F_8 ( & V_28 ) ) {
F_16 ( L_92 ) ;
return - 1 ;
}
if ( ! V_203 )
V_171 = true ;
if ( F_160 ( V_259 , & V_218 ,
F_162 ( & V_222 ) ) < 0 ) {
F_16 ( L_93 ) ;
return - 1 ;
}
if ( V_259 [ 0 ] && V_218 ) {
if ( V_222 )
F_163 () ;
V_77 = F_165 ( V_8 , V_218 , NULL ) ;
if ( V_77 ) {
fprintf ( V_256 ,
L_94 ,
V_218 , V_77 ) ;
free ( V_218 ) ;
return - 1 ;
}
} else {
fprintf ( V_256 , L_95 ) ;
return - 1 ;
}
free ( V_218 ) ;
}
if ( ! V_8 -> V_260 ) {
if ( F_8 ( & V_28 ) )
V_223 [ 0 ] . V_225 = V_261 ;
if ( F_166 ( V_8 , V_223 ) < 0 )
return - 1 ;
if ( F_161 ( L_87 , L_96 ) ) {
if ( F_166 ( V_8 ,
V_232 ) < 0 )
return - 1 ;
}
if ( F_161 ( L_87 , L_97 ) ) {
if ( F_166 ( V_8 ,
V_234 ) < 0 )
return - 1 ;
}
if ( F_166 ( V_8 , V_236 ) < 0 )
return - 1 ;
}
if ( V_262 < 1 )
return 0 ;
if ( F_166 ( V_8 , V_240 ) < 0 )
return - 1 ;
if ( V_262 < 2 )
return 0 ;
if ( F_166 ( V_8 , V_247 ) < 0 )
return - 1 ;
if ( V_262 < 3 )
return 0 ;
return F_166 ( V_8 , V_251 ) ;
}
static void F_167 ( struct V_263 * V_78 )
{
int V_264 ;
for ( V_264 = V_265 ; V_264 < V_266 ; V_264 ++ )
F_168 ( & V_78 -> V_41 , V_264 ) ;
F_169 ( & V_78 -> V_41 , V_267 ) ;
F_169 ( & V_78 -> V_41 , V_268 ) ;
F_169 ( & V_78 -> V_41 , V_269 ) ;
F_169 ( & V_78 -> V_41 , V_270 ) ;
}
static int F_170 ( int V_86 , const char * * V_87 )
{
struct V_263 * V_78 ;
struct V_271 * V_23 = & V_22 . V_23 ;
V_86 = F_171 ( V_86 , V_87 , V_272 , V_273 ,
V_274 ) ;
if ( V_275 )
V_23 -> V_276 = V_275 ;
if ( V_129 != 1 || V_277 ) {
F_16 ( L_98 ) ;
return - 1 ;
}
V_78 = F_172 ( V_23 , false , NULL ) ;
if ( V_78 == NULL ) {
F_16 ( L_99 ) ;
return - 1 ;
}
F_167 ( V_78 ) ;
V_78 -> V_278 = V_8 ;
V_22 . V_78 = V_78 ;
V_22 . V_279 = true ;
return V_86 ;
}
static int F_173 ( struct V_35 * T_1 V_36 ,
union V_37 * V_38 ,
struct V_263 * V_78 )
{
struct V_280 * V_281 = & V_38 -> V_281 ;
struct V_9 * V_45 ;
struct V_1 V_282 , * V_66 = NULL ;
const char * * V_87 = V_78 -> V_41 . V_209 . V_283 ;
int V_86 = V_78 -> V_41 . V_209 . V_284 ;
F_29 (evsel_list, counter)
F_31 ( & V_13 , V_45 ) ;
if ( V_281 -> type == V_285 )
F_81 ( & V_117 , V_281 -> time ) ;
if ( V_13 . V_88 && V_281 -> time ) {
V_282 . V_5 = V_281 -> time / V_7 ;
V_282 . V_6 = V_281 -> time % V_7 ;
V_66 = & V_282 ;
}
F_36 ( V_66 , V_86 , V_87 ) ;
return 0 ;
}
static
int F_174 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_263 * V_78 V_36 )
{
struct V_22 * V_217 = F_175 ( T_1 , struct V_22 , T_1 ) ;
F_176 ( & V_13 , & V_38 -> V_13 ) ;
if ( F_177 ( V_217 -> V_80 ) ) {
if ( V_217 -> V_132 != V_139 )
F_32 ( L_100 ) ;
return 0 ;
}
if ( V_217 -> V_132 != V_139 )
V_13 . V_132 = V_217 -> V_132 ;
if ( V_22 . V_23 . V_24 )
F_145 () ;
else
F_159 ( V_217 ) ;
return 0 ;
}
static int F_178 ( struct V_22 * V_217 )
{
if ( ! V_217 -> V_80 || ! V_217 -> V_31 )
return 0 ;
if ( F_179 ( V_217 -> V_286 , L_101 ) )
return - V_104 ;
F_180 ( V_8 , V_217 -> V_80 , V_217 -> V_31 ) ;
if ( F_181 ( V_8 , true ) )
return - V_85 ;
V_217 -> V_286 = true ;
return 0 ;
}
static
int F_182 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_263 * V_78 V_36 )
{
struct V_22 * V_217 = F_175 ( T_1 , struct V_22 , T_1 ) ;
if ( V_217 -> V_31 ) {
F_32 ( L_102 ) ;
return 0 ;
}
V_217 -> V_31 = F_183 ( & V_38 -> V_82 ) ;
if ( ! V_217 -> V_31 )
return - V_85 ;
return F_178 ( V_217 ) ;
}
static
int F_184 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_263 * V_78 V_36 )
{
struct V_22 * V_217 = F_175 ( T_1 , struct V_22 , T_1 ) ;
struct V_81 * V_80 ;
if ( V_217 -> V_80 ) {
F_32 ( L_103 ) ;
return 0 ;
}
V_80 = F_185 ( & V_38 -> V_81 . V_211 ) ;
if ( ! V_80 )
return - V_85 ;
V_217 -> V_80 = V_80 ;
return F_178 ( V_217 ) ;
}
static int F_186 ( int V_86 , const char * * V_87 )
{
struct V_263 * V_78 ;
const struct V_200 V_287 [] = {
F_187 ( 'i' , L_104 , & V_288 , L_105 , L_106 ) ,
F_188 ( 0 , L_107 , & V_22 . V_132 ,
L_108 , V_134 ) ,
F_188 ( 0 , L_109 , & V_22 . V_132 ,
L_110 , V_133 ) ,
F_188 ( 'A' , L_111 , & V_22 . V_132 ,
L_112 , V_135 ) ,
F_189 ()
} ;
struct V_289 V_217 ;
int V_118 ;
V_86 = F_171 ( V_86 , V_87 , V_287 , V_290 , 0 ) ;
if ( ! V_288 || ! strlen ( V_288 ) ) {
if ( ! F_190 ( V_291 , & V_217 ) && F_191 ( V_217 . V_292 ) )
V_288 = L_113 ;
else
V_288 = L_114 ;
}
V_22 . V_23 . V_276 = V_288 ;
V_22 . V_23 . V_293 = V_294 ;
V_78 = F_172 ( & V_22 . V_23 , false , & V_22 . T_1 ) ;
if ( V_78 == NULL )
return - 1 ;
V_22 . V_78 = V_78 ;
V_13 . V_60 = V_256 ;
V_8 = V_78 -> V_278 ;
V_118 = F_192 ( V_78 ) ;
if ( V_118 )
return V_118 ;
F_193 ( V_78 ) ;
return 0 ;
}
int F_194 ( int V_86 , const char * * V_87 , const char * V_145 V_36 )
{
const char * const V_295 [] = {
L_115 ,
NULL
} ;
int V_93 = - V_104 , V_296 ;
const char * V_293 ;
T_9 * V_60 = V_256 ;
unsigned int V_88 ;
const char * const V_297 [] = { L_116 , L_117 } ;
setlocale ( V_298 , L_33 ) ;
V_8 = F_195 () ;
if ( V_8 == NULL )
return - V_85 ;
F_196 () ;
V_86 = F_197 ( V_86 , V_87 , V_272 , V_297 ,
( const char * * ) V_295 ,
V_274 ) ;
F_198 () ;
if ( V_123 ) {
V_122 = true ;
if ( ! strcmp ( V_123 , L_118 ) )
V_123 = L_119 ;
} else
V_123 = V_299 ;
if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_120 , 3 ) ) {
V_86 = F_170 ( V_86 , V_87 ) ;
if ( V_86 < 0 )
return - 1 ;
} else if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_121 , 3 ) )
return F_186 ( V_86 , V_87 ) ;
V_88 = V_13 . V_88 ;
if ( ! V_21 && V_275 && strcmp ( V_275 , L_113 ) )
V_60 = NULL ;
if ( V_275 && V_300 ) {
fprintf ( V_256 , L_122 ) ;
F_199 ( V_295 , V_272 , L_123 , 1 ) ;
F_199 ( NULL , V_272 , L_124 , 0 ) ;
goto V_148;
}
if ( V_171 && V_13 . V_132 == V_137 ) {
fprintf ( V_256 , L_125 ) ;
goto V_148;
}
if ( V_171 && V_129 > 1 ) {
fprintf ( V_256 , L_126 ) ;
goto V_148;
}
if ( V_300 < 0 ) {
fprintf ( V_256 , L_127 ) ;
F_199 ( V_295 , V_272 , L_124 , 0 ) ;
goto V_148;
}
if ( ! V_60 ) {
struct V_1 V_44 ;
V_293 = V_301 ? L_128 : L_129 ;
V_60 = fopen ( V_275 , V_293 ) ;
if ( ! V_60 ) {
perror ( L_130 ) ;
return - 1 ;
}
F_34 ( V_302 , & V_44 ) ;
fprintf ( V_60 , L_131 , ctime ( & V_44 . V_5 ) ) ;
} else if ( V_300 > 0 ) {
V_293 = V_301 ? L_128 : L_129 ;
V_60 = fdopen ( V_300 , V_293 ) ;
if ( ! V_60 ) {
perror ( L_132 ) ;
return - V_103 ;
}
}
V_13 . V_60 = V_60 ;
if ( V_122 ) {
if ( V_202 == 1 ) {
fprintf ( V_256 , L_133 ) ;
F_199 ( V_295 , V_272 , L_134 , 1 ) ;
F_199 ( NULL , V_272 , L_135 , 1 ) ;
goto V_148;
} else
V_166 = false ;
} else if ( V_202 == 0 )
V_166 = false ;
if ( ! V_86 && F_7 ( & V_28 ) )
F_200 ( V_295 , V_272 ) ;
if ( V_129 < 0 ) {
F_16 ( L_136 ) ;
F_199 ( V_295 , V_272 , L_137 , 1 ) ;
goto V_148;
} else if ( V_129 == 0 ) {
V_277 = true ;
V_129 = 1 ;
}
if ( ( V_13 . V_132 == V_137 ) && ! F_127 ( & V_28 ) ) {
fprintf ( V_256 , L_138
L_139 ) ;
F_199 ( NULL , V_272 , L_140 , 1 ) ;
F_199 ( NULL , V_272 , L_141 , 1 ) ;
goto V_148;
}
if ( ( ( V_13 . V_132 != V_138 &&
V_13 . V_132 != V_137 ) || V_258 ) &&
! F_8 ( & V_28 ) ) {
fprintf ( V_256 , L_142
L_143 ) ;
F_199 ( V_295 , V_272 , L_144 , 1 ) ;
F_199 ( NULL , V_272 , L_145 , 1 ) ;
F_199 ( NULL , V_272 , L_128 , 1 ) ;
goto V_148;
}
if ( F_164 () )
goto V_148;
F_201 ( & V_28 ) ;
if ( F_202 ( V_8 , & V_28 ) < 0 ) {
if ( F_127 ( & V_28 ) ) {
F_16 ( L_146 ) ;
F_199 ( V_295 , V_272 , L_140 , 1 ) ;
F_199 ( NULL , V_272 , L_141 , 1 ) ;
} else if ( F_8 ( & V_28 ) ) {
perror ( L_147 ) ;
F_199 ( V_295 , V_272 , L_148 , 1 ) ;
F_199 ( NULL , V_272 , L_128 , 1 ) ;
}
goto V_148;
}
if ( V_13 . V_132 == V_137 )
F_203 ( V_8 -> V_31 ) ;
if ( V_88 && V_88 < 100 ) {
if ( V_88 < 10 ) {
F_16 ( L_149 ) ;
F_199 ( V_295 , V_272 , L_150 , 1 ) ;
goto V_148;
} else
F_32 ( L_151
L_152
L_153 ) ;
}
if ( F_181 ( V_8 , V_88 ) )
goto V_148;
if ( F_145 () )
goto V_148;
atexit ( F_130 ) ;
if ( ! V_277 )
signal ( V_303 , F_129 ) ;
signal ( V_196 , F_129 ) ;
signal ( V_304 , F_129 ) ;
signal ( V_305 , F_129 ) ;
V_93 = 0 ;
for ( V_296 = 0 ; V_277 || V_296 < V_129 ; V_296 ++ ) {
if ( V_129 != 1 && V_59 )
fprintf ( V_60 , L_154 ,
V_296 + 1 ) ;
V_93 = F_84 ( V_86 , V_87 ) ;
if ( V_277 && V_93 != - 1 ) {
F_36 ( NULL , V_86 , V_87 ) ;
F_2 () ;
}
}
if ( ! V_277 && V_93 != - 1 && ! V_88 )
F_36 ( NULL , V_86 , V_87 ) ;
if ( V_21 ) {
int V_84 = F_70 ( & V_22 . V_23 ) ;
int V_77 = F_204 ( ( void * ) & V_22 ,
F_14 ,
& V_22 . V_78 -> V_306 . V_307 ) ;
if ( V_77 ) {
F_32 ( L_155
L_156 ) ;
}
if ( ! V_88 ) {
if ( F_35 ( V_117 . V_204 , V_308 ) )
F_16 ( L_8 ) ;
}
if ( ! V_22 . V_23 . V_24 ) {
V_22 . V_78 -> V_41 . V_309 += V_22 . V_43 ;
F_72 ( V_22 . V_78 , V_8 , V_84 , true ) ;
}
F_193 ( V_22 . V_78 ) ;
}
F_149 () ;
F_205 ( V_8 ) ;
V_148:
F_206 ( V_8 ) ;
return V_93 ;
}
