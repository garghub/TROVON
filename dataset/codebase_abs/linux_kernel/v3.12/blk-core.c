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
if ( F_24 ( V_2 -> V_40 & V_41 ) )
F_25 ( V_42 , & V_35 -> V_38 ) ;
F_26 ( V_35 , V_36 ) ;
if ( V_35 -> V_43 == 0 && ! ( V_2 -> V_40 & V_44 ) )
F_27 ( V_35 , error ) ;
}
void F_28 ( struct V_1 * V_2 , char * V_45 )
{
int V_46 ;
F_29 ( V_47 L_1 , V_45 ,
V_2 -> V_9 ? V_2 -> V_9 -> V_48 : L_2 , V_2 -> V_49 ,
V_2 -> V_40 ) ;
F_29 ( V_47 L_3 ,
( unsigned long long ) F_7 ( V_2 ) ,
F_30 ( V_2 ) , F_31 ( V_2 ) ) ;
F_29 ( V_47 L_4 ,
V_2 -> V_35 , V_2 -> V_50 , V_2 -> V_51 , F_32 ( V_2 ) ) ;
if ( V_2 -> V_49 == V_52 ) {
F_29 ( V_47 L_5 ) ;
for ( V_46 = 0 ; V_46 < V_30 ; V_46 ++ )
F_29 ( L_6 , V_2 -> V_27 [ V_46 ] ) ;
F_29 ( L_7 ) ;
}
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_11 * V_12 ;
V_12 = F_34 ( V_54 , struct V_11 , V_55 . V_54 ) ;
F_35 ( V_12 -> V_56 ) ;
F_36 ( V_12 ) ;
F_37 ( V_12 -> V_56 ) ;
}
void F_38 ( struct V_11 * V_12 , unsigned long V_57 )
{
if ( F_39 ( ! F_40 ( V_12 ) ) )
F_41 ( V_58 , & V_12 -> V_55 ,
F_42 ( V_57 ) ) ;
}
void F_43 ( struct V_11 * V_12 )
{
F_44 ( ! F_45 () ) ;
F_46 ( V_59 , V_12 ) ;
F_36 ( V_12 ) ;
}
void F_47 ( struct V_11 * V_12 )
{
F_48 ( & V_12 -> V_55 ) ;
F_49 ( V_59 , V_12 ) ;
}
void F_50 ( struct V_11 * V_12 )
{
F_51 ( & V_12 -> V_60 ) ;
F_52 ( & V_12 -> V_55 ) ;
}
inline void F_53 ( struct V_11 * V_12 )
{
if ( F_24 ( F_40 ( V_12 ) ) )
return;
V_12 -> V_61 ++ ;
V_12 -> V_62 ( V_12 ) ;
V_12 -> V_61 -- ;
}
void F_36 ( struct V_11 * V_12 )
{
if ( F_24 ( F_54 ( V_12 ) ) )
return;
F_53 ( V_12 ) ;
}
void F_55 ( struct V_11 * V_12 )
{
if ( F_39 ( ! F_54 ( V_12 ) && ! F_40 ( V_12 ) ) )
F_56 ( V_58 , & V_12 -> V_55 , 0 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
unsigned long V_63 ;
F_58 ( V_12 -> V_56 , V_63 ) ;
F_36 ( V_12 ) ;
F_59 ( V_12 -> V_56 , V_63 ) ;
}
void F_60 ( struct V_11 * V_12 )
{
F_61 ( & V_12 -> V_64 ) ;
}
static void F_62 ( struct V_11 * V_12 , bool V_65 )
__releases( V_12 -> V_56 )
__acquires( V_12 -> V_56 )
{
int V_66 ;
F_63 ( V_12 -> V_56 ) ;
while ( true ) {
bool V_67 = false ;
if ( V_12 -> V_68 )
F_64 ( V_12 ) ;
F_65 ( V_12 ) ;
if ( ! F_66 ( & V_12 -> V_69 ) && V_12 -> V_62 )
F_36 ( V_12 ) ;
V_67 |= V_12 -> V_70 ;
V_67 |= V_12 -> V_61 ;
if ( V_65 ) {
V_67 |= ! F_66 ( & V_12 -> V_69 ) ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
V_67 |= V_12 -> V_71 [ V_66 ] ;
V_67 |= V_12 -> V_72 [ V_66 ] ;
V_67 |= ! F_66 ( & V_12 -> V_73 [ V_66 ] ) ;
}
}
if ( ! V_67 )
break;
F_37 ( V_12 -> V_56 ) ;
F_67 ( 10 ) ;
F_35 ( V_12 -> V_56 ) ;
}
if ( V_12 -> V_62 ) {
struct V_74 * V_75 ;
F_68 (rl, q)
for ( V_66 = 0 ; V_66 < F_69 ( V_75 -> V_76 ) ; V_66 ++ )
F_70 ( & V_75 -> V_76 [ V_66 ] ) ;
}
}
void F_71 ( struct V_11 * V_12 )
{
bool V_67 ;
F_35 ( V_12 -> V_56 ) ;
V_67 = ! V_12 -> V_77 ++ ;
F_49 ( V_78 , V_12 ) ;
F_37 ( V_12 -> V_56 ) ;
if ( V_67 ) {
F_35 ( V_12 -> V_56 ) ;
F_62 ( V_12 , false ) ;
F_37 ( V_12 -> V_56 ) ;
F_72 () ;
}
}
void F_73 ( struct V_11 * V_12 )
{
F_35 ( V_12 -> V_56 ) ;
if ( ! -- V_12 -> V_77 )
F_46 ( V_78 , V_12 ) ;
F_74 ( V_12 -> V_77 < 0 ) ;
F_37 ( V_12 -> V_56 ) ;
}
void F_75 ( struct V_11 * V_12 )
{
T_1 * V_79 = V_12 -> V_56 ;
F_76 ( & V_12 -> V_80 ) ;
F_77 ( V_81 , V_12 ) ;
F_35 ( V_79 ) ;
V_12 -> V_77 ++ ;
F_49 ( V_78 , V_12 ) ;
F_49 ( V_82 , V_12 ) ;
F_49 ( V_83 , V_12 ) ;
F_49 ( V_81 , V_12 ) ;
F_37 ( V_79 ) ;
F_78 ( & V_12 -> V_80 ) ;
F_35 ( V_79 ) ;
F_62 ( V_12 , true ) ;
F_49 ( V_84 , V_12 ) ;
F_37 ( V_79 ) ;
F_51 ( & V_12 -> V_17 . V_85 ) ;
F_50 ( V_12 ) ;
F_35 ( V_79 ) ;
if ( V_12 -> V_56 != & V_12 -> V_86 )
V_12 -> V_56 = & V_12 -> V_86 ;
F_37 ( V_79 ) ;
F_60 ( V_12 ) ;
}
int F_79 ( struct V_74 * V_75 , struct V_11 * V_12 ,
T_2 V_87 )
{
if ( F_24 ( V_75 -> V_88 ) )
return 0 ;
V_75 -> V_12 = V_12 ;
V_75 -> V_89 [ V_90 ] = V_75 -> V_89 [ V_91 ] = 0 ;
V_75 -> V_92 [ V_90 ] = V_75 -> V_92 [ V_91 ] = 0 ;
F_80 ( & V_75 -> V_76 [ V_90 ] ) ;
F_80 ( & V_75 -> V_76 [ V_91 ] ) ;
V_75 -> V_88 = F_81 ( V_93 , V_94 ,
V_95 , V_96 ,
V_87 , V_12 -> V_97 ) ;
if ( ! V_75 -> V_88 )
return - V_98 ;
return 0 ;
}
void F_82 ( struct V_74 * V_75 )
{
if ( V_75 -> V_88 )
F_83 ( V_75 -> V_88 ) ;
}
struct V_11 * F_84 ( T_2 V_87 )
{
return F_85 ( V_87 , V_99 ) ;
}
struct V_11 * F_85 ( T_2 V_87 , int V_100 )
{
struct V_11 * V_12 ;
int V_101 ;
V_12 = F_86 ( V_102 ,
V_87 | V_103 , V_100 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_104 = F_87 ( & V_105 , 0 , 0 , V_87 ) ;
if ( V_12 -> V_104 < 0 )
goto V_106;
V_12 -> V_17 . V_107 =
( V_108 * 1024 ) / V_109 ;
V_12 -> V_17 . V_110 = 0 ;
V_12 -> V_17 . V_111 = V_112 ;
V_12 -> V_17 . V_113 = L_8 ;
V_12 -> V_97 = V_100 ;
V_101 = F_88 ( & V_12 -> V_17 ) ;
if ( V_101 )
goto V_114;
F_89 ( & V_12 -> V_17 . V_85 ,
V_115 , ( unsigned long ) V_12 ) ;
F_89 ( & V_12 -> V_60 , V_116 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_69 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_117 ) ;
#ifdef F_90
F_17 ( & V_12 -> V_118 ) ;
#endif
F_17 ( & V_12 -> V_73 [ 0 ] ) ;
F_17 ( & V_12 -> V_73 [ 1 ] ) ;
F_17 ( & V_12 -> V_119 ) ;
F_91 ( & V_12 -> V_55 , F_33 ) ;
F_92 ( & V_12 -> V_64 , & V_120 ) ;
F_93 ( & V_12 -> V_80 ) ;
F_94 ( & V_12 -> V_86 ) ;
V_12 -> V_56 = & V_12 -> V_86 ;
V_12 -> V_77 = 1 ;
F_95 ( V_78 , & V_12 -> V_121 ) ;
if ( F_96 ( V_12 ) )
goto V_114;
return V_12 ;
V_114:
F_97 ( & V_105 , V_12 -> V_104 ) ;
V_106:
F_98 ( V_102 , V_12 ) ;
return NULL ;
}
struct V_11 * F_99 ( T_3 * V_122 , T_1 * V_79 )
{
return F_100 ( V_122 , V_79 , V_99 ) ;
}
struct V_11 *
F_100 ( T_3 * V_122 , T_1 * V_79 , int V_100 )
{
struct V_11 * V_123 , * V_12 ;
V_123 = F_85 ( V_124 , V_100 ) ;
if ( ! V_123 )
return NULL ;
V_12 = F_101 ( V_123 , V_122 , V_79 ) ;
if ( ! V_12 )
F_75 ( V_123 ) ;
return V_12 ;
}
struct V_11 *
F_101 ( struct V_11 * V_12 , T_3 * V_122 ,
T_1 * V_79 )
{
if ( ! V_12 )
return NULL ;
if ( F_79 ( & V_12 -> V_125 , V_12 , V_124 ) )
return NULL ;
V_12 -> V_62 = V_122 ;
V_12 -> V_126 = NULL ;
V_12 -> V_127 = NULL ;
V_12 -> V_121 |= V_128 ;
if ( V_79 )
V_12 -> V_56 = V_79 ;
F_102 ( V_12 , V_129 ) ;
V_12 -> V_130 = V_131 ;
if ( F_103 ( V_12 , NULL ) )
return NULL ;
return V_12 ;
}
bool F_104 ( struct V_11 * V_12 )
{
if ( F_39 ( ! F_105 ( V_12 ) ) ) {
F_106 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_107 ( struct V_74 * V_75 , struct V_1 * V_2 )
{
if ( V_2 -> V_40 & V_132 ) {
F_108 ( V_75 -> V_12 , V_2 ) ;
if ( V_2 -> V_133 . V_134 )
F_109 ( V_2 -> V_133 . V_134 -> V_135 ) ;
}
F_110 ( V_2 , V_75 -> V_88 ) ;
}
static inline int F_111 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 )
return 0 ;
return V_135 -> V_137 == V_12 -> V_138 ||
( V_135 -> V_137 > 0
&& F_112 ( V_34 , V_135 -> V_139 + V_140 ) ) ;
}
static void F_113 ( struct V_11 * V_12 , struct V_136 * V_135 )
{
if ( ! V_135 || F_111 ( V_12 , V_135 ) )
return;
V_135 -> V_137 = V_12 -> V_138 ;
V_135 -> V_139 = V_34 ;
}
static void F_114 ( struct V_74 * V_75 , int V_141 )
{
struct V_11 * V_12 = V_75 -> V_12 ;
if ( V_75 == & V_12 -> V_125 &&
V_75 -> V_89 [ V_141 ] < F_115 ( V_12 ) )
F_116 ( V_12 , V_141 ) ;
if ( V_75 -> V_89 [ V_141 ] + 1 <= V_12 -> V_14 ) {
if ( F_117 ( & V_75 -> V_76 [ V_141 ] ) )
F_118 ( & V_75 -> V_76 [ V_141 ] ) ;
F_119 ( V_75 , V_141 ) ;
}
}
static void F_120 ( struct V_74 * V_75 , unsigned int V_63 )
{
struct V_11 * V_12 = V_75 -> V_12 ;
int V_141 = F_121 ( V_63 ) ;
V_12 -> V_71 [ V_141 ] -- ;
V_75 -> V_89 [ V_141 ] -- ;
if ( V_63 & V_132 )
V_12 -> V_70 -- ;
F_114 ( V_75 , V_141 ) ;
if ( F_24 ( V_75 -> V_92 [ V_141 ^ 1 ] ) )
F_114 ( V_75 , V_141 ^ 1 ) ;
}
static bool F_122 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_142 & ( V_143 | V_144 ) )
return false ;
return true ;
}
static struct V_136 * F_123 ( struct V_35 * V_35 )
{
#ifdef F_90
if ( V_35 && V_35 -> V_145 )
return V_35 -> V_145 ;
#endif
return V_146 -> V_136 ;
}
static struct V_1 * F_124 ( struct V_74 * V_75 , int V_147 ,
struct V_35 * V_35 , T_2 V_87 )
{
struct V_11 * V_12 = V_75 -> V_12 ;
struct V_1 * V_2 ;
struct V_148 * V_149 = V_12 -> V_68 -> type ;
struct V_136 * V_135 = F_123 ( V_35 ) ;
struct V_150 * V_134 = NULL ;
const bool V_151 = F_121 ( V_147 ) != 0 ;
int V_152 ;
if ( F_24 ( F_105 ( V_12 ) ) )
return NULL ;
V_152 = F_125 ( V_12 , V_147 ) ;
if ( V_152 == V_153 )
goto V_154;
if ( V_75 -> V_89 [ V_151 ] + 1 >= F_126 ( V_12 ) ) {
if ( V_75 -> V_89 [ V_151 ] + 1 >= V_12 -> V_14 ) {
if ( ! F_127 ( V_75 , V_151 ) ) {
F_113 ( V_12 , V_135 ) ;
F_128 ( V_75 , V_151 ) ;
} else {
if ( V_152 != V_155
&& ! F_111 ( V_12 , V_135 ) ) {
return NULL ;
}
}
}
if ( V_75 == & V_12 -> V_125 )
F_129 ( V_12 , V_151 ) ;
}
if ( V_75 -> V_89 [ V_151 ] >= ( 3 * V_12 -> V_14 / 2 ) )
return NULL ;
V_12 -> V_71 [ V_151 ] ++ ;
V_75 -> V_89 [ V_151 ] ++ ;
V_75 -> V_92 [ V_151 ] = 0 ;
if ( F_122 ( V_35 ) && ! F_130 ( V_12 ) ) {
V_147 |= V_132 ;
V_12 -> V_70 ++ ;
if ( V_149 -> V_156 && V_135 )
V_134 = F_131 ( V_135 , V_12 ) ;
}
if ( F_132 ( V_12 ) )
V_147 |= V_157 ;
F_37 ( V_12 -> V_56 ) ;
V_2 = F_133 ( V_75 -> V_88 , V_87 ) ;
if ( ! V_2 )
goto V_158;
F_16 ( V_12 , V_2 ) ;
F_134 ( V_2 , V_75 ) ;
V_2 -> V_40 = V_147 | V_159 ;
if ( V_147 & V_132 ) {
if ( F_24 ( V_149 -> V_156 && ! V_134 ) ) {
if ( V_135 )
V_134 = F_135 ( V_135 , V_12 , V_87 ) ;
if ( ! V_134 )
goto V_160;
}
V_2 -> V_133 . V_134 = V_134 ;
if ( F_24 ( F_136 ( V_12 , V_2 , V_35 , V_87 ) ) )
goto V_160;
if ( V_134 )
F_137 ( V_134 -> V_135 ) ;
}
V_161:
if ( F_111 ( V_12 , V_135 ) )
V_135 -> V_137 -- ;
F_138 ( V_12 , V_35 , V_147 & 1 ) ;
return V_2 ;
V_160:
F_139 ( V_162 L_9 ,
F_140 ( V_12 -> V_17 . V_163 ) ) ;
V_2 -> V_40 &= ~ V_132 ;
V_2 -> V_133 . V_134 = NULL ;
F_35 ( V_12 -> V_56 ) ;
V_12 -> V_70 -- ;
F_37 ( V_12 -> V_56 ) ;
goto V_161;
V_158:
F_35 ( V_12 -> V_56 ) ;
F_120 ( V_75 , V_147 ) ;
V_154:
if ( F_24 ( V_75 -> V_89 [ V_151 ] == 0 ) )
V_75 -> V_92 [ V_151 ] = 1 ;
return NULL ;
}
static struct V_1 * F_141 ( struct V_11 * V_12 , int V_147 ,
struct V_35 * V_35 , T_2 V_87 )
{
const bool V_151 = F_121 ( V_147 ) != 0 ;
F_142 ( V_76 ) ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
V_75 = F_143 ( V_12 , V_35 ) ;
V_164:
V_2 = F_124 ( V_75 , V_147 , V_35 , V_87 ) ;
if ( V_2 )
return V_2 ;
if ( ! ( V_87 & V_165 ) || F_24 ( F_105 ( V_12 ) ) ) {
F_144 ( V_75 ) ;
return NULL ;
}
F_145 ( & V_75 -> V_76 [ V_151 ] , & V_76 ,
V_166 ) ;
F_146 ( V_12 , V_35 , V_147 & 1 ) ;
F_37 ( V_12 -> V_56 ) ;
F_147 () ;
F_113 ( V_12 , V_146 -> V_136 ) ;
F_35 ( V_12 -> V_56 ) ;
F_148 ( & V_75 -> V_76 [ V_151 ] , & V_76 ) ;
goto V_164;
}
struct V_1 * F_149 ( struct V_11 * V_12 , int V_6 , T_2 V_87 )
{
struct V_1 * V_2 ;
F_150 ( V_6 != V_167 && V_6 != V_168 ) ;
F_151 ( V_87 , V_12 -> V_97 ) ;
F_35 ( V_12 -> V_56 ) ;
V_2 = F_141 ( V_12 , V_6 , NULL , V_87 ) ;
if ( ! V_2 )
F_37 ( V_12 -> V_56 ) ;
return V_2 ;
}
struct V_1 * F_152 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_87 )
{
struct V_1 * V_2 = F_149 ( V_12 , F_153 ( V_35 ) , V_87 ) ;
if ( F_24 ( ! V_2 ) )
return F_154 ( - V_98 ) ;
F_155 (bio) {
struct V_35 * V_169 = V_35 ;
int V_20 ;
F_156 ( V_12 , & V_169 ) ;
V_20 = F_157 ( V_12 , V_2 , V_169 ) ;
if ( F_24 ( V_20 ) ) {
F_158 ( V_2 ) ;
return F_154 ( V_20 ) ;
}
}
return V_2 ;
}
void F_159 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_162 ( V_12 , V_2 ) ;
if ( F_163 ( V_2 ) )
F_164 ( V_12 , V_2 ) ;
F_150 ( F_165 ( V_2 ) ) ;
F_166 ( V_12 , V_2 ) ;
}
static void F_167 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_170 )
{
F_1 ( V_2 , 1 ) ;
F_168 ( V_12 , V_2 , V_170 ) ;
}
static void F_169 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_171 )
{
if ( V_171 == V_5 -> V_172 )
return;
if ( F_170 ( V_5 ) ) {
F_171 ( V_7 , V_5 , V_173 ,
F_170 ( V_5 ) * ( V_171 - V_5 -> V_172 ) ) ;
F_171 ( V_7 , V_5 , V_174 , ( V_171 - V_5 -> V_172 ) ) ;
}
V_5 -> V_172 = V_171 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_171 = V_34 ;
if ( V_5 -> V_175 )
F_169 ( V_7 , & F_172 ( V_5 ) -> V_10 , V_171 ) ;
F_169 ( V_7 , V_5 , V_171 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 -> V_163 && ! ( V_2 -> V_40 & V_176 ) && ! -- V_2 -> V_12 -> V_177 )
F_174 ( V_2 -> V_12 -> V_163 ) ;
}
static inline void F_173 ( struct V_1 * V_2 ) {}
void F_175 ( struct V_11 * V_12 , struct V_1 * V_178 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_178 -> V_32 ) )
return;
F_173 ( V_178 ) ;
F_176 ( V_12 , V_178 ) ;
F_44 ( V_178 -> V_35 != NULL ) ;
if ( V_178 -> V_40 & V_159 ) {
unsigned int V_63 = V_178 -> V_40 ;
struct V_74 * V_75 = F_177 ( V_178 ) ;
F_150 ( ! F_66 ( & V_178 -> V_21 ) ) ;
F_150 ( ! F_178 ( & V_178 -> V_25 ) ) ;
F_107 ( V_75 , V_178 ) ;
F_120 ( V_75 , V_63 ) ;
F_144 ( V_75 ) ;
}
}
void F_158 ( struct V_1 * V_178 )
{
unsigned long V_63 ;
struct V_11 * V_12 = V_178 -> V_12 ;
F_58 ( V_12 -> V_56 , V_63 ) ;
F_175 ( V_12 , V_178 ) ;
F_59 ( V_12 -> V_56 , V_63 ) ;
}
void F_179 ( struct V_1 * V_2 , struct V_179 * V_179 ,
unsigned int V_180 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_181 -> V_182 = V_179 ;
V_35 -> V_181 -> V_183 = 0 ;
V_35 -> V_181 -> V_184 = V_180 ;
V_35 -> V_43 = V_180 ;
V_35 -> V_185 = 1 ;
V_35 -> V_186 = 1 ;
V_2 -> V_187 = V_2 -> V_188 = V_180 ;
V_2 -> V_189 = 1 ;
V_2 -> V_51 = F_180 ( V_35 ) ;
}
static bool F_181 ( struct V_11 * V_12 , struct V_1 * V_178 ,
struct V_35 * V_35 )
{
const int V_190 = V_35 -> V_142 & V_191 ;
if ( ! F_182 ( V_12 , V_178 , V_35 ) )
return false ;
F_183 ( V_12 , V_178 , V_35 ) ;
if ( ( V_178 -> V_40 & V_191 ) != V_190 )
F_184 ( V_178 ) ;
V_178 -> V_50 -> V_192 = V_35 ;
V_178 -> V_50 = V_35 ;
V_178 -> V_187 += V_35 -> V_43 ;
V_178 -> V_193 = F_185 ( V_178 -> V_193 , F_186 ( V_35 ) ) ;
F_1 ( V_178 , 0 ) ;
return true ;
}
static bool F_187 ( struct V_11 * V_12 ,
struct V_1 * V_178 , struct V_35 * V_35 )
{
const int V_190 = V_35 -> V_142 & V_191 ;
if ( ! F_188 ( V_12 , V_178 , V_35 ) )
return false ;
F_189 ( V_12 , V_178 , V_35 ) ;
if ( ( V_178 -> V_40 & V_191 ) != V_190 )
F_184 ( V_178 ) ;
V_35 -> V_192 = V_178 -> V_35 ;
V_178 -> V_35 = V_35 ;
V_178 -> V_51 = F_180 ( V_35 ) ;
V_178 -> V_23 = V_35 -> V_194 ;
V_178 -> V_187 += V_35 -> V_43 ;
V_178 -> V_193 = F_185 ( V_178 -> V_193 , F_186 ( V_35 ) ) ;
F_1 ( V_178 , 0 ) ;
return true ;
}
static bool F_190 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_195 )
{
struct V_196 * V_197 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_197 = V_146 -> V_197 ;
if ( ! V_197 )
goto V_161;
* V_195 = 0 ;
F_191 (rq, &plug->list, queuelist) {
int V_198 ;
if ( V_2 -> V_12 == V_12 )
( * V_195 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_192 ( V_2 , V_35 ) )
continue;
V_198 = F_193 ( V_2 , V_35 ) ;
if ( V_198 == V_199 ) {
V_20 = F_181 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_198 == V_200 ) {
V_20 = F_187 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_161:
return V_20 ;
}
void F_194 ( struct V_1 * V_178 , struct V_35 * V_35 )
{
V_178 -> V_49 = V_201 ;
V_178 -> V_40 |= V_35 -> V_142 & V_202 ;
if ( V_35 -> V_142 & V_203 )
V_178 -> V_40 |= V_191 ;
V_178 -> V_204 = 0 ;
V_178 -> V_23 = V_35 -> V_194 ;
V_178 -> V_193 = F_186 ( V_35 ) ;
F_195 ( V_178 -> V_12 , V_178 , V_35 ) ;
}
void V_129 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_141 = ! ! ( V_35 -> V_142 & V_205 ) ;
struct V_196 * V_197 ;
int V_198 , V_147 , V_170 = V_206 ;
struct V_1 * V_178 ;
unsigned int V_195 = 0 ;
F_156 ( V_12 , & V_35 ) ;
if ( F_196 ( V_35 ) && F_197 ( V_35 ) ) {
F_27 ( V_35 , - V_39 ) ;
return;
}
if ( V_35 -> V_142 & ( V_143 | V_144 ) ) {
F_35 ( V_12 -> V_56 ) ;
V_170 = V_207 ;
goto V_208;
}
if ( F_190 ( V_12 , V_35 , & V_195 ) )
return;
F_35 ( V_12 -> V_56 ) ;
V_198 = F_198 ( V_12 , & V_178 , V_35 ) ;
if ( V_198 == V_199 ) {
if ( F_181 ( V_12 , V_178 , V_35 ) ) {
F_199 ( V_12 , V_178 , V_35 ) ;
if ( ! F_200 ( V_12 , V_178 ) )
F_201 ( V_12 , V_178 , V_198 ) ;
goto V_209;
}
} else if ( V_198 == V_200 ) {
if ( F_187 ( V_12 , V_178 , V_35 ) ) {
F_199 ( V_12 , V_178 , V_35 ) ;
if ( ! F_202 ( V_12 , V_178 ) )
F_201 ( V_12 , V_178 , V_198 ) ;
goto V_209;
}
}
V_208:
V_147 = F_153 ( V_35 ) ;
if ( V_141 )
V_147 |= V_205 ;
V_178 = F_141 ( V_12 , V_147 , V_35 , V_210 ) ;
if ( F_24 ( ! V_178 ) ) {
F_27 ( V_35 , - V_211 ) ;
goto V_209;
}
F_194 ( V_178 , V_35 ) ;
if ( F_23 ( V_212 , & V_12 -> V_121 ) )
V_178 -> V_7 = F_203 () ;
V_197 = V_146 -> V_197 ;
if ( V_197 ) {
if ( ! V_195 )
F_204 ( V_12 ) ;
else {
if ( V_195 >= V_213 ) {
F_205 ( V_197 , false ) ;
F_204 ( V_12 ) ;
}
}
F_206 ( & V_178 -> V_21 , & V_197 -> V_214 ) ;
F_1 ( V_178 , 1 ) ;
} else {
F_35 ( V_12 -> V_56 ) ;
F_167 ( V_12 , V_178 , V_170 ) ;
F_36 ( V_12 ) ;
V_209:
F_37 ( V_12 -> V_56 ) ;
}
}
static inline void F_207 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_215 ;
if ( F_208 ( V_35 ) && V_19 != V_19 -> V_216 ) {
struct V_4 * V_217 = V_19 -> V_218 ;
V_35 -> V_194 += V_217 -> V_219 ;
V_35 -> V_215 = V_19 -> V_216 ;
F_209 ( F_15 ( V_35 -> V_215 ) , V_35 ,
V_19 -> V_220 ,
V_35 -> V_194 - V_217 -> V_219 ) ;
}
}
static void F_210 ( struct V_35 * V_35 )
{
char V_221 [ V_222 ] ;
F_29 ( V_47 L_10 ) ;
F_29 ( V_47 L_11 ,
F_211 ( V_35 -> V_215 , V_221 ) ,
V_35 -> V_142 ,
( unsigned long long ) F_212 ( V_35 ) ,
( long long ) ( F_213 ( V_35 -> V_215 -> V_223 ) >> 9 ) ) ;
F_25 ( V_224 , & V_35 -> V_38 ) ;
}
static int T_4 F_214 ( char * V_225 )
{
return F_215 ( & V_226 , V_225 ) ;
}
static bool F_216 ( struct V_4 * V_5 , unsigned int V_227 )
{
return V_5 -> V_228 && F_217 ( & V_226 , V_227 ) ;
}
static int T_4 F_218 ( void )
{
struct V_229 * V_230 = F_219 ( L_12 ,
NULL , & V_226 ) ;
return F_220 ( V_230 ) ? F_221 ( V_230 ) : 0 ;
}
static inline bool F_216 ( struct V_4 * V_5 ,
unsigned int V_227 )
{
return false ;
}
static inline int F_222 ( struct V_35 * V_35 , unsigned int V_231 )
{
V_24 V_232 ;
if ( ! V_231 )
return 0 ;
V_232 = F_213 ( V_35 -> V_215 -> V_223 ) >> 9 ;
if ( V_232 ) {
V_24 V_233 = V_35 -> V_194 ;
if ( V_232 < V_231 || V_232 - V_231 < V_233 ) {
F_210 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_223 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_231 = F_208 ( V_35 ) ;
int V_101 = - V_39 ;
char V_221 [ V_222 ] ;
struct V_4 * V_5 ;
F_224 () ;
if ( F_222 ( V_35 , V_231 ) )
goto V_234;
V_12 = F_15 ( V_35 -> V_215 ) ;
if ( F_24 ( ! V_12 ) ) {
F_29 ( V_235
L_13
L_14 ,
F_211 ( V_35 -> V_215 , V_221 ) ,
( long long ) V_35 -> V_194 ) ;
goto V_234;
}
if ( F_39 ( F_225 ( V_35 ) &&
V_231 > F_226 ( V_12 ) ) ) {
F_29 ( V_235 L_15 ,
F_211 ( V_35 -> V_215 , V_221 ) ,
F_208 ( V_35 ) ,
F_226 ( V_12 ) ) ;
goto V_234;
}
V_5 = V_35 -> V_215 -> V_218 ;
if ( F_216 ( V_5 , V_35 -> V_43 ) ||
F_216 ( & F_172 ( V_5 ) -> V_10 ,
V_35 -> V_43 ) )
goto V_234;
F_207 ( V_35 ) ;
if ( F_222 ( V_35 , V_231 ) )
goto V_234;
if ( ( V_35 -> V_142 & ( V_143 | V_144 ) ) && ! V_12 -> V_236 ) {
V_35 -> V_142 &= ~ ( V_143 | V_144 ) ;
if ( ! V_231 ) {
V_101 = 0 ;
goto V_234;
}
}
if ( ( V_35 -> V_142 & V_237 ) &&
( ! F_227 ( V_12 ) ||
( ( V_35 -> V_142 & V_238 ) && ! F_228 ( V_12 ) ) ) ) {
V_101 = - V_239 ;
goto V_234;
}
if ( V_35 -> V_142 & V_240 && ! F_229 ( V_35 -> V_215 ) ) {
V_101 = - V_239 ;
goto V_234;
}
F_151 ( V_241 , V_12 -> V_97 ) ;
if ( F_230 ( V_12 , V_35 ) )
return false ;
F_231 ( V_12 , V_35 ) ;
return true ;
V_234:
F_27 ( V_35 , V_101 ) ;
return false ;
}
void F_232 ( struct V_35 * V_35 )
{
struct V_242 V_243 ;
if ( ! F_223 ( V_35 ) )
return;
if ( V_146 -> V_242 ) {
F_233 ( V_146 -> V_242 , V_35 ) ;
return;
}
F_150 ( V_35 -> V_192 ) ;
F_234 ( & V_243 ) ;
V_146 -> V_242 = & V_243 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_215 ) ;
V_12 -> V_244 ( V_12 , V_35 ) ;
V_35 = F_235 ( V_146 -> V_242 ) ;
} while ( V_35 );
V_146 -> V_242 = NULL ;
}
void F_236 ( int V_6 , struct V_35 * V_35 )
{
V_35 -> V_142 |= V_6 ;
if ( F_237 ( V_35 ) ) {
unsigned int V_89 ;
if ( F_24 ( V_6 & V_240 ) )
V_89 = F_238 ( V_35 -> V_215 ) >> 9 ;
else
V_89 = F_208 ( V_35 ) ;
if ( V_6 & V_168 ) {
F_239 ( V_245 , V_89 ) ;
} else {
F_240 ( V_35 -> V_43 ) ;
F_239 ( V_246 , V_89 ) ;
}
if ( F_24 ( V_247 ) ) {
char V_221 [ V_222 ] ;
F_29 ( V_248 L_16 ,
V_146 -> V_249 , F_241 ( V_146 ) ,
( V_6 & V_168 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_194 ,
F_211 ( V_35 -> V_215 , V_221 ) ,
V_89 ) ;
}
}
F_232 ( V_35 ) ;
}
int F_242 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( ! F_243 ( V_2 ) )
return 0 ;
if ( F_30 ( V_2 ) > F_244 ( V_12 , V_2 -> V_40 ) ) {
F_29 ( V_235 L_19 , V_250 ) ;
return - V_39 ;
}
F_245 ( V_2 ) ;
if ( V_2 -> V_189 > F_246 ( V_12 ) ) {
F_29 ( V_235 L_20 , V_250 ) ;
return - V_39 ;
}
return 0 ;
}
int F_247 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_63 ;
int V_170 = V_251 ;
if ( F_242 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_216 ( & V_2 -> V_9 -> V_10 , F_32 ( V_2 ) ) )
return - V_39 ;
F_58 ( V_12 -> V_56 , V_63 ) ;
if ( F_24 ( F_105 ( V_12 ) ) ) {
F_59 ( V_12 -> V_56 , V_63 ) ;
return - V_211 ;
}
F_150 ( F_165 ( V_2 ) ) ;
if ( V_2 -> V_40 & ( V_143 | V_144 ) )
V_170 = V_207 ;
F_167 ( V_12 , V_2 , V_170 ) ;
if ( V_170 == V_207 )
F_36 ( V_12 ) ;
F_59 ( V_12 -> V_56 , V_63 ) ;
return 0 ;
}
unsigned int F_248 ( const struct V_1 * V_2 )
{
unsigned int V_190 = V_2 -> V_40 & V_191 ;
unsigned int V_227 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_40 & V_252 ) )
return F_32 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_192 ) {
if ( ( V_35 -> V_142 & V_190 ) != V_190 )
break;
V_227 += V_35 -> V_43 ;
}
F_150 ( F_32 ( V_2 ) && ! V_227 ) ;
return V_227 ;
}
static void F_249 ( struct V_1 * V_178 , unsigned int V_227 )
{
if ( F_3 ( V_178 ) ) {
const int V_6 = F_2 ( V_178 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_178 -> V_5 ;
F_250 ( V_7 , V_5 , V_253 [ V_6 ] , V_227 >> 9 ) ;
F_12 () ;
}
}
static void F_251 ( struct V_1 * V_178 )
{
if ( F_3 ( V_178 ) && ! ( V_178 -> V_40 & V_44 ) ) {
unsigned long V_254 = V_34 - V_178 -> V_33 ;
const int V_6 = F_2 ( V_178 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_178 -> V_5 ;
F_5 ( V_7 , V_5 , V_255 [ V_6 ] ) ;
F_250 ( V_7 , V_5 , V_256 [ V_6 ] , V_254 ) ;
F_10 ( V_7 , V_5 ) ;
F_252 ( V_5 , V_6 ) ;
F_253 ( V_5 ) ;
F_12 () ;
}
}
static struct V_1 * F_254 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
if ( V_12 -> V_163 && ( V_12 -> V_257 == V_258 ||
( V_12 -> V_257 != V_259 && ! ( V_2 -> V_40 & V_176 ) ) ) )
return NULL ;
else
return V_2 ;
}
static inline struct V_1 * F_254 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
return V_2 ;
}
struct V_1 * F_255 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_256 ( V_12 ) ) != NULL ) {
V_2 = F_254 ( V_12 , V_2 ) ;
if ( ! V_2 )
break;
if ( ! ( V_2 -> V_40 & V_260 ) ) {
if ( V_2 -> V_40 & V_261 )
F_257 ( V_12 , V_2 ) ;
V_2 -> V_40 |= V_260 ;
F_258 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_262 || V_12 -> V_262 == V_2 ) {
V_12 -> V_263 = F_259 ( V_2 ) ;
V_12 -> V_262 = NULL ;
}
if ( V_2 -> V_40 & V_264 )
break;
if ( V_12 -> V_265 && F_32 ( V_2 ) ) {
V_2 -> V_189 ++ ;
}
if ( ! V_12 -> V_126 )
break;
V_20 = V_12 -> V_126 ( V_12 , V_2 ) ;
if ( V_20 == V_266 ) {
break;
} else if ( V_20 == V_267 ) {
if ( V_12 -> V_265 && F_32 ( V_2 ) &&
! ( V_2 -> V_40 & V_264 ) ) {
-- V_2 -> V_189 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_268 ) {
V_2 -> V_40 |= V_41 ;
F_260 ( V_2 ) ;
F_261 ( V_2 , - V_39 ) ;
} else {
F_29 ( V_235 L_21 , V_250 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_262 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_150 ( F_66 ( & V_2 -> V_21 ) ) ;
F_150 ( F_263 ( V_2 ) ) ;
F_264 ( & V_2 -> V_21 ) ;
if ( F_265 ( V_2 ) ) {
V_12 -> V_72 [ F_266 ( V_2 ) ] ++ ;
F_267 ( V_2 ) ;
}
}
void F_260 ( struct V_1 * V_178 )
{
F_262 ( V_178 ) ;
V_178 -> V_188 = F_32 ( V_178 ) ;
if ( F_24 ( F_268 ( V_178 ) ) )
V_178 -> V_269 -> V_188 = F_32 ( V_178 -> V_269 ) ;
F_269 ( V_178 ) ;
}
struct V_1 * F_270 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_255 ( V_12 ) ;
if ( V_2 )
F_260 ( V_2 ) ;
return V_2 ;
}
bool F_271 ( struct V_1 * V_178 , int error , unsigned int V_270 )
{
int V_271 ;
if ( ! V_178 -> V_35 )
return false ;
F_272 ( V_178 -> V_12 , V_178 ) ;
if ( V_178 -> V_49 == V_201 )
V_178 -> V_204 = 0 ;
if ( error && V_178 -> V_49 == V_201 &&
! ( V_178 -> V_40 & V_41 ) ) {
char * V_272 ;
switch ( error ) {
case - V_273 :
V_272 = L_22 ;
break;
case - V_274 :
V_272 = L_23 ;
break;
case - V_275 :
V_272 = L_24 ;
break;
case - V_276 :
V_272 = L_25 ;
break;
case - V_277 :
V_272 = L_26 ;
break;
case - V_278 :
V_272 = L_27 ;
break;
case - V_39 :
default:
V_272 = L_28 ;
break;
}
F_139 ( V_235 L_29 ,
V_272 , V_178 -> V_9 ?
V_178 -> V_9 -> V_48 : L_2 ,
( unsigned long long ) F_7 ( V_178 ) ) ;
}
F_249 ( V_178 , V_270 ) ;
V_271 = 0 ;
while ( V_178 -> V_35 ) {
struct V_35 * V_35 = V_178 -> V_35 ;
unsigned V_279 = F_273 ( V_35 -> V_43 , V_270 ) ;
if ( V_279 == V_35 -> V_43 )
V_178 -> V_35 = V_35 -> V_192 ;
F_21 ( V_178 , V_35 , V_279 , error ) ;
V_271 += V_279 ;
V_270 -= V_279 ;
if ( ! V_270 )
break;
}
if ( ! V_178 -> V_35 ) {
V_178 -> V_187 = 0 ;
return false ;
}
V_178 -> V_187 -= V_271 ;
V_178 -> V_51 = F_180 ( V_178 -> V_35 ) ;
if ( V_178 -> V_49 == V_201 )
V_178 -> V_23 += V_271 >> 9 ;
if ( V_178 -> V_40 & V_252 ) {
V_178 -> V_40 &= ~ V_191 ;
V_178 -> V_40 |= V_178 -> V_35 -> V_142 & V_191 ;
}
if ( F_32 ( V_178 ) < F_274 ( V_178 ) ) {
F_28 ( V_178 , L_30 ) ;
V_178 -> V_187 = F_274 ( V_178 ) ;
}
F_245 ( V_178 ) ;
return true ;
}
static bool F_275 ( struct V_1 * V_2 , int error ,
unsigned int V_270 ,
unsigned int V_280 )
{
if ( F_271 ( V_2 , error , V_270 ) )
return true ;
if ( F_24 ( F_268 ( V_2 ) ) &&
F_271 ( V_2 -> V_269 , error , V_280 ) )
return true ;
if ( F_276 ( V_2 -> V_12 ) )
F_277 ( V_2 -> V_9 ) ;
return false ;
}
void F_278 ( struct V_1 * V_178 )
{
struct V_11 * V_12 = V_178 -> V_12 ;
V_178 -> V_40 &= ~ V_264 ;
if ( V_12 -> V_127 )
V_12 -> V_127 ( V_12 , V_178 ) ;
}
static void F_279 ( struct V_1 * V_178 , int error )
{
if ( F_163 ( V_178 ) )
F_164 ( V_178 -> V_12 , V_178 ) ;
F_150 ( F_165 ( V_178 ) ) ;
if ( F_24 ( V_281 ) && V_178 -> V_49 == V_201 )
F_280 ( & V_178 -> V_12 -> V_17 ) ;
F_160 ( V_178 ) ;
if ( V_178 -> V_40 & V_264 )
F_278 ( V_178 ) ;
F_251 ( V_178 ) ;
if ( V_178 -> V_234 )
V_178 -> V_234 ( V_178 , error ) ;
else {
if ( F_268 ( V_178 ) )
F_175 ( V_178 -> V_269 -> V_12 , V_178 -> V_269 ) ;
F_175 ( V_178 -> V_12 , V_178 ) ;
}
}
static bool F_281 ( struct V_1 * V_2 , int error ,
unsigned int V_270 , unsigned int V_280 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_63 ;
if ( F_275 ( V_2 , error , V_270 , V_280 ) )
return true ;
F_58 ( V_12 -> V_56 , V_63 ) ;
F_279 ( V_2 , error ) ;
F_59 ( V_12 -> V_56 , V_63 ) ;
return false ;
}
bool F_282 ( struct V_1 * V_2 , int error ,
unsigned int V_270 , unsigned int V_280 )
{
if ( F_275 ( V_2 , error , V_270 , V_280 ) )
return true ;
F_279 ( V_2 , error ) ;
return false ;
}
bool F_283 ( struct V_1 * V_2 , int error , unsigned int V_270 )
{
return F_281 ( V_2 , error , V_270 , 0 ) ;
}
void F_284 ( struct V_1 * V_2 , int error )
{
bool V_282 ;
unsigned int V_280 = 0 ;
if ( F_24 ( F_268 ( V_2 ) ) )
V_280 = F_32 ( V_2 -> V_269 ) ;
V_282 = F_281 ( V_2 , error , F_32 ( V_2 ) , V_280 ) ;
F_150 ( V_282 ) ;
}
bool F_285 ( struct V_1 * V_2 , int error )
{
return F_283 ( V_2 , error , F_274 ( V_2 ) ) ;
}
bool F_286 ( struct V_1 * V_2 , int error )
{
F_44 ( error >= 0 ) ;
return F_283 ( V_2 , error , F_248 ( V_2 ) ) ;
}
bool F_287 ( struct V_1 * V_2 , int error , unsigned int V_270 )
{
return F_282 ( V_2 , error , V_270 , 0 ) ;
}
void F_261 ( struct V_1 * V_2 , int error )
{
bool V_282 ;
unsigned int V_280 = 0 ;
if ( F_24 ( F_268 ( V_2 ) ) )
V_280 = F_32 ( V_2 -> V_269 ) ;
V_282 = F_282 ( V_2 , error , F_32 ( V_2 ) , V_280 ) ;
F_150 ( V_282 ) ;
}
bool F_288 ( struct V_1 * V_2 , int error )
{
return F_287 ( V_2 , error , F_274 ( V_2 ) ) ;
}
bool F_289 ( struct V_1 * V_2 , int error )
{
F_44 ( error >= 0 ) ;
return F_287 ( V_2 , error , F_248 ( V_2 ) ) ;
}
void F_195 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_40 |= V_35 -> V_142 & V_283 ;
if ( F_237 ( V_35 ) ) {
V_2 -> V_189 = F_290 ( V_12 , V_35 ) ;
V_2 -> V_51 = F_180 ( V_35 ) ;
}
V_2 -> V_187 = V_35 -> V_43 ;
V_2 -> V_35 = V_2 -> V_50 = V_35 ;
if ( V_35 -> V_215 )
V_2 -> V_9 = V_35 -> V_215 -> V_284 ;
}
void F_291 ( struct V_1 * V_2 )
{
struct V_285 V_286 ;
struct V_287 * V_288 ;
F_292 (bvec, rq, iter)
F_293 ( V_288 -> V_182 ) ;
}
int F_294 ( struct V_11 * V_12 )
{
if ( V_12 -> V_289 )
return V_12 -> V_289 ( V_12 ) ;
return 0 ;
}
void F_295 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_192 ;
F_296 ( V_35 ) ;
}
}
static void F_297 ( struct V_1 * V_290 , struct V_1 * V_291 )
{
V_290 -> V_7 = V_291 -> V_7 ;
V_290 -> V_40 = ( V_291 -> V_40 & V_292 ) | V_293 ;
V_290 -> V_49 = V_291 -> V_49 ;
V_290 -> V_23 = F_7 ( V_291 ) ;
V_290 -> V_187 = F_32 ( V_291 ) ;
V_290 -> V_189 = V_291 -> V_189 ;
V_290 -> V_193 = V_291 -> V_193 ;
V_290 -> V_294 = V_291 -> V_294 ;
}
int F_298 ( struct V_1 * V_2 , struct V_1 * V_295 ,
struct V_296 * V_297 , T_2 V_87 ,
int (* F_299)( struct V_35 * , struct V_35 * , void * ) ,
void * V_298 )
{
struct V_35 * V_35 , * V_299 ;
if ( ! V_297 )
V_297 = V_300 ;
F_16 ( NULL , V_2 ) ;
F_300 (bio_src, rq_src) {
V_35 = F_301 ( V_299 , V_87 , V_297 ) ;
if ( ! V_35 )
goto V_301;
if ( F_299 && F_299 ( V_35 , V_299 , V_298 ) )
goto V_301;
if ( V_2 -> V_35 ) {
V_2 -> V_50 -> V_192 = V_35 ;
V_2 -> V_50 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_50 = V_35 ;
}
F_297 ( V_2 , V_295 ) ;
return 0 ;
V_301:
if ( V_35 )
F_296 ( V_35 ) ;
F_295 ( V_2 ) ;
return - V_98 ;
}
int F_302 ( struct V_11 * V_12 , struct V_53 * V_54 )
{
return F_303 ( V_58 , V_54 ) ;
}
int F_304 ( struct V_11 * V_12 ,
struct V_302 * V_303 , unsigned long V_304 )
{
return F_41 ( V_58 , V_303 , V_304 ) ;
}
void F_305 ( struct V_196 * V_197 )
{
struct V_305 * V_306 = V_146 ;
V_197 -> V_307 = V_308 ;
F_17 ( & V_197 -> V_214 ) ;
F_17 ( & V_197 -> V_309 ) ;
if ( ! V_306 -> V_197 ) {
V_306 -> V_197 = V_197 ;
}
}
static int F_306 ( void * V_310 , struct V_311 * V_312 , struct V_311 * V_221 )
{
struct V_1 * V_313 = F_34 ( V_312 , struct V_1 , V_21 ) ;
struct V_1 * V_314 = F_34 ( V_221 , struct V_1 , V_21 ) ;
return ! ( V_313 -> V_12 < V_314 -> V_12 ||
( V_313 -> V_12 == V_314 -> V_12 && F_7 ( V_313 ) < F_7 ( V_314 ) ) ) ;
}
static void F_307 ( struct V_11 * V_12 , unsigned int V_315 ,
bool V_316 )
__releases( V_12 -> V_56 )
{
F_308 ( V_12 , V_315 , ! V_316 ) ;
if ( V_316 )
F_55 ( V_12 ) ;
else
F_36 ( V_12 ) ;
F_309 ( V_12 -> V_56 ) ;
}
static void F_310 ( struct V_196 * V_197 , bool V_316 )
{
F_311 ( V_317 ) ;
while ( ! F_66 ( & V_197 -> V_309 ) ) {
F_312 ( & V_197 -> V_309 , & V_317 ) ;
while ( ! F_66 ( & V_317 ) ) {
struct V_318 * V_319 = F_313 ( & V_317 ,
struct V_318 ,
V_214 ) ;
F_314 ( & V_319 -> V_214 ) ;
V_319 -> V_320 ( V_319 , V_316 ) ;
}
}
}
struct V_318 * F_315 ( T_6 V_321 , void * V_298 ,
int V_322 )
{
struct V_196 * V_197 = V_146 -> V_197 ;
struct V_318 * V_319 ;
if ( ! V_197 )
return NULL ;
F_316 (cb, &plug->cb_list, list)
if ( V_319 -> V_320 == V_321 && V_319 -> V_298 == V_298 )
return V_319 ;
F_150 ( V_322 < sizeof( * V_319 ) ) ;
V_319 = F_317 ( V_322 , V_241 ) ;
if ( V_319 ) {
V_319 -> V_298 = V_298 ;
V_319 -> V_320 = V_321 ;
F_318 ( & V_319 -> V_214 , & V_197 -> V_309 ) ;
}
return V_319 ;
}
void F_205 ( struct V_196 * V_197 , bool V_316 )
{
struct V_11 * V_12 ;
unsigned long V_63 ;
struct V_1 * V_2 ;
F_311 ( V_214 ) ;
unsigned int V_315 ;
F_150 ( V_197 -> V_307 != V_308 ) ;
F_310 ( V_197 , V_316 ) ;
if ( F_66 ( & V_197 -> V_214 ) )
return;
F_312 ( & V_197 -> V_214 , & V_214 ) ;
F_319 ( NULL , & V_214 , F_306 ) ;
V_12 = NULL ;
V_315 = 0 ;
F_320 ( V_63 ) ;
while ( ! F_66 ( & V_214 ) ) {
V_2 = F_321 ( V_214 . V_323 ) ;
F_264 ( & V_2 -> V_21 ) ;
F_150 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_307 ( V_12 , V_315 , V_316 ) ;
V_12 = V_2 -> V_12 ;
V_315 = 0 ;
F_322 ( V_12 -> V_56 ) ;
}
if ( F_24 ( F_105 ( V_12 ) ) ) {
F_261 ( V_2 , - V_211 ) ;
continue;
}
if ( V_2 -> V_40 & ( V_143 | V_144 ) )
F_168 ( V_12 , V_2 , V_207 ) ;
else
F_168 ( V_12 , V_2 , V_324 ) ;
V_315 ++ ;
}
if ( V_12 )
F_307 ( V_12 , V_315 , V_316 ) ;
F_323 ( V_63 ) ;
}
void F_324 ( struct V_196 * V_197 )
{
F_205 ( V_197 , false ) ;
if ( V_197 == V_146 -> V_197 )
V_146 -> V_197 = NULL ;
}
void F_325 ( struct V_11 * V_12 , struct V_325 * V_163 )
{
V_12 -> V_163 = V_163 ;
V_12 -> V_257 = V_259 ;
F_326 ( V_12 -> V_163 , - 1 ) ;
F_327 ( V_12 -> V_163 ) ;
}
int F_328 ( struct V_11 * V_12 )
{
int V_20 = 0 ;
F_35 ( V_12 -> V_56 ) ;
if ( V_12 -> V_177 ) {
V_20 = - V_326 ;
F_174 ( V_12 -> V_163 ) ;
} else {
V_12 -> V_257 = V_327 ;
}
F_37 ( V_12 -> V_56 ) ;
return V_20 ;
}
void F_329 ( struct V_11 * V_12 , int V_101 )
{
F_35 ( V_12 -> V_56 ) ;
if ( ! V_101 ) {
V_12 -> V_257 = V_258 ;
} else {
V_12 -> V_257 = V_259 ;
F_174 ( V_12 -> V_163 ) ;
}
F_37 ( V_12 -> V_56 ) ;
}
void F_330 ( struct V_11 * V_12 )
{
F_35 ( V_12 -> V_56 ) ;
V_12 -> V_257 = V_328 ;
F_37 ( V_12 -> V_56 ) ;
}
void F_331 ( struct V_11 * V_12 , int V_101 )
{
F_35 ( V_12 -> V_56 ) ;
if ( ! V_101 ) {
V_12 -> V_257 = V_259 ;
F_36 ( V_12 ) ;
F_174 ( V_12 -> V_163 ) ;
F_332 ( V_12 -> V_163 ) ;
} else {
V_12 -> V_257 = V_258 ;
}
F_37 ( V_12 -> V_56 ) ;
}
int T_4 F_333 ( void )
{
F_334 ( V_329 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_40 ) ) ;
V_58 = F_335 ( L_31 ,
V_330 | V_331 |
V_332 , 0 ) ;
if ( ! V_58 )
F_336 ( L_32 ) ;
V_96 = F_337 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_333 , NULL ) ;
V_102 = F_337 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_333 , NULL ) ;
return 0 ;
}
