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
V_14 , & V_21 , V_12 ,
V_7 -> V_37 ) ;
if ( V_26 )
return V_26 ;
}
V_30 = F_7 ( V_17 , V_12 -> V_36 , V_14 , V_22 ) ;
if ( ! V_30 )
return - V_38 ;
if ( V_7 -> V_39 && ! V_12 -> V_40 )
return 0 ;
V_32 = V_14 -> V_41 ;
if ( ! V_32 )
V_32 = 1 ;
V_28 = F_8 ( & V_16 -> V_42 , V_12 , V_21 , NULL , V_30 ,
V_32 , V_32 , 0 ) ;
if ( ! V_28 )
return - V_38 ;
if ( V_43 && V_28 -> V_44 . V_40 && V_45 > 0 ) {
struct V_46 * V_47 = F_9 ( V_28 -> V_44 . V_40 ) ;
assert ( V_16 != NULL ) ;
if ( V_47 -> V_48 == NULL && F_10 ( V_28 -> V_44 . V_40 ) < 0 )
goto V_49;
V_26 = F_11 ( V_28 , V_16 -> V_50 , V_12 -> V_51 ) ;
if ( V_26 )
goto V_49;
}
if ( V_43 && V_28 -> V_29 -> V_52 . V_40 && V_45 > 0 ) {
struct V_46 * V_47 ;
V_31 = V_28 -> V_29 ;
V_47 = F_9 ( V_31 -> V_52 . V_40 ) ;
if ( V_47 -> V_48 == NULL && F_10 ( V_31 -> V_52 . V_40 ) < 0 )
goto V_49;
V_26 = F_12 ( V_31 -> V_52 . V_40 ,
V_31 -> V_52 . V_53 ,
V_16 -> V_50 ,
V_31 -> V_52 . V_54 ) ;
if ( V_26 )
goto V_49;
}
V_16 -> V_42 . V_55 . V_56 += V_32 ;
F_13 ( & V_16 -> V_42 , V_57 ) ;
V_26 = 0 ;
if ( V_4 . V_34 ) {
V_26 = F_14 ( V_28 -> V_35 ,
& V_58 ,
V_14 -> V_59 ) ;
}
V_49:
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
unsigned V_60 ;
struct V_27 * V_28 ;
struct V_61 * V_62 , * V_63 ;
if ( ( V_33 || V_4 . V_34 )
&& V_14 -> V_35 ) {
V_26 = F_6 ( V_17 , V_16 , V_12 -> V_36 ,
V_14 , & V_21 , V_12 ,
V_7 -> V_37 ) ;
if ( V_26 )
return V_26 ;
}
V_62 = F_16 ( V_17 , V_12 -> V_36 ,
V_14 -> V_64 ) ;
if ( ! V_62 )
return - V_38 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_64 -> V_65 ; V_60 ++ ) {
if ( V_7 -> V_39 && ! ( V_62 [ V_60 ] . V_66 . V_40 && V_62 [ V_60 ] . V_67 . V_40 ) )
continue;
V_26 = - V_38 ;
V_12 -> V_53 = V_62 [ V_60 ] . V_67 . V_53 ;
V_12 -> V_40 = V_62 [ V_60 ] . V_67 . V_40 ;
V_12 -> V_51 = V_62 [ V_60 ] . V_67 . V_51 ;
V_28 = F_8 ( & V_16 -> V_42 , V_12 , V_21 , & V_62 [ V_60 ] , NULL ,
1 , 1 , 0 ) ;
if ( V_28 ) {
struct V_46 * V_47 ;
V_63 = V_28 -> V_61 ;
if ( V_63 -> V_66 . V_40 && V_45 == 1 && V_43 ) {
V_47 = F_9 ( V_63 -> V_66 . V_40 ) ;
if ( ! V_47 -> V_48
&& F_10 ( V_63 -> V_66 . V_40 ) < 0 )
goto V_49;
V_26 = F_12 ( V_63 -> V_66 . V_40 ,
V_63 -> V_66 . V_53 ,
V_16 -> V_50 ,
V_63 -> V_66 . V_54 ) ;
if ( V_26 )
goto V_49;
}
if ( V_63 -> V_67 . V_40 && V_45 == 1 && V_43 ) {
V_47 = F_9 ( V_63 -> V_67 . V_40 ) ;
if ( ! V_47 -> V_48
&& F_10 ( V_63 -> V_67 . V_40 ) < 0 )
goto V_49;
V_26 = F_12 ( V_63 -> V_67 . V_40 ,
V_63 -> V_67 . V_53 ,
V_16 -> V_50 ,
V_63 -> V_67 . V_54 ) ;
if ( V_26 )
goto V_49;
}
V_16 -> V_42 . V_55 . V_56 += 1 ;
F_13 ( & V_16 -> V_42 , V_57 ) ;
} else
goto V_49;
}
V_26 = 0 ;
V_49:
free ( V_62 ) ;
return V_26 ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_15 * V_16 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_17 * V_17 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_20 * V_21 = NULL ;
int V_26 = 0 ;
struct V_27 * V_28 ;
if ( ( V_33 || V_4 . V_34 ) && V_14 -> V_35 ) {
V_26 = F_6 ( V_17 , V_16 , V_12 -> V_36 ,
V_14 , & V_21 , V_12 ,
V_7 -> V_37 ) ;
if ( V_26 )
return V_26 ;
}
V_28 = F_8 ( & V_16 -> V_42 , V_12 , V_21 , NULL , NULL ,
V_14 -> V_59 , V_14 -> V_41 ,
V_14 -> V_68 ) ;
if ( V_28 == NULL )
return - V_38 ;
if ( V_4 . V_34 ) {
V_26 = F_14 ( V_28 -> V_35 ,
& V_58 ,
V_14 -> V_59 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_28 -> V_44 . V_40 != NULL && V_45 == 1 && V_43 ) {
struct V_46 * V_47 = F_9 ( V_28 -> V_44 . V_40 ) ;
assert ( V_16 != NULL ) ;
V_26 = - V_38 ;
if ( V_47 -> V_48 == NULL && F_10 ( V_28 -> V_44 . V_40 ) < 0 )
goto V_49;
V_26 = F_11 ( V_28 , V_16 -> V_50 , V_12 -> V_51 ) ;
}
V_16 -> V_42 . V_55 . V_56 += V_14 -> V_59 ;
F_13 ( & V_16 -> V_42 , V_57 ) ;
V_49:
return V_26 ;
}
static int F_18 ( struct V_9 * V_10 ,
union V_18 * V_19 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_17 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_11 V_12 ;
int V_69 ;
if ( F_19 ( V_19 , V_17 , & V_12 , V_14 ) < 0 ) {
fprintf ( V_70 , L_3 ,
V_19 -> V_23 . type ) ;
return - 1 ;
}
if ( V_12 . V_71 || ( V_7 -> V_39 && V_12 . V_40 == NULL ) )
return 0 ;
if ( V_7 -> V_72 && ! F_20 ( V_14 -> V_73 , V_7 -> V_74 ) )
return 0 ;
if ( V_75 == V_76 ) {
V_69 = F_15 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 ) ;
if ( V_69 < 0 )
F_21 ( L_4 ) ;
} else if ( V_7 -> V_77 == 1 ) {
V_69 = F_4 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 , V_19 ) ;
if ( V_69 < 0 )
F_21 ( L_5 ) ;
} else {
if ( V_12 . V_53 != NULL )
V_12 . V_53 -> V_78 -> V_79 = 1 ;
V_69 = F_17 ( V_10 , V_16 , & V_12 , V_14 ,
V_17 ) ;
if ( V_69 < 0 )
F_21 ( L_6 ) ;
}
return V_69 ;
}
static int F_22 ( struct V_9 * V_10 ,
union V_18 * V_19 ,
struct V_13 * V_14 V_80 ,
struct V_15 * V_16 ,
struct V_17 * V_17 V_80 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
if ( V_7 -> V_81 ) {
const char * V_82 = V_16 ? F_23 ( V_16 ) : L_7 ;
F_24 ( & V_7 -> V_83 ,
V_19 -> V_84 . V_85 , V_19 -> V_84 . V_86 ,
V_19 -> V_84 . V_87 ,
V_82 ,
V_19 -> V_84 . V_2 ) ;
}
F_25 ( L_8 V_88 L_9 , V_19 -> V_84 . V_85 , V_19 -> V_84 . V_86 ,
V_16 ? F_23 ( V_16 ) : L_10 ,
V_19 -> V_84 . V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_89 * V_90 = V_7 -> V_90 ;
T_3 V_91 = F_27 ( V_90 -> V_92 ) ;
bool V_93 = F_28 ( V_90 -> V_94 ) ;
if ( ! V_93 && ! ( V_91 & V_95 ) ) {
if ( V_33 ) {
F_29 ( L_11
L_12
L_13 ) ;
return - V_96 ;
}
if ( V_4 . V_34 ) {
F_29 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_97 &&
V_98 . V_99 != V_100 &&
! V_4 . V_34 ) {
V_4 . V_34 = true ;
if ( F_30 ( & V_98 ) < 0 ) {
F_29 ( L_16 ) ;
return - V_96 ;
}
}
if ( V_75 == V_76 ) {
if ( ! V_93 &&
! ( V_91 & V_101 ) ) {
F_29 ( L_17
L_18 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_31 ( int T_4 V_80 )
{
V_102 = 1 ;
}
static T_5 F_32 ( struct V_6 * V_7 ,
struct V_42 * V_42 ,
const char * V_103 , T_6 * V_104 )
{
T_5 V_69 ;
char V_105 ;
unsigned long V_106 = V_42 -> V_55 . V_107 [ V_57 ] ;
T_3 V_107 = V_42 -> V_55 . V_56 ;
struct V_15 * V_16 = F_33 ( V_42 ) ;
char V_108 [ 512 ] ;
T_5 V_109 = sizeof( V_108 ) ;
if ( F_34 ( V_16 ) ) {
struct V_15 * V_110 ;
F_35 ( V_16 , V_108 , V_109 ) ;
V_103 = V_108 ;
F_36 (pos, evsel) {
V_106 += V_110 -> V_42 . V_55 . V_107 [ V_57 ] ;
V_107 += V_110 -> V_42 . V_55 . V_56 ;
}
}
V_106 = F_37 ( V_106 , & V_105 ) ;
V_69 = fprintf ( V_104 , L_19 , V_106 , V_105 ) ;
if ( V_103 != NULL )
V_69 += fprintf ( V_104 , L_20 , V_103 ) ;
if ( V_7 -> V_77 ) {
V_69 += fprintf ( V_104 , L_21 V_88 , V_107 ) ;
V_69 += fprintf ( V_104 , L_22 , V_111 ) ;
} else
V_69 += fprintf ( V_104 , L_23 V_88 , V_107 ) ;
return V_69 + fprintf ( V_104 , L_24 ) ;
}
static int F_38 ( struct V_112 * V_92 ,
struct V_6 * V_7 ,
const char * V_113 )
{
struct V_15 * V_110 ;
F_39 (pos, &evlist->entries, node) {
struct V_42 * V_42 = & V_110 -> V_42 ;
const char * V_103 = F_23 ( V_110 ) ;
if ( V_4 . V_5 &&
! F_40 ( V_110 ) )
continue;
F_32 ( V_7 , V_42 , V_103 , stdout ) ;
F_41 ( V_42 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_111 == V_114 &&
V_115 == V_116 ) {
fprintf ( stdout , L_26 , V_113 ) ;
if ( V_7 -> V_81 ) {
bool V_117 = ! strcmp ( V_7 -> V_118 , L_27 ) ;
F_42 ( stdout , & V_7 -> V_83 ,
V_117 ) ;
F_43 ( & V_7 -> V_83 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_6 * V_7 )
{
int V_69 = - V_96 ;
T_3 V_106 ;
struct V_89 * V_90 = V_7 -> V_90 ;
struct V_15 * V_110 ;
struct V_53 * V_119 ;
struct V_120 * V_121 ;
const char * V_113 = L_28 ;
struct V_122 V_123 ;
struct V_124 * V_94 = V_90 -> V_94 ;
signal ( V_125 , F_31 ) ;
if ( V_7 -> V_72 ) {
V_69 = F_45 ( V_90 , V_7 -> V_72 ,
V_7 -> V_74 ) ;
if ( V_69 )
return V_69 ;
}
if ( V_45 <= 0 )
F_46 ( V_90 , stdout , V_7 -> V_126 ) ;
if ( V_7 -> V_81 )
F_47 ( & V_7 -> V_83 ) ;
V_69 = F_26 ( V_7 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_48 ( V_90 , & V_7 -> V_10 ) ;
if ( V_69 )
return V_69 ;
V_119 = V_90 -> V_127 . V_128 . V_129 [ V_130 ] ;
V_121 = F_49 ( V_119 ) ;
if ( V_119 == NULL ||
( V_119 -> V_78 -> V_79 &&
( V_121 -> V_131 == NULL ||
V_121 -> V_131 -> V_51 == 0 ) ) ) {
const char * V_132 =
L_29
L_30 ;
if ( V_119 ) {
const struct V_78 * V_133 = V_119 -> V_78 ;
if ( ! F_50 ( & V_133 -> V_134 [ V_130 ] ) ) {
V_132 = L_31
L_32 ;
}
}
F_51 (
L_33
L_34
L_35 ,
V_132 ) ;
}
if ( V_135 > 3 )
F_52 ( V_90 , stdout ) ;
if ( V_135 > 2 )
F_53 ( V_90 , stdout ) ;
if ( V_136 ) {
F_54 ( V_90 , stdout ) ;
return 0 ;
}
V_106 = 0 ;
F_39 (pos, &session->evlist->entries, node)
V_106 += V_110 -> V_42 . V_137 ;
F_55 ( & V_123 , V_106 , L_36 ) ;
V_106 = 0 ;
F_39 (pos, &session->evlist->entries, node) {
struct V_42 * V_42 = & V_110 -> V_42 ;
if ( V_110 -> V_50 == 0 )
V_42 -> V_138 = V_7 -> V_138 ;
F_56 ( V_42 , & V_123 ) ;
V_106 += V_42 -> V_55 . V_107 [ V_57 ] ;
if ( V_4 . V_5 &&
! F_40 ( V_110 ) ) {
struct V_42 * V_139 = & V_110 -> V_140 -> V_42 ;
F_57 ( V_139 , V_42 ) ;
F_58 ( V_139 , V_42 ) ;
}
}
F_59 () ;
if ( V_102 () )
return 0 ;
if ( V_106 == 0 ) {
F_29 ( L_37 , V_94 -> V_141 ) ;
return 0 ;
}
F_39 (pos, &session->evlist->entries, node)
F_60 ( & V_110 -> V_42 ) ;
if ( V_45 > 0 ) {
if ( V_45 == 1 ) {
V_69 = F_61 ( V_90 -> V_92 ,
V_113 , NULL ,
V_7 -> V_8 ,
& V_90 -> V_23 . V_142 ) ;
if ( V_69 != V_143 )
V_69 = 0 ;
} else if ( V_45 == 2 ) {
int (* F_62)( struct V_112 * ,
const char * ,
struct V_144 * ,
float V_145 );
F_62 = F_63 ( V_146 ,
L_38 ) ;
if ( F_62 == NULL ) {
F_29 ( L_39 ) ;
return V_69 ;
}
F_62 ( V_90 -> V_92 , V_113 , NULL ,
V_7 -> V_8 ) ;
}
} else
F_38 ( V_90 -> V_92 , V_7 , V_113 ) ;
return V_69 ;
}
static int
F_64 ( const struct V_147 * V_148 , const char * V_149 , int V_150 )
{
struct V_6 * V_7 = (struct V_6 * ) V_148 -> V_2 ;
char * V_151 , * V_152 ;
char * V_153 ;
if ( V_150 ) {
V_7 -> V_97 = true ;
return 0 ;
}
V_4 . V_34 = true ;
if ( ! V_149 )
return 0 ;
V_151 = strtok ( ( char * ) V_149 , L_40 ) ;
if ( ! V_151 )
return - 1 ;
if ( ! strncmp ( V_151 , L_41 , strlen ( V_149 ) ) )
V_98 . V_99 = V_154 ;
else if ( ! strncmp ( V_151 , L_42 , strlen ( V_149 ) ) )
V_98 . V_99 = V_155 ;
else if ( ! strncmp ( V_151 , L_43 , strlen ( V_149 ) ) )
V_98 . V_99 = V_156 ;
else if ( ! strncmp ( V_151 , L_44 , strlen ( V_149 ) ) ) {
V_98 . V_99 = V_100 ;
V_4 . V_34 = false ;
return 0 ;
}
else
return - 1 ;
V_151 = strtok ( NULL , L_40 ) ;
if ( ! V_151 )
goto V_157;
V_98 . V_8 = strtod ( V_151 , & V_153 ) ;
if ( V_151 == V_153 )
return - 1 ;
V_152 = strtok ( NULL , L_40 ) ;
if ( ! V_152 )
goto V_157;
if ( V_152 [ 0 ] != 'c' ) {
V_98 . V_158 = strtoul ( V_152 , & V_153 , 0 ) ;
V_152 = strtok ( NULL , L_40 ) ;
if ( ! V_152 )
goto V_157;
}
if ( ! strncmp ( V_152 , L_45 , strlen ( L_45 ) ) )
V_98 . V_159 = V_160 ;
else if ( ! strncmp ( V_152 , L_46 , strlen ( L_46 ) ) )
V_98 . V_159 = V_161 ;
else
return - 1 ;
V_152 = strtok ( NULL , L_40 ) ;
if ( ! V_152 )
goto V_157;
if ( ! strncmp ( V_152 , L_47 , strlen ( L_47 ) ) )
V_98 . V_162 = V_163 ;
else if ( ! strncmp ( V_152 , L_48 , strlen ( L_48 ) ) )
V_98 . V_162 = V_164 ;
else
return - 1 ;
V_157:
if ( F_30 ( & V_98 ) < 0 ) {
fprintf ( V_70 , L_49 ) ;
return - 1 ;
}
return 0 ;
}
int
F_65 ( const struct V_147 * V_148 V_80 ,
const char * V_149 , int V_150 V_80 )
{
if ( V_149 ) {
int V_26 = regcomp ( & V_165 , V_149 , V_166 ) ;
if ( V_26 ) {
char V_108 [ V_167 ] ;
regerror ( V_26 , & V_165 , V_108 , sizeof( V_108 ) ) ;
F_66 ( L_50 , V_149 , V_108 ) ;
return - 1 ;
}
V_168 = 1 ;
}
return 0 ;
}
static int
F_67 ( const struct V_147 * V_148 V_80 ,
const char * T_7 V_80 , int V_150 )
{
int * V_169 = V_148 -> V_2 ;
* V_169 = ! V_150 ;
return 0 ;
}
static int
F_68 ( const struct V_147 * V_148 , const char * T_7 ,
int V_150 V_80 )
{
struct V_6 * V_7 = V_148 -> V_2 ;
V_7 -> V_8 = strtof ( T_7 , NULL ) ;
return 0 ;
}
int F_69 ( int V_170 , const char * * V_171 , const char * T_8 V_80 )
{
struct V_89 * V_90 ;
struct V_172 V_173 ;
bool V_174 = false ;
int V_169 = - 1 ;
int V_69 = - 1 ;
char V_175 [] = L_51 ;
const char * const V_176 [] = {
L_52 ,
NULL
} ;
struct V_6 V_177 = {
. V_10 = {
. V_14 = F_18 ,
. V_178 = V_179 ,
. V_180 = V_181 ,
. V_182 = V_183 ,
. exit = V_184 ,
. V_185 = V_186 ,
. V_187 = V_188 ,
. V_84 = F_22 ,
. V_189 = V_190 ,
. V_191 = V_192 ,
. V_193 = V_194 ,
. V_195 = true ,
. V_196 = true ,
} ,
. V_37 = V_197 ,
. V_118 = L_53 ,
} ;
const struct V_147 V_198 [] = {
F_70 ( 'i' , L_54 , & V_199 , L_55 ,
L_56 ) ,
F_71 ( 'v' , L_57 , & V_135 ,
L_58 ) ,
F_72 ( 'D' , L_59 , & V_136 ,
L_60 ) ,
F_70 ( 'k' , L_61 , & V_4 . V_200 ,
L_55 , L_62 ) ,
F_70 ( 0 , L_63 , & V_4 . V_201 ,
L_55 , L_64 ) ,
F_72 ( 'f' , L_65 , & V_177 . V_202 , L_66 ) ,
F_72 ( 'm' , L_67 , & V_4 . V_203 ,
L_68 ) ,
F_72 ( 'n' , L_69 , & V_4 . V_204 ,
L_70 ) ,
F_72 ( 'T' , L_71 , & V_177 . V_81 ,
L_72 ) ,
F_70 ( 0 , L_73 , & V_177 . V_118 , L_74 ,
L_75 ) ,
F_72 ( 0 , L_76 , & V_177 . V_205 , L_77 ) ,
F_72 ( 0 , L_78 , & V_177 . V_206 , L_79 ) ,
F_72 ( 0 , L_80 , & V_177 . V_207 ,
L_81 ) ,
F_70 ( 's' , L_82 , & V_111 , L_83 ,
L_84
L_85
L_86
L_87 ) ,
F_72 ( 0 , L_88 , & V_4 . V_208 ,
L_89 ) ,
F_70 ( 'p' , L_90 , & V_115 , L_91 ,
L_92 ) ,
F_72 ( 'x' , L_93 , & V_4 . V_209 ,
L_94 ) ,
F_73 ( 'g' , L_95 , & V_177 , L_96 ,
L_97
L_98 , & F_64 , V_175 ) ,
F_74 ( 0 , L_99 , & V_177 . V_37 ,
L_100
L_101
L_102 F_75 ( V_197 ) ) ,
F_72 ( 'G' , L_103 , & V_177 . V_210 ,
L_104 ) ,
F_76 ( 0 , L_105 , NULL , L_91 ,
L_106 ,
F_65 ) ,
F_70 ( 'd' , L_107 , & V_4 . V_211 , L_108 ,
L_109 ) ,
F_70 ( 'c' , L_110 , & V_4 . V_212 , L_111 ,
L_112 ) ,
F_70 ( 'S' , L_113 , & V_4 . V_213 , L_114 ,
L_115 ) ,
F_70 ( 0 , L_116 , & V_177 . V_138 , L_117 ,
L_118 ) ,
F_70 ( 'w' , L_119 , & V_4 . V_214 ,
L_120 ,
L_121 ) ,
F_70 ( 't' , L_122 , & V_4 . V_215 , L_123 ,
L_124
L_125 ) ,
F_72 ( 'U' , L_126 , & V_177 . V_39 ,
L_127 ) ,
F_70 ( 0 , L_128 , & V_4 . V_216 , L_129 ,
L_130 ) ,
F_70 ( 'C' , L_131 , & V_177 . V_72 , L_131 ,
L_132 ) ,
F_72 ( 'I' , L_133 , & V_177 . V_126 ,
L_134 ) ,
F_72 ( 0 , L_135 , & V_4 . V_217 ,
L_136 ) ,
F_72 ( 0 , L_137 , & V_4 . V_218 ,
L_138 ) ,
F_70 ( 'M' , L_139 , & V_219 , L_140 ,
L_141 ) ,
F_72 ( 0 , L_142 , & V_4 . V_220 ,
L_143 ) ,
F_72 ( 0 , L_144 , & V_4 . V_5 ,
L_145 ) ,
F_77 ( 'b' , L_146 , & V_169 , L_147 ,
L_148 , F_67 ) ,
F_70 ( 0 , L_149 , & V_221 , L_150 ,
L_151 ) ,
F_72 ( 0 , L_152 , & V_4 . V_222 ,
L_153 ) ,
F_72 ( 0 , L_154 , & V_177 . V_77 , L_155 ) ,
F_76 ( 0 , L_156 , & V_177 , L_157 ,
L_158 , F_68 ) ,
F_78 ()
} ;
struct V_124 V_94 = {
. V_99 = V_223 ,
} ;
F_79 ( F_1 , & V_177 ) ;
V_170 = F_80 ( V_170 , V_171 , V_198 , V_176 , 0 ) ;
if ( V_177 . V_207 )
V_45 = 0 ;
else if ( V_177 . V_205 )
V_45 = 1 ;
else if ( V_177 . V_206 )
V_45 = 2 ;
if ( V_177 . V_210 )
V_98 . V_159 = V_160 ;
if ( ! V_199 || ! strlen ( V_199 ) ) {
if ( ! F_81 ( V_224 , & V_173 ) && F_82 ( V_173 . V_225 ) )
V_199 = L_159 ;
else
V_199 = L_160 ;
}
V_94 . V_141 = V_199 ;
V_94 . V_202 = V_177 . V_202 ;
V_226:
V_90 = F_83 ( & V_94 , false , & V_177 . V_10 ) ;
if ( V_90 == NULL )
return - V_38 ;
V_177 . V_90 = V_90 ;
V_174 = F_84 ( & V_90 -> V_23 ,
V_227 ) ;
if ( V_169 == - 1 && V_174 )
V_75 = V_76 ;
if ( V_75 == V_76 ) {
if ( V_111 == V_114 )
V_111 = L_161
L_162 ;
}
if ( V_177 . V_77 ) {
if ( V_75 == V_76 ) {
fprintf ( V_70 , L_163 ) ;
goto error;
}
V_75 = V_228 ;
if ( V_111 == V_114 )
V_111 = L_164 ;
}
if ( F_85 () < 0 ) {
F_86 ( V_176 , V_198 , L_165 , 1 ) ;
goto error;
}
if ( V_115 != V_116 ) {
if ( F_87 ( L_90 ) < 0 )
goto error;
}
if ( strcmp ( V_199 , L_159 ) != 0 )
F_88 ( true ) ;
else {
V_45 = 0 ;
F_89 () ;
}
if ( V_45 == 1 && V_43 ) {
V_4 . V_229 = sizeof( struct V_46 ) ;
F_90 ( & V_90 -> V_127 ,
V_230 ) ;
if ( V_135 ) {
V_4 . V_229 += sizeof( V_231 ) ;
V_4 . V_232 = true ;
}
}
if ( F_91 () < 0 )
goto error;
if ( V_170 ) {
if ( V_170 > 1 )
F_92 ( V_176 , V_198 ) ;
V_177 . V_138 = V_171 [ 0 ] ;
}
F_93 ( stdout ) ;
V_69 = F_44 ( & V_177 ) ;
if ( V_69 == V_143 ) {
F_94 ( V_90 ) ;
goto V_226;
} else
V_69 = 0 ;
error:
F_94 ( V_90 ) ;
return V_69 ;
}
