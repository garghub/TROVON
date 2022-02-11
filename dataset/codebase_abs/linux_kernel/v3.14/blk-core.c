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
V_12 -> V_28 , V_12 -> V_45 , V_12 -> V_46 , F_21 ( V_12 ) ) ;
if ( V_12 -> V_44 == V_47 ) {
F_17 ( V_41 L_5 ) ;
for ( V_40 = 0 ; V_40 < V_23 ; V_40 ++ )
F_17 ( L_6 , V_12 -> V_20 [ V_40 ] ) ;
F_17 ( L_7 ) ;
}
}
static void F_22 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_49 , struct V_1 , V_50 . V_49 ) ;
F_24 ( V_2 -> V_51 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_51 ) ;
}
void F_27 ( struct V_1 * V_2 , unsigned long V_52 )
{
if ( F_28 ( ! F_29 ( V_2 ) ) )
F_30 ( V_53 , & V_2 -> V_50 ,
F_31 ( V_52 ) ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( ! F_34 () ) ;
F_35 ( V_54 , V_2 ) ;
F_25 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_50 ) ;
F_38 ( V_54 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_56 ) {
struct V_57 * V_58 ;
int V_59 ;
F_41 (q, hctx, i)
F_42 ( & V_58 -> V_60 ) ;
} else {
F_42 ( & V_2 -> V_50 ) ;
}
}
inline void F_43 ( struct V_1 * V_2 )
{
if ( F_12 ( F_29 ( V_2 ) ) )
return;
V_2 -> V_61 ++ ;
V_2 -> V_62 ( V_2 ) ;
V_2 -> V_61 -- ;
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
F_46 ( V_53 , & V_2 -> V_50 , 0 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_63 ;
F_48 ( V_2 -> V_51 , V_63 ) ;
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_51 , V_63 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_64 ) ;
}
static void F_52 ( struct V_1 * V_2 , bool V_65 )
__releases( V_2 -> V_51 )
__acquires( V_2 -> V_51 )
{
int V_59 ;
F_53 ( V_2 -> V_51 ) ;
while ( true ) {
bool V_66 = false ;
if ( V_2 -> V_67 )
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( ! F_56 ( & V_2 -> V_68 ) && V_2 -> V_62 )
F_25 ( V_2 ) ;
V_66 |= V_2 -> V_69 ;
V_66 |= V_2 -> V_61 ;
if ( V_65 ) {
V_66 |= ! F_56 ( & V_2 -> V_68 ) ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
V_66 |= V_2 -> V_70 [ V_59 ] ;
V_66 |= V_2 -> V_71 [ V_59 ] ;
V_66 |= ! F_56 ( & V_2 -> V_72 [ V_59 ] ) ;
}
}
if ( ! V_66 )
break;
F_26 ( V_2 -> V_51 ) ;
F_57 ( 10 ) ;
F_24 ( V_2 -> V_51 ) ;
}
if ( V_2 -> V_62 ) {
struct V_73 * V_74 ;
F_58 (rl, q)
for ( V_59 = 0 ; V_59 < F_59 ( V_74 -> V_75 ) ; V_59 ++ )
F_60 ( & V_74 -> V_75 [ V_59 ] ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
bool V_66 ;
F_24 ( V_2 -> V_51 ) ;
V_66 = ! V_2 -> V_76 ++ ;
F_38 ( V_77 , V_2 ) ;
F_26 ( V_2 -> V_51 ) ;
if ( V_66 ) {
F_24 ( V_2 -> V_51 ) ;
F_52 ( V_2 , false ) ;
F_26 ( V_2 -> V_51 ) ;
F_62 () ;
}
}
void F_63 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_51 ) ;
if ( ! -- V_2 -> V_76 )
F_35 ( V_77 , V_2 ) ;
F_64 ( V_2 -> V_76 < 0 ) ;
F_26 ( V_2 -> V_51 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
T_1 * V_78 = V_2 -> V_51 ;
F_66 ( & V_2 -> V_79 ) ;
F_67 ( V_80 , V_2 ) ;
F_24 ( V_78 ) ;
V_2 -> V_76 ++ ;
F_38 ( V_77 , V_2 ) ;
F_38 ( V_81 , V_2 ) ;
F_38 ( V_82 , V_2 ) ;
F_38 ( V_80 , V_2 ) ;
F_26 ( V_78 ) ;
F_68 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_56 ) {
F_69 ( V_2 ) ;
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
if ( V_2 -> V_51 != & V_2 -> V_85 )
V_2 -> V_51 = & V_2 -> V_85 ;
F_26 ( V_78 ) ;
F_50 ( V_2 ) ;
}
int F_70 ( struct V_73 * V_74 , struct V_1 * V_2 ,
T_2 V_86 )
{
if ( F_12 ( V_74 -> V_87 ) )
return 0 ;
V_74 -> V_2 = V_2 ;
V_74 -> V_88 [ V_89 ] = V_74 -> V_88 [ V_90 ] = 0 ;
V_74 -> V_91 [ V_89 ] = V_74 -> V_91 [ V_90 ] = 0 ;
F_71 ( & V_74 -> V_75 [ V_89 ] ) ;
F_71 ( & V_74 -> V_75 [ V_90 ] ) ;
V_74 -> V_87 = F_72 ( V_92 , V_93 ,
V_94 , V_95 ,
V_86 , V_2 -> V_96 ) ;
if ( ! V_74 -> V_87 )
return - V_97 ;
return 0 ;
}
void F_73 ( struct V_73 * V_74 )
{
if ( V_74 -> V_87 )
F_74 ( V_74 -> V_87 ) ;
}
struct V_1 * F_75 ( T_2 V_86 )
{
return F_76 ( V_86 , V_98 ) ;
}
struct V_1 * F_76 ( T_2 V_86 , int V_99 )
{
struct V_1 * V_2 ;
int V_100 ;
V_2 = F_77 ( V_101 ,
V_86 | V_102 , V_99 ) ;
if ( ! V_2 )
return NULL ;
if ( F_78 ( & V_2 -> V_103 , 0 ) )
goto V_104;
V_2 -> V_105 = F_79 ( & V_106 , 0 , 0 , V_86 ) ;
if ( V_2 -> V_105 < 0 )
goto V_107;
V_2 -> V_7 . V_108 =
( V_109 * 1024 ) / V_110 ;
V_2 -> V_7 . V_111 = 0 ;
V_2 -> V_7 . V_112 = V_113 ;
V_2 -> V_7 . V_114 = L_8 ;
V_2 -> V_96 = V_99 ;
V_100 = F_80 ( & V_2 -> V_7 ) ;
if ( V_100 )
goto V_115;
F_81 ( & V_2 -> V_7 . V_84 ,
V_116 , ( unsigned long ) V_2 ) ;
F_81 ( & V_2 -> V_55 , V_117 , ( unsigned long ) V_2 ) ;
F_5 ( & V_2 -> V_68 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_118 ) ;
#ifdef F_82
F_5 ( & V_2 -> V_119 ) ;
#endif
F_5 ( & V_2 -> V_72 [ 0 ] ) ;
F_5 ( & V_2 -> V_72 [ 1 ] ) ;
F_5 ( & V_2 -> V_120 ) ;
F_83 ( & V_2 -> V_50 , F_22 ) ;
F_84 ( & V_2 -> V_64 , & V_121 ) ;
F_85 ( & V_2 -> V_79 ) ;
F_86 ( & V_2 -> V_85 ) ;
V_2 -> V_51 = & V_2 -> V_85 ;
V_2 -> V_76 = 1 ;
F_87 ( V_77 , & V_2 -> V_122 ) ;
F_71 ( & V_2 -> V_123 ) ;
if ( F_88 ( V_2 ) )
goto V_124;
return V_2 ;
V_124:
F_89 ( & V_2 -> V_7 ) ;
V_115:
F_90 ( & V_106 , V_2 -> V_105 ) ;
V_107:
F_91 ( & V_2 -> V_103 ) ;
V_104:
F_92 ( V_101 , V_2 ) ;
return NULL ;
}
struct V_1 * F_93 ( T_3 * V_125 , T_1 * V_78 )
{
return F_94 ( V_125 , V_78 , V_98 ) ;
}
struct V_1 *
F_94 ( T_3 * V_125 , T_1 * V_78 , int V_99 )
{
struct V_1 * V_126 , * V_2 ;
V_126 = F_76 ( V_127 , V_99 ) ;
if ( ! V_126 )
return NULL ;
V_2 = F_95 ( V_126 , V_125 , V_78 ) ;
if ( ! V_2 )
F_65 ( V_126 ) ;
return V_2 ;
}
struct V_1 *
F_95 ( struct V_1 * V_2 , T_3 * V_125 ,
T_1 * V_78 )
{
if ( ! V_2 )
return NULL ;
V_2 -> V_128 = F_96 ( sizeof( struct V_11 ) , V_127 ) ;
if ( ! V_2 -> V_128 )
return NULL ;
if ( F_70 ( & V_2 -> V_129 , V_2 , V_127 ) )
goto V_130;
V_2 -> V_62 = V_125 ;
V_2 -> V_131 = NULL ;
V_2 -> V_132 = NULL ;
V_2 -> V_122 |= V_133 ;
if ( V_78 )
V_2 -> V_51 = V_78 ;
F_97 ( V_2 , V_134 ) ;
V_2 -> V_135 = V_136 ;
F_66 ( & V_2 -> V_79 ) ;
if ( F_98 ( V_2 , NULL ) ) {
F_68 ( & V_2 -> V_79 ) ;
goto V_130;
}
F_68 ( & V_2 -> V_79 ) ;
return V_2 ;
V_130:
F_99 ( V_2 -> V_128 ) ;
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
static inline void F_103 ( struct V_73 * V_74 , struct V_11 * V_12 )
{
if ( V_12 -> V_33 & V_137 ) {
F_104 ( V_74 -> V_2 , V_12 ) ;
if ( V_12 -> V_138 . V_139 )
F_105 ( V_12 -> V_138 . V_139 -> V_140 ) ;
}
F_106 ( V_12 , V_74 -> V_87 ) ;
}
static inline int F_107 ( struct V_1 * V_2 , struct V_141 * V_140 )
{
if ( ! V_140 )
return 0 ;
return V_140 -> V_142 == V_2 -> V_143 ||
( V_140 -> V_142 > 0
&& F_108 ( V_26 , V_140 -> V_144 + V_145 ) ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_141 * V_140 )
{
if ( ! V_140 || F_107 ( V_2 , V_140 ) )
return;
V_140 -> V_142 = V_2 -> V_143 ;
V_140 -> V_144 = V_26 ;
}
static void F_110 ( struct V_73 * V_74 , int V_146 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
if ( V_74 == & V_2 -> V_129 &&
V_74 -> V_88 [ V_146 ] < F_111 ( V_2 ) )
F_112 ( V_2 , V_146 ) ;
if ( V_74 -> V_88 [ V_146 ] + 1 <= V_2 -> V_4 ) {
if ( F_113 ( & V_74 -> V_75 [ V_146 ] ) )
F_114 ( & V_74 -> V_75 [ V_146 ] ) ;
F_115 ( V_74 , V_146 ) ;
}
}
static void F_116 ( struct V_73 * V_74 , unsigned int V_63 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_146 = F_117 ( V_63 ) ;
V_2 -> V_70 [ V_146 ] -- ;
V_74 -> V_88 [ V_146 ] -- ;
if ( V_63 & V_137 )
V_2 -> V_69 -- ;
F_110 ( V_74 , V_146 ) ;
if ( F_12 ( V_74 -> V_91 [ V_146 ^ 1 ] ) )
F_110 ( V_74 , V_146 ^ 1 ) ;
}
static bool F_118 ( struct V_28 * V_28 )
{
if ( ! V_28 )
return true ;
if ( V_28 -> V_147 & ( V_148 | V_149 ) )
return false ;
return true ;
}
static struct V_141 * F_119 ( struct V_28 * V_28 )
{
#ifdef F_82
if ( V_28 && V_28 -> V_150 )
return V_28 -> V_150 ;
#endif
return V_151 -> V_141 ;
}
static struct V_11 * F_120 ( struct V_73 * V_74 , int V_152 ,
struct V_28 * V_28 , T_2 V_86 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_11 * V_12 ;
struct V_153 * V_154 = V_2 -> V_67 -> type ;
struct V_141 * V_140 = F_119 ( V_28 ) ;
struct V_155 * V_139 = NULL ;
const bool V_156 = F_117 ( V_152 ) != 0 ;
int V_157 ;
if ( F_12 ( F_101 ( V_2 ) ) )
return NULL ;
V_157 = F_121 ( V_2 , V_152 ) ;
if ( V_157 == V_158 )
goto V_159;
if ( V_74 -> V_88 [ V_156 ] + 1 >= F_122 ( V_2 ) ) {
if ( V_74 -> V_88 [ V_156 ] + 1 >= V_2 -> V_4 ) {
if ( ! F_123 ( V_74 , V_156 ) ) {
F_109 ( V_2 , V_140 ) ;
F_124 ( V_74 , V_156 ) ;
} else {
if ( V_157 != V_160
&& ! F_107 ( V_2 , V_140 ) ) {
return NULL ;
}
}
}
if ( V_74 == & V_2 -> V_129 )
F_125 ( V_2 , V_156 ) ;
}
if ( V_74 -> V_88 [ V_156 ] >= ( 3 * V_2 -> V_4 / 2 ) )
return NULL ;
V_2 -> V_70 [ V_156 ] ++ ;
V_74 -> V_88 [ V_156 ] ++ ;
V_74 -> V_91 [ V_156 ] = 0 ;
if ( F_118 ( V_28 ) && ! F_126 ( V_2 ) ) {
V_152 |= V_137 ;
V_2 -> V_69 ++ ;
if ( V_154 -> V_161 && V_140 )
V_139 = F_127 ( V_140 , V_2 ) ;
}
if ( F_128 ( V_2 ) )
V_152 |= V_162 ;
F_26 ( V_2 -> V_51 ) ;
V_12 = F_129 ( V_74 -> V_87 , V_86 ) ;
if ( ! V_12 )
goto V_163;
F_4 ( V_2 , V_12 ) ;
F_130 ( V_12 , V_74 ) ;
V_12 -> V_33 = V_152 | V_164 ;
if ( V_152 & V_137 ) {
if ( F_12 ( V_154 -> V_161 && ! V_139 ) ) {
if ( V_140 )
V_139 = F_131 ( V_140 , V_2 , V_86 ) ;
if ( ! V_139 )
goto V_165;
}
V_12 -> V_138 . V_139 = V_139 ;
if ( F_12 ( F_132 ( V_2 , V_12 , V_28 , V_86 ) ) )
goto V_165;
if ( V_139 )
F_133 ( V_139 -> V_140 ) ;
}
V_166:
if ( F_107 ( V_2 , V_140 ) )
V_140 -> V_142 -- ;
F_134 ( V_2 , V_28 , V_152 & 1 ) ;
return V_12 ;
V_165:
F_135 ( V_167 L_9 ,
F_136 ( V_2 -> V_7 . V_168 ) ) ;
V_12 -> V_33 &= ~ V_137 ;
V_12 -> V_138 . V_139 = NULL ;
F_24 ( V_2 -> V_51 ) ;
V_2 -> V_69 -- ;
F_26 ( V_2 -> V_51 ) ;
goto V_166;
V_163:
F_24 ( V_2 -> V_51 ) ;
F_116 ( V_74 , V_152 ) ;
V_159:
if ( F_12 ( V_74 -> V_88 [ V_156 ] == 0 ) )
V_74 -> V_91 [ V_156 ] = 1 ;
return NULL ;
}
static struct V_11 * F_137 ( struct V_1 * V_2 , int V_152 ,
struct V_28 * V_28 , T_2 V_86 )
{
const bool V_156 = F_117 ( V_152 ) != 0 ;
F_138 ( V_75 ) ;
struct V_73 * V_74 ;
struct V_11 * V_12 ;
V_74 = F_139 ( V_2 , V_28 ) ;
V_169:
V_12 = F_120 ( V_74 , V_152 , V_28 , V_86 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_86 & V_170 ) || F_12 ( F_101 ( V_2 ) ) ) {
F_140 ( V_74 ) ;
return NULL ;
}
F_141 ( & V_74 -> V_75 [ V_156 ] , & V_75 ,
V_171 ) ;
F_142 ( V_2 , V_28 , V_152 & 1 ) ;
F_26 ( V_2 -> V_51 ) ;
F_143 () ;
F_109 ( V_2 , V_151 -> V_141 ) ;
F_24 ( V_2 -> V_51 ) ;
F_144 ( & V_74 -> V_75 [ V_156 ] , & V_75 ) ;
goto V_169;
}
static struct V_11 * F_145 ( struct V_1 * V_2 , int V_172 ,
T_2 V_86 )
{
struct V_11 * V_12 ;
F_146 ( V_172 != V_173 && V_172 != V_174 ) ;
F_147 ( V_86 , V_2 -> V_96 ) ;
F_24 ( V_2 -> V_51 ) ;
V_12 = F_137 ( V_2 , V_172 , NULL , V_86 ) ;
if ( ! V_12 )
F_26 ( V_2 -> V_51 ) ;
return V_12 ;
}
struct V_11 * F_148 ( struct V_1 * V_2 , int V_172 , T_2 V_86 )
{
if ( V_2 -> V_56 )
return F_149 ( V_2 , V_172 , V_86 ) ;
else
return F_145 ( V_2 , V_172 , V_86 ) ;
}
struct V_11 * F_150 ( struct V_1 * V_2 , struct V_28 * V_28 ,
T_2 V_86 )
{
struct V_11 * V_12 = F_148 ( V_2 , F_151 ( V_28 ) , V_86 ) ;
if ( F_12 ( ! V_12 ) )
return F_152 ( - V_97 ) ;
F_153 (bio) {
struct V_28 * V_175 = V_28 ;
int V_10 ;
F_154 ( V_2 , & V_175 ) ;
V_10 = F_155 ( V_2 , V_12 , V_175 ) ;
if ( F_12 ( V_10 ) ) {
F_156 ( V_12 ) ;
return F_152 ( V_10 ) ;
}
}
return V_12 ;
}
void F_157 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_158 ( V_12 ) ;
F_159 ( V_12 ) ;
F_160 ( V_2 , V_12 ) ;
if ( F_161 ( V_12 ) )
F_162 ( V_2 , V_12 ) ;
F_146 ( F_163 ( V_12 ) ) ;
F_164 ( V_2 , V_12 ) ;
}
static void F_165 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_176 )
{
F_166 ( V_12 , true ) ;
F_167 ( V_2 , V_12 , V_176 ) ;
}
static void F_168 ( int V_15 , struct V_177 * V_27 ,
unsigned long V_178 )
{
if ( V_178 == V_27 -> V_179 )
return;
if ( F_169 ( V_27 ) ) {
F_170 ( V_15 , V_27 , V_180 ,
F_169 ( V_27 ) * ( V_178 - V_27 -> V_179 ) ) ;
F_170 ( V_15 , V_27 , V_181 , ( V_178 - V_27 -> V_179 ) ) ;
}
V_27 -> V_179 = V_178 ;
}
void F_171 ( int V_15 , struct V_177 * V_27 )
{
unsigned long V_178 = V_26 ;
if ( V_27 -> V_182 )
F_168 ( V_15 , & F_172 ( V_27 ) -> V_183 , V_178 ) ;
F_168 ( V_15 , V_27 , V_178 ) ;
}
static void F_173 ( struct V_11 * V_12 )
{
if ( V_12 -> V_2 -> V_168 && ! ( V_12 -> V_33 & V_184 ) && ! -- V_12 -> V_2 -> V_185 )
F_174 ( V_12 -> V_2 -> V_168 ) ;
}
static inline void F_173 ( struct V_11 * V_12 ) {}
void F_175 ( struct V_1 * V_2 , struct V_11 * V_186 )
{
if ( F_12 ( ! V_2 ) )
return;
if ( V_2 -> V_56 ) {
F_176 ( V_186 ) ;
return;
}
F_173 ( V_186 ) ;
F_177 ( V_2 , V_186 ) ;
F_33 ( V_186 -> V_28 != NULL ) ;
if ( V_186 -> V_33 & V_164 ) {
unsigned int V_63 = V_186 -> V_33 ;
struct V_73 * V_74 = F_178 ( V_186 ) ;
F_146 ( ! F_56 ( & V_186 -> V_13 ) ) ;
F_146 ( ! F_179 ( & V_186 -> V_18 ) ) ;
F_103 ( V_74 , V_186 ) ;
F_116 ( V_74 , V_63 ) ;
F_140 ( V_74 ) ;
}
}
void F_156 ( struct V_11 * V_186 )
{
struct V_1 * V_2 = V_186 -> V_2 ;
if ( V_2 -> V_56 )
F_176 ( V_186 ) ;
else {
unsigned long V_63 ;
F_48 ( V_2 -> V_51 , V_63 ) ;
F_175 ( V_2 , V_186 ) ;
F_49 ( V_2 -> V_51 , V_63 ) ;
}
}
void F_180 ( struct V_11 * V_12 , struct V_187 * V_187 ,
unsigned int V_188 )
{
struct V_28 * V_28 = V_12 -> V_28 ;
V_28 -> V_189 -> V_190 = V_187 ;
V_28 -> V_189 -> V_191 = 0 ;
V_28 -> V_189 -> V_192 = V_188 ;
V_28 -> V_36 . V_37 = V_188 ;
V_28 -> V_193 = 1 ;
V_28 -> V_194 = 1 ;
V_12 -> V_195 = V_12 -> V_196 = V_188 ;
V_12 -> V_197 = 1 ;
V_12 -> V_46 = F_181 ( V_28 ) ;
}
bool F_182 ( struct V_1 * V_2 , struct V_11 * V_186 ,
struct V_28 * V_28 )
{
const int V_198 = V_28 -> V_147 & V_199 ;
if ( ! F_183 ( V_2 , V_186 , V_28 ) )
return false ;
F_184 ( V_2 , V_186 , V_28 ) ;
if ( ( V_186 -> V_33 & V_199 ) != V_198 )
F_185 ( V_186 ) ;
V_186 -> V_45 -> V_200 = V_28 ;
V_186 -> V_45 = V_28 ;
V_186 -> V_195 += V_28 -> V_36 . V_37 ;
V_186 -> V_201 = F_186 ( V_186 -> V_201 , F_187 ( V_28 ) ) ;
F_166 ( V_186 , false ) ;
return true ;
}
bool F_188 ( struct V_1 * V_2 , struct V_11 * V_186 ,
struct V_28 * V_28 )
{
const int V_198 = V_28 -> V_147 & V_199 ;
if ( ! F_189 ( V_2 , V_186 , V_28 ) )
return false ;
F_190 ( V_2 , V_186 , V_28 ) ;
if ( ( V_186 -> V_33 & V_199 ) != V_198 )
F_185 ( V_186 ) ;
V_28 -> V_200 = V_186 -> V_28 ;
V_186 -> V_28 = V_28 ;
V_186 -> V_46 = F_181 ( V_28 ) ;
V_186 -> V_16 = V_28 -> V_36 . V_202 ;
V_186 -> V_195 += V_28 -> V_36 . V_37 ;
V_186 -> V_201 = F_186 ( V_186 -> V_201 , F_187 ( V_28 ) ) ;
F_166 ( V_186 , false ) ;
return true ;
}
bool F_191 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned int * V_203 )
{
struct V_204 * V_205 ;
struct V_11 * V_12 ;
bool V_10 = false ;
struct V_206 * V_207 ;
if ( F_192 ( V_2 ) )
goto V_166;
V_205 = V_151 -> V_205 ;
if ( ! V_205 )
goto V_166;
* V_203 = 0 ;
if ( V_2 -> V_56 )
V_207 = & V_205 -> V_208 ;
else
V_207 = & V_205 -> V_209 ;
F_193 (rq, plug_list, queuelist) {
int V_210 ;
if ( V_12 -> V_2 == V_2 )
( * V_203 ) ++ ;
if ( V_12 -> V_2 != V_2 || ! F_194 ( V_12 , V_28 ) )
continue;
V_210 = F_195 ( V_12 , V_28 ) ;
if ( V_210 == V_211 ) {
V_10 = F_182 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
} else if ( V_210 == V_212 ) {
V_10 = F_188 ( V_2 , V_12 , V_28 ) ;
if ( V_10 )
break;
}
}
V_166:
return V_10 ;
}
void F_196 ( struct V_11 * V_186 , struct V_28 * V_28 )
{
V_186 -> V_44 = V_213 ;
V_186 -> V_33 |= V_28 -> V_147 & V_214 ;
if ( V_28 -> V_147 & V_215 )
V_186 -> V_33 |= V_199 ;
V_186 -> V_216 = 0 ;
V_186 -> V_16 = V_28 -> V_36 . V_202 ;
V_186 -> V_201 = F_187 ( V_28 ) ;
F_197 ( V_186 -> V_2 , V_186 , V_28 ) ;
}
void V_134 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
const bool V_146 = ! ! ( V_28 -> V_147 & V_217 ) ;
struct V_204 * V_205 ;
int V_210 , V_152 , V_176 = V_218 ;
struct V_11 * V_186 ;
unsigned int V_203 = 0 ;
F_154 ( V_2 , & V_28 ) ;
if ( F_198 ( V_28 ) && F_199 ( V_28 ) ) {
F_15 ( V_28 , - V_32 ) ;
return;
}
if ( V_28 -> V_147 & ( V_148 | V_149 ) ) {
F_24 ( V_2 -> V_51 ) ;
V_176 = V_219 ;
goto V_220;
}
if ( F_191 ( V_2 , V_28 , & V_203 ) )
return;
F_24 ( V_2 -> V_51 ) ;
V_210 = F_200 ( V_2 , & V_186 , V_28 ) ;
if ( V_210 == V_211 ) {
if ( F_182 ( V_2 , V_186 , V_28 ) ) {
F_201 ( V_2 , V_186 , V_28 ) ;
if ( ! F_202 ( V_2 , V_186 ) )
F_203 ( V_2 , V_186 , V_210 ) ;
goto V_221;
}
} else if ( V_210 == V_212 ) {
if ( F_188 ( V_2 , V_186 , V_28 ) ) {
F_201 ( V_2 , V_186 , V_28 ) ;
if ( ! F_204 ( V_2 , V_186 ) )
F_203 ( V_2 , V_186 , V_210 ) ;
goto V_221;
}
}
V_220:
V_152 = F_151 ( V_28 ) ;
if ( V_146 )
V_152 |= V_217 ;
V_186 = F_137 ( V_2 , V_152 , V_28 , V_222 ) ;
if ( F_12 ( ! V_186 ) ) {
F_15 ( V_28 , - V_223 ) ;
goto V_221;
}
F_196 ( V_186 , V_28 ) ;
if ( F_11 ( V_224 , & V_2 -> V_122 ) )
V_186 -> V_15 = F_205 () ;
V_205 = V_151 -> V_205 ;
if ( V_205 ) {
if ( ! V_203 )
F_206 ( V_2 ) ;
else {
if ( V_203 >= V_225 ) {
F_207 ( V_205 , false ) ;
F_206 ( V_2 ) ;
}
}
F_208 ( & V_186 -> V_13 , & V_205 -> V_209 ) ;
F_166 ( V_186 , true ) ;
} else {
F_24 ( V_2 -> V_51 ) ;
F_165 ( V_2 , V_186 , V_176 ) ;
F_25 ( V_2 ) ;
V_221:
F_26 ( V_2 -> V_51 ) ;
}
}
static inline void F_209 ( struct V_28 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_226 ;
if ( F_210 ( V_28 ) && V_9 != V_9 -> V_227 ) {
struct V_177 * V_228 = V_9 -> V_229 ;
V_28 -> V_36 . V_202 += V_228 -> V_230 ;
V_28 -> V_226 = V_9 -> V_227 ;
F_211 ( F_3 ( V_28 -> V_226 ) , V_28 ,
V_9 -> V_231 ,
V_28 -> V_36 . V_202 - V_228 -> V_230 ) ;
}
}
static void F_212 ( struct V_28 * V_28 )
{
char V_232 [ V_233 ] ;
F_17 ( V_41 L_10 ) ;
F_17 ( V_41 L_11 ,
F_213 ( V_28 -> V_226 , V_232 ) ,
V_28 -> V_147 ,
( unsigned long long ) F_214 ( V_28 ) ,
( long long ) ( F_215 ( V_28 -> V_226 -> V_234 ) >> 9 ) ) ;
F_13 ( V_235 , & V_28 -> V_31 ) ;
}
static int T_4 F_216 ( char * V_236 )
{
return F_217 ( & V_237 , V_236 ) ;
}
static bool F_218 ( struct V_177 * V_27 , unsigned int V_238 )
{
return V_27 -> V_239 && F_219 ( & V_237 , V_238 ) ;
}
static int T_4 F_220 ( void )
{
struct V_240 * V_241 = F_221 ( L_12 ,
NULL , & V_237 ) ;
return F_222 ( V_241 ) ? F_223 ( V_241 ) : 0 ;
}
static inline bool F_218 ( struct V_177 * V_27 ,
unsigned int V_238 )
{
return false ;
}
static inline int F_224 ( struct V_28 * V_28 , unsigned int V_242 )
{
V_17 V_243 ;
if ( ! V_242 )
return 0 ;
V_243 = F_215 ( V_28 -> V_226 -> V_234 ) >> 9 ;
if ( V_243 ) {
V_17 V_244 = V_28 -> V_36 . V_202 ;
if ( V_243 < V_242 || V_243 - V_242 < V_244 ) {
F_212 ( V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_225 ( struct V_28 * V_28 )
{
struct V_1 * V_2 ;
int V_242 = F_210 ( V_28 ) ;
int V_100 = - V_32 ;
char V_232 [ V_233 ] ;
struct V_177 * V_27 ;
F_226 () ;
if ( F_224 ( V_28 , V_242 ) )
goto V_245;
V_2 = F_3 ( V_28 -> V_226 ) ;
if ( F_12 ( ! V_2 ) ) {
F_17 ( V_246
L_13
L_14 ,
F_213 ( V_28 -> V_226 , V_232 ) ,
( long long ) V_28 -> V_36 . V_202 ) ;
goto V_245;
}
if ( F_28 ( F_227 ( V_28 ) &&
V_242 > F_228 ( V_2 ) ) ) {
F_17 ( V_246 L_15 ,
F_213 ( V_28 -> V_226 , V_232 ) ,
F_210 ( V_28 ) ,
F_228 ( V_2 ) ) ;
goto V_245;
}
V_27 = V_28 -> V_226 -> V_229 ;
if ( F_218 ( V_27 , V_28 -> V_36 . V_37 ) ||
F_218 ( & F_172 ( V_27 ) -> V_183 ,
V_28 -> V_36 . V_37 ) )
goto V_245;
F_209 ( V_28 ) ;
if ( F_224 ( V_28 , V_242 ) )
goto V_245;
if ( ( V_28 -> V_147 & ( V_148 | V_149 ) ) && ! V_2 -> V_247 ) {
V_28 -> V_147 &= ~ ( V_148 | V_149 ) ;
if ( ! V_242 ) {
V_100 = 0 ;
goto V_245;
}
}
if ( ( V_28 -> V_147 & V_248 ) &&
( ! F_229 ( V_2 ) ||
( ( V_28 -> V_147 & V_249 ) && ! F_230 ( V_2 ) ) ) ) {
V_100 = - V_250 ;
goto V_245;
}
if ( V_28 -> V_147 & V_251 && ! F_231 ( V_28 -> V_226 ) ) {
V_100 = - V_250 ;
goto V_245;
}
F_147 ( V_252 , V_2 -> V_96 ) ;
if ( F_232 ( V_2 , V_28 ) )
return false ;
F_233 ( V_2 , V_28 ) ;
return true ;
V_245:
F_15 ( V_28 , V_100 ) ;
return false ;
}
void F_234 ( struct V_28 * V_28 )
{
struct V_253 V_254 ;
if ( ! F_225 ( V_28 ) )
return;
if ( V_151 -> V_253 ) {
F_235 ( V_151 -> V_253 , V_28 ) ;
return;
}
F_146 ( V_28 -> V_200 ) ;
F_236 ( & V_254 ) ;
V_151 -> V_253 = & V_254 ;
do {
struct V_1 * V_2 = F_3 ( V_28 -> V_226 ) ;
V_2 -> V_255 ( V_2 , V_28 ) ;
V_28 = F_237 ( V_151 -> V_253 ) ;
} while ( V_28 );
V_151 -> V_253 = NULL ;
}
void F_238 ( int V_172 , struct V_28 * V_28 )
{
V_28 -> V_147 |= V_172 ;
if ( F_239 ( V_28 ) ) {
unsigned int V_88 ;
if ( F_12 ( V_172 & V_251 ) )
V_88 = F_240 ( V_28 -> V_226 ) >> 9 ;
else
V_88 = F_210 ( V_28 ) ;
if ( V_172 & V_174 ) {
F_241 ( V_256 , V_88 ) ;
} else {
F_242 ( V_28 -> V_36 . V_37 ) ;
F_241 ( V_257 , V_88 ) ;
}
if ( F_12 ( V_258 ) ) {
char V_232 [ V_233 ] ;
F_17 ( V_259 L_16 ,
V_151 -> V_260 , F_243 ( V_151 ) ,
( V_172 & V_174 ) ? L_17 : L_18 ,
( unsigned long long ) V_28 -> V_36 . V_202 ,
F_213 ( V_28 -> V_226 , V_232 ) ,
V_88 ) ;
}
}
F_234 ( V_28 ) ;
}
int F_244 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_245 ( V_12 ) )
return 0 ;
if ( F_19 ( V_12 ) > F_246 ( V_2 , V_12 -> V_33 ) ) {
F_17 ( V_246 L_19 , V_261 ) ;
return - V_32 ;
}
F_247 ( V_12 ) ;
if ( V_12 -> V_197 > F_248 ( V_2 ) ) {
F_17 ( V_246 L_20 , V_261 ) ;
return - V_32 ;
}
return 0 ;
}
int F_249 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned long V_63 ;
int V_176 = V_262 ;
if ( F_244 ( V_2 , V_12 ) )
return - V_32 ;
if ( V_12 -> V_42 &&
F_218 ( & V_12 -> V_42 -> V_183 , F_21 ( V_12 ) ) )
return - V_32 ;
F_48 ( V_2 -> V_51 , V_63 ) ;
if ( F_12 ( F_101 ( V_2 ) ) ) {
F_49 ( V_2 -> V_51 , V_63 ) ;
return - V_223 ;
}
F_146 ( F_163 ( V_12 ) ) ;
if ( V_12 -> V_33 & ( V_148 | V_149 ) )
V_176 = V_219 ;
F_165 ( V_2 , V_12 , V_176 ) ;
if ( V_176 == V_219 )
F_25 ( V_2 ) ;
F_49 ( V_2 -> V_51 , V_63 ) ;
return 0 ;
}
unsigned int F_250 ( const struct V_11 * V_12 )
{
unsigned int V_198 = V_12 -> V_33 & V_199 ;
unsigned int V_238 = 0 ;
struct V_28 * V_28 ;
if ( ! ( V_12 -> V_33 & V_263 ) )
return F_21 ( V_12 ) ;
for ( V_28 = V_12 -> V_28 ; V_28 ; V_28 = V_28 -> V_200 ) {
if ( ( V_28 -> V_147 & V_198 ) != V_198 )
break;
V_238 += V_28 -> V_36 . V_37 ;
}
F_146 ( F_21 ( V_12 ) && ! V_238 ) ;
return V_238 ;
}
void F_251 ( struct V_11 * V_186 , unsigned int V_238 )
{
if ( F_252 ( V_186 ) ) {
const int V_172 = F_253 ( V_186 ) ;
struct V_177 * V_27 ;
int V_15 ;
V_15 = F_254 () ;
V_27 = V_186 -> V_27 ;
F_255 ( V_15 , V_27 , V_264 [ V_172 ] , V_238 >> 9 ) ;
F_256 () ;
}
}
void F_257 ( struct V_11 * V_186 )
{
if ( F_252 ( V_186 ) && ! ( V_186 -> V_33 & V_38 ) ) {
unsigned long V_265 = V_26 - V_186 -> V_25 ;
const int V_172 = F_253 ( V_186 ) ;
struct V_177 * V_27 ;
int V_15 ;
V_15 = F_254 () ;
V_27 = V_186 -> V_27 ;
F_258 ( V_15 , V_27 , V_266 [ V_172 ] ) ;
F_255 ( V_15 , V_27 , V_267 [ V_172 ] , V_265 ) ;
F_171 ( V_15 , V_27 ) ;
F_259 ( V_27 , V_172 ) ;
F_260 ( V_27 ) ;
F_256 () ;
}
}
static struct V_11 * F_261 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( V_2 -> V_168 && ( V_2 -> V_268 == V_269 ||
( V_2 -> V_268 != V_270 && ! ( V_12 -> V_33 & V_184 ) ) ) )
return NULL ;
else
return V_12 ;
}
static inline struct V_11 * F_261 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return V_12 ;
}
void F_166 ( struct V_11 * V_12 , bool V_271 )
{
struct V_177 * V_27 ;
int V_172 = F_253 ( V_12 ) ;
int V_15 ;
if ( ! F_252 ( V_12 ) )
return;
V_15 = F_254 () ;
if ( ! V_271 ) {
V_27 = V_12 -> V_27 ;
F_258 ( V_15 , V_27 , V_272 [ V_172 ] ) ;
} else {
V_27 = F_262 ( V_12 -> V_42 , F_18 ( V_12 ) ) ;
if ( ! F_263 ( V_27 ) ) {
V_27 = & V_12 -> V_42 -> V_183 ;
F_264 ( V_27 ) ;
}
F_171 ( V_15 , V_27 ) ;
F_265 ( V_27 , V_172 ) ;
V_12 -> V_27 = V_27 ;
}
F_256 () ;
}
struct V_11 * F_266 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_10 ;
while ( ( V_12 = F_267 ( V_2 ) ) != NULL ) {
V_12 = F_261 ( V_2 , V_12 ) ;
if ( ! V_12 )
break;
if ( ! ( V_12 -> V_33 & V_273 ) ) {
if ( V_12 -> V_33 & V_274 )
F_268 ( V_2 , V_12 ) ;
V_12 -> V_33 |= V_273 ;
F_269 ( V_2 , V_12 ) ;
}
if ( ! V_2 -> V_275 || V_2 -> V_275 == V_12 ) {
V_2 -> V_276 = F_270 ( V_12 ) ;
V_2 -> V_275 = NULL ;
}
if ( V_12 -> V_33 & V_277 )
break;
if ( V_2 -> V_278 && F_21 ( V_12 ) ) {
V_12 -> V_197 ++ ;
}
if ( ! V_2 -> V_131 )
break;
V_10 = V_2 -> V_131 ( V_2 , V_12 ) ;
if ( V_10 == V_279 ) {
break;
} else if ( V_10 == V_280 ) {
if ( V_2 -> V_278 && F_21 ( V_12 ) &&
! ( V_12 -> V_33 & V_277 ) ) {
-- V_12 -> V_197 ;
}
V_12 = NULL ;
break;
} else if ( V_10 == V_281 ) {
V_12 -> V_33 |= V_34 ;
F_271 ( V_12 ) ;
F_272 ( V_12 , - V_32 ) ;
} else {
F_17 ( V_246 L_21 , V_261 , V_10 ) ;
break;
}
}
return V_12 ;
}
void F_273 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_146 ( F_56 ( & V_12 -> V_13 ) ) ;
F_146 ( F_274 ( V_12 ) ) ;
F_275 ( & V_12 -> V_13 ) ;
if ( F_276 ( V_12 ) ) {
V_2 -> V_71 [ F_277 ( V_12 ) ] ++ ;
F_278 ( V_12 ) ;
}
}
void F_271 ( struct V_11 * V_186 )
{
F_273 ( V_186 ) ;
V_186 -> V_196 = F_21 ( V_186 ) ;
if ( F_12 ( F_279 ( V_186 ) ) )
V_186 -> V_282 -> V_196 = F_21 ( V_186 -> V_282 ) ;
F_146 ( F_11 ( V_283 , & V_186 -> V_284 ) ) ;
F_280 ( V_186 ) ;
}
struct V_11 * F_281 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_266 ( V_2 ) ;
if ( V_12 )
F_271 ( V_12 ) ;
return V_12 ;
}
bool F_282 ( struct V_11 * V_186 , int error , unsigned int V_285 )
{
int V_286 ;
if ( ! V_186 -> V_28 )
return false ;
F_283 ( V_186 -> V_2 , V_186 ) ;
if ( V_186 -> V_44 == V_213 )
V_186 -> V_216 = 0 ;
if ( error && V_186 -> V_44 == V_213 &&
! ( V_186 -> V_33 & V_34 ) ) {
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
case - V_32 :
default:
V_287 = L_28 ;
break;
}
F_135 ( V_246 L_29 ,
V_287 , V_186 -> V_42 ?
V_186 -> V_42 -> V_43 : L_2 ,
( unsigned long long ) F_18 ( V_186 ) ) ;
}
F_251 ( V_186 , V_285 ) ;
V_286 = 0 ;
while ( V_186 -> V_28 ) {
struct V_28 * V_28 = V_186 -> V_28 ;
unsigned V_294 = F_284 ( V_28 -> V_36 . V_37 , V_285 ) ;
if ( V_294 == V_28 -> V_36 . V_37 )
V_186 -> V_28 = V_28 -> V_200 ;
F_9 ( V_186 , V_28 , V_294 , error ) ;
V_286 += V_294 ;
V_285 -= V_294 ;
if ( ! V_285 )
break;
}
if ( ! V_186 -> V_28 ) {
V_186 -> V_195 = 0 ;
return false ;
}
V_186 -> V_195 -= V_286 ;
V_186 -> V_46 = F_181 ( V_186 -> V_28 ) ;
if ( V_186 -> V_44 == V_213 )
V_186 -> V_16 += V_286 >> 9 ;
if ( V_186 -> V_33 & V_263 ) {
V_186 -> V_33 &= ~ V_199 ;
V_186 -> V_33 |= V_186 -> V_28 -> V_147 & V_199 ;
}
if ( F_21 ( V_186 ) < F_285 ( V_186 ) ) {
F_16 ( V_186 , L_30 ) ;
V_186 -> V_195 = F_285 ( V_186 ) ;
}
F_247 ( V_186 ) ;
return true ;
}
static bool F_286 ( struct V_11 * V_12 , int error ,
unsigned int V_285 ,
unsigned int V_295 )
{
if ( F_282 ( V_12 , error , V_285 ) )
return true ;
if ( F_12 ( F_279 ( V_12 ) ) &&
F_282 ( V_12 -> V_282 , error , V_295 ) )
return true ;
if ( F_287 ( V_12 -> V_2 ) )
F_288 ( V_12 -> V_42 ) ;
return false ;
}
void F_289 ( struct V_11 * V_186 )
{
struct V_1 * V_2 = V_186 -> V_2 ;
V_186 -> V_33 &= ~ V_277 ;
if ( V_2 -> V_132 )
V_2 -> V_132 ( V_2 , V_186 ) ;
}
static void F_290 ( struct V_11 * V_186 , int error )
{
if ( F_161 ( V_186 ) )
F_162 ( V_186 -> V_2 , V_186 ) ;
F_146 ( F_163 ( V_186 ) ) ;
if ( F_12 ( V_296 ) && V_186 -> V_44 == V_213 )
F_291 ( & V_186 -> V_2 -> V_7 ) ;
F_158 ( V_186 ) ;
if ( V_186 -> V_33 & V_277 )
F_289 ( V_186 ) ;
F_257 ( V_186 ) ;
if ( V_186 -> V_245 )
V_186 -> V_245 ( V_186 , error ) ;
else {
if ( F_279 ( V_186 ) )
F_175 ( V_186 -> V_282 -> V_2 , V_186 -> V_282 ) ;
F_175 ( V_186 -> V_2 , V_186 ) ;
}
}
static bool F_292 ( struct V_11 * V_12 , int error ,
unsigned int V_285 , unsigned int V_295 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_63 ;
if ( F_286 ( V_12 , error , V_285 , V_295 ) )
return true ;
F_48 ( V_2 -> V_51 , V_63 ) ;
F_290 ( V_12 , error ) ;
F_49 ( V_2 -> V_51 , V_63 ) ;
return false ;
}
bool F_293 ( struct V_11 * V_12 , int error ,
unsigned int V_285 , unsigned int V_295 )
{
if ( F_286 ( V_12 , error , V_285 , V_295 ) )
return true ;
F_290 ( V_12 , error ) ;
return false ;
}
bool F_294 ( struct V_11 * V_12 , int error , unsigned int V_285 )
{
return F_292 ( V_12 , error , V_285 , 0 ) ;
}
void F_295 ( struct V_11 * V_12 , int error )
{
bool V_297 ;
unsigned int V_295 = 0 ;
if ( F_12 ( F_279 ( V_12 ) ) )
V_295 = F_21 ( V_12 -> V_282 ) ;
V_297 = F_292 ( V_12 , error , F_21 ( V_12 ) , V_295 ) ;
F_146 ( V_297 ) ;
}
bool F_296 ( struct V_11 * V_12 , int error )
{
return F_294 ( V_12 , error , F_285 ( V_12 ) ) ;
}
bool F_297 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_294 ( V_12 , error , F_250 ( V_12 ) ) ;
}
bool F_298 ( struct V_11 * V_12 , int error , unsigned int V_285 )
{
return F_293 ( V_12 , error , V_285 , 0 ) ;
}
void F_272 ( struct V_11 * V_12 , int error )
{
bool V_297 ;
unsigned int V_295 = 0 ;
if ( F_12 ( F_279 ( V_12 ) ) )
V_295 = F_21 ( V_12 -> V_282 ) ;
V_297 = F_293 ( V_12 , error , F_21 ( V_12 ) , V_295 ) ;
F_146 ( V_297 ) ;
}
bool F_299 ( struct V_11 * V_12 , int error )
{
return F_298 ( V_12 , error , F_285 ( V_12 ) ) ;
}
bool F_300 ( struct V_11 * V_12 , int error )
{
F_33 ( error >= 0 ) ;
return F_298 ( V_12 , error , F_250 ( V_12 ) ) ;
}
void F_197 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_28 * V_28 )
{
V_12 -> V_33 |= V_28 -> V_147 & V_298 ;
if ( F_239 ( V_28 ) ) {
V_12 -> V_197 = F_301 ( V_2 , V_28 ) ;
V_12 -> V_46 = F_181 ( V_28 ) ;
}
V_12 -> V_195 = V_28 -> V_36 . V_37 ;
V_12 -> V_28 = V_12 -> V_45 = V_28 ;
if ( V_28 -> V_226 )
V_12 -> V_42 = V_28 -> V_226 -> V_299 ;
}
void F_302 ( struct V_11 * V_12 )
{
struct V_300 V_301 ;
struct V_302 V_303 ;
F_303 (bvec, rq, iter)
F_304 ( V_303 . V_190 ) ;
}
int F_305 ( struct V_1 * V_2 )
{
if ( V_2 -> V_304 )
return V_2 -> V_304 ( V_2 ) ;
return 0 ;
}
void F_306 ( struct V_11 * V_12 )
{
struct V_28 * V_28 ;
while ( ( V_28 = V_12 -> V_28 ) != NULL ) {
V_12 -> V_28 = V_28 -> V_200 ;
F_307 ( V_28 ) ;
}
}
static void F_308 ( struct V_11 * V_305 , struct V_11 * V_306 )
{
V_305 -> V_15 = V_306 -> V_15 ;
V_305 -> V_33 = ( V_306 -> V_33 & V_307 ) | V_308 ;
V_305 -> V_44 = V_306 -> V_44 ;
V_305 -> V_16 = F_18 ( V_306 ) ;
V_305 -> V_195 = F_21 ( V_306 ) ;
V_305 -> V_197 = V_306 -> V_197 ;
V_305 -> V_201 = V_306 -> V_201 ;
V_305 -> V_309 = V_306 -> V_309 ;
}
int F_309 ( struct V_11 * V_12 , struct V_11 * V_310 ,
struct V_311 * V_312 , T_2 V_86 ,
int (* F_310)( struct V_28 * , struct V_28 * , void * ) ,
void * V_313 )
{
struct V_28 * V_28 , * V_314 ;
if ( ! V_312 )
V_312 = V_315 ;
F_4 ( NULL , V_12 ) ;
F_311 (bio_src, rq_src) {
V_28 = F_312 ( V_314 , V_86 , V_312 ) ;
if ( ! V_28 )
goto V_316;
if ( F_310 && F_310 ( V_28 , V_314 , V_313 ) )
goto V_316;
if ( V_12 -> V_28 ) {
V_12 -> V_45 -> V_200 = V_28 ;
V_12 -> V_45 = V_28 ;
} else
V_12 -> V_28 = V_12 -> V_45 = V_28 ;
}
F_308 ( V_12 , V_310 ) ;
return 0 ;
V_316:
if ( V_28 )
F_307 ( V_28 ) ;
F_306 ( V_12 ) ;
return - V_97 ;
}
int F_313 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
return F_314 ( V_53 , V_49 ) ;
}
int F_315 ( struct V_1 * V_2 ,
struct V_60 * V_317 , unsigned long V_318 )
{
return F_30 ( V_53 , V_317 , V_318 ) ;
}
void F_316 ( struct V_204 * V_205 )
{
struct V_319 * V_320 = V_151 ;
V_205 -> V_321 = V_322 ;
F_5 ( & V_205 -> V_209 ) ;
F_5 ( & V_205 -> V_208 ) ;
F_5 ( & V_205 -> V_323 ) ;
if ( ! V_320 -> V_205 ) {
V_320 -> V_205 = V_205 ;
}
}
static int F_317 ( void * V_324 , struct V_206 * V_325 , struct V_206 * V_232 )
{
struct V_11 * V_326 = F_23 ( V_325 , struct V_11 , V_13 ) ;
struct V_11 * V_327 = F_23 ( V_232 , struct V_11 , V_13 ) ;
return ! ( V_326 -> V_2 < V_327 -> V_2 ||
( V_326 -> V_2 == V_327 -> V_2 && F_18 ( V_326 ) < F_18 ( V_327 ) ) ) ;
}
static void F_318 ( struct V_1 * V_2 , unsigned int V_328 ,
bool V_329 )
__releases( V_2 -> V_51 )
{
F_319 ( V_2 , V_328 , ! V_329 ) ;
if ( V_329 )
F_45 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_320 ( V_2 -> V_51 ) ;
}
static void F_321 ( struct V_204 * V_205 , bool V_329 )
{
F_322 ( V_330 ) ;
while ( ! F_56 ( & V_205 -> V_323 ) ) {
F_323 ( & V_205 -> V_323 , & V_330 ) ;
while ( ! F_56 ( & V_330 ) ) {
struct V_331 * V_332 = F_324 ( & V_330 ,
struct V_331 ,
V_209 ) ;
F_325 ( & V_332 -> V_209 ) ;
V_332 -> V_333 ( V_332 , V_329 ) ;
}
}
}
struct V_331 * F_326 ( T_6 V_334 , void * V_313 ,
int V_335 )
{
struct V_204 * V_205 = V_151 -> V_205 ;
struct V_331 * V_332 ;
if ( ! V_205 )
return NULL ;
F_327 (cb, &plug->cb_list, list)
if ( V_332 -> V_333 == V_334 && V_332 -> V_313 == V_313 )
return V_332 ;
F_146 ( V_335 < sizeof( * V_332 ) ) ;
V_332 = F_96 ( V_335 , V_252 ) ;
if ( V_332 ) {
V_332 -> V_313 = V_313 ;
V_332 -> V_333 = V_334 ;
F_328 ( & V_332 -> V_209 , & V_205 -> V_323 ) ;
}
return V_332 ;
}
void F_207 ( struct V_204 * V_205 , bool V_329 )
{
struct V_1 * V_2 ;
unsigned long V_63 ;
struct V_11 * V_12 ;
F_322 ( V_209 ) ;
unsigned int V_328 ;
F_146 ( V_205 -> V_321 != V_322 ) ;
F_321 ( V_205 , V_329 ) ;
if ( ! F_56 ( & V_205 -> V_208 ) )
F_329 ( V_205 , V_329 ) ;
if ( F_56 ( & V_205 -> V_209 ) )
return;
F_323 ( & V_205 -> V_209 , & V_209 ) ;
F_330 ( NULL , & V_209 , F_317 ) ;
V_2 = NULL ;
V_328 = 0 ;
F_331 ( V_63 ) ;
while ( ! F_56 ( & V_209 ) ) {
V_12 = F_332 ( V_209 . V_336 ) ;
F_275 ( & V_12 -> V_13 ) ;
F_146 ( ! V_12 -> V_2 ) ;
if ( V_12 -> V_2 != V_2 ) {
if ( V_2 )
F_318 ( V_2 , V_328 , V_329 ) ;
V_2 = V_12 -> V_2 ;
V_328 = 0 ;
F_333 ( V_2 -> V_51 ) ;
}
if ( F_12 ( F_101 ( V_2 ) ) ) {
F_272 ( V_12 , - V_223 ) ;
continue;
}
if ( V_12 -> V_33 & ( V_148 | V_149 ) )
F_167 ( V_2 , V_12 , V_219 ) ;
else
F_167 ( V_2 , V_12 , V_337 ) ;
V_328 ++ ;
}
if ( V_2 )
F_318 ( V_2 , V_328 , V_329 ) ;
F_334 ( V_63 ) ;
}
void F_335 ( struct V_204 * V_205 )
{
F_207 ( V_205 , false ) ;
if ( V_205 == V_151 -> V_205 )
V_151 -> V_205 = NULL ;
}
void F_336 ( struct V_1 * V_2 , struct V_338 * V_168 )
{
V_2 -> V_168 = V_168 ;
V_2 -> V_268 = V_270 ;
F_337 ( V_2 -> V_168 , - 1 ) ;
F_338 ( V_2 -> V_168 ) ;
}
int F_339 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_24 ( V_2 -> V_51 ) ;
if ( V_2 -> V_185 ) {
V_10 = - V_339 ;
F_174 ( V_2 -> V_168 ) ;
} else {
V_2 -> V_268 = V_340 ;
}
F_26 ( V_2 -> V_51 ) ;
return V_10 ;
}
void F_340 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_51 ) ;
if ( ! V_100 ) {
V_2 -> V_268 = V_269 ;
} else {
V_2 -> V_268 = V_270 ;
F_174 ( V_2 -> V_168 ) ;
}
F_26 ( V_2 -> V_51 ) ;
}
void F_341 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_51 ) ;
V_2 -> V_268 = V_341 ;
F_26 ( V_2 -> V_51 ) ;
}
void F_342 ( struct V_1 * V_2 , int V_100 )
{
F_24 ( V_2 -> V_51 ) ;
if ( ! V_100 ) {
V_2 -> V_268 = V_270 ;
F_25 ( V_2 ) ;
F_174 ( V_2 -> V_168 ) ;
F_343 ( V_2 -> V_168 ) ;
} else {
V_2 -> V_268 = V_269 ;
}
F_26 ( V_2 -> V_51 ) ;
}
int T_4 F_344 ( void )
{
F_345 ( V_342 > 8 *
sizeof( ( (struct V_11 * ) 0 ) -> V_33 ) ) ;
V_53 = F_346 ( L_31 ,
V_343 | V_344 |
V_345 , 0 ) ;
if ( ! V_53 )
F_347 ( L_32 ) ;
V_95 = F_348 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_346 , NULL ) ;
V_101 = F_348 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_346 , NULL ) ;
return 0 ;
}
