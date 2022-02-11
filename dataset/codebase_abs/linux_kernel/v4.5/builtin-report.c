static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! strcmp ( V_1 , L_1 ) ) {
V_6 . V_7 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_2 ) ) {
V_5 -> V_8 = strtof ( V_2 , NULL ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_3 ) ) {
V_6 . V_9 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_4 ) ) {
V_5 -> V_10 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
return F_4 ( V_1 , V_2 , V_3 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 , bool V_15 ,
void * V_16 )
{
int V_17 = 0 ;
struct V_4 * V_5 = V_16 ;
struct V_18 * V_19 = V_12 -> V_19 ;
struct V_20 * V_21 = V_12 -> V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
if ( ! F_6 () )
return 0 ;
F_7 ( V_12 -> V_26 -> V_27 , V_14 , V_12 -> V_26 ,
V_5 -> V_28 ) ;
if ( V_29 == V_30 ) {
V_25 = V_19 -> V_24 ;
V_17 = F_8 ( & V_25 -> V_31 , V_21 -> V_32 ) ;
if ( V_17 )
goto V_33;
V_17 = F_8 ( & V_25 -> V_34 , V_21 -> V_32 ) ;
} else if ( V_5 -> V_35 ) {
V_23 = V_19 -> V_22 ;
V_17 = F_8 ( & V_23 -> V_36 , V_21 -> V_32 ) ;
if ( V_17 )
goto V_33;
V_17 = F_9 ( V_19 , V_21 -> V_32 , V_14 -> V_37 ) ;
} else if ( V_6 . V_9 ) {
if ( V_15 )
V_17 = F_9 ( V_19 , V_21 -> V_32 ,
V_14 -> V_37 ) ;
} else {
V_17 = F_9 ( V_19 , V_21 -> V_32 , V_14 -> V_37 ) ;
}
V_33:
return V_17 ;
}
static int F_10 ( struct V_38 * V_39 ,
union V_40 * V_41 ,
struct V_42 * V_26 ,
struct V_20 * V_21 ,
struct V_43 * V_43 )
{
struct V_4 * V_5 = F_11 ( V_39 , struct V_4 , V_39 ) ;
struct V_13 V_14 ;
struct V_11 V_12 = {
. V_21 = V_21 ,
. V_26 = V_26 ,
. V_44 = V_6 . V_44 ,
. V_45 = F_5 ,
} ;
int V_46 = 0 ;
if ( F_12 ( V_41 , V_43 , & V_14 , V_26 ) < 0 ) {
F_13 ( L_5 ,
V_41 -> V_47 . type ) ;
return - 1 ;
}
if ( V_6 . V_44 && V_14 . V_48 == NULL )
goto V_49;
if ( V_5 -> V_50 && ! F_14 ( V_26 -> V_51 , V_5 -> V_52 ) )
goto V_49;
if ( V_29 == V_30 ) {
if ( ! V_26 -> V_27 )
goto V_49;
V_12 . V_53 = & V_54 ;
} else if ( V_5 -> V_35 ) {
V_12 . V_53 = & V_55 ;
} else if ( V_6 . V_9 ) {
V_12 . V_53 = & V_56 ;
} else {
V_12 . V_53 = & V_57 ;
}
if ( V_14 . V_58 != NULL )
V_14 . V_58 -> V_59 -> V_60 = 1 ;
V_46 = F_15 ( & V_12 , & V_14 , V_5 -> V_61 , V_5 ) ;
if ( V_46 < 0 )
F_13 ( L_6 ) ;
V_49:
F_16 ( & V_14 ) ;
return V_46 ;
}
static int F_17 ( struct V_38 * V_39 ,
union V_40 * V_41 ,
struct V_42 * V_26 V_62 ,
struct V_20 * V_21 ,
struct V_43 * V_43 V_62 )
{
struct V_4 * V_5 = F_11 ( V_39 , struct V_4 , V_39 ) ;
if ( V_5 -> V_63 ) {
const char * V_64 = V_21 ? F_18 ( V_21 ) : L_7 ;
F_19 ( & V_5 -> V_65 ,
V_41 -> V_66 . V_67 , V_41 -> V_66 . V_68 ,
V_41 -> V_66 . V_69 ,
V_64 ,
V_41 -> V_66 . V_2 ) ;
}
F_20 ( L_8 V_70 L_9 , V_41 -> V_66 . V_67 , V_41 -> V_66 . V_68 ,
V_21 ? F_18 ( V_21 ) : L_10 ,
V_41 -> V_66 . V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_71 * V_72 = V_5 -> V_72 ;
T_1 V_73 = F_22 ( V_72 -> V_74 ) ;
bool V_75 = F_23 ( V_72 -> V_76 ) ;
if ( V_72 -> V_77 -> V_78 ||
( ! V_75 &&
F_24 ( & V_72 -> V_47 , V_79 ) &&
! V_72 -> V_77 -> V_80 ) )
V_73 |= V_81 ;
if ( V_72 -> V_77 -> V_82 )
V_73 |= V_83 ;
if ( ! V_75 && ! ( V_73 & V_81 ) ) {
if ( V_84 ) {
F_25 ( L_11
L_12
L_13 ) ;
return - V_85 ;
}
if ( V_6 . V_86 ) {
F_25 ( L_14
L_15
L_16 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_87 &&
V_88 . V_89 != V_90 &&
! V_6 . V_86 ) {
V_6 . V_86 = true ;
if ( F_26 ( & V_88 ) < 0 ) {
F_25 ( L_17 ) ;
return - V_85 ;
}
}
if ( V_6 . V_9 ) {
if ( ! ( V_73 & V_81 ) ) {
V_6 . V_9 = false ;
F_27 () ;
}
}
if ( V_29 == V_30 ) {
if ( ! V_75 &&
! ( V_73 & V_83 ) ) {
F_25 ( L_18
L_19 ) ;
return - 1 ;
}
}
if ( V_6 . V_86 || V_6 . V_9 ) {
if ( ( V_73 & V_91 ) &&
( V_73 & V_92 ) )
V_88 . V_93 = V_94 ;
else if ( V_73 & V_83 )
V_88 . V_93 = V_95 ;
else
V_88 . V_93 = V_96 ;
}
if ( ! ( F_28 ( V_72 -> V_74 ) &
V_97 ) )
V_5 -> V_28 = true ;
return 0 ;
}
static void F_29 ( int T_2 V_62 )
{
V_98 = 1 ;
}
static T_3 F_30 ( struct V_99 * V_99 , struct V_4 * V_5 ,
const char * V_100 , T_4 * V_101 )
{
T_3 V_46 ;
char V_102 ;
unsigned long V_103 = V_99 -> V_104 . V_105 [ V_106 ] ;
T_1 V_105 = V_99 -> V_104 . V_107 ;
struct V_20 * V_21 = F_31 ( V_99 ) ;
char V_108 [ 512 ] ;
T_3 V_109 = sizeof( V_108 ) ;
int V_110 = V_99 -> V_111 ;
if ( V_6 . V_112 ) {
V_103 = V_99 -> V_104 . V_113 ;
V_105 = V_99 -> V_104 . V_114 ;
}
if ( F_32 ( V_21 ) ) {
struct V_20 * V_115 ;
F_33 ( V_21 , V_108 , V_109 ) ;
V_100 = V_108 ;
F_34 (pos, evsel) {
const struct V_99 * V_116 = F_35 ( V_115 ) ;
if ( V_6 . V_112 ) {
V_103 += V_116 -> V_104 . V_113 ;
V_105 += V_116 -> V_104 . V_114 ;
} else {
V_103 += V_116 -> V_104 . V_105 [ V_106 ] ;
V_105 += V_116 -> V_104 . V_107 ;
}
}
}
V_103 = F_36 ( V_103 , & V_102 ) ;
V_46 = fprintf ( V_101 , L_20 , V_103 , V_102 ) ;
if ( V_100 != NULL )
V_46 += fprintf ( V_101 , L_21 , V_100 ) ;
if ( V_6 . V_117 &&
strstr ( V_100 , L_22 ) ) {
V_46 += fprintf ( V_101 , L_23 ) ;
}
if ( V_5 -> V_35 ) {
V_46 += fprintf ( V_101 , L_24 V_70 , V_105 ) ;
V_46 += fprintf ( V_101 , L_25 , V_118 ? : V_119 ) ;
} else
V_46 += fprintf ( V_101 , L_26 V_70 , V_105 ) ;
if ( V_110 > - 1 )
V_46 += fprintf ( V_101 , L_27 , V_110 ) ;
return V_46 + fprintf ( V_101 , L_28 ) ;
}
static int F_37 ( struct V_120 * V_74 ,
struct V_4 * V_5 ,
const char * V_121 )
{
struct V_20 * V_115 ;
fprintf ( stdout , L_29 V_70 L_28 , V_74 -> V_104 . V_122 ) ;
F_38 (evlist, pos) {
struct V_99 * V_99 = F_35 ( V_115 ) ;
const char * V_100 = F_18 ( V_115 ) ;
if ( V_6 . V_7 &&
! F_39 ( V_115 ) )
continue;
F_30 ( V_99 , V_5 , V_100 , stdout ) ;
F_40 ( V_99 , true , 0 , 0 , V_5 -> V_8 , stdout ) ;
fprintf ( stdout , L_30 ) ;
}
if ( V_118 == NULL &&
V_123 == V_124 )
fprintf ( stdout , L_31 , V_121 ) ;
if ( V_5 -> V_63 ) {
bool V_125 = ! strcmp ( V_5 -> V_126 , L_32 ) ;
F_41 ( stdout , & V_5 -> V_65 ,
V_125 ) ;
F_42 ( & V_5 -> V_65 ) ;
}
return 0 ;
}
static void F_43 ( const struct V_4 * V_5 )
{
struct V_58 * V_127 = F_44 ( & V_5 -> V_72 -> V_128 . V_129 ) ;
struct V_130 * V_131 = V_127 ? F_45 ( V_127 ) : NULL ;
if ( V_127 == NULL ||
( V_127 -> V_59 -> V_60 &&
( V_131 -> V_132 == NULL ||
V_131 -> V_132 -> V_37 == 0 ) ) ) {
const char * V_133 =
L_33
L_34 ;
if ( V_127 ) {
const struct V_59 * V_134 = V_127 -> V_59 ;
if ( ! F_46 ( & V_134 -> V_135 [ V_136 ] ) ) {
V_133 = L_35
L_36 ;
}
}
F_47 (
L_37
L_38
L_39 ,
V_133 ) ;
}
}
static int F_48 ( struct V_4 * V_5 , const char * V_121 )
{
int (* F_49)( struct V_120 * V_74 , const char * V_121 ,
struct V_137 * V_138 , float V_139 );
F_49 = F_50 ( V_140 , L_40 ) ;
if ( F_49 == NULL ) {
F_25 ( L_41 ) ;
return - 1 ;
}
return F_49 ( V_5 -> V_72 -> V_74 , V_121 , NULL , V_5 -> V_8 ) ;
}
static int F_51 ( struct V_4 * V_5 )
{
int V_46 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_120 * V_74 = V_72 -> V_74 ;
const char * V_121 = F_52 ( F_53 ( V_141 ) ) ;
if ( V_121 == NULL ) {
V_121 = F_52 ( V_142 ) ;
if ( V_121 == NULL )
V_121 = L_42 ;
}
switch ( V_143 ) {
case 1 :
V_46 = F_54 ( V_74 , V_121 , NULL ,
V_5 -> V_8 ,
& V_72 -> V_47 . V_144 ) ;
if ( V_46 != V_145 )
V_46 = 0 ;
break;
case 2 :
V_46 = F_48 ( V_5 , V_121 ) ;
break;
default:
V_46 = F_37 ( V_74 , V_5 , V_121 ) ;
break;
}
return V_46 ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_146 V_147 ;
struct V_20 * V_115 ;
F_56 ( & V_147 , V_5 -> V_148 , L_43 ) ;
F_38 (rep->session->evlist, pos) {
struct V_99 * V_99 = F_35 ( V_115 ) ;
if ( V_115 -> V_32 == 0 )
V_99 -> V_149 = V_5 -> V_149 ;
V_99 -> V_111 = V_5 -> V_111 ;
F_57 ( V_99 , & V_147 ) ;
if ( V_6 . V_7 &&
! F_39 ( V_115 ) ) {
struct V_99 * V_150 = F_35 ( V_115 -> V_151 ) ;
F_58 ( V_150 , V_99 ) ;
F_59 ( V_150 , V_99 ) ;
}
}
F_60 () ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_146 V_147 ;
struct V_20 * V_115 ;
F_56 ( & V_147 , V_5 -> V_148 , L_44 ) ;
F_38 (rep->session->evlist, pos)
F_62 ( F_35 ( V_115 ) , & V_147 ) ;
F_60 () ;
}
static int F_63 ( struct V_4 * V_5 )
{
int V_46 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_20 * V_115 ;
struct V_152 * V_76 = V_72 -> V_76 ;
signal ( V_153 , F_29 ) ;
if ( V_5 -> V_50 ) {
V_46 = F_64 ( V_72 , V_5 -> V_50 ,
V_5 -> V_52 ) ;
if ( V_46 ) {
F_25 ( L_45 ) ;
return V_46 ;
}
}
if ( V_5 -> V_63 )
F_65 ( & V_5 -> V_65 ) ;
V_46 = F_21 ( V_5 ) ;
if ( V_46 ) {
return V_46 ;
}
V_46 = F_66 ( V_72 ) ;
if ( V_46 ) {
F_25 ( L_46 ) ;
return V_46 ;
}
F_43 ( V_5 ) ;
F_38 (session->evlist, pos)
V_5 -> V_148 += F_35 ( V_115 ) -> V_148 ;
if ( V_143 == 0 ) {
if ( V_154 > 3 )
F_67 ( V_72 , stdout ) ;
if ( V_154 > 2 )
F_68 ( V_72 , stdout ) ;
if ( V_155 ) {
F_69 ( V_72 , stdout ) ;
F_70 ( V_72 -> V_74 , stdout ) ;
return 0 ;
}
}
F_55 ( V_5 ) ;
if ( V_98 () )
return 0 ;
V_5 -> V_148 = 0 ;
F_38 (session->evlist, pos)
V_5 -> V_148 += F_35 ( V_115 ) -> V_148 ;
if ( V_5 -> V_148 == 0 ) {
F_25 ( L_47 , V_76 -> V_156 ) ;
return 0 ;
}
F_61 ( V_5 ) ;
return F_51 ( V_5 ) ;
}
static int
F_71 ( const struct V_157 * V_158 , const char * V_16 , int V_159 )
{
struct V_4 * V_5 = (struct V_4 * ) V_158 -> V_2 ;
if ( V_159 ) {
V_5 -> V_87 = true ;
return 0 ;
}
return F_72 ( V_16 ) ;
}
int
F_73 ( const struct V_157 * V_158 V_62 ,
const char * V_16 , int V_159 V_62 )
{
if ( V_16 ) {
int V_17 = regcomp ( & V_160 , V_16 , V_161 ) ;
if ( V_17 ) {
char V_108 [ V_162 ] ;
regerror ( V_17 , & V_160 , V_108 , sizeof( V_108 ) ) ;
F_74 ( L_48 , V_16 , V_108 ) ;
return - 1 ;
}
V_163 = 1 ;
}
return 0 ;
}
static int
F_75 ( const struct V_157 * V_158 V_62 ,
const char * T_5 V_62 , int V_159 )
{
int * V_164 = V_158 -> V_2 ;
* V_164 = ! V_159 ;
return 0 ;
}
static int
F_76 ( const struct V_157 * V_158 , const char * T_5 ,
int V_159 V_62 )
{
struct V_4 * V_5 = V_158 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_77 ( int V_165 , const char * * V_166 , const char * T_6 V_62 )
{
struct V_71 * V_72 ;
struct V_77 V_77 = { . V_80 = 0 , } ;
struct V_167 V_168 ;
bool V_169 = false ;
int V_164 = - 1 ;
bool V_170 = false ;
char V_171 [] = V_172 ;
const char * const V_173 [] = {
L_49 ,
NULL
} ;
struct V_4 V_4 = {
. V_39 = {
. V_26 = F_10 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. V_178 = V_179 ,
. exit = V_180 ,
. V_181 = V_182 ,
. V_183 = V_184 ,
. V_66 = F_17 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = V_196 ,
. V_197 = true ,
. V_198 = true ,
} ,
. V_61 = V_199 ,
. V_126 = L_50 ,
. V_111 = - 1 ,
} ;
const struct V_157 V_200 [] = {
F_78 ( 'i' , L_51 , & V_201 , L_52 ,
L_53 ) ,
F_79 ( 'v' , L_54 , & V_154 ,
L_55 ) ,
F_80 ( 'D' , L_56 , & V_155 ,
L_57 ) ,
F_78 ( 'k' , L_58 , & V_6 . V_202 ,
L_52 , L_59 ) ,
F_78 ( 0 , L_60 , & V_6 . V_203 ,
L_52 , L_61 ) ,
F_80 ( 'f' , L_62 , & V_6 . V_204 , L_63 ) ,
F_80 ( 'm' , L_64 , & V_6 . V_205 ,
L_65 ) ,
F_80 ( 'n' , L_66 , & V_6 . V_206 ,
L_67 ) ,
F_80 ( 'T' , L_68 , & V_4 . V_63 ,
L_69 ) ,
F_78 ( 0 , L_70 , & V_4 . V_126 , L_71 ,
L_72 ) ,
F_80 ( 0 , L_73 , & V_4 . V_207 , L_74 ) ,
F_80 ( 0 , L_75 , & V_4 . V_208 , L_76 ) ,
F_80 ( 0 , L_77 , & V_4 . V_209 ,
L_78 ) ,
F_80 ( 0 , L_79 , & V_4 . V_47 , L_80 ) ,
F_80 ( 0 , L_81 , & V_4 . V_210 ,
L_82 ) ,
F_78 ( 's' , L_83 , & V_118 , L_84 ,
L_85
L_86 ) ,
F_78 ( 'F' , L_87 , & V_211 , L_88 ,
L_89 ) ,
F_80 ( 0 , L_90 , & V_6 . V_212 ,
L_91 ) ,
F_81 ( 0 , L_92 , & V_6 . V_212 ,
L_91 , V_213 ) ,
F_78 ( 'p' , L_93 , & V_123 , L_94 ,
L_95 ) ,
F_80 ( 'x' , L_96 , & V_6 . V_214 ,
L_97 ) ,
F_82 ( 'g' , L_98 , & V_4 ,
L_99 ,
V_215 , & F_71 ,
V_171 ) ,
F_80 ( 0 , L_100 , & V_6 . V_9 ,
L_101 ) ,
F_83 ( 0 , L_102 , & V_4 . V_61 ,
L_103
L_104
L_105 F_84 ( V_199 ) ) ,
F_80 ( 'G' , L_106 , & V_4 . V_216 ,
L_107 ) ,
F_85 ( 0 , L_108 , NULL , L_94 ,
L_109 ,
F_73 ) ,
F_78 ( 'd' , L_110 , & V_6 . V_217 , L_111 ,
L_112 ) ,
F_78 ( 'c' , L_113 , & V_6 . V_218 , L_114 ,
L_115 ) ,
F_78 ( 0 , L_116 , & V_6 . V_219 , L_117 ,
L_118 ) ,
F_78 ( 0 , L_119 , & V_6 . V_220 , L_120 ,
L_121 ) ,
F_78 ( 'S' , L_122 , & V_6 . V_221 , L_123 ,
L_124 ) ,
F_78 ( 0 , L_125 , & V_4 . V_149 , L_126 ,
L_127 ) ,
F_78 ( 'w' , L_128 , & V_6 . V_222 ,
L_129 ,
L_130 ) ,
F_86 ( 't' , L_131 , & V_6 . V_223 , L_132 ,
L_133
L_134 ) ,
F_80 ( 'U' , L_135 , & V_6 . V_44 ,
L_136 ) ,
F_78 ( 0 , L_137 , & V_6 . V_224 , L_138 ,
L_139 ) ,
F_78 ( 'C' , L_140 , & V_4 . V_50 , L_140 ,
L_141 ) ,
F_80 ( 'I' , L_142 , & V_4 . V_225 ,
L_143 ) ,
F_80 ( 0 , L_144 , & V_6 . V_226 ,
L_145 ) ,
F_80 ( 0 , L_146 , & V_6 . V_227 ,
L_147 ) ,
F_78 ( 'M' , L_148 , & V_228 , L_149 ,
L_150 ) ,
F_80 ( 0 , L_151 , & V_6 . V_229 ,
L_152 ) ,
F_80 ( 0 , L_153 , & V_6 . V_7 ,
L_154 ) ,
F_87 ( 'b' , L_155 , & V_164 , L_156 ,
L_157 ,
F_75 ) ,
F_80 ( 0 , L_158 , & V_170 ,
L_159 ) ,
F_78 ( 0 , L_160 , & V_230 , L_161 ,
L_162 ) ,
F_80 ( 0 , L_163 , & V_6 . V_231 ,
L_164 ) ,
F_80 ( 0 , L_165 , & V_6 . V_232 ,
L_166 ) ,
F_80 ( 0 , L_167 , & V_4 . V_35 , L_168 ) ,
F_85 ( 0 , L_169 , & V_4 , L_170 ,
L_171 , F_76 ) ,
F_85 ( 0 , L_172 , NULL , L_173 ,
L_174 , V_233 ) ,
F_88 ( 0 , L_175 , & V_77 , NULL , L_176 ,
L_177 ,
V_234 ) ,
F_80 ( 0 , L_178 , & V_235 ,
L_179 ) ,
F_80 ( 0 , L_180 , & V_6 . V_117 ,
L_181 ) ,
F_83 ( 0 , L_182 , & V_4 . V_111 ,
L_183 ) ,
F_80 ( 0 , L_184 , & V_6 . V_236 ,
L_185 ) ,
F_89 ()
} ;
struct V_152 V_76 = {
. V_89 = V_237 ,
} ;
int V_46 = F_90 () ;
if ( V_46 < 0 )
return V_46 ;
F_91 ( F_1 , & V_4 ) ;
V_165 = F_92 ( V_165 , V_166 , V_200 , V_173 , 0 ) ;
if ( V_165 ) {
if ( V_165 > 1 )
F_93 ( V_173 , V_200 ) ;
V_4 . V_149 = V_166 [ 0 ] ;
}
if ( V_6 . V_202 &&
F_94 ( V_6 . V_202 , V_238 ) ) {
F_74 ( L_186 , V_6 . V_202 ) ;
return - V_85 ;
}
if ( V_6 . V_203 &&
F_94 ( V_6 . V_203 , V_238 ) ) {
F_74 ( L_186 , V_6 . V_203 ) ;
return - V_85 ;
}
if ( V_4 . V_209 )
V_143 = 0 ;
else if ( V_4 . V_207 )
V_143 = 1 ;
else if ( V_4 . V_208 )
V_143 = 2 ;
if ( V_4 . V_216 )
V_88 . V_239 = V_240 ;
if ( V_6 . V_9 && ! V_88 . V_241 )
V_88 . V_239 = V_240 ;
if ( V_77 . V_78 &&
( int ) V_77 . V_242 > V_4 . V_61 )
V_4 . V_61 = V_77 . V_242 ;
if ( ! V_201 || ! strlen ( V_201 ) ) {
if ( ! F_95 ( V_243 , & V_168 ) && F_96 ( V_168 . V_244 ) )
V_201 = L_187 ;
else
V_201 = L_188 ;
}
V_76 . V_156 = V_201 ;
V_76 . V_204 = V_6 . V_204 ;
V_245:
V_72 = F_97 ( & V_76 , false , & V_4 . V_39 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_98 ( & V_72 -> V_197 ,
V_4 . V_10 ) ;
}
V_72 -> V_77 = & V_77 ;
V_4 . V_72 = V_72 ;
V_169 = F_24 ( & V_72 -> V_47 ,
V_246 ) ;
if ( V_77 . V_82 )
V_169 = true ;
if ( ( ( V_164 == - 1 && V_169 ) || V_164 == 1 ) &&
! V_170 ) {
V_29 = V_30 ;
V_6 . V_9 = false ;
}
if ( V_170 ) {
V_88 . V_247 = V_248 ;
V_88 . V_249 = 1 ;
V_6 . V_86 = true ;
F_26 ( & V_88 ) ;
if ( V_118 == NULL )
V_118 = L_189 ;
}
if ( V_4 . V_35 ) {
if ( V_29 == V_30 ) {
F_74 ( L_190 ) ;
goto error;
}
V_29 = V_250 ;
V_6 . V_9 = false ;
}
if ( F_99 ( V_72 -> V_74 ) < 0 ) {
if ( V_118 )
F_100 ( V_173 , V_200 , L_191 , 1 ) ;
if ( V_211 )
F_100 ( V_118 ? NULL : V_173 ,
V_200 , L_192 , 1 ) ;
goto error;
}
if ( V_4 . V_47 || V_4 . V_210 || V_4 . V_63 )
V_143 = 0 ;
if ( strcmp ( V_201 , L_187 ) != 0 )
F_101 ( true ) ;
else
V_143 = 0 ;
if ( V_4 . V_47 || V_4 . V_210 ) {
F_102 ( V_72 , stdout ,
V_4 . V_225 ) ;
if ( V_4 . V_210 ) {
V_46 = 0 ;
goto error;
}
} else if ( V_143 == 0 ) {
fputs ( L_193 ,
stdout ) ;
}
if ( F_6 () ) {
V_6 . V_251 = sizeof( struct V_252 ) ;
F_103 ( & V_72 -> V_128 ,
V_253 ) ;
if ( V_154 ) {
V_6 . V_251 += sizeof( V_254 ) ;
V_6 . V_255 = true ;
}
}
if ( F_104 ( & V_72 -> V_47 . V_144 ) < 0 )
goto error;
F_105 ( stdout ) ;
V_46 = F_63 ( & V_4 ) ;
if ( V_46 == V_145 ) {
F_106 ( V_72 ) ;
goto V_245;
} else
V_46 = 0 ;
error:
F_106 ( V_72 ) ;
return V_46 ;
}
