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
. V_42 = V_5 -> V_42 ,
. V_43 = F_5 ,
} ;
int V_44 ;
if ( F_11 ( V_38 , V_41 , & V_14 , V_40 ) < 0 ) {
F_12 ( L_5 ,
V_38 -> V_45 . type ) ;
return - 1 ;
}
if ( V_5 -> V_42 && V_14 . V_46 == NULL )
return 0 ;
if ( V_5 -> V_47 && ! F_13 ( V_40 -> V_48 , V_5 -> V_49 ) )
return 0 ;
if ( V_26 == V_27 )
V_12 . V_50 = & V_51 ;
else if ( V_5 -> V_32 )
V_12 . V_50 = & V_52 ;
else if ( V_6 . V_9 )
V_12 . V_50 = & V_53 ;
else
V_12 . V_50 = & V_54 ;
if ( V_14 . V_55 != NULL )
V_14 . V_55 -> V_56 -> V_57 = 1 ;
V_44 = F_14 ( & V_12 , & V_14 , V_21 , V_40 , V_5 -> V_58 ,
V_5 ) ;
if ( V_44 < 0 )
F_12 ( L_6 ) ;
return V_44 ;
}
static int F_15 ( struct V_35 * V_36 ,
union V_37 * V_38 ,
struct V_39 * V_40 V_59 ,
struct V_20 * V_21 ,
struct V_41 * V_41 V_59 )
{
struct V_4 * V_5 = F_10 ( V_36 , struct V_4 , V_36 ) ;
if ( V_5 -> V_60 ) {
const char * V_61 = V_21 ? F_16 ( V_21 ) : L_7 ;
F_17 ( & V_5 -> V_62 ,
V_38 -> V_63 . V_64 , V_38 -> V_63 . V_65 ,
V_38 -> V_63 . V_66 ,
V_61 ,
V_38 -> V_63 . V_2 ) ;
}
F_18 ( L_8 V_67 L_9 , V_38 -> V_63 . V_64 , V_38 -> V_63 . V_65 ,
V_21 ? F_16 ( V_21 ) : L_10 ,
V_38 -> V_63 . V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_68 * V_69 = V_5 -> V_69 ;
T_1 V_70 = F_20 ( V_69 -> V_71 ) ;
bool V_72 = F_21 ( V_69 -> V_73 ) ;
if ( ! V_72 && ! ( V_70 & V_74 ) ) {
if ( V_75 ) {
F_22 ( L_11
L_12
L_13 ) ;
return - V_76 ;
}
if ( V_6 . V_77 ) {
F_22 ( L_14
L_15
L_16 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_78 &&
V_79 . V_80 != V_81 &&
! V_6 . V_77 ) {
V_6 . V_77 = true ;
if ( F_23 ( & V_79 ) < 0 ) {
F_22 ( L_17 ) ;
return - V_76 ;
}
}
if ( V_6 . V_9 ) {
if ( ! ( V_70 & V_74 ) ) {
V_6 . V_9 = false ;
F_24 () ;
}
}
if ( V_26 == V_27 ) {
if ( ! V_72 &&
! ( V_70 & V_82 ) ) {
F_22 ( L_18
L_19 ) ;
return - 1 ;
}
}
if ( V_6 . V_77 || V_6 . V_9 ) {
if ( ( V_70 & V_83 ) &&
( V_70 & V_84 ) )
V_79 . V_85 = V_86 ;
else if ( V_70 & V_82 )
V_79 . V_85 = V_87 ;
else
V_79 . V_85 = V_88 ;
}
return 0 ;
}
static void F_25 ( int T_2 V_59 )
{
V_89 = 1 ;
}
static T_3 F_26 ( struct V_90 * V_90 , struct V_4 * V_5 ,
const char * V_91 , T_4 * V_92 )
{
T_3 V_44 ;
char V_93 ;
unsigned long V_94 = V_90 -> V_95 . V_96 [ V_97 ] ;
T_1 V_96 = V_90 -> V_95 . V_98 ;
struct V_20 * V_21 = F_27 ( V_90 ) ;
char V_99 [ 512 ] ;
T_3 V_100 = sizeof( V_99 ) ;
if ( V_6 . V_101 ) {
V_94 = V_90 -> V_95 . V_102 ;
V_96 = V_90 -> V_95 . V_103 ;
}
if ( F_28 ( V_21 ) ) {
struct V_20 * V_104 ;
F_29 ( V_21 , V_99 , V_100 ) ;
V_91 = V_99 ;
F_30 (pos, evsel) {
const struct V_90 * V_105 = F_31 ( V_104 ) ;
if ( V_6 . V_101 ) {
V_94 += V_105 -> V_95 . V_102 ;
V_96 += V_105 -> V_95 . V_103 ;
} else {
V_94 += V_105 -> V_95 . V_96 [ V_97 ] ;
V_96 += V_105 -> V_95 . V_98 ;
}
}
}
V_94 = F_32 ( V_94 , & V_93 ) ;
V_44 = fprintf ( V_92 , L_20 , V_94 , V_93 ) ;
if ( V_91 != NULL )
V_44 += fprintf ( V_92 , L_21 , V_91 ) ;
if ( V_5 -> V_32 ) {
V_44 += fprintf ( V_92 , L_22 V_67 , V_96 ) ;
V_44 += fprintf ( V_92 , L_23 , V_106 ? : V_107 ) ;
} else
V_44 += fprintf ( V_92 , L_24 V_67 , V_96 ) ;
return V_44 + fprintf ( V_92 , L_25 ) ;
}
static int F_33 ( struct V_108 * V_71 ,
struct V_4 * V_5 ,
const char * V_109 )
{
struct V_20 * V_104 ;
F_34 (evlist, pos) {
struct V_90 * V_90 = F_31 ( V_104 ) ;
const char * V_91 = F_16 ( V_104 ) ;
if ( V_6 . V_7 &&
! F_35 ( V_104 ) )
continue;
F_26 ( V_90 , V_5 , V_91 , stdout ) ;
F_36 ( V_90 , true , 0 , 0 , V_5 -> V_8 , stdout ) ;
fprintf ( stdout , L_26 ) ;
}
if ( V_106 == NULL &&
V_110 == V_111 ) {
fprintf ( stdout , L_27 , V_109 ) ;
if ( V_5 -> V_60 ) {
bool V_112 = ! strcmp ( V_5 -> V_113 , L_28 ) ;
F_37 ( stdout , & V_5 -> V_62 ,
V_112 ) ;
F_38 ( & V_5 -> V_62 ) ;
}
}
return 0 ;
}
static void F_39 ( const struct V_4 * V_5 )
{
struct V_55 * V_114 = V_5 -> V_69 -> V_115 . V_116 . V_117 [ V_118 ] ;
struct V_119 * V_120 = V_114 ? F_40 ( V_114 ) : NULL ;
if ( V_114 == NULL ||
( V_114 -> V_56 -> V_57 &&
( V_120 -> V_121 == NULL ||
V_120 -> V_121 -> V_34 == 0 ) ) ) {
const char * V_122 =
L_29
L_30 ;
if ( V_114 ) {
const struct V_56 * V_123 = V_114 -> V_56 ;
if ( ! F_41 ( & V_123 -> V_124 [ V_118 ] ) ) {
V_122 = L_31
L_32 ;
}
}
F_42 (
L_33
L_34
L_35 ,
V_122 ) ;
}
}
static int F_43 ( struct V_4 * V_5 , const char * V_109 )
{
int (* F_44)( struct V_108 * V_71 , const char * V_109 ,
struct V_125 * V_126 , float V_127 );
F_44 = F_45 ( V_128 , L_36 ) ;
if ( F_44 == NULL ) {
F_22 ( L_37 ) ;
return - 1 ;
}
return F_44 ( V_5 -> V_69 -> V_71 , V_109 , NULL , V_5 -> V_8 ) ;
}
static int F_46 ( struct V_4 * V_5 )
{
int V_44 ;
struct V_68 * V_69 = V_5 -> V_69 ;
struct V_108 * V_71 = V_69 -> V_71 ;
const char * V_109 = L_38 ;
switch ( V_129 ) {
case 1 :
V_44 = F_47 ( V_71 , V_109 , NULL ,
V_5 -> V_8 ,
& V_69 -> V_45 . V_130 ) ;
if ( V_44 != V_131 )
V_44 = 0 ;
break;
case 2 :
V_44 = F_43 ( V_5 , V_109 ) ;
break;
default:
V_44 = F_33 ( V_71 , V_5 , V_109 ) ;
break;
}
return V_44 ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_132 V_133 ;
struct V_20 * V_104 ;
F_49 ( & V_133 , V_5 -> V_134 , L_39 ) ;
F_34 (rep->session->evlist, pos) {
struct V_90 * V_90 = F_31 ( V_104 ) ;
if ( V_104 -> V_29 == 0 )
V_90 -> V_135 = V_5 -> V_135 ;
F_50 ( V_90 , & V_133 ) ;
if ( V_6 . V_7 &&
! F_35 ( V_104 ) ) {
struct V_90 * V_136 = F_31 ( V_104 -> V_137 ) ;
F_51 ( V_136 , V_90 ) ;
F_52 ( V_136 , V_90 ) ;
}
}
F_53 () ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_132 V_133 ;
struct V_20 * V_104 ;
F_49 ( & V_133 , V_5 -> V_134 , L_40 ) ;
F_34 (rep->session->evlist, pos)
F_55 ( F_31 ( V_104 ) , & V_133 ) ;
F_53 () ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_44 ;
struct V_68 * V_69 = V_5 -> V_69 ;
struct V_20 * V_104 ;
struct V_138 * V_73 = V_69 -> V_73 ;
signal ( V_139 , F_25 ) ;
if ( V_5 -> V_47 ) {
V_44 = F_57 ( V_69 , V_5 -> V_47 ,
V_5 -> V_49 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_5 -> V_60 )
F_58 ( & V_5 -> V_62 ) ;
V_44 = F_19 ( V_5 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_59 ( V_69 ) ;
if ( V_44 )
return V_44 ;
F_39 ( V_5 ) ;
F_34 (session->evlist, pos)
V_5 -> V_134 += F_31 ( V_104 ) -> V_134 ;
if ( V_129 == 0 ) {
if ( V_140 > 3 )
F_60 ( V_69 , stdout ) ;
if ( V_140 > 2 )
F_61 ( V_69 , stdout ) ;
if ( V_141 ) {
F_62 ( V_69 , stdout ) ;
F_63 ( V_69 -> V_71 , stdout ) ;
return 0 ;
}
}
F_48 ( V_5 ) ;
if ( V_89 () )
return 0 ;
V_5 -> V_134 = 0 ;
F_34 (session->evlist, pos)
V_5 -> V_134 += F_31 ( V_104 ) -> V_134 ;
if ( V_5 -> V_134 == 0 ) {
F_22 ( L_41 , V_73 -> V_142 ) ;
return 0 ;
}
F_54 ( V_5 ) ;
return F_46 ( V_5 ) ;
}
static int
F_64 ( const struct V_143 * V_144 , const char * V_16 , int V_145 )
{
struct V_4 * V_5 = (struct V_4 * ) V_144 -> V_2 ;
if ( V_145 ) {
V_5 -> V_78 = true ;
return 0 ;
}
return F_65 ( V_16 ) ;
}
int
F_66 ( const struct V_143 * V_144 V_59 ,
const char * V_16 , int V_145 V_59 )
{
if ( V_16 ) {
int V_17 = regcomp ( & V_146 , V_16 , V_147 ) ;
if ( V_17 ) {
char V_99 [ V_148 ] ;
regerror ( V_17 , & V_146 , V_99 , sizeof( V_99 ) ) ;
F_67 ( L_42 , V_16 , V_99 ) ;
return - 1 ;
}
V_149 = 1 ;
}
return 0 ;
}
static int
F_68 ( const struct V_143 * V_144 V_59 ,
const char * T_5 V_59 , int V_145 )
{
int * V_150 = V_144 -> V_2 ;
* V_150 = ! V_145 ;
return 0 ;
}
static int
F_69 ( const struct V_143 * V_144 , const char * T_5 ,
int V_145 V_59 )
{
struct V_4 * V_5 = V_144 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_70 ( int V_151 , const char * * V_152 , const char * T_6 V_59 )
{
struct V_68 * V_69 ;
struct V_153 V_154 ;
bool V_155 = false ;
int V_150 = - 1 ;
bool V_156 = false ;
char V_157 [] = L_43 ;
const char * const V_158 [] = {
L_44 ,
NULL
} ;
struct V_4 V_4 = {
. V_36 = {
. V_40 = F_9 ,
. V_159 = V_160 ,
. V_161 = V_162 ,
. V_163 = V_164 ,
. exit = V_165 ,
. V_166 = V_167 ,
. V_168 = V_169 ,
. V_63 = F_15 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
. V_176 = true ,
. V_177 = true ,
} ,
. V_58 = V_178 ,
. V_113 = L_45 ,
} ;
const struct V_143 V_179 [] = {
F_71 ( 'i' , L_46 , & V_180 , L_47 ,
L_48 ) ,
F_72 ( 'v' , L_49 , & V_140 ,
L_50 ) ,
F_73 ( 'D' , L_51 , & V_141 ,
L_52 ) ,
F_71 ( 'k' , L_53 , & V_6 . V_181 ,
L_47 , L_54 ) ,
F_71 ( 0 , L_55 , & V_6 . V_182 ,
L_47 , L_56 ) ,
F_73 ( 'f' , L_57 , & V_4 . V_183 , L_58 ) ,
F_73 ( 'm' , L_59 , & V_6 . V_184 ,
L_60 ) ,
F_73 ( 'n' , L_61 , & V_6 . V_185 ,
L_62 ) ,
F_73 ( 'T' , L_63 , & V_4 . V_60 ,
L_64 ) ,
F_71 ( 0 , L_65 , & V_4 . V_113 , L_66 ,
L_67 ) ,
F_73 ( 0 , L_68 , & V_4 . V_186 , L_69 ) ,
F_73 ( 0 , L_70 , & V_4 . V_187 , L_71 ) ,
F_73 ( 0 , L_72 , & V_4 . V_188 ,
L_73 ) ,
F_73 ( 0 , L_74 , & V_4 . V_45 , L_75 ) ,
F_73 ( 0 , L_76 , & V_4 . V_189 ,
L_77 ) ,
F_71 ( 's' , L_78 , & V_106 , L_79 ,
L_80
L_81 ) ,
F_71 ( 'F' , L_82 , & V_190 , L_83 ,
L_84 ) ,
F_73 ( 0 , L_85 , & V_6 . V_191 ,
L_86 ) ,
F_71 ( 'p' , L_87 , & V_110 , L_88 ,
L_89 ) ,
F_73 ( 'x' , L_90 , & V_6 . V_192 ,
L_91 ) ,
F_74 ( 'g' , L_92 , & V_4 , L_93 ,
L_94
L_95 , & F_64 , V_157 ) ,
F_73 ( 0 , L_96 , & V_6 . V_9 ,
L_97 ) ,
F_75 ( 0 , L_98 , & V_4 . V_58 ,
L_99
L_100
L_101 F_76 ( V_178 ) ) ,
F_73 ( 'G' , L_102 , & V_4 . V_193 ,
L_103 ) ,
F_77 ( 0 , L_104 , NULL , L_88 ,
L_105 ,
F_66 ) ,
F_71 ( 'd' , L_106 , & V_6 . V_194 , L_107 ,
L_108 ) ,
F_71 ( 'c' , L_109 , & V_6 . V_195 , L_110 ,
L_111 ) ,
F_71 ( 0 , L_112 , & V_6 . V_196 , L_113 ,
L_114 ) ,
F_71 ( 0 , L_115 , & V_6 . V_197 , L_116 ,
L_117 ) ,
F_71 ( 'S' , L_118 , & V_6 . V_198 , L_119 ,
L_120 ) ,
F_71 ( 0 , L_121 , & V_4 . V_135 , L_122 ,
L_123 ) ,
F_71 ( 'w' , L_124 , & V_6 . V_199 ,
L_125 ,
L_126 ) ,
F_78 ( 't' , L_127 , & V_6 . V_200 , L_128 ,
L_129
L_130 ) ,
F_73 ( 'U' , L_131 , & V_4 . V_42 ,
L_132 ) ,
F_71 ( 0 , L_133 , & V_6 . V_201 , L_134 ,
L_135 ) ,
F_71 ( 'C' , L_136 , & V_4 . V_47 , L_136 ,
L_137 ) ,
F_73 ( 'I' , L_138 , & V_4 . V_202 ,
L_139 ) ,
F_73 ( 0 , L_140 , & V_6 . V_203 ,
L_141 ) ,
F_73 ( 0 , L_142 , & V_6 . V_204 ,
L_143 ) ,
F_71 ( 'M' , L_144 , & V_205 , L_145 ,
L_146 ) ,
F_73 ( 0 , L_147 , & V_6 . V_206 ,
L_148 ) ,
F_73 ( 0 , L_149 , & V_6 . V_7 ,
L_150 ) ,
F_79 ( 'b' , L_151 , & V_150 , L_152 ,
L_153 ,
F_68 ) ,
F_73 ( 0 , L_154 , & V_156 ,
L_155 ) ,
F_71 ( 0 , L_156 , & V_207 , L_157 ,
L_158 ) ,
F_73 ( 0 , L_159 , & V_6 . V_208 ,
L_160 ) ,
F_73 ( 0 , L_161 , & V_6 . V_209 ,
L_162 ) ,
F_73 ( 0 , L_163 , & V_4 . V_32 , L_164 ) ,
F_77 ( 0 , L_165 , & V_4 , L_166 ,
L_167 , F_69 ) ,
F_77 ( 0 , L_168 , NULL , L_169 ,
L_170 , V_210 ) ,
F_80 ()
} ;
struct V_138 V_73 = {
. V_80 = V_211 ,
} ;
int V_44 = F_81 () ;
if ( V_44 < 0 )
return V_44 ;
F_82 ( F_1 , & V_4 ) ;
V_151 = F_83 ( V_151 , V_152 , V_179 , V_158 , 0 ) ;
if ( V_4 . V_188 )
V_129 = 0 ;
else if ( V_4 . V_186 )
V_129 = 1 ;
else if ( V_4 . V_187 )
V_129 = 2 ;
if ( V_4 . V_193 )
V_79 . V_212 = V_213 ;
if ( ! V_180 || ! strlen ( V_180 ) ) {
if ( ! F_84 ( V_214 , & V_154 ) && F_85 ( V_154 . V_215 ) )
V_180 = L_171 ;
else
V_180 = L_172 ;
}
V_73 . V_142 = V_180 ;
V_73 . V_183 = V_4 . V_183 ;
V_216:
V_69 = F_86 ( & V_73 , false , & V_4 . V_36 ) ;
if ( V_69 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_87 ( & V_69 -> V_176 ,
V_4 . V_10 ) ;
}
V_4 . V_69 = V_69 ;
V_155 = F_88 ( & V_69 -> V_45 ,
V_217 ) ;
if ( ( ( V_150 == - 1 && V_155 ) || V_150 == 1 ) &&
! V_156 ) {
V_26 = V_27 ;
V_6 . V_9 = false ;
}
if ( V_156 ) {
V_79 . V_218 = V_219 ;
V_79 . V_220 = 1 ;
V_6 . V_77 = true ;
F_23 ( & V_79 ) ;
if ( V_106 == NULL )
V_106 = L_173 ;
}
if ( V_4 . V_32 ) {
if ( V_26 == V_27 ) {
F_67 ( L_174 ) ;
goto error;
}
V_26 = V_221 ;
V_6 . V_9 = false ;
}
if ( F_89 () < 0 ) {
if ( V_106 )
F_90 ( V_158 , V_179 , L_175 , 1 ) ;
if ( V_190 )
F_90 ( V_106 ? NULL : V_158 ,
V_179 , L_176 , 1 ) ;
goto error;
}
if ( V_4 . V_45 || V_4 . V_189 )
V_129 = 0 ;
if ( strcmp ( V_180 , L_171 ) != 0 )
F_91 ( true ) ;
else
V_129 = 0 ;
if ( V_4 . V_45 || V_4 . V_189 ) {
F_92 ( V_69 , stdout ,
V_4 . V_202 ) ;
if ( V_4 . V_189 )
return 0 ;
} else if ( V_129 == 0 ) {
fputs ( L_177 ,
stdout ) ;
}
if ( F_6 () ) {
V_6 . V_222 = sizeof( struct V_223 ) ;
F_93 ( & V_69 -> V_115 ,
V_224 ) ;
if ( V_140 ) {
V_6 . V_222 += sizeof( V_225 ) ;
V_6 . V_226 = true ;
}
}
if ( F_94 ( & V_69 -> V_45 . V_130 ) < 0 )
goto error;
if ( V_151 ) {
if ( V_151 > 1 )
F_95 ( V_158 , V_179 ) ;
V_4 . V_135 = V_152 [ 0 ] ;
}
F_96 ( stdout ) ;
V_44 = F_56 ( & V_4 ) ;
if ( V_44 == V_131 ) {
F_97 ( V_69 ) ;
goto V_216;
} else
V_44 = 0 ;
error:
F_97 ( V_69 ) ;
return V_44 ;
}
