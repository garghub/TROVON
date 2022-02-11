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
V_35 -> V_37 = error ;
if ( F_15 ( V_19 -> V_38 & V_39 ) )
F_16 ( V_35 , V_40 ) ;
F_17 ( V_35 , V_36 ) ;
if ( V_35 -> V_41 . V_42 == 0 && ! ( V_19 -> V_38 & V_43 ) )
F_18 ( V_35 ) ;
}
void F_19 ( struct V_18 * V_19 , char * V_44 )
{
int V_45 ;
F_20 ( V_46 L_1 , V_44 ,
V_19 -> V_47 ? V_19 -> V_47 -> V_48 : L_2 , V_19 -> V_49 ,
( unsigned long long ) V_19 -> V_38 ) ;
F_20 ( V_46 L_3 ,
( unsigned long long ) F_21 ( V_19 ) ,
F_22 ( V_19 ) , F_23 ( V_19 ) ) ;
F_20 ( V_46 L_4 ,
V_19 -> V_35 , V_19 -> V_50 , F_24 ( V_19 ) ) ;
if ( V_19 -> V_49 == V_51 ) {
F_20 ( V_46 L_5 ) ;
for ( V_45 = 0 ; V_45 < V_30 ; V_45 ++ )
F_20 ( L_6 , V_19 -> V_27 [ V_45 ] ) ;
F_20 ( L_7 ) ;
}
}
static void F_25 ( struct V_52 * V_53 )
{
struct V_11 * V_6 ;
V_6 = F_26 ( V_53 , struct V_11 , V_54 . V_53 ) ;
F_27 ( V_6 -> V_55 ) ;
F_28 ( V_6 ) ;
F_29 ( V_6 -> V_55 ) ;
}
void F_30 ( struct V_11 * V_6 , unsigned long V_56 )
{
if ( F_31 ( ! F_32 ( V_6 ) ) )
F_33 ( V_57 , & V_6 -> V_54 ,
F_34 ( V_56 ) ) ;
}
void F_35 ( struct V_11 * V_6 )
{
F_36 ( ! F_37 () ) ;
F_38 ( V_58 , V_6 ) ;
F_28 ( V_6 ) ;
}
void F_39 ( struct V_11 * V_6 )
{
F_40 ( & V_6 -> V_54 ) ;
F_41 ( V_58 , V_6 ) ;
}
void F_42 ( struct V_11 * V_6 )
{
F_43 ( & V_6 -> V_59 ) ;
if ( V_6 -> V_60 ) {
struct V_61 * V_62 ;
int V_63 ;
F_44 (q, hctx, i) {
F_45 ( & V_62 -> V_64 ) ;
F_45 ( & V_62 -> V_54 ) ;
}
} else {
F_45 ( & V_6 -> V_54 ) ;
}
}
inline void F_46 ( struct V_11 * V_6 )
{
if ( F_15 ( F_32 ( V_6 ) ) )
return;
V_6 -> V_65 ++ ;
V_6 -> V_66 ( V_6 ) ;
V_6 -> V_65 -- ;
}
void F_28 ( struct V_11 * V_6 )
{
if ( F_15 ( F_47 ( V_6 ) ) )
return;
F_46 ( V_6 ) ;
}
void F_48 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_47 ( V_6 ) && ! F_32 ( V_6 ) ) )
F_49 ( V_57 , & V_6 -> V_54 , 0 ) ;
}
void F_50 ( struct V_11 * V_6 )
{
unsigned long V_67 ;
F_51 ( V_6 -> V_55 , V_67 ) ;
F_28 ( V_6 ) ;
F_52 ( V_6 -> V_55 , V_67 ) ;
}
void F_53 ( struct V_11 * V_6 )
{
F_54 ( & V_6 -> V_68 ) ;
}
static void F_55 ( struct V_11 * V_6 , bool V_69 )
__releases( V_6 -> V_55 )
__acquires( V_6 -> V_55 )
{
int V_63 ;
F_56 ( V_6 -> V_55 ) ;
while ( true ) {
bool V_70 = false ;
if ( V_6 -> V_71 )
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
if ( ! F_59 ( & V_6 -> V_72 ) && V_6 -> V_66 )
F_28 ( V_6 ) ;
V_70 |= V_6 -> V_73 ;
V_70 |= V_6 -> V_65 ;
if ( V_69 ) {
struct V_74 * V_75 = F_60 ( V_6 , NULL ) ;
V_70 |= ! F_59 ( & V_6 -> V_72 ) ;
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
V_70 |= V_6 -> V_76 [ V_63 ] ;
V_70 |= V_6 -> V_77 [ V_63 ] ;
if ( V_75 )
V_70 |= ! F_59 ( & V_75 -> V_78 [ V_63 ] ) ;
}
}
if ( ! V_70 )
break;
F_29 ( V_6 -> V_55 ) ;
F_61 ( 10 ) ;
F_27 ( V_6 -> V_55 ) ;
}
if ( V_6 -> V_66 ) {
struct V_1 * V_2 ;
F_62 (rl, q)
for ( V_63 = 0 ; V_63 < F_63 ( V_2 -> V_79 ) ; V_63 ++ )
F_64 ( & V_2 -> V_79 [ V_63 ] ) ;
}
}
void F_65 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_80 ++ ;
F_41 ( V_81 , V_6 ) ;
F_29 ( V_6 -> V_55 ) ;
if ( F_66 ( V_6 ) ) {
F_27 ( V_6 -> V_55 ) ;
F_55 ( V_6 , false ) ;
F_29 ( V_6 -> V_55 ) ;
F_67 () ;
}
}
void F_68 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
if ( ! -- V_6 -> V_80 )
F_38 ( V_81 , V_6 ) ;
F_69 ( V_6 -> V_80 < 0 ) ;
F_29 ( V_6 -> V_55 ) ;
}
void F_70 ( struct V_11 * V_6 )
{
F_71 ( V_82 , V_6 ) ;
if ( V_6 -> V_60 )
F_72 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_62 (rl, q) {
if ( V_2 -> V_83 ) {
F_73 ( & V_2 -> V_79 [ V_84 ] ) ;
F_73 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
}
}
void F_74 ( struct V_11 * V_6 )
{
T_1 * V_86 = V_6 -> V_55 ;
F_75 ( & V_6 -> V_87 ) ;
F_70 ( V_6 ) ;
F_27 ( V_86 ) ;
V_6 -> V_80 ++ ;
F_41 ( V_81 , V_6 ) ;
F_41 ( V_88 , V_6 ) ;
F_41 ( V_89 , V_6 ) ;
F_41 ( V_82 , V_6 ) ;
F_29 ( V_86 ) ;
F_76 ( & V_6 -> V_87 ) ;
if ( V_6 -> V_60 ) {
F_77 ( V_6 ) ;
F_27 ( V_86 ) ;
} else {
F_27 ( V_86 ) ;
F_55 ( V_6 , true ) ;
}
F_41 ( V_90 , V_6 ) ;
F_29 ( V_86 ) ;
F_43 ( & V_6 -> V_8 . V_91 ) ;
F_42 ( V_6 ) ;
if ( V_6 -> V_60 )
F_78 ( V_6 ) ;
F_27 ( V_86 ) ;
if ( V_6 -> V_55 != & V_6 -> V_92 )
V_6 -> V_55 = & V_6 -> V_92 ;
F_29 ( V_86 ) ;
F_79 ( & V_6 -> V_8 ) ;
F_53 ( V_6 ) ;
}
static void * F_80 ( T_2 V_93 , void * V_94 )
{
int V_95 = ( int ) ( long ) V_94 ;
return F_81 ( V_96 , V_93 , V_95 ) ;
}
static void F_82 ( void * V_97 , void * V_98 )
{
F_83 ( V_96 , V_97 ) ;
}
int F_84 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_93 )
{
if ( F_15 ( V_2 -> V_83 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_99 [ V_84 ] = V_2 -> V_99 [ V_85 ] = 0 ;
V_2 -> V_100 [ V_84 ] = V_2 -> V_100 [ V_85 ] = 0 ;
F_85 ( & V_2 -> V_79 [ V_84 ] ) ;
F_85 ( & V_2 -> V_79 [ V_85 ] ) ;
V_2 -> V_83 = F_86 ( V_101 , F_80 ,
F_82 ,
( void * ) ( long ) V_6 -> V_102 , V_93 ,
V_6 -> V_102 ) ;
if ( ! V_2 -> V_83 )
return - V_103 ;
return 0 ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 )
F_88 ( V_2 -> V_83 ) ;
}
struct V_11 * F_89 ( T_2 V_93 )
{
return F_90 ( V_93 , V_104 ) ;
}
struct V_11 * F_90 ( T_2 V_93 , int V_105 )
{
struct V_11 * V_6 ;
int V_106 ;
V_6 = F_81 ( V_107 ,
V_93 | V_108 , V_105 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_109 = F_91 ( & V_110 , 0 , 0 , V_93 ) ;
if ( V_6 -> V_109 < 0 )
goto V_111;
V_6 -> V_112 = F_92 ( V_113 , 0 ) ;
if ( ! V_6 -> V_112 )
goto V_114;
V_6 -> V_8 . V_115 =
( V_116 * 1024 ) / V_117 ;
V_6 -> V_8 . V_118 = V_119 ;
V_6 -> V_8 . V_120 = L_8 ;
V_6 -> V_102 = V_105 ;
V_106 = F_93 ( & V_6 -> V_8 ) ;
if ( V_106 )
goto V_121;
F_94 ( & V_6 -> V_8 . V_91 ,
V_122 , ( unsigned long ) V_6 ) ;
F_94 ( & V_6 -> V_59 , V_123 , ( unsigned long ) V_6 ) ;
F_10 ( & V_6 -> V_72 ) ;
F_10 ( & V_6 -> V_21 ) ;
F_10 ( & V_6 -> V_124 ) ;
#ifdef F_95
F_10 ( & V_6 -> V_125 ) ;
#endif
F_96 ( & V_6 -> V_54 , F_25 ) ;
F_97 ( & V_6 -> V_68 , & V_126 ) ;
F_98 ( & V_6 -> V_87 ) ;
F_99 ( & V_6 -> V_92 ) ;
V_6 -> V_55 = & V_6 -> V_92 ;
V_6 -> V_80 = 1 ;
F_100 ( V_81 , & V_6 -> V_127 ) ;
F_85 ( & V_6 -> V_128 ) ;
if ( F_101 ( V_6 ) )
goto V_129;
return V_6 ;
V_129:
F_102 ( & V_6 -> V_8 ) ;
V_121:
F_103 ( V_6 -> V_112 ) ;
V_114:
F_104 ( & V_110 , V_6 -> V_109 ) ;
V_111:
F_83 ( V_107 , V_6 ) ;
return NULL ;
}
struct V_11 * F_105 ( T_3 * V_130 , T_1 * V_86 )
{
return F_106 ( V_130 , V_86 , V_104 ) ;
}
struct V_11 *
F_106 ( T_3 * V_130 , T_1 * V_86 , int V_105 )
{
struct V_11 * V_131 , * V_6 ;
V_131 = F_90 ( V_132 , V_105 ) ;
if ( ! V_131 )
return NULL ;
V_6 = F_107 ( V_131 , V_130 , V_86 ) ;
if ( ! V_6 )
F_74 ( V_131 ) ;
return V_6 ;
}
struct V_11 *
F_107 ( struct V_11 * V_6 , T_3 * V_130 ,
T_1 * V_86 )
{
if ( ! V_6 )
return NULL ;
V_6 -> V_75 = F_108 ( V_6 , V_104 , 0 ) ;
if ( ! V_6 -> V_75 )
return NULL ;
if ( F_84 ( & V_6 -> V_7 , V_6 , V_132 ) )
goto V_133;
V_6 -> V_66 = V_130 ;
V_6 -> V_134 = NULL ;
V_6 -> V_135 = NULL ;
V_6 -> V_127 |= V_136 ;
if ( V_86 )
V_6 -> V_55 = V_86 ;
F_109 ( V_6 , V_137 ) ;
V_6 -> V_138 = V_139 ;
F_75 ( & V_6 -> V_87 ) ;
if ( F_110 ( V_6 , NULL ) ) {
F_76 ( & V_6 -> V_87 ) ;
goto V_133;
}
F_76 ( & V_6 -> V_87 ) ;
return V_6 ;
V_133:
F_111 ( V_6 -> V_75 ) ;
return NULL ;
}
bool F_112 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_113 ( V_6 ) ) ) {
F_114 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_115 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_38 & V_140 ) {
F_116 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_141 . V_142 )
F_117 ( V_19 -> V_141 . V_142 -> V_143 ) ;
}
F_118 ( V_19 , V_2 -> V_83 ) ;
}
static inline int F_119 ( struct V_11 * V_6 , struct V_144 * V_143 )
{
if ( ! V_143 )
return 0 ;
return V_143 -> V_145 == V_6 -> V_146 ||
( V_143 -> V_145 > 0
&& F_120 ( V_33 , V_143 -> V_147 + V_148 ) ) ;
}
static void F_121 ( struct V_11 * V_6 , struct V_144 * V_143 )
{
if ( ! V_143 || F_119 ( V_6 , V_143 ) )
return;
V_143 -> V_145 = V_6 -> V_146 ;
V_143 -> V_147 = V_33 ;
}
static void F_122 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_99 [ V_3 ] < F_123 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_99 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_124 ( & V_2 -> V_79 [ V_3 ] ) )
F_73 ( & V_2 -> V_79 [ V_3 ] ) ;
F_125 ( V_2 , V_3 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , unsigned int V_67 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_3 = F_127 ( V_67 ) ;
V_6 -> V_76 [ V_3 ] -- ;
V_2 -> V_99 [ V_3 ] -- ;
if ( V_67 & V_140 )
V_6 -> V_73 -- ;
F_122 ( V_2 , V_3 ) ;
if ( F_15 ( V_2 -> V_100 [ V_3 ^ 1 ] ) )
F_122 ( V_2 , V_3 ^ 1 ) ;
}
int F_128 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_149 , V_150 ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_149 = F_129 ( V_6 ) ;
V_150 = F_123 ( V_6 ) ;
F_62 (rl, q) {
if ( V_2 -> V_99 [ V_84 ] >= V_149 )
F_4 ( V_2 , V_84 ) ;
else if ( V_2 -> V_99 [ V_84 ] < V_150 )
F_1 ( V_2 , V_84 ) ;
if ( V_2 -> V_99 [ V_85 ] >= V_149 )
F_4 ( V_2 , V_85 ) ;
else if ( V_2 -> V_99 [ V_85 ] < V_150 )
F_1 ( V_2 , V_85 ) ;
if ( V_2 -> V_99 [ V_84 ] >= V_6 -> V_13 ) {
F_130 ( V_2 , V_84 ) ;
} else {
F_125 ( V_2 , V_84 ) ;
F_73 ( & V_2 -> V_79 [ V_84 ] ) ;
}
if ( V_2 -> V_99 [ V_85 ] >= V_6 -> V_13 ) {
F_130 ( V_2 , V_85 ) ;
} else {
F_125 ( V_2 , V_85 ) ;
F_73 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
F_29 ( V_6 -> V_55 ) ;
return 0 ;
}
static bool F_131 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_151 & ( V_152 | V_153 ) )
return false ;
return true ;
}
static struct V_144 * F_132 ( struct V_35 * V_35 )
{
#ifdef F_95
if ( V_35 && V_35 -> V_154 )
return V_35 -> V_154 ;
#endif
return V_155 -> V_144 ;
}
static struct V_18 * F_133 ( struct V_1 * V_2 , int V_156 ,
struct V_35 * V_35 , T_2 V_93 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_157 * V_158 = V_6 -> V_71 -> type ;
struct V_144 * V_143 = F_132 ( V_35 ) ;
struct V_159 * V_142 = NULL ;
const bool V_160 = F_127 ( V_156 ) != 0 ;
int V_161 ;
if ( F_15 ( F_113 ( V_6 ) ) )
return F_134 ( - V_162 ) ;
V_161 = F_135 ( V_6 , V_156 ) ;
if ( V_161 == V_163 )
goto V_164;
if ( V_2 -> V_99 [ V_160 ] + 1 >= F_129 ( V_6 ) ) {
if ( V_2 -> V_99 [ V_160 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_136 ( V_2 , V_160 ) ) {
F_121 ( V_6 , V_143 ) ;
F_130 ( V_2 , V_160 ) ;
} else {
if ( V_161 != V_165
&& ! F_119 ( V_6 , V_143 ) ) {
return F_134 ( - V_103 ) ;
}
}
}
F_4 ( V_2 , V_160 ) ;
}
if ( V_2 -> V_99 [ V_160 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_134 ( - V_103 ) ;
V_6 -> V_76 [ V_160 ] ++ ;
V_2 -> V_99 [ V_160 ] ++ ;
V_2 -> V_100 [ V_160 ] = 0 ;
if ( F_131 ( V_35 ) && ! F_137 ( V_6 ) ) {
V_156 |= V_140 ;
V_6 -> V_73 ++ ;
if ( V_158 -> V_166 && V_143 )
V_142 = F_138 ( V_143 , V_6 ) ;
}
if ( F_139 ( V_6 ) )
V_156 |= V_167 ;
F_29 ( V_6 -> V_55 ) ;
V_19 = F_140 ( V_2 -> V_83 , V_93 ) ;
if ( ! V_19 )
goto V_168;
F_9 ( V_6 , V_19 ) ;
F_141 ( V_19 , V_2 ) ;
V_19 -> V_38 = V_156 | V_169 ;
if ( V_156 & V_140 ) {
if ( F_15 ( V_158 -> V_166 && ! V_142 ) ) {
if ( V_143 )
V_142 = F_142 ( V_143 , V_6 , V_93 ) ;
if ( ! V_142 )
goto V_170;
}
V_19 -> V_141 . V_142 = V_142 ;
if ( F_15 ( F_143 ( V_6 , V_19 , V_35 , V_93 ) ) )
goto V_170;
if ( V_142 )
F_144 ( V_142 -> V_143 ) ;
}
V_171:
if ( F_119 ( V_6 , V_143 ) )
V_143 -> V_145 -- ;
F_145 ( V_6 , V_35 , V_156 & 1 ) ;
return V_19 ;
V_170:
F_146 ( V_172 L_9 ,
V_173 , F_147 ( V_6 -> V_8 . V_174 ) ) ;
V_19 -> V_38 &= ~ V_140 ;
V_19 -> V_141 . V_142 = NULL ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_73 -- ;
F_29 ( V_6 -> V_55 ) ;
goto V_171;
V_168:
F_27 ( V_6 -> V_55 ) ;
F_126 ( V_2 , V_156 ) ;
V_164:
if ( F_15 ( V_2 -> V_99 [ V_160 ] == 0 ) )
V_2 -> V_100 [ V_160 ] = 1 ;
return F_134 ( - V_103 ) ;
}
static struct V_18 * F_148 ( struct V_11 * V_6 , int V_156 ,
struct V_35 * V_35 , T_2 V_93 )
{
const bool V_160 = F_127 ( V_156 ) != 0 ;
F_149 ( V_79 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_150 ( V_6 , V_35 ) ;
V_175:
V_19 = F_133 ( V_2 , V_156 , V_35 , V_93 ) ;
if ( ! F_151 ( V_19 ) )
return V_19 ;
if ( ! ( V_93 & V_176 ) || F_15 ( F_113 ( V_6 ) ) ) {
F_152 ( V_2 ) ;
return V_19 ;
}
F_153 ( & V_2 -> V_79 [ V_160 ] , & V_79 ,
V_177 ) ;
F_154 ( V_6 , V_35 , V_156 & 1 ) ;
F_29 ( V_6 -> V_55 ) ;
F_155 () ;
F_121 ( V_6 , V_155 -> V_144 ) ;
F_27 ( V_6 -> V_55 ) ;
F_156 ( & V_2 -> V_79 [ V_160 ] , & V_79 ) ;
goto V_175;
}
static struct V_18 * F_157 ( struct V_11 * V_6 , int V_178 ,
T_2 V_93 )
{
struct V_18 * V_19 ;
F_158 ( V_178 != V_179 && V_178 != V_180 ) ;
F_159 ( V_93 , V_6 -> V_102 ) ;
F_27 ( V_6 -> V_55 ) ;
V_19 = F_148 ( V_6 , V_178 , NULL , V_93 ) ;
if ( F_151 ( V_19 ) )
F_29 ( V_6 -> V_55 ) ;
return V_19 ;
}
struct V_18 * F_160 ( struct V_11 * V_6 , int V_178 , T_2 V_93 )
{
if ( V_6 -> V_60 )
return F_161 ( V_6 , V_178 , V_93 , false ) ;
else
return F_157 ( V_6 , V_178 , V_93 ) ;
}
struct V_18 * F_162 ( struct V_11 * V_6 , struct V_35 * V_35 ,
T_2 V_93 )
{
struct V_18 * V_19 = F_160 ( V_6 , F_163 ( V_35 ) , V_93 ) ;
if ( F_151 ( V_19 ) )
return V_19 ;
F_164 ( V_19 ) ;
F_165 (bio) {
struct V_35 * V_181 = V_35 ;
int V_182 ;
F_166 ( V_6 , & V_181 ) ;
V_182 = F_167 ( V_6 , V_19 , V_181 ) ;
if ( F_15 ( V_182 ) ) {
F_168 ( V_19 ) ;
return F_134 ( V_182 ) ;
}
}
return V_19 ;
}
void F_164 ( struct V_18 * V_19 )
{
V_19 -> V_49 = V_51 ;
V_19 -> V_183 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_50 = NULL ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_169 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_170 ( V_19 ) ;
F_171 ( V_19 ) ;
F_172 ( V_6 , V_19 ) ;
if ( V_19 -> V_38 & V_184 )
F_173 ( V_6 , V_19 ) ;
F_158 ( F_174 ( V_19 ) ) ;
F_175 ( V_6 , V_19 ) ;
}
static void F_176 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_185 )
{
F_177 ( V_19 , true ) ;
F_178 ( V_6 , V_19 , V_185 ) ;
}
static void F_179 ( int V_22 , struct V_186 * V_34 ,
unsigned long V_187 )
{
int V_188 ;
if ( V_187 == V_34 -> V_189 )
return;
V_188 = F_180 ( V_34 ) ;
if ( V_188 ) {
F_181 ( V_22 , V_34 , V_190 ,
V_188 * ( V_187 - V_34 -> V_189 ) ) ;
F_181 ( V_22 , V_34 , V_191 , ( V_187 - V_34 -> V_189 ) ) ;
}
V_34 -> V_189 = V_187 ;
}
void F_182 ( int V_22 , struct V_186 * V_34 )
{
unsigned long V_187 = V_33 ;
if ( V_34 -> V_192 )
F_179 ( V_22 , & F_183 ( V_34 ) -> V_193 , V_187 ) ;
F_179 ( V_22 , V_34 , V_187 ) ;
}
static void F_184 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_174 && ! ( V_19 -> V_38 & V_194 ) && ! -- V_19 -> V_6 -> V_195 )
F_185 ( V_19 -> V_6 -> V_174 ) ;
}
static inline void F_184 ( struct V_18 * V_19 ) {}
void F_186 ( struct V_11 * V_6 , struct V_18 * V_196 )
{
if ( F_15 ( ! V_6 ) )
return;
if ( V_6 -> V_60 ) {
F_187 ( V_196 ) ;
return;
}
F_184 ( V_196 ) ;
F_188 ( V_6 , V_196 ) ;
F_36 ( V_196 -> V_35 != NULL ) ;
if ( V_196 -> V_38 & V_169 ) {
unsigned int V_67 = V_196 -> V_38 ;
struct V_1 * V_2 = F_189 ( V_196 ) ;
F_158 ( ! F_59 ( & V_196 -> V_20 ) ) ;
F_158 ( F_190 ( V_196 ) ) ;
F_115 ( V_2 , V_196 ) ;
F_126 ( V_2 , V_67 ) ;
F_152 ( V_2 ) ;
}
}
void F_168 ( struct V_18 * V_196 )
{
struct V_11 * V_6 = V_196 -> V_6 ;
if ( V_6 -> V_60 )
F_187 ( V_196 ) ;
else {
unsigned long V_67 ;
F_51 ( V_6 -> V_55 , V_67 ) ;
F_186 ( V_6 , V_196 ) ;
F_52 ( V_6 -> V_55 , V_67 ) ;
}
}
void F_191 ( struct V_18 * V_19 , struct V_197 * V_197 ,
unsigned int V_198 )
{
struct V_35 * V_35 = V_19 -> V_35 ;
V_35 -> V_199 -> V_200 = V_197 ;
V_35 -> V_199 -> V_201 = 0 ;
V_35 -> V_199 -> V_202 = V_198 ;
V_35 -> V_41 . V_42 = V_198 ;
V_35 -> V_203 = 1 ;
V_35 -> V_204 = 1 ;
V_19 -> V_183 = V_19 -> V_205 = V_198 ;
V_19 -> V_206 = 1 ;
}
bool F_192 ( struct V_11 * V_6 , struct V_18 * V_196 ,
struct V_35 * V_35 )
{
const int V_207 = V_35 -> V_151 & V_208 ;
if ( ! F_193 ( V_6 , V_196 , V_35 ) )
return false ;
F_194 ( V_6 , V_196 , V_35 ) ;
if ( ( V_196 -> V_38 & V_208 ) != V_207 )
F_195 ( V_196 ) ;
V_196 -> V_50 -> V_209 = V_35 ;
V_196 -> V_50 = V_35 ;
V_196 -> V_183 += V_35 -> V_41 . V_42 ;
V_196 -> V_210 = F_196 ( V_196 -> V_210 , F_197 ( V_35 ) ) ;
F_177 ( V_196 , false ) ;
return true ;
}
bool F_198 ( struct V_11 * V_6 , struct V_18 * V_196 ,
struct V_35 * V_35 )
{
const int V_207 = V_35 -> V_151 & V_208 ;
if ( ! F_199 ( V_6 , V_196 , V_35 ) )
return false ;
F_200 ( V_6 , V_196 , V_35 ) ;
if ( ( V_196 -> V_38 & V_208 ) != V_207 )
F_195 ( V_196 ) ;
V_35 -> V_209 = V_196 -> V_35 ;
V_196 -> V_35 = V_35 ;
V_196 -> V_23 = V_35 -> V_41 . V_211 ;
V_196 -> V_183 += V_35 -> V_41 . V_42 ;
V_196 -> V_210 = F_196 ( V_196 -> V_210 , F_197 ( V_35 ) ) ;
F_177 ( V_196 , false ) ;
return true ;
}
bool F_201 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_212 ,
struct V_18 * * V_213 )
{
struct V_214 * V_215 ;
struct V_18 * V_19 ;
bool V_182 = false ;
struct V_216 * V_217 ;
V_215 = V_155 -> V_215 ;
if ( ! V_215 )
goto V_171;
* V_212 = 0 ;
if ( V_6 -> V_60 )
V_217 = & V_215 -> V_218 ;
else
V_217 = & V_215 -> V_219 ;
F_202 (rq, plug_list, queuelist) {
int V_220 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_212 ) ++ ;
if ( V_213 )
* V_213 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_203 ( V_19 , V_35 ) )
continue;
V_220 = F_204 ( V_19 , V_35 ) ;
if ( V_220 == V_221 ) {
V_182 = F_192 ( V_6 , V_19 , V_35 ) ;
if ( V_182 )
break;
} else if ( V_220 == V_222 ) {
V_182 = F_198 ( V_6 , V_19 , V_35 ) ;
if ( V_182 )
break;
}
}
V_171:
return V_182 ;
}
void F_205 ( struct V_18 * V_196 , struct V_35 * V_35 )
{
V_196 -> V_49 = V_223 ;
V_196 -> V_38 |= V_35 -> V_151 & V_224 ;
if ( V_35 -> V_151 & V_225 )
V_196 -> V_38 |= V_208 ;
V_196 -> V_226 = 0 ;
V_196 -> V_23 = V_35 -> V_41 . V_211 ;
V_196 -> V_210 = F_197 ( V_35 ) ;
F_206 ( V_196 -> V_6 , V_196 , V_35 ) ;
}
static void V_137 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
const bool V_3 = ! ! ( V_35 -> V_151 & V_227 ) ;
struct V_214 * V_215 ;
int V_220 , V_156 , V_185 = V_228 ;
struct V_18 * V_196 ;
unsigned int V_212 = 0 ;
F_207 ( V_6 , & V_35 , V_6 -> V_112 ) ;
F_166 ( V_6 , & V_35 ) ;
if ( F_208 ( V_35 ) && F_209 ( V_35 ) ) {
V_35 -> V_37 = - V_229 ;
F_18 ( V_35 ) ;
return;
}
if ( V_35 -> V_151 & ( V_152 | V_153 ) ) {
F_27 ( V_6 -> V_55 ) ;
V_185 = V_230 ;
goto V_231;
}
if ( ! F_210 ( V_6 ) &&
F_201 ( V_6 , V_35 , & V_212 , NULL ) )
return;
F_27 ( V_6 -> V_55 ) ;
V_220 = F_211 ( V_6 , & V_196 , V_35 ) ;
if ( V_220 == V_221 ) {
if ( F_192 ( V_6 , V_196 , V_35 ) ) {
F_212 ( V_6 , V_196 , V_35 ) ;
if ( ! F_213 ( V_6 , V_196 ) )
F_214 ( V_6 , V_196 , V_220 ) ;
goto V_232;
}
} else if ( V_220 == V_222 ) {
if ( F_198 ( V_6 , V_196 , V_35 ) ) {
F_212 ( V_6 , V_196 , V_35 ) ;
if ( ! F_215 ( V_6 , V_196 ) )
F_214 ( V_6 , V_196 , V_220 ) ;
goto V_232;
}
}
V_231:
V_156 = F_163 ( V_35 ) ;
if ( V_3 )
V_156 |= V_227 ;
V_196 = F_148 ( V_6 , V_156 , V_35 , V_233 ) ;
if ( F_151 ( V_196 ) ) {
V_35 -> V_37 = F_216 ( V_196 ) ;
F_18 ( V_35 ) ;
goto V_232;
}
F_205 ( V_196 , V_35 ) ;
if ( F_217 ( V_234 , & V_6 -> V_127 ) )
V_196 -> V_22 = F_218 () ;
V_215 = V_155 -> V_215 ;
if ( V_215 ) {
if ( ! V_212 )
F_219 ( V_6 ) ;
else {
if ( V_212 >= V_235 ) {
F_220 ( V_215 , false ) ;
F_219 ( V_6 ) ;
}
}
F_221 ( & V_196 -> V_20 , & V_215 -> V_219 ) ;
F_177 ( V_196 , true ) ;
} else {
F_27 ( V_6 -> V_55 ) ;
F_176 ( V_6 , V_196 , V_185 ) ;
F_28 ( V_6 ) ;
V_232:
F_29 ( V_6 -> V_55 ) ;
}
}
static inline void F_222 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_236 ;
if ( F_223 ( V_35 ) && V_17 != V_17 -> V_237 ) {
struct V_186 * V_238 = V_17 -> V_239 ;
V_35 -> V_41 . V_211 += V_238 -> V_240 ;
V_35 -> V_236 = V_17 -> V_237 ;
F_224 ( F_8 ( V_35 -> V_236 ) , V_35 ,
V_17 -> V_241 ,
V_35 -> V_41 . V_211 - V_238 -> V_240 ) ;
}
}
static void F_225 ( struct V_35 * V_35 )
{
char V_242 [ V_243 ] ;
F_20 ( V_46 L_10 ) ;
F_20 ( V_46 L_11 ,
F_226 ( V_35 -> V_236 , V_242 ) ,
V_35 -> V_151 ,
( unsigned long long ) F_227 ( V_35 ) ,
( long long ) ( F_228 ( V_35 -> V_236 -> V_244 ) >> 9 ) ) ;
}
static int T_4 F_229 ( char * V_245 )
{
return F_230 ( & V_246 , V_245 ) ;
}
static bool F_231 ( struct V_186 * V_34 , unsigned int V_247 )
{
return V_34 -> V_248 && F_232 ( & V_246 , V_247 ) ;
}
static int T_4 F_233 ( void )
{
struct V_249 * V_250 = F_234 ( L_12 ,
NULL , & V_246 ) ;
return F_235 ( V_250 ) ;
}
static inline bool F_231 ( struct V_186 * V_34 ,
unsigned int V_247 )
{
return false ;
}
static inline int F_236 ( struct V_35 * V_35 , unsigned int V_251 )
{
V_24 V_252 ;
if ( ! V_251 )
return 0 ;
V_252 = F_228 ( V_35 -> V_236 -> V_244 ) >> 9 ;
if ( V_252 ) {
V_24 V_253 = V_35 -> V_41 . V_211 ;
if ( V_252 < V_251 || V_252 - V_251 < V_253 ) {
F_225 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_237 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_251 = F_223 ( V_35 ) ;
int V_106 = - V_229 ;
char V_242 [ V_243 ] ;
struct V_186 * V_34 ;
F_238 () ;
if ( F_236 ( V_35 , V_251 ) )
goto V_254;
V_6 = F_8 ( V_35 -> V_236 ) ;
if ( F_15 ( ! V_6 ) ) {
F_20 ( V_255
L_13
L_14 ,
F_226 ( V_35 -> V_236 , V_242 ) ,
( long long ) V_35 -> V_41 . V_211 ) ;
goto V_254;
}
V_34 = V_35 -> V_236 -> V_239 ;
if ( F_231 ( V_34 , V_35 -> V_41 . V_42 ) ||
F_231 ( & F_183 ( V_34 ) -> V_193 ,
V_35 -> V_41 . V_42 ) )
goto V_254;
F_222 ( V_35 ) ;
if ( F_236 ( V_35 , V_251 ) )
goto V_254;
if ( ( V_35 -> V_151 & ( V_152 | V_153 ) ) && ! V_6 -> V_256 ) {
V_35 -> V_151 &= ~ ( V_152 | V_153 ) ;
if ( ! V_251 ) {
V_106 = 0 ;
goto V_254;
}
}
if ( ( V_35 -> V_151 & V_257 ) &&
( ! F_239 ( V_6 ) ||
( ( V_35 -> V_151 & V_258 ) && ! F_240 ( V_6 ) ) ) ) {
V_106 = - V_259 ;
goto V_254;
}
if ( V_35 -> V_151 & V_260 && ! F_241 ( V_35 -> V_236 ) ) {
V_106 = - V_259 ;
goto V_254;
}
F_159 ( V_261 , V_6 -> V_102 ) ;
if ( ! F_242 ( V_6 , V_35 ) )
return false ;
F_243 ( V_6 , V_35 ) ;
return true ;
V_254:
V_35 -> V_37 = V_106 ;
F_18 ( V_35 ) ;
return false ;
}
void F_244 ( struct V_35 * V_35 )
{
struct V_262 V_263 ;
if ( ! F_237 ( V_35 ) )
return;
if ( V_155 -> V_262 ) {
F_245 ( V_155 -> V_262 , V_35 ) ;
return;
}
F_158 ( V_35 -> V_209 ) ;
F_246 ( & V_263 ) ;
V_155 -> V_262 = & V_263 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_236 ) ;
V_6 -> V_264 ( V_6 , V_35 ) ;
V_35 = F_247 ( V_155 -> V_262 ) ;
} while ( V_35 );
V_155 -> V_262 = NULL ;
}
void F_248 ( int V_178 , struct V_35 * V_35 )
{
V_35 -> V_151 |= V_178 ;
if ( F_249 ( V_35 ) ) {
unsigned int V_99 ;
if ( F_15 ( V_178 & V_260 ) )
V_99 = F_250 ( V_35 -> V_236 ) >> 9 ;
else
V_99 = F_223 ( V_35 ) ;
if ( V_178 & V_180 ) {
F_251 ( V_265 , V_99 ) ;
} else {
F_252 ( V_35 -> V_41 . V_42 ) ;
F_251 ( V_266 , V_99 ) ;
}
if ( F_15 ( V_267 ) ) {
char V_242 [ V_243 ] ;
F_20 ( V_268 L_15 ,
V_155 -> V_269 , F_253 ( V_155 ) ,
( V_178 & V_180 ) ? L_16 : L_17 ,
( unsigned long long ) V_35 -> V_41 . V_211 ,
F_226 ( V_35 -> V_236 , V_242 ) ,
V_99 ) ;
}
}
F_244 ( V_35 ) ;
}
int F_254 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
if ( ! F_255 ( V_19 ) )
return 0 ;
if ( F_22 ( V_19 ) > F_256 ( V_6 , V_19 -> V_38 ) ) {
F_20 ( V_255 L_18 , V_173 ) ;
return - V_229 ;
}
F_257 ( V_19 ) ;
if ( V_19 -> V_206 > F_258 ( V_6 ) ) {
F_20 ( V_255 L_19 , V_173 ) ;
return - V_229 ;
}
return 0 ;
}
int F_259 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_67 ;
int V_185 = V_270 ;
if ( F_254 ( V_6 , V_19 ) )
return - V_229 ;
if ( V_19 -> V_47 &&
F_231 ( & V_19 -> V_47 -> V_193 , F_24 ( V_19 ) ) )
return - V_229 ;
if ( V_6 -> V_60 ) {
if ( F_139 ( V_6 ) )
F_177 ( V_19 , true ) ;
F_260 ( V_19 , false , true , true ) ;
return 0 ;
}
F_51 ( V_6 -> V_55 , V_67 ) ;
if ( F_15 ( F_113 ( V_6 ) ) ) {
F_52 ( V_6 -> V_55 , V_67 ) ;
return - V_162 ;
}
F_158 ( F_174 ( V_19 ) ) ;
if ( V_19 -> V_38 & ( V_152 | V_153 ) )
V_185 = V_230 ;
F_176 ( V_6 , V_19 , V_185 ) ;
if ( V_185 == V_230 )
F_28 ( V_6 ) ;
F_52 ( V_6 -> V_55 , V_67 ) ;
return 0 ;
}
unsigned int F_261 ( const struct V_18 * V_19 )
{
unsigned int V_207 = V_19 -> V_38 & V_208 ;
unsigned int V_247 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_38 & V_271 ) )
return F_24 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_209 ) {
if ( ( V_35 -> V_151 & V_207 ) != V_207 )
break;
V_247 += V_35 -> V_41 . V_42 ;
}
F_158 ( F_24 ( V_19 ) && ! V_247 ) ;
return V_247 ;
}
void F_262 ( struct V_18 * V_196 , unsigned int V_247 )
{
if ( F_263 ( V_196 ) ) {
const int V_178 = F_264 ( V_196 ) ;
struct V_186 * V_34 ;
int V_22 ;
V_22 = F_265 () ;
V_34 = V_196 -> V_34 ;
F_266 ( V_22 , V_34 , V_272 [ V_178 ] , V_247 >> 9 ) ;
F_267 () ;
}
}
void F_268 ( struct V_18 * V_196 )
{
if ( F_263 ( V_196 ) && ! ( V_196 -> V_38 & V_43 ) ) {
unsigned long V_273 = V_33 - V_196 -> V_32 ;
const int V_178 = F_264 ( V_196 ) ;
struct V_186 * V_34 ;
int V_22 ;
V_22 = F_265 () ;
V_34 = V_196 -> V_34 ;
F_269 ( V_22 , V_34 , V_274 [ V_178 ] ) ;
F_266 ( V_22 , V_34 , V_275 [ V_178 ] , V_273 ) ;
F_182 ( V_22 , V_34 ) ;
F_270 ( V_34 , V_178 ) ;
F_271 ( V_34 ) ;
F_267 () ;
}
}
static struct V_18 * F_272 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_174 && ( V_6 -> V_276 == V_277 ||
( V_6 -> V_276 != V_278 && ! ( V_19 -> V_38 & V_194 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_272 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_177 ( struct V_18 * V_19 , bool V_279 )
{
struct V_186 * V_34 ;
int V_178 = F_264 ( V_19 ) ;
int V_22 ;
if ( ! F_263 ( V_19 ) )
return;
V_22 = F_265 () ;
if ( ! V_279 ) {
V_34 = V_19 -> V_34 ;
F_269 ( V_22 , V_34 , V_280 [ V_178 ] ) ;
} else {
V_34 = F_273 ( V_19 -> V_47 , F_21 ( V_19 ) ) ;
if ( ! F_274 ( V_34 ) ) {
V_34 = & V_19 -> V_47 -> V_193 ;
F_275 ( V_34 ) ;
}
F_182 ( V_22 , V_34 ) ;
F_276 ( V_34 , V_178 ) ;
V_19 -> V_34 = V_34 ;
}
F_267 () ;
}
struct V_18 * F_277 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
int V_182 ;
while ( ( V_19 = F_278 ( V_6 ) ) != NULL ) {
V_19 = F_272 ( V_6 , V_19 ) ;
if ( ! V_19 )
break;
if ( ! ( V_19 -> V_38 & V_281 ) ) {
if ( V_19 -> V_38 & V_282 )
F_279 ( V_6 , V_19 ) ;
V_19 -> V_38 |= V_281 ;
F_280 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_283 || V_6 -> V_283 == V_19 ) {
V_6 -> V_284 = F_281 ( V_19 ) ;
V_6 -> V_283 = NULL ;
}
if ( V_19 -> V_38 & V_285 )
break;
if ( V_6 -> V_286 && F_24 ( V_19 ) ) {
V_19 -> V_206 ++ ;
}
if ( ! V_6 -> V_134 )
break;
V_182 = V_6 -> V_134 ( V_6 , V_19 ) ;
if ( V_182 == V_287 ) {
break;
} else if ( V_182 == V_288 ) {
if ( V_6 -> V_286 && F_24 ( V_19 ) &&
! ( V_19 -> V_38 & V_285 ) ) {
-- V_19 -> V_206 ;
}
V_19 = NULL ;
break;
} else if ( V_182 == V_289 ) {
V_19 -> V_38 |= V_39 ;
F_282 ( V_19 ) ;
F_283 ( V_19 , - V_229 ) ;
} else {
F_20 ( V_255 L_20 , V_173 , V_182 ) ;
break;
}
}
return V_19 ;
}
void F_284 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_158 ( F_59 ( & V_19 -> V_20 ) ) ;
F_158 ( F_190 ( V_19 ) ) ;
F_285 ( & V_19 -> V_20 ) ;
if ( F_286 ( V_19 ) ) {
V_6 -> V_77 [ F_287 ( V_19 ) ] ++ ;
F_288 ( V_19 ) ;
}
}
void F_282 ( struct V_18 * V_196 )
{
F_284 ( V_196 ) ;
V_196 -> V_205 = F_24 ( V_196 ) ;
if ( F_15 ( F_289 ( V_196 ) ) )
V_196 -> V_290 -> V_205 = F_24 ( V_196 -> V_290 ) ;
F_158 ( F_217 ( V_291 , & V_196 -> V_292 ) ) ;
F_290 ( V_196 ) ;
}
struct V_18 * F_291 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_277 ( V_6 ) ;
if ( V_19 )
F_282 ( V_19 ) ;
return V_19 ;
}
bool F_292 ( struct V_18 * V_196 , int error , unsigned int V_293 )
{
int V_294 ;
F_293 ( V_196 -> V_6 , V_196 , V_293 ) ;
if ( ! V_196 -> V_35 )
return false ;
if ( V_196 -> V_49 == V_223 )
V_196 -> V_226 = 0 ;
if ( error && V_196 -> V_49 == V_223 &&
! ( V_196 -> V_38 & V_39 ) ) {
char * V_295 ;
switch ( error ) {
case - V_296 :
V_295 = L_21 ;
break;
case - V_297 :
V_295 = L_22 ;
break;
case - V_298 :
V_295 = L_23 ;
break;
case - V_299 :
V_295 = L_24 ;
break;
case - V_300 :
V_295 = L_25 ;
break;
case - V_301 :
V_295 = L_26 ;
break;
case - V_229 :
default:
V_295 = L_27 ;
break;
}
F_146 ( V_255 L_28 ,
V_173 , V_295 , V_196 -> V_47 ?
V_196 -> V_47 -> V_48 : L_2 ,
( unsigned long long ) F_21 ( V_196 ) ) ;
}
F_262 ( V_196 , V_293 ) ;
V_294 = 0 ;
while ( V_196 -> V_35 ) {
struct V_35 * V_35 = V_196 -> V_35 ;
unsigned V_302 = F_294 ( V_35 -> V_41 . V_42 , V_293 ) ;
if ( V_302 == V_35 -> V_41 . V_42 )
V_196 -> V_35 = V_35 -> V_209 ;
F_14 ( V_196 , V_35 , V_302 , error ) ;
V_294 += V_302 ;
V_293 -= V_302 ;
if ( ! V_293 )
break;
}
if ( ! V_196 -> V_35 ) {
V_196 -> V_183 = 0 ;
return false ;
}
V_196 -> V_183 -= V_294 ;
if ( V_196 -> V_49 == V_223 )
V_196 -> V_23 += V_294 >> 9 ;
if ( V_196 -> V_38 & V_271 ) {
V_196 -> V_38 &= ~ V_208 ;
V_196 -> V_38 |= V_196 -> V_35 -> V_151 & V_208 ;
}
if ( F_24 ( V_196 ) < F_295 ( V_196 ) ) {
F_19 ( V_196 , L_29 ) ;
V_196 -> V_183 = F_295 ( V_196 ) ;
}
F_257 ( V_196 ) ;
return true ;
}
static bool F_296 ( struct V_18 * V_19 , int error ,
unsigned int V_293 ,
unsigned int V_303 )
{
if ( F_292 ( V_19 , error , V_293 ) )
return true ;
if ( F_15 ( F_289 ( V_19 ) ) &&
F_292 ( V_19 -> V_290 , error , V_303 ) )
return true ;
if ( F_297 ( V_19 -> V_6 ) )
F_298 ( V_19 -> V_47 ) ;
return false ;
}
void F_299 ( struct V_18 * V_196 )
{
struct V_11 * V_6 = V_196 -> V_6 ;
V_196 -> V_38 &= ~ V_285 ;
if ( V_6 -> V_135 )
V_6 -> V_135 ( V_6 , V_196 ) ;
}
void F_300 ( struct V_18 * V_196 , int error )
{
if ( V_196 -> V_38 & V_184 )
F_173 ( V_196 -> V_6 , V_196 ) ;
F_158 ( F_174 ( V_196 ) ) ;
if ( F_15 ( V_304 ) && V_196 -> V_49 == V_223 )
F_301 ( & V_196 -> V_6 -> V_8 ) ;
F_170 ( V_196 ) ;
if ( V_196 -> V_38 & V_285 )
F_299 ( V_196 ) ;
F_268 ( V_196 ) ;
if ( V_196 -> V_254 )
V_196 -> V_254 ( V_196 , error ) ;
else {
if ( F_289 ( V_196 ) )
F_186 ( V_196 -> V_290 -> V_6 , V_196 -> V_290 ) ;
F_186 ( V_196 -> V_6 , V_196 ) ;
}
}
static bool F_302 ( struct V_18 * V_19 , int error ,
unsigned int V_293 , unsigned int V_303 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_67 ;
if ( F_296 ( V_19 , error , V_293 , V_303 ) )
return true ;
F_51 ( V_6 -> V_55 , V_67 ) ;
F_300 ( V_19 , error ) ;
F_52 ( V_6 -> V_55 , V_67 ) ;
return false ;
}
bool F_303 ( struct V_18 * V_19 , int error ,
unsigned int V_293 , unsigned int V_303 )
{
if ( F_296 ( V_19 , error , V_293 , V_303 ) )
return true ;
F_300 ( V_19 , error ) ;
return false ;
}
bool F_304 ( struct V_18 * V_19 , int error , unsigned int V_293 )
{
return F_302 ( V_19 , error , V_293 , 0 ) ;
}
void F_305 ( struct V_18 * V_19 , int error )
{
bool V_305 ;
unsigned int V_303 = 0 ;
if ( F_15 ( F_289 ( V_19 ) ) )
V_303 = F_24 ( V_19 -> V_290 ) ;
V_305 = F_302 ( V_19 , error , F_24 ( V_19 ) , V_303 ) ;
F_158 ( V_305 ) ;
}
bool F_306 ( struct V_18 * V_19 , int error )
{
return F_304 ( V_19 , error , F_295 ( V_19 ) ) ;
}
bool F_307 ( struct V_18 * V_19 , int error )
{
F_36 ( error >= 0 ) ;
return F_304 ( V_19 , error , F_261 ( V_19 ) ) ;
}
bool F_308 ( struct V_18 * V_19 , int error , unsigned int V_293 )
{
return F_303 ( V_19 , error , V_293 , 0 ) ;
}
void F_283 ( struct V_18 * V_19 , int error )
{
bool V_305 ;
unsigned int V_303 = 0 ;
if ( F_15 ( F_289 ( V_19 ) ) )
V_303 = F_24 ( V_19 -> V_290 ) ;
V_305 = F_303 ( V_19 , error , F_24 ( V_19 ) , V_303 ) ;
F_158 ( V_305 ) ;
}
bool F_309 ( struct V_18 * V_19 , int error )
{
return F_308 ( V_19 , error , F_295 ( V_19 ) ) ;
}
bool F_310 ( struct V_18 * V_19 , int error )
{
F_36 ( error >= 0 ) ;
return F_308 ( V_19 , error , F_261 ( V_19 ) ) ;
}
void F_206 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
V_19 -> V_38 |= V_35 -> V_151 & V_306 ;
if ( F_249 ( V_35 ) )
V_19 -> V_206 = F_311 ( V_6 , V_35 ) ;
V_19 -> V_183 = V_35 -> V_41 . V_42 ;
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
if ( V_35 -> V_236 )
V_19 -> V_47 = V_35 -> V_236 -> V_307 ;
}
void F_312 ( struct V_18 * V_19 )
{
struct V_308 V_309 ;
struct V_310 V_311 ;
F_313 (bvec, rq, iter)
F_314 ( V_311 . V_200 ) ;
}
int F_315 ( struct V_11 * V_6 )
{
if ( V_6 -> V_312 )
return V_6 -> V_312 ( V_6 ) ;
return 0 ;
}
void F_316 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_209 ;
F_317 ( V_35 ) ;
}
}
static void F_318 ( struct V_18 * V_313 , struct V_18 * V_314 )
{
V_313 -> V_22 = V_314 -> V_22 ;
V_313 -> V_38 |= ( V_314 -> V_38 & V_315 ) | V_316 ;
V_313 -> V_49 = V_314 -> V_49 ;
V_313 -> V_23 = F_21 ( V_314 ) ;
V_313 -> V_183 = F_24 ( V_314 ) ;
V_313 -> V_206 = V_314 -> V_206 ;
V_313 -> V_210 = V_314 -> V_210 ;
V_313 -> V_317 = V_314 -> V_317 ;
}
int F_319 ( struct V_18 * V_19 , struct V_18 * V_318 ,
struct V_319 * V_320 , T_2 V_93 ,
int (* F_320)( struct V_35 * , struct V_35 * , void * ) ,
void * V_94 )
{
struct V_35 * V_35 , * V_321 ;
if ( ! V_320 )
V_320 = V_322 ;
F_321 (bio_src, rq_src) {
V_35 = F_322 ( V_321 , V_93 , V_320 ) ;
if ( ! V_35 )
goto V_323;
if ( F_320 && F_320 ( V_35 , V_321 , V_94 ) )
goto V_323;
if ( V_19 -> V_35 ) {
V_19 -> V_50 -> V_209 = V_35 ;
V_19 -> V_50 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
}
F_318 ( V_19 , V_318 ) ;
return 0 ;
V_323:
if ( V_35 )
F_317 ( V_35 ) ;
F_316 ( V_19 ) ;
return - V_103 ;
}
int F_323 ( struct V_52 * V_53 )
{
return F_324 ( V_57 , V_53 ) ;
}
int F_325 ( struct V_324 * V_325 ,
unsigned long V_326 )
{
return F_33 ( V_57 , V_325 , V_326 ) ;
}
int F_326 ( int V_22 , struct V_324 * V_325 ,
unsigned long V_326 )
{
return F_327 ( V_22 , V_57 , V_325 , V_326 ) ;
}
void F_328 ( struct V_214 * V_215 )
{
struct V_327 * V_328 = V_155 ;
if ( V_328 -> V_215 )
return;
F_10 ( & V_215 -> V_219 ) ;
F_10 ( & V_215 -> V_218 ) ;
F_10 ( & V_215 -> V_329 ) ;
V_328 -> V_215 = V_215 ;
}
static int F_329 ( void * V_330 , struct V_216 * V_331 , struct V_216 * V_242 )
{
struct V_18 * V_332 = F_26 ( V_331 , struct V_18 , V_20 ) ;
struct V_18 * V_333 = F_26 ( V_242 , struct V_18 , V_20 ) ;
return ! ( V_332 -> V_6 < V_333 -> V_6 ||
( V_332 -> V_6 == V_333 -> V_6 && F_21 ( V_332 ) < F_21 ( V_333 ) ) ) ;
}
static void F_330 ( struct V_11 * V_6 , unsigned int V_334 ,
bool V_335 )
__releases( V_6 -> V_55 )
{
F_331 ( V_6 , V_334 , ! V_335 ) ;
if ( V_335 )
F_48 ( V_6 ) ;
else
F_28 ( V_6 ) ;
F_332 ( V_6 -> V_55 ) ;
}
static void F_333 ( struct V_214 * V_215 , bool V_335 )
{
F_334 ( V_336 ) ;
while ( ! F_59 ( & V_215 -> V_329 ) ) {
F_335 ( & V_215 -> V_329 , & V_336 ) ;
while ( ! F_59 ( & V_336 ) ) {
struct V_337 * V_338 = F_336 ( & V_336 ,
struct V_337 ,
V_219 ) ;
F_337 ( & V_338 -> V_219 ) ;
V_338 -> V_339 ( V_338 , V_335 ) ;
}
}
}
struct V_337 * F_338 ( T_6 V_340 , void * V_94 ,
int V_341 )
{
struct V_214 * V_215 = V_155 -> V_215 ;
struct V_337 * V_338 ;
if ( ! V_215 )
return NULL ;
F_339 (cb, &plug->cb_list, list)
if ( V_338 -> V_339 == V_340 && V_338 -> V_94 == V_94 )
return V_338 ;
F_158 ( V_341 < sizeof( * V_338 ) ) ;
V_338 = F_340 ( V_341 , V_261 ) ;
if ( V_338 ) {
V_338 -> V_94 = V_94 ;
V_338 -> V_339 = V_340 ;
F_341 ( & V_338 -> V_219 , & V_215 -> V_329 ) ;
}
return V_338 ;
}
void F_220 ( struct V_214 * V_215 , bool V_335 )
{
struct V_11 * V_6 ;
unsigned long V_67 ;
struct V_18 * V_19 ;
F_334 ( V_219 ) ;
unsigned int V_334 ;
F_333 ( V_215 , V_335 ) ;
if ( ! F_59 ( & V_215 -> V_218 ) )
F_342 ( V_215 , V_335 ) ;
if ( F_59 ( & V_215 -> V_219 ) )
return;
F_335 ( & V_215 -> V_219 , & V_219 ) ;
F_343 ( NULL , & V_219 , F_329 ) ;
V_6 = NULL ;
V_334 = 0 ;
F_344 ( V_67 ) ;
while ( ! F_59 ( & V_219 ) ) {
V_19 = F_345 ( V_219 . V_342 ) ;
F_285 ( & V_19 -> V_20 ) ;
F_158 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_330 ( V_6 , V_334 , V_335 ) ;
V_6 = V_19 -> V_6 ;
V_334 = 0 ;
F_346 ( V_6 -> V_55 ) ;
}
if ( F_15 ( F_113 ( V_6 ) ) ) {
F_283 ( V_19 , - V_162 ) ;
continue;
}
if ( V_19 -> V_38 & ( V_152 | V_153 ) )
F_178 ( V_6 , V_19 , V_230 ) ;
else
F_178 ( V_6 , V_19 , V_343 ) ;
V_334 ++ ;
}
if ( V_6 )
F_330 ( V_6 , V_334 , V_335 ) ;
F_347 ( V_67 ) ;
}
void F_348 ( struct V_214 * V_215 )
{
if ( V_215 != V_155 -> V_215 )
return;
F_220 ( V_215 , false ) ;
V_155 -> V_215 = NULL ;
}
void F_349 ( struct V_11 * V_6 , struct V_344 * V_174 )
{
V_6 -> V_174 = V_174 ;
V_6 -> V_276 = V_278 ;
F_350 ( V_6 -> V_174 , - 1 ) ;
F_351 ( V_6 -> V_174 ) ;
}
int F_352 ( struct V_11 * V_6 )
{
int V_182 = 0 ;
F_27 ( V_6 -> V_55 ) ;
if ( V_6 -> V_195 ) {
V_182 = - V_345 ;
F_185 ( V_6 -> V_174 ) ;
} else {
V_6 -> V_276 = V_346 ;
}
F_29 ( V_6 -> V_55 ) ;
return V_182 ;
}
void F_353 ( struct V_11 * V_6 , int V_106 )
{
F_27 ( V_6 -> V_55 ) ;
if ( ! V_106 ) {
V_6 -> V_276 = V_277 ;
} else {
V_6 -> V_276 = V_278 ;
F_185 ( V_6 -> V_174 ) ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_354 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_276 = V_347 ;
F_29 ( V_6 -> V_55 ) ;
}
void F_355 ( struct V_11 * V_6 , int V_106 )
{
F_27 ( V_6 -> V_55 ) ;
if ( ! V_106 ) {
V_6 -> V_276 = V_278 ;
F_28 ( V_6 ) ;
F_185 ( V_6 -> V_174 ) ;
F_356 ( V_6 -> V_174 ) ;
} else {
V_6 -> V_276 = V_277 ;
}
F_29 ( V_6 -> V_55 ) ;
}
int T_4 F_357 ( void )
{
F_358 ( V_348 > 8 *
F_359 ( struct V_18 , V_38 ) ) ;
V_57 = F_360 ( L_30 ,
V_349 | V_350 , 0 ) ;
if ( ! V_57 )
F_361 ( L_31 ) ;
V_96 = F_362 ( L_32 ,
sizeof( struct V_18 ) , 0 , V_351 , NULL ) ;
V_107 = F_362 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_351 , NULL ) ;
return 0 ;
}
