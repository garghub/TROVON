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
struct V_57 * V_58 = V_2 -> V_47 ;
struct V_42 * V_42 = F_29 ( V_58 ) ;
puts ( V_59 ) ;
F_30 ( V_2 , V_53 , sizeof( V_53 ) ) ;
printf ( L_21 , V_53 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_55 , V_55 , V_60 ) ;
if ( V_42 -> V_61 . V_62 !=
V_42 -> V_61 . V_63 [ V_64 ] ) {
V_42 -> V_61 . V_62 =
V_42 -> V_61 . V_63 [ V_64 ] ;
F_32 ( stdout , V_65 ,
L_23 ,
V_42 -> V_61 . V_62 ) ;
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
F_34 ( V_42 , V_2 -> V_66 ,
V_2 -> V_67 ) ;
}
}
F_35 ( V_42 , NULL ) ;
F_36 ( V_58 , NULL ) ;
F_37 ( V_42 , V_2 -> V_3 - V_54 ) ;
putchar ( '\n' ) ;
F_38 ( V_42 , false , V_2 -> V_3 - V_54 , V_55 ,
V_2 -> V_68 , stdout ) ;
}
static void F_39 ( int * V_69 , const char * V_70 )
{
char * V_71 = malloc ( 0 ) , * V_72 ;
T_5 V_73 = 0 ;
int V_74 ;
fprintf ( stdout , L_24 , V_70 ) ;
if ( F_40 ( & V_71 , & V_73 , V_75 ) < 0 )
return;
V_72 = strchr ( V_71 , '\n' ) ;
if ( V_72 )
* V_72 = 0 ;
V_72 = V_71 ;
while( * V_72 ) {
if ( ! isdigit ( * V_72 ) )
goto V_76;
V_72 ++ ;
}
V_74 = strtoul ( V_71 , NULL , 10 ) ;
* V_69 = V_74 ;
V_76:
free ( V_71 ) ;
}
static void F_41 ( int * V_69 , const char * V_70 )
{
int V_74 = 0 ;
F_39 ( & V_74 , V_70 ) ;
if ( V_74 >= 0 && V_74 <= 100 )
* V_69 = V_74 ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_70 )
{
char * V_71 = malloc ( 0 ) , * V_72 ;
struct V_9 * V_77 = V_2 -> V_25 , * V_78 , * V_79 = NULL ;
struct V_42 * V_42 = F_29 ( V_2 -> V_47 ) ;
struct V_80 * V_81 ;
T_5 V_73 = 0 ;
if ( V_77 ) {
F_13 ( V_77 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_70 ) ;
if ( F_40 ( & V_71 , & V_73 , V_75 ) < 0 )
goto V_76;
V_72 = strchr ( V_71 , '\n' ) ;
if ( V_72 )
* V_72 = 0 ;
V_81 = F_43 ( & V_42 -> V_82 ) ;
while ( V_81 ) {
V_78 = F_44 ( V_81 , struct V_9 , V_80 ) ;
if ( V_78 -> V_17 . V_12 && ! strcmp ( V_71 , V_78 -> V_17 . V_12 -> V_21 ) ) {
V_79 = V_78 ;
break;
}
V_81 = F_45 ( & V_78 -> V_80 ) ;
}
if ( ! V_79 ) {
fprintf ( V_83 , L_25 , V_71 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_79 ) ;
V_76:
free ( V_71 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_84 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_49 -> V_85 > 1 )
fprintf ( stdout , L_29 , F_24 ( V_2 -> V_47 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_86 ) ;
fprintf ( stdout , L_31 , V_2 -> V_48 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_67 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_66 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_51 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_87 )
{
switch ( V_87 ) {
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
return V_2 -> V_49 -> V_85 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_48 ( struct V_1 * V_2 , int V_87 )
{
bool V_88 = true ;
if ( ! F_47 ( V_2 , V_87 ) ) {
struct V_89 V_90 = { . V_91 = 0 , . V_92 = V_93 } ;
struct V_94 V_95 ;
F_46 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_49 ( & V_95 ) ;
F_50 ( & V_90 , 1 , - 1 ) ;
V_87 = getc ( V_75 ) ;
F_51 ( 0 , V_96 , & V_95 ) ;
if ( ! F_47 ( V_2 , V_87 ) )
return V_88 ;
}
switch ( V_87 ) {
case 'd' :
F_39 ( & V_2 -> V_84 , L_42 ) ;
if ( V_2 -> V_84 < 1 )
V_2 -> V_84 = 1 ;
break;
case 'e' :
F_39 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_97 V_98 = {
. V_99 = F_2 ,
. V_100 = V_101 ,
} ;
F_2 ( V_102 , NULL , V_2 ) ;
V_97 ( V_102 , & V_98 , NULL ) ;
} else {
signal ( V_102 , V_103 ) ;
}
break;
case 'E' :
if ( V_2 -> V_49 -> V_85 > 1 ) {
int V_41 = 0 ;
fprintf ( V_83 , L_44 ) ;
F_52 (top->evlist, top->sym_evsel)
fprintf ( V_83 , L_45 , V_2 -> V_47 -> V_52 , F_24 ( V_2 -> V_47 ) ) ;
F_39 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_49 -> V_85 ) {
V_2 -> V_47 = F_53 ( V_2 -> V_49 ) ;
fprintf ( V_83 , L_47 , F_24 ( V_2 -> V_47 ) ) ;
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
F_39 ( & V_2 -> V_86 , L_48 ) ;
break;
case 'F' :
F_41 ( & V_2 -> V_48 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_67 = ! V_2 -> V_67 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_104 )
F_54 ( V_2 -> V_105 , V_83 ) ;
V_88 = false ;
break;
case 's' :
F_42 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_77 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_77 ) ;
}
break;
case 'U' :
V_2 -> V_66 = ! V_2 -> V_66 ;
break;
case 'z' :
V_2 -> V_51 = ! V_2 -> V_51 ;
break;
default:
break;
}
return V_88 ;
}
static void F_55 ( void * V_8 )
{
struct V_1 * V_106 = V_8 ;
struct V_57 * V_58 = V_106 -> V_47 ;
struct V_42 * V_42 ;
F_31 ( V_106 ) ;
if ( V_106 -> V_49 -> V_107 != NULL )
V_106 -> V_47 = V_106 -> V_49 -> V_107 ;
V_42 = F_29 ( V_58 ) ;
if ( V_106 -> V_49 -> V_50 ) {
if ( V_106 -> V_51 ) {
F_33 ( V_42 ) ;
} else {
F_34 ( V_42 , V_106 -> V_66 ,
V_106 -> V_67 ) ;
}
}
F_35 ( V_42 , NULL ) ;
F_36 ( V_58 , NULL ) ;
}
static void * F_56 ( void * V_8 )
{
struct V_57 * V_108 ;
struct V_1 * V_2 = V_8 ;
const char * V_109 = L_52 ;
struct V_110 V_111 = {
. V_112 = F_55 ,
. V_8 = V_2 ,
. V_113 = V_2 -> V_84 ,
} ;
F_55 ( V_2 ) ;
F_52 (top->evlist, pos) {
struct V_42 * V_42 = F_29 ( V_108 ) ;
V_42 -> V_114 = V_2 -> V_115 . V_69 . V_116 ;
}
F_57 ( V_2 -> V_49 , V_109 , & V_111 ,
V_2 -> V_68 ,
& V_2 -> V_105 -> V_117 . V_118 ) ;
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
struct V_89 V_90 = { . V_91 = 0 , . V_92 = V_93 } ;
struct V_94 V_95 ;
struct V_1 * V_2 = V_8 ;
int V_126 , V_87 ;
F_59 () ;
F_61 () ;
V_127:
V_126 = V_2 -> V_84 * 1000 ;
F_49 ( & V_95 ) ;
getc ( V_75 ) ;
while ( ! V_119 ) {
F_28 ( V_2 ) ;
switch ( F_50 ( & V_90 , 1 , V_126 ) ) {
case 0 :
continue;
case - 1 :
if ( V_128 == V_129 )
continue;
default:
V_87 = getc ( V_75 ) ;
F_51 ( 0 , V_96 , & V_95 ) ;
if ( F_48 ( V_2 , V_87 ) )
goto V_127;
V_119 = 1 ;
}
}
F_51 ( 0 , V_96 , & V_95 ) ;
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
struct V_57 * V_58 = V_132 -> V_58 ;
if ( V_136 && V_135 )
F_19 ( V_2 , V_10 , V_58 -> V_52 , V_134 -> V_137 ) ;
F_66 ( V_132 -> V_138 -> V_139 , V_134 , V_132 -> V_138 ,
! ( V_2 -> V_115 . V_139 & V_140 ) ) ;
return 0 ;
}
static void F_67 ( struct V_141 * V_142 ,
const union V_143 * V_144 ,
struct V_57 * V_58 ,
struct V_145 * V_138 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_68 ( V_142 , struct V_1 , V_142 ) ;
struct V_133 V_134 ;
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
V_2 -> V_105 -> V_49 -> V_61 . V_150 ++ ) ;
return;
}
if ( V_144 -> V_117 . V_151 & V_152 )
V_2 -> V_153 ++ ;
if ( F_72 ( V_36 , & V_134 , V_138 ) < 0 )
return;
if ( ! V_2 -> V_154 &&
V_155 . V_156 &&
V_134 . V_157 == V_158 ) {
F_17 (
L_62
L_63
L_64 ,
V_134 . V_15 && ! F_73 ( & V_134 . V_15 -> V_18 -> V_159 [ V_160 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_154 = true ;
}
if ( V_134 . V_12 == NULL ) {
const char * V_70 = L_67 ;
if ( ! V_2 -> V_154 && ! V_2 -> V_161 &&
V_134 . V_15 == V_36 -> V_162 [ V_160 ] &&
F_73 ( & V_134 . V_15 -> V_18 -> V_159 [ V_160 ] ) ) {
if ( V_155 . V_163 ) {
char V_164 [ 256 ] ;
F_74 ( V_134 . V_15 -> V_18 , V_164 , sizeof( V_164 ) ) ;
F_17 ( L_68 ,
V_155 . V_163 , V_164 , V_70 ) ;
} else {
F_17 ( L_69 ,
V_70 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_161 = true ;
}
}
if ( V_134 . V_12 == NULL || ! V_134 . V_12 -> V_130 ) {
struct V_42 * V_42 = F_29 ( V_58 ) ;
struct V_131 V_132 = {
. V_58 = V_58 ,
. V_138 = V_138 ,
. V_165 = F_65 ,
} ;
if ( V_155 . V_166 )
V_132 . V_167 = & V_168 ;
else
V_132 . V_167 = & V_169 ;
F_9 ( & V_42 -> V_23 ) ;
V_16 = F_75 ( & V_132 , & V_134 , V_2 -> V_170 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_42 -> V_23 ) ;
}
F_76 ( & V_134 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_52 )
{
struct V_145 V_138 ;
struct V_57 * V_58 ;
struct V_171 * V_105 = V_2 -> V_105 ;
union V_143 * V_144 ;
struct V_36 * V_36 ;
int V_88 ;
while ( ( V_144 = F_78 ( V_2 -> V_49 , V_52 ) ) != NULL ) {
V_88 = F_79 ( V_2 -> V_49 , V_144 , & V_138 ) ;
if ( V_88 ) {
F_6 ( L_71 , V_88 ) ;
goto V_172;
}
V_58 = F_80 ( V_105 -> V_49 , V_138 . V_173 ) ;
assert ( V_58 != NULL ) ;
if ( V_144 -> V_117 . type == V_174 )
++ V_2 -> V_175 ;
switch ( V_138 . V_157 ) {
case V_176 :
++ V_2 -> V_177 ;
if ( V_2 -> V_66 )
goto V_172;
V_36 = & V_105 -> V_178 . V_179 ;
break;
case V_158 :
++ V_2 -> V_180 ;
if ( V_2 -> V_67 )
goto V_172;
V_36 = & V_105 -> V_178 . V_179 ;
break;
case V_181 :
++ V_2 -> V_182 ;
V_36 = F_81 ( V_105 ,
V_138 . V_149 ) ;
break;
case V_183 :
++ V_2 -> V_184 ;
goto V_172;
default:
if ( V_144 -> V_117 . type == V_174 )
goto V_172;
V_36 = & V_105 -> V_178 . V_179 ;
break;
}
if ( V_144 -> V_117 . type == V_174 ) {
F_67 ( & V_2 -> V_142 , V_144 , V_58 ,
& V_138 , V_36 ) ;
} else if ( V_144 -> V_117 . type < V_185 ) {
F_82 ( F_29 ( V_58 ) , V_144 -> V_117 . type ) ;
F_83 ( V_36 , V_144 , & V_138 ) ;
} else
++ V_105 -> V_49 -> V_61 . V_186 ;
V_172:
F_84 ( V_2 -> V_49 , V_52 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
int V_187 ;
for ( V_187 = 0 ; V_187 < V_2 -> V_49 -> V_188 ; V_187 ++ )
F_77 ( V_2 , V_187 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
char V_70 [ 512 ] ;
struct V_57 * V_41 ;
struct V_189 * V_49 = V_2 -> V_49 ;
struct V_115 * V_190 = & V_2 -> V_115 ;
F_87 ( V_49 , V_190 ) ;
F_52 (evlist, counter) {
V_191:
if ( F_88 ( V_41 , V_2 -> V_49 -> V_192 ,
V_2 -> V_49 -> V_193 ) < 0 ) {
if ( F_89 ( V_41 , V_128 , V_70 , sizeof( V_70 ) ) ) {
if ( V_194 )
F_17 ( L_21 , V_70 ) ;
goto V_191;
}
F_90 ( V_41 , & V_190 -> V_69 ,
V_128 , V_70 , sizeof( V_70 ) ) ;
F_91 ( L_21 , V_70 ) ;
goto V_195;
}
}
if ( F_92 ( V_49 , V_190 -> V_196 , false ) < 0 ) {
F_91 ( L_72 ,
V_128 , F_93 ( V_128 , V_70 , sizeof( V_70 ) ) ) ;
goto V_195;
}
return 0 ;
V_195:
return - 1 ;
}
static int F_94 ( struct V_1 * V_2 V_7 )
{
if ( ! V_136 ) {
if ( V_155 . V_197 ) {
F_91 ( L_73 ) ;
return - V_198 ;
}
} else if ( V_199 . V_200 != V_201 ) {
if ( F_95 ( & V_199 ) < 0 ) {
F_91 ( L_74 ) ;
return - V_198 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_115 * V_190 = & V_2 -> V_115 ;
T_6 V_202 ;
int V_88 ;
V_2 -> V_105 = F_97 ( NULL , false , NULL ) ;
if ( V_2 -> V_105 == NULL )
return - 1 ;
F_98 ( & V_2 -> V_105 -> V_178 , F_62 ) ;
if ( ! V_203 ) {
V_88 = F_99 ( & V_2 -> V_105 -> V_117 . V_118 ) ;
if ( V_88 )
goto V_204;
}
V_88 = F_94 ( V_2 ) ;
if ( V_88 )
goto V_204;
if ( F_100 ( V_2 -> V_105 ) < 0 )
goto V_204;
F_101 ( & V_2 -> V_105 -> V_178 . V_179 , & V_190 -> V_69 ,
V_2 -> V_49 -> V_193 , false , V_190 -> V_205 ) ;
if ( V_206 ) {
V_88 = F_102 ( & V_207 ) ;
if ( V_88 < 0 )
goto V_208;
}
V_88 = F_86 ( V_2 ) ;
if ( V_88 )
goto V_204;
V_2 -> V_105 -> V_49 = V_2 -> V_49 ;
F_103 ( V_2 -> V_105 ) ;
if ( ! F_104 ( & V_190 -> V_69 ) )
F_105 ( V_2 -> V_49 ) ;
F_106 ( V_2 -> V_49 , 100 ) ;
F_85 ( V_2 ) ;
V_88 = - 1 ;
if ( F_107 ( & V_202 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_91 ( L_75 ) ;
goto V_204;
}
if ( V_2 -> V_209 ) {
struct V_210 V_211 ;
V_211 . V_212 = V_2 -> V_209 ;
if ( F_108 ( 0 , V_213 , & V_211 ) ) {
F_91 ( L_76 ) ;
goto V_214;
}
}
while ( ! V_119 ) {
T_4 V_215 = V_2 -> V_175 ;
F_85 ( V_2 ) ;
if ( V_215 == V_2 -> V_175 )
V_88 = F_106 ( V_2 -> V_49 , 100 ) ;
}
V_88 = 0 ;
V_214:
F_109 ( V_202 , NULL ) ;
V_204:
F_110 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
return V_88 ;
V_208: {
char V_216 [ V_217 ] ;
const char * V_16 = F_93 ( - V_88 , V_216 , sizeof( V_216 ) ) ;
F_91 ( L_77 , V_16 ) ;
goto V_204;
}
}
static int
F_111 ( const struct V_218 * V_219 , const char * V_8 , int V_220 )
{
V_155 . V_197 = true ;
return F_112 ( V_219 , V_8 , V_220 ) ;
}
static int
F_113 ( const struct V_218 * V_219 , const char * V_8 , int V_220 )
{
struct V_115 * V_221 = (struct V_115 * ) V_219 -> V_222 ;
V_221 -> V_223 = true ;
V_199 . V_50 = ! V_220 ;
V_199 . V_224 = V_225 ;
if ( V_220 ) {
V_155 . V_197 = false ;
V_199 . V_224 = V_226 ;
return 0 ;
}
return F_114 ( V_8 ) ;
}
static int F_115 ( const char * V_227 , const char * V_222 , void * T_7 V_7 )
{
if ( ! strcmp ( V_227 , L_78 ) )
V_227 = L_79 ;
if ( ! strcmp ( V_227 , L_80 ) ) {
V_155 . V_166 = F_116 ( V_227 , V_222 ) ;
return 0 ;
}
return 0 ;
}
static int
F_117 ( const struct V_218 * V_219 , const char * V_8 ,
int V_220 V_7 )
{
struct V_1 * V_2 = V_219 -> V_222 ;
V_2 -> V_68 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_118 ( int V_228 , const char * * V_229 , const char * T_8 V_7 )
{
char V_216 [ V_217 ] ;
struct V_1 V_2 = {
. V_86 = 5 ,
. V_84 = 2 ,
. V_115 = {
. V_196 = V_230 ,
. V_231 = V_230 ,
. V_232 = V_233 ,
. V_234 = 4000 ,
. V_69 = {
. V_235 = true ,
} ,
. V_205 = 500 ,
} ,
. V_170 = V_236 ,
. V_48 = 5 ,
} ;
struct V_115 * V_190 = & V_2 . V_115 ;
struct V_69 * V_69 = & V_190 -> V_69 ;
const struct V_218 V_237 [] = {
F_119 ( 'e' , L_81 , & V_2 . V_49 , L_81 ,
L_82 ,
V_238 ) ,
F_120 ( 'c' , L_83 , & V_190 -> V_232 , L_84 ) ,
F_121 ( 'p' , L_85 , & V_69 -> V_149 , L_85 ,
L_86 ) ,
F_121 ( 't' , L_87 , & V_69 -> V_239 , L_87 ,
L_88 ) ,
F_122 ( 'a' , L_89 , & V_69 -> V_240 ,
L_90 ) ,
F_121 ( 'C' , L_91 , & V_69 -> V_241 , L_91 ,
L_92 ) ,
F_121 ( 'k' , L_93 , & V_155 . V_163 ,
L_94 , L_95 ) ,
F_122 ( 0 , L_96 , & V_155 . V_242 ,
L_97 ) ,
F_122 ( 'K' , L_98 , & V_2 . V_67 ,
L_99 ) ,
F_119 ( 'm' , L_100 , & V_190 -> V_196 , L_101 ,
L_102 ,
V_243 ) ,
F_123 ( 'r' , L_103 , & V_2 . V_209 ,
L_104 ) ,
F_123 ( 'd' , L_105 , & V_2 . V_84 ,
L_106 ) ,
F_122 ( 'D' , L_107 , & V_2 . V_104 ,
L_108 ) ,
F_123 ( 'f' , L_109 , & V_2 . V_86 ,
L_110 ) ,
F_122 ( 0 , L_111 , & V_190 -> V_244 ,
L_112 ) ,
F_122 ( 'i' , L_113 , & V_190 -> V_245 ,
L_114 ) ,
F_121 ( 0 , L_115 , & V_2 . V_246 , L_116 ,
L_117 ) ,
F_122 ( 'z' , L_118 , & V_2 . V_51 , L_119 ) ,
F_124 ( 'F' , L_120 , & V_190 -> V_231 , L_121 ) ,
F_123 ( 'E' , L_122 , & V_2 . V_3 ,
L_123 ) ,
F_122 ( 'U' , L_124 , & V_2 . V_66 ,
L_125 ) ,
F_122 ( 0 , L_126 , & V_2 . V_247 , L_127 ) ,
F_122 ( 0 , L_128 , & V_2 . V_248 , L_129 ) ,
F_125 ( 'v' , L_130 , & V_194 ,
L_131 ) ,
F_121 ( 's' , L_132 , & V_249 , L_133 ,
L_134
L_135 ) ,
F_121 ( 0 , L_136 , & V_250 , L_137 ,
L_138 ) ,
F_122 ( 'n' , L_139 , & V_155 . V_251 ,
L_140 ) ,
F_126 ( 'g' , NULL , & V_2 . V_115 ,
NULL , L_141 ,
& F_111 ) ,
F_119 ( 0 , L_142 , & V_2 . V_115 ,
L_143 ,
V_252 , & F_113 ) ,
F_122 ( 0 , L_144 , & V_155 . V_166 ,
L_145 ) ,
F_123 ( 0 , L_146 , & V_2 . V_170 ,
L_147
L_148 F_127 ( V_236 ) ) ,
F_119 ( 0 , L_149 , NULL , L_150 ,
L_151 ,
V_253 ) ,
F_122 ( 0 , L_152 , & V_155 . V_254 ,
L_153 ) ,
F_121 ( 0 , L_154 , & V_155 . V_255 , L_155 ,
L_156 ) ,
F_121 ( 0 , L_157 , & V_155 . V_256 , L_158 ,
L_159 ) ,
F_121 ( 0 , L_160 , & V_155 . V_257 , L_161 ,
L_162 ) ,
F_122 ( 0 , L_163 , & V_155 . V_258 ,
L_164 ) ,
F_122 ( 0 , L_165 , & V_155 . V_259 ,
L_166 ) ,
F_122 ( 0 , L_167 , & V_155 . V_260 ,
L_168 ) ,
F_121 ( 0 , L_169 , & V_203 , L_170 ,
L_171 ) ,
F_121 ( 'M' , L_172 , & V_261 , L_173 ,
L_174 ) ,
F_121 ( 'u' , L_175 , & V_69 -> V_116 , L_176 , L_177 ) ,
F_119 ( 0 , L_178 , & V_2 , L_179 ,
L_180 , F_117 ) ,
F_119 ( 0 , L_181 , NULL , L_182 ,
L_183 , V_262 ) ,
F_121 ( 'w' , L_184 , & V_155 . V_263 ,
L_185 ,
L_186 ) ,
F_124 ( 0 , L_187 , & V_190 -> V_205 ,
L_188 ) ,
F_126 ( 'b' , L_189 , & V_190 -> V_139 ,
L_190 , L_191 ,
V_264 ) ,
F_119 ( 'j' , L_192 , & V_190 -> V_139 ,
L_193 , L_194 ,
V_264 ) ,
F_122 ( 0 , L_195 , & V_155 . V_265 ,
L_196 ) ,
F_122 ( 0 , L_197 , & V_155 . V_266 ,
L_198 ) ,
F_128 ()
} ;
const char * const V_267 [] = {
L_199 ,
NULL
} ;
int V_268 = F_129 () ;
if ( V_268 < 0 )
return V_268 ;
V_2 . V_49 = F_130 () ;
if ( V_2 . V_49 == NULL )
return - V_44 ;
F_131 ( F_115 , & V_2 ) ;
V_228 = F_132 ( V_228 , V_229 , V_237 , V_267 , 0 ) ;
if ( V_228 )
F_133 ( V_267 , V_237 ) ;
if ( ! V_2 . V_49 -> V_85 &&
F_134 ( V_2 . V_49 ) < 0 ) {
F_6 ( L_200 ) ;
goto V_269;
}
if ( V_155 . V_266 ) {
V_155 . V_270 = false ;
V_155 . V_166 = false ;
if ( V_250 ) {
F_6 ( L_201 ) ;
F_135 ( V_267 , V_237 , L_136 , 0 ) ;
F_135 ( NULL , V_237 , L_197 , 0 ) ;
goto V_269;
}
}
V_271 = V_272 ;
V_273 = 1 ;
if ( V_2 . V_248 )
V_39 = 0 ;
else if ( V_2 . V_247 )
V_39 = 1 ;
F_136 ( false ) ;
if ( F_137 ( V_2 . V_49 ) < 0 ) {
if ( V_249 )
F_135 ( V_267 , V_237 , L_202 , 1 ) ;
if ( V_250 )
F_135 ( V_249 ? NULL : V_267 ,
V_237 , L_136 , 0 ) ;
goto V_269;
}
V_268 = F_138 ( V_69 ) ;
if ( V_268 ) {
F_139 ( V_69 , V_268 , V_216 , V_217 ) ;
F_17 ( L_21 , V_216 ) ;
}
V_268 = F_140 ( V_69 ) ;
if ( V_268 ) {
int V_274 = V_128 ;
F_139 ( V_69 , V_268 , V_216 , V_217 ) ;
F_91 ( L_21 , V_216 ) ;
V_268 = - V_274 ;
goto V_269;
}
if ( F_104 ( V_69 ) )
V_69 -> V_240 = true ;
if ( F_141 ( V_2 . V_49 , V_69 ) < 0 ) {
F_91 ( L_203 ,
V_128 == V_275 ? L_204 : F_93 ( V_128 , V_216 , sizeof( V_216 ) ) ) ;
goto V_269;
}
V_155 . V_63 = V_2 . V_49 -> V_85 ;
if ( V_2 . V_84 < 1 )
V_2 . V_84 = 1 ;
if ( F_142 ( V_190 ) ) {
V_268 = - V_198 ;
goto V_269;
}
V_2 . V_47 = F_53 ( V_2 . V_49 ) ;
if ( ! V_155 . V_197 ) {
V_155 . V_166 = false ;
F_143 () ;
}
if ( V_155 . V_166 && ! V_199 . V_276 )
V_199 . V_277 = V_278 ;
V_155 . V_279 = sizeof( struct V_13 ) ;
V_155 . V_280 = ( V_155 . V_163 == NULL ) ;
if ( F_144 ( NULL ) < 0 )
return - 1 ;
F_145 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_97 V_98 = {
. V_99 = F_2 ,
. V_100 = V_101 ,
} ;
F_1 ( & V_2 ) ;
V_97 ( V_102 , & V_98 , NULL ) ;
}
V_268 = F_96 ( & V_2 ) ;
V_269:
F_146 ( V_2 . V_49 ) ;
return V_268 ;
}
