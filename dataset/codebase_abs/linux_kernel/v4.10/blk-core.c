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
( unsigned long long ) V_19 -> V_50 ) ;
F_20 ( V_46 L_3 ,
( unsigned long long ) F_21 ( V_19 ) ,
F_22 ( V_19 ) , F_23 ( V_19 ) ) ;
F_20 ( V_46 L_4 ,
V_19 -> V_35 , V_19 -> V_51 , F_24 ( V_19 ) ) ;
if ( V_19 -> V_49 == V_52 ) {
F_20 ( V_46 L_5 ) ;
for ( V_45 = 0 ; V_45 < V_30 ; V_45 ++ )
F_20 ( L_6 , V_19 -> V_27 [ V_45 ] ) ;
F_20 ( L_7 ) ;
}
}
static void F_25 ( struct V_53 * V_54 )
{
struct V_11 * V_6 ;
V_6 = F_26 ( V_54 , struct V_11 , V_55 . V_54 ) ;
F_27 ( V_6 -> V_56 ) ;
F_28 ( V_6 ) ;
F_29 ( V_6 -> V_56 ) ;
}
void F_30 ( struct V_11 * V_6 , unsigned long V_57 )
{
if ( F_31 ( ! F_32 ( V_6 ) ) )
F_33 ( V_58 , & V_6 -> V_55 ,
F_34 ( V_57 ) ) ;
}
void F_35 ( struct V_11 * V_6 )
{
F_36 ( V_59 , V_6 ) ;
F_37 ( V_6 ) ;
}
void F_38 ( struct V_11 * V_6 )
{
F_39 ( ! F_40 () ) ;
F_36 ( V_59 , V_6 ) ;
F_28 ( V_6 ) ;
}
void F_41 ( struct V_11 * V_6 )
{
F_42 ( & V_6 -> V_55 ) ;
F_43 ( V_59 , V_6 ) ;
}
void F_44 ( struct V_11 * V_6 )
{
F_45 ( & V_6 -> V_60 ) ;
if ( V_6 -> V_61 ) {
struct V_62 * V_63 ;
int V_64 ;
F_46 (q, hctx, i) {
F_47 ( & V_63 -> V_65 ) ;
F_48 ( & V_63 -> V_55 ) ;
}
} else {
F_48 ( & V_6 -> V_55 ) ;
}
}
inline void F_49 ( struct V_11 * V_6 )
{
if ( F_15 ( F_32 ( V_6 ) ) )
return;
V_6 -> V_66 ++ ;
V_6 -> V_67 ( V_6 ) ;
V_6 -> V_66 -- ;
}
void F_28 ( struct V_11 * V_6 )
{
if ( F_15 ( F_50 ( V_6 ) ) )
return;
F_49 ( V_6 ) ;
}
void F_37 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_50 ( V_6 ) && ! F_32 ( V_6 ) ) )
F_51 ( V_58 , & V_6 -> V_55 , 0 ) ;
}
void F_52 ( struct V_11 * V_6 )
{
unsigned long V_68 ;
F_53 ( V_6 -> V_56 , V_68 ) ;
F_28 ( V_6 ) ;
F_54 ( V_6 -> V_56 , V_68 ) ;
}
void F_55 ( struct V_11 * V_6 )
{
F_56 ( & V_6 -> V_69 ) ;
}
static void F_57 ( struct V_11 * V_6 , bool V_70 )
__releases( V_6 -> V_56 )
__acquires( V_6 -> V_56 )
{
int V_64 ;
F_58 ( V_6 -> V_56 ) ;
while ( true ) {
bool V_71 = false ;
if ( V_6 -> V_72 )
F_59 ( V_6 ) ;
F_60 ( V_6 ) ;
if ( ! F_61 ( & V_6 -> V_73 ) && V_6 -> V_67 )
F_28 ( V_6 ) ;
V_71 |= V_6 -> V_74 ;
V_71 |= V_6 -> V_66 ;
if ( V_70 ) {
struct V_75 * V_76 = F_62 ( V_6 , NULL ) ;
V_71 |= ! F_61 ( & V_6 -> V_73 ) ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
V_71 |= V_6 -> V_77 [ V_64 ] ;
V_71 |= V_6 -> V_78 [ V_64 ] ;
if ( V_76 )
V_71 |= ! F_61 ( & V_76 -> V_79 [ V_64 ] ) ;
}
}
if ( ! V_71 )
break;
F_29 ( V_6 -> V_56 ) ;
F_63 ( 10 ) ;
F_27 ( V_6 -> V_56 ) ;
}
if ( V_6 -> V_67 ) {
struct V_1 * V_2 ;
F_64 (rl, q)
for ( V_64 = 0 ; V_64 < F_65 ( V_2 -> V_80 ) ; V_64 ++ )
F_66 ( & V_2 -> V_80 [ V_64 ] ) ;
}
}
void F_67 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_56 ) ;
V_6 -> V_81 ++ ;
F_43 ( V_82 , V_6 ) ;
F_29 ( V_6 -> V_56 ) ;
if ( F_68 ( V_6 ) ) {
F_27 ( V_6 -> V_56 ) ;
F_57 ( V_6 , false ) ;
F_29 ( V_6 -> V_56 ) ;
F_69 () ;
}
}
void F_70 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_56 ) ;
if ( ! -- V_6 -> V_81 )
F_36 ( V_82 , V_6 ) ;
F_71 ( V_6 -> V_81 < 0 ) ;
F_29 ( V_6 -> V_56 ) ;
}
void F_72 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_56 ) ;
F_43 ( V_83 , V_6 ) ;
F_29 ( V_6 -> V_56 ) ;
if ( V_6 -> V_61 )
F_73 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_64 (rl, q) {
if ( V_2 -> V_84 ) {
F_74 ( & V_2 -> V_80 [ V_85 ] ) ;
F_74 ( & V_2 -> V_80 [ V_86 ] ) ;
}
}
}
}
void F_75 ( struct V_11 * V_6 )
{
T_1 * V_87 = V_6 -> V_56 ;
F_76 ( & V_6 -> V_88 ) ;
F_72 ( V_6 ) ;
F_27 ( V_87 ) ;
V_6 -> V_81 ++ ;
F_43 ( V_82 , V_6 ) ;
F_43 ( V_89 , V_6 ) ;
F_43 ( V_90 , V_6 ) ;
F_43 ( V_83 , V_6 ) ;
F_29 ( V_87 ) ;
F_77 ( & V_6 -> V_88 ) ;
F_78 ( V_6 ) ;
F_27 ( V_87 ) ;
if ( ! V_6 -> V_61 )
F_57 ( V_6 , true ) ;
F_43 ( V_91 , V_6 ) ;
F_29 ( V_87 ) ;
F_79 () ;
F_45 ( & V_6 -> V_8 . V_92 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_61 )
F_80 ( V_6 ) ;
F_81 ( & V_6 -> V_93 ) ;
F_27 ( V_87 ) ;
if ( V_6 -> V_56 != & V_6 -> V_94 )
V_6 -> V_56 = & V_6 -> V_94 ;
F_29 ( V_87 ) ;
F_82 ( & V_6 -> V_8 ) ;
F_55 ( V_6 ) ;
}
static void * F_83 ( T_2 V_95 , void * V_96 )
{
int V_97 = ( int ) ( long ) V_96 ;
return F_84 ( V_98 , V_95 , V_97 ) ;
}
static void F_85 ( void * V_99 , void * V_100 )
{
F_86 ( V_98 , V_99 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_95 )
{
if ( F_15 ( V_2 -> V_84 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_101 [ V_85 ] = V_2 -> V_101 [ V_86 ] = 0 ;
V_2 -> V_102 [ V_85 ] = V_2 -> V_102 [ V_86 ] = 0 ;
F_88 ( & V_2 -> V_80 [ V_85 ] ) ;
F_88 ( & V_2 -> V_80 [ V_86 ] ) ;
V_2 -> V_84 = F_89 ( V_103 , F_83 ,
F_85 ,
( void * ) ( long ) V_6 -> V_104 , V_95 ,
V_6 -> V_104 ) ;
if ( ! V_2 -> V_84 )
return - V_105 ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 )
F_91 ( V_2 -> V_84 ) ;
}
struct V_11 * F_92 ( T_2 V_95 )
{
return F_93 ( V_95 , V_106 ) ;
}
int F_94 ( struct V_11 * V_6 , bool V_107 )
{
while ( true ) {
int V_108 ;
if ( F_95 ( & V_6 -> V_93 ) )
return 0 ;
if ( V_107 )
return - V_109 ;
V_108 = F_96 ( V_6 -> V_110 ,
! F_97 ( & V_6 -> V_111 ) ||
F_98 ( V_6 ) ) ;
if ( F_98 ( V_6 ) )
return - V_112 ;
if ( V_108 )
return V_108 ;
}
}
void F_99 ( struct V_11 * V_6 )
{
F_100 ( & V_6 -> V_93 ) ;
}
static void F_101 ( struct V_113 * V_114 )
{
struct V_11 * V_6 =
F_26 ( V_114 , struct V_11 , V_93 ) ;
F_66 ( & V_6 -> V_110 ) ;
}
static void F_102 ( unsigned long V_96 )
{
struct V_11 * V_6 = (struct V_11 * ) V_96 ;
F_103 ( & V_6 -> V_115 ) ;
}
struct V_11 * F_93 ( T_2 V_95 , int V_116 )
{
struct V_11 * V_6 ;
int V_117 ;
V_6 = F_84 ( V_118 ,
V_95 | V_119 , V_116 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_120 = F_104 ( & V_121 , 0 , 0 , V_95 ) ;
if ( V_6 -> V_120 < 0 )
goto V_122;
V_6 -> V_123 = F_105 ( V_124 , 0 ) ;
if ( ! V_6 -> V_123 )
goto V_125;
V_6 -> V_8 . V_126 =
( V_127 * 1024 ) / V_128 ;
V_6 -> V_8 . V_129 = V_130 ;
V_6 -> V_8 . V_131 = L_8 ;
V_6 -> V_104 = V_116 ;
V_117 = F_106 ( & V_6 -> V_8 ) ;
if ( V_117 )
goto V_132;
F_107 ( & V_6 -> V_8 . V_92 ,
V_133 , ( unsigned long ) V_6 ) ;
F_107 ( & V_6 -> V_60 , F_102 , ( unsigned long ) V_6 ) ;
F_10 ( & V_6 -> V_73 ) ;
F_10 ( & V_6 -> V_21 ) ;
F_10 ( & V_6 -> V_134 ) ;
#ifdef F_108
F_10 ( & V_6 -> V_135 ) ;
#endif
F_109 ( & V_6 -> V_55 , F_25 ) ;
F_110 ( & V_6 -> V_69 , & V_136 ) ;
F_111 ( & V_6 -> V_88 ) ;
F_112 ( & V_6 -> V_94 ) ;
V_6 -> V_56 = & V_6 -> V_94 ;
V_6 -> V_81 = 1 ;
F_113 ( V_82 , & V_6 -> V_137 ) ;
F_88 ( & V_6 -> V_110 ) ;
if ( F_114 ( & V_6 -> V_93 ,
F_101 ,
V_138 , V_139 ) )
goto V_140;
if ( F_115 ( V_6 ) )
goto V_141;
return V_6 ;
V_141:
F_81 ( & V_6 -> V_93 ) ;
V_140:
F_116 ( & V_6 -> V_8 ) ;
V_132:
F_117 ( V_6 -> V_123 ) ;
V_125:
F_118 ( & V_121 , V_6 -> V_120 ) ;
V_122:
F_86 ( V_118 , V_6 ) ;
return NULL ;
}
struct V_11 * F_119 ( T_3 * V_142 , T_1 * V_87 )
{
return F_120 ( V_142 , V_87 , V_106 ) ;
}
struct V_11 *
F_120 ( T_3 * V_142 , T_1 * V_87 , int V_116 )
{
struct V_11 * V_143 , * V_6 ;
V_143 = F_93 ( V_139 , V_116 ) ;
if ( ! V_143 )
return NULL ;
V_6 = F_121 ( V_143 , V_142 , V_87 ) ;
if ( ! V_6 )
F_75 ( V_143 ) ;
return V_6 ;
}
struct V_11 *
F_121 ( struct V_11 * V_6 , T_3 * V_142 ,
T_1 * V_87 )
{
if ( ! V_6 )
return NULL ;
V_6 -> V_76 = F_122 ( V_6 , V_106 , 0 ) ;
if ( ! V_6 -> V_76 )
return NULL ;
if ( F_87 ( & V_6 -> V_7 , V_6 , V_139 ) )
goto V_144;
F_123 ( & V_6 -> V_115 , V_145 ) ;
V_6 -> V_67 = V_142 ;
V_6 -> V_146 = NULL ;
V_6 -> V_147 = NULL ;
V_6 -> V_137 |= V_148 ;
if ( V_87 )
V_6 -> V_56 = V_87 ;
F_124 ( V_6 , V_149 ) ;
V_6 -> V_150 = V_151 ;
F_76 ( & V_6 -> V_88 ) ;
if ( F_125 ( V_6 , NULL ) ) {
F_77 ( & V_6 -> V_88 ) ;
goto V_144;
}
F_77 ( & V_6 -> V_88 ) ;
return V_6 ;
V_144:
F_126 ( V_6 -> V_76 ) ;
F_127 ( V_6 ) ;
return NULL ;
}
bool F_128 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_98 ( V_6 ) ) ) {
F_129 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_130 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_38 & V_152 ) {
F_131 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_153 . V_154 )
F_132 ( V_19 -> V_153 . V_154 -> V_155 ) ;
}
F_133 ( V_19 , V_2 -> V_84 ) ;
}
static inline int F_134 ( struct V_11 * V_6 , struct V_156 * V_155 )
{
if ( ! V_155 )
return 0 ;
return V_155 -> V_157 == V_6 -> V_158 ||
( V_155 -> V_157 > 0
&& F_135 ( V_33 , V_155 -> V_159 + V_160 ) ) ;
}
static void F_136 ( struct V_11 * V_6 , struct V_156 * V_155 )
{
if ( ! V_155 || F_134 ( V_6 , V_155 ) )
return;
V_155 -> V_157 = V_6 -> V_158 ;
V_155 -> V_159 = V_33 ;
}
static void F_137 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_101 [ V_3 ] < F_138 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_101 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_139 ( & V_2 -> V_80 [ V_3 ] ) )
F_74 ( & V_2 -> V_80 [ V_3 ] ) ;
F_140 ( V_2 , V_3 ) ;
}
}
static void F_141 ( struct V_1 * V_2 , bool V_3 ,
T_4 V_38 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
V_6 -> V_77 [ V_3 ] -- ;
V_2 -> V_101 [ V_3 ] -- ;
if ( V_38 & V_152 )
V_6 -> V_74 -- ;
F_137 ( V_2 , V_3 ) ;
if ( F_15 ( V_2 -> V_102 [ V_3 ^ 1 ] ) )
F_137 ( V_2 , V_3 ^ 1 ) ;
}
int F_142 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_161 , V_162 ;
F_27 ( V_6 -> V_56 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_161 = F_143 ( V_6 ) ;
V_162 = F_138 ( V_6 ) ;
F_64 (rl, q) {
if ( V_2 -> V_101 [ V_85 ] >= V_161 )
F_4 ( V_2 , V_85 ) ;
else if ( V_2 -> V_101 [ V_85 ] < V_162 )
F_1 ( V_2 , V_85 ) ;
if ( V_2 -> V_101 [ V_86 ] >= V_161 )
F_4 ( V_2 , V_86 ) ;
else if ( V_2 -> V_101 [ V_86 ] < V_162 )
F_1 ( V_2 , V_86 ) ;
if ( V_2 -> V_101 [ V_85 ] >= V_6 -> V_13 ) {
F_144 ( V_2 , V_85 ) ;
} else {
F_140 ( V_2 , V_85 ) ;
F_74 ( & V_2 -> V_80 [ V_85 ] ) ;
}
if ( V_2 -> V_101 [ V_86 ] >= V_6 -> V_13 ) {
F_144 ( V_2 , V_86 ) ;
} else {
F_140 ( V_2 , V_86 ) ;
F_74 ( & V_2 -> V_80 [ V_86 ] ) ;
}
}
F_29 ( V_6 -> V_56 ) ;
return 0 ;
}
static bool F_145 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_163 & ( V_164 | V_165 ) )
return false ;
return true ;
}
static struct V_156 * F_146 ( struct V_35 * V_35 )
{
#ifdef F_108
if ( V_35 && V_35 -> V_166 )
return V_35 -> V_166 ;
#endif
return V_167 -> V_156 ;
}
static struct V_18 * F_147 ( struct V_1 * V_2 , unsigned int V_168 ,
struct V_35 * V_35 , T_2 V_95 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_169 * V_170 = V_6 -> V_72 -> type ;
struct V_156 * V_155 = F_146 ( V_35 ) ;
struct V_171 * V_154 = NULL ;
const bool V_172 = F_148 ( V_168 ) ;
int V_173 ;
T_4 V_38 = V_174 ;
if ( F_15 ( F_98 ( V_6 ) ) )
return F_149 ( - V_112 ) ;
V_173 = F_150 ( V_6 , V_168 ) ;
if ( V_173 == V_175 )
goto V_176;
if ( V_2 -> V_101 [ V_172 ] + 1 >= F_143 ( V_6 ) ) {
if ( V_2 -> V_101 [ V_172 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_151 ( V_2 , V_172 ) ) {
F_136 ( V_6 , V_155 ) ;
F_144 ( V_2 , V_172 ) ;
} else {
if ( V_173 != V_177
&& ! F_134 ( V_6 , V_155 ) ) {
return F_149 ( - V_105 ) ;
}
}
}
F_4 ( V_2 , V_172 ) ;
}
if ( V_2 -> V_101 [ V_172 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_149 ( - V_105 ) ;
V_6 -> V_77 [ V_172 ] ++ ;
V_2 -> V_101 [ V_172 ] ++ ;
V_2 -> V_102 [ V_172 ] = 0 ;
if ( F_145 ( V_35 ) && ! F_152 ( V_6 ) ) {
V_38 |= V_152 ;
V_6 -> V_74 ++ ;
if ( V_170 -> V_178 && V_155 )
V_154 = F_153 ( V_155 , V_6 ) ;
}
if ( F_154 ( V_6 ) )
V_38 |= V_179 ;
F_29 ( V_6 -> V_56 ) ;
V_19 = F_155 ( V_2 -> V_84 , V_95 ) ;
if ( ! V_19 )
goto V_180;
F_9 ( V_6 , V_19 ) ;
F_156 ( V_19 , V_2 ) ;
F_157 ( V_19 , V_155 ) ;
V_19 -> V_50 = V_168 ;
V_19 -> V_38 = V_38 ;
if ( V_38 & V_152 ) {
if ( F_15 ( V_170 -> V_178 && ! V_154 ) ) {
if ( V_155 )
V_154 = F_158 ( V_155 , V_6 , V_95 ) ;
if ( ! V_154 )
goto V_181;
}
V_19 -> V_153 . V_154 = V_154 ;
if ( F_15 ( F_159 ( V_6 , V_19 , V_35 , V_95 ) ) )
goto V_181;
if ( V_154 )
F_160 ( V_154 -> V_155 ) ;
}
V_182:
if ( F_134 ( V_6 , V_155 ) )
V_155 -> V_157 -- ;
F_161 ( V_6 , V_35 , V_168 ) ;
return V_19 ;
V_181:
F_162 ( V_183 L_9 ,
V_184 , F_163 ( V_6 -> V_8 . V_185 ) ) ;
V_19 -> V_38 &= ~ V_152 ;
V_19 -> V_153 . V_154 = NULL ;
F_27 ( V_6 -> V_56 ) ;
V_6 -> V_74 -- ;
F_29 ( V_6 -> V_56 ) ;
goto V_182;
V_180:
F_27 ( V_6 -> V_56 ) ;
F_141 ( V_2 , V_172 , V_38 ) ;
V_176:
if ( F_15 ( V_2 -> V_101 [ V_172 ] == 0 ) )
V_2 -> V_102 [ V_172 ] = 1 ;
return F_149 ( - V_105 ) ;
}
static struct V_18 * F_164 ( struct V_11 * V_6 , unsigned int V_168 ,
struct V_35 * V_35 , T_2 V_95 )
{
const bool V_172 = F_148 ( V_168 ) ;
F_165 ( V_80 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_166 ( V_6 , V_35 ) ;
V_186:
V_19 = F_147 ( V_2 , V_168 , V_35 , V_95 ) ;
if ( ! F_167 ( V_19 ) )
return V_19 ;
if ( ! F_168 ( V_95 ) || F_15 ( F_98 ( V_6 ) ) ) {
F_169 ( V_2 ) ;
return V_19 ;
}
F_170 ( & V_2 -> V_80 [ V_172 ] , & V_80 ,
V_187 ) ;
F_171 ( V_6 , V_35 , V_168 ) ;
F_29 ( V_6 -> V_56 ) ;
F_172 () ;
F_136 ( V_6 , V_167 -> V_156 ) ;
F_27 ( V_6 -> V_56 ) ;
F_173 ( & V_2 -> V_80 [ V_172 ] , & V_80 ) ;
goto V_186;
}
static struct V_18 * F_174 ( struct V_11 * V_6 , int V_188 ,
T_2 V_95 )
{
struct V_18 * V_19 ;
F_175 ( V_188 != V_189 && V_188 != V_190 ) ;
F_176 ( V_95 , V_6 -> V_104 ) ;
F_27 ( V_6 -> V_56 ) ;
V_19 = F_164 ( V_6 , V_188 , NULL , V_95 ) ;
if ( F_167 ( V_19 ) ) {
F_29 ( V_6 -> V_56 ) ;
return V_19 ;
}
V_19 -> V_191 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_51 = NULL ;
return V_19 ;
}
struct V_18 * F_177 ( struct V_11 * V_6 , int V_188 , T_2 V_95 )
{
if ( V_6 -> V_61 )
return F_178 ( V_6 , V_188 ,
( V_95 & V_192 ) ?
0 : V_193 ) ;
else
return F_174 ( V_6 , V_188 , V_95 ) ;
}
void F_179 ( struct V_18 * V_19 )
{
V_19 -> V_49 = V_52 ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_180 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_181 ( V_19 ) ;
F_182 ( V_19 ) ;
F_183 ( V_6 , V_19 ) ;
F_184 ( V_6 -> V_194 , & V_19 -> V_195 ) ;
if ( V_19 -> V_38 & V_196 )
F_185 ( V_6 , V_19 ) ;
F_175 ( F_186 ( V_19 ) ) ;
F_187 ( V_6 , V_19 ) ;
}
static void F_188 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_197 )
{
F_189 ( V_19 , true ) ;
F_190 ( V_6 , V_19 , V_197 ) ;
}
static void F_191 ( int V_22 , struct V_198 * V_34 ,
unsigned long V_199 )
{
int V_200 ;
if ( V_199 == V_34 -> V_201 )
return;
V_200 = F_192 ( V_34 ) ;
if ( V_200 ) {
F_193 ( V_22 , V_34 , V_202 ,
V_200 * ( V_199 - V_34 -> V_201 ) ) ;
F_193 ( V_22 , V_34 , V_203 , ( V_199 - V_34 -> V_201 ) ) ;
}
V_34 -> V_201 = V_199 ;
}
void F_194 ( int V_22 , struct V_198 * V_34 )
{
unsigned long V_199 = V_33 ;
if ( V_34 -> V_204 )
F_191 ( V_22 , & F_195 ( V_34 ) -> V_205 , V_199 ) ;
F_191 ( V_22 , V_34 , V_199 ) ;
}
static void F_196 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_185 && ! ( V_19 -> V_38 & V_206 ) && ! -- V_19 -> V_6 -> V_207 )
F_197 ( V_19 -> V_6 -> V_185 ) ;
}
static inline void F_196 ( struct V_18 * V_19 ) {}
void F_198 ( struct V_11 * V_6 , struct V_18 * V_208 )
{
T_4 V_38 = V_208 -> V_38 ;
if ( F_15 ( ! V_6 ) )
return;
if ( V_6 -> V_61 ) {
F_199 ( V_208 ) ;
return;
}
F_196 ( V_208 ) ;
F_200 ( V_6 , V_208 ) ;
F_39 ( V_208 -> V_35 != NULL ) ;
F_201 ( V_6 -> V_194 , & V_208 -> V_195 ) ;
if ( V_38 & V_174 ) {
struct V_1 * V_2 = F_202 ( V_208 ) ;
bool V_3 = F_148 ( V_208 -> V_50 ) ;
F_175 ( ! F_61 ( & V_208 -> V_20 ) ) ;
F_175 ( F_203 ( V_208 ) ) ;
F_130 ( V_2 , V_208 ) ;
F_141 ( V_2 , V_3 , V_38 ) ;
F_169 ( V_2 ) ;
}
}
void F_204 ( struct V_18 * V_208 )
{
struct V_11 * V_6 = V_208 -> V_6 ;
if ( V_6 -> V_61 )
F_199 ( V_208 ) ;
else {
unsigned long V_68 ;
F_53 ( V_6 -> V_56 , V_68 ) ;
F_198 ( V_6 , V_208 ) ;
F_54 ( V_6 -> V_56 , V_68 ) ;
}
}
bool F_205 ( struct V_11 * V_6 , struct V_18 * V_208 ,
struct V_35 * V_35 )
{
const int V_209 = V_35 -> V_163 & V_210 ;
if ( ! F_206 ( V_6 , V_208 , V_35 ) )
return false ;
F_207 ( V_6 , V_208 , V_35 ) ;
if ( ( V_208 -> V_50 & V_210 ) != V_209 )
F_208 ( V_208 ) ;
V_208 -> V_51 -> V_211 = V_35 ;
V_208 -> V_51 = V_35 ;
V_208 -> V_191 += V_35 -> V_41 . V_42 ;
V_208 -> V_212 = F_209 ( V_208 -> V_212 , F_210 ( V_35 ) ) ;
F_189 ( V_208 , false ) ;
return true ;
}
bool F_211 ( struct V_11 * V_6 , struct V_18 * V_208 ,
struct V_35 * V_35 )
{
const int V_209 = V_35 -> V_163 & V_210 ;
if ( ! F_212 ( V_6 , V_208 , V_35 ) )
return false ;
F_213 ( V_6 , V_208 , V_35 ) ;
if ( ( V_208 -> V_50 & V_210 ) != V_209 )
F_208 ( V_208 ) ;
V_35 -> V_211 = V_208 -> V_35 ;
V_208 -> V_35 = V_35 ;
V_208 -> V_23 = V_35 -> V_41 . V_213 ;
V_208 -> V_191 += V_35 -> V_41 . V_42 ;
V_208 -> V_212 = F_209 ( V_208 -> V_212 , F_210 ( V_35 ) ) ;
F_189 ( V_208 , false ) ;
return true ;
}
bool F_214 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_214 ,
struct V_18 * * V_215 )
{
struct V_216 * V_217 ;
struct V_18 * V_19 ;
bool V_108 = false ;
struct V_218 * V_219 ;
V_217 = V_167 -> V_217 ;
if ( ! V_217 )
goto V_182;
* V_214 = 0 ;
if ( V_6 -> V_61 )
V_219 = & V_217 -> V_220 ;
else
V_219 = & V_217 -> V_221 ;
F_215 (rq, plug_list, queuelist) {
int V_222 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_214 ) ++ ;
if ( V_215 )
* V_215 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_216 ( V_19 , V_35 ) )
continue;
V_222 = F_217 ( V_19 , V_35 ) ;
if ( V_222 == V_223 ) {
V_108 = F_205 ( V_6 , V_19 , V_35 ) ;
if ( V_108 )
break;
} else if ( V_222 == V_224 ) {
V_108 = F_211 ( V_6 , V_19 , V_35 ) ;
if ( V_108 )
break;
}
}
V_182:
return V_108 ;
}
unsigned int F_218 ( struct V_11 * V_6 )
{
struct V_216 * V_217 ;
struct V_18 * V_19 ;
struct V_218 * V_219 ;
unsigned int V_108 = 0 ;
V_217 = V_167 -> V_217 ;
if ( ! V_217 )
goto V_182;
if ( V_6 -> V_61 )
V_219 = & V_217 -> V_220 ;
else
V_219 = & V_217 -> V_221 ;
F_219 (rq, plug_list, queuelist) {
if ( V_19 -> V_6 == V_6 )
V_108 ++ ;
}
V_182:
return V_108 ;
}
void F_220 ( struct V_18 * V_208 , struct V_35 * V_35 )
{
V_208 -> V_49 = V_225 ;
if ( V_35 -> V_163 & V_226 )
V_208 -> V_50 |= V_210 ;
V_208 -> V_227 = 0 ;
V_208 -> V_23 = V_35 -> V_41 . V_213 ;
if ( F_221 ( F_210 ( V_35 ) ) )
V_208 -> V_212 = F_210 ( V_35 ) ;
F_222 ( V_208 -> V_6 , V_208 , V_35 ) ;
}
static T_5 V_149 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
struct V_216 * V_217 ;
int V_222 , V_197 = V_228 ;
struct V_18 * V_208 ;
unsigned int V_214 = 0 ;
unsigned int V_229 ;
F_223 ( V_6 , & V_35 ) ;
F_224 ( V_6 , & V_35 , V_6 -> V_123 ) ;
if ( F_225 ( V_35 ) && F_226 ( V_35 ) ) {
V_35 -> V_37 = - V_230 ;
F_18 ( V_35 ) ;
return V_231 ;
}
if ( V_35 -> V_163 & ( V_164 | V_165 ) ) {
F_27 ( V_6 -> V_56 ) ;
V_197 = V_232 ;
goto V_233;
}
if ( ! F_227 ( V_6 ) ) {
if ( F_214 ( V_6 , V_35 , & V_214 , NULL ) )
return V_231 ;
} else
V_214 = F_218 ( V_6 ) ;
F_27 ( V_6 -> V_56 ) ;
V_222 = F_228 ( V_6 , & V_208 , V_35 ) ;
if ( V_222 == V_223 ) {
if ( F_205 ( V_6 , V_208 , V_35 ) ) {
F_229 ( V_6 , V_208 , V_35 ) ;
if ( ! F_230 ( V_6 , V_208 ) )
F_231 ( V_6 , V_208 , V_222 ) ;
goto V_234;
}
} else if ( V_222 == V_224 ) {
if ( F_211 ( V_6 , V_208 , V_35 ) ) {
F_229 ( V_6 , V_208 , V_35 ) ;
if ( ! F_232 ( V_6 , V_208 ) )
F_231 ( V_6 , V_208 , V_222 ) ;
goto V_234;
}
}
V_233:
V_229 = F_233 ( V_6 -> V_194 , V_35 , V_6 -> V_56 ) ;
V_208 = F_164 ( V_6 , V_35 -> V_163 , V_35 , V_235 ) ;
if ( F_167 ( V_208 ) ) {
F_234 ( V_6 -> V_194 , V_229 ) ;
V_35 -> V_37 = F_235 ( V_208 ) ;
F_18 ( V_35 ) ;
goto V_234;
}
F_236 ( & V_208 -> V_195 , V_229 ) ;
F_220 ( V_208 , V_35 ) ;
if ( F_237 ( V_236 , & V_6 -> V_137 ) )
V_208 -> V_22 = F_238 () ;
V_217 = V_167 -> V_217 ;
if ( V_217 ) {
if ( ! V_214 || F_61 ( & V_217 -> V_221 ) )
F_239 ( V_6 ) ;
else {
struct V_18 * V_237 = F_240 ( V_217 -> V_221 . V_238 ) ;
if ( V_214 >= V_239 ||
F_24 ( V_237 ) >= V_240 ) {
F_241 ( V_217 , false ) ;
F_239 ( V_6 ) ;
}
}
F_242 ( & V_208 -> V_20 , & V_217 -> V_221 ) ;
F_189 ( V_208 , true ) ;
} else {
F_27 ( V_6 -> V_56 ) ;
F_188 ( V_6 , V_208 , V_197 ) ;
F_28 ( V_6 ) ;
V_234:
F_29 ( V_6 -> V_56 ) ;
}
return V_231 ;
}
static inline void F_243 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_241 ;
if ( V_17 != V_17 -> V_242 &&
( F_244 ( V_35 ) || F_245 ( V_35 ) == V_243 ) ) {
struct V_198 * V_244 = V_17 -> V_245 ;
V_35 -> V_41 . V_213 += V_244 -> V_246 ;
V_35 -> V_241 = V_17 -> V_242 ;
F_246 ( F_8 ( V_35 -> V_241 ) , V_35 ,
V_17 -> V_247 ,
V_35 -> V_41 . V_213 - V_244 -> V_246 ) ;
}
}
static void F_247 ( struct V_35 * V_35 )
{
char V_248 [ V_249 ] ;
F_20 ( V_46 L_10 ) ;
F_20 ( V_46 L_11 ,
F_248 ( V_35 -> V_241 , V_248 ) ,
V_35 -> V_163 ,
( unsigned long long ) F_249 ( V_35 ) ,
( long long ) ( F_250 ( V_35 -> V_241 -> V_250 ) >> 9 ) ) ;
}
static int T_6 F_251 ( char * V_251 )
{
return F_252 ( & V_252 , V_251 ) ;
}
static bool F_253 ( struct V_198 * V_34 , unsigned int V_253 )
{
return V_34 -> V_254 && F_254 ( & V_252 , V_253 ) ;
}
static int T_6 F_255 ( void )
{
struct V_255 * V_256 = F_256 ( L_12 ,
NULL , & V_252 ) ;
return F_257 ( V_256 ) ;
}
static inline bool F_253 ( struct V_198 * V_34 ,
unsigned int V_253 )
{
return false ;
}
static inline int F_258 ( struct V_35 * V_35 , unsigned int V_257 )
{
V_24 V_258 ;
if ( ! V_257 )
return 0 ;
V_258 = F_250 ( V_35 -> V_241 -> V_250 ) >> 9 ;
if ( V_258 ) {
V_24 V_259 = V_35 -> V_41 . V_213 ;
if ( V_258 < V_257 || V_258 - V_257 < V_259 ) {
F_247 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_7 bool
F_259 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_257 = F_244 ( V_35 ) ;
int V_117 = - V_230 ;
char V_248 [ V_249 ] ;
struct V_198 * V_34 ;
F_260 () ;
if ( F_258 ( V_35 , V_257 ) )
goto V_260;
V_6 = F_8 ( V_35 -> V_241 ) ;
if ( F_15 ( ! V_6 ) ) {
F_20 ( V_261
L_13
L_14 ,
F_248 ( V_35 -> V_241 , V_248 ) ,
( long long ) V_35 -> V_41 . V_213 ) ;
goto V_260;
}
V_34 = V_35 -> V_241 -> V_245 ;
if ( F_253 ( V_34 , V_35 -> V_41 . V_42 ) ||
F_253 ( & F_195 ( V_34 ) -> V_205 ,
V_35 -> V_41 . V_42 ) )
goto V_260;
F_243 ( V_35 ) ;
if ( F_258 ( V_35 , V_257 ) )
goto V_260;
if ( ( V_35 -> V_163 & ( V_164 | V_165 ) ) &&
! F_237 ( V_262 , & V_6 -> V_137 ) ) {
V_35 -> V_163 &= ~ ( V_164 | V_165 ) ;
if ( ! V_257 ) {
V_117 = 0 ;
goto V_260;
}
}
switch ( F_245 ( V_35 ) ) {
case V_263 :
if ( ! F_261 ( V_6 ) )
goto V_264;
break;
case V_265 :
if ( ! F_262 ( V_6 ) )
goto V_264;
break;
case V_266 :
if ( ! F_263 ( V_35 -> V_241 ) )
goto V_264;
break;
case V_267 :
case V_243 :
if ( ! F_264 ( V_35 -> V_241 ) )
goto V_264;
break;
case V_268 :
if ( ! F_265 ( V_35 -> V_241 ) )
goto V_264;
break;
default:
break;
}
F_176 ( V_269 , V_6 -> V_104 ) ;
if ( ! F_266 ( V_6 , V_35 ) )
return false ;
F_267 ( V_6 , V_35 ) ;
return true ;
V_264:
V_117 = - V_270 ;
V_260:
V_35 -> V_37 = V_117 ;
F_18 ( V_35 ) ;
return false ;
}
T_5 F_268 ( struct V_35 * V_35 )
{
struct V_271 V_272 ;
T_5 V_108 = V_231 ;
if ( ! F_259 ( V_35 ) )
goto V_182;
if ( V_167 -> V_271 ) {
F_269 ( V_167 -> V_271 , V_35 ) ;
goto V_182;
}
F_175 ( V_35 -> V_211 ) ;
F_270 ( & V_272 ) ;
V_167 -> V_271 = & V_272 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_241 ) ;
if ( F_31 ( F_94 ( V_6 , false ) == 0 ) ) {
V_108 = V_6 -> V_273 ( V_6 , V_35 ) ;
F_99 ( V_6 ) ;
V_35 = F_271 ( V_167 -> V_271 ) ;
} else {
struct V_35 * V_274 = F_271 ( V_167 -> V_271 ) ;
F_272 ( V_35 ) ;
V_35 = V_274 ;
}
} while ( V_35 );
V_167 -> V_271 = NULL ;
V_182:
return V_108 ;
}
T_5 F_273 ( struct V_35 * V_35 )
{
if ( F_274 ( V_35 ) ) {
unsigned int V_101 ;
if ( F_15 ( F_245 ( V_35 ) == V_266 ) )
V_101 = F_275 ( V_35 -> V_241 ) >> 9 ;
else
V_101 = F_244 ( V_35 ) ;
if ( F_276 ( F_245 ( V_35 ) ) ) {
F_277 ( V_275 , V_101 ) ;
} else {
F_278 ( V_35 -> V_41 . V_42 ) ;
F_277 ( V_276 , V_101 ) ;
}
if ( F_15 ( V_277 ) ) {
char V_248 [ V_249 ] ;
F_20 ( V_278 L_15 ,
V_167 -> V_279 , F_279 ( V_167 ) ,
F_276 ( F_245 ( V_35 ) ) ? L_16 : L_17 ,
( unsigned long long ) V_35 -> V_41 . V_213 ,
F_248 ( V_35 -> V_241 , V_248 ) ,
V_101 ) ;
}
}
return F_268 ( V_35 ) ;
}
static int F_280 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( F_22 ( V_19 ) > F_281 ( V_6 , F_282 ( V_19 ) ) ) {
F_20 ( V_261 L_18 , V_184 ) ;
return - V_230 ;
}
F_283 ( V_19 ) ;
if ( V_19 -> V_280 > F_284 ( V_6 ) ) {
F_20 ( V_261 L_19 , V_184 ) ;
return - V_230 ;
}
return 0 ;
}
int F_285 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_68 ;
int V_197 = V_281 ;
if ( F_280 ( V_6 , V_19 ) )
return - V_230 ;
if ( V_19 -> V_47 &&
F_253 ( & V_19 -> V_47 -> V_205 , F_24 ( V_19 ) ) )
return - V_230 ;
if ( V_6 -> V_61 ) {
if ( F_154 ( V_6 ) )
F_189 ( V_19 , true ) ;
F_286 ( V_19 , false , true , false ) ;
return 0 ;
}
F_53 ( V_6 -> V_56 , V_68 ) ;
if ( F_15 ( F_98 ( V_6 ) ) ) {
F_54 ( V_6 -> V_56 , V_68 ) ;
return - V_112 ;
}
F_175 ( F_186 ( V_19 ) ) ;
if ( V_19 -> V_50 & ( V_164 | V_165 ) )
V_197 = V_232 ;
F_188 ( V_6 , V_19 , V_197 ) ;
if ( V_197 == V_232 )
F_28 ( V_6 ) ;
F_54 ( V_6 -> V_56 , V_68 ) ;
return 0 ;
}
unsigned int F_287 ( const struct V_18 * V_19 )
{
unsigned int V_209 = V_19 -> V_50 & V_210 ;
unsigned int V_253 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_38 & V_282 ) )
return F_24 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_211 ) {
if ( ( V_35 -> V_163 & V_209 ) != V_209 )
break;
V_253 += V_35 -> V_41 . V_42 ;
}
F_175 ( F_24 ( V_19 ) && ! V_253 ) ;
return V_253 ;
}
void F_288 ( struct V_18 * V_208 , unsigned int V_253 )
{
if ( F_289 ( V_208 ) ) {
const int V_188 = F_290 ( V_208 ) ;
struct V_198 * V_34 ;
int V_22 ;
V_22 = F_291 () ;
V_34 = V_208 -> V_34 ;
F_292 ( V_22 , V_34 , V_283 [ V_188 ] , V_253 >> 9 ) ;
F_293 () ;
}
}
void F_294 ( struct V_18 * V_208 )
{
if ( F_289 ( V_208 ) && ! ( V_208 -> V_38 & V_43 ) ) {
unsigned long V_284 = V_33 - V_208 -> V_32 ;
const int V_188 = F_290 ( V_208 ) ;
struct V_198 * V_34 ;
int V_22 ;
V_22 = F_291 () ;
V_34 = V_208 -> V_34 ;
F_295 ( V_22 , V_34 , V_285 [ V_188 ] ) ;
F_292 ( V_22 , V_34 , V_286 [ V_188 ] , V_284 ) ;
F_194 ( V_22 , V_34 ) ;
F_296 ( V_34 , V_188 ) ;
F_297 ( V_34 ) ;
F_293 () ;
}
}
static struct V_18 * F_298 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_185 && ( V_6 -> V_287 == V_288 ||
( V_6 -> V_287 != V_289 && ! ( V_19 -> V_38 & V_206 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_298 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_189 ( struct V_18 * V_19 , bool V_290 )
{
struct V_198 * V_34 ;
int V_188 = F_290 ( V_19 ) ;
int V_22 ;
if ( ! F_289 ( V_19 ) )
return;
V_22 = F_291 () ;
if ( ! V_290 ) {
V_34 = V_19 -> V_34 ;
F_295 ( V_22 , V_34 , V_291 [ V_188 ] ) ;
} else {
V_34 = F_299 ( V_19 -> V_47 , F_21 ( V_19 ) ) ;
if ( ! F_300 ( V_34 ) ) {
V_34 = & V_19 -> V_47 -> V_205 ;
F_301 ( V_34 ) ;
}
F_194 ( V_22 , V_34 ) ;
F_302 ( V_34 , V_188 ) ;
V_19 -> V_34 = V_34 ;
}
F_293 () ;
}
struct V_18 * F_303 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
int V_108 ;
while ( ( V_19 = F_304 ( V_6 ) ) != NULL ) {
V_19 = F_298 ( V_6 , V_19 ) ;
if ( ! V_19 )
break;
if ( ! ( V_19 -> V_38 & V_292 ) ) {
if ( V_19 -> V_38 & V_293 )
F_305 ( V_6 , V_19 ) ;
V_19 -> V_38 |= V_292 ;
F_306 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_294 || V_6 -> V_294 == V_19 ) {
V_6 -> V_295 = F_307 ( V_19 ) ;
V_6 -> V_294 = NULL ;
}
if ( V_19 -> V_38 & V_296 )
break;
if ( V_6 -> V_297 && F_24 ( V_19 ) ) {
V_19 -> V_280 ++ ;
}
if ( ! V_6 -> V_146 )
break;
V_108 = V_6 -> V_146 ( V_6 , V_19 ) ;
if ( V_108 == V_298 ) {
break;
} else if ( V_108 == V_299 ) {
if ( V_6 -> V_297 && F_24 ( V_19 ) &&
! ( V_19 -> V_38 & V_296 ) ) {
-- V_19 -> V_280 ;
}
V_19 = NULL ;
break;
} else if ( V_108 == V_300 || V_108 == V_301 ) {
int V_117 = ( V_108 == V_301 ) ? - V_302 : - V_230 ;
V_19 -> V_38 |= V_39 ;
F_308 ( V_19 ) ;
F_309 ( V_19 , V_117 ) ;
} else {
F_20 ( V_261 L_20 , V_184 , V_108 ) ;
break;
}
}
return V_19 ;
}
void F_310 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_175 ( F_61 ( & V_19 -> V_20 ) ) ;
F_175 ( F_203 ( V_19 ) ) ;
F_311 ( & V_19 -> V_20 ) ;
if ( F_312 ( V_19 ) ) {
V_6 -> V_78 [ F_313 ( V_19 ) ] ++ ;
F_314 ( V_19 ) ;
}
}
void F_308 ( struct V_18 * V_208 )
{
F_310 ( V_208 ) ;
if ( F_237 ( V_303 , & V_208 -> V_6 -> V_137 ) ) {
F_315 ( & V_208 -> V_195 ) ;
V_208 -> V_38 |= V_304 ;
F_316 ( V_208 -> V_6 -> V_194 , & V_208 -> V_195 ) ;
}
V_208 -> V_305 = F_24 ( V_208 ) ;
if ( F_15 ( F_317 ( V_208 ) ) )
V_208 -> V_306 -> V_305 = F_24 ( V_208 -> V_306 ) ;
F_175 ( F_237 ( V_307 , & V_208 -> V_308 ) ) ;
F_318 ( V_208 ) ;
}
struct V_18 * F_319 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_303 ( V_6 ) ;
if ( V_19 )
F_308 ( V_19 ) ;
return V_19 ;
}
bool F_320 ( struct V_18 * V_208 , int error , unsigned int V_309 )
{
int V_310 ;
F_321 ( V_208 -> V_6 , V_208 , V_309 ) ;
if ( ! V_208 -> V_35 )
return false ;
if ( V_208 -> V_49 == V_225 )
V_208 -> V_227 = 0 ;
if ( error && V_208 -> V_49 == V_225 &&
! ( V_208 -> V_38 & V_39 ) ) {
char * V_311 ;
switch ( error ) {
case - V_312 :
V_311 = L_21 ;
break;
case - V_302 :
V_311 = L_22 ;
break;
case - V_313 :
V_311 = L_23 ;
break;
case - V_314 :
V_311 = L_24 ;
break;
case - V_315 :
V_311 = L_25 ;
break;
case - V_316 :
V_311 = L_26 ;
break;
case - V_230 :
default:
V_311 = L_27 ;
break;
}
F_162 ( V_261 L_28 ,
V_184 , V_311 , V_208 -> V_47 ?
V_208 -> V_47 -> V_48 : L_2 ,
( unsigned long long ) F_21 ( V_208 ) ) ;
}
F_288 ( V_208 , V_309 ) ;
V_310 = 0 ;
while ( V_208 -> V_35 ) {
struct V_35 * V_35 = V_208 -> V_35 ;
unsigned V_317 = F_322 ( V_35 -> V_41 . V_42 , V_309 ) ;
if ( V_317 == V_35 -> V_41 . V_42 )
V_208 -> V_35 = V_35 -> V_211 ;
F_14 ( V_208 , V_35 , V_317 , error ) ;
V_310 += V_317 ;
V_309 -= V_317 ;
if ( ! V_309 )
break;
}
if ( ! V_208 -> V_35 ) {
V_208 -> V_191 = 0 ;
return false ;
}
F_71 ( V_208 -> V_38 & V_318 ) ;
V_208 -> V_191 -= V_310 ;
if ( V_208 -> V_49 == V_225 )
V_208 -> V_23 += V_310 >> 9 ;
if ( V_208 -> V_38 & V_282 ) {
V_208 -> V_50 &= ~ V_210 ;
V_208 -> V_50 |= V_208 -> V_35 -> V_163 & V_210 ;
}
if ( F_24 ( V_208 ) < F_323 ( V_208 ) ) {
F_19 ( V_208 , L_29 ) ;
V_208 -> V_191 = F_323 ( V_208 ) ;
}
F_283 ( V_208 ) ;
return true ;
}
static bool F_324 ( struct V_18 * V_19 , int error ,
unsigned int V_309 ,
unsigned int V_319 )
{
if ( F_320 ( V_19 , error , V_309 ) )
return true ;
if ( F_15 ( F_317 ( V_19 ) ) &&
F_320 ( V_19 -> V_306 , error , V_319 ) )
return true ;
if ( F_325 ( V_19 -> V_6 ) )
F_326 ( V_19 -> V_47 ) ;
return false ;
}
void F_327 ( struct V_18 * V_208 )
{
struct V_11 * V_6 = V_208 -> V_6 ;
V_208 -> V_38 &= ~ V_296 ;
if ( V_6 -> V_147 )
V_6 -> V_147 ( V_6 , V_208 ) ;
}
void F_328 ( struct V_18 * V_208 , int error )
{
struct V_11 * V_6 = V_208 -> V_6 ;
if ( V_208 -> V_38 & V_304 )
F_329 ( & V_6 -> V_320 [ F_290 ( V_208 ) ] , V_208 ) ;
if ( V_208 -> V_38 & V_196 )
F_185 ( V_6 , V_208 ) ;
F_175 ( F_186 ( V_208 ) ) ;
if ( F_15 ( V_321 ) && V_208 -> V_49 == V_225 )
F_330 ( & V_208 -> V_6 -> V_8 ) ;
F_181 ( V_208 ) ;
if ( V_208 -> V_38 & V_296 )
F_327 ( V_208 ) ;
F_294 ( V_208 ) ;
if ( V_208 -> V_260 ) {
F_201 ( V_208 -> V_6 -> V_194 , & V_208 -> V_195 ) ;
V_208 -> V_260 ( V_208 , error ) ;
} else {
if ( F_317 ( V_208 ) )
F_198 ( V_208 -> V_306 -> V_6 , V_208 -> V_306 ) ;
F_198 ( V_6 , V_208 ) ;
}
}
static bool F_331 ( struct V_18 * V_19 , int error ,
unsigned int V_309 , unsigned int V_319 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_68 ;
if ( F_324 ( V_19 , error , V_309 , V_319 ) )
return true ;
F_53 ( V_6 -> V_56 , V_68 ) ;
F_328 ( V_19 , error ) ;
F_54 ( V_6 -> V_56 , V_68 ) ;
return false ;
}
bool F_332 ( struct V_18 * V_19 , int error ,
unsigned int V_309 , unsigned int V_319 )
{
if ( F_324 ( V_19 , error , V_309 , V_319 ) )
return true ;
F_328 ( V_19 , error ) ;
return false ;
}
bool F_333 ( struct V_18 * V_19 , int error , unsigned int V_309 )
{
return F_331 ( V_19 , error , V_309 , 0 ) ;
}
void F_334 ( struct V_18 * V_19 , int error )
{
bool V_322 ;
unsigned int V_319 = 0 ;
if ( F_15 ( F_317 ( V_19 ) ) )
V_319 = F_24 ( V_19 -> V_306 ) ;
V_322 = F_331 ( V_19 , error , F_24 ( V_19 ) , V_319 ) ;
F_175 ( V_322 ) ;
}
bool F_335 ( struct V_18 * V_19 , int error )
{
return F_333 ( V_19 , error , F_323 ( V_19 ) ) ;
}
bool F_336 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_333 ( V_19 , error , F_287 ( V_19 ) ) ;
}
bool F_337 ( struct V_18 * V_19 , int error , unsigned int V_309 )
{
return F_332 ( V_19 , error , V_309 , 0 ) ;
}
void F_309 ( struct V_18 * V_19 , int error )
{
bool V_322 ;
unsigned int V_319 = 0 ;
if ( F_15 ( F_317 ( V_19 ) ) )
V_319 = F_24 ( V_19 -> V_306 ) ;
V_322 = F_332 ( V_19 , error , F_24 ( V_19 ) , V_319 ) ;
F_175 ( V_322 ) ;
}
bool F_338 ( struct V_18 * V_19 , int error )
{
return F_337 ( V_19 , error , F_323 ( V_19 ) ) ;
}
bool F_339 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_337 ( V_19 , error , F_287 ( V_19 ) ) ;
}
void F_222 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
if ( F_274 ( V_35 ) )
V_19 -> V_280 = F_340 ( V_6 , V_35 ) ;
V_19 -> V_191 = V_35 -> V_41 . V_42 ;
V_19 -> V_35 = V_19 -> V_51 = V_35 ;
if ( V_35 -> V_241 )
V_19 -> V_47 = V_35 -> V_241 -> V_323 ;
}
void F_341 ( struct V_18 * V_19 )
{
struct V_324 V_325 ;
struct V_326 V_327 ;
F_342 (bvec, rq, iter)
F_343 ( V_327 . V_328 ) ;
}
int F_344 ( struct V_11 * V_6 )
{
if ( V_6 -> V_329 )
return V_6 -> V_329 ( V_6 ) ;
return 0 ;
}
void F_345 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_211 ;
F_346 ( V_35 ) ;
}
}
static void F_347 ( struct V_18 * V_330 , struct V_18 * V_331 )
{
V_330 -> V_22 = V_331 -> V_22 ;
V_330 -> V_50 = V_331 -> V_50 | V_332 ;
V_330 -> V_49 = V_331 -> V_49 ;
V_330 -> V_23 = F_21 ( V_331 ) ;
V_330 -> V_191 = F_24 ( V_331 ) ;
V_330 -> V_280 = V_331 -> V_280 ;
V_330 -> V_212 = V_331 -> V_212 ;
V_330 -> V_333 = V_331 -> V_333 ;
}
int F_348 ( struct V_18 * V_19 , struct V_18 * V_334 ,
struct V_335 * V_336 , T_2 V_95 ,
int (* F_349)( struct V_35 * , struct V_35 * , void * ) ,
void * V_96 )
{
struct V_35 * V_35 , * V_337 ;
if ( ! V_336 )
V_336 = V_338 ;
F_350 (bio_src, rq_src) {
V_35 = F_351 ( V_337 , V_95 , V_336 ) ;
if ( ! V_35 )
goto V_339;
if ( F_349 && F_349 ( V_35 , V_337 , V_96 ) )
goto V_339;
if ( V_19 -> V_35 ) {
V_19 -> V_51 -> V_211 = V_35 ;
V_19 -> V_51 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_51 = V_35 ;
}
F_347 ( V_19 , V_334 ) ;
return 0 ;
V_339:
if ( V_35 )
F_346 ( V_35 ) ;
F_345 ( V_19 ) ;
return - V_105 ;
}
int F_103 ( struct V_53 * V_54 )
{
return F_352 ( V_58 , V_54 ) ;
}
int F_353 ( int V_22 , struct V_53 * V_54 )
{
return F_354 ( V_22 , V_58 , V_54 ) ;
}
int F_355 ( struct V_340 * V_341 ,
unsigned long V_342 )
{
return F_33 ( V_58 , V_341 , V_342 ) ;
}
int F_356 ( int V_22 , struct V_340 * V_341 ,
unsigned long V_342 )
{
return F_357 ( V_22 , V_58 , V_341 , V_342 ) ;
}
void F_358 ( struct V_216 * V_217 )
{
struct V_343 * V_344 = V_167 ;
if ( V_344 -> V_217 )
return;
F_10 ( & V_217 -> V_221 ) ;
F_10 ( & V_217 -> V_220 ) ;
F_10 ( & V_217 -> V_345 ) ;
V_344 -> V_217 = V_217 ;
}
static int F_359 ( void * V_346 , struct V_218 * V_347 , struct V_218 * V_248 )
{
struct V_18 * V_348 = F_26 ( V_347 , struct V_18 , V_20 ) ;
struct V_18 * V_349 = F_26 ( V_248 , struct V_18 , V_20 ) ;
return ! ( V_348 -> V_6 < V_349 -> V_6 ||
( V_348 -> V_6 == V_349 -> V_6 && F_21 ( V_348 ) < F_21 ( V_349 ) ) ) ;
}
static void F_360 ( struct V_11 * V_6 , unsigned int V_350 ,
bool V_351 )
__releases( V_6 -> V_56 )
{
F_361 ( V_6 , V_350 , ! V_351 ) ;
if ( V_351 )
F_37 ( V_6 ) ;
else
F_28 ( V_6 ) ;
F_362 ( V_6 -> V_56 ) ;
}
static void F_363 ( struct V_216 * V_217 , bool V_351 )
{
F_364 ( V_352 ) ;
while ( ! F_61 ( & V_217 -> V_345 ) ) {
F_365 ( & V_217 -> V_345 , & V_352 ) ;
while ( ! F_61 ( & V_352 ) ) {
struct V_353 * V_354 = F_366 ( & V_352 ,
struct V_353 ,
V_221 ) ;
F_367 ( & V_354 -> V_221 ) ;
V_354 -> V_355 ( V_354 , V_351 ) ;
}
}
}
struct V_353 * F_368 ( T_8 V_356 , void * V_96 ,
int V_357 )
{
struct V_216 * V_217 = V_167 -> V_217 ;
struct V_353 * V_354 ;
if ( ! V_217 )
return NULL ;
F_219 (cb, &plug->cb_list, list)
if ( V_354 -> V_355 == V_356 && V_354 -> V_96 == V_96 )
return V_354 ;
F_175 ( V_357 < sizeof( * V_354 ) ) ;
V_354 = F_369 ( V_357 , V_269 ) ;
if ( V_354 ) {
V_354 -> V_96 = V_96 ;
V_354 -> V_355 = V_356 ;
F_370 ( & V_354 -> V_221 , & V_217 -> V_345 ) ;
}
return V_354 ;
}
void F_241 ( struct V_216 * V_217 , bool V_351 )
{
struct V_11 * V_6 ;
unsigned long V_68 ;
struct V_18 * V_19 ;
F_364 ( V_221 ) ;
unsigned int V_350 ;
F_363 ( V_217 , V_351 ) ;
if ( ! F_61 ( & V_217 -> V_220 ) )
F_371 ( V_217 , V_351 ) ;
if ( F_61 ( & V_217 -> V_221 ) )
return;
F_365 ( & V_217 -> V_221 , & V_221 ) ;
F_372 ( NULL , & V_221 , F_359 ) ;
V_6 = NULL ;
V_350 = 0 ;
F_373 ( V_68 ) ;
while ( ! F_61 ( & V_221 ) ) {
V_19 = F_240 ( V_221 . V_358 ) ;
F_311 ( & V_19 -> V_20 ) ;
F_175 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_360 ( V_6 , V_350 , V_351 ) ;
V_6 = V_19 -> V_6 ;
V_350 = 0 ;
F_374 ( V_6 -> V_56 ) ;
}
if ( F_15 ( F_98 ( V_6 ) ) ) {
F_309 ( V_19 , - V_112 ) ;
continue;
}
if ( V_19 -> V_50 & ( V_164 | V_165 ) )
F_190 ( V_6 , V_19 , V_232 ) ;
else
F_190 ( V_6 , V_19 , V_359 ) ;
V_350 ++ ;
}
if ( V_6 )
F_360 ( V_6 , V_350 , V_351 ) ;
F_375 ( V_68 ) ;
}
void F_376 ( struct V_216 * V_217 )
{
if ( V_217 != V_167 -> V_217 )
return;
F_241 ( V_217 , false ) ;
V_167 -> V_217 = NULL ;
}
void F_377 ( struct V_11 * V_6 , struct V_360 * V_185 )
{
V_6 -> V_185 = V_185 ;
V_6 -> V_287 = V_289 ;
F_378 ( V_6 -> V_185 , - 1 ) ;
F_379 ( V_6 -> V_185 ) ;
}
int F_380 ( struct V_11 * V_6 )
{
int V_108 = 0 ;
if ( ! V_6 -> V_185 )
return V_108 ;
F_27 ( V_6 -> V_56 ) ;
if ( V_6 -> V_207 ) {
V_108 = - V_109 ;
F_197 ( V_6 -> V_185 ) ;
} else {
V_6 -> V_287 = V_361 ;
}
F_29 ( V_6 -> V_56 ) ;
return V_108 ;
}
void F_381 ( struct V_11 * V_6 , int V_117 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_56 ) ;
if ( ! V_117 ) {
V_6 -> V_287 = V_288 ;
} else {
V_6 -> V_287 = V_289 ;
F_197 ( V_6 -> V_185 ) ;
}
F_29 ( V_6 -> V_56 ) ;
}
void F_382 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_56 ) ;
V_6 -> V_287 = V_362 ;
F_29 ( V_6 -> V_56 ) ;
}
void F_383 ( struct V_11 * V_6 , int V_117 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_56 ) ;
if ( ! V_117 ) {
V_6 -> V_287 = V_289 ;
F_28 ( V_6 ) ;
F_197 ( V_6 -> V_185 ) ;
F_384 ( V_6 -> V_185 ) ;
} else {
V_6 -> V_287 = V_288 ;
}
F_29 ( V_6 -> V_56 ) ;
}
void F_385 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_56 ) ;
V_6 -> V_287 = V_289 ;
F_197 ( V_6 -> V_185 ) ;
F_384 ( V_6 -> V_185 ) ;
F_29 ( V_6 -> V_56 ) ;
}
int T_6 F_386 ( void )
{
F_387 ( V_363 >= ( 1 << V_364 ) ) ;
F_387 ( V_364 + V_365 > 8 *
F_388 ( struct V_18 , V_50 ) ) ;
F_387 ( V_364 + V_365 > 8 *
F_388 ( struct V_35 , V_163 ) ) ;
V_58 = F_389 ( L_30 ,
V_366 | V_367 , 0 ) ;
if ( ! V_58 )
F_390 ( L_31 ) ;
V_98 = F_391 ( L_32 ,
sizeof( struct V_18 ) , 0 , V_368 , NULL ) ;
V_118 = F_391 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_368 , NULL ) ;
return 0 ;
}
