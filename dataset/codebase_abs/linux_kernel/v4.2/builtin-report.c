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
if ( V_26 == V_27 ) {
V_25 = V_19 -> V_24 ;
V_17 = F_7 ( & V_25 -> V_28 , V_21 -> V_29 ) ;
if ( V_17 )
goto V_30;
V_17 = F_7 ( & V_25 -> V_31 , V_21 -> V_29 ) ;
} else if ( V_5 -> V_32 ) {
V_23 = V_19 -> V_22 ;
V_17 = F_7 ( & V_23 -> V_33 , V_21 -> V_29 ) ;
if ( V_17 )
goto V_30;
V_17 = F_8 ( V_19 , V_21 -> V_29 , V_14 -> V_34 ) ;
} else if ( V_6 . V_9 ) {
if ( V_15 )
V_17 = F_8 ( V_19 , V_21 -> V_29 ,
V_14 -> V_34 ) ;
} else {
V_17 = F_8 ( V_19 , V_21 -> V_29 , V_14 -> V_34 ) ;
}
V_30:
return V_17 ;
}
static int F_9 ( struct V_35 * V_36 ,
union V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_20 * V_21 ,
struct V_41 * V_41 )
{
struct V_4 * V_5 = F_10 ( V_36 , struct V_4 , V_36 ) ;
struct V_13 V_14 ;
struct V_11 V_12 = {
. V_21 = V_21 ,
. V_40 = V_40 ,
. V_42 = V_5 -> V_42 ,
. V_43 = F_5 ,
} ;
int V_44 = 0 ;
if ( F_11 ( V_38 , V_41 , & V_14 , V_40 ) < 0 ) {
F_12 ( L_5 ,
V_38 -> V_45 . type ) ;
return - 1 ;
}
if ( V_5 -> V_42 && V_14 . V_46 == NULL )
goto V_47;
if ( V_5 -> V_48 && ! F_13 ( V_40 -> V_49 , V_5 -> V_50 ) )
goto V_47;
if ( V_26 == V_27 )
V_12 . V_51 = & V_52 ;
else if ( V_5 -> V_32 )
V_12 . V_51 = & V_53 ;
else if ( V_6 . V_9 )
V_12 . V_51 = & V_54 ;
else
V_12 . V_51 = & V_55 ;
if ( V_14 . V_56 != NULL )
V_14 . V_56 -> V_57 -> V_58 = 1 ;
V_44 = F_14 ( & V_12 , & V_14 , V_5 -> V_59 , V_5 ) ;
if ( V_44 < 0 )
F_12 ( L_6 ) ;
V_47:
F_15 ( & V_14 ) ;
return V_44 ;
}
static int F_16 ( struct V_35 * V_36 ,
union V_37 * V_38 ,
struct V_39 * V_40 V_60 ,
struct V_20 * V_21 ,
struct V_41 * V_41 V_60 )
{
struct V_4 * V_5 = F_10 ( V_36 , struct V_4 , V_36 ) ;
if ( V_5 -> V_61 ) {
const char * V_62 = V_21 ? F_17 ( V_21 ) : L_7 ;
F_18 ( & V_5 -> V_63 ,
V_38 -> V_64 . V_65 , V_38 -> V_64 . V_66 ,
V_38 -> V_64 . V_67 ,
V_62 ,
V_38 -> V_64 . V_2 ) ;
}
F_19 ( L_8 V_68 L_9 , V_38 -> V_64 . V_65 , V_38 -> V_64 . V_66 ,
V_21 ? F_17 ( V_21 ) : L_10 ,
V_38 -> V_64 . V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_69 * V_70 = V_5 -> V_70 ;
T_1 V_71 = F_21 ( V_70 -> V_72 ) ;
bool V_73 = F_22 ( V_70 -> V_74 ) ;
if ( ! V_73 && ! ( V_71 & V_75 ) ) {
if ( V_76 ) {
F_23 ( L_11
L_12
L_13 ) ;
return - V_77 ;
}
if ( V_6 . V_78 ) {
F_23 ( L_14
L_15
L_16 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_79 &&
V_80 . V_81 != V_82 &&
! V_6 . V_78 ) {
V_6 . V_78 = true ;
if ( F_24 ( & V_80 ) < 0 ) {
F_23 ( L_17 ) ;
return - V_77 ;
}
}
if ( V_6 . V_9 ) {
if ( ! ( V_71 & V_75 ) ) {
V_6 . V_9 = false ;
F_25 () ;
}
}
if ( V_26 == V_27 ) {
if ( ! V_73 &&
! ( V_71 & V_83 ) ) {
F_23 ( L_18
L_19 ) ;
return - 1 ;
}
}
if ( V_6 . V_78 || V_6 . V_9 ) {
if ( ( V_71 & V_84 ) &&
( V_71 & V_85 ) )
V_80 . V_86 = V_87 ;
else if ( V_71 & V_83 )
V_80 . V_86 = V_88 ;
else
V_80 . V_86 = V_89 ;
}
return 0 ;
}
static void F_26 ( int T_2 V_60 )
{
V_90 = 1 ;
}
static T_3 F_27 ( struct V_91 * V_91 , struct V_4 * V_5 ,
const char * V_92 , T_4 * V_93 )
{
T_3 V_44 ;
char V_94 ;
unsigned long V_95 = V_91 -> V_96 . V_97 [ V_98 ] ;
T_1 V_97 = V_91 -> V_96 . V_99 ;
struct V_20 * V_21 = F_28 ( V_91 ) ;
char V_100 [ 512 ] ;
T_3 V_101 = sizeof( V_100 ) ;
if ( V_6 . V_102 ) {
V_95 = V_91 -> V_96 . V_103 ;
V_97 = V_91 -> V_96 . V_104 ;
}
if ( F_29 ( V_21 ) ) {
struct V_20 * V_105 ;
F_30 ( V_21 , V_100 , V_101 ) ;
V_92 = V_100 ;
F_31 (pos, evsel) {
const struct V_91 * V_106 = F_32 ( V_105 ) ;
if ( V_6 . V_102 ) {
V_95 += V_106 -> V_96 . V_103 ;
V_97 += V_106 -> V_96 . V_104 ;
} else {
V_95 += V_106 -> V_96 . V_97 [ V_98 ] ;
V_97 += V_106 -> V_96 . V_99 ;
}
}
}
V_95 = F_33 ( V_95 , & V_94 ) ;
V_44 = fprintf ( V_93 , L_20 , V_95 , V_94 ) ;
if ( V_92 != NULL )
V_44 += fprintf ( V_93 , L_21 , V_92 ) ;
if ( V_5 -> V_32 ) {
V_44 += fprintf ( V_93 , L_22 V_68 , V_97 ) ;
V_44 += fprintf ( V_93 , L_23 , V_107 ? : V_108 ) ;
} else
V_44 += fprintf ( V_93 , L_24 V_68 , V_97 ) ;
return V_44 + fprintf ( V_93 , L_25 ) ;
}
static int F_34 ( struct V_109 * V_72 ,
struct V_4 * V_5 ,
const char * V_110 )
{
struct V_20 * V_105 ;
fprintf ( stdout , L_26 V_68 L_25 , V_72 -> V_96 . V_111 ) ;
F_35 (evlist, pos) {
struct V_91 * V_91 = F_32 ( V_105 ) ;
const char * V_92 = F_17 ( V_105 ) ;
if ( V_6 . V_7 &&
! F_36 ( V_105 ) )
continue;
F_27 ( V_91 , V_5 , V_92 , stdout ) ;
F_37 ( V_91 , true , 0 , 0 , V_5 -> V_8 , stdout ) ;
fprintf ( stdout , L_27 ) ;
}
if ( V_107 == NULL &&
V_112 == V_113 )
fprintf ( stdout , L_28 , V_110 ) ;
if ( V_5 -> V_61 ) {
bool V_114 = ! strcmp ( V_5 -> V_115 , L_29 ) ;
F_38 ( stdout , & V_5 -> V_63 ,
V_114 ) ;
F_39 ( & V_5 -> V_63 ) ;
}
return 0 ;
}
static void F_40 ( const struct V_4 * V_5 )
{
struct V_56 * V_116 = V_5 -> V_70 -> V_117 . V_118 . V_119 [ V_120 ] ;
struct V_121 * V_122 = V_116 ? F_41 ( V_116 ) : NULL ;
if ( V_116 == NULL ||
( V_116 -> V_57 -> V_58 &&
( V_122 -> V_123 == NULL ||
V_122 -> V_123 -> V_34 == 0 ) ) ) {
const char * V_124 =
L_30
L_31 ;
if ( V_116 ) {
const struct V_57 * V_125 = V_116 -> V_57 ;
if ( ! F_42 ( & V_125 -> V_126 [ V_120 ] ) ) {
V_124 = L_32
L_33 ;
}
}
F_43 (
L_34
L_35
L_36 ,
V_124 ) ;
}
}
static int F_44 ( struct V_4 * V_5 , const char * V_110 )
{
int (* F_45)( struct V_109 * V_72 , const char * V_110 ,
struct V_127 * V_128 , float V_129 );
F_45 = F_46 ( V_130 , L_37 ) ;
if ( F_45 == NULL ) {
F_23 ( L_38 ) ;
return - 1 ;
}
return F_45 ( V_5 -> V_70 -> V_72 , V_110 , NULL , V_5 -> V_8 ) ;
}
static int F_47 ( struct V_4 * V_5 )
{
int V_44 ;
struct V_69 * V_70 = V_5 -> V_70 ;
struct V_109 * V_72 = V_70 -> V_72 ;
const char * V_110 = L_39 ;
switch ( V_131 ) {
case 1 :
V_44 = F_48 ( V_72 , V_110 , NULL ,
V_5 -> V_8 ,
& V_70 -> V_45 . V_132 ) ;
if ( V_44 != V_133 )
V_44 = 0 ;
break;
case 2 :
V_44 = F_44 ( V_5 , V_110 ) ;
break;
default:
V_44 = F_34 ( V_72 , V_5 , V_110 ) ;
break;
}
return V_44 ;
}
static void F_49 ( struct V_4 * V_5 )
{
struct V_134 V_135 ;
struct V_20 * V_105 ;
F_50 ( & V_135 , V_5 -> V_136 , L_40 ) ;
F_35 (rep->session->evlist, pos) {
struct V_91 * V_91 = F_32 ( V_105 ) ;
if ( V_105 -> V_29 == 0 )
V_91 -> V_137 = V_5 -> V_137 ;
F_51 ( V_91 , & V_135 ) ;
if ( V_6 . V_7 &&
! F_36 ( V_105 ) ) {
struct V_91 * V_138 = F_32 ( V_105 -> V_139 ) ;
F_52 ( V_138 , V_91 ) ;
F_53 ( V_138 , V_91 ) ;
}
}
F_54 () ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_134 V_135 ;
struct V_20 * V_105 ;
F_50 ( & V_135 , V_5 -> V_136 , L_41 ) ;
F_35 (rep->session->evlist, pos)
F_56 ( F_32 ( V_105 ) , & V_135 ) ;
F_54 () ;
}
static int F_57 ( struct V_4 * V_5 )
{
int V_44 ;
struct V_69 * V_70 = V_5 -> V_70 ;
struct V_20 * V_105 ;
struct V_140 * V_74 = V_70 -> V_74 ;
signal ( V_141 , F_26 ) ;
if ( V_5 -> V_48 ) {
V_44 = F_58 ( V_70 , V_5 -> V_48 ,
V_5 -> V_50 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_5 -> V_61 )
F_59 ( & V_5 -> V_63 ) ;
V_44 = F_20 ( V_5 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_60 ( V_70 ) ;
if ( V_44 )
return V_44 ;
F_40 ( V_5 ) ;
F_35 (session->evlist, pos)
V_5 -> V_136 += F_32 ( V_105 ) -> V_136 ;
if ( V_131 == 0 ) {
if ( V_142 > 3 )
F_61 ( V_70 , stdout ) ;
if ( V_142 > 2 )
F_62 ( V_70 , stdout ) ;
if ( V_143 ) {
F_63 ( V_70 , stdout ) ;
F_64 ( V_70 -> V_72 , stdout ) ;
return 0 ;
}
}
F_49 ( V_5 ) ;
if ( V_90 () )
return 0 ;
V_5 -> V_136 = 0 ;
F_35 (session->evlist, pos)
V_5 -> V_136 += F_32 ( V_105 ) -> V_136 ;
if ( V_5 -> V_136 == 0 ) {
F_23 ( L_42 , V_74 -> V_144 ) ;
return 0 ;
}
F_55 ( V_5 ) ;
return F_47 ( V_5 ) ;
}
static int
F_65 ( const struct V_145 * V_146 , const char * V_16 , int V_147 )
{
struct V_4 * V_5 = (struct V_4 * ) V_146 -> V_2 ;
if ( V_147 ) {
V_5 -> V_79 = true ;
return 0 ;
}
return F_66 ( V_16 ) ;
}
int
F_67 ( const struct V_145 * V_146 V_60 ,
const char * V_16 , int V_147 V_60 )
{
if ( V_16 ) {
int V_17 = regcomp ( & V_148 , V_16 , V_149 ) ;
if ( V_17 ) {
char V_100 [ V_150 ] ;
regerror ( V_17 , & V_148 , V_100 , sizeof( V_100 ) ) ;
F_68 ( L_43 , V_16 , V_100 ) ;
return - 1 ;
}
V_151 = 1 ;
}
return 0 ;
}
static int
F_69 ( const struct V_145 * V_146 V_60 ,
const char * T_5 V_60 , int V_147 )
{
int * V_152 = V_146 -> V_2 ;
* V_152 = ! V_147 ;
return 0 ;
}
static int
F_70 ( const struct V_145 * V_146 , const char * T_5 ,
int V_147 V_60 )
{
struct V_4 * V_5 = V_146 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_71 ( int V_153 , const char * * V_154 , const char * T_6 V_60 )
{
struct V_69 * V_70 ;
struct V_155 V_155 = { . V_156 = 0 , } ;
struct V_157 V_158 ;
bool V_159 = false ;
int V_152 = - 1 ;
bool V_160 = false ;
char V_161 [] = L_44 ;
const char * const V_162 [] = {
L_45 ,
NULL
} ;
struct V_4 V_4 = {
. V_36 = {
. V_40 = F_9 ,
. V_163 = V_164 ,
. V_165 = V_166 ,
. V_167 = V_168 ,
. exit = V_169 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_64 = F_16 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. V_178 = V_179 ,
. V_180 = V_181 ,
. V_182 = V_183 ,
. V_184 = V_185 ,
. V_186 = true ,
. V_187 = true ,
} ,
. V_59 = V_188 ,
. V_115 = L_46 ,
} ;
const struct V_145 V_189 [] = {
F_72 ( 'i' , L_47 , & V_190 , L_48 ,
L_49 ) ,
F_73 ( 'v' , L_50 , & V_142 ,
L_51 ) ,
F_74 ( 'D' , L_52 , & V_143 ,
L_53 ) ,
F_72 ( 'k' , L_54 , & V_6 . V_191 ,
L_48 , L_55 ) ,
F_72 ( 0 , L_56 , & V_6 . V_192 ,
L_48 , L_57 ) ,
F_74 ( 'f' , L_58 , & V_4 . V_193 , L_59 ) ,
F_74 ( 'm' , L_60 , & V_6 . V_194 ,
L_61 ) ,
F_74 ( 'n' , L_62 , & V_6 . V_195 ,
L_63 ) ,
F_74 ( 'T' , L_64 , & V_4 . V_61 ,
L_65 ) ,
F_72 ( 0 , L_66 , & V_4 . V_115 , L_67 ,
L_68 ) ,
F_74 ( 0 , L_69 , & V_4 . V_196 , L_70 ) ,
F_74 ( 0 , L_71 , & V_4 . V_197 , L_72 ) ,
F_74 ( 0 , L_73 , & V_4 . V_198 ,
L_74 ) ,
F_74 ( 0 , L_75 , & V_4 . V_45 , L_76 ) ,
F_74 ( 0 , L_77 , & V_4 . V_199 ,
L_78 ) ,
F_72 ( 's' , L_79 , & V_107 , L_80 ,
L_81
L_82 ) ,
F_72 ( 'F' , L_83 , & V_200 , L_84 ,
L_85 ) ,
F_74 ( 0 , L_86 , & V_6 . V_201 ,
L_87 ) ,
F_72 ( 'p' , L_88 , & V_112 , L_89 ,
L_90 ) ,
F_74 ( 'x' , L_91 , & V_6 . V_202 ,
L_92 ) ,
F_75 ( 'g' , L_93 , & V_4 , L_94 ,
L_95
L_96 , & F_65 , V_161 ) ,
F_74 ( 0 , L_97 , & V_6 . V_9 ,
L_98 ) ,
F_76 ( 0 , L_99 , & V_4 . V_59 ,
L_100
L_101
L_102 F_77 ( V_188 ) ) ,
F_74 ( 'G' , L_103 , & V_4 . V_203 ,
L_104 ) ,
F_78 ( 0 , L_105 , NULL , L_89 ,
L_106 ,
F_67 ) ,
F_72 ( 'd' , L_107 , & V_6 . V_204 , L_108 ,
L_109 ) ,
F_72 ( 'c' , L_110 , & V_6 . V_205 , L_111 ,
L_112 ) ,
F_72 ( 0 , L_113 , & V_6 . V_206 , L_114 ,
L_115 ) ,
F_72 ( 0 , L_116 , & V_6 . V_207 , L_117 ,
L_118 ) ,
F_72 ( 'S' , L_119 , & V_6 . V_208 , L_120 ,
L_121 ) ,
F_72 ( 0 , L_122 , & V_4 . V_137 , L_123 ,
L_124 ) ,
F_72 ( 'w' , L_125 , & V_6 . V_209 ,
L_126 ,
L_127 ) ,
F_79 ( 't' , L_128 , & V_6 . V_210 , L_129 ,
L_130
L_131 ) ,
F_74 ( 'U' , L_132 , & V_4 . V_42 ,
L_133 ) ,
F_72 ( 0 , L_134 , & V_6 . V_211 , L_135 ,
L_136 ) ,
F_72 ( 'C' , L_137 , & V_4 . V_48 , L_137 ,
L_138 ) ,
F_74 ( 'I' , L_139 , & V_4 . V_212 ,
L_140 ) ,
F_74 ( 0 , L_141 , & V_6 . V_213 ,
L_142 ) ,
F_74 ( 0 , L_143 , & V_6 . V_214 ,
L_144 ) ,
F_72 ( 'M' , L_145 , & V_215 , L_146 ,
L_147 ) ,
F_74 ( 0 , L_148 , & V_6 . V_216 ,
L_149 ) ,
F_74 ( 0 , L_150 , & V_6 . V_7 ,
L_151 ) ,
F_80 ( 'b' , L_152 , & V_152 , L_153 ,
L_154 ,
F_69 ) ,
F_74 ( 0 , L_155 , & V_160 ,
L_156 ) ,
F_72 ( 0 , L_157 , & V_217 , L_158 ,
L_159 ) ,
F_74 ( 0 , L_160 , & V_6 . V_218 ,
L_161 ) ,
F_74 ( 0 , L_162 , & V_6 . V_219 ,
L_163 ) ,
F_74 ( 0 , L_164 , & V_4 . V_32 , L_165 ) ,
F_78 ( 0 , L_166 , & V_4 , L_167 ,
L_168 , F_70 ) ,
F_78 ( 0 , L_169 , NULL , L_170 ,
L_171 , V_220 ) ,
F_81 ( 0 , L_172 , & V_155 , NULL , L_173 ,
L_174 ,
V_221 ) ,
F_82 ()
} ;
struct V_140 V_74 = {
. V_81 = V_222 ,
} ;
int V_44 = F_83 () ;
if ( V_44 < 0 )
return V_44 ;
F_84 ( F_1 , & V_4 ) ;
V_153 = F_85 ( V_153 , V_154 , V_189 , V_162 , 0 ) ;
if ( V_6 . V_191 &&
F_86 ( V_6 . V_191 , V_223 ) ) {
F_68 ( L_175 , V_6 . V_191 ) ;
return - V_77 ;
}
if ( V_6 . V_192 &&
F_86 ( V_6 . V_192 , V_223 ) ) {
F_68 ( L_175 , V_6 . V_192 ) ;
return - V_77 ;
}
if ( V_4 . V_198 )
V_131 = 0 ;
else if ( V_4 . V_196 )
V_131 = 1 ;
else if ( V_4 . V_197 )
V_131 = 2 ;
if ( V_4 . V_203 )
V_80 . V_224 = V_225 ;
if ( ! V_190 || ! strlen ( V_190 ) ) {
if ( ! F_87 ( V_226 , & V_158 ) && F_88 ( V_158 . V_227 ) )
V_190 = L_176 ;
else
V_190 = L_177 ;
}
V_74 . V_144 = V_190 ;
V_74 . V_193 = V_4 . V_193 ;
V_228:
V_70 = F_89 ( & V_74 , false , & V_4 . V_36 ) ;
if ( V_70 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_90 ( & V_70 -> V_186 ,
V_4 . V_10 ) ;
}
V_70 -> V_155 = & V_155 ;
V_4 . V_70 = V_70 ;
V_159 = F_91 ( & V_70 -> V_45 ,
V_229 ) ;
if ( ( ( V_152 == - 1 && V_159 ) || V_152 == 1 ) &&
! V_160 ) {
V_26 = V_27 ;
V_6 . V_9 = false ;
}
if ( V_160 ) {
V_80 . V_230 = V_231 ;
V_80 . V_232 = 1 ;
V_6 . V_78 = true ;
F_24 ( & V_80 ) ;
if ( V_107 == NULL )
V_107 = L_178 ;
}
if ( V_4 . V_32 ) {
if ( V_26 == V_27 ) {
F_68 ( L_179 ) ;
goto error;
}
V_26 = V_233 ;
V_6 . V_9 = false ;
}
if ( F_92 () < 0 ) {
if ( V_107 )
F_93 ( V_162 , V_189 , L_180 , 1 ) ;
if ( V_200 )
F_93 ( V_107 ? NULL : V_162 ,
V_189 , L_181 , 1 ) ;
goto error;
}
if ( V_4 . V_45 || V_4 . V_199 || V_4 . V_61 )
V_131 = 0 ;
if ( strcmp ( V_190 , L_176 ) != 0 )
F_94 ( true ) ;
else
V_131 = 0 ;
if ( V_4 . V_45 || V_4 . V_199 ) {
F_95 ( V_70 , stdout ,
V_4 . V_212 ) ;
if ( V_4 . V_199 ) {
V_44 = 0 ;
goto error;
}
} else if ( V_131 == 0 ) {
fputs ( L_182 ,
stdout ) ;
}
if ( F_6 () ) {
V_6 . V_234 = sizeof( struct V_235 ) ;
F_96 ( & V_70 -> V_117 ,
V_236 ) ;
if ( V_142 ) {
V_6 . V_234 += sizeof( V_237 ) ;
V_6 . V_238 = true ;
}
}
if ( F_97 ( & V_70 -> V_45 . V_132 ) < 0 )
goto error;
if ( V_153 ) {
if ( V_153 > 1 )
F_98 ( V_162 , V_189 ) ;
V_4 . V_137 = V_154 [ 0 ] ;
}
F_99 ( stdout ) ;
V_44 = F_57 ( & V_4 ) ;
if ( V_44 == V_133 ) {
F_100 ( V_70 ) ;
goto V_228;
} else
V_44 = 0 ;
error:
F_100 ( V_70 ) ;
return V_44 ;
}
