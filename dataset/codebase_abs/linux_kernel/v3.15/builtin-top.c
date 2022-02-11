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
if ( V_16 == - V_43 && ! V_10 -> V_17 . V_15 -> V_40 )
F_15 ( V_10 -> V_17 . V_15 , V_12 , V_26 ) ;
else if ( V_16 == - V_44 ) {
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
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
if ( V_2 -> V_49 )
F_26 ( V_11 , V_2 -> V_47 -> V_50 ) ;
else
F_27 ( V_11 , V_2 -> V_47 -> V_50 ) ;
if ( V_45 != 0 )
printf ( L_20 , V_45 ) ;
V_46:
F_11 ( & V_14 -> V_23 ) ;
}
static struct V_9 * F_28 ( struct V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_9 * V_10 ;
F_9 ( & V_52 -> V_57 . V_23 ) ;
V_10 = F_29 ( & V_52 -> V_57 , V_54 , NULL , NULL , NULL ,
V_56 -> V_58 , V_56 -> V_59 ,
V_56 -> V_60 ) ;
F_11 ( & V_52 -> V_57 . V_23 ) ;
if ( V_10 == NULL )
return NULL ;
F_30 ( & V_52 -> V_57 , V_61 ) ;
return V_10 ;
}
static void F_31 ( struct V_1 * V_2 )
{
char V_62 [ 160 ] ;
int V_63 = 0 ;
const int V_64 = V_2 -> V_4 . V_65 - 1 ;
puts ( V_66 ) ;
F_32 ( V_2 , V_62 , sizeof( V_62 ) ) ;
printf ( L_21 , V_62 ) ;
F_33 ( V_2 ) ;
printf ( L_22 , V_64 , V_64 , V_67 ) ;
if ( V_2 -> V_47 -> V_57 . V_68 . V_69 !=
V_2 -> V_47 -> V_57 . V_68 . V_70 [ V_71 ] ) {
V_2 -> V_47 -> V_57 . V_68 . V_69 =
V_2 -> V_47 -> V_57 . V_68 . V_70 [ V_71 ] ;
F_34 ( stdout , V_72 ,
L_23 ,
V_2 -> V_47 -> V_57 . V_68 . V_69 ) ;
++ V_63 ;
}
if ( V_2 -> V_25 ) {
F_23 ( V_2 ) ;
return;
}
F_35 ( & V_2 -> V_47 -> V_57 , NULL ) ;
F_36 ( & V_2 -> V_47 -> V_57 ) ;
F_37 ( & V_2 -> V_47 -> V_57 ,
V_2 -> V_73 ,
V_2 -> V_74 ) ;
F_38 ( & V_2 -> V_47 -> V_57 ,
V_2 -> V_3 - V_63 ) ;
putchar ( '\n' ) ;
F_39 ( & V_2 -> V_47 -> V_57 , false ,
V_2 -> V_3 - V_63 , V_64 ,
V_2 -> V_75 , stdout ) ;
}
static void F_40 ( int * V_76 , const char * V_77 )
{
char * V_78 = malloc ( 0 ) , * V_79 ;
T_5 V_80 = 0 ;
int V_81 ;
fprintf ( stdout , L_24 , V_77 ) ;
if ( F_41 ( & V_78 , & V_80 , V_82 ) < 0 )
return;
V_79 = strchr ( V_78 , '\n' ) ;
if ( V_79 )
* V_79 = 0 ;
V_79 = V_78 ;
while( * V_79 ) {
if ( ! isdigit ( * V_79 ) )
goto V_83;
V_79 ++ ;
}
V_81 = strtoul ( V_78 , NULL , 10 ) ;
* V_76 = V_81 ;
V_83:
free ( V_78 ) ;
}
static void F_42 ( int * V_76 , const char * V_77 )
{
int V_81 = 0 ;
F_40 ( & V_81 , V_77 ) ;
if ( V_81 >= 0 && V_81 <= 100 )
* V_76 = V_81 ;
}
static void F_43 ( struct V_1 * V_2 , const char * V_77 )
{
char * V_78 = malloc ( 0 ) , * V_79 ;
struct V_9 * V_84 = V_2 -> V_25 , * V_85 , * V_86 = NULL ;
struct V_87 * V_88 ;
T_5 V_80 = 0 ;
if ( V_84 ) {
F_13 ( V_84 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_77 ) ;
if ( F_41 ( & V_78 , & V_80 , V_82 ) < 0 )
goto V_83;
V_79 = strchr ( V_78 , '\n' ) ;
if ( V_79 )
* V_79 = 0 ;
V_88 = F_44 ( & V_2 -> V_47 -> V_57 . V_89 ) ;
while ( V_88 ) {
V_85 = F_45 ( V_88 , struct V_9 , V_87 ) ;
if ( V_85 -> V_17 . V_12 && ! strcmp ( V_78 , V_85 -> V_17 . V_12 -> V_21 ) ) {
V_86 = V_85 ;
break;
}
V_88 = F_46 ( & V_85 -> V_87 ) ;
}
if ( ! V_86 ) {
fprintf ( V_90 , L_25 , V_78 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_86 ) ;
V_83:
free ( V_78 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_91 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_92 -> V_93 > 1 )
fprintf ( stdout , L_29 , F_24 ( V_2 -> V_47 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_94 ) ;
fprintf ( stdout , L_31 , V_2 -> V_48 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_74 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_73 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_49 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_95 )
{
switch ( V_95 ) {
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
return V_2 -> V_92 -> V_93 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_49 ( struct V_1 * V_2 , int V_95 )
{
bool V_96 = true ;
if ( ! F_48 ( V_2 , V_95 ) ) {
struct V_97 V_98 = { . V_99 = 0 , . V_100 = V_101 } ;
struct V_102 V_103 , V_104 ;
F_47 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_50 ( 0 , & V_104 ) ;
V_103 = V_104 ;
V_103 . V_105 &= ~ ( V_106 | V_107 ) ;
V_103 . V_108 [ V_109 ] = 0 ;
V_103 . V_108 [ V_110 ] = 0 ;
F_51 ( 0 , V_111 , & V_103 ) ;
F_52 ( & V_98 , 1 , - 1 ) ;
V_95 = getc ( V_82 ) ;
F_51 ( 0 , V_112 , & V_104 ) ;
if ( ! F_48 ( V_2 , V_95 ) )
return V_96 ;
}
switch ( V_95 ) {
case 'd' :
F_40 ( & V_2 -> V_91 , L_42 ) ;
if ( V_2 -> V_91 < 1 )
V_2 -> V_91 = 1 ;
break;
case 'e' :
F_40 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_113 V_114 = {
. V_115 = F_2 ,
. V_116 = V_117 ,
} ;
F_2 ( V_118 , NULL , V_2 ) ;
V_113 ( V_118 , & V_114 , NULL ) ;
} else {
signal ( V_118 , V_119 ) ;
}
break;
case 'E' :
if ( V_2 -> V_92 -> V_93 > 1 ) {
int V_41 = 0 ;
fprintf ( V_90 , L_44 ) ;
F_53 (top->evlist, top->sym_evsel)
fprintf ( V_90 , L_45 , V_2 -> V_47 -> V_50 , F_24 ( V_2 -> V_47 ) ) ;
F_40 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_92 -> V_93 ) {
V_2 -> V_47 = F_54 ( V_2 -> V_92 ) ;
fprintf ( V_90 , L_47 , F_24 ( V_2 -> V_47 ) ) ;
F_7 ( 1 ) ;
break;
}
F_53 (top->evlist, top->sym_evsel)
if ( V_2 -> V_47 -> V_50 == V_41 )
break;
} else
V_2 -> V_47 = F_54 ( V_2 -> V_92 ) ;
break;
case 'f' :
F_40 ( & V_2 -> V_94 , L_48 ) ;
break;
case 'F' :
F_42 ( & V_2 -> V_48 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_74 = ! V_2 -> V_74 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_120 )
F_55 ( V_2 -> V_121 , V_90 ) ;
V_96 = false ;
break;
case 's' :
F_43 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_84 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_84 ) ;
}
break;
case 'U' :
V_2 -> V_73 = ! V_2 -> V_73 ;
break;
case 'z' :
V_2 -> V_49 = ! V_2 -> V_49 ;
break;
default:
break;
}
return V_96 ;
}
static void F_56 ( void * V_8 )
{
struct V_1 * V_122 = V_8 ;
F_33 ( V_122 ) ;
if ( V_122 -> V_92 -> V_123 != NULL )
V_122 -> V_47 = V_122 -> V_92 -> V_123 ;
F_35 ( & V_122 -> V_47 -> V_57 , NULL ) ;
F_36 ( & V_122 -> V_47 -> V_57 ) ;
F_37 ( & V_122 -> V_47 -> V_57 ,
V_122 -> V_73 ,
V_122 -> V_74 ) ;
}
static void * F_57 ( void * V_8 )
{
struct V_51 * V_124 ;
struct V_1 * V_2 = V_8 ;
const char * V_125 = L_52 ;
struct V_126 V_127 = {
. V_128 = F_56 ,
. V_8 = V_2 ,
. V_129 = V_2 -> V_91 ,
} ;
F_56 ( V_2 ) ;
F_53 (top->evlist, pos)
V_124 -> V_57 . V_130 = V_2 -> V_131 . V_76 . V_132 ;
F_58 ( V_2 -> V_92 , V_125 , & V_127 , V_2 -> V_75 ,
& V_2 -> V_121 -> V_133 . V_134 ) ;
V_135 = 1 ;
return NULL ;
}
static void * F_59 ( void * V_8 )
{
struct V_97 V_98 = { . V_99 = 0 , . V_100 = V_101 } ;
struct V_102 V_103 , V_104 ;
struct V_1 * V_2 = V_8 ;
int V_136 , V_95 ;
F_50 ( 0 , & V_104 ) ;
V_103 = V_104 ;
V_103 . V_105 &= ~ ( V_106 | V_107 ) ;
V_103 . V_108 [ V_109 ] = 0 ;
V_103 . V_108 [ V_110 ] = 0 ;
F_60 () ;
V_137:
V_136 = V_2 -> V_91 * 1000 ;
F_51 ( 0 , V_111 , & V_103 ) ;
getc ( V_82 ) ;
while ( ! V_135 ) {
F_31 ( V_2 ) ;
switch ( F_52 ( & V_98 , 1 , V_136 ) ) {
case 0 :
continue;
case - 1 :
if ( V_138 == V_139 )
continue;
default:
V_95 = getc ( V_82 ) ;
F_51 ( 0 , V_112 , & V_104 ) ;
if ( F_49 ( V_2 , V_95 ) )
goto V_137;
V_135 = 1 ;
}
}
return NULL ;
}
static int F_61 ( struct V_15 * V_15 V_7 , struct V_11 * V_12 )
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
if ( F_62 ( V_12 ) )
V_12 -> V_140 = true ;
return 0 ;
}
static void F_63 ( struct V_141 * V_142 ,
const union V_143 * V_144 ,
struct V_51 * V_52 ,
struct V_55 * V_56 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_64 ( V_142 , struct V_1 , V_142 ) ;
struct V_11 * V_145 = NULL ;
T_4 V_26 = V_56 -> V_26 ;
struct V_53 V_54 ;
int V_16 ;
if ( ! V_36 && V_146 ) {
static struct V_147 * V_148 ;
if ( ! V_148 )
V_148 = F_65 ( NULL ) ;
if ( ! F_66 ( V_148 , V_56 -> V_149 ) ) {
F_6 ( L_60 ,
V_56 -> V_149 ) ;
F_67 ( V_148 , V_56 -> V_149 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_121 -> V_68 . V_150 ++ ) ;
return;
}
if ( V_144 -> V_133 . V_151 & V_152 )
V_2 -> V_153 ++ ;
if ( F_68 ( V_144 , V_36 , & V_54 , V_56 ) < 0 ||
V_54 . V_154 )
return;
if ( ! V_2 -> V_155 &&
V_156 . V_157 &&
V_54 . V_158 == V_159 ) {
F_17 (
L_62
L_63
L_64 ,
! F_69 ( & V_54 . V_15 -> V_18 -> V_160 [ V_161 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_155 = true ;
}
if ( V_54 . V_12 == NULL ) {
const char * V_77 = L_67 ;
if ( ! V_2 -> V_155 && ! V_2 -> V_162 &&
V_54 . V_15 == V_36 -> V_163 [ V_161 ] &&
F_69 ( & V_54 . V_15 -> V_18 -> V_160 [ V_161 ] ) ) {
if ( V_156 . V_164 ) {
F_17 ( L_68 ,
V_156 . V_164 , V_77 ) ;
} else {
F_17 ( L_69 ,
V_77 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_162 = true ;
}
}
if ( V_54 . V_12 == NULL || ! V_54 . V_12 -> V_140 ) {
struct V_9 * V_10 ;
V_16 = F_70 ( V_56 , & V_145 , V_52 , & V_54 ,
V_2 -> V_165 ) ;
if ( V_16 )
return;
V_10 = F_28 ( V_52 , & V_54 , V_56 ) ;
if ( V_10 == NULL ) {
F_6 ( L_70 ) ;
return;
}
V_16 = F_71 ( V_10 , V_56 ) ;
if ( V_16 )
return;
if ( V_166 )
F_19 ( V_2 , V_10 , V_52 -> V_50 , V_26 ) ;
}
return;
}
static void F_72 ( struct V_1 * V_2 , int V_50 )
{
struct V_55 V_56 ;
struct V_51 * V_52 ;
struct V_167 * V_121 = V_2 -> V_121 ;
union V_143 * V_144 ;
struct V_36 * V_36 ;
T_6 V_168 ;
int V_96 ;
while ( ( V_144 = F_73 ( V_2 -> V_92 , V_50 ) ) != NULL ) {
V_96 = F_74 ( V_2 -> V_92 , V_144 , & V_56 ) ;
if ( V_96 ) {
F_6 ( L_71 , V_96 ) ;
goto V_169;
}
V_52 = F_75 ( V_121 -> V_92 , V_56 . V_170 ) ;
assert ( V_52 != NULL ) ;
V_168 = V_144 -> V_133 . V_151 & V_171 ;
if ( V_144 -> V_133 . type == V_61 )
++ V_2 -> V_172 ;
switch ( V_168 ) {
case V_173 :
++ V_2 -> V_174 ;
if ( V_2 -> V_73 )
goto V_169;
V_36 = & V_121 -> V_175 . V_176 ;
break;
case V_159 :
++ V_2 -> V_177 ;
if ( V_2 -> V_74 )
goto V_169;
V_36 = & V_121 -> V_175 . V_176 ;
break;
case V_178 :
++ V_2 -> V_179 ;
V_36 = F_76 ( V_121 ,
V_56 . V_149 ) ;
break;
case V_180 :
++ V_2 -> V_181 ;
default:
goto V_169;
}
if ( V_144 -> V_133 . type == V_61 ) {
F_63 ( & V_2 -> V_142 , V_144 , V_52 ,
& V_56 , V_36 ) ;
} else if ( V_144 -> V_133 . type < V_182 ) {
F_30 ( & V_52 -> V_57 , V_144 -> V_133 . type ) ;
F_77 ( V_36 , V_144 , & V_56 ) ;
} else
++ V_121 -> V_68 . V_183 ;
V_169:
F_78 ( V_2 -> V_92 , V_50 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
int V_184 ;
for ( V_184 = 0 ; V_184 < V_2 -> V_92 -> V_185 ; V_184 ++ )
F_72 ( V_2 , V_184 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
char V_77 [ 512 ] ;
struct V_51 * V_41 ;
struct V_186 * V_92 = V_2 -> V_92 ;
struct V_131 * V_187 = & V_2 -> V_131 ;
F_81 ( V_92 , V_187 ) ;
F_53 (evlist, counter) {
V_188:
if ( F_82 ( V_41 , V_2 -> V_92 -> V_189 ,
V_2 -> V_92 -> V_190 ) < 0 ) {
if ( F_83 ( V_41 , V_138 , V_77 , sizeof( V_77 ) ) ) {
if ( V_191 )
F_17 ( L_21 , V_77 ) ;
goto V_188;
}
F_84 ( V_41 , & V_187 -> V_76 ,
V_138 , V_77 , sizeof( V_77 ) ) ;
F_85 ( L_21 , V_77 ) ;
goto V_192;
}
}
if ( F_86 ( V_92 , V_187 -> V_193 , false ) < 0 ) {
F_85 ( L_72 ,
V_138 , strerror ( V_138 ) ) ;
goto V_192;
}
return 0 ;
V_192:
return - 1 ;
}
static int F_87 ( struct V_1 * V_2 V_7 )
{
if ( ! V_166 ) {
if ( V_156 . V_194 ) {
F_85 ( L_73 ) ;
return - V_195 ;
}
} else if ( V_196 . V_197 != V_198 ) {
if ( F_88 ( & V_196 ) < 0 ) {
F_85 ( L_74 ) ;
return - V_195 ;
}
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_131 * V_187 = & V_2 -> V_131 ;
T_7 V_199 ;
int V_96 ;
V_2 -> V_121 = F_90 ( NULL , false , NULL ) ;
if ( V_2 -> V_121 == NULL )
return - V_44 ;
F_91 ( & V_2 -> V_121 -> V_175 , F_61 ) ;
if ( ! V_200 ) {
V_96 = F_92 ( & V_2 -> V_121 -> V_133 . V_134 ) ;
if ( V_96 )
goto V_201;
}
V_96 = F_87 ( V_2 ) ;
if ( V_96 )
goto V_201;
F_93 ( & V_2 -> V_121 -> V_175 . V_176 , & V_187 -> V_76 ,
V_2 -> V_92 -> V_190 , false ) ;
V_96 = F_80 ( V_2 ) ;
if ( V_96 )
goto V_201;
V_2 -> V_121 -> V_92 = V_2 -> V_92 ;
F_94 ( V_2 -> V_121 ) ;
if ( ! F_95 ( & V_187 -> V_76 ) )
F_96 ( V_2 -> V_92 ) ;
F_52 ( V_2 -> V_92 -> V_97 , V_2 -> V_92 -> V_202 , 100 ) ;
F_79 ( V_2 ) ;
V_96 = - 1 ;
if ( F_97 ( & V_199 , NULL , ( V_39 > 0 ? F_57 :
F_59 ) , V_2 ) ) {
F_85 ( L_75 ) ;
goto V_201;
}
if ( V_2 -> V_203 ) {
struct V_204 V_205 ;
V_205 . V_206 = V_2 -> V_203 ;
if ( F_98 ( 0 , V_207 , & V_205 ) ) {
F_85 ( L_76 ) ;
goto V_201;
}
}
while ( ! V_135 ) {
T_4 V_208 = V_2 -> V_172 ;
F_79 ( V_2 ) ;
if ( V_208 == V_2 -> V_172 )
V_96 = F_52 ( V_2 -> V_92 -> V_97 , V_2 -> V_92 -> V_202 , 100 ) ;
}
V_96 = 0 ;
V_201:
F_99 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
return V_96 ;
}
static int
F_100 ( const struct V_209 * V_210 , const char * V_8 , int V_211 )
{
V_156 . V_194 = true ;
return F_101 ( V_210 , V_8 , V_211 ) ;
}
static int
F_102 ( const struct V_209 * V_210 , const char * V_8 , int V_211 )
{
V_156 . V_194 = true ;
return F_103 ( V_210 , V_8 , V_211 ) ;
}
static int F_104 ( const char * V_212 , const char * V_213 , void * V_214 )
{
struct V_1 * V_2 = V_214 ;
if ( ! strcmp ( V_212 , L_77 ) )
return F_105 ( V_213 , & V_2 -> V_131 ) ;
return F_106 ( V_212 , V_213 , V_214 ) ;
}
static int
F_107 ( const struct V_209 * V_210 , const char * V_8 ,
int V_211 V_7 )
{
struct V_1 * V_2 = V_210 -> V_213 ;
V_2 -> V_75 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_108 ( int V_215 , const char * * V_216 , const char * T_8 V_7 )
{
int V_217 = - 1 ;
char V_218 [ V_219 ] ;
struct V_1 V_2 = {
. V_94 = 5 ,
. V_91 = 2 ,
. V_131 = {
. V_193 = V_220 ,
. V_221 = V_220 ,
. V_222 = V_223 ,
. V_224 = 4000 ,
. V_76 = {
. V_225 = true ,
} ,
} ,
. V_165 = V_226 ,
. V_48 = 5 ,
} ;
struct V_131 * V_187 = & V_2 . V_131 ;
struct V_76 * V_76 = & V_187 -> V_76 ;
const struct V_209 V_227 [] = {
F_109 ( 'e' , L_78 , & V_2 . V_92 , L_78 ,
L_79 ,
V_228 ) ,
F_110 ( 'c' , L_80 , & V_187 -> V_222 , L_81 ) ,
F_111 ( 'p' , L_82 , & V_76 -> V_149 , L_82 ,
L_83 ) ,
F_111 ( 't' , L_84 , & V_76 -> V_229 , L_84 ,
L_85 ) ,
F_112 ( 'a' , L_86 , & V_76 -> V_230 ,
L_87 ) ,
F_111 ( 'C' , L_88 , & V_76 -> V_231 , L_88 ,
L_89 ) ,
F_111 ( 'k' , L_90 , & V_156 . V_164 ,
L_91 , L_92 ) ,
F_112 ( 0 , L_93 , & V_156 . V_232 ,
L_94 ) ,
F_112 ( 'K' , L_95 , & V_2 . V_74 ,
L_96 ) ,
F_109 ( 'm' , L_97 , & V_187 -> V_193 , L_98 ,
L_99 ,
V_233 ) ,
F_113 ( 'r' , L_100 , & V_2 . V_203 ,
L_101 ) ,
F_113 ( 'd' , L_102 , & V_2 . V_91 ,
L_103 ) ,
F_112 ( 'D' , L_104 , & V_2 . V_120 ,
L_105 ) ,
F_113 ( 'f' , L_106 , & V_2 . V_94 ,
L_107 ) ,
F_112 ( 0 , L_108 , & V_187 -> V_234 ,
L_109 ) ,
F_112 ( 'i' , L_110 , & V_187 -> V_235 ,
L_111 ) ,
F_111 ( 0 , L_112 , & V_2 . V_236 , L_113 ,
L_114 ) ,
F_112 ( 'z' , L_115 , & V_2 . V_49 , L_116 ) ,
F_114 ( 'F' , L_117 , & V_187 -> V_221 , L_118 ) ,
F_113 ( 'E' , L_119 , & V_2 . V_3 ,
L_120 ) ,
F_112 ( 'U' , L_121 , & V_2 . V_73 ,
L_122 ) ,
F_112 ( 0 , L_123 , & V_2 . V_237 , L_124 ) ,
F_112 ( 0 , L_125 , & V_2 . V_238 , L_126 ) ,
F_115 ( 'v' , L_127 , & V_191 ,
L_128 ) ,
F_111 ( 's' , L_129 , & V_239 , L_130 ,
L_131
L_132 ) ,
F_112 ( 'n' , L_133 , & V_156 . V_240 ,
L_134 ) ,
F_116 ( 'g' , NULL , & V_2 . V_131 ,
NULL , L_135 ,
& F_100 ) ,
F_109 ( 0 , L_136 , & V_2 . V_131 ,
L_137 , V_241 ,
& F_102 ) ,
F_113 ( 0 , L_138 , & V_2 . V_165 ,
L_139
L_140 F_117 ( V_226 ) ) ,
F_109 ( 0 , L_141 , NULL , L_142 ,
L_143 ,
V_242 ) ,
F_112 ( 0 , L_144 , & V_156 . V_243 ,
L_145 ) ,
F_111 ( 0 , L_146 , & V_156 . V_244 , L_147 ,
L_148 ) ,
F_111 ( 0 , L_149 , & V_156 . V_245 , L_150 ,
L_151 ) ,
F_111 ( 0 , L_152 , & V_156 . V_246 , L_153 ,
L_154 ) ,
F_112 ( 0 , L_155 , & V_156 . V_247 ,
L_156 ) ,
F_112 ( 0 , L_157 , & V_156 . V_248 ,
L_158 ) ,
F_111 ( 0 , L_159 , & V_200 , L_160 ,
L_161 ) ,
F_111 ( 'M' , L_162 , & V_249 , L_163 ,
L_164 ) ,
F_111 ( 'u' , L_165 , & V_76 -> V_132 , L_166 , L_167 ) ,
F_109 ( 0 , L_168 , & V_2 , L_169 ,
L_170 , F_107 ) ,
F_118 ()
} ;
const char * const V_250 [] = {
L_171 ,
NULL
} ;
V_2 . V_92 = F_119 () ;
if ( V_2 . V_92 == NULL )
return - V_44 ;
F_120 ( F_104 , & V_2 ) ;
V_215 = F_121 ( V_215 , V_216 , V_227 , V_250 , 0 ) ;
if ( V_215 )
F_122 ( V_250 , V_227 ) ;
if ( V_239 == V_251 )
V_239 = L_172 ;
if ( F_123 () < 0 ) {
F_124 ( V_250 , V_227 , L_173 , 1 ) ;
goto V_252;
}
V_253 = 1 ;
if ( V_2 . V_238 )
V_39 = 0 ;
else if ( V_2 . V_237 )
V_39 = 1 ;
F_125 ( false ) ;
V_217 = F_126 ( V_76 ) ;
if ( V_217 ) {
F_127 ( V_76 , V_217 , V_218 , V_219 ) ;
F_17 ( L_21 , V_218 ) ;
}
V_217 = F_128 ( V_76 ) ;
if ( V_217 ) {
int V_254 = V_138 ;
F_127 ( V_76 , V_217 , V_218 , V_219 ) ;
F_85 ( L_21 , V_218 ) ;
V_217 = - V_254 ;
goto V_252;
}
if ( F_95 ( V_76 ) )
V_76 -> V_230 = true ;
if ( F_129 ( V_2 . V_92 , V_76 ) < 0 )
F_122 ( V_250 , V_227 ) ;
if ( ! V_2 . V_92 -> V_93 &&
F_130 ( V_2 . V_92 ) < 0 ) {
F_85 ( L_174 ) ;
goto V_252;
}
V_156 . V_70 = V_2 . V_92 -> V_93 ;
if ( V_2 . V_91 < 1 )
V_2 . V_91 = 1 ;
if ( F_131 ( V_187 ) ) {
V_217 = - V_195 ;
goto V_252;
}
V_2 . V_47 = F_54 ( V_2 . V_92 ) ;
V_156 . V_255 = sizeof( struct V_13 ) ;
V_156 . V_256 = ( V_156 . V_164 == NULL ) ;
if ( F_132 () < 0 )
return - 1 ;
F_133 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_113 V_114 = {
. V_115 = F_2 ,
. V_116 = V_117 ,
} ;
F_1 ( & V_2 ) ;
V_113 ( V_118 , & V_114 , NULL ) ;
}
V_217 = F_89 ( & V_2 ) ;
V_252:
F_134 ( V_2 . V_92 ) ;
return V_217 ;
}
