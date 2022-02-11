static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
if ( ! strcmp ( V_1 , L_1 ) ) {
V_4 . V_5 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_2 ) ) {
struct V_6 * V_7 = V_3 ;
V_7 -> V_8 = strtof ( V_2 , NULL ) ;
return 0 ;
}
if ( ! strcmp ( V_1 , L_3 ) ) {
V_4 . V_9 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
return F_3 ( V_1 , V_2 , V_3 ) ;
}
static void F_4 ( struct V_6 * V_7 , struct V_10 * V_11 )
{
if ( V_11 -> V_12 . V_13 == 1 )
V_7 -> V_14 ++ ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 , bool V_19 ,
void * V_20 )
{
int V_21 = 0 ;
struct V_6 * V_7 = V_20 ;
struct V_10 * V_11 = V_16 -> V_11 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
F_4 ( V_7 , V_11 ) ;
if ( ! F_6 () )
return 0 ;
if ( V_28 == V_29 ) {
V_27 = V_11 -> V_26 ;
V_21 = F_7 ( & V_27 -> V_30 , V_23 -> V_31 ) ;
if ( V_21 )
goto V_32;
V_21 = F_7 ( & V_27 -> V_33 , V_23 -> V_31 ) ;
} else if ( V_7 -> V_34 ) {
V_25 = V_11 -> V_24 ;
V_21 = F_7 ( & V_25 -> V_35 , V_23 -> V_31 ) ;
if ( V_21 )
goto V_32;
V_21 = F_8 ( V_11 , V_23 -> V_31 , V_18 -> V_36 ) ;
} else if ( V_4 . V_9 ) {
if ( V_19 )
V_21 = F_8 ( V_11 , V_23 -> V_31 ,
V_18 -> V_36 ) ;
} else {
V_21 = F_8 ( V_11 , V_23 -> V_31 , V_18 -> V_36 ) ;
}
V_32:
return V_21 ;
}
static int F_9 ( struct V_37 * V_38 ,
union V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_22 * V_23 ,
struct V_43 * V_43 )
{
struct V_6 * V_7 = F_10 ( V_38 , struct V_6 , V_38 ) ;
struct V_17 V_18 ;
struct V_15 V_16 = {
. V_44 = V_7 -> V_44 ,
. V_45 = F_5 ,
} ;
int V_46 ;
if ( F_11 ( V_40 , V_43 , & V_18 , V_42 ) < 0 ) {
F_12 ( L_4 ,
V_40 -> V_47 . type ) ;
return - 1 ;
}
if ( V_7 -> V_44 && V_18 . V_48 == NULL )
return 0 ;
if ( V_7 -> V_49 && ! F_13 ( V_42 -> V_50 , V_7 -> V_51 ) )
return 0 ;
if ( V_28 == V_29 )
V_16 . V_52 = & V_53 ;
else if ( V_7 -> V_34 )
V_16 . V_52 = & V_54 ;
else if ( V_4 . V_9 )
V_16 . V_52 = & V_55 ;
else
V_16 . V_52 = & V_56 ;
if ( V_18 . V_57 != NULL )
V_18 . V_57 -> V_58 -> V_59 = 1 ;
V_46 = F_14 ( & V_16 , & V_18 , V_23 , V_42 , V_7 -> V_60 ,
V_7 ) ;
if ( V_46 < 0 )
F_12 ( L_5 ) ;
return V_46 ;
}
static int F_15 ( struct V_37 * V_38 ,
union V_39 * V_40 ,
struct V_41 * V_42 V_61 ,
struct V_22 * V_23 ,
struct V_43 * V_43 V_61 )
{
struct V_6 * V_7 = F_10 ( V_38 , struct V_6 , V_38 ) ;
if ( V_7 -> V_62 ) {
const char * V_63 = V_23 ? F_16 ( V_23 ) : L_6 ;
F_17 ( & V_7 -> V_64 ,
V_40 -> V_65 . V_66 , V_40 -> V_65 . V_67 ,
V_40 -> V_65 . V_68 ,
V_63 ,
V_40 -> V_65 . V_2 ) ;
}
F_18 ( L_7 V_69 L_8 , V_40 -> V_65 . V_66 , V_40 -> V_65 . V_67 ,
V_23 ? F_16 ( V_23 ) : L_9 ,
V_40 -> V_65 . V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_70 * V_71 = V_7 -> V_71 ;
T_1 V_72 = F_20 ( V_71 -> V_73 ) ;
bool V_74 = F_21 ( V_71 -> V_75 ) ;
if ( ! V_74 && ! ( V_72 & V_76 ) ) {
if ( V_77 ) {
F_22 ( L_10
L_11
L_12 ) ;
return - V_78 ;
}
if ( V_4 . V_79 ) {
F_22 ( L_13
L_14 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_80 &&
V_81 . V_82 != V_83 &&
! V_4 . V_79 ) {
V_4 . V_79 = true ;
if ( F_23 ( & V_81 ) < 0 ) {
F_22 ( L_15 ) ;
return - V_78 ;
}
}
if ( V_4 . V_9 ) {
if ( ! ( V_72 & V_76 ) ) {
V_4 . V_9 = false ;
F_24 () ;
}
}
if ( V_28 == V_29 ) {
if ( ! V_74 &&
! ( V_72 & V_84 ) ) {
F_22 ( L_16
L_17 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_25 ( int T_2 V_61 )
{
V_85 = 1 ;
}
static T_3 F_26 ( struct V_86 * V_86 , struct V_6 * V_7 ,
const char * V_87 , T_4 * V_88 )
{
T_3 V_46 ;
char V_89 ;
unsigned long V_90 = V_86 -> V_91 . V_13 [ V_92 ] ;
T_1 V_13 = V_86 -> V_91 . V_93 ;
struct V_22 * V_23 = F_27 ( V_86 ) ;
char V_94 [ 512 ] ;
T_3 V_95 = sizeof( V_94 ) ;
if ( V_4 . V_96 ) {
V_90 = V_86 -> V_91 . V_97 ;
V_13 = V_86 -> V_91 . V_98 ;
}
if ( F_28 ( V_23 ) ) {
struct V_22 * V_99 ;
F_29 ( V_23 , V_94 , V_95 ) ;
V_87 = V_94 ;
F_30 (pos, evsel) {
if ( V_4 . V_96 ) {
V_90 += V_99 -> V_86 . V_91 . V_97 ;
V_13 += V_99 -> V_86 . V_91 . V_98 ;
} else {
V_90 += V_99 -> V_86 . V_91 . V_13 [ V_92 ] ;
V_13 += V_99 -> V_86 . V_91 . V_93 ;
}
}
}
V_90 = F_31 ( V_90 , & V_89 ) ;
V_46 = fprintf ( V_88 , L_18 , V_90 , V_89 ) ;
if ( V_87 != NULL )
V_46 += fprintf ( V_88 , L_19 , V_87 ) ;
if ( V_7 -> V_34 ) {
V_46 += fprintf ( V_88 , L_20 V_69 , V_13 ) ;
V_46 += fprintf ( V_88 , L_21 , V_100 ) ;
} else
V_46 += fprintf ( V_88 , L_22 V_69 , V_13 ) ;
return V_46 + fprintf ( V_88 , L_23 ) ;
}
static int F_32 ( struct V_101 * V_73 ,
struct V_6 * V_7 ,
const char * V_102 )
{
struct V_22 * V_99 ;
F_33 (evlist, pos) {
struct V_86 * V_86 = & V_99 -> V_86 ;
const char * V_87 = F_16 ( V_99 ) ;
if ( V_4 . V_5 &&
! F_34 ( V_99 ) )
continue;
F_26 ( V_86 , V_7 , V_87 , stdout ) ;
F_35 ( V_86 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_24 ) ;
}
if ( V_100 == V_103 &&
V_104 == V_105 ) {
fprintf ( stdout , L_25 , V_102 ) ;
if ( V_7 -> V_62 ) {
bool V_106 = ! strcmp ( V_7 -> V_107 , L_26 ) ;
F_36 ( stdout , & V_7 -> V_64 ,
V_106 ) ;
F_37 ( & V_7 -> V_64 ) ;
}
}
return 0 ;
}
static void F_38 ( const struct V_6 * V_7 )
{
struct V_57 * V_108 = V_7 -> V_71 -> V_109 . V_110 . V_111 [ V_112 ] ;
struct V_113 * V_114 = F_39 ( V_108 ) ;
if ( V_108 == NULL ||
( V_108 -> V_58 -> V_59 &&
( V_114 -> V_115 == NULL ||
V_114 -> V_115 -> V_36 == 0 ) ) ) {
const char * V_116 =
L_27
L_28 ;
if ( V_108 ) {
const struct V_58 * V_117 = V_108 -> V_58 ;
if ( ! F_40 ( & V_117 -> V_118 [ V_112 ] ) ) {
V_116 = L_29
L_30 ;
}
}
F_41 (
L_31
L_32
L_33 ,
V_116 ) ;
}
}
static int F_42 ( struct V_6 * V_7 , const char * V_102 )
{
int (* F_43)( struct V_101 * V_73 , const char * V_102 ,
struct V_119 * V_120 , float V_121 );
F_43 = F_44 ( V_122 , L_34 ) ;
if ( F_43 == NULL ) {
F_22 ( L_35 ) ;
return - 1 ;
}
return F_43 ( V_7 -> V_71 -> V_73 , V_102 , NULL , V_7 -> V_8 ) ;
}
static int F_45 ( struct V_6 * V_7 )
{
int V_46 ;
struct V_70 * V_71 = V_7 -> V_71 ;
struct V_101 * V_73 = V_71 -> V_73 ;
const char * V_102 = L_36 ;
switch ( V_123 ) {
case 1 :
V_46 = F_46 ( V_73 , V_102 , NULL ,
V_7 -> V_8 ,
& V_71 -> V_47 . V_124 ) ;
if ( V_46 != V_125 )
V_46 = 0 ;
break;
case 2 :
V_46 = F_42 ( V_7 , V_102 ) ;
break;
default:
V_46 = F_32 ( V_73 , V_7 , V_102 ) ;
break;
}
return V_46 ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_126 V_127 ;
struct V_22 * V_99 ;
F_48 ( & V_127 , V_7 -> V_14 , L_37 ) ;
F_33 (rep->session->evlist, pos) {
struct V_86 * V_86 = & V_99 -> V_86 ;
if ( V_99 -> V_31 == 0 )
V_86 -> V_128 = V_7 -> V_128 ;
F_49 ( V_86 , & V_127 ) ;
if ( V_4 . V_5 &&
! F_34 ( V_99 ) ) {
struct V_86 * V_129 = & V_99 -> V_130 -> V_86 ;
F_50 ( V_129 , V_86 ) ;
F_51 ( V_129 , V_86 ) ;
}
}
F_52 () ;
}
static int F_53 ( struct V_6 * V_7 )
{
int V_46 ;
struct V_70 * V_71 = V_7 -> V_71 ;
struct V_22 * V_99 ;
struct V_131 * V_75 = V_71 -> V_75 ;
signal ( V_132 , F_25 ) ;
if ( V_7 -> V_49 ) {
V_46 = F_54 ( V_71 , V_7 -> V_49 ,
V_7 -> V_51 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_7 -> V_62 )
F_55 ( & V_7 -> V_64 ) ;
V_46 = F_19 ( V_7 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_56 ( V_71 , & V_7 -> V_38 ) ;
if ( V_46 )
return V_46 ;
F_38 ( V_7 ) ;
if ( V_123 == 0 ) {
if ( V_133 > 3 )
F_57 ( V_71 , stdout ) ;
if ( V_133 > 2 )
F_58 ( V_71 , stdout ) ;
if ( V_134 ) {
F_59 ( V_71 , stdout ) ;
return 0 ;
}
}
F_47 ( V_7 ) ;
if ( V_85 () )
return 0 ;
if ( V_7 -> V_14 == 0 ) {
F_22 ( L_38 , V_75 -> V_135 ) ;
return 0 ;
}
F_33 (session->evlist, pos)
F_60 ( & V_99 -> V_86 ) ;
return F_45 ( V_7 ) ;
}
static int
F_61 ( const struct V_136 * V_137 , const char * V_20 , int V_138 )
{
struct V_6 * V_7 = (struct V_6 * ) V_137 -> V_2 ;
if ( V_138 ) {
V_7 -> V_80 = true ;
return 0 ;
}
return F_62 ( V_20 ) ;
}
int
F_63 ( const struct V_136 * V_137 V_61 ,
const char * V_20 , int V_138 V_61 )
{
if ( V_20 ) {
int V_21 = regcomp ( & V_139 , V_20 , V_140 ) ;
if ( V_21 ) {
char V_94 [ V_141 ] ;
regerror ( V_21 , & V_139 , V_94 , sizeof( V_94 ) ) ;
F_64 ( L_39 , V_20 , V_94 ) ;
return - 1 ;
}
V_142 = 1 ;
}
return 0 ;
}
static int
F_65 ( const struct V_136 * V_137 V_61 ,
const char * T_5 V_61 , int V_138 )
{
int * V_143 = V_137 -> V_2 ;
* V_143 = ! V_138 ;
return 0 ;
}
static int
F_66 ( const struct V_136 * V_137 , const char * T_5 ,
int V_138 V_61 )
{
struct V_6 * V_7 = V_137 -> V_2 ;
V_7 -> V_8 = strtof ( T_5 , NULL ) ;
return 0 ;
}
int F_67 ( int V_144 , const char * * V_145 , const char * T_6 V_61 )
{
struct V_70 * V_71 ;
struct V_12 V_146 ;
bool V_147 = false ;
int V_143 = - 1 ;
int V_46 = - 1 ;
char V_148 [] = L_40 ;
const char * const V_149 [] = {
L_41 ,
NULL
} ;
struct V_6 V_6 = {
. V_38 = {
. V_42 = F_9 ,
. V_150 = V_151 ,
. V_152 = V_153 ,
. V_154 = V_155 ,
. exit = V_156 ,
. V_157 = V_158 ,
. V_159 = V_160 ,
. V_65 = F_15 ,
. V_161 = V_162 ,
. V_163 = V_164 ,
. V_165 = V_166 ,
. V_167 = true ,
. V_168 = true ,
} ,
. V_60 = V_169 ,
. V_107 = L_42 ,
} ;
const struct V_136 V_170 [] = {
F_68 ( 'i' , L_43 , & V_171 , L_44 ,
L_45 ) ,
F_69 ( 'v' , L_46 , & V_133 ,
L_47 ) ,
F_70 ( 'D' , L_48 , & V_134 ,
L_49 ) ,
F_68 ( 'k' , L_50 , & V_4 . V_172 ,
L_44 , L_51 ) ,
F_68 ( 0 , L_52 , & V_4 . V_173 ,
L_44 , L_53 ) ,
F_70 ( 'f' , L_54 , & V_6 . V_174 , L_55 ) ,
F_70 ( 'm' , L_56 , & V_4 . V_175 ,
L_57 ) ,
F_70 ( 'n' , L_58 , & V_4 . V_176 ,
L_59 ) ,
F_70 ( 'T' , L_60 , & V_6 . V_62 ,
L_61 ) ,
F_68 ( 0 , L_62 , & V_6 . V_107 , L_63 ,
L_64 ) ,
F_70 ( 0 , L_65 , & V_6 . V_177 , L_66 ) ,
F_70 ( 0 , L_67 , & V_6 . V_178 , L_68 ) ,
F_70 ( 0 , L_69 , & V_6 . V_179 ,
L_70 ) ,
F_70 ( 0 , L_71 , & V_6 . V_47 , L_72 ) ,
F_70 ( 0 , L_73 , & V_6 . V_180 ,
L_74 ) ,
F_68 ( 's' , L_75 , & V_100 , L_76 ,
L_77
L_78 ) ,
F_68 ( 'F' , L_79 , & V_181 , L_80 ,
L_81 ) ,
F_70 ( 0 , L_82 , & V_4 . V_182 ,
L_83 ) ,
F_68 ( 'p' , L_84 , & V_104 , L_85 ,
L_86 ) ,
F_70 ( 'x' , L_87 , & V_4 . V_183 ,
L_88 ) ,
F_71 ( 'g' , L_89 , & V_6 , L_90 ,
L_91
L_92 , & F_61 , V_148 ) ,
F_70 ( 0 , L_93 , & V_4 . V_9 ,
L_94 ) ,
F_72 ( 0 , L_95 , & V_6 . V_60 ,
L_96
L_97
L_98 F_73 ( V_169 ) ) ,
F_70 ( 'G' , L_99 , & V_6 . V_184 ,
L_100 ) ,
F_74 ( 0 , L_101 , NULL , L_85 ,
L_102 ,
F_63 ) ,
F_68 ( 'd' , L_103 , & V_4 . V_185 , L_104 ,
L_105 ) ,
F_68 ( 'c' , L_106 , & V_4 . V_186 , L_107 ,
L_108 ) ,
F_68 ( 'S' , L_109 , & V_4 . V_187 , L_110 ,
L_111 ) ,
F_68 ( 0 , L_112 , & V_6 . V_128 , L_113 ,
L_114 ) ,
F_68 ( 'w' , L_115 , & V_4 . V_188 ,
L_116 ,
L_117 ) ,
F_68 ( 't' , L_118 , & V_4 . V_189 , L_119 ,
L_120
L_121 ) ,
F_70 ( 'U' , L_122 , & V_6 . V_44 ,
L_123 ) ,
F_68 ( 0 , L_124 , & V_4 . V_190 , L_125 ,
L_126 ) ,
F_68 ( 'C' , L_127 , & V_6 . V_49 , L_127 ,
L_128 ) ,
F_70 ( 'I' , L_129 , & V_6 . V_191 ,
L_130 ) ,
F_70 ( 0 , L_131 , & V_4 . V_192 ,
L_132 ) ,
F_70 ( 0 , L_133 , & V_4 . V_193 ,
L_134 ) ,
F_68 ( 'M' , L_135 , & V_194 , L_136 ,
L_137 ) ,
F_70 ( 0 , L_138 , & V_4 . V_195 ,
L_139 ) ,
F_70 ( 0 , L_140 , & V_4 . V_5 ,
L_141 ) ,
F_75 ( 'b' , L_142 , & V_143 , L_143 ,
L_144 , F_65 ) ,
F_68 ( 0 , L_145 , & V_196 , L_146 ,
L_147 ) ,
F_70 ( 0 , L_148 , & V_4 . V_197 ,
L_149 ) ,
F_70 ( 0 , L_150 , & V_6 . V_34 , L_151 ) ,
F_74 ( 0 , L_152 , & V_6 , L_153 ,
L_154 , F_66 ) ,
F_74 ( 0 , L_155 , NULL , L_156 ,
L_157 , V_198 ) ,
F_76 ()
} ;
struct V_131 V_75 = {
. V_82 = V_199 ,
} ;
F_77 ( F_1 , & V_6 ) ;
V_144 = F_78 ( V_144 , V_145 , V_170 , V_149 , 0 ) ;
if ( V_6 . V_179 )
V_123 = 0 ;
else if ( V_6 . V_177 )
V_123 = 1 ;
else if ( V_6 . V_178 )
V_123 = 2 ;
if ( V_6 . V_184 )
V_81 . V_200 = V_201 ;
if ( ! V_171 || ! strlen ( V_171 ) ) {
if ( ! F_79 ( V_202 , & V_146 ) && F_80 ( V_146 . V_203 ) )
V_171 = L_158 ;
else
V_171 = L_159 ;
}
V_75 . V_135 = V_171 ;
V_75 . V_174 = V_6 . V_174 ;
V_204:
V_71 = F_81 ( & V_75 , false , & V_6 . V_38 ) ;
if ( V_71 == NULL )
return - V_205 ;
V_6 . V_71 = V_71 ;
V_147 = F_82 ( & V_71 -> V_47 ,
V_206 ) ;
if ( V_143 == - 1 && V_147 ) {
V_28 = V_29 ;
V_4 . V_9 = false ;
}
if ( V_6 . V_34 ) {
if ( V_28 == V_29 ) {
F_64 ( L_160 ) ;
goto error;
}
V_28 = V_207 ;
V_4 . V_9 = false ;
}
if ( F_83 () < 0 ) {
if ( V_100 )
F_84 ( V_149 , V_170 , L_161 , 1 ) ;
if ( V_181 )
F_84 ( V_100 ? NULL : V_149 ,
V_170 , L_162 , 1 ) ;
goto error;
}
if ( V_6 . V_47 || V_6 . V_180 )
V_123 = 0 ;
if ( strcmp ( V_171 , L_158 ) != 0 )
F_85 ( true ) ;
else
V_123 = 0 ;
if ( V_6 . V_47 || V_6 . V_180 ) {
F_86 ( V_71 , stdout ,
V_6 . V_191 ) ;
if ( V_6 . V_180 )
return 0 ;
} else if ( V_123 == 0 ) {
fputs ( L_163 ,
stdout ) ;
}
if ( F_6 () ) {
V_4 . V_208 = sizeof( struct V_209 ) ;
F_87 ( & V_71 -> V_109 ,
V_210 ) ;
if ( V_133 ) {
V_4 . V_208 += sizeof( V_211 ) ;
V_4 . V_212 = true ;
}
}
if ( F_88 () < 0 )
goto error;
if ( V_144 ) {
if ( V_144 > 1 )
F_89 ( V_149 , V_170 ) ;
V_6 . V_128 = V_145 [ 0 ] ;
}
F_90 ( stdout ) ;
V_46 = F_53 ( & V_6 ) ;
if ( V_46 == V_125 ) {
F_91 ( V_71 ) ;
goto V_204;
} else
V_46 = 0 ;
error:
F_91 ( V_71 ) ;
return V_46 ;
}
