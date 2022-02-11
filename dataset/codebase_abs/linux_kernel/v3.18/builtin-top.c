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
F_36 ( V_43 ) ;
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
F_36 ( V_43 ) ;
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
V_2 -> V_103 -> V_58 . V_149 ++ ) ;
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
! F_71 ( & V_133 . V_15 -> V_18 -> V_158 [ V_159 ] ) ?
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
F_17 ( L_68 ,
V_154 . V_162 , V_67 ) ;
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
. V_163 = F_64 ,
} ;
if ( V_154 . V_164 )
V_131 . V_165 = & V_166 ;
else
V_131 . V_165 = & V_167 ;
F_9 ( & V_43 -> V_23 ) ;
V_16 = F_72 ( & V_131 , & V_133 , V_135 , V_144 ,
V_2 -> V_168 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_70 ) ;
F_11 ( & V_43 -> V_23 ) ;
}
return;
}
static void F_73 ( struct V_1 * V_2 , int V_51 )
{
struct V_143 V_144 ;
struct V_106 * V_135 ;
struct V_169 * V_103 = V_2 -> V_103 ;
union V_141 * V_142 ;
struct V_36 * V_36 ;
T_6 V_170 ;
int V_86 ;
while ( ( V_142 = F_74 ( V_2 -> V_82 , V_51 ) ) != NULL ) {
V_86 = F_75 ( V_2 -> V_82 , V_142 , & V_144 ) ;
if ( V_86 ) {
F_6 ( L_71 , V_86 ) ;
goto V_171;
}
V_135 = F_76 ( V_103 -> V_82 , V_144 . V_172 ) ;
assert ( V_135 != NULL ) ;
V_170 = V_142 -> V_116 . V_150 & V_173 ;
if ( V_142 -> V_116 . type == V_174 )
++ V_2 -> V_175 ;
switch ( V_170 ) {
case V_176 :
++ V_2 -> V_177 ;
if ( V_2 -> V_63 )
goto V_171;
V_36 = & V_103 -> V_178 . V_179 ;
break;
case V_157 :
++ V_2 -> V_180 ;
if ( V_2 -> V_64 )
goto V_171;
V_36 = & V_103 -> V_178 . V_179 ;
break;
case V_181 :
++ V_2 -> V_182 ;
V_36 = F_77 ( V_103 ,
V_144 . V_148 ) ;
break;
case V_183 :
++ V_2 -> V_184 ;
default:
goto V_171;
}
if ( V_142 -> V_116 . type == V_174 ) {
F_65 ( & V_2 -> V_140 , V_142 , V_135 ,
& V_144 , V_36 ) ;
} else if ( V_142 -> V_116 . type < V_185 ) {
F_78 ( F_29 ( V_135 ) , V_142 -> V_116 . type ) ;
F_79 ( V_36 , V_142 , & V_144 ) ;
} else
++ V_103 -> V_58 . V_186 ;
V_171:
F_80 ( V_2 -> V_82 , V_51 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
int V_187 ;
for ( V_187 = 0 ; V_187 < V_2 -> V_82 -> V_188 ; V_187 ++ )
F_73 ( V_2 , V_187 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
char V_67 [ 512 ] ;
struct V_106 * V_41 ;
struct V_189 * V_82 = V_2 -> V_82 ;
struct V_114 * V_190 = & V_2 -> V_114 ;
F_83 ( V_82 , V_190 ) ;
F_52 (evlist, counter) {
V_191:
if ( F_84 ( V_41 , V_2 -> V_82 -> V_192 ,
V_2 -> V_82 -> V_193 ) < 0 ) {
if ( F_85 ( V_41 , V_126 , V_67 , sizeof( V_67 ) ) ) {
if ( V_194 )
F_17 ( L_21 , V_67 ) ;
goto V_191;
}
F_86 ( V_41 , & V_190 -> V_66 ,
V_126 , V_67 , sizeof( V_67 ) ) ;
F_87 ( L_21 , V_67 ) ;
goto V_195;
}
}
if ( F_88 ( V_82 , V_190 -> V_196 , false ) < 0 ) {
F_87 ( L_72 ,
V_126 , F_89 ( V_126 , V_67 , sizeof( V_67 ) ) ) ;
goto V_195;
}
return 0 ;
V_195:
return - 1 ;
}
static int F_90 ( struct V_1 * V_2 V_7 )
{
if ( ! V_136 ) {
if ( V_154 . V_197 ) {
F_87 ( L_73 ) ;
return - V_198 ;
}
} else if ( V_199 . V_200 != V_201 ) {
if ( F_91 ( & V_199 ) < 0 ) {
F_87 ( L_74 ) ;
return - V_198 ;
}
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_114 * V_190 = & V_2 -> V_114 ;
T_7 V_202 ;
int V_86 ;
V_2 -> V_103 = F_93 ( NULL , false , NULL ) ;
if ( V_2 -> V_103 == NULL )
return - 1 ;
F_94 ( & V_2 -> V_103 -> V_178 , F_62 ) ;
if ( ! V_203 ) {
V_86 = F_95 ( & V_2 -> V_103 -> V_116 . V_117 ) ;
if ( V_86 )
goto V_204;
}
V_86 = F_90 ( V_2 ) ;
if ( V_86 )
goto V_204;
F_96 ( & V_2 -> V_103 -> V_178 . V_179 , & V_190 -> V_66 ,
V_2 -> V_82 -> V_193 , false ) ;
V_86 = F_82 ( V_2 ) ;
if ( V_86 )
goto V_204;
V_2 -> V_103 -> V_82 = V_2 -> V_82 ;
F_97 ( V_2 -> V_103 ) ;
if ( ! F_98 ( & V_190 -> V_66 ) )
F_99 ( V_2 -> V_82 ) ;
F_100 ( V_2 -> V_82 , 100 ) ;
F_81 ( V_2 ) ;
V_86 = - 1 ;
if ( F_101 ( & V_202 , NULL , ( V_39 > 0 ? F_56 :
F_60 ) , V_2 ) ) {
F_87 ( L_75 ) ;
goto V_204;
}
if ( V_2 -> V_205 ) {
struct V_206 V_207 ;
V_207 . V_208 = V_2 -> V_205 ;
if ( F_102 ( 0 , V_209 , & V_207 ) ) {
F_87 ( L_76 ) ;
goto V_210;
}
}
while ( ! V_118 ) {
T_4 V_211 = V_2 -> V_175 ;
F_81 ( V_2 ) ;
if ( V_211 == V_2 -> V_175 )
V_86 = F_100 ( V_2 -> V_82 , 100 ) ;
}
V_86 = 0 ;
V_210:
F_103 ( V_202 , NULL ) ;
V_204:
F_104 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
return V_86 ;
}
static int
F_105 ( const struct V_212 * V_213 , const char * V_8 , int V_214 )
{
V_154 . V_197 = true ;
return F_106 ( V_213 , V_8 , V_214 ) ;
}
static int
F_107 ( const struct V_212 * V_213 , const char * V_8 , int V_214 )
{
V_154 . V_197 = true ;
return F_108 ( V_213 , V_8 , V_214 ) ;
}
static int F_109 ( const char * V_215 , const char * V_216 , void * V_217 )
{
if ( ! strcmp ( V_215 , L_77 ) )
V_215 = L_78 ;
if ( ! strcmp ( V_215 , L_79 ) ) {
V_154 . V_164 = F_110 ( V_215 , V_216 ) ;
return 0 ;
}
return F_111 ( V_215 , V_216 , V_217 ) ;
}
static int
F_112 ( const struct V_212 * V_213 , const char * V_8 ,
int V_214 V_7 )
{
struct V_1 * V_2 = V_213 -> V_216 ;
V_2 -> V_65 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_113 ( int V_218 , const char * * V_219 , const char * T_8 V_7 )
{
char V_220 [ V_221 ] ;
struct V_1 V_2 = {
. V_84 = 5 ,
. V_81 = 2 ,
. V_114 = {
. V_196 = V_222 ,
. V_223 = V_222 ,
. V_224 = V_225 ,
. V_226 = 4000 ,
. V_66 = {
. V_227 = true ,
} ,
} ,
. V_168 = V_228 ,
. V_49 = 5 ,
} ;
struct V_114 * V_190 = & V_2 . V_114 ;
struct V_66 * V_66 = & V_190 -> V_66 ;
const struct V_212 V_229 [] = {
F_114 ( 'e' , L_80 , & V_2 . V_82 , L_80 ,
L_81 ,
V_230 ) ,
F_115 ( 'c' , L_82 , & V_190 -> V_224 , L_83 ) ,
F_116 ( 'p' , L_84 , & V_66 -> V_148 , L_84 ,
L_85 ) ,
F_116 ( 't' , L_86 , & V_66 -> V_231 , L_86 ,
L_87 ) ,
F_117 ( 'a' , L_88 , & V_66 -> V_232 ,
L_89 ) ,
F_116 ( 'C' , L_90 , & V_66 -> V_233 , L_90 ,
L_91 ) ,
F_116 ( 'k' , L_92 , & V_154 . V_162 ,
L_93 , L_94 ) ,
F_117 ( 0 , L_95 , & V_154 . V_234 ,
L_96 ) ,
F_117 ( 'K' , L_97 , & V_2 . V_64 ,
L_98 ) ,
F_114 ( 'm' , L_99 , & V_190 -> V_196 , L_100 ,
L_101 ,
V_235 ) ,
F_118 ( 'r' , L_102 , & V_2 . V_205 ,
L_103 ) ,
F_118 ( 'd' , L_104 , & V_2 . V_81 ,
L_105 ) ,
F_117 ( 'D' , L_106 , & V_2 . V_102 ,
L_107 ) ,
F_118 ( 'f' , L_108 , & V_2 . V_84 ,
L_109 ) ,
F_117 ( 0 , L_110 , & V_190 -> V_236 ,
L_111 ) ,
F_117 ( 'i' , L_112 , & V_190 -> V_237 ,
L_113 ) ,
F_116 ( 0 , L_114 , & V_2 . V_238 , L_115 ,
L_116 ) ,
F_117 ( 'z' , L_117 , & V_2 . V_50 , L_118 ) ,
F_119 ( 'F' , L_119 , & V_190 -> V_223 , L_120 ) ,
F_118 ( 'E' , L_121 , & V_2 . V_3 ,
L_122 ) ,
F_117 ( 'U' , L_123 , & V_2 . V_63 ,
L_124 ) ,
F_117 ( 0 , L_125 , & V_2 . V_239 , L_126 ) ,
F_117 ( 0 , L_127 , & V_2 . V_240 , L_128 ) ,
F_120 ( 'v' , L_129 , & V_194 ,
L_130 ) ,
F_116 ( 's' , L_131 , & V_241 , L_132 ,
L_133
L_134 ) ,
F_116 ( 0 , L_135 , & V_242 , L_136 ,
L_137 ) ,
F_117 ( 'n' , L_138 , & V_154 . V_243 ,
L_139 ) ,
F_121 ( 'g' , NULL , & V_2 . V_114 ,
NULL , L_140 ,
& F_105 ) ,
F_114 ( 0 , L_141 , & V_2 . V_114 ,
L_142 , V_244 ,
& F_107 ) ,
F_117 ( 0 , L_143 , & V_154 . V_164 ,
L_144 ) ,
F_118 ( 0 , L_145 , & V_2 . V_168 ,
L_146
L_147 F_122 ( V_228 ) ) ,
F_114 ( 0 , L_148 , NULL , L_149 ,
L_150 ,
V_245 ) ,
F_117 ( 0 , L_151 , & V_154 . V_246 ,
L_152 ) ,
F_116 ( 0 , L_153 , & V_154 . V_247 , L_154 ,
L_155 ) ,
F_116 ( 0 , L_156 , & V_154 . V_248 , L_157 ,
L_158 ) ,
F_116 ( 0 , L_159 , & V_154 . V_249 , L_160 ,
L_161 ) ,
F_117 ( 0 , L_162 , & V_154 . V_250 ,
L_163 ) ,
F_117 ( 0 , L_164 , & V_154 . V_251 ,
L_165 ) ,
F_117 ( 0 , L_166 , & V_154 . V_252 ,
L_167 ) ,
F_116 ( 0 , L_168 , & V_203 , L_169 ,
L_170 ) ,
F_116 ( 'M' , L_171 , & V_253 , L_172 ,
L_173 ) ,
F_116 ( 'u' , L_174 , & V_66 -> V_115 , L_175 , L_176 ) ,
F_114 ( 0 , L_177 , & V_2 , L_178 ,
L_179 , F_112 ) ,
F_114 ( 0 , L_180 , NULL , L_181 ,
L_182 , V_254 ) ,
F_116 ( 'w' , L_183 , & V_154 . V_255 ,
L_184 ,
L_185 ) ,
F_123 ()
} ;
const char * const V_256 [] = {
L_186 ,
NULL
} ;
int V_257 = F_124 () ;
if ( V_257 < 0 )
return V_257 ;
V_2 . V_82 = F_125 () ;
if ( V_2 . V_82 == NULL )
return - V_45 ;
F_126 ( F_109 , & V_2 ) ;
V_218 = F_127 ( V_218 , V_219 , V_229 , V_256 , 0 ) ;
if ( V_218 )
F_128 ( V_256 , V_229 ) ;
V_258 = V_259 ;
V_260 = 1 ;
if ( F_129 () < 0 ) {
if ( V_241 )
F_130 ( V_256 , V_229 , L_187 , 1 ) ;
if ( V_242 )
F_130 ( V_241 ? NULL : V_256 ,
V_229 , L_135 , 0 ) ;
goto V_261;
}
if ( V_2 . V_240 )
V_39 = 0 ;
else if ( V_2 . V_239 )
V_39 = 1 ;
F_131 ( false ) ;
V_257 = F_132 ( V_66 ) ;
if ( V_257 ) {
F_133 ( V_66 , V_257 , V_220 , V_221 ) ;
F_17 ( L_21 , V_220 ) ;
}
V_257 = F_134 ( V_66 ) ;
if ( V_257 ) {
int V_262 = V_126 ;
F_133 ( V_66 , V_257 , V_220 , V_221 ) ;
F_87 ( L_21 , V_220 ) ;
V_257 = - V_262 ;
goto V_261;
}
if ( F_98 ( V_66 ) )
V_66 -> V_232 = true ;
if ( F_135 ( V_2 . V_82 , V_66 ) < 0 )
F_128 ( V_256 , V_229 ) ;
if ( ! V_2 . V_82 -> V_83 &&
F_136 ( V_2 . V_82 ) < 0 ) {
F_87 ( L_188 ) ;
goto V_261;
}
V_154 . V_60 = V_2 . V_82 -> V_83 ;
if ( V_2 . V_81 < 1 )
V_2 . V_81 = 1 ;
if ( F_137 ( V_190 ) ) {
V_257 = - V_198 ;
goto V_261;
}
V_2 . V_48 = F_53 ( V_2 . V_82 ) ;
if ( ! V_154 . V_197 ) {
V_154 . V_164 = false ;
F_138 () ;
}
V_154 . V_263 = sizeof( struct V_13 ) ;
V_154 . V_264 = ( V_154 . V_162 == NULL ) ;
if ( F_139 ( NULL ) < 0 )
return - 1 ;
F_140 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_2 ,
. V_98 = V_99 ,
} ;
F_1 ( & V_2 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
}
V_257 = F_92 ( & V_2 ) ;
V_261:
F_141 ( V_2 . V_82 ) ;
return V_257 ;
}
