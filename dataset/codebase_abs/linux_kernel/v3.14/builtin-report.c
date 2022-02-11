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
static int F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 , struct V_15 * V_16 ,
union V_17 * V_18 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_19 * V_20 = NULL ;
T_1 V_21 = V_18 -> V_22 . V_23 & V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 , * V_29 ;
T_2 V_30 ;
int V_31 = F_6 ( V_14 , & V_20 , V_16 , V_12 , V_7 -> V_32 ) ;
if ( V_31 )
return V_31 ;
V_28 = F_7 ( V_12 -> V_33 , V_12 -> V_34 , V_14 , V_21 ) ;
if ( ! V_28 )
return - V_35 ;
if ( V_7 -> V_36 && ! V_12 -> V_37 )
return 0 ;
V_30 = V_14 -> V_38 ;
if ( ! V_30 )
V_30 = 1 ;
V_26 = F_8 ( & V_16 -> V_39 , V_12 , V_20 , NULL , V_28 ,
V_30 , V_30 , 0 ) ;
if ( ! V_26 )
return - V_35 ;
if ( F_9 () ) {
V_31 = F_10 ( V_26 , V_16 -> V_40 , V_12 -> V_41 ) ;
if ( V_31 )
goto V_42;
V_29 = V_26 -> V_27 ;
V_31 = F_11 ( & V_29 -> V_43 , V_16 -> V_40 ) ;
if ( V_31 )
goto V_42;
}
V_16 -> V_39 . V_44 . V_45 += V_30 ;
F_12 ( & V_16 -> V_39 , V_46 ) ;
V_31 = F_13 ( V_26 , V_14 ) ;
V_42:
return V_31 ;
}
static int F_14 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_19 * V_20 = NULL ;
unsigned V_47 ;
struct V_25 * V_26 ;
struct V_48 * V_49 , * V_50 ;
int V_31 = F_6 ( V_14 , & V_20 , V_16 , V_12 , V_7 -> V_32 ) ;
if ( V_31 )
return V_31 ;
V_49 = F_15 ( V_12 -> V_33 , V_12 -> V_34 ,
V_14 -> V_51 ) ;
if ( ! V_49 )
return - V_35 ;
for ( V_47 = 0 ; V_47 < V_14 -> V_51 -> V_52 ; V_47 ++ ) {
if ( V_7 -> V_36 && ! ( V_49 [ V_47 ] . V_53 . V_37 && V_49 [ V_47 ] . V_54 . V_37 ) )
continue;
V_31 = - V_35 ;
V_12 -> V_55 = V_49 [ V_47 ] . V_54 . V_55 ;
V_12 -> V_37 = V_49 [ V_47 ] . V_54 . V_37 ;
V_12 -> V_41 = V_49 [ V_47 ] . V_54 . V_41 ;
V_26 = F_8 ( & V_16 -> V_39 , V_12 , V_20 , & V_49 [ V_47 ] , NULL ,
1 , 1 , 0 ) ;
if ( V_26 ) {
if ( F_9 () ) {
V_50 = V_26 -> V_48 ;
V_31 = F_11 ( & V_50 -> V_53 ,
V_16 -> V_40 ) ;
if ( V_31 )
goto V_42;
V_31 = F_11 ( & V_50 -> V_54 ,
V_16 -> V_40 ) ;
if ( V_31 )
goto V_42;
}
V_16 -> V_39 . V_44 . V_45 += 1 ;
F_12 ( & V_16 -> V_39 , V_46 ) ;
} else
goto V_42;
}
V_31 = 0 ;
V_42:
free ( V_49 ) ;
return V_31 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_15 * V_16 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_19 * V_20 = NULL ;
struct V_25 * V_26 ;
int V_31 = F_6 ( V_14 , & V_20 , V_16 , V_12 , V_7 -> V_32 ) ;
if ( V_31 )
return V_31 ;
V_26 = F_8 ( & V_16 -> V_39 , V_12 , V_20 , NULL , NULL ,
V_14 -> V_56 , V_14 -> V_38 ,
V_14 -> V_57 ) ;
if ( V_26 == NULL )
return - V_35 ;
V_31 = F_13 ( V_26 , V_14 ) ;
if ( V_31 )
goto V_42;
if ( F_9 () )
V_31 = F_10 ( V_26 , V_16 -> V_40 , V_12 -> V_41 ) ;
V_16 -> V_39 . V_44 . V_45 += V_14 -> V_56 ;
F_12 ( & V_16 -> V_39 , V_46 ) ;
V_42:
return V_31 ;
}
static int F_17 ( struct V_9 * V_10 ,
union V_17 * V_18 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_33 * V_33 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
struct V_11 V_12 ;
int V_58 ;
if ( F_18 ( V_18 , V_33 , & V_12 , V_14 ) < 0 ) {
F_19 ( L_3 ,
V_18 -> V_22 . type ) ;
return - 1 ;
}
if ( V_12 . V_59 || ( V_7 -> V_36 && V_12 . V_37 == NULL ) )
return 0 ;
if ( V_7 -> V_60 && ! F_20 ( V_14 -> V_61 , V_7 -> V_62 ) )
return 0 ;
if ( V_63 == V_64 ) {
V_58 = F_14 ( V_10 , & V_12 , V_14 , V_16 ) ;
if ( V_58 < 0 )
F_19 ( L_4 ) ;
} else if ( V_7 -> V_65 == 1 ) {
V_58 = F_4 ( V_10 , & V_12 , V_14 , V_16 , V_18 ) ;
if ( V_58 < 0 )
F_19 ( L_5 ) ;
} else {
if ( V_12 . V_55 != NULL )
V_12 . V_55 -> V_66 -> V_67 = 1 ;
V_58 = F_16 ( V_10 , V_16 , & V_12 , V_14 ) ;
if ( V_58 < 0 )
F_19 ( L_6 ) ;
}
return V_58 ;
}
static int F_21 ( struct V_9 * V_10 ,
union V_17 * V_18 ,
struct V_13 * V_14 V_68 ,
struct V_15 * V_16 ,
struct V_33 * V_33 V_68 )
{
struct V_6 * V_7 = F_5 ( V_10 , struct V_6 , V_10 ) ;
if ( V_7 -> V_69 ) {
const char * V_70 = V_16 ? F_22 ( V_16 ) : L_7 ;
F_23 ( & V_7 -> V_71 ,
V_18 -> V_72 . V_73 , V_18 -> V_72 . V_74 ,
V_18 -> V_72 . V_75 ,
V_70 ,
V_18 -> V_72 . V_2 ) ;
}
F_24 ( L_8 V_76 L_9 , V_18 -> V_72 . V_73 , V_18 -> V_72 . V_74 ,
V_16 ? F_22 ( V_16 ) : L_10 ,
V_18 -> V_72 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_77 * V_78 = V_7 -> V_78 ;
T_3 V_79 = F_26 ( V_78 -> V_80 ) ;
bool V_81 = F_27 ( V_78 -> V_82 ) ;
if ( ! V_81 && ! ( V_79 & V_83 ) ) {
if ( V_84 ) {
F_28 ( L_11
L_12
L_13 ) ;
return - V_85 ;
}
if ( V_4 . V_86 ) {
F_28 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_87 &&
V_88 . V_89 != V_90 &&
! V_4 . V_86 ) {
V_4 . V_86 = true ;
if ( F_29 ( & V_88 ) < 0 ) {
F_28 ( L_16 ) ;
return - V_85 ;
}
}
if ( V_63 == V_64 ) {
if ( ! V_81 &&
! ( V_79 & V_91 ) ) {
F_28 ( L_17
L_18 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_30 ( int T_4 V_68 )
{
V_92 = 1 ;
}
static T_5 F_31 ( struct V_39 * V_39 , struct V_6 * V_7 ,
const char * V_93 , T_6 * V_94 )
{
T_5 V_58 ;
char V_95 ;
unsigned long V_96 = V_39 -> V_44 . V_97 [ V_46 ] ;
T_3 V_97 = V_39 -> V_44 . V_45 ;
struct V_15 * V_16 = F_32 ( V_39 ) ;
char V_98 [ 512 ] ;
T_5 V_99 = sizeof( V_98 ) ;
if ( F_33 ( V_16 ) ) {
struct V_15 * V_100 ;
F_34 ( V_16 , V_98 , V_99 ) ;
V_93 = V_98 ;
F_35 (pos, evsel) {
V_96 += V_100 -> V_39 . V_44 . V_97 [ V_46 ] ;
V_97 += V_100 -> V_39 . V_44 . V_45 ;
}
}
V_96 = F_36 ( V_96 , & V_95 ) ;
V_58 = fprintf ( V_94 , L_19 , V_96 , V_95 ) ;
if ( V_93 != NULL )
V_58 += fprintf ( V_94 , L_20 , V_93 ) ;
if ( V_7 -> V_65 ) {
V_58 += fprintf ( V_94 , L_21 V_76 , V_97 ) ;
V_58 += fprintf ( V_94 , L_22 , V_101 ) ;
} else
V_58 += fprintf ( V_94 , L_23 V_76 , V_97 ) ;
return V_58 + fprintf ( V_94 , L_24 ) ;
}
static int F_37 ( struct V_102 * V_80 ,
struct V_6 * V_7 ,
const char * V_103 )
{
struct V_15 * V_100 ;
F_38 (evlist, pos) {
struct V_39 * V_39 = & V_100 -> V_39 ;
const char * V_93 = F_22 ( V_100 ) ;
if ( V_4 . V_5 &&
! F_39 ( V_100 ) )
continue;
F_31 ( V_39 , V_7 , V_93 , stdout ) ;
F_40 ( V_39 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_101 == V_104 &&
V_105 == V_106 ) {
fprintf ( stdout , L_26 , V_103 ) ;
if ( V_7 -> V_69 ) {
bool V_107 = ! strcmp ( V_7 -> V_108 , L_27 ) ;
F_41 ( stdout , & V_7 -> V_71 ,
V_107 ) ;
F_42 ( & V_7 -> V_71 ) ;
}
}
return 0 ;
}
static void F_43 ( const struct V_6 * V_7 )
{
struct V_55 * V_109 = V_7 -> V_78 -> V_110 . V_111 . V_112 [ V_113 ] ;
struct V_114 * V_115 = F_44 ( V_109 ) ;
if ( V_109 == NULL ||
( V_109 -> V_66 -> V_67 &&
( V_115 -> V_116 == NULL ||
V_115 -> V_116 -> V_41 == 0 ) ) ) {
const char * V_117 =
L_28
L_29 ;
if ( V_109 ) {
const struct V_66 * V_118 = V_109 -> V_66 ;
if ( ! F_45 ( & V_118 -> V_119 [ V_113 ] ) ) {
V_117 = L_30
L_31 ;
}
}
F_46 (
L_32
L_33
L_34 ,
V_117 ) ;
}
}
static int F_47 ( struct V_6 * V_7 , const char * V_103 )
{
int (* F_48)( struct V_102 * V_80 , const char * V_103 ,
struct V_120 * V_121 , float V_122 );
F_48 = F_49 ( V_123 , L_35 ) ;
if ( F_48 == NULL ) {
F_28 ( L_36 ) ;
return - 1 ;
}
return F_48 ( V_7 -> V_78 -> V_80 , V_103 , NULL , V_7 -> V_8 ) ;
}
static int F_50 ( struct V_6 * V_7 )
{
int V_58 ;
struct V_77 * V_78 = V_7 -> V_78 ;
struct V_102 * V_80 = V_78 -> V_80 ;
const char * V_103 = L_37 ;
switch ( V_124 ) {
case 1 :
V_58 = F_51 ( V_80 , V_103 , NULL ,
V_7 -> V_8 ,
& V_78 -> V_22 . V_125 ) ;
if ( V_58 != V_126 )
V_58 = 0 ;
break;
case 2 :
V_58 = F_47 ( V_7 , V_103 ) ;
break;
default:
V_58 = F_37 ( V_80 , V_7 , V_103 ) ;
break;
}
return V_58 ;
}
static T_3 F_52 ( struct V_6 * V_7 )
{
struct V_127 V_128 ;
struct V_15 * V_100 ;
T_3 V_96 = 0 ;
F_38 (rep->session->evlist, pos)
V_96 += V_100 -> V_39 . V_129 ;
F_53 ( & V_128 , V_96 , L_38 ) ;
V_96 = 0 ;
F_38 (rep->session->evlist, pos) {
struct V_39 * V_39 = & V_100 -> V_39 ;
if ( V_100 -> V_40 == 0 )
V_39 -> V_130 = V_7 -> V_130 ;
F_54 ( V_39 , & V_128 ) ;
V_96 += V_39 -> V_44 . V_97 [ V_46 ] ;
if ( V_4 . V_5 &&
! F_39 ( V_100 ) ) {
struct V_39 * V_131 = & V_100 -> V_132 -> V_39 ;
F_55 ( V_131 , V_39 ) ;
F_56 ( V_131 , V_39 ) ;
}
}
F_57 () ;
return V_96 ;
}
static int F_58 ( struct V_6 * V_7 )
{
int V_58 ;
T_3 V_96 ;
struct V_77 * V_78 = V_7 -> V_78 ;
struct V_15 * V_100 ;
struct V_133 * V_82 = V_78 -> V_82 ;
signal ( V_134 , F_30 ) ;
if ( V_7 -> V_60 ) {
V_58 = F_59 ( V_78 , V_7 -> V_60 ,
V_7 -> V_62 ) ;
if ( V_58 )
return V_58 ;
}
if ( V_7 -> V_69 )
F_60 ( & V_7 -> V_71 ) ;
V_58 = F_25 ( V_7 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_61 ( V_78 , & V_7 -> V_10 ) ;
if ( V_58 )
return V_58 ;
F_43 ( V_7 ) ;
if ( V_124 == 0 ) {
if ( V_135 > 3 )
F_62 ( V_78 , stdout ) ;
if ( V_135 > 2 )
F_63 ( V_78 , stdout ) ;
if ( V_136 ) {
F_64 ( V_78 , stdout ) ;
return 0 ;
}
}
V_96 = F_52 ( V_7 ) ;
if ( V_92 () )
return 0 ;
if ( V_96 == 0 ) {
F_28 ( L_39 , V_82 -> V_137 ) ;
return 0 ;
}
F_38 (session->evlist, pos)
F_65 ( & V_100 -> V_39 ) ;
return F_50 ( V_7 ) ;
}
static int
F_66 ( const struct V_138 * V_139 , const char * V_140 , int V_141 )
{
struct V_6 * V_7 = (struct V_6 * ) V_139 -> V_2 ;
char * V_142 , * V_143 ;
char * V_144 ;
if ( V_141 ) {
V_7 -> V_87 = true ;
return 0 ;
}
V_4 . V_86 = true ;
if ( ! V_140 )
return 0 ;
V_142 = strtok ( ( char * ) V_140 , L_40 ) ;
if ( ! V_142 )
return - 1 ;
if ( ! strncmp ( V_142 , L_41 , strlen ( V_140 ) ) )
V_88 . V_89 = V_145 ;
else if ( ! strncmp ( V_142 , L_42 , strlen ( V_140 ) ) )
V_88 . V_89 = V_146 ;
else if ( ! strncmp ( V_142 , L_43 , strlen ( V_140 ) ) )
V_88 . V_89 = V_147 ;
else if ( ! strncmp ( V_142 , L_44 , strlen ( V_140 ) ) ) {
V_88 . V_89 = V_90 ;
V_4 . V_86 = false ;
return 0 ;
}
else
return - 1 ;
V_142 = strtok ( NULL , L_40 ) ;
if ( ! V_142 )
goto V_148;
V_88 . V_8 = strtod ( V_142 , & V_144 ) ;
if ( V_142 == V_144 )
return - 1 ;
V_143 = strtok ( NULL , L_40 ) ;
if ( ! V_143 )
goto V_148;
if ( V_143 [ 0 ] != 'c' ) {
V_88 . V_149 = strtoul ( V_143 , & V_144 , 0 ) ;
V_143 = strtok ( NULL , L_40 ) ;
if ( ! V_143 )
goto V_148;
}
if ( ! strncmp ( V_143 , L_45 , strlen ( L_45 ) ) )
V_88 . V_150 = V_151 ;
else if ( ! strncmp ( V_143 , L_46 , strlen ( L_46 ) ) )
V_88 . V_150 = V_152 ;
else
return - 1 ;
V_143 = strtok ( NULL , L_40 ) ;
if ( ! V_143 )
goto V_148;
if ( ! strncmp ( V_143 , L_47 , strlen ( L_47 ) ) )
V_88 . V_153 = V_154 ;
else if ( ! strncmp ( V_143 , L_48 , strlen ( L_48 ) ) )
V_88 . V_153 = V_155 ;
else
return - 1 ;
V_148:
if ( F_29 ( & V_88 ) < 0 ) {
F_67 ( L_49 ) ;
return - 1 ;
}
return 0 ;
}
int
F_68 ( const struct V_138 * V_139 V_68 ,
const char * V_140 , int V_141 V_68 )
{
if ( V_140 ) {
int V_31 = regcomp ( & V_156 , V_140 , V_157 ) ;
if ( V_31 ) {
char V_98 [ V_158 ] ;
regerror ( V_31 , & V_156 , V_98 , sizeof( V_98 ) ) ;
F_67 ( L_50 , V_140 , V_98 ) ;
return - 1 ;
}
V_159 = 1 ;
}
return 0 ;
}
static int
F_69 ( const struct V_138 * V_139 V_68 ,
const char * T_7 V_68 , int V_141 )
{
int * V_160 = V_139 -> V_2 ;
* V_160 = ! V_141 ;
return 0 ;
}
static int
F_70 ( const struct V_138 * V_139 , const char * T_7 ,
int V_141 V_68 )
{
struct V_6 * V_7 = V_139 -> V_2 ;
V_7 -> V_8 = strtof ( T_7 , NULL ) ;
return 0 ;
}
int F_71 ( int V_161 , const char * * V_162 , const char * T_8 V_68 )
{
struct V_77 * V_78 ;
struct V_163 V_164 ;
bool V_165 = false ;
int V_160 = - 1 ;
int V_58 = - 1 ;
char V_166 [] = L_51 ;
const char * const V_167 [] = {
L_52 ,
NULL
} ;
struct V_6 V_6 = {
. V_10 = {
. V_14 = F_17 ,
. V_168 = V_169 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. exit = V_174 ,
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_72 = F_21 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. V_183 = V_184 ,
. V_185 = true ,
. V_186 = true ,
} ,
. V_32 = V_187 ,
. V_108 = L_53 ,
} ;
const struct V_138 V_188 [] = {
F_72 ( 'i' , L_54 , & V_189 , L_55 ,
L_56 ) ,
F_73 ( 'v' , L_57 , & V_135 ,
L_58 ) ,
F_74 ( 'D' , L_59 , & V_136 ,
L_60 ) ,
F_72 ( 'k' , L_61 , & V_4 . V_190 ,
L_55 , L_62 ) ,
F_72 ( 0 , L_63 , & V_4 . V_191 ,
L_55 , L_64 ) ,
F_74 ( 'f' , L_65 , & V_6 . V_192 , L_66 ) ,
F_74 ( 'm' , L_67 , & V_4 . V_193 ,
L_68 ) ,
F_74 ( 'n' , L_69 , & V_4 . V_194 ,
L_70 ) ,
F_74 ( 'T' , L_71 , & V_6 . V_69 ,
L_72 ) ,
F_72 ( 0 , L_73 , & V_6 . V_108 , L_74 ,
L_75 ) ,
F_74 ( 0 , L_76 , & V_6 . V_195 , L_77 ) ,
F_74 ( 0 , L_78 , & V_6 . V_196 , L_79 ) ,
F_74 ( 0 , L_80 , & V_6 . V_197 ,
L_81 ) ,
F_74 ( 0 , L_82 , & V_6 . V_22 , L_83 ) ,
F_74 ( 0 , L_84 , & V_6 . V_198 ,
L_85 ) ,
F_72 ( 's' , L_86 , & V_101 , L_87 ,
L_88
L_89
L_90
L_91 ) ,
F_74 ( 0 , L_92 , & V_4 . V_199 ,
L_93 ) ,
F_72 ( 'p' , L_94 , & V_105 , L_95 ,
L_96 ) ,
F_74 ( 'x' , L_97 , & V_4 . V_200 ,
L_98 ) ,
F_75 ( 'g' , L_99 , & V_6 , L_100 ,
L_101
L_102 , & F_66 , V_166 ) ,
F_76 ( 0 , L_103 , & V_6 . V_32 ,
L_104
L_105
L_106 F_77 ( V_187 ) ) ,
F_74 ( 'G' , L_107 , & V_6 . V_201 ,
L_108 ) ,
F_78 ( 0 , L_109 , NULL , L_95 ,
L_110 ,
F_68 ) ,
F_72 ( 'd' , L_111 , & V_4 . V_202 , L_112 ,
L_113 ) ,
F_72 ( 'c' , L_114 , & V_4 . V_203 , L_115 ,
L_116 ) ,
F_72 ( 'S' , L_117 , & V_4 . V_204 , L_118 ,
L_119 ) ,
F_72 ( 0 , L_120 , & V_6 . V_130 , L_121 ,
L_122 ) ,
F_72 ( 'w' , L_123 , & V_4 . V_205 ,
L_124 ,
L_125 ) ,
F_72 ( 't' , L_126 , & V_4 . V_206 , L_127 ,
L_128
L_129 ) ,
F_74 ( 'U' , L_130 , & V_6 . V_36 ,
L_131 ) ,
F_72 ( 0 , L_132 , & V_4 . V_207 , L_133 ,
L_134 ) ,
F_72 ( 'C' , L_135 , & V_6 . V_60 , L_135 ,
L_136 ) ,
F_74 ( 'I' , L_137 , & V_6 . V_208 ,
L_138 ) ,
F_74 ( 0 , L_139 , & V_4 . V_209 ,
L_140 ) ,
F_74 ( 0 , L_141 , & V_4 . V_210 ,
L_142 ) ,
F_72 ( 'M' , L_143 , & V_211 , L_144 ,
L_145 ) ,
F_74 ( 0 , L_146 , & V_4 . V_212 ,
L_147 ) ,
F_74 ( 0 , L_148 , & V_4 . V_5 ,
L_149 ) ,
F_79 ( 'b' , L_150 , & V_160 , L_151 ,
L_152 , F_69 ) ,
F_72 ( 0 , L_153 , & V_213 , L_154 ,
L_155 ) ,
F_74 ( 0 , L_156 , & V_4 . V_214 ,
L_157 ) ,
F_74 ( 0 , L_158 , & V_6 . V_65 , L_159 ) ,
F_78 ( 0 , L_160 , & V_6 , L_161 ,
L_162 , F_70 ) ,
F_80 ()
} ;
struct V_133 V_82 = {
. V_89 = V_215 ,
} ;
F_81 ( F_1 , & V_6 ) ;
V_161 = F_82 ( V_161 , V_162 , V_188 , V_167 , 0 ) ;
if ( V_6 . V_197 )
V_124 = 0 ;
else if ( V_6 . V_195 )
V_124 = 1 ;
else if ( V_6 . V_196 )
V_124 = 2 ;
if ( V_6 . V_201 )
V_88 . V_150 = V_151 ;
if ( ! V_189 || ! strlen ( V_189 ) ) {
if ( ! F_83 ( V_216 , & V_164 ) && F_84 ( V_164 . V_217 ) )
V_189 = L_163 ;
else
V_189 = L_164 ;
}
V_82 . V_137 = V_189 ;
V_82 . V_192 = V_6 . V_192 ;
V_218:
V_78 = F_85 ( & V_82 , false , & V_6 . V_10 ) ;
if ( V_78 == NULL )
return - V_35 ;
V_6 . V_78 = V_78 ;
V_165 = F_86 ( & V_78 -> V_22 ,
V_219 ) ;
if ( V_160 == - 1 && V_165 )
V_63 = V_64 ;
if ( V_63 == V_64 ) {
if ( V_101 == V_104 )
V_101 = L_165
L_166 ;
}
if ( V_6 . V_65 ) {
if ( V_63 == V_64 ) {
F_67 ( L_167 ) ;
goto error;
}
V_63 = V_220 ;
if ( V_101 == V_104 )
V_101 = L_168 ;
}
if ( F_87 () < 0 ) {
F_88 ( V_167 , V_188 , L_169 , 1 ) ;
goto error;
}
if ( V_105 != V_106 ) {
if ( F_89 ( L_94 ) < 0 )
goto error;
}
if ( V_6 . V_22 || V_6 . V_198 )
V_124 = 0 ;
if ( strcmp ( V_189 , L_163 ) != 0 )
F_90 ( true ) ;
else {
V_124 = 0 ;
F_91 () ;
}
if ( V_6 . V_22 || V_6 . V_198 ) {
F_92 ( V_78 , stdout ,
V_6 . V_208 ) ;
if ( V_6 . V_198 )
return 0 ;
} else if ( V_124 == 0 ) {
fputs ( L_170 ,
stdout ) ;
}
if ( V_124 == 1 && V_221 ) {
V_4 . V_222 = sizeof( struct V_223 ) ;
F_93 ( & V_78 -> V_110 ,
V_224 ) ;
if ( V_135 ) {
V_4 . V_222 += sizeof( V_225 ) ;
V_4 . V_226 = true ;
}
}
if ( F_94 () < 0 )
goto error;
if ( V_161 ) {
if ( V_161 > 1 )
F_95 ( V_167 , V_188 ) ;
V_6 . V_130 = V_162 [ 0 ] ;
}
F_96 ( stdout ) ;
V_58 = F_58 ( & V_6 ) ;
if ( V_58 == V_126 ) {
F_97 ( V_78 ) ;
goto V_218;
} else
V_58 = 0 ;
error:
F_97 ( V_78 ) ;
return V_58 ;
}
