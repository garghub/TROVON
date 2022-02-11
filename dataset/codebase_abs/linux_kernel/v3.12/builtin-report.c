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
return F_3 ( V_1 , V_2 , V_3 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_17 ,
union V_18 * V_19 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_20 * V_21 = NULL ;
T_1 V_22 = V_19 -> V_23 . V_24 & V_25 ;
int V_26 = 0 ;
struct V_27 * V_28 ;
struct V_29 * V_30 , * V_31 ;
T_2 V_32 ;
if ( ( V_33 || V_4 . V_34 ) &&
V_14 -> V_35 ) {
V_26 = F_6 ( V_17 , V_16 , V_12 -> V_36 ,
V_14 , & V_21 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
V_30 = F_7 ( V_17 , V_12 -> V_36 , V_14 , V_22 ) ;
if ( ! V_30 )
return - V_37 ;
if ( V_7 -> V_38 && ! V_12 -> V_39 )
return 0 ;
V_32 = V_14 -> V_40 ;
if ( ! V_32 )
V_32 = 1 ;
V_28 = F_8 ( & V_16 -> V_41 , V_12 , V_21 , V_30 , V_32 , V_32 ) ;
if ( ! V_28 )
return - V_37 ;
if ( V_42 && V_28 -> V_43 . V_39 && V_44 > 0 ) {
struct V_45 * V_46 = F_9 ( V_28 -> V_43 . V_39 ) ;
assert ( V_16 != NULL ) ;
if ( V_46 -> V_47 == NULL && F_10 ( V_28 -> V_43 . V_39 ) < 0 )
goto V_48;
V_26 = F_11 ( V_28 , V_16 -> V_49 , V_12 -> V_50 ) ;
if ( V_26 )
goto V_48;
}
if ( V_42 && V_28 -> V_29 -> V_51 . V_39 && V_44 > 0 ) {
struct V_45 * V_46 ;
V_31 = V_28 -> V_29 ;
V_46 = F_9 ( V_31 -> V_51 . V_39 ) ;
if ( V_46 -> V_47 == NULL && F_10 ( V_31 -> V_51 . V_39 ) < 0 )
goto V_48;
V_26 = F_12 ( V_31 -> V_51 . V_39 ,
V_31 -> V_51 . V_52 ,
V_16 -> V_49 ,
V_31 -> V_51 . V_53 ) ;
if ( V_26 )
goto V_48;
}
V_16 -> V_41 . V_54 . V_55 += V_32 ;
F_13 ( & V_16 -> V_41 , V_56 ) ;
V_26 = 0 ;
if ( V_4 . V_34 ) {
V_26 = F_14 ( V_28 -> V_35 ,
& V_57 ,
V_14 -> V_58 ) ;
}
V_48:
return V_26 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_17 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_20 * V_21 = NULL ;
int V_26 = 0 ;
unsigned V_59 ;
struct V_27 * V_28 ;
struct V_60 * V_61 , * V_62 ;
if ( ( V_33 || V_4 . V_34 )
&& V_14 -> V_35 ) {
V_26 = F_6 ( V_17 , V_16 , V_12 -> V_36 ,
V_14 , & V_21 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
V_61 = F_16 ( V_17 , V_12 -> V_36 ,
V_14 -> V_63 ) ;
if ( ! V_61 )
return - V_37 ;
for ( V_59 = 0 ; V_59 < V_14 -> V_63 -> V_64 ; V_59 ++ ) {
if ( V_7 -> V_38 && ! ( V_61 [ V_59 ] . V_65 . V_39 && V_61 [ V_59 ] . V_66 . V_39 ) )
continue;
V_26 = - V_37 ;
V_28 = F_17 ( & V_16 -> V_41 , V_12 , V_21 ,
& V_61 [ V_59 ] , 1 , 1 ) ;
if ( V_28 ) {
struct V_45 * V_46 ;
V_62 = V_28 -> V_60 ;
if ( V_62 -> V_65 . V_39 && V_44 == 1 && V_42 ) {
V_46 = F_9 ( V_62 -> V_65 . V_39 ) ;
if ( ! V_46 -> V_47
&& F_10 ( V_62 -> V_65 . V_39 ) < 0 )
goto V_48;
V_26 = F_12 ( V_62 -> V_65 . V_39 ,
V_62 -> V_65 . V_52 ,
V_16 -> V_49 ,
V_62 -> V_65 . V_53 ) ;
if ( V_26 )
goto V_48;
}
if ( V_62 -> V_66 . V_39 && V_44 == 1 && V_42 ) {
V_46 = F_9 ( V_62 -> V_66 . V_39 ) ;
if ( ! V_46 -> V_47
&& F_10 ( V_62 -> V_66 . V_39 ) < 0 )
goto V_48;
V_26 = F_12 ( V_62 -> V_66 . V_39 ,
V_62 -> V_66 . V_52 ,
V_16 -> V_49 ,
V_62 -> V_66 . V_53 ) ;
if ( V_26 )
goto V_48;
}
V_16 -> V_41 . V_54 . V_55 += 1 ;
F_13 ( & V_16 -> V_41 , V_56 ) ;
} else
goto V_48;
}
V_26 = 0 ;
V_48:
free ( V_61 ) ;
return V_26 ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_17 * V_17 )
{
struct V_20 * V_21 = NULL ;
int V_26 = 0 ;
struct V_27 * V_28 ;
if ( ( V_33 || V_4 . V_34 ) && V_14 -> V_35 ) {
V_26 = F_6 ( V_17 , V_16 , V_12 -> V_36 ,
V_14 , & V_21 , V_12 ) ;
if ( V_26 )
return V_26 ;
}
V_28 = F_19 ( & V_16 -> V_41 , V_12 , V_21 , V_14 -> V_58 ,
V_14 -> V_40 ) ;
if ( V_28 == NULL )
return - V_37 ;
if ( V_4 . V_34 ) {
V_26 = F_14 ( V_28 -> V_35 ,
& V_57 ,
V_14 -> V_58 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_28 -> V_43 . V_39 != NULL && V_44 == 1 && V_42 ) {
struct V_45 * V_46 = F_9 ( V_28 -> V_43 . V_39 ) ;
assert ( V_16 != NULL ) ;
V_26 = - V_37 ;
if ( V_46 -> V_47 == NULL && F_10 ( V_28 -> V_43 . V_39 ) < 0 )
goto V_48;
V_26 = F_11 ( V_28 , V_16 -> V_49 , V_12 -> V_50 ) ;
}
V_16 -> V_41 . V_54 . V_55 += V_14 -> V_58 ;
F_13 ( & V_16 -> V_41 , V_56 ) ;
V_48:
return V_26 ;
}
static int F_20 ( struct V_9 * V_10 ,
union V_18 * V_19 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_17 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_11 V_12 ;
int V_67 ;
if ( F_21 ( V_19 , V_17 , & V_12 , V_14 ) < 0 ) {
fprintf ( V_68 , L_3 ,
V_19 -> V_23 . type ) ;
return - 1 ;
}
if ( V_12 . V_69 || ( V_7 -> V_38 && V_12 . V_39 == NULL ) )
return 0 ;
if ( V_7 -> V_70 && ! F_22 ( V_14 -> V_71 , V_7 -> V_72 ) )
return 0 ;
if ( V_73 == V_74 ) {
V_67 = F_15 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 ) ;
if ( V_67 < 0 )
F_23 ( L_4 ) ;
} else if ( V_7 -> V_75 == 1 ) {
V_67 = F_4 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 , V_19 ) ;
if ( V_67 < 0 )
F_23 ( L_5 ) ;
} else {
if ( V_12 . V_52 != NULL )
V_12 . V_52 -> V_76 -> V_77 = 1 ;
V_67 = F_18 ( V_16 , & V_12 , V_14 , V_17 ) ;
if ( V_67 < 0 )
F_23 ( L_6 ) ;
}
return V_67 ;
}
static int F_24 ( struct V_9 * V_10 ,
union V_18 * V_19 ,
struct V_13 * V_14 V_78 ,
struct V_15 * V_16 ,
struct V_17 * V_17 V_78 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
if ( V_7 -> V_79 ) {
const char * V_80 = V_16 ? F_25 ( V_16 ) : L_7 ;
F_26 ( & V_7 -> V_81 ,
V_19 -> V_82 . V_83 , V_19 -> V_82 . V_84 ,
V_19 -> V_82 . V_85 ,
V_80 ,
V_19 -> V_82 . V_2 ) ;
}
F_27 ( L_8 V_86 L_9 , V_19 -> V_82 . V_83 , V_19 -> V_82 . V_84 ,
V_16 ? F_25 ( V_16 ) : L_10 ,
V_19 -> V_82 . V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_87 * V_88 = V_7 -> V_89 ;
T_3 V_90 = F_29 ( V_88 -> V_91 ) ;
if ( ! V_88 -> V_92 && ! ( V_90 & V_93 ) ) {
if ( V_33 ) {
F_30 ( L_11
L_12
L_13 ) ;
return - V_94 ;
}
if ( V_4 . V_34 ) {
F_30 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_95 &&
V_96 . V_97 != V_98 &&
! V_4 . V_34 ) {
V_4 . V_34 = true ;
if ( F_31 ( & V_96 ) < 0 ) {
F_30 ( L_16 ) ;
return - V_94 ;
}
}
if ( V_73 == V_74 ) {
if ( ! V_88 -> V_92 &&
! ( V_90 & V_99 ) ) {
F_30 ( L_17
L_18 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_32 ( int T_4 V_78 )
{
V_100 = 1 ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_41 * V_88 ,
const char * V_101 , T_6 * V_102 )
{
T_5 V_67 ;
char V_103 ;
unsigned long V_104 = V_88 -> V_54 . V_105 [ V_56 ] ;
T_3 V_105 = V_88 -> V_54 . V_55 ;
struct V_15 * V_16 = F_34 ( V_88 ) ;
char V_106 [ 512 ] ;
T_5 V_107 = sizeof( V_106 ) ;
if ( F_35 ( V_16 ) ) {
struct V_15 * V_108 ;
F_36 ( V_16 , V_106 , V_107 ) ;
V_101 = V_106 ;
F_37 (pos, evsel) {
V_104 += V_108 -> V_41 . V_54 . V_105 [ V_56 ] ;
V_105 += V_108 -> V_41 . V_54 . V_55 ;
}
}
V_104 = F_38 ( V_104 , & V_103 ) ;
V_67 = fprintf ( V_102 , L_19 , V_104 , V_103 ) ;
if ( V_101 != NULL )
V_67 += fprintf ( V_102 , L_20 , V_101 ) ;
if ( V_7 -> V_75 ) {
V_67 += fprintf ( V_102 , L_21 V_86 , V_105 ) ;
V_67 += fprintf ( V_102 , L_22 , V_109 ) ;
} else
V_67 += fprintf ( V_102 , L_23 V_86 , V_105 ) ;
return V_67 + fprintf ( V_102 , L_24 ) ;
}
static int F_39 ( struct V_110 * V_91 ,
struct V_6 * V_7 ,
const char * V_111 )
{
struct V_15 * V_108 ;
F_40 (pos, &evlist->entries, node) {
struct V_41 * V_41 = & V_108 -> V_41 ;
const char * V_101 = F_25 ( V_108 ) ;
if ( V_4 . V_5 &&
! F_41 ( V_108 ) )
continue;
F_33 ( V_7 , V_41 , V_101 , stdout ) ;
F_42 ( V_41 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_109 == V_112 &&
V_113 == V_114 ) {
fprintf ( stdout , L_26 , V_111 ) ;
if ( V_7 -> V_79 ) {
bool V_115 = ! strcmp ( V_7 -> V_116 , L_27 ) ;
F_43 ( stdout , & V_7 -> V_81 ,
V_115 ) ;
F_44 ( & V_7 -> V_81 ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
int V_67 = - V_94 ;
T_3 V_104 ;
struct V_87 * V_89 = V_7 -> V_89 ;
struct V_15 * V_108 ;
struct V_52 * V_117 ;
struct V_118 * V_119 ;
const char * V_111 = L_28 ;
signal ( V_120 , F_32 ) ;
if ( V_7 -> V_70 ) {
V_67 = F_46 ( V_89 , V_7 -> V_70 ,
V_7 -> V_72 ) ;
if ( V_67 )
return V_67 ;
}
if ( V_44 <= 0 )
F_47 ( V_89 , stdout , V_7 -> V_121 ) ;
if ( V_7 -> V_79 )
F_48 ( & V_7 -> V_81 ) ;
V_67 = F_28 ( V_7 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_49 ( V_89 , & V_7 -> V_10 ) ;
if ( V_67 )
return V_67 ;
V_117 = V_89 -> V_122 . V_123 . V_124 [ V_125 ] ;
V_119 = F_50 ( V_117 ) ;
if ( V_117 == NULL ||
( V_117 -> V_76 -> V_77 &&
( V_119 -> V_126 == NULL ||
V_119 -> V_126 -> V_50 == 0 ) ) ) {
const char * V_127 =
L_29
L_30 ;
if ( V_117 ) {
const struct V_76 * V_128 = V_117 -> V_76 ;
if ( ! F_51 ( & V_128 -> V_129 [ V_125 ] ) ) {
V_127 = L_31
L_32 ;
}
}
F_52 (
L_33
L_34
L_35 ,
V_127 ) ;
}
if ( V_130 > 3 )
F_53 ( V_89 , stdout ) ;
if ( V_130 > 2 )
F_54 ( V_89 , stdout ) ;
if ( V_131 ) {
F_55 ( V_89 , stdout ) ;
return 0 ;
}
V_104 = 0 ;
F_40 (pos, &session->evlist->entries, node) {
struct V_41 * V_41 = & V_108 -> V_41 ;
if ( V_108 -> V_49 == 0 )
V_41 -> V_132 = V_7 -> V_132 ;
F_56 ( V_41 ) ;
V_104 += V_41 -> V_54 . V_105 [ V_56 ] ;
if ( V_4 . V_5 &&
! F_41 ( V_108 ) ) {
struct V_41 * V_133 = & V_108 -> V_134 -> V_41 ;
F_57 ( V_133 , V_41 ) ;
F_58 ( V_133 , V_41 ) ;
}
}
if ( V_100 () )
return 0 ;
if ( V_104 == 0 ) {
F_30 ( L_36 , V_89 -> V_135 ) ;
return 0 ;
}
F_40 (pos, &session->evlist->entries, node)
F_59 ( & V_108 -> V_41 ) ;
if ( V_44 > 0 ) {
if ( V_44 == 1 ) {
V_67 = F_60 ( V_89 -> V_91 ,
V_111 , NULL ,
V_7 -> V_8 ,
& V_89 -> V_23 . V_136 ) ;
if ( V_67 != V_137 )
V_67 = 0 ;
} else if ( V_44 == 2 ) {
F_61 ( V_89 -> V_91 , V_111 ,
NULL , V_7 -> V_8 ) ;
}
} else
F_39 ( V_89 -> V_91 , V_7 , V_111 ) ;
return V_67 ;
}
static int
F_62 ( const struct V_138 * V_139 , const char * V_140 , int V_141 )
{
struct V_6 * V_7 = (struct V_6 * ) V_139 -> V_2 ;
char * V_142 , * V_143 ;
char * V_144 ;
if ( V_141 ) {
V_7 -> V_95 = true ;
return 0 ;
}
V_4 . V_34 = true ;
if ( ! V_140 )
return 0 ;
V_142 = strtok ( ( char * ) V_140 , L_37 ) ;
if ( ! V_142 )
return - 1 ;
if ( ! strncmp ( V_142 , L_38 , strlen ( V_140 ) ) )
V_96 . V_97 = V_145 ;
else if ( ! strncmp ( V_142 , L_39 , strlen ( V_140 ) ) )
V_96 . V_97 = V_146 ;
else if ( ! strncmp ( V_142 , L_40 , strlen ( V_140 ) ) )
V_96 . V_97 = V_147 ;
else if ( ! strncmp ( V_142 , L_41 , strlen ( V_140 ) ) ) {
V_96 . V_97 = V_98 ;
V_4 . V_34 = false ;
return 0 ;
}
else
return - 1 ;
V_142 = strtok ( NULL , L_37 ) ;
if ( ! V_142 )
goto V_148;
V_96 . V_8 = strtod ( V_142 , & V_144 ) ;
if ( V_142 == V_144 )
return - 1 ;
V_143 = strtok ( NULL , L_37 ) ;
if ( ! V_143 )
goto V_148;
if ( V_143 [ 0 ] != 'c' ) {
V_96 . V_149 = strtoul ( V_143 , & V_144 , 0 ) ;
V_143 = strtok ( NULL , L_37 ) ;
if ( ! V_143 )
goto V_148;
}
if ( ! strncmp ( V_143 , L_42 , strlen ( L_42 ) ) )
V_96 . V_150 = V_151 ;
else if ( ! strncmp ( V_143 , L_43 , strlen ( L_43 ) ) )
V_96 . V_150 = V_152 ;
else
return - 1 ;
V_143 = strtok ( NULL , L_37 ) ;
if ( ! V_143 )
goto V_148;
if ( ! strncmp ( V_143 , L_44 , strlen ( L_44 ) ) )
V_96 . V_153 = V_154 ;
else if ( ! strncmp ( V_143 , L_45 , strlen ( L_45 ) ) )
V_96 . V_153 = V_155 ;
else
return - 1 ;
V_148:
if ( F_31 ( & V_96 ) < 0 ) {
fprintf ( V_68 , L_46 ) ;
return - 1 ;
}
return 0 ;
}
int
F_63 ( const struct V_138 * V_139 V_78 ,
const char * V_140 , int V_141 V_78 )
{
if ( V_140 ) {
int V_26 = regcomp ( & V_156 , V_140 , V_157 ) ;
if ( V_26 ) {
char V_106 [ V_158 ] ;
regerror ( V_26 , & V_156 , V_106 , sizeof( V_106 ) ) ;
F_64 ( L_47 , V_140 , V_106 ) ;
return - 1 ;
}
V_159 = 1 ;
}
return 0 ;
}
static int
F_65 ( const struct V_138 * V_139 V_78 ,
const char * T_7 V_78 , int V_141 )
{
int * V_160 = V_139 -> V_2 ;
* V_160 = ! V_141 ;
return 0 ;
}
static int
F_66 ( const struct V_138 * V_139 , const char * T_7 ,
int V_141 V_78 )
{
struct V_6 * V_7 = V_139 -> V_2 ;
V_7 -> V_8 = strtof ( T_7 , NULL ) ;
return 0 ;
}
int F_67 ( int V_161 , const char * * V_162 , const char * T_8 V_78 )
{
struct V_87 * V_89 ;
struct V_163 V_164 ;
bool V_165 = false ;
int V_160 = - 1 ;
int V_67 = - 1 ;
char V_166 [] = L_48 ;
const char * const V_167 [] = {
L_49 ,
NULL
} ;
struct V_6 V_168 = {
. V_10 = {
. V_14 = F_20 ,
. V_169 = V_170 ,
. V_171 = V_172 ,
. V_173 = V_174 ,
. exit = V_175 ,
. V_176 = V_177 ,
. V_178 = V_179 ,
. V_82 = F_24 ,
. V_180 = V_181 ,
. V_182 = V_183 ,
. V_184 = V_185 ,
. V_186 = true ,
. V_187 = true ,
} ,
. V_116 = L_50 ,
} ;
const struct V_138 V_188 [] = {
F_68 ( 'i' , L_51 , & V_189 , L_52 ,
L_53 ) ,
F_69 ( 'v' , L_54 , & V_130 ,
L_55 ) ,
F_70 ( 'D' , L_56 , & V_131 ,
L_57 ) ,
F_68 ( 'k' , L_58 , & V_4 . V_190 ,
L_52 , L_59 ) ,
F_68 ( 0 , L_60 , & V_4 . V_191 ,
L_52 , L_61 ) ,
F_70 ( 'f' , L_62 , & V_168 . V_192 , L_63 ) ,
F_70 ( 'm' , L_64 , & V_4 . V_193 ,
L_65 ) ,
F_70 ( 'n' , L_66 , & V_4 . V_194 ,
L_67 ) ,
F_70 ( 'T' , L_68 , & V_168 . V_79 ,
L_69 ) ,
F_68 ( 0 , L_70 , & V_168 . V_116 , L_71 ,
L_72 ) ,
F_70 ( 0 , L_73 , & V_168 . V_195 , L_74 ) ,
F_70 ( 0 , L_75 , & V_168 . V_196 , L_76 ) ,
F_70 ( 0 , L_77 , & V_168 . V_197 ,
L_78 ) ,
F_68 ( 's' , L_79 , & V_109 , L_80 ,
L_81
L_82
L_83
L_84 ) ,
F_70 ( 0 , L_85 , & V_4 . V_198 ,
L_86 ) ,
F_68 ( 'p' , L_87 , & V_113 , L_88 ,
L_89 ) ,
F_70 ( 'x' , L_90 , & V_4 . V_199 ,
L_91 ) ,
F_71 ( 'g' , L_92 , & V_168 , L_93 ,
L_94
L_95 , & F_62 , V_166 ) ,
F_70 ( 'G' , L_96 , & V_168 . V_200 ,
L_97 ) ,
F_72 ( 0 , L_98 , NULL , L_88 ,
L_99 ,
F_63 ) ,
F_68 ( 'd' , L_100 , & V_4 . V_201 , L_101 ,
L_102 ) ,
F_68 ( 'c' , L_103 , & V_4 . V_202 , L_104 ,
L_105 ) ,
F_68 ( 'S' , L_106 , & V_4 . V_203 , L_107 ,
L_108 ) ,
F_68 ( 0 , L_109 , & V_168 . V_132 , L_110 ,
L_111 ) ,
F_68 ( 'w' , L_112 , & V_4 . V_204 ,
L_113 ,
L_114 ) ,
F_68 ( 't' , L_115 , & V_4 . V_205 , L_116 ,
L_117
L_118 ) ,
F_70 ( 'U' , L_119 , & V_168 . V_38 ,
L_120 ) ,
F_68 ( 0 , L_121 , & V_4 . V_206 , L_122 ,
L_123 ) ,
F_68 ( 'C' , L_124 , & V_168 . V_70 , L_124 ,
L_125 ) ,
F_70 ( 'I' , L_126 , & V_168 . V_121 ,
L_127 ) ,
F_70 ( 0 , L_128 , & V_4 . V_207 ,
L_129 ) ,
F_70 ( 0 , L_130 , & V_4 . V_208 ,
L_131 ) ,
F_68 ( 'M' , L_132 , & V_209 , L_133 ,
L_134 ) ,
F_70 ( 0 , L_135 , & V_4 . V_210 ,
L_136 ) ,
F_70 ( 0 , L_137 , & V_4 . V_5 ,
L_138 ) ,
F_73 ( 'b' , L_139 , & V_160 , L_140 ,
L_141 , F_65 ) ,
F_68 ( 0 , L_142 , & V_211 , L_143 ,
L_144 ) ,
F_70 ( 0 , L_145 , & V_4 . V_212 ,
L_146 ) ,
F_70 ( 0 , L_147 , & V_168 . V_75 , L_148 ) ,
F_72 ( 0 , L_149 , & V_168 , L_150 ,
L_151 , F_66 ) ,
F_74 ()
} ;
F_75 ( F_1 , & V_168 ) ;
V_161 = F_76 ( V_161 , V_162 , V_188 , V_167 , 0 ) ;
if ( V_168 . V_197 )
V_44 = 0 ;
else if ( V_168 . V_195 )
V_44 = 1 ;
else if ( V_168 . V_196 )
V_44 = 2 ;
if ( V_168 . V_200 )
V_96 . V_150 = V_151 ;
if ( ! V_189 || ! strlen ( V_189 ) ) {
if ( ! F_77 ( V_213 , & V_164 ) && F_78 ( V_164 . V_214 ) )
V_189 = L_152 ;
else
V_189 = L_153 ;
}
if ( strcmp ( V_189 , L_152 ) != 0 )
F_79 ( true ) ;
else {
V_44 = 0 ;
F_80 () ;
}
V_215:
V_89 = F_81 ( V_189 , V_216 ,
V_168 . V_192 , false , & V_168 . V_10 ) ;
if ( V_89 == NULL )
return - V_37 ;
V_168 . V_89 = V_89 ;
V_165 = F_82 ( & V_89 -> V_23 ,
V_217 ) ;
if ( V_160 == - 1 && V_165 )
V_73 = V_74 ;
if ( V_73 == V_74 ) {
if ( V_109 == V_112 )
V_109 = L_154
L_155 ;
}
if ( V_168 . V_75 ) {
if ( V_73 == V_74 ) {
fprintf ( V_68 , L_156 ) ;
goto error;
}
V_73 = V_218 ;
if ( V_109 == V_112 )
V_109 = L_157 ;
}
if ( F_83 () < 0 )
F_84 ( V_167 , V_188 ) ;
if ( V_44 == 1 && V_42 ) {
V_4 . V_219 = sizeof( struct V_45 ) ;
F_85 ( & V_89 -> V_122 ,
V_220 ) ;
if ( V_130 ) {
V_4 . V_219 += sizeof( V_221 ) ;
V_4 . V_222 = true ;
}
}
if ( F_86 () < 0 )
goto error;
if ( V_113 != V_114 ) {
if ( F_87 ( L_87 ) < 0 )
goto error;
}
if ( V_161 ) {
if ( V_161 > 1 )
F_84 ( V_167 , V_188 ) ;
V_168 . V_132 = V_162 [ 0 ] ;
}
F_88 ( stdout ) ;
V_67 = F_45 ( & V_168 ) ;
if ( V_67 == V_137 ) {
F_89 ( V_89 ) ;
goto V_215;
} else
V_67 = 0 ;
error:
F_89 ( V_89 ) ;
return V_67 ;
}
