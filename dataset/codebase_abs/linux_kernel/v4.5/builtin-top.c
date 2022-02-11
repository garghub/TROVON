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
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
int V_16 = 0 ;
if ( V_12 == NULL || ( V_39 == 0 &&
( V_2 -> V_25 == NULL ||
V_2 -> V_25 -> V_17 . V_12 != V_12 ) ) )
return;
V_14 = F_8 ( V_12 ) ;
if ( F_20 ( & V_14 -> V_23 ) )
return;
V_16 = F_21 ( V_10 , V_41 , V_26 ) ;
F_11 ( & V_14 -> V_23 ) ;
if ( F_22 ( V_16 ) ) {
F_11 ( & V_10 -> V_42 -> V_23 ) ;
if ( V_16 == - V_43 && ! V_10 -> V_17 . V_15 -> V_40 )
F_15 ( V_10 -> V_17 . V_15 , V_12 , V_26 ) ;
else if ( V_16 == - V_44 ) {
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
}
F_9 ( & V_10 -> V_42 -> V_23 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_45 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_46;
printf ( L_18 , F_24 ( V_2 -> V_47 ) , V_11 -> V_21 ) ;
printf ( L_19 , V_2 -> V_48 ) ;
V_45 = F_25 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_47 ,
0 , V_2 -> V_48 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_49 -> V_50 ) {
if ( V_2 -> V_51 )
F_26 ( V_11 , V_2 -> V_47 -> V_52 ) ;
else
F_27 ( V_11 , V_2 -> V_47 -> V_52 ) ;
}
if ( V_45 != 0 )
printf ( L_20 , V_45 ) ;
V_46:
F_11 ( & V_14 -> V_23 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
char V_53 [ 160 ] ;
int V_54 = 0 ;
const int V_55 = V_2 -> V_4 . V_56 - 1 ;
struct V_42 * V_42 = F_29 ( V_2 -> V_47 ) ;
puts ( V_57 ) ;
F_30 ( V_2 , V_53 , sizeof( V_53 ) ) ;
printf ( L_21 , V_53 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_55 , V_55 , V_58 ) ;
if ( V_42 -> V_59 . V_60 !=
V_42 -> V_59 . V_61 [ V_62 ] ) {
V_42 -> V_59 . V_60 =
V_42 -> V_59 . V_61 [ V_62 ] ;
F_32 ( stdout , V_63 ,
L_23 ,
V_42 -> V_59 . V_60 ) ;
++ V_54 ;
}
if ( V_2 -> V_25 ) {
F_23 ( V_2 ) ;
return;
}
if ( V_2 -> V_49 -> V_50 ) {
if ( V_2 -> V_51 ) {
F_33 ( V_42 ) ;
} else {
F_34 ( V_42 , V_2 -> V_64 ,
V_2 -> V_65 ) ;
}
}
F_35 ( V_42 , NULL ) ;
F_36 ( V_42 , NULL ) ;
F_37 ( V_42 , V_2 -> V_3 - V_54 ) ;
putchar ( '\n' ) ;
F_38 ( V_42 , false , V_2 -> V_3 - V_54 , V_55 ,
V_2 -> V_66 , stdout ) ;
}
static void F_39 ( int * V_67 , const char * V_68 )
{
char * V_69 = malloc ( 0 ) , * V_70 ;
T_5 V_71 = 0 ;
int V_72 ;
fprintf ( stdout , L_24 , V_68 ) ;
if ( F_40 ( & V_69 , & V_71 , V_73 ) < 0 )
return;
V_70 = strchr ( V_69 , '\n' ) ;
if ( V_70 )
* V_70 = 0 ;
V_70 = V_69 ;
while( * V_70 ) {
if ( ! isdigit ( * V_70 ) )
goto V_74;
V_70 ++ ;
}
V_72 = strtoul ( V_69 , NULL , 10 ) ;
* V_67 = V_72 ;
V_74:
free ( V_69 ) ;
}
static void F_41 ( int * V_67 , const char * V_68 )
{
int V_72 = 0 ;
F_39 ( & V_72 , V_68 ) ;
if ( V_72 >= 0 && V_72 <= 100 )
* V_67 = V_72 ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_68 )
{
char * V_69 = malloc ( 0 ) , * V_70 ;
struct V_9 * V_75 = V_2 -> V_25 , * V_76 , * V_77 = NULL ;
struct V_42 * V_42 = F_29 ( V_2 -> V_47 ) ;
struct V_78 * V_79 ;
T_5 V_71 = 0 ;
if ( V_75 ) {
F_13 ( V_75 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_68 ) ;
if ( F_40 ( & V_69 , & V_71 , V_73 ) < 0 )
goto V_74;
V_70 = strchr ( V_69 , '\n' ) ;
if ( V_70 )
* V_70 = 0 ;
V_79 = F_43 ( & V_42 -> V_80 ) ;
while ( V_79 ) {
V_76 = F_44 ( V_79 , struct V_9 , V_78 ) ;
if ( V_76 -> V_17 . V_12 && ! strcmp ( V_69 , V_76 -> V_17 . V_12 -> V_21 ) ) {
V_77 = V_76 ;
break;
}
V_79 = F_45 ( & V_76 -> V_78 ) ;
}
if ( ! V_77 ) {
fprintf ( V_81 , L_25 , V_69 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_77 ) ;
V_74:
free ( V_69 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_82 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_49 -> V_83 > 1 )
fprintf ( stdout , L_29 , F_24 ( V_2 -> V_47 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_84 ) ;
fprintf ( stdout , L_31 , V_2 -> V_48 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_65 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_64 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_51 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_85 )
{
switch ( V_85 ) {
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
return V_2 -> V_49 -> V_83 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_48 ( struct V_1 * V_2 , int V_85 )
{
bool V_86 = true ;
if ( ! F_47 ( V_2 , V_85 ) ) {
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 ;
F_46 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_49 ( & V_93 ) ;
F_50 ( & V_88 , 1 , - 1 ) ;
V_85 = getc ( V_73 ) ;
F_51 ( 0 , V_94 , & V_93 ) ;
if ( ! F_47 ( V_2 , V_85 ) )
return V_86 ;
}
switch ( V_85 ) {
case 'd' :
F_39 ( & V_2 -> V_82 , L_42 ) ;
if ( V_2 -> V_82 < 1 )
V_2 -> V_82 = 1 ;
break;
case 'e' :
F_39 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_2 ,
. V_98 = V_99 ,
} ;
F_2 ( V_100 , NULL , V_2 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
} else {
signal ( V_100 , V_101 ) ;
}
break;
case 'E' :
if ( V_2 -> V_49 -> V_83 > 1 ) {
int V_41 = 0 ;
fprintf ( V_81 , L_44 ) ;
F_52 (top->evlist, top->sym_evsel)
fprintf ( V_81 , L_45 , V_2 -> V_47 -> V_52 , F_24 ( V_2 -> V_47 ) ) ;
F_39 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_49 -> V_83 ) {
V_2 -> V_47 = F_53 ( V_2 -> V_49 ) ;
fprintf ( V_81 , L_47 , F_24 ( V_2 -> V_47 ) ) ;
F_7 ( 1 ) ;
break;
}
F_52 (top->evlist, top->sym_evsel)
if ( V_2 -> V_47 -> V_52 == V_41 )
break;
} else
V_2 -> V_47 = F_53 ( V_2 -> V_49 ) ;
break;
case 'f' :
F_39 ( & V_2 -> V_84 , L_48 ) ;
break;
case 'F' :
F_41 ( & V_2 -> V_48 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_65 = ! V_2 -> V_65 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_102 )
F_54 ( V_2 -> V_103 , V_81 ) ;
V_86 = false ;
break;
case 's' :
F_42 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_75 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_75 ) ;
}
break;
case 'U' :
V_2 -> V_64 = ! V_2 -> V_64 ;
break;
case 'z' :
V_2 -> V_51 = ! V_2 -> V_51 ;
break;
default:
break;
}
return V_86 ;
}
static void F_55 ( void * V_8 )
{
struct V_1 * V_104 = V_8 ;
struct V_42 * V_42 ;
F_31 ( V_104 ) ;
if ( V_104 -> V_49 -> V_105 != NULL )
V_104 -> V_47 = V_104 -> V_49 -> V_105 ;
V_42 = F_29 ( V_104 -> V_47 ) ;
if ( V_104 -> V_49 -> V_50 ) {
if ( V_104 -> V_51 ) {
F_33 ( V_42 ) ;
} else {
F_34 ( V_42 , V_104 -> V_64 ,
V_104 -> V_65 ) ;
}
}
F_35 ( V_42 , NULL ) ;
F_36 ( V_42 , NULL ) ;
}
static void * F_56 ( void * V_8 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 = V_8 ;
const char * V_108 = L_52 ;
struct V_109 V_110 = {
. V_111 = F_55 ,
. V_8 = V_2 ,
. V_112 = V_2 -> V_82 ,
} ;
F_55 ( V_2 ) ;
F_52 (top->evlist, pos) {
struct V_42 * V_42 = F_29 ( V_107 ) ;
V_42 -> V_113 = V_2 -> V_114 . V_67 . V_115 ;
}
F_57 ( V_2 -> V_49 , V_108 , & V_110 ,
V_2 -> V_66 ,
& V_2 -> V_103 -> V_116 . V_117 ) ;
V_118 = 1 ;
return NULL ;
}
static void F_58 ( int T_1 V_7 )
{
V_118 = 1 ;
}
static void F_59 ( void )
{
signal ( V_119 , V_120 ) ;
signal ( V_121 , V_120 ) ;
signal ( V_122 , F_58 ) ;
signal ( V_123 , F_58 ) ;
signal ( V_124 , F_58 ) ;
}
static void * F_60 ( void * V_8 )
{
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 ;
struct V_1 * V_2 = V_8 ;
int V_125 , V_85 ;
F_59 () ;
F_61 () ;
V_126:
V_125 = V_2 -> V_82 * 1000 ;
F_49 ( & V_93 ) ;
getc ( V_73 ) ;
while ( ! V_118 ) {
F_28 ( V_2 ) ;
switch ( F_50 ( & V_88 , 1 , V_125 ) ) {
case 0 :
continue;
case - 1 :
if ( V_127 == V_128 )
continue;
default:
V_85 = getc ( V_73 ) ;
F_51 ( 0 , V_94 , & V_93 ) ;
if ( F_48 ( V_2 , V_85 ) )
goto V_126;
V_118 = 1 ;
}
}
F_51 ( 0 , V_94 , & V_93 ) ;
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
V_12 -> V_129 = true ;
return 0 ;
}
static int F_65 ( struct V_130 * V_131 ,
struct V_132 * V_133 , bool V_134 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_131 -> V_10 ;
struct V_106 * V_135 = V_131 -> V_135 ;
if ( V_136 && V_134 )
F_19 ( V_2 , V_10 , V_135 -> V_52 , V_133 -> V_137 ) ;
F_66 ( V_131 -> V_138 -> V_139 , V_133 , V_131 -> V_138 ,
! ( V_2 -> V_114 . V_139 & V_140 ) ) ;
return 0 ;
}
static void F_67 ( struct V_141 * V_142 ,
const union V_143 * V_144 ,
struct V_106 * V_135 ,
struct V_145 * V_138 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_68 ( V_142 , struct V_1 , V_142 ) ;
struct V_132 V_133 ;
int V_16 ;
if ( ! V_36 && V_146 ) {
static struct V_147 * V_148 ;
if ( ! V_148 )
V_148 = F_69 ( NULL ) ;
if ( ! F_70 ( V_148 , V_138 -> V_149 ) ) {
F_6 ( L_60 ,
V_138 -> V_149 ) ;
F_71 ( V_148 , V_138 -> V_149 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_103 -> V_49 -> V_59 . V_150 ++ ) ;
return;
}
if ( V_144 -> V_116 . V_151 & V_152 )
V_2 -> V_153 ++ ;
if ( F_72 ( V_144 , V_36 , & V_133 , V_138 ) < 0 )
return;
if ( ! V_2 -> V_154 &&
V_155 . V_156 &&
V_133 . V_157 == V_158 ) {
F_17 (
L_62
L_63
L_64 ,
V_133 . V_15 && ! F_73 ( & V_133 . V_15 -> V_18 -> V_159 [ V_160 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_154 = true ;
}
if ( V_133 . V_12 == NULL ) {
const char * V_68 = L_67 ;
if ( ! V_2 -> V_154 && ! V_2 -> V_161 &&
V_133 . V_15 == V_36 -> V_162 [ V_160 ] &&
F_73 ( & V_133 . V_15 -> V_18 -> V_159 [ V_160 ] ) ) {
if ( V_155 . V_163 ) {
char V_164 [ 256 ] ;
F_74 ( V_133 . V_15 -> V_18 , V_164 , sizeof( V_164 ) ) ;
F_17 ( L_68 ,
V_155 . V_163 , V_164 , V_68 ) ;
} else {
F_17 ( L_69 ,
V_68 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_161 = true ;
}
}
if ( V_133 . V_12 == NULL || ! V_133 . V_12 -> V_129 ) {
struct V_42 * V_42 = F_29 ( V_135 ) ;
struct V_130 V_131 = {
. V_135 = V_135 ,
. V_138 = V_138 ,
. V_165 = F_65 ,
} ;
if ( V_155 . V_166 )
V_131 . V_167 = & V_168 ;
else
V_131 . V_167 = & V_169 ;
F_9 ( & V_42 -> V_23 ) ;
V_16 = F_75 ( & V_131 , & V_133 , V_2 -> V_170 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_42 -> V_23 ) ;
}
F_76 ( & V_133 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_52 )
{
struct V_145 V_138 ;
struct V_106 * V_135 ;
struct V_171 * V_103 = V_2 -> V_103 ;
union V_143 * V_144 ;
struct V_36 * V_36 ;
T_6 V_172 ;
int V_86 ;
while ( ( V_144 = F_78 ( V_2 -> V_49 , V_52 ) ) != NULL ) {
V_86 = F_79 ( V_2 -> V_49 , V_144 , & V_138 ) ;
if ( V_86 ) {
F_6 ( L_71 , V_86 ) ;
goto V_173;
}
V_135 = F_80 ( V_103 -> V_49 , V_138 . V_174 ) ;
assert ( V_135 != NULL ) ;
V_172 = V_144 -> V_116 . V_151 & V_175 ;
if ( V_144 -> V_116 . type == V_176 )
++ V_2 -> V_177 ;
switch ( V_172 ) {
case V_178 :
++ V_2 -> V_179 ;
if ( V_2 -> V_64 )
goto V_173;
V_36 = & V_103 -> V_180 . V_181 ;
break;
case V_158 :
++ V_2 -> V_182 ;
if ( V_2 -> V_65 )
goto V_173;
V_36 = & V_103 -> V_180 . V_181 ;
break;
case V_183 :
++ V_2 -> V_184 ;
V_36 = F_81 ( V_103 ,
V_138 . V_149 ) ;
break;
case V_185 :
++ V_2 -> V_186 ;
goto V_173;
default:
if ( V_144 -> V_116 . type == V_176 )
goto V_173;
V_36 = & V_103 -> V_180 . V_181 ;
break;
}
if ( V_144 -> V_116 . type == V_176 ) {
F_67 ( & V_2 -> V_142 , V_144 , V_135 ,
& V_138 , V_36 ) ;
} else if ( V_144 -> V_116 . type < V_187 ) {
F_82 ( F_29 ( V_135 ) , V_144 -> V_116 . type ) ;
F_83 ( V_36 , V_144 , & V_138 ) ;
} else
++ V_103 -> V_49 -> V_59 . V_188 ;
V_173:
F_84 ( V_2 -> V_49 , V_52 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
int V_189 ;
for ( V_189 = 0 ; V_189 < V_2 -> V_49 -> V_190 ; V_189 ++ )
F_77 ( V_2 , V_189 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
char V_68 [ 512 ] ;
struct V_106 * V_41 ;
struct V_191 * V_49 = V_2 -> V_49 ;
struct V_114 * V_192 = & V_2 -> V_114 ;
F_87 ( V_49 , V_192 ) ;
F_52 (evlist, counter) {
V_193:
if ( F_88 ( V_41 , V_2 -> V_49 -> V_194 ,
V_2 -> V_49 -> V_195 ) < 0 ) {
if ( F_89 ( V_41 , V_127 , V_68 , sizeof( V_68 ) ) ) {
if ( V_196 )
F_17 ( L_21 , V_68 ) ;
goto V_193;
}
F_90 ( V_41 , & V_192 -> V_67 ,
V_127 , V_68 , sizeof( V_68 ) ) ;
F_91 ( L_21 , V_68 ) ;
goto V_197;
}
}
if ( F_92 ( V_49 , V_192 -> V_198 , false ) < 0 ) {
F_91 ( L_72 ,
V_127 , F_93 ( V_127 , V_68 , sizeof( V_68 ) ) ) ;
goto V_197;
}
return 0 ;
V_197:
return - 1 ;
}
static int F_94 ( struct V_1 * V_2 V_7 )
{
if ( ! V_136 ) {
if ( V_155 . V_199 ) {
F_91 ( L_73 ) ;
return - V_200 ;
}
} else if ( V_201 . V_202 != V_203 ) {
if ( F_95 ( & V_201 ) < 0 ) {
F_91 ( L_74 ) ;
return - V_200 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_114 * V_192 = & V_2 -> V_114 ;
T_7 V_204 ;
int V_86 ;
V_2 -> V_103 = F_97 ( NULL , false , NULL ) ;
if ( V_2 -> V_103 == NULL )
return - 1 ;
F_98 ( & V_2 -> V_103 -> V_180 , F_62 ) ;
if ( ! V_205 ) {
V_86 = F_99 ( & V_2 -> V_103 -> V_116 . V_117 ) ;
if ( V_86 )
goto V_206;
}
V_86 = F_94 ( V_2 ) ;
if ( V_86 )
goto V_206;
if ( F_100 ( V_2 -> V_103 ) < 0 )
goto V_206;
F_101 ( & V_2 -> V_103 -> V_180 . V_181 , & V_192 -> V_67 ,
V_2 -> V_49 -> V_195 , false , V_192 -> V_207 ) ;
if ( V_208 ) {
V_86 = F_102 ( & V_209 ) ;
if ( V_86 < 0 )
goto V_210;
}
V_86 = F_86 ( V_2 ) ;
if ( V_86 )
goto V_206;
V_2 -> V_103 -> V_49 = V_2 -> V_49 ;
F_103 ( V_2 -> V_103 ) ;
if ( ! F_104 ( & V_192 -> V_67 ) )
F_105 ( V_2 -> V_49 ) ;
F_106 ( V_2 -> V_49 , 100 ) ;
F_85 ( V_2 ) ;
V_86 = - 1 ;
if ( F_107 ( & V_204 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_91 ( L_75 ) ;
goto V_206;
}
if ( V_2 -> V_211 ) {
struct V_212 V_213 ;
V_213 . V_214 = V_2 -> V_211 ;
if ( F_108 ( 0 , V_215 , & V_213 ) ) {
F_91 ( L_76 ) ;
goto V_216;
}
}
while ( ! V_118 ) {
T_4 V_217 = V_2 -> V_177 ;
F_85 ( V_2 ) ;
if ( V_217 == V_2 -> V_177 )
V_86 = F_106 ( V_2 -> V_49 , 100 ) ;
}
V_86 = 0 ;
V_216:
F_109 ( V_204 , NULL ) ;
V_206:
F_110 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
return V_86 ;
V_210: {
char V_218 [ V_219 ] ;
const char * V_16 = F_93 ( - V_86 , V_218 , sizeof( V_218 ) ) ;
F_91 ( L_77 , V_16 ) ;
goto V_206;
}
}
static int
F_111 ( const struct V_220 * V_221 , const char * V_8 , int V_222 )
{
V_155 . V_199 = true ;
return F_112 ( V_221 , V_8 , V_222 ) ;
}
static int
F_113 ( const struct V_220 * V_221 , const char * V_8 , int V_222 )
{
struct V_114 * V_223 = (struct V_114 * ) V_221 -> V_224 ;
V_223 -> V_225 = true ;
V_201 . V_50 = ! V_222 ;
V_201 . V_226 = V_227 ;
if ( V_222 ) {
V_155 . V_199 = false ;
V_201 . V_226 = V_228 ;
return 0 ;
}
return F_114 ( V_8 ) ;
}
static int F_115 ( const char * V_229 , const char * V_224 , void * V_230 )
{
if ( ! strcmp ( V_229 , L_78 ) )
V_229 = L_79 ;
if ( ! strcmp ( V_229 , L_80 ) ) {
V_155 . V_166 = F_116 ( V_229 , V_224 ) ;
return 0 ;
}
return F_117 ( V_229 , V_224 , V_230 ) ;
}
static int
F_118 ( const struct V_220 * V_221 , const char * V_8 ,
int V_222 V_7 )
{
struct V_1 * V_2 = V_221 -> V_224 ;
V_2 -> V_66 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_119 ( int V_231 , const char * * V_232 , const char * T_8 V_7 )
{
char V_218 [ V_219 ] ;
struct V_1 V_2 = {
. V_84 = 5 ,
. V_82 = 2 ,
. V_114 = {
. V_198 = V_233 ,
. V_234 = V_233 ,
. V_235 = V_236 ,
. V_237 = 4000 ,
. V_67 = {
. V_238 = true ,
} ,
. V_207 = 500 ,
} ,
. V_170 = V_239 ,
. V_48 = 5 ,
} ;
struct V_114 * V_192 = & V_2 . V_114 ;
struct V_67 * V_67 = & V_192 -> V_67 ;
const struct V_220 V_240 [] = {
F_120 ( 'e' , L_81 , & V_2 . V_49 , L_81 ,
L_82 ,
V_241 ) ,
F_121 ( 'c' , L_83 , & V_192 -> V_235 , L_84 ) ,
F_122 ( 'p' , L_85 , & V_67 -> V_149 , L_85 ,
L_86 ) ,
F_122 ( 't' , L_87 , & V_67 -> V_242 , L_87 ,
L_88 ) ,
F_123 ( 'a' , L_89 , & V_67 -> V_243 ,
L_90 ) ,
F_122 ( 'C' , L_91 , & V_67 -> V_244 , L_91 ,
L_92 ) ,
F_122 ( 'k' , L_93 , & V_155 . V_163 ,
L_94 , L_95 ) ,
F_123 ( 0 , L_96 , & V_155 . V_245 ,
L_97 ) ,
F_123 ( 'K' , L_98 , & V_2 . V_65 ,
L_99 ) ,
F_120 ( 'm' , L_100 , & V_192 -> V_198 , L_101 ,
L_102 ,
V_246 ) ,
F_124 ( 'r' , L_103 , & V_2 . V_211 ,
L_104 ) ,
F_124 ( 'd' , L_105 , & V_2 . V_82 ,
L_106 ) ,
F_123 ( 'D' , L_107 , & V_2 . V_102 ,
L_108 ) ,
F_124 ( 'f' , L_109 , & V_2 . V_84 ,
L_110 ) ,
F_123 ( 0 , L_111 , & V_192 -> V_247 ,
L_112 ) ,
F_123 ( 'i' , L_113 , & V_192 -> V_248 ,
L_114 ) ,
F_122 ( 0 , L_115 , & V_2 . V_249 , L_116 ,
L_117 ) ,
F_123 ( 'z' , L_118 , & V_2 . V_51 , L_119 ) ,
F_125 ( 'F' , L_120 , & V_192 -> V_234 , L_121 ) ,
F_124 ( 'E' , L_122 , & V_2 . V_3 ,
L_123 ) ,
F_123 ( 'U' , L_124 , & V_2 . V_64 ,
L_125 ) ,
F_123 ( 0 , L_126 , & V_2 . V_250 , L_127 ) ,
F_123 ( 0 , L_128 , & V_2 . V_251 , L_129 ) ,
F_126 ( 'v' , L_130 , & V_196 ,
L_131 ) ,
F_122 ( 's' , L_132 , & V_252 , L_133 ,
L_134
L_135 ) ,
F_122 ( 0 , L_136 , & V_253 , L_137 ,
L_138 ) ,
F_123 ( 'n' , L_139 , & V_155 . V_254 ,
L_140 ) ,
F_127 ( 'g' , NULL , & V_2 . V_114 ,
NULL , L_141 ,
& F_111 ) ,
F_120 ( 0 , L_142 , & V_2 . V_114 ,
L_143 ,
V_255 , & F_113 ) ,
F_123 ( 0 , L_144 , & V_155 . V_166 ,
L_145 ) ,
F_124 ( 0 , L_146 , & V_2 . V_170 ,
L_147
L_148 F_128 ( V_239 ) ) ,
F_120 ( 0 , L_149 , NULL , L_150 ,
L_151 ,
V_256 ) ,
F_123 ( 0 , L_152 , & V_155 . V_257 ,
L_153 ) ,
F_122 ( 0 , L_154 , & V_155 . V_258 , L_155 ,
L_156 ) ,
F_122 ( 0 , L_157 , & V_155 . V_259 , L_158 ,
L_159 ) ,
F_122 ( 0 , L_160 , & V_155 . V_260 , L_161 ,
L_162 ) ,
F_123 ( 0 , L_163 , & V_155 . V_261 ,
L_164 ) ,
F_123 ( 0 , L_165 , & V_155 . V_262 ,
L_166 ) ,
F_123 ( 0 , L_167 , & V_155 . V_263 ,
L_168 ) ,
F_122 ( 0 , L_169 , & V_205 , L_170 ,
L_171 ) ,
F_122 ( 'M' , L_172 , & V_264 , L_173 ,
L_174 ) ,
F_122 ( 'u' , L_175 , & V_67 -> V_115 , L_176 , L_177 ) ,
F_120 ( 0 , L_178 , & V_2 , L_179 ,
L_180 , F_118 ) ,
F_120 ( 0 , L_181 , NULL , L_182 ,
L_183 , V_265 ) ,
F_122 ( 'w' , L_184 , & V_155 . V_266 ,
L_185 ,
L_186 ) ,
F_125 ( 0 , L_187 , & V_192 -> V_207 ,
L_188 ) ,
F_127 ( 'b' , L_189 , & V_192 -> V_139 ,
L_190 , L_191 ,
V_267 ) ,
F_120 ( 'j' , L_192 , & V_192 -> V_139 ,
L_193 , L_194 ,
V_267 ) ,
F_123 ( 0 , L_195 , & V_155 . V_268 ,
L_196 ) ,
F_129 ()
} ;
const char * const V_269 [] = {
L_197 ,
NULL
} ;
int V_270 = F_130 () ;
if ( V_270 < 0 )
return V_270 ;
V_2 . V_49 = F_131 () ;
if ( V_2 . V_49 == NULL )
return - V_44 ;
F_132 ( F_115 , & V_2 ) ;
V_231 = F_133 ( V_231 , V_232 , V_240 , V_269 , 0 ) ;
if ( V_231 )
F_134 ( V_269 , V_240 ) ;
if ( ! V_2 . V_49 -> V_83 &&
F_135 ( V_2 . V_49 ) < 0 ) {
F_6 ( L_198 ) ;
goto V_271;
}
V_272 = V_273 ;
V_274 = 1 ;
if ( F_136 ( V_2 . V_49 ) < 0 ) {
if ( V_252 )
F_137 ( V_269 , V_240 , L_199 , 1 ) ;
if ( V_253 )
F_137 ( V_252 ? NULL : V_269 ,
V_240 , L_136 , 0 ) ;
goto V_271;
}
if ( V_2 . V_251 )
V_39 = 0 ;
else if ( V_2 . V_250 )
V_39 = 1 ;
F_138 ( false ) ;
V_270 = F_139 ( V_67 ) ;
if ( V_270 ) {
F_140 ( V_67 , V_270 , V_218 , V_219 ) ;
F_17 ( L_21 , V_218 ) ;
}
V_270 = F_141 ( V_67 ) ;
if ( V_270 ) {
int V_275 = V_127 ;
F_140 ( V_67 , V_270 , V_218 , V_219 ) ;
F_91 ( L_21 , V_218 ) ;
V_270 = - V_275 ;
goto V_271;
}
if ( F_104 ( V_67 ) )
V_67 -> V_243 = true ;
if ( F_142 ( V_2 . V_49 , V_67 ) < 0 ) {
F_91 ( L_200 ,
V_127 == V_276 ? L_201 : F_93 ( V_127 , V_218 , sizeof( V_218 ) ) ) ;
goto V_271;
}
V_155 . V_61 = V_2 . V_49 -> V_83 ;
if ( V_2 . V_82 < 1 )
V_2 . V_82 = 1 ;
if ( F_143 ( V_192 ) ) {
V_270 = - V_200 ;
goto V_271;
}
V_2 . V_47 = F_53 ( V_2 . V_49 ) ;
if ( ! V_155 . V_199 ) {
V_155 . V_166 = false ;
F_144 () ;
}
if ( V_155 . V_166 && ! V_201 . V_277 )
V_201 . V_278 = V_279 ;
V_155 . V_280 = sizeof( struct V_13 ) ;
V_155 . V_281 = ( V_155 . V_163 == NULL ) ;
if ( F_145 ( NULL ) < 0 )
return - 1 ;
F_146 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_2 ,
. V_98 = V_99 ,
} ;
F_1 ( & V_2 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
}
V_270 = F_96 ( & V_2 ) ;
V_271:
F_147 ( V_2 . V_49 ) ;
return V_270 ;
}
