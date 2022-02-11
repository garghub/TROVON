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
char V_89 [ V_90 ] ;
unsigned long long V_91 , V_92 ;
struct V_9 * V_45 ;
struct V_1 V_66 ;
T_8 V_93 ;
int V_94 = 0 ;
const bool V_95 = ( V_86 > 0 ) ;
bool V_24 = V_21 ? V_22 . V_23 . V_24 : false ;
struct V_96 * V_97 ;
if ( V_88 ) {
V_66 . V_5 = V_88 / V_71 ;
V_66 . V_6 = ( V_88 % V_71 ) * V_98 ;
} else {
V_66 . V_5 = 1 ;
V_66 . V_6 = 0 ;
}
if ( V_95 ) {
if ( F_60 ( V_8 , & V_28 , V_87 , V_24 ,
F_42 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_99 = V_8 -> V_100 . V_101 ;
}
if ( V_102 )
F_61 ( V_8 ) ;
F_29 (evsel_list, counter) {
V_103:
if ( F_5 ( V_45 ) < 0 ) {
if ( V_104 == V_105 || V_104 == V_106 ||
V_104 == V_56 || V_104 == V_107 ||
V_104 == V_108 ) {
if ( V_59 > 0 )
F_62 ( L_16 ,
F_27 ( V_45 ) ) ;
V_45 -> V_55 = false ;
if ( ( V_45 -> V_109 != V_45 ) ||
! ( V_45 -> V_109 -> V_110 > 1 ) )
continue;
} else if ( F_63 ( V_45 , V_104 , V_89 , sizeof( V_89 ) ) ) {
if ( V_59 > 0 )
F_62 ( L_17 , V_89 ) ;
goto V_103;
}
F_64 ( V_45 , & V_28 ,
V_104 , V_89 , sizeof( V_89 ) ) ;
F_65 ( L_17 , V_89 ) ;
if ( V_99 != - 1 )
F_66 ( V_99 , V_111 ) ;
return - 1 ;
}
V_45 -> V_55 = true ;
V_93 = strlen ( V_45 -> V_76 ) ;
if ( V_93 > V_112 )
V_112 = V_93 ;
if ( V_21 && F_57 ( V_45 ) )
return - 1 ;
}
if ( F_67 ( V_8 , & V_45 ) ) {
error ( L_18 ,
V_45 -> V_113 , F_27 ( V_45 ) , V_104 ,
F_68 ( V_104 , V_89 , sizeof( V_89 ) ) ) ;
return - 1 ;
}
if ( F_69 ( V_8 , & V_45 , & V_97 ) ) {
error ( L_19 ,
V_97 -> V_62 . V_114 , F_27 ( V_45 ) , V_104 ,
F_68 ( V_104 , V_89 , sizeof( V_89 ) ) ) ;
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
V_91 = F_73 () ;
F_34 ( V_68 , & V_69 ) ;
if ( V_95 ) {
F_74 ( V_8 ) ;
F_37 () ;
if ( V_88 ) {
while ( ! F_75 ( V_99 , & V_94 , V_115 ) ) {
F_76 ( & V_66 , NULL ) ;
F_33 () ;
}
}
F_77 ( & V_94 ) ;
if ( V_73 ) {
const char * V_116 = F_68 ( V_73 , V_89 , sizeof( V_89 ) ) ;
F_16 ( L_20 , V_116 ) ;
return - 1 ;
}
if ( F_78 ( V_94 ) )
F_79 ( F_80 ( V_94 ) , V_87 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_117 ) {
F_76 ( & V_66 , NULL ) ;
if ( V_88 )
F_33 () ;
}
}
F_40 () ;
V_92 = F_73 () ;
F_81 ( & V_118 , V_92 - V_91 ) ;
F_28 () ;
F_82 ( V_8 ) ;
return F_83 ( V_94 ) ;
}
static int F_84 ( int V_86 , const char * * V_87 )
{
int V_119 ;
if ( V_120 ) {
V_119 = system ( V_120 ) ;
if ( V_119 )
return V_119 ;
}
if ( V_121 )
F_85 () ;
V_119 = F_59 ( V_86 , V_87 ) ;
if ( V_119 )
return V_119 ;
if ( V_122 ) {
V_119 = system ( V_122 ) ;
if ( V_119 )
return V_119 ;
}
return V_119 ;
}
static void F_86 ( T_3 V_64 , T_3 V_63 )
{
if ( V_123 ) {
fprintf ( V_13 . V_60 , L_21 V_61 L_22 ,
V_124 ,
V_64 ,
V_124 ,
V_63 ? 100.0 * V_64 / V_63 : 100.0 ) ;
} else if ( V_64 != V_63 ) {
fprintf ( V_13 . V_60 , L_23 , 100.0 * V_64 / V_63 ) ;
}
}
static void F_87 ( double V_125 , double V_126 )
{
double V_127 = F_88 ( V_125 , V_126 ) ;
if ( V_123 )
fprintf ( V_13 . V_60 , L_24 , V_124 , V_127 ) ;
else if ( V_127 )
fprintf ( V_13 . V_60 , L_25 , V_127 ) ;
}
static void F_89 ( struct V_9 * V_10 , double V_126 )
{
struct V_128 * V_129 ;
if ( V_130 == 1 )
return;
V_129 = V_10 -> V_131 ;
F_87 ( F_90 ( & V_129 -> V_132 [ 0 ] ) , V_126 ) ;
}
static void F_91 ( struct V_9 * V_10 , int V_52 , int V_83 )
{
switch ( V_13 . V_133 ) {
case V_134 :
fprintf ( V_13 . V_60 , L_26 ,
F_92 ( V_52 ) ,
V_123 ? 0 : - 8 ,
F_93 ( V_52 ) ,
V_124 ,
V_123 ? 0 : 4 ,
V_83 ,
V_124 ) ;
break;
case V_135 :
fprintf ( V_13 . V_60 , L_27 ,
V_123 ? 0 : - 5 ,
V_52 ,
V_124 ,
V_123 ? 0 : 4 ,
V_83 ,
V_124 ) ;
break;
case V_136 :
fprintf ( V_13 . V_60 , L_28 ,
V_123 ? 0 : - 4 ,
F_10 ( V_10 ) -> V_137 [ V_52 ] , V_124 ) ;
break;
case V_138 :
fprintf ( V_13 . V_60 , L_29 ,
V_123 ? 0 : 16 ,
F_94 ( V_10 -> V_31 , V_52 ) ,
V_123 ? 0 : - 8 ,
F_95 ( V_10 -> V_31 , V_52 ) ,
V_124 ) ;
break;
case V_139 :
case V_140 :
default:
break;
}
}
static void F_96 ( void * V_141 )
{
struct V_142 * V_143 = V_141 ;
V_143 -> V_144 = true ;
}
static void F_97 ( struct V_142 * V_143 )
{
fputc ( '\n' , V_143 -> V_145 ) ;
fputs ( V_143 -> V_146 , V_143 -> V_145 ) ;
F_91 ( V_143 -> V_10 , V_143 -> V_52 , V_143 -> V_83 ) ;
if ( V_13 . V_133 == V_136 )
fprintf ( V_143 -> V_145 , L_30 ) ;
fprintf ( V_143 -> V_145 , L_31 ) ;
}
static void F_98 ( void * V_141 , const char * V_147 , const char * V_148 ,
const char * V_76 , double V_62 )
{
struct V_142 * V_143 = V_141 ;
T_9 * V_149 = V_143 -> V_145 ;
int V_150 ;
bool V_144 = V_143 -> V_144 ;
V_143 -> V_144 = false ;
if ( V_76 == NULL || V_148 == NULL ) {
fprintf ( V_149 , L_32 , V_151 , L_33 ) ;
return;
}
if ( V_144 )
F_97 ( V_143 ) ;
V_150 = fprintf ( V_149 , L_34 ) ;
if ( V_147 )
V_150 += F_99 ( V_149 , V_147 , V_148 , V_62 ) ;
else
V_150 += fprintf ( V_149 , V_148 , V_62 ) ;
fprintf ( V_149 , L_35 , V_151 - V_150 - 1 , V_76 ) ;
}
static void F_100 ( void * V_141 )
{
struct V_142 * V_143 = V_141 ;
int V_152 ;
fputc ( '\n' , V_143 -> V_145 ) ;
if ( V_143 -> V_146 )
fprintf ( V_143 -> V_145 , L_36 , V_143 -> V_146 , V_124 ) ;
F_91 ( V_143 -> V_10 , V_143 -> V_52 , V_143 -> V_83 ) ;
for ( V_152 = 0 ; V_152 < V_143 -> V_153 ; V_152 ++ )
fputs ( V_124 , V_143 -> V_145 ) ;
}
static void F_101 ( void * V_141 ,
const char * V_147 V_36 ,
const char * V_148 , const char * V_76 , double V_62 )
{
struct V_142 * V_143 = V_141 ;
T_9 * V_149 = V_143 -> V_145 ;
char V_154 [ 64 ] , * V_155 , * V_156 ;
if ( V_76 == NULL || V_148 == NULL ) {
fprintf ( V_149 , L_37 , V_124 , V_124 , V_124 , V_124 ) ;
return;
}
snprintf ( V_154 , sizeof( V_154 ) , V_148 , V_62 ) ;
V_155 = V_154 ;
while ( isspace ( * V_155 ) )
V_155 ++ ;
V_156 = V_155 ;
while ( isdigit ( * V_156 ) || * V_156 == '.' )
V_156 ++ ;
* V_156 = 0 ;
while ( isspace ( * V_76 ) )
V_76 ++ ;
fprintf ( V_149 , L_37 , V_124 , V_155 , V_124 , V_76 ) ;
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
static const char * F_103 ( char * V_154 , struct V_9 * V_10 ,
const char * V_76 )
{
if ( ! strncmp ( V_76 , L_42 , 6 ) ) {
snprintf ( V_154 , 1024 , L_43 , F_27 ( V_10 ) ,
V_76 ) ;
return V_154 ;
}
return V_76 ;
}
static void F_104 ( void * V_141 , const char * V_147 , const char * V_148 ,
const char * V_76 , double V_62 )
{
struct V_142 * V_143 = V_141 ;
T_9 * V_149 = V_143 -> V_145 ;
int V_150 ;
char V_154 [ 1024 ] ;
unsigned V_157 = V_158 ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_154 , V_143 -> V_10 , V_76 ) ;
if ( V_147 )
V_150 = F_99 ( V_149 , V_147 , V_148 , V_62 ) ;
else
V_150 = fprintf ( V_149 , V_148 , V_62 ) ;
if ( V_150 > V_158 )
V_150 = V_158 ;
if ( V_157 < strlen ( V_76 ) )
V_157 = strlen ( V_76 ) + 1 ;
fprintf ( V_149 , L_44 , V_157 - V_150 , L_33 ) ;
}
static void F_105 ( void * V_141 , const char * V_147 V_36 ,
const char * V_148 ,
const char * V_76 , double V_62 )
{
struct V_142 * V_143 = V_141 ;
T_9 * V_149 = V_143 -> V_145 ;
char V_154 [ 64 ] , * V_155 , * V_156 ;
char V_159 [ 1024 ] ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_159 , V_143 -> V_10 , V_76 ) ;
snprintf ( V_154 , sizeof V_154 , V_148 , V_62 ) ;
V_155 = V_154 ;
while ( isspace ( * V_155 ) )
V_155 ++ ;
V_156 = V_155 ;
while ( isdigit ( * V_156 ) || * V_156 == '.' )
V_156 ++ ;
* V_156 = 0 ;
fprintf ( V_149 , L_36 , V_155 , V_124 ) ;
}
static void F_106 ( void * V_141 V_36 )
{
}
static void F_107 ( void * V_141 , const char * V_147 V_36 ,
const char * V_148 V_36 ,
const char * V_76 , double V_62 V_36 )
{
struct V_142 * V_143 = V_141 ;
char V_159 [ 1024 ] ;
if ( ! F_102 ( V_76 ) )
return;
V_76 = F_103 ( V_159 , V_143 -> V_10 , V_76 ) ;
if ( V_123 )
fprintf ( V_143 -> V_145 , L_36 , V_76 , V_124 ) ;
else
fprintf ( V_143 -> V_145 , L_45 , V_158 , V_76 ) ;
}
static void F_108 ( int V_52 , int V_83 , struct V_9 * V_10 , double V_126 )
{
T_9 * V_60 = V_13 . V_60 ;
double V_160 = V_126 / V_98 ;
const char * V_161 , * V_162 ;
char V_65 [ 25 ] ;
V_161 = V_123 ? L_46 : L_47 ;
V_162 = V_123 ? L_48 : L_49 ;
F_91 ( V_10 , V_52 , V_83 ) ;
F_109 ( V_65 , sizeof( V_65 ) , L_36 ,
F_27 ( V_10 ) , V_123 ? L_33 : L_50 ) ;
fprintf ( V_60 , V_161 , V_160 , V_124 ) ;
if ( V_123 )
fprintf ( V_60 , L_36 , V_10 -> V_76 , V_124 ) ;
else
fprintf ( V_60 , L_51 , V_112 , V_10 -> V_76 , V_124 ) ;
fprintf ( V_60 , V_162 , V_65 ) ;
if ( V_10 -> V_163 )
fprintf ( V_60 , L_36 , V_124 , V_10 -> V_163 -> V_65 ) ;
}
static int F_110 ( struct V_9 * V_10 , int V_52 )
{
int V_152 ;
if ( ! V_164 )
return 0 ;
if ( V_13 . V_133 == V_136 )
return V_52 ;
if ( V_13 . V_133 == V_139 )
return 0 ;
for ( V_152 = 0 ; V_152 < F_24 ( V_10 ) ; V_152 ++ ) {
int V_165 = F_10 ( V_10 ) -> V_137 [ V_152 ] ;
if ( V_164 ( V_8 -> V_80 , V_165 ) == V_52 )
return V_165 ;
}
return 0 ;
}
static void F_111 ( int V_52 , int V_83 , struct V_9 * V_10 , double V_126 )
{
T_9 * V_60 = V_13 . V_60 ;
double V_166 = V_10 -> V_14 ;
const char * V_148 ;
if ( V_123 ) {
V_148 = floor ( V_166 ) != V_166 ? L_52 : L_53 ;
} else {
if ( V_167 )
V_148 = floor ( V_166 ) != V_166 ? L_54 : L_55 ;
else
V_148 = floor ( V_166 ) != V_166 ? L_56 : L_57 ;
}
F_91 ( V_10 , V_52 , V_83 ) ;
fprintf ( V_60 , V_148 , V_126 , V_124 ) ;
if ( V_10 -> V_76 )
fprintf ( V_60 , L_51 ,
V_123 ? 0 : V_112 ,
V_10 -> V_76 , V_124 ) ;
fprintf ( V_60 , L_32 , V_123 ? 0 : 25 , F_27 ( V_10 ) ) ;
if ( V_10 -> V_163 )
fprintf ( V_60 , L_36 , V_124 , V_10 -> V_163 -> V_65 ) ;
}
static void F_112 ( int V_52 , int V_83 , struct V_9 * V_45 , double V_168 ,
char * V_146 , T_3 V_64 , T_3 V_63 , double V_169 )
{
struct V_170 V_149 ;
struct V_142 V_143 = {
. V_145 = V_13 . V_60 ,
. V_146 = V_146 ? V_146 : L_33 ,
. V_52 = V_52 ,
. V_83 = V_83 ,
. V_10 = V_45 ,
} ;
T_10 V_171 = F_98 ;
void (* F_113)( void * );
if ( V_172 ) {
F_113 = F_106 ;
if ( V_123 )
V_171 = F_105 ;
else
V_171 = F_104 ;
} else
F_113 = F_96 ;
if ( V_123 && ! V_172 ) {
static int V_173 [] = {
[ V_139 ] = 0 ,
[ V_138 ] = 1 ,
[ V_136 ] = 1 ,
[ V_135 ] = 2 ,
[ V_134 ] = 2 ,
} ;
V_171 = F_101 ;
F_113 = F_100 ;
V_143 . V_153 = 3 ;
V_143 . V_153 += V_173 [ V_13 . V_133 ] ;
if ( V_45 -> V_163 )
V_143 . V_153 ++ ;
}
if ( V_64 == 0 || V_63 == 0 || V_45 -> V_58 -> V_174 == - 1 ) {
if ( V_172 ) {
V_171 ( & V_143 , NULL , L_33 , L_33 , 0 ) ;
return;
}
F_91 ( V_45 , V_52 , V_83 ) ;
fprintf ( V_13 . V_60 , L_58 ,
V_123 ? 0 : 18 ,
V_45 -> V_55 ? V_175 : V_176 ,
V_124 ) ;
fprintf ( V_13 . V_60 , L_51 ,
V_123 ? 0 : V_112 ,
V_45 -> V_76 , V_124 ) ;
fprintf ( V_13 . V_60 , L_44 ,
V_123 ? 0 : - 25 ,
F_27 ( V_45 ) ) ;
if ( V_45 -> V_163 )
fprintf ( V_13 . V_60 , L_36 ,
V_124 , V_45 -> V_163 -> V_65 ) ;
if ( ! V_123 )
V_171 ( & V_143 , NULL , NULL , L_33 , 0 ) ;
F_89 ( V_45 , V_169 ) ;
F_86 ( V_64 , V_63 ) ;
if ( V_123 )
V_171 ( & V_143 , NULL , NULL , L_33 , 0 ) ;
return;
}
if ( V_172 )
;
else if ( F_12 ( V_45 ) )
F_108 ( V_52 , V_83 , V_45 , V_168 ) ;
else
F_111 ( V_52 , V_83 , V_45 , V_168 ) ;
V_149 . V_177 = V_171 ;
V_149 . V_178 = F_113 ;
V_149 . V_141 = & V_143 ;
if ( V_123 && ! V_172 ) {
F_89 ( V_45 , V_169 ) ;
F_86 ( V_64 , V_63 ) ;
}
F_114 ( V_45 , V_168 ,
F_110 ( V_45 , V_52 ) ,
& V_149 ) ;
if ( ! V_123 && ! V_172 ) {
F_89 ( V_45 , V_169 ) ;
F_86 ( V_64 , V_63 ) ;
}
}
static void F_115 ( void )
{
int V_46 , V_179 , V_52 , V_180 ;
T_3 V_62 ;
struct V_9 * V_45 ;
for ( V_180 = 0 ; V_180 < V_181 -> V_83 ; V_180 ++ ) {
V_52 = V_181 -> V_137 [ V_180 ] ;
F_29 (evsel_list, counter) {
V_62 = 0 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_179 = V_164 ( V_8 -> V_80 , V_46 ) ;
if ( V_179 != V_52 )
continue;
V_62 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
}
V_62 = V_62 * V_45 -> V_14 ;
F_116 ( V_45 , & V_62 ,
F_110 ( V_45 , V_52 ) ) ;
}
}
}
static void F_117 ( char * V_146 )
{
T_9 * V_60 = V_13 . V_60 ;
struct V_9 * V_45 ;
int V_46 , V_180 , V_179 , V_52 , V_83 ;
double V_168 ;
T_3 V_63 , V_64 , V_62 ;
bool V_182 ;
if ( ! ( V_181 || V_164 ) )
return;
F_115 () ;
for ( V_180 = 0 ; V_180 < V_181 -> V_83 ; V_180 ++ ) {
if ( V_146 && V_172 )
fprintf ( V_60 , L_48 , V_146 ) ;
V_52 = V_181 -> V_137 [ V_180 ] ;
V_182 = true ;
F_29 (evsel_list, counter) {
V_62 = V_63 = V_64 = 0 ;
V_83 = 0 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_179 = V_164 ( F_10 ( V_45 ) , V_46 ) ;
if ( V_179 != V_52 )
continue;
V_62 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 += F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
V_83 ++ ;
}
if ( V_182 && V_172 ) {
V_182 = false ;
F_91 ( V_45 , V_52 , V_83 ) ;
}
if ( V_146 && ! V_172 )
fprintf ( V_60 , L_48 , V_146 ) ;
V_168 = V_62 * V_45 -> V_14 ;
F_112 ( V_52 , V_83 , V_45 , V_168 , V_146 , V_64 , V_63 , 1.0 ) ;
if ( ! V_172 )
fputc ( '\n' , V_60 ) ;
}
if ( V_172 )
fputc ( '\n' , V_60 ) ;
}
}
static void F_118 ( struct V_9 * V_45 , char * V_146 )
{
T_9 * V_60 = V_13 . V_60 ;
int V_53 = F_23 ( V_45 -> V_31 ) ;
int V_54 = F_119 ( V_45 -> V_80 ) ;
int V_46 , V_47 ;
double V_168 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
T_3 V_63 = 0 , V_64 = 0 , V_62 = 0 ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
V_62 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_62 ;
V_63 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_63 ;
V_64 += F_25 ( V_45 -> V_58 , V_46 , V_47 ) -> V_64 ;
}
if ( V_146 )
fprintf ( V_60 , L_48 , V_146 ) ;
V_168 = V_62 * V_45 -> V_14 ;
F_112 ( V_47 , 0 , V_45 , V_168 , V_146 , V_64 , V_63 , 1.0 ) ;
fputc ( '\n' , V_60 ) ;
}
}
static void F_120 ( struct V_9 * V_45 , char * V_146 )
{
T_9 * V_60 = V_13 . V_60 ;
struct V_128 * V_129 = V_45 -> V_131 ;
double V_126 = F_121 ( & V_129 -> V_132 [ 0 ] ) ;
double V_168 ;
double V_183 , V_184 ;
V_183 = F_121 ( & V_129 -> V_132 [ 1 ] ) ;
V_184 = F_121 ( & V_129 -> V_132 [ 2 ] ) ;
if ( V_146 && ! V_172 )
fprintf ( V_60 , L_48 , V_146 ) ;
V_168 = V_126 * V_45 -> V_14 ;
F_112 ( - 1 , 0 , V_45 , V_168 , V_146 , V_184 , V_183 , V_126 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_5 ) ;
}
static void F_122 ( struct V_9 * V_45 , char * V_146 )
{
T_9 * V_60 = V_13 . V_60 ;
T_3 V_63 , V_64 , V_62 ;
double V_168 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_24 ( V_45 ) ; V_46 ++ ) {
V_62 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
if ( V_146 )
fprintf ( V_60 , L_48 , V_146 ) ;
V_168 = V_62 * V_45 -> V_14 ;
F_112 ( V_46 , 0 , V_45 , V_168 , V_146 , V_64 , V_63 , 1.0 ) ;
fputc ( '\n' , V_60 ) ;
}
}
static void F_123 ( char * V_146 )
{
int V_46 ;
int V_185 = 0 ;
struct V_9 * V_45 ;
T_3 V_63 , V_64 , V_62 ;
double V_168 ;
V_185 = V_8 -> V_80 -> V_83 ;
for ( V_46 = 0 ; V_46 < V_185 ; V_46 ++ ) {
bool V_182 = true ;
if ( V_146 )
fputs ( V_146 , V_13 . V_60 ) ;
F_29 (evsel_list, counter) {
if ( V_182 ) {
F_91 ( V_45 , V_46 , 0 ) ;
V_182 = false ;
}
V_62 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_62 ;
V_63 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_63 ;
V_64 = F_25 ( V_45 -> V_58 , V_46 , 0 ) -> V_64 ;
V_168 = V_62 * V_45 -> V_14 ;
F_112 ( V_46 , 0 , V_45 , V_168 , V_146 , V_64 , V_63 , 1.0 ) ;
}
fputc ( '\n' , V_13 . V_60 ) ;
}
}
static void F_124 ( const char * V_146 , bool V_186 )
{
struct V_170 V_149 ;
struct V_9 * V_45 ;
struct V_142 V_143 = {
. V_145 = V_13 . V_60
} ;
if ( V_146 )
fprintf ( V_13 . V_60 , L_48 , V_146 ) ;
if ( ! V_123 && ! V_186 )
fprintf ( V_13 . V_60 , L_44 ,
V_187 [ V_13 . V_133 ] , L_33 ) ;
if ( V_123 ) {
if ( V_13 . V_88 )
fputs ( L_59 , V_13 . V_60 ) ;
fputs ( V_188 [ V_13 . V_133 ] ,
V_13 . V_60 ) ;
}
F_29 (evsel_list, counter) {
V_143 . V_10 = V_45 ;
V_149 . V_141 = & V_143 ;
V_149 . V_177 = F_107 ;
V_149 . V_178 = F_106 ;
V_143 . V_10 = V_45 ;
F_114 ( V_45 , 0 ,
0 ,
& V_149 ) ;
}
fputc ( '\n' , V_13 . V_60 ) ;
}
static void F_125 ( char * V_146 , struct V_1 * V_66 )
{
T_9 * V_60 = V_13 . V_60 ;
static int V_189 ;
sprintf ( V_146 , L_60 , V_66 -> V_5 , V_66 -> V_6 , V_124 ) ;
if ( V_189 == 0 && ! V_123 ) {
switch ( V_13 . V_133 ) {
case V_135 :
fprintf ( V_60 , L_61 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_62 , V_112 , L_63 ) ;
break;
case V_134 :
fprintf ( V_60 , L_64 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_62 , V_112 , L_63 ) ;
break;
case V_136 :
fprintf ( V_60 , L_65 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_66 , V_112 , L_63 ) ;
break;
case V_138 :
fprintf ( V_60 , L_67 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_68 , V_112 , L_63 ) ;
break;
case V_139 :
default:
fprintf ( V_60 , L_69 ) ;
if ( ! V_172 )
fprintf ( V_60 , L_62 , V_112 , L_63 ) ;
case V_140 :
break;
}
}
if ( V_189 == 0 && V_172 )
F_124 ( L_70 , true ) ;
if ( ++ V_189 == 25 )
V_189 = 0 ;
}
static void F_126 ( int V_86 , const char * * V_87 )
{
T_9 * V_60 = V_13 . V_60 ;
int V_152 ;
fflush ( stdout ) ;
if ( ! V_123 ) {
fprintf ( V_60 , L_5 ) ;
fprintf ( V_60 , L_71 ) ;
if ( V_28 . V_57 )
fprintf ( V_60 , L_72 ) ;
else if ( V_28 . V_190 )
fprintf ( V_60 , L_73 , V_28 . V_190 ) ;
else if ( ! F_127 ( & V_28 ) ) {
fprintf ( V_60 , L_74 , V_87 ? V_87 [ 0 ] : L_75 ) ;
for ( V_152 = 1 ; V_87 && ( V_152 < V_86 ) ; V_152 ++ )
fprintf ( V_60 , L_76 , V_87 [ V_152 ] ) ;
} else if ( V_28 . V_101 )
fprintf ( V_60 , L_77 , V_28 . V_101 ) ;
else
fprintf ( V_60 , L_78 , V_28 . V_191 ) ;
fprintf ( V_60 , L_79 ) ;
if ( V_130 > 1 )
fprintf ( V_60 , L_80 , V_130 ) ;
fprintf ( V_60 , L_81 ) ;
}
}
static void F_128 ( void )
{
T_9 * V_60 = V_13 . V_60 ;
if ( ! V_192 )
fprintf ( V_60 , L_5 ) ;
fprintf ( V_60 , L_82 ,
F_121 ( & V_118 ) / V_7 ) ;
if ( V_130 > 1 ) {
fprintf ( V_60 , L_83 ) ;
F_87 ( F_90 ( & V_118 ) ,
F_121 ( & V_118 ) ) ;
}
fprintf ( V_60 , L_84 ) ;
}
static void F_36 ( struct V_1 * V_66 , int V_86 , const char * * V_87 )
{
int V_88 = V_13 . V_88 ;
struct V_9 * V_45 ;
char V_154 [ 64 ] , * V_146 = NULL ;
if ( V_21 && V_22 . V_23 . V_24 )
return;
if ( V_88 )
F_125 ( V_146 = V_154 , V_66 ) ;
else
F_126 ( V_86 , V_87 ) ;
if ( V_172 ) {
static int V_193 ;
if ( V_193 == 0 && ! V_88 )
F_124 ( V_146 , false ) ;
if ( V_193 ++ == 25 )
V_193 = 0 ;
if ( V_13 . V_133 == V_139 && V_146 )
fprintf ( V_13 . V_60 , L_48 , V_146 ) ;
}
switch ( V_13 . V_133 ) {
case V_134 :
case V_135 :
F_117 ( V_146 ) ;
break;
case V_138 :
F_29 (evsel_list, counter)
F_118 ( V_45 , V_146 ) ;
break;
case V_139 :
F_29 (evsel_list, counter)
F_120 ( V_45 , V_146 ) ;
if ( V_172 )
fputc ( '\n' , V_13 . V_60 ) ;
break;
case V_136 :
if ( V_172 )
F_123 ( V_146 ) ;
else {
F_29 (evsel_list, counter)
F_122 ( V_45 , V_146 ) ;
}
break;
case V_140 :
default:
break;
}
if ( ! V_88 && ! V_123 )
F_128 () ;
fflush ( V_13 . V_60 ) ;
}
static void F_129 ( int T_5 )
{
if ( ( V_99 == - 1 ) || V_13 . V_88 )
V_117 = 1 ;
V_194 = T_5 ;
V_99 = - 1 ;
}
static void F_130 ( void )
{
T_11 V_195 , V_196 ;
F_131 ( & V_195 ) ;
F_132 ( & V_195 , V_197 ) ;
F_133 ( V_198 , & V_195 , & V_196 ) ;
if ( V_99 != - 1 )
F_66 ( V_99 , V_111 ) ;
F_133 ( V_199 , & V_196 , NULL ) ;
if ( V_194 == - 1 )
return;
signal ( V_194 , V_200 ) ;
F_66 ( F_134 () , V_194 ) ;
}
static int F_135 ( const struct V_201 * T_12 V_36 ,
const char * V_180 V_36 , int V_202 )
{
V_203 = V_202 ? 0 : 1 ;
return 0 ;
}
static int F_136 ( const struct V_201 * T_12 V_36 ,
const char * V_180 V_36 , int V_202 )
{
V_204 = true ;
V_172 = ! V_202 ;
return 0 ;
}
static int F_137 ( struct V_81 * V_137 , int V_46 )
{
return F_138 ( V_137 , V_46 , NULL ) ;
}
static int F_139 ( struct V_81 * V_137 , int V_46 )
{
return F_140 ( V_137 , V_46 , NULL ) ;
}
static int F_141 ( struct V_81 * V_137 )
{
int V_152 , V_205 = - 1 ;
for ( V_152 = 0 ; V_152 < V_137 -> V_83 ; V_152 ++ ) {
if ( V_137 -> V_137 [ V_152 ] > V_205 )
V_205 = V_137 -> V_137 [ V_152 ] ;
}
return V_205 ;
}
static int F_142 ( T_13 V_206 , struct V_81 * V_137 , int V_207 )
{
int V_46 ;
if ( V_207 >= V_137 -> V_83 )
return - 1 ;
V_46 = V_137 -> V_137 [ V_207 ] ;
if ( V_208 -> V_137 [ V_46 ] == - 1 )
V_208 -> V_137 [ V_46 ] = V_206 ( V_137 , V_207 ) ;
return V_208 -> V_137 [ V_46 ] ;
}
static int F_143 ( struct V_81 * V_137 , int V_207 )
{
return F_142 ( F_137 , V_137 , V_207 ) ;
}
static int F_144 ( struct V_81 * V_137 , int V_207 )
{
return F_142 ( F_139 , V_137 , V_207 ) ;
}
static int F_145 ( void )
{
int V_83 ;
switch ( V_13 . V_133 ) {
case V_135 :
if ( F_146 ( V_8 -> V_80 , & V_181 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_164 = F_143 ;
break;
case V_134 :
if ( F_147 ( V_8 -> V_80 , & V_181 ) ) {
perror ( L_86 ) ;
return - 1 ;
}
V_164 = F_144 ;
break;
case V_136 :
case V_139 :
case V_138 :
case V_140 :
default:
break;
}
V_83 = F_141 ( V_8 -> V_80 ) ;
V_208 = F_148 ( V_83 + 1 ) ;
return V_208 ? 0 : - V_85 ;
}
static void F_149 ( void )
{
F_150 ( V_181 ) ;
F_150 ( V_208 ) ;
V_181 = NULL ;
V_208 = NULL ;
}
static inline int F_151 ( struct V_209 * V_210 , struct V_81 * V_137 , int V_207 )
{
int V_46 ;
if ( V_207 > V_137 -> V_83 )
return - 1 ;
V_46 = V_137 -> V_137 [ V_207 ] ;
if ( V_46 >= V_210 -> V_211 )
return - 1 ;
return V_46 ;
}
static int F_152 ( struct V_81 * V_137 , int V_207 , void * V_212 )
{
struct V_209 * V_210 = V_212 ;
int V_46 = F_151 ( V_210 , V_137 , V_207 ) ;
return V_46 == - 1 ? - 1 : V_210 -> V_46 [ V_46 ] . V_213 ;
}
static int F_153 ( struct V_81 * V_137 , int V_207 , void * V_212 )
{
struct V_209 * V_210 = V_212 ;
int V_214 = - 1 , V_46 = F_151 ( V_210 , V_137 , V_207 ) ;
if ( V_46 != - 1 ) {
int V_213 = V_210 -> V_46 [ V_46 ] . V_213 ;
V_214 = ( V_213 << 16 ) | ( V_210 -> V_46 [ V_46 ] . V_215 & 0xffff ) ;
}
return V_214 ;
}
static int F_154 ( struct V_209 * V_210 , struct V_81 * V_80 ,
struct V_81 * * V_216 )
{
return F_155 ( V_80 , V_216 , F_152 , V_210 ) ;
}
static int F_156 ( struct V_209 * V_210 , struct V_81 * V_80 ,
struct V_81 * * V_217 )
{
return F_155 ( V_80 , V_217 , F_153 , V_210 ) ;
}
static int F_157 ( struct V_81 * V_137 , int V_207 )
{
return F_152 ( V_137 , V_207 , & V_22 . V_78 -> V_41 . V_210 ) ;
}
static int F_158 ( struct V_81 * V_137 , int V_207 )
{
return F_153 ( V_137 , V_207 , & V_22 . V_78 -> V_41 . V_210 ) ;
}
static int F_159 ( struct V_22 * V_218 )
{
struct V_209 * V_210 = & V_218 -> V_78 -> V_41 . V_210 ;
switch ( V_13 . V_133 ) {
case V_135 :
if ( F_154 ( V_210 , V_8 -> V_80 , & V_181 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_164 = F_157 ;
break;
case V_134 :
if ( F_156 ( V_210 , V_8 -> V_80 , & V_181 ) ) {
perror ( L_86 ) ;
return - 1 ;
}
V_164 = F_158 ;
break;
case V_136 :
case V_139 :
case V_138 :
case V_140 :
default:
break;
}
return 0 ;
}
static int F_160 ( const char * * V_12 , char * * V_219 , bool V_220 )
{
int V_221 = 0 ;
int V_152 ;
int V_222 = 0 ;
char * V_180 ;
for ( V_152 = 0 ; V_12 [ V_152 ] ; V_152 ++ ) {
if ( F_161 ( L_87 , V_12 [ V_152 ] ) ) {
V_222 += strlen ( V_12 [ V_152 ] ) + 1 ;
V_12 [ V_152 - V_221 ] = V_12 [ V_152 ] ;
} else
V_221 ++ ;
}
V_12 [ V_152 - V_221 ] = NULL ;
* V_219 = malloc ( V_222 + 1 + 2 ) ;
if ( ! * V_219 )
return - 1 ;
V_180 = * V_219 ;
if ( V_152 - V_221 == 0 ) {
* V_180 = 0 ;
return 0 ;
}
if ( V_220 )
* V_180 ++ = '{' ;
for ( V_152 = 0 ; V_12 [ V_152 ] ; V_152 ++ ) {
strcpy ( V_180 , V_12 [ V_152 ] ) ;
V_180 += strlen ( V_180 ) ;
* V_180 ++ = ',' ;
}
if ( V_220 ) {
V_180 [ - 1 ] = '}' ;
* V_180 = 0 ;
} else
V_180 [ - 1 ] = 0 ;
return 0 ;
}
__weak bool F_162 ( bool * V_223 )
{
* V_223 = false ;
return false ;
}
__weak void F_163 ( void )
{
}
static int F_164 ( void )
{
int V_77 ;
struct V_11 V_224 [] = {
{ . type = V_225 , . V_226 = V_227 } ,
{ . type = V_225 , . V_226 = V_228 } ,
{ . type = V_225 , . V_226 = V_229 } ,
{ . type = V_225 , . V_226 = V_230 } ,
{ . type = V_231 , . V_226 = V_232 } ,
} ;
struct V_11 V_233 [] = {
{ . type = V_231 , . V_226 = V_234 } ,
} ;
struct V_11 V_235 [] = {
{ . type = V_231 , . V_226 = V_236 } ,
} ;
struct V_11 V_237 [] = {
{ . type = V_231 , . V_226 = V_238 } ,
{ . type = V_231 , . V_226 = V_239 } ,
{ . type = V_231 , . V_226 = V_240 } ,
} ;
struct V_11 V_241 [] = {
{ . type = V_242 ,
. V_226 =
V_243 << 0 |
( V_244 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_243 << 0 |
( V_244 << 8 ) |
( V_246 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_247 << 0 |
( V_244 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_247 << 0 |
( V_244 << 8 ) |
( V_246 << 16 ) } ,
} ;
struct V_11 V_248 [] = {
{ . type = V_242 ,
. V_226 =
V_249 << 0 |
( V_244 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_249 << 0 |
( V_244 << 8 ) |
( V_246 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_250 << 0 |
( V_244 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_250 << 0 |
( V_244 << 8 ) |
( V_246 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_251 << 0 |
( V_244 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_251 << 0 |
( V_244 << 8 ) |
( V_246 << 16 ) } ,
} ;
struct V_11 V_252 [] = {
{ . type = V_242 ,
. V_226 =
V_243 << 0 |
( V_253 << 8 ) |
( V_245 << 16 ) } ,
{ . type = V_242 ,
. V_226 =
V_243 << 0 |
( V_253 << 8 ) |
( V_246 << 16 ) } ,
} ;
if ( V_192 )
return 0 ;
if ( V_254 ) {
if ( F_161 ( L_87 , L_88 ) &&
F_161 ( L_87 , L_89 ) )
V_77 = F_165 ( V_8 , V_255 , NULL ) ;
else
V_77 = F_165 ( V_8 , V_256 , NULL ) ;
if ( V_77 ) {
fprintf ( V_257 , L_90 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_258 ) {
char * V_219 = NULL ;
bool V_223 = false ;
if ( V_13 . V_133 != V_139 &&
V_13 . V_133 != V_134 ) {
F_16 ( L_91 ) ;
return - 1 ;
}
V_13 . V_133 = V_134 ;
if ( V_259 || ! F_8 ( & V_28 ) ) {
F_16 ( L_92 ) ;
return - 1 ;
}
if ( ! V_204 )
V_172 = true ;
if ( F_160 ( V_260 , & V_219 ,
F_162 ( & V_223 ) ) < 0 ) {
F_16 ( L_93 ) ;
return - 1 ;
}
if ( V_260 [ 0 ] && V_219 ) {
if ( V_223 )
F_163 () ;
V_77 = F_165 ( V_8 , V_219 , NULL ) ;
if ( V_77 ) {
fprintf ( V_257 ,
L_94 ,
V_219 , V_77 ) ;
free ( V_219 ) ;
return - 1 ;
}
} else {
fprintf ( V_257 , L_95 ) ;
return - 1 ;
}
free ( V_219 ) ;
}
if ( ! V_8 -> V_261 ) {
if ( F_8 ( & V_28 ) )
V_224 [ 0 ] . V_226 = V_262 ;
if ( F_166 ( V_8 , V_224 ) < 0 )
return - 1 ;
if ( F_161 ( L_87 , L_96 ) ) {
if ( F_166 ( V_8 ,
V_233 ) < 0 )
return - 1 ;
}
if ( F_161 ( L_87 , L_97 ) ) {
if ( F_166 ( V_8 ,
V_235 ) < 0 )
return - 1 ;
}
if ( F_166 ( V_8 , V_237 ) < 0 )
return - 1 ;
}
if ( V_263 < 1 )
return 0 ;
if ( F_166 ( V_8 , V_241 ) < 0 )
return - 1 ;
if ( V_263 < 2 )
return 0 ;
if ( F_166 ( V_8 , V_248 ) < 0 )
return - 1 ;
if ( V_263 < 3 )
return 0 ;
return F_166 ( V_8 , V_252 ) ;
}
static void F_167 ( struct V_264 * V_78 )
{
int V_265 ;
for ( V_265 = V_266 ; V_265 < V_267 ; V_265 ++ )
F_168 ( & V_78 -> V_41 , V_265 ) ;
F_169 ( & V_78 -> V_41 , V_268 ) ;
F_169 ( & V_78 -> V_41 , V_269 ) ;
F_169 ( & V_78 -> V_41 , V_270 ) ;
F_169 ( & V_78 -> V_41 , V_271 ) ;
}
static int F_170 ( int V_86 , const char * * V_87 )
{
struct V_264 * V_78 ;
struct V_272 * V_23 = & V_22 . V_23 ;
V_86 = F_171 ( V_86 , V_87 , V_273 , V_274 ,
V_275 ) ;
if ( V_276 )
V_23 -> V_277 = V_276 ;
if ( V_130 != 1 || V_278 ) {
F_16 ( L_98 ) ;
return - 1 ;
}
V_78 = F_172 ( V_23 , false , NULL ) ;
if ( V_78 == NULL ) {
F_16 ( L_99 ) ;
return - 1 ;
}
F_167 ( V_78 ) ;
V_78 -> V_279 = V_8 ;
V_22 . V_78 = V_78 ;
V_22 . V_280 = true ;
return V_86 ;
}
static int F_173 ( struct V_35 * T_1 V_36 ,
union V_37 * V_38 ,
struct V_264 * V_78 )
{
struct V_281 * V_282 = & V_38 -> V_282 ;
struct V_9 * V_45 ;
struct V_1 V_283 , * V_66 = NULL ;
const char * * V_87 = V_78 -> V_41 . V_210 . V_284 ;
int V_86 = V_78 -> V_41 . V_210 . V_285 ;
F_29 (evsel_list, counter)
F_31 ( & V_13 , V_45 ) ;
if ( V_282 -> type == V_286 )
F_81 ( & V_118 , V_282 -> time ) ;
if ( V_13 . V_88 && V_282 -> time ) {
V_283 . V_5 = V_282 -> time / V_7 ;
V_283 . V_6 = V_282 -> time % V_7 ;
V_66 = & V_283 ;
}
F_36 ( V_66 , V_86 , V_87 ) ;
return 0 ;
}
static
int F_174 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_264 * V_78 V_36 )
{
struct V_22 * V_218 = F_175 ( T_1 , struct V_22 , T_1 ) ;
F_176 ( & V_13 , & V_38 -> V_13 ) ;
if ( F_177 ( V_218 -> V_80 ) ) {
if ( V_218 -> V_133 != V_140 )
F_32 ( L_100 ) ;
return 0 ;
}
if ( V_218 -> V_133 != V_140 )
V_13 . V_133 = V_218 -> V_133 ;
if ( V_22 . V_23 . V_24 )
F_145 () ;
else
F_159 ( V_218 ) ;
return 0 ;
}
static int F_178 ( struct V_22 * V_218 )
{
if ( ! V_218 -> V_80 || ! V_218 -> V_31 )
return 0 ;
if ( F_179 ( V_218 -> V_287 , L_101 ) )
return - V_105 ;
F_180 ( V_8 , V_218 -> V_80 , V_218 -> V_31 ) ;
if ( F_181 ( V_8 , true ) )
return - V_85 ;
V_218 -> V_287 = true ;
return 0 ;
}
static
int F_182 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_264 * V_78 V_36 )
{
struct V_22 * V_218 = F_175 ( T_1 , struct V_22 , T_1 ) ;
if ( V_218 -> V_31 ) {
F_32 ( L_102 ) ;
return 0 ;
}
V_218 -> V_31 = F_183 ( & V_38 -> V_82 ) ;
if ( ! V_218 -> V_31 )
return - V_85 ;
return F_178 ( V_218 ) ;
}
static
int F_184 ( struct V_35 * T_1 ,
union V_37 * V_38 ,
struct V_264 * V_78 V_36 )
{
struct V_22 * V_218 = F_175 ( T_1 , struct V_22 , T_1 ) ;
struct V_81 * V_80 ;
if ( V_218 -> V_80 ) {
F_32 ( L_103 ) ;
return 0 ;
}
V_80 = F_185 ( & V_38 -> V_81 . V_212 ) ;
if ( ! V_80 )
return - V_85 ;
V_218 -> V_80 = V_80 ;
return F_178 ( V_218 ) ;
}
static int F_186 ( int V_86 , const char * * V_87 )
{
struct V_264 * V_78 ;
const struct V_201 V_288 [] = {
F_187 ( 'i' , L_104 , & V_289 , L_105 , L_106 ) ,
F_188 ( 0 , L_107 , & V_22 . V_133 ,
L_108 , V_135 ) ,
F_188 ( 0 , L_109 , & V_22 . V_133 ,
L_110 , V_134 ) ,
F_188 ( 'A' , L_111 , & V_22 . V_133 ,
L_112 , V_136 ) ,
F_189 ()
} ;
struct V_290 V_218 ;
int V_119 ;
V_86 = F_171 ( V_86 , V_87 , V_288 , V_291 , 0 ) ;
if ( ! V_289 || ! strlen ( V_289 ) ) {
if ( ! F_190 ( V_292 , & V_218 ) && F_191 ( V_218 . V_293 ) )
V_289 = L_113 ;
else
V_289 = L_114 ;
}
V_22 . V_23 . V_277 = V_289 ;
V_22 . V_23 . V_294 = V_295 ;
V_78 = F_172 ( & V_22 . V_23 , false , & V_22 . T_1 ) ;
if ( V_78 == NULL )
return - 1 ;
V_22 . V_78 = V_78 ;
V_13 . V_60 = V_257 ;
V_8 = V_78 -> V_279 ;
V_119 = F_192 ( V_78 ) ;
if ( V_119 )
return V_119 ;
F_193 ( V_78 ) ;
return 0 ;
}
int F_194 ( int V_86 , const char * * V_87 , const char * V_146 V_36 )
{
const char * const V_296 [] = {
L_115 ,
NULL
} ;
int V_94 = - V_105 , V_297 ;
const char * V_294 ;
T_9 * V_60 = V_257 ;
unsigned int V_88 ;
const char * const V_298 [] = { L_116 , L_117 } ;
setlocale ( V_299 , L_33 ) ;
V_8 = F_195 () ;
if ( V_8 == NULL )
return - V_85 ;
F_196 () ;
V_86 = F_197 ( V_86 , V_87 , V_273 , V_298 ,
( const char * * ) V_296 ,
V_275 ) ;
F_198 () ;
if ( V_124 ) {
V_123 = true ;
if ( ! strcmp ( V_124 , L_118 ) )
V_124 = L_119 ;
} else
V_124 = V_300 ;
if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_120 , 3 ) ) {
V_86 = F_170 ( V_86 , V_87 ) ;
if ( V_86 < 0 )
return - 1 ;
} else if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_121 , 3 ) )
return F_186 ( V_86 , V_87 ) ;
V_88 = V_13 . V_88 ;
if ( ! V_21 && V_276 && strcmp ( V_276 , L_113 ) )
V_60 = NULL ;
if ( V_276 && V_301 ) {
fprintf ( V_257 , L_122 ) ;
F_199 ( V_296 , V_273 , L_123 , 1 ) ;
F_199 ( NULL , V_273 , L_124 , 0 ) ;
goto V_149;
}
if ( V_172 && V_13 . V_133 == V_138 ) {
fprintf ( V_257 , L_125 ) ;
goto V_149;
}
if ( V_172 && V_130 > 1 ) {
fprintf ( V_257 , L_126 ) ;
goto V_149;
}
if ( V_301 < 0 ) {
fprintf ( V_257 , L_127 ) ;
F_199 ( V_296 , V_273 , L_124 , 0 ) ;
goto V_149;
}
if ( ! V_60 ) {
struct V_1 V_44 ;
V_294 = V_302 ? L_128 : L_129 ;
V_60 = fopen ( V_276 , V_294 ) ;
if ( ! V_60 ) {
perror ( L_130 ) ;
return - 1 ;
}
F_34 ( V_303 , & V_44 ) ;
fprintf ( V_60 , L_131 , ctime ( & V_44 . V_5 ) ) ;
} else if ( V_301 > 0 ) {
V_294 = V_302 ? L_128 : L_129 ;
V_60 = fdopen ( V_301 , V_294 ) ;
if ( ! V_60 ) {
perror ( L_132 ) ;
return - V_104 ;
}
}
V_13 . V_60 = V_60 ;
if ( V_123 ) {
if ( V_203 == 1 ) {
fprintf ( V_257 , L_133 ) ;
F_199 ( V_296 , V_273 , L_134 , 1 ) ;
F_199 ( NULL , V_273 , L_135 , 1 ) ;
goto V_149;
} else
V_167 = false ;
} else if ( V_203 == 0 )
V_167 = false ;
if ( ! V_86 && F_7 ( & V_28 ) )
V_28 . V_57 = true ;
if ( V_130 < 0 ) {
F_16 ( L_136 ) ;
F_199 ( V_296 , V_273 , L_137 , 1 ) ;
goto V_149;
} else if ( V_130 == 0 ) {
V_278 = true ;
V_130 = 1 ;
}
if ( ( V_13 . V_133 == V_138 ) && ! F_127 ( & V_28 ) ) {
fprintf ( V_257 , L_138
L_139 ) ;
F_199 ( NULL , V_273 , L_140 , 1 ) ;
F_199 ( NULL , V_273 , L_141 , 1 ) ;
goto V_149;
}
if ( ( ( V_13 . V_133 != V_139 &&
V_13 . V_133 != V_138 ) || V_259 ) &&
! F_8 ( & V_28 ) ) {
fprintf ( V_257 , L_142
L_143 ) ;
F_199 ( V_296 , V_273 , L_144 , 1 ) ;
F_199 ( NULL , V_273 , L_145 , 1 ) ;
F_199 ( NULL , V_273 , L_128 , 1 ) ;
goto V_149;
}
if ( F_164 () )
goto V_149;
F_200 ( & V_28 ) ;
if ( F_201 ( V_8 , & V_28 ) < 0 ) {
if ( F_127 ( & V_28 ) ) {
F_16 ( L_146 ) ;
F_199 ( V_296 , V_273 , L_140 , 1 ) ;
F_199 ( NULL , V_273 , L_141 , 1 ) ;
} else if ( F_8 ( & V_28 ) ) {
perror ( L_147 ) ;
F_199 ( V_296 , V_273 , L_148 , 1 ) ;
F_199 ( NULL , V_273 , L_128 , 1 ) ;
}
goto V_149;
}
if ( V_13 . V_133 == V_138 )
F_202 ( V_8 -> V_31 ) ;
if ( V_88 && V_88 < 100 ) {
if ( V_88 < 10 ) {
F_16 ( L_149 ) ;
F_199 ( V_296 , V_273 , L_150 , 1 ) ;
goto V_149;
} else
F_32 ( L_151
L_152
L_153 ) ;
}
if ( F_181 ( V_8 , V_88 ) )
goto V_149;
if ( F_145 () )
goto V_149;
atexit ( F_130 ) ;
if ( ! V_278 )
signal ( V_304 , F_129 ) ;
signal ( V_197 , F_129 ) ;
signal ( V_305 , F_129 ) ;
signal ( V_306 , F_129 ) ;
V_94 = 0 ;
for ( V_297 = 0 ; V_278 || V_297 < V_130 ; V_297 ++ ) {
if ( V_130 != 1 && V_59 > 0 )
fprintf ( V_60 , L_154 ,
V_297 + 1 ) ;
V_94 = F_84 ( V_86 , V_87 ) ;
if ( V_278 && V_94 != - 1 ) {
F_36 ( NULL , V_86 , V_87 ) ;
F_2 () ;
}
}
if ( ! V_278 && V_94 != - 1 && ! V_88 )
F_36 ( NULL , V_86 , V_87 ) ;
if ( V_21 ) {
int V_84 = F_70 ( & V_22 . V_23 ) ;
int V_77 = F_203 ( ( void * ) & V_22 ,
F_14 ,
& V_22 . V_78 -> V_307 . V_308 ) ;
if ( V_77 ) {
F_32 ( L_155
L_156 ) ;
}
if ( ! V_88 ) {
if ( F_35 ( V_118 . V_205 , V_309 ) )
F_16 ( L_8 ) ;
}
if ( ! V_22 . V_23 . V_24 ) {
V_22 . V_78 -> V_41 . V_310 += V_22 . V_43 ;
F_72 ( V_22 . V_78 , V_8 , V_84 , true ) ;
}
F_193 ( V_22 . V_78 ) ;
}
F_149 () ;
F_204 ( V_8 ) ;
V_149:
F_205 ( V_8 ) ;
return V_94 ;
}
