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
static void F_5 ( int T_1 V_9 ,
T_2 * T_3 V_9 , void * V_10 )
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
F_39 ( & V_7 -> V_48 -> V_58 , false ,
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
V_7 -> V_48 = F_54 ( V_7 -> V_89 ) ;
fprintf ( V_87 , L_49 , F_24 ( V_7 -> V_48 ) ) ;
F_8 ( 1 ) ;
break;
}
F_53 (top->sym_evsel, &top->evlist->entries, node)
if ( V_7 -> V_48 -> V_50 == V_43 )
break;
} else
V_7 -> V_48 = F_54 ( V_7 -> V_89 ) ;
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
if ( V_7 -> V_116 )
F_55 ( V_7 -> V_117 , V_87 ) ;
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
struct V_6 * V_118 = V_10 ;
F_33 ( V_118 ) ;
if ( V_118 -> V_89 -> V_119 != NULL )
V_118 -> V_48 = V_118 -> V_89 -> V_119 ;
F_35 ( & V_118 -> V_48 -> V_58 ) ;
F_36 ( & V_118 -> V_48 -> V_58 ) ;
F_37 ( & V_118 -> V_48 -> V_58 ,
V_118 -> V_71 ,
V_118 -> V_72 ) ;
}
static void * F_57 ( void * V_10 )
{
struct V_52 * V_120 ;
struct V_6 * V_7 = V_10 ;
const char * V_121 = L_54 ;
F_56 ( V_7 ) ;
F_53 (pos, &top->evlist->entries, node)
V_120 -> V_58 . V_122 = V_7 -> V_73 . V_123 ;
F_58 ( V_7 -> V_89 , V_121 ,
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
int V_124 , V_92 ;
F_50 ( 0 , & V_100 ) ;
V_99 = V_100 ;
V_99 . V_101 &= ~ ( V_102 | V_103 ) ;
V_99 . V_104 [ V_105 ] = 0 ;
V_99 . V_104 [ V_106 ] = 0 ;
F_61 () ;
V_125:
V_124 = V_7 -> V_88 * 1000 ;
F_51 ( 0 , V_107 , & V_99 ) ;
getc ( V_79 ) ;
while ( 1 ) {
F_31 ( V_7 ) ;
switch ( F_52 ( & V_94 , 1 , V_124 ) ) {
case 0 :
continue;
case - 1 :
if ( V_126 == V_127 )
continue;
default:
goto V_128;
}
}
V_128:
V_92 = getc ( V_79 ) ;
F_51 ( 0 , V_108 , & V_100 ) ;
F_49 ( V_7 , V_92 ) ;
goto V_125;
return NULL ;
}
static int F_62 ( struct V_17 * V_17 V_9 , struct V_13 * V_14 )
{
const char * V_23 = V_14 -> V_23 ;
int V_129 ;
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
for ( V_129 = 0 ; V_130 [ V_129 ] ; V_129 ++ ) {
if ( ! strcmp ( V_130 [ V_129 ] , V_23 ) ) {
V_14 -> V_131 = true ;
break;
}
}
return 0 ;
}
static void F_63 ( struct V_132 * V_133 ,
const union V_134 * V_135 ,
struct V_52 * V_53 ,
struct V_56 * V_57 ,
struct V_38 * V_38 )
{
struct V_6 * V_7 = F_64 ( V_133 , struct V_6 , V_133 ) ;
struct V_13 * V_136 = NULL ;
T_4 V_28 = V_135 -> V_28 . V_28 ;
struct V_54 V_55 ;
int V_18 ;
if ( ! V_38 && V_137 ) {
static struct V_138 * V_139 ;
if ( ! V_139 )
V_139 = F_65 () ;
if ( ! F_66 ( V_139 , V_135 -> V_28 . V_140 ) ) {
F_7 ( L_62 ,
V_135 -> V_28 . V_140 ) ;
F_67 ( V_139 , V_135 -> V_28 . V_140 ) ;
}
return;
}
if ( ! V_38 ) {
F_7 ( L_63 ,
V_7 -> V_117 -> V_58 . V_66 . V_141 ++ ) ;
return;
}
if ( V_135 -> V_142 . V_143 & V_144 )
V_7 -> V_145 ++ ;
if ( F_68 ( V_135 , V_38 , & V_55 , V_57 ,
F_62 ) < 0 ||
V_55 . V_146 )
return;
if ( ! V_7 -> V_147 &&
V_148 . V_149 &&
V_55 . V_150 == V_151 ) {
F_18 (
L_64
L_65
L_66 ,
! F_69 ( & V_55 . V_17 -> V_20 -> V_152 [ V_153 ] ) ?
L_67 : L_68 ) ;
if ( V_41 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_147 = true ;
}
if ( V_55 . V_14 == NULL ) {
const char * V_74 = L_69 ;
if ( ! V_7 -> V_147 && ! V_7 -> V_154 &&
V_55 . V_17 == V_38 -> V_155 [ V_153 ] &&
F_69 ( & V_55 . V_17 -> V_20 -> V_152 [ V_153 ] ) ) {
if ( V_148 . V_156 ) {
F_18 ( L_70 ,
V_148 . V_156 , V_74 ) ;
} else {
F_18 ( L_71 ,
V_74 ) ;
}
if ( V_41 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_154 = true ;
}
}
if ( V_55 . V_14 == NULL || ! V_55 . V_14 -> V_131 ) {
struct V_11 * V_12 ;
if ( ( V_157 || V_148 . V_158 ) &&
V_57 -> V_159 ) {
V_18 = F_70 ( V_38 , V_53 ,
V_55 . V_160 , V_57 ,
& V_136 ) ;
if ( V_18 )
return;
}
V_12 = F_28 ( V_53 , & V_55 , V_57 ) ;
if ( V_12 == NULL ) {
F_7 ( L_72 ) ;
return;
}
if ( V_148 . V_158 ) {
V_18 = F_71 ( V_12 -> V_159 , & V_161 ,
V_57 -> V_59 ) ;
if ( V_18 )
return;
}
if ( V_7 -> V_162 )
F_20 ( V_7 , V_12 , V_53 -> V_50 , V_28 ) ;
}
return;
}
static void F_72 ( struct V_6 * V_7 , int V_50 )
{
struct V_56 V_57 ;
struct V_52 * V_53 ;
struct V_163 * V_117 = V_7 -> V_117 ;
union V_134 * V_135 ;
struct V_38 * V_38 ;
T_6 V_164 ;
int V_165 ;
while ( ( V_135 = F_73 ( V_7 -> V_89 , V_50 ) ) != NULL ) {
V_165 = F_74 ( V_7 -> V_89 , V_135 , & V_57 ) ;
if ( V_165 ) {
F_7 ( L_73 , V_165 ) ;
continue;
}
V_53 = F_75 ( V_117 -> V_89 , V_57 . V_166 ) ;
assert ( V_53 != NULL ) ;
V_164 = V_135 -> V_142 . V_143 & V_167 ;
if ( V_135 -> V_142 . type == V_60 )
++ V_7 -> V_168 ;
switch ( V_164 ) {
case V_169 :
++ V_7 -> V_170 ;
if ( V_7 -> V_71 )
continue;
V_38 = F_76 ( V_117 ) ;
break;
case V_151 :
++ V_7 -> V_171 ;
if ( V_7 -> V_72 )
continue;
V_38 = F_76 ( V_117 ) ;
break;
case V_172 :
++ V_7 -> V_173 ;
V_38 = F_77 ( V_117 , V_135 -> V_28 . V_140 ) ;
break;
case V_174 :
++ V_7 -> V_175 ;
default:
continue;
}
if ( V_135 -> V_142 . type == V_60 ) {
F_63 ( & V_7 -> V_133 , V_135 , V_53 ,
& V_57 , V_38 ) ;
} else if ( V_135 -> V_142 . type < V_176 ) {
F_30 ( & V_53 -> V_58 , V_135 -> V_142 . type ) ;
F_78 ( & V_7 -> V_133 , V_135 , & V_57 , V_38 ) ;
} else
++ V_117 -> V_58 . V_66 . V_177 ;
}
}
static void F_79 ( struct V_6 * V_7 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_7 -> V_89 -> V_178 ; V_129 ++ )
F_72 ( V_7 , V_129 ) ;
}
static void F_80 ( struct V_6 * V_7 )
{
struct V_52 * V_43 ;
struct V_179 * V_89 = V_7 -> V_89 ;
if ( V_7 -> V_180 )
F_81 ( V_89 ) ;
F_53 (counter, &evlist->entries, node) {
struct V_181 * V_182 = & V_43 -> V_182 ;
V_182 -> V_183 = V_184 | V_185 ;
if ( V_7 -> V_186 ) {
V_182 -> V_183 |= V_187 ;
V_182 -> V_186 = 1 ;
V_182 -> V_188 = V_7 -> V_186 ;
}
if ( V_89 -> V_90 > 1 ) {
V_182 -> V_183 |= V_189 ;
V_182 -> V_190 |= V_191 ;
}
if ( F_82 ( & V_7 -> V_73 ) )
V_182 -> V_183 |= V_192 ;
if ( V_148 . V_158 )
V_182 -> V_183 |= V_193 ;
V_182 -> V_194 = 1 ;
V_182 -> V_195 = 1 ;
V_182 -> V_196 = V_7 -> V_196 ;
V_197:
if ( V_7 -> V_198 )
V_182 -> V_199 = V_182 -> V_200 = 0 ;
V_201:
V_182 -> V_202 = V_7 -> V_203 ? 0 : 1 ;
V_204:
if ( F_83 ( V_43 , V_7 -> V_89 -> V_205 ,
V_7 -> V_89 -> V_206 ) < 0 ) {
int V_18 = V_126 ;
if ( V_18 == V_207 || V_18 == V_208 ) {
F_84 () ;
goto V_209;
} else if ( V_18 == V_210 ) {
if ( ! V_7 -> V_198 &&
( V_182 -> V_199 || V_182 -> V_200 ) ) {
F_85 ( L_74
L_75 ) ;
V_7 -> V_198 = true ;
goto V_197;
} else if ( ! V_7 -> V_203 ) {
V_7 -> V_203 = true ;
goto V_201;
}
}
if ( ( V_18 == V_211 || V_18 == V_212 ) &&
( V_182 -> type == V_213 ) &&
( V_182 -> V_214 == V_215 ) ) {
if ( V_216 )
F_18 ( L_76
L_77 ) ;
V_182 -> type = V_217 ;
V_182 -> V_214 = V_218 ;
if ( V_43 -> V_23 ) {
free ( V_43 -> V_23 ) ;
V_43 -> V_23 = NULL ;
}
goto V_204;
}
if ( V_18 == V_211 ) {
F_86 ( L_78 ,
F_24 ( V_43 ) ) ;
goto V_209;
} else if ( V_18 == V_219 ) {
F_86 ( L_79
L_80 ) ;
goto V_209;
}
F_86 ( L_81
L_82
L_83
L_84
L_85 , V_18 , strerror ( V_18 ) ) ;
goto V_209;
}
}
if ( F_87 ( V_89 , V_7 -> V_220 , false ) < 0 ) {
F_86 ( L_86 ,
V_126 , strerror ( V_126 ) ) ;
goto V_209;
}
return;
V_209:
F_59 ( 0 ) ;
exit ( 0 ) ;
}
static int F_88 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_162 ) {
if ( V_148 . V_158 ) {
F_86 ( L_87 ) ;
return - V_210 ;
}
} else if ( ! V_7 -> V_221 && V_222 . V_223 != V_224 ) {
if ( F_89 ( & V_222 ) < 0 ) {
F_86 ( L_88 ) ;
return - V_210 ;
}
}
return 0 ;
}
static int F_90 ( struct V_6 * V_7 )
{
T_7 V_160 ;
int V_165 ;
V_7 -> V_117 = F_91 ( NULL , V_225 , false , false , NULL ) ;
if ( V_7 -> V_117 == NULL )
return - V_226 ;
V_165 = F_88 ( V_7 ) ;
if ( V_165 )
goto V_227;
if ( F_92 ( & V_7 -> V_73 ) )
F_93 ( & V_7 -> V_133 , V_7 -> V_89 -> V_206 ,
F_78 ,
& V_7 -> V_117 -> V_228 ) ;
else
F_94 ( & V_7 -> V_133 , F_78 ,
& V_7 -> V_117 -> V_228 ) ;
F_80 ( V_7 ) ;
V_7 -> V_117 -> V_89 = V_7 -> V_89 ;
F_95 ( V_7 -> V_117 ) ;
F_52 ( V_7 -> V_89 -> V_93 , V_7 -> V_89 -> V_229 , 100 ) ;
F_79 ( V_7 ) ;
if ( F_96 ( & V_160 , NULL , ( V_41 > 0 ? F_57 :
F_60 ) , V_7 ) ) {
F_86 ( L_89 ) ;
exit ( - 1 ) ;
}
if ( V_7 -> V_230 ) {
struct V_231 V_232 ;
V_232 . V_233 = V_7 -> V_230 ;
if ( F_97 ( 0 , V_234 , & V_232 ) ) {
F_86 ( L_90 ) ;
exit ( - 1 ) ;
}
}
while ( 1 ) {
T_4 V_235 = V_7 -> V_168 ;
F_79 ( V_7 ) ;
if ( V_235 == V_7 -> V_168 )
V_165 = F_52 ( V_7 -> V_89 -> V_93 , V_7 -> V_89 -> V_229 , 100 ) ;
}
V_227:
F_98 ( V_7 -> V_117 ) ;
V_7 -> V_117 = NULL ;
return 0 ;
}
static int
F_99 ( const struct V_236 * V_237 , const char * V_10 , int V_238 )
{
struct V_6 * V_7 = (struct V_6 * ) V_237 -> V_239 ;
char * V_240 , * V_241 ;
char * V_242 ;
if ( V_238 ) {
V_7 -> V_221 = true ;
return 0 ;
}
V_148 . V_158 = true ;
if ( ! V_10 )
return 0 ;
V_240 = strtok ( ( char * ) V_10 , L_91 ) ;
if ( ! V_240 )
return - 1 ;
if ( ! strncmp ( V_240 , L_92 , strlen ( V_10 ) ) )
V_222 . V_223 = V_243 ;
else if ( ! strncmp ( V_240 , L_93 , strlen ( V_10 ) ) )
V_222 . V_223 = V_244 ;
else if ( ! strncmp ( V_240 , L_94 , strlen ( V_10 ) ) )
V_222 . V_223 = V_245 ;
else if ( ! strncmp ( V_240 , L_95 , strlen ( V_10 ) ) ) {
V_222 . V_223 = V_224 ;
V_148 . V_158 = false ;
return 0 ;
} else
return - 1 ;
V_240 = strtok ( NULL , L_91 ) ;
if ( ! V_240 )
goto V_246;
V_222 . V_247 = strtod ( V_240 , & V_242 ) ;
if ( V_240 == V_242 )
return - 1 ;
V_241 = strtok ( NULL , L_91 ) ;
if ( ! V_241 )
goto V_246;
if ( V_241 [ 0 ] != 'c' ) {
V_222 . V_248 = strtod ( V_241 , & V_242 ) ;
V_241 = strtok ( NULL , L_91 ) ;
if ( ! V_241 )
goto V_246;
}
if ( ! strcmp ( V_241 , L_96 ) )
V_222 . V_249 = V_250 ;
else if ( ! strcmp ( V_241 , L_97 ) )
V_222 . V_249 = V_251 ;
else
return - 1 ;
V_246:
if ( F_89 ( & V_222 ) < 0 ) {
fprintf ( V_87 , L_98 ) ;
return - 1 ;
}
return 0 ;
}
int F_100 ( int V_252 , const char * * V_253 , const char * T_8 V_9 )
{
struct V_52 * V_120 ;
int V_254 ;
char V_255 [ V_256 ] ;
struct V_6 V_7 = {
. V_91 = 5 ,
. V_88 = 2 ,
. V_186 = 4000 ,
. V_220 = 128 ,
. V_49 = 5 ,
. V_73 = {
. V_257 = true ,
} ,
} ;
char V_258 [] = L_99 ;
const struct V_236 V_259 [] = {
F_101 ( 'e' , L_100 , & V_7 . V_89 , L_100 ,
L_101 ,
V_260 ) ,
F_102 ( 'c' , L_102 , & V_7 . V_261 ,
L_103 ) ,
F_103 ( 'p' , L_104 , & V_7 . V_73 . V_140 , L_104 ,
L_105 ) ,
F_103 ( 't' , L_106 , & V_7 . V_73 . V_262 , L_106 ,
L_107 ) ,
F_104 ( 'a' , L_108 , & V_7 . V_73 . V_263 ,
L_109 ) ,
F_103 ( 'C' , L_110 , & V_7 . V_73 . V_264 , L_110 ,
L_111 ) ,
F_103 ( 'k' , L_112 , & V_148 . V_156 ,
L_113 , L_114 ) ,
F_104 ( 'K' , L_115 , & V_7 . V_72 ,
L_116 ) ,
F_105 ( 'm' , L_117 , & V_7 . V_220 , L_118 ) ,
F_102 ( 'r' , L_119 , & V_7 . V_230 ,
L_120 ) ,
F_102 ( 'd' , L_121 , & V_7 . V_88 ,
L_122 ) ,
F_104 ( 'D' , L_123 , & V_7 . V_116 ,
L_124 ) ,
F_102 ( 'f' , L_125 , & V_7 . V_91 ,
L_126 ) ,
F_104 ( 'g' , L_127 , & V_7 . V_180 ,
L_128 ) ,
F_104 ( 'i' , L_129 , & V_7 . V_196 ,
L_130 ) ,
F_103 ( 0 , L_131 , & V_7 . V_265 , L_132 ,
L_133 ) ,
F_104 ( 'z' , L_134 , & V_7 . V_51 ,
L_135 ) ,
F_102 ( 'F' , L_136 , & V_7 . V_186 ,
L_137 ) ,
F_102 ( 'E' , L_138 , & V_7 . V_8 ,
L_139 ) ,
F_104 ( 'U' , L_140 , & V_7 . V_71 ,
L_141 ) ,
F_104 ( 0 , L_142 , & V_7 . V_266 , L_143 ) ,
F_104 ( 0 , L_144 , & V_7 . V_267 , L_145 ) ,
F_106 ( 'v' , L_146 , & V_216 ,
L_147 ) ,
F_103 ( 's' , L_148 , & V_268 , L_149 ,
L_150 ) ,
F_104 ( 'n' , L_151 , & V_148 . V_269 ,
L_152 ) ,
F_107 ( 'G' , L_153 , & V_7 , L_154 ,
L_155
L_156 , & F_99 ,
V_258 ) ,
F_104 ( 0 , L_157 , & V_148 . V_270 ,
L_158 ) ,
F_103 ( 0 , L_159 , & V_148 . V_271 , L_160 ,
L_161 ) ,
F_103 ( 0 , L_162 , & V_148 . V_272 , L_163 ,
L_164 ) ,
F_103 ( 0 , L_165 , & V_148 . V_273 , L_166 ,
L_167 ) ,
F_104 ( 0 , L_168 , & V_148 . V_274 ,
L_169 ) ,
F_104 ( 0 , L_170 , & V_148 . V_275 ,
L_171 ) ,
F_103 ( 'M' , L_172 , & V_276 , L_173 ,
L_174 ) ,
F_103 ( 'u' , L_175 , & V_7 . V_73 . V_123 , L_176 , L_177 ) ,
F_108 ()
} ;
const char * const V_277 [] = {
L_178 ,
NULL
} ;
V_7 . V_89 = F_109 ( NULL , NULL ) ;
if ( V_7 . V_89 == NULL )
return - V_226 ;
V_148 . V_278 = false ;
V_252 = F_110 ( V_252 , V_253 , V_259 , V_277 , 0 ) ;
if ( V_252 )
F_111 ( V_277 , V_259 ) ;
if ( V_268 == V_279 )
V_268 = L_179 ;
F_112 ( V_277 , V_259 ) ;
if ( V_7 . V_267 )
V_41 = 0 ;
else if ( V_7 . V_266 )
V_41 = 1 ;
F_113 ( false ) ;
V_254 = F_114 ( & V_7 . V_73 ) ;
if ( V_254 ) {
F_115 ( & V_7 . V_73 , V_254 , V_255 , V_256 ) ;
F_18 ( L_180 , V_255 ) ;
}
V_254 = F_116 ( & V_7 . V_73 ) ;
if ( V_254 ) {
int V_280 = V_126 ;
F_115 ( & V_7 . V_73 , V_254 , V_255 , V_256 ) ;
F_86 ( L_180 , V_255 ) ;
V_254 = - V_280 ;
goto V_281;
}
if ( F_117 ( & V_7 . V_73 ) )
V_7 . V_73 . V_263 = true ;
if ( F_118 ( V_7 . V_89 , & V_7 . V_73 ) < 0 )
F_111 ( V_277 , V_259 ) ;
if ( ! V_7 . V_89 -> V_90 &&
F_119 ( V_7 . V_89 ) < 0 ) {
F_86 ( L_181 ) ;
return - V_226 ;
}
V_148 . V_68 = V_7 . V_89 -> V_90 ;
if ( V_7 . V_88 < 1 )
V_7 . V_88 = 1 ;
if ( V_7 . V_261 )
V_7 . V_186 = 0 ;
else if ( V_7 . V_186 ) {
V_7 . V_261 = V_7 . V_186 ;
} else {
F_86 ( L_182 ) ;
exit ( V_282 ) ;
}
F_53 (pos, &top.evlist->entries, node) {
if ( ! V_120 -> V_182 . V_283 )
V_120 -> V_182 . V_283 = V_7 . V_261 ;
}
V_7 . V_48 = F_54 ( V_7 . V_89 ) ;
V_148 . V_284 = sizeof( struct V_15 ) ;
V_148 . V_285 = ( V_148 . V_156 == NULL ) ;
if ( F_120 () < 0 )
return - 1 ;
F_121 ( & V_286 , V_148 . V_287 , L_183 , stdout ) ;
F_121 ( & V_288 , V_148 . V_289 , L_184 , stdout ) ;
F_121 ( & V_290 , V_148 . V_291 , L_185 , stdout ) ;
V_7 . V_162 = V_290 . V_292 . V_85 != NULL ;
F_1 ( & V_7 . V_1 ) ;
if ( V_7 . V_8 == 0 ) {
struct V_109 V_110 = {
. V_111 = F_5 ,
. V_112 = V_113 ,
} ;
F_4 ( & V_7 ) ;
V_109 ( V_114 , & V_110 , NULL ) ;
}
V_254 = F_90 ( & V_7 ) ;
V_281:
F_122 ( V_7 . V_89 ) ;
return V_254 ;
}
