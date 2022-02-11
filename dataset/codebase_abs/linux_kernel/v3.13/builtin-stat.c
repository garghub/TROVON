static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + 1000000000L - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static inline struct V_7 * F_2 ( struct V_8 * V_9 )
{
return ( V_9 -> V_10 && ! V_11 . V_12 ) ? V_9 -> V_10 : V_13 -> V_10 ;
}
static inline int F_3 ( struct V_8 * V_9 )
{
return F_2 ( V_9 ) -> V_14 ;
}
static void F_4 ( struct V_8 * V_9 )
{
memset ( V_9 -> V_15 , 0 , sizeof( struct V_16 ) ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
V_9 -> V_15 = F_6 ( sizeof( struct V_16 ) ) ;
return V_9 -> V_15 == NULL ? - V_17 : 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
free ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
static int F_8 ( struct V_8 * V_9 )
{
void * V_18 ;
T_1 V_19 ;
V_19 = sizeof( * V_9 -> V_20 ) +
( F_3 ( V_9 ) * sizeof( struct V_21 ) ) ;
V_18 = F_6 ( V_19 ) ;
if ( ! V_18 )
return - V_17 ;
V_9 -> V_22 = V_18 ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 )
{
free ( V_9 -> V_22 ) ;
V_9 -> V_22 = NULL ;
}
static void F_10 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
F_7 ( V_9 ) ;
F_12 ( V_9 ) ;
F_9 ( V_9 ) ;
}
}
static int F_13 ( struct V_23 * V_24 , bool V_25 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
if ( F_5 ( V_9 ) < 0 ||
F_14 ( V_9 , F_3 ( V_9 ) ) < 0 ||
( V_25 && F_8 ( V_9 ) < 0 ) )
goto V_26;
}
return 0 ;
V_26:
F_10 ( V_24 ) ;
return - 1 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
F_4 ( V_9 ) ;
F_16 ( V_9 , F_3 ( V_9 ) ) ;
}
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_38 , 0 ,
sizeof( V_38 ) ) ;
memset ( V_39 , 0 ,
sizeof( V_39 ) ) ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_42 * V_43 = & V_9 -> V_43 ;
if ( V_44 )
V_43 -> V_45 = V_46 |
V_47 ;
V_43 -> V_48 = ! V_49 ;
if ( F_18 ( & V_11 ) )
return F_19 ( V_9 , F_2 ( V_9 ) ) ;
if ( ! F_20 ( & V_11 ) && F_21 ( V_9 ) ) {
V_43 -> V_50 = 1 ;
if ( ! V_51 )
V_43 -> V_52 = 1 ;
}
return F_22 ( V_9 , V_13 -> V_53 ) ;
}
static inline int F_23 ( struct V_8 * V_9 )
{
if ( F_24 ( V_9 , V_54 , V_55 ) ||
F_24 ( V_9 , V_54 , V_56 ) )
return 1 ;
return 0 ;
}
static struct V_8 * F_25 ( int V_57 )
{
static struct V_8 * * V_58 ;
static int V_59 ;
struct V_8 * V_60 ;
int V_61 ;
if ( ! V_58 ) {
F_11 (ev, &evsel_list->entries, node)
V_59 ++ ;
V_58 = malloc ( V_59 * sizeof( void * ) ) ;
if ( ! V_58 )
exit ( V_17 ) ;
V_61 = 0 ;
F_11 (ev, &evsel_list->entries, node)
V_58 [ V_61 ++ ] = V_60 ;
}
if ( V_57 < V_59 )
return V_58 [ V_57 ] ;
return NULL ;
}
static void F_26 ( struct V_8 * V_62 , T_2 * V_63 )
{
if ( F_24 ( V_62 , V_54 , V_56 ) )
F_27 ( & V_27 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_64 , V_65 ) )
F_27 ( & V_28 [ 0 ] , V_63 [ 0 ] ) ;
else if ( V_66 &&
F_28 ( V_62 , F_25 ( V_67 ) ) )
F_27 ( & V_38 [ 0 ] , V_63 [ 0 ] ) ;
else if ( V_66 &&
F_28 ( V_62 , F_25 ( V_68 ) ) )
F_27 ( & V_39 [ 0 ] , V_63 [ 0 ] ) ;
else if ( V_66 &&
F_28 ( V_62 , F_25 ( V_69 ) ) )
F_27 ( & V_40 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_64 , V_70 ) )
F_27 ( & V_29 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_64 , V_71 ) )
F_27 ( & V_30 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_64 , V_72 ) )
F_27 ( & V_31 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_64 , V_73 ) )
F_27 ( & V_32 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_74 , V_75 ) )
F_27 ( & V_33 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_74 , V_76 ) )
F_27 ( & V_34 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_74 , V_77 ) )
F_27 ( & V_35 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_74 , V_78 ) )
F_27 ( & V_37 [ 0 ] , V_63 [ 0 ] ) ;
else if ( F_24 ( V_62 , V_74 , V_79 ) )
F_27 ( & V_36 [ 0 ] , V_63 [ 0 ] ) ;
}
static int F_29 ( struct V_8 * V_62 )
{
struct V_16 * V_80 = V_62 -> V_15 ;
T_2 * V_63 = V_62 -> V_20 -> V_81 . V_82 ;
int V_83 ;
if ( F_30 ( V_62 , F_3 ( V_62 ) ,
F_31 ( V_13 -> V_53 ) , V_44 ) < 0 )
return - 1 ;
for ( V_83 = 0 ; V_83 < 3 ; V_83 ++ )
F_27 ( & V_80 -> V_84 [ V_83 ] , V_63 [ V_83 ] ) ;
if ( V_85 ) {
fprintf ( V_86 , L_1 V_87 L_2 V_87 L_2 V_87 L_3 ,
F_32 ( V_62 ) , V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] ) ;
}
F_26 ( V_62 , V_63 ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_62 )
{
T_2 * V_63 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_62 ) ; V_88 ++ ) {
if ( F_34 ( V_62 , V_88 , 0 , V_44 ) < 0 )
return - 1 ;
V_63 = V_62 -> V_20 -> V_88 [ V_88 ] . V_82 ;
F_26 ( V_62 , V_63 ) ;
}
return 0 ;
}
static void F_35 ( void )
{
static int V_89 ;
struct V_8 * V_62 ;
struct V_16 * V_80 ;
struct V_1 V_90 , V_91 ;
char V_92 [ 64 ] ;
if ( V_93 == V_94 ) {
F_11 (counter, &evsel_list->entries, node) {
V_80 = V_62 -> V_15 ;
memset ( V_80 -> V_84 , 0 , sizeof( V_80 -> V_84 ) ) ;
F_29 ( V_62 ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
V_80 = V_62 -> V_15 ;
memset ( V_80 -> V_84 , 0 , sizeof( V_80 -> V_84 ) ) ;
F_33 ( V_62 ) ;
}
}
F_36 ( V_95 , & V_90 ) ;
F_1 ( & V_91 , & V_90 , & V_96 ) ;
sprintf ( V_92 , L_4 , V_91 . V_5 , V_91 . V_6 , V_97 ) ;
if ( V_89 == 0 && ! V_98 ) {
switch ( V_93 ) {
case V_99 :
fprintf ( V_86 , L_5 ) ;
break;
case V_100 :
fprintf ( V_86 , L_6 ) ;
break;
case V_101 :
fprintf ( V_86 , L_7 ) ;
break;
case V_94 :
default:
fprintf ( V_86 , L_8 ) ;
}
}
if ( ++ V_89 == 25 )
V_89 = 0 ;
switch ( V_93 ) {
case V_100 :
case V_99 :
F_37 ( V_92 ) ;
break;
case V_101 :
F_11 (counter, &evsel_list->entries, node)
F_38 ( V_62 , V_92 ) ;
break;
case V_94 :
default:
F_11 (counter, &evsel_list->entries, node)
F_39 ( V_62 , V_92 ) ;
}
fflush ( V_86 ) ;
}
static void F_40 ( void )
{
struct V_8 * V_62 ;
if ( V_51 ) {
const int V_102 = F_41 ( V_13 -> V_10 ) ,
V_103 = F_31 ( V_13 -> V_53 ) ;
F_42 ( V_51 * 1000 ) ;
F_11 (counter, &evsel_list->entries, node)
F_43 ( V_62 , V_102 , V_103 ) ;
}
}
static int F_44 ( int V_104 , const char * * V_105 )
{
char V_106 [ 512 ] ;
unsigned long long V_107 , V_108 ;
struct V_8 * V_62 ;
struct V_1 V_90 ;
int V_109 = 0 ;
const bool V_110 = ( V_104 > 0 ) ;
if ( V_111 ) {
V_90 . V_5 = V_111 / 1000 ;
V_90 . V_6 = ( V_111 % 1000 ) * 1000000 ;
} else {
V_90 . V_5 = 1 ;
V_90 . V_6 = 0 ;
}
if ( V_110 ) {
if ( F_45 ( V_13 , & V_11 , V_105 ,
false , false ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
V_112 = V_13 -> V_113 . V_114 ;
}
if ( V_115 )
F_46 ( V_13 ) ;
F_11 (counter, &evsel_list->entries, node) {
if ( F_17 ( V_62 ) < 0 ) {
if ( V_116 == V_117 || V_116 == V_118 ||
V_116 == V_119 || V_116 == V_120 ||
V_116 == V_121 ) {
if ( V_85 )
F_47 ( L_10 ,
F_32 ( V_62 ) ) ;
V_62 -> V_122 = false ;
continue;
}
F_48 ( V_62 , & V_11 ,
V_116 , V_106 , sizeof( V_106 ) ) ;
F_49 ( L_11 , V_106 ) ;
if ( V_112 != - 1 )
F_50 ( V_112 , V_123 ) ;
return - 1 ;
}
V_62 -> V_122 = true ;
}
if ( F_51 ( V_13 ) ) {
error ( L_12 , V_116 ,
strerror ( V_116 ) ) ;
return - 1 ;
}
V_107 = F_52 () ;
F_36 ( V_95 , & V_96 ) ;
if ( V_110 ) {
F_53 ( V_13 ) ;
F_40 () ;
if ( V_111 ) {
while ( ! F_54 ( V_112 , & V_109 , V_124 ) ) {
F_55 ( & V_90 , NULL ) ;
F_35 () ;
}
}
F_56 ( & V_109 ) ;
if ( F_57 ( V_109 ) )
F_58 ( F_59 ( V_109 ) , V_105 [ 0 ] ) ;
} else {
F_40 () ;
while ( ! V_125 ) {
F_55 ( & V_90 , NULL ) ;
if ( V_111 )
F_35 () ;
}
}
V_108 = F_52 () ;
F_27 ( & V_41 , V_108 - V_107 ) ;
if ( V_93 == V_94 ) {
F_11 (counter, &evsel_list->entries, node) {
F_29 ( V_62 ) ;
F_60 ( V_62 , F_3 ( V_62 ) ,
F_31 ( V_13 -> V_53 ) ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
F_33 ( V_62 ) ;
F_60 ( V_62 , F_3 ( V_62 ) , 1 ) ;
}
}
return F_61 ( V_109 ) ;
}
static int F_62 ( int V_104 V_126 , const char * * V_105 )
{
int V_127 ;
if ( V_128 ) {
V_127 = system ( V_128 ) ;
if ( V_127 )
return V_127 ;
}
if ( V_129 )
F_63 () ;
V_127 = F_44 ( V_104 , V_105 ) ;
if ( V_127 )
return V_127 ;
if ( V_130 ) {
V_127 = system ( V_130 ) ;
if ( V_127 )
return V_127 ;
}
return V_127 ;
}
static void F_64 ( double V_131 , double V_132 )
{
double V_133 = F_65 ( V_131 , V_132 ) ;
if ( V_98 )
fprintf ( V_86 , L_13 , V_97 , V_133 ) ;
else if ( V_133 )
fprintf ( V_86 , L_14 , V_133 ) ;
}
static void F_66 ( struct V_8 * V_9 , double V_132 )
{
struct V_16 * V_80 ;
if ( V_134 == 1 )
return;
V_80 = V_9 -> V_15 ;
F_64 ( F_67 ( & V_80 -> V_84 [ 0 ] ) , V_132 ) ;
}
static void F_68 ( struct V_8 * V_9 , int V_135 , int V_14 )
{
switch ( V_93 ) {
case V_100 :
fprintf ( V_86 , L_15 ,
F_69 ( V_135 ) ,
V_98 ? 0 : - 8 ,
F_70 ( V_135 ) ,
V_97 ,
V_98 ? 0 : 4 ,
V_14 ,
V_97 ) ;
break;
case V_99 :
fprintf ( V_86 , L_16 ,
V_98 ? 0 : - 5 ,
V_135 ,
V_97 ,
V_98 ? 0 : 4 ,
V_14 ,
V_97 ) ;
break;
case V_101 :
fprintf ( V_86 , L_17 ,
V_98 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_136 [ V_135 ] , V_97 ) ;
break;
case V_94 :
default:
break;
}
}
static void F_71 ( int V_88 , int V_14 , struct V_8 * V_9 , double V_132 )
{
double V_137 = V_132 / 1e6 ;
const char * V_138 = V_98 ? L_18 : L_19 ;
char V_139 [ 25 ] ;
F_68 ( V_9 , V_88 , V_14 ) ;
F_72 ( V_139 , sizeof( V_139 ) , L_20 ,
F_32 ( V_9 ) , V_98 ? L_21 : L_22 ) ;
fprintf ( V_86 , V_138 , V_137 , V_97 , V_139 ) ;
if ( V_9 -> V_140 )
fprintf ( V_86 , L_20 , V_97 , V_9 -> V_140 -> V_139 ) ;
if ( V_98 || V_111 )
return;
if ( F_24 ( V_9 , V_54 , V_56 ) )
fprintf ( V_86 , L_23 ,
V_132 / F_73 ( & V_41 ) ) ;
else
fprintf ( V_86 , L_24 ) ;
}
static const char * F_74 ( enum V_141 type , double V_142 )
{
static const double V_143 [ V_144 ] [ 3 ] = {
[ V_145 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_146 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_147 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_148 = V_149 ;
if ( V_142 > V_143 [ type ] [ 0 ] )
V_148 = V_150 ;
else if ( V_142 > V_143 [ type ] [ 1 ] )
V_148 = V_151 ;
else if ( V_142 > V_143 [ type ] [ 2 ] )
V_148 = V_152 ;
return V_148 ;
}
static void F_75 ( int V_88 ,
struct V_8 * V_9
V_126 , double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_28 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_145 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_27 ) ;
}
static void F_77 ( int V_88 ,
struct V_8 * V_9
V_126 , double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_28 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_146 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_28 ) ;
}
static void F_78 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_31 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_29 ) ;
}
static void F_79 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_33 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_30 ) ;
}
static void F_80 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_34 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_31 ) ;
}
static void F_81 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_37 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_32 ) ;
}
static void F_82 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_36 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_33 ) ;
}
static void F_83 ( int V_88 ,
struct V_8 * V_9 V_126 ,
double V_132 )
{
double V_131 , V_142 = 0.0 ;
const char * V_148 ;
V_131 = F_73 ( & V_35 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 / V_131 * 100.0 ;
V_148 = F_74 ( V_147 , V_142 ) ;
fprintf ( V_86 , L_25 ) ;
F_76 ( V_86 , V_148 , L_26 , V_142 ) ;
fprintf ( V_86 , L_34 ) ;
}
static void F_84 ( int V_88 , int V_14 , struct V_8 * V_9 , double V_132 )
{
double V_131 , V_142 = 0.0 , V_153 ;
const char * V_138 ;
if ( V_98 )
V_138 = L_35 ;
else if ( V_154 )
V_138 = L_36 ;
else
V_138 = L_37 ;
F_68 ( V_9 , V_88 , V_14 ) ;
if ( V_93 == V_94 )
V_88 = 0 ;
fprintf ( V_86 , V_138 , V_132 , V_97 , F_32 ( V_9 ) ) ;
if ( V_9 -> V_140 )
fprintf ( V_86 , L_20 , V_97 , V_9 -> V_140 -> V_139 ) ;
if ( V_98 || V_111 )
return;
if ( F_24 ( V_9 , V_64 , V_155 ) ) {
V_131 = F_73 ( & V_28 [ V_88 ] ) ;
if ( V_131 ) {
V_142 = V_132 / V_131 ;
fprintf ( V_86 , L_38 , V_142 ) ;
}
V_131 = F_73 ( & V_29 [ V_88 ] ) ;
V_131 = F_85 ( V_131 , F_73 ( & V_30 [ V_88 ] ) ) ;
if ( V_131 && V_132 ) {
V_142 = V_131 / V_132 ;
fprintf ( V_86 , L_39 , V_142 ) ;
}
} else if ( F_24 ( V_9 , V_64 , V_156 ) &&
V_31 [ V_88 ] . V_57 != 0 ) {
F_78 ( V_88 , V_9 , V_132 ) ;
} else if (
V_9 -> V_43 . type == V_157 &&
V_9 -> V_43 . V_158 == ( V_159 |
( ( V_160 ) << 8 ) |
( ( V_161 ) << 16 ) ) &&
V_33 [ V_88 ] . V_57 != 0 ) {
F_79 ( V_88 , V_9 , V_132 ) ;
} else if (
V_9 -> V_43 . type == V_157 &&
V_9 -> V_43 . V_158 == ( V_162 |
( ( V_160 ) << 8 ) |
( ( V_161 ) << 16 ) ) &&
V_34 [ V_88 ] . V_57 != 0 ) {
F_80 ( V_88 , V_9 , V_132 ) ;
} else if (
V_9 -> V_43 . type == V_157 &&
V_9 -> V_43 . V_158 == ( V_163 |
( ( V_160 ) << 8 ) |
( ( V_161 ) << 16 ) ) &&
V_37 [ V_88 ] . V_57 != 0 ) {
F_81 ( V_88 , V_9 , V_132 ) ;
} else if (
V_9 -> V_43 . type == V_157 &&
V_9 -> V_43 . V_158 == ( V_164 |
( ( V_160 ) << 8 ) |
( ( V_161 ) << 16 ) ) &&
V_36 [ V_88 ] . V_57 != 0 ) {
F_82 ( V_88 , V_9 , V_132 ) ;
} else if (
V_9 -> V_43 . type == V_157 &&
V_9 -> V_43 . V_158 == ( V_165 |
( ( V_160 ) << 8 ) |
( ( V_161 ) << 16 ) ) &&
V_35 [ V_88 ] . V_57 != 0 ) {
F_83 ( V_88 , V_9 , V_132 ) ;
} else if ( F_24 ( V_9 , V_64 , V_166 ) &&
V_32 [ V_88 ] . V_57 != 0 ) {
V_131 = F_73 ( & V_32 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_132 * 100 / V_131 ;
fprintf ( V_86 , L_40 , V_142 ) ;
} else if ( F_24 ( V_9 , V_64 , V_70 ) ) {
F_75 ( V_88 , V_9 , V_132 ) ;
} else if ( F_24 ( V_9 , V_64 , V_71 ) ) {
F_77 ( V_88 , V_9 , V_132 ) ;
} else if ( F_24 ( V_9 , V_64 , V_65 ) ) {
V_131 = F_73 ( & V_27 [ V_88 ] ) ;
if ( V_131 ) {
V_142 = V_132 / V_131 ;
fprintf ( V_86 , L_41 , V_142 ) ;
}
} else if ( V_66 &&
F_28 ( V_9 , F_25 ( V_67 ) ) ) {
V_131 = F_73 ( & V_28 [ V_88 ] ) ;
if ( V_131 )
fprintf ( V_86 ,
L_42 ,
100.0 * ( V_132 / V_131 ) ) ;
} else if ( V_66 &&
F_28 ( V_9 , F_25 ( V_167 ) ) ) {
V_131 = F_73 ( & V_28 [ V_88 ] ) ;
V_153 = F_73 ( & V_38 [ V_88 ] ) ;
if ( V_153 < V_132 )
V_153 = V_132 ;
if ( V_131 )
fprintf ( V_86 ,
L_43 ,
100.0 * ( ( V_153 - V_132 ) / V_131 ) ) ;
} else if ( V_66 &&
F_28 ( V_9 , F_25 ( V_68 ) ) &&
V_132 > 0 &&
V_38 [ V_88 ] . V_57 != 0 ) {
V_131 = F_73 ( & V_38 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_131 / V_132 ;
fprintf ( V_86 , L_44 , V_142 ) ;
} else if ( V_66 &&
F_28 ( V_9 , F_25 ( V_69 ) ) &&
V_132 > 0 &&
V_38 [ V_88 ] . V_57 != 0 ) {
V_131 = F_73 ( & V_38 [ V_88 ] ) ;
if ( V_131 )
V_142 = V_131 / V_132 ;
fprintf ( V_86 , L_45 , V_142 ) ;
} else if ( V_27 [ V_88 ] . V_57 != 0 ) {
char V_168 = 'M' ;
V_131 = F_73 ( & V_27 [ V_88 ] ) ;
if ( V_131 )
V_142 = 1000.0 * V_132 / V_131 ;
if ( V_142 < 0.001 ) {
V_142 *= 1000 ;
V_168 = 'K' ;
}
fprintf ( V_86 , L_46 , V_142 , V_168 ) ;
} else {
fprintf ( V_86 , L_24 ) ;
}
}
static void F_37 ( char * V_92 )
{
struct V_8 * V_62 ;
int V_88 , V_169 , V_170 , V_171 , V_135 , V_14 ;
T_2 V_172 , V_173 , V_174 ;
if ( ! ( V_175 || V_176 ) )
return;
for ( V_170 = 0 ; V_170 < V_175 -> V_14 ; V_170 ++ ) {
V_135 = V_175 -> V_136 [ V_170 ] ;
F_11 (counter, &evsel_list->entries, node) {
V_174 = V_172 = V_173 = 0 ;
V_14 = 0 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_62 ) ; V_88 ++ ) {
V_169 = F_2 ( V_62 ) -> V_136 [ V_88 ] ;
V_171 = V_176 ( V_13 -> V_10 , V_169 ) ;
if ( V_171 != V_135 )
continue;
V_174 += V_62 -> V_20 -> V_88 [ V_88 ] . V_174 ;
V_172 += V_62 -> V_20 -> V_88 [ V_88 ] . V_172 ;
V_173 += V_62 -> V_20 -> V_88 [ V_88 ] . V_173 ;
V_14 ++ ;
}
if ( V_92 )
fprintf ( V_86 , L_47 , V_92 ) ;
if ( V_173 == 0 || V_172 == 0 ) {
F_68 ( V_62 , V_135 , V_14 ) ;
fprintf ( V_86 , L_48 ,
V_98 ? 0 : 18 ,
V_62 -> V_122 ? V_177 : V_178 ,
V_97 ,
V_98 ? 0 : - 24 ,
F_32 ( V_62 ) ) ;
if ( V_62 -> V_140 )
fprintf ( V_86 , L_20 ,
V_97 , V_62 -> V_140 -> V_139 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
if ( F_23 ( V_62 ) )
F_71 ( V_135 , V_14 , V_62 , V_174 ) ;
else
F_84 ( V_135 , V_14 , V_62 , V_174 ) ;
if ( ! V_98 ) {
F_66 ( V_62 , 1.0 ) ;
if ( V_173 != V_172 )
fprintf ( V_86 , L_49 ,
100.0 * V_173 / V_172 ) ;
}
fputc ( '\n' , V_86 ) ;
}
}
}
static void F_39 ( struct V_8 * V_62 , char * V_92 )
{
struct V_16 * V_80 = V_62 -> V_15 ;
double V_132 = F_73 ( & V_80 -> V_84 [ 0 ] ) ;
int V_179 = V_62 -> V_20 -> V_179 ;
if ( V_92 )
fprintf ( V_86 , L_47 , V_92 ) ;
if ( V_179 == - 1 ) {
fprintf ( V_86 , L_48 ,
V_98 ? 0 : 18 ,
V_62 -> V_122 ? V_177 : V_178 ,
V_97 ,
V_98 ? 0 : - 24 ,
F_32 ( V_62 ) ) ;
if ( V_62 -> V_140 )
fprintf ( V_86 , L_20 , V_97 , V_62 -> V_140 -> V_139 ) ;
fputc ( '\n' , V_86 ) ;
return;
}
if ( F_23 ( V_62 ) )
F_71 ( - 1 , 0 , V_62 , V_132 ) ;
else
F_84 ( - 1 , 0 , V_62 , V_132 ) ;
F_66 ( V_62 , V_132 ) ;
if ( V_98 ) {
fputc ( '\n' , V_86 ) ;
return;
}
if ( V_179 ) {
double V_180 , V_181 ;
V_180 = F_73 ( & V_80 -> V_84 [ 1 ] ) ;
V_181 = F_73 ( & V_80 -> V_84 [ 2 ] ) ;
fprintf ( V_86 , L_50 , 100 * V_181 / V_180 ) ;
}
fprintf ( V_86 , L_3 ) ;
}
static void F_38 ( struct V_8 * V_62 , char * V_92 )
{
T_2 V_172 , V_173 , V_174 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_62 ) ; V_88 ++ ) {
V_174 = V_62 -> V_20 -> V_88 [ V_88 ] . V_174 ;
V_172 = V_62 -> V_20 -> V_88 [ V_88 ] . V_172 ;
V_173 = V_62 -> V_20 -> V_88 [ V_88 ] . V_173 ;
if ( V_92 )
fprintf ( V_86 , L_47 , V_92 ) ;
if ( V_173 == 0 || V_172 == 0 ) {
fprintf ( V_86 , L_51 ,
V_98 ? 0 : - 4 ,
F_2 ( V_62 ) -> V_136 [ V_88 ] , V_97 ,
V_98 ? 0 : 18 ,
V_62 -> V_122 ? V_177 : V_178 ,
V_97 ,
V_98 ? 0 : - 24 ,
F_32 ( V_62 ) ) ;
if ( V_62 -> V_140 )
fprintf ( V_86 , L_20 ,
V_97 , V_62 -> V_140 -> V_139 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
if ( F_23 ( V_62 ) )
F_71 ( V_88 , 0 , V_62 , V_174 ) ;
else
F_84 ( V_88 , 0 , V_62 , V_174 ) ;
if ( ! V_98 ) {
F_66 ( V_62 , 1.0 ) ;
if ( V_173 != V_172 )
fprintf ( V_86 , L_49 ,
100.0 * V_173 / V_172 ) ;
}
fputc ( '\n' , V_86 ) ;
}
}
static void F_86 ( int V_104 , const char * * V_105 )
{
struct V_8 * V_62 ;
int V_83 ;
fflush ( stdout ) ;
if ( ! V_98 ) {
fprintf ( V_86 , L_3 ) ;
fprintf ( V_86 , L_52 ) ;
if ( V_11 . V_182 )
fprintf ( V_86 , L_53 ) ;
else if ( V_11 . V_12 )
fprintf ( V_86 , L_54 , V_11 . V_12 ) ;
else if ( ! F_20 ( & V_11 ) ) {
fprintf ( V_86 , L_55 , V_105 [ 0 ] ) ;
for ( V_83 = 1 ; V_83 < V_104 ; V_83 ++ )
fprintf ( V_86 , L_56 , V_105 [ V_83 ] ) ;
} else if ( V_11 . V_114 )
fprintf ( V_86 , L_57 , V_11 . V_114 ) ;
else
fprintf ( V_86 , L_58 , V_11 . V_183 ) ;
fprintf ( V_86 , L_59 ) ;
if ( V_134 > 1 )
fprintf ( V_86 , L_60 , V_134 ) ;
fprintf ( V_86 , L_61 ) ;
}
switch ( V_93 ) {
case V_100 :
case V_99 :
F_37 ( NULL ) ;
break;
case V_94 :
F_11 (counter, &evsel_list->entries, node)
F_39 ( V_62 , NULL ) ;
break;
case V_101 :
F_11 (counter, &evsel_list->entries, node)
F_38 ( V_62 , NULL ) ;
break;
default:
break;
}
if ( ! V_98 ) {
if ( ! V_184 )
fprintf ( V_86 , L_3 ) ;
fprintf ( V_86 , L_62 ,
F_73 ( & V_41 ) / 1e9 ) ;
if ( V_134 > 1 ) {
fprintf ( V_86 , L_63 ) ;
F_64 ( F_67 ( & V_41 ) ,
F_73 ( & V_41 ) ) ;
}
fprintf ( V_86 , L_64 ) ;
}
}
static void F_87 ( int V_185 )
{
if ( ( V_112 == - 1 ) || V_111 )
V_125 = 1 ;
V_186 = V_185 ;
V_112 = - 1 ;
}
static void F_88 ( void )
{
T_3 V_187 , V_188 ;
F_89 ( & V_187 ) ;
F_90 ( & V_187 , V_189 ) ;
F_91 ( V_190 , & V_187 , & V_188 ) ;
if ( V_112 != - 1 )
F_50 ( V_112 , V_123 ) ;
F_91 ( V_191 , & V_188 , NULL ) ;
if ( V_186 == - 1 )
return;
signal ( V_186 , V_192 ) ;
F_50 ( F_92 () , V_186 ) ;
}
static int F_93 ( const struct V_193 * T_4 V_126 ,
const char * V_170 V_126 , int V_194 )
{
V_195 = V_194 ? 0 : 1 ;
return 0 ;
}
static int F_94 ( void )
{
switch ( V_93 ) {
case V_99 :
if ( F_95 ( V_13 -> V_10 , & V_175 ) ) {
perror ( L_65 ) ;
return - 1 ;
}
V_176 = V_196 ;
break;
case V_100 :
if ( F_96 ( V_13 -> V_10 , & V_175 ) ) {
perror ( L_66 ) ;
return - 1 ;
}
V_176 = V_197 ;
break;
case V_101 :
case V_94 :
default:
break;
}
return 0 ;
}
static int F_97 ( const char * const * V_198 , unsigned V_199 )
{
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_199 ; V_83 ++ ) {
if ( F_98 ( V_13 , V_198 [ V_83 ] ) )
return - 1 ;
}
return 0 ;
}
static int F_99 ( void )
{
struct V_42 V_200 [] = {
{ . type = V_201 , . V_158 = V_202 } ,
{ . type = V_201 , . V_158 = V_203 } ,
{ . type = V_201 , . V_158 = V_204 } ,
{ . type = V_201 , . V_158 = V_205 } ,
{ . type = V_206 , . V_158 = V_207 } ,
{ . type = V_206 , . V_158 = V_208 } ,
{ . type = V_206 , . V_158 = V_209 } ,
{ . type = V_206 , . V_158 = V_210 } ,
{ . type = V_206 , . V_158 = V_211 } ,
{ . type = V_206 , . V_158 = V_212 } ,
} ;
struct V_42 V_213 [] = {
{ . type = V_157 ,
. V_158 =
V_159 << 0 |
( V_160 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_159 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_165 << 0 |
( V_160 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_165 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
} ;
struct V_42 V_215 [] = {
{ . type = V_157 ,
. V_158 =
V_162 << 0 |
( V_160 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_162 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_163 << 0 |
( V_160 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_163 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_164 << 0 |
( V_160 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_164 << 0 |
( V_160 << 8 ) |
( V_161 << 16 ) } ,
} ;
struct V_42 V_216 [] = {
{ . type = V_157 ,
. V_158 =
V_159 << 0 |
( V_217 << 8 ) |
( V_214 << 16 ) } ,
{ . type = V_157 ,
. V_158 =
V_159 << 0 |
( V_217 << 8 ) |
( V_161 << 16 ) } ,
} ;
if ( V_184 )
return 0 ;
if ( V_66 ) {
int V_218 ;
if ( F_100 ( L_67 , L_68 ) &&
F_100 ( L_67 , L_69 ) )
V_218 = F_97 ( V_219 ,
F_101 ( V_219 ) ) ;
else
V_218 = F_97 ( V_220 ,
F_101 ( V_220 ) ) ;
if ( V_218 < 0 ) {
fprintf ( V_221 , L_70 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_13 -> V_222 ) {
if ( F_102 ( V_13 , V_200 ) < 0 )
return - 1 ;
}
if ( V_223 < 1 )
return 0 ;
if ( F_102 ( V_13 , V_213 ) < 0 )
return - 1 ;
if ( V_223 < 2 )
return 0 ;
if ( F_102 ( V_13 , V_215 ) < 0 )
return - 1 ;
if ( V_223 < 3 )
return 0 ;
return F_102 ( V_13 , V_216 ) ;
}
int F_103 ( int V_104 , const char * * V_105 , const char * V_92 V_126 )
{
bool V_224 = false ;
int V_225 = 0 ;
const char * V_226 = NULL ;
const struct V_193 V_227 [] = {
F_104 ( 'T' , L_71 , & V_66 ,
L_72 ) ,
F_105 ( 'e' , L_73 , & V_13 , L_73 ,
L_74 ,
V_228 ) ,
F_105 ( 0 , L_75 , & V_13 , L_75 ,
L_76 , V_229 ) ,
F_104 ( 'i' , L_77 , & V_49 ,
L_78 ) ,
F_106 ( 'p' , L_79 , & V_11 . V_114 , L_79 ,
L_80 ) ,
F_106 ( 't' , L_81 , & V_11 . V_183 , L_81 ,
L_82 ) ,
F_104 ( 'a' , L_83 , & V_11 . V_182 ,
L_84 ) ,
F_104 ( 'g' , L_85 , & V_115 ,
L_86 ) ,
F_104 ( 'c' , L_87 , & V_44 , L_88 ) ,
F_107 ( 'v' , L_89 , & V_85 ,
L_90 ) ,
F_108 ( 'r' , L_91 , & V_134 ,
L_92 ) ,
F_104 ( 'n' , L_93 , & V_184 ,
L_94 ) ,
F_107 ( 'd' , L_95 , & V_223 ,
L_96 ) ,
F_104 ( 'S' , L_97 , & V_129 ,
L_98 ) ,
F_109 ( 'B' , L_99 , NULL , NULL ,
L_100 ,
F_93 ) ,
F_106 ( 'C' , L_67 , & V_11 . V_12 , L_67 ,
L_101 ) ,
F_110 ( 'A' , L_102 , & V_93 ,
L_103 , V_101 ) ,
F_106 ( 'x' , L_104 , & V_97 , L_105 ,
L_106 ) ,
F_105 ( 'G' , L_107 , & V_13 , L_108 ,
L_109 , V_230 ) ,
F_106 ( 'o' , L_110 , & V_226 , L_111 , L_112 ) ,
F_104 ( 0 , L_113 , & V_224 , L_114 ) ,
F_108 ( 0 , L_115 , & V_225 ,
L_116 ) ,
F_106 ( 0 , L_117 , & V_128 , L_118 ,
L_119 ) ,
F_106 ( 0 , L_120 , & V_130 , L_118 ,
L_121 ) ,
F_111 ( 'I' , L_122 , & V_111 ,
L_123 ) ,
F_110 ( 0 , L_124 , & V_93 ,
L_125 , V_99 ) ,
F_110 ( 0 , L_126 , & V_93 ,
L_127 , V_100 ) ,
F_111 ( 'D' , L_128 , & V_51 ,
L_129 ) ,
F_112 ()
} ;
const char * const V_231 [] = {
L_130 ,
NULL
} ;
int V_109 = - V_117 , V_232 ;
const char * V_233 ;
setlocale ( V_234 , L_21 ) ;
V_13 = F_113 () ;
if ( V_13 == NULL )
return - V_17 ;
V_104 = F_114 ( V_104 , V_105 , V_227 , V_231 ,
V_235 ) ;
V_86 = V_221 ;
if ( V_226 && strcmp ( V_226 , L_131 ) )
V_86 = NULL ;
if ( V_226 && V_225 ) {
fprintf ( V_221 , L_132 ) ;
F_115 ( V_231 , V_227 , L_133 , 1 ) ;
F_115 ( NULL , V_227 , L_115 , 0 ) ;
goto V_236;
}
if ( V_225 < 0 ) {
fprintf ( V_221 , L_134 ) ;
F_115 ( V_231 , V_227 , L_115 , 0 ) ;
goto V_236;
}
if ( ! V_86 ) {
struct V_1 V_237 ;
V_233 = V_224 ? L_135 : L_136 ;
V_86 = fopen ( V_226 , V_233 ) ;
if ( ! V_86 ) {
perror ( L_137 ) ;
return - 1 ;
}
F_36 ( V_238 , & V_237 ) ;
fprintf ( V_86 , L_138 , ctime ( & V_237 . V_5 ) ) ;
} else if ( V_225 > 0 ) {
V_233 = V_224 ? L_135 : L_136 ;
V_86 = fdopen ( V_225 , V_233 ) ;
if ( ! V_86 ) {
perror ( L_139 ) ;
return - V_116 ;
}
}
if ( V_97 ) {
V_98 = true ;
if ( ! strcmp ( V_97 , L_140 ) )
V_97 = L_141 ;
} else
V_97 = V_239 ;
if ( V_98 ) {
if ( V_195 == 1 ) {
fprintf ( V_221 , L_142 ) ;
F_115 ( V_231 , V_227 , L_143 , 1 ) ;
F_115 ( NULL , V_227 , L_144 , 1 ) ;
goto V_236;
} else
V_154 = false ;
} else if ( V_195 == 0 )
V_154 = false ;
if ( ! V_104 && F_116 ( & V_11 ) )
F_117 ( V_231 , V_227 ) ;
if ( V_134 < 0 ) {
F_118 ( L_145 ) ;
F_115 ( V_231 , V_227 , L_146 , 1 ) ;
goto V_236;
} else if ( V_134 == 0 ) {
V_240 = true ;
V_134 = 1 ;
}
if ( ( V_93 != V_94 || V_241 ) &&
! F_18 ( & V_11 ) ) {
fprintf ( V_221 , L_147
L_148 ) ;
F_115 ( V_231 , V_227 , L_149 , 1 ) ;
F_115 ( NULL , V_227 , L_150 , 1 ) ;
F_115 ( NULL , V_227 , L_135 , 1 ) ;
goto V_236;
}
if ( F_99 () )
goto V_236;
F_119 ( & V_11 ) ;
if ( F_120 ( V_13 , & V_11 ) < 0 ) {
if ( F_20 ( & V_11 ) ) {
F_118 ( L_151 ) ;
F_115 ( V_231 , V_227 , L_152 , 1 ) ;
F_115 ( NULL , V_227 , L_153 , 1 ) ;
} else if ( F_18 ( & V_11 ) ) {
perror ( L_154 ) ;
F_115 ( V_231 , V_227 , L_155 , 1 ) ;
F_115 ( NULL , V_227 , L_135 , 1 ) ;
}
goto V_236;
}
if ( V_111 && V_111 < 100 ) {
F_118 ( L_156 ) ;
F_115 ( V_231 , V_227 , L_157 , 1 ) ;
goto V_242;
}
if ( F_13 ( V_13 , V_111 ) )
goto V_242;
if ( F_94 () )
goto V_242;
atexit ( F_88 ) ;
if ( ! V_240 )
signal ( V_243 , F_87 ) ;
signal ( V_189 , F_87 ) ;
signal ( V_244 , F_87 ) ;
signal ( V_245 , F_87 ) ;
V_109 = 0 ;
for ( V_232 = 0 ; V_240 || V_232 < V_134 ; V_232 ++ ) {
if ( V_134 != 1 && V_85 )
fprintf ( V_86 , L_158 ,
V_232 + 1 ) ;
V_109 = F_62 ( V_104 , V_105 ) ;
if ( V_240 && V_109 != - 1 ) {
F_86 ( V_104 , V_105 ) ;
F_15 ( V_13 ) ;
}
}
if ( ! V_240 && V_109 != - 1 && ! V_111 )
F_86 ( V_104 , V_105 ) ;
F_10 ( V_13 ) ;
V_242:
F_121 ( V_13 ) ;
V_236:
F_122 ( V_13 ) ;
return V_109 ;
}
