void F_1 ( struct V_1 * V_2 )
{
char * V_3 = getenv ( L_1 ) ;
if ( V_3 != NULL ) {
V_2 -> V_4 = atoi ( V_3 ) ;
V_3 = getenv ( L_2 ) ;
if ( V_3 != NULL ) {
V_2 -> V_5 = atoi ( V_3 ) ;
if ( V_2 -> V_4 && V_2 -> V_5 )
return;
}
}
#ifdef F_2
if ( F_3 ( 1 , F_2 , V_2 ) == 0 &&
V_2 -> V_4 && V_2 -> V_5 )
return;
#endif
V_2 -> V_4 = 25 ;
V_2 -> V_5 = 80 ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_6 . V_7 = V_2 -> V_4 ;
if ( V_6 . V_7 > 9 )
V_6 . V_7 -= 9 ;
}
static void F_5 ( int T_1 V_8 )
{
F_1 ( & V_1 ) ;
F_4 ( & V_1 ) ;
}
static int F_6 ( struct V_9 * V_10 )
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
F_7 ( L_3
L_4 , V_12 -> V_21 ) ;
F_8 ( 1 ) ;
return - 1 ;
}
V_14 = F_9 ( V_12 ) ;
if ( V_14 -> V_22 != NULL ) {
F_10 ( & V_14 -> V_23 ) ;
goto V_24;
}
F_10 ( & V_14 -> V_23 ) ;
if ( F_11 ( V_12 , V_6 . V_25 -> V_26 ) < 0 ) {
F_12 ( & V_14 -> V_23 ) ;
F_7 ( L_5 ,
V_12 -> V_21 ) ;
F_8 ( 1 ) ;
return V_16 ;
}
V_16 = F_13 ( V_12 , V_15 , 0 ) ;
if ( V_16 == 0 ) {
V_24:
V_6 . V_27 = V_10 ;
}
F_12 ( & V_14 -> V_23 ) ;
return V_16 ;
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_17 . V_12 ;
F_15 ( V_12 ) ;
}
static void F_16 ( struct V_9 * V_10 , int V_28 , T_2 V_29 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
if ( V_10 == NULL || V_10 -> V_17 . V_12 == NULL ||
( ( V_6 . V_27 == NULL ||
V_6 . V_27 -> V_17 . V_12 != V_10 -> V_17 . V_12 ) && V_30 != 1 ) )
return;
V_12 = V_10 -> V_17 . V_12 ;
V_14 = F_9 ( V_12 ) ;
if ( F_17 ( & V_14 -> V_23 ) )
return;
if ( V_14 -> V_22 == NULL &&
F_11 ( V_12 , V_6 . V_25 -> V_26 ) < 0 ) {
F_12 ( & V_14 -> V_23 ) ;
F_7 ( L_5 ,
V_12 -> V_21 ) ;
F_8 ( 1 ) ;
return;
}
V_29 = V_10 -> V_17 . V_15 -> V_31 ( V_10 -> V_17 . V_15 , V_29 ) ;
F_18 ( V_12 , V_10 -> V_17 . V_15 , V_28 , V_29 ) ;
F_12 ( & V_14 -> V_23 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_32 ;
if ( ! V_10 )
return;
V_11 = V_10 -> V_17 . V_12 ;
V_14 = F_9 ( V_11 ) ;
F_10 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == NULL )
goto V_33;
printf ( L_6 , F_20 ( V_6 . V_34 ) , V_11 -> V_21 ) ;
printf ( L_7 , V_35 ) ;
V_32 = F_21 ( V_11 , V_10 -> V_17 . V_15 , V_6 . V_34 -> V_36 ,
0 , V_35 , V_6 . V_7 , 4 ) ;
if ( V_6 . V_37 )
F_22 ( V_11 , V_6 . V_34 -> V_36 ) ;
else
F_23 ( V_11 , V_6 . V_34 -> V_36 ) ;
if ( V_32 != 0 )
printf ( L_8 , V_32 ) ;
V_33:
F_12 ( & V_14 -> V_23 ) ;
}
static struct V_9 *
F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( & V_45 -> V_46 , V_41 , NULL , V_43 -> V_47 ) ;
if ( V_10 == NULL )
return NULL ;
V_39 -> V_46 . V_48 . V_49 += V_43 -> V_47 ;
F_26 ( & V_45 -> V_46 , V_50 ) ;
return V_10 ;
}
static void F_27 ( void )
{
char V_51 [ 160 ] ;
int V_52 = 0 ;
const int V_53 = V_1 . V_5 - 1 ;
puts ( V_54 ) ;
F_28 ( & V_6 , V_51 , sizeof( V_51 ) ) ;
printf ( L_9 , V_51 ) ;
F_29 ( & V_6 ) ;
printf ( L_10 , V_53 , V_53 , V_55 ) ;
if ( V_6 . V_34 -> V_46 . V_48 . V_56 !=
V_6 . V_34 -> V_46 . V_48 . V_57 [ V_58 ] ) {
V_6 . V_34 -> V_46 . V_48 . V_56 =
V_6 . V_34 -> V_46 . V_48 . V_57 [ V_58 ] ;
F_30 ( stdout , V_59 ,
L_11 ,
V_6 . V_34 -> V_46 . V_48 . V_56 ) ;
++ V_52 ;
}
if ( V_6 . V_27 ) {
F_19 ( V_6 . V_27 ) ;
return;
}
F_31 ( & V_6 . V_34 -> V_46 ) ;
F_32 ( & V_6 . V_34 -> V_46 ) ;
F_33 ( & V_6 . V_34 -> V_46 ,
V_6 . V_60 ,
V_6 . V_61 ) ;
F_34 ( & V_6 . V_34 -> V_46 , V_1 . V_4 - 3 ) ;
putchar ( '\n' ) ;
F_35 ( & V_6 . V_34 -> V_46 , NULL , false , false ,
V_1 . V_4 - 4 - V_52 , V_53 , stdout ) ;
}
static void F_36 ( int * V_62 , const char * V_63 )
{
char * V_64 = malloc ( 0 ) , * V_65 ;
T_3 V_66 = 0 ;
int V_67 ;
fprintf ( stdout , L_12 , V_63 ) ;
if ( F_37 ( & V_64 , & V_66 , V_68 ) < 0 )
return;
V_65 = strchr ( V_64 , '\n' ) ;
if ( V_65 )
* V_65 = 0 ;
V_65 = V_64 ;
while( * V_65 ) {
if ( ! isdigit ( * V_65 ) )
goto V_69;
V_65 ++ ;
}
V_67 = strtoul ( V_64 , NULL , 10 ) ;
* V_62 = V_67 ;
V_69:
free ( V_64 ) ;
}
static void F_38 ( int * V_62 , const char * V_63 )
{
int V_67 = 0 ;
F_36 ( & V_67 , V_63 ) ;
if ( V_67 >= 0 && V_67 <= 100 )
* V_62 = V_67 ;
}
static void F_39 ( struct V_9 * * V_62 , const char * V_63 )
{
char * V_64 = malloc ( 0 ) , * V_65 ;
struct V_9 * V_70 = * V_62 , * V_71 , * V_72 = NULL ;
struct V_73 * V_74 ;
T_3 V_66 = 0 ;
if ( V_70 ) {
F_14 ( V_70 ) ;
* V_62 = NULL ;
}
fprintf ( stdout , L_12 , V_63 ) ;
if ( F_37 ( & V_64 , & V_66 , V_68 ) < 0 )
goto V_69;
V_65 = strchr ( V_64 , '\n' ) ;
if ( V_65 )
* V_65 = 0 ;
V_74 = F_40 ( & V_6 . V_34 -> V_46 . V_75 ) ;
while ( V_74 ) {
V_71 = F_41 ( V_74 , struct V_9 , V_73 ) ;
if ( V_71 -> V_17 . V_12 && ! strcmp ( V_64 , V_71 -> V_17 . V_12 -> V_21 ) ) {
V_72 = V_71 ;
break;
}
V_74 = F_42 ( & V_71 -> V_73 ) ;
}
if ( ! V_72 ) {
fprintf ( V_76 , L_13 , V_64 ) ;
F_8 ( 1 ) ;
return;
} else
F_6 ( V_72 ) ;
V_69:
free ( V_64 ) ;
}
static void F_43 ( void )
{
char * V_21 = NULL ;
if ( V_6 . V_27 ) {
struct V_11 * V_12 = V_6 . V_27 -> V_17 . V_12 ;
V_21 = V_12 -> V_21 ;
}
fprintf ( stdout , L_14 ) ;
fprintf ( stdout , L_15 , V_6 . V_77 ) ;
fprintf ( stdout , L_16 , V_6 . V_7 ) ;
if ( V_6 . V_25 -> V_26 > 1 )
fprintf ( stdout , L_17 , F_20 ( V_6 . V_34 ) ) ;
fprintf ( stdout , L_18 , V_6 . V_78 ) ;
fprintf ( stdout , L_19 , V_35 ) ;
fprintf ( stdout , L_20 , V_21 ? : L_21 ) ;
fprintf ( stdout , L_22 ) ;
fprintf ( stdout ,
L_23 ,
V_6 . V_61 ? L_24 : L_25 ) ;
fprintf ( stdout ,
L_26 ,
V_6 . V_60 ? L_24 : L_25 ) ;
fprintf ( stdout , L_27 , V_6 . V_37 ? 1 : 0 ) ;
fprintf ( stdout , L_28 ) ;
}
static int F_44 ( int V_79 )
{
switch ( V_79 ) {
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
return V_6 . V_25 -> V_26 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static void F_45 ( int V_79 )
{
if ( ! F_44 ( V_79 ) ) {
struct V_80 V_81 = { . V_82 = 0 , . V_83 = V_84 } ;
struct V_85 V_86 , V_87 ;
F_43 () ;
fprintf ( stdout , L_29 ) ;
fflush ( stdout ) ;
F_46 ( 0 , & V_87 ) ;
V_86 = V_87 ;
V_86 . V_88 &= ~ ( V_89 | V_90 ) ;
V_86 . V_91 [ V_92 ] = 0 ;
V_86 . V_91 [ V_93 ] = 0 ;
F_47 ( 0 , V_94 , & V_86 ) ;
F_48 ( & V_81 , 1 , - 1 ) ;
V_79 = getc ( V_68 ) ;
F_47 ( 0 , V_95 , & V_87 ) ;
if ( ! F_44 ( V_79 ) )
return;
}
switch ( V_79 ) {
case 'd' :
F_36 ( & V_6 . V_77 , L_30 ) ;
if ( V_6 . V_77 < 1 )
V_6 . V_77 = 1 ;
break;
case 'e' :
F_36 ( & V_6 . V_7 , L_31 ) ;
if ( V_6 . V_7 == 0 ) {
F_5 ( V_96 ) ;
signal ( V_96 , F_5 ) ;
} else
signal ( V_96 , V_97 ) ;
break;
case 'E' :
if ( V_6 . V_25 -> V_26 > 1 ) {
int V_28 = 0 ;
fprintf ( V_76 , L_32 ) ;
F_49 (top.sym_evsel, &top.evlist->entries, node)
fprintf ( V_76 , L_33 , V_6 . V_34 -> V_36 , F_20 ( V_6 . V_34 ) ) ;
F_36 ( & V_28 , L_34 ) ;
if ( V_28 >= V_6 . V_25 -> V_26 ) {
V_6 . V_34 = F_50 ( V_6 . V_25 -> V_75 . V_74 , struct V_44 , V_98 ) ;
fprintf ( V_76 , L_35 , F_20 ( V_6 . V_34 ) ) ;
F_8 ( 1 ) ;
break;
}
F_49 (top.sym_evsel, &top.evlist->entries, node)
if ( V_6 . V_34 -> V_36 == V_28 )
break;
} else
V_6 . V_34 = F_50 ( V_6 . V_25 -> V_75 . V_74 , struct V_44 , V_98 ) ;
break;
case 'f' :
F_36 ( & V_6 . V_78 , L_36 ) ;
break;
case 'F' :
F_38 ( & V_35 , L_37 ) ;
break;
case 'K' :
V_6 . V_61 = ! V_6 . V_61 ;
break;
case 'q' :
case 'Q' :
printf ( L_38 ) ;
if ( V_99 )
F_51 ( V_6 . V_39 , V_76 ) ;
exit ( 0 ) ;
case 's' :
F_39 ( & V_6 . V_27 , L_39 ) ;
break;
case 'S' :
if ( ! V_6 . V_27 )
break;
else {
struct V_9 * V_70 = V_6 . V_27 ;
V_6 . V_27 = NULL ;
F_14 ( V_70 ) ;
}
break;
case 'U' :
V_6 . V_60 = ! V_6 . V_60 ;
break;
case 'z' :
V_6 . V_37 = ! V_6 . V_37 ;
break;
default:
break;
}
}
static void F_52 ( void * V_100 )
{
struct V_101 * V_102 = V_100 ;
F_29 ( V_102 ) ;
if ( V_102 -> V_25 -> V_103 != NULL )
V_102 -> V_34 = V_102 -> V_25 -> V_103 ;
F_31 ( & V_102 -> V_34 -> V_46 ) ;
F_32 ( & V_102 -> V_34 -> V_46 ) ;
F_33 ( & V_102 -> V_34 -> V_46 ,
V_6 . V_60 ,
V_6 . V_61 ) ;
}
static void * F_53 ( void * V_100 V_8 )
{
const char * V_104 = L_40 ;
F_52 ( & V_6 ) ;
F_54 ( V_6 . V_25 , V_104 ,
F_52 ,
& V_6 , V_6 . V_77 ) ;
F_55 ( 0 ) ;
exit ( 0 ) ;
return NULL ;
}
static void * F_56 ( void * V_100 V_8 )
{
struct V_80 V_81 = { . V_82 = 0 , . V_83 = V_84 } ;
struct V_85 V_86 , V_87 ;
int V_105 , V_79 ;
F_46 ( 0 , & V_87 ) ;
V_86 = V_87 ;
V_86 . V_88 &= ~ ( V_89 | V_90 ) ;
V_86 . V_91 [ V_92 ] = 0 ;
V_86 . V_91 [ V_93 ] = 0 ;
F_57 () ;
V_106:
V_105 = V_6 . V_77 * 1000 ;
F_47 ( 0 , V_94 , & V_86 ) ;
getc ( V_68 ) ;
while ( 1 ) {
F_27 () ;
switch ( F_48 ( & V_81 , 1 , V_105 ) ) {
case 0 :
continue;
case - 1 :
if ( V_107 == V_108 )
continue;
default:
goto V_109;
}
}
V_109:
V_79 = getc ( V_68 ) ;
F_47 ( 0 , V_95 , & V_87 ) ;
F_45 ( V_79 ) ;
goto V_106;
return NULL ;
}
static int F_58 ( struct V_15 * V_15 V_8 , struct V_11 * V_12 )
{
const char * V_21 = V_12 -> V_21 ;
int V_110 ;
if ( V_21 [ 0 ] == '.' )
V_21 ++ ;
if ( ! strcmp ( V_21 , L_41 ) ||
! strcmp ( V_21 , L_42 ) ||
! strcmp ( V_21 , L_43 ) ||
! strncmp ( L_44 , V_21 , 11 ) ||
! strncmp ( L_45 , V_21 , 14 ) ||
strstr ( V_21 , L_46 ) ||
strstr ( V_21 , L_47 ) )
return 1 ;
for ( V_110 = 0 ; V_111 [ V_110 ] ; V_110 ++ ) {
if ( ! strcmp ( V_111 [ V_110 ] , V_21 ) ) {
V_12 -> V_112 = true ;
break;
}
}
return 0 ;
}
static void F_59 ( const union V_113 * V_114 ,
struct V_44 * V_45 ,
struct V_42 * V_43 ,
struct V_38 * V_39 )
{
struct V_11 * V_115 = NULL ;
T_2 V_29 = V_114 -> V_29 . V_29 ;
struct V_40 V_41 ;
struct V_116 * V_116 ;
int V_16 ;
T_4 V_117 = V_114 -> V_118 . V_119 & V_120 ;
++ V_6 . V_121 ;
switch ( V_117 ) {
case V_122 :
++ V_6 . V_123 ;
if ( V_6 . V_60 )
return;
V_116 = F_60 ( V_39 ) ;
break;
case V_124 :
++ V_6 . V_125 ;
if ( V_6 . V_61 )
return;
V_116 = F_60 ( V_39 ) ;
break;
case V_126 :
++ V_6 . V_127 ;
V_116 = F_61 ( V_39 , V_114 -> V_29 . V_128 ) ;
break;
case V_129 :
++ V_6 . V_130 ;
return;
default:
return;
}
if ( ! V_116 && V_131 ) {
F_7 ( L_48 ,
V_114 -> V_29 . V_128 ) ;
return;
}
if ( V_114 -> V_118 . V_119 & V_132 )
V_6 . V_133 ++ ;
if ( F_62 ( V_114 , V_39 , & V_41 , V_43 ,
F_58 ) < 0 ||
V_41 . V_134 )
return;
if ( ! V_135 &&
V_136 . V_137 &&
V_41 . V_138 == V_124 ) {
F_63 (
L_49
L_50
L_51 ,
! F_64 ( & V_41 . V_15 -> V_18 -> V_139 [ V_140 ] ) ?
L_52 : L_53 ) ;
if ( V_30 <= 0 )
F_8 ( 5 ) ;
V_135 = true ;
}
if ( V_41 . V_12 == NULL ) {
const char * V_63 = L_54 ;
if ( ! V_135 && ! V_141 &&
V_41 . V_15 == V_116 -> V_142 [ V_140 ] &&
F_64 ( & V_41 . V_15 -> V_18 -> V_139 [ V_140 ] ) ) {
if ( V_136 . V_143 ) {
F_63 ( L_55 ,
V_136 . V_143 , V_63 ) ;
} else {
F_63 ( L_56 ,
V_63 ) ;
}
if ( V_30 <= 0 )
F_8 ( 5 ) ;
V_141 = true ;
}
}
if ( V_41 . V_12 == NULL || ! V_41 . V_12 -> V_112 ) {
struct V_9 * V_10 ;
if ( ( V_144 || V_136 . V_145 ) &&
V_43 -> V_146 ) {
V_16 = F_65 ( V_39 , V_41 . V_147 ,
V_43 -> V_146 , & V_115 ) ;
if ( V_16 )
return;
}
V_10 = F_24 ( V_39 , & V_41 , V_43 , V_45 ) ;
if ( V_10 == NULL ) {
F_7 ( L_57 ) ;
return;
}
if ( V_136 . V_145 ) {
V_16 = F_66 ( V_10 -> V_146 , & V_39 -> V_148 ,
V_43 -> V_47 ) ;
if ( V_16 )
return;
}
if ( V_149 )
F_16 ( V_10 , V_45 -> V_36 , V_29 ) ;
}
return;
}
static void F_67 ( struct V_38 * V_150 , int V_36 )
{
struct V_42 V_43 ;
struct V_44 * V_45 ;
union V_113 * V_114 ;
int V_151 ;
while ( ( V_114 = F_68 ( V_6 . V_25 , V_36 ) ) != NULL ) {
V_151 = F_69 ( V_150 , V_114 , & V_43 ) ;
if ( V_151 ) {
F_7 ( L_58 , V_151 ) ;
continue;
}
V_45 = F_70 ( V_150 -> V_25 , V_43 . V_152 ) ;
assert ( V_45 != NULL ) ;
if ( V_114 -> V_118 . type == V_50 )
F_59 ( V_114 , V_45 , & V_43 , V_150 ) ;
else if ( V_114 -> V_118 . type < V_153 ) {
F_26 ( & V_45 -> V_46 , V_114 -> V_118 . type ) ;
F_71 ( V_114 , & V_43 , V_150 ) ;
} else
++ V_150 -> V_46 . V_48 . V_154 ;
}
}
static void F_72 ( struct V_38 * V_150 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_6 . V_25 -> V_155 ; V_110 ++ )
F_67 ( V_150 , V_110 ) ;
}
static void F_73 ( struct V_156 * V_25 )
{
struct V_44 * V_28 , * V_157 ;
V_157 = F_50 ( V_25 -> V_75 . V_74 , struct V_44 , V_98 ) ;
F_49 (counter, &evlist->entries, node) {
struct V_158 * V_159 = & V_28 -> V_159 ;
struct V_160 * V_161 = NULL ;
if ( V_162 && V_28 != V_157 )
V_161 = V_157 -> V_82 ;
V_159 -> V_163 = V_164 | V_165 ;
if ( V_6 . V_166 ) {
V_159 -> V_163 |= V_167 ;
V_159 -> V_166 = 1 ;
V_159 -> V_168 = V_6 . V_166 ;
}
if ( V_25 -> V_26 > 1 ) {
V_159 -> V_163 |= V_169 ;
V_159 -> V_170 |= V_171 ;
}
if ( V_136 . V_145 )
V_159 -> V_163 |= V_172 ;
V_159 -> V_173 = 1 ;
V_159 -> V_174 = 1 ;
V_159 -> V_175 = V_175 ;
V_176:
V_159 -> V_177 = V_178 ? 1 : 0 ;
V_179:
if ( F_74 ( V_28 , V_6 . V_25 -> V_180 ,
V_6 . V_25 -> V_181 , V_162 ,
V_161 ) < 0 ) {
int V_16 = V_107 ;
if ( V_16 == V_182 || V_16 == V_183 ) {
F_75 () ;
goto V_184;
} else if ( V_16 == V_185 && V_178 ) {
V_178 = false ;
goto V_176;
}
if ( V_159 -> type == V_186 &&
V_159 -> V_187 == V_188 ) {
if ( V_189 )
F_63 ( L_59
L_60 ) ;
V_159 -> type = V_190 ;
V_159 -> V_187 = V_191 ;
goto V_179;
}
if ( V_16 == V_192 ) {
F_63 ( L_61 ,
F_20 ( V_28 ) ) ;
goto V_184;
}
F_63 ( L_62
L_63
L_64
L_65
L_66 , V_16 , strerror ( V_16 ) ) ;
goto V_184;
}
}
if ( F_76 ( V_25 , V_193 , false ) < 0 ) {
F_63 ( L_67 ,
V_107 , strerror ( V_107 ) ) ;
goto V_184;
}
return;
V_184:
F_55 ( 0 ) ;
exit ( 0 ) ;
}
static int F_77 ( void )
{
if ( ! V_149 ) {
if ( V_136 . V_145 ) {
F_63 ( L_68 ) ;
return - V_185 ;
}
} else if ( ! V_194 && V_195 . V_196 != V_197 ) {
if ( F_78 ( & V_195 ) < 0 ) {
F_63 ( L_69 ) ;
return - V_185 ;
}
}
return 0 ;
}
static int F_79 ( void )
{
T_5 V_147 ;
int V_151 ;
V_6 . V_39 = F_80 ( NULL , V_198 , false , false , NULL ) ;
if ( V_6 . V_39 == NULL )
return - V_199 ;
V_151 = F_77 () ;
if ( V_151 )
goto V_200;
if ( V_6 . V_201 != - 1 )
F_81 ( V_6 . V_25 -> V_181 ,
F_71 , V_6 . V_39 ) ;
else
F_82 ( F_71 , V_6 . V_39 ) ;
F_73 ( V_6 . V_25 ) ;
V_6 . V_39 -> V_25 = V_6 . V_25 ;
F_83 ( V_6 . V_39 ) ;
F_48 ( V_6 . V_25 -> V_80 , V_6 . V_25 -> V_202 , 100 ) ;
F_72 ( V_6 . V_39 ) ;
if ( F_84 ( & V_147 , NULL , ( V_30 > 0 ? F_53 :
F_56 ) , NULL ) ) {
printf ( L_70 ) ;
exit ( - 1 ) ;
}
if ( V_203 ) {
struct V_204 V_205 ;
V_205 . V_206 = V_203 ;
if ( F_85 ( 0 , V_207 , & V_205 ) ) {
printf ( L_71 ) ;
exit ( - 1 ) ;
}
}
while ( 1 ) {
T_2 V_208 = V_6 . V_121 ;
F_72 ( V_6 . V_39 ) ;
if ( V_208 == V_6 . V_121 )
V_151 = F_48 ( V_6 . V_25 -> V_80 , V_6 . V_25 -> V_202 , 100 ) ;
}
V_200:
F_86 ( V_6 . V_39 ) ;
V_6 . V_39 = NULL ;
return 0 ;
}
static int
F_87 ( const struct V_209 * T_6 V_8 , const char * V_100 ,
int V_210 )
{
char * V_211 , * V_212 ;
char * V_213 ;
if ( V_210 ) {
V_194 = true ;
return 0 ;
}
V_136 . V_145 = true ;
if ( ! V_100 )
return 0 ;
V_211 = strtok ( ( char * ) V_100 , L_72 ) ;
if ( ! V_211 )
return - 1 ;
if ( ! strncmp ( V_211 , L_73 , strlen ( V_100 ) ) )
V_195 . V_196 = V_214 ;
else if ( ! strncmp ( V_211 , L_74 , strlen ( V_100 ) ) )
V_195 . V_196 = V_215 ;
else if ( ! strncmp ( V_211 , L_75 , strlen ( V_100 ) ) )
V_195 . V_196 = V_216 ;
else if ( ! strncmp ( V_211 , L_76 , strlen ( V_100 ) ) ) {
V_195 . V_196 = V_197 ;
V_136 . V_145 = false ;
return 0 ;
}
else
return - 1 ;
V_211 = strtok ( NULL , L_72 ) ;
if ( ! V_211 )
goto V_217;
V_195 . V_218 = strtod ( V_211 , & V_213 ) ;
if ( V_211 == V_213 )
return - 1 ;
V_212 = strtok ( NULL , L_72 ) ;
if ( ! V_212 )
goto V_217;
if ( V_212 [ 0 ] != 'c' ) {
V_195 . V_219 = strtod ( V_212 , & V_213 ) ;
V_212 = strtok ( NULL , L_72 ) ;
if ( ! V_212 )
goto V_217;
}
if ( ! strcmp ( V_212 , L_77 ) )
V_195 . V_220 = V_221 ;
else if ( ! strcmp ( V_212 , L_78 ) )
V_195 . V_220 = V_222 ;
else
return - 1 ;
V_217:
if ( F_78 ( & V_195 ) < 0 ) {
fprintf ( V_76 , L_79 ) ;
return - 1 ;
}
return 0 ;
}
int F_88 ( int V_223 , const char * * V_224 , const char * T_7 V_8 )
{
struct V_44 * V_225 ;
int V_226 = - V_199 ;
V_6 . V_25 = F_89 ( NULL , NULL ) ;
if ( V_6 . V_25 == NULL )
return - V_199 ;
V_136 . V_227 = false ;
V_223 = F_90 ( V_223 , V_224 , V_228 , V_229 , 0 ) ;
if ( V_223 )
F_91 ( V_229 , V_228 ) ;
if ( V_230 == V_231 )
V_230 = L_80 ;
F_92 ( V_229 , V_228 ) ;
if ( V_232 )
V_30 = 0 ;
else if ( V_233 )
V_30 = 1 ;
F_93 ( false ) ;
if ( V_6 . V_201 > 0 && V_6 . V_234 ) {
printf ( L_81 ) ;
F_8 ( 1 ) ;
V_6 . V_234 = NULL ;
}
if ( V_6 . V_235 != - 1 )
V_6 . V_201 = V_6 . V_235 ;
if ( F_94 ( V_6 . V_25 , V_6 . V_235 ,
V_6 . V_201 , V_6 . V_234 ) < 0 )
F_91 ( V_229 , V_228 ) ;
if ( ! V_6 . V_25 -> V_26 &&
F_95 ( V_6 . V_25 ) < 0 ) {
F_7 ( L_82 ) ;
return - V_199 ;
}
if ( V_6 . V_77 < 1 )
V_6 . V_77 = 1 ;
if ( V_236 )
V_6 . V_166 = 0 ;
else if ( V_6 . V_166 ) {
V_236 = V_6 . V_166 ;
} else {
fprintf ( V_76 , L_83 ) ;
exit ( V_237 ) ;
}
F_49 (pos, &top.evlist->entries, node) {
if ( F_96 ( V_225 , V_6 . V_25 -> V_180 -> V_238 ,
V_6 . V_25 -> V_181 -> V_238 ) < 0 )
goto V_239;
if ( V_225 -> V_159 . V_240 )
continue;
V_225 -> V_159 . V_240 = V_236 ;
}
if ( F_97 ( V_6 . V_25 ) < 0 ||
F_98 ( V_6 . V_25 ) < 0 )
goto V_239;
V_6 . V_34 = F_50 ( V_6 . V_25 -> V_75 . V_74 , struct V_44 , V_98 ) ;
V_136 . V_241 = sizeof( struct V_13 ) ;
V_136 . V_242 = ( V_136 . V_143 == NULL ) ;
if ( F_99 () < 0 )
return - 1 ;
F_100 ( & V_243 , V_136 . V_244 , L_84 , stdout ) ;
F_100 ( & V_245 , V_136 . V_246 , L_85 , stdout ) ;
F_100 ( & V_247 , V_136 . V_248 , L_86 , stdout ) ;
V_149 = V_247 . V_249 . V_74 != NULL ;
F_1 ( & V_1 ) ;
if ( V_6 . V_7 == 0 ) {
F_4 ( & V_1 ) ;
signal ( V_96 , F_5 ) ;
}
V_226 = F_79 () ;
V_239:
F_101 ( V_6 . V_25 ) ;
return V_226 ;
}
