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
static void F_16 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
int V_28 , T_4 V_29 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
if ( V_12 == NULL || V_12 -> V_19 . V_14 == NULL ||
( ( V_7 -> V_27 == NULL ||
V_7 -> V_27 -> V_19 . V_14 != V_12 -> V_19 . V_14 ) && V_30 != 1 ) )
return;
V_14 = V_12 -> V_19 . V_14 ;
V_16 = F_9 ( V_14 ) ;
if ( F_17 ( & V_16 -> V_25 ) )
return;
if ( V_16 -> V_24 == NULL && F_11 ( V_14 ) < 0 ) {
F_12 ( & V_16 -> V_25 ) ;
F_7 ( L_5 ,
V_14 -> V_23 ) ;
F_8 ( 1 ) ;
return;
}
V_29 = V_12 -> V_19 . V_17 -> V_31 ( V_12 -> V_19 . V_17 , V_29 ) ;
F_18 ( V_14 , V_12 -> V_19 . V_17 , V_28 , V_29 ) ;
F_12 ( & V_16 -> V_25 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_27 ;
struct V_15 * V_16 ;
struct V_13 * V_13 ;
int V_32 ;
if ( ! V_12 )
return;
V_13 = V_12 -> V_19 . V_14 ;
V_16 = F_9 ( V_13 ) ;
F_10 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_24 == NULL )
goto V_33;
printf ( L_6 , F_20 ( V_7 -> V_34 ) , V_13 -> V_23 ) ;
printf ( L_7 , V_7 -> V_35 ) ;
V_32 = F_21 ( V_13 , V_12 -> V_19 . V_17 , V_7 -> V_34 -> V_36 ,
0 , V_7 -> V_35 , V_7 -> V_8 , 4 ) ;
if ( V_7 -> V_37 )
F_22 ( V_13 , V_7 -> V_34 -> V_36 ) ;
else
F_23 ( V_13 , V_7 -> V_34 -> V_36 ) ;
if ( V_32 != 0 )
printf ( L_8 , V_32 ) ;
V_33:
F_12 ( & V_16 -> V_25 ) ;
}
static struct V_11 * F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_11 * V_12 ;
V_12 = F_25 ( & V_39 -> V_44 , V_41 , NULL , V_43 -> V_45 ) ;
if ( V_12 == NULL )
return NULL ;
F_26 ( & V_39 -> V_44 , V_46 ) ;
return V_12 ;
}
static void F_27 ( struct V_6 * V_7 )
{
char V_47 [ 160 ] ;
int V_48 = 0 ;
const int V_49 = V_7 -> V_1 . V_5 - 1 ;
puts ( V_50 ) ;
F_28 ( V_7 , V_47 , sizeof( V_47 ) ) ;
printf ( L_9 , V_47 ) ;
F_29 ( V_7 ) ;
printf ( L_10 , V_49 , V_49 , V_51 ) ;
if ( V_7 -> V_34 -> V_44 . V_52 . V_53 !=
V_7 -> V_34 -> V_44 . V_52 . V_54 [ V_55 ] ) {
V_7 -> V_34 -> V_44 . V_52 . V_53 =
V_7 -> V_34 -> V_44 . V_52 . V_54 [ V_55 ] ;
F_30 ( stdout , V_56 ,
L_11 ,
V_7 -> V_34 -> V_44 . V_52 . V_53 ) ;
++ V_48 ;
}
if ( V_7 -> V_27 ) {
F_19 ( V_7 ) ;
return;
}
F_31 ( & V_7 -> V_34 -> V_44 ) ;
F_32 ( & V_7 -> V_34 -> V_44 ) ;
F_33 ( & V_7 -> V_34 -> V_44 ,
V_7 -> V_57 ,
V_7 -> V_58 ) ;
F_34 ( & V_7 -> V_34 -> V_44 ,
V_7 -> V_1 . V_4 - 3 ) ;
putchar ( '\n' ) ;
F_35 ( & V_7 -> V_34 -> V_44 , NULL , false , false ,
V_7 -> V_1 . V_4 - 4 - V_48 , V_49 , stdout ) ;
}
static void F_36 ( int * V_59 , const char * V_60 )
{
char * V_61 = malloc ( 0 ) , * V_62 ;
T_5 V_63 = 0 ;
int V_64 ;
fprintf ( stdout , L_12 , V_60 ) ;
if ( F_37 ( & V_61 , & V_63 , V_65 ) < 0 )
return;
V_62 = strchr ( V_61 , '\n' ) ;
if ( V_62 )
* V_62 = 0 ;
V_62 = V_61 ;
while( * V_62 ) {
if ( ! isdigit ( * V_62 ) )
goto V_66;
V_62 ++ ;
}
V_64 = strtoul ( V_61 , NULL , 10 ) ;
* V_59 = V_64 ;
V_66:
free ( V_61 ) ;
}
static void F_38 ( int * V_59 , const char * V_60 )
{
int V_64 = 0 ;
F_36 ( & V_64 , V_60 ) ;
if ( V_64 >= 0 && V_64 <= 100 )
* V_59 = V_64 ;
}
static void F_39 ( struct V_6 * V_7 , const char * V_60 )
{
char * V_61 = malloc ( 0 ) , * V_62 ;
struct V_11 * V_67 = V_7 -> V_27 , * V_68 , * V_69 = NULL ;
struct V_70 * V_71 ;
T_5 V_63 = 0 ;
if ( V_67 ) {
F_14 ( V_67 ) ;
V_7 -> V_27 = NULL ;
}
fprintf ( stdout , L_12 , V_60 ) ;
if ( F_37 ( & V_61 , & V_63 , V_65 ) < 0 )
goto V_66;
V_62 = strchr ( V_61 , '\n' ) ;
if ( V_62 )
* V_62 = 0 ;
V_71 = F_40 ( & V_7 -> V_34 -> V_44 . V_72 ) ;
while ( V_71 ) {
V_68 = F_41 ( V_71 , struct V_11 , V_70 ) ;
if ( V_68 -> V_19 . V_14 && ! strcmp ( V_61 , V_68 -> V_19 . V_14 -> V_23 ) ) {
V_69 = V_68 ;
break;
}
V_71 = F_42 ( & V_68 -> V_70 ) ;
}
if ( ! V_69 ) {
fprintf ( V_73 , L_13 , V_61 ) ;
F_8 ( 1 ) ;
} else
F_6 ( V_7 , V_69 ) ;
V_66:
free ( V_61 ) ;
}
static void F_43 ( struct V_6 * V_7 )
{
char * V_23 = NULL ;
if ( V_7 -> V_27 ) {
struct V_13 * V_14 = V_7 -> V_27 -> V_19 . V_14 ;
V_23 = V_14 -> V_23 ;
}
fprintf ( stdout , L_14 ) ;
fprintf ( stdout , L_15 , V_7 -> V_74 ) ;
fprintf ( stdout , L_16 , V_7 -> V_8 ) ;
if ( V_7 -> V_75 -> V_76 > 1 )
fprintf ( stdout , L_17 , F_20 ( V_7 -> V_34 ) ) ;
fprintf ( stdout , L_18 , V_7 -> V_77 ) ;
fprintf ( stdout , L_19 , V_7 -> V_35 ) ;
fprintf ( stdout , L_20 , V_23 ? : L_21 ) ;
fprintf ( stdout , L_22 ) ;
fprintf ( stdout ,
L_23 ,
V_7 -> V_58 ? L_24 : L_25 ) ;
fprintf ( stdout ,
L_26 ,
V_7 -> V_57 ? L_24 : L_25 ) ;
fprintf ( stdout , L_27 , V_7 -> V_37 ? 1 : 0 ) ;
fprintf ( stdout , L_28 ) ;
}
static int F_44 ( struct V_6 * V_7 , int V_78 )
{
switch ( V_78 ) {
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
return V_7 -> V_75 -> V_76 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static void F_45 ( struct V_6 * V_7 , int V_78 )
{
if ( ! F_44 ( V_7 , V_78 ) ) {
struct V_79 V_80 = { . V_81 = 0 , . V_82 = V_83 } ;
struct V_84 V_85 , V_86 ;
F_43 ( V_7 ) ;
fprintf ( stdout , L_29 ) ;
fflush ( stdout ) ;
F_46 ( 0 , & V_86 ) ;
V_85 = V_86 ;
V_85 . V_87 &= ~ ( V_88 | V_89 ) ;
V_85 . V_90 [ V_91 ] = 0 ;
V_85 . V_90 [ V_92 ] = 0 ;
F_47 ( 0 , V_93 , & V_85 ) ;
F_48 ( & V_80 , 1 , - 1 ) ;
V_78 = getc ( V_65 ) ;
F_47 ( 0 , V_94 , & V_86 ) ;
if ( ! F_44 ( V_7 , V_78 ) )
return;
}
switch ( V_78 ) {
case 'd' :
F_36 ( & V_7 -> V_74 , L_30 ) ;
if ( V_7 -> V_74 < 1 )
V_7 -> V_74 = 1 ;
break;
case 'e' :
F_36 ( & V_7 -> V_8 , L_31 ) ;
if ( V_7 -> V_8 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_5 ,
. V_98 = V_99 ,
} ;
F_5 ( V_100 , NULL , V_7 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
} else {
F_5 ( V_100 , NULL , V_7 ) ;
signal ( V_100 , V_101 ) ;
}
break;
case 'E' :
if ( V_7 -> V_75 -> V_76 > 1 ) {
int V_28 = 0 ;
fprintf ( V_73 , L_32 ) ;
F_49 (top->sym_evsel, &top->evlist->entries, node)
fprintf ( V_73 , L_33 , V_7 -> V_34 -> V_36 , F_20 ( V_7 -> V_34 ) ) ;
F_36 ( & V_28 , L_34 ) ;
if ( V_28 >= V_7 -> V_75 -> V_76 ) {
V_7 -> V_34 = F_50 ( V_7 -> V_75 -> V_72 . V_71 , struct V_38 , V_102 ) ;
fprintf ( V_73 , L_35 , F_20 ( V_7 -> V_34 ) ) ;
F_8 ( 1 ) ;
break;
}
F_49 (top->sym_evsel, &top->evlist->entries, node)
if ( V_7 -> V_34 -> V_36 == V_28 )
break;
} else
V_7 -> V_34 = F_50 ( V_7 -> V_75 -> V_72 . V_71 , struct V_38 , V_102 ) ;
break;
case 'f' :
F_36 ( & V_7 -> V_77 , L_36 ) ;
break;
case 'F' :
F_38 ( & V_7 -> V_35 ,
L_37 ) ;
break;
case 'K' :
V_7 -> V_58 = ! V_7 -> V_58 ;
break;
case 'q' :
case 'Q' :
printf ( L_38 ) ;
if ( V_7 -> V_103 )
F_51 ( V_7 -> V_104 , V_73 ) ;
exit ( 0 ) ;
case 's' :
F_39 ( V_7 , L_39 ) ;
break;
case 'S' :
if ( ! V_7 -> V_27 )
break;
else {
struct V_11 * V_67 = V_7 -> V_27 ;
V_7 -> V_27 = NULL ;
F_14 ( V_67 ) ;
}
break;
case 'U' :
V_7 -> V_57 = ! V_7 -> V_57 ;
break;
case 'z' :
V_7 -> V_37 = ! V_7 -> V_37 ;
break;
default:
break;
}
}
static void F_52 ( void * V_10 )
{
struct V_6 * V_105 = V_10 ;
F_29 ( V_105 ) ;
if ( V_105 -> V_75 -> V_106 != NULL )
V_105 -> V_34 = V_105 -> V_75 -> V_106 ;
F_31 ( & V_105 -> V_34 -> V_44 ) ;
F_32 ( & V_105 -> V_34 -> V_44 ) ;
F_33 ( & V_105 -> V_34 -> V_44 ,
V_105 -> V_57 ,
V_105 -> V_58 ) ;
}
static void * F_53 ( void * V_10 )
{
struct V_6 * V_7 = V_10 ;
const char * V_107 = L_40 ;
F_52 ( V_7 ) ;
F_54 ( V_7 -> V_75 , V_107 ,
F_52 ,
V_7 , V_7 -> V_74 ) ;
F_55 ( 0 ) ;
exit ( 0 ) ;
return NULL ;
}
static void * F_56 ( void * V_10 )
{
struct V_79 V_80 = { . V_81 = 0 , . V_82 = V_83 } ;
struct V_84 V_85 , V_86 ;
struct V_6 * V_7 = V_10 ;
int V_108 , V_78 ;
F_46 ( 0 , & V_86 ) ;
V_85 = V_86 ;
V_85 . V_87 &= ~ ( V_88 | V_89 ) ;
V_85 . V_90 [ V_91 ] = 0 ;
V_85 . V_90 [ V_92 ] = 0 ;
F_57 () ;
V_109:
V_108 = V_7 -> V_74 * 1000 ;
F_47 ( 0 , V_93 , & V_85 ) ;
getc ( V_65 ) ;
while ( 1 ) {
F_27 ( V_7 ) ;
switch ( F_48 ( & V_80 , 1 , V_108 ) ) {
case 0 :
continue;
case - 1 :
if ( V_110 == V_111 )
continue;
default:
goto V_112;
}
}
V_112:
V_78 = getc ( V_65 ) ;
F_47 ( 0 , V_94 , & V_86 ) ;
F_45 ( V_7 , V_78 ) ;
goto V_109;
return NULL ;
}
static int F_58 ( struct V_17 * V_17 V_9 , struct V_13 * V_14 )
{
const char * V_23 = V_14 -> V_23 ;
int V_113 ;
if ( V_23 [ 0 ] == '.' )
V_23 ++ ;
if ( ! strcmp ( V_23 , L_41 ) ||
! strcmp ( V_23 , L_42 ) ||
! strcmp ( V_23 , L_43 ) ||
! strncmp ( L_44 , V_23 , 11 ) ||
! strncmp ( L_45 , V_23 , 14 ) ||
strstr ( V_23 , L_46 ) ||
strstr ( V_23 , L_47 ) )
return 1 ;
for ( V_113 = 0 ; V_114 [ V_113 ] ; V_113 ++ ) {
if ( ! strcmp ( V_114 [ V_113 ] , V_23 ) ) {
V_14 -> V_115 = true ;
break;
}
}
return 0 ;
}
static void F_59 ( struct V_116 * V_117 ,
const union V_118 * V_119 ,
struct V_38 * V_39 ,
struct V_42 * V_43 ,
struct V_120 * V_120 )
{
struct V_6 * V_7 = F_60 ( V_117 , struct V_6 , V_117 ) ;
struct V_13 * V_121 = NULL ;
T_4 V_29 = V_119 -> V_29 . V_29 ;
struct V_40 V_41 ;
int V_18 ;
if ( ! V_120 && V_122 ) {
F_7 ( L_48 ,
V_119 -> V_29 . V_123 ) ;
return;
}
if ( V_119 -> V_124 . V_125 & V_126 )
V_7 -> V_127 ++ ;
if ( F_61 ( V_119 , V_120 , & V_41 , V_43 ,
F_58 ) < 0 ||
V_41 . V_128 )
return;
if ( ! V_7 -> V_129 &&
V_130 . V_131 &&
V_41 . V_132 == V_133 ) {
F_62 (
L_49
L_50
L_51 ,
! F_63 ( & V_41 . V_17 -> V_20 -> V_134 [ V_135 ] ) ?
L_52 : L_53 ) ;
if ( V_30 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_129 = true ;
}
if ( V_41 . V_14 == NULL ) {
const char * V_60 = L_54 ;
if ( ! V_7 -> V_129 && ! V_7 -> V_136 &&
V_41 . V_17 == V_120 -> V_137 [ V_135 ] &&
F_63 ( & V_41 . V_17 -> V_20 -> V_134 [ V_135 ] ) ) {
if ( V_130 . V_138 ) {
F_62 ( L_55 ,
V_130 . V_138 , V_60 ) ;
} else {
F_62 ( L_56 ,
V_60 ) ;
}
if ( V_30 <= 0 )
F_8 ( 5 ) ;
V_7 -> V_136 = true ;
}
}
if ( V_41 . V_14 == NULL || ! V_41 . V_14 -> V_115 ) {
struct V_11 * V_12 ;
if ( ( V_139 || V_130 . V_140 ) &&
V_43 -> V_141 ) {
V_18 = F_64 ( V_120 , V_39 , V_41 . V_142 ,
V_43 -> V_141 , & V_121 ) ;
if ( V_18 )
return;
}
V_12 = F_24 ( V_39 , & V_41 , V_43 ) ;
if ( V_12 == NULL ) {
F_7 ( L_57 ) ;
return;
}
if ( V_130 . V_140 ) {
V_18 = F_65 ( V_12 -> V_141 , & V_39 -> V_44 . V_143 ,
V_43 -> V_45 ) ;
if ( V_18 )
return;
}
if ( V_7 -> V_144 )
F_16 ( V_7 , V_12 , V_39 -> V_36 , V_29 ) ;
}
return;
}
static void F_66 ( struct V_6 * V_7 , int V_36 )
{
struct V_42 V_43 ;
struct V_38 * V_39 ;
struct V_145 * V_104 = V_7 -> V_104 ;
union V_118 * V_119 ;
struct V_120 * V_120 ;
T_6 V_146 ;
int V_147 ;
while ( ( V_119 = F_67 ( V_7 -> V_75 , V_36 ) ) != NULL ) {
V_147 = F_68 ( V_104 , V_119 , & V_43 ) ;
if ( V_147 ) {
F_7 ( L_58 , V_147 ) ;
continue;
}
V_39 = F_69 ( V_104 -> V_75 , V_43 . V_148 ) ;
assert ( V_39 != NULL ) ;
V_146 = V_119 -> V_124 . V_125 & V_149 ;
if ( V_119 -> V_124 . type == V_46 )
++ V_7 -> V_150 ;
switch ( V_146 ) {
case V_151 :
++ V_7 -> V_152 ;
if ( V_7 -> V_57 )
continue;
V_120 = F_70 ( V_104 ) ;
break;
case V_133 :
++ V_7 -> V_153 ;
if ( V_7 -> V_58 )
continue;
V_120 = F_70 ( V_104 ) ;
break;
case V_154 :
++ V_7 -> V_155 ;
V_120 = F_71 ( V_104 , V_119 -> V_29 . V_123 ) ;
break;
case V_156 :
++ V_7 -> V_157 ;
default:
continue;
}
if ( V_119 -> V_124 . type == V_46 ) {
F_59 ( & V_7 -> V_117 , V_119 , V_39 ,
& V_43 , V_120 ) ;
} else if ( V_119 -> V_124 . type < V_158 ) {
F_26 ( & V_39 -> V_44 , V_119 -> V_124 . type ) ;
F_72 ( & V_7 -> V_117 , V_119 , & V_43 , V_120 ) ;
} else
++ V_104 -> V_44 . V_52 . V_159 ;
}
}
static void F_73 ( struct V_6 * V_7 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_7 -> V_75 -> V_160 ; V_113 ++ )
F_66 ( V_7 , V_113 ) ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_38 * V_28 , * V_161 ;
struct V_162 * V_75 = V_7 -> V_75 ;
V_161 = F_50 ( V_75 -> V_72 . V_71 , struct V_38 , V_102 ) ;
F_49 (counter, &evlist->entries, node) {
struct V_163 * V_164 = & V_28 -> V_164 ;
struct V_165 * V_166 = NULL ;
if ( V_7 -> V_167 && V_28 != V_161 )
V_166 = V_161 -> V_81 ;
V_164 -> V_168 = V_169 | V_170 ;
if ( V_7 -> V_171 ) {
V_164 -> V_168 |= V_172 ;
V_164 -> V_171 = 1 ;
V_164 -> V_173 = V_7 -> V_171 ;
}
if ( V_75 -> V_76 > 1 ) {
V_164 -> V_168 |= V_174 ;
V_164 -> V_175 |= V_176 ;
}
if ( V_130 . V_140 )
V_164 -> V_168 |= V_177 ;
V_164 -> V_178 = 1 ;
V_164 -> V_179 = 1 ;
V_164 -> V_180 = V_7 -> V_180 ;
V_181:
if ( V_7 -> V_182 )
V_164 -> V_183 = V_164 -> V_184 = 0 ;
V_185:
V_164 -> V_186 = V_7 -> V_187 ? 1 : 0 ;
V_188:
if ( F_75 ( V_28 , V_7 -> V_75 -> V_189 ,
V_7 -> V_75 -> V_190 , V_7 -> V_167 ,
V_166 ) < 0 ) {
int V_18 = V_110 ;
if ( V_18 == V_191 || V_18 == V_192 ) {
F_76 () ;
goto V_193;
} else if ( V_18 == V_194 ) {
if ( ! V_7 -> V_182 &&
( V_164 -> V_183 || V_164 -> V_184 ) ) {
F_77 ( L_59
L_60 ) ;
V_7 -> V_182 = true ;
goto V_181;
} else if ( V_7 -> V_187 ) {
V_7 -> V_187 = false ;
goto V_185;
}
}
if ( V_164 -> type == V_195 &&
V_164 -> V_196 == V_197 ) {
if ( V_198 )
F_62 ( L_61
L_62 ) ;
V_164 -> type = V_199 ;
V_164 -> V_196 = V_200 ;
goto V_188;
}
if ( V_18 == V_201 ) {
F_62 ( L_63 ,
F_20 ( V_28 ) ) ;
goto V_193;
} else if ( V_18 == V_202 ) {
F_62 ( L_64
L_65 ) ;
goto V_193;
}
F_62 ( L_66
L_67
L_68
L_69
L_70 , V_18 , strerror ( V_18 ) ) ;
goto V_193;
}
}
if ( F_78 ( V_75 , V_7 -> V_203 , false ) < 0 ) {
F_62 ( L_71 ,
V_110 , strerror ( V_110 ) ) ;
goto V_193;
}
return;
V_193:
F_55 ( 0 ) ;
exit ( 0 ) ;
}
static int F_79 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_144 ) {
if ( V_130 . V_140 ) {
F_62 ( L_72 ) ;
return - V_194 ;
}
} else if ( ! V_7 -> V_204 && V_205 . V_206 != V_207 ) {
if ( F_80 ( & V_205 ) < 0 ) {
F_62 ( L_73 ) ;
return - V_194 ;
}
}
return 0 ;
}
static int F_81 ( struct V_6 * V_7 )
{
T_7 V_142 ;
int V_147 ;
V_7 -> V_104 = F_82 ( NULL , V_208 , false , false , NULL ) ;
if ( V_7 -> V_104 == NULL )
return - V_209 ;
V_147 = F_79 ( V_7 ) ;
if ( V_147 )
goto V_210;
if ( V_7 -> V_211 != - 1 )
F_83 ( & V_7 -> V_117 , V_7 -> V_75 -> V_190 ,
F_72 ,
& V_7 -> V_104 -> V_212 ) ;
else
F_84 ( & V_7 -> V_117 , F_72 ,
& V_7 -> V_104 -> V_212 ) ;
F_74 ( V_7 ) ;
V_7 -> V_104 -> V_75 = V_7 -> V_75 ;
F_85 ( V_7 -> V_104 ) ;
F_48 ( V_7 -> V_75 -> V_79 , V_7 -> V_75 -> V_213 , 100 ) ;
F_73 ( V_7 ) ;
if ( F_86 ( & V_142 , NULL , ( V_30 > 0 ? F_53 :
F_56 ) , V_7 ) ) {
printf ( L_74 ) ;
exit ( - 1 ) ;
}
if ( V_7 -> V_214 ) {
struct V_215 V_216 ;
V_216 . V_217 = V_7 -> V_214 ;
if ( F_87 ( 0 , V_218 , & V_216 ) ) {
printf ( L_75 ) ;
exit ( - 1 ) ;
}
}
while ( 1 ) {
T_4 V_219 = V_7 -> V_150 ;
F_73 ( V_7 ) ;
if ( V_219 == V_7 -> V_150 )
V_147 = F_48 ( V_7 -> V_75 -> V_79 , V_7 -> V_75 -> V_213 , 100 ) ;
}
V_210:
F_88 ( V_7 -> V_104 ) ;
V_7 -> V_104 = NULL ;
return 0 ;
}
static int
F_89 ( const struct V_220 * V_221 , const char * V_10 , int V_222 )
{
struct V_6 * V_7 = (struct V_6 * ) V_221 -> V_223 ;
char * V_224 , * V_225 ;
char * V_226 ;
if ( V_222 ) {
V_7 -> V_204 = true ;
return 0 ;
}
V_130 . V_140 = true ;
if ( ! V_10 )
return 0 ;
V_224 = strtok ( ( char * ) V_10 , L_76 ) ;
if ( ! V_224 )
return - 1 ;
if ( ! strncmp ( V_224 , L_77 , strlen ( V_10 ) ) )
V_205 . V_206 = V_227 ;
else if ( ! strncmp ( V_224 , L_78 , strlen ( V_10 ) ) )
V_205 . V_206 = V_228 ;
else if ( ! strncmp ( V_224 , L_79 , strlen ( V_10 ) ) )
V_205 . V_206 = V_229 ;
else if ( ! strncmp ( V_224 , L_80 , strlen ( V_10 ) ) ) {
V_205 . V_206 = V_207 ;
V_130 . V_140 = false ;
return 0 ;
} else
return - 1 ;
V_224 = strtok ( NULL , L_76 ) ;
if ( ! V_224 )
goto V_230;
V_205 . V_231 = strtod ( V_224 , & V_226 ) ;
if ( V_224 == V_226 )
return - 1 ;
V_225 = strtok ( NULL , L_76 ) ;
if ( ! V_225 )
goto V_230;
if ( V_225 [ 0 ] != 'c' ) {
V_205 . V_232 = strtod ( V_225 , & V_226 ) ;
V_225 = strtok ( NULL , L_76 ) ;
if ( ! V_225 )
goto V_230;
}
if ( ! strcmp ( V_225 , L_81 ) )
V_205 . V_233 = V_234 ;
else if ( ! strcmp ( V_225 , L_82 ) )
V_205 . V_233 = V_235 ;
else
return - 1 ;
V_230:
if ( F_80 ( & V_205 ) < 0 ) {
fprintf ( V_73 , L_83 ) ;
return - 1 ;
}
return 0 ;
}
int F_90 ( int V_236 , const char * * V_237 , const char * T_8 V_9 )
{
struct V_38 * V_238 ;
int V_239 = - V_209 ;
struct V_6 V_7 = {
. V_77 = 5 ,
. V_74 = 2 ,
. V_240 = - 1 ,
. V_211 = - 1 ,
. V_171 = 1000 ,
. V_187 = true ,
. V_203 = 128 ,
. V_35 = 5 ,
} ;
char V_241 [] = L_84 ;
const struct V_220 V_242 [] = {
F_91 ( 'e' , L_85 , & V_7 . V_75 , L_85 ,
L_86 ,
V_243 ) ,
F_92 ( 'c' , L_87 , & V_7 . V_244 ,
L_88 ) ,
F_92 ( 'p' , L_89 , & V_7 . V_240 ,
L_90 ) ,
F_92 ( 't' , L_91 , & V_7 . V_211 ,
L_92 ) ,
F_93 ( 'a' , L_93 , & V_7 . V_245 ,
L_94 ) ,
F_94 ( 'C' , L_95 , & V_7 . V_246 , L_95 ,
L_96 ) ,
F_94 ( 'k' , L_97 , & V_130 . V_138 ,
L_98 , L_99 ) ,
F_93 ( 'K' , L_100 , & V_7 . V_58 ,
L_101 ) ,
F_95 ( 'm' , L_102 , & V_7 . V_203 , L_103 ) ,
F_92 ( 'r' , L_104 , & V_7 . V_214 ,
L_105 ) ,
F_92 ( 'd' , L_106 , & V_7 . V_74 ,
L_107 ) ,
F_93 ( 'D' , L_108 , & V_7 . V_103 ,
L_109 ) ,
F_92 ( 'f' , L_110 , & V_7 . V_77 ,
L_111 ) ,
F_93 ( 'g' , L_112 , & V_7 . V_167 ,
L_113 ) ,
F_93 ( 'i' , L_114 , & V_7 . V_180 ,
L_115 ) ,
F_94 ( 0 , L_116 , & V_7 . V_247 , L_117 ,
L_118 ) ,
F_93 ( 'z' , L_119 , & V_7 . V_37 ,
L_120 ) ,
F_92 ( 'F' , L_121 , & V_7 . V_171 ,
L_122 ) ,
F_92 ( 'E' , L_123 , & V_7 . V_8 ,
L_124 ) ,
F_93 ( 'U' , L_125 , & V_7 . V_57 ,
L_126 ) ,
F_93 ( 0 , L_127 , & V_7 . V_248 , L_128 ) ,
F_93 ( 0 , L_129 , & V_7 . V_249 , L_130 ) ,
F_96 ( 'v' , L_131 , & V_198 ,
L_132 ) ,
F_94 ( 's' , L_133 , & V_250 , L_134 ,
L_135 ) ,
F_93 ( 'n' , L_136 , & V_130 . V_251 ,
L_137 ) ,
F_97 ( 'G' , L_138 , & V_7 , L_139 ,
L_140
L_141 , & F_89 ,
V_241 ) ,
F_93 ( 0 , L_142 , & V_130 . V_252 ,
L_143 ) ,
F_94 ( 0 , L_144 , & V_130 . V_253 , L_145 ,
L_146 ) ,
F_94 ( 0 , L_147 , & V_130 . V_254 , L_148 ,
L_149 ) ,
F_94 ( 0 , L_150 , & V_130 . V_255 , L_151 ,
L_152 ) ,
F_93 ( 0 , L_153 , & V_130 . V_256 ,
L_154 ) ,
F_93 ( 0 , L_155 , & V_130 . V_257 ,
L_156 ) ,
F_94 ( 'M' , L_157 , & V_258 , L_158 ,
L_159 ) ,
F_98 ()
} ;
V_7 . V_75 = F_99 ( NULL , NULL ) ;
if ( V_7 . V_75 == NULL )
return - V_209 ;
V_130 . V_259 = false ;
V_236 = F_100 ( V_236 , V_237 , V_242 , V_260 , 0 ) ;
if ( V_236 )
F_101 ( V_260 , V_242 ) ;
if ( V_250 == V_261 )
V_250 = L_160 ;
F_102 ( V_260 , V_242 ) ;
if ( V_7 . V_249 )
V_30 = 0 ;
else if ( V_7 . V_248 )
V_30 = 1 ;
F_103 ( false ) ;
if ( V_7 . V_211 > 0 && V_7 . V_246 ) {
printf ( L_161 ) ;
F_8 ( 1 ) ;
V_7 . V_246 = NULL ;
}
if ( V_7 . V_240 != - 1 )
V_7 . V_211 = V_7 . V_240 ;
if ( F_104 ( V_7 . V_75 , V_7 . V_240 ,
V_7 . V_211 , V_7 . V_246 ) < 0 )
F_101 ( V_260 , V_242 ) ;
if ( ! V_7 . V_75 -> V_76 &&
F_105 ( V_7 . V_75 ) < 0 ) {
F_7 ( L_162 ) ;
return - V_209 ;
}
V_130 . V_54 = V_7 . V_75 -> V_76 ;
if ( V_7 . V_74 < 1 )
V_7 . V_74 = 1 ;
if ( V_7 . V_244 )
V_7 . V_171 = 0 ;
else if ( V_7 . V_171 ) {
V_7 . V_244 = V_7 . V_171 ;
} else {
fprintf ( V_73 , L_163 ) ;
exit ( V_262 ) ;
}
F_49 (pos, &top.evlist->entries, node) {
if ( ! V_238 -> V_164 . V_263 )
V_238 -> V_164 . V_263 = V_7 . V_244 ;
}
V_7 . V_34 = F_50 ( V_7 . V_75 -> V_72 . V_71 , struct V_38 , V_102 ) ;
V_130 . V_264 = sizeof( struct V_15 ) ;
V_130 . V_265 = ( V_130 . V_138 == NULL ) ;
if ( F_106 () < 0 )
return - 1 ;
F_107 ( & V_266 , V_130 . V_267 , L_164 , stdout ) ;
F_107 ( & V_268 , V_130 . V_269 , L_165 , stdout ) ;
F_107 ( & V_270 , V_130 . V_271 , L_166 , stdout ) ;
V_7 . V_144 = V_270 . V_272 . V_71 != NULL ;
F_1 ( & V_7 . V_1 ) ;
if ( V_7 . V_8 == 0 ) {
struct V_95 V_96 = {
. V_97 = F_5 ,
. V_98 = V_99 ,
} ;
F_4 ( & V_7 ) ;
V_95 ( V_100 , & V_96 , NULL ) ;
}
V_239 = F_81 ( & V_7 ) ;
F_108 ( V_7 . V_75 ) ;
return V_239 ;
}
