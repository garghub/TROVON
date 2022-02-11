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
if ( V_28 -> V_36 . V_37 == 0 && ! ( V_12 -> V_33 & V_38 ) )
F_15 ( V_28 , error ) ;
}
void F_16 ( struct V_11 * V_12 , char * V_39 )
{
int V_40 ;
F_17 ( V_41 L_1 , V_39 ,
V_12 -> V_42 ? V_12 -> V_42 -> V_43 : L_2 , V_12 -> V_44 ,
( unsigned long long ) V_12 -> V_33 ) ;
F_17 ( V_41 L_3 ,
( unsigned long long ) F_18 ( V_12 ) ,
F_19 ( V_12 ) , F_20 ( V_12 ) ) ;
F_17 ( V_41 L_4 ,
V_12 -> V_28 , V_12 -> V_45 , F_21 ( V_12 ) ) ;
if ( V_12 -> V_44 == V_46 ) {
F_17 ( V_41 L_5 ) ;
for ( V_40 = 0 ; V_40 < V_23 ; V_40 ++ )
F_17 ( L_6 , V_12 -> V_20 [ V_40 ] ) ;
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
if ( V_2 -> V_55 ) {
struct V_56 * V_57 ;
int V_58 ;
F_41 (q, hctx, i) {
F_42 ( & V_57 -> V_59 ) ;
F_42 ( & V_57 -> V_49 ) ;
}
} else {
F_42 ( & V_2 -> V_49 ) ;
}
}
inline void F_43 ( struct V_1 * V_2 )
{
if ( F_12 ( F_29 ( V_2 ) ) )
return;
V_2 -> V_60 ++ ;
V_2 -> V_61 ( V_2 ) ;
V_2 -> V_60 -- ;
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
F_46 ( V_52 , & V_2 -> V_49 , 0 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_48 ( V_2 -> V_50 , V_62 ) ;
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_50 , V_62 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_63 ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_64 )
__releases( V_2 -> V_50 )
__acquires( V_2 -> V_50 )
{
int V_58 ;
F_53 ( V_2 -> V_50 ) ;
while ( true ) {
bool V_65 = false ;
if ( V_2 -> V_66 )
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( ! F_56 ( & V_2 -> V_67 ) && V_2 -> V_61 )
F_25 ( V_2 ) ;
V_65 |= V_2 -> V_68 ;
V_65 |= V_2 -> V_60 ;
if ( V_64 ) {
V_65 |= ! F_56 ( & V_2 -> V_67 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
V_65 |= V_2 -> V_69 [ V_58 ] ;
V_65 |= V_2 -> V_70 [ V_58 ] ;
V_65 |= ! F_56 ( & V_2 -> V_71 [ V_58 ] ) ;
}
}
if ( ! V_65 )
break;
F_26 ( V_2 -> V_50 ) ;
F_57 ( 10 ) ;
F_24 ( V_2 -> V_50 ) ;
}
if ( V_2 -> V_61 ) {
struct V_72 * V_73 ;
F_58 (rl, q)
for ( V_58 = 0 ; V_58 < F_59 ( V_73 -> V_74 ) ; V_58 ++ )
F_60 ( & V_73 -> V_74 [ V_58 ] ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
bool V_65 ;
F_24 ( V_2 -> V_50 ) ;
V_65 = ! V_2 -> V_75 ++ ;
F_38 ( V_76 , V_2 ) ;
F_26 ( V_2 -> V_50 ) ;
if ( V_65 ) {
F_24 ( V_2 -> V_50 ) ;
F_52 ( V_2 , false ) ;
F_26 ( V_2 -> V_50 ) ;
F_62 () ;
}
}
void F_63 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! -- V_2 -> V_75 )
F_35 ( V_76 , V_2 ) ;
F_64 ( V_2 -> V_75 < 0 ) ;
F_26 ( V_2 -> V_50 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
T_1 * V_77 = V_2 -> V_50 ;
F_66 ( & V_2 -> V_78 ) ;
F_67 ( V_79 , V_2 ) ;
F_24 ( V_77 ) ;
V_2 -> V_75 ++ ;
F_38 ( V_76 , V_2 ) ;
F_38 ( V_80 , V_2 ) ;
F_38 ( V_81 , V_2 ) ;
F_38 ( V_79 , V_2 ) ;
F_26 ( V_77 ) ;
F_68 ( & V_2 -> V_78 ) ;
if ( V_2 -> V_55 ) {
F_69 ( V_2 ) ;
F_24 ( V_77 ) ;
} else {
F_24 ( V_77 ) ;
F_52 ( V_2 , true ) ;
}
F_38 ( V_82 , V_2 ) ;
F_26 ( V_77 ) ;
F_40 ( & V_2 -> V_7 . V_83 ) ;
F_39 ( V_2 ) ;
F_24 ( V_77 ) ;
if ( V_2 -> V_50 != & V_2 -> V_84 )
V_2 -> V_50 = & V_2 -> V_84 ;
F_26 ( V_77 ) ;
F_50 ( V_2 ) ;
}
int F_70 ( struct V_72 * V_73 , struct V_1 * V_2 ,
T_2 V_85 )
{
if ( F_12 ( V_73 -> V_86 ) )
return 0 ;
V_73 -> V_2 = V_2 ;
V_73 -> V_87 [ V_88 ] = V_73 -> V_87 [ V_89 ] = 0 ;
V_73 -> V_90 [ V_88 ] = V_73 -> V_90 [ V_89 ] = 0 ;
F_71 ( & V_73 -> V_74 [ V_88 ] ) ;
F_71 ( & V_73 -> V_74 [ V_89 ] ) ;
V_73 -> V_86 = F_72 ( V_91 , V_92 ,
V_93 , V_94 ,
V_85 , V_2 -> V_95 ) ;
if ( ! V_73 -> V_86 )
return - V_96 ;
return 0 ;
}
void F_73 ( struct V_72 * V_73 )
{
if ( V_73 -> V_86 )
F_74 ( V_73 -> V_86 ) ;
}
struct V_1 * F_75 ( T_2 V_85 )
{
return F_76 ( V_85 , V_97 ) ;
}
struct V_1 * F_76 ( T_2 V_85 , int V_98 )
{
struct V_1 * V_2 ;
int V_99 ;
V_2 = F_77 ( V_100 ,
V_85 | V_101 , V_98 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_102 = F_78 ( & V_103 , 0 , 0 , V_85 ) ;
if ( V_2 -> V_102 < 0 )
goto V_104;
V_2 -> V_7 . V_105 =
( V_106 * 1024 ) / V_107 ;
V_2 -> V_7 . V_108 = 0 ;
V_2 -> V_7 . V_109 = V_110 ;
V_2 -> V_7 . V_111 = L_8 ;
V_2 -> V_95 = V_98 ;
V_99 = F_79 ( & V_2 -> V_7 ) ;
if ( V_99 )
goto V_112;
F_80 ( & V_2 -> V_7 . V_83 ,
V_113 , ( unsigned long ) V_2 ) ;
F_80 ( & V_2 -> V_54 , V_114 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_67 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_115 ) ;
#ifdef F_81
F_5 ( & V_2 -> V_116 ) ;
#endif
F_5 ( & V_2 -> V_71 [ 0 ] ) ;
F_5 ( & V_2 -> V_71 [ 1 ] ) ;
F_5 ( & V_2 -> V_117 ) ;
F_82 ( & V_2 -> V_49 , F_22 ) ;
F_83 ( & V_2 -> V_63 , & V_118 ) ;
F_84 ( & V_2 -> V_78 ) ;
F_85 ( & V_2 -> V_84 ) ;
V_2 -> V_50 = & V_2 -> V_84 ;
V_2 -> V_75 = 1 ;
F_86 ( V_76 , & V_2 -> V_119 ) ;
F_71 ( & V_2 -> V_120 ) ;
if ( F_87 ( V_2 ) )
goto V_121;
return V_2 ;
V_121:
F_88 ( & V_2 -> V_7 ) ;
V_112:
F_89 ( & V_103 , V_2 -> V_102 ) ;
V_104:
F_90 ( V_100 , V_2 ) ;
return NULL ;
}
struct V_1 * F_91 ( T_3 * V_122 , T_1 * V_77 )
{
return F_92 ( V_122 , V_77 , V_97 ) ;
}
struct V_1 *
F_92 ( T_3 * V_122 , T_1 * V_77 , int V_98 )
{
struct V_1 * V_123 , * V_2 ;
V_123 = F_76 ( V_124 , V_98 ) ;
if ( ! V_123 )
return NULL ;
V_2 = F_93 ( V_123 , V_122 , V_77 ) ;
if ( ! V_2 )
F_65 ( V_123 ) ;
return V_2 ;
}
struct V_1 *
F_93 ( struct V_1 * V_2 , T_3 * V_122 ,
T_1 * V_77 )
{
if ( ! V_2 )
return NULL ;
V_2 -> V_125 = F_94 ( sizeof( struct V_11 ) , V_124 ) ;
if ( ! V_2 -> V_125 )
return NULL ;
if ( F_70 ( & V_2 -> V_126 , V_2 , V_124 ) )
goto V_127;
V_2 -> V_61 = V_122 ;
V_2 -> V_128 = NULL ;
V_2 -> V_129 = NULL ;
V_2 -> V_119 |= V_130 ;
if ( V_77 )
V_2 -> V_50 = V_77 ;
F_95 ( V_2 , V_131 ) ;
V_2 -> V_132 = V_133 ;
F_66 ( & V_2 -> V_78 ) ;
if ( F_96 ( V_2 , NULL ) ) {
F_68 ( & V_2 -> V_78 ) ;
goto V_127;
}
F_68 ( & V_2 -> V_78 ) ;
return V_2 ;
V_127:
F_97 ( V_2 -> V_125 ) ;
return NULL ;
}
bool F_98 ( struct V_1 * V_2 )
{
if ( F_28 ( ! F_99 ( V_2 ) ) ) {
F_100 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_101 ( struct V_72 * V_73 , struct V_11 * V_12 )
{
if ( V_12 -> V_33 & V_134 ) {
F_102 ( V_73 -> V_2 , V_12 ) ;
if ( V_12 -> V_135 . V_136 )
F_103 ( V_12 -> V_135 . V_136 -> V_137 ) ;
}
F_104 ( V_12 , V_73 -> V_86 ) ;
}
static inline int F_105 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
if ( ! V_137 )
return 0 ;
return V_137 -> V_139 == V_2 -> V_140 ||
( V_137 -> V_139 > 0
&& F_106 ( V_26 , V_137 -> V_141 + V_142 ) ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
if ( ! V_137 || F_105 ( V_2 , V_137 ) )
return;
V_137 -> V_139 = V_2 -> V_140 ;
V_137 -> V_141 = V_26 ;
}
static void F_108 ( struct V_72 * V_73 , int V_143 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
if ( V_73 == & V_2 -> V_126 &&
V_73 -> V_87 [ V_143 ] < F_109 ( V_2 ) )
F_110 ( V_2 , V_143 ) ;
if ( V_73 -> V_87 [ V_143 ] + 1 <= V_2 -> V_4 ) {
if ( F_111 ( & V_73 -> V_74 [ V_143 ] ) )
F_112 ( & V_73 -> V_74 [ V_143 ] ) ;
F_113 ( V_73 , V_143 ) ;
}
}
static void F_114 ( struct V_72 * V_73 , unsigned int V_62 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
int V_143 = F_115 ( V_62 ) ;
V_2 -> V_69 [ V_143 ] -- ;
V_73 -> V_87 [ V_143 ] -- ;
if ( V_62 & V_134 )
V_2 -> V_68 -- ;
F_108 ( V_73 , V_143 ) ;
if ( F_12 ( V_73 -> V_90 [ V_143 ^ 1 ] ) )
F_108 ( V_73 , V_143 ^ 1 ) ;
}
int F_116 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_72 * V_73 ;
F_24 ( V_2 -> V_50 ) ;
V_2 -> V_4 = V_3 ;
F_1 ( V_2 ) ;
V_73 = & V_2 -> V_126 ;
if ( V_73 -> V_87 [ V_88 ] >= F_117 ( V_2 ) )
F_118 ( V_2 , V_88 ) ;
else if ( V_73 -> V_87 [ V_88 ] < F_109 ( V_2 ) )
F_110 ( V_2 , V_88 ) ;
if ( V_73 -> V_87 [ V_89 ] >= F_117 ( V_2 ) )
F_118 ( V_2 , V_89 ) ;
else if ( V_73 -> V_87 [ V_89 ] < F_109 ( V_2 ) )
F_110 ( V_2 , V_89 ) ;
F_58 (rl, q) {
if ( V_73 -> V_87 [ V_88 ] >= V_2 -> V_4 ) {
F_119 ( V_73 , V_88 ) ;
} else {
F_113 ( V_73 , V_88 ) ;
F_112 ( & V_73 -> V_74 [ V_88 ] ) ;
}
if ( V_73 -> V_87 [ V_89 ] >= V_2 -> V_4 ) {
F_119 ( V_73 , V_89 ) ;
} else {
F_113 ( V_73 , V_89 ) ;
F_112 ( & V_73 -> V_74 [ V_89 ] ) ;
}
}
F_26 ( V_2 -> V_50 ) ;
return 0 ;
}
static bool F_120 ( struct V_28 * V_28 )
{
if ( ! V_28 )
return true ;
if ( V_28 -> V_144 & ( V_145 | V_146 ) )
return false ;
return true ;
}
static struct V_138 * F_121 ( struct V_28 * V_28 )
{
#ifdef F_81
if ( V_28 && V_28 -> V_147 )
return V_28 -> V_147 ;
#endif
return V_148 -> V_138 ;
}
static struct V_11 * F_122 ( struct V_72 * V_73 , int V_149 ,
struct V_28 * V_28 , T_2 V_85 )
{
struct V_1 * V_2 = V_73 -> V_2 ;
struct V_11 * V_12 ;
struct V_150 * V_151 = V_2 -> V_66 -> type ;
struct V_138 * V_137 = F_121 ( V_28 ) ;
struct V_152 * V_136 = NULL ;
const bool V_153 = F_115 ( V_149 ) != 0 ;
int V_154 ;
if ( F_12 ( F_99 ( V_2 ) ) )
return NULL ;
V_154 = F_123 ( V_2 , V_149 ) ;
if ( V_154 == V_155 )
goto V_156;
if ( V_73 -> V_87 [ V_153 ] + 1 >= F_117 ( V_2 ) ) {
if ( V_73 -> V_87 [ V_153 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_124 ( V_73 , V_153 ) ) {
F_107 ( V_2 , V_137 ) ;
F_119 ( V_73 , V_153 ) ;
} else {
if ( V_154 != V_157
&& ! F_105 ( V_2 , V_137 ) ) {
return NULL ;
}
}
}
if ( V_73 == & V_2 -> V_126 )
F_118 ( V_2 , V_153 ) ;
}
if ( V_73 -> V_87 [ V_153 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return NULL ;
V_2 -> V_69 [ V_153 ] ++ ;
V_73 -> V_87 [ V_153 ] ++ ;
V_73 -> V_90 [ V_153 ] = 0 ;
if ( F_120 ( V_28 ) && ! F_125 ( V_2 ) ) {
V_149 |= V_134 ;
V_2 -> V_68 ++ ;
if ( V_151 -> V_158 && V_137 )
V_136 = F_126 ( V_137 , V_2 ) ;
}
if ( F_127 ( V_2 ) )
V_149 |= V_159 ;
F_26 ( V_2 -> V_50 ) ;
V_12 = F_128 ( V_73 -> V_86 , V_85 ) ;
if ( ! V_12 )
goto V_160;
F_4 ( V_2 , V_12 ) ;
F_129 ( V_12 , V_73 ) ;
V_12 -> V_33 = V_149 | V_161 ;
if ( V_149 & V_134 ) {
if ( F_12 ( V_151 -> V_158 && ! V_136 ) ) {
if ( V_137 )
V_136 = F_130 ( V_137 , V_2 , V_85 ) ;
if ( ! V_136 )
goto V_162;
}
V_12 -> V_135 . V_136 = V_136 ;
if ( F_12 ( F_131 ( V_2 , V_12 , V_28 , V_85 ) ) )
goto V_162;
if ( V_136 )
F_132 ( V_136 -> V_137 ) ;
}
V_163:
if ( F_105 ( V_2 , V_137 ) )
V_137 -> V_139 -- ;
F_133 ( V_2 , V_28 , V_149 & 1 ) ;
return V_12 ;
V_162:
F_134 ( V_164 L_9 ,
F_135 ( V_2 -> V_7 . V_165 ) ) ;
V_12 -> V_33 &= ~ V_134 ;
V_12 -> V_135 . V_136 = NULL ;
F_24 ( V_2 -> V_50 ) ;
V_2 -> V_68 -- ;
F_26 ( V_2 -> V_50 ) ;
goto V_163;
V_160:
F_24 ( V_2 -> V_50 ) ;
F_114 ( V_73 , V_149 ) ;
V_156:
if ( F_12 ( V_73 -> V_87 [ V_153 ] == 0 ) )
V_73 -> V_90 [ V_153 ] = 1 ;
return NULL ;
}
static struct V_11 * F_136 ( struct V_1 * V_2 , int V_149 ,
struct V_28 * V_28 , T_2 V_85 )
{
const bool V_153 = F_115 ( V_149 ) != 0 ;
F_137 ( V_74 ) ;
struct V_72 * V_73 ;
struct V_11 * V_12 ;
V_73 = F_138 ( V_2 , V_28 ) ;
V_166:
V_12 = F_122 ( V_73 , V_149 , V_28 , V_85 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_85 & V_167 ) || F_12 ( F_99 ( V_2 ) ) ) {
F_139 ( V_73 ) ;
return NULL ;
}
F_140 ( & V_73 -> V_74 [ V_153 ] , & V_74 ,
V_168 ) ;
F_141 ( V_2 , V_28 , V_149 & 1 ) ;
F_26 ( V_2 -> V_50 ) ;
F_142 () ;
F_107 ( V_2 , V_148 -> V_138 ) ;
F_24 ( V_2 -> V_50 ) ;
F_143 ( & V_73 -> V_74 [ V_153 ] , & V_74 ) ;
goto V_166;
}
static struct V_11 * F_144 ( struct V_1 * V_2 , int V_169 ,
T_2 V_85 )
{
struct V_11 * V_12 ;
F_145 ( V_169 != V_170 && V_169 != V_171 ) ;
F_146 ( V_85 , V_2 -> V_95 ) ;
F_24 ( V_2 -> V_50 ) ;
V_12 = F_136 ( V_2 , V_169 , NULL , V_85 ) ;
if ( ! V_12 )
F_26 ( V_2 -> V_50 ) ;
return V_12 ;
}
struct V_11 * F_147 ( struct V_1 * V_2 , int V_169 , T_2 V_85 )
{
if ( V_2 -> V_55 )
return F_148 ( V_2 , V_169 , V_85 , false ) ;
else
return F_144 ( V_2 , V_169 , V_85 ) ;
}
struct V_11 * F_149 ( struct V_1 * V_2 , struct V_28 * V_28 ,
T_2 V_85 )
{
struct V_11 * V_12 = F_147 ( V_2 , F_150 ( V_28 ) , V_85 ) ;
if ( F_12 ( ! V_12 ) )
return F_151 ( - V_96 ) ;
F_152 ( V_12 ) ;
F_153 (bio) {
struct V_28 * V_172 = V_28 ;
int V_10 ;
F_154 ( V_2 , & V_172 ) ;
V_10 = F_155 ( V_2 , V_12 , V_172 ) ;
if ( F_12 ( V_10 ) ) {
F_156 ( V_12 ) ;
return F_151 ( V_10 ) ;
}
}
return V_12 ;
}
void F_152 ( struct V_11 * V_12 )
{
V_12 -> V_44 = V_46 ;
V_12 -> V_173 = 0 ;
V_12 -> V_16 = ( V_17 ) - 1 ;
V_12 -> V_28 = V_12 -> V_45 = NULL ;
memset ( V_12 -> V_21 , 0 , sizeof( V_12 -> V_21 ) ) ;
V_12 -> V_20 = V_12 -> V_21 ;
}
void F_157 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_158 ( V_12 ) ;
F_159 ( V_12 ) ;
F_160 ( V_2 , V_12 ) ;
if ( F_161 ( V_12 ) )
F_162 ( V_2 , V_12 ) ;
F_145 ( F_163 ( V_12 ) ) ;
F_164 ( V_2 , V_12 ) ;
}
static void F_165 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_174 )
{
F_166 ( V_12 , true ) ;
F_167 ( V_2 , V_12 , V_174 ) ;
}
static void F_168 ( int V_15 , struct V_175 * V_27 ,
unsigned long V_176 )
{
int V_177 ;
if ( V_176 == V_27 -> V_178 )
return;
V_177 = F_169 ( V_27 ) ;
if ( V_177 ) {
F_170 ( V_15 , V_27 , V_179 ,
V_177 * ( V_176 - V_27 -> V_178 ) ) ;
F_170 ( V_15 , V_27 , V_180 , ( V_176 - V_27 -> V_178 ) ) ;
}
V_27 -> V_178 = V_176 ;
}
void F_171 ( int V_15 , struct V_175 * V_27 )
{
unsigned long V_176 = V_26 ;
if ( V_27 -> V_181 )
F_168 ( V_15 , & F_172 ( V_27 ) -> V_182 , V_176 ) ;
F_168 ( V_15 , V_27 , V_176 ) ;
}
static void F_173 ( struct V_11 * V_12 )
{
if ( V_12 -> V_2 -> V_165 && ! ( V_12 -> V_33 & V_183 ) && ! -- V_12 -> V_2 -> V_184 )
F_174 ( V_12 -> V_2 -> V_165 ) ;
}
static inline void F_173 ( struct V_11 * V_12 ) {}
void F_175 ( struct V_1 * V_2 , struct V_11 * V_185 )
{
if ( F_12 ( ! V_2 ) )
return;
if ( V_2 -> V_55 ) {
F_176 ( V_185 ) ;
return;
}
F_173 ( V_185 ) ;
F_177 ( V_2 , V_185 ) ;
F_33 ( V_185 -> V_28 != NULL ) ;
if ( V_185 -> V_33 & V_161 ) {
unsigned int V_62 = V_185 -> V_33 ;
struct V_72 * V_73 = F_178 ( V_185 ) ;
F_145 ( ! F_56 ( & V_185 -> V_13 ) ) ;
F_145 ( F_179 ( V_185 ) ) ;
F_101 ( V_73 , V_185 ) ;
F_114 ( V_73 , V_62 ) ;
F_139 ( V_73 ) ;
}
}
void F_156 ( struct V_11 * V_185 )
{
struct V_1 * V_2 = V_185 -> V_2 ;
if ( V_2 -> V_55 )
F_176 ( V_185 ) ;
else {
unsigned long V_62 ;
F_48 ( V_2 -> V_50 , V_62 ) ;
F_175 ( V_2 , V_185 ) ;
F_49 ( V_2 -> V_50 , V_62 ) ;
}
}
void F_180 ( struct V_11 * V_12 , struct V_186 * V_186 ,
unsigned int V_187 )
{
struct V_28 * V_28 = V_12 -> V_28 ;
V_28 -> V_188 -> V_189 = V_186 ;
V_28 -> V_188 -> V_190 = 0 ;
V_28 -> V_188 -> V_191 = V_187 ;
V_28 -> V_36 . V_37 = V_187 ;
V_28 -> V_192 = 1 ;
V_28 -> V_193 = 1 ;
V_12 -> V_173 = V_12 -> V_194 = V_187 ;
V_12 -> V_195 = 1 ;
}
bool F_181 ( struct V_1 * V_2 , struct V_11 * V_185 ,
struct V_28 * V_28 )
{
const int V_196 = V_28 -> V_144 & V_197 ;
if ( ! F_182 ( V_2 , V_185 , V_28 ) )
return false ;
F_183 ( V_2 , V_185 , V_28 ) ;
if ( ( V_185 -> V_33 & V_197 ) != V_196 )
F_184 ( V_185 ) ;
V_185 -> V_45 -> V_198 = V_28 ;
V_185 -> V_45 = V_28 ;
V_185 -> V_173 += V_28 -> V_36 . V_37 ;
V_185 -> V_199 = F_185 ( V_185 -> V_199 , F_186 ( V_28 ) ) ;
F_166 ( V_185 , false ) ;
return true ;
}
bool F_187 ( struct V_1 * V_2 , struct V_11 * V_185 ,
struct V_28 * V_28 )
{
const int V_196 = V_28 -> V_144 & V_197 ;
if ( ! F_188 ( V_2 , V_185 , V_28 ) )
return false ;
F_189 ( V_2 , V_185 , V_28 ) ;
if ( ( V_185 -> V_33 & V_197 ) != V_196 )
F_184 ( V_185 ) ;
V_28 -> V_198 = V_185 -> V_28 ;
V_185 -> V_28 = V_28 ;
V_185 -> V_16 = V_28 -> V_36 . V_200 ;
V_185 -> V_173 += V_28 -> V_36 . V_37 ;
V_185 -> V_199 = F_185 ( V_185 -> V_199 , F_186 ( V_28 ) ) ;
F_166 ( V_185 , false ) ;
return true ;
}
bool F_190 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned int * V_201 )
{
struct V_202 * V_203 ;
struct V_11 * V_12 ;
bool V_10 = false ;
struct V_204 * V_205 ;
V_203 = V_148 -> V_203 ;
if ( ! V_203 )
goto V_163;
* V_201 = 0 ;
if ( V_2 -> V_55 )
V_205 = & V_203 -> V_206 ;
else
V_205 = & V_203 -> V_207 ;
F_191 (rq, plug_list, queuelist) {
int V_208 ;
if ( V_12 -> V_2 == V_2 )
( * V_201 ) ++ ;
if ( V_12 -> V_2 != V_2 || ! F_192 ( V_12 , V_28 ) )
continue;
V_208 = F_193 ( V_12 , V_28 ) ;
if ( V_208 == V_209 ) {
V_10 = F_181 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
} else if ( V_208 == V_210 ) {
V_10 = F_187 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
}
}
V_163:
return V_10 ;
}
void F_194 ( struct V_11 * V_185 , struct V_28 * V_28 )
{
V_185 -> V_44 = V_211 ;
V_185 -> V_33 |= V_28 -> V_144 & V_212 ;
if ( V_28 -> V_144 & V_213 )
V_185 -> V_33 |= V_197 ;
V_185 -> V_214 = 0 ;
V_185 -> V_16 = V_28 -> V_36 . V_200 ;
V_185 -> V_199 = F_186 ( V_28 ) ;
F_195 ( V_185 -> V_2 , V_185 , V_28 ) ;
}
void V_131 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
const bool V_143 = ! ! ( V_28 -> V_144 & V_215 ) ;
struct V_202 * V_203 ;
int V_208 , V_149 , V_174 = V_216 ;
struct V_11 * V_185 ;
unsigned int V_201 = 0 ;
F_154 ( V_2 , & V_28 ) ;
if ( F_196 ( V_28 ) && F_197 ( V_28 ) ) {
F_15 ( V_28 , - V_32 ) ;
return;
}
if ( V_28 -> V_144 & ( V_145 | V_146 ) ) {
F_24 ( V_2 -> V_50 ) ;
V_174 = V_217 ;
goto V_218;
}
if ( ! F_198 ( V_2 ) &&
F_190 ( V_2 , V_28 , & V_201 ) )
return;
F_24 ( V_2 -> V_50 ) ;
V_208 = F_199 ( V_2 , & V_185 , V_28 ) ;
if ( V_208 == V_209 ) {
if ( F_181 ( V_2 , V_185 , V_28 ) ) {
F_200 ( V_2 , V_185 , V_28 ) ;
if ( ! F_201 ( V_2 , V_185 ) )
F_202 ( V_2 , V_185 , V_208 ) ;
goto V_219;
}
} else if ( V_208 == V_210 ) {
if ( F_187 ( V_2 , V_185 , V_28 ) ) {
F_200 ( V_2 , V_185 , V_28 ) ;
if ( ! F_203 ( V_2 , V_185 ) )
F_202 ( V_2 , V_185 , V_208 ) ;
goto V_219;
}
}
V_218:
V_149 = F_150 ( V_28 ) ;
if ( V_143 )
V_149 |= V_215 ;
V_185 = F_136 ( V_2 , V_149 , V_28 , V_220 ) ;
if ( F_12 ( ! V_185 ) ) {
F_15 ( V_28 , - V_221 ) ;
goto V_219;
}
F_194 ( V_185 , V_28 ) ;
if ( F_11 ( V_222 , & V_2 -> V_119 ) )
V_185 -> V_15 = F_204 () ;
V_203 = V_148 -> V_203 ;
if ( V_203 ) {
if ( ! V_201 )
F_205 ( V_2 ) ;
else {
if ( V_201 >= V_223 ) {
F_206 ( V_203 , false ) ;
F_205 ( V_2 ) ;
}
}
F_207 ( & V_185 -> V_13 , & V_203 -> V_207 ) ;
F_166 ( V_185 , true ) ;
} else {
F_24 ( V_2 -> V_50 ) ;
F_165 ( V_2 , V_185 , V_174 ) ;
F_25 ( V_2 ) ;
V_219:
F_26 ( V_2 -> V_50 ) ;
}
}
static inline void F_208 ( struct V_28 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_224 ;
if ( F_209 ( V_28 ) && V_9 != V_9 -> V_225 ) {
struct V_175 * V_226 = V_9 -> V_227 ;
V_28 -> V_36 . V_200 += V_226 -> V_228 ;
V_28 -> V_224 = V_9 -> V_225 ;
F_210 ( F_3 ( V_28 -> V_224 ) , V_28 ,
V_9 -> V_229 ,
V_28 -> V_36 . V_200 - V_226 -> V_228 ) ;
}
}
static void F_211 ( struct V_28 * V_28 )
{
char V_230 [ V_231 ] ;
F_17 ( V_41 L_10 ) ;
F_17 ( V_41 L_11 ,
F_212 ( V_28 -> V_224 , V_230 ) ,
V_28 -> V_144 ,
( unsigned long long ) F_213 ( V_28 ) ,
( long long ) ( F_214 ( V_28 -> V_224 -> V_232 ) >> 9 ) ) ;
F_13 ( V_233 , & V_28 -> V_31 ) ;
}
static int T_4 F_215 ( char * V_234 )
{
return F_216 ( & V_235 , V_234 ) ;
}
static bool F_217 ( struct V_175 * V_27 , unsigned int V_236 )
{
return V_27 -> V_237 && F_218 ( & V_235 , V_236 ) ;
}
static int T_4 F_219 ( void )
{
struct V_238 * V_239 = F_220 ( L_12 ,
NULL , & V_235 ) ;
return F_221 ( V_239 ) ;
}
static inline bool F_217 ( struct V_175 * V_27 ,
unsigned int V_236 )
{
return false ;
}
static inline int F_222 ( struct V_28 * V_28 , unsigned int V_240 )
{
V_17 V_241 ;
if ( ! V_240 )
return 0 ;
V_241 = F_214 ( V_28 -> V_224 -> V_232 ) >> 9 ;
if ( V_241 ) {
V_17 V_242 = V_28 -> V_36 . V_200 ;
if ( V_241 < V_240 || V_241 - V_240 < V_242 ) {
F_211 ( V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_223 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
int V_240 = F_209 ( V_28 ) ;
int V_99 = - V_32 ;
char V_230 [ V_231 ] ;
struct V_175 * V_27 ;
F_224 () ;
if ( F_222 ( V_28 , V_240 ) )
goto V_243;
V_2 = F_3 ( V_28 -> V_224 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_244
L_13
L_14 ,
F_212 ( V_28 -> V_224 , V_230 ) ,
( long long ) V_28 -> V_36 . V_200 ) ;
goto V_243;
}
if ( F_28 ( F_225 ( V_28 ) &&
V_240 > F_226 ( V_2 ) ) ) {
F_17 ( V_244 L_15 ,
F_212 ( V_28 -> V_224 , V_230 ) ,
F_209 ( V_28 ) ,
F_226 ( V_2 ) ) ;
goto V_243;
}
V_27 = V_28 -> V_224 -> V_227 ;
if ( F_217 ( V_27 , V_28 -> V_36 . V_37 ) ||
F_217 ( & F_172 ( V_27 ) -> V_182 ,
V_28 -> V_36 . V_37 ) )
goto V_243;
F_208 ( V_28 ) ;
if ( F_222 ( V_28 , V_240 ) )
goto V_243;
if ( ( V_28 -> V_144 & ( V_145 | V_146 ) ) && ! V_2 -> V_245 ) {
V_28 -> V_144 &= ~ ( V_145 | V_146 ) ;
if ( ! V_240 ) {
V_99 = 0 ;
goto V_243;
}
}
if ( ( V_28 -> V_144 & V_246 ) &&
( ! F_227 ( V_2 ) ||
( ( V_28 -> V_144 & V_247 ) && ! F_228 ( V_2 ) ) ) ) {
V_99 = - V_248 ;
goto V_243;
}
if ( V_28 -> V_144 & V_249 && ! F_229 ( V_28 -> V_224 ) ) {
V_99 = - V_248 ;
goto V_243;
}
F_146 ( V_250 , V_2 -> V_95 ) ;
if ( F_230 ( V_2 , V_28 ) )
return false ;
F_231 ( V_2 , V_28 ) ;
return true ;
V_243:
F_15 ( V_28 , V_99 ) ;
return false ;
}
void F_232 ( struct V_28 * V_28 )
{
struct V_251 V_252 ;
if ( ! F_223 ( V_28 ) )
return;
if ( V_148 -> V_251 ) {
F_233 ( V_148 -> V_251 , V_28 ) ;
return;
}
F_145 ( V_28 -> V_198 ) ;
F_234 ( & V_252 ) ;
V_148 -> V_251 = & V_252 ;
do {
struct V_1 * V_2 = F_3 ( V_28 -> V_224 ) ;
V_2 -> V_253 ( V_2 , V_28 ) ;
V_28 = F_235 ( V_148 -> V_251 ) ;
} while ( V_28 );
V_148 -> V_251 = NULL ;
}
void F_236 ( int V_169 , struct V_28 * V_28 )
{
V_28 -> V_144 |= V_169 ;
if ( F_237 ( V_28 ) ) {
unsigned int V_87 ;
if ( F_12 ( V_169 & V_249 ) )
V_87 = F_238 ( V_28 -> V_224 ) >> 9 ;
else
V_87 = F_209 ( V_28 ) ;
if ( V_169 & V_171 ) {
F_239 ( V_254 , V_87 ) ;
} else {
F_240 ( V_28 -> V_36 . V_37 ) ;
F_239 ( V_255 , V_87 ) ;
}
if ( F_12 ( V_256 ) ) {
char V_230 [ V_231 ] ;
F_17 ( V_257 L_16 ,
V_148 -> V_258 , F_241 ( V_148 ) ,
( V_169 & V_171 ) ? L_17 : L_18 ,
( unsigned long long ) V_28 -> V_36 . V_200 ,
F_212 ( V_28 -> V_224 , V_230 ) ,
V_87 ) ;
}
}
F_232 ( V_28 ) ;
}
int F_242 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_243 ( V_12 ) )
return 0 ;
if ( F_19 ( V_12 ) > F_244 ( V_2 , V_12 -> V_33 ) ) {
F_17 ( V_244 L_19 , V_259 ) ;
return - V_32 ;
}
F_245 ( V_12 ) ;
if ( V_12 -> V_195 > F_246 ( V_2 ) ) {
F_17 ( V_244 L_20 , V_259 ) ;
return - V_32 ;
}
return 0 ;
}
int F_247 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned long V_62 ;
int V_174 = V_260 ;
if ( F_242 ( V_2 , V_12 ) )
return - V_32 ;
if ( V_12 -> V_42 &&
F_217 ( & V_12 -> V_42 -> V_182 , F_21 ( V_12 ) ) )
return - V_32 ;
F_48 ( V_2 -> V_50 , V_62 ) ;
if ( F_12 ( F_99 ( V_2 ) ) ) {
F_49 ( V_2 -> V_50 , V_62 ) ;
return - V_221 ;
}
F_145 ( F_163 ( V_12 ) ) ;
if ( V_12 -> V_33 & ( V_145 | V_146 ) )
V_174 = V_217 ;
F_165 ( V_2 , V_12 , V_174 ) ;
if ( V_174 == V_217 )
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_50 , V_62 ) ;
return 0 ;
}
unsigned int F_248 ( const struct V_11 * V_12 )
{
unsigned int V_196 = V_12 -> V_33 & V_197 ;
unsigned int V_236 = 0 ;
struct V_28 * V_28 ;
if ( ! ( V_12 -> V_33 & V_261 ) )
return F_21 ( V_12 ) ;
for ( V_28 = V_12 -> V_28 ; V_28 ; V_28 = V_28 -> V_198 ) {
if ( ( V_28 -> V_144 & V_196 ) != V_196 )
break;
V_236 += V_28 -> V_36 . V_37 ;
}
F_145 ( F_21 ( V_12 ) && ! V_236 ) ;
return V_236 ;
}
void F_249 ( struct V_11 * V_185 , unsigned int V_236 )
{
if ( F_250 ( V_185 ) ) {
const int V_169 = F_251 ( V_185 ) ;
struct V_175 * V_27 ;
int V_15 ;
V_15 = F_252 () ;
V_27 = V_185 -> V_27 ;
F_253 ( V_15 , V_27 , V_262 [ V_169 ] , V_236 >> 9 ) ;
F_254 () ;
}
}
void F_255 ( struct V_11 * V_185 )
{
if ( F_250 ( V_185 ) && ! ( V_185 -> V_33 & V_38 ) ) {
unsigned long V_263 = V_26 - V_185 -> V_25 ;
const int V_169 = F_251 ( V_185 ) ;
struct V_175 * V_27 ;
int V_15 ;
V_15 = F_252 () ;
V_27 = V_185 -> V_27 ;
F_256 ( V_15 , V_27 , V_264 [ V_169 ] ) ;
F_253 ( V_15 , V_27 , V_265 [ V_169 ] , V_263 ) ;
F_171 ( V_15 , V_27 ) ;
F_257 ( V_27 , V_169 ) ;
F_258 ( V_27 ) ;
F_254 () ;
}
}
static struct V_11 * F_259 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( V_2 -> V_165 && ( V_2 -> V_266 == V_267 ||
( V_2 -> V_266 != V_268 && ! ( V_12 -> V_33 & V_183 ) ) ) )
return NULL ;
else
return V_12 ;
}
static inline struct V_11 * F_259 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return V_12 ;
}
void F_166 ( struct V_11 * V_12 , bool V_269 )
{
struct V_175 * V_27 ;
int V_169 = F_251 ( V_12 ) ;
int V_15 ;
if ( ! F_250 ( V_12 ) )
return;
V_15 = F_252 () ;
if ( ! V_269 ) {
V_27 = V_12 -> V_27 ;
F_256 ( V_15 , V_27 , V_270 [ V_169 ] ) ;
} else {
V_27 = F_260 ( V_12 -> V_42 , F_18 ( V_12 ) ) ;
if ( ! F_261 ( V_27 ) ) {
V_27 = & V_12 -> V_42 -> V_182 ;
F_262 ( V_27 ) ;
}
F_171 ( V_15 , V_27 ) ;
F_263 ( V_27 , V_169 ) ;
V_12 -> V_27 = V_27 ;
}
F_254 () ;
}
struct V_11 * F_264 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_10 ;
while ( ( V_12 = F_265 ( V_2 ) ) != NULL ) {
V_12 = F_259 ( V_2 , V_12 ) ;
if ( ! V_12 )
break;
if ( ! ( V_12 -> V_33 & V_271 ) ) {
if ( V_12 -> V_33 & V_272 )
F_266 ( V_2 , V_12 ) ;
V_12 -> V_33 |= V_271 ;
F_267 ( V_2 , V_12 ) ;
}
if ( ! V_2 -> V_273 || V_2 -> V_273 == V_12 ) {
V_2 -> V_274 = F_268 ( V_12 ) ;
V_2 -> V_273 = NULL ;
}
if ( V_12 -> V_33 & V_275 )
break;
if ( V_2 -> V_276 && F_21 ( V_12 ) ) {
V_12 -> V_195 ++ ;
}
if ( ! V_2 -> V_128 )
break;
V_10 = V_2 -> V_128 ( V_2 , V_12 ) ;
if ( V_10 == V_277 ) {
break;
} else if ( V_10 == V_278 ) {
if ( V_2 -> V_276 && F_21 ( V_12 ) &&
! ( V_12 -> V_33 & V_275 ) ) {
-- V_12 -> V_195 ;
}
V_12 = NULL ;
break;
} else if ( V_10 == V_279 ) {
V_12 -> V_33 |= V_34 ;
F_269 ( V_12 ) ;
F_270 ( V_12 , - V_32 ) ;
} else {
F_17 ( V_244 L_21 , V_259 , V_10 ) ;
break;
}
}
return V_12 ;
}
void F_271 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_145 ( F_56 ( & V_12 -> V_13 ) ) ;
F_145 ( F_179 ( V_12 ) ) ;
F_272 ( & V_12 -> V_13 ) ;
if ( F_273 ( V_12 ) ) {
V_2 -> V_70 [ F_274 ( V_12 ) ] ++ ;
F_275 ( V_12 ) ;
}
}
void F_269 ( struct V_11 * V_185 )
{
F_271 ( V_185 ) ;
V_185 -> V_194 = F_21 ( V_185 ) ;
if ( F_12 ( F_276 ( V_185 ) ) )
V_185 -> V_280 -> V_194 = F_21 ( V_185 -> V_280 ) ;
F_145 ( F_11 ( V_281 , & V_185 -> V_282 ) ) ;
F_277 ( V_185 ) ;
}
struct V_11 * F_278 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_264 ( V_2 ) ;
if ( V_12 )
F_269 ( V_12 ) ;
return V_12 ;
}
bool F_279 ( struct V_11 * V_185 , int error , unsigned int V_283 )
{
int V_284 ;
if ( ! V_185 -> V_28 )
return false ;
F_280 ( V_185 -> V_2 , V_185 , V_283 ) ;
if ( V_185 -> V_44 == V_211 )
V_185 -> V_214 = 0 ;
if ( error && V_185 -> V_44 == V_211 &&
! ( V_185 -> V_33 & V_34 ) ) {
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
case - V_32 :
default:
V_285 = L_28 ;
break;
}
F_134 ( V_244 L_29 ,
V_285 , V_185 -> V_42 ?
V_185 -> V_42 -> V_43 : L_2 ,
( unsigned long long ) F_18 ( V_185 ) ) ;
}
F_249 ( V_185 , V_283 ) ;
V_284 = 0 ;
while ( V_185 -> V_28 ) {
struct V_28 * V_28 = V_185 -> V_28 ;
unsigned V_292 = F_281 ( V_28 -> V_36 . V_37 , V_283 ) ;
if ( V_292 == V_28 -> V_36 . V_37 )
V_185 -> V_28 = V_28 -> V_198 ;
F_9 ( V_185 , V_28 , V_292 , error ) ;
V_284 += V_292 ;
V_283 -= V_292 ;
if ( ! V_283 )
break;
}
if ( ! V_185 -> V_28 ) {
V_185 -> V_173 = 0 ;
return false ;
}
V_185 -> V_173 -= V_284 ;
if ( V_185 -> V_44 == V_211 )
V_185 -> V_16 += V_284 >> 9 ;
if ( V_185 -> V_33 & V_261 ) {
V_185 -> V_33 &= ~ V_197 ;
V_185 -> V_33 |= V_185 -> V_28 -> V_144 & V_197 ;
}
if ( F_21 ( V_185 ) < F_282 ( V_185 ) ) {
F_16 ( V_185 , L_30 ) ;
V_185 -> V_173 = F_282 ( V_185 ) ;
}
F_245 ( V_185 ) ;
return true ;
}
static bool F_283 ( struct V_11 * V_12 , int error ,
unsigned int V_283 ,
unsigned int V_293 )
{
if ( F_279 ( V_12 , error , V_283 ) )
return true ;
if ( F_12 ( F_276 ( V_12 ) ) &&
F_279 ( V_12 -> V_280 , error , V_293 ) )
return true ;
if ( F_284 ( V_12 -> V_2 ) )
F_285 ( V_12 -> V_42 ) ;
return false ;
}
void F_286 ( struct V_11 * V_185 )
{
struct V_1 * V_2 = V_185 -> V_2 ;
V_185 -> V_33 &= ~ V_275 ;
if ( V_2 -> V_129 )
V_2 -> V_129 ( V_2 , V_185 ) ;
}
void F_287 ( struct V_11 * V_185 , int error )
{
if ( F_161 ( V_185 ) )
F_162 ( V_185 -> V_2 , V_185 ) ;
F_145 ( F_163 ( V_185 ) ) ;
if ( F_12 ( V_294 ) && V_185 -> V_44 == V_211 )
F_288 ( & V_185 -> V_2 -> V_7 ) ;
F_158 ( V_185 ) ;
if ( V_185 -> V_33 & V_275 )
F_286 ( V_185 ) ;
F_255 ( V_185 ) ;
if ( V_185 -> V_243 )
V_185 -> V_243 ( V_185 , error ) ;
else {
if ( F_276 ( V_185 ) )
F_175 ( V_185 -> V_280 -> V_2 , V_185 -> V_280 ) ;
F_175 ( V_185 -> V_2 , V_185 ) ;
}
}
static bool F_289 ( struct V_11 * V_12 , int error ,
unsigned int V_283 , unsigned int V_293 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_62 ;
if ( F_283 ( V_12 , error , V_283 , V_293 ) )
return true ;
F_48 ( V_2 -> V_50 , V_62 ) ;
F_287 ( V_12 , error ) ;
F_49 ( V_2 -> V_50 , V_62 ) ;
return false ;
}
bool F_290 ( struct V_11 * V_12 , int error ,
unsigned int V_283 , unsigned int V_293 )
{
if ( F_283 ( V_12 , error , V_283 , V_293 ) )
return true ;
F_287 ( V_12 , error ) ;
return false ;
}
bool F_291 ( struct V_11 * V_12 , int error , unsigned int V_283 )
{
return F_289 ( V_12 , error , V_283 , 0 ) ;
}
void F_292 ( struct V_11 * V_12 , int error )
{
bool V_295 ;
unsigned int V_293 = 0 ;
if ( F_12 ( F_276 ( V_12 ) ) )
V_293 = F_21 ( V_12 -> V_280 ) ;
V_295 = F_289 ( V_12 , error , F_21 ( V_12 ) , V_293 ) ;
F_145 ( V_295 ) ;
}
bool F_293 ( struct V_11 * V_12 , int error )
{
return F_291 ( V_12 , error , F_282 ( V_12 ) ) ;
}
bool F_294 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_291 ( V_12 , error , F_248 ( V_12 ) ) ;
}
bool F_295 ( struct V_11 * V_12 , int error , unsigned int V_283 )
{
return F_290 ( V_12 , error , V_283 , 0 ) ;
}
void F_270 ( struct V_11 * V_12 , int error )
{
bool V_295 ;
unsigned int V_293 = 0 ;
if ( F_12 ( F_276 ( V_12 ) ) )
V_293 = F_21 ( V_12 -> V_280 ) ;
V_295 = F_290 ( V_12 , error , F_21 ( V_12 ) , V_293 ) ;
F_145 ( V_295 ) ;
}
bool F_296 ( struct V_11 * V_12 , int error )
{
return F_295 ( V_12 , error , F_282 ( V_12 ) ) ;
}
bool F_297 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_295 ( V_12 , error , F_248 ( V_12 ) ) ;
}
void F_195 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_28 * V_28 )
{
V_12 -> V_33 |= V_28 -> V_144 & V_296 ;
if ( F_237 ( V_28 ) )
V_12 -> V_195 = F_298 ( V_2 , V_28 ) ;
V_12 -> V_173 = V_28 -> V_36 . V_37 ;
V_12 -> V_28 = V_12 -> V_45 = V_28 ;
if ( V_28 -> V_224 )
V_12 -> V_42 = V_28 -> V_224 -> V_297 ;
}
void F_299 ( struct V_11 * V_12 )
{
struct V_298 V_299 ;
struct V_300 V_301 ;
F_300 (bvec, rq, iter)
F_301 ( V_301 . V_189 ) ;
}
int F_302 ( struct V_1 * V_2 )
{
if ( V_2 -> V_302 )
return V_2 -> V_302 ( V_2 ) ;
return 0 ;
}
void F_303 ( struct V_11 * V_12 )
{
struct V_28 * V_28 ;
while ( ( V_28 = V_12 -> V_28 ) != NULL ) {
V_12 -> V_28 = V_28 -> V_198 ;
F_304 ( V_28 ) ;
}
}
static void F_305 ( struct V_11 * V_303 , struct V_11 * V_304 )
{
V_303 -> V_15 = V_304 -> V_15 ;
V_303 -> V_33 = ( V_304 -> V_33 & V_305 ) | V_306 ;
V_303 -> V_44 = V_304 -> V_44 ;
V_303 -> V_16 = F_18 ( V_304 ) ;
V_303 -> V_173 = F_21 ( V_304 ) ;
V_303 -> V_195 = V_304 -> V_195 ;
V_303 -> V_199 = V_304 -> V_199 ;
V_303 -> V_307 = V_304 -> V_307 ;
}
int F_306 ( struct V_11 * V_12 , struct V_11 * V_308 ,
struct V_309 * V_310 , T_2 V_85 ,
int (* F_307)( struct V_28 * , struct V_28 * , void * ) ,
void * V_311 )
{
struct V_28 * V_28 , * V_312 ;
if ( ! V_310 )
V_310 = V_313 ;
F_4 ( NULL , V_12 ) ;
F_308 (bio_src, rq_src) {
V_28 = F_309 ( V_312 , V_85 , V_310 ) ;
if ( ! V_28 )
goto V_314;
if ( F_307 && F_307 ( V_28 , V_312 , V_311 ) )
goto V_314;
if ( V_12 -> V_28 ) {
V_12 -> V_45 -> V_198 = V_28 ;
V_12 -> V_45 = V_28 ;
} else
V_12 -> V_28 = V_12 -> V_45 = V_28 ;
}
F_305 ( V_12 , V_308 ) ;
return 0 ;
V_314:
if ( V_28 )
F_304 ( V_28 ) ;
F_303 ( V_12 ) ;
return - V_96 ;
}
int F_310 ( struct V_47 * V_48 )
{
return F_311 ( V_52 , V_48 ) ;
}
int F_312 ( struct V_315 * V_316 ,
unsigned long V_317 )
{
return F_30 ( V_52 , V_316 , V_317 ) ;
}
int F_313 ( int V_15 , struct V_315 * V_316 ,
unsigned long V_317 )
{
return F_314 ( V_15 , V_52 , V_316 , V_317 ) ;
}
void F_315 ( struct V_202 * V_203 )
{
struct V_318 * V_319 = V_148 ;
F_5 ( & V_203 -> V_207 ) ;
F_5 ( & V_203 -> V_206 ) ;
F_5 ( & V_203 -> V_320 ) ;
if ( ! V_319 -> V_203 ) {
V_319 -> V_203 = V_203 ;
}
}
static int F_316 ( void * V_321 , struct V_204 * V_322 , struct V_204 * V_230 )
{
struct V_11 * V_323 = F_23 ( V_322 , struct V_11 , V_13 ) ;
struct V_11 * V_324 = F_23 ( V_230 , struct V_11 , V_13 ) ;
return ! ( V_323 -> V_2 < V_324 -> V_2 ||
( V_323 -> V_2 == V_324 -> V_2 && F_18 ( V_323 ) < F_18 ( V_324 ) ) ) ;
}
static void F_317 ( struct V_1 * V_2 , unsigned int V_325 ,
bool V_326 )
__releases( V_2 -> V_50 )
{
F_318 ( V_2 , V_325 , ! V_326 ) ;
if ( V_326 )
F_45 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_319 ( V_2 -> V_50 ) ;
}
static void F_320 ( struct V_202 * V_203 , bool V_326 )
{
F_321 ( V_327 ) ;
while ( ! F_56 ( & V_203 -> V_320 ) ) {
F_322 ( & V_203 -> V_320 , & V_327 ) ;
while ( ! F_56 ( & V_327 ) ) {
struct V_328 * V_329 = F_323 ( & V_327 ,
struct V_328 ,
V_207 ) ;
F_324 ( & V_329 -> V_207 ) ;
V_329 -> V_330 ( V_329 , V_326 ) ;
}
}
}
struct V_328 * F_325 ( T_6 V_331 , void * V_311 ,
int V_332 )
{
struct V_202 * V_203 = V_148 -> V_203 ;
struct V_328 * V_329 ;
if ( ! V_203 )
return NULL ;
F_326 (cb, &plug->cb_list, list)
if ( V_329 -> V_330 == V_331 && V_329 -> V_311 == V_311 )
return V_329 ;
F_145 ( V_332 < sizeof( * V_329 ) ) ;
V_329 = F_94 ( V_332 , V_250 ) ;
if ( V_329 ) {
V_329 -> V_311 = V_311 ;
V_329 -> V_330 = V_331 ;
F_327 ( & V_329 -> V_207 , & V_203 -> V_320 ) ;
}
return V_329 ;
}
void F_206 ( struct V_202 * V_203 , bool V_326 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
struct V_11 * V_12 ;
F_321 ( V_207 ) ;
unsigned int V_325 ;
F_320 ( V_203 , V_326 ) ;
if ( ! F_56 ( & V_203 -> V_206 ) )
F_328 ( V_203 , V_326 ) ;
if ( F_56 ( & V_203 -> V_207 ) )
return;
F_322 ( & V_203 -> V_207 , & V_207 ) ;
F_329 ( NULL , & V_207 , F_316 ) ;
V_2 = NULL ;
V_325 = 0 ;
F_330 ( V_62 ) ;
while ( ! F_56 ( & V_207 ) ) {
V_12 = F_331 ( V_207 . V_333 ) ;
F_272 ( & V_12 -> V_13 ) ;
F_145 ( ! V_12 -> V_2 ) ;
if ( V_12 -> V_2 != V_2 ) {
if ( V_2 )
F_317 ( V_2 , V_325 , V_326 ) ;
V_2 = V_12 -> V_2 ;
V_325 = 0 ;
F_332 ( V_2 -> V_50 ) ;
}
if ( F_12 ( F_99 ( V_2 ) ) ) {
F_270 ( V_12 , - V_221 ) ;
continue;
}
if ( V_12 -> V_33 & ( V_145 | V_146 ) )
F_167 ( V_2 , V_12 , V_217 ) ;
else
F_167 ( V_2 , V_12 , V_334 ) ;
V_325 ++ ;
}
if ( V_2 )
F_317 ( V_2 , V_325 , V_326 ) ;
F_333 ( V_62 ) ;
}
void F_334 ( struct V_202 * V_203 )
{
F_206 ( V_203 , false ) ;
if ( V_203 == V_148 -> V_203 )
V_148 -> V_203 = NULL ;
}
void F_335 ( struct V_1 * V_2 , struct V_335 * V_165 )
{
V_2 -> V_165 = V_165 ;
V_2 -> V_266 = V_268 ;
F_336 ( V_2 -> V_165 , - 1 ) ;
F_337 ( V_2 -> V_165 ) ;
}
int F_338 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_24 ( V_2 -> V_50 ) ;
if ( V_2 -> V_184 ) {
V_10 = - V_336 ;
F_174 ( V_2 -> V_165 ) ;
} else {
V_2 -> V_266 = V_337 ;
}
F_26 ( V_2 -> V_50 ) ;
return V_10 ;
}
void F_339 ( struct V_1 * V_2 , int V_99 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! V_99 ) {
V_2 -> V_266 = V_267 ;
} else {
V_2 -> V_266 = V_268 ;
F_174 ( V_2 -> V_165 ) ;
}
F_26 ( V_2 -> V_50 ) ;
}
void F_340 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_50 ) ;
V_2 -> V_266 = V_338 ;
F_26 ( V_2 -> V_50 ) ;
}
void F_341 ( struct V_1 * V_2 , int V_99 )
{
F_24 ( V_2 -> V_50 ) ;
if ( ! V_99 ) {
V_2 -> V_266 = V_268 ;
F_25 ( V_2 ) ;
F_174 ( V_2 -> V_165 ) ;
F_342 ( V_2 -> V_165 ) ;
} else {
V_2 -> V_266 = V_267 ;
}
F_26 ( V_2 -> V_50 ) ;
}
int T_4 F_343 ( void )
{
F_344 ( V_339 > 8 *
sizeof( ( (struct V_11 * ) 0 ) -> V_33 ) ) ;
V_52 = F_345 ( L_31 ,
V_340 | V_341 , 0 ) ;
if ( ! V_52 )
F_346 ( L_32 ) ;
V_94 = F_347 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_342 , NULL ) ;
V_100 = F_347 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_342 , NULL ) ;
return 0 ;
}
