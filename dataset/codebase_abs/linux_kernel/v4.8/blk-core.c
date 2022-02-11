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
F_27 ( V_6 -> V_55 ) ;
F_43 ( V_82 , V_6 ) ;
F_29 ( V_6 -> V_55 ) ;
if ( V_6 -> V_60 )
F_72 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_63 (rl, q) {
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
F_71 ( V_6 ) ;
F_27 ( V_86 ) ;
V_6 -> V_80 ++ ;
F_43 ( V_81 , V_6 ) ;
F_43 ( V_88 , V_6 ) ;
F_43 ( V_89 , V_6 ) ;
F_43 ( V_82 , V_6 ) ;
F_29 ( V_86 ) ;
F_76 ( & V_6 -> V_87 ) ;
F_77 ( V_6 ) ;
F_27 ( V_86 ) ;
if ( ! V_6 -> V_60 )
F_56 ( V_6 , true ) ;
F_43 ( V_90 , V_6 ) ;
F_29 ( V_86 ) ;
F_78 () ;
F_45 ( & V_6 -> V_8 . V_91 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_60 )
F_79 ( V_6 ) ;
F_80 ( & V_6 -> V_92 ) ;
F_27 ( V_86 ) ;
if ( V_6 -> V_55 != & V_6 -> V_93 )
V_6 -> V_55 = & V_6 -> V_93 ;
F_29 ( V_86 ) ;
F_81 ( & V_6 -> V_8 ) ;
F_54 ( V_6 ) ;
}
static void * F_82 ( T_2 V_94 , void * V_95 )
{
int V_96 = ( int ) ( long ) V_95 ;
return F_83 ( V_97 , V_94 , V_96 ) ;
}
static void F_84 ( void * V_98 , void * V_99 )
{
F_85 ( V_97 , V_98 ) ;
}
int F_86 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_94 )
{
if ( F_15 ( V_2 -> V_83 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_100 [ V_84 ] = V_2 -> V_100 [ V_85 ] = 0 ;
V_2 -> V_101 [ V_84 ] = V_2 -> V_101 [ V_85 ] = 0 ;
F_87 ( & V_2 -> V_79 [ V_84 ] ) ;
F_87 ( & V_2 -> V_79 [ V_85 ] ) ;
V_2 -> V_83 = F_88 ( V_102 , F_82 ,
F_84 ,
( void * ) ( long ) V_6 -> V_103 , V_94 ,
V_6 -> V_103 ) ;
if ( ! V_2 -> V_83 )
return - V_104 ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 )
F_90 ( V_2 -> V_83 ) ;
}
struct V_11 * F_91 ( T_2 V_94 )
{
return F_92 ( V_94 , V_105 ) ;
}
int F_93 ( struct V_11 * V_6 , bool V_106 )
{
while ( true ) {
int V_107 ;
if ( F_94 ( & V_6 -> V_92 ) )
return 0 ;
if ( V_106 )
return - V_108 ;
V_107 = F_95 ( V_6 -> V_109 ,
! F_96 ( & V_6 -> V_110 ) ||
F_97 ( V_6 ) ) ;
if ( F_97 ( V_6 ) )
return - V_111 ;
if ( V_107 )
return V_107 ;
}
}
void F_98 ( struct V_11 * V_6 )
{
F_99 ( & V_6 -> V_92 ) ;
}
static void F_100 ( struct V_112 * V_113 )
{
struct V_11 * V_6 =
F_26 ( V_113 , struct V_11 , V_92 ) ;
F_65 ( & V_6 -> V_109 ) ;
}
static void F_101 ( unsigned long V_95 )
{
struct V_11 * V_6 = (struct V_11 * ) V_95 ;
F_102 ( & V_6 -> V_114 ) ;
}
struct V_11 * F_92 ( T_2 V_94 , int V_115 )
{
struct V_11 * V_6 ;
int V_116 ;
V_6 = F_83 ( V_117 ,
V_94 | V_118 , V_115 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_119 = F_103 ( & V_120 , 0 , 0 , V_94 ) ;
if ( V_6 -> V_119 < 0 )
goto V_121;
V_6 -> V_122 = F_104 ( V_123 , 0 ) ;
if ( ! V_6 -> V_122 )
goto V_124;
V_6 -> V_8 . V_125 =
( V_126 * 1024 ) / V_127 ;
V_6 -> V_8 . V_128 = V_129 ;
V_6 -> V_8 . V_130 = L_8 ;
V_6 -> V_103 = V_115 ;
V_116 = F_105 ( & V_6 -> V_8 ) ;
if ( V_116 )
goto V_131;
F_106 ( & V_6 -> V_8 . V_91 ,
V_132 , ( unsigned long ) V_6 ) ;
F_106 ( & V_6 -> V_59 , F_101 , ( unsigned long ) V_6 ) ;
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
F_87 ( & V_6 -> V_109 ) ;
if ( F_113 ( & V_6 -> V_92 ,
F_100 ,
V_137 , V_138 ) )
goto V_139;
if ( F_114 ( V_6 ) )
goto V_140;
return V_6 ;
V_140:
F_80 ( & V_6 -> V_92 ) ;
V_139:
F_115 ( & V_6 -> V_8 ) ;
V_131:
F_116 ( V_6 -> V_122 ) ;
V_124:
F_117 ( & V_120 , V_6 -> V_119 ) ;
V_121:
F_85 ( V_117 , V_6 ) ;
return NULL ;
}
struct V_11 * F_118 ( T_3 * V_141 , T_1 * V_86 )
{
return F_119 ( V_141 , V_86 , V_105 ) ;
}
struct V_11 *
F_119 ( T_3 * V_141 , T_1 * V_86 , int V_115 )
{
struct V_11 * V_142 , * V_6 ;
V_142 = F_92 ( V_138 , V_115 ) ;
if ( ! V_142 )
return NULL ;
V_6 = F_120 ( V_142 , V_141 , V_86 ) ;
if ( ! V_6 )
F_74 ( V_142 ) ;
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
if ( F_86 ( & V_6 -> V_7 , V_6 , V_138 ) )
goto V_143;
F_122 ( & V_6 -> V_114 , V_144 ) ;
V_6 -> V_66 = V_141 ;
V_6 -> V_145 = NULL ;
V_6 -> V_146 = NULL ;
V_6 -> V_136 |= V_147 ;
if ( V_86 )
V_6 -> V_55 = V_86 ;
F_123 ( V_6 , V_148 ) ;
V_6 -> V_149 = V_150 ;
F_75 ( & V_6 -> V_87 ) ;
if ( F_124 ( V_6 , NULL ) ) {
F_76 ( & V_6 -> V_87 ) ;
goto V_143;
}
F_76 ( & V_6 -> V_87 ) ;
return V_6 ;
V_143:
F_125 ( V_6 -> V_75 ) ;
return NULL ;
}
bool F_126 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_97 ( V_6 ) ) ) {
F_127 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_128 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_38 & V_151 ) {
F_129 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_152 . V_153 )
F_130 ( V_19 -> V_152 . V_153 -> V_154 ) ;
}
F_131 ( V_19 , V_2 -> V_83 ) ;
}
static inline int F_132 ( struct V_11 * V_6 , struct V_155 * V_154 )
{
if ( ! V_154 )
return 0 ;
return V_154 -> V_156 == V_6 -> V_157 ||
( V_154 -> V_156 > 0
&& F_133 ( V_33 , V_154 -> V_158 + V_159 ) ) ;
}
static void F_134 ( struct V_11 * V_6 , struct V_155 * V_154 )
{
if ( ! V_154 || F_132 ( V_6 , V_154 ) )
return;
V_154 -> V_156 = V_6 -> V_157 ;
V_154 -> V_158 = V_33 ;
}
static void F_135 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_100 [ V_3 ] < F_136 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_100 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_137 ( & V_2 -> V_79 [ V_3 ] ) )
F_73 ( & V_2 -> V_79 [ V_3 ] ) ;
F_138 ( V_2 , V_3 ) ;
}
}
static void F_139 ( struct V_1 * V_2 , int V_160 , unsigned int V_67 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_3 = F_140 ( V_160 , V_67 ) ;
V_6 -> V_76 [ V_3 ] -- ;
V_2 -> V_100 [ V_3 ] -- ;
if ( V_67 & V_151 )
V_6 -> V_73 -- ;
F_135 ( V_2 , V_3 ) ;
if ( F_15 ( V_2 -> V_101 [ V_3 ^ 1 ] ) )
F_135 ( V_2 , V_3 ^ 1 ) ;
}
int F_141 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_161 , V_162 ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_161 = F_142 ( V_6 ) ;
V_162 = F_136 ( V_6 ) ;
F_63 (rl, q) {
if ( V_2 -> V_100 [ V_84 ] >= V_161 )
F_4 ( V_2 , V_84 ) ;
else if ( V_2 -> V_100 [ V_84 ] < V_162 )
F_1 ( V_2 , V_84 ) ;
if ( V_2 -> V_100 [ V_85 ] >= V_161 )
F_4 ( V_2 , V_85 ) ;
else if ( V_2 -> V_100 [ V_85 ] < V_162 )
F_1 ( V_2 , V_85 ) ;
if ( V_2 -> V_100 [ V_84 ] >= V_6 -> V_13 ) {
F_143 ( V_2 , V_84 ) ;
} else {
F_138 ( V_2 , V_84 ) ;
F_73 ( & V_2 -> V_79 [ V_84 ] ) ;
}
if ( V_2 -> V_100 [ V_85 ] >= V_6 -> V_13 ) {
F_143 ( V_2 , V_85 ) ;
} else {
F_138 ( V_2 , V_85 ) ;
F_73 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
F_29 ( V_6 -> V_55 ) ;
return 0 ;
}
static bool F_144 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_163 & ( V_164 | V_165 ) )
return false ;
return true ;
}
static struct V_155 * F_145 ( struct V_35 * V_35 )
{
#ifdef F_107
if ( V_35 && V_35 -> V_166 )
return V_35 -> V_166 ;
#endif
return V_167 -> V_155 ;
}
static struct V_18 * F_146 ( struct V_1 * V_2 , int V_160 ,
int V_168 , struct V_35 * V_35 ,
T_2 V_94 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_169 * V_170 = V_6 -> V_71 -> type ;
struct V_155 * V_154 = F_145 ( V_35 ) ;
struct V_171 * V_153 = NULL ;
const bool V_172 = F_140 ( V_160 , V_168 ) != 0 ;
int V_173 ;
if ( F_15 ( F_97 ( V_6 ) ) )
return F_147 ( - V_111 ) ;
V_173 = F_148 ( V_6 , V_160 , V_168 ) ;
if ( V_173 == V_174 )
goto V_175;
if ( V_2 -> V_100 [ V_172 ] + 1 >= F_142 ( V_6 ) ) {
if ( V_2 -> V_100 [ V_172 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_149 ( V_2 , V_172 ) ) {
F_134 ( V_6 , V_154 ) ;
F_143 ( V_2 , V_172 ) ;
} else {
if ( V_173 != V_176
&& ! F_132 ( V_6 , V_154 ) ) {
return F_147 ( - V_104 ) ;
}
}
}
F_4 ( V_2 , V_172 ) ;
}
if ( V_2 -> V_100 [ V_172 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_147 ( - V_104 ) ;
V_6 -> V_76 [ V_172 ] ++ ;
V_2 -> V_100 [ V_172 ] ++ ;
V_2 -> V_101 [ V_172 ] = 0 ;
if ( F_144 ( V_35 ) && ! F_150 ( V_6 ) ) {
V_168 |= V_151 ;
V_6 -> V_73 ++ ;
if ( V_170 -> V_177 && V_154 )
V_153 = F_151 ( V_154 , V_6 ) ;
}
if ( F_152 ( V_6 ) )
V_168 |= V_178 ;
F_29 ( V_6 -> V_55 ) ;
V_19 = F_153 ( V_2 -> V_83 , V_94 ) ;
if ( ! V_19 )
goto V_179;
F_9 ( V_6 , V_19 ) ;
F_154 ( V_19 , V_2 ) ;
F_155 ( V_19 , V_160 , V_168 | V_180 ) ;
if ( V_168 & V_151 ) {
if ( F_15 ( V_170 -> V_177 && ! V_153 ) ) {
if ( V_154 )
V_153 = F_156 ( V_154 , V_6 , V_94 ) ;
if ( ! V_153 )
goto V_181;
}
V_19 -> V_152 . V_153 = V_153 ;
if ( F_15 ( F_157 ( V_6 , V_19 , V_35 , V_94 ) ) )
goto V_181;
if ( V_153 )
F_158 ( V_153 -> V_154 ) ;
}
V_182:
if ( F_132 ( V_6 , V_154 ) )
V_154 -> V_156 -- ;
F_159 ( V_6 , V_35 , V_160 ) ;
return V_19 ;
V_181:
F_160 ( V_183 L_9 ,
V_184 , F_161 ( V_6 -> V_8 . V_185 ) ) ;
V_19 -> V_38 &= ~ V_151 ;
V_19 -> V_152 . V_153 = NULL ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_73 -- ;
F_29 ( V_6 -> V_55 ) ;
goto V_182;
V_179:
F_27 ( V_6 -> V_55 ) ;
F_139 ( V_2 , V_160 , V_168 ) ;
V_175:
if ( F_15 ( V_2 -> V_100 [ V_172 ] == 0 ) )
V_2 -> V_101 [ V_172 ] = 1 ;
return F_147 ( - V_104 ) ;
}
static struct V_18 * F_162 ( struct V_11 * V_6 , int V_160 ,
int V_168 , struct V_35 * V_35 ,
T_2 V_94 )
{
const bool V_172 = F_140 ( V_160 , V_168 ) != 0 ;
F_163 ( V_79 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_164 ( V_6 , V_35 ) ;
V_186:
V_19 = F_146 ( V_2 , V_160 , V_168 , V_35 , V_94 ) ;
if ( ! F_165 ( V_19 ) )
return V_19 ;
if ( ! F_166 ( V_94 ) || F_15 ( F_97 ( V_6 ) ) ) {
F_167 ( V_2 ) ;
return V_19 ;
}
F_168 ( & V_2 -> V_79 [ V_172 ] , & V_79 ,
V_187 ) ;
F_169 ( V_6 , V_35 , V_160 ) ;
F_29 ( V_6 -> V_55 ) ;
F_170 () ;
F_134 ( V_6 , V_167 -> V_155 ) ;
F_27 ( V_6 -> V_55 ) ;
F_171 ( & V_2 -> V_79 [ V_172 ] , & V_79 ) ;
goto V_186;
}
static struct V_18 * F_172 ( struct V_11 * V_6 , int V_188 ,
T_2 V_94 )
{
struct V_18 * V_19 ;
F_173 ( V_188 != V_189 && V_188 != V_190 ) ;
F_174 ( V_94 , V_6 -> V_103 ) ;
F_27 ( V_6 -> V_55 ) ;
V_19 = F_162 ( V_6 , V_188 , 0 , NULL , V_94 ) ;
if ( F_165 ( V_19 ) ) {
F_29 ( V_6 -> V_55 ) ;
return V_19 ;
}
V_19 -> V_191 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_50 = NULL ;
return V_19 ;
}
struct V_18 * F_175 ( struct V_11 * V_6 , int V_188 , T_2 V_94 )
{
if ( V_6 -> V_60 )
return F_176 ( V_6 , V_188 ,
( V_94 & V_192 ) ?
0 : V_193 ) ;
else
return F_172 ( V_6 , V_188 , V_94 ) ;
}
void F_177 ( struct V_18 * V_19 )
{
V_19 -> V_49 = V_51 ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_178 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_179 ( V_19 ) ;
F_180 ( V_19 ) ;
F_181 ( V_6 , V_19 ) ;
if ( V_19 -> V_38 & V_194 )
F_182 ( V_6 , V_19 ) ;
F_173 ( F_183 ( V_19 ) ) ;
F_184 ( V_6 , V_19 ) ;
}
static void F_185 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_195 )
{
F_186 ( V_19 , true ) ;
F_187 ( V_6 , V_19 , V_195 ) ;
}
static void F_188 ( int V_22 , struct V_196 * V_34 ,
unsigned long V_197 )
{
int V_198 ;
if ( V_197 == V_34 -> V_199 )
return;
V_198 = F_189 ( V_34 ) ;
if ( V_198 ) {
F_190 ( V_22 , V_34 , V_200 ,
V_198 * ( V_197 - V_34 -> V_199 ) ) ;
F_190 ( V_22 , V_34 , V_201 , ( V_197 - V_34 -> V_199 ) ) ;
}
V_34 -> V_199 = V_197 ;
}
void F_191 ( int V_22 , struct V_196 * V_34 )
{
unsigned long V_197 = V_33 ;
if ( V_34 -> V_202 )
F_188 ( V_22 , & F_192 ( V_34 ) -> V_203 , V_197 ) ;
F_188 ( V_22 , V_34 , V_197 ) ;
}
static void F_193 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_185 && ! ( V_19 -> V_38 & V_204 ) && ! -- V_19 -> V_6 -> V_205 )
F_194 ( V_19 -> V_6 -> V_185 ) ;
}
static inline void F_193 ( struct V_18 * V_19 ) {}
void F_195 ( struct V_11 * V_6 , struct V_18 * V_206 )
{
if ( F_15 ( ! V_6 ) )
return;
if ( V_6 -> V_60 ) {
F_196 ( V_206 ) ;
return;
}
F_193 ( V_206 ) ;
F_197 ( V_6 , V_206 ) ;
F_39 ( V_206 -> V_35 != NULL ) ;
if ( V_206 -> V_38 & V_180 ) {
unsigned int V_67 = V_206 -> V_38 ;
int V_160 = F_198 ( V_206 ) ;
struct V_1 * V_2 = F_199 ( V_206 ) ;
F_173 ( ! F_60 ( & V_206 -> V_20 ) ) ;
F_173 ( F_200 ( V_206 ) ) ;
F_128 ( V_2 , V_206 ) ;
F_139 ( V_2 , V_160 , V_67 ) ;
F_167 ( V_2 ) ;
}
}
void F_201 ( struct V_18 * V_206 )
{
struct V_11 * V_6 = V_206 -> V_6 ;
if ( V_6 -> V_60 )
F_196 ( V_206 ) ;
else {
unsigned long V_67 ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_195 ( V_6 , V_206 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
}
}
void F_202 ( struct V_18 * V_19 , struct V_207 * V_207 ,
int V_208 , unsigned int V_209 )
{
struct V_35 * V_35 = V_19 -> V_35 ;
V_35 -> V_210 -> V_211 = V_207 ;
V_35 -> V_210 -> V_212 = V_208 ;
V_35 -> V_210 -> V_213 = V_209 ;
V_35 -> V_41 . V_42 = V_209 ;
V_35 -> V_214 = 1 ;
V_35 -> V_215 = 1 ;
V_19 -> V_191 = V_19 -> V_216 = V_209 ;
V_19 -> V_217 = 1 ;
}
bool F_203 ( struct V_11 * V_6 , struct V_18 * V_206 ,
struct V_35 * V_35 )
{
const int V_218 = V_35 -> V_163 & V_219 ;
if ( ! F_204 ( V_6 , V_206 , V_35 ) )
return false ;
F_205 ( V_6 , V_206 , V_35 ) ;
if ( ( V_206 -> V_38 & V_219 ) != V_218 )
F_206 ( V_206 ) ;
V_206 -> V_50 -> V_220 = V_35 ;
V_206 -> V_50 = V_35 ;
V_206 -> V_191 += V_35 -> V_41 . V_42 ;
V_206 -> V_221 = F_207 ( V_206 -> V_221 , F_208 ( V_35 ) ) ;
F_186 ( V_206 , false ) ;
return true ;
}
bool F_209 ( struct V_11 * V_6 , struct V_18 * V_206 ,
struct V_35 * V_35 )
{
const int V_218 = V_35 -> V_163 & V_219 ;
if ( ! F_210 ( V_6 , V_206 , V_35 ) )
return false ;
F_211 ( V_6 , V_206 , V_35 ) ;
if ( ( V_206 -> V_38 & V_219 ) != V_218 )
F_206 ( V_206 ) ;
V_35 -> V_220 = V_206 -> V_35 ;
V_206 -> V_35 = V_35 ;
V_206 -> V_23 = V_35 -> V_41 . V_222 ;
V_206 -> V_191 += V_35 -> V_41 . V_42 ;
V_206 -> V_221 = F_207 ( V_206 -> V_221 , F_208 ( V_35 ) ) ;
F_186 ( V_206 , false ) ;
return true ;
}
bool F_212 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_223 ,
struct V_18 * * V_224 )
{
struct V_225 * V_226 ;
struct V_18 * V_19 ;
bool V_107 = false ;
struct V_227 * V_228 ;
V_226 = V_167 -> V_226 ;
if ( ! V_226 )
goto V_182;
* V_223 = 0 ;
if ( V_6 -> V_60 )
V_228 = & V_226 -> V_229 ;
else
V_228 = & V_226 -> V_230 ;
F_213 (rq, plug_list, queuelist) {
int V_231 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_223 ) ++ ;
if ( V_224 )
* V_224 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_214 ( V_19 , V_35 ) )
continue;
V_231 = F_215 ( V_19 , V_35 ) ;
if ( V_231 == V_232 ) {
V_107 = F_203 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
} else if ( V_231 == V_233 ) {
V_107 = F_209 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
}
}
V_182:
return V_107 ;
}
unsigned int F_216 ( struct V_11 * V_6 )
{
struct V_225 * V_226 ;
struct V_18 * V_19 ;
struct V_227 * V_228 ;
unsigned int V_107 = 0 ;
V_226 = V_167 -> V_226 ;
if ( ! V_226 )
goto V_182;
if ( V_6 -> V_60 )
V_228 = & V_226 -> V_229 ;
else
V_228 = & V_226 -> V_230 ;
F_217 (rq, plug_list, queuelist) {
if ( V_19 -> V_6 == V_6 )
V_107 ++ ;
}
V_182:
return V_107 ;
}
void F_218 ( struct V_18 * V_206 , struct V_35 * V_35 )
{
V_206 -> V_49 = V_234 ;
V_206 -> V_38 |= V_35 -> V_163 & V_235 ;
if ( V_35 -> V_163 & V_236 )
V_206 -> V_38 |= V_219 ;
V_206 -> V_237 = 0 ;
V_206 -> V_23 = V_35 -> V_41 . V_222 ;
V_206 -> V_221 = F_208 ( V_35 ) ;
F_219 ( V_206 -> V_6 , V_206 , V_35 ) ;
}
static T_4 V_148 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
const bool V_3 = ! ! ( V_35 -> V_163 & V_238 ) ;
struct V_225 * V_226 ;
int V_231 , V_239 = 0 , V_195 = V_240 ;
struct V_18 * V_206 ;
unsigned int V_223 = 0 ;
F_220 ( V_6 , & V_35 ) ;
F_221 ( V_6 , & V_35 , V_6 -> V_122 ) ;
if ( F_222 ( V_35 ) && F_223 ( V_35 ) ) {
V_35 -> V_37 = - V_241 ;
F_18 ( V_35 ) ;
return V_242 ;
}
if ( V_35 -> V_163 & ( V_164 | V_165 ) ) {
F_27 ( V_6 -> V_55 ) ;
V_195 = V_243 ;
goto V_244;
}
if ( ! F_224 ( V_6 ) ) {
if ( F_212 ( V_6 , V_35 , & V_223 , NULL ) )
return V_242 ;
} else
V_223 = F_216 ( V_6 ) ;
F_27 ( V_6 -> V_55 ) ;
V_231 = F_225 ( V_6 , & V_206 , V_35 ) ;
if ( V_231 == V_232 ) {
if ( F_203 ( V_6 , V_206 , V_35 ) ) {
F_226 ( V_6 , V_206 , V_35 ) ;
if ( ! F_227 ( V_6 , V_206 ) )
F_228 ( V_6 , V_206 , V_231 ) ;
goto V_245;
}
} else if ( V_231 == V_233 ) {
if ( F_209 ( V_6 , V_206 , V_35 ) ) {
F_226 ( V_6 , V_206 , V_35 ) ;
if ( ! F_229 ( V_6 , V_206 ) )
F_228 ( V_6 , V_206 , V_231 ) ;
goto V_245;
}
}
V_244:
if ( V_3 )
V_239 |= V_238 ;
V_239 |= ( V_35 -> V_163 & ( V_246 | V_247 ) ) ;
V_206 = F_162 ( V_6 , F_230 ( V_35 ) , V_239 , V_35 , V_248 ) ;
if ( F_165 ( V_206 ) ) {
V_35 -> V_37 = F_231 ( V_206 ) ;
F_18 ( V_35 ) ;
goto V_245;
}
F_218 ( V_206 , V_35 ) ;
if ( F_232 ( V_249 , & V_6 -> V_136 ) )
V_206 -> V_22 = F_233 () ;
V_226 = V_167 -> V_226 ;
if ( V_226 ) {
if ( ! V_223 )
F_234 ( V_6 ) ;
else {
if ( V_223 >= V_250 ) {
F_235 ( V_226 , false ) ;
F_234 ( V_6 ) ;
}
}
F_236 ( & V_206 -> V_20 , & V_226 -> V_230 ) ;
F_186 ( V_206 , true ) ;
} else {
F_27 ( V_6 -> V_55 ) ;
F_185 ( V_6 , V_206 , V_195 ) ;
F_28 ( V_6 ) ;
V_245:
F_29 ( V_6 -> V_55 ) ;
}
return V_242 ;
}
static inline void F_237 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_251 ;
if ( F_238 ( V_35 ) && V_17 != V_17 -> V_252 ) {
struct V_196 * V_253 = V_17 -> V_254 ;
V_35 -> V_41 . V_222 += V_253 -> V_255 ;
V_35 -> V_251 = V_17 -> V_252 ;
F_239 ( F_8 ( V_35 -> V_251 ) , V_35 ,
V_17 -> V_256 ,
V_35 -> V_41 . V_222 - V_253 -> V_255 ) ;
}
}
static void F_240 ( struct V_35 * V_35 )
{
char V_257 [ V_258 ] ;
F_20 ( V_46 L_10 ) ;
F_20 ( V_46 L_11 ,
F_241 ( V_35 -> V_251 , V_257 ) ,
V_35 -> V_163 ,
( unsigned long long ) F_242 ( V_35 ) ,
( long long ) ( F_243 ( V_35 -> V_251 -> V_259 ) >> 9 ) ) ;
}
static int T_5 F_244 ( char * V_260 )
{
return F_245 ( & V_261 , V_260 ) ;
}
static bool F_246 ( struct V_196 * V_34 , unsigned int V_262 )
{
return V_34 -> V_263 && F_247 ( & V_261 , V_262 ) ;
}
static int T_5 F_248 ( void )
{
struct V_264 * V_265 = F_249 ( L_12 ,
NULL , & V_261 ) ;
return F_250 ( V_265 ) ;
}
static inline bool F_246 ( struct V_196 * V_34 ,
unsigned int V_262 )
{
return false ;
}
static inline int F_251 ( struct V_35 * V_35 , unsigned int V_266 )
{
V_24 V_267 ;
if ( ! V_266 )
return 0 ;
V_267 = F_243 ( V_35 -> V_251 -> V_259 ) >> 9 ;
if ( V_267 ) {
V_24 V_268 = V_35 -> V_41 . V_222 ;
if ( V_267 < V_266 || V_267 - V_266 < V_268 ) {
F_240 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_6 bool
F_252 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_266 = F_238 ( V_35 ) ;
int V_116 = - V_241 ;
char V_257 [ V_258 ] ;
struct V_196 * V_34 ;
F_253 () ;
if ( F_251 ( V_35 , V_266 ) )
goto V_269;
V_6 = F_8 ( V_35 -> V_251 ) ;
if ( F_15 ( ! V_6 ) ) {
F_20 ( V_270
L_13
L_14 ,
F_241 ( V_35 -> V_251 , V_257 ) ,
( long long ) V_35 -> V_41 . V_222 ) ;
goto V_269;
}
V_34 = V_35 -> V_251 -> V_254 ;
if ( F_246 ( V_34 , V_35 -> V_41 . V_42 ) ||
F_246 ( & F_192 ( V_34 ) -> V_203 ,
V_35 -> V_41 . V_42 ) )
goto V_269;
F_237 ( V_35 ) ;
if ( F_251 ( V_35 , V_266 ) )
goto V_269;
if ( ( V_35 -> V_163 & ( V_164 | V_165 ) ) &&
! F_232 ( V_271 , & V_6 -> V_136 ) ) {
V_35 -> V_163 &= ~ ( V_164 | V_165 ) ;
if ( ! V_266 ) {
V_116 = 0 ;
goto V_269;
}
}
switch ( F_254 ( V_35 ) ) {
case V_272 :
if ( ! F_255 ( V_6 ) )
goto V_273;
break;
case V_274 :
if ( ! F_256 ( V_6 ) )
goto V_273;
break;
case V_275 :
if ( ! F_257 ( V_35 -> V_251 ) )
goto V_273;
break;
default:
break;
}
F_174 ( V_276 , V_6 -> V_103 ) ;
if ( ! F_258 ( V_6 , V_35 ) )
return false ;
F_259 ( V_6 , V_35 ) ;
return true ;
V_273:
V_116 = - V_277 ;
V_269:
V_35 -> V_37 = V_116 ;
F_18 ( V_35 ) ;
return false ;
}
T_4 F_260 ( struct V_35 * V_35 )
{
struct V_278 V_279 ;
T_4 V_107 = V_242 ;
if ( ! F_252 ( V_35 ) )
goto V_182;
if ( V_167 -> V_278 ) {
F_261 ( V_167 -> V_278 , V_35 ) ;
goto V_182;
}
F_173 ( V_35 -> V_220 ) ;
F_262 ( & V_279 ) ;
V_167 -> V_278 = & V_279 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_251 ) ;
if ( F_31 ( F_93 ( V_6 , false ) == 0 ) ) {
V_107 = V_6 -> V_280 ( V_6 , V_35 ) ;
F_98 ( V_6 ) ;
V_35 = F_263 ( V_167 -> V_278 ) ;
} else {
struct V_35 * V_281 = F_263 ( V_167 -> V_278 ) ;
F_264 ( V_35 ) ;
V_35 = V_281 ;
}
} while ( V_35 );
V_167 -> V_278 = NULL ;
V_182:
return V_107 ;
}
T_4 F_265 ( struct V_35 * V_35 )
{
if ( F_266 ( V_35 ) ) {
unsigned int V_100 ;
if ( F_15 ( F_254 ( V_35 ) == V_275 ) )
V_100 = F_267 ( V_35 -> V_251 ) >> 9 ;
else
V_100 = F_238 ( V_35 ) ;
if ( F_268 ( F_254 ( V_35 ) ) ) {
F_269 ( V_282 , V_100 ) ;
} else {
F_270 ( V_35 -> V_41 . V_42 ) ;
F_269 ( V_283 , V_100 ) ;
}
if ( F_15 ( V_284 ) ) {
char V_257 [ V_258 ] ;
F_20 ( V_285 L_15 ,
V_167 -> V_286 , F_271 ( V_167 ) ,
F_268 ( F_254 ( V_35 ) ) ? L_16 : L_17 ,
( unsigned long long ) V_35 -> V_41 . V_222 ,
F_241 ( V_35 -> V_251 , V_257 ) ,
V_100 ) ;
}
}
return F_260 ( V_35 ) ;
}
static int F_272 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( F_22 ( V_19 ) > F_273 ( V_6 , F_198 ( V_19 ) ) ) {
F_20 ( V_270 L_18 , V_184 ) ;
return - V_241 ;
}
F_274 ( V_19 ) ;
if ( V_19 -> V_217 > F_275 ( V_6 ) ) {
F_20 ( V_270 L_19 , V_184 ) ;
return - V_241 ;
}
return 0 ;
}
int F_276 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_67 ;
int V_195 = V_287 ;
if ( F_272 ( V_6 , V_19 ) )
return - V_241 ;
if ( V_19 -> V_47 &&
F_246 ( & V_19 -> V_47 -> V_203 , F_24 ( V_19 ) ) )
return - V_241 ;
if ( V_6 -> V_60 ) {
if ( F_152 ( V_6 ) )
F_186 ( V_19 , true ) ;
F_277 ( V_19 , false , true , false ) ;
return 0 ;
}
F_52 ( V_6 -> V_55 , V_67 ) ;
if ( F_15 ( F_97 ( V_6 ) ) ) {
F_53 ( V_6 -> V_55 , V_67 ) ;
return - V_111 ;
}
F_173 ( F_183 ( V_19 ) ) ;
if ( V_19 -> V_38 & ( V_164 | V_165 ) )
V_195 = V_243 ;
F_185 ( V_6 , V_19 , V_195 ) ;
if ( V_195 == V_243 )
F_28 ( V_6 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return 0 ;
}
unsigned int F_278 ( const struct V_18 * V_19 )
{
unsigned int V_218 = V_19 -> V_38 & V_219 ;
unsigned int V_262 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_38 & V_288 ) )
return F_24 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_220 ) {
if ( ( V_35 -> V_163 & V_218 ) != V_218 )
break;
V_262 += V_35 -> V_41 . V_42 ;
}
F_173 ( F_24 ( V_19 ) && ! V_262 ) ;
return V_262 ;
}
void F_279 ( struct V_18 * V_206 , unsigned int V_262 )
{
if ( F_280 ( V_206 ) ) {
const int V_188 = F_281 ( V_206 ) ;
struct V_196 * V_34 ;
int V_22 ;
V_22 = F_282 () ;
V_34 = V_206 -> V_34 ;
F_283 ( V_22 , V_34 , V_289 [ V_188 ] , V_262 >> 9 ) ;
F_284 () ;
}
}
void F_285 ( struct V_18 * V_206 )
{
if ( F_280 ( V_206 ) && ! ( V_206 -> V_38 & V_43 ) ) {
unsigned long V_290 = V_33 - V_206 -> V_32 ;
const int V_188 = F_281 ( V_206 ) ;
struct V_196 * V_34 ;
int V_22 ;
V_22 = F_282 () ;
V_34 = V_206 -> V_34 ;
F_286 ( V_22 , V_34 , V_291 [ V_188 ] ) ;
F_283 ( V_22 , V_34 , V_292 [ V_188 ] , V_290 ) ;
F_191 ( V_22 , V_34 ) ;
F_287 ( V_34 , V_188 ) ;
F_288 ( V_34 ) ;
F_284 () ;
}
}
static struct V_18 * F_289 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_185 && ( V_6 -> V_293 == V_294 ||
( V_6 -> V_293 != V_295 && ! ( V_19 -> V_38 & V_204 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_289 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_186 ( struct V_18 * V_19 , bool V_296 )
{
struct V_196 * V_34 ;
int V_188 = F_281 ( V_19 ) ;
int V_22 ;
if ( ! F_280 ( V_19 ) )
return;
V_22 = F_282 () ;
if ( ! V_296 ) {
V_34 = V_19 -> V_34 ;
F_286 ( V_22 , V_34 , V_297 [ V_188 ] ) ;
} else {
V_34 = F_290 ( V_19 -> V_47 , F_21 ( V_19 ) ) ;
if ( ! F_291 ( V_34 ) ) {
V_34 = & V_19 -> V_47 -> V_203 ;
F_292 ( V_34 ) ;
}
F_191 ( V_22 , V_34 ) ;
F_293 ( V_34 , V_188 ) ;
V_19 -> V_34 = V_34 ;
}
F_284 () ;
}
struct V_18 * F_294 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
int V_107 ;
while ( ( V_19 = F_295 ( V_6 ) ) != NULL ) {
V_19 = F_289 ( V_6 , V_19 ) ;
if ( ! V_19 )
break;
if ( ! ( V_19 -> V_38 & V_298 ) ) {
if ( V_19 -> V_38 & V_299 )
F_296 ( V_6 , V_19 ) ;
V_19 -> V_38 |= V_298 ;
F_297 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_300 || V_6 -> V_300 == V_19 ) {
V_6 -> V_301 = F_298 ( V_19 ) ;
V_6 -> V_300 = NULL ;
}
if ( V_19 -> V_38 & V_302 )
break;
if ( V_6 -> V_303 && F_24 ( V_19 ) ) {
V_19 -> V_217 ++ ;
}
if ( ! V_6 -> V_145 )
break;
V_107 = V_6 -> V_145 ( V_6 , V_19 ) ;
if ( V_107 == V_304 ) {
break;
} else if ( V_107 == V_305 ) {
if ( V_6 -> V_303 && F_24 ( V_19 ) &&
! ( V_19 -> V_38 & V_302 ) ) {
-- V_19 -> V_217 ;
}
V_19 = NULL ;
break;
} else if ( V_107 == V_306 || V_107 == V_307 ) {
int V_116 = ( V_107 == V_307 ) ? - V_308 : - V_241 ;
V_19 -> V_38 |= V_39 ;
F_299 ( V_19 ) ;
F_300 ( V_19 , V_116 ) ;
} else {
F_20 ( V_270 L_20 , V_184 , V_107 ) ;
break;
}
}
return V_19 ;
}
void F_301 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_173 ( F_60 ( & V_19 -> V_20 ) ) ;
F_173 ( F_200 ( V_19 ) ) ;
F_302 ( & V_19 -> V_20 ) ;
if ( F_303 ( V_19 ) ) {
V_6 -> V_77 [ F_304 ( V_19 ) ] ++ ;
F_305 ( V_19 ) ;
}
}
void F_299 ( struct V_18 * V_206 )
{
F_301 ( V_206 ) ;
V_206 -> V_216 = F_24 ( V_206 ) ;
if ( F_15 ( F_306 ( V_206 ) ) )
V_206 -> V_309 -> V_216 = F_24 ( V_206 -> V_309 ) ;
F_173 ( F_232 ( V_310 , & V_206 -> V_311 ) ) ;
F_307 ( V_206 ) ;
}
struct V_18 * F_308 ( struct V_11 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_294 ( V_6 ) ;
if ( V_19 )
F_299 ( V_19 ) ;
return V_19 ;
}
bool F_309 ( struct V_18 * V_206 , int error , unsigned int V_312 )
{
int V_313 ;
F_310 ( V_206 -> V_6 , V_206 , V_312 ) ;
if ( ! V_206 -> V_35 )
return false ;
if ( V_206 -> V_49 == V_234 )
V_206 -> V_237 = 0 ;
if ( error && V_206 -> V_49 == V_234 &&
! ( V_206 -> V_38 & V_39 ) ) {
char * V_314 ;
switch ( error ) {
case - V_315 :
V_314 = L_21 ;
break;
case - V_308 :
V_314 = L_22 ;
break;
case - V_316 :
V_314 = L_23 ;
break;
case - V_317 :
V_314 = L_24 ;
break;
case - V_318 :
V_314 = L_25 ;
break;
case - V_319 :
V_314 = L_26 ;
break;
case - V_241 :
default:
V_314 = L_27 ;
break;
}
F_160 ( V_270 L_28 ,
V_184 , V_314 , V_206 -> V_47 ?
V_206 -> V_47 -> V_48 : L_2 ,
( unsigned long long ) F_21 ( V_206 ) ) ;
}
F_279 ( V_206 , V_312 ) ;
V_313 = 0 ;
while ( V_206 -> V_35 ) {
struct V_35 * V_35 = V_206 -> V_35 ;
unsigned V_320 = F_311 ( V_35 -> V_41 . V_42 , V_312 ) ;
if ( V_320 == V_35 -> V_41 . V_42 )
V_206 -> V_35 = V_35 -> V_220 ;
F_14 ( V_206 , V_35 , V_320 , error ) ;
V_313 += V_320 ;
V_312 -= V_320 ;
if ( ! V_312 )
break;
}
if ( ! V_206 -> V_35 ) {
V_206 -> V_191 = 0 ;
return false ;
}
V_206 -> V_191 -= V_313 ;
if ( V_206 -> V_49 == V_234 )
V_206 -> V_23 += V_313 >> 9 ;
if ( V_206 -> V_38 & V_288 ) {
V_206 -> V_38 &= ~ V_219 ;
V_206 -> V_38 |= V_206 -> V_35 -> V_163 & V_219 ;
}
if ( F_24 ( V_206 ) < F_312 ( V_206 ) ) {
F_19 ( V_206 , L_29 ) ;
V_206 -> V_191 = F_312 ( V_206 ) ;
}
F_274 ( V_206 ) ;
return true ;
}
static bool F_313 ( struct V_18 * V_19 , int error ,
unsigned int V_312 ,
unsigned int V_321 )
{
if ( F_309 ( V_19 , error , V_312 ) )
return true ;
if ( F_15 ( F_306 ( V_19 ) ) &&
F_309 ( V_19 -> V_309 , error , V_321 ) )
return true ;
if ( F_314 ( V_19 -> V_6 ) )
F_315 ( V_19 -> V_47 ) ;
return false ;
}
void F_316 ( struct V_18 * V_206 )
{
struct V_11 * V_6 = V_206 -> V_6 ;
V_206 -> V_38 &= ~ V_302 ;
if ( V_6 -> V_146 )
V_6 -> V_146 ( V_6 , V_206 ) ;
}
void F_317 ( struct V_18 * V_206 , int error )
{
if ( V_206 -> V_38 & V_194 )
F_182 ( V_206 -> V_6 , V_206 ) ;
F_173 ( F_183 ( V_206 ) ) ;
if ( F_15 ( V_322 ) && V_206 -> V_49 == V_234 )
F_318 ( & V_206 -> V_6 -> V_8 ) ;
F_179 ( V_206 ) ;
if ( V_206 -> V_38 & V_302 )
F_316 ( V_206 ) ;
F_285 ( V_206 ) ;
if ( V_206 -> V_269 )
V_206 -> V_269 ( V_206 , error ) ;
else {
if ( F_306 ( V_206 ) )
F_195 ( V_206 -> V_309 -> V_6 , V_206 -> V_309 ) ;
F_195 ( V_206 -> V_6 , V_206 ) ;
}
}
static bool F_319 ( struct V_18 * V_19 , int error ,
unsigned int V_312 , unsigned int V_321 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_67 ;
if ( F_313 ( V_19 , error , V_312 , V_321 ) )
return true ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_317 ( V_19 , error ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return false ;
}
bool F_320 ( struct V_18 * V_19 , int error ,
unsigned int V_312 , unsigned int V_321 )
{
if ( F_313 ( V_19 , error , V_312 , V_321 ) )
return true ;
F_317 ( V_19 , error ) ;
return false ;
}
bool F_321 ( struct V_18 * V_19 , int error , unsigned int V_312 )
{
return F_319 ( V_19 , error , V_312 , 0 ) ;
}
void F_322 ( struct V_18 * V_19 , int error )
{
bool V_323 ;
unsigned int V_321 = 0 ;
if ( F_15 ( F_306 ( V_19 ) ) )
V_321 = F_24 ( V_19 -> V_309 ) ;
V_323 = F_319 ( V_19 , error , F_24 ( V_19 ) , V_321 ) ;
F_173 ( V_323 ) ;
}
bool F_323 ( struct V_18 * V_19 , int error )
{
return F_321 ( V_19 , error , F_312 ( V_19 ) ) ;
}
bool F_324 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_321 ( V_19 , error , F_278 ( V_19 ) ) ;
}
bool F_325 ( struct V_18 * V_19 , int error , unsigned int V_312 )
{
return F_320 ( V_19 , error , V_312 , 0 ) ;
}
void F_300 ( struct V_18 * V_19 , int error )
{
bool V_323 ;
unsigned int V_321 = 0 ;
if ( F_15 ( F_306 ( V_19 ) ) )
V_321 = F_24 ( V_19 -> V_309 ) ;
V_323 = F_320 ( V_19 , error , F_24 ( V_19 ) , V_321 ) ;
F_173 ( V_323 ) ;
}
bool F_326 ( struct V_18 * V_19 , int error )
{
return F_325 ( V_19 , error , F_312 ( V_19 ) ) ;
}
bool F_327 ( struct V_18 * V_19 , int error )
{
F_39 ( error >= 0 ) ;
return F_325 ( V_19 , error , F_278 ( V_19 ) ) ;
}
void F_219 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
F_328 ( V_19 , F_254 ( V_35 ) ) ;
if ( F_266 ( V_35 ) )
V_19 -> V_217 = F_329 ( V_6 , V_35 ) ;
V_19 -> V_191 = V_35 -> V_41 . V_42 ;
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
if ( V_35 -> V_251 )
V_19 -> V_47 = V_35 -> V_251 -> V_324 ;
}
void F_330 ( struct V_18 * V_19 )
{
struct V_325 V_326 ;
struct V_327 V_328 ;
F_331 (bvec, rq, iter)
F_332 ( V_328 . V_211 ) ;
}
int F_333 ( struct V_11 * V_6 )
{
if ( V_6 -> V_329 )
return V_6 -> V_329 ( V_6 ) ;
return 0 ;
}
void F_334 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_220 ;
F_335 ( V_35 ) ;
}
}
static void F_336 ( struct V_18 * V_330 , struct V_18 * V_331 )
{
V_330 -> V_22 = V_331 -> V_22 ;
F_155 ( V_330 , F_198 ( V_331 ) ,
( V_331 -> V_38 & V_332 ) | V_333 ) ;
V_330 -> V_49 = V_331 -> V_49 ;
V_330 -> V_23 = F_21 ( V_331 ) ;
V_330 -> V_191 = F_24 ( V_331 ) ;
V_330 -> V_217 = V_331 -> V_217 ;
V_330 -> V_221 = V_331 -> V_221 ;
V_330 -> V_334 = V_331 -> V_334 ;
}
int F_337 ( struct V_18 * V_19 , struct V_18 * V_335 ,
struct V_336 * V_337 , T_2 V_94 ,
int (* F_338)( struct V_35 * , struct V_35 * , void * ) ,
void * V_95 )
{
struct V_35 * V_35 , * V_338 ;
if ( ! V_337 )
V_337 = V_339 ;
F_339 (bio_src, rq_src) {
V_35 = F_340 ( V_338 , V_94 , V_337 ) ;
if ( ! V_35 )
goto V_340;
if ( F_338 && F_338 ( V_35 , V_338 , V_95 ) )
goto V_340;
if ( V_19 -> V_35 ) {
V_19 -> V_50 -> V_220 = V_35 ;
V_19 -> V_50 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
}
F_336 ( V_19 , V_335 ) ;
return 0 ;
V_340:
if ( V_35 )
F_335 ( V_35 ) ;
F_334 ( V_19 ) ;
return - V_104 ;
}
int F_102 ( struct V_52 * V_53 )
{
return F_341 ( V_57 , V_53 ) ;
}
int F_342 ( struct V_341 * V_342 ,
unsigned long V_343 )
{
return F_33 ( V_57 , V_342 , V_343 ) ;
}
int F_343 ( int V_22 , struct V_341 * V_342 ,
unsigned long V_343 )
{
return F_344 ( V_22 , V_57 , V_342 , V_343 ) ;
}
void F_345 ( struct V_225 * V_226 )
{
struct V_344 * V_345 = V_167 ;
if ( V_345 -> V_226 )
return;
F_10 ( & V_226 -> V_230 ) ;
F_10 ( & V_226 -> V_229 ) ;
F_10 ( & V_226 -> V_346 ) ;
V_345 -> V_226 = V_226 ;
}
static int F_346 ( void * V_347 , struct V_227 * V_348 , struct V_227 * V_257 )
{
struct V_18 * V_349 = F_26 ( V_348 , struct V_18 , V_20 ) ;
struct V_18 * V_350 = F_26 ( V_257 , struct V_18 , V_20 ) ;
return ! ( V_349 -> V_6 < V_350 -> V_6 ||
( V_349 -> V_6 == V_350 -> V_6 && F_21 ( V_349 ) < F_21 ( V_350 ) ) ) ;
}
static void F_347 ( struct V_11 * V_6 , unsigned int V_351 ,
bool V_352 )
__releases( V_6 -> V_55 )
{
F_348 ( V_6 , V_351 , ! V_352 ) ;
if ( V_352 )
F_37 ( V_6 ) ;
else
F_28 ( V_6 ) ;
F_349 ( V_6 -> V_55 ) ;
}
static void F_350 ( struct V_225 * V_226 , bool V_352 )
{
F_351 ( V_353 ) ;
while ( ! F_60 ( & V_226 -> V_346 ) ) {
F_352 ( & V_226 -> V_346 , & V_353 ) ;
while ( ! F_60 ( & V_353 ) ) {
struct V_354 * V_355 = F_353 ( & V_353 ,
struct V_354 ,
V_230 ) ;
F_354 ( & V_355 -> V_230 ) ;
V_355 -> V_356 ( V_355 , V_352 ) ;
}
}
}
struct V_354 * F_355 ( T_7 V_357 , void * V_95 ,
int V_358 )
{
struct V_225 * V_226 = V_167 -> V_226 ;
struct V_354 * V_355 ;
if ( ! V_226 )
return NULL ;
F_217 (cb, &plug->cb_list, list)
if ( V_355 -> V_356 == V_357 && V_355 -> V_95 == V_95 )
return V_355 ;
F_173 ( V_358 < sizeof( * V_355 ) ) ;
V_355 = F_356 ( V_358 , V_276 ) ;
if ( V_355 ) {
V_355 -> V_95 = V_95 ;
V_355 -> V_356 = V_357 ;
F_357 ( & V_355 -> V_230 , & V_226 -> V_346 ) ;
}
return V_355 ;
}
void F_235 ( struct V_225 * V_226 , bool V_352 )
{
struct V_11 * V_6 ;
unsigned long V_67 ;
struct V_18 * V_19 ;
F_351 ( V_230 ) ;
unsigned int V_351 ;
F_350 ( V_226 , V_352 ) ;
if ( ! F_60 ( & V_226 -> V_229 ) )
F_358 ( V_226 , V_352 ) ;
if ( F_60 ( & V_226 -> V_230 ) )
return;
F_352 ( & V_226 -> V_230 , & V_230 ) ;
F_359 ( NULL , & V_230 , F_346 ) ;
V_6 = NULL ;
V_351 = 0 ;
F_360 ( V_67 ) ;
while ( ! F_60 ( & V_230 ) ) {
V_19 = F_361 ( V_230 . V_359 ) ;
F_302 ( & V_19 -> V_20 ) ;
F_173 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_347 ( V_6 , V_351 , V_352 ) ;
V_6 = V_19 -> V_6 ;
V_351 = 0 ;
F_362 ( V_6 -> V_55 ) ;
}
if ( F_15 ( F_97 ( V_6 ) ) ) {
F_300 ( V_19 , - V_111 ) ;
continue;
}
if ( V_19 -> V_38 & ( V_164 | V_165 ) )
F_187 ( V_6 , V_19 , V_243 ) ;
else
F_187 ( V_6 , V_19 , V_360 ) ;
V_351 ++ ;
}
if ( V_6 )
F_347 ( V_6 , V_351 , V_352 ) ;
F_363 ( V_67 ) ;
}
void F_364 ( struct V_225 * V_226 )
{
if ( V_226 != V_167 -> V_226 )
return;
F_235 ( V_226 , false ) ;
V_167 -> V_226 = NULL ;
}
bool F_365 ( struct V_11 * V_6 , T_4 V_361 )
{
struct V_225 * V_226 ;
long V_362 ;
if ( ! V_6 -> V_60 || ! V_6 -> V_60 -> V_363 || ! F_366 ( V_361 ) ||
! F_232 ( V_364 , & V_6 -> V_136 ) )
return false ;
V_226 = V_167 -> V_226 ;
if ( V_226 )
F_235 ( V_226 , false ) ;
V_362 = V_167 -> V_362 ;
while ( ! F_367 () ) {
unsigned int V_365 = F_368 ( V_361 ) ;
struct V_61 * V_62 = V_6 -> V_366 [ V_365 ] ;
int V_107 ;
V_62 -> V_367 ++ ;
V_107 = V_6 -> V_60 -> V_363 ( V_62 , F_369 ( V_361 ) ) ;
if ( V_107 > 0 ) {
V_62 -> V_368 ++ ;
F_370 ( V_369 ) ;
return true ;
}
if ( F_371 ( V_362 , V_167 ) )
F_370 ( V_369 ) ;
if ( V_167 -> V_362 == V_369 )
return true ;
if ( V_107 < 0 )
break;
F_372 () ;
}
return false ;
}
void F_373 ( struct V_11 * V_6 , struct V_370 * V_185 )
{
V_6 -> V_185 = V_185 ;
V_6 -> V_293 = V_295 ;
F_374 ( V_6 -> V_185 , - 1 ) ;
F_375 ( V_6 -> V_185 ) ;
}
int F_376 ( struct V_11 * V_6 )
{
int V_107 = 0 ;
if ( ! V_6 -> V_185 )
return V_107 ;
F_27 ( V_6 -> V_55 ) ;
if ( V_6 -> V_205 ) {
V_107 = - V_108 ;
F_194 ( V_6 -> V_185 ) ;
} else {
V_6 -> V_293 = V_371 ;
}
F_29 ( V_6 -> V_55 ) ;
return V_107 ;
}
void F_377 ( struct V_11 * V_6 , int V_116 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_116 ) {
V_6 -> V_293 = V_294 ;
} else {
V_6 -> V_293 = V_295 ;
F_194 ( V_6 -> V_185 ) ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_378 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_293 = V_372 ;
F_29 ( V_6 -> V_55 ) ;
}
void F_379 ( struct V_11 * V_6 , int V_116 )
{
if ( ! V_6 -> V_185 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_116 ) {
V_6 -> V_293 = V_295 ;
F_28 ( V_6 ) ;
F_194 ( V_6 -> V_185 ) ;
F_380 ( V_6 -> V_185 ) ;
} else {
V_6 -> V_293 = V_294 ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_381 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_293 = V_295 ;
F_194 ( V_6 -> V_185 ) ;
F_380 ( V_6 -> V_185 ) ;
F_29 ( V_6 -> V_55 ) ;
}
int T_5 F_382 ( void )
{
F_383 ( V_373 > 8 *
F_384 ( struct V_18 , V_38 ) ) ;
V_57 = F_385 ( L_30 ,
V_374 | V_375 , 0 ) ;
if ( ! V_57 )
F_386 ( L_31 ) ;
V_97 = F_387 ( L_32 ,
sizeof( struct V_18 ) , 0 , V_376 , NULL ) ;
V_117 = F_387 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_376 , NULL ) ;
return 0 ;
}
