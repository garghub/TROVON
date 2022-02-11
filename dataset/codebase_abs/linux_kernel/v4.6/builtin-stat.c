static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + 1000000000L - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static void F_2 ( void )
{
F_3 ( V_7 ) ;
F_4 () ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
if ( V_12 . V_13 )
V_11 -> V_14 = V_15 |
V_16 ;
V_11 -> V_17 = ! V_18 ;
V_11 -> V_19 = 0 ;
if ( ! ( V_20 && V_21 . V_22 . V_23 ) )
V_11 -> V_24 = V_25 ;
if ( F_6 ( V_9 ) ) {
V_11 -> V_26 = 1 ;
if ( F_7 ( & V_27 ) && ! V_28 )
V_11 -> V_29 = 1 ;
}
if ( F_8 ( & V_27 ) )
return F_9 ( V_9 , F_10 ( V_9 ) ) ;
return F_11 ( V_9 , V_7 -> V_30 ) ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
if ( F_13 ( V_9 , V_31 , V_32 ) ||
F_13 ( V_9 , V_31 , V_33 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_38 * T_2 V_35 ,
struct V_39 * V_39 V_35 )
{
if ( F_15 ( & V_21 . V_22 , V_37 , V_37 -> V_40 . V_41 ) < 0 ) {
F_16 ( L_1 ) ;
return - 1 ;
}
V_21 . V_42 += V_37 -> V_40 . V_41 ;
return 0 ;
}
static int F_17 ( T_3 V_43 , T_3 type )
{
return F_18 ( NULL , V_43 , type ,
F_14 ,
NULL ) ;
}
static int
F_19 ( struct V_8 * V_44 , T_4 V_45 , T_4 V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = F_20 ( V_44 , V_45 , V_46 ) ;
return F_21 ( NULL , V_45 , V_46 , V_50 -> V_51 , V_48 ,
F_14 , NULL ) ;
}
static int F_22 ( struct V_8 * V_44 )
{
int V_52 = F_23 ( V_7 -> V_30 ) ;
int V_53 = F_24 ( V_44 ) ;
int V_45 , V_46 ;
if ( ! V_44 -> V_54 )
return - V_55 ;
if ( V_44 -> V_56 )
V_52 = 1 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
struct V_47 * V_48 ;
V_48 = F_25 ( V_44 -> V_57 , V_45 , V_46 ) ;
if ( F_26 ( V_44 , V_45 , V_46 , V_48 ) )
return - 1 ;
if ( V_20 ) {
if ( F_19 ( V_44 , V_45 , V_46 , V_48 ) ) {
F_16 ( L_2 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static void F_27 ( bool V_58 )
{
struct V_8 * V_44 ;
F_28 (evsel_list, counter) {
if ( F_22 ( V_44 ) )
F_29 ( L_3 , V_44 -> V_59 ) ;
if ( F_30 ( & V_12 , V_44 ) )
F_31 ( L_4 , V_44 -> V_59 ) ;
if ( V_58 ) {
F_32 ( V_44 , F_24 ( V_44 ) ,
F_23 ( V_7 -> V_30 ) ) ;
}
}
}
static void F_33 ( void )
{
struct V_1 V_60 , V_61 ;
F_27 ( false ) ;
F_34 ( V_62 , & V_60 ) ;
F_1 ( & V_61 , & V_60 , & V_63 ) ;
if ( V_20 ) {
if ( F_35 ( V_61 . V_5 * V_64 + V_61 . V_6 , V_65 ) )
F_16 ( L_5 ) ;
}
F_36 ( & V_61 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_28 )
F_38 ( V_28 * 1000 ) ;
if ( ! F_7 ( & V_27 ) || V_28 )
F_39 ( V_7 ) ;
}
static void F_40 ( int T_5 V_35 , T_6 * V_66 ,
void * T_7 V_35 )
{
V_67 = V_66 -> V_68 . V_69 ;
}
static bool F_41 ( struct V_8 * V_44 )
{
return V_44 -> V_70 && * V_44 -> V_70 ;
}
static bool F_42 ( struct V_8 * V_44 )
{
return V_44 -> V_13 != 1 ;
}
static int F_43 ( bool V_23 )
{
struct V_8 * V_44 ;
int V_71 ;
if ( V_23 ) {
V_71 = F_44 ( NULL , V_21 . V_72 ,
F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_6 ) ;
return V_71 ;
}
}
F_28 (evsel_list, counter) {
if ( ! V_44 -> V_54 )
continue;
if ( F_41 ( V_44 ) ) {
V_71 = F_45 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_7 ) ;
return V_71 ;
}
}
if ( F_42 ( V_44 ) ) {
V_71 = F_46 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_8 ) ;
return V_71 ;
}
}
if ( V_44 -> V_73 ) {
V_71 = F_47 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_8 ) ;
return V_71 ;
}
}
if ( V_23 ) {
V_71 = F_48 ( NULL , V_44 , F_14 ) ;
if ( V_71 < 0 ) {
F_16 ( L_9 ) ;
return V_71 ;
}
}
}
V_71 = F_49 ( NULL , V_7 -> V_30 ,
F_14 ,
NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_10 ) ;
return V_71 ;
}
V_71 = F_50 ( NULL , V_7 -> V_74 ,
F_14 , NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_10 ) ;
return V_71 ;
}
V_71 = F_51 ( NULL , & V_12 ,
F_14 , NULL ) ;
if ( V_71 < 0 ) {
F_16 ( L_11 ) ;
return V_71 ;
}
return 0 ;
}
static int F_52 ( struct V_8 * V_44 ,
struct V_75 * V_74 ,
struct V_76 * V_30 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_74 -> V_77 ; V_45 ++ ) {
for ( V_46 = 0 ; V_46 < V_30 -> V_77 ; V_46 ++ ) {
int V_78 = F_53 ( V_44 , V_45 , V_46 ) ;
if ( F_54 ( V_7 , V_44 ,
V_45 , V_46 , V_78 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_55 ( struct V_8 * V_44 )
{
struct V_75 * V_74 = V_44 -> V_74 ;
struct V_76 * V_30 = V_44 -> V_30 ;
if ( F_56 ( V_44 , V_74 -> V_77 , V_30 -> V_77 ) )
return - V_79 ;
return F_52 ( V_44 , V_74 , V_30 ) ;
}
static int F_57 ( int V_80 , const char * * V_81 )
{
int V_82 = V_12 . V_82 ;
char V_83 [ 512 ] ;
unsigned long long V_84 , V_85 ;
struct V_8 * V_44 ;
struct V_1 V_60 ;
T_8 V_86 ;
int V_87 = 0 ;
const bool V_88 = ( V_80 > 0 ) ;
bool V_23 = V_20 ? V_21 . V_22 . V_23 : false ;
if ( V_82 ) {
V_60 . V_5 = V_82 / 1000 ;
V_60 . V_6 = ( V_82 % 1000 ) * 1000000 ;
} else {
V_60 . V_5 = 1 ;
V_60 . V_6 = 0 ;
}
if ( V_88 ) {
if ( F_58 ( V_7 , & V_27 , V_81 , V_23 ,
F_40 ) < 0 ) {
perror ( L_12 ) ;
return - 1 ;
}
V_89 = V_7 -> V_90 . V_91 ;
}
if ( V_92 )
F_59 ( V_7 ) ;
F_28 (evsel_list, counter) {
V_93:
if ( F_5 ( V_44 ) < 0 ) {
if ( V_94 == V_95 || V_94 == V_96 ||
V_94 == V_55 || V_94 == V_97 ||
V_94 == V_98 ) {
if ( V_99 )
F_60 ( L_13 ,
F_61 ( V_44 ) ) ;
V_44 -> V_54 = false ;
if ( ( V_44 -> V_100 != V_44 ) ||
! ( V_44 -> V_100 -> V_101 > 1 ) )
continue;
} else if ( F_62 ( V_44 , V_94 , V_83 , sizeof( V_83 ) ) ) {
if ( V_99 )
F_60 ( L_14 , V_83 ) ;
goto V_93;
}
F_63 ( V_44 , & V_27 ,
V_94 , V_83 , sizeof( V_83 ) ) ;
F_64 ( L_14 , V_83 ) ;
if ( V_89 != - 1 )
F_65 ( V_89 , V_102 ) ;
return - 1 ;
}
V_44 -> V_54 = true ;
V_86 = strlen ( V_44 -> V_70 ) ;
if ( V_86 > V_103 )
V_103 = V_86 ;
if ( V_20 && F_55 ( V_44 ) )
return - 1 ;
}
if ( F_66 ( V_7 , & V_44 ) ) {
error ( L_15 ,
V_44 -> V_104 , F_61 ( V_44 ) , V_94 ,
F_67 ( V_94 , V_83 , sizeof( V_83 ) ) ) ;
return - 1 ;
}
if ( V_20 ) {
int V_71 , V_78 = F_68 ( & V_21 . V_22 ) ;
if ( V_23 ) {
V_71 = F_69 ( F_68 ( & V_21 . V_22 ) ) ;
} else {
V_71 = F_70 ( V_21 . V_72 , V_7 ,
V_78 , false ) ;
}
if ( V_71 < 0 )
return V_71 ;
V_71 = F_43 ( V_23 ) ;
if ( V_71 < 0 )
return V_71 ;
}
V_84 = F_71 () ;
F_34 ( V_62 , & V_63 ) ;
if ( V_88 ) {
F_72 ( V_7 ) ;
F_37 () ;
if ( V_82 ) {
while ( ! F_73 ( V_89 , & V_87 , V_105 ) ) {
F_74 ( & V_60 , NULL ) ;
F_33 () ;
}
}
F_75 ( & V_87 ) ;
if ( V_67 ) {
const char * V_106 = F_67 ( V_67 , V_83 , sizeof( V_83 ) ) ;
F_16 ( L_16 , V_106 ) ;
return - 1 ;
}
if ( F_76 ( V_87 ) )
F_77 ( F_78 ( V_87 ) , V_81 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_107 ) {
F_74 ( & V_60 , NULL ) ;
if ( V_82 )
F_33 () ;
}
}
V_85 = F_71 () ;
F_79 ( & V_108 , V_85 - V_84 ) ;
F_27 ( true ) ;
return F_80 ( V_87 ) ;
}
static int F_81 ( int V_80 , const char * * V_81 )
{
int V_109 ;
if ( V_110 ) {
V_109 = system ( V_110 ) ;
if ( V_109 )
return V_109 ;
}
if ( V_111 )
F_82 () ;
V_109 = F_57 ( V_80 , V_81 ) ;
if ( V_109 )
return V_109 ;
if ( V_112 ) {
V_109 = system ( V_112 ) ;
if ( V_109 )
return V_109 ;
}
return V_109 ;
}
static void F_83 ( T_3 V_113 , T_3 V_114 )
{
if ( V_115 ) {
fprintf ( V_12 . V_116 , L_17 V_117 L_18 ,
V_118 ,
V_113 ,
V_118 ,
V_114 ? 100.0 * V_113 / V_114 : 100.0 ) ;
} else if ( V_113 != V_114 ) {
fprintf ( V_12 . V_116 , L_19 , 100.0 * V_113 / V_114 ) ;
}
}
static void F_84 ( double V_119 , double V_120 )
{
double V_121 = F_85 ( V_119 , V_120 ) ;
if ( V_115 )
fprintf ( V_12 . V_116 , L_20 , V_118 , V_121 ) ;
else if ( V_121 )
fprintf ( V_12 . V_116 , L_21 , V_121 ) ;
}
static void F_86 ( struct V_8 * V_9 , double V_120 )
{
struct V_122 * V_123 ;
if ( V_124 == 1 )
return;
V_123 = V_9 -> V_125 ;
F_84 ( F_87 ( & V_123 -> V_126 [ 0 ] ) , V_120 ) ;
}
static void F_88 ( struct V_8 * V_9 , int V_51 , int V_77 )
{
switch ( V_12 . V_127 ) {
case V_128 :
fprintf ( V_12 . V_116 , L_22 ,
F_89 ( V_51 ) ,
V_115 ? 0 : - 8 ,
F_90 ( V_51 ) ,
V_118 ,
V_115 ? 0 : 4 ,
V_77 ,
V_118 ) ;
break;
case V_129 :
fprintf ( V_12 . V_116 , L_23 ,
V_115 ? 0 : - 5 ,
V_51 ,
V_118 ,
V_115 ? 0 : 4 ,
V_77 ,
V_118 ) ;
break;
case V_130 :
fprintf ( V_12 . V_116 , L_24 ,
V_115 ? 0 : - 4 ,
F_10 ( V_9 ) -> V_131 [ V_51 ] , V_118 ) ;
break;
case V_132 :
fprintf ( V_12 . V_116 , L_25 ,
V_115 ? 0 : 16 ,
F_91 ( V_9 -> V_30 , V_51 ) ,
V_115 ? 0 : - 8 ,
F_92 ( V_9 -> V_30 , V_51 ) ,
V_118 ) ;
break;
case V_133 :
case V_134 :
default:
break;
}
}
static void F_93 ( void * V_135 )
{
struct V_136 * V_137 = V_135 ;
V_137 -> V_138 = true ;
}
static void F_94 ( struct V_136 * V_137 )
{
fputc ( '\n' , V_137 -> V_139 ) ;
fputs ( V_137 -> V_140 , V_137 -> V_139 ) ;
F_88 ( V_137 -> V_9 , V_137 -> V_51 , V_137 -> V_77 ) ;
if ( V_12 . V_127 == V_130 )
fprintf ( V_137 -> V_139 , L_26 ) ;
fprintf ( V_137 -> V_139 , L_27 ) ;
}
static void F_95 ( void * V_135 , const char * V_141 , const char * V_142 ,
const char * V_70 , double V_143 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_144 = V_137 -> V_139 ;
int V_145 ;
bool V_138 = V_137 -> V_138 ;
V_137 -> V_138 = false ;
if ( V_70 == NULL || V_142 == NULL ) {
fprintf ( V_144 , L_28 , V_146 , L_29 ) ;
return;
}
if ( V_138 )
F_94 ( V_137 ) ;
V_145 = fprintf ( V_144 , L_30 ) ;
if ( V_141 )
V_145 += F_96 ( V_144 , V_141 , V_142 , V_143 ) ;
else
V_145 += fprintf ( V_144 , V_142 , V_143 ) ;
fprintf ( V_144 , L_31 , V_146 - V_145 - 1 , V_70 ) ;
}
static void F_97 ( void * V_135 )
{
struct V_136 * V_137 = V_135 ;
int V_147 ;
fputc ( '\n' , V_137 -> V_139 ) ;
if ( V_137 -> V_140 )
fprintf ( V_137 -> V_139 , L_32 , V_137 -> V_140 , V_118 ) ;
F_88 ( V_137 -> V_9 , V_137 -> V_51 , V_137 -> V_77 ) ;
for ( V_147 = 0 ; V_147 < V_137 -> V_148 ; V_147 ++ )
fputs ( V_118 , V_137 -> V_139 ) ;
}
static void F_98 ( void * V_135 ,
const char * V_141 V_35 ,
const char * V_142 , const char * V_70 , double V_143 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_144 = V_137 -> V_139 ;
char V_149 [ 64 ] , * V_150 , * V_151 ;
if ( V_70 == NULL || V_142 == NULL ) {
fprintf ( V_144 , L_33 , V_118 , V_118 , V_118 , V_118 ) ;
return;
}
snprintf ( V_149 , sizeof( V_149 ) , V_142 , V_143 ) ;
V_150 = V_149 ;
while ( isspace ( * V_150 ) )
V_150 ++ ;
V_151 = V_150 ;
while ( isdigit ( * V_151 ) || * V_151 == '.' )
V_151 ++ ;
* V_151 = 0 ;
while ( isspace ( * V_70 ) )
V_70 ++ ;
fprintf ( V_144 , L_33 , V_118 , V_150 , V_118 , V_70 ) ;
}
static bool F_99 ( const char * V_70 )
{
if ( ! V_70 )
return false ;
if ( strstr ( V_70 , L_34 ) ||
strstr ( V_70 , L_35 ) ||
strstr ( V_70 , L_36 ) ||
strstr ( V_70 , L_37 ) )
return false ;
return true ;
}
static const char * F_100 ( char * V_149 , struct V_8 * V_9 ,
const char * V_70 )
{
if ( ! strncmp ( V_70 , L_38 , 6 ) ) {
snprintf ( V_149 , 1024 , L_39 , F_61 ( V_9 ) ,
V_70 ) ;
return V_149 ;
}
return V_70 ;
}
static void F_101 ( void * V_135 , const char * V_141 , const char * V_142 ,
const char * V_70 , double V_143 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_144 = V_137 -> V_139 ;
int V_145 ;
char V_149 [ 1024 ] ;
unsigned V_152 = V_153 ;
if ( ! F_99 ( V_70 ) )
return;
V_70 = F_100 ( V_149 , V_137 -> V_9 , V_70 ) ;
if ( V_141 )
V_145 = F_96 ( V_144 , V_141 , V_142 , V_143 ) ;
else
V_145 = fprintf ( V_144 , V_142 , V_143 ) ;
if ( V_145 > V_153 )
V_145 = V_153 ;
if ( V_152 < strlen ( V_70 ) )
V_152 = strlen ( V_70 ) + 1 ;
fprintf ( V_144 , L_40 , V_152 - V_145 , L_29 ) ;
}
static void F_102 ( void * V_135 , const char * V_141 V_35 ,
const char * V_142 ,
const char * V_70 , double V_143 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_144 = V_137 -> V_139 ;
char V_149 [ 64 ] , * V_150 , * V_151 ;
char V_154 [ 1024 ] ;
if ( ! F_99 ( V_70 ) )
return;
V_70 = F_100 ( V_154 , V_137 -> V_9 , V_70 ) ;
snprintf ( V_149 , sizeof V_149 , V_142 , V_143 ) ;
V_150 = V_149 ;
while ( isspace ( * V_150 ) )
V_150 ++ ;
V_151 = V_150 ;
while ( isdigit ( * V_151 ) || * V_151 == '.' )
V_151 ++ ;
* V_151 = 0 ;
fprintf ( V_144 , L_32 , V_150 , V_118 ) ;
}
static void F_103 ( void * V_135 V_35 )
{
}
static void F_104 ( void * V_135 , const char * V_141 V_35 ,
const char * V_142 V_35 ,
const char * V_70 , double V_143 V_35 )
{
struct V_136 * V_137 = V_135 ;
char V_154 [ 1024 ] ;
if ( ! F_99 ( V_70 ) )
return;
V_70 = F_100 ( V_154 , V_137 -> V_9 , V_70 ) ;
if ( V_115 )
fprintf ( V_137 -> V_139 , L_32 , V_70 , V_118 ) ;
else
fprintf ( V_137 -> V_139 , L_41 , V_153 , V_70 ) ;
}
static void F_105 ( int V_51 , int V_77 , struct V_8 * V_9 , double V_120 )
{
T_9 * V_116 = V_12 . V_116 ;
double V_155 = V_120 / 1e6 ;
const char * V_156 , * V_157 ;
char V_59 [ 25 ] ;
V_156 = V_115 ? L_42 : L_43 ;
V_157 = V_115 ? L_44 : L_45 ;
F_88 ( V_9 , V_51 , V_77 ) ;
F_106 ( V_59 , sizeof( V_59 ) , L_32 ,
F_61 ( V_9 ) , V_115 ? L_29 : L_46 ) ;
fprintf ( V_116 , V_156 , V_155 , V_118 ) ;
if ( V_115 )
fprintf ( V_116 , L_32 , V_9 -> V_70 , V_118 ) ;
else
fprintf ( V_116 , L_47 , V_103 , V_9 -> V_70 , V_118 ) ;
fprintf ( V_116 , V_157 , V_59 ) ;
if ( V_9 -> V_158 )
fprintf ( V_116 , L_32 , V_118 , V_9 -> V_158 -> V_59 ) ;
}
static int F_107 ( struct V_8 * V_9 , int V_51 )
{
int V_147 ;
if ( ! V_159 )
return 0 ;
if ( V_12 . V_127 == V_130 )
return V_51 ;
if ( V_12 . V_127 == V_133 )
return 0 ;
for ( V_147 = 0 ; V_147 < F_24 ( V_9 ) ; V_147 ++ ) {
int V_160 = F_10 ( V_9 ) -> V_131 [ V_147 ] ;
if ( V_159 ( V_7 -> V_74 , V_160 ) == V_51 )
return V_160 ;
}
return 0 ;
}
static void F_108 ( int V_51 , int V_77 , struct V_8 * V_9 , double V_120 )
{
T_9 * V_116 = V_12 . V_116 ;
double V_161 = V_9 -> V_13 ;
const char * V_142 ;
if ( V_115 ) {
V_142 = V_161 != 1.0 ? L_48 : L_49 ;
} else {
if ( V_162 )
V_142 = V_161 != 1.0 ? L_50 : L_51 ;
else
V_142 = V_161 != 1.0 ? L_52 : L_53 ;
}
F_88 ( V_9 , V_51 , V_77 ) ;
fprintf ( V_116 , V_142 , V_120 , V_118 ) ;
if ( V_9 -> V_70 )
fprintf ( V_116 , L_47 ,
V_115 ? 0 : V_103 ,
V_9 -> V_70 , V_118 ) ;
fprintf ( V_116 , L_28 , V_115 ? 0 : 25 , F_61 ( V_9 ) ) ;
if ( V_9 -> V_158 )
fprintf ( V_116 , L_32 , V_118 , V_9 -> V_158 -> V_59 ) ;
}
static void F_109 ( int V_51 , int V_77 , struct V_8 * V_44 , double V_163 ,
char * V_140 , T_3 V_113 , T_3 V_114 , double V_164 )
{
struct V_165 V_144 ;
struct V_136 V_137 = {
. V_139 = V_12 . V_116 ,
. V_140 = V_140 ? V_140 : L_29 ,
. V_51 = V_51 ,
. V_77 = V_77 ,
. V_9 = V_44 ,
} ;
T_10 V_166 = F_95 ;
void (* F_110)( void * );
if ( V_167 ) {
F_110 = F_103 ;
if ( V_115 )
V_166 = F_102 ;
else
V_166 = F_101 ;
} else
F_110 = F_93 ;
if ( V_115 && ! V_167 ) {
static int V_168 [] = {
[ V_133 ] = 0 ,
[ V_132 ] = 1 ,
[ V_130 ] = 1 ,
[ V_129 ] = 2 ,
[ V_128 ] = 2 ,
} ;
V_166 = F_98 ;
F_110 = F_97 ;
V_137 . V_148 = 3 ;
V_137 . V_148 += V_168 [ V_12 . V_127 ] ;
if ( V_44 -> V_158 )
V_137 . V_148 ++ ;
}
if ( V_113 == 0 || V_114 == 0 || V_44 -> V_57 -> V_169 == - 1 ) {
if ( V_167 ) {
V_166 ( & V_137 , NULL , L_29 , L_29 , 0 ) ;
return;
}
F_88 ( V_44 , V_51 , V_77 ) ;
fprintf ( V_12 . V_116 , L_54 ,
V_115 ? 0 : 18 ,
V_44 -> V_54 ? V_170 : V_171 ,
V_118 ) ;
fprintf ( V_12 . V_116 , L_47 ,
V_115 ? 0 : V_103 ,
V_44 -> V_70 , V_118 ) ;
fprintf ( V_12 . V_116 , L_40 ,
V_115 ? 0 : - 25 ,
F_61 ( V_44 ) ) ;
if ( V_44 -> V_158 )
fprintf ( V_12 . V_116 , L_32 ,
V_118 , V_44 -> V_158 -> V_59 ) ;
if ( ! V_115 )
V_166 ( & V_137 , NULL , NULL , L_29 , 0 ) ;
F_86 ( V_44 , V_164 ) ;
F_83 ( V_113 , V_114 ) ;
if ( V_115 )
V_166 ( & V_137 , NULL , NULL , L_29 , 0 ) ;
return;
}
if ( V_167 )
;
else if ( F_12 ( V_44 ) )
F_105 ( V_51 , V_77 , V_44 , V_163 ) ;
else
F_108 ( V_51 , V_77 , V_44 , V_163 ) ;
V_144 . V_172 = V_166 ;
V_144 . V_173 = F_110 ;
V_144 . V_135 = & V_137 ;
if ( V_115 && ! V_167 ) {
F_86 ( V_44 , V_164 ) ;
F_83 ( V_113 , V_114 ) ;
}
F_111 ( V_44 , V_163 ,
F_107 ( V_44 , V_51 ) ,
& V_144 ) ;
if ( ! V_115 && ! V_167 ) {
F_86 ( V_44 , V_164 ) ;
F_83 ( V_113 , V_114 ) ;
}
}
static void F_112 ( void )
{
int V_45 , V_174 , V_51 , V_175 ;
T_3 V_143 ;
struct V_8 * V_44 ;
for ( V_175 = 0 ; V_175 < V_176 -> V_77 ; V_175 ++ ) {
V_51 = V_176 -> V_131 [ V_175 ] ;
F_28 (evsel_list, counter) {
V_143 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_174 = V_159 ( V_7 -> V_74 , V_45 ) ;
if ( V_174 != V_51 )
continue;
V_143 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_143 ;
}
V_143 = V_143 * V_44 -> V_13 ;
F_113 ( V_44 , & V_143 ,
F_107 ( V_44 , V_51 ) ) ;
}
}
}
static void F_114 ( char * V_140 )
{
T_9 * V_116 = V_12 . V_116 ;
struct V_8 * V_44 ;
int V_45 , V_175 , V_174 , V_51 , V_77 ;
double V_163 ;
T_3 V_114 , V_113 , V_143 ;
bool V_177 ;
if ( ! ( V_176 || V_159 ) )
return;
F_112 () ;
for ( V_175 = 0 ; V_175 < V_176 -> V_77 ; V_175 ++ ) {
if ( V_140 && V_167 )
fprintf ( V_116 , L_44 , V_140 ) ;
V_51 = V_176 -> V_131 [ V_175 ] ;
V_177 = true ;
F_28 (evsel_list, counter) {
V_143 = V_114 = V_113 = 0 ;
V_77 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_174 = V_159 ( F_10 ( V_44 ) , V_45 ) ;
if ( V_174 != V_51 )
continue;
V_143 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_143 ;
V_114 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_114 ;
V_113 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_113 ;
V_77 ++ ;
}
if ( V_177 && V_167 ) {
V_177 = false ;
F_88 ( V_44 , V_51 , V_77 ) ;
}
if ( V_140 && ! V_167 )
fprintf ( V_116 , L_44 , V_140 ) ;
V_163 = V_143 * V_44 -> V_13 ;
F_109 ( V_51 , V_77 , V_44 , V_163 , V_140 , V_113 , V_114 , 1.0 ) ;
if ( ! V_167 )
fputc ( '\n' , V_116 ) ;
}
if ( V_167 )
fputc ( '\n' , V_116 ) ;
}
}
static void F_115 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_116 = V_12 . V_116 ;
int V_52 = F_23 ( V_44 -> V_30 ) ;
int V_53 = F_116 ( V_44 -> V_74 ) ;
int V_45 , V_46 ;
double V_163 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
T_3 V_114 = 0 , V_113 = 0 , V_143 = 0 ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
V_143 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_143 ;
V_114 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_114 ;
V_113 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_113 ;
}
if ( V_140 )
fprintf ( V_116 , L_44 , V_140 ) ;
V_163 = V_143 * V_44 -> V_13 ;
F_109 ( V_46 , 0 , V_44 , V_163 , V_140 , V_113 , V_114 , 1.0 ) ;
fputc ( '\n' , V_116 ) ;
}
}
static void F_117 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_116 = V_12 . V_116 ;
struct V_122 * V_123 = V_44 -> V_125 ;
double V_120 = F_118 ( & V_123 -> V_126 [ 0 ] ) ;
double V_163 ;
double V_178 , V_179 ;
V_178 = F_118 ( & V_123 -> V_126 [ 1 ] ) ;
V_179 = F_118 ( & V_123 -> V_126 [ 2 ] ) ;
if ( V_140 && ! V_167 )
fprintf ( V_116 , L_44 , V_140 ) ;
V_163 = V_120 * V_44 -> V_13 ;
F_109 ( - 1 , 0 , V_44 , V_163 , V_140 , V_179 , V_178 , V_120 ) ;
if ( ! V_167 )
fprintf ( V_116 , L_55 ) ;
}
static void F_119 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_116 = V_12 . V_116 ;
T_3 V_114 , V_113 , V_143 ;
double V_163 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_143 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_143 ;
V_114 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_114 ;
V_113 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_113 ;
if ( V_140 )
fprintf ( V_116 , L_44 , V_140 ) ;
V_163 = V_143 * V_44 -> V_13 ;
F_109 ( V_45 , 0 , V_44 , V_163 , V_140 , V_113 , V_114 , 1.0 ) ;
fputc ( '\n' , V_116 ) ;
}
}
static void F_120 ( char * V_140 )
{
int V_45 ;
int V_180 = 0 ;
struct V_8 * V_44 ;
T_3 V_114 , V_113 , V_143 ;
double V_163 ;
V_180 = V_7 -> V_74 -> V_77 ;
for ( V_45 = 0 ; V_45 < V_180 ; V_45 ++ ) {
bool V_177 = true ;
if ( V_140 )
fputs ( V_140 , V_12 . V_116 ) ;
F_28 (evsel_list, counter) {
if ( V_177 ) {
F_88 ( V_44 , V_45 , 0 ) ;
V_177 = false ;
}
V_143 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_143 ;
V_114 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_114 ;
V_113 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_113 ;
V_163 = V_143 * V_44 -> V_13 ;
F_109 ( V_45 , 0 , V_44 , V_163 , V_140 , V_113 , V_114 , 1.0 ) ;
}
fputc ( '\n' , V_12 . V_116 ) ;
}
}
static void F_121 ( char * V_140 )
{
struct V_165 V_144 ;
struct V_8 * V_44 ;
struct V_136 V_137 = {
. V_139 = V_12 . V_116
} ;
if ( V_140 )
fprintf ( V_12 . V_116 , L_44 , V_140 ) ;
if ( ! V_115 )
fprintf ( V_12 . V_116 , L_40 ,
V_181 [ V_12 . V_127 ] , L_29 ) ;
F_28 (evsel_list, counter) {
V_137 . V_9 = V_44 ;
V_144 . V_135 = & V_137 ;
V_144 . V_172 = F_104 ;
V_144 . V_173 = F_103 ;
V_137 . V_9 = V_44 ;
F_111 ( V_44 , 0 ,
0 ,
& V_144 ) ;
}
fputc ( '\n' , V_12 . V_116 ) ;
}
static void F_122 ( char * V_140 , struct V_1 * V_60 )
{
T_9 * V_116 = V_12 . V_116 ;
static int V_182 ;
sprintf ( V_140 , L_56 , V_60 -> V_5 , V_60 -> V_6 , V_118 ) ;
if ( V_182 == 0 && ! V_115 && ! V_167 ) {
switch ( V_12 . V_127 ) {
case V_129 :
fprintf ( V_116 , L_57 , V_103 , L_58 ) ;
break;
case V_128 :
fprintf ( V_116 , L_59 , V_103 , L_58 ) ;
break;
case V_130 :
fprintf ( V_116 , L_60 , V_103 , L_58 ) ;
break;
case V_132 :
fprintf ( V_116 , L_61 , V_103 , L_58 ) ;
break;
case V_133 :
default:
fprintf ( V_116 , L_62 , V_103 , L_58 ) ;
case V_134 :
break;
}
}
if ( ++ V_182 == 25 )
V_182 = 0 ;
}
static void F_123 ( int V_80 , const char * * V_81 )
{
T_9 * V_116 = V_12 . V_116 ;
int V_147 ;
fflush ( stdout ) ;
if ( ! V_115 ) {
fprintf ( V_116 , L_55 ) ;
fprintf ( V_116 , L_63 ) ;
if ( V_27 . V_56 )
fprintf ( V_116 , L_64 ) ;
else if ( V_27 . V_183 )
fprintf ( V_116 , L_65 , V_27 . V_183 ) ;
else if ( ! F_124 ( & V_27 ) ) {
fprintf ( V_116 , L_66 , V_81 ? V_81 [ 0 ] : L_67 ) ;
for ( V_147 = 1 ; V_81 && ( V_147 < V_80 ) ; V_147 ++ )
fprintf ( V_116 , L_68 , V_81 [ V_147 ] ) ;
} else if ( V_27 . V_91 )
fprintf ( V_116 , L_69 , V_27 . V_91 ) ;
else
fprintf ( V_116 , L_70 , V_27 . V_184 ) ;
fprintf ( V_116 , L_71 ) ;
if ( V_124 > 1 )
fprintf ( V_116 , L_72 , V_124 ) ;
fprintf ( V_116 , L_73 ) ;
}
}
static void F_125 ( void )
{
T_9 * V_116 = V_12 . V_116 ;
if ( ! V_185 )
fprintf ( V_116 , L_55 ) ;
fprintf ( V_116 , L_74 ,
F_118 ( & V_108 ) / 1e9 ) ;
if ( V_124 > 1 ) {
fprintf ( V_116 , L_75 ) ;
F_84 ( F_87 ( & V_108 ) ,
F_118 ( & V_108 ) ) ;
}
fprintf ( V_116 , L_76 ) ;
}
static void F_36 ( struct V_1 * V_60 , int V_80 , const char * * V_81 )
{
int V_82 = V_12 . V_82 ;
struct V_8 * V_44 ;
char V_149 [ 64 ] , * V_140 = NULL ;
if ( V_20 && V_21 . V_22 . V_23 )
return;
if ( V_82 )
F_122 ( V_140 = V_149 , V_60 ) ;
else
F_123 ( V_80 , V_81 ) ;
if ( V_167 ) {
static int V_186 ;
if ( V_186 == 0 )
F_121 ( V_140 ) ;
if ( V_186 ++ == 25 )
V_186 = 0 ;
if ( V_12 . V_127 == V_133 && V_140 )
fprintf ( V_12 . V_116 , L_44 , V_140 ) ;
}
switch ( V_12 . V_127 ) {
case V_128 :
case V_129 :
F_114 ( V_140 ) ;
break;
case V_132 :
F_28 (evsel_list, counter)
F_115 ( V_44 , V_140 ) ;
break;
case V_133 :
F_28 (evsel_list, counter)
F_117 ( V_44 , V_140 ) ;
if ( V_167 )
fputc ( '\n' , V_12 . V_116 ) ;
break;
case V_130 :
if ( V_167 )
F_120 ( V_140 ) ;
else {
F_28 (evsel_list, counter)
F_119 ( V_44 , V_140 ) ;
}
break;
case V_134 :
default:
break;
}
if ( ! V_82 && ! V_115 )
F_125 () ;
fflush ( V_12 . V_116 ) ;
}
static void F_126 ( int T_5 )
{
if ( ( V_89 == - 1 ) || V_12 . V_82 )
V_107 = 1 ;
V_187 = T_5 ;
V_89 = - 1 ;
}
static void F_127 ( void )
{
T_11 V_188 , V_189 ;
F_128 ( & V_188 ) ;
F_129 ( & V_188 , V_190 ) ;
F_130 ( V_191 , & V_188 , & V_189 ) ;
if ( V_89 != - 1 )
F_65 ( V_89 , V_102 ) ;
F_130 ( V_192 , & V_189 , NULL ) ;
if ( V_187 == - 1 )
return;
signal ( V_187 , V_193 ) ;
F_65 ( F_131 () , V_187 ) ;
}
static int F_132 ( const struct V_194 * T_12 V_35 ,
const char * V_175 V_35 , int V_195 )
{
V_196 = V_195 ? 0 : 1 ;
return 0 ;
}
static int F_133 ( struct V_75 * V_131 , int V_45 )
{
return F_134 ( V_131 , V_45 , NULL ) ;
}
static int F_135 ( struct V_75 * V_131 , int V_45 )
{
return F_136 ( V_131 , V_45 , NULL ) ;
}
static int F_137 ( struct V_75 * V_131 )
{
int V_147 , V_197 = - 1 ;
for ( V_147 = 0 ; V_147 < V_131 -> V_77 ; V_147 ++ ) {
if ( V_131 -> V_131 [ V_147 ] > V_197 )
V_197 = V_131 -> V_131 [ V_147 ] ;
}
return V_197 ;
}
static int F_138 ( T_13 V_198 , struct V_75 * V_131 , int V_199 )
{
int V_45 ;
if ( V_199 >= V_131 -> V_77 )
return - 1 ;
V_45 = V_131 -> V_131 [ V_199 ] ;
if ( V_200 -> V_131 [ V_45 ] == - 1 )
V_200 -> V_131 [ V_45 ] = V_198 ( V_131 , V_199 ) ;
return V_200 -> V_131 [ V_45 ] ;
}
static int F_139 ( struct V_75 * V_131 , int V_199 )
{
return F_138 ( F_133 , V_131 , V_199 ) ;
}
static int F_140 ( struct V_75 * V_131 , int V_199 )
{
return F_138 ( F_135 , V_131 , V_199 ) ;
}
static int F_141 ( void )
{
int V_77 ;
switch ( V_12 . V_127 ) {
case V_129 :
if ( F_142 ( V_7 -> V_74 , & V_176 ) ) {
perror ( L_77 ) ;
return - 1 ;
}
V_159 = F_139 ;
break;
case V_128 :
if ( F_143 ( V_7 -> V_74 , & V_176 ) ) {
perror ( L_78 ) ;
return - 1 ;
}
V_159 = F_140 ;
break;
case V_130 :
case V_133 :
case V_132 :
case V_134 :
default:
break;
}
V_77 = F_137 ( V_7 -> V_74 ) ;
V_200 = F_144 ( V_77 + 1 ) ;
return V_200 ? 0 : - V_79 ;
}
static void F_145 ( void )
{
F_146 ( V_176 ) ;
F_146 ( V_200 ) ;
V_176 = NULL ;
V_200 = NULL ;
}
static inline int F_147 ( struct V_201 * V_202 , struct V_75 * V_131 , int V_199 )
{
int V_45 ;
if ( V_199 > V_131 -> V_77 )
return - 1 ;
V_45 = V_131 -> V_131 [ V_199 ] ;
if ( V_45 >= V_202 -> V_203 )
return - 1 ;
return V_45 ;
}
static int F_148 ( struct V_75 * V_131 , int V_199 , void * V_204 )
{
struct V_201 * V_202 = V_204 ;
int V_45 = F_147 ( V_202 , V_131 , V_199 ) ;
return V_45 == - 1 ? - 1 : V_202 -> V_45 [ V_45 ] . V_205 ;
}
static int F_149 ( struct V_75 * V_131 , int V_199 , void * V_204 )
{
struct V_201 * V_202 = V_204 ;
int V_206 = - 1 , V_45 = F_147 ( V_202 , V_131 , V_199 ) ;
if ( V_45 != - 1 ) {
int V_205 = V_202 -> V_45 [ V_45 ] . V_205 ;
V_206 = ( V_205 << 16 ) | ( V_202 -> V_45 [ V_45 ] . V_207 & 0xffff ) ;
}
return V_206 ;
}
static int F_150 ( struct V_201 * V_202 , struct V_75 * V_74 ,
struct V_75 * * V_208 )
{
return F_151 ( V_74 , V_208 , F_148 , V_202 ) ;
}
static int F_152 ( struct V_201 * V_202 , struct V_75 * V_74 ,
struct V_75 * * V_209 )
{
return F_151 ( V_74 , V_209 , F_149 , V_202 ) ;
}
static int F_153 ( struct V_75 * V_131 , int V_199 )
{
return F_148 ( V_131 , V_199 , & V_21 . V_72 -> V_40 . V_202 ) ;
}
static int F_154 ( struct V_75 * V_131 , int V_199 )
{
return F_149 ( V_131 , V_199 , & V_21 . V_72 -> V_40 . V_202 ) ;
}
static int F_155 ( struct V_21 * V_210 )
{
struct V_201 * V_202 = & V_210 -> V_72 -> V_40 . V_202 ;
switch ( V_12 . V_127 ) {
case V_129 :
if ( F_150 ( V_202 , V_7 -> V_74 , & V_176 ) ) {
perror ( L_77 ) ;
return - 1 ;
}
V_159 = F_153 ;
break;
case V_128 :
if ( F_152 ( V_202 , V_7 -> V_74 , & V_176 ) ) {
perror ( L_78 ) ;
return - 1 ;
}
V_159 = F_154 ;
break;
case V_130 :
case V_133 :
case V_132 :
case V_134 :
default:
break;
}
return 0 ;
}
static int F_156 ( void )
{
struct V_10 V_211 [] = {
{ . type = V_212 , . V_213 = V_214 } ,
{ . type = V_212 , . V_213 = V_215 } ,
{ . type = V_212 , . V_213 = V_216 } ,
{ . type = V_212 , . V_213 = V_217 } ,
{ . type = V_218 , . V_213 = V_219 } ,
} ;
struct V_10 V_220 [] = {
{ . type = V_218 , . V_213 = V_221 } ,
} ;
struct V_10 V_222 [] = {
{ . type = V_218 , . V_213 = V_223 } ,
} ;
struct V_10 V_224 [] = {
{ . type = V_218 , . V_213 = V_225 } ,
{ . type = V_218 , . V_213 = V_226 } ,
{ . type = V_218 , . V_213 = V_227 } ,
} ;
struct V_10 V_228 [] = {
{ . type = V_229 ,
. V_213 =
V_230 << 0 |
( V_231 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_230 << 0 |
( V_231 << 8 ) |
( V_233 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_234 << 0 |
( V_231 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_234 << 0 |
( V_231 << 8 ) |
( V_233 << 16 ) } ,
} ;
struct V_10 V_235 [] = {
{ . type = V_229 ,
. V_213 =
V_236 << 0 |
( V_231 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_236 << 0 |
( V_231 << 8 ) |
( V_233 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_237 << 0 |
( V_231 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_237 << 0 |
( V_231 << 8 ) |
( V_233 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_238 << 0 |
( V_231 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_238 << 0 |
( V_231 << 8 ) |
( V_233 << 16 ) } ,
} ;
struct V_10 V_239 [] = {
{ . type = V_229 ,
. V_213 =
V_230 << 0 |
( V_240 << 8 ) |
( V_232 << 16 ) } ,
{ . type = V_229 ,
. V_213 =
V_230 << 0 |
( V_240 << 8 ) |
( V_233 << 16 ) } ,
} ;
if ( V_185 )
return 0 ;
if ( V_241 ) {
int V_71 ;
if ( F_157 ( L_79 , L_80 ) &&
F_157 ( L_79 , L_81 ) )
V_71 = F_158 ( V_7 , V_242 , NULL ) ;
else
V_71 = F_158 ( V_7 , V_243 , NULL ) ;
if ( V_71 ) {
fprintf ( V_244 , L_82 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_245 ) {
if ( F_159 ( V_7 , V_211 ) < 0 )
return - 1 ;
if ( F_157 ( L_79 , L_83 ) ) {
if ( F_159 ( V_7 ,
V_220 ) < 0 )
return - 1 ;
}
if ( F_157 ( L_79 , L_84 ) ) {
if ( F_159 ( V_7 ,
V_222 ) < 0 )
return - 1 ;
}
if ( F_159 ( V_7 , V_224 ) < 0 )
return - 1 ;
}
if ( V_246 < 1 )
return 0 ;
if ( F_159 ( V_7 , V_228 ) < 0 )
return - 1 ;
if ( V_246 < 2 )
return 0 ;
if ( F_159 ( V_7 , V_235 ) < 0 )
return - 1 ;
if ( V_246 < 3 )
return 0 ;
return F_159 ( V_7 , V_239 ) ;
}
static void F_160 ( struct V_247 * V_72 )
{
int V_248 ;
for ( V_248 = V_249 ; V_248 < V_250 ; V_248 ++ )
F_161 ( & V_72 -> V_40 , V_248 ) ;
F_162 ( & V_72 -> V_40 , V_251 ) ;
F_162 ( & V_72 -> V_40 , V_252 ) ;
F_162 ( & V_72 -> V_40 , V_253 ) ;
F_162 ( & V_72 -> V_40 , V_254 ) ;
}
static int F_163 ( int V_80 , const char * * V_81 )
{
struct V_247 * V_72 ;
struct V_255 * V_22 = & V_21 . V_22 ;
V_80 = F_164 ( V_80 , V_81 , V_256 , V_257 ,
V_258 ) ;
if ( V_259 )
V_22 -> V_260 = V_259 ;
if ( V_124 != 1 || V_261 ) {
F_16 ( L_85 ) ;
return - 1 ;
}
V_72 = F_165 ( V_22 , false , NULL ) ;
if ( V_72 == NULL ) {
F_16 ( L_86 ) ;
return - 1 ;
}
F_160 ( V_72 ) ;
V_72 -> V_262 = V_7 ;
V_21 . V_72 = V_72 ;
V_21 . V_263 = true ;
return V_80 ;
}
static int F_166 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_247 * V_72 )
{
struct V_264 * V_265 = & V_37 -> V_266 ;
struct V_8 * V_44 ;
struct V_1 V_267 , * V_60 = NULL ;
const char * * V_81 = V_72 -> V_40 . V_202 . V_268 ;
int V_80 = V_72 -> V_40 . V_202 . V_269 ;
F_28 (evsel_list, counter)
F_30 ( & V_12 , V_44 ) ;
if ( V_265 -> type == V_270 )
F_79 ( & V_108 , V_265 -> time ) ;
if ( V_12 . V_82 && V_265 -> time ) {
V_267 . V_5 = V_265 -> time / V_64 ;
V_267 . V_6 = V_265 -> time % V_64 ;
V_60 = & V_267 ;
}
F_36 ( V_60 , V_80 , V_81 ) ;
return 0 ;
}
static
int F_167 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_247 * V_72 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
F_169 ( & V_12 , & V_37 -> V_12 ) ;
if ( F_170 ( V_210 -> V_74 ) ) {
if ( V_210 -> V_127 != V_134 )
F_31 ( L_87 ) ;
return 0 ;
}
if ( V_210 -> V_127 != V_134 )
V_12 . V_127 = V_210 -> V_127 ;
if ( V_21 . V_22 . V_23 )
F_141 () ;
else
F_155 ( V_210 ) ;
return 0 ;
}
static int F_171 ( struct V_21 * V_210 )
{
if ( ! V_210 -> V_74 || ! V_210 -> V_30 )
return 0 ;
if ( F_172 ( V_210 -> V_271 , L_88 ) )
return - V_95 ;
F_173 ( V_7 , V_210 -> V_74 , V_210 -> V_30 ) ;
if ( F_174 ( V_7 , true ) )
return - V_79 ;
V_210 -> V_271 = true ;
return 0 ;
}
static
int F_175 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_247 * V_72 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
if ( V_210 -> V_30 ) {
F_31 ( L_89 ) ;
return 0 ;
}
V_210 -> V_30 = F_176 ( & V_37 -> V_76 ) ;
if ( ! V_210 -> V_30 )
return - V_79 ;
return F_171 ( V_210 ) ;
}
static
int F_177 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_247 * V_72 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
struct V_75 * V_74 ;
if ( V_210 -> V_74 ) {
F_31 ( L_90 ) ;
return 0 ;
}
V_74 = F_178 ( & V_37 -> V_75 . V_204 ) ;
if ( ! V_74 )
return - V_79 ;
V_210 -> V_74 = V_74 ;
return F_171 ( V_210 ) ;
}
static int F_179 ( int V_80 , const char * * V_81 )
{
struct V_247 * V_72 ;
const struct V_194 V_272 [] = {
F_180 ( 'i' , L_91 , & V_273 , L_92 , L_93 ) ,
F_181 ( 0 , L_94 , & V_21 . V_127 ,
L_95 , V_129 ) ,
F_181 ( 0 , L_96 , & V_21 . V_127 ,
L_97 , V_128 ) ,
F_181 ( 'A' , L_98 , & V_21 . V_127 ,
L_99 , V_130 ) ,
F_182 ()
} ;
struct V_274 V_210 ;
int V_109 ;
V_80 = F_164 ( V_80 , V_81 , V_272 , V_275 , 0 ) ;
if ( ! V_273 || ! strlen ( V_273 ) ) {
if ( ! F_183 ( V_276 , & V_210 ) && F_184 ( V_210 . V_277 ) )
V_273 = L_100 ;
else
V_273 = L_101 ;
}
V_21 . V_22 . V_260 = V_273 ;
V_21 . V_22 . V_278 = V_279 ;
V_72 = F_165 ( & V_21 . V_22 , false , & V_21 . T_1 ) ;
if ( V_72 == NULL )
return - 1 ;
V_21 . V_72 = V_72 ;
V_12 . V_116 = V_244 ;
V_7 = V_72 -> V_262 ;
V_109 = F_185 ( V_72 ) ;
if ( V_109 )
return V_109 ;
F_186 ( V_72 ) ;
return 0 ;
}
int F_187 ( int V_80 , const char * * V_81 , const char * V_140 V_35 )
{
const char * const V_280 [] = {
L_102 ,
NULL
} ;
int V_87 = - V_95 , V_281 ;
const char * V_278 ;
T_9 * V_116 = V_244 ;
unsigned int V_82 ;
const char * const V_282 [] = { L_103 , L_104 } ;
setlocale ( V_283 , L_29 ) ;
V_7 = F_188 () ;
if ( V_7 == NULL )
return - V_79 ;
F_189 () ;
V_80 = F_190 ( V_80 , V_81 , V_256 , V_282 ,
( const char * * ) V_280 ,
V_258 ) ;
F_191 () ;
if ( V_118 ) {
V_115 = true ;
if ( ! strcmp ( V_118 , L_105 ) )
V_118 = L_106 ;
} else
V_118 = V_284 ;
if ( V_80 && ! strncmp ( V_81 [ 0 ] , L_107 , 3 ) ) {
V_80 = F_163 ( V_80 , V_81 ) ;
if ( V_80 < 0 )
return - 1 ;
} else if ( V_80 && ! strncmp ( V_81 [ 0 ] , L_108 , 3 ) )
return F_179 ( V_80 , V_81 ) ;
V_82 = V_12 . V_82 ;
if ( ! V_20 && V_259 && strcmp ( V_259 , L_100 ) )
V_116 = NULL ;
if ( V_259 && V_285 ) {
fprintf ( V_244 , L_109 ) ;
F_192 ( V_280 , V_256 , L_110 , 1 ) ;
F_192 ( NULL , V_256 , L_111 , 0 ) ;
goto V_144;
}
if ( V_167 && V_12 . V_127 == V_132 ) {
fprintf ( V_244 , L_112 ) ;
goto V_144;
}
if ( V_167 && V_124 > 1 ) {
fprintf ( V_244 , L_113 ) ;
goto V_144;
}
if ( V_285 < 0 ) {
fprintf ( V_244 , L_114 ) ;
F_192 ( V_280 , V_256 , L_111 , 0 ) ;
goto V_144;
}
if ( ! V_116 ) {
struct V_1 V_43 ;
V_278 = V_286 ? L_115 : L_116 ;
V_116 = fopen ( V_259 , V_278 ) ;
if ( ! V_116 ) {
perror ( L_117 ) ;
return - 1 ;
}
F_34 ( V_287 , & V_43 ) ;
fprintf ( V_116 , L_118 , ctime ( & V_43 . V_5 ) ) ;
} else if ( V_285 > 0 ) {
V_278 = V_286 ? L_115 : L_116 ;
V_116 = fdopen ( V_285 , V_278 ) ;
if ( ! V_116 ) {
perror ( L_119 ) ;
return - V_94 ;
}
}
V_12 . V_116 = V_116 ;
if ( V_115 ) {
if ( V_196 == 1 ) {
fprintf ( V_244 , L_120 ) ;
F_192 ( V_280 , V_256 , L_121 , 1 ) ;
F_192 ( NULL , V_256 , L_122 , 1 ) ;
goto V_144;
} else
V_162 = false ;
} else if ( V_196 == 0 )
V_162 = false ;
if ( ! V_80 && F_7 ( & V_27 ) )
F_193 ( V_280 , V_256 ) ;
if ( V_124 < 0 ) {
F_16 ( L_123 ) ;
F_192 ( V_280 , V_256 , L_124 , 1 ) ;
goto V_144;
} else if ( V_124 == 0 ) {
V_261 = true ;
V_124 = 1 ;
}
if ( ( V_12 . V_127 == V_132 ) && ! F_124 ( & V_27 ) ) {
fprintf ( V_244 , L_125
L_126 ) ;
F_192 ( NULL , V_256 , L_127 , 1 ) ;
F_192 ( NULL , V_256 , L_128 , 1 ) ;
goto V_144;
}
if ( ( ( V_12 . V_127 != V_133 &&
V_12 . V_127 != V_132 ) || V_288 ) &&
! F_8 ( & V_27 ) ) {
fprintf ( V_244 , L_129
L_130 ) ;
F_192 ( V_280 , V_256 , L_131 , 1 ) ;
F_192 ( NULL , V_256 , L_132 , 1 ) ;
F_192 ( NULL , V_256 , L_115 , 1 ) ;
goto V_144;
}
if ( F_156 () )
goto V_144;
F_194 ( & V_27 ) ;
if ( F_195 ( V_7 , & V_27 ) < 0 ) {
if ( F_124 ( & V_27 ) ) {
F_16 ( L_133 ) ;
F_192 ( V_280 , V_256 , L_127 , 1 ) ;
F_192 ( NULL , V_256 , L_128 , 1 ) ;
} else if ( F_8 ( & V_27 ) ) {
perror ( L_134 ) ;
F_192 ( V_280 , V_256 , L_135 , 1 ) ;
F_192 ( NULL , V_256 , L_115 , 1 ) ;
}
goto V_144;
}
if ( V_12 . V_127 == V_132 )
F_196 ( V_7 -> V_30 ) ;
if ( V_82 && V_82 < 100 ) {
if ( V_82 < 10 ) {
F_16 ( L_136 ) ;
F_192 ( V_280 , V_256 , L_137 , 1 ) ;
goto V_144;
} else
F_31 ( L_138
L_139
L_140 ) ;
}
if ( F_174 ( V_7 , V_82 ) )
goto V_144;
if ( F_141 () )
goto V_144;
atexit ( F_127 ) ;
if ( ! V_261 )
signal ( V_289 , F_126 ) ;
signal ( V_190 , F_126 ) ;
signal ( V_290 , F_126 ) ;
signal ( V_291 , F_126 ) ;
V_87 = 0 ;
for ( V_281 = 0 ; V_261 || V_281 < V_124 ; V_281 ++ ) {
if ( V_124 != 1 && V_99 )
fprintf ( V_116 , L_141 ,
V_281 + 1 ) ;
V_87 = F_81 ( V_80 , V_81 ) ;
if ( V_261 && V_87 != - 1 ) {
F_36 ( NULL , V_80 , V_81 ) ;
F_2 () ;
}
}
if ( ! V_261 && V_87 != - 1 && ! V_82 )
F_36 ( NULL , V_80 , V_81 ) ;
if ( V_20 ) {
int V_78 = F_68 ( & V_21 . V_22 ) ;
int V_71 = F_197 ( ( void * ) & V_21 ,
F_14 ,
& V_21 . V_72 -> V_292 . V_293 ) ;
if ( V_71 ) {
F_31 ( L_142
L_143 ) ;
}
if ( ! V_82 ) {
if ( F_35 ( V_108 . V_197 , V_294 ) )
F_16 ( L_5 ) ;
}
if ( ! V_21 . V_22 . V_23 ) {
V_21 . V_72 -> V_40 . V_295 += V_21 . V_42 ;
F_70 ( V_21 . V_72 , V_7 , V_78 , true ) ;
}
F_186 ( V_21 . V_72 ) ;
}
F_145 () ;
F_198 ( V_7 ) ;
V_144:
F_199 ( V_7 ) ;
return V_87 ;
}
