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
if ( V_29 == V_30 )
V_12 . V_53 = & V_54 ;
else if ( V_5 -> V_35 )
V_12 . V_53 = & V_55 ;
else if ( V_6 . V_9 )
V_12 . V_53 = & V_56 ;
else
V_12 . V_53 = & V_57 ;
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
if ( ! V_75 && ! ( V_73 & V_77 ) ) {
if ( V_78 ) {
F_24 ( L_11
L_12
L_13 ) ;
return - V_79 ;
}
if ( V_6 . V_80 ) {
F_24 ( L_14
L_15
L_16 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_81 &&
V_82 . V_83 != V_84 &&
! V_6 . V_80 ) {
V_6 . V_80 = true ;
if ( F_25 ( & V_82 ) < 0 ) {
F_24 ( L_17 ) ;
return - V_79 ;
}
}
if ( V_6 . V_9 ) {
if ( ! ( V_73 & V_77 ) ) {
V_6 . V_9 = false ;
F_26 () ;
}
}
if ( V_29 == V_30 ) {
if ( ! V_75 &&
! ( V_73 & V_85 ) ) {
F_24 ( L_18
L_19 ) ;
return - 1 ;
}
}
if ( V_6 . V_80 || V_6 . V_9 ) {
if ( ( V_73 & V_86 ) &&
( V_73 & V_87 ) )
V_82 . V_88 = V_89 ;
else if ( V_73 & V_85 )
V_82 . V_88 = V_90 ;
else
V_82 . V_88 = V_91 ;
}
if ( ! ( F_27 ( V_72 -> V_74 ) &
V_92 ) )
V_5 -> V_28 = true ;
return 0 ;
}
static void F_28 ( int T_2 V_62 )
{
V_93 = 1 ;
}
static T_3 F_29 ( struct V_94 * V_94 , struct V_4 * V_5 ,
const char * V_95 , T_4 * V_96 )
{
T_3 V_46 ;
char V_97 ;
unsigned long V_98 = V_94 -> V_99 . V_100 [ V_101 ] ;
T_1 V_100 = V_94 -> V_99 . V_102 ;
struct V_20 * V_21 = F_30 ( V_94 ) ;
char V_103 [ 512 ] ;
T_3 V_104 = sizeof( V_103 ) ;
if ( V_6 . V_105 ) {
V_98 = V_94 -> V_99 . V_106 ;
V_100 = V_94 -> V_99 . V_107 ;
}
if ( F_31 ( V_21 ) ) {
struct V_20 * V_108 ;
F_32 ( V_21 , V_103 , V_104 ) ;
V_95 = V_103 ;
F_33 (pos, evsel) {
const struct V_94 * V_109 = F_34 ( V_108 ) ;
if ( V_6 . V_105 ) {
V_98 += V_109 -> V_99 . V_106 ;
V_100 += V_109 -> V_99 . V_107 ;
} else {
V_98 += V_109 -> V_99 . V_100 [ V_101 ] ;
V_100 += V_109 -> V_99 . V_102 ;
}
}
}
V_98 = F_35 ( V_98 , & V_97 ) ;
V_46 = fprintf ( V_96 , L_20 , V_98 , V_97 ) ;
if ( V_95 != NULL )
V_46 += fprintf ( V_96 , L_21 , V_95 ) ;
if ( V_6 . V_110 &&
strstr ( V_95 , L_22 ) ) {
V_46 += fprintf ( V_96 , L_23 ) ;
}
if ( V_5 -> V_35 ) {
V_46 += fprintf ( V_96 , L_24 V_70 , V_100 ) ;
V_46 += fprintf ( V_96 , L_25 , V_111 ? : V_112 ) ;
} else
V_46 += fprintf ( V_96 , L_26 V_70 , V_100 ) ;
return V_46 + fprintf ( V_96 , L_27 ) ;
}
static int F_36 ( struct V_113 * V_74 ,
struct V_4 * V_5 ,
const char * V_114 )
{
struct V_20 * V_108 ;
fprintf ( stdout , L_28 V_70 L_27 , V_74 -> V_99 . V_115 ) ;
F_37 (evlist, pos) {
struct V_94 * V_94 = F_34 ( V_108 ) ;
const char * V_95 = F_18 ( V_108 ) ;
if ( V_6 . V_7 &&
! F_38 ( V_108 ) )
continue;
F_29 ( V_94 , V_5 , V_95 , stdout ) ;
F_39 ( V_94 , true , 0 , 0 , V_5 -> V_8 , stdout ) ;
fprintf ( stdout , L_29 ) ;
}
if ( V_111 == NULL &&
V_116 == V_117 )
fprintf ( stdout , L_30 , V_114 ) ;
if ( V_5 -> V_63 ) {
bool V_118 = ! strcmp ( V_5 -> V_119 , L_31 ) ;
F_40 ( stdout , & V_5 -> V_65 ,
V_118 ) ;
F_41 ( & V_5 -> V_65 ) ;
}
return 0 ;
}
static void F_42 ( const struct V_4 * V_5 )
{
struct V_58 * V_120 = V_5 -> V_72 -> V_121 . V_122 . V_123 [ V_124 ] ;
struct V_125 * V_126 = V_120 ? F_43 ( V_120 ) : NULL ;
if ( V_120 == NULL ||
( V_120 -> V_59 -> V_60 &&
( V_126 -> V_127 == NULL ||
V_126 -> V_127 -> V_37 == 0 ) ) ) {
const char * V_128 =
L_32
L_33 ;
if ( V_120 ) {
const struct V_59 * V_129 = V_120 -> V_59 ;
if ( ! F_44 ( & V_129 -> V_130 [ V_124 ] ) ) {
V_128 = L_34
L_35 ;
}
}
F_45 (
L_36
L_37
L_38 ,
V_128 ) ;
}
}
static int F_46 ( struct V_4 * V_5 , const char * V_114 )
{
int (* F_47)( struct V_113 * V_74 , const char * V_114 ,
struct V_131 * V_132 , float V_133 );
F_47 = F_48 ( V_134 , L_39 ) ;
if ( F_47 == NULL ) {
F_24 ( L_40 ) ;
return - 1 ;
}
return F_47 ( V_5 -> V_72 -> V_74 , V_114 , NULL , V_5 -> V_8 ) ;
}
static int F_49 ( struct V_4 * V_5 )
{
int V_46 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_113 * V_74 = V_72 -> V_74 ;
const char * V_114 = L_41 ;
switch ( V_135 ) {
case 1 :
V_46 = F_50 ( V_74 , V_114 , NULL ,
V_5 -> V_8 ,
& V_72 -> V_47 . V_136 ) ;
if ( V_46 != V_137 )
V_46 = 0 ;
break;
case 2 :
V_46 = F_46 ( V_5 , V_114 ) ;
break;
default:
V_46 = F_36 ( V_74 , V_5 , V_114 ) ;
break;
}
return V_46 ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_138 V_139 ;
struct V_20 * V_108 ;
F_52 ( & V_139 , V_5 -> V_140 , L_42 ) ;
F_37 (rep->session->evlist, pos) {
struct V_94 * V_94 = F_34 ( V_108 ) ;
if ( V_108 -> V_32 == 0 )
V_94 -> V_141 = V_5 -> V_141 ;
F_53 ( V_94 , & V_139 ) ;
if ( V_6 . V_7 &&
! F_38 ( V_108 ) ) {
struct V_94 * V_142 = F_34 ( V_108 -> V_143 ) ;
F_54 ( V_142 , V_94 ) ;
F_55 ( V_142 , V_94 ) ;
}
}
F_56 () ;
}
static void F_57 ( struct V_4 * V_5 )
{
struct V_138 V_139 ;
struct V_20 * V_108 ;
F_52 ( & V_139 , V_5 -> V_140 , L_43 ) ;
F_37 (rep->session->evlist, pos)
F_58 ( F_34 ( V_108 ) , & V_139 ) ;
F_56 () ;
}
static int F_59 ( struct V_4 * V_5 )
{
int V_46 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_20 * V_108 ;
struct V_144 * V_76 = V_72 -> V_76 ;
signal ( V_145 , F_28 ) ;
if ( V_5 -> V_50 ) {
V_46 = F_60 ( V_72 , V_5 -> V_50 ,
V_5 -> V_52 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_5 -> V_63 )
F_61 ( & V_5 -> V_65 ) ;
V_46 = F_21 ( V_5 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_62 ( V_72 ) ;
if ( V_46 )
return V_46 ;
F_42 ( V_5 ) ;
F_37 (session->evlist, pos)
V_5 -> V_140 += F_34 ( V_108 ) -> V_140 ;
if ( V_135 == 0 ) {
if ( V_146 > 3 )
F_63 ( V_72 , stdout ) ;
if ( V_146 > 2 )
F_64 ( V_72 , stdout ) ;
if ( V_147 ) {
F_65 ( V_72 , stdout ) ;
F_66 ( V_72 -> V_74 , stdout ) ;
return 0 ;
}
}
F_51 ( V_5 ) ;
if ( V_93 () )
return 0 ;
V_5 -> V_140 = 0 ;
F_37 (session->evlist, pos)
V_5 -> V_140 += F_34 ( V_108 ) -> V_140 ;
if ( V_5 -> V_140 == 0 ) {
F_24 ( L_44 , V_76 -> V_148 ) ;
return 0 ;
}
F_57 ( V_5 ) ;
return F_49 ( V_5 ) ;
}
static int
F_67 ( const struct V_149 * V_150 , const char * V_16 , int V_151 )
{
struct V_4 * V_5 = (struct V_4 * ) V_150 -> V_2 ;
if ( V_151 ) {
V_5 -> V_81 = true ;
return 0 ;
}
return F_68 ( V_16 ) ;
}
int
F_69 ( const struct V_149 * V_150 V_62 ,
const char * V_16 , int V_151 V_62 )
{
if ( V_16 ) {
int V_17 = regcomp ( & V_152 , V_16 , V_153 ) ;
if ( V_17 ) {
char V_103 [ V_154 ] ;
regerror ( V_17 , & V_152 , V_103 , sizeof( V_103 ) ) ;
F_70 ( L_45 , V_16 , V_103 ) ;
return - 1 ;
}
V_155 = 1 ;
}
return 0 ;
}
static int
F_71 ( const struct V_149 * V_150 V_62 ,
const char * T_5 V_62 , int V_151 )
{
int * V_156 = V_150 -> V_2 ;
* V_156 = ! V_151 ;
return 0 ;
}
static int
F_72 ( const struct V_149 * V_150 , const char * T_5 ,
int V_151 V_62 )
{
struct V_4 * V_5 = V_150 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_73 ( int V_157 , const char * * V_158 , const char * T_6 V_62 )
{
struct V_71 * V_72 ;
struct V_159 V_159 = { . V_160 = 0 , } ;
struct V_161 V_162 ;
bool V_163 = false ;
int V_156 = - 1 ;
bool V_164 = false ;
char V_165 [] = L_46 ;
const char * const V_166 [] = {
L_47 ,
NULL
} ;
struct V_4 V_4 = {
. V_39 = {
. V_26 = F_10 ,
. V_167 = V_168 ,
. V_169 = V_170 ,
. V_171 = V_172 ,
. exit = V_173 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. V_66 = F_17 ,
. V_178 = V_179 ,
. V_180 = V_181 ,
. V_182 = V_183 ,
. V_184 = V_185 ,
. V_186 = V_187 ,
. V_188 = V_189 ,
. V_190 = true ,
. V_191 = true ,
} ,
. V_61 = V_192 ,
. V_119 = L_48 ,
} ;
const struct V_149 V_193 [] = {
F_74 ( 'i' , L_49 , & V_194 , L_50 ,
L_51 ) ,
F_75 ( 'v' , L_52 , & V_146 ,
L_53 ) ,
F_76 ( 'D' , L_54 , & V_147 ,
L_55 ) ,
F_74 ( 'k' , L_56 , & V_6 . V_195 ,
L_50 , L_57 ) ,
F_74 ( 0 , L_58 , & V_6 . V_196 ,
L_50 , L_59 ) ,
F_76 ( 'f' , L_60 , & V_4 . V_197 , L_61 ) ,
F_76 ( 'm' , L_62 , & V_6 . V_198 ,
L_63 ) ,
F_76 ( 'n' , L_64 , & V_6 . V_199 ,
L_65 ) ,
F_76 ( 'T' , L_66 , & V_4 . V_63 ,
L_67 ) ,
F_74 ( 0 , L_68 , & V_4 . V_119 , L_69 ,
L_70 ) ,
F_76 ( 0 , L_71 , & V_4 . V_200 , L_72 ) ,
F_76 ( 0 , L_73 , & V_4 . V_201 , L_74 ) ,
F_76 ( 0 , L_75 , & V_4 . V_202 ,
L_76 ) ,
F_76 ( 0 , L_77 , & V_4 . V_47 , L_78 ) ,
F_76 ( 0 , L_79 , & V_4 . V_203 ,
L_80 ) ,
F_74 ( 's' , L_81 , & V_111 , L_82 ,
L_83
L_84 ) ,
F_74 ( 'F' , L_85 , & V_204 , L_86 ,
L_87 ) ,
F_76 ( 0 , L_88 , & V_6 . V_205 ,
L_89 ) ,
F_74 ( 'p' , L_90 , & V_116 , L_91 ,
L_92 ) ,
F_76 ( 'x' , L_93 , & V_6 . V_206 ,
L_94 ) ,
F_77 ( 'g' , L_95 , & V_4 , L_96 ,
L_97
L_98 , & F_67 , V_165 ) ,
F_76 ( 0 , L_99 , & V_6 . V_9 ,
L_100 ) ,
F_78 ( 0 , L_101 , & V_4 . V_61 ,
L_102
L_103
L_104 F_79 ( V_192 ) ) ,
F_76 ( 'G' , L_105 , & V_4 . V_207 ,
L_106 ) ,
F_80 ( 0 , L_107 , NULL , L_91 ,
L_108 ,
F_69 ) ,
F_74 ( 'd' , L_109 , & V_6 . V_208 , L_110 ,
L_111 ) ,
F_74 ( 'c' , L_112 , & V_6 . V_209 , L_113 ,
L_114 ) ,
F_74 ( 0 , L_115 , & V_6 . V_210 , L_116 ,
L_117 ) ,
F_74 ( 0 , L_118 , & V_6 . V_211 , L_119 ,
L_120 ) ,
F_74 ( 'S' , L_121 , & V_6 . V_212 , L_122 ,
L_123 ) ,
F_74 ( 0 , L_124 , & V_4 . V_141 , L_125 ,
L_126 ) ,
F_74 ( 'w' , L_127 , & V_6 . V_213 ,
L_128 ,
L_129 ) ,
F_81 ( 't' , L_130 , & V_6 . V_214 , L_131 ,
L_132
L_133 ) ,
F_76 ( 'U' , L_134 , & V_4 . V_44 ,
L_135 ) ,
F_74 ( 0 , L_136 , & V_6 . V_215 , L_137 ,
L_138 ) ,
F_74 ( 'C' , L_139 , & V_4 . V_50 , L_139 ,
L_140 ) ,
F_76 ( 'I' , L_141 , & V_4 . V_216 ,
L_142 ) ,
F_76 ( 0 , L_143 , & V_6 . V_217 ,
L_144 ) ,
F_76 ( 0 , L_145 , & V_6 . V_218 ,
L_146 ) ,
F_74 ( 'M' , L_147 , & V_219 , L_148 ,
L_149 ) ,
F_76 ( 0 , L_150 , & V_6 . V_220 ,
L_151 ) ,
F_76 ( 0 , L_152 , & V_6 . V_7 ,
L_153 ) ,
F_82 ( 'b' , L_154 , & V_156 , L_155 ,
L_156 ,
F_71 ) ,
F_76 ( 0 , L_157 , & V_164 ,
L_158 ) ,
F_74 ( 0 , L_159 , & V_221 , L_160 ,
L_161 ) ,
F_76 ( 0 , L_162 , & V_6 . V_222 ,
L_163 ) ,
F_76 ( 0 , L_164 , & V_6 . V_223 ,
L_165 ) ,
F_76 ( 0 , L_166 , & V_4 . V_35 , L_167 ) ,
F_80 ( 0 , L_168 , & V_4 , L_169 ,
L_170 , F_72 ) ,
F_80 ( 0 , L_171 , NULL , L_172 ,
L_173 , V_224 ) ,
F_83 ( 0 , L_174 , & V_159 , NULL , L_175 ,
L_176 ,
V_225 ) ,
F_76 ( 0 , L_177 , & V_226 ,
L_178 ) ,
F_76 ( 0 , L_179 , & V_6 . V_110 ,
L_180 ) ,
F_84 ()
} ;
struct V_144 V_76 = {
. V_83 = V_227 ,
} ;
int V_46 = F_85 () ;
if ( V_46 < 0 )
return V_46 ;
F_86 ( F_1 , & V_4 ) ;
V_157 = F_87 ( V_157 , V_158 , V_193 , V_166 , 0 ) ;
if ( V_6 . V_195 &&
F_88 ( V_6 . V_195 , V_228 ) ) {
F_70 ( L_181 , V_6 . V_195 ) ;
return - V_79 ;
}
if ( V_6 . V_196 &&
F_88 ( V_6 . V_196 , V_228 ) ) {
F_70 ( L_181 , V_6 . V_196 ) ;
return - V_79 ;
}
if ( V_4 . V_202 )
V_135 = 0 ;
else if ( V_4 . V_200 )
V_135 = 1 ;
else if ( V_4 . V_201 )
V_135 = 2 ;
if ( V_4 . V_207 )
V_82 . V_229 = V_230 ;
if ( ! V_194 || ! strlen ( V_194 ) ) {
if ( ! F_89 ( V_231 , & V_162 ) && F_90 ( V_162 . V_232 ) )
V_194 = L_182 ;
else
V_194 = L_183 ;
}
V_76 . V_148 = V_194 ;
V_76 . V_197 = V_4 . V_197 ;
V_233:
V_72 = F_91 ( & V_76 , false , & V_4 . V_39 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_92 ( & V_72 -> V_190 ,
V_4 . V_10 ) ;
}
V_72 -> V_159 = & V_159 ;
V_4 . V_72 = V_72 ;
V_163 = F_93 ( & V_72 -> V_47 ,
V_234 ) ;
if ( ( ( V_156 == - 1 && V_163 ) || V_156 == 1 ) &&
! V_164 ) {
V_29 = V_30 ;
V_6 . V_9 = false ;
}
if ( V_164 ) {
V_82 . V_235 = V_236 ;
V_82 . V_237 = 1 ;
V_6 . V_80 = true ;
F_25 ( & V_82 ) ;
if ( V_111 == NULL )
V_111 = L_184 ;
}
if ( V_4 . V_35 ) {
if ( V_29 == V_30 ) {
F_70 ( L_185 ) ;
goto error;
}
V_29 = V_238 ;
V_6 . V_9 = false ;
}
if ( F_94 () < 0 ) {
if ( V_111 )
F_95 ( V_166 , V_193 , L_186 , 1 ) ;
if ( V_204 )
F_95 ( V_111 ? NULL : V_166 ,
V_193 , L_187 , 1 ) ;
goto error;
}
if ( V_4 . V_47 || V_4 . V_203 || V_4 . V_63 )
V_135 = 0 ;
if ( strcmp ( V_194 , L_182 ) != 0 )
F_96 ( true ) ;
else
V_135 = 0 ;
if ( V_4 . V_47 || V_4 . V_203 ) {
F_97 ( V_72 , stdout ,
V_4 . V_216 ) ;
if ( V_4 . V_203 ) {
V_46 = 0 ;
goto error;
}
} else if ( V_135 == 0 ) {
fputs ( L_188 ,
stdout ) ;
}
if ( F_6 () ) {
V_6 . V_239 = sizeof( struct V_240 ) ;
F_98 ( & V_72 -> V_121 ,
V_241 ) ;
if ( V_146 ) {
V_6 . V_239 += sizeof( V_242 ) ;
V_6 . V_243 = true ;
}
}
if ( F_99 ( & V_72 -> V_47 . V_136 ) < 0 )
goto error;
if ( V_157 ) {
if ( V_157 > 1 )
F_100 ( V_166 , V_193 ) ;
V_4 . V_141 = V_158 [ 0 ] ;
}
F_101 ( stdout ) ;
V_46 = F_59 ( & V_4 ) ;
if ( V_46 == V_137 ) {
F_102 ( V_72 ) ;
goto V_233;
} else
V_46 = 0 ;
error:
F_102 ( V_72 ) ;
return V_46 ;
}
