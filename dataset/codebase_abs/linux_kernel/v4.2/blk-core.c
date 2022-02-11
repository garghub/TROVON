static void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
F_3 ( V_2 -> V_4 -> V_5 , V_3 ) ;
#else
if ( V_2 == & V_2 -> V_6 -> V_7 )
F_3 ( V_2 -> V_6 -> V_8 . V_9 . V_10 , V_3 ) ;
#endif
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
F_5 ( V_2 -> V_4 -> V_5 , V_3 ) ;
#else
if ( V_2 == & V_2 -> V_6 -> V_7 )
F_5 ( V_2 -> V_6 -> V_8 . V_9 . V_10 , V_3 ) ;
#endif
}
void F_6 ( struct V_11 * V_6 )
{
int V_12 ;
V_12 = V_6 -> V_13 - ( V_6 -> V_13 / 8 ) + 1 ;
if ( V_12 > V_6 -> V_13 )
V_12 = V_6 -> V_13 ;
V_6 -> V_14 = V_12 ;
V_12 = V_6 -> V_13 - ( V_6 -> V_13 / 8 ) - ( V_6 -> V_13 / 16 ) - 1 ;
if ( V_12 < 1 )
V_12 = 1 ;
V_6 -> V_15 = V_12 ;
}
struct V_8 * F_7 ( struct V_16 * V_17 )
{
struct V_11 * V_6 = F_8 ( V_17 ) ;
return & V_6 -> V_8 ;
}
void F_9 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_10 ( & V_19 -> V_20 ) ;
F_10 ( & V_19 -> V_21 ) ;
V_19 -> V_22 = - 1 ;
V_19 -> V_6 = V_6 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
F_11 ( & V_19 -> V_25 ) ;
F_12 ( & V_19 -> V_26 ) ;
V_19 -> V_27 = V_19 -> V_28 ;
V_19 -> V_29 = V_30 ;
V_19 -> V_31 = - 1 ;
V_19 -> V_32 = V_33 ;
F_13 ( V_19 ) ;
V_19 -> V_34 = NULL ;
}
static void F_14 ( struct V_18 * V_19 , struct V_35 * V_35 ,
unsigned int V_36 , int error )
{
if ( error )
F_15 ( V_37 , & V_35 -> V_38 ) ;
else if ( ! F_16 ( V_37 , & V_35 -> V_38 ) )
error = - V_39 ;
if ( F_17 ( V_19 -> V_40 & V_41 ) )
F_18 ( V_42 , & V_35 -> V_38 ) ;
F_19 ( V_35 , V_36 ) ;
if ( V_35 -> V_43 . V_44 == 0 && ! ( V_19 -> V_40 & V_45 ) )
F_20 ( V_35 , error ) ;
}
void F_21 ( struct V_18 * V_19 , char * V_46 )
{
int V_47 ;
F_22 ( V_48 L_1 , V_46 ,
V_19 -> V_49 ? V_19 -> V_49 -> V_50 : L_2 , V_19 -> V_51 ,
( unsigned long long ) V_19 -> V_40 ) ;
F_22 ( V_48 L_3 ,
( unsigned long long ) F_23 ( V_19 ) ,
F_24 ( V_19 ) , F_25 ( V_19 ) ) ;
F_22 ( V_48 L_4 ,
V_19 -> V_35 , V_19 -> V_52 , F_26 ( V_19 ) ) ;
if ( V_19 -> V_51 == V_53 ) {
F_22 ( V_48 L_5 ) ;
for ( V_47 = 0 ; V_47 < V_30 ; V_47 ++ )
F_22 ( L_6 , V_19 -> V_27 [ V_47 ] ) ;
F_22 ( L_7 ) ;
}
}
static void F_27 ( struct V_54 * V_55 )
{
struct V_11 * V_6 ;
V_6 = F_28 ( V_55 , struct V_11 , V_56 . V_55 ) ;
F_29 ( V_6 -> V_57 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 -> V_57 ) ;
}
void F_32 ( struct V_11 * V_6 , unsigned long V_58 )
{
if ( F_33 ( ! F_34 ( V_6 ) ) )
F_35 ( V_59 , & V_6 -> V_56 ,
F_36 ( V_58 ) ) ;
}
void F_37 ( struct V_11 * V_6 )
{
F_38 ( ! F_39 () ) ;
F_40 ( V_60 , V_6 ) ;
F_30 ( V_6 ) ;
}
void F_41 ( struct V_11 * V_6 )
{
F_42 ( & V_6 -> V_56 ) ;
F_43 ( V_60 , V_6 ) ;
}
void F_44 ( struct V_11 * V_6 )
{
F_45 ( & V_6 -> V_61 ) ;
if ( V_6 -> V_62 ) {
struct V_63 * V_64 ;
int V_65 ;
F_46 (q, hctx, i) {
F_47 ( & V_64 -> V_66 ) ;
F_47 ( & V_64 -> V_56 ) ;
}
} else {
F_47 ( & V_6 -> V_56 ) ;
}
}
inline void F_48 ( struct V_11 * V_6 )
{
if ( F_17 ( F_34 ( V_6 ) ) )
return;
V_6 -> V_67 ++ ;
V_6 -> V_68 ( V_6 ) ;
V_6 -> V_67 -- ;
}
void F_30 ( struct V_11 * V_6 )
{
if ( F_17 ( F_49 ( V_6 ) ) )
return;
F_48 ( V_6 ) ;
}
void F_50 ( struct V_11 * V_6 )
{
if ( F_33 ( ! F_49 ( V_6 ) && ! F_34 ( V_6 ) ) )
F_51 ( V_59 , & V_6 -> V_56 , 0 ) ;
}
void F_52 ( struct V_11 * V_6 )
{
unsigned long V_69 ;
F_53 ( V_6 -> V_57 , V_69 ) ;
F_30 ( V_6 ) ;
F_54 ( V_6 -> V_57 , V_69 ) ;
}
void F_55 ( struct V_11 * V_6 )
{
F_56 ( & V_6 -> V_70 ) ;
}
static void F_57 ( struct V_11 * V_6 , bool V_71 )
__releases( V_6 -> V_57 )
__acquires( V_6 -> V_57 )
{
int V_65 ;
F_58 ( V_6 -> V_57 ) ;
while ( true ) {
bool V_72 = false ;
if ( V_6 -> V_73 )
F_59 ( V_6 ) ;
F_60 ( V_6 ) ;
if ( ! F_61 ( & V_6 -> V_74 ) && V_6 -> V_68 )
F_30 ( V_6 ) ;
V_72 |= V_6 -> V_75 ;
V_72 |= V_6 -> V_67 ;
if ( V_71 ) {
struct V_76 * V_77 = F_62 ( V_6 , NULL ) ;
V_72 |= ! F_61 ( & V_6 -> V_74 ) ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
V_72 |= V_6 -> V_78 [ V_65 ] ;
V_72 |= V_6 -> V_79 [ V_65 ] ;
if ( V_77 )
V_72 |= ! F_61 ( & V_77 -> V_80 [ V_65 ] ) ;
}
}
if ( ! V_72 )
break;
F_31 ( V_6 -> V_57 ) ;
F_63 ( 10 ) ;
F_29 ( V_6 -> V_57 ) ;
}
if ( V_6 -> V_68 ) {
struct V_1 * V_2 ;
F_64 (rl, q)
for ( V_65 = 0 ; V_65 < F_65 ( V_2 -> V_81 ) ; V_65 ++ )
F_66 ( & V_2 -> V_81 [ V_65 ] ) ;
}
}
void F_67 ( struct V_11 * V_6 )
{
F_29 ( V_6 -> V_57 ) ;
V_6 -> V_82 ++ ;
F_43 ( V_83 , V_6 ) ;
F_31 ( V_6 -> V_57 ) ;
if ( F_68 ( V_6 ) ) {
F_29 ( V_6 -> V_57 ) ;
F_57 ( V_6 , false ) ;
F_31 ( V_6 -> V_57 ) ;
F_69 () ;
}
}
void F_70 ( struct V_11 * V_6 )
{
F_29 ( V_6 -> V_57 ) ;
if ( ! -- V_6 -> V_82 )
F_40 ( V_83 , V_6 ) ;
F_71 ( V_6 -> V_82 < 0 ) ;
F_31 ( V_6 -> V_57 ) ;
}
void F_72 ( struct V_11 * V_6 )
{
F_73 ( V_84 , V_6 ) ;
if ( V_6 -> V_62 )
F_74 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_64 (rl, q) {
if ( V_2 -> V_85 ) {
F_75 ( & V_2 -> V_81 [ V_86 ] ) ;
F_75 ( & V_2 -> V_81 [ V_87 ] ) ;
}
}
}
}
void F_76 ( struct V_11 * V_6 )
{
T_1 * V_88 = V_6 -> V_57 ;
F_77 ( & V_6 -> V_89 ) ;
F_72 ( V_6 ) ;
F_29 ( V_88 ) ;
V_6 -> V_82 ++ ;
F_43 ( V_83 , V_6 ) ;
F_43 ( V_90 , V_6 ) ;
F_43 ( V_91 , V_6 ) ;
F_43 ( V_84 , V_6 ) ;
F_31 ( V_88 ) ;
F_78 ( & V_6 -> V_89 ) ;
if ( V_6 -> V_62 ) {
F_79 ( V_6 ) ;
F_29 ( V_88 ) ;
} else {
F_29 ( V_88 ) ;
F_57 ( V_6 , true ) ;
}
F_43 ( V_92 , V_6 ) ;
F_31 ( V_88 ) ;
F_45 ( & V_6 -> V_8 . V_93 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_62 )
F_80 ( V_6 ) ;
F_29 ( V_88 ) ;
if ( V_6 -> V_57 != & V_6 -> V_94 )
V_6 -> V_57 = & V_6 -> V_94 ;
F_31 ( V_88 ) ;
F_81 ( & V_6 -> V_8 ) ;
F_55 ( V_6 ) ;
}
static void * F_82 ( T_2 V_95 , void * V_96 )
{
int V_97 = ( int ) ( long ) V_96 ;
return F_83 ( V_98 , V_95 , V_97 ) ;
}
static void F_84 ( void * V_99 , void * V_100 )
{
F_85 ( V_98 , V_99 ) ;
}
int F_86 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_95 )
{
if ( F_17 ( V_2 -> V_85 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_101 [ V_86 ] = V_2 -> V_101 [ V_87 ] = 0 ;
V_2 -> V_102 [ V_86 ] = V_2 -> V_102 [ V_87 ] = 0 ;
F_87 ( & V_2 -> V_81 [ V_86 ] ) ;
F_87 ( & V_2 -> V_81 [ V_87 ] ) ;
V_2 -> V_85 = F_88 ( V_103 , F_82 ,
F_84 ,
( void * ) ( long ) V_6 -> V_104 , V_95 ,
V_6 -> V_104 ) ;
if ( ! V_2 -> V_85 )
return - V_105 ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 )
F_90 ( V_2 -> V_85 ) ;
}
struct V_11 * F_91 ( T_2 V_95 )
{
return F_92 ( V_95 , V_106 ) ;
}
struct V_11 * F_92 ( T_2 V_95 , int V_107 )
{
struct V_11 * V_6 ;
int V_108 ;
V_6 = F_83 ( V_109 ,
V_95 | V_110 , V_107 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_111 = F_93 ( & V_112 , 0 , 0 , V_95 ) ;
if ( V_6 -> V_111 < 0 )
goto V_113;
V_6 -> V_8 . V_114 =
( V_115 * 1024 ) / V_116 ;
V_6 -> V_8 . V_117 = V_118 ;
V_6 -> V_8 . V_119 = L_8 ;
V_6 -> V_104 = V_107 ;
V_108 = F_94 ( & V_6 -> V_8 ) ;
if ( V_108 )
goto V_120;
F_95 ( & V_6 -> V_8 . V_93 ,
V_121 , ( unsigned long ) V_6 ) ;
F_95 ( & V_6 -> V_61 , V_122 , ( unsigned long ) V_6 ) ;
F_10 ( & V_6 -> V_74 ) ;
F_10 ( & V_6 -> V_21 ) ;
F_10 ( & V_6 -> V_123 ) ;
#ifdef F_96
F_10 ( & V_6 -> V_124 ) ;
#endif
F_97 ( & V_6 -> V_56 , F_27 ) ;
F_98 ( & V_6 -> V_70 , & V_125 ) ;
F_99 ( & V_6 -> V_89 ) ;
F_100 ( & V_6 -> V_94 ) ;
V_6 -> V_57 = & V_6 -> V_94 ;
V_6 -> V_82 = 1 ;
F_101 ( V_83 , & V_6 -> V_126 ) ;
F_87 ( & V_6 -> V_127 ) ;
if ( F_102 ( V_6 ) )
goto V_128;
return V_6 ;
V_128:
F_81 ( & V_6 -> V_8 ) ;
V_120:
F_103 ( & V_112 , V_6 -> V_111 ) ;
V_113:
F_85 ( V_109 , V_6 ) ;
return NULL ;
}
struct V_11 * F_104 ( T_3 * V_129 , T_1 * V_88 )
{
return F_105 ( V_129 , V_88 , V_106 ) ;
}
struct V_11 *
F_105 ( T_3 * V_129 , T_1 * V_88 , int V_107 )
{
struct V_11 * V_130 , * V_6 ;
V_130 = F_92 ( V_131 , V_107 ) ;
if ( ! V_130 )
return NULL ;
V_6 = F_106 ( V_130 , V_129 , V_88 ) ;
if ( ! V_6 )
F_76 ( V_130 ) ;
return V_6 ;
}
struct V_11 *
F_106 ( struct V_11 * V_6 , T_3 * V_129 ,
T_1 * V_88 )
{
if ( ! V_6 )
return NULL ;
V_6 -> V_77 = F_107 ( V_6 , V_106 , 0 ) ;
if ( ! V_6 -> V_77 )
return NULL ;
if ( F_86 ( & V_6 -> V_7 , V_6 , V_131 ) )
goto V_132;
V_6 -> V_68 = V_129 ;
V_6 -> V_133 = NULL ;
V_6 -> V_134 = NULL ;
V_6 -> V_126 |= V_135 ;
if ( V_88 )
V_6 -> V_57 = V_88 ;
F_108 ( V_6 , V_136 ) ;
V_6 -> V_137 = V_138 ;
F_77 ( & V_6 -> V_89 ) ;
if ( F_109 ( V_6 , NULL ) ) {
F_78 ( & V_6 -> V_89 ) ;
goto V_132;
}
F_78 ( & V_6 -> V_89 ) ;
return V_6 ;
V_132:
F_110 ( V_6 -> V_77 ) ;
return NULL ;
}
bool F_111 ( struct V_11 * V_6 )
{
if ( F_33 ( ! F_112 ( V_6 ) ) ) {
F_113 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_114 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_40 & V_139 ) {
F_115 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_140 . V_141 )
F_116 ( V_19 -> V_140 . V_141 -> V_142 ) ;
}
F_117 ( V_19 , V_2 -> V_85 ) ;
}
static inline int F_118 ( struct V_11 * V_6 , struct V_143 * V_142 )
{
if ( ! V_142 )
return 0 ;
return V_142 -> V_144 == V_6 -> V_145 ||
( V_142 -> V_144 > 0
&& F_119 ( V_33 , V_142 -> V_146 + V_147 ) ) ;
}
static void F_120 ( struct V_11 * V_6 , struct V_143 * V_142 )
{
if ( ! V_142 || F_118 ( V_6 , V_142 ) )
return;
V_142 -> V_144 = V_6 -> V_145 ;
V_142 -> V_146 = V_33 ;
}
static void F_121 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_101 [ V_3 ] < F_122 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_101 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_123 ( & V_2 -> V_81 [ V_3 ] ) )
F_75 ( & V_2 -> V_81 [ V_3 ] ) ;
F_124 ( V_2 , V_3 ) ;
}
}
static void F_125 ( struct V_1 * V_2 , unsigned int V_69 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_3 = F_126 ( V_69 ) ;
V_6 -> V_78 [ V_3 ] -- ;
V_2 -> V_101 [ V_3 ] -- ;
if ( V_69 & V_139 )
V_6 -> V_75 -- ;
F_121 ( V_2 , V_3 ) ;
if ( F_17 ( V_2 -> V_102 [ V_3 ^ 1 ] ) )
F_121 ( V_2 , V_3 ^ 1 ) ;
}
int F_127 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_148 , V_149 ;
F_29 ( V_6 -> V_57 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_148 = F_128 ( V_6 ) ;
V_149 = F_122 ( V_6 ) ;
F_64 (rl, q) {
if ( V_2 -> V_101 [ V_86 ] >= V_148 )
F_4 ( V_2 , V_86 ) ;
else if ( V_2 -> V_101 [ V_86 ] < V_149 )
F_1 ( V_2 , V_86 ) ;
if ( V_2 -> V_101 [ V_87 ] >= V_148 )
F_4 ( V_2 , V_87 ) ;
else if ( V_2 -> V_101 [ V_87 ] < V_149 )
F_1 ( V_2 , V_87 ) ;
if ( V_2 -> V_101 [ V_86 ] >= V_6 -> V_13 ) {
F_129 ( V_2 , V_86 ) ;
} else {
F_124 ( V_2 , V_86 ) ;
F_75 ( & V_2 -> V_81 [ V_86 ] ) ;
}
if ( V_2 -> V_101 [ V_87 ] >= V_6 -> V_13 ) {
F_129 ( V_2 , V_87 ) ;
} else {
F_124 ( V_2 , V_87 ) ;
F_75 ( & V_2 -> V_81 [ V_87 ] ) ;
}
}
F_31 ( V_6 -> V_57 ) ;
return 0 ;
}
static bool F_130 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_150 & ( V_151 | V_152 ) )
return false ;
return true ;
}
static struct V_143 * F_131 ( struct V_35 * V_35 )
{
#ifdef F_96
if ( V_35 && V_35 -> V_153 )
return V_35 -> V_153 ;
#endif
return V_154 -> V_143 ;
}
static struct V_18 * F_132 ( struct V_1 * V_2 , int V_155 ,
struct V_35 * V_35 , T_2 V_95 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_156 * V_157 = V_6 -> V_73 -> type ;
struct V_143 * V_142 = F_131 ( V_35 ) ;
struct V_158 * V_141 = NULL ;
const bool V_159 = F_126 ( V_155 ) != 0 ;
int V_160 ;
if ( F_17 ( F_112 ( V_6 ) ) )
return F_133 ( - V_161 ) ;
V_160 = F_134 ( V_6 , V_155 ) ;
if ( V_160 == V_162 )
goto V_163;
if ( V_2 -> V_101 [ V_159 ] + 1 >= F_128 ( V_6 ) ) {
if ( V_2 -> V_101 [ V_159 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_135 ( V_2 , V_159 ) ) {
F_120 ( V_6 , V_142 ) ;
F_129 ( V_2 , V_159 ) ;
} else {
if ( V_160 != V_164
&& ! F_118 ( V_6 , V_142 ) ) {
return F_133 ( - V_105 ) ;
}
}
}
F_4 ( V_2 , V_159 ) ;
}
if ( V_2 -> V_101 [ V_159 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_133 ( - V_105 ) ;
V_6 -> V_78 [ V_159 ] ++ ;
V_2 -> V_101 [ V_159 ] ++ ;
V_2 -> V_102 [ V_159 ] = 0 ;
if ( F_130 ( V_35 ) && ! F_136 ( V_6 ) ) {
V_155 |= V_139 ;
V_6 -> V_75 ++ ;
if ( V_157 -> V_165 && V_142 )
V_141 = F_137 ( V_142 , V_6 ) ;
}
if ( F_138 ( V_6 ) )
V_155 |= V_166 ;
F_31 ( V_6 -> V_57 ) ;
V_19 = F_139 ( V_2 -> V_85 , V_95 ) ;
if ( ! V_19 )
goto V_167;
F_9 ( V_6 , V_19 ) ;
F_140 ( V_19 , V_2 ) ;
V_19 -> V_40 = V_155 | V_168 ;
if ( V_155 & V_139 ) {
if ( F_17 ( V_157 -> V_165 && ! V_141 ) ) {
if ( V_142 )
V_141 = F_141 ( V_142 , V_6 , V_95 ) ;
if ( ! V_141 )
goto V_169;
}
V_19 -> V_140 . V_141 = V_141 ;
if ( F_17 ( F_142 ( V_6 , V_19 , V_35 , V_95 ) ) )
goto V_169;
if ( V_141 )
F_143 ( V_141 -> V_142 ) ;
}
V_170:
if ( F_118 ( V_6 , V_142 ) )
V_142 -> V_144 -- ;
F_144 ( V_6 , V_35 , V_155 & 1 ) ;
return V_19 ;
V_169:
F_145 ( V_171 L_9 ,
V_172 , F_146 ( V_6 -> V_8 . V_173 ) ) ;
V_19 -> V_40 &= ~ V_139 ;
V_19 -> V_140 . V_141 = NULL ;
F_29 ( V_6 -> V_57 ) ;
V_6 -> V_75 -- ;
F_31 ( V_6 -> V_57 ) ;
goto V_170;
V_167:
F_29 ( V_6 -> V_57 ) ;
F_125 ( V_2 , V_155 ) ;
V_163:
if ( F_17 ( V_2 -> V_101 [ V_159 ] == 0 ) )
V_2 -> V_102 [ V_159 ] = 1 ;
return F_133 ( - V_105 ) ;
}
static struct V_18 * F_147 ( struct V_11 * V_6 , int V_155 ,
struct V_35 * V_35 , T_2 V_95 )
{
const bool V_159 = F_126 ( V_155 ) != 0 ;
F_148 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_149 ( V_6 , V_35 ) ;
V_174:
V_19 = F_132 ( V_2 , V_155 , V_35 , V_95 ) ;
if ( ! F_150 ( V_19 ) )
return V_19 ;
if ( ! ( V_95 & V_175 ) || F_17 ( F_112 ( V_6 ) ) ) {
F_151 ( V_2 ) ;
return V_19 ;
}
F_152 ( & V_2 -> V_81 [ V_159 ] , & V_81 ,
V_176 ) ;
F_153 ( V_6 , V_35 , V_155 & 1 ) ;
F_31 ( V_6 -> V_57 ) ;
F_154 () ;
F_120 ( V_6 , V_154 -> V_143 ) ;
F_29 ( V_6 -> V_57 ) ;
F_155 ( & V_2 -> V_81 [ V_159 ] , & V_81 ) ;
goto V_174;
}
static struct V_18 * F_156 ( struct V_11 * V_6 , int V_177 ,
T_2 V_95 )
{
struct V_18 * V_19 ;
F_157 ( V_177 != V_178 && V_177 != V_179 ) ;
F_158 ( V_95 , V_6 -> V_104 ) ;
F_29 ( V_6 -> V_57 ) ;
V_19 = F_147 ( V_6 , V_177 , NULL , V_95 ) ;
if ( F_150 ( V_19 ) )
F_31 ( V_6 -> V_57 ) ;
return V_19 ;
}
struct V_18 * F_159 ( struct V_11 * V_6 , int V_177 , T_2 V_95 )
{
if ( V_6 -> V_62 )
return F_160 ( V_6 , V_177 , V_95 , false ) ;
else
return F_156 ( V_6 , V_177 , V_95 ) ;
}
struct V_18 * F_161 ( struct V_11 * V_6 , struct V_35 * V_35 ,
T_2 V_95 )
{
struct V_18 * V_19 = F_159 ( V_6 , F_162 ( V_35 ) , V_95 ) ;
if ( F_150 ( V_19 ) )
return V_19 ;
F_163 ( V_19 ) ;
F_164 (bio) {
struct V_35 * V_180 = V_35 ;
int V_181 ;
F_165 ( V_6 , & V_180 ) ;
V_181 = F_166 ( V_6 , V_19 , V_180 ) ;
if ( F_17 ( V_181 ) ) {
F_167 ( V_19 ) ;
return F_133 ( V_181 ) ;
}
}
return V_19 ;
}
void F_163 ( struct V_18 * V_19 )
{
V_19 -> V_51 = V_53 ;
V_19 -> V_182 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_52 = NULL ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_168 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_169 ( V_19 ) ;
F_170 ( V_19 ) ;
F_171 ( V_6 , V_19 ) ;
if ( V_19 -> V_40 & V_183 )
F_172 ( V_6 , V_19 ) ;
F_157 ( F_173 ( V_19 ) ) ;
F_174 ( V_6 , V_19 ) ;
}
static void F_175 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_184 )
{
F_176 ( V_19 , true ) ;
F_177 ( V_6 , V_19 , V_184 ) ;
}
static void F_178 ( int V_22 , struct V_185 * V_34 ,
unsigned long V_186 )
{
int V_187 ;
if ( V_186 == V_34 -> V_188 )
return;
V_187 = F_179 ( V_34 ) ;
if ( V_187 ) {
F_180 ( V_22 , V_34 , V_189 ,
V_187 * ( V_186 - V_34 -> V_188 ) ) ;
F_180 ( V_22 , V_34 , V_190 , ( V_186 - V_34 -> V_188 ) ) ;
}
V_34 -> V_188 = V_186 ;
}
void F_181 ( int V_22 , struct V_185 * V_34 )
{
unsigned long V_186 = V_33 ;
if ( V_34 -> V_191 )
F_178 ( V_22 , & F_182 ( V_34 ) -> V_192 , V_186 ) ;
F_178 ( V_22 , V_34 , V_186 ) ;
}
static void F_183 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_173 && ! ( V_19 -> V_40 & V_193 ) && ! -- V_19 -> V_6 -> V_194 )
F_184 ( V_19 -> V_6 -> V_173 ) ;
}
static inline void F_183 ( struct V_18 * V_19 ) {}
void F_185 ( struct V_11 * V_6 , struct V_18 * V_195 )
{
if ( F_17 ( ! V_6 ) )
return;
if ( V_6 -> V_62 ) {
F_186 ( V_195 ) ;
return;
}
F_183 ( V_195 ) ;
F_187 ( V_6 , V_195 ) ;
F_38 ( V_195 -> V_35 != NULL ) ;
if ( V_195 -> V_40 & V_168 ) {
unsigned int V_69 = V_195 -> V_40 ;
struct V_1 * V_2 = F_188 ( V_195 ) ;
F_157 ( ! F_61 ( & V_195 -> V_20 ) ) ;
F_157 ( F_189 ( V_195 ) ) ;
F_114 ( V_2 , V_195 ) ;
F_125 ( V_2 , V_69 ) ;
F_151 ( V_2 ) ;
}
}
void F_167 ( struct V_18 * V_195 )
{
struct V_11 * V_6 = V_195 -> V_6 ;
if ( V_6 -> V_62 )
F_186 ( V_195 ) ;
else {
unsigned long V_69 ;
F_53 ( V_6 -> V_57 , V_69 ) ;
F_185 ( V_6 , V_195 ) ;
F_54 ( V_6 -> V_57 , V_69 ) ;
}
}
void F_190 ( struct V_18 * V_19 , struct V_196 * V_196 ,
unsigned int V_197 )
{
struct V_35 * V_35 = V_19 -> V_35 ;
V_35 -> V_198 -> V_199 = V_196 ;
V_35 -> V_198 -> V_200 = 0 ;
V_35 -> V_198 -> V_201 = V_197 ;
V_35 -> V_43 . V_44 = V_197 ;
V_35 -> V_202 = 1 ;
V_35 -> V_203 = 1 ;
V_19 -> V_182 = V_19 -> V_204 = V_197 ;
V_19 -> V_205 = 1 ;
}
bool F_191 ( struct V_11 * V_6 , struct V_18 * V_195 ,
struct V_35 * V_35 )
{
const int V_206 = V_35 -> V_150 & V_207 ;
if ( ! F_192 ( V_6 , V_195 , V_35 ) )
return false ;
F_193 ( V_6 , V_195 , V_35 ) ;
if ( ( V_195 -> V_40 & V_207 ) != V_206 )
F_194 ( V_195 ) ;
V_195 -> V_52 -> V_208 = V_35 ;
V_195 -> V_52 = V_35 ;
V_195 -> V_182 += V_35 -> V_43 . V_44 ;
V_195 -> V_209 = F_195 ( V_195 -> V_209 , F_196 ( V_35 ) ) ;
F_176 ( V_195 , false ) ;
return true ;
}
bool F_197 ( struct V_11 * V_6 , struct V_18 * V_195 ,
struct V_35 * V_35 )
{
const int V_206 = V_35 -> V_150 & V_207 ;
if ( ! F_198 ( V_6 , V_195 , V_35 ) )
return false ;
F_199 ( V_6 , V_195 , V_35 ) ;
if ( ( V_195 -> V_40 & V_207 ) != V_206 )
F_194 ( V_195 ) ;
V_35 -> V_208 = V_195 -> V_35 ;
V_195 -> V_35 = V_35 ;
V_195 -> V_23 = V_35 -> V_43 . V_210 ;
V_195 -> V_182 += V_35 -> V_43 . V_44 ;
V_195 -> V_209 = F_195 ( V_195 -> V_209 , F_196 ( V_35 ) ) ;
F_176 ( V_195 , false ) ;
return true ;
}
bool F_200 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_211 ,
struct V_18 * * V_212 )
{
struct V_213 * V_214 ;
struct V_18 * V_19 ;
bool V_181 = false ;
struct V_215 * V_216 ;
V_214 = V_154 -> V_214 ;
if ( ! V_214 )
goto V_170;
* V_211 = 0 ;
if ( V_6 -> V_62 )
V_216 = & V_214 -> V_217 ;
else
V_216 = & V_214 -> V_218 ;
F_201 (rq, plug_list, queuelist) {
int V_219 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_211 ) ++ ;
if ( V_212 )
* V_212 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_202 ( V_19 , V_35 ) )
continue;
V_219 = F_203 ( V_19 , V_35 ) ;
if ( V_219 == V_220 ) {
V_181 = F_191 ( V_6 , V_19 , V_35 ) ;
if ( V_181 )
break;
} else if ( V_219 == V_221 ) {
V_181 = F_197 ( V_6 , V_19 , V_35 ) ;
if ( V_181 )
break;
}
}
V_170:
return V_181 ;
}
void F_204 ( struct V_18 * V_195 , struct V_35 * V_35 )
{
V_195 -> V_51 = V_222 ;
V_195 -> V_40 |= V_35 -> V_150 & V_223 ;
if ( V_35 -> V_150 & V_224 )
V_195 -> V_40 |= V_207 ;
V_195 -> V_225 = 0 ;
V_195 -> V_23 = V_35 -> V_43 . V_210 ;
V_195 -> V_209 = F_196 ( V_35 ) ;
F_205 ( V_195 -> V_6 , V_195 , V_35 ) ;
}
static void V_136 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
const bool V_3 = ! ! ( V_35 -> V_150 & V_226 ) ;
struct V_213 * V_214 ;
int V_219 , V_155 , V_184 = V_227 ;
struct V_18 * V_195 ;
unsigned int V_211 = 0 ;
F_165 ( V_6 , & V_35 ) ;
if ( F_206 ( V_35 ) && F_207 ( V_35 ) ) {
F_20 ( V_35 , - V_39 ) ;
return;
}
if ( V_35 -> V_150 & ( V_151 | V_152 ) ) {
F_29 ( V_6 -> V_57 ) ;
V_184 = V_228 ;
goto V_229;
}
if ( ! F_208 ( V_6 ) &&
F_200 ( V_6 , V_35 , & V_211 , NULL ) )
return;
F_29 ( V_6 -> V_57 ) ;
V_219 = F_209 ( V_6 , & V_195 , V_35 ) ;
if ( V_219 == V_220 ) {
if ( F_191 ( V_6 , V_195 , V_35 ) ) {
F_210 ( V_6 , V_195 , V_35 ) ;
if ( ! F_211 ( V_6 , V_195 ) )
F_212 ( V_6 , V_195 , V_219 ) ;
goto V_230;
}
} else if ( V_219 == V_221 ) {
if ( F_197 ( V_6 , V_195 , V_35 ) ) {
F_210 ( V_6 , V_195 , V_35 ) ;
if ( ! F_213 ( V_6 , V_195 ) )
F_212 ( V_6 , V_195 , V_219 ) ;
goto V_230;
}
}
V_229:
V_155 = F_162 ( V_35 ) ;
if ( V_3 )
V_155 |= V_226 ;
V_195 = F_147 ( V_6 , V_155 , V_35 , V_231 ) ;
if ( F_150 ( V_195 ) ) {
F_20 ( V_35 , F_214 ( V_195 ) ) ;
goto V_230;
}
F_204 ( V_195 , V_35 ) ;
if ( F_16 ( V_232 , & V_6 -> V_126 ) )
V_195 -> V_22 = F_215 () ;
V_214 = V_154 -> V_214 ;
if ( V_214 ) {
if ( ! V_211 )
F_216 ( V_6 ) ;
else {
if ( V_211 >= V_233 ) {
F_217 ( V_214 , false ) ;
F_216 ( V_6 ) ;
}
}
F_218 ( & V_195 -> V_20 , & V_214 -> V_218 ) ;
F_176 ( V_195 , true ) ;
} else {
F_29 ( V_6 -> V_57 ) ;
F_175 ( V_6 , V_195 , V_184 ) ;
F_30 ( V_6 ) ;
V_230:
F_31 ( V_6 -> V_57 ) ;
}
}
static inline void F_219 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_234 ;
if ( F_220 ( V_35 ) && V_17 != V_17 -> V_235 ) {
struct V_185 * V_236 = V_17 -> V_237 ;
V_35 -> V_43 . V_210 += V_236 -> V_238 ;
V_35 -> V_234 = V_17 -> V_235 ;
F_221 ( F_8 ( V_35 -> V_234 ) , V_35 ,
V_17 -> V_239 ,
V_35 -> V_43 . V_210 - V_236 -> V_238 ) ;
}
}
static void F_222 ( struct V_35 * V_35 )
{
char V_240 [ V_241 ] ;
F_22 ( V_48 L_10 ) ;
F_22 ( V_48 L_11 ,
F_223 ( V_35 -> V_234 , V_240 ) ,
V_35 -> V_150 ,
( unsigned long long ) F_224 ( V_35 ) ,
( long long ) ( F_225 ( V_35 -> V_234 -> V_242 ) >> 9 ) ) ;
}
static int T_4 F_226 ( char * V_243 )
{
return F_227 ( & V_244 , V_243 ) ;
}
static bool F_228 ( struct V_185 * V_34 , unsigned int V_245 )
{
return V_34 -> V_246 && F_229 ( & V_244 , V_245 ) ;
}
static int T_4 F_230 ( void )
{
struct V_247 * V_248 = F_231 ( L_12 ,
NULL , & V_244 ) ;
return F_232 ( V_248 ) ;
}
static inline bool F_228 ( struct V_185 * V_34 ,
unsigned int V_245 )
{
return false ;
}
static inline int F_233 ( struct V_35 * V_35 , unsigned int V_249 )
{
V_24 V_250 ;
if ( ! V_249 )
return 0 ;
V_250 = F_225 ( V_35 -> V_234 -> V_242 ) >> 9 ;
if ( V_250 ) {
V_24 V_251 = V_35 -> V_43 . V_210 ;
if ( V_250 < V_249 || V_250 - V_249 < V_251 ) {
F_222 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_234 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_249 = F_220 ( V_35 ) ;
int V_108 = - V_39 ;
char V_240 [ V_241 ] ;
struct V_185 * V_34 ;
F_235 () ;
if ( F_233 ( V_35 , V_249 ) )
goto V_252;
V_6 = F_8 ( V_35 -> V_234 ) ;
if ( F_17 ( ! V_6 ) ) {
F_22 ( V_253
L_13
L_14 ,
F_223 ( V_35 -> V_234 , V_240 ) ,
( long long ) V_35 -> V_43 . V_210 ) ;
goto V_252;
}
if ( F_33 ( F_236 ( V_35 ) &&
V_249 > F_237 ( V_6 ) ) ) {
F_22 ( V_253 L_15 ,
F_223 ( V_35 -> V_234 , V_240 ) ,
F_220 ( V_35 ) ,
F_237 ( V_6 ) ) ;
goto V_252;
}
V_34 = V_35 -> V_234 -> V_237 ;
if ( F_228 ( V_34 , V_35 -> V_43 . V_44 ) ||
F_228 ( & F_182 ( V_34 ) -> V_192 ,
V_35 -> V_43 . V_44 ) )
goto V_252;
F_219 ( V_35 ) ;
if ( F_233 ( V_35 , V_249 ) )
goto V_252;
if ( ( V_35 -> V_150 & ( V_151 | V_152 ) ) && ! V_6 -> V_254 ) {
V_35 -> V_150 &= ~ ( V_151 | V_152 ) ;
if ( ! V_249 ) {
V_108 = 0 ;
goto V_252;
}
}
if ( ( V_35 -> V_150 & V_255 ) &&
( ! F_238 ( V_6 ) ||
( ( V_35 -> V_150 & V_256 ) && ! F_239 ( V_6 ) ) ) ) {
V_108 = - V_257 ;
goto V_252;
}
if ( V_35 -> V_150 & V_258 && ! F_240 ( V_35 -> V_234 ) ) {
V_108 = - V_257 ;
goto V_252;
}
F_158 ( V_259 , V_6 -> V_104 ) ;
if ( F_241 ( V_6 , V_35 ) )
return false ;
F_242 ( V_6 , V_35 ) ;
return true ;
V_252:
F_20 ( V_35 , V_108 ) ;
return false ;
}
void F_243 ( struct V_35 * V_35 )
{
struct V_260 V_261 ;
if ( ! F_234 ( V_35 ) )
return;
if ( V_154 -> V_260 ) {
F_244 ( V_154 -> V_260 , V_35 ) ;
return;
}
F_157 ( V_35 -> V_208 ) ;
F_245 ( & V_261 ) ;
V_154 -> V_260 = & V_261 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_234 ) ;
V_6 -> V_262 ( V_6 , V_35 ) ;
V_35 = F_246 ( V_154 -> V_260 ) ;
} while ( V_35 );
V_154 -> V_260 = NULL ;
}
void F_247 ( int V_177 , struct V_35 * V_35 )
{
V_35 -> V_150 |= V_177 ;
if ( F_248 ( V_35 ) ) {
unsigned int V_101 ;
if ( F_17 ( V_177 & V_258 ) )
V_101 = F_249 ( V_35 -> V_234 ) >> 9 ;
else
V_101 = F_220 ( V_35 ) ;
if ( V_177 & V_179 ) {
F_250 ( V_263 , V_101 ) ;
} else {
F_251 ( V_35 -> V_43 . V_44 ) ;
F_250 ( V_264 , V_101 ) ;
}
if ( F_17 ( V_265 ) ) {
char V_240 [ V_241 ] ;
F_22 ( V_266 L_16 ,
V_154 -> V_267 , F_252 ( V_154 ) ,
( V_177 & V_179 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_43 . V_210 ,
F_223 ( V_35 -> V_234 , V_240 ) ,
V_101 ) ;
}
}
F_243 ( V_35 ) ;
}
int F_253 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
if ( ! F_254 ( V_19 ) )
return 0 ;
if ( F_24 ( V_19 ) > F_255 ( V_6 , V_19 -> V_40 ) ) {
F_22 ( V_253 L_19 , V_172 ) ;
return - V_39 ;
}
F_256 ( V_19 ) ;
if ( V_19 -> V_205 > F_257 ( V_6 ) ) {
F_22 ( V_253 L_20 , V_172 ) ;
return - V_39 ;
}
return 0 ;
}
int F_258 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_69 ;
int V_184 = V_268 ;
if ( F_253 ( V_6 , V_19 ) )
return - V_39 ;
if ( V_19 -> V_49 &&
F_228 ( & V_19 -> V_49 -> V_192 , F_26 ( V_19 ) ) )
return - V_39 ;
if ( V_6 -> V_62 ) {
if ( F_138 ( V_6 ) )
F_176 ( V_19 , true ) ;
F_259 ( V_19 , false , true , true ) ;
return 0 ;
}
F_53 ( V_6 -> V_57 , V_69 ) ;
if ( F_17 ( F_112 ( V_6 ) ) ) {
F_54 ( V_6 -> V_57 , V_69 ) ;
return - V_161 ;
}
F_157 ( F_173 ( V_19 ) ) ;
if ( V_19 -> V_40 & ( V_151 | V_152 ) )
V_184 = V_228 ;
F_175 ( V_6 , V_19 , V_184 ) ;
if ( V_184 == V_228 )
F_30 ( V_6 ) ;
F_54 ( V_6 -> V_57 , V_69 ) ;
return 0 ;
}
unsigned int F_260 ( const struct V_18 * V_19 )
{
unsigned int V_206 = V_19 -> V_40 & V_207 ;
unsigned int V_245 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_40 & V_269 ) )
return F_26 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_208 ) {
if ( ( V_35 -> V_150 & V_206 ) != V_206 )
break;
V_245 += V_35 -> V_43 . V_44 ;
}
F_157 ( F_26 ( V_19 ) && ! V_245 ) ;
return V_245 ;
}
void F_261 ( struct V_18 * V_195 , unsigned int V_245 )
{
if ( F_262 ( V_195 ) ) {
const int V_177 = F_263 ( V_195 ) ;
struct V_185 * V_34 ;
int V_22 ;
V_22 = F_264 () ;
V_34 = V_195 -> V_34 ;
F_265 ( V_22 , V_34 , V_270 [ V_177 ] , V_245 >> 9 ) ;
F_266 () ;
}
}
void F_267 ( struct V_18 * V_195 )
{
if ( F_262 ( V_195 ) && ! ( V_195 -> V_40 & V_45 ) ) {
unsigned long V_271 = V_33 - V_195 -> V_32 ;
const int V_177 = F_263 ( V_195 ) ;
struct V_185 * V_34 ;
int V_22 ;
V_22 = F_264 () ;
V_34 = V_195 -> V_34 ;
F_268 ( V_22 , V_34 , V_272 [ V_177 ] ) ;
F_265 ( V_22 , V_34 , V_273 [ V_177 ] , V_271 ) ;
F_181 ( V_22 , V_34 ) ;
F_269 ( V_34 , V_177 ) ;
F_270 ( V_34 ) ;
F_266 () ;
}
}
static struct V_18 * F_271 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_173 && ( V_6 -> V_274 == V_275 ||
( V_6 -> V_274 != V_276 && ! ( V_19 -> V_40 & V_193 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_271 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_176 ( struct V_18 * V_19 , bool V_277 )
{
struct V_185 * V_34 ;
int V_177 = F_263 ( V_19 ) ;
int V_22 ;
if ( ! F_262 ( V_19 ) )
return;
V_22 = F_264 () ;
if ( ! V_277 ) {
V_34 = V_19 -> V_34 ;
F_268 ( V_22 , V_34 , V_278 [ V_177 ] ) ;
} else {
V_34 = F_272 ( V_19 -> V_49 , F_23 ( V_19 ) ) ;
if ( ! F_273 ( V_34 ) ) {
V_34 = & V_19 -> V_49 -> V_192 ;
F_274 ( V_34 ) ;
}
F_181 ( V_22 , V_34 ) ;
F_275 ( V_34 , V_177 ) ;
V_19 -> V_34 = V_34 ;
}
F_266 () ;
}
struct V_18 * F_276 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
int V_181 ;
while ( ( V_19 = F_277 ( V_6 ) ) != NULL ) {
V_19 = F_271 ( V_6 , V_19 ) ;
if ( ! V_19 )
break;
if ( ! ( V_19 -> V_40 & V_279 ) ) {
if ( V_19 -> V_40 & V_280 )
F_278 ( V_6 , V_19 ) ;
V_19 -> V_40 |= V_279 ;
F_279 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_281 || V_6 -> V_281 == V_19 ) {
V_6 -> V_282 = F_280 ( V_19 ) ;
V_6 -> V_281 = NULL ;
}
if ( V_19 -> V_40 & V_283 )
break;
if ( V_6 -> V_284 && F_26 ( V_19 ) ) {
V_19 -> V_205 ++ ;
}
if ( ! V_6 -> V_133 )
break;
V_181 = V_6 -> V_133 ( V_6 , V_19 ) ;
if ( V_181 == V_285 ) {
break;
} else if ( V_181 == V_286 ) {
if ( V_6 -> V_284 && F_26 ( V_19 ) &&
! ( V_19 -> V_40 & V_283 ) ) {
-- V_19 -> V_205 ;
}
V_19 = NULL ;
break;
} else if ( V_181 == V_287 ) {
V_19 -> V_40 |= V_41 ;
F_281 ( V_19 ) ;
F_282 ( V_19 , - V_39 ) ;
} else {
F_22 ( V_253 L_21 , V_172 , V_181 ) ;
break;
}
}
return V_19 ;
}
void F_283 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_157 ( F_61 ( & V_19 -> V_20 ) ) ;
F_157 ( F_189 ( V_19 ) ) ;
F_284 ( & V_19 -> V_20 ) ;
if ( F_285 ( V_19 ) ) {
V_6 -> V_79 [ F_286 ( V_19 ) ] ++ ;
F_287 ( V_19 ) ;
}
}
void F_281 ( struct V_18 * V_195 )
{
F_283 ( V_195 ) ;
V_195 -> V_204 = F_26 ( V_195 ) ;
if ( F_17 ( F_288 ( V_195 ) ) )
V_195 -> V_288 -> V_204 = F_26 ( V_195 -> V_288 ) ;
F_157 ( F_16 ( V_289 , & V_195 -> V_290 ) ) ;
F_289 ( V_195 ) ;
}
struct V_18 * F_290 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_276 ( V_6 ) ;
if ( V_19 )
F_281 ( V_19 ) ;
return V_19 ;
}
bool F_291 ( struct V_18 * V_195 , int error , unsigned int V_291 )
{
int V_292 ;
F_292 ( V_195 -> V_6 , V_195 , V_291 ) ;
if ( ! V_195 -> V_35 )
return false ;
if ( V_195 -> V_51 == V_222 )
V_195 -> V_225 = 0 ;
if ( error && V_195 -> V_51 == V_222 &&
! ( V_195 -> V_40 & V_41 ) ) {
char * V_293 ;
switch ( error ) {
case - V_294 :
V_293 = L_22 ;
break;
case - V_295 :
V_293 = L_23 ;
break;
case - V_296 :
V_293 = L_24 ;
break;
case - V_297 :
V_293 = L_25 ;
break;
case - V_298 :
V_293 = L_26 ;
break;
case - V_299 :
V_293 = L_27 ;
break;
case - V_39 :
default:
V_293 = L_28 ;
break;
}
F_145 ( V_253 L_29 ,
V_172 , V_293 , V_195 -> V_49 ?
V_195 -> V_49 -> V_50 : L_2 ,
( unsigned long long ) F_23 ( V_195 ) ) ;
}
F_261 ( V_195 , V_291 ) ;
V_292 = 0 ;
while ( V_195 -> V_35 ) {
struct V_35 * V_35 = V_195 -> V_35 ;
unsigned V_300 = F_293 ( V_35 -> V_43 . V_44 , V_291 ) ;
if ( V_300 == V_35 -> V_43 . V_44 )
V_195 -> V_35 = V_35 -> V_208 ;
F_14 ( V_195 , V_35 , V_300 , error ) ;
V_292 += V_300 ;
V_291 -= V_300 ;
if ( ! V_291 )
break;
}
if ( ! V_195 -> V_35 ) {
V_195 -> V_182 = 0 ;
return false ;
}
V_195 -> V_182 -= V_292 ;
if ( V_195 -> V_51 == V_222 )
V_195 -> V_23 += V_292 >> 9 ;
if ( V_195 -> V_40 & V_269 ) {
V_195 -> V_40 &= ~ V_207 ;
V_195 -> V_40 |= V_195 -> V_35 -> V_150 & V_207 ;
}
if ( F_26 ( V_195 ) < F_294 ( V_195 ) ) {
F_21 ( V_195 , L_30 ) ;
V_195 -> V_182 = F_294 ( V_195 ) ;
}
F_256 ( V_195 ) ;
return true ;
}
static bool F_295 ( struct V_18 * V_19 , int error ,
unsigned int V_291 ,
unsigned int V_301 )
{
if ( F_291 ( V_19 , error , V_291 ) )
return true ;
if ( F_17 ( F_288 ( V_19 ) ) &&
F_291 ( V_19 -> V_288 , error , V_301 ) )
return true ;
if ( F_296 ( V_19 -> V_6 ) )
F_297 ( V_19 -> V_49 ) ;
return false ;
}
void F_298 ( struct V_18 * V_195 )
{
struct V_11 * V_6 = V_195 -> V_6 ;
V_195 -> V_40 &= ~ V_283 ;
if ( V_6 -> V_134 )
V_6 -> V_134 ( V_6 , V_195 ) ;
}
void F_299 ( struct V_18 * V_195 , int error )
{
if ( V_195 -> V_40 & V_183 )
F_172 ( V_195 -> V_6 , V_195 ) ;
F_157 ( F_173 ( V_195 ) ) ;
if ( F_17 ( V_302 ) && V_195 -> V_51 == V_222 )
F_300 ( & V_195 -> V_6 -> V_8 ) ;
F_169 ( V_195 ) ;
if ( V_195 -> V_40 & V_283 )
F_298 ( V_195 ) ;
F_267 ( V_195 ) ;
if ( V_195 -> V_252 )
V_195 -> V_252 ( V_195 , error ) ;
else {
if ( F_288 ( V_195 ) )
F_185 ( V_195 -> V_288 -> V_6 , V_195 -> V_288 ) ;
F_185 ( V_195 -> V_6 , V_195 ) ;
}
}
static bool F_301 ( struct V_18 * V_19 , int error ,
unsigned int V_291 , unsigned int V_301 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_69 ;
if ( F_295 ( V_19 , error , V_291 , V_301 ) )
return true ;
F_53 ( V_6 -> V_57 , V_69 ) ;
F_299 ( V_19 , error ) ;
F_54 ( V_6 -> V_57 , V_69 ) ;
return false ;
}
bool F_302 ( struct V_18 * V_19 , int error ,
unsigned int V_291 , unsigned int V_301 )
{
if ( F_295 ( V_19 , error , V_291 , V_301 ) )
return true ;
F_299 ( V_19 , error ) ;
return false ;
}
bool F_303 ( struct V_18 * V_19 , int error , unsigned int V_291 )
{
return F_301 ( V_19 , error , V_291 , 0 ) ;
}
void F_304 ( struct V_18 * V_19 , int error )
{
bool V_303 ;
unsigned int V_301 = 0 ;
if ( F_17 ( F_288 ( V_19 ) ) )
V_301 = F_26 ( V_19 -> V_288 ) ;
V_303 = F_301 ( V_19 , error , F_26 ( V_19 ) , V_301 ) ;
F_157 ( V_303 ) ;
}
bool F_305 ( struct V_18 * V_19 , int error )
{
return F_303 ( V_19 , error , F_294 ( V_19 ) ) ;
}
bool F_306 ( struct V_18 * V_19 , int error )
{
F_38 ( error >= 0 ) ;
return F_303 ( V_19 , error , F_260 ( V_19 ) ) ;
}
bool F_307 ( struct V_18 * V_19 , int error , unsigned int V_291 )
{
return F_302 ( V_19 , error , V_291 , 0 ) ;
}
void F_282 ( struct V_18 * V_19 , int error )
{
bool V_303 ;
unsigned int V_301 = 0 ;
if ( F_17 ( F_288 ( V_19 ) ) )
V_301 = F_26 ( V_19 -> V_288 ) ;
V_303 = F_302 ( V_19 , error , F_26 ( V_19 ) , V_301 ) ;
F_157 ( V_303 ) ;
}
bool F_308 ( struct V_18 * V_19 , int error )
{
return F_307 ( V_19 , error , F_294 ( V_19 ) ) ;
}
bool F_309 ( struct V_18 * V_19 , int error )
{
F_38 ( error >= 0 ) ;
return F_307 ( V_19 , error , F_260 ( V_19 ) ) ;
}
void F_205 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
V_19 -> V_40 |= V_35 -> V_150 & V_304 ;
if ( F_248 ( V_35 ) )
V_19 -> V_205 = F_310 ( V_6 , V_35 ) ;
V_19 -> V_182 = V_35 -> V_43 . V_44 ;
V_19 -> V_35 = V_19 -> V_52 = V_35 ;
if ( V_35 -> V_234 )
V_19 -> V_49 = V_35 -> V_234 -> V_305 ;
}
void F_311 ( struct V_18 * V_19 )
{
struct V_306 V_307 ;
struct V_308 V_309 ;
F_312 (bvec, rq, iter)
F_313 ( V_309 . V_199 ) ;
}
int F_314 ( struct V_11 * V_6 )
{
if ( V_6 -> V_310 )
return V_6 -> V_310 ( V_6 ) ;
return 0 ;
}
void F_315 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_208 ;
F_316 ( V_35 ) ;
}
}
static void F_317 ( struct V_18 * V_311 , struct V_18 * V_312 )
{
V_311 -> V_22 = V_312 -> V_22 ;
V_311 -> V_40 |= ( V_312 -> V_40 & V_313 ) | V_314 ;
V_311 -> V_51 = V_312 -> V_51 ;
V_311 -> V_23 = F_23 ( V_312 ) ;
V_311 -> V_182 = F_26 ( V_312 ) ;
V_311 -> V_205 = V_312 -> V_205 ;
V_311 -> V_209 = V_312 -> V_209 ;
V_311 -> V_315 = V_312 -> V_315 ;
}
int F_318 ( struct V_18 * V_19 , struct V_18 * V_316 ,
struct V_317 * V_318 , T_2 V_95 ,
int (* F_319)( struct V_35 * , struct V_35 * , void * ) ,
void * V_96 )
{
struct V_35 * V_35 , * V_319 ;
if ( ! V_318 )
V_318 = V_320 ;
F_320 (bio_src, rq_src) {
V_35 = F_321 ( V_319 , V_95 , V_318 ) ;
if ( ! V_35 )
goto V_321;
if ( F_319 && F_319 ( V_35 , V_319 , V_96 ) )
goto V_321;
if ( V_19 -> V_35 ) {
V_19 -> V_52 -> V_208 = V_35 ;
V_19 -> V_52 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_52 = V_35 ;
}
F_317 ( V_19 , V_316 ) ;
return 0 ;
V_321:
if ( V_35 )
F_316 ( V_35 ) ;
F_315 ( V_19 ) ;
return - V_105 ;
}
int F_322 ( struct V_54 * V_55 )
{
return F_323 ( V_59 , V_55 ) ;
}
int F_324 ( struct V_322 * V_323 ,
unsigned long V_324 )
{
return F_35 ( V_59 , V_323 , V_324 ) ;
}
int F_325 ( int V_22 , struct V_322 * V_323 ,
unsigned long V_324 )
{
return F_326 ( V_22 , V_59 , V_323 , V_324 ) ;
}
void F_327 ( struct V_213 * V_214 )
{
struct V_325 * V_326 = V_154 ;
if ( V_326 -> V_214 )
return;
F_10 ( & V_214 -> V_218 ) ;
F_10 ( & V_214 -> V_217 ) ;
F_10 ( & V_214 -> V_327 ) ;
V_326 -> V_214 = V_214 ;
}
static int F_328 ( void * V_328 , struct V_215 * V_329 , struct V_215 * V_240 )
{
struct V_18 * V_330 = F_28 ( V_329 , struct V_18 , V_20 ) ;
struct V_18 * V_331 = F_28 ( V_240 , struct V_18 , V_20 ) ;
return ! ( V_330 -> V_6 < V_331 -> V_6 ||
( V_330 -> V_6 == V_331 -> V_6 && F_23 ( V_330 ) < F_23 ( V_331 ) ) ) ;
}
static void F_329 ( struct V_11 * V_6 , unsigned int V_332 ,
bool V_333 )
__releases( V_6 -> V_57 )
{
F_330 ( V_6 , V_332 , ! V_333 ) ;
if ( V_333 )
F_50 ( V_6 ) ;
else
F_30 ( V_6 ) ;
F_331 ( V_6 -> V_57 ) ;
}
static void F_332 ( struct V_213 * V_214 , bool V_333 )
{
F_333 ( V_334 ) ;
while ( ! F_61 ( & V_214 -> V_327 ) ) {
F_334 ( & V_214 -> V_327 , & V_334 ) ;
while ( ! F_61 ( & V_334 ) ) {
struct V_335 * V_336 = F_335 ( & V_334 ,
struct V_335 ,
V_218 ) ;
F_336 ( & V_336 -> V_218 ) ;
V_336 -> V_337 ( V_336 , V_333 ) ;
}
}
}
struct V_335 * F_337 ( T_6 V_338 , void * V_96 ,
int V_339 )
{
struct V_213 * V_214 = V_154 -> V_214 ;
struct V_335 * V_336 ;
if ( ! V_214 )
return NULL ;
F_338 (cb, &plug->cb_list, list)
if ( V_336 -> V_337 == V_338 && V_336 -> V_96 == V_96 )
return V_336 ;
F_157 ( V_339 < sizeof( * V_336 ) ) ;
V_336 = F_339 ( V_339 , V_259 ) ;
if ( V_336 ) {
V_336 -> V_96 = V_96 ;
V_336 -> V_337 = V_338 ;
F_340 ( & V_336 -> V_218 , & V_214 -> V_327 ) ;
}
return V_336 ;
}
void F_217 ( struct V_213 * V_214 , bool V_333 )
{
struct V_11 * V_6 ;
unsigned long V_69 ;
struct V_18 * V_19 ;
F_333 ( V_218 ) ;
unsigned int V_332 ;
F_332 ( V_214 , V_333 ) ;
if ( ! F_61 ( & V_214 -> V_217 ) )
F_341 ( V_214 , V_333 ) ;
if ( F_61 ( & V_214 -> V_218 ) )
return;
F_334 ( & V_214 -> V_218 , & V_218 ) ;
F_342 ( NULL , & V_218 , F_328 ) ;
V_6 = NULL ;
V_332 = 0 ;
F_343 ( V_69 ) ;
while ( ! F_61 ( & V_218 ) ) {
V_19 = F_344 ( V_218 . V_340 ) ;
F_284 ( & V_19 -> V_20 ) ;
F_157 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_329 ( V_6 , V_332 , V_333 ) ;
V_6 = V_19 -> V_6 ;
V_332 = 0 ;
F_345 ( V_6 -> V_57 ) ;
}
if ( F_17 ( F_112 ( V_6 ) ) ) {
F_282 ( V_19 , - V_161 ) ;
continue;
}
if ( V_19 -> V_40 & ( V_151 | V_152 ) )
F_177 ( V_6 , V_19 , V_228 ) ;
else
F_177 ( V_6 , V_19 , V_341 ) ;
V_332 ++ ;
}
if ( V_6 )
F_329 ( V_6 , V_332 , V_333 ) ;
F_346 ( V_69 ) ;
}
void F_347 ( struct V_213 * V_214 )
{
if ( V_214 != V_154 -> V_214 )
return;
F_217 ( V_214 , false ) ;
V_154 -> V_214 = NULL ;
}
void F_348 ( struct V_11 * V_6 , struct V_342 * V_173 )
{
V_6 -> V_173 = V_173 ;
V_6 -> V_274 = V_276 ;
F_349 ( V_6 -> V_173 , - 1 ) ;
F_350 ( V_6 -> V_173 ) ;
}
int F_351 ( struct V_11 * V_6 )
{
int V_181 = 0 ;
F_29 ( V_6 -> V_57 ) ;
if ( V_6 -> V_194 ) {
V_181 = - V_343 ;
F_184 ( V_6 -> V_173 ) ;
} else {
V_6 -> V_274 = V_344 ;
}
F_31 ( V_6 -> V_57 ) ;
return V_181 ;
}
void F_352 ( struct V_11 * V_6 , int V_108 )
{
F_29 ( V_6 -> V_57 ) ;
if ( ! V_108 ) {
V_6 -> V_274 = V_275 ;
} else {
V_6 -> V_274 = V_276 ;
F_184 ( V_6 -> V_173 ) ;
}
F_31 ( V_6 -> V_57 ) ;
}
void F_353 ( struct V_11 * V_6 )
{
F_29 ( V_6 -> V_57 ) ;
V_6 -> V_274 = V_345 ;
F_31 ( V_6 -> V_57 ) ;
}
void F_354 ( struct V_11 * V_6 , int V_108 )
{
F_29 ( V_6 -> V_57 ) ;
if ( ! V_108 ) {
V_6 -> V_274 = V_276 ;
F_30 ( V_6 ) ;
F_184 ( V_6 -> V_173 ) ;
F_355 ( V_6 -> V_173 ) ;
} else {
V_6 -> V_274 = V_275 ;
}
F_31 ( V_6 -> V_57 ) ;
}
int T_4 F_356 ( void )
{
F_357 ( V_346 > 8 *
F_358 ( struct V_18 , V_40 ) ) ;
V_59 = F_359 ( L_31 ,
V_347 | V_348 , 0 ) ;
if ( ! V_59 )
F_360 ( L_32 ) ;
V_98 = F_361 ( L_33 ,
sizeof( struct V_18 ) , 0 , V_349 , NULL ) ;
V_109 = F_361 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_349 , NULL ) ;
return 0 ;
}
