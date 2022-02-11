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
F_36 ( V_58 , V_6 ) ;
F_37 ( V_6 ) ;
}
void F_38 ( struct V_11 * V_6 )
{
F_39 ( ! F_40 () ) ;
F_36 ( V_58 , V_6 ) ;
F_28 ( V_6 ) ;
}
void F_41 ( struct V_11 * V_6 )
{
F_42 ( & V_6 -> V_54 ) ;
F_43 ( V_58 , V_6 ) ;
}
void F_44 ( struct V_11 * V_6 )
{
F_45 ( & V_6 -> V_59 ) ;
if ( V_6 -> V_60 ) {
struct V_61 * V_62 ;
int V_63 ;
F_46 (q, hctx, i) {
F_47 ( & V_62 -> V_64 ) ;
F_47 ( & V_62 -> V_54 ) ;
}
} else {
F_47 ( & V_6 -> V_54 ) ;
}
}
inline void F_48 ( struct V_11 * V_6 )
{
if ( F_15 ( F_32 ( V_6 ) ) )
return;
V_6 -> V_65 ++ ;
V_6 -> V_66 ( V_6 ) ;
V_6 -> V_65 -- ;
}
void F_28 ( struct V_11 * V_6 )
{
if ( F_15 ( F_49 ( V_6 ) ) )
return;
F_48 ( V_6 ) ;
}
void F_37 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_49 ( V_6 ) && ! F_32 ( V_6 ) ) )
F_50 ( V_57 , & V_6 -> V_54 , 0 ) ;
}
void F_51 ( struct V_11 * V_6 )
{
unsigned long V_67 ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_28 ( V_6 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
}
void F_54 ( struct V_11 * V_6 )
{
F_55 ( & V_6 -> V_68 ) ;
}
static void F_56 ( struct V_11 * V_6 , bool V_69 )
__releases( V_6 -> V_55 )
__acquires( V_6 -> V_55 )
{
int V_63 ;
F_57 ( V_6 -> V_55 ) ;
while ( true ) {
bool V_70 = false ;
if ( V_6 -> V_71 )
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
if ( ! F_60 ( & V_6 -> V_72 ) && V_6 -> V_66 )
F_28 ( V_6 ) ;
V_70 |= V_6 -> V_73 ;
V_70 |= V_6 -> V_65 ;
if ( V_69 ) {
struct V_74 * V_75 = F_61 ( V_6 , NULL ) ;
V_70 |= ! F_60 ( & V_6 -> V_72 ) ;
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
V_70 |= V_6 -> V_76 [ V_63 ] ;
V_70 |= V_6 -> V_77 [ V_63 ] ;
if ( V_75 )
V_70 |= ! F_60 ( & V_75 -> V_78 [ V_63 ] ) ;
}
}
if ( ! V_70 )
break;
F_29 ( V_6 -> V_55 ) ;
F_62 ( 10 ) ;
F_27 ( V_6 -> V_55 ) ;
}
if ( V_6 -> V_66 ) {
struct V_1 * V_2 ;
F_63 (rl, q)
for ( V_63 = 0 ; V_63 < F_64 ( V_2 -> V_79 ) ; V_63 ++ )
F_65 ( & V_2 -> V_79 [ V_63 ] ) ;
}
}
void F_66 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_80 ++ ;
F_43 ( V_81 , V_6 ) ;
F_29 ( V_6 -> V_55 ) ;
if ( F_67 ( V_6 ) ) {
F_27 ( V_6 -> V_55 ) ;
F_56 ( V_6 , false ) ;
F_29 ( V_6 -> V_55 ) ;
F_68 () ;
}
}
void F_69 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
if ( ! -- V_6 -> V_80 )
F_36 ( V_81 , V_6 ) ;
F_70 ( V_6 -> V_80 < 0 ) ;
F_29 ( V_6 -> V_55 ) ;
}
void F_71 ( struct V_11 * V_6 )
{
F_72 ( V_82 , V_6 ) ;
if ( V_6 -> V_60 )
F_73 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_63 (rl, q) {
if ( V_2 -> V_83 ) {
F_74 ( & V_2 -> V_79 [ V_84 ] ) ;
F_74 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
}
}
void F_75 ( struct V_11 * V_6 )
{
T_1 * V_86 = V_6 -> V_55 ;
F_76 ( & V_6 -> V_87 ) ;
F_71 ( V_6 ) ;
F_27 ( V_86 ) ;
V_6 -> V_80 ++ ;
F_43 ( V_81 , V_6 ) ;
F_43 ( V_88 , V_6 ) ;
F_43 ( V_89 , V_6 ) ;
F_43 ( V_82 , V_6 ) ;
F_29 ( V_86 ) ;
F_77 ( & V_6 -> V_87 ) ;
F_78 ( V_6 ) ;
F_27 ( V_86 ) ;
if ( ! V_6 -> V_60 )
F_56 ( V_6 , true ) ;
F_43 ( V_90 , V_6 ) ;
F_29 ( V_86 ) ;
F_79 () ;
F_45 ( & V_6 -> V_8 . V_91 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_60 )
F_80 ( V_6 ) ;
F_81 ( & V_6 -> V_92 ) ;
F_27 ( V_86 ) ;
if ( V_6 -> V_55 != & V_6 -> V_93 )
V_6 -> V_55 = & V_6 -> V_93 ;
F_29 ( V_86 ) ;
F_82 ( & V_6 -> V_8 ) ;
F_54 ( V_6 ) ;
}
static void * F_83 ( T_2 V_94 , void * V_95 )
{
int V_96 = ( int ) ( long ) V_95 ;
return F_84 ( V_97 , V_94 , V_96 ) ;
}
static void F_85 ( void * V_98 , void * V_99 )
{
F_86 ( V_97 , V_98 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_94 )
{
if ( F_15 ( V_2 -> V_83 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_100 [ V_84 ] = V_2 -> V_100 [ V_85 ] = 0 ;
V_2 -> V_101 [ V_84 ] = V_2 -> V_101 [ V_85 ] = 0 ;
F_88 ( & V_2 -> V_79 [ V_84 ] ) ;
F_88 ( & V_2 -> V_79 [ V_85 ] ) ;
V_2 -> V_83 = F_89 ( V_102 , F_83 ,
F_85 ,
( void * ) ( long ) V_6 -> V_103 , V_94 ,
V_6 -> V_103 ) ;
if ( ! V_2 -> V_83 )
return - V_104 ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 )
F_91 ( V_2 -> V_83 ) ;
}
struct V_11 * F_92 ( T_2 V_94 )
{
return F_93 ( V_94 , V_105 ) ;
}
int F_94 ( struct V_11 * V_6 , T_2 V_106 )
{
while ( true ) {
int V_107 ;
if ( F_95 ( & V_6 -> V_92 ) )
return 0 ;
if ( ! F_96 ( V_106 ) )
return - V_108 ;
V_107 = F_97 ( V_6 -> V_109 ,
! F_98 ( & V_6 -> V_110 ) ||
F_99 ( V_6 ) ) ;
if ( F_99 ( V_6 ) )
return - V_111 ;
if ( V_107 )
return V_107 ;
}
}
void F_100 ( struct V_11 * V_6 )
{
F_101 ( & V_6 -> V_92 ) ;
}
static void F_102 ( struct V_112 * V_113 )
{
struct V_11 * V_6 =
F_26 ( V_113 , struct V_11 , V_92 ) ;
F_65 ( & V_6 -> V_109 ) ;
}
struct V_11 * F_93 ( T_2 V_94 , int V_114 )
{
struct V_11 * V_6 ;
int V_115 ;
V_6 = F_84 ( V_116 ,
V_94 | V_117 , V_114 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_118 = F_103 ( & V_119 , 0 , 0 , V_94 ) ;
if ( V_6 -> V_118 < 0 )
goto V_120;
V_6 -> V_121 = F_104 ( V_122 , 0 ) ;
if ( ! V_6 -> V_121 )
goto V_123;
V_6 -> V_8 . V_124 =
( V_125 * 1024 ) / V_126 ;
V_6 -> V_8 . V_127 = V_128 ;
V_6 -> V_8 . V_129 = L_8 ;
V_6 -> V_103 = V_114 ;
V_115 = F_105 ( & V_6 -> V_8 ) ;
if ( V_115 )
goto V_130;
F_106 ( & V_6 -> V_8 . V_91 ,
V_131 , ( unsigned long ) V_6 ) ;
F_106 ( & V_6 -> V_59 , V_132 , ( unsigned long ) V_6 ) ;
F_10 ( & V_6 -> V_72 ) ;
F_10 ( & V_6 -> V_21 ) ;
F_10 ( & V_6 -> V_133 ) ;
#ifdef F_107
F_10 ( & V_6 -> V_134 ) ;
#endif
F_108 ( & V_6 -> V_54 , F_25 ) ;
F_109 ( & V_6 -> V_68 , & V_135 ) ;
F_110 ( & V_6 -> V_87 ) ;
F_111 ( & V_6 -> V_93 ) ;
V_6 -> V_55 = & V_6 -> V_93 ;
V_6 -> V_80 = 1 ;
F_112 ( V_81 , & V_6 -> V_136 ) ;
F_88 ( & V_6 -> V_109 ) ;
if ( F_113 ( & V_6 -> V_92 ,
F_102 ,
V_137 , V_138 ) )
goto V_139;
if ( F_114 ( V_6 ) )
goto V_140;
return V_6 ;
V_140:
F_81 ( & V_6 -> V_92 ) ;
V_139:
F_115 ( & V_6 -> V_8 ) ;
V_130:
F_116 ( V_6 -> V_121 ) ;
V_123:
F_117 ( & V_119 , V_6 -> V_118 ) ;
V_120:
F_86 ( V_116 , V_6 ) ;
return NULL ;
}
struct V_11 * F_118 ( T_3 * V_141 , T_1 * V_86 )
{
return F_119 ( V_141 , V_86 , V_105 ) ;
}
struct V_11 *
F_119 ( T_3 * V_141 , T_1 * V_86 , int V_114 )
{
struct V_11 * V_142 , * V_6 ;
V_142 = F_93 ( V_138 , V_114 ) ;
if ( ! V_142 )
return NULL ;
V_6 = F_120 ( V_142 , V_141 , V_86 ) ;
if ( ! V_6 )
F_75 ( V_142 ) ;
return V_6 ;
}
struct V_11 *
F_120 ( struct V_11 * V_6 , T_3 * V_141 ,
T_1 * V_86 )
{
if ( ! V_6 )
return NULL ;
V_6 -> V_75 = F_121 ( V_6 , V_105 , 0 ) ;
if ( ! V_6 -> V_75 )
return NULL ;
if ( F_87 ( & V_6 -> V_7 , V_6 , V_138 ) )
goto V_143;
V_6 -> V_66 = V_141 ;
V_6 -> V_144 = NULL ;
V_6 -> V_145 = NULL ;
V_6 -> V_136 |= V_146 ;
if ( V_86 )
V_6 -> V_55 = V_86 ;
F_122 ( V_6 , V_147 ) ;
V_6 -> V_148 = V_149 ;
F_76 ( & V_6 -> V_87 ) ;
if ( F_123 ( V_6 , NULL ) ) {
F_77 ( & V_6 -> V_87 ) ;
goto V_143;
}
F_77 ( & V_6 -> V_87 ) ;
return V_6 ;
V_143:
F_124 ( V_6 -> V_75 ) ;
return NULL ;
}
bool F_125 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_99 ( V_6 ) ) ) {
F_126 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_127 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_38 & V_150 ) {
F_128 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_151 . V_152 )
F_129 ( V_19 -> V_151 . V_152 -> V_153 ) ;
}
F_130 ( V_19 , V_2 -> V_83 ) ;
}
static inline int F_131 ( struct V_11 * V_6 , struct V_154 * V_153 )
{
if ( ! V_153 )
return 0 ;
return V_153 -> V_155 == V_6 -> V_156 ||
( V_153 -> V_155 > 0
&& F_132 ( V_33 , V_153 -> V_157 + V_158 ) ) ;
}
static void F_133 ( struct V_11 * V_6 , struct V_154 * V_153 )
{
if ( ! V_153 || F_131 ( V_6 , V_153 ) )
return;
V_153 -> V_155 = V_6 -> V_156 ;
V_153 -> V_157 = V_33 ;
}
static void F_134 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_100 [ V_3 ] < F_135 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_100 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_136 ( & V_2 -> V_79 [ V_3 ] ) )
F_74 ( & V_2 -> V_79 [ V_3 ] ) ;
F_137 ( V_2 , V_3 ) ;
}
}
static void F_138 ( struct V_1 * V_2 , unsigned int V_67 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_3 = F_139 ( V_67 ) ;
V_6 -> V_76 [ V_3 ] -- ;
V_2 -> V_100 [ V_3 ] -- ;
if ( V_67 & V_150 )
V_6 -> V_73 -- ;
F_134 ( V_2 , V_3 ) ;
if ( F_15 ( V_2 -> V_101 [ V_3 ^ 1 ] ) )
F_134 ( V_2 , V_3 ^ 1 ) ;
}
int F_140 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_159 , V_160 ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_159 = F_141 ( V_6 ) ;
V_160 = F_135 ( V_6 ) ;
F_63 (rl, q) {
if ( V_2 -> V_100 [ V_84 ] >= V_159 )
F_4 ( V_2 , V_84 ) ;
else if ( V_2 -> V_100 [ V_84 ] < V_160 )
F_1 ( V_2 , V_84 ) ;
if ( V_2 -> V_100 [ V_85 ] >= V_159 )
F_4 ( V_2 , V_85 ) ;
else if ( V_2 -> V_100 [ V_85 ] < V_160 )
F_1 ( V_2 , V_85 ) ;
if ( V_2 -> V_100 [ V_84 ] >= V_6 -> V_13 ) {
F_142 ( V_2 , V_84 ) ;
} else {
F_137 ( V_2 , V_84 ) ;
F_74 ( & V_2 -> V_79 [ V_84 ] ) ;
}
if ( V_2 -> V_100 [ V_85 ] >= V_6 -> V_13 ) {
F_142 ( V_2 , V_85 ) ;
} else {
F_137 ( V_2 , V_85 ) ;
F_74 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
F_29 ( V_6 -> V_55 ) ;
return 0 ;
}
static bool F_143 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_161 & ( V_162 | V_163 ) )
return false ;
return true ;
}
static struct V_154 * F_144 ( struct V_35 * V_35 )
{
#ifdef F_107
if ( V_35 && V_35 -> V_164 )
return V_35 -> V_164 ;
#endif
return V_165 -> V_154 ;
}
static struct V_18 * F_145 ( struct V_1 * V_2 , int V_166 ,
struct V_35 * V_35 , T_2 V_94 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_167 * V_168 = V_6 -> V_71 -> type ;
struct V_154 * V_153 = F_144 ( V_35 ) ;
struct V_169 * V_152 = NULL ;
const bool V_170 = F_139 ( V_166 ) != 0 ;
int V_171 ;
if ( F_15 ( F_99 ( V_6 ) ) )
return F_146 ( - V_111 ) ;
V_171 = F_147 ( V_6 , V_166 ) ;
if ( V_171 == V_172 )
goto V_173;
if ( V_2 -> V_100 [ V_170 ] + 1 >= F_141 ( V_6 ) ) {
if ( V_2 -> V_100 [ V_170 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_148 ( V_2 , V_170 ) ) {
F_133 ( V_6 , V_153 ) ;
F_142 ( V_2 , V_170 ) ;
} else {
if ( V_171 != V_174
&& ! F_131 ( V_6 , V_153 ) ) {
return F_146 ( - V_104 ) ;
}
}
}
F_4 ( V_2 , V_170 ) ;
}
if ( V_2 -> V_100 [ V_170 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_146 ( - V_104 ) ;
V_6 -> V_76 [ V_170 ] ++ ;
V_2 -> V_100 [ V_170 ] ++ ;
V_2 -> V_101 [ V_170 ] = 0 ;
if ( F_143 ( V_35 ) && ! F_149 ( V_6 ) ) {
V_166 |= V_150 ;
V_6 -> V_73 ++ ;
if ( V_168 -> V_175 && V_153 )
V_152 = F_150 ( V_153 , V_6 ) ;
}
if ( F_151 ( V_6 ) )
V_166 |= V_176 ;
F_29 ( V_6 -> V_55 ) ;
V_19 = F_152 ( V_2 -> V_83 , V_94 ) ;
if ( ! V_19 )
goto V_177;
F_9 ( V_6 , V_19 ) ;
F_153 ( V_19 , V_2 ) ;
V_19 -> V_38 = V_166 | V_178 ;
if ( V_166 & V_150 ) {
if ( F_15 ( V_168 -> V_175 && ! V_152 ) ) {
if ( V_153 )
V_152 = F_154 ( V_153 , V_6 , V_94 ) ;
if ( ! V_152 )
goto V_179;
}
V_19 -> V_151 . V_152 = V_152 ;
if ( F_15 ( F_155 ( V_6 , V_19 , V_35 , V_94 ) ) )
goto V_179;
if ( V_152 )
F_156 ( V_152 -> V_153 ) ;
}
V_180:
if ( F_131 ( V_6 , V_153 ) )
V_153 -> V_155 -- ;
F_157 ( V_6 , V_35 , V_166 & 1 ) ;
return V_19 ;
V_179:
F_158 ( V_181 L_9 ,
V_182 , F_159 ( V_6 -> V_8 . V_183 ) ) ;
V_19 -> V_38 &= ~ V_150 ;
V_19 -> V_151 . V_152 = NULL ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_73 -- ;
F_29 ( V_6 -> V_55 ) ;
goto V_180;
V_177:
F_27 ( V_6 -> V_55 ) ;
F_138 ( V_2 , V_166 ) ;
V_173:
if ( F_15 ( V_2 -> V_100 [ V_170 ] == 0 ) )
V_2 -> V_101 [ V_170 ] = 1 ;
return F_146 ( - V_104 ) ;
}
static struct V_18 * F_160 ( struct V_11 * V_6 , int V_166 ,
struct V_35 * V_35 , T_2 V_94 )
{
const bool V_170 = F_139 ( V_166 ) != 0 ;
F_161 ( V_79 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_162 ( V_6 , V_35 ) ;
V_184:
V_19 = F_145 ( V_2 , V_166 , V_35 , V_94 ) ;
if ( ! F_163 ( V_19 ) )
return V_19 ;
if ( ! F_96 ( V_94 ) || F_15 ( F_99 ( V_6 ) ) ) {
F_164 ( V_2 ) ;
return V_19 ;
}
F_165 ( & V_2 -> V_79 [ V_170 ] , & V_79 ,
V_185 ) ;
F_166 ( V_6 , V_35 , V_166 & 1 ) ;
F_29 ( V_6 -> V_55 ) ;
F_167 () ;
F_133 ( V_6 , V_165 -> V_154 ) ;
F_27 ( V_6 -> V_55 ) ;
F_168 ( & V_2 -> V_79 [ V_170 ] , & V_79 ) ;
goto V_184;
}
static struct V_18 * F_169 ( struct V_11 * V_6 , int V_186 ,
T_2 V_94 )
{
struct V_18 * V_19 ;
F_170 ( V_186 != V_187 && V_186 != V_188 ) ;
F_171 ( V_94 , V_6 -> V_103 ) ;
F_27 ( V_6 -> V_55 ) ;
V_19 = F_160 ( V_6 , V_186 , NULL , V_94 ) ;
if ( F_163 ( V_19 ) )
F_29 ( V_6 -> V_55 ) ;
return V_19 ;
}
struct V_18 * F_172 ( struct V_11 * V_6 , int V_186 , T_2 V_94 )
{
if ( V_6 -> V_60 )
return F_173 ( V_6 , V_186 , V_94 , false ) ;
else
return F_169 ( V_6 , V_186 , V_94 ) ;
}
struct V_18 * F_174 ( struct V_11 * V_6 , struct V_35 * V_35 ,
T_2 V_94 )
{
struct V_18 * V_19 = F_172 ( V_6 , F_175 ( V_35 ) , V_94 ) ;
if ( F_163 ( V_19 ) )
return V_19 ;
F_176 ( V_19 ) ;
F_177 (bio) {
struct V_35 * V_189 = V_35 ;
int V_107 ;
F_178 ( V_6 , & V_189 ) ;
V_107 = F_179 ( V_6 , V_19 , V_189 ) ;
if ( F_15 ( V_107 ) ) {
F_180 ( V_19 ) ;
return F_146 ( V_107 ) ;
}
}
return V_19 ;
}
void F_176 ( struct V_18 * V_19 )
{
V_19 -> V_49 = V_51 ;
V_19 -> V_190 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_50 = NULL ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_181 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_182 ( V_19 ) ;
F_183 ( V_19 ) ;
F_184 ( V_6 , V_19 ) ;
if ( V_19 -> V_38 & V_191 )
F_185 ( V_6 , V_19 ) ;
F_170 ( F_186 ( V_19 ) ) ;
F_187 ( V_6 , V_19 ) ;
}
static void F_188 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_192 )
{
F_189 ( V_19 , true ) ;
F_190 ( V_6 , V_19 , V_192 ) ;
}
static void F_191 ( int V_22 , struct V_193 * V_34 ,
unsigned long V_194 )
{
int V_195 ;
if ( V_194 == V_34 -> V_196 )
return;
V_195 = F_192 ( V_34 ) ;
if ( V_195 ) {
F_193 ( V_22 , V_34 , V_197 ,
V_195 * ( V_194 - V_34 -> V_196 ) ) ;
F_193 ( V_22 , V_34 , V_198 , ( V_194 - V_34 -> V_196 ) ) ;
}
V_34 -> V_196 = V_194 ;
}
void F_194 ( int V_22 , struct V_193 * V_34 )
{
unsigned long V_194 = V_33 ;
if ( V_34 -> V_199 )
F_191 ( V_22 , & F_195 ( V_34 ) -> V_200 , V_194 ) ;
F_191 ( V_22 , V_34 , V_194 ) ;
}
static void F_196 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_183 && ! ( V_19 -> V_38 & V_201 ) && ! -- V_19 -> V_6 -> V_202 )
F_197 ( V_19 -> V_6 -> V_183 ) ;
}
static inline void F_196 ( struct V_18 * V_19 ) {}
void F_198 ( struct V_11 * V_6 , struct V_18 * V_203 )
{
if ( F_15 ( ! V_6 ) )
return;
if ( V_6 -> V_60 ) {
F_199 ( V_203 ) ;
return;
}
F_196 ( V_203 ) ;
F_200 ( V_6 , V_203 ) ;
F_39 ( V_203 -> V_35 != NULL ) ;
if ( V_203 -> V_38 & V_178 ) {
unsigned int V_67 = V_203 -> V_38 ;
struct V_1 * V_2 = F_201 ( V_203 ) ;
F_170 ( ! F_60 ( & V_203 -> V_20 ) ) ;
F_170 ( F_202 ( V_203 ) ) ;
F_127 ( V_2 , V_203 ) ;
F_138 ( V_2 , V_67 ) ;
F_164 ( V_2 ) ;
}
}
void F_180 ( struct V_18 * V_203 )
{
struct V_11 * V_6 = V_203 -> V_6 ;
if ( V_6 -> V_60 )
F_199 ( V_203 ) ;
else {
unsigned long V_67 ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_198 ( V_6 , V_203 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
}
}
void F_203 ( struct V_18 * V_19 , struct V_204 * V_204 ,
unsigned int V_205 )
{
struct V_35 * V_35 = V_19 -> V_35 ;
V_35 -> V_206 -> V_207 = V_204 ;
V_35 -> V_206 -> V_208 = 0 ;
V_35 -> V_206 -> V_209 = V_205 ;
V_35 -> V_41 . V_42 = V_205 ;
V_35 -> V_210 = 1 ;
V_35 -> V_211 = 1 ;
V_19 -> V_190 = V_19 -> V_212 = V_205 ;
V_19 -> V_213 = 1 ;
}
bool F_204 ( struct V_11 * V_6 , struct V_18 * V_203 ,
struct V_35 * V_35 )
{
const int V_214 = V_35 -> V_161 & V_215 ;
if ( ! F_205 ( V_6 , V_203 , V_35 ) )
return false ;
F_206 ( V_6 , V_203 , V_35 ) ;
if ( ( V_203 -> V_38 & V_215 ) != V_214 )
F_207 ( V_203 ) ;
V_203 -> V_50 -> V_216 = V_35 ;
V_203 -> V_50 = V_35 ;
V_203 -> V_190 += V_35 -> V_41 . V_42 ;
V_203 -> V_217 = F_208 ( V_203 -> V_217 , F_209 ( V_35 ) ) ;
F_189 ( V_203 , false ) ;
return true ;
}
bool F_210 ( struct V_11 * V_6 , struct V_18 * V_203 ,
struct V_35 * V_35 )
{
const int V_214 = V_35 -> V_161 & V_215 ;
if ( ! F_211 ( V_6 , V_203 , V_35 ) )
return false ;
F_212 ( V_6 , V_203 , V_35 ) ;
if ( ( V_203 -> V_38 & V_215 ) != V_214 )
F_207 ( V_203 ) ;
V_35 -> V_216 = V_203 -> V_35 ;
V_203 -> V_35 = V_35 ;
V_203 -> V_23 = V_35 -> V_41 . V_218 ;
V_203 -> V_190 += V_35 -> V_41 . V_42 ;
V_203 -> V_217 = F_208 ( V_203 -> V_217 , F_209 ( V_35 ) ) ;
F_189 ( V_203 , false ) ;
return true ;
}
bool F_213 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_219 ,
struct V_18 * * V_220 )
{
struct V_221 * V_222 ;
struct V_18 * V_19 ;
bool V_107 = false ;
struct V_223 * V_224 ;
V_222 = V_165 -> V_222 ;
if ( ! V_222 )
goto V_180;
* V_219 = 0 ;
if ( V_6 -> V_60 )
V_224 = & V_222 -> V_225 ;
else
V_224 = & V_222 -> V_226 ;
F_214 (rq, plug_list, queuelist) {
int V_227 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_219 ) ++ ;
if ( V_220 )
* V_220 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_215 ( V_19 , V_35 ) )
continue;
V_227 = F_216 ( V_19 , V_35 ) ;
if ( V_227 == V_228 ) {
V_107 = F_204 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
} else if ( V_227 == V_229 ) {
V_107 = F_210 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
}
}
V_180:
return V_107 ;
}
unsigned int F_217 ( struct V_11 * V_6 )
{
struct V_221 * V_222 ;
struct V_18 * V_19 ;
struct V_223 * V_224 ;
unsigned int V_107 = 0 ;
V_222 = V_165 -> V_222 ;
if ( ! V_222 )
goto V_180;
if ( V_6 -> V_60 )
V_224 = & V_222 -> V_225 ;
else
V_224 = & V_222 -> V_226 ;
F_218 (rq, plug_list, queuelist) {
if ( V_19 -> V_6 == V_6 )
V_107 ++ ;
}
V_180:
return V_107 ;
}
void F_219 ( struct V_18 * V_203 , struct V_35 * V_35 )
{
V_203 -> V_49 = V_230 ;
V_203 -> V_38 |= V_35 -> V_161 & V_231 ;
if ( V_35 -> V_161 & V_232 )
V_203 -> V_38 |= V_215 ;
V_203 -> V_233 = 0 ;
V_203 -> V_23 = V_35 -> V_41 . V_218 ;
V_203 -> V_217 = F_209 ( V_35 ) ;
F_220 ( V_203 -> V_6 , V_203 , V_35 ) ;
}
static T_4 V_147 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
const bool V_3 = ! ! ( V_35 -> V_161 & V_234 ) ;
struct V_221 * V_222 ;
int V_227 , V_166 , V_192 = V_235 ;
struct V_18 * V_203 ;
unsigned int V_219 = 0 ;
F_178 ( V_6 , & V_35 ) ;
F_221 ( V_6 , & V_35 , V_6 -> V_121 ) ;
if ( F_222 ( V_35 ) && F_223 ( V_35 ) ) {
V_35 -> V_37 = - V_236 ;
F_18 ( V_35 ) ;
return V_237 ;
}
if ( V_35 -> V_161 & ( V_162 | V_163 ) ) {
F_27 ( V_6 -> V_55 ) ;
V_192 = V_238 ;
goto V_239;
}
if ( ! F_224 ( V_6 ) ) {
if ( F_213 ( V_6 , V_35 , & V_219 , NULL ) )
return V_237 ;
} else
V_219 = F_217 ( V_6 ) ;
F_27 ( V_6 -> V_55 ) ;
V_227 = F_225 ( V_6 , & V_203 , V_35 ) ;
if ( V_227 == V_228 ) {
if ( F_204 ( V_6 , V_203 , V_35 ) ) {
F_226 ( V_6 , V_203 , V_35 ) ;
if ( ! F_227 ( V_6 , V_203 ) )
F_228 ( V_6 , V_203 , V_227 ) ;
goto V_240;
}
} else if ( V_227 == V_229 ) {
if ( F_210 ( V_6 , V_203 , V_35 ) ) {
F_226 ( V_6 , V_203 , V_35 ) ;
if ( ! F_229 ( V_6 , V_203 ) )
F_228 ( V_6 , V_203 , V_227 ) ;
goto V_240;
}
}
V_239:
V_166 = F_175 ( V_35 ) ;
if ( V_3 )
V_166 |= V_234 ;
V_203 = F_160 ( V_6 , V_166 , V_35 , V_241 ) ;
if ( F_163 ( V_203 ) ) {
V_35 -> V_37 = F_230 ( V_203 ) ;
F_18 ( V_35 ) ;
goto V_240;
}
F_219 ( V_203 , V_35 ) ;
if ( F_231 ( V_242 , & V_6 -> V_136 ) )
V_203 -> V_22 = F_232 () ;
V_222 = V_165 -> V_222 ;
if ( V_222 ) {
if ( ! V_219 )
F_233 ( V_6 ) ;
else {
if ( V_219 >= V_243 ) {
F_234 ( V_222 , false ) ;
F_233 ( V_6 ) ;
}
}
F_235 ( & V_203 -> V_20 , & V_222 -> V_226 ) ;
F_189 ( V_203 , true ) ;
} else {
F_27 ( V_6 -> V_55 ) ;
F_188 ( V_6 , V_203 , V_192 ) ;
F_28 ( V_6 ) ;
V_240:
F_29 ( V_6 -> V_55 ) ;
}
return V_237 ;
}
static inline void F_236 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_244 ;
if ( F_237 ( V_35 ) && V_17 != V_17 -> V_245 ) {
struct V_193 * V_246 = V_17 -> V_247 ;
V_35 -> V_41 . V_218 += V_246 -> V_248 ;
V_35 -> V_244 = V_17 -> V_245 ;
F_238 ( F_8 ( V_35 -> V_244 ) , V_35 ,
V_17 -> V_249 ,
V_35 -> V_41 . V_218 - V_246 -> V_248 ) ;
}
}
static void F_239 ( struct V_35 * V_35 )
{
char V_250 [ V_251 ] ;
F_20 ( V_46 L_10 ) ;
F_20 ( V_46 L_11 ,
F_240 ( V_35 -> V_244 , V_250 ) ,
V_35 -> V_161 ,
( unsigned long long ) F_241 ( V_35 ) ,
( long long ) ( F_242 ( V_35 -> V_244 -> V_252 ) >> 9 ) ) ;
}
static int T_5 F_243 ( char * V_253 )
{
return F_244 ( & V_254 , V_253 ) ;
}
static bool F_245 ( struct V_193 * V_34 , unsigned int V_255 )
{
return V_34 -> V_256 && F_246 ( & V_254 , V_255 ) ;
}
static int T_5 F_247 ( void )
{
struct V_257 * V_258 = F_248 ( L_12 ,
NULL , & V_254 ) ;
return F_249 ( V_258 ) ;
}
static inline bool F_245 ( struct V_193 * V_34 ,
unsigned int V_255 )
{
return false ;
}
static inline int F_250 ( struct V_35 * V_35 , unsigned int V_259 )
{
V_24 V_260 ;
if ( ! V_259 )
return 0 ;
V_260 = F_242 ( V_35 -> V_244 -> V_252 ) >> 9 ;
if ( V_260 ) {
V_24 V_261 = V_35 -> V_41 . V_218 ;
if ( V_260 < V_259 || V_260 - V_259 < V_261 ) {
F_239 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_6 bool
F_251 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_259 = F_237 ( V_35 ) ;
int V_115 = - V_236 ;
char V_250 [ V_251 ] ;
struct V_193 * V_34 ;
F_252 () ;
if ( F_250 ( V_35 , V_259 ) )
goto V_262;
V_6 = F_8 ( V_35 -> V_244 ) ;
if ( F_15 ( ! V_6 ) ) {
F_20 ( V_263
L_13
L_14 ,
F_240 ( V_35 -> V_244 , V_250 ) ,
( long long ) V_35 -> V_41 . V_218 ) ;
goto V_262;
}
V_34 = V_35 -> V_244 -> V_247 ;
if ( F_245 ( V_34 , V_35 -> V_41 . V_42 ) ||
F_245 ( & F_195 ( V_34 ) -> V_200 ,
V_35 -> V_41 . V_42 ) )
goto V_262;
F_236 ( V_35 ) ;
if ( F_250 ( V_35 , V_259 ) )
goto V_262;
if ( ( V_35 -> V_161 & ( V_162 | V_163 ) ) && ! V_6 -> V_264 ) {
V_35 -> V_161 &= ~ ( V_162 | V_163 ) ;
if ( ! V_259 ) {
V_115 = 0 ;
goto V_262;
}
}
if ( ( V_35 -> V_161 & V_265 ) &&
( ! F_253 ( V_6 ) ||
( ( V_35 -> V_161 & V_266 ) && ! F_254 ( V_6 ) ) ) ) {
V_115 = - V_267 ;
goto V_262;
}
if ( V_35 -> V_161 & V_268 && ! F_255 ( V_35 -> V_244 ) ) {
V_115 = - V_267 ;
goto V_262;
}
F_171 ( V_269 , V_6 -> V_103 ) ;
if ( ! F_256 ( V_6 , V_35 ) )
return false ;
F_257 ( V_6 , V_35 ) ;
return true ;
V_262:
V_35 -> V_37 = V_115 ;
F_18 ( V_35 ) ;
return false ;
}
T_4 F_258 ( struct V_35 * V_35 )
{
struct V_270 V_271 ;
T_4 V_107 = V_237 ;
if ( ! F_251 ( V_35 ) )
goto V_180;
if ( V_165 -> V_270 ) {
F_259 ( V_165 -> V_270 , V_35 ) ;
goto V_180;
}
F_170 ( V_35 -> V_216 ) ;
F_260 ( & V_271 ) ;
V_165 -> V_270 = & V_271 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_244 ) ;
if ( F_31 ( F_94 ( V_6 , V_272 ) == 0 ) ) {
V_107 = V_6 -> V_273 ( V_6 , V_35 ) ;
F_100 ( V_6 ) ;
V_35 = F_261 ( V_165 -> V_270 ) ;
} else {
struct V_35 * V_274 = F_261 ( V_165 -> V_270 ) ;
F_262 ( V_35 ) ;
V_35 = V_274 ;
}
} while ( V_35 );
V_165 -> V_270 = NULL ;
V_180:
return V_107 ;
}
T_4 F_263 ( int V_186 , struct V_35 * V_35 )
{
V_35 -> V_161 |= V_186 ;
if ( F_264 ( V_35 ) ) {
unsigned int V_100 ;
if ( F_15 ( V_186 & V_268 ) )
V_100 = F_265 ( V_35 -> V_244 ) >> 9 ;
else
V_100 = F_237 ( V_35 ) ;
if ( V_186 & V_188 ) {
F_266 ( V_275 , V_100 ) ;
} else {
F_267 ( V_35 -> V_41 . V_42 ) ;
F_266 ( V_276 , V_100 ) ;
}
if ( F_15 ( V_277 ) ) {
char V_250 [ V_251 ] ;
F_20 ( V_278 L_15 ,
V_165 -> V_279 , F_268 ( V_165 ) ,
( V_186 & V_188 ) ? L_16 : L_17 ,
( unsigned long long ) V_35 -> V_41 . V_218 ,
F_240 ( V_35 -> V_244 , V_250 ) ,
V_100 ) ;
}
}
return F_258 ( V_35 ) ;
}
static int F_269 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( F_22 ( V_19 ) > F_270 ( V_6 , V_19 -> V_38 ) ) {
F_20 ( V_263 L_18 , V_182 ) ;
return - V_236 ;
}
F_271 ( V_19 ) ;
if ( V_19 -> V_213 > F_272 ( V_6 ) ) {
F_20 ( V_263 L_19 , V_182 ) ;
return - V_236 ;
}
return 0 ;
}
int F_273 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_67 ;
int V_192 = V_280 ;
if ( F_269 ( V_6 , V_19 ) )
return - V_236 ;
if ( V_19 -> V_47 &&
F_245 ( & V_19 -> V_47 -> V_200 , F_24 ( V_19 ) ) )
return - V_236 ;
if ( V_6 -> V_60 ) {
if ( F_151 ( V_6 ) )
F_189 ( V_19 , true ) ;
F_274 ( V_19 , false , true , true ) ;
return 0 ;
}
F_52 ( V_6 -> V_55 , V_67 ) ;
if ( F_15 ( F_99 ( V_6 ) ) ) {
F_53 ( V_6 -> V_55 , V_67 ) ;
return - V_111 ;
}
F_170 ( F_186 ( V_19 ) ) ;
if ( V_19 -> V_38 & ( V_162 | V_163 ) )
V_192 = V_238 ;
F_188 ( V_6 , V_19 , V_192 ) ;
if ( V_192 == V_238 )
F_28 ( V_6 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return 0 ;
}
unsigned int F_275 ( const struct V_18 * V_19 )
{
unsigned int V_214 = V_19 -> V_38 & V_215 ;
unsigned int V_255 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_38 & V_281 ) )
return F_24 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_216 ) {
if ( ( V_35 -> V_161 & V_214 ) != V_214 )
break;
V_255 += V_35 -> V_41 . V_42 ;
}
F_170 ( F_24 ( V_19 ) && ! V_255 ) ;
return V_255 ;
}
void F_276 ( struct V_18 * V_203 , unsigned int V_255 )
{
if ( F_277 ( V_203 ) ) {
const int V_186 = F_278 ( V_203 ) ;
struct V_193 * V_34 ;
int V_22 ;
V_22 = F_279 () ;
V_34 = V_203 -> V_34 ;
F_280 ( V_22 , V_34 , V_282 [ V_186 ] , V_255 >> 9 ) ;
F_281 () ;
}
}
void F_282 ( struct V_18 * V_203 )
{
if ( F_277 ( V_203 ) && ! ( V_203 -> V_38 & V_43 ) ) {
unsigned long V_283 = V_33 - V_203 -> V_32 ;
const int V_186 = F_278 ( V_203 ) ;
struct V_193 * V_34 ;
int V_22 ;
V_22 = F_279 () ;
V_34 = V_203 -> V_34 ;
F_283 ( V_22 , V_34 , V_284 [ V_186 ] ) ;
F_280 ( V_22 , V_34 , V_285 [ V_186 ] , V_283 ) ;
F_194 ( V_22 , V_34 ) ;
F_284 ( V_34 , V_186 ) ;
F_285 ( V_34 ) ;
F_281 () ;
}
}
static struct V_18 * F_286 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_183 && ( V_6 -> V_286 == V_287 ||
( V_6 -> V_286 != V_288 && ! ( V_19 -> V_38 & V_201 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_286 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_189 ( struct V_18 * V_19 , bool V_289 )
{
struct V_193 * V_34 ;
int V_186 = F_278 ( V_19 ) ;
int V_22 ;
if ( ! F_277 ( V_19 ) )
return;
V_22 = F_279 () ;
if ( ! V_289 ) {
V_34 = V_19 -> V_34 ;
F_283 ( V_22 , V_34 , V_290 [ V_186 ] ) ;
} else {
V_34 = F_287 ( V_19 -> V_47 , F_21 ( V_19 ) ) ;
if ( ! F_288 ( V_34 ) ) {
V_34 = & V_19 -> V_47 -> V_200 ;
F_289 ( V_34 ) ;
}
F_194 ( V_22 , V_34 ) ;
F_290 ( V_34 , V_186 ) ;
V_19 -> V_34 = V_34 ;
}
F_281 () ;
}
struct V_18 * F_291 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
int V_107 ;
while ( ( V_19 = F_292 ( V_6 ) ) != NULL ) {
V_19 = F_286 ( V_6 , V_19 ) ;
if ( ! V_19 )
break;
if ( ! ( V_19 -> V_38 & V_291 ) ) {
if ( V_19 -> V_38 & V_292 )
F_293 ( V_6 , V_19 ) ;
V_19 -> V_38 |= V_291 ;
F_294 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_293 || V_6 -> V_293 == V_19 ) {
V_6 -> V_294 = F_295 ( V_19 ) ;
V_6 -> V_293 = NULL ;
}
if ( V_19 -> V_38 & V_295 )
break;
if ( V_6 -> V_296 && F_24 ( V_19 ) ) {
V_19 -> V_213 ++ ;
}
if ( ! V_6 -> V_144 )
break;
V_107 = V_6 -> V_144 ( V_6 , V_19 ) ;
if ( V_107 == V_297 ) {
break;
} else if ( V_107 == V_298 ) {
if ( V_6 -> V_296 && F_24 ( V_19 ) &&
! ( V_19 -> V_38 & V_295 ) ) {
-- V_19 -> V_213 ;
}
V_19 = NULL ;
break;
} else if ( V_107 == V_299 ) {
V_19 -> V_38 |= V_39 ;
F_296 ( V_19 ) ;
F_297 ( V_19 , - V_236 ) ;
} else {
F_20 ( V_263 L_20 , V_182 , V_107 ) ;
break;
}
}
return V_19 ;
}
void F_298 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_170 ( F_60 ( & V_19 -> V_20 ) ) ;
F_170 ( F_202 ( V_19 ) ) ;
F_299 ( & V_19 -> V_20 ) ;
if ( F_300 ( V_19 ) ) {
V_6 -> V_77 [ F_301 ( V_19 ) ] ++ ;
F_302 ( V_19 ) ;
}
}
void F_296 ( struct V_18 * V_203 )
{
F_298 ( V_203 ) ;
V_203 -> V_212 = F_24 ( V_203 ) ;
if ( F_15 ( F_303 ( V_203 ) ) )
V_203 -> V_300 -> V_212 = F_24 ( V_203 -> V_300 ) ;
F_170 ( F_231 ( V_301 , & V_203 -> V_302 ) ) ;
F_304 ( V_203 ) ;
}
struct V_18 * F_305 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_291 ( V_6 ) ;
if ( V_19 )
F_296 ( V_19 ) ;
return V_19 ;
}
bool F_306 ( struct V_18 * V_203 , int error , unsigned int V_303 )
{
int V_304 ;
F_307 ( V_203 -> V_6 , V_203 , V_303 ) ;
if ( ! V_203 -> V_35 )
return false ;
if ( V_203 -> V_49 == V_230 )
V_203 -> V_233 = 0 ;
if ( error && V_203 -> V_49 == V_230 &&
! ( V_203 -> V_38 & V_39 ) ) {
char * V_305 ;
switch ( error ) {
case - V_306 :
V_305 = L_21 ;
break;
case - V_307 :
V_305 = L_22 ;
break;
case - V_308 :
V_305 = L_23 ;
break;
case - V_309 :
V_305 = L_24 ;
break;
case - V_310 :
V_305 = L_25 ;
break;
case - V_311 :
V_305 = L_26 ;
break;
case - V_236 :
default:
V_305 = L_27 ;
break;
}
F_158 ( V_263 L_28 ,
V_182 , V_305 , V_203 -> V_47 ?
V_203 -> V_47 -> V_48 : L_2 ,
( unsigned long long ) F_21 ( V_203 ) ) ;
}
F_276 ( V_203 , V_303 ) ;
V_304 = 0 ;
while ( V_203 -> V_35 ) {
struct V_35 * V_35 = V_203 -> V_35 ;
unsigned V_312 = F_308 ( V_35 -> V_41 . V_42 , V_303 ) ;
if ( V_312 == V_35 -> V_41 . V_42 )
V_203 -> V_35 = V_35 -> V_216 ;
F_14 ( V_203 , V_35 , V_312 , error ) ;
V_304 += V_312 ;
V_303 -= V_312 ;
if ( ! V_303 )
break;
}
if ( ! V_203 -> V_35 ) {
V_203 -> V_190 = 0 ;
return false ;
}
V_203 -> V_190 -= V_304 ;
if ( V_203 -> V_49 == V_230 )
V_203 -> V_23 += V_304 >> 9 ;
if ( V_203 -> V_38 & V_281 ) {
V_203 -> V_38 &= ~ V_215 ;
V_203 -> V_38 |= V_203 -> V_35 -> V_161 & V_215 ;
}
if ( F_24 ( V_203 ) < F_309 ( V_203 ) ) {
F_19 ( V_203 , L_29 ) ;
V_203 -> V_190 = F_309 ( V_203 ) ;
}
F_271 ( V_203 ) ;
return true ;
}
static bool F_310 ( struct V_18 * V_19 , int error ,
unsigned int V_303 ,
unsigned int V_313 )
{
if ( F_306 ( V_19 , error , V_303 ) )
return true ;
if ( F_15 ( F_303 ( V_19 ) ) &&
F_306 ( V_19 -> V_300 , error , V_313 ) )
return true ;
if ( F_311 ( V_19 -> V_6 ) )
F_312 ( V_19 -> V_47 ) ;
return false ;
}
void F_313 ( struct V_18 * V_203 )
{
struct V_11 * V_6 = V_203 -> V_6 ;
V_203 -> V_38 &= ~ V_295 ;
if ( V_6 -> V_145 )
V_6 -> V_145 ( V_6 , V_203 ) ;
}
void F_314 ( struct V_18 * V_203 , int error )
{
if ( V_203 -> V_38 & V_191 )
F_185 ( V_203 -> V_6 , V_203 ) ;
F_170 ( F_186 ( V_203 ) ) ;
if ( F_15 ( V_314 ) && V_203 -> V_49 == V_230 )
F_315 ( & V_203 -> V_6 -> V_8 ) ;
F_182 ( V_203 ) ;
if ( V_203 -> V_38 & V_295 )
F_313 ( V_203 ) ;
F_282 ( V_203 ) ;
if ( V_203 -> V_262 )
V_203 -> V_262 ( V_203 , error ) ;
else {
if ( F_303 ( V_203 ) )
F_198 ( V_203 -> V_300 -> V_6 , V_203 -> V_300 ) ;
F_198 ( V_203 -> V_6 , V_203 ) ;
}
}
static bool F_316 ( struct V_18 * V_19 , int error ,
unsigned int V_303 , unsigned int V_313 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_67 ;
if ( F_310 ( V_19 , error , V_303 , V_313 ) )
return true ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_314 ( V_19 , error ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return false ;
}
bool F_317 ( struct V_18 * V_19 , int error ,
unsigned int V_303 , unsigned int V_313 )
{
if ( F_310 ( V_19 , error , V_303 , V_313 ) )
return true ;
F_314 ( V_19 , error ) ;
return false ;
}
bool F_318 ( struct V_18 * V_19 , int error , unsigned int V_303 )
{
return F_316 ( V_19 , error , V_303 , 0 ) ;
}
void F_319 ( struct V_18 * V_19 , int error )
{
bool V_315 ;
unsigned int V_313 = 0 ;
if ( F_15 ( F_303 ( V_19 ) ) )
V_313 = F_24 ( V_19 -> V_300 ) ;
V_315 = F_316 ( V_19 , error , F_24 ( V_19 ) , V_313 ) ;
F_170 ( V_315 ) ;
}
bool F_320 ( struct V_18 * V_19 , int error )
{
return F_318 ( V_19 , error , F_309 ( V_19 ) ) ;
}
bool F_321 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_318 ( V_19 , error , F_275 ( V_19 ) ) ;
}
bool F_322 ( struct V_18 * V_19 , int error , unsigned int V_303 )
{
return F_317 ( V_19 , error , V_303 , 0 ) ;
}
void F_297 ( struct V_18 * V_19 , int error )
{
bool V_315 ;
unsigned int V_313 = 0 ;
if ( F_15 ( F_303 ( V_19 ) ) )
V_313 = F_24 ( V_19 -> V_300 ) ;
V_315 = F_317 ( V_19 , error , F_24 ( V_19 ) , V_313 ) ;
F_170 ( V_315 ) ;
}
bool F_323 ( struct V_18 * V_19 , int error )
{
return F_322 ( V_19 , error , F_309 ( V_19 ) ) ;
}
bool F_324 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_322 ( V_19 , error , F_275 ( V_19 ) ) ;
}
void F_220 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
V_19 -> V_38 |= V_35 -> V_161 & V_316 ;
if ( F_264 ( V_35 ) )
V_19 -> V_213 = F_325 ( V_6 , V_35 ) ;
V_19 -> V_190 = V_35 -> V_41 . V_42 ;
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
if ( V_35 -> V_244 )
V_19 -> V_47 = V_35 -> V_244 -> V_317 ;
}
void F_326 ( struct V_18 * V_19 )
{
struct V_318 V_319 ;
struct V_320 V_321 ;
F_327 (bvec, rq, iter)
F_328 ( V_321 . V_207 ) ;
}
int F_329 ( struct V_11 * V_6 )
{
if ( V_6 -> V_322 )
return V_6 -> V_322 ( V_6 ) ;
return 0 ;
}
void F_330 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_216 ;
F_331 ( V_35 ) ;
}
}
static void F_332 ( struct V_18 * V_323 , struct V_18 * V_324 )
{
V_323 -> V_22 = V_324 -> V_22 ;
V_323 -> V_38 |= ( V_324 -> V_38 & V_325 ) | V_326 ;
V_323 -> V_49 = V_324 -> V_49 ;
V_323 -> V_23 = F_21 ( V_324 ) ;
V_323 -> V_190 = F_24 ( V_324 ) ;
V_323 -> V_213 = V_324 -> V_213 ;
V_323 -> V_217 = V_324 -> V_217 ;
V_323 -> V_327 = V_324 -> V_327 ;
}
int F_333 ( struct V_18 * V_19 , struct V_18 * V_328 ,
struct V_329 * V_330 , T_2 V_94 ,
int (* F_334)( struct V_35 * , struct V_35 * , void * ) ,
void * V_95 )
{
struct V_35 * V_35 , * V_331 ;
if ( ! V_330 )
V_330 = V_332 ;
F_335 (bio_src, rq_src) {
V_35 = F_336 ( V_331 , V_94 , V_330 ) ;
if ( ! V_35 )
goto V_333;
if ( F_334 && F_334 ( V_35 , V_331 , V_95 ) )
goto V_333;
if ( V_19 -> V_35 ) {
V_19 -> V_50 -> V_216 = V_35 ;
V_19 -> V_50 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
}
F_332 ( V_19 , V_328 ) ;
return 0 ;
V_333:
if ( V_35 )
F_331 ( V_35 ) ;
F_330 ( V_19 ) ;
return - V_104 ;
}
int F_337 ( struct V_52 * V_53 )
{
return F_338 ( V_57 , V_53 ) ;
}
int F_339 ( struct V_334 * V_335 ,
unsigned long V_336 )
{
return F_33 ( V_57 , V_335 , V_336 ) ;
}
int F_340 ( int V_22 , struct V_334 * V_335 ,
unsigned long V_336 )
{
return F_341 ( V_22 , V_57 , V_335 , V_336 ) ;
}
void F_342 ( struct V_221 * V_222 )
{
struct V_337 * V_338 = V_165 ;
if ( V_338 -> V_222 )
return;
F_10 ( & V_222 -> V_226 ) ;
F_10 ( & V_222 -> V_225 ) ;
F_10 ( & V_222 -> V_339 ) ;
V_338 -> V_222 = V_222 ;
}
static int F_343 ( void * V_340 , struct V_223 * V_341 , struct V_223 * V_250 )
{
struct V_18 * V_342 = F_26 ( V_341 , struct V_18 , V_20 ) ;
struct V_18 * V_343 = F_26 ( V_250 , struct V_18 , V_20 ) ;
return ! ( V_342 -> V_6 < V_343 -> V_6 ||
( V_342 -> V_6 == V_343 -> V_6 && F_21 ( V_342 ) < F_21 ( V_343 ) ) ) ;
}
static void F_344 ( struct V_11 * V_6 , unsigned int V_344 ,
bool V_345 )
__releases( V_6 -> V_55 )
{
F_345 ( V_6 , V_344 , ! V_345 ) ;
if ( V_345 )
F_37 ( V_6 ) ;
else
F_28 ( V_6 ) ;
F_346 ( V_6 -> V_55 ) ;
}
static void F_347 ( struct V_221 * V_222 , bool V_345 )
{
F_348 ( V_346 ) ;
while ( ! F_60 ( & V_222 -> V_339 ) ) {
F_349 ( & V_222 -> V_339 , & V_346 ) ;
while ( ! F_60 ( & V_346 ) ) {
struct V_347 * V_348 = F_350 ( & V_346 ,
struct V_347 ,
V_226 ) ;
F_351 ( & V_348 -> V_226 ) ;
V_348 -> V_349 ( V_348 , V_345 ) ;
}
}
}
struct V_347 * F_352 ( T_7 V_350 , void * V_95 ,
int V_351 )
{
struct V_221 * V_222 = V_165 -> V_222 ;
struct V_347 * V_348 ;
if ( ! V_222 )
return NULL ;
F_218 (cb, &plug->cb_list, list)
if ( V_348 -> V_349 == V_350 && V_348 -> V_95 == V_95 )
return V_348 ;
F_170 ( V_351 < sizeof( * V_348 ) ) ;
V_348 = F_353 ( V_351 , V_269 ) ;
if ( V_348 ) {
V_348 -> V_95 = V_95 ;
V_348 -> V_349 = V_350 ;
F_354 ( & V_348 -> V_226 , & V_222 -> V_339 ) ;
}
return V_348 ;
}
void F_234 ( struct V_221 * V_222 , bool V_345 )
{
struct V_11 * V_6 ;
unsigned long V_67 ;
struct V_18 * V_19 ;
F_348 ( V_226 ) ;
unsigned int V_344 ;
F_347 ( V_222 , V_345 ) ;
if ( ! F_60 ( & V_222 -> V_225 ) )
F_355 ( V_222 , V_345 ) ;
if ( F_60 ( & V_222 -> V_226 ) )
return;
F_349 ( & V_222 -> V_226 , & V_226 ) ;
F_356 ( NULL , & V_226 , F_343 ) ;
V_6 = NULL ;
V_344 = 0 ;
F_357 ( V_67 ) ;
while ( ! F_60 ( & V_226 ) ) {
V_19 = F_358 ( V_226 . V_352 ) ;
F_299 ( & V_19 -> V_20 ) ;
F_170 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_344 ( V_6 , V_344 , V_345 ) ;
V_6 = V_19 -> V_6 ;
V_344 = 0 ;
F_359 ( V_6 -> V_55 ) ;
}
if ( F_15 ( F_99 ( V_6 ) ) ) {
F_297 ( V_19 , - V_111 ) ;
continue;
}
if ( V_19 -> V_38 & ( V_162 | V_163 ) )
F_190 ( V_6 , V_19 , V_238 ) ;
else
F_190 ( V_6 , V_19 , V_353 ) ;
V_344 ++ ;
}
if ( V_6 )
F_344 ( V_6 , V_344 , V_345 ) ;
F_360 ( V_67 ) ;
}
void F_361 ( struct V_221 * V_222 )
{
if ( V_222 != V_165 -> V_222 )
return;
F_234 ( V_222 , false ) ;
V_165 -> V_222 = NULL ;
}
bool F_362 ( struct V_11 * V_6 , T_4 V_354 )
{
struct V_221 * V_222 ;
long V_355 ;
if ( ! V_6 -> V_60 || ! V_6 -> V_60 -> V_356 || ! F_363 ( V_354 ) ||
! F_231 ( V_357 , & V_6 -> V_136 ) )
return false ;
V_222 = V_165 -> V_222 ;
if ( V_222 )
F_234 ( V_222 , false ) ;
V_355 = V_165 -> V_355 ;
while ( ! F_364 () ) {
unsigned int V_358 = F_365 ( V_354 ) ;
struct V_61 * V_62 = V_6 -> V_359 [ V_358 ] ;
int V_107 ;
V_62 -> V_360 ++ ;
V_107 = V_6 -> V_60 -> V_356 ( V_62 , F_366 ( V_354 ) ) ;
if ( V_107 > 0 ) {
V_62 -> V_361 ++ ;
F_367 ( V_362 ) ;
return true ;
}
if ( F_368 ( V_355 , V_165 ) )
F_367 ( V_362 ) ;
if ( V_165 -> V_355 == V_362 )
return true ;
if ( V_107 < 0 )
break;
F_369 () ;
}
return false ;
}
void F_370 ( struct V_11 * V_6 , struct V_363 * V_183 )
{
V_6 -> V_183 = V_183 ;
V_6 -> V_286 = V_288 ;
F_371 ( V_6 -> V_183 , - 1 ) ;
F_372 ( V_6 -> V_183 ) ;
}
int F_373 ( struct V_11 * V_6 )
{
int V_107 = 0 ;
if ( ! V_6 -> V_183 )
return V_107 ;
F_27 ( V_6 -> V_55 ) ;
if ( V_6 -> V_202 ) {
V_107 = - V_108 ;
F_197 ( V_6 -> V_183 ) ;
} else {
V_6 -> V_286 = V_364 ;
}
F_29 ( V_6 -> V_55 ) ;
return V_107 ;
}
void F_374 ( struct V_11 * V_6 , int V_115 )
{
if ( ! V_6 -> V_183 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_115 ) {
V_6 -> V_286 = V_287 ;
} else {
V_6 -> V_286 = V_288 ;
F_197 ( V_6 -> V_183 ) ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_375 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_183 )
return;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_286 = V_365 ;
F_29 ( V_6 -> V_55 ) ;
}
void F_376 ( struct V_11 * V_6 , int V_115 )
{
if ( ! V_6 -> V_183 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_115 ) {
V_6 -> V_286 = V_288 ;
F_28 ( V_6 ) ;
F_197 ( V_6 -> V_183 ) ;
F_377 ( V_6 -> V_183 ) ;
} else {
V_6 -> V_286 = V_287 ;
}
F_29 ( V_6 -> V_55 ) ;
}
int T_5 F_378 ( void )
{
F_379 ( V_366 > 8 *
F_380 ( struct V_18 , V_38 ) ) ;
V_57 = F_381 ( L_30 ,
V_367 | V_368 , 0 ) ;
if ( ! V_57 )
F_382 ( L_31 ) ;
V_97 = F_383 ( L_32 ,
sizeof( struct V_18 ) , 0 , V_369 , NULL ) ;
V_116 = F_383 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_369 , NULL ) ;
return 0 ;
}
