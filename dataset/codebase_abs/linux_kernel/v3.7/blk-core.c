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
if ( F_54 ( ! F_52 ( V_12 ) ) )
F_55 ( V_61 , & V_12 -> V_58 , 0 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
unsigned long V_65 ;
F_57 ( V_12 -> V_59 , V_65 ) ;
F_37 ( V_12 ) ;
F_58 ( V_12 -> V_59 , V_65 ) ;
}
void F_59 ( struct V_11 * V_12 )
{
F_60 ( & V_12 -> V_66 ) ;
}
void F_61 ( struct V_11 * V_12 , bool V_67 )
{
int V_68 ;
while ( true ) {
bool V_69 = false ;
F_36 ( V_12 -> V_59 ) ;
if ( V_12 -> V_70 )
F_62 ( V_12 ) ;
F_63 ( V_12 ) ;
if ( ! F_64 ( & V_12 -> V_71 ) && V_12 -> V_64 )
F_37 ( V_12 ) ;
V_69 |= V_12 -> V_72 ;
if ( V_67 ) {
V_69 |= ! F_64 ( & V_12 -> V_71 ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_69 |= V_12 -> V_73 [ V_68 ] ;
V_69 |= V_12 -> V_74 [ V_68 ] ;
V_69 |= ! F_64 ( & V_12 -> V_75 [ V_68 ] ) ;
}
}
F_38 ( V_12 -> V_59 ) ;
if ( ! V_69 )
break;
F_65 ( 10 ) ;
}
if ( V_12 -> V_64 ) {
struct V_76 * V_77 ;
F_36 ( V_12 -> V_59 ) ;
F_66 (rl, q)
for ( V_68 = 0 ; V_68 < F_67 ( V_77 -> V_78 ) ; V_68 ++ )
F_68 ( & V_77 -> V_78 [ V_68 ] ) ;
F_38 ( V_12 -> V_59 ) ;
}
}
void F_69 ( struct V_11 * V_12 )
{
bool V_69 ;
F_36 ( V_12 -> V_59 ) ;
V_69 = ! V_12 -> V_79 ++ ;
F_48 ( V_80 , V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
if ( V_69 ) {
F_61 ( V_12 , false ) ;
F_70 () ;
}
}
void F_71 ( struct V_11 * V_12 )
{
F_36 ( V_12 -> V_59 ) ;
if ( ! -- V_12 -> V_79 )
F_45 ( V_80 , V_12 ) ;
F_72 ( V_12 -> V_79 < 0 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_73 ( struct V_11 * V_12 )
{
T_1 * V_81 = V_12 -> V_59 ;
F_74 ( & V_12 -> V_82 ) ;
F_75 ( V_83 , V_12 ) ;
F_36 ( V_81 ) ;
V_12 -> V_79 ++ ;
F_48 ( V_80 , V_12 ) ;
F_48 ( V_84 , V_12 ) ;
F_48 ( V_85 , V_12 ) ;
F_48 ( V_83 , V_12 ) ;
F_38 ( V_81 ) ;
F_76 ( & V_12 -> V_82 ) ;
F_61 ( V_12 , true ) ;
F_50 ( & V_12 -> V_17 . V_86 ) ;
F_49 ( V_12 ) ;
F_36 ( V_81 ) ;
if ( V_12 -> V_59 != & V_12 -> V_87 )
V_12 -> V_59 = & V_12 -> V_87 ;
F_38 ( V_81 ) ;
F_59 ( V_12 ) ;
}
int F_77 ( struct V_76 * V_77 , struct V_11 * V_12 ,
T_2 V_88 )
{
if ( F_24 ( V_77 -> V_89 ) )
return 0 ;
V_77 -> V_12 = V_12 ;
V_77 -> V_90 [ V_91 ] = V_77 -> V_90 [ V_92 ] = 0 ;
V_77 -> V_93 [ V_91 ] = V_77 -> V_93 [ V_92 ] = 0 ;
F_78 ( & V_77 -> V_78 [ V_91 ] ) ;
F_78 ( & V_77 -> V_78 [ V_92 ] ) ;
V_77 -> V_89 = F_79 ( V_94 , V_95 ,
V_96 , V_97 ,
V_88 , V_12 -> V_98 ) ;
if ( ! V_77 -> V_89 )
return - V_99 ;
return 0 ;
}
void F_80 ( struct V_76 * V_77 )
{
if ( V_77 -> V_89 )
F_81 ( V_77 -> V_89 ) ;
}
struct V_11 * F_82 ( T_2 V_88 )
{
return F_83 ( V_88 , - 1 ) ;
}
struct V_11 * F_83 ( T_2 V_88 , int V_100 )
{
struct V_11 * V_12 ;
int V_101 ;
V_12 = F_84 ( V_102 ,
V_88 | V_103 , V_100 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_104 = F_85 ( & V_105 , 0 , 0 , V_88 ) ;
if ( V_12 -> V_104 < 0 )
goto V_106;
V_12 -> V_17 . V_107 =
( V_108 * 1024 ) / V_109 ;
V_12 -> V_17 . V_110 = 0 ;
V_12 -> V_17 . V_111 = V_112 ;
V_12 -> V_17 . V_113 = L_9 ;
V_12 -> V_98 = V_100 ;
V_101 = F_86 ( & V_12 -> V_17 ) ;
if ( V_101 )
goto V_114;
F_87 ( & V_12 -> V_17 . V_86 ,
V_115 , ( unsigned long ) V_12 ) ;
F_87 ( & V_12 -> V_63 , V_116 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_71 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_117 ) ;
#ifdef F_88
F_17 ( & V_12 -> V_118 ) ;
#endif
F_17 ( & V_12 -> V_75 [ 0 ] ) ;
F_17 ( & V_12 -> V_75 [ 1 ] ) ;
F_17 ( & V_12 -> V_119 ) ;
F_89 ( & V_12 -> V_58 , F_34 ) ;
F_90 ( & V_12 -> V_66 , & V_120 ) ;
F_91 ( & V_12 -> V_82 ) ;
F_92 ( & V_12 -> V_87 ) ;
V_12 -> V_59 = & V_12 -> V_87 ;
V_12 -> V_79 = 1 ;
F_93 ( V_80 , & V_12 -> V_121 ) ;
if ( F_94 ( V_12 ) )
goto V_114;
return V_12 ;
V_114:
F_95 ( & V_105 , V_12 -> V_104 ) ;
V_106:
F_96 ( V_102 , V_12 ) ;
return NULL ;
}
struct V_11 * F_97 ( T_3 * V_122 , T_1 * V_81 )
{
return F_98 ( V_122 , V_81 , - 1 ) ;
}
struct V_11 *
F_98 ( T_3 * V_122 , T_1 * V_81 , int V_100 )
{
struct V_11 * V_123 , * V_12 ;
V_123 = F_83 ( V_124 , V_100 ) ;
if ( ! V_123 )
return NULL ;
V_12 = F_99 ( V_123 , V_122 , V_81 ) ;
if ( ! V_12 )
F_73 ( V_123 ) ;
return V_12 ;
}
struct V_11 *
F_99 ( struct V_11 * V_12 , T_3 * V_122 ,
T_1 * V_81 )
{
if ( ! V_12 )
return NULL ;
if ( F_77 ( & V_12 -> V_125 , V_12 , V_124 ) )
return NULL ;
V_12 -> V_64 = V_122 ;
V_12 -> V_126 = NULL ;
V_12 -> V_127 = NULL ;
V_12 -> V_121 |= V_128 ;
if ( V_81 )
V_12 -> V_59 = V_81 ;
F_100 ( V_12 , V_129 ) ;
V_12 -> V_130 = V_131 ;
if ( F_101 ( V_12 , NULL ) )
return NULL ;
return V_12 ;
}
bool F_102 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_103 ( V_12 ) ) ) {
F_104 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_105 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_132 ) {
F_106 ( V_77 -> V_12 , V_2 ) ;
if ( V_2 -> V_133 . V_134 )
F_107 ( V_2 -> V_133 . V_134 -> V_135 ) ;
}
F_108 ( V_2 , V_77 -> V_89 ) ;
}
static inline int F_109 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 )
return 0 ;
return V_135 -> V_137 == V_12 -> V_138 ||
( V_135 -> V_137 > 0
&& F_110 ( V_34 , V_135 -> V_139 + V_140 ) ) ;
}
static void F_111 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 || F_109 ( V_12 , V_135 ) )
return;
V_135 -> V_137 = V_12 -> V_138 ;
V_135 -> V_139 = V_34 ;
}
static void F_112 ( struct V_76 * V_77 , int V_141 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
if ( V_77 == & V_12 -> V_125 &&
V_77 -> V_90 [ V_141 ] < F_113 ( V_12 ) )
F_114 ( V_12 , V_141 ) ;
if ( V_77 -> V_90 [ V_141 ] + 1 <= V_12 -> V_14 ) {
if ( F_115 ( & V_77 -> V_78 [ V_141 ] ) )
F_116 ( & V_77 -> V_78 [ V_141 ] ) ;
F_117 ( V_77 , V_141 ) ;
}
}
static void F_118 ( struct V_76 * V_77 , unsigned int V_65 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
int V_141 = F_119 ( V_65 ) ;
V_12 -> V_73 [ V_141 ] -- ;
V_77 -> V_90 [ V_141 ] -- ;
if ( V_65 & V_132 )
V_12 -> V_72 -- ;
F_112 ( V_77 , V_141 ) ;
if ( F_24 ( V_77 -> V_93 [ V_141 ^ 1 ] ) )
F_112 ( V_77 , V_141 ^ 1 ) ;
}
static bool F_120 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_142 & ( V_143 | V_144 ) )
return false ;
return true ;
}
static struct V_136 * F_121 ( struct V_35 * V_35 )
{
#ifdef F_88
if ( V_35 && V_35 -> V_145 )
return V_35 -> V_145 ;
#endif
return V_146 -> V_136 ;
}
static struct V_1 * F_122 ( struct V_76 * V_77 , int V_147 ,
struct V_35 * V_35 , T_2 V_88 )
{
struct V_11 * V_12 = V_77 -> V_12 ;
struct V_1 * V_2 ;
struct V_148 * V_149 = V_12 -> V_70 -> type ;
struct V_136 * V_135 = F_121 ( V_35 ) ;
struct V_150 * V_134 = NULL ;
const bool V_151 = F_119 ( V_147 ) != 0 ;
int V_152 ;
if ( F_24 ( F_103 ( V_12 ) ) )
return NULL ;
V_152 = F_123 ( V_12 , V_147 ) ;
if ( V_152 == V_153 )
goto V_154;
if ( V_77 -> V_90 [ V_151 ] + 1 >= F_124 ( V_12 ) ) {
if ( V_77 -> V_90 [ V_151 ] + 1 >= V_12 -> V_14 ) {
if ( ! F_125 ( V_77 , V_151 ) ) {
F_111 ( V_12 , V_135 ) ;
F_126 ( V_77 , V_151 ) ;
} else {
if ( V_152 != V_155
&& ! F_109 ( V_12 , V_135 ) ) {
return NULL ;
}
}
}
if ( V_77 == & V_12 -> V_125 )
F_127 ( V_12 , V_151 ) ;
}
if ( V_77 -> V_90 [ V_151 ] >= ( 3 * V_12 -> V_14 / 2 ) )
return NULL ;
V_12 -> V_73 [ V_151 ] ++ ;
V_77 -> V_90 [ V_151 ] ++ ;
V_77 -> V_93 [ V_151 ] = 0 ;
if ( F_120 ( V_35 ) && ! F_128 ( V_12 ) ) {
V_147 |= V_132 ;
V_12 -> V_72 ++ ;
if ( V_149 -> V_156 && V_135 )
V_134 = F_129 ( V_135 , V_12 ) ;
}
if ( F_130 ( V_12 ) )
V_147 |= V_157 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_131 ( V_77 -> V_89 , V_88 ) ;
if ( ! V_2 )
goto V_158;
F_16 ( V_12 , V_2 ) ;
F_132 ( V_2 , V_77 ) ;
V_2 -> V_43 = V_147 | V_159 ;
if ( V_147 & V_132 ) {
if ( F_24 ( V_149 -> V_156 && ! V_134 ) ) {
if ( V_135 )
V_134 = F_133 ( V_135 , V_12 , V_88 ) ;
if ( ! V_134 )
goto V_160;
}
V_2 -> V_133 . V_134 = V_134 ;
if ( F_24 ( F_134 ( V_12 , V_2 , V_35 , V_88 ) ) )
goto V_160;
if ( V_134 )
F_135 ( V_134 -> V_135 ) ;
}
V_161:
if ( F_109 ( V_12 , V_135 ) )
V_135 -> V_137 -- ;
F_136 ( V_12 , V_35 , V_147 & 1 ) ;
return V_2 ;
V_160:
F_137 ( V_162 L_10 ,
F_138 ( V_12 -> V_17 . V_163 ) ) ;
V_2 -> V_43 &= ~ V_132 ;
V_2 -> V_133 . V_134 = NULL ;
F_36 ( V_12 -> V_59 ) ;
V_12 -> V_72 -- ;
F_38 ( V_12 -> V_59 ) ;
goto V_161;
V_158:
F_36 ( V_12 -> V_59 ) ;
F_118 ( V_77 , V_147 ) ;
V_154:
if ( F_24 ( V_77 -> V_90 [ V_151 ] == 0 ) )
V_77 -> V_93 [ V_151 ] = 1 ;
return NULL ;
}
static struct V_1 * F_139 ( struct V_11 * V_12 , int V_147 ,
struct V_35 * V_35 , T_2 V_88 )
{
const bool V_151 = F_119 ( V_147 ) != 0 ;
F_140 ( V_78 ) ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
V_77 = F_141 ( V_12 , V_35 ) ;
V_164:
V_2 = F_122 ( V_77 , V_147 , V_35 , V_88 ) ;
if ( V_2 )
return V_2 ;
if ( ! ( V_88 & V_165 ) || F_24 ( F_103 ( V_12 ) ) ) {
F_142 ( V_77 ) ;
return NULL ;
}
F_143 ( & V_77 -> V_78 [ V_151 ] , & V_78 ,
V_166 ) ;
F_144 ( V_12 , V_35 , V_147 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_145 () ;
F_111 ( V_12 , V_146 -> V_136 ) ;
F_36 ( V_12 -> V_59 ) ;
F_146 ( & V_77 -> V_78 [ V_151 ] , & V_78 ) ;
goto V_164;
}
struct V_1 * F_147 ( struct V_11 * V_12 , int V_6 , T_2 V_88 )
{
struct V_1 * V_2 ;
F_148 ( V_6 != V_167 && V_6 != V_168 ) ;
F_149 ( V_88 , V_12 -> V_98 ) ;
F_36 ( V_12 -> V_59 ) ;
V_2 = F_139 ( V_12 , V_6 , NULL , V_88 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_150 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_88 )
{
struct V_1 * V_2 = F_147 ( V_12 , F_151 ( V_35 ) , V_88 ) ;
if ( F_24 ( ! V_2 ) )
return F_152 ( - V_99 ) ;
F_153 (bio) {
struct V_35 * V_169 = V_35 ;
int V_20 ;
F_154 ( V_12 , & V_169 ) ;
V_20 = F_155 ( V_12 , V_2 , V_169 ) ;
if ( F_24 ( V_20 ) ) {
F_156 ( V_2 ) ;
return F_152 ( V_20 ) ;
}
}
return V_2 ;
}
void F_157 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_158 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_12 , V_2 ) ;
if ( F_161 ( V_2 ) )
F_162 ( V_12 , V_2 ) ;
F_148 ( F_163 ( V_2 ) ) ;
F_164 ( V_12 , V_2 ) ;
}
static void F_165 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_170 )
{
F_1 ( V_2 , 1 ) ;
F_166 ( V_12 , V_2 , V_170 ) ;
}
static void F_167 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_171 )
{
if ( V_171 == V_5 -> V_172 )
return;
if ( F_168 ( V_5 ) ) {
F_169 ( V_7 , V_5 , V_173 ,
F_168 ( V_5 ) * ( V_171 - V_5 -> V_172 ) ) ;
F_169 ( V_7 , V_5 , V_174 , ( V_171 - V_5 -> V_172 ) ) ;
}
V_5 -> V_172 = V_171 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_171 = V_34 ;
if ( V_5 -> V_175 )
F_167 ( V_7 , & F_170 ( V_5 ) -> V_10 , V_171 ) ;
F_167 ( V_7 , V_5 , V_171 ) ;
}
void F_171 ( struct V_11 * V_12 , struct V_1 * V_176 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_176 -> V_32 ) )
return;
F_172 ( V_12 , V_176 ) ;
F_43 ( V_176 -> V_35 != NULL ) ;
if ( V_176 -> V_43 & V_159 ) {
unsigned int V_65 = V_176 -> V_43 ;
struct V_76 * V_77 = F_173 ( V_176 ) ;
F_148 ( ! F_64 ( & V_176 -> V_21 ) ) ;
F_148 ( ! F_174 ( & V_176 -> V_25 ) ) ;
F_105 ( V_77 , V_176 ) ;
F_118 ( V_77 , V_65 ) ;
F_142 ( V_77 ) ;
}
}
void F_156 ( struct V_1 * V_176 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_176 -> V_12 ;
F_57 ( V_12 -> V_59 , V_65 ) ;
F_171 ( V_12 , V_176 ) ;
F_58 ( V_12 -> V_59 , V_65 ) ;
}
void F_175 ( struct V_1 * V_2 , struct V_177 * V_177 ,
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
V_2 -> V_54 = F_176 ( V_35 ) ;
}
static bool F_177 ( struct V_11 * V_12 , struct V_1 * V_176 ,
struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_142 & V_189 ;
if ( ! F_178 ( V_12 , V_176 , V_35 ) )
return false ;
F_179 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_180 ( V_176 ) ;
V_176 -> V_53 -> V_190 = V_35 ;
V_176 -> V_53 = V_35 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_181 ( V_176 -> V_191 , F_182 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_183 ( struct V_11 * V_12 ,
struct V_1 * V_176 , struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_142 & V_189 ;
if ( ! F_184 ( V_12 , V_176 , V_35 ) )
return false ;
F_185 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_180 ( V_176 ) ;
V_35 -> V_190 = V_176 -> V_35 ;
V_176 -> V_35 = V_35 ;
V_176 -> V_54 = F_176 ( V_35 ) ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_181 ( V_176 -> V_191 , F_182 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_186 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_192 )
{
struct V_193 * V_194 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_194 = V_146 -> V_194 ;
if ( ! V_194 )
goto V_161;
* V_192 = 0 ;
F_187 (rq, &plug->list, queuelist) {
int V_195 ;
if ( V_2 -> V_12 == V_12 )
( * V_192 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_188 ( V_2 , V_35 ) )
continue;
V_195 = F_189 ( V_2 , V_35 ) ;
if ( V_195 == V_196 ) {
V_20 = F_177 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_195 == V_197 ) {
V_20 = F_183 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_161:
return V_20 ;
}
void F_190 ( struct V_1 * V_176 , struct V_35 * V_35 )
{
V_176 -> V_52 = V_198 ;
V_176 -> V_43 |= V_35 -> V_142 & V_199 ;
if ( V_35 -> V_142 & V_200 )
V_176 -> V_43 |= V_189 ;
V_176 -> V_201 = 0 ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_191 = F_182 ( V_35 ) ;
F_191 ( V_176 -> V_12 , V_176 , V_35 ) ;
}
void V_129 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_141 = ! ! ( V_35 -> V_142 & V_202 ) ;
struct V_193 * V_194 ;
int V_195 , V_147 , V_170 = V_203 ;
struct V_1 * V_176 ;
unsigned int V_192 = 0 ;
F_154 ( V_12 , & V_35 ) ;
if ( V_35 -> V_142 & ( V_143 | V_144 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_170 = V_204 ;
goto V_205;
}
if ( F_186 ( V_12 , V_35 , & V_192 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_195 = F_192 ( V_12 , & V_176 , V_35 ) ;
if ( V_195 == V_196 ) {
if ( F_177 ( V_12 , V_176 , V_35 ) ) {
F_193 ( V_12 , V_176 , V_35 ) ;
if ( ! F_194 ( V_12 , V_176 ) )
F_195 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
} else if ( V_195 == V_197 ) {
if ( F_183 ( V_12 , V_176 , V_35 ) ) {
F_193 ( V_12 , V_176 , V_35 ) ;
if ( ! F_196 ( V_12 , V_176 ) )
F_195 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
}
V_205:
V_147 = F_151 ( V_35 ) ;
if ( V_141 )
V_147 |= V_202 ;
V_176 = F_139 ( V_12 , V_147 , V_35 , V_207 ) ;
if ( F_24 ( ! V_176 ) ) {
F_29 ( V_35 , - V_208 ) ;
goto V_206;
}
F_190 ( V_176 , V_35 ) ;
if ( F_23 ( V_209 , & V_12 -> V_121 ) )
V_176 -> V_7 = F_197 () ;
V_194 = V_146 -> V_194 ;
if ( V_194 ) {
if ( F_64 ( & V_194 -> V_210 ) )
F_198 ( V_12 ) ;
else {
if ( ! V_194 -> V_211 ) {
struct V_1 * V_212 ;
V_212 = F_199 ( V_194 -> V_210 . V_213 ) ;
if ( V_212 -> V_12 != V_12 )
V_194 -> V_211 = 1 ;
}
if ( V_192 >= V_214 ) {
F_200 ( V_194 , false ) ;
F_198 ( V_12 ) ;
}
}
F_201 ( & V_176 -> V_21 , & V_194 -> V_210 ) ;
F_1 ( V_176 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_165 ( V_12 , V_176 , V_170 ) ;
F_37 ( V_12 ) ;
V_206:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_202 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_215 ;
if ( F_203 ( V_35 ) && V_19 != V_19 -> V_216 ) {
struct V_4 * V_217 = V_19 -> V_218 ;
V_35 -> V_46 += V_217 -> V_219 ;
V_35 -> V_215 = V_19 -> V_216 ;
F_204 ( F_15 ( V_35 -> V_215 ) , V_35 ,
V_19 -> V_220 ,
V_35 -> V_46 - V_217 -> V_219 ) ;
}
}
static void F_205 ( struct V_35 * V_35 )
{
char V_221 [ V_222 ] ;
F_25 ( V_50 L_11 ) ;
F_25 ( V_50 L_12 ,
F_206 ( V_35 -> V_215 , V_221 ) ,
V_35 -> V_142 ,
( unsigned long long ) V_35 -> V_46 + F_203 ( V_35 ) ,
( long long ) ( F_207 ( V_35 -> V_215 -> V_223 ) >> 9 ) ) ;
F_26 ( V_224 , & V_35 -> V_38 ) ;
}
static int T_4 F_208 ( char * V_225 )
{
return F_209 ( & V_226 , V_225 ) ;
}
static bool F_210 ( struct V_4 * V_5 , unsigned int V_227 )
{
return V_5 -> V_228 && F_211 ( & V_226 , V_227 ) ;
}
static int T_4 F_212 ( void )
{
struct V_229 * V_230 = F_213 ( L_13 ,
NULL , & V_226 ) ;
return F_214 ( V_230 ) ? F_215 ( V_230 ) : 0 ;
}
static inline bool F_210 ( struct V_4 * V_5 ,
unsigned int V_227 )
{
return false ;
}
static inline int F_216 ( struct V_35 * V_35 , unsigned int V_231 )
{
V_24 V_232 ;
if ( ! V_231 )
return 0 ;
V_232 = F_207 ( V_35 -> V_215 -> V_223 ) >> 9 ;
if ( V_232 ) {
V_24 V_233 = V_35 -> V_46 ;
if ( V_232 < V_231 || V_232 - V_231 < V_233 ) {
F_205 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_217 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_231 = F_203 ( V_35 ) ;
int V_101 = - V_39 ;
char V_221 [ V_222 ] ;
struct V_4 * V_5 ;
F_218 () ;
if ( F_216 ( V_35 , V_231 ) )
goto V_234;
V_12 = F_15 ( V_35 -> V_215 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_14
L_15 ,
F_206 ( V_35 -> V_215 , V_221 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_234;
}
if ( F_54 ( F_219 ( V_35 ) &&
V_231 > F_220 ( V_12 ) ) ) {
F_25 ( V_41 L_16 ,
F_206 ( V_35 -> V_215 , V_221 ) ,
F_203 ( V_35 ) ,
F_220 ( V_12 ) ) ;
goto V_234;
}
V_5 = V_35 -> V_215 -> V_218 ;
if ( F_210 ( V_5 , V_35 -> V_40 ) ||
F_210 ( & F_170 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_234;
F_202 ( V_35 ) ;
if ( F_221 ( V_35 ) && F_222 ( V_35 ) )
goto V_234;
if ( F_216 ( V_35 , V_231 ) )
goto V_234;
if ( ( V_35 -> V_142 & ( V_143 | V_144 ) ) && ! V_12 -> V_235 ) {
V_35 -> V_142 &= ~ ( V_143 | V_144 ) ;
if ( ! V_231 ) {
V_101 = 0 ;
goto V_234;
}
}
if ( ( V_35 -> V_142 & V_236 ) &&
( ! F_223 ( V_12 ) ||
( ( V_35 -> V_142 & V_237 ) && ! F_224 ( V_12 ) ) ) ) {
V_101 = - V_238 ;
goto V_234;
}
if ( V_35 -> V_142 & V_239 && ! F_225 ( V_35 -> V_215 ) ) {
V_101 = - V_238 ;
goto V_234;
}
F_149 ( V_240 , V_12 -> V_98 ) ;
if ( F_226 ( V_12 , V_35 ) )
return false ;
F_227 ( V_12 , V_35 ) ;
return true ;
V_234:
F_29 ( V_35 , V_101 ) ;
return false ;
}
void F_228 ( struct V_35 * V_35 )
{
struct V_241 V_242 ;
if ( ! F_217 ( V_35 ) )
return;
if ( V_146 -> V_241 ) {
F_229 ( V_146 -> V_241 , V_35 ) ;
return;
}
F_148 ( V_35 -> V_190 ) ;
F_230 ( & V_242 ) ;
V_146 -> V_241 = & V_242 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_215 ) ;
V_12 -> V_243 ( V_12 , V_35 ) ;
V_35 = F_231 ( V_146 -> V_241 ) ;
} while ( V_35 );
V_146 -> V_241 = NULL ;
}
void F_232 ( int V_6 , struct V_35 * V_35 )
{
V_35 -> V_142 |= V_6 ;
if ( F_233 ( V_35 ) ) {
unsigned int V_90 ;
if ( F_24 ( V_6 & V_239 ) )
V_90 = F_234 ( V_35 -> V_215 ) >> 9 ;
else
V_90 = F_203 ( V_35 ) ;
if ( V_6 & V_168 ) {
F_235 ( V_244 , V_90 ) ;
} else {
F_236 ( V_35 -> V_40 ) ;
F_235 ( V_245 , V_90 ) ;
}
if ( F_24 ( V_246 ) ) {
char V_221 [ V_222 ] ;
F_25 ( V_247 L_17 ,
V_146 -> V_248 , F_237 ( V_146 ) ,
( V_6 & V_168 ) ? L_18 : L_19 ,
( unsigned long long ) V_35 -> V_46 ,
F_206 ( V_35 -> V_215 , V_221 ) ,
V_90 ) ;
}
}
F_228 ( V_35 ) ;
}
int F_238 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( ! F_239 ( V_2 ) )
return 0 ;
if ( F_31 ( V_2 ) > F_240 ( V_12 , V_2 -> V_43 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
F_241 ( V_2 ) ;
if ( V_2 -> V_187 > F_242 ( V_12 ) ) {
F_25 ( V_41 L_21 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_243 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_170 = V_249 ;
if ( F_238 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_210 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_57 ( V_12 -> V_59 , V_65 ) ;
if ( F_24 ( F_103 ( V_12 ) ) ) {
F_58 ( V_12 -> V_59 , V_65 ) ;
return - V_208 ;
}
F_148 ( F_163 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_143 | V_144 ) )
V_170 = V_204 ;
F_165 ( V_12 , V_2 , V_170 ) ;
if ( V_170 == V_204 )
F_37 ( V_12 ) ;
F_58 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_244 ( const struct V_1 * V_2 )
{
unsigned int V_188 = V_2 -> V_43 & V_189 ;
unsigned int V_227 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_250 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_190 ) {
if ( ( V_35 -> V_142 & V_188 ) != V_188 )
break;
V_227 += V_35 -> V_40 ;
}
F_148 ( F_33 ( V_2 ) && ! V_227 ) ;
return V_227 ;
}
static void F_245 ( struct V_1 * V_176 , unsigned int V_227 )
{
if ( F_3 ( V_176 ) ) {
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_246 ( V_7 , V_5 , V_251 [ V_6 ] , V_227 >> 9 ) ;
F_12 () ;
}
}
static void F_247 ( struct V_1 * V_176 )
{
if ( F_3 ( V_176 ) && ! ( V_176 -> V_43 & V_47 ) ) {
unsigned long V_252 = V_34 - V_176 -> V_33 ;
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_5 ( V_7 , V_5 , V_253 [ V_6 ] ) ;
F_246 ( V_7 , V_5 , V_254 [ V_6 ] , V_252 ) ;
F_10 ( V_7 , V_5 ) ;
F_248 ( V_5 , V_6 ) ;
F_249 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_250 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_251 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_255 ) ) {
if ( V_2 -> V_43 & V_256 )
F_252 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_255 ;
F_253 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_257 || V_12 -> V_257 == V_2 ) {
V_12 -> V_258 = F_254 ( V_2 ) ;
V_12 -> V_257 = NULL ;
}
if ( V_2 -> V_43 & V_259 )
break;
if ( V_12 -> V_260 && F_33 ( V_2 ) ) {
V_2 -> V_187 ++ ;
}
if ( ! V_12 -> V_126 )
break;
V_20 = V_12 -> V_126 ( V_12 , V_2 ) ;
if ( V_20 == V_261 ) {
break;
} else if ( V_20 == V_262 ) {
if ( V_12 -> V_260 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_259 ) ) {
-- V_2 -> V_187 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_263 ) {
V_2 -> V_43 |= V_44 ;
F_255 ( V_2 ) ;
F_256 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_22 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_257 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_148 ( F_64 ( & V_2 -> V_21 ) ) ;
F_148 ( F_258 ( V_2 ) ) ;
F_259 ( & V_2 -> V_21 ) ;
if ( F_260 ( V_2 ) ) {
V_12 -> V_74 [ F_261 ( V_2 ) ] ++ ;
F_262 ( V_2 ) ;
}
}
void F_255 ( struct V_1 * V_176 )
{
F_257 ( V_176 ) ;
V_176 -> V_186 = F_33 ( V_176 ) ;
if ( F_24 ( F_263 ( V_176 ) ) )
V_176 -> V_264 -> V_186 = F_33 ( V_176 -> V_264 ) ;
F_264 ( V_176 ) ;
}
struct V_1 * F_265 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_250 ( V_12 ) ;
if ( V_2 )
F_255 ( V_2 ) ;
return V_2 ;
}
bool F_266 ( struct V_1 * V_176 , int error , unsigned int V_265 )
{
int V_266 , V_267 , V_268 = 0 ;
struct V_35 * V_35 ;
if ( ! V_176 -> V_35 )
return false ;
F_267 ( V_176 -> V_12 , V_176 ) ;
if ( V_176 -> V_52 == V_198 )
V_176 -> V_201 = 0 ;
if ( error && V_176 -> V_52 == V_198 &&
! ( V_176 -> V_43 & V_44 ) ) {
char * V_269 ;
switch ( error ) {
case - V_270 :
V_269 = L_23 ;
break;
case - V_271 :
V_269 = L_24 ;
break;
case - V_272 :
V_269 = L_25 ;
break;
case - V_39 :
default:
V_269 = L_26 ;
break;
}
F_137 ( V_41 L_27 ,
V_269 , V_176 -> V_9 ?
V_176 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_176 ) ) ;
}
F_245 ( V_176 , V_265 ) ;
V_266 = V_267 = 0 ;
while ( ( V_35 = V_176 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_265 >= V_35 -> V_40 ) {
V_176 -> V_35 = V_35 -> V_190 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_176 , V_35 , V_36 , error ) ;
V_268 = 0 ;
V_267 = 0 ;
} else {
int V_273 = V_35 -> V_274 + V_268 ;
if ( F_24 ( V_273 >= V_35 -> V_183 ) ) {
F_30 ( V_176 , L_28 ) ;
F_25 ( V_41 L_29 ,
V_42 , V_273 , V_35 -> V_183 ) ;
break;
}
V_36 = F_268 ( V_35 , V_273 ) -> V_182 ;
F_269 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_265 ) ) {
V_267 += V_265 ;
V_266 += V_265 ;
break;
}
V_268 ++ ;
V_267 += V_36 ;
}
V_266 += V_36 ;
V_265 -= V_36 ;
V_35 = V_176 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_265 <= 0 ) )
break;
}
}
if ( ! V_176 -> V_35 ) {
V_176 -> V_185 = 0 ;
return false ;
}
if ( V_267 ) {
F_21 ( V_176 , V_35 , V_267 , error ) ;
V_35 -> V_274 += V_268 ;
F_270 ( V_35 ) -> V_181 += V_265 ;
F_270 ( V_35 ) -> V_182 -= V_265 ;
}
V_176 -> V_185 -= V_266 ;
V_176 -> V_54 = F_176 ( V_176 -> V_35 ) ;
if ( V_176 -> V_52 == V_198 )
V_176 -> V_23 += V_266 >> 9 ;
if ( V_176 -> V_43 & V_250 ) {
V_176 -> V_43 &= ~ V_189 ;
V_176 -> V_43 |= V_176 -> V_35 -> V_142 & V_189 ;
}
if ( F_33 ( V_176 ) < F_271 ( V_176 ) ) {
F_30 ( V_176 , L_30 ) ;
V_176 -> V_185 = F_271 ( V_176 ) ;
}
F_241 ( V_176 ) ;
return true ;
}
static bool F_272 ( struct V_1 * V_2 , int error ,
unsigned int V_265 ,
unsigned int V_275 )
{
if ( F_266 ( V_2 , error , V_265 ) )
return true ;
if ( F_24 ( F_263 ( V_2 ) ) &&
F_266 ( V_2 -> V_264 , error , V_275 ) )
return true ;
if ( F_273 ( V_2 -> V_12 ) )
F_274 ( V_2 -> V_9 ) ;
return false ;
}
void F_275 ( struct V_1 * V_176 )
{
struct V_11 * V_12 = V_176 -> V_12 ;
V_176 -> V_43 &= ~ V_259 ;
if ( V_12 -> V_127 )
V_12 -> V_127 ( V_12 , V_176 ) ;
}
static void F_276 ( struct V_1 * V_176 , int error )
{
if ( F_161 ( V_176 ) )
F_162 ( V_176 -> V_12 , V_176 ) ;
F_148 ( F_163 ( V_176 ) ) ;
if ( F_24 ( V_276 ) && V_176 -> V_52 == V_198 )
F_277 ( & V_176 -> V_12 -> V_17 ) ;
F_158 ( V_176 ) ;
if ( V_176 -> V_43 & V_259 )
F_275 ( V_176 ) ;
F_247 ( V_176 ) ;
if ( V_176 -> V_234 )
V_176 -> V_234 ( V_176 , error ) ;
else {
if ( F_263 ( V_176 ) )
F_171 ( V_176 -> V_264 -> V_12 , V_176 -> V_264 ) ;
F_171 ( V_176 -> V_12 , V_176 ) ;
}
}
static bool F_278 ( struct V_1 * V_2 , int error ,
unsigned int V_265 , unsigned int V_275 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_272 ( V_2 , error , V_265 , V_275 ) )
return true ;
F_57 ( V_12 -> V_59 , V_65 ) ;
F_276 ( V_2 , error ) ;
F_58 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_279 ( struct V_1 * V_2 , int error ,
unsigned int V_265 , unsigned int V_275 )
{
if ( F_272 ( V_2 , error , V_265 , V_275 ) )
return true ;
F_276 ( V_2 , error ) ;
return false ;
}
bool F_280 ( struct V_1 * V_2 , int error , unsigned int V_265 )
{
return F_278 ( V_2 , error , V_265 , 0 ) ;
}
void F_281 ( struct V_1 * V_2 , int error )
{
bool V_277 ;
unsigned int V_275 = 0 ;
if ( F_24 ( F_263 ( V_2 ) ) )
V_275 = F_33 ( V_2 -> V_264 ) ;
V_277 = F_278 ( V_2 , error , F_33 ( V_2 ) , V_275 ) ;
F_148 ( V_277 ) ;
}
bool F_282 ( struct V_1 * V_2 , int error )
{
return F_280 ( V_2 , error , F_271 ( V_2 ) ) ;
}
bool F_283 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_280 ( V_2 , error , F_244 ( V_2 ) ) ;
}
bool F_284 ( struct V_1 * V_2 , int error , unsigned int V_265 )
{
return F_279 ( V_2 , error , V_265 , 0 ) ;
}
void F_256 ( struct V_1 * V_2 , int error )
{
bool V_277 ;
unsigned int V_275 = 0 ;
if ( F_24 ( F_263 ( V_2 ) ) )
V_275 = F_33 ( V_2 -> V_264 ) ;
V_277 = F_279 ( V_2 , error , F_33 ( V_2 ) , V_275 ) ;
F_148 ( V_277 ) ;
}
bool F_285 ( struct V_1 * V_2 , int error )
{
return F_284 ( V_2 , error , F_271 ( V_2 ) ) ;
}
bool F_286 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_284 ( V_2 , error , F_244 ( V_2 ) ) ;
}
void F_191 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_142 & V_278 ;
if ( F_233 ( V_35 ) ) {
V_2 -> V_187 = F_287 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_176 ( V_35 ) ;
}
V_2 -> V_185 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_215 )
V_2 -> V_9 = V_35 -> V_215 -> V_279 ;
}
void F_288 ( struct V_1 * V_2 )
{
struct V_280 V_281 ;
struct V_282 * V_283 ;
F_289 (bvec, rq, iter)
F_290 ( V_283 -> V_180 ) ;
}
int F_291 ( struct V_11 * V_12 )
{
if ( V_12 -> V_284 )
return V_12 -> V_284 ( V_12 ) ;
return 0 ;
}
void F_292 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_190 ;
F_293 ( V_35 ) ;
}
}
static void F_294 ( struct V_1 * V_285 , struct V_1 * V_286 )
{
V_285 -> V_7 = V_286 -> V_7 ;
V_285 -> V_43 = ( V_286 -> V_43 & V_287 ) | V_288 ;
V_285 -> V_52 = V_286 -> V_52 ;
V_285 -> V_23 = F_7 ( V_286 ) ;
V_285 -> V_185 = F_33 ( V_286 ) ;
V_285 -> V_187 = V_286 -> V_187 ;
V_285 -> V_191 = V_286 -> V_191 ;
V_285 -> V_289 = V_286 -> V_289 ;
}
int F_295 ( struct V_1 * V_2 , struct V_1 * V_290 ,
struct V_291 * V_292 , T_2 V_88 ,
int (* F_296)( struct V_35 * , struct V_35 * , void * ) ,
void * V_293 )
{
struct V_35 * V_35 , * V_294 ;
if ( ! V_292 )
V_292 = V_295 ;
F_16 ( NULL , V_2 ) ;
F_297 (bio_src, rq_src) {
V_35 = F_298 ( V_294 , V_88 , V_292 ) ;
if ( ! V_35 )
goto V_296;
if ( F_296 && F_296 ( V_35 , V_294 , V_293 ) )
goto V_296;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_190 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_294 ( V_2 , V_290 ) ;
return 0 ;
V_296:
if ( V_35 )
F_293 ( V_35 ) ;
F_292 ( V_2 ) ;
return - V_99 ;
}
int F_299 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_300 ( V_61 , V_57 ) ;
}
int F_301 ( struct V_11 * V_12 ,
struct V_297 * V_298 , unsigned long V_299 )
{
return F_40 ( V_61 , V_298 , V_299 ) ;
}
void F_302 ( struct V_193 * V_194 )
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
static int F_303 ( void * V_305 , struct V_306 * V_307 , struct V_306 * V_221 )
{
struct V_1 * V_308 = F_35 ( V_307 , struct V_1 , V_21 ) ;
struct V_1 * V_309 = F_35 ( V_221 , struct V_1 , V_21 ) ;
return ! ( V_308 -> V_12 < V_309 -> V_12 ||
( V_308 -> V_12 == V_309 -> V_12 && F_7 ( V_308 ) < F_7 ( V_309 ) ) ) ;
}
static void F_304 ( struct V_11 * V_12 , unsigned int V_310 ,
bool V_311 )
__releases( V_12 -> V_59 )
{
F_305 ( V_12 , V_310 , ! V_311 ) ;
if ( F_24 ( F_103 ( V_12 ) ) ) {
F_306 ( V_12 -> V_59 ) ;
return;
}
if ( V_311 ) {
F_306 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_306 ( V_12 -> V_59 ) ;
}
}
static void F_307 ( struct V_193 * V_194 , bool V_311 )
{
F_308 ( V_312 ) ;
while ( ! F_64 ( & V_194 -> V_304 ) ) {
F_309 ( & V_194 -> V_304 , & V_312 ) ;
while ( ! F_64 ( & V_312 ) ) {
struct V_313 * V_314 = F_310 ( & V_312 ,
struct V_313 ,
V_210 ) ;
F_311 ( & V_314 -> V_210 ) ;
V_314 -> V_315 ( V_314 , V_311 ) ;
}
}
}
struct V_313 * F_312 ( T_6 V_316 , void * V_293 ,
int V_317 )
{
struct V_193 * V_194 = V_146 -> V_194 ;
struct V_313 * V_314 ;
if ( ! V_194 )
return NULL ;
F_313 (cb, &plug->cb_list, list)
if ( V_314 -> V_315 == V_316 && V_314 -> V_293 == V_293 )
return V_314 ;
F_148 ( V_317 < sizeof( * V_314 ) ) ;
V_314 = F_314 ( V_317 , V_240 ) ;
if ( V_314 ) {
V_314 -> V_293 = V_293 ;
V_314 -> V_315 = V_316 ;
F_315 ( & V_314 -> V_210 , & V_194 -> V_304 ) ;
}
return V_314 ;
}
void F_200 ( struct V_193 * V_194 , bool V_311 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_308 ( V_210 ) ;
unsigned int V_310 ;
F_148 ( V_194 -> V_302 != V_303 ) ;
F_307 ( V_194 , V_311 ) ;
if ( F_64 ( & V_194 -> V_210 ) )
return;
F_309 ( & V_194 -> V_210 , & V_210 ) ;
if ( V_194 -> V_211 ) {
F_316 ( NULL , & V_210 , F_303 ) ;
V_194 -> V_211 = 0 ;
}
V_12 = NULL ;
V_310 = 0 ;
F_317 ( V_65 ) ;
while ( ! F_64 ( & V_210 ) ) {
V_2 = F_199 ( V_210 . V_318 ) ;
F_259 ( & V_2 -> V_21 ) ;
F_148 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_304 ( V_12 , V_310 , V_311 ) ;
V_12 = V_2 -> V_12 ;
V_310 = 0 ;
F_318 ( V_12 -> V_59 ) ;
}
if ( F_24 ( F_103 ( V_12 ) ) ) {
F_256 ( V_2 , - V_208 ) ;
continue;
}
if ( V_2 -> V_43 & ( V_143 | V_144 ) )
F_166 ( V_12 , V_2 , V_204 ) ;
else
F_166 ( V_12 , V_2 , V_319 ) ;
V_310 ++ ;
}
if ( V_12 )
F_304 ( V_12 , V_310 , V_311 ) ;
F_319 ( V_65 ) ;
}
void F_320 ( struct V_193 * V_194 )
{
F_200 ( V_194 , false ) ;
if ( V_194 == V_146 -> V_194 )
V_146 -> V_194 = NULL ;
}
int T_4 F_321 ( void )
{
F_322 ( V_320 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_323 ( L_31 ,
V_321 | V_322 , 0 ) ;
if ( ! V_61 )
F_324 ( L_32 ) ;
V_97 = F_325 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_323 , NULL ) ;
V_102 = F_325 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_323 , NULL ) ;
return 0 ;
}
