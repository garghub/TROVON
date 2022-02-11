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
struct V_14 * V_14 ,
union V_15 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_7 , struct V_17 , V_7 ) ;
struct V_19 * V_20 = NULL ;
T_1 V_21 = V_16 -> V_22 . V_23 & V_24 ;
int V_25 = 0 ;
struct V_26 * V_27 ;
struct V_28 * V_29 , * V_30 ;
T_2 V_31 ;
if ( ( V_32 || V_4 . V_33 ) &&
V_11 -> V_34 ) {
V_25 = F_6 ( V_14 , V_13 , V_9 -> V_35 ,
V_11 , & V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_29 = F_7 ( V_14 , V_9 -> V_35 , V_11 , V_21 ) ;
if ( ! V_29 )
return - V_36 ;
if ( V_18 -> V_37 && ! V_9 -> V_38 )
return 0 ;
V_31 = V_11 -> V_39 ;
if ( ! V_31 )
V_31 = 1 ;
V_27 = F_8 ( & V_13 -> V_40 , V_9 , V_20 , V_29 , V_31 , V_31 ) ;
if ( ! V_27 )
return - V_36 ;
if ( V_41 && V_27 -> V_42 . V_38 && V_43 > 0 ) {
struct V_44 * V_45 = F_9 ( V_27 -> V_42 . V_38 ) ;
assert ( V_13 != NULL ) ;
if ( V_45 -> V_46 == NULL && F_10 ( V_27 -> V_42 . V_38 ) < 0 )
goto V_47;
V_25 = F_11 ( V_27 , V_13 -> V_48 , V_9 -> V_49 ) ;
if ( V_25 )
goto V_47;
}
if ( V_41 && V_27 -> V_28 -> V_50 . V_38 && V_43 > 0 ) {
struct V_44 * V_45 ;
V_30 = V_27 -> V_28 ;
V_45 = F_9 ( V_30 -> V_50 . V_38 ) ;
if ( V_45 -> V_46 == NULL && F_10 ( V_30 -> V_50 . V_38 ) < 0 )
goto V_47;
V_25 = F_12 ( V_30 -> V_50 . V_38 ,
V_30 -> V_50 . V_51 ,
V_13 -> V_48 ,
V_30 -> V_50 . V_52 ) ;
if ( V_25 )
goto V_47;
}
V_13 -> V_40 . V_53 . V_54 += V_31 ;
F_13 ( & V_13 -> V_40 , V_55 ) ;
V_25 = 0 ;
if ( V_4 . V_33 ) {
V_25 = F_14 ( V_27 -> V_34 ,
& V_56 ,
V_11 -> V_57 ) ;
}
V_47:
return V_25 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_17 * V_18 = F_5 ( V_7 , struct V_17 , V_7 ) ;
struct V_19 * V_20 = NULL ;
int V_25 = 0 ;
unsigned V_58 ;
struct V_26 * V_27 ;
struct V_59 * V_60 , * V_61 ;
if ( ( V_32 || V_4 . V_33 )
&& V_11 -> V_34 ) {
V_25 = F_6 ( V_14 , V_13 , V_9 -> V_35 ,
V_11 , & V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_60 = F_16 ( V_14 , V_9 -> V_35 ,
V_11 -> V_62 ) ;
if ( ! V_60 )
return - V_36 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_62 -> V_63 ; V_58 ++ ) {
if ( V_18 -> V_37 && ! ( V_60 [ V_58 ] . V_64 . V_38 && V_60 [ V_58 ] . V_65 . V_38 ) )
continue;
V_27 = F_17 ( & V_13 -> V_40 , V_9 , V_20 ,
& V_60 [ V_58 ] , 1 , 1 ) ;
if ( V_27 ) {
struct V_44 * V_45 ;
V_25 = - V_36 ;
V_61 = V_27 -> V_59 ;
if ( V_61 -> V_64 . V_38 && V_43 == 1 && V_41 ) {
V_45 = F_9 ( V_61 -> V_64 . V_38 ) ;
if ( ! V_45 -> V_46
&& F_10 ( V_61 -> V_64 . V_38 ) < 0 )
goto V_47;
V_25 = F_12 ( V_61 -> V_64 . V_38 ,
V_61 -> V_64 . V_51 ,
V_13 -> V_48 ,
V_61 -> V_64 . V_52 ) ;
if ( V_25 )
goto V_47;
}
if ( V_61 -> V_65 . V_38 && V_43 == 1 && V_41 ) {
V_45 = F_9 ( V_61 -> V_65 . V_38 ) ;
if ( ! V_45 -> V_46
&& F_10 ( V_61 -> V_65 . V_38 ) < 0 )
goto V_47;
V_25 = F_12 ( V_61 -> V_65 . V_38 ,
V_61 -> V_65 . V_51 ,
V_13 -> V_48 ,
V_61 -> V_65 . V_52 ) ;
if ( V_25 )
goto V_47;
}
V_13 -> V_40 . V_53 . V_54 += 1 ;
F_13 ( & V_13 -> V_40 , V_55 ) ;
V_25 = 0 ;
} else
return - V_36 ;
}
V_47:
return V_25 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_14 * V_14 )
{
struct V_19 * V_20 = NULL ;
int V_25 = 0 ;
struct V_26 * V_27 ;
if ( ( V_32 || V_4 . V_33 ) && V_11 -> V_34 ) {
V_25 = F_6 ( V_14 , V_13 , V_9 -> V_35 ,
V_11 , & V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_27 = F_19 ( & V_13 -> V_40 , V_9 , V_20 , V_11 -> V_57 ,
V_11 -> V_39 ) ;
if ( V_27 == NULL )
return - V_36 ;
if ( V_4 . V_33 ) {
V_25 = F_14 ( V_27 -> V_34 ,
& V_56 ,
V_11 -> V_57 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_27 -> V_42 . V_38 != NULL && V_43 == 1 && V_41 ) {
struct V_44 * V_45 = F_9 ( V_27 -> V_42 . V_38 ) ;
assert ( V_13 != NULL ) ;
V_25 = - V_36 ;
if ( V_45 -> V_46 == NULL && F_10 ( V_27 -> V_42 . V_38 ) < 0 )
goto V_47;
V_25 = F_11 ( V_27 , V_13 -> V_48 , V_9 -> V_49 ) ;
}
V_13 -> V_40 . V_53 . V_54 += V_11 -> V_57 ;
F_13 ( & V_13 -> V_40 , V_55 ) ;
V_47:
return V_25 ;
}
static int F_20 ( struct V_6 * V_7 ,
union V_15 * V_16 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_17 * V_18 = F_5 ( V_7 , struct V_17 , V_7 ) ;
struct V_8 V_9 ;
if ( F_21 ( V_16 , V_14 , & V_9 , V_11 ,
V_18 -> V_66 ) < 0 ) {
fprintf ( V_67 , L_2 ,
V_16 -> V_22 . type ) ;
return - 1 ;
}
if ( V_9 . V_68 || ( V_18 -> V_37 && V_9 . V_38 == NULL ) )
return 0 ;
if ( V_18 -> V_69 && ! F_22 ( V_11 -> V_70 , V_18 -> V_71 ) )
return 0 ;
if ( V_72 == 1 ) {
if ( F_15 ( V_7 , & V_9 , V_11 ,
V_13 , V_14 ) ) {
F_23 ( L_3 ) ;
return - 1 ;
}
} else if ( V_18 -> V_73 == 1 ) {
if ( F_4 ( V_7 , & V_9 , V_11 ,
V_13 , V_14 , V_16 ) ) {
F_23 ( L_4 ) ;
return - 1 ;
}
} else {
if ( V_9 . V_51 != NULL )
V_9 . V_51 -> V_74 -> V_75 = 1 ;
if ( F_18 ( V_13 , & V_9 , V_11 , V_14 ) ) {
F_23 ( L_5 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
union V_15 * V_16 ,
struct V_10 * V_11 V_76 ,
struct V_12 * V_13 ,
struct V_14 * V_14 V_76 )
{
struct V_17 * V_18 = F_5 ( V_7 , struct V_17 , V_7 ) ;
if ( V_18 -> V_77 ) {
const char * V_78 = V_13 ? F_25 ( V_13 ) : L_6 ;
F_26 ( & V_18 -> V_79 ,
V_16 -> V_80 . V_81 , V_16 -> V_80 . V_82 ,
V_16 -> V_80 . V_83 ,
V_78 ,
V_16 -> V_80 . V_2 ) ;
}
F_27 ( L_7 V_84 L_8 , V_16 -> V_80 . V_81 , V_16 -> V_80 . V_82 ,
V_13 ? F_25 ( V_13 ) : L_9 ,
V_16 -> V_80 . V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_85 * V_86 = V_18 -> V_87 ;
T_3 V_88 = F_29 ( V_86 -> V_89 ) ;
if ( ! V_86 -> V_90 && ! ( V_88 & V_91 ) ) {
if ( V_32 ) {
F_30 ( L_10
L_11
L_12 ) ;
return - V_92 ;
}
if ( V_4 . V_33 ) {
F_30 ( L_13
L_14 ) ;
return - 1 ;
}
} else if ( ! V_18 -> V_93 &&
V_94 . V_95 != V_96 &&
! V_4 . V_33 ) {
V_4 . V_33 = true ;
if ( F_31 ( & V_94 ) < 0 ) {
F_30 ( L_15 ) ;
return - V_92 ;
}
}
if ( V_72 == 1 ) {
if ( ! V_86 -> V_90 &&
! ( V_88 & V_97 ) ) {
F_30 ( L_16
L_17 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_32 ( int T_4 V_76 )
{
V_98 = 1 ;
}
static T_5 F_33 ( struct V_17 * V_18 ,
struct V_40 * V_86 ,
const char * V_99 , T_6 * V_100 )
{
T_5 V_101 ;
char V_102 ;
unsigned long V_103 = V_86 -> V_53 . V_104 [ V_55 ] ;
T_3 V_104 = V_86 -> V_53 . V_54 ;
struct V_12 * V_13 = F_34 ( V_86 ) ;
char V_105 [ 512 ] ;
T_5 V_106 = sizeof( V_105 ) ;
if ( F_35 ( V_13 ) ) {
struct V_12 * V_107 ;
F_36 ( V_13 , V_105 , V_106 ) ;
V_99 = V_105 ;
F_37 (pos, evsel) {
V_103 += V_107 -> V_40 . V_53 . V_104 [ V_55 ] ;
V_104 += V_107 -> V_40 . V_53 . V_54 ;
}
}
V_103 = F_38 ( V_103 , & V_102 ) ;
V_101 = fprintf ( V_100 , L_18 , V_103 , V_102 ) ;
if ( V_99 != NULL )
V_101 += fprintf ( V_100 , L_19 , V_99 ) ;
if ( V_18 -> V_73 ) {
V_101 += fprintf ( V_100 , L_20 V_84 , V_104 ) ;
V_101 += fprintf ( V_100 , L_21 , V_108 ) ;
} else
V_101 += fprintf ( V_100 , L_22 V_84 , V_104 ) ;
return V_101 + fprintf ( V_100 , L_23 ) ;
}
static int F_39 ( struct V_109 * V_89 ,
struct V_17 * V_18 ,
const char * V_110 )
{
struct V_12 * V_107 ;
F_40 (pos, &evlist->entries, node) {
struct V_40 * V_40 = & V_107 -> V_40 ;
const char * V_99 = F_25 ( V_107 ) ;
if ( V_4 . V_5 &&
! F_41 ( V_107 ) )
continue;
F_33 ( V_18 , V_40 , V_99 , stdout ) ;
F_42 ( V_40 , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_24 ) ;
}
if ( V_108 == V_111 &&
V_112 == V_113 ) {
fprintf ( stdout , L_25 , V_110 ) ;
if ( V_18 -> V_77 ) {
bool V_114 = ! strcmp ( V_18 -> V_115 , L_26 ) ;
F_43 ( stdout , & V_18 -> V_79 ,
V_114 ) ;
F_44 ( & V_18 -> V_79 ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_17 * V_18 )
{
int V_101 = - V_92 ;
T_3 V_103 ;
struct V_85 * V_87 = V_18 -> V_87 ;
struct V_12 * V_107 ;
struct V_51 * V_116 ;
struct V_117 * V_118 ;
const char * V_110 = L_27 ;
signal ( V_119 , F_32 ) ;
if ( V_18 -> V_69 ) {
V_101 = F_46 ( V_87 , V_18 -> V_69 ,
V_18 -> V_71 ) ;
if ( V_101 )
goto V_120;
}
if ( V_43 <= 0 )
F_47 ( V_87 , stdout , V_18 -> V_121 ) ;
if ( V_18 -> V_77 )
F_48 ( & V_18 -> V_79 ) ;
V_101 = F_28 ( V_18 ) ;
if ( V_101 )
goto V_120;
V_101 = F_49 ( V_87 , & V_18 -> V_7 ) ;
if ( V_101 )
goto V_120;
V_116 = V_87 -> V_122 . V_123 . V_124 [ V_125 ] ;
V_118 = F_50 ( V_116 ) ;
if ( V_116 == NULL ||
( V_116 -> V_74 -> V_75 &&
( V_118 -> V_126 == NULL ||
V_118 -> V_126 -> V_49 == 0 ) ) ) {
const char * V_127 =
L_28
L_29 ;
if ( V_116 ) {
const struct V_74 * V_128 = V_116 -> V_74 ;
if ( ! F_51 ( & V_128 -> V_129 [ V_125 ] ) ) {
V_127 = L_30
L_31 ;
}
}
F_52 (
L_32
L_33
L_34 ,
V_127 ) ;
}
if ( V_130 > 3 )
F_53 ( V_87 , stdout ) ;
if ( V_130 > 2 )
F_54 ( V_87 , stdout ) ;
if ( V_131 ) {
F_55 ( V_87 , stdout ) ;
goto V_120;
}
V_103 = 0 ;
F_40 (pos, &session->evlist->entries, node) {
struct V_40 * V_40 = & V_107 -> V_40 ;
if ( V_107 -> V_48 == 0 )
V_40 -> V_132 = V_18 -> V_132 ;
F_56 ( V_40 ) ;
V_103 += V_40 -> V_53 . V_104 [ V_55 ] ;
if ( V_4 . V_5 &&
! F_41 ( V_107 ) ) {
struct V_40 * V_133 = & V_107 -> V_134 -> V_40 ;
F_57 ( V_133 , V_40 ) ;
F_58 ( V_133 , V_40 ) ;
}
}
if ( V_103 == 0 ) {
F_30 ( L_35 , V_87 -> V_135 ) ;
goto V_120;
}
F_40 (pos, &session->evlist->entries, node)
F_59 ( & V_107 -> V_40 ) ;
if ( V_43 > 0 ) {
if ( V_43 == 1 ) {
V_101 = F_60 ( V_87 -> V_89 ,
V_110 ,
NULL ,
& V_87 -> V_22 . V_136 ) ;
if ( V_101 != V_137 )
V_101 = 0 ;
} else if ( V_43 == 2 ) {
F_61 ( V_87 -> V_89 , V_110 ,
NULL ) ;
}
} else
F_39 ( V_87 -> V_89 , V_18 , V_110 ) ;
V_120:
return V_101 ;
}
static int
F_62 ( const struct V_138 * V_139 , const char * V_140 , int V_141 )
{
struct V_17 * V_18 = (struct V_17 * ) V_139 -> V_2 ;
char * V_142 , * V_143 ;
char * V_144 ;
if ( V_141 ) {
V_18 -> V_93 = true ;
return 0 ;
}
V_4 . V_33 = true ;
if ( ! V_140 )
return 0 ;
V_142 = strtok ( ( char * ) V_140 , L_36 ) ;
if ( ! V_142 )
return - 1 ;
if ( ! strncmp ( V_142 , L_37 , strlen ( V_140 ) ) )
V_94 . V_95 = V_145 ;
else if ( ! strncmp ( V_142 , L_38 , strlen ( V_140 ) ) )
V_94 . V_95 = V_146 ;
else if ( ! strncmp ( V_142 , L_39 , strlen ( V_140 ) ) )
V_94 . V_95 = V_147 ;
else if ( ! strncmp ( V_142 , L_40 , strlen ( V_140 ) ) ) {
V_94 . V_95 = V_96 ;
V_4 . V_33 = false ;
return 0 ;
}
else
return - 1 ;
V_142 = strtok ( NULL , L_36 ) ;
if ( ! V_142 )
goto V_148;
V_94 . V_149 = strtod ( V_142 , & V_144 ) ;
if ( V_142 == V_144 )
return - 1 ;
V_143 = strtok ( NULL , L_36 ) ;
if ( ! V_143 )
goto V_148;
if ( V_143 [ 0 ] != 'c' ) {
V_94 . V_150 = strtoul ( V_143 , & V_144 , 0 ) ;
V_143 = strtok ( NULL , L_36 ) ;
if ( ! V_143 )
goto V_148;
}
if ( ! strcmp ( V_143 , L_41 ) )
V_94 . V_151 = V_152 ;
else if ( ! strcmp ( V_143 , L_42 ) )
V_94 . V_151 = V_153 ;
else
return - 1 ;
V_148:
if ( F_31 ( & V_94 ) < 0 ) {
fprintf ( V_67 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_63 ( const struct V_138 * V_139 V_76 ,
const char * T_7 V_76 , int V_141 )
{
V_72 = ! V_141 ;
return 0 ;
}
int F_64 ( int V_154 , const char * * V_155 , const char * T_8 V_76 )
{
struct V_85 * V_87 ;
struct V_156 V_157 ;
bool V_158 = false ;
int V_101 = - 1 ;
char V_159 [] = L_44 ;
const char * const V_160 [] = {
L_45 ,
NULL
} ;
struct V_17 V_161 = {
. V_7 = {
. V_11 = F_20 ,
. V_162 = V_163 ,
. V_164 = V_165 ,
. exit = V_166 ,
. V_167 = V_168 ,
. V_169 = V_170 ,
. V_80 = F_24 ,
. V_171 = V_172 ,
. V_173 = V_174 ,
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_179 = true ,
. V_180 = true ,
} ,
. V_115 = L_46 ,
} ;
const struct V_138 V_181 [] = {
F_65 ( 'i' , L_47 , & V_182 , L_48 ,
L_49 ) ,
F_66 ( 'v' , L_50 , & V_130 ,
L_51 ) ,
F_67 ( 'D' , L_52 , & V_131 ,
L_53 ) ,
F_65 ( 'k' , L_54 , & V_4 . V_183 ,
L_48 , L_55 ) ,
F_65 ( 0 , L_56 , & V_4 . V_184 ,
L_48 , L_57 ) ,
F_67 ( 'f' , L_58 , & V_161 . V_185 , L_59 ) ,
F_67 ( 'm' , L_60 , & V_4 . V_186 ,
L_61 ) ,
F_67 ( 'n' , L_62 , & V_4 . V_187 ,
L_63 ) ,
F_67 ( 'T' , L_64 , & V_161 . V_77 ,
L_65 ) ,
F_65 ( 0 , L_66 , & V_161 . V_115 , L_67 ,
L_68 ) ,
F_67 ( 0 , L_69 , & V_161 . V_188 , L_70 ) ,
F_67 ( 0 , L_71 , & V_161 . V_189 , L_72 ) ,
F_67 ( 0 , L_73 , & V_161 . V_190 ,
L_74 ) ,
F_65 ( 's' , L_75 , & V_108 , L_76 ,
L_77
L_78
L_79
L_80 ) ,
F_67 ( 0 , L_81 , & V_4 . V_191 ,
L_82 ) ,
F_65 ( 'p' , L_83 , & V_112 , L_84 ,
L_85 ) ,
F_67 ( 'x' , L_86 , & V_4 . V_192 ,
L_87 ) ,
F_68 ( 'g' , L_88 , & V_161 , L_89 ,
L_90
L_91 , & F_62 , V_159 ) ,
F_67 ( 'G' , L_92 , & V_161 . V_193 ,
L_93 ) ,
F_65 ( 'd' , L_94 , & V_4 . V_194 , L_95 ,
L_96 ) ,
F_65 ( 'c' , L_97 , & V_4 . V_195 , L_98 ,
L_99 ) ,
F_65 ( 'S' , L_100 , & V_4 . V_196 , L_101 ,
L_102 ) ,
F_65 ( 0 , L_103 , & V_161 . V_132 , L_104 ,
L_105 ) ,
F_65 ( 'w' , L_106 , & V_4 . V_197 ,
L_107 ,
L_108 ) ,
F_65 ( 't' , L_109 , & V_4 . V_198 , L_110 ,
L_111
L_112 ) ,
F_67 ( 'U' , L_113 , & V_161 . V_37 ,
L_114 ) ,
F_65 ( 0 , L_115 , & V_4 . V_199 , L_116 ,
L_117 ) ,
F_65 ( 'C' , L_118 , & V_161 . V_69 , L_118 ,
L_119 ) ,
F_67 ( 'I' , L_120 , & V_161 . V_121 ,
L_121 ) ,
F_67 ( 0 , L_122 , & V_4 . V_200 ,
L_123 ) ,
F_67 ( 0 , L_124 , & V_4 . V_201 ,
L_125 ) ,
F_65 ( 'M' , L_126 , & V_202 , L_127 ,
L_128 ) ,
F_67 ( 0 , L_129 , & V_4 . V_203 ,
L_130 ) ,
F_67 ( 0 , L_131 , & V_4 . V_5 ,
L_132 ) ,
F_69 ( 'b' , L_133 , & V_72 , L_134 ,
L_135 , F_63 ) ,
F_65 ( 0 , L_136 , & V_204 , L_137 ,
L_138 ) ,
F_67 ( 0 , L_139 , & V_4 . V_205 ,
L_140 ) ,
F_67 ( 0 , L_141 , & V_161 . V_73 , L_142 ) ,
F_70 ()
} ;
F_71 ( F_1 , NULL ) ;
V_154 = F_72 ( V_154 , V_155 , V_181 , V_160 , 0 ) ;
if ( V_161 . V_190 )
V_43 = 0 ;
else if ( V_161 . V_188 )
V_43 = 1 ;
else if ( V_161 . V_189 )
V_43 = 2 ;
if ( V_161 . V_193 )
V_94 . V_151 = V_152 ;
if ( ! V_182 || ! strlen ( V_182 ) ) {
if ( ! F_73 ( V_206 , & V_157 ) && F_74 ( V_157 . V_207 ) )
V_182 = L_143 ;
else
V_182 = L_144 ;
}
if ( strcmp ( V_182 , L_143 ) != 0 )
F_75 ( true ) ;
else {
V_43 = 0 ;
F_76 ( V_208 ) ;
F_77 () ;
}
V_209:
V_87 = F_78 ( V_182 , V_210 ,
V_161 . V_185 , false , & V_161 . V_7 ) ;
if ( V_87 == NULL )
return - V_36 ;
V_161 . V_87 = V_87 ;
V_158 = F_79 ( & V_87 -> V_22 ,
V_211 ) ;
if ( V_72 == - 1 && V_158 )
V_72 = 1 ;
if ( V_72 == 1 ) {
if ( V_108 == V_111 )
V_108 = L_145
L_146 ;
}
if ( V_161 . V_73 ) {
if ( V_72 == 1 ) {
fprintf ( V_67 , L_147 ) ;
goto error;
}
if ( V_108 == V_111 )
V_108 = L_148 ;
}
if ( F_80 () < 0 )
F_81 ( V_160 , V_181 ) ;
if ( V_43 == 1 && V_41 ) {
V_4 . V_212 = sizeof( struct V_44 ) ;
V_161 . V_66 = V_213 ;
if ( V_130 ) {
V_4 . V_212 += sizeof( V_214 ) ;
V_4 . V_215 = true ;
}
}
if ( F_82 () < 0 )
goto error;
if ( V_112 != V_113 ) {
if ( F_83 ( L_83 ) < 0 )
goto error;
if ( ! strstr ( V_108 , L_83 ) )
V_216 . V_217 = 1 ;
} else
V_4 . V_192 = false ;
if ( V_154 ) {
if ( V_154 > 1 )
F_81 ( V_160 , V_181 ) ;
V_161 . V_132 = V_155 [ 0 ] ;
}
F_84 ( & V_218 , V_4 . V_219 , L_149 , stdout ) ;
if ( V_72 == 1 ) {
F_84 ( & V_220 , V_4 . V_221 , L_150 , stdout ) ;
F_84 ( & V_222 , V_4 . V_223 , L_151 , stdout ) ;
F_84 ( & V_224 , V_4 . V_225 , L_152 , stdout ) ;
F_84 ( & V_226 , V_4 . V_227 , L_153 , stdout ) ;
} else {
if ( V_161 . V_73 ) {
F_84 ( & V_228 , V_4 . V_229 , L_154 , stdout ) ;
F_84 ( & V_228 , V_4 . V_229 , L_155 , stdout ) ;
F_84 ( & V_228 , V_4 . V_229 , L_156 , stdout ) ;
F_84 ( & V_228 , V_4 . V_229 , L_157 , stdout ) ;
F_84 ( & V_228 , V_4 . V_229 , L_158 , stdout ) ;
F_84 ( & V_228 , V_4 . V_229 , L_159 , stdout ) ;
}
F_84 ( & V_228 , V_4 . V_229 , L_160 , stdout ) ;
F_84 ( & V_230 , V_4 . V_231 , L_161 , stdout ) ;
}
V_101 = F_45 ( & V_161 ) ;
if ( V_101 == V_137 ) {
F_85 ( V_87 ) ;
goto V_209;
} else
V_101 = 0 ;
error:
F_85 ( V_87 ) ;
return V_101 ;
}
