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
} else {
char V_26 [ V_27 ] ;
F_13 ( V_12 , V_15 , V_16 , V_26 , sizeof( V_26 ) ) ;
F_6 ( L_4 , V_12 -> V_21 , V_26 ) ;
}
F_11 ( & V_14 -> V_23 ) ;
return V_16 ;
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
F_15 ( V_12 ) ;
}
static void F_16 ( struct V_15 * V_15 , struct V_11 * V_12 , T_4 V_28 )
{
struct V_29 V_30 ;
int V_16 = F_17 ( & V_30 ) ;
F_18 ( L_5
L_6 V_31 L_7
L_8
L_9 V_31 L_10 V_31 L_7
L_11 V_31 L_10 V_31 L_12
L_13
L_14
L_15
L_16
L_17 ,
V_28 , V_15 -> V_18 -> V_32 , F_19 ( V_15 -> V_18 ) ,
V_15 -> V_33 , V_15 -> V_34 , V_12 -> V_33 , V_12 -> V_34 ,
V_12 -> V_35 == V_36 ? 'g' :
V_12 -> V_35 == V_37 ? 'l' : 'w' , V_12 -> V_21 ,
V_16 ? L_18 : V_30 . V_38 ,
V_16 ? L_18 : V_30 . V_39 , V_40 ) ;
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_15 -> V_42 = true ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_43 , T_4 V_28 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
int V_16 = 0 ;
if ( V_12 == NULL || ( V_41 == 0 &&
( V_2 -> V_25 == NULL ||
V_2 -> V_25 -> V_17 . V_12 != V_12 ) ) )
return;
V_14 = F_8 ( V_12 ) ;
if ( F_21 ( & V_14 -> V_23 ) )
return;
V_16 = F_22 ( V_10 , V_43 , V_28 ) ;
F_11 ( & V_14 -> V_23 ) ;
if ( F_23 ( V_16 ) ) {
F_11 ( & V_10 -> V_44 -> V_23 ) ;
if ( V_16 == - V_45 && ! V_10 -> V_17 . V_15 -> V_42 )
F_16 ( V_10 -> V_17 . V_15 , V_12 , V_28 ) ;
else if ( V_16 == - V_46 ) {
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
}
F_9 ( & V_10 -> V_44 -> V_23 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_47 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_48;
printf ( L_19 , F_25 ( V_2 -> V_49 ) , V_11 -> V_21 ) ;
printf ( L_20 , V_2 -> V_50 ) ;
V_47 = F_26 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_49 ,
0 , V_2 -> V_50 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_51 -> V_52 ) {
if ( V_2 -> V_53 )
F_27 ( V_11 , V_2 -> V_49 -> V_54 ) ;
else
F_28 ( V_11 , V_2 -> V_49 -> V_54 ) ;
}
if ( V_47 != 0 )
printf ( L_21 , V_47 ) ;
V_48:
F_11 ( & V_14 -> V_23 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
char V_55 [ 160 ] ;
int V_56 = 0 ;
const int V_57 = V_2 -> V_4 . V_58 - 1 ;
struct V_59 * V_60 = V_2 -> V_49 ;
struct V_44 * V_44 = F_30 ( V_60 ) ;
puts ( V_61 ) ;
F_31 ( V_2 , V_55 , sizeof( V_55 ) ) ;
printf ( L_22 , V_55 ) ;
F_32 ( V_2 ) ;
printf ( L_23 , V_57 , V_57 , V_62 ) ;
if ( V_44 -> V_63 . V_64 !=
V_44 -> V_63 . V_65 [ V_66 ] ) {
V_44 -> V_63 . V_64 =
V_44 -> V_63 . V_65 [ V_66 ] ;
F_33 ( stdout , V_67 ,
L_24 ,
V_44 -> V_63 . V_64 ) ;
++ V_56 ;
}
if ( V_2 -> V_25 ) {
F_24 ( V_2 ) ;
return;
}
if ( V_2 -> V_51 -> V_52 ) {
if ( V_2 -> V_53 ) {
F_34 ( V_44 ) ;
} else {
F_35 ( V_44 , V_2 -> V_68 ,
V_2 -> V_69 ) ;
}
}
F_36 ( V_44 , NULL ) ;
F_37 ( V_60 , NULL ) ;
F_38 ( V_44 , V_2 -> V_3 - V_56 ) ;
putchar ( '\n' ) ;
F_39 ( V_44 , false , V_2 -> V_3 - V_56 , V_57 ,
V_2 -> V_70 , stdout , V_71 . V_72 ) ;
}
static void F_40 ( int * V_73 , const char * V_26 )
{
char * V_74 = malloc ( 0 ) , * V_75 ;
T_5 V_76 = 0 ;
int V_77 ;
fprintf ( stdout , L_25 , V_26 ) ;
if ( F_41 ( & V_74 , & V_76 , V_78 ) < 0 )
return;
V_75 = strchr ( V_74 , '\n' ) ;
if ( V_75 )
* V_75 = 0 ;
V_75 = V_74 ;
while( * V_75 ) {
if ( ! isdigit ( * V_75 ) )
goto V_79;
V_75 ++ ;
}
V_77 = strtoul ( V_74 , NULL , 10 ) ;
* V_73 = V_77 ;
V_79:
free ( V_74 ) ;
}
static void F_42 ( int * V_73 , const char * V_26 )
{
int V_77 = 0 ;
F_40 ( & V_77 , V_26 ) ;
if ( V_77 >= 0 && V_77 <= 100 )
* V_73 = V_77 ;
}
static void F_43 ( struct V_1 * V_2 , const char * V_26 )
{
char * V_74 = malloc ( 0 ) , * V_75 ;
struct V_9 * V_80 = V_2 -> V_25 , * V_81 , * V_82 = NULL ;
struct V_44 * V_44 = F_30 ( V_2 -> V_49 ) ;
struct V_83 * V_84 ;
T_5 V_76 = 0 ;
if ( V_80 ) {
F_14 ( V_80 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_25 , V_26 ) ;
if ( F_41 ( & V_74 , & V_76 , V_78 ) < 0 )
goto V_79;
V_75 = strchr ( V_74 , '\n' ) ;
if ( V_75 )
* V_75 = 0 ;
V_84 = F_44 ( & V_44 -> V_85 ) ;
while ( V_84 ) {
V_81 = F_45 ( V_84 , struct V_9 , V_83 ) ;
if ( V_81 -> V_17 . V_12 && ! strcmp ( V_74 , V_81 -> V_17 . V_12 -> V_21 ) ) {
V_82 = V_81 ;
break;
}
V_84 = F_46 ( & V_81 -> V_83 ) ;
}
if ( ! V_82 ) {
fprintf ( V_86 , L_26 , V_74 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_82 ) ;
V_79:
free ( V_74 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_27 ) ;
fprintf ( stdout , L_28 , V_2 -> V_87 ) ;
fprintf ( stdout , L_29 , V_2 -> V_3 ) ;
if ( V_2 -> V_51 -> V_88 > 1 )
fprintf ( stdout , L_30 , F_25 ( V_2 -> V_49 ) ) ;
fprintf ( stdout , L_31 , V_2 -> V_89 ) ;
fprintf ( stdout , L_32 , V_2 -> V_50 ) ;
fprintf ( stdout , L_33 , V_21 ? : L_34 ) ;
fprintf ( stdout , L_35 ) ;
fprintf ( stdout ,
L_36 ,
V_2 -> V_69 ? L_37 : L_38 ) ;
fprintf ( stdout ,
L_39 ,
V_2 -> V_68 ? L_37 : L_38 ) ;
fprintf ( stdout , L_40 , V_2 -> V_53 ? 1 : 0 ) ;
fprintf ( stdout , L_41 ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_90 )
{
switch ( V_90 ) {
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
return V_2 -> V_51 -> V_88 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_49 ( struct V_1 * V_2 , int V_90 )
{
bool V_91 = true ;
if ( ! F_48 ( V_2 , V_90 ) ) {
struct V_92 V_93 = { . V_94 = 0 , . V_95 = V_96 } ;
struct V_97 V_98 ;
F_47 ( V_2 ) ;
fprintf ( stdout , L_42 ) ;
fflush ( stdout ) ;
F_50 ( & V_98 ) ;
F_51 ( & V_93 , 1 , - 1 ) ;
V_90 = getc ( V_78 ) ;
F_52 ( 0 , V_99 , & V_98 ) ;
if ( ! F_48 ( V_2 , V_90 ) )
return V_91 ;
}
switch ( V_90 ) {
case 'd' :
F_40 ( & V_2 -> V_87 , L_43 ) ;
if ( V_2 -> V_87 < 1 )
V_2 -> V_87 = 1 ;
break;
case 'e' :
F_40 ( & V_2 -> V_3 , L_44 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_100 V_101 = {
. V_102 = F_2 ,
. V_103 = V_104 ,
} ;
F_2 ( V_105 , NULL , V_2 ) ;
V_100 ( V_105 , & V_101 , NULL ) ;
} else {
signal ( V_105 , V_106 ) ;
}
break;
case 'E' :
if ( V_2 -> V_51 -> V_88 > 1 ) {
int V_43 = 0 ;
fprintf ( V_86 , L_45 ) ;
F_53 (top->evlist, top->sym_evsel)
fprintf ( V_86 , L_46 , V_2 -> V_49 -> V_54 , F_25 ( V_2 -> V_49 ) ) ;
F_40 ( & V_43 , L_47 ) ;
if ( V_43 >= V_2 -> V_51 -> V_88 ) {
V_2 -> V_49 = F_54 ( V_2 -> V_51 ) ;
fprintf ( V_86 , L_48 , F_25 ( V_2 -> V_49 ) ) ;
F_7 ( 1 ) ;
break;
}
F_53 (top->evlist, top->sym_evsel)
if ( V_2 -> V_49 -> V_54 == V_43 )
break;
} else
V_2 -> V_49 = F_54 ( V_2 -> V_51 ) ;
break;
case 'f' :
F_40 ( & V_2 -> V_89 , L_49 ) ;
break;
case 'F' :
F_42 ( & V_2 -> V_50 ,
L_50 ) ;
break;
case 'K' :
V_2 -> V_69 = ! V_2 -> V_69 ;
break;
case 'q' :
case 'Q' :
printf ( L_51 ) ;
if ( V_2 -> V_107 )
F_55 ( V_2 -> V_108 , V_86 ) ;
V_91 = false ;
break;
case 's' :
F_43 ( V_2 , L_52 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_80 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_14 ( V_80 ) ;
}
break;
case 'U' :
V_2 -> V_68 = ! V_2 -> V_68 ;
break;
case 'z' :
V_2 -> V_53 = ! V_2 -> V_53 ;
break;
default:
break;
}
return V_91 ;
}
static void F_56 ( void * V_8 )
{
struct V_1 * V_109 = V_8 ;
struct V_59 * V_60 = V_109 -> V_49 ;
struct V_44 * V_44 ;
F_32 ( V_109 ) ;
if ( V_109 -> V_51 -> V_110 != NULL )
V_109 -> V_49 = V_109 -> V_51 -> V_110 ;
V_44 = F_30 ( V_60 ) ;
if ( V_109 -> V_51 -> V_52 ) {
if ( V_109 -> V_53 ) {
F_34 ( V_44 ) ;
} else {
F_35 ( V_44 , V_109 -> V_68 ,
V_109 -> V_69 ) ;
}
}
F_36 ( V_44 , NULL ) ;
F_37 ( V_60 , NULL ) ;
}
static void * F_57 ( void * V_8 )
{
struct V_59 * V_111 ;
struct V_1 * V_2 = V_8 ;
const char * V_112 = L_53 ;
struct V_113 V_114 = {
. V_115 = F_56 ,
. V_8 = V_2 ,
. V_116 = V_2 -> V_87 ,
} ;
F_56 ( V_2 ) ;
F_53 (top->evlist, pos) {
struct V_44 * V_44 = F_30 ( V_111 ) ;
V_44 -> V_117 = V_2 -> V_118 . V_73 . V_119 ;
}
F_58 ( V_2 -> V_51 , V_112 , & V_114 ,
V_2 -> V_70 ,
& V_2 -> V_108 -> V_120 . V_121 ) ;
V_122 = 1 ;
return NULL ;
}
static void F_59 ( int T_1 V_7 )
{
V_122 = 1 ;
}
static void F_60 ( void )
{
signal ( V_123 , V_124 ) ;
signal ( V_125 , V_124 ) ;
signal ( V_126 , F_59 ) ;
signal ( V_127 , F_59 ) ;
signal ( V_128 , F_59 ) ;
}
static void * F_61 ( void * V_8 )
{
struct V_92 V_93 = { . V_94 = 0 , . V_95 = V_96 } ;
struct V_97 V_98 ;
struct V_1 * V_2 = V_8 ;
int V_129 , V_90 ;
F_60 () ;
F_62 () ;
V_130:
V_129 = V_2 -> V_87 * 1000 ;
F_50 ( & V_98 ) ;
getc ( V_78 ) ;
while ( ! V_122 ) {
F_29 ( V_2 ) ;
switch ( F_51 ( & V_93 , 1 , V_129 ) ) {
case 0 :
continue;
case - 1 :
if ( V_131 == V_132 )
continue;
default:
V_90 = getc ( V_78 ) ;
F_52 ( 0 , V_99 , & V_98 ) ;
if ( F_49 ( V_2 , V_90 ) )
goto V_130;
V_122 = 1 ;
}
}
F_52 ( 0 , V_99 , & V_98 ) ;
return NULL ;
}
static int F_63 ( struct V_15 * V_15 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
if ( ! F_64 ( V_15 ) )
return 0 ;
if ( V_21 [ 0 ] == '.' )
V_21 ++ ;
if ( ! strcmp ( V_21 , L_54 ) ||
! strcmp ( V_21 , L_55 ) ||
! strcmp ( V_21 , L_56 ) ||
! strncmp ( L_57 , V_21 , 11 ) ||
! strncmp ( L_58 , V_21 , 14 ) ||
strstr ( V_21 , L_59 ) ||
strstr ( V_21 , L_60 ) )
return 1 ;
if ( F_65 ( V_12 ) )
V_12 -> V_133 = true ;
return 0 ;
}
static int F_66 ( struct V_134 * V_135 ,
struct V_136 * V_137 , bool V_138 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_59 * V_60 = V_135 -> V_60 ;
if ( V_139 . V_12 && V_138 )
F_20 ( V_2 , V_10 , V_60 -> V_54 , V_137 -> V_140 ) ;
F_67 ( V_135 -> V_141 -> V_142 , V_137 , V_135 -> V_141 ,
! ( V_2 -> V_118 . V_142 & V_143 ) ) ;
return 0 ;
}
static void F_68 ( struct V_144 * V_145 ,
const union V_146 * V_147 ,
struct V_59 * V_60 ,
struct V_148 * V_141 ,
struct V_38 * V_38 )
{
struct V_1 * V_2 = F_69 ( V_145 , struct V_1 , V_145 ) ;
struct V_136 V_137 ;
int V_16 ;
if ( ! V_38 && V_149 ) {
static struct V_150 * V_151 ;
if ( ! V_151 )
V_151 = F_70 ( NULL ) ;
if ( ! F_71 ( V_151 , V_141 -> V_152 ) ) {
F_6 ( L_61 ,
V_141 -> V_152 ) ;
F_72 ( V_151 , V_141 -> V_152 ) ;
}
return;
}
if ( ! V_38 ) {
F_6 ( L_62 ,
V_2 -> V_108 -> V_51 -> V_63 . V_153 ++ ) ;
return;
}
if ( V_147 -> V_120 . V_154 & V_155 )
V_2 -> V_156 ++ ;
if ( F_73 ( V_38 , & V_137 , V_141 ) < 0 )
return;
if ( ! V_38 -> V_157 &&
V_71 . V_158 &&
V_137 . V_159 == V_160 ) {
F_18 (
L_63
L_64
L_65 ,
V_137 . V_15 && ! F_74 ( & V_137 . V_15 -> V_18 -> V_161 [ V_162 ] ) ?
L_66 : L_67 ) ;
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_38 -> V_157 = true ;
}
if ( V_137 . V_12 == NULL ) {
const char * V_26 = L_68 ;
if ( ! V_38 -> V_157 && ! V_2 -> V_163 &&
V_137 . V_15 == V_38 -> V_164 [ V_162 ] &&
F_74 ( & V_137 . V_15 -> V_18 -> V_161 [ V_162 ] ) ) {
if ( V_71 . V_165 ) {
char V_166 [ 256 ] ;
F_75 ( V_137 . V_15 -> V_18 , V_166 , sizeof( V_166 ) ) ;
F_18 ( L_69 ,
V_71 . V_165 , V_166 , V_26 ) ;
} else {
F_18 ( L_70 ,
V_26 ) ;
}
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_163 = true ;
}
}
if ( V_137 . V_12 == NULL || ! V_137 . V_12 -> V_133 ) {
struct V_44 * V_44 = F_30 ( V_60 ) ;
struct V_134 V_135 = {
. V_60 = V_60 ,
. V_141 = V_141 ,
. V_167 = F_66 ,
} ;
if ( V_71 . V_168 )
V_135 . V_169 = & V_170 ;
else
V_135 . V_169 = & V_171 ;
F_9 ( & V_44 -> V_23 ) ;
V_16 = F_76 ( & V_135 , & V_137 , V_2 -> V_172 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_71 ) ;
F_11 ( & V_44 -> V_23 ) ;
}
F_77 ( & V_137 ) ;
}
static void F_78 ( struct V_1 * V_2 , int V_54 )
{
struct V_148 V_141 ;
struct V_59 * V_60 ;
struct V_173 * V_108 = V_2 -> V_108 ;
union V_146 * V_147 ;
struct V_38 * V_38 ;
int V_91 ;
while ( ( V_147 = F_79 ( V_2 -> V_51 , V_54 ) ) != NULL ) {
V_91 = F_80 ( V_2 -> V_51 , V_147 , & V_141 ) ;
if ( V_91 ) {
F_6 ( L_72 , V_91 ) ;
goto V_174;
}
V_60 = F_81 ( V_108 -> V_51 , V_141 . V_175 ) ;
assert ( V_60 != NULL ) ;
if ( V_147 -> V_120 . type == V_176 )
++ V_2 -> V_177 ;
switch ( V_141 . V_159 ) {
case V_178 :
++ V_2 -> V_179 ;
if ( V_2 -> V_68 )
goto V_174;
V_38 = & V_108 -> V_180 . V_181 ;
break;
case V_160 :
++ V_2 -> V_182 ;
if ( V_2 -> V_69 )
goto V_174;
V_38 = & V_108 -> V_180 . V_181 ;
break;
case V_183 :
++ V_2 -> V_184 ;
V_38 = F_82 ( V_108 ,
V_141 . V_152 ) ;
break;
case V_185 :
++ V_2 -> V_186 ;
goto V_174;
default:
if ( V_147 -> V_120 . type == V_176 )
goto V_174;
V_38 = & V_108 -> V_180 . V_181 ;
break;
}
if ( V_147 -> V_120 . type == V_176 ) {
F_68 ( & V_2 -> V_145 , V_147 , V_60 ,
& V_141 , V_38 ) ;
} else if ( V_147 -> V_120 . type < V_187 ) {
F_83 ( F_30 ( V_60 ) , V_147 -> V_120 . type ) ;
F_84 ( V_38 , V_147 , & V_141 ) ;
} else
++ V_108 -> V_51 -> V_63 . V_188 ;
V_174:
F_85 ( V_2 -> V_51 , V_54 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
int V_189 ;
for ( V_189 = 0 ; V_189 < V_2 -> V_51 -> V_190 ; V_189 ++ )
F_78 ( V_2 , V_189 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
char V_26 [ 512 ] ;
struct V_59 * V_43 ;
struct V_191 * V_51 = V_2 -> V_51 ;
struct V_118 * V_192 = & V_2 -> V_118 ;
F_88 ( V_51 , V_192 , & V_193 ) ;
F_53 (evlist, counter) {
V_194:
if ( F_89 ( V_43 , V_2 -> V_51 -> V_195 ,
V_2 -> V_51 -> V_196 ) < 0 ) {
if ( F_90 ( V_43 , V_131 , V_26 , sizeof( V_26 ) ) ) {
if ( V_197 )
F_18 ( L_22 , V_26 ) ;
goto V_194;
}
F_91 ( V_43 , & V_192 -> V_73 ,
V_131 , V_26 , sizeof( V_26 ) ) ;
F_92 ( L_22 , V_26 ) ;
goto V_198;
}
}
if ( F_93 ( V_51 , V_192 -> V_199 , false ) < 0 ) {
F_92 ( L_73 ,
V_131 , F_94 ( V_131 , V_26 , sizeof( V_26 ) ) ) ;
goto V_198;
}
return 0 ;
V_198:
return - 1 ;
}
static int F_95 ( struct V_193 * V_200 )
{
if ( ! V_139 . V_12 ) {
if ( V_200 -> V_52 ) {
F_92 ( L_74 ) ;
return - V_201 ;
}
} else if ( V_200 -> V_202 != V_203 ) {
if ( F_96 ( V_200 ) < 0 ) {
F_92 ( L_75 ) ;
return - V_201 ;
}
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_118 * V_192 = & V_2 -> V_118 ;
T_6 V_204 ;
int V_91 ;
V_2 -> V_108 = F_98 ( NULL , false , NULL ) ;
if ( V_2 -> V_108 == NULL )
return - 1 ;
F_99 ( & V_2 -> V_108 -> V_180 , F_63 ) ;
if ( ! V_205 ) {
V_91 = F_100 ( & V_2 -> V_108 -> V_120 . V_121 ) ;
if ( V_91 )
goto V_206;
}
V_91 = F_95 ( & V_193 ) ;
if ( V_91 )
goto V_206;
if ( F_101 ( V_2 -> V_108 ) < 0 )
goto V_206;
F_102 ( & V_2 -> V_108 -> V_180 . V_181 , & V_192 -> V_73 ,
V_2 -> V_51 -> V_196 , false , V_192 -> V_207 ) ;
if ( V_139 . V_208 ) {
V_91 = F_103 ( & V_209 ) ;
if ( V_91 < 0 )
goto V_210;
}
V_91 = F_87 ( V_2 ) ;
if ( V_91 )
goto V_206;
V_2 -> V_108 -> V_51 = V_2 -> V_51 ;
F_104 ( V_2 -> V_108 ) ;
if ( ! F_105 ( & V_192 -> V_73 ) )
F_106 ( V_2 -> V_51 ) ;
F_107 ( V_2 -> V_51 , 100 ) ;
F_86 ( V_2 ) ;
V_91 = - 1 ;
if ( F_108 ( & V_204 , NULL , ( V_41 > 0 ? F_57 :
F_61 ) , V_2 ) ) {
F_92 ( L_76 ) ;
goto V_206;
}
if ( V_2 -> V_211 ) {
struct V_212 V_213 ;
V_213 . V_214 = V_2 -> V_211 ;
if ( F_109 ( 0 , V_215 , & V_213 ) ) {
F_92 ( L_77 ) ;
goto V_216;
}
}
while ( ! V_122 ) {
T_4 V_217 = V_2 -> V_177 ;
F_86 ( V_2 ) ;
if ( V_217 == V_2 -> V_177 )
V_91 = F_107 ( V_2 -> V_51 , 100 ) ;
}
V_91 = 0 ;
V_216:
F_110 ( V_204 , NULL ) ;
V_206:
F_111 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
return V_91 ;
V_210: {
char V_218 [ V_27 ] ;
const char * V_16 = F_94 ( - V_91 , V_218 , sizeof( V_218 ) ) ;
F_92 ( L_78 , V_16 ) ;
goto V_206;
}
}
static int
F_112 ( const struct V_219 * V_220 , const char * V_8 , int V_221 )
{
V_71 . V_72 = true ;
return F_113 ( V_220 , V_8 , V_221 ) ;
}
static int
F_114 ( const struct V_219 * V_220 , const char * V_8 , int V_221 )
{
struct V_193 * V_200 = V_220 -> V_222 ;
V_200 -> V_52 = ! V_221 ;
V_200 -> V_223 = V_224 ;
if ( V_221 ) {
V_71 . V_72 = false ;
V_200 -> V_223 = V_225 ;
return 0 ;
}
return F_115 ( V_8 ) ;
}
static int F_116 ( const char * V_226 , const char * V_222 , void * T_7 V_7 )
{
if ( ! strcmp ( V_226 , L_79 ) )
V_226 = L_80 ;
if ( ! strcmp ( V_226 , L_81 ) ) {
V_71 . V_168 = F_117 ( V_226 , V_222 ) ;
return 0 ;
}
return 0 ;
}
static int
F_118 ( const struct V_219 * V_220 , const char * V_8 ,
int V_221 V_7 )
{
struct V_1 * V_2 = V_220 -> V_222 ;
V_2 -> V_70 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_119 ( int V_227 , const char * * V_228 , const char * T_8 V_7 )
{
char V_218 [ V_27 ] ;
struct V_1 V_2 = {
. V_89 = 5 ,
. V_87 = 2 ,
. V_118 = {
. V_199 = V_229 ,
. V_230 = V_229 ,
. V_231 = V_232 ,
. V_233 = 4000 ,
. V_73 = {
. V_234 = true ,
} ,
. V_207 = 500 ,
} ,
. V_172 = V_235 ,
. V_50 = 5 ,
} ;
struct V_118 * V_192 = & V_2 . V_118 ;
struct V_73 * V_73 = & V_192 -> V_73 ;
const struct V_219 V_236 [] = {
F_120 ( 'e' , L_82 , & V_2 . V_51 , L_82 ,
L_83 ,
V_237 ) ,
F_121 ( 'c' , L_84 , & V_192 -> V_231 , L_85 ) ,
F_122 ( 'p' , L_86 , & V_73 -> V_152 , L_86 ,
L_87 ) ,
F_122 ( 't' , L_88 , & V_73 -> V_238 , L_88 ,
L_89 ) ,
F_123 ( 'a' , L_90 , & V_73 -> V_239 ,
L_91 ) ,
F_122 ( 'C' , L_92 , & V_73 -> V_240 , L_92 ,
L_93 ) ,
F_122 ( 'k' , L_94 , & V_71 . V_165 ,
L_95 , L_96 ) ,
F_123 ( 0 , L_97 , & V_71 . V_241 ,
L_98 ) ,
F_123 ( 'K' , L_99 , & V_2 . V_69 ,
L_100 ) ,
F_120 ( 'm' , L_101 , & V_192 -> V_199 , L_102 ,
L_103 ,
V_242 ) ,
F_124 ( 'r' , L_104 , & V_2 . V_211 ,
L_105 ) ,
F_124 ( 'd' , L_106 , & V_2 . V_87 ,
L_107 ) ,
F_123 ( 'D' , L_108 , & V_2 . V_107 ,
L_109 ) ,
F_124 ( 'f' , L_110 , & V_2 . V_89 ,
L_111 ) ,
F_123 ( 0 , L_112 , & V_192 -> V_243 ,
L_113 ) ,
F_123 ( 'i' , L_114 , & V_192 -> V_244 ,
L_115 ) ,
F_122 ( 0 , L_116 , & V_2 . V_245 , L_117 ,
L_118 ) ,
F_123 ( 'z' , L_119 , & V_2 . V_53 , L_120 ) ,
F_125 ( 'F' , L_121 , & V_192 -> V_230 , L_122 ) ,
F_124 ( 'E' , L_123 , & V_2 . V_3 ,
L_124 ) ,
F_123 ( 'U' , L_125 , & V_2 . V_68 ,
L_126 ) ,
F_123 ( 0 , L_127 , & V_2 . V_246 , L_128 ) ,
F_123 ( 0 , L_129 , & V_2 . V_247 , L_130 ) ,
F_126 ( 'v' , L_131 , & V_197 ,
L_132 ) ,
F_122 ( 's' , L_133 , & V_248 , L_134 ,
L_135
L_136 ) ,
F_122 ( 0 , L_137 , & V_249 , L_138 ,
L_139 ) ,
F_123 ( 'n' , L_140 , & V_71 . V_250 ,
L_141 ) ,
F_127 ( 'g' , NULL , & V_193 ,
NULL , L_142 ,
& F_112 ) ,
F_120 ( 0 , L_143 , & V_193 ,
L_144 ,
V_251 , & F_114 ) ,
F_123 ( 0 , L_145 , & V_71 . V_168 ,
L_146 ) ,
F_124 ( 0 , L_147 , & V_2 . V_172 ,
L_148
L_149 F_128 ( V_252 ) ) ,
F_120 ( 0 , L_150 , NULL , L_151 ,
L_152 ,
V_253 ) ,
F_123 ( 0 , L_153 , & V_71 . V_254 ,
L_154 ) ,
F_122 ( 0 , L_155 , & V_71 . V_255 , L_156 ,
L_157 ) ,
F_122 ( 0 , L_158 , & V_71 . V_256 , L_159 ,
L_160 ) ,
F_122 ( 0 , L_161 , & V_71 . V_257 , L_162 ,
L_163 ) ,
F_123 ( 0 , L_164 , & V_71 . V_258 ,
L_165 ) ,
F_123 ( 0 , L_166 , & V_71 . V_259 ,
L_167 ) ,
F_123 ( 0 , L_168 , & V_71 . V_260 ,
L_169 ) ,
F_122 ( 0 , L_170 , & V_205 , L_171 ,
L_172 ) ,
F_122 ( 'M' , L_173 , & V_261 , L_174 ,
L_175 ) ,
F_122 ( 'u' , L_176 , & V_73 -> V_119 , L_177 , L_178 ) ,
F_120 ( 0 , L_179 , & V_2 , L_180 ,
L_181 , F_118 ) ,
F_120 ( 0 , L_182 , NULL , L_183 ,
L_184 , V_262 ) ,
F_122 ( 'w' , L_185 , & V_71 . V_263 ,
L_186 ,
L_187 ) ,
F_125 ( 0 , L_188 , & V_192 -> V_207 ,
L_189 ) ,
F_127 ( 'b' , L_190 , & V_192 -> V_142 ,
L_191 , L_192 ,
V_264 ) ,
F_120 ( 'j' , L_193 , & V_192 -> V_142 ,
L_194 , L_195 ,
V_264 ) ,
F_123 ( 0 , L_196 , & V_71 . V_265 ,
L_197 ) ,
F_123 ( 0 , L_198 , & V_71 . V_266 ,
L_199 ) ,
F_129 ()
} ;
const char * const V_267 [] = {
L_200 ,
NULL
} ;
int V_268 = F_130 () ;
if ( V_268 < 0 )
return V_268 ;
V_2 . V_51 = F_131 () ;
if ( V_2 . V_51 == NULL )
return - V_46 ;
F_132 ( F_116 , & V_2 ) ;
V_227 = F_133 ( V_227 , V_228 , V_236 , V_267 , 0 ) ;
if ( V_227 )
F_134 ( V_267 , V_236 ) ;
if ( ! V_2 . V_51 -> V_88 &&
F_135 ( V_2 . V_51 ) < 0 ) {
F_6 ( L_201 ) ;
goto V_269;
}
if ( V_71 . V_266 ) {
V_71 . V_270 = false ;
V_71 . V_168 = false ;
if ( V_249 ) {
F_6 ( L_202 ) ;
F_136 ( V_267 , V_236 , L_137 , 0 ) ;
F_136 ( NULL , V_236 , L_198 , 0 ) ;
goto V_269;
}
}
V_271 = V_272 ;
V_139 . V_273 = 1 ;
if ( V_2 . V_247 )
V_41 = 0 ;
else if ( V_2 . V_246 )
V_41 = 1 ;
F_137 ( false ) ;
if ( F_138 ( V_2 . V_51 ) < 0 ) {
if ( V_248 )
F_136 ( V_267 , V_236 , L_203 , 1 ) ;
if ( V_249 )
F_136 ( V_248 ? NULL : V_267 ,
V_236 , L_137 , 0 ) ;
goto V_269;
}
V_268 = F_139 ( V_73 ) ;
if ( V_268 ) {
F_140 ( V_73 , V_268 , V_218 , V_27 ) ;
F_18 ( L_22 , V_218 ) ;
}
V_268 = F_141 ( V_73 ) ;
if ( V_268 ) {
int V_274 = V_131 ;
F_140 ( V_73 , V_268 , V_218 , V_27 ) ;
F_92 ( L_22 , V_218 ) ;
V_268 = - V_274 ;
goto V_269;
}
if ( F_105 ( V_73 ) )
V_73 -> V_239 = true ;
if ( F_142 ( V_2 . V_51 , V_73 ) < 0 ) {
F_92 ( L_204 ,
V_131 == V_275 ? L_205 : F_94 ( V_131 , V_218 , sizeof( V_218 ) ) ) ;
goto V_269;
}
V_71 . V_65 = V_2 . V_51 -> V_88 ;
if ( V_2 . V_87 < 1 )
V_2 . V_87 = 1 ;
if ( F_143 ( V_192 ) ) {
V_268 = - V_201 ;
goto V_269;
}
V_2 . V_49 = F_54 ( V_2 . V_51 ) ;
if ( ! V_193 . V_52 ) {
V_71 . V_168 = false ;
F_144 () ;
}
if ( V_71 . V_168 && ! V_193 . V_276 )
V_193 . V_277 = V_278 ;
V_71 . V_279 = sizeof( struct V_13 ) ;
V_71 . V_280 = ( V_71 . V_165 == NULL ) ;
if ( F_145 ( NULL ) < 0 )
return - 1 ;
F_146 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_100 V_101 = {
. V_102 = F_2 ,
. V_103 = V_104 ,
} ;
F_1 ( & V_2 ) ;
V_100 ( V_105 , & V_101 , NULL ) ;
}
V_268 = F_97 ( & V_2 ) ;
V_269:
F_147 ( V_2 . V_51 ) ;
return V_268 ;
}
