static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 . V_5 - V_6 ;
}
static void F_2 ( int T_1 V_7 ,
T_2 * T_3 V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
F_3 ( & V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_15 ;
int V_16 = - 1 ;
if ( ! V_10 || ! V_10 -> V_17 . V_12 )
return - 1 ;
V_12 = V_10 -> V_17 . V_12 ;
V_15 = V_10 -> V_17 . V_15 ;
if ( V_15 -> V_18 -> V_19 == V_20 &&
! F_5 ( V_15 -> V_18 ) ) {
F_6 ( L_1
L_2 , V_12 -> V_21 ) ;
F_7 ( 1 ) ;
return - 1 ;
}
V_14 = F_8 ( V_12 ) ;
if ( V_14 -> V_22 != NULL ) {
F_9 ( & V_14 -> V_23 ) ;
goto V_24;
}
F_9 ( & V_14 -> V_23 ) ;
if ( F_10 ( V_12 ) < 0 ) {
F_11 ( & V_14 -> V_23 ) ;
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
return V_16 ;
}
V_16 = F_12 ( V_12 , V_15 , 0 ) ;
if ( V_16 == 0 ) {
V_24:
V_2 -> V_25 = V_10 ;
}
F_11 ( & V_14 -> V_23 ) ;
return V_16 ;
}
static void F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
F_14 ( V_12 ) ;
}
static void F_15 ( struct V_15 * V_15 , struct V_11 * V_12 , T_4 V_26 )
{
struct V_27 V_28 ;
int V_16 = F_16 ( & V_28 ) ;
F_17 ( L_4
L_5 V_29 L_6
L_7
L_8 V_29 L_9 V_29 L_6
L_10 V_29 L_9 V_29 L_11
L_12
L_13
L_14
L_15
L_16 ,
V_26 , V_15 -> V_18 -> V_30 , F_18 ( V_15 -> V_18 ) ,
V_15 -> V_31 , V_15 -> V_32 , V_12 -> V_31 , V_12 -> V_32 ,
V_12 -> V_33 == V_34 ? 'g' :
V_12 -> V_33 == V_35 ? 'l' : 'w' , V_12 -> V_21 ,
V_16 ? L_17 : V_28 . V_36 ,
V_16 ? L_17 : V_28 . V_37 , V_38 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_15 -> V_40 = true ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_41 , T_4 V_26 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int V_16 = 0 ;
if ( V_10 == NULL || V_10 -> V_17 . V_12 == NULL ||
( ( V_2 -> V_25 == NULL ||
V_2 -> V_25 -> V_17 . V_12 != V_10 -> V_17 . V_12 ) && V_39 != 1 ) )
return;
V_12 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( F_20 ( & V_14 -> V_23 ) )
return;
V_26 = V_10 -> V_17 . V_15 -> V_42 ( V_10 -> V_17 . V_15 , V_26 ) ;
if ( F_21 () )
V_16 = F_22 ( V_10 , V_41 , V_26 ) ;
F_11 ( & V_14 -> V_23 ) ;
F_11 ( & V_10 -> V_43 -> V_23 ) ;
if ( V_16 == - V_44 && ! V_10 -> V_17 . V_15 -> V_40 )
F_15 ( V_10 -> V_17 . V_15 , V_12 , V_26 ) ;
else if ( V_16 == - V_45 ) {
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
}
F_9 ( & V_10 -> V_43 -> V_23 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_46 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_47;
printf ( L_18 , F_24 ( V_2 -> V_48 ) , V_11 -> V_21 ) ;
printf ( L_19 , V_2 -> V_49 ) ;
V_46 = F_25 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_48 ,
0 , V_2 -> V_49 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_50 -> V_51 ) {
if ( V_2 -> V_52 )
F_26 ( V_11 , V_2 -> V_48 -> V_53 ) ;
else
F_27 ( V_11 , V_2 -> V_48 -> V_53 ) ;
}
if ( V_46 != 0 )
printf ( L_20 , V_46 ) ;
V_47:
F_11 ( & V_14 -> V_23 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
char V_54 [ 160 ] ;
int V_55 = 0 ;
const int V_56 = V_2 -> V_4 . V_57 - 1 ;
struct V_43 * V_43 = F_29 ( V_2 -> V_48 ) ;
puts ( V_58 ) ;
F_30 ( V_2 , V_54 , sizeof( V_54 ) ) ;
printf ( L_21 , V_54 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_56 , V_56 , V_59 ) ;
if ( V_43 -> V_60 . V_61 !=
V_43 -> V_60 . V_62 [ V_63 ] ) {
V_43 -> V_60 . V_61 =
V_43 -> V_60 . V_62 [ V_63 ] ;
F_32 ( stdout , V_64 ,
L_23 ,
V_43 -> V_60 . V_61 ) ;
++ V_55 ;
}
if ( V_2 -> V_25 ) {
F_23 ( V_2 ) ;
return;
}
if ( V_2 -> V_50 -> V_51 ) {
if ( V_2 -> V_52 ) {
F_33 ( V_43 ) ;
} else {
F_34 ( V_43 , V_2 -> V_65 ,
V_2 -> V_66 ) ;
}
}
F_35 ( V_43 , NULL ) ;
F_36 ( V_43 , NULL ) ;
F_37 ( V_43 , V_2 -> V_3 - V_55 ) ;
putchar ( '\n' ) ;
F_38 ( V_43 , false , V_2 -> V_3 - V_55 , V_56 ,
V_2 -> V_67 , stdout ) ;
}
static void F_39 ( int * V_68 , const char * V_69 )
{
char * V_70 = malloc ( 0 ) , * V_71 ;
T_5 V_72 = 0 ;
int V_73 ;
fprintf ( stdout , L_24 , V_69 ) ;
if ( F_40 ( & V_70 , & V_72 , V_74 ) < 0 )
return;
V_71 = strchr ( V_70 , '\n' ) ;
if ( V_71 )
* V_71 = 0 ;
V_71 = V_70 ;
while( * V_71 ) {
if ( ! isdigit ( * V_71 ) )
goto V_75;
V_71 ++ ;
}
V_73 = strtoul ( V_70 , NULL , 10 ) ;
* V_68 = V_73 ;
V_75:
free ( V_70 ) ;
}
static void F_41 ( int * V_68 , const char * V_69 )
{
int V_73 = 0 ;
F_39 ( & V_73 , V_69 ) ;
if ( V_73 >= 0 && V_73 <= 100 )
* V_68 = V_73 ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_69 )
{
char * V_70 = malloc ( 0 ) , * V_71 ;
struct V_9 * V_76 = V_2 -> V_25 , * V_77 , * V_78 = NULL ;
struct V_43 * V_43 = F_29 ( V_2 -> V_48 ) ;
struct V_79 * V_80 ;
T_5 V_72 = 0 ;
if ( V_76 ) {
F_13 ( V_76 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_69 ) ;
if ( F_40 ( & V_70 , & V_72 , V_74 ) < 0 )
goto V_75;
V_71 = strchr ( V_70 , '\n' ) ;
if ( V_71 )
* V_71 = 0 ;
V_80 = F_43 ( & V_43 -> V_81 ) ;
while ( V_80 ) {
V_77 = F_44 ( V_80 , struct V_9 , V_79 ) ;
if ( V_77 -> V_17 . V_12 && ! strcmp ( V_70 , V_77 -> V_17 . V_12 -> V_21 ) ) {
V_78 = V_77 ;
break;
}
V_80 = F_45 ( & V_77 -> V_79 ) ;
}
if ( ! V_78 ) {
fprintf ( V_82 , L_25 , V_70 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_78 ) ;
V_75:
free ( V_70 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_83 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_50 -> V_84 > 1 )
fprintf ( stdout , L_29 , F_24 ( V_2 -> V_48 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_85 ) ;
fprintf ( stdout , L_31 , V_2 -> V_49 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_66 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_65 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_52 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_86 )
{
switch ( V_86 ) {
case 'd' :
case 'e' :
case 'f' :
case 'z' :
case 'q' :
case 'Q' :
case 'K' :
case 'U' :
case 'F' :
case 's' :
case 'S' :
return 1 ;
case 'E' :
return V_2 -> V_50 -> V_84 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_48 ( struct V_1 * V_2 , int V_86 )
{
bool V_87 = true ;
if ( ! F_47 ( V_2 , V_86 ) ) {
struct V_88 V_89 = { . V_90 = 0 , . V_91 = V_92 } ;
struct V_93 V_94 ;
F_46 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_49 ( & V_94 ) ;
F_50 ( & V_89 , 1 , - 1 ) ;
V_86 = getc ( V_74 ) ;
F_51 ( 0 , V_95 , & V_94 ) ;
if ( ! F_47 ( V_2 , V_86 ) )
return V_87 ;
}
switch ( V_86 ) {
case 'd' :
F_39 ( & V_2 -> V_83 , L_42 ) ;
if ( V_2 -> V_83 < 1 )
V_2 -> V_83 = 1 ;
break;
case 'e' :
F_39 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_96 V_97 = {
. V_98 = F_2 ,
. V_99 = V_100 ,
} ;
F_2 ( V_101 , NULL , V_2 ) ;
V_96 ( V_101 , & V_97 , NULL ) ;
} else {
signal ( V_101 , V_102 ) ;
}
break;
case 'E' :
if ( V_2 -> V_50 -> V_84 > 1 ) {
int V_41 = 0 ;
fprintf ( V_82 , L_44 ) ;
F_52 (top->evlist, top->sym_evsel)
fprintf ( V_82 , L_45 , V_2 -> V_48 -> V_53 , F_24 ( V_2 -> V_48 ) ) ;
F_39 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_50 -> V_84 ) {
V_2 -> V_48 = F_53 ( V_2 -> V_50 ) ;
fprintf ( V_82 , L_47 , F_24 ( V_2 -> V_48 ) ) ;
F_7 ( 1 ) ;
break;
}
F_52 (top->evlist, top->sym_evsel)
if ( V_2 -> V_48 -> V_53 == V_41 )
break;
} else
V_2 -> V_48 = F_53 ( V_2 -> V_50 ) ;
break;
case 'f' :
F_39 ( & V_2 -> V_85 , L_48 ) ;
break;
case 'F' :
F_41 ( & V_2 -> V_49 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_66 = ! V_2 -> V_66 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_103 )
F_54 ( V_2 -> V_104 , V_82 ) ;
V_87 = false ;
break;
case 's' :
F_42 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_76 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_76 ) ;
}
break;
case 'U' :
V_2 -> V_65 = ! V_2 -> V_65 ;
break;
case 'z' :
V_2 -> V_52 = ! V_2 -> V_52 ;
break;
default:
break;
}
return V_87 ;
}
static void F_55 ( void * V_8 )
{
struct V_1 * V_105 = V_8 ;
struct V_43 * V_43 ;
F_31 ( V_105 ) ;
if ( V_105 -> V_50 -> V_106 != NULL )
V_105 -> V_48 = V_105 -> V_50 -> V_106 ;
V_43 = F_29 ( V_105 -> V_48 ) ;
if ( V_105 -> V_50 -> V_51 ) {
if ( V_105 -> V_52 ) {
F_33 ( V_43 ) ;
} else {
F_34 ( V_43 , V_105 -> V_65 ,
V_105 -> V_66 ) ;
}
}
F_35 ( V_43 , NULL ) ;
F_36 ( V_43 , NULL ) ;
}
static void * F_56 ( void * V_8 )
{
struct V_107 * V_108 ;
struct V_1 * V_2 = V_8 ;
const char * V_109 = L_52 ;
struct V_110 V_111 = {
. V_112 = F_55 ,
. V_8 = V_2 ,
. V_113 = V_2 -> V_83 ,
} ;
F_55 ( V_2 ) ;
F_52 (top->evlist, pos) {
struct V_43 * V_43 = F_29 ( V_108 ) ;
V_43 -> V_114 = V_2 -> V_115 . V_68 . V_116 ;
}
F_57 ( V_2 -> V_50 , V_109 , & V_111 ,
V_2 -> V_67 ,
& V_2 -> V_104 -> V_117 . V_118 ) ;
V_119 = 1 ;
return NULL ;
}
static void F_58 ( int T_1 V_7 )
{
V_119 = 1 ;
}
static void F_59 ( void )
{
signal ( V_120 , V_121 ) ;
signal ( V_122 , V_121 ) ;
signal ( V_123 , F_58 ) ;
signal ( V_124 , F_58 ) ;
signal ( V_125 , F_58 ) ;
}
static void * F_60 ( void * V_8 )
{
struct V_88 V_89 = { . V_90 = 0 , . V_91 = V_92 } ;
struct V_93 V_94 ;
struct V_1 * V_2 = V_8 ;
int V_126 , V_86 ;
F_59 () ;
F_61 () ;
V_127:
V_126 = V_2 -> V_83 * 1000 ;
F_49 ( & V_94 ) ;
getc ( V_74 ) ;
while ( ! V_119 ) {
F_28 ( V_2 ) ;
switch ( F_50 ( & V_89 , 1 , V_126 ) ) {
case 0 :
continue;
case - 1 :
if ( V_128 == V_129 )
continue;
default:
V_86 = getc ( V_74 ) ;
F_51 ( 0 , V_95 , & V_94 ) ;
if ( F_48 ( V_2 , V_86 ) )
goto V_127;
V_119 = 1 ;
}
}
F_51 ( 0 , V_95 , & V_94 ) ;
return NULL ;
}
static int F_62 ( struct V_15 * V_15 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
if ( ! V_15 -> V_18 -> V_130 )
return 0 ;
if ( V_21 [ 0 ] == '.' )
V_21 ++ ;
if ( ! strcmp ( V_21 , L_53 ) ||
! strcmp ( V_21 , L_54 ) ||
! strcmp ( V_21 , L_55 ) ||
! strncmp ( L_56 , V_21 , 11 ) ||
! strncmp ( L_57 , V_21 , 14 ) ||
strstr ( V_21 , L_58 ) ||
strstr ( V_21 , L_59 ) )
return 1 ;
if ( F_63 ( V_12 ) )
V_12 -> V_131 = true ;
return 0 ;
}
static int F_64 ( struct V_132 * V_133 ,
struct V_134 * V_135 , bool V_136 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_133 -> V_10 ;
struct V_107 * V_137 = V_133 -> V_137 ;
if ( V_138 && V_136 ) {
T_4 V_26 = V_135 -> V_139 ;
if ( V_135 -> V_15 )
V_26 = V_135 -> V_15 -> V_140 ( V_135 -> V_15 , V_26 ) ;
F_19 ( V_2 , V_10 , V_137 -> V_53 , V_26 ) ;
}
F_65 ( V_133 -> V_141 -> V_142 , V_135 , V_133 -> V_141 ,
! ( V_2 -> V_115 . V_142 & V_143 ) ) ;
return 0 ;
}
static void F_66 ( struct V_144 * V_145 ,
const union V_146 * V_147 ,
struct V_107 * V_137 ,
struct V_148 * V_141 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_67 ( V_145 , struct V_1 , V_145 ) ;
struct V_134 V_135 ;
int V_16 ;
if ( ! V_36 && V_149 ) {
static struct V_150 * V_151 ;
if ( ! V_151 )
V_151 = F_68 ( NULL ) ;
if ( ! F_69 ( V_151 , V_141 -> V_152 ) ) {
F_6 ( L_60 ,
V_141 -> V_152 ) ;
F_70 ( V_151 , V_141 -> V_152 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_104 -> V_50 -> V_60 . V_153 ++ ) ;
return;
}
if ( V_147 -> V_117 . V_154 & V_155 )
V_2 -> V_156 ++ ;
if ( F_71 ( V_147 , V_36 , & V_135 , V_141 ) < 0 )
return;
if ( ! V_2 -> V_157 &&
V_158 . V_159 &&
V_135 . V_160 == V_161 ) {
F_17 (
L_62
L_63
L_64 ,
V_135 . V_15 && ! F_72 ( & V_135 . V_15 -> V_18 -> V_162 [ V_163 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_157 = true ;
}
if ( V_135 . V_12 == NULL ) {
const char * V_69 = L_67 ;
if ( ! V_2 -> V_157 && ! V_2 -> V_164 &&
V_135 . V_15 == V_36 -> V_165 [ V_163 ] &&
F_72 ( & V_135 . V_15 -> V_18 -> V_162 [ V_163 ] ) ) {
if ( V_158 . V_166 ) {
char V_167 [ 256 ] ;
F_73 ( V_135 . V_15 -> V_18 , V_167 , sizeof( V_167 ) ) ;
F_17 ( L_68 ,
V_158 . V_166 , V_167 , V_69 ) ;
} else {
F_17 ( L_69 ,
V_69 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_164 = true ;
}
}
if ( V_135 . V_12 == NULL || ! V_135 . V_12 -> V_131 ) {
struct V_43 * V_43 = F_29 ( V_137 ) ;
struct V_132 V_133 = {
. V_137 = V_137 ,
. V_141 = V_141 ,
. V_168 = F_64 ,
} ;
if ( V_158 . V_169 )
V_133 . V_170 = & V_171 ;
else
V_133 . V_170 = & V_172 ;
F_9 ( & V_43 -> V_23 ) ;
V_16 = F_74 ( & V_133 , & V_135 , V_2 -> V_173 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_43 -> V_23 ) ;
}
F_75 ( & V_135 ) ;
}
static void F_76 ( struct V_1 * V_2 , int V_53 )
{
struct V_148 V_141 ;
struct V_107 * V_137 ;
struct V_174 * V_104 = V_2 -> V_104 ;
union V_146 * V_147 ;
struct V_36 * V_36 ;
T_6 V_175 ;
int V_87 ;
while ( ( V_147 = F_77 ( V_2 -> V_50 , V_53 ) ) != NULL ) {
V_87 = F_78 ( V_2 -> V_50 , V_147 , & V_141 ) ;
if ( V_87 ) {
F_6 ( L_71 , V_87 ) ;
goto V_176;
}
V_137 = F_79 ( V_104 -> V_50 , V_141 . V_177 ) ;
assert ( V_137 != NULL ) ;
V_175 = V_147 -> V_117 . V_154 & V_178 ;
if ( V_147 -> V_117 . type == V_179 )
++ V_2 -> V_180 ;
switch ( V_175 ) {
case V_181 :
++ V_2 -> V_182 ;
if ( V_2 -> V_65 )
goto V_176;
V_36 = & V_104 -> V_183 . V_184 ;
break;
case V_161 :
++ V_2 -> V_185 ;
if ( V_2 -> V_66 )
goto V_176;
V_36 = & V_104 -> V_183 . V_184 ;
break;
case V_186 :
++ V_2 -> V_187 ;
V_36 = F_80 ( V_104 ,
V_141 . V_152 ) ;
break;
case V_188 :
++ V_2 -> V_189 ;
default:
goto V_176;
}
if ( V_147 -> V_117 . type == V_179 ) {
F_66 ( & V_2 -> V_145 , V_147 , V_137 ,
& V_141 , V_36 ) ;
} else if ( V_147 -> V_117 . type < V_190 ) {
F_81 ( F_29 ( V_137 ) , V_147 -> V_117 . type ) ;
F_82 ( V_36 , V_147 , & V_141 ) ;
} else
++ V_104 -> V_50 -> V_60 . V_191 ;
V_176:
F_83 ( V_2 -> V_50 , V_53 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_50 -> V_193 ; V_192 ++ )
F_76 ( V_2 , V_192 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
char V_69 [ 512 ] ;
struct V_107 * V_41 ;
struct V_194 * V_50 = V_2 -> V_50 ;
struct V_115 * V_195 = & V_2 -> V_115 ;
F_86 ( V_50 , V_195 ) ;
F_52 (evlist, counter) {
V_196:
if ( F_87 ( V_41 , V_2 -> V_50 -> V_197 ,
V_2 -> V_50 -> V_198 ) < 0 ) {
if ( F_88 ( V_41 , V_128 , V_69 , sizeof( V_69 ) ) ) {
if ( V_199 )
F_17 ( L_21 , V_69 ) ;
goto V_196;
}
F_89 ( V_41 , & V_195 -> V_68 ,
V_128 , V_69 , sizeof( V_69 ) ) ;
F_90 ( L_21 , V_69 ) ;
goto V_200;
}
}
if ( F_91 ( V_50 , V_195 -> V_201 , false ) < 0 ) {
F_90 ( L_72 ,
V_128 , F_92 ( V_128 , V_69 , sizeof( V_69 ) ) ) ;
goto V_200;
}
return 0 ;
V_200:
return - 1 ;
}
static int F_93 ( struct V_1 * V_2 V_7 )
{
if ( ! V_138 ) {
if ( V_158 . V_202 ) {
F_90 ( L_73 ) ;
return - V_203 ;
}
} else if ( V_204 . V_205 != V_206 ) {
if ( F_94 ( & V_204 ) < 0 ) {
F_90 ( L_74 ) ;
return - V_203 ;
}
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_115 * V_195 = & V_2 -> V_115 ;
T_7 V_207 ;
int V_87 ;
V_2 -> V_104 = F_96 ( NULL , false , NULL ) ;
if ( V_2 -> V_104 == NULL )
return - 1 ;
F_97 ( & V_2 -> V_104 -> V_183 , F_62 ) ;
if ( ! V_208 ) {
V_87 = F_98 ( & V_2 -> V_104 -> V_117 . V_118 ) ;
if ( V_87 )
goto V_209;
}
V_87 = F_93 ( V_2 ) ;
if ( V_87 )
goto V_209;
F_99 ( & V_2 -> V_104 -> V_183 . V_184 , & V_195 -> V_68 ,
V_2 -> V_50 -> V_198 , false , V_195 -> V_210 ) ;
V_87 = F_85 ( V_2 ) ;
if ( V_87 )
goto V_209;
V_2 -> V_104 -> V_50 = V_2 -> V_50 ;
F_100 ( V_2 -> V_104 ) ;
if ( ! F_101 ( & V_195 -> V_68 ) )
F_102 ( V_2 -> V_50 ) ;
F_103 ( V_2 -> V_50 , 100 ) ;
F_84 ( V_2 ) ;
V_87 = - 1 ;
if ( F_104 ( & V_207 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_90 ( L_75 ) ;
goto V_209;
}
if ( V_2 -> V_211 ) {
struct V_212 V_213 ;
V_213 . V_214 = V_2 -> V_211 ;
if ( F_105 ( 0 , V_215 , & V_213 ) ) {
F_90 ( L_76 ) ;
goto V_216;
}
}
while ( ! V_119 ) {
T_4 V_217 = V_2 -> V_180 ;
F_84 ( V_2 ) ;
if ( V_217 == V_2 -> V_180 )
V_87 = F_103 ( V_2 -> V_50 , 100 ) ;
}
V_87 = 0 ;
V_216:
F_106 ( V_207 , NULL ) ;
V_209:
F_107 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
return V_87 ;
}
static int
F_108 ( const struct V_218 * V_219 , const char * V_8 , int V_220 )
{
V_158 . V_202 = true ;
return F_109 ( V_219 , V_8 , V_220 ) ;
}
static int
F_110 ( const struct V_218 * V_219 , const char * V_8 , int V_220 )
{
V_158 . V_202 = true ;
return F_111 ( V_219 , V_8 , V_220 ) ;
}
static int F_112 ( const char * V_221 , const char * V_222 , void * V_223 )
{
if ( ! strcmp ( V_221 , L_77 ) )
V_221 = L_78 ;
if ( ! strcmp ( V_221 , L_79 ) ) {
V_158 . V_169 = F_113 ( V_221 , V_222 ) ;
return 0 ;
}
return F_114 ( V_221 , V_222 , V_223 ) ;
}
static int
F_115 ( const struct V_218 * V_219 , const char * V_8 ,
int V_220 V_7 )
{
struct V_1 * V_2 = V_219 -> V_222 ;
V_2 -> V_67 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_116 ( int V_224 , const char * * V_225 , const char * T_8 V_7 )
{
char V_226 [ V_227 ] ;
struct V_1 V_2 = {
. V_85 = 5 ,
. V_83 = 2 ,
. V_115 = {
. V_201 = V_228 ,
. V_229 = V_228 ,
. V_230 = V_231 ,
. V_232 = 4000 ,
. V_68 = {
. V_233 = true ,
} ,
. V_210 = 500 ,
} ,
. V_173 = V_234 ,
. V_49 = 5 ,
} ;
struct V_115 * V_195 = & V_2 . V_115 ;
struct V_68 * V_68 = & V_195 -> V_68 ;
const struct V_218 V_235 [] = {
F_117 ( 'e' , L_80 , & V_2 . V_50 , L_80 ,
L_81 ,
V_236 ) ,
F_118 ( 'c' , L_82 , & V_195 -> V_230 , L_83 ) ,
F_119 ( 'p' , L_84 , & V_68 -> V_152 , L_84 ,
L_85 ) ,
F_119 ( 't' , L_86 , & V_68 -> V_237 , L_86 ,
L_87 ) ,
F_120 ( 'a' , L_88 , & V_68 -> V_238 ,
L_89 ) ,
F_119 ( 'C' , L_90 , & V_68 -> V_239 , L_90 ,
L_91 ) ,
F_119 ( 'k' , L_92 , & V_158 . V_166 ,
L_93 , L_94 ) ,
F_120 ( 0 , L_95 , & V_158 . V_240 ,
L_96 ) ,
F_120 ( 'K' , L_97 , & V_2 . V_66 ,
L_98 ) ,
F_117 ( 'm' , L_99 , & V_195 -> V_201 , L_100 ,
L_101 ,
V_241 ) ,
F_121 ( 'r' , L_102 , & V_2 . V_211 ,
L_103 ) ,
F_121 ( 'd' , L_104 , & V_2 . V_83 ,
L_105 ) ,
F_120 ( 'D' , L_106 , & V_2 . V_103 ,
L_107 ) ,
F_121 ( 'f' , L_108 , & V_2 . V_85 ,
L_109 ) ,
F_120 ( 0 , L_110 , & V_195 -> V_242 ,
L_111 ) ,
F_120 ( 'i' , L_112 , & V_195 -> V_243 ,
L_113 ) ,
F_119 ( 0 , L_114 , & V_2 . V_244 , L_115 ,
L_116 ) ,
F_120 ( 'z' , L_117 , & V_2 . V_52 , L_118 ) ,
F_122 ( 'F' , L_119 , & V_195 -> V_229 , L_120 ) ,
F_121 ( 'E' , L_121 , & V_2 . V_3 ,
L_122 ) ,
F_120 ( 'U' , L_123 , & V_2 . V_65 ,
L_124 ) ,
F_120 ( 0 , L_125 , & V_2 . V_245 , L_126 ) ,
F_120 ( 0 , L_127 , & V_2 . V_246 , L_128 ) ,
F_123 ( 'v' , L_129 , & V_199 ,
L_130 ) ,
F_119 ( 's' , L_131 , & V_247 , L_132 ,
L_133
L_134 ) ,
F_119 ( 0 , L_135 , & V_248 , L_136 ,
L_137 ) ,
F_120 ( 'n' , L_138 , & V_158 . V_249 ,
L_139 ) ,
F_124 ( 'g' , NULL , & V_2 . V_115 ,
NULL , L_140 ,
& F_108 ) ,
F_117 ( 0 , L_141 , & V_2 . V_115 ,
L_142 , V_250 ,
& F_110 ) ,
F_120 ( 0 , L_143 , & V_158 . V_169 ,
L_144 ) ,
F_121 ( 0 , L_145 , & V_2 . V_173 ,
L_146
L_147 F_125 ( V_234 ) ) ,
F_117 ( 0 , L_148 , NULL , L_149 ,
L_150 ,
V_251 ) ,
F_120 ( 0 , L_151 , & V_158 . V_252 ,
L_152 ) ,
F_119 ( 0 , L_153 , & V_158 . V_253 , L_154 ,
L_155 ) ,
F_119 ( 0 , L_156 , & V_158 . V_254 , L_157 ,
L_158 ) ,
F_119 ( 0 , L_159 , & V_158 . V_255 , L_160 ,
L_161 ) ,
F_120 ( 0 , L_162 , & V_158 . V_256 ,
L_163 ) ,
F_120 ( 0 , L_164 , & V_158 . V_257 ,
L_165 ) ,
F_120 ( 0 , L_166 , & V_158 . V_258 ,
L_167 ) ,
F_119 ( 0 , L_168 , & V_208 , L_169 ,
L_170 ) ,
F_119 ( 'M' , L_171 , & V_259 , L_172 ,
L_173 ) ,
F_119 ( 'u' , L_174 , & V_68 -> V_116 , L_175 , L_176 ) ,
F_117 ( 0 , L_177 , & V_2 , L_178 ,
L_179 , F_115 ) ,
F_117 ( 0 , L_180 , NULL , L_181 ,
L_182 , V_260 ) ,
F_119 ( 'w' , L_183 , & V_158 . V_261 ,
L_184 ,
L_185 ) ,
F_122 ( 0 , L_186 , & V_195 -> V_210 ,
L_187 ) ,
F_124 ( 'b' , L_188 , & V_195 -> V_142 ,
L_189 , L_190 ,
V_262 ) ,
F_117 ( 'j' , L_191 , & V_195 -> V_142 ,
L_192 , L_193 ,
V_262 ) ,
F_126 ()
} ;
const char * const V_263 [] = {
L_194 ,
NULL
} ;
int V_264 = F_127 () ;
if ( V_264 < 0 )
return V_264 ;
V_2 . V_50 = F_128 () ;
if ( V_2 . V_50 == NULL )
return - V_45 ;
F_129 ( F_112 , & V_2 ) ;
V_224 = F_130 ( V_224 , V_225 , V_235 , V_263 , 0 ) ;
if ( V_224 )
F_131 ( V_263 , V_235 ) ;
V_265 = V_266 ;
V_267 = 1 ;
if ( F_132 () < 0 ) {
if ( V_247 )
F_133 ( V_263 , V_235 , L_195 , 1 ) ;
if ( V_248 )
F_133 ( V_247 ? NULL : V_263 ,
V_235 , L_135 , 0 ) ;
goto V_268;
}
if ( V_2 . V_246 )
V_39 = 0 ;
else if ( V_2 . V_245 )
V_39 = 1 ;
F_134 ( false ) ;
V_264 = F_135 ( V_68 ) ;
if ( V_264 ) {
F_136 ( V_68 , V_264 , V_226 , V_227 ) ;
F_17 ( L_21 , V_226 ) ;
}
V_264 = F_137 ( V_68 ) ;
if ( V_264 ) {
int V_269 = V_128 ;
F_136 ( V_68 , V_264 , V_226 , V_227 ) ;
F_90 ( L_21 , V_226 ) ;
V_264 = - V_269 ;
goto V_268;
}
if ( F_101 ( V_68 ) )
V_68 -> V_238 = true ;
if ( F_138 ( V_2 . V_50 , V_68 ) < 0 )
F_131 ( V_263 , V_235 ) ;
if ( ! V_2 . V_50 -> V_84 &&
F_139 ( V_2 . V_50 ) < 0 ) {
F_90 ( L_196 ) ;
goto V_268;
}
V_158 . V_62 = V_2 . V_50 -> V_84 ;
if ( V_2 . V_83 < 1 )
V_2 . V_83 = 1 ;
if ( F_140 ( V_195 ) ) {
V_264 = - V_203 ;
goto V_268;
}
V_2 . V_48 = F_53 ( V_2 . V_50 ) ;
if ( ! V_158 . V_202 ) {
V_158 . V_169 = false ;
F_141 () ;
}
V_158 . V_270 = sizeof( struct V_13 ) ;
V_158 . V_271 = ( V_158 . V_166 == NULL ) ;
if ( F_142 ( NULL ) < 0 )
return - 1 ;
F_143 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_96 V_97 = {
. V_98 = F_2 ,
. V_99 = V_100 ,
} ;
F_1 ( & V_2 ) ;
V_96 ( V_101 , & V_97 , NULL ) ;
}
V_264 = F_95 ( & V_2 ) ;
V_268:
F_144 ( V_2 . V_50 ) ;
return V_264 ;
}
