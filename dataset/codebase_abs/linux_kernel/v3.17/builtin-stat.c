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
int V_15 ;
struct V_16 * V_17 = V_9 -> V_18 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_5 ( & V_17 -> V_19 [ V_15 ] ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
V_9 -> V_18 = F_7 ( sizeof( struct V_16 ) ) ;
if ( V_9 -> V_18 == NULL )
return - V_20 ;
F_4 ( V_9 ) ;
return 0 ;
}
static void F_8 ( struct V_8 * V_9 )
{
F_9 ( & V_9 -> V_18 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
void * V_21 ;
T_1 V_22 ;
V_22 = sizeof( * V_9 -> V_23 ) +
( F_3 ( V_9 ) * sizeof( struct V_24 ) ) ;
V_21 = F_7 ( V_22 ) ;
if ( ! V_21 )
return - V_20 ;
V_9 -> V_25 = V_21 ;
return 0 ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_9 ( & V_9 -> V_25 ) ;
}
static void F_12 ( struct V_26 * V_27 )
{
struct V_8 * V_9 ;
F_13 (evlist, evsel) {
F_8 ( V_9 ) ;
F_14 ( V_9 ) ;
F_11 ( V_9 ) ;
}
}
static int F_15 ( struct V_26 * V_27 , bool V_28 )
{
struct V_8 * V_9 ;
F_13 (evlist, evsel) {
if ( F_6 ( V_9 ) < 0 ||
F_16 ( V_9 , F_3 ( V_9 ) ) < 0 ||
( V_28 && F_10 ( V_9 ) < 0 ) )
goto V_29;
}
return 0 ;
V_29:
F_12 ( V_27 ) ;
return - 1 ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_8 * V_9 ;
F_13 (evlist, evsel) {
F_4 ( V_9 ) ;
F_18 ( V_9 , F_3 ( V_9 ) ) ;
}
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
memset ( V_41 , 0 ,
sizeof( V_41 ) ) ;
memset ( V_42 , 0 ,
sizeof( V_42 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
}
static int F_19 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = & V_9 -> V_46 ;
if ( V_47 )
V_46 -> V_48 = V_49 |
V_50 ;
V_46 -> V_51 = ! V_52 ;
if ( F_20 ( & V_11 ) )
return F_21 ( V_9 , F_2 ( V_9 ) ) ;
if ( ! F_22 ( & V_11 ) && F_23 ( V_9 ) ) {
V_46 -> V_53 = 1 ;
if ( ! V_54 )
V_46 -> V_55 = 1 ;
}
return F_24 ( V_9 , V_13 -> V_56 ) ;
}
static inline int F_25 ( struct V_8 * V_9 )
{
if ( F_26 ( V_9 , V_57 , V_58 ) ||
F_26 ( V_9 , V_57 , V_59 ) )
return 1 ;
return 0 ;
}
static struct V_8 * F_27 ( int V_60 )
{
static struct V_8 * * V_61 ;
static int V_62 ;
struct V_8 * V_63 ;
int V_64 ;
if ( ! V_61 ) {
F_13 (evsel_list, ev)
V_62 ++ ;
V_61 = malloc ( V_62 * sizeof( void * ) ) ;
if ( ! V_61 )
exit ( V_20 ) ;
V_64 = 0 ;
F_13 (evsel_list, ev)
V_61 [ V_64 ++ ] = V_63 ;
}
if ( V_60 < V_62 )
return V_61 [ V_60 ] ;
return NULL ;
}
static void F_28 ( struct V_8 * V_65 , T_2 * V_66 )
{
if ( F_26 ( V_65 , V_57 , V_59 ) )
F_29 ( & V_30 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_67 , V_68 ) )
F_29 ( & V_31 [ 0 ] , V_66 [ 0 ] ) ;
else if ( V_69 &&
F_30 ( V_65 , F_27 ( V_70 ) ) )
F_29 ( & V_41 [ 0 ] , V_66 [ 0 ] ) ;
else if ( V_69 &&
F_30 ( V_65 , F_27 ( V_71 ) ) )
F_29 ( & V_42 [ 0 ] , V_66 [ 0 ] ) ;
else if ( V_69 &&
F_30 ( V_65 , F_27 ( V_72 ) ) )
F_29 ( & V_43 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_67 , V_73 ) )
F_29 ( & V_32 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_67 , V_74 ) )
F_29 ( & V_33 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_67 , V_75 ) )
F_29 ( & V_34 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_67 , V_76 ) )
F_29 ( & V_35 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_77 , V_78 ) )
F_29 ( & V_36 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_77 , V_79 ) )
F_29 ( & V_37 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_77 , V_80 ) )
F_29 ( & V_38 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_77 , V_81 ) )
F_29 ( & V_40 [ 0 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_77 , V_82 ) )
F_29 ( & V_39 [ 0 ] , V_66 [ 0 ] ) ;
}
static int F_31 ( struct V_8 * V_65 )
{
struct V_16 * V_17 = V_65 -> V_18 ;
T_2 * V_66 = V_65 -> V_23 -> V_83 . V_84 ;
int V_15 ;
if ( F_32 ( V_65 , F_3 ( V_65 ) ,
F_33 ( V_13 -> V_56 ) , V_47 ) < 0 )
return - 1 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_29 ( & V_17 -> V_19 [ V_15 ] , V_66 [ V_15 ] ) ;
if ( V_85 ) {
fprintf ( V_86 , L_1 V_87 L_2 V_87 L_2 V_87 L_3 ,
F_34 ( V_65 ) , V_66 [ 0 ] , V_66 [ 1 ] , V_66 [ 2 ] ) ;
}
F_28 ( V_65 , V_66 ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_65 )
{
T_2 * V_66 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_65 ) ; V_88 ++ ) {
if ( F_36 ( V_65 , V_88 , 0 , V_47 ) < 0 )
return - 1 ;
V_66 = V_65 -> V_23 -> V_88 [ V_88 ] . V_84 ;
F_28 ( V_65 , V_66 ) ;
}
return 0 ;
}
static void F_37 ( void )
{
static int V_89 ;
struct V_8 * V_65 ;
struct V_16 * V_17 ;
struct V_1 V_90 , V_91 ;
char V_92 [ 64 ] ;
if ( V_93 == V_94 ) {
F_13 (evsel_list, counter) {
V_17 = V_65 -> V_18 ;
memset ( V_17 -> V_19 , 0 , sizeof( V_17 -> V_19 ) ) ;
F_31 ( V_65 ) ;
}
} else {
F_13 (evsel_list, counter) {
V_17 = V_65 -> V_18 ;
memset ( V_17 -> V_19 , 0 , sizeof( V_17 -> V_19 ) ) ;
F_35 ( V_65 ) ;
}
}
F_38 ( V_95 , & V_90 ) ;
F_1 ( & V_91 , & V_90 , & V_96 ) ;
sprintf ( V_92 , L_4 , V_91 . V_5 , V_91 . V_6 , V_97 ) ;
if ( V_89 == 0 && ! V_98 ) {
switch ( V_93 ) {
case V_99 :
fprintf ( V_86 , L_5 , V_100 , L_6 ) ;
break;
case V_101 :
fprintf ( V_86 , L_7 , V_100 , L_6 ) ;
break;
case V_102 :
fprintf ( V_86 , L_8 , V_100 , L_6 ) ;
break;
case V_94 :
default:
fprintf ( V_86 , L_9 , V_100 , L_6 ) ;
}
}
if ( ++ V_89 == 25 )
V_89 = 0 ;
switch ( V_93 ) {
case V_101 :
case V_99 :
F_39 ( V_92 ) ;
break;
case V_102 :
F_13 (evsel_list, counter)
F_40 ( V_65 , V_92 ) ;
break;
case V_94 :
default:
F_13 (evsel_list, counter)
F_41 ( V_65 , V_92 ) ;
}
fflush ( V_86 ) ;
}
static void F_42 ( void )
{
struct V_8 * V_65 ;
if ( V_54 ) {
const int V_103 = F_43 ( V_13 -> V_10 ) ,
V_104 = F_33 ( V_13 -> V_56 ) ;
F_44 ( V_54 * 1000 ) ;
F_13 (evsel_list, counter)
F_45 ( V_65 , V_103 , V_104 ) ;
}
}
static void F_46 ( int T_3 V_105 , T_4 * V_106 ,
void * T_5 V_105 )
{
V_107 = V_106 -> V_108 . V_109 ;
}
static int F_47 ( int V_110 , const char * * V_111 )
{
char V_112 [ 512 ] ;
unsigned long long V_113 , V_114 ;
struct V_8 * V_65 ;
struct V_1 V_90 ;
T_1 V_115 ;
int V_116 = 0 ;
const bool V_117 = ( V_110 > 0 ) ;
if ( V_118 ) {
V_90 . V_5 = V_118 / 1000 ;
V_90 . V_6 = ( V_118 % 1000 ) * 1000000 ;
} else {
V_90 . V_5 = 1 ;
V_90 . V_6 = 0 ;
}
if ( V_117 ) {
if ( F_48 ( V_13 , & V_11 , V_111 , false ,
F_46 ) < 0 ) {
perror ( L_10 ) ;
return - 1 ;
}
V_119 = V_13 -> V_120 . V_121 ;
}
if ( V_122 )
F_49 ( V_13 ) ;
F_13 (evsel_list, counter) {
if ( F_19 ( V_65 ) < 0 ) {
if ( V_123 == V_124 || V_123 == V_125 ||
V_123 == V_126 || V_123 == V_127 ||
V_123 == V_128 ) {
if ( V_85 )
F_50 ( L_11 ,
F_34 ( V_65 ) ) ;
V_65 -> V_129 = false ;
continue;
}
F_51 ( V_65 , & V_11 ,
V_123 , V_112 , sizeof( V_112 ) ) ;
F_52 ( L_12 , V_112 ) ;
if ( V_119 != - 1 )
F_53 ( V_119 , V_130 ) ;
return - 1 ;
}
V_65 -> V_129 = true ;
V_115 = strlen ( V_65 -> V_131 ) ;
if ( V_115 > V_100 )
V_100 = V_115 ;
}
if ( F_54 ( V_13 ) ) {
error ( L_13 , V_123 ,
strerror ( V_123 ) ) ;
return - 1 ;
}
V_113 = F_55 () ;
F_38 ( V_95 , & V_96 ) ;
if ( V_117 ) {
F_56 ( V_13 ) ;
F_42 () ;
if ( V_118 ) {
while ( ! F_57 ( V_119 , & V_116 , V_132 ) ) {
F_58 ( & V_90 , NULL ) ;
F_37 () ;
}
}
F_59 ( & V_116 ) ;
if ( V_107 ) {
const char * V_133 = F_60 ( V_107 , V_112 , sizeof( V_112 ) ) ;
F_61 ( L_14 , V_133 ) ;
return - 1 ;
}
if ( F_62 ( V_116 ) )
F_63 ( F_64 ( V_116 ) , V_111 [ 0 ] ) ;
} else {
F_42 () ;
while ( ! V_134 ) {
F_58 ( & V_90 , NULL ) ;
if ( V_118 )
F_37 () ;
}
}
V_114 = F_55 () ;
F_29 ( & V_44 , V_114 - V_113 ) ;
if ( V_93 == V_94 ) {
F_13 (evsel_list, counter) {
F_31 ( V_65 ) ;
F_65 ( V_65 , F_3 ( V_65 ) ,
F_33 ( V_13 -> V_56 ) ) ;
}
} else {
F_13 (evsel_list, counter) {
F_35 ( V_65 ) ;
F_65 ( V_65 , F_3 ( V_65 ) , 1 ) ;
}
}
return F_66 ( V_116 ) ;
}
static int F_67 ( int V_110 , const char * * V_111 )
{
int V_135 ;
if ( V_136 ) {
V_135 = system ( V_136 ) ;
if ( V_135 )
return V_135 ;
}
if ( V_137 )
F_68 () ;
V_135 = F_47 ( V_110 , V_111 ) ;
if ( V_135 )
return V_135 ;
if ( V_138 ) {
V_135 = system ( V_138 ) ;
if ( V_135 )
return V_135 ;
}
return V_135 ;
}
static void F_69 ( double V_139 , double V_140 )
{
double V_141 = F_70 ( V_139 , V_140 ) ;
if ( V_98 )
fprintf ( V_86 , L_15 , V_97 , V_141 ) ;
else if ( V_141 )
fprintf ( V_86 , L_16 , V_141 ) ;
}
static void F_71 ( struct V_8 * V_9 , double V_140 )
{
struct V_16 * V_17 ;
if ( V_142 == 1 )
return;
V_17 = V_9 -> V_18 ;
F_69 ( F_72 ( & V_17 -> V_19 [ 0 ] ) , V_140 ) ;
}
static void F_73 ( struct V_8 * V_9 , int V_143 , int V_14 )
{
switch ( V_93 ) {
case V_101 :
fprintf ( V_86 , L_17 ,
F_74 ( V_143 ) ,
V_98 ? 0 : - 8 ,
F_75 ( V_143 ) ,
V_97 ,
V_98 ? 0 : 4 ,
V_14 ,
V_97 ) ;
break;
case V_99 :
fprintf ( V_86 , L_18 ,
V_98 ? 0 : - 5 ,
V_143 ,
V_97 ,
V_98 ? 0 : 4 ,
V_14 ,
V_97 ) ;
break;
case V_102 :
fprintf ( V_86 , L_19 ,
V_98 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_144 [ V_143 ] , V_97 ) ;
break;
case V_94 :
default:
break;
}
}
static void F_76 ( int V_88 , int V_14 , struct V_8 * V_9 , double V_140 )
{
double V_145 = V_140 / 1e6 ;
const char * V_146 , * V_147 ;
char V_148 [ 25 ] ;
V_146 = V_98 ? L_20 : L_21 ;
V_147 = V_98 ? L_22 : L_23 ;
F_73 ( V_9 , V_88 , V_14 ) ;
F_77 ( V_148 , sizeof( V_148 ) , L_24 ,
F_34 ( V_9 ) , V_98 ? L_25 : L_26 ) ;
fprintf ( V_86 , V_146 , V_145 , V_97 ) ;
if ( V_98 )
fprintf ( V_86 , L_24 , V_9 -> V_131 , V_97 ) ;
else
fprintf ( V_86 , L_27 , V_100 , V_9 -> V_131 , V_97 ) ;
fprintf ( V_86 , V_147 , V_148 ) ;
if ( V_9 -> V_149 )
fprintf ( V_86 , L_24 , V_97 , V_9 -> V_149 -> V_148 ) ;
if ( V_98 || V_118 )
return;
if ( F_26 ( V_9 , V_57 , V_59 ) )
fprintf ( V_86 , L_28 ,
V_140 / F_78 ( & V_44 ) ) ;
else
fprintf ( V_86 , L_29 ) ;
}
static const char * F_79 ( enum V_150 type , double V_151 )
{
static const double V_152 [ V_153 ] [ 3 ] = {
[ V_154 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_155 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_156 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_157 = V_158 ;
if ( V_151 > V_152 [ type ] [ 0 ] )
V_157 = V_159 ;
else if ( V_151 > V_152 [ type ] [ 1 ] )
V_157 = V_160 ;
else if ( V_151 > V_152 [ type ] [ 2 ] )
V_157 = V_161 ;
return V_157 ;
}
static void F_80 ( int V_88 ,
struct V_8 * V_9
V_105 , double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_31 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_154 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_32 ) ;
}
static void F_82 ( int V_88 ,
struct V_8 * V_9
V_105 , double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_31 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_155 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_33 ) ;
}
static void F_83 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_34 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_34 ) ;
}
static void F_84 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_36 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_35 ) ;
}
static void F_85 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_37 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_36 ) ;
}
static void F_86 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_40 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_37 ) ;
}
static void F_87 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_39 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_38 ) ;
}
static void F_88 ( int V_88 ,
struct V_8 * V_9 V_105 ,
double V_140 )
{
double V_139 , V_151 = 0.0 ;
const char * V_157 ;
V_139 = F_78 ( & V_38 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 / V_139 * 100.0 ;
V_157 = F_79 ( V_156 , V_151 ) ;
fprintf ( V_86 , L_30 ) ;
F_81 ( V_86 , V_157 , L_31 , V_151 ) ;
fprintf ( V_86 , L_39 ) ;
}
static void F_89 ( int V_88 , int V_14 , struct V_8 * V_9 , double V_140 )
{
double V_139 , V_151 = 0.0 , V_162 ;
double V_163 = V_9 -> V_47 ;
const char * V_164 ;
if ( V_98 ) {
V_164 = V_163 != 1.0 ? L_40 : L_41 ;
} else {
if ( V_165 )
V_164 = V_163 != 1.0 ? L_42 : L_43 ;
else
V_164 = V_163 != 1.0 ? L_44 : L_45 ;
}
F_73 ( V_9 , V_88 , V_14 ) ;
if ( V_93 == V_94 )
V_88 = 0 ;
fprintf ( V_86 , V_164 , V_140 , V_97 ) ;
if ( V_9 -> V_131 )
fprintf ( V_86 , L_27 ,
V_98 ? 0 : V_100 ,
V_9 -> V_131 , V_97 ) ;
fprintf ( V_86 , L_46 , V_98 ? 0 : 25 , F_34 ( V_9 ) ) ;
if ( V_9 -> V_149 )
fprintf ( V_86 , L_24 , V_97 , V_9 -> V_149 -> V_148 ) ;
if ( V_98 || V_118 )
return;
if ( F_26 ( V_9 , V_67 , V_166 ) ) {
V_139 = F_78 ( & V_31 [ V_88 ] ) ;
if ( V_139 ) {
V_151 = V_140 / V_139 ;
fprintf ( V_86 , L_47 , V_151 ) ;
}
V_139 = F_78 ( & V_32 [ V_88 ] ) ;
V_139 = F_90 ( V_139 , F_78 ( & V_33 [ V_88 ] ) ) ;
if ( V_139 && V_140 ) {
V_151 = V_139 / V_140 ;
fprintf ( V_86 , L_3 ) ;
if ( V_93 == V_102 )
fprintf ( V_86 , L_48 ) ;
fprintf ( V_86 , L_49 , V_151 ) ;
}
} else if ( F_26 ( V_9 , V_67 , V_167 ) &&
V_34 [ V_88 ] . V_60 != 0 ) {
F_83 ( V_88 , V_9 , V_140 ) ;
} else if (
V_9 -> V_46 . type == V_168 &&
V_9 -> V_46 . V_169 == ( V_170 |
( ( V_171 ) << 8 ) |
( ( V_172 ) << 16 ) ) &&
V_36 [ V_88 ] . V_60 != 0 ) {
F_84 ( V_88 , V_9 , V_140 ) ;
} else if (
V_9 -> V_46 . type == V_168 &&
V_9 -> V_46 . V_169 == ( V_173 |
( ( V_171 ) << 8 ) |
( ( V_172 ) << 16 ) ) &&
V_37 [ V_88 ] . V_60 != 0 ) {
F_85 ( V_88 , V_9 , V_140 ) ;
} else if (
V_9 -> V_46 . type == V_168 &&
V_9 -> V_46 . V_169 == ( V_174 |
( ( V_171 ) << 8 ) |
( ( V_172 ) << 16 ) ) &&
V_40 [ V_88 ] . V_60 != 0 ) {
F_86 ( V_88 , V_9 , V_140 ) ;
} else if (
V_9 -> V_46 . type == V_168 &&
V_9 -> V_46 . V_169 == ( V_175 |
( ( V_171 ) << 8 ) |
( ( V_172 ) << 16 ) ) &&
V_39 [ V_88 ] . V_60 != 0 ) {
F_87 ( V_88 , V_9 , V_140 ) ;
} else if (
V_9 -> V_46 . type == V_168 &&
V_9 -> V_46 . V_169 == ( V_176 |
( ( V_171 ) << 8 ) |
( ( V_172 ) << 16 ) ) &&
V_38 [ V_88 ] . V_60 != 0 ) {
F_88 ( V_88 , V_9 , V_140 ) ;
} else if ( F_26 ( V_9 , V_67 , V_177 ) &&
V_35 [ V_88 ] . V_60 != 0 ) {
V_139 = F_78 ( & V_35 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_140 * 100 / V_139 ;
fprintf ( V_86 , L_50 , V_151 ) ;
} else if ( F_26 ( V_9 , V_67 , V_73 ) ) {
F_80 ( V_88 , V_9 , V_140 ) ;
} else if ( F_26 ( V_9 , V_67 , V_74 ) ) {
F_82 ( V_88 , V_9 , V_140 ) ;
} else if ( F_26 ( V_9 , V_67 , V_68 ) ) {
V_139 = F_78 ( & V_30 [ V_88 ] ) ;
if ( V_139 ) {
V_151 = V_140 / V_139 ;
fprintf ( V_86 , L_51 , V_151 ) ;
}
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_70 ) ) ) {
V_139 = F_78 ( & V_31 [ V_88 ] ) ;
if ( V_139 )
fprintf ( V_86 ,
L_52 ,
100.0 * ( V_140 / V_139 ) ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_178 ) ) ) {
V_139 = F_78 ( & V_31 [ V_88 ] ) ;
V_162 = F_78 ( & V_41 [ V_88 ] ) ;
if ( V_162 < V_140 )
V_162 = V_140 ;
if ( V_139 )
fprintf ( V_86 ,
L_53 ,
100.0 * ( ( V_162 - V_140 ) / V_139 ) ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_71 ) ) &&
V_140 > 0 &&
V_41 [ V_88 ] . V_60 != 0 ) {
V_139 = F_78 ( & V_41 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_139 / V_140 ;
fprintf ( V_86 , L_54 , V_151 ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_72 ) ) &&
V_140 > 0 &&
V_41 [ V_88 ] . V_60 != 0 ) {
V_139 = F_78 ( & V_41 [ V_88 ] ) ;
if ( V_139 )
V_151 = V_139 / V_140 ;
fprintf ( V_86 , L_55 , V_151 ) ;
} else if ( V_30 [ V_88 ] . V_60 != 0 ) {
char V_131 = 'M' ;
V_139 = F_78 ( & V_30 [ V_88 ] ) ;
if ( V_139 )
V_151 = 1000.0 * V_140 / V_139 ;
if ( V_151 < 0.001 ) {
V_151 *= 1000 ;
V_131 = 'K' ;
}
fprintf ( V_86 , L_56 , V_151 , V_131 ) ;
} else {
fprintf ( V_86 , L_29 ) ;
}
}
static void F_39 ( char * V_92 )
{
struct V_8 * V_65 ;
int V_88 , V_179 , V_180 , V_181 , V_143 , V_14 ;
double V_182 ;
T_2 V_183 , V_184 , V_185 ;
if ( ! ( V_186 || V_187 ) )
return;
for ( V_180 = 0 ; V_180 < V_186 -> V_14 ; V_180 ++ ) {
V_143 = V_186 -> V_144 [ V_180 ] ;
F_13 (evsel_list, counter) {
V_185 = V_183 = V_184 = 0 ;
V_14 = 0 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_65 ) ; V_88 ++ ) {
V_179 = F_2 ( V_65 ) -> V_144 [ V_88 ] ;
V_181 = V_187 ( V_13 -> V_10 , V_179 ) ;
if ( V_181 != V_143 )
continue;
V_185 += V_65 -> V_23 -> V_88 [ V_88 ] . V_185 ;
V_183 += V_65 -> V_23 -> V_88 [ V_88 ] . V_183 ;
V_184 += V_65 -> V_23 -> V_88 [ V_88 ] . V_184 ;
V_14 ++ ;
}
if ( V_92 )
fprintf ( V_86 , L_22 , V_92 ) ;
if ( V_184 == 0 || V_183 == 0 ) {
F_73 ( V_65 , V_143 , V_14 ) ;
fprintf ( V_86 , L_57 ,
V_98 ? 0 : 18 ,
V_65 -> V_129 ? V_188 : V_189 ,
V_97 ) ;
fprintf ( V_86 , L_27 ,
V_98 ? 0 : V_100 ,
V_65 -> V_131 , V_97 ) ;
fprintf ( V_86 , L_58 ,
V_98 ? 0 : - 25 ,
F_34 ( V_65 ) ) ;
if ( V_65 -> V_149 )
fprintf ( V_86 , L_24 ,
V_97 , V_65 -> V_149 -> V_148 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_182 = V_185 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_76 ( V_143 , V_14 , V_65 , V_182 ) ;
else
F_89 ( V_143 , V_14 , V_65 , V_182 ) ;
if ( ! V_98 ) {
F_71 ( V_65 , 1.0 ) ;
if ( V_184 != V_183 )
fprintf ( V_86 , L_59 ,
100.0 * V_184 / V_183 ) ;
}
fputc ( '\n' , V_86 ) ;
}
}
}
static void F_41 ( struct V_8 * V_65 , char * V_92 )
{
struct V_16 * V_17 = V_65 -> V_18 ;
double V_140 = F_78 ( & V_17 -> V_19 [ 0 ] ) ;
int V_190 = V_65 -> V_23 -> V_190 ;
double V_182 ;
if ( V_92 )
fprintf ( V_86 , L_22 , V_92 ) ;
if ( V_190 == - 1 ) {
fprintf ( V_86 , L_57 ,
V_98 ? 0 : 18 ,
V_65 -> V_129 ? V_188 : V_189 ,
V_97 ) ;
fprintf ( V_86 , L_27 ,
V_98 ? 0 : V_100 ,
V_65 -> V_131 , V_97 ) ;
fprintf ( V_86 , L_58 ,
V_98 ? 0 : - 25 ,
F_34 ( V_65 ) ) ;
if ( V_65 -> V_149 )
fprintf ( V_86 , L_24 , V_97 , V_65 -> V_149 -> V_148 ) ;
fputc ( '\n' , V_86 ) ;
return;
}
V_182 = V_140 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_76 ( - 1 , 0 , V_65 , V_182 ) ;
else
F_89 ( - 1 , 0 , V_65 , V_182 ) ;
F_71 ( V_65 , V_140 ) ;
if ( V_98 ) {
fputc ( '\n' , V_86 ) ;
return;
}
if ( V_190 ) {
double V_191 , V_192 ;
V_191 = F_78 ( & V_17 -> V_19 [ 1 ] ) ;
V_192 = F_78 ( & V_17 -> V_19 [ 2 ] ) ;
fprintf ( V_86 , L_60 , 100 * V_192 / V_191 ) ;
}
fprintf ( V_86 , L_3 ) ;
}
static void F_40 ( struct V_8 * V_65 , char * V_92 )
{
T_2 V_183 , V_184 , V_185 ;
double V_182 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < F_3 ( V_65 ) ; V_88 ++ ) {
V_185 = V_65 -> V_23 -> V_88 [ V_88 ] . V_185 ;
V_183 = V_65 -> V_23 -> V_88 [ V_88 ] . V_183 ;
V_184 = V_65 -> V_23 -> V_88 [ V_88 ] . V_184 ;
if ( V_92 )
fprintf ( V_86 , L_22 , V_92 ) ;
if ( V_184 == 0 || V_183 == 0 ) {
fprintf ( V_86 , L_61 ,
V_98 ? 0 : - 4 ,
F_2 ( V_65 ) -> V_144 [ V_88 ] , V_97 ,
V_98 ? 0 : 18 ,
V_65 -> V_129 ? V_188 : V_189 ,
V_97 ) ;
fprintf ( V_86 , L_27 ,
V_98 ? 0 : V_100 ,
V_65 -> V_131 , V_97 ) ;
fprintf ( V_86 , L_58 ,
V_98 ? 0 : - 25 ,
F_34 ( V_65 ) ) ;
if ( V_65 -> V_149 )
fprintf ( V_86 , L_24 ,
V_97 , V_65 -> V_149 -> V_148 ) ;
fputc ( '\n' , V_86 ) ;
continue;
}
V_182 = V_185 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_76 ( V_88 , 0 , V_65 , V_182 ) ;
else
F_89 ( V_88 , 0 , V_65 , V_182 ) ;
if ( ! V_98 ) {
F_71 ( V_65 , 1.0 ) ;
if ( V_184 != V_183 )
fprintf ( V_86 , L_59 ,
100.0 * V_184 / V_183 ) ;
}
fputc ( '\n' , V_86 ) ;
}
}
static void F_91 ( int V_110 , const char * * V_111 )
{
struct V_8 * V_65 ;
int V_15 ;
fflush ( stdout ) ;
if ( ! V_98 ) {
fprintf ( V_86 , L_3 ) ;
fprintf ( V_86 , L_62 ) ;
if ( V_11 . V_193 )
fprintf ( V_86 , L_63 ) ;
else if ( V_11 . V_12 )
fprintf ( V_86 , L_64 , V_11 . V_12 ) ;
else if ( ! F_22 ( & V_11 ) ) {
fprintf ( V_86 , L_65 , V_111 [ 0 ] ) ;
for ( V_15 = 1 ; V_15 < V_110 ; V_15 ++ )
fprintf ( V_86 , L_66 , V_111 [ V_15 ] ) ;
} else if ( V_11 . V_121 )
fprintf ( V_86 , L_67 , V_11 . V_121 ) ;
else
fprintf ( V_86 , L_68 , V_11 . V_194 ) ;
fprintf ( V_86 , L_69 ) ;
if ( V_142 > 1 )
fprintf ( V_86 , L_70 , V_142 ) ;
fprintf ( V_86 , L_71 ) ;
}
switch ( V_93 ) {
case V_101 :
case V_99 :
F_39 ( NULL ) ;
break;
case V_94 :
F_13 (evsel_list, counter)
F_41 ( V_65 , NULL ) ;
break;
case V_102 :
F_13 (evsel_list, counter)
F_40 ( V_65 , NULL ) ;
break;
default:
break;
}
if ( ! V_98 ) {
if ( ! V_195 )
fprintf ( V_86 , L_3 ) ;
fprintf ( V_86 , L_72 ,
F_78 ( & V_44 ) / 1e9 ) ;
if ( V_142 > 1 ) {
fprintf ( V_86 , L_73 ) ;
F_69 ( F_72 ( & V_44 ) ,
F_78 ( & V_44 ) ) ;
}
fprintf ( V_86 , L_74 ) ;
}
}
static void F_92 ( int T_3 )
{
if ( ( V_119 == - 1 ) || V_118 )
V_134 = 1 ;
V_196 = T_3 ;
V_119 = - 1 ;
}
static void F_93 ( void )
{
T_6 V_197 , V_198 ;
F_94 ( & V_197 ) ;
F_95 ( & V_197 , V_199 ) ;
F_96 ( V_200 , & V_197 , & V_198 ) ;
if ( V_119 != - 1 )
F_53 ( V_119 , V_130 ) ;
F_96 ( V_201 , & V_198 , NULL ) ;
if ( V_196 == - 1 )
return;
signal ( V_196 , V_202 ) ;
F_53 ( F_97 () , V_196 ) ;
}
static int F_98 ( const struct V_203 * T_7 V_105 ,
const char * V_180 V_105 , int V_204 )
{
V_205 = V_204 ? 0 : 1 ;
return 0 ;
}
static int F_99 ( void )
{
switch ( V_93 ) {
case V_99 :
if ( F_100 ( V_13 -> V_10 , & V_186 ) ) {
perror ( L_75 ) ;
return - 1 ;
}
V_187 = V_206 ;
break;
case V_101 :
if ( F_101 ( V_13 -> V_10 , & V_186 ) ) {
perror ( L_76 ) ;
return - 1 ;
}
V_187 = V_207 ;
break;
case V_102 :
case V_94 :
default:
break;
}
return 0 ;
}
static int F_102 ( const char * const * V_208 , unsigned V_209 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_209 ; V_15 ++ ) {
if ( F_103 ( V_13 , V_208 [ V_15 ] ) )
return - 1 ;
}
return 0 ;
}
static int F_104 ( void )
{
struct V_45 V_210 [] = {
{ . type = V_211 , . V_169 = V_212 } ,
{ . type = V_211 , . V_169 = V_213 } ,
{ . type = V_211 , . V_169 = V_214 } ,
{ . type = V_211 , . V_169 = V_215 } ,
{ . type = V_216 , . V_169 = V_217 } ,
{ . type = V_216 , . V_169 = V_218 } ,
{ . type = V_216 , . V_169 = V_219 } ,
{ . type = V_216 , . V_169 = V_220 } ,
{ . type = V_216 , . V_169 = V_221 } ,
{ . type = V_216 , . V_169 = V_222 } ,
} ;
struct V_45 V_223 [] = {
{ . type = V_168 ,
. V_169 =
V_170 << 0 |
( V_171 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_170 << 0 |
( V_171 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_176 << 0 |
( V_171 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_176 << 0 |
( V_171 << 8 ) |
( V_172 << 16 ) } ,
} ;
struct V_45 V_225 [] = {
{ . type = V_168 ,
. V_169 =
V_173 << 0 |
( V_171 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_173 << 0 |
( V_171 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_174 << 0 |
( V_171 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_174 << 0 |
( V_171 << 8 ) |
( V_172 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_175 << 0 |
( V_171 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_175 << 0 |
( V_171 << 8 ) |
( V_172 << 16 ) } ,
} ;
struct V_45 V_226 [] = {
{ . type = V_168 ,
. V_169 =
V_170 << 0 |
( V_227 << 8 ) |
( V_224 << 16 ) } ,
{ . type = V_168 ,
. V_169 =
V_170 << 0 |
( V_227 << 8 ) |
( V_172 << 16 ) } ,
} ;
if ( V_195 )
return 0 ;
if ( V_69 ) {
int V_228 ;
if ( F_105 ( L_77 , L_78 ) &&
F_105 ( L_77 , L_79 ) )
V_228 = F_102 ( V_229 ,
F_106 ( V_229 ) ) ;
else
V_228 = F_102 ( V_230 ,
F_106 ( V_230 ) ) ;
if ( V_228 < 0 ) {
fprintf ( V_231 , L_80 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_13 -> V_232 ) {
if ( F_107 ( V_13 , V_210 ) < 0 )
return - 1 ;
}
if ( V_233 < 1 )
return 0 ;
if ( F_107 ( V_13 , V_223 ) < 0 )
return - 1 ;
if ( V_233 < 2 )
return 0 ;
if ( F_107 ( V_13 , V_225 ) < 0 )
return - 1 ;
if ( V_233 < 3 )
return 0 ;
return F_107 ( V_13 , V_226 ) ;
}
int F_108 ( int V_110 , const char * * V_111 , const char * V_92 V_105 )
{
bool V_234 = false ;
int V_235 = 0 ;
const char * V_236 = NULL ;
const struct V_203 V_237 [] = {
F_109 ( 'T' , L_81 , & V_69 ,
L_82 ) ,
F_110 ( 'e' , L_83 , & V_13 , L_83 ,
L_84 ,
V_238 ) ,
F_110 ( 0 , L_85 , & V_13 , L_85 ,
L_86 , V_239 ) ,
F_109 ( 'i' , L_87 , & V_52 ,
L_88 ) ,
F_111 ( 'p' , L_89 , & V_11 . V_121 , L_89 ,
L_90 ) ,
F_111 ( 't' , L_91 , & V_11 . V_194 , L_91 ,
L_92 ) ,
F_109 ( 'a' , L_93 , & V_11 . V_193 ,
L_94 ) ,
F_109 ( 'g' , L_95 , & V_122 ,
L_96 ) ,
F_109 ( 'c' , L_97 , & V_47 , L_98 ) ,
F_112 ( 'v' , L_99 , & V_85 ,
L_100 ) ,
F_113 ( 'r' , L_101 , & V_142 ,
L_102 ) ,
F_109 ( 'n' , L_103 , & V_195 ,
L_104 ) ,
F_112 ( 'd' , L_105 , & V_233 ,
L_106 ) ,
F_109 ( 'S' , L_107 , & V_137 ,
L_108 ) ,
F_114 ( 'B' , L_109 , NULL , NULL ,
L_110 ,
F_98 ) ,
F_111 ( 'C' , L_77 , & V_11 . V_12 , L_77 ,
L_111 ) ,
F_115 ( 'A' , L_112 , & V_93 ,
L_113 , V_102 ) ,
F_111 ( 'x' , L_114 , & V_97 , L_115 ,
L_116 ) ,
F_110 ( 'G' , L_117 , & V_13 , L_118 ,
L_119 , V_240 ) ,
F_111 ( 'o' , L_120 , & V_236 , L_121 , L_122 ) ,
F_109 ( 0 , L_123 , & V_234 , L_124 ) ,
F_113 ( 0 , L_125 , & V_235 ,
L_126 ) ,
F_111 ( 0 , L_127 , & V_136 , L_128 ,
L_129 ) ,
F_111 ( 0 , L_130 , & V_138 , L_128 ,
L_131 ) ,
F_116 ( 'I' , L_132 , & V_118 ,
L_133 ) ,
F_115 ( 0 , L_134 , & V_93 ,
L_135 , V_99 ) ,
F_115 ( 0 , L_136 , & V_93 ,
L_137 , V_101 ) ,
F_116 ( 'D' , L_138 , & V_54 ,
L_139 ) ,
F_117 ()
} ;
const char * const V_241 [] = {
L_140 ,
NULL
} ;
int V_116 = - V_124 , V_242 ;
const char * V_243 ;
setlocale ( V_244 , L_25 ) ;
V_13 = F_118 () ;
if ( V_13 == NULL )
return - V_20 ;
V_110 = F_119 ( V_110 , V_111 , V_237 , V_241 ,
V_245 ) ;
V_86 = V_231 ;
if ( V_236 && strcmp ( V_236 , L_141 ) )
V_86 = NULL ;
if ( V_236 && V_235 ) {
fprintf ( V_231 , L_142 ) ;
F_120 ( V_241 , V_237 , L_143 , 1 ) ;
F_120 ( NULL , V_237 , L_125 , 0 ) ;
goto V_246;
}
if ( V_235 < 0 ) {
fprintf ( V_231 , L_144 ) ;
F_120 ( V_241 , V_237 , L_125 , 0 ) ;
goto V_246;
}
if ( ! V_86 ) {
struct V_1 V_247 ;
V_243 = V_234 ? L_145 : L_146 ;
V_86 = fopen ( V_236 , V_243 ) ;
if ( ! V_86 ) {
perror ( L_147 ) ;
return - 1 ;
}
F_38 ( V_248 , & V_247 ) ;
fprintf ( V_86 , L_148 , ctime ( & V_247 . V_5 ) ) ;
} else if ( V_235 > 0 ) {
V_243 = V_234 ? L_145 : L_146 ;
V_86 = fdopen ( V_235 , V_243 ) ;
if ( ! V_86 ) {
perror ( L_149 ) ;
return - V_123 ;
}
}
if ( V_97 ) {
V_98 = true ;
if ( ! strcmp ( V_97 , L_150 ) )
V_97 = L_151 ;
} else
V_97 = V_249 ;
if ( V_98 ) {
if ( V_205 == 1 ) {
fprintf ( V_231 , L_152 ) ;
F_120 ( V_241 , V_237 , L_153 , 1 ) ;
F_120 ( NULL , V_237 , L_154 , 1 ) ;
goto V_246;
} else
V_165 = false ;
} else if ( V_205 == 0 )
V_165 = false ;
if ( ! V_110 && F_121 ( & V_11 ) )
F_122 ( V_241 , V_237 ) ;
if ( V_142 < 0 ) {
F_61 ( L_155 ) ;
F_120 ( V_241 , V_237 , L_156 , 1 ) ;
goto V_246;
} else if ( V_142 == 0 ) {
V_250 = true ;
V_142 = 1 ;
}
if ( ( V_93 != V_94 || V_251 ) &&
! F_20 ( & V_11 ) ) {
fprintf ( V_231 , L_157
L_158 ) ;
F_120 ( V_241 , V_237 , L_159 , 1 ) ;
F_120 ( NULL , V_237 , L_160 , 1 ) ;
F_120 ( NULL , V_237 , L_145 , 1 ) ;
goto V_246;
}
if ( F_104 () )
goto V_246;
F_123 ( & V_11 ) ;
if ( F_124 ( V_13 , & V_11 ) < 0 ) {
if ( F_22 ( & V_11 ) ) {
F_61 ( L_161 ) ;
F_120 ( V_241 , V_237 , L_162 , 1 ) ;
F_120 ( NULL , V_237 , L_163 , 1 ) ;
} else if ( F_20 ( & V_11 ) ) {
perror ( L_164 ) ;
F_120 ( V_241 , V_237 , L_165 , 1 ) ;
F_120 ( NULL , V_237 , L_145 , 1 ) ;
}
goto V_246;
}
if ( V_118 && V_118 < 100 ) {
F_61 ( L_166 ) ;
F_120 ( V_241 , V_237 , L_167 , 1 ) ;
goto V_246;
}
if ( F_15 ( V_13 , V_118 ) )
goto V_246;
if ( F_99 () )
goto V_246;
atexit ( F_93 ) ;
if ( ! V_250 )
signal ( V_252 , F_92 ) ;
signal ( V_199 , F_92 ) ;
signal ( V_253 , F_92 ) ;
signal ( V_254 , F_92 ) ;
V_116 = 0 ;
for ( V_242 = 0 ; V_250 || V_242 < V_142 ; V_242 ++ ) {
if ( V_142 != 1 && V_85 )
fprintf ( V_86 , L_168 ,
V_242 + 1 ) ;
V_116 = F_67 ( V_110 , V_111 ) ;
if ( V_250 && V_116 != - 1 ) {
F_91 ( V_110 , V_111 ) ;
F_17 ( V_13 ) ;
}
}
if ( ! V_250 && V_116 != - 1 && ! V_118 )
F_91 ( V_110 , V_111 ) ;
F_12 ( V_13 ) ;
V_246:
F_125 ( V_13 ) ;
return V_116 ;
}
