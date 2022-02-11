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
static int F_4 ( struct V_6 * V_7 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 ;
T_1 V_22 ;
int V_23 = F_5 ( V_12 , & V_16 , V_14 , V_10 , V_7 -> V_24 ) ;
if ( V_23 )
return V_23 ;
V_20 = F_6 ( V_12 , V_10 ) ;
if ( ! V_20 )
return - V_25 ;
if ( V_7 -> V_26 && ! V_10 -> V_27 )
return 0 ;
V_22 = V_12 -> V_28 ;
if ( ! V_22 )
V_22 = 1 ;
V_18 = F_7 ( & V_14 -> V_29 , V_10 , V_16 , NULL , V_20 ,
V_22 , V_22 , 0 ) ;
if ( ! V_18 )
return - V_25 ;
if ( F_8 () ) {
V_23 = F_9 ( V_18 , V_14 -> V_30 , V_10 -> V_31 ) ;
if ( V_23 )
goto V_32;
V_21 = V_18 -> V_19 ;
V_23 = F_10 ( & V_21 -> V_33 , V_14 -> V_30 ) ;
if ( V_23 )
goto V_32;
}
V_14 -> V_29 . V_34 . V_35 += V_22 ;
F_11 ( & V_14 -> V_29 , V_36 ) ;
V_23 = F_12 ( V_18 , V_12 ) ;
V_32:
return V_23 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = NULL ;
unsigned V_37 ;
struct V_17 * V_18 ;
struct V_38 * V_39 , * V_40 ;
int V_23 = F_5 ( V_12 , & V_16 , V_14 , V_10 , V_7 -> V_24 ) ;
if ( V_23 )
return V_23 ;
V_39 = F_14 ( V_12 , V_10 ) ;
if ( ! V_39 )
return - V_25 ;
for ( V_37 = 0 ; V_37 < V_12 -> V_41 -> V_42 ; V_37 ++ ) {
if ( V_7 -> V_26 && ! ( V_39 [ V_37 ] . V_43 . V_27 && V_39 [ V_37 ] . V_44 . V_27 ) )
continue;
V_23 = - V_25 ;
V_10 -> V_45 = V_39 [ V_37 ] . V_44 . V_45 ;
V_10 -> V_27 = V_39 [ V_37 ] . V_44 . V_27 ;
V_10 -> V_31 = V_39 [ V_37 ] . V_44 . V_31 ;
V_18 = F_7 ( & V_14 -> V_29 , V_10 , V_16 , & V_39 [ V_37 ] , NULL ,
1 , 1 , 0 ) ;
if ( V_18 ) {
if ( F_8 () ) {
V_40 = V_18 -> V_38 ;
V_23 = F_10 ( & V_40 -> V_43 ,
V_14 -> V_30 ) ;
if ( V_23 )
goto V_32;
V_23 = F_10 ( & V_40 -> V_44 ,
V_14 -> V_30 ) ;
if ( V_23 )
goto V_32;
}
V_14 -> V_29 . V_34 . V_35 += 1 ;
F_11 ( & V_14 -> V_29 , V_36 ) ;
} else
goto V_32;
}
V_23 = 0 ;
V_32:
free ( V_39 ) ;
return V_23 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_13 * V_14 ,
struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
int V_23 = F_5 ( V_12 , & V_16 , V_14 , V_10 , V_7 -> V_24 ) ;
if ( V_23 )
return V_23 ;
V_18 = F_7 ( & V_14 -> V_29 , V_10 , V_16 , NULL , NULL ,
V_12 -> V_46 , V_12 -> V_28 ,
V_12 -> V_47 ) ;
if ( V_18 == NULL )
return - V_25 ;
V_23 = F_12 ( V_18 , V_12 ) ;
if ( V_23 )
goto V_32;
if ( F_8 () )
V_23 = F_9 ( V_18 , V_14 -> V_30 , V_10 -> V_31 ) ;
V_14 -> V_29 . V_34 . V_35 += V_12 -> V_46 ;
F_11 ( & V_14 -> V_29 , V_36 ) ;
V_32:
return V_23 ;
}
static int F_16 ( struct V_48 * V_49 ,
union V_50 * V_51 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_52 * V_52 )
{
struct V_6 * V_7 = F_17 ( V_49 , struct V_6 , V_49 ) ;
struct V_9 V_10 ;
int V_53 ;
if ( F_18 ( V_51 , V_52 , & V_10 , V_12 ) < 0 ) {
F_19 ( L_3 ,
V_51 -> V_54 . type ) ;
return - 1 ;
}
if ( V_7 -> V_26 && V_10 . V_27 == NULL )
return 0 ;
if ( V_7 -> V_55 && ! F_20 ( V_12 -> V_56 , V_7 -> V_57 ) )
return 0 ;
if ( V_58 == V_59 ) {
V_53 = F_13 ( V_7 , & V_10 , V_12 , V_14 ) ;
if ( V_53 < 0 )
F_19 ( L_4 ) ;
} else if ( V_7 -> V_60 == 1 ) {
V_53 = F_4 ( V_7 , & V_10 , V_12 , V_14 ) ;
if ( V_53 < 0 )
F_19 ( L_5 ) ;
} else {
if ( V_10 . V_45 != NULL )
V_10 . V_45 -> V_61 -> V_62 = 1 ;
V_53 = F_15 ( V_7 , V_14 , & V_10 , V_12 ) ;
if ( V_53 < 0 )
F_19 ( L_6 ) ;
}
return V_53 ;
}
static int F_21 ( struct V_48 * V_49 ,
union V_50 * V_51 ,
struct V_11 * V_12 V_63 ,
struct V_13 * V_14 ,
struct V_52 * V_52 V_63 )
{
struct V_6 * V_7 = F_17 ( V_49 , struct V_6 , V_49 ) ;
if ( V_7 -> V_64 ) {
const char * V_65 = V_14 ? F_22 ( V_14 ) : L_7 ;
F_23 ( & V_7 -> V_66 ,
V_51 -> V_67 . V_68 , V_51 -> V_67 . V_69 ,
V_51 -> V_67 . V_70 ,
V_65 ,
V_51 -> V_67 . V_2 ) ;
}
F_24 ( L_8 V_71 L_9 , V_51 -> V_67 . V_68 , V_51 -> V_67 . V_69 ,
V_14 ? F_22 ( V_14 ) : L_10 ,
V_51 -> V_67 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_72 * V_73 = V_7 -> V_73 ;
T_2 V_74 = F_26 ( V_73 -> V_75 ) ;
bool V_76 = F_27 ( V_73 -> V_77 ) ;
if ( ! V_76 && ! ( V_74 & V_78 ) ) {
if ( V_79 ) {
F_28 ( L_11
L_12
L_13 ) ;
return - V_80 ;
}
if ( V_4 . V_81 ) {
F_28 ( L_14
L_15 ) ;
return - 1 ;
}
} else if ( ! V_7 -> V_82 &&
V_83 . V_84 != V_85 &&
! V_4 . V_81 ) {
V_4 . V_81 = true ;
if ( F_29 ( & V_83 ) < 0 ) {
F_28 ( L_16 ) ;
return - V_80 ;
}
}
if ( V_58 == V_59 ) {
if ( ! V_76 &&
! ( V_74 & V_86 ) ) {
F_28 ( L_17
L_18 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_30 ( int T_3 V_63 )
{
V_87 = 1 ;
}
static T_4 F_31 ( struct V_29 * V_29 , struct V_6 * V_7 ,
const char * V_88 , T_5 * V_89 )
{
T_4 V_53 ;
char V_90 ;
unsigned long V_91 = V_29 -> V_34 . V_92 [ V_36 ] ;
T_2 V_92 = V_29 -> V_34 . V_35 ;
struct V_13 * V_14 = F_32 ( V_29 ) ;
char V_93 [ 512 ] ;
T_4 V_94 = sizeof( V_93 ) ;
if ( F_33 ( V_14 ) ) {
struct V_13 * V_95 ;
F_34 ( V_14 , V_93 , V_94 ) ;
V_88 = V_93 ;
F_35 (pos, evsel) {
V_91 += V_95 -> V_29 . V_34 . V_92 [ V_36 ] ;
V_92 += V_95 -> V_29 . V_34 . V_35 ;
}
}
V_91 = F_36 ( V_91 , & V_90 ) ;
V_53 = fprintf ( V_89 , L_19 , V_91 , V_90 ) ;
if ( V_88 != NULL )
V_53 += fprintf ( V_89 , L_20 , V_88 ) ;
if ( V_7 -> V_60 ) {
V_53 += fprintf ( V_89 , L_21 V_71 , V_92 ) ;
V_53 += fprintf ( V_89 , L_22 , V_96 ) ;
} else
V_53 += fprintf ( V_89 , L_23 V_71 , V_92 ) ;
return V_53 + fprintf ( V_89 , L_24 ) ;
}
static int F_37 ( struct V_97 * V_75 ,
struct V_6 * V_7 ,
const char * V_98 )
{
struct V_13 * V_95 ;
F_38 (evlist, pos) {
struct V_29 * V_29 = & V_95 -> V_29 ;
const char * V_88 = F_22 ( V_95 ) ;
if ( V_4 . V_5 &&
! F_39 ( V_95 ) )
continue;
F_31 ( V_29 , V_7 , V_88 , stdout ) ;
F_40 ( V_29 , true , 0 , 0 , V_7 -> V_8 , stdout ) ;
fprintf ( stdout , L_25 ) ;
}
if ( V_96 == V_99 &&
V_100 == V_101 ) {
fprintf ( stdout , L_26 , V_98 ) ;
if ( V_7 -> V_64 ) {
bool V_102 = ! strcmp ( V_7 -> V_103 , L_27 ) ;
F_41 ( stdout , & V_7 -> V_66 ,
V_102 ) ;
F_42 ( & V_7 -> V_66 ) ;
}
}
return 0 ;
}
static void F_43 ( const struct V_6 * V_7 )
{
struct V_45 * V_104 = V_7 -> V_73 -> V_105 . V_106 . V_107 [ V_108 ] ;
struct V_109 * V_110 = F_44 ( V_104 ) ;
if ( V_104 == NULL ||
( V_104 -> V_61 -> V_62 &&
( V_110 -> V_111 == NULL ||
V_110 -> V_111 -> V_31 == 0 ) ) ) {
const char * V_112 =
L_28
L_29 ;
if ( V_104 ) {
const struct V_61 * V_113 = V_104 -> V_61 ;
if ( ! F_45 ( & V_113 -> V_114 [ V_108 ] ) ) {
V_112 = L_30
L_31 ;
}
}
F_46 (
L_32
L_33
L_34 ,
V_112 ) ;
}
}
static int F_47 ( struct V_6 * V_7 , const char * V_98 )
{
int (* F_48)( struct V_97 * V_75 , const char * V_98 ,
struct V_115 * V_116 , float V_117 );
F_48 = F_49 ( V_118 , L_35 ) ;
if ( F_48 == NULL ) {
F_28 ( L_36 ) ;
return - 1 ;
}
return F_48 ( V_7 -> V_73 -> V_75 , V_98 , NULL , V_7 -> V_8 ) ;
}
static int F_50 ( struct V_6 * V_7 )
{
int V_53 ;
struct V_72 * V_73 = V_7 -> V_73 ;
struct V_97 * V_75 = V_73 -> V_75 ;
const char * V_98 = L_37 ;
switch ( V_119 ) {
case 1 :
V_53 = F_51 ( V_75 , V_98 , NULL ,
V_7 -> V_8 ,
& V_73 -> V_54 . V_120 ) ;
if ( V_53 != V_121 )
V_53 = 0 ;
break;
case 2 :
V_53 = F_47 ( V_7 , V_98 ) ;
break;
default:
V_53 = F_37 ( V_75 , V_7 , V_98 ) ;
break;
}
return V_53 ;
}
static T_2 F_52 ( struct V_6 * V_7 )
{
struct V_122 V_123 ;
struct V_13 * V_95 ;
T_2 V_91 = 0 ;
F_38 (rep->session->evlist, pos)
V_91 += V_95 -> V_29 . V_124 ;
F_53 ( & V_123 , V_91 , L_38 ) ;
V_91 = 0 ;
F_38 (rep->session->evlist, pos) {
struct V_29 * V_29 = & V_95 -> V_29 ;
if ( V_95 -> V_30 == 0 )
V_29 -> V_125 = V_7 -> V_125 ;
F_54 ( V_29 , & V_123 ) ;
V_91 += V_29 -> V_34 . V_92 [ V_36 ] ;
if ( V_4 . V_5 &&
! F_39 ( V_95 ) ) {
struct V_29 * V_126 = & V_95 -> V_127 -> V_29 ;
F_55 ( V_126 , V_29 ) ;
F_56 ( V_126 , V_29 ) ;
}
}
F_57 () ;
return V_91 ;
}
static int F_58 ( struct V_6 * V_7 )
{
int V_53 ;
T_2 V_91 ;
struct V_72 * V_73 = V_7 -> V_73 ;
struct V_13 * V_95 ;
struct V_128 * V_77 = V_73 -> V_77 ;
signal ( V_129 , F_30 ) ;
if ( V_7 -> V_55 ) {
V_53 = F_59 ( V_73 , V_7 -> V_55 ,
V_7 -> V_57 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_7 -> V_64 )
F_60 ( & V_7 -> V_66 ) ;
V_53 = F_25 ( V_7 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_61 ( V_73 , & V_7 -> V_49 ) ;
if ( V_53 )
return V_53 ;
F_43 ( V_7 ) ;
if ( V_119 == 0 ) {
if ( V_130 > 3 )
F_62 ( V_73 , stdout ) ;
if ( V_130 > 2 )
F_63 ( V_73 , stdout ) ;
if ( V_131 ) {
F_64 ( V_73 , stdout ) ;
return 0 ;
}
}
V_91 = F_52 ( V_7 ) ;
if ( V_87 () )
return 0 ;
if ( V_91 == 0 ) {
F_28 ( L_39 , V_77 -> V_132 ) ;
return 0 ;
}
F_38 (session->evlist, pos)
F_65 ( & V_95 -> V_29 ) ;
return F_50 ( V_7 ) ;
}
static int
F_66 ( const struct V_133 * V_134 , const char * V_135 , int V_136 )
{
struct V_6 * V_7 = (struct V_6 * ) V_134 -> V_2 ;
char * V_137 , * V_138 ;
char * V_139 ;
if ( V_136 ) {
V_7 -> V_82 = true ;
return 0 ;
}
V_4 . V_81 = true ;
if ( ! V_135 )
return 0 ;
V_137 = strtok ( ( char * ) V_135 , L_40 ) ;
if ( ! V_137 )
return - 1 ;
if ( ! strncmp ( V_137 , L_41 , strlen ( V_135 ) ) )
V_83 . V_84 = V_140 ;
else if ( ! strncmp ( V_137 , L_42 , strlen ( V_135 ) ) )
V_83 . V_84 = V_141 ;
else if ( ! strncmp ( V_137 , L_43 , strlen ( V_135 ) ) )
V_83 . V_84 = V_142 ;
else if ( ! strncmp ( V_137 , L_44 , strlen ( V_135 ) ) ) {
V_83 . V_84 = V_85 ;
V_4 . V_81 = false ;
return 0 ;
}
else
return - 1 ;
V_137 = strtok ( NULL , L_40 ) ;
if ( ! V_137 )
goto V_143;
V_83 . V_8 = strtod ( V_137 , & V_139 ) ;
if ( V_137 == V_139 )
return - 1 ;
V_138 = strtok ( NULL , L_40 ) ;
if ( ! V_138 )
goto V_143;
if ( V_138 [ 0 ] != 'c' ) {
V_83 . V_144 = strtoul ( V_138 , & V_139 , 0 ) ;
V_138 = strtok ( NULL , L_40 ) ;
if ( ! V_138 )
goto V_143;
}
if ( ! strncmp ( V_138 , L_45 , strlen ( L_45 ) ) )
V_83 . V_145 = V_146 ;
else if ( ! strncmp ( V_138 , L_46 , strlen ( L_46 ) ) )
V_83 . V_145 = V_147 ;
else
return - 1 ;
V_138 = strtok ( NULL , L_40 ) ;
if ( ! V_138 )
goto V_143;
if ( ! strncmp ( V_138 , L_47 , strlen ( L_47 ) ) )
V_83 . V_148 = V_149 ;
else if ( ! strncmp ( V_138 , L_48 , strlen ( L_48 ) ) )
V_83 . V_148 = V_150 ;
else
return - 1 ;
V_143:
if ( F_29 ( & V_83 ) < 0 ) {
F_67 ( L_49 ) ;
return - 1 ;
}
return 0 ;
}
int
F_68 ( const struct V_133 * V_134 V_63 ,
const char * V_135 , int V_136 V_63 )
{
if ( V_135 ) {
int V_23 = regcomp ( & V_151 , V_135 , V_152 ) ;
if ( V_23 ) {
char V_93 [ V_153 ] ;
regerror ( V_23 , & V_151 , V_93 , sizeof( V_93 ) ) ;
F_67 ( L_50 , V_135 , V_93 ) ;
return - 1 ;
}
V_154 = 1 ;
}
return 0 ;
}
static int
F_69 ( const struct V_133 * V_134 V_63 ,
const char * T_6 V_63 , int V_136 )
{
int * V_155 = V_134 -> V_2 ;
* V_155 = ! V_136 ;
return 0 ;
}
static int
F_70 ( const struct V_133 * V_134 , const char * T_6 ,
int V_136 V_63 )
{
struct V_6 * V_7 = V_134 -> V_2 ;
V_7 -> V_8 = strtof ( T_6 , NULL ) ;
return 0 ;
}
int F_71 ( int V_156 , const char * * V_157 , const char * T_7 V_63 )
{
struct V_72 * V_73 ;
struct V_158 V_159 ;
bool V_160 = false ;
int V_155 = - 1 ;
int V_53 = - 1 ;
char V_161 [] = L_51 ;
const char * const V_162 [] = {
L_52 ,
NULL
} ;
struct V_6 V_6 = {
. V_49 = {
. V_12 = F_16 ,
. V_163 = V_164 ,
. V_165 = V_166 ,
. V_167 = V_168 ,
. exit = V_169 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_67 = F_21 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. V_178 = V_179 ,
. V_180 = true ,
. V_181 = true ,
} ,
. V_24 = V_182 ,
. V_103 = L_53 ,
} ;
const struct V_133 V_183 [] = {
F_72 ( 'i' , L_54 , & V_184 , L_55 ,
L_56 ) ,
F_73 ( 'v' , L_57 , & V_130 ,
L_58 ) ,
F_74 ( 'D' , L_59 , & V_131 ,
L_60 ) ,
F_72 ( 'k' , L_61 , & V_4 . V_185 ,
L_55 , L_62 ) ,
F_72 ( 0 , L_63 , & V_4 . V_186 ,
L_55 , L_64 ) ,
F_74 ( 'f' , L_65 , & V_6 . V_187 , L_66 ) ,
F_74 ( 'm' , L_67 , & V_4 . V_188 ,
L_68 ) ,
F_74 ( 'n' , L_69 , & V_4 . V_189 ,
L_70 ) ,
F_74 ( 'T' , L_71 , & V_6 . V_64 ,
L_72 ) ,
F_72 ( 0 , L_73 , & V_6 . V_103 , L_74 ,
L_75 ) ,
F_74 ( 0 , L_76 , & V_6 . V_190 , L_77 ) ,
F_74 ( 0 , L_78 , & V_6 . V_191 , L_79 ) ,
F_74 ( 0 , L_80 , & V_6 . V_192 ,
L_81 ) ,
F_74 ( 0 , L_82 , & V_6 . V_54 , L_83 ) ,
F_74 ( 0 , L_84 , & V_6 . V_193 ,
L_85 ) ,
F_72 ( 's' , L_86 , & V_96 , L_87 ,
L_88
L_89
L_90
L_91 ) ,
F_74 ( 0 , L_92 , & V_4 . V_194 ,
L_93 ) ,
F_72 ( 'p' , L_94 , & V_100 , L_95 ,
L_96 ) ,
F_74 ( 'x' , L_97 , & V_4 . V_195 ,
L_98 ) ,
F_75 ( 'g' , L_99 , & V_6 , L_100 ,
L_101
L_102 , & F_66 , V_161 ) ,
F_76 ( 0 , L_103 , & V_6 . V_24 ,
L_104
L_105
L_106 F_77 ( V_182 ) ) ,
F_74 ( 'G' , L_107 , & V_6 . V_196 ,
L_108 ) ,
F_78 ( 0 , L_109 , NULL , L_95 ,
L_110 ,
F_68 ) ,
F_72 ( 'd' , L_111 , & V_4 . V_197 , L_112 ,
L_113 ) ,
F_72 ( 'c' , L_114 , & V_4 . V_198 , L_115 ,
L_116 ) ,
F_72 ( 'S' , L_117 , & V_4 . V_199 , L_118 ,
L_119 ) ,
F_72 ( 0 , L_120 , & V_6 . V_125 , L_121 ,
L_122 ) ,
F_72 ( 'w' , L_123 , & V_4 . V_200 ,
L_124 ,
L_125 ) ,
F_72 ( 't' , L_126 , & V_4 . V_201 , L_127 ,
L_128
L_129 ) ,
F_74 ( 'U' , L_130 , & V_6 . V_26 ,
L_131 ) ,
F_72 ( 0 , L_132 , & V_4 . V_202 , L_133 ,
L_134 ) ,
F_72 ( 'C' , L_135 , & V_6 . V_55 , L_135 ,
L_136 ) ,
F_74 ( 'I' , L_137 , & V_6 . V_203 ,
L_138 ) ,
F_74 ( 0 , L_139 , & V_4 . V_204 ,
L_140 ) ,
F_74 ( 0 , L_141 , & V_4 . V_205 ,
L_142 ) ,
F_72 ( 'M' , L_143 , & V_206 , L_144 ,
L_145 ) ,
F_74 ( 0 , L_146 , & V_4 . V_207 ,
L_147 ) ,
F_74 ( 0 , L_148 , & V_4 . V_5 ,
L_149 ) ,
F_79 ( 'b' , L_150 , & V_155 , L_151 ,
L_152 , F_69 ) ,
F_72 ( 0 , L_153 , & V_208 , L_154 ,
L_155 ) ,
F_74 ( 0 , L_156 , & V_4 . V_209 ,
L_157 ) ,
F_74 ( 0 , L_158 , & V_6 . V_60 , L_159 ) ,
F_78 ( 0 , L_160 , & V_6 , L_161 ,
L_162 , F_70 ) ,
F_80 ()
} ;
struct V_128 V_77 = {
. V_84 = V_210 ,
} ;
F_81 ( F_1 , & V_6 ) ;
V_156 = F_82 ( V_156 , V_157 , V_183 , V_162 , 0 ) ;
if ( V_6 . V_192 )
V_119 = 0 ;
else if ( V_6 . V_190 )
V_119 = 1 ;
else if ( V_6 . V_191 )
V_119 = 2 ;
if ( V_6 . V_196 )
V_83 . V_145 = V_146 ;
if ( ! V_184 || ! strlen ( V_184 ) ) {
if ( ! F_83 ( V_211 , & V_159 ) && F_84 ( V_159 . V_212 ) )
V_184 = L_163 ;
else
V_184 = L_164 ;
}
V_77 . V_132 = V_184 ;
V_77 . V_187 = V_6 . V_187 ;
V_213:
V_73 = F_85 ( & V_77 , false , & V_6 . V_49 ) ;
if ( V_73 == NULL )
return - V_25 ;
V_6 . V_73 = V_73 ;
V_160 = F_86 ( & V_73 -> V_54 ,
V_214 ) ;
if ( V_155 == - 1 && V_160 )
V_58 = V_59 ;
if ( V_58 == V_59 ) {
if ( V_96 == V_99 )
V_96 = L_165
L_166 ;
}
if ( V_6 . V_60 ) {
if ( V_58 == V_59 ) {
F_67 ( L_167 ) ;
goto error;
}
V_58 = V_215 ;
if ( V_96 == V_99 )
V_96 = L_168 ;
}
if ( F_87 () < 0 ) {
F_88 ( V_162 , V_183 , L_169 , 1 ) ;
goto error;
}
if ( V_100 != V_101 ) {
if ( F_89 ( L_94 ) < 0 )
goto error;
}
if ( V_6 . V_54 || V_6 . V_193 )
V_119 = 0 ;
if ( strcmp ( V_184 , L_163 ) != 0 )
F_90 ( true ) ;
else {
V_119 = 0 ;
F_91 () ;
}
if ( V_6 . V_54 || V_6 . V_193 ) {
F_92 ( V_73 , stdout ,
V_6 . V_203 ) ;
if ( V_6 . V_193 )
return 0 ;
} else if ( V_119 == 0 ) {
fputs ( L_170 ,
stdout ) ;
}
if ( F_8 () ) {
V_4 . V_216 = sizeof( struct V_217 ) ;
F_93 ( & V_73 -> V_105 ,
V_218 ) ;
if ( V_130 ) {
V_4 . V_216 += sizeof( V_219 ) ;
V_4 . V_220 = true ;
}
}
if ( F_94 () < 0 )
goto error;
if ( V_156 ) {
if ( V_156 > 1 )
F_95 ( V_162 , V_183 ) ;
V_6 . V_125 = V_157 [ 0 ] ;
}
F_96 ( stdout ) ;
V_53 = F_58 ( & V_6 ) ;
if ( V_53 == V_121 ) {
F_97 ( V_73 ) ;
goto V_213;
} else
V_53 = 0 ;
error:
F_97 ( V_73 ) ;
return V_53 ;
}
