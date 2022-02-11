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
V_43 = F_23 ( V_10 , V_9 -> V_16 . V_14 , V_2 -> V_45 -> V_47 ,
0 , V_2 -> V_46 , V_2 -> V_3 , 4 ) ;
if ( V_2 -> V_48 )
F_24 ( V_10 , V_2 -> V_45 -> V_47 ) ;
else
F_25 ( V_10 , V_2 -> V_45 -> V_47 ) ;
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
V_9 = F_27 ( & V_50 -> V_55 , V_52 , NULL , V_54 -> V_56 ) ;
if ( V_9 == NULL )
return NULL ;
F_28 ( & V_50 -> V_55 , V_57 ) ;
return V_9 ;
}
static void F_29 ( struct V_1 * V_2 )
{
char V_58 [ 160 ] ;
int V_59 = 0 ;
const int V_60 = V_2 -> V_6 . V_61 - 1 ;
puts ( V_62 ) ;
F_30 ( V_2 , V_58 , sizeof( V_58 ) ) ;
printf ( L_21 , V_58 ) ;
F_31 ( V_2 ) ;
printf ( L_22 , V_60 , V_60 , V_63 ) ;
if ( V_2 -> V_45 -> V_55 . V_64 . V_65 !=
V_2 -> V_45 -> V_55 . V_64 . V_66 [ V_67 ] ) {
V_2 -> V_45 -> V_55 . V_64 . V_65 =
V_2 -> V_45 -> V_55 . V_64 . V_66 [ V_67 ] ;
F_32 ( stdout , V_68 ,
L_23 ,
V_2 -> V_45 -> V_55 . V_64 . V_65 ) ;
++ V_59 ;
}
if ( V_2 -> V_24 ) {
F_21 ( V_2 ) ;
return;
}
F_33 ( & V_2 -> V_45 -> V_55 ) ;
F_34 ( & V_2 -> V_45 -> V_55 ) ;
F_35 ( & V_2 -> V_45 -> V_55 ,
V_2 -> V_69 ,
V_2 -> V_70 ) ;
F_36 ( & V_2 -> V_45 -> V_55 ,
V_2 -> V_6 . V_7 - 3 ) ;
putchar ( '\n' ) ;
F_37 ( & V_2 -> V_45 -> V_55 , false ,
V_2 -> V_6 . V_7 - 4 - V_59 , V_60 , stdout ) ;
}
static void F_38 ( int * V_71 , const char * V_72 )
{
char * V_73 = malloc ( 0 ) , * V_74 ;
T_5 V_75 = 0 ;
int V_76 ;
fprintf ( stdout , L_24 , V_72 ) ;
if ( F_39 ( & V_73 , & V_75 , V_77 ) < 0 )
return;
V_74 = strchr ( V_73 , '\n' ) ;
if ( V_74 )
* V_74 = 0 ;
V_74 = V_73 ;
while( * V_74 ) {
if ( ! isdigit ( * V_74 ) )
goto V_78;
V_74 ++ ;
}
V_76 = strtoul ( V_73 , NULL , 10 ) ;
* V_71 = V_76 ;
V_78:
free ( V_73 ) ;
}
static void F_40 ( int * V_71 , const char * V_72 )
{
int V_76 = 0 ;
F_38 ( & V_76 , V_72 ) ;
if ( V_76 >= 0 && V_76 <= 100 )
* V_71 = V_76 ;
}
static void F_41 ( struct V_1 * V_2 , const char * V_72 )
{
char * V_73 = malloc ( 0 ) , * V_74 ;
struct V_8 * V_79 = V_2 -> V_24 , * V_80 , * V_81 = NULL ;
struct V_82 * V_83 ;
T_5 V_75 = 0 ;
if ( V_79 ) {
F_12 ( V_79 ) ;
V_2 -> V_24 = NULL ;
}
fprintf ( stdout , L_24 , V_72 ) ;
if ( F_39 ( & V_73 , & V_75 , V_77 ) < 0 )
goto V_78;
V_74 = strchr ( V_73 , '\n' ) ;
if ( V_74 )
* V_74 = 0 ;
V_83 = F_42 ( & V_2 -> V_45 -> V_55 . V_84 ) ;
while ( V_83 ) {
V_80 = F_43 ( V_83 , struct V_8 , V_82 ) ;
if ( V_80 -> V_16 . V_11 && ! strcmp ( V_73 , V_80 -> V_16 . V_11 -> V_20 ) ) {
V_81 = V_80 ;
break;
}
V_83 = F_44 ( & V_80 -> V_82 ) ;
}
if ( ! V_81 ) {
fprintf ( V_85 , L_25 , V_73 ) ;
F_6 ( 1 ) ;
} else
F_4 ( V_2 , V_81 ) ;
V_78:
free ( V_73 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
char * V_20 = NULL ;
if ( V_2 -> V_24 ) {
struct V_10 * V_11 = V_2 -> V_24 -> V_16 . V_11 ;
V_20 = V_11 -> V_20 ;
}
fprintf ( stdout , L_26 ) ;
fprintf ( stdout , L_27 , V_2 -> V_86 ) ;
fprintf ( stdout , L_28 , V_2 -> V_3 ) ;
if ( V_2 -> V_87 -> V_88 > 1 )
fprintf ( stdout , L_29 , F_22 ( V_2 -> V_45 ) ) ;
fprintf ( stdout , L_30 , V_2 -> V_89 ) ;
fprintf ( stdout , L_31 , V_2 -> V_46 ) ;
fprintf ( stdout , L_32 , V_20 ? : L_33 ) ;
fprintf ( stdout , L_34 ) ;
fprintf ( stdout ,
L_35 ,
V_2 -> V_70 ? L_36 : L_37 ) ;
fprintf ( stdout ,
L_38 ,
V_2 -> V_69 ? L_36 : L_37 ) ;
fprintf ( stdout , L_39 , V_2 -> V_48 ? 1 : 0 ) ;
fprintf ( stdout , L_40 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_90 )
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
return V_2 -> V_87 -> V_88 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , int V_90 )
{
bool V_91 = true ;
if ( ! F_46 ( V_2 , V_90 ) ) {
struct V_92 V_93 = { . V_94 = 0 , . V_95 = V_96 } ;
struct V_97 V_98 , V_99 ;
F_45 ( V_2 ) ;
fprintf ( stdout , L_41 ) ;
fflush ( stdout ) ;
F_48 ( 0 , & V_99 ) ;
V_98 = V_99 ;
V_98 . V_100 &= ~ ( V_101 | V_102 ) ;
V_98 . V_103 [ V_104 ] = 0 ;
V_98 . V_103 [ V_105 ] = 0 ;
F_49 ( 0 , V_106 , & V_98 ) ;
F_50 ( & V_93 , 1 , - 1 ) ;
V_90 = getc ( V_77 ) ;
F_49 ( 0 , V_107 , & V_99 ) ;
if ( ! F_46 ( V_2 , V_90 ) )
return V_91 ;
}
switch ( V_90 ) {
case 'd' :
F_38 ( & V_2 -> V_86 , L_42 ) ;
if ( V_2 -> V_86 < 1 )
V_2 -> V_86 = 1 ;
break;
case 'e' :
F_38 ( & V_2 -> V_3 , L_43 ) ;
if ( V_2 -> V_3 == 0 ) {
struct V_108 V_109 = {
. V_110 = F_2 ,
. V_111 = V_112 ,
} ;
F_2 ( V_113 , NULL , V_2 ) ;
V_108 ( V_113 , & V_109 , NULL ) ;
} else {
F_2 ( V_113 , NULL , V_2 ) ;
signal ( V_113 , V_114 ) ;
}
break;
case 'E' :
if ( V_2 -> V_87 -> V_88 > 1 ) {
int V_40 = 0 ;
fprintf ( V_85 , L_44 ) ;
F_51 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_85 , L_45 , V_2 -> V_45 -> V_47 , F_22 ( V_2 -> V_45 ) ) ;
F_38 ( & V_40 , L_46 ) ;
if ( V_40 >= V_2 -> V_87 -> V_88 ) {
V_2 -> V_45 = F_52 ( V_2 -> V_87 ) ;
fprintf ( V_85 , L_47 , F_22 ( V_2 -> V_45 ) ) ;
F_6 ( 1 ) ;
break;
}
F_51 (top->sym_evsel, &top->evlist->entries, node)
if ( V_2 -> V_45 -> V_47 == V_40 )
break;
} else
V_2 -> V_45 = F_52 ( V_2 -> V_87 ) ;
break;
case 'f' :
F_38 ( & V_2 -> V_89 , L_48 ) ;
break;
case 'F' :
F_40 ( & V_2 -> V_46 ,
L_49 ) ;
break;
case 'K' :
V_2 -> V_70 = ! V_2 -> V_70 ;
break;
case 'q' :
case 'Q' :
printf ( L_50 ) ;
if ( V_2 -> V_115 )
F_53 ( V_2 -> V_116 , V_85 ) ;
V_91 = false ;
break;
case 's' :
F_41 ( V_2 , L_51 ) ;
break;
case 'S' :
if ( ! V_2 -> V_24 )
break;
else {
struct V_8 * V_79 = V_2 -> V_24 ;
V_2 -> V_24 = NULL ;
F_12 ( V_79 ) ;
}
break;
case 'U' :
V_2 -> V_69 = ! V_2 -> V_69 ;
break;
case 'z' :
V_2 -> V_48 = ! V_2 -> V_48 ;
break;
default:
break;
}
return V_91 ;
}
static void F_54 ( void * V_5 )
{
struct V_1 * V_117 = V_5 ;
F_31 ( V_117 ) ;
if ( V_117 -> V_87 -> V_118 != NULL )
V_117 -> V_45 = V_117 -> V_87 -> V_118 ;
F_33 ( & V_117 -> V_45 -> V_55 ) ;
F_34 ( & V_117 -> V_45 -> V_55 ) ;
F_35 ( & V_117 -> V_45 -> V_55 ,
V_117 -> V_69 ,
V_117 -> V_70 ) ;
}
static void * F_55 ( void * V_5 )
{
struct V_49 * V_119 ;
struct V_1 * V_2 = V_5 ;
const char * V_120 = L_52 ;
struct V_121 V_122 = {
. V_123 = F_54 ,
. V_5 = V_2 ,
. V_124 = V_2 -> V_86 ,
} ;
F_54 ( V_2 ) ;
F_51 (pos, &top->evlist->entries, node)
V_119 -> V_55 . V_125 = V_2 -> V_126 . V_71 . V_127 ;
F_56 ( V_2 -> V_87 , V_120 , & V_122 ,
& V_2 -> V_116 -> V_128 . V_129 ) ;
V_130 = 1 ;
return NULL ;
}
static void * F_57 ( void * V_5 )
{
struct V_92 V_93 = { . V_94 = 0 , . V_95 = V_96 } ;
struct V_97 V_98 , V_99 ;
struct V_1 * V_2 = V_5 ;
int V_131 , V_90 ;
F_48 ( 0 , & V_99 ) ;
V_98 = V_99 ;
V_98 . V_100 &= ~ ( V_101 | V_102 ) ;
V_98 . V_103 [ V_104 ] = 0 ;
V_98 . V_103 [ V_105 ] = 0 ;
F_58 () ;
V_132:
V_131 = V_2 -> V_86 * 1000 ;
F_49 ( 0 , V_106 , & V_98 ) ;
getc ( V_77 ) ;
while ( ! V_130 ) {
F_29 ( V_2 ) ;
switch ( F_50 ( & V_93 , 1 , V_131 ) ) {
case 0 :
continue;
case - 1 :
if ( V_133 == V_134 )
continue;
default:
V_90 = getc ( V_77 ) ;
F_49 ( 0 , V_107 , & V_99 ) ;
if ( F_47 ( V_2 , V_90 ) )
goto V_132;
V_130 = 1 ;
}
}
return NULL ;
}
static int F_59 ( struct V_14 * V_14 V_4 , struct V_10 * V_11 )
{
const char * V_20 = V_11 -> V_20 ;
int V_135 ;
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
for ( V_135 = 0 ; V_136 [ V_135 ] ; V_135 ++ ) {
if ( ! strcmp ( V_136 [ V_135 ] , V_20 ) ) {
V_11 -> V_137 = true ;
break;
}
}
return 0 ;
}
static void F_60 ( struct V_138 * V_139 ,
const union V_140 * V_141 ,
struct V_49 * V_50 ,
struct V_53 * V_54 ,
struct V_35 * V_35 )
{
struct V_1 * V_2 = F_61 ( V_139 , struct V_1 , V_139 ) ;
struct V_10 * V_142 = NULL ;
T_4 V_25 = V_141 -> V_25 . V_25 ;
struct V_51 V_52 ;
int V_15 ;
if ( ! V_35 && V_143 ) {
static struct V_144 * V_145 ;
if ( ! V_145 )
V_145 = F_62 ( NULL ) ;
if ( ! F_63 ( V_145 , V_141 -> V_25 . V_146 ) ) {
F_5 ( L_60 ,
V_141 -> V_25 . V_146 ) ;
F_64 ( V_145 , V_141 -> V_25 . V_146 ) ;
}
return;
}
if ( ! V_35 ) {
F_5 ( L_61 ,
V_2 -> V_116 -> V_64 . V_147 ++ ) ;
return;
}
if ( V_141 -> V_128 . V_148 & V_149 )
V_2 -> V_150 ++ ;
if ( F_65 ( V_141 , V_35 , & V_52 , V_54 ,
F_59 ) < 0 ||
V_52 . V_151 )
return;
if ( ! V_2 -> V_152 &&
V_153 . V_154 &&
V_52 . V_155 == V_156 ) {
F_16 (
L_62
L_63
L_64 ,
! F_66 ( & V_52 . V_14 -> V_17 -> V_157 [ V_158 ] ) ?
L_65 : L_66 ) ;
if ( V_38 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_152 = true ;
}
if ( V_52 . V_11 == NULL ) {
const char * V_72 = L_67 ;
if ( ! V_2 -> V_152 && ! V_2 -> V_159 &&
V_52 . V_14 == V_35 -> V_160 [ V_158 ] &&
F_66 ( & V_52 . V_14 -> V_17 -> V_157 [ V_158 ] ) ) {
if ( V_153 . V_161 ) {
F_16 ( L_68 ,
V_153 . V_161 , V_72 ) ;
} else {
F_16 ( L_69 ,
V_72 ) ;
}
if ( V_38 <= 0 )
F_6 ( 5 ) ;
V_2 -> V_159 = true ;
}
}
if ( V_52 . V_11 == NULL || ! V_52 . V_11 -> V_137 ) {
struct V_8 * V_9 ;
if ( ( V_162 || V_153 . V_163 ) &&
V_54 -> V_164 ) {
V_15 = F_67 ( V_35 , V_50 ,
V_52 . V_165 , V_54 ,
& V_142 ) ;
if ( V_15 )
return;
}
V_9 = F_26 ( V_50 , & V_52 , V_54 ) ;
if ( V_9 == NULL ) {
F_5 ( L_70 ) ;
return;
}
if ( V_153 . V_163 ) {
V_15 = F_68 ( V_9 -> V_164 , & V_166 ,
V_54 -> V_56 ) ;
if ( V_15 )
return;
}
if ( V_2 -> V_167 )
F_18 ( V_2 , V_9 , V_50 -> V_47 , V_25 ) ;
}
return;
}
static void F_69 ( struct V_1 * V_2 , int V_47 )
{
struct V_53 V_54 ;
struct V_49 * V_50 ;
struct V_168 * V_116 = V_2 -> V_116 ;
union V_140 * V_141 ;
struct V_35 * V_35 ;
T_6 V_169 ;
int V_91 ;
while ( ( V_141 = F_70 ( V_2 -> V_87 , V_47 ) ) != NULL ) {
V_91 = F_71 ( V_2 -> V_87 , V_141 , & V_54 ) ;
if ( V_91 ) {
F_5 ( L_71 , V_91 ) ;
continue;
}
V_50 = F_72 ( V_116 -> V_87 , V_54 . V_170 ) ;
assert ( V_50 != NULL ) ;
V_169 = V_141 -> V_128 . V_148 & V_171 ;
if ( V_141 -> V_128 . type == V_57 )
++ V_2 -> V_172 ;
switch ( V_169 ) {
case V_173 :
++ V_2 -> V_174 ;
if ( V_2 -> V_69 )
continue;
V_35 = & V_116 -> V_175 . V_176 ;
break;
case V_156 :
++ V_2 -> V_177 ;
if ( V_2 -> V_70 )
continue;
V_35 = & V_116 -> V_175 . V_176 ;
break;
case V_178 :
++ V_2 -> V_179 ;
V_35 = F_73 ( V_116 , V_141 -> V_25 . V_146 ) ;
break;
case V_180 :
++ V_2 -> V_181 ;
default:
continue;
}
if ( V_141 -> V_128 . type == V_57 ) {
F_60 ( & V_2 -> V_139 , V_141 , V_50 ,
& V_54 , V_35 ) ;
} else if ( V_141 -> V_128 . type < V_182 ) {
F_28 ( & V_50 -> V_55 , V_141 -> V_128 . type ) ;
F_74 ( V_35 , V_141 ) ;
} else
++ V_116 -> V_64 . V_183 ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_2 -> V_87 -> V_184 ; V_135 ++ )
F_69 ( V_2 , V_135 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
char V_72 [ 512 ] ;
struct V_49 * V_40 ;
struct V_185 * V_87 = V_2 -> V_87 ;
struct V_186 * V_187 = & V_2 -> V_126 ;
F_77 ( V_87 , V_187 ) ;
F_51 (counter, &evlist->entries, node) {
V_188:
if ( F_78 ( V_40 , V_2 -> V_87 -> V_189 ,
V_2 -> V_87 -> V_190 ) < 0 ) {
if ( F_79 ( V_40 , V_133 , V_72 , sizeof( V_72 ) ) ) {
if ( V_191 )
F_16 ( L_21 , V_72 ) ;
goto V_188;
}
F_80 ( V_40 , & V_187 -> V_71 ,
V_133 , V_72 , sizeof( V_72 ) ) ;
F_81 ( L_21 , V_72 ) ;
goto V_192;
}
}
if ( F_82 ( V_87 , V_187 -> V_193 , false ) < 0 ) {
F_81 ( L_72 ,
V_133 , strerror ( V_133 ) ) ;
goto V_192;
}
return 0 ;
V_192:
return - 1 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_167 ) {
if ( V_153 . V_163 ) {
F_81 ( L_73 ) ;
return - V_194 ;
}
} else if ( V_195 . V_196 != V_197 ) {
if ( F_84 ( & V_195 ) < 0 ) {
F_81 ( L_74 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_186 * V_187 = & V_2 -> V_126 ;
T_7 V_165 ;
int V_91 ;
V_2 -> V_116 = F_86 ( NULL , V_198 , false , false , NULL ) ;
if ( V_2 -> V_116 == NULL )
return - V_199 ;
V_91 = F_83 ( V_2 ) ;
if ( V_91 )
goto V_200;
if ( F_87 ( & V_187 -> V_71 ) )
F_88 ( & V_2 -> V_139 , V_2 -> V_87 -> V_190 ,
V_201 ,
& V_2 -> V_116 -> V_175 . V_176 ) ;
else
F_89 ( & V_2 -> V_139 , V_201 ,
& V_2 -> V_116 -> V_175 . V_176 ) ;
V_91 = F_76 ( V_2 ) ;
if ( V_91 )
goto V_200;
V_2 -> V_116 -> V_87 = V_2 -> V_87 ;
F_90 ( V_2 -> V_116 ) ;
if ( ! F_91 ( & V_187 -> V_71 ) )
F_92 ( V_2 -> V_87 ) ;
F_50 ( V_2 -> V_87 -> V_92 , V_2 -> V_87 -> V_202 , 100 ) ;
F_75 ( V_2 ) ;
V_91 = - 1 ;
if ( F_93 ( & V_165 , NULL , ( V_38 > 0 ? F_55 :
F_57 ) , V_2 ) ) {
F_81 ( L_75 ) ;
goto V_200;
}
if ( V_2 -> V_203 ) {
struct V_204 V_205 ;
V_205 . V_206 = V_2 -> V_203 ;
if ( F_94 ( 0 , V_207 , & V_205 ) ) {
F_81 ( L_76 ) ;
goto V_200;
}
}
while ( ! V_130 ) {
T_4 V_208 = V_2 -> V_172 ;
F_75 ( V_2 ) ;
if ( V_208 == V_2 -> V_172 )
V_91 = F_50 ( V_2 -> V_87 -> V_92 , V_2 -> V_87 -> V_202 , 100 ) ;
}
V_91 = 0 ;
V_200:
F_95 ( V_2 -> V_116 ) ;
V_2 -> V_116 = NULL ;
return V_91 ;
}
static int
F_96 ( const struct V_209 * V_210 , const char * V_5 , int V_211 )
{
if ( V_211 )
return 0 ;
V_153 . V_163 = true ;
return F_97 ( V_210 , V_5 , V_211 ) ;
}
int F_98 ( int V_212 , const char * * V_213 , const char * T_8 V_4 )
{
int V_214 ;
char V_215 [ V_216 ] ;
struct V_1 V_2 = {
. V_89 = 5 ,
. V_86 = 2 ,
. V_126 = {
. V_193 = V_217 ,
. V_218 = V_217 ,
. V_219 = V_220 ,
. V_221 = 4000 ,
. V_71 = {
. V_222 = true ,
} ,
} ,
. V_46 = 5 ,
} ;
struct V_186 * V_187 = & V_2 . V_126 ;
struct V_223 * V_71 = & V_187 -> V_71 ;
const struct V_209 V_224 [] = {
F_99 ( 'e' , L_77 , & V_2 . V_87 , L_77 ,
L_78 ,
V_225 ) ,
F_100 ( 'c' , L_79 , & V_187 -> V_219 , L_80 ) ,
F_101 ( 'p' , L_81 , & V_71 -> V_146 , L_81 ,
L_82 ) ,
F_101 ( 't' , L_83 , & V_71 -> V_226 , L_83 ,
L_84 ) ,
F_102 ( 'a' , L_85 , & V_71 -> V_227 ,
L_86 ) ,
F_101 ( 'C' , L_87 , & V_71 -> V_228 , L_87 ,
L_88 ) ,
F_101 ( 'k' , L_89 , & V_153 . V_161 ,
L_90 , L_91 ) ,
F_102 ( 'K' , L_92 , & V_2 . V_70 ,
L_93 ) ,
F_103 ( 'm' , L_94 , & V_187 -> V_193 ,
L_95 ) ,
F_104 ( 'r' , L_96 , & V_2 . V_203 ,
L_97 ) ,
F_104 ( 'd' , L_98 , & V_2 . V_86 ,
L_99 ) ,
F_102 ( 'D' , L_100 , & V_2 . V_115 ,
L_101 ) ,
F_104 ( 'f' , L_102 , & V_2 . V_89 ,
L_103 ) ,
F_102 ( 'g' , L_104 , & V_187 -> V_229 ,
L_105 ) ,
F_102 ( 'i' , L_106 , & V_187 -> V_230 ,
L_107 ) ,
F_101 ( 0 , L_108 , & V_2 . V_231 , L_109 ,
L_110 ) ,
F_102 ( 'z' , L_111 , & V_2 . V_48 , L_112 ) ,
F_103 ( 'F' , L_113 , & V_187 -> V_218 , L_114 ) ,
F_104 ( 'E' , L_115 , & V_2 . V_3 ,
L_116 ) ,
F_102 ( 'U' , L_117 , & V_2 . V_69 ,
L_118 ) ,
F_102 ( 0 , L_119 , & V_2 . V_232 , L_120 ) ,
F_102 ( 0 , L_121 , & V_2 . V_233 , L_122 ) ,
F_105 ( 'v' , L_123 , & V_191 ,
L_124 ) ,
F_101 ( 's' , L_125 , & V_234 , L_126 ,
L_127 ) ,
F_102 ( 'n' , L_128 , & V_153 . V_235 ,
L_129 ) ,
F_106 ( 'G' , L_130 , & V_2 . V_126 ,
L_131 , V_236 ,
& F_96 , L_132 ) ,
F_102 ( 0 , L_133 , & V_153 . V_237 ,
L_134 ) ,
F_101 ( 0 , L_135 , & V_153 . V_238 , L_136 ,
L_137 ) ,
F_101 ( 0 , L_138 , & V_153 . V_239 , L_139 ,
L_140 ) ,
F_101 ( 0 , L_141 , & V_153 . V_240 , L_142 ,
L_143 ) ,
F_102 ( 0 , L_144 , & V_153 . V_241 ,
L_145 ) ,
F_102 ( 0 , L_146 , & V_153 . V_242 ,
L_147 ) ,
F_101 ( 'M' , L_148 , & V_243 , L_149 ,
L_150 ) ,
F_101 ( 'u' , L_151 , & V_71 -> V_127 , L_152 , L_153 ) ,
F_107 ()
} ;
const char * const V_244 [] = {
L_154 ,
NULL
} ;
V_2 . V_87 = F_108 ( NULL , NULL ) ;
if ( V_2 . V_87 == NULL )
return - V_199 ;
V_153 . V_245 = false ;
V_212 = F_109 ( V_212 , V_213 , V_224 , V_244 , 0 ) ;
if ( V_212 )
F_110 ( V_244 , V_224 ) ;
if ( V_234 == V_246 )
V_234 = L_155 ;
if ( F_111 () < 0 )
F_110 ( V_244 , V_224 ) ;
if ( V_2 . V_233 )
V_38 = 0 ;
else if ( V_2 . V_232 )
V_38 = 1 ;
F_112 ( false ) ;
V_214 = F_113 ( V_71 ) ;
if ( V_214 ) {
F_114 ( V_71 , V_214 , V_215 , V_216 ) ;
F_16 ( L_156 , V_215 ) ;
}
V_214 = F_115 ( V_71 ) ;
if ( V_214 ) {
int V_247 = V_133 ;
F_114 ( V_71 , V_214 , V_215 , V_216 ) ;
F_81 ( L_156 , V_215 ) ;
V_214 = - V_247 ;
goto V_248;
}
if ( F_91 ( V_71 ) )
V_71 -> V_227 = true ;
if ( F_116 ( V_2 . V_87 , V_71 ) < 0 )
F_110 ( V_244 , V_224 ) ;
if ( ! V_2 . V_87 -> V_88 &&
F_117 ( V_2 . V_87 ) < 0 ) {
F_81 ( L_157 ) ;
goto V_249;
}
V_153 . V_66 = V_2 . V_87 -> V_88 ;
if ( V_2 . V_86 < 1 )
V_2 . V_86 = 1 ;
if ( V_187 -> V_219 != V_220 )
V_187 -> V_250 = V_187 -> V_219 ;
if ( V_187 -> V_218 != V_217 )
V_187 -> V_221 = V_187 -> V_218 ;
if ( V_187 -> V_250 )
V_187 -> V_221 = 0 ;
else if ( V_187 -> V_221 ) {
V_187 -> V_250 = V_187 -> V_221 ;
} else {
F_81 ( L_158 ) ;
V_214 = - V_194 ;
goto V_249;
}
V_2 . V_45 = F_52 ( V_2 . V_87 ) ;
V_153 . V_251 = sizeof( struct V_12 ) ;
V_153 . V_252 = ( V_153 . V_161 == NULL ) ;
if ( F_118 () < 0 )
return - 1 ;
F_119 ( & V_253 , V_153 . V_254 , L_159 , stdout ) ;
F_119 ( & V_255 , V_153 . V_256 , L_160 , stdout ) ;
F_119 ( & V_257 , V_153 . V_258 , L_161 , stdout ) ;
V_2 . V_167 = V_257 . V_259 . V_83 != NULL ;
F_3 ( & V_2 . V_6 ) ;
if ( V_2 . V_3 == 0 ) {
struct V_108 V_109 = {
. V_110 = F_2 ,
. V_111 = V_112 ,
} ;
F_1 ( & V_2 ) ;
V_108 ( V_113 , & V_109 , NULL ) ;
}
V_214 = F_85 ( & V_2 ) ;
V_249:
F_120 ( V_2 . V_87 ) ;
V_248:
F_121 ( V_2 . V_87 ) ;
return V_214 ;
}
