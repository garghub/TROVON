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
V_14 , & V_21 ) ;
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
V_14 , & V_21 ) ;
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
V_14 , & V_21 ) ;
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
if ( F_21 ( V_19 , V_17 , & V_12 , V_14 ,
V_7 -> V_68 ) < 0 ) {
fprintf ( V_69 , L_3 ,
V_19 -> V_23 . type ) ;
return - 1 ;
}
if ( V_12 . V_70 || ( V_7 -> V_38 && V_12 . V_39 == NULL ) )
return 0 ;
if ( V_7 -> V_71 && ! F_22 ( V_14 -> V_72 , V_7 -> V_73 ) )
return 0 ;
if ( V_74 == V_75 ) {
V_67 = F_15 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 ) ;
if ( V_67 < 0 )
F_23 ( L_4 ) ;
} else if ( V_7 -> V_76 == 1 ) {
V_67 = F_4 ( V_10 , & V_12 , V_14 ,
V_16 , V_17 , V_19 ) ;
if ( V_67 < 0 )
F_23 ( L_5 ) ;
} else {
if ( V_12 . V_52 != NULL )
V_12 . V_52 -> V_77 -> V_78 = 1 ;
V_67 = F_18 ( V_16 , & V_12 , V_14 , V_17 ) ;
if ( V_67 < 0 )
F_23 ( L_6 ) ;
}
return V_67 ;
}
static int F_24 ( struct V_9 * V_10 ,
union V_18 * V_19 ,
struct V_13 * V_14 V_79 ,
struct V_15 * V_16 ,
struct V_17 * V_17 V_79 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
if ( V_7 -> V_80 ) {
const char * V_81 = V_16 ? F_25 ( V_16 ) : L_7 ;
F_26 ( & V_7 -> V_82 ,
V_19 -> V_83 . V_84 , V_19 -> V_83 . V_85 ,
V_19 -> V_83 . V_86 ,
V_81 ,
V_19 -> V_83 . V_2 ) ;
}
F_27 ( L_8 V_87 L_9 , V_19 -> V_83 . V_84 , V_19 -> V_83 . V_85 ,
V_16 ? F_25 ( V_16 ) : L_10 ,
V_19 -> V_83 . V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_88 * V_89 = V_7 -> V_90 ;
T_3 V_91 = F_29 ( V_89 -> V_92 ) ;
if ( ! V_89 -> V_93 && ! ( V_91 & V_94 ) ) {
if ( V_33 ) {
F_30 ( L_11
L_12
L_13 ) ;
return - V_95 ;
}
if ( V_4 . V_34 ) {
F_30 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_96 &&
V_97 . V_98 != V_99 &&
! V_4 . V_34 ) {
V_4 . V_34 = true ;
if ( F_31 ( & V_97 ) < 0 ) {
F_30 ( L_16 ) ;
return - V_95 ;
}
}
if ( V_74 == V_75 ) {
if ( ! V_89 -> V_93 &&
! ( V_91 & V_100 ) ) {
F_30 ( L_17
L_18 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_32 ( int T_4 V_79 )
{
V_101 = 1 ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_41 * V_89 ,
const char * V_102 , T_6 * V_103 )
{
T_5 V_67 ;
char V_104 ;
unsigned long V_105 = V_89 -> V_54 . V_106 [ V_56 ] ;
T_3 V_106 = V_89 -> V_54 . V_55 ;
struct V_15 * V_16 = F_34 ( V_89 ) ;
char V_107 [ 512 ] ;
T_5 V_108 = sizeof( V_107 ) ;
if ( F_35 ( V_16 ) ) {
struct V_15 * V_109 ;
F_36 ( V_16 , V_107 , V_108 ) ;
V_102 = V_107 ;
F_37 (pos, evsel) {
V_105 += V_109 -> V_41 . V_54 . V_106 [ V_56 ] ;
V_106 += V_109 -> V_41 . V_54 . V_55 ;
}
}
V_105 = F_38 ( V_105 , & V_104 ) ;
V_67 = fprintf ( V_103 , L_19 , V_105 , V_104 ) ;
if ( V_102 != NULL )
V_67 += fprintf ( V_103 , L_20 , V_102 ) ;
if ( V_7 -> V_76 ) {
V_67 += fprintf ( V_103 , L_21 V_87 , V_106 ) ;
V_67 += fprintf ( V_103 , L_22 , V_110 ) ;
} else
V_67 += fprintf ( V_103 , L_23 V_87 , V_106 ) ;
return V_67 + fprintf ( V_103 , L_24 ) ;
}
static int F_39 ( struct V_111 * V_92 ,
struct V_6 * V_7 ,
const char * V_112 )
{
struct V_15 * V_109 ;
F_40 (pos, &evlist->entries, node) {
struct V_41 * V_41 = & V_109 -> V_41 ;
const char * V_102 = F_25 ( V_109 ) ;
if ( V_4 . V_5 &&
! F_41 ( V_109 ) )
continue;
F_33 ( V_7 , V_41 , V_102 , stdout ) ;
F_42 ( V_41 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_110 == V_113 &&
V_114 == V_115 ) {
fprintf ( stdout , L_26 , V_112 ) ;
if ( V_7 -> V_80 ) {
bool V_116 = ! strcmp ( V_7 -> V_117 , L_27 ) ;
F_43 ( stdout , & V_7 -> V_82 ,
V_116 ) ;
F_44 ( & V_7 -> V_82 ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
int V_67 = - V_95 ;
T_3 V_105 ;
struct V_88 * V_90 = V_7 -> V_90 ;
struct V_15 * V_109 ;
struct V_52 * V_118 ;
struct V_119 * V_120 ;
const char * V_112 = L_28 ;
signal ( V_121 , F_32 ) ;
if ( V_7 -> V_71 ) {
V_67 = F_46 ( V_90 , V_7 -> V_71 ,
V_7 -> V_73 ) ;
if ( V_67 )
goto V_122;
}
if ( V_44 <= 0 )
F_47 ( V_90 , stdout , V_7 -> V_123 ) ;
if ( V_7 -> V_80 )
F_48 ( & V_7 -> V_82 ) ;
V_67 = F_28 ( V_7 ) ;
if ( V_67 )
goto V_122;
V_67 = F_49 ( V_90 , & V_7 -> V_10 ) ;
if ( V_67 )
goto V_122;
V_118 = V_90 -> V_124 . V_125 . V_126 [ V_127 ] ;
V_120 = F_50 ( V_118 ) ;
if ( V_118 == NULL ||
( V_118 -> V_77 -> V_78 &&
( V_120 -> V_128 == NULL ||
V_120 -> V_128 -> V_50 == 0 ) ) ) {
const char * V_129 =
L_29
L_30 ;
if ( V_118 ) {
const struct V_77 * V_130 = V_118 -> V_77 ;
if ( ! F_51 ( & V_130 -> V_131 [ V_127 ] ) ) {
V_129 = L_31
L_32 ;
}
}
F_52 (
L_33
L_34
L_35 ,
V_129 ) ;
}
if ( V_132 > 3 )
F_53 ( V_90 , stdout ) ;
if ( V_132 > 2 )
F_54 ( V_90 , stdout ) ;
if ( V_133 ) {
F_55 ( V_90 , stdout ) ;
goto V_122;
}
V_105 = 0 ;
F_40 (pos, &session->evlist->entries, node) {
struct V_41 * V_41 = & V_109 -> V_41 ;
if ( V_109 -> V_49 == 0 )
V_41 -> V_134 = V_7 -> V_134 ;
F_56 ( V_41 ) ;
V_105 += V_41 -> V_54 . V_106 [ V_56 ] ;
if ( V_4 . V_5 &&
! F_41 ( V_109 ) ) {
struct V_41 * V_135 = & V_109 -> V_136 -> V_41 ;
F_57 ( V_135 , V_41 ) ;
F_58 ( V_135 , V_41 ) ;
}
}
if ( V_105 == 0 ) {
F_30 ( L_36 , V_90 -> V_137 ) ;
goto V_122;
}
F_40 (pos, &session->evlist->entries, node)
F_59 ( & V_109 -> V_41 ) ;
if ( V_44 > 0 ) {
if ( V_44 == 1 ) {
V_67 = F_60 ( V_90 -> V_92 ,
V_112 , NULL ,
V_7 -> V_8 ,
& V_90 -> V_23 . V_138 ) ;
if ( V_67 != V_139 )
V_67 = 0 ;
} else if ( V_44 == 2 ) {
F_61 ( V_90 -> V_92 , V_112 ,
NULL , V_7 -> V_8 ) ;
}
} else
F_39 ( V_90 -> V_92 , V_7 , V_112 ) ;
V_122:
return V_67 ;
}
static int
F_62 ( const struct V_140 * V_141 , const char * V_142 , int V_143 )
{
struct V_6 * V_7 = (struct V_6 * ) V_141 -> V_2 ;
char * V_144 , * V_145 ;
char * V_146 ;
if ( V_143 ) {
V_7 -> V_96 = true ;
return 0 ;
}
V_4 . V_34 = true ;
if ( ! V_142 )
return 0 ;
V_144 = strtok ( ( char * ) V_142 , L_37 ) ;
if ( ! V_144 )
return - 1 ;
if ( ! strncmp ( V_144 , L_38 , strlen ( V_142 ) ) )
V_97 . V_98 = V_147 ;
else if ( ! strncmp ( V_144 , L_39 , strlen ( V_142 ) ) )
V_97 . V_98 = V_148 ;
else if ( ! strncmp ( V_144 , L_40 , strlen ( V_142 ) ) )
V_97 . V_98 = V_149 ;
else if ( ! strncmp ( V_144 , L_41 , strlen ( V_142 ) ) ) {
V_97 . V_98 = V_99 ;
V_4 . V_34 = false ;
return 0 ;
}
else
return - 1 ;
V_144 = strtok ( NULL , L_37 ) ;
if ( ! V_144 )
goto V_150;
V_97 . V_8 = strtod ( V_144 , & V_146 ) ;
if ( V_144 == V_146 )
return - 1 ;
V_145 = strtok ( NULL , L_37 ) ;
if ( ! V_145 )
goto V_150;
if ( V_145 [ 0 ] != 'c' ) {
V_97 . V_151 = strtoul ( V_145 , & V_146 , 0 ) ;
V_145 = strtok ( NULL , L_37 ) ;
if ( ! V_145 )
goto V_150;
}
if ( ! strcmp ( V_145 , L_42 ) )
V_97 . V_152 = V_153 ;
else if ( ! strcmp ( V_145 , L_43 ) )
V_97 . V_152 = V_154 ;
else
return - 1 ;
V_150:
if ( F_31 ( & V_97 ) < 0 ) {
fprintf ( V_69 , L_44 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_63 ( const struct V_140 * V_141 V_79 ,
const char * T_7 V_79 , int V_143 )
{
int * V_155 = V_141 -> V_2 ;
* V_155 = ! V_143 ;
return 0 ;
}
static int
F_64 ( const struct V_140 * V_141 , const char * T_7 ,
int V_143 V_79 )
{
struct V_6 * V_7 = V_141 -> V_2 ;
V_7 -> V_8 = strtof ( T_7 , NULL ) ;
return 0 ;
}
int F_65 ( int V_156 , const char * * V_157 , const char * T_8 V_79 )
{
struct V_88 * V_90 ;
struct V_158 V_159 ;
bool V_160 = false ;
int V_155 = - 1 ;
int V_67 = - 1 ;
char V_161 [] = L_45 ;
const char * const V_162 [] = {
L_46 ,
NULL
} ;
struct V_6 V_163 = {
. V_10 = {
. V_14 = F_20 ,
. V_164 = V_165 ,
. V_166 = V_167 ,
. exit = V_168 ,
. V_169 = V_170 ,
. V_171 = V_172 ,
. V_83 = F_24 ,
. V_173 = V_174 ,
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_179 = V_180 ,
. V_181 = true ,
. V_182 = true ,
} ,
. V_117 = L_47 ,
} ;
const struct V_140 V_183 [] = {
F_66 ( 'i' , L_48 , & V_184 , L_49 ,
L_50 ) ,
F_67 ( 'v' , L_51 , & V_132 ,
L_52 ) ,
F_68 ( 'D' , L_53 , & V_133 ,
L_54 ) ,
F_66 ( 'k' , L_55 , & V_4 . V_185 ,
L_49 , L_56 ) ,
F_66 ( 0 , L_57 , & V_4 . V_186 ,
L_49 , L_58 ) ,
F_68 ( 'f' , L_59 , & V_163 . V_187 , L_60 ) ,
F_68 ( 'm' , L_61 , & V_4 . V_188 ,
L_62 ) ,
F_68 ( 'n' , L_63 , & V_4 . V_189 ,
L_64 ) ,
F_68 ( 'T' , L_65 , & V_163 . V_80 ,
L_66 ) ,
F_66 ( 0 , L_67 , & V_163 . V_117 , L_68 ,
L_69 ) ,
F_68 ( 0 , L_70 , & V_163 . V_190 , L_71 ) ,
F_68 ( 0 , L_72 , & V_163 . V_191 , L_73 ) ,
F_68 ( 0 , L_74 , & V_163 . V_192 ,
L_75 ) ,
F_66 ( 's' , L_76 , & V_110 , L_77 ,
L_78
L_79
L_80
L_81 ) ,
F_68 ( 0 , L_82 , & V_4 . V_193 ,
L_83 ) ,
F_66 ( 'p' , L_84 , & V_114 , L_85 ,
L_86 ) ,
F_68 ( 'x' , L_87 , & V_4 . V_194 ,
L_88 ) ,
F_69 ( 'g' , L_89 , & V_163 , L_90 ,
L_91
L_92 , & F_62 , V_161 ) ,
F_68 ( 'G' , L_93 , & V_163 . V_195 ,
L_94 ) ,
F_66 ( 'd' , L_95 , & V_4 . V_196 , L_96 ,
L_97 ) ,
F_66 ( 'c' , L_98 , & V_4 . V_197 , L_99 ,
L_100 ) ,
F_66 ( 'S' , L_101 , & V_4 . V_198 , L_102 ,
L_103 ) ,
F_66 ( 0 , L_104 , & V_163 . V_134 , L_105 ,
L_106 ) ,
F_66 ( 'w' , L_107 , & V_4 . V_199 ,
L_108 ,
L_109 ) ,
F_66 ( 't' , L_110 , & V_4 . V_200 , L_111 ,
L_112
L_113 ) ,
F_68 ( 'U' , L_114 , & V_163 . V_38 ,
L_115 ) ,
F_66 ( 0 , L_116 , & V_4 . V_201 , L_117 ,
L_118 ) ,
F_66 ( 'C' , L_119 , & V_163 . V_71 , L_119 ,
L_120 ) ,
F_68 ( 'I' , L_121 , & V_163 . V_123 ,
L_122 ) ,
F_68 ( 0 , L_123 , & V_4 . V_202 ,
L_124 ) ,
F_68 ( 0 , L_125 , & V_4 . V_203 ,
L_126 ) ,
F_66 ( 'M' , L_127 , & V_204 , L_128 ,
L_129 ) ,
F_68 ( 0 , L_130 , & V_4 . V_205 ,
L_131 ) ,
F_68 ( 0 , L_132 , & V_4 . V_5 ,
L_133 ) ,
F_70 ( 'b' , L_134 , & V_155 , L_135 ,
L_136 , F_63 ) ,
F_66 ( 0 , L_137 , & V_206 , L_138 ,
L_139 ) ,
F_68 ( 0 , L_140 , & V_4 . V_207 ,
L_141 ) ,
F_68 ( 0 , L_142 , & V_163 . V_76 , L_143 ) ,
F_71 ( 0 , L_144 , & V_163 , L_145 ,
L_146 , F_64 ) ,
F_72 ()
} ;
F_73 ( F_1 , & V_163 ) ;
V_156 = F_74 ( V_156 , V_157 , V_183 , V_162 , 0 ) ;
if ( V_163 . V_192 )
V_44 = 0 ;
else if ( V_163 . V_190 )
V_44 = 1 ;
else if ( V_163 . V_191 )
V_44 = 2 ;
if ( V_163 . V_195 )
V_97 . V_152 = V_153 ;
if ( ! V_184 || ! strlen ( V_184 ) ) {
if ( ! F_75 ( V_208 , & V_159 ) && F_76 ( V_159 . V_209 ) )
V_184 = L_147 ;
else
V_184 = L_148 ;
}
if ( strcmp ( V_184 , L_147 ) != 0 )
F_77 ( true ) ;
else {
V_44 = 0 ;
F_78 ( V_210 ) ;
F_79 () ;
}
V_211:
V_90 = F_80 ( V_184 , V_212 ,
V_163 . V_187 , false , & V_163 . V_10 ) ;
if ( V_90 == NULL )
return - V_37 ;
V_163 . V_90 = V_90 ;
V_160 = F_81 ( & V_90 -> V_23 ,
V_213 ) ;
if ( V_155 == - 1 && V_160 )
V_74 = V_75 ;
if ( V_74 == V_75 ) {
if ( V_110 == V_113 )
V_110 = L_149
L_150 ;
}
if ( V_163 . V_76 ) {
if ( V_74 == V_75 ) {
fprintf ( V_69 , L_151 ) ;
goto error;
}
V_74 = V_214 ;
if ( V_110 == V_113 )
V_110 = L_152 ;
}
if ( F_82 () < 0 )
F_83 ( V_162 , V_183 ) ;
if ( V_44 == 1 && V_42 ) {
V_4 . V_215 = sizeof( struct V_45 ) ;
V_163 . V_68 = V_216 ;
if ( V_132 ) {
V_4 . V_215 += sizeof( V_217 ) ;
V_4 . V_218 = true ;
}
}
if ( F_84 () < 0 )
goto error;
if ( V_114 != V_115 ) {
if ( F_85 ( L_84 ) < 0 )
goto error;
if ( ! strstr ( V_110 , L_84 ) )
V_219 . V_220 = 1 ;
}
if ( V_156 ) {
if ( V_156 > 1 )
F_83 ( V_162 , V_183 ) ;
V_163 . V_134 = V_157 [ 0 ] ;
}
F_86 ( stdout ) ;
V_67 = F_45 ( & V_163 ) ;
if ( V_67 == V_139 ) {
F_87 ( V_90 ) ;
goto V_211;
} else
V_67 = 0 ;
error:
F_87 ( V_90 ) ;
return V_67 ;
}
