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
V_6 -> V_24 , & V_13 ) ;
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
if ( V_20 -> V_30 . V_31 && V_36 > 0 ) {
V_35 = F_6 ( V_20 -> V_30 . V_31 ) ;
if ( ! V_35 -> V_37
&& F_7 ( V_20 -> V_30 . V_31 ) < 0 )
goto V_38;
V_14 = F_8 ( V_20 -> V_30 . V_31 ,
V_20 -> V_30 . V_39 ,
V_8 -> V_40 ,
V_20 -> V_30 . V_41 ) ;
if ( V_14 )
goto V_38;
}
if ( V_20 -> V_32 . V_31 && V_36 > 0 ) {
V_35 = F_6 ( V_20 -> V_32 . V_31 ) ;
if ( ! V_35 -> V_37
&& F_7 ( V_20 -> V_32 . V_31 ) < 0 )
goto V_38;
V_14 = F_8 ( V_20 -> V_32 . V_31 ,
V_20 -> V_32 . V_39 ,
V_8 -> V_40 ,
V_20 -> V_32 . V_41 ) ;
if ( V_14 )
goto V_38;
}
V_8 -> V_33 . V_42 . V_43 += 1 ;
F_9 ( & V_8 -> V_33 , V_44 ) ;
V_14 = 0 ;
} else
return - V_27 ;
}
V_38:
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
V_6 -> V_24 , & V_13 ) ;
if ( V_14 )
return V_14 ;
}
V_17 = F_11 ( & V_8 -> V_33 , V_4 , V_13 , V_6 -> V_45 ) ;
if ( V_17 == NULL )
return - V_27 ;
if ( V_22 . V_23 ) {
V_14 = F_12 ( V_17 -> V_24 ,
& V_8 -> V_33 . V_46 ,
V_6 -> V_45 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_4 -> V_31 != NULL && V_36 > 0 ) {
struct V_34 * V_35 = F_6 ( V_17 -> V_47 . V_31 ) ;
assert ( V_8 != NULL ) ;
V_14 = - V_27 ;
if ( V_35 -> V_37 == NULL && F_7 ( V_17 -> V_47 . V_31 ) < 0 )
goto V_38;
V_14 = F_13 ( V_17 , V_8 -> V_40 , V_4 -> V_48 ) ;
}
V_8 -> V_33 . V_42 . V_43 += V_6 -> V_45 ;
F_9 ( & V_8 -> V_33 , V_44 ) ;
V_38:
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_49 * V_50 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 , struct V_10 , V_2 ) ;
struct V_3 V_4 ;
if ( F_15 ( V_50 , V_9 , & V_4 , V_6 ,
V_11 -> V_51 ) < 0 ) {
fprintf ( V_52 , L_1 ,
V_50 -> V_53 . type ) ;
return - 1 ;
}
if ( V_4 . V_54 || ( V_11 -> V_29 && V_4 . V_31 == NULL ) )
return 0 ;
if ( V_11 -> V_55 && ! F_16 ( V_6 -> V_56 , V_11 -> V_57 ) )
return 0 ;
if ( V_58 == 1 ) {
if ( F_1 ( V_2 , & V_4 , V_6 ,
V_8 , V_9 ) ) {
F_17 ( L_2 ) ;
return - 1 ;
}
} else {
if ( V_4 . V_39 != NULL )
V_4 . V_39 -> V_59 -> V_60 = 1 ;
if ( F_10 ( V_8 , & V_4 , V_6 , V_9 ) ) {
F_17 ( L_3 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
union V_49 * V_50 ,
struct V_5 * V_6 V_61 ,
struct V_7 * V_8 ,
struct V_9 * V_9 V_61 )
{
struct V_10 * V_11 = F_2 ( V_2 , struct V_10 , V_2 ) ;
if ( V_11 -> V_62 ) {
const char * V_63 = V_8 ? F_19 ( V_8 ) : L_4 ;
F_20 ( & V_11 -> V_64 ,
V_50 -> V_65 . V_66 , V_50 -> V_65 . V_67 ,
V_50 -> V_65 . V_68 ,
V_63 ,
V_50 -> V_65 . V_69 ) ;
}
F_21 ( L_5 V_70 L_6 , V_50 -> V_65 . V_66 , V_50 -> V_65 . V_67 ,
V_8 ? F_19 ( V_8 ) : L_7 ,
V_50 -> V_65 . V_69 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_71 * V_72 = V_11 -> V_73 ;
if ( ! ( V_72 -> V_74 & V_75 ) ) {
if ( V_21 ) {
F_23 ( L_8
L_9
L_10 ) ;
return - V_76 ;
}
if ( V_22 . V_23 ) {
F_23 ( L_11
L_12 ) ;
return - 1 ;
}
} else if ( ! V_11 -> V_77 &&
V_78 . V_79 != V_80 &&
! V_22 . V_23 ) {
V_22 . V_23 = true ;
if ( F_24 ( & V_78 ) < 0 ) {
F_23 ( L_13
L_14 ) ;
return - V_76 ;
}
}
if ( V_58 == 1 ) {
if ( ! ( V_72 -> V_74 & V_81 ) ) {
fprintf ( V_52 , L_15
L_16
L_17 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_25 ( int T_1 V_61 )
{
V_82 = 1 ;
}
static T_2 F_26 ( struct V_33 * V_72 ,
const char * V_83 , T_3 * V_84 )
{
T_2 V_85 ;
char V_86 ;
unsigned long V_87 = V_72 -> V_42 . V_87 [ V_44 ] ;
V_87 = F_27 ( V_87 , & V_86 ) ;
V_85 = fprintf ( V_84 , L_18 , V_87 , V_86 ) ;
if ( V_83 != NULL )
V_85 += fprintf ( V_84 , L_19 , V_83 ) ;
return V_85 + fprintf ( V_84 , L_20 ) ;
}
static int F_28 ( struct V_88 * V_89 ,
struct V_10 * V_11 ,
const char * V_90 )
{
struct V_7 * V_91 ;
F_29 (pos, &evlist->entries, node) {
struct V_33 * V_33 = & V_91 -> V_33 ;
const char * V_83 = F_19 ( V_91 ) ;
F_26 ( V_33 , V_83 , stdout ) ;
F_30 ( V_33 , NULL , false , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_21 ) ;
}
if ( V_92 == V_93 &&
V_94 == V_95 ) {
fprintf ( stdout , L_22 , V_90 ) ;
if ( V_11 -> V_62 ) {
bool V_96 = ! strcmp ( V_11 -> V_97 , L_23 ) ;
F_31 ( stdout , & V_11 -> V_64 ,
V_96 ) ;
F_32 ( & V_11 -> V_64 ) ;
}
}
return 0 ;
}
static int F_33 ( struct V_10 * V_11 )
{
int V_85 = - V_76 ;
T_4 V_98 ;
struct V_71 * V_73 = V_11 -> V_73 ;
struct V_7 * V_91 ;
struct V_39 * V_99 ;
struct V_100 * V_101 ;
const char * V_90 = L_24 ;
signal ( V_102 , F_25 ) ;
if ( V_11 -> V_55 ) {
V_85 = F_34 ( V_73 , V_11 -> V_55 ,
V_11 -> V_57 ) ;
if ( V_85 )
goto V_103;
}
if ( V_36 <= 0 )
F_35 ( V_73 , stdout , V_11 -> V_104 ) ;
if ( V_11 -> V_62 )
F_36 ( & V_11 -> V_64 ) ;
V_85 = F_22 ( V_11 ) ;
if ( V_85 )
goto V_103;
V_85 = F_37 ( V_73 , & V_11 -> V_2 ) ;
if ( V_85 )
goto V_103;
V_99 = V_73 -> V_105 . V_106 [ V_107 ] ;
V_101 = F_38 ( V_99 ) ;
if ( V_99 == NULL ||
( V_99 -> V_59 -> V_60 &&
( V_101 -> V_108 == NULL ||
V_101 -> V_108 -> V_48 == 0 ) ) ) {
const char * V_109 =
L_25
L_26 ;
if ( V_99 ) {
const struct V_59 * V_110 = V_99 -> V_59 ;
if ( ! F_39 ( & V_110 -> V_111 [ V_107 ] ) ) {
V_109 = L_27
L_28 ;
}
}
F_23 (
L_29
L_30
L_31 ,
V_109 ) ;
}
if ( V_112 ) {
F_40 ( V_73 , stdout ) ;
goto V_103;
}
if ( V_113 > 3 )
F_41 ( V_73 , stdout ) ;
if ( V_113 > 2 )
F_42 ( V_73 , stdout ) ;
V_98 = 0 ;
F_29 (pos, &session->evlist->entries, node) {
struct V_33 * V_33 = & V_91 -> V_33 ;
if ( V_91 -> V_40 == 0 )
V_33 -> V_114 = V_11 -> V_114 ;
F_43 ( V_33 ) ;
F_44 ( V_33 ) ;
V_98 += V_33 -> V_42 . V_87 [ V_44 ] ;
}
if ( V_98 == 0 ) {
F_23 ( L_32 , V_73 -> V_115 ) ;
goto V_103;
}
if ( V_36 > 0 ) {
if ( V_36 == 1 ) {
F_45 ( V_73 -> V_89 , V_90 ,
NULL , NULL , 0 ) ;
} else if ( V_36 == 2 ) {
F_46 ( V_73 -> V_89 , V_90 ,
NULL , NULL , 0 ) ;
}
} else
F_28 ( V_73 -> V_89 , V_11 , V_90 ) ;
V_103:
return V_85 ;
}
static int
F_47 ( const struct V_116 * V_117 , const char * V_118 , int V_119 )
{
struct V_10 * V_11 = (struct V_10 * ) V_117 -> V_69 ;
char * V_120 , * V_121 ;
char * V_122 ;
if ( V_119 ) {
V_11 -> V_77 = true ;
return 0 ;
}
V_22 . V_23 = true ;
if ( ! V_118 )
return 0 ;
V_120 = strtok ( ( char * ) V_118 , L_33 ) ;
if ( ! V_120 )
return - 1 ;
if ( ! strncmp ( V_120 , L_34 , strlen ( V_118 ) ) )
V_78 . V_79 = V_123 ;
else if ( ! strncmp ( V_120 , L_35 , strlen ( V_118 ) ) )
V_78 . V_79 = V_124 ;
else if ( ! strncmp ( V_120 , L_36 , strlen ( V_118 ) ) )
V_78 . V_79 = V_125 ;
else if ( ! strncmp ( V_120 , L_37 , strlen ( V_118 ) ) ) {
V_78 . V_79 = V_80 ;
V_22 . V_23 = false ;
return 0 ;
}
else
return - 1 ;
V_120 = strtok ( NULL , L_33 ) ;
if ( ! V_120 )
goto V_126;
V_78 . V_127 = strtod ( V_120 , & V_122 ) ;
if ( V_120 == V_122 )
return - 1 ;
V_121 = strtok ( NULL , L_33 ) ;
if ( ! V_121 )
goto V_126;
if ( V_121 [ 0 ] != 'c' ) {
V_78 . V_128 = strtoul ( V_121 , & V_122 , 0 ) ;
V_121 = strtok ( NULL , L_33 ) ;
if ( ! V_121 )
goto V_126;
}
if ( ! strcmp ( V_121 , L_38 ) )
V_78 . V_129 = V_130 ;
else if ( ! strcmp ( V_121 , L_39 ) )
V_78 . V_129 = V_131 ;
else
return - 1 ;
V_126:
if ( F_24 ( & V_78 ) < 0 ) {
fprintf ( V_52 , L_40 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_48 ( const struct V_116 * V_117 V_61 , const char * T_5 V_61 , int V_119 )
{
V_58 = ! V_119 ;
return 0 ;
}
int F_49 ( int V_132 , const char * * V_133 , const char * T_6 V_61 )
{
struct V_71 * V_73 ;
struct V_134 V_135 ;
bool V_136 = false ;
int V_85 = - 1 ;
char V_137 [] = L_41 ;
const char * const V_138 [] = {
L_42 ,
NULL
} ;
struct V_10 V_139 = {
. V_2 = {
. V_6 = F_14 ,
. V_140 = V_141 ,
. V_142 = V_143 ,
. exit = V_144 ,
. V_145 = V_144 ,
. V_146 = V_147 ,
. V_65 = F_18 ,
. V_148 = V_149 ,
. V_150 = V_151 ,
. V_152 = V_153 ,
. V_154 = V_155 ,
. V_156 = true ,
. V_157 = true ,
} ,
. V_97 = L_43 ,
} ;
const struct V_116 V_158 [] = {
F_50 ( 'i' , L_44 , & V_139 . V_159 , L_45 ,
L_46 ) ,
F_51 ( 'v' , L_47 , & V_113 ,
L_48 ) ,
F_52 ( 'D' , L_49 , & V_112 ,
L_50 ) ,
F_50 ( 'k' , L_51 , & V_22 . V_160 ,
L_45 , L_52 ) ,
F_50 ( 0 , L_53 , & V_22 . V_161 ,
L_45 , L_54 ) ,
F_52 ( 'f' , L_55 , & V_139 . V_162 , L_56 ) ,
F_52 ( 'm' , L_57 , & V_22 . V_163 ,
L_58 ) ,
F_52 ( 'n' , L_59 , & V_22 . V_164 ,
L_60 ) ,
F_52 ( 'T' , L_61 , & V_139 . V_62 ,
L_62 ) ,
F_50 ( 0 , L_63 , & V_139 . V_97 , L_64 ,
L_65 ) ,
F_52 ( 0 , L_66 , & V_139 . V_165 , L_67 ) ,
F_52 ( 0 , L_68 , & V_139 . V_166 , L_69 ) ,
F_52 ( 0 , L_70 , & V_139 . V_167 ,
L_71 ) ,
F_50 ( 's' , L_72 , & V_92 , L_73 ,
L_74
L_75 ) ,
F_52 ( 0 , L_76 , & V_22 . V_168 ,
L_77 ) ,
F_50 ( 'p' , L_78 , & V_94 , L_79 ,
L_80 ) ,
F_52 ( 'x' , L_81 , & V_22 . V_169 ,
L_82 ) ,
F_53 ( 'g' , L_83 , & V_139 , L_84 ,
L_85
L_86 , & F_47 , V_137 ) ,
F_52 ( 'G' , L_87 , & V_139 . V_170 ,
L_88 ) ,
F_50 ( 'd' , L_89 , & V_22 . V_171 , L_90 ,
L_91 ) ,
F_50 ( 'c' , L_92 , & V_22 . V_172 , L_93 ,
L_94 ) ,
F_50 ( 'S' , L_95 , & V_22 . V_173 , L_96 ,
L_97 ) ,
F_50 ( 0 , L_98 , & V_139 . V_114 , L_99 ,
L_100 ) ,
F_50 ( 'w' , L_101 , & V_22 . V_174 ,
L_102 ,
L_103 ) ,
F_50 ( 't' , L_104 , & V_22 . V_175 , L_105 ,
L_106
L_107 ) ,
F_52 ( 'U' , L_108 , & V_139 . V_29 ,
L_109 ) ,
F_50 ( 0 , L_110 , & V_22 . V_176 , L_111 ,
L_112 ) ,
F_50 ( 'C' , L_113 , & V_139 . V_55 , L_113 ,
L_114 ) ,
F_52 ( 'I' , L_115 , & V_139 . V_104 ,
L_116 ) ,
F_52 ( 0 , L_117 , & V_22 . V_177 ,
L_118 ) ,
F_52 ( 0 , L_119 , & V_22 . V_178 ,
L_120 ) ,
F_50 ( 'M' , L_121 , & V_179 , L_122 ,
L_123 ) ,
F_52 ( 0 , L_124 , & V_22 . V_180 ,
L_125 ) ,
F_54 ( 'b' , L_126 , & V_58 , L_127 ,
L_128 , F_48 ) ,
F_55 ()
} ;
V_132 = F_56 ( V_132 , V_133 , V_158 , V_138 , 0 ) ;
if ( V_139 . V_167 )
V_36 = 0 ;
else if ( V_139 . V_165 )
V_36 = 1 ;
else if ( V_139 . V_166 )
V_36 = 2 ;
if ( V_139 . V_170 )
V_78 . V_129 = V_130 ;
if ( ! V_139 . V_159 || ! strlen ( V_139 . V_159 ) ) {
if ( ! F_57 ( V_181 , & V_135 ) && F_58 ( V_135 . V_182 ) )
V_139 . V_159 = L_129 ;
else
V_139 . V_159 = L_130 ;
}
V_73 = F_59 ( V_139 . V_159 , V_183 ,
V_139 . V_162 , false , & V_139 . V_2 ) ;
if ( V_73 == NULL )
return - V_27 ;
V_139 . V_73 = V_73 ;
V_136 = F_60 ( & V_73 -> V_53 ,
V_184 ) ;
if ( V_58 == - 1 && V_136 )
V_58 = 1 ;
if ( V_58 == 1 ) {
if ( V_92 == V_93 )
V_92 = L_131
L_132 ;
}
if ( strcmp ( V_139 . V_159 , L_129 ) != 0 ) {
if ( V_139 . V_166 )
F_61 ( V_132 , V_133 , true ) ;
else
F_62 ( true ) ;
} else {
V_36 = 0 ;
}
if ( V_36 > 0 ) {
V_22 . V_185 = sizeof( struct V_34 ) ;
V_139 . V_51 = V_186 ;
if ( V_113 ) {
V_22 . V_185 += sizeof( V_187 ) ;
V_22 . V_188 = true ;
}
}
if ( F_63 () < 0 )
goto error;
F_64 ( V_138 , V_158 ) ;
if ( V_94 != V_95 ) {
if ( F_65 ( L_78 ) < 0 )
goto error;
if ( ! strstr ( V_92 , L_78 ) )
V_189 . V_190 = 1 ;
} else
V_22 . V_169 = false ;
if ( V_132 ) {
if ( V_132 > 1 )
F_66 ( V_138 , V_158 ) ;
V_139 . V_114 = V_133 [ 0 ] ;
}
F_67 ( & V_191 , V_22 . V_192 , L_133 , stdout ) ;
if ( V_58 == 1 ) {
F_67 ( & V_193 , V_22 . V_194 , L_134 , stdout ) ;
F_67 ( & V_195 , V_22 . V_196 , L_135 , stdout ) ;
F_67 ( & V_197 , V_22 . V_198 , L_136 , stdout ) ;
F_67 ( & V_199 , V_22 . V_200 , L_137 , stdout ) ;
} else {
F_67 ( & V_201 , V_22 . V_202 , L_138 , stdout ) ;
F_67 ( & V_203 , V_22 . V_204 , L_139 , stdout ) ;
}
V_85 = F_33 ( & V_139 ) ;
error:
F_68 ( V_73 ) ;
return V_85 ;
}
