void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = V_2 -> V_4 - ( V_2 -> V_4 / 8 ) + 1 ;
if ( V_3 > V_2 -> V_4 )
V_3 = V_2 -> V_4 ;
V_2 -> V_5 = V_3 ;
V_3 = V_2 -> V_4 - ( V_2 -> V_4 / 8 ) - ( V_2 -> V_4 / 16 ) - 1 ;
if ( V_3 < 1 )
V_3 = 1 ;
V_2 -> V_6 = V_3 ;
}
struct V_7 * F_2 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_3 ( V_9 ) ;
return & V_2 -> V_7 ;
}
void F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_5 ( & V_11 -> V_12 ) ;
F_5 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = - 1 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_15 = ( V_16 ) - 1 ;
F_6 ( & V_11 -> V_17 ) ;
F_7 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = V_11 -> V_20 ;
V_11 -> V_21 = V_22 ;
V_11 -> V_23 = - 1 ;
V_11 -> V_24 = V_25 ;
F_8 ( V_11 ) ;
V_11 -> V_26 = NULL ;
}
static void F_9 ( struct V_10 * V_11 , struct V_27 * V_27 ,
unsigned int V_28 , int error )
{
if ( error )
F_10 ( V_29 , & V_27 -> V_30 ) ;
else if ( ! F_11 ( V_29 , & V_27 -> V_30 ) )
error = - V_31 ;
if ( F_12 ( V_11 -> V_32 & V_33 ) )
F_13 ( V_34 , & V_27 -> V_30 ) ;
F_14 ( V_27 , V_28 ) ;
if ( V_27 -> V_35 . V_36 == 0 && ! ( V_11 -> V_32 & V_37 ) )
F_15 ( V_27 , error ) ;
}
void F_16 ( struct V_10 * V_11 , char * V_38 )
{
int V_39 ;
F_17 ( V_40 L_1 , V_38 ,
V_11 -> V_41 ? V_11 -> V_41 -> V_42 : L_2 , V_11 -> V_43 ,
( unsigned long long ) V_11 -> V_32 ) ;
F_17 ( V_40 L_3 ,
( unsigned long long ) F_18 ( V_11 ) ,
F_19 ( V_11 ) , F_20 ( V_11 ) ) ;
F_17 ( V_40 L_4 ,
V_11 -> V_27 , V_11 -> V_44 , F_21 ( V_11 ) ) ;
if ( V_11 -> V_43 == V_45 ) {
F_17 ( V_40 L_5 ) ;
for ( V_39 = 0 ; V_39 < V_22 ; V_39 ++ )
F_17 ( L_6 , V_11 -> V_19 [ V_39 ] ) ;
F_17 ( L_7 ) ;
}
}
static void F_22 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_47 , struct V_1 , V_48 . V_47 ) ;
F_24 ( V_2 -> V_49 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_49 ) ;
}
void F_27 ( struct V_1 * V_2 , unsigned long V_50 )
{
if ( F_28 ( ! F_29 ( V_2 ) ) )
F_30 ( V_51 , & V_2 -> V_48 ,
F_31 ( V_50 ) ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( ! F_34 () ) ;
F_35 ( V_52 , V_2 ) ;
F_25 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_48 ) ;
F_38 ( V_52 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
struct V_55 * V_56 ;
int V_57 ;
F_41 (q, hctx, i) {
F_42 ( & V_56 -> V_58 ) ;
F_42 ( & V_56 -> V_48 ) ;
}
} else {
F_42 ( & V_2 -> V_48 ) ;
}
}
inline void F_43 ( struct V_1 * V_2 )
{
if ( F_12 ( F_29 ( V_2 ) ) )
return;
V_2 -> V_59 ++ ;
V_2 -> V_60 ( V_2 ) ;
V_2 -> V_59 -- ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_12 ( F_44 ( V_2 ) ) )
return;
F_43 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_44 ( V_2 ) && ! F_29 ( V_2 ) ) )
F_46 ( V_51 , & V_2 -> V_48 , 0 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_61 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_62 ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_63 )
__releases( V_2 -> V_49 )
__acquires( V_2 -> V_49 )
{
int V_57 ;
F_53 ( V_2 -> V_49 ) ;
while ( true ) {
bool V_64 = false ;
if ( V_2 -> V_65 )
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( ! F_56 ( & V_2 -> V_66 ) && V_2 -> V_60 )
F_25 ( V_2 ) ;
V_64 |= V_2 -> V_67 ;
V_64 |= V_2 -> V_59 ;
if ( V_63 ) {
struct V_68 * V_69 = F_57 ( V_2 , NULL ) ;
V_64 |= ! F_56 ( & V_2 -> V_66 ) ;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
V_64 |= V_2 -> V_70 [ V_57 ] ;
V_64 |= V_2 -> V_71 [ V_57 ] ;
if ( V_69 )
V_64 |= ! F_56 ( & V_69 -> V_72 [ V_57 ] ) ;
}
}
if ( ! V_64 )
break;
F_26 ( V_2 -> V_49 ) ;
F_58 ( 10 ) ;
F_24 ( V_2 -> V_49 ) ;
}
if ( V_2 -> V_60 ) {
struct V_73 * V_74 ;
F_59 (rl, q)
for ( V_57 = 0 ; V_57 < F_60 ( V_74 -> V_75 ) ; V_57 ++ )
F_61 ( & V_74 -> V_75 [ V_57 ] ) ;
}
}
void F_62 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_76 ++ ;
F_38 ( V_77 , V_2 ) ;
F_26 ( V_2 -> V_49 ) ;
if ( F_63 ( V_2 ) ) {
F_24 ( V_2 -> V_49 ) ;
F_52 ( V_2 , false ) ;
F_26 ( V_2 -> V_49 ) ;
F_64 () ;
}
}
void F_65 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! -- V_2 -> V_76 )
F_35 ( V_77 , V_2 ) ;
F_66 ( V_2 -> V_76 < 0 ) ;
F_26 ( V_2 -> V_49 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_68 ( V_78 , V_2 ) ;
if ( V_2 -> V_54 )
F_69 ( V_2 ) ;
else {
struct V_73 * V_74 ;
F_59 (rl, q) {
if ( V_74 -> V_79 ) {
F_70 ( & V_74 -> V_75 [ V_80 ] ) ;
F_70 ( & V_74 -> V_75 [ V_81 ] ) ;
}
}
}
}
void F_71 ( struct V_1 * V_2 )
{
T_1 * V_82 = V_2 -> V_49 ;
F_72 ( & V_2 -> V_83 ) ;
F_67 ( V_2 ) ;
F_24 ( V_82 ) ;
V_2 -> V_76 ++ ;
F_38 ( V_77 , V_2 ) ;
F_38 ( V_84 , V_2 ) ;
F_38 ( V_85 , V_2 ) ;
F_38 ( V_78 , V_2 ) ;
F_26 ( V_82 ) ;
F_73 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_54 ) {
F_74 ( V_2 ) ;
F_24 ( V_82 ) ;
} else {
F_24 ( V_82 ) ;
F_52 ( V_2 , true ) ;
}
F_38 ( V_86 , V_2 ) ;
F_26 ( V_82 ) ;
F_40 ( & V_2 -> V_7 . V_87 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_54 )
F_75 ( V_2 ) ;
F_24 ( V_82 ) ;
if ( V_2 -> V_49 != & V_2 -> V_88 )
V_2 -> V_49 = & V_2 -> V_88 ;
F_26 ( V_82 ) ;
F_76 ( & V_2 -> V_7 ) ;
F_50 ( V_2 ) ;
}
static void * F_77 ( T_2 V_89 , void * V_90 )
{
int V_91 = ( int ) ( long ) V_90 ;
return F_78 ( V_92 , V_89 , V_91 ) ;
}
static void F_79 ( void * V_93 , void * V_94 )
{
F_80 ( V_92 , V_93 ) ;
}
int F_81 ( struct V_73 * V_74 , struct V_1 * V_2 ,
T_2 V_89 )
{
if ( F_12 ( V_74 -> V_79 ) )
return 0 ;
V_74 -> V_2 = V_2 ;
V_74 -> V_95 [ V_80 ] = V_74 -> V_95 [ V_81 ] = 0 ;
V_74 -> V_96 [ V_80 ] = V_74 -> V_96 [ V_81 ] = 0 ;
F_82 ( & V_74 -> V_75 [ V_80 ] ) ;
F_82 ( & V_74 -> V_75 [ V_81 ] ) ;
V_74 -> V_79 = F_83 ( V_97 , F_77 ,
F_79 ,
( void * ) ( long ) V_2 -> V_98 , V_89 ,
V_2 -> V_98 ) ;
if ( ! V_74 -> V_79 )
return - V_99 ;
return 0 ;
}
void F_84 ( struct V_73 * V_74 )
{
if ( V_74 -> V_79 )
F_85 ( V_74 -> V_79 ) ;
}
struct V_1 * F_86 ( T_2 V_89 )
{
return F_87 ( V_89 , V_100 ) ;
}
struct V_1 * F_87 ( T_2 V_89 , int V_101 )
{
struct V_1 * V_2 ;
int V_102 ;
V_2 = F_78 ( V_103 ,
V_89 | V_104 , V_101 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_105 = F_88 ( & V_106 , 0 , 0 , V_89 ) ;
if ( V_2 -> V_105 < 0 )
goto V_107;
V_2 -> V_7 . V_108 =
( V_109 * 1024 ) / V_110 ;
V_2 -> V_7 . V_111 = 0 ;
V_2 -> V_7 . V_112 = 0 ;
V_2 -> V_7 . V_113 = L_8 ;
V_2 -> V_98 = V_101 ;
V_102 = F_89 ( & V_2 -> V_7 ) ;
if ( V_102 )
goto V_114;
F_90 ( & V_2 -> V_7 . V_87 ,
V_115 , ( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_53 , V_116 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_66 ) ;
F_5 ( & V_2 -> V_13 ) ;
F_5 ( & V_2 -> V_117 ) ;
#ifdef F_91
F_5 ( & V_2 -> V_118 ) ;
#endif
F_92 ( & V_2 -> V_48 , F_22 ) ;
F_93 ( & V_2 -> V_62 , & V_119 ) ;
F_94 ( & V_2 -> V_83 ) ;
F_95 ( & V_2 -> V_88 ) ;
V_2 -> V_49 = & V_2 -> V_88 ;
V_2 -> V_76 = 1 ;
F_96 ( V_77 , & V_2 -> V_120 ) ;
F_82 ( & V_2 -> V_121 ) ;
if ( F_97 ( V_2 ) )
goto V_122;
return V_2 ;
V_122:
F_76 ( & V_2 -> V_7 ) ;
V_114:
F_98 ( & V_106 , V_2 -> V_105 ) ;
V_107:
F_80 ( V_103 , V_2 ) ;
return NULL ;
}
struct V_1 * F_99 ( T_3 * V_123 , T_1 * V_82 )
{
return F_100 ( V_123 , V_82 , V_100 ) ;
}
struct V_1 *
F_100 ( T_3 * V_123 , T_1 * V_82 , int V_101 )
{
struct V_1 * V_124 , * V_2 ;
V_124 = F_87 ( V_125 , V_101 ) ;
if ( ! V_124 )
return NULL ;
V_2 = F_101 ( V_124 , V_123 , V_82 ) ;
if ( ! V_2 )
F_71 ( V_124 ) ;
return V_2 ;
}
struct V_1 *
F_101 ( struct V_1 * V_2 , T_3 * V_123 ,
T_1 * V_82 )
{
if ( ! V_2 )
return NULL ;
V_2 -> V_69 = F_102 ( V_2 , V_100 , 0 ) ;
if ( ! V_2 -> V_69 )
return NULL ;
if ( F_81 ( & V_2 -> V_126 , V_2 , V_125 ) )
goto V_127;
V_2 -> V_60 = V_123 ;
V_2 -> V_128 = NULL ;
V_2 -> V_129 = NULL ;
V_2 -> V_120 |= V_130 ;
if ( V_82 )
V_2 -> V_49 = V_82 ;
F_103 ( V_2 , V_131 ) ;
V_2 -> V_132 = V_133 ;
F_72 ( & V_2 -> V_83 ) ;
if ( F_104 ( V_2 , NULL ) ) {
F_73 ( & V_2 -> V_83 ) ;
goto V_127;
}
F_73 ( & V_2 -> V_83 ) ;
return V_2 ;
V_127:
F_105 ( V_2 -> V_69 ) ;
return NULL ;
}
bool F_106 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_107 ( V_2 ) ) ) {
F_108 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_109 ( struct V_73 * V_74 , struct V_10 * V_11 )
{
if ( V_11 -> V_32 & V_134 ) {
F_110 ( V_74 -> V_2 , V_11 ) ;
if ( V_11 -> V_135 . V_136 )
F_111 ( V_11 -> V_135 . V_136 -> V_137 ) ;
}
F_112 ( V_11 , V_74 -> V_79 ) ;
}
static inline int F_113 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
if ( ! V_137 )
return 0 ;
return V_137 -> V_139 == V_2 -> V_140 ||
( V_137 -> V_139 > 0
&& F_114 ( V_25 , V_137 -> V_141 + V_142 ) ) ;
}
static void F_115 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
if ( ! V_137 || F_113 ( V_2 , V_137 ) )
return;
V_137 -> V_139 = V_2 -> V_140 ;
V_137 -> V_141 = V_25 ;
}
static void F_116 ( struct V_73 * V_74 , int V_143 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
if ( V_74 == & V_2 -> V_126 &&
V_74 -> V_95 [ V_143 ] < F_117 ( V_2 ) )
F_118 ( V_2 , V_143 ) ;
if ( V_74 -> V_95 [ V_143 ] + 1 <= V_2 -> V_4 ) {
if ( F_119 ( & V_74 -> V_75 [ V_143 ] ) )
F_70 ( & V_74 -> V_75 [ V_143 ] ) ;
F_120 ( V_74 , V_143 ) ;
}
}
static void F_121 ( struct V_73 * V_74 , unsigned int V_61 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_143 = F_122 ( V_61 ) ;
V_2 -> V_70 [ V_143 ] -- ;
V_74 -> V_95 [ V_143 ] -- ;
if ( V_61 & V_134 )
V_2 -> V_67 -- ;
F_116 ( V_74 , V_143 ) ;
if ( F_12 ( V_74 -> V_96 [ V_143 ^ 1 ] ) )
F_116 ( V_74 , V_143 ^ 1 ) ;
}
int F_123 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_73 * V_74 ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_4 = V_3 ;
F_1 ( V_2 ) ;
V_74 = & V_2 -> V_126 ;
if ( V_74 -> V_95 [ V_80 ] >= F_124 ( V_2 ) )
F_125 ( V_2 , V_80 ) ;
else if ( V_74 -> V_95 [ V_80 ] < F_117 ( V_2 ) )
F_118 ( V_2 , V_80 ) ;
if ( V_74 -> V_95 [ V_81 ] >= F_124 ( V_2 ) )
F_125 ( V_2 , V_81 ) ;
else if ( V_74 -> V_95 [ V_81 ] < F_117 ( V_2 ) )
F_118 ( V_2 , V_81 ) ;
F_59 (rl, q) {
if ( V_74 -> V_95 [ V_80 ] >= V_2 -> V_4 ) {
F_126 ( V_74 , V_80 ) ;
} else {
F_120 ( V_74 , V_80 ) ;
F_70 ( & V_74 -> V_75 [ V_80 ] ) ;
}
if ( V_74 -> V_95 [ V_81 ] >= V_2 -> V_4 ) {
F_126 ( V_74 , V_81 ) ;
} else {
F_120 ( V_74 , V_81 ) ;
F_70 ( & V_74 -> V_75 [ V_81 ] ) ;
}
}
F_26 ( V_2 -> V_49 ) ;
return 0 ;
}
static bool F_127 ( struct V_27 * V_27 )
{
if ( ! V_27 )
return true ;
if ( V_27 -> V_144 & ( V_145 | V_146 ) )
return false ;
return true ;
}
static struct V_138 * F_128 ( struct V_27 * V_27 )
{
#ifdef F_91
if ( V_27 && V_27 -> V_147 )
return V_27 -> V_147 ;
#endif
return V_148 -> V_138 ;
}
static struct V_10 * F_129 ( struct V_73 * V_74 , int V_149 ,
struct V_27 * V_27 , T_2 V_89 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_10 * V_11 ;
struct V_150 * V_151 = V_2 -> V_65 -> type ;
struct V_138 * V_137 = F_128 ( V_27 ) ;
struct V_152 * V_136 = NULL ;
const bool V_153 = F_122 ( V_149 ) != 0 ;
int V_154 ;
if ( F_12 ( F_107 ( V_2 ) ) )
return F_130 ( - V_155 ) ;
V_154 = F_131 ( V_2 , V_149 ) ;
if ( V_154 == V_156 )
goto V_157;
if ( V_74 -> V_95 [ V_153 ] + 1 >= F_124 ( V_2 ) ) {
if ( V_74 -> V_95 [ V_153 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_132 ( V_74 , V_153 ) ) {
F_115 ( V_2 , V_137 ) ;
F_126 ( V_74 , V_153 ) ;
} else {
if ( V_154 != V_158
&& ! F_113 ( V_2 , V_137 ) ) {
return F_130 ( - V_99 ) ;
}
}
}
if ( V_74 == & V_2 -> V_126 )
F_125 ( V_2 , V_153 ) ;
}
if ( V_74 -> V_95 [ V_153 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return F_130 ( - V_99 ) ;
V_2 -> V_70 [ V_153 ] ++ ;
V_74 -> V_95 [ V_153 ] ++ ;
V_74 -> V_96 [ V_153 ] = 0 ;
if ( F_127 ( V_27 ) && ! F_133 ( V_2 ) ) {
V_149 |= V_134 ;
V_2 -> V_67 ++ ;
if ( V_151 -> V_159 && V_137 )
V_136 = F_134 ( V_137 , V_2 ) ;
}
if ( F_135 ( V_2 ) )
V_149 |= V_160 ;
F_26 ( V_2 -> V_49 ) ;
V_11 = F_136 ( V_74 -> V_79 , V_89 ) ;
if ( ! V_11 )
goto V_161;
F_4 ( V_2 , V_11 ) ;
F_137 ( V_11 , V_74 ) ;
V_11 -> V_32 = V_149 | V_162 ;
if ( V_149 & V_134 ) {
if ( F_12 ( V_151 -> V_159 && ! V_136 ) ) {
if ( V_137 )
V_136 = F_138 ( V_137 , V_2 , V_89 ) ;
if ( ! V_136 )
goto V_163;
}
V_11 -> V_135 . V_136 = V_136 ;
if ( F_12 ( F_139 ( V_2 , V_11 , V_27 , V_89 ) ) )
goto V_163;
if ( V_136 )
F_140 ( V_136 -> V_137 ) ;
}
V_164:
if ( F_113 ( V_2 , V_137 ) )
V_137 -> V_139 -- ;
F_141 ( V_2 , V_27 , V_149 & 1 ) ;
return V_11 ;
V_163:
F_142 ( V_165 L_9 ,
V_166 , F_143 ( V_2 -> V_7 . V_167 ) ) ;
V_11 -> V_32 &= ~ V_134 ;
V_11 -> V_135 . V_136 = NULL ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_67 -- ;
F_26 ( V_2 -> V_49 ) ;
goto V_164;
V_161:
F_24 ( V_2 -> V_49 ) ;
F_121 ( V_74 , V_149 ) ;
V_157:
if ( F_12 ( V_74 -> V_95 [ V_153 ] == 0 ) )
V_74 -> V_96 [ V_153 ] = 1 ;
return F_130 ( - V_99 ) ;
}
static struct V_10 * F_144 ( struct V_1 * V_2 , int V_149 ,
struct V_27 * V_27 , T_2 V_89 )
{
const bool V_153 = F_122 ( V_149 ) != 0 ;
F_145 ( V_75 ) ;
struct V_73 * V_74 ;
struct V_10 * V_11 ;
V_74 = F_146 ( V_2 , V_27 ) ;
V_168:
V_11 = F_129 ( V_74 , V_149 , V_27 , V_89 ) ;
if ( ! F_147 ( V_11 ) )
return V_11 ;
if ( ! ( V_89 & V_169 ) || F_12 ( F_107 ( V_2 ) ) ) {
F_148 ( V_74 ) ;
return V_11 ;
}
F_149 ( & V_74 -> V_75 [ V_153 ] , & V_75 ,
V_170 ) ;
F_150 ( V_2 , V_27 , V_149 & 1 ) ;
F_26 ( V_2 -> V_49 ) ;
F_151 () ;
F_115 ( V_2 , V_148 -> V_138 ) ;
F_24 ( V_2 -> V_49 ) ;
F_152 ( & V_74 -> V_75 [ V_153 ] , & V_75 ) ;
goto V_168;
}
static struct V_10 * F_153 ( struct V_1 * V_2 , int V_171 ,
T_2 V_89 )
{
struct V_10 * V_11 ;
F_154 ( V_171 != V_172 && V_171 != V_173 ) ;
F_155 ( V_89 , V_2 -> V_98 ) ;
F_24 ( V_2 -> V_49 ) ;
V_11 = F_144 ( V_2 , V_171 , NULL , V_89 ) ;
if ( F_147 ( V_11 ) )
F_26 ( V_2 -> V_49 ) ;
return V_11 ;
}
struct V_10 * F_156 ( struct V_1 * V_2 , int V_171 , T_2 V_89 )
{
if ( V_2 -> V_54 )
return F_157 ( V_2 , V_171 , V_89 , false ) ;
else
return F_153 ( V_2 , V_171 , V_89 ) ;
}
struct V_10 * F_158 ( struct V_1 * V_2 , struct V_27 * V_27 ,
T_2 V_89 )
{
struct V_10 * V_11 = F_156 ( V_2 , F_159 ( V_27 ) , V_89 ) ;
if ( F_147 ( V_11 ) )
return V_11 ;
F_160 ( V_11 ) ;
F_161 (bio) {
struct V_27 * V_174 = V_27 ;
int V_175 ;
F_162 ( V_2 , & V_174 ) ;
V_175 = F_163 ( V_2 , V_11 , V_174 ) ;
if ( F_12 ( V_175 ) ) {
F_164 ( V_11 ) ;
return F_130 ( V_175 ) ;
}
}
return V_11 ;
}
void F_160 ( struct V_10 * V_11 )
{
V_11 -> V_43 = V_45 ;
V_11 -> V_176 = 0 ;
V_11 -> V_15 = ( V_16 ) - 1 ;
V_11 -> V_27 = V_11 -> V_44 = NULL ;
memset ( V_11 -> V_20 , 0 , sizeof( V_11 -> V_20 ) ) ;
}
void F_165 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_166 ( V_11 ) ;
F_167 ( V_11 ) ;
F_168 ( V_2 , V_11 ) ;
if ( V_11 -> V_32 & V_177 )
F_169 ( V_2 , V_11 ) ;
F_154 ( F_170 ( V_11 ) ) ;
F_171 ( V_2 , V_11 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_178 )
{
F_173 ( V_11 , true ) ;
F_174 ( V_2 , V_11 , V_178 ) ;
}
static void F_175 ( int V_14 , struct V_179 * V_26 ,
unsigned long V_180 )
{
int V_181 ;
if ( V_180 == V_26 -> V_182 )
return;
V_181 = F_176 ( V_26 ) ;
if ( V_181 ) {
F_177 ( V_14 , V_26 , V_183 ,
V_181 * ( V_180 - V_26 -> V_182 ) ) ;
F_177 ( V_14 , V_26 , V_184 , ( V_180 - V_26 -> V_182 ) ) ;
}
V_26 -> V_182 = V_180 ;
}
void F_178 ( int V_14 , struct V_179 * V_26 )
{
unsigned long V_180 = V_25 ;
if ( V_26 -> V_185 )
F_175 ( V_14 , & F_179 ( V_26 ) -> V_186 , V_180 ) ;
F_175 ( V_14 , V_26 , V_180 ) ;
}
static void F_180 ( struct V_10 * V_11 )
{
if ( V_11 -> V_2 -> V_167 && ! ( V_11 -> V_32 & V_187 ) && ! -- V_11 -> V_2 -> V_188 )
F_181 ( V_11 -> V_2 -> V_167 ) ;
}
static inline void F_180 ( struct V_10 * V_11 ) {}
void F_182 ( struct V_1 * V_2 , struct V_10 * V_189 )
{
if ( F_12 ( ! V_2 ) )
return;
if ( V_2 -> V_54 ) {
F_183 ( V_189 ) ;
return;
}
F_180 ( V_189 ) ;
F_184 ( V_2 , V_189 ) ;
F_33 ( V_189 -> V_27 != NULL ) ;
if ( V_189 -> V_32 & V_162 ) {
unsigned int V_61 = V_189 -> V_32 ;
struct V_73 * V_74 = F_185 ( V_189 ) ;
F_154 ( ! F_56 ( & V_189 -> V_12 ) ) ;
F_154 ( F_186 ( V_189 ) ) ;
F_109 ( V_74 , V_189 ) ;
F_121 ( V_74 , V_61 ) ;
F_148 ( V_74 ) ;
}
}
void F_164 ( struct V_10 * V_189 )
{
struct V_1 * V_2 = V_189 -> V_2 ;
if ( V_2 -> V_54 )
F_183 ( V_189 ) ;
else {
unsigned long V_61 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_182 ( V_2 , V_189 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
}
}
void F_187 ( struct V_10 * V_11 , struct V_190 * V_190 ,
unsigned int V_191 )
{
struct V_27 * V_27 = V_11 -> V_27 ;
V_27 -> V_192 -> V_193 = V_190 ;
V_27 -> V_192 -> V_194 = 0 ;
V_27 -> V_192 -> V_195 = V_191 ;
V_27 -> V_35 . V_36 = V_191 ;
V_27 -> V_196 = 1 ;
V_27 -> V_197 = 1 ;
V_11 -> V_176 = V_11 -> V_198 = V_191 ;
V_11 -> V_199 = 1 ;
}
bool F_188 ( struct V_1 * V_2 , struct V_10 * V_189 ,
struct V_27 * V_27 )
{
const int V_200 = V_27 -> V_144 & V_201 ;
if ( ! F_189 ( V_2 , V_189 , V_27 ) )
return false ;
F_190 ( V_2 , V_189 , V_27 ) ;
if ( ( V_189 -> V_32 & V_201 ) != V_200 )
F_191 ( V_189 ) ;
V_189 -> V_44 -> V_202 = V_27 ;
V_189 -> V_44 = V_27 ;
V_189 -> V_176 += V_27 -> V_35 . V_36 ;
V_189 -> V_203 = F_192 ( V_189 -> V_203 , F_193 ( V_27 ) ) ;
F_173 ( V_189 , false ) ;
return true ;
}
bool F_194 ( struct V_1 * V_2 , struct V_10 * V_189 ,
struct V_27 * V_27 )
{
const int V_200 = V_27 -> V_144 & V_201 ;
if ( ! F_195 ( V_2 , V_189 , V_27 ) )
return false ;
F_196 ( V_2 , V_189 , V_27 ) ;
if ( ( V_189 -> V_32 & V_201 ) != V_200 )
F_191 ( V_189 ) ;
V_27 -> V_202 = V_189 -> V_27 ;
V_189 -> V_27 = V_27 ;
V_189 -> V_15 = V_27 -> V_35 . V_204 ;
V_189 -> V_176 += V_27 -> V_35 . V_36 ;
V_189 -> V_203 = F_192 ( V_189 -> V_203 , F_193 ( V_27 ) ) ;
F_173 ( V_189 , false ) ;
return true ;
}
bool F_197 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned int * V_205 )
{
struct V_206 * V_207 ;
struct V_10 * V_11 ;
bool V_175 = false ;
struct V_208 * V_209 ;
V_207 = V_148 -> V_207 ;
if ( ! V_207 )
goto V_164;
* V_205 = 0 ;
if ( V_2 -> V_54 )
V_209 = & V_207 -> V_210 ;
else
V_209 = & V_207 -> V_211 ;
F_198 (rq, plug_list, queuelist) {
int V_212 ;
if ( V_11 -> V_2 == V_2 )
( * V_205 ) ++ ;
if ( V_11 -> V_2 != V_2 || ! F_199 ( V_11 , V_27 ) )
continue;
V_212 = F_200 ( V_11 , V_27 ) ;
if ( V_212 == V_213 ) {
V_175 = F_188 ( V_2 , V_11 , V_27 ) ;
if ( V_175 )
break;
} else if ( V_212 == V_214 ) {
V_175 = F_194 ( V_2 , V_11 , V_27 ) ;
if ( V_175 )
break;
}
}
V_164:
return V_175 ;
}
void F_201 ( struct V_10 * V_189 , struct V_27 * V_27 )
{
V_189 -> V_43 = V_215 ;
V_189 -> V_32 |= V_27 -> V_144 & V_216 ;
if ( V_27 -> V_144 & V_217 )
V_189 -> V_32 |= V_201 ;
V_189 -> V_218 = 0 ;
V_189 -> V_15 = V_27 -> V_35 . V_204 ;
V_189 -> V_203 = F_193 ( V_27 ) ;
F_202 ( V_189 -> V_2 , V_189 , V_27 ) ;
}
static void V_131 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
const bool V_143 = ! ! ( V_27 -> V_144 & V_219 ) ;
struct V_206 * V_207 ;
int V_212 , V_149 , V_178 = V_220 ;
struct V_10 * V_189 ;
unsigned int V_205 = 0 ;
F_162 ( V_2 , & V_27 ) ;
if ( F_203 ( V_27 ) && F_204 ( V_27 ) ) {
F_15 ( V_27 , - V_31 ) ;
return;
}
if ( V_27 -> V_144 & ( V_145 | V_146 ) ) {
F_24 ( V_2 -> V_49 ) ;
V_178 = V_221 ;
goto V_222;
}
if ( ! F_205 ( V_2 ) &&
F_197 ( V_2 , V_27 , & V_205 ) )
return;
F_24 ( V_2 -> V_49 ) ;
V_212 = F_206 ( V_2 , & V_189 , V_27 ) ;
if ( V_212 == V_213 ) {
if ( F_188 ( V_2 , V_189 , V_27 ) ) {
F_207 ( V_2 , V_189 , V_27 ) ;
if ( ! F_208 ( V_2 , V_189 ) )
F_209 ( V_2 , V_189 , V_212 ) ;
goto V_223;
}
} else if ( V_212 == V_214 ) {
if ( F_194 ( V_2 , V_189 , V_27 ) ) {
F_207 ( V_2 , V_189 , V_27 ) ;
if ( ! F_210 ( V_2 , V_189 ) )
F_209 ( V_2 , V_189 , V_212 ) ;
goto V_223;
}
}
V_222:
V_149 = F_159 ( V_27 ) ;
if ( V_143 )
V_149 |= V_219 ;
V_189 = F_144 ( V_2 , V_149 , V_27 , V_224 ) ;
if ( F_147 ( V_189 ) ) {
F_15 ( V_27 , F_211 ( V_189 ) ) ;
goto V_223;
}
F_201 ( V_189 , V_27 ) ;
if ( F_11 ( V_225 , & V_2 -> V_120 ) )
V_189 -> V_14 = F_212 () ;
V_207 = V_148 -> V_207 ;
if ( V_207 ) {
if ( ! V_205 )
F_213 ( V_2 ) ;
else {
if ( V_205 >= V_226 ) {
F_214 ( V_207 , false ) ;
F_213 ( V_2 ) ;
}
}
F_215 ( & V_189 -> V_12 , & V_207 -> V_211 ) ;
F_173 ( V_189 , true ) ;
} else {
F_24 ( V_2 -> V_49 ) ;
F_172 ( V_2 , V_189 , V_178 ) ;
F_25 ( V_2 ) ;
V_223:
F_26 ( V_2 -> V_49 ) ;
}
}
static inline void F_216 ( struct V_27 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_227 ;
if ( F_217 ( V_27 ) && V_9 != V_9 -> V_228 ) {
struct V_179 * V_229 = V_9 -> V_230 ;
V_27 -> V_35 . V_204 += V_229 -> V_231 ;
V_27 -> V_227 = V_9 -> V_228 ;
F_218 ( F_3 ( V_27 -> V_227 ) , V_27 ,
V_9 -> V_232 ,
V_27 -> V_35 . V_204 - V_229 -> V_231 ) ;
}
}
static void F_219 ( struct V_27 * V_27 )
{
char V_233 [ V_234 ] ;
F_17 ( V_40 L_10 ) ;
F_17 ( V_40 L_11 ,
F_220 ( V_27 -> V_227 , V_233 ) ,
V_27 -> V_144 ,
( unsigned long long ) F_221 ( V_27 ) ,
( long long ) ( F_222 ( V_27 -> V_227 -> V_235 ) >> 9 ) ) ;
F_13 ( V_236 , & V_27 -> V_30 ) ;
}
static int T_4 F_223 ( char * V_237 )
{
return F_224 ( & V_238 , V_237 ) ;
}
static bool F_225 ( struct V_179 * V_26 , unsigned int V_239 )
{
return V_26 -> V_240 && F_226 ( & V_238 , V_239 ) ;
}
static int T_4 F_227 ( void )
{
struct V_241 * V_242 = F_228 ( L_12 ,
NULL , & V_238 ) ;
return F_229 ( V_242 ) ;
}
static inline bool F_225 ( struct V_179 * V_26 ,
unsigned int V_239 )
{
return false ;
}
static inline int F_230 ( struct V_27 * V_27 , unsigned int V_243 )
{
V_16 V_244 ;
if ( ! V_243 )
return 0 ;
V_244 = F_222 ( V_27 -> V_227 -> V_235 ) >> 9 ;
if ( V_244 ) {
V_16 V_245 = V_27 -> V_35 . V_204 ;
if ( V_244 < V_243 || V_244 - V_243 < V_245 ) {
F_219 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_231 ( struct V_27 * V_27 )
{
struct V_1 * V_2 ;
int V_243 = F_217 ( V_27 ) ;
int V_102 = - V_31 ;
char V_233 [ V_234 ] ;
struct V_179 * V_26 ;
F_232 () ;
if ( F_230 ( V_27 , V_243 ) )
goto V_246;
V_2 = F_3 ( V_27 -> V_227 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_247
L_13
L_14 ,
F_220 ( V_27 -> V_227 , V_233 ) ,
( long long ) V_27 -> V_35 . V_204 ) ;
goto V_246;
}
if ( F_28 ( F_233 ( V_27 ) &&
V_243 > F_234 ( V_2 ) ) ) {
F_17 ( V_247 L_15 ,
F_220 ( V_27 -> V_227 , V_233 ) ,
F_217 ( V_27 ) ,
F_234 ( V_2 ) ) ;
goto V_246;
}
V_26 = V_27 -> V_227 -> V_230 ;
if ( F_225 ( V_26 , V_27 -> V_35 . V_36 ) ||
F_225 ( & F_179 ( V_26 ) -> V_186 ,
V_27 -> V_35 . V_36 ) )
goto V_246;
F_216 ( V_27 ) ;
if ( F_230 ( V_27 , V_243 ) )
goto V_246;
if ( ( V_27 -> V_144 & ( V_145 | V_146 ) ) && ! V_2 -> V_248 ) {
V_27 -> V_144 &= ~ ( V_145 | V_146 ) ;
if ( ! V_243 ) {
V_102 = 0 ;
goto V_246;
}
}
if ( ( V_27 -> V_144 & V_249 ) &&
( ! F_235 ( V_2 ) ||
( ( V_27 -> V_144 & V_250 ) && ! F_236 ( V_2 ) ) ) ) {
V_102 = - V_251 ;
goto V_246;
}
if ( V_27 -> V_144 & V_252 && ! F_237 ( V_27 -> V_227 ) ) {
V_102 = - V_251 ;
goto V_246;
}
F_155 ( V_253 , V_2 -> V_98 ) ;
if ( F_238 ( V_2 , V_27 ) )
return false ;
F_239 ( V_2 , V_27 ) ;
return true ;
V_246:
F_15 ( V_27 , V_102 ) ;
return false ;
}
void F_240 ( struct V_27 * V_27 )
{
struct V_254 V_255 ;
if ( ! F_231 ( V_27 ) )
return;
if ( V_148 -> V_254 ) {
F_241 ( V_148 -> V_254 , V_27 ) ;
return;
}
F_154 ( V_27 -> V_202 ) ;
F_242 ( & V_255 ) ;
V_148 -> V_254 = & V_255 ;
do {
struct V_1 * V_2 = F_3 ( V_27 -> V_227 ) ;
V_2 -> V_256 ( V_2 , V_27 ) ;
V_27 = F_243 ( V_148 -> V_254 ) ;
} while ( V_27 );
V_148 -> V_254 = NULL ;
}
void F_244 ( int V_171 , struct V_27 * V_27 )
{
V_27 -> V_144 |= V_171 ;
if ( F_245 ( V_27 ) ) {
unsigned int V_95 ;
if ( F_12 ( V_171 & V_252 ) )
V_95 = F_246 ( V_27 -> V_227 ) >> 9 ;
else
V_95 = F_217 ( V_27 ) ;
if ( V_171 & V_173 ) {
F_247 ( V_257 , V_95 ) ;
} else {
F_248 ( V_27 -> V_35 . V_36 ) ;
F_247 ( V_258 , V_95 ) ;
}
if ( F_12 ( V_259 ) ) {
char V_233 [ V_234 ] ;
F_17 ( V_260 L_16 ,
V_148 -> V_261 , F_249 ( V_148 ) ,
( V_171 & V_173 ) ? L_17 : L_18 ,
( unsigned long long ) V_27 -> V_35 . V_204 ,
F_220 ( V_27 -> V_227 , V_233 ) ,
V_95 ) ;
}
}
F_240 ( V_27 ) ;
}
int F_250 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( ! F_251 ( V_11 ) )
return 0 ;
if ( F_19 ( V_11 ) > F_252 ( V_2 , V_11 -> V_32 ) ) {
F_17 ( V_247 L_19 , V_166 ) ;
return - V_31 ;
}
F_253 ( V_11 ) ;
if ( V_11 -> V_199 > F_254 ( V_2 ) ) {
F_17 ( V_247 L_20 , V_166 ) ;
return - V_31 ;
}
return 0 ;
}
int F_255 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
unsigned long V_61 ;
int V_178 = V_262 ;
if ( F_250 ( V_2 , V_11 ) )
return - V_31 ;
if ( V_11 -> V_41 &&
F_225 ( & V_11 -> V_41 -> V_186 , F_21 ( V_11 ) ) )
return - V_31 ;
if ( V_2 -> V_54 ) {
if ( F_135 ( V_2 ) )
F_173 ( V_11 , true ) ;
F_256 ( V_11 , false , true , true ) ;
return 0 ;
}
F_48 ( V_2 -> V_49 , V_61 ) ;
if ( F_12 ( F_107 ( V_2 ) ) ) {
F_49 ( V_2 -> V_49 , V_61 ) ;
return - V_155 ;
}
F_154 ( F_170 ( V_11 ) ) ;
if ( V_11 -> V_32 & ( V_145 | V_146 ) )
V_178 = V_221 ;
F_172 ( V_2 , V_11 , V_178 ) ;
if ( V_178 == V_221 )
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return 0 ;
}
unsigned int F_257 ( const struct V_10 * V_11 )
{
unsigned int V_200 = V_11 -> V_32 & V_201 ;
unsigned int V_239 = 0 ;
struct V_27 * V_27 ;
if ( ! ( V_11 -> V_32 & V_263 ) )
return F_21 ( V_11 ) ;
for ( V_27 = V_11 -> V_27 ; V_27 ; V_27 = V_27 -> V_202 ) {
if ( ( V_27 -> V_144 & V_200 ) != V_200 )
break;
V_239 += V_27 -> V_35 . V_36 ;
}
F_154 ( F_21 ( V_11 ) && ! V_239 ) ;
return V_239 ;
}
void F_258 ( struct V_10 * V_189 , unsigned int V_239 )
{
if ( F_259 ( V_189 ) ) {
const int V_171 = F_260 ( V_189 ) ;
struct V_179 * V_26 ;
int V_14 ;
V_14 = F_261 () ;
V_26 = V_189 -> V_26 ;
F_262 ( V_14 , V_26 , V_264 [ V_171 ] , V_239 >> 9 ) ;
F_263 () ;
}
}
void F_264 ( struct V_10 * V_189 )
{
if ( F_259 ( V_189 ) && ! ( V_189 -> V_32 & V_37 ) ) {
unsigned long V_265 = V_25 - V_189 -> V_24 ;
const int V_171 = F_260 ( V_189 ) ;
struct V_179 * V_26 ;
int V_14 ;
V_14 = F_261 () ;
V_26 = V_189 -> V_26 ;
F_265 ( V_14 , V_26 , V_266 [ V_171 ] ) ;
F_262 ( V_14 , V_26 , V_267 [ V_171 ] , V_265 ) ;
F_178 ( V_14 , V_26 ) ;
F_266 ( V_26 , V_171 ) ;
F_267 ( V_26 ) ;
F_263 () ;
}
}
static struct V_10 * F_268 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( V_2 -> V_167 && ( V_2 -> V_268 == V_269 ||
( V_2 -> V_268 != V_270 && ! ( V_11 -> V_32 & V_187 ) ) ) )
return NULL ;
else
return V_11 ;
}
static inline struct V_10 * F_268 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
return V_11 ;
}
void F_173 ( struct V_10 * V_11 , bool V_271 )
{
struct V_179 * V_26 ;
int V_171 = F_260 ( V_11 ) ;
int V_14 ;
if ( ! F_259 ( V_11 ) )
return;
V_14 = F_261 () ;
if ( ! V_271 ) {
V_26 = V_11 -> V_26 ;
F_265 ( V_14 , V_26 , V_272 [ V_171 ] ) ;
} else {
V_26 = F_269 ( V_11 -> V_41 , F_18 ( V_11 ) ) ;
if ( ! F_270 ( V_26 ) ) {
V_26 = & V_11 -> V_41 -> V_186 ;
F_271 ( V_26 ) ;
}
F_178 ( V_14 , V_26 ) ;
F_272 ( V_26 , V_171 ) ;
V_11 -> V_26 = V_26 ;
}
F_263 () ;
}
struct V_10 * F_273 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_175 ;
while ( ( V_11 = F_274 ( V_2 ) ) != NULL ) {
V_11 = F_268 ( V_2 , V_11 ) ;
if ( ! V_11 )
break;
if ( ! ( V_11 -> V_32 & V_273 ) ) {
if ( V_11 -> V_32 & V_274 )
F_275 ( V_2 , V_11 ) ;
V_11 -> V_32 |= V_273 ;
F_276 ( V_2 , V_11 ) ;
}
if ( ! V_2 -> V_275 || V_2 -> V_275 == V_11 ) {
V_2 -> V_276 = F_277 ( V_11 ) ;
V_2 -> V_275 = NULL ;
}
if ( V_11 -> V_32 & V_277 )
break;
if ( V_2 -> V_278 && F_21 ( V_11 ) ) {
V_11 -> V_199 ++ ;
}
if ( ! V_2 -> V_128 )
break;
V_175 = V_2 -> V_128 ( V_2 , V_11 ) ;
if ( V_175 == V_279 ) {
break;
} else if ( V_175 == V_280 ) {
if ( V_2 -> V_278 && F_21 ( V_11 ) &&
! ( V_11 -> V_32 & V_277 ) ) {
-- V_11 -> V_199 ;
}
V_11 = NULL ;
break;
} else if ( V_175 == V_281 ) {
V_11 -> V_32 |= V_33 ;
F_278 ( V_11 ) ;
F_279 ( V_11 , - V_31 ) ;
} else {
F_17 ( V_247 L_21 , V_166 , V_175 ) ;
break;
}
}
return V_11 ;
}
void F_280 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_154 ( F_56 ( & V_11 -> V_12 ) ) ;
F_154 ( F_186 ( V_11 ) ) ;
F_281 ( & V_11 -> V_12 ) ;
if ( F_282 ( V_11 ) ) {
V_2 -> V_71 [ F_283 ( V_11 ) ] ++ ;
F_284 ( V_11 ) ;
}
}
void F_278 ( struct V_10 * V_189 )
{
F_280 ( V_189 ) ;
V_189 -> V_198 = F_21 ( V_189 ) ;
if ( F_12 ( F_285 ( V_189 ) ) )
V_189 -> V_282 -> V_198 = F_21 ( V_189 -> V_282 ) ;
F_154 ( F_11 ( V_283 , & V_189 -> V_284 ) ) ;
F_286 ( V_189 ) ;
}
struct V_10 * F_287 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_273 ( V_2 ) ;
if ( V_11 )
F_278 ( V_11 ) ;
return V_11 ;
}
bool F_288 ( struct V_10 * V_189 , int error , unsigned int V_285 )
{
int V_286 ;
F_289 ( V_189 -> V_2 , V_189 , V_285 ) ;
if ( ! V_189 -> V_27 )
return false ;
if ( V_189 -> V_43 == V_215 )
V_189 -> V_218 = 0 ;
if ( error && V_189 -> V_43 == V_215 &&
! ( V_189 -> V_32 & V_33 ) ) {
char * V_287 ;
switch ( error ) {
case - V_288 :
V_287 = L_22 ;
break;
case - V_289 :
V_287 = L_23 ;
break;
case - V_290 :
V_287 = L_24 ;
break;
case - V_291 :
V_287 = L_25 ;
break;
case - V_292 :
V_287 = L_26 ;
break;
case - V_293 :
V_287 = L_27 ;
break;
case - V_31 :
default:
V_287 = L_28 ;
break;
}
F_142 ( V_247 L_29 ,
V_166 , V_287 , V_189 -> V_41 ?
V_189 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_18 ( V_189 ) ) ;
}
F_258 ( V_189 , V_285 ) ;
V_286 = 0 ;
while ( V_189 -> V_27 ) {
struct V_27 * V_27 = V_189 -> V_27 ;
unsigned V_294 = F_290 ( V_27 -> V_35 . V_36 , V_285 ) ;
if ( V_294 == V_27 -> V_35 . V_36 )
V_189 -> V_27 = V_27 -> V_202 ;
F_9 ( V_189 , V_27 , V_294 , error ) ;
V_286 += V_294 ;
V_285 -= V_294 ;
if ( ! V_285 )
break;
}
if ( ! V_189 -> V_27 ) {
V_189 -> V_176 = 0 ;
return false ;
}
V_189 -> V_176 -= V_286 ;
if ( V_189 -> V_43 == V_215 )
V_189 -> V_15 += V_286 >> 9 ;
if ( V_189 -> V_32 & V_263 ) {
V_189 -> V_32 &= ~ V_201 ;
V_189 -> V_32 |= V_189 -> V_27 -> V_144 & V_201 ;
}
if ( F_21 ( V_189 ) < F_291 ( V_189 ) ) {
F_16 ( V_189 , L_30 ) ;
V_189 -> V_176 = F_291 ( V_189 ) ;
}
F_253 ( V_189 ) ;
return true ;
}
static bool F_292 ( struct V_10 * V_11 , int error ,
unsigned int V_285 ,
unsigned int V_295 )
{
if ( F_288 ( V_11 , error , V_285 ) )
return true ;
if ( F_12 ( F_285 ( V_11 ) ) &&
F_288 ( V_11 -> V_282 , error , V_295 ) )
return true ;
if ( F_293 ( V_11 -> V_2 ) )
F_294 ( V_11 -> V_41 ) ;
return false ;
}
void F_295 ( struct V_10 * V_189 )
{
struct V_1 * V_2 = V_189 -> V_2 ;
V_189 -> V_32 &= ~ V_277 ;
if ( V_2 -> V_129 )
V_2 -> V_129 ( V_2 , V_189 ) ;
}
void F_296 ( struct V_10 * V_189 , int error )
{
if ( V_189 -> V_32 & V_177 )
F_169 ( V_189 -> V_2 , V_189 ) ;
F_154 ( F_170 ( V_189 ) ) ;
if ( F_12 ( V_296 ) && V_189 -> V_43 == V_215 )
F_297 ( & V_189 -> V_2 -> V_7 ) ;
F_166 ( V_189 ) ;
if ( V_189 -> V_32 & V_277 )
F_295 ( V_189 ) ;
F_264 ( V_189 ) ;
if ( V_189 -> V_246 )
V_189 -> V_246 ( V_189 , error ) ;
else {
if ( F_285 ( V_189 ) )
F_182 ( V_189 -> V_282 -> V_2 , V_189 -> V_282 ) ;
F_182 ( V_189 -> V_2 , V_189 ) ;
}
}
static bool F_298 ( struct V_10 * V_11 , int error ,
unsigned int V_285 , unsigned int V_295 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_61 ;
if ( F_292 ( V_11 , error , V_285 , V_295 ) )
return true ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_296 ( V_11 , error ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return false ;
}
bool F_299 ( struct V_10 * V_11 , int error ,
unsigned int V_285 , unsigned int V_295 )
{
if ( F_292 ( V_11 , error , V_285 , V_295 ) )
return true ;
F_296 ( V_11 , error ) ;
return false ;
}
bool F_300 ( struct V_10 * V_11 , int error , unsigned int V_285 )
{
return F_298 ( V_11 , error , V_285 , 0 ) ;
}
void F_301 ( struct V_10 * V_11 , int error )
{
bool V_297 ;
unsigned int V_295 = 0 ;
if ( F_12 ( F_285 ( V_11 ) ) )
V_295 = F_21 ( V_11 -> V_282 ) ;
V_297 = F_298 ( V_11 , error , F_21 ( V_11 ) , V_295 ) ;
F_154 ( V_297 ) ;
}
bool F_302 ( struct V_10 * V_11 , int error )
{
return F_300 ( V_11 , error , F_291 ( V_11 ) ) ;
}
bool F_303 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_300 ( V_11 , error , F_257 ( V_11 ) ) ;
}
bool F_304 ( struct V_10 * V_11 , int error , unsigned int V_285 )
{
return F_299 ( V_11 , error , V_285 , 0 ) ;
}
void F_279 ( struct V_10 * V_11 , int error )
{
bool V_297 ;
unsigned int V_295 = 0 ;
if ( F_12 ( F_285 ( V_11 ) ) )
V_295 = F_21 ( V_11 -> V_282 ) ;
V_297 = F_299 ( V_11 , error , F_21 ( V_11 ) , V_295 ) ;
F_154 ( V_297 ) ;
}
bool F_305 ( struct V_10 * V_11 , int error )
{
return F_304 ( V_11 , error , F_291 ( V_11 ) ) ;
}
bool F_306 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_304 ( V_11 , error , F_257 ( V_11 ) ) ;
}
void F_202 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_27 * V_27 )
{
V_11 -> V_32 |= V_27 -> V_144 & V_298 ;
if ( F_245 ( V_27 ) )
V_11 -> V_199 = F_307 ( V_2 , V_27 ) ;
V_11 -> V_176 = V_27 -> V_35 . V_36 ;
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
if ( V_27 -> V_227 )
V_11 -> V_41 = V_27 -> V_227 -> V_299 ;
}
void F_308 ( struct V_10 * V_11 )
{
struct V_300 V_301 ;
struct V_302 V_303 ;
F_309 (bvec, rq, iter)
F_310 ( V_303 . V_193 ) ;
}
int F_311 ( struct V_1 * V_2 )
{
if ( V_2 -> V_304 )
return V_2 -> V_304 ( V_2 ) ;
return 0 ;
}
void F_312 ( struct V_10 * V_11 )
{
struct V_27 * V_27 ;
while ( ( V_27 = V_11 -> V_27 ) != NULL ) {
V_11 -> V_27 = V_27 -> V_202 ;
F_313 ( V_27 ) ;
}
}
static void F_314 ( struct V_10 * V_305 , struct V_10 * V_306 )
{
V_305 -> V_14 = V_306 -> V_14 ;
V_305 -> V_32 |= ( V_306 -> V_32 & V_307 ) | V_308 ;
V_305 -> V_43 = V_306 -> V_43 ;
V_305 -> V_15 = F_18 ( V_306 ) ;
V_305 -> V_176 = F_21 ( V_306 ) ;
V_305 -> V_199 = V_306 -> V_199 ;
V_305 -> V_203 = V_306 -> V_203 ;
V_305 -> V_309 = V_306 -> V_309 ;
}
int F_315 ( struct V_10 * V_11 , struct V_10 * V_310 ,
struct V_311 * V_312 , T_2 V_89 ,
int (* F_316)( struct V_27 * , struct V_27 * , void * ) ,
void * V_90 )
{
struct V_27 * V_27 , * V_313 ;
if ( ! V_312 )
V_312 = V_314 ;
F_317 (bio_src, rq_src) {
V_27 = F_318 ( V_313 , V_89 , V_312 ) ;
if ( ! V_27 )
goto V_315;
if ( F_316 && F_316 ( V_27 , V_313 , V_90 ) )
goto V_315;
if ( V_11 -> V_27 ) {
V_11 -> V_44 -> V_202 = V_27 ;
V_11 -> V_44 = V_27 ;
} else
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
}
F_314 ( V_11 , V_310 ) ;
return 0 ;
V_315:
if ( V_27 )
F_313 ( V_27 ) ;
F_312 ( V_11 ) ;
return - V_99 ;
}
int F_319 ( struct V_46 * V_47 )
{
return F_320 ( V_51 , V_47 ) ;
}
int F_321 ( struct V_316 * V_317 ,
unsigned long V_318 )
{
return F_30 ( V_51 , V_317 , V_318 ) ;
}
int F_322 ( int V_14 , struct V_316 * V_317 ,
unsigned long V_318 )
{
return F_323 ( V_14 , V_51 , V_317 , V_318 ) ;
}
void F_324 ( struct V_206 * V_207 )
{
struct V_319 * V_320 = V_148 ;
F_5 ( & V_207 -> V_211 ) ;
F_5 ( & V_207 -> V_210 ) ;
F_5 ( & V_207 -> V_321 ) ;
if ( ! V_320 -> V_207 ) {
V_320 -> V_207 = V_207 ;
}
}
static int F_325 ( void * V_322 , struct V_208 * V_323 , struct V_208 * V_233 )
{
struct V_10 * V_324 = F_23 ( V_323 , struct V_10 , V_12 ) ;
struct V_10 * V_325 = F_23 ( V_233 , struct V_10 , V_12 ) ;
return ! ( V_324 -> V_2 < V_325 -> V_2 ||
( V_324 -> V_2 == V_325 -> V_2 && F_18 ( V_324 ) < F_18 ( V_325 ) ) ) ;
}
static void F_326 ( struct V_1 * V_2 , unsigned int V_326 ,
bool V_327 )
__releases( V_2 -> V_49 )
{
F_327 ( V_2 , V_326 , ! V_327 ) ;
if ( V_327 )
F_45 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_328 ( V_2 -> V_49 ) ;
}
static void F_329 ( struct V_206 * V_207 , bool V_327 )
{
F_330 ( V_328 ) ;
while ( ! F_56 ( & V_207 -> V_321 ) ) {
F_331 ( & V_207 -> V_321 , & V_328 ) ;
while ( ! F_56 ( & V_328 ) ) {
struct V_329 * V_330 = F_332 ( & V_328 ,
struct V_329 ,
V_211 ) ;
F_333 ( & V_330 -> V_211 ) ;
V_330 -> V_331 ( V_330 , V_327 ) ;
}
}
}
struct V_329 * F_334 ( T_6 V_332 , void * V_90 ,
int V_333 )
{
struct V_206 * V_207 = V_148 -> V_207 ;
struct V_329 * V_330 ;
if ( ! V_207 )
return NULL ;
F_335 (cb, &plug->cb_list, list)
if ( V_330 -> V_331 == V_332 && V_330 -> V_90 == V_90 )
return V_330 ;
F_154 ( V_333 < sizeof( * V_330 ) ) ;
V_330 = F_336 ( V_333 , V_253 ) ;
if ( V_330 ) {
V_330 -> V_90 = V_90 ;
V_330 -> V_331 = V_332 ;
F_337 ( & V_330 -> V_211 , & V_207 -> V_321 ) ;
}
return V_330 ;
}
void F_214 ( struct V_206 * V_207 , bool V_327 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
struct V_10 * V_11 ;
F_330 ( V_211 ) ;
unsigned int V_326 ;
F_329 ( V_207 , V_327 ) ;
if ( ! F_56 ( & V_207 -> V_210 ) )
F_338 ( V_207 , V_327 ) ;
if ( F_56 ( & V_207 -> V_211 ) )
return;
F_331 ( & V_207 -> V_211 , & V_211 ) ;
F_339 ( NULL , & V_211 , F_325 ) ;
V_2 = NULL ;
V_326 = 0 ;
F_340 ( V_61 ) ;
while ( ! F_56 ( & V_211 ) ) {
V_11 = F_341 ( V_211 . V_334 ) ;
F_281 ( & V_11 -> V_12 ) ;
F_154 ( ! V_11 -> V_2 ) ;
if ( V_11 -> V_2 != V_2 ) {
if ( V_2 )
F_326 ( V_2 , V_326 , V_327 ) ;
V_2 = V_11 -> V_2 ;
V_326 = 0 ;
F_342 ( V_2 -> V_49 ) ;
}
if ( F_12 ( F_107 ( V_2 ) ) ) {
F_279 ( V_11 , - V_155 ) ;
continue;
}
if ( V_11 -> V_32 & ( V_145 | V_146 ) )
F_174 ( V_2 , V_11 , V_221 ) ;
else
F_174 ( V_2 , V_11 , V_335 ) ;
V_326 ++ ;
}
if ( V_2 )
F_326 ( V_2 , V_326 , V_327 ) ;
F_343 ( V_61 ) ;
}
void F_344 ( struct V_206 * V_207 )
{
F_214 ( V_207 , false ) ;
if ( V_207 == V_148 -> V_207 )
V_148 -> V_207 = NULL ;
}
void F_345 ( struct V_1 * V_2 , struct V_336 * V_167 )
{
V_2 -> V_167 = V_167 ;
V_2 -> V_268 = V_270 ;
F_346 ( V_2 -> V_167 , - 1 ) ;
F_347 ( V_2 -> V_167 ) ;
}
int F_348 ( struct V_1 * V_2 )
{
int V_175 = 0 ;
F_24 ( V_2 -> V_49 ) ;
if ( V_2 -> V_188 ) {
V_175 = - V_337 ;
F_181 ( V_2 -> V_167 ) ;
} else {
V_2 -> V_268 = V_338 ;
}
F_26 ( V_2 -> V_49 ) ;
return V_175 ;
}
void F_349 ( struct V_1 * V_2 , int V_102 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_102 ) {
V_2 -> V_268 = V_269 ;
} else {
V_2 -> V_268 = V_270 ;
F_181 ( V_2 -> V_167 ) ;
}
F_26 ( V_2 -> V_49 ) ;
}
void F_350 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_268 = V_339 ;
F_26 ( V_2 -> V_49 ) ;
}
void F_351 ( struct V_1 * V_2 , int V_102 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_102 ) {
V_2 -> V_268 = V_270 ;
F_25 ( V_2 ) ;
F_181 ( V_2 -> V_167 ) ;
F_352 ( V_2 -> V_167 ) ;
} else {
V_2 -> V_268 = V_269 ;
}
F_26 ( V_2 -> V_49 ) ;
}
int T_4 F_353 ( void )
{
F_354 ( V_340 > 8 *
sizeof( ( (struct V_10 * ) 0 ) -> V_32 ) ) ;
V_51 = F_355 ( L_31 ,
V_341 | V_342 , 0 ) ;
if ( ! V_51 )
F_356 ( L_32 ) ;
V_92 = F_357 ( L_33 ,
sizeof( struct V_10 ) , 0 , V_343 , NULL ) ;
V_103 = F_357 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_343 , NULL ) ;
return 0 ;
}
