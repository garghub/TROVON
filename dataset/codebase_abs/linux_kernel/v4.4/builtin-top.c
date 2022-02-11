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
if ( ! F_63 ( V_15 ) )
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
if ( F_64 ( V_12 ) )
V_12 -> V_130 = true ;
return 0 ;
}
static int F_65 ( struct V_131 * V_132 ,
struct V_133 * V_134 , bool V_135 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_132 -> V_10 ;
struct V_107 * V_136 = V_132 -> V_136 ;
if ( V_137 && V_135 ) {
T_4 V_26 = V_134 -> V_138 ;
if ( V_134 -> V_15 )
V_26 = V_134 -> V_15 -> V_139 ( V_134 -> V_15 , V_26 ) ;
F_19 ( V_2 , V_10 , V_136 -> V_53 , V_26 ) ;
}
F_66 ( V_132 -> V_140 -> V_141 , V_134 , V_132 -> V_140 ,
! ( V_2 -> V_115 . V_141 & V_142 ) ) ;
return 0 ;
}
static void F_67 ( struct V_143 * V_144 ,
const union V_145 * V_146 ,
struct V_107 * V_136 ,
struct V_147 * V_140 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_68 ( V_144 , struct V_1 , V_144 ) ;
struct V_133 V_134 ;
int V_16 ;
if ( ! V_36 && V_148 ) {
static struct V_149 * V_150 ;
if ( ! V_150 )
V_150 = F_69 ( NULL ) ;
if ( ! F_70 ( V_150 , V_140 -> V_151 ) ) {
F_6 ( L_60 ,
V_140 -> V_151 ) ;
F_71 ( V_150 , V_140 -> V_151 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_104 -> V_50 -> V_60 . V_152 ++ ) ;
return;
}
if ( V_146 -> V_117 . V_153 & V_154 )
V_2 -> V_155 ++ ;
if ( F_72 ( V_146 , V_36 , & V_134 , V_140 ) < 0 )
return;
if ( ! V_2 -> V_156 &&
V_157 . V_158 &&
V_134 . V_159 == V_160 ) {
F_17 (
L_62
L_63
L_64 ,
V_134 . V_15 && ! F_73 ( & V_134 . V_15 -> V_18 -> V_161 [ V_162 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_156 = true ;
}
if ( V_134 . V_12 == NULL ) {
const char * V_69 = L_67 ;
if ( ! V_2 -> V_156 && ! V_2 -> V_163 &&
V_134 . V_15 == V_36 -> V_164 [ V_162 ] &&
F_73 ( & V_134 . V_15 -> V_18 -> V_161 [ V_162 ] ) ) {
if ( V_157 . V_165 ) {
char V_166 [ 256 ] ;
F_74 ( V_134 . V_15 -> V_18 , V_166 , sizeof( V_166 ) ) ;
F_17 ( L_68 ,
V_157 . V_165 , V_166 , V_69 ) ;
} else {
F_17 ( L_69 ,
V_69 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_163 = true ;
}
}
if ( V_134 . V_12 == NULL || ! V_134 . V_12 -> V_130 ) {
struct V_43 * V_43 = F_29 ( V_136 ) ;
struct V_131 V_132 = {
. V_136 = V_136 ,
. V_140 = V_140 ,
. V_167 = F_65 ,
} ;
if ( V_157 . V_168 )
V_132 . V_169 = & V_170 ;
else
V_132 . V_169 = & V_171 ;
F_9 ( & V_43 -> V_23 ) ;
V_16 = F_75 ( & V_132 , & V_134 , V_2 -> V_172 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_43 -> V_23 ) ;
}
F_76 ( & V_134 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_53 )
{
struct V_147 V_140 ;
struct V_107 * V_136 ;
struct V_173 * V_104 = V_2 -> V_104 ;
union V_145 * V_146 ;
struct V_36 * V_36 ;
T_6 V_174 ;
int V_87 ;
while ( ( V_146 = F_78 ( V_2 -> V_50 , V_53 ) ) != NULL ) {
V_87 = F_79 ( V_2 -> V_50 , V_146 , & V_140 ) ;
if ( V_87 ) {
F_6 ( L_71 , V_87 ) ;
goto V_175;
}
V_136 = F_80 ( V_104 -> V_50 , V_140 . V_176 ) ;
assert ( V_136 != NULL ) ;
V_174 = V_146 -> V_117 . V_153 & V_177 ;
if ( V_146 -> V_117 . type == V_178 )
++ V_2 -> V_179 ;
switch ( V_174 ) {
case V_180 :
++ V_2 -> V_181 ;
if ( V_2 -> V_65 )
goto V_175;
V_36 = & V_104 -> V_182 . V_183 ;
break;
case V_160 :
++ V_2 -> V_184 ;
if ( V_2 -> V_66 )
goto V_175;
V_36 = & V_104 -> V_182 . V_183 ;
break;
case V_185 :
++ V_2 -> V_186 ;
V_36 = F_81 ( V_104 ,
V_140 . V_151 ) ;
break;
case V_187 :
++ V_2 -> V_188 ;
goto V_175;
default:
if ( V_146 -> V_117 . type == V_178 )
goto V_175;
V_36 = & V_104 -> V_182 . V_183 ;
break;
}
if ( V_146 -> V_117 . type == V_178 ) {
F_67 ( & V_2 -> V_144 , V_146 , V_136 ,
& V_140 , V_36 ) ;
} else if ( V_146 -> V_117 . type < V_189 ) {
F_82 ( F_29 ( V_136 ) , V_146 -> V_117 . type ) ;
F_83 ( V_36 , V_146 , & V_140 ) ;
} else
++ V_104 -> V_50 -> V_60 . V_190 ;
V_175:
F_84 ( V_2 -> V_50 , V_53 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < V_2 -> V_50 -> V_192 ; V_191 ++ )
F_77 ( V_2 , V_191 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
char V_69 [ 512 ] ;
struct V_107 * V_41 ;
struct V_193 * V_50 = V_2 -> V_50 ;
struct V_115 * V_194 = & V_2 -> V_115 ;
F_87 ( V_50 , V_194 ) ;
F_52 (evlist, counter) {
V_195:
if ( F_88 ( V_41 , V_2 -> V_50 -> V_196 ,
V_2 -> V_50 -> V_197 ) < 0 ) {
if ( F_89 ( V_41 , V_128 , V_69 , sizeof( V_69 ) ) ) {
if ( V_198 )
F_17 ( L_21 , V_69 ) ;
goto V_195;
}
F_90 ( V_41 , & V_194 -> V_68 ,
V_128 , V_69 , sizeof( V_69 ) ) ;
F_91 ( L_21 , V_69 ) ;
goto V_199;
}
}
if ( F_92 ( V_50 , V_194 -> V_200 , false ) < 0 ) {
F_91 ( L_72 ,
V_128 , F_93 ( V_128 , V_69 , sizeof( V_69 ) ) ) ;
goto V_199;
}
return 0 ;
V_199:
return - 1 ;
}
static int F_94 ( struct V_1 * V_2 V_7 )
{
if ( ! V_137 ) {
if ( V_157 . V_201 ) {
F_91 ( L_73 ) ;
return - V_202 ;
}
} else if ( V_203 . V_204 != V_205 ) {
if ( F_95 ( & V_203 ) < 0 ) {
F_91 ( L_74 ) ;
return - V_202 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_115 * V_194 = & V_2 -> V_115 ;
T_7 V_206 ;
int V_87 ;
V_2 -> V_104 = F_97 ( NULL , false , NULL ) ;
if ( V_2 -> V_104 == NULL )
return - 1 ;
F_98 ( & V_2 -> V_104 -> V_182 , F_62 ) ;
if ( ! V_207 ) {
V_87 = F_99 ( & V_2 -> V_104 -> V_117 . V_118 ) ;
if ( V_87 )
goto V_208;
}
V_87 = F_94 ( V_2 ) ;
if ( V_87 )
goto V_208;
if ( F_100 ( V_2 -> V_104 ) == NULL )
goto V_208;
F_101 ( & V_2 -> V_104 -> V_182 . V_183 , & V_194 -> V_68 ,
V_2 -> V_50 -> V_197 , false , V_194 -> V_209 ) ;
if ( V_210 ) {
V_87 = F_102 ( & V_211 ) ;
if ( V_87 < 0 )
goto V_212;
}
V_87 = F_86 ( V_2 ) ;
if ( V_87 )
goto V_208;
V_2 -> V_104 -> V_50 = V_2 -> V_50 ;
F_103 ( V_2 -> V_104 ) ;
if ( ! F_104 ( & V_194 -> V_68 ) )
F_105 ( V_2 -> V_50 ) ;
F_106 ( V_2 -> V_50 , 100 ) ;
F_85 ( V_2 ) ;
V_87 = - 1 ;
if ( F_107 ( & V_206 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_91 ( L_75 ) ;
goto V_208;
}
if ( V_2 -> V_213 ) {
struct V_214 V_215 ;
V_215 . V_216 = V_2 -> V_213 ;
if ( F_108 ( 0 , V_217 , & V_215 ) ) {
F_91 ( L_76 ) ;
goto V_218;
}
}
while ( ! V_119 ) {
T_4 V_219 = V_2 -> V_179 ;
F_85 ( V_2 ) ;
if ( V_219 == V_2 -> V_179 )
V_87 = F_106 ( V_2 -> V_50 , 100 ) ;
}
V_87 = 0 ;
V_218:
F_109 ( V_206 , NULL ) ;
V_208:
F_110 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
return V_87 ;
V_212: {
char V_220 [ V_221 ] ;
const char * V_16 = F_93 ( - V_87 , V_220 , sizeof( V_220 ) ) ;
F_91 ( L_77 , V_16 ) ;
goto V_208;
}
}
static int
F_111 ( const struct V_222 * V_223 , const char * V_8 , int V_224 )
{
V_157 . V_201 = true ;
return F_112 ( V_223 , V_8 , V_224 ) ;
}
static int
F_113 ( const struct V_222 * V_223 , const char * V_8 , int V_224 )
{
struct V_115 * V_225 = (struct V_115 * ) V_223 -> V_226 ;
V_225 -> V_227 = true ;
V_203 . V_51 = ! V_224 ;
V_203 . V_228 = V_229 ;
if ( V_224 ) {
V_157 . V_201 = false ;
V_203 . V_228 = V_230 ;
return 0 ;
}
return F_114 ( V_8 ) ;
}
static int F_115 ( const char * V_231 , const char * V_226 , void * V_232 )
{
if ( ! strcmp ( V_231 , L_78 ) )
V_231 = L_79 ;
if ( ! strcmp ( V_231 , L_80 ) ) {
V_157 . V_168 = F_116 ( V_231 , V_226 ) ;
return 0 ;
}
return F_117 ( V_231 , V_226 , V_232 ) ;
}
static int
F_118 ( const struct V_222 * V_223 , const char * V_8 ,
int V_224 V_7 )
{
struct V_1 * V_2 = V_223 -> V_226 ;
V_2 -> V_67 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_119 ( int V_233 , const char * * V_234 , const char * T_8 V_7 )
{
char V_220 [ V_221 ] ;
struct V_1 V_2 = {
. V_85 = 5 ,
. V_83 = 2 ,
. V_115 = {
. V_200 = V_235 ,
. V_236 = V_235 ,
. V_237 = V_238 ,
. V_239 = 4000 ,
. V_68 = {
. V_240 = true ,
} ,
. V_209 = 500 ,
} ,
. V_172 = V_241 ,
. V_49 = 5 ,
} ;
struct V_115 * V_194 = & V_2 . V_115 ;
struct V_68 * V_68 = & V_194 -> V_68 ;
const struct V_222 V_242 [] = {
F_120 ( 'e' , L_81 , & V_2 . V_50 , L_81 ,
L_82 ,
V_243 ) ,
F_121 ( 'c' , L_83 , & V_194 -> V_237 , L_84 ) ,
F_122 ( 'p' , L_85 , & V_68 -> V_151 , L_85 ,
L_86 ) ,
F_122 ( 't' , L_87 , & V_68 -> V_244 , L_87 ,
L_88 ) ,
F_123 ( 'a' , L_89 , & V_68 -> V_245 ,
L_90 ) ,
F_122 ( 'C' , L_91 , & V_68 -> V_246 , L_91 ,
L_92 ) ,
F_122 ( 'k' , L_93 , & V_157 . V_165 ,
L_94 , L_95 ) ,
F_123 ( 0 , L_96 , & V_157 . V_247 ,
L_97 ) ,
F_123 ( 'K' , L_98 , & V_2 . V_66 ,
L_99 ) ,
F_120 ( 'm' , L_100 , & V_194 -> V_200 , L_101 ,
L_102 ,
V_248 ) ,
F_124 ( 'r' , L_103 , & V_2 . V_213 ,
L_104 ) ,
F_124 ( 'd' , L_105 , & V_2 . V_83 ,
L_106 ) ,
F_123 ( 'D' , L_107 , & V_2 . V_103 ,
L_108 ) ,
F_124 ( 'f' , L_109 , & V_2 . V_85 ,
L_110 ) ,
F_123 ( 0 , L_111 , & V_194 -> V_249 ,
L_112 ) ,
F_123 ( 'i' , L_113 , & V_194 -> V_250 ,
L_114 ) ,
F_122 ( 0 , L_115 , & V_2 . V_251 , L_116 ,
L_117 ) ,
F_123 ( 'z' , L_118 , & V_2 . V_52 , L_119 ) ,
F_125 ( 'F' , L_120 , & V_194 -> V_236 , L_121 ) ,
F_124 ( 'E' , L_122 , & V_2 . V_3 ,
L_123 ) ,
F_123 ( 'U' , L_124 , & V_2 . V_65 ,
L_125 ) ,
F_123 ( 0 , L_126 , & V_2 . V_252 , L_127 ) ,
F_123 ( 0 , L_128 , & V_2 . V_253 , L_129 ) ,
F_126 ( 'v' , L_130 , & V_198 ,
L_131 ) ,
F_122 ( 's' , L_132 , & V_254 , L_133 ,
L_134
L_135 ) ,
F_122 ( 0 , L_136 , & V_255 , L_137 ,
L_138 ) ,
F_123 ( 'n' , L_139 , & V_157 . V_256 ,
L_140 ) ,
F_127 ( 'g' , NULL , & V_2 . V_115 ,
NULL , L_141 ,
& F_111 ) ,
F_120 ( 0 , L_142 , & V_2 . V_115 ,
L_143 ,
V_257 , & F_113 ) ,
F_123 ( 0 , L_144 , & V_157 . V_168 ,
L_145 ) ,
F_124 ( 0 , L_146 , & V_2 . V_172 ,
L_147
L_148 F_128 ( V_241 ) ) ,
F_120 ( 0 , L_149 , NULL , L_150 ,
L_151 ,
V_258 ) ,
F_123 ( 0 , L_152 , & V_157 . V_259 ,
L_153 ) ,
F_122 ( 0 , L_154 , & V_157 . V_260 , L_155 ,
L_156 ) ,
F_122 ( 0 , L_157 , & V_157 . V_261 , L_158 ,
L_159 ) ,
F_122 ( 0 , L_160 , & V_157 . V_262 , L_161 ,
L_162 ) ,
F_123 ( 0 , L_163 , & V_157 . V_263 ,
L_164 ) ,
F_123 ( 0 , L_165 , & V_157 . V_264 ,
L_166 ) ,
F_123 ( 0 , L_167 , & V_157 . V_265 ,
L_168 ) ,
F_122 ( 0 , L_169 , & V_207 , L_170 ,
L_171 ) ,
F_122 ( 'M' , L_172 , & V_266 , L_173 ,
L_174 ) ,
F_122 ( 'u' , L_175 , & V_68 -> V_116 , L_176 , L_177 ) ,
F_120 ( 0 , L_178 , & V_2 , L_179 ,
L_180 , F_118 ) ,
F_120 ( 0 , L_181 , NULL , L_182 ,
L_183 , V_267 ) ,
F_122 ( 'w' , L_184 , & V_157 . V_268 ,
L_185 ,
L_186 ) ,
F_125 ( 0 , L_187 , & V_194 -> V_209 ,
L_188 ) ,
F_127 ( 'b' , L_189 , & V_194 -> V_141 ,
L_190 , L_191 ,
V_269 ) ,
F_120 ( 'j' , L_192 , & V_194 -> V_141 ,
L_193 , L_194 ,
V_269 ) ,
F_129 ()
} ;
const char * const V_270 [] = {
L_195 ,
NULL
} ;
int V_271 = F_130 () ;
if ( V_271 < 0 )
return V_271 ;
V_2 . V_50 = F_131 () ;
if ( V_2 . V_50 == NULL )
return - V_45 ;
F_132 ( F_115 , & V_2 ) ;
V_233 = F_133 ( V_233 , V_234 , V_242 , V_270 , 0 ) ;
if ( V_233 )
F_134 ( V_270 , V_242 ) ;
V_272 = V_273 ;
V_274 = 1 ;
if ( F_135 () < 0 ) {
if ( V_254 )
F_136 ( V_270 , V_242 , L_196 , 1 ) ;
if ( V_255 )
F_136 ( V_254 ? NULL : V_270 ,
V_242 , L_136 , 0 ) ;
goto V_275;
}
if ( V_2 . V_253 )
V_39 = 0 ;
else if ( V_2 . V_252 )
V_39 = 1 ;
F_137 ( false ) ;
V_271 = F_138 ( V_68 ) ;
if ( V_271 ) {
F_139 ( V_68 , V_271 , V_220 , V_221 ) ;
F_17 ( L_21 , V_220 ) ;
}
V_271 = F_140 ( V_68 ) ;
if ( V_271 ) {
int V_276 = V_128 ;
F_139 ( V_68 , V_271 , V_220 , V_221 ) ;
F_91 ( L_21 , V_220 ) ;
V_271 = - V_276 ;
goto V_275;
}
if ( F_104 ( V_68 ) )
V_68 -> V_245 = true ;
if ( F_141 ( V_2 . V_50 , V_68 ) < 0 )
F_134 ( V_270 , V_242 ) ;
if ( ! V_2 . V_50 -> V_84 &&
F_142 ( V_2 . V_50 ) < 0 ) {
F_91 ( L_197 ) ;
goto V_275;
}
V_157 . V_62 = V_2 . V_50 -> V_84 ;
if ( V_2 . V_83 < 1 )
V_2 . V_83 = 1 ;
if ( F_143 ( V_194 ) ) {
V_271 = - V_202 ;
goto V_275;
}
V_2 . V_48 = F_53 ( V_2 . V_50 ) ;
if ( ! V_157 . V_201 ) {
V_157 . V_168 = false ;
F_144 () ;
}
if ( V_157 . V_168 && ! V_203 . V_277 )
V_203 . V_278 = V_279 ;
V_157 . V_280 = sizeof( struct V_13 ) ;
V_157 . V_281 = ( V_157 . V_165 == NULL ) ;
if ( F_145 ( NULL ) < 0 )
return - 1 ;
F_146 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_96 V_97 = {
. V_98 = F_2 ,
. V_99 = V_100 ,
} ;
F_1 ( & V_2 ) ;
V_96 ( V_101 , & V_97 , NULL ) ;
}
V_271 = F_96 ( & V_2 ) ;
V_275:
F_147 ( V_2 . V_50 ) ;
return V_271 ;
}
