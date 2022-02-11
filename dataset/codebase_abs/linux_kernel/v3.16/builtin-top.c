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
puts ( V_56 ) ;
F_29 ( V_2 , V_52 , sizeof( V_52 ) ) ;
printf ( L_21 , V_52 ) ;
F_30 ( V_2 ) ;
printf ( L_22 , V_54 , V_54 , V_57 ) ;
if ( V_2 -> V_48 -> V_43 . V_58 . V_59 !=
V_2 -> V_48 -> V_43 . V_58 . V_60 [ V_61 ] ) {
V_2 -> V_48 -> V_43 . V_58 . V_59 =
V_2 -> V_48 -> V_43 . V_58 . V_60 [ V_61 ] ;
F_31 ( stdout , V_62 ,
L_23 ,
V_2 -> V_48 -> V_43 . V_58 . V_59 ) ;
++ V_53 ;
}
if ( V_2 -> V_25 ) {
F_23 ( V_2 ) ;
return;
}
F_32 ( & V_2 -> V_48 -> V_43 , NULL ) ;
F_33 ( & V_2 -> V_48 -> V_43 ) ;
F_34 ( & V_2 -> V_48 -> V_43 ,
V_2 -> V_63 ,
V_2 -> V_64 ) ;
F_35 ( & V_2 -> V_48 -> V_43 ,
V_2 -> V_3 - V_53 ) ;
putchar ( '\n' ) ;
F_36 ( & V_2 -> V_48 -> V_43 , false ,
V_2 -> V_3 - V_53 , V_54 ,
V_2 -> V_65 , stdout ) ;
}
static void F_37 ( int * V_66 , const char * V_67 )
{
char * V_68 = malloc ( 0 ) , * V_69 ;
T_5 V_70 = 0 ;
int V_71 ;
fprintf ( stdout , L_24 , V_67 ) ;
if ( F_38 ( & V_68 , & V_70 , V_72 ) < 0 )
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
static void F_39 ( int * V_66 , const char * V_67 )
{
int V_71 = 0 ;
F_37 ( & V_71 , V_67 ) ;
if ( V_71 >= 0 && V_71 <= 100 )
* V_66 = V_71 ;
}
static void F_40 ( struct V_1 * V_2 , const char * V_67 )
{
char * V_68 = malloc ( 0 ) , * V_69 ;
struct V_9 * V_74 = V_2 -> V_25 , * V_75 , * V_76 = NULL ;
struct V_77 * V_78 ;
T_5 V_70 = 0 ;
if ( V_74 ) {
F_13 ( V_74 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_67 ) ;
if ( F_38 ( & V_68 , & V_70 , V_72 ) < 0 )
goto V_73;
V_69 = strchr ( V_68 , '\n' ) ;
if ( V_69 )
* V_69 = 0 ;
V_78 = F_41 ( & V_2 -> V_48 -> V_43 . V_79 ) ;
while ( V_78 ) {
V_75 = F_42 ( V_78 , struct V_9 , V_77 ) ;
if ( V_75 -> V_17 . V_12 && ! strcmp ( V_68 , V_75 -> V_17 . V_12 -> V_21 ) ) {
V_76 = V_75 ;
break;
}
V_78 = F_43 ( & V_75 -> V_77 ) ;
}
if ( ! V_76 ) {
fprintf ( V_80 , L_25 , V_68 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_76 ) ;
V_73:
free ( V_68 ) ;
}
static void F_44 ( struct V_1 * V_2 )
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
static int F_45 ( struct V_1 * V_2 , int V_85 )
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
static bool F_46 ( struct V_1 * V_2 , int V_85 )
{
bool V_86 = true ;
if ( ! F_45 ( V_2 , V_85 ) ) {
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 , V_94 ;
F_44 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_47 ( 0 , & V_94 ) ;
V_93 = V_94 ;
V_93 . V_95 &= ~ ( V_96 | V_97 ) ;
V_93 . V_98 [ V_99 ] = 0 ;
V_93 . V_98 [ V_100 ] = 0 ;
F_48 ( 0 , V_101 , & V_93 ) ;
F_49 ( & V_88 , 1 , - 1 ) ;
V_85 = getc ( V_72 ) ;
F_48 ( 0 , V_102 , & V_94 ) ;
if ( ! F_45 ( V_2 , V_85 ) )
return V_86 ;
}
switch ( V_85 ) {
case 'd' :
F_37 ( & V_2 -> V_81 , L_42 ) ;
if ( V_2 -> V_81 < 1 )
V_2 -> V_81 = 1 ;
break;
case 'e' :
F_37 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_103 V_104 = {
. V_105 = F_2 ,
. V_106 = V_107 ,
} ;
F_2 ( V_108 , NULL , V_2 ) ;
V_103 ( V_108 , & V_104 , NULL ) ;
} else {
signal ( V_108 , V_109 ) ;
}
break;
case 'E' :
if ( V_2 -> V_82 -> V_83 > 1 ) {
int V_41 = 0 ;
fprintf ( V_80 , L_44 ) ;
F_50 (top->evlist, top->sym_evsel)
fprintf ( V_80 , L_45 , V_2 -> V_48 -> V_51 , F_24 ( V_2 -> V_48 ) ) ;
F_37 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_82 -> V_83 ) {
V_2 -> V_48 = F_51 ( V_2 -> V_82 ) ;
fprintf ( V_80 , L_47 , F_24 ( V_2 -> V_48 ) ) ;
F_7 ( 1 ) ;
break;
}
F_50 (top->evlist, top->sym_evsel)
if ( V_2 -> V_48 -> V_51 == V_41 )
break;
} else
V_2 -> V_48 = F_51 ( V_2 -> V_82 ) ;
break;
case 'f' :
F_37 ( & V_2 -> V_84 , L_48 ) ;
break;
case 'F' :
F_39 ( & V_2 -> V_49 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_64 = ! V_2 -> V_64 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_110 )
F_52 ( V_2 -> V_111 , V_80 ) ;
V_86 = false ;
break;
case 's' :
F_40 ( V_2 , L_51 ) ;
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
static void F_53 ( void * V_8 )
{
struct V_1 * V_112 = V_8 ;
F_30 ( V_112 ) ;
if ( V_112 -> V_82 -> V_113 != NULL )
V_112 -> V_48 = V_112 -> V_82 -> V_113 ;
F_32 ( & V_112 -> V_48 -> V_43 , NULL ) ;
F_33 ( & V_112 -> V_48 -> V_43 ) ;
F_34 ( & V_112 -> V_48 -> V_43 ,
V_112 -> V_63 ,
V_112 -> V_64 ) ;
}
static void * F_54 ( void * V_8 )
{
struct V_114 * V_115 ;
struct V_1 * V_2 = V_8 ;
const char * V_116 = L_52 ;
struct V_117 V_118 = {
. V_119 = F_53 ,
. V_8 = V_2 ,
. V_120 = V_2 -> V_81 ,
} ;
F_53 ( V_2 ) ;
F_50 (top->evlist, pos)
V_115 -> V_43 . V_121 = V_2 -> V_122 . V_66 . V_123 ;
F_55 ( V_2 -> V_82 , V_116 , & V_118 , V_2 -> V_65 ,
& V_2 -> V_111 -> V_124 . V_125 ) ;
V_126 = 1 ;
return NULL ;
}
static void * F_56 ( void * V_8 )
{
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 , V_94 ;
struct V_1 * V_2 = V_8 ;
int V_127 , V_85 ;
F_47 ( 0 , & V_94 ) ;
V_93 = V_94 ;
V_93 . V_95 &= ~ ( V_96 | V_97 ) ;
V_93 . V_98 [ V_99 ] = 0 ;
V_93 . V_98 [ V_100 ] = 0 ;
F_57 () ;
V_128:
V_127 = V_2 -> V_81 * 1000 ;
F_48 ( 0 , V_101 , & V_93 ) ;
getc ( V_72 ) ;
while ( ! V_126 ) {
F_28 ( V_2 ) ;
switch ( F_49 ( & V_88 , 1 , V_127 ) ) {
case 0 :
continue;
case - 1 :
if ( V_129 == V_130 )
continue;
default:
V_85 = getc ( V_72 ) ;
F_48 ( 0 , V_102 , & V_94 ) ;
if ( F_46 ( V_2 , V_85 ) )
goto V_128;
V_126 = 1 ;
}
}
return NULL ;
}
static int F_58 ( struct V_15 * V_15 V_7 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
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
if ( F_59 ( V_12 ) )
V_12 -> V_131 = true ;
return 0 ;
}
static int F_60 ( struct V_132 * V_133 ,
struct V_134 * V_135 , bool V_136 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_133 -> V_10 ;
struct V_114 * V_137 = V_133 -> V_137 ;
if ( V_138 && V_136 ) {
T_4 V_26 = V_135 -> V_139 ;
if ( V_135 -> V_15 )
V_26 = V_135 -> V_15 -> V_140 ( V_135 -> V_15 , V_26 ) ;
F_19 ( V_2 , V_10 , V_137 -> V_51 , V_26 ) ;
}
return 0 ;
}
static void F_61 ( struct V_141 * V_142 ,
const union V_143 * V_144 ,
struct V_114 * V_137 ,
struct V_145 * V_146 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_62 ( V_142 , struct V_1 , V_142 ) ;
struct V_134 V_135 ;
int V_16 ;
if ( ! V_36 && V_147 ) {
static struct V_148 * V_149 ;
if ( ! V_149 )
V_149 = F_63 ( NULL ) ;
if ( ! F_64 ( V_149 , V_146 -> V_150 ) ) {
F_6 ( L_60 ,
V_146 -> V_150 ) ;
F_65 ( V_149 , V_146 -> V_150 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_111 -> V_58 . V_151 ++ ) ;
return;
}
if ( V_144 -> V_124 . V_152 & V_153 )
V_2 -> V_154 ++ ;
if ( F_66 ( V_144 , V_36 , & V_135 , V_146 ) < 0 )
return;
if ( ! V_2 -> V_155 &&
V_156 . V_157 &&
V_135 . V_158 == V_159 ) {
F_17 (
L_62
L_63
L_64 ,
! F_67 ( & V_135 . V_15 -> V_18 -> V_160 [ V_161 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_155 = true ;
}
if ( V_135 . V_12 == NULL ) {
const char * V_67 = L_67 ;
if ( ! V_2 -> V_155 && ! V_2 -> V_162 &&
V_135 . V_15 == V_36 -> V_163 [ V_161 ] &&
F_67 ( & V_135 . V_15 -> V_18 -> V_160 [ V_161 ] ) ) {
if ( V_156 . V_164 ) {
F_17 ( L_68 ,
V_156 . V_164 , V_67 ) ;
} else {
F_17 ( L_69 ,
V_67 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_162 = true ;
}
}
if ( V_135 . V_12 == NULL || ! V_135 . V_12 -> V_131 ) {
struct V_132 V_133 = {
. V_165 = F_60 ,
} ;
if ( V_156 . V_166 )
V_133 . V_167 = & V_168 ;
else
V_133 . V_167 = & V_169 ;
F_9 ( & V_137 -> V_43 . V_23 ) ;
V_16 = F_68 ( & V_133 , & V_135 , V_137 , V_146 ,
V_2 -> V_170 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_137 -> V_43 . V_23 ) ;
}
return;
}
static void F_69 ( struct V_1 * V_2 , int V_51 )
{
struct V_145 V_146 ;
struct V_114 * V_137 ;
struct V_171 * V_111 = V_2 -> V_111 ;
union V_143 * V_144 ;
struct V_36 * V_36 ;
T_6 V_172 ;
int V_86 ;
while ( ( V_144 = F_70 ( V_2 -> V_82 , V_51 ) ) != NULL ) {
V_86 = F_71 ( V_2 -> V_82 , V_144 , & V_146 ) ;
if ( V_86 ) {
F_6 ( L_71 , V_86 ) ;
goto V_173;
}
V_137 = F_72 ( V_111 -> V_82 , V_146 . V_174 ) ;
assert ( V_137 != NULL ) ;
V_172 = V_144 -> V_124 . V_152 & V_175 ;
if ( V_144 -> V_124 . type == V_176 )
++ V_2 -> V_177 ;
switch ( V_172 ) {
case V_178 :
++ V_2 -> V_179 ;
if ( V_2 -> V_63 )
goto V_173;
V_36 = & V_111 -> V_180 . V_181 ;
break;
case V_159 :
++ V_2 -> V_182 ;
if ( V_2 -> V_64 )
goto V_173;
V_36 = & V_111 -> V_180 . V_181 ;
break;
case V_183 :
++ V_2 -> V_184 ;
V_36 = F_73 ( V_111 ,
V_146 . V_150 ) ;
break;
case V_185 :
++ V_2 -> V_186 ;
default:
goto V_173;
}
if ( V_144 -> V_124 . type == V_176 ) {
F_61 ( & V_2 -> V_142 , V_144 , V_137 ,
& V_146 , V_36 ) ;
} else if ( V_144 -> V_124 . type < V_187 ) {
F_74 ( & V_137 -> V_43 , V_144 -> V_124 . type ) ;
F_75 ( V_36 , V_144 , & V_146 ) ;
} else
++ V_111 -> V_58 . V_188 ;
V_173:
F_76 ( V_2 -> V_82 , V_51 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
int V_189 ;
for ( V_189 = 0 ; V_189 < V_2 -> V_82 -> V_190 ; V_189 ++ )
F_69 ( V_2 , V_189 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
char V_67 [ 512 ] ;
struct V_114 * V_41 ;
struct V_191 * V_82 = V_2 -> V_82 ;
struct V_122 * V_192 = & V_2 -> V_122 ;
F_79 ( V_82 , V_192 ) ;
F_50 (evlist, counter) {
V_193:
if ( F_80 ( V_41 , V_2 -> V_82 -> V_194 ,
V_2 -> V_82 -> V_195 ) < 0 ) {
if ( F_81 ( V_41 , V_129 , V_67 , sizeof( V_67 ) ) ) {
if ( V_196 )
F_17 ( L_21 , V_67 ) ;
goto V_193;
}
F_82 ( V_41 , & V_192 -> V_66 ,
V_129 , V_67 , sizeof( V_67 ) ) ;
F_83 ( L_21 , V_67 ) ;
goto V_197;
}
}
if ( F_84 ( V_82 , V_192 -> V_198 , false ) < 0 ) {
F_83 ( L_72 ,
V_129 , strerror ( V_129 ) ) ;
goto V_197;
}
return 0 ;
V_197:
return - 1 ;
}
static int F_85 ( struct V_1 * V_2 V_7 )
{
if ( ! V_138 ) {
if ( V_156 . V_199 ) {
F_83 ( L_73 ) ;
return - V_200 ;
}
} else if ( V_201 . V_202 != V_203 ) {
if ( F_86 ( & V_201 ) < 0 ) {
F_83 ( L_74 ) ;
return - V_200 ;
}
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_122 * V_192 = & V_2 -> V_122 ;
T_7 V_204 ;
int V_86 ;
V_2 -> V_111 = F_88 ( NULL , false , NULL ) ;
if ( V_2 -> V_111 == NULL )
return - V_45 ;
F_89 ( & V_2 -> V_111 -> V_180 , F_58 ) ;
if ( ! V_205 ) {
V_86 = F_90 ( & V_2 -> V_111 -> V_124 . V_125 ) ;
if ( V_86 )
goto V_206;
}
V_86 = F_85 ( V_2 ) ;
if ( V_86 )
goto V_206;
F_91 ( & V_2 -> V_111 -> V_180 . V_181 , & V_192 -> V_66 ,
V_2 -> V_82 -> V_195 , false ) ;
V_86 = F_78 ( V_2 ) ;
if ( V_86 )
goto V_206;
V_2 -> V_111 -> V_82 = V_2 -> V_82 ;
F_92 ( V_2 -> V_111 ) ;
if ( ! F_93 ( & V_192 -> V_66 ) )
F_94 ( V_2 -> V_82 ) ;
F_49 ( V_2 -> V_82 -> V_87 , V_2 -> V_82 -> V_207 , 100 ) ;
F_77 ( V_2 ) ;
V_86 = - 1 ;
if ( F_95 ( & V_204 , NULL , ( V_39 > 0 ? F_54 :
F_56 ) , V_2 ) ) {
F_83 ( L_75 ) ;
goto V_206;
}
if ( V_2 -> V_208 ) {
struct V_209 V_210 ;
V_210 . V_211 = V_2 -> V_208 ;
if ( F_96 ( 0 , V_212 , & V_210 ) ) {
F_83 ( L_76 ) ;
goto V_206;
}
}
while ( ! V_126 ) {
T_4 V_213 = V_2 -> V_177 ;
F_77 ( V_2 ) ;
if ( V_213 == V_2 -> V_177 )
V_86 = F_49 ( V_2 -> V_82 -> V_87 , V_2 -> V_82 -> V_207 , 100 ) ;
}
V_86 = 0 ;
V_206:
F_97 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
return V_86 ;
}
static int
F_98 ( const struct V_214 * V_215 , const char * V_8 , int V_216 )
{
V_156 . V_199 = true ;
return F_99 ( V_215 , V_8 , V_216 ) ;
}
static int
F_100 ( const struct V_214 * V_215 , const char * V_8 , int V_216 )
{
V_156 . V_199 = true ;
return F_101 ( V_215 , V_8 , V_216 ) ;
}
static int F_102 ( const char * V_217 , const char * V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
if ( ! strcmp ( V_217 , L_77 ) )
return F_103 ( V_218 , & V_2 -> V_122 ) ;
if ( ! strcmp ( V_217 , L_78 ) ) {
V_156 . V_166 = F_104 ( V_217 , V_218 ) ;
return 0 ;
}
return F_105 ( V_217 , V_218 , V_219 ) ;
}
static int
F_106 ( const struct V_214 * V_215 , const char * V_8 ,
int V_216 V_7 )
{
struct V_1 * V_2 = V_215 -> V_218 ;
V_2 -> V_65 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_107 ( int V_220 , const char * * V_221 , const char * T_8 V_7 )
{
int V_222 = - 1 ;
char V_223 [ V_224 ] ;
struct V_1 V_2 = {
. V_84 = 5 ,
. V_81 = 2 ,
. V_122 = {
. V_198 = V_225 ,
. V_226 = V_225 ,
. V_227 = V_228 ,
. V_229 = 4000 ,
. V_66 = {
. V_230 = true ,
} ,
} ,
. V_170 = V_231 ,
. V_49 = 5 ,
} ;
struct V_122 * V_192 = & V_2 . V_122 ;
struct V_66 * V_66 = & V_192 -> V_66 ;
const struct V_214 V_232 [] = {
F_108 ( 'e' , L_79 , & V_2 . V_82 , L_79 ,
L_80 ,
V_233 ) ,
F_109 ( 'c' , L_81 , & V_192 -> V_227 , L_82 ) ,
F_110 ( 'p' , L_83 , & V_66 -> V_150 , L_83 ,
L_84 ) ,
F_110 ( 't' , L_85 , & V_66 -> V_234 , L_85 ,
L_86 ) ,
F_111 ( 'a' , L_87 , & V_66 -> V_235 ,
L_88 ) ,
F_110 ( 'C' , L_89 , & V_66 -> V_236 , L_89 ,
L_90 ) ,
F_110 ( 'k' , L_91 , & V_156 . V_164 ,
L_92 , L_93 ) ,
F_111 ( 0 , L_94 , & V_156 . V_237 ,
L_95 ) ,
F_111 ( 'K' , L_96 , & V_2 . V_64 ,
L_97 ) ,
F_108 ( 'm' , L_98 , & V_192 -> V_198 , L_99 ,
L_100 ,
V_238 ) ,
F_112 ( 'r' , L_101 , & V_2 . V_208 ,
L_102 ) ,
F_112 ( 'd' , L_103 , & V_2 . V_81 ,
L_104 ) ,
F_111 ( 'D' , L_105 , & V_2 . V_110 ,
L_106 ) ,
F_112 ( 'f' , L_107 , & V_2 . V_84 ,
L_108 ) ,
F_111 ( 0 , L_109 , & V_192 -> V_239 ,
L_110 ) ,
F_111 ( 'i' , L_111 , & V_192 -> V_240 ,
L_112 ) ,
F_110 ( 0 , L_113 , & V_2 . V_241 , L_114 ,
L_115 ) ,
F_111 ( 'z' , L_116 , & V_2 . V_50 , L_117 ) ,
F_113 ( 'F' , L_118 , & V_192 -> V_226 , L_119 ) ,
F_112 ( 'E' , L_120 , & V_2 . V_3 ,
L_121 ) ,
F_111 ( 'U' , L_122 , & V_2 . V_63 ,
L_123 ) ,
F_111 ( 0 , L_124 , & V_2 . V_242 , L_125 ) ,
F_111 ( 0 , L_126 , & V_2 . V_243 , L_127 ) ,
F_114 ( 'v' , L_128 , & V_196 ,
L_129 ) ,
F_110 ( 's' , L_130 , & V_244 , L_131 ,
L_132
L_133 ) ,
F_110 ( 0 , L_134 , & V_245 , L_135 ,
L_136 ) ,
F_111 ( 'n' , L_137 , & V_156 . V_246 ,
L_138 ) ,
F_115 ( 'g' , NULL , & V_2 . V_122 ,
NULL , L_139 ,
& F_98 ) ,
F_108 ( 0 , L_140 , & V_2 . V_122 ,
L_141 , V_247 ,
& F_100 ) ,
F_111 ( 0 , L_142 , & V_156 . V_166 ,
L_143 ) ,
F_112 ( 0 , L_144 , & V_2 . V_170 ,
L_145
L_146 F_116 ( V_231 ) ) ,
F_108 ( 0 , L_147 , NULL , L_148 ,
L_149 ,
V_248 ) ,
F_111 ( 0 , L_150 , & V_156 . V_249 ,
L_151 ) ,
F_110 ( 0 , L_152 , & V_156 . V_250 , L_153 ,
L_154 ) ,
F_110 ( 0 , L_155 , & V_156 . V_251 , L_156 ,
L_157 ) ,
F_110 ( 0 , L_158 , & V_156 . V_252 , L_159 ,
L_160 ) ,
F_111 ( 0 , L_161 , & V_156 . V_253 ,
L_162 ) ,
F_111 ( 0 , L_163 , & V_156 . V_254 ,
L_164 ) ,
F_110 ( 0 , L_165 , & V_205 , L_166 ,
L_167 ) ,
F_110 ( 'M' , L_168 , & V_255 , L_169 ,
L_170 ) ,
F_110 ( 'u' , L_171 , & V_66 -> V_123 , L_172 , L_173 ) ,
F_108 ( 0 , L_174 , & V_2 , L_175 ,
L_176 , F_106 ) ,
F_108 ( 0 , L_177 , NULL , L_178 ,
L_179 , V_256 ) ,
F_117 ()
} ;
const char * const V_257 [] = {
L_180 ,
NULL
} ;
V_2 . V_82 = F_118 () ;
if ( V_2 . V_82 == NULL )
return - V_45 ;
F_119 ( F_102 , & V_2 ) ;
V_220 = F_120 ( V_220 , V_221 , V_232 , V_257 , 0 ) ;
if ( V_220 )
F_121 ( V_257 , V_232 ) ;
V_258 = V_259 ;
V_260 = 1 ;
if ( F_122 () < 0 ) {
if ( V_244 )
F_123 ( V_257 , V_232 , L_181 , 1 ) ;
if ( V_245 )
F_123 ( V_244 ? NULL : V_257 ,
V_232 , L_134 , 0 ) ;
goto V_261;
}
if ( V_2 . V_243 )
V_39 = 0 ;
else if ( V_2 . V_242 )
V_39 = 1 ;
F_124 ( false ) ;
V_222 = F_125 ( V_66 ) ;
if ( V_222 ) {
F_126 ( V_66 , V_222 , V_223 , V_224 ) ;
F_17 ( L_21 , V_223 ) ;
}
V_222 = F_127 ( V_66 ) ;
if ( V_222 ) {
int V_262 = V_129 ;
F_126 ( V_66 , V_222 , V_223 , V_224 ) ;
F_83 ( L_21 , V_223 ) ;
V_222 = - V_262 ;
goto V_261;
}
if ( F_93 ( V_66 ) )
V_66 -> V_235 = true ;
if ( F_128 ( V_2 . V_82 , V_66 ) < 0 )
F_121 ( V_257 , V_232 ) ;
if ( ! V_2 . V_82 -> V_83 &&
F_129 ( V_2 . V_82 ) < 0 ) {
F_83 ( L_182 ) ;
goto V_261;
}
V_156 . V_60 = V_2 . V_82 -> V_83 ;
if ( V_2 . V_81 < 1 )
V_2 . V_81 = 1 ;
if ( F_130 ( V_192 ) ) {
V_222 = - V_200 ;
goto V_261;
}
V_2 . V_48 = F_51 ( V_2 . V_82 ) ;
if ( ! V_156 . V_199 ) {
V_156 . V_166 = false ;
F_131 () ;
}
V_156 . V_263 = sizeof( struct V_13 ) ;
V_156 . V_264 = ( V_156 . V_164 == NULL ) ;
if ( F_132 () < 0 )
return - 1 ;
F_133 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_103 V_104 = {
. V_105 = F_2 ,
. V_106 = V_107 ,
} ;
F_1 ( & V_2 ) ;
V_103 ( V_108 , & V_104 , NULL ) ;
}
V_222 = F_87 ( & V_2 ) ;
V_261:
F_134 ( V_2 . V_82 ) ;
return V_222 ;
}
