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
int V_16 ;
if ( V_10 == NULL || V_10 -> V_17 . V_12 == NULL ||
( ( V_2 -> V_25 == NULL ||
V_2 -> V_25 -> V_17 . V_12 != V_10 -> V_17 . V_12 ) && V_39 != 1 ) )
return;
V_12 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_12 ) ;
if ( F_20 ( & V_14 -> V_23 ) )
return;
if ( V_14 -> V_22 == NULL && F_10 ( V_12 ) < 0 ) {
F_11 ( & V_14 -> V_23 ) ;
F_6 ( L_3 ,
V_12 -> V_21 ) ;
F_7 ( 1 ) ;
return;
}
V_26 = V_10 -> V_17 . V_15 -> V_42 ( V_10 -> V_17 . V_15 , V_26 ) ;
V_16 = F_21 ( V_12 , V_10 -> V_17 . V_15 , V_41 , V_26 ) ;
F_11 ( & V_14 -> V_23 ) ;
if ( V_16 == - V_43 && ! V_10 -> V_17 . V_15 -> V_40 )
F_15 ( V_10 -> V_17 . V_15 , V_12 , V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_25 ;
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_44 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_8 ( V_11 ) ;
F_9 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_45;
printf ( L_18 , F_23 ( V_2 -> V_46 ) , V_11 -> V_21 ) ;
printf ( L_19 , V_2 -> V_47 ) ;
V_44 = F_24 ( V_11 , V_10 -> V_17 . V_15 , V_2 -> V_46 ,
0 , V_2 -> V_47 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_48 )
F_25 ( V_11 , V_2 -> V_46 -> V_49 ) ;
else
F_26 ( V_11 , V_2 -> V_46 -> V_49 ) ;
if ( V_44 != 0 )
printf ( L_20 , V_44 ) ;
V_45:
F_11 ( & V_14 -> V_23 ) ;
}
static struct V_9 * F_27 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_9 * V_10 ;
F_9 ( & V_51 -> V_56 . V_23 ) ;
V_10 = F_28 ( & V_51 -> V_56 , V_53 , NULL , NULL , NULL ,
V_55 -> V_57 , V_55 -> V_58 ,
V_55 -> V_59 ) ;
F_11 ( & V_51 -> V_56 . V_23 ) ;
if ( V_10 == NULL )
return NULL ;
F_29 ( & V_51 -> V_56 , V_60 ) ;
return V_10 ;
}
static void F_30 ( struct V_1 * V_2 )
{
char V_61 [ 160 ] ;
int V_62 = 0 ;
const int V_63 = V_2 -> V_4 . V_64 - 1 ;
puts ( V_65 ) ;
F_31 ( V_2 , V_61 , sizeof( V_61 ) ) ;
printf ( L_21 , V_61 ) ;
F_32 ( V_2 ) ;
printf ( L_22 , V_63 , V_63 , V_66 ) ;
if ( V_2 -> V_46 -> V_56 . V_67 . V_68 !=
V_2 -> V_46 -> V_56 . V_67 . V_69 [ V_70 ] ) {
V_2 -> V_46 -> V_56 . V_67 . V_68 =
V_2 -> V_46 -> V_56 . V_67 . V_69 [ V_70 ] ;
F_33 ( stdout , V_71 ,
L_23 ,
V_2 -> V_46 -> V_56 . V_67 . V_68 ) ;
++ V_62 ;
}
if ( V_2 -> V_25 ) {
F_22 ( V_2 ) ;
return;
}
F_34 ( & V_2 -> V_46 -> V_56 , NULL ) ;
F_35 ( & V_2 -> V_46 -> V_56 ) ;
F_36 ( & V_2 -> V_46 -> V_56 ,
V_2 -> V_72 ,
V_2 -> V_73 ) ;
F_37 ( & V_2 -> V_46 -> V_56 ,
V_2 -> V_3 - V_62 ) ;
putchar ( '\n' ) ;
F_38 ( & V_2 -> V_46 -> V_56 , false ,
V_2 -> V_3 - V_62 , V_63 ,
V_2 -> V_74 , stdout ) ;
}
static void F_39 ( int * V_75 , const char * V_76 )
{
char * V_77 = malloc ( 0 ) , * V_78 ;
T_5 V_79 = 0 ;
int V_80 ;
fprintf ( stdout , L_24 , V_76 ) ;
if ( F_40 ( & V_77 , & V_79 , V_81 ) < 0 )
return;
V_78 = strchr ( V_77 , '\n' ) ;
if ( V_78 )
* V_78 = 0 ;
V_78 = V_77 ;
while( * V_78 ) {
if ( ! isdigit ( * V_78 ) )
goto V_82;
V_78 ++ ;
}
V_80 = strtoul ( V_77 , NULL , 10 ) ;
* V_75 = V_80 ;
V_82:
free ( V_77 ) ;
}
static void F_41 ( int * V_75 , const char * V_76 )
{
int V_80 = 0 ;
F_39 ( & V_80 , V_76 ) ;
if ( V_80 >= 0 && V_80 <= 100 )
* V_75 = V_80 ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_76 )
{
char * V_77 = malloc ( 0 ) , * V_78 ;
struct V_9 * V_83 = V_2 -> V_25 , * V_84 , * V_85 = NULL ;
struct V_86 * V_87 ;
T_5 V_79 = 0 ;
if ( V_83 ) {
F_13 ( V_83 ) ;
V_2 -> V_25 = NULL ;
}
fprintf ( stdout , L_24 , V_76 ) ;
if ( F_40 ( & V_77 , & V_79 , V_81 ) < 0 )
goto V_82;
V_78 = strchr ( V_77 , '\n' ) ;
if ( V_78 )
* V_78 = 0 ;
V_87 = F_43 ( & V_2 -> V_46 -> V_56 . V_88 ) ;
while ( V_87 ) {
V_84 = F_44 ( V_87 , struct V_9 , V_86 ) ;
if ( V_84 -> V_17 . V_12 && ! strcmp ( V_77 , V_84 -> V_17 . V_12 -> V_21 ) ) {
V_85 = V_84 ;
break;
}
V_87 = F_45 ( & V_84 -> V_86 ) ;
}
if ( ! V_85 ) {
fprintf ( V_89 , L_25 , V_77 ) ;
F_7 ( 1 ) ;
} else
F_4 ( V_2 , V_85 ) ;
V_82:
free ( V_77 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_21 = NULL ;
if ( V_2 -> V_25 ) {
struct V_11 * V_12 = V_2 -> V_25 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_90 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_91 -> V_92 > 1 )
fprintf ( stdout , L_29 , F_23 ( V_2 -> V_46 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_93 ) ;
fprintf ( stdout , L_31 , V_2 -> V_47 ) ;
fprintf ( stdout , L_32 , V_21 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_73 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_72 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_48 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_94 )
{
switch ( V_94 ) {
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
return V_2 -> V_91 -> V_92 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_48 ( struct V_1 * V_2 , int V_94 )
{
bool V_95 = true ;
if ( ! F_47 ( V_2 , V_94 ) ) {
struct V_96 V_97 = { . V_98 = 0 , . V_99 = V_100 } ;
struct V_101 V_102 , V_103 ;
F_46 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_49 ( 0 , & V_103 ) ;
V_102 = V_103 ;
V_102 . V_104 &= ~ ( V_105 | V_106 ) ;
V_102 . V_107 [ V_108 ] = 0 ;
V_102 . V_107 [ V_109 ] = 0 ;
F_50 ( 0 , V_110 , & V_102 ) ;
F_51 ( & V_97 , 1 , - 1 ) ;
V_94 = getc ( V_81 ) ;
F_50 ( 0 , V_111 , & V_103 ) ;
if ( ! F_47 ( V_2 , V_94 ) )
return V_95 ;
}
switch ( V_94 ) {
case 'd' :
F_39 ( & V_2 -> V_90 , L_42 ) ;
if ( V_2 -> V_90 < 1 )
V_2 -> V_90 = 1 ;
break;
case 'e' :
F_39 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_112 V_113 = {
. V_114 = F_2 ,
. V_115 = V_116 ,
} ;
F_2 ( V_117 , NULL , V_2 ) ;
V_112 ( V_117 , & V_113 , NULL ) ;
} else {
signal ( V_117 , V_118 ) ;
}
break;
case 'E' :
if ( V_2 -> V_91 -> V_92 > 1 ) {
int V_41 = 0 ;
fprintf ( V_89 , L_44 ) ;
F_52 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_89 , L_45 , V_2 -> V_46 -> V_49 , F_23 ( V_2 -> V_46 ) ) ;
F_39 ( & V_41 , L_46 ) ;
if ( V_41 >= V_2 -> V_91 -> V_92 ) {
V_2 -> V_46 = F_53 ( V_2 -> V_91 ) ;
fprintf ( V_89 , L_47 , F_23 ( V_2 -> V_46 ) ) ;
F_7 ( 1 ) ;
break;
}
F_52 (top->sym_evsel, &top->evlist->entries, node)
if ( V_2 -> V_46 -> V_49 == V_41 )
break;
} else
V_2 -> V_46 = F_53 ( V_2 -> V_91 ) ;
break;
case 'f' :
F_39 ( & V_2 -> V_93 , L_48 ) ;
break;
case 'F' :
F_41 ( & V_2 -> V_47 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_73 = ! V_2 -> V_73 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_119 )
F_54 ( V_2 -> V_120 , V_89 ) ;
V_95 = false ;
break;
case 's' :
F_42 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_25 )
break;
else {
struct V_9 * V_83 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
F_13 ( V_83 ) ;
}
break;
case 'U' :
V_2 -> V_72 = ! V_2 -> V_72 ;
break;
case 'z' :
V_2 -> V_48 = ! V_2 -> V_48 ;
break;
default:
break;
}
return V_95 ;
}
static void F_55 ( void * V_8 )
{
struct V_1 * V_121 = V_8 ;
F_32 ( V_121 ) ;
if ( V_121 -> V_91 -> V_122 != NULL )
V_121 -> V_46 = V_121 -> V_91 -> V_122 ;
F_34 ( & V_121 -> V_46 -> V_56 , NULL ) ;
F_35 ( & V_121 -> V_46 -> V_56 ) ;
F_36 ( & V_121 -> V_46 -> V_56 ,
V_121 -> V_72 ,
V_121 -> V_73 ) ;
}
static void * F_56 ( void * V_8 )
{
struct V_50 * V_123 ;
struct V_1 * V_2 = V_8 ;
const char * V_124 = L_52 ;
struct V_125 V_126 = {
. V_127 = F_55 ,
. V_8 = V_2 ,
. V_128 = V_2 -> V_90 ,
} ;
F_55 ( V_2 ) ;
F_52 (pos, &top->evlist->entries, node)
V_123 -> V_56 . V_129 = V_2 -> V_130 . V_75 . V_131 ;
F_57 ( V_2 -> V_91 , V_124 , & V_126 , V_2 -> V_74 ,
& V_2 -> V_120 -> V_132 . V_133 ) ;
V_134 = 1 ;
return NULL ;
}
static void * F_58 ( void * V_8 )
{
struct V_96 V_97 = { . V_98 = 0 , . V_99 = V_100 } ;
struct V_101 V_102 , V_103 ;
struct V_1 * V_2 = V_8 ;
int V_135 , V_94 ;
F_49 ( 0 , & V_103 ) ;
V_102 = V_103 ;
V_102 . V_104 &= ~ ( V_105 | V_106 ) ;
V_102 . V_107 [ V_108 ] = 0 ;
V_102 . V_107 [ V_109 ] = 0 ;
F_59 () ;
V_136:
V_135 = V_2 -> V_90 * 1000 ;
F_50 ( 0 , V_110 , & V_102 ) ;
getc ( V_81 ) ;
while ( ! V_134 ) {
F_30 ( V_2 ) ;
switch ( F_51 ( & V_97 , 1 , V_135 ) ) {
case 0 :
continue;
case - 1 :
if ( V_137 == V_138 )
continue;
default:
V_94 = getc ( V_81 ) ;
F_50 ( 0 , V_111 , & V_103 ) ;
if ( F_48 ( V_2 , V_94 ) )
goto V_136;
V_134 = 1 ;
}
}
return NULL ;
}
static int F_60 ( struct V_15 * V_15 V_7 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
int V_139 ;
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
for ( V_139 = 0 ; V_140 [ V_139 ] ; V_139 ++ ) {
if ( ! strcmp ( V_140 [ V_139 ] , V_21 ) ) {
V_12 -> V_141 = true ;
break;
}
}
return 0 ;
}
static void F_61 ( struct V_142 * V_143 ,
const union V_144 * V_145 ,
struct V_50 * V_51 ,
struct V_54 * V_55 ,
struct V_36 * V_36 )
{
struct V_1 * V_2 = F_62 ( V_143 , struct V_1 , V_143 ) ;
struct V_11 * V_146 = NULL ;
T_4 V_26 = V_55 -> V_26 ;
struct V_52 V_53 ;
int V_16 ;
if ( ! V_36 && V_147 ) {
static struct V_148 * V_149 ;
if ( ! V_149 )
V_149 = F_63 ( NULL ) ;
if ( ! F_64 ( V_149 , V_55 -> V_150 ) ) {
F_6 ( L_60 ,
V_55 -> V_150 ) ;
F_65 ( V_149 , V_55 -> V_150 ) ;
}
return;
}
if ( ! V_36 ) {
F_6 ( L_61 ,
V_2 -> V_120 -> V_67 . V_151 ++ ) ;
return;
}
if ( V_145 -> V_132 . V_152 & V_153 )
V_2 -> V_154 ++ ;
if ( F_66 ( V_145 , V_36 , & V_53 , V_55 ) < 0 ||
V_53 . V_155 )
return;
if ( ! V_2 -> V_156 &&
V_157 . V_158 &&
V_53 . V_159 == V_160 ) {
F_17 (
L_62
L_63
L_64 ,
! F_67 ( & V_53 . V_15 -> V_18 -> V_161 [ V_162 ] ) ?
L_65 : L_66 ) ;
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_156 = true ;
}
if ( V_53 . V_12 == NULL ) {
const char * V_76 = L_67 ;
if ( ! V_2 -> V_156 && ! V_2 -> V_163 &&
V_53 . V_15 == V_36 -> V_164 [ V_162 ] &&
F_67 ( & V_53 . V_15 -> V_18 -> V_161 [ V_162 ] ) ) {
if ( V_157 . V_165 ) {
F_17 ( L_68 ,
V_157 . V_165 , V_76 ) ;
} else {
F_17 ( L_69 ,
V_76 ) ;
}
if ( V_39 <= 0 )
F_7 ( 5 ) ;
V_2 -> V_163 = true ;
}
}
if ( V_53 . V_12 == NULL || ! V_53 . V_12 -> V_141 ) {
struct V_9 * V_10 ;
if ( ( V_166 || V_157 . V_167 ) &&
V_55 -> V_168 ) {
V_16 = F_68 ( V_36 , V_51 ,
V_53 . V_169 , V_55 ,
& V_146 , & V_53 ,
V_2 -> V_170 ) ;
if ( V_16 )
return;
}
V_10 = F_27 ( V_51 , & V_53 , V_55 ) ;
if ( V_10 == NULL ) {
F_6 ( L_70 ) ;
return;
}
if ( V_157 . V_167 ) {
V_16 = F_69 ( V_10 -> V_168 , & V_171 ,
V_55 -> V_57 ) ;
if ( V_16 )
return;
}
if ( V_172 )
F_19 ( V_2 , V_10 , V_51 -> V_49 , V_26 ) ;
}
return;
}
static void F_70 ( struct V_1 * V_2 , int V_49 )
{
struct V_54 V_55 ;
struct V_50 * V_51 ;
struct V_173 * V_120 = V_2 -> V_120 ;
union V_144 * V_145 ;
struct V_36 * V_36 ;
T_6 V_174 ;
int V_95 ;
while ( ( V_145 = F_71 ( V_2 -> V_91 , V_49 ) ) != NULL ) {
V_95 = F_72 ( V_2 -> V_91 , V_145 , & V_55 ) ;
if ( V_95 ) {
F_6 ( L_71 , V_95 ) ;
goto V_175;
}
V_51 = F_73 ( V_120 -> V_91 , V_55 . V_176 ) ;
assert ( V_51 != NULL ) ;
V_174 = V_145 -> V_132 . V_152 & V_177 ;
if ( V_145 -> V_132 . type == V_60 )
++ V_2 -> V_178 ;
switch ( V_174 ) {
case V_179 :
++ V_2 -> V_180 ;
if ( V_2 -> V_72 )
goto V_175;
V_36 = & V_120 -> V_181 . V_182 ;
break;
case V_160 :
++ V_2 -> V_183 ;
if ( V_2 -> V_73 )
goto V_175;
V_36 = & V_120 -> V_181 . V_182 ;
break;
case V_184 :
++ V_2 -> V_185 ;
V_36 = F_74 ( V_120 ,
V_55 . V_150 ) ;
break;
case V_186 :
++ V_2 -> V_187 ;
default:
goto V_175;
}
if ( V_145 -> V_132 . type == V_60 ) {
F_61 ( & V_2 -> V_143 , V_145 , V_51 ,
& V_55 , V_36 ) ;
} else if ( V_145 -> V_132 . type < V_188 ) {
F_29 ( & V_51 -> V_56 , V_145 -> V_132 . type ) ;
F_75 ( V_36 , V_145 , & V_55 ) ;
} else
++ V_120 -> V_67 . V_189 ;
V_175:
F_76 ( V_2 -> V_91 , V_49 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_2 -> V_91 -> V_190 ; V_139 ++ )
F_70 ( V_2 , V_139 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
char V_76 [ 512 ] ;
struct V_50 * V_41 ;
struct V_191 * V_91 = V_2 -> V_91 ;
struct V_192 * V_193 = & V_2 -> V_130 ;
F_79 ( V_91 , V_193 ) ;
F_52 (counter, &evlist->entries, node) {
V_194:
if ( F_80 ( V_41 , V_2 -> V_91 -> V_195 ,
V_2 -> V_91 -> V_196 ) < 0 ) {
if ( F_81 ( V_41 , V_137 , V_76 , sizeof( V_76 ) ) ) {
if ( V_197 )
F_17 ( L_21 , V_76 ) ;
goto V_194;
}
F_82 ( V_41 , & V_193 -> V_75 ,
V_137 , V_76 , sizeof( V_76 ) ) ;
F_83 ( L_21 , V_76 ) ;
goto V_198;
}
}
if ( F_84 ( V_91 , V_193 -> V_199 , false ) < 0 ) {
F_83 ( L_72 ,
V_137 , strerror ( V_137 ) ) ;
goto V_198;
}
return 0 ;
V_198:
return - 1 ;
}
static int F_85 ( struct V_1 * V_2 V_7 )
{
if ( ! V_172 ) {
if ( V_157 . V_167 ) {
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
struct V_192 * V_193 = & V_2 -> V_130 ;
T_7 V_169 ;
int V_95 ;
V_2 -> V_120 = F_88 ( NULL , false , NULL ) ;
if ( V_2 -> V_120 == NULL )
return - V_204 ;
F_89 ( & V_2 -> V_120 -> V_181 , F_60 ) ;
if ( ! V_205 ) {
V_95 = F_90 ( & V_2 -> V_120 -> V_132 . V_133 ) ;
if ( V_95 )
goto V_206;
}
V_95 = F_85 ( V_2 ) ;
if ( V_95 )
goto V_206;
F_91 ( & V_2 -> V_120 -> V_181 . V_182 , & V_193 -> V_75 ,
V_2 -> V_91 -> V_196 , false ) ;
V_95 = F_78 ( V_2 ) ;
if ( V_95 )
goto V_206;
V_2 -> V_120 -> V_91 = V_2 -> V_91 ;
F_92 ( V_2 -> V_120 ) ;
if ( ! F_93 ( & V_193 -> V_75 ) )
F_94 ( V_2 -> V_91 ) ;
F_51 ( V_2 -> V_91 -> V_96 , V_2 -> V_91 -> V_207 , 100 ) ;
F_77 ( V_2 ) ;
V_95 = - 1 ;
if ( F_95 ( & V_169 , NULL , ( V_39 > 0 ? F_56 :
F_58 ) , V_2 ) ) {
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
while ( ! V_134 ) {
T_4 V_213 = V_2 -> V_178 ;
F_77 ( V_2 ) ;
if ( V_213 == V_2 -> V_178 )
V_95 = F_51 ( V_2 -> V_91 -> V_96 , V_2 -> V_91 -> V_207 , 100 ) ;
}
V_95 = 0 ;
V_206:
F_97 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
return V_95 ;
}
static int
F_98 ( const struct V_214 * V_215 , const char * V_8 , int V_216 )
{
V_157 . V_167 = true ;
return F_99 ( V_215 , V_8 , V_216 ) ;
}
static int
F_100 ( const struct V_214 * V_215 , const char * V_8 , int V_216 )
{
V_157 . V_167 = true ;
return F_101 ( V_215 , V_8 , V_216 ) ;
}
static int
F_102 ( const struct V_214 * V_215 , const char * V_8 ,
int V_216 V_7 )
{
struct V_1 * V_2 = V_215 -> V_217 ;
V_2 -> V_74 = strtof ( V_8 , NULL ) ;
return 0 ;
}
int F_103 ( int V_218 , const char * * V_219 , const char * T_8 V_7 )
{
int V_220 = - 1 ;
char V_221 [ V_222 ] ;
struct V_1 V_2 = {
. V_93 = 5 ,
. V_90 = 2 ,
. V_130 = {
. V_199 = V_223 ,
. V_224 = V_223 ,
. V_225 = V_226 ,
. V_227 = 4000 ,
. V_75 = {
. V_228 = true ,
} ,
} ,
. V_170 = V_229 ,
. V_47 = 5 ,
} ;
struct V_192 * V_193 = & V_2 . V_130 ;
struct V_75 * V_75 = & V_193 -> V_75 ;
const struct V_214 V_230 [] = {
F_104 ( 'e' , L_77 , & V_2 . V_91 , L_77 ,
L_78 ,
V_231 ) ,
F_105 ( 'c' , L_79 , & V_193 -> V_225 , L_80 ) ,
F_106 ( 'p' , L_81 , & V_75 -> V_150 , L_81 ,
L_82 ) ,
F_106 ( 't' , L_83 , & V_75 -> V_232 , L_83 ,
L_84 ) ,
F_107 ( 'a' , L_85 , & V_75 -> V_233 ,
L_86 ) ,
F_106 ( 'C' , L_87 , & V_75 -> V_234 , L_87 ,
L_88 ) ,
F_106 ( 'k' , L_89 , & V_157 . V_165 ,
L_90 , L_91 ) ,
F_107 ( 0 , L_92 , & V_157 . V_235 ,
L_93 ) ,
F_107 ( 'K' , L_94 , & V_2 . V_73 ,
L_95 ) ,
F_104 ( 'm' , L_96 , & V_193 -> V_199 , L_97 ,
L_98 ,
V_236 ) ,
F_108 ( 'r' , L_99 , & V_2 . V_208 ,
L_100 ) ,
F_108 ( 'd' , L_101 , & V_2 . V_90 ,
L_102 ) ,
F_107 ( 'D' , L_103 , & V_2 . V_119 ,
L_104 ) ,
F_108 ( 'f' , L_105 , & V_2 . V_93 ,
L_106 ) ,
F_107 ( 'g' , L_107 , & V_193 -> V_237 ,
L_108 ) ,
F_107 ( 'i' , L_109 , & V_193 -> V_238 ,
L_110 ) ,
F_106 ( 0 , L_111 , & V_2 . V_239 , L_112 ,
L_113 ) ,
F_107 ( 'z' , L_114 , & V_2 . V_48 , L_115 ) ,
F_109 ( 'F' , L_116 , & V_193 -> V_224 , L_117 ) ,
F_108 ( 'E' , L_118 , & V_2 . V_3 ,
L_119 ) ,
F_107 ( 'U' , L_120 , & V_2 . V_72 ,
L_121 ) ,
F_107 ( 0 , L_122 , & V_2 . V_240 , L_123 ) ,
F_107 ( 0 , L_124 , & V_2 . V_241 , L_125 ) ,
F_110 ( 'v' , L_126 , & V_197 ,
L_127 ) ,
F_106 ( 's' , L_128 , & V_242 , L_129 ,
L_130
L_131 ) ,
F_107 ( 'n' , L_132 , & V_157 . V_243 ,
L_133 ) ,
F_111 ( 'G' , NULL , & V_2 . V_130 ,
NULL , L_134 ,
& F_98 ) ,
F_104 ( 0 , L_135 , & V_2 . V_130 ,
L_136 , V_244 ,
& F_100 ) ,
F_108 ( 0 , L_137 , & V_2 . V_170 ,
L_138
L_139 F_112 ( V_229 ) ) ,
F_104 ( 0 , L_140 , NULL , L_141 ,
L_142 ,
V_245 ) ,
F_107 ( 0 , L_143 , & V_157 . V_246 ,
L_144 ) ,
F_106 ( 0 , L_145 , & V_157 . V_247 , L_146 ,
L_147 ) ,
F_106 ( 0 , L_148 , & V_157 . V_248 , L_149 ,
L_150 ) ,
F_106 ( 0 , L_151 , & V_157 . V_249 , L_152 ,
L_153 ) ,
F_107 ( 0 , L_154 , & V_157 . V_250 ,
L_155 ) ,
F_107 ( 0 , L_156 , & V_157 . V_251 ,
L_157 ) ,
F_106 ( 0 , L_158 , & V_205 , L_159 ,
L_160 ) ,
F_106 ( 'M' , L_161 , & V_252 , L_162 ,
L_163 ) ,
F_106 ( 'u' , L_164 , & V_75 -> V_131 , L_165 , L_166 ) ,
F_104 ( 0 , L_167 , & V_2 , L_168 ,
L_169 , F_102 ) ,
F_113 ()
} ;
const char * const V_253 [] = {
L_170 ,
NULL
} ;
V_2 . V_91 = F_114 () ;
if ( V_2 . V_91 == NULL )
return - V_204 ;
V_218 = F_115 ( V_218 , V_219 , V_230 , V_253 , 0 ) ;
if ( V_218 )
F_116 ( V_253 , V_230 ) ;
if ( V_242 == V_254 )
V_242 = L_171 ;
if ( F_117 () < 0 ) {
F_118 ( V_253 , V_230 , L_172 , 1 ) ;
goto V_255;
}
V_256 = 1 ;
if ( V_2 . V_241 )
V_39 = 0 ;
else if ( V_2 . V_240 )
V_39 = 1 ;
F_119 ( false ) ;
V_220 = F_120 ( V_75 ) ;
if ( V_220 ) {
F_121 ( V_75 , V_220 , V_221 , V_222 ) ;
F_17 ( L_21 , V_221 ) ;
}
V_220 = F_122 ( V_75 ) ;
if ( V_220 ) {
int V_257 = V_137 ;
F_121 ( V_75 , V_220 , V_221 , V_222 ) ;
F_83 ( L_21 , V_221 ) ;
V_220 = - V_257 ;
goto V_255;
}
if ( F_93 ( V_75 ) )
V_75 -> V_233 = true ;
if ( F_123 ( V_2 . V_91 , V_75 ) < 0 )
F_116 ( V_253 , V_230 ) ;
if ( ! V_2 . V_91 -> V_92 &&
F_124 ( V_2 . V_91 ) < 0 ) {
F_83 ( L_173 ) ;
goto V_258;
}
V_157 . V_69 = V_2 . V_91 -> V_92 ;
if ( V_2 . V_90 < 1 )
V_2 . V_90 = 1 ;
if ( F_125 ( V_193 ) ) {
V_220 = - V_200 ;
goto V_258;
}
V_2 . V_46 = F_53 ( V_2 . V_91 ) ;
V_157 . V_259 = sizeof( struct V_13 ) ;
V_157 . V_260 = ( V_157 . V_165 == NULL ) ;
if ( F_126 () < 0 )
return - 1 ;
F_127 ( stdout ) ;
F_3 ( & V_2 . V_4 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_112 V_113 = {
. V_114 = F_2 ,
. V_115 = V_116 ,
} ;
F_1 ( & V_2 ) ;
V_112 ( V_117 , & V_113 , NULL ) ;
}
V_220 = F_87 ( & V_2 ) ;
V_258:
F_128 ( V_2 . V_91 ) ;
V_255:
F_129 ( V_2 . V_91 ) ;
return V_220 ;
}
