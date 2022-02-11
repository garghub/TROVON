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
int F_94 ( struct V_11 * V_6 , bool V_106 )
{
while ( true ) {
int V_107 ;
if ( F_95 ( & V_6 -> V_92 ) )
return 0 ;
if ( V_106 )
return - V_108 ;
V_107 = F_96 ( V_6 -> V_109 ,
! F_97 ( & V_6 -> V_110 ) ||
F_98 ( V_6 ) ) ;
if ( F_98 ( V_6 ) )
return - V_111 ;
if ( V_107 )
return V_107 ;
}
}
void F_99 ( struct V_11 * V_6 )
{
F_100 ( & V_6 -> V_92 ) ;
}
static void F_101 ( struct V_112 * V_113 )
{
struct V_11 * V_6 =
F_26 ( V_113 , struct V_11 , V_92 ) ;
F_65 ( & V_6 -> V_109 ) ;
}
static void F_102 ( unsigned long V_95 )
{
struct V_11 * V_6 = (struct V_11 * ) V_95 ;
F_103 ( & V_6 -> V_114 ) ;
}
struct V_11 * F_93 ( T_2 V_94 , int V_115 )
{
struct V_11 * V_6 ;
int V_116 ;
V_6 = F_84 ( V_117 ,
V_94 | V_118 , V_115 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_119 = F_104 ( & V_120 , 0 , 0 , V_94 ) ;
if ( V_6 -> V_119 < 0 )
goto V_121;
V_6 -> V_122 = F_105 ( V_123 , 0 ) ;
if ( ! V_6 -> V_122 )
goto V_124;
V_6 -> V_8 . V_125 =
( V_126 * 1024 ) / V_127 ;
V_6 -> V_8 . V_128 = V_129 ;
V_6 -> V_8 . V_130 = L_8 ;
V_6 -> V_103 = V_115 ;
V_116 = F_106 ( & V_6 -> V_8 ) ;
if ( V_116 )
goto V_131;
F_107 ( & V_6 -> V_8 . V_91 ,
V_132 , ( unsigned long ) V_6 ) ;
F_107 ( & V_6 -> V_59 , F_102 , ( unsigned long ) V_6 ) ;
F_10 ( & V_6 -> V_72 ) ;
F_10 ( & V_6 -> V_21 ) ;
F_10 ( & V_6 -> V_133 ) ;
#ifdef F_108
F_10 ( & V_6 -> V_134 ) ;
#endif
F_109 ( & V_6 -> V_54 , F_25 ) ;
F_110 ( & V_6 -> V_68 , & V_135 ) ;
F_111 ( & V_6 -> V_87 ) ;
F_112 ( & V_6 -> V_93 ) ;
V_6 -> V_55 = & V_6 -> V_93 ;
V_6 -> V_80 = 1 ;
F_113 ( V_81 , & V_6 -> V_136 ) ;
F_88 ( & V_6 -> V_109 ) ;
if ( F_114 ( & V_6 -> V_92 ,
F_101 ,
V_137 , V_138 ) )
goto V_139;
if ( F_115 ( V_6 ) )
goto V_140;
return V_6 ;
V_140:
F_81 ( & V_6 -> V_92 ) ;
V_139:
F_116 ( & V_6 -> V_8 ) ;
V_131:
F_117 ( V_6 -> V_122 ) ;
V_124:
F_118 ( & V_120 , V_6 -> V_119 ) ;
V_121:
F_86 ( V_117 , V_6 ) ;
return NULL ;
}
struct V_11 * F_119 ( T_3 * V_141 , T_1 * V_86 )
{
return F_120 ( V_141 , V_86 , V_105 ) ;
}
struct V_11 *
F_120 ( T_3 * V_141 , T_1 * V_86 , int V_115 )
{
struct V_11 * V_142 , * V_6 ;
V_142 = F_93 ( V_138 , V_115 ) ;
if ( ! V_142 )
return NULL ;
V_6 = F_121 ( V_142 , V_141 , V_86 ) ;
if ( ! V_6 )
F_75 ( V_142 ) ;
return V_6 ;
}
struct V_11 *
F_121 ( struct V_11 * V_6 , T_3 * V_141 ,
T_1 * V_86 )
{
if ( ! V_6 )
return NULL ;
V_6 -> V_75 = F_122 ( V_6 , V_105 , 0 ) ;
if ( ! V_6 -> V_75 )
return NULL ;
if ( F_87 ( & V_6 -> V_7 , V_6 , V_138 ) )
goto V_143;
F_123 ( & V_6 -> V_114 , V_144 ) ;
V_6 -> V_66 = V_141 ;
V_6 -> V_145 = NULL ;
V_6 -> V_146 = NULL ;
V_6 -> V_136 |= V_147 ;
if ( V_86 )
V_6 -> V_55 = V_86 ;
F_124 ( V_6 , V_148 ) ;
V_6 -> V_149 = V_150 ;
F_76 ( & V_6 -> V_87 ) ;
if ( F_125 ( V_6 , NULL ) ) {
F_77 ( & V_6 -> V_87 ) ;
goto V_143;
}
F_77 ( & V_6 -> V_87 ) ;
return V_6 ;
V_143:
F_126 ( V_6 -> V_75 ) ;
return NULL ;
}
bool F_127 ( struct V_11 * V_6 )
{
if ( F_31 ( ! F_98 ( V_6 ) ) ) {
F_128 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_129 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_38 & V_151 ) {
F_130 ( V_2 -> V_6 , V_19 ) ;
if ( V_19 -> V_152 . V_153 )
F_131 ( V_19 -> V_152 . V_153 -> V_154 ) ;
}
F_132 ( V_19 , V_2 -> V_83 ) ;
}
static inline int F_133 ( struct V_11 * V_6 , struct V_155 * V_154 )
{
if ( ! V_154 )
return 0 ;
return V_154 -> V_156 == V_6 -> V_157 ||
( V_154 -> V_156 > 0
&& F_134 ( V_33 , V_154 -> V_158 + V_159 ) ) ;
}
static void F_135 ( struct V_11 * V_6 , struct V_155 * V_154 )
{
if ( ! V_154 || F_133 ( V_6 , V_154 ) )
return;
V_154 -> V_156 = V_6 -> V_157 ;
V_154 -> V_158 = V_33 ;
}
static void F_136 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_100 [ V_3 ] < F_137 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_100 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_138 ( & V_2 -> V_79 [ V_3 ] ) )
F_74 ( & V_2 -> V_79 [ V_3 ] ) ;
F_139 ( V_2 , V_3 ) ;
}
}
static void F_140 ( struct V_1 * V_2 , unsigned int V_67 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
int V_3 = F_141 ( V_67 ) ;
V_6 -> V_76 [ V_3 ] -- ;
V_2 -> V_100 [ V_3 ] -- ;
if ( V_67 & V_151 )
V_6 -> V_73 -- ;
F_136 ( V_2 , V_3 ) ;
if ( F_15 ( V_2 -> V_101 [ V_3 ^ 1 ] ) )
F_136 ( V_2 , V_3 ^ 1 ) ;
}
int F_142 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_160 , V_161 ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_160 = F_143 ( V_6 ) ;
V_161 = F_137 ( V_6 ) ;
F_63 (rl, q) {
if ( V_2 -> V_100 [ V_84 ] >= V_160 )
F_4 ( V_2 , V_84 ) ;
else if ( V_2 -> V_100 [ V_84 ] < V_161 )
F_1 ( V_2 , V_84 ) ;
if ( V_2 -> V_100 [ V_85 ] >= V_160 )
F_4 ( V_2 , V_85 ) ;
else if ( V_2 -> V_100 [ V_85 ] < V_161 )
F_1 ( V_2 , V_85 ) ;
if ( V_2 -> V_100 [ V_84 ] >= V_6 -> V_13 ) {
F_144 ( V_2 , V_84 ) ;
} else {
F_139 ( V_2 , V_84 ) ;
F_74 ( & V_2 -> V_79 [ V_84 ] ) ;
}
if ( V_2 -> V_100 [ V_85 ] >= V_6 -> V_13 ) {
F_144 ( V_2 , V_85 ) ;
} else {
F_139 ( V_2 , V_85 ) ;
F_74 ( & V_2 -> V_79 [ V_85 ] ) ;
}
}
F_29 ( V_6 -> V_55 ) ;
return 0 ;
}
static bool F_145 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_162 & ( V_163 | V_164 ) )
return false ;
return true ;
}
static struct V_155 * F_146 ( struct V_35 * V_35 )
{
#ifdef F_108
if ( V_35 && V_35 -> V_165 )
return V_35 -> V_165 ;
#endif
return V_166 -> V_155 ;
}
static struct V_18 * F_147 ( struct V_1 * V_2 , int V_167 ,
struct V_35 * V_35 , T_2 V_94 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_18 * V_19 ;
struct V_168 * V_169 = V_6 -> V_71 -> type ;
struct V_155 * V_154 = F_146 ( V_35 ) ;
struct V_170 * V_153 = NULL ;
const bool V_171 = F_141 ( V_167 ) != 0 ;
int V_172 ;
if ( F_15 ( F_98 ( V_6 ) ) )
return F_148 ( - V_111 ) ;
V_172 = F_149 ( V_6 , V_167 ) ;
if ( V_172 == V_173 )
goto V_174;
if ( V_2 -> V_100 [ V_171 ] + 1 >= F_143 ( V_6 ) ) {
if ( V_2 -> V_100 [ V_171 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_150 ( V_2 , V_171 ) ) {
F_135 ( V_6 , V_154 ) ;
F_144 ( V_2 , V_171 ) ;
} else {
if ( V_172 != V_175
&& ! F_133 ( V_6 , V_154 ) ) {
return F_148 ( - V_104 ) ;
}
}
}
F_4 ( V_2 , V_171 ) ;
}
if ( V_2 -> V_100 [ V_171 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_148 ( - V_104 ) ;
V_6 -> V_76 [ V_171 ] ++ ;
V_2 -> V_100 [ V_171 ] ++ ;
V_2 -> V_101 [ V_171 ] = 0 ;
if ( F_145 ( V_35 ) && ! F_151 ( V_6 ) ) {
V_167 |= V_151 ;
V_6 -> V_73 ++ ;
if ( V_169 -> V_176 && V_154 )
V_153 = F_152 ( V_154 , V_6 ) ;
}
if ( F_153 ( V_6 ) )
V_167 |= V_177 ;
F_29 ( V_6 -> V_55 ) ;
V_19 = F_154 ( V_2 -> V_83 , V_94 ) ;
if ( ! V_19 )
goto V_178;
F_9 ( V_6 , V_19 ) ;
F_155 ( V_19 , V_2 ) ;
V_19 -> V_38 = V_167 | V_179 ;
if ( V_167 & V_151 ) {
if ( F_15 ( V_169 -> V_176 && ! V_153 ) ) {
if ( V_154 )
V_153 = F_156 ( V_154 , V_6 , V_94 ) ;
if ( ! V_153 )
goto V_180;
}
V_19 -> V_152 . V_153 = V_153 ;
if ( F_15 ( F_157 ( V_6 , V_19 , V_35 , V_94 ) ) )
goto V_180;
if ( V_153 )
F_158 ( V_153 -> V_154 ) ;
}
V_181:
if ( F_133 ( V_6 , V_154 ) )
V_154 -> V_156 -- ;
F_159 ( V_6 , V_35 , V_167 & 1 ) ;
return V_19 ;
V_180:
F_160 ( V_182 L_9 ,
V_183 , F_161 ( V_6 -> V_8 . V_184 ) ) ;
V_19 -> V_38 &= ~ V_151 ;
V_19 -> V_152 . V_153 = NULL ;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_73 -- ;
F_29 ( V_6 -> V_55 ) ;
goto V_181;
V_178:
F_27 ( V_6 -> V_55 ) ;
F_140 ( V_2 , V_167 ) ;
V_174:
if ( F_15 ( V_2 -> V_100 [ V_171 ] == 0 ) )
V_2 -> V_101 [ V_171 ] = 1 ;
return F_148 ( - V_104 ) ;
}
static struct V_18 * F_162 ( struct V_11 * V_6 , int V_167 ,
struct V_35 * V_35 , T_2 V_94 )
{
const bool V_171 = F_141 ( V_167 ) != 0 ;
F_163 ( V_79 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_164 ( V_6 , V_35 ) ;
V_185:
V_19 = F_147 ( V_2 , V_167 , V_35 , V_94 ) ;
if ( ! F_165 ( V_19 ) )
return V_19 ;
if ( ! F_166 ( V_94 ) || F_15 ( F_98 ( V_6 ) ) ) {
F_167 ( V_2 ) ;
return V_19 ;
}
F_168 ( & V_2 -> V_79 [ V_171 ] , & V_79 ,
V_186 ) ;
F_169 ( V_6 , V_35 , V_167 & 1 ) ;
F_29 ( V_6 -> V_55 ) ;
F_170 () ;
F_135 ( V_6 , V_166 -> V_155 ) ;
F_27 ( V_6 -> V_55 ) ;
F_171 ( & V_2 -> V_79 [ V_171 ] , & V_79 ) ;
goto V_185;
}
static struct V_18 * F_172 ( struct V_11 * V_6 , int V_187 ,
T_2 V_94 )
{
struct V_18 * V_19 ;
F_173 ( V_187 != V_188 && V_187 != V_189 ) ;
F_174 ( V_94 , V_6 -> V_103 ) ;
F_27 ( V_6 -> V_55 ) ;
V_19 = F_162 ( V_6 , V_187 , NULL , V_94 ) ;
if ( F_165 ( V_19 ) )
F_29 ( V_6 -> V_55 ) ;
return V_19 ;
}
struct V_18 * F_175 ( struct V_11 * V_6 , int V_187 , T_2 V_94 )
{
if ( V_6 -> V_60 )
return F_176 ( V_6 , V_187 ,
( V_94 & V_190 ) ?
0 : V_191 ) ;
else
return F_172 ( V_6 , V_187 , V_94 ) ;
}
struct V_18 * F_177 ( struct V_11 * V_6 , struct V_35 * V_35 ,
T_2 V_94 )
{
struct V_18 * V_19 = F_175 ( V_6 , F_178 ( V_35 ) , V_94 ) ;
if ( F_165 ( V_19 ) )
return V_19 ;
F_179 ( V_19 ) ;
F_180 (bio) {
struct V_35 * V_192 = V_35 ;
int V_107 ;
F_181 ( V_6 , & V_192 ) ;
V_107 = F_182 ( V_6 , V_19 , V_192 ) ;
if ( F_15 ( V_107 ) ) {
F_183 ( V_19 ) ;
return F_148 ( V_107 ) ;
}
}
return V_19 ;
}
void F_179 ( struct V_18 * V_19 )
{
V_19 -> V_49 = V_51 ;
V_19 -> V_193 = 0 ;
V_19 -> V_23 = ( V_24 ) - 1 ;
V_19 -> V_35 = V_19 -> V_50 = NULL ;
memset ( V_19 -> V_28 , 0 , sizeof( V_19 -> V_28 ) ) ;
}
void F_184 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
F_185 ( V_19 ) ;
F_186 ( V_19 ) ;
F_187 ( V_6 , V_19 ) ;
if ( V_19 -> V_38 & V_194 )
F_188 ( V_6 , V_19 ) ;
F_173 ( F_189 ( V_19 ) ) ;
F_190 ( V_6 , V_19 ) ;
}
static void F_191 ( struct V_11 * V_6 , struct V_18 * V_19 ,
int V_195 )
{
F_192 ( V_19 , true ) ;
F_193 ( V_6 , V_19 , V_195 ) ;
}
static void F_194 ( int V_22 , struct V_196 * V_34 ,
unsigned long V_197 )
{
int V_198 ;
if ( V_197 == V_34 -> V_199 )
return;
V_198 = F_195 ( V_34 ) ;
if ( V_198 ) {
F_196 ( V_22 , V_34 , V_200 ,
V_198 * ( V_197 - V_34 -> V_199 ) ) ;
F_196 ( V_22 , V_34 , V_201 , ( V_197 - V_34 -> V_199 ) ) ;
}
V_34 -> V_199 = V_197 ;
}
void F_197 ( int V_22 , struct V_196 * V_34 )
{
unsigned long V_197 = V_33 ;
if ( V_34 -> V_202 )
F_194 ( V_22 , & F_198 ( V_34 ) -> V_203 , V_197 ) ;
F_194 ( V_22 , V_34 , V_197 ) ;
}
static void F_199 ( struct V_18 * V_19 )
{
if ( V_19 -> V_6 -> V_184 && ! ( V_19 -> V_38 & V_204 ) && ! -- V_19 -> V_6 -> V_205 )
F_200 ( V_19 -> V_6 -> V_184 ) ;
}
static inline void F_199 ( struct V_18 * V_19 ) {}
void F_201 ( struct V_11 * V_6 , struct V_18 * V_206 )
{
if ( F_15 ( ! V_6 ) )
return;
if ( V_6 -> V_60 ) {
F_202 ( V_206 ) ;
return;
}
F_199 ( V_206 ) ;
F_203 ( V_6 , V_206 ) ;
F_39 ( V_206 -> V_35 != NULL ) ;
if ( V_206 -> V_38 & V_179 ) {
unsigned int V_67 = V_206 -> V_38 ;
struct V_1 * V_2 = F_204 ( V_206 ) ;
F_173 ( ! F_60 ( & V_206 -> V_20 ) ) ;
F_173 ( F_205 ( V_206 ) ) ;
F_129 ( V_2 , V_206 ) ;
F_140 ( V_2 , V_67 ) ;
F_167 ( V_2 ) ;
}
}
void F_183 ( struct V_18 * V_206 )
{
struct V_11 * V_6 = V_206 -> V_6 ;
if ( V_6 -> V_60 )
F_202 ( V_206 ) ;
else {
unsigned long V_67 ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_201 ( V_6 , V_206 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
}
}
void F_206 ( struct V_18 * V_19 , struct V_207 * V_207 ,
unsigned int V_208 )
{
struct V_35 * V_35 = V_19 -> V_35 ;
V_35 -> V_209 -> V_210 = V_207 ;
V_35 -> V_209 -> V_211 = 0 ;
V_35 -> V_209 -> V_212 = V_208 ;
V_35 -> V_41 . V_42 = V_208 ;
V_35 -> V_213 = 1 ;
V_35 -> V_214 = 1 ;
V_19 -> V_193 = V_19 -> V_215 = V_208 ;
V_19 -> V_216 = 1 ;
}
bool F_207 ( struct V_11 * V_6 , struct V_18 * V_206 ,
struct V_35 * V_35 )
{
const int V_217 = V_35 -> V_162 & V_218 ;
if ( ! F_208 ( V_6 , V_206 , V_35 ) )
return false ;
F_209 ( V_6 , V_206 , V_35 ) ;
if ( ( V_206 -> V_38 & V_218 ) != V_217 )
F_210 ( V_206 ) ;
V_206 -> V_50 -> V_219 = V_35 ;
V_206 -> V_50 = V_35 ;
V_206 -> V_193 += V_35 -> V_41 . V_42 ;
V_206 -> V_220 = F_211 ( V_206 -> V_220 , F_212 ( V_35 ) ) ;
F_192 ( V_206 , false ) ;
return true ;
}
bool F_213 ( struct V_11 * V_6 , struct V_18 * V_206 ,
struct V_35 * V_35 )
{
const int V_217 = V_35 -> V_162 & V_218 ;
if ( ! F_214 ( V_6 , V_206 , V_35 ) )
return false ;
F_215 ( V_6 , V_206 , V_35 ) ;
if ( ( V_206 -> V_38 & V_218 ) != V_217 )
F_210 ( V_206 ) ;
V_35 -> V_219 = V_206 -> V_35 ;
V_206 -> V_35 = V_35 ;
V_206 -> V_23 = V_35 -> V_41 . V_221 ;
V_206 -> V_193 += V_35 -> V_41 . V_42 ;
V_206 -> V_220 = F_211 ( V_206 -> V_220 , F_212 ( V_35 ) ) ;
F_192 ( V_206 , false ) ;
return true ;
}
bool F_216 ( struct V_11 * V_6 , struct V_35 * V_35 ,
unsigned int * V_222 ,
struct V_18 * * V_223 )
{
struct V_224 * V_225 ;
struct V_18 * V_19 ;
bool V_107 = false ;
struct V_226 * V_227 ;
V_225 = V_166 -> V_225 ;
if ( ! V_225 )
goto V_181;
* V_222 = 0 ;
if ( V_6 -> V_60 )
V_227 = & V_225 -> V_228 ;
else
V_227 = & V_225 -> V_229 ;
F_217 (rq, plug_list, queuelist) {
int V_230 ;
if ( V_19 -> V_6 == V_6 ) {
( * V_222 ) ++ ;
if ( V_223 )
* V_223 = V_19 ;
}
if ( V_19 -> V_6 != V_6 || ! F_218 ( V_19 , V_35 ) )
continue;
V_230 = F_219 ( V_19 , V_35 ) ;
if ( V_230 == V_231 ) {
V_107 = F_207 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
} else if ( V_230 == V_232 ) {
V_107 = F_213 ( V_6 , V_19 , V_35 ) ;
if ( V_107 )
break;
}
}
V_181:
return V_107 ;
}
unsigned int F_220 ( struct V_11 * V_6 )
{
struct V_224 * V_225 ;
struct V_18 * V_19 ;
struct V_226 * V_227 ;
unsigned int V_107 = 0 ;
V_225 = V_166 -> V_225 ;
if ( ! V_225 )
goto V_181;
if ( V_6 -> V_60 )
V_227 = & V_225 -> V_228 ;
else
V_227 = & V_225 -> V_229 ;
F_221 (rq, plug_list, queuelist) {
if ( V_19 -> V_6 == V_6 )
V_107 ++ ;
}
V_181:
return V_107 ;
}
void F_222 ( struct V_18 * V_206 , struct V_35 * V_35 )
{
V_206 -> V_49 = V_233 ;
V_206 -> V_38 |= V_35 -> V_162 & V_234 ;
if ( V_35 -> V_162 & V_235 )
V_206 -> V_38 |= V_218 ;
V_206 -> V_236 = 0 ;
V_206 -> V_23 = V_35 -> V_41 . V_221 ;
V_206 -> V_220 = F_212 ( V_35 ) ;
F_223 ( V_206 -> V_6 , V_206 , V_35 ) ;
}
static T_4 V_148 ( struct V_11 * V_6 , struct V_35 * V_35 )
{
const bool V_3 = ! ! ( V_35 -> V_162 & V_237 ) ;
struct V_224 * V_225 ;
int V_230 , V_167 , V_195 = V_238 ;
struct V_18 * V_206 ;
unsigned int V_222 = 0 ;
F_181 ( V_6 , & V_35 ) ;
F_224 ( V_6 , & V_35 , V_6 -> V_122 ) ;
if ( F_225 ( V_35 ) && F_226 ( V_35 ) ) {
V_35 -> V_37 = - V_239 ;
F_18 ( V_35 ) ;
return V_240 ;
}
if ( V_35 -> V_162 & ( V_163 | V_164 ) ) {
F_27 ( V_6 -> V_55 ) ;
V_195 = V_241 ;
goto V_242;
}
if ( ! F_227 ( V_6 ) ) {
if ( F_216 ( V_6 , V_35 , & V_222 , NULL ) )
return V_240 ;
} else
V_222 = F_220 ( V_6 ) ;
F_27 ( V_6 -> V_55 ) ;
V_230 = F_228 ( V_6 , & V_206 , V_35 ) ;
if ( V_230 == V_231 ) {
if ( F_207 ( V_6 , V_206 , V_35 ) ) {
F_229 ( V_6 , V_206 , V_35 ) ;
if ( ! F_230 ( V_6 , V_206 ) )
F_231 ( V_6 , V_206 , V_230 ) ;
goto V_243;
}
} else if ( V_230 == V_232 ) {
if ( F_213 ( V_6 , V_206 , V_35 ) ) {
F_229 ( V_6 , V_206 , V_35 ) ;
if ( ! F_232 ( V_6 , V_206 ) )
F_231 ( V_6 , V_206 , V_230 ) ;
goto V_243;
}
}
V_242:
V_167 = F_178 ( V_35 ) ;
if ( V_3 )
V_167 |= V_237 ;
V_206 = F_162 ( V_6 , V_167 , V_35 , V_244 ) ;
if ( F_165 ( V_206 ) ) {
V_35 -> V_37 = F_233 ( V_206 ) ;
F_18 ( V_35 ) ;
goto V_243;
}
F_222 ( V_206 , V_35 ) ;
if ( F_234 ( V_245 , & V_6 -> V_136 ) )
V_206 -> V_22 = F_235 () ;
V_225 = V_166 -> V_225 ;
if ( V_225 ) {
if ( ! V_222 )
F_236 ( V_6 ) ;
else {
if ( V_222 >= V_246 ) {
F_237 ( V_225 , false ) ;
F_236 ( V_6 ) ;
}
}
F_238 ( & V_206 -> V_20 , & V_225 -> V_229 ) ;
F_192 ( V_206 , true ) ;
} else {
F_27 ( V_6 -> V_55 ) ;
F_191 ( V_6 , V_206 , V_195 ) ;
F_28 ( V_6 ) ;
V_243:
F_29 ( V_6 -> V_55 ) ;
}
return V_240 ;
}
static inline void F_239 ( struct V_35 * V_35 )
{
struct V_16 * V_17 = V_35 -> V_247 ;
if ( F_240 ( V_35 ) && V_17 != V_17 -> V_248 ) {
struct V_196 * V_249 = V_17 -> V_250 ;
V_35 -> V_41 . V_221 += V_249 -> V_251 ;
V_35 -> V_247 = V_17 -> V_248 ;
F_241 ( F_8 ( V_35 -> V_247 ) , V_35 ,
V_17 -> V_252 ,
V_35 -> V_41 . V_221 - V_249 -> V_251 ) ;
}
}
static void F_242 ( struct V_35 * V_35 )
{
char V_253 [ V_254 ] ;
F_20 ( V_46 L_10 ) ;
F_20 ( V_46 L_11 ,
F_243 ( V_35 -> V_247 , V_253 ) ,
V_35 -> V_162 ,
( unsigned long long ) F_244 ( V_35 ) ,
( long long ) ( F_245 ( V_35 -> V_247 -> V_255 ) >> 9 ) ) ;
}
static int T_5 F_246 ( char * V_256 )
{
return F_247 ( & V_257 , V_256 ) ;
}
static bool F_248 ( struct V_196 * V_34 , unsigned int V_258 )
{
return V_34 -> V_259 && F_249 ( & V_257 , V_258 ) ;
}
static int T_5 F_250 ( void )
{
struct V_260 * V_261 = F_251 ( L_12 ,
NULL , & V_257 ) ;
return F_252 ( V_261 ) ;
}
static inline bool F_248 ( struct V_196 * V_34 ,
unsigned int V_258 )
{
return false ;
}
static inline int F_253 ( struct V_35 * V_35 , unsigned int V_262 )
{
V_24 V_263 ;
if ( ! V_262 )
return 0 ;
V_263 = F_245 ( V_35 -> V_247 -> V_255 ) >> 9 ;
if ( V_263 ) {
V_24 V_264 = V_35 -> V_41 . V_221 ;
if ( V_263 < V_262 || V_263 - V_262 < V_264 ) {
F_242 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_6 bool
F_254 ( struct V_35 * V_35 )
{
struct V_11 * V_6 ;
int V_262 = F_240 ( V_35 ) ;
int V_116 = - V_239 ;
char V_253 [ V_254 ] ;
struct V_196 * V_34 ;
F_255 () ;
if ( F_253 ( V_35 , V_262 ) )
goto V_265;
V_6 = F_8 ( V_35 -> V_247 ) ;
if ( F_15 ( ! V_6 ) ) {
F_20 ( V_266
L_13
L_14 ,
F_243 ( V_35 -> V_247 , V_253 ) ,
( long long ) V_35 -> V_41 . V_221 ) ;
goto V_265;
}
V_34 = V_35 -> V_247 -> V_250 ;
if ( F_248 ( V_34 , V_35 -> V_41 . V_42 ) ||
F_248 ( & F_198 ( V_34 ) -> V_203 ,
V_35 -> V_41 . V_42 ) )
goto V_265;
F_239 ( V_35 ) ;
if ( F_253 ( V_35 , V_262 ) )
goto V_265;
if ( ( V_35 -> V_162 & ( V_163 | V_164 ) ) && ! V_6 -> V_267 ) {
V_35 -> V_162 &= ~ ( V_163 | V_164 ) ;
if ( ! V_262 ) {
V_116 = 0 ;
goto V_265;
}
}
if ( ( V_35 -> V_162 & V_268 ) &&
( ! F_256 ( V_6 ) ||
( ( V_35 -> V_162 & V_269 ) && ! F_257 ( V_6 ) ) ) ) {
V_116 = - V_270 ;
goto V_265;
}
if ( V_35 -> V_162 & V_271 && ! F_258 ( V_35 -> V_247 ) ) {
V_116 = - V_270 ;
goto V_265;
}
F_174 ( V_272 , V_6 -> V_103 ) ;
if ( ! F_259 ( V_6 , V_35 ) )
return false ;
F_260 ( V_6 , V_35 ) ;
return true ;
V_265:
V_35 -> V_37 = V_116 ;
F_18 ( V_35 ) ;
return false ;
}
T_4 F_261 ( struct V_35 * V_35 )
{
struct V_273 V_274 ;
T_4 V_107 = V_240 ;
if ( ! F_254 ( V_35 ) )
goto V_181;
if ( V_166 -> V_273 ) {
F_262 ( V_166 -> V_273 , V_35 ) ;
goto V_181;
}
F_173 ( V_35 -> V_219 ) ;
F_263 ( & V_274 ) ;
V_166 -> V_273 = & V_274 ;
do {
struct V_11 * V_6 = F_8 ( V_35 -> V_247 ) ;
if ( F_31 ( F_94 ( V_6 , false ) == 0 ) ) {
V_107 = V_6 -> V_275 ( V_6 , V_35 ) ;
F_99 ( V_6 ) ;
V_35 = F_264 ( V_166 -> V_273 ) ;
} else {
struct V_35 * V_276 = F_264 ( V_166 -> V_273 ) ;
F_265 ( V_35 ) ;
V_35 = V_276 ;
}
} while ( V_35 );
V_166 -> V_273 = NULL ;
V_181:
return V_107 ;
}
T_4 F_266 ( int V_187 , struct V_35 * V_35 )
{
V_35 -> V_162 |= V_187 ;
if ( F_267 ( V_35 ) ) {
unsigned int V_100 ;
if ( F_15 ( V_187 & V_271 ) )
V_100 = F_268 ( V_35 -> V_247 ) >> 9 ;
else
V_100 = F_240 ( V_35 ) ;
if ( V_187 & V_189 ) {
F_269 ( V_277 , V_100 ) ;
} else {
F_270 ( V_35 -> V_41 . V_42 ) ;
F_269 ( V_278 , V_100 ) ;
}
if ( F_15 ( V_279 ) ) {
char V_253 [ V_254 ] ;
F_20 ( V_280 L_15 ,
V_166 -> V_281 , F_271 ( V_166 ) ,
( V_187 & V_189 ) ? L_16 : L_17 ,
( unsigned long long ) V_35 -> V_41 . V_221 ,
F_243 ( V_35 -> V_247 , V_253 ) ,
V_100 ) ;
}
}
return F_261 ( V_35 ) ;
}
static int F_272 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( F_22 ( V_19 ) > F_273 ( V_6 , V_19 -> V_38 ) ) {
F_20 ( V_266 L_18 , V_183 ) ;
return - V_239 ;
}
F_274 ( V_19 ) ;
if ( V_19 -> V_216 > F_275 ( V_6 ) ) {
F_20 ( V_266 L_19 , V_183 ) ;
return - V_239 ;
}
return 0 ;
}
int F_276 ( struct V_11 * V_6 , struct V_18 * V_19 )
{
unsigned long V_67 ;
int V_195 = V_282 ;
if ( F_272 ( V_6 , V_19 ) )
return - V_239 ;
if ( V_19 -> V_47 &&
F_248 ( & V_19 -> V_47 -> V_203 , F_24 ( V_19 ) ) )
return - V_239 ;
if ( V_6 -> V_60 ) {
if ( F_153 ( V_6 ) )
F_192 ( V_19 , true ) ;
F_277 ( V_19 , false , true , false ) ;
return 0 ;
}
F_52 ( V_6 -> V_55 , V_67 ) ;
if ( F_15 ( F_98 ( V_6 ) ) ) {
F_53 ( V_6 -> V_55 , V_67 ) ;
return - V_111 ;
}
F_173 ( F_189 ( V_19 ) ) ;
if ( V_19 -> V_38 & ( V_163 | V_164 ) )
V_195 = V_241 ;
F_191 ( V_6 , V_19 , V_195 ) ;
if ( V_195 == V_241 )
F_28 ( V_6 ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return 0 ;
}
unsigned int F_278 ( const struct V_18 * V_19 )
{
unsigned int V_217 = V_19 -> V_38 & V_218 ;
unsigned int V_258 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_19 -> V_38 & V_283 ) )
return F_24 ( V_19 ) ;
for ( V_35 = V_19 -> V_35 ; V_35 ; V_35 = V_35 -> V_219 ) {
if ( ( V_35 -> V_162 & V_217 ) != V_217 )
break;
V_258 += V_35 -> V_41 . V_42 ;
}
F_173 ( F_24 ( V_19 ) && ! V_258 ) ;
return V_258 ;
}
void F_279 ( struct V_18 * V_206 , unsigned int V_258 )
{
if ( F_280 ( V_206 ) ) {
const int V_187 = F_281 ( V_206 ) ;
struct V_196 * V_34 ;
int V_22 ;
V_22 = F_282 () ;
V_34 = V_206 -> V_34 ;
F_283 ( V_22 , V_34 , V_284 [ V_187 ] , V_258 >> 9 ) ;
F_284 () ;
}
}
void F_285 ( struct V_18 * V_206 )
{
if ( F_280 ( V_206 ) && ! ( V_206 -> V_38 & V_43 ) ) {
unsigned long V_285 = V_33 - V_206 -> V_32 ;
const int V_187 = F_281 ( V_206 ) ;
struct V_196 * V_34 ;
int V_22 ;
V_22 = F_282 () ;
V_34 = V_206 -> V_34 ;
F_286 ( V_22 , V_34 , V_286 [ V_187 ] ) ;
F_283 ( V_22 , V_34 , V_287 [ V_187 ] , V_285 ) ;
F_197 ( V_22 , V_34 ) ;
F_287 ( V_34 , V_187 ) ;
F_288 ( V_34 ) ;
F_284 () ;
}
}
static struct V_18 * F_289 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_184 && ( V_6 -> V_288 == V_289 ||
( V_6 -> V_288 != V_290 && ! ( V_19 -> V_38 & V_204 ) ) ) )
return NULL ;
else
return V_19 ;
}
static inline struct V_18 * F_289 ( struct V_11 * V_6 ,
struct V_18 * V_19 )
{
return V_19 ;
}
void F_192 ( struct V_18 * V_19 , bool V_291 )
{
struct V_196 * V_34 ;
int V_187 = F_281 ( V_19 ) ;
int V_22 ;
if ( ! F_280 ( V_19 ) )
return;
V_22 = F_282 () ;
if ( ! V_291 ) {
V_34 = V_19 -> V_34 ;
F_286 ( V_22 , V_34 , V_292 [ V_187 ] ) ;
} else {
V_34 = F_290 ( V_19 -> V_47 , F_21 ( V_19 ) ) ;
if ( ! F_291 ( V_34 ) ) {
V_34 = & V_19 -> V_47 -> V_203 ;
F_292 ( V_34 ) ;
}
F_197 ( V_22 , V_34 ) ;
F_293 ( V_34 , V_187 ) ;
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
if ( ! ( V_19 -> V_38 & V_293 ) ) {
if ( V_19 -> V_38 & V_294 )
F_296 ( V_6 , V_19 ) ;
V_19 -> V_38 |= V_293 ;
F_297 ( V_6 , V_19 ) ;
}
if ( ! V_6 -> V_295 || V_6 -> V_295 == V_19 ) {
V_6 -> V_296 = F_298 ( V_19 ) ;
V_6 -> V_295 = NULL ;
}
if ( V_19 -> V_38 & V_297 )
break;
if ( V_6 -> V_298 && F_24 ( V_19 ) ) {
V_19 -> V_216 ++ ;
}
if ( ! V_6 -> V_145 )
break;
V_107 = V_6 -> V_145 ( V_6 , V_19 ) ;
if ( V_107 == V_299 ) {
break;
} else if ( V_107 == V_300 ) {
if ( V_6 -> V_298 && F_24 ( V_19 ) &&
! ( V_19 -> V_38 & V_297 ) ) {
-- V_19 -> V_216 ;
}
V_19 = NULL ;
break;
} else if ( V_107 == V_301 || V_107 == V_302 ) {
int V_116 = ( V_107 == V_302 ) ? - V_303 : - V_239 ;
V_19 -> V_38 |= V_39 ;
F_299 ( V_19 ) ;
F_300 ( V_19 , V_116 ) ;
} else {
F_20 ( V_266 L_20 , V_183 , V_107 ) ;
break;
}
}
return V_19 ;
}
void F_301 ( struct V_18 * V_19 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
F_173 ( F_60 ( & V_19 -> V_20 ) ) ;
F_173 ( F_205 ( V_19 ) ) ;
F_302 ( & V_19 -> V_20 ) ;
if ( F_303 ( V_19 ) ) {
V_6 -> V_77 [ F_304 ( V_19 ) ] ++ ;
F_305 ( V_19 ) ;
}
}
void F_299 ( struct V_18 * V_206 )
{
F_301 ( V_206 ) ;
V_206 -> V_215 = F_24 ( V_206 ) ;
if ( F_15 ( F_306 ( V_206 ) ) )
V_206 -> V_304 -> V_215 = F_24 ( V_206 -> V_304 ) ;
F_173 ( F_234 ( V_305 , & V_206 -> V_306 ) ) ;
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
bool F_309 ( struct V_18 * V_206 , int error , unsigned int V_307 )
{
int V_308 ;
F_310 ( V_206 -> V_6 , V_206 , V_307 ) ;
if ( ! V_206 -> V_35 )
return false ;
if ( V_206 -> V_49 == V_233 )
V_206 -> V_236 = 0 ;
if ( error && V_206 -> V_49 == V_233 &&
! ( V_206 -> V_38 & V_39 ) ) {
char * V_309 ;
switch ( error ) {
case - V_310 :
V_309 = L_21 ;
break;
case - V_303 :
V_309 = L_22 ;
break;
case - V_311 :
V_309 = L_23 ;
break;
case - V_312 :
V_309 = L_24 ;
break;
case - V_313 :
V_309 = L_25 ;
break;
case - V_314 :
V_309 = L_26 ;
break;
case - V_239 :
default:
V_309 = L_27 ;
break;
}
F_160 ( V_266 L_28 ,
V_183 , V_309 , V_206 -> V_47 ?
V_206 -> V_47 -> V_48 : L_2 ,
( unsigned long long ) F_21 ( V_206 ) ) ;
}
F_279 ( V_206 , V_307 ) ;
V_308 = 0 ;
while ( V_206 -> V_35 ) {
struct V_35 * V_35 = V_206 -> V_35 ;
unsigned V_315 = F_311 ( V_35 -> V_41 . V_42 , V_307 ) ;
if ( V_315 == V_35 -> V_41 . V_42 )
V_206 -> V_35 = V_35 -> V_219 ;
F_14 ( V_206 , V_35 , V_315 , error ) ;
V_308 += V_315 ;
V_307 -= V_315 ;
if ( ! V_307 )
break;
}
if ( ! V_206 -> V_35 ) {
V_206 -> V_193 = 0 ;
return false ;
}
V_206 -> V_193 -= V_308 ;
if ( V_206 -> V_49 == V_233 )
V_206 -> V_23 += V_308 >> 9 ;
if ( V_206 -> V_38 & V_283 ) {
V_206 -> V_38 &= ~ V_218 ;
V_206 -> V_38 |= V_206 -> V_35 -> V_162 & V_218 ;
}
if ( F_24 ( V_206 ) < F_312 ( V_206 ) ) {
F_19 ( V_206 , L_29 ) ;
V_206 -> V_193 = F_312 ( V_206 ) ;
}
F_274 ( V_206 ) ;
return true ;
}
static bool F_313 ( struct V_18 * V_19 , int error ,
unsigned int V_307 ,
unsigned int V_316 )
{
if ( F_309 ( V_19 , error , V_307 ) )
return true ;
if ( F_15 ( F_306 ( V_19 ) ) &&
F_309 ( V_19 -> V_304 , error , V_316 ) )
return true ;
if ( F_314 ( V_19 -> V_6 ) )
F_315 ( V_19 -> V_47 ) ;
return false ;
}
void F_316 ( struct V_18 * V_206 )
{
struct V_11 * V_6 = V_206 -> V_6 ;
V_206 -> V_38 &= ~ V_297 ;
if ( V_6 -> V_146 )
V_6 -> V_146 ( V_6 , V_206 ) ;
}
void F_317 ( struct V_18 * V_206 , int error )
{
if ( V_206 -> V_38 & V_194 )
F_188 ( V_206 -> V_6 , V_206 ) ;
F_173 ( F_189 ( V_206 ) ) ;
if ( F_15 ( V_317 ) && V_206 -> V_49 == V_233 )
F_318 ( & V_206 -> V_6 -> V_8 ) ;
F_185 ( V_206 ) ;
if ( V_206 -> V_38 & V_297 )
F_316 ( V_206 ) ;
F_285 ( V_206 ) ;
if ( V_206 -> V_265 )
V_206 -> V_265 ( V_206 , error ) ;
else {
if ( F_306 ( V_206 ) )
F_201 ( V_206 -> V_304 -> V_6 , V_206 -> V_304 ) ;
F_201 ( V_206 -> V_6 , V_206 ) ;
}
}
static bool F_319 ( struct V_18 * V_19 , int error ,
unsigned int V_307 , unsigned int V_316 )
{
struct V_11 * V_6 = V_19 -> V_6 ;
unsigned long V_67 ;
if ( F_313 ( V_19 , error , V_307 , V_316 ) )
return true ;
F_52 ( V_6 -> V_55 , V_67 ) ;
F_317 ( V_19 , error ) ;
F_53 ( V_6 -> V_55 , V_67 ) ;
return false ;
}
bool F_320 ( struct V_18 * V_19 , int error ,
unsigned int V_307 , unsigned int V_316 )
{
if ( F_313 ( V_19 , error , V_307 , V_316 ) )
return true ;
F_317 ( V_19 , error ) ;
return false ;
}
bool F_321 ( struct V_18 * V_19 , int error , unsigned int V_307 )
{
return F_319 ( V_19 , error , V_307 , 0 ) ;
}
void F_322 ( struct V_18 * V_19 , int error )
{
bool V_318 ;
unsigned int V_316 = 0 ;
if ( F_15 ( F_306 ( V_19 ) ) )
V_316 = F_24 ( V_19 -> V_304 ) ;
V_318 = F_319 ( V_19 , error , F_24 ( V_19 ) , V_316 ) ;
F_173 ( V_318 ) ;
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
bool F_325 ( struct V_18 * V_19 , int error , unsigned int V_307 )
{
return F_320 ( V_19 , error , V_307 , 0 ) ;
}
void F_300 ( struct V_18 * V_19 , int error )
{
bool V_318 ;
unsigned int V_316 = 0 ;
if ( F_15 ( F_306 ( V_19 ) ) )
V_316 = F_24 ( V_19 -> V_304 ) ;
V_318 = F_320 ( V_19 , error , F_24 ( V_19 ) , V_316 ) ;
F_173 ( V_318 ) ;
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
void F_223 ( struct V_11 * V_6 , struct V_18 * V_19 ,
struct V_35 * V_35 )
{
V_19 -> V_38 |= V_35 -> V_162 & V_319 ;
if ( F_267 ( V_35 ) )
V_19 -> V_216 = F_328 ( V_6 , V_35 ) ;
V_19 -> V_193 = V_35 -> V_41 . V_42 ;
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
if ( V_35 -> V_247 )
V_19 -> V_47 = V_35 -> V_247 -> V_320 ;
}
void F_329 ( struct V_18 * V_19 )
{
struct V_321 V_322 ;
struct V_323 V_324 ;
F_330 (bvec, rq, iter)
F_331 ( V_324 . V_210 ) ;
}
int F_332 ( struct V_11 * V_6 )
{
if ( V_6 -> V_325 )
return V_6 -> V_325 ( V_6 ) ;
return 0 ;
}
void F_333 ( struct V_18 * V_19 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_19 -> V_35 ) != NULL ) {
V_19 -> V_35 = V_35 -> V_219 ;
F_334 ( V_35 ) ;
}
}
static void F_335 ( struct V_18 * V_326 , struct V_18 * V_327 )
{
V_326 -> V_22 = V_327 -> V_22 ;
V_326 -> V_38 |= ( V_327 -> V_38 & V_328 ) | V_329 ;
V_326 -> V_49 = V_327 -> V_49 ;
V_326 -> V_23 = F_21 ( V_327 ) ;
V_326 -> V_193 = F_24 ( V_327 ) ;
V_326 -> V_216 = V_327 -> V_216 ;
V_326 -> V_220 = V_327 -> V_220 ;
V_326 -> V_330 = V_327 -> V_330 ;
}
int F_336 ( struct V_18 * V_19 , struct V_18 * V_331 ,
struct V_332 * V_333 , T_2 V_94 ,
int (* F_337)( struct V_35 * , struct V_35 * , void * ) ,
void * V_95 )
{
struct V_35 * V_35 , * V_334 ;
if ( ! V_333 )
V_333 = V_335 ;
F_338 (bio_src, rq_src) {
V_35 = F_339 ( V_334 , V_94 , V_333 ) ;
if ( ! V_35 )
goto V_336;
if ( F_337 && F_337 ( V_35 , V_334 , V_95 ) )
goto V_336;
if ( V_19 -> V_35 ) {
V_19 -> V_50 -> V_219 = V_35 ;
V_19 -> V_50 = V_35 ;
} else
V_19 -> V_35 = V_19 -> V_50 = V_35 ;
}
F_335 ( V_19 , V_331 ) ;
return 0 ;
V_336:
if ( V_35 )
F_334 ( V_35 ) ;
F_333 ( V_19 ) ;
return - V_104 ;
}
int F_103 ( struct V_52 * V_53 )
{
return F_340 ( V_57 , V_53 ) ;
}
int F_341 ( struct V_337 * V_338 ,
unsigned long V_339 )
{
return F_33 ( V_57 , V_338 , V_339 ) ;
}
int F_342 ( int V_22 , struct V_337 * V_338 ,
unsigned long V_339 )
{
return F_343 ( V_22 , V_57 , V_338 , V_339 ) ;
}
void F_344 ( struct V_224 * V_225 )
{
struct V_340 * V_341 = V_166 ;
if ( V_341 -> V_225 )
return;
F_10 ( & V_225 -> V_229 ) ;
F_10 ( & V_225 -> V_228 ) ;
F_10 ( & V_225 -> V_342 ) ;
V_341 -> V_225 = V_225 ;
}
static int F_345 ( void * V_343 , struct V_226 * V_344 , struct V_226 * V_253 )
{
struct V_18 * V_345 = F_26 ( V_344 , struct V_18 , V_20 ) ;
struct V_18 * V_346 = F_26 ( V_253 , struct V_18 , V_20 ) ;
return ! ( V_345 -> V_6 < V_346 -> V_6 ||
( V_345 -> V_6 == V_346 -> V_6 && F_21 ( V_345 ) < F_21 ( V_346 ) ) ) ;
}
static void F_346 ( struct V_11 * V_6 , unsigned int V_347 ,
bool V_348 )
__releases( V_6 -> V_55 )
{
F_347 ( V_6 , V_347 , ! V_348 ) ;
if ( V_348 )
F_37 ( V_6 ) ;
else
F_28 ( V_6 ) ;
F_348 ( V_6 -> V_55 ) ;
}
static void F_349 ( struct V_224 * V_225 , bool V_348 )
{
F_350 ( V_349 ) ;
while ( ! F_60 ( & V_225 -> V_342 ) ) {
F_351 ( & V_225 -> V_342 , & V_349 ) ;
while ( ! F_60 ( & V_349 ) ) {
struct V_350 * V_351 = F_352 ( & V_349 ,
struct V_350 ,
V_229 ) ;
F_353 ( & V_351 -> V_229 ) ;
V_351 -> V_352 ( V_351 , V_348 ) ;
}
}
}
struct V_350 * F_354 ( T_7 V_353 , void * V_95 ,
int V_354 )
{
struct V_224 * V_225 = V_166 -> V_225 ;
struct V_350 * V_351 ;
if ( ! V_225 )
return NULL ;
F_221 (cb, &plug->cb_list, list)
if ( V_351 -> V_352 == V_353 && V_351 -> V_95 == V_95 )
return V_351 ;
F_173 ( V_354 < sizeof( * V_351 ) ) ;
V_351 = F_355 ( V_354 , V_272 ) ;
if ( V_351 ) {
V_351 -> V_95 = V_95 ;
V_351 -> V_352 = V_353 ;
F_356 ( & V_351 -> V_229 , & V_225 -> V_342 ) ;
}
return V_351 ;
}
void F_237 ( struct V_224 * V_225 , bool V_348 )
{
struct V_11 * V_6 ;
unsigned long V_67 ;
struct V_18 * V_19 ;
F_350 ( V_229 ) ;
unsigned int V_347 ;
F_349 ( V_225 , V_348 ) ;
if ( ! F_60 ( & V_225 -> V_228 ) )
F_357 ( V_225 , V_348 ) ;
if ( F_60 ( & V_225 -> V_229 ) )
return;
F_351 ( & V_225 -> V_229 , & V_229 ) ;
F_358 ( NULL , & V_229 , F_345 ) ;
V_6 = NULL ;
V_347 = 0 ;
F_359 ( V_67 ) ;
while ( ! F_60 ( & V_229 ) ) {
V_19 = F_360 ( V_229 . V_355 ) ;
F_302 ( & V_19 -> V_20 ) ;
F_173 ( ! V_19 -> V_6 ) ;
if ( V_19 -> V_6 != V_6 ) {
if ( V_6 )
F_346 ( V_6 , V_347 , V_348 ) ;
V_6 = V_19 -> V_6 ;
V_347 = 0 ;
F_361 ( V_6 -> V_55 ) ;
}
if ( F_15 ( F_98 ( V_6 ) ) ) {
F_300 ( V_19 , - V_111 ) ;
continue;
}
if ( V_19 -> V_38 & ( V_163 | V_164 ) )
F_193 ( V_6 , V_19 , V_241 ) ;
else
F_193 ( V_6 , V_19 , V_356 ) ;
V_347 ++ ;
}
if ( V_6 )
F_346 ( V_6 , V_347 , V_348 ) ;
F_362 ( V_67 ) ;
}
void F_363 ( struct V_224 * V_225 )
{
if ( V_225 != V_166 -> V_225 )
return;
F_237 ( V_225 , false ) ;
V_166 -> V_225 = NULL ;
}
bool F_364 ( struct V_11 * V_6 , T_4 V_357 )
{
struct V_224 * V_225 ;
long V_358 ;
if ( ! V_6 -> V_60 || ! V_6 -> V_60 -> V_359 || ! F_365 ( V_357 ) ||
! F_234 ( V_360 , & V_6 -> V_136 ) )
return false ;
V_225 = V_166 -> V_225 ;
if ( V_225 )
F_237 ( V_225 , false ) ;
V_358 = V_166 -> V_358 ;
while ( ! F_366 () ) {
unsigned int V_361 = F_367 ( V_357 ) ;
struct V_61 * V_62 = V_6 -> V_362 [ V_361 ] ;
int V_107 ;
V_62 -> V_363 ++ ;
V_107 = V_6 -> V_60 -> V_359 ( V_62 , F_368 ( V_357 ) ) ;
if ( V_107 > 0 ) {
V_62 -> V_364 ++ ;
F_369 ( V_365 ) ;
return true ;
}
if ( F_370 ( V_358 , V_166 ) )
F_369 ( V_365 ) ;
if ( V_166 -> V_358 == V_365 )
return true ;
if ( V_107 < 0 )
break;
F_371 () ;
}
return false ;
}
void F_372 ( struct V_11 * V_6 , struct V_366 * V_184 )
{
V_6 -> V_184 = V_184 ;
V_6 -> V_288 = V_290 ;
F_373 ( V_6 -> V_184 , - 1 ) ;
F_374 ( V_6 -> V_184 ) ;
}
int F_375 ( struct V_11 * V_6 )
{
int V_107 = 0 ;
if ( ! V_6 -> V_184 )
return V_107 ;
F_27 ( V_6 -> V_55 ) ;
if ( V_6 -> V_205 ) {
V_107 = - V_108 ;
F_200 ( V_6 -> V_184 ) ;
} else {
V_6 -> V_288 = V_367 ;
}
F_29 ( V_6 -> V_55 ) ;
return V_107 ;
}
void F_376 ( struct V_11 * V_6 , int V_116 )
{
if ( ! V_6 -> V_184 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_116 ) {
V_6 -> V_288 = V_289 ;
} else {
V_6 -> V_288 = V_290 ;
F_200 ( V_6 -> V_184 ) ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_377 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_184 )
return;
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_288 = V_368 ;
F_29 ( V_6 -> V_55 ) ;
}
void F_378 ( struct V_11 * V_6 , int V_116 )
{
if ( ! V_6 -> V_184 )
return;
F_27 ( V_6 -> V_55 ) ;
if ( ! V_116 ) {
V_6 -> V_288 = V_290 ;
F_28 ( V_6 ) ;
F_200 ( V_6 -> V_184 ) ;
F_379 ( V_6 -> V_184 ) ;
} else {
V_6 -> V_288 = V_289 ;
}
F_29 ( V_6 -> V_55 ) ;
}
void F_380 ( struct V_11 * V_6 )
{
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_288 = V_290 ;
F_200 ( V_6 -> V_184 ) ;
F_379 ( V_6 -> V_184 ) ;
F_29 ( V_6 -> V_55 ) ;
}
int T_5 F_381 ( void )
{
F_382 ( V_369 > 8 *
F_383 ( struct V_18 , V_38 ) ) ;
V_57 = F_384 ( L_30 ,
V_370 | V_371 , 0 ) ;
if ( ! V_57 )
F_385 ( L_31 ) ;
V_97 = F_386 ( L_32 ,
sizeof( struct V_18 ) , 0 , V_372 , NULL ) ;
V_117 = F_386 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_372 , NULL ) ;
return 0 ;
}
