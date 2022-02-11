static bool F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 )
return true ;
}
return false ;
}
static const char * F_2 ( enum V_5 V_6 )
{
int V_7 , V_8 = F_3 ( V_9 ) ;
const char * V_10 = L_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( V_9 [ V_7 ] . V_6 == V_6 ) {
V_10 = V_9 [ V_7 ] . V_10 ;
break;
}
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 ,
bool V_15 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
int type = V_17 -> type ;
const char * V_18 ;
if ( V_17 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
if ( V_15 )
return 0 ;
V_18 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_19 &= ~ V_6 ;
V_18 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_18 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
return F_4 ( V_12 , V_13 , V_14 , V_6 ,
false ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_20 * V_21 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_15 ;
if ( F_10 ( & V_21 -> V_22 , V_23 ) )
return 0 ;
V_15 = F_10 ( & V_21 -> V_22 ,
V_24 ) ;
if ( F_11 ( V_25 ) &&
! F_12 ( V_21 , L_5 ) )
return - V_26 ;
if ( F_11 ( V_27 ) ) {
if ( F_8 ( V_12 , V_28 , L_6 ,
V_29 ) )
return - V_26 ;
}
if ( F_11 ( V_30 ) &&
F_4 ( V_12 , V_31 , L_7 ,
V_32 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_33 ) &&
F_8 ( V_12 , V_34 , L_8 ,
V_35 ) )
return - V_26 ;
if ( F_11 ( V_36 ) &&
F_8 ( V_12 , V_37 , L_9 ,
V_38 ) )
return - V_26 ;
if ( F_11 ( V_39 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_10
L_11
L_12 ) ;
return - V_26 ;
}
if ( F_11 ( V_40 ) && ! F_11 ( V_39 ) ) {
F_6 ( L_13
L_14 ) ;
return - V_26 ;
}
if ( F_11 ( V_41 ) && ! F_11 ( V_27 ) && ! F_11 ( V_30 ) ) {
F_6 ( L_15
L_11
L_16 ) ;
return - V_26 ;
}
if ( F_11 ( V_42 ) && ! F_11 ( V_27 ) ) {
F_6 ( L_17
L_18 ) ;
return - V_26 ;
}
if ( ( F_11 ( V_43 ) || F_11 ( V_44 ) ) &&
F_8 ( V_12 , V_45 , L_19 ,
V_46 | V_47 ) )
return - V_26 ;
if ( F_11 ( TIME ) &&
F_8 ( V_12 , V_48 , L_20 ,
V_49 ) )
return - V_26 ;
if ( F_11 ( V_50 ) &&
F_4 ( V_12 , V_51 , L_21 ,
V_52 , V_15 ) )
return - V_26 ;
if ( F_11 ( V_53 ) &&
F_8 ( V_12 , V_54 , L_22 ,
V_55 ) )
return - V_26 ;
if ( F_11 ( V_56 ) &&
F_8 ( V_12 , V_57 , L_23 ,
V_58 ) )
return - V_26 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
unsigned int type = V_17 -> type ;
V_3 [ type ] . V_59 = 0 ;
if ( F_11 ( V_27 ) )
V_3 [ type ] . V_59 |= V_60 ;
if ( F_11 ( V_39 ) )
V_3 [ type ] . V_59 |= V_61 ;
if ( F_11 ( V_41 ) )
V_3 [ type ] . V_59 |= V_62 ;
if ( F_11 ( V_40 ) )
V_3 [ type ] . V_59 |= V_63 ;
if ( F_11 ( V_42 ) )
V_3 [ type ] . V_59 |= V_64 ;
}
static int F_14 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_15 ( V_21 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_65 ) {
F_6 ( L_24
L_25 ,
F_16 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_19 &&
F_9 ( V_12 , V_21 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_13 ( & V_12 -> V_17 ) ;
}
if ( ! V_66 ) {
bool V_67 = false ;
F_17 (session->evlist, evsel) {
if ( V_12 -> V_17 . V_13 & V_68 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
V_69 . V_67 = false ;
}
if ( V_69 . V_67 &&
! V_3 [ V_70 ] . V_4 ) {
struct V_16 * V_17 ;
V_1 = V_70 ;
V_12 = F_15 ( V_21 , V_1 ) ;
if ( V_12 == NULL )
goto V_71;
V_17 = & V_12 -> V_17 ;
if ( V_17 -> V_13 & V_68 ) {
V_3 [ V_1 ] . V_19 |= V_29 ;
V_3 [ V_1 ] . V_19 |= V_72 ;
V_3 [ V_1 ] . V_19 |= V_73 ;
F_13 ( V_17 ) ;
}
}
V_71:
return 0 ;
}
static void F_18 ( struct V_74 * V_75 ,
struct V_16 * V_17 )
{
struct V_76 * V_77 = & V_75 -> V_78 ;
T_2 V_79 = V_17 -> V_80 ;
unsigned V_7 = 0 , V_81 ;
if ( ! V_77 )
return;
F_19 (r, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_1 V_82 = V_77 -> V_77 [ V_7 ++ ] ;
printf ( L_26 V_83 L_27 , F_20 ( V_81 ) , V_82 ) ;
}
}
static void F_21 ( struct V_74 * V_75 ,
struct V_84 * V_84 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
unsigned long V_85 ;
unsigned long V_86 ;
unsigned long long V_87 ;
if ( F_11 ( V_88 ) ) {
if ( V_89 )
printf ( L_28 , F_22 ( V_84 ) ) ;
else if ( F_11 ( V_27 ) && V_69 . V_67 )
printf ( L_29 , F_22 ( V_84 ) ) ;
else
printf ( L_30 , F_22 ( V_84 ) ) ;
}
if ( F_11 ( V_43 ) && F_11 ( V_44 ) )
printf ( L_31 , V_75 -> V_90 , V_75 -> V_91 ) ;
else if ( F_11 ( V_43 ) )
printf ( L_32 , V_75 -> V_90 ) ;
else if ( F_11 ( V_44 ) )
printf ( L_32 , V_75 -> V_91 ) ;
if ( F_11 ( V_50 ) ) {
if ( V_89 )
printf ( L_33 , V_75 -> V_92 ) ;
else
printf ( L_34 , V_75 -> V_92 ) ;
}
if ( F_11 ( TIME ) ) {
V_87 = V_75 -> time ;
V_85 = V_87 / V_93 ;
V_87 -= V_85 * V_93 ;
V_86 = V_87 / V_94 ;
if ( V_95 )
printf ( L_35 , V_85 , V_87 ) ;
else
printf ( L_36 , V_85 , V_86 ) ;
}
}
static inline char
F_23 ( struct V_96 * V_97 )
{
if ( ! ( V_97 -> V_98 . V_99 || V_97 -> V_98 . V_100 ) )
return '-' ;
return V_97 -> V_98 . V_100 ? 'P' : 'M' ;
}
static void F_24 ( struct V_74 * V_75 )
{
struct V_101 * V_97 = V_75 -> V_101 ;
T_1 V_7 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
printf ( L_37 V_83 L_38 V_83 L_39 ,
V_97 -> V_103 [ V_7 ] . V_104 ,
V_97 -> V_103 [ V_7 ] . V_105 ,
F_23 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_25 ( struct V_74 * V_75 ,
struct V_84 * V_84 )
{
struct V_101 * V_97 = V_75 -> V_101 ;
struct V_108 V_109 , V_110 ;
T_1 V_7 , V_104 , V_105 ;
if ( ! ( V_97 && V_97 -> V_102 ) )
return;
for ( V_7 = 0 ; V_7 < V_97 -> V_102 ; V_7 ++ ) {
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_104 = V_97 -> V_103 [ V_7 ] . V_104 ;
V_105 = V_97 -> V_103 [ V_7 ] . V_105 ;
F_26 ( V_84 , V_75 -> V_111 , V_112 , V_104 , & V_109 ) ;
if ( V_109 . V_113 )
V_109 . V_114 = F_27 ( V_109 . V_113 , V_109 . V_115 , NULL ) ;
F_26 ( V_84 , V_75 -> V_111 , V_112 , V_105 , & V_110 ) ;
if ( V_110 . V_113 )
V_110 . V_114 = F_27 ( V_110 . V_113 , V_110 . V_115 , NULL ) ;
F_28 ( V_109 . V_114 , & V_109 , stdout ) ;
putchar ( '/' ) ;
F_28 ( V_110 . V_114 , & V_110 , stdout ) ;
printf ( L_39 ,
F_23 ( V_97 -> V_103 + V_7 ) ,
V_97 -> V_103 [ V_7 ] . V_98 . V_106 ? 'X' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . abort ? 'A' : '-' ,
V_97 -> V_103 [ V_7 ] . V_98 . V_107 ) ;
}
}
static void F_29 ( struct V_74 * V_75 ,
struct V_84 * V_84 ,
struct V_16 * V_17 )
{
struct V_108 V_116 ;
printf ( L_40 V_83 , V_75 -> V_115 ) ;
if ( ! F_30 ( V_17 ) )
return;
F_31 ( V_84 , & V_116 , V_75 ) ;
if ( F_11 ( V_39 ) ) {
printf ( L_27 ) ;
if ( F_11 ( V_40 ) )
F_28 ( V_116 . V_114 , & V_116 , stdout ) ;
else
F_32 ( V_116 . V_114 , stdout ) ;
}
if ( F_11 ( V_41 ) ) {
printf ( L_41 ) ;
F_33 ( V_116 . V_113 , stdout ) ;
printf ( L_42 ) ;
}
}
static void F_34 ( struct V_74 * V_75 ,
struct V_11 * V_12 ,
struct V_84 * V_84 ,
struct V_108 * V_116 )
{
struct V_16 * V_17 = & V_12 -> V_17 ;
bool V_117 = false ;
if ( F_11 ( V_27 ) ) {
unsigned int V_118 = V_3 [ V_17 -> type ] . V_59 ;
struct V_119 * V_120 = NULL ;
if ( V_69 . V_67 && V_75 -> V_121 &&
F_35 ( V_116 -> V_84 , & V_119 , V_12 ,
V_75 , NULL , NULL , V_122 ) == 0 )
V_120 = & V_119 ;
if ( V_120 == NULL ) {
putchar ( ' ' ) ;
if ( V_118 & V_64 ) {
V_117 = true ;
V_118 &= ~ V_64 ;
}
} else
putchar ( '\n' ) ;
F_36 ( V_75 , V_116 , 0 , V_118 , V_120 , stdout ) ;
}
if ( F_11 ( V_30 ) ||
( ( V_12 -> V_17 . V_13 & V_31 ) &&
! V_3 [ V_17 -> type ] . V_4 ) ) {
printf ( L_43 ) ;
F_29 ( V_75 , V_84 , V_17 ) ;
}
if ( V_117 )
F_37 ( V_116 -> V_113 , V_116 -> V_115 , L_44 , stdout ) ;
printf ( L_45 ) ;
}
static void F_38 ( T_3 V_98 )
{
const char * V_123 = V_124 ;
const int V_125 = strlen ( V_124 ) ;
char V_10 [ 33 ] ;
int V_7 , V_126 = 0 ;
for ( V_7 = 0 ; V_7 < V_125 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_126 ++ ] = V_123 [ V_7 ] ;
}
for (; V_7 < 32 ; V_7 ++ , V_98 >>= 1 ) {
if ( V_98 & 1 )
V_10 [ V_126 ++ ] = '?' ;
}
V_10 [ V_126 ] = 0 ;
printf ( L_46 , V_10 ) ;
}
static void
F_39 ( enum V_127 V_128 ,
unsigned int V_82 ,
void * V_129 )
{
unsigned char V_130 = ( unsigned char ) V_82 ;
struct V_131 * V_131 = V_129 ;
switch ( V_128 ) {
case V_132 :
printf ( L_45 ) ;
break;
case V_133 :
printf ( L_47 , ! V_131 -> V_134 ? L_48 :
L_49 ) ;
break;
case V_135 :
printf ( L_50 , V_82 ) ;
break;
case V_136 :
printf ( L_51 , V_82 ) ;
break;
case V_137 :
printf ( L_52 ) ;
break;
case V_138 :
printf ( L_53 ) ;
break;
case V_139 :
if ( V_131 -> V_140 && V_130 )
V_131 -> V_141 = false ;
if ( ! isprint ( V_130 ) ) {
printf ( L_54 , '.' ) ;
if ( ! V_131 -> V_141 )
break;
if ( V_130 == '\0' )
V_131 -> V_140 = true ;
else
V_131 -> V_141 = false ;
} else {
printf ( L_54 , V_130 ) ;
}
break;
case V_142 :
printf ( L_27 ) ;
break;
case V_143 :
printf ( L_45 ) ;
V_131 -> V_134 ++ ;
break;
case V_144 :
default:
break;
}
}
static void F_40 ( struct V_74 * V_75 )
{
unsigned int V_145 = V_75 -> V_146 ;
struct V_131 V_131 = { 0 , false , true } ;
F_41 ( V_75 -> V_147 , V_145 , 8 ,
F_39 , & V_131 ) ;
if ( V_131 . V_141 && V_131 . V_140 )
printf ( L_55 , L_56 ,
( char * ) ( V_75 -> V_147 ) ) ;
}
static int F_42 ( struct V_148 * V_149 )
{
struct V_11 * V_12 ;
int V_150 = 0 ;
F_17 (evlist, evsel) {
int V_151 = strlen ( F_5 ( V_12 ) ) ;
V_150 = F_43 ( V_151 , V_150 ) ;
}
return V_150 ;
}
static T_4 F_44 ( T_1 V_152 )
{
struct V_153 V_154 = { . V_152 . V_82 = V_152 } ;
char V_155 [ 100 ] ;
char V_71 [ 100 ] ;
static int V_156 ;
int V_151 ;
F_45 ( V_155 , 100 , & V_154 ) ;
V_151 = F_46 ( V_71 , 100 , L_40 V_83 L_57 , V_152 , V_155 ) ;
if ( V_156 < V_151 )
V_156 = V_151 ;
return printf ( L_58 , V_156 , V_71 ) ;
}
static void F_47 ( struct V_157 * V_158 ,
struct V_74 * V_75 , struct V_11 * V_12 ,
struct V_108 * V_116 )
{
struct V_84 * V_84 = V_116 -> V_84 ;
struct V_16 * V_17 = & V_12 -> V_17 ;
if ( V_3 [ V_17 -> type ] . V_19 == 0 )
return;
F_21 ( V_75 , V_84 , V_12 ) ;
if ( F_11 ( V_53 ) )
printf ( L_59 V_159 L_27 , V_75 -> V_160 ) ;
if ( F_11 ( V_161 ) ) {
const char * V_18 = F_5 ( V_12 ) ;
if ( ! V_158 -> V_162 )
V_158 -> V_162 = F_42 ( V_158 -> V_21 -> V_149 ) ;
printf ( L_60 , V_158 -> V_162 ,
V_18 ? V_18 : L_61 ) ;
}
if ( V_163 )
F_38 ( V_75 -> V_98 ) ;
if ( F_48 ( V_17 ) ) {
F_34 ( V_75 , V_12 , V_84 , V_116 ) ;
return;
}
if ( F_11 ( V_25 ) )
F_49 ( V_12 -> V_164 , V_75 -> V_92 ,
V_75 -> V_147 , V_75 -> V_146 ) ;
if ( F_11 ( V_30 ) )
F_29 ( V_75 , V_84 , V_17 ) ;
if ( F_11 ( V_33 ) )
F_44 ( V_75 -> V_152 ) ;
if ( F_11 ( V_36 ) )
printf ( L_40 V_159 , V_75 -> V_165 ) ;
if ( F_11 ( V_27 ) ) {
struct V_119 * V_120 = NULL ;
if ( V_69 . V_67 && V_75 -> V_121 &&
F_35 ( V_116 -> V_84 , & V_119 , V_12 ,
V_75 , NULL , NULL , V_122 ) == 0 )
V_120 = & V_119 ;
putchar ( V_120 ? '\n' : ' ' ) ;
F_36 ( V_75 , V_116 , 0 , V_3 [ V_17 -> type ] . V_59 , V_120 , stdout ) ;
}
if ( F_11 ( V_56 ) )
F_18 ( V_75 , V_17 ) ;
if ( F_11 ( V_166 ) )
F_24 ( V_75 ) ;
else if ( F_11 ( V_167 ) )
F_25 ( V_75 , V_84 ) ;
if ( F_50 ( V_12 ) && F_11 ( V_168 ) )
F_40 ( V_75 ) ;
printf ( L_45 ) ;
}
static void F_51 ( struct V_11 * V_169 , T_1 V_170 )
{
int V_171 = F_52 ( V_169 -> V_172 ) ;
int V_173 = F_53 ( V_169 ) ;
int V_92 , V_84 ;
static int V_174 ;
if ( V_169 -> V_175 )
V_171 = 1 ;
if ( ! V_174 ) {
printf ( L_62 ,
L_21 , L_63 , L_64 , L_65 , L_66 , L_20 , L_67 ) ;
V_174 = 1 ;
}
for ( V_84 = 0 ; V_84 < V_171 ; V_84 ++ ) {
for ( V_92 = 0 ; V_92 < V_173 ; V_92 ++ ) {
struct V_176 * V_177 ;
V_177 = F_54 ( V_169 -> V_177 , V_92 , V_84 ) ;
printf ( L_68 V_159 L_69 V_159 L_69 V_159 L_69 V_159 L_70 ,
V_169 -> V_178 -> V_113 [ V_92 ] ,
F_55 ( V_169 -> V_172 , V_84 ) ,
V_177 -> V_82 ,
V_177 -> V_179 ,
V_177 -> V_180 ,
V_170 ,
F_5 ( V_169 ) ) ;
}
}
}
static void F_56 ( struct V_11 * V_169 , T_1 V_170 )
{
if ( V_181 && V_181 -> F_56 )
V_181 -> F_56 ( & V_182 , V_169 , V_170 ) ;
else
F_51 ( V_169 , V_170 ) ;
}
static void F_57 ( T_1 V_170 )
{
if ( V_181 && V_181 -> F_57 )
V_181 -> F_57 ( V_170 ) ;
}
static void F_58 ( void )
{
F_59 () ;
F_60 () ;
}
static int F_61 ( void )
{
return V_181 ? V_181 -> V_183 () : 0 ;
}
static int F_62 ( void )
{
F_7 ( L_71 ) ;
return V_181 ? V_181 -> V_184 () : 0 ;
}
static int F_63 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_11 * V_12 ,
struct V_189 * V_189 )
{
struct V_157 * V_190 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_108 V_116 ;
if ( V_191 ) {
if ( V_75 -> time < V_192 ) {
F_6 ( L_72 V_159
L_73 V_159 L_45 , V_192 ,
V_75 -> time ) ;
V_193 ++ ;
}
V_192 = V_75 -> time ;
return 0 ;
}
if ( F_65 ( V_189 , & V_116 , V_75 ) < 0 ) {
F_6 ( L_74 ,
V_188 -> V_22 . type ) ;
return - 1 ;
}
if ( V_116 . V_194 )
goto V_195;
if ( V_196 && ! F_66 ( V_75 -> V_92 , V_197 ) )
goto V_195;
if ( V_181 )
V_181 -> F_47 ( V_188 , V_75 , V_12 , & V_116 ) ;
else
F_47 ( V_190 , V_75 , V_12 , & V_116 ) ;
V_195:
F_67 ( & V_116 ) ;
return 0 ;
}
static int F_68 ( struct V_185 * V_186 , union V_187 * V_188 ,
struct V_148 * * V_198 )
{
struct V_157 * V_190 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_148 * V_149 ;
struct V_11 * V_12 , * V_126 ;
int V_199 ;
V_199 = F_69 ( V_186 , V_188 , V_198 ) ;
if ( V_199 )
return V_199 ;
V_149 = * V_198 ;
V_12 = F_70 ( * V_198 ) ;
if ( V_12 -> V_17 . type >= V_2 )
return 0 ;
F_17 (evlist, pos) {
if ( V_126 -> V_17 . type == V_12 -> V_17 . type && V_126 != V_12 )
return 0 ;
}
F_13 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_17 . V_13 )
V_199 = F_9 ( V_12 , V_190 -> V_21 ) ;
return V_199 ;
}
static int F_71 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
int V_201 = - 1 ;
V_84 = F_73 ( V_189 , V_188 -> V_202 . V_90 , V_188 -> V_202 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_75 ) ;
return - 1 ;
}
if ( F_74 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
goto V_71;
if ( ! V_12 -> V_17 . V_203 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_188 -> V_202 . V_91 ;
V_75 -> V_90 = V_188 -> V_202 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
V_201 = 0 ;
V_71:
F_76 ( V_84 ) ;
return V_201 ;
}
static int F_77 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
if ( F_78 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
return - 1 ;
V_84 = F_73 ( V_189 , V_188 -> V_204 . V_90 , V_188 -> V_204 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_76 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_203 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = V_188 -> V_204 . time ;
V_75 -> V_91 = V_188 -> V_204 . V_91 ;
V_75 -> V_90 = V_188 -> V_204 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
F_76 ( V_84 ) ;
return 0 ;
}
static int F_79 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
int V_199 = 0 ;
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
V_84 = F_73 ( V_189 , V_188 -> V_204 . V_90 , V_188 -> V_204 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_77 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_203 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_188 -> V_204 . V_91 ;
V_75 -> V_90 = V_188 -> V_204 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
if ( F_80 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
V_199 = - 1 ;
F_76 ( V_84 ) ;
return V_199 ;
}
static int F_81 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
if ( F_82 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
return - 1 ;
V_84 = F_73 ( V_189 , V_188 -> V_205 . V_90 , V_188 -> V_205 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_78 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_203 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_188 -> V_205 . V_91 ;
V_75 -> V_90 = V_188 -> V_205 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
F_76 ( V_84 ) ;
return 0 ;
}
static int F_83 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
if ( F_84 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
return - 1 ;
V_84 = F_73 ( V_189 , V_188 -> V_206 . V_90 , V_188 -> V_206 . V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_79 ) ;
return - 1 ;
}
if ( ! V_12 -> V_17 . V_203 ) {
V_75 -> V_92 = 0 ;
V_75 -> time = 0 ;
V_75 -> V_91 = V_188 -> V_206 . V_91 ;
V_75 -> V_90 = V_188 -> V_206 . V_90 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
F_76 ( V_84 ) ;
return 0 ;
}
static int F_85 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_74 * V_75 ,
struct V_189 * V_189 )
{
struct V_84 * V_84 ;
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
struct V_20 * V_21 = V_158 -> V_21 ;
struct V_11 * V_12 = F_72 ( V_21 -> V_149 , V_75 -> V_200 ) ;
if ( F_86 ( V_186 , V_188 , V_75 , V_189 ) < 0 )
return - 1 ;
V_84 = F_73 ( V_189 , V_75 -> V_90 ,
V_75 -> V_91 ) ;
if ( V_84 == NULL ) {
F_7 ( L_80 ) ;
return - 1 ;
}
F_21 ( V_75 , V_84 , V_12 ) ;
F_75 ( V_188 , stdout ) ;
F_76 ( V_84 ) ;
return 0 ;
}
static void F_87 ( int T_5 V_207 )
{
V_208 = 1 ;
}
static int F_88 ( struct V_157 * V_158 )
{
int V_201 ;
signal ( V_209 , F_87 ) ;
if ( V_158 -> V_210 ) {
V_158 -> V_186 . V_202 = F_71 ;
V_158 -> V_186 . V_204 = F_77 ;
V_158 -> V_186 . exit = F_79 ;
}
if ( V_158 -> V_211 ) {
V_158 -> V_186 . V_205 = F_81 ;
V_158 -> V_186 . V_206 = F_83 ;
}
if ( V_158 -> V_212 )
V_158 -> V_186 . V_213 = F_85 ;
V_201 = F_89 ( V_158 -> V_21 ) ;
if ( V_191 )
F_6 ( L_81 V_159 L_45 , V_193 ) ;
return V_201 ;
}
static struct V_214 * F_90 ( const char * V_215 ,
struct V_181 * V_216 )
{
struct V_214 * V_217 = malloc ( sizeof( * V_217 ) + strlen ( V_215 ) + 1 ) ;
if ( V_217 != NULL ) {
strcpy ( V_217 -> V_215 , V_215 ) ;
V_217 -> V_216 = V_216 ;
}
return V_217 ;
}
static void F_91 ( struct V_214 * V_217 )
{
F_92 ( & V_217 -> V_218 , & V_219 ) ;
}
static struct V_214 * F_93 ( const char * V_215 )
{
struct V_214 * V_217 ;
F_94 (s, &script_specs, node)
if ( strcasecmp ( V_217 -> V_215 , V_215 ) == 0 )
return V_217 ;
return NULL ;
}
int F_95 ( const char * V_215 , struct V_181 * V_216 )
{
struct V_214 * V_217 ;
V_217 = F_93 ( V_215 ) ;
if ( V_217 )
return - 1 ;
V_217 = F_90 ( V_215 , V_216 ) ;
if ( ! V_217 )
return - 1 ;
else
F_91 ( V_217 ) ;
return 0 ;
}
static struct V_181 * F_96 ( const char * V_215 )
{
struct V_214 * V_217 = F_93 ( V_215 ) ;
if ( ! V_217 )
return NULL ;
return V_217 -> V_216 ;
}
static void F_97 ( void )
{
struct V_214 * V_217 ;
fprintf ( V_220 , L_45 ) ;
fprintf ( V_220 , L_82
L_83 ) ;
F_94 (s, &script_specs, node)
fprintf ( V_220 , L_84 , V_217 -> V_215 , V_217 -> V_216 -> V_221 ) ;
fprintf ( V_220 , L_45 ) ;
}
static int F_98 ( const struct V_222 * T_6 V_207 ,
const char * V_10 , int T_7 V_207 )
{
char V_215 [ V_223 ] ;
const char * V_158 , * V_224 ;
int V_151 ;
if ( strcmp ( V_10 , L_85 ) == 0 ) {
F_97 () ;
exit ( 0 ) ;
}
V_158 = strchr ( V_10 , ':' ) ;
if ( V_158 ) {
V_151 = V_158 - V_10 ;
if ( V_151 >= V_223 ) {
fprintf ( V_220 , L_86 ) ;
return - 1 ;
}
strncpy ( V_215 , V_10 , V_151 ) ;
V_215 [ V_151 ] = '\0' ;
V_181 = F_96 ( V_215 ) ;
if ( ! V_181 ) {
fprintf ( V_220 , L_86 ) ;
return - 1 ;
}
V_158 ++ ;
} else {
V_158 = V_10 ;
V_224 = strrchr ( V_158 , '.' ) ;
if ( ! V_224 ) {
fprintf ( V_220 , L_87 ) ;
return - 1 ;
}
V_181 = F_96 ( ++ V_224 ) ;
if ( ! V_181 ) {
fprintf ( V_220 , L_87 ) ;
return - 1 ;
}
}
V_225 = F_99 ( V_158 ) ;
return 0 ;
}
static int F_100 ( const struct V_222 * T_6 V_207 ,
const char * V_226 , int T_7 V_207 )
{
char * V_227 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_228 = 0 ;
char * V_10 = F_99 ( V_226 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_229 ;
V_227 = strchr ( V_10 , ':' ) ;
if ( V_227 ) {
* V_227 = '\0' ;
V_227 ++ ;
if ( ! strcmp ( V_10 , L_88 ) )
type = V_230 ;
else if ( ! strcmp ( V_10 , L_89 ) )
type = V_231 ;
else if ( ! strcmp ( V_10 , L_90 ) )
type = V_70 ;
else if ( ! strcmp ( V_10 , L_91 ) )
type = V_232 ;
else if ( ! strcmp ( V_10 , L_92 ) )
type = V_233 ;
else {
fprintf ( V_220 , L_93 ) ;
V_228 = - V_26 ;
goto V_71;
}
if ( V_3 [ type ] . V_4 )
F_101 ( L_94 ,
F_16 ( type ) ) ;
V_3 [ type ] . V_19 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_65 = false ;
} else {
V_227 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_220 ,
L_95 ) ;
V_228 = - V_26 ;
goto V_71;
}
if ( F_1 () )
F_101 ( L_96 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_19 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_65 = true ;
}
}
for ( V_227 = strtok ( V_227 , L_97 ) ; V_227 ; V_227 = strtok ( NULL , L_97 ) ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_227 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 && strcmp ( V_227 , L_98 ) == 0 ) {
V_163 = true ;
continue;
}
if ( V_7 == V_8 ) {
fprintf ( V_220 , L_99 ) ;
V_228 = - V_26 ;
goto V_71;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_234 & V_9 [ V_7 ] . V_6 ) {
F_101 ( L_100 ,
V_9 [ V_7 ] . V_10 , F_16 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_234 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_220 , L_101 ,
V_9 [ V_7 ] . V_10 , F_16 ( type ) ) ;
V_228 = - V_26 ;
goto V_71;
}
V_3 [ type ] . V_19 |= V_9 [ V_7 ] . V_6 ;
}
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_19 == 0 ) {
F_7 ( L_102
L_103 , F_16 ( type ) ) ;
}
}
V_71:
free ( V_10 ) ;
return V_228 ;
}
static int F_102 ( const char * V_235 , const struct V_236 * V_237 )
{
char V_238 [ V_223 ] ;
struct V_239 V_240 ;
sprintf ( V_238 , L_104 , V_235 , V_237 -> V_241 ) ;
if ( V_239 ( V_238 , & V_240 ) )
return 0 ;
return F_103 ( V_240 . V_242 ) ;
}
static struct V_243 * F_104 ( const char * V_221 )
{
struct V_243 * V_217 = F_105 ( sizeof( * V_217 ) ) ;
if ( V_217 != NULL && V_221 )
V_217 -> V_221 = F_99 ( V_221 ) ;
return V_217 ;
}
static void F_106 ( struct V_243 * V_217 )
{
F_107 ( & V_217 -> V_221 ) ;
F_107 ( & V_217 -> V_244 ) ;
F_107 ( & V_217 -> args ) ;
free ( V_217 ) ;
}
static void F_108 ( struct V_243 * V_217 )
{
F_92 ( & V_217 -> V_218 , & V_245 ) ;
}
static struct V_243 * F_109 ( const char * V_221 )
{
struct V_243 * V_217 ;
F_94 (s, &script_descs, node)
if ( strcasecmp ( V_217 -> V_221 , V_221 ) == 0 )
return V_217 ;
return NULL ;
}
static struct V_243 * F_110 ( const char * V_221 )
{
struct V_243 * V_217 = F_109 ( V_221 ) ;
if ( V_217 )
return V_217 ;
V_217 = F_104 ( V_221 ) ;
if ( ! V_217 )
goto V_246;
F_108 ( V_217 ) ;
return V_217 ;
V_246:
F_106 ( V_217 ) ;
return NULL ;
}
static const char * F_111 ( const char * V_10 , const char * V_247 )
{
T_4 V_248 = strlen ( V_247 ) ;
const char * V_249 = V_10 ;
if ( strlen ( V_10 ) > V_248 ) {
V_249 = V_10 + strlen ( V_10 ) - V_248 ;
if ( ! strncmp ( V_249 , V_247 , V_248 ) )
return V_249 ;
}
return NULL ;
}
static int F_112 ( struct V_243 * V_250 , const char * V_251 )
{
char line [ V_252 ] , * V_249 ;
T_8 * V_253 ;
V_253 = fopen ( V_251 , L_105 ) ;
if ( ! V_253 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_253 ) ) {
V_249 = F_113 ( line ) ;
if ( strlen ( V_249 ) == 0 )
continue;
if ( * V_249 != '#' )
continue;
V_249 ++ ;
if ( strlen ( V_249 ) && * V_249 == '!' )
continue;
V_249 = F_113 ( V_249 ) ;
if ( strlen ( V_249 ) && V_249 [ strlen ( V_249 ) - 1 ] == '\n' )
V_249 [ strlen ( V_249 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_249 , L_106 , strlen ( L_106 ) ) ) {
V_249 += strlen ( L_106 ) ;
V_250 -> V_244 = F_99 ( F_113 ( V_249 ) ) ;
continue;
}
if ( ! strncmp ( V_249 , L_107 , strlen ( L_107 ) ) ) {
V_249 += strlen ( L_107 ) ;
V_250 -> args = F_99 ( F_113 ( V_249 ) ) ;
continue;
}
}
fclose ( V_253 ) ;
return 0 ;
}
static char * F_114 ( struct V_236 * V_254 , const char * V_247 )
{
char * V_255 , * V_10 ;
V_255 = F_99 ( V_254 -> V_241 ) ;
if ( ! V_255 )
return NULL ;
V_10 = ( char * ) F_111 ( V_255 , V_247 ) ;
if ( ! V_10 ) {
free ( V_255 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_255 ;
}
static int F_115 ( const struct V_222 * T_6 V_207 ,
const char * V_217 V_207 ,
int T_7 V_207 )
{
struct V_236 * V_254 , * V_256 ;
char V_257 [ V_258 ] ;
T_9 * V_259 , * V_260 ;
char V_261 [ V_258 ] ;
char V_262 [ V_258 ] ;
struct V_243 * V_250 ;
char V_263 [ V_252 ] ;
char * V_255 ;
snprintf ( V_257 , V_258 , L_108 , F_116 () ) ;
V_259 = F_117 ( V_257 ) ;
if ( ! V_259 )
return - 1 ;
F_118 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_262 , V_258 , L_109 , V_257 ,
V_256 -> V_241 ) ;
V_260 = F_117 ( V_262 ) ;
if ( ! V_260 )
continue;
F_119 (lang_path, lang_dir, script_dirent) {
V_255 = F_114 ( V_254 , V_264 ) ;
if ( V_255 ) {
V_250 = F_110 ( V_255 ) ;
snprintf ( V_261 , V_258 , L_104 ,
V_262 , V_254 -> V_241 ) ;
F_112 ( V_250 , V_261 ) ;
free ( V_255 ) ;
}
}
}
fprintf ( stdout , L_110 ) ;
F_94 (desc, &script_descs, node) {
sprintf ( V_263 , L_111 , V_250 -> V_221 ,
V_250 -> args ? V_250 -> args : L_1 ) ;
fprintf ( stdout , L_112 , V_263 ,
V_250 -> V_244 ? V_250 -> V_244 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_120 ( char * V_265 , char * V_266 ,
struct V_20 * V_21 )
{
char V_251 [ V_258 ] , V_18 [ 128 ] ;
char line [ V_252 ] , * V_249 ;
struct V_11 * V_126 ;
int V_267 , V_151 ;
T_8 * V_253 ;
sprintf ( V_251 , L_113 , V_265 , V_266 ) ;
V_253 = fopen ( V_251 , L_105 ) ;
if ( ! V_253 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_253 ) ) {
V_249 = F_113 ( line ) ;
if ( * V_249 == '#' )
continue;
while ( strlen ( V_249 ) ) {
V_249 = strstr ( V_249 , L_114 ) ;
if ( ! V_249 )
break;
V_249 += 2 ;
V_249 = F_113 ( V_249 ) ;
V_151 = strcspn ( V_249 , L_115 ) ;
if ( ! V_151 )
break;
snprintf ( V_18 , V_151 + 1 , L_116 , V_249 ) ;
V_267 = 0 ;
F_17 (session->evlist, pos) {
if ( ! strcmp ( F_5 ( V_126 ) , V_18 ) ) {
V_267 = 1 ;
break;
}
}
if ( ! V_267 ) {
fclose ( V_253 ) ;
return - 1 ;
}
}
}
fclose ( V_253 ) ;
return 0 ;
}
int F_121 ( char * * V_268 , char * * V_269 )
{
struct V_236 * V_254 , * V_256 ;
char V_257 [ V_258 ] , V_262 [ V_258 ] ;
T_9 * V_259 , * V_260 ;
struct V_20 * V_21 ;
struct V_270 V_271 = {
. V_238 = V_272 ,
. V_273 = V_274 ,
} ;
char * V_275 ;
int V_7 = 0 ;
V_21 = F_122 ( & V_271 , false , NULL ) ;
if ( ! V_21 )
return - 1 ;
snprintf ( V_257 , V_258 , L_108 , F_116 () ) ;
V_259 = F_117 ( V_257 ) ;
if ( ! V_259 ) {
F_123 ( V_21 ) ;
return - 1 ;
}
F_118 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_262 , V_258 , L_104 , V_257 ,
V_256 -> V_241 ) ;
#ifdef F_124
if ( strstr ( V_262 , L_117 ) )
continue;
#endif
#ifdef F_125
if ( strstr ( V_262 , L_118 ) )
continue;
#endif
V_260 = F_117 ( V_262 ) ;
if ( ! V_260 )
continue;
F_119 (lang_path, lang_dir, script_dirent) {
if ( strstr ( V_254 -> V_241 , L_119 ) )
continue;
sprintf ( V_269 [ V_7 ] , L_104 , V_262 ,
V_254 -> V_241 ) ;
V_275 = strchr ( V_254 -> V_241 , '.' ) ;
snprintf ( V_268 [ V_7 ] ,
( V_275 - V_254 -> V_241 ) + 1 ,
L_116 , V_254 -> V_241 ) ;
if ( F_120 ( V_262 ,
V_268 [ V_7 ] , V_21 ) )
continue;
V_7 ++ ;
}
F_126 ( V_260 ) ;
}
F_126 ( V_259 ) ;
F_123 ( V_21 ) ;
return V_7 ;
}
static char * F_127 ( const char * V_255 , const char * V_247 )
{
struct V_236 * V_254 , * V_256 ;
char V_257 [ V_258 ] ;
char V_261 [ V_258 ] ;
T_9 * V_259 , * V_260 ;
char V_262 [ V_258 ] ;
char * V_276 ;
snprintf ( V_257 , V_258 , L_108 , F_116 () ) ;
V_259 = F_117 ( V_257 ) ;
if ( ! V_259 )
return NULL ;
F_118 (scripts_path, scripts_dir, lang_dirent) {
snprintf ( V_262 , V_258 , L_109 , V_257 ,
V_256 -> V_241 ) ;
V_260 = F_117 ( V_262 ) ;
if ( ! V_260 )
continue;
F_119 (lang_path, lang_dir, script_dirent) {
V_276 = F_114 ( V_254 , V_247 ) ;
if ( V_276 && ! strcmp ( V_255 , V_276 ) ) {
free ( V_276 ) ;
F_126 ( V_260 ) ;
F_126 ( V_259 ) ;
snprintf ( V_261 , V_258 , L_104 ,
V_262 , V_254 -> V_241 ) ;
return F_99 ( V_261 ) ;
}
free ( V_276 ) ;
}
F_126 ( V_260 ) ;
}
F_126 ( V_259 ) ;
return NULL ;
}
static bool F_128 ( const char * V_261 )
{
return F_111 ( V_261 , L_120 ) == NULL ? false : true ;
}
static int F_129 ( char * V_261 )
{
struct V_243 * V_250 ;
int V_277 = 0 ;
char * V_249 ;
V_250 = F_104 ( NULL ) ;
if ( F_112 ( V_250 , V_261 ) )
goto V_71;
if ( ! V_250 -> args )
goto V_71;
for ( V_249 = V_250 -> args ; * V_249 ; V_249 ++ )
if ( * V_249 == '<' )
V_277 ++ ;
V_71:
F_106 ( V_250 ) ;
return V_277 ;
}
static int F_130 ( int V_278 , const char * * V_279 )
{
char * * V_280 = malloc ( sizeof( const char * ) * V_278 ) ;
if ( ! V_280 ) {
F_6 ( L_121 ) ;
return - 1 ;
}
memcpy ( V_280 , V_279 , sizeof( const char * ) * V_278 ) ;
V_278 = F_131 ( V_278 , ( const char * * ) V_280 , V_281 ,
NULL , V_282 ) ;
free ( V_280 ) ;
V_175 = ( V_278 == 0 ) ;
return 0 ;
}
static void F_132 ( struct V_157 * V_158 )
{
struct V_20 * V_21 = V_158 -> V_21 ;
T_1 V_13 = F_133 ( V_21 -> V_149 ) ;
if ( V_69 . V_67 || V_69 . V_283 ) {
if ( ( V_13 & V_284 ) &&
( V_13 & V_285 ) )
V_286 . V_287 = V_288 ;
else if ( V_13 & V_289 )
V_286 . V_287 = V_290 ;
else
V_286 . V_287 = V_291 ;
}
}
static int F_134 ( struct V_185 * V_186 V_207 ,
union V_187 * V_188 ,
struct V_20 * V_21 )
{
struct V_292 * V_293 = & V_188 -> V_294 ;
struct V_11 * V_169 ;
F_17 (session->evlist, counter) {
F_135 ( & V_182 , V_169 ) ;
F_56 ( V_169 , V_293 -> time ) ;
}
F_57 ( V_293 -> time ) ;
return 0 ;
}
static int F_136 ( struct V_185 * V_186 V_207 ,
union V_187 * V_188 ,
struct V_20 * V_21 V_207 )
{
F_137 ( & V_182 , & V_188 -> V_182 ) ;
return 0 ;
}
static int F_138 ( struct V_157 * V_158 )
{
struct V_148 * V_149 = V_158 -> V_21 -> V_149 ;
if ( ! V_158 -> V_178 || ! V_158 -> V_172 )
return 0 ;
if ( F_139 ( V_158 -> V_295 , L_122 ) )
return - V_26 ;
F_140 ( V_149 , V_158 -> V_178 , V_158 -> V_172 ) ;
if ( F_141 ( V_149 , true ) )
return - V_229 ;
V_158 -> V_295 = true ;
return 0 ;
}
static
int F_142 ( struct V_185 * V_186 ,
union V_187 * V_188 ,
struct V_20 * V_21 V_207 )
{
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
if ( V_158 -> V_172 ) {
F_101 ( L_123 ) ;
return 0 ;
}
V_158 -> V_172 = F_143 ( & V_188 -> V_296 ) ;
if ( ! V_158 -> V_172 )
return - V_229 ;
return F_138 ( V_158 ) ;
}
static
int F_144 ( struct V_185 * V_186 V_207 ,
union V_187 * V_188 ,
struct V_20 * V_21 V_207 )
{
struct V_157 * V_158 = F_64 ( V_186 , struct V_157 , V_186 ) ;
if ( V_158 -> V_178 ) {
F_101 ( L_124 ) ;
return 0 ;
}
V_158 -> V_178 = F_145 ( & V_188 -> V_297 . V_298 ) ;
if ( ! V_158 -> V_178 )
return - V_229 ;
return F_138 ( V_158 ) ;
}
int F_146 ( int V_278 , const char * * V_279 , const char * T_10 V_207 )
{
bool V_299 = false ;
bool V_22 = false ;
bool V_300 = false ;
bool V_301 = false ;
char * V_302 = NULL ;
char * V_303 = NULL ;
struct V_20 * V_21 ;
struct V_304 V_304 = { . V_305 = false , } ;
char * V_261 = NULL ;
const char * * V_280 ;
int V_7 , V_1 , V_199 = 0 ;
struct V_157 V_158 = {
. V_186 = {
. V_75 = F_63 ,
. V_205 = F_82 ,
. V_206 = F_84 ,
. V_202 = F_74 ,
. exit = F_80 ,
. V_204 = F_78 ,
. V_17 = F_68 ,
. V_306 = V_307 ,
. V_308 = V_309 ,
. V_310 = V_311 ,
. V_312 = V_313 ,
. V_314 = V_315 ,
. V_316 = V_317 ,
. V_318 = V_319 ,
. V_239 = V_320 ,
. V_294 = F_134 ,
. V_182 = F_136 ,
. V_296 = F_142 ,
. V_297 = F_144 ,
. V_321 = true ,
. V_322 = true ,
} ,
} ;
struct V_270 V_271 = {
. V_273 = V_274 ,
} ;
const struct V_222 V_323 [] = {
F_147 ( 'D' , L_125 , & V_324 ,
L_126 ) ,
F_148 ( 'v' , L_127 , & V_325 ,
L_128 ) ,
F_147 ( 'L' , L_129 , & V_89 ,
L_130 ) ,
F_149 ( 'l' , L_131 , NULL , NULL , L_132 ,
F_115 ) ,
F_150 ( 's' , L_133 , NULL , L_134 ,
L_135 ,
F_98 ) ,
F_151 ( 'g' , L_136 , & V_326 , L_85 ,
L_137 ) ,
F_151 ( 'i' , L_138 , & V_272 , L_139 , L_140 ) ,
F_147 ( 'd' , L_141 , & V_191 ,
L_142 ) ,
F_147 ( 0 , L_143 , & V_22 , L_144 ) ,
F_147 ( 0 , L_145 , & V_300 , L_146 ) ,
F_151 ( 'k' , L_147 , & V_69 . V_327 ,
L_139 , L_148 ) ,
F_151 ( 0 , L_149 , & V_69 . V_328 ,
L_139 , L_150 ) ,
F_147 ( 'G' , L_151 , & V_66 ,
L_152 ) ,
F_150 ( 0 , L_153 , NULL , L_154 ,
L_155 ,
V_329 ) ,
F_150 ( 'F' , L_156 , NULL , L_157 ,
L_158
L_159
L_160
L_161 , F_100 ) ,
F_147 ( 'a' , L_162 , & V_175 ,
L_163 ) ,
F_151 ( 'S' , L_164 , & V_69 . V_330 , L_165 ,
L_166 ) ,
F_151 ( 'C' , L_167 , & V_196 , L_167 , L_168 ) ,
F_151 ( 'c' , L_169 , & V_69 . V_331 , L_170 ,
L_171 ) ,
F_151 ( 0 , L_172 , & V_69 . V_332 , L_173 ,
L_174 ) ,
F_151 ( 0 , L_175 , & V_69 . V_333 , L_176 ,
L_177 ) ,
F_152 ( 0 , L_178 , & V_122 ,
L_179
L_180
L_181 F_153 ( V_334 ) ) ,
F_147 ( 'I' , L_182 , & V_299 ,
L_183 ) ,
F_147 ( '\0' , L_184 , & V_69 . V_335 ,
L_185 ) ,
F_147 ( '\0' , L_186 , & V_158 . V_210 ,
L_187 ) ,
F_147 ( '\0' , L_188 , & V_158 . V_211 ,
L_189 ) ,
F_147 ( '\0' , L_190 , & V_158 . V_212 ,
L_191 ) ,
F_147 ( 'f' , L_192 , & V_271 . V_336 , L_193 ) ,
F_147 ( 0 , L_194 , & V_95 ,
L_195 ) ,
F_154 ( 0 , L_196 , & V_304 , NULL , L_197 ,
L_198 ,
V_337 ) ,
F_147 ( 0 , L_199 , & V_338 ,
L_200 ) ,
F_147 ( 0 , L_201 , & V_69 . V_339 ,
L_202 ) ,
F_147 ( 0 , L_203 , & V_69 . V_340 ,
L_204 ) ,
F_155 ()
} ;
const char * const V_341 [] = { L_205 , L_206 , NULL } ;
const char * V_342 [] = {
L_207 ,
L_208 ,
L_209 ,
L_210 ,
L_211 ,
NULL
} ;
F_58 () ;
V_278 = F_156 ( V_278 , V_279 , V_323 , V_341 , V_342 ,
V_282 ) ;
V_271 . V_238 = V_272 ;
if ( V_278 > 1 && ! strncmp ( V_279 [ 0 ] , L_212 , strlen ( L_212 ) ) ) {
V_302 = F_127 ( V_279 [ 1 ] , V_343 ) ;
if ( ! V_302 )
return F_157 ( V_278 , V_279 , NULL ) ;
}
if ( V_278 > 1 && ! strncmp ( V_279 [ 0 ] , L_213 , strlen ( L_213 ) ) ) {
V_303 = F_127 ( V_279 [ 1 ] , V_264 ) ;
if ( ! V_303 ) {
fprintf ( V_220 ,
L_214
L_215 ) ;
return - 1 ;
}
}
if ( V_304 . V_121 &&
V_304 . V_344 > V_122 )
V_122 = V_304 . V_344 ;
F_158 ( F_116 () ) ;
if ( V_278 && ! V_225 && ! V_302 && ! V_303 ) {
int V_345 [ 2 ] ;
int V_346 ;
T_11 V_90 ;
V_302 = F_127 ( V_279 [ 0 ] , V_343 ) ;
V_303 = F_127 ( V_279 [ 0 ] , V_264 ) ;
if ( ! V_302 && ! V_303 ) {
F_159 ( V_342 , V_323 ,
L_216
L_217 , V_279 [ 0 ] ) ;
}
if ( F_128 ( V_279 [ 0 ] ) ) {
V_346 = V_278 - 1 ;
} else {
int V_347 ;
V_346 = F_129 ( V_303 ) ;
V_347 = ( V_278 - 1 ) - V_346 ;
if ( V_347 < 0 ) {
F_159 ( V_342 , V_323 ,
L_218
L_219
L_220 , V_279 [ 0 ] ) ;
}
}
if ( F_160 ( V_345 ) < 0 ) {
perror ( L_221 ) ;
return - 1 ;
}
V_90 = V_204 () ;
if ( V_90 < 0 ) {
perror ( L_222 ) ;
return - 1 ;
}
if ( ! V_90 ) {
V_1 = 0 ;
F_161 ( V_345 [ 1 ] , 1 ) ;
F_162 ( V_345 [ 0 ] ) ;
if ( F_128 ( V_279 [ 0 ] ) ) {
V_175 = true ;
} else if ( ! V_175 ) {
if ( F_130 ( V_278 - V_346 , & V_279 [ V_346 ] ) != 0 ) {
V_199 = - 1 ;
goto V_71;
}
}
V_280 = malloc ( ( V_278 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_280 ) {
F_6 ( L_121 ) ;
V_199 = - V_229 ;
goto V_71;
}
V_280 [ V_1 ++ ] = L_223 ;
V_280 [ V_1 ++ ] = V_302 ;
if ( V_175 )
V_280 [ V_1 ++ ] = L_224 ;
V_280 [ V_1 ++ ] = L_225 ;
V_280 [ V_1 ++ ] = L_226 ;
V_280 [ V_1 ++ ] = L_227 ;
for ( V_7 = V_346 + 1 ; V_7 < V_278 ; V_7 ++ )
V_280 [ V_1 ++ ] = V_279 [ V_7 ] ;
V_280 [ V_1 ++ ] = NULL ;
F_163 ( L_223 , ( char * * ) V_280 ) ;
free ( V_280 ) ;
exit ( - 1 ) ;
}
F_161 ( V_345 [ 0 ] , 0 ) ;
F_162 ( V_345 [ 1 ] ) ;
V_280 = malloc ( ( V_278 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_280 ) {
F_6 ( L_121 ) ;
V_199 = - V_229 ;
goto V_71;
}
V_1 = 0 ;
V_280 [ V_1 ++ ] = L_223 ;
V_280 [ V_1 ++ ] = V_303 ;
for ( V_7 = 1 ; V_7 < V_346 + 1 ; V_7 ++ )
V_280 [ V_1 ++ ] = V_279 [ V_7 ] ;
V_280 [ V_1 ++ ] = L_228 ;
V_280 [ V_1 ++ ] = L_227 ;
V_280 [ V_1 ++ ] = NULL ;
F_163 ( L_223 , ( char * * ) V_280 ) ;
free ( V_280 ) ;
exit ( - 1 ) ;
}
if ( V_302 )
V_261 = V_302 ;
if ( V_303 )
V_261 = V_303 ;
if ( V_261 ) {
V_1 = 0 ;
if ( ! V_302 )
V_175 = false ;
else if ( ! V_175 ) {
if ( F_130 ( V_278 - 1 , & V_279 [ 1 ] ) != 0 ) {
V_199 = - 1 ;
goto V_71;
}
}
V_280 = malloc ( ( V_278 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_280 ) {
F_6 ( L_121 ) ;
V_199 = - V_229 ;
goto V_71;
}
V_280 [ V_1 ++ ] = L_223 ;
V_280 [ V_1 ++ ] = V_261 ;
if ( V_175 )
V_280 [ V_1 ++ ] = L_224 ;
for ( V_7 = 2 ; V_7 < V_278 ; V_7 ++ )
V_280 [ V_1 ++ ] = V_279 [ V_7 ] ;
V_280 [ V_1 ++ ] = NULL ;
F_163 ( L_223 , ( char * * ) V_280 ) ;
free ( V_280 ) ;
exit ( - 1 ) ;
}
if ( ! V_225 )
F_164 () ;
V_21 = F_122 ( & V_271 , false , & V_158 . V_186 ) ;
if ( V_21 == NULL )
return - 1 ;
if ( V_22 || V_300 ) {
F_165 ( V_21 , stdout , V_299 ) ;
if ( V_300 )
goto V_348;
}
if ( F_166 ( & V_21 -> V_22 . V_349 ) < 0 )
goto V_348;
V_158 . V_21 = V_21 ;
F_132 ( & V_158 ) ;
V_21 -> V_304 = & V_304 ;
if ( V_196 ) {
V_199 = F_167 ( V_21 , V_196 , V_197 ) ;
if ( V_199 < 0 )
goto V_348;
}
if ( ! V_66 )
V_69 . V_67 = true ;
else
V_69 . V_67 = false ;
if ( V_21 -> V_350 . V_351 &&
F_168 ( V_21 -> V_350 . V_351 ,
V_352 ,
& V_21 -> V_353 . V_354 ) < 0 ) {
F_6 ( L_229 , V_355 ) ;
return - 1 ;
}
if ( V_326 ) {
struct V_239 V_356 ;
int V_357 ;
if ( F_1 () ) {
fprintf ( V_220 ,
L_230 ) ;
V_199 = - V_26 ;
goto V_348;
}
V_357 = F_169 ( V_271 . V_238 , V_358 ) ;
if ( V_357 < 0 ) {
V_199 = - V_359 ;
perror ( L_231 ) ;
goto V_348;
}
V_199 = F_170 ( V_357 , & V_356 ) ;
if ( V_199 < 0 ) {
perror ( L_232 ) ;
goto V_348;
}
if ( ! V_356 . V_360 ) {
fprintf ( V_220 , L_233 ) ;
goto V_348;
}
V_181 = F_96 ( V_326 ) ;
if ( ! V_181 ) {
fprintf ( V_220 , L_86 ) ;
V_199 = - V_361 ;
goto V_348;
}
V_199 = V_181 -> V_362 ( V_21 -> V_350 . V_351 ,
L_234 ) ;
goto V_348;
}
if ( V_225 ) {
V_199 = V_181 -> V_363 ( V_225 , V_278 , V_279 ) ;
if ( V_199 )
goto V_348;
F_7 ( L_235 , V_225 ) ;
V_301 = true ;
}
V_199 = F_14 ( V_21 ) ;
if ( V_199 < 0 )
goto V_348;
V_199 = F_88 ( & V_158 ) ;
F_61 () ;
V_348:
F_171 ( V_21 -> V_149 ) ;
F_123 ( V_21 ) ;
if ( V_301 )
F_62 () ;
V_71:
return V_199 ;
}
