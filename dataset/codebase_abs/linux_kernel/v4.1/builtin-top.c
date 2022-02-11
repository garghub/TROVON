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
if ( V_2 -> V_50 )
F_26 ( V_11 , V_2 -> V_48 -> V_51 ) ;
else
F_27 ( V_11 , V_2 -> V_48 -> V_51 ) ;
if ( V_46 != 0 )
printf ( L_20 , V_46 ) ;
V_47:
F_11 ( & V_14 -> V_23 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
char V_52 [ 160 ] ;
int V_53 = 0 ;
const int V_54 = V_2 -> V_4 . V_55 - 1 ;
struct V_43 * V_43 = F_29 ( V_2 -> V_48 ) ;
puts ( V_56 ) ;
F_30 ( V_2 , V_52 , sizeof( V_52 ) ) ;
printf ( L_21 , V_52 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_54 , V_54 , V_57 ) ;
if ( V_43 -> V_58 . V_59 !=
V_43 -> V_58 . V_60 [ V_61 ] ) {
V_43 -> V_58 . V_59 =
V_43 -> V_58 . V_60 [ V_61 ] ;
F_32 ( stdout , V_62 ,
L_23 ,
V_43 -> V_58 . V_59 ) ;
++ V_53 ;
}
if ( V_2 -> V_25 ) {
F_23 ( V_2 ) ;
return;
}
if ( V_2 -> V_50 ) {
F_33 ( V_43 ) ;
} else {
F_34 ( V_43 , V_2 -> V_63 ,
V_2 -> V_64 ) ;
}
F_35 ( V_43 , NULL ) ;
F_36 ( V_43 , NULL ) ;
F_37 ( V_43 , V_2 -> V_3 - V_53 ) ;
putchar ( '\n' ) ;
F_38 ( V_43 , false , V_2 -> V_3 - V_53 , V_54 ,
V_2 -> V_65 , stdout ) ;
}
static void F_39 ( int * V_66 , const char * V_67 )
{
char * V_68 = malloc ( 0 ) , * V_69 ;
T_5 V_70 = 0 ;
int V_71 ;
fprintf ( stdout , L_24 , V_67 ) ;
if ( F_40 ( & V_68 , & V_70 , V_72 ) < 0 )
return;
V_69 = strchr ( V_68 , '\n' ) ;
if ( V_69 )
* V_69 = 0 ;
V_69 = V_68 ;
while( * V_69 ) {
if ( ! isdigit ( * V_69 ) )
goto V_73;
V_69 ++ ;
}
V_71 = strtoul ( V_68 , NULL , 10 ) ;
* V_66 = V_71 ;
V_73:
free ( V_68 ) ;
}
static void F_41 ( int * V_66 , const char * V_67 )
{
int V_71 = 0 ;
F_39 ( & V_71 , V_67 ) ;
if ( V_71 >= 0 && V_71 <= 100 )
* V_66 = V_71 ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_67 )
{
char * V_68 = malloc ( 0 ) , * V_69 ;
struct V_9 * V_74 = V_2 -> V_25 , * V_75 , * V_76 = NULL ;
struct V_43 * V_43 = F_29 ( V_2 -> V_48 ) ;
struct V_77 * V_78 ;
T_5 V_70 = 0 ;
if ( V_74 ) {
F_13 ( V_74 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_67 ) ;
if ( F_40 ( & V_68 , & V_70 , V_72 ) < 0 )
goto V_73;
V_69 = strchr ( V_68 , '\n' ) ;
if ( V_69 )
* V_69 = 0 ;
V_78 = F_43 ( & V_43 -> V_79 ) ;
while ( V_78 ) {
V_75 = F_44 ( V_78 , struct V_9 , V_77 ) ;
if ( V_75 -> V_17 . V_12 && ! strcmp ( V_68 , V_75 -> V_17 . V_12 -> V_21 ) ) {
V_76 = V_75 ;
break;
}
V_78 = F_45 ( & V_75 -> V_77 ) ;
}
if ( ! V_76 ) {
fprintf ( V_80 , L_25 , V_68 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_76 ) ;
V_73:
free ( V_68 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_81 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_82 -> V_83 > 1 )
fprintf ( stdout , L_29 , F_24 ( V_2 -> V_48 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_84 ) ;
fprintf ( stdout , L_31 , V_2 -> V_49 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_64 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_63 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_50 ? 1 : 0 ) ;
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
return V_2 -> V_82 -> V_83 > 1 ? 1 : 0 ;
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
V_85 = getc ( V_72 ) ;
F_51 ( 0 , V_94 , & V_93 ) ;
if ( ! F_47 ( V_2 , V_85 ) )
return V_86 ;
}
switch ( V_85 ) {
case 'd' :
F_39 ( & V_2 -> V_81 , L_42 ) ;
if ( V_2 -> V_81 < 1 )
V_2 -> V_81 = 1 ;
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
if ( V_2 -> V_82 -> V_83 > 1 ) {
int V_41 = 0 ;
fprintf ( V_80 , L_44 ) ;
F_52 (top->evlist, top->sym_evsel)
fprintf ( V_80 , L_45 , V_2 -> V_48 -> V_51 , F_24 ( V_2 -> V_48 ) ) ;
F_39 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_82 -> V_83 ) {
V_2 -> V_48 = F_53 ( V_2 -> V_82 ) ;
fprintf ( V_80 , L_47 , F_24 ( V_2 -> V_48 ) ) ;
F_7 ( 1 ) ;
break;
}
F_52 (top->evlist, top->sym_evsel)
if ( V_2 -> V_48 -> V_51 == V_41 )
break;
} else
V_2 -> V_48 = F_53 ( V_2 -> V_82 ) ;
break;
case 'f' :
F_39 ( & V_2 -> V_84 , L_48 ) ;
break;
case 'F' :
F_41 ( & V_2 -> V_49 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_64 = ! V_2 -> V_64 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_102 )
F_54 ( V_2 -> V_103 , V_80 ) ;
V_86 = false ;
break;
case 's' :
F_42 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_74 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_74 ) ;
}
break;
case 'U' :
V_2 -> V_63 = ! V_2 -> V_63 ;
break;
case 'z' :
V_2 -> V_50 = ! V_2 -> V_50 ;
break;
default:
break;
}
return V_86 ;
}
static void F_55 ( void * V_8 )
{
struct V_1 * V_104 = V_8 ;
struct V_43 * V_43 ;
F_31 ( V_104 ) ;
if ( V_104 -> V_82 -> V_105 != NULL )
V_104 -> V_48 = V_104 -> V_82 -> V_105 ;
V_43 = F_29 ( V_104 -> V_48 ) ;
if ( V_104 -> V_50 ) {
F_33 ( V_43 ) ;
} else {
F_34 ( V_43 , V_104 -> V_63 ,
V_104 -> V_64 ) ;
}
F_35 ( V_43 , NULL ) ;
F_36 ( V_43 , NULL ) ;
}
static void * F_56 ( void * V_8 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 = V_8 ;
const char * V_108 = L_52 ;
struct V_109 V_110 = {
. V_111 = F_55 ,
. V_8 = V_2 ,
. V_112 = V_2 -> V_81 ,
} ;
F_55 ( V_2 ) ;
F_52 (top->evlist, pos) {
struct V_43 * V_43 = F_29 ( V_107 ) ;
V_43 -> V_113 = V_2 -> V_114 . V_66 . V_115 ;
}
F_57 ( V_2 -> V_82 , V_108 , & V_110 , V_2 -> V_65 ,
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
signal ( V_119 , F_58 ) ;
signal ( V_120 , F_58 ) ;
signal ( V_121 , F_58 ) ;
signal ( V_122 , F_58 ) ;
signal ( V_123 , F_58 ) ;
}
static void * F_60 ( void * V_8 )
{
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 ;
struct V_1 * V_2 = V_8 ;
int V_124 , V_85 ;
F_59 () ;
F_61 () ;
V_125:
V_124 = V_2 -> V_81 * 1000 ;
F_49 ( & V_93 ) ;
getc ( V_72 ) ;
while ( ! V_118 ) {
F_28 ( V_2 ) ;
switch ( F_50 ( & V_88 , 1 , V_124 ) ) {
case 0 :
continue;
case - 1 :
if ( V_126 == V_127 )
continue;
default:
V_85 = getc ( V_72 ) ;
F_51 ( 0 , V_94 , & V_93 ) ;
if ( F_48 ( V_2 , V_85 ) )
goto V_125;
V_118 = 1 ;
}
}
F_51 ( 0 , V_94 , & V_93 ) ;
return NULL ;
}
static int F_62 ( struct V_15 * V_15 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
if ( ! V_15 -> V_18 -> V_128 )
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
V_12 -> V_129 = true ;
return 0 ;
}
static int F_64 ( struct V_130 * V_131 ,
struct V_132 * V_133 , bool V_134 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_131 -> V_10 ;
struct V_106 * V_135 = V_131 -> V_135 ;
if ( V_136 && V_134 ) {
T_4 V_26 = V_133 -> V_137 ;
if ( V_133 -> V_15 )
V_26 = V_133 -> V_15 -> V_138 ( V_133 -> V_15 , V_26 ) ;
F_19 ( V_2 , V_10 , V_135 -> V_51 , V_26 ) ;
}
return 0 ;
}
static void F_65 ( struct V_139 * V_140 ,
const union V_141 * V_142 ,
struct V_106 * V_135 ,
struct V_143 * V_144 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_66 ( V_140 , struct V_1 , V_140 ) ;
struct V_132 V_133 ;
int V_16 ;
if ( ! V_36 && V_145 ) {
static struct V_146 * V_147 ;
if ( ! V_147 )
V_147 = F_67 ( NULL ) ;
if ( ! F_68 ( V_147 , V_144 -> V_148 ) ) {
F_6 ( L_60 ,
V_144 -> V_148 ) ;
F_69 ( V_147 , V_144 -> V_148 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_103 -> V_82 -> V_58 . V_149 ++ ) ;
return;
}
if ( V_142 -> V_116 . V_150 & V_151 )
V_2 -> V_152 ++ ;
if ( F_70 ( V_142 , V_36 , & V_133 , V_144 ) < 0 )
return;
if ( ! V_2 -> V_153 &&
V_154 . V_155 &&
V_133 . V_156 == V_157 ) {
F_17 (
L_62
L_63
L_64 ,
V_133 . V_15 && ! F_71 ( & V_133 . V_15 -> V_18 -> V_158 [ V_159 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_153 = true ;
}
if ( V_133 . V_12 == NULL ) {
const char * V_67 = L_67 ;
if ( ! V_2 -> V_153 && ! V_2 -> V_160 &&
V_133 . V_15 == V_36 -> V_161 [ V_159 ] &&
F_71 ( & V_133 . V_15 -> V_18 -> V_158 [ V_159 ] ) ) {
if ( V_154 . V_162 ) {
char V_163 [ 256 ] ;
F_72 ( V_133 . V_15 -> V_18 , V_163 , sizeof( V_163 ) ) ;
F_17 ( L_68 ,
V_154 . V_162 , V_163 , V_67 ) ;
} else {
F_17 ( L_69 ,
V_67 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_160 = true ;
}
}
if ( V_133 . V_12 == NULL || ! V_133 . V_12 -> V_129 ) {
struct V_43 * V_43 = F_29 ( V_135 ) ;
struct V_130 V_131 = {
. V_164 = F_64 ,
} ;
if ( V_154 . V_165 )
V_131 . V_166 = & V_167 ;
else
V_131 . V_166 = & V_168 ;
F_9 ( & V_43 -> V_23 ) ;
V_16 = F_73 ( & V_131 , & V_133 , V_135 , V_144 ,
V_2 -> V_169 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_43 -> V_23 ) ;
}
return;
}
static void F_74 ( struct V_1 * V_2 , int V_51 )
{
struct V_143 V_144 ;
struct V_106 * V_135 ;
struct V_170 * V_103 = V_2 -> V_103 ;
union V_141 * V_142 ;
struct V_36 * V_36 ;
T_6 V_171 ;
int V_86 ;
while ( ( V_142 = F_75 ( V_2 -> V_82 , V_51 ) ) != NULL ) {
V_86 = F_76 ( V_2 -> V_82 , V_142 , & V_144 ) ;
if ( V_86 ) {
F_6 ( L_71 , V_86 ) ;
goto V_172;
}
V_135 = F_77 ( V_103 -> V_82 , V_144 . V_173 ) ;
assert ( V_135 != NULL ) ;
V_171 = V_142 -> V_116 . V_150 & V_174 ;
if ( V_142 -> V_116 . type == V_175 )
++ V_2 -> V_176 ;
switch ( V_171 ) {
case V_177 :
++ V_2 -> V_178 ;
if ( V_2 -> V_63 )
goto V_172;
V_36 = & V_103 -> V_179 . V_180 ;
break;
case V_157 :
++ V_2 -> V_181 ;
if ( V_2 -> V_64 )
goto V_172;
V_36 = & V_103 -> V_179 . V_180 ;
break;
case V_182 :
++ V_2 -> V_183 ;
V_36 = F_78 ( V_103 ,
V_144 . V_148 ) ;
break;
case V_184 :
++ V_2 -> V_185 ;
default:
goto V_172;
}
if ( V_142 -> V_116 . type == V_175 ) {
F_65 ( & V_2 -> V_140 , V_142 , V_135 ,
& V_144 , V_36 ) ;
} else if ( V_142 -> V_116 . type < V_186 ) {
F_79 ( F_29 ( V_135 ) , V_142 -> V_116 . type ) ;
F_80 ( V_36 , V_142 , & V_144 ) ;
} else
++ V_103 -> V_82 -> V_58 . V_187 ;
V_172:
F_81 ( V_2 -> V_82 , V_51 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
int V_188 ;
for ( V_188 = 0 ; V_188 < V_2 -> V_82 -> V_189 ; V_188 ++ )
F_74 ( V_2 , V_188 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
char V_67 [ 512 ] ;
struct V_106 * V_41 ;
struct V_190 * V_82 = V_2 -> V_82 ;
struct V_114 * V_191 = & V_2 -> V_114 ;
F_84 ( V_82 , V_191 ) ;
F_52 (evlist, counter) {
V_192:
if ( F_85 ( V_41 , V_2 -> V_82 -> V_193 ,
V_2 -> V_82 -> V_194 ) < 0 ) {
if ( F_86 ( V_41 , V_126 , V_67 , sizeof( V_67 ) ) ) {
if ( V_195 )
F_17 ( L_21 , V_67 ) ;
goto V_192;
}
F_87 ( V_41 , & V_191 -> V_66 ,
V_126 , V_67 , sizeof( V_67 ) ) ;
F_88 ( L_21 , V_67 ) ;
goto V_196;
}
}
if ( F_89 ( V_82 , V_191 -> V_197 , false ) < 0 ) {
F_88 ( L_72 ,
V_126 , F_90 ( V_126 , V_67 , sizeof( V_67 ) ) ) ;
goto V_196;
}
return 0 ;
V_196:
return - 1 ;
}
static int F_91 ( struct V_1 * V_2 V_7 )
{
if ( ! V_136 ) {
if ( V_154 . V_198 ) {
F_88 ( L_73 ) ;
return - V_199 ;
}
} else if ( V_200 . V_201 != V_202 ) {
if ( F_92 ( & V_200 ) < 0 ) {
F_88 ( L_74 ) ;
return - V_199 ;
}
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_114 * V_191 = & V_2 -> V_114 ;
T_7 V_203 ;
int V_86 ;
V_2 -> V_103 = F_94 ( NULL , false , NULL ) ;
if ( V_2 -> V_103 == NULL )
return - 1 ;
F_95 ( & V_2 -> V_103 -> V_179 , F_62 ) ;
if ( ! V_204 ) {
V_86 = F_96 ( & V_2 -> V_103 -> V_116 . V_117 ) ;
if ( V_86 )
goto V_205;
}
V_86 = F_91 ( V_2 ) ;
if ( V_86 )
goto V_205;
F_97 ( & V_2 -> V_103 -> V_179 . V_180 , & V_191 -> V_66 ,
V_2 -> V_82 -> V_194 , false ) ;
V_86 = F_83 ( V_2 ) ;
if ( V_86 )
goto V_205;
V_2 -> V_103 -> V_82 = V_2 -> V_82 ;
F_98 ( V_2 -> V_103 ) ;
if ( ! F_99 ( & V_191 -> V_66 ) )
F_100 ( V_2 -> V_82 ) ;
F_101 ( V_2 -> V_82 , 100 ) ;
F_82 ( V_2 ) ;
V_86 = - 1 ;
if ( F_102 ( & V_203 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_88 ( L_75 ) ;
goto V_205;
}
if ( V_2 -> V_206 ) {
struct V_207 V_208 ;
V_208 . V_209 = V_2 -> V_206 ;
if ( F_103 ( 0 , V_210 , & V_208 ) ) {
F_88 ( L_76 ) ;
goto V_211;
}
}
while ( ! V_118 ) {
T_4 V_212 = V_2 -> V_176 ;
F_82 ( V_2 ) ;
if ( V_212 == V_2 -> V_176 )
V_86 = F_101 ( V_2 -> V_82 , 100 ) ;
}
V_86 = 0 ;
V_211:
F_104 ( V_203 , NULL ) ;
V_205:
F_105 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
return V_86 ;
}
static int
F_106 ( const struct V_213 * V_214 , const char * V_8 , int V_215 )
{
V_154 . V_198 = true ;
return F_107 ( V_214 , V_8 , V_215 ) ;
}
static int
F_108 ( const struct V_213 * V_214 , const char * V_8 , int V_215 )
{
V_154 . V_198 = true ;
return F_109 ( V_214 , V_8 , V_215 ) ;
}
static int F_110 ( const char * V_216 , const char * V_217 , void * V_218 )
{
if ( ! strcmp ( V_216 , L_77 ) )
V_216 = L_78 ;
if ( ! strcmp ( V_216 , L_79 ) ) {
V_154 . V_165 = F_111 ( V_216 , V_217 ) ;
return 0 ;
}
return F_112 ( V_216 , V_217 , V_218 ) ;
}
static int
F_113 ( const struct V_213 * V_214 , const char * V_8 ,
int V_215 V_7 )
{
struct V_1 * V_2 = V_214 -> V_217 ;
V_2 -> V_65 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_114 ( int V_219 , const char * * V_220 , const char * T_8 V_7 )
{
char V_221 [ V_222 ] ;
struct V_1 V_2 = {
. V_84 = 5 ,
. V_81 = 2 ,
. V_114 = {
. V_197 = V_223 ,
. V_224 = V_223 ,
. V_225 = V_226 ,
. V_227 = 4000 ,
. V_66 = {
. V_228 = true ,
} ,
} ,
. V_169 = V_229 ,
. V_49 = 5 ,
} ;
struct V_114 * V_191 = & V_2 . V_114 ;
struct V_66 * V_66 = & V_191 -> V_66 ;
const struct V_213 V_230 [] = {
F_115 ( 'e' , L_80 , & V_2 . V_82 , L_80 ,
L_81 ,
V_231 ) ,
F_116 ( 'c' , L_82 , & V_191 -> V_225 , L_83 ) ,
F_117 ( 'p' , L_84 , & V_66 -> V_148 , L_84 ,
L_85 ) ,
F_117 ( 't' , L_86 , & V_66 -> V_232 , L_86 ,
L_87 ) ,
F_118 ( 'a' , L_88 , & V_66 -> V_233 ,
L_89 ) ,
F_117 ( 'C' , L_90 , & V_66 -> V_234 , L_90 ,
L_91 ) ,
F_117 ( 'k' , L_92 , & V_154 . V_162 ,
L_93 , L_94 ) ,
F_118 ( 0 , L_95 , & V_154 . V_235 ,
L_96 ) ,
F_118 ( 'K' , L_97 , & V_2 . V_64 ,
L_98 ) ,
F_115 ( 'm' , L_99 , & V_191 -> V_197 , L_100 ,
L_101 ,
V_236 ) ,
F_119 ( 'r' , L_102 , & V_2 . V_206 ,
L_103 ) ,
F_119 ( 'd' , L_104 , & V_2 . V_81 ,
L_105 ) ,
F_118 ( 'D' , L_106 , & V_2 . V_102 ,
L_107 ) ,
F_119 ( 'f' , L_108 , & V_2 . V_84 ,
L_109 ) ,
F_118 ( 0 , L_110 , & V_191 -> V_237 ,
L_111 ) ,
F_118 ( 'i' , L_112 , & V_191 -> V_238 ,
L_113 ) ,
F_117 ( 0 , L_114 , & V_2 . V_239 , L_115 ,
L_116 ) ,
F_118 ( 'z' , L_117 , & V_2 . V_50 , L_118 ) ,
F_120 ( 'F' , L_119 , & V_191 -> V_224 , L_120 ) ,
F_119 ( 'E' , L_121 , & V_2 . V_3 ,
L_122 ) ,
F_118 ( 'U' , L_123 , & V_2 . V_63 ,
L_124 ) ,
F_118 ( 0 , L_125 , & V_2 . V_240 , L_126 ) ,
F_118 ( 0 , L_127 , & V_2 . V_241 , L_128 ) ,
F_121 ( 'v' , L_129 , & V_195 ,
L_130 ) ,
F_117 ( 's' , L_131 , & V_242 , L_132 ,
L_133
L_134 ) ,
F_117 ( 0 , L_135 , & V_243 , L_136 ,
L_137 ) ,
F_118 ( 'n' , L_138 , & V_154 . V_244 ,
L_139 ) ,
F_122 ( 'g' , NULL , & V_2 . V_114 ,
NULL , L_140 ,
& F_106 ) ,
F_115 ( 0 , L_141 , & V_2 . V_114 ,
L_142 , V_245 ,
& F_108 ) ,
F_118 ( 0 , L_143 , & V_154 . V_165 ,
L_144 ) ,
F_119 ( 0 , L_145 , & V_2 . V_169 ,
L_146
L_147 F_123 ( V_229 ) ) ,
F_115 ( 0 , L_148 , NULL , L_149 ,
L_150 ,
V_246 ) ,
F_118 ( 0 , L_151 , & V_154 . V_247 ,
L_152 ) ,
F_117 ( 0 , L_153 , & V_154 . V_248 , L_154 ,
L_155 ) ,
F_117 ( 0 , L_156 , & V_154 . V_249 , L_157 ,
L_158 ) ,
F_117 ( 0 , L_159 , & V_154 . V_250 , L_160 ,
L_161 ) ,
F_118 ( 0 , L_162 , & V_154 . V_251 ,
L_163 ) ,
F_118 ( 0 , L_164 , & V_154 . V_252 ,
L_165 ) ,
F_118 ( 0 , L_166 , & V_154 . V_253 ,
L_167 ) ,
F_117 ( 0 , L_168 , & V_204 , L_169 ,
L_170 ) ,
F_117 ( 'M' , L_171 , & V_254 , L_172 ,
L_173 ) ,
F_117 ( 'u' , L_174 , & V_66 -> V_115 , L_175 , L_176 ) ,
F_115 ( 0 , L_177 , & V_2 , L_178 ,
L_179 , F_113 ) ,
F_115 ( 0 , L_180 , NULL , L_181 ,
L_182 , V_255 ) ,
F_117 ( 'w' , L_183 , & V_154 . V_256 ,
L_184 ,
L_185 ) ,
F_124 ()
} ;
const char * const V_257 [] = {
L_186 ,
NULL
} ;
int V_258 = F_125 () ;
if ( V_258 < 0 )
return V_258 ;
V_2 . V_82 = F_126 () ;
if ( V_2 . V_82 == NULL )
return - V_45 ;
F_127 ( F_110 , & V_2 ) ;
V_219 = F_128 ( V_219 , V_220 , V_230 , V_257 , 0 ) ;
if ( V_219 )
F_129 ( V_257 , V_230 ) ;
V_259 = V_260 ;
V_261 = 1 ;
if ( F_130 () < 0 ) {
if ( V_242 )
F_131 ( V_257 , V_230 , L_187 , 1 ) ;
if ( V_243 )
F_131 ( V_242 ? NULL : V_257 ,
V_230 , L_135 , 0 ) ;
goto V_262;
}
if ( V_2 . V_241 )
V_39 = 0 ;
else if ( V_2 . V_240 )
V_39 = 1 ;
F_132 ( false ) ;
V_258 = F_133 ( V_66 ) ;
if ( V_258 ) {
F_134 ( V_66 , V_258 , V_221 , V_222 ) ;
F_17 ( L_21 , V_221 ) ;
}
V_258 = F_135 ( V_66 ) ;
if ( V_258 ) {
int V_263 = V_126 ;
F_134 ( V_66 , V_258 , V_221 , V_222 ) ;
F_88 ( L_21 , V_221 ) ;
V_258 = - V_263 ;
goto V_262;
}
if ( F_99 ( V_66 ) )
V_66 -> V_233 = true ;
if ( F_136 ( V_2 . V_82 , V_66 ) < 0 )
F_129 ( V_257 , V_230 ) ;
if ( ! V_2 . V_82 -> V_83 &&
F_137 ( V_2 . V_82 ) < 0 ) {
F_88 ( L_188 ) ;
goto V_262;
}
V_154 . V_60 = V_2 . V_82 -> V_83 ;
if ( V_2 . V_81 < 1 )
V_2 . V_81 = 1 ;
if ( F_138 ( V_191 ) ) {
V_258 = - V_199 ;
goto V_262;
}
V_2 . V_48 = F_53 ( V_2 . V_82 ) ;
if ( ! V_154 . V_198 ) {
V_154 . V_165 = false ;
F_139 () ;
}
V_154 . V_264 = sizeof( struct V_13 ) ;
V_154 . V_265 = ( V_154 . V_162 == NULL ) ;
if ( F_140 ( NULL ) < 0 )
return - 1 ;
F_141 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_2 ,
. V_98 = V_99 ,
} ;
F_1 ( & V_2 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
}
V_258 = F_93 ( & V_2 ) ;
V_262:
F_142 ( V_2 . V_82 ) ;
return V_258 ;
}
