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
if ( V_15 -> V_18 -> V_19 == V_20 ) {
F_5 ( L_1
L_2 , V_12 -> V_21 ) ;
F_6 ( 1 ) ;
return - 1 ;
}
V_14 = F_7 ( V_12 ) ;
if ( V_14 -> V_22 != NULL ) {
F_8 ( & V_14 -> V_23 ) ;
goto V_24;
}
F_8 ( & V_14 -> V_23 ) ;
if ( F_9 ( V_12 ) < 0 ) {
F_10 ( & V_14 -> V_23 ) ;
F_5 ( L_3 ,
V_12 -> V_21 ) ;
F_6 ( 1 ) ;
return V_16 ;
}
V_16 = F_11 ( V_12 , V_15 , 0 ) ;
if ( V_16 == 0 ) {
V_24:
V_2 -> V_25 = V_10 ;
}
F_10 ( & V_14 -> V_23 ) ;
return V_16 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
F_13 ( V_12 ) ;
}
static void F_14 ( struct V_15 * V_15 , struct V_11 * V_12 , T_4 V_26 )
{
struct V_27 V_28 ;
int V_16 = F_15 ( & V_28 ) ;
F_16 ( L_4
L_5 V_29 L_6
L_7
L_8 V_29 L_9 V_29 L_6
L_10 V_29 L_9 V_29 L_11
L_12
L_13
L_14
L_15
L_16 ,
V_26 , V_15 -> V_18 -> V_30 , F_17 ( V_15 -> V_18 ) ,
V_15 -> V_31 , V_15 -> V_32 , V_12 -> V_31 , V_12 -> V_32 ,
V_12 -> V_33 == V_34 ? 'g' :
V_12 -> V_33 == V_35 ? 'l' : 'w' , V_12 -> V_21 ,
V_16 ? L_17 : V_28 . V_36 ,
V_16 ? L_17 : V_28 . V_37 , V_38 ) ;
if ( V_39 <= 0 )
F_6 ( 5 ) ;
V_15 -> V_40 = true ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int V_41 , T_4 V_26 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int V_16 ;
if ( V_10 == NULL || V_10 -> V_17 . V_12 == NULL ||
( ( V_2 -> V_25 == NULL ||
V_2 -> V_25 -> V_17 . V_12 != V_10 -> V_17 . V_12 ) && V_39 != 1 ) )
return;
V_12 = V_10 -> V_17 . V_12 ;
V_14 = F_7 ( V_12 ) ;
if ( F_19 ( & V_14 -> V_23 ) )
return;
if ( V_14 -> V_22 == NULL && F_9 ( V_12 ) < 0 ) {
F_10 ( & V_14 -> V_23 ) ;
F_5 ( L_3 ,
V_12 -> V_21 ) ;
F_6 ( 1 ) ;
return;
}
V_26 = V_10 -> V_17 . V_15 -> V_42 ( V_10 -> V_17 . V_15 , V_26 ) ;
V_16 = F_20 ( V_12 , V_10 -> V_17 . V_15 , V_41 , V_26 ) ;
F_10 ( & V_14 -> V_23 ) ;
if ( V_16 == - V_43 && ! V_10 -> V_17 . V_15 -> V_40 )
F_14 ( V_10 -> V_17 . V_15 , V_12 , V_26 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_44 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_7 ( V_11 ) ;
F_8 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_45;
printf ( L_18 , F_22 ( V_2 -> V_46 ) , V_11 -> V_21 ) ;
printf ( L_19 , V_2 -> V_47 ) ;
V_44 = F_23 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_46 ,
0 , V_2 -> V_47 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_48 )
F_24 ( V_11 , V_2 -> V_46 -> V_49 ) ;
else
F_25 ( V_11 , V_2 -> V_46 -> V_49 ) ;
if ( V_44 != 0 )
printf ( L_20 , V_44 ) ;
V_45:
F_10 ( & V_14 -> V_23 ) ;
}
static struct V_9 * F_26 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_9 * V_10 ;
F_8 ( & V_51 -> V_56 . V_23 ) ;
V_10 = F_27 ( & V_51 -> V_56 , V_53 , NULL , V_55 -> V_57 ,
V_55 -> V_58 ) ;
F_10 ( & V_51 -> V_56 . V_23 ) ;
if ( V_10 == NULL )
return NULL ;
F_28 ( & V_51 -> V_56 , V_59 ) ;
return V_10 ;
}
static void F_29 ( struct V_1 * V_2 )
{
char V_60 [ 160 ] ;
int V_61 = 0 ;
const int V_62 = V_2 -> V_4 . V_63 - 1 ;
puts ( V_64 ) ;
F_30 ( V_2 , V_60 , sizeof( V_60 ) ) ;
printf ( L_21 , V_60 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_62 , V_62 , V_65 ) ;
if ( V_2 -> V_46 -> V_56 . V_66 . V_67 !=
V_2 -> V_46 -> V_56 . V_66 . V_68 [ V_69 ] ) {
V_2 -> V_46 -> V_56 . V_66 . V_67 =
V_2 -> V_46 -> V_56 . V_66 . V_68 [ V_69 ] ;
F_32 ( stdout , V_70 ,
L_23 ,
V_2 -> V_46 -> V_56 . V_66 . V_67 ) ;
++ V_61 ;
}
if ( V_2 -> V_25 ) {
F_21 ( V_2 ) ;
return;
}
F_33 ( & V_2 -> V_46 -> V_56 ) ;
F_34 ( & V_2 -> V_46 -> V_56 ) ;
F_35 ( & V_2 -> V_46 -> V_56 ,
V_2 -> V_71 ,
V_2 -> V_72 ) ;
F_36 ( & V_2 -> V_46 -> V_56 ,
V_2 -> V_3 - V_61 ) ;
putchar ( '\n' ) ;
F_37 ( & V_2 -> V_46 -> V_56 , false ,
V_2 -> V_3 - V_61 , V_62 ,
V_2 -> V_73 , stdout ) ;
}
static void F_38 ( int * V_74 , const char * V_75 )
{
char * V_76 = malloc ( 0 ) , * V_77 ;
T_5 V_78 = 0 ;
int V_79 ;
fprintf ( stdout , L_24 , V_75 ) ;
if ( F_39 ( & V_76 , & V_78 , V_80 ) < 0 )
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
* V_74 = V_79 ;
V_81:
free ( V_76 ) ;
}
static void F_40 ( int * V_74 , const char * V_75 )
{
int V_79 = 0 ;
F_38 ( & V_79 , V_75 ) ;
if ( V_79 >= 0 && V_79 <= 100 )
* V_74 = V_79 ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_75 )
{
char * V_76 = malloc ( 0 ) , * V_77 ;
struct V_9 * V_82 = V_2 -> V_25 , * V_83 , * V_84 = NULL ;
struct V_85 * V_86 ;
T_5 V_78 = 0 ;
if ( V_82 ) {
F_12 ( V_82 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_75 ) ;
if ( F_39 ( & V_76 , & V_78 , V_80 ) < 0 )
goto V_81;
V_77 = strchr ( V_76 , '\n' ) ;
if ( V_77 )
* V_77 = 0 ;
V_86 = F_42 ( & V_2 -> V_46 -> V_56 . V_87 ) ;
while ( V_86 ) {
V_83 = F_43 ( V_86 , struct V_9 , V_85 ) ;
if ( V_83 -> V_17 . V_12 && ! strcmp ( V_76 , V_83 -> V_17 . V_12 -> V_21 ) ) {
V_84 = V_83 ;
break;
}
V_86 = F_44 ( & V_83 -> V_85 ) ;
}
if ( ! V_84 ) {
fprintf ( V_88 , L_25 , V_76 ) ;
F_6 ( 1 ) ;
} else
F_4 ( V_2 , V_84 ) ;
V_81:
free ( V_76 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_89 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_90 -> V_91 > 1 )
fprintf ( stdout , L_29 , F_22 ( V_2 -> V_46 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_92 ) ;
fprintf ( stdout , L_31 , V_2 -> V_47 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_72 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_71 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_48 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_93 )
{
switch ( V_93 ) {
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
return V_2 -> V_90 -> V_91 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , int V_93 )
{
bool V_94 = true ;
if ( ! F_46 ( V_2 , V_93 ) ) {
struct V_95 V_96 = { . V_97 = 0 , . V_98 = V_99 } ;
struct V_100 V_101 , V_102 ;
F_45 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_48 ( 0 , & V_102 ) ;
V_101 = V_102 ;
V_101 . V_103 &= ~ ( V_104 | V_105 ) ;
V_101 . V_106 [ V_107 ] = 0 ;
V_101 . V_106 [ V_108 ] = 0 ;
F_49 ( 0 , V_109 , & V_101 ) ;
F_50 ( & V_96 , 1 , - 1 ) ;
V_93 = getc ( V_80 ) ;
F_49 ( 0 , V_110 , & V_102 ) ;
if ( ! F_46 ( V_2 , V_93 ) )
return V_94 ;
}
switch ( V_93 ) {
case 'd' :
F_38 ( & V_2 -> V_89 , L_42 ) ;
if ( V_2 -> V_89 < 1 )
V_2 -> V_89 = 1 ;
break;
case 'e' :
F_38 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_111 V_112 = {
. V_113 = F_2 ,
. V_114 = V_115 ,
} ;
F_2 ( V_116 , NULL , V_2 ) ;
V_111 ( V_116 , & V_112 , NULL ) ;
} else {
signal ( V_116 , V_117 ) ;
}
break;
case 'E' :
if ( V_2 -> V_90 -> V_91 > 1 ) {
int V_41 = 0 ;
fprintf ( V_88 , L_44 ) ;
F_51 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_88 , L_45 , V_2 -> V_46 -> V_49 , F_22 ( V_2 -> V_46 ) ) ;
F_38 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_90 -> V_91 ) {
V_2 -> V_46 = F_52 ( V_2 -> V_90 ) ;
fprintf ( V_88 , L_47 , F_22 ( V_2 -> V_46 ) ) ;
F_6 ( 1 ) ;
break;
}
F_51 (top->sym_evsel, &top->evlist->entries, node)
if ( V_2 -> V_46 -> V_49 == V_41 )
break;
} else
V_2 -> V_46 = F_52 ( V_2 -> V_90 ) ;
break;
case 'f' :
F_38 ( & V_2 -> V_92 , L_48 ) ;
break;
case 'F' :
F_40 ( & V_2 -> V_47 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_72 = ! V_2 -> V_72 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_118 )
F_53 ( V_2 -> V_119 , V_88 ) ;
V_94 = false ;
break;
case 's' :
F_41 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_82 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_12 ( V_82 ) ;
}
break;
case 'U' :
V_2 -> V_71 = ! V_2 -> V_71 ;
break;
case 'z' :
V_2 -> V_48 = ! V_2 -> V_48 ;
break;
default:
break;
}
return V_94 ;
}
static void F_54 ( void * V_8 )
{
struct V_1 * V_120 = V_8 ;
F_31 ( V_120 ) ;
if ( V_120 -> V_90 -> V_121 != NULL )
V_120 -> V_46 = V_120 -> V_90 -> V_121 ;
F_33 ( & V_120 -> V_46 -> V_56 ) ;
F_34 ( & V_120 -> V_46 -> V_56 ) ;
F_35 ( & V_120 -> V_46 -> V_56 ,
V_120 -> V_71 ,
V_120 -> V_72 ) ;
}
static void * F_55 ( void * V_8 )
{
struct V_50 * V_122 ;
struct V_1 * V_2 = V_8 ;
const char * V_123 = L_52 ;
struct V_124 V_125 = {
. V_126 = F_54 ,
. V_8 = V_2 ,
. V_127 = V_2 -> V_89 ,
} ;
F_54 ( V_2 ) ;
F_51 (pos, &top->evlist->entries, node)
V_122 -> V_56 . V_128 = V_2 -> V_129 . V_74 . V_130 ;
F_56 ( V_2 -> V_90 , V_123 , & V_125 , V_2 -> V_73 ,
& V_2 -> V_119 -> V_131 . V_132 ) ;
V_133 = 1 ;
return NULL ;
}
static void * F_57 ( void * V_8 )
{
struct V_95 V_96 = { . V_97 = 0 , . V_98 = V_99 } ;
struct V_100 V_101 , V_102 ;
struct V_1 * V_2 = V_8 ;
int V_134 , V_93 ;
F_48 ( 0 , & V_102 ) ;
V_101 = V_102 ;
V_101 . V_103 &= ~ ( V_104 | V_105 ) ;
V_101 . V_106 [ V_107 ] = 0 ;
V_101 . V_106 [ V_108 ] = 0 ;
F_58 () ;
V_135:
V_134 = V_2 -> V_89 * 1000 ;
F_49 ( 0 , V_109 , & V_101 ) ;
getc ( V_80 ) ;
while ( ! V_133 ) {
F_29 ( V_2 ) ;
switch ( F_50 ( & V_96 , 1 , V_134 ) ) {
case 0 :
continue;
case - 1 :
if ( V_136 == V_137 )
continue;
default:
V_93 = getc ( V_80 ) ;
F_49 ( 0 , V_110 , & V_102 ) ;
if ( F_47 ( V_2 , V_93 ) )
goto V_135;
V_133 = 1 ;
}
}
return NULL ;
}
static int F_59 ( struct V_15 * V_15 V_7 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
int V_138 ;
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
for ( V_138 = 0 ; V_139 [ V_138 ] ; V_138 ++ ) {
if ( ! strcmp ( V_139 [ V_138 ] , V_21 ) ) {
V_12 -> V_140 = true ;
break;
}
}
return 0 ;
}
static void F_60 ( struct V_141 * V_142 ,
const union V_143 * V_144 ,
struct V_50 * V_51 ,
struct V_54 * V_55 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_61 ( V_142 , struct V_1 , V_142 ) ;
struct V_11 * V_145 = NULL ;
T_4 V_26 = V_144 -> V_26 . V_26 ;
struct V_52 V_53 ;
int V_16 ;
if ( ! V_36 && V_146 ) {
static struct V_147 * V_148 ;
if ( ! V_148 )
V_148 = F_62 ( NULL ) ;
if ( ! F_63 ( V_148 , V_144 -> V_26 . V_149 ) ) {
F_5 ( L_60 ,
V_144 -> V_26 . V_149 ) ;
F_64 ( V_148 , V_144 -> V_26 . V_149 ) ;
}
return;
}
if ( ! V_36 ) {
F_5 ( L_61 ,
V_2 -> V_119 -> V_66 . V_150 ++ ) ;
return;
}
if ( V_144 -> V_131 . V_151 & V_152 )
V_2 -> V_153 ++ ;
if ( F_65 ( V_144 , V_36 , & V_53 , V_55 ,
F_59 ) < 0 ||
V_53 . V_154 )
return;
if ( ! V_2 -> V_155 &&
V_156 . V_157 &&
V_53 . V_158 == V_159 ) {
F_16 (
L_62
L_63
L_64 ,
! F_66 ( & V_53 . V_15 -> V_18 -> V_160 [ V_161 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_155 = true ;
}
if ( V_53 . V_12 == NULL ) {
const char * V_75 = L_67 ;
if ( ! V_2 -> V_155 && ! V_2 -> V_162 &&
V_53 . V_15 == V_36 -> V_163 [ V_161 ] &&
F_66 ( & V_53 . V_15 -> V_18 -> V_160 [ V_161 ] ) ) {
if ( V_156 . V_164 ) {
F_16 ( L_68 ,
V_156 . V_164 , V_75 ) ;
} else {
F_16 ( L_69 ,
V_75 ) ;
}
if ( V_39 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_162 = true ;
}
}
if ( V_53 . V_12 == NULL || ! V_53 . V_12 -> V_140 ) {
struct V_9 * V_10 ;
if ( ( V_165 || V_156 . V_166 ) &&
V_55 -> V_167 ) {
V_16 = F_67 ( V_36 , V_51 ,
V_53 . V_168 , V_55 ,
& V_145 ) ;
if ( V_16 )
return;
}
V_10 = F_26 ( V_51 , & V_53 , V_55 ) ;
if ( V_10 == NULL ) {
F_5 ( L_70 ) ;
return;
}
if ( V_156 . V_166 ) {
V_16 = F_68 ( V_10 -> V_167 , & V_169 ,
V_55 -> V_57 ) ;
if ( V_16 )
return;
}
if ( V_170 )
F_18 ( V_2 , V_10 , V_51 -> V_49 , V_26 ) ;
}
return;
}
static void F_69 ( struct V_1 * V_2 , int V_49 )
{
struct V_54 V_55 ;
struct V_50 * V_51 ;
struct V_171 * V_119 = V_2 -> V_119 ;
union V_143 * V_144 ;
struct V_36 * V_36 ;
T_6 V_172 ;
int V_94 ;
while ( ( V_144 = F_70 ( V_2 -> V_90 , V_49 ) ) != NULL ) {
V_94 = F_71 ( V_2 -> V_90 , V_144 , & V_55 ) ;
if ( V_94 ) {
F_5 ( L_71 , V_94 ) ;
continue;
}
V_51 = F_72 ( V_119 -> V_90 , V_55 . V_173 ) ;
assert ( V_51 != NULL ) ;
V_172 = V_144 -> V_131 . V_151 & V_174 ;
if ( V_144 -> V_131 . type == V_59 )
++ V_2 -> V_175 ;
switch ( V_172 ) {
case V_176 :
++ V_2 -> V_177 ;
if ( V_2 -> V_71 )
continue;
V_36 = & V_119 -> V_178 . V_179 ;
break;
case V_159 :
++ V_2 -> V_180 ;
if ( V_2 -> V_72 )
continue;
V_36 = & V_119 -> V_178 . V_179 ;
break;
case V_181 :
++ V_2 -> V_182 ;
V_36 = F_73 ( V_119 , V_144 -> V_26 . V_149 ) ;
break;
case V_183 :
++ V_2 -> V_184 ;
default:
continue;
}
if ( V_144 -> V_131 . type == V_59 ) {
F_60 ( & V_2 -> V_142 , V_144 , V_51 ,
& V_55 , V_36 ) ;
} else if ( V_144 -> V_131 . type < V_185 ) {
F_28 ( & V_51 -> V_56 , V_144 -> V_131 . type ) ;
F_74 ( V_36 , V_144 ) ;
} else
++ V_119 -> V_66 . V_186 ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_2 -> V_90 -> V_187 ; V_138 ++ )
F_69 ( V_2 , V_138 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
char V_75 [ 512 ] ;
struct V_50 * V_41 ;
struct V_188 * V_90 = V_2 -> V_90 ;
struct V_189 * V_190 = & V_2 -> V_129 ;
F_77 ( V_90 , V_190 ) ;
F_51 (counter, &evlist->entries, node) {
V_191:
if ( F_78 ( V_41 , V_2 -> V_90 -> V_192 ,
V_2 -> V_90 -> V_193 ) < 0 ) {
if ( F_79 ( V_41 , V_136 , V_75 , sizeof( V_75 ) ) ) {
if ( V_194 )
F_16 ( L_21 , V_75 ) ;
goto V_191;
}
F_80 ( V_41 , & V_190 -> V_74 ,
V_136 , V_75 , sizeof( V_75 ) ) ;
F_81 ( L_21 , V_75 ) ;
goto V_195;
}
}
if ( F_82 ( V_90 , V_190 -> V_196 , false ) < 0 ) {
F_81 ( L_72 ,
V_136 , strerror ( V_136 ) ) ;
goto V_195;
}
return 0 ;
V_195:
return - 1 ;
}
static int F_83 ( struct V_1 * V_2 V_7 )
{
if ( ! V_170 ) {
if ( V_156 . V_166 ) {
F_81 ( L_73 ) ;
return - V_197 ;
}
} else if ( V_198 . V_199 != V_200 ) {
if ( F_84 ( & V_198 ) < 0 ) {
F_81 ( L_74 ) ;
return - V_197 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_129 ;
T_7 V_168 ;
int V_94 ;
V_2 -> V_119 = F_86 ( NULL , V_201 , false , false , NULL ) ;
if ( V_2 -> V_119 == NULL )
return - V_202 ;
V_94 = F_83 ( V_2 ) ;
if ( V_94 )
goto V_203;
if ( F_87 ( & V_190 -> V_74 ) )
F_88 ( & V_2 -> V_142 , V_2 -> V_90 -> V_193 ,
V_204 ,
& V_2 -> V_119 -> V_178 . V_179 ) ;
else
F_89 ( & V_2 -> V_142 , V_204 ,
& V_2 -> V_119 -> V_178 . V_179 ) ;
V_94 = F_76 ( V_2 ) ;
if ( V_94 )
goto V_203;
V_2 -> V_119 -> V_90 = V_2 -> V_90 ;
F_90 ( V_2 -> V_119 ) ;
if ( ! F_91 ( & V_190 -> V_74 ) )
F_92 ( V_2 -> V_90 ) ;
F_50 ( V_2 -> V_90 -> V_95 , V_2 -> V_90 -> V_205 , 100 ) ;
F_75 ( V_2 ) ;
V_94 = - 1 ;
if ( F_93 ( & V_168 , NULL , ( V_39 > 0 ? F_55 :
F_57 ) , V_2 ) ) {
F_81 ( L_75 ) ;
goto V_203;
}
if ( V_2 -> V_206 ) {
struct V_207 V_208 ;
V_208 . V_209 = V_2 -> V_206 ;
if ( F_94 ( 0 , V_210 , & V_208 ) ) {
F_81 ( L_76 ) ;
goto V_203;
}
}
while ( ! V_133 ) {
T_4 V_211 = V_2 -> V_175 ;
F_75 ( V_2 ) ;
if ( V_211 == V_2 -> V_175 )
V_94 = F_50 ( V_2 -> V_90 -> V_95 , V_2 -> V_90 -> V_205 , 100 ) ;
}
V_94 = 0 ;
V_203:
F_95 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
return V_94 ;
}
static int
F_96 ( const struct V_212 * V_213 , const char * V_8 , int V_214 )
{
if ( V_214 )
return 0 ;
V_156 . V_166 = true ;
return F_97 ( V_213 , V_8 , V_214 ) ;
}
static int
F_98 ( const struct V_212 * V_213 , const char * V_8 ,
int V_214 V_7 )
{
struct V_1 * V_2 = V_213 -> V_215 ;
V_2 -> V_73 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_99 ( int V_216 , const char * * V_217 , const char * T_8 V_7 )
{
int V_218 ;
char V_219 [ V_220 ] ;
struct V_1 V_2 = {
. V_92 = 5 ,
. V_89 = 2 ,
. V_129 = {
. V_196 = V_221 ,
. V_222 = V_221 ,
. V_223 = V_224 ,
. V_225 = 4000 ,
. V_74 = {
. V_226 = true ,
} ,
} ,
. V_47 = 5 ,
} ;
struct V_189 * V_190 = & V_2 . V_129 ;
struct V_227 * V_74 = & V_190 -> V_74 ;
const struct V_212 V_228 [] = {
F_100 ( 'e' , L_77 , & V_2 . V_90 , L_77 ,
L_78 ,
V_229 ) ,
F_101 ( 'c' , L_79 , & V_190 -> V_223 , L_80 ) ,
F_102 ( 'p' , L_81 , & V_74 -> V_149 , L_81 ,
L_82 ) ,
F_102 ( 't' , L_83 , & V_74 -> V_230 , L_83 ,
L_84 ) ,
F_103 ( 'a' , L_85 , & V_74 -> V_231 ,
L_86 ) ,
F_102 ( 'C' , L_87 , & V_74 -> V_232 , L_87 ,
L_88 ) ,
F_102 ( 'k' , L_89 , & V_156 . V_164 ,
L_90 , L_91 ) ,
F_103 ( 'K' , L_92 , & V_2 . V_72 ,
L_93 ) ,
F_104 ( 'm' , L_94 , & V_190 -> V_196 ,
L_95 ) ,
F_105 ( 'r' , L_96 , & V_2 . V_206 ,
L_97 ) ,
F_105 ( 'd' , L_98 , & V_2 . V_89 ,
L_99 ) ,
F_103 ( 'D' , L_100 , & V_2 . V_118 ,
L_101 ) ,
F_105 ( 'f' , L_102 , & V_2 . V_92 ,
L_103 ) ,
F_103 ( 'g' , L_104 , & V_190 -> V_233 ,
L_105 ) ,
F_103 ( 'i' , L_106 , & V_190 -> V_234 ,
L_107 ) ,
F_102 ( 0 , L_108 , & V_2 . V_235 , L_109 ,
L_110 ) ,
F_103 ( 'z' , L_111 , & V_2 . V_48 , L_112 ) ,
F_104 ( 'F' , L_113 , & V_190 -> V_222 , L_114 ) ,
F_105 ( 'E' , L_115 , & V_2 . V_3 ,
L_116 ) ,
F_103 ( 'U' , L_117 , & V_2 . V_71 ,
L_118 ) ,
F_103 ( 0 , L_119 , & V_2 . V_236 , L_120 ) ,
F_103 ( 0 , L_121 , & V_2 . V_237 , L_122 ) ,
F_106 ( 'v' , L_123 , & V_194 ,
L_124 ) ,
F_102 ( 's' , L_125 , & V_238 , L_126 ,
L_127 ) ,
F_103 ( 'n' , L_128 , & V_156 . V_239 ,
L_129 ) ,
F_107 ( 'G' , L_130 , & V_2 . V_129 ,
L_131 , V_240 ,
& F_96 , L_132 ) ,
F_103 ( 0 , L_133 , & V_156 . V_241 ,
L_134 ) ,
F_102 ( 0 , L_135 , & V_156 . V_242 , L_136 ,
L_137 ) ,
F_102 ( 0 , L_138 , & V_156 . V_243 , L_139 ,
L_140 ) ,
F_102 ( 0 , L_141 , & V_156 . V_244 , L_142 ,
L_143 ) ,
F_103 ( 0 , L_144 , & V_156 . V_245 ,
L_145 ) ,
F_103 ( 0 , L_146 , & V_156 . V_246 ,
L_147 ) ,
F_102 ( 'M' , L_148 , & V_247 , L_149 ,
L_150 ) ,
F_102 ( 'u' , L_151 , & V_74 -> V_130 , L_152 , L_153 ) ,
F_100 ( 0 , L_154 , & V_2 , L_155 ,
L_156 , F_98 ) ,
F_108 ()
} ;
const char * const V_248 [] = {
L_157 ,
NULL
} ;
V_2 . V_90 = F_109 () ;
if ( V_2 . V_90 == NULL )
return - V_202 ;
V_216 = F_110 ( V_216 , V_217 , V_228 , V_248 , 0 ) ;
if ( V_216 )
F_111 ( V_248 , V_228 ) ;
if ( V_238 == V_249 )
V_238 = L_158 ;
if ( F_112 () < 0 )
F_111 ( V_248 , V_228 ) ;
V_250 = 1 ;
if ( V_2 . V_237 )
V_39 = 0 ;
else if ( V_2 . V_236 )
V_39 = 1 ;
F_113 ( false ) ;
V_218 = F_114 ( V_74 ) ;
if ( V_218 ) {
F_115 ( V_74 , V_218 , V_219 , V_220 ) ;
F_16 ( L_159 , V_219 ) ;
}
V_218 = F_116 ( V_74 ) ;
if ( V_218 ) {
int V_251 = V_136 ;
F_115 ( V_74 , V_218 , V_219 , V_220 ) ;
F_81 ( L_159 , V_219 ) ;
V_218 = - V_251 ;
goto V_252;
}
if ( F_91 ( V_74 ) )
V_74 -> V_231 = true ;
if ( F_117 ( V_2 . V_90 , V_74 ) < 0 )
F_111 ( V_248 , V_228 ) ;
if ( ! V_2 . V_90 -> V_91 &&
F_118 ( V_2 . V_90 ) < 0 ) {
F_81 ( L_160 ) ;
goto V_253;
}
V_156 . V_68 = V_2 . V_90 -> V_91 ;
if ( V_2 . V_89 < 1 )
V_2 . V_89 = 1 ;
if ( V_190 -> V_223 != V_224 )
V_190 -> V_254 = V_190 -> V_223 ;
if ( V_190 -> V_222 != V_221 )
V_190 -> V_225 = V_190 -> V_222 ;
if ( V_190 -> V_254 )
V_190 -> V_225 = 0 ;
else if ( V_190 -> V_225 ) {
V_190 -> V_254 = V_190 -> V_225 ;
} else {
F_81 ( L_161 ) ;
V_218 = - V_197 ;
goto V_253;
}
V_2 . V_46 = F_52 ( V_2 . V_90 ) ;
V_156 . V_255 = sizeof( struct V_13 ) ;
V_156 . V_256 = ( V_156 . V_164 == NULL ) ;
if ( F_119 () < 0 )
return - 1 ;
F_120 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_111 V_112 = {
. V_113 = F_2 ,
. V_114 = V_115 ,
} ;
F_1 ( & V_2 ) ;
V_111 ( V_116 , & V_112 , NULL ) ;
}
V_218 = F_85 ( & V_2 ) ;
V_253:
F_121 ( V_2 . V_90 ) ;
V_252:
F_122 ( V_2 . V_90 ) ;
return V_218 ;
}
