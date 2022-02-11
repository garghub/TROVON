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
static void F_4 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 > 9 )
V_7 -> V_8 -= 9 ;
}
static void F_5 ( int T_1 V_9 , T_2 * T_3 V_9 , void * V_10 )
{
struct V_6 * V_7 = V_10 ;
F_1 ( & V_7 -> V_1 ) ;
if ( ! V_7 -> V_8
|| ( V_7 -> V_8 + 4 ) > V_7 -> V_1 . V_4 ) {
V_7 -> V_8 = V_7 -> V_1 . V_4 ;
} else {
V_7 -> V_8 += 4 ;
V_7 -> V_1 . V_4 = V_7 -> V_8 ;
}
F_4 ( V_7 ) ;
}
static int F_6 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_17 ;
int V_18 = - 1 ;
if ( ! V_12 || ! V_12 -> V_19 . V_14 )
return - 1 ;
V_14 = V_12 -> V_19 . V_14 ;
V_17 = V_12 -> V_19 . V_17 ;
if ( V_17 -> V_20 -> V_21 == V_22 ) {
F_7 ( L_3
L_4 , V_14 -> V_23 ) ;
F_8 ( 1 ) ;
return - 1 ;
}
V_16 = F_9 ( V_14 ) ;
if ( V_16 -> V_24 != NULL ) {
F_10 ( & V_16 -> V_25 ) ;
goto V_26;
}
F_10 ( & V_16 -> V_25 ) ;
if ( F_11 ( V_14 ) < 0 ) {
F_12 ( & V_16 -> V_25 ) ;
F_7 ( L_5 ,
V_14 -> V_23 ) ;
F_8 ( 1 ) ;
return V_18 ;
}
V_18 = F_13 ( V_14 , V_17 , 0 ) ;
if ( V_18 == 0 ) {
V_26:
V_7 -> V_27 = V_12 ;
}
F_12 ( & V_16 -> V_25 ) ;
return V_18 ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_19 . V_14 ;
F_15 ( V_14 ) ;
}
static void F_16 ( struct V_17 * V_17 , struct V_13 * V_14 , T_4 V_28 )
{
struct V_29 V_30 ;
int V_18 = F_17 ( & V_30 ) ;
F_18 ( L_6
L_7 V_31 L_8
L_9
L_10 V_31 L_11 V_31 L_8
L_12 V_31 L_11 V_31 L_13
L_14
L_15
L_16
L_17
L_18 ,
V_28 , V_17 -> V_20 -> V_32 , F_19 ( V_17 -> V_20 ) ,
V_17 -> V_33 , V_17 -> V_34 , V_14 -> V_33 , V_14 -> V_34 ,
V_14 -> V_35 == V_36 ? 'g' :
V_14 -> V_35 == V_37 ? 'l' : 'w' , V_14 -> V_23 ,
V_18 ? L_19 : V_30 . V_38 ,
V_18 ? L_19 : V_30 . V_39 , V_40 ) ;
if ( V_41 <= 0 )
F_8 ( 5 ) ;
V_17 -> V_42 = true ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
int V_43 , T_4 V_28 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_18 ;
if ( V_12 == NULL || V_12 -> V_19 . V_14 == NULL ||
( ( V_7 -> V_27 == NULL ||
V_7 -> V_27 -> V_19 . V_14 != V_12 -> V_19 . V_14 ) && V_41 != 1 ) )
return;
V_14 = V_12 -> V_19 . V_14 ;
V_16 = F_9 ( V_14 ) ;
if ( F_21 ( & V_16 -> V_25 ) )
return;
if ( V_16 -> V_24 == NULL && F_11 ( V_14 ) < 0 ) {
F_12 ( & V_16 -> V_25 ) ;
F_7 ( L_5 ,
V_14 -> V_23 ) ;
F_8 ( 1 ) ;
return;
}
V_28 = V_12 -> V_19 . V_17 -> V_44 ( V_12 -> V_19 . V_17 , V_28 ) ;
V_18 = F_22 ( V_14 , V_12 -> V_19 . V_17 , V_43 , V_28 ) ;
F_12 ( & V_16 -> V_25 ) ;
if ( V_18 == - V_45 && ! V_12 -> V_19 . V_17 -> V_42 )
F_16 ( V_12 -> V_19 . V_17 , V_14 , V_28 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_27 ;
struct V_15 * V_16 ;
struct V_13 * V_13 ;
int V_46 ;
if ( ! V_12 )
return;
V_13 = V_12 -> V_19 . V_14 ;
V_16 = F_9 ( V_13 ) ;
F_10 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_24 == NULL )
goto V_47;
printf ( L_20 , F_24 ( V_7 -> V_48 ) , V_13 -> V_23 ) ;
printf ( L_21 , V_7 -> V_49 ) ;
V_46 = F_25 ( V_13 , V_12 -> V_19 . V_17 , V_7 -> V_48 -> V_50 ,
0 , V_7 -> V_49 , V_7 -> V_8 , 4 ) ;
if ( V_7 -> V_51 )
F_26 ( V_13 , V_7 -> V_48 -> V_50 ) ;
else
F_27 ( V_13 , V_7 -> V_48 -> V_50 ) ;
if ( V_46 != 0 )
printf ( L_22 , V_46 ) ;
V_47:
F_12 ( & V_16 -> V_25 ) ;
}
static struct V_11 * F_28 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_11 * V_12 ;
V_12 = F_29 ( & V_53 -> V_58 , V_55 , NULL , V_57 -> V_59 ) ;
if ( V_12 == NULL )
return NULL ;
F_30 ( & V_53 -> V_58 , V_60 ) ;
return V_12 ;
}
static void F_31 ( struct V_6 * V_7 )
{
char V_61 [ 160 ] ;
int V_62 = 0 ;
const int V_63 = V_7 -> V_1 . V_5 - 1 ;
puts ( V_64 ) ;
F_32 ( V_7 , V_61 , sizeof( V_61 ) ) ;
printf ( L_23 , V_61 ) ;
F_33 ( V_7 ) ;
printf ( L_24 , V_63 , V_63 , V_65 ) ;
if ( V_7 -> V_48 -> V_58 . V_66 . V_67 !=
V_7 -> V_48 -> V_58 . V_66 . V_68 [ V_69 ] ) {
V_7 -> V_48 -> V_58 . V_66 . V_67 =
V_7 -> V_48 -> V_58 . V_66 . V_68 [ V_69 ] ;
F_34 ( stdout , V_70 ,
L_25 ,
V_7 -> V_48 -> V_58 . V_66 . V_67 ) ;
++ V_62 ;
}
if ( V_7 -> V_27 ) {
F_23 ( V_7 ) ;
return;
}
F_35 ( & V_7 -> V_48 -> V_58 ) ;
F_36 ( & V_7 -> V_48 -> V_58 ) ;
F_37 ( & V_7 -> V_48 -> V_58 ,
V_7 -> V_71 ,
V_7 -> V_72 ) ;
F_38 ( & V_7 -> V_48 -> V_58 ,
V_7 -> V_1 . V_4 - 3 ) ;
putchar ( '\n' ) ;
F_39 ( & V_7 -> V_48 -> V_58 , NULL , false , false ,
V_7 -> V_1 . V_4 - 4 - V_62 , V_63 , stdout ) ;
}
static void F_40 ( int * V_73 , const char * V_74 )
{
char * V_75 = malloc ( 0 ) , * V_76 ;
T_5 V_77 = 0 ;
int V_78 ;
fprintf ( stdout , L_26 , V_74 ) ;
if ( F_41 ( & V_75 , & V_77 , V_79 ) < 0 )
return;
V_76 = strchr ( V_75 , '\n' ) ;
if ( V_76 )
* V_76 = 0 ;
V_76 = V_75 ;
while( * V_76 ) {
if ( ! isdigit ( * V_76 ) )
goto V_80;
V_76 ++ ;
}
V_78 = strtoul ( V_75 , NULL , 10 ) ;
* V_73 = V_78 ;
V_80:
free ( V_75 ) ;
}
static void F_42 ( int * V_73 , const char * V_74 )
{
int V_78 = 0 ;
F_40 ( & V_78 , V_74 ) ;
if ( V_78 >= 0 && V_78 <= 100 )
* V_73 = V_78 ;
}
static void F_43 ( struct V_6 * V_7 , const char * V_74 )
{
char * V_75 = malloc ( 0 ) , * V_76 ;
struct V_11 * V_81 = V_7 -> V_27 , * V_82 , * V_83 = NULL ;
struct V_84 * V_85 ;
T_5 V_77 = 0 ;
if ( V_81 ) {
F_14 ( V_81 ) ;
V_7 -> V_27 = NULL ;
}
fprintf ( stdout , L_26 , V_74 ) ;
if ( F_41 ( & V_75 , & V_77 , V_79 ) < 0 )
goto V_80;
V_76 = strchr ( V_75 , '\n' ) ;
if ( V_76 )
* V_76 = 0 ;
V_85 = F_44 ( & V_7 -> V_48 -> V_58 . V_86 ) ;
while ( V_85 ) {
V_82 = F_45 ( V_85 , struct V_11 , V_84 ) ;
if ( V_82 -> V_19 . V_14 && ! strcmp ( V_75 , V_82 -> V_19 . V_14 -> V_23 ) ) {
V_83 = V_82 ;
break;
}
V_85 = F_46 ( & V_82 -> V_84 ) ;
}
if ( ! V_83 ) {
fprintf ( V_87 , L_27 , V_75 ) ;
F_8 ( 1 ) ;
} else
F_6 ( V_7 , V_83 ) ;
V_80:
free ( V_75 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
char * V_23 = NULL ;
if ( V_7 -> V_27 ) {
struct V_13 * V_14 = V_7 -> V_27 -> V_19 . V_14 ;
V_23 = V_14 -> V_23 ;
}
fprintf ( stdout , L_28 ) ;
fprintf ( stdout , L_29 , V_7 -> V_88 ) ;
fprintf ( stdout , L_30 , V_7 -> V_8 ) ;
if ( V_7 -> V_89 -> V_90 > 1 )
fprintf ( stdout , L_31 , F_24 ( V_7 -> V_48 ) ) ;
fprintf ( stdout , L_32 , V_7 -> V_91 ) ;
fprintf ( stdout , L_33 , V_7 -> V_49 ) ;
fprintf ( stdout , L_34 , V_23 ? : L_35 ) ;
fprintf ( stdout , L_36 ) ;
fprintf ( stdout ,
L_37 ,
V_7 -> V_72 ? L_38 : L_39 ) ;
fprintf ( stdout ,
L_40 ,
V_7 -> V_71 ? L_38 : L_39 ) ;
fprintf ( stdout , L_41 , V_7 -> V_51 ? 1 : 0 ) ;
fprintf ( stdout , L_42 ) ;
}
static int F_48 ( struct V_6 * V_7 , int V_92 )
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
return V_7 -> V_89 -> V_90 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static void F_49 ( struct V_6 * V_7 , int V_92 )
{
if ( ! F_48 ( V_7 , V_92 ) ) {
struct V_93 V_94 = { . V_95 = 0 , . V_96 = V_97 } ;
struct V_98 V_99 , V_100 ;
F_47 ( V_7 ) ;
fprintf ( stdout , L_43 ) ;
fflush ( stdout ) ;
F_50 ( 0 , & V_100 ) ;
V_99 = V_100 ;
V_99 . V_101 &= ~ ( V_102 | V_103 ) ;
V_99 . V_104 [ V_105 ] = 0 ;
V_99 . V_104 [ V_106 ] = 0 ;
F_51 ( 0 , V_107 , & V_99 ) ;
F_52 ( & V_94 , 1 , - 1 ) ;
V_92 = getc ( V_79 ) ;
F_51 ( 0 , V_108 , & V_100 ) ;
if ( ! F_48 ( V_7 , V_92 ) )
return;
}
switch ( V_92 ) {
case 'd' :
F_40 ( & V_7 -> V_88 , L_44 ) ;
if ( V_7 -> V_88 < 1 )
V_7 -> V_88 = 1 ;
break;
case 'e' :
F_40 ( & V_7 -> V_8 , L_45 ) ;
if ( V_7 -> V_8 == 0 ) {
struct V_109 V_110 = {
. V_111 = F_5 ,
. V_112 = V_113 ,
} ;
F_5 ( V_114 , NULL , V_7 ) ;
V_109 ( V_114 , & V_110 , NULL ) ;
} else {
F_5 ( V_114 , NULL , V_7 ) ;
signal ( V_114 , V_115 ) ;
}
break;
case 'E' :
if ( V_7 -> V_89 -> V_90 > 1 ) {
int V_43 = 0 ;
fprintf ( V_87 , L_46 ) ;
F_53 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_87 , L_47 , V_7 -> V_48 -> V_50 , F_24 ( V_7 -> V_48 ) ) ;
F_40 ( & V_43 , L_48 ) ;
if ( V_43 >= V_7 -> V_89 -> V_90 ) {
V_7 -> V_48 = F_54 ( V_7 -> V_89 -> V_86 . V_85 , struct V_52 , V_116 ) ;
fprintf ( V_87 , L_49 , F_24 ( V_7 -> V_48 ) ) ;
F_8 ( 1 ) ;
break;
}
F_53 (top->sym_evsel, &top->evlist->entries, node)
if ( V_7 -> V_48 -> V_50 == V_43 )
break;
} else
V_7 -> V_48 = F_54 ( V_7 -> V_89 -> V_86 . V_85 , struct V_52 , V_116 ) ;
break;
case 'f' :
F_40 ( & V_7 -> V_91 , L_50 ) ;
break;
case 'F' :
F_42 ( & V_7 -> V_49 ,
L_51 ) ;
break;
case 'K' :
V_7 -> V_72 = ! V_7 -> V_72 ;
break;
case 'q' :
case 'Q' :
printf ( L_52 ) ;
if ( V_7 -> V_117 )
F_55 ( V_7 -> V_118 , V_87 ) ;
exit ( 0 ) ;
case 's' :
F_43 ( V_7 , L_53 ) ;
break;
case 'S' :
if ( ! V_7 -> V_27 )
break;
else {
struct V_11 * V_81 = V_7 -> V_27 ;
V_7 -> V_27 = NULL ;
F_14 ( V_81 ) ;
}
break;
case 'U' :
V_7 -> V_71 = ! V_7 -> V_71 ;
break;
case 'z' :
V_7 -> V_51 = ! V_7 -> V_51 ;
break;
default:
break;
}
}
static void F_56 ( void * V_10 )
{
struct V_6 * V_119 = V_10 ;
F_33 ( V_119 ) ;
if ( V_119 -> V_89 -> V_120 != NULL )
V_119 -> V_48 = V_119 -> V_89 -> V_120 ;
F_35 ( & V_119 -> V_48 -> V_58 ) ;
F_36 ( & V_119 -> V_48 -> V_58 ) ;
F_37 ( & V_119 -> V_48 -> V_58 ,
V_119 -> V_71 ,
V_119 -> V_72 ) ;
}
static void * F_57 ( void * V_10 )
{
struct V_52 * V_121 ;
struct V_6 * V_7 = V_10 ;
const char * V_122 = L_54 ;
F_56 ( V_7 ) ;
F_53 (pos, &top->evlist->entries, node)
V_121 -> V_58 . V_123 = V_7 -> V_73 . V_124 ;
F_58 ( V_7 -> V_89 , V_122 ,
F_56 ,
V_7 , V_7 -> V_88 ) ;
F_59 ( 0 ) ;
exit ( 0 ) ;
return NULL ;
}
static void * F_60 ( void * V_10 )
{
struct V_93 V_94 = { . V_95 = 0 , . V_96 = V_97 } ;
struct V_98 V_99 , V_100 ;
struct V_6 * V_7 = V_10 ;
int V_125 , V_92 ;
F_50 ( 0 , & V_100 ) ;
V_99 = V_100 ;
V_99 . V_101 &= ~ ( V_102 | V_103 ) ;
V_99 . V_104 [ V_105 ] = 0 ;
V_99 . V_104 [ V_106 ] = 0 ;
F_61 () ;
V_126:
V_125 = V_7 -> V_88 * 1000 ;
F_51 ( 0 , V_107 , & V_99 ) ;
getc ( V_79 ) ;
while ( 1 ) {
F_31 ( V_7 ) ;
switch ( F_52 ( & V_94 , 1 , V_125 ) ) {
case 0 :
continue;
case - 1 :
if ( V_127 == V_128 )
continue;
default:
goto V_129;
}
}
V_129:
V_92 = getc ( V_79 ) ;
F_51 ( 0 , V_108 , & V_100 ) ;
F_49 ( V_7 , V_92 ) ;
goto V_126;
return NULL ;
}
static int F_62 ( struct V_17 * V_17 V_9 , struct V_13 * V_14 )
{
const char * V_23 = V_14 -> V_23 ;
int V_130 ;
if ( V_23 [ 0 ] == '.' )
V_23 ++ ;
if ( ! strcmp ( V_23 , L_55 ) ||
! strcmp ( V_23 , L_56 ) ||
! strcmp ( V_23 , L_57 ) ||
! strncmp ( L_58 , V_23 , 11 ) ||
! strncmp ( L_59 , V_23 , 14 ) ||
strstr ( V_23 , L_60 ) ||
strstr ( V_23 , L_61 ) )
return 1 ;
for ( V_130 = 0 ; V_131 [ V_130 ] ; V_130 ++ ) {
if ( ! strcmp ( V_131 [ V_130 ] , V_23 ) ) {
V_14 -> V_132 = true ;
break;
}
}
return 0 ;
}
static void F_63 ( struct V_133 * V_134 ,
const union V_135 * V_136 ,
struct V_52 * V_53 ,
struct V_56 * V_57 ,
struct V_38 * V_38 )
{
struct V_6 * V_7 = F_64 ( V_134 , struct V_6 , V_134 ) ;
struct V_13 * V_137 = NULL ;
T_4 V_28 = V_136 -> V_28 . V_28 ;
struct V_54 V_55 ;
int V_18 ;
if ( ! V_38 && V_138 ) {
F_7 ( L_62 ,
V_136 -> V_28 . V_139 ) ;
return;
}
if ( ! V_38 ) {
F_7 ( L_63 ,
V_7 -> V_118 -> V_58 . V_66 . V_140 ++ ) ;
return;
}
if ( V_136 -> V_141 . V_142 & V_143 )
V_7 -> V_144 ++ ;
if ( F_65 ( V_136 , V_38 , & V_55 , V_57 ,
F_62 ) < 0 ||
V_55 . V_145 )
return;
if ( ! V_7 -> V_146 &&
V_147 . V_148 &&
V_55 . V_149 == V_150 ) {
F_18 (
L_64
L_65
L_66 ,
! F_66 ( & V_55 . V_17 -> V_20 -> V_151 [ V_152 ] ) ?
L_67 : L_68 ) ;
if ( V_41 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_146 = true ;
}
if ( V_55 . V_14 == NULL ) {
const char * V_74 = L_69 ;
if ( ! V_7 -> V_146 && ! V_7 -> V_153 &&
V_55 . V_17 == V_38 -> V_154 [ V_152 ] &&
F_66 ( & V_55 . V_17 -> V_20 -> V_151 [ V_152 ] ) ) {
if ( V_147 . V_155 ) {
F_18 ( L_70 ,
V_147 . V_155 , V_74 ) ;
} else {
F_18 ( L_71 ,
V_74 ) ;
}
if ( V_41 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_153 = true ;
}
}
if ( V_55 . V_14 == NULL || ! V_55 . V_14 -> V_132 ) {
struct V_11 * V_12 ;
if ( ( V_156 || V_147 . V_157 ) &&
V_57 -> V_158 ) {
V_18 = F_67 ( V_38 , V_53 , V_55 . V_159 ,
V_57 -> V_158 , & V_137 ) ;
if ( V_18 )
return;
}
V_12 = F_28 ( V_53 , & V_55 , V_57 ) ;
if ( V_12 == NULL ) {
F_7 ( L_72 ) ;
return;
}
if ( V_147 . V_157 ) {
V_18 = F_68 ( V_12 -> V_158 , & V_160 ,
V_57 -> V_59 ) ;
if ( V_18 )
return;
}
if ( V_7 -> V_161 )
F_20 ( V_7 , V_12 , V_53 -> V_50 , V_28 ) ;
}
return;
}
static void F_69 ( struct V_6 * V_7 , int V_50 )
{
struct V_56 V_57 ;
struct V_52 * V_53 ;
struct V_162 * V_118 = V_7 -> V_118 ;
union V_135 * V_136 ;
struct V_38 * V_38 ;
T_6 V_163 ;
int V_164 ;
while ( ( V_136 = F_70 ( V_7 -> V_89 , V_50 ) ) != NULL ) {
V_164 = F_71 ( V_118 , V_136 , & V_57 ) ;
if ( V_164 ) {
F_7 ( L_73 , V_164 ) ;
continue;
}
V_53 = F_72 ( V_118 -> V_89 , V_57 . V_165 ) ;
assert ( V_53 != NULL ) ;
V_163 = V_136 -> V_141 . V_142 & V_166 ;
if ( V_136 -> V_141 . type == V_60 )
++ V_7 -> V_167 ;
switch ( V_163 ) {
case V_168 :
++ V_7 -> V_169 ;
if ( V_7 -> V_71 )
continue;
V_38 = F_73 ( V_118 ) ;
break;
case V_150 :
++ V_7 -> V_170 ;
if ( V_7 -> V_72 )
continue;
V_38 = F_73 ( V_118 ) ;
break;
case V_171 :
++ V_7 -> V_172 ;
V_38 = F_74 ( V_118 , V_136 -> V_28 . V_139 ) ;
break;
case V_173 :
++ V_7 -> V_174 ;
default:
continue;
}
if ( V_136 -> V_141 . type == V_60 ) {
F_63 ( & V_7 -> V_134 , V_136 , V_53 ,
& V_57 , V_38 ) ;
} else if ( V_136 -> V_141 . type < V_175 ) {
F_30 ( & V_53 -> V_58 , V_136 -> V_141 . type ) ;
F_75 ( & V_7 -> V_134 , V_136 , & V_57 , V_38 ) ;
} else
++ V_118 -> V_58 . V_66 . V_176 ;
}
}
static void F_76 ( struct V_6 * V_7 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_7 -> V_89 -> V_177 ; V_130 ++ )
F_69 ( V_7 , V_130 ) ;
}
static void F_77 ( struct V_6 * V_7 )
{
struct V_52 * V_43 , * V_178 ;
struct V_179 * V_89 = V_7 -> V_89 ;
V_178 = F_54 ( V_89 -> V_86 . V_85 , struct V_52 , V_116 ) ;
F_53 (counter, &evlist->entries, node) {
struct V_180 * V_181 = & V_43 -> V_181 ;
struct V_182 * V_183 = NULL ;
if ( V_7 -> V_184 && V_43 != V_178 )
V_183 = V_178 -> V_95 ;
V_181 -> V_185 = V_186 | V_187 ;
if ( V_7 -> V_188 ) {
V_181 -> V_185 |= V_189 ;
V_181 -> V_188 = 1 ;
V_181 -> V_190 = V_7 -> V_188 ;
}
if ( V_89 -> V_90 > 1 ) {
V_181 -> V_185 |= V_191 ;
V_181 -> V_192 |= V_193 ;
}
if ( F_78 ( & V_7 -> V_73 ) )
V_181 -> V_185 |= V_194 ;
if ( V_147 . V_157 )
V_181 -> V_185 |= V_195 ;
V_181 -> V_196 = 1 ;
V_181 -> V_197 = 1 ;
V_181 -> V_198 = V_7 -> V_198 ;
V_199:
if ( V_7 -> V_200 )
V_181 -> V_201 = V_181 -> V_202 = 0 ;
V_203:
V_181 -> V_204 = V_7 -> V_205 ? 0 : 1 ;
V_206:
if ( F_79 ( V_43 , V_7 -> V_89 -> V_207 ,
V_7 -> V_89 -> V_208 , V_7 -> V_184 ,
V_183 ) < 0 ) {
int V_18 = V_127 ;
if ( V_18 == V_209 || V_18 == V_210 ) {
F_80 () ;
goto V_211;
} else if ( V_18 == V_212 ) {
if ( ! V_7 -> V_200 &&
( V_181 -> V_201 || V_181 -> V_202 ) ) {
F_81 ( L_74
L_75 ) ;
V_7 -> V_200 = true ;
goto V_199;
} else if ( ! V_7 -> V_205 ) {
V_7 -> V_205 = true ;
goto V_203;
}
}
if ( V_181 -> type == V_213 &&
V_181 -> V_214 == V_215 ) {
if ( V_216 )
F_18 ( L_76
L_77 ) ;
V_181 -> type = V_217 ;
V_181 -> V_214 = V_218 ;
if ( V_43 -> V_23 ) {
free ( V_43 -> V_23 ) ;
V_43 -> V_23 = NULL ;
}
goto V_206;
}
if ( V_18 == V_219 ) {
F_82 ( L_78 ,
F_24 ( V_43 ) ) ;
goto V_211;
} else if ( V_18 == V_220 ) {
F_82 ( L_79
L_80 ) ;
goto V_211;
}
F_82 ( L_81
L_82
L_83
L_84
L_85 , V_18 , strerror ( V_18 ) ) ;
goto V_211;
}
}
if ( F_83 ( V_89 , V_7 -> V_221 , false ) < 0 ) {
F_82 ( L_86 ,
V_127 , strerror ( V_127 ) ) ;
goto V_211;
}
return;
V_211:
F_59 ( 0 ) ;
exit ( 0 ) ;
}
static int F_84 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_161 ) {
if ( V_147 . V_157 ) {
F_82 ( L_87 ) ;
return - V_212 ;
}
} else if ( ! V_7 -> V_222 && V_223 . V_224 != V_225 ) {
if ( F_85 ( & V_223 ) < 0 ) {
F_82 ( L_88 ) ;
return - V_212 ;
}
}
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
T_7 V_159 ;
int V_164 ;
V_7 -> V_118 = F_87 ( NULL , V_226 , false , false , NULL ) ;
if ( V_7 -> V_118 == NULL )
return - V_227 ;
V_164 = F_84 ( V_7 ) ;
if ( V_164 )
goto V_228;
if ( F_88 ( & V_7 -> V_73 ) )
F_89 ( & V_7 -> V_134 , V_7 -> V_89 -> V_208 ,
F_75 ,
& V_7 -> V_118 -> V_229 ) ;
else
F_90 ( & V_7 -> V_134 , F_75 ,
& V_7 -> V_118 -> V_229 ) ;
F_77 ( V_7 ) ;
V_7 -> V_118 -> V_89 = V_7 -> V_89 ;
F_91 ( V_7 -> V_118 ) ;
F_52 ( V_7 -> V_89 -> V_93 , V_7 -> V_89 -> V_230 , 100 ) ;
F_76 ( V_7 ) ;
if ( F_92 ( & V_159 , NULL , ( V_41 > 0 ? F_57 :
F_60 ) , V_7 ) ) {
F_82 ( L_89 ) ;
exit ( - 1 ) ;
}
if ( V_7 -> V_231 ) {
struct V_232 V_233 ;
V_233 . V_234 = V_7 -> V_231 ;
if ( F_93 ( 0 , V_235 , & V_233 ) ) {
F_82 ( L_90 ) ;
exit ( - 1 ) ;
}
}
while ( 1 ) {
T_4 V_236 = V_7 -> V_167 ;
F_76 ( V_7 ) ;
if ( V_236 == V_7 -> V_167 )
V_164 = F_52 ( V_7 -> V_89 -> V_93 , V_7 -> V_89 -> V_230 , 100 ) ;
}
V_228:
F_94 ( V_7 -> V_118 ) ;
V_7 -> V_118 = NULL ;
return 0 ;
}
static int
F_95 ( const struct V_237 * V_238 , const char * V_10 , int V_239 )
{
struct V_6 * V_7 = (struct V_6 * ) V_238 -> V_240 ;
char * V_241 , * V_242 ;
char * V_243 ;
if ( V_239 ) {
V_7 -> V_222 = true ;
return 0 ;
}
V_147 . V_157 = true ;
if ( ! V_10 )
return 0 ;
V_241 = strtok ( ( char * ) V_10 , L_91 ) ;
if ( ! V_241 )
return - 1 ;
if ( ! strncmp ( V_241 , L_92 , strlen ( V_10 ) ) )
V_223 . V_224 = V_244 ;
else if ( ! strncmp ( V_241 , L_93 , strlen ( V_10 ) ) )
V_223 . V_224 = V_245 ;
else if ( ! strncmp ( V_241 , L_94 , strlen ( V_10 ) ) )
V_223 . V_224 = V_246 ;
else if ( ! strncmp ( V_241 , L_95 , strlen ( V_10 ) ) ) {
V_223 . V_224 = V_225 ;
V_147 . V_157 = false ;
return 0 ;
} else
return - 1 ;
V_241 = strtok ( NULL , L_91 ) ;
if ( ! V_241 )
goto V_247;
V_223 . V_248 = strtod ( V_241 , & V_243 ) ;
if ( V_241 == V_243 )
return - 1 ;
V_242 = strtok ( NULL , L_91 ) ;
if ( ! V_242 )
goto V_247;
if ( V_242 [ 0 ] != 'c' ) {
V_223 . V_249 = strtod ( V_242 , & V_243 ) ;
V_242 = strtok ( NULL , L_91 ) ;
if ( ! V_242 )
goto V_247;
}
if ( ! strcmp ( V_242 , L_96 ) )
V_223 . V_250 = V_251 ;
else if ( ! strcmp ( V_242 , L_97 ) )
V_223 . V_250 = V_252 ;
else
return - 1 ;
V_247:
if ( F_85 ( & V_223 ) < 0 ) {
fprintf ( V_87 , L_98 ) ;
return - 1 ;
}
return 0 ;
}
int F_96 ( int V_253 , const char * * V_254 , const char * T_8 V_9 )
{
struct V_52 * V_121 ;
int V_255 ;
char V_256 [ V_257 ] ;
struct V_6 V_7 = {
. V_91 = 5 ,
. V_88 = 2 ,
. V_188 = 4000 ,
. V_221 = 128 ,
. V_49 = 5 ,
. V_73 = {
. V_258 = true ,
} ,
} ;
char V_259 [] = L_99 ;
const struct V_237 V_260 [] = {
F_97 ( 'e' , L_100 , & V_7 . V_89 , L_100 ,
L_101 ,
V_261 ) ,
F_98 ( 'c' , L_102 , & V_7 . V_262 ,
L_103 ) ,
F_99 ( 'p' , L_104 , & V_7 . V_73 . V_139 , L_104 ,
L_105 ) ,
F_99 ( 't' , L_106 , & V_7 . V_73 . V_263 , L_106 ,
L_107 ) ,
F_100 ( 'a' , L_108 , & V_7 . V_73 . V_264 ,
L_109 ) ,
F_99 ( 'C' , L_110 , & V_7 . V_73 . V_265 , L_110 ,
L_111 ) ,
F_99 ( 'k' , L_112 , & V_147 . V_155 ,
L_113 , L_114 ) ,
F_100 ( 'K' , L_115 , & V_7 . V_72 ,
L_116 ) ,
F_101 ( 'm' , L_117 , & V_7 . V_221 , L_118 ) ,
F_98 ( 'r' , L_119 , & V_7 . V_231 ,
L_120 ) ,
F_98 ( 'd' , L_121 , & V_7 . V_88 ,
L_122 ) ,
F_100 ( 'D' , L_123 , & V_7 . V_117 ,
L_124 ) ,
F_98 ( 'f' , L_125 , & V_7 . V_91 ,
L_126 ) ,
F_100 ( 'g' , L_127 , & V_7 . V_184 ,
L_128 ) ,
F_100 ( 'i' , L_129 , & V_7 . V_198 ,
L_130 ) ,
F_99 ( 0 , L_131 , & V_7 . V_266 , L_132 ,
L_133 ) ,
F_100 ( 'z' , L_134 , & V_7 . V_51 ,
L_135 ) ,
F_98 ( 'F' , L_136 , & V_7 . V_188 ,
L_137 ) ,
F_98 ( 'E' , L_138 , & V_7 . V_8 ,
L_139 ) ,
F_100 ( 'U' , L_140 , & V_7 . V_71 ,
L_141 ) ,
F_100 ( 0 , L_142 , & V_7 . V_267 , L_143 ) ,
F_100 ( 0 , L_144 , & V_7 . V_268 , L_145 ) ,
F_102 ( 'v' , L_146 , & V_216 ,
L_147 ) ,
F_99 ( 's' , L_148 , & V_269 , L_149 ,
L_150 ) ,
F_100 ( 'n' , L_151 , & V_147 . V_270 ,
L_152 ) ,
F_103 ( 'G' , L_153 , & V_7 , L_154 ,
L_155
L_156 , & F_95 ,
V_259 ) ,
F_100 ( 0 , L_157 , & V_147 . V_271 ,
L_158 ) ,
F_99 ( 0 , L_159 , & V_147 . V_272 , L_160 ,
L_161 ) ,
F_99 ( 0 , L_162 , & V_147 . V_273 , L_163 ,
L_164 ) ,
F_99 ( 0 , L_165 , & V_147 . V_274 , L_166 ,
L_167 ) ,
F_100 ( 0 , L_168 , & V_147 . V_275 ,
L_169 ) ,
F_100 ( 0 , L_170 , & V_147 . V_276 ,
L_171 ) ,
F_99 ( 'M' , L_172 , & V_277 , L_173 ,
L_174 ) ,
F_99 ( 'u' , L_175 , & V_7 . V_73 . V_124 , L_176 , L_177 ) ,
F_104 ()
} ;
V_7 . V_89 = F_105 ( NULL , NULL ) ;
if ( V_7 . V_89 == NULL )
return - V_227 ;
V_147 . V_278 = false ;
V_253 = F_106 ( V_253 , V_254 , V_260 , V_279 , 0 ) ;
if ( V_253 )
F_107 ( V_279 , V_260 ) ;
if ( V_269 == V_280 )
V_269 = L_178 ;
F_108 ( V_279 , V_260 ) ;
if ( V_7 . V_268 )
V_41 = 0 ;
else if ( V_7 . V_267 )
V_41 = 1 ;
F_109 ( false ) ;
V_255 = F_110 ( & V_7 . V_73 ) ;
if ( V_255 ) {
F_111 ( & V_7 . V_73 , V_255 , V_256 , V_257 ) ;
F_18 ( L_179 , V_256 ) ;
}
V_255 = F_112 ( & V_7 . V_73 ) ;
if ( V_255 ) {
int V_281 = V_127 ;
F_111 ( & V_7 . V_73 , V_255 , V_256 , V_257 ) ;
F_82 ( L_179 , V_256 ) ;
V_255 = - V_281 ;
goto V_282;
}
if ( F_113 ( & V_7 . V_73 ) )
V_7 . V_73 . V_264 = true ;
if ( F_114 ( V_7 . V_89 , & V_7 . V_73 ) < 0 )
F_107 ( V_279 , V_260 ) ;
if ( ! V_7 . V_89 -> V_90 &&
F_115 ( V_7 . V_89 ) < 0 ) {
F_82 ( L_180 ) ;
return - V_227 ;
}
V_147 . V_68 = V_7 . V_89 -> V_90 ;
if ( V_7 . V_88 < 1 )
V_7 . V_88 = 1 ;
if ( V_7 . V_262 )
V_7 . V_188 = 0 ;
else if ( V_7 . V_188 ) {
V_7 . V_262 = V_7 . V_188 ;
} else {
F_82 ( L_181 ) ;
exit ( V_283 ) ;
}
F_53 (pos, &top.evlist->entries, node) {
if ( ! V_121 -> V_181 . V_284 )
V_121 -> V_181 . V_284 = V_7 . V_262 ;
}
V_7 . V_48 = F_54 ( V_7 . V_89 -> V_86 . V_85 , struct V_52 , V_116 ) ;
V_147 . V_285 = sizeof( struct V_15 ) ;
V_147 . V_286 = ( V_147 . V_155 == NULL ) ;
if ( F_116 () < 0 )
return - 1 ;
F_117 ( & V_287 , V_147 . V_288 , L_182 , stdout ) ;
F_117 ( & V_289 , V_147 . V_290 , L_183 , stdout ) ;
F_117 ( & V_291 , V_147 . V_292 , L_184 , stdout ) ;
V_7 . V_161 = V_291 . V_293 . V_85 != NULL ;
F_1 ( & V_7 . V_1 ) ;
if ( V_7 . V_8 == 0 ) {
struct V_109 V_110 = {
. V_111 = F_5 ,
. V_112 = V_113 ,
} ;
F_4 ( & V_7 ) ;
V_109 ( V_114 , & V_110 , NULL ) ;
}
V_255 = F_86 ( & V_7 ) ;
V_282:
F_118 ( V_7 . V_89 ) ;
return V_255 ;
}
