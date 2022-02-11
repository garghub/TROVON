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
if ( F_12 ( & V_5 -> V_50 , V_29 -> time ) )
return 0 ;
if ( F_13 ( V_46 , & V_17 , V_29 ) < 0 ) {
F_14 ( L_6 ,
V_44 -> V_51 . type ) ;
return - 1 ;
}
if ( V_6 . V_47 && V_17 . V_52 == NULL )
goto V_53;
if ( V_5 -> V_54 && ! F_15 ( V_29 -> V_55 , V_5 -> V_56 ) )
goto V_53;
if ( V_32 == V_33 ) {
if ( ! V_29 -> V_30 )
goto V_53;
V_15 . V_57 = & V_58 ;
} else if ( V_5 -> V_38 ) {
V_15 . V_57 = & V_59 ;
} else if ( V_6 . V_11 ) {
V_15 . V_57 = & V_60 ;
} else {
V_15 . V_57 = & V_61 ;
}
if ( V_17 . V_62 != NULL )
V_17 . V_62 -> V_63 -> V_64 = 1 ;
V_49 = F_16 ( & V_15 , & V_17 , V_5 -> V_65 , V_5 ) ;
if ( V_49 < 0 )
F_14 ( L_7 ) ;
V_53:
F_17 ( & V_17 ) ;
return V_49 ;
}
static int F_18 ( struct V_41 * V_42 ,
union V_43 * V_44 ,
struct V_45 * V_29 V_66 ,
struct V_23 * V_24 ,
struct V_46 * V_46 V_66 )
{
struct V_4 * V_5 = F_11 ( V_42 , struct V_4 , V_42 ) ;
if ( V_5 -> V_67 ) {
const char * V_68 = V_24 ? F_19 ( V_24 ) : L_8 ;
int V_20 = F_20 ( & V_5 -> V_69 ,
V_44 -> V_70 . V_71 , V_44 -> V_70 . V_72 ,
V_44 -> V_70 . V_73 ,
V_68 ,
V_44 -> V_70 . V_2 ) ;
if ( V_20 )
return V_20 ;
}
F_21 ( L_9 V_74 L_10 , V_44 -> V_70 . V_71 , V_44 -> V_70 . V_72 ,
V_24 ? F_19 ( V_24 ) : L_11 ,
V_44 -> V_70 . V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_75 * V_76 = V_5 -> V_76 ;
T_1 V_77 = F_23 ( V_76 -> V_78 ) ;
bool V_79 = F_24 ( V_76 -> V_80 ) ;
if ( V_76 -> V_81 -> V_82 ||
( ! V_79 &&
F_25 ( & V_76 -> V_51 , V_83 ) &&
! V_76 -> V_81 -> V_84 ) )
V_77 |= V_85 ;
if ( V_76 -> V_81 -> V_86 )
V_77 |= V_87 ;
if ( ! V_79 && ! ( V_77 & V_85 ) ) {
if ( V_88 . V_89 ) {
F_26 ( L_12
L_13
L_14 ) ;
return - V_90 ;
}
if ( V_6 . V_91 ) {
F_26 ( L_15
L_16
L_17 ) ;
return - 1 ;
}
} else if ( ! V_10 . V_92 &&
V_10 . V_93 != V_94 &&
! V_6 . V_91 ) {
V_6 . V_91 = true ;
if ( F_27 ( & V_10 ) < 0 ) {
F_26 ( L_18 ) ;
return - V_90 ;
}
}
if ( V_6 . V_11 ) {
if ( ! ( V_77 & V_85 ) ) {
V_6 . V_11 = false ;
F_28 () ;
}
}
if ( V_32 == V_33 ) {
if ( ! V_79 &&
! ( V_77 & V_87 ) ) {
F_26 ( L_19
L_20 ) ;
return - 1 ;
}
}
if ( V_6 . V_91 || V_6 . V_11 ) {
if ( ( V_77 & V_95 ) &&
( V_77 & V_96 ) )
V_10 . V_97 = V_98 ;
else if ( V_77 & V_87 )
V_10 . V_97 = V_99 ;
else
V_10 . V_97 = V_100 ;
}
if ( ! ( F_29 ( V_76 -> V_78 ) &
V_101 ) )
V_5 -> V_31 = true ;
return 0 ;
}
static void F_30 ( int T_2 V_66 )
{
V_102 = 1 ;
}
static T_3 F_31 ( struct V_103 * V_103 , struct V_4 * V_5 ,
const char * V_104 , T_4 * V_105 )
{
T_3 V_49 ;
char V_106 ;
unsigned long V_107 = V_103 -> V_108 . V_109 [ V_110 ] ;
T_1 V_109 = V_103 -> V_108 . V_111 ;
struct V_23 * V_24 = F_32 ( V_103 ) ;
char V_112 [ 512 ] ;
T_3 V_113 = sizeof( V_112 ) ;
int V_114 = V_103 -> V_115 ;
if ( V_6 . V_116 ) {
V_107 = V_103 -> V_108 . V_117 ;
V_109 = V_103 -> V_108 . V_118 ;
}
if ( F_33 ( V_24 ) ) {
struct V_23 * V_119 ;
F_34 ( V_24 , V_112 , V_113 ) ;
V_104 = V_112 ;
F_35 (pos, evsel) {
const struct V_103 * V_120 = F_36 ( V_119 ) ;
if ( V_6 . V_116 ) {
V_107 += V_120 -> V_108 . V_117 ;
V_109 += V_120 -> V_108 . V_118 ;
} else {
V_107 += V_120 -> V_108 . V_109 [ V_110 ] ;
V_109 += V_120 -> V_108 . V_111 ;
}
}
}
V_107 = F_37 ( V_107 , & V_106 ) ;
V_49 = fprintf ( V_105 , L_21 , V_107 , V_106 ) ;
if ( V_104 != NULL )
V_49 += fprintf ( V_105 , L_22 , V_104 ) ;
if ( V_6 . V_121 &&
strstr ( V_104 , L_23 ) ) {
V_49 += fprintf ( V_105 , L_24 ) ;
}
if ( V_5 -> V_38 ) {
V_49 += fprintf ( V_105 , L_25 V_74 , V_109 ) ;
V_49 += fprintf ( V_105 , L_26 , V_122 ? : V_123 ) ;
} else
V_49 += fprintf ( V_105 , L_27 V_74 , V_109 ) ;
if ( V_114 > - 1 )
V_49 += fprintf ( V_105 , L_28 , V_114 ) ;
return V_49 + fprintf ( V_105 , L_29 ) ;
}
static int F_38 ( struct V_124 * V_78 ,
struct V_4 * V_5 ,
const char * V_125 )
{
struct V_23 * V_119 ;
fprintf ( stdout , L_30 V_74 L_29 , V_78 -> V_108 . V_126 ) ;
F_39 (evlist, pos) {
struct V_103 * V_103 = F_36 ( V_119 ) ;
const char * V_104 = F_19 ( V_119 ) ;
if ( V_6 . V_7 &&
! F_40 ( V_119 ) )
continue;
F_31 ( V_103 , V_5 , V_104 , stdout ) ;
F_41 ( V_103 , true , 0 , 0 , V_5 -> V_9 , stdout ,
V_6 . V_91 ) ;
fprintf ( stdout , L_31 ) ;
}
if ( V_122 == NULL &&
V_127 == V_128 )
fprintf ( stdout , L_32 , V_125 ) ;
if ( V_5 -> V_67 ) {
bool V_129 = ! strcmp ( V_5 -> V_130 , L_33 ) ;
F_42 ( stdout , & V_5 -> V_69 ,
V_129 ) ;
F_43 ( & V_5 -> V_69 ) ;
}
return 0 ;
}
static void F_44 ( const struct V_4 * V_5 )
{
struct V_62 * V_131 = F_45 ( & V_5 -> V_76 -> V_132 . V_133 ) ;
struct V_134 * V_135 = V_131 ? F_46 ( V_131 ) : NULL ;
if ( V_131 == NULL ||
( V_131 -> V_63 -> V_64 &&
( V_135 -> V_136 == NULL ||
V_135 -> V_136 -> V_40 == 0 ) ) ) {
const char * V_137 =
L_34
L_35 ;
if ( V_131 ) {
const struct V_63 * V_138 = V_131 -> V_63 ;
if ( ! F_47 ( & V_138 -> V_139 [ V_140 ] ) ) {
V_137 = L_36
L_37 ;
}
}
F_48 (
L_38
L_39
L_40 ,
V_137 ) ;
}
}
static int F_49 ( struct V_4 * V_5 , const char * V_125 )
{
int (* F_50)( struct V_124 * V_78 , const char * V_125 ,
struct V_141 * V_142 , float V_143 );
F_50 = F_51 ( V_144 , L_41 ) ;
if ( F_50 == NULL ) {
F_26 ( L_42 ) ;
return - 1 ;
}
return F_50 ( V_5 -> V_76 -> V_78 , V_125 , NULL , V_5 -> V_9 ) ;
}
static int F_52 ( struct V_4 * V_5 )
{
int V_49 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_124 * V_78 = V_76 -> V_78 ;
const char * V_125 = F_53 ( F_54 ( V_145 ) ) ;
if ( V_125 == NULL ) {
V_125 = F_53 ( V_146 ) ;
if ( V_125 == NULL )
V_125 = L_43 ;
}
switch ( V_147 ) {
case 1 :
V_49 = F_55 ( V_78 , V_125 , NULL ,
V_5 -> V_9 ,
& V_76 -> V_51 . V_148 ) ;
if ( V_49 != V_149 )
V_49 = 0 ;
break;
case 2 :
V_49 = F_49 ( V_5 , V_125 ) ;
break;
default:
V_49 = F_38 ( V_78 , V_5 , V_125 ) ;
break;
}
return V_49 ;
}
static int F_56 ( struct V_4 * V_5 )
{
struct V_150 V_151 ;
struct V_23 * V_119 ;
int V_49 = 0 ;
F_57 ( & V_151 , V_5 -> V_152 , L_44 ) ;
F_39 (rep->session->evlist, pos) {
struct V_103 * V_103 = F_36 ( V_119 ) ;
if ( V_119 -> V_35 == 0 )
V_103 -> V_153 = V_5 -> V_153 ;
V_103 -> V_115 = V_5 -> V_115 ;
V_49 = F_58 ( V_103 , & V_151 ) ;
if ( V_49 < 0 )
break;
if ( V_6 . V_7 &&
! F_40 ( V_119 ) ) {
struct V_103 * V_154 = F_36 ( V_119 -> V_155 ) ;
F_59 ( V_154 , V_103 ) ;
F_60 ( V_154 , V_103 ) ;
}
}
F_61 () ;
return V_49 ;
}
static void F_62 ( struct V_4 * V_5 )
{
struct V_150 V_151 ;
struct V_23 * V_119 ;
F_57 ( & V_151 , V_5 -> V_152 , L_45 ) ;
F_39 (rep->session->evlist, pos)
F_63 ( V_119 , & V_151 ) ;
F_61 () ;
}
static int F_64 ( struct V_4 * V_5 )
{
int V_49 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_23 * V_119 ;
struct V_156 * V_80 = V_76 -> V_80 ;
signal ( V_157 , F_30 ) ;
if ( V_5 -> V_54 ) {
V_49 = F_65 ( V_76 , V_5 -> V_54 ,
V_5 -> V_56 ) ;
if ( V_49 ) {
F_26 ( L_46 ) ;
return V_49 ;
}
}
if ( V_5 -> V_67 ) {
V_49 = F_66 ( & V_5 -> V_69 ) ;
if ( V_49 )
return V_49 ;
}
V_49 = F_22 ( V_5 ) ;
if ( V_49 ) {
return V_49 ;
}
V_49 = F_67 ( V_76 ) ;
if ( V_49 ) {
F_26 ( L_47 ) ;
return V_49 ;
}
F_44 ( V_5 ) ;
F_39 (session->evlist, pos)
V_5 -> V_152 += F_36 ( V_119 ) -> V_152 ;
if ( V_147 == 0 ) {
if ( V_158 > 3 )
F_68 ( V_76 , stdout ) ;
if ( V_158 > 2 )
F_69 ( V_76 , stdout ) ;
if ( V_159 ) {
F_70 ( V_76 , stdout ) ;
F_71 ( V_76 -> V_78 , stdout ) ;
return 0 ;
}
}
V_49 = F_56 ( V_5 ) ;
if ( V_49 ) {
F_26 ( L_48 ) ;
return V_49 ;
}
if ( V_102 () )
return 0 ;
V_5 -> V_152 = 0 ;
F_39 (session->evlist, pos)
V_5 -> V_152 += F_36 ( V_119 ) -> V_152 ;
if ( V_5 -> V_152 == 0 ) {
F_26 ( L_49 , V_80 -> V_160 ) ;
return 0 ;
}
F_62 ( V_5 ) ;
return F_52 ( V_5 ) ;
}
static int
F_72 ( const struct V_161 * V_162 , const char * V_19 , int V_163 )
{
struct V_10 * V_82 = V_162 -> V_2 ;
V_82 -> V_92 = ! V_163 ;
if ( V_163 ) {
V_6 . V_91 = false ;
V_82 -> V_93 = V_94 ;
return 0 ;
}
return F_73 ( V_19 ) ;
}
int
F_74 ( const struct V_161 * V_162 V_66 ,
const char * V_19 , int V_163 V_66 )
{
if ( V_19 ) {
int V_20 = regcomp ( & V_164 , V_19 , V_165 ) ;
if ( V_20 ) {
char V_112 [ V_166 ] ;
regerror ( V_20 , & V_164 , V_112 , sizeof( V_112 ) ) ;
F_75 ( L_50 , V_19 , V_112 ) ;
return - 1 ;
}
V_167 = 1 ;
}
return 0 ;
}
static int
F_76 ( const struct V_161 * V_162 ,
const char * T_5 V_66 , int V_163 )
{
int * V_168 = V_162 -> V_2 ;
* V_168 = ! V_163 ;
return 0 ;
}
static int
F_77 ( const struct V_161 * V_162 , const char * T_5 ,
int V_163 V_66 )
{
struct V_4 * V_5 = V_162 -> V_2 ;
double V_8 = strtof ( T_5 , NULL ) ;
V_5 -> V_9 = V_8 ;
V_10 . V_9 = V_8 ;
return 0 ;
}
int F_78 ( int V_169 , const char * * V_170 , const char * T_6 V_66 )
{
struct V_75 * V_76 ;
struct V_81 V_81 = { . V_84 = 0 , } ;
struct V_171 V_172 ;
bool V_173 = false ;
int V_168 = - 1 ;
bool V_174 = false ;
char V_175 [] = V_176 ;
const char * const V_177 [] = {
L_51 ,
NULL
} ;
struct V_4 V_4 = {
. V_42 = {
. V_29 = F_10 ,
. V_178 = V_179 ,
. V_180 = V_181 ,
. V_182 = V_183 ,
. exit = V_184 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
. V_70 = F_18 ,
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = V_196 ,
. V_197 = V_198 ,
. V_199 = V_200 ,
. V_201 = true ,
. V_202 = true ,
} ,
. V_65 = V_203 ,
. V_130 = L_52 ,
. V_115 = - 1 ,
} ;
const struct V_161 V_204 [] = {
F_79 ( 'i' , L_53 , & V_205 , L_54 ,
L_55 ) ,
F_80 ( 'v' , L_56 , & V_158 ,
L_57 ) ,
F_81 ( 'D' , L_58 , & V_159 ,
L_59 ) ,
F_79 ( 'k' , L_60 , & V_6 . V_206 ,
L_54 , L_61 ) ,
F_79 ( 0 , L_62 , & V_6 . V_207 ,
L_54 , L_63 ) ,
F_81 ( 'f' , L_64 , & V_6 . V_208 , L_65 ) ,
F_81 ( 'm' , L_66 , & V_6 . V_209 ,
L_67 ) ,
F_81 ( 'n' , L_68 , & V_6 . V_210 ,
L_69 ) ,
F_81 ( 'T' , L_70 , & V_4 . V_67 ,
L_71 ) ,
F_79 ( 0 , L_72 , & V_4 . V_130 , L_73 ,
L_74 ) ,
F_81 ( 0 , L_75 , & V_4 . V_211 , L_76 ) ,
F_81 ( 0 , L_77 , & V_4 . V_212 , L_78 ) ,
F_81 ( 0 , L_79 , & V_4 . V_213 ,
L_80 ) ,
F_81 ( 0 , L_81 , & V_4 . V_51 , L_82 ) ,
F_81 ( 0 , L_83 , & V_4 . V_214 ,
L_84 ) ,
F_79 ( 's' , L_85 , & V_122 , L_86 ,
L_87
L_88 ) ,
F_79 ( 'F' , L_89 , & V_215 , L_90 ,
L_91 ) ,
F_81 ( 0 , L_92 , & V_6 . V_216 ,
L_93 ) ,
F_82 ( 0 , L_94 , & V_6 . V_216 ,
L_93 , V_217 ) ,
F_79 ( 'p' , L_95 , & V_127 , L_96 ,
L_97 ) ,
F_81 ( 'x' , L_98 , & V_6 . V_218 ,
L_99 ) ,
F_83 ( 'g' , L_100 , & V_10 ,
L_101 ,
V_219 , & F_72 ,
V_175 ) ,
F_81 ( 0 , L_102 , & V_6 . V_11 ,
L_103 ) ,
F_84 ( 0 , L_104 , & V_4 . V_65 ,
L_105
L_106
L_107 F_85 ( V_203 ) ) ,
F_81 ( 'G' , L_108 , & V_4 . V_220 ,
L_109 ) ,
F_86 ( 0 , L_110 , NULL , L_96 ,
L_111 ,
F_74 ) ,
F_79 ( 'd' , L_112 , & V_6 . V_221 , L_113 ,
L_114 ) ,
F_79 ( 'c' , L_115 , & V_6 . V_222 , L_116 ,
L_117 ) ,
F_79 ( 0 , L_118 , & V_6 . V_223 , L_119 ,
L_120 ) ,
F_79 ( 0 , L_121 , & V_6 . V_224 , L_122 ,
L_123 ) ,
F_79 ( 'S' , L_124 , & V_6 . V_225 , L_125 ,
L_126 ) ,
F_79 ( 0 , L_127 , & V_4 . V_153 , L_128 ,
L_129 ) ,
F_79 ( 'w' , L_130 , & V_6 . V_226 ,
L_131 ,
L_132 ) ,
F_87 ( 't' , L_133 , & V_6 . V_227 , L_134 ,
L_135
L_136 ) ,
F_81 ( 'U' , L_137 , & V_6 . V_47 ,
L_138 ) ,
F_86 ( 0 , L_139 , NULL , L_140 ,
L_141 ,
V_228 ) ,
F_79 ( 'C' , L_142 , & V_4 . V_54 , L_142 ,
L_143 ) ,
F_81 ( 'I' , L_144 , & V_4 . V_229 ,
L_145 ) ,
F_81 ( 0 , L_146 , & V_6 . V_230 ,
L_147 ) ,
F_81 ( 0 , L_148 , & V_6 . V_231 ,
L_149 ) ,
F_79 ( 'M' , L_150 , & V_232 , L_151 ,
L_152 ) ,
F_81 ( 0 , L_153 , & V_6 . V_233 ,
L_154 ) ,
F_81 ( 0 , L_155 , & V_6 . V_7 ,
L_156 ) ,
F_88 ( 'b' , L_157 , & V_168 , L_158 ,
L_159 ,
F_76 ) ,
F_81 ( 0 , L_160 , & V_174 ,
L_161 ) ,
F_79 ( 0 , L_162 , & V_234 , L_163 ,
L_164 ) ,
F_81 ( 0 , L_165 , & V_6 . V_235 ,
L_166 ) ,
F_81 ( 0 , L_167 , & V_6 . V_236 ,
L_168 ) ,
F_81 ( 0 , L_169 , & V_4 . V_38 , L_170 ) ,
F_86 ( 0 , L_171 , & V_4 , L_172 ,
L_173 , F_77 ) ,
F_86 ( 0 , L_174 , NULL , L_175 ,
L_176 , V_237 ) ,
F_89 ( 0 , L_177 , & V_81 , NULL , L_178 ,
L_179 ,
V_238 ) ,
F_81 ( 0 , L_180 , & V_239 ,
L_181 ) ,
F_81 ( 0 , L_182 , & V_6 . V_121 ,
L_183 ) ,
F_84 ( 0 , L_184 , & V_4 . V_115 ,
L_185 ) ,
F_81 ( 0 , L_186 , & V_6 . V_240 ,
L_187 ) ,
F_81 ( 0 , L_188 , & V_6 . V_241 ,
L_189 ) ,
F_83 ( 0 , L_190 , NULL , L_191 ,
L_192 ,
V_242 , L_193 ) ,
F_79 ( 0 , L_194 , & V_4 . V_243 , L_195 ,
L_196 ) ,
F_90 ()
} ;
struct V_156 V_80 = {
. V_93 = V_244 ,
} ;
int V_49 = F_91 () ;
if ( V_49 < 0 )
return V_49 ;
F_92 ( F_1 , & V_4 ) ;
V_169 = F_93 ( V_169 , V_170 , V_204 , V_177 , 0 ) ;
if ( V_169 ) {
if ( V_169 > 1 )
F_94 ( V_177 , V_204 ) ;
V_4 . V_153 = V_170 [ 0 ] ;
}
if ( V_6 . V_206 &&
F_95 ( V_6 . V_206 , V_245 ) ) {
F_75 ( L_197 , V_6 . V_206 ) ;
return - V_90 ;
}
if ( V_6 . V_207 &&
F_95 ( V_6 . V_207 , V_245 ) ) {
F_75 ( L_197 , V_6 . V_207 ) ;
return - V_90 ;
}
if ( V_4 . V_213 )
V_147 = 0 ;
else if ( V_4 . V_211 )
V_147 = 1 ;
else if ( V_4 . V_212 )
V_147 = 2 ;
if ( V_4 . V_220 )
V_10 . V_246 = V_247 ;
if ( V_6 . V_11 && ! V_10 . V_248 )
V_10 . V_246 = V_247 ;
if ( V_81 . V_82 &&
( int ) V_81 . V_249 > V_4 . V_65 )
V_4 . V_65 = V_81 . V_249 ;
if ( ! V_205 || ! strlen ( V_205 ) ) {
if ( ! F_96 ( V_250 , & V_172 ) && F_97 ( V_172 . V_251 ) )
V_205 = L_198 ;
else
V_205 = L_199 ;
}
V_80 . V_160 = V_205 ;
V_80 . V_208 = V_6 . V_208 ;
V_252:
V_76 = F_98 ( & V_80 , false , & V_4 . V_42 ) ;
if ( V_76 == NULL )
return - 1 ;
if ( V_4 . V_12 ) {
F_99 ( & V_76 -> V_201 ,
V_4 . V_12 ) ;
}
V_76 -> V_81 = & V_81 ;
V_4 . V_76 = V_76 ;
V_173 = F_25 ( & V_76 -> V_51 ,
V_253 ) ;
if ( V_81 . V_86 )
V_173 = true ;
if ( V_173 && V_174 )
V_6 . V_254 = true ;
if ( ( ( V_168 == - 1 && V_173 ) || V_168 == 1 ) &&
! V_174 ) {
V_32 = V_33 ;
V_6 . V_11 = false ;
}
if ( V_174 ) {
V_10 . V_255 = V_256 ;
V_10 . V_257 = 1 ;
V_6 . V_91 = true ;
F_27 ( & V_10 ) ;
if ( V_122 == NULL )
V_122 = L_200 ;
}
if ( V_4 . V_38 ) {
if ( V_32 == V_33 ) {
F_75 ( L_201 ) ;
goto error;
}
V_32 = V_258 ;
V_6 . V_11 = false ;
}
if ( V_6 . V_241 ) {
V_6 . V_11 = false ;
if ( V_215 ) {
F_75 ( L_202 ) ;
F_100 ( V_177 , V_204 , L_203 , 1 ) ;
F_100 ( NULL , V_204 , L_188 , 0 ) ;
goto error;
}
V_88 . V_259 = true ;
}
if ( V_4 . V_51 || V_4 . V_214 || V_4 . V_67 )
V_147 = 0 ;
if ( strcmp ( V_205 , L_198 ) != 0 )
F_101 ( true ) ;
else
V_147 = 0 ;
if ( F_102 ( V_76 -> V_78 ) < 0 ) {
if ( V_122 )
F_100 ( V_177 , V_204 , L_204 , 1 ) ;
if ( V_215 )
F_100 ( V_122 ? NULL : V_177 ,
V_204 , L_203 , 1 ) ;
goto error;
}
if ( V_4 . V_51 || V_4 . V_214 ) {
F_103 ( V_76 , stdout ,
V_4 . V_229 ) ;
if ( V_4 . V_214 ) {
V_49 = 0 ;
goto error;
}
} else if ( V_147 == 0 ) {
fputs ( L_205 ,
stdout ) ;
}
if ( F_6 () ) {
V_49 = F_104 () ;
if ( V_49 < 0 )
goto error;
if ( V_158 ) {
V_6 . V_260 += sizeof( V_261 ) ;
V_6 . V_262 = true ;
}
}
if ( F_105 ( & V_76 -> V_51 . V_148 ) < 0 )
goto error;
if ( F_106 ( & V_4 . V_50 , V_4 . V_243 ) != 0 ) {
F_75 ( L_206 ) ;
return - V_90 ;
}
F_107 ( stdout ) ;
V_49 = F_64 ( & V_4 ) ;
if ( V_49 == V_149 ) {
F_108 ( V_76 ) ;
goto V_252;
} else
V_49 = 0 ;
error:
F_108 ( V_76 ) ;
return V_49 ;
}
