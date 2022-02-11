static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 , struct V_10 , V_2 ) ;
struct V_12 * V_13 = NULL ;
int V_14 = 0 ;
unsigned V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 , * V_20 ;
if ( ( V_21 || V_22 . V_23 )
&& V_6 -> V_24 ) {
V_14 = F_3 ( V_9 , V_8 , V_4 -> V_25 ,
V_6 , & V_13 ) ;
if ( V_14 )
return V_14 ;
}
V_19 = F_4 ( V_9 , V_4 -> V_25 ,
V_6 -> V_26 ) ;
if ( ! V_19 )
return - V_27 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_26 -> V_28 ; V_15 ++ ) {
if ( V_11 -> V_29 && ! ( V_19 [ V_15 ] . V_30 . V_31 && V_19 [ V_15 ] . V_32 . V_31 ) )
continue;
V_17 = F_5 ( & V_8 -> V_33 , V_4 , V_13 ,
& V_19 [ V_15 ] , 1 ) ;
if ( V_17 ) {
struct V_34 * V_35 ;
V_14 = - V_27 ;
V_20 = V_17 -> V_18 ;
if ( V_20 -> V_30 . V_31 && V_36 == 1 && V_37 ) {
V_35 = F_6 ( V_20 -> V_30 . V_31 ) ;
if ( ! V_35 -> V_38
&& F_7 ( V_20 -> V_30 . V_31 ) < 0 )
goto V_39;
V_14 = F_8 ( V_20 -> V_30 . V_31 ,
V_20 -> V_30 . V_40 ,
V_8 -> V_41 ,
V_20 -> V_30 . V_42 ) ;
if ( V_14 )
goto V_39;
}
if ( V_20 -> V_32 . V_31 && V_36 == 1 && V_37 ) {
V_35 = F_6 ( V_20 -> V_32 . V_31 ) ;
if ( ! V_35 -> V_38
&& F_7 ( V_20 -> V_32 . V_31 ) < 0 )
goto V_39;
V_14 = F_8 ( V_20 -> V_32 . V_31 ,
V_20 -> V_32 . V_40 ,
V_8 -> V_41 ,
V_20 -> V_32 . V_42 ) ;
if ( V_14 )
goto V_39;
}
V_8 -> V_33 . V_43 . V_44 += 1 ;
F_9 ( & V_8 -> V_33 , V_45 ) ;
V_14 = 0 ;
} else
return - V_27 ;
}
V_39:
return V_14 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_9 * V_9 )
{
struct V_12 * V_13 = NULL ;
int V_14 = 0 ;
struct V_16 * V_17 ;
if ( ( V_21 || V_22 . V_23 ) && V_6 -> V_24 ) {
V_14 = F_3 ( V_9 , V_8 , V_4 -> V_25 ,
V_6 , & V_13 ) ;
if ( V_14 )
return V_14 ;
}
V_17 = F_11 ( & V_8 -> V_33 , V_4 , V_13 , V_6 -> V_46 ) ;
if ( V_17 == NULL )
return - V_27 ;
if ( V_22 . V_23 ) {
V_14 = F_12 ( V_17 -> V_24 ,
& V_47 ,
V_6 -> V_46 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_17 -> V_48 . V_31 != NULL && V_36 == 1 && V_37 ) {
struct V_34 * V_35 = F_6 ( V_17 -> V_48 . V_31 ) ;
assert ( V_8 != NULL ) ;
V_14 = - V_27 ;
if ( V_35 -> V_38 == NULL && F_7 ( V_17 -> V_48 . V_31 ) < 0 )
goto V_39;
V_14 = F_13 ( V_17 , V_8 -> V_41 , V_4 -> V_49 ) ;
}
V_8 -> V_33 . V_43 . V_44 += V_6 -> V_46 ;
F_9 ( & V_8 -> V_33 , V_45 ) ;
V_39:
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_50 * V_51 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 , struct V_10 , V_2 ) ;
struct V_3 V_4 ;
if ( F_15 ( V_51 , V_9 , & V_4 , V_6 ,
V_11 -> V_52 ) < 0 ) {
fprintf ( V_53 , L_1 ,
V_51 -> V_54 . type ) ;
return - 1 ;
}
if ( V_4 . V_55 || ( V_11 -> V_29 && V_4 . V_31 == NULL ) )
return 0 ;
if ( V_11 -> V_56 && ! F_16 ( V_6 -> V_57 , V_11 -> V_58 ) )
return 0 ;
if ( V_59 == 1 ) {
if ( F_1 ( V_2 , & V_4 , V_6 ,
V_8 , V_9 ) ) {
F_17 ( L_2 ) ;
return - 1 ;
}
} else {
if ( V_4 . V_40 != NULL )
V_4 . V_40 -> V_60 -> V_61 = 1 ;
if ( F_10 ( V_8 , & V_4 , V_6 , V_9 ) ) {
F_17 ( L_3 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
union V_50 * V_51 ,
struct V_5 * V_6 V_62 ,
struct V_7 * V_8 ,
struct V_9 * V_9 V_62 )
{
struct V_10 * V_11 = F_2 ( V_2 , struct V_10 , V_2 ) ;
if ( V_11 -> V_63 ) {
const char * V_64 = V_8 ? F_19 ( V_8 ) : L_4 ;
F_20 ( & V_11 -> V_65 ,
V_51 -> V_66 . V_67 , V_51 -> V_66 . V_68 ,
V_51 -> V_66 . V_69 ,
V_64 ,
V_51 -> V_66 . V_70 ) ;
}
F_21 ( L_5 V_71 L_6 , V_51 -> V_66 . V_67 , V_51 -> V_66 . V_68 ,
V_8 ? F_19 ( V_8 ) : L_7 ,
V_51 -> V_66 . V_70 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_72 * V_73 = V_11 -> V_74 ;
T_1 V_75 = F_23 ( V_73 -> V_76 ) ;
if ( ! V_73 -> V_77 && ! ( V_75 & V_78 ) ) {
if ( V_21 ) {
F_24 ( L_8
L_9
L_10 ) ;
return - V_79 ;
}
if ( V_22 . V_23 ) {
F_24 ( L_11
L_12 ) ;
return - 1 ;
}
} else if ( ! V_11 -> V_80 &&
V_81 . V_82 != V_83 &&
! V_22 . V_23 ) {
V_22 . V_23 = true ;
if ( F_25 ( & V_81 ) < 0 ) {
F_24 ( L_13 ) ;
return - V_79 ;
}
}
if ( V_59 == 1 ) {
if ( ! V_73 -> V_77 &&
! ( V_75 & V_84 ) ) {
F_24 ( L_14
L_15 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_26 ( int T_2 V_62 )
{
V_85 = 1 ;
}
static T_3 F_27 ( struct V_33 * V_73 ,
const char * V_86 , T_4 * V_87 )
{
T_3 V_88 ;
char V_89 ;
unsigned long V_90 = V_73 -> V_43 . V_91 [ V_45 ] ;
T_1 V_91 = V_73 -> V_43 . V_44 ;
V_90 = F_28 ( V_90 , & V_89 ) ;
V_88 = fprintf ( V_87 , L_16 , V_90 , V_89 ) ;
if ( V_86 != NULL )
V_88 += fprintf ( V_87 , L_17 , V_86 ) ;
V_88 += fprintf ( V_87 , L_18 V_71 , V_91 ) ;
return V_88 + fprintf ( V_87 , L_19 ) ;
}
static int F_29 ( struct V_92 * V_76 ,
struct V_10 * V_11 ,
const char * V_93 )
{
struct V_7 * V_94 ;
F_30 (pos, &evlist->entries, node) {
struct V_33 * V_33 = & V_94 -> V_33 ;
const char * V_86 = F_19 ( V_94 ) ;
F_27 ( V_33 , V_86 , stdout ) ;
F_31 ( V_33 , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_20 ) ;
}
if ( V_95 == V_96 &&
V_97 == V_98 ) {
fprintf ( stdout , L_21 , V_93 ) ;
if ( V_11 -> V_63 ) {
bool V_99 = ! strcmp ( V_11 -> V_100 , L_22 ) ;
F_32 ( stdout , & V_11 -> V_65 ,
V_99 ) ;
F_33 ( & V_11 -> V_65 ) ;
}
}
return 0 ;
}
static int F_34 ( struct V_10 * V_11 )
{
int V_88 = - V_79 ;
T_1 V_90 ;
struct V_72 * V_74 = V_11 -> V_74 ;
struct V_7 * V_94 ;
struct V_40 * V_101 ;
struct V_102 * V_103 ;
const char * V_93 = L_23 ;
signal ( V_104 , F_26 ) ;
if ( V_11 -> V_56 ) {
V_88 = F_35 ( V_74 , V_11 -> V_56 ,
V_11 -> V_58 ) ;
if ( V_88 )
goto V_105;
}
if ( V_36 <= 0 )
F_36 ( V_74 , stdout , V_11 -> V_106 ) ;
if ( V_11 -> V_63 )
F_37 ( & V_11 -> V_65 ) ;
V_88 = F_22 ( V_11 ) ;
if ( V_88 )
goto V_105;
V_88 = F_38 ( V_74 , & V_11 -> V_2 ) ;
if ( V_88 )
goto V_105;
V_101 = V_74 -> V_107 . V_108 [ V_109 ] ;
V_103 = F_39 ( V_101 ) ;
if ( V_101 == NULL ||
( V_101 -> V_60 -> V_61 &&
( V_103 -> V_110 == NULL ||
V_103 -> V_110 -> V_49 == 0 ) ) ) {
const char * V_111 =
L_24
L_25 ;
if ( V_101 ) {
const struct V_60 * V_112 = V_101 -> V_60 ;
if ( ! F_40 ( & V_112 -> V_113 [ V_109 ] ) ) {
V_111 = L_26
L_27 ;
}
}
F_41 (
L_28
L_29
L_30 ,
V_111 ) ;
}
if ( V_114 > 3 )
F_42 ( V_74 , stdout ) ;
if ( V_114 > 2 )
F_43 ( V_74 , stdout ) ;
if ( V_115 ) {
F_44 ( V_74 , stdout ) ;
goto V_105;
}
V_90 = 0 ;
F_30 (pos, &session->evlist->entries, node) {
struct V_33 * V_33 = & V_94 -> V_33 ;
if ( V_94 -> V_41 == 0 )
V_33 -> V_116 = V_11 -> V_116 ;
F_45 ( V_33 ) ;
F_46 ( V_33 ) ;
V_90 += V_33 -> V_43 . V_91 [ V_45 ] ;
}
if ( V_90 == 0 ) {
F_24 ( L_31 , V_74 -> V_117 ) ;
goto V_105;
}
if ( V_36 > 0 ) {
if ( V_36 == 1 ) {
F_47 ( V_74 -> V_76 , V_93 ,
NULL ,
& V_74 -> V_54 . V_118 ) ;
} else if ( V_36 == 2 ) {
F_48 ( V_74 -> V_76 , V_93 ,
NULL ) ;
}
} else
F_29 ( V_74 -> V_76 , V_11 , V_93 ) ;
V_105:
return V_88 ;
}
static int
F_49 ( const struct V_119 * V_120 , const char * V_121 , int V_122 )
{
struct V_10 * V_11 = (struct V_10 * ) V_120 -> V_70 ;
char * V_123 , * V_124 ;
char * V_125 ;
if ( V_122 ) {
V_11 -> V_80 = true ;
return 0 ;
}
V_22 . V_23 = true ;
if ( ! V_121 )
return 0 ;
V_123 = strtok ( ( char * ) V_121 , L_32 ) ;
if ( ! V_123 )
return - 1 ;
if ( ! strncmp ( V_123 , L_33 , strlen ( V_121 ) ) )
V_81 . V_82 = V_126 ;
else if ( ! strncmp ( V_123 , L_34 , strlen ( V_121 ) ) )
V_81 . V_82 = V_127 ;
else if ( ! strncmp ( V_123 , L_35 , strlen ( V_121 ) ) )
V_81 . V_82 = V_128 ;
else if ( ! strncmp ( V_123 , L_36 , strlen ( V_121 ) ) ) {
V_81 . V_82 = V_83 ;
V_22 . V_23 = false ;
return 0 ;
}
else
return - 1 ;
V_123 = strtok ( NULL , L_32 ) ;
if ( ! V_123 )
goto V_129;
V_81 . V_130 = strtod ( V_123 , & V_125 ) ;
if ( V_123 == V_125 )
return - 1 ;
V_124 = strtok ( NULL , L_32 ) ;
if ( ! V_124 )
goto V_129;
if ( V_124 [ 0 ] != 'c' ) {
V_81 . V_131 = strtoul ( V_124 , & V_125 , 0 ) ;
V_124 = strtok ( NULL , L_32 ) ;
if ( ! V_124 )
goto V_129;
}
if ( ! strcmp ( V_124 , L_37 ) )
V_81 . V_132 = V_133 ;
else if ( ! strcmp ( V_124 , L_38 ) )
V_81 . V_132 = V_134 ;
else
return - 1 ;
V_129:
if ( F_25 ( & V_81 ) < 0 ) {
fprintf ( V_53 , L_39 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_50 ( const struct V_119 * V_120 V_62 ,
const char * T_5 V_62 , int V_122 )
{
V_59 = ! V_122 ;
return 0 ;
}
int F_51 ( int V_135 , const char * * V_136 , const char * T_6 V_62 )
{
struct V_72 * V_74 ;
struct V_137 V_138 ;
bool V_139 = false ;
int V_88 = - 1 ;
char V_140 [] = L_40 ;
const char * const V_141 [] = {
L_41 ,
NULL
} ;
struct V_10 V_142 = {
. V_2 = {
. V_6 = F_14 ,
. V_143 = V_144 ,
. V_145 = V_146 ,
. exit = V_147 ,
. V_148 = V_149 ,
. V_150 = V_151 ,
. V_66 = F_18 ,
. V_152 = V_153 ,
. V_154 = V_155 ,
. V_156 = V_157 ,
. V_158 = V_159 ,
. V_160 = true ,
. V_161 = true ,
} ,
. V_100 = L_42 ,
} ;
const struct V_119 V_162 [] = {
F_52 ( 'i' , L_43 , & V_163 , L_44 ,
L_45 ) ,
F_53 ( 'v' , L_46 , & V_114 ,
L_47 ) ,
F_54 ( 'D' , L_48 , & V_115 ,
L_49 ) ,
F_52 ( 'k' , L_50 , & V_22 . V_164 ,
L_44 , L_51 ) ,
F_52 ( 0 , L_52 , & V_22 . V_165 ,
L_44 , L_53 ) ,
F_54 ( 'f' , L_54 , & V_142 . V_166 , L_55 ) ,
F_54 ( 'm' , L_56 , & V_22 . V_167 ,
L_57 ) ,
F_54 ( 'n' , L_58 , & V_22 . V_168 ,
L_59 ) ,
F_54 ( 'T' , L_60 , & V_142 . V_63 ,
L_61 ) ,
F_52 ( 0 , L_62 , & V_142 . V_100 , L_63 ,
L_64 ) ,
F_54 ( 0 , L_65 , & V_142 . V_169 , L_66 ) ,
F_54 ( 0 , L_67 , & V_142 . V_170 , L_68 ) ,
F_54 ( 0 , L_69 , & V_142 . V_171 ,
L_70 ) ,
F_52 ( 's' , L_71 , & V_95 , L_72 ,
L_73
L_74 ) ,
F_54 ( 0 , L_75 , & V_22 . V_172 ,
L_76 ) ,
F_52 ( 'p' , L_77 , & V_97 , L_78 ,
L_79 ) ,
F_54 ( 'x' , L_80 , & V_22 . V_173 ,
L_81 ) ,
F_55 ( 'g' , L_82 , & V_142 , L_83 ,
L_84
L_85 , & F_49 , V_140 ) ,
F_54 ( 'G' , L_86 , & V_142 . V_174 ,
L_87 ) ,
F_52 ( 'd' , L_88 , & V_22 . V_175 , L_89 ,
L_90 ) ,
F_52 ( 'c' , L_91 , & V_22 . V_176 , L_92 ,
L_93 ) ,
F_52 ( 'S' , L_94 , & V_22 . V_177 , L_95 ,
L_96 ) ,
F_52 ( 0 , L_97 , & V_142 . V_116 , L_98 ,
L_99 ) ,
F_52 ( 'w' , L_100 , & V_22 . V_178 ,
L_101 ,
L_102 ) ,
F_52 ( 't' , L_103 , & V_22 . V_179 , L_104 ,
L_105
L_106 ) ,
F_54 ( 'U' , L_107 , & V_142 . V_29 ,
L_108 ) ,
F_52 ( 0 , L_109 , & V_22 . V_180 , L_110 ,
L_111 ) ,
F_52 ( 'C' , L_112 , & V_142 . V_56 , L_112 ,
L_113 ) ,
F_54 ( 'I' , L_114 , & V_142 . V_106 ,
L_115 ) ,
F_54 ( 0 , L_116 , & V_22 . V_181 ,
L_117 ) ,
F_54 ( 0 , L_118 , & V_22 . V_182 ,
L_119 ) ,
F_52 ( 'M' , L_120 , & V_183 , L_121 ,
L_122 ) ,
F_54 ( 0 , L_123 , & V_22 . V_184 ,
L_124 ) ,
F_56 ( 'b' , L_125 , & V_59 , L_126 ,
L_127 , F_50 ) ,
F_52 ( 0 , L_128 , & V_185 , L_129 ,
L_130 ) ,
F_57 ()
} ;
V_135 = F_58 ( V_135 , V_136 , V_162 , V_141 , 0 ) ;
if ( V_142 . V_171 )
V_36 = 0 ;
else if ( V_142 . V_169 )
V_36 = 1 ;
else if ( V_142 . V_170 )
V_36 = 2 ;
if ( V_142 . V_174 )
V_81 . V_132 = V_133 ;
if ( ! V_163 || ! strlen ( V_163 ) ) {
if ( ! F_59 ( V_186 , & V_138 ) && F_60 ( V_138 . V_187 ) )
V_163 = L_131 ;
else
V_163 = L_132 ;
}
V_74 = F_61 ( V_163 , V_188 ,
V_142 . V_166 , false , & V_142 . V_2 ) ;
if ( V_74 == NULL )
return - V_27 ;
V_142 . V_74 = V_74 ;
V_139 = F_62 ( & V_74 -> V_54 ,
V_189 ) ;
if ( V_59 == - 1 && V_139 )
V_59 = 1 ;
if ( V_59 == 1 ) {
if ( V_95 == V_96 )
V_95 = L_133
L_134 ;
}
if ( strcmp ( V_163 , L_131 ) != 0 )
F_63 ( true ) ;
else {
V_36 = 0 ;
F_64 () ;
}
F_65 ( V_141 , V_162 ) ;
if ( V_36 == 1 && V_37 ) {
V_22 . V_190 = sizeof( struct V_34 ) ;
V_142 . V_52 = V_191 ;
if ( V_114 ) {
V_22 . V_190 += sizeof( V_192 ) ;
V_22 . V_193 = true ;
}
}
if ( F_66 () < 0 )
goto error;
if ( V_97 != V_98 ) {
if ( F_67 ( L_77 ) < 0 )
goto error;
if ( ! strstr ( V_95 , L_77 ) )
V_194 . V_195 = 1 ;
} else
V_22 . V_173 = false ;
if ( V_135 ) {
if ( V_135 > 1 )
F_68 ( V_141 , V_162 ) ;
V_142 . V_116 = V_136 [ 0 ] ;
}
F_69 ( & V_196 , V_22 . V_197 , L_135 , stdout ) ;
if ( V_59 == 1 ) {
F_69 ( & V_198 , V_22 . V_199 , L_136 , stdout ) ;
F_69 ( & V_200 , V_22 . V_201 , L_137 , stdout ) ;
F_69 ( & V_202 , V_22 . V_203 , L_138 , stdout ) ;
F_69 ( & V_204 , V_22 . V_205 , L_139 , stdout ) ;
} else {
F_69 ( & V_206 , V_22 . V_207 , L_140 , stdout ) ;
F_69 ( & V_208 , V_22 . V_209 , L_141 , stdout ) ;
}
V_88 = F_34 ( & V_142 ) ;
error:
F_70 ( V_74 ) ;
return V_88 ;
}
