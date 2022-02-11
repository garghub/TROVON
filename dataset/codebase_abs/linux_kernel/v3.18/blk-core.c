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
T_1 * V_78 = V_2 -> V_49 ;
F_68 ( & V_2 -> V_79 ) ;
F_69 ( V_80 , V_2 ) ;
F_24 ( V_78 ) ;
V_2 -> V_76 ++ ;
F_38 ( V_77 , V_2 ) ;
F_38 ( V_81 , V_2 ) ;
F_38 ( V_82 , V_2 ) ;
F_38 ( V_80 , V_2 ) ;
F_26 ( V_78 ) ;
F_70 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_54 ) {
F_71 ( V_2 ) ;
F_24 ( V_78 ) ;
} else {
F_24 ( V_78 ) ;
F_52 ( V_2 , true ) ;
}
F_38 ( V_83 , V_2 ) ;
F_26 ( V_78 ) ;
F_40 ( & V_2 -> V_7 . V_84 ) ;
F_39 ( V_2 ) ;
F_24 ( V_78 ) ;
if ( V_2 -> V_49 != & V_2 -> V_85 )
V_2 -> V_49 = & V_2 -> V_85 ;
F_26 ( V_78 ) ;
F_50 ( V_2 ) ;
}
int F_72 ( struct V_73 * V_74 , struct V_1 * V_2 ,
T_2 V_86 )
{
if ( F_12 ( V_74 -> V_87 ) )
return 0 ;
V_74 -> V_2 = V_2 ;
V_74 -> V_88 [ V_89 ] = V_74 -> V_88 [ V_90 ] = 0 ;
V_74 -> V_91 [ V_89 ] = V_74 -> V_91 [ V_90 ] = 0 ;
F_73 ( & V_74 -> V_75 [ V_89 ] ) ;
F_73 ( & V_74 -> V_75 [ V_90 ] ) ;
V_74 -> V_87 = F_74 ( V_92 , V_93 ,
V_94 , V_95 ,
V_86 , V_2 -> V_96 ) ;
if ( ! V_74 -> V_87 )
return - V_97 ;
return 0 ;
}
void F_75 ( struct V_73 * V_74 )
{
if ( V_74 -> V_87 )
F_76 ( V_74 -> V_87 ) ;
}
struct V_1 * F_77 ( T_2 V_86 )
{
return F_78 ( V_86 , V_98 ) ;
}
struct V_1 * F_78 ( T_2 V_86 , int V_99 )
{
struct V_1 * V_2 ;
int V_100 ;
V_2 = F_79 ( V_101 ,
V_86 | V_102 , V_99 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_103 = F_80 ( & V_104 , 0 , 0 , V_86 ) ;
if ( V_2 -> V_103 < 0 )
goto V_105;
V_2 -> V_7 . V_106 =
( V_107 * 1024 ) / V_108 ;
V_2 -> V_7 . V_109 = 0 ;
V_2 -> V_7 . V_110 = V_111 ;
V_2 -> V_7 . V_112 = L_8 ;
V_2 -> V_96 = V_99 ;
V_100 = F_81 ( & V_2 -> V_7 ) ;
if ( V_100 )
goto V_113;
F_82 ( & V_2 -> V_7 . V_84 ,
V_114 , ( unsigned long ) V_2 ) ;
F_82 ( & V_2 -> V_53 , V_115 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_66 ) ;
F_5 ( & V_2 -> V_13 ) ;
F_5 ( & V_2 -> V_116 ) ;
#ifdef F_83
F_5 ( & V_2 -> V_117 ) ;
#endif
F_84 ( & V_2 -> V_48 , F_22 ) ;
F_85 ( & V_2 -> V_62 , & V_118 ) ;
F_86 ( & V_2 -> V_79 ) ;
F_87 ( & V_2 -> V_85 ) ;
V_2 -> V_49 = & V_2 -> V_85 ;
V_2 -> V_76 = 1 ;
F_88 ( V_77 , & V_2 -> V_119 ) ;
F_73 ( & V_2 -> V_120 ) ;
if ( F_89 ( V_2 ) )
goto V_121;
return V_2 ;
V_121:
F_90 ( & V_2 -> V_7 ) ;
V_113:
F_91 ( & V_104 , V_2 -> V_103 ) ;
V_105:
F_92 ( V_101 , V_2 ) ;
return NULL ;
}
struct V_1 * F_93 ( T_3 * V_122 , T_1 * V_78 )
{
return F_94 ( V_122 , V_78 , V_98 ) ;
}
struct V_1 *
F_94 ( T_3 * V_122 , T_1 * V_78 , int V_99 )
{
struct V_1 * V_123 , * V_2 ;
V_123 = F_78 ( V_124 , V_99 ) ;
if ( ! V_123 )
return NULL ;
V_2 = F_95 ( V_123 , V_122 , V_78 ) ;
if ( ! V_2 )
F_67 ( V_123 ) ;
return V_2 ;
}
struct V_1 *
F_95 ( struct V_1 * V_2 , T_3 * V_122 ,
T_1 * V_78 )
{
if ( ! V_2 )
return NULL ;
V_2 -> V_69 = F_96 ( V_2 , V_98 , 0 ) ;
if ( ! V_2 -> V_69 )
return NULL ;
if ( F_72 ( & V_2 -> V_125 , V_2 , V_124 ) )
goto V_126;
V_2 -> V_60 = V_122 ;
V_2 -> V_127 = NULL ;
V_2 -> V_128 = NULL ;
V_2 -> V_119 |= V_129 ;
if ( V_78 )
V_2 -> V_49 = V_78 ;
F_97 ( V_2 , V_130 ) ;
V_2 -> V_131 = V_132 ;
F_68 ( & V_2 -> V_79 ) ;
if ( F_98 ( V_2 , NULL ) ) {
F_70 ( & V_2 -> V_79 ) ;
goto V_126;
}
F_70 ( & V_2 -> V_79 ) ;
return V_2 ;
V_126:
F_99 ( V_2 -> V_69 ) ;
return NULL ;
}
bool F_100 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_101 ( V_2 ) ) ) {
F_102 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_103 ( struct V_73 * V_74 , struct V_10 * V_11 )
{
if ( V_11 -> V_32 & V_133 ) {
F_104 ( V_74 -> V_2 , V_11 ) ;
if ( V_11 -> V_134 . V_135 )
F_105 ( V_11 -> V_134 . V_135 -> V_136 ) ;
}
F_106 ( V_11 , V_74 -> V_87 ) ;
}
static inline int F_107 ( struct V_1 * V_2 , struct V_137 * V_136 )
{
if ( ! V_136 )
return 0 ;
return V_136 -> V_138 == V_2 -> V_139 ||
( V_136 -> V_138 > 0
&& F_108 ( V_25 , V_136 -> V_140 + V_141 ) ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_137 * V_136 )
{
if ( ! V_136 || F_107 ( V_2 , V_136 ) )
return;
V_136 -> V_138 = V_2 -> V_139 ;
V_136 -> V_140 = V_25 ;
}
static void F_110 ( struct V_73 * V_74 , int V_142 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
if ( V_74 == & V_2 -> V_125 &&
V_74 -> V_88 [ V_142 ] < F_111 ( V_2 ) )
F_112 ( V_2 , V_142 ) ;
if ( V_74 -> V_88 [ V_142 ] + 1 <= V_2 -> V_4 ) {
if ( F_113 ( & V_74 -> V_75 [ V_142 ] ) )
F_114 ( & V_74 -> V_75 [ V_142 ] ) ;
F_115 ( V_74 , V_142 ) ;
}
}
static void F_116 ( struct V_73 * V_74 , unsigned int V_61 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_142 = F_117 ( V_61 ) ;
V_2 -> V_70 [ V_142 ] -- ;
V_74 -> V_88 [ V_142 ] -- ;
if ( V_61 & V_133 )
V_2 -> V_67 -- ;
F_110 ( V_74 , V_142 ) ;
if ( F_12 ( V_74 -> V_91 [ V_142 ^ 1 ] ) )
F_110 ( V_74 , V_142 ^ 1 ) ;
}
int F_118 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_73 * V_74 ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_4 = V_3 ;
F_1 ( V_2 ) ;
V_74 = & V_2 -> V_125 ;
if ( V_74 -> V_88 [ V_89 ] >= F_119 ( V_2 ) )
F_120 ( V_2 , V_89 ) ;
else if ( V_74 -> V_88 [ V_89 ] < F_111 ( V_2 ) )
F_112 ( V_2 , V_89 ) ;
if ( V_74 -> V_88 [ V_90 ] >= F_119 ( V_2 ) )
F_120 ( V_2 , V_90 ) ;
else if ( V_74 -> V_88 [ V_90 ] < F_111 ( V_2 ) )
F_112 ( V_2 , V_90 ) ;
F_59 (rl, q) {
if ( V_74 -> V_88 [ V_89 ] >= V_2 -> V_4 ) {
F_121 ( V_74 , V_89 ) ;
} else {
F_115 ( V_74 , V_89 ) ;
F_114 ( & V_74 -> V_75 [ V_89 ] ) ;
}
if ( V_74 -> V_88 [ V_90 ] >= V_2 -> V_4 ) {
F_121 ( V_74 , V_90 ) ;
} else {
F_115 ( V_74 , V_90 ) ;
F_114 ( & V_74 -> V_75 [ V_90 ] ) ;
}
}
F_26 ( V_2 -> V_49 ) ;
return 0 ;
}
static bool F_122 ( struct V_27 * V_27 )
{
if ( ! V_27 )
return true ;
if ( V_27 -> V_143 & ( V_144 | V_145 ) )
return false ;
return true ;
}
static struct V_137 * F_123 ( struct V_27 * V_27 )
{
#ifdef F_83
if ( V_27 && V_27 -> V_146 )
return V_27 -> V_146 ;
#endif
return V_147 -> V_137 ;
}
static struct V_10 * F_124 ( struct V_73 * V_74 , int V_148 ,
struct V_27 * V_27 , T_2 V_86 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_10 * V_11 ;
struct V_149 * V_150 = V_2 -> V_65 -> type ;
struct V_137 * V_136 = F_123 ( V_27 ) ;
struct V_151 * V_135 = NULL ;
const bool V_152 = F_117 ( V_148 ) != 0 ;
int V_153 ;
if ( F_12 ( F_101 ( V_2 ) ) )
return F_125 ( - V_154 ) ;
V_153 = F_126 ( V_2 , V_148 ) ;
if ( V_153 == V_155 )
goto V_156;
if ( V_74 -> V_88 [ V_152 ] + 1 >= F_119 ( V_2 ) ) {
if ( V_74 -> V_88 [ V_152 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_127 ( V_74 , V_152 ) ) {
F_109 ( V_2 , V_136 ) ;
F_121 ( V_74 , V_152 ) ;
} else {
if ( V_153 != V_157
&& ! F_107 ( V_2 , V_136 ) ) {
return F_125 ( - V_97 ) ;
}
}
}
if ( V_74 == & V_2 -> V_125 )
F_120 ( V_2 , V_152 ) ;
}
if ( V_74 -> V_88 [ V_152 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return F_125 ( - V_97 ) ;
V_2 -> V_70 [ V_152 ] ++ ;
V_74 -> V_88 [ V_152 ] ++ ;
V_74 -> V_91 [ V_152 ] = 0 ;
if ( F_122 ( V_27 ) && ! F_128 ( V_2 ) ) {
V_148 |= V_133 ;
V_2 -> V_67 ++ ;
if ( V_150 -> V_158 && V_136 )
V_135 = F_129 ( V_136 , V_2 ) ;
}
if ( F_130 ( V_2 ) )
V_148 |= V_159 ;
F_26 ( V_2 -> V_49 ) ;
V_11 = F_131 ( V_74 -> V_87 , V_86 ) ;
if ( ! V_11 )
goto V_160;
F_4 ( V_2 , V_11 ) ;
F_132 ( V_11 , V_74 ) ;
V_11 -> V_32 = V_148 | V_161 ;
if ( V_148 & V_133 ) {
if ( F_12 ( V_150 -> V_158 && ! V_135 ) ) {
if ( V_136 )
V_135 = F_133 ( V_136 , V_2 , V_86 ) ;
if ( ! V_135 )
goto V_162;
}
V_11 -> V_134 . V_135 = V_135 ;
if ( F_12 ( F_134 ( V_2 , V_11 , V_27 , V_86 ) ) )
goto V_162;
if ( V_135 )
F_135 ( V_135 -> V_136 ) ;
}
V_163:
if ( F_107 ( V_2 , V_136 ) )
V_136 -> V_138 -- ;
F_136 ( V_2 , V_27 , V_148 & 1 ) ;
return V_11 ;
V_162:
F_137 ( V_164 L_9 ,
V_165 , F_138 ( V_2 -> V_7 . V_166 ) ) ;
V_11 -> V_32 &= ~ V_133 ;
V_11 -> V_134 . V_135 = NULL ;
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_67 -- ;
F_26 ( V_2 -> V_49 ) ;
goto V_163;
V_160:
F_24 ( V_2 -> V_49 ) ;
F_116 ( V_74 , V_148 ) ;
V_156:
if ( F_12 ( V_74 -> V_88 [ V_152 ] == 0 ) )
V_74 -> V_91 [ V_152 ] = 1 ;
return F_125 ( - V_97 ) ;
}
static struct V_10 * F_139 ( struct V_1 * V_2 , int V_148 ,
struct V_27 * V_27 , T_2 V_86 )
{
const bool V_152 = F_117 ( V_148 ) != 0 ;
F_140 ( V_75 ) ;
struct V_73 * V_74 ;
struct V_10 * V_11 ;
V_74 = F_141 ( V_2 , V_27 ) ;
V_167:
V_11 = F_124 ( V_74 , V_148 , V_27 , V_86 ) ;
if ( ! F_142 ( V_11 ) )
return V_11 ;
if ( ! ( V_86 & V_168 ) || F_12 ( F_101 ( V_2 ) ) ) {
F_143 ( V_74 ) ;
return V_11 ;
}
F_144 ( & V_74 -> V_75 [ V_152 ] , & V_75 ,
V_169 ) ;
F_145 ( V_2 , V_27 , V_148 & 1 ) ;
F_26 ( V_2 -> V_49 ) ;
F_146 () ;
F_109 ( V_2 , V_147 -> V_137 ) ;
F_24 ( V_2 -> V_49 ) ;
F_147 ( & V_74 -> V_75 [ V_152 ] , & V_75 ) ;
goto V_167;
}
static struct V_10 * F_148 ( struct V_1 * V_2 , int V_170 ,
T_2 V_86 )
{
struct V_10 * V_11 ;
F_149 ( V_170 != V_171 && V_170 != V_172 ) ;
F_150 ( V_86 , V_2 -> V_96 ) ;
F_24 ( V_2 -> V_49 ) ;
V_11 = F_139 ( V_2 , V_170 , NULL , V_86 ) ;
if ( F_142 ( V_11 ) )
F_26 ( V_2 -> V_49 ) ;
return V_11 ;
}
struct V_10 * F_151 ( struct V_1 * V_2 , int V_170 , T_2 V_86 )
{
if ( V_2 -> V_54 )
return F_152 ( V_2 , V_170 , V_86 , false ) ;
else
return F_148 ( V_2 , V_170 , V_86 ) ;
}
struct V_10 * F_153 ( struct V_1 * V_2 , struct V_27 * V_27 ,
T_2 V_86 )
{
struct V_10 * V_11 = F_151 ( V_2 , F_154 ( V_27 ) , V_86 ) ;
if ( F_142 ( V_11 ) )
return V_11 ;
F_155 ( V_11 ) ;
F_156 (bio) {
struct V_27 * V_173 = V_27 ;
int V_174 ;
F_157 ( V_2 , & V_173 ) ;
V_174 = F_158 ( V_2 , V_11 , V_173 ) ;
if ( F_12 ( V_174 ) ) {
F_159 ( V_11 ) ;
return F_125 ( V_174 ) ;
}
}
return V_11 ;
}
void F_155 ( struct V_10 * V_11 )
{
V_11 -> V_43 = V_45 ;
V_11 -> V_175 = 0 ;
V_11 -> V_15 = ( V_16 ) - 1 ;
V_11 -> V_27 = V_11 -> V_44 = NULL ;
memset ( V_11 -> V_20 , 0 , sizeof( V_11 -> V_20 ) ) ;
}
void F_160 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_161 ( V_11 ) ;
F_162 ( V_11 ) ;
F_163 ( V_2 , V_11 ) ;
if ( F_164 ( V_11 ) )
F_165 ( V_2 , V_11 ) ;
F_149 ( F_166 ( V_11 ) ) ;
F_167 ( V_2 , V_11 ) ;
}
static void F_168 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_176 )
{
F_169 ( V_11 , true ) ;
F_170 ( V_2 , V_11 , V_176 ) ;
}
static void F_171 ( int V_14 , struct V_177 * V_26 ,
unsigned long V_178 )
{
int V_179 ;
if ( V_178 == V_26 -> V_180 )
return;
V_179 = F_172 ( V_26 ) ;
if ( V_179 ) {
F_173 ( V_14 , V_26 , V_181 ,
V_179 * ( V_178 - V_26 -> V_180 ) ) ;
F_173 ( V_14 , V_26 , V_182 , ( V_178 - V_26 -> V_180 ) ) ;
}
V_26 -> V_180 = V_178 ;
}
void F_174 ( int V_14 , struct V_177 * V_26 )
{
unsigned long V_178 = V_25 ;
if ( V_26 -> V_183 )
F_171 ( V_14 , & F_175 ( V_26 ) -> V_184 , V_178 ) ;
F_171 ( V_14 , V_26 , V_178 ) ;
}
static void F_176 ( struct V_10 * V_11 )
{
if ( V_11 -> V_2 -> V_166 && ! ( V_11 -> V_32 & V_185 ) && ! -- V_11 -> V_2 -> V_186 )
F_177 ( V_11 -> V_2 -> V_166 ) ;
}
static inline void F_176 ( struct V_10 * V_11 ) {}
void F_178 ( struct V_1 * V_2 , struct V_10 * V_187 )
{
if ( F_12 ( ! V_2 ) )
return;
if ( V_2 -> V_54 ) {
F_179 ( V_187 ) ;
return;
}
F_176 ( V_187 ) ;
F_180 ( V_2 , V_187 ) ;
F_33 ( V_187 -> V_27 != NULL ) ;
if ( V_187 -> V_32 & V_161 ) {
unsigned int V_61 = V_187 -> V_32 ;
struct V_73 * V_74 = F_181 ( V_187 ) ;
F_149 ( ! F_56 ( & V_187 -> V_12 ) ) ;
F_149 ( F_182 ( V_187 ) ) ;
F_103 ( V_74 , V_187 ) ;
F_116 ( V_74 , V_61 ) ;
F_143 ( V_74 ) ;
}
}
void F_159 ( struct V_10 * V_187 )
{
struct V_1 * V_2 = V_187 -> V_2 ;
if ( V_2 -> V_54 )
F_179 ( V_187 ) ;
else {
unsigned long V_61 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_178 ( V_2 , V_187 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
}
}
void F_183 ( struct V_10 * V_11 , struct V_188 * V_188 ,
unsigned int V_189 )
{
struct V_27 * V_27 = V_11 -> V_27 ;
V_27 -> V_190 -> V_191 = V_188 ;
V_27 -> V_190 -> V_192 = 0 ;
V_27 -> V_190 -> V_193 = V_189 ;
V_27 -> V_35 . V_36 = V_189 ;
V_27 -> V_194 = 1 ;
V_27 -> V_195 = 1 ;
V_11 -> V_175 = V_11 -> V_196 = V_189 ;
V_11 -> V_197 = 1 ;
}
bool F_184 ( struct V_1 * V_2 , struct V_10 * V_187 ,
struct V_27 * V_27 )
{
const int V_198 = V_27 -> V_143 & V_199 ;
if ( ! F_185 ( V_2 , V_187 , V_27 ) )
return false ;
F_186 ( V_2 , V_187 , V_27 ) ;
if ( ( V_187 -> V_32 & V_199 ) != V_198 )
F_187 ( V_187 ) ;
V_187 -> V_44 -> V_200 = V_27 ;
V_187 -> V_44 = V_27 ;
V_187 -> V_175 += V_27 -> V_35 . V_36 ;
V_187 -> V_201 = F_188 ( V_187 -> V_201 , F_189 ( V_27 ) ) ;
F_169 ( V_187 , false ) ;
return true ;
}
bool F_190 ( struct V_1 * V_2 , struct V_10 * V_187 ,
struct V_27 * V_27 )
{
const int V_198 = V_27 -> V_143 & V_199 ;
if ( ! F_191 ( V_2 , V_187 , V_27 ) )
return false ;
F_192 ( V_2 , V_187 , V_27 ) ;
if ( ( V_187 -> V_32 & V_199 ) != V_198 )
F_187 ( V_187 ) ;
V_27 -> V_200 = V_187 -> V_27 ;
V_187 -> V_27 = V_27 ;
V_187 -> V_15 = V_27 -> V_35 . V_202 ;
V_187 -> V_175 += V_27 -> V_35 . V_36 ;
V_187 -> V_201 = F_188 ( V_187 -> V_201 , F_189 ( V_27 ) ) ;
F_169 ( V_187 , false ) ;
return true ;
}
bool F_193 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned int * V_203 )
{
struct V_204 * V_205 ;
struct V_10 * V_11 ;
bool V_174 = false ;
struct V_206 * V_207 ;
V_205 = V_147 -> V_205 ;
if ( ! V_205 )
goto V_163;
* V_203 = 0 ;
if ( V_2 -> V_54 )
V_207 = & V_205 -> V_208 ;
else
V_207 = & V_205 -> V_209 ;
F_194 (rq, plug_list, queuelist) {
int V_210 ;
if ( V_11 -> V_2 == V_2 )
( * V_203 ) ++ ;
if ( V_11 -> V_2 != V_2 || ! F_195 ( V_11 , V_27 ) )
continue;
V_210 = F_196 ( V_11 , V_27 ) ;
if ( V_210 == V_211 ) {
V_174 = F_184 ( V_2 , V_11 , V_27 ) ;
if ( V_174 )
break;
} else if ( V_210 == V_212 ) {
V_174 = F_190 ( V_2 , V_11 , V_27 ) ;
if ( V_174 )
break;
}
}
V_163:
return V_174 ;
}
void F_197 ( struct V_10 * V_187 , struct V_27 * V_27 )
{
V_187 -> V_43 = V_213 ;
V_187 -> V_32 |= V_27 -> V_143 & V_214 ;
if ( V_27 -> V_143 & V_215 )
V_187 -> V_32 |= V_199 ;
V_187 -> V_216 = 0 ;
V_187 -> V_15 = V_27 -> V_35 . V_202 ;
V_187 -> V_201 = F_189 ( V_27 ) ;
F_198 ( V_187 -> V_2 , V_187 , V_27 ) ;
}
void V_130 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
const bool V_142 = ! ! ( V_27 -> V_143 & V_217 ) ;
struct V_204 * V_205 ;
int V_210 , V_148 , V_176 = V_218 ;
struct V_10 * V_187 ;
unsigned int V_203 = 0 ;
F_157 ( V_2 , & V_27 ) ;
if ( F_199 ( V_27 ) && F_200 ( V_27 ) ) {
F_15 ( V_27 , - V_31 ) ;
return;
}
if ( V_27 -> V_143 & ( V_144 | V_145 ) ) {
F_24 ( V_2 -> V_49 ) ;
V_176 = V_219 ;
goto V_220;
}
if ( ! F_201 ( V_2 ) &&
F_193 ( V_2 , V_27 , & V_203 ) )
return;
F_24 ( V_2 -> V_49 ) ;
V_210 = F_202 ( V_2 , & V_187 , V_27 ) ;
if ( V_210 == V_211 ) {
if ( F_184 ( V_2 , V_187 , V_27 ) ) {
F_203 ( V_2 , V_187 , V_27 ) ;
if ( ! F_204 ( V_2 , V_187 ) )
F_205 ( V_2 , V_187 , V_210 ) ;
goto V_221;
}
} else if ( V_210 == V_212 ) {
if ( F_190 ( V_2 , V_187 , V_27 ) ) {
F_203 ( V_2 , V_187 , V_27 ) ;
if ( ! F_206 ( V_2 , V_187 ) )
F_205 ( V_2 , V_187 , V_210 ) ;
goto V_221;
}
}
V_220:
V_148 = F_154 ( V_27 ) ;
if ( V_142 )
V_148 |= V_217 ;
V_187 = F_139 ( V_2 , V_148 , V_27 , V_222 ) ;
if ( F_142 ( V_187 ) ) {
F_15 ( V_27 , F_207 ( V_187 ) ) ;
goto V_221;
}
F_197 ( V_187 , V_27 ) ;
if ( F_11 ( V_223 , & V_2 -> V_119 ) )
V_187 -> V_14 = F_208 () ;
V_205 = V_147 -> V_205 ;
if ( V_205 ) {
if ( ! V_203 )
F_209 ( V_2 ) ;
else {
if ( V_203 >= V_224 ) {
F_210 ( V_205 , false ) ;
F_209 ( V_2 ) ;
}
}
F_211 ( & V_187 -> V_12 , & V_205 -> V_209 ) ;
F_169 ( V_187 , true ) ;
} else {
F_24 ( V_2 -> V_49 ) ;
F_168 ( V_2 , V_187 , V_176 ) ;
F_25 ( V_2 ) ;
V_221:
F_26 ( V_2 -> V_49 ) ;
}
}
static inline void F_212 ( struct V_27 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_225 ;
if ( F_213 ( V_27 ) && V_9 != V_9 -> V_226 ) {
struct V_177 * V_227 = V_9 -> V_228 ;
V_27 -> V_35 . V_202 += V_227 -> V_229 ;
V_27 -> V_225 = V_9 -> V_226 ;
F_214 ( F_3 ( V_27 -> V_225 ) , V_27 ,
V_9 -> V_230 ,
V_27 -> V_35 . V_202 - V_227 -> V_229 ) ;
}
}
static void F_215 ( struct V_27 * V_27 )
{
char V_231 [ V_232 ] ;
F_17 ( V_40 L_10 ) ;
F_17 ( V_40 L_11 ,
F_216 ( V_27 -> V_225 , V_231 ) ,
V_27 -> V_143 ,
( unsigned long long ) F_217 ( V_27 ) ,
( long long ) ( F_218 ( V_27 -> V_225 -> V_233 ) >> 9 ) ) ;
F_13 ( V_234 , & V_27 -> V_30 ) ;
}
static int T_4 F_219 ( char * V_235 )
{
return F_220 ( & V_236 , V_235 ) ;
}
static bool F_221 ( struct V_177 * V_26 , unsigned int V_237 )
{
return V_26 -> V_238 && F_222 ( & V_236 , V_237 ) ;
}
static int T_4 F_223 ( void )
{
struct V_239 * V_240 = F_224 ( L_12 ,
NULL , & V_236 ) ;
return F_225 ( V_240 ) ;
}
static inline bool F_221 ( struct V_177 * V_26 ,
unsigned int V_237 )
{
return false ;
}
static inline int F_226 ( struct V_27 * V_27 , unsigned int V_241 )
{
V_16 V_242 ;
if ( ! V_241 )
return 0 ;
V_242 = F_218 ( V_27 -> V_225 -> V_233 ) >> 9 ;
if ( V_242 ) {
V_16 V_243 = V_27 -> V_35 . V_202 ;
if ( V_242 < V_241 || V_242 - V_241 < V_243 ) {
F_215 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_227 ( struct V_27 * V_27 )
{
struct V_1 * V_2 ;
int V_241 = F_213 ( V_27 ) ;
int V_100 = - V_31 ;
char V_231 [ V_232 ] ;
struct V_177 * V_26 ;
F_228 () ;
if ( F_226 ( V_27 , V_241 ) )
goto V_244;
V_2 = F_3 ( V_27 -> V_225 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_245
L_13
L_14 ,
F_216 ( V_27 -> V_225 , V_231 ) ,
( long long ) V_27 -> V_35 . V_202 ) ;
goto V_244;
}
if ( F_28 ( F_229 ( V_27 ) &&
V_241 > F_230 ( V_2 ) ) ) {
F_17 ( V_245 L_15 ,
F_216 ( V_27 -> V_225 , V_231 ) ,
F_213 ( V_27 ) ,
F_230 ( V_2 ) ) ;
goto V_244;
}
V_26 = V_27 -> V_225 -> V_228 ;
if ( F_221 ( V_26 , V_27 -> V_35 . V_36 ) ||
F_221 ( & F_175 ( V_26 ) -> V_184 ,
V_27 -> V_35 . V_36 ) )
goto V_244;
F_212 ( V_27 ) ;
if ( F_226 ( V_27 , V_241 ) )
goto V_244;
if ( ( V_27 -> V_143 & ( V_144 | V_145 ) ) && ! V_2 -> V_246 ) {
V_27 -> V_143 &= ~ ( V_144 | V_145 ) ;
if ( ! V_241 ) {
V_100 = 0 ;
goto V_244;
}
}
if ( ( V_27 -> V_143 & V_247 ) &&
( ! F_231 ( V_2 ) ||
( ( V_27 -> V_143 & V_248 ) && ! F_232 ( V_2 ) ) ) ) {
V_100 = - V_249 ;
goto V_244;
}
if ( V_27 -> V_143 & V_250 && ! F_233 ( V_27 -> V_225 ) ) {
V_100 = - V_249 ;
goto V_244;
}
F_150 ( V_251 , V_2 -> V_96 ) ;
if ( F_234 ( V_2 , V_27 ) )
return false ;
F_235 ( V_2 , V_27 ) ;
return true ;
V_244:
F_15 ( V_27 , V_100 ) ;
return false ;
}
void F_236 ( struct V_27 * V_27 )
{
struct V_252 V_253 ;
if ( ! F_227 ( V_27 ) )
return;
if ( V_147 -> V_252 ) {
F_237 ( V_147 -> V_252 , V_27 ) ;
return;
}
F_149 ( V_27 -> V_200 ) ;
F_238 ( & V_253 ) ;
V_147 -> V_252 = & V_253 ;
do {
struct V_1 * V_2 = F_3 ( V_27 -> V_225 ) ;
V_2 -> V_254 ( V_2 , V_27 ) ;
V_27 = F_239 ( V_147 -> V_252 ) ;
} while ( V_27 );
V_147 -> V_252 = NULL ;
}
void F_240 ( int V_170 , struct V_27 * V_27 )
{
V_27 -> V_143 |= V_170 ;
if ( F_241 ( V_27 ) ) {
unsigned int V_88 ;
if ( F_12 ( V_170 & V_250 ) )
V_88 = F_242 ( V_27 -> V_225 ) >> 9 ;
else
V_88 = F_213 ( V_27 ) ;
if ( V_170 & V_172 ) {
F_243 ( V_255 , V_88 ) ;
} else {
F_244 ( V_27 -> V_35 . V_36 ) ;
F_243 ( V_256 , V_88 ) ;
}
if ( F_12 ( V_257 ) ) {
char V_231 [ V_232 ] ;
F_17 ( V_258 L_16 ,
V_147 -> V_259 , F_245 ( V_147 ) ,
( V_170 & V_172 ) ? L_17 : L_18 ,
( unsigned long long ) V_27 -> V_35 . V_202 ,
F_216 ( V_27 -> V_225 , V_231 ) ,
V_88 ) ;
}
}
F_236 ( V_27 ) ;
}
int F_246 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( ! F_247 ( V_11 ) )
return 0 ;
if ( F_19 ( V_11 ) > F_248 ( V_2 , V_11 -> V_32 ) ) {
F_17 ( V_245 L_19 , V_165 ) ;
return - V_31 ;
}
F_249 ( V_11 ) ;
if ( V_11 -> V_197 > F_250 ( V_2 ) ) {
F_17 ( V_245 L_20 , V_165 ) ;
return - V_31 ;
}
return 0 ;
}
int F_251 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
unsigned long V_61 ;
int V_176 = V_260 ;
if ( F_246 ( V_2 , V_11 ) )
return - V_31 ;
if ( V_11 -> V_41 &&
F_221 ( & V_11 -> V_41 -> V_184 , F_21 ( V_11 ) ) )
return - V_31 ;
F_48 ( V_2 -> V_49 , V_61 ) ;
if ( F_12 ( F_101 ( V_2 ) ) ) {
F_49 ( V_2 -> V_49 , V_61 ) ;
return - V_154 ;
}
F_149 ( F_166 ( V_11 ) ) ;
if ( V_11 -> V_32 & ( V_144 | V_145 ) )
V_176 = V_219 ;
F_168 ( V_2 , V_11 , V_176 ) ;
if ( V_176 == V_219 )
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return 0 ;
}
unsigned int F_252 ( const struct V_10 * V_11 )
{
unsigned int V_198 = V_11 -> V_32 & V_199 ;
unsigned int V_237 = 0 ;
struct V_27 * V_27 ;
if ( ! ( V_11 -> V_32 & V_261 ) )
return F_21 ( V_11 ) ;
for ( V_27 = V_11 -> V_27 ; V_27 ; V_27 = V_27 -> V_200 ) {
if ( ( V_27 -> V_143 & V_198 ) != V_198 )
break;
V_237 += V_27 -> V_35 . V_36 ;
}
F_149 ( F_21 ( V_11 ) && ! V_237 ) ;
return V_237 ;
}
void F_253 ( struct V_10 * V_187 , unsigned int V_237 )
{
if ( F_254 ( V_187 ) ) {
const int V_170 = F_255 ( V_187 ) ;
struct V_177 * V_26 ;
int V_14 ;
V_14 = F_256 () ;
V_26 = V_187 -> V_26 ;
F_257 ( V_14 , V_26 , V_262 [ V_170 ] , V_237 >> 9 ) ;
F_258 () ;
}
}
void F_259 ( struct V_10 * V_187 )
{
if ( F_254 ( V_187 ) && ! ( V_187 -> V_32 & V_37 ) ) {
unsigned long V_263 = V_25 - V_187 -> V_24 ;
const int V_170 = F_255 ( V_187 ) ;
struct V_177 * V_26 ;
int V_14 ;
V_14 = F_256 () ;
V_26 = V_187 -> V_26 ;
F_260 ( V_14 , V_26 , V_264 [ V_170 ] ) ;
F_257 ( V_14 , V_26 , V_265 [ V_170 ] , V_263 ) ;
F_174 ( V_14 , V_26 ) ;
F_261 ( V_26 , V_170 ) ;
F_262 ( V_26 ) ;
F_258 () ;
}
}
static struct V_10 * F_263 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( V_2 -> V_166 && ( V_2 -> V_266 == V_267 ||
( V_2 -> V_266 != V_268 && ! ( V_11 -> V_32 & V_185 ) ) ) )
return NULL ;
else
return V_11 ;
}
static inline struct V_10 * F_263 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
return V_11 ;
}
void F_169 ( struct V_10 * V_11 , bool V_269 )
{
struct V_177 * V_26 ;
int V_170 = F_255 ( V_11 ) ;
int V_14 ;
if ( ! F_254 ( V_11 ) )
return;
V_14 = F_256 () ;
if ( ! V_269 ) {
V_26 = V_11 -> V_26 ;
F_260 ( V_14 , V_26 , V_270 [ V_170 ] ) ;
} else {
V_26 = F_264 ( V_11 -> V_41 , F_18 ( V_11 ) ) ;
if ( ! F_265 ( V_26 ) ) {
V_26 = & V_11 -> V_41 -> V_184 ;
F_266 ( V_26 ) ;
}
F_174 ( V_14 , V_26 ) ;
F_267 ( V_26 , V_170 ) ;
V_11 -> V_26 = V_26 ;
}
F_258 () ;
}
struct V_10 * F_268 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_174 ;
while ( ( V_11 = F_269 ( V_2 ) ) != NULL ) {
V_11 = F_263 ( V_2 , V_11 ) ;
if ( ! V_11 )
break;
if ( ! ( V_11 -> V_32 & V_271 ) ) {
if ( V_11 -> V_32 & V_272 )
F_270 ( V_2 , V_11 ) ;
V_11 -> V_32 |= V_271 ;
F_271 ( V_2 , V_11 ) ;
}
if ( ! V_2 -> V_273 || V_2 -> V_273 == V_11 ) {
V_2 -> V_274 = F_272 ( V_11 ) ;
V_2 -> V_273 = NULL ;
}
if ( V_11 -> V_32 & V_275 )
break;
if ( V_2 -> V_276 && F_21 ( V_11 ) ) {
V_11 -> V_197 ++ ;
}
if ( ! V_2 -> V_127 )
break;
V_174 = V_2 -> V_127 ( V_2 , V_11 ) ;
if ( V_174 == V_277 ) {
break;
} else if ( V_174 == V_278 ) {
if ( V_2 -> V_276 && F_21 ( V_11 ) &&
! ( V_11 -> V_32 & V_275 ) ) {
-- V_11 -> V_197 ;
}
V_11 = NULL ;
break;
} else if ( V_174 == V_279 ) {
V_11 -> V_32 |= V_33 ;
F_273 ( V_11 ) ;
F_274 ( V_11 , - V_31 ) ;
} else {
F_17 ( V_245 L_21 , V_165 , V_174 ) ;
break;
}
}
return V_11 ;
}
void F_275 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_149 ( F_56 ( & V_11 -> V_12 ) ) ;
F_149 ( F_182 ( V_11 ) ) ;
F_276 ( & V_11 -> V_12 ) ;
if ( F_277 ( V_11 ) ) {
V_2 -> V_71 [ F_278 ( V_11 ) ] ++ ;
F_279 ( V_11 ) ;
}
}
void F_273 ( struct V_10 * V_187 )
{
F_275 ( V_187 ) ;
V_187 -> V_196 = F_21 ( V_187 ) ;
if ( F_12 ( F_280 ( V_187 ) ) )
V_187 -> V_280 -> V_196 = F_21 ( V_187 -> V_280 ) ;
F_149 ( F_11 ( V_281 , & V_187 -> V_282 ) ) ;
F_281 ( V_187 ) ;
}
struct V_10 * F_282 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_268 ( V_2 ) ;
if ( V_11 )
F_273 ( V_11 ) ;
return V_11 ;
}
bool F_283 ( struct V_10 * V_187 , int error , unsigned int V_283 )
{
int V_284 ;
F_284 ( V_187 -> V_2 , V_187 , V_283 ) ;
if ( ! V_187 -> V_27 )
return false ;
if ( V_187 -> V_43 == V_213 )
V_187 -> V_216 = 0 ;
if ( error && V_187 -> V_43 == V_213 &&
! ( V_187 -> V_32 & V_33 ) ) {
char * V_285 ;
switch ( error ) {
case - V_286 :
V_285 = L_22 ;
break;
case - V_287 :
V_285 = L_23 ;
break;
case - V_288 :
V_285 = L_24 ;
break;
case - V_289 :
V_285 = L_25 ;
break;
case - V_290 :
V_285 = L_26 ;
break;
case - V_291 :
V_285 = L_27 ;
break;
case - V_31 :
default:
V_285 = L_28 ;
break;
}
F_137 ( V_245 L_29 ,
V_165 , V_285 , V_187 -> V_41 ?
V_187 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_18 ( V_187 ) ) ;
}
F_253 ( V_187 , V_283 ) ;
V_284 = 0 ;
while ( V_187 -> V_27 ) {
struct V_27 * V_27 = V_187 -> V_27 ;
unsigned V_292 = F_285 ( V_27 -> V_35 . V_36 , V_283 ) ;
if ( V_292 == V_27 -> V_35 . V_36 )
V_187 -> V_27 = V_27 -> V_200 ;
F_9 ( V_187 , V_27 , V_292 , error ) ;
V_284 += V_292 ;
V_283 -= V_292 ;
if ( ! V_283 )
break;
}
if ( ! V_187 -> V_27 ) {
V_187 -> V_175 = 0 ;
return false ;
}
V_187 -> V_175 -= V_284 ;
if ( V_187 -> V_43 == V_213 )
V_187 -> V_15 += V_284 >> 9 ;
if ( V_187 -> V_32 & V_261 ) {
V_187 -> V_32 &= ~ V_199 ;
V_187 -> V_32 |= V_187 -> V_27 -> V_143 & V_199 ;
}
if ( F_21 ( V_187 ) < F_286 ( V_187 ) ) {
F_16 ( V_187 , L_30 ) ;
V_187 -> V_175 = F_286 ( V_187 ) ;
}
F_249 ( V_187 ) ;
return true ;
}
static bool F_287 ( struct V_10 * V_11 , int error ,
unsigned int V_283 ,
unsigned int V_293 )
{
if ( F_283 ( V_11 , error , V_283 ) )
return true ;
if ( F_12 ( F_280 ( V_11 ) ) &&
F_283 ( V_11 -> V_280 , error , V_293 ) )
return true ;
if ( F_288 ( V_11 -> V_2 ) )
F_289 ( V_11 -> V_41 ) ;
return false ;
}
void F_290 ( struct V_10 * V_187 )
{
struct V_1 * V_2 = V_187 -> V_2 ;
V_187 -> V_32 &= ~ V_275 ;
if ( V_2 -> V_128 )
V_2 -> V_128 ( V_2 , V_187 ) ;
}
void F_291 ( struct V_10 * V_187 , int error )
{
if ( F_164 ( V_187 ) )
F_165 ( V_187 -> V_2 , V_187 ) ;
F_149 ( F_166 ( V_187 ) ) ;
if ( F_12 ( V_294 ) && V_187 -> V_43 == V_213 )
F_292 ( & V_187 -> V_2 -> V_7 ) ;
F_161 ( V_187 ) ;
if ( V_187 -> V_32 & V_275 )
F_290 ( V_187 ) ;
F_259 ( V_187 ) ;
if ( V_187 -> V_244 )
V_187 -> V_244 ( V_187 , error ) ;
else {
if ( F_280 ( V_187 ) )
F_178 ( V_187 -> V_280 -> V_2 , V_187 -> V_280 ) ;
F_178 ( V_187 -> V_2 , V_187 ) ;
}
}
static bool F_293 ( struct V_10 * V_11 , int error ,
unsigned int V_283 , unsigned int V_293 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_61 ;
if ( F_287 ( V_11 , error , V_283 , V_293 ) )
return true ;
F_48 ( V_2 -> V_49 , V_61 ) ;
F_291 ( V_11 , error ) ;
F_49 ( V_2 -> V_49 , V_61 ) ;
return false ;
}
bool F_294 ( struct V_10 * V_11 , int error ,
unsigned int V_283 , unsigned int V_293 )
{
if ( F_287 ( V_11 , error , V_283 , V_293 ) )
return true ;
F_291 ( V_11 , error ) ;
return false ;
}
bool F_295 ( struct V_10 * V_11 , int error , unsigned int V_283 )
{
return F_293 ( V_11 , error , V_283 , 0 ) ;
}
void F_296 ( struct V_10 * V_11 , int error )
{
bool V_295 ;
unsigned int V_293 = 0 ;
if ( F_12 ( F_280 ( V_11 ) ) )
V_293 = F_21 ( V_11 -> V_280 ) ;
V_295 = F_293 ( V_11 , error , F_21 ( V_11 ) , V_293 ) ;
F_149 ( V_295 ) ;
}
bool F_297 ( struct V_10 * V_11 , int error )
{
return F_295 ( V_11 , error , F_286 ( V_11 ) ) ;
}
bool F_298 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_295 ( V_11 , error , F_252 ( V_11 ) ) ;
}
bool F_299 ( struct V_10 * V_11 , int error , unsigned int V_283 )
{
return F_294 ( V_11 , error , V_283 , 0 ) ;
}
void F_274 ( struct V_10 * V_11 , int error )
{
bool V_295 ;
unsigned int V_293 = 0 ;
if ( F_12 ( F_280 ( V_11 ) ) )
V_293 = F_21 ( V_11 -> V_280 ) ;
V_295 = F_294 ( V_11 , error , F_21 ( V_11 ) , V_293 ) ;
F_149 ( V_295 ) ;
}
bool F_300 ( struct V_10 * V_11 , int error )
{
return F_299 ( V_11 , error , F_286 ( V_11 ) ) ;
}
bool F_301 ( struct V_10 * V_11 , int error )
{
F_33 ( error >= 0 ) ;
return F_299 ( V_11 , error , F_252 ( V_11 ) ) ;
}
void F_198 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_27 * V_27 )
{
V_11 -> V_32 |= V_27 -> V_143 & V_296 ;
if ( F_241 ( V_27 ) )
V_11 -> V_197 = F_302 ( V_2 , V_27 ) ;
V_11 -> V_175 = V_27 -> V_35 . V_36 ;
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
if ( V_27 -> V_225 )
V_11 -> V_41 = V_27 -> V_225 -> V_297 ;
}
void F_303 ( struct V_10 * V_11 )
{
struct V_298 V_299 ;
struct V_300 V_301 ;
F_304 (bvec, rq, iter)
F_305 ( V_301 . V_191 ) ;
}
int F_306 ( struct V_1 * V_2 )
{
if ( V_2 -> V_302 )
return V_2 -> V_302 ( V_2 ) ;
return 0 ;
}
void F_307 ( struct V_10 * V_11 )
{
struct V_27 * V_27 ;
while ( ( V_27 = V_11 -> V_27 ) != NULL ) {
V_11 -> V_27 = V_27 -> V_200 ;
F_308 ( V_27 ) ;
}
}
static void F_309 ( struct V_10 * V_303 , struct V_10 * V_304 )
{
V_303 -> V_14 = V_304 -> V_14 ;
V_303 -> V_32 = ( V_304 -> V_32 & V_305 ) | V_306 ;
V_303 -> V_43 = V_304 -> V_43 ;
V_303 -> V_15 = F_18 ( V_304 ) ;
V_303 -> V_175 = F_21 ( V_304 ) ;
V_303 -> V_197 = V_304 -> V_197 ;
V_303 -> V_201 = V_304 -> V_201 ;
V_303 -> V_307 = V_304 -> V_307 ;
}
int F_310 ( struct V_10 * V_11 , struct V_10 * V_308 ,
struct V_309 * V_310 , T_2 V_86 ,
int (* F_311)( struct V_27 * , struct V_27 * , void * ) ,
void * V_311 )
{
struct V_27 * V_27 , * V_312 ;
if ( ! V_310 )
V_310 = V_313 ;
F_4 ( NULL , V_11 ) ;
F_312 (bio_src, rq_src) {
V_27 = F_313 ( V_312 , V_86 , V_310 ) ;
if ( ! V_27 )
goto V_314;
if ( F_311 && F_311 ( V_27 , V_312 , V_311 ) )
goto V_314;
if ( V_11 -> V_27 ) {
V_11 -> V_44 -> V_200 = V_27 ;
V_11 -> V_44 = V_27 ;
} else
V_11 -> V_27 = V_11 -> V_44 = V_27 ;
}
F_309 ( V_11 , V_308 ) ;
return 0 ;
V_314:
if ( V_27 )
F_308 ( V_27 ) ;
F_307 ( V_11 ) ;
return - V_97 ;
}
int F_314 ( struct V_46 * V_47 )
{
return F_315 ( V_51 , V_47 ) ;
}
int F_316 ( struct V_315 * V_316 ,
unsigned long V_317 )
{
return F_30 ( V_51 , V_316 , V_317 ) ;
}
int F_317 ( int V_14 , struct V_315 * V_316 ,
unsigned long V_317 )
{
return F_318 ( V_14 , V_51 , V_316 , V_317 ) ;
}
void F_319 ( struct V_204 * V_205 )
{
struct V_318 * V_319 = V_147 ;
F_5 ( & V_205 -> V_209 ) ;
F_5 ( & V_205 -> V_208 ) ;
F_5 ( & V_205 -> V_320 ) ;
if ( ! V_319 -> V_205 ) {
V_319 -> V_205 = V_205 ;
}
}
static int F_320 ( void * V_321 , struct V_206 * V_322 , struct V_206 * V_231 )
{
struct V_10 * V_323 = F_23 ( V_322 , struct V_10 , V_12 ) ;
struct V_10 * V_324 = F_23 ( V_231 , struct V_10 , V_12 ) ;
return ! ( V_323 -> V_2 < V_324 -> V_2 ||
( V_323 -> V_2 == V_324 -> V_2 && F_18 ( V_323 ) < F_18 ( V_324 ) ) ) ;
}
static void F_321 ( struct V_1 * V_2 , unsigned int V_325 ,
bool V_326 )
__releases( V_2 -> V_49 )
{
F_322 ( V_2 , V_325 , ! V_326 ) ;
if ( V_326 )
F_45 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_323 ( V_2 -> V_49 ) ;
}
static void F_324 ( struct V_204 * V_205 , bool V_326 )
{
F_325 ( V_327 ) ;
while ( ! F_56 ( & V_205 -> V_320 ) ) {
F_326 ( & V_205 -> V_320 , & V_327 ) ;
while ( ! F_56 ( & V_327 ) ) {
struct V_328 * V_329 = F_327 ( & V_327 ,
struct V_328 ,
V_209 ) ;
F_328 ( & V_329 -> V_209 ) ;
V_329 -> V_330 ( V_329 , V_326 ) ;
}
}
}
struct V_328 * F_329 ( T_6 V_331 , void * V_311 ,
int V_332 )
{
struct V_204 * V_205 = V_147 -> V_205 ;
struct V_328 * V_329 ;
if ( ! V_205 )
return NULL ;
F_330 (cb, &plug->cb_list, list)
if ( V_329 -> V_330 == V_331 && V_329 -> V_311 == V_311 )
return V_329 ;
F_149 ( V_332 < sizeof( * V_329 ) ) ;
V_329 = F_331 ( V_332 , V_251 ) ;
if ( V_329 ) {
V_329 -> V_311 = V_311 ;
V_329 -> V_330 = V_331 ;
F_332 ( & V_329 -> V_209 , & V_205 -> V_320 ) ;
}
return V_329 ;
}
void F_210 ( struct V_204 * V_205 , bool V_326 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
struct V_10 * V_11 ;
F_325 ( V_209 ) ;
unsigned int V_325 ;
F_324 ( V_205 , V_326 ) ;
if ( ! F_56 ( & V_205 -> V_208 ) )
F_333 ( V_205 , V_326 ) ;
if ( F_56 ( & V_205 -> V_209 ) )
return;
F_326 ( & V_205 -> V_209 , & V_209 ) ;
F_334 ( NULL , & V_209 , F_320 ) ;
V_2 = NULL ;
V_325 = 0 ;
F_335 ( V_61 ) ;
while ( ! F_56 ( & V_209 ) ) {
V_11 = F_336 ( V_209 . V_333 ) ;
F_276 ( & V_11 -> V_12 ) ;
F_149 ( ! V_11 -> V_2 ) ;
if ( V_11 -> V_2 != V_2 ) {
if ( V_2 )
F_321 ( V_2 , V_325 , V_326 ) ;
V_2 = V_11 -> V_2 ;
V_325 = 0 ;
F_337 ( V_2 -> V_49 ) ;
}
if ( F_12 ( F_101 ( V_2 ) ) ) {
F_274 ( V_11 , - V_154 ) ;
continue;
}
if ( V_11 -> V_32 & ( V_144 | V_145 ) )
F_170 ( V_2 , V_11 , V_219 ) ;
else
F_170 ( V_2 , V_11 , V_334 ) ;
V_325 ++ ;
}
if ( V_2 )
F_321 ( V_2 , V_325 , V_326 ) ;
F_338 ( V_61 ) ;
}
void F_339 ( struct V_204 * V_205 )
{
F_210 ( V_205 , false ) ;
if ( V_205 == V_147 -> V_205 )
V_147 -> V_205 = NULL ;
}
void F_340 ( struct V_1 * V_2 , struct V_335 * V_166 )
{
V_2 -> V_166 = V_166 ;
V_2 -> V_266 = V_268 ;
F_341 ( V_2 -> V_166 , - 1 ) ;
F_342 ( V_2 -> V_166 ) ;
}
int F_343 ( struct V_1 * V_2 )
{
int V_174 = 0 ;
F_24 ( V_2 -> V_49 ) ;
if ( V_2 -> V_186 ) {
V_174 = - V_336 ;
F_177 ( V_2 -> V_166 ) ;
} else {
V_2 -> V_266 = V_337 ;
}
F_26 ( V_2 -> V_49 ) ;
return V_174 ;
}
void F_344 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_100 ) {
V_2 -> V_266 = V_267 ;
} else {
V_2 -> V_266 = V_268 ;
F_177 ( V_2 -> V_166 ) ;
}
F_26 ( V_2 -> V_49 ) ;
}
void F_345 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_49 ) ;
V_2 -> V_266 = V_338 ;
F_26 ( V_2 -> V_49 ) ;
}
void F_346 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_49 ) ;
if ( ! V_100 ) {
V_2 -> V_266 = V_268 ;
F_25 ( V_2 ) ;
F_177 ( V_2 -> V_166 ) ;
F_347 ( V_2 -> V_166 ) ;
} else {
V_2 -> V_266 = V_267 ;
}
F_26 ( V_2 -> V_49 ) ;
}
int T_4 F_348 ( void )
{
F_349 ( V_339 > 8 *
sizeof( ( (struct V_10 * ) 0 ) -> V_32 ) ) ;
V_51 = F_350 ( L_31 ,
V_340 | V_341 , 0 ) ;
if ( ! V_51 )
F_351 ( L_32 ) ;
V_95 = F_352 ( L_33 ,
sizeof( struct V_10 ) , 0 , V_342 , NULL ) ;
V_101 = F_352 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_342 , NULL ) ;
return 0 ;
}
