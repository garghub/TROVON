static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! strcmp ( V_1 , L_1 ) ) {
V_6 . V_7 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_2 ) ) {
double V_8 = strtof ( V_2 , NULL ) ;
V_5 -> V_9 = V_8 ;
V_10 . V_9 = V_8 ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_3 ) ) {
V_6 . V_11 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_4 ) ) {
V_5 -> V_12 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
return 0 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 , bool V_17 ,
void * V_18 )
{
int V_19 = 0 ;
struct V_4 * V_5 = V_18 ;
struct V_20 * V_21 = V_14 -> V_21 ;
struct V_22 * V_23 = V_14 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( ! F_5 () )
return 0 ;
F_6 ( V_14 -> V_28 -> V_29 , V_16 , V_14 -> V_28 ,
V_5 -> V_30 ) ;
if ( V_31 == V_32 ) {
V_27 = V_21 -> V_26 ;
V_19 = F_7 ( & V_27 -> V_33 , V_23 -> V_34 ) ;
if ( V_19 )
goto V_35;
V_19 = F_7 ( & V_27 -> V_36 , V_23 -> V_34 ) ;
} else if ( V_5 -> V_37 ) {
V_25 = V_21 -> V_24 ;
V_19 = F_7 ( & V_25 -> V_38 , V_23 -> V_34 ) ;
if ( V_19 )
goto V_35;
V_19 = F_8 ( V_21 , V_23 -> V_34 , V_16 -> V_39 ) ;
} else if ( V_6 . V_11 ) {
if ( V_17 )
V_19 = F_8 ( V_21 , V_23 -> V_34 ,
V_16 -> V_39 ) ;
} else {
V_19 = F_8 ( V_21 , V_23 -> V_34 , V_16 -> V_39 ) ;
}
V_35:
return V_19 ;
}
static int F_9 ( struct V_40 * V_41 ,
union V_42 * V_43 ,
struct V_44 * V_28 ,
struct V_22 * V_23 ,
struct V_45 * V_45 )
{
struct V_4 * V_5 = F_10 ( V_41 , struct V_4 , V_41 ) ;
struct V_15 V_16 ;
struct V_13 V_14 = {
. V_23 = V_23 ,
. V_28 = V_28 ,
. V_46 = V_6 . V_46 ,
. V_47 = F_4 ,
} ;
int V_48 = 0 ;
if ( F_11 ( V_45 , & V_16 , V_28 ) < 0 ) {
F_12 ( L_5 ,
V_43 -> V_49 . type ) ;
return - 1 ;
}
if ( V_6 . V_46 && V_16 . V_50 == NULL )
goto V_51;
if ( V_5 -> V_52 && ! F_13 ( V_28 -> V_53 , V_5 -> V_54 ) )
goto V_51;
if ( V_31 == V_32 ) {
if ( ! V_28 -> V_29 )
goto V_51;
V_14 . V_55 = & V_56 ;
} else if ( V_5 -> V_37 ) {
V_14 . V_55 = & V_57 ;
} else if ( V_6 . V_11 ) {
V_14 . V_55 = & V_58 ;
} else {
V_14 . V_55 = & V_59 ;
}
if ( V_16 . V_60 != NULL )
V_16 . V_60 -> V_61 -> V_62 = 1 ;
V_48 = F_14 ( & V_14 , & V_16 , V_5 -> V_63 , V_5 ) ;
if ( V_48 < 0 )
F_12 ( L_6 ) ;
V_51:
F_15 ( & V_16 ) ;
return V_48 ;
}
static int F_16 ( struct V_40 * V_41 ,
union V_42 * V_43 ,
struct V_44 * V_28 V_64 ,
struct V_22 * V_23 ,
struct V_45 * V_45 V_64 )
{
struct V_4 * V_5 = F_10 ( V_41 , struct V_4 , V_41 ) ;
if ( V_5 -> V_65 ) {
const char * V_66 = V_23 ? F_17 ( V_23 ) : L_7 ;
F_18 ( & V_5 -> V_67 ,
V_43 -> V_68 . V_69 , V_43 -> V_68 . V_70 ,
V_43 -> V_68 . V_71 ,
V_66 ,
V_43 -> V_68 . V_2 ) ;
}
F_19 ( L_8 V_72 L_9 , V_43 -> V_68 . V_69 , V_43 -> V_68 . V_70 ,
V_23 ? F_17 ( V_23 ) : L_10 ,
V_43 -> V_68 . V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_73 * V_74 = V_5 -> V_74 ;
T_1 V_75 = F_21 ( V_74 -> V_76 ) ;
bool V_77 = F_22 ( V_74 -> V_78 ) ;
if ( V_74 -> V_79 -> V_80 ||
( ! V_77 &&
F_23 ( & V_74 -> V_49 , V_81 ) &&
! V_74 -> V_79 -> V_82 ) )
V_75 |= V_83 ;
if ( V_74 -> V_79 -> V_84 )
V_75 |= V_85 ;
if ( ! V_77 && ! ( V_75 & V_83 ) ) {
if ( V_86 ) {
F_24 ( L_11
L_12
L_13 ) ;
return - V_87 ;
}
if ( V_6 . V_88 ) {
F_24 ( L_14
L_15
L_16 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_89 &&
V_10 . V_90 != V_91 &&
! V_6 . V_88 ) {
V_6 . V_88 = true ;
if ( F_25 ( & V_10 ) < 0 ) {
F_24 ( L_17 ) ;
return - V_87 ;
}
}
if ( V_6 . V_11 ) {
if ( ! ( V_75 & V_83 ) ) {
V_6 . V_11 = false ;
F_26 () ;
}
}
if ( V_31 == V_32 ) {
if ( ! V_77 &&
! ( V_75 & V_85 ) ) {
F_24 ( L_18
L_19 ) ;
return - 1 ;
}
}
if ( V_6 . V_88 || V_6 . V_11 ) {
if ( ( V_75 & V_92 ) &&
( V_75 & V_93 ) )
V_10 . V_94 = V_95 ;
else if ( V_75 & V_85 )
V_10 . V_94 = V_96 ;
else
V_10 . V_94 = V_97 ;
}
if ( ! ( F_27 ( V_74 -> V_76 ) &
V_98 ) )
V_5 -> V_30 = true ;
return 0 ;
}
static void F_28 ( int T_2 V_64 )
{
V_99 = 1 ;
}
static T_3 F_29 ( struct V_100 * V_100 , struct V_4 * V_5 ,
const char * V_101 , T_4 * V_102 )
{
T_3 V_48 ;
char V_103 ;
unsigned long V_104 = V_100 -> V_105 . V_106 [ V_107 ] ;
T_1 V_106 = V_100 -> V_105 . V_108 ;
struct V_22 * V_23 = F_30 ( V_100 ) ;
char V_109 [ 512 ] ;
T_3 V_110 = sizeof( V_109 ) ;
int V_111 = V_100 -> V_112 ;
if ( V_6 . V_113 ) {
V_104 = V_100 -> V_105 . V_114 ;
V_106 = V_100 -> V_105 . V_115 ;
}
if ( F_31 ( V_23 ) ) {
struct V_22 * V_116 ;
F_32 ( V_23 , V_109 , V_110 ) ;
V_101 = V_109 ;
F_33 (pos, evsel) {
const struct V_100 * V_117 = F_34 ( V_116 ) ;
if ( V_6 . V_113 ) {
V_104 += V_117 -> V_105 . V_114 ;
V_106 += V_117 -> V_105 . V_115 ;
} else {
V_104 += V_117 -> V_105 . V_106 [ V_107 ] ;
V_106 += V_117 -> V_105 . V_108 ;
}
}
}
V_104 = F_35 ( V_104 , & V_103 ) ;
V_48 = fprintf ( V_102 , L_20 , V_104 , V_103 ) ;
if ( V_101 != NULL )
V_48 += fprintf ( V_102 , L_21 , V_101 ) ;
if ( V_6 . V_118 &&
strstr ( V_101 , L_22 ) ) {
V_48 += fprintf ( V_102 , L_23 ) ;
}
if ( V_5 -> V_37 ) {
V_48 += fprintf ( V_102 , L_24 V_72 , V_106 ) ;
V_48 += fprintf ( V_102 , L_25 , V_119 ? : V_120 ) ;
} else
V_48 += fprintf ( V_102 , L_26 V_72 , V_106 ) ;
if ( V_111 > - 1 )
V_48 += fprintf ( V_102 , L_27 , V_111 ) ;
return V_48 + fprintf ( V_102 , L_28 ) ;
}
static int F_36 ( struct V_121 * V_76 ,
struct V_4 * V_5 ,
const char * V_122 )
{
struct V_22 * V_116 ;
fprintf ( stdout , L_29 V_72 L_28 , V_76 -> V_105 . V_123 ) ;
F_37 (evlist, pos) {
struct V_100 * V_100 = F_34 ( V_116 ) ;
const char * V_101 = F_17 ( V_116 ) ;
if ( V_6 . V_7 &&
! F_38 ( V_116 ) )
continue;
F_29 ( V_100 , V_5 , V_101 , stdout ) ;
F_39 ( V_100 , true , 0 , 0 , V_5 -> V_9 , stdout ) ;
fprintf ( stdout , L_30 ) ;
}
if ( V_119 == NULL &&
V_124 == V_125 )
fprintf ( stdout , L_31 , V_122 ) ;
if ( V_5 -> V_65 ) {
bool V_126 = ! strcmp ( V_5 -> V_127 , L_32 ) ;
F_40 ( stdout , & V_5 -> V_67 ,
V_126 ) ;
F_41 ( & V_5 -> V_67 ) ;
}
return 0 ;
}
static void F_42 ( const struct V_4 * V_5 )
{
struct V_60 * V_128 = F_43 ( & V_5 -> V_74 -> V_129 . V_130 ) ;
struct V_131 * V_132 = V_128 ? F_44 ( V_128 ) : NULL ;
if ( V_128 == NULL ||
( V_128 -> V_61 -> V_62 &&
( V_132 -> V_133 == NULL ||
V_132 -> V_133 -> V_39 == 0 ) ) ) {
const char * V_134 =
L_33
L_34 ;
if ( V_128 ) {
const struct V_61 * V_135 = V_128 -> V_61 ;
if ( ! F_45 ( & V_135 -> V_136 [ V_137 ] ) ) {
V_134 = L_35
L_36 ;
}
}
F_46 (
L_37
L_38
L_39 ,
V_134 ) ;
}
}
static int F_47 ( struct V_4 * V_5 , const char * V_122 )
{
int (* F_48)( struct V_121 * V_76 , const char * V_122 ,
struct V_138 * V_139 , float V_140 );
F_48 = F_49 ( V_141 , L_40 ) ;
if ( F_48 == NULL ) {
F_24 ( L_41 ) ;
return - 1 ;
}
return F_48 ( V_5 -> V_74 -> V_76 , V_122 , NULL , V_5 -> V_9 ) ;
}
static int F_50 ( struct V_4 * V_5 )
{
int V_48 ;
struct V_73 * V_74 = V_5 -> V_74 ;
struct V_121 * V_76 = V_74 -> V_76 ;
const char * V_122 = F_51 ( F_52 ( V_142 ) ) ;
if ( V_122 == NULL ) {
V_122 = F_51 ( V_143 ) ;
if ( V_122 == NULL )
V_122 = L_42 ;
}
switch ( V_144 ) {
case 1 :
V_48 = F_53 ( V_76 , V_122 , NULL ,
V_5 -> V_9 ,
& V_74 -> V_49 . V_145 ) ;
if ( V_48 != V_146 )
V_48 = 0 ;
break;
case 2 :
V_48 = F_47 ( V_5 , V_122 ) ;
break;
default:
V_48 = F_36 ( V_76 , V_5 , V_122 ) ;
break;
}
return V_48 ;
}
static int F_54 ( struct V_4 * V_5 )
{
struct V_147 V_148 ;
struct V_22 * V_116 ;
int V_48 = 0 ;
F_55 ( & V_148 , V_5 -> V_149 , L_43 ) ;
F_37 (rep->session->evlist, pos) {
struct V_100 * V_100 = F_34 ( V_116 ) ;
if ( V_116 -> V_34 == 0 )
V_100 -> V_150 = V_5 -> V_150 ;
V_100 -> V_112 = V_5 -> V_112 ;
V_48 = F_56 ( V_100 , & V_148 ) ;
if ( V_48 < 0 )
break;
if ( V_6 . V_7 &&
! F_38 ( V_116 ) ) {
struct V_100 * V_151 = F_34 ( V_116 -> V_152 ) ;
F_57 ( V_151 , V_100 ) ;
F_58 ( V_151 , V_100 ) ;
}
}
F_59 () ;
return V_48 ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_147 V_148 ;
struct V_22 * V_116 ;
F_55 ( & V_148 , V_5 -> V_149 , L_44 ) ;
F_37 (rep->session->evlist, pos)
F_61 ( V_116 , & V_148 ) ;
F_59 () ;
}
static int F_62 ( struct V_4 * V_5 )
{
int V_48 ;
struct V_73 * V_74 = V_5 -> V_74 ;
struct V_22 * V_116 ;
struct V_153 * V_78 = V_74 -> V_78 ;
signal ( V_154 , F_28 ) ;
if ( V_5 -> V_52 ) {
V_48 = F_63 ( V_74 , V_5 -> V_52 ,
V_5 -> V_54 ) ;
if ( V_48 ) {
F_24 ( L_45 ) ;
return V_48 ;
}
}
if ( V_5 -> V_65 )
F_64 ( & V_5 -> V_67 ) ;
V_48 = F_20 ( V_5 ) ;
if ( V_48 ) {
return V_48 ;
}
V_48 = F_65 ( V_74 ) ;
if ( V_48 ) {
F_24 ( L_46 ) ;
return V_48 ;
}
F_42 ( V_5 ) ;
F_37 (session->evlist, pos)
V_5 -> V_149 += F_34 ( V_116 ) -> V_149 ;
if ( V_144 == 0 ) {
if ( V_155 > 3 )
F_66 ( V_74 , stdout ) ;
if ( V_155 > 2 )
F_67 ( V_74 , stdout ) ;
if ( V_156 ) {
F_68 ( V_74 , stdout ) ;
F_69 ( V_74 -> V_76 , stdout ) ;
return 0 ;
}
}
V_48 = F_54 ( V_5 ) ;
if ( V_48 ) {
F_24 ( L_47 ) ;
return V_48 ;
}
if ( V_99 () )
return 0 ;
V_5 -> V_149 = 0 ;
F_37 (session->evlist, pos)
V_5 -> V_149 += F_34 ( V_116 ) -> V_149 ;
if ( V_5 -> V_149 == 0 ) {
F_24 ( L_48 , V_78 -> V_157 ) ;
return 0 ;
}
F_60 ( V_5 ) ;
return F_50 ( V_5 ) ;
}
static int
F_70 ( const struct V_158 * V_159 , const char * V_18 , int V_160 )
{
struct V_4 * V_5 = (struct V_4 * ) V_159 -> V_2 ;
if ( V_160 ) {
V_5 -> V_89 = true ;
return 0 ;
}
return F_71 ( V_18 ) ;
}
int
F_72 ( const struct V_158 * V_159 V_64 ,
const char * V_18 , int V_160 V_64 )
{
if ( V_18 ) {
int V_19 = regcomp ( & V_161 , V_18 , V_162 ) ;
if ( V_19 ) {
char V_109 [ V_163 ] ;
regerror ( V_19 , & V_161 , V_109 , sizeof( V_109 ) ) ;
F_73 ( L_49 , V_18 , V_109 ) ;
return - 1 ;
}
V_164 = 1 ;
}
return 0 ;
}
static int
F_74 ( const struct V_158 * V_159 V_64 ,
const char * T_5 V_64 , int V_160 )
{
int * V_165 = V_159 -> V_2 ;
* V_165 = ! V_160 ;
return 0 ;
}
static int
F_75 ( const struct V_158 * V_159 , const char * T_5 ,
int V_160 V_64 )
{
struct V_4 * V_5 = V_159 -> V_2 ;
double V_8 = strtof ( T_5 , NULL ) ;
V_5 -> V_9 = V_8 ;
V_10 . V_9 = V_8 ;
return 0 ;
}
int F_76 ( int V_166 , const char * * V_167 , const char * T_6 V_64 )
{
struct V_73 * V_74 ;
struct V_79 V_79 = { . V_82 = 0 , } ;
struct V_168 V_169 ;
bool V_170 = false ;
int V_165 = - 1 ;
bool V_171 = false ;
char V_172 [] = V_173 ;
const char * const V_174 [] = {
L_50 ,
NULL
} ;
struct V_4 V_4 = {
. V_41 = {
. V_28 = F_9 ,
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_179 = V_180 ,
. exit = V_181 ,
. V_182 = V_183 ,
. V_184 = V_185 ,
. V_68 = F_16 ,
. V_186 = V_187 ,
. V_188 = V_189 ,
. V_190 = V_191 ,
. V_192 = V_193 ,
. V_194 = V_195 ,
. V_196 = V_197 ,
. V_198 = true ,
. V_199 = true ,
} ,
. V_63 = V_200 ,
. V_127 = L_51 ,
. V_112 = - 1 ,
} ;
const struct V_158 V_201 [] = {
F_77 ( 'i' , L_52 , & V_202 , L_53 ,
L_54 ) ,
F_78 ( 'v' , L_55 , & V_155 ,
L_56 ) ,
F_79 ( 'D' , L_57 , & V_156 ,
L_58 ) ,
F_77 ( 'k' , L_59 , & V_6 . V_203 ,
L_53 , L_60 ) ,
F_77 ( 0 , L_61 , & V_6 . V_204 ,
L_53 , L_62 ) ,
F_79 ( 'f' , L_63 , & V_6 . V_205 , L_64 ) ,
F_79 ( 'm' , L_65 , & V_6 . V_206 ,
L_66 ) ,
F_79 ( 'n' , L_67 , & V_6 . V_207 ,
L_68 ) ,
F_79 ( 'T' , L_69 , & V_4 . V_65 ,
L_70 ) ,
F_77 ( 0 , L_71 , & V_4 . V_127 , L_72 ,
L_73 ) ,
F_79 ( 0 , L_74 , & V_4 . V_208 , L_75 ) ,
F_79 ( 0 , L_76 , & V_4 . V_209 , L_77 ) ,
F_79 ( 0 , L_78 , & V_4 . V_210 ,
L_79 ) ,
F_79 ( 0 , L_80 , & V_4 . V_49 , L_81 ) ,
F_79 ( 0 , L_82 , & V_4 . V_211 ,
L_83 ) ,
F_77 ( 's' , L_84 , & V_119 , L_85 ,
L_86
L_87 ) ,
F_77 ( 'F' , L_88 , & V_212 , L_89 ,
L_90 ) ,
F_79 ( 0 , L_91 , & V_6 . V_213 ,
L_92 ) ,
F_80 ( 0 , L_93 , & V_6 . V_213 ,
L_92 , V_214 ) ,
F_77 ( 'p' , L_94 , & V_124 , L_95 ,
L_96 ) ,
F_79 ( 'x' , L_97 , & V_6 . V_215 ,
L_98 ) ,
F_81 ( 'g' , L_99 , & V_4 ,
L_100 ,
V_216 , & F_70 ,
V_172 ) ,
F_79 ( 0 , L_101 , & V_6 . V_11 ,
L_102 ) ,
F_82 ( 0 , L_103 , & V_4 . V_63 ,
L_104
L_105
L_106 F_83 ( V_200 ) ) ,
F_79 ( 'G' , L_107 , & V_4 . V_217 ,
L_108 ) ,
F_84 ( 0 , L_109 , NULL , L_95 ,
L_110 ,
F_72 ) ,
F_77 ( 'd' , L_111 , & V_6 . V_218 , L_112 ,
L_113 ) ,
F_77 ( 'c' , L_114 , & V_6 . V_219 , L_115 ,
L_116 ) ,
F_77 ( 0 , L_117 , & V_6 . V_220 , L_118 ,
L_119 ) ,
F_77 ( 0 , L_120 , & V_6 . V_221 , L_121 ,
L_122 ) ,
F_77 ( 'S' , L_123 , & V_6 . V_222 , L_124 ,
L_125 ) ,
F_77 ( 0 , L_126 , & V_4 . V_150 , L_127 ,
L_128 ) ,
F_77 ( 'w' , L_129 , & V_6 . V_223 ,
L_130 ,
L_131 ) ,
F_85 ( 't' , L_132 , & V_6 . V_224 , L_133 ,
L_134
L_135 ) ,
F_79 ( 'U' , L_136 , & V_6 . V_46 ,
L_137 ) ,
F_77 ( 0 , L_138 , & V_6 . V_225 , L_139 ,
L_140 ) ,
F_77 ( 'C' , L_141 , & V_4 . V_52 , L_141 ,
L_142 ) ,
F_79 ( 'I' , L_143 , & V_4 . V_226 ,
L_144 ) ,
F_79 ( 0 , L_145 , & V_6 . V_227 ,
L_146 ) ,
F_79 ( 0 , L_147 , & V_6 . V_228 ,
L_148 ) ,
F_77 ( 'M' , L_149 , & V_229 , L_150 ,
L_151 ) ,
F_79 ( 0 , L_152 , & V_6 . V_230 ,
L_153 ) ,
F_79 ( 0 , L_154 , & V_6 . V_7 ,
L_155 ) ,
F_86 ( 'b' , L_156 , & V_165 , L_157 ,
L_158 ,
F_74 ) ,
F_79 ( 0 , L_159 , & V_171 ,
L_160 ) ,
F_77 ( 0 , L_161 , & V_231 , L_162 ,
L_163 ) ,
F_79 ( 0 , L_164 , & V_6 . V_232 ,
L_165 ) ,
F_79 ( 0 , L_166 , & V_6 . V_233 ,
L_167 ) ,
F_79 ( 0 , L_168 , & V_4 . V_37 , L_169 ) ,
F_84 ( 0 , L_170 , & V_4 , L_171 ,
L_172 , F_75 ) ,
F_84 ( 0 , L_173 , NULL , L_174 ,
L_175 , V_234 ) ,
F_87 ( 0 , L_176 , & V_79 , NULL , L_177 ,
L_178 ,
V_235 ) ,
F_79 ( 0 , L_179 , & V_236 ,
L_180 ) ,
F_79 ( 0 , L_181 , & V_6 . V_118 ,
L_182 ) ,
F_82 ( 0 , L_183 , & V_4 . V_112 ,
L_184 ) ,
F_79 ( 0 , L_185 , & V_6 . V_237 ,
L_186 ) ,
F_79 ( 0 , L_187 , & V_6 . V_238 ,
L_188 ) ,
F_88 ()
} ;
struct V_153 V_78 = {
. V_90 = V_239 ,
} ;
int V_48 = F_89 () ;
if ( V_48 < 0 )
return V_48 ;
F_90 ( F_1 , & V_4 ) ;
V_166 = F_91 ( V_166 , V_167 , V_201 , V_174 , 0 ) ;
if ( V_166 ) {
if ( V_166 > 1 )
F_92 ( V_174 , V_201 ) ;
V_4 . V_150 = V_167 [ 0 ] ;
}
if ( V_6 . V_203 &&
F_93 ( V_6 . V_203 , V_240 ) ) {
F_73 ( L_189 , V_6 . V_203 ) ;
return - V_87 ;
}
if ( V_6 . V_204 &&
F_93 ( V_6 . V_204 , V_240 ) ) {
F_73 ( L_189 , V_6 . V_204 ) ;
return - V_87 ;
}
if ( V_4 . V_210 )
V_144 = 0 ;
else if ( V_4 . V_208 )
V_144 = 1 ;
else if ( V_4 . V_209 )
V_144 = 2 ;
if ( V_4 . V_217 )
V_10 . V_241 = V_242 ;
if ( V_6 . V_11 && ! V_10 . V_243 )
V_10 . V_241 = V_242 ;
if ( V_79 . V_80 &&
( int ) V_79 . V_244 > V_4 . V_63 )
V_4 . V_63 = V_79 . V_244 ;
if ( ! V_202 || ! strlen ( V_202 ) ) {
if ( ! F_94 ( V_245 , & V_169 ) && F_95 ( V_169 . V_246 ) )
V_202 = L_190 ;
else
V_202 = L_191 ;
}
V_78 . V_157 = V_202 ;
V_78 . V_205 = V_6 . V_205 ;
V_247:
V_74 = F_96 ( & V_78 , false , & V_4 . V_41 ) ;
if ( V_74 == NULL )
return - 1 ;
if ( V_4 . V_12 ) {
F_97 ( & V_74 -> V_198 ,
V_4 . V_12 ) ;
}
V_74 -> V_79 = & V_79 ;
V_4 . V_74 = V_74 ;
V_170 = F_23 ( & V_74 -> V_49 ,
V_248 ) ;
if ( V_79 . V_84 )
V_170 = true ;
if ( ( ( V_165 == - 1 && V_170 ) || V_165 == 1 ) &&
! V_171 ) {
V_31 = V_32 ;
V_6 . V_11 = false ;
}
if ( V_171 ) {
V_10 . V_249 = V_250 ;
V_10 . V_251 = 1 ;
V_6 . V_88 = true ;
F_25 ( & V_10 ) ;
if ( V_119 == NULL )
V_119 = L_192 ;
}
if ( V_4 . V_37 ) {
if ( V_31 == V_32 ) {
F_73 ( L_193 ) ;
goto error;
}
V_31 = V_252 ;
V_6 . V_11 = false ;
}
if ( V_6 . V_238 ) {
V_6 . V_7 = false ;
V_6 . V_11 = false ;
if ( V_212 ) {
F_73 ( L_194 ) ;
F_98 ( V_174 , V_201 , L_195 , 1 ) ;
F_98 ( NULL , V_201 , L_187 , 0 ) ;
goto error;
}
V_253 = true ;
}
if ( V_4 . V_49 || V_4 . V_211 || V_4 . V_65 )
V_144 = 0 ;
if ( strcmp ( V_202 , L_190 ) != 0 )
F_99 ( true ) ;
else
V_144 = 0 ;
if ( F_100 ( V_74 -> V_76 ) < 0 ) {
if ( V_119 )
F_98 ( V_174 , V_201 , L_196 , 1 ) ;
if ( V_212 )
F_98 ( V_119 ? NULL : V_174 ,
V_201 , L_195 , 1 ) ;
goto error;
}
if ( V_4 . V_49 || V_4 . V_211 ) {
F_101 ( V_74 , stdout ,
V_4 . V_226 ) ;
if ( V_4 . V_211 ) {
V_48 = 0 ;
goto error;
}
} else if ( V_144 == 0 ) {
fputs ( L_197 ,
stdout ) ;
}
if ( F_5 () ) {
V_6 . V_254 = sizeof( struct V_255 ) ;
F_102 ( & V_74 -> V_129 ,
V_256 ) ;
if ( V_155 ) {
V_6 . V_254 += sizeof( V_257 ) ;
V_6 . V_258 = true ;
}
}
if ( F_103 ( & V_74 -> V_49 . V_145 ) < 0 )
goto error;
F_104 ( stdout ) ;
V_48 = F_62 ( & V_4 ) ;
if ( V_48 == V_146 ) {
F_105 ( V_74 ) ;
goto V_247;
} else
V_48 = 0 ;
error:
F_105 ( V_74 ) ;
return V_48 ;
}
