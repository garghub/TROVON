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
static void F_31 ( struct V_8 * V_65 )
{
if ( V_65 -> V_83 )
memset ( V_65 -> V_83 , 0 , V_84 ) ;
}
static int F_32 ( struct V_8 * V_65 , int V_85 , bool * V_86 )
{
unsigned long * V_87 = V_65 -> V_83 ;
struct V_7 * V_10 = F_2 ( V_65 ) ;
int V_88 ;
* V_86 = false ;
if ( ! V_65 -> V_89 )
return 0 ;
if ( F_33 ( V_10 ) )
return 0 ;
if ( ! V_87 ) {
V_87 = F_7 ( V_84 ) ;
if ( ! V_87 )
return - V_20 ;
V_65 -> V_83 = V_87 ;
}
V_88 = F_34 ( V_10 , V_85 ) ;
if ( V_88 < 0 )
return - 1 ;
* V_86 = F_35 ( V_88 , V_87 ) == 1 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 , int V_85 , int T_3 V_90 ,
struct V_24 * V_66 )
{
struct V_24 * V_91 = & V_9 -> V_23 -> V_91 ;
static struct V_24 V_92 ;
bool V_86 = false ;
if ( F_32 ( V_9 , V_85 , & V_86 ) ) {
F_37 ( L_1 ) ;
return - 1 ;
}
if ( V_86 )
V_66 = & V_92 ;
switch ( V_93 ) {
case V_94 :
case V_95 :
case V_96 :
if ( ! V_9 -> V_97 )
F_38 ( V_9 , V_85 , V_66 ) ;
F_39 ( V_66 , V_47 , NULL ) ;
V_9 -> V_23 -> V_85 [ V_85 ] = * V_66 ;
F_28 ( V_9 , V_66 -> V_98 ) ;
break;
case V_99 :
V_91 -> V_100 += V_66 -> V_100 ;
if ( V_47 ) {
V_91 -> V_101 += V_66 -> V_101 ;
V_91 -> V_102 += V_66 -> V_102 ;
}
default:
break;
}
return 0 ;
}
static int F_40 ( struct V_8 * V_65 )
{
struct V_24 * V_91 = & V_65 -> V_23 -> V_91 ;
struct V_16 * V_17 = V_65 -> V_18 ;
T_2 * V_66 = V_65 -> V_23 -> V_91 . V_98 ;
int V_15 ;
V_91 -> V_100 = V_91 -> V_101 = V_91 -> V_102 = 0 ;
if ( F_41 ( V_65 ) )
return - 1 ;
if ( ! V_65 -> V_97 )
F_38 ( V_65 , - 1 , V_91 ) ;
F_39 ( V_91 , V_47 , & V_65 -> V_23 -> V_103 ) ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_29 ( & V_17 -> V_19 [ V_15 ] , V_66 [ V_15 ] ) ;
if ( V_104 ) {
fprintf ( V_105 , L_2 V_106 L_3 V_106 L_3 V_106 L_4 ,
F_42 ( V_65 ) , V_66 [ 0 ] , V_66 [ 1 ] , V_66 [ 2 ] ) ;
}
F_28 ( V_65 , V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_65 )
{
int V_107 = F_43 ( V_13 -> V_56 ) ;
int V_108 = F_3 ( V_65 ) ;
int V_85 , T_3 ;
if ( V_65 -> V_109 )
V_107 = 1 ;
if ( V_65 -> V_89 )
F_31 ( V_65 ) ;
for ( T_3 = 0 ; T_3 < V_107 ; T_3 ++ ) {
for ( V_85 = 0 ; V_85 < V_108 ; V_85 ++ ) {
if ( F_44 ( V_65 , V_85 , T_3 , F_36 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_45 ( void )
{
static int V_110 ;
struct V_8 * V_65 ;
struct V_16 * V_17 ;
struct V_1 V_111 , V_112 ;
char V_113 [ 64 ] ;
if ( V_93 == V_99 ) {
F_13 (evsel_list, counter) {
V_17 = V_65 -> V_18 ;
memset ( V_17 -> V_19 , 0 , sizeof( V_17 -> V_19 ) ) ;
F_40 ( V_65 ) ;
}
} else {
F_13 (evsel_list, counter) {
V_17 = V_65 -> V_18 ;
memset ( V_17 -> V_19 , 0 , sizeof( V_17 -> V_19 ) ) ;
F_41 ( V_65 ) ;
}
}
F_46 ( V_114 , & V_111 ) ;
F_1 ( & V_112 , & V_111 , & V_115 ) ;
sprintf ( V_113 , L_5 , V_112 . V_5 , V_112 . V_6 , V_116 ) ;
if ( V_110 == 0 && ! V_117 ) {
switch ( V_93 ) {
case V_95 :
fprintf ( V_105 , L_6 , V_118 , L_7 ) ;
break;
case V_94 :
fprintf ( V_105 , L_8 , V_118 , L_7 ) ;
break;
case V_96 :
fprintf ( V_105 , L_9 , V_118 , L_7 ) ;
break;
case V_99 :
default:
fprintf ( V_105 , L_10 , V_118 , L_7 ) ;
}
}
if ( ++ V_110 == 25 )
V_110 = 0 ;
switch ( V_93 ) {
case V_94 :
case V_95 :
F_47 ( V_113 ) ;
break;
case V_96 :
F_13 (evsel_list, counter)
F_48 ( V_65 , V_113 ) ;
break;
case V_99 :
default:
F_13 (evsel_list, counter)
F_49 ( V_65 , V_113 ) ;
}
fflush ( V_105 ) ;
}
static void F_50 ( void )
{
struct V_8 * V_65 ;
if ( V_54 ) {
const int V_108 = F_51 ( V_13 -> V_10 ) ,
V_107 = F_43 ( V_13 -> V_56 ) ;
F_52 ( V_54 * 1000 ) ;
F_13 (evsel_list, counter)
F_53 ( V_65 , V_108 , V_107 ) ;
}
}
static void F_54 ( int T_4 V_90 , T_5 * V_119 ,
void * T_6 V_90 )
{
V_120 = V_119 -> V_121 . V_122 ;
}
static int F_55 ( int V_123 , const char * * V_124 )
{
char V_125 [ 512 ] ;
unsigned long long V_126 , V_127 ;
struct V_8 * V_65 ;
struct V_1 V_111 ;
T_1 V_128 ;
int V_129 = 0 ;
const bool V_130 = ( V_123 > 0 ) ;
if ( V_131 ) {
V_111 . V_5 = V_131 / 1000 ;
V_111 . V_6 = ( V_131 % 1000 ) * 1000000 ;
} else {
V_111 . V_5 = 1 ;
V_111 . V_6 = 0 ;
}
if ( V_130 ) {
if ( F_56 ( V_13 , & V_11 , V_124 , false ,
F_54 ) < 0 ) {
perror ( L_11 ) ;
return - 1 ;
}
V_132 = V_13 -> V_133 . V_134 ;
}
if ( V_135 )
F_57 ( V_13 ) ;
F_13 (evsel_list, counter) {
if ( F_19 ( V_65 ) < 0 ) {
if ( V_136 == V_137 || V_136 == V_138 ||
V_136 == V_139 || V_136 == V_140 ||
V_136 == V_141 ) {
if ( V_104 )
F_58 ( L_12 ,
F_42 ( V_65 ) ) ;
V_65 -> V_142 = false ;
continue;
}
F_59 ( V_65 , & V_11 ,
V_136 , V_125 , sizeof( V_125 ) ) ;
F_60 ( L_13 , V_125 ) ;
if ( V_132 != - 1 )
F_61 ( V_132 , V_143 ) ;
return - 1 ;
}
V_65 -> V_142 = true ;
V_128 = strlen ( V_65 -> V_144 ) ;
if ( V_128 > V_118 )
V_118 = V_128 ;
}
if ( F_62 ( V_13 ) ) {
error ( L_14 , V_136 ,
F_63 ( V_136 , V_125 , sizeof( V_125 ) ) ) ;
return - 1 ;
}
V_126 = F_64 () ;
F_46 ( V_114 , & V_115 ) ;
if ( V_130 ) {
F_65 ( V_13 ) ;
F_50 () ;
if ( V_131 ) {
while ( ! F_66 ( V_132 , & V_129 , V_145 ) ) {
F_67 ( & V_111 , NULL ) ;
F_45 () ;
}
}
F_68 ( & V_129 ) ;
if ( V_120 ) {
const char * V_146 = F_63 ( V_120 , V_125 , sizeof( V_125 ) ) ;
F_37 ( L_15 , V_146 ) ;
return - 1 ;
}
if ( F_69 ( V_129 ) )
F_70 ( F_71 ( V_129 ) , V_124 [ 0 ] ) ;
} else {
F_50 () ;
while ( ! V_147 ) {
F_67 ( & V_111 , NULL ) ;
if ( V_131 )
F_45 () ;
}
}
V_127 = F_64 () ;
F_29 ( & V_44 , V_127 - V_126 ) ;
if ( V_93 == V_99 ) {
F_13 (evsel_list, counter) {
F_40 ( V_65 ) ;
F_72 ( V_65 , F_3 ( V_65 ) ,
F_43 ( V_13 -> V_56 ) ) ;
}
} else {
F_13 (evsel_list, counter) {
F_41 ( V_65 ) ;
F_72 ( V_65 , F_3 ( V_65 ) , 1 ) ;
}
}
return F_73 ( V_129 ) ;
}
static int F_74 ( int V_123 , const char * * V_124 )
{
int V_148 ;
if ( V_149 ) {
V_148 = system ( V_149 ) ;
if ( V_148 )
return V_148 ;
}
if ( V_150 )
F_75 () ;
V_148 = F_55 ( V_123 , V_124 ) ;
if ( V_148 )
return V_148 ;
if ( V_151 ) {
V_148 = system ( V_151 ) ;
if ( V_148 )
return V_148 ;
}
return V_148 ;
}
static void F_76 ( double V_152 , double V_153 )
{
double V_154 = F_77 ( V_152 , V_153 ) ;
if ( V_117 )
fprintf ( V_105 , L_16 , V_116 , V_154 ) ;
else if ( V_154 )
fprintf ( V_105 , L_17 , V_154 ) ;
}
static void F_78 ( struct V_8 * V_9 , double V_153 )
{
struct V_16 * V_17 ;
if ( V_155 == 1 )
return;
V_17 = V_9 -> V_18 ;
F_76 ( F_79 ( & V_17 -> V_19 [ 0 ] ) , V_153 ) ;
}
static void F_80 ( struct V_8 * V_9 , int V_156 , int V_14 )
{
switch ( V_93 ) {
case V_94 :
fprintf ( V_105 , L_18 ,
F_81 ( V_156 ) ,
V_117 ? 0 : - 8 ,
F_82 ( V_156 ) ,
V_116 ,
V_117 ? 0 : 4 ,
V_14 ,
V_116 ) ;
break;
case V_95 :
fprintf ( V_105 , L_19 ,
V_117 ? 0 : - 5 ,
V_156 ,
V_116 ,
V_117 ? 0 : 4 ,
V_14 ,
V_116 ) ;
break;
case V_96 :
fprintf ( V_105 , L_20 ,
V_117 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_157 [ V_156 ] , V_116 ) ;
break;
case V_99 :
default:
break;
}
}
static void F_83 ( int V_156 , int V_14 , struct V_8 * V_9 , double V_153 )
{
double V_158 = V_153 / 1e6 ;
const char * V_159 , * V_160 ;
char V_161 [ 25 ] ;
V_159 = V_117 ? L_21 : L_22 ;
V_160 = V_117 ? L_23 : L_24 ;
F_80 ( V_9 , V_156 , V_14 ) ;
F_84 ( V_161 , sizeof( V_161 ) , L_25 ,
F_42 ( V_9 ) , V_117 ? L_26 : L_27 ) ;
fprintf ( V_105 , V_159 , V_158 , V_116 ) ;
if ( V_117 )
fprintf ( V_105 , L_25 , V_9 -> V_144 , V_116 ) ;
else
fprintf ( V_105 , L_28 , V_118 , V_9 -> V_144 , V_116 ) ;
fprintf ( V_105 , V_160 , V_161 ) ;
if ( V_9 -> V_162 )
fprintf ( V_105 , L_25 , V_116 , V_9 -> V_162 -> V_161 ) ;
if ( V_117 || V_131 )
return;
if ( F_26 ( V_9 , V_57 , V_59 ) )
fprintf ( V_105 , L_29 ,
V_153 / F_85 ( & V_44 ) ) ;
else
fprintf ( V_105 , L_30 ) ;
}
static const char * F_86 ( enum V_163 type , double V_164 )
{
static const double V_165 [ V_166 ] [ 3 ] = {
[ V_167 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_168 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_169 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_170 = V_171 ;
if ( V_164 > V_165 [ type ] [ 0 ] )
V_170 = V_172 ;
else if ( V_164 > V_165 [ type ] [ 1 ] )
V_170 = V_173 ;
else if ( V_164 > V_165 [ type ] [ 2 ] )
V_170 = V_174 ;
return V_170 ;
}
static void F_87 ( int V_85 ,
struct V_8 * V_9
V_90 , double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_31 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_167 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_33 ) ;
}
static void F_89 ( int V_85 ,
struct V_8 * V_9
V_90 , double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_31 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_168 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_34 ) ;
}
static void F_90 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_34 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_35 ) ;
}
static void F_91 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_36 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_36 ) ;
}
static void F_92 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_37 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_37 ) ;
}
static void F_93 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_40 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_38 ) ;
}
static void F_94 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_39 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_39 ) ;
}
static void F_95 ( int V_85 ,
struct V_8 * V_9 V_90 ,
double V_153 )
{
double V_152 , V_164 = 0.0 ;
const char * V_170 ;
V_152 = F_85 ( & V_38 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 / V_152 * 100.0 ;
V_170 = F_86 ( V_169 , V_164 ) ;
fprintf ( V_105 , L_31 ) ;
F_88 ( V_105 , V_170 , L_32 , V_164 ) ;
fprintf ( V_105 , L_40 ) ;
}
static void F_96 ( int V_156 , int V_14 , struct V_8 * V_9 , double V_153 )
{
double V_152 , V_164 = 0.0 , V_175 ;
double V_176 = V_9 -> V_47 ;
const char * V_177 ;
int V_85 = F_82 ( V_156 ) ;
if ( V_117 ) {
V_177 = V_176 != 1.0 ? L_41 : L_42 ;
} else {
if ( V_178 )
V_177 = V_176 != 1.0 ? L_43 : L_44 ;
else
V_177 = V_176 != 1.0 ? L_45 : L_46 ;
}
F_80 ( V_9 , V_156 , V_14 ) ;
if ( V_93 == V_99 )
V_85 = 0 ;
fprintf ( V_105 , V_177 , V_153 , V_116 ) ;
if ( V_9 -> V_144 )
fprintf ( V_105 , L_28 ,
V_117 ? 0 : V_118 ,
V_9 -> V_144 , V_116 ) ;
fprintf ( V_105 , L_47 , V_117 ? 0 : 25 , F_42 ( V_9 ) ) ;
if ( V_9 -> V_162 )
fprintf ( V_105 , L_25 , V_116 , V_9 -> V_162 -> V_161 ) ;
if ( V_117 || V_131 )
return;
if ( F_26 ( V_9 , V_67 , V_179 ) ) {
V_152 = F_85 ( & V_31 [ V_85 ] ) ;
if ( V_152 ) {
V_164 = V_153 / V_152 ;
fprintf ( V_105 , L_48 , V_164 ) ;
}
V_152 = F_85 ( & V_32 [ V_85 ] ) ;
V_152 = F_97 ( V_152 , F_85 ( & V_33 [ V_85 ] ) ) ;
if ( V_152 && V_153 ) {
V_164 = V_152 / V_153 ;
fprintf ( V_105 , L_4 ) ;
if ( V_93 == V_96 )
fprintf ( V_105 , L_49 ) ;
fprintf ( V_105 , L_50 , V_164 ) ;
}
} else if ( F_26 ( V_9 , V_67 , V_180 ) &&
V_34 [ V_85 ] . V_60 != 0 ) {
F_90 ( V_85 , V_9 , V_153 ) ;
} else if (
V_9 -> V_46 . type == V_181 &&
V_9 -> V_46 . V_182 == ( V_183 |
( ( V_184 ) << 8 ) |
( ( V_185 ) << 16 ) ) &&
V_36 [ V_85 ] . V_60 != 0 ) {
F_91 ( V_85 , V_9 , V_153 ) ;
} else if (
V_9 -> V_46 . type == V_181 &&
V_9 -> V_46 . V_182 == ( V_186 |
( ( V_184 ) << 8 ) |
( ( V_185 ) << 16 ) ) &&
V_37 [ V_85 ] . V_60 != 0 ) {
F_92 ( V_85 , V_9 , V_153 ) ;
} else if (
V_9 -> V_46 . type == V_181 &&
V_9 -> V_46 . V_182 == ( V_187 |
( ( V_184 ) << 8 ) |
( ( V_185 ) << 16 ) ) &&
V_40 [ V_85 ] . V_60 != 0 ) {
F_93 ( V_85 , V_9 , V_153 ) ;
} else if (
V_9 -> V_46 . type == V_181 &&
V_9 -> V_46 . V_182 == ( V_188 |
( ( V_184 ) << 8 ) |
( ( V_185 ) << 16 ) ) &&
V_39 [ V_85 ] . V_60 != 0 ) {
F_94 ( V_85 , V_9 , V_153 ) ;
} else if (
V_9 -> V_46 . type == V_181 &&
V_9 -> V_46 . V_182 == ( V_189 |
( ( V_184 ) << 8 ) |
( ( V_185 ) << 16 ) ) &&
V_38 [ V_85 ] . V_60 != 0 ) {
F_95 ( V_85 , V_9 , V_153 ) ;
} else if ( F_26 ( V_9 , V_67 , V_190 ) &&
V_35 [ V_85 ] . V_60 != 0 ) {
V_152 = F_85 ( & V_35 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_153 * 100 / V_152 ;
fprintf ( V_105 , L_51 , V_164 ) ;
} else if ( F_26 ( V_9 , V_67 , V_73 ) ) {
F_87 ( V_85 , V_9 , V_153 ) ;
} else if ( F_26 ( V_9 , V_67 , V_74 ) ) {
F_89 ( V_85 , V_9 , V_153 ) ;
} else if ( F_26 ( V_9 , V_67 , V_68 ) ) {
V_152 = F_85 ( & V_30 [ V_85 ] ) ;
if ( V_152 ) {
V_164 = V_153 / V_152 ;
fprintf ( V_105 , L_52 , V_164 ) ;
}
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_70 ) ) ) {
V_152 = F_85 ( & V_31 [ V_85 ] ) ;
if ( V_152 )
fprintf ( V_105 ,
L_53 ,
100.0 * ( V_153 / V_152 ) ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_191 ) ) ) {
V_152 = F_85 ( & V_31 [ V_85 ] ) ;
V_175 = F_85 ( & V_41 [ V_85 ] ) ;
if ( V_175 < V_153 )
V_175 = V_153 ;
if ( V_152 )
fprintf ( V_105 ,
L_54 ,
100.0 * ( ( V_175 - V_153 ) / V_152 ) ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_71 ) ) &&
V_153 > 0 &&
V_41 [ V_85 ] . V_60 != 0 ) {
V_152 = F_85 ( & V_41 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_152 / V_153 ;
fprintf ( V_105 , L_55 , V_164 ) ;
} else if ( V_69 &&
F_30 ( V_9 , F_27 ( V_72 ) ) &&
V_153 > 0 &&
V_41 [ V_85 ] . V_60 != 0 ) {
V_152 = F_85 ( & V_41 [ V_85 ] ) ;
if ( V_152 )
V_164 = V_152 / V_153 ;
fprintf ( V_105 , L_56 , V_164 ) ;
} else if ( V_30 [ V_85 ] . V_60 != 0 ) {
char V_144 = 'M' ;
V_152 = F_85 ( & V_30 [ V_85 ] ) ;
if ( V_152 )
V_164 = 1000.0 * V_153 / V_152 ;
if ( V_164 < 0.001 ) {
V_164 *= 1000 ;
V_144 = 'K' ;
}
fprintf ( V_105 , L_57 , V_164 , V_144 ) ;
} else {
fprintf ( V_105 , L_30 ) ;
}
}
static void F_47 ( char * V_113 )
{
struct V_8 * V_65 ;
int V_85 , V_192 , V_88 , V_193 , V_156 , V_14 ;
double V_194 ;
T_2 V_101 , V_102 , V_100 ;
if ( ! ( V_195 || V_196 ) )
return;
for ( V_88 = 0 ; V_88 < V_195 -> V_14 ; V_88 ++ ) {
V_156 = V_195 -> V_157 [ V_88 ] ;
F_13 (evsel_list, counter) {
V_100 = V_101 = V_102 = 0 ;
V_14 = 0 ;
for ( V_85 = 0 ; V_85 < F_3 ( V_65 ) ; V_85 ++ ) {
V_192 = F_2 ( V_65 ) -> V_157 [ V_85 ] ;
V_193 = V_196 ( V_13 -> V_10 , V_192 ) ;
if ( V_193 != V_156 )
continue;
V_100 += V_65 -> V_23 -> V_85 [ V_85 ] . V_100 ;
V_101 += V_65 -> V_23 -> V_85 [ V_85 ] . V_101 ;
V_102 += V_65 -> V_23 -> V_85 [ V_85 ] . V_102 ;
V_14 ++ ;
}
if ( V_113 )
fprintf ( V_105 , L_23 , V_113 ) ;
if ( V_102 == 0 || V_101 == 0 ) {
F_80 ( V_65 , V_156 , V_14 ) ;
fprintf ( V_105 , L_58 ,
V_117 ? 0 : 18 ,
V_65 -> V_142 ? V_197 : V_198 ,
V_116 ) ;
fprintf ( V_105 , L_28 ,
V_117 ? 0 : V_118 ,
V_65 -> V_144 , V_116 ) ;
fprintf ( V_105 , L_59 ,
V_117 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_162 )
fprintf ( V_105 , L_25 ,
V_116 , V_65 -> V_162 -> V_161 ) ;
fputc ( '\n' , V_105 ) ;
continue;
}
V_194 = V_100 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_83 ( V_156 , V_14 , V_65 , V_194 ) ;
else
F_96 ( V_156 , V_14 , V_65 , V_194 ) ;
if ( ! V_117 ) {
F_78 ( V_65 , 1.0 ) ;
if ( V_102 != V_101 )
fprintf ( V_105 , L_60 ,
100.0 * V_102 / V_101 ) ;
}
fputc ( '\n' , V_105 ) ;
}
}
}
static void F_49 ( struct V_8 * V_65 , char * V_113 )
{
struct V_16 * V_17 = V_65 -> V_18 ;
double V_153 = F_85 ( & V_17 -> V_19 [ 0 ] ) ;
int V_103 = V_65 -> V_23 -> V_103 ;
double V_194 ;
if ( V_113 )
fprintf ( V_105 , L_23 , V_113 ) ;
if ( V_103 == - 1 ) {
fprintf ( V_105 , L_58 ,
V_117 ? 0 : 18 ,
V_65 -> V_142 ? V_197 : V_198 ,
V_116 ) ;
fprintf ( V_105 , L_28 ,
V_117 ? 0 : V_118 ,
V_65 -> V_144 , V_116 ) ;
fprintf ( V_105 , L_59 ,
V_117 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_162 )
fprintf ( V_105 , L_25 , V_116 , V_65 -> V_162 -> V_161 ) ;
fputc ( '\n' , V_105 ) ;
return;
}
V_194 = V_153 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_83 ( - 1 , 0 , V_65 , V_194 ) ;
else
F_96 ( - 1 , 0 , V_65 , V_194 ) ;
F_78 ( V_65 , V_153 ) ;
if ( V_117 ) {
fputc ( '\n' , V_105 ) ;
return;
}
if ( V_103 ) {
double V_199 , V_200 ;
V_199 = F_85 ( & V_17 -> V_19 [ 1 ] ) ;
V_200 = F_85 ( & V_17 -> V_19 [ 2 ] ) ;
fprintf ( V_105 , L_61 , 100 * V_200 / V_199 ) ;
}
fprintf ( V_105 , L_4 ) ;
}
static void F_48 ( struct V_8 * V_65 , char * V_113 )
{
T_2 V_101 , V_102 , V_100 ;
double V_194 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < F_3 ( V_65 ) ; V_85 ++ ) {
V_100 = V_65 -> V_23 -> V_85 [ V_85 ] . V_100 ;
V_101 = V_65 -> V_23 -> V_85 [ V_85 ] . V_101 ;
V_102 = V_65 -> V_23 -> V_85 [ V_85 ] . V_102 ;
if ( V_113 )
fprintf ( V_105 , L_23 , V_113 ) ;
if ( V_102 == 0 || V_101 == 0 ) {
fprintf ( V_105 , L_62 ,
V_117 ? 0 : - 4 ,
F_2 ( V_65 ) -> V_157 [ V_85 ] , V_116 ,
V_117 ? 0 : 18 ,
V_65 -> V_142 ? V_197 : V_198 ,
V_116 ) ;
fprintf ( V_105 , L_28 ,
V_117 ? 0 : V_118 ,
V_65 -> V_144 , V_116 ) ;
fprintf ( V_105 , L_59 ,
V_117 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_162 )
fprintf ( V_105 , L_25 ,
V_116 , V_65 -> V_162 -> V_161 ) ;
fputc ( '\n' , V_105 ) ;
continue;
}
V_194 = V_100 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_83 ( V_85 , 0 , V_65 , V_194 ) ;
else
F_96 ( V_85 , 0 , V_65 , V_194 ) ;
if ( ! V_117 ) {
F_78 ( V_65 , 1.0 ) ;
if ( V_102 != V_101 )
fprintf ( V_105 , L_60 ,
100.0 * V_102 / V_101 ) ;
}
fputc ( '\n' , V_105 ) ;
}
}
static void F_98 ( int V_123 , const char * * V_124 )
{
struct V_8 * V_65 ;
int V_15 ;
fflush ( stdout ) ;
if ( ! V_117 ) {
fprintf ( V_105 , L_4 ) ;
fprintf ( V_105 , L_63 ) ;
if ( V_11 . V_109 )
fprintf ( V_105 , L_64 ) ;
else if ( V_11 . V_12 )
fprintf ( V_105 , L_65 , V_11 . V_12 ) ;
else if ( ! F_22 ( & V_11 ) ) {
fprintf ( V_105 , L_66 , V_124 [ 0 ] ) ;
for ( V_15 = 1 ; V_15 < V_123 ; V_15 ++ )
fprintf ( V_105 , L_67 , V_124 [ V_15 ] ) ;
} else if ( V_11 . V_134 )
fprintf ( V_105 , L_68 , V_11 . V_134 ) ;
else
fprintf ( V_105 , L_69 , V_11 . V_201 ) ;
fprintf ( V_105 , L_70 ) ;
if ( V_155 > 1 )
fprintf ( V_105 , L_71 , V_155 ) ;
fprintf ( V_105 , L_72 ) ;
}
switch ( V_93 ) {
case V_94 :
case V_95 :
F_47 ( NULL ) ;
break;
case V_99 :
F_13 (evsel_list, counter)
F_49 ( V_65 , NULL ) ;
break;
case V_96 :
F_13 (evsel_list, counter)
F_48 ( V_65 , NULL ) ;
break;
default:
break;
}
if ( ! V_117 ) {
if ( ! V_202 )
fprintf ( V_105 , L_4 ) ;
fprintf ( V_105 , L_73 ,
F_85 ( & V_44 ) / 1e9 ) ;
if ( V_155 > 1 ) {
fprintf ( V_105 , L_74 ) ;
F_76 ( F_79 ( & V_44 ) ,
F_85 ( & V_44 ) ) ;
}
fprintf ( V_105 , L_75 ) ;
}
}
static void F_99 ( int T_4 )
{
if ( ( V_132 == - 1 ) || V_131 )
V_147 = 1 ;
V_203 = T_4 ;
V_132 = - 1 ;
}
static void F_100 ( void )
{
T_7 V_204 , V_205 ;
F_101 ( & V_204 ) ;
F_102 ( & V_204 , V_206 ) ;
F_103 ( V_207 , & V_204 , & V_205 ) ;
if ( V_132 != - 1 )
F_61 ( V_132 , V_143 ) ;
F_103 ( V_208 , & V_205 , NULL ) ;
if ( V_203 == - 1 )
return;
signal ( V_203 , V_209 ) ;
F_61 ( F_104 () , V_203 ) ;
}
static int F_105 ( const struct V_210 * T_8 V_90 ,
const char * V_88 V_90 , int V_211 )
{
V_212 = V_211 ? 0 : 1 ;
return 0 ;
}
static int F_106 ( void )
{
switch ( V_93 ) {
case V_95 :
if ( F_107 ( V_13 -> V_10 , & V_195 ) ) {
perror ( L_76 ) ;
return - 1 ;
}
V_196 = F_34 ;
break;
case V_94 :
if ( F_108 ( V_13 -> V_10 , & V_195 ) ) {
perror ( L_77 ) ;
return - 1 ;
}
V_196 = V_213 ;
break;
case V_96 :
case V_99 :
default:
break;
}
return 0 ;
}
static int F_109 ( const char * const * V_214 , unsigned V_215 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_215 ; V_15 ++ ) {
if ( F_110 ( V_13 , V_214 [ V_15 ] ) )
return - 1 ;
}
return 0 ;
}
static int F_111 ( void )
{
struct V_45 V_216 [] = {
{ . type = V_217 , . V_182 = V_218 } ,
{ . type = V_217 , . V_182 = V_219 } ,
{ . type = V_217 , . V_182 = V_220 } ,
{ . type = V_217 , . V_182 = V_221 } ,
{ . type = V_222 , . V_182 = V_223 } ,
{ . type = V_222 , . V_182 = V_224 } ,
{ . type = V_222 , . V_182 = V_225 } ,
{ . type = V_222 , . V_182 = V_226 } ,
{ . type = V_222 , . V_182 = V_227 } ,
{ . type = V_222 , . V_182 = V_228 } ,
} ;
struct V_45 V_229 [] = {
{ . type = V_181 ,
. V_182 =
V_183 << 0 |
( V_184 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_183 << 0 |
( V_184 << 8 ) |
( V_185 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_189 << 0 |
( V_184 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_189 << 0 |
( V_184 << 8 ) |
( V_185 << 16 ) } ,
} ;
struct V_45 V_231 [] = {
{ . type = V_181 ,
. V_182 =
V_186 << 0 |
( V_184 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_186 << 0 |
( V_184 << 8 ) |
( V_185 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_187 << 0 |
( V_184 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_187 << 0 |
( V_184 << 8 ) |
( V_185 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_188 << 0 |
( V_184 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_188 << 0 |
( V_184 << 8 ) |
( V_185 << 16 ) } ,
} ;
struct V_45 V_232 [] = {
{ . type = V_181 ,
. V_182 =
V_183 << 0 |
( V_233 << 8 ) |
( V_230 << 16 ) } ,
{ . type = V_181 ,
. V_182 =
V_183 << 0 |
( V_233 << 8 ) |
( V_185 << 16 ) } ,
} ;
if ( V_202 )
return 0 ;
if ( V_69 ) {
int V_234 ;
if ( F_112 ( L_78 , L_79 ) &&
F_112 ( L_78 , L_80 ) )
V_234 = F_109 ( V_235 ,
F_113 ( V_235 ) ) ;
else
V_234 = F_109 ( V_236 ,
F_113 ( V_236 ) ) ;
if ( V_234 < 0 ) {
fprintf ( V_237 , L_81 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_13 -> V_238 ) {
if ( F_114 ( V_13 , V_216 ) < 0 )
return - 1 ;
}
if ( V_239 < 1 )
return 0 ;
if ( F_114 ( V_13 , V_229 ) < 0 )
return - 1 ;
if ( V_239 < 2 )
return 0 ;
if ( F_114 ( V_13 , V_231 ) < 0 )
return - 1 ;
if ( V_239 < 3 )
return 0 ;
return F_114 ( V_13 , V_232 ) ;
}
int F_115 ( int V_123 , const char * * V_124 , const char * V_113 V_90 )
{
bool V_240 = false ;
int V_241 = 0 ;
const char * V_242 = NULL ;
const struct V_210 V_243 [] = {
F_116 ( 'T' , L_82 , & V_69 ,
L_83 ) ,
F_117 ( 'e' , L_84 , & V_13 , L_84 ,
L_85 ,
V_244 ) ,
F_117 ( 0 , L_86 , & V_13 , L_86 ,
L_87 , V_245 ) ,
F_116 ( 'i' , L_88 , & V_52 ,
L_89 ) ,
F_118 ( 'p' , L_90 , & V_11 . V_134 , L_90 ,
L_91 ) ,
F_118 ( 't' , L_92 , & V_11 . V_201 , L_92 ,
L_93 ) ,
F_116 ( 'a' , L_94 , & V_11 . V_109 ,
L_95 ) ,
F_116 ( 'g' , L_96 , & V_135 ,
L_97 ) ,
F_116 ( 'c' , L_98 , & V_47 , L_99 ) ,
F_119 ( 'v' , L_100 , & V_104 ,
L_101 ) ,
F_120 ( 'r' , L_102 , & V_155 ,
L_103 ) ,
F_116 ( 'n' , L_104 , & V_202 ,
L_105 ) ,
F_119 ( 'd' , L_106 , & V_239 ,
L_107 ) ,
F_116 ( 'S' , L_108 , & V_150 ,
L_109 ) ,
F_121 ( 'B' , L_110 , NULL , NULL ,
L_111 ,
F_105 ) ,
F_118 ( 'C' , L_78 , & V_11 . V_12 , L_78 ,
L_112 ) ,
F_122 ( 'A' , L_113 , & V_93 ,
L_114 , V_96 ) ,
F_118 ( 'x' , L_115 , & V_116 , L_116 ,
L_117 ) ,
F_117 ( 'G' , L_118 , & V_13 , L_119 ,
L_120 , V_246 ) ,
F_118 ( 'o' , L_121 , & V_242 , L_122 , L_123 ) ,
F_116 ( 0 , L_124 , & V_240 , L_125 ) ,
F_120 ( 0 , L_126 , & V_241 ,
L_127 ) ,
F_118 ( 0 , L_128 , & V_149 , L_129 ,
L_130 ) ,
F_118 ( 0 , L_131 , & V_151 , L_129 ,
L_132 ) ,
F_123 ( 'I' , L_133 , & V_131 ,
L_134 ) ,
F_122 ( 0 , L_135 , & V_93 ,
L_136 , V_95 ) ,
F_122 ( 0 , L_137 , & V_93 ,
L_138 , V_94 ) ,
F_123 ( 'D' , L_139 , & V_54 ,
L_140 ) ,
F_124 ()
} ;
const char * const V_247 [] = {
L_141 ,
NULL
} ;
int V_129 = - V_137 , V_248 ;
const char * V_249 ;
setlocale ( V_250 , L_26 ) ;
V_13 = F_125 () ;
if ( V_13 == NULL )
return - V_20 ;
V_123 = F_126 ( V_123 , V_124 , V_243 , V_247 ,
V_251 ) ;
V_105 = V_237 ;
if ( V_242 && strcmp ( V_242 , L_142 ) )
V_105 = NULL ;
if ( V_242 && V_241 ) {
fprintf ( V_237 , L_143 ) ;
F_127 ( V_247 , V_243 , L_144 , 1 ) ;
F_127 ( NULL , V_243 , L_126 , 0 ) ;
goto V_252;
}
if ( V_241 < 0 ) {
fprintf ( V_237 , L_145 ) ;
F_127 ( V_247 , V_243 , L_126 , 0 ) ;
goto V_252;
}
if ( ! V_105 ) {
struct V_1 V_253 ;
V_249 = V_240 ? L_146 : L_147 ;
V_105 = fopen ( V_242 , V_249 ) ;
if ( ! V_105 ) {
perror ( L_148 ) ;
return - 1 ;
}
F_46 ( V_254 , & V_253 ) ;
fprintf ( V_105 , L_149 , ctime ( & V_253 . V_5 ) ) ;
} else if ( V_241 > 0 ) {
V_249 = V_240 ? L_146 : L_147 ;
V_105 = fdopen ( V_241 , V_249 ) ;
if ( ! V_105 ) {
perror ( L_150 ) ;
return - V_136 ;
}
}
if ( V_116 ) {
V_117 = true ;
if ( ! strcmp ( V_116 , L_151 ) )
V_116 = L_152 ;
} else
V_116 = V_255 ;
if ( V_117 ) {
if ( V_212 == 1 ) {
fprintf ( V_237 , L_153 ) ;
F_127 ( V_247 , V_243 , L_154 , 1 ) ;
F_127 ( NULL , V_243 , L_155 , 1 ) ;
goto V_252;
} else
V_178 = false ;
} else if ( V_212 == 0 )
V_178 = false ;
if ( ! V_123 && F_128 ( & V_11 ) )
F_129 ( V_247 , V_243 ) ;
if ( V_155 < 0 ) {
F_37 ( L_156 ) ;
F_127 ( V_247 , V_243 , L_157 , 1 ) ;
goto V_252;
} else if ( V_155 == 0 ) {
V_256 = true ;
V_155 = 1 ;
}
if ( ( V_93 != V_99 || V_257 ) &&
! F_20 ( & V_11 ) ) {
fprintf ( V_237 , L_158
L_159 ) ;
F_127 ( V_247 , V_243 , L_160 , 1 ) ;
F_127 ( NULL , V_243 , L_161 , 1 ) ;
F_127 ( NULL , V_243 , L_146 , 1 ) ;
goto V_252;
}
if ( F_111 () )
goto V_252;
F_130 ( & V_11 ) ;
if ( F_131 ( V_13 , & V_11 ) < 0 ) {
if ( F_22 ( & V_11 ) ) {
F_37 ( L_162 ) ;
F_127 ( V_247 , V_243 , L_163 , 1 ) ;
F_127 ( NULL , V_243 , L_164 , 1 ) ;
} else if ( F_20 ( & V_11 ) ) {
perror ( L_165 ) ;
F_127 ( V_247 , V_243 , L_166 , 1 ) ;
F_127 ( NULL , V_243 , L_146 , 1 ) ;
}
goto V_252;
}
if ( V_131 && V_131 < 100 ) {
F_37 ( L_167 ) ;
F_127 ( V_247 , V_243 , L_168 , 1 ) ;
goto V_252;
}
if ( F_15 ( V_13 , V_131 ) )
goto V_252;
if ( F_106 () )
goto V_252;
atexit ( F_100 ) ;
if ( ! V_256 )
signal ( V_258 , F_99 ) ;
signal ( V_206 , F_99 ) ;
signal ( V_259 , F_99 ) ;
signal ( V_260 , F_99 ) ;
V_129 = 0 ;
for ( V_248 = 0 ; V_256 || V_248 < V_155 ; V_248 ++ ) {
if ( V_155 != 1 && V_104 )
fprintf ( V_105 , L_169 ,
V_248 + 1 ) ;
V_129 = F_74 ( V_123 , V_124 ) ;
if ( V_256 && V_129 != - 1 ) {
F_98 ( V_123 , V_124 ) ;
F_17 ( V_13 ) ;
}
}
if ( ! V_256 && V_129 != - 1 && ! V_131 )
F_98 ( V_123 , V_124 ) ;
F_12 ( V_13 ) ;
V_252:
F_132 ( V_13 ) ;
return V_129 ;
}
