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
if ( ! strcmp ( V_1 , L_5 ) ) {
V_13 = F_4 ( V_2 ) ;
return 0 ;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 , bool V_18 ,
void * V_19 )
{
int V_20 = 0 ;
struct V_4 * V_5 = V_19 ;
struct V_21 * V_22 = V_15 -> V_22 ;
struct V_23 * V_24 = V_15 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
if ( ! F_6 () )
return 0 ;
F_7 ( V_15 -> V_29 -> V_30 , V_17 , V_15 -> V_29 ,
V_5 -> V_31 ) ;
if ( V_32 == V_33 ) {
V_28 = V_22 -> V_27 ;
V_20 = F_8 ( & V_28 -> V_34 , V_24 -> V_35 ) ;
if ( V_20 )
goto V_36;
V_20 = F_8 ( & V_28 -> V_37 , V_24 -> V_35 ) ;
} else if ( V_5 -> V_38 ) {
V_26 = V_22 -> V_25 ;
V_20 = F_8 ( & V_26 -> V_39 , V_24 -> V_35 ) ;
if ( V_20 )
goto V_36;
V_20 = F_9 ( V_22 , V_24 -> V_35 , V_17 -> V_40 ) ;
} else if ( V_6 . V_11 ) {
if ( V_18 )
V_20 = F_9 ( V_22 , V_24 -> V_35 ,
V_17 -> V_40 ) ;
} else {
V_20 = F_9 ( V_22 , V_24 -> V_35 , V_17 -> V_40 ) ;
}
V_36:
return V_20 ;
}
static int F_10 ( struct V_41 * V_42 ,
union V_43 * V_44 ,
struct V_45 * V_29 ,
struct V_23 * V_24 ,
struct V_46 * V_46 )
{
struct V_4 * V_5 = F_11 ( V_42 , struct V_4 , V_42 ) ;
struct V_16 V_17 ;
struct V_14 V_15 = {
. V_24 = V_24 ,
. V_29 = V_29 ,
. V_47 = V_6 . V_47 ,
. V_48 = F_5 ,
} ;
int V_49 = 0 ;
if ( F_12 ( V_46 , & V_17 , V_29 ) < 0 ) {
F_13 ( L_6 ,
V_44 -> V_50 . type ) ;
return - 1 ;
}
if ( V_6 . V_47 && V_17 . V_51 == NULL )
goto V_52;
if ( V_5 -> V_53 && ! F_14 ( V_29 -> V_54 , V_5 -> V_55 ) )
goto V_52;
if ( V_32 == V_33 ) {
if ( ! V_29 -> V_30 )
goto V_52;
V_15 . V_56 = & V_57 ;
} else if ( V_5 -> V_38 ) {
V_15 . V_56 = & V_58 ;
} else if ( V_6 . V_11 ) {
V_15 . V_56 = & V_59 ;
} else {
V_15 . V_56 = & V_60 ;
}
if ( V_17 . V_61 != NULL )
V_17 . V_61 -> V_62 -> V_63 = 1 ;
V_49 = F_15 ( & V_15 , & V_17 , V_5 -> V_64 , V_5 ) ;
if ( V_49 < 0 )
F_13 ( L_7 ) ;
V_52:
F_16 ( & V_17 ) ;
return V_49 ;
}
static int F_17 ( struct V_41 * V_42 ,
union V_43 * V_44 ,
struct V_45 * V_29 V_65 ,
struct V_23 * V_24 ,
struct V_46 * V_46 V_65 )
{
struct V_4 * V_5 = F_11 ( V_42 , struct V_4 , V_42 ) ;
if ( V_5 -> V_66 ) {
const char * V_67 = V_24 ? F_18 ( V_24 ) : L_8 ;
F_19 ( & V_5 -> V_68 ,
V_44 -> V_69 . V_70 , V_44 -> V_69 . V_71 ,
V_44 -> V_69 . V_72 ,
V_67 ,
V_44 -> V_69 . V_2 ) ;
}
F_20 ( L_9 V_73 L_10 , V_44 -> V_69 . V_70 , V_44 -> V_69 . V_71 ,
V_24 ? F_18 ( V_24 ) : L_11 ,
V_44 -> V_69 . V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_74 * V_75 = V_5 -> V_75 ;
T_1 V_76 = F_22 ( V_75 -> V_77 ) ;
bool V_78 = F_23 ( V_75 -> V_79 ) ;
if ( V_75 -> V_80 -> V_81 ||
( ! V_78 &&
F_24 ( & V_75 -> V_50 , V_82 ) &&
! V_75 -> V_80 -> V_83 ) )
V_76 |= V_84 ;
if ( V_75 -> V_80 -> V_85 )
V_76 |= V_86 ;
if ( ! V_78 && ! ( V_76 & V_84 ) ) {
if ( V_87 . V_88 ) {
F_25 ( L_12
L_13
L_14 ) ;
return - V_89 ;
}
if ( V_6 . V_90 ) {
F_25 ( L_15
L_16
L_17 ) ;
return - 1 ;
}
} else if ( ! V_10 . V_91 &&
V_10 . V_92 != V_93 &&
! V_6 . V_90 ) {
V_6 . V_90 = true ;
if ( F_26 ( & V_10 ) < 0 ) {
F_25 ( L_18 ) ;
return - V_89 ;
}
}
if ( V_6 . V_11 ) {
if ( ! ( V_76 & V_84 ) ) {
V_6 . V_11 = false ;
F_27 () ;
}
}
if ( V_32 == V_33 ) {
if ( ! V_78 &&
! ( V_76 & V_86 ) ) {
F_25 ( L_19
L_20 ) ;
return - 1 ;
}
}
if ( V_6 . V_90 || V_6 . V_11 ) {
if ( ( V_76 & V_94 ) &&
( V_76 & V_95 ) )
V_10 . V_96 = V_97 ;
else if ( V_76 & V_86 )
V_10 . V_96 = V_98 ;
else
V_10 . V_96 = V_99 ;
}
if ( ! ( F_28 ( V_75 -> V_77 ) &
V_100 ) )
V_5 -> V_31 = true ;
return 0 ;
}
static void F_29 ( int T_2 V_65 )
{
V_101 = 1 ;
}
static T_3 F_30 ( struct V_102 * V_102 , struct V_4 * V_5 ,
const char * V_103 , T_4 * V_104 )
{
T_3 V_49 ;
char V_105 ;
unsigned long V_106 = V_102 -> V_107 . V_108 [ V_109 ] ;
T_1 V_108 = V_102 -> V_107 . V_110 ;
struct V_23 * V_24 = F_31 ( V_102 ) ;
char V_111 [ 512 ] ;
T_3 V_112 = sizeof( V_111 ) ;
int V_113 = V_102 -> V_114 ;
if ( V_6 . V_115 ) {
V_106 = V_102 -> V_107 . V_116 ;
V_108 = V_102 -> V_107 . V_117 ;
}
if ( F_32 ( V_24 ) ) {
struct V_23 * V_118 ;
F_33 ( V_24 , V_111 , V_112 ) ;
V_103 = V_111 ;
F_34 (pos, evsel) {
const struct V_102 * V_119 = F_35 ( V_118 ) ;
if ( V_6 . V_115 ) {
V_106 += V_119 -> V_107 . V_116 ;
V_108 += V_119 -> V_107 . V_117 ;
} else {
V_106 += V_119 -> V_107 . V_108 [ V_109 ] ;
V_108 += V_119 -> V_107 . V_110 ;
}
}
}
V_106 = F_36 ( V_106 , & V_105 ) ;
V_49 = fprintf ( V_104 , L_21 , V_106 , V_105 ) ;
if ( V_103 != NULL )
V_49 += fprintf ( V_104 , L_22 , V_103 ) ;
if ( V_6 . V_120 &&
strstr ( V_103 , L_23 ) ) {
V_49 += fprintf ( V_104 , L_24 ) ;
}
if ( V_5 -> V_38 ) {
V_49 += fprintf ( V_104 , L_25 V_73 , V_108 ) ;
V_49 += fprintf ( V_104 , L_26 , V_121 ? : V_122 ) ;
} else
V_49 += fprintf ( V_104 , L_27 V_73 , V_108 ) ;
if ( V_113 > - 1 )
V_49 += fprintf ( V_104 , L_28 , V_113 ) ;
return V_49 + fprintf ( V_104 , L_29 ) ;
}
static int F_37 ( struct V_123 * V_77 ,
struct V_4 * V_5 ,
const char * V_124 )
{
struct V_23 * V_118 ;
fprintf ( stdout , L_30 V_73 L_29 , V_77 -> V_107 . V_125 ) ;
F_38 (evlist, pos) {
struct V_102 * V_102 = F_35 ( V_118 ) ;
const char * V_103 = F_18 ( V_118 ) ;
if ( V_6 . V_7 &&
! F_39 ( V_118 ) )
continue;
F_30 ( V_102 , V_5 , V_103 , stdout ) ;
F_40 ( V_102 , true , 0 , 0 , V_5 -> V_9 , stdout ,
V_6 . V_90 ) ;
fprintf ( stdout , L_31 ) ;
}
if ( V_121 == NULL &&
V_126 == V_127 )
fprintf ( stdout , L_32 , V_124 ) ;
if ( V_5 -> V_66 ) {
bool V_128 = ! strcmp ( V_5 -> V_129 , L_33 ) ;
F_41 ( stdout , & V_5 -> V_68 ,
V_128 ) ;
F_42 ( & V_5 -> V_68 ) ;
}
return 0 ;
}
static void F_43 ( const struct V_4 * V_5 )
{
struct V_61 * V_130 = F_44 ( & V_5 -> V_75 -> V_131 . V_132 ) ;
struct V_133 * V_134 = V_130 ? F_45 ( V_130 ) : NULL ;
if ( V_130 == NULL ||
( V_130 -> V_62 -> V_63 &&
( V_134 -> V_135 == NULL ||
V_134 -> V_135 -> V_40 == 0 ) ) ) {
const char * V_136 =
L_34
L_35 ;
if ( V_130 ) {
const struct V_62 * V_137 = V_130 -> V_62 ;
if ( ! F_46 ( & V_137 -> V_138 [ V_139 ] ) ) {
V_136 = L_36
L_37 ;
}
}
F_47 (
L_38
L_39
L_40 ,
V_136 ) ;
}
}
static int F_48 ( struct V_4 * V_5 , const char * V_124 )
{
int (* F_49)( struct V_123 * V_77 , const char * V_124 ,
struct V_140 * V_141 , float V_142 );
F_49 = F_50 ( V_143 , L_41 ) ;
if ( F_49 == NULL ) {
F_25 ( L_42 ) ;
return - 1 ;
}
return F_49 ( V_5 -> V_75 -> V_77 , V_124 , NULL , V_5 -> V_9 ) ;
}
static int F_51 ( struct V_4 * V_5 )
{
int V_49 ;
struct V_74 * V_75 = V_5 -> V_75 ;
struct V_123 * V_77 = V_75 -> V_77 ;
const char * V_124 = F_52 ( F_53 ( V_144 ) ) ;
if ( V_124 == NULL ) {
V_124 = F_52 ( V_145 ) ;
if ( V_124 == NULL )
V_124 = L_43 ;
}
switch ( V_146 ) {
case 1 :
V_49 = F_54 ( V_77 , V_124 , NULL ,
V_5 -> V_9 ,
& V_75 -> V_50 . V_147 ) ;
if ( V_49 != V_148 )
V_49 = 0 ;
break;
case 2 :
V_49 = F_48 ( V_5 , V_124 ) ;
break;
default:
V_49 = F_37 ( V_77 , V_5 , V_124 ) ;
break;
}
return V_49 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_149 V_150 ;
struct V_23 * V_118 ;
int V_49 = 0 ;
F_56 ( & V_150 , V_5 -> V_151 , L_44 ) ;
F_38 (rep->session->evlist, pos) {
struct V_102 * V_102 = F_35 ( V_118 ) ;
if ( V_118 -> V_35 == 0 )
V_102 -> V_152 = V_5 -> V_152 ;
V_102 -> V_114 = V_5 -> V_114 ;
V_49 = F_57 ( V_102 , & V_150 ) ;
if ( V_49 < 0 )
break;
if ( V_6 . V_7 &&
! F_39 ( V_118 ) ) {
struct V_102 * V_153 = F_35 ( V_118 -> V_154 ) ;
F_58 ( V_153 , V_102 ) ;
F_59 ( V_153 , V_102 ) ;
}
}
F_60 () ;
return V_49 ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_149 V_150 ;
struct V_23 * V_118 ;
F_56 ( & V_150 , V_5 -> V_151 , L_45 ) ;
F_38 (rep->session->evlist, pos)
F_62 ( V_118 , & V_150 ) ;
F_60 () ;
}
static int F_63 ( struct V_4 * V_5 )
{
int V_49 ;
struct V_74 * V_75 = V_5 -> V_75 ;
struct V_23 * V_118 ;
struct V_155 * V_79 = V_75 -> V_79 ;
signal ( V_156 , F_29 ) ;
if ( V_5 -> V_53 ) {
V_49 = F_64 ( V_75 , V_5 -> V_53 ,
V_5 -> V_55 ) ;
if ( V_49 ) {
F_25 ( L_46 ) ;
return V_49 ;
}
}
if ( V_5 -> V_66 )
F_65 ( & V_5 -> V_68 ) ;
V_49 = F_21 ( V_5 ) ;
if ( V_49 ) {
return V_49 ;
}
V_49 = F_66 ( V_75 ) ;
if ( V_49 ) {
F_25 ( L_47 ) ;
return V_49 ;
}
F_43 ( V_5 ) ;
F_38 (session->evlist, pos)
V_5 -> V_151 += F_35 ( V_118 ) -> V_151 ;
if ( V_146 == 0 ) {
if ( V_157 > 3 )
F_67 ( V_75 , stdout ) ;
if ( V_157 > 2 )
F_68 ( V_75 , stdout ) ;
if ( V_158 ) {
F_69 ( V_75 , stdout ) ;
F_70 ( V_75 -> V_77 , stdout ) ;
return 0 ;
}
}
V_49 = F_55 ( V_5 ) ;
if ( V_49 ) {
F_25 ( L_48 ) ;
return V_49 ;
}
if ( V_101 () )
return 0 ;
V_5 -> V_151 = 0 ;
F_38 (session->evlist, pos)
V_5 -> V_151 += F_35 ( V_118 ) -> V_151 ;
if ( V_5 -> V_151 == 0 ) {
F_25 ( L_49 , V_79 -> V_159 ) ;
return 0 ;
}
F_61 ( V_5 ) ;
return F_51 ( V_5 ) ;
}
static int
F_71 ( const struct V_160 * V_161 , const char * V_19 , int V_162 )
{
struct V_10 * V_81 = V_161 -> V_2 ;
V_81 -> V_91 = ! V_162 ;
if ( V_162 ) {
V_6 . V_90 = false ;
V_81 -> V_92 = V_93 ;
return 0 ;
}
return F_72 ( V_19 ) ;
}
int
F_73 ( const struct V_160 * V_161 V_65 ,
const char * V_19 , int V_162 V_65 )
{
if ( V_19 ) {
int V_20 = regcomp ( & V_163 , V_19 , V_164 ) ;
if ( V_20 ) {
char V_111 [ V_165 ] ;
regerror ( V_20 , & V_163 , V_111 , sizeof( V_111 ) ) ;
F_74 ( L_50 , V_19 , V_111 ) ;
return - 1 ;
}
V_166 = 1 ;
}
return 0 ;
}
static int
F_75 ( const struct V_160 * V_161 V_65 ,
const char * T_5 V_65 , int V_162 )
{
int * V_167 = V_161 -> V_2 ;
* V_167 = ! V_162 ;
return 0 ;
}
static int
F_76 ( const struct V_160 * V_161 , const char * T_5 ,
int V_162 V_65 )
{
struct V_4 * V_5 = V_161 -> V_2 ;
double V_8 = strtof ( T_5 , NULL ) ;
V_5 -> V_9 = V_8 ;
V_10 . V_9 = V_8 ;
return 0 ;
}
int F_77 ( int V_168 , const char * * V_169 , const char * T_6 V_65 )
{
struct V_74 * V_75 ;
struct V_80 V_80 = { . V_83 = 0 , } ;
struct V_170 V_171 ;
bool V_172 = false ;
int V_167 = - 1 ;
bool V_173 = false ;
char V_174 [] = V_175 ;
const char * const V_176 [] = {
L_51 ,
NULL
} ;
struct V_4 V_4 = {
. V_42 = {
. V_29 = F_10 ,
. V_177 = V_178 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. exit = V_183 ,
. V_184 = V_185 ,
. V_186 = V_187 ,
. V_69 = F_17 ,
. V_188 = V_189 ,
. V_190 = V_191 ,
. V_192 = V_193 ,
. V_194 = V_195 ,
. V_196 = V_197 ,
. V_198 = V_199 ,
. V_200 = true ,
. V_201 = true ,
} ,
. V_64 = V_202 ,
. V_129 = L_52 ,
. V_114 = - 1 ,
} ;
const struct V_160 V_203 [] = {
F_78 ( 'i' , L_53 , & V_204 , L_54 ,
L_55 ) ,
F_79 ( 'v' , L_56 , & V_157 ,
L_57 ) ,
F_80 ( 'D' , L_58 , & V_158 ,
L_59 ) ,
F_78 ( 'k' , L_60 , & V_6 . V_205 ,
L_54 , L_61 ) ,
F_78 ( 0 , L_62 , & V_6 . V_206 ,
L_54 , L_63 ) ,
F_80 ( 'f' , L_64 , & V_6 . V_207 , L_65 ) ,
F_80 ( 'm' , L_66 , & V_6 . V_208 ,
L_67 ) ,
F_80 ( 'n' , L_68 , & V_6 . V_209 ,
L_69 ) ,
F_80 ( 'T' , L_70 , & V_4 . V_66 ,
L_71 ) ,
F_78 ( 0 , L_72 , & V_4 . V_129 , L_73 ,
L_74 ) ,
F_80 ( 0 , L_75 , & V_4 . V_210 , L_76 ) ,
F_80 ( 0 , L_77 , & V_4 . V_211 , L_78 ) ,
F_80 ( 0 , L_79 , & V_4 . V_212 ,
L_80 ) ,
F_80 ( 0 , L_81 , & V_4 . V_50 , L_82 ) ,
F_80 ( 0 , L_83 , & V_4 . V_213 ,
L_84 ) ,
F_78 ( 's' , L_85 , & V_121 , L_86 ,
L_87
L_88 ) ,
F_78 ( 'F' , L_89 , & V_214 , L_90 ,
L_91 ) ,
F_80 ( 0 , L_92 , & V_6 . V_215 ,
L_93 ) ,
F_81 ( 0 , L_94 , & V_6 . V_215 ,
L_93 , V_216 ) ,
F_78 ( 'p' , L_95 , & V_126 , L_96 ,
L_97 ) ,
F_80 ( 'x' , L_98 , & V_6 . V_217 ,
L_99 ) ,
F_82 ( 'g' , L_100 , & V_10 ,
L_101 ,
V_218 , & F_71 ,
V_174 ) ,
F_80 ( 0 , L_102 , & V_6 . V_11 ,
L_103 ) ,
F_83 ( 0 , L_104 , & V_4 . V_64 ,
L_105
L_106
L_107 F_84 ( V_202 ) ) ,
F_80 ( 'G' , L_108 , & V_4 . V_219 ,
L_109 ) ,
F_85 ( 0 , L_110 , NULL , L_96 ,
L_111 ,
F_73 ) ,
F_78 ( 'd' , L_112 , & V_6 . V_220 , L_113 ,
L_114 ) ,
F_78 ( 'c' , L_115 , & V_6 . V_221 , L_116 ,
L_117 ) ,
F_78 ( 0 , L_118 , & V_6 . V_222 , L_119 ,
L_120 ) ,
F_78 ( 0 , L_121 , & V_6 . V_223 , L_122 ,
L_123 ) ,
F_78 ( 'S' , L_124 , & V_6 . V_224 , L_125 ,
L_126 ) ,
F_78 ( 0 , L_127 , & V_4 . V_152 , L_128 ,
L_129 ) ,
F_78 ( 'w' , L_130 , & V_6 . V_225 ,
L_131 ,
L_132 ) ,
F_86 ( 't' , L_133 , & V_6 . V_226 , L_134 ,
L_135
L_136 ) ,
F_80 ( 'U' , L_137 , & V_6 . V_47 ,
L_138 ) ,
F_85 ( 0 , L_139 , NULL , L_140 ,
L_141 ,
V_227 ) ,
F_78 ( 'C' , L_142 , & V_4 . V_53 , L_142 ,
L_143 ) ,
F_80 ( 'I' , L_144 , & V_4 . V_228 ,
L_145 ) ,
F_80 ( 0 , L_146 , & V_6 . V_229 ,
L_147 ) ,
F_80 ( 0 , L_148 , & V_6 . V_230 ,
L_149 ) ,
F_78 ( 'M' , L_150 , & V_231 , L_151 ,
L_152 ) ,
F_80 ( 0 , L_153 , & V_6 . V_232 ,
L_154 ) ,
F_80 ( 0 , L_155 , & V_6 . V_7 ,
L_156 ) ,
F_87 ( 'b' , L_157 , & V_167 , L_158 ,
L_159 ,
F_75 ) ,
F_80 ( 0 , L_160 , & V_173 ,
L_161 ) ,
F_78 ( 0 , L_162 , & V_233 , L_163 ,
L_164 ) ,
F_80 ( 0 , L_165 , & V_6 . V_234 ,
L_166 ) ,
F_80 ( 0 , L_167 , & V_6 . V_235 ,
L_168 ) ,
F_80 ( 0 , L_169 , & V_4 . V_38 , L_170 ) ,
F_85 ( 0 , L_171 , & V_4 , L_172 ,
L_173 , F_76 ) ,
F_85 ( 0 , L_174 , NULL , L_175 ,
L_176 , V_236 ) ,
F_88 ( 0 , L_177 , & V_80 , NULL , L_178 ,
L_179 ,
V_237 ) ,
F_80 ( 0 , L_180 , & V_238 ,
L_181 ) ,
F_80 ( 0 , L_182 , & V_6 . V_120 ,
L_183 ) ,
F_83 ( 0 , L_184 , & V_4 . V_114 ,
L_185 ) ,
F_80 ( 0 , L_186 , & V_6 . V_239 ,
L_187 ) ,
F_80 ( 0 , L_188 , & V_6 . V_240 ,
L_189 ) ,
F_82 ( 0 , L_190 , NULL , L_191 ,
L_192 ,
V_241 , L_193 ) ,
F_89 ()
} ;
struct V_155 V_79 = {
. V_92 = V_242 ,
} ;
int V_49 = F_90 () ;
if ( V_49 < 0 )
return V_49 ;
F_91 ( F_1 , & V_4 ) ;
V_168 = F_92 ( V_168 , V_169 , V_203 , V_176 , 0 ) ;
if ( V_168 ) {
if ( V_168 > 1 )
F_93 ( V_176 , V_203 ) ;
V_4 . V_152 = V_169 [ 0 ] ;
}
if ( V_6 . V_205 &&
F_94 ( V_6 . V_205 , V_243 ) ) {
F_74 ( L_194 , V_6 . V_205 ) ;
return - V_89 ;
}
if ( V_6 . V_206 &&
F_94 ( V_6 . V_206 , V_243 ) ) {
F_74 ( L_194 , V_6 . V_206 ) ;
return - V_89 ;
}
if ( V_4 . V_212 )
V_146 = 0 ;
else if ( V_4 . V_210 )
V_146 = 1 ;
else if ( V_4 . V_211 )
V_146 = 2 ;
if ( V_4 . V_219 )
V_10 . V_244 = V_245 ;
if ( V_6 . V_11 && ! V_10 . V_246 )
V_10 . V_244 = V_245 ;
if ( V_80 . V_81 &&
( int ) V_80 . V_247 > V_4 . V_64 )
V_4 . V_64 = V_80 . V_247 ;
if ( ! V_204 || ! strlen ( V_204 ) ) {
if ( ! F_95 ( V_248 , & V_171 ) && F_96 ( V_171 . V_249 ) )
V_204 = L_195 ;
else
V_204 = L_196 ;
}
V_79 . V_159 = V_204 ;
V_79 . V_207 = V_6 . V_207 ;
V_250:
V_75 = F_97 ( & V_79 , false , & V_4 . V_42 ) ;
if ( V_75 == NULL )
return - 1 ;
if ( V_4 . V_12 ) {
F_98 ( & V_75 -> V_200 ,
V_4 . V_12 ) ;
}
V_75 -> V_80 = & V_80 ;
V_4 . V_75 = V_75 ;
V_172 = F_24 ( & V_75 -> V_50 ,
V_251 ) ;
if ( V_80 . V_85 )
V_172 = true ;
if ( ( ( V_167 == - 1 && V_172 ) || V_167 == 1 ) &&
! V_173 ) {
V_32 = V_33 ;
V_6 . V_11 = false ;
}
if ( V_173 ) {
V_10 . V_252 = V_253 ;
V_10 . V_254 = 1 ;
V_6 . V_90 = true ;
F_26 ( & V_10 ) ;
if ( V_121 == NULL )
V_121 = L_197 ;
}
if ( V_4 . V_38 ) {
if ( V_32 == V_33 ) {
F_74 ( L_198 ) ;
goto error;
}
V_32 = V_255 ;
V_6 . V_11 = false ;
}
if ( V_6 . V_240 ) {
V_6 . V_11 = false ;
if ( V_214 ) {
F_74 ( L_199 ) ;
F_99 ( V_176 , V_203 , L_200 , 1 ) ;
F_99 ( NULL , V_203 , L_188 , 0 ) ;
goto error;
}
V_87 . V_256 = true ;
}
if ( V_4 . V_50 || V_4 . V_213 || V_4 . V_66 )
V_146 = 0 ;
if ( strcmp ( V_204 , L_195 ) != 0 )
F_100 ( true ) ;
else
V_146 = 0 ;
if ( F_101 ( V_75 -> V_77 ) < 0 ) {
if ( V_121 )
F_99 ( V_176 , V_203 , L_201 , 1 ) ;
if ( V_214 )
F_99 ( V_121 ? NULL : V_176 ,
V_203 , L_200 , 1 ) ;
goto error;
}
if ( V_4 . V_50 || V_4 . V_213 ) {
F_102 ( V_75 , stdout ,
V_4 . V_228 ) ;
if ( V_4 . V_213 ) {
V_49 = 0 ;
goto error;
}
} else if ( V_146 == 0 ) {
fputs ( L_202 ,
stdout ) ;
}
if ( F_6 () ) {
V_49 = F_103 () ;
if ( V_49 < 0 )
goto error;
if ( V_157 ) {
V_6 . V_257 += sizeof( V_258 ) ;
V_6 . V_259 = true ;
}
}
if ( F_104 ( & V_75 -> V_50 . V_147 ) < 0 )
goto error;
F_105 ( stdout ) ;
V_49 = F_63 ( & V_4 ) ;
if ( V_49 == V_148 ) {
F_106 ( V_75 ) ;
goto V_250;
} else
V_49 = 0 ;
error:
F_106 ( V_75 ) ;
return V_49 ;
}
