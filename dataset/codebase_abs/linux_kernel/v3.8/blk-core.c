static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_7 ;
if ( ! F_3 ( V_2 ) )
return;
V_7 = F_4 () ;
if ( ! V_3 ) {
V_5 = V_2 -> V_5 ;
F_5 ( V_7 , V_5 , V_8 [ V_6 ] ) ;
} else {
V_5 = F_6 ( V_2 -> V_9 , F_7 ( V_2 ) ) ;
if ( ! F_8 ( V_5 ) ) {
V_5 = & V_2 -> V_9 -> V_10 ;
F_9 ( V_5 ) ;
}
F_10 ( V_7 , V_5 ) ;
F_11 ( V_5 , V_6 ) ;
V_2 -> V_5 = V_5 ;
}
F_12 () ;
}
void F_13 ( struct V_11 * V_12 )
{
int V_13 ;
V_13 = V_12 -> V_14 - ( V_12 -> V_14 / 8 ) + 1 ;
if ( V_13 > V_12 -> V_14 )
V_13 = V_12 -> V_14 ;
V_12 -> V_15 = V_13 ;
V_13 = V_12 -> V_14 - ( V_12 -> V_14 / 8 ) - ( V_12 -> V_14 / 16 ) - 1 ;
if ( V_13 < 1 )
V_13 = 1 ;
V_12 -> V_16 = V_13 ;
}
struct V_17 * F_14 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
struct V_11 * V_12 = F_15 ( V_19 ) ;
if ( V_12 )
V_20 = & V_12 -> V_17 ;
return V_20 ;
}
void F_16 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_17 ( & V_2 -> V_21 ) ;
F_17 ( & V_2 -> V_22 ) ;
V_2 -> V_7 = - 1 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = ( V_24 ) - 1 ;
F_18 ( & V_2 -> V_25 ) ;
F_19 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = V_2 -> V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = - 1 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_34 ;
F_20 ( V_2 ) ;
V_2 -> V_5 = NULL ;
}
static void F_21 ( struct V_1 * V_2 , struct V_35 * V_35 ,
unsigned int V_36 , int error )
{
if ( error )
F_22 ( V_37 , & V_35 -> V_38 ) ;
else if ( ! F_23 ( V_37 , & V_35 -> V_38 ) )
error = - V_39 ;
if ( F_24 ( V_36 > V_35 -> V_40 ) ) {
F_25 ( V_41 L_1 ,
V_42 , V_36 , V_35 -> V_40 ) ;
V_36 = V_35 -> V_40 ;
}
if ( F_24 ( V_2 -> V_43 & V_44 ) )
F_26 ( V_45 , & V_35 -> V_38 ) ;
V_35 -> V_40 -= V_36 ;
V_35 -> V_46 += ( V_36 >> 9 ) ;
if ( F_27 ( V_35 ) )
F_28 ( V_35 , V_36 ) ;
if ( V_35 -> V_40 == 0 && ! ( V_2 -> V_43 & V_47 ) )
F_29 ( V_35 , error ) ;
}
void F_30 ( struct V_1 * V_2 , char * V_48 )
{
int V_49 ;
F_25 ( V_50 L_2 , V_48 ,
V_2 -> V_9 ? V_2 -> V_9 -> V_51 : L_3 , V_2 -> V_52 ,
V_2 -> V_43 ) ;
F_25 ( V_50 L_4 ,
( unsigned long long ) F_7 ( V_2 ) ,
F_31 ( V_2 ) , F_32 ( V_2 ) ) ;
F_25 ( V_50 L_5 ,
V_2 -> V_35 , V_2 -> V_53 , V_2 -> V_54 , F_33 ( V_2 ) ) ;
if ( V_2 -> V_52 == V_55 ) {
F_25 ( V_50 L_6 ) ;
for ( V_49 = 0 ; V_49 < V_30 ; V_49 ++ )
F_25 ( L_7 , V_2 -> V_27 [ V_49 ] ) ;
F_25 ( L_8 ) ;
}
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_11 * V_12 ;
V_12 = F_35 ( V_57 , struct V_11 , V_58 . V_57 ) ;
F_36 ( V_12 -> V_59 ) ;
F_37 ( V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_39 ( struct V_11 * V_12 , unsigned long V_60 )
{
if ( F_40 ( ! F_41 ( V_12 ) ) )
F_42 ( V_61 , & V_12 -> V_58 ,
F_43 ( V_60 ) ) ;
}
void F_44 ( struct V_11 * V_12 )
{
F_45 ( ! F_46 () ) ;
F_47 ( V_62 , V_12 ) ;
F_37 ( V_12 ) ;
}
void F_48 ( struct V_11 * V_12 )
{
F_49 ( & V_12 -> V_58 ) ;
F_50 ( V_62 , V_12 ) ;
}
void F_51 ( struct V_11 * V_12 )
{
F_52 ( & V_12 -> V_63 ) ;
F_53 ( & V_12 -> V_58 ) ;
}
inline void F_54 ( struct V_11 * V_12 )
{
if ( F_24 ( F_41 ( V_12 ) ) )
return;
V_12 -> V_64 ++ ;
V_12 -> V_65 ( V_12 ) ;
V_12 -> V_64 -- ;
}
void F_37 ( struct V_11 * V_12 )
{
if ( F_24 ( F_55 ( V_12 ) ) )
return;
F_54 ( V_12 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
if ( F_40 ( ! F_55 ( V_12 ) && ! F_41 ( V_12 ) ) )
F_57 ( V_61 , & V_12 -> V_58 , 0 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
unsigned long V_66 ;
F_59 ( V_12 -> V_59 , V_66 ) ;
F_37 ( V_12 ) ;
F_60 ( V_12 -> V_59 , V_66 ) ;
}
void F_61 ( struct V_11 * V_12 )
{
F_62 ( & V_12 -> V_67 ) ;
}
static void F_63 ( struct V_11 * V_12 , bool V_68 )
__releases( V_12 -> V_59 )
__acquires( V_12 -> V_59 )
{
int V_69 ;
F_64 ( V_12 -> V_59 ) ;
while ( true ) {
bool V_70 = false ;
if ( V_12 -> V_71 )
F_65 ( V_12 ) ;
F_66 ( V_12 ) ;
if ( ! F_67 ( & V_12 -> V_72 ) && V_12 -> V_65 )
F_37 ( V_12 ) ;
V_70 |= V_12 -> V_73 ;
V_70 |= V_12 -> V_64 ;
if ( V_68 ) {
V_70 |= ! F_67 ( & V_12 -> V_72 ) ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
V_70 |= V_12 -> V_74 [ V_69 ] ;
V_70 |= V_12 -> V_75 [ V_69 ] ;
V_70 |= ! F_67 ( & V_12 -> V_76 [ V_69 ] ) ;
}
}
if ( ! V_70 )
break;
F_38 ( V_12 -> V_59 ) ;
F_68 ( 10 ) ;
F_36 ( V_12 -> V_59 ) ;
}
if ( V_12 -> V_65 ) {
struct V_77 * V_78 ;
F_69 (rl, q)
for ( V_69 = 0 ; V_69 < F_70 ( V_78 -> V_79 ) ; V_69 ++ )
F_71 ( & V_78 -> V_79 [ V_69 ] ) ;
}
}
void F_72 ( struct V_11 * V_12 )
{
bool V_70 ;
F_36 ( V_12 -> V_59 ) ;
V_70 = ! V_12 -> V_80 ++ ;
F_50 ( V_81 , V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
if ( V_70 ) {
F_36 ( V_12 -> V_59 ) ;
F_63 ( V_12 , false ) ;
F_38 ( V_12 -> V_59 ) ;
F_73 () ;
}
}
void F_74 ( struct V_11 * V_12 )
{
F_36 ( V_12 -> V_59 ) ;
if ( ! -- V_12 -> V_80 )
F_47 ( V_81 , V_12 ) ;
F_75 ( V_12 -> V_80 < 0 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_76 ( struct V_11 * V_12 )
{
T_1 * V_82 = V_12 -> V_59 ;
F_77 ( & V_12 -> V_83 ) ;
F_78 ( V_84 , V_12 ) ;
F_36 ( V_82 ) ;
V_12 -> V_80 ++ ;
F_50 ( V_81 , V_12 ) ;
F_50 ( V_85 , V_12 ) ;
F_50 ( V_86 , V_12 ) ;
F_50 ( V_84 , V_12 ) ;
F_38 ( V_82 ) ;
F_79 ( & V_12 -> V_83 ) ;
F_36 ( V_82 ) ;
F_63 ( V_12 , true ) ;
F_50 ( V_87 , V_12 ) ;
F_38 ( V_82 ) ;
F_52 ( & V_12 -> V_17 . V_88 ) ;
F_51 ( V_12 ) ;
F_36 ( V_82 ) ;
if ( V_12 -> V_59 != & V_12 -> V_89 )
V_12 -> V_59 = & V_12 -> V_89 ;
F_38 ( V_82 ) ;
F_61 ( V_12 ) ;
}
int F_80 ( struct V_77 * V_78 , struct V_11 * V_12 ,
T_2 V_90 )
{
if ( F_24 ( V_78 -> V_91 ) )
return 0 ;
V_78 -> V_12 = V_12 ;
V_78 -> V_92 [ V_93 ] = V_78 -> V_92 [ V_94 ] = 0 ;
V_78 -> V_95 [ V_93 ] = V_78 -> V_95 [ V_94 ] = 0 ;
F_81 ( & V_78 -> V_79 [ V_93 ] ) ;
F_81 ( & V_78 -> V_79 [ V_94 ] ) ;
V_78 -> V_91 = F_82 ( V_96 , V_97 ,
V_98 , V_99 ,
V_90 , V_12 -> V_100 ) ;
if ( ! V_78 -> V_91 )
return - V_101 ;
return 0 ;
}
void F_83 ( struct V_77 * V_78 )
{
if ( V_78 -> V_91 )
F_84 ( V_78 -> V_91 ) ;
}
struct V_11 * F_85 ( T_2 V_90 )
{
return F_86 ( V_90 , V_102 ) ;
}
struct V_11 * F_86 ( T_2 V_90 , int V_103 )
{
struct V_11 * V_12 ;
int V_104 ;
V_12 = F_87 ( V_105 ,
V_90 | V_106 , V_103 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_107 = F_88 ( & V_108 , 0 , 0 , V_90 ) ;
if ( V_12 -> V_107 < 0 )
goto V_109;
V_12 -> V_17 . V_110 =
( V_111 * 1024 ) / V_112 ;
V_12 -> V_17 . V_113 = 0 ;
V_12 -> V_17 . V_114 = V_115 ;
V_12 -> V_17 . V_116 = L_9 ;
V_12 -> V_100 = V_103 ;
V_104 = F_89 ( & V_12 -> V_17 ) ;
if ( V_104 )
goto V_117;
F_90 ( & V_12 -> V_17 . V_88 ,
V_118 , ( unsigned long ) V_12 ) ;
F_90 ( & V_12 -> V_63 , V_119 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_72 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_120 ) ;
#ifdef F_91
F_17 ( & V_12 -> V_121 ) ;
#endif
F_17 ( & V_12 -> V_76 [ 0 ] ) ;
F_17 ( & V_12 -> V_76 [ 1 ] ) ;
F_17 ( & V_12 -> V_122 ) ;
F_92 ( & V_12 -> V_58 , F_34 ) ;
F_93 ( & V_12 -> V_67 , & V_123 ) ;
F_94 ( & V_12 -> V_83 ) ;
F_95 ( & V_12 -> V_89 ) ;
V_12 -> V_59 = & V_12 -> V_89 ;
V_12 -> V_80 = 1 ;
F_96 ( V_81 , & V_12 -> V_124 ) ;
if ( F_97 ( V_12 ) )
goto V_117;
return V_12 ;
V_117:
F_98 ( & V_108 , V_12 -> V_107 ) ;
V_109:
F_99 ( V_105 , V_12 ) ;
return NULL ;
}
struct V_11 * F_100 ( T_3 * V_125 , T_1 * V_82 )
{
return F_101 ( V_125 , V_82 , V_102 ) ;
}
struct V_11 *
F_101 ( T_3 * V_125 , T_1 * V_82 , int V_103 )
{
struct V_11 * V_126 , * V_12 ;
V_126 = F_86 ( V_127 , V_103 ) ;
if ( ! V_126 )
return NULL ;
V_12 = F_102 ( V_126 , V_125 , V_82 ) ;
if ( ! V_12 )
F_76 ( V_126 ) ;
return V_12 ;
}
struct V_11 *
F_102 ( struct V_11 * V_12 , T_3 * V_125 ,
T_1 * V_82 )
{
if ( ! V_12 )
return NULL ;
if ( F_80 ( & V_12 -> V_128 , V_12 , V_127 ) )
return NULL ;
V_12 -> V_65 = V_125 ;
V_12 -> V_129 = NULL ;
V_12 -> V_130 = NULL ;
V_12 -> V_124 |= V_131 ;
if ( V_82 )
V_12 -> V_59 = V_82 ;
F_103 ( V_12 , V_132 ) ;
V_12 -> V_133 = V_134 ;
if ( F_104 ( V_12 , NULL ) )
return NULL ;
return V_12 ;
}
bool F_105 ( struct V_11 * V_12 )
{
if ( F_40 ( ! F_106 ( V_12 ) ) ) {
F_107 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_108 ( struct V_77 * V_78 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_135 ) {
F_109 ( V_78 -> V_12 , V_2 ) ;
if ( V_2 -> V_136 . V_137 )
F_110 ( V_2 -> V_136 . V_137 -> V_138 ) ;
}
F_111 ( V_2 , V_78 -> V_91 ) ;
}
static inline int F_112 ( struct V_11 * V_12 , struct V_139 * V_138 )
{
if ( ! V_138 )
return 0 ;
return V_138 -> V_140 == V_12 -> V_141 ||
( V_138 -> V_140 > 0
&& F_113 ( V_34 , V_138 -> V_142 + V_143 ) ) ;
}
static void F_114 ( struct V_11 * V_12 , struct V_139 * V_138 )
{
if ( ! V_138 || F_112 ( V_12 , V_138 ) )
return;
V_138 -> V_140 = V_12 -> V_141 ;
V_138 -> V_142 = V_34 ;
}
static void F_115 ( struct V_77 * V_78 , int V_144 )
{
struct V_11 * V_12 = V_78 -> V_12 ;
if ( V_78 == & V_12 -> V_128 &&
V_78 -> V_92 [ V_144 ] < F_116 ( V_12 ) )
F_117 ( V_12 , V_144 ) ;
if ( V_78 -> V_92 [ V_144 ] + 1 <= V_12 -> V_14 ) {
if ( F_118 ( & V_78 -> V_79 [ V_144 ] ) )
F_119 ( & V_78 -> V_79 [ V_144 ] ) ;
F_120 ( V_78 , V_144 ) ;
}
}
static void F_121 ( struct V_77 * V_78 , unsigned int V_66 )
{
struct V_11 * V_12 = V_78 -> V_12 ;
int V_144 = F_122 ( V_66 ) ;
V_12 -> V_74 [ V_144 ] -- ;
V_78 -> V_92 [ V_144 ] -- ;
if ( V_66 & V_135 )
V_12 -> V_73 -- ;
F_115 ( V_78 , V_144 ) ;
if ( F_24 ( V_78 -> V_95 [ V_144 ^ 1 ] ) )
F_115 ( V_78 , V_144 ^ 1 ) ;
}
static bool F_123 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_145 & ( V_146 | V_147 ) )
return false ;
return true ;
}
static struct V_139 * F_124 ( struct V_35 * V_35 )
{
#ifdef F_91
if ( V_35 && V_35 -> V_148 )
return V_35 -> V_148 ;
#endif
return V_149 -> V_139 ;
}
static struct V_1 * F_125 ( struct V_77 * V_78 , int V_150 ,
struct V_35 * V_35 , T_2 V_90 )
{
struct V_11 * V_12 = V_78 -> V_12 ;
struct V_1 * V_2 ;
struct V_151 * V_152 = V_12 -> V_71 -> type ;
struct V_139 * V_138 = F_124 ( V_35 ) ;
struct V_153 * V_137 = NULL ;
const bool V_154 = F_122 ( V_150 ) != 0 ;
int V_155 ;
if ( F_24 ( F_106 ( V_12 ) ) )
return NULL ;
V_155 = F_126 ( V_12 , V_150 ) ;
if ( V_155 == V_156 )
goto V_157;
if ( V_78 -> V_92 [ V_154 ] + 1 >= F_127 ( V_12 ) ) {
if ( V_78 -> V_92 [ V_154 ] + 1 >= V_12 -> V_14 ) {
if ( ! F_128 ( V_78 , V_154 ) ) {
F_114 ( V_12 , V_138 ) ;
F_129 ( V_78 , V_154 ) ;
} else {
if ( V_155 != V_158
&& ! F_112 ( V_12 , V_138 ) ) {
return NULL ;
}
}
}
if ( V_78 == & V_12 -> V_128 )
F_130 ( V_12 , V_154 ) ;
}
if ( V_78 -> V_92 [ V_154 ] >= ( 3 * V_12 -> V_14 / 2 ) )
return NULL ;
V_12 -> V_74 [ V_154 ] ++ ;
V_78 -> V_92 [ V_154 ] ++ ;
V_78 -> V_95 [ V_154 ] = 0 ;
if ( F_123 ( V_35 ) && ! F_131 ( V_12 ) ) {
V_150 |= V_135 ;
V_12 -> V_73 ++ ;
if ( V_152 -> V_159 && V_138 )
V_137 = F_132 ( V_138 , V_12 ) ;
}
if ( F_133 ( V_12 ) )
V_150 |= V_160 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_134 ( V_78 -> V_91 , V_90 ) ;
if ( ! V_2 )
goto V_161;
F_16 ( V_12 , V_2 ) ;
F_135 ( V_2 , V_78 ) ;
V_2 -> V_43 = V_150 | V_162 ;
if ( V_150 & V_135 ) {
if ( F_24 ( V_152 -> V_159 && ! V_137 ) ) {
if ( V_138 )
V_137 = F_136 ( V_138 , V_12 , V_90 ) ;
if ( ! V_137 )
goto V_163;
}
V_2 -> V_136 . V_137 = V_137 ;
if ( F_24 ( F_137 ( V_12 , V_2 , V_35 , V_90 ) ) )
goto V_163;
if ( V_137 )
F_138 ( V_137 -> V_138 ) ;
}
V_164:
if ( F_112 ( V_12 , V_138 ) )
V_138 -> V_140 -- ;
F_139 ( V_12 , V_35 , V_150 & 1 ) ;
return V_2 ;
V_163:
F_140 ( V_165 L_10 ,
F_141 ( V_12 -> V_17 . V_166 ) ) ;
V_2 -> V_43 &= ~ V_135 ;
V_2 -> V_136 . V_137 = NULL ;
F_36 ( V_12 -> V_59 ) ;
V_12 -> V_73 -- ;
F_38 ( V_12 -> V_59 ) ;
goto V_164;
V_161:
F_36 ( V_12 -> V_59 ) ;
F_121 ( V_78 , V_150 ) ;
V_157:
if ( F_24 ( V_78 -> V_92 [ V_154 ] == 0 ) )
V_78 -> V_95 [ V_154 ] = 1 ;
return NULL ;
}
static struct V_1 * F_142 ( struct V_11 * V_12 , int V_150 ,
struct V_35 * V_35 , T_2 V_90 )
{
const bool V_154 = F_122 ( V_150 ) != 0 ;
F_143 ( V_79 ) ;
struct V_77 * V_78 ;
struct V_1 * V_2 ;
V_78 = F_144 ( V_12 , V_35 ) ;
V_167:
V_2 = F_125 ( V_78 , V_150 , V_35 , V_90 ) ;
if ( V_2 )
return V_2 ;
if ( ! ( V_90 & V_168 ) || F_24 ( F_106 ( V_12 ) ) ) {
F_145 ( V_78 ) ;
return NULL ;
}
F_146 ( & V_78 -> V_79 [ V_154 ] , & V_79 ,
V_169 ) ;
F_147 ( V_12 , V_35 , V_150 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_148 () ;
F_114 ( V_12 , V_149 -> V_139 ) ;
F_36 ( V_12 -> V_59 ) ;
F_149 ( & V_78 -> V_79 [ V_154 ] , & V_79 ) ;
goto V_167;
}
struct V_1 * F_150 ( struct V_11 * V_12 , int V_6 , T_2 V_90 )
{
struct V_1 * V_2 ;
F_151 ( V_6 != V_170 && V_6 != V_171 ) ;
F_152 ( V_90 , V_12 -> V_100 ) ;
F_36 ( V_12 -> V_59 ) ;
V_2 = F_142 ( V_12 , V_6 , NULL , V_90 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_153 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_90 )
{
struct V_1 * V_2 = F_150 ( V_12 , F_154 ( V_35 ) , V_90 ) ;
if ( F_24 ( ! V_2 ) )
return F_155 ( - V_101 ) ;
F_156 (bio) {
struct V_35 * V_172 = V_35 ;
int V_20 ;
F_157 ( V_12 , & V_172 ) ;
V_20 = F_158 ( V_12 , V_2 , V_172 ) ;
if ( F_24 ( V_20 ) ) {
F_159 ( V_2 ) ;
return F_155 ( V_20 ) ;
}
}
return V_2 ;
}
void F_160 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_161 ( V_2 ) ;
F_162 ( V_2 ) ;
F_163 ( V_12 , V_2 ) ;
if ( F_164 ( V_2 ) )
F_165 ( V_12 , V_2 ) ;
F_151 ( F_166 ( V_2 ) ) ;
F_167 ( V_12 , V_2 ) ;
}
static void F_168 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_173 )
{
F_1 ( V_2 , 1 ) ;
F_169 ( V_12 , V_2 , V_173 ) ;
}
static void F_170 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_174 )
{
if ( V_174 == V_5 -> V_175 )
return;
if ( F_171 ( V_5 ) ) {
F_172 ( V_7 , V_5 , V_176 ,
F_171 ( V_5 ) * ( V_174 - V_5 -> V_175 ) ) ;
F_172 ( V_7 , V_5 , V_177 , ( V_174 - V_5 -> V_175 ) ) ;
}
V_5 -> V_175 = V_174 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_174 = V_34 ;
if ( V_5 -> V_178 )
F_170 ( V_7 , & F_173 ( V_5 ) -> V_10 , V_174 ) ;
F_170 ( V_7 , V_5 , V_174 ) ;
}
void F_174 ( struct V_11 * V_12 , struct V_1 * V_179 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_179 -> V_32 ) )
return;
F_175 ( V_12 , V_179 ) ;
F_45 ( V_179 -> V_35 != NULL ) ;
if ( V_179 -> V_43 & V_162 ) {
unsigned int V_66 = V_179 -> V_43 ;
struct V_77 * V_78 = F_176 ( V_179 ) ;
F_151 ( ! F_67 ( & V_179 -> V_21 ) ) ;
F_151 ( ! F_177 ( & V_179 -> V_25 ) ) ;
F_108 ( V_78 , V_179 ) ;
F_121 ( V_78 , V_66 ) ;
F_145 ( V_78 ) ;
}
}
void F_159 ( struct V_1 * V_179 )
{
unsigned long V_66 ;
struct V_11 * V_12 = V_179 -> V_12 ;
F_59 ( V_12 -> V_59 , V_66 ) ;
F_174 ( V_12 , V_179 ) ;
F_60 ( V_12 -> V_59 , V_66 ) ;
}
void F_178 ( struct V_1 * V_2 , struct V_180 * V_180 ,
unsigned int V_181 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_182 -> V_183 = V_180 ;
V_35 -> V_182 -> V_184 = 0 ;
V_35 -> V_182 -> V_185 = V_181 ;
V_35 -> V_40 = V_181 ;
V_35 -> V_186 = 1 ;
V_35 -> V_187 = 1 ;
V_2 -> V_188 = V_2 -> V_189 = V_181 ;
V_2 -> V_190 = 1 ;
V_2 -> V_54 = F_179 ( V_35 ) ;
}
static bool F_180 ( struct V_11 * V_12 , struct V_1 * V_179 ,
struct V_35 * V_35 )
{
const int V_191 = V_35 -> V_145 & V_192 ;
if ( ! F_181 ( V_12 , V_179 , V_35 ) )
return false ;
F_182 ( V_12 , V_35 ) ;
if ( ( V_179 -> V_43 & V_192 ) != V_191 )
F_183 ( V_179 ) ;
V_179 -> V_53 -> V_193 = V_35 ;
V_179 -> V_53 = V_35 ;
V_179 -> V_188 += V_35 -> V_40 ;
V_179 -> V_194 = F_184 ( V_179 -> V_194 , F_185 ( V_35 ) ) ;
F_1 ( V_179 , 0 ) ;
return true ;
}
static bool F_186 ( struct V_11 * V_12 ,
struct V_1 * V_179 , struct V_35 * V_35 )
{
const int V_191 = V_35 -> V_145 & V_192 ;
if ( ! F_187 ( V_12 , V_179 , V_35 ) )
return false ;
F_188 ( V_12 , V_35 ) ;
if ( ( V_179 -> V_43 & V_192 ) != V_191 )
F_183 ( V_179 ) ;
V_35 -> V_193 = V_179 -> V_35 ;
V_179 -> V_35 = V_35 ;
V_179 -> V_54 = F_179 ( V_35 ) ;
V_179 -> V_23 = V_35 -> V_46 ;
V_179 -> V_188 += V_35 -> V_40 ;
V_179 -> V_194 = F_184 ( V_179 -> V_194 , F_185 ( V_35 ) ) ;
F_1 ( V_179 , 0 ) ;
return true ;
}
static bool F_189 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_195 )
{
struct V_196 * V_197 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_197 = V_149 -> V_197 ;
if ( ! V_197 )
goto V_164;
* V_195 = 0 ;
F_190 (rq, &plug->list, queuelist) {
int V_198 ;
if ( V_2 -> V_12 == V_12 )
( * V_195 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_191 ( V_2 , V_35 ) )
continue;
V_198 = F_192 ( V_2 , V_35 ) ;
if ( V_198 == V_199 ) {
V_20 = F_180 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_198 == V_200 ) {
V_20 = F_186 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_164:
return V_20 ;
}
void F_193 ( struct V_1 * V_179 , struct V_35 * V_35 )
{
V_179 -> V_52 = V_201 ;
V_179 -> V_43 |= V_35 -> V_145 & V_202 ;
if ( V_35 -> V_145 & V_203 )
V_179 -> V_43 |= V_192 ;
V_179 -> V_204 = 0 ;
V_179 -> V_23 = V_35 -> V_46 ;
V_179 -> V_194 = F_185 ( V_35 ) ;
F_194 ( V_179 -> V_12 , V_179 , V_35 ) ;
}
void V_132 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_144 = ! ! ( V_35 -> V_145 & V_205 ) ;
struct V_196 * V_197 ;
int V_198 , V_150 , V_173 = V_206 ;
struct V_1 * V_179 ;
unsigned int V_195 = 0 ;
F_157 ( V_12 , & V_35 ) ;
if ( V_35 -> V_145 & ( V_146 | V_147 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_173 = V_207 ;
goto V_208;
}
if ( F_189 ( V_12 , V_35 , & V_195 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_198 = F_195 ( V_12 , & V_179 , V_35 ) ;
if ( V_198 == V_199 ) {
if ( F_180 ( V_12 , V_179 , V_35 ) ) {
F_196 ( V_12 , V_179 , V_35 ) ;
if ( ! F_197 ( V_12 , V_179 ) )
F_198 ( V_12 , V_179 , V_198 ) ;
goto V_209;
}
} else if ( V_198 == V_200 ) {
if ( F_186 ( V_12 , V_179 , V_35 ) ) {
F_196 ( V_12 , V_179 , V_35 ) ;
if ( ! F_199 ( V_12 , V_179 ) )
F_198 ( V_12 , V_179 , V_198 ) ;
goto V_209;
}
}
V_208:
V_150 = F_154 ( V_35 ) ;
if ( V_144 )
V_150 |= V_205 ;
V_179 = F_142 ( V_12 , V_150 , V_35 , V_210 ) ;
if ( F_24 ( ! V_179 ) ) {
F_29 ( V_35 , - V_211 ) ;
goto V_209;
}
F_193 ( V_179 , V_35 ) ;
if ( F_23 ( V_212 , & V_12 -> V_124 ) )
V_179 -> V_7 = F_200 () ;
V_197 = V_149 -> V_197 ;
if ( V_197 ) {
if ( F_67 ( & V_197 -> V_213 ) )
F_201 ( V_12 ) ;
else {
if ( ! V_197 -> V_214 ) {
struct V_1 * V_215 ;
V_215 = F_202 ( V_197 -> V_213 . V_216 ) ;
if ( V_215 -> V_12 != V_12 )
V_197 -> V_214 = 1 ;
}
if ( V_195 >= V_217 ) {
F_203 ( V_197 , false ) ;
F_201 ( V_12 ) ;
}
}
F_204 ( & V_179 -> V_21 , & V_197 -> V_213 ) ;
F_1 ( V_179 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_168 ( V_12 , V_179 , V_173 ) ;
F_37 ( V_12 ) ;
V_209:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_205 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_218 ;
if ( F_206 ( V_35 ) && V_19 != V_19 -> V_219 ) {
struct V_4 * V_220 = V_19 -> V_221 ;
V_35 -> V_46 += V_220 -> V_222 ;
V_35 -> V_218 = V_19 -> V_219 ;
F_207 ( F_15 ( V_35 -> V_218 ) , V_35 ,
V_19 -> V_223 ,
V_35 -> V_46 - V_220 -> V_222 ) ;
}
}
static void F_208 ( struct V_35 * V_35 )
{
char V_224 [ V_225 ] ;
F_25 ( V_50 L_11 ) ;
F_25 ( V_50 L_12 ,
F_209 ( V_35 -> V_218 , V_224 ) ,
V_35 -> V_145 ,
( unsigned long long ) V_35 -> V_46 + F_206 ( V_35 ) ,
( long long ) ( F_210 ( V_35 -> V_218 -> V_226 ) >> 9 ) ) ;
F_26 ( V_227 , & V_35 -> V_38 ) ;
}
static int T_4 F_211 ( char * V_228 )
{
return F_212 ( & V_229 , V_228 ) ;
}
static bool F_213 ( struct V_4 * V_5 , unsigned int V_230 )
{
return V_5 -> V_231 && F_214 ( & V_229 , V_230 ) ;
}
static int T_4 F_215 ( void )
{
struct V_232 * V_233 = F_216 ( L_13 ,
NULL , & V_229 ) ;
return F_217 ( V_233 ) ? F_218 ( V_233 ) : 0 ;
}
static inline bool F_213 ( struct V_4 * V_5 ,
unsigned int V_230 )
{
return false ;
}
static inline int F_219 ( struct V_35 * V_35 , unsigned int V_234 )
{
V_24 V_235 ;
if ( ! V_234 )
return 0 ;
V_235 = F_210 ( V_35 -> V_218 -> V_226 ) >> 9 ;
if ( V_235 ) {
V_24 V_236 = V_35 -> V_46 ;
if ( V_235 < V_234 || V_235 - V_234 < V_236 ) {
F_208 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_220 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_234 = F_206 ( V_35 ) ;
int V_104 = - V_39 ;
char V_224 [ V_225 ] ;
struct V_4 * V_5 ;
F_221 () ;
if ( F_219 ( V_35 , V_234 ) )
goto V_237;
V_12 = F_15 ( V_35 -> V_218 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_14
L_15 ,
F_209 ( V_35 -> V_218 , V_224 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_237;
}
if ( F_40 ( F_222 ( V_35 ) &&
V_234 > F_223 ( V_12 ) ) ) {
F_25 ( V_41 L_16 ,
F_209 ( V_35 -> V_218 , V_224 ) ,
F_206 ( V_35 ) ,
F_223 ( V_12 ) ) ;
goto V_237;
}
V_5 = V_35 -> V_218 -> V_221 ;
if ( F_213 ( V_5 , V_35 -> V_40 ) ||
F_213 ( & F_173 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_237;
F_205 ( V_35 ) ;
if ( F_224 ( V_35 ) && F_225 ( V_35 ) )
goto V_237;
if ( F_219 ( V_35 , V_234 ) )
goto V_237;
if ( ( V_35 -> V_145 & ( V_146 | V_147 ) ) && ! V_12 -> V_238 ) {
V_35 -> V_145 &= ~ ( V_146 | V_147 ) ;
if ( ! V_234 ) {
V_104 = 0 ;
goto V_237;
}
}
if ( ( V_35 -> V_145 & V_239 ) &&
( ! F_226 ( V_12 ) ||
( ( V_35 -> V_145 & V_240 ) && ! F_227 ( V_12 ) ) ) ) {
V_104 = - V_241 ;
goto V_237;
}
if ( V_35 -> V_145 & V_242 && ! F_228 ( V_35 -> V_218 ) ) {
V_104 = - V_241 ;
goto V_237;
}
F_152 ( V_243 , V_12 -> V_100 ) ;
if ( F_229 ( V_12 , V_35 ) )
return false ;
F_230 ( V_12 , V_35 ) ;
return true ;
V_237:
F_29 ( V_35 , V_104 ) ;
return false ;
}
void F_231 ( struct V_35 * V_35 )
{
struct V_244 V_245 ;
if ( ! F_220 ( V_35 ) )
return;
if ( V_149 -> V_244 ) {
F_232 ( V_149 -> V_244 , V_35 ) ;
return;
}
F_151 ( V_35 -> V_193 ) ;
F_233 ( & V_245 ) ;
V_149 -> V_244 = & V_245 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_218 ) ;
V_12 -> V_246 ( V_12 , V_35 ) ;
V_35 = F_234 ( V_149 -> V_244 ) ;
} while ( V_35 );
V_149 -> V_244 = NULL ;
}
void F_235 ( int V_6 , struct V_35 * V_35 )
{
V_35 -> V_145 |= V_6 ;
if ( F_236 ( V_35 ) ) {
unsigned int V_92 ;
if ( F_24 ( V_6 & V_242 ) )
V_92 = F_237 ( V_35 -> V_218 ) >> 9 ;
else
V_92 = F_206 ( V_35 ) ;
if ( V_6 & V_171 ) {
F_238 ( V_247 , V_92 ) ;
} else {
F_239 ( V_35 -> V_40 ) ;
F_238 ( V_248 , V_92 ) ;
}
if ( F_24 ( V_249 ) ) {
char V_224 [ V_225 ] ;
F_25 ( V_250 L_17 ,
V_149 -> V_251 , F_240 ( V_149 ) ,
( V_6 & V_171 ) ? L_18 : L_19 ,
( unsigned long long ) V_35 -> V_46 ,
F_209 ( V_35 -> V_218 , V_224 ) ,
V_92 ) ;
}
}
F_231 ( V_35 ) ;
}
int F_241 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( ! F_242 ( V_2 ) )
return 0 ;
if ( F_31 ( V_2 ) > F_243 ( V_12 , V_2 -> V_43 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
F_244 ( V_2 ) ;
if ( V_2 -> V_190 > F_245 ( V_12 ) ) {
F_25 ( V_41 L_21 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_246 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_66 ;
int V_173 = V_252 ;
if ( F_241 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_213 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_59 ( V_12 -> V_59 , V_66 ) ;
if ( F_24 ( F_106 ( V_12 ) ) ) {
F_60 ( V_12 -> V_59 , V_66 ) ;
return - V_211 ;
}
F_151 ( F_166 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_146 | V_147 ) )
V_173 = V_207 ;
F_168 ( V_12 , V_2 , V_173 ) ;
if ( V_173 == V_207 )
F_37 ( V_12 ) ;
F_60 ( V_12 -> V_59 , V_66 ) ;
return 0 ;
}
unsigned int F_247 ( const struct V_1 * V_2 )
{
unsigned int V_191 = V_2 -> V_43 & V_192 ;
unsigned int V_230 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_253 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_193 ) {
if ( ( V_35 -> V_145 & V_191 ) != V_191 )
break;
V_230 += V_35 -> V_40 ;
}
F_151 ( F_33 ( V_2 ) && ! V_230 ) ;
return V_230 ;
}
static void F_248 ( struct V_1 * V_179 , unsigned int V_230 )
{
if ( F_3 ( V_179 ) ) {
const int V_6 = F_2 ( V_179 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_179 -> V_5 ;
F_249 ( V_7 , V_5 , V_254 [ V_6 ] , V_230 >> 9 ) ;
F_12 () ;
}
}
static void F_250 ( struct V_1 * V_179 )
{
if ( F_3 ( V_179 ) && ! ( V_179 -> V_43 & V_47 ) ) {
unsigned long V_255 = V_34 - V_179 -> V_33 ;
const int V_6 = F_2 ( V_179 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_179 -> V_5 ;
F_5 ( V_7 , V_5 , V_256 [ V_6 ] ) ;
F_249 ( V_7 , V_5 , V_257 [ V_6 ] , V_255 ) ;
F_10 ( V_7 , V_5 ) ;
F_251 ( V_5 , V_6 ) ;
F_252 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_253 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_254 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_258 ) ) {
if ( V_2 -> V_43 & V_259 )
F_255 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_258 ;
F_256 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_260 || V_12 -> V_260 == V_2 ) {
V_12 -> V_261 = F_257 ( V_2 ) ;
V_12 -> V_260 = NULL ;
}
if ( V_2 -> V_43 & V_262 )
break;
if ( V_12 -> V_263 && F_33 ( V_2 ) ) {
V_2 -> V_190 ++ ;
}
if ( ! V_12 -> V_129 )
break;
V_20 = V_12 -> V_129 ( V_12 , V_2 ) ;
if ( V_20 == V_264 ) {
break;
} else if ( V_20 == V_265 ) {
if ( V_12 -> V_263 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_262 ) ) {
-- V_2 -> V_190 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_266 ) {
V_2 -> V_43 |= V_44 ;
F_258 ( V_2 ) ;
F_259 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_22 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_260 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_151 ( F_67 ( & V_2 -> V_21 ) ) ;
F_151 ( F_261 ( V_2 ) ) ;
F_262 ( & V_2 -> V_21 ) ;
if ( F_263 ( V_2 ) ) {
V_12 -> V_75 [ F_264 ( V_2 ) ] ++ ;
F_265 ( V_2 ) ;
}
}
void F_258 ( struct V_1 * V_179 )
{
F_260 ( V_179 ) ;
V_179 -> V_189 = F_33 ( V_179 ) ;
if ( F_24 ( F_266 ( V_179 ) ) )
V_179 -> V_267 -> V_189 = F_33 ( V_179 -> V_267 ) ;
F_267 ( V_179 ) ;
}
struct V_1 * F_268 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_253 ( V_12 ) ;
if ( V_2 )
F_258 ( V_2 ) ;
return V_2 ;
}
bool F_269 ( struct V_1 * V_179 , int error , unsigned int V_268 )
{
int V_269 , V_270 , V_271 = 0 ;
struct V_35 * V_35 ;
if ( ! V_179 -> V_35 )
return false ;
F_270 ( V_179 -> V_12 , V_179 ) ;
if ( V_179 -> V_52 == V_201 )
V_179 -> V_204 = 0 ;
if ( error && V_179 -> V_52 == V_201 &&
! ( V_179 -> V_43 & V_44 ) ) {
char * V_272 ;
switch ( error ) {
case - V_273 :
V_272 = L_23 ;
break;
case - V_274 :
V_272 = L_24 ;
break;
case - V_275 :
V_272 = L_25 ;
break;
case - V_39 :
default:
V_272 = L_26 ;
break;
}
F_140 ( V_41 L_27 ,
V_272 , V_179 -> V_9 ?
V_179 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_179 ) ) ;
}
F_248 ( V_179 , V_268 ) ;
V_269 = V_270 = 0 ;
while ( ( V_35 = V_179 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_268 >= V_35 -> V_40 ) {
V_179 -> V_35 = V_35 -> V_193 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_179 , V_35 , V_36 , error ) ;
V_271 = 0 ;
V_270 = 0 ;
} else {
int V_276 = V_35 -> V_277 + V_271 ;
if ( F_24 ( V_276 >= V_35 -> V_186 ) ) {
F_30 ( V_179 , L_28 ) ;
F_25 ( V_41 L_29 ,
V_42 , V_276 , V_35 -> V_186 ) ;
break;
}
V_36 = F_271 ( V_35 , V_276 ) -> V_185 ;
F_272 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_268 ) ) {
V_270 += V_268 ;
V_269 += V_268 ;
break;
}
V_271 ++ ;
V_270 += V_36 ;
}
V_269 += V_36 ;
V_268 -= V_36 ;
V_35 = V_179 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_268 <= 0 ) )
break;
}
}
if ( ! V_179 -> V_35 ) {
V_179 -> V_188 = 0 ;
return false ;
}
if ( V_270 ) {
F_21 ( V_179 , V_35 , V_270 , error ) ;
V_35 -> V_277 += V_271 ;
F_273 ( V_35 ) -> V_184 += V_268 ;
F_273 ( V_35 ) -> V_185 -= V_268 ;
}
V_179 -> V_188 -= V_269 ;
V_179 -> V_54 = F_179 ( V_179 -> V_35 ) ;
if ( V_179 -> V_52 == V_201 )
V_179 -> V_23 += V_269 >> 9 ;
if ( V_179 -> V_43 & V_253 ) {
V_179 -> V_43 &= ~ V_192 ;
V_179 -> V_43 |= V_179 -> V_35 -> V_145 & V_192 ;
}
if ( F_33 ( V_179 ) < F_274 ( V_179 ) ) {
F_30 ( V_179 , L_30 ) ;
V_179 -> V_188 = F_274 ( V_179 ) ;
}
F_244 ( V_179 ) ;
return true ;
}
static bool F_275 ( struct V_1 * V_2 , int error ,
unsigned int V_268 ,
unsigned int V_278 )
{
if ( F_269 ( V_2 , error , V_268 ) )
return true ;
if ( F_24 ( F_266 ( V_2 ) ) &&
F_269 ( V_2 -> V_267 , error , V_278 ) )
return true ;
if ( F_276 ( V_2 -> V_12 ) )
F_277 ( V_2 -> V_9 ) ;
return false ;
}
void F_278 ( struct V_1 * V_179 )
{
struct V_11 * V_12 = V_179 -> V_12 ;
V_179 -> V_43 &= ~ V_262 ;
if ( V_12 -> V_130 )
V_12 -> V_130 ( V_12 , V_179 ) ;
}
static void F_279 ( struct V_1 * V_179 , int error )
{
if ( F_164 ( V_179 ) )
F_165 ( V_179 -> V_12 , V_179 ) ;
F_151 ( F_166 ( V_179 ) ) ;
if ( F_24 ( V_279 ) && V_179 -> V_52 == V_201 )
F_280 ( & V_179 -> V_12 -> V_17 ) ;
F_161 ( V_179 ) ;
if ( V_179 -> V_43 & V_262 )
F_278 ( V_179 ) ;
F_250 ( V_179 ) ;
if ( V_179 -> V_237 )
V_179 -> V_237 ( V_179 , error ) ;
else {
if ( F_266 ( V_179 ) )
F_174 ( V_179 -> V_267 -> V_12 , V_179 -> V_267 ) ;
F_174 ( V_179 -> V_12 , V_179 ) ;
}
}
static bool F_281 ( struct V_1 * V_2 , int error ,
unsigned int V_268 , unsigned int V_278 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_66 ;
if ( F_275 ( V_2 , error , V_268 , V_278 ) )
return true ;
F_59 ( V_12 -> V_59 , V_66 ) ;
F_279 ( V_2 , error ) ;
F_60 ( V_12 -> V_59 , V_66 ) ;
return false ;
}
bool F_282 ( struct V_1 * V_2 , int error ,
unsigned int V_268 , unsigned int V_278 )
{
if ( F_275 ( V_2 , error , V_268 , V_278 ) )
return true ;
F_279 ( V_2 , error ) ;
return false ;
}
bool F_283 ( struct V_1 * V_2 , int error , unsigned int V_268 )
{
return F_281 ( V_2 , error , V_268 , 0 ) ;
}
void F_284 ( struct V_1 * V_2 , int error )
{
bool V_280 ;
unsigned int V_278 = 0 ;
if ( F_24 ( F_266 ( V_2 ) ) )
V_278 = F_33 ( V_2 -> V_267 ) ;
V_280 = F_281 ( V_2 , error , F_33 ( V_2 ) , V_278 ) ;
F_151 ( V_280 ) ;
}
bool F_285 ( struct V_1 * V_2 , int error )
{
return F_283 ( V_2 , error , F_274 ( V_2 ) ) ;
}
bool F_286 ( struct V_1 * V_2 , int error )
{
F_45 ( error >= 0 ) ;
return F_283 ( V_2 , error , F_247 ( V_2 ) ) ;
}
bool F_287 ( struct V_1 * V_2 , int error , unsigned int V_268 )
{
return F_282 ( V_2 , error , V_268 , 0 ) ;
}
void F_259 ( struct V_1 * V_2 , int error )
{
bool V_280 ;
unsigned int V_278 = 0 ;
if ( F_24 ( F_266 ( V_2 ) ) )
V_278 = F_33 ( V_2 -> V_267 ) ;
V_280 = F_282 ( V_2 , error , F_33 ( V_2 ) , V_278 ) ;
F_151 ( V_280 ) ;
}
bool F_288 ( struct V_1 * V_2 , int error )
{
return F_287 ( V_2 , error , F_274 ( V_2 ) ) ;
}
bool F_289 ( struct V_1 * V_2 , int error )
{
F_45 ( error >= 0 ) ;
return F_287 ( V_2 , error , F_247 ( V_2 ) ) ;
}
void F_194 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_145 & V_281 ;
if ( F_236 ( V_35 ) ) {
V_2 -> V_190 = F_290 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_179 ( V_35 ) ;
}
V_2 -> V_188 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_218 )
V_2 -> V_9 = V_35 -> V_218 -> V_282 ;
}
void F_291 ( struct V_1 * V_2 )
{
struct V_283 V_284 ;
struct V_285 * V_286 ;
F_292 (bvec, rq, iter)
F_293 ( V_286 -> V_183 ) ;
}
int F_294 ( struct V_11 * V_12 )
{
if ( V_12 -> V_287 )
return V_12 -> V_287 ( V_12 ) ;
return 0 ;
}
void F_295 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_193 ;
F_296 ( V_35 ) ;
}
}
static void F_297 ( struct V_1 * V_288 , struct V_1 * V_289 )
{
V_288 -> V_7 = V_289 -> V_7 ;
V_288 -> V_43 = ( V_289 -> V_43 & V_290 ) | V_291 ;
V_288 -> V_52 = V_289 -> V_52 ;
V_288 -> V_23 = F_7 ( V_289 ) ;
V_288 -> V_188 = F_33 ( V_289 ) ;
V_288 -> V_190 = V_289 -> V_190 ;
V_288 -> V_194 = V_289 -> V_194 ;
V_288 -> V_292 = V_289 -> V_292 ;
}
int F_298 ( struct V_1 * V_2 , struct V_1 * V_293 ,
struct V_294 * V_295 , T_2 V_90 ,
int (* F_299)( struct V_35 * , struct V_35 * , void * ) ,
void * V_296 )
{
struct V_35 * V_35 , * V_297 ;
if ( ! V_295 )
V_295 = V_298 ;
F_16 ( NULL , V_2 ) ;
F_300 (bio_src, rq_src) {
V_35 = F_301 ( V_297 , V_90 , V_295 ) ;
if ( ! V_35 )
goto V_299;
if ( F_299 && F_299 ( V_35 , V_297 , V_296 ) )
goto V_299;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_193 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_297 ( V_2 , V_293 ) ;
return 0 ;
V_299:
if ( V_35 )
F_296 ( V_35 ) ;
F_295 ( V_2 ) ;
return - V_101 ;
}
int F_302 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_303 ( V_61 , V_57 ) ;
}
int F_304 ( struct V_11 * V_12 ,
struct V_300 * V_301 , unsigned long V_302 )
{
return F_42 ( V_61 , V_301 , V_302 ) ;
}
void F_305 ( struct V_196 * V_197 )
{
struct V_303 * V_304 = V_149 ;
V_197 -> V_305 = V_306 ;
F_17 ( & V_197 -> V_213 ) ;
F_17 ( & V_197 -> V_307 ) ;
V_197 -> V_214 = 0 ;
if ( ! V_304 -> V_197 ) {
V_304 -> V_197 = V_197 ;
}
}
static int F_306 ( void * V_308 , struct V_309 * V_310 , struct V_309 * V_224 )
{
struct V_1 * V_311 = F_35 ( V_310 , struct V_1 , V_21 ) ;
struct V_1 * V_312 = F_35 ( V_224 , struct V_1 , V_21 ) ;
return ! ( V_311 -> V_12 < V_312 -> V_12 ||
( V_311 -> V_12 == V_312 -> V_12 && F_7 ( V_311 ) < F_7 ( V_312 ) ) ) ;
}
static void F_307 ( struct V_11 * V_12 , unsigned int V_313 ,
bool V_314 )
__releases( V_12 -> V_59 )
{
F_308 ( V_12 , V_313 , ! V_314 ) ;
if ( V_314 )
F_56 ( V_12 ) ;
else
F_37 ( V_12 ) ;
F_309 ( V_12 -> V_59 ) ;
}
static void F_310 ( struct V_196 * V_197 , bool V_314 )
{
F_311 ( V_315 ) ;
while ( ! F_67 ( & V_197 -> V_307 ) ) {
F_312 ( & V_197 -> V_307 , & V_315 ) ;
while ( ! F_67 ( & V_315 ) ) {
struct V_316 * V_317 = F_313 ( & V_315 ,
struct V_316 ,
V_213 ) ;
F_314 ( & V_317 -> V_213 ) ;
V_317 -> V_318 ( V_317 , V_314 ) ;
}
}
}
struct V_316 * F_315 ( T_6 V_319 , void * V_296 ,
int V_320 )
{
struct V_196 * V_197 = V_149 -> V_197 ;
struct V_316 * V_317 ;
if ( ! V_197 )
return NULL ;
F_316 (cb, &plug->cb_list, list)
if ( V_317 -> V_318 == V_319 && V_317 -> V_296 == V_296 )
return V_317 ;
F_151 ( V_320 < sizeof( * V_317 ) ) ;
V_317 = F_317 ( V_320 , V_243 ) ;
if ( V_317 ) {
V_317 -> V_296 = V_296 ;
V_317 -> V_318 = V_319 ;
F_318 ( & V_317 -> V_213 , & V_197 -> V_307 ) ;
}
return V_317 ;
}
void F_203 ( struct V_196 * V_197 , bool V_314 )
{
struct V_11 * V_12 ;
unsigned long V_66 ;
struct V_1 * V_2 ;
F_311 ( V_213 ) ;
unsigned int V_313 ;
F_151 ( V_197 -> V_305 != V_306 ) ;
F_310 ( V_197 , V_314 ) ;
if ( F_67 ( & V_197 -> V_213 ) )
return;
F_312 ( & V_197 -> V_213 , & V_213 ) ;
if ( V_197 -> V_214 ) {
F_319 ( NULL , & V_213 , F_306 ) ;
V_197 -> V_214 = 0 ;
}
V_12 = NULL ;
V_313 = 0 ;
F_320 ( V_66 ) ;
while ( ! F_67 ( & V_213 ) ) {
V_2 = F_202 ( V_213 . V_321 ) ;
F_262 ( & V_2 -> V_21 ) ;
F_151 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_307 ( V_12 , V_313 , V_314 ) ;
V_12 = V_2 -> V_12 ;
V_313 = 0 ;
F_321 ( V_12 -> V_59 ) ;
}
if ( F_24 ( F_106 ( V_12 ) ) ) {
F_259 ( V_2 , - V_211 ) ;
continue;
}
if ( V_2 -> V_43 & ( V_146 | V_147 ) )
F_169 ( V_12 , V_2 , V_207 ) ;
else
F_169 ( V_12 , V_2 , V_322 ) ;
V_313 ++ ;
}
if ( V_12 )
F_307 ( V_12 , V_313 , V_314 ) ;
F_322 ( V_66 ) ;
}
void F_323 ( struct V_196 * V_197 )
{
F_203 ( V_197 , false ) ;
if ( V_197 == V_149 -> V_197 )
V_149 -> V_197 = NULL ;
}
int T_4 F_324 ( void )
{
F_325 ( V_323 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_326 ( L_31 ,
V_324 | V_325 , 0 ) ;
if ( ! V_61 )
F_327 ( L_32 ) ;
V_99 = F_328 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_326 , NULL ) ;
V_105 = F_328 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_326 , NULL ) ;
return 0 ;
}
