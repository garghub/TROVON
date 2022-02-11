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
int V_53 , V_45 , V_46 ;
if ( F_8 ( & V_27 ) )
V_53 = F_24 ( V_44 ) ;
else
V_53 = 1 ;
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
if ( V_58 > 1 ) {
fprintf ( V_12 . V_59 ,
L_3 V_60 L_4 V_60 L_4 V_60 L_5 ,
F_27 ( V_44 ) ,
V_45 ,
V_48 -> V_61 , V_48 -> V_62 , V_48 -> V_63 ) ;
}
}
}
return 0 ;
}
static void F_28 ( void )
{
struct V_8 * V_44 ;
F_29 (evsel_list, counter) {
if ( F_22 ( V_44 ) )
F_30 ( L_6 , V_44 -> V_64 ) ;
if ( F_31 ( & V_12 , V_44 ) )
F_32 ( L_7 , V_44 -> V_64 ) ;
}
}
static void F_33 ( void )
{
struct V_1 V_65 , V_66 ;
F_28 () ;
F_34 ( V_67 , & V_65 ) ;
F_1 ( & V_66 , & V_65 , & V_68 ) ;
if ( V_20 ) {
if ( F_35 ( V_66 . V_5 * V_69 + V_66 . V_6 , V_70 ) )
F_16 ( L_8 ) ;
}
F_36 ( & V_66 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_28 )
F_38 ( V_28 * 1000 ) ;
if ( ! F_7 ( & V_27 ) || V_28 )
F_39 ( V_7 ) ;
}
static void F_40 ( void )
{
if ( ! F_7 ( & V_27 ) )
F_41 ( V_7 ) ;
}
static void F_42 ( int T_5 V_35 , T_6 * V_71 ,
void * T_7 V_35 )
{
V_72 = V_71 -> V_73 . V_74 ;
}
static bool F_43 ( struct V_8 * V_44 )
{
return V_44 -> V_75 && * V_44 -> V_75 ;
}
static bool F_44 ( struct V_8 * V_44 )
{
return V_44 -> V_13 != 1 ;
}
static int F_45 ( bool V_23 )
{
struct V_8 * V_44 ;
int V_76 ;
if ( V_23 ) {
V_76 = F_46 ( NULL , V_21 . V_77 ,
F_14 ) ;
if ( V_76 < 0 ) {
F_16 ( L_9 ) ;
return V_76 ;
}
}
F_29 (evsel_list, counter) {
if ( ! V_44 -> V_54 )
continue;
if ( F_43 ( V_44 ) ) {
V_76 = F_47 ( NULL , V_44 , F_14 ) ;
if ( V_76 < 0 ) {
F_16 ( L_10 ) ;
return V_76 ;
}
}
if ( F_44 ( V_44 ) ) {
V_76 = F_48 ( NULL , V_44 , F_14 ) ;
if ( V_76 < 0 ) {
F_16 ( L_11 ) ;
return V_76 ;
}
}
if ( V_44 -> V_78 ) {
V_76 = F_49 ( NULL , V_44 , F_14 ) ;
if ( V_76 < 0 ) {
F_16 ( L_11 ) ;
return V_76 ;
}
}
if ( V_23 ) {
V_76 = F_50 ( NULL , V_44 , F_14 ) ;
if ( V_76 < 0 ) {
F_16 ( L_12 ) ;
return V_76 ;
}
}
}
V_76 = F_51 ( NULL , V_7 -> V_30 ,
F_14 ,
NULL ) ;
if ( V_76 < 0 ) {
F_16 ( L_13 ) ;
return V_76 ;
}
V_76 = F_52 ( NULL , V_7 -> V_79 ,
F_14 , NULL ) ;
if ( V_76 < 0 ) {
F_16 ( L_13 ) ;
return V_76 ;
}
V_76 = F_53 ( NULL , & V_12 ,
F_14 , NULL ) ;
if ( V_76 < 0 ) {
F_16 ( L_14 ) ;
return V_76 ;
}
return 0 ;
}
static int F_54 ( struct V_8 * V_44 ,
struct V_80 * V_79 ,
struct V_81 * V_30 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_79 -> V_82 ; V_45 ++ ) {
for ( V_46 = 0 ; V_46 < V_30 -> V_82 ; V_46 ++ ) {
int V_83 = F_55 ( V_44 , V_45 , V_46 ) ;
if ( F_56 ( V_7 , V_44 ,
V_45 , V_46 , V_83 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_8 * V_44 )
{
struct V_80 * V_79 = V_44 -> V_79 ;
struct V_81 * V_30 = V_44 -> V_30 ;
if ( F_58 ( V_44 , V_79 -> V_82 , V_30 -> V_82 ) )
return - V_84 ;
return F_54 ( V_44 , V_79 , V_30 ) ;
}
static int F_59 ( int V_85 , const char * * V_86 )
{
int V_87 = V_12 . V_87 ;
char V_88 [ 512 ] ;
unsigned long long V_89 , V_90 ;
struct V_8 * V_44 ;
struct V_1 V_65 ;
T_8 V_91 ;
int V_92 = 0 ;
const bool V_93 = ( V_85 > 0 ) ;
bool V_23 = V_20 ? V_21 . V_22 . V_23 : false ;
if ( V_87 ) {
V_65 . V_5 = V_87 / 1000 ;
V_65 . V_6 = ( V_87 % 1000 ) * 1000000 ;
} else {
V_65 . V_5 = 1 ;
V_65 . V_6 = 0 ;
}
if ( V_93 ) {
if ( F_60 ( V_7 , & V_27 , V_86 , V_23 ,
F_42 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_94 = V_7 -> V_95 . V_96 ;
}
if ( V_97 )
F_61 ( V_7 ) ;
F_29 (evsel_list, counter) {
V_98:
if ( F_5 ( V_44 ) < 0 ) {
if ( V_99 == V_100 || V_99 == V_101 ||
V_99 == V_55 || V_99 == V_102 ||
V_99 == V_103 ) {
if ( V_58 )
F_62 ( L_16 ,
F_27 ( V_44 ) ) ;
V_44 -> V_54 = false ;
if ( ( V_44 -> V_104 != V_44 ) ||
! ( V_44 -> V_104 -> V_105 > 1 ) )
continue;
} else if ( F_63 ( V_44 , V_99 , V_88 , sizeof( V_88 ) ) ) {
if ( V_58 )
F_62 ( L_17 , V_88 ) ;
goto V_98;
}
F_64 ( V_44 , & V_27 ,
V_99 , V_88 , sizeof( V_88 ) ) ;
F_65 ( L_17 , V_88 ) ;
if ( V_94 != - 1 )
F_66 ( V_94 , V_106 ) ;
return - 1 ;
}
V_44 -> V_54 = true ;
V_91 = strlen ( V_44 -> V_75 ) ;
if ( V_91 > V_107 )
V_107 = V_91 ;
if ( V_20 && F_57 ( V_44 ) )
return - 1 ;
}
if ( F_67 ( V_7 , & V_44 ) ) {
error ( L_18 ,
V_44 -> V_108 , F_27 ( V_44 ) , V_99 ,
F_68 ( V_99 , V_88 , sizeof( V_88 ) ) ) ;
return - 1 ;
}
if ( V_20 ) {
int V_76 , V_83 = F_69 ( & V_21 . V_22 ) ;
if ( V_23 ) {
V_76 = F_70 ( F_69 ( & V_21 . V_22 ) ) ;
} else {
V_76 = F_71 ( V_21 . V_77 , V_7 ,
V_83 , false ) ;
}
if ( V_76 < 0 )
return V_76 ;
V_76 = F_45 ( V_23 ) ;
if ( V_76 < 0 )
return V_76 ;
}
V_89 = F_72 () ;
F_34 ( V_67 , & V_68 ) ;
if ( V_93 ) {
F_73 ( V_7 ) ;
F_37 () ;
if ( V_87 ) {
while ( ! F_74 ( V_94 , & V_92 , V_109 ) ) {
F_75 ( & V_65 , NULL ) ;
F_33 () ;
}
}
F_76 ( & V_92 ) ;
if ( V_72 ) {
const char * V_110 = F_68 ( V_72 , V_88 , sizeof( V_88 ) ) ;
F_16 ( L_19 , V_110 ) ;
return - 1 ;
}
if ( F_77 ( V_92 ) )
F_78 ( F_79 ( V_92 ) , V_86 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_111 ) {
F_75 ( & V_65 , NULL ) ;
if ( V_87 )
F_33 () ;
}
}
F_40 () ;
V_90 = F_72 () ;
F_80 ( & V_112 , V_90 - V_89 ) ;
F_28 () ;
F_81 ( V_7 ) ;
return F_82 ( V_92 ) ;
}
static int F_83 ( int V_85 , const char * * V_86 )
{
int V_113 ;
if ( V_114 ) {
V_113 = system ( V_114 ) ;
if ( V_113 )
return V_113 ;
}
if ( V_115 )
F_84 () ;
V_113 = F_59 ( V_85 , V_86 ) ;
if ( V_113 )
return V_113 ;
if ( V_116 ) {
V_113 = system ( V_116 ) ;
if ( V_113 )
return V_113 ;
}
return V_113 ;
}
static void F_85 ( T_3 V_63 , T_3 V_62 )
{
if ( V_117 ) {
fprintf ( V_12 . V_59 , L_20 V_60 L_21 ,
V_118 ,
V_63 ,
V_118 ,
V_62 ? 100.0 * V_63 / V_62 : 100.0 ) ;
} else if ( V_63 != V_62 ) {
fprintf ( V_12 . V_59 , L_22 , 100.0 * V_63 / V_62 ) ;
}
}
static void F_86 ( double V_119 , double V_120 )
{
double V_121 = F_87 ( V_119 , V_120 ) ;
if ( V_117 )
fprintf ( V_12 . V_59 , L_23 , V_118 , V_121 ) ;
else if ( V_121 )
fprintf ( V_12 . V_59 , L_24 , V_121 ) ;
}
static void F_88 ( struct V_8 * V_9 , double V_120 )
{
struct V_122 * V_123 ;
if ( V_124 == 1 )
return;
V_123 = V_9 -> V_125 ;
F_86 ( F_89 ( & V_123 -> V_126 [ 0 ] ) , V_120 ) ;
}
static void F_90 ( struct V_8 * V_9 , int V_51 , int V_82 )
{
switch ( V_12 . V_127 ) {
case V_128 :
fprintf ( V_12 . V_59 , L_25 ,
F_91 ( V_51 ) ,
V_117 ? 0 : - 8 ,
F_92 ( V_51 ) ,
V_118 ,
V_117 ? 0 : 4 ,
V_82 ,
V_118 ) ;
break;
case V_129 :
fprintf ( V_12 . V_59 , L_26 ,
V_117 ? 0 : - 5 ,
V_51 ,
V_118 ,
V_117 ? 0 : 4 ,
V_82 ,
V_118 ) ;
break;
case V_130 :
fprintf ( V_12 . V_59 , L_27 ,
V_117 ? 0 : - 4 ,
F_10 ( V_9 ) -> V_131 [ V_51 ] , V_118 ) ;
break;
case V_132 :
fprintf ( V_12 . V_59 , L_28 ,
V_117 ? 0 : 16 ,
F_93 ( V_9 -> V_30 , V_51 ) ,
V_117 ? 0 : - 8 ,
F_94 ( V_9 -> V_30 , V_51 ) ,
V_118 ) ;
break;
case V_133 :
case V_134 :
default:
break;
}
}
static void F_95 ( void * V_135 )
{
struct V_136 * V_137 = V_135 ;
V_137 -> V_138 = true ;
}
static void F_96 ( struct V_136 * V_137 )
{
fputc ( '\n' , V_137 -> V_139 ) ;
fputs ( V_137 -> V_140 , V_137 -> V_139 ) ;
F_90 ( V_137 -> V_9 , V_137 -> V_51 , V_137 -> V_82 ) ;
if ( V_12 . V_127 == V_130 )
fprintf ( V_137 -> V_139 , L_29 ) ;
fprintf ( V_137 -> V_139 , L_30 ) ;
}
static void F_97 ( void * V_135 , const char * V_141 , const char * V_142 ,
const char * V_75 , double V_61 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_143 = V_137 -> V_139 ;
int V_144 ;
bool V_138 = V_137 -> V_138 ;
V_137 -> V_138 = false ;
if ( V_75 == NULL || V_142 == NULL ) {
fprintf ( V_143 , L_31 , V_145 , L_32 ) ;
return;
}
if ( V_138 )
F_96 ( V_137 ) ;
V_144 = fprintf ( V_143 , L_33 ) ;
if ( V_141 )
V_144 += F_98 ( V_143 , V_141 , V_142 , V_61 ) ;
else
V_144 += fprintf ( V_143 , V_142 , V_61 ) ;
fprintf ( V_143 , L_34 , V_145 - V_144 - 1 , V_75 ) ;
}
static void F_99 ( void * V_135 )
{
struct V_136 * V_137 = V_135 ;
int V_146 ;
fputc ( '\n' , V_137 -> V_139 ) ;
if ( V_137 -> V_140 )
fprintf ( V_137 -> V_139 , L_35 , V_137 -> V_140 , V_118 ) ;
F_90 ( V_137 -> V_9 , V_137 -> V_51 , V_137 -> V_82 ) ;
for ( V_146 = 0 ; V_146 < V_137 -> V_147 ; V_146 ++ )
fputs ( V_118 , V_137 -> V_139 ) ;
}
static void F_100 ( void * V_135 ,
const char * V_141 V_35 ,
const char * V_142 , const char * V_75 , double V_61 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_143 = V_137 -> V_139 ;
char V_148 [ 64 ] , * V_149 , * V_150 ;
if ( V_75 == NULL || V_142 == NULL ) {
fprintf ( V_143 , L_36 , V_118 , V_118 , V_118 , V_118 ) ;
return;
}
snprintf ( V_148 , sizeof( V_148 ) , V_142 , V_61 ) ;
V_149 = V_148 ;
while ( isspace ( * V_149 ) )
V_149 ++ ;
V_150 = V_149 ;
while ( isdigit ( * V_150 ) || * V_150 == '.' )
V_150 ++ ;
* V_150 = 0 ;
while ( isspace ( * V_75 ) )
V_75 ++ ;
fprintf ( V_143 , L_36 , V_118 , V_149 , V_118 , V_75 ) ;
}
static bool F_101 ( const char * V_75 )
{
if ( ! V_75 )
return false ;
if ( strstr ( V_75 , L_37 ) ||
strstr ( V_75 , L_38 ) ||
strstr ( V_75 , L_39 ) ||
strstr ( V_75 , L_40 ) )
return false ;
return true ;
}
static const char * F_102 ( char * V_148 , struct V_8 * V_9 ,
const char * V_75 )
{
if ( ! strncmp ( V_75 , L_41 , 6 ) ) {
snprintf ( V_148 , 1024 , L_42 , F_27 ( V_9 ) ,
V_75 ) ;
return V_148 ;
}
return V_75 ;
}
static void F_103 ( void * V_135 , const char * V_141 , const char * V_142 ,
const char * V_75 , double V_61 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_143 = V_137 -> V_139 ;
int V_144 ;
char V_148 [ 1024 ] ;
unsigned V_151 = V_152 ;
if ( ! F_101 ( V_75 ) )
return;
V_75 = F_102 ( V_148 , V_137 -> V_9 , V_75 ) ;
if ( V_141 )
V_144 = F_98 ( V_143 , V_141 , V_142 , V_61 ) ;
else
V_144 = fprintf ( V_143 , V_142 , V_61 ) ;
if ( V_144 > V_152 )
V_144 = V_152 ;
if ( V_151 < strlen ( V_75 ) )
V_151 = strlen ( V_75 ) + 1 ;
fprintf ( V_143 , L_43 , V_151 - V_144 , L_32 ) ;
}
static void F_104 ( void * V_135 , const char * V_141 V_35 ,
const char * V_142 ,
const char * V_75 , double V_61 )
{
struct V_136 * V_137 = V_135 ;
T_9 * V_143 = V_137 -> V_139 ;
char V_148 [ 64 ] , * V_149 , * V_150 ;
char V_153 [ 1024 ] ;
if ( ! F_101 ( V_75 ) )
return;
V_75 = F_102 ( V_153 , V_137 -> V_9 , V_75 ) ;
snprintf ( V_148 , sizeof V_148 , V_142 , V_61 ) ;
V_149 = V_148 ;
while ( isspace ( * V_149 ) )
V_149 ++ ;
V_150 = V_149 ;
while ( isdigit ( * V_150 ) || * V_150 == '.' )
V_150 ++ ;
* V_150 = 0 ;
fprintf ( V_143 , L_35 , V_149 , V_118 ) ;
}
static void F_105 ( void * V_135 V_35 )
{
}
static void F_106 ( void * V_135 , const char * V_141 V_35 ,
const char * V_142 V_35 ,
const char * V_75 , double V_61 V_35 )
{
struct V_136 * V_137 = V_135 ;
char V_153 [ 1024 ] ;
if ( ! F_101 ( V_75 ) )
return;
V_75 = F_102 ( V_153 , V_137 -> V_9 , V_75 ) ;
if ( V_117 )
fprintf ( V_137 -> V_139 , L_35 , V_75 , V_118 ) ;
else
fprintf ( V_137 -> V_139 , L_44 , V_152 , V_75 ) ;
}
static void F_107 ( int V_51 , int V_82 , struct V_8 * V_9 , double V_120 )
{
T_9 * V_59 = V_12 . V_59 ;
double V_154 = V_120 / 1e6 ;
const char * V_155 , * V_156 ;
char V_64 [ 25 ] ;
V_155 = V_117 ? L_45 : L_46 ;
V_156 = V_117 ? L_47 : L_48 ;
F_90 ( V_9 , V_51 , V_82 ) ;
F_108 ( V_64 , sizeof( V_64 ) , L_35 ,
F_27 ( V_9 ) , V_117 ? L_32 : L_49 ) ;
fprintf ( V_59 , V_155 , V_154 , V_118 ) ;
if ( V_117 )
fprintf ( V_59 , L_35 , V_9 -> V_75 , V_118 ) ;
else
fprintf ( V_59 , L_50 , V_107 , V_9 -> V_75 , V_118 ) ;
fprintf ( V_59 , V_156 , V_64 ) ;
if ( V_9 -> V_157 )
fprintf ( V_59 , L_35 , V_118 , V_9 -> V_157 -> V_64 ) ;
}
static int F_109 ( struct V_8 * V_9 , int V_51 )
{
int V_146 ;
if ( ! V_158 )
return 0 ;
if ( V_12 . V_127 == V_130 )
return V_51 ;
if ( V_12 . V_127 == V_133 )
return 0 ;
for ( V_146 = 0 ; V_146 < F_24 ( V_9 ) ; V_146 ++ ) {
int V_159 = F_10 ( V_9 ) -> V_131 [ V_146 ] ;
if ( V_158 ( V_7 -> V_79 , V_159 ) == V_51 )
return V_159 ;
}
return 0 ;
}
static void F_110 ( int V_51 , int V_82 , struct V_8 * V_9 , double V_120 )
{
T_9 * V_59 = V_12 . V_59 ;
double V_160 = V_9 -> V_13 ;
const char * V_142 ;
if ( V_117 ) {
V_142 = floor ( V_160 ) != V_160 ? L_51 : L_52 ;
} else {
if ( V_161 )
V_142 = floor ( V_160 ) != V_160 ? L_53 : L_54 ;
else
V_142 = floor ( V_160 ) != V_160 ? L_55 : L_56 ;
}
F_90 ( V_9 , V_51 , V_82 ) ;
fprintf ( V_59 , V_142 , V_120 , V_118 ) ;
if ( V_9 -> V_75 )
fprintf ( V_59 , L_50 ,
V_117 ? 0 : V_107 ,
V_9 -> V_75 , V_118 ) ;
fprintf ( V_59 , L_31 , V_117 ? 0 : 25 , F_27 ( V_9 ) ) ;
if ( V_9 -> V_157 )
fprintf ( V_59 , L_35 , V_118 , V_9 -> V_157 -> V_64 ) ;
}
static void F_111 ( int V_51 , int V_82 , struct V_8 * V_44 , double V_162 ,
char * V_140 , T_3 V_63 , T_3 V_62 , double V_163 )
{
struct V_164 V_143 ;
struct V_136 V_137 = {
. V_139 = V_12 . V_59 ,
. V_140 = V_140 ? V_140 : L_32 ,
. V_51 = V_51 ,
. V_82 = V_82 ,
. V_9 = V_44 ,
} ;
T_10 V_165 = F_97 ;
void (* F_112)( void * );
if ( V_166 ) {
F_112 = F_105 ;
if ( V_117 )
V_165 = F_104 ;
else
V_165 = F_103 ;
} else
F_112 = F_95 ;
if ( V_117 && ! V_166 ) {
static int V_167 [] = {
[ V_133 ] = 0 ,
[ V_132 ] = 1 ,
[ V_130 ] = 1 ,
[ V_129 ] = 2 ,
[ V_128 ] = 2 ,
} ;
V_165 = F_100 ;
F_112 = F_99 ;
V_137 . V_147 = 3 ;
V_137 . V_147 += V_167 [ V_12 . V_127 ] ;
if ( V_44 -> V_157 )
V_137 . V_147 ++ ;
}
if ( V_63 == 0 || V_62 == 0 || V_44 -> V_57 -> V_168 == - 1 ) {
if ( V_166 ) {
V_165 ( & V_137 , NULL , L_32 , L_32 , 0 ) ;
return;
}
F_90 ( V_44 , V_51 , V_82 ) ;
fprintf ( V_12 . V_59 , L_57 ,
V_117 ? 0 : 18 ,
V_44 -> V_54 ? V_169 : V_170 ,
V_118 ) ;
fprintf ( V_12 . V_59 , L_50 ,
V_117 ? 0 : V_107 ,
V_44 -> V_75 , V_118 ) ;
fprintf ( V_12 . V_59 , L_43 ,
V_117 ? 0 : - 25 ,
F_27 ( V_44 ) ) ;
if ( V_44 -> V_157 )
fprintf ( V_12 . V_59 , L_35 ,
V_118 , V_44 -> V_157 -> V_64 ) ;
if ( ! V_117 )
V_165 ( & V_137 , NULL , NULL , L_32 , 0 ) ;
F_88 ( V_44 , V_163 ) ;
F_85 ( V_63 , V_62 ) ;
if ( V_117 )
V_165 ( & V_137 , NULL , NULL , L_32 , 0 ) ;
return;
}
if ( V_166 )
;
else if ( F_12 ( V_44 ) )
F_107 ( V_51 , V_82 , V_44 , V_162 ) ;
else
F_110 ( V_51 , V_82 , V_44 , V_162 ) ;
V_143 . V_171 = V_165 ;
V_143 . V_172 = F_112 ;
V_143 . V_135 = & V_137 ;
if ( V_117 && ! V_166 ) {
F_88 ( V_44 , V_163 ) ;
F_85 ( V_63 , V_62 ) ;
}
F_113 ( V_44 , V_162 ,
F_109 ( V_44 , V_51 ) ,
& V_143 ) ;
if ( ! V_117 && ! V_166 ) {
F_88 ( V_44 , V_163 ) ;
F_85 ( V_63 , V_62 ) ;
}
}
static void F_114 ( void )
{
int V_45 , V_173 , V_51 , V_174 ;
T_3 V_61 ;
struct V_8 * V_44 ;
for ( V_174 = 0 ; V_174 < V_175 -> V_82 ; V_174 ++ ) {
V_51 = V_175 -> V_131 [ V_174 ] ;
F_29 (evsel_list, counter) {
V_61 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_173 = V_158 ( V_7 -> V_79 , V_45 ) ;
if ( V_173 != V_51 )
continue;
V_61 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
}
V_61 = V_61 * V_44 -> V_13 ;
F_115 ( V_44 , & V_61 ,
F_109 ( V_44 , V_51 ) ) ;
}
}
}
static void F_116 ( char * V_140 )
{
T_9 * V_59 = V_12 . V_59 ;
struct V_8 * V_44 ;
int V_45 , V_174 , V_173 , V_51 , V_82 ;
double V_162 ;
T_3 V_62 , V_63 , V_61 ;
bool V_176 ;
if ( ! ( V_175 || V_158 ) )
return;
F_114 () ;
for ( V_174 = 0 ; V_174 < V_175 -> V_82 ; V_174 ++ ) {
if ( V_140 && V_166 )
fprintf ( V_59 , L_47 , V_140 ) ;
V_51 = V_175 -> V_131 [ V_174 ] ;
V_176 = true ;
F_29 (evsel_list, counter) {
V_61 = V_62 = V_63 = 0 ;
V_82 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_173 = V_158 ( F_10 ( V_44 ) , V_45 ) ;
if ( V_173 != V_51 )
continue;
V_61 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
V_82 ++ ;
}
if ( V_176 && V_166 ) {
V_176 = false ;
F_90 ( V_44 , V_51 , V_82 ) ;
}
if ( V_140 && ! V_166 )
fprintf ( V_59 , L_47 , V_140 ) ;
V_162 = V_61 * V_44 -> V_13 ;
F_111 ( V_51 , V_82 , V_44 , V_162 , V_140 , V_63 , V_62 , 1.0 ) ;
if ( ! V_166 )
fputc ( '\n' , V_59 ) ;
}
if ( V_166 )
fputc ( '\n' , V_59 ) ;
}
}
static void F_117 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_59 = V_12 . V_59 ;
int V_52 = F_23 ( V_44 -> V_30 ) ;
int V_53 = F_118 ( V_44 -> V_79 ) ;
int V_45 , V_46 ;
double V_162 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
T_3 V_62 = 0 , V_63 = 0 , V_61 = 0 ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
V_61 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_61 ;
V_62 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_62 ;
V_63 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_63 ;
}
if ( V_140 )
fprintf ( V_59 , L_47 , V_140 ) ;
V_162 = V_61 * V_44 -> V_13 ;
F_111 ( V_46 , 0 , V_44 , V_162 , V_140 , V_63 , V_62 , 1.0 ) ;
fputc ( '\n' , V_59 ) ;
}
}
static void F_119 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_59 = V_12 . V_59 ;
struct V_122 * V_123 = V_44 -> V_125 ;
double V_120 = F_120 ( & V_123 -> V_126 [ 0 ] ) ;
double V_162 ;
double V_177 , V_178 ;
V_177 = F_120 ( & V_123 -> V_126 [ 1 ] ) ;
V_178 = F_120 ( & V_123 -> V_126 [ 2 ] ) ;
if ( V_140 && ! V_166 )
fprintf ( V_59 , L_47 , V_140 ) ;
V_162 = V_120 * V_44 -> V_13 ;
F_111 ( - 1 , 0 , V_44 , V_162 , V_140 , V_178 , V_177 , V_120 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_5 ) ;
}
static void F_121 ( struct V_8 * V_44 , char * V_140 )
{
T_9 * V_59 = V_12 . V_59 ;
T_3 V_62 , V_63 , V_61 ;
double V_162 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_61 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
if ( V_140 )
fprintf ( V_59 , L_47 , V_140 ) ;
V_162 = V_61 * V_44 -> V_13 ;
F_111 ( V_45 , 0 , V_44 , V_162 , V_140 , V_63 , V_62 , 1.0 ) ;
fputc ( '\n' , V_59 ) ;
}
}
static void F_122 ( char * V_140 )
{
int V_45 ;
int V_179 = 0 ;
struct V_8 * V_44 ;
T_3 V_62 , V_63 , V_61 ;
double V_162 ;
V_179 = V_7 -> V_79 -> V_82 ;
for ( V_45 = 0 ; V_45 < V_179 ; V_45 ++ ) {
bool V_176 = true ;
if ( V_140 )
fputs ( V_140 , V_12 . V_59 ) ;
F_29 (evsel_list, counter) {
if ( V_176 ) {
F_90 ( V_44 , V_45 , 0 ) ;
V_176 = false ;
}
V_61 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
V_162 = V_61 * V_44 -> V_13 ;
F_111 ( V_45 , 0 , V_44 , V_162 , V_140 , V_63 , V_62 , 1.0 ) ;
}
fputc ( '\n' , V_12 . V_59 ) ;
}
}
static void F_123 ( const char * V_140 , bool V_180 )
{
struct V_164 V_143 ;
struct V_8 * V_44 ;
struct V_136 V_137 = {
. V_139 = V_12 . V_59
} ;
if ( V_140 )
fprintf ( V_12 . V_59 , L_47 , V_140 ) ;
if ( ! V_117 && ! V_180 )
fprintf ( V_12 . V_59 , L_43 ,
V_181 [ V_12 . V_127 ] , L_32 ) ;
if ( V_117 ) {
if ( V_12 . V_87 )
fputs ( L_58 , V_12 . V_59 ) ;
fputs ( V_182 [ V_12 . V_127 ] ,
V_12 . V_59 ) ;
}
F_29 (evsel_list, counter) {
V_137 . V_9 = V_44 ;
V_143 . V_135 = & V_137 ;
V_143 . V_171 = F_106 ;
V_143 . V_172 = F_105 ;
V_137 . V_9 = V_44 ;
F_113 ( V_44 , 0 ,
0 ,
& V_143 ) ;
}
fputc ( '\n' , V_12 . V_59 ) ;
}
static void F_124 ( char * V_140 , struct V_1 * V_65 )
{
T_9 * V_59 = V_12 . V_59 ;
static int V_183 ;
sprintf ( V_140 , L_59 , V_65 -> V_5 , V_65 -> V_6 , V_118 ) ;
if ( V_183 == 0 && ! V_117 ) {
switch ( V_12 . V_127 ) {
case V_129 :
fprintf ( V_59 , L_60 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_61 , V_107 , L_62 ) ;
break;
case V_128 :
fprintf ( V_59 , L_63 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_61 , V_107 , L_62 ) ;
break;
case V_130 :
fprintf ( V_59 , L_64 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_65 , V_107 , L_62 ) ;
break;
case V_132 :
fprintf ( V_59 , L_66 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_67 , V_107 , L_62 ) ;
break;
case V_133 :
default:
fprintf ( V_59 , L_68 ) ;
if ( ! V_166 )
fprintf ( V_59 , L_61 , V_107 , L_62 ) ;
case V_134 :
break;
}
}
if ( V_183 == 0 && V_166 )
F_123 ( L_69 , true ) ;
if ( ++ V_183 == 25 )
V_183 = 0 ;
}
static void F_125 ( int V_85 , const char * * V_86 )
{
T_9 * V_59 = V_12 . V_59 ;
int V_146 ;
fflush ( stdout ) ;
if ( ! V_117 ) {
fprintf ( V_59 , L_5 ) ;
fprintf ( V_59 , L_70 ) ;
if ( V_27 . V_56 )
fprintf ( V_59 , L_71 ) ;
else if ( V_27 . V_184 )
fprintf ( V_59 , L_72 , V_27 . V_184 ) ;
else if ( ! F_126 ( & V_27 ) ) {
fprintf ( V_59 , L_73 , V_86 ? V_86 [ 0 ] : L_74 ) ;
for ( V_146 = 1 ; V_86 && ( V_146 < V_85 ) ; V_146 ++ )
fprintf ( V_59 , L_75 , V_86 [ V_146 ] ) ;
} else if ( V_27 . V_96 )
fprintf ( V_59 , L_76 , V_27 . V_96 ) ;
else
fprintf ( V_59 , L_77 , V_27 . V_185 ) ;
fprintf ( V_59 , L_78 ) ;
if ( V_124 > 1 )
fprintf ( V_59 , L_79 , V_124 ) ;
fprintf ( V_59 , L_80 ) ;
}
}
static void F_127 ( void )
{
T_9 * V_59 = V_12 . V_59 ;
if ( ! V_186 )
fprintf ( V_59 , L_5 ) ;
fprintf ( V_59 , L_81 ,
F_120 ( & V_112 ) / 1e9 ) ;
if ( V_124 > 1 ) {
fprintf ( V_59 , L_82 ) ;
F_86 ( F_89 ( & V_112 ) ,
F_120 ( & V_112 ) ) ;
}
fprintf ( V_59 , L_83 ) ;
}
static void F_36 ( struct V_1 * V_65 , int V_85 , const char * * V_86 )
{
int V_87 = V_12 . V_87 ;
struct V_8 * V_44 ;
char V_148 [ 64 ] , * V_140 = NULL ;
if ( V_20 && V_21 . V_22 . V_23 )
return;
if ( V_87 )
F_124 ( V_140 = V_148 , V_65 ) ;
else
F_125 ( V_85 , V_86 ) ;
if ( V_166 ) {
static int V_187 ;
if ( V_187 == 0 && ! V_87 )
F_123 ( V_140 , false ) ;
if ( V_187 ++ == 25 )
V_187 = 0 ;
if ( V_12 . V_127 == V_133 && V_140 )
fprintf ( V_12 . V_59 , L_47 , V_140 ) ;
}
switch ( V_12 . V_127 ) {
case V_128 :
case V_129 :
F_116 ( V_140 ) ;
break;
case V_132 :
F_29 (evsel_list, counter)
F_117 ( V_44 , V_140 ) ;
break;
case V_133 :
F_29 (evsel_list, counter)
F_119 ( V_44 , V_140 ) ;
if ( V_166 )
fputc ( '\n' , V_12 . V_59 ) ;
break;
case V_130 :
if ( V_166 )
F_122 ( V_140 ) ;
else {
F_29 (evsel_list, counter)
F_121 ( V_44 , V_140 ) ;
}
break;
case V_134 :
default:
break;
}
if ( ! V_87 && ! V_117 )
F_127 () ;
fflush ( V_12 . V_59 ) ;
}
static void F_128 ( int T_5 )
{
if ( ( V_94 == - 1 ) || V_12 . V_87 )
V_111 = 1 ;
V_188 = T_5 ;
V_94 = - 1 ;
}
static void F_129 ( void )
{
T_11 V_189 , V_190 ;
F_130 ( & V_189 ) ;
F_131 ( & V_189 , V_191 ) ;
F_132 ( V_192 , & V_189 , & V_190 ) ;
if ( V_94 != - 1 )
F_66 ( V_94 , V_106 ) ;
F_132 ( V_193 , & V_190 , NULL ) ;
if ( V_188 == - 1 )
return;
signal ( V_188 , V_194 ) ;
F_66 ( F_133 () , V_188 ) ;
}
static int F_134 ( const struct V_195 * T_12 V_35 ,
const char * V_174 V_35 , int V_196 )
{
V_197 = V_196 ? 0 : 1 ;
return 0 ;
}
static int F_135 ( const struct V_195 * T_12 V_35 ,
const char * V_174 V_35 , int V_196 )
{
V_198 = true ;
V_166 = ! V_196 ;
return 0 ;
}
static int F_136 ( struct V_80 * V_131 , int V_45 )
{
return F_137 ( V_131 , V_45 , NULL ) ;
}
static int F_138 ( struct V_80 * V_131 , int V_45 )
{
return F_139 ( V_131 , V_45 , NULL ) ;
}
static int F_140 ( struct V_80 * V_131 )
{
int V_146 , V_199 = - 1 ;
for ( V_146 = 0 ; V_146 < V_131 -> V_82 ; V_146 ++ ) {
if ( V_131 -> V_131 [ V_146 ] > V_199 )
V_199 = V_131 -> V_131 [ V_146 ] ;
}
return V_199 ;
}
static int F_141 ( T_13 V_200 , struct V_80 * V_131 , int V_201 )
{
int V_45 ;
if ( V_201 >= V_131 -> V_82 )
return - 1 ;
V_45 = V_131 -> V_131 [ V_201 ] ;
if ( V_202 -> V_131 [ V_45 ] == - 1 )
V_202 -> V_131 [ V_45 ] = V_200 ( V_131 , V_201 ) ;
return V_202 -> V_131 [ V_45 ] ;
}
static int F_142 ( struct V_80 * V_131 , int V_201 )
{
return F_141 ( F_136 , V_131 , V_201 ) ;
}
static int F_143 ( struct V_80 * V_131 , int V_201 )
{
return F_141 ( F_138 , V_131 , V_201 ) ;
}
static int F_144 ( void )
{
int V_82 ;
switch ( V_12 . V_127 ) {
case V_129 :
if ( F_145 ( V_7 -> V_79 , & V_175 ) ) {
perror ( L_84 ) ;
return - 1 ;
}
V_158 = F_142 ;
break;
case V_128 :
if ( F_146 ( V_7 -> V_79 , & V_175 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_158 = F_143 ;
break;
case V_130 :
case V_133 :
case V_132 :
case V_134 :
default:
break;
}
V_82 = F_140 ( V_7 -> V_79 ) ;
V_202 = F_147 ( V_82 + 1 ) ;
return V_202 ? 0 : - V_84 ;
}
static void F_148 ( void )
{
F_149 ( V_175 ) ;
F_149 ( V_202 ) ;
V_175 = NULL ;
V_202 = NULL ;
}
static inline int F_150 ( struct V_203 * V_204 , struct V_80 * V_131 , int V_201 )
{
int V_45 ;
if ( V_201 > V_131 -> V_82 )
return - 1 ;
V_45 = V_131 -> V_131 [ V_201 ] ;
if ( V_45 >= V_204 -> V_205 )
return - 1 ;
return V_45 ;
}
static int F_151 ( struct V_80 * V_131 , int V_201 , void * V_206 )
{
struct V_203 * V_204 = V_206 ;
int V_45 = F_150 ( V_204 , V_131 , V_201 ) ;
return V_45 == - 1 ? - 1 : V_204 -> V_45 [ V_45 ] . V_207 ;
}
static int F_152 ( struct V_80 * V_131 , int V_201 , void * V_206 )
{
struct V_203 * V_204 = V_206 ;
int V_208 = - 1 , V_45 = F_150 ( V_204 , V_131 , V_201 ) ;
if ( V_45 != - 1 ) {
int V_207 = V_204 -> V_45 [ V_45 ] . V_207 ;
V_208 = ( V_207 << 16 ) | ( V_204 -> V_45 [ V_45 ] . V_209 & 0xffff ) ;
}
return V_208 ;
}
static int F_153 ( struct V_203 * V_204 , struct V_80 * V_79 ,
struct V_80 * * V_210 )
{
return F_154 ( V_79 , V_210 , F_151 , V_204 ) ;
}
static int F_155 ( struct V_203 * V_204 , struct V_80 * V_79 ,
struct V_80 * * V_211 )
{
return F_154 ( V_79 , V_211 , F_152 , V_204 ) ;
}
static int F_156 ( struct V_80 * V_131 , int V_201 )
{
return F_151 ( V_131 , V_201 , & V_21 . V_77 -> V_40 . V_204 ) ;
}
static int F_157 ( struct V_80 * V_131 , int V_201 )
{
return F_152 ( V_131 , V_201 , & V_21 . V_77 -> V_40 . V_204 ) ;
}
static int F_158 ( struct V_21 * V_212 )
{
struct V_203 * V_204 = & V_212 -> V_77 -> V_40 . V_204 ;
switch ( V_12 . V_127 ) {
case V_129 :
if ( F_153 ( V_204 , V_7 -> V_79 , & V_175 ) ) {
perror ( L_84 ) ;
return - 1 ;
}
V_158 = F_156 ;
break;
case V_128 :
if ( F_155 ( V_204 , V_7 -> V_79 , & V_175 ) ) {
perror ( L_85 ) ;
return - 1 ;
}
V_158 = F_157 ;
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
static int F_159 ( const char * * V_11 , char * * V_213 , bool V_214 )
{
int V_215 = 0 ;
int V_146 ;
int V_216 = 0 ;
char * V_174 ;
for ( V_146 = 0 ; V_11 [ V_146 ] ; V_146 ++ ) {
if ( F_160 ( L_86 , V_11 [ V_146 ] ) ) {
V_216 += strlen ( V_11 [ V_146 ] ) + 1 ;
V_11 [ V_146 - V_215 ] = V_11 [ V_146 ] ;
} else
V_215 ++ ;
}
V_11 [ V_146 - V_215 ] = NULL ;
* V_213 = malloc ( V_216 + 1 + 2 ) ;
if ( ! * V_213 )
return - 1 ;
V_174 = * V_213 ;
if ( V_146 - V_215 == 0 ) {
* V_174 = 0 ;
return 0 ;
}
if ( V_214 )
* V_174 ++ = '{' ;
for ( V_146 = 0 ; V_11 [ V_146 ] ; V_146 ++ ) {
strcpy ( V_174 , V_11 [ V_146 ] ) ;
V_174 += strlen ( V_174 ) ;
* V_174 ++ = ',' ;
}
if ( V_214 ) {
V_174 [ - 1 ] = '}' ;
* V_174 = 0 ;
} else
V_174 [ - 1 ] = 0 ;
return 0 ;
}
__weak bool F_161 ( bool * V_217 )
{
* V_217 = false ;
return false ;
}
__weak void F_162 ( void )
{
}
static int F_163 ( void )
{
int V_76 ;
struct V_10 V_218 [] = {
{ . type = V_219 , . V_220 = V_221 } ,
{ . type = V_219 , . V_220 = V_222 } ,
{ . type = V_219 , . V_220 = V_223 } ,
{ . type = V_219 , . V_220 = V_224 } ,
{ . type = V_225 , . V_220 = V_226 } ,
} ;
struct V_10 V_227 [] = {
{ . type = V_225 , . V_220 = V_228 } ,
} ;
struct V_10 V_229 [] = {
{ . type = V_225 , . V_220 = V_230 } ,
} ;
struct V_10 V_231 [] = {
{ . type = V_225 , . V_220 = V_232 } ,
{ . type = V_225 , . V_220 = V_233 } ,
{ . type = V_225 , . V_220 = V_234 } ,
} ;
struct V_10 V_235 [] = {
{ . type = V_236 ,
. V_220 =
V_237 << 0 |
( V_238 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_237 << 0 |
( V_238 << 8 ) |
( V_240 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_241 << 0 |
( V_238 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_241 << 0 |
( V_238 << 8 ) |
( V_240 << 16 ) } ,
} ;
struct V_10 V_242 [] = {
{ . type = V_236 ,
. V_220 =
V_243 << 0 |
( V_238 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_243 << 0 |
( V_238 << 8 ) |
( V_240 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_244 << 0 |
( V_238 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_244 << 0 |
( V_238 << 8 ) |
( V_240 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_245 << 0 |
( V_238 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_245 << 0 |
( V_238 << 8 ) |
( V_240 << 16 ) } ,
} ;
struct V_10 V_246 [] = {
{ . type = V_236 ,
. V_220 =
V_237 << 0 |
( V_247 << 8 ) |
( V_239 << 16 ) } ,
{ . type = V_236 ,
. V_220 =
V_237 << 0 |
( V_247 << 8 ) |
( V_240 << 16 ) } ,
} ;
if ( V_186 )
return 0 ;
if ( V_248 ) {
if ( F_160 ( L_86 , L_87 ) &&
F_160 ( L_86 , L_88 ) )
V_76 = F_164 ( V_7 , V_249 , NULL ) ;
else
V_76 = F_164 ( V_7 , V_250 , NULL ) ;
if ( V_76 ) {
fprintf ( V_251 , L_89 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_252 ) {
char * V_213 = NULL ;
bool V_217 = false ;
if ( V_12 . V_127 != V_133 &&
V_12 . V_127 != V_128 ) {
F_16 ( L_90 ) ;
return - 1 ;
}
V_12 . V_127 = V_128 ;
if ( V_253 || ! F_8 ( & V_27 ) ) {
F_16 ( L_91 ) ;
return - 1 ;
}
if ( ! V_198 )
V_166 = true ;
if ( F_159 ( V_254 , & V_213 ,
F_161 ( & V_217 ) ) < 0 ) {
F_16 ( L_92 ) ;
return - 1 ;
}
if ( V_254 [ 0 ] && V_213 ) {
if ( V_217 )
F_162 () ;
V_76 = F_164 ( V_7 , V_213 , NULL ) ;
if ( V_76 ) {
fprintf ( V_251 ,
L_93 ,
V_213 , V_76 ) ;
free ( V_213 ) ;
return - 1 ;
}
} else {
fprintf ( V_251 , L_94 ) ;
return - 1 ;
}
free ( V_213 ) ;
}
if ( ! V_7 -> V_255 ) {
if ( F_8 ( & V_27 ) )
V_218 [ 0 ] . V_220 = V_256 ;
if ( F_165 ( V_7 , V_218 ) < 0 )
return - 1 ;
if ( F_160 ( L_86 , L_95 ) ) {
if ( F_165 ( V_7 ,
V_227 ) < 0 )
return - 1 ;
}
if ( F_160 ( L_86 , L_96 ) ) {
if ( F_165 ( V_7 ,
V_229 ) < 0 )
return - 1 ;
}
if ( F_165 ( V_7 , V_231 ) < 0 )
return - 1 ;
}
if ( V_257 < 1 )
return 0 ;
if ( F_165 ( V_7 , V_235 ) < 0 )
return - 1 ;
if ( V_257 < 2 )
return 0 ;
if ( F_165 ( V_7 , V_242 ) < 0 )
return - 1 ;
if ( V_257 < 3 )
return 0 ;
return F_165 ( V_7 , V_246 ) ;
}
static void F_166 ( struct V_258 * V_77 )
{
int V_259 ;
for ( V_259 = V_260 ; V_259 < V_261 ; V_259 ++ )
F_167 ( & V_77 -> V_40 , V_259 ) ;
F_168 ( & V_77 -> V_40 , V_262 ) ;
F_168 ( & V_77 -> V_40 , V_263 ) ;
F_168 ( & V_77 -> V_40 , V_264 ) ;
F_168 ( & V_77 -> V_40 , V_265 ) ;
}
static int F_169 ( int V_85 , const char * * V_86 )
{
struct V_258 * V_77 ;
struct V_266 * V_22 = & V_21 . V_22 ;
V_85 = F_170 ( V_85 , V_86 , V_267 , V_268 ,
V_269 ) ;
if ( V_270 )
V_22 -> V_271 = V_270 ;
if ( V_124 != 1 || V_272 ) {
F_16 ( L_97 ) ;
return - 1 ;
}
V_77 = F_171 ( V_22 , false , NULL ) ;
if ( V_77 == NULL ) {
F_16 ( L_98 ) ;
return - 1 ;
}
F_166 ( V_77 ) ;
V_77 -> V_273 = V_7 ;
V_21 . V_77 = V_77 ;
V_21 . V_274 = true ;
return V_85 ;
}
static int F_172 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_258 * V_77 )
{
struct V_275 * V_276 = & V_37 -> V_276 ;
struct V_8 * V_44 ;
struct V_1 V_277 , * V_65 = NULL ;
const char * * V_86 = V_77 -> V_40 . V_204 . V_278 ;
int V_85 = V_77 -> V_40 . V_204 . V_279 ;
F_29 (evsel_list, counter)
F_31 ( & V_12 , V_44 ) ;
if ( V_276 -> type == V_280 )
F_80 ( & V_112 , V_276 -> time ) ;
if ( V_12 . V_87 && V_276 -> time ) {
V_277 . V_5 = V_276 -> time / V_69 ;
V_277 . V_6 = V_276 -> time % V_69 ;
V_65 = & V_277 ;
}
F_36 ( V_65 , V_85 , V_86 ) ;
return 0 ;
}
static
int F_173 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_258 * V_77 V_35 )
{
struct V_21 * V_212 = F_174 ( T_1 , struct V_21 , T_1 ) ;
F_175 ( & V_12 , & V_37 -> V_12 ) ;
if ( F_176 ( V_212 -> V_79 ) ) {
if ( V_212 -> V_127 != V_134 )
F_32 ( L_99 ) ;
return 0 ;
}
if ( V_212 -> V_127 != V_134 )
V_12 . V_127 = V_212 -> V_127 ;
if ( V_21 . V_22 . V_23 )
F_144 () ;
else
F_158 ( V_212 ) ;
return 0 ;
}
static int F_177 ( struct V_21 * V_212 )
{
if ( ! V_212 -> V_79 || ! V_212 -> V_30 )
return 0 ;
if ( F_178 ( V_212 -> V_281 , L_100 ) )
return - V_100 ;
F_179 ( V_7 , V_212 -> V_79 , V_212 -> V_30 ) ;
if ( F_180 ( V_7 , true ) )
return - V_84 ;
V_212 -> V_281 = true ;
return 0 ;
}
static
int F_181 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_258 * V_77 V_35 )
{
struct V_21 * V_212 = F_174 ( T_1 , struct V_21 , T_1 ) ;
if ( V_212 -> V_30 ) {
F_32 ( L_101 ) ;
return 0 ;
}
V_212 -> V_30 = F_182 ( & V_37 -> V_81 ) ;
if ( ! V_212 -> V_30 )
return - V_84 ;
return F_177 ( V_212 ) ;
}
static
int F_183 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_258 * V_77 V_35 )
{
struct V_21 * V_212 = F_174 ( T_1 , struct V_21 , T_1 ) ;
struct V_80 * V_79 ;
if ( V_212 -> V_79 ) {
F_32 ( L_102 ) ;
return 0 ;
}
V_79 = F_184 ( & V_37 -> V_80 . V_206 ) ;
if ( ! V_79 )
return - V_84 ;
V_212 -> V_79 = V_79 ;
return F_177 ( V_212 ) ;
}
static int F_185 ( int V_85 , const char * * V_86 )
{
struct V_258 * V_77 ;
const struct V_195 V_282 [] = {
F_186 ( 'i' , L_103 , & V_283 , L_104 , L_105 ) ,
F_187 ( 0 , L_106 , & V_21 . V_127 ,
L_107 , V_129 ) ,
F_187 ( 0 , L_108 , & V_21 . V_127 ,
L_109 , V_128 ) ,
F_187 ( 'A' , L_110 , & V_21 . V_127 ,
L_111 , V_130 ) ,
F_188 ()
} ;
struct V_284 V_212 ;
int V_113 ;
V_85 = F_170 ( V_85 , V_86 , V_282 , V_285 , 0 ) ;
if ( ! V_283 || ! strlen ( V_283 ) ) {
if ( ! F_189 ( V_286 , & V_212 ) && F_190 ( V_212 . V_287 ) )
V_283 = L_112 ;
else
V_283 = L_113 ;
}
V_21 . V_22 . V_271 = V_283 ;
V_21 . V_22 . V_288 = V_289 ;
V_77 = F_171 ( & V_21 . V_22 , false , & V_21 . T_1 ) ;
if ( V_77 == NULL )
return - 1 ;
V_21 . V_77 = V_77 ;
V_12 . V_59 = V_251 ;
V_7 = V_77 -> V_273 ;
V_113 = F_191 ( V_77 ) ;
if ( V_113 )
return V_113 ;
F_192 ( V_77 ) ;
return 0 ;
}
int F_193 ( int V_85 , const char * * V_86 , const char * V_140 V_35 )
{
const char * const V_290 [] = {
L_114 ,
NULL
} ;
int V_92 = - V_100 , V_291 ;
const char * V_288 ;
T_9 * V_59 = V_251 ;
unsigned int V_87 ;
const char * const V_292 [] = { L_115 , L_116 } ;
setlocale ( V_293 , L_32 ) ;
V_7 = F_194 () ;
if ( V_7 == NULL )
return - V_84 ;
F_195 () ;
V_85 = F_196 ( V_85 , V_86 , V_267 , V_292 ,
( const char * * ) V_290 ,
V_269 ) ;
F_197 () ;
if ( V_118 ) {
V_117 = true ;
if ( ! strcmp ( V_118 , L_117 ) )
V_118 = L_118 ;
} else
V_118 = V_294 ;
if ( V_85 && ! strncmp ( V_86 [ 0 ] , L_119 , 3 ) ) {
V_85 = F_169 ( V_85 , V_86 ) ;
if ( V_85 < 0 )
return - 1 ;
} else if ( V_85 && ! strncmp ( V_86 [ 0 ] , L_120 , 3 ) )
return F_185 ( V_85 , V_86 ) ;
V_87 = V_12 . V_87 ;
if ( ! V_20 && V_270 && strcmp ( V_270 , L_112 ) )
V_59 = NULL ;
if ( V_270 && V_295 ) {
fprintf ( V_251 , L_121 ) ;
F_198 ( V_290 , V_267 , L_122 , 1 ) ;
F_198 ( NULL , V_267 , L_123 , 0 ) ;
goto V_143;
}
if ( V_166 && V_12 . V_127 == V_132 ) {
fprintf ( V_251 , L_124 ) ;
goto V_143;
}
if ( V_166 && V_124 > 1 ) {
fprintf ( V_251 , L_125 ) ;
goto V_143;
}
if ( V_295 < 0 ) {
fprintf ( V_251 , L_126 ) ;
F_198 ( V_290 , V_267 , L_123 , 0 ) ;
goto V_143;
}
if ( ! V_59 ) {
struct V_1 V_43 ;
V_288 = V_296 ? L_127 : L_128 ;
V_59 = fopen ( V_270 , V_288 ) ;
if ( ! V_59 ) {
perror ( L_129 ) ;
return - 1 ;
}
F_34 ( V_297 , & V_43 ) ;
fprintf ( V_59 , L_130 , ctime ( & V_43 . V_5 ) ) ;
} else if ( V_295 > 0 ) {
V_288 = V_296 ? L_127 : L_128 ;
V_59 = fdopen ( V_295 , V_288 ) ;
if ( ! V_59 ) {
perror ( L_131 ) ;
return - V_99 ;
}
}
V_12 . V_59 = V_59 ;
if ( V_117 ) {
if ( V_197 == 1 ) {
fprintf ( V_251 , L_132 ) ;
F_198 ( V_290 , V_267 , L_133 , 1 ) ;
F_198 ( NULL , V_267 , L_134 , 1 ) ;
goto V_143;
} else
V_161 = false ;
} else if ( V_197 == 0 )
V_161 = false ;
if ( ! V_85 && F_7 ( & V_27 ) )
F_199 ( V_290 , V_267 ) ;
if ( V_124 < 0 ) {
F_16 ( L_135 ) ;
F_198 ( V_290 , V_267 , L_136 , 1 ) ;
goto V_143;
} else if ( V_124 == 0 ) {
V_272 = true ;
V_124 = 1 ;
}
if ( ( V_12 . V_127 == V_132 ) && ! F_126 ( & V_27 ) ) {
fprintf ( V_251 , L_137
L_138 ) ;
F_198 ( NULL , V_267 , L_139 , 1 ) ;
F_198 ( NULL , V_267 , L_140 , 1 ) ;
goto V_143;
}
if ( ( ( V_12 . V_127 != V_133 &&
V_12 . V_127 != V_132 ) || V_253 ) &&
! F_8 ( & V_27 ) ) {
fprintf ( V_251 , L_141
L_142 ) ;
F_198 ( V_290 , V_267 , L_143 , 1 ) ;
F_198 ( NULL , V_267 , L_144 , 1 ) ;
F_198 ( NULL , V_267 , L_127 , 1 ) ;
goto V_143;
}
if ( F_163 () )
goto V_143;
F_200 ( & V_27 ) ;
if ( F_201 ( V_7 , & V_27 ) < 0 ) {
if ( F_126 ( & V_27 ) ) {
F_16 ( L_145 ) ;
F_198 ( V_290 , V_267 , L_139 , 1 ) ;
F_198 ( NULL , V_267 , L_140 , 1 ) ;
} else if ( F_8 ( & V_27 ) ) {
perror ( L_146 ) ;
F_198 ( V_290 , V_267 , L_147 , 1 ) ;
F_198 ( NULL , V_267 , L_127 , 1 ) ;
}
goto V_143;
}
if ( V_12 . V_127 == V_132 )
F_202 ( V_7 -> V_30 ) ;
if ( V_87 && V_87 < 100 ) {
if ( V_87 < 10 ) {
F_16 ( L_148 ) ;
F_198 ( V_290 , V_267 , L_149 , 1 ) ;
goto V_143;
} else
F_32 ( L_150
L_151
L_152 ) ;
}
if ( F_180 ( V_7 , V_87 ) )
goto V_143;
if ( F_144 () )
goto V_143;
atexit ( F_129 ) ;
if ( ! V_272 )
signal ( V_298 , F_128 ) ;
signal ( V_191 , F_128 ) ;
signal ( V_299 , F_128 ) ;
signal ( V_300 , F_128 ) ;
V_92 = 0 ;
for ( V_291 = 0 ; V_272 || V_291 < V_124 ; V_291 ++ ) {
if ( V_124 != 1 && V_58 )
fprintf ( V_59 , L_153 ,
V_291 + 1 ) ;
V_92 = F_83 ( V_85 , V_86 ) ;
if ( V_272 && V_92 != - 1 ) {
F_36 ( NULL , V_85 , V_86 ) ;
F_2 () ;
}
}
if ( ! V_272 && V_92 != - 1 && ! V_87 )
F_36 ( NULL , V_85 , V_86 ) ;
if ( V_20 ) {
int V_83 = F_69 ( & V_21 . V_22 ) ;
int V_76 = F_203 ( ( void * ) & V_21 ,
F_14 ,
& V_21 . V_77 -> V_301 . V_302 ) ;
if ( V_76 ) {
F_32 ( L_154
L_155 ) ;
}
if ( ! V_87 ) {
if ( F_35 ( V_112 . V_199 , V_303 ) )
F_16 ( L_8 ) ;
}
if ( ! V_21 . V_22 . V_23 ) {
V_21 . V_77 -> V_40 . V_304 += V_21 . V_42 ;
F_71 ( V_21 . V_77 , V_7 , V_83 , true ) ;
}
F_192 ( V_21 . V_77 ) ;
}
F_148 () ;
F_204 ( V_7 ) ;
V_143:
F_205 ( V_7 ) ;
return V_92 ;
}
