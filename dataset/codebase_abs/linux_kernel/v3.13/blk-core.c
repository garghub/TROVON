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
struct V_7 * V_10 = NULL ;
struct V_1 * V_2 = F_3 ( V_9 ) ;
if ( V_2 )
V_10 = & V_2 -> V_7 ;
return V_10 ;
}
void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
F_5 ( & V_12 -> V_13 ) ;
F_5 ( & V_12 -> V_14 ) ;
V_12 -> V_15 = - 1 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_16 = ( V_17 ) - 1 ;
F_6 ( & V_12 -> V_18 ) ;
F_7 ( & V_12 -> V_19 ) ;
V_12 -> V_20 = V_12 -> V_21 ;
V_12 -> V_22 = V_23 ;
V_12 -> V_24 = - 1 ;
V_12 -> V_25 = V_26 ;
F_8 ( V_12 ) ;
V_12 -> V_27 = NULL ;
}
static void F_9 ( struct V_11 * V_12 , struct V_28 * V_28 ,
unsigned int V_29 , int error )
{
if ( error )
F_10 ( V_30 , & V_28 -> V_31 ) ;
else if ( ! F_11 ( V_30 , & V_28 -> V_31 ) )
error = - V_32 ;
if ( F_12 ( V_12 -> V_33 & V_34 ) )
F_13 ( V_35 , & V_28 -> V_31 ) ;
F_14 ( V_28 , V_29 ) ;
if ( V_28 -> V_36 == 0 && ! ( V_12 -> V_33 & V_37 ) )
F_15 ( V_28 , error ) ;
}
void F_16 ( struct V_11 * V_12 , char * V_38 )
{
int V_39 ;
F_17 ( V_40 L_1 , V_38 ,
V_12 -> V_41 ? V_12 -> V_41 -> V_42 : L_2 , V_12 -> V_43 ,
( unsigned long long ) V_12 -> V_33 ) ;
F_17 ( V_40 L_3 ,
( unsigned long long ) F_18 ( V_12 ) ,
F_19 ( V_12 ) , F_20 ( V_12 ) ) ;
F_17 ( V_40 L_4 ,
V_12 -> V_28 , V_12 -> V_44 , V_12 -> V_45 , F_21 ( V_12 ) ) ;
if ( V_12 -> V_43 == V_46 ) {
F_17 ( V_40 L_5 ) ;
for ( V_39 = 0 ; V_39 < V_23 ; V_39 ++ )
F_17 ( L_6 , V_12 -> V_20 [ V_39 ] ) ;
F_17 ( L_7 ) ;
}
}
static void F_22 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_48 , struct V_1 , V_49 . V_48 ) ;
F_24 ( V_2 -> V_50 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_50 ) ;
}
void F_27 ( struct V_1 * V_2 , unsigned long V_51 )
{
if ( F_28 ( ! F_29 ( V_2 ) ) )
F_30 ( V_52 , & V_2 -> V_49 ,
F_31 ( V_51 ) ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( ! F_34 () ) ;
F_35 ( V_53 , V_2 ) ;
F_25 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_49 ) ;
F_38 ( V_53 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_54 ) ;
F_41 ( & V_2 -> V_49 ) ;
}
inline void F_42 ( struct V_1 * V_2 )
{
if ( F_12 ( F_29 ( V_2 ) ) )
return;
V_2 -> V_55 ++ ;
V_2 -> V_56 ( V_2 ) ;
V_2 -> V_55 -- ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_12 ( F_43 ( V_2 ) ) )
return;
F_42 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_43 ( V_2 ) && ! F_29 ( V_2 ) ) )
F_45 ( V_52 , & V_2 -> V_49 , 0 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
unsigned long V_57 ;
F_47 ( V_2 -> V_50 , V_57 ) ;
F_25 ( V_2 ) ;
F_48 ( V_2 -> V_50 , V_57 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_58 ) ;
}
static void F_51 ( struct V_1 * V_2 , bool V_59 )
__releases( V_2 -> V_50 )
__acquires( V_2 -> V_50 )
{
int V_60 ;
F_52 ( V_2 -> V_50 ) ;
while ( true ) {
bool V_61 = false ;
if ( V_2 -> V_62 )
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( ! F_55 ( & V_2 -> V_63 ) && V_2 -> V_56 )
F_25 ( V_2 ) ;
V_61 |= V_2 -> V_64 ;
V_61 |= V_2 -> V_55 ;
if ( V_59 ) {
V_61 |= ! F_55 ( & V_2 -> V_63 ) ;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
V_61 |= V_2 -> V_65 [ V_60 ] ;
V_61 |= V_2 -> V_66 [ V_60 ] ;
V_61 |= ! F_55 ( & V_2 -> V_67 [ V_60 ] ) ;
}
}
if ( ! V_61 )
break;
F_26 ( V_2 -> V_50 ) ;
F_56 ( 10 ) ;
F_24 ( V_2 -> V_50 ) ;
}
if ( V_2 -> V_56 ) {
struct V_68 * V_69 ;
F_57 (rl, q)
for ( V_60 = 0 ; V_60 < F_58 ( V_69 -> V_70 ) ; V_60 ++ )
F_59 ( & V_69 -> V_70 [ V_60 ] ) ;
}
}
void F_60 ( struct V_1 * V_2 )
{
bool V_61 ;
F_24 ( V_2 -> V_50 ) ;
V_61 = ! V_2 -> V_71 ++ ;
F_38 ( V_72 , V_2 ) ;
F_26 ( V_2 -> V_50 ) ;
if ( V_61 ) {
F_24 ( V_2 -> V_50 ) ;
F_51 ( V_2 , false ) ;
F_26 ( V_2 -> V_50 ) ;
F_61 () ;
}
}
void F_62 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_71 )
F_35 ( V_72 , V_2 ) ;
F_63 ( V_2 -> V_71 < 0 ) ;
F_26 ( V_2 -> V_50 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
T_1 * V_73 = V_2 -> V_50 ;
F_65 ( & V_2 -> V_74 ) ;
F_66 ( V_75 , V_2 ) ;
F_24 ( V_73 ) ;
V_2 -> V_71 ++ ;
F_38 ( V_72 , V_2 ) ;
F_38 ( V_76 , V_2 ) ;
F_38 ( V_77 , V_2 ) ;
F_38 ( V_75 , V_2 ) ;
F_26 ( V_73 ) ;
F_67 ( & V_2 -> V_74 ) ;
F_24 ( V_73 ) ;
F_51 ( V_2 , true ) ;
F_38 ( V_78 , V_2 ) ;
F_26 ( V_73 ) ;
F_40 ( & V_2 -> V_7 . V_79 ) ;
F_39 ( V_2 ) ;
F_24 ( V_73 ) ;
if ( V_2 -> V_50 != & V_2 -> V_80 )
V_2 -> V_50 = & V_2 -> V_80 ;
F_26 ( V_73 ) ;
F_49 ( V_2 ) ;
}
int F_68 ( struct V_68 * V_69 , struct V_1 * V_2 ,
T_2 V_81 )
{
if ( F_12 ( V_69 -> V_82 ) )
return 0 ;
V_69 -> V_2 = V_2 ;
V_69 -> V_83 [ V_84 ] = V_69 -> V_83 [ V_85 ] = 0 ;
V_69 -> V_86 [ V_84 ] = V_69 -> V_86 [ V_85 ] = 0 ;
F_69 ( & V_69 -> V_70 [ V_84 ] ) ;
F_69 ( & V_69 -> V_70 [ V_85 ] ) ;
V_69 -> V_82 = F_70 ( V_87 , V_88 ,
V_89 , V_90 ,
V_81 , V_2 -> V_91 ) ;
if ( ! V_69 -> V_82 )
return - V_92 ;
return 0 ;
}
void F_71 ( struct V_68 * V_69 )
{
if ( V_69 -> V_82 )
F_72 ( V_69 -> V_82 ) ;
}
struct V_1 * F_73 ( T_2 V_81 )
{
return F_74 ( V_81 , V_93 ) ;
}
struct V_1 * F_74 ( T_2 V_81 , int V_94 )
{
struct V_1 * V_2 ;
int V_95 ;
V_2 = F_75 ( V_96 ,
V_81 | V_97 , V_94 ) ;
if ( ! V_2 )
return NULL ;
if ( F_76 ( & V_2 -> V_98 , 0 ) )
goto V_99;
V_2 -> V_100 = F_77 ( & V_101 , 0 , 0 , V_81 ) ;
if ( V_2 -> V_100 < 0 )
goto V_102;
V_2 -> V_7 . V_103 =
( V_104 * 1024 ) / V_105 ;
V_2 -> V_7 . V_106 = 0 ;
V_2 -> V_7 . V_107 = V_108 ;
V_2 -> V_7 . V_109 = L_8 ;
V_2 -> V_91 = V_94 ;
V_95 = F_78 ( & V_2 -> V_7 ) ;
if ( V_95 )
goto V_110;
F_79 ( & V_2 -> V_7 . V_79 ,
V_111 , ( unsigned long ) V_2 ) ;
F_79 ( & V_2 -> V_54 , V_112 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_63 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_113 ) ;
#ifdef F_80
F_5 ( & V_2 -> V_114 ) ;
#endif
F_5 ( & V_2 -> V_67 [ 0 ] ) ;
F_5 ( & V_2 -> V_67 [ 1 ] ) ;
F_5 ( & V_2 -> V_115 ) ;
F_81 ( & V_2 -> V_49 , F_22 ) ;
F_82 ( & V_2 -> V_58 , & V_116 ) ;
F_83 ( & V_2 -> V_74 ) ;
F_84 ( & V_2 -> V_80 ) ;
V_2 -> V_50 = & V_2 -> V_80 ;
V_2 -> V_71 = 1 ;
F_85 ( V_72 , & V_2 -> V_117 ) ;
F_69 ( & V_2 -> V_118 ) ;
if ( F_86 ( V_2 ) )
goto V_119;
return V_2 ;
V_119:
F_87 ( & V_2 -> V_7 ) ;
V_110:
F_88 ( & V_101 , V_2 -> V_100 ) ;
V_102:
F_89 ( & V_2 -> V_98 ) ;
V_99:
F_90 ( V_96 , V_2 ) ;
return NULL ;
}
struct V_1 * F_91 ( T_3 * V_120 , T_1 * V_73 )
{
return F_92 ( V_120 , V_73 , V_93 ) ;
}
struct V_1 *
F_92 ( T_3 * V_120 , T_1 * V_73 , int V_94 )
{
struct V_1 * V_121 , * V_2 ;
V_121 = F_74 ( V_122 , V_94 ) ;
if ( ! V_121 )
return NULL ;
V_2 = F_93 ( V_121 , V_120 , V_73 ) ;
if ( ! V_2 )
F_64 ( V_121 ) ;
return V_2 ;
}
struct V_1 *
F_93 ( struct V_1 * V_2 , T_3 * V_120 ,
T_1 * V_73 )
{
if ( ! V_2 )
return NULL ;
if ( F_68 ( & V_2 -> V_123 , V_2 , V_122 ) )
return NULL ;
V_2 -> V_56 = V_120 ;
V_2 -> V_124 = NULL ;
V_2 -> V_125 = NULL ;
V_2 -> V_117 |= V_126 ;
if ( V_73 )
V_2 -> V_50 = V_73 ;
F_94 ( V_2 , V_127 ) ;
V_2 -> V_128 = V_129 ;
F_65 ( & V_2 -> V_74 ) ;
if ( F_95 ( V_2 , NULL ) ) {
F_67 ( & V_2 -> V_74 ) ;
return NULL ;
}
F_67 ( & V_2 -> V_74 ) ;
return V_2 ;
}
bool F_96 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_97 ( V_2 ) ) ) {
F_98 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_99 ( struct V_68 * V_69 , struct V_11 * V_12 )
{
if ( V_12 -> V_33 & V_130 ) {
F_100 ( V_69 -> V_2 , V_12 ) ;
if ( V_12 -> V_131 . V_132 )
F_101 ( V_12 -> V_131 . V_132 -> V_133 ) ;
}
F_102 ( V_12 , V_69 -> V_82 ) ;
}
static inline int F_103 ( struct V_1 * V_2 , struct V_134 * V_133 )
{
if ( ! V_133 )
return 0 ;
return V_133 -> V_135 == V_2 -> V_136 ||
( V_133 -> V_135 > 0
&& F_104 ( V_26 , V_133 -> V_137 + V_138 ) ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_134 * V_133 )
{
if ( ! V_133 || F_103 ( V_2 , V_133 ) )
return;
V_133 -> V_135 = V_2 -> V_136 ;
V_133 -> V_137 = V_26 ;
}
static void F_106 ( struct V_68 * V_69 , int V_139 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
if ( V_69 == & V_2 -> V_123 &&
V_69 -> V_83 [ V_139 ] < F_107 ( V_2 ) )
F_108 ( V_2 , V_139 ) ;
if ( V_69 -> V_83 [ V_139 ] + 1 <= V_2 -> V_4 ) {
if ( F_109 ( & V_69 -> V_70 [ V_139 ] ) )
F_110 ( & V_69 -> V_70 [ V_139 ] ) ;
F_111 ( V_69 , V_139 ) ;
}
}
static void F_112 ( struct V_68 * V_69 , unsigned int V_57 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
int V_139 = F_113 ( V_57 ) ;
V_2 -> V_65 [ V_139 ] -- ;
V_69 -> V_83 [ V_139 ] -- ;
if ( V_57 & V_130 )
V_2 -> V_64 -- ;
F_106 ( V_69 , V_139 ) ;
if ( F_12 ( V_69 -> V_86 [ V_139 ^ 1 ] ) )
F_106 ( V_69 , V_139 ^ 1 ) ;
}
static bool F_114 ( struct V_28 * V_28 )
{
if ( ! V_28 )
return true ;
if ( V_28 -> V_140 & ( V_141 | V_142 ) )
return false ;
return true ;
}
static struct V_134 * F_115 ( struct V_28 * V_28 )
{
#ifdef F_80
if ( V_28 && V_28 -> V_143 )
return V_28 -> V_143 ;
#endif
return V_144 -> V_134 ;
}
static struct V_11 * F_116 ( struct V_68 * V_69 , int V_145 ,
struct V_28 * V_28 , T_2 V_81 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_11 * V_12 ;
struct V_146 * V_147 = V_2 -> V_62 -> type ;
struct V_134 * V_133 = F_115 ( V_28 ) ;
struct V_148 * V_132 = NULL ;
const bool V_149 = F_113 ( V_145 ) != 0 ;
int V_150 ;
if ( F_12 ( F_97 ( V_2 ) ) )
return NULL ;
V_150 = F_117 ( V_2 , V_145 ) ;
if ( V_150 == V_151 )
goto V_152;
if ( V_69 -> V_83 [ V_149 ] + 1 >= F_118 ( V_2 ) ) {
if ( V_69 -> V_83 [ V_149 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_119 ( V_69 , V_149 ) ) {
F_105 ( V_2 , V_133 ) ;
F_120 ( V_69 , V_149 ) ;
} else {
if ( V_150 != V_153
&& ! F_103 ( V_2 , V_133 ) ) {
return NULL ;
}
}
}
if ( V_69 == & V_2 -> V_123 )
F_121 ( V_2 , V_149 ) ;
}
if ( V_69 -> V_83 [ V_149 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return NULL ;
V_2 -> V_65 [ V_149 ] ++ ;
V_69 -> V_83 [ V_149 ] ++ ;
V_69 -> V_86 [ V_149 ] = 0 ;
if ( F_114 ( V_28 ) && ! F_122 ( V_2 ) ) {
V_145 |= V_130 ;
V_2 -> V_64 ++ ;
if ( V_147 -> V_154 && V_133 )
V_132 = F_123 ( V_133 , V_2 ) ;
}
if ( F_124 ( V_2 ) )
V_145 |= V_155 ;
F_26 ( V_2 -> V_50 ) ;
V_12 = F_125 ( V_69 -> V_82 , V_81 ) ;
if ( ! V_12 )
goto V_156;
F_4 ( V_2 , V_12 ) ;
F_126 ( V_12 , V_69 ) ;
V_12 -> V_33 = V_145 | V_157 ;
if ( V_145 & V_130 ) {
if ( F_12 ( V_147 -> V_154 && ! V_132 ) ) {
if ( V_133 )
V_132 = F_127 ( V_133 , V_2 , V_81 ) ;
if ( ! V_132 )
goto V_158;
}
V_12 -> V_131 . V_132 = V_132 ;
if ( F_12 ( F_128 ( V_2 , V_12 , V_28 , V_81 ) ) )
goto V_158;
if ( V_132 )
F_129 ( V_132 -> V_133 ) ;
}
V_159:
if ( F_103 ( V_2 , V_133 ) )
V_133 -> V_135 -- ;
F_130 ( V_2 , V_28 , V_145 & 1 ) ;
return V_12 ;
V_158:
F_131 ( V_160 L_9 ,
F_132 ( V_2 -> V_7 . V_161 ) ) ;
V_12 -> V_33 &= ~ V_130 ;
V_12 -> V_131 . V_132 = NULL ;
F_24 ( V_2 -> V_50 ) ;
V_2 -> V_64 -- ;
F_26 ( V_2 -> V_50 ) ;
goto V_159;
V_156:
F_24 ( V_2 -> V_50 ) ;
F_112 ( V_69 , V_145 ) ;
V_152:
if ( F_12 ( V_69 -> V_83 [ V_149 ] == 0 ) )
V_69 -> V_86 [ V_149 ] = 1 ;
return NULL ;
}
static struct V_11 * F_133 ( struct V_1 * V_2 , int V_145 ,
struct V_28 * V_28 , T_2 V_81 )
{
const bool V_149 = F_113 ( V_145 ) != 0 ;
F_134 ( V_70 ) ;
struct V_68 * V_69 ;
struct V_11 * V_12 ;
V_69 = F_135 ( V_2 , V_28 ) ;
V_162:
V_12 = F_116 ( V_69 , V_145 , V_28 , V_81 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_81 & V_163 ) || F_12 ( F_97 ( V_2 ) ) ) {
F_136 ( V_69 ) ;
return NULL ;
}
F_137 ( & V_69 -> V_70 [ V_149 ] , & V_70 ,
V_164 ) ;
F_138 ( V_2 , V_28 , V_145 & 1 ) ;
F_26 ( V_2 -> V_50 ) ;
F_139 () ;
F_105 ( V_2 , V_144 -> V_134 ) ;
F_24 ( V_2 -> V_50 ) ;
F_140 ( & V_69 -> V_70 [ V_149 ] , & V_70 ) ;
goto V_162;
}
static struct V_11 * F_141 ( struct V_1 * V_2 , int V_165 ,
T_2 V_81 )
{
struct V_11 * V_12 ;
F_142 ( V_165 != V_166 && V_165 != V_167 ) ;
F_143 ( V_81 , V_2 -> V_91 ) ;
F_24 ( V_2 -> V_50 ) ;
V_12 = F_133 ( V_2 , V_165 , NULL , V_81 ) ;
if ( ! V_12 )
F_26 ( V_2 -> V_50 ) ;
return V_12 ;
}
struct V_11 * F_144 ( struct V_1 * V_2 , int V_165 , T_2 V_81 )
{
if ( V_2 -> V_168 )
return F_145 ( V_2 , V_165 , V_81 , false ) ;
else
return F_141 ( V_2 , V_165 , V_81 ) ;
}
struct V_11 * F_146 ( struct V_1 * V_2 , struct V_28 * V_28 ,
T_2 V_81 )
{
struct V_11 * V_12 = F_144 ( V_2 , F_147 ( V_28 ) , V_81 ) ;
if ( F_12 ( ! V_12 ) )
return F_148 ( - V_92 ) ;
F_149 (bio) {
struct V_28 * V_169 = V_28 ;
int V_10 ;
F_150 ( V_2 , & V_169 ) ;
V_10 = F_151 ( V_2 , V_12 , V_169 ) ;
if ( F_12 ( V_10 ) ) {
F_152 ( V_12 ) ;
return F_148 ( V_10 ) ;
}
}
return V_12 ;
}
void F_153 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_154 ( V_12 ) ;
F_155 ( V_12 ) ;
F_156 ( V_2 , V_12 ) ;
if ( F_157 ( V_12 ) )
F_158 ( V_2 , V_12 ) ;
F_142 ( F_159 ( V_12 ) ) ;
F_160 ( V_2 , V_12 ) ;
}
static void F_161 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_170 )
{
F_162 ( V_12 , true ) ;
F_163 ( V_2 , V_12 , V_170 ) ;
}
static void F_164 ( int V_15 , struct V_171 * V_27 ,
unsigned long V_172 )
{
if ( V_172 == V_27 -> V_173 )
return;
if ( F_165 ( V_27 ) ) {
F_166 ( V_15 , V_27 , V_174 ,
F_165 ( V_27 ) * ( V_172 - V_27 -> V_173 ) ) ;
F_166 ( V_15 , V_27 , V_175 , ( V_172 - V_27 -> V_173 ) ) ;
}
V_27 -> V_173 = V_172 ;
}
void F_167 ( int V_15 , struct V_171 * V_27 )
{
unsigned long V_172 = V_26 ;
if ( V_27 -> V_176 )
F_164 ( V_15 , & F_168 ( V_27 ) -> V_177 , V_172 ) ;
F_164 ( V_15 , V_27 , V_172 ) ;
}
static void F_169 ( struct V_11 * V_12 )
{
if ( V_12 -> V_2 -> V_161 && ! ( V_12 -> V_33 & V_178 ) && ! -- V_12 -> V_2 -> V_179 )
F_170 ( V_12 -> V_2 -> V_161 ) ;
}
static inline void F_169 ( struct V_11 * V_12 ) {}
void F_171 ( struct V_1 * V_2 , struct V_11 * V_180 )
{
if ( F_12 ( ! V_2 ) )
return;
F_169 ( V_180 ) ;
F_172 ( V_2 , V_180 ) ;
F_33 ( V_180 -> V_28 != NULL ) ;
if ( V_180 -> V_33 & V_157 ) {
unsigned int V_57 = V_180 -> V_33 ;
struct V_68 * V_69 = F_173 ( V_180 ) ;
F_142 ( ! F_55 ( & V_180 -> V_13 ) ) ;
F_142 ( ! F_174 ( & V_180 -> V_18 ) ) ;
F_99 ( V_69 , V_180 ) ;
F_112 ( V_69 , V_57 ) ;
F_136 ( V_69 ) ;
}
}
void F_152 ( struct V_11 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_2 ;
if ( V_2 -> V_168 )
F_175 ( V_180 ) ;
else {
unsigned long V_57 ;
F_47 ( V_2 -> V_50 , V_57 ) ;
F_171 ( V_2 , V_180 ) ;
F_48 ( V_2 -> V_50 , V_57 ) ;
}
}
void F_176 ( struct V_11 * V_12 , struct V_181 * V_181 ,
unsigned int V_182 )
{
struct V_28 * V_28 = V_12 -> V_28 ;
V_28 -> V_183 -> V_184 = V_181 ;
V_28 -> V_183 -> V_185 = 0 ;
V_28 -> V_183 -> V_186 = V_182 ;
V_28 -> V_36 = V_182 ;
V_28 -> V_187 = 1 ;
V_28 -> V_188 = 1 ;
V_12 -> V_189 = V_12 -> V_190 = V_182 ;
V_12 -> V_191 = 1 ;
V_12 -> V_45 = F_177 ( V_28 ) ;
}
bool F_178 ( struct V_1 * V_2 , struct V_11 * V_180 ,
struct V_28 * V_28 )
{
const int V_192 = V_28 -> V_140 & V_193 ;
if ( ! F_179 ( V_2 , V_180 , V_28 ) )
return false ;
F_180 ( V_2 , V_180 , V_28 ) ;
if ( ( V_180 -> V_33 & V_193 ) != V_192 )
F_181 ( V_180 ) ;
V_180 -> V_44 -> V_194 = V_28 ;
V_180 -> V_44 = V_28 ;
V_180 -> V_189 += V_28 -> V_36 ;
V_180 -> V_195 = F_182 ( V_180 -> V_195 , F_183 ( V_28 ) ) ;
F_162 ( V_180 , false ) ;
return true ;
}
bool F_184 ( struct V_1 * V_2 , struct V_11 * V_180 ,
struct V_28 * V_28 )
{
const int V_192 = V_28 -> V_140 & V_193 ;
if ( ! F_185 ( V_2 , V_180 , V_28 ) )
return false ;
F_186 ( V_2 , V_180 , V_28 ) ;
if ( ( V_180 -> V_33 & V_193 ) != V_192 )
F_181 ( V_180 ) ;
V_28 -> V_194 = V_180 -> V_28 ;
V_180 -> V_28 = V_28 ;
V_180 -> V_45 = F_177 ( V_28 ) ;
V_180 -> V_16 = V_28 -> V_196 ;
V_180 -> V_189 += V_28 -> V_36 ;
V_180 -> V_195 = F_182 ( V_180 -> V_195 , F_183 ( V_28 ) ) ;
F_162 ( V_180 , false ) ;
return true ;
}
bool F_187 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned int * V_197 )
{
struct V_198 * V_199 ;
struct V_11 * V_12 ;
bool V_10 = false ;
struct V_200 * V_201 ;
if ( F_188 ( V_2 ) )
goto V_159;
V_199 = V_144 -> V_199 ;
if ( ! V_199 )
goto V_159;
* V_197 = 0 ;
if ( V_2 -> V_168 )
V_201 = & V_199 -> V_202 ;
else
V_201 = & V_199 -> V_203 ;
F_189 (rq, plug_list, queuelist) {
int V_204 ;
if ( V_12 -> V_2 == V_2 )
( * V_197 ) ++ ;
if ( V_12 -> V_2 != V_2 || ! F_190 ( V_12 , V_28 ) )
continue;
V_204 = F_191 ( V_12 , V_28 ) ;
if ( V_204 == V_205 ) {
V_10 = F_178 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
} else if ( V_204 == V_206 ) {
V_10 = F_184 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
}
}
V_159:
return V_10 ;
}
void F_192 ( struct V_11 * V_180 , struct V_28 * V_28 )
{
V_180 -> V_43 = V_207 ;
V_180 -> V_33 |= V_28 -> V_140 & V_208 ;
if ( V_28 -> V_140 & V_209 )
V_180 -> V_33 |= V_193 ;
V_180 -> V_210 = 0 ;
V_180 -> V_16 = V_28 -> V_196 ;
V_180 -> V_195 = F_183 ( V_28 ) ;
F_193 ( V_180 -> V_2 , V_180 , V_28 ) ;
}
void V_127 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
const bool V_139 = ! ! ( V_28 -> V_140 & V_211 ) ;
struct V_198 * V_199 ;
int V_204 , V_145 , V_170 = V_212 ;
struct V_11 * V_180 ;
unsigned int V_197 = 0 ;
F_150 ( V_2 , & V_28 ) ;
if ( F_194 ( V_28 ) && F_195 ( V_28 ) ) {
F_15 ( V_28 , - V_32 ) ;
return;
}
if ( V_28 -> V_140 & ( V_141 | V_142 ) ) {
F_24 ( V_2 -> V_50 ) ;
V_170 = V_213 ;
goto V_214;
}
if ( F_187 ( V_2 , V_28 , & V_197 ) )
return;
F_24 ( V_2 -> V_50 ) ;
V_204 = F_196 ( V_2 , & V_180 , V_28 ) ;
if ( V_204 == V_205 ) {
if ( F_178 ( V_2 , V_180 , V_28 ) ) {
F_197 ( V_2 , V_180 , V_28 ) ;
if ( ! F_198 ( V_2 , V_180 ) )
F_199 ( V_2 , V_180 , V_204 ) ;
goto V_215;
}
} else if ( V_204 == V_206 ) {
if ( F_184 ( V_2 , V_180 , V_28 ) ) {
F_197 ( V_2 , V_180 , V_28 ) ;
if ( ! F_200 ( V_2 , V_180 ) )
F_199 ( V_2 , V_180 , V_204 ) ;
goto V_215;
}
}
V_214:
V_145 = F_147 ( V_28 ) ;
if ( V_139 )
V_145 |= V_211 ;
V_180 = F_133 ( V_2 , V_145 , V_28 , V_216 ) ;
if ( F_12 ( ! V_180 ) ) {
F_15 ( V_28 , - V_217 ) ;
goto V_215;
}
F_192 ( V_180 , V_28 ) ;
if ( F_11 ( V_218 , & V_2 -> V_117 ) )
V_180 -> V_15 = F_201 () ;
V_199 = V_144 -> V_199 ;
if ( V_199 ) {
if ( ! V_197 )
F_202 ( V_2 ) ;
else {
if ( V_197 >= V_219 ) {
F_203 ( V_199 , false ) ;
F_202 ( V_2 ) ;
}
}
F_204 ( & V_180 -> V_13 , & V_199 -> V_203 ) ;
F_162 ( V_180 , true ) ;
} else {
F_24 ( V_2 -> V_50 ) ;
F_161 ( V_2 , V_180 , V_170 ) ;
F_25 ( V_2 ) ;
V_215:
F_26 ( V_2 -> V_50 ) ;
}
}
static inline void F_205 ( struct V_28 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_220 ;
if ( F_206 ( V_28 ) && V_9 != V_9 -> V_221 ) {
struct V_171 * V_222 = V_9 -> V_223 ;
V_28 -> V_196 += V_222 -> V_224 ;
V_28 -> V_220 = V_9 -> V_221 ;
F_207 ( F_3 ( V_28 -> V_220 ) , V_28 ,
V_9 -> V_225 ,
V_28 -> V_196 - V_222 -> V_224 ) ;
}
}
static void F_208 ( struct V_28 * V_28 )
{
char V_226 [ V_227 ] ;
F_17 ( V_40 L_10 ) ;
F_17 ( V_40 L_11 ,
F_209 ( V_28 -> V_220 , V_226 ) ,
V_28 -> V_140 ,
( unsigned long long ) F_210 ( V_28 ) ,
( long long ) ( F_211 ( V_28 -> V_220 -> V_228 ) >> 9 ) ) ;
F_13 ( V_229 , & V_28 -> V_31 ) ;
}
static int T_4 F_212 ( char * V_230 )
{
return F_213 ( & V_231 , V_230 ) ;
}
static bool F_214 ( struct V_171 * V_27 , unsigned int V_232 )
{
return V_27 -> V_233 && F_215 ( & V_231 , V_232 ) ;
}
static int T_4 F_216 ( void )
{
struct V_234 * V_235 = F_217 ( L_12 ,
NULL , & V_231 ) ;
return F_218 ( V_235 ) ? F_219 ( V_235 ) : 0 ;
}
static inline bool F_214 ( struct V_171 * V_27 ,
unsigned int V_232 )
{
return false ;
}
static inline int F_220 ( struct V_28 * V_28 , unsigned int V_236 )
{
V_17 V_237 ;
if ( ! V_236 )
return 0 ;
V_237 = F_211 ( V_28 -> V_220 -> V_228 ) >> 9 ;
if ( V_237 ) {
V_17 V_238 = V_28 -> V_196 ;
if ( V_237 < V_236 || V_237 - V_236 < V_238 ) {
F_208 ( V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_221 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
int V_236 = F_206 ( V_28 ) ;
int V_95 = - V_32 ;
char V_226 [ V_227 ] ;
struct V_171 * V_27 ;
F_222 () ;
if ( F_220 ( V_28 , V_236 ) )
goto V_239;
V_2 = F_3 ( V_28 -> V_220 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_240
L_13
L_14 ,
F_209 ( V_28 -> V_220 , V_226 ) ,
( long long ) V_28 -> V_196 ) ;
goto V_239;
}
if ( F_28 ( F_223 ( V_28 ) &&
V_236 > F_224 ( V_2 ) ) ) {
F_17 ( V_240 L_15 ,
F_209 ( V_28 -> V_220 , V_226 ) ,
F_206 ( V_28 ) ,
F_224 ( V_2 ) ) ;
goto V_239;
}
V_27 = V_28 -> V_220 -> V_223 ;
if ( F_214 ( V_27 , V_28 -> V_36 ) ||
F_214 ( & F_168 ( V_27 ) -> V_177 ,
V_28 -> V_36 ) )
goto V_239;
F_205 ( V_28 ) ;
if ( F_220 ( V_28 , V_236 ) )
goto V_239;
if ( ( V_28 -> V_140 & ( V_141 | V_142 ) ) && ! V_2 -> V_241 ) {
V_28 -> V_140 &= ~ ( V_141 | V_142 ) ;
if ( ! V_236 ) {
V_95 = 0 ;
goto V_239;
}
}
if ( ( V_28 -> V_140 & V_242 ) &&
( ! F_225 ( V_2 ) ||
( ( V_28 -> V_140 & V_243 ) && ! F_226 ( V_2 ) ) ) ) {
V_95 = - V_244 ;
goto V_239;
}
if ( V_28 -> V_140 & V_245 && ! F_227 ( V_28 -> V_220 ) ) {
V_95 = - V_244 ;
goto V_239;
}
F_143 ( V_246 , V_2 -> V_91 ) ;
if ( F_228 ( V_2 , V_28 ) )
return false ;
F_229 ( V_2 , V_28 ) ;
return true ;
V_239:
F_15 ( V_28 , V_95 ) ;
return false ;
}
void F_230 ( struct V_28 * V_28 )
{
struct V_247 V_248 ;
if ( ! F_221 ( V_28 ) )
return;
if ( V_144 -> V_247 ) {
F_231 ( V_144 -> V_247 , V_28 ) ;
return;
}
F_142 ( V_28 -> V_194 ) ;
F_232 ( & V_248 ) ;
V_144 -> V_247 = & V_248 ;
do {
struct V_1 * V_2 = F_3 ( V_28 -> V_220 ) ;
V_2 -> V_249 ( V_2 , V_28 ) ;
V_28 = F_233 ( V_144 -> V_247 ) ;
} while ( V_28 );
V_144 -> V_247 = NULL ;
}
void F_234 ( int V_165 , struct V_28 * V_28 )
{
V_28 -> V_140 |= V_165 ;
if ( F_235 ( V_28 ) ) {
unsigned int V_83 ;
if ( F_12 ( V_165 & V_245 ) )
V_83 = F_236 ( V_28 -> V_220 ) >> 9 ;
else
V_83 = F_206 ( V_28 ) ;
if ( V_165 & V_167 ) {
F_237 ( V_250 , V_83 ) ;
} else {
F_238 ( V_28 -> V_36 ) ;
F_237 ( V_251 , V_83 ) ;
}
if ( F_12 ( V_252 ) ) {
char V_226 [ V_227 ] ;
F_17 ( V_253 L_16 ,
V_144 -> V_254 , F_239 ( V_144 ) ,
( V_165 & V_167 ) ? L_17 : L_18 ,
( unsigned long long ) V_28 -> V_196 ,
F_209 ( V_28 -> V_220 , V_226 ) ,
V_83 ) ;
}
}
F_230 ( V_28 ) ;
}
int F_240 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_241 ( V_12 ) )
return 0 ;
if ( F_19 ( V_12 ) > F_242 ( V_2 , V_12 -> V_33 ) ) {
F_17 ( V_240 L_19 , V_255 ) ;
return - V_32 ;
}
F_243 ( V_12 ) ;
if ( V_12 -> V_191 > F_244 ( V_2 ) ) {
F_17 ( V_240 L_20 , V_255 ) ;
return - V_32 ;
}
return 0 ;
}
int F_245 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned long V_57 ;
int V_170 = V_256 ;
if ( F_240 ( V_2 , V_12 ) )
return - V_32 ;
if ( V_12 -> V_41 &&
F_214 ( & V_12 -> V_41 -> V_177 , F_21 ( V_12 ) ) )
return - V_32 ;
F_47 ( V_2 -> V_50 , V_57 ) ;
if ( F_12 ( F_97 ( V_2 ) ) ) {
F_48 ( V_2 -> V_50 , V_57 ) ;
return - V_217 ;
}
F_142 ( F_159 ( V_12 ) ) ;
if ( V_12 -> V_33 & ( V_141 | V_142 ) )
V_170 = V_213 ;
F_161 ( V_2 , V_12 , V_170 ) ;
if ( V_170 == V_213 )
F_25 ( V_2 ) ;
F_48 ( V_2 -> V_50 , V_57 ) ;
return 0 ;
}
unsigned int F_246 ( const struct V_11 * V_12 )
{
unsigned int V_192 = V_12 -> V_33 & V_193 ;
unsigned int V_232 = 0 ;
struct V_28 * V_28 ;
if ( ! ( V_12 -> V_33 & V_257 ) )
return F_21 ( V_12 ) ;
for ( V_28 = V_12 -> V_28 ; V_28 ; V_28 = V_28 -> V_194 ) {
if ( ( V_28 -> V_140 & V_192 ) != V_192 )
break;
V_232 += V_28 -> V_36 ;
}
F_142 ( F_21 ( V_12 ) && ! V_232 ) ;
return V_232 ;
}
void F_247 ( struct V_11 * V_180 , unsigned int V_232 )
{
if ( F_248 ( V_180 ) ) {
const int V_165 = F_249 ( V_180 ) ;
struct V_171 * V_27 ;
int V_15 ;
V_15 = F_250 () ;
V_27 = V_180 -> V_27 ;
F_251 ( V_15 , V_27 , V_258 [ V_165 ] , V_232 >> 9 ) ;
F_252 () ;
}
}
void F_253 ( struct V_11 * V_180 )
{
if ( F_248 ( V_180 ) && ! ( V_180 -> V_33 & V_37 ) ) {
unsigned long V_259 = V_26 - V_180 -> V_25 ;
const int V_165 = F_249 ( V_180 ) ;
struct V_171 * V_27 ;
int V_15 ;
V_15 = F_250 () ;
V_27 = V_180 -> V_27 ;
F_254 ( V_15 , V_27 , V_260 [ V_165 ] ) ;
F_251 ( V_15 , V_27 , V_261 [ V_165 ] , V_259 ) ;
F_167 ( V_15 , V_27 ) ;
F_255 ( V_27 , V_165 ) ;
F_256 ( V_27 ) ;
F_252 () ;
}
}
static struct V_11 * F_257 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( V_2 -> V_161 && ( V_2 -> V_262 == V_263 ||
( V_2 -> V_262 != V_264 && ! ( V_12 -> V_33 & V_178 ) ) ) )
return NULL ;
else
return V_12 ;
}
static inline struct V_11 * F_257 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return V_12 ;
}
void F_162 ( struct V_11 * V_12 , bool V_265 )
{
struct V_171 * V_27 ;
int V_165 = F_249 ( V_12 ) ;
int V_15 ;
if ( ! F_248 ( V_12 ) )
return;
V_15 = F_250 () ;
if ( ! V_265 ) {
V_27 = V_12 -> V_27 ;
F_254 ( V_15 , V_27 , V_266 [ V_165 ] ) ;
} else {
V_27 = F_258 ( V_12 -> V_41 , F_18 ( V_12 ) ) ;
if ( ! F_259 ( V_27 ) ) {
V_27 = & V_12 -> V_41 -> V_177 ;
F_260 ( V_27 ) ;
}
F_167 ( V_15 , V_27 ) ;
F_261 ( V_27 , V_165 ) ;
V_12 -> V_27 = V_27 ;
}
F_252 () ;
}
struct V_11 * F_262 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_10 ;
while ( ( V_12 = F_263 ( V_2 ) ) != NULL ) {
V_12 = F_257 ( V_2 , V_12 ) ;
if ( ! V_12 )
break;
if ( ! ( V_12 -> V_33 & V_267 ) ) {
if ( V_12 -> V_33 & V_268 )
F_264 ( V_2 , V_12 ) ;
V_12 -> V_33 |= V_267 ;
F_265 ( V_2 , V_12 ) ;
}
if ( ! V_2 -> V_269 || V_2 -> V_269 == V_12 ) {
V_2 -> V_270 = F_266 ( V_12 ) ;
V_2 -> V_269 = NULL ;
}
if ( V_12 -> V_33 & V_271 )
break;
if ( V_2 -> V_272 && F_21 ( V_12 ) ) {
V_12 -> V_191 ++ ;
}
if ( ! V_2 -> V_124 )
break;
V_10 = V_2 -> V_124 ( V_2 , V_12 ) ;
if ( V_10 == V_273 ) {
break;
} else if ( V_10 == V_274 ) {
if ( V_2 -> V_272 && F_21 ( V_12 ) &&
! ( V_12 -> V_33 & V_271 ) ) {
-- V_12 -> V_191 ;
}
V_12 = NULL ;
break;
} else if ( V_10 == V_275 ) {
V_12 -> V_33 |= V_34 ;
F_267 ( V_12 ) ;
F_268 ( V_12 , - V_32 ) ;
} else {
F_17 ( V_240 L_21 , V_255 , V_10 ) ;
break;
}
}
return V_12 ;
}
void F_269 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_142 ( F_55 ( & V_12 -> V_13 ) ) ;
F_142 ( F_270 ( V_12 ) ) ;
F_271 ( & V_12 -> V_13 ) ;
if ( F_272 ( V_12 ) ) {
V_2 -> V_66 [ F_273 ( V_12 ) ] ++ ;
F_274 ( V_12 ) ;
}
}
void F_267 ( struct V_11 * V_180 )
{
F_269 ( V_180 ) ;
V_180 -> V_190 = F_21 ( V_180 ) ;
if ( F_12 ( F_275 ( V_180 ) ) )
V_180 -> V_276 -> V_190 = F_21 ( V_180 -> V_276 ) ;
F_142 ( F_11 ( V_277 , & V_180 -> V_278 ) ) ;
F_276 ( V_180 ) ;
}
struct V_11 * F_277 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_262 ( V_2 ) ;
if ( V_12 )
F_267 ( V_12 ) ;
return V_12 ;
}
bool F_278 ( struct V_11 * V_180 , int error , unsigned int V_279 )
{
int V_280 ;
if ( ! V_180 -> V_28 )
return false ;
F_279 ( V_180 -> V_2 , V_180 ) ;
if ( V_180 -> V_43 == V_207 )
V_180 -> V_210 = 0 ;
if ( error && V_180 -> V_43 == V_207 &&
! ( V_180 -> V_33 & V_34 ) ) {
char * V_281 ;
switch ( error ) {
case - V_282 :
V_281 = L_22 ;
break;
case - V_283 :
V_281 = L_23 ;
break;
case - V_284 :
V_281 = L_24 ;
break;
case - V_285 :
V_281 = L_25 ;
break;
case - V_286 :
V_281 = L_26 ;
break;
case - V_287 :
V_281 = L_27 ;
break;
case - V_32 :
default:
V_281 = L_28 ;
break;
}
F_131 ( V_240 L_29 ,
V_281 , V_180 -> V_41 ?
V_180 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_18 ( V_180 ) ) ;
}
F_247 ( V_180 , V_279 ) ;
V_280 = 0 ;
while ( V_180 -> V_28 ) {
struct V_28 * V_28 = V_180 -> V_28 ;
unsigned V_288 = F_280 ( V_28 -> V_36 , V_279 ) ;
if ( V_288 == V_28 -> V_36 )
V_180 -> V_28 = V_28 -> V_194 ;
F_9 ( V_180 , V_28 , V_288 , error ) ;
V_280 += V_288 ;
V_279 -= V_288 ;
if ( ! V_279 )
break;
}
if ( ! V_180 -> V_28 ) {
V_180 -> V_189 = 0 ;
return false ;
}
V_180 -> V_189 -= V_280 ;
V_180 -> V_45 = F_177 ( V_180 -> V_28 ) ;
if ( V_180 -> V_43 == V_207 )
V_180 -> V_16 += V_280 >> 9 ;
if ( V_180 -> V_33 & V_257 ) {
V_180 -> V_33 &= ~ V_193 ;
V_180 -> V_33 |= V_180 -> V_28 -> V_140 & V_193 ;
}
if ( F_21 ( V_180 ) < F_281 ( V_180 ) ) {
F_16 ( V_180 , L_30 ) ;
V_180 -> V_189 = F_281 ( V_180 ) ;
}
F_243 ( V_180 ) ;
return true ;
}
static bool F_282 ( struct V_11 * V_12 , int error ,
unsigned int V_279 ,
unsigned int V_289 )
{
if ( F_278 ( V_12 , error , V_279 ) )
return true ;
if ( F_12 ( F_275 ( V_12 ) ) &&
F_278 ( V_12 -> V_276 , error , V_289 ) )
return true ;
if ( F_283 ( V_12 -> V_2 ) )
F_284 ( V_12 -> V_41 ) ;
return false ;
}
void F_285 ( struct V_11 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_2 ;
V_180 -> V_33 &= ~ V_271 ;
if ( V_2 -> V_125 )
V_2 -> V_125 ( V_2 , V_180 ) ;
}
static void F_286 ( struct V_11 * V_180 , int error )
{
if ( F_157 ( V_180 ) )
F_158 ( V_180 -> V_2 , V_180 ) ;
F_142 ( F_159 ( V_180 ) ) ;
if ( F_12 ( V_290 ) && V_180 -> V_43 == V_207 )
F_287 ( & V_180 -> V_2 -> V_7 ) ;
F_154 ( V_180 ) ;
if ( V_180 -> V_33 & V_271 )
F_285 ( V_180 ) ;
F_253 ( V_180 ) ;
if ( V_180 -> V_239 )
V_180 -> V_239 ( V_180 , error ) ;
else {
if ( F_275 ( V_180 ) )
F_171 ( V_180 -> V_276 -> V_2 , V_180 -> V_276 ) ;
F_171 ( V_180 -> V_2 , V_180 ) ;
}
}
static bool F_288 ( struct V_11 * V_12 , int error ,
unsigned int V_279 , unsigned int V_289 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_57 ;
if ( F_282 ( V_12 , error , V_279 , V_289 ) )
return true ;
F_47 ( V_2 -> V_50 , V_57 ) ;
F_286 ( V_12 , error ) ;
F_48 ( V_2 -> V_50 , V_57 ) ;
return false ;
}
bool F_289 ( struct V_11 * V_12 , int error ,
unsigned int V_279 , unsigned int V_289 )
{
if ( F_282 ( V_12 , error , V_279 , V_289 ) )
return true ;
F_286 ( V_12 , error ) ;
return false ;
}
bool F_290 ( struct V_11 * V_12 , int error , unsigned int V_279 )
{
return F_288 ( V_12 , error , V_279 , 0 ) ;
}
void F_291 ( struct V_11 * V_12 , int error )
{
bool V_291 ;
unsigned int V_289 = 0 ;
if ( F_12 ( F_275 ( V_12 ) ) )
V_289 = F_21 ( V_12 -> V_276 ) ;
V_291 = F_288 ( V_12 , error , F_21 ( V_12 ) , V_289 ) ;
F_142 ( V_291 ) ;
}
bool F_292 ( struct V_11 * V_12 , int error )
{
return F_290 ( V_12 , error , F_281 ( V_12 ) ) ;
}
bool F_293 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_290 ( V_12 , error , F_246 ( V_12 ) ) ;
}
bool F_294 ( struct V_11 * V_12 , int error , unsigned int V_279 )
{
return F_289 ( V_12 , error , V_279 , 0 ) ;
}
void F_268 ( struct V_11 * V_12 , int error )
{
bool V_291 ;
unsigned int V_289 = 0 ;
if ( F_12 ( F_275 ( V_12 ) ) )
V_289 = F_21 ( V_12 -> V_276 ) ;
V_291 = F_289 ( V_12 , error , F_21 ( V_12 ) , V_289 ) ;
F_142 ( V_291 ) ;
}
bool F_295 ( struct V_11 * V_12 , int error )
{
return F_294 ( V_12 , error , F_281 ( V_12 ) ) ;
}
bool F_296 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_294 ( V_12 , error , F_246 ( V_12 ) ) ;
}
void F_193 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_28 * V_28 )
{
V_12 -> V_33 |= V_28 -> V_140 & V_292 ;
if ( F_235 ( V_28 ) ) {
V_12 -> V_191 = F_297 ( V_2 , V_28 ) ;
V_12 -> V_45 = F_177 ( V_28 ) ;
}
V_12 -> V_189 = V_28 -> V_36 ;
V_12 -> V_28 = V_12 -> V_44 = V_28 ;
if ( V_28 -> V_220 )
V_12 -> V_41 = V_28 -> V_220 -> V_293 ;
}
void F_298 ( struct V_11 * V_12 )
{
struct V_294 V_295 ;
struct V_296 * V_297 ;
F_299 (bvec, rq, iter)
F_300 ( V_297 -> V_184 ) ;
}
int F_301 ( struct V_1 * V_2 )
{
if ( V_2 -> V_298 )
return V_2 -> V_298 ( V_2 ) ;
return 0 ;
}
void F_302 ( struct V_11 * V_12 )
{
struct V_28 * V_28 ;
while ( ( V_28 = V_12 -> V_28 ) != NULL ) {
V_12 -> V_28 = V_28 -> V_194 ;
F_303 ( V_28 ) ;
}
}
static void F_304 ( struct V_11 * V_299 , struct V_11 * V_300 )
{
V_299 -> V_15 = V_300 -> V_15 ;
V_299 -> V_33 = ( V_300 -> V_33 & V_301 ) | V_302 ;
V_299 -> V_43 = V_300 -> V_43 ;
V_299 -> V_16 = F_18 ( V_300 ) ;
V_299 -> V_189 = F_21 ( V_300 ) ;
V_299 -> V_191 = V_300 -> V_191 ;
V_299 -> V_195 = V_300 -> V_195 ;
V_299 -> V_303 = V_300 -> V_303 ;
}
int F_305 ( struct V_11 * V_12 , struct V_11 * V_304 ,
struct V_305 * V_306 , T_2 V_81 ,
int (* F_306)( struct V_28 * , struct V_28 * , void * ) ,
void * V_307 )
{
struct V_28 * V_28 , * V_308 ;
if ( ! V_306 )
V_306 = V_309 ;
F_4 ( NULL , V_12 ) ;
F_307 (bio_src, rq_src) {
V_28 = F_308 ( V_308 , V_81 , V_306 ) ;
if ( ! V_28 )
goto V_310;
if ( F_306 && F_306 ( V_28 , V_308 , V_307 ) )
goto V_310;
if ( V_12 -> V_28 ) {
V_12 -> V_44 -> V_194 = V_28 ;
V_12 -> V_44 = V_28 ;
} else
V_12 -> V_28 = V_12 -> V_44 = V_28 ;
}
F_304 ( V_12 , V_304 ) ;
return 0 ;
V_310:
if ( V_28 )
F_303 ( V_28 ) ;
F_302 ( V_12 ) ;
return - V_92 ;
}
int F_309 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
return F_310 ( V_52 , V_48 ) ;
}
int F_311 ( struct V_1 * V_2 ,
struct V_311 * V_312 , unsigned long V_313 )
{
return F_30 ( V_52 , V_312 , V_313 ) ;
}
void F_312 ( struct V_198 * V_199 )
{
struct V_314 * V_315 = V_144 ;
V_199 -> V_316 = V_317 ;
F_5 ( & V_199 -> V_203 ) ;
F_5 ( & V_199 -> V_202 ) ;
F_5 ( & V_199 -> V_318 ) ;
if ( ! V_315 -> V_199 ) {
V_315 -> V_199 = V_199 ;
}
}
static int F_313 ( void * V_319 , struct V_200 * V_320 , struct V_200 * V_226 )
{
struct V_11 * V_321 = F_23 ( V_320 , struct V_11 , V_13 ) ;
struct V_11 * V_322 = F_23 ( V_226 , struct V_11 , V_13 ) ;
return ! ( V_321 -> V_2 < V_322 -> V_2 ||
( V_321 -> V_2 == V_322 -> V_2 && F_18 ( V_321 ) < F_18 ( V_322 ) ) ) ;
}
static void F_314 ( struct V_1 * V_2 , unsigned int V_323 ,
bool V_324 )
__releases( V_2 -> V_50 )
{
F_315 ( V_2 , V_323 , ! V_324 ) ;
if ( V_324 )
F_44 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_316 ( V_2 -> V_50 ) ;
}
static void F_317 ( struct V_198 * V_199 , bool V_324 )
{
F_318 ( V_325 ) ;
while ( ! F_55 ( & V_199 -> V_318 ) ) {
F_319 ( & V_199 -> V_318 , & V_325 ) ;
while ( ! F_55 ( & V_325 ) ) {
struct V_326 * V_327 = F_320 ( & V_325 ,
struct V_326 ,
V_203 ) ;
F_321 ( & V_327 -> V_203 ) ;
V_327 -> V_328 ( V_327 , V_324 ) ;
}
}
}
struct V_326 * F_322 ( T_6 V_329 , void * V_307 ,
int V_330 )
{
struct V_198 * V_199 = V_144 -> V_199 ;
struct V_326 * V_327 ;
if ( ! V_199 )
return NULL ;
F_323 (cb, &plug->cb_list, list)
if ( V_327 -> V_328 == V_329 && V_327 -> V_307 == V_307 )
return V_327 ;
F_142 ( V_330 < sizeof( * V_327 ) ) ;
V_327 = F_324 ( V_330 , V_246 ) ;
if ( V_327 ) {
V_327 -> V_307 = V_307 ;
V_327 -> V_328 = V_329 ;
F_325 ( & V_327 -> V_203 , & V_199 -> V_318 ) ;
}
return V_327 ;
}
void F_203 ( struct V_198 * V_199 , bool V_324 )
{
struct V_1 * V_2 ;
unsigned long V_57 ;
struct V_11 * V_12 ;
F_318 ( V_203 ) ;
unsigned int V_323 ;
F_142 ( V_199 -> V_316 != V_317 ) ;
F_317 ( V_199 , V_324 ) ;
if ( ! F_55 ( & V_199 -> V_202 ) )
F_326 ( V_199 , V_324 ) ;
if ( F_55 ( & V_199 -> V_203 ) )
return;
F_319 ( & V_199 -> V_203 , & V_203 ) ;
F_327 ( NULL , & V_203 , F_313 ) ;
V_2 = NULL ;
V_323 = 0 ;
F_328 ( V_57 ) ;
while ( ! F_55 ( & V_203 ) ) {
V_12 = F_329 ( V_203 . V_331 ) ;
F_271 ( & V_12 -> V_13 ) ;
F_142 ( ! V_12 -> V_2 ) ;
if ( V_12 -> V_2 != V_2 ) {
if ( V_2 )
F_314 ( V_2 , V_323 , V_324 ) ;
V_2 = V_12 -> V_2 ;
V_323 = 0 ;
F_330 ( V_2 -> V_50 ) ;
}
if ( F_12 ( F_97 ( V_2 ) ) ) {
F_268 ( V_12 , - V_217 ) ;
continue;
}
if ( V_12 -> V_33 & ( V_141 | V_142 ) )
F_163 ( V_2 , V_12 , V_213 ) ;
else
F_163 ( V_2 , V_12 , V_332 ) ;
V_323 ++ ;
}
if ( V_2 )
F_314 ( V_2 , V_323 , V_324 ) ;
F_331 ( V_57 ) ;
}
void F_332 ( struct V_198 * V_199 )
{
F_203 ( V_199 , false ) ;
if ( V_199 == V_144 -> V_199 )
V_144 -> V_199 = NULL ;
}
void F_333 ( struct V_1 * V_2 , struct V_333 * V_161 )
{
V_2 -> V_161 = V_161 ;
V_2 -> V_262 = V_264 ;
F_334 ( V_2 -> V_161 , - 1 ) ;
F_335 ( V_2 -> V_161 ) ;
}
int F_336 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_24 ( V_2 -> V_50 ) ;
if ( V_2 -> V_179 ) {
V_10 = - V_334 ;
F_170 ( V_2 -> V_161 ) ;
} else {
V_2 -> V_262 = V_335 ;
}
F_26 ( V_2 -> V_50 ) ;
return V_10 ;
}
void F_337 ( struct V_1 * V_2 , int V_95 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! V_95 ) {
V_2 -> V_262 = V_263 ;
} else {
V_2 -> V_262 = V_264 ;
F_170 ( V_2 -> V_161 ) ;
}
F_26 ( V_2 -> V_50 ) ;
}
void F_338 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_50 ) ;
V_2 -> V_262 = V_336 ;
F_26 ( V_2 -> V_50 ) ;
}
void F_339 ( struct V_1 * V_2 , int V_95 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! V_95 ) {
V_2 -> V_262 = V_264 ;
F_25 ( V_2 ) ;
F_170 ( V_2 -> V_161 ) ;
F_340 ( V_2 -> V_161 ) ;
} else {
V_2 -> V_262 = V_263 ;
}
F_26 ( V_2 -> V_50 ) ;
}
int T_4 F_341 ( void )
{
F_342 ( V_337 > 8 *
sizeof( ( (struct V_11 * ) 0 ) -> V_33 ) ) ;
V_52 = F_343 ( L_31 ,
V_338 | V_339 |
V_340 , 0 ) ;
if ( ! V_52 )
F_344 ( L_32 ) ;
V_90 = F_345 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_341 , NULL ) ;
V_96 = F_345 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_341 , NULL ) ;
return 0 ;
}
