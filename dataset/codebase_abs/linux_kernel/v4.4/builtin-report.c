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
. V_44 = V_5 -> V_44 ,
. V_45 = F_5 ,
} ;
int V_46 = 0 ;
if ( F_12 ( V_41 , V_43 , & V_14 , V_26 ) < 0 ) {
F_13 ( L_5 ,
V_41 -> V_47 . type ) ;
return - 1 ;
}
if ( V_5 -> V_44 && V_14 . V_48 == NULL )
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
const char * V_121 = L_42 ;
switch ( V_141 ) {
case 1 :
V_46 = F_52 ( V_74 , V_121 , NULL ,
V_5 -> V_8 ,
& V_72 -> V_47 . V_142 ) ;
if ( V_46 != V_143 )
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
static void F_53 ( struct V_4 * V_5 )
{
struct V_144 V_145 ;
struct V_20 * V_115 ;
F_54 ( & V_145 , V_5 -> V_146 , L_43 ) ;
F_38 (rep->session->evlist, pos) {
struct V_99 * V_99 = F_35 ( V_115 ) ;
if ( V_115 -> V_32 == 0 )
V_99 -> V_147 = V_5 -> V_147 ;
V_99 -> V_111 = V_5 -> V_111 ;
F_55 ( V_99 , & V_145 ) ;
if ( V_6 . V_7 &&
! F_39 ( V_115 ) ) {
struct V_99 * V_148 = F_35 ( V_115 -> V_149 ) ;
F_56 ( V_148 , V_99 ) ;
F_57 ( V_148 , V_99 ) ;
}
}
F_58 () ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_144 V_145 ;
struct V_20 * V_115 ;
F_54 ( & V_145 , V_5 -> V_146 , L_44 ) ;
F_38 (rep->session->evlist, pos)
F_60 ( F_35 ( V_115 ) , & V_145 ) ;
F_58 () ;
}
static int F_61 ( struct V_4 * V_5 )
{
int V_46 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_20 * V_115 ;
struct V_150 * V_76 = V_72 -> V_76 ;
signal ( V_151 , F_29 ) ;
if ( V_5 -> V_50 ) {
V_46 = F_62 ( V_72 , V_5 -> V_50 ,
V_5 -> V_52 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_5 -> V_63 )
F_63 ( & V_5 -> V_65 ) ;
V_46 = F_21 ( V_5 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_64 ( V_72 ) ;
if ( V_46 )
return V_46 ;
F_43 ( V_5 ) ;
F_38 (session->evlist, pos)
V_5 -> V_146 += F_35 ( V_115 ) -> V_146 ;
if ( V_141 == 0 ) {
if ( V_152 > 3 )
F_65 ( V_72 , stdout ) ;
if ( V_152 > 2 )
F_66 ( V_72 , stdout ) ;
if ( V_153 ) {
F_67 ( V_72 , stdout ) ;
F_68 ( V_72 -> V_74 , stdout ) ;
return 0 ;
}
}
F_53 ( V_5 ) ;
if ( V_98 () )
return 0 ;
V_5 -> V_146 = 0 ;
F_38 (session->evlist, pos)
V_5 -> V_146 += F_35 ( V_115 ) -> V_146 ;
if ( V_5 -> V_146 == 0 ) {
F_25 ( L_45 , V_76 -> V_154 ) ;
return 0 ;
}
F_59 ( V_5 ) ;
return F_51 ( V_5 ) ;
}
static int
F_69 ( const struct V_155 * V_156 , const char * V_16 , int V_157 )
{
struct V_4 * V_5 = (struct V_4 * ) V_156 -> V_2 ;
if ( V_157 ) {
V_5 -> V_87 = true ;
return 0 ;
}
return F_70 ( V_16 ) ;
}
int
F_71 ( const struct V_155 * V_156 V_62 ,
const char * V_16 , int V_157 V_62 )
{
if ( V_16 ) {
int V_17 = regcomp ( & V_158 , V_16 , V_159 ) ;
if ( V_17 ) {
char V_108 [ V_160 ] ;
regerror ( V_17 , & V_158 , V_108 , sizeof( V_108 ) ) ;
F_72 ( L_46 , V_16 , V_108 ) ;
return - 1 ;
}
V_161 = 1 ;
}
return 0 ;
}
static int
F_73 ( const struct V_155 * V_156 V_62 ,
const char * T_5 V_62 , int V_157 )
{
int * V_162 = V_156 -> V_2 ;
* V_162 = ! V_157 ;
return 0 ;
}
static int
F_74 ( const struct V_155 * V_156 , const char * T_5 ,
int V_157 V_62 )
{
struct V_4 * V_5 = V_156 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_75 ( int V_163 , const char * * V_164 , const char * T_6 V_62 )
{
struct V_71 * V_72 ;
struct V_77 V_77 = { . V_80 = 0 , } ;
struct V_165 V_166 ;
bool V_167 = false ;
int V_162 = - 1 ;
bool V_168 = false ;
char V_169 [] = V_170 ;
const char * const V_171 [] = {
L_47 ,
NULL
} ;
struct V_4 V_4 = {
. V_39 = {
. V_26 = F_10 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. exit = V_178 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. V_66 = F_17 ,
. V_183 = V_184 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = true ,
. V_196 = true ,
} ,
. V_61 = V_197 ,
. V_126 = L_48 ,
. V_111 = - 1 ,
} ;
const struct V_155 V_198 [] = {
F_76 ( 'i' , L_49 , & V_199 , L_50 ,
L_51 ) ,
F_77 ( 'v' , L_52 , & V_152 ,
L_53 ) ,
F_78 ( 'D' , L_54 , & V_153 ,
L_55 ) ,
F_76 ( 'k' , L_56 , & V_6 . V_200 ,
L_50 , L_57 ) ,
F_76 ( 0 , L_58 , & V_6 . V_201 ,
L_50 , L_59 ) ,
F_78 ( 'f' , L_60 , & V_6 . V_202 , L_61 ) ,
F_78 ( 'm' , L_62 , & V_6 . V_203 ,
L_63 ) ,
F_78 ( 'n' , L_64 , & V_6 . V_204 ,
L_65 ) ,
F_78 ( 'T' , L_66 , & V_4 . V_63 ,
L_67 ) ,
F_76 ( 0 , L_68 , & V_4 . V_126 , L_69 ,
L_70 ) ,
F_78 ( 0 , L_71 , & V_4 . V_205 , L_72 ) ,
F_78 ( 0 , L_73 , & V_4 . V_206 , L_74 ) ,
F_78 ( 0 , L_75 , & V_4 . V_207 ,
L_76 ) ,
F_78 ( 0 , L_77 , & V_4 . V_47 , L_78 ) ,
F_78 ( 0 , L_79 , & V_4 . V_208 ,
L_80 ) ,
F_76 ( 's' , L_81 , & V_118 , L_82 ,
L_83
L_84 ) ,
F_76 ( 'F' , L_85 , & V_209 , L_86 ,
L_87 ) ,
F_78 ( 0 , L_88 , & V_6 . V_210 ,
L_89 ) ,
F_79 ( 0 , L_90 , & V_6 . V_210 ,
L_89 , V_211 ) ,
F_76 ( 'p' , L_91 , & V_123 , L_92 ,
L_93 ) ,
F_78 ( 'x' , L_94 , & V_6 . V_212 ,
L_95 ) ,
F_80 ( 'g' , L_96 , & V_4 ,
L_97 ,
V_213 , & F_69 ,
V_169 ) ,
F_78 ( 0 , L_98 , & V_6 . V_9 ,
L_99 ) ,
F_81 ( 0 , L_100 , & V_4 . V_61 ,
L_101
L_102
L_103 F_82 ( V_197 ) ) ,
F_78 ( 'G' , L_104 , & V_4 . V_214 ,
L_105 ) ,
F_83 ( 0 , L_106 , NULL , L_92 ,
L_107 ,
F_71 ) ,
F_76 ( 'd' , L_108 , & V_6 . V_215 , L_109 ,
L_110 ) ,
F_76 ( 'c' , L_111 , & V_6 . V_216 , L_112 ,
L_113 ) ,
F_76 ( 0 , L_114 , & V_6 . V_217 , L_115 ,
L_116 ) ,
F_76 ( 0 , L_117 , & V_6 . V_218 , L_118 ,
L_119 ) ,
F_76 ( 'S' , L_120 , & V_6 . V_219 , L_121 ,
L_122 ) ,
F_76 ( 0 , L_123 , & V_4 . V_147 , L_124 ,
L_125 ) ,
F_76 ( 'w' , L_126 , & V_6 . V_220 ,
L_127 ,
L_128 ) ,
F_84 ( 't' , L_129 , & V_6 . V_221 , L_130 ,
L_131
L_132 ) ,
F_78 ( 'U' , L_133 , & V_4 . V_44 ,
L_134 ) ,
F_76 ( 0 , L_135 , & V_6 . V_222 , L_136 ,
L_137 ) ,
F_76 ( 'C' , L_138 , & V_4 . V_50 , L_138 ,
L_139 ) ,
F_78 ( 'I' , L_140 , & V_4 . V_223 ,
L_141 ) ,
F_78 ( 0 , L_142 , & V_6 . V_224 ,
L_143 ) ,
F_78 ( 0 , L_144 , & V_6 . V_225 ,
L_145 ) ,
F_76 ( 'M' , L_146 , & V_226 , L_147 ,
L_148 ) ,
F_78 ( 0 , L_149 , & V_6 . V_227 ,
L_150 ) ,
F_78 ( 0 , L_151 , & V_6 . V_7 ,
L_152 ) ,
F_85 ( 'b' , L_153 , & V_162 , L_154 ,
L_155 ,
F_73 ) ,
F_78 ( 0 , L_156 , & V_168 ,
L_157 ) ,
F_76 ( 0 , L_158 , & V_228 , L_159 ,
L_160 ) ,
F_78 ( 0 , L_161 , & V_6 . V_229 ,
L_162 ) ,
F_78 ( 0 , L_163 , & V_6 . V_230 ,
L_164 ) ,
F_78 ( 0 , L_165 , & V_4 . V_35 , L_166 ) ,
F_83 ( 0 , L_167 , & V_4 , L_168 ,
L_169 , F_74 ) ,
F_83 ( 0 , L_170 , NULL , L_171 ,
L_172 , V_231 ) ,
F_86 ( 0 , L_173 , & V_77 , NULL , L_174 ,
L_175 ,
V_232 ) ,
F_78 ( 0 , L_176 , & V_233 ,
L_177 ) ,
F_78 ( 0 , L_178 , & V_6 . V_117 ,
L_179 ) ,
F_81 ( 0 , L_180 , & V_4 . V_111 ,
L_181 ) ,
F_87 ()
} ;
struct V_150 V_76 = {
. V_89 = V_234 ,
} ;
int V_46 = F_88 () ;
if ( V_46 < 0 )
return V_46 ;
F_89 ( F_1 , & V_4 ) ;
V_163 = F_90 ( V_163 , V_164 , V_198 , V_171 , 0 ) ;
if ( V_6 . V_200 &&
F_91 ( V_6 . V_200 , V_235 ) ) {
F_72 ( L_182 , V_6 . V_200 ) ;
return - V_85 ;
}
if ( V_6 . V_201 &&
F_91 ( V_6 . V_201 , V_235 ) ) {
F_72 ( L_182 , V_6 . V_201 ) ;
return - V_85 ;
}
if ( V_4 . V_207 )
V_141 = 0 ;
else if ( V_4 . V_205 )
V_141 = 1 ;
else if ( V_4 . V_206 )
V_141 = 2 ;
if ( V_4 . V_214 )
V_88 . V_236 = V_237 ;
if ( V_6 . V_9 && ! V_88 . V_238 )
V_88 . V_236 = V_237 ;
if ( V_77 . V_78 &&
( int ) V_77 . V_239 > V_4 . V_61 )
V_4 . V_61 = V_77 . V_239 ;
if ( ! V_199 || ! strlen ( V_199 ) ) {
if ( ! F_92 ( V_240 , & V_166 ) && F_93 ( V_166 . V_241 ) )
V_199 = L_183 ;
else
V_199 = L_184 ;
}
V_76 . V_154 = V_199 ;
V_76 . V_202 = V_6 . V_202 ;
V_242:
V_72 = F_94 ( & V_76 , false , & V_4 . V_39 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_95 ( & V_72 -> V_195 ,
V_4 . V_10 ) ;
}
V_72 -> V_77 = & V_77 ;
V_4 . V_72 = V_72 ;
V_167 = F_24 ( & V_72 -> V_47 ,
V_243 ) ;
if ( V_77 . V_82 )
V_167 = true ;
if ( ( ( V_162 == - 1 && V_167 ) || V_162 == 1 ) &&
! V_168 ) {
V_29 = V_30 ;
V_6 . V_9 = false ;
}
if ( V_168 ) {
V_88 . V_244 = V_245 ;
V_88 . V_246 = 1 ;
V_6 . V_86 = true ;
F_26 ( & V_88 ) ;
if ( V_118 == NULL )
V_118 = L_185 ;
}
if ( V_4 . V_35 ) {
if ( V_29 == V_30 ) {
F_72 ( L_186 ) ;
goto error;
}
V_29 = V_247 ;
V_6 . V_9 = false ;
}
if ( F_96 () < 0 ) {
if ( V_118 )
F_97 ( V_171 , V_198 , L_187 , 1 ) ;
if ( V_209 )
F_97 ( V_118 ? NULL : V_171 ,
V_198 , L_188 , 1 ) ;
goto error;
}
if ( V_4 . V_47 || V_4 . V_208 || V_4 . V_63 )
V_141 = 0 ;
if ( strcmp ( V_199 , L_183 ) != 0 )
F_98 ( true ) ;
else
V_141 = 0 ;
if ( V_4 . V_47 || V_4 . V_208 ) {
F_99 ( V_72 , stdout ,
V_4 . V_223 ) ;
if ( V_4 . V_208 ) {
V_46 = 0 ;
goto error;
}
} else if ( V_141 == 0 ) {
fputs ( L_189 ,
stdout ) ;
}
if ( F_6 () ) {
V_6 . V_248 = sizeof( struct V_249 ) ;
F_100 ( & V_72 -> V_128 ,
V_250 ) ;
if ( V_152 ) {
V_6 . V_248 += sizeof( V_251 ) ;
V_6 . V_252 = true ;
}
}
if ( F_101 ( & V_72 -> V_47 . V_142 ) < 0 )
goto error;
if ( V_163 ) {
if ( V_163 > 1 )
F_102 ( V_171 , V_198 ) ;
V_4 . V_147 = V_164 [ 0 ] ;
}
F_103 ( stdout ) ;
V_46 = F_61 ( & V_4 ) ;
if ( V_46 == V_143 ) {
F_104 ( V_72 ) ;
goto V_242;
} else
V_46 = 0 ;
error:
F_104 ( V_72 ) ;
return V_46 ;
}
