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
F_50 ( V_2 ) ;
}
int F_76 ( struct V_73 * V_74 , struct V_1 * V_2 ,
T_2 V_89 )
{
if ( F_12 ( V_74 -> V_79 ) )
return 0 ;
V_74 -> V_2 = V_2 ;
V_74 -> V_90 [ V_80 ] = V_74 -> V_90 [ V_81 ] = 0 ;
V_74 -> V_91 [ V_80 ] = V_74 -> V_91 [ V_81 ] = 0 ;
F_77 ( & V_74 -> V_75 [ V_80 ] ) ;
F_77 ( & V_74 -> V_75 [ V_81 ] ) ;
V_74 -> V_79 = F_78 ( V_92 , V_93 ,
V_94 , V_95 ,
V_89 , V_2 -> V_96 ) ;
if ( ! V_74 -> V_79 )
return - V_97 ;
return 0 ;
}
void F_79 ( struct V_73 * V_74 )
{
if ( V_74 -> V_79 )
F_80 ( V_74 -> V_79 ) ;
}
struct V_1 * F_81 ( T_2 V_89 )
{
return F_82 ( V_89 , V_98 ) ;
}
struct V_1 * F_82 ( T_2 V_89 , int V_99 )
{
struct V_1 * V_2 ;
int V_100 ;
V_2 = F_83 ( V_101 ,
V_89 | V_102 , V_99 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_103 = F_84 ( & V_104 , 0 , 0 , V_89 ) ;
if ( V_2 -> V_103 < 0 )
goto V_105;
V_2 -> V_7 . V_106 =
( V_107 * 1024 ) / V_108 ;
V_2 -> V_7 . V_109 = 0 ;
V_2 -> V_7 . V_110 = V_111 ;
V_2 -> V_7 . V_112 = L_8 ;
V_2 -> V_96 = V_99 ;
V_100 = F_85 ( & V_2 -> V_7 ) ;
if ( V_100 )
goto V_113;
F_86 ( & V_2 -> V_7 . V_87 ,
V_114 , ( unsigned long ) V_2 ) ;
F_86 ( & V_2 -> V_53 , V_115 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_66 ) ;
F_5 ( & V_2 -> V_13 ) ;
F_5 ( & V_2 -> V_116 ) ;
#ifdef F_87
F_5 ( & V_2 -> V_117 ) ;
#endif
F_88 ( & V_2 -> V_48 , F_22 ) ;
F_89 ( & V_2 -> V_62 , & V_118 ) ;
F_90 ( & V_2 -> V_83 ) ;
F_91 ( & V_2 -> V_88 ) ;
V_2 -> V_49 = & V_2 -> V_88 ;
V_2 -> V_76 = 1 ;
F_92 ( V_77 , & V_2 -> V_119 ) ;
F_77 ( & V_2 -> V_120 ) ;
if ( F_93 ( V_2 ) )
goto V_121;
return V_2 ;
V_121:
F_94 ( & V_2 -> V_7 ) ;
V_113:
F_95 ( & V_104 , V_2 -> V_103 ) ;
V_105:
F_96 ( V_101 , V_2 ) ;
return NULL ;
}
struct V_1 * F_97 ( T_3 * V_122 , T_1 * V_82 )
{
return F_98 ( V_122 , V_82 , V_98 ) ;
}
struct V_1 *
F_98 ( T_3 * V_122 , T_1 * V_82 , int V_99 )
{
struct V_1 * V_123 , * V_2 ;
V_123 = F_82 ( V_124 , V_99 ) ;
if ( ! V_123 )
return NULL ;
V_2 = F_99 ( V_123 , V_122 , V_82 ) ;
if ( ! V_2 )
F_71 ( V_123 ) ;
return V_2 ;
}
struct V_1 *
F_99 ( struct V_1 * V_2 , T_3 * V_122 ,
T_1 * V_82 )
{
if ( ! V_2 )
return NULL ;
V_2 -> V_69 = F_100 ( V_2 , V_98 , 0 ) ;
if ( ! V_2 -> V_69 )
return NULL ;
if ( F_76 ( & V_2 -> V_125 , V_2 , V_124 ) )
goto V_126;
V_2 -> V_60 = V_122 ;
V_2 -> V_127 = NULL ;
V_2 -> V_128 = NULL ;
V_2 -> V_119 |= V_129 ;
if ( V_82 )
V_2 -> V_49 = V_82 ;
F_101 ( V_2 , V_130 ) ;
V_2 -> V_131 = V_132 ;
F_72 ( & V_2 -> V_83 ) ;
if ( F_102 ( V_2 , NULL ) ) {
F_73 ( & V_2 -> V_83 ) ;
goto V_126;
}
F_73 ( & V_2 -> V_83 ) ;
return V_2 ;
V_126:
F_103 ( V_2 -> V_69 ) ;
return NULL ;
}
bool F_104 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_105 ( V_2 ) ) ) {
F_106 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_107 ( struct V_73 * V_74 , struct V_10 * V_11 )
{
if ( V_11 -> V_32 & V_133 ) {
F_108 ( V_74 -> V_2 , V_11 ) ;
if ( V_11 -> V_134 . V_135 )
F_109 ( V_11 -> V_134 . V_135 -> V_136 ) ;
}
F_110 ( V_11 , V_74 -> V_79 ) ;
}
static inline int F_111 ( struct V_1 * V_2 , struct V_137 * V_136 )
{
if ( ! V_136 )
return 0 ;
return V_136 -> V_138 == V_2 -> V_139 ||
( V_136 -> V_138 > 0
&& F_112 ( V_25 , V_136 -> V_140 + V_141 ) ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_137 * V_136 )
{
if ( ! V_136 || F_111 ( V_2 , V_136 ) )
return;
V_136 -> V_138 = V_2 -> V_139 ;
V_136 -> V_140 = V_25 ;
}
static void F_114 ( struct V_73 * V_74 , int V_142 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
if ( V_74 == & V_2 -> V_125 &&
V_74 -> V_90 [ V_142 ] < F_115 ( V_2 ) )
F_116 ( V_2 , V_142 ) ;
if ( V_74 -> V_90 [ V_142 ] + 1 <= V_2 -> V_4 ) {
if ( F_117 ( & V_74 -> V_75 [ V_142 ] ) )
F_70 ( & V_74 -> V_75 [ V_142 ] ) ;
F_118 ( V_74 , V_142 ) ;
}
}
static void F_119 ( struct V_73 * V_74 , unsigned int V_61 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_142 = F_120 ( V_61 ) ;
V_2 -> V_70 [ V_142 ] -- ;
V_74 -> V_90 [ V_142 ] -- ;
if ( V_61 & V_133 )
V_2 -> V_67 -- ;
F_114 ( V_74 , V_142 ) ;
if ( F_12 ( V_74 -> V_91 [ V_142 ^ 1 ] ) )
F_114 ( V_74 , V_142 ^ 1 ) ;
}
int F_121 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_73 * V_74 ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_4 = V_3 ;
F_1 ( V_2 ) ;
V_74 = & V_2 -> V_125 ;
if ( V_74 -> V_90 [ V_80 ] >= F_122 ( V_2 ) )
F_123 ( V_2 , V_80 ) ;
else if ( V_74 -> V_90 [ V_80 ] < F_115 ( V_2 ) )
F_116 ( V_2 , V_80 ) ;
if ( V_74 -> V_90 [ V_81 ] >= F_122 ( V_2 ) )
F_123 ( V_2 , V_81 ) ;
else if ( V_74 -> V_90 [ V_81 ] < F_115 ( V_2 ) )
F_116 ( V_2 , V_81 ) ;
F_59 (rl, q) {
if ( V_74 -> V_90 [ V_80 ] >= V_2 -> V_4 ) {
F_124 ( V_74 , V_80 ) ;
} else {
F_118 ( V_74 , V_80 ) ;
F_70 ( & V_74 -> V_75 [ V_80 ] ) ;
}
if ( V_74 -> V_90 [ V_81 ] >= V_2 -> V_4 ) {
F_124 ( V_74 , V_81 ) ;
} else {
F_118 ( V_74 , V_81 ) ;
F_70 ( & V_74 -> V_75 [ V_81 ] ) ;
}
}
F_26 ( V_2 -> V_49 ) ;
return 0 ;
}
static bool F_125 ( struct V_27 * V_27 )
{
if ( ! V_27 )
return true ;
if ( V_27 -> V_143 & ( V_144 | V_145 ) )
return false ;
return true ;
}
static struct V_137 * F_126 ( struct V_27 * V_27 )
{
#ifdef F_87
if ( V_27 && V_27 -> V_146 )
return V_27 -> V_146 ;
#endif
return V_147 -> V_137 ;
}
static struct V_10 * F_127 ( struct V_73 * V_74 , int V_148 ,
struct V_27 * V_27 , T_2 V_89 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_10 * V_11 ;
struct V_149 * V_150 = V_2 -> V_65 -> type ;
struct V_137 * V_136 = F_126 ( V_27 ) ;
struct V_151 * V_135 = NULL ;
const bool V_152 = F_120 ( V_148 ) != 0 ;
int V_153 ;
if ( F_12 ( F_105 ( V_2 ) ) )
return F_128 ( - V_154 ) ;
V_153 = F_129 ( V_2 , V_148 ) ;
if ( V_153 == V_155 )
goto V_156;
if ( V_74 -> V_90 [ V_152 ] + 1 >= F_122 ( V_2 ) ) {
if ( V_74 -> V_90 [ V_152 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_130 ( V_74 , V_152 ) ) {
F_113 ( V_2 , V_136 ) ;
F_124 ( V_74 , V_152 ) ;
} else {
if ( V_153 != V_157
&& ! F_111 ( V_2 , V_136 ) ) {
return F_128 ( - V_97 ) ;
}
}
}
if ( V_74 == & V_2 -> V_125 )
F_123 ( V_2 , V_152 ) ;
}
if ( V_74 -> V_90 [ V_152 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return F_128 ( - V_97 ) ;
V_2 -> V_70 [ V_152 ] ++ ;
V_74 -> V_90 [ V_152 ] ++ ;
V_74 -> V_91 [ V_152 ] = 0 ;
if ( F_125 ( V_27 ) && ! F_131 ( V_2 ) ) {
V_148 |= V_133 ;
V_2 -> V_67 ++ ;
if ( V_150 -> V_158 && V_136 )
V_135 = F_132 ( V_136 , V_2 ) ;
}
if ( F_133 ( V_2 ) )
V_148 |= V_159 ;
F_26 ( V_2 -> V_49 ) ;
V_11 = F_134 ( V_74 -> V_79 , V_89 ) ;
if ( ! V_11 )
goto V_160;
F_4 ( V_2 , V_11 ) ;
F_135 ( V_11 , V_74 ) ;
V_11 -> V_32 = V_148 | V_161 ;
if ( V_148 & V_133 ) {
if ( F_12 ( V_150 -> V_158 && ! V_135 ) ) {
if ( V_136 )
V_135 = F_136 ( V_136 , V_2 , V_89 ) ;
if ( ! V_135 )
goto V_162;
}
V_11 -> V_134 . V_135 = V_135 ;
if ( F_12 ( F_137 ( V_2 , V_11 , V_27 , V_89 ) ) )
goto V_162;
if ( V_135 )
F_138 ( V_135 -> V_136 ) ;
}
V_163:
if ( F_111 ( V_2 , V_136 ) )
V_136 -> V_138 -- ;
F_139 ( V_2 , V_27 , V_148 & 1 ) ;
return V_11 ;
V_162:
F_140 ( V_164 L_9 ,
V_165 , F_141 ( V_2 -> V_7 . V_166 ) ) ;
V_11 -> V_32 &= ~ V_133 ;
V_11 -> V_134 . V_135 = NULL ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_67 -- ;
F_26 ( V_2 -> V_49 ) ;
goto V_163;
V_160:
F_24 ( V_2 -> V_49 ) ;
F_119 ( V_74 , V_148 ) ;
V_156:
if ( F_12 ( V_74 -> V_90 [ V_152 ] == 0 ) )
V_74 -> V_91 [ V_152 ] = 1 ;
return F_128 ( - V_97 ) ;
}
static struct V_10 * F_142 ( struct V_1 * V_2 , int V_148 ,
struct V_27 * V_27 , T_2 V_89 )
{
const bool V_152 = F_120 ( V_148 ) != 0 ;
F_143 ( V_75 ) ;
struct V_73 * V_74 ;
struct V_10 * V_11 ;
V_74 = F_144 ( V_2 , V_27 ) ;
V_167:
V_11 = F_127 ( V_74 , V_148 , V_27 , V_89 ) ;
if ( ! F_145 ( V_11 ) )
return V_11 ;
if ( ! ( V_89 & V_168 ) || F_12 ( F_105 ( V_2 ) ) ) {
F_146 ( V_74 ) ;
return V_11 ;
}
F_147 ( & V_74 -> V_75 [ V_152 ] , & V_75 ,
V_169 ) ;
F_148 ( V_2 , V_27 , V_148 & 1 ) ;
F_26 ( V_2 -> V_49 ) ;
F_149 () ;
F_113 ( V_2 , V_147 -> V_137 ) ;
F_24 ( V_2 -> V_49 ) ;
F_150 ( & V_74 -> V_75 [ V_152 ] , & V_75 ) ;
goto V_167;
}
static struct V_10 * F_151 ( struct V_1 * V_2 , int V_170 ,
T_2 V_89 )
{
struct V_10 * V_11 ;
F_152 ( V_170 != V_171 && V_170 != V_172 ) ;
F_153 ( V_89 , V_2 -> V_96 ) ;
F_24 ( V_2 -> V_49 ) ;
V_11 = F_142 ( V_2 , V_170 , NULL , V_89 ) ;
if ( F_145 ( V_11 ) )
F_26 ( V_2 -> V_49 ) ;
return V_11 ;
}
struct V_10 * F_154 ( struct V_1 * V_2 , int V_170 , T_2 V_89 )
{
if ( V_2 -> V_54 )
return F_155 ( V_2 , V_170 , V_89 , false ) ;
else
return F_151 ( V_2 , V_170 , V_89 ) ;
}
struct V_10 * F_156 ( struct V_1 * V_2 , struct V_27 * V_27 ,
T_2 V_89 )
{
struct V_10 * V_11 = F_154 ( V_2 , F_157 ( V_27 ) , V_89 ) ;
if ( F_145 ( V_11 ) )
return V_11 ;
F_158 ( V_11 ) ;
F_159 (bio) {
struct V_27 * V_173 = V_27 ;
int V_174 ;
F_160 ( V_2 , & V_173 ) ;
V_174 = F_161 ( V_2 , V_11 , V_173 ) ;
if ( F_12 ( V_174 ) ) {
F_162 ( V_11 ) ;
return F_128 ( V_174 ) ;
}
}
return V_11 ;
}
void F_158 ( struct V_10 * V_11 )
{
V_11 -> V_43 = V_45 ;
V_11 -> V_175 = 0 ;
V_11 -> V_15 = ( V_16 ) - 1 ;
V_11 -> V_27 = V_11 -> V_44 = NULL ;
memset ( V_11 -> V_20 , 0 , sizeof( V_11 -> V_20 ) ) ;
}
void F_163 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_164 ( V_11 ) ;
F_165 ( V_11 ) ;
F_166 ( V_2 , V_11 ) ;
if ( V_11 -> V_32 & V_176 )
F_167 ( V_2 , V_11 ) ;
F_152 ( F_168 ( V_11 ) ) ;
F_169 ( V_2 , V_11 ) ;
}
static void F_170 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_177 )
{
F_171 ( V_11 , true ) ;
F_172 ( V_2 , V_11 , V_177 ) ;
}
static void F_173 ( int V_14 , struct V_178 * V_26 ,
unsigned long V_179 )
{
int V_180 ;
if ( V_179 == V_26 -> V_181 )
return;
V_180 = F_174 ( V_26 ) ;
if ( V_180 ) {
F_175 ( V_14 , V_26 , V_182 ,
V_180 * ( V_179 - V_26 -> V_181 ) ) ;
F_175 ( V_14 , V_26 , V_183 , ( V_179 - V_26 -> V_181 ) ) ;
}
V_26 -> V_181 = V_179 ;
}
void F_176 ( int V_14 , struct V_178 * V_26 )
{
unsigned long V_179 = V_25 ;
if ( V_26 -> V_184 )
F_173 ( V_14 , & F_177 ( V_26 ) -> V_185 , V_179 ) ;
F_173 ( V_14 , V_26 , V_179 ) ;
}
static void F_178 ( struct V_10 * V_11 )
{
if ( V_11 -> V_2 -> V_166 && ! ( V_11 -> V_32 & V_186 ) && ! -- V_11 -> V_2 -> V_187 )
F_179 ( V_11 -> V_2 -> V_166 ) ;
}
static inline void F_178 ( struct V_10 * V_11 ) {}
void F_180 ( struct V_1 * V_2 , struct V_10 * V_188 )
{
if ( F_12 ( ! V_2 ) )
return;
if ( V_2 -> V_54 ) {
F_181 ( V_188 ) ;
return;
}
F_178 ( V_188 ) ;
F_182 ( V_2 , V_188 ) ;
F_33 ( V_188 -> V_27 != NULL ) ;
if ( V_188 -> V_32 & V_161 ) {
unsigned int V_61 = V_188 -> V_32 ;
struct V_73 * V_74 = F_183 ( V_188 ) ;
F_152 ( ! F_56 ( & V_188 -> V_12 ) ) ;
F_152 ( F_184 ( V_188 ) ) ;
F_107 ( V_74 , V_188 ) ;
F_119 ( V_74 , V_61 ) ;
F_146 ( V_74 ) ;
}
}
void F_162 ( struct V_10 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_2 ;
if ( V_2 -> V_54 )
F_181 ( V_188 ) ;
else {
unsigned long V_61 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_180 ( V_2 , V_188 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
}
}
void F_185 ( struct V_10 * V_11 , struct V_189 * V_189 ,
unsigned int V_190 )
{
struct V_27 * V_27 = V_11 -> V_27 ;
V_27 -> V_191 -> V_192 = V_189 ;
V_27 -> V_191 -> V_193 = 0 ;
V_27 -> V_191 -> V_194 = V_190 ;
V_27 -> V_35 . V_36 = V_190 ;
V_27 -> V_195 = 1 ;
V_27 -> V_196 = 1 ;
V_11 -> V_175 = V_11 -> V_197 = V_190 ;
V_11 -> V_198 = 1 ;
}
bool F_186 ( struct V_1 * V_2 , struct V_10 * V_188 ,
struct V_27 * V_27 )
{
const int V_199 = V_27 -> V_143 & V_200 ;
if ( ! F_187 ( V_2 , V_188 , V_27 ) )
return false ;
F_188 ( V_2 , V_188 , V_27 ) ;
if ( ( V_188 -> V_32 & V_200 ) != V_199 )
F_189 ( V_188 ) ;
V_188 -> V_44 -> V_201 = V_27 ;
V_188 -> V_44 = V_27 ;
V_188 -> V_175 += V_27 -> V_35 . V_36 ;
V_188 -> V_202 = F_190 ( V_188 -> V_202 , F_191 ( V_27 ) ) ;
F_171 ( V_188 , false ) ;
return true ;
}
bool F_192 ( struct V_1 * V_2 , struct V_10 * V_188 ,
struct V_27 * V_27 )
{
const int V_199 = V_27 -> V_143 & V_200 ;
if ( ! F_193 ( V_2 , V_188 , V_27 ) )
return false ;
F_194 ( V_2 , V_188 , V_27 ) ;
if ( ( V_188 -> V_32 & V_200 ) != V_199 )
F_189 ( V_188 ) ;
V_27 -> V_201 = V_188 -> V_27 ;
V_188 -> V_27 = V_27 ;
V_188 -> V_15 = V_27 -> V_35 . V_203 ;
V_188 -> V_175 += V_27 -> V_35 . V_36 ;
V_188 -> V_202 = F_190 ( V_188 -> V_202 , F_191 ( V_27 ) ) ;
F_171 ( V_188 , false ) ;
return true ;
}
bool F_195 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned int * V_204 )
{
struct V_205 * V_206 ;
struct V_10 * V_11 ;
bool V_174 = false ;
struct V_207 * V_208 ;
V_206 = V_147 -> V_206 ;
if ( ! V_206 )
goto V_163;
* V_204 = 0 ;
if ( V_2 -> V_54 )
V_208 = & V_206 -> V_209 ;
else
V_208 = & V_206 -> V_210 ;
F_196 (rq, plug_list, queuelist) {
int V_211 ;
if ( V_11 -> V_2 == V_2 )
( * V_204 ) ++ ;
if ( V_11 -> V_2 != V_2 || ! F_197 ( V_11 , V_27 ) )
continue;
V_211 = F_198 ( V_11 , V_27 ) ;
if ( V_211 == V_212 ) {
V_174 = F_186 ( V_2 , V_11 , V_27 ) ;
if ( V_174 )
break;
} else if ( V_211 == V_213 ) {
V_174 = F_192 ( V_2 , V_11 , V_27 ) ;
if ( V_174 )
break;
}
}
V_163:
return V_174 ;
}
void F_199 ( struct V_10 * V_188 , struct V_27 * V_27 )
{
V_188 -> V_43 = V_214 ;
V_188 -> V_32 |= V_27 -> V_143 & V_215 ;
if ( V_27 -> V_143 & V_216 )
V_188 -> V_32 |= V_200 ;
V_188 -> V_217 = 0 ;
V_188 -> V_15 = V_27 -> V_35 . V_203 ;
V_188 -> V_202 = F_191 ( V_27 ) ;
F_200 ( V_188 -> V_2 , V_188 , V_27 ) ;
}
void V_130 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
const bool V_142 = ! ! ( V_27 -> V_143 & V_218 ) ;
struct V_205 * V_206 ;
int V_211 , V_148 , V_177 = V_219 ;
struct V_10 * V_188 ;
unsigned int V_204 = 0 ;
F_160 ( V_2 , & V_27 ) ;
if ( F_201 ( V_27 ) && F_202 ( V_27 ) ) {
F_15 ( V_27 , - V_31 ) ;
return;
}
if ( V_27 -> V_143 & ( V_144 | V_145 ) ) {
F_24 ( V_2 -> V_49 ) ;
V_177 = V_220 ;
goto V_221;
}
if ( ! F_203 ( V_2 ) &&
F_195 ( V_2 , V_27 , & V_204 ) )
return;
F_24 ( V_2 -> V_49 ) ;
V_211 = F_204 ( V_2 , & V_188 , V_27 ) ;
if ( V_211 == V_212 ) {
if ( F_186 ( V_2 , V_188 , V_27 ) ) {
F_205 ( V_2 , V_188 , V_27 ) ;
if ( ! F_206 ( V_2 , V_188 ) )
F_207 ( V_2 , V_188 , V_211 ) ;
goto V_222;
}
} else if ( V_211 == V_213 ) {
if ( F_192 ( V_2 , V_188 , V_27 ) ) {
F_205 ( V_2 , V_188 , V_27 ) ;
if ( ! F_208 ( V_2 , V_188 ) )
F_207 ( V_2 , V_188 , V_211 ) ;
goto V_222;
}
}
V_221:
V_148 = F_157 ( V_27 ) ;
if ( V_142 )
V_148 |= V_218 ;
V_188 = F_142 ( V_2 , V_148 , V_27 , V_223 ) ;
if ( F_145 ( V_188 ) ) {
F_15 ( V_27 , F_209 ( V_188 ) ) ;
goto V_222;
}
F_199 ( V_188 , V_27 ) ;
if ( F_11 ( V_224 , & V_2 -> V_119 ) )
V_188 -> V_14 = F_210 () ;
V_206 = V_147 -> V_206 ;
if ( V_206 ) {
if ( ! V_204 )
F_211 ( V_2 ) ;
else {
if ( V_204 >= V_225 ) {
F_212 ( V_206 , false ) ;
F_211 ( V_2 ) ;
}
}
F_213 ( & V_188 -> V_12 , & V_206 -> V_210 ) ;
F_171 ( V_188 , true ) ;
} else {
F_24 ( V_2 -> V_49 ) ;
F_170 ( V_2 , V_188 , V_177 ) ;
F_25 ( V_2 ) ;
V_222:
F_26 ( V_2 -> V_49 ) ;
}
}
static inline void F_214 ( struct V_27 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_226 ;
if ( F_215 ( V_27 ) && V_9 != V_9 -> V_227 ) {
struct V_178 * V_228 = V_9 -> V_229 ;
V_27 -> V_35 . V_203 += V_228 -> V_230 ;
V_27 -> V_226 = V_9 -> V_227 ;
F_216 ( F_3 ( V_27 -> V_226 ) , V_27 ,
V_9 -> V_231 ,
V_27 -> V_35 . V_203 - V_228 -> V_230 ) ;
}
}
static void F_217 ( struct V_27 * V_27 )
{
char V_232 [ V_233 ] ;
F_17 ( V_40 L_10 ) ;
F_17 ( V_40 L_11 ,
F_218 ( V_27 -> V_226 , V_232 ) ,
V_27 -> V_143 ,
( unsigned long long ) F_219 ( V_27 ) ,
( long long ) ( F_220 ( V_27 -> V_226 -> V_234 ) >> 9 ) ) ;
F_13 ( V_235 , & V_27 -> V_30 ) ;
}
static int T_4 F_221 ( char * V_236 )
{
return F_222 ( & V_237 , V_236 ) ;
}
static bool F_223 ( struct V_178 * V_26 , unsigned int V_238 )
{
return V_26 -> V_239 && F_224 ( & V_237 , V_238 ) ;
}
static int T_4 F_225 ( void )
{
struct V_240 * V_241 = F_226 ( L_12 ,
NULL , & V_237 ) ;
return F_227 ( V_241 ) ;
}
static inline bool F_223 ( struct V_178 * V_26 ,
unsigned int V_238 )
{
return false ;
}
static inline int F_228 ( struct V_27 * V_27 , unsigned int V_242 )
{
V_16 V_243 ;
if ( ! V_242 )
return 0 ;
V_243 = F_220 ( V_27 -> V_226 -> V_234 ) >> 9 ;
if ( V_243 ) {
V_16 V_244 = V_27 -> V_35 . V_203 ;
if ( V_243 < V_242 || V_243 - V_242 < V_244 ) {
F_217 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_229 ( struct V_27 * V_27 )
{
struct V_1 * V_2 ;
int V_242 = F_215 ( V_27 ) ;
int V_100 = - V_31 ;
char V_232 [ V_233 ] ;
struct V_178 * V_26 ;
F_230 () ;
if ( F_228 ( V_27 , V_242 ) )
goto V_245;
V_2 = F_3 ( V_27 -> V_226 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_246
L_13
L_14 ,
F_218 ( V_27 -> V_226 , V_232 ) ,
( long long ) V_27 -> V_35 . V_203 ) ;
goto V_245;
}
if ( F_28 ( F_231 ( V_27 ) &&
V_242 > F_232 ( V_2 ) ) ) {
F_17 ( V_246 L_15 ,
F_218 ( V_27 -> V_226 , V_232 ) ,
F_215 ( V_27 ) ,
F_232 ( V_2 ) ) ;
goto V_245;
}
V_26 = V_27 -> V_226 -> V_229 ;
if ( F_223 ( V_26 , V_27 -> V_35 . V_36 ) ||
F_223 ( & F_177 ( V_26 ) -> V_185 ,
V_27 -> V_35 . V_36 ) )
goto V_245;
F_214 ( V_27 ) ;
if ( F_228 ( V_27 , V_242 ) )
goto V_245;
if ( ( V_27 -> V_143 & ( V_144 | V_145 ) ) && ! V_2 -> V_247 ) {
V_27 -> V_143 &= ~ ( V_144 | V_145 ) ;
if ( ! V_242 ) {
V_100 = 0 ;
goto V_245;
}
}
if ( ( V_27 -> V_143 & V_248 ) &&
( ! F_233 ( V_2 ) ||
( ( V_27 -> V_143 & V_249 ) && ! F_234 ( V_2 ) ) ) ) {
V_100 = - V_250 ;
goto V_245;
}
if ( V_27 -> V_143 & V_251 && ! F_235 ( V_27 -> V_226 ) ) {
V_100 = - V_250 ;
goto V_245;
}
F_153 ( V_252 , V_2 -> V_96 ) ;
if ( F_236 ( V_2 , V_27 ) )
return false ;
F_237 ( V_2 , V_27 ) ;
return true ;
V_245:
F_15 ( V_27 , V_100 ) ;
return false ;
}
void F_238 ( struct V_27 * V_27 )
{
struct V_253 V_254 ;
if ( ! F_229 ( V_27 ) )
return;
if ( V_147 -> V_253 ) {
F_239 ( V_147 -> V_253 , V_27 ) ;
return;
}
F_152 ( V_27 -> V_201 ) ;
F_240 ( & V_254 ) ;
V_147 -> V_253 = & V_254 ;
do {
struct V_1 * V_2 = F_3 ( V_27 -> V_226 ) ;
V_2 -> V_255 ( V_2 , V_27 ) ;
V_27 = F_241 ( V_147 -> V_253 ) ;
} while ( V_27 );
V_147 -> V_253 = NULL ;
}
void F_242 ( int V_170 , struct V_27 * V_27 )
{
V_27 -> V_143 |= V_170 ;
if ( F_243 ( V_27 ) ) {
unsigned int V_90 ;
if ( F_12 ( V_170 & V_251 ) )
V_90 = F_244 ( V_27 -> V_226 ) >> 9 ;
else
V_90 = F_215 ( V_27 ) ;
if ( V_170 & V_172 ) {
F_245 ( V_256 , V_90 ) ;
} else {
F_246 ( V_27 -> V_35 . V_36 ) ;
F_245 ( V_257 , V_90 ) ;
}
if ( F_12 ( V_258 ) ) {
char V_232 [ V_233 ] ;
F_17 ( V_259 L_16 ,
V_147 -> V_260 , F_247 ( V_147 ) ,
( V_170 & V_172 ) ? L_17 : L_18 ,
( unsigned long long ) V_27 -> V_35 . V_203 ,
F_218 ( V_27 -> V_226 , V_232 ) ,
V_90 ) ;
}
}
F_238 ( V_27 ) ;
}
int F_248 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( ! F_249 ( V_11 ) )
return 0 ;
if ( F_19 ( V_11 ) > F_250 ( V_2 , V_11 -> V_32 ) ) {
F_17 ( V_246 L_19 , V_165 ) ;
return - V_31 ;
}
F_251 ( V_11 ) ;
if ( V_11 -> V_198 > F_252 ( V_2 ) ) {
F_17 ( V_246 L_20 , V_165 ) ;
return - V_31 ;
}
return 0 ;
}
int F_253 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
unsigned long V_61 ;
int V_177 = V_261 ;
if ( F_248 ( V_2 , V_11 ) )
return - V_31 ;
if ( V_11 -> V_41 &&
F_223 ( & V_11 -> V_41 -> V_185 , F_21 ( V_11 ) ) )
return - V_31 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
if ( F_12 ( F_105 ( V_2 ) ) ) {
F_49 ( V_2 -> V_49 , V_61 ) ;
return - V_154 ;
}
F_152 ( F_168 ( V_11 ) ) ;
if ( V_11 -> V_32 & ( V_144 | V_145 ) )
V_177 = V_220 ;
F_170 ( V_2 , V_11 , V_177 ) ;
if ( V_177 == V_220 )
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return 0 ;
}
unsigned int F_254 ( const struct V_10 * V_11 )
{
unsigned int V_199 = V_11 -> V_32 & V_200 ;
unsigned int V_238 = 0 ;
struct V_27 * V_27 ;
if ( ! ( V_11 -> V_32 & V_262 ) )
return F_21 ( V_11 ) ;
for ( V_27 = V_11 -> V_27 ; V_27 ; V_27 = V_27 -> V_201 ) {
if ( ( V_27 -> V_143 & V_199 ) != V_199 )
break;
V_238 += V_27 -> V_35 . V_36 ;
}
F_152 ( F_21 ( V_11 ) && ! V_238 ) ;
return V_238 ;
}
void F_255 ( struct V_10 * V_188 , unsigned int V_238 )
{
if ( F_256 ( V_188 ) ) {
const int V_170 = F_257 ( V_188 ) ;
struct V_178 * V_26 ;
int V_14 ;
V_14 = F_258 () ;
V_26 = V_188 -> V_26 ;
F_259 ( V_14 , V_26 , V_263 [ V_170 ] , V_238 >> 9 ) ;
F_260 () ;
}
}
void F_261 ( struct V_10 * V_188 )
{
if ( F_256 ( V_188 ) && ! ( V_188 -> V_32 & V_37 ) ) {
unsigned long V_264 = V_25 - V_188 -> V_24 ;
const int V_170 = F_257 ( V_188 ) ;
struct V_178 * V_26 ;
int V_14 ;
V_14 = F_258 () ;
V_26 = V_188 -> V_26 ;
F_262 ( V_14 , V_26 , V_265 [ V_170 ] ) ;
F_259 ( V_14 , V_26 , V_266 [ V_170 ] , V_264 ) ;
F_176 ( V_14 , V_26 ) ;
F_263 ( V_26 , V_170 ) ;
F_264 ( V_26 ) ;
F_260 () ;
}
}
static struct V_10 * F_265 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( V_2 -> V_166 && ( V_2 -> V_267 == V_268 ||
( V_2 -> V_267 != V_269 && ! ( V_11 -> V_32 & V_186 ) ) ) )
return NULL ;
else
return V_11 ;
}
static inline struct V_10 * F_265 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
return V_11 ;
}
void F_171 ( struct V_10 * V_11 , bool V_270 )
{
struct V_178 * V_26 ;
int V_170 = F_257 ( V_11 ) ;
int V_14 ;
if ( ! F_256 ( V_11 ) )
return;
V_14 = F_258 () ;
if ( ! V_270 ) {
V_26 = V_11 -> V_26 ;
F_262 ( V_14 , V_26 , V_271 [ V_170 ] ) ;
} else {
V_26 = F_266 ( V_11 -> V_41 , F_18 ( V_11 ) ) ;
if ( ! F_267 ( V_26 ) ) {
V_26 = & V_11 -> V_41 -> V_185 ;
F_268 ( V_26 ) ;
}
F_176 ( V_14 , V_26 ) ;
F_269 ( V_26 , V_170 ) ;
V_11 -> V_26 = V_26 ;
}
F_260 () ;
}
struct V_10 * F_270 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_174 ;
while ( ( V_11 = F_271 ( V_2 ) ) != NULL ) {
V_11 = F_265 ( V_2 , V_11 ) ;
if ( ! V_11 )
break;
if ( ! ( V_11 -> V_32 & V_272 ) ) {
if ( V_11 -> V_32 & V_273 )
F_272 ( V_2 , V_11 ) ;
V_11 -> V_32 |= V_272 ;
F_273 ( V_2 , V_11 ) ;
}
if ( ! V_2 -> V_274 || V_2 -> V_274 == V_11 ) {
V_2 -> V_275 = F_274 ( V_11 ) ;
V_2 -> V_274 = NULL ;
}
if ( V_11 -> V_32 & V_276 )
break;
if ( V_2 -> V_277 && F_21 ( V_11 ) ) {
V_11 -> V_198 ++ ;
}
if ( ! V_2 -> V_127 )
break;
V_174 = V_2 -> V_127 ( V_2 , V_11 ) ;
if ( V_174 == V_278 ) {
break;
} else if ( V_174 == V_279 ) {
if ( V_2 -> V_277 && F_21 ( V_11 ) &&
! ( V_11 -> V_32 & V_276 ) ) {
-- V_11 -> V_198 ;
}
V_11 = NULL ;
break;
} else if ( V_174 == V_280 ) {
V_11 -> V_32 |= V_33 ;
F_275 ( V_11 ) ;
F_276 ( V_11 , - V_31 ) ;
} else {
F_17 ( V_246 L_21 , V_165 , V_174 ) ;
break;
}
}
return V_11 ;
}
void F_277 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_152 ( F_56 ( & V_11 -> V_12 ) ) ;
F_152 ( F_184 ( V_11 ) ) ;
F_278 ( & V_11 -> V_12 ) ;
if ( F_279 ( V_11 ) ) {
V_2 -> V_71 [ F_280 ( V_11 ) ] ++ ;
F_281 ( V_11 ) ;
}
}
void F_275 ( struct V_10 * V_188 )
{
F_277 ( V_188 ) ;
V_188 -> V_197 = F_21 ( V_188 ) ;
if ( F_12 ( F_282 ( V_188 ) ) )
V_188 -> V_281 -> V_197 = F_21 ( V_188 -> V_281 ) ;
F_152 ( F_11 ( V_282 , & V_188 -> V_283 ) ) ;
F_283 ( V_188 ) ;
}
struct V_10 * F_284 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_270 ( V_2 ) ;
if ( V_11 )
F_275 ( V_11 ) ;
return V_11 ;
}
bool F_285 ( struct V_10 * V_188 , int error , unsigned int V_284 )
{
int V_285 ;
F_286 ( V_188 -> V_2 , V_188 , V_284 ) ;
if ( ! V_188 -> V_27 )
return false ;
if ( V_188 -> V_43 == V_214 )
V_188 -> V_217 = 0 ;
if ( error && V_188 -> V_43 == V_214 &&
! ( V_188 -> V_32 & V_33 ) ) {
char * V_286 ;
switch ( error ) {
case - V_287 :
V_286 = L_22 ;
break;
case - V_288 :
V_286 = L_23 ;
break;
case - V_289 :
V_286 = L_24 ;
break;
case - V_290 :
V_286 = L_25 ;
break;
case - V_291 :
V_286 = L_26 ;
break;
case - V_292 :
V_286 = L_27 ;
break;
case - V_31 :
default:
V_286 = L_28 ;
break;
}
F_140 ( V_246 L_29 ,
V_165 , V_286 , V_188 -> V_41 ?
V_188 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_18 ( V_188 ) ) ;
}
F_255 ( V_188 , V_284 ) ;
V_285 = 0 ;
while ( V_188 -> V_27 ) {
struct V_27 * V_27 = V_188 -> V_27 ;
unsigned V_293 = F_287 ( V_27 -> V_35 . V_36 , V_284 ) ;
if ( V_293 == V_27 -> V_35 . V_36 )
V_188 -> V_27 = V_27 -> V_201 ;
F_9 ( V_188 , V_27 , V_293 , error ) ;
V_285 += V_293 ;
V_284 -= V_293 ;
if ( ! V_284 )
break;
}
if ( ! V_188 -> V_27 ) {
V_188 -> V_175 = 0 ;
return false ;
}
V_188 -> V_175 -= V_285 ;
if ( V_188 -> V_43 == V_214 )
V_188 -> V_15 += V_285 >> 9 ;
if ( V_188 -> V_32 & V_262 ) {
V_188 -> V_32 &= ~ V_200 ;
V_188 -> V_32 |= V_188 -> V_27 -> V_143 & V_200 ;
}
if ( F_21 ( V_188 ) < F_288 ( V_188 ) ) {
F_16 ( V_188 , L_30 ) ;
V_188 -> V_175 = F_288 ( V_188 ) ;
}
F_251 ( V_188 ) ;
return true ;
}
static bool F_289 ( struct V_10 * V_11 , int error ,
unsigned int V_284 ,
unsigned int V_294 )
{
if ( F_285 ( V_11 , error , V_284 ) )
return true ;
if ( F_12 ( F_282 ( V_11 ) ) &&
F_285 ( V_11 -> V_281 , error , V_294 ) )
return true ;
if ( F_290 ( V_11 -> V_2 ) )
F_291 ( V_11 -> V_41 ) ;
return false ;
}
void F_292 ( struct V_10 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_2 ;
V_188 -> V_32 &= ~ V_276 ;
if ( V_2 -> V_128 )
V_2 -> V_128 ( V_2 , V_188 ) ;
}
void F_293 ( struct V_10 * V_188 , int error )
{
if ( V_188 -> V_32 & V_176 )
F_167 ( V_188 -> V_2 , V_188 ) ;
F_152 ( F_168 ( V_188 ) ) ;
if ( F_12 ( V_295 ) && V_188 -> V_43 == V_214 )
F_294 ( & V_188 -> V_2 -> V_7 ) ;
F_164 ( V_188 ) ;
if ( V_188 -> V_32 & V_276 )
F_292 ( V_188 ) ;
F_261 ( V_188 ) ;
if ( V_188 -> V_245 )
V_188 -> V_245 ( V_188 , error ) ;
else {
if ( F_282 ( V_188 ) )
F_180 ( V_188 -> V_281 -> V_2 , V_188 -> V_281 ) ;
F_180 ( V_188 -> V_2 , V_188 ) ;
}
}
static bool F_295 ( struct V_10 * V_11 , int error ,
unsigned int V_284 , unsigned int V_294 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_61 ;
if ( F_289 ( V_11 , error , V_284 , V_294 ) )
return true ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_293 ( V_11 , error ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return false ;
}
bool F_296 ( struct V_10 * V_11 , int error ,
unsigned int V_284 , unsigned int V_294 )
{
if ( F_289 ( V_11 , error , V_284 , V_294 ) )
return true ;
F_293 ( V_11 , error ) ;
return false ;
}
bool F_297 ( struct V_10 * V_11 , int error , unsigned int V_284 )
{
return F_295 ( V_11 , error , V_284 , 0 ) ;
}
void F_298 ( struct V_10 * V_11 , int error )
{
bool V_296 ;
unsigned int V_294 = 0 ;
if ( F_12 ( F_282 ( V_11 ) ) )
V_294 = F_21 ( V_11 -> V_281 ) ;
V_296 = F_295 ( V_11 , error , F_21 ( V_11 ) , V_294 ) ;
F_152 ( V_296 ) ;
}
bool F_299 ( struct V_10 * V_11 , int error )
{
return F_297 ( V_11 , error , F_288 ( V_11 ) ) ;
}
bool F_300 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_297 ( V_11 , error , F_254 ( V_11 ) ) ;
}
bool F_301 ( struct V_10 * V_11 , int error , unsigned int V_284 )
{
return F_296 ( V_11 , error , V_284 , 0 ) ;
}
void F_276 ( struct V_10 * V_11 , int error )
{
bool V_296 ;
unsigned int V_294 = 0 ;
if ( F_12 ( F_282 ( V_11 ) ) )
V_294 = F_21 ( V_11 -> V_281 ) ;
V_296 = F_296 ( V_11 , error , F_21 ( V_11 ) , V_294 ) ;
F_152 ( V_296 ) ;
}
bool F_302 ( struct V_10 * V_11 , int error )
{
return F_301 ( V_11 , error , F_288 ( V_11 ) ) ;
}
bool F_303 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_301 ( V_11 , error , F_254 ( V_11 ) ) ;
}
void F_200 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_27 * V_27 )
{
V_11 -> V_32 |= V_27 -> V_143 & V_297 ;
if ( F_243 ( V_27 ) )
V_11 -> V_198 = F_304 ( V_2 , V_27 ) ;
V_11 -> V_175 = V_27 -> V_35 . V_36 ;
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
if ( V_27 -> V_226 )
V_11 -> V_41 = V_27 -> V_226 -> V_298 ;
}
void F_305 ( struct V_10 * V_11 )
{
struct V_299 V_300 ;
struct V_301 V_302 ;
F_306 (bvec, rq, iter)
F_307 ( V_302 . V_192 ) ;
}
int F_308 ( struct V_1 * V_2 )
{
if ( V_2 -> V_303 )
return V_2 -> V_303 ( V_2 ) ;
return 0 ;
}
void F_309 ( struct V_10 * V_11 )
{
struct V_27 * V_27 ;
while ( ( V_27 = V_11 -> V_27 ) != NULL ) {
V_11 -> V_27 = V_27 -> V_201 ;
F_310 ( V_27 ) ;
}
}
static void F_311 ( struct V_10 * V_304 , struct V_10 * V_305 )
{
V_304 -> V_14 = V_305 -> V_14 ;
V_304 -> V_32 = ( V_305 -> V_32 & V_306 ) | V_307 ;
V_304 -> V_43 = V_305 -> V_43 ;
V_304 -> V_15 = F_18 ( V_305 ) ;
V_304 -> V_175 = F_21 ( V_305 ) ;
V_304 -> V_198 = V_305 -> V_198 ;
V_304 -> V_202 = V_305 -> V_202 ;
V_304 -> V_308 = V_305 -> V_308 ;
}
int F_312 ( struct V_10 * V_11 , struct V_10 * V_309 ,
struct V_310 * V_311 , T_2 V_89 ,
int (* F_313)( struct V_27 * , struct V_27 * , void * ) ,
void * V_312 )
{
struct V_27 * V_27 , * V_313 ;
if ( ! V_311 )
V_311 = V_314 ;
F_4 ( NULL , V_11 ) ;
F_314 (bio_src, rq_src) {
V_27 = F_315 ( V_313 , V_89 , V_311 ) ;
if ( ! V_27 )
goto V_315;
if ( F_313 && F_313 ( V_27 , V_313 , V_312 ) )
goto V_315;
if ( V_11 -> V_27 ) {
V_11 -> V_44 -> V_201 = V_27 ;
V_11 -> V_44 = V_27 ;
} else
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
}
F_311 ( V_11 , V_309 ) ;
return 0 ;
V_315:
if ( V_27 )
F_310 ( V_27 ) ;
F_309 ( V_11 ) ;
return - V_97 ;
}
int F_316 ( struct V_46 * V_47 )
{
return F_317 ( V_51 , V_47 ) ;
}
int F_318 ( struct V_316 * V_317 ,
unsigned long V_318 )
{
return F_30 ( V_51 , V_317 , V_318 ) ;
}
int F_319 ( int V_14 , struct V_316 * V_317 ,
unsigned long V_318 )
{
return F_320 ( V_14 , V_51 , V_317 , V_318 ) ;
}
void F_321 ( struct V_205 * V_206 )
{
struct V_319 * V_320 = V_147 ;
F_5 ( & V_206 -> V_210 ) ;
F_5 ( & V_206 -> V_209 ) ;
F_5 ( & V_206 -> V_321 ) ;
if ( ! V_320 -> V_206 ) {
V_320 -> V_206 = V_206 ;
}
}
static int F_322 ( void * V_322 , struct V_207 * V_323 , struct V_207 * V_232 )
{
struct V_10 * V_324 = F_23 ( V_323 , struct V_10 , V_12 ) ;
struct V_10 * V_325 = F_23 ( V_232 , struct V_10 , V_12 ) ;
return ! ( V_324 -> V_2 < V_325 -> V_2 ||
( V_324 -> V_2 == V_325 -> V_2 && F_18 ( V_324 ) < F_18 ( V_325 ) ) ) ;
}
static void F_323 ( struct V_1 * V_2 , unsigned int V_326 ,
bool V_327 )
__releases( V_2 -> V_49 )
{
F_324 ( V_2 , V_326 , ! V_327 ) ;
if ( V_327 )
F_45 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_325 ( V_2 -> V_49 ) ;
}
static void F_326 ( struct V_205 * V_206 , bool V_327 )
{
F_327 ( V_328 ) ;
while ( ! F_56 ( & V_206 -> V_321 ) ) {
F_328 ( & V_206 -> V_321 , & V_328 ) ;
while ( ! F_56 ( & V_328 ) ) {
struct V_329 * V_330 = F_329 ( & V_328 ,
struct V_329 ,
V_210 ) ;
F_330 ( & V_330 -> V_210 ) ;
V_330 -> V_331 ( V_330 , V_327 ) ;
}
}
}
struct V_329 * F_331 ( T_6 V_332 , void * V_312 ,
int V_333 )
{
struct V_205 * V_206 = V_147 -> V_206 ;
struct V_329 * V_330 ;
if ( ! V_206 )
return NULL ;
F_332 (cb, &plug->cb_list, list)
if ( V_330 -> V_331 == V_332 && V_330 -> V_312 == V_312 )
return V_330 ;
F_152 ( V_333 < sizeof( * V_330 ) ) ;
V_330 = F_333 ( V_333 , V_252 ) ;
if ( V_330 ) {
V_330 -> V_312 = V_312 ;
V_330 -> V_331 = V_332 ;
F_334 ( & V_330 -> V_210 , & V_206 -> V_321 ) ;
}
return V_330 ;
}
void F_212 ( struct V_205 * V_206 , bool V_327 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
struct V_10 * V_11 ;
F_327 ( V_210 ) ;
unsigned int V_326 ;
F_326 ( V_206 , V_327 ) ;
if ( ! F_56 ( & V_206 -> V_209 ) )
F_335 ( V_206 , V_327 ) ;
if ( F_56 ( & V_206 -> V_210 ) )
return;
F_328 ( & V_206 -> V_210 , & V_210 ) ;
F_336 ( NULL , & V_210 , F_322 ) ;
V_2 = NULL ;
V_326 = 0 ;
F_337 ( V_61 ) ;
while ( ! F_56 ( & V_210 ) ) {
V_11 = F_338 ( V_210 . V_334 ) ;
F_278 ( & V_11 -> V_12 ) ;
F_152 ( ! V_11 -> V_2 ) ;
if ( V_11 -> V_2 != V_2 ) {
if ( V_2 )
F_323 ( V_2 , V_326 , V_327 ) ;
V_2 = V_11 -> V_2 ;
V_326 = 0 ;
F_339 ( V_2 -> V_49 ) ;
}
if ( F_12 ( F_105 ( V_2 ) ) ) {
F_276 ( V_11 , - V_154 ) ;
continue;
}
if ( V_11 -> V_32 & ( V_144 | V_145 ) )
F_172 ( V_2 , V_11 , V_220 ) ;
else
F_172 ( V_2 , V_11 , V_335 ) ;
V_326 ++ ;
}
if ( V_2 )
F_323 ( V_2 , V_326 , V_327 ) ;
F_340 ( V_61 ) ;
}
void F_341 ( struct V_205 * V_206 )
{
F_212 ( V_206 , false ) ;
if ( V_206 == V_147 -> V_206 )
V_147 -> V_206 = NULL ;
}
void F_342 ( struct V_1 * V_2 , struct V_336 * V_166 )
{
V_2 -> V_166 = V_166 ;
V_2 -> V_267 = V_269 ;
F_343 ( V_2 -> V_166 , - 1 ) ;
F_344 ( V_2 -> V_166 ) ;
}
int F_345 ( struct V_1 * V_2 )
{
int V_174 = 0 ;
F_24 ( V_2 -> V_49 ) ;
if ( V_2 -> V_187 ) {
V_174 = - V_337 ;
F_179 ( V_2 -> V_166 ) ;
} else {
V_2 -> V_267 = V_338 ;
}
F_26 ( V_2 -> V_49 ) ;
return V_174 ;
}
void F_346 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_100 ) {
V_2 -> V_267 = V_268 ;
} else {
V_2 -> V_267 = V_269 ;
F_179 ( V_2 -> V_166 ) ;
}
F_26 ( V_2 -> V_49 ) ;
}
void F_347 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_267 = V_339 ;
F_26 ( V_2 -> V_49 ) ;
}
void F_348 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_100 ) {
V_2 -> V_267 = V_269 ;
F_25 ( V_2 ) ;
F_179 ( V_2 -> V_166 ) ;
F_349 ( V_2 -> V_166 ) ;
} else {
V_2 -> V_267 = V_268 ;
}
F_26 ( V_2 -> V_49 ) ;
}
int T_4 F_350 ( void )
{
F_351 ( V_340 > 8 *
sizeof( ( (struct V_10 * ) 0 ) -> V_32 ) ) ;
V_51 = F_352 ( L_31 ,
V_341 | V_342 , 0 ) ;
if ( ! V_51 )
F_353 ( L_32 ) ;
V_95 = F_354 ( L_33 ,
sizeof( struct V_10 ) , 0 , V_343 , NULL ) ;
V_101 = F_354 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_343 , NULL ) ;
return 0 ;
}
