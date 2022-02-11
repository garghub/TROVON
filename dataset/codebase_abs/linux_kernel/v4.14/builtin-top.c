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
V_16 = F_12 ( V_12 , V_15 , NULL , 0 , NULL , NULL ) ;
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
struct V_43 * V_44 ,
int V_45 , T_4 V_28 )
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
V_16 = F_22 ( V_10 , V_44 , V_45 , V_28 ) ;
F_11 ( & V_14 -> V_23 ) ;
if ( F_23 ( V_16 ) ) {
F_11 ( & V_10 -> V_46 -> V_23 ) ;
if ( V_16 == - V_47 && ! V_10 -> V_17 . V_15 -> V_42 )
F_16 ( V_10 -> V_17 . V_15 , V_12 , V_28 ) ;
else if ( V_16 == - V_48 ) {
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
}
F_9 ( & V_10 -> V_46 -> V_23 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_49 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_50;
printf ( L_19 , F_25 ( V_2 -> V_51 ) , V_11 -> V_21 ) ;
printf ( L_20 , V_2 -> V_52 ) ;
V_49 = F_26 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_51 ,
0 , V_2 -> V_52 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_53 -> V_54 ) {
if ( V_2 -> V_55 )
F_27 ( V_11 , V_2 -> V_51 -> V_56 ) ;
else
F_28 ( V_11 , V_2 -> V_51 -> V_56 ) ;
}
if ( V_49 != 0 )
printf ( L_21 , V_49 ) ;
V_50:
F_11 ( & V_14 -> V_23 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
char V_57 [ 160 ] ;
int V_58 = 0 ;
const int V_59 = V_2 -> V_4 . V_60 - 1 ;
struct V_61 * V_62 = V_2 -> V_51 ;
struct V_46 * V_46 = F_30 ( V_62 ) ;
puts ( V_63 ) ;
F_31 ( V_2 , V_57 , sizeof( V_57 ) ) ;
printf ( L_22 , V_57 ) ;
F_32 ( V_2 ) ;
printf ( L_23 , V_59 , V_59 , V_64 ) ;
if ( V_46 -> V_65 . V_66 !=
V_46 -> V_65 . V_67 [ V_68 ] ) {
V_46 -> V_65 . V_66 =
V_46 -> V_65 . V_67 [ V_68 ] ;
F_33 ( stdout , V_69 ,
L_24 ,
V_46 -> V_65 . V_66 ) ;
++ V_58 ;
}
if ( V_2 -> V_25 ) {
F_24 ( V_2 ) ;
return;
}
if ( V_2 -> V_53 -> V_54 ) {
if ( V_2 -> V_55 ) {
F_34 ( V_46 ) ;
} else {
F_35 ( V_46 , V_2 -> V_70 ,
V_2 -> V_71 ) ;
}
}
F_36 ( V_46 , NULL ) ;
F_37 ( V_62 , NULL ) ;
F_38 ( V_46 , V_2 -> V_3 - V_58 ) ;
putchar ( '\n' ) ;
F_39 ( V_46 , false , V_2 -> V_3 - V_58 , V_59 ,
V_2 -> V_72 , stdout , V_73 . V_74 ) ;
}
static void F_40 ( int * V_75 , const char * V_26 )
{
char * V_76 = malloc ( 0 ) , * V_77 ;
T_5 V_78 = 0 ;
int V_79 ;
fprintf ( stdout , L_25 , V_26 ) ;
if ( F_41 ( & V_76 , & V_78 , V_80 ) < 0 )
return;
V_77 = strchr ( V_76 , '\n' ) ;
if ( V_77 )
* V_77 = 0 ;
V_77 = V_76 ;
while( * V_77 ) {
if ( ! isdigit ( * V_77 ) )
goto V_81;
V_77 ++ ;
}
V_79 = strtoul ( V_76 , NULL , 10 ) ;
* V_75 = V_79 ;
V_81:
free ( V_76 ) ;
}
static void F_42 ( int * V_75 , const char * V_26 )
{
int V_79 = 0 ;
F_40 ( & V_79 , V_26 ) ;
if ( V_79 >= 0 && V_79 <= 100 )
* V_75 = V_79 ;
}
static void F_43 ( struct V_1 * V_2 , const char * V_26 )
{
char * V_76 = malloc ( 0 ) , * V_77 ;
struct V_9 * V_82 = V_2 -> V_25 , * V_83 , * V_84 = NULL ;
struct V_46 * V_46 = F_30 ( V_2 -> V_51 ) ;
struct V_85 * V_86 ;
T_5 V_78 = 0 ;
if ( V_82 ) {
F_14 ( V_82 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_25 , V_26 ) ;
if ( F_41 ( & V_76 , & V_78 , V_80 ) < 0 )
goto V_81;
V_77 = strchr ( V_76 , '\n' ) ;
if ( V_77 )
* V_77 = 0 ;
V_86 = F_44 ( & V_46 -> V_87 ) ;
while ( V_86 ) {
V_83 = F_45 ( V_86 , struct V_9 , V_85 ) ;
if ( V_83 -> V_17 . V_12 && ! strcmp ( V_76 , V_83 -> V_17 . V_12 -> V_21 ) ) {
V_84 = V_83 ;
break;
}
V_86 = F_46 ( & V_83 -> V_85 ) ;
}
if ( ! V_84 ) {
fprintf ( V_88 , L_26 , V_76 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_84 ) ;
V_81:
free ( V_76 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_27 ) ;
fprintf ( stdout , L_28 , V_2 -> V_89 ) ;
fprintf ( stdout , L_29 , V_2 -> V_3 ) ;
if ( V_2 -> V_53 -> V_90 > 1 )
fprintf ( stdout , L_30 , F_25 ( V_2 -> V_51 ) ) ;
fprintf ( stdout , L_31 , V_2 -> V_91 ) ;
fprintf ( stdout , L_32 , V_2 -> V_52 ) ;
fprintf ( stdout , L_33 , V_21 ? : L_34 ) ;
fprintf ( stdout , L_35 ) ;
fprintf ( stdout ,
L_36 ,
V_2 -> V_71 ? L_37 : L_38 ) ;
fprintf ( stdout ,
L_39 ,
V_2 -> V_70 ? L_37 : L_38 ) ;
fprintf ( stdout , L_40 , V_2 -> V_55 ? 1 : 0 ) ;
fprintf ( stdout , L_41 ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_92 )
{
switch ( V_92 ) {
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
return V_2 -> V_53 -> V_90 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_49 ( struct V_1 * V_2 , int V_92 )
{
bool V_93 = true ;
if ( ! F_48 ( V_2 , V_92 ) ) {
struct V_94 V_95 = { . V_96 = 0 , . V_97 = V_98 } ;
struct V_99 V_100 ;
F_47 ( V_2 ) ;
fprintf ( stdout , L_42 ) ;
fflush ( stdout ) ;
F_50 ( & V_100 ) ;
F_51 ( & V_95 , 1 , - 1 ) ;
V_92 = getc ( V_80 ) ;
F_52 ( 0 , V_101 , & V_100 ) ;
if ( ! F_48 ( V_2 , V_92 ) )
return V_93 ;
}
switch ( V_92 ) {
case 'd' :
F_40 ( & V_2 -> V_89 , L_43 ) ;
if ( V_2 -> V_89 < 1 )
V_2 -> V_89 = 1 ;
break;
case 'e' :
F_40 ( & V_2 -> V_3 , L_44 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_102 V_103 = {
. V_104 = F_2 ,
. V_105 = V_106 ,
} ;
F_2 ( V_107 , NULL , V_2 ) ;
V_102 ( V_107 , & V_103 , NULL ) ;
} else {
signal ( V_107 , V_108 ) ;
}
break;
case 'E' :
if ( V_2 -> V_53 -> V_90 > 1 ) {
int V_45 = 0 ;
fprintf ( V_88 , L_45 ) ;
F_53 (top->evlist, top->sym_evsel)
fprintf ( V_88 , L_46 , V_2 -> V_51 -> V_56 , F_25 ( V_2 -> V_51 ) ) ;
F_40 ( & V_45 , L_47 ) ;
if ( V_45 >= V_2 -> V_53 -> V_90 ) {
V_2 -> V_51 = F_54 ( V_2 -> V_53 ) ;
fprintf ( V_88 , L_48 , F_25 ( V_2 -> V_51 ) ) ;
F_7 ( 1 ) ;
break;
}
F_53 (top->evlist, top->sym_evsel)
if ( V_2 -> V_51 -> V_56 == V_45 )
break;
} else
V_2 -> V_51 = F_54 ( V_2 -> V_53 ) ;
break;
case 'f' :
F_40 ( & V_2 -> V_91 , L_49 ) ;
break;
case 'F' :
F_42 ( & V_2 -> V_52 ,
L_50 ) ;
break;
case 'K' :
V_2 -> V_71 = ! V_2 -> V_71 ;
break;
case 'q' :
case 'Q' :
printf ( L_51 ) ;
if ( V_2 -> V_109 )
F_55 ( V_2 -> V_110 , V_88 ) ;
V_93 = false ;
break;
case 's' :
F_43 ( V_2 , L_52 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_82 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_14 ( V_82 ) ;
}
break;
case 'U' :
V_2 -> V_70 = ! V_2 -> V_70 ;
break;
case 'z' :
V_2 -> V_55 = ! V_2 -> V_55 ;
break;
default:
break;
}
return V_93 ;
}
static void F_56 ( void * V_8 )
{
struct V_1 * V_111 = V_8 ;
struct V_61 * V_62 = V_111 -> V_51 ;
struct V_46 * V_46 ;
F_32 ( V_111 ) ;
if ( V_111 -> V_53 -> V_112 != NULL )
V_111 -> V_51 = V_111 -> V_53 -> V_112 ;
V_46 = F_30 ( V_62 ) ;
if ( V_111 -> V_53 -> V_54 ) {
if ( V_111 -> V_55 ) {
F_34 ( V_46 ) ;
} else {
F_35 ( V_46 , V_111 -> V_70 ,
V_111 -> V_71 ) ;
}
}
F_36 ( V_46 , NULL ) ;
F_37 ( V_62 , NULL ) ;
}
static void * F_57 ( void * V_8 )
{
struct V_61 * V_113 ;
struct V_1 * V_2 = V_8 ;
const char * V_114 = L_53 ;
struct V_115 V_116 = {
. V_117 = F_56 ,
. V_8 = V_2 ,
. V_118 = V_2 -> V_89 ,
} ;
F_58 ( V_119 ) ;
F_56 ( V_2 ) ;
F_53 (top->evlist, pos) {
struct V_46 * V_46 = F_30 ( V_113 ) ;
V_46 -> V_120 = V_2 -> V_121 . V_75 . V_122 ;
}
F_59 ( V_2 -> V_53 , V_114 , & V_116 ,
V_2 -> V_72 ,
& V_2 -> V_110 -> V_123 . V_124 ) ;
V_125 = 1 ;
return NULL ;
}
static void F_60 ( int T_1 V_7 )
{
V_125 = 1 ;
}
static void F_61 ( void )
{
signal ( V_126 , V_127 ) ;
signal ( V_128 , V_127 ) ;
signal ( V_129 , F_60 ) ;
signal ( V_130 , F_60 ) ;
signal ( V_131 , F_60 ) ;
}
static void * F_62 ( void * V_8 )
{
struct V_94 V_95 = { . V_96 = 0 , . V_97 = V_98 } ;
struct V_99 V_100 ;
struct V_1 * V_2 = V_8 ;
int V_132 , V_92 ;
F_58 ( V_119 ) ;
F_61 () ;
F_63 () ;
V_133:
V_132 = V_2 -> V_89 * V_134 ;
F_50 ( & V_100 ) ;
getc ( V_80 ) ;
while ( ! V_125 ) {
F_29 ( V_2 ) ;
switch ( F_51 ( & V_95 , 1 , V_132 ) ) {
case 0 :
continue;
case - 1 :
if ( V_135 == V_136 )
continue;
V_137 ;
default:
V_92 = getc ( V_80 ) ;
F_52 ( 0 , V_101 , & V_100 ) ;
if ( F_49 ( V_2 , V_92 ) )
goto V_133;
V_125 = 1 ;
}
}
F_52 ( 0 , V_101 , & V_100 ) ;
return NULL ;
}
static int F_64 ( struct V_138 * V_139 ,
struct V_140 * V_141 , bool V_142 ,
void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_9 * V_10 = V_139 -> V_10 ;
struct V_61 * V_62 = V_139 -> V_62 ;
if ( V_143 . V_12 && V_142 )
F_20 ( V_2 , V_10 , V_139 -> V_44 , V_62 -> V_56 , V_141 -> V_144 ) ;
F_65 ( V_139 -> V_44 -> V_145 , V_141 , V_139 -> V_44 ,
! ( V_2 -> V_121 . V_145 & V_146 ) ) ;
return 0 ;
}
static void F_66 ( struct V_147 * V_148 ,
const union V_149 * V_150 ,
struct V_61 * V_62 ,
struct V_43 * V_44 ,
struct V_38 * V_38 )
{
struct V_1 * V_2 = F_67 ( V_148 , struct V_1 , V_148 ) ;
struct V_140 V_141 ;
int V_16 ;
if ( ! V_38 && V_151 ) {
static struct V_152 * V_153 ;
if ( ! V_153 )
V_153 = F_68 ( NULL ) ;
if ( ! F_69 ( V_153 , V_44 -> V_154 ) ) {
F_6 ( L_54 ,
V_44 -> V_154 ) ;
F_70 ( V_153 , V_44 -> V_154 ) ;
}
return;
}
if ( ! V_38 ) {
F_6 ( L_55 ,
V_2 -> V_110 -> V_53 -> V_65 . V_155 ++ ) ;
return;
}
if ( V_150 -> V_123 . V_156 & V_157 )
V_2 -> V_158 ++ ;
if ( F_71 ( V_38 , & V_141 , V_44 ) < 0 )
return;
if ( ! V_38 -> V_159 &&
V_73 . V_160 &&
V_141 . V_161 == V_162 ) {
F_18 (
L_56
L_57
L_58 ,
V_141 . V_15 && ! F_72 ( & V_141 . V_15 -> V_18 -> V_163 [ V_164 ] ) ?
L_59 : L_60 ) ;
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_38 -> V_159 = true ;
}
if ( V_141 . V_12 == NULL ) {
const char * V_26 = L_61 ;
if ( ! V_38 -> V_159 && ! V_2 -> V_165 &&
V_141 . V_15 == V_38 -> V_166 [ V_164 ] &&
F_72 ( & V_141 . V_15 -> V_18 -> V_163 [ V_164 ] ) ) {
if ( V_73 . V_167 ) {
char V_168 [ 256 ] ;
F_73 ( V_141 . V_15 -> V_18 , V_168 , sizeof( V_168 ) ) ;
F_18 ( L_62 ,
V_73 . V_167 , V_168 , V_26 ) ;
} else {
F_18 ( L_63 ,
V_26 ) ;
}
if ( V_41 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_165 = true ;
}
}
if ( V_141 . V_12 == NULL || ! V_141 . V_12 -> V_169 ) {
struct V_46 * V_46 = F_30 ( V_62 ) ;
struct V_138 V_139 = {
. V_62 = V_62 ,
. V_44 = V_44 ,
. V_170 = F_64 ,
} ;
if ( V_73 . V_171 )
V_139 . V_172 = & V_173 ;
else
V_139 . V_172 = & V_174 ;
F_9 ( & V_46 -> V_23 ) ;
V_16 = F_74 ( & V_139 , & V_141 , V_2 -> V_175 , V_2 ) ;
if ( V_16 < 0 )
F_6 ( L_64 ) ;
F_11 ( & V_46 -> V_23 ) ;
}
F_75 ( & V_141 ) ;
}
static void F_76 ( struct V_1 * V_2 , int V_56 )
{
struct V_43 V_44 ;
struct V_61 * V_62 ;
struct V_176 * V_110 = V_2 -> V_110 ;
union V_149 * V_150 ;
struct V_38 * V_38 ;
int V_93 ;
while ( ( V_150 = F_77 ( V_2 -> V_53 , V_56 ) ) != NULL ) {
V_93 = F_78 ( V_2 -> V_53 , V_150 , & V_44 ) ;
if ( V_93 ) {
F_6 ( L_65 , V_93 ) ;
goto V_177;
}
V_62 = F_79 ( V_110 -> V_53 , V_44 . V_178 ) ;
assert ( V_62 != NULL ) ;
if ( V_150 -> V_123 . type == V_179 )
++ V_2 -> V_180 ;
switch ( V_44 . V_161 ) {
case V_181 :
++ V_2 -> V_182 ;
if ( V_2 -> V_70 )
goto V_177;
V_38 = & V_110 -> V_183 . V_184 ;
break;
case V_162 :
++ V_2 -> V_185 ;
if ( V_2 -> V_71 )
goto V_177;
V_38 = & V_110 -> V_183 . V_184 ;
break;
case V_186 :
++ V_2 -> V_187 ;
V_38 = F_80 ( V_110 ,
V_44 . V_154 ) ;
break;
case V_188 :
++ V_2 -> V_189 ;
goto V_177;
default:
if ( V_150 -> V_123 . type == V_179 )
goto V_177;
V_38 = & V_110 -> V_183 . V_184 ;
break;
}
if ( V_150 -> V_123 . type == V_179 ) {
F_66 ( & V_2 -> V_148 , V_150 , V_62 ,
& V_44 , V_38 ) ;
} else if ( V_150 -> V_123 . type < V_190 ) {
F_81 ( F_30 ( V_62 ) , V_150 -> V_123 . type ) ;
F_82 ( V_38 , V_150 , & V_44 ) ;
} else
++ V_110 -> V_53 -> V_65 . V_191 ;
V_177:
F_83 ( V_2 -> V_53 , V_56 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_53 -> V_193 ; V_192 ++ )
F_76 ( V_2 , V_192 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
char V_26 [ V_27 ] ;
struct V_61 * V_45 ;
struct V_194 * V_53 = V_2 -> V_53 ;
struct V_121 * V_195 = & V_2 -> V_121 ;
F_86 ( V_53 , V_195 , & V_196 ) ;
F_53 (evlist, counter) {
V_197:
if ( F_87 ( V_45 , V_2 -> V_53 -> V_198 ,
V_2 -> V_53 -> V_199 ) < 0 ) {
if ( F_88 ( V_45 , V_135 , V_26 , sizeof( V_26 ) ) ) {
if ( V_200 > 0 )
F_18 ( L_22 , V_26 ) ;
goto V_197;
}
F_89 ( V_45 , & V_195 -> V_75 ,
V_135 , V_26 , sizeof( V_26 ) ) ;
F_90 ( L_22 , V_26 ) ;
goto V_201;
}
}
if ( F_91 ( V_53 , V_195 -> V_202 , false ) < 0 ) {
F_90 ( L_66 ,
V_135 , F_92 ( V_135 , V_26 , sizeof( V_26 ) ) ) ;
goto V_201;
}
return 0 ;
V_201:
return - 1 ;
}
static int F_93 ( struct V_196 * V_203 )
{
if ( ! V_143 . V_12 ) {
if ( V_203 -> V_54 ) {
F_90 ( L_67 ) ;
return - V_204 ;
}
} else if ( V_203 -> V_205 != V_206 ) {
if ( F_94 ( V_203 ) < 0 ) {
F_90 ( L_68 ) ;
return - V_204 ;
}
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
char V_26 [ 512 ] ;
struct V_61 * V_113 ;
struct V_207 * V_208 ;
struct V_194 * V_53 = V_2 -> V_53 ;
struct V_121 * V_195 = & V_2 -> V_121 ;
T_6 V_209 ;
int V_93 ;
V_2 -> V_110 = F_96 ( NULL , false , NULL ) ;
if ( V_2 -> V_110 == NULL )
return - 1 ;
if ( ! V_210 ) {
V_93 = F_97 ( & V_2 -> V_110 -> V_123 . V_124 ) ;
if ( V_93 )
goto V_211;
}
V_93 = F_93 ( & V_196 ) ;
if ( V_93 )
goto V_211;
if ( F_98 ( V_2 -> V_110 ) < 0 )
goto V_211;
F_99 ( & V_2 -> V_110 -> V_183 . V_184 , & V_195 -> V_75 ,
V_2 -> V_53 -> V_199 , false , V_195 -> V_212 ) ;
if ( V_143 . V_213 ) {
V_93 = F_100 ( & V_214 ) ;
if ( V_93 < 0 )
goto V_215;
}
V_93 = F_85 ( V_2 ) ;
if ( V_93 )
goto V_211;
V_93 = F_101 ( V_53 , & V_113 , & V_208 ) ;
if ( V_93 ) {
F_6 ( L_69 ,
V_208 -> V_216 . V_217 , F_25 ( V_113 ) , V_135 ,
F_92 ( V_135 , V_26 , sizeof( V_26 ) ) ) ;
goto V_211;
}
V_2 -> V_110 -> V_53 = V_2 -> V_53 ;
F_102 ( V_2 -> V_110 ) ;
if ( ! F_103 ( & V_195 -> V_75 ) )
F_104 ( V_2 -> V_53 ) ;
F_105 ( V_2 -> V_53 , 100 ) ;
F_84 ( V_2 ) ;
V_93 = - 1 ;
if ( F_106 ( & V_209 , NULL , ( V_41 > 0 ? F_57 :
F_62 ) , V_2 ) ) {
F_90 ( L_70 ) ;
goto V_211;
}
if ( V_2 -> V_218 ) {
struct V_219 V_220 ;
V_220 . V_221 = V_2 -> V_218 ;
if ( F_107 ( 0 , V_222 , & V_220 ) ) {
F_90 ( L_71 ) ;
goto V_223;
}
}
while ( ! V_125 ) {
T_4 V_224 = V_2 -> V_180 ;
F_84 ( V_2 ) ;
if ( V_224 == V_2 -> V_180 )
V_93 = F_105 ( V_2 -> V_53 , 100 ) ;
}
V_93 = 0 ;
V_223:
F_108 ( V_209 , NULL ) ;
V_211:
F_109 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
return V_93 ;
V_215: {
char V_225 [ V_27 ] ;
const char * V_16 = F_92 ( - V_93 , V_225 , sizeof( V_225 ) ) ;
F_90 ( L_72 , V_16 ) ;
goto V_211;
}
}
static int
F_110 ( const struct V_226 * V_227 , const char * V_8 , int V_228 )
{
V_73 . V_74 = true ;
return F_111 ( V_227 , V_8 , V_228 ) ;
}
static int
F_112 ( const struct V_226 * V_227 , const char * V_8 , int V_228 )
{
struct V_196 * V_203 = V_227 -> V_229 ;
V_203 -> V_54 = ! V_228 ;
V_203 -> V_230 = V_231 ;
if ( V_228 ) {
V_73 . V_74 = false ;
V_203 -> V_230 = V_232 ;
return 0 ;
}
return F_113 ( V_8 ) ;
}
static int F_114 ( const char * V_233 , const char * V_229 , void * T_7 V_7 )
{
if ( ! strcmp ( V_233 , L_73 ) )
V_233 = L_74 ;
if ( ! strcmp ( V_233 , L_75 ) ) {
V_73 . V_171 = F_115 ( V_233 , V_229 ) ;
return 0 ;
}
return 0 ;
}
static int
F_116 ( const struct V_226 * V_227 , const char * V_8 ,
int V_228 V_7 )
{
struct V_1 * V_2 = V_227 -> V_229 ;
V_2 -> V_72 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_117 ( int V_234 , const char * * V_235 )
{
char V_225 [ V_27 ] ;
struct V_1 V_2 = {
. V_91 = 5 ,
. V_89 = 2 ,
. V_121 = {
. V_202 = V_236 ,
. V_237 = V_236 ,
. V_238 = V_239 ,
. V_240 = 4000 ,
. V_75 = {
. V_241 = true ,
} ,
. V_212 = 500 ,
} ,
. V_175 = V_242 ,
. V_52 = 5 ,
} ;
struct V_121 * V_195 = & V_2 . V_121 ;
struct V_75 * V_75 = & V_195 -> V_75 ;
const struct V_226 V_243 [] = {
F_118 ( 'e' , L_76 , & V_2 . V_53 , L_76 ,
L_77 ,
V_244 ) ,
F_119 ( 'c' , L_78 , & V_195 -> V_238 , L_79 ) ,
F_120 ( 'p' , L_80 , & V_75 -> V_154 , L_80 ,
L_81 ) ,
F_120 ( 't' , L_82 , & V_75 -> V_245 , L_82 ,
L_83 ) ,
F_121 ( 'a' , L_84 , & V_75 -> V_246 ,
L_85 ) ,
F_120 ( 'C' , L_86 , & V_75 -> V_247 , L_86 ,
L_87 ) ,
F_120 ( 'k' , L_88 , & V_73 . V_167 ,
L_89 , L_90 ) ,
F_121 ( 0 , L_91 , & V_73 . V_248 ,
L_92 ) ,
F_121 ( 'K' , L_93 , & V_2 . V_71 ,
L_94 ) ,
F_118 ( 'm' , L_95 , & V_195 -> V_202 , L_96 ,
L_97 ,
V_249 ) ,
F_122 ( 'r' , L_98 , & V_2 . V_218 ,
L_99 ) ,
F_122 ( 'd' , L_100 , & V_2 . V_89 ,
L_101 ) ,
F_121 ( 'D' , L_102 , & V_2 . V_109 ,
L_103 ) ,
F_122 ( 'f' , L_104 , & V_2 . V_91 ,
L_105 ) ,
F_121 ( 0 , L_106 , & V_195 -> V_250 ,
L_107 ) ,
F_121 ( 'i' , L_108 , & V_195 -> V_251 ,
L_109 ) ,
F_120 ( 0 , L_110 , & V_2 . V_252 , L_111 ,
L_112 ) ,
F_121 ( 'z' , L_113 , & V_2 . V_55 , L_114 ) ,
F_123 ( 'F' , L_115 , & V_195 -> V_237 , L_116 ) ,
F_122 ( 'E' , L_117 , & V_2 . V_3 ,
L_118 ) ,
F_121 ( 'U' , L_119 , & V_2 . V_70 ,
L_120 ) ,
F_121 ( 0 , L_121 , & V_2 . V_253 , L_122 ) ,
F_121 ( 0 , L_123 , & V_2 . V_254 , L_124 ) ,
F_124 ( 'v' , L_125 , & V_200 ,
L_126 ) ,
F_120 ( 's' , L_127 , & V_255 , L_128 ,
L_129
L_130 ) ,
F_120 ( 0 , L_131 , & V_256 , L_132 ,
L_133 ) ,
F_121 ( 'n' , L_134 , & V_73 . V_257 ,
L_135 ) ,
F_125 ( 'g' , NULL , & V_196 ,
NULL , L_136 ,
& F_110 ) ,
F_118 ( 0 , L_137 , & V_196 ,
L_138 ,
V_258 , & F_112 ) ,
F_121 ( 0 , L_139 , & V_73 . V_171 ,
L_140 ) ,
F_122 ( 0 , L_141 , & V_2 . V_175 ,
L_142
L_143 F_126 ( V_259 ) ) ,
F_118 ( 0 , L_144 , NULL , L_145 ,
L_146 ,
V_260 ) ,
F_121 ( 0 , L_147 , & V_73 . V_261 ,
L_148 ) ,
F_120 ( 0 , L_149 , & V_73 . V_262 , L_150 ,
L_151 ) ,
F_120 ( 0 , L_152 , & V_73 . V_263 , L_153 ,
L_154 ) ,
F_120 ( 0 , L_155 , & V_73 . V_264 , L_156 ,
L_157 ) ,
F_121 ( 0 , L_158 , & V_73 . V_265 ,
L_159 ) ,
F_121 ( 0 , L_160 , & V_73 . V_266 ,
L_161 ) ,
F_121 ( 0 , L_162 , & V_73 . V_267 ,
L_163 ) ,
F_120 ( 0 , L_164 , & V_210 , L_165 ,
L_166 ) ,
F_120 ( 'M' , L_167 , & V_268 , L_168 ,
L_169 ) ,
F_120 ( 'u' , L_170 , & V_75 -> V_122 , L_171 , L_172 ) ,
F_118 ( 0 , L_173 , & V_2 , L_174 ,
L_175 , F_116 ) ,
F_118 ( 0 , L_176 , NULL , L_177 ,
L_178 , V_269 ) ,
F_120 ( 'w' , L_179 , & V_73 . V_270 ,
L_180 ,
L_181 ) ,
F_123 ( 0 , L_182 , & V_195 -> V_212 ,
L_183 ) ,
F_125 ( 'b' , L_184 , & V_195 -> V_145 ,
L_185 , L_186 ,
V_271 ) ,
F_118 ( 'j' , L_187 , & V_195 -> V_145 ,
L_188 , L_189 ,
V_271 ) ,
F_121 ( 0 , L_190 , & V_73 . V_272 ,
L_191 ) ,
F_121 ( 0 , L_192 , & V_73 . V_273 ,
L_193 ) ,
F_121 ( 0 , L_194 , & V_73 . V_274 , L_195 ) ,
F_127 ()
} ;
const char * const V_275 [] = {
L_196 ,
NULL
} ;
int V_276 = F_128 () ;
if ( V_276 < 0 )
return V_276 ;
V_2 . V_53 = F_129 () ;
if ( V_2 . V_53 == NULL )
return - V_48 ;
V_276 = F_130 ( F_114 , & V_2 ) ;
if ( V_276 )
return V_276 ;
V_234 = F_131 ( V_234 , V_235 , V_243 , V_275 , 0 ) ;
if ( V_234 )
F_132 ( V_275 , V_243 ) ;
if ( ! V_2 . V_53 -> V_90 &&
F_133 ( V_2 . V_53 ) < 0 ) {
F_6 ( L_197 ) ;
goto V_277;
}
if ( V_73 . V_273 ) {
V_73 . V_278 = false ;
V_73 . V_171 = false ;
if ( V_256 ) {
F_6 ( L_198 ) ;
F_134 ( V_275 , V_243 , L_131 , 0 ) ;
F_134 ( NULL , V_243 , L_192 , 0 ) ;
goto V_277;
}
}
V_279 = V_280 ;
V_143 . V_281 = 1 ;
if ( V_2 . V_254 )
V_41 = 0 ;
else if ( V_2 . V_253 )
V_41 = 1 ;
F_135 ( false ) ;
if ( F_136 ( V_2 . V_53 ) < 0 ) {
if ( V_255 )
F_134 ( V_275 , V_243 , L_199 , 1 ) ;
if ( V_256 )
F_134 ( V_255 ? NULL : V_275 ,
V_243 , L_131 , 0 ) ;
goto V_277;
}
V_276 = F_137 ( V_75 ) ;
if ( V_276 ) {
F_138 ( V_75 , V_276 , V_225 , V_27 ) ;
F_18 ( L_22 , V_225 ) ;
}
V_276 = F_139 ( V_75 ) ;
if ( V_276 ) {
int V_282 = V_135 ;
F_138 ( V_75 , V_276 , V_225 , V_27 ) ;
F_90 ( L_22 , V_225 ) ;
V_276 = - V_282 ;
goto V_277;
}
if ( F_103 ( V_75 ) )
V_75 -> V_246 = true ;
if ( F_140 ( V_2 . V_53 , V_75 ) < 0 ) {
F_90 ( L_200 ,
V_135 == V_283 ? L_201 : F_92 ( V_135 , V_225 , sizeof( V_225 ) ) ) ;
goto V_277;
}
V_73 . V_67 = V_2 . V_53 -> V_90 ;
if ( V_2 . V_89 < 1 )
V_2 . V_89 = 1 ;
if ( F_141 ( V_195 ) ) {
V_276 = - V_204 ;
goto V_277;
}
V_2 . V_51 = F_54 ( V_2 . V_53 ) ;
if ( ! V_196 . V_54 ) {
V_73 . V_171 = false ;
F_142 () ;
}
if ( V_73 . V_171 && ! V_196 . V_284 )
V_196 . V_285 = V_286 ;
V_276 = F_143 () ;
if ( V_276 < 0 )
goto V_277;
V_73 . V_287 = ( V_73 . V_167 == NULL ) ;
if ( F_144 ( NULL ) < 0 )
return - 1 ;
F_145 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_102 V_103 = {
. V_104 = F_2 ,
. V_105 = V_106 ,
} ;
F_1 ( & V_2 ) ;
V_102 ( V_107 , & V_103 , NULL ) ;
}
V_276 = F_95 ( & V_2 ) ;
V_277:
F_146 ( V_2 . V_53 ) ;
return V_276 ;
}
