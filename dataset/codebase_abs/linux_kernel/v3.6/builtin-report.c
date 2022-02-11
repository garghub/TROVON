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
V_14 = F_3 ( V_9 , V_4 -> V_25 ,
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
V_14 = F_3 ( V_9 , V_4 -> V_25 ,
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
T_1 V_74 = F_23 ( V_72 -> V_75 ) ;
if ( ! V_72 -> V_76 && ! ( V_74 & V_77 ) ) {
if ( V_21 ) {
F_24 ( L_8
L_9
L_10 ) ;
return - V_78 ;
}
if ( V_22 . V_23 ) {
F_24 ( L_11
L_12 ) ;
return - 1 ;
}
} else if ( ! V_11 -> V_79 &&
V_80 . V_81 != V_82 &&
! V_22 . V_23 ) {
V_22 . V_23 = true ;
if ( F_25 ( & V_80 ) < 0 ) {
F_24 ( L_13 ) ;
return - V_78 ;
}
}
if ( V_58 == 1 ) {
if ( ! V_72 -> V_76 &&
! ( V_74 & V_83 ) ) {
F_24 ( L_14
L_15 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_26 ( int T_2 V_61 )
{
V_84 = 1 ;
}
static T_3 F_27 ( struct V_33 * V_72 ,
const char * V_85 , T_4 * V_86 )
{
T_3 V_87 ;
char V_88 ;
unsigned long V_89 = V_72 -> V_42 . V_90 [ V_44 ] ;
T_1 V_90 = V_72 -> V_42 . V_43 ;
V_89 = F_28 ( V_89 , & V_88 ) ;
V_87 = fprintf ( V_86 , L_16 , V_89 , V_88 ) ;
if ( V_85 != NULL )
V_87 += fprintf ( V_86 , L_17 , V_85 ) ;
V_87 += fprintf ( V_86 , L_18 V_70 , V_90 ) ;
return V_87 + fprintf ( V_86 , L_19 ) ;
}
static int F_29 ( struct V_91 * V_75 ,
struct V_10 * V_11 ,
const char * V_92 )
{
struct V_7 * V_93 ;
F_30 (pos, &evlist->entries, node) {
struct V_33 * V_33 = & V_93 -> V_33 ;
const char * V_85 = F_19 ( V_93 ) ;
F_27 ( V_33 , V_85 , stdout ) ;
F_31 ( V_33 , NULL , false , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_20 ) ;
}
if ( V_94 == V_95 &&
V_96 == V_97 ) {
fprintf ( stdout , L_21 , V_92 ) ;
if ( V_11 -> V_62 ) {
bool V_98 = ! strcmp ( V_11 -> V_99 , L_22 ) ;
F_32 ( stdout , & V_11 -> V_64 ,
V_98 ) ;
F_33 ( & V_11 -> V_64 ) ;
}
}
return 0 ;
}
static int F_34 ( struct V_10 * V_11 )
{
int V_87 = - V_78 ;
T_1 V_89 ;
struct V_71 * V_73 = V_11 -> V_73 ;
struct V_7 * V_93 ;
struct V_39 * V_100 ;
struct V_101 * V_102 ;
const char * V_92 = L_23 ;
signal ( V_103 , F_26 ) ;
if ( V_11 -> V_55 ) {
V_87 = F_35 ( V_73 , V_11 -> V_55 ,
V_11 -> V_57 ) ;
if ( V_87 )
goto V_104;
}
if ( V_36 <= 0 )
F_36 ( V_73 , stdout , V_11 -> V_105 ) ;
if ( V_11 -> V_62 )
F_37 ( & V_11 -> V_64 ) ;
V_87 = F_22 ( V_11 ) ;
if ( V_87 )
goto V_104;
V_87 = F_38 ( V_73 , & V_11 -> V_2 ) ;
if ( V_87 )
goto V_104;
V_100 = V_73 -> V_106 . V_107 [ V_108 ] ;
V_102 = F_39 ( V_100 ) ;
if ( V_100 == NULL ||
( V_100 -> V_59 -> V_60 &&
( V_102 -> V_109 == NULL ||
V_102 -> V_109 -> V_48 == 0 ) ) ) {
const char * V_110 =
L_24
L_25 ;
if ( V_100 ) {
const struct V_59 * V_111 = V_100 -> V_59 ;
if ( ! F_40 ( & V_111 -> V_112 [ V_108 ] ) ) {
V_110 = L_26
L_27 ;
}
}
F_41 (
L_28
L_29
L_30 ,
V_110 ) ;
}
if ( V_113 ) {
F_42 ( V_73 , stdout ) ;
goto V_104;
}
if ( V_114 > 3 )
F_43 ( V_73 , stdout ) ;
if ( V_114 > 2 )
F_44 ( V_73 , stdout ) ;
V_89 = 0 ;
F_30 (pos, &session->evlist->entries, node) {
struct V_33 * V_33 = & V_93 -> V_33 ;
if ( V_93 -> V_40 == 0 )
V_33 -> V_115 = V_11 -> V_115 ;
F_45 ( V_33 ) ;
F_46 ( V_33 ) ;
V_89 += V_33 -> V_42 . V_90 [ V_44 ] ;
}
if ( V_89 == 0 ) {
F_24 ( L_31 , V_73 -> V_116 ) ;
goto V_104;
}
if ( V_36 > 0 ) {
if ( V_36 == 1 ) {
F_47 ( V_73 -> V_75 , V_92 ,
NULL , NULL , 0 ) ;
} else if ( V_36 == 2 ) {
F_48 ( V_73 -> V_75 , V_92 ,
NULL , NULL , 0 ) ;
}
} else
F_29 ( V_73 -> V_75 , V_11 , V_92 ) ;
V_104:
return V_87 ;
}
static int
F_49 ( const struct V_117 * V_118 , const char * V_119 , int V_120 )
{
struct V_10 * V_11 = (struct V_10 * ) V_118 -> V_69 ;
char * V_121 , * V_122 ;
char * V_123 ;
if ( V_120 ) {
V_11 -> V_79 = true ;
return 0 ;
}
V_22 . V_23 = true ;
if ( ! V_119 )
return 0 ;
V_121 = strtok ( ( char * ) V_119 , L_32 ) ;
if ( ! V_121 )
return - 1 ;
if ( ! strncmp ( V_121 , L_33 , strlen ( V_119 ) ) )
V_80 . V_81 = V_124 ;
else if ( ! strncmp ( V_121 , L_34 , strlen ( V_119 ) ) )
V_80 . V_81 = V_125 ;
else if ( ! strncmp ( V_121 , L_35 , strlen ( V_119 ) ) )
V_80 . V_81 = V_126 ;
else if ( ! strncmp ( V_121 , L_36 , strlen ( V_119 ) ) ) {
V_80 . V_81 = V_82 ;
V_22 . V_23 = false ;
return 0 ;
}
else
return - 1 ;
V_121 = strtok ( NULL , L_32 ) ;
if ( ! V_121 )
goto V_127;
V_80 . V_128 = strtod ( V_121 , & V_123 ) ;
if ( V_121 == V_123 )
return - 1 ;
V_122 = strtok ( NULL , L_32 ) ;
if ( ! V_122 )
goto V_127;
if ( V_122 [ 0 ] != 'c' ) {
V_80 . V_129 = strtoul ( V_122 , & V_123 , 0 ) ;
V_122 = strtok ( NULL , L_32 ) ;
if ( ! V_122 )
goto V_127;
}
if ( ! strcmp ( V_122 , L_37 ) )
V_80 . V_130 = V_131 ;
else if ( ! strcmp ( V_122 , L_38 ) )
V_80 . V_130 = V_132 ;
else
return - 1 ;
V_127:
if ( F_25 ( & V_80 ) < 0 ) {
fprintf ( V_52 , L_39 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_50 ( const struct V_117 * V_118 V_61 , const char * T_5 V_61 , int V_120 )
{
V_58 = ! V_120 ;
return 0 ;
}
int F_51 ( int V_133 , const char * * V_134 , const char * T_6 V_61 )
{
struct V_71 * V_73 ;
struct V_135 V_136 ;
bool V_137 = false ;
int V_87 = - 1 ;
char V_138 [] = L_40 ;
const char * const V_139 [] = {
L_41 ,
NULL
} ;
struct V_10 V_140 = {
. V_2 = {
. V_6 = F_14 ,
. V_141 = V_142 ,
. V_143 = V_144 ,
. exit = V_145 ,
. V_146 = V_145 ,
. V_147 = V_148 ,
. V_65 = F_18 ,
. V_149 = V_150 ,
. V_151 = V_152 ,
. V_153 = V_154 ,
. V_155 = V_156 ,
. V_157 = true ,
. V_158 = true ,
} ,
. V_99 = L_42 ,
} ;
const struct V_117 V_159 [] = {
F_52 ( 'i' , L_43 , & V_140 . V_160 , L_44 ,
L_45 ) ,
F_53 ( 'v' , L_46 , & V_114 ,
L_47 ) ,
F_54 ( 'D' , L_48 , & V_113 ,
L_49 ) ,
F_52 ( 'k' , L_50 , & V_22 . V_161 ,
L_44 , L_51 ) ,
F_52 ( 0 , L_52 , & V_22 . V_162 ,
L_44 , L_53 ) ,
F_54 ( 'f' , L_54 , & V_140 . V_163 , L_55 ) ,
F_54 ( 'm' , L_56 , & V_22 . V_164 ,
L_57 ) ,
F_54 ( 'n' , L_58 , & V_22 . V_165 ,
L_59 ) ,
F_54 ( 'T' , L_60 , & V_140 . V_62 ,
L_61 ) ,
F_52 ( 0 , L_62 , & V_140 . V_99 , L_63 ,
L_64 ) ,
F_54 ( 0 , L_65 , & V_140 . V_166 , L_66 ) ,
F_54 ( 0 , L_67 , & V_140 . V_167 , L_68 ) ,
F_54 ( 0 , L_69 , & V_140 . V_168 ,
L_70 ) ,
F_52 ( 's' , L_71 , & V_94 , L_72 ,
L_73
L_74 ) ,
F_54 ( 0 , L_75 , & V_22 . V_169 ,
L_76 ) ,
F_52 ( 'p' , L_77 , & V_96 , L_78 ,
L_79 ) ,
F_54 ( 'x' , L_80 , & V_22 . V_170 ,
L_81 ) ,
F_55 ( 'g' , L_82 , & V_140 , L_83 ,
L_84
L_85 , & F_49 , V_138 ) ,
F_54 ( 'G' , L_86 , & V_140 . V_171 ,
L_87 ) ,
F_52 ( 'd' , L_88 , & V_22 . V_172 , L_89 ,
L_90 ) ,
F_52 ( 'c' , L_91 , & V_22 . V_173 , L_92 ,
L_93 ) ,
F_52 ( 'S' , L_94 , & V_22 . V_174 , L_95 ,
L_96 ) ,
F_52 ( 0 , L_97 , & V_140 . V_115 , L_98 ,
L_99 ) ,
F_52 ( 'w' , L_100 , & V_22 . V_175 ,
L_101 ,
L_102 ) ,
F_52 ( 't' , L_103 , & V_22 . V_176 , L_104 ,
L_105
L_106 ) ,
F_54 ( 'U' , L_107 , & V_140 . V_29 ,
L_108 ) ,
F_52 ( 0 , L_109 , & V_22 . V_177 , L_110 ,
L_111 ) ,
F_52 ( 'C' , L_112 , & V_140 . V_55 , L_112 ,
L_113 ) ,
F_54 ( 'I' , L_114 , & V_140 . V_105 ,
L_115 ) ,
F_54 ( 0 , L_116 , & V_22 . V_178 ,
L_117 ) ,
F_54 ( 0 , L_118 , & V_22 . V_179 ,
L_119 ) ,
F_52 ( 'M' , L_120 , & V_180 , L_121 ,
L_122 ) ,
F_54 ( 0 , L_123 , & V_22 . V_181 ,
L_124 ) ,
F_56 ( 'b' , L_125 , & V_58 , L_126 ,
L_127 , F_50 ) ,
F_57 ()
} ;
V_133 = F_58 ( V_133 , V_134 , V_159 , V_139 , 0 ) ;
if ( V_140 . V_168 )
V_36 = 0 ;
else if ( V_140 . V_166 )
V_36 = 1 ;
else if ( V_140 . V_167 )
V_36 = 2 ;
if ( V_140 . V_171 )
V_80 . V_130 = V_131 ;
if ( ! V_140 . V_160 || ! strlen ( V_140 . V_160 ) ) {
if ( ! F_59 ( V_182 , & V_136 ) && F_60 ( V_136 . V_183 ) )
V_140 . V_160 = L_128 ;
else
V_140 . V_160 = L_129 ;
}
V_73 = F_61 ( V_140 . V_160 , V_184 ,
V_140 . V_163 , false , & V_140 . V_2 ) ;
if ( V_73 == NULL )
return - V_27 ;
V_140 . V_73 = V_73 ;
V_137 = F_62 ( & V_73 -> V_53 ,
V_185 ) ;
if ( V_58 == - 1 && V_137 )
V_58 = 1 ;
if ( V_58 == 1 ) {
if ( V_94 == V_95 )
V_94 = L_130
L_131 ;
}
if ( strcmp ( V_140 . V_160 , L_128 ) != 0 )
F_63 ( true ) ;
else
V_36 = 0 ;
if ( V_36 > 0 ) {
V_22 . V_186 = sizeof( struct V_34 ) ;
V_140 . V_51 = V_187 ;
if ( V_114 ) {
V_22 . V_186 += sizeof( V_188 ) ;
V_22 . V_189 = true ;
}
}
if ( F_64 () < 0 )
goto error;
F_65 ( V_139 , V_159 ) ;
if ( V_96 != V_97 ) {
if ( F_66 ( L_77 ) < 0 )
goto error;
if ( ! strstr ( V_94 , L_77 ) )
V_190 . V_191 = 1 ;
} else
V_22 . V_170 = false ;
if ( V_133 ) {
if ( V_133 > 1 )
F_67 ( V_139 , V_159 ) ;
V_140 . V_115 = V_134 [ 0 ] ;
}
F_68 ( & V_192 , V_22 . V_193 , L_132 , stdout ) ;
if ( V_58 == 1 ) {
F_68 ( & V_194 , V_22 . V_195 , L_133 , stdout ) ;
F_68 ( & V_196 , V_22 . V_197 , L_134 , stdout ) ;
F_68 ( & V_198 , V_22 . V_199 , L_135 , stdout ) ;
F_68 ( & V_200 , V_22 . V_201 , L_136 , stdout ) ;
} else {
F_68 ( & V_202 , V_22 . V_203 , L_137 , stdout ) ;
F_68 ( & V_204 , V_22 . V_205 , L_138 , stdout ) ;
}
V_87 = F_34 ( & V_140 ) ;
error:
F_69 ( V_73 ) ;
return V_87 ;
}
