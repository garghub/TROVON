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
static void F_28 ( struct V_8 * V_65 , T_2 * V_66 ,
int V_67 )
{
if ( F_26 ( V_65 , V_57 , V_59 ) )
F_29 ( & V_30 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_68 , V_69 ) )
F_29 ( & V_31 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( V_70 &&
F_30 ( V_65 , F_27 ( V_71 ) ) )
F_29 ( & V_41 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( V_70 &&
F_30 ( V_65 , F_27 ( V_72 ) ) )
F_29 ( & V_42 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( V_70 &&
F_30 ( V_65 , F_27 ( V_73 ) ) )
F_29 ( & V_43 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_68 , V_74 ) )
F_29 ( & V_32 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_68 , V_75 ) )
F_29 ( & V_33 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_68 , V_76 ) )
F_29 ( & V_34 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_68 , V_77 ) )
F_29 ( & V_35 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_78 , V_79 ) )
F_29 ( & V_36 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_78 , V_80 ) )
F_29 ( & V_37 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_78 , V_81 ) )
F_29 ( & V_38 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_78 , V_82 ) )
F_29 ( & V_40 [ V_67 ] , V_66 [ 0 ] ) ;
else if ( F_26 ( V_65 , V_78 , V_83 ) )
F_29 ( & V_39 [ V_67 ] , V_66 [ 0 ] ) ;
}
static void F_31 ( struct V_8 * V_65 )
{
if ( V_65 -> V_84 )
memset ( V_65 -> V_84 , 0 , V_85 ) ;
}
static int F_32 ( struct V_8 * V_65 , int V_67 , bool * V_86 )
{
unsigned long * V_87 = V_65 -> V_84 ;
struct V_7 * V_10 = F_2 ( V_65 ) ;
int V_88 ;
* V_86 = false ;
if ( ! V_65 -> V_89 )
return 0 ;
if ( F_33 ( V_10 ) )
return 0 ;
if ( ! V_87 ) {
V_87 = F_7 ( V_85 ) ;
if ( ! V_87 )
return - V_20 ;
V_65 -> V_84 = V_87 ;
}
V_88 = F_34 ( V_10 , V_67 ) ;
if ( V_88 < 0 )
return - 1 ;
* V_86 = F_35 ( V_88 , V_87 ) == 1 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 , int V_67 , int T_3 V_90 ,
struct V_24 * V_66 )
{
struct V_24 * V_91 = & V_9 -> V_23 -> V_91 ;
static struct V_24 V_92 ;
bool V_86 = false ;
if ( F_32 ( V_9 , V_67 , & V_86 ) ) {
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
F_38 ( V_9 , V_67 , V_66 ) ;
F_39 ( V_66 , V_47 , NULL ) ;
V_9 -> V_23 -> V_67 [ V_67 ] = * V_66 ;
if ( V_93 == V_96 )
F_28 ( V_9 , V_66 -> V_98 , V_67 ) ;
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
F_28 ( V_65 , V_66 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_65 )
{
int V_107 = F_43 ( V_13 -> V_56 ) ;
int V_108 = F_3 ( V_65 ) ;
int V_67 , T_3 ;
if ( ! V_65 -> V_109 )
return - V_110 ;
if ( V_65 -> V_111 )
V_107 = 1 ;
if ( V_65 -> V_89 )
F_31 ( V_65 ) ;
for ( T_3 = 0 ; T_3 < V_107 ; T_3 ++ ) {
for ( V_67 = 0 ; V_67 < V_108 ; V_67 ++ ) {
if ( F_44 ( V_65 , V_67 , T_3 , F_36 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_45 ( void )
{
static int V_112 ;
struct V_8 * V_65 ;
struct V_16 * V_17 ;
struct V_1 V_113 , V_114 ;
char V_115 [ 64 ] ;
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
F_46 ( V_116 , & V_113 ) ;
F_1 ( & V_114 , & V_113 , & V_117 ) ;
sprintf ( V_115 , L_5 , V_114 . V_5 , V_114 . V_6 , V_118 ) ;
if ( V_112 == 0 && ! V_119 ) {
switch ( V_93 ) {
case V_95 :
fprintf ( V_105 , L_6 , V_120 , L_7 ) ;
break;
case V_94 :
fprintf ( V_105 , L_8 , V_120 , L_7 ) ;
break;
case V_96 :
fprintf ( V_105 , L_9 , V_120 , L_7 ) ;
break;
case V_99 :
default:
fprintf ( V_105 , L_10 , V_120 , L_7 ) ;
}
}
if ( ++ V_112 == 25 )
V_112 = 0 ;
switch ( V_93 ) {
case V_94 :
case V_95 :
F_47 ( V_115 ) ;
break;
case V_96 :
F_13 (evsel_list, counter)
F_48 ( V_65 , V_115 ) ;
break;
case V_99 :
default:
F_13 (evsel_list, counter)
F_49 ( V_65 , V_115 ) ;
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
static void F_54 ( int T_4 V_90 , T_5 * V_121 ,
void * T_6 V_90 )
{
V_122 = V_121 -> V_123 . V_124 ;
}
static int F_55 ( int V_125 , const char * * V_126 )
{
char V_127 [ 512 ] ;
unsigned long long V_128 , V_129 ;
struct V_8 * V_65 ;
struct V_1 V_113 ;
T_1 V_130 ;
int V_131 = 0 ;
const bool V_132 = ( V_125 > 0 ) ;
if ( V_133 ) {
V_113 . V_5 = V_133 / 1000 ;
V_113 . V_6 = ( V_133 % 1000 ) * 1000000 ;
} else {
V_113 . V_5 = 1 ;
V_113 . V_6 = 0 ;
}
if ( V_132 ) {
if ( F_56 ( V_13 , & V_11 , V_126 , false ,
F_54 ) < 0 ) {
perror ( L_11 ) ;
return - 1 ;
}
V_134 = V_13 -> V_135 . V_136 ;
}
if ( V_137 )
F_57 ( V_13 ) ;
F_13 (evsel_list, counter) {
if ( F_19 ( V_65 ) < 0 ) {
if ( V_138 == V_139 || V_138 == V_140 ||
V_138 == V_110 || V_138 == V_141 ||
V_138 == V_142 ) {
if ( V_104 )
F_58 ( L_12 ,
F_42 ( V_65 ) ) ;
V_65 -> V_109 = false ;
continue;
}
F_59 ( V_65 , & V_11 ,
V_138 , V_127 , sizeof( V_127 ) ) ;
F_60 ( L_13 , V_127 ) ;
if ( V_134 != - 1 )
F_61 ( V_134 , V_143 ) ;
return - 1 ;
}
V_65 -> V_109 = true ;
V_130 = strlen ( V_65 -> V_144 ) ;
if ( V_130 > V_120 )
V_120 = V_130 ;
}
if ( F_62 ( V_13 , & V_65 ) ) {
error ( L_14 ,
V_65 -> V_145 , F_42 ( V_65 ) , V_138 ,
F_63 ( V_138 , V_127 , sizeof( V_127 ) ) ) ;
return - 1 ;
}
V_128 = F_64 () ;
F_46 ( V_116 , & V_117 ) ;
if ( V_132 ) {
F_65 ( V_13 ) ;
F_50 () ;
if ( V_133 ) {
while ( ! F_66 ( V_134 , & V_131 , V_146 ) ) {
F_67 ( & V_113 , NULL ) ;
F_45 () ;
}
}
F_68 ( & V_131 ) ;
if ( V_122 ) {
const char * V_147 = F_63 ( V_122 , V_127 , sizeof( V_127 ) ) ;
F_37 ( L_15 , V_147 ) ;
return - 1 ;
}
if ( F_69 ( V_131 ) )
F_70 ( F_71 ( V_131 ) , V_126 [ 0 ] ) ;
} else {
F_50 () ;
while ( ! V_148 ) {
F_67 ( & V_113 , NULL ) ;
if ( V_133 )
F_45 () ;
}
}
V_129 = F_64 () ;
F_29 ( & V_44 , V_129 - V_128 ) ;
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
return F_73 ( V_131 ) ;
}
static int F_74 ( int V_125 , const char * * V_126 )
{
int V_149 ;
if ( V_150 ) {
V_149 = system ( V_150 ) ;
if ( V_149 )
return V_149 ;
}
if ( V_151 )
F_75 () ;
V_149 = F_55 ( V_125 , V_126 ) ;
if ( V_149 )
return V_149 ;
if ( V_152 ) {
V_149 = system ( V_152 ) ;
if ( V_149 )
return V_149 ;
}
return V_149 ;
}
static void F_76 ( T_2 V_102 , T_2 V_101 )
{
if ( V_119 ) {
fprintf ( V_105 , L_16 V_106 L_17 ,
V_118 ,
V_102 ,
V_118 ,
V_101 ? 100.0 * V_102 / V_101 : 100.0 ) ;
} else if ( V_102 != V_101 ) {
fprintf ( V_105 , L_18 , 100.0 * V_102 / V_101 ) ;
}
}
static void F_77 ( double V_153 , double V_154 )
{
double V_155 = F_78 ( V_153 , V_154 ) ;
if ( V_119 )
fprintf ( V_105 , L_19 , V_118 , V_155 ) ;
else if ( V_155 )
fprintf ( V_105 , L_20 , V_155 ) ;
}
static void F_79 ( struct V_8 * V_9 , double V_154 )
{
struct V_16 * V_17 ;
if ( V_156 == 1 )
return;
V_17 = V_9 -> V_18 ;
F_77 ( F_80 ( & V_17 -> V_19 [ 0 ] ) , V_154 ) ;
}
static void F_81 ( struct V_8 * V_9 , int V_157 , int V_14 )
{
switch ( V_93 ) {
case V_94 :
fprintf ( V_105 , L_21 ,
F_82 ( V_157 ) ,
V_119 ? 0 : - 8 ,
F_83 ( V_157 ) ,
V_118 ,
V_119 ? 0 : 4 ,
V_14 ,
V_118 ) ;
break;
case V_95 :
fprintf ( V_105 , L_22 ,
V_119 ? 0 : - 5 ,
V_157 ,
V_118 ,
V_119 ? 0 : 4 ,
V_14 ,
V_118 ) ;
break;
case V_96 :
fprintf ( V_105 , L_23 ,
V_119 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_158 [ V_157 ] , V_118 ) ;
break;
case V_99 :
default:
break;
}
}
static void F_84 ( int V_157 , int V_14 , struct V_8 * V_9 , double V_154 )
{
double V_159 = V_154 / 1e6 ;
const char * V_160 , * V_161 ;
char V_162 [ 25 ] ;
V_160 = V_119 ? L_24 : L_25 ;
V_161 = V_119 ? L_26 : L_27 ;
F_81 ( V_9 , V_157 , V_14 ) ;
F_85 ( V_162 , sizeof( V_162 ) , L_28 ,
F_42 ( V_9 ) , V_119 ? L_29 : L_30 ) ;
fprintf ( V_105 , V_160 , V_159 , V_118 ) ;
if ( V_119 )
fprintf ( V_105 , L_28 , V_9 -> V_144 , V_118 ) ;
else
fprintf ( V_105 , L_31 , V_120 , V_9 -> V_144 , V_118 ) ;
fprintf ( V_105 , V_161 , V_162 ) ;
if ( V_9 -> V_163 )
fprintf ( V_105 , L_28 , V_118 , V_9 -> V_163 -> V_162 ) ;
if ( V_119 || V_133 )
return;
if ( F_26 ( V_9 , V_57 , V_59 ) )
fprintf ( V_105 , L_32 ,
V_154 / F_86 ( & V_44 ) ) ;
else
fprintf ( V_105 , L_33 ) ;
}
static const char * F_87 ( enum V_164 type , double V_165 )
{
static const double V_166 [ V_167 ] [ 3 ] = {
[ V_168 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_169 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_170 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_171 = V_172 ;
if ( V_165 > V_166 [ type ] [ 0 ] )
V_171 = V_173 ;
else if ( V_165 > V_166 [ type ] [ 1 ] )
V_171 = V_174 ;
else if ( V_165 > V_166 [ type ] [ 2 ] )
V_171 = V_175 ;
return V_171 ;
}
static void F_88 ( int V_67 ,
struct V_8 * V_9
V_90 , double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_31 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_168 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_36 ) ;
}
static void F_90 ( int V_67 ,
struct V_8 * V_9
V_90 , double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_31 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_169 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_37 ) ;
}
static void F_91 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_34 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_38 ) ;
}
static void F_92 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_36 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_39 ) ;
}
static void F_93 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_37 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_40 ) ;
}
static void F_94 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_40 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_41 ) ;
}
static void F_95 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_39 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_42 ) ;
}
static void F_96 ( int V_67 ,
struct V_8 * V_9 V_90 ,
double V_154 )
{
double V_153 , V_165 = 0.0 ;
const char * V_171 ;
V_153 = F_86 ( & V_38 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 / V_153 * 100.0 ;
V_171 = F_87 ( V_170 , V_165 ) ;
fprintf ( V_105 , L_34 ) ;
F_89 ( V_105 , V_171 , L_35 , V_165 ) ;
fprintf ( V_105 , L_43 ) ;
}
static void F_97 ( int V_157 , int V_14 , struct V_8 * V_9 , double V_154 )
{
double V_153 , V_165 = 0.0 , V_176 ;
double V_177 = V_9 -> V_47 ;
const char * V_178 ;
int V_67 = F_83 ( V_157 ) ;
if ( V_119 ) {
V_178 = V_177 != 1.0 ? L_44 : L_45 ;
} else {
if ( V_179 )
V_178 = V_177 != 1.0 ? L_46 : L_47 ;
else
V_178 = V_177 != 1.0 ? L_48 : L_49 ;
}
F_81 ( V_9 , V_157 , V_14 ) ;
if ( V_93 == V_99 )
V_67 = 0 ;
fprintf ( V_105 , V_178 , V_154 , V_118 ) ;
if ( V_9 -> V_144 )
fprintf ( V_105 , L_31 ,
V_119 ? 0 : V_120 ,
V_9 -> V_144 , V_118 ) ;
fprintf ( V_105 , L_50 , V_119 ? 0 : 25 , F_42 ( V_9 ) ) ;
if ( V_9 -> V_163 )
fprintf ( V_105 , L_28 , V_118 , V_9 -> V_163 -> V_162 ) ;
if ( V_119 || V_133 )
return;
if ( F_26 ( V_9 , V_68 , V_180 ) ) {
V_153 = F_86 ( & V_31 [ V_67 ] ) ;
if ( V_153 ) {
V_165 = V_154 / V_153 ;
fprintf ( V_105 , L_51 , V_165 ) ;
} else {
fprintf ( V_105 , L_33 ) ;
}
V_153 = F_86 ( & V_32 [ V_67 ] ) ;
V_153 = F_98 ( V_153 , F_86 ( & V_33 [ V_67 ] ) ) ;
if ( V_153 && V_154 ) {
V_165 = V_153 / V_154 ;
fprintf ( V_105 , L_4 ) ;
if ( V_93 == V_96 )
fprintf ( V_105 , L_52 ) ;
fprintf ( V_105 , L_53 , V_165 ) ;
}
} else if ( F_26 ( V_9 , V_68 , V_181 ) &&
V_34 [ V_67 ] . V_60 != 0 ) {
F_91 ( V_67 , V_9 , V_154 ) ;
} else if (
V_9 -> V_46 . type == V_182 &&
V_9 -> V_46 . V_183 == ( V_184 |
( ( V_185 ) << 8 ) |
( ( V_186 ) << 16 ) ) &&
V_36 [ V_67 ] . V_60 != 0 ) {
F_92 ( V_67 , V_9 , V_154 ) ;
} else if (
V_9 -> V_46 . type == V_182 &&
V_9 -> V_46 . V_183 == ( V_187 |
( ( V_185 ) << 8 ) |
( ( V_186 ) << 16 ) ) &&
V_37 [ V_67 ] . V_60 != 0 ) {
F_93 ( V_67 , V_9 , V_154 ) ;
} else if (
V_9 -> V_46 . type == V_182 &&
V_9 -> V_46 . V_183 == ( V_188 |
( ( V_185 ) << 8 ) |
( ( V_186 ) << 16 ) ) &&
V_40 [ V_67 ] . V_60 != 0 ) {
F_94 ( V_67 , V_9 , V_154 ) ;
} else if (
V_9 -> V_46 . type == V_182 &&
V_9 -> V_46 . V_183 == ( V_189 |
( ( V_185 ) << 8 ) |
( ( V_186 ) << 16 ) ) &&
V_39 [ V_67 ] . V_60 != 0 ) {
F_95 ( V_67 , V_9 , V_154 ) ;
} else if (
V_9 -> V_46 . type == V_182 &&
V_9 -> V_46 . V_183 == ( V_190 |
( ( V_185 ) << 8 ) |
( ( V_186 ) << 16 ) ) &&
V_38 [ V_67 ] . V_60 != 0 ) {
F_96 ( V_67 , V_9 , V_154 ) ;
} else if ( F_26 ( V_9 , V_68 , V_191 ) &&
V_35 [ V_67 ] . V_60 != 0 ) {
V_153 = F_86 ( & V_35 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_154 * 100 / V_153 ;
fprintf ( V_105 , L_54 , V_165 ) ;
} else if ( F_26 ( V_9 , V_68 , V_74 ) ) {
F_88 ( V_67 , V_9 , V_154 ) ;
} else if ( F_26 ( V_9 , V_68 , V_75 ) ) {
F_90 ( V_67 , V_9 , V_154 ) ;
} else if ( F_26 ( V_9 , V_68 , V_69 ) ) {
V_153 = F_86 ( & V_30 [ V_67 ] ) ;
if ( V_153 ) {
V_165 = V_154 / V_153 ;
fprintf ( V_105 , L_55 , V_165 ) ;
} else {
fprintf ( V_105 , L_33 ) ;
}
} else if ( V_70 &&
F_30 ( V_9 , F_27 ( V_71 ) ) ) {
V_153 = F_86 ( & V_31 [ V_67 ] ) ;
if ( V_153 )
fprintf ( V_105 ,
L_56 ,
100.0 * ( V_154 / V_153 ) ) ;
} else if ( V_70 &&
F_30 ( V_9 , F_27 ( V_192 ) ) ) {
V_153 = F_86 ( & V_31 [ V_67 ] ) ;
V_176 = F_86 ( & V_41 [ V_67 ] ) ;
if ( V_176 < V_154 )
V_176 = V_154 ;
if ( V_153 )
fprintf ( V_105 ,
L_57 ,
100.0 * ( ( V_176 - V_154 ) / V_153 ) ) ;
} else if ( V_70 &&
F_30 ( V_9 , F_27 ( V_72 ) ) &&
V_154 > 0 &&
V_41 [ V_67 ] . V_60 != 0 ) {
V_153 = F_86 ( & V_41 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_153 / V_154 ;
fprintf ( V_105 , L_58 , V_165 ) ;
} else if ( V_70 &&
F_30 ( V_9 , F_27 ( V_73 ) ) &&
V_154 > 0 &&
V_41 [ V_67 ] . V_60 != 0 ) {
V_153 = F_86 ( & V_41 [ V_67 ] ) ;
if ( V_153 )
V_165 = V_153 / V_154 ;
fprintf ( V_105 , L_59 , V_165 ) ;
} else if ( V_30 [ V_67 ] . V_60 != 0 ) {
char V_144 = 'M' ;
V_153 = F_86 ( & V_30 [ V_67 ] ) ;
if ( V_153 )
V_165 = 1000.0 * V_154 / V_153 ;
if ( V_165 < 0.001 ) {
V_165 *= 1000 ;
V_144 = 'K' ;
}
fprintf ( V_105 , L_60 , V_165 , V_144 ) ;
} else {
fprintf ( V_105 , L_33 ) ;
}
}
static void F_47 ( char * V_115 )
{
struct V_8 * V_65 ;
int V_67 , V_193 , V_88 , V_194 , V_157 , V_14 ;
double V_195 ;
T_2 V_101 , V_102 , V_100 ;
if ( ! ( V_196 || V_197 ) )
return;
for ( V_88 = 0 ; V_88 < V_196 -> V_14 ; V_88 ++ ) {
V_157 = V_196 -> V_158 [ V_88 ] ;
F_13 (evsel_list, counter) {
V_100 = V_101 = V_102 = 0 ;
V_14 = 0 ;
for ( V_67 = 0 ; V_67 < F_3 ( V_65 ) ; V_67 ++ ) {
V_193 = F_2 ( V_65 ) -> V_158 [ V_67 ] ;
V_194 = V_197 ( V_13 -> V_10 , V_193 ) ;
if ( V_194 != V_157 )
continue;
V_100 += V_65 -> V_23 -> V_67 [ V_67 ] . V_100 ;
V_101 += V_65 -> V_23 -> V_67 [ V_67 ] . V_101 ;
V_102 += V_65 -> V_23 -> V_67 [ V_67 ] . V_102 ;
V_14 ++ ;
}
if ( V_115 )
fprintf ( V_105 , L_26 , V_115 ) ;
if ( V_102 == 0 || V_101 == 0 ) {
F_81 ( V_65 , V_157 , V_14 ) ;
fprintf ( V_105 , L_61 ,
V_119 ? 0 : 18 ,
V_65 -> V_109 ? V_198 : V_199 ,
V_118 ) ;
fprintf ( V_105 , L_31 ,
V_119 ? 0 : V_120 ,
V_65 -> V_144 , V_118 ) ;
fprintf ( V_105 , L_62 ,
V_119 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_163 )
fprintf ( V_105 , L_28 ,
V_118 , V_65 -> V_163 -> V_162 ) ;
F_76 ( V_102 , V_101 ) ;
fputc ( '\n' , V_105 ) ;
continue;
}
V_195 = V_100 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_84 ( V_157 , V_14 , V_65 , V_195 ) ;
else
F_97 ( V_157 , V_14 , V_65 , V_195 ) ;
if ( ! V_119 )
F_79 ( V_65 , 1.0 ) ;
F_76 ( V_102 , V_101 ) ;
fputc ( '\n' , V_105 ) ;
}
}
}
static void F_49 ( struct V_8 * V_65 , char * V_115 )
{
struct V_16 * V_17 = V_65 -> V_18 ;
double V_154 = F_86 ( & V_17 -> V_19 [ 0 ] ) ;
int V_103 = V_65 -> V_23 -> V_103 ;
double V_195 ;
double V_200 , V_201 ;
V_200 = F_86 ( & V_17 -> V_19 [ 1 ] ) ;
V_201 = F_86 ( & V_17 -> V_19 [ 2 ] ) ;
if ( V_115 )
fprintf ( V_105 , L_26 , V_115 ) ;
if ( V_103 == - 1 || ! V_65 -> V_109 ) {
fprintf ( V_105 , L_61 ,
V_119 ? 0 : 18 ,
V_65 -> V_109 ? V_198 : V_199 ,
V_118 ) ;
fprintf ( V_105 , L_31 ,
V_119 ? 0 : V_120 ,
V_65 -> V_144 , V_118 ) ;
fprintf ( V_105 , L_62 ,
V_119 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_163 )
fprintf ( V_105 , L_28 , V_118 , V_65 -> V_163 -> V_162 ) ;
F_76 ( V_201 , V_200 ) ;
fputc ( '\n' , V_105 ) ;
return;
}
V_195 = V_154 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_84 ( - 1 , 0 , V_65 , V_195 ) ;
else
F_97 ( - 1 , 0 , V_65 , V_195 ) ;
F_79 ( V_65 , V_154 ) ;
F_76 ( V_201 , V_200 ) ;
fprintf ( V_105 , L_4 ) ;
}
static void F_48 ( struct V_8 * V_65 , char * V_115 )
{
T_2 V_101 , V_102 , V_100 ;
double V_195 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < F_3 ( V_65 ) ; V_67 ++ ) {
V_100 = V_65 -> V_23 -> V_67 [ V_67 ] . V_100 ;
V_101 = V_65 -> V_23 -> V_67 [ V_67 ] . V_101 ;
V_102 = V_65 -> V_23 -> V_67 [ V_67 ] . V_102 ;
if ( V_115 )
fprintf ( V_105 , L_26 , V_115 ) ;
if ( V_102 == 0 || V_101 == 0 ) {
fprintf ( V_105 , L_63 ,
V_119 ? 0 : - 4 ,
F_2 ( V_65 ) -> V_158 [ V_67 ] , V_118 ,
V_119 ? 0 : 18 ,
V_65 -> V_109 ? V_198 : V_199 ,
V_118 ) ;
fprintf ( V_105 , L_31 ,
V_119 ? 0 : V_120 ,
V_65 -> V_144 , V_118 ) ;
fprintf ( V_105 , L_62 ,
V_119 ? 0 : - 25 ,
F_42 ( V_65 ) ) ;
if ( V_65 -> V_163 )
fprintf ( V_105 , L_28 ,
V_118 , V_65 -> V_163 -> V_162 ) ;
F_76 ( V_102 , V_101 ) ;
fputc ( '\n' , V_105 ) ;
continue;
}
V_195 = V_100 * V_65 -> V_47 ;
if ( F_25 ( V_65 ) )
F_84 ( V_67 , 0 , V_65 , V_195 ) ;
else
F_97 ( V_67 , 0 , V_65 , V_195 ) ;
if ( ! V_119 )
F_79 ( V_65 , 1.0 ) ;
F_76 ( V_102 , V_101 ) ;
fputc ( '\n' , V_105 ) ;
}
}
static void F_99 ( int V_125 , const char * * V_126 )
{
struct V_8 * V_65 ;
int V_15 ;
fflush ( stdout ) ;
if ( ! V_119 ) {
fprintf ( V_105 , L_4 ) ;
fprintf ( V_105 , L_64 ) ;
if ( V_11 . V_111 )
fprintf ( V_105 , L_65 ) ;
else if ( V_11 . V_12 )
fprintf ( V_105 , L_66 , V_11 . V_12 ) ;
else if ( ! F_22 ( & V_11 ) ) {
fprintf ( V_105 , L_67 , V_126 [ 0 ] ) ;
for ( V_15 = 1 ; V_15 < V_125 ; V_15 ++ )
fprintf ( V_105 , L_68 , V_126 [ V_15 ] ) ;
} else if ( V_11 . V_136 )
fprintf ( V_105 , L_69 , V_11 . V_136 ) ;
else
fprintf ( V_105 , L_70 , V_11 . V_202 ) ;
fprintf ( V_105 , L_71 ) ;
if ( V_156 > 1 )
fprintf ( V_105 , L_72 , V_156 ) ;
fprintf ( V_105 , L_73 ) ;
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
if ( ! V_119 ) {
if ( ! V_203 )
fprintf ( V_105 , L_4 ) ;
fprintf ( V_105 , L_74 ,
F_86 ( & V_44 ) / 1e9 ) ;
if ( V_156 > 1 ) {
fprintf ( V_105 , L_75 ) ;
F_77 ( F_80 ( & V_44 ) ,
F_86 ( & V_44 ) ) ;
}
fprintf ( V_105 , L_76 ) ;
}
}
static void F_100 ( int T_4 )
{
if ( ( V_134 == - 1 ) || V_133 )
V_148 = 1 ;
V_204 = T_4 ;
V_134 = - 1 ;
}
static void F_101 ( void )
{
T_7 V_205 , V_206 ;
F_102 ( & V_205 ) ;
F_103 ( & V_205 , V_207 ) ;
F_104 ( V_208 , & V_205 , & V_206 ) ;
if ( V_134 != - 1 )
F_61 ( V_134 , V_143 ) ;
F_104 ( V_209 , & V_206 , NULL ) ;
if ( V_204 == - 1 )
return;
signal ( V_204 , V_210 ) ;
F_61 ( F_105 () , V_204 ) ;
}
static int F_106 ( const struct V_211 * T_8 V_90 ,
const char * V_88 V_90 , int V_212 )
{
V_213 = V_212 ? 0 : 1 ;
return 0 ;
}
static int F_107 ( void )
{
switch ( V_93 ) {
case V_95 :
if ( F_108 ( V_13 -> V_10 , & V_196 ) ) {
perror ( L_77 ) ;
return - 1 ;
}
V_197 = F_34 ;
break;
case V_94 :
if ( F_109 ( V_13 -> V_10 , & V_196 ) ) {
perror ( L_78 ) ;
return - 1 ;
}
V_197 = V_214 ;
break;
case V_96 :
case V_99 :
default:
break;
}
return 0 ;
}
static int F_110 ( const char * const * V_215 , unsigned V_216 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_216 ; V_15 ++ ) {
if ( F_111 ( V_13 , V_215 [ V_15 ] ) )
return - 1 ;
}
return 0 ;
}
static int F_112 ( void )
{
struct V_45 V_217 [] = {
{ . type = V_218 , . V_183 = V_219 } ,
{ . type = V_218 , . V_183 = V_220 } ,
{ . type = V_218 , . V_183 = V_221 } ,
{ . type = V_218 , . V_183 = V_222 } ,
{ . type = V_223 , . V_183 = V_224 } ,
{ . type = V_223 , . V_183 = V_225 } ,
{ . type = V_223 , . V_183 = V_226 } ,
{ . type = V_223 , . V_183 = V_227 } ,
{ . type = V_223 , . V_183 = V_228 } ,
{ . type = V_223 , . V_183 = V_229 } ,
} ;
struct V_45 V_230 [] = {
{ . type = V_182 ,
. V_183 =
V_184 << 0 |
( V_185 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_184 << 0 |
( V_185 << 8 ) |
( V_186 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_190 << 0 |
( V_185 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_190 << 0 |
( V_185 << 8 ) |
( V_186 << 16 ) } ,
} ;
struct V_45 V_232 [] = {
{ . type = V_182 ,
. V_183 =
V_187 << 0 |
( V_185 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_187 << 0 |
( V_185 << 8 ) |
( V_186 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_188 << 0 |
( V_185 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_188 << 0 |
( V_185 << 8 ) |
( V_186 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_189 << 0 |
( V_185 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_189 << 0 |
( V_185 << 8 ) |
( V_186 << 16 ) } ,
} ;
struct V_45 V_233 [] = {
{ . type = V_182 ,
. V_183 =
V_184 << 0 |
( V_234 << 8 ) |
( V_231 << 16 ) } ,
{ . type = V_182 ,
. V_183 =
V_184 << 0 |
( V_234 << 8 ) |
( V_186 << 16 ) } ,
} ;
if ( V_203 )
return 0 ;
if ( V_70 ) {
int V_235 ;
if ( F_113 ( L_79 , L_80 ) &&
F_113 ( L_79 , L_81 ) )
V_235 = F_110 ( V_236 ,
F_114 ( V_236 ) ) ;
else
V_235 = F_110 ( V_237 ,
F_114 ( V_237 ) ) ;
if ( V_235 < 0 ) {
fprintf ( V_238 , L_82 ) ;
return - 1 ;
}
return 0 ;
}
if ( ! V_13 -> V_239 ) {
if ( F_115 ( V_13 , V_217 ) < 0 )
return - 1 ;
}
if ( V_240 < 1 )
return 0 ;
if ( F_115 ( V_13 , V_230 ) < 0 )
return - 1 ;
if ( V_240 < 2 )
return 0 ;
if ( F_115 ( V_13 , V_232 ) < 0 )
return - 1 ;
if ( V_240 < 3 )
return 0 ;
return F_115 ( V_13 , V_233 ) ;
}
int F_116 ( int V_125 , const char * * V_126 , const char * V_115 V_90 )
{
bool V_241 = false ;
int V_242 = 0 ;
const char * V_243 = NULL ;
const struct V_211 V_244 [] = {
F_117 ( 'T' , L_83 , & V_70 ,
L_84 ) ,
F_118 ( 'e' , L_85 , & V_13 , L_85 ,
L_86 ,
V_245 ) ,
F_118 ( 0 , L_87 , & V_13 , L_87 ,
L_88 , V_246 ) ,
F_117 ( 'i' , L_89 , & V_52 ,
L_90 ) ,
F_119 ( 'p' , L_91 , & V_11 . V_136 , L_91 ,
L_92 ) ,
F_119 ( 't' , L_93 , & V_11 . V_202 , L_93 ,
L_94 ) ,
F_117 ( 'a' , L_95 , & V_11 . V_111 ,
L_96 ) ,
F_117 ( 'g' , L_97 , & V_137 ,
L_98 ) ,
F_117 ( 'c' , L_99 , & V_47 , L_100 ) ,
F_120 ( 'v' , L_101 , & V_104 ,
L_102 ) ,
F_121 ( 'r' , L_103 , & V_156 ,
L_104 ) ,
F_117 ( 'n' , L_105 , & V_203 ,
L_106 ) ,
F_120 ( 'd' , L_107 , & V_240 ,
L_108 ) ,
F_117 ( 'S' , L_109 , & V_151 ,
L_110 ) ,
F_122 ( 'B' , L_111 , NULL , NULL ,
L_112 ,
F_106 ) ,
F_119 ( 'C' , L_79 , & V_11 . V_12 , L_79 ,
L_113 ) ,
F_123 ( 'A' , L_114 , & V_93 ,
L_115 , V_96 ) ,
F_119 ( 'x' , L_116 , & V_118 , L_117 ,
L_118 ) ,
F_118 ( 'G' , L_119 , & V_13 , L_120 ,
L_121 , V_247 ) ,
F_119 ( 'o' , L_122 , & V_243 , L_123 , L_124 ) ,
F_117 ( 0 , L_125 , & V_241 , L_126 ) ,
F_121 ( 0 , L_127 , & V_242 ,
L_128 ) ,
F_119 ( 0 , L_129 , & V_150 , L_130 ,
L_131 ) ,
F_119 ( 0 , L_132 , & V_152 , L_130 ,
L_133 ) ,
F_124 ( 'I' , L_134 , & V_133 ,
L_135 ) ,
F_123 ( 0 , L_136 , & V_93 ,
L_137 , V_95 ) ,
F_123 ( 0 , L_138 , & V_93 ,
L_139 , V_94 ) ,
F_124 ( 'D' , L_140 , & V_54 ,
L_141 ) ,
F_125 ()
} ;
const char * const V_248 [] = {
L_142 ,
NULL
} ;
int V_131 = - V_139 , V_249 ;
const char * V_250 ;
setlocale ( V_251 , L_29 ) ;
V_13 = F_126 () ;
if ( V_13 == NULL )
return - V_20 ;
V_125 = F_127 ( V_125 , V_126 , V_244 , V_248 ,
V_252 ) ;
V_105 = V_238 ;
if ( V_243 && strcmp ( V_243 , L_143 ) )
V_105 = NULL ;
if ( V_243 && V_242 ) {
fprintf ( V_238 , L_144 ) ;
F_128 ( V_248 , V_244 , L_145 , 1 ) ;
F_128 ( NULL , V_244 , L_127 , 0 ) ;
goto V_253;
}
if ( V_242 < 0 ) {
fprintf ( V_238 , L_146 ) ;
F_128 ( V_248 , V_244 , L_127 , 0 ) ;
goto V_253;
}
if ( ! V_105 ) {
struct V_1 V_254 ;
V_250 = V_241 ? L_147 : L_148 ;
V_105 = fopen ( V_243 , V_250 ) ;
if ( ! V_105 ) {
perror ( L_149 ) ;
return - 1 ;
}
F_46 ( V_255 , & V_254 ) ;
fprintf ( V_105 , L_150 , ctime ( & V_254 . V_5 ) ) ;
} else if ( V_242 > 0 ) {
V_250 = V_241 ? L_147 : L_148 ;
V_105 = fdopen ( V_242 , V_250 ) ;
if ( ! V_105 ) {
perror ( L_151 ) ;
return - V_138 ;
}
}
if ( V_118 ) {
V_119 = true ;
if ( ! strcmp ( V_118 , L_152 ) )
V_118 = L_153 ;
} else
V_118 = V_256 ;
if ( V_119 ) {
if ( V_213 == 1 ) {
fprintf ( V_238 , L_154 ) ;
F_128 ( V_248 , V_244 , L_155 , 1 ) ;
F_128 ( NULL , V_244 , L_156 , 1 ) ;
goto V_253;
} else
V_179 = false ;
} else if ( V_213 == 0 )
V_179 = false ;
if ( ! V_125 && F_129 ( & V_11 ) )
F_130 ( V_248 , V_244 ) ;
if ( V_156 < 0 ) {
F_37 ( L_157 ) ;
F_128 ( V_248 , V_244 , L_158 , 1 ) ;
goto V_253;
} else if ( V_156 == 0 ) {
V_257 = true ;
V_156 = 1 ;
}
if ( ( V_93 != V_99 || V_258 ) &&
! F_20 ( & V_11 ) ) {
fprintf ( V_238 , L_159
L_160 ) ;
F_128 ( V_248 , V_244 , L_161 , 1 ) ;
F_128 ( NULL , V_244 , L_162 , 1 ) ;
F_128 ( NULL , V_244 , L_147 , 1 ) ;
goto V_253;
}
if ( F_112 () )
goto V_253;
F_131 ( & V_11 ) ;
if ( F_132 ( V_13 , & V_11 ) < 0 ) {
if ( F_22 ( & V_11 ) ) {
F_37 ( L_163 ) ;
F_128 ( V_248 , V_244 , L_164 , 1 ) ;
F_128 ( NULL , V_244 , L_165 , 1 ) ;
} else if ( F_20 ( & V_11 ) ) {
perror ( L_166 ) ;
F_128 ( V_248 , V_244 , L_167 , 1 ) ;
F_128 ( NULL , V_244 , L_147 , 1 ) ;
}
goto V_253;
}
if ( V_133 && V_133 < 100 ) {
F_37 ( L_168 ) ;
F_128 ( V_248 , V_244 , L_169 , 1 ) ;
goto V_253;
}
if ( F_15 ( V_13 , V_133 ) )
goto V_253;
if ( F_107 () )
goto V_253;
atexit ( F_101 ) ;
if ( ! V_257 )
signal ( V_259 , F_100 ) ;
signal ( V_207 , F_100 ) ;
signal ( V_260 , F_100 ) ;
signal ( V_261 , F_100 ) ;
V_131 = 0 ;
for ( V_249 = 0 ; V_257 || V_249 < V_156 ; V_249 ++ ) {
if ( V_156 != 1 && V_104 )
fprintf ( V_105 , L_170 ,
V_249 + 1 ) ;
V_131 = F_74 ( V_125 , V_126 ) ;
if ( V_257 && V_131 != - 1 ) {
F_99 ( V_125 , V_126 ) ;
F_17 ( V_13 ) ;
}
}
if ( ! V_257 && V_131 != - 1 && ! V_133 )
F_99 ( V_125 , V_126 ) ;
F_12 ( V_13 ) ;
V_253:
F_133 ( V_13 ) ;
return V_131 ;
}
