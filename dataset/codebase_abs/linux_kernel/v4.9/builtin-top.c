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
V_129 = V_2 -> V_87 * V_131 ;
F_50 ( & V_98 ) ;
getc ( V_78 ) ;
while ( ! V_122 ) {
F_29 ( V_2 ) ;
switch ( F_51 ( & V_93 , 1 , V_129 ) ) {
case 0 :
continue;
case - 1 :
if ( V_132 == V_133 )
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
static int F_63 ( struct V_134 * V_135 ,
struct V_136 * V_137 , bool V_138 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_135 -> V_10 ;
struct V_59 * V_60 = V_135 -> V_60 ;
if ( V_139 . V_12 && V_138 )
F_20 ( V_2 , V_10 , V_60 -> V_54 , V_137 -> V_140 ) ;
F_64 ( V_135 -> V_141 -> V_142 , V_137 , V_135 -> V_141 ,
! ( V_2 -> V_118 . V_142 & V_143 ) ) ;
return 0 ;
}
static void F_65 ( struct V_144 * V_145 ,
const union V_146 * V_147 ,
struct V_59 * V_60 ,
struct V_148 * V_141 ,
struct V_38 * V_38 )
{
struct V_1 * V_2 = F_66 ( V_145 , struct V_1 , V_145 ) ;
struct V_136 V_137 ;
int V_16 ;
if ( ! V_38 && V_149 ) {
static struct V_150 * V_151 ;
if ( ! V_151 )
V_151 = F_67 ( NULL ) ;
if ( ! F_68 ( V_151 , V_141 -> V_152 ) ) {
F_6 ( L_54 ,
V_141 -> V_152 ) ;
F_69 ( V_151 , V_141 -> V_152 ) ;
}
return;
}
if ( ! V_38 ) {
F_6 ( L_55 ,
V_2 -> V_108 -> V_51 -> V_63 . V_153 ++ ) ;
return;
}
if ( V_147 -> V_120 . V_154 & V_155 )
V_2 -> V_156 ++ ;
if ( F_70 ( V_38 , & V_137 , V_141 ) < 0 )
return;
if ( ! V_38 -> V_157 &&
V_71 . V_158 &&
V_137 . V_159 == V_160 ) {
F_18 (
L_56
L_57
L_58 ,
V_137 . V_15 && ! F_71 ( & V_137 . V_15 -> V_18 -> V_161 [ V_162 ] ) ?
L_59 : L_60 ) ;
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_38 -> V_157 = true ;
}
if ( V_137 . V_12 == NULL ) {
const char * V_26 = L_61 ;
if ( ! V_38 -> V_157 && ! V_2 -> V_163 &&
V_137 . V_15 == V_38 -> V_164 [ V_162 ] &&
F_71 ( & V_137 . V_15 -> V_18 -> V_161 [ V_162 ] ) ) {
if ( V_71 . V_165 ) {
char V_166 [ 256 ] ;
F_72 ( V_137 . V_15 -> V_18 , V_166 , sizeof( V_166 ) ) ;
F_18 ( L_62 ,
V_71 . V_165 , V_166 , V_26 ) ;
} else {
F_18 ( L_63 ,
V_26 ) ;
}
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_163 = true ;
}
}
if ( V_137 . V_12 == NULL || ! V_137 . V_12 -> V_167 ) {
struct V_44 * V_44 = F_30 ( V_60 ) ;
struct V_134 V_135 = {
. V_60 = V_60 ,
. V_141 = V_141 ,
. V_168 = F_63 ,
} ;
if ( V_71 . V_169 )
V_135 . V_170 = & V_171 ;
else
V_135 . V_170 = & V_172 ;
F_9 ( & V_44 -> V_23 ) ;
V_16 = F_73 ( & V_135 , & V_137 , V_2 -> V_173 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_64 ) ;
F_11 ( & V_44 -> V_23 ) ;
}
F_74 ( & V_137 ) ;
}
static void F_75 ( struct V_1 * V_2 , int V_54 )
{
struct V_148 V_141 ;
struct V_59 * V_60 ;
struct V_174 * V_108 = V_2 -> V_108 ;
union V_146 * V_147 ;
struct V_38 * V_38 ;
int V_91 ;
while ( ( V_147 = F_76 ( V_2 -> V_51 , V_54 ) ) != NULL ) {
V_91 = F_77 ( V_2 -> V_51 , V_147 , & V_141 ) ;
if ( V_91 ) {
F_6 ( L_65 , V_91 ) ;
goto V_175;
}
V_60 = F_78 ( V_108 -> V_51 , V_141 . V_176 ) ;
assert ( V_60 != NULL ) ;
if ( V_147 -> V_120 . type == V_177 )
++ V_2 -> V_178 ;
switch ( V_141 . V_159 ) {
case V_179 :
++ V_2 -> V_180 ;
if ( V_2 -> V_68 )
goto V_175;
V_38 = & V_108 -> V_181 . V_182 ;
break;
case V_160 :
++ V_2 -> V_183 ;
if ( V_2 -> V_69 )
goto V_175;
V_38 = & V_108 -> V_181 . V_182 ;
break;
case V_184 :
++ V_2 -> V_185 ;
V_38 = F_79 ( V_108 ,
V_141 . V_152 ) ;
break;
case V_186 :
++ V_2 -> V_187 ;
goto V_175;
default:
if ( V_147 -> V_120 . type == V_177 )
goto V_175;
V_38 = & V_108 -> V_181 . V_182 ;
break;
}
if ( V_147 -> V_120 . type == V_177 ) {
F_65 ( & V_2 -> V_145 , V_147 , V_60 ,
& V_141 , V_38 ) ;
} else if ( V_147 -> V_120 . type < V_188 ) {
F_80 ( F_30 ( V_60 ) , V_147 -> V_120 . type ) ;
F_81 ( V_38 , V_147 , & V_141 ) ;
} else
++ V_108 -> V_51 -> V_63 . V_189 ;
V_175:
F_82 ( V_2 -> V_51 , V_54 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
int V_190 ;
for ( V_190 = 0 ; V_190 < V_2 -> V_51 -> V_191 ; V_190 ++ )
F_75 ( V_2 , V_190 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
char V_26 [ 512 ] ;
struct V_59 * V_43 ;
struct V_192 * V_51 = V_2 -> V_51 ;
struct V_118 * V_193 = & V_2 -> V_118 ;
F_85 ( V_51 , V_193 , & V_194 ) ;
F_53 (evlist, counter) {
V_195:
if ( F_86 ( V_43 , V_2 -> V_51 -> V_196 ,
V_2 -> V_51 -> V_197 ) < 0 ) {
if ( F_87 ( V_43 , V_132 , V_26 , sizeof( V_26 ) ) ) {
if ( V_198 )
F_18 ( L_22 , V_26 ) ;
goto V_195;
}
F_88 ( V_43 , & V_193 -> V_73 ,
V_132 , V_26 , sizeof( V_26 ) ) ;
F_89 ( L_22 , V_26 ) ;
goto V_199;
}
}
if ( F_90 ( V_51 , V_193 -> V_200 , false ) < 0 ) {
F_89 ( L_66 ,
V_132 , F_91 ( V_132 , V_26 , sizeof( V_26 ) ) ) ;
goto V_199;
}
return 0 ;
V_199:
return - 1 ;
}
static int F_92 ( struct V_194 * V_201 )
{
if ( ! V_139 . V_12 ) {
if ( V_201 -> V_52 ) {
F_89 ( L_67 ) ;
return - V_202 ;
}
} else if ( V_201 -> V_203 != V_204 ) {
if ( F_93 ( V_201 ) < 0 ) {
F_89 ( L_68 ) ;
return - V_202 ;
}
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
char V_26 [ 512 ] ;
struct V_59 * V_111 ;
struct V_205 * V_206 ;
struct V_192 * V_51 = V_2 -> V_51 ;
struct V_118 * V_193 = & V_2 -> V_118 ;
T_6 V_207 ;
int V_91 ;
V_2 -> V_108 = F_95 ( NULL , false , NULL ) ;
if ( V_2 -> V_108 == NULL )
return - 1 ;
if ( ! V_208 ) {
V_91 = F_96 ( & V_2 -> V_108 -> V_120 . V_121 ) ;
if ( V_91 )
goto V_209;
}
V_91 = F_92 ( & V_194 ) ;
if ( V_91 )
goto V_209;
if ( F_97 ( V_2 -> V_108 ) < 0 )
goto V_209;
F_98 ( & V_2 -> V_108 -> V_181 . V_182 , & V_193 -> V_73 ,
V_2 -> V_51 -> V_197 , false , V_193 -> V_210 ) ;
if ( V_139 . V_211 ) {
V_91 = F_99 ( & V_212 ) ;
if ( V_91 < 0 )
goto V_213;
}
V_91 = F_84 ( V_2 ) ;
if ( V_91 )
goto V_209;
V_91 = F_100 ( V_51 , & V_111 , & V_206 ) ;
if ( V_91 ) {
error ( L_69 ,
V_206 -> V_214 . V_215 , F_25 ( V_111 ) , V_132 ,
F_91 ( V_132 , V_26 , sizeof( V_26 ) ) ) ;
goto V_209;
}
V_2 -> V_108 -> V_51 = V_2 -> V_51 ;
F_101 ( V_2 -> V_108 ) ;
if ( ! F_102 ( & V_193 -> V_73 ) )
F_103 ( V_2 -> V_51 ) ;
F_104 ( V_2 -> V_51 , 100 ) ;
F_83 ( V_2 ) ;
V_91 = - 1 ;
if ( F_105 ( & V_207 , NULL , ( V_41 > 0 ? F_57 :
F_61 ) , V_2 ) ) {
F_89 ( L_70 ) ;
goto V_209;
}
if ( V_2 -> V_216 ) {
struct V_217 V_218 ;
V_218 . V_219 = V_2 -> V_216 ;
if ( F_106 ( 0 , V_220 , & V_218 ) ) {
F_89 ( L_71 ) ;
goto V_221;
}
}
while ( ! V_122 ) {
T_4 V_222 = V_2 -> V_178 ;
F_83 ( V_2 ) ;
if ( V_222 == V_2 -> V_178 )
V_91 = F_104 ( V_2 -> V_51 , 100 ) ;
}
V_91 = 0 ;
V_221:
F_107 ( V_207 , NULL ) ;
V_209:
F_108 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
return V_91 ;
V_213: {
char V_223 [ V_27 ] ;
const char * V_16 = F_91 ( - V_91 , V_223 , sizeof( V_223 ) ) ;
F_89 ( L_72 , V_16 ) ;
goto V_209;
}
}
static int
F_109 ( const struct V_224 * V_225 , const char * V_8 , int V_226 )
{
V_71 . V_72 = true ;
return F_110 ( V_225 , V_8 , V_226 ) ;
}
static int
F_111 ( const struct V_224 * V_225 , const char * V_8 , int V_226 )
{
struct V_194 * V_201 = V_225 -> V_227 ;
V_201 -> V_52 = ! V_226 ;
V_201 -> V_228 = V_229 ;
if ( V_226 ) {
V_71 . V_72 = false ;
V_201 -> V_228 = V_230 ;
return 0 ;
}
return F_112 ( V_8 ) ;
}
static int F_113 ( const char * V_231 , const char * V_227 , void * T_7 V_7 )
{
if ( ! strcmp ( V_231 , L_73 ) )
V_231 = L_74 ;
if ( ! strcmp ( V_231 , L_75 ) ) {
V_71 . V_169 = F_114 ( V_231 , V_227 ) ;
return 0 ;
}
return 0 ;
}
static int
F_115 ( const struct V_224 * V_225 , const char * V_8 ,
int V_226 V_7 )
{
struct V_1 * V_2 = V_225 -> V_227 ;
V_2 -> V_70 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_116 ( int V_232 , const char * * V_233 , const char * T_8 V_7 )
{
char V_223 [ V_27 ] ;
struct V_1 V_2 = {
. V_89 = 5 ,
. V_87 = 2 ,
. V_118 = {
. V_200 = V_234 ,
. V_235 = V_234 ,
. V_236 = V_237 ,
. V_238 = 4000 ,
. V_73 = {
. V_239 = true ,
} ,
. V_210 = 500 ,
} ,
. V_173 = V_240 ,
. V_50 = 5 ,
} ;
struct V_118 * V_193 = & V_2 . V_118 ;
struct V_73 * V_73 = & V_193 -> V_73 ;
const struct V_224 V_241 [] = {
F_117 ( 'e' , L_76 , & V_2 . V_51 , L_76 ,
L_77 ,
V_242 ) ,
F_118 ( 'c' , L_78 , & V_193 -> V_236 , L_79 ) ,
F_119 ( 'p' , L_80 , & V_73 -> V_152 , L_80 ,
L_81 ) ,
F_119 ( 't' , L_82 , & V_73 -> V_243 , L_82 ,
L_83 ) ,
F_120 ( 'a' , L_84 , & V_73 -> V_244 ,
L_85 ) ,
F_119 ( 'C' , L_86 , & V_73 -> V_245 , L_86 ,
L_87 ) ,
F_119 ( 'k' , L_88 , & V_71 . V_165 ,
L_89 , L_90 ) ,
F_120 ( 0 , L_91 , & V_71 . V_246 ,
L_92 ) ,
F_120 ( 'K' , L_93 , & V_2 . V_69 ,
L_94 ) ,
F_117 ( 'm' , L_95 , & V_193 -> V_200 , L_96 ,
L_97 ,
V_247 ) ,
F_121 ( 'r' , L_98 , & V_2 . V_216 ,
L_99 ) ,
F_121 ( 'd' , L_100 , & V_2 . V_87 ,
L_101 ) ,
F_120 ( 'D' , L_102 , & V_2 . V_107 ,
L_103 ) ,
F_121 ( 'f' , L_104 , & V_2 . V_89 ,
L_105 ) ,
F_120 ( 0 , L_106 , & V_193 -> V_248 ,
L_107 ) ,
F_120 ( 'i' , L_108 , & V_193 -> V_249 ,
L_109 ) ,
F_119 ( 0 , L_110 , & V_2 . V_250 , L_111 ,
L_112 ) ,
F_120 ( 'z' , L_113 , & V_2 . V_53 , L_114 ) ,
F_122 ( 'F' , L_115 , & V_193 -> V_235 , L_116 ) ,
F_121 ( 'E' , L_117 , & V_2 . V_3 ,
L_118 ) ,
F_120 ( 'U' , L_119 , & V_2 . V_68 ,
L_120 ) ,
F_120 ( 0 , L_121 , & V_2 . V_251 , L_122 ) ,
F_120 ( 0 , L_123 , & V_2 . V_252 , L_124 ) ,
F_123 ( 'v' , L_125 , & V_198 ,
L_126 ) ,
F_119 ( 's' , L_127 , & V_253 , L_128 ,
L_129
L_130 ) ,
F_119 ( 0 , L_131 , & V_254 , L_132 ,
L_133 ) ,
F_120 ( 'n' , L_134 , & V_71 . V_255 ,
L_135 ) ,
F_124 ( 'g' , NULL , & V_194 ,
NULL , L_136 ,
& F_109 ) ,
F_117 ( 0 , L_137 , & V_194 ,
L_138 ,
V_256 , & F_111 ) ,
F_120 ( 0 , L_139 , & V_71 . V_169 ,
L_140 ) ,
F_121 ( 0 , L_141 , & V_2 . V_173 ,
L_142
L_143 F_125 ( V_257 ) ) ,
F_117 ( 0 , L_144 , NULL , L_145 ,
L_146 ,
V_258 ) ,
F_120 ( 0 , L_147 , & V_71 . V_259 ,
L_148 ) ,
F_119 ( 0 , L_149 , & V_71 . V_260 , L_150 ,
L_151 ) ,
F_119 ( 0 , L_152 , & V_71 . V_261 , L_153 ,
L_154 ) ,
F_119 ( 0 , L_155 , & V_71 . V_262 , L_156 ,
L_157 ) ,
F_120 ( 0 , L_158 , & V_71 . V_263 ,
L_159 ) ,
F_120 ( 0 , L_160 , & V_71 . V_264 ,
L_161 ) ,
F_120 ( 0 , L_162 , & V_71 . V_265 ,
L_163 ) ,
F_119 ( 0 , L_164 , & V_208 , L_165 ,
L_166 ) ,
F_119 ( 'M' , L_167 , & V_266 , L_168 ,
L_169 ) ,
F_119 ( 'u' , L_170 , & V_73 -> V_119 , L_171 , L_172 ) ,
F_117 ( 0 , L_173 , & V_2 , L_174 ,
L_175 , F_115 ) ,
F_117 ( 0 , L_176 , NULL , L_177 ,
L_178 , V_267 ) ,
F_119 ( 'w' , L_179 , & V_71 . V_268 ,
L_180 ,
L_181 ) ,
F_122 ( 0 , L_182 , & V_193 -> V_210 ,
L_183 ) ,
F_124 ( 'b' , L_184 , & V_193 -> V_142 ,
L_185 , L_186 ,
V_269 ) ,
F_117 ( 'j' , L_187 , & V_193 -> V_142 ,
L_188 , L_189 ,
V_269 ) ,
F_120 ( 0 , L_190 , & V_71 . V_270 ,
L_191 ) ,
F_120 ( 0 , L_192 , & V_71 . V_271 ,
L_193 ) ,
F_126 ()
} ;
const char * const V_272 [] = {
L_194 ,
NULL
} ;
int V_273 = F_127 () ;
if ( V_273 < 0 )
return V_273 ;
V_2 . V_51 = F_128 () ;
if ( V_2 . V_51 == NULL )
return - V_46 ;
F_129 ( F_113 , & V_2 ) ;
V_232 = F_130 ( V_232 , V_233 , V_241 , V_272 , 0 ) ;
if ( V_232 )
F_131 ( V_272 , V_241 ) ;
if ( ! V_2 . V_51 -> V_88 &&
F_132 ( V_2 . V_51 ) < 0 ) {
F_6 ( L_195 ) ;
goto V_274;
}
if ( V_71 . V_271 ) {
V_71 . V_275 = false ;
V_71 . V_169 = false ;
if ( V_254 ) {
F_6 ( L_196 ) ;
F_133 ( V_272 , V_241 , L_131 , 0 ) ;
F_133 ( NULL , V_241 , L_192 , 0 ) ;
goto V_274;
}
}
V_276 = V_277 ;
V_139 . V_278 = 1 ;
if ( V_2 . V_252 )
V_41 = 0 ;
else if ( V_2 . V_251 )
V_41 = 1 ;
F_134 ( false ) ;
if ( F_135 ( V_2 . V_51 ) < 0 ) {
if ( V_253 )
F_133 ( V_272 , V_241 , L_197 , 1 ) ;
if ( V_254 )
F_133 ( V_253 ? NULL : V_272 ,
V_241 , L_131 , 0 ) ;
goto V_274;
}
V_273 = F_136 ( V_73 ) ;
if ( V_273 ) {
F_137 ( V_73 , V_273 , V_223 , V_27 ) ;
F_18 ( L_22 , V_223 ) ;
}
V_273 = F_138 ( V_73 ) ;
if ( V_273 ) {
int V_279 = V_132 ;
F_137 ( V_73 , V_273 , V_223 , V_27 ) ;
F_89 ( L_22 , V_223 ) ;
V_273 = - V_279 ;
goto V_274;
}
if ( F_102 ( V_73 ) )
V_73 -> V_244 = true ;
if ( F_139 ( V_2 . V_51 , V_73 ) < 0 ) {
F_89 ( L_198 ,
V_132 == V_280 ? L_199 : F_91 ( V_132 , V_223 , sizeof( V_223 ) ) ) ;
goto V_274;
}
V_71 . V_65 = V_2 . V_51 -> V_88 ;
if ( V_2 . V_87 < 1 )
V_2 . V_87 = 1 ;
if ( F_140 ( V_193 ) ) {
V_273 = - V_202 ;
goto V_274;
}
V_2 . V_49 = F_54 ( V_2 . V_51 ) ;
if ( ! V_194 . V_52 ) {
V_71 . V_169 = false ;
F_141 () ;
}
if ( V_71 . V_169 && ! V_194 . V_281 )
V_194 . V_282 = V_283 ;
V_273 = F_142 () ;
if ( V_273 < 0 )
goto V_274;
V_71 . V_284 = ( V_71 . V_165 == NULL ) ;
if ( F_143 ( NULL ) < 0 )
return - 1 ;
F_144 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_100 V_101 = {
. V_102 = F_2 ,
. V_103 = V_104 ,
} ;
F_1 ( & V_2 ) ;
V_100 ( V_105 , & V_101 , NULL ) ;
}
V_273 = F_94 ( & V_2 ) ;
V_274:
F_145 ( V_2 . V_51 ) ;
return V_273 ;
}
