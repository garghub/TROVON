static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
if ( ! strcmp ( V_1 , L_1 ) ) {
V_4 . V_5 = F_2 ( V_1 , V_2 ) ;
return 0 ;
}
return F_3 ( V_1 , V_2 , V_3 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_7 , struct V_15 , V_7 ) ;
struct V_17 * V_18 = NULL ;
int V_19 = 0 ;
unsigned V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 , * V_25 ;
if ( ( V_26 || V_4 . V_27 )
&& V_11 -> V_28 ) {
V_19 = F_6 ( V_14 , V_13 , V_9 -> V_29 ,
V_11 , & V_18 ) ;
if ( V_19 )
return V_19 ;
}
V_24 = F_7 ( V_14 , V_9 -> V_29 ,
V_11 -> V_30 ) ;
if ( ! V_24 )
return - V_31 ;
for ( V_20 = 0 ; V_20 < V_11 -> V_30 -> V_32 ; V_20 ++ ) {
if ( V_16 -> V_33 && ! ( V_24 [ V_20 ] . V_34 . V_35 && V_24 [ V_20 ] . V_36 . V_35 ) )
continue;
V_22 = F_8 ( & V_13 -> V_37 , V_9 , V_18 ,
& V_24 [ V_20 ] , 1 ) ;
if ( V_22 ) {
struct V_38 * V_39 ;
V_19 = - V_31 ;
V_25 = V_22 -> V_23 ;
if ( V_25 -> V_34 . V_35 && V_40 == 1 && V_41 ) {
V_39 = F_9 ( V_25 -> V_34 . V_35 ) ;
if ( ! V_39 -> V_42
&& F_10 ( V_25 -> V_34 . V_35 ) < 0 )
goto V_43;
V_19 = F_11 ( V_25 -> V_34 . V_35 ,
V_25 -> V_34 . V_44 ,
V_13 -> V_45 ,
V_25 -> V_34 . V_46 ) ;
if ( V_19 )
goto V_43;
}
if ( V_25 -> V_36 . V_35 && V_40 == 1 && V_41 ) {
V_39 = F_9 ( V_25 -> V_36 . V_35 ) ;
if ( ! V_39 -> V_42
&& F_10 ( V_25 -> V_36 . V_35 ) < 0 )
goto V_43;
V_19 = F_11 ( V_25 -> V_36 . V_35 ,
V_25 -> V_36 . V_44 ,
V_13 -> V_45 ,
V_25 -> V_36 . V_46 ) ;
if ( V_19 )
goto V_43;
}
V_13 -> V_37 . V_47 . V_48 += 1 ;
F_12 ( & V_13 -> V_37 , V_49 ) ;
V_19 = 0 ;
} else
return - V_31 ;
}
V_43:
return V_19 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_14 * V_14 )
{
struct V_17 * V_18 = NULL ;
int V_19 = 0 ;
struct V_21 * V_22 ;
if ( ( V_26 || V_4 . V_27 ) && V_11 -> V_28 ) {
V_19 = F_6 ( V_14 , V_13 , V_9 -> V_29 ,
V_11 , & V_18 ) ;
if ( V_19 )
return V_19 ;
}
V_22 = F_14 ( & V_13 -> V_37 , V_9 , V_18 , V_11 -> V_50 ) ;
if ( V_22 == NULL )
return - V_31 ;
if ( V_4 . V_27 ) {
V_19 = F_15 ( V_22 -> V_28 ,
& V_51 ,
V_11 -> V_50 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_22 -> V_52 . V_35 != NULL && V_40 == 1 && V_41 ) {
struct V_38 * V_39 = F_9 ( V_22 -> V_52 . V_35 ) ;
assert ( V_13 != NULL ) ;
V_19 = - V_31 ;
if ( V_39 -> V_42 == NULL && F_10 ( V_22 -> V_52 . V_35 ) < 0 )
goto V_43;
V_19 = F_16 ( V_22 , V_13 -> V_45 , V_9 -> V_53 ) ;
}
V_13 -> V_37 . V_47 . V_48 += V_11 -> V_50 ;
F_12 ( & V_13 -> V_37 , V_49 ) ;
V_43:
return V_19 ;
}
static int F_17 ( struct V_6 * V_7 ,
union V_54 * V_55 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_7 , struct V_15 , V_7 ) ;
struct V_8 V_9 ;
if ( F_18 ( V_55 , V_14 , & V_9 , V_11 ,
V_16 -> V_56 ) < 0 ) {
fprintf ( V_57 , L_2 ,
V_55 -> V_58 . type ) ;
return - 1 ;
}
if ( V_9 . V_59 || ( V_16 -> V_33 && V_9 . V_35 == NULL ) )
return 0 ;
if ( V_16 -> V_60 && ! F_19 ( V_11 -> V_61 , V_16 -> V_62 ) )
return 0 ;
if ( V_63 == 1 ) {
if ( F_4 ( V_7 , & V_9 , V_11 ,
V_13 , V_14 ) ) {
F_20 ( L_3 ) ;
return - 1 ;
}
} else {
if ( V_9 . V_44 != NULL )
V_9 . V_44 -> V_64 -> V_65 = 1 ;
if ( F_13 ( V_13 , & V_9 , V_11 , V_14 ) ) {
F_20 ( L_4 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
union V_54 * V_55 ,
struct V_10 * V_11 V_66 ,
struct V_12 * V_13 ,
struct V_14 * V_14 V_66 )
{
struct V_15 * V_16 = F_5 ( V_7 , struct V_15 , V_7 ) ;
if ( V_16 -> V_67 ) {
const char * V_68 = V_13 ? F_22 ( V_13 ) : L_5 ;
F_23 ( & V_16 -> V_69 ,
V_55 -> V_70 . V_71 , V_55 -> V_70 . V_72 ,
V_55 -> V_70 . V_73 ,
V_68 ,
V_55 -> V_70 . V_2 ) ;
}
F_24 ( L_6 V_74 L_7 , V_55 -> V_70 . V_71 , V_55 -> V_70 . V_72 ,
V_13 ? F_22 ( V_13 ) : L_8 ,
V_55 -> V_70 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_75 * V_76 = V_16 -> V_77 ;
T_1 V_78 = F_26 ( V_76 -> V_79 ) ;
if ( ! V_76 -> V_80 && ! ( V_78 & V_81 ) ) {
if ( V_26 ) {
F_27 ( L_9
L_10
L_11 ) ;
return - V_82 ;
}
if ( V_4 . V_27 ) {
F_27 ( L_12
L_13 ) ;
return - 1 ;
}
} else if ( ! V_16 -> V_83 &&
V_84 . V_85 != V_86 &&
! V_4 . V_27 ) {
V_4 . V_27 = true ;
if ( F_28 ( & V_84 ) < 0 ) {
F_27 ( L_14 ) ;
return - V_82 ;
}
}
if ( V_63 == 1 ) {
if ( ! V_76 -> V_80 &&
! ( V_78 & V_87 ) ) {
F_27 ( L_15
L_16 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_29 ( int T_2 V_66 )
{
V_88 = 1 ;
}
static T_3 F_30 ( struct V_37 * V_76 ,
const char * V_89 , T_4 * V_90 )
{
T_3 V_91 ;
char V_92 ;
unsigned long V_93 = V_76 -> V_47 . V_94 [ V_49 ] ;
T_1 V_94 = V_76 -> V_47 . V_48 ;
struct V_12 * V_13 = F_31 ( V_76 ) ;
char V_95 [ 512 ] ;
T_3 V_96 = sizeof( V_95 ) ;
if ( V_4 . V_5 && V_13 -> V_97 > 1 ) {
struct V_12 * V_98 ;
F_32 ( V_13 , V_95 , V_96 ) ;
V_89 = V_95 ;
F_33 (pos, evsel) {
V_93 += V_98 -> V_37 . V_47 . V_94 [ V_49 ] ;
V_94 += V_98 -> V_37 . V_47 . V_48 ;
}
}
V_93 = F_34 ( V_93 , & V_92 ) ;
V_91 = fprintf ( V_90 , L_17 , V_93 , V_92 ) ;
if ( V_89 != NULL )
V_91 += fprintf ( V_90 , L_18 , V_89 ) ;
V_91 += fprintf ( V_90 , L_19 V_74 , V_94 ) ;
return V_91 + fprintf ( V_90 , L_20 ) ;
}
static int F_35 ( struct V_99 * V_79 ,
struct V_15 * V_16 ,
const char * V_100 )
{
struct V_12 * V_98 ;
F_36 (pos, &evlist->entries, node) {
struct V_37 * V_37 = & V_98 -> V_37 ;
const char * V_89 = F_22 ( V_98 ) ;
if ( V_4 . V_5 &&
! F_37 ( V_98 ) )
continue;
F_30 ( V_37 , V_89 , stdout ) ;
F_38 ( V_37 , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_21 ) ;
}
if ( V_101 == V_102 &&
V_103 == V_104 ) {
fprintf ( stdout , L_22 , V_100 ) ;
if ( V_16 -> V_67 ) {
bool V_105 = ! strcmp ( V_16 -> V_106 , L_23 ) ;
F_39 ( stdout , & V_16 -> V_69 ,
V_105 ) ;
F_40 ( & V_16 -> V_69 ) ;
}
}
return 0 ;
}
static int F_41 ( struct V_15 * V_16 )
{
int V_91 = - V_82 ;
T_1 V_93 ;
struct V_75 * V_77 = V_16 -> V_77 ;
struct V_12 * V_98 ;
struct V_44 * V_107 ;
struct V_108 * V_109 ;
const char * V_100 = L_24 ;
signal ( V_110 , F_29 ) ;
if ( V_16 -> V_60 ) {
V_91 = F_42 ( V_77 , V_16 -> V_60 ,
V_16 -> V_62 ) ;
if ( V_91 )
goto V_111;
}
if ( V_40 <= 0 )
F_43 ( V_77 , stdout , V_16 -> V_112 ) ;
if ( V_16 -> V_67 )
F_44 ( & V_16 -> V_69 ) ;
V_91 = F_25 ( V_16 ) ;
if ( V_91 )
goto V_111;
V_91 = F_45 ( V_77 , & V_16 -> V_7 ) ;
if ( V_91 )
goto V_111;
V_107 = V_77 -> V_113 . V_114 . V_115 [ V_116 ] ;
V_109 = F_46 ( V_107 ) ;
if ( V_107 == NULL ||
( V_107 -> V_64 -> V_65 &&
( V_109 -> V_117 == NULL ||
V_109 -> V_117 -> V_53 == 0 ) ) ) {
const char * V_118 =
L_25
L_26 ;
if ( V_107 ) {
const struct V_64 * V_119 = V_107 -> V_64 ;
if ( ! F_47 ( & V_119 -> V_120 [ V_116 ] ) ) {
V_118 = L_27
L_28 ;
}
}
F_48 (
L_29
L_30
L_31 ,
V_118 ) ;
}
if ( V_121 > 3 )
F_49 ( V_77 , stdout ) ;
if ( V_121 > 2 )
F_50 ( V_77 , stdout ) ;
if ( V_122 ) {
F_51 ( V_77 , stdout ) ;
goto V_111;
}
V_93 = 0 ;
F_36 (pos, &session->evlist->entries, node) {
struct V_37 * V_37 = & V_98 -> V_37 ;
if ( V_98 -> V_45 == 0 )
V_37 -> V_123 = V_16 -> V_123 ;
F_52 ( V_37 ) ;
V_93 += V_37 -> V_47 . V_94 [ V_49 ] ;
if ( V_4 . V_5 &&
! F_37 ( V_98 ) ) {
struct V_37 * V_124 = & V_98 -> V_125 -> V_37 ;
F_53 ( V_124 , V_37 ) ;
F_54 ( V_124 , V_37 ) ;
}
}
if ( V_93 == 0 ) {
F_27 ( L_32 , V_77 -> V_126 ) ;
goto V_111;
}
F_36 (pos, &session->evlist->entries, node)
F_55 ( & V_98 -> V_37 ) ;
if ( V_40 > 0 ) {
if ( V_40 == 1 ) {
V_91 = F_56 ( V_77 -> V_79 ,
V_100 ,
NULL ,
& V_77 -> V_58 . V_127 ) ;
if ( V_91 != V_128 )
V_91 = 0 ;
} else if ( V_40 == 2 ) {
F_57 ( V_77 -> V_79 , V_100 ,
NULL ) ;
}
} else
F_35 ( V_77 -> V_79 , V_16 , V_100 ) ;
V_111:
return V_91 ;
}
static int
F_58 ( const struct V_129 * V_130 , const char * V_131 , int V_132 )
{
struct V_15 * V_16 = (struct V_15 * ) V_130 -> V_2 ;
char * V_133 , * V_134 ;
char * V_135 ;
if ( V_132 ) {
V_16 -> V_83 = true ;
return 0 ;
}
V_4 . V_27 = true ;
if ( ! V_131 )
return 0 ;
V_133 = strtok ( ( char * ) V_131 , L_33 ) ;
if ( ! V_133 )
return - 1 ;
if ( ! strncmp ( V_133 , L_34 , strlen ( V_131 ) ) )
V_84 . V_85 = V_136 ;
else if ( ! strncmp ( V_133 , L_35 , strlen ( V_131 ) ) )
V_84 . V_85 = V_137 ;
else if ( ! strncmp ( V_133 , L_36 , strlen ( V_131 ) ) )
V_84 . V_85 = V_138 ;
else if ( ! strncmp ( V_133 , L_37 , strlen ( V_131 ) ) ) {
V_84 . V_85 = V_86 ;
V_4 . V_27 = false ;
return 0 ;
}
else
return - 1 ;
V_133 = strtok ( NULL , L_33 ) ;
if ( ! V_133 )
goto V_139;
V_84 . V_140 = strtod ( V_133 , & V_135 ) ;
if ( V_133 == V_135 )
return - 1 ;
V_134 = strtok ( NULL , L_33 ) ;
if ( ! V_134 )
goto V_139;
if ( V_134 [ 0 ] != 'c' ) {
V_84 . V_141 = strtoul ( V_134 , & V_135 , 0 ) ;
V_134 = strtok ( NULL , L_33 ) ;
if ( ! V_134 )
goto V_139;
}
if ( ! strcmp ( V_134 , L_38 ) )
V_84 . V_142 = V_143 ;
else if ( ! strcmp ( V_134 , L_39 ) )
V_84 . V_142 = V_144 ;
else
return - 1 ;
V_139:
if ( F_28 ( & V_84 ) < 0 ) {
fprintf ( V_57 , L_40 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_59 ( const struct V_129 * V_130 V_66 ,
const char * T_5 V_66 , int V_132 )
{
V_63 = ! V_132 ;
return 0 ;
}
int F_60 ( int V_145 , const char * * V_146 , const char * T_6 V_66 )
{
struct V_75 * V_77 ;
struct V_147 V_148 ;
bool V_149 = false ;
int V_91 = - 1 ;
char V_150 [] = L_41 ;
const char * const V_151 [] = {
L_42 ,
NULL
} ;
struct V_15 V_152 = {
. V_7 = {
. V_11 = F_17 ,
. V_153 = V_154 ,
. V_155 = V_156 ,
. exit = V_157 ,
. V_158 = V_159 ,
. V_160 = V_161 ,
. V_70 = F_21 ,
. V_162 = V_163 ,
. V_164 = V_165 ,
. V_166 = V_167 ,
. V_168 = V_169 ,
. V_170 = true ,
. V_171 = true ,
} ,
. V_106 = L_43 ,
} ;
const struct V_129 V_172 [] = {
F_61 ( 'i' , L_44 , & V_173 , L_45 ,
L_46 ) ,
F_62 ( 'v' , L_47 , & V_121 ,
L_48 ) ,
F_63 ( 'D' , L_49 , & V_122 ,
L_50 ) ,
F_61 ( 'k' , L_51 , & V_4 . V_174 ,
L_45 , L_52 ) ,
F_61 ( 0 , L_53 , & V_4 . V_175 ,
L_45 , L_54 ) ,
F_63 ( 'f' , L_55 , & V_152 . V_176 , L_56 ) ,
F_63 ( 'm' , L_57 , & V_4 . V_177 ,
L_58 ) ,
F_63 ( 'n' , L_59 , & V_4 . V_178 ,
L_60 ) ,
F_63 ( 'T' , L_61 , & V_152 . V_67 ,
L_62 ) ,
F_61 ( 0 , L_63 , & V_152 . V_106 , L_64 ,
L_65 ) ,
F_63 ( 0 , L_66 , & V_152 . V_179 , L_67 ) ,
F_63 ( 0 , L_68 , & V_152 . V_180 , L_69 ) ,
F_63 ( 0 , L_70 , & V_152 . V_181 ,
L_71 ) ,
F_61 ( 's' , L_72 , & V_101 , L_73 ,
L_74
L_75 ) ,
F_63 ( 0 , L_76 , & V_4 . V_182 ,
L_77 ) ,
F_61 ( 'p' , L_78 , & V_103 , L_79 ,
L_80 ) ,
F_63 ( 'x' , L_81 , & V_4 . V_183 ,
L_82 ) ,
F_64 ( 'g' , L_83 , & V_152 , L_84 ,
L_85
L_86 , & F_58 , V_150 ) ,
F_63 ( 'G' , L_87 , & V_152 . V_184 ,
L_88 ) ,
F_61 ( 'd' , L_89 , & V_4 . V_185 , L_90 ,
L_91 ) ,
F_61 ( 'c' , L_92 , & V_4 . V_186 , L_93 ,
L_94 ) ,
F_61 ( 'S' , L_95 , & V_4 . V_187 , L_96 ,
L_97 ) ,
F_61 ( 0 , L_98 , & V_152 . V_123 , L_99 ,
L_100 ) ,
F_61 ( 'w' , L_101 , & V_4 . V_188 ,
L_102 ,
L_103 ) ,
F_61 ( 't' , L_104 , & V_4 . V_189 , L_105 ,
L_106
L_107 ) ,
F_63 ( 'U' , L_108 , & V_152 . V_33 ,
L_109 ) ,
F_61 ( 0 , L_110 , & V_4 . V_190 , L_111 ,
L_112 ) ,
F_61 ( 'C' , L_113 , & V_152 . V_60 , L_113 ,
L_114 ) ,
F_63 ( 'I' , L_115 , & V_152 . V_112 ,
L_116 ) ,
F_63 ( 0 , L_117 , & V_4 . V_191 ,
L_118 ) ,
F_63 ( 0 , L_119 , & V_4 . V_192 ,
L_120 ) ,
F_61 ( 'M' , L_121 , & V_193 , L_122 ,
L_123 ) ,
F_63 ( 0 , L_124 , & V_4 . V_194 ,
L_125 ) ,
F_63 ( 0 , L_126 , & V_4 . V_5 ,
L_127 ) ,
F_65 ( 'b' , L_128 , & V_63 , L_129 ,
L_130 , F_59 ) ,
F_61 ( 0 , L_131 , & V_195 , L_132 ,
L_133 ) ,
F_66 ()
} ;
F_67 ( F_1 , NULL ) ;
V_145 = F_68 ( V_145 , V_146 , V_172 , V_151 , 0 ) ;
if ( V_152 . V_181 )
V_40 = 0 ;
else if ( V_152 . V_179 )
V_40 = 1 ;
else if ( V_152 . V_180 )
V_40 = 2 ;
if ( V_152 . V_184 )
V_84 . V_142 = V_143 ;
if ( ! V_173 || ! strlen ( V_173 ) ) {
if ( ! F_69 ( V_196 , & V_148 ) && F_70 ( V_148 . V_197 ) )
V_173 = L_134 ;
else
V_173 = L_135 ;
}
if ( strcmp ( V_173 , L_134 ) != 0 )
F_71 ( true ) ;
else {
V_40 = 0 ;
F_72 ( V_198 ) ;
F_73 () ;
}
V_199:
V_77 = F_74 ( V_173 , V_200 ,
V_152 . V_176 , false , & V_152 . V_7 ) ;
if ( V_77 == NULL )
return - V_31 ;
V_152 . V_77 = V_77 ;
V_149 = F_75 ( & V_77 -> V_58 ,
V_201 ) ;
if ( V_63 == - 1 && V_149 )
V_63 = 1 ;
if ( V_63 == 1 ) {
if ( V_101 == V_102 )
V_101 = L_136
L_137 ;
}
if ( F_76 () < 0 )
F_77 ( V_151 , V_172 ) ;
if ( V_40 == 1 && V_41 ) {
V_4 . V_202 = sizeof( struct V_38 ) ;
V_152 . V_56 = V_203 ;
if ( V_121 ) {
V_4 . V_202 += sizeof( V_204 ) ;
V_4 . V_205 = true ;
}
}
if ( F_78 () < 0 )
goto error;
if ( V_103 != V_104 ) {
if ( F_79 ( L_78 ) < 0 )
goto error;
if ( ! strstr ( V_101 , L_78 ) )
V_206 . V_207 = 1 ;
} else
V_4 . V_183 = false ;
if ( V_145 ) {
if ( V_145 > 1 )
F_77 ( V_151 , V_172 ) ;
V_152 . V_123 = V_146 [ 0 ] ;
}
F_80 ( & V_208 , V_4 . V_209 , L_138 , stdout ) ;
if ( V_63 == 1 ) {
F_80 ( & V_210 , V_4 . V_211 , L_139 , stdout ) ;
F_80 ( & V_212 , V_4 . V_213 , L_140 , stdout ) ;
F_80 ( & V_214 , V_4 . V_215 , L_141 , stdout ) ;
F_80 ( & V_216 , V_4 . V_217 , L_142 , stdout ) ;
} else {
F_80 ( & V_218 , V_4 . V_219 , L_143 , stdout ) ;
F_80 ( & V_220 , V_4 . V_221 , L_144 , stdout ) ;
}
V_91 = F_41 ( & V_152 ) ;
if ( V_91 == V_128 ) {
F_81 ( V_77 ) ;
goto V_199;
} else
V_91 = 0 ;
error:
F_81 ( V_77 ) ;
return V_91 ;
}
