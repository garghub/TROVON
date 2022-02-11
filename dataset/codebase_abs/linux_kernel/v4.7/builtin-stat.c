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
static void F_28 ( bool V_64 )
{
struct V_8 * V_44 ;
F_29 (evsel_list, counter) {
if ( F_22 ( V_44 ) )
F_30 ( L_6 , V_44 -> V_65 ) ;
if ( F_31 ( & V_12 , V_44 ) )
F_32 ( L_7 , V_44 -> V_65 ) ;
if ( V_64 ) {
F_33 ( V_44 , F_24 ( V_44 ) ,
F_23 ( V_7 -> V_30 ) ) ;
}
}
}
static void F_34 ( void )
{
struct V_1 V_66 , V_67 ;
F_28 ( false ) ;
F_35 ( V_68 , & V_66 ) ;
F_1 ( & V_67 , & V_66 , & V_69 ) ;
if ( V_20 ) {
if ( F_36 ( V_67 . V_5 * V_70 + V_67 . V_6 , V_71 ) )
F_16 ( L_8 ) ;
}
F_37 ( & V_67 , 0 , NULL ) ;
}
static void F_38 ( void )
{
if ( V_28 )
F_39 ( V_28 * 1000 ) ;
if ( ! F_7 ( & V_27 ) || V_28 )
F_40 ( V_7 ) ;
}
static void F_41 ( int T_5 V_35 , T_6 * V_72 ,
void * T_7 V_35 )
{
V_73 = V_72 -> V_74 . V_75 ;
}
static bool F_42 ( struct V_8 * V_44 )
{
return V_44 -> V_76 && * V_44 -> V_76 ;
}
static bool F_43 ( struct V_8 * V_44 )
{
return V_44 -> V_13 != 1 ;
}
static int F_44 ( bool V_23 )
{
struct V_8 * V_44 ;
int V_77 ;
if ( V_23 ) {
V_77 = F_45 ( NULL , V_21 . V_78 ,
F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_9 ) ;
return V_77 ;
}
}
F_29 (evsel_list, counter) {
if ( ! V_44 -> V_54 )
continue;
if ( F_42 ( V_44 ) ) {
V_77 = F_46 ( NULL , V_44 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_10 ) ;
return V_77 ;
}
}
if ( F_43 ( V_44 ) ) {
V_77 = F_47 ( NULL , V_44 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_11 ) ;
return V_77 ;
}
}
if ( V_44 -> V_79 ) {
V_77 = F_48 ( NULL , V_44 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_11 ) ;
return V_77 ;
}
}
if ( V_23 ) {
V_77 = F_49 ( NULL , V_44 , F_14 ) ;
if ( V_77 < 0 ) {
F_16 ( L_12 ) ;
return V_77 ;
}
}
}
V_77 = F_50 ( NULL , V_7 -> V_30 ,
F_14 ,
NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_13 ) ;
return V_77 ;
}
V_77 = F_51 ( NULL , V_7 -> V_80 ,
F_14 , NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_13 ) ;
return V_77 ;
}
V_77 = F_52 ( NULL , & V_12 ,
F_14 , NULL ) ;
if ( V_77 < 0 ) {
F_16 ( L_14 ) ;
return V_77 ;
}
return 0 ;
}
static int F_53 ( struct V_8 * V_44 ,
struct V_81 * V_80 ,
struct V_82 * V_30 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_80 -> V_83 ; V_45 ++ ) {
for ( V_46 = 0 ; V_46 < V_30 -> V_83 ; V_46 ++ ) {
int V_84 = F_54 ( V_44 , V_45 , V_46 ) ;
if ( F_55 ( V_7 , V_44 ,
V_45 , V_46 , V_84 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_56 ( struct V_8 * V_44 )
{
struct V_81 * V_80 = V_44 -> V_80 ;
struct V_82 * V_30 = V_44 -> V_30 ;
if ( F_57 ( V_44 , V_80 -> V_83 , V_30 -> V_83 ) )
return - V_85 ;
return F_53 ( V_44 , V_80 , V_30 ) ;
}
static int F_58 ( int V_86 , const char * * V_87 )
{
int V_88 = V_12 . V_88 ;
char V_89 [ 512 ] ;
unsigned long long V_90 , V_91 ;
struct V_8 * V_44 ;
struct V_1 V_66 ;
T_8 V_92 ;
int V_93 = 0 ;
const bool V_94 = ( V_86 > 0 ) ;
bool V_23 = V_20 ? V_21 . V_22 . V_23 : false ;
if ( V_88 ) {
V_66 . V_5 = V_88 / 1000 ;
V_66 . V_6 = ( V_88 % 1000 ) * 1000000 ;
} else {
V_66 . V_5 = 1 ;
V_66 . V_6 = 0 ;
}
if ( V_94 ) {
if ( F_59 ( V_7 , & V_27 , V_87 , V_23 ,
F_41 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_95 = V_7 -> V_96 . V_97 ;
}
if ( V_98 )
F_60 ( V_7 ) ;
F_29 (evsel_list, counter) {
V_99:
if ( F_5 ( V_44 ) < 0 ) {
if ( V_100 == V_101 || V_100 == V_102 ||
V_100 == V_55 || V_100 == V_103 ||
V_100 == V_104 ) {
if ( V_58 )
F_61 ( L_16 ,
F_27 ( V_44 ) ) ;
V_44 -> V_54 = false ;
if ( ( V_44 -> V_105 != V_44 ) ||
! ( V_44 -> V_105 -> V_106 > 1 ) )
continue;
} else if ( F_62 ( V_44 , V_100 , V_89 , sizeof( V_89 ) ) ) {
if ( V_58 )
F_61 ( L_17 , V_89 ) ;
goto V_99;
}
F_63 ( V_44 , & V_27 ,
V_100 , V_89 , sizeof( V_89 ) ) ;
F_64 ( L_17 , V_89 ) ;
if ( V_95 != - 1 )
F_65 ( V_95 , V_107 ) ;
return - 1 ;
}
V_44 -> V_54 = true ;
V_92 = strlen ( V_44 -> V_76 ) ;
if ( V_92 > V_108 )
V_108 = V_92 ;
if ( V_20 && F_56 ( V_44 ) )
return - 1 ;
}
if ( F_66 ( V_7 , & V_44 ) ) {
error ( L_18 ,
V_44 -> V_109 , F_27 ( V_44 ) , V_100 ,
F_67 ( V_100 , V_89 , sizeof( V_89 ) ) ) ;
return - 1 ;
}
if ( V_20 ) {
int V_77 , V_84 = F_68 ( & V_21 . V_22 ) ;
if ( V_23 ) {
V_77 = F_69 ( F_68 ( & V_21 . V_22 ) ) ;
} else {
V_77 = F_70 ( V_21 . V_78 , V_7 ,
V_84 , false ) ;
}
if ( V_77 < 0 )
return V_77 ;
V_77 = F_44 ( V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
}
V_90 = F_71 () ;
F_35 ( V_68 , & V_69 ) ;
if ( V_94 ) {
F_72 ( V_7 ) ;
F_38 () ;
if ( V_88 ) {
while ( ! F_73 ( V_95 , & V_93 , V_110 ) ) {
F_74 ( & V_66 , NULL ) ;
F_34 () ;
}
}
F_75 ( & V_93 ) ;
if ( V_73 ) {
const char * V_111 = F_67 ( V_73 , V_89 , sizeof( V_89 ) ) ;
F_16 ( L_19 , V_111 ) ;
return - 1 ;
}
if ( F_76 ( V_93 ) )
F_77 ( F_78 ( V_93 ) , V_87 [ 0 ] ) ;
} else {
F_38 () ;
while ( ! V_112 ) {
F_74 ( & V_66 , NULL ) ;
if ( V_88 )
F_34 () ;
}
}
V_91 = F_71 () ;
F_79 ( & V_113 , V_91 - V_90 ) ;
F_28 ( true ) ;
return F_80 ( V_93 ) ;
}
static int F_81 ( int V_86 , const char * * V_87 )
{
int V_114 ;
if ( V_115 ) {
V_114 = system ( V_115 ) ;
if ( V_114 )
return V_114 ;
}
if ( V_116 )
F_82 () ;
V_114 = F_58 ( V_86 , V_87 ) ;
if ( V_114 )
return V_114 ;
if ( V_117 ) {
V_114 = system ( V_117 ) ;
if ( V_114 )
return V_114 ;
}
return V_114 ;
}
static void F_83 ( T_3 V_63 , T_3 V_62 )
{
if ( V_118 ) {
fprintf ( V_12 . V_59 , L_20 V_60 L_21 ,
V_119 ,
V_63 ,
V_119 ,
V_62 ? 100.0 * V_63 / V_62 : 100.0 ) ;
} else if ( V_63 != V_62 ) {
fprintf ( V_12 . V_59 , L_22 , 100.0 * V_63 / V_62 ) ;
}
}
static void F_84 ( double V_120 , double V_121 )
{
double V_122 = F_85 ( V_120 , V_121 ) ;
if ( V_118 )
fprintf ( V_12 . V_59 , L_23 , V_119 , V_122 ) ;
else if ( V_122 )
fprintf ( V_12 . V_59 , L_24 , V_122 ) ;
}
static void F_86 ( struct V_8 * V_9 , double V_121 )
{
struct V_123 * V_124 ;
if ( V_125 == 1 )
return;
V_124 = V_9 -> V_126 ;
F_84 ( F_87 ( & V_124 -> V_127 [ 0 ] ) , V_121 ) ;
}
static void F_88 ( struct V_8 * V_9 , int V_51 , int V_83 )
{
switch ( V_12 . V_128 ) {
case V_129 :
fprintf ( V_12 . V_59 , L_25 ,
F_89 ( V_51 ) ,
V_118 ? 0 : - 8 ,
F_90 ( V_51 ) ,
V_119 ,
V_118 ? 0 : 4 ,
V_83 ,
V_119 ) ;
break;
case V_130 :
fprintf ( V_12 . V_59 , L_26 ,
V_118 ? 0 : - 5 ,
V_51 ,
V_119 ,
V_118 ? 0 : 4 ,
V_83 ,
V_119 ) ;
break;
case V_131 :
fprintf ( V_12 . V_59 , L_27 ,
V_118 ? 0 : - 4 ,
F_10 ( V_9 ) -> V_132 [ V_51 ] , V_119 ) ;
break;
case V_133 :
fprintf ( V_12 . V_59 , L_28 ,
V_118 ? 0 : 16 ,
F_91 ( V_9 -> V_30 , V_51 ) ,
V_118 ? 0 : - 8 ,
F_92 ( V_9 -> V_30 , V_51 ) ,
V_119 ) ;
break;
case V_134 :
case V_135 :
default:
break;
}
}
static void F_93 ( void * V_136 )
{
struct V_137 * V_138 = V_136 ;
V_138 -> V_139 = true ;
}
static void F_94 ( struct V_137 * V_138 )
{
fputc ( '\n' , V_138 -> V_140 ) ;
fputs ( V_138 -> V_141 , V_138 -> V_140 ) ;
F_88 ( V_138 -> V_9 , V_138 -> V_51 , V_138 -> V_83 ) ;
if ( V_12 . V_128 == V_131 )
fprintf ( V_138 -> V_140 , L_29 ) ;
fprintf ( V_138 -> V_140 , L_30 ) ;
}
static void F_95 ( void * V_136 , const char * V_142 , const char * V_143 ,
const char * V_76 , double V_61 )
{
struct V_137 * V_138 = V_136 ;
T_9 * V_144 = V_138 -> V_140 ;
int V_145 ;
bool V_139 = V_138 -> V_139 ;
V_138 -> V_139 = false ;
if ( V_76 == NULL || V_143 == NULL ) {
fprintf ( V_144 , L_31 , V_146 , L_32 ) ;
return;
}
if ( V_139 )
F_94 ( V_138 ) ;
V_145 = fprintf ( V_144 , L_33 ) ;
if ( V_142 )
V_145 += F_96 ( V_144 , V_142 , V_143 , V_61 ) ;
else
V_145 += fprintf ( V_144 , V_143 , V_61 ) ;
fprintf ( V_144 , L_34 , V_146 - V_145 - 1 , V_76 ) ;
}
static void F_97 ( void * V_136 )
{
struct V_137 * V_138 = V_136 ;
int V_147 ;
fputc ( '\n' , V_138 -> V_140 ) ;
if ( V_138 -> V_141 )
fprintf ( V_138 -> V_140 , L_35 , V_138 -> V_141 , V_119 ) ;
F_88 ( V_138 -> V_9 , V_138 -> V_51 , V_138 -> V_83 ) ;
for ( V_147 = 0 ; V_147 < V_138 -> V_148 ; V_147 ++ )
fputs ( V_119 , V_138 -> V_140 ) ;
}
static void F_98 ( void * V_136 ,
const char * V_142 V_35 ,
const char * V_143 , const char * V_76 , double V_61 )
{
struct V_137 * V_138 = V_136 ;
T_9 * V_144 = V_138 -> V_140 ;
char V_149 [ 64 ] , * V_150 , * V_151 ;
if ( V_76 == NULL || V_143 == NULL ) {
fprintf ( V_144 , L_36 , V_119 , V_119 , V_119 , V_119 ) ;
return;
}
snprintf ( V_149 , sizeof( V_149 ) , V_143 , V_61 ) ;
V_150 = V_149 ;
while ( isspace ( * V_150 ) )
V_150 ++ ;
V_151 = V_150 ;
while ( isdigit ( * V_151 ) || * V_151 == '.' )
V_151 ++ ;
* V_151 = 0 ;
while ( isspace ( * V_76 ) )
V_76 ++ ;
fprintf ( V_144 , L_36 , V_119 , V_150 , V_119 , V_76 ) ;
}
static bool F_99 ( const char * V_76 )
{
if ( ! V_76 )
return false ;
if ( strstr ( V_76 , L_37 ) ||
strstr ( V_76 , L_38 ) ||
strstr ( V_76 , L_39 ) ||
strstr ( V_76 , L_40 ) )
return false ;
return true ;
}
static const char * F_100 ( char * V_149 , struct V_8 * V_9 ,
const char * V_76 )
{
if ( ! strncmp ( V_76 , L_41 , 6 ) ) {
snprintf ( V_149 , 1024 , L_42 , F_27 ( V_9 ) ,
V_76 ) ;
return V_149 ;
}
return V_76 ;
}
static void F_101 ( void * V_136 , const char * V_142 , const char * V_143 ,
const char * V_76 , double V_61 )
{
struct V_137 * V_138 = V_136 ;
T_9 * V_144 = V_138 -> V_140 ;
int V_145 ;
char V_149 [ 1024 ] ;
unsigned V_152 = V_153 ;
if ( ! F_99 ( V_76 ) )
return;
V_76 = F_100 ( V_149 , V_138 -> V_9 , V_76 ) ;
if ( V_142 )
V_145 = F_96 ( V_144 , V_142 , V_143 , V_61 ) ;
else
V_145 = fprintf ( V_144 , V_143 , V_61 ) ;
if ( V_145 > V_153 )
V_145 = V_153 ;
if ( V_152 < strlen ( V_76 ) )
V_152 = strlen ( V_76 ) + 1 ;
fprintf ( V_144 , L_43 , V_152 - V_145 , L_32 ) ;
}
static void F_102 ( void * V_136 , const char * V_142 V_35 ,
const char * V_143 ,
const char * V_76 , double V_61 )
{
struct V_137 * V_138 = V_136 ;
T_9 * V_144 = V_138 -> V_140 ;
char V_149 [ 64 ] , * V_150 , * V_151 ;
char V_154 [ 1024 ] ;
if ( ! F_99 ( V_76 ) )
return;
V_76 = F_100 ( V_154 , V_138 -> V_9 , V_76 ) ;
snprintf ( V_149 , sizeof V_149 , V_143 , V_61 ) ;
V_150 = V_149 ;
while ( isspace ( * V_150 ) )
V_150 ++ ;
V_151 = V_150 ;
while ( isdigit ( * V_151 ) || * V_151 == '.' )
V_151 ++ ;
* V_151 = 0 ;
fprintf ( V_144 , L_35 , V_150 , V_119 ) ;
}
static void F_103 ( void * V_136 V_35 )
{
}
static void F_104 ( void * V_136 , const char * V_142 V_35 ,
const char * V_143 V_35 ,
const char * V_76 , double V_61 V_35 )
{
struct V_137 * V_138 = V_136 ;
char V_154 [ 1024 ] ;
if ( ! F_99 ( V_76 ) )
return;
V_76 = F_100 ( V_154 , V_138 -> V_9 , V_76 ) ;
if ( V_118 )
fprintf ( V_138 -> V_140 , L_35 , V_76 , V_119 ) ;
else
fprintf ( V_138 -> V_140 , L_44 , V_153 , V_76 ) ;
}
static void F_105 ( int V_51 , int V_83 , struct V_8 * V_9 , double V_121 )
{
T_9 * V_59 = V_12 . V_59 ;
double V_155 = V_121 / 1e6 ;
const char * V_156 , * V_157 ;
char V_65 [ 25 ] ;
V_156 = V_118 ? L_45 : L_46 ;
V_157 = V_118 ? L_47 : L_48 ;
F_88 ( V_9 , V_51 , V_83 ) ;
F_106 ( V_65 , sizeof( V_65 ) , L_35 ,
F_27 ( V_9 ) , V_118 ? L_32 : L_49 ) ;
fprintf ( V_59 , V_156 , V_155 , V_119 ) ;
if ( V_118 )
fprintf ( V_59 , L_35 , V_9 -> V_76 , V_119 ) ;
else
fprintf ( V_59 , L_50 , V_108 , V_9 -> V_76 , V_119 ) ;
fprintf ( V_59 , V_157 , V_65 ) ;
if ( V_9 -> V_158 )
fprintf ( V_59 , L_35 , V_119 , V_9 -> V_158 -> V_65 ) ;
}
static int F_107 ( struct V_8 * V_9 , int V_51 )
{
int V_147 ;
if ( ! V_159 )
return 0 ;
if ( V_12 . V_128 == V_131 )
return V_51 ;
if ( V_12 . V_128 == V_134 )
return 0 ;
for ( V_147 = 0 ; V_147 < F_24 ( V_9 ) ; V_147 ++ ) {
int V_160 = F_10 ( V_9 ) -> V_132 [ V_147 ] ;
if ( V_159 ( V_7 -> V_80 , V_160 ) == V_51 )
return V_160 ;
}
return 0 ;
}
static void F_108 ( int V_51 , int V_83 , struct V_8 * V_9 , double V_121 )
{
T_9 * V_59 = V_12 . V_59 ;
double V_161 = V_9 -> V_13 ;
const char * V_143 ;
if ( V_118 ) {
V_143 = floor ( V_161 ) != V_161 ? L_51 : L_52 ;
} else {
if ( V_162 )
V_143 = floor ( V_161 ) != V_161 ? L_53 : L_54 ;
else
V_143 = floor ( V_161 ) != V_161 ? L_55 : L_56 ;
}
F_88 ( V_9 , V_51 , V_83 ) ;
fprintf ( V_59 , V_143 , V_121 , V_119 ) ;
if ( V_9 -> V_76 )
fprintf ( V_59 , L_50 ,
V_118 ? 0 : V_108 ,
V_9 -> V_76 , V_119 ) ;
fprintf ( V_59 , L_31 , V_118 ? 0 : 25 , F_27 ( V_9 ) ) ;
if ( V_9 -> V_158 )
fprintf ( V_59 , L_35 , V_119 , V_9 -> V_158 -> V_65 ) ;
}
static void F_109 ( int V_51 , int V_83 , struct V_8 * V_44 , double V_163 ,
char * V_141 , T_3 V_63 , T_3 V_62 , double V_164 )
{
struct V_165 V_144 ;
struct V_137 V_138 = {
. V_140 = V_12 . V_59 ,
. V_141 = V_141 ? V_141 : L_32 ,
. V_51 = V_51 ,
. V_83 = V_83 ,
. V_9 = V_44 ,
} ;
T_10 V_166 = F_95 ;
void (* F_110)( void * );
if ( V_167 ) {
F_110 = F_103 ;
if ( V_118 )
V_166 = F_102 ;
else
V_166 = F_101 ;
} else
F_110 = F_93 ;
if ( V_118 && ! V_167 ) {
static int V_168 [] = {
[ V_134 ] = 0 ,
[ V_133 ] = 1 ,
[ V_131 ] = 1 ,
[ V_130 ] = 2 ,
[ V_129 ] = 2 ,
} ;
V_166 = F_98 ;
F_110 = F_97 ;
V_138 . V_148 = 3 ;
V_138 . V_148 += V_168 [ V_12 . V_128 ] ;
if ( V_44 -> V_158 )
V_138 . V_148 ++ ;
}
if ( V_63 == 0 || V_62 == 0 || V_44 -> V_57 -> V_169 == - 1 ) {
if ( V_167 ) {
V_166 ( & V_138 , NULL , L_32 , L_32 , 0 ) ;
return;
}
F_88 ( V_44 , V_51 , V_83 ) ;
fprintf ( V_12 . V_59 , L_57 ,
V_118 ? 0 : 18 ,
V_44 -> V_54 ? V_170 : V_171 ,
V_119 ) ;
fprintf ( V_12 . V_59 , L_50 ,
V_118 ? 0 : V_108 ,
V_44 -> V_76 , V_119 ) ;
fprintf ( V_12 . V_59 , L_43 ,
V_118 ? 0 : - 25 ,
F_27 ( V_44 ) ) ;
if ( V_44 -> V_158 )
fprintf ( V_12 . V_59 , L_35 ,
V_119 , V_44 -> V_158 -> V_65 ) ;
if ( ! V_118 )
V_166 ( & V_138 , NULL , NULL , L_32 , 0 ) ;
F_86 ( V_44 , V_164 ) ;
F_83 ( V_63 , V_62 ) ;
if ( V_118 )
V_166 ( & V_138 , NULL , NULL , L_32 , 0 ) ;
return;
}
if ( V_167 )
;
else if ( F_12 ( V_44 ) )
F_105 ( V_51 , V_83 , V_44 , V_163 ) ;
else
F_108 ( V_51 , V_83 , V_44 , V_163 ) ;
V_144 . V_172 = V_166 ;
V_144 . V_173 = F_110 ;
V_144 . V_136 = & V_138 ;
if ( V_118 && ! V_167 ) {
F_86 ( V_44 , V_164 ) ;
F_83 ( V_63 , V_62 ) ;
}
F_111 ( V_44 , V_163 ,
F_107 ( V_44 , V_51 ) ,
& V_144 ) ;
if ( ! V_118 && ! V_167 ) {
F_86 ( V_44 , V_164 ) ;
F_83 ( V_63 , V_62 ) ;
}
}
static void F_112 ( void )
{
int V_45 , V_174 , V_51 , V_175 ;
T_3 V_61 ;
struct V_8 * V_44 ;
for ( V_175 = 0 ; V_175 < V_176 -> V_83 ; V_175 ++ ) {
V_51 = V_176 -> V_132 [ V_175 ] ;
F_29 (evsel_list, counter) {
V_61 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_174 = V_159 ( V_7 -> V_80 , V_45 ) ;
if ( V_174 != V_51 )
continue;
V_61 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
}
V_61 = V_61 * V_44 -> V_13 ;
F_113 ( V_44 , & V_61 ,
F_107 ( V_44 , V_51 ) ) ;
}
}
}
static void F_114 ( char * V_141 )
{
T_9 * V_59 = V_12 . V_59 ;
struct V_8 * V_44 ;
int V_45 , V_175 , V_174 , V_51 , V_83 ;
double V_163 ;
T_3 V_62 , V_63 , V_61 ;
bool V_177 ;
if ( ! ( V_176 || V_159 ) )
return;
F_112 () ;
for ( V_175 = 0 ; V_175 < V_176 -> V_83 ; V_175 ++ ) {
if ( V_141 && V_167 )
fprintf ( V_59 , L_47 , V_141 ) ;
V_51 = V_176 -> V_132 [ V_175 ] ;
V_177 = true ;
F_29 (evsel_list, counter) {
V_61 = V_62 = V_63 = 0 ;
V_83 = 0 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_174 = V_159 ( F_10 ( V_44 ) , V_45 ) ;
if ( V_174 != V_51 )
continue;
V_61 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 += F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
V_83 ++ ;
}
if ( V_177 && V_167 ) {
V_177 = false ;
F_88 ( V_44 , V_51 , V_83 ) ;
}
if ( V_141 && ! V_167 )
fprintf ( V_59 , L_47 , V_141 ) ;
V_163 = V_61 * V_44 -> V_13 ;
F_109 ( V_51 , V_83 , V_44 , V_163 , V_141 , V_63 , V_62 , 1.0 ) ;
if ( ! V_167 )
fputc ( '\n' , V_59 ) ;
}
if ( V_167 )
fputc ( '\n' , V_59 ) ;
}
}
static void F_115 ( struct V_8 * V_44 , char * V_141 )
{
T_9 * V_59 = V_12 . V_59 ;
int V_52 = F_23 ( V_44 -> V_30 ) ;
int V_53 = F_116 ( V_44 -> V_80 ) ;
int V_45 , V_46 ;
double V_163 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
T_3 V_62 = 0 , V_63 = 0 , V_61 = 0 ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
V_61 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_61 ;
V_62 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_62 ;
V_63 += F_25 ( V_44 -> V_57 , V_45 , V_46 ) -> V_63 ;
}
if ( V_141 )
fprintf ( V_59 , L_47 , V_141 ) ;
V_163 = V_61 * V_44 -> V_13 ;
F_109 ( V_46 , 0 , V_44 , V_163 , V_141 , V_63 , V_62 , 1.0 ) ;
fputc ( '\n' , V_59 ) ;
}
}
static void F_117 ( struct V_8 * V_44 , char * V_141 )
{
T_9 * V_59 = V_12 . V_59 ;
struct V_123 * V_124 = V_44 -> V_126 ;
double V_121 = F_118 ( & V_124 -> V_127 [ 0 ] ) ;
double V_163 ;
double V_178 , V_179 ;
V_178 = F_118 ( & V_124 -> V_127 [ 1 ] ) ;
V_179 = F_118 ( & V_124 -> V_127 [ 2 ] ) ;
if ( V_141 && ! V_167 )
fprintf ( V_59 , L_47 , V_141 ) ;
V_163 = V_121 * V_44 -> V_13 ;
F_109 ( - 1 , 0 , V_44 , V_163 , V_141 , V_179 , V_178 , V_121 ) ;
if ( ! V_167 )
fprintf ( V_59 , L_5 ) ;
}
static void F_119 ( struct V_8 * V_44 , char * V_141 )
{
T_9 * V_59 = V_12 . V_59 ;
T_3 V_62 , V_63 , V_61 ;
double V_163 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_24 ( V_44 ) ; V_45 ++ ) {
V_61 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
if ( V_141 )
fprintf ( V_59 , L_47 , V_141 ) ;
V_163 = V_61 * V_44 -> V_13 ;
F_109 ( V_45 , 0 , V_44 , V_163 , V_141 , V_63 , V_62 , 1.0 ) ;
fputc ( '\n' , V_59 ) ;
}
}
static void F_120 ( char * V_141 )
{
int V_45 ;
int V_180 = 0 ;
struct V_8 * V_44 ;
T_3 V_62 , V_63 , V_61 ;
double V_163 ;
V_180 = V_7 -> V_80 -> V_83 ;
for ( V_45 = 0 ; V_45 < V_180 ; V_45 ++ ) {
bool V_177 = true ;
if ( V_141 )
fputs ( V_141 , V_12 . V_59 ) ;
F_29 (evsel_list, counter) {
if ( V_177 ) {
F_88 ( V_44 , V_45 , 0 ) ;
V_177 = false ;
}
V_61 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_61 ;
V_62 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_62 ;
V_63 = F_25 ( V_44 -> V_57 , V_45 , 0 ) -> V_63 ;
V_163 = V_61 * V_44 -> V_13 ;
F_109 ( V_45 , 0 , V_44 , V_163 , V_141 , V_63 , V_62 , 1.0 ) ;
}
fputc ( '\n' , V_12 . V_59 ) ;
}
}
static void F_121 ( char * V_141 )
{
struct V_165 V_144 ;
struct V_8 * V_44 ;
struct V_137 V_138 = {
. V_140 = V_12 . V_59
} ;
if ( V_141 )
fprintf ( V_12 . V_59 , L_47 , V_141 ) ;
if ( ! V_118 )
fprintf ( V_12 . V_59 , L_43 ,
V_181 [ V_12 . V_128 ] , L_32 ) ;
F_29 (evsel_list, counter) {
V_138 . V_9 = V_44 ;
V_144 . V_136 = & V_138 ;
V_144 . V_172 = F_104 ;
V_144 . V_173 = F_103 ;
V_138 . V_9 = V_44 ;
F_111 ( V_44 , 0 ,
0 ,
& V_144 ) ;
}
fputc ( '\n' , V_12 . V_59 ) ;
}
static void F_122 ( char * V_141 , struct V_1 * V_66 )
{
T_9 * V_59 = V_12 . V_59 ;
static int V_182 ;
sprintf ( V_141 , L_58 , V_66 -> V_5 , V_66 -> V_6 , V_119 ) ;
if ( V_182 == 0 && ! V_118 && ! V_167 ) {
switch ( V_12 . V_128 ) {
case V_130 :
fprintf ( V_59 , L_59 , V_108 , L_60 ) ;
break;
case V_129 :
fprintf ( V_59 , L_61 , V_108 , L_60 ) ;
break;
case V_131 :
fprintf ( V_59 , L_62 , V_108 , L_60 ) ;
break;
case V_133 :
fprintf ( V_59 , L_63 , V_108 , L_60 ) ;
break;
case V_134 :
default:
fprintf ( V_59 , L_64 , V_108 , L_60 ) ;
case V_135 :
break;
}
}
if ( ++ V_182 == 25 )
V_182 = 0 ;
}
static void F_123 ( int V_86 , const char * * V_87 )
{
T_9 * V_59 = V_12 . V_59 ;
int V_147 ;
fflush ( stdout ) ;
if ( ! V_118 ) {
fprintf ( V_59 , L_5 ) ;
fprintf ( V_59 , L_65 ) ;
if ( V_27 . V_56 )
fprintf ( V_59 , L_66 ) ;
else if ( V_27 . V_183 )
fprintf ( V_59 , L_67 , V_27 . V_183 ) ;
else if ( ! F_124 ( & V_27 ) ) {
fprintf ( V_59 , L_68 , V_87 ? V_87 [ 0 ] : L_69 ) ;
for ( V_147 = 1 ; V_87 && ( V_147 < V_86 ) ; V_147 ++ )
fprintf ( V_59 , L_70 , V_87 [ V_147 ] ) ;
} else if ( V_27 . V_97 )
fprintf ( V_59 , L_71 , V_27 . V_97 ) ;
else
fprintf ( V_59 , L_72 , V_27 . V_184 ) ;
fprintf ( V_59 , L_73 ) ;
if ( V_125 > 1 )
fprintf ( V_59 , L_74 , V_125 ) ;
fprintf ( V_59 , L_75 ) ;
}
}
static void F_125 ( void )
{
T_9 * V_59 = V_12 . V_59 ;
if ( ! V_185 )
fprintf ( V_59 , L_5 ) ;
fprintf ( V_59 , L_76 ,
F_118 ( & V_113 ) / 1e9 ) ;
if ( V_125 > 1 ) {
fprintf ( V_59 , L_77 ) ;
F_84 ( F_87 ( & V_113 ) ,
F_118 ( & V_113 ) ) ;
}
fprintf ( V_59 , L_78 ) ;
}
static void F_37 ( struct V_1 * V_66 , int V_86 , const char * * V_87 )
{
int V_88 = V_12 . V_88 ;
struct V_8 * V_44 ;
char V_149 [ 64 ] , * V_141 = NULL ;
if ( V_20 && V_21 . V_22 . V_23 )
return;
if ( V_88 )
F_122 ( V_141 = V_149 , V_66 ) ;
else
F_123 ( V_86 , V_87 ) ;
if ( V_167 ) {
static int V_186 ;
if ( V_186 == 0 )
F_121 ( V_141 ) ;
if ( V_186 ++ == 25 )
V_186 = 0 ;
if ( V_12 . V_128 == V_134 && V_141 )
fprintf ( V_12 . V_59 , L_47 , V_141 ) ;
}
switch ( V_12 . V_128 ) {
case V_129 :
case V_130 :
F_114 ( V_141 ) ;
break;
case V_133 :
F_29 (evsel_list, counter)
F_115 ( V_44 , V_141 ) ;
break;
case V_134 :
F_29 (evsel_list, counter)
F_117 ( V_44 , V_141 ) ;
if ( V_167 )
fputc ( '\n' , V_12 . V_59 ) ;
break;
case V_131 :
if ( V_167 )
F_120 ( V_141 ) ;
else {
F_29 (evsel_list, counter)
F_119 ( V_44 , V_141 ) ;
}
break;
case V_135 :
default:
break;
}
if ( ! V_88 && ! V_118 )
F_125 () ;
fflush ( V_12 . V_59 ) ;
}
static void F_126 ( int T_5 )
{
if ( ( V_95 == - 1 ) || V_12 . V_88 )
V_112 = 1 ;
V_187 = T_5 ;
V_95 = - 1 ;
}
static void F_127 ( void )
{
T_11 V_188 , V_189 ;
F_128 ( & V_188 ) ;
F_129 ( & V_188 , V_190 ) ;
F_130 ( V_191 , & V_188 , & V_189 ) ;
if ( V_95 != - 1 )
F_65 ( V_95 , V_107 ) ;
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
static int F_133 ( struct V_81 * V_132 , int V_45 )
{
return F_134 ( V_132 , V_45 , NULL ) ;
}
static int F_135 ( struct V_81 * V_132 , int V_45 )
{
return F_136 ( V_132 , V_45 , NULL ) ;
}
static int F_137 ( struct V_81 * V_132 )
{
int V_147 , V_197 = - 1 ;
for ( V_147 = 0 ; V_147 < V_132 -> V_83 ; V_147 ++ ) {
if ( V_132 -> V_132 [ V_147 ] > V_197 )
V_197 = V_132 -> V_132 [ V_147 ] ;
}
return V_197 ;
}
static int F_138 ( T_13 V_198 , struct V_81 * V_132 , int V_199 )
{
int V_45 ;
if ( V_199 >= V_132 -> V_83 )
return - 1 ;
V_45 = V_132 -> V_132 [ V_199 ] ;
if ( V_200 -> V_132 [ V_45 ] == - 1 )
V_200 -> V_132 [ V_45 ] = V_198 ( V_132 , V_199 ) ;
return V_200 -> V_132 [ V_45 ] ;
}
static int F_139 ( struct V_81 * V_132 , int V_199 )
{
return F_138 ( F_133 , V_132 , V_199 ) ;
}
static int F_140 ( struct V_81 * V_132 , int V_199 )
{
return F_138 ( F_135 , V_132 , V_199 ) ;
}
static int F_141 ( void )
{
int V_83 ;
switch ( V_12 . V_128 ) {
case V_130 :
if ( F_142 ( V_7 -> V_80 , & V_176 ) ) {
perror ( L_79 ) ;
return - 1 ;
}
V_159 = F_139 ;
break;
case V_129 :
if ( F_143 ( V_7 -> V_80 , & V_176 ) ) {
perror ( L_80 ) ;
return - 1 ;
}
V_159 = F_140 ;
break;
case V_131 :
case V_134 :
case V_133 :
case V_135 :
default:
break;
}
V_83 = F_137 ( V_7 -> V_80 ) ;
V_200 = F_144 ( V_83 + 1 ) ;
return V_200 ? 0 : - V_85 ;
}
static void F_145 ( void )
{
F_146 ( V_176 ) ;
F_146 ( V_200 ) ;
V_176 = NULL ;
V_200 = NULL ;
}
static inline int F_147 ( struct V_201 * V_202 , struct V_81 * V_132 , int V_199 )
{
int V_45 ;
if ( V_199 > V_132 -> V_83 )
return - 1 ;
V_45 = V_132 -> V_132 [ V_199 ] ;
if ( V_45 >= V_202 -> V_203 )
return - 1 ;
return V_45 ;
}
static int F_148 ( struct V_81 * V_132 , int V_199 , void * V_204 )
{
struct V_201 * V_202 = V_204 ;
int V_45 = F_147 ( V_202 , V_132 , V_199 ) ;
return V_45 == - 1 ? - 1 : V_202 -> V_45 [ V_45 ] . V_205 ;
}
static int F_149 ( struct V_81 * V_132 , int V_199 , void * V_204 )
{
struct V_201 * V_202 = V_204 ;
int V_206 = - 1 , V_45 = F_147 ( V_202 , V_132 , V_199 ) ;
if ( V_45 != - 1 ) {
int V_205 = V_202 -> V_45 [ V_45 ] . V_205 ;
V_206 = ( V_205 << 16 ) | ( V_202 -> V_45 [ V_45 ] . V_207 & 0xffff ) ;
}
return V_206 ;
}
static int F_150 ( struct V_201 * V_202 , struct V_81 * V_80 ,
struct V_81 * * V_208 )
{
return F_151 ( V_80 , V_208 , F_148 , V_202 ) ;
}
static int F_152 ( struct V_201 * V_202 , struct V_81 * V_80 ,
struct V_81 * * V_209 )
{
return F_151 ( V_80 , V_209 , F_149 , V_202 ) ;
}
static int F_153 ( struct V_81 * V_132 , int V_199 )
{
return F_148 ( V_132 , V_199 , & V_21 . V_78 -> V_40 . V_202 ) ;
}
static int F_154 ( struct V_81 * V_132 , int V_199 )
{
return F_149 ( V_132 , V_199 , & V_21 . V_78 -> V_40 . V_202 ) ;
}
static int F_155 ( struct V_21 * V_210 )
{
struct V_201 * V_202 = & V_210 -> V_78 -> V_40 . V_202 ;
switch ( V_12 . V_128 ) {
case V_130 :
if ( F_150 ( V_202 , V_7 -> V_80 , & V_176 ) ) {
perror ( L_79 ) ;
return - 1 ;
}
V_159 = F_153 ;
break;
case V_129 :
if ( F_152 ( V_202 , V_7 -> V_80 , & V_176 ) ) {
perror ( L_80 ) ;
return - 1 ;
}
V_159 = F_154 ;
break;
case V_131 :
case V_134 :
case V_133 :
case V_135 :
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
int V_77 ;
if ( F_157 ( L_81 , L_82 ) &&
F_157 ( L_81 , L_83 ) )
V_77 = F_158 ( V_7 , V_242 , NULL ) ;
else
V_77 = F_158 ( V_7 , V_243 , NULL ) ;
if ( V_77 ) {
fprintf ( V_244 , L_84 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_7 -> V_245 ) {
if ( F_8 ( & V_27 ) )
V_211 [ 0 ] . V_213 = V_246 ;
if ( F_159 ( V_7 , V_211 ) < 0 )
return - 1 ;
if ( F_157 ( L_81 , L_85 ) ) {
if ( F_159 ( V_7 ,
V_220 ) < 0 )
return - 1 ;
}
if ( F_157 ( L_81 , L_86 ) ) {
if ( F_159 ( V_7 ,
V_222 ) < 0 )
return - 1 ;
}
if ( F_159 ( V_7 , V_224 ) < 0 )
return - 1 ;
}
if ( V_247 < 1 )
return 0 ;
if ( F_159 ( V_7 , V_228 ) < 0 )
return - 1 ;
if ( V_247 < 2 )
return 0 ;
if ( F_159 ( V_7 , V_235 ) < 0 )
return - 1 ;
if ( V_247 < 3 )
return 0 ;
return F_159 ( V_7 , V_239 ) ;
}
static void F_160 ( struct V_248 * V_78 )
{
int V_249 ;
for ( V_249 = V_250 ; V_249 < V_251 ; V_249 ++ )
F_161 ( & V_78 -> V_40 , V_249 ) ;
F_162 ( & V_78 -> V_40 , V_252 ) ;
F_162 ( & V_78 -> V_40 , V_253 ) ;
F_162 ( & V_78 -> V_40 , V_254 ) ;
F_162 ( & V_78 -> V_40 , V_255 ) ;
}
static int F_163 ( int V_86 , const char * * V_87 )
{
struct V_248 * V_78 ;
struct V_256 * V_22 = & V_21 . V_22 ;
V_86 = F_164 ( V_86 , V_87 , V_257 , V_258 ,
V_259 ) ;
if ( V_260 )
V_22 -> V_261 = V_260 ;
if ( V_125 != 1 || V_262 ) {
F_16 ( L_87 ) ;
return - 1 ;
}
V_78 = F_165 ( V_22 , false , NULL ) ;
if ( V_78 == NULL ) {
F_16 ( L_88 ) ;
return - 1 ;
}
F_160 ( V_78 ) ;
V_78 -> V_263 = V_7 ;
V_21 . V_78 = V_78 ;
V_21 . V_264 = true ;
return V_86 ;
}
static int F_166 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_248 * V_78 )
{
struct V_265 * V_266 = & V_37 -> V_266 ;
struct V_8 * V_44 ;
struct V_1 V_267 , * V_66 = NULL ;
const char * * V_87 = V_78 -> V_40 . V_202 . V_268 ;
int V_86 = V_78 -> V_40 . V_202 . V_269 ;
F_29 (evsel_list, counter)
F_31 ( & V_12 , V_44 ) ;
if ( V_266 -> type == V_270 )
F_79 ( & V_113 , V_266 -> time ) ;
if ( V_12 . V_88 && V_266 -> time ) {
V_267 . V_5 = V_266 -> time / V_70 ;
V_267 . V_6 = V_266 -> time % V_70 ;
V_66 = & V_267 ;
}
F_37 ( V_66 , V_86 , V_87 ) ;
return 0 ;
}
static
int F_167 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_248 * V_78 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
F_169 ( & V_12 , & V_37 -> V_12 ) ;
if ( F_170 ( V_210 -> V_80 ) ) {
if ( V_210 -> V_128 != V_135 )
F_32 ( L_89 ) ;
return 0 ;
}
if ( V_210 -> V_128 != V_135 )
V_12 . V_128 = V_210 -> V_128 ;
if ( V_21 . V_22 . V_23 )
F_141 () ;
else
F_155 ( V_210 ) ;
return 0 ;
}
static int F_171 ( struct V_21 * V_210 )
{
if ( ! V_210 -> V_80 || ! V_210 -> V_30 )
return 0 ;
if ( F_172 ( V_210 -> V_271 , L_90 ) )
return - V_101 ;
F_173 ( V_7 , V_210 -> V_80 , V_210 -> V_30 ) ;
if ( F_174 ( V_7 , true ) )
return - V_85 ;
V_210 -> V_271 = true ;
return 0 ;
}
static
int F_175 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_248 * V_78 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
if ( V_210 -> V_30 ) {
F_32 ( L_91 ) ;
return 0 ;
}
V_210 -> V_30 = F_176 ( & V_37 -> V_82 ) ;
if ( ! V_210 -> V_30 )
return - V_85 ;
return F_171 ( V_210 ) ;
}
static
int F_177 ( struct V_34 * T_1 V_35 ,
union V_36 * V_37 ,
struct V_248 * V_78 V_35 )
{
struct V_21 * V_210 = F_168 ( T_1 , struct V_21 , T_1 ) ;
struct V_81 * V_80 ;
if ( V_210 -> V_80 ) {
F_32 ( L_92 ) ;
return 0 ;
}
V_80 = F_178 ( & V_37 -> V_81 . V_204 ) ;
if ( ! V_80 )
return - V_85 ;
V_210 -> V_80 = V_80 ;
return F_171 ( V_210 ) ;
}
static int F_179 ( int V_86 , const char * * V_87 )
{
struct V_248 * V_78 ;
const struct V_194 V_272 [] = {
F_180 ( 'i' , L_93 , & V_273 , L_94 , L_95 ) ,
F_181 ( 0 , L_96 , & V_21 . V_128 ,
L_97 , V_130 ) ,
F_181 ( 0 , L_98 , & V_21 . V_128 ,
L_99 , V_129 ) ,
F_181 ( 'A' , L_100 , & V_21 . V_128 ,
L_101 , V_131 ) ,
F_182 ()
} ;
struct V_274 V_210 ;
int V_114 ;
V_86 = F_164 ( V_86 , V_87 , V_272 , V_275 , 0 ) ;
if ( ! V_273 || ! strlen ( V_273 ) ) {
if ( ! F_183 ( V_276 , & V_210 ) && F_184 ( V_210 . V_277 ) )
V_273 = L_102 ;
else
V_273 = L_103 ;
}
V_21 . V_22 . V_261 = V_273 ;
V_21 . V_22 . V_278 = V_279 ;
V_78 = F_165 ( & V_21 . V_22 , false , & V_21 . T_1 ) ;
if ( V_78 == NULL )
return - 1 ;
V_21 . V_78 = V_78 ;
V_12 . V_59 = V_244 ;
V_7 = V_78 -> V_263 ;
V_114 = F_185 ( V_78 ) ;
if ( V_114 )
return V_114 ;
F_186 ( V_78 ) ;
return 0 ;
}
int F_187 ( int V_86 , const char * * V_87 , const char * V_141 V_35 )
{
const char * const V_280 [] = {
L_104 ,
NULL
} ;
int V_93 = - V_101 , V_281 ;
const char * V_278 ;
T_9 * V_59 = V_244 ;
unsigned int V_88 ;
const char * const V_282 [] = { L_105 , L_106 } ;
setlocale ( V_283 , L_32 ) ;
V_7 = F_188 () ;
if ( V_7 == NULL )
return - V_85 ;
F_189 () ;
V_86 = F_190 ( V_86 , V_87 , V_257 , V_282 ,
( const char * * ) V_280 ,
V_259 ) ;
F_191 () ;
if ( V_119 ) {
V_118 = true ;
if ( ! strcmp ( V_119 , L_107 ) )
V_119 = L_108 ;
} else
V_119 = V_284 ;
if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_109 , 3 ) ) {
V_86 = F_163 ( V_86 , V_87 ) ;
if ( V_86 < 0 )
return - 1 ;
} else if ( V_86 && ! strncmp ( V_87 [ 0 ] , L_110 , 3 ) )
return F_179 ( V_86 , V_87 ) ;
V_88 = V_12 . V_88 ;
if ( ! V_20 && V_260 && strcmp ( V_260 , L_102 ) )
V_59 = NULL ;
if ( V_260 && V_285 ) {
fprintf ( V_244 , L_111 ) ;
F_192 ( V_280 , V_257 , L_112 , 1 ) ;
F_192 ( NULL , V_257 , L_113 , 0 ) ;
goto V_144;
}
if ( V_167 && V_12 . V_128 == V_133 ) {
fprintf ( V_244 , L_114 ) ;
goto V_144;
}
if ( V_167 && V_125 > 1 ) {
fprintf ( V_244 , L_115 ) ;
goto V_144;
}
if ( V_285 < 0 ) {
fprintf ( V_244 , L_116 ) ;
F_192 ( V_280 , V_257 , L_113 , 0 ) ;
goto V_144;
}
if ( ! V_59 ) {
struct V_1 V_43 ;
V_278 = V_286 ? L_117 : L_118 ;
V_59 = fopen ( V_260 , V_278 ) ;
if ( ! V_59 ) {
perror ( L_119 ) ;
return - 1 ;
}
F_35 ( V_287 , & V_43 ) ;
fprintf ( V_59 , L_120 , ctime ( & V_43 . V_5 ) ) ;
} else if ( V_285 > 0 ) {
V_278 = V_286 ? L_117 : L_118 ;
V_59 = fdopen ( V_285 , V_278 ) ;
if ( ! V_59 ) {
perror ( L_121 ) ;
return - V_100 ;
}
}
V_12 . V_59 = V_59 ;
if ( V_118 ) {
if ( V_196 == 1 ) {
fprintf ( V_244 , L_122 ) ;
F_192 ( V_280 , V_257 , L_123 , 1 ) ;
F_192 ( NULL , V_257 , L_124 , 1 ) ;
goto V_144;
} else
V_162 = false ;
} else if ( V_196 == 0 )
V_162 = false ;
if ( ! V_86 && F_7 ( & V_27 ) )
F_193 ( V_280 , V_257 ) ;
if ( V_125 < 0 ) {
F_16 ( L_125 ) ;
F_192 ( V_280 , V_257 , L_126 , 1 ) ;
goto V_144;
} else if ( V_125 == 0 ) {
V_262 = true ;
V_125 = 1 ;
}
if ( ( V_12 . V_128 == V_133 ) && ! F_124 ( & V_27 ) ) {
fprintf ( V_244 , L_127
L_128 ) ;
F_192 ( NULL , V_257 , L_129 , 1 ) ;
F_192 ( NULL , V_257 , L_130 , 1 ) ;
goto V_144;
}
if ( ( ( V_12 . V_128 != V_134 &&
V_12 . V_128 != V_133 ) || V_288 ) &&
! F_8 ( & V_27 ) ) {
fprintf ( V_244 , L_131
L_132 ) ;
F_192 ( V_280 , V_257 , L_133 , 1 ) ;
F_192 ( NULL , V_257 , L_134 , 1 ) ;
F_192 ( NULL , V_257 , L_117 , 1 ) ;
goto V_144;
}
if ( F_156 () )
goto V_144;
F_194 ( & V_27 ) ;
if ( F_195 ( V_7 , & V_27 ) < 0 ) {
if ( F_124 ( & V_27 ) ) {
F_16 ( L_135 ) ;
F_192 ( V_280 , V_257 , L_129 , 1 ) ;
F_192 ( NULL , V_257 , L_130 , 1 ) ;
} else if ( F_8 ( & V_27 ) ) {
perror ( L_136 ) ;
F_192 ( V_280 , V_257 , L_137 , 1 ) ;
F_192 ( NULL , V_257 , L_117 , 1 ) ;
}
goto V_144;
}
if ( V_12 . V_128 == V_133 )
F_196 ( V_7 -> V_30 ) ;
if ( V_88 && V_88 < 100 ) {
if ( V_88 < 10 ) {
F_16 ( L_138 ) ;
F_192 ( V_280 , V_257 , L_139 , 1 ) ;
goto V_144;
} else
F_32 ( L_140
L_141
L_142 ) ;
}
if ( F_174 ( V_7 , V_88 ) )
goto V_144;
if ( F_141 () )
goto V_144;
atexit ( F_127 ) ;
if ( ! V_262 )
signal ( V_289 , F_126 ) ;
signal ( V_190 , F_126 ) ;
signal ( V_290 , F_126 ) ;
signal ( V_291 , F_126 ) ;
V_93 = 0 ;
for ( V_281 = 0 ; V_262 || V_281 < V_125 ; V_281 ++ ) {
if ( V_125 != 1 && V_58 )
fprintf ( V_59 , L_143 ,
V_281 + 1 ) ;
V_93 = F_81 ( V_86 , V_87 ) ;
if ( V_262 && V_93 != - 1 ) {
F_37 ( NULL , V_86 , V_87 ) ;
F_2 () ;
}
}
if ( ! V_262 && V_93 != - 1 && ! V_88 )
F_37 ( NULL , V_86 , V_87 ) ;
if ( V_20 ) {
int V_84 = F_68 ( & V_21 . V_22 ) ;
int V_77 = F_197 ( ( void * ) & V_21 ,
F_14 ,
& V_21 . V_78 -> V_292 . V_293 ) ;
if ( V_77 ) {
F_32 ( L_144
L_145 ) ;
}
if ( ! V_88 ) {
if ( F_36 ( V_113 . V_197 , V_294 ) )
F_16 ( L_8 ) ;
}
if ( ! V_21 . V_22 . V_23 ) {
V_21 . V_78 -> V_40 . V_295 += V_21 . V_42 ;
F_70 ( V_21 . V_78 , V_7 , V_84 , true ) ;
}
F_186 ( V_21 . V_78 ) ;
}
F_145 () ;
F_198 ( V_7 ) ;
V_144:
F_199 ( V_7 ) ;
return V_93 ;
}
