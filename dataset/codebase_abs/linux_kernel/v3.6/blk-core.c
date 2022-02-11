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
F_40 ( V_61 , & V_12 -> V_58 ,
F_41 ( V_60 ) ) ;
}
void F_42 ( struct V_11 * V_12 )
{
F_43 ( ! F_44 () ) ;
F_45 ( V_62 , V_12 ) ;
F_37 ( V_12 ) ;
}
void F_46 ( struct V_11 * V_12 )
{
F_47 ( & V_12 -> V_58 ) ;
F_48 ( V_62 , V_12 ) ;
}
void F_49 ( struct V_11 * V_12 )
{
F_50 ( & V_12 -> V_63 ) ;
F_51 ( & V_12 -> V_58 ) ;
}
void F_37 ( struct V_11 * V_12 )
{
if ( F_24 ( F_52 ( V_12 ) ) )
return;
V_12 -> V_64 ( V_12 ) ;
}
void F_53 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_52 ( V_12 ) ) ) {
F_47 ( & V_12 -> V_58 ) ;
F_40 ( V_61 , & V_12 -> V_58 , 0 ) ;
}
}
void F_55 ( struct V_11 * V_12 )
{
unsigned long V_65 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
F_59 ( & V_12 -> V_66 ) ;
}
void F_60 ( struct V_11 * V_12 , bool V_67 )
{
int V_68 ;
while ( true ) {
bool V_69 = false ;
F_36 ( V_12 -> V_59 ) ;
if ( V_12 -> V_70 )
F_61 ( V_12 ) ;
F_62 ( V_12 ) ;
if ( ! F_63 ( & V_12 -> V_71 ) && V_12 -> V_64 )
F_37 ( V_12 ) ;
V_69 |= V_12 -> V_72 ;
if ( V_67 ) {
V_69 |= ! F_63 ( & V_12 -> V_71 ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_69 |= V_12 -> V_73 [ V_68 ] ;
V_69 |= V_12 -> V_74 [ V_68 ] ;
V_69 |= ! F_63 ( & V_12 -> V_75 [ V_68 ] ) ;
}
}
F_38 ( V_12 -> V_59 ) ;
if ( ! V_69 )
break;
F_64 ( 10 ) ;
}
if ( V_12 -> V_64 ) {
struct V_76 * V_77 ;
F_36 ( V_12 -> V_59 ) ;
F_65 (rl, q)
for ( V_68 = 0 ; V_68 < F_66 ( V_77 -> V_78 ) ; V_68 ++ )
F_67 ( & V_77 -> V_78 [ V_68 ] ) ;
F_38 ( V_12 -> V_59 ) ;
}
}
void F_68 ( struct V_11 * V_12 )
{
bool V_69 ;
F_36 ( V_12 -> V_59 ) ;
V_69 = ! V_12 -> V_79 ++ ;
F_48 ( V_80 , V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
if ( V_69 ) {
F_60 ( V_12 , false ) ;
F_69 () ;
}
}
void F_70 ( struct V_11 * V_12 )
{
F_36 ( V_12 -> V_59 ) ;
if ( ! -- V_12 -> V_79 )
F_45 ( V_80 , V_12 ) ;
F_71 ( V_12 -> V_79 < 0 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_72 ( struct V_11 * V_12 )
{
T_1 * V_81 = V_12 -> V_59 ;
F_73 ( & V_12 -> V_82 ) ;
F_74 ( V_83 , V_12 ) ;
F_36 ( V_81 ) ;
V_12 -> V_79 ++ ;
F_48 ( V_80 , V_12 ) ;
F_48 ( V_84 , V_12 ) ;
F_48 ( V_85 , V_12 ) ;
F_48 ( V_83 , V_12 ) ;
F_38 ( V_81 ) ;
F_75 ( & V_12 -> V_82 ) ;
F_60 ( V_12 , true ) ;
F_50 ( & V_12 -> V_17 . V_86 ) ;
F_49 ( V_12 ) ;
F_36 ( V_81 ) ;
if ( V_12 -> V_59 != & V_12 -> V_87 )
V_12 -> V_59 = & V_12 -> V_87 ;
F_38 ( V_81 ) ;
F_58 ( V_12 ) ;
}
int F_76 ( struct V_76 * V_77 , struct V_11 * V_12 ,
T_2 V_88 )
{
if ( F_24 ( V_77 -> V_89 ) )
return 0 ;
V_77 -> V_12 = V_12 ;
V_77 -> V_90 [ V_91 ] = V_77 -> V_90 [ V_92 ] = 0 ;
V_77 -> V_93 [ V_91 ] = V_77 -> V_93 [ V_92 ] = 0 ;
F_77 ( & V_77 -> V_78 [ V_91 ] ) ;
F_77 ( & V_77 -> V_78 [ V_92 ] ) ;
V_77 -> V_89 = F_78 ( V_94 , V_95 ,
V_96 , V_97 ,
V_88 , V_12 -> V_98 ) ;
if ( ! V_77 -> V_89 )
return - V_99 ;
return 0 ;
}
void F_79 ( struct V_76 * V_77 )
{
if ( V_77 -> V_89 )
F_80 ( V_77 -> V_89 ) ;
}
struct V_11 * F_81 ( T_2 V_88 )
{
return F_82 ( V_88 , - 1 ) ;
}
struct V_11 * F_82 ( T_2 V_88 , int V_100 )
{
struct V_11 * V_12 ;
int V_101 ;
V_12 = F_83 ( V_102 ,
V_88 | V_103 , V_100 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_104 = F_84 ( & V_105 , 0 , 0 , V_88 ) ;
if ( V_12 -> V_104 < 0 )
goto V_106;
V_12 -> V_17 . V_107 =
( V_108 * 1024 ) / V_109 ;
V_12 -> V_17 . V_110 = 0 ;
V_12 -> V_17 . V_111 = V_112 ;
V_12 -> V_17 . V_113 = L_9 ;
V_12 -> V_98 = V_100 ;
V_101 = F_85 ( & V_12 -> V_17 ) ;
if ( V_101 )
goto V_114;
F_86 ( & V_12 -> V_17 . V_86 ,
V_115 , ( unsigned long ) V_12 ) ;
F_86 ( & V_12 -> V_63 , V_116 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_71 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_117 ) ;
#ifdef F_87
F_17 ( & V_12 -> V_118 ) ;
#endif
F_17 ( & V_12 -> V_75 [ 0 ] ) ;
F_17 ( & V_12 -> V_75 [ 1 ] ) ;
F_17 ( & V_12 -> V_119 ) ;
F_88 ( & V_12 -> V_58 , F_34 ) ;
F_89 ( & V_12 -> V_66 , & V_120 ) ;
F_90 ( & V_12 -> V_82 ) ;
F_91 ( & V_12 -> V_87 ) ;
V_12 -> V_59 = & V_12 -> V_87 ;
V_12 -> V_79 = 1 ;
F_92 ( V_80 , & V_12 -> V_121 ) ;
if ( F_93 ( V_12 ) )
goto V_114;
return V_12 ;
V_114:
F_94 ( & V_105 , V_12 -> V_104 ) ;
V_106:
F_95 ( V_102 , V_12 ) ;
return NULL ;
}
struct V_11 * F_96 ( T_3 * V_122 , T_1 * V_81 )
{
return F_97 ( V_122 , V_81 , - 1 ) ;
}
struct V_11 *
F_97 ( T_3 * V_122 , T_1 * V_81 , int V_100 )
{
struct V_11 * V_123 , * V_12 ;
V_123 = F_82 ( V_124 , V_100 ) ;
if ( ! V_123 )
return NULL ;
V_12 = F_98 ( V_123 , V_122 , V_81 ) ;
if ( ! V_12 )
F_72 ( V_123 ) ;
return V_12 ;
}
struct V_11 *
F_98 ( struct V_11 * V_12 , T_3 * V_122 ,
T_1 * V_81 )
{
if ( ! V_12 )
return NULL ;
if ( F_76 ( & V_12 -> V_125 , V_12 , V_124 ) )
return NULL ;
V_12 -> V_64 = V_122 ;
V_12 -> V_126 = NULL ;
V_12 -> V_127 = NULL ;
V_12 -> V_121 = V_128 ;
if ( V_81 )
V_12 -> V_59 = V_81 ;
F_99 ( V_12 , V_129 ) ;
V_12 -> V_130 = V_131 ;
if ( F_100 ( V_12 , NULL ) )
return NULL ;
F_13 ( V_12 ) ;
F_70 ( V_12 ) ;
return V_12 ;
}
bool F_101 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_102 ( V_12 ) ) ) {
F_103 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_104 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_132 ) {
F_105 ( V_77 -> V_12 , V_2 ) ;
if ( V_2 -> V_133 . V_134 )
F_106 ( V_2 -> V_133 . V_134 -> V_135 ) ;
}
F_107 ( V_2 , V_77 -> V_89 ) ;
}
static inline int F_108 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 )
return 0 ;
return V_135 -> V_137 == V_12 -> V_138 ||
( V_135 -> V_137 > 0
&& F_109 ( V_34 , V_135 -> V_139 + V_140 ) ) ;
}
static void F_110 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 || F_108 ( V_12 , V_135 ) )
return;
V_135 -> V_137 = V_12 -> V_138 ;
V_135 -> V_139 = V_34 ;
}
static void F_111 ( struct V_76 * V_77 , int V_141 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
if ( V_77 == & V_12 -> V_125 &&
V_77 -> V_90 [ V_141 ] < F_112 ( V_12 ) )
F_113 ( V_12 , V_141 ) ;
if ( V_77 -> V_90 [ V_141 ] + 1 <= V_12 -> V_14 ) {
if ( F_114 ( & V_77 -> V_78 [ V_141 ] ) )
F_115 ( & V_77 -> V_78 [ V_141 ] ) ;
F_116 ( V_77 , V_141 ) ;
}
}
static void F_117 ( struct V_76 * V_77 , unsigned int V_65 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
int V_141 = F_118 ( V_65 ) ;
V_12 -> V_73 [ V_141 ] -- ;
V_77 -> V_90 [ V_141 ] -- ;
if ( V_65 & V_132 )
V_12 -> V_72 -- ;
F_111 ( V_77 , V_141 ) ;
if ( F_24 ( V_77 -> V_93 [ V_141 ^ 1 ] ) )
F_111 ( V_77 , V_141 ^ 1 ) ;
}
static bool F_119 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_142 & ( V_143 | V_144 ) )
return false ;
return true ;
}
static struct V_136 * F_120 ( struct V_35 * V_35 )
{
#ifdef F_87
if ( V_35 && V_35 -> V_145 )
return V_35 -> V_145 ;
#endif
return V_146 -> V_136 ;
}
static struct V_1 * F_121 ( struct V_76 * V_77 , int V_147 ,
struct V_35 * V_35 , T_2 V_88 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
struct V_1 * V_2 ;
struct V_148 * V_149 = V_12 -> V_70 -> type ;
struct V_136 * V_135 = F_120 ( V_35 ) ;
struct V_150 * V_134 = NULL ;
const bool V_151 = F_118 ( V_147 ) != 0 ;
int V_152 ;
if ( F_24 ( F_102 ( V_12 ) ) )
return NULL ;
V_152 = F_122 ( V_12 , V_147 ) ;
if ( V_152 == V_153 )
goto V_154;
if ( V_77 -> V_90 [ V_151 ] + 1 >= F_123 ( V_12 ) ) {
if ( V_77 -> V_90 [ V_151 ] + 1 >= V_12 -> V_14 ) {
if ( ! F_124 ( V_77 , V_151 ) ) {
F_110 ( V_12 , V_135 ) ;
F_125 ( V_77 , V_151 ) ;
} else {
if ( V_152 != V_155
&& ! F_108 ( V_12 , V_135 ) ) {
return NULL ;
}
}
}
if ( V_77 == & V_12 -> V_125 )
F_126 ( V_12 , V_151 ) ;
}
if ( V_77 -> V_90 [ V_151 ] >= ( 3 * V_12 -> V_14 / 2 ) )
return NULL ;
V_12 -> V_73 [ V_151 ] ++ ;
V_77 -> V_90 [ V_151 ] ++ ;
V_77 -> V_93 [ V_151 ] = 0 ;
if ( F_119 ( V_35 ) && ! F_127 ( V_12 ) ) {
V_147 |= V_132 ;
V_12 -> V_72 ++ ;
if ( V_149 -> V_156 && V_135 )
V_134 = F_128 ( V_135 , V_12 ) ;
}
if ( F_129 ( V_12 ) )
V_147 |= V_157 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_130 ( V_77 -> V_89 , V_88 ) ;
if ( ! V_2 )
goto V_158;
F_16 ( V_12 , V_2 ) ;
F_131 ( V_2 , V_77 ) ;
V_2 -> V_43 = V_147 | V_159 ;
if ( V_147 & V_132 ) {
if ( F_24 ( V_149 -> V_156 && ! V_134 ) ) {
if ( V_135 )
V_134 = F_132 ( V_135 , V_12 , V_88 ) ;
if ( ! V_134 )
goto V_160;
}
V_2 -> V_133 . V_134 = V_134 ;
if ( F_24 ( F_133 ( V_12 , V_2 , V_35 , V_88 ) ) )
goto V_160;
if ( V_134 )
F_134 ( V_134 -> V_135 ) ;
}
V_161:
if ( F_108 ( V_12 , V_135 ) )
V_135 -> V_137 -- ;
F_135 ( V_12 , V_35 , V_147 & 1 ) ;
return V_2 ;
V_160:
F_136 ( V_162 L_10 ,
F_137 ( V_12 -> V_17 . V_163 ) ) ;
V_2 -> V_43 &= ~ V_132 ;
V_2 -> V_133 . V_134 = NULL ;
F_36 ( V_12 -> V_59 ) ;
V_12 -> V_72 -- ;
F_38 ( V_12 -> V_59 ) ;
goto V_161;
V_158:
F_36 ( V_12 -> V_59 ) ;
F_117 ( V_77 , V_147 ) ;
V_154:
if ( F_24 ( V_77 -> V_90 [ V_151 ] == 0 ) )
V_77 -> V_93 [ V_151 ] = 1 ;
return NULL ;
}
static struct V_1 * F_138 ( struct V_11 * V_12 , int V_147 ,
struct V_35 * V_35 , T_2 V_88 )
{
const bool V_151 = F_118 ( V_147 ) != 0 ;
F_139 ( V_78 ) ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
V_77 = F_140 ( V_12 , V_35 ) ;
V_164:
V_2 = F_121 ( V_77 , V_147 , V_35 , V_88 ) ;
if ( V_2 )
return V_2 ;
if ( ! ( V_88 & V_165 ) || F_24 ( F_102 ( V_12 ) ) ) {
F_141 ( V_77 ) ;
return NULL ;
}
F_142 ( & V_77 -> V_78 [ V_151 ] , & V_78 ,
V_166 ) ;
F_143 ( V_12 , V_35 , V_147 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_144 () ;
F_110 ( V_12 , V_146 -> V_136 ) ;
F_36 ( V_12 -> V_59 ) ;
F_145 ( & V_77 -> V_78 [ V_151 ] , & V_78 ) ;
goto V_164;
}
struct V_1 * F_146 ( struct V_11 * V_12 , int V_6 , T_2 V_88 )
{
struct V_1 * V_2 ;
F_147 ( V_6 != V_167 && V_6 != V_168 ) ;
F_148 ( V_88 , V_12 -> V_98 ) ;
F_36 ( V_12 -> V_59 ) ;
V_2 = F_138 ( V_12 , V_6 , NULL , V_88 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_149 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_88 )
{
struct V_1 * V_2 = F_146 ( V_12 , F_150 ( V_35 ) , V_88 ) ;
if ( F_24 ( ! V_2 ) )
return F_151 ( - V_99 ) ;
F_152 (bio) {
struct V_35 * V_169 = V_35 ;
int V_20 ;
F_153 ( V_12 , & V_169 ) ;
V_20 = F_154 ( V_12 , V_2 , V_169 ) ;
if ( F_24 ( V_20 ) ) {
F_155 ( V_2 ) ;
return F_151 ( V_20 ) ;
}
}
return V_2 ;
}
void F_156 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_159 ( V_12 , V_2 ) ;
if ( F_160 ( V_2 ) )
F_161 ( V_12 , V_2 ) ;
F_147 ( F_162 ( V_2 ) ) ;
F_163 ( V_12 , V_2 ) ;
}
static void F_164 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_170 )
{
F_1 ( V_2 , 1 ) ;
F_165 ( V_12 , V_2 , V_170 ) ;
}
static void F_166 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_171 )
{
if ( V_171 == V_5 -> V_172 )
return;
if ( F_167 ( V_5 ) ) {
F_168 ( V_7 , V_5 , V_173 ,
F_167 ( V_5 ) * ( V_171 - V_5 -> V_172 ) ) ;
F_168 ( V_7 , V_5 , V_174 , ( V_171 - V_5 -> V_172 ) ) ;
}
V_5 -> V_172 = V_171 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_171 = V_34 ;
if ( V_5 -> V_175 )
F_166 ( V_7 , & F_169 ( V_5 ) -> V_10 , V_171 ) ;
F_166 ( V_7 , V_5 , V_171 ) ;
}
void F_170 ( struct V_11 * V_12 , struct V_1 * V_176 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_176 -> V_32 ) )
return;
F_171 ( V_12 , V_176 ) ;
F_43 ( V_176 -> V_35 != NULL ) ;
if ( V_176 -> V_43 & V_159 ) {
unsigned int V_65 = V_176 -> V_43 ;
struct V_76 * V_77 = F_172 ( V_176 ) ;
F_147 ( ! F_63 ( & V_176 -> V_21 ) ) ;
F_147 ( ! F_173 ( & V_176 -> V_25 ) ) ;
F_104 ( V_77 , V_176 ) ;
F_117 ( V_77 , V_65 ) ;
F_141 ( V_77 ) ;
}
}
void F_155 ( struct V_1 * V_176 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_176 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_170 ( V_12 , V_176 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_174 ( struct V_1 * V_2 , struct V_177 * V_177 ,
unsigned int V_178 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_179 -> V_180 = V_177 ;
V_35 -> V_179 -> V_181 = 0 ;
V_35 -> V_179 -> V_182 = V_178 ;
V_35 -> V_40 = V_178 ;
V_35 -> V_183 = 1 ;
V_35 -> V_184 = 1 ;
V_2 -> V_185 = V_2 -> V_186 = V_178 ;
V_2 -> V_187 = 1 ;
V_2 -> V_54 = F_175 ( V_35 ) ;
}
static bool F_176 ( struct V_11 * V_12 , struct V_1 * V_176 ,
struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_142 & V_189 ;
if ( ! F_177 ( V_12 , V_176 , V_35 ) )
return false ;
F_178 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_179 ( V_176 ) ;
V_176 -> V_53 -> V_190 = V_35 ;
V_176 -> V_53 = V_35 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_180 ( V_176 -> V_191 , F_181 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_182 ( struct V_11 * V_12 ,
struct V_1 * V_176 , struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_142 & V_189 ;
if ( ! F_183 ( V_12 , V_176 , V_35 ) )
return false ;
F_184 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_179 ( V_176 ) ;
V_35 -> V_190 = V_176 -> V_35 ;
V_176 -> V_35 = V_35 ;
V_176 -> V_54 = F_175 ( V_35 ) ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_180 ( V_176 -> V_191 , F_181 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_185 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_192 )
{
struct V_193 * V_194 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_194 = V_146 -> V_194 ;
if ( ! V_194 )
goto V_161;
* V_192 = 0 ;
F_186 (rq, &plug->list, queuelist) {
int V_195 ;
if ( V_2 -> V_12 == V_12 )
( * V_192 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_187 ( V_2 , V_35 ) )
continue;
V_195 = F_188 ( V_2 , V_35 ) ;
if ( V_195 == V_196 ) {
V_20 = F_176 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_195 == V_197 ) {
V_20 = F_182 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_161:
return V_20 ;
}
void F_189 ( struct V_1 * V_176 , struct V_35 * V_35 )
{
V_176 -> V_52 = V_198 ;
V_176 -> V_43 |= V_35 -> V_142 & V_199 ;
if ( V_35 -> V_142 & V_200 )
V_176 -> V_43 |= V_189 ;
V_176 -> V_201 = 0 ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_191 = F_181 ( V_35 ) ;
F_190 ( V_176 -> V_12 , V_176 , V_35 ) ;
}
void V_129 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_141 = ! ! ( V_35 -> V_142 & V_202 ) ;
struct V_193 * V_194 ;
int V_195 , V_147 , V_170 = V_203 ;
struct V_1 * V_176 ;
unsigned int V_192 = 0 ;
F_153 ( V_12 , & V_35 ) ;
if ( V_35 -> V_142 & ( V_143 | V_144 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_170 = V_204 ;
goto V_205;
}
if ( F_185 ( V_12 , V_35 , & V_192 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_195 = F_191 ( V_12 , & V_176 , V_35 ) ;
if ( V_195 == V_196 ) {
if ( F_176 ( V_12 , V_176 , V_35 ) ) {
F_192 ( V_12 , V_176 , V_35 ) ;
if ( ! F_193 ( V_12 , V_176 ) )
F_194 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
} else if ( V_195 == V_197 ) {
if ( F_182 ( V_12 , V_176 , V_35 ) ) {
F_192 ( V_12 , V_176 , V_35 ) ;
if ( ! F_195 ( V_12 , V_176 ) )
F_194 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
}
V_205:
V_147 = F_150 ( V_35 ) ;
if ( V_141 )
V_147 |= V_202 ;
V_176 = F_138 ( V_12 , V_147 , V_35 , V_207 ) ;
if ( F_24 ( ! V_176 ) ) {
F_29 ( V_35 , - V_208 ) ;
goto V_206;
}
F_189 ( V_176 , V_35 ) ;
if ( F_23 ( V_209 , & V_12 -> V_121 ) )
V_176 -> V_7 = F_196 () ;
V_194 = V_146 -> V_194 ;
if ( V_194 ) {
if ( F_63 ( & V_194 -> V_210 ) )
F_197 ( V_12 ) ;
else {
if ( ! V_194 -> V_211 ) {
struct V_1 * V_212 ;
V_212 = F_198 ( V_194 -> V_210 . V_213 ) ;
if ( V_212 -> V_12 != V_12 )
V_194 -> V_211 = 1 ;
}
if ( V_192 >= V_214 ) {
F_199 ( V_194 , false ) ;
F_197 ( V_12 ) ;
}
}
F_200 ( & V_176 -> V_21 , & V_194 -> V_210 ) ;
F_1 ( V_176 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_164 ( V_12 , V_176 , V_170 ) ;
F_37 ( V_12 ) ;
V_206:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_201 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_215 ;
if ( F_202 ( V_35 ) && V_19 != V_19 -> V_216 ) {
struct V_4 * V_217 = V_19 -> V_218 ;
V_35 -> V_46 += V_217 -> V_219 ;
V_35 -> V_215 = V_19 -> V_216 ;
F_203 ( F_15 ( V_35 -> V_215 ) , V_35 ,
V_19 -> V_220 ,
V_35 -> V_46 - V_217 -> V_219 ) ;
}
}
static void F_204 ( struct V_35 * V_35 )
{
char V_221 [ V_222 ] ;
F_25 ( V_50 L_11 ) ;
F_25 ( V_50 L_12 ,
F_205 ( V_35 -> V_215 , V_221 ) ,
V_35 -> V_142 ,
( unsigned long long ) V_35 -> V_46 + F_202 ( V_35 ) ,
( long long ) ( F_206 ( V_35 -> V_215 -> V_223 ) >> 9 ) ) ;
F_26 ( V_224 , & V_35 -> V_38 ) ;
}
static int T_4 F_207 ( char * V_225 )
{
return F_208 ( & V_226 , V_225 ) ;
}
static bool F_209 ( struct V_4 * V_5 , unsigned int V_227 )
{
return V_5 -> V_228 && F_210 ( & V_226 , V_227 ) ;
}
static int T_4 F_211 ( void )
{
struct V_229 * V_230 = F_212 ( L_13 ,
NULL , & V_226 ) ;
return F_213 ( V_230 ) ? F_214 ( V_230 ) : 0 ;
}
static inline bool F_209 ( struct V_4 * V_5 ,
unsigned int V_227 )
{
return false ;
}
static inline int F_215 ( struct V_35 * V_35 , unsigned int V_231 )
{
V_24 V_232 ;
if ( ! V_231 )
return 0 ;
V_232 = F_206 ( V_35 -> V_215 -> V_223 ) >> 9 ;
if ( V_232 ) {
V_24 V_233 = V_35 -> V_46 ;
if ( V_232 < V_231 || V_232 - V_231 < V_233 ) {
F_204 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_216 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_231 = F_202 ( V_35 ) ;
int V_101 = - V_39 ;
char V_221 [ V_222 ] ;
struct V_4 * V_5 ;
F_217 () ;
if ( F_215 ( V_35 , V_231 ) )
goto V_234;
V_12 = F_15 ( V_35 -> V_215 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_14
L_15 ,
F_205 ( V_35 -> V_215 , V_221 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_234;
}
if ( F_24 ( ! ( V_35 -> V_142 & V_235 ) &&
V_231 > F_218 ( V_12 ) ) ) {
F_25 ( V_41 L_16 ,
F_205 ( V_35 -> V_215 , V_221 ) ,
F_202 ( V_35 ) ,
F_218 ( V_12 ) ) ;
goto V_234;
}
V_5 = V_35 -> V_215 -> V_218 ;
if ( F_209 ( V_5 , V_35 -> V_40 ) ||
F_209 ( & F_169 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_234;
F_201 ( V_35 ) ;
if ( F_219 ( V_35 ) && F_220 ( V_35 ) )
goto V_234;
if ( F_215 ( V_35 , V_231 ) )
goto V_234;
if ( ( V_35 -> V_142 & ( V_143 | V_144 ) ) && ! V_12 -> V_236 ) {
V_35 -> V_142 &= ~ ( V_143 | V_144 ) ;
if ( ! V_231 ) {
V_101 = 0 ;
goto V_234;
}
}
if ( ( V_35 -> V_142 & V_235 ) &&
( ! F_221 ( V_12 ) ||
( ( V_35 -> V_142 & V_237 ) &&
! F_222 ( V_12 ) ) ) ) {
V_101 = - V_238 ;
goto V_234;
}
F_148 ( V_239 , V_12 -> V_98 ) ;
if ( F_223 ( V_12 , V_35 ) )
return false ;
F_224 ( V_12 , V_35 ) ;
return true ;
V_234:
F_29 ( V_35 , V_101 ) ;
return false ;
}
void F_225 ( struct V_35 * V_35 )
{
struct V_240 V_241 ;
if ( ! F_216 ( V_35 ) )
return;
if ( V_146 -> V_240 ) {
F_226 ( V_146 -> V_240 , V_35 ) ;
return;
}
F_147 ( V_35 -> V_190 ) ;
F_227 ( & V_241 ) ;
V_146 -> V_240 = & V_241 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_215 ) ;
V_12 -> V_242 ( V_12 , V_35 ) ;
V_35 = F_228 ( V_146 -> V_240 ) ;
} while ( V_35 );
V_146 -> V_240 = NULL ;
}
void F_229 ( int V_6 , struct V_35 * V_35 )
{
int V_90 = F_202 ( V_35 ) ;
V_35 -> V_142 |= V_6 ;
if ( F_230 ( V_35 ) && ! ( V_6 & V_235 ) ) {
if ( V_6 & V_168 ) {
F_231 ( V_243 , V_90 ) ;
} else {
F_232 ( V_35 -> V_40 ) ;
F_231 ( V_244 , V_90 ) ;
}
if ( F_24 ( V_245 ) ) {
char V_221 [ V_222 ] ;
F_25 ( V_246 L_17 ,
V_146 -> V_247 , F_233 ( V_146 ) ,
( V_6 & V_168 ) ? L_18 : L_19 ,
( unsigned long long ) V_35 -> V_46 ,
F_205 ( V_35 -> V_215 , V_221 ) ,
V_90 ) ;
}
}
F_225 ( V_35 ) ;
}
int F_234 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_235 )
return 0 ;
if ( F_31 ( V_2 ) > F_235 ( V_12 ) ||
F_33 ( V_2 ) > F_218 ( V_12 ) << 9 ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
F_236 ( V_2 ) ;
if ( V_2 -> V_187 > F_237 ( V_12 ) ) {
F_25 ( V_41 L_21 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_238 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_170 = V_248 ;
if ( F_234 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_209 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_24 ( F_102 ( V_12 ) ) ) {
F_57 ( V_12 -> V_59 , V_65 ) ;
return - V_208 ;
}
F_147 ( F_162 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_143 | V_144 ) )
V_170 = V_204 ;
F_164 ( V_12 , V_2 , V_170 ) ;
if ( V_170 == V_204 )
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_239 ( const struct V_1 * V_2 )
{
unsigned int V_188 = V_2 -> V_43 & V_189 ;
unsigned int V_227 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_249 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_190 ) {
if ( ( V_35 -> V_142 & V_188 ) != V_188 )
break;
V_227 += V_35 -> V_40 ;
}
F_147 ( F_33 ( V_2 ) && ! V_227 ) ;
return V_227 ;
}
static void F_240 ( struct V_1 * V_176 , unsigned int V_227 )
{
if ( F_3 ( V_176 ) ) {
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_241 ( V_7 , V_5 , V_250 [ V_6 ] , V_227 >> 9 ) ;
F_12 () ;
}
}
static void F_242 ( struct V_1 * V_176 )
{
if ( F_3 ( V_176 ) && ! ( V_176 -> V_43 & V_47 ) ) {
unsigned long V_251 = V_34 - V_176 -> V_33 ;
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_5 ( V_7 , V_5 , V_252 [ V_6 ] ) ;
F_241 ( V_7 , V_5 , V_253 [ V_6 ] , V_251 ) ;
F_10 ( V_7 , V_5 ) ;
F_243 ( V_5 , V_6 ) ;
F_244 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_245 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_246 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_254 ) ) {
if ( V_2 -> V_43 & V_255 )
F_247 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_254 ;
F_248 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_256 || V_12 -> V_256 == V_2 ) {
V_12 -> V_257 = F_249 ( V_2 ) ;
V_12 -> V_256 = NULL ;
}
if ( V_2 -> V_43 & V_258 )
break;
if ( V_12 -> V_259 && F_33 ( V_2 ) ) {
V_2 -> V_187 ++ ;
}
if ( ! V_12 -> V_126 )
break;
V_20 = V_12 -> V_126 ( V_12 , V_2 ) ;
if ( V_20 == V_260 ) {
break;
} else if ( V_20 == V_261 ) {
if ( V_12 -> V_259 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_258 ) ) {
-- V_2 -> V_187 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_262 ) {
V_2 -> V_43 |= V_44 ;
F_250 ( V_2 ) ;
F_251 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_22 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_252 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_147 ( F_63 ( & V_2 -> V_21 ) ) ;
F_147 ( F_253 ( V_2 ) ) ;
F_254 ( & V_2 -> V_21 ) ;
if ( F_255 ( V_2 ) ) {
V_12 -> V_74 [ F_256 ( V_2 ) ] ++ ;
F_257 ( V_2 ) ;
}
}
void F_250 ( struct V_1 * V_176 )
{
F_252 ( V_176 ) ;
V_176 -> V_186 = F_33 ( V_176 ) ;
if ( F_24 ( F_258 ( V_176 ) ) )
V_176 -> V_263 -> V_186 = F_33 ( V_176 -> V_263 ) ;
F_259 ( V_176 ) ;
}
struct V_1 * F_260 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_245 ( V_12 ) ;
if ( V_2 )
F_250 ( V_2 ) ;
return V_2 ;
}
bool F_261 ( struct V_1 * V_176 , int error , unsigned int V_264 )
{
int V_265 , V_266 , V_267 = 0 ;
struct V_35 * V_35 ;
if ( ! V_176 -> V_35 )
return false ;
F_262 ( V_176 -> V_12 , V_176 ) ;
if ( V_176 -> V_52 == V_198 )
V_176 -> V_201 = 0 ;
if ( error && V_176 -> V_52 == V_198 &&
! ( V_176 -> V_43 & V_44 ) ) {
char * V_268 ;
switch ( error ) {
case - V_269 :
V_268 = L_23 ;
break;
case - V_270 :
V_268 = L_24 ;
break;
case - V_271 :
V_268 = L_25 ;
break;
case - V_39 :
default:
V_268 = L_26 ;
break;
}
F_136 ( V_41 L_27 ,
V_268 , V_176 -> V_9 ?
V_176 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_176 ) ) ;
}
F_240 ( V_176 , V_264 ) ;
V_265 = V_266 = 0 ;
while ( ( V_35 = V_176 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_264 >= V_35 -> V_40 ) {
V_176 -> V_35 = V_35 -> V_190 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_176 , V_35 , V_36 , error ) ;
V_267 = 0 ;
V_266 = 0 ;
} else {
int V_272 = V_35 -> V_273 + V_267 ;
if ( F_24 ( V_272 >= V_35 -> V_183 ) ) {
F_30 ( V_176 , L_28 ) ;
F_25 ( V_41 L_29 ,
V_42 , V_272 , V_35 -> V_183 ) ;
break;
}
V_36 = F_263 ( V_35 , V_272 ) -> V_182 ;
F_264 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_264 ) ) {
V_266 += V_264 ;
V_265 += V_264 ;
break;
}
V_267 ++ ;
V_266 += V_36 ;
}
V_265 += V_36 ;
V_264 -= V_36 ;
V_35 = V_176 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_264 <= 0 ) )
break;
}
}
if ( ! V_176 -> V_35 ) {
V_176 -> V_185 = 0 ;
return false ;
}
if ( V_266 ) {
F_21 ( V_176 , V_35 , V_266 , error ) ;
V_35 -> V_273 += V_267 ;
F_265 ( V_35 ) -> V_181 += V_264 ;
F_265 ( V_35 ) -> V_182 -= V_264 ;
}
V_176 -> V_185 -= V_265 ;
V_176 -> V_54 = F_175 ( V_176 -> V_35 ) ;
if ( V_176 -> V_52 == V_198 || ( V_176 -> V_43 & V_235 ) )
V_176 -> V_23 += V_265 >> 9 ;
if ( V_176 -> V_43 & V_249 ) {
V_176 -> V_43 &= ~ V_189 ;
V_176 -> V_43 |= V_176 -> V_35 -> V_142 & V_189 ;
}
if ( F_33 ( V_176 ) < F_266 ( V_176 ) ) {
F_30 ( V_176 , L_30 ) ;
V_176 -> V_185 = F_266 ( V_176 ) ;
}
F_236 ( V_176 ) ;
return true ;
}
static bool F_267 ( struct V_1 * V_2 , int error ,
unsigned int V_264 ,
unsigned int V_274 )
{
if ( F_261 ( V_2 , error , V_264 ) )
return true ;
if ( F_24 ( F_258 ( V_2 ) ) &&
F_261 ( V_2 -> V_263 , error , V_274 ) )
return true ;
if ( F_268 ( V_2 -> V_12 ) )
F_269 ( V_2 -> V_9 ) ;
return false ;
}
void F_270 ( struct V_1 * V_176 )
{
struct V_11 * V_12 = V_176 -> V_12 ;
V_176 -> V_43 &= ~ V_258 ;
if ( V_12 -> V_127 )
V_12 -> V_127 ( V_12 , V_176 ) ;
}
static void F_271 ( struct V_1 * V_176 , int error )
{
if ( F_160 ( V_176 ) )
F_161 ( V_176 -> V_12 , V_176 ) ;
F_147 ( F_162 ( V_176 ) ) ;
if ( F_24 ( V_275 ) && V_176 -> V_52 == V_198 )
F_272 ( & V_176 -> V_12 -> V_17 ) ;
F_157 ( V_176 ) ;
if ( V_176 -> V_43 & V_258 )
F_270 ( V_176 ) ;
F_242 ( V_176 ) ;
if ( V_176 -> V_234 )
V_176 -> V_234 ( V_176 , error ) ;
else {
if ( F_258 ( V_176 ) )
F_170 ( V_176 -> V_263 -> V_12 , V_176 -> V_263 ) ;
F_170 ( V_176 -> V_12 , V_176 ) ;
}
}
static bool F_273 ( struct V_1 * V_2 , int error ,
unsigned int V_264 , unsigned int V_274 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_267 ( V_2 , error , V_264 , V_274 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_271 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_274 ( struct V_1 * V_2 , int error ,
unsigned int V_264 , unsigned int V_274 )
{
if ( F_267 ( V_2 , error , V_264 , V_274 ) )
return true ;
F_271 ( V_2 , error ) ;
return false ;
}
bool F_275 ( struct V_1 * V_2 , int error , unsigned int V_264 )
{
return F_273 ( V_2 , error , V_264 , 0 ) ;
}
void F_276 ( struct V_1 * V_2 , int error )
{
bool V_276 ;
unsigned int V_274 = 0 ;
if ( F_24 ( F_258 ( V_2 ) ) )
V_274 = F_33 ( V_2 -> V_263 ) ;
V_276 = F_273 ( V_2 , error , F_33 ( V_2 ) , V_274 ) ;
F_147 ( V_276 ) ;
}
bool F_277 ( struct V_1 * V_2 , int error )
{
return F_275 ( V_2 , error , F_266 ( V_2 ) ) ;
}
bool F_278 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_275 ( V_2 , error , F_239 ( V_2 ) ) ;
}
bool F_279 ( struct V_1 * V_2 , int error , unsigned int V_264 )
{
return F_274 ( V_2 , error , V_264 , 0 ) ;
}
void F_251 ( struct V_1 * V_2 , int error )
{
bool V_276 ;
unsigned int V_274 = 0 ;
if ( F_24 ( F_258 ( V_2 ) ) )
V_274 = F_33 ( V_2 -> V_263 ) ;
V_276 = F_274 ( V_2 , error , F_33 ( V_2 ) , V_274 ) ;
F_147 ( V_276 ) ;
}
bool F_280 ( struct V_1 * V_2 , int error )
{
return F_279 ( V_2 , error , F_266 ( V_2 ) ) ;
}
bool F_281 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_279 ( V_2 , error , F_239 ( V_2 ) ) ;
}
void F_190 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_142 & V_277 ;
if ( F_230 ( V_35 ) ) {
V_2 -> V_187 = F_282 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_175 ( V_35 ) ;
}
V_2 -> V_185 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_215 )
V_2 -> V_9 = V_35 -> V_215 -> V_278 ;
}
void F_283 ( struct V_1 * V_2 )
{
struct V_279 V_280 ;
struct V_281 * V_282 ;
F_284 (bvec, rq, iter)
F_285 ( V_282 -> V_180 ) ;
}
int F_286 ( struct V_11 * V_12 )
{
if ( V_12 -> V_283 )
return V_12 -> V_283 ( V_12 ) ;
return 0 ;
}
void F_287 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_190 ;
F_288 ( V_35 ) ;
}
}
static void F_289 ( struct V_1 * V_284 , struct V_1 * V_285 )
{
V_284 -> V_7 = V_285 -> V_7 ;
V_284 -> V_43 = ( V_285 -> V_43 & V_286 ) | V_287 ;
V_284 -> V_52 = V_285 -> V_52 ;
V_284 -> V_23 = F_7 ( V_285 ) ;
V_284 -> V_185 = F_33 ( V_285 ) ;
V_284 -> V_187 = V_285 -> V_187 ;
V_284 -> V_191 = V_285 -> V_191 ;
V_284 -> V_288 = V_285 -> V_288 ;
}
int F_290 ( struct V_1 * V_2 , struct V_1 * V_289 ,
struct V_290 * V_291 , T_2 V_88 ,
int (* F_291)( struct V_35 * , struct V_35 * , void * ) ,
void * V_292 )
{
struct V_35 * V_35 , * V_293 ;
if ( ! V_291 )
V_291 = V_294 ;
F_16 ( NULL , V_2 ) ;
F_292 (bio_src, rq_src) {
V_35 = F_293 ( V_88 , V_293 -> V_295 , V_291 ) ;
if ( ! V_35 )
goto V_296;
F_294 ( V_35 , V_293 ) ;
if ( F_27 ( V_293 ) &&
F_295 ( V_35 , V_293 , V_88 , V_291 ) )
goto V_296;
if ( F_291 && F_291 ( V_35 , V_293 , V_292 ) )
goto V_296;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_190 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_289 ( V_2 , V_289 ) ;
return 0 ;
V_296:
if ( V_35 )
F_296 ( V_35 , V_291 ) ;
F_287 ( V_2 ) ;
return - V_99 ;
}
int F_297 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_298 ( V_61 , V_57 ) ;
}
int F_299 ( struct V_11 * V_12 ,
struct V_297 * V_298 , unsigned long V_299 )
{
return F_40 ( V_61 , V_298 , V_299 ) ;
}
void F_300 ( struct V_193 * V_194 )
{
struct V_300 * V_301 = V_146 ;
V_194 -> V_302 = V_303 ;
F_17 ( & V_194 -> V_210 ) ;
F_17 ( & V_194 -> V_304 ) ;
V_194 -> V_211 = 0 ;
if ( ! V_301 -> V_194 ) {
V_301 -> V_194 = V_194 ;
}
}
static int F_301 ( void * V_305 , struct V_306 * V_307 , struct V_306 * V_221 )
{
struct V_1 * V_308 = F_35 ( V_307 , struct V_1 , V_21 ) ;
struct V_1 * V_309 = F_35 ( V_221 , struct V_1 , V_21 ) ;
return ! ( V_308 -> V_12 <= V_309 -> V_12 ) ;
}
static void F_302 ( struct V_11 * V_12 , unsigned int V_310 ,
bool V_311 )
__releases( V_12 -> V_59 )
{
F_303 ( V_12 , V_310 , ! V_311 ) ;
if ( F_24 ( F_102 ( V_12 ) ) ) {
F_304 ( V_12 -> V_59 ) ;
return;
}
if ( V_311 ) {
F_304 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_304 ( V_12 -> V_59 ) ;
}
}
static void F_305 ( struct V_193 * V_194 , bool V_311 )
{
F_306 ( V_312 ) ;
while ( ! F_63 ( & V_194 -> V_304 ) ) {
F_307 ( & V_194 -> V_304 , & V_312 ) ;
while ( ! F_63 ( & V_312 ) ) {
struct V_313 * V_314 = F_308 ( & V_312 ,
struct V_313 ,
V_210 ) ;
F_309 ( & V_314 -> V_210 ) ;
V_314 -> V_315 ( V_314 , V_311 ) ;
}
}
}
struct V_313 * F_310 ( T_6 V_316 , void * V_292 ,
int V_317 )
{
struct V_193 * V_194 = V_146 -> V_194 ;
struct V_313 * V_314 ;
if ( ! V_194 )
return NULL ;
F_311 (cb, &plug->cb_list, list)
if ( V_314 -> V_315 == V_316 && V_314 -> V_292 == V_292 )
return V_314 ;
F_147 ( V_317 < sizeof( * V_314 ) ) ;
V_314 = F_312 ( V_317 , V_239 ) ;
if ( V_314 ) {
V_314 -> V_292 = V_292 ;
V_314 -> V_315 = V_316 ;
F_313 ( & V_314 -> V_210 , & V_194 -> V_304 ) ;
}
return V_314 ;
}
void F_199 ( struct V_193 * V_194 , bool V_311 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_306 ( V_210 ) ;
unsigned int V_310 ;
F_147 ( V_194 -> V_302 != V_303 ) ;
F_305 ( V_194 , V_311 ) ;
if ( F_63 ( & V_194 -> V_210 ) )
return;
F_307 ( & V_194 -> V_210 , & V_210 ) ;
if ( V_194 -> V_211 ) {
F_314 ( NULL , & V_210 , F_301 ) ;
V_194 -> V_211 = 0 ;
}
V_12 = NULL ;
V_310 = 0 ;
F_315 ( V_65 ) ;
while ( ! F_63 ( & V_210 ) ) {
V_2 = F_198 ( V_210 . V_318 ) ;
F_254 ( & V_2 -> V_21 ) ;
F_147 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_302 ( V_12 , V_310 , V_311 ) ;
V_12 = V_2 -> V_12 ;
V_310 = 0 ;
F_316 ( V_12 -> V_59 ) ;
}
if ( F_24 ( F_102 ( V_12 ) ) ) {
F_251 ( V_2 , - V_208 ) ;
continue;
}
if ( V_2 -> V_43 & ( V_143 | V_144 ) )
F_165 ( V_12 , V_2 , V_204 ) ;
else
F_165 ( V_12 , V_2 , V_319 ) ;
V_310 ++ ;
}
if ( V_12 )
F_302 ( V_12 , V_310 , V_311 ) ;
F_317 ( V_65 ) ;
}
void F_318 ( struct V_193 * V_194 )
{
F_199 ( V_194 , false ) ;
if ( V_194 == V_146 -> V_194 )
V_146 -> V_194 = NULL ;
}
int T_4 F_319 ( void )
{
F_320 ( V_320 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_321 ( L_31 ,
V_321 | V_322 , 0 ) ;
if ( ! V_61 )
F_322 ( L_32 ) ;
V_97 = F_323 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_323 , NULL ) ;
V_102 = F_323 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_323 , NULL ) ;
return 0 ;
}
