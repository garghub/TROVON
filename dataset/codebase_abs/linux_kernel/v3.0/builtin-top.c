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
if ( ! V_10 )
return - 1 ;
V_12 = F_7 ( V_10 ) ;
V_15 = V_10 -> V_15 ;
if ( V_15 -> V_17 -> V_18 == V_19 ) {
F_8 ( L_3
L_4 , V_12 -> V_20 ) ;
F_9 ( 1 ) ;
return - 1 ;
}
V_14 = F_10 ( V_12 ) ;
if ( V_14 -> V_21 != NULL ) {
F_11 ( & V_14 -> V_22 ) ;
goto V_23;
}
F_11 ( & V_14 -> V_22 ) ;
if ( F_12 ( V_12 , V_6 . V_24 -> V_25 ) < 0 ) {
F_13 ( & V_14 -> V_22 ) ;
F_8 ( L_5 ,
V_12 -> V_20 ) ;
F_9 ( 1 ) ;
return V_16 ;
}
V_16 = F_14 ( V_12 , V_10 -> V_15 , 0 ) ;
if ( V_16 == 0 ) {
V_23:
V_6 . V_26 = V_10 ;
}
F_13 ( & V_14 -> V_22 ) ;
return V_16 ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
F_16 ( V_12 ) ;
}
static void F_17 ( struct V_9 * V_10 , int V_27 , T_2 V_28 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
if ( V_10 != V_6 . V_26 )
return;
V_12 = F_7 ( V_10 ) ;
V_14 = F_10 ( V_12 ) ;
if ( F_18 ( & V_14 -> V_22 ) )
return;
V_28 = V_10 -> V_15 -> V_29 ( V_10 -> V_15 , V_28 ) ;
F_19 ( V_12 , V_10 -> V_15 , V_27 , V_28 ) ;
F_13 ( & V_14 -> V_22 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
struct V_11 * V_11 ;
int V_30 ;
if ( ! V_10 )
return;
V_11 = F_7 ( V_10 ) ;
V_14 = F_10 ( V_11 ) ;
F_11 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_21 == NULL )
goto V_31;
printf ( L_6 , F_21 ( V_6 . V_32 ) , V_11 -> V_20 ) ;
printf ( L_7 , V_33 ) ;
V_30 = F_22 ( V_11 , V_10 -> V_15 , V_6 . V_32 -> V_34 ,
0 , V_33 , V_6 . V_7 , 4 ) ;
if ( V_6 . V_35 )
F_23 ( V_11 , V_6 . V_32 -> V_34 ) ;
else
F_24 ( V_11 , V_6 . V_32 -> V_34 ) ;
if ( V_30 != 0 )
printf ( L_8 , V_30 ) ;
V_31:
F_13 ( & V_14 -> V_22 ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
F_26 ( & V_10 -> V_36 , & V_6 . V_37 ) ;
}
static void F_27 ( struct V_38 * V_39 )
{
char V_40 [ 160 ] ;
int V_41 = 0 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
struct V_44 V_45 = V_46 ;
const int V_47 = V_1 . V_5 - 1 ;
int V_48 , V_49 , V_50 ;
float V_51 = F_28 ( & V_6 , & V_45 ) ;
puts ( V_52 ) ;
F_29 ( & V_6 , V_40 , sizeof( V_40 ) ) ;
printf ( L_9 , V_40 ) ;
F_30 ( & V_6 ) ;
printf ( L_10 , V_47 , V_47 , V_53 ) ;
if ( V_39 -> V_54 . V_55 . V_56 != 0 ) {
F_31 ( stdout , V_57 , L_11 ) ;
printf ( L_12 V_58 L_13 ,
V_39 -> V_54 . V_55 . V_56 ) ;
}
if ( V_6 . V_26 ) {
F_20 ( V_6 . V_26 ) ;
return;
}
F_32 ( & V_6 , & V_45 , & V_49 , & V_50 ,
& V_48 ) ;
if ( V_48 + V_49 > V_1 . V_5 - 29 ) {
V_49 = V_50 ;
if ( V_48 + V_49 > V_1 . V_5 - 29 )
V_48 = V_1 . V_5 - V_49 - 29 ;
}
putchar ( '\n' ) ;
if ( V_6 . V_24 -> V_25 == 1 )
printf ( L_14 ) ;
else
printf ( L_15 ) ;
if ( V_59 )
printf ( L_16 ) ;
printf ( L_17 , V_48 , V_48 , L_18 ) ;
printf ( L_19 ,
V_6 . V_24 -> V_25 == 1 ? L_20 : L_21 ) ;
if ( V_59 )
printf ( L_22 ) ;
printf ( L_23 , V_48 , V_48 , V_60 ) ;
printf ( L_23 , V_49 , V_49 , V_60 ) ;
puts ( L_24 ) ;
for ( V_43 = F_33 ( & V_45 ) ; V_43 ; V_43 = F_34 ( V_43 ) ) {
struct V_11 * V_12 ;
double V_61 ;
V_10 = F_35 ( V_43 , struct V_9 , V_42 ) ;
V_12 = F_7 ( V_10 ) ;
if ( ++ V_41 > V_6 . V_7 ||
( int ) V_10 -> V_62 < V_6 . V_63 )
continue;
V_61 = 100.0 - ( 100.0 * ( ( V_51 - V_10 -> V_62 ) /
V_51 ) ) ;
if ( V_6 . V_24 -> V_25 == 1 || ! V_6 . V_64 )
printf ( L_25 , V_10 -> V_65 ) ;
else
printf ( L_26 , V_10 -> V_65 , V_10 -> V_62 ) ;
F_36 ( stdout , L_27 , V_61 ) ;
if ( V_59 )
printf ( L_28 V_66 , V_12 -> V_67 ) ;
printf ( L_23 , V_48 , V_48 , V_12 -> V_20 ) ;
printf ( L_29 , V_49 , V_49 ,
V_49 >= V_10 -> V_15 -> V_17 -> V_68 ?
V_10 -> V_15 -> V_17 -> V_69 :
V_10 -> V_15 -> V_17 -> V_70 ) ;
}
}
static void F_37 ( int * V_71 , const char * V_72 )
{
char * V_73 = malloc ( 0 ) , * V_74 ;
T_3 V_75 = 0 ;
int V_45 ;
fprintf ( stdout , L_30 , V_72 ) ;
if ( F_38 ( & V_73 , & V_75 , V_76 ) < 0 )
return;
V_74 = strchr ( V_73 , '\n' ) ;
if ( V_74 )
* V_74 = 0 ;
V_74 = V_73 ;
while( * V_74 ) {
if ( ! isdigit ( * V_74 ) )
goto V_77;
V_74 ++ ;
}
V_45 = strtoul ( V_73 , NULL , 10 ) ;
* V_71 = V_45 ;
V_77:
free ( V_73 ) ;
}
static void F_39 ( int * V_71 , const char * V_72 )
{
int V_45 = 0 ;
F_37 ( & V_45 , V_72 ) ;
if ( V_45 >= 0 && V_45 <= 100 )
* V_71 = V_45 ;
}
static void F_40 ( struct V_9 * * V_71 , const char * V_72 )
{
char * V_73 = malloc ( 0 ) , * V_74 ;
struct V_9 * V_10 = * V_71 , * V_78 , * V_79 = NULL ;
T_3 V_75 = 0 ;
if ( V_10 ) {
F_15 ( V_10 ) ;
* V_71 = NULL ;
}
fprintf ( stdout , L_30 , V_72 ) ;
if ( F_38 ( & V_73 , & V_75 , V_76 ) < 0 )
goto V_77;
V_74 = strchr ( V_73 , '\n' ) ;
if ( V_74 )
* V_74 = 0 ;
F_11 ( & V_6 . V_80 ) ;
V_10 = F_41 ( V_6 . V_37 . V_81 , struct V_9 , V_36 ) ;
F_13 ( & V_6 . V_80 ) ;
F_42 (syme, n, &top.active_symbols, node) {
struct V_11 * V_12 = F_7 ( V_10 ) ;
if ( ! strcmp ( V_73 , V_12 -> V_20 ) ) {
V_79 = V_10 ;
break;
}
}
if ( ! V_79 ) {
fprintf ( V_82 , L_31 , V_73 ) ;
F_9 ( 1 ) ;
return;
} else
F_6 ( V_79 ) ;
V_77:
free ( V_73 ) ;
}
static void F_43 ( void )
{
char * V_20 = NULL ;
if ( V_6 . V_26 ) {
struct V_11 * V_12 = F_7 ( V_6 . V_26 ) ;
V_20 = V_12 -> V_20 ;
}
fprintf ( stdout , L_32 ) ;
fprintf ( stdout , L_33 , V_6 . V_83 ) ;
fprintf ( stdout , L_34 , V_6 . V_7 ) ;
if ( V_6 . V_24 -> V_25 > 1 )
fprintf ( stdout , L_35 , F_21 ( V_6 . V_32 ) ) ;
fprintf ( stdout , L_36 , V_6 . V_63 ) ;
fprintf ( stdout , L_37 , V_33 ) ;
fprintf ( stdout , L_38 , V_20 ? : L_39 ) ;
fprintf ( stdout , L_40 ) ;
if ( V_6 . V_24 -> V_25 > 1 )
fprintf ( stdout , L_41 , V_6 . V_64 ? 1 : 0 ) ;
fprintf ( stdout ,
L_42 ,
V_6 . V_84 ? L_43 : L_44 ) ;
fprintf ( stdout ,
L_45 ,
V_6 . V_85 ? L_43 : L_44 ) ;
fprintf ( stdout , L_46 , V_6 . V_35 ? 1 : 0 ) ;
fprintf ( stdout , L_47 ) ;
}
static int F_44 ( int V_86 )
{
switch ( V_86 ) {
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
case 'w' :
return V_6 . V_24 -> V_25 > 1 ? 1 : 0 ;
default:
break;
}
return 0 ;
}
static void F_45 ( struct V_38 * V_39 , int V_86 )
{
if ( ! F_44 ( V_86 ) ) {
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 , V_94 ;
F_43 () ;
fprintf ( stdout , L_48 ) ;
fflush ( stdout ) ;
F_46 ( 0 , & V_94 ) ;
V_93 = V_94 ;
V_93 . V_95 &= ~ ( V_96 | V_97 ) ;
V_93 . V_98 [ V_99 ] = 0 ;
V_93 . V_98 [ V_100 ] = 0 ;
F_47 ( 0 , V_101 , & V_93 ) ;
F_48 ( & V_88 , 1 , - 1 ) ;
V_86 = getc ( V_76 ) ;
F_47 ( 0 , V_102 , & V_94 ) ;
if ( ! F_44 ( V_86 ) )
return;
}
switch ( V_86 ) {
case 'd' :
F_37 ( & V_6 . V_83 , L_49 ) ;
if ( V_6 . V_83 < 1 )
V_6 . V_83 = 1 ;
break;
case 'e' :
F_37 ( & V_6 . V_7 , L_50 ) ;
if ( V_6 . V_7 == 0 ) {
F_5 ( V_103 ) ;
signal ( V_103 , F_5 ) ;
} else
signal ( V_103 , V_104 ) ;
break;
case 'E' :
if ( V_6 . V_24 -> V_25 > 1 ) {
int V_27 = 0 ;
fprintf ( V_82 , L_51 ) ;
F_49 (top.sym_evsel, &top.evlist->entries, node)
fprintf ( V_82 , L_52 , V_6 . V_32 -> V_34 , F_21 ( V_6 . V_32 ) ) ;
F_37 ( & V_27 , L_53 ) ;
if ( V_27 >= V_6 . V_24 -> V_25 ) {
V_6 . V_32 = F_41 ( V_6 . V_24 -> V_105 . V_81 , struct V_106 , V_36 ) ;
fprintf ( V_82 , L_54 , F_21 ( V_6 . V_32 ) ) ;
F_9 ( 1 ) ;
break;
}
F_49 (top.sym_evsel, &top.evlist->entries, node)
if ( V_6 . V_32 -> V_34 == V_27 )
break;
} else
V_6 . V_32 = F_41 ( V_6 . V_24 -> V_105 . V_81 , struct V_106 , V_36 ) ;
break;
case 'f' :
F_37 ( & V_6 . V_63 , L_55 ) ;
break;
case 'F' :
F_39 ( & V_33 , L_56 ) ;
break;
case 'K' :
V_6 . V_84 = ! V_6 . V_84 ;
break;
case 'q' :
case 'Q' :
printf ( L_57 ) ;
if ( V_107 )
F_50 ( V_39 , V_82 ) ;
exit ( 0 ) ;
case 's' :
F_40 ( & V_6 . V_26 , L_58 ) ;
break;
case 'S' :
if ( ! V_6 . V_26 )
break;
else {
struct V_9 * V_10 = V_6 . V_26 ;
V_6 . V_26 = NULL ;
F_15 ( V_10 ) ;
}
break;
case 'U' :
V_6 . V_85 = ! V_6 . V_85 ;
break;
case 'w' :
V_6 . V_64 = ~ V_6 . V_64 ;
break;
case 'z' :
V_6 . V_35 = ! V_6 . V_35 ;
break;
default:
break;
}
}
static void * F_51 ( void * T_4 V_8 )
{
int V_16 = 0 ;
F_11 ( & V_6 . V_80 ) ;
while ( F_52 ( & V_6 . V_37 ) ) {
V_16 = F_53 ( & V_6 . V_108 ,
& V_6 . V_80 ) ;
if ( V_16 )
break;
}
F_13 ( & V_6 . V_80 ) ;
if ( ! V_16 )
F_54 ( & V_6 ) ;
F_55 ( 0 ) ;
exit ( 0 ) ;
return NULL ;
}
static void * F_56 ( void * T_4 V_8 )
{
struct V_87 V_88 = { . V_89 = 0 , . V_90 = V_91 } ;
struct V_92 V_93 , V_94 ;
int V_109 , V_86 ;
struct V_38 * V_39 = (struct V_38 * ) T_4 ;
F_46 ( 0 , & V_94 ) ;
V_93 = V_94 ;
V_93 . V_95 &= ~ ( V_96 | V_97 ) ;
V_93 . V_98 [ V_99 ] = 0 ;
V_93 . V_98 [ V_100 ] = 0 ;
V_110:
V_109 = V_6 . V_83 * 1000 ;
F_47 ( 0 , V_101 , & V_93 ) ;
getc ( V_76 ) ;
do {
F_27 ( V_39 ) ;
} while ( ! F_48 ( & V_88 , 1 , V_109 ) == 1 );
V_86 = getc ( V_76 ) ;
F_47 ( 0 , V_102 , & V_94 ) ;
F_45 ( V_39 , V_86 ) ;
goto V_110;
return NULL ;
}
static int F_57 ( struct V_15 * V_15 , struct V_11 * V_12 )
{
struct V_9 * V_10 ;
const char * V_20 = V_12 -> V_20 ;
int V_111 ;
if ( V_20 [ 0 ] == '.' )
V_20 ++ ;
if ( ! strcmp ( V_20 , L_59 ) ||
! strcmp ( V_20 , L_60 ) ||
! strcmp ( V_20 , L_61 ) ||
! strncmp ( L_62 , V_20 , 11 ) ||
! strncmp ( L_63 , V_20 , 14 ) ||
strstr ( V_20 , L_64 ) ||
strstr ( V_20 , L_65 ) )
return 1 ;
V_10 = F_58 ( V_12 ) ;
V_10 -> V_15 = V_15 ;
F_59 ( V_15 , V_12 ) ;
if ( ! V_6 . V_26 && V_112 && ! strcmp ( V_20 , V_112 ) ) {
V_113 = V_10 ;
V_112 = NULL ;
}
for ( V_111 = 0 ; V_114 [ V_111 ] ; V_111 ++ ) {
if ( ! strcmp ( V_114 [ V_111 ] , V_20 ) ) {
V_12 -> V_115 = true ;
break;
}
}
return 0 ;
}
static void F_60 ( const union V_116 * V_117 ,
struct V_118 * V_119 ,
struct V_38 * V_39 )
{
T_2 V_28 = V_117 -> V_28 . V_28 ;
struct V_9 * V_10 ;
struct V_120 V_121 ;
struct V_122 * V_122 ;
T_5 V_123 = V_117 -> V_124 . V_125 & V_126 ;
++ V_6 . V_127 ;
switch ( V_123 ) {
case V_128 :
++ V_6 . V_129 ;
if ( V_6 . V_85 )
return;
V_122 = F_61 ( V_39 ) ;
break;
case V_130 :
++ V_6 . V_131 ;
if ( V_6 . V_84 )
return;
V_122 = F_61 ( V_39 ) ;
break;
case V_132 :
++ V_6 . V_133 ;
V_122 = F_62 ( V_39 , V_117 -> V_28 . V_134 ) ;
break;
case V_135 :
++ V_6 . V_136 ;
return;
default:
return;
}
if ( ! V_122 && V_137 ) {
F_8 ( L_66 ,
V_117 -> V_28 . V_134 ) ;
return;
}
if ( V_117 -> V_124 . V_125 & V_138 )
V_6 . V_139 ++ ;
if ( F_63 ( V_117 , V_39 , & V_121 , V_119 ,
F_57 ) < 0 ||
V_121 . V_140 )
return;
if ( ! V_141 &&
V_142 . V_143 &&
V_121 . V_144 == V_130 ) {
F_64 (
L_67
L_68
L_69 ,
! F_65 ( & V_121 . V_15 -> V_17 -> V_145 [ V_146 ] ) ?
L_70 : L_71 ) ;
if ( V_147 <= 0 )
F_9 ( 5 ) ;
V_141 = true ;
}
if ( V_121 . V_12 == NULL ) {
const char * V_72 = L_72 ;
if ( ! V_141 && ! V_148 &&
V_121 . V_15 == V_122 -> V_149 [ V_146 ] &&
F_65 ( & V_121 . V_15 -> V_17 -> V_145 [ V_146 ] ) ) {
if ( V_142 . V_150 ) {
F_64 ( L_73 ,
V_142 . V_150 , V_72 ) ;
} else {
F_64 ( L_74 ,
V_72 ) ;
}
if ( V_147 <= 0 )
F_9 ( 5 ) ;
V_148 = true ;
}
return;
}
if ( V_113 ) {
V_6 . V_26 = V_113 ;
V_113 = NULL ;
if ( F_6 ( V_6 . V_26 ) < 0 ) {
struct V_11 * V_12 = F_7 ( V_6 . V_26 ) ;
F_8 ( L_75 , V_12 -> V_20 ) ;
if ( V_6 . V_26 -> V_15 -> V_17 -> V_18 == V_19 ) {
F_8 ( L_76 ) ;
F_66 ( V_122 , V_82 ) ;
} else
F_8 ( L_77 ) ;
exit ( 1 ) ;
}
}
V_10 = F_58 ( V_121 . V_12 ) ;
if ( ! V_121 . V_12 -> V_115 ) {
struct V_106 * V_151 ;
V_151 = F_67 ( V_6 . V_24 , V_119 -> V_152 ) ;
assert ( V_151 != NULL ) ;
V_10 -> V_153 [ V_151 -> V_34 ] ++ ;
F_17 ( V_10 , V_151 -> V_34 , V_28 ) ;
F_11 ( & V_6 . V_80 ) ;
if ( F_52 ( & V_10 -> V_36 ) || ! V_10 -> V_36 . V_81 ) {
static bool V_154 = true ;
F_25 ( V_10 ) ;
if ( V_154 ) {
F_68 ( & V_6 . V_108 ) ;
V_154 = false ;
}
}
F_13 ( & V_6 . V_80 ) ;
}
}
static void F_69 ( struct V_38 * V_155 , int V_34 )
{
struct V_118 V_119 ;
union V_116 * V_117 ;
int V_156 ;
while ( ( V_117 = F_70 ( V_6 . V_24 , V_34 ) ) != NULL ) {
V_156 = F_71 ( V_155 , V_117 , & V_119 ) ;
if ( V_156 ) {
F_8 ( L_78 , V_156 ) ;
continue;
}
if ( V_117 -> V_124 . type == V_157 )
F_60 ( V_117 , & V_119 , V_155 ) ;
else
F_72 ( V_117 , & V_119 , V_155 ) ;
}
}
static void F_73 ( struct V_38 * V_155 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_6 . V_24 -> V_158 ; V_111 ++ )
F_69 ( V_155 , V_111 ) ;
}
static void F_74 ( struct V_159 * V_24 )
{
struct V_106 * V_27 ;
F_49 (counter, &evlist->entries, node) {
struct V_160 * V_161 = & V_27 -> V_161 ;
V_161 -> V_162 = V_163 | V_164 ;
if ( V_6 . V_165 ) {
V_161 -> V_162 |= V_166 ;
V_161 -> V_165 = 1 ;
V_161 -> V_167 = V_6 . V_165 ;
}
if ( V_24 -> V_25 > 1 ) {
V_161 -> V_162 |= V_168 ;
V_161 -> V_169 |= V_170 ;
}
V_161 -> V_171 = 1 ;
V_161 -> V_172 = V_172 ;
V_173:
if ( F_75 ( V_27 , V_6 . V_24 -> V_174 ,
V_6 . V_24 -> V_175 , V_176 ) < 0 ) {
int V_16 = V_177 ;
if ( V_16 == V_178 || V_16 == V_179 ) {
F_76 () ;
goto V_180;
}
if ( V_161 -> type == V_181 &&
V_161 -> V_182 == V_183 ) {
if ( V_59 )
F_64 ( L_79
L_80 ) ;
V_161 -> type = V_184 ;
V_161 -> V_182 = V_185 ;
goto V_173;
}
if ( V_16 == V_186 ) {
F_64 ( L_81 ,
F_21 ( V_27 ) ) ;
goto V_180;
}
F_64 ( L_82
L_83
L_84
L_85
L_86 , V_16 , strerror ( V_16 ) ) ;
goto V_180;
}
}
if ( F_77 ( V_24 , V_187 , false ) < 0 ) {
F_64 ( L_87 ,
V_177 , strerror ( V_177 ) ) ;
goto V_180;
}
return;
V_180:
F_55 ( 0 ) ;
exit ( 0 ) ;
}
static int F_78 ( void )
{
T_6 V_188 ;
int V_156 V_8 ;
struct V_38 * V_39 = F_79 ( NULL , V_189 , false , false , NULL ) ;
if ( V_39 == NULL )
return - V_190 ;
if ( V_6 . V_191 != - 1 )
F_80 ( V_6 . V_24 -> V_175 ,
F_72 , V_39 ) ;
else
F_81 ( F_72 , V_39 ) ;
F_74 ( V_6 . V_24 ) ;
V_39 -> V_24 = V_6 . V_24 ;
F_82 ( V_39 ) ;
F_48 ( V_6 . V_24 -> V_87 , V_6 . V_24 -> V_192 , 100 ) ;
F_73 ( V_39 ) ;
if ( F_83 ( & V_188 , NULL , ( V_147 > 0 ? F_51 :
F_56 ) , V_39 ) ) {
printf ( L_88 ) ;
exit ( - 1 ) ;
}
if ( V_193 ) {
struct V_194 V_195 ;
V_195 . V_196 = V_193 ;
if ( F_84 ( 0 , V_197 , & V_195 ) ) {
printf ( L_89 ) ;
exit ( - 1 ) ;
}
}
while ( 1 ) {
T_2 V_198 = V_6 . V_127 ;
F_73 ( V_39 ) ;
if ( V_198 == V_6 . V_127 )
V_156 = F_48 ( V_6 . V_24 -> V_87 , V_6 . V_24 -> V_192 , 100 ) ;
}
return 0 ;
}
int F_85 ( int V_199 , const char * * V_200 , const char * T_7 V_8 )
{
struct V_106 * V_201 ;
int V_202 = - V_190 ;
V_6 . V_24 = F_86 ( NULL , NULL ) ;
if ( V_6 . V_24 == NULL )
return - V_190 ;
V_203 = F_87 ( V_204 ) ;
V_199 = F_88 ( V_199 , V_200 , V_205 , V_206 , 0 ) ;
if ( V_199 )
F_89 ( V_206 , V_205 ) ;
V_147 = 0 ;
if ( V_207 )
V_147 = 0 ;
else if ( V_208 )
V_147 = 1 ;
F_90 ( false ) ;
if ( V_6 . V_191 > 0 && V_6 . V_209 ) {
printf ( L_90 ) ;
F_9 ( 1 ) ;
V_6 . V_209 = NULL ;
}
if ( V_6 . V_210 != - 1 )
V_6 . V_191 = V_6 . V_210 ;
if ( F_91 ( V_6 . V_24 , V_6 . V_210 ,
V_6 . V_191 , V_6 . V_209 ) < 0 )
F_89 ( V_206 , V_205 ) ;
if ( ! V_6 . V_24 -> V_25 &&
F_92 ( V_6 . V_24 ) < 0 ) {
F_8 ( L_91 ) ;
return - V_190 ;
}
if ( V_6 . V_83 < 1 )
V_6 . V_83 = 1 ;
if ( V_211 )
V_6 . V_165 = 0 ;
else if ( V_6 . V_165 ) {
V_211 = V_6 . V_165 ;
} else {
fprintf ( V_82 , L_92 ) ;
exit ( V_212 ) ;
}
F_49 (pos, &top.evlist->entries, node) {
if ( F_93 ( V_201 , V_6 . V_24 -> V_174 -> V_213 ,
V_6 . V_24 -> V_175 -> V_213 ) < 0 )
goto V_214;
if ( V_201 -> V_161 . V_215 )
continue;
V_201 -> V_161 . V_215 = V_211 ;
}
if ( F_94 ( V_6 . V_24 ) < 0 ||
F_95 ( V_6 . V_24 ) < 0 )
goto V_214;
V_6 . V_32 = F_41 ( V_6 . V_24 -> V_105 . V_81 , struct V_106 , V_36 ) ;
V_142 . V_216 = ( sizeof( struct V_9 ) + sizeof( struct V_13 ) +
( V_6 . V_24 -> V_25 + 1 ) * sizeof( unsigned long ) ) ;
V_142 . V_217 = ( V_142 . V_150 == NULL ) ;
if ( F_96 () < 0 )
return - 1 ;
F_1 ( & V_1 ) ;
if ( V_6 . V_7 == 0 ) {
F_4 ( & V_1 ) ;
signal ( V_103 , F_5 ) ;
}
V_202 = F_78 () ;
V_214:
F_97 ( V_6 . V_24 ) ;
return V_202 ;
}
