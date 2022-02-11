static void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
F_3 ( V_2 -> V_4 -> V_5 , V_3 ) ;
#else
if ( V_2 == & V_2 -> V_6 -> V_7 )
F_3 ( V_2 -> V_6 -> V_8 -> V_9 . V_10 , V_3 ) ;
#endif
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
F_5 ( V_2 -> V_4 -> V_5 , V_3 ) ;
#else
if ( V_2 == & V_2 -> V_6 -> V_7 )
F_5 ( V_2 -> V_6 -> V_8 -> V_9 . V_10 , V_3 ) ;
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
void F_7 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
F_8 ( & V_17 -> V_18 ) ;
F_8 ( & V_17 -> V_19 ) ;
V_17 -> V_20 = - 1 ;
V_17 -> V_6 = V_6 ;
V_17 -> V_21 = ( V_22 ) - 1 ;
F_9 ( & V_17 -> V_23 ) ;
F_10 ( & V_17 -> V_24 ) ;
V_17 -> V_25 = - 1 ;
V_17 -> V_26 = - 1 ;
V_17 -> V_27 = V_28 ;
F_11 ( V_17 ) ;
V_17 -> V_29 = NULL ;
}
static void F_12 ( struct V_16 * V_17 , struct V_30 * V_30 ,
unsigned int V_31 , int error )
{
if ( error )
V_30 -> V_32 = error ;
if ( F_13 ( V_17 -> V_33 & V_34 ) )
F_14 ( V_30 , V_35 ) ;
F_15 ( V_30 , V_31 ) ;
if ( V_30 -> V_36 . V_37 == 0 && ! ( V_17 -> V_33 & V_38 ) )
F_16 ( V_30 ) ;
}
void F_17 ( struct V_16 * V_17 , char * V_39 )
{
F_18 ( V_40 L_1 , V_39 ,
V_17 -> V_41 ? V_17 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) V_17 -> V_43 ) ;
F_18 ( V_40 L_3 ,
( unsigned long long ) F_19 ( V_17 ) ,
F_20 ( V_17 ) , F_21 ( V_17 ) ) ;
F_18 ( V_40 L_4 ,
V_17 -> V_30 , V_17 -> V_44 , F_22 ( V_17 ) ) ;
}
static void F_23 ( struct V_45 * V_46 )
{
struct V_11 * V_6 ;
V_6 = F_24 ( V_46 , struct V_11 , V_47 . V_46 ) ;
F_25 ( V_6 -> V_48 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 -> V_48 ) ;
}
void F_28 ( struct V_11 * V_6 , unsigned long V_49 )
{
if ( F_29 ( ! F_30 ( V_6 ) ) )
F_31 ( V_50 , & V_6 -> V_47 ,
F_32 ( V_49 ) ) ;
}
void F_33 ( struct V_11 * V_6 )
{
F_34 ( V_51 , V_6 ) ;
F_35 ( V_6 ) ;
}
void F_36 ( struct V_11 * V_6 )
{
F_37 ( ! F_38 () ) ;
F_34 ( V_51 , V_6 ) ;
F_26 ( V_6 ) ;
}
void F_39 ( struct V_11 * V_6 )
{
F_40 ( & V_6 -> V_47 ) ;
F_41 ( V_51 , V_6 ) ;
}
void F_42 ( struct V_11 * V_6 )
{
F_43 ( & V_6 -> V_52 ) ;
if ( V_6 -> V_53 ) {
struct V_54 * V_55 ;
int V_56 ;
F_44 (q, hctx, i)
F_45 ( & V_55 -> V_57 ) ;
} else {
F_45 ( & V_6 -> V_47 ) ;
}
}
inline void F_46 ( struct V_11 * V_6 )
{
if ( F_13 ( F_30 ( V_6 ) ) )
return;
V_6 -> V_58 ++ ;
V_6 -> V_59 ( V_6 ) ;
V_6 -> V_58 -- ;
}
void F_26 ( struct V_11 * V_6 )
{
if ( F_13 ( F_47 ( V_6 ) ) )
return;
F_46 ( V_6 ) ;
}
void F_35 ( struct V_11 * V_6 )
{
if ( F_29 ( ! F_47 ( V_6 ) && ! F_30 ( V_6 ) ) )
F_48 ( V_50 , & V_6 -> V_47 , 0 ) ;
}
void F_49 ( struct V_11 * V_6 )
{
unsigned long V_60 ;
F_50 ( V_6 -> V_48 , V_60 ) ;
F_26 ( V_6 ) ;
F_51 ( V_6 -> V_48 , V_60 ) ;
}
void F_52 ( struct V_11 * V_6 )
{
F_53 ( & V_6 -> V_61 ) ;
}
static void F_54 ( struct V_11 * V_6 , bool V_62 )
__releases( V_6 -> V_48 )
__acquires( V_6 -> V_48 )
{
int V_56 ;
F_55 ( V_6 -> V_48 ) ;
while ( true ) {
bool V_63 = false ;
if ( V_6 -> V_64 )
F_56 ( V_6 ) ;
F_57 ( V_6 ) ;
if ( ! F_58 ( & V_6 -> V_65 ) && V_6 -> V_59 )
F_26 ( V_6 ) ;
V_63 |= V_6 -> V_66 ;
V_63 |= V_6 -> V_58 ;
if ( V_62 ) {
struct V_67 * V_68 = F_59 ( V_6 , NULL ) ;
V_63 |= ! F_58 ( & V_6 -> V_65 ) ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
V_63 |= V_6 -> V_69 [ V_56 ] ;
V_63 |= V_6 -> V_70 [ V_56 ] ;
if ( V_68 )
V_63 |= ! F_58 ( & V_68 -> V_71 [ V_56 ] ) ;
}
}
if ( ! V_63 )
break;
F_27 ( V_6 -> V_48 ) ;
F_60 ( 10 ) ;
F_25 ( V_6 -> V_48 ) ;
}
if ( V_6 -> V_59 ) {
struct V_1 * V_2 ;
F_61 (rl, q)
for ( V_56 = 0 ; V_56 < F_62 ( V_2 -> V_72 ) ; V_56 ++ )
F_63 ( & V_2 -> V_72 [ V_56 ] ) ;
}
}
void F_64 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_73 ++ ;
F_41 ( V_74 , V_6 ) ;
F_27 ( V_6 -> V_48 ) ;
if ( F_65 ( V_6 ) ) {
F_25 ( V_6 -> V_48 ) ;
F_54 ( V_6 , false ) ;
F_27 ( V_6 -> V_48 ) ;
F_66 () ;
}
}
void F_67 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
if ( ! -- V_6 -> V_73 )
F_34 ( V_74 , V_6 ) ;
F_68 ( V_6 -> V_73 < 0 ) ;
F_27 ( V_6 -> V_48 ) ;
}
void F_69 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
F_41 ( V_75 , V_6 ) ;
F_27 ( V_6 -> V_48 ) ;
F_70 ( V_6 ) ;
if ( V_6 -> V_53 )
F_71 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_25 ( V_6 -> V_48 ) ;
F_61 (rl, q) {
if ( V_2 -> V_76 ) {
F_72 ( & V_2 -> V_72 [ V_77 ] ) ;
F_72 ( & V_2 -> V_72 [ V_78 ] ) ;
}
}
F_27 ( V_6 -> V_48 ) ;
}
}
void F_73 ( struct V_11 * V_6 )
{
T_1 * V_79 = V_6 -> V_48 ;
F_74 ( & V_6 -> V_80 ) ;
F_69 ( V_6 ) ;
F_25 ( V_79 ) ;
V_6 -> V_73 ++ ;
F_41 ( V_74 , V_6 ) ;
F_41 ( V_81 , V_6 ) ;
F_41 ( V_82 , V_6 ) ;
F_41 ( V_75 , V_6 ) ;
F_27 ( V_79 ) ;
F_75 ( & V_6 -> V_80 ) ;
F_76 ( V_6 ) ;
F_25 ( V_79 ) ;
if ( ! V_6 -> V_53 )
F_54 ( V_6 , true ) ;
F_41 ( V_83 , V_6 ) ;
F_27 ( V_79 ) ;
F_77 () ;
F_43 ( & V_6 -> V_8 -> V_84 ) ;
F_42 ( V_6 ) ;
if ( V_6 -> V_53 )
F_78 ( V_6 ) ;
F_79 ( & V_6 -> V_85 ) ;
F_25 ( V_79 ) ;
if ( V_6 -> V_48 != & V_6 -> V_86 )
V_6 -> V_48 = & V_6 -> V_86 ;
F_27 ( V_79 ) ;
F_52 ( V_6 ) ;
}
static void * F_80 ( T_2 V_87 , void * V_88 )
{
struct V_11 * V_6 = V_88 ;
return F_81 ( V_89 , V_87 , V_6 -> V_90 ) ;
}
static void F_82 ( void * V_91 , void * V_88 )
{
F_83 ( V_89 , V_91 ) ;
}
static void * F_84 ( T_2 V_87 , void * V_88 )
{
struct V_11 * V_6 = V_88 ;
struct V_16 * V_17 ;
V_17 = F_85 ( sizeof( struct V_16 ) + V_6 -> V_92 , V_87 ,
V_6 -> V_90 ) ;
if ( V_17 && V_6 -> V_93 && V_6 -> V_93 ( V_6 , V_17 , V_87 ) < 0 ) {
F_86 ( V_17 ) ;
V_17 = NULL ;
}
return V_17 ;
}
static void F_87 ( void * V_91 , void * V_88 )
{
struct V_11 * V_6 = V_88 ;
if ( V_6 -> V_94 )
V_6 -> V_94 ( V_6 , V_91 ) ;
F_86 ( V_91 ) ;
}
int F_88 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_2 V_87 )
{
if ( F_13 ( V_2 -> V_76 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_95 [ V_77 ] = V_2 -> V_95 [ V_78 ] = 0 ;
V_2 -> V_96 [ V_77 ] = V_2 -> V_96 [ V_78 ] = 0 ;
F_89 ( & V_2 -> V_72 [ V_77 ] ) ;
F_89 ( & V_2 -> V_72 [ V_78 ] ) ;
if ( V_6 -> V_92 ) {
V_2 -> V_76 = F_90 ( V_97 ,
F_84 , F_87 ,
V_6 , V_87 , V_6 -> V_90 ) ;
} else {
V_2 -> V_76 = F_90 ( V_97 ,
F_80 , F_82 ,
V_6 , V_87 , V_6 -> V_90 ) ;
}
if ( ! V_2 -> V_76 )
return - V_98 ;
if ( V_2 != & V_6 -> V_7 )
F_68 ( ! F_91 ( V_6 ) ) ;
return 0 ;
}
void F_92 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
if ( V_2 -> V_76 ) {
F_93 ( V_2 -> V_76 ) ;
if ( V_2 != & V_6 -> V_7 )
F_52 ( V_6 ) ;
}
}
struct V_11 * F_94 ( T_2 V_87 )
{
return F_95 ( V_87 , V_99 ) ;
}
int F_96 ( struct V_11 * V_6 , bool V_100 )
{
while ( true ) {
int V_101 ;
if ( F_97 ( & V_6 -> V_85 ) )
return 0 ;
if ( V_100 )
return - V_102 ;
F_98 () ;
V_101 = F_99 ( V_6 -> V_103 ,
! F_100 ( & V_6 -> V_104 ) ||
F_101 ( V_6 ) ) ;
if ( F_101 ( V_6 ) )
return - V_105 ;
if ( V_101 )
return V_101 ;
}
}
void F_102 ( struct V_11 * V_6 )
{
F_103 ( & V_6 -> V_85 ) ;
}
static void F_104 ( struct V_106 * V_107 )
{
struct V_11 * V_6 =
F_24 ( V_107 , struct V_11 , V_85 ) ;
F_63 ( & V_6 -> V_103 ) ;
}
static void F_105 ( unsigned long V_88 )
{
struct V_11 * V_6 = (struct V_11 * ) V_88 ;
F_106 ( & V_6 -> V_108 ) ;
}
struct V_11 * F_95 ( T_2 V_87 , int V_109 )
{
struct V_11 * V_6 ;
V_6 = F_81 ( V_110 ,
V_87 | V_111 , V_109 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_112 = F_107 ( & V_113 , 0 , 0 , V_87 ) ;
if ( V_6 -> V_112 < 0 )
goto V_114;
V_6 -> V_115 = F_108 ( V_116 , 0 ) ;
if ( ! V_6 -> V_115 )
goto V_117;
V_6 -> V_8 = F_109 ( V_87 , V_109 ) ;
if ( ! V_6 -> V_8 )
goto V_118;
V_6 -> V_119 = F_110 () ;
if ( ! V_6 -> V_119 )
goto V_120;
V_6 -> V_8 -> V_121 =
( V_122 * 1024 ) / V_123 ;
V_6 -> V_8 -> V_124 = V_125 ;
V_6 -> V_8 -> V_126 = L_5 ;
V_6 -> V_90 = V_109 ;
F_111 ( & V_6 -> V_8 -> V_84 ,
V_127 , ( unsigned long ) V_6 ) ;
F_111 ( & V_6 -> V_52 , F_105 , ( unsigned long ) V_6 ) ;
F_8 ( & V_6 -> V_65 ) ;
F_8 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_128 ) ;
#ifdef F_112
F_8 ( & V_6 -> V_129 ) ;
#endif
F_113 ( & V_6 -> V_47 , F_23 ) ;
F_114 ( & V_6 -> V_61 , & V_130 ) ;
F_115 ( & V_6 -> V_80 ) ;
F_116 ( & V_6 -> V_86 ) ;
V_6 -> V_48 = & V_6 -> V_86 ;
V_6 -> V_73 = 1 ;
F_117 ( V_74 , & V_6 -> V_131 ) ;
F_89 ( & V_6 -> V_103 ) ;
if ( F_118 ( & V_6 -> V_85 ,
F_104 ,
V_132 , V_133 ) )
goto V_134;
if ( F_119 ( V_6 ) )
goto V_135;
return V_6 ;
V_135:
F_79 ( & V_6 -> V_85 ) ;
V_134:
F_120 ( V_6 -> V_119 ) ;
V_120:
F_121 ( V_6 -> V_8 ) ;
V_118:
F_122 ( V_6 -> V_115 ) ;
V_117:
F_123 ( & V_113 , V_6 -> V_112 ) ;
V_114:
F_83 ( V_110 , V_6 ) ;
return NULL ;
}
struct V_11 * F_124 ( T_3 * V_136 , T_1 * V_79 )
{
return F_125 ( V_136 , V_79 , V_99 ) ;
}
struct V_11 *
F_125 ( T_3 * V_136 , T_1 * V_79 , int V_109 )
{
struct V_11 * V_6 ;
V_6 = F_95 ( V_133 , V_109 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_59 = V_136 ;
if ( V_79 )
V_6 -> V_48 = V_79 ;
if ( F_126 ( V_6 ) < 0 ) {
F_73 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
int F_126 ( struct V_11 * V_6 )
{
V_6 -> V_68 = F_127 ( V_6 , V_99 , V_6 -> V_92 ) ;
if ( ! V_6 -> V_68 )
return - V_98 ;
if ( V_6 -> V_93 && V_6 -> V_93 ( V_6 , V_6 -> V_68 -> V_137 , V_133 ) )
goto V_138;
if ( F_88 ( & V_6 -> V_7 , V_6 , V_133 ) )
goto V_139;
F_128 ( & V_6 -> V_108 , V_140 ) ;
V_6 -> V_131 |= V_141 ;
F_129 ( V_6 , V_142 ) ;
V_6 -> V_143 = V_144 ;
F_74 ( & V_6 -> V_80 ) ;
if ( F_130 ( V_6 , NULL ) ) {
F_75 ( & V_6 -> V_80 ) ;
goto V_139;
}
F_75 ( & V_6 -> V_80 ) ;
return 0 ;
V_139:
if ( V_6 -> V_94 )
V_6 -> V_94 ( V_6 , V_6 -> V_68 -> V_137 ) ;
V_138:
F_131 ( V_6 -> V_68 ) ;
return - V_98 ;
}
bool F_91 ( struct V_11 * V_6 )
{
if ( F_29 ( ! F_101 ( V_6 ) ) ) {
F_132 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_133 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_33 & V_145 ) {
F_134 ( V_2 -> V_6 , V_17 ) ;
if ( V_17 -> V_146 . V_147 )
F_135 ( V_17 -> V_146 . V_147 -> V_148 ) ;
}
F_136 ( V_17 , V_2 -> V_76 ) ;
}
static inline int F_137 ( struct V_11 * V_6 , struct V_149 * V_148 )
{
if ( ! V_148 )
return 0 ;
return V_148 -> V_150 == V_6 -> V_151 ||
( V_148 -> V_150 > 0
&& F_138 ( V_28 , V_148 -> V_152 + V_153 ) ) ;
}
static void F_139 ( struct V_11 * V_6 , struct V_149 * V_148 )
{
if ( ! V_148 || F_137 ( V_6 , V_148 ) )
return;
V_148 -> V_150 = V_6 -> V_151 ;
V_148 -> V_152 = V_28 ;
}
static void F_140 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_95 [ V_3 ] < F_141 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_95 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_142 ( & V_2 -> V_72 [ V_3 ] ) )
F_72 ( & V_2 -> V_72 [ V_3 ] ) ;
F_143 ( V_2 , V_3 ) ;
}
}
static void F_144 ( struct V_1 * V_2 , bool V_3 ,
T_4 V_33 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
V_6 -> V_69 [ V_3 ] -- ;
V_2 -> V_95 [ V_3 ] -- ;
if ( V_33 & V_145 )
V_6 -> V_66 -- ;
F_140 ( V_2 , V_3 ) ;
if ( F_13 ( V_2 -> V_96 [ V_3 ^ 1 ] ) )
F_140 ( V_2 , V_3 ^ 1 ) ;
}
int F_145 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_154 , V_155 ;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_154 = F_146 ( V_6 ) ;
V_155 = F_141 ( V_6 ) ;
F_61 (rl, q) {
if ( V_2 -> V_95 [ V_77 ] >= V_154 )
F_4 ( V_2 , V_77 ) ;
else if ( V_2 -> V_95 [ V_77 ] < V_155 )
F_1 ( V_2 , V_77 ) ;
if ( V_2 -> V_95 [ V_78 ] >= V_154 )
F_4 ( V_2 , V_78 ) ;
else if ( V_2 -> V_95 [ V_78 ] < V_155 )
F_1 ( V_2 , V_78 ) ;
if ( V_2 -> V_95 [ V_77 ] >= V_6 -> V_13 ) {
F_147 ( V_2 , V_77 ) ;
} else {
F_143 ( V_2 , V_77 ) ;
F_72 ( & V_2 -> V_72 [ V_77 ] ) ;
}
if ( V_2 -> V_95 [ V_78 ] >= V_6 -> V_13 ) {
F_147 ( V_2 , V_78 ) ;
} else {
F_143 ( V_2 , V_78 ) ;
F_72 ( & V_2 -> V_72 [ V_78 ] ) ;
}
}
F_27 ( V_6 -> V_48 ) ;
return 0 ;
}
static struct V_16 * F_148 ( struct V_1 * V_2 , unsigned int V_156 ,
struct V_30 * V_30 , T_2 V_87 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 ;
struct V_157 * V_158 = V_6 -> V_64 -> type ;
struct V_149 * V_148 = F_149 ( V_30 ) ;
struct V_159 * V_147 = NULL ;
const bool V_160 = F_150 ( V_156 ) ;
int V_161 ;
T_4 V_33 = V_162 ;
if ( F_13 ( F_101 ( V_6 ) ) )
return F_151 ( - V_105 ) ;
V_161 = F_152 ( V_6 , V_156 ) ;
if ( V_161 == V_163 )
goto V_164;
if ( V_2 -> V_95 [ V_160 ] + 1 >= F_146 ( V_6 ) ) {
if ( V_2 -> V_95 [ V_160 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_153 ( V_2 , V_160 ) ) {
F_139 ( V_6 , V_148 ) ;
F_147 ( V_2 , V_160 ) ;
} else {
if ( V_161 != V_165
&& ! F_137 ( V_6 , V_148 ) ) {
return F_151 ( - V_98 ) ;
}
}
}
F_4 ( V_2 , V_160 ) ;
}
if ( V_2 -> V_95 [ V_160 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_151 ( - V_98 ) ;
V_6 -> V_69 [ V_160 ] ++ ;
V_2 -> V_95 [ V_160 ] ++ ;
V_2 -> V_96 [ V_160 ] = 0 ;
if ( ! F_154 ( V_156 ) && ! F_155 ( V_6 ) ) {
V_33 |= V_145 ;
V_6 -> V_66 ++ ;
if ( V_158 -> V_166 && V_148 )
V_147 = F_156 ( V_148 , V_6 ) ;
}
if ( F_157 ( V_6 ) )
V_33 |= V_167 ;
F_27 ( V_6 -> V_48 ) ;
V_17 = F_158 ( V_2 -> V_76 , V_87 ) ;
if ( ! V_17 )
goto V_168;
F_7 ( V_6 , V_17 ) ;
F_159 ( V_17 , V_2 ) ;
V_17 -> V_43 = V_156 ;
V_17 -> V_33 = V_33 ;
if ( V_33 & V_145 ) {
if ( F_13 ( V_158 -> V_166 && ! V_147 ) ) {
if ( V_148 )
V_147 = F_160 ( V_148 , V_6 , V_87 ) ;
if ( ! V_147 )
goto V_169;
}
V_17 -> V_146 . V_147 = V_147 ;
if ( F_13 ( F_161 ( V_6 , V_17 , V_30 , V_87 ) ) )
goto V_169;
if ( V_147 )
F_162 ( V_147 -> V_148 ) ;
}
V_170:
if ( F_137 ( V_6 , V_148 ) )
V_148 -> V_150 -- ;
F_163 ( V_6 , V_30 , V_156 ) ;
return V_17 ;
V_169:
F_164 ( V_171 L_6 ,
V_172 , F_165 ( V_6 -> V_8 -> V_173 ) ) ;
V_17 -> V_33 &= ~ V_145 ;
V_17 -> V_146 . V_147 = NULL ;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_66 -- ;
F_27 ( V_6 -> V_48 ) ;
goto V_170;
V_168:
F_25 ( V_6 -> V_48 ) ;
F_144 ( V_2 , V_160 , V_33 ) ;
V_164:
if ( F_13 ( V_2 -> V_95 [ V_160 ] == 0 ) )
V_2 -> V_96 [ V_160 ] = 1 ;
return F_151 ( - V_98 ) ;
}
static struct V_16 * F_166 ( struct V_11 * V_6 , unsigned int V_156 ,
struct V_30 * V_30 , T_2 V_87 )
{
const bool V_160 = F_150 ( V_156 ) ;
F_167 ( V_72 ) ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = F_168 ( V_6 , V_30 ) ;
V_174:
V_17 = F_148 ( V_2 , V_156 , V_30 , V_87 ) ;
if ( ! F_169 ( V_17 ) )
return V_17 ;
if ( ! F_170 ( V_87 ) || F_13 ( F_101 ( V_6 ) ) ) {
F_171 ( V_2 ) ;
return V_17 ;
}
F_172 ( & V_2 -> V_72 [ V_160 ] , & V_72 ,
V_175 ) ;
F_173 ( V_6 , V_30 , V_156 ) ;
F_27 ( V_6 -> V_48 ) ;
F_174 () ;
F_139 ( V_6 , V_176 -> V_149 ) ;
F_25 ( V_6 -> V_48 ) ;
F_175 ( & V_2 -> V_72 [ V_160 ] , & V_72 ) ;
goto V_174;
}
static struct V_16 * F_176 ( struct V_11 * V_6 , int V_177 ,
T_2 V_87 )
{
struct V_16 * V_17 ;
F_177 ( V_87 , V_6 -> V_90 ) ;
F_25 ( V_6 -> V_48 ) ;
V_17 = F_166 ( V_6 , V_177 , NULL , V_87 ) ;
if ( F_169 ( V_17 ) ) {
F_27 ( V_6 -> V_48 ) ;
return V_17 ;
}
V_17 -> V_178 = 0 ;
V_17 -> V_21 = ( V_22 ) - 1 ;
V_17 -> V_30 = V_17 -> V_44 = NULL ;
return V_17 ;
}
struct V_16 * F_178 ( struct V_11 * V_6 , int V_177 , T_2 V_87 )
{
if ( V_6 -> V_53 )
return F_179 ( V_6 , V_177 ,
( V_87 & V_179 ) ?
0 : V_180 ) ;
else
return F_176 ( V_6 , V_177 , V_87 ) ;
}
void F_180 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
F_181 ( V_17 ) ;
F_182 ( V_17 ) ;
F_183 ( V_6 , V_17 ) ;
F_184 ( V_6 -> V_181 , & V_17 -> V_182 ) ;
if ( V_17 -> V_33 & V_183 )
F_185 ( V_6 , V_17 ) ;
F_186 ( F_187 ( V_17 ) ) ;
F_188 ( V_6 , V_17 ) ;
}
static void F_189 ( struct V_11 * V_6 , struct V_16 * V_17 ,
int V_184 )
{
F_190 ( V_17 , true ) ;
F_191 ( V_6 , V_17 , V_184 ) ;
}
static void F_192 ( int V_20 , struct V_185 * V_29 ,
unsigned long V_186 )
{
int V_187 ;
if ( V_186 == V_29 -> V_188 )
return;
V_187 = F_193 ( V_29 ) ;
if ( V_187 ) {
F_194 ( V_20 , V_29 , V_189 ,
V_187 * ( V_186 - V_29 -> V_188 ) ) ;
F_194 ( V_20 , V_29 , V_190 , ( V_186 - V_29 -> V_188 ) ) ;
}
V_29 -> V_188 = V_186 ;
}
void F_195 ( int V_20 , struct V_185 * V_29 )
{
unsigned long V_186 = V_28 ;
if ( V_29 -> V_191 )
F_192 ( V_20 , & F_196 ( V_29 ) -> V_192 , V_186 ) ;
F_192 ( V_20 , V_29 , V_186 ) ;
}
static void F_197 ( struct V_16 * V_17 )
{
if ( V_17 -> V_6 -> V_173 && ! ( V_17 -> V_33 & V_193 ) && ! -- V_17 -> V_6 -> V_194 )
F_198 ( V_17 -> V_6 -> V_173 ) ;
}
static inline void F_197 ( struct V_16 * V_17 ) {}
void F_199 ( struct V_11 * V_6 , struct V_16 * V_195 )
{
T_4 V_33 = V_195 -> V_33 ;
if ( F_13 ( ! V_6 ) )
return;
if ( V_6 -> V_53 ) {
F_200 ( V_195 ) ;
return;
}
F_197 ( V_195 ) ;
F_201 ( V_6 , V_195 ) ;
F_37 ( V_195 -> V_30 != NULL ) ;
F_202 ( V_6 -> V_181 , & V_195 -> V_182 ) ;
if ( V_33 & V_162 ) {
struct V_1 * V_2 = F_203 ( V_195 ) ;
bool V_3 = F_150 ( V_195 -> V_43 ) ;
F_186 ( ! F_58 ( & V_195 -> V_18 ) ) ;
F_186 ( F_204 ( V_195 ) ) ;
F_133 ( V_2 , V_195 ) ;
F_144 ( V_2 , V_3 , V_33 ) ;
F_171 ( V_2 ) ;
}
}
void F_205 ( struct V_16 * V_195 )
{
struct V_11 * V_6 = V_195 -> V_6 ;
if ( V_6 -> V_53 )
F_200 ( V_195 ) ;
else {
unsigned long V_60 ;
F_50 ( V_6 -> V_48 , V_60 ) ;
F_199 ( V_6 , V_195 ) ;
F_51 ( V_6 -> V_48 , V_60 ) ;
}
}
bool F_206 ( struct V_11 * V_6 , struct V_16 * V_195 ,
struct V_30 * V_30 )
{
const int V_196 = V_30 -> V_197 & V_198 ;
if ( ! F_207 ( V_6 , V_195 , V_30 ) )
return false ;
F_208 ( V_6 , V_195 , V_30 ) ;
if ( ( V_195 -> V_43 & V_198 ) != V_196 )
F_209 ( V_195 ) ;
V_195 -> V_44 -> V_199 = V_30 ;
V_195 -> V_44 = V_30 ;
V_195 -> V_178 += V_30 -> V_36 . V_37 ;
V_195 -> V_200 = F_210 ( V_195 -> V_200 , F_211 ( V_30 ) ) ;
F_190 ( V_195 , false ) ;
return true ;
}
bool F_212 ( struct V_11 * V_6 , struct V_16 * V_195 ,
struct V_30 * V_30 )
{
const int V_196 = V_30 -> V_197 & V_198 ;
if ( ! F_213 ( V_6 , V_195 , V_30 ) )
return false ;
F_214 ( V_6 , V_195 , V_30 ) ;
if ( ( V_195 -> V_43 & V_198 ) != V_196 )
F_209 ( V_195 ) ;
V_30 -> V_199 = V_195 -> V_30 ;
V_195 -> V_30 = V_30 ;
V_195 -> V_21 = V_30 -> V_36 . V_201 ;
V_195 -> V_178 += V_30 -> V_36 . V_37 ;
V_195 -> V_200 = F_210 ( V_195 -> V_200 , F_211 ( V_30 ) ) ;
F_190 ( V_195 , false ) ;
return true ;
}
bool F_215 ( struct V_11 * V_6 , struct V_16 * V_195 ,
struct V_30 * V_30 )
{
unsigned short V_202 = F_216 ( V_195 ) ;
if ( V_202 >= F_217 ( V_6 ) )
goto V_203;
if ( F_20 ( V_195 ) + F_218 ( V_30 ) >
F_219 ( V_195 , F_19 ( V_195 ) ) )
goto V_203;
V_195 -> V_44 -> V_199 = V_30 ;
V_195 -> V_44 = V_30 ;
V_195 -> V_178 += V_30 -> V_36 . V_37 ;
V_195 -> V_200 = F_210 ( V_195 -> V_200 , F_211 ( V_30 ) ) ;
V_195 -> V_204 = V_202 + 1 ;
F_190 ( V_195 , false ) ;
return true ;
V_203:
F_220 ( V_6 , V_195 ) ;
return false ;
}
bool F_221 ( struct V_11 * V_6 , struct V_30 * V_30 ,
unsigned int * V_205 ,
struct V_16 * * V_206 )
{
struct V_207 * V_208 ;
struct V_16 * V_17 ;
struct V_209 * V_210 ;
V_208 = V_176 -> V_208 ;
if ( ! V_208 )
return false ;
* V_205 = 0 ;
if ( V_6 -> V_53 )
V_210 = & V_208 -> V_211 ;
else
V_210 = & V_208 -> V_212 ;
F_222 (rq, plug_list, queuelist) {
bool V_213 = false ;
if ( V_17 -> V_6 == V_6 ) {
( * V_205 ) ++ ;
if ( V_206 )
* V_206 = V_17 ;
}
if ( V_17 -> V_6 != V_6 || ! F_223 ( V_17 , V_30 ) )
continue;
switch ( F_224 ( V_17 , V_30 ) ) {
case V_214 :
V_213 = F_206 ( V_6 , V_17 , V_30 ) ;
break;
case V_215 :
V_213 = F_212 ( V_6 , V_17 , V_30 ) ;
break;
case V_216 :
V_213 = F_215 ( V_6 , V_17 , V_30 ) ;
break;
default:
break;
}
if ( V_213 )
return true ;
}
return false ;
}
unsigned int F_225 ( struct V_11 * V_6 )
{
struct V_207 * V_208 ;
struct V_16 * V_17 ;
struct V_209 * V_210 ;
unsigned int V_101 = 0 ;
V_208 = V_176 -> V_208 ;
if ( ! V_208 )
goto V_170;
if ( V_6 -> V_53 )
V_210 = & V_208 -> V_211 ;
else
V_210 = & V_208 -> V_212 ;
F_226 (rq, plug_list, queuelist) {
if ( V_17 -> V_6 == V_6 )
V_101 ++ ;
}
V_170:
return V_101 ;
}
void F_227 ( struct V_16 * V_195 , struct V_30 * V_30 )
{
struct V_149 * V_148 = F_149 ( V_30 ) ;
if ( V_30 -> V_197 & V_217 )
V_195 -> V_43 |= V_198 ;
V_195 -> V_21 = V_30 -> V_36 . V_201 ;
if ( F_228 ( F_211 ( V_30 ) ) )
V_195 -> V_200 = F_211 ( V_30 ) ;
else if ( V_148 )
V_195 -> V_200 = V_148 -> V_200 ;
else
V_195 -> V_200 = F_229 ( V_218 , 0 ) ;
F_230 ( V_195 -> V_6 , V_195 , V_30 ) ;
}
static T_5 V_142 ( struct V_11 * V_6 , struct V_30 * V_30 )
{
struct V_207 * V_208 ;
int V_184 = V_219 ;
struct V_16 * V_195 , * free ;
unsigned int V_205 = 0 ;
unsigned int V_220 ;
F_231 ( V_6 , & V_30 ) ;
F_232 ( V_6 , & V_30 , V_6 -> V_115 ) ;
if ( F_233 ( V_30 ) && F_234 ( V_30 ) ) {
V_30 -> V_32 = - V_221 ;
F_16 ( V_30 ) ;
return V_222 ;
}
if ( F_154 ( V_30 -> V_197 ) ) {
F_25 ( V_6 -> V_48 ) ;
V_184 = V_223 ;
goto V_224;
}
if ( ! F_235 ( V_6 ) ) {
if ( F_221 ( V_6 , V_30 , & V_205 , NULL ) )
return V_222 ;
} else
V_205 = F_225 ( V_6 ) ;
F_25 ( V_6 -> V_48 ) ;
switch ( F_236 ( V_6 , & V_195 , V_30 ) ) {
case V_214 :
if ( ! F_206 ( V_6 , V_195 , V_30 ) )
break;
F_237 ( V_6 , V_195 , V_30 ) ;
free = F_238 ( V_6 , V_195 ) ;
if ( free )
F_199 ( V_6 , free ) ;
else
F_239 ( V_6 , V_195 , V_214 ) ;
goto V_225;
case V_215 :
if ( ! F_212 ( V_6 , V_195 , V_30 ) )
break;
F_237 ( V_6 , V_195 , V_30 ) ;
free = F_240 ( V_6 , V_195 ) ;
if ( free )
F_199 ( V_6 , free ) ;
else
F_239 ( V_6 , V_195 , V_215 ) ;
goto V_225;
default:
break;
}
V_224:
V_220 = F_241 ( V_6 -> V_181 , V_30 , V_6 -> V_48 ) ;
V_195 = F_166 ( V_6 , V_30 -> V_197 , V_30 , V_226 ) ;
if ( F_169 ( V_195 ) ) {
F_242 ( V_6 -> V_181 , V_220 ) ;
V_30 -> V_32 = F_243 ( V_195 ) ;
F_16 ( V_30 ) ;
goto V_225;
}
F_244 ( & V_195 -> V_182 , V_220 ) ;
F_227 ( V_195 , V_30 ) ;
if ( F_245 ( V_227 , & V_6 -> V_131 ) )
V_195 -> V_20 = F_246 () ;
V_208 = V_176 -> V_208 ;
if ( V_208 ) {
if ( ! V_205 || F_58 ( & V_208 -> V_212 ) )
F_247 ( V_6 ) ;
else {
struct V_16 * V_228 = F_248 ( V_208 -> V_212 . V_229 ) ;
if ( V_205 >= V_230 ||
F_22 ( V_228 ) >= V_231 ) {
F_249 ( V_208 , false ) ;
F_247 ( V_6 ) ;
}
}
F_250 ( & V_195 -> V_18 , & V_208 -> V_212 ) ;
F_190 ( V_195 , true ) ;
} else {
F_25 ( V_6 -> V_48 ) ;
F_189 ( V_6 , V_195 , V_184 ) ;
F_26 ( V_6 ) ;
V_225:
F_27 ( V_6 -> V_48 ) ;
}
return V_222 ;
}
static inline void F_251 ( struct V_30 * V_30 )
{
struct V_232 * V_233 = V_30 -> V_234 ;
if ( V_233 != V_233 -> V_235 &&
( F_218 ( V_30 ) || F_252 ( V_30 ) == V_236 ) ) {
struct V_185 * V_237 = V_233 -> V_238 ;
V_30 -> V_36 . V_201 += V_237 -> V_239 ;
V_30 -> V_234 = V_233 -> V_235 ;
F_253 ( F_254 ( V_30 -> V_234 ) , V_30 ,
V_233 -> V_240 ,
V_30 -> V_36 . V_201 - V_237 -> V_239 ) ;
}
}
static void F_255 ( struct V_30 * V_30 )
{
char V_241 [ V_242 ] ;
F_18 ( V_40 L_7 ) ;
F_18 ( V_40 L_8 ,
F_256 ( V_30 -> V_234 , V_241 ) ,
V_30 -> V_197 ,
( unsigned long long ) F_257 ( V_30 ) ,
( long long ) ( F_258 ( V_30 -> V_234 -> V_243 ) >> 9 ) ) ;
}
static int T_6 F_259 ( char * V_244 )
{
return F_260 ( & V_245 , V_244 ) ;
}
static bool F_261 ( struct V_185 * V_29 , unsigned int V_246 )
{
return V_29 -> V_247 && F_262 ( & V_245 , V_246 ) ;
}
static int T_6 F_263 ( void )
{
struct V_248 * V_249 = F_264 ( L_9 ,
NULL , & V_245 ) ;
return F_265 ( V_249 ) ;
}
static inline bool F_261 ( struct V_185 * V_29 ,
unsigned int V_246 )
{
return false ;
}
static inline int F_266 ( struct V_30 * V_30 , unsigned int V_250 )
{
V_22 V_251 ;
if ( ! V_250 )
return 0 ;
V_251 = F_258 ( V_30 -> V_234 -> V_243 ) >> 9 ;
if ( V_251 ) {
V_22 V_252 = V_30 -> V_36 . V_201 ;
if ( V_251 < V_250 || V_251 - V_250 < V_252 ) {
F_255 ( V_30 ) ;
return 1 ;
}
}
return 0 ;
}
static T_7 bool
F_267 ( struct V_30 * V_30 )
{
struct V_11 * V_6 ;
int V_250 = F_218 ( V_30 ) ;
int V_253 = - V_221 ;
char V_241 [ V_242 ] ;
struct V_185 * V_29 ;
F_268 () ;
if ( F_266 ( V_30 , V_250 ) )
goto V_254;
V_6 = F_254 ( V_30 -> V_234 ) ;
if ( F_13 ( ! V_6 ) ) {
F_18 ( V_255
L_10
L_11 ,
F_256 ( V_30 -> V_234 , V_241 ) ,
( long long ) V_30 -> V_36 . V_201 ) ;
goto V_254;
}
V_29 = V_30 -> V_234 -> V_238 ;
if ( F_261 ( V_29 , V_30 -> V_36 . V_37 ) ||
F_261 ( & F_196 ( V_29 ) -> V_192 ,
V_30 -> V_36 . V_37 ) )
goto V_254;
F_251 ( V_30 ) ;
if ( F_266 ( V_30 , V_250 ) )
goto V_254;
if ( F_154 ( V_30 -> V_197 ) &&
! F_245 ( V_256 , & V_6 -> V_131 ) ) {
V_30 -> V_197 &= ~ ( V_257 | V_258 ) ;
if ( ! V_250 ) {
V_253 = 0 ;
goto V_254;
}
}
switch ( F_252 ( V_30 ) ) {
case V_259 :
if ( ! F_269 ( V_6 ) )
goto V_260;
break;
case V_261 :
if ( ! F_270 ( V_6 ) )
goto V_260;
break;
case V_262 :
if ( ! F_271 ( V_30 -> V_234 ) )
goto V_260;
break;
case V_263 :
case V_236 :
if ( ! F_272 ( V_30 -> V_234 ) )
goto V_260;
break;
case V_264 :
if ( ! F_273 ( V_30 -> V_234 ) )
goto V_260;
break;
default:
break;
}
F_177 ( V_265 , V_6 -> V_90 ) ;
if ( ! F_274 ( V_6 , V_30 ) )
return false ;
if ( ! F_275 ( V_30 , V_266 ) ) {
F_276 ( V_6 , V_30 ) ;
F_14 ( V_30 , V_266 ) ;
}
return true ;
V_260:
V_253 = - V_267 ;
V_254:
V_30 -> V_32 = V_253 ;
F_16 ( V_30 ) ;
return false ;
}
T_5 F_277 ( struct V_30 * V_30 )
{
struct V_268 V_269 [ 2 ] ;
T_5 V_101 = V_222 ;
if ( ! F_267 ( V_30 ) )
goto V_170;
if ( V_176 -> V_268 ) {
F_278 ( & V_176 -> V_268 [ 0 ] , V_30 ) ;
goto V_170;
}
F_186 ( V_30 -> V_199 ) ;
F_279 ( & V_269 [ 0 ] ) ;
V_176 -> V_268 = V_269 ;
do {
struct V_11 * V_6 = F_254 ( V_30 -> V_234 ) ;
if ( F_29 ( F_96 ( V_6 , false ) == 0 ) ) {
struct V_268 V_270 , V_271 ;
V_269 [ 1 ] = V_269 [ 0 ] ;
F_279 ( & V_269 [ 0 ] ) ;
V_101 = V_6 -> V_272 ( V_6 , V_30 ) ;
F_102 ( V_6 ) ;
F_279 ( & V_270 ) ;
F_279 ( & V_271 ) ;
while ( ( V_30 = F_280 ( & V_269 [ 0 ] ) ) != NULL )
if ( V_6 == F_254 ( V_30 -> V_234 ) )
F_278 ( & V_271 , V_30 ) ;
else
F_278 ( & V_270 , V_30 ) ;
F_281 ( & V_269 [ 0 ] , & V_270 ) ;
F_281 ( & V_269 [ 0 ] , & V_271 ) ;
F_281 ( & V_269 [ 0 ] , & V_269 [ 1 ] ) ;
} else {
F_282 ( V_30 ) ;
}
V_30 = F_280 ( & V_269 [ 0 ] ) ;
} while ( V_30 );
V_176 -> V_268 = NULL ;
V_170:
return V_101 ;
}
T_5 F_283 ( struct V_30 * V_30 )
{
if ( F_284 ( V_30 ) ) {
unsigned int V_95 ;
if ( F_13 ( F_252 ( V_30 ) == V_262 ) )
V_95 = F_285 ( V_30 -> V_234 ) >> 9 ;
else
V_95 = F_218 ( V_30 ) ;
if ( F_286 ( F_252 ( V_30 ) ) ) {
F_287 ( V_273 , V_95 ) ;
} else {
F_288 ( V_30 -> V_36 . V_37 ) ;
F_287 ( V_274 , V_95 ) ;
}
if ( F_13 ( V_275 ) ) {
char V_241 [ V_242 ] ;
F_18 ( V_276 L_12 ,
V_176 -> V_277 , F_289 ( V_176 ) ,
F_286 ( F_252 ( V_30 ) ) ? L_13 : L_14 ,
( unsigned long long ) V_30 -> V_36 . V_201 ,
F_256 ( V_30 -> V_234 , V_241 ) ,
V_95 ) ;
}
}
return F_277 ( V_30 ) ;
}
static int F_290 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( F_20 ( V_17 ) > F_291 ( V_6 , F_292 ( V_17 ) ) ) {
F_18 ( V_255 L_15 , V_172 ) ;
return - V_221 ;
}
F_293 ( V_17 ) ;
if ( V_17 -> V_204 > F_294 ( V_6 ) ) {
F_18 ( V_255 L_16 , V_172 ) ;
return - V_221 ;
}
return 0 ;
}
int F_295 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
unsigned long V_60 ;
int V_184 = V_278 ;
if ( F_290 ( V_6 , V_17 ) )
return - V_221 ;
if ( V_17 -> V_41 &&
F_261 ( & V_17 -> V_41 -> V_192 , F_22 ( V_17 ) ) )
return - V_221 ;
if ( V_6 -> V_53 ) {
if ( F_157 ( V_6 ) )
F_190 ( V_17 , true ) ;
F_296 ( V_17 , false , true , false , false ) ;
return 0 ;
}
F_50 ( V_6 -> V_48 , V_60 ) ;
if ( F_13 ( F_101 ( V_6 ) ) ) {
F_51 ( V_6 -> V_48 , V_60 ) ;
return - V_105 ;
}
F_186 ( F_187 ( V_17 ) ) ;
if ( F_154 ( V_17 -> V_43 ) )
V_184 = V_223 ;
F_189 ( V_6 , V_17 , V_184 ) ;
if ( V_184 == V_223 )
F_26 ( V_6 ) ;
F_51 ( V_6 -> V_48 , V_60 ) ;
return 0 ;
}
unsigned int F_297 ( const struct V_16 * V_17 )
{
unsigned int V_196 = V_17 -> V_43 & V_198 ;
unsigned int V_246 = 0 ;
struct V_30 * V_30 ;
if ( ! ( V_17 -> V_33 & V_279 ) )
return F_22 ( V_17 ) ;
for ( V_30 = V_17 -> V_30 ; V_30 ; V_30 = V_30 -> V_199 ) {
if ( ( V_30 -> V_197 & V_196 ) != V_196 )
break;
V_246 += V_30 -> V_36 . V_37 ;
}
F_186 ( F_22 ( V_17 ) && ! V_246 ) ;
return V_246 ;
}
void F_298 ( struct V_16 * V_195 , unsigned int V_246 )
{
if ( F_299 ( V_195 ) ) {
const int V_177 = F_300 ( V_195 ) ;
struct V_185 * V_29 ;
int V_20 ;
V_20 = F_301 () ;
V_29 = V_195 -> V_29 ;
F_302 ( V_20 , V_29 , V_280 [ V_177 ] , V_246 >> 9 ) ;
F_303 () ;
}
}
void F_304 ( struct V_16 * V_195 )
{
if ( F_299 ( V_195 ) && ! ( V_195 -> V_33 & V_38 ) ) {
unsigned long V_281 = V_28 - V_195 -> V_27 ;
const int V_177 = F_300 ( V_195 ) ;
struct V_185 * V_29 ;
int V_20 ;
V_20 = F_301 () ;
V_29 = V_195 -> V_29 ;
F_305 ( V_20 , V_29 , V_282 [ V_177 ] ) ;
F_302 ( V_20 , V_29 , V_283 [ V_177 ] , V_281 ) ;
F_195 ( V_20 , V_29 ) ;
F_306 ( V_29 , V_177 ) ;
F_307 ( V_29 ) ;
F_303 () ;
}
}
static struct V_16 * F_308 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( V_6 -> V_173 && ( V_6 -> V_284 == V_285 ||
( V_6 -> V_284 != V_286 && ! ( V_17 -> V_33 & V_193 ) ) ) )
return NULL ;
else
return V_17 ;
}
static inline struct V_16 * F_308 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
return V_17 ;
}
void F_190 ( struct V_16 * V_17 , bool V_287 )
{
struct V_185 * V_29 ;
int V_177 = F_300 ( V_17 ) ;
int V_20 ;
if ( ! F_299 ( V_17 ) )
return;
V_20 = F_301 () ;
if ( ! V_287 ) {
V_29 = V_17 -> V_29 ;
F_305 ( V_20 , V_29 , V_288 [ V_177 ] ) ;
} else {
V_29 = F_309 ( V_17 -> V_41 , F_19 ( V_17 ) ) ;
if ( ! F_310 ( V_29 ) ) {
V_29 = & V_17 -> V_41 -> V_192 ;
F_311 ( V_29 ) ;
}
F_195 ( V_20 , V_29 ) ;
F_312 ( V_29 , V_177 ) ;
V_17 -> V_29 = V_29 ;
}
F_303 () ;
}
struct V_16 * F_313 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
int V_101 ;
while ( ( V_17 = F_314 ( V_6 ) ) != NULL ) {
V_17 = F_308 ( V_6 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! ( V_17 -> V_33 & V_289 ) ) {
if ( V_17 -> V_33 & V_290 )
F_315 ( V_6 , V_17 ) ;
V_17 -> V_33 |= V_289 ;
F_316 ( V_6 , V_17 ) ;
}
if ( ! V_6 -> V_291 || V_6 -> V_291 == V_17 ) {
V_6 -> V_292 = F_317 ( V_17 ) ;
V_6 -> V_291 = NULL ;
}
if ( V_17 -> V_33 & V_293 )
break;
if ( V_6 -> V_294 && F_22 ( V_17 ) ) {
V_17 -> V_204 ++ ;
}
if ( ! V_6 -> V_295 )
break;
V_101 = V_6 -> V_295 ( V_6 , V_17 ) ;
if ( V_101 == V_296 ) {
break;
} else if ( V_101 == V_297 ) {
if ( V_6 -> V_294 && F_22 ( V_17 ) &&
! ( V_17 -> V_33 & V_293 ) ) {
-- V_17 -> V_204 ;
}
V_17 = NULL ;
break;
} else if ( V_101 == V_298 || V_101 == V_299 ) {
int V_253 = ( V_101 == V_299 ) ? - V_300 : - V_221 ;
V_17 -> V_33 |= V_34 ;
F_318 ( V_17 ) ;
F_319 ( V_17 , V_253 ) ;
} else {
F_18 ( V_255 L_17 , V_172 , V_101 ) ;
break;
}
}
return V_17 ;
}
void F_320 ( struct V_16 * V_17 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
F_186 ( F_58 ( & V_17 -> V_18 ) ) ;
F_186 ( F_204 ( V_17 ) ) ;
F_321 ( & V_17 -> V_18 ) ;
if ( F_322 ( V_17 ) ) {
V_6 -> V_70 [ F_323 ( V_17 ) ] ++ ;
F_324 ( V_17 ) ;
}
}
void F_318 ( struct V_16 * V_195 )
{
F_320 ( V_195 ) ;
if ( F_245 ( V_301 , & V_195 -> V_6 -> V_131 ) ) {
F_325 ( & V_195 -> V_182 , F_20 ( V_195 ) ) ;
V_195 -> V_33 |= V_302 ;
F_326 ( V_195 -> V_6 -> V_181 , & V_195 -> V_182 ) ;
}
F_186 ( F_245 ( V_303 , & V_195 -> V_304 ) ) ;
F_327 ( V_195 ) ;
}
struct V_16 * F_328 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
V_17 = F_313 ( V_6 ) ;
if ( V_17 )
F_318 ( V_17 ) ;
return V_17 ;
}
bool F_329 ( struct V_16 * V_195 , int error , unsigned int V_305 )
{
int V_306 ;
F_330 ( V_195 , error , V_305 ) ;
if ( ! V_195 -> V_30 )
return false ;
if ( error && ! F_331 ( V_195 ) &&
! ( V_195 -> V_33 & V_34 ) ) {
char * V_307 ;
switch ( error ) {
case - V_308 :
V_307 = L_18 ;
break;
case - V_300 :
V_307 = L_19 ;
break;
case - V_309 :
V_307 = L_20 ;
break;
case - V_310 :
V_307 = L_21 ;
break;
case - V_311 :
V_307 = L_22 ;
break;
case - V_312 :
V_307 = L_23 ;
break;
case - V_221 :
default:
V_307 = L_24 ;
break;
}
F_164 ( V_255 L_25 ,
V_172 , V_307 , V_195 -> V_41 ?
V_195 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_19 ( V_195 ) ) ;
}
F_298 ( V_195 , V_305 ) ;
V_306 = 0 ;
while ( V_195 -> V_30 ) {
struct V_30 * V_30 = V_195 -> V_30 ;
unsigned V_313 = F_332 ( V_30 -> V_36 . V_37 , V_305 ) ;
if ( V_313 == V_30 -> V_36 . V_37 )
V_195 -> V_30 = V_30 -> V_199 ;
F_333 ( V_30 , V_266 ) ;
F_12 ( V_195 , V_30 , V_313 , error ) ;
V_306 += V_313 ;
V_305 -= V_313 ;
if ( ! V_305 )
break;
}
if ( ! V_195 -> V_30 ) {
V_195 -> V_178 = 0 ;
return false ;
}
V_195 -> V_178 -= V_306 ;
if ( ! F_331 ( V_195 ) )
V_195 -> V_21 += V_306 >> 9 ;
if ( V_195 -> V_33 & V_279 ) {
V_195 -> V_43 &= ~ V_198 ;
V_195 -> V_43 |= V_195 -> V_30 -> V_197 & V_198 ;
}
if ( ! ( V_195 -> V_33 & V_314 ) ) {
if ( F_22 ( V_195 ) < F_334 ( V_195 ) ) {
F_17 ( V_195 , L_26 ) ;
V_195 -> V_178 = F_334 ( V_195 ) ;
}
F_293 ( V_195 ) ;
}
return true ;
}
static bool F_335 ( struct V_16 * V_17 , int error ,
unsigned int V_305 ,
unsigned int V_315 )
{
if ( F_329 ( V_17 , error , V_305 ) )
return true ;
if ( F_13 ( F_336 ( V_17 ) ) &&
F_329 ( V_17 -> V_316 , error , V_315 ) )
return true ;
if ( F_337 ( V_17 -> V_6 ) )
F_338 ( V_17 -> V_41 ) ;
return false ;
}
void F_339 ( struct V_16 * V_195 )
{
struct V_11 * V_6 = V_195 -> V_6 ;
V_195 -> V_33 &= ~ V_293 ;
if ( V_6 -> V_317 )
V_6 -> V_317 ( V_6 , V_195 ) ;
}
void F_340 ( struct V_16 * V_195 , int error )
{
struct V_11 * V_6 = V_195 -> V_6 ;
if ( V_195 -> V_33 & V_302 )
F_341 ( V_195 ) ;
if ( V_195 -> V_33 & V_183 )
F_185 ( V_6 , V_195 ) ;
F_186 ( F_187 ( V_195 ) ) ;
if ( F_13 ( V_318 ) && ! F_331 ( V_195 ) )
F_342 ( V_195 -> V_6 -> V_8 ) ;
F_181 ( V_195 ) ;
if ( V_195 -> V_33 & V_293 )
F_339 ( V_195 ) ;
F_304 ( V_195 ) ;
if ( V_195 -> V_254 ) {
F_202 ( V_195 -> V_6 -> V_181 , & V_195 -> V_182 ) ;
V_195 -> V_254 ( V_195 , error ) ;
} else {
if ( F_336 ( V_195 ) )
F_199 ( V_195 -> V_316 -> V_6 , V_195 -> V_316 ) ;
F_199 ( V_6 , V_195 ) ;
}
}
static bool F_343 ( struct V_16 * V_17 , int error ,
unsigned int V_305 , unsigned int V_315 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
unsigned long V_60 ;
if ( F_335 ( V_17 , error , V_305 , V_315 ) )
return true ;
F_50 ( V_6 -> V_48 , V_60 ) ;
F_340 ( V_17 , error ) ;
F_51 ( V_6 -> V_48 , V_60 ) ;
return false ;
}
static bool F_344 ( struct V_16 * V_17 , int error ,
unsigned int V_305 , unsigned int V_315 )
{
if ( F_335 ( V_17 , error , V_305 , V_315 ) )
return true ;
F_340 ( V_17 , error ) ;
return false ;
}
bool F_345 ( struct V_16 * V_17 , int error , unsigned int V_305 )
{
return F_343 ( V_17 , error , V_305 , 0 ) ;
}
void F_346 ( struct V_16 * V_17 , int error )
{
bool V_319 ;
unsigned int V_315 = 0 ;
if ( F_13 ( F_336 ( V_17 ) ) )
V_315 = F_22 ( V_17 -> V_316 ) ;
V_319 = F_343 ( V_17 , error , F_22 ( V_17 ) , V_315 ) ;
F_186 ( V_319 ) ;
}
bool F_347 ( struct V_16 * V_17 , int error , unsigned int V_305 )
{
return F_344 ( V_17 , error , V_305 , 0 ) ;
}
void F_319 ( struct V_16 * V_17 , int error )
{
bool V_319 ;
unsigned int V_315 = 0 ;
if ( F_13 ( F_336 ( V_17 ) ) )
V_315 = F_22 ( V_17 -> V_316 ) ;
V_319 = F_344 ( V_17 , error , F_22 ( V_17 ) , V_315 ) ;
F_186 ( V_319 ) ;
}
bool F_348 ( struct V_16 * V_17 , int error )
{
return F_347 ( V_17 , error , F_334 ( V_17 ) ) ;
}
void F_230 ( struct V_11 * V_6 , struct V_16 * V_17 ,
struct V_30 * V_30 )
{
if ( F_284 ( V_30 ) )
V_17 -> V_204 = F_349 ( V_6 , V_30 ) ;
V_17 -> V_178 = V_30 -> V_36 . V_37 ;
V_17 -> V_30 = V_17 -> V_44 = V_30 ;
if ( V_30 -> V_234 )
V_17 -> V_41 = V_30 -> V_234 -> V_320 ;
}
void F_350 ( struct V_16 * V_17 )
{
struct V_321 V_322 ;
struct V_323 V_324 ;
F_351 (bvec, rq, iter)
F_352 ( V_324 . V_325 ) ;
}
int F_353 ( struct V_11 * V_6 )
{
if ( V_6 -> V_326 )
return V_6 -> V_326 ( V_6 ) ;
return 0 ;
}
void F_354 ( struct V_16 * V_17 )
{
struct V_30 * V_30 ;
while ( ( V_30 = V_17 -> V_30 ) != NULL ) {
V_17 -> V_30 = V_30 -> V_199 ;
F_355 ( V_30 ) ;
}
}
static void F_356 ( struct V_16 * V_327 , struct V_16 * V_328 )
{
V_327 -> V_20 = V_328 -> V_20 ;
V_327 -> V_21 = F_19 ( V_328 ) ;
V_327 -> V_178 = F_22 ( V_328 ) ;
V_327 -> V_204 = V_328 -> V_204 ;
V_327 -> V_200 = V_328 -> V_200 ;
V_327 -> V_329 = V_328 -> V_329 ;
}
int F_357 ( struct V_16 * V_17 , struct V_16 * V_330 ,
struct V_331 * V_332 , T_2 V_87 ,
int (* F_358)( struct V_30 * , struct V_30 * , void * ) ,
void * V_88 )
{
struct V_30 * V_30 , * V_333 ;
if ( ! V_332 )
V_332 = V_334 ;
F_359 (bio_src, rq_src) {
V_30 = F_360 ( V_333 , V_87 , V_332 ) ;
if ( ! V_30 )
goto V_335;
if ( F_358 && F_358 ( V_30 , V_333 , V_88 ) )
goto V_335;
if ( V_17 -> V_30 ) {
V_17 -> V_44 -> V_199 = V_30 ;
V_17 -> V_44 = V_30 ;
} else
V_17 -> V_30 = V_17 -> V_44 = V_30 ;
}
F_356 ( V_17 , V_330 ) ;
return 0 ;
V_335:
if ( V_30 )
F_355 ( V_30 ) ;
F_354 ( V_17 ) ;
return - V_98 ;
}
int F_106 ( struct V_45 * V_46 )
{
return F_361 ( V_50 , V_46 ) ;
}
int F_362 ( int V_20 , struct V_45 * V_46 )
{
return F_363 ( V_20 , V_50 , V_46 ) ;
}
int F_364 ( int V_20 , struct V_336 * V_337 ,
unsigned long V_338 )
{
return F_365 ( V_20 , V_50 , V_337 , V_338 ) ;
}
int F_366 ( struct V_336 * V_337 ,
unsigned long V_338 )
{
return F_31 ( V_50 , V_337 , V_338 ) ;
}
int F_367 ( int V_20 , struct V_336 * V_337 ,
unsigned long V_338 )
{
return F_368 ( V_20 , V_50 , V_337 , V_338 ) ;
}
void F_369 ( struct V_207 * V_208 )
{
struct V_339 * V_340 = V_176 ;
if ( V_340 -> V_208 )
return;
F_8 ( & V_208 -> V_212 ) ;
F_8 ( & V_208 -> V_211 ) ;
F_8 ( & V_208 -> V_341 ) ;
V_340 -> V_208 = V_208 ;
}
static int F_370 ( void * V_342 , struct V_209 * V_343 , struct V_209 * V_241 )
{
struct V_16 * V_344 = F_24 ( V_343 , struct V_16 , V_18 ) ;
struct V_16 * V_345 = F_24 ( V_241 , struct V_16 , V_18 ) ;
return ! ( V_344 -> V_6 < V_345 -> V_6 ||
( V_344 -> V_6 == V_345 -> V_6 && F_19 ( V_344 ) < F_19 ( V_345 ) ) ) ;
}
static void F_371 ( struct V_11 * V_6 , unsigned int V_346 ,
bool V_347 )
__releases( V_6 -> V_48 )
{
F_372 ( V_6 , V_346 , ! V_347 ) ;
if ( V_347 )
F_35 ( V_6 ) ;
else
F_26 ( V_6 ) ;
F_373 ( V_6 -> V_48 ) ;
}
static void F_374 ( struct V_207 * V_208 , bool V_347 )
{
F_375 ( V_348 ) ;
while ( ! F_58 ( & V_208 -> V_341 ) ) {
F_376 ( & V_208 -> V_341 , & V_348 ) ;
while ( ! F_58 ( & V_348 ) ) {
struct V_349 * V_350 = F_377 ( & V_348 ,
struct V_349 ,
V_212 ) ;
F_378 ( & V_350 -> V_212 ) ;
V_350 -> V_351 ( V_350 , V_347 ) ;
}
}
}
struct V_349 * F_379 ( T_8 V_352 , void * V_88 ,
int V_353 )
{
struct V_207 * V_208 = V_176 -> V_208 ;
struct V_349 * V_350 ;
if ( ! V_208 )
return NULL ;
F_226 (cb, &plug->cb_list, list)
if ( V_350 -> V_351 == V_352 && V_350 -> V_88 == V_88 )
return V_350 ;
F_186 ( V_353 < sizeof( * V_350 ) ) ;
V_350 = F_380 ( V_353 , V_265 ) ;
if ( V_350 ) {
V_350 -> V_88 = V_88 ;
V_350 -> V_351 = V_352 ;
F_381 ( & V_350 -> V_212 , & V_208 -> V_341 ) ;
}
return V_350 ;
}
void F_249 ( struct V_207 * V_208 , bool V_347 )
{
struct V_11 * V_6 ;
unsigned long V_60 ;
struct V_16 * V_17 ;
F_375 ( V_212 ) ;
unsigned int V_346 ;
F_374 ( V_208 , V_347 ) ;
if ( ! F_58 ( & V_208 -> V_211 ) )
F_382 ( V_208 , V_347 ) ;
if ( F_58 ( & V_208 -> V_212 ) )
return;
F_376 ( & V_208 -> V_212 , & V_212 ) ;
F_383 ( NULL , & V_212 , F_370 ) ;
V_6 = NULL ;
V_346 = 0 ;
F_384 ( V_60 ) ;
while ( ! F_58 ( & V_212 ) ) {
V_17 = F_248 ( V_212 . V_354 ) ;
F_321 ( & V_17 -> V_18 ) ;
F_186 ( ! V_17 -> V_6 ) ;
if ( V_17 -> V_6 != V_6 ) {
if ( V_6 )
F_371 ( V_6 , V_346 , V_347 ) ;
V_6 = V_17 -> V_6 ;
V_346 = 0 ;
F_385 ( V_6 -> V_48 ) ;
}
if ( F_13 ( F_101 ( V_6 ) ) ) {
F_319 ( V_17 , - V_105 ) ;
continue;
}
if ( F_154 ( V_17 -> V_43 ) )
F_191 ( V_6 , V_17 , V_223 ) ;
else
F_191 ( V_6 , V_17 , V_355 ) ;
V_346 ++ ;
}
if ( V_6 )
F_371 ( V_6 , V_346 , V_347 ) ;
F_386 ( V_60 ) ;
}
void F_387 ( struct V_207 * V_208 )
{
if ( V_208 != V_176 -> V_208 )
return;
F_249 ( V_208 , false ) ;
V_176 -> V_208 = NULL ;
}
void F_388 ( struct V_11 * V_6 , struct V_356 * V_173 )
{
V_6 -> V_173 = V_173 ;
V_6 -> V_284 = V_286 ;
F_389 ( V_6 -> V_173 , - 1 ) ;
F_390 ( V_6 -> V_173 ) ;
}
int F_391 ( struct V_11 * V_6 )
{
int V_101 = 0 ;
if ( ! V_6 -> V_173 )
return V_101 ;
F_25 ( V_6 -> V_48 ) ;
if ( V_6 -> V_194 ) {
V_101 = - V_102 ;
F_198 ( V_6 -> V_173 ) ;
} else {
V_6 -> V_284 = V_357 ;
}
F_27 ( V_6 -> V_48 ) ;
return V_101 ;
}
void F_392 ( struct V_11 * V_6 , int V_253 )
{
if ( ! V_6 -> V_173 )
return;
F_25 ( V_6 -> V_48 ) ;
if ( ! V_253 ) {
V_6 -> V_284 = V_285 ;
} else {
V_6 -> V_284 = V_286 ;
F_198 ( V_6 -> V_173 ) ;
}
F_27 ( V_6 -> V_48 ) ;
}
void F_393 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_173 )
return;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_284 = V_358 ;
F_27 ( V_6 -> V_48 ) ;
}
void F_394 ( struct V_11 * V_6 , int V_253 )
{
if ( ! V_6 -> V_173 )
return;
F_25 ( V_6 -> V_48 ) ;
if ( ! V_253 ) {
V_6 -> V_284 = V_286 ;
F_26 ( V_6 ) ;
F_198 ( V_6 -> V_173 ) ;
F_395 ( V_6 -> V_173 ) ;
} else {
V_6 -> V_284 = V_285 ;
}
F_27 ( V_6 -> V_48 ) ;
}
void F_396 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_284 = V_286 ;
F_198 ( V_6 -> V_173 ) ;
F_395 ( V_6 -> V_173 ) ;
F_27 ( V_6 -> V_48 ) ;
}
int T_6 F_397 ( void )
{
F_398 ( V_359 >= ( 1 << V_360 ) ) ;
F_398 ( V_360 + V_361 > 8 *
F_399 ( struct V_16 , V_43 ) ) ;
F_398 ( V_360 + V_361 > 8 *
F_399 ( struct V_30 , V_197 ) ) ;
V_50 = F_400 ( L_27 ,
V_362 | V_363 , 0 ) ;
if ( ! V_50 )
F_401 ( L_28 ) ;
V_89 = F_402 ( L_29 ,
sizeof( struct V_16 ) , 0 , V_364 , NULL ) ;
V_110 = F_402 ( L_30 ,
sizeof( struct V_11 ) , 0 , V_364 , NULL ) ;
#ifdef F_403
V_365 = F_404 ( L_5 , NULL ) ;
#endif
return 0 ;
}
