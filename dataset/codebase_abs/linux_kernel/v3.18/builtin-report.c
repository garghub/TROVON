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
static void F_5 ( struct V_4 * V_5 , struct V_11 * V_12 )
{
if ( V_12 -> V_13 . V_14 == 1 )
V_5 -> V_15 ++ ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 , bool V_20 ,
void * V_21 )
{
int V_22 = 0 ;
struct V_4 * V_5 = V_21 ;
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_23 * V_24 = V_17 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_5 ( V_5 , V_12 ) ;
if ( ! F_7 () )
return 0 ;
if ( V_29 == V_30 ) {
V_28 = V_12 -> V_27 ;
V_22 = F_8 ( & V_28 -> V_31 , V_24 -> V_32 ) ;
if ( V_22 )
goto V_33;
V_22 = F_8 ( & V_28 -> V_34 , V_24 -> V_32 ) ;
} else if ( V_5 -> V_35 ) {
V_26 = V_12 -> V_25 ;
V_22 = F_8 ( & V_26 -> V_36 , V_24 -> V_32 ) ;
if ( V_22 )
goto V_33;
V_22 = F_9 ( V_12 , V_24 -> V_32 , V_19 -> V_37 ) ;
} else if ( V_6 . V_9 ) {
if ( V_20 )
V_22 = F_9 ( V_12 , V_24 -> V_32 ,
V_19 -> V_37 ) ;
} else {
V_22 = F_9 ( V_12 , V_24 -> V_32 , V_19 -> V_37 ) ;
}
V_33:
return V_22 ;
}
static int F_10 ( struct V_38 * V_39 ,
union V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_23 * V_24 ,
struct V_44 * V_44 )
{
struct V_4 * V_5 = F_11 ( V_39 , struct V_4 , V_39 ) ;
struct V_18 V_19 ;
struct V_16 V_17 = {
. V_45 = V_5 -> V_45 ,
. V_46 = F_6 ,
} ;
int V_47 ;
if ( F_12 ( V_41 , V_44 , & V_19 , V_43 ) < 0 ) {
F_13 ( L_5 ,
V_41 -> V_48 . type ) ;
return - 1 ;
}
if ( V_5 -> V_45 && V_19 . V_49 == NULL )
return 0 ;
if ( V_5 -> V_50 && ! F_14 ( V_43 -> V_51 , V_5 -> V_52 ) )
return 0 ;
if ( V_29 == V_30 )
V_17 . V_53 = & V_54 ;
else if ( V_5 -> V_35 )
V_17 . V_53 = & V_55 ;
else if ( V_6 . V_9 )
V_17 . V_53 = & V_56 ;
else
V_17 . V_53 = & V_57 ;
if ( V_19 . V_58 != NULL )
V_19 . V_58 -> V_59 -> V_60 = 1 ;
V_47 = F_15 ( & V_17 , & V_19 , V_24 , V_43 , V_5 -> V_61 ,
V_5 ) ;
if ( V_47 < 0 )
F_13 ( L_6 ) ;
return V_47 ;
}
static int F_16 ( struct V_38 * V_39 ,
union V_40 * V_41 ,
struct V_42 * V_43 V_62 ,
struct V_23 * V_24 ,
struct V_44 * V_44 V_62 )
{
struct V_4 * V_5 = F_11 ( V_39 , struct V_4 , V_39 ) ;
if ( V_5 -> V_63 ) {
const char * V_64 = V_24 ? F_17 ( V_24 ) : L_7 ;
F_18 ( & V_5 -> V_65 ,
V_41 -> V_66 . V_67 , V_41 -> V_66 . V_68 ,
V_41 -> V_66 . V_69 ,
V_64 ,
V_41 -> V_66 . V_2 ) ;
}
F_19 ( L_8 V_70 L_9 , V_41 -> V_66 . V_67 , V_41 -> V_66 . V_68 ,
V_24 ? F_17 ( V_24 ) : L_10 ,
V_41 -> V_66 . V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_71 * V_72 = V_5 -> V_72 ;
T_1 V_73 = F_21 ( V_72 -> V_74 ) ;
bool V_75 = F_22 ( V_72 -> V_76 ) ;
if ( ! V_75 && ! ( V_73 & V_77 ) ) {
if ( V_78 ) {
F_23 ( L_11
L_12
L_13 ) ;
return - V_79 ;
}
if ( V_6 . V_80 ) {
F_23 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_5 -> V_81 &&
V_82 . V_83 != V_84 &&
! V_6 . V_80 ) {
V_6 . V_80 = true ;
if ( F_24 ( & V_82 ) < 0 ) {
F_23 ( L_16 ) ;
return - V_79 ;
}
}
if ( V_6 . V_9 ) {
if ( ! ( V_73 & V_77 ) ) {
V_6 . V_9 = false ;
F_25 () ;
}
}
if ( V_29 == V_30 ) {
if ( ! V_75 &&
! ( V_73 & V_85 ) ) {
F_23 ( L_17
L_18 ) ;
return - 1 ;
}
}
if ( V_6 . V_80 || V_6 . V_9 ) {
if ( ( V_73 & V_86 ) &&
( V_73 & V_87 ) )
V_82 . V_88 = V_89 ;
else
V_82 . V_88 = V_90 ;
}
return 0 ;
}
static void F_26 ( int T_2 V_62 )
{
V_91 = 1 ;
}
static T_3 F_27 ( struct V_92 * V_92 , struct V_4 * V_5 ,
const char * V_93 , T_4 * V_94 )
{
T_3 V_47 ;
char V_95 ;
unsigned long V_96 = V_92 -> V_97 . V_14 [ V_98 ] ;
T_1 V_14 = V_92 -> V_97 . V_99 ;
struct V_23 * V_24 = F_28 ( V_92 ) ;
char V_100 [ 512 ] ;
T_3 V_101 = sizeof( V_100 ) ;
if ( V_6 . V_102 ) {
V_96 = V_92 -> V_97 . V_103 ;
V_14 = V_92 -> V_97 . V_104 ;
}
if ( F_29 ( V_24 ) ) {
struct V_23 * V_105 ;
F_30 ( V_24 , V_100 , V_101 ) ;
V_93 = V_100 ;
F_31 (pos, evsel) {
const struct V_92 * V_106 = F_32 ( V_105 ) ;
if ( V_6 . V_102 ) {
V_96 += V_106 -> V_97 . V_103 ;
V_14 += V_106 -> V_97 . V_104 ;
} else {
V_96 += V_106 -> V_97 . V_14 [ V_98 ] ;
V_14 += V_106 -> V_97 . V_99 ;
}
}
}
V_96 = F_33 ( V_96 , & V_95 ) ;
V_47 = fprintf ( V_94 , L_19 , V_96 , V_95 ) ;
if ( V_93 != NULL )
V_47 += fprintf ( V_94 , L_20 , V_93 ) ;
if ( V_5 -> V_35 ) {
V_47 += fprintf ( V_94 , L_21 V_70 , V_14 ) ;
V_47 += fprintf ( V_94 , L_22 , V_107 ) ;
} else
V_47 += fprintf ( V_94 , L_23 V_70 , V_14 ) ;
return V_47 + fprintf ( V_94 , L_24 ) ;
}
static int F_34 ( struct V_108 * V_74 ,
struct V_4 * V_5 ,
const char * V_109 )
{
struct V_23 * V_105 ;
F_35 (evlist, pos) {
struct V_92 * V_92 = F_32 ( V_105 ) ;
const char * V_93 = F_17 ( V_105 ) ;
if ( V_6 . V_7 &&
! F_36 ( V_105 ) )
continue;
F_27 ( V_92 , V_5 , V_93 , stdout ) ;
F_37 ( V_92 , true , 0 , 0 , V_5 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_107 == V_110 &&
V_111 == V_112 ) {
fprintf ( stdout , L_26 , V_109 ) ;
if ( V_5 -> V_63 ) {
bool V_113 = ! strcmp ( V_5 -> V_114 , L_27 ) ;
F_38 ( stdout , & V_5 -> V_65 ,
V_113 ) ;
F_39 ( & V_5 -> V_65 ) ;
}
}
return 0 ;
}
static void F_40 ( const struct V_4 * V_5 )
{
struct V_58 * V_115 = V_5 -> V_72 -> V_116 . V_117 . V_118 [ V_119 ] ;
struct V_120 * V_121 = F_41 ( V_115 ) ;
if ( V_115 == NULL ||
( V_115 -> V_59 -> V_60 &&
( V_121 -> V_122 == NULL ||
V_121 -> V_122 -> V_37 == 0 ) ) ) {
const char * V_123 =
L_28
L_29 ;
if ( V_115 ) {
const struct V_59 * V_124 = V_115 -> V_59 ;
if ( ! F_42 ( & V_124 -> V_125 [ V_119 ] ) ) {
V_123 = L_30
L_31 ;
}
}
F_43 (
L_32
L_33
L_34 ,
V_123 ) ;
}
}
static int F_44 ( struct V_4 * V_5 , const char * V_109 )
{
int (* F_45)( struct V_108 * V_74 , const char * V_109 ,
struct V_126 * V_127 , float V_128 );
F_45 = F_46 ( V_129 , L_35 ) ;
if ( F_45 == NULL ) {
F_23 ( L_36 ) ;
return - 1 ;
}
return F_45 ( V_5 -> V_72 -> V_74 , V_109 , NULL , V_5 -> V_8 ) ;
}
static int F_47 ( struct V_4 * V_5 )
{
int V_47 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_108 * V_74 = V_72 -> V_74 ;
const char * V_109 = L_37 ;
switch ( V_130 ) {
case 1 :
V_47 = F_48 ( V_74 , V_109 , NULL ,
V_5 -> V_8 ,
& V_72 -> V_48 . V_131 ) ;
if ( V_47 != V_132 )
V_47 = 0 ;
break;
case 2 :
V_47 = F_44 ( V_5 , V_109 ) ;
break;
default:
V_47 = F_34 ( V_74 , V_5 , V_109 ) ;
break;
}
return V_47 ;
}
static void F_49 ( struct V_4 * V_5 )
{
struct V_133 V_134 ;
struct V_23 * V_105 ;
F_50 ( & V_134 , V_5 -> V_15 , L_38 ) ;
F_35 (rep->session->evlist, pos) {
struct V_92 * V_92 = F_32 ( V_105 ) ;
if ( V_105 -> V_32 == 0 )
V_92 -> V_135 = V_5 -> V_135 ;
F_51 ( V_92 , & V_134 ) ;
if ( V_6 . V_7 &&
! F_36 ( V_105 ) ) {
struct V_92 * V_136 = F_32 ( V_105 -> V_137 ) ;
F_52 ( V_136 , V_92 ) ;
F_53 ( V_136 , V_92 ) ;
}
}
F_54 () ;
}
static int F_55 ( struct V_4 * V_5 )
{
int V_47 ;
struct V_71 * V_72 = V_5 -> V_72 ;
struct V_23 * V_105 ;
struct V_138 * V_76 = V_72 -> V_76 ;
signal ( V_139 , F_26 ) ;
if ( V_5 -> V_50 ) {
V_47 = F_56 ( V_72 , V_5 -> V_50 ,
V_5 -> V_52 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_5 -> V_63 )
F_57 ( & V_5 -> V_65 ) ;
V_47 = F_20 ( V_5 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_58 ( V_72 , & V_5 -> V_39 ) ;
if ( V_47 )
return V_47 ;
F_40 ( V_5 ) ;
if ( V_130 == 0 ) {
if ( V_140 > 3 )
F_59 ( V_72 , stdout ) ;
if ( V_140 > 2 )
F_60 ( V_72 , stdout ) ;
if ( V_141 ) {
F_61 ( V_72 , stdout ) ;
F_62 ( V_72 -> V_74 , stdout ) ;
return 0 ;
}
}
F_49 ( V_5 ) ;
if ( V_91 () )
return 0 ;
if ( V_5 -> V_15 == 0 ) {
F_23 ( L_39 , V_76 -> V_142 ) ;
return 0 ;
}
F_35 (session->evlist, pos)
F_63 ( F_32 ( V_105 ) ) ;
return F_47 ( V_5 ) ;
}
static int
F_64 ( const struct V_143 * V_144 , const char * V_21 , int V_145 )
{
struct V_4 * V_5 = (struct V_4 * ) V_144 -> V_2 ;
if ( V_145 ) {
V_5 -> V_81 = true ;
return 0 ;
}
return F_65 ( V_21 ) ;
}
int
F_66 ( const struct V_143 * V_144 V_62 ,
const char * V_21 , int V_145 V_62 )
{
if ( V_21 ) {
int V_22 = regcomp ( & V_146 , V_21 , V_147 ) ;
if ( V_22 ) {
char V_100 [ V_148 ] ;
regerror ( V_22 , & V_146 , V_100 , sizeof( V_100 ) ) ;
F_67 ( L_40 , V_21 , V_100 ) ;
return - 1 ;
}
V_149 = 1 ;
}
return 0 ;
}
static int
F_68 ( const struct V_143 * V_144 V_62 ,
const char * T_5 V_62 , int V_145 )
{
int * V_150 = V_144 -> V_2 ;
* V_150 = ! V_145 ;
return 0 ;
}
static int
F_69 ( const struct V_143 * V_144 , const char * T_5 ,
int V_145 V_62 )
{
struct V_4 * V_5 = V_144 -> V_2 ;
V_5 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_70 ( int V_151 , const char * * V_152 , const char * T_6 V_62 )
{
struct V_71 * V_72 ;
struct V_13 V_153 ;
bool V_154 = false ;
int V_150 = - 1 ;
char V_155 [] = L_41 ;
const char * const V_156 [] = {
L_42 ,
NULL
} ;
struct V_4 V_4 = {
. V_39 = {
. V_43 = F_10 ,
. V_157 = V_158 ,
. V_159 = V_160 ,
. V_161 = V_162 ,
. exit = V_163 ,
. V_164 = V_165 ,
. V_166 = V_167 ,
. V_66 = F_16 ,
. V_168 = V_169 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = true ,
. V_175 = true ,
} ,
. V_61 = V_176 ,
. V_114 = L_43 ,
} ;
const struct V_143 V_177 [] = {
F_71 ( 'i' , L_44 , & V_178 , L_45 ,
L_46 ) ,
F_72 ( 'v' , L_47 , & V_140 ,
L_48 ) ,
F_73 ( 'D' , L_49 , & V_141 ,
L_50 ) ,
F_71 ( 'k' , L_51 , & V_6 . V_179 ,
L_45 , L_52 ) ,
F_71 ( 0 , L_53 , & V_6 . V_180 ,
L_45 , L_54 ) ,
F_73 ( 'f' , L_55 , & V_4 . V_181 , L_56 ) ,
F_73 ( 'm' , L_57 , & V_6 . V_182 ,
L_58 ) ,
F_73 ( 'n' , L_59 , & V_6 . V_183 ,
L_60 ) ,
F_73 ( 'T' , L_61 , & V_4 . V_63 ,
L_62 ) ,
F_71 ( 0 , L_63 , & V_4 . V_114 , L_64 ,
L_65 ) ,
F_73 ( 0 , L_66 , & V_4 . V_184 , L_67 ) ,
F_73 ( 0 , L_68 , & V_4 . V_185 , L_69 ) ,
F_73 ( 0 , L_70 , & V_4 . V_186 ,
L_71 ) ,
F_73 ( 0 , L_72 , & V_4 . V_48 , L_73 ) ,
F_73 ( 0 , L_74 , & V_4 . V_187 ,
L_75 ) ,
F_71 ( 's' , L_76 , & V_107 , L_77 ,
L_78
L_79 ) ,
F_71 ( 'F' , L_80 , & V_188 , L_81 ,
L_82 ) ,
F_73 ( 0 , L_83 , & V_6 . V_189 ,
L_84 ) ,
F_71 ( 'p' , L_85 , & V_111 , L_86 ,
L_87 ) ,
F_73 ( 'x' , L_88 , & V_6 . V_190 ,
L_89 ) ,
F_74 ( 'g' , L_90 , & V_4 , L_91 ,
L_92
L_93 , & F_64 , V_155 ) ,
F_73 ( 0 , L_94 , & V_6 . V_9 ,
L_95 ) ,
F_75 ( 0 , L_96 , & V_4 . V_61 ,
L_97
L_98
L_99 F_76 ( V_176 ) ) ,
F_73 ( 'G' , L_100 , & V_4 . V_191 ,
L_101 ) ,
F_77 ( 0 , L_102 , NULL , L_86 ,
L_103 ,
F_66 ) ,
F_71 ( 'd' , L_104 , & V_6 . V_192 , L_105 ,
L_106 ) ,
F_71 ( 'c' , L_107 , & V_6 . V_193 , L_108 ,
L_109 ) ,
F_71 ( 'S' , L_110 , & V_6 . V_194 , L_111 ,
L_112 ) ,
F_71 ( 0 , L_113 , & V_4 . V_135 , L_114 ,
L_115 ) ,
F_71 ( 'w' , L_116 , & V_6 . V_195 ,
L_117 ,
L_118 ) ,
F_71 ( 't' , L_119 , & V_6 . V_196 , L_120 ,
L_121
L_122 ) ,
F_73 ( 'U' , L_123 , & V_4 . V_45 ,
L_124 ) ,
F_71 ( 0 , L_125 , & V_6 . V_197 , L_126 ,
L_127 ) ,
F_71 ( 'C' , L_128 , & V_4 . V_50 , L_128 ,
L_129 ) ,
F_73 ( 'I' , L_130 , & V_4 . V_198 ,
L_131 ) ,
F_73 ( 0 , L_132 , & V_6 . V_199 ,
L_133 ) ,
F_73 ( 0 , L_134 , & V_6 . V_200 ,
L_135 ) ,
F_71 ( 'M' , L_136 , & V_201 , L_137 ,
L_138 ) ,
F_73 ( 0 , L_139 , & V_6 . V_202 ,
L_140 ) ,
F_73 ( 0 , L_141 , & V_6 . V_7 ,
L_142 ) ,
F_78 ( 'b' , L_143 , & V_150 , L_144 ,
L_145 , F_68 ) ,
F_71 ( 0 , L_146 , & V_203 , L_147 ,
L_148 ) ,
F_73 ( 0 , L_149 , & V_6 . V_204 ,
L_150 ) ,
F_73 ( 0 , L_151 , & V_6 . V_205 ,
L_152 ) ,
F_73 ( 0 , L_153 , & V_4 . V_35 , L_154 ) ,
F_77 ( 0 , L_155 , & V_4 , L_156 ,
L_157 , F_69 ) ,
F_77 ( 0 , L_158 , NULL , L_159 ,
L_160 , V_206 ) ,
F_79 ()
} ;
struct V_138 V_76 = {
. V_83 = V_207 ,
} ;
int V_47 = F_80 () ;
if ( V_47 < 0 )
return V_47 ;
F_81 ( F_1 , & V_4 ) ;
V_151 = F_82 ( V_151 , V_152 , V_177 , V_156 , 0 ) ;
if ( V_4 . V_186 )
V_130 = 0 ;
else if ( V_4 . V_184 )
V_130 = 1 ;
else if ( V_4 . V_185 )
V_130 = 2 ;
if ( V_4 . V_191 )
V_82 . V_208 = V_209 ;
if ( ! V_178 || ! strlen ( V_178 ) ) {
if ( ! F_83 ( V_210 , & V_153 ) && F_84 ( V_153 . V_211 ) )
V_178 = L_161 ;
else
V_178 = L_162 ;
}
V_76 . V_142 = V_178 ;
V_76 . V_181 = V_4 . V_181 ;
V_212:
V_72 = F_85 ( & V_76 , false , & V_4 . V_39 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( V_4 . V_10 ) {
F_86 ( & V_72 -> V_174 ,
V_4 . V_10 ) ;
}
V_4 . V_72 = V_72 ;
V_154 = F_87 ( & V_72 -> V_48 ,
V_213 ) ;
if ( ( V_150 == - 1 && V_154 ) || V_150 == 1 ) {
V_29 = V_30 ;
V_6 . V_9 = false ;
}
if ( V_4 . V_35 ) {
if ( V_29 == V_30 ) {
F_67 ( L_163 ) ;
goto error;
}
V_29 = V_214 ;
V_6 . V_9 = false ;
}
if ( F_88 () < 0 ) {
if ( V_107 )
F_89 ( V_156 , V_177 , L_164 , 1 ) ;
if ( V_188 )
F_89 ( V_107 ? NULL : V_156 ,
V_177 , L_165 , 1 ) ;
goto error;
}
if ( V_4 . V_48 || V_4 . V_187 )
V_130 = 0 ;
if ( strcmp ( V_178 , L_161 ) != 0 )
F_90 ( true ) ;
else
V_130 = 0 ;
if ( V_4 . V_48 || V_4 . V_187 ) {
F_91 ( V_72 , stdout ,
V_4 . V_198 ) ;
if ( V_4 . V_187 )
return 0 ;
} else if ( V_130 == 0 ) {
fputs ( L_166 ,
stdout ) ;
}
if ( F_7 () ) {
V_6 . V_215 = sizeof( struct V_216 ) ;
F_92 ( & V_72 -> V_116 ,
V_217 ) ;
if ( V_140 ) {
V_6 . V_215 += sizeof( V_218 ) ;
V_6 . V_219 = true ;
}
}
if ( F_93 ( & V_72 -> V_48 . V_131 ) < 0 )
goto error;
if ( V_151 ) {
if ( V_151 > 1 )
F_94 ( V_156 , V_177 ) ;
V_4 . V_135 = V_152 [ 0 ] ;
}
F_95 ( stdout ) ;
V_47 = F_55 ( & V_4 ) ;
if ( V_47 == V_132 ) {
F_96 ( V_72 ) ;
goto V_212;
} else
V_47 = 0 ;
error:
F_96 ( V_72 ) ;
return V_47 ;
}
