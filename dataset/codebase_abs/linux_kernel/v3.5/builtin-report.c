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
& V_46 ,
V_6 -> V_45 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_17 -> V_47 . V_31 != NULL && V_36 > 0 ) {
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
F_23 ( L_13 ) ;
return - V_76 ;
}
}
if ( V_58 == 1 ) {
if ( ! ( V_72 -> V_74 & V_81 ) ) {
F_23 ( L_14
L_15 ) ;
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
unsigned long V_87 = V_72 -> V_42 . V_88 [ V_44 ] ;
T_4 V_88 = V_72 -> V_42 . V_43 ;
V_87 = F_27 ( V_87 , & V_86 ) ;
V_85 = fprintf ( V_84 , L_16 , V_87 , V_86 ) ;
if ( V_83 != NULL )
V_85 += fprintf ( V_84 , L_17 , V_83 ) ;
V_85 += fprintf ( V_84 , L_18 V_70 , V_88 ) ;
return V_85 + fprintf ( V_84 , L_19 ) ;
}
static int F_28 ( struct V_89 * V_90 ,
struct V_10 * V_11 ,
const char * V_91 )
{
struct V_7 * V_92 ;
F_29 (pos, &evlist->entries, node) {
struct V_33 * V_33 = & V_92 -> V_33 ;
const char * V_83 = F_19 ( V_92 ) ;
F_26 ( V_33 , V_83 , stdout ) ;
F_30 ( V_33 , NULL , false , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_20 ) ;
}
if ( V_93 == V_94 &&
V_95 == V_96 ) {
fprintf ( stdout , L_21 , V_91 ) ;
if ( V_11 -> V_62 ) {
bool V_97 = ! strcmp ( V_11 -> V_98 , L_22 ) ;
F_31 ( stdout , & V_11 -> V_64 ,
V_97 ) ;
F_32 ( & V_11 -> V_64 ) ;
}
}
return 0 ;
}
static int F_33 ( struct V_10 * V_11 )
{
int V_85 = - V_76 ;
T_4 V_87 ;
struct V_71 * V_73 = V_11 -> V_73 ;
struct V_7 * V_92 ;
struct V_39 * V_99 ;
struct V_100 * V_101 ;
const char * V_91 = L_23 ;
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
L_24
L_25 ;
if ( V_99 ) {
const struct V_59 * V_110 = V_99 -> V_59 ;
if ( ! F_39 ( & V_110 -> V_111 [ V_107 ] ) ) {
V_109 = L_26
L_27 ;
}
}
F_40 (
L_28
L_29
L_30 ,
V_109 ) ;
}
if ( V_112 ) {
F_41 ( V_73 , stdout ) ;
goto V_103;
}
if ( V_113 > 3 )
F_42 ( V_73 , stdout ) ;
if ( V_113 > 2 )
F_43 ( V_73 , stdout ) ;
V_87 = 0 ;
F_29 (pos, &session->evlist->entries, node) {
struct V_33 * V_33 = & V_92 -> V_33 ;
if ( V_92 -> V_40 == 0 )
V_33 -> V_114 = V_11 -> V_114 ;
F_44 ( V_33 ) ;
F_45 ( V_33 ) ;
V_87 += V_33 -> V_42 . V_88 [ V_44 ] ;
}
if ( V_87 == 0 ) {
F_23 ( L_31 , V_73 -> V_115 ) ;
goto V_103;
}
if ( V_36 > 0 ) {
if ( V_36 == 1 ) {
F_46 ( V_73 -> V_90 , V_91 ,
NULL , NULL , 0 ) ;
} else if ( V_36 == 2 ) {
F_47 ( V_73 -> V_90 , V_91 ,
NULL , NULL , 0 ) ;
}
} else
F_28 ( V_73 -> V_90 , V_11 , V_91 ) ;
V_103:
return V_85 ;
}
static int
F_48 ( const struct V_116 * V_117 , const char * V_118 , int V_119 )
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
V_120 = strtok ( ( char * ) V_118 , L_32 ) ;
if ( ! V_120 )
return - 1 ;
if ( ! strncmp ( V_120 , L_33 , strlen ( V_118 ) ) )
V_78 . V_79 = V_123 ;
else if ( ! strncmp ( V_120 , L_34 , strlen ( V_118 ) ) )
V_78 . V_79 = V_124 ;
else if ( ! strncmp ( V_120 , L_35 , strlen ( V_118 ) ) )
V_78 . V_79 = V_125 ;
else if ( ! strncmp ( V_120 , L_36 , strlen ( V_118 ) ) ) {
V_78 . V_79 = V_80 ;
V_22 . V_23 = false ;
return 0 ;
}
else
return - 1 ;
V_120 = strtok ( NULL , L_32 ) ;
if ( ! V_120 )
goto V_126;
V_78 . V_127 = strtod ( V_120 , & V_122 ) ;
if ( V_120 == V_122 )
return - 1 ;
V_121 = strtok ( NULL , L_32 ) ;
if ( ! V_121 )
goto V_126;
if ( V_121 [ 0 ] != 'c' ) {
V_78 . V_128 = strtoul ( V_121 , & V_122 , 0 ) ;
V_121 = strtok ( NULL , L_32 ) ;
if ( ! V_121 )
goto V_126;
}
if ( ! strcmp ( V_121 , L_37 ) )
V_78 . V_129 = V_130 ;
else if ( ! strcmp ( V_121 , L_38 ) )
V_78 . V_129 = V_131 ;
else
return - 1 ;
V_126:
if ( F_24 ( & V_78 ) < 0 ) {
fprintf ( V_52 , L_39 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_49 ( const struct V_116 * V_117 V_61 , const char * T_5 V_61 , int V_119 )
{
V_58 = ! V_119 ;
return 0 ;
}
int F_50 ( int V_132 , const char * * V_133 , const char * T_6 V_61 )
{
struct V_71 * V_73 ;
struct V_134 V_135 ;
bool V_136 = false ;
int V_85 = - 1 ;
char V_137 [] = L_40 ;
const char * const V_138 [] = {
L_41 ,
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
. V_98 = L_42 ,
} ;
const struct V_116 V_158 [] = {
F_51 ( 'i' , L_43 , & V_139 . V_159 , L_44 ,
L_45 ) ,
F_52 ( 'v' , L_46 , & V_113 ,
L_47 ) ,
F_53 ( 'D' , L_48 , & V_112 ,
L_49 ) ,
F_51 ( 'k' , L_50 , & V_22 . V_160 ,
L_44 , L_51 ) ,
F_51 ( 0 , L_52 , & V_22 . V_161 ,
L_44 , L_53 ) ,
F_53 ( 'f' , L_54 , & V_139 . V_162 , L_55 ) ,
F_53 ( 'm' , L_56 , & V_22 . V_163 ,
L_57 ) ,
F_53 ( 'n' , L_58 , & V_22 . V_164 ,
L_59 ) ,
F_53 ( 'T' , L_60 , & V_139 . V_62 ,
L_61 ) ,
F_51 ( 0 , L_62 , & V_139 . V_98 , L_63 ,
L_64 ) ,
F_53 ( 0 , L_65 , & V_139 . V_165 , L_66 ) ,
F_53 ( 0 , L_67 , & V_139 . V_166 , L_68 ) ,
F_53 ( 0 , L_69 , & V_139 . V_167 ,
L_70 ) ,
F_51 ( 's' , L_71 , & V_93 , L_72 ,
L_73
L_74 ) ,
F_53 ( 0 , L_75 , & V_22 . V_168 ,
L_76 ) ,
F_51 ( 'p' , L_77 , & V_95 , L_78 ,
L_79 ) ,
F_53 ( 'x' , L_80 , & V_22 . V_169 ,
L_81 ) ,
F_54 ( 'g' , L_82 , & V_139 , L_83 ,
L_84
L_85 , & F_48 , V_137 ) ,
F_53 ( 'G' , L_86 , & V_139 . V_170 ,
L_87 ) ,
F_51 ( 'd' , L_88 , & V_22 . V_171 , L_89 ,
L_90 ) ,
F_51 ( 'c' , L_91 , & V_22 . V_172 , L_92 ,
L_93 ) ,
F_51 ( 'S' , L_94 , & V_22 . V_173 , L_95 ,
L_96 ) ,
F_51 ( 0 , L_97 , & V_139 . V_114 , L_98 ,
L_99 ) ,
F_51 ( 'w' , L_100 , & V_22 . V_174 ,
L_101 ,
L_102 ) ,
F_51 ( 't' , L_103 , & V_22 . V_175 , L_104 ,
L_105
L_106 ) ,
F_53 ( 'U' , L_107 , & V_139 . V_29 ,
L_108 ) ,
F_51 ( 0 , L_109 , & V_22 . V_176 , L_110 ,
L_111 ) ,
F_51 ( 'C' , L_112 , & V_139 . V_55 , L_112 ,
L_113 ) ,
F_53 ( 'I' , L_114 , & V_139 . V_104 ,
L_115 ) ,
F_53 ( 0 , L_116 , & V_22 . V_177 ,
L_117 ) ,
F_53 ( 0 , L_118 , & V_22 . V_178 ,
L_119 ) ,
F_51 ( 'M' , L_120 , & V_179 , L_121 ,
L_122 ) ,
F_53 ( 0 , L_123 , & V_22 . V_180 ,
L_124 ) ,
F_55 ( 'b' , L_125 , & V_58 , L_126 ,
L_127 , F_49 ) ,
F_56 ()
} ;
V_132 = F_57 ( V_132 , V_133 , V_158 , V_138 , 0 ) ;
if ( V_139 . V_167 )
V_36 = 0 ;
else if ( V_139 . V_165 )
V_36 = 1 ;
else if ( V_139 . V_166 )
V_36 = 2 ;
if ( V_139 . V_170 )
V_78 . V_129 = V_130 ;
if ( ! V_139 . V_159 || ! strlen ( V_139 . V_159 ) ) {
if ( ! F_58 ( V_181 , & V_135 ) && F_59 ( V_135 . V_182 ) )
V_139 . V_159 = L_128 ;
else
V_139 . V_159 = L_129 ;
}
V_73 = F_60 ( V_139 . V_159 , V_183 ,
V_139 . V_162 , false , & V_139 . V_2 ) ;
if ( V_73 == NULL )
return - V_27 ;
V_139 . V_73 = V_73 ;
V_136 = F_61 ( & V_73 -> V_53 ,
V_184 ) ;
if ( V_58 == - 1 && V_136 )
V_58 = 1 ;
if ( V_58 == 1 ) {
if ( V_93 == V_94 )
V_93 = L_130
L_131 ;
}
if ( strcmp ( V_139 . V_159 , L_128 ) != 0 )
F_62 ( true ) ;
else
V_36 = 0 ;
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
if ( V_95 != V_96 ) {
if ( F_65 ( L_77 ) < 0 )
goto error;
if ( ! strstr ( V_93 , L_77 ) )
V_189 . V_190 = 1 ;
} else
V_22 . V_169 = false ;
if ( V_132 ) {
if ( V_132 > 1 )
F_66 ( V_138 , V_158 ) ;
V_139 . V_114 = V_133 [ 0 ] ;
}
F_67 ( & V_191 , V_22 . V_192 , L_132 , stdout ) ;
if ( V_58 == 1 ) {
F_67 ( & V_193 , V_22 . V_194 , L_133 , stdout ) ;
F_67 ( & V_195 , V_22 . V_196 , L_134 , stdout ) ;
F_67 ( & V_197 , V_22 . V_198 , L_135 , stdout ) ;
F_67 ( & V_199 , V_22 . V_200 , L_136 , stdout ) ;
} else {
F_67 ( & V_201 , V_22 . V_202 , L_137 , stdout ) ;
F_67 ( & V_203 , V_22 . V_204 , L_138 , stdout ) ;
}
V_85 = F_33 ( & V_139 ) ;
error:
F_68 ( V_73 ) ;
return V_85 ;
}
