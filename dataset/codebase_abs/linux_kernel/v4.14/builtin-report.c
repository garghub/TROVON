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
if ( ! strcmp ( V_1 , L_4 ) )
return F_3 ( & V_5 -> V_12 , V_1 , V_2 ) ;
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
struct V_25 * V_26 = V_15 -> V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
if ( ! F_6 () )
return 0 ;
F_7 ( V_26 -> V_31 , V_17 , V_26 ,
V_5 -> V_32 ) ;
if ( V_33 == V_34 ) {
V_30 = V_22 -> V_29 ;
V_20 = F_8 ( & V_30 -> V_35 , V_26 , V_24 -> V_36 ) ;
if ( V_20 )
goto V_37;
V_20 = F_8 ( & V_30 -> V_38 , V_26 , V_24 -> V_36 ) ;
} else if ( V_5 -> V_39 ) {
V_28 = V_22 -> V_27 ;
V_20 = F_8 ( & V_28 -> V_40 , V_26 , V_24 -> V_36 ) ;
if ( V_20 )
goto V_37;
V_20 = F_9 ( V_22 , V_26 , V_24 -> V_36 , V_17 -> V_41 ) ;
} else if ( V_6 . V_11 ) {
if ( V_18 )
V_20 = F_9 ( V_22 , V_26 , V_24 -> V_36 ,
V_17 -> V_41 ) ;
} else {
V_20 = F_9 ( V_22 , V_26 , V_24 -> V_36 , V_17 -> V_41 ) ;
}
V_37:
return V_20 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17 V_42 ,
bool V_18 V_42 ,
void * V_19 )
{
struct V_21 * V_22 = V_15 -> V_22 ;
struct V_4 * V_5 = V_19 ;
struct V_29 * V_30 ;
V_30 = V_22 -> V_29 ;
F_11 ( & V_5 -> V_43 , & V_30 -> V_44 ,
V_30 -> V_35 . V_41 , V_30 -> V_38 . V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_45 * V_46 ,
union V_47 * V_48 ,
struct V_25 * V_26 ,
struct V_23 * V_24 ,
struct V_49 * V_49 )
{
struct V_4 * V_5 = F_13 ( V_46 , struct V_4 , V_46 ) ;
struct V_16 V_17 ;
struct V_14 V_15 = {
. V_24 = V_24 ,
. V_26 = V_26 ,
. V_50 = V_6 . V_50 ,
. V_51 = F_5 ,
} ;
int V_52 = 0 ;
if ( F_14 ( & V_5 -> V_53 , V_26 -> time ) )
return 0 ;
if ( F_15 ( V_49 , & V_17 , V_26 ) < 0 ) {
F_16 ( L_6 ,
V_48 -> V_54 . type ) ;
return - 1 ;
}
if ( V_6 . V_50 && V_17 . V_55 == NULL )
goto V_56;
if ( V_5 -> V_57 && ! F_17 ( V_26 -> V_58 , V_5 -> V_59 ) )
goto V_56;
if ( V_33 == V_34 ) {
if ( ! V_26 -> V_31 )
goto V_56;
V_15 . V_51 = F_10 ;
V_15 . V_60 = & V_61 ;
} else if ( V_5 -> V_39 ) {
V_15 . V_60 = & V_62 ;
} else if ( V_6 . V_11 ) {
V_15 . V_60 = & V_63 ;
} else {
V_15 . V_60 = & V_64 ;
}
if ( V_17 . V_65 != NULL )
V_17 . V_65 -> V_66 -> V_67 = 1 ;
V_52 = F_18 ( & V_15 , & V_17 , V_5 -> V_68 , V_5 ) ;
if ( V_52 < 0 )
F_16 ( L_7 ) ;
V_56:
F_19 ( & V_17 ) ;
return V_52 ;
}
static int F_20 ( struct V_45 * V_46 ,
union V_47 * V_48 ,
struct V_25 * V_26 V_42 ,
struct V_23 * V_24 ,
struct V_49 * V_49 V_42 )
{
struct V_4 * V_5 = F_13 ( V_46 , struct V_4 , V_46 ) ;
if ( V_5 -> V_69 ) {
const char * V_70 = V_24 ? F_21 ( V_24 ) : L_8 ;
int V_20 = F_22 ( & V_5 -> V_71 ,
V_48 -> V_72 . V_73 , V_48 -> V_72 . V_74 ,
V_24 -> V_36 ,
V_70 ,
V_48 -> V_72 . V_2 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
struct V_75 * V_76 = V_5 -> V_76 ;
T_1 V_77 = F_24 ( V_76 -> V_78 ) ;
bool V_79 = F_25 ( V_76 -> V_80 ) ;
if ( V_76 -> V_81 -> V_82 ||
( ! V_79 &&
F_26 ( & V_76 -> V_54 , V_83 ) &&
! V_76 -> V_81 -> V_84 ) )
V_77 |= V_85 ;
if ( V_76 -> V_81 -> V_86 )
V_77 |= V_87 ;
if ( ! V_79 && ! ( V_77 & V_85 ) ) {
if ( V_88 . V_89 ) {
F_27 ( L_9
L_10
L_11 ) ;
return - V_90 ;
}
if ( V_6 . V_91 &&
! V_6 . V_92 ) {
F_27 ( L_12
L_13
L_14 ) ;
return - 1 ;
}
} else if ( ! V_10 . V_93 &&
V_10 . V_94 != V_95 &&
! V_6 . V_91 ) {
V_6 . V_91 = true ;
if ( F_28 ( & V_10 ) < 0 ) {
F_27 ( L_15 ) ;
return - V_90 ;
}
}
if ( V_6 . V_11 ) {
if ( ! ( V_77 & V_85 ) ) {
V_6 . V_11 = false ;
F_29 () ;
}
}
if ( V_33 == V_34 ) {
if ( ! V_79 &&
! ( V_77 & V_87 ) ) {
F_27 ( L_16
L_17 ) ;
return - 1 ;
}
}
if ( V_6 . V_91 || V_6 . V_11 ) {
if ( ( V_77 & V_96 ) &&
( V_77 & V_97 ) )
V_10 . V_98 = V_99 ;
else if ( V_77 & V_87 )
V_10 . V_98 = V_100 ;
else
V_10 . V_98 = V_101 ;
}
if ( ! ( F_30 ( V_76 -> V_78 ) &
V_102 ) )
V_5 -> V_32 = true ;
return 0 ;
}
static void F_31 ( int T_2 V_42 )
{
V_103 = 1 ;
}
static T_3 F_32 ( struct V_104 * V_104 , struct V_4 * V_5 ,
const char * V_105 , T_4 * V_106 )
{
T_3 V_52 ;
char V_107 ;
unsigned long V_108 = V_104 -> V_109 . V_110 [ V_111 ] ;
T_1 V_110 = V_104 -> V_109 . V_112 ;
struct V_23 * V_24 = F_33 ( V_104 ) ;
char V_113 [ 512 ] ;
T_3 V_114 = sizeof( V_113 ) ;
int V_115 = V_104 -> V_116 ;
if ( V_117 )
return 0 ;
if ( V_6 . V_118 ) {
V_108 = V_104 -> V_109 . V_119 ;
V_110 = V_104 -> V_109 . V_120 ;
}
if ( F_34 ( V_24 ) ) {
struct V_23 * V_121 ;
F_35 ( V_24 , V_113 , V_114 ) ;
V_105 = V_113 ;
F_36 (pos, evsel) {
const struct V_104 * V_122 = F_37 ( V_121 ) ;
if ( V_6 . V_118 ) {
V_108 += V_122 -> V_109 . V_119 ;
V_110 += V_122 -> V_109 . V_120 ;
} else {
V_108 += V_122 -> V_109 . V_110 [ V_111 ] ;
V_110 += V_122 -> V_109 . V_112 ;
}
}
}
V_108 = F_38 ( V_108 , & V_107 ) ;
V_52 = fprintf ( V_106 , L_18 , V_108 , V_107 ) ;
if ( V_105 != NULL )
V_52 += fprintf ( V_106 , L_19 , V_105 ) ;
if ( V_6 . V_123 &&
strstr ( V_105 , L_20 ) ) {
V_52 += fprintf ( V_106 , L_21 ) ;
}
if ( V_5 -> V_39 ) {
V_52 += fprintf ( V_106 , L_22 V_124 , V_110 ) ;
V_52 += fprintf ( V_106 , L_23 , V_125 ? : V_126 ) ;
} else
V_52 += fprintf ( V_106 , L_24 V_124 , V_110 ) ;
if ( V_115 > - 1 )
V_52 += fprintf ( V_106 , L_25 , V_115 ) ;
return V_52 + fprintf ( V_106 , L_26 ) ;
}
static int F_39 ( struct V_127 * V_78 ,
struct V_4 * V_5 ,
const char * V_128 )
{
struct V_23 * V_121 ;
if ( ! V_117 ) {
fprintf ( stdout , L_27 V_124 L_26 ,
V_78 -> V_109 . V_129 ) ;
}
F_40 (evlist, pos) {
struct V_104 * V_104 = F_37 ( V_121 ) ;
const char * V_105 = F_21 ( V_121 ) ;
if ( V_6 . V_7 &&
! F_41 ( V_121 ) )
continue;
F_32 ( V_104 , V_5 , V_105 , stdout ) ;
F_42 ( V_104 , ! V_117 , 0 , 0 , V_5 -> V_9 , stdout ,
V_6 . V_91 ||
V_6 . V_92 ) ;
fprintf ( stdout , L_28 ) ;
}
if ( ! V_117 )
fprintf ( stdout , L_29 , V_128 ) ;
if ( V_5 -> V_69 ) {
bool V_130 = ! strcmp ( V_5 -> V_131 , L_30 ) ;
F_43 ( stdout , & V_5 -> V_71 ,
V_130 ) ;
F_44 ( & V_5 -> V_71 ) ;
}
if ( V_33 == V_34 )
F_45 ( stdout , & V_5 -> V_43 ) ;
return 0 ;
}
static void F_46 ( const struct V_4 * V_5 )
{
struct V_65 * V_132 = F_47 ( & V_5 -> V_76 -> V_133 . V_134 ) ;
struct V_135 * V_136 = V_132 ? F_48 ( V_132 ) : NULL ;
if ( V_132 == NULL ||
( V_132 -> V_66 -> V_67 &&
( V_136 -> V_137 == NULL ||
V_136 -> V_137 -> V_41 == 0 ) ) ) {
const char * V_138 =
L_31
L_32 ;
if ( V_132 ) {
const struct V_66 * V_139 = V_132 -> V_66 ;
if ( ! F_49 ( & V_139 -> V_140 [ V_141 ] ) ) {
V_138 = L_33
L_34 ;
}
}
F_50 (
L_35
L_36
L_37 ,
V_138 ) ;
}
}
static int F_51 ( struct V_4 * V_5 , const char * V_128 )
{
int (* F_52)( struct V_127 * V_78 , const char * V_128 ,
struct V_142 * V_143 , float V_144 );
F_52 = F_53 ( V_145 , L_38 ) ;
if ( F_52 == NULL ) {
F_27 ( L_39 ) ;
return - 1 ;
}
return F_52 ( V_5 -> V_76 -> V_78 , V_128 , NULL , V_5 -> V_9 ) ;
}
static int F_54 ( struct V_4 * V_5 )
{
int V_52 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_127 * V_78 = V_76 -> V_78 ;
const char * V_128 = F_55 ( F_56 ( V_146 ) ) ;
if ( V_128 == NULL ) {
V_128 = F_55 ( V_147 ) ;
if ( V_128 == NULL )
V_128 = L_40 ;
}
switch ( V_148 ) {
case 1 :
V_52 = F_57 ( V_78 , V_128 , NULL ,
V_5 -> V_9 ,
& V_76 -> V_54 . V_149 ) ;
if ( V_52 != V_150 )
V_52 = 0 ;
break;
case 2 :
V_52 = F_51 ( V_5 , V_128 ) ;
break;
default:
V_52 = F_39 ( V_78 , V_5 , V_128 ) ;
break;
}
return V_52 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_151 V_152 ;
struct V_23 * V_121 ;
int V_52 = 0 ;
F_59 ( & V_152 , V_5 -> V_153 , L_41 ) ;
F_40 (rep->session->evlist, pos) {
struct V_104 * V_104 = F_37 ( V_121 ) ;
if ( V_121 -> V_36 == 0 )
V_104 -> V_154 = V_5 -> V_154 ;
V_104 -> V_116 = V_5 -> V_116 ;
V_52 = F_60 ( V_104 , & V_152 ) ;
if ( V_52 < 0 )
break;
if ( V_6 . V_7 &&
! F_41 ( V_121 ) ) {
struct V_104 * V_155 = F_37 ( V_121 -> V_156 ) ;
F_61 ( V_155 , V_104 ) ;
F_62 ( V_155 , V_104 ) ;
}
}
F_63 () ;
return V_52 ;
}
static void F_64 ( struct V_4 * V_5 )
{
struct V_151 V_152 ;
struct V_23 * V_121 ;
F_59 ( & V_152 , V_5 -> V_153 , L_42 ) ;
F_40 (rep->session->evlist, pos)
F_65 ( V_121 , & V_152 ) ;
F_63 () ;
}
static int F_66 ( struct V_4 * V_5 )
{
int V_52 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_23 * V_121 ;
struct V_157 * V_80 = V_76 -> V_80 ;
signal ( V_158 , F_31 ) ;
if ( V_5 -> V_57 ) {
V_52 = F_67 ( V_76 , V_5 -> V_57 ,
V_5 -> V_59 ) ;
if ( V_52 ) {
F_27 ( L_43 ) ;
return V_52 ;
}
V_76 -> V_81 -> V_59 = V_5 -> V_59 ;
}
if ( V_5 -> V_69 ) {
V_52 = F_68 ( & V_5 -> V_71 ) ;
if ( V_52 )
return V_52 ;
}
V_52 = F_23 ( V_5 ) ;
if ( V_52 ) {
return V_52 ;
}
V_52 = F_69 ( V_76 ) ;
if ( V_52 ) {
F_27 ( L_44 ) ;
return V_52 ;
}
F_46 ( V_5 ) ;
F_40 (session->evlist, pos)
V_5 -> V_153 += F_37 ( V_121 ) -> V_153 ;
if ( V_148 == 0 ) {
if ( V_159 > 3 )
F_70 ( V_76 , stdout ) ;
if ( V_159 > 2 )
F_71 ( V_76 , stdout ) ;
if ( V_160 ) {
F_72 ( V_76 , stdout ) ;
F_73 ( V_76 -> V_78 , stdout ) ;
return 0 ;
}
}
V_52 = F_58 ( V_5 ) ;
if ( V_52 ) {
F_27 ( L_45 ) ;
return V_52 ;
}
if ( V_103 () )
return 0 ;
V_5 -> V_153 = 0 ;
F_40 (session->evlist, pos)
V_5 -> V_153 += F_37 ( V_121 ) -> V_153 ;
if ( V_5 -> V_153 == 0 ) {
F_27 ( L_46 , V_80 -> V_161 ) ;
return 0 ;
}
F_64 ( V_5 ) ;
return F_54 ( V_5 ) ;
}
static int
F_74 ( const struct V_162 * V_163 , const char * V_19 , int V_164 )
{
struct V_10 * V_82 = V_163 -> V_2 ;
V_82 -> V_93 = ! V_164 ;
if ( V_164 ) {
V_6 . V_91 = false ;
V_82 -> V_94 = V_95 ;
return 0 ;
}
return F_75 ( V_19 ) ;
}
int
F_76 ( const struct V_162 * V_163 V_42 ,
const char * V_19 , int V_164 V_42 )
{
if ( V_19 ) {
int V_20 = regcomp ( & V_165 , V_19 , V_166 ) ;
if ( V_20 ) {
char V_113 [ V_167 ] ;
regerror ( V_20 , & V_165 , V_113 , sizeof( V_113 ) ) ;
F_77 ( L_47 , V_19 , V_113 ) ;
return - 1 ;
}
V_168 = 1 ;
}
return 0 ;
}
static int
F_78 ( const struct V_162 * V_163 ,
const char * T_5 V_42 , int V_164 )
{
int * V_169 = V_163 -> V_2 ;
* V_169 = ! V_164 ;
return 0 ;
}
static int
F_79 ( const struct V_162 * V_163 , const char * T_5 ,
int V_164 V_42 )
{
struct V_4 * V_5 = V_163 -> V_2 ;
double V_8 = strtof ( T_5 , NULL ) ;
V_5 -> V_9 = V_8 ;
V_10 . V_9 = V_8 ;
return 0 ;
}
int F_80 ( int V_170 , const char * * V_171 )
{
struct V_75 * V_76 ;
struct V_81 V_81 = { . V_84 = 0 , } ;
struct V_172 V_173 ;
bool V_174 = false ;
int V_169 = - 1 ;
bool V_175 = false ;
char V_176 [] = V_177 ;
const char * const V_178 [] = {
L_48 ,
NULL
} ;
struct V_4 V_4 = {
. V_46 = {
. V_26 = F_12 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. V_183 = V_184 ,
. V_185 = V_186 ,
. exit = V_187 ,
. V_188 = V_189 ,
. V_190 = V_191 ,
. V_72 = F_20 ,
. V_192 = V_193 ,
. V_194 = V_195 ,
. V_196 = V_197 ,
. V_198 = V_199 ,
. V_200 = V_201 ,
. V_202 = V_203 ,
. V_204 = V_205 ,
. V_206 = true ,
. V_207 = true ,
} ,
. V_68 = V_208 ,
. V_131 = L_49 ,
. V_116 = - 1 ,
} ;
const struct V_162 V_209 [] = {
F_81 ( 'i' , L_50 , & V_210 , L_51 ,
L_52 ) ,
F_82 ( 'v' , L_53 , & V_159 ,
L_54 ) ,
F_83 ( 'q' , L_55 , & V_117 , L_56 ) ,
F_83 ( 'D' , L_57 , & V_160 ,
L_58 ) ,
F_81 ( 'k' , L_59 , & V_6 . V_211 ,
L_51 , L_60 ) ,
F_81 ( 0 , L_61 , & V_6 . V_212 ,
L_51 , L_62 ) ,
F_83 ( 'f' , L_63 , & V_6 . V_213 , L_64 ) ,
F_83 ( 'm' , L_65 , & V_6 . V_214 ,
L_66 ) ,
F_83 ( 'n' , L_67 , & V_6 . V_215 ,
L_68 ) ,
F_83 ( 'T' , L_69 , & V_4 . V_69 ,
L_70 ) ,
F_81 ( 0 , L_71 , & V_4 . V_131 , L_72 ,
L_73 ) ,
F_83 ( 0 , L_74 , & V_4 . V_216 , L_75 ) ,
F_83 ( 0 , L_76 , & V_4 . V_217 , L_77 ) ,
F_83 ( 0 , L_78 , & V_4 . V_218 ,
L_79 ) ,
F_83 ( 0 , L_80 , & V_4 . V_54 , L_81 ) ,
F_83 ( 0 , L_82 , & V_4 . V_219 ,
L_83 ) ,
F_81 ( 's' , L_84 , & V_125 , L_85 ,
L_86
L_87 ) ,
F_81 ( 'F' , L_88 , & V_220 , L_89 ,
L_90 ) ,
F_83 ( 0 , L_91 , & V_6 . V_221 ,
L_92 ) ,
F_84 ( 0 , L_93 , & V_6 . V_221 ,
L_92 , V_222 ) ,
F_81 ( 'p' , L_94 , & V_223 , L_95 ,
L_96 ) ,
F_83 ( 'x' , L_97 , & V_6 . V_224 ,
L_98 ) ,
F_85 ( 'g' , L_99 , & V_10 ,
L_100 ,
V_225 , & F_74 ,
V_176 ) ,
F_83 ( 0 , L_101 , & V_6 . V_11 ,
L_102 ) ,
F_86 ( 0 , L_103 , & V_4 . V_68 ,
L_104
L_105
L_106 F_87 ( V_208 ) ) ,
F_83 ( 'G' , L_107 , & V_4 . V_226 ,
L_108 ) ,
F_88 ( 0 , L_109 , NULL , L_95 ,
L_110 ,
F_76 ) ,
F_81 ( 'd' , L_111 , & V_6 . V_227 , L_112 ,
L_113 ) ,
F_81 ( 'c' , L_114 , & V_6 . V_228 , L_115 ,
L_116 ) ,
F_81 ( 0 , L_117 , & V_6 . V_229 , L_118 ,
L_119 ) ,
F_81 ( 0 , L_120 , & V_6 . V_230 , L_121 ,
L_122 ) ,
F_81 ( 'S' , L_123 , & V_6 . V_231 , L_124 ,
L_125 ) ,
F_81 ( 0 , L_126 , & V_4 . V_154 , L_127 ,
L_128 ) ,
F_81 ( 'w' , L_129 , & V_6 . V_232 ,
L_130 ,
L_131 ) ,
F_89 ( 't' , L_132 , & V_6 . V_233 , L_133 ,
L_134
L_135 ) ,
F_83 ( 'U' , L_136 , & V_6 . V_50 ,
L_137 ) ,
F_88 ( 0 , L_138 , NULL , L_139 ,
L_140 ,
V_234 ) ,
F_81 ( 'C' , L_141 , & V_4 . V_57 , L_141 ,
L_142 ) ,
F_83 ( 'I' , L_143 , & V_4 . V_235 ,
L_144 ) ,
F_83 ( 0 , L_145 , & V_6 . V_236 ,
L_146 ) ,
F_83 ( 0 , L_147 , & V_6 . V_237 ,
L_148 ) ,
F_81 ( 'M' , L_149 , & V_238 , L_150 ,
L_151 ) ,
F_83 ( 0 , L_152 , & V_6 . V_239 ,
L_153 ) ,
F_83 ( 0 , L_154 , & V_6 . V_7 ,
L_155 ) ,
F_90 ( 'b' , L_156 , & V_169 , L_157 ,
L_158 ,
F_78 ) ,
F_83 ( 0 , L_159 , & V_175 ,
L_160 ) ,
F_81 ( 0 , L_161 , & V_240 , L_162 ,
L_163 ) ,
F_83 ( 0 , L_164 , & V_6 . V_241 ,
L_165 ) ,
F_83 ( 0 , L_166 , & V_6 . V_242 ,
L_167 ) ,
F_83 ( 0 , L_168 , & V_4 . V_39 , L_169 ) ,
F_88 ( 0 , L_170 , & V_4 , L_171 ,
L_172 , F_79 ) ,
F_88 ( 0 , L_173 , NULL , L_174 ,
L_175 , V_243 ) ,
F_91 ( 0 , L_176 , & V_81 , NULL , L_177 ,
L_178 ,
V_244 ) ,
F_83 ( 0 , L_179 , & V_245 ,
L_180 ) ,
F_83 ( 0 , L_181 , & V_6 . V_123 ,
L_182 ) ,
F_86 ( 0 , L_183 , & V_4 . V_116 ,
L_184 ) ,
F_83 ( 0 , L_185 , & V_6 . V_246 ,
L_186 ) ,
F_83 ( 0 , L_187 , & V_6 . V_247 ,
L_188 ) ,
F_85 ( 0 , L_189 , NULL , L_190 ,
L_191 ,
V_248 , L_192 ) ,
F_81 ( 0 , L_193 , & V_4 . V_249 , L_194 ,
L_195 ) ,
F_83 ( 0 , L_196 , & V_6 . V_250 ,
L_197 ) ,
F_92 ()
} ;
struct V_157 V_80 = {
. V_94 = V_251 ,
} ;
int V_52 = F_93 () ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_94 ( F_1 , & V_4 ) ;
if ( V_52 )
return V_52 ;
V_170 = F_95 ( V_170 , V_171 , V_209 , V_178 , 0 ) ;
if ( V_170 ) {
if ( V_170 > 1 )
F_96 ( V_178 , V_209 ) ;
V_4 . V_154 = V_171 [ 0 ] ;
}
if ( V_117 )
F_97 () ;
if ( V_6 . V_211 &&
F_98 ( V_6 . V_211 , V_252 ) ) {
F_77 ( L_198 , V_6 . V_211 ) ;
return - V_90 ;
}
if ( V_6 . V_212 &&
F_98 ( V_6 . V_212 , V_252 ) ) {
F_77 ( L_198 , V_6 . V_212 ) ;
return - V_90 ;
}
if ( V_4 . V_218 )
V_148 = 0 ;
else if ( V_4 . V_216 )
V_148 = 1 ;
else if ( V_4 . V_217 )
V_148 = 2 ;
if ( V_4 . V_226 )
V_10 . V_253 = V_254 ;
if ( V_6 . V_11 && ! V_10 . V_255 )
V_10 . V_253 = V_254 ;
if ( V_81 . V_82 &&
( int ) V_81 . V_256 > V_4 . V_68 )
V_4 . V_68 = V_81 . V_256 ;
if ( ! V_210 || ! strlen ( V_210 ) ) {
if ( ! F_99 ( V_257 , & V_173 ) && F_100 ( V_173 . V_258 ) )
V_210 = L_199 ;
else
V_210 = L_200 ;
}
V_80 . V_161 = V_210 ;
V_80 . V_213 = V_6 . V_213 ;
V_259:
V_76 = F_101 ( & V_80 , false , & V_4 . V_46 ) ;
if ( V_76 == NULL )
return - 1 ;
if ( V_4 . V_12 ) {
F_102 ( & V_76 -> V_206 ,
V_4 . V_12 ) ;
}
V_76 -> V_81 = & V_81 ;
V_4 . V_76 = V_76 ;
V_174 = F_26 ( & V_76 -> V_54 ,
V_260 ) ;
if ( V_81 . V_86 )
V_174 = true ;
if ( V_174 && V_175 )
V_6 . V_92 = true ;
memset ( & V_4 . V_43 , 0 , sizeof( struct V_261 ) ) ;
if ( ( ( V_169 == - 1 && V_174 ) || V_169 == 1 ) &&
! V_175 ) {
V_33 = V_34 ;
V_6 . V_11 = false ;
}
if ( V_175 ) {
V_10 . V_262 = V_263 ;
V_10 . V_264 = 1 ;
V_6 . V_91 = true ;
F_28 ( & V_10 ) ;
if ( V_125 == NULL )
V_125 = L_201 ;
}
if ( V_4 . V_39 ) {
if ( V_33 == V_34 ) {
F_77 ( L_202 ) ;
goto error;
}
V_33 = V_265 ;
V_6 . V_11 = false ;
}
if ( V_6 . V_247 ) {
V_6 . V_11 = false ;
if ( V_220 ) {
F_77 ( L_203 ) ;
F_103 ( V_178 , V_209 , L_204 , 1 ) ;
F_103 ( NULL , V_209 , L_187 , 0 ) ;
goto error;
}
V_88 . V_266 = true ;
}
if ( V_4 . V_54 || V_4 . V_219 || V_4 . V_69 )
V_148 = 0 ;
if ( V_4 . V_54 || V_4 . V_219 )
V_4 . V_46 . V_267 = V_268 ;
if ( V_4 . V_235 )
V_4 . V_46 . V_267 = V_269 ;
if ( strcmp ( V_210 , L_199 ) != 0 )
F_104 ( true ) ;
else
V_148 = 0 ;
if ( F_105 ( V_76 -> V_78 ) < 0 ) {
if ( V_125 )
F_103 ( V_178 , V_209 , L_205 , 1 ) ;
if ( V_220 )
F_103 ( V_125 ? NULL : V_178 ,
V_209 , L_204 , 1 ) ;
goto error;
}
if ( ( V_4 . V_54 || V_4 . V_219 ) && ! V_117 ) {
F_106 ( V_76 , stdout ,
V_4 . V_235 ) ;
if ( V_4 . V_219 ) {
V_52 = 0 ;
goto error;
}
} else if ( V_148 == 0 && ! V_117 ) {
fputs ( L_206 ,
stdout ) ;
}
if ( F_6 () ) {
V_52 = F_107 () ;
if ( V_52 < 0 )
goto error;
if ( V_159 > 0 ) {
V_6 . V_270 += sizeof( V_271 ) ;
V_6 . V_272 = true ;
}
}
if ( F_108 ( & V_76 -> V_54 . V_149 ) < 0 )
goto error;
if ( F_109 ( & V_4 . V_53 , V_4 . V_249 ) != 0 ) {
F_77 ( L_207 ) ;
return - V_90 ;
}
F_110 ( stdout ) ;
V_52 = F_66 ( & V_4 ) ;
if ( V_52 == V_150 ) {
F_111 ( V_76 ) ;
goto V_259;
} else
V_52 = 0 ;
error:
F_111 ( V_76 ) ;
return V_52 ;
}
