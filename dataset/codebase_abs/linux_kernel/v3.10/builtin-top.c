static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > 9 )
V_2 -> V_3 -= 9 ;
}
static void F_2 ( int T_1 V_4 ,
T_2 * T_3 V_4 , void * V_5 )
{
struct V_1 * V_2 = V_5 ;
F_3 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_3
|| ( V_2 -> V_3 + 4 ) > V_2 -> V_6 . V_7 ) {
V_2 -> V_3 = V_2 -> V_6 . V_7 ;
} else {
V_2 -> V_3 += 4 ;
V_2 -> V_6 . V_7 = V_2 -> V_3 ;
}
F_1 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
int V_15 = - 1 ;
if ( ! V_9 || ! V_9 -> V_16 . V_11 )
return - 1 ;
V_11 = V_9 -> V_16 . V_11 ;
V_14 = V_9 -> V_16 . V_14 ;
if ( V_14 -> V_17 -> V_18 == V_19 ) {
F_5 ( L_1
L_2 , V_11 -> V_20 ) ;
F_6 ( 1 ) ;
return - 1 ;
}
V_13 = F_7 ( V_11 ) ;
if ( V_13 -> V_21 != NULL ) {
F_8 ( & V_13 -> V_22 ) ;
goto V_23;
}
F_8 ( & V_13 -> V_22 ) ;
if ( F_9 ( V_11 ) < 0 ) {
F_10 ( & V_13 -> V_22 ) ;
F_5 ( L_3 ,
V_11 -> V_20 ) ;
F_6 ( 1 ) ;
return V_15 ;
}
V_15 = F_11 ( V_11 , V_14 , 0 ) ;
if ( V_15 == 0 ) {
V_23:
V_2 -> V_24 = V_9 ;
}
F_10 ( & V_13 -> V_22 ) ;
return V_15 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_16 . V_11 ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_14 * V_14 , struct V_10 * V_11 , T_4 V_25 )
{
struct V_26 V_27 ;
int V_15 = F_15 ( & V_27 ) ;
F_16 ( L_4
L_5 V_28 L_6
L_7
L_8 V_28 L_9 V_28 L_6
L_10 V_28 L_9 V_28 L_11
L_12
L_13
L_14
L_15
L_16 ,
V_25 , V_14 -> V_17 -> V_29 , F_17 ( V_14 -> V_17 ) ,
V_14 -> V_30 , V_14 -> V_31 , V_11 -> V_30 , V_11 -> V_31 ,
V_11 -> V_32 == V_33 ? 'g' :
V_11 -> V_32 == V_34 ? 'l' : 'w' , V_11 -> V_20 ,
V_15 ? L_17 : V_27 . V_35 ,
V_15 ? L_17 : V_27 . V_36 , V_37 ) ;
if ( V_38 <= 0 )
F_6 ( 5 ) ;
V_14 -> V_39 = true ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
int V_40 , T_4 V_25 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 ;
int V_15 ;
if ( V_9 == NULL || V_9 -> V_16 . V_11 == NULL ||
( ( V_2 -> V_24 == NULL ||
V_2 -> V_24 -> V_16 . V_11 != V_9 -> V_16 . V_11 ) && V_38 != 1 ) )
return;
V_11 = V_9 -> V_16 . V_11 ;
V_13 = F_7 ( V_11 ) ;
if ( F_19 ( & V_13 -> V_22 ) )
return;
if ( V_13 -> V_21 == NULL && F_9 ( V_11 ) < 0 ) {
F_10 ( & V_13 -> V_22 ) ;
F_5 ( L_3 ,
V_11 -> V_20 ) ;
F_6 ( 1 ) ;
return;
}
V_25 = V_9 -> V_16 . V_14 -> V_41 ( V_9 -> V_16 . V_14 , V_25 ) ;
V_15 = F_20 ( V_11 , V_9 -> V_16 . V_14 , V_40 , V_25 ) ;
F_10 ( & V_13 -> V_22 ) ;
if ( V_15 == - V_42 && ! V_9 -> V_16 . V_14 -> V_39 )
F_14 ( V_9 -> V_16 . V_14 , V_11 , V_25 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_24 ;
struct V_12 * V_13 ;
struct V_10 * V_10 ;
int V_43 ;
if ( ! V_9 )
return;
V_10 = V_9 -> V_16 . V_11 ;
V_13 = F_7 ( V_10 ) ;
F_8 ( & V_13 -> V_22 ) ;
if ( V_13 -> V_21 == NULL )
goto V_44;
printf ( L_18 , F_22 ( V_2 -> V_45 ) , V_10 -> V_20 ) ;
printf ( L_19 , V_2 -> V_46 ) ;
V_43 = F_23 ( V_10 , V_9 -> V_16 . V_14 , V_2 -> V_45 ,
0 , V_2 -> V_46 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_47 )
F_24 ( V_10 , V_2 -> V_45 -> V_48 ) ;
else
F_25 ( V_10 , V_2 -> V_45 -> V_48 ) ;
if ( V_43 != 0 )
printf ( L_20 , V_43 ) ;
V_44:
F_10 ( & V_13 -> V_22 ) ;
}
static struct V_8 * F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_8 * V_9 ;
V_9 = F_27 ( & V_50 -> V_55 , V_52 , NULL , V_54 -> V_56 ,
V_54 -> V_57 ) ;
if ( V_9 == NULL )
return NULL ;
F_28 ( & V_50 -> V_55 , V_58 ) ;
return V_9 ;
}
static void F_29 ( struct V_1 * V_2 )
{
char V_59 [ 160 ] ;
int V_60 = 0 ;
const int V_61 = V_2 -> V_6 . V_62 - 1 ;
puts ( V_63 ) ;
F_30 ( V_2 , V_59 , sizeof( V_59 ) ) ;
printf ( L_21 , V_59 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_61 , V_61 , V_64 ) ;
if ( V_2 -> V_45 -> V_55 . V_65 . V_66 !=
V_2 -> V_45 -> V_55 . V_65 . V_67 [ V_68 ] ) {
V_2 -> V_45 -> V_55 . V_65 . V_66 =
V_2 -> V_45 -> V_55 . V_65 . V_67 [ V_68 ] ;
F_32 ( stdout , V_69 ,
L_23 ,
V_2 -> V_45 -> V_55 . V_65 . V_66 ) ;
++ V_60 ;
}
if ( V_2 -> V_24 ) {
F_21 ( V_2 ) ;
return;
}
F_33 ( & V_2 -> V_45 -> V_55 ) ;
F_34 ( & V_2 -> V_45 -> V_55 ) ;
F_35 ( & V_2 -> V_45 -> V_55 ,
V_2 -> V_70 ,
V_2 -> V_71 ) ;
F_36 ( & V_2 -> V_45 -> V_55 ,
V_2 -> V_6 . V_7 - 3 ) ;
putchar ( '\n' ) ;
F_37 ( & V_2 -> V_45 -> V_55 , false ,
V_2 -> V_6 . V_7 - 4 - V_60 , V_61 , stdout ) ;
}
static void F_38 ( int * V_72 , const char * V_73 )
{
char * V_74 = malloc ( 0 ) , * V_75 ;
T_5 V_76 = 0 ;
int V_77 ;
fprintf ( stdout , L_24 , V_73 ) ;
if ( F_39 ( & V_74 , & V_76 , V_78 ) < 0 )
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
* V_72 = V_77 ;
V_79:
free ( V_74 ) ;
}
static void F_40 ( int * V_72 , const char * V_73 )
{
int V_77 = 0 ;
F_38 ( & V_77 , V_73 ) ;
if ( V_77 >= 0 && V_77 <= 100 )
* V_72 = V_77 ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_73 )
{
char * V_74 = malloc ( 0 ) , * V_75 ;
struct V_8 * V_80 = V_2 -> V_24 , * V_81 , * V_82 = NULL ;
struct V_83 * V_84 ;
T_5 V_76 = 0 ;
if ( V_80 ) {
F_12 ( V_80 ) ;
V_2 -> V_24 = NULL ;
}
fprintf ( stdout , L_24 , V_73 ) ;
if ( F_39 ( & V_74 , & V_76 , V_78 ) < 0 )
goto V_79;
V_75 = strchr ( V_74 , '\n' ) ;
if ( V_75 )
* V_75 = 0 ;
V_84 = F_42 ( & V_2 -> V_45 -> V_55 . V_85 ) ;
while ( V_84 ) {
V_81 = F_43 ( V_84 , struct V_8 , V_83 ) ;
if ( V_81 -> V_16 . V_11 && ! strcmp ( V_74 , V_81 -> V_16 . V_11 -> V_20 ) ) {
V_82 = V_81 ;
break;
}
V_84 = F_44 ( & V_81 -> V_83 ) ;
}
if ( ! V_82 ) {
fprintf ( V_86 , L_25 , V_74 ) ;
F_6 ( 1 ) ;
} else
F_4 ( V_2 , V_82 ) ;
V_79:
free ( V_74 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
char * V_20 = NULL ;
if ( V_2 -> V_24 ) {
struct V_10 * V_11 = V_2 -> V_24 -> V_16 . V_11 ;
V_20 = V_11 -> V_20 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_87 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_88 -> V_89 > 1 )
fprintf ( stdout , L_29 , F_22 ( V_2 -> V_45 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_90 ) ;
fprintf ( stdout , L_31 , V_2 -> V_46 ) ;
fprintf ( stdout , L_32 , V_20 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_71 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_70 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_47 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_91 )
{
switch ( V_91 ) {
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
return V_2 -> V_88 -> V_89 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , int V_91 )
{
bool V_92 = true ;
if ( ! F_46 ( V_2 , V_91 ) ) {
struct V_93 V_94 = { . V_95 = 0 , . V_96 = V_97 } ;
struct V_98 V_99 , V_100 ;
F_45 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_48 ( 0 , & V_100 ) ;
V_99 = V_100 ;
V_99 . V_101 &= ~ ( V_102 | V_103 ) ;
V_99 . V_104 [ V_105 ] = 0 ;
V_99 . V_104 [ V_106 ] = 0 ;
F_49 ( 0 , V_107 , & V_99 ) ;
F_50 ( & V_94 , 1 , - 1 ) ;
V_91 = getc ( V_78 ) ;
F_49 ( 0 , V_108 , & V_100 ) ;
if ( ! F_46 ( V_2 , V_91 ) )
return V_92 ;
}
switch ( V_91 ) {
case 'd' :
F_38 ( & V_2 -> V_87 , L_42 ) ;
if ( V_2 -> V_87 < 1 )
V_2 -> V_87 = 1 ;
break;
case 'e' :
F_38 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_109 V_110 = {
. V_111 = F_2 ,
. V_112 = V_113 ,
} ;
F_2 ( V_114 , NULL , V_2 ) ;
V_109 ( V_114 , & V_110 , NULL ) ;
} else {
F_2 ( V_114 , NULL , V_2 ) ;
signal ( V_114 , V_115 ) ;
}
break;
case 'E' :
if ( V_2 -> V_88 -> V_89 > 1 ) {
int V_40 = 0 ;
fprintf ( V_86 , L_44 ) ;
F_51 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_86 , L_45 , V_2 -> V_45 -> V_48 , F_22 ( V_2 -> V_45 ) ) ;
F_38 ( & V_40 , L_46 ) ;
if ( V_40 >= V_2 -> V_88 -> V_89 ) {
V_2 -> V_45 = F_52 ( V_2 -> V_88 ) ;
fprintf ( V_86 , L_47 , F_22 ( V_2 -> V_45 ) ) ;
F_6 ( 1 ) ;
break;
}
F_51 (top->sym_evsel, &top->evlist->entries, node)
if ( V_2 -> V_45 -> V_48 == V_40 )
break;
} else
V_2 -> V_45 = F_52 ( V_2 -> V_88 ) ;
break;
case 'f' :
F_38 ( & V_2 -> V_90 , L_48 ) ;
break;
case 'F' :
F_40 ( & V_2 -> V_46 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_71 = ! V_2 -> V_71 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_116 )
F_53 ( V_2 -> V_117 , V_86 ) ;
V_92 = false ;
break;
case 's' :
F_41 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_24 )
break;
else {
struct V_8 * V_80 = V_2 -> V_24 ;
V_2 -> V_24 = NULL ;
F_12 ( V_80 ) ;
}
break;
case 'U' :
V_2 -> V_70 = ! V_2 -> V_70 ;
break;
case 'z' :
V_2 -> V_47 = ! V_2 -> V_47 ;
break;
default:
break;
}
return V_92 ;
}
static void F_54 ( void * V_5 )
{
struct V_1 * V_118 = V_5 ;
F_31 ( V_118 ) ;
if ( V_118 -> V_88 -> V_119 != NULL )
V_118 -> V_45 = V_118 -> V_88 -> V_119 ;
F_33 ( & V_118 -> V_45 -> V_55 ) ;
F_34 ( & V_118 -> V_45 -> V_55 ) ;
F_35 ( & V_118 -> V_45 -> V_55 ,
V_118 -> V_70 ,
V_118 -> V_71 ) ;
}
static void * F_55 ( void * V_5 )
{
struct V_49 * V_120 ;
struct V_1 * V_2 = V_5 ;
const char * V_121 = L_52 ;
struct V_122 V_123 = {
. V_124 = F_54 ,
. V_5 = V_2 ,
. V_125 = V_2 -> V_87 ,
} ;
F_54 ( V_2 ) ;
F_51 (pos, &top->evlist->entries, node)
V_120 -> V_55 . V_126 = V_2 -> V_127 . V_72 . V_128 ;
F_56 ( V_2 -> V_88 , V_121 , & V_123 ,
& V_2 -> V_117 -> V_129 . V_130 ) ;
V_131 = 1 ;
return NULL ;
}
static void * F_57 ( void * V_5 )
{
struct V_93 V_94 = { . V_95 = 0 , . V_96 = V_97 } ;
struct V_98 V_99 , V_100 ;
struct V_1 * V_2 = V_5 ;
int V_132 , V_91 ;
F_48 ( 0 , & V_100 ) ;
V_99 = V_100 ;
V_99 . V_101 &= ~ ( V_102 | V_103 ) ;
V_99 . V_104 [ V_105 ] = 0 ;
V_99 . V_104 [ V_106 ] = 0 ;
F_58 () ;
V_133:
V_132 = V_2 -> V_87 * 1000 ;
F_49 ( 0 , V_107 , & V_99 ) ;
getc ( V_78 ) ;
while ( ! V_131 ) {
F_29 ( V_2 ) ;
switch ( F_50 ( & V_94 , 1 , V_132 ) ) {
case 0 :
continue;
case - 1 :
if ( V_134 == V_135 )
continue;
default:
V_91 = getc ( V_78 ) ;
F_49 ( 0 , V_108 , & V_100 ) ;
if ( F_47 ( V_2 , V_91 ) )
goto V_133;
V_131 = 1 ;
}
}
return NULL ;
}
static int F_59 ( struct V_14 * V_14 V_4 , struct V_10 * V_11 )
{
const char * V_20 = V_11 -> V_20 ;
int V_136 ;
if ( V_20 [ 0 ] == '.' )
V_20 ++ ;
if ( ! strcmp ( V_20 , L_53 ) ||
! strcmp ( V_20 , L_54 ) ||
! strcmp ( V_20 , L_55 ) ||
! strncmp ( L_56 , V_20 , 11 ) ||
! strncmp ( L_57 , V_20 , 14 ) ||
strstr ( V_20 , L_58 ) ||
strstr ( V_20 , L_59 ) )
return 1 ;
for ( V_136 = 0 ; V_137 [ V_136 ] ; V_136 ++ ) {
if ( ! strcmp ( V_137 [ V_136 ] , V_20 ) ) {
V_11 -> V_138 = true ;
break;
}
}
return 0 ;
}
static void F_60 ( struct V_139 * V_140 ,
const union V_141 * V_142 ,
struct V_49 * V_50 ,
struct V_53 * V_54 ,
struct V_35 * V_35 )
{
struct V_1 * V_2 = F_61 ( V_140 , struct V_1 , V_140 ) ;
struct V_10 * V_143 = NULL ;
T_4 V_25 = V_142 -> V_25 . V_25 ;
struct V_51 V_52 ;
int V_15 ;
if ( ! V_35 && V_144 ) {
static struct V_145 * V_146 ;
if ( ! V_146 )
V_146 = F_62 ( NULL ) ;
if ( ! F_63 ( V_146 , V_142 -> V_25 . V_147 ) ) {
F_5 ( L_60 ,
V_142 -> V_25 . V_147 ) ;
F_64 ( V_146 , V_142 -> V_25 . V_147 ) ;
}
return;
}
if ( ! V_35 ) {
F_5 ( L_61 ,
V_2 -> V_117 -> V_65 . V_148 ++ ) ;
return;
}
if ( V_142 -> V_129 . V_149 & V_150 )
V_2 -> V_151 ++ ;
if ( F_65 ( V_142 , V_35 , & V_52 , V_54 ,
F_59 ) < 0 ||
V_52 . V_152 )
return;
if ( ! V_2 -> V_153 &&
V_154 . V_155 &&
V_52 . V_156 == V_157 ) {
F_16 (
L_62
L_63
L_64 ,
! F_66 ( & V_52 . V_14 -> V_17 -> V_158 [ V_159 ] ) ?
L_65 : L_66 ) ;
if ( V_38 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_153 = true ;
}
if ( V_52 . V_11 == NULL ) {
const char * V_73 = L_67 ;
if ( ! V_2 -> V_153 && ! V_2 -> V_160 &&
V_52 . V_14 == V_35 -> V_161 [ V_159 ] &&
F_66 ( & V_52 . V_14 -> V_17 -> V_158 [ V_159 ] ) ) {
if ( V_154 . V_162 ) {
F_16 ( L_68 ,
V_154 . V_162 , V_73 ) ;
} else {
F_16 ( L_69 ,
V_73 ) ;
}
if ( V_38 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_160 = true ;
}
}
if ( V_52 . V_11 == NULL || ! V_52 . V_11 -> V_138 ) {
struct V_8 * V_9 ;
if ( ( V_163 || V_154 . V_164 ) &&
V_54 -> V_165 ) {
V_15 = F_67 ( V_35 , V_50 ,
V_52 . V_166 , V_54 ,
& V_143 ) ;
if ( V_15 )
return;
}
V_9 = F_26 ( V_50 , & V_52 , V_54 ) ;
if ( V_9 == NULL ) {
F_5 ( L_70 ) ;
return;
}
if ( V_154 . V_164 ) {
V_15 = F_68 ( V_9 -> V_165 , & V_167 ,
V_54 -> V_56 ) ;
if ( V_15 )
return;
}
if ( V_2 -> V_168 )
F_18 ( V_2 , V_9 , V_50 -> V_48 , V_25 ) ;
}
return;
}
static void F_69 ( struct V_1 * V_2 , int V_48 )
{
struct V_53 V_54 ;
struct V_49 * V_50 ;
struct V_169 * V_117 = V_2 -> V_117 ;
union V_141 * V_142 ;
struct V_35 * V_35 ;
T_6 V_170 ;
int V_92 ;
while ( ( V_142 = F_70 ( V_2 -> V_88 , V_48 ) ) != NULL ) {
V_92 = F_71 ( V_2 -> V_88 , V_142 , & V_54 ) ;
if ( V_92 ) {
F_5 ( L_71 , V_92 ) ;
continue;
}
V_50 = F_72 ( V_117 -> V_88 , V_54 . V_171 ) ;
assert ( V_50 != NULL ) ;
V_170 = V_142 -> V_129 . V_149 & V_172 ;
if ( V_142 -> V_129 . type == V_58 )
++ V_2 -> V_173 ;
switch ( V_170 ) {
case V_174 :
++ V_2 -> V_175 ;
if ( V_2 -> V_70 )
continue;
V_35 = & V_117 -> V_176 . V_177 ;
break;
case V_157 :
++ V_2 -> V_178 ;
if ( V_2 -> V_71 )
continue;
V_35 = & V_117 -> V_176 . V_177 ;
break;
case V_179 :
++ V_2 -> V_180 ;
V_35 = F_73 ( V_117 , V_142 -> V_25 . V_147 ) ;
break;
case V_181 :
++ V_2 -> V_182 ;
default:
continue;
}
if ( V_142 -> V_129 . type == V_58 ) {
F_60 ( & V_2 -> V_140 , V_142 , V_50 ,
& V_54 , V_35 ) ;
} else if ( V_142 -> V_129 . type < V_183 ) {
F_28 ( & V_50 -> V_55 , V_142 -> V_129 . type ) ;
F_74 ( V_35 , V_142 ) ;
} else
++ V_117 -> V_65 . V_184 ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_2 -> V_88 -> V_185 ; V_136 ++ )
F_69 ( V_2 , V_136 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
char V_73 [ 512 ] ;
struct V_49 * V_40 ;
struct V_186 * V_88 = V_2 -> V_88 ;
struct V_187 * V_188 = & V_2 -> V_127 ;
F_77 ( V_88 , V_188 ) ;
F_51 (counter, &evlist->entries, node) {
V_189:
if ( F_78 ( V_40 , V_2 -> V_88 -> V_190 ,
V_2 -> V_88 -> V_191 ) < 0 ) {
if ( F_79 ( V_40 , V_134 , V_73 , sizeof( V_73 ) ) ) {
if ( V_192 )
F_16 ( L_21 , V_73 ) ;
goto V_189;
}
F_80 ( V_40 , & V_188 -> V_72 ,
V_134 , V_73 , sizeof( V_73 ) ) ;
F_81 ( L_21 , V_73 ) ;
goto V_193;
}
}
if ( F_82 ( V_88 , V_188 -> V_194 , false ) < 0 ) {
F_81 ( L_72 ,
V_134 , strerror ( V_134 ) ) ;
goto V_193;
}
return 0 ;
V_193:
return - 1 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_168 ) {
if ( V_154 . V_164 ) {
F_81 ( L_73 ) ;
return - V_195 ;
}
} else if ( V_196 . V_197 != V_198 ) {
if ( F_84 ( & V_196 ) < 0 ) {
F_81 ( L_74 ) ;
return - V_195 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_127 ;
T_7 V_166 ;
int V_92 ;
V_2 -> V_117 = F_86 ( NULL , V_199 , false , false , NULL ) ;
if ( V_2 -> V_117 == NULL )
return - V_200 ;
V_92 = F_83 ( V_2 ) ;
if ( V_92 )
goto V_201;
if ( F_87 ( & V_188 -> V_72 ) )
F_88 ( & V_2 -> V_140 , V_2 -> V_88 -> V_191 ,
V_202 ,
& V_2 -> V_117 -> V_176 . V_177 ) ;
else
F_89 ( & V_2 -> V_140 , V_202 ,
& V_2 -> V_117 -> V_176 . V_177 ) ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 )
goto V_201;
V_2 -> V_117 -> V_88 = V_2 -> V_88 ;
F_90 ( V_2 -> V_117 ) ;
if ( ! F_91 ( & V_188 -> V_72 ) )
F_92 ( V_2 -> V_88 ) ;
F_50 ( V_2 -> V_88 -> V_93 , V_2 -> V_88 -> V_203 , 100 ) ;
F_75 ( V_2 ) ;
V_92 = - 1 ;
if ( F_93 ( & V_166 , NULL , ( V_38 > 0 ? F_55 :
F_57 ) , V_2 ) ) {
F_81 ( L_75 ) ;
goto V_201;
}
if ( V_2 -> V_204 ) {
struct V_205 V_206 ;
V_206 . V_207 = V_2 -> V_204 ;
if ( F_94 ( 0 , V_208 , & V_206 ) ) {
F_81 ( L_76 ) ;
goto V_201;
}
}
while ( ! V_131 ) {
T_4 V_209 = V_2 -> V_173 ;
F_75 ( V_2 ) ;
if ( V_209 == V_2 -> V_173 )
V_92 = F_50 ( V_2 -> V_88 -> V_93 , V_2 -> V_88 -> V_203 , 100 ) ;
}
V_92 = 0 ;
V_201:
F_95 ( V_2 -> V_117 ) ;
V_2 -> V_117 = NULL ;
return V_92 ;
}
static int
F_96 ( const struct V_210 * V_211 , const char * V_5 , int V_212 )
{
if ( V_212 )
return 0 ;
V_154 . V_164 = true ;
return F_97 ( V_211 , V_5 , V_212 ) ;
}
int F_98 ( int V_213 , const char * * V_214 , const char * T_8 V_4 )
{
int V_215 ;
char V_216 [ V_217 ] ;
struct V_1 V_2 = {
. V_90 = 5 ,
. V_87 = 2 ,
. V_127 = {
. V_194 = V_218 ,
. V_219 = V_218 ,
. V_220 = V_221 ,
. V_222 = 4000 ,
. V_72 = {
. V_223 = true ,
} ,
} ,
. V_46 = 5 ,
} ;
struct V_187 * V_188 = & V_2 . V_127 ;
struct V_224 * V_72 = & V_188 -> V_72 ;
const struct V_210 V_225 [] = {
F_99 ( 'e' , L_77 , & V_2 . V_88 , L_77 ,
L_78 ,
V_226 ) ,
F_100 ( 'c' , L_79 , & V_188 -> V_220 , L_80 ) ,
F_101 ( 'p' , L_81 , & V_72 -> V_147 , L_81 ,
L_82 ) ,
F_101 ( 't' , L_83 , & V_72 -> V_227 , L_83 ,
L_84 ) ,
F_102 ( 'a' , L_85 , & V_72 -> V_228 ,
L_86 ) ,
F_101 ( 'C' , L_87 , & V_72 -> V_229 , L_87 ,
L_88 ) ,
F_101 ( 'k' , L_89 , & V_154 . V_162 ,
L_90 , L_91 ) ,
F_102 ( 'K' , L_92 , & V_2 . V_71 ,
L_93 ) ,
F_103 ( 'm' , L_94 , & V_188 -> V_194 ,
L_95 ) ,
F_104 ( 'r' , L_96 , & V_2 . V_204 ,
L_97 ) ,
F_104 ( 'd' , L_98 , & V_2 . V_87 ,
L_99 ) ,
F_102 ( 'D' , L_100 , & V_2 . V_116 ,
L_101 ) ,
F_104 ( 'f' , L_102 , & V_2 . V_90 ,
L_103 ) ,
F_102 ( 'g' , L_104 , & V_188 -> V_230 ,
L_105 ) ,
F_102 ( 'i' , L_106 , & V_188 -> V_231 ,
L_107 ) ,
F_101 ( 0 , L_108 , & V_2 . V_232 , L_109 ,
L_110 ) ,
F_102 ( 'z' , L_111 , & V_2 . V_47 , L_112 ) ,
F_103 ( 'F' , L_113 , & V_188 -> V_219 , L_114 ) ,
F_104 ( 'E' , L_115 , & V_2 . V_3 ,
L_116 ) ,
F_102 ( 'U' , L_117 , & V_2 . V_70 ,
L_118 ) ,
F_102 ( 0 , L_119 , & V_2 . V_233 , L_120 ) ,
F_102 ( 0 , L_121 , & V_2 . V_234 , L_122 ) ,
F_105 ( 'v' , L_123 , & V_192 ,
L_124 ) ,
F_101 ( 's' , L_125 , & V_235 , L_126 ,
L_127 ) ,
F_102 ( 'n' , L_128 , & V_154 . V_236 ,
L_129 ) ,
F_106 ( 'G' , L_130 , & V_2 . V_127 ,
L_131 , V_237 ,
& F_96 , L_132 ) ,
F_102 ( 0 , L_133 , & V_154 . V_238 ,
L_134 ) ,
F_101 ( 0 , L_135 , & V_154 . V_239 , L_136 ,
L_137 ) ,
F_101 ( 0 , L_138 , & V_154 . V_240 , L_139 ,
L_140 ) ,
F_101 ( 0 , L_141 , & V_154 . V_241 , L_142 ,
L_143 ) ,
F_102 ( 0 , L_144 , & V_154 . V_242 ,
L_145 ) ,
F_102 ( 0 , L_146 , & V_154 . V_243 ,
L_147 ) ,
F_101 ( 'M' , L_148 , & V_244 , L_149 ,
L_150 ) ,
F_101 ( 'u' , L_151 , & V_72 -> V_128 , L_152 , L_153 ) ,
F_107 ()
} ;
const char * const V_245 [] = {
L_154 ,
NULL
} ;
V_2 . V_88 = F_108 () ;
if ( V_2 . V_88 == NULL )
return - V_200 ;
V_154 . V_246 = false ;
V_213 = F_109 ( V_213 , V_214 , V_225 , V_245 , 0 ) ;
if ( V_213 )
F_110 ( V_245 , V_225 ) ;
if ( V_235 == V_247 )
V_235 = L_155 ;
if ( F_111 () < 0 )
F_110 ( V_245 , V_225 ) ;
if ( V_2 . V_234 )
V_38 = 0 ;
else if ( V_2 . V_233 )
V_38 = 1 ;
F_112 ( false ) ;
V_215 = F_113 ( V_72 ) ;
if ( V_215 ) {
F_114 ( V_72 , V_215 , V_216 , V_217 ) ;
F_16 ( L_156 , V_216 ) ;
}
V_215 = F_115 ( V_72 ) ;
if ( V_215 ) {
int V_248 = V_134 ;
F_114 ( V_72 , V_215 , V_216 , V_217 ) ;
F_81 ( L_156 , V_216 ) ;
V_215 = - V_248 ;
goto V_249;
}
if ( F_91 ( V_72 ) )
V_72 -> V_228 = true ;
if ( F_116 ( V_2 . V_88 , V_72 ) < 0 )
F_110 ( V_245 , V_225 ) ;
if ( ! V_2 . V_88 -> V_89 &&
F_117 ( V_2 . V_88 ) < 0 ) {
F_81 ( L_157 ) ;
goto V_250;
}
V_154 . V_67 = V_2 . V_88 -> V_89 ;
if ( V_2 . V_87 < 1 )
V_2 . V_87 = 1 ;
if ( V_188 -> V_220 != V_221 )
V_188 -> V_251 = V_188 -> V_220 ;
if ( V_188 -> V_219 != V_218 )
V_188 -> V_222 = V_188 -> V_219 ;
if ( V_188 -> V_251 )
V_188 -> V_222 = 0 ;
else if ( V_188 -> V_222 ) {
V_188 -> V_251 = V_188 -> V_222 ;
} else {
F_81 ( L_158 ) ;
V_215 = - V_195 ;
goto V_250;
}
V_2 . V_45 = F_52 ( V_2 . V_88 ) ;
V_154 . V_252 = sizeof( struct V_12 ) ;
V_154 . V_253 = ( V_154 . V_162 == NULL ) ;
if ( F_118 () < 0 )
return - 1 ;
F_119 ( & V_254 , V_154 . V_255 , L_159 , stdout ) ;
F_119 ( & V_256 , V_154 . V_257 , L_160 , stdout ) ;
F_119 ( & V_258 , V_154 . V_259 , L_161 , stdout ) ;
V_2 . V_168 = V_258 . V_260 . V_84 != NULL ;
F_3 ( & V_2 . V_6 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_109 V_110 = {
. V_111 = F_2 ,
. V_112 = V_113 ,
} ;
F_1 ( & V_2 ) ;
V_109 ( V_114 , & V_110 , NULL ) ;
}
V_215 = F_85 ( & V_2 ) ;
V_250:
F_120 ( V_2 . V_88 ) ;
V_249:
F_121 ( V_2 . V_88 ) ;
return V_215 ;
}
