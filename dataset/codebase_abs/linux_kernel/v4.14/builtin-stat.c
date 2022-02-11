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
struct V_9 * V_13 = V_10 -> V_13 ;
if ( V_14 . V_15 ) {
V_12 -> V_16 = V_17 |
V_18 ;
}
if ( V_13 -> V_19 > 1 )
V_12 -> V_16 |= V_20 | V_21 ;
V_12 -> V_22 = ! V_23 ;
V_12 -> V_24 = 0 ;
if ( ! ( V_25 && V_26 . V_27 . V_28 ) )
V_12 -> V_29 = V_30 ;
if ( F_6 ( V_10 ) ) {
V_12 -> V_31 = 1 ;
if ( F_7 ( & V_32 ) && ! V_33 )
V_12 -> V_34 = 1 ;
}
if ( F_8 ( & V_32 ) )
return F_9 ( V_10 , F_10 ( V_10 ) ) ;
return F_11 ( V_10 , V_8 -> V_35 ) ;
}
static inline int F_12 ( struct V_9 * V_10 )
{
if ( F_13 ( V_10 , V_36 , V_37 ) ||
F_13 ( V_10 , V_36 , V_38 ) )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_39 * T_1 V_40 ,
union V_41 * V_42 ,
struct V_43 * T_2 V_40 ,
struct V_44 * V_44 V_40 )
{
if ( F_15 ( & V_26 . V_27 , V_42 , V_42 -> V_45 . V_46 ) < 0 ) {
F_16 ( L_1 ) ;
return - 1 ;
}
V_26 . V_47 += V_42 -> V_45 . V_46 ;
return 0 ;
}
static int F_17 ( T_3 V_48 , T_3 type )
{
return F_18 ( NULL , V_48 , type ,
F_14 ,
NULL ) ;
}
static int
F_19 ( struct V_9 * V_49 , T_4 V_50 , T_4 V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_20 ( V_49 , V_50 , V_51 ) ;
return F_21 ( NULL , V_50 , V_51 , V_55 -> V_56 , V_53 ,
F_14 , NULL ) ;
}
static int F_22 ( struct V_9 * V_49 )
{
int V_57 = F_23 ( V_8 -> V_35 ) ;
int V_58 , V_50 , V_51 ;
if ( F_8 ( & V_32 ) )
V_58 = F_24 ( V_49 ) ;
else
V_58 = 1 ;
if ( ! V_49 -> V_59 )
return - V_60 ;
if ( V_49 -> V_61 )
V_57 = 1 ;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
for ( V_50 = 0 ; V_50 < V_58 ; V_50 ++ ) {
struct V_52 * V_53 ;
V_53 = F_25 ( V_49 -> V_62 , V_50 , V_51 ) ;
if ( ! V_53 -> V_63 &&
F_26 ( V_49 , V_50 , V_51 ) ) {
V_49 -> V_62 -> V_64 = - 1 ;
F_25 ( V_49 -> V_62 , V_50 , V_51 ) -> V_65 = 0 ;
F_25 ( V_49 -> V_62 , V_50 , V_51 ) -> V_66 = 0 ;
return - 1 ;
}
V_53 -> V_63 = false ;
if ( V_25 ) {
if ( F_19 ( V_49 , V_50 , V_51 , V_53 ) ) {
F_16 ( L_2 ) ;
return - 1 ;
}
}
if ( V_67 > 1 ) {
fprintf ( V_14 . V_68 ,
L_3 V_69 L_4 V_69 L_4 V_69 L_5 ,
F_27 ( V_49 ) ,
V_50 ,
V_53 -> V_70 , V_53 -> V_65 , V_53 -> V_66 ) ;
}
}
}
return 0 ;
}
static void F_28 ( void )
{
struct V_9 * V_49 ;
int V_71 ;
F_29 (evsel_list, counter) {
V_71 = F_22 ( V_49 ) ;
if ( V_71 )
F_30 ( L_6 , V_49 -> V_72 ) ;
if ( V_71 == 0 && F_31 ( & V_14 , V_49 ) )
F_32 ( L_7 , V_49 -> V_72 ) ;
}
}
static void F_33 ( void )
{
struct V_1 V_73 , V_74 ;
F_28 () ;
F_34 ( V_75 , & V_73 ) ;
F_1 ( & V_74 , & V_73 , & V_76 ) ;
if ( V_25 ) {
if ( F_35 ( V_74 . V_5 * V_7 + V_74 . V_6 , V_77 ) )
F_16 ( L_8 ) ;
}
F_36 ( & V_74 , 0 , NULL ) ;
}
static void F_37 ( void )
{
if ( V_33 )
F_38 ( V_33 * V_78 ) ;
if ( ! F_7 ( & V_32 ) || V_33 )
F_39 ( V_8 ) ;
}
static void F_40 ( void )
{
if ( ! F_7 ( & V_32 ) )
F_41 ( V_8 ) ;
}
static void F_42 ( int T_5 V_40 , T_6 * V_79 ,
void * T_7 V_40 )
{
V_80 = V_79 -> V_81 . V_82 ;
}
static bool F_43 ( struct V_9 * V_49 )
{
return V_49 -> V_83 && * V_49 -> V_83 ;
}
static bool F_44 ( struct V_9 * V_49 )
{
return V_49 -> V_15 != 1 ;
}
static int F_45 ( bool V_28 )
{
struct V_9 * V_49 ;
int V_84 ;
if ( V_28 ) {
V_84 = F_46 ( NULL , V_26 . V_85 ,
F_14 ) ;
if ( V_84 < 0 ) {
F_16 ( L_9 ) ;
return V_84 ;
}
}
F_29 (evsel_list, counter) {
if ( ! V_49 -> V_59 )
continue;
if ( F_43 ( V_49 ) ) {
V_84 = F_47 ( NULL , V_49 , F_14 ) ;
if ( V_84 < 0 ) {
F_16 ( L_10 ) ;
return V_84 ;
}
}
if ( F_44 ( V_49 ) ) {
V_84 = F_48 ( NULL , V_49 , F_14 ) ;
if ( V_84 < 0 ) {
F_16 ( L_11 ) ;
return V_84 ;
}
}
if ( V_49 -> V_86 ) {
V_84 = F_49 ( NULL , V_49 , F_14 ) ;
if ( V_84 < 0 ) {
F_16 ( L_11 ) ;
return V_84 ;
}
}
if ( V_28 ) {
V_84 = F_50 ( NULL , V_49 , F_14 ) ;
if ( V_84 < 0 ) {
F_16 ( L_12 ) ;
return V_84 ;
}
}
}
V_84 = F_51 ( NULL , V_8 -> V_35 ,
F_14 ,
NULL ) ;
if ( V_84 < 0 ) {
F_16 ( L_13 ) ;
return V_84 ;
}
V_84 = F_52 ( NULL , V_8 -> V_87 ,
F_14 , NULL ) ;
if ( V_84 < 0 ) {
F_16 ( L_13 ) ;
return V_84 ;
}
V_84 = F_53 ( NULL , & V_14 ,
F_14 , NULL ) ;
if ( V_84 < 0 ) {
F_16 ( L_14 ) ;
return V_84 ;
}
return 0 ;
}
static int F_54 ( struct V_9 * V_49 ,
struct V_88 * V_87 ,
struct V_89 * V_35 )
{
int V_50 , V_51 ;
for ( V_50 = 0 ; V_50 < V_87 -> V_90 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < V_35 -> V_90 ; V_51 ++ ) {
int V_91 = F_55 ( V_49 , V_50 , V_51 ) ;
if ( F_56 ( V_8 , V_49 ,
V_50 , V_51 , V_91 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_9 * V_49 )
{
struct V_88 * V_87 = V_49 -> V_87 ;
struct V_89 * V_35 = V_49 -> V_35 ;
if ( F_58 ( V_49 , V_87 -> V_90 , V_35 -> V_90 ) )
return - V_92 ;
return F_54 ( V_49 , V_87 , V_35 ) ;
}
static bool F_59 ( struct V_9 * V_49 )
{
return V_25 || V_49 -> V_12 . V_16 & V_20 ;
}
static int F_60 ( int V_93 , const char * * V_94 )
{
int V_95 = V_14 . V_95 ;
char V_96 [ V_97 ] ;
unsigned long long V_98 , V_99 ;
struct V_9 * V_49 ;
struct V_1 V_73 ;
T_8 V_100 ;
int V_101 = 0 ;
const bool V_102 = ( V_93 > 0 ) ;
bool V_28 = V_25 ? V_26 . V_27 . V_28 : false ;
struct V_103 * V_104 ;
if ( V_95 ) {
V_73 . V_5 = V_95 / V_78 ;
V_73 . V_6 = ( V_95 % V_78 ) * V_105 ;
} else {
V_73 . V_5 = 1 ;
V_73 . V_6 = 0 ;
}
if ( V_102 ) {
if ( F_61 ( V_8 , & V_32 , V_94 , V_28 ,
F_42 ) < 0 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_106 = V_8 -> V_107 . V_108 ;
}
if ( V_109 )
F_62 ( V_8 ) ;
F_29 (evsel_list, counter) {
V_110:
if ( F_5 ( V_49 ) < 0 ) {
if ( V_111 == V_112 || V_111 == V_113 ||
V_111 == V_60 || V_111 == V_114 ||
V_111 == V_115 ) {
if ( V_67 > 0 )
F_63 ( L_16 ,
F_27 ( V_49 ) ) ;
V_49 -> V_59 = false ;
if ( ( V_49 -> V_13 != V_49 ) ||
! ( V_49 -> V_13 -> V_19 > 1 ) )
continue;
} else if ( F_64 ( V_49 , V_111 , V_96 , sizeof( V_96 ) ) ) {
if ( V_67 > 0 )
F_63 ( L_17 , V_96 ) ;
goto V_110;
}
F_65 ( V_49 , & V_32 ,
V_111 , V_96 , sizeof( V_96 ) ) ;
F_66 ( L_17 , V_96 ) ;
if ( V_106 != - 1 )
F_67 ( V_106 , V_116 ) ;
return - 1 ;
}
V_49 -> V_59 = true ;
V_100 = strlen ( V_49 -> V_83 ) ;
if ( V_100 > V_117 )
V_117 = V_100 ;
if ( F_59 ( V_49 ) &&
F_57 ( V_49 ) )
return - 1 ;
}
if ( F_68 ( V_8 , & V_49 ) ) {
F_16 ( L_18 ,
V_49 -> V_118 , F_27 ( V_49 ) , V_111 ,
F_69 ( V_111 , V_96 , sizeof( V_96 ) ) ) ;
return - 1 ;
}
if ( F_70 ( V_8 , & V_49 , & V_104 ) ) {
F_16 ( L_19 ,
V_104 -> V_70 . V_119 , F_27 ( V_49 ) , V_111 ,
F_69 ( V_111 , V_96 , sizeof( V_96 ) ) ) ;
return - 1 ;
}
if ( V_25 ) {
int V_84 , V_91 = F_71 ( & V_26 . V_27 ) ;
if ( V_28 ) {
V_84 = F_72 ( F_71 ( & V_26 . V_27 ) ) ;
} else {
V_84 = F_73 ( V_26 . V_85 , V_8 ,
V_91 , false ) ;
}
if ( V_84 < 0 )
return V_84 ;
V_84 = F_45 ( V_28 ) ;
if ( V_84 < 0 )
return V_84 ;
}
V_98 = F_74 () ;
F_34 ( V_75 , & V_76 ) ;
if ( V_102 ) {
F_75 ( V_8 ) ;
F_37 () ;
if ( V_95 ) {
while ( ! F_76 ( V_106 , & V_101 , V_120 ) ) {
F_77 ( & V_73 , NULL ) ;
F_33 () ;
}
}
F_76 ( V_106 , & V_101 , 0 ) ;
if ( V_80 ) {
const char * V_121 = F_69 ( V_80 , V_96 , sizeof( V_96 ) ) ;
F_16 ( L_20 , V_121 ) ;
return - 1 ;
}
if ( F_78 ( V_101 ) )
F_79 ( F_80 ( V_101 ) , V_94 [ 0 ] ) ;
} else {
F_37 () ;
while ( ! V_122 ) {
F_77 ( & V_73 , NULL ) ;
if ( V_95 )
F_33 () ;
}
}
F_40 () ;
V_99 = F_74 () ;
F_81 ( & V_123 , V_99 - V_98 ) ;
F_28 () ;
F_82 ( V_8 ) ;
return F_83 ( V_101 ) ;
}
static int F_84 ( int V_93 , const char * * V_94 )
{
int V_71 ;
if ( V_124 ) {
V_71 = system ( V_124 ) ;
if ( V_71 )
return V_71 ;
}
if ( V_125 )
F_85 () ;
V_71 = F_60 ( V_93 , V_94 ) ;
if ( V_71 )
return V_71 ;
if ( V_126 ) {
V_71 = system ( V_126 ) ;
if ( V_71 )
return V_71 ;
}
return V_71 ;
}
static void F_86 ( T_3 V_66 , T_3 V_65 )
{
if ( V_127 ) {
fprintf ( V_14 . V_68 , L_21 V_69 L_22 ,
V_128 ,
V_66 ,
V_128 ,
V_65 ? 100.0 * V_66 / V_65 : 100.0 ) ;
} else if ( V_66 != V_65 ) {
fprintf ( V_14 . V_68 , L_23 , 100.0 * V_66 / V_65 ) ;
}
}
static void F_87 ( double V_129 , double V_130 )
{
double V_131 = F_88 ( V_129 , V_130 ) ;
if ( V_127 )
fprintf ( V_14 . V_68 , L_24 , V_128 , V_131 ) ;
else if ( V_131 )
fprintf ( V_14 . V_68 , L_25 , V_131 ) ;
}
static void F_89 ( struct V_9 * V_10 , double V_130 )
{
struct V_132 * V_133 ;
if ( V_134 == 1 )
return;
V_133 = V_10 -> V_135 ;
F_87 ( F_90 ( & V_133 -> V_136 [ 0 ] ) , V_130 ) ;
}
static void F_91 ( struct V_9 * V_10 , int V_56 , int V_90 )
{
switch ( V_14 . V_137 ) {
case V_138 :
fprintf ( V_14 . V_68 , L_26 ,
F_92 ( V_56 ) ,
V_127 ? 0 : - 8 ,
F_93 ( V_56 ) ,
V_128 ,
V_127 ? 0 : 4 ,
V_90 ,
V_128 ) ;
break;
case V_139 :
fprintf ( V_14 . V_68 , L_27 ,
V_127 ? 0 : - 5 ,
V_56 ,
V_128 ,
V_127 ? 0 : 4 ,
V_90 ,
V_128 ) ;
break;
case V_140 :
fprintf ( V_14 . V_68 , L_28 ,
V_127 ? 0 : - 4 ,
F_10 ( V_10 ) -> V_141 [ V_56 ] , V_128 ) ;
break;
case V_142 :
fprintf ( V_14 . V_68 , L_29 ,
V_127 ? 0 : 16 ,
F_94 ( V_10 -> V_35 , V_56 ) ,
V_127 ? 0 : - 8 ,
F_95 ( V_10 -> V_35 , V_56 ) ,
V_128 ) ;
break;
case V_143 :
case V_144 :
default:
break;
}
}
static void F_96 ( void * V_145 )
{
struct V_146 * V_147 = V_145 ;
V_147 -> V_148 = true ;
}
static void F_97 ( struct V_146 * V_147 )
{
fputc ( '\n' , V_147 -> V_149 ) ;
fputs ( V_147 -> V_150 , V_147 -> V_149 ) ;
F_91 ( V_147 -> V_10 , V_147 -> V_56 , V_147 -> V_90 ) ;
if ( V_14 . V_137 == V_140 )
fprintf ( V_147 -> V_149 , L_30 ) ;
fprintf ( V_147 -> V_149 , L_31 ) ;
}
static void F_98 ( void * V_145 , const char * V_151 , const char * V_152 ,
const char * V_83 , double V_70 )
{
struct V_146 * V_147 = V_145 ;
T_9 * V_153 = V_147 -> V_149 ;
int V_154 ;
bool V_148 = V_147 -> V_148 ;
V_147 -> V_148 = false ;
if ( V_83 == NULL || V_152 == NULL ) {
fprintf ( V_153 , L_32 , V_155 , L_33 ) ;
return;
}
if ( V_148 )
F_97 ( V_147 ) ;
V_154 = fprintf ( V_153 , L_34 ) ;
if ( V_151 )
V_154 += F_99 ( V_153 , V_151 , V_152 , V_70 ) ;
else
V_154 += fprintf ( V_153 , V_152 , V_70 ) ;
fprintf ( V_153 , L_35 , V_155 - V_154 - 1 , V_83 ) ;
}
static void F_100 ( void * V_145 )
{
struct V_146 * V_147 = V_145 ;
int V_156 ;
fputc ( '\n' , V_147 -> V_149 ) ;
if ( V_147 -> V_150 )
fprintf ( V_147 -> V_149 , L_36 , V_147 -> V_150 , V_128 ) ;
F_91 ( V_147 -> V_10 , V_147 -> V_56 , V_147 -> V_90 ) ;
for ( V_156 = 0 ; V_156 < V_147 -> V_157 ; V_156 ++ )
fputs ( V_128 , V_147 -> V_149 ) ;
}
static void F_101 ( void * V_145 ,
const char * V_151 V_40 ,
const char * V_152 , const char * V_83 , double V_70 )
{
struct V_146 * V_147 = V_145 ;
T_9 * V_153 = V_147 -> V_149 ;
char V_158 [ 64 ] , * V_159 , * V_160 ;
if ( V_83 == NULL || V_152 == NULL ) {
fprintf ( V_153 , L_37 , V_128 , V_128 , V_128 , V_128 ) ;
return;
}
snprintf ( V_158 , sizeof( V_158 ) , V_152 , V_70 ) ;
V_160 = V_159 = F_102 ( V_158 ) ;
while ( isdigit ( * V_160 ) || * V_160 == '.' )
V_160 ++ ;
* V_160 = 0 ;
while ( isspace ( * V_83 ) )
V_83 ++ ;
fprintf ( V_153 , L_37 , V_128 , V_159 , V_128 , V_83 ) ;
}
static bool F_103 ( const char * V_83 )
{
if ( ! V_83 )
return false ;
if ( strstr ( V_83 , L_38 ) ||
strstr ( V_83 , L_39 ) ||
strstr ( V_83 , L_40 ) ||
strstr ( V_83 , L_41 ) )
return false ;
return true ;
}
static const char * F_104 ( char * V_158 , struct V_9 * V_10 ,
const char * V_83 )
{
if ( ! strncmp ( V_83 , L_42 , 6 ) ) {
snprintf ( V_158 , 1024 , L_43 , F_27 ( V_10 ) ,
V_83 ) ;
return V_158 ;
}
return V_83 ;
}
static void F_105 ( void * V_145 , const char * V_151 , const char * V_152 ,
const char * V_83 , double V_70 )
{
struct V_146 * V_147 = V_145 ;
T_9 * V_153 = V_147 -> V_149 ;
int V_154 ;
char V_158 [ 1024 ] ;
unsigned V_161 = V_162 ;
if ( ! F_103 ( V_83 ) )
return;
V_83 = F_104 ( V_158 , V_147 -> V_10 , V_83 ) ;
if ( V_151 )
V_154 = F_99 ( V_153 , V_151 , V_152 , V_70 ) ;
else
V_154 = fprintf ( V_153 , V_152 , V_70 ) ;
if ( V_154 > V_162 )
V_154 = V_162 ;
if ( V_161 < strlen ( V_83 ) )
V_161 = strlen ( V_83 ) + 1 ;
fprintf ( V_153 , L_44 , V_161 - V_154 , L_33 ) ;
}
static void F_106 ( void * V_145 , const char * V_151 V_40 ,
const char * V_152 ,
const char * V_83 , double V_70 )
{
struct V_146 * V_147 = V_145 ;
T_9 * V_153 = V_147 -> V_149 ;
char V_158 [ 64 ] , * V_159 , * V_160 ;
char V_163 [ 1024 ] ;
if ( ! F_103 ( V_83 ) )
return;
V_83 = F_104 ( V_163 , V_147 -> V_10 , V_83 ) ;
snprintf ( V_158 , sizeof V_158 , V_152 , V_70 ) ;
V_160 = V_159 = F_102 ( V_158 ) ;
while ( isdigit ( * V_160 ) || * V_160 == '.' )
V_160 ++ ;
* V_160 = 0 ;
fprintf ( V_153 , L_36 , V_159 , V_128 ) ;
}
static void F_107 ( void * V_145 V_40 )
{
}
static void F_108 ( void * V_145 , const char * V_151 V_40 ,
const char * V_152 V_40 ,
const char * V_83 , double V_70 V_40 )
{
struct V_146 * V_147 = V_145 ;
char V_163 [ 1024 ] ;
if ( ! F_103 ( V_83 ) )
return;
V_83 = F_104 ( V_163 , V_147 -> V_10 , V_83 ) ;
if ( V_127 )
fprintf ( V_147 -> V_149 , L_36 , V_83 , V_128 ) ;
else
fprintf ( V_147 -> V_149 , L_45 , V_162 , V_83 ) ;
}
static void F_109 ( int V_56 , int V_90 , struct V_9 * V_10 , double V_130 )
{
T_9 * V_68 = V_14 . V_68 ;
double V_164 = V_130 / V_105 ;
const char * V_165 , * V_166 ;
char V_72 [ 25 ] ;
V_165 = V_127 ? L_46 : L_47 ;
V_166 = V_127 ? L_48 : L_49 ;
F_91 ( V_10 , V_56 , V_90 ) ;
F_110 ( V_72 , sizeof( V_72 ) , L_36 ,
F_27 ( V_10 ) , V_127 ? L_33 : L_50 ) ;
fprintf ( V_68 , V_165 , V_164 , V_128 ) ;
if ( V_127 )
fprintf ( V_68 , L_36 , V_10 -> V_83 , V_128 ) ;
else
fprintf ( V_68 , L_51 , V_117 , V_10 -> V_83 , V_128 ) ;
fprintf ( V_68 , V_166 , V_72 ) ;
if ( V_10 -> V_167 )
fprintf ( V_68 , L_36 , V_128 , V_10 -> V_167 -> V_72 ) ;
}
static int F_111 ( struct V_9 * V_10 , int V_56 )
{
int V_156 ;
if ( ! V_168 )
return 0 ;
if ( V_14 . V_137 == V_140 )
return V_56 ;
if ( V_14 . V_137 == V_143 )
return 0 ;
for ( V_156 = 0 ; V_156 < F_24 ( V_10 ) ; V_156 ++ ) {
int V_169 = F_10 ( V_10 ) -> V_141 [ V_156 ] ;
if ( V_168 ( V_8 -> V_87 , V_169 ) == V_56 )
return V_169 ;
}
return 0 ;
}
static void F_112 ( int V_56 , int V_90 , struct V_9 * V_10 , double V_130 )
{
T_9 * V_68 = V_14 . V_68 ;
double V_170 = V_10 -> V_15 ;
const char * V_152 ;
if ( V_127 ) {
V_152 = floor ( V_170 ) != V_170 ? L_52 : L_53 ;
} else {
if ( V_171 )
V_152 = floor ( V_170 ) != V_170 ? L_54 : L_55 ;
else
V_152 = floor ( V_170 ) != V_170 ? L_56 : L_57 ;
}
F_91 ( V_10 , V_56 , V_90 ) ;
fprintf ( V_68 , V_152 , V_130 , V_128 ) ;
if ( V_10 -> V_83 )
fprintf ( V_68 , L_51 ,
V_127 ? 0 : V_117 ,
V_10 -> V_83 , V_128 ) ;
fprintf ( V_68 , L_32 , V_127 ? 0 : 25 , F_27 ( V_10 ) ) ;
if ( V_10 -> V_167 )
fprintf ( V_68 , L_36 , V_128 , V_10 -> V_167 -> V_72 ) ;
}
static void F_113 ( int V_56 , int V_90 , struct V_9 * V_49 , double V_172 ,
char * V_150 , T_3 V_66 , T_3 V_65 , double V_173 )
{
struct V_174 V_153 ;
struct V_146 V_147 = {
. V_149 = V_14 . V_68 ,
. V_150 = V_150 ? V_150 : L_33 ,
. V_56 = V_56 ,
. V_90 = V_90 ,
. V_10 = V_49 ,
} ;
T_10 V_175 = F_98 ;
void (* F_114)( void * );
if ( V_176 ) {
F_114 = F_107 ;
if ( V_127 )
V_175 = F_106 ;
else
V_175 = F_105 ;
} else
F_114 = F_96 ;
if ( V_127 && ! V_176 ) {
static int V_177 [] = {
[ V_143 ] = 0 ,
[ V_142 ] = 1 ,
[ V_140 ] = 1 ,
[ V_139 ] = 2 ,
[ V_138 ] = 2 ,
} ;
V_175 = F_101 ;
F_114 = F_100 ;
V_147 . V_157 = 3 ;
V_147 . V_157 += V_177 [ V_14 . V_137 ] ;
if ( V_49 -> V_167 )
V_147 . V_157 ++ ;
}
if ( V_66 == 0 || V_65 == 0 || V_49 -> V_62 -> V_64 == - 1 ) {
if ( V_176 ) {
V_175 ( & V_147 , NULL , L_33 , L_33 , 0 ) ;
return;
}
F_91 ( V_49 , V_56 , V_90 ) ;
fprintf ( V_14 . V_68 , L_58 ,
V_127 ? 0 : 18 ,
V_49 -> V_59 ? V_178 : V_179 ,
V_128 ) ;
if ( V_49 -> V_59 )
V_180 = 1 ;
fprintf ( V_14 . V_68 , L_51 ,
V_127 ? 0 : V_117 ,
V_49 -> V_83 , V_128 ) ;
fprintf ( V_14 . V_68 , L_44 ,
V_127 ? 0 : - 25 ,
F_27 ( V_49 ) ) ;
if ( V_49 -> V_167 )
fprintf ( V_14 . V_68 , L_36 ,
V_128 , V_49 -> V_167 -> V_72 ) ;
if ( ! V_127 )
V_175 ( & V_147 , NULL , NULL , L_33 , 0 ) ;
F_89 ( V_49 , V_173 ) ;
F_86 ( V_66 , V_65 ) ;
if ( V_127 )
V_175 ( & V_147 , NULL , NULL , L_33 , 0 ) ;
return;
}
if ( V_176 )
;
else if ( F_12 ( V_49 ) )
F_109 ( V_56 , V_90 , V_49 , V_172 ) ;
else
F_112 ( V_56 , V_90 , V_49 , V_172 ) ;
V_153 . V_181 = V_175 ;
V_153 . V_182 = F_114 ;
V_153 . V_145 = & V_147 ;
V_153 . V_183 = false ;
if ( V_127 && ! V_176 ) {
F_89 ( V_49 , V_173 ) ;
F_86 ( V_66 , V_65 ) ;
}
F_115 ( V_49 , V_172 ,
F_111 ( V_49 , V_56 ) ,
& V_153 ) ;
if ( ! V_127 && ! V_176 ) {
F_89 ( V_49 , V_173 ) ;
F_86 ( V_66 , V_65 ) ;
}
}
static void F_116 ( void )
{
int V_50 , V_184 , V_56 , V_185 ;
T_3 V_70 ;
struct V_9 * V_49 ;
for ( V_185 = 0 ; V_185 < V_186 -> V_90 ; V_185 ++ ) {
V_56 = V_186 -> V_141 [ V_185 ] ;
F_29 (evsel_list, counter) {
V_70 = 0 ;
for ( V_50 = 0 ; V_50 < F_24 ( V_49 ) ; V_50 ++ ) {
V_184 = V_168 ( V_8 -> V_87 , V_50 ) ;
if ( V_184 != V_56 )
continue;
V_70 += F_25 ( V_49 -> V_62 , V_50 , 0 ) -> V_70 ;
}
V_70 = V_70 * V_49 -> V_15 ;
F_117 ( V_49 , & V_70 ,
F_111 ( V_49 , V_56 ) ) ;
}
}
}
static void F_118 ( struct V_9 * V_49 ,
void (* F_119)( struct V_9 * V_49 , void * V_187 ,
bool V_188 ) ,
void * V_187 )
{
struct V_9 * V_189 ;
V_189 = F_120 ( V_49 , & ( V_8 -> V_190 ) , V_191 ) ;
F_121 (alias, &evsel_list->entries, node) {
if ( strcmp ( F_27 ( V_189 ) , F_27 ( V_49 ) ) ||
V_189 -> V_15 != V_49 -> V_15 ||
V_189 -> V_167 != V_49 -> V_167 ||
strcmp ( V_189 -> V_83 , V_49 -> V_83 ) ||
F_12 ( V_189 ) != F_12 ( V_49 ) )
break;
V_189 -> V_192 = true ;
F_119 ( V_189 , V_187 , false ) ;
}
}
static bool F_122 ( struct V_9 * V_49 ,
void (* F_119)( struct V_9 * V_49 , void * V_187 ,
bool V_188 ) ,
void * V_187 )
{
if ( V_49 -> V_192 )
return false ;
F_119 ( V_49 , V_187 , true ) ;
if ( ! V_193 && V_49 -> V_194 )
F_118 ( V_49 , F_119 , V_187 ) ;
return true ;
}
static void F_123 ( struct V_9 * V_49 , void * V_187 , bool V_188 )
{
struct V_195 * V_196 = V_187 ;
int V_50 , V_184 ;
for ( V_50 = 0 ; V_50 < F_24 ( V_49 ) ; V_50 ++ ) {
struct V_52 * V_62 ;
V_184 = V_168 ( F_10 ( V_49 ) , V_50 ) ;
if ( V_184 != V_196 -> V_56 )
continue;
if ( V_188 )
V_196 -> V_90 ++ ;
V_62 = F_25 ( V_49 -> V_62 , V_50 , 0 ) ;
if ( V_62 -> V_65 == 0 || V_62 -> V_66 == 0 ||
V_49 -> V_62 -> V_64 == - 1 ) {
V_196 -> V_65 = 0 ;
V_196 -> V_66 = 0 ;
break;
}
V_196 -> V_70 += V_62 -> V_70 ;
V_196 -> V_65 += V_62 -> V_65 ;
V_196 -> V_66 += V_62 -> V_66 ;
}
}
static void F_124 ( char * V_150 )
{
T_9 * V_68 = V_14 . V_68 ;
struct V_9 * V_49 ;
int V_185 , V_56 , V_90 ;
double V_172 ;
T_3 V_65 , V_66 , V_70 ;
bool V_188 ;
if ( ! ( V_186 || V_168 ) )
return;
F_116 () ;
for ( V_185 = 0 ; V_185 < V_186 -> V_90 ; V_185 ++ ) {
struct V_195 V_196 ;
if ( V_150 && V_176 )
fprintf ( V_68 , L_48 , V_150 ) ;
V_196 . V_56 = V_56 = V_186 -> V_141 [ V_185 ] ;
V_188 = true ;
F_29 (evsel_list, counter) {
V_196 . V_70 = V_196 . V_65 = V_196 . V_66 = 0 ;
V_196 . V_90 = 0 ;
if ( ! F_122 ( V_49 , F_123 , & V_196 ) )
continue;
V_90 = V_196 . V_90 ;
V_65 = V_196 . V_65 ;
V_66 = V_196 . V_66 ;
V_70 = V_196 . V_70 ;
if ( V_188 && V_176 ) {
V_188 = false ;
F_91 ( V_49 , V_56 , V_90 ) ;
}
if ( V_150 && ! V_176 )
fprintf ( V_68 , L_48 , V_150 ) ;
V_172 = V_70 * V_49 -> V_15 ;
F_113 ( V_56 , V_90 , V_49 , V_172 , V_150 , V_66 , V_65 , 1.0 ) ;
if ( ! V_176 )
fputc ( '\n' , V_68 ) ;
}
if ( V_176 )
fputc ( '\n' , V_68 ) ;
}
}
static void F_125 ( struct V_9 * V_49 , char * V_150 )
{
T_9 * V_68 = V_14 . V_68 ;
int V_57 = F_23 ( V_49 -> V_35 ) ;
int V_58 = F_126 ( V_49 -> V_87 ) ;
int V_50 , V_51 ;
double V_172 ;
for ( V_51 = 0 ; V_51 < V_57 ; V_51 ++ ) {
T_3 V_65 = 0 , V_66 = 0 , V_70 = 0 ;
for ( V_50 = 0 ; V_50 < V_58 ; V_50 ++ ) {
V_70 += F_25 ( V_49 -> V_62 , V_50 , V_51 ) -> V_70 ;
V_65 += F_25 ( V_49 -> V_62 , V_50 , V_51 ) -> V_65 ;
V_66 += F_25 ( V_49 -> V_62 , V_50 , V_51 ) -> V_66 ;
}
if ( V_150 )
fprintf ( V_68 , L_48 , V_150 ) ;
V_172 = V_70 * V_49 -> V_15 ;
F_113 ( V_51 , 0 , V_49 , V_172 , V_150 , V_66 , V_65 , 1.0 ) ;
fputc ( '\n' , V_68 ) ;
}
}
static void F_127 ( struct V_9 * V_49 , void * V_187 ,
bool V_188 V_40 )
{
struct V_197 * V_198 = V_187 ;
struct V_132 * V_133 = V_49 -> V_135 ;
V_198 -> V_130 += F_128 ( & V_133 -> V_136 [ 0 ] ) ;
V_198 -> V_199 += F_128 ( & V_133 -> V_136 [ 1 ] ) ;
V_198 -> V_200 += F_128 ( & V_133 -> V_136 [ 2 ] ) ;
}
static void F_129 ( struct V_9 * V_49 , char * V_150 )
{
T_9 * V_68 = V_14 . V_68 ;
double V_172 ;
struct V_197 V_198 = { . V_130 = 0.0 } ;
if ( ! F_122 ( V_49 , F_127 , & V_198 ) )
return;
if ( V_150 && ! V_176 )
fprintf ( V_68 , L_48 , V_150 ) ;
V_172 = V_198 . V_130 * V_49 -> V_15 ;
F_113 ( - 1 , 0 , V_49 , V_172 , V_150 , V_198 . V_200 , V_198 . V_199 , V_198 . V_130 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_5 ) ;
}
static void F_130 ( struct V_9 * V_49 , void * V_187 ,
bool V_188 V_40 )
{
struct V_195 * V_196 = V_187 ;
V_196 -> V_70 += F_25 ( V_49 -> V_62 , V_196 -> V_50 , 0 ) -> V_70 ;
V_196 -> V_65 += F_25 ( V_49 -> V_62 , V_196 -> V_50 , 0 ) -> V_65 ;
V_196 -> V_66 += F_25 ( V_49 -> V_62 , V_196 -> V_50 , 0 ) -> V_66 ;
}
static void F_131 ( struct V_9 * V_49 , char * V_150 )
{
T_9 * V_68 = V_14 . V_68 ;
T_3 V_65 , V_66 , V_70 ;
double V_172 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_24 ( V_49 ) ; V_50 ++ ) {
struct V_195 V_196 = { . V_50 = V_50 } ;
if ( ! F_122 ( V_49 , F_130 , & V_196 ) )
return;
V_70 = V_196 . V_70 ;
V_65 = V_196 . V_65 ;
V_66 = V_196 . V_66 ;
if ( V_150 )
fprintf ( V_68 , L_48 , V_150 ) ;
V_172 = V_70 * V_49 -> V_15 ;
F_113 ( V_50 , 0 , V_49 , V_172 , V_150 , V_66 , V_65 , 1.0 ) ;
fputc ( '\n' , V_68 ) ;
}
}
static void F_132 ( char * V_150 )
{
int V_50 ;
int V_201 = 0 ;
struct V_9 * V_49 ;
T_3 V_65 , V_66 , V_70 ;
double V_172 ;
V_201 = V_8 -> V_87 -> V_90 ;
for ( V_50 = 0 ; V_50 < V_201 ; V_50 ++ ) {
bool V_188 = true ;
if ( V_150 )
fputs ( V_150 , V_14 . V_68 ) ;
F_29 (evsel_list, counter) {
if ( V_188 ) {
F_91 ( V_49 , V_50 , 0 ) ;
V_188 = false ;
}
V_70 = F_25 ( V_49 -> V_62 , V_50 , 0 ) -> V_70 ;
V_65 = F_25 ( V_49 -> V_62 , V_50 , 0 ) -> V_65 ;
V_66 = F_25 ( V_49 -> V_62 , V_50 , 0 ) -> V_66 ;
V_172 = V_70 * V_49 -> V_15 ;
F_113 ( V_50 , 0 , V_49 , V_172 , V_150 , V_66 , V_65 , 1.0 ) ;
}
fputc ( '\n' , V_14 . V_68 ) ;
}
}
static void F_133 ( const char * V_150 , bool V_202 )
{
struct V_174 V_153 ;
struct V_9 * V_49 ;
struct V_146 V_147 = {
. V_149 = V_14 . V_68
} ;
if ( V_150 )
fprintf ( V_14 . V_68 , L_48 , V_150 ) ;
if ( ! V_127 && ! V_202 )
fprintf ( V_14 . V_68 , L_44 ,
V_203 [ V_14 . V_137 ] , L_33 ) ;
if ( V_127 ) {
if ( V_14 . V_95 )
fputs ( L_59 , V_14 . V_68 ) ;
fputs ( V_204 [ V_14 . V_137 ] ,
V_14 . V_68 ) ;
}
F_29 (evsel_list, counter) {
V_147 . V_10 = V_49 ;
V_153 . V_145 = & V_147 ;
V_153 . V_181 = F_108 ;
V_153 . V_182 = F_107 ;
V_153 . V_183 = true ;
V_147 . V_10 = V_49 ;
F_115 ( V_49 , 0 ,
0 ,
& V_153 ) ;
}
fputc ( '\n' , V_14 . V_68 ) ;
}
static void F_134 ( char * V_150 , struct V_1 * V_73 )
{
T_9 * V_68 = V_14 . V_68 ;
static int V_205 ;
sprintf ( V_150 , L_60 , V_73 -> V_5 , V_73 -> V_6 , V_128 ) ;
if ( V_205 == 0 && ! V_127 ) {
switch ( V_14 . V_137 ) {
case V_139 :
fprintf ( V_68 , L_61 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_62 , V_117 , L_63 ) ;
break;
case V_138 :
fprintf ( V_68 , L_64 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_62 , V_117 , L_63 ) ;
break;
case V_140 :
fprintf ( V_68 , L_65 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_66 , V_117 , L_63 ) ;
break;
case V_142 :
fprintf ( V_68 , L_67 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_68 , V_117 , L_63 ) ;
break;
case V_143 :
default:
fprintf ( V_68 , L_69 ) ;
if ( ! V_176 )
fprintf ( V_68 , L_62 , V_117 , L_63 ) ;
case V_144 :
break;
}
}
if ( V_205 == 0 && V_176 )
F_133 ( L_70 , true ) ;
if ( ++ V_205 == 25 )
V_205 = 0 ;
}
static void F_135 ( int V_93 , const char * * V_94 )
{
T_9 * V_68 = V_14 . V_68 ;
int V_156 ;
fflush ( stdout ) ;
if ( ! V_127 ) {
fprintf ( V_68 , L_5 ) ;
fprintf ( V_68 , L_71 ) ;
if ( V_32 . V_61 )
fprintf ( V_68 , L_72 ) ;
else if ( V_32 . V_206 )
fprintf ( V_68 , L_73 , V_32 . V_206 ) ;
else if ( ! F_136 ( & V_32 ) ) {
fprintf ( V_68 , L_74 , V_94 ? V_94 [ 0 ] : L_75 ) ;
for ( V_156 = 1 ; V_94 && ( V_156 < V_93 ) ; V_156 ++ )
fprintf ( V_68 , L_76 , V_94 [ V_156 ] ) ;
} else if ( V_32 . V_108 )
fprintf ( V_68 , L_77 , V_32 . V_108 ) ;
else
fprintf ( V_68 , L_78 , V_32 . V_207 ) ;
fprintf ( V_68 , L_79 ) ;
if ( V_134 > 1 )
fprintf ( V_68 , L_80 , V_134 ) ;
fprintf ( V_68 , L_81 ) ;
}
}
static void F_137 ( void )
{
T_9 * V_68 = V_14 . V_68 ;
int V_154 ;
if ( ! V_208 )
fprintf ( V_68 , L_5 ) ;
fprintf ( V_68 , L_82 ,
F_128 ( & V_123 ) / V_7 ) ;
if ( V_134 > 1 ) {
fprintf ( V_68 , L_83 ) ;
F_87 ( F_90 ( & V_123 ) ,
F_128 ( & V_123 ) ) ;
}
fprintf ( V_68 , L_84 ) ;
if ( V_180 &&
F_138 ( L_85 , & V_154 ) >= 0 &&
V_154 > 0 )
fprintf ( V_68 ,
L_86
L_87
L_88
L_89 ) ;
}
static void F_36 ( struct V_1 * V_73 , int V_93 , const char * * V_94 )
{
int V_95 = V_14 . V_95 ;
struct V_9 * V_49 ;
char V_158 [ 64 ] , * V_150 = NULL ;
if ( V_25 && V_26 . V_27 . V_28 )
return;
if ( V_95 )
F_134 ( V_150 = V_158 , V_73 ) ;
else
F_135 ( V_93 , V_94 ) ;
if ( V_176 ) {
static int V_209 ;
if ( V_209 == 0 && ! V_95 )
F_133 ( V_150 , false ) ;
if ( V_209 ++ == 25 )
V_209 = 0 ;
if ( V_14 . V_137 == V_143 && V_150 )
fprintf ( V_14 . V_68 , L_48 , V_150 ) ;
}
switch ( V_14 . V_137 ) {
case V_138 :
case V_139 :
F_124 ( V_150 ) ;
break;
case V_142 :
F_29 (evsel_list, counter)
F_125 ( V_49 , V_150 ) ;
break;
case V_143 :
F_29 (evsel_list, counter)
F_129 ( V_49 , V_150 ) ;
if ( V_176 )
fputc ( '\n' , V_14 . V_68 ) ;
break;
case V_140 :
if ( V_176 )
F_132 ( V_150 ) ;
else {
F_29 (evsel_list, counter)
F_131 ( V_49 , V_150 ) ;
}
break;
case V_144 :
default:
break;
}
if ( ! V_95 && ! V_127 )
F_137 () ;
fflush ( V_14 . V_68 ) ;
}
static void F_139 ( int T_5 )
{
if ( ( V_106 == - 1 ) || V_14 . V_95 )
V_122 = 1 ;
V_210 = T_5 ;
V_106 = - 1 ;
}
static void F_140 ( void )
{
T_11 V_211 , V_212 ;
F_141 ( & V_211 ) ;
F_142 ( & V_211 , V_213 ) ;
F_143 ( V_214 , & V_211 , & V_212 ) ;
if ( V_106 != - 1 )
F_67 ( V_106 , V_116 ) ;
F_143 ( V_215 , & V_212 , NULL ) ;
if ( V_210 == - 1 )
return;
signal ( V_210 , V_216 ) ;
F_67 ( F_144 () , V_210 ) ;
}
static int F_145 ( const struct V_217 * T_12 V_40 ,
const char * V_185 V_40 , int V_218 )
{
V_219 = V_218 ? 0 : 1 ;
return 0 ;
}
static int F_146 ( const struct V_217 * T_12 V_40 ,
const char * V_185 V_40 , int V_218 )
{
V_220 = true ;
V_176 = ! V_218 ;
return 0 ;
}
static int F_147 ( struct V_88 * V_141 , int V_50 )
{
return F_148 ( V_141 , V_50 , NULL ) ;
}
static int F_149 ( struct V_88 * V_141 , int V_50 )
{
return F_150 ( V_141 , V_50 , NULL ) ;
}
static int F_151 ( struct V_88 * V_141 )
{
int V_156 , V_221 = - 1 ;
for ( V_156 = 0 ; V_156 < V_141 -> V_90 ; V_156 ++ ) {
if ( V_141 -> V_141 [ V_156 ] > V_221 )
V_221 = V_141 -> V_141 [ V_156 ] ;
}
return V_221 ;
}
static int F_152 ( T_13 V_222 , struct V_88 * V_141 , int V_223 )
{
int V_50 ;
if ( V_223 >= V_141 -> V_90 )
return - 1 ;
V_50 = V_141 -> V_141 [ V_223 ] ;
if ( V_224 -> V_141 [ V_50 ] == - 1 )
V_224 -> V_141 [ V_50 ] = V_222 ( V_141 , V_223 ) ;
return V_224 -> V_141 [ V_50 ] ;
}
static int F_153 ( struct V_88 * V_141 , int V_223 )
{
return F_152 ( F_147 , V_141 , V_223 ) ;
}
static int F_154 ( struct V_88 * V_141 , int V_223 )
{
return F_152 ( F_149 , V_141 , V_223 ) ;
}
static int F_155 ( void )
{
int V_90 ;
switch ( V_14 . V_137 ) {
case V_139 :
if ( F_156 ( V_8 -> V_87 , & V_186 ) ) {
perror ( L_90 ) ;
return - 1 ;
}
V_168 = F_153 ;
break;
case V_138 :
if ( F_157 ( V_8 -> V_87 , & V_186 ) ) {
perror ( L_91 ) ;
return - 1 ;
}
V_168 = F_154 ;
break;
case V_140 :
case V_143 :
case V_142 :
case V_144 :
default:
break;
}
V_90 = F_151 ( V_8 -> V_87 ) ;
V_224 = F_158 ( V_90 + 1 ) ;
return V_224 ? 0 : - V_92 ;
}
static void F_159 ( void )
{
F_160 ( V_186 ) ;
F_160 ( V_224 ) ;
V_186 = NULL ;
V_224 = NULL ;
}
static inline int F_161 ( struct V_225 * V_226 , struct V_88 * V_141 , int V_223 )
{
int V_50 ;
if ( V_223 > V_141 -> V_90 )
return - 1 ;
V_50 = V_141 -> V_141 [ V_223 ] ;
if ( V_50 >= V_226 -> V_227 )
return - 1 ;
return V_50 ;
}
static int F_162 ( struct V_88 * V_141 , int V_223 , void * V_187 )
{
struct V_225 * V_226 = V_187 ;
int V_50 = F_161 ( V_226 , V_141 , V_223 ) ;
return V_50 == - 1 ? - 1 : V_226 -> V_50 [ V_50 ] . V_228 ;
}
static int F_163 ( struct V_88 * V_141 , int V_223 , void * V_187 )
{
struct V_225 * V_226 = V_187 ;
int V_229 = - 1 , V_50 = F_161 ( V_226 , V_141 , V_223 ) ;
if ( V_50 != - 1 ) {
int V_228 = V_226 -> V_50 [ V_50 ] . V_228 ;
V_229 = ( V_228 << 16 ) | ( V_226 -> V_50 [ V_50 ] . V_230 & 0xffff ) ;
}
return V_229 ;
}
static int F_164 ( struct V_225 * V_226 , struct V_88 * V_87 ,
struct V_88 * * V_231 )
{
return F_165 ( V_87 , V_231 , F_162 , V_226 ) ;
}
static int F_166 ( struct V_225 * V_226 , struct V_88 * V_87 ,
struct V_88 * * V_232 )
{
return F_165 ( V_87 , V_232 , F_163 , V_226 ) ;
}
static int F_167 ( struct V_88 * V_141 , int V_223 )
{
return F_162 ( V_141 , V_223 , & V_26 . V_85 -> V_45 . V_226 ) ;
}
static int F_168 ( struct V_88 * V_141 , int V_223 )
{
return F_163 ( V_141 , V_223 , & V_26 . V_85 -> V_45 . V_226 ) ;
}
static int F_169 ( struct V_26 * V_233 )
{
struct V_225 * V_226 = & V_233 -> V_85 -> V_45 . V_226 ;
switch ( V_14 . V_137 ) {
case V_139 :
if ( F_164 ( V_226 , V_8 -> V_87 , & V_186 ) ) {
perror ( L_90 ) ;
return - 1 ;
}
V_168 = F_167 ;
break;
case V_138 :
if ( F_166 ( V_226 , V_8 -> V_87 , & V_186 ) ) {
perror ( L_91 ) ;
return - 1 ;
}
V_168 = F_168 ;
break;
case V_140 :
case V_143 :
case V_142 :
case V_144 :
default:
break;
}
return 0 ;
}
static int F_170 ( const char * * V_12 , char * * V_234 , bool V_235 )
{
int V_236 = 0 ;
int V_156 ;
int V_237 = 0 ;
char * V_185 ;
for ( V_156 = 0 ; V_12 [ V_156 ] ; V_156 ++ ) {
if ( F_171 ( L_92 , V_12 [ V_156 ] ) ) {
V_237 += strlen ( V_12 [ V_156 ] ) + 1 ;
V_12 [ V_156 - V_236 ] = V_12 [ V_156 ] ;
} else
V_236 ++ ;
}
V_12 [ V_156 - V_236 ] = NULL ;
* V_234 = malloc ( V_237 + 1 + 2 ) ;
if ( ! * V_234 )
return - 1 ;
V_185 = * V_234 ;
if ( V_156 - V_236 == 0 ) {
* V_185 = 0 ;
return 0 ;
}
if ( V_235 )
* V_185 ++ = '{' ;
for ( V_156 = 0 ; V_12 [ V_156 ] ; V_156 ++ ) {
strcpy ( V_185 , V_12 [ V_156 ] ) ;
V_185 += strlen ( V_185 ) ;
* V_185 ++ = ',' ;
}
if ( V_235 ) {
V_185 [ - 1 ] = '}' ;
* V_185 = 0 ;
} else
V_185 [ - 1 ] = 0 ;
return 0 ;
}
__weak bool F_172 ( bool * V_238 )
{
* V_238 = false ;
return false ;
}
__weak void F_173 ( void )
{
}
static int F_174 ( void )
{
int V_84 ;
struct V_11 V_239 [] = {
{ . type = V_240 , . V_241 = V_242 } ,
{ . type = V_240 , . V_241 = V_243 } ,
{ . type = V_240 , . V_241 = V_244 } ,
{ . type = V_240 , . V_241 = V_245 } ,
{ . type = V_246 , . V_241 = V_247 } ,
} ;
struct V_11 V_248 [] = {
{ . type = V_246 , . V_241 = V_249 } ,
} ;
struct V_11 V_250 [] = {
{ . type = V_246 , . V_241 = V_251 } ,
} ;
struct V_11 V_252 [] = {
{ . type = V_246 , . V_241 = V_253 } ,
{ . type = V_246 , . V_241 = V_254 } ,
{ . type = V_246 , . V_241 = V_255 } ,
} ;
struct V_11 V_256 [] = {
{ . type = V_257 ,
. V_241 =
V_258 << 0 |
( V_259 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_258 << 0 |
( V_259 << 8 ) |
( V_261 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_262 << 0 |
( V_259 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_262 << 0 |
( V_259 << 8 ) |
( V_261 << 16 ) } ,
} ;
struct V_11 V_263 [] = {
{ . type = V_257 ,
. V_241 =
V_264 << 0 |
( V_259 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_264 << 0 |
( V_259 << 8 ) |
( V_261 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_265 << 0 |
( V_259 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_265 << 0 |
( V_259 << 8 ) |
( V_261 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_266 << 0 |
( V_259 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_266 << 0 |
( V_259 << 8 ) |
( V_261 << 16 ) } ,
} ;
struct V_11 V_267 [] = {
{ . type = V_257 ,
. V_241 =
V_258 << 0 |
( V_268 << 8 ) |
( V_260 << 16 ) } ,
{ . type = V_257 ,
. V_241 =
V_258 << 0 |
( V_268 << 8 ) |
( V_261 << 16 ) } ,
} ;
if ( V_208 )
return 0 ;
if ( V_269 ) {
if ( F_171 ( L_92 , L_93 ) &&
F_171 ( L_92 , L_94 ) )
V_84 = F_175 ( V_8 , V_270 , NULL ) ;
else
V_84 = F_175 ( V_8 , V_271 , NULL ) ;
if ( V_84 ) {
fprintf ( V_272 , L_95 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_273 ) {
int V_274 ;
if ( F_176 ( V_275 , & V_274 ) < 0 ) {
fprintf ( V_272 , L_96 ) ;
return - 1 ;
}
if ( ! V_274 ) {
if ( F_177 ( V_275 , 1 ) < 0 ) {
fprintf ( V_272 , L_97 ) ;
return - 1 ;
}
V_276 = true ;
}
if ( F_171 ( L_98 , L_99 ) &&
F_171 ( L_98 , L_100 ) ) {
if ( ! V_220 )
V_176 = true ;
V_84 = F_175 ( V_8 , V_277 , NULL ) ;
} else {
fprintf ( V_272 , L_101
L_102 ) ;
return - 1 ;
}
if ( V_84 ) {
fprintf ( V_272 , L_103 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_278 ) {
char * V_234 = NULL ;
bool V_238 = false ;
if ( V_14 . V_137 != V_143 &&
V_14 . V_137 != V_138 ) {
F_16 ( L_104 ) ;
return - 1 ;
}
V_14 . V_137 = V_138 ;
if ( V_279 || ! F_8 ( & V_32 ) ) {
F_16 ( L_105 ) ;
return - 1 ;
}
if ( ! V_220 )
V_176 = true ;
if ( F_170 ( V_280 , & V_234 ,
F_172 ( & V_238 ) ) < 0 ) {
F_16 ( L_106 ) ;
return - 1 ;
}
if ( V_280 [ 0 ] && V_234 ) {
if ( V_238 )
F_173 () ;
V_84 = F_175 ( V_8 , V_234 , NULL ) ;
if ( V_84 ) {
fprintf ( V_272 ,
L_107 ,
V_234 , V_84 ) ;
free ( V_234 ) ;
return - 1 ;
}
} else {
fprintf ( V_272 , L_108 ) ;
return - 1 ;
}
free ( V_234 ) ;
}
if ( ! V_8 -> V_281 ) {
if ( F_8 ( & V_32 ) )
V_239 [ 0 ] . V_241 = V_282 ;
if ( F_178 ( V_8 , V_239 ) < 0 )
return - 1 ;
if ( F_171 ( L_92 , L_109 ) ) {
if ( F_178 ( V_8 ,
V_248 ) < 0 )
return - 1 ;
}
if ( F_171 ( L_92 , L_110 ) ) {
if ( F_178 ( V_8 ,
V_250 ) < 0 )
return - 1 ;
}
if ( F_178 ( V_8 , V_252 ) < 0 )
return - 1 ;
}
if ( V_283 < 1 )
return 0 ;
if ( F_178 ( V_8 , V_256 ) < 0 )
return - 1 ;
if ( V_283 < 2 )
return 0 ;
if ( F_178 ( V_8 , V_263 ) < 0 )
return - 1 ;
if ( V_283 < 3 )
return 0 ;
return F_178 ( V_8 , V_267 ) ;
}
static void F_179 ( struct V_284 * V_85 )
{
int V_285 ;
for ( V_285 = V_286 ; V_285 < V_287 ; V_285 ++ )
F_180 ( & V_85 -> V_45 , V_285 ) ;
F_181 ( & V_85 -> V_45 , V_288 ) ;
F_181 ( & V_85 -> V_45 , V_289 ) ;
F_181 ( & V_85 -> V_45 , V_290 ) ;
F_181 ( & V_85 -> V_45 , V_291 ) ;
}
static int F_182 ( int V_93 , const char * * V_94 )
{
struct V_284 * V_85 ;
struct V_292 * V_27 = & V_26 . V_27 ;
V_93 = F_183 ( V_93 , V_94 , V_293 , V_294 ,
V_295 ) ;
if ( V_296 )
V_27 -> V_297 = V_296 ;
if ( V_134 != 1 || V_298 ) {
F_16 ( L_111 ) ;
return - 1 ;
}
V_85 = F_184 ( V_27 , false , NULL ) ;
if ( V_85 == NULL ) {
F_16 ( L_112 ) ;
return - 1 ;
}
F_179 ( V_85 ) ;
V_85 -> V_299 = V_8 ;
V_26 . V_85 = V_85 ;
V_26 . V_300 = true ;
return V_93 ;
}
static int F_185 ( struct V_39 * T_1 V_40 ,
union V_41 * V_42 ,
struct V_284 * V_85 )
{
struct V_301 * V_302 = & V_42 -> V_302 ;
struct V_9 * V_49 ;
struct V_1 V_303 , * V_73 = NULL ;
const char * * V_94 = V_85 -> V_45 . V_226 . V_304 ;
int V_93 = V_85 -> V_45 . V_226 . V_305 ;
F_29 (evsel_list, counter)
F_31 ( & V_14 , V_49 ) ;
if ( V_302 -> type == V_306 )
F_81 ( & V_123 , V_302 -> time ) ;
if ( V_14 . V_95 && V_302 -> time ) {
V_303 . V_5 = V_302 -> time / V_7 ;
V_303 . V_6 = V_302 -> time % V_7 ;
V_73 = & V_303 ;
}
F_36 ( V_73 , V_93 , V_94 ) ;
return 0 ;
}
static
int F_186 ( struct V_39 * T_1 ,
union V_41 * V_42 ,
struct V_284 * V_85 V_40 )
{
struct V_26 * V_233 = F_187 ( T_1 , struct V_26 , T_1 ) ;
F_188 ( & V_14 , & V_42 -> V_14 ) ;
if ( F_189 ( V_233 -> V_87 ) ) {
if ( V_233 -> V_137 != V_144 )
F_32 ( L_113 ) ;
return 0 ;
}
if ( V_233 -> V_137 != V_144 )
V_14 . V_137 = V_233 -> V_137 ;
if ( V_26 . V_27 . V_28 )
F_155 () ;
else
F_169 ( V_233 ) ;
return 0 ;
}
static int F_190 ( struct V_26 * V_233 )
{
if ( ! V_233 -> V_87 || ! V_233 -> V_35 )
return 0 ;
if ( F_191 ( V_233 -> V_307 , L_114 ) )
return - V_112 ;
F_192 ( V_8 , V_233 -> V_87 , V_233 -> V_35 ) ;
if ( F_193 ( V_8 , true ) )
return - V_92 ;
V_233 -> V_307 = true ;
return 0 ;
}
static
int F_194 ( struct V_39 * T_1 ,
union V_41 * V_42 ,
struct V_284 * V_85 V_40 )
{
struct V_26 * V_233 = F_187 ( T_1 , struct V_26 , T_1 ) ;
if ( V_233 -> V_35 ) {
F_32 ( L_115 ) ;
return 0 ;
}
V_233 -> V_35 = F_195 ( & V_42 -> V_89 ) ;
if ( ! V_233 -> V_35 )
return - V_92 ;
return F_190 ( V_233 ) ;
}
static
int F_196 ( struct V_39 * T_1 ,
union V_41 * V_42 ,
struct V_284 * V_85 V_40 )
{
struct V_26 * V_233 = F_187 ( T_1 , struct V_26 , T_1 ) ;
struct V_88 * V_87 ;
if ( V_233 -> V_87 ) {
F_32 ( L_116 ) ;
return 0 ;
}
V_87 = F_197 ( & V_42 -> V_88 . V_187 ) ;
if ( ! V_87 )
return - V_92 ;
V_233 -> V_87 = V_87 ;
return F_190 ( V_233 ) ;
}
static int F_198 ( int V_93 , const char * * V_94 )
{
struct V_284 * V_85 ;
const struct V_217 V_308 [] = {
F_199 ( 'i' , L_117 , & V_309 , L_118 , L_119 ) ,
F_200 ( 0 , L_120 , & V_26 . V_137 ,
L_121 , V_139 ) ,
F_200 ( 0 , L_122 , & V_26 . V_137 ,
L_123 , V_138 ) ,
F_200 ( 'A' , L_124 , & V_26 . V_137 ,
L_125 , V_140 ) ,
F_201 ()
} ;
struct V_310 V_233 ;
int V_71 ;
V_93 = F_183 ( V_93 , V_94 , V_308 , V_311 , 0 ) ;
if ( ! V_309 || ! strlen ( V_309 ) ) {
if ( ! F_202 ( V_312 , & V_233 ) && F_203 ( V_233 . V_313 ) )
V_309 = L_126 ;
else
V_309 = L_127 ;
}
V_26 . V_27 . V_297 = V_309 ;
V_26 . V_27 . V_314 = V_315 ;
V_85 = F_184 ( & V_26 . V_27 , false , & V_26 . T_1 ) ;
if ( V_85 == NULL )
return - 1 ;
V_26 . V_85 = V_85 ;
V_14 . V_68 = V_272 ;
V_8 = V_85 -> V_299 ;
V_71 = F_204 ( V_85 ) ;
if ( V_71 )
return V_71 ;
F_205 ( V_85 ) ;
return 0 ;
}
static void F_206 ( int V_102 )
{
if ( ! F_7 ( & V_32 ) )
return;
if ( ! V_102 )
V_32 . V_61 = true ;
else {
struct V_9 * V_49 ;
F_29 (evsel_list, counter) {
if ( ! V_49 -> V_61 )
return;
}
if ( V_8 -> V_281 )
V_32 . V_61 = true ;
}
}
int F_207 ( int V_93 , const char * * V_94 )
{
const char * const V_316 [] = {
L_128 ,
NULL
} ;
int V_101 = - V_112 , V_317 ;
const char * V_314 ;
T_9 * V_68 = V_272 ;
unsigned int V_95 ;
const char * const V_318 [] = { L_129 , L_130 } ;
setlocale ( V_319 , L_33 ) ;
V_8 = F_208 () ;
if ( V_8 == NULL )
return - V_92 ;
F_209 () ;
V_93 = F_210 ( V_93 , V_94 , V_293 , V_318 ,
( const char * * ) V_316 ,
V_295 ) ;
F_211 ( V_8 ) ;
F_212 () ;
if ( V_128 ) {
V_127 = true ;
if ( ! strcmp ( V_128 , L_131 ) )
V_128 = L_132 ;
} else
V_128 = V_320 ;
if ( V_93 && ! strncmp ( V_94 [ 0 ] , L_133 , 3 ) ) {
V_93 = F_182 ( V_93 , V_94 ) ;
if ( V_93 < 0 )
return - 1 ;
} else if ( V_93 && ! strncmp ( V_94 [ 0 ] , L_134 , 3 ) )
return F_198 ( V_93 , V_94 ) ;
V_95 = V_14 . V_95 ;
if ( ! V_25 && V_296 && strcmp ( V_296 , L_126 ) )
V_68 = NULL ;
if ( V_296 && V_321 ) {
fprintf ( V_272 , L_135 ) ;
F_213 ( V_316 , V_293 , L_136 , 1 ) ;
F_213 ( NULL , V_293 , L_137 , 0 ) ;
goto V_153;
}
if ( V_176 && V_14 . V_137 == V_142 ) {
fprintf ( V_272 , L_138 ) ;
goto V_153;
}
if ( V_176 && V_134 > 1 ) {
fprintf ( V_272 , L_139 ) ;
goto V_153;
}
if ( V_321 < 0 ) {
fprintf ( V_272 , L_140 ) ;
F_213 ( V_316 , V_293 , L_137 , 0 ) ;
goto V_153;
}
if ( ! V_68 ) {
struct V_1 V_48 ;
V_314 = V_322 ? L_141 : L_142 ;
V_68 = fopen ( V_296 , V_314 ) ;
if ( ! V_68 ) {
perror ( L_143 ) ;
return - 1 ;
}
F_34 ( V_323 , & V_48 ) ;
fprintf ( V_68 , L_144 , ctime ( & V_48 . V_5 ) ) ;
} else if ( V_321 > 0 ) {
V_314 = V_322 ? L_141 : L_142 ;
V_68 = fdopen ( V_321 , V_314 ) ;
if ( ! V_68 ) {
perror ( L_145 ) ;
return - V_111 ;
}
}
V_14 . V_68 = V_68 ;
if ( V_127 ) {
if ( V_219 == 1 ) {
fprintf ( V_272 , L_146 ) ;
F_213 ( V_316 , V_293 , L_147 , 1 ) ;
F_213 ( NULL , V_293 , L_148 , 1 ) ;
goto V_153;
} else
V_171 = false ;
} else if ( V_219 == 0 )
V_171 = false ;
F_206 ( V_93 ) ;
if ( V_134 < 0 ) {
F_16 ( L_149 ) ;
F_213 ( V_316 , V_293 , L_150 , 1 ) ;
goto V_153;
} else if ( V_134 == 0 ) {
V_298 = true ;
V_134 = 1 ;
}
if ( ( V_14 . V_137 == V_142 ) && ! F_136 ( & V_32 ) ) {
fprintf ( V_272 , L_151
L_152 ) ;
F_213 ( NULL , V_293 , L_153 , 1 ) ;
F_213 ( NULL , V_293 , L_154 , 1 ) ;
goto V_153;
}
if ( ( ( V_14 . V_137 != V_143 &&
V_14 . V_137 != V_142 ) || V_279 ) &&
! F_8 ( & V_32 ) ) {
fprintf ( V_272 , L_155
L_156 ) ;
F_213 ( V_316 , V_293 , L_157 , 1 ) ;
F_213 ( NULL , V_293 , L_158 , 1 ) ;
F_213 ( NULL , V_293 , L_141 , 1 ) ;
goto V_153;
}
if ( F_174 () )
goto V_153;
F_214 ( & V_32 ) ;
if ( F_215 ( V_8 , & V_32 ) < 0 ) {
if ( F_136 ( & V_32 ) ) {
F_16 ( L_159 ) ;
F_213 ( V_316 , V_293 , L_153 , 1 ) ;
F_213 ( NULL , V_293 , L_154 , 1 ) ;
} else if ( F_8 ( & V_32 ) ) {
perror ( L_160 ) ;
F_213 ( V_316 , V_293 , L_161 , 1 ) ;
F_213 ( NULL , V_293 , L_141 , 1 ) ;
}
goto V_153;
}
if ( V_14 . V_137 == V_142 )
F_216 ( V_8 -> V_35 ) ;
if ( V_95 && V_95 < 100 ) {
if ( V_95 < 10 ) {
F_16 ( L_162 ) ;
F_213 ( V_316 , V_293 , L_163 , 1 ) ;
goto V_153;
} else
F_32 ( L_164
L_165
L_166 ) ;
}
if ( F_193 ( V_8 , V_95 ) )
goto V_153;
if ( F_155 () )
goto V_153;
atexit ( F_140 ) ;
if ( ! V_298 )
signal ( V_324 , F_139 ) ;
signal ( V_213 , F_139 ) ;
signal ( V_325 , F_139 ) ;
signal ( V_326 , F_139 ) ;
V_101 = 0 ;
for ( V_317 = 0 ; V_298 || V_317 < V_134 ; V_317 ++ ) {
if ( V_134 != 1 && V_67 > 0 )
fprintf ( V_68 , L_167 ,
V_317 + 1 ) ;
V_101 = F_84 ( V_93 , V_94 ) ;
if ( V_298 && V_101 != - 1 ) {
F_36 ( NULL , V_93 , V_94 ) ;
F_2 () ;
}
}
if ( ! V_298 && V_101 != - 1 && ! V_95 )
F_36 ( NULL , V_93 , V_94 ) ;
if ( V_25 ) {
int V_91 = F_71 ( & V_26 . V_27 ) ;
int V_84 = F_217 ( ( void * ) & V_26 ,
F_14 ,
& V_26 . V_85 -> V_327 . V_328 ) ;
if ( V_84 ) {
F_32 ( L_168
L_169 ) ;
}
if ( ! V_95 ) {
if ( F_35 ( V_123 . V_221 , V_329 ) )
F_16 ( L_8 ) ;
}
if ( ! V_26 . V_27 . V_28 ) {
V_26 . V_85 -> V_45 . V_330 += V_26 . V_47 ;
F_73 ( V_26 . V_85 , V_8 , V_91 , true ) ;
}
F_205 ( V_26 . V_85 ) ;
}
F_159 () ;
F_218 ( V_8 ) ;
V_153:
if ( V_273 && V_276 )
F_177 ( V_275 , 0 ) ;
F_219 ( V_8 ) ;
return V_101 ;
}
