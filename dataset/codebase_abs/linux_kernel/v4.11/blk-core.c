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
F_44 (q, hctx, i) {
F_45 ( & V_55 -> V_57 ) ;
F_46 ( & V_55 -> V_47 ) ;
}
} else {
F_46 ( & V_6 -> V_47 ) ;
}
}
inline void F_47 ( struct V_11 * V_6 )
{
if ( F_13 ( F_30 ( V_6 ) ) )
return;
V_6 -> V_58 ++ ;
V_6 -> V_59 ( V_6 ) ;
V_6 -> V_58 -- ;
}
void F_26 ( struct V_11 * V_6 )
{
if ( F_13 ( F_48 ( V_6 ) ) )
return;
F_47 ( V_6 ) ;
}
void F_35 ( struct V_11 * V_6 )
{
if ( F_29 ( ! F_48 ( V_6 ) && ! F_30 ( V_6 ) ) )
F_49 ( V_50 , & V_6 -> V_47 , 0 ) ;
}
void F_50 ( struct V_11 * V_6 )
{
unsigned long V_60 ;
F_51 ( V_6 -> V_48 , V_60 ) ;
F_26 ( V_6 ) ;
F_52 ( V_6 -> V_48 , V_60 ) ;
}
void F_53 ( struct V_11 * V_6 )
{
F_54 ( & V_6 -> V_61 ) ;
}
static void F_55 ( struct V_11 * V_6 , bool V_62 )
__releases( V_6 -> V_48 )
__acquires( V_6 -> V_48 )
{
int V_56 ;
F_56 ( V_6 -> V_48 ) ;
while ( true ) {
bool V_63 = false ;
if ( V_6 -> V_64 )
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
if ( ! F_59 ( & V_6 -> V_65 ) && V_6 -> V_59 )
F_26 ( V_6 ) ;
V_63 |= V_6 -> V_66 ;
V_63 |= V_6 -> V_58 ;
if ( V_62 ) {
struct V_67 * V_68 = F_60 ( V_6 , NULL ) ;
V_63 |= ! F_59 ( & V_6 -> V_65 ) ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
V_63 |= V_6 -> V_69 [ V_56 ] ;
V_63 |= V_6 -> V_70 [ V_56 ] ;
if ( V_68 )
V_63 |= ! F_59 ( & V_68 -> V_71 [ V_56 ] ) ;
}
}
if ( ! V_63 )
break;
F_27 ( V_6 -> V_48 ) ;
F_61 ( 10 ) ;
F_25 ( V_6 -> V_48 ) ;
}
if ( V_6 -> V_59 ) {
struct V_1 * V_2 ;
F_62 (rl, q)
for ( V_56 = 0 ; V_56 < F_63 ( V_2 -> V_72 ) ; V_56 ++ )
F_64 ( & V_2 -> V_72 [ V_56 ] ) ;
}
}
void F_65 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_73 ++ ;
F_41 ( V_74 , V_6 ) ;
F_27 ( V_6 -> V_48 ) ;
if ( F_66 ( V_6 ) ) {
F_25 ( V_6 -> V_48 ) ;
F_55 ( V_6 , false ) ;
F_27 ( V_6 -> V_48 ) ;
F_67 () ;
}
}
void F_68 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
if ( ! -- V_6 -> V_73 )
F_34 ( V_74 , V_6 ) ;
F_69 ( V_6 -> V_73 < 0 ) ;
F_27 ( V_6 -> V_48 ) ;
}
void F_70 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
F_41 ( V_75 , V_6 ) ;
F_27 ( V_6 -> V_48 ) ;
if ( V_6 -> V_53 )
F_71 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_25 ( V_6 -> V_48 ) ;
F_62 (rl, q) {
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
F_70 ( V_6 ) ;
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
F_55 ( V_6 , true ) ;
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
F_53 ( V_6 ) ;
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
return 0 ;
}
void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_76 )
F_92 ( V_2 -> V_76 ) ;
}
struct V_11 * F_93 ( T_2 V_87 )
{
return F_94 ( V_87 , V_99 ) ;
}
int F_95 ( struct V_11 * V_6 , bool V_100 )
{
while ( true ) {
int V_101 ;
if ( F_96 ( & V_6 -> V_85 ) )
return 0 ;
if ( V_100 )
return - V_102 ;
V_101 = F_97 ( V_6 -> V_103 ,
! F_98 ( & V_6 -> V_104 ) ||
F_99 ( V_6 ) ) ;
if ( F_99 ( V_6 ) )
return - V_105 ;
if ( V_101 )
return V_101 ;
}
}
void F_100 ( struct V_11 * V_6 )
{
F_101 ( & V_6 -> V_85 ) ;
}
static void F_102 ( struct V_106 * V_107 )
{
struct V_11 * V_6 =
F_24 ( V_107 , struct V_11 , V_85 ) ;
F_64 ( & V_6 -> V_103 ) ;
}
static void F_103 ( unsigned long V_88 )
{
struct V_11 * V_6 = (struct V_11 * ) V_88 ;
F_104 ( & V_6 -> V_108 ) ;
}
struct V_11 * F_94 ( T_2 V_87 , int V_109 )
{
struct V_11 * V_6 ;
V_6 = F_81 ( V_110 ,
V_87 | V_111 , V_109 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_112 = F_105 ( & V_113 , 0 , 0 , V_87 ) ;
if ( V_6 -> V_112 < 0 )
goto V_114;
V_6 -> V_115 = F_106 ( V_116 , 0 ) ;
if ( ! V_6 -> V_115 )
goto V_117;
V_6 -> V_8 = F_107 ( V_87 , V_109 ) ;
if ( ! V_6 -> V_8 )
goto V_118;
V_6 -> V_8 -> V_119 =
( V_120 * 1024 ) / V_121 ;
V_6 -> V_8 -> V_122 = V_123 ;
V_6 -> V_8 -> V_124 = L_5 ;
V_6 -> V_90 = V_109 ;
F_108 ( & V_6 -> V_8 -> V_84 ,
V_125 , ( unsigned long ) V_6 ) ;
F_108 ( & V_6 -> V_52 , F_103 , ( unsigned long ) V_6 ) ;
F_8 ( & V_6 -> V_65 ) ;
F_8 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_126 ) ;
#ifdef F_109
F_8 ( & V_6 -> V_127 ) ;
#endif
F_110 ( & V_6 -> V_47 , F_23 ) ;
F_111 ( & V_6 -> V_61 , & V_128 ) ;
F_112 ( & V_6 -> V_80 ) ;
F_113 ( & V_6 -> V_86 ) ;
V_6 -> V_48 = & V_6 -> V_86 ;
V_6 -> V_73 = 1 ;
F_114 ( V_74 , & V_6 -> V_129 ) ;
F_89 ( & V_6 -> V_103 ) ;
if ( F_115 ( & V_6 -> V_85 ,
F_102 ,
V_130 , V_131 ) )
goto V_132;
if ( F_116 ( V_6 ) )
goto V_133;
return V_6 ;
V_133:
F_79 ( & V_6 -> V_85 ) ;
V_132:
F_117 ( V_6 -> V_8 ) ;
V_118:
F_118 ( V_6 -> V_115 ) ;
V_117:
F_119 ( & V_113 , V_6 -> V_112 ) ;
V_114:
F_83 ( V_110 , V_6 ) ;
return NULL ;
}
struct V_11 * F_120 ( T_3 * V_134 , T_1 * V_79 )
{
return F_121 ( V_134 , V_79 , V_99 ) ;
}
struct V_11 *
F_121 ( T_3 * V_134 , T_1 * V_79 , int V_109 )
{
struct V_11 * V_6 ;
V_6 = F_94 ( V_131 , V_109 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_59 = V_134 ;
if ( V_79 )
V_6 -> V_48 = V_79 ;
if ( F_122 ( V_6 ) < 0 ) {
F_73 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
int F_122 ( struct V_11 * V_6 )
{
V_6 -> V_68 = F_123 ( V_6 , V_99 , V_6 -> V_92 ) ;
if ( ! V_6 -> V_68 )
return - V_98 ;
if ( V_6 -> V_93 && V_6 -> V_93 ( V_6 , V_6 -> V_68 -> V_135 , V_131 ) )
goto V_136;
if ( F_88 ( & V_6 -> V_7 , V_6 , V_131 ) )
goto V_137;
F_124 ( & V_6 -> V_108 , V_138 ) ;
V_6 -> V_129 |= V_139 ;
F_125 ( V_6 , V_140 ) ;
V_6 -> V_141 = V_142 ;
F_74 ( & V_6 -> V_80 ) ;
if ( F_126 ( V_6 , NULL ) ) {
F_75 ( & V_6 -> V_80 ) ;
goto V_137;
}
F_75 ( & V_6 -> V_80 ) ;
return 0 ;
V_137:
if ( V_6 -> V_94 )
V_6 -> V_94 ( V_6 , V_6 -> V_68 -> V_135 ) ;
V_136:
F_127 ( V_6 -> V_68 ) ;
F_128 ( V_6 ) ;
return - V_98 ;
}
bool F_129 ( struct V_11 * V_6 )
{
if ( F_29 ( ! F_99 ( V_6 ) ) ) {
F_130 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_131 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_33 & V_143 ) {
F_132 ( V_2 -> V_6 , V_17 ) ;
if ( V_17 -> V_144 . V_145 )
F_133 ( V_17 -> V_144 . V_145 -> V_146 ) ;
}
F_134 ( V_17 , V_2 -> V_76 ) ;
}
static inline int F_135 ( struct V_11 * V_6 , struct V_147 * V_146 )
{
if ( ! V_146 )
return 0 ;
return V_146 -> V_148 == V_6 -> V_149 ||
( V_146 -> V_148 > 0
&& F_136 ( V_28 , V_146 -> V_150 + V_151 ) ) ;
}
static void F_137 ( struct V_11 * V_6 , struct V_147 * V_146 )
{
if ( ! V_146 || F_135 ( V_6 , V_146 ) )
return;
V_146 -> V_148 = V_6 -> V_149 ;
V_146 -> V_150 = V_28 ;
}
static void F_138 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_95 [ V_3 ] < F_139 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_95 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_140 ( & V_2 -> V_72 [ V_3 ] ) )
F_72 ( & V_2 -> V_72 [ V_3 ] ) ;
F_141 ( V_2 , V_3 ) ;
}
}
static void F_142 ( struct V_1 * V_2 , bool V_3 ,
T_4 V_33 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
V_6 -> V_69 [ V_3 ] -- ;
V_2 -> V_95 [ V_3 ] -- ;
if ( V_33 & V_143 )
V_6 -> V_66 -- ;
F_138 ( V_2 , V_3 ) ;
if ( F_13 ( V_2 -> V_96 [ V_3 ^ 1 ] ) )
F_138 ( V_2 , V_3 ^ 1 ) ;
}
int F_143 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_152 , V_153 ;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_152 = F_144 ( V_6 ) ;
V_153 = F_139 ( V_6 ) ;
F_62 (rl, q) {
if ( V_2 -> V_95 [ V_77 ] >= V_152 )
F_4 ( V_2 , V_77 ) ;
else if ( V_2 -> V_95 [ V_77 ] < V_153 )
F_1 ( V_2 , V_77 ) ;
if ( V_2 -> V_95 [ V_78 ] >= V_152 )
F_4 ( V_2 , V_78 ) ;
else if ( V_2 -> V_95 [ V_78 ] < V_153 )
F_1 ( V_2 , V_78 ) ;
if ( V_2 -> V_95 [ V_77 ] >= V_6 -> V_13 ) {
F_145 ( V_2 , V_77 ) ;
} else {
F_141 ( V_2 , V_77 ) ;
F_72 ( & V_2 -> V_72 [ V_77 ] ) ;
}
if ( V_2 -> V_95 [ V_78 ] >= V_6 -> V_13 ) {
F_145 ( V_2 , V_78 ) ;
} else {
F_141 ( V_2 , V_78 ) ;
F_72 ( & V_2 -> V_72 [ V_78 ] ) ;
}
}
F_27 ( V_6 -> V_48 ) ;
return 0 ;
}
static struct V_16 * F_146 ( struct V_1 * V_2 , unsigned int V_154 ,
struct V_30 * V_30 , T_2 V_87 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 ;
struct V_155 * V_156 = V_6 -> V_64 -> type ;
struct V_147 * V_146 = F_147 ( V_30 ) ;
struct V_157 * V_145 = NULL ;
const bool V_158 = F_148 ( V_154 ) ;
int V_159 ;
T_4 V_33 = V_160 ;
if ( F_13 ( F_99 ( V_6 ) ) )
return F_149 ( - V_105 ) ;
V_159 = F_150 ( V_6 , V_154 ) ;
if ( V_159 == V_161 )
goto V_162;
if ( V_2 -> V_95 [ V_158 ] + 1 >= F_144 ( V_6 ) ) {
if ( V_2 -> V_95 [ V_158 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_151 ( V_2 , V_158 ) ) {
F_137 ( V_6 , V_146 ) ;
F_145 ( V_2 , V_158 ) ;
} else {
if ( V_159 != V_163
&& ! F_135 ( V_6 , V_146 ) ) {
return F_149 ( - V_98 ) ;
}
}
}
F_4 ( V_2 , V_158 ) ;
}
if ( V_2 -> V_95 [ V_158 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_149 ( - V_98 ) ;
V_6 -> V_69 [ V_158 ] ++ ;
V_2 -> V_95 [ V_158 ] ++ ;
V_2 -> V_96 [ V_158 ] = 0 ;
if ( ! F_152 ( V_154 ) && ! F_153 ( V_6 ) ) {
V_33 |= V_143 ;
V_6 -> V_66 ++ ;
if ( V_156 -> V_164 && V_146 )
V_145 = F_154 ( V_146 , V_6 ) ;
}
if ( F_155 ( V_6 ) )
V_33 |= V_165 ;
F_27 ( V_6 -> V_48 ) ;
V_17 = F_156 ( V_2 -> V_76 , V_87 ) ;
if ( ! V_17 )
goto V_166;
F_7 ( V_6 , V_17 ) ;
F_157 ( V_17 , V_2 ) ;
F_158 ( V_17 , V_146 ) ;
V_17 -> V_43 = V_154 ;
V_17 -> V_33 = V_33 ;
if ( V_33 & V_143 ) {
if ( F_13 ( V_156 -> V_164 && ! V_145 ) ) {
if ( V_146 )
V_145 = F_159 ( V_146 , V_6 , V_87 ) ;
if ( ! V_145 )
goto V_167;
}
V_17 -> V_144 . V_145 = V_145 ;
if ( F_13 ( F_160 ( V_6 , V_17 , V_30 , V_87 ) ) )
goto V_167;
if ( V_145 )
F_161 ( V_145 -> V_146 ) ;
}
V_168:
if ( F_135 ( V_6 , V_146 ) )
V_146 -> V_148 -- ;
F_162 ( V_6 , V_30 , V_154 ) ;
return V_17 ;
V_167:
F_163 ( V_169 L_6 ,
V_170 , F_164 ( V_6 -> V_8 -> V_171 ) ) ;
V_17 -> V_33 &= ~ V_143 ;
V_17 -> V_144 . V_145 = NULL ;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_66 -- ;
F_27 ( V_6 -> V_48 ) ;
goto V_168;
V_166:
F_25 ( V_6 -> V_48 ) ;
F_142 ( V_2 , V_158 , V_33 ) ;
V_162:
if ( F_13 ( V_2 -> V_95 [ V_158 ] == 0 ) )
V_2 -> V_96 [ V_158 ] = 1 ;
return F_149 ( - V_98 ) ;
}
static struct V_16 * F_165 ( struct V_11 * V_6 , unsigned int V_154 ,
struct V_30 * V_30 , T_2 V_87 )
{
const bool V_158 = F_148 ( V_154 ) ;
F_166 ( V_72 ) ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = F_167 ( V_6 , V_30 ) ;
V_172:
V_17 = F_146 ( V_2 , V_154 , V_30 , V_87 ) ;
if ( ! F_168 ( V_17 ) )
return V_17 ;
if ( ! F_169 ( V_87 ) || F_13 ( F_99 ( V_6 ) ) ) {
F_170 ( V_2 ) ;
return V_17 ;
}
F_171 ( & V_2 -> V_72 [ V_158 ] , & V_72 ,
V_173 ) ;
F_172 ( V_6 , V_30 , V_154 ) ;
F_27 ( V_6 -> V_48 ) ;
F_173 () ;
F_137 ( V_6 , V_174 -> V_147 ) ;
F_25 ( V_6 -> V_48 ) ;
F_174 ( & V_2 -> V_72 [ V_158 ] , & V_72 ) ;
goto V_172;
}
static struct V_16 * F_175 ( struct V_11 * V_6 , int V_175 ,
T_2 V_87 )
{
struct V_16 * V_17 ;
F_176 ( V_87 , V_6 -> V_90 ) ;
F_25 ( V_6 -> V_48 ) ;
V_17 = F_165 ( V_6 , V_175 , NULL , V_87 ) ;
if ( F_168 ( V_17 ) ) {
F_27 ( V_6 -> V_48 ) ;
return V_17 ;
}
V_17 -> V_176 = 0 ;
V_17 -> V_21 = ( V_22 ) - 1 ;
V_17 -> V_30 = V_17 -> V_44 = NULL ;
return V_17 ;
}
struct V_16 * F_177 ( struct V_11 * V_6 , int V_175 , T_2 V_87 )
{
if ( V_6 -> V_53 )
return F_178 ( V_6 , V_175 ,
( V_87 & V_177 ) ?
0 : V_178 ) ;
else
return F_175 ( V_6 , V_175 , V_87 ) ;
}
void F_179 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
F_180 ( V_17 ) ;
F_181 ( V_17 ) ;
F_182 ( V_6 , V_17 ) ;
F_183 ( V_6 -> V_179 , & V_17 -> V_180 ) ;
if ( V_17 -> V_33 & V_181 )
F_184 ( V_6 , V_17 ) ;
F_185 ( F_186 ( V_17 ) ) ;
F_187 ( V_6 , V_17 ) ;
}
static void F_188 ( struct V_11 * V_6 , struct V_16 * V_17 ,
int V_182 )
{
F_189 ( V_17 , true ) ;
F_190 ( V_6 , V_17 , V_182 ) ;
}
static void F_191 ( int V_20 , struct V_183 * V_29 ,
unsigned long V_184 )
{
int V_185 ;
if ( V_184 == V_29 -> V_186 )
return;
V_185 = F_192 ( V_29 ) ;
if ( V_185 ) {
F_193 ( V_20 , V_29 , V_187 ,
V_185 * ( V_184 - V_29 -> V_186 ) ) ;
F_193 ( V_20 , V_29 , V_188 , ( V_184 - V_29 -> V_186 ) ) ;
}
V_29 -> V_186 = V_184 ;
}
void F_194 ( int V_20 , struct V_183 * V_29 )
{
unsigned long V_184 = V_28 ;
if ( V_29 -> V_189 )
F_191 ( V_20 , & F_195 ( V_29 ) -> V_190 , V_184 ) ;
F_191 ( V_20 , V_29 , V_184 ) ;
}
static void F_196 ( struct V_16 * V_17 )
{
if ( V_17 -> V_6 -> V_171 && ! ( V_17 -> V_33 & V_191 ) && ! -- V_17 -> V_6 -> V_192 )
F_197 ( V_17 -> V_6 -> V_171 ) ;
}
static inline void F_196 ( struct V_16 * V_17 ) {}
void F_198 ( struct V_11 * V_6 , struct V_16 * V_193 )
{
T_4 V_33 = V_193 -> V_33 ;
if ( F_13 ( ! V_6 ) )
return;
if ( V_6 -> V_53 ) {
F_199 ( V_193 ) ;
return;
}
F_196 ( V_193 ) ;
F_200 ( V_6 , V_193 ) ;
F_37 ( V_193 -> V_30 != NULL ) ;
F_201 ( V_6 -> V_179 , & V_193 -> V_180 ) ;
if ( V_33 & V_160 ) {
struct V_1 * V_2 = F_202 ( V_193 ) ;
bool V_3 = F_148 ( V_193 -> V_43 ) ;
F_185 ( ! F_59 ( & V_193 -> V_18 ) ) ;
F_185 ( F_203 ( V_193 ) ) ;
F_131 ( V_2 , V_193 ) ;
F_142 ( V_2 , V_3 , V_33 ) ;
F_170 ( V_2 ) ;
}
}
void F_204 ( struct V_16 * V_193 )
{
struct V_11 * V_6 = V_193 -> V_6 ;
if ( V_6 -> V_53 )
F_199 ( V_193 ) ;
else {
unsigned long V_60 ;
F_51 ( V_6 -> V_48 , V_60 ) ;
F_198 ( V_6 , V_193 ) ;
F_52 ( V_6 -> V_48 , V_60 ) ;
}
}
bool F_205 ( struct V_11 * V_6 , struct V_16 * V_193 ,
struct V_30 * V_30 )
{
const int V_194 = V_30 -> V_195 & V_196 ;
if ( ! F_206 ( V_6 , V_193 , V_30 ) )
return false ;
F_207 ( V_6 , V_193 , V_30 ) ;
if ( ( V_193 -> V_43 & V_196 ) != V_194 )
F_208 ( V_193 ) ;
V_193 -> V_44 -> V_197 = V_30 ;
V_193 -> V_44 = V_30 ;
V_193 -> V_176 += V_30 -> V_36 . V_37 ;
V_193 -> V_198 = F_209 ( V_193 -> V_198 , F_210 ( V_30 ) ) ;
F_189 ( V_193 , false ) ;
return true ;
}
bool F_211 ( struct V_11 * V_6 , struct V_16 * V_193 ,
struct V_30 * V_30 )
{
const int V_194 = V_30 -> V_195 & V_196 ;
if ( ! F_212 ( V_6 , V_193 , V_30 ) )
return false ;
F_213 ( V_6 , V_193 , V_30 ) ;
if ( ( V_193 -> V_43 & V_196 ) != V_194 )
F_208 ( V_193 ) ;
V_30 -> V_197 = V_193 -> V_30 ;
V_193 -> V_30 = V_30 ;
V_193 -> V_21 = V_30 -> V_36 . V_199 ;
V_193 -> V_176 += V_30 -> V_36 . V_37 ;
V_193 -> V_198 = F_209 ( V_193 -> V_198 , F_210 ( V_30 ) ) ;
F_189 ( V_193 , false ) ;
return true ;
}
bool F_214 ( struct V_11 * V_6 , struct V_16 * V_193 ,
struct V_30 * V_30 )
{
unsigned short V_200 = F_215 ( V_193 ) ;
if ( V_200 >= F_216 ( V_6 ) )
goto V_201;
if ( F_20 ( V_193 ) + F_217 ( V_30 ) >
F_218 ( V_193 , F_19 ( V_193 ) ) )
goto V_201;
V_193 -> V_44 -> V_197 = V_30 ;
V_193 -> V_44 = V_30 ;
V_193 -> V_176 += V_30 -> V_36 . V_37 ;
V_193 -> V_198 = F_209 ( V_193 -> V_198 , F_210 ( V_30 ) ) ;
V_193 -> V_202 = V_200 + 1 ;
F_189 ( V_193 , false ) ;
return true ;
V_201:
F_219 ( V_6 , V_193 ) ;
return false ;
}
bool F_220 ( struct V_11 * V_6 , struct V_30 * V_30 ,
unsigned int * V_203 ,
struct V_16 * * V_204 )
{
struct V_205 * V_206 ;
struct V_16 * V_17 ;
struct V_207 * V_208 ;
V_206 = V_174 -> V_206 ;
if ( ! V_206 )
return false ;
* V_203 = 0 ;
if ( V_6 -> V_53 )
V_208 = & V_206 -> V_209 ;
else
V_208 = & V_206 -> V_210 ;
F_221 (rq, plug_list, queuelist) {
bool V_211 = false ;
if ( V_17 -> V_6 == V_6 ) {
( * V_203 ) ++ ;
if ( V_204 )
* V_204 = V_17 ;
}
if ( V_17 -> V_6 != V_6 || ! F_222 ( V_17 , V_30 ) )
continue;
switch ( F_223 ( V_17 , V_30 ) ) {
case V_212 :
V_211 = F_205 ( V_6 , V_17 , V_30 ) ;
break;
case V_213 :
V_211 = F_211 ( V_6 , V_17 , V_30 ) ;
break;
case V_214 :
V_211 = F_214 ( V_6 , V_17 , V_30 ) ;
break;
default:
break;
}
if ( V_211 )
return true ;
}
return false ;
}
unsigned int F_224 ( struct V_11 * V_6 )
{
struct V_205 * V_206 ;
struct V_16 * V_17 ;
struct V_207 * V_208 ;
unsigned int V_101 = 0 ;
V_206 = V_174 -> V_206 ;
if ( ! V_206 )
goto V_168;
if ( V_6 -> V_53 )
V_208 = & V_206 -> V_209 ;
else
V_208 = & V_206 -> V_210 ;
F_225 (rq, plug_list, queuelist) {
if ( V_17 -> V_6 == V_6 )
V_101 ++ ;
}
V_168:
return V_101 ;
}
void F_226 ( struct V_16 * V_193 , struct V_30 * V_30 )
{
if ( V_30 -> V_195 & V_215 )
V_193 -> V_43 |= V_196 ;
V_193 -> V_216 = 0 ;
V_193 -> V_21 = V_30 -> V_36 . V_199 ;
if ( F_227 ( F_210 ( V_30 ) ) )
V_193 -> V_198 = F_210 ( V_30 ) ;
F_228 ( V_193 -> V_6 , V_193 , V_30 ) ;
}
static T_5 V_140 ( struct V_11 * V_6 , struct V_30 * V_30 )
{
struct V_205 * V_206 ;
int V_182 = V_217 ;
struct V_16 * V_193 , * free ;
unsigned int V_203 = 0 ;
unsigned int V_218 ;
F_229 ( V_6 , & V_30 ) ;
F_230 ( V_6 , & V_30 , V_6 -> V_115 ) ;
if ( F_231 ( V_30 ) && F_232 ( V_30 ) ) {
V_30 -> V_32 = - V_219 ;
F_16 ( V_30 ) ;
return V_220 ;
}
if ( F_152 ( V_30 -> V_195 ) ) {
F_25 ( V_6 -> V_48 ) ;
V_182 = V_221 ;
goto V_222;
}
if ( ! F_233 ( V_6 ) ) {
if ( F_220 ( V_6 , V_30 , & V_203 , NULL ) )
return V_220 ;
} else
V_203 = F_224 ( V_6 ) ;
F_25 ( V_6 -> V_48 ) ;
switch ( F_234 ( V_6 , & V_193 , V_30 ) ) {
case V_212 :
if ( ! F_205 ( V_6 , V_193 , V_30 ) )
break;
F_235 ( V_6 , V_193 , V_30 ) ;
free = F_236 ( V_6 , V_193 ) ;
if ( free )
F_198 ( V_6 , free ) ;
else
F_237 ( V_6 , V_193 , V_212 ) ;
goto V_223;
case V_213 :
if ( ! F_211 ( V_6 , V_193 , V_30 ) )
break;
F_235 ( V_6 , V_193 , V_30 ) ;
free = F_238 ( V_6 , V_193 ) ;
if ( free )
F_198 ( V_6 , free ) ;
else
F_237 ( V_6 , V_193 , V_213 ) ;
goto V_223;
default:
break;
}
V_222:
V_218 = F_239 ( V_6 -> V_179 , V_30 , V_6 -> V_48 ) ;
V_193 = F_165 ( V_6 , V_30 -> V_195 , V_30 , V_224 ) ;
if ( F_168 ( V_193 ) ) {
F_240 ( V_6 -> V_179 , V_218 ) ;
V_30 -> V_32 = F_241 ( V_193 ) ;
F_16 ( V_30 ) ;
goto V_223;
}
F_242 ( & V_193 -> V_180 , V_218 ) ;
F_226 ( V_193 , V_30 ) ;
if ( F_243 ( V_225 , & V_6 -> V_129 ) )
V_193 -> V_20 = F_244 () ;
V_206 = V_174 -> V_206 ;
if ( V_206 ) {
if ( ! V_203 || F_59 ( & V_206 -> V_210 ) )
F_245 ( V_6 ) ;
else {
struct V_16 * V_226 = F_246 ( V_206 -> V_210 . V_227 ) ;
if ( V_203 >= V_228 ||
F_22 ( V_226 ) >= V_229 ) {
F_247 ( V_206 , false ) ;
F_245 ( V_6 ) ;
}
}
F_248 ( & V_193 -> V_18 , & V_206 -> V_210 ) ;
F_189 ( V_193 , true ) ;
} else {
F_25 ( V_6 -> V_48 ) ;
F_188 ( V_6 , V_193 , V_182 ) ;
F_26 ( V_6 ) ;
V_223:
F_27 ( V_6 -> V_48 ) ;
}
return V_220 ;
}
static inline void F_249 ( struct V_30 * V_30 )
{
struct V_230 * V_231 = V_30 -> V_232 ;
if ( V_231 != V_231 -> V_233 &&
( F_217 ( V_30 ) || F_250 ( V_30 ) == V_234 ) ) {
struct V_183 * V_235 = V_231 -> V_236 ;
V_30 -> V_36 . V_199 += V_235 -> V_237 ;
V_30 -> V_232 = V_231 -> V_233 ;
F_251 ( F_252 ( V_30 -> V_232 ) , V_30 ,
V_231 -> V_238 ,
V_30 -> V_36 . V_199 - V_235 -> V_237 ) ;
}
}
static void F_253 ( struct V_30 * V_30 )
{
char V_239 [ V_240 ] ;
F_18 ( V_40 L_7 ) ;
F_18 ( V_40 L_8 ,
F_254 ( V_30 -> V_232 , V_239 ) ,
V_30 -> V_195 ,
( unsigned long long ) F_255 ( V_30 ) ,
( long long ) ( F_256 ( V_30 -> V_232 -> V_241 ) >> 9 ) ) ;
}
static int T_6 F_257 ( char * V_242 )
{
return F_258 ( & V_243 , V_242 ) ;
}
static bool F_259 ( struct V_183 * V_29 , unsigned int V_244 )
{
return V_29 -> V_245 && F_260 ( & V_243 , V_244 ) ;
}
static int T_6 F_261 ( void )
{
struct V_246 * V_247 = F_262 ( L_9 ,
NULL , & V_243 ) ;
return F_263 ( V_247 ) ;
}
static inline bool F_259 ( struct V_183 * V_29 ,
unsigned int V_244 )
{
return false ;
}
static inline int F_264 ( struct V_30 * V_30 , unsigned int V_248 )
{
V_22 V_249 ;
if ( ! V_248 )
return 0 ;
V_249 = F_256 ( V_30 -> V_232 -> V_241 ) >> 9 ;
if ( V_249 ) {
V_22 V_250 = V_30 -> V_36 . V_199 ;
if ( V_249 < V_248 || V_249 - V_248 < V_250 ) {
F_253 ( V_30 ) ;
return 1 ;
}
}
return 0 ;
}
static T_7 bool
F_265 ( struct V_30 * V_30 )
{
struct V_11 * V_6 ;
int V_248 = F_217 ( V_30 ) ;
int V_251 = - V_219 ;
char V_239 [ V_240 ] ;
struct V_183 * V_29 ;
F_266 () ;
if ( F_264 ( V_30 , V_248 ) )
goto V_252;
V_6 = F_252 ( V_30 -> V_232 ) ;
if ( F_13 ( ! V_6 ) ) {
F_18 ( V_253
L_10
L_11 ,
F_254 ( V_30 -> V_232 , V_239 ) ,
( long long ) V_30 -> V_36 . V_199 ) ;
goto V_252;
}
V_29 = V_30 -> V_232 -> V_236 ;
if ( F_259 ( V_29 , V_30 -> V_36 . V_37 ) ||
F_259 ( & F_195 ( V_29 ) -> V_190 ,
V_30 -> V_36 . V_37 ) )
goto V_252;
F_249 ( V_30 ) ;
if ( F_264 ( V_30 , V_248 ) )
goto V_252;
if ( F_152 ( V_30 -> V_195 ) &&
! F_243 ( V_254 , & V_6 -> V_129 ) ) {
V_30 -> V_195 &= ~ ( V_255 | V_256 ) ;
if ( ! V_248 ) {
V_251 = 0 ;
goto V_252;
}
}
switch ( F_250 ( V_30 ) ) {
case V_257 :
if ( ! F_267 ( V_6 ) )
goto V_258;
break;
case V_259 :
if ( ! F_268 ( V_6 ) )
goto V_258;
break;
case V_260 :
if ( ! F_269 ( V_30 -> V_232 ) )
goto V_258;
break;
case V_261 :
case V_234 :
if ( ! F_270 ( V_30 -> V_232 ) )
goto V_258;
break;
case V_262 :
if ( ! F_271 ( V_30 -> V_232 ) )
goto V_258;
break;
default:
break;
}
F_176 ( V_263 , V_6 -> V_90 ) ;
if ( ! F_272 ( V_6 , V_30 ) )
return false ;
F_273 ( V_6 , V_30 ) ;
return true ;
V_258:
V_251 = - V_264 ;
V_252:
V_30 -> V_32 = V_251 ;
F_16 ( V_30 ) ;
return false ;
}
T_5 F_274 ( struct V_30 * V_30 )
{
struct V_265 V_266 [ 2 ] ;
T_5 V_101 = V_220 ;
if ( ! F_265 ( V_30 ) )
goto V_168;
if ( V_174 -> V_265 ) {
F_275 ( & V_174 -> V_265 [ 0 ] , V_30 ) ;
goto V_168;
}
F_185 ( V_30 -> V_197 ) ;
F_276 ( & V_266 [ 0 ] ) ;
V_174 -> V_265 = V_266 ;
do {
struct V_11 * V_6 = F_252 ( V_30 -> V_232 ) ;
if ( F_29 ( F_95 ( V_6 , false ) == 0 ) ) {
struct V_265 V_267 , V_268 ;
V_266 [ 1 ] = V_266 [ 0 ] ;
F_276 ( & V_266 [ 0 ] ) ;
V_101 = V_6 -> V_269 ( V_6 , V_30 ) ;
F_100 ( V_6 ) ;
F_276 ( & V_267 ) ;
F_276 ( & V_268 ) ;
while ( ( V_30 = F_277 ( & V_266 [ 0 ] ) ) != NULL )
if ( V_6 == F_252 ( V_30 -> V_232 ) )
F_275 ( & V_268 , V_30 ) ;
else
F_275 ( & V_267 , V_30 ) ;
F_278 ( & V_266 [ 0 ] , & V_267 ) ;
F_278 ( & V_266 [ 0 ] , & V_268 ) ;
F_278 ( & V_266 [ 0 ] , & V_266 [ 1 ] ) ;
} else {
F_279 ( V_30 ) ;
}
V_30 = F_277 ( & V_266 [ 0 ] ) ;
} while ( V_30 );
V_174 -> V_265 = NULL ;
V_168:
return V_101 ;
}
T_5 F_280 ( struct V_30 * V_30 )
{
if ( F_281 ( V_30 ) ) {
unsigned int V_95 ;
if ( F_13 ( F_250 ( V_30 ) == V_260 ) )
V_95 = F_282 ( V_30 -> V_232 ) >> 9 ;
else
V_95 = F_217 ( V_30 ) ;
if ( F_283 ( F_250 ( V_30 ) ) ) {
F_284 ( V_270 , V_95 ) ;
} else {
F_285 ( V_30 -> V_36 . V_37 ) ;
F_284 ( V_271 , V_95 ) ;
}
if ( F_13 ( V_272 ) ) {
char V_239 [ V_240 ] ;
F_18 ( V_273 L_12 ,
V_174 -> V_274 , F_286 ( V_174 ) ,
F_283 ( F_250 ( V_30 ) ) ? L_13 : L_14 ,
( unsigned long long ) V_30 -> V_36 . V_199 ,
F_254 ( V_30 -> V_232 , V_239 ) ,
V_95 ) ;
}
}
return F_274 ( V_30 ) ;
}
static int F_287 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( F_20 ( V_17 ) > F_288 ( V_6 , F_289 ( V_17 ) ) ) {
F_18 ( V_253 L_15 , V_170 ) ;
return - V_219 ;
}
F_290 ( V_17 ) ;
if ( V_17 -> V_202 > F_291 ( V_6 ) ) {
F_18 ( V_253 L_16 , V_170 ) ;
return - V_219 ;
}
return 0 ;
}
int F_292 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
unsigned long V_60 ;
int V_182 = V_275 ;
if ( F_287 ( V_6 , V_17 ) )
return - V_219 ;
if ( V_17 -> V_41 &&
F_259 ( & V_17 -> V_41 -> V_190 , F_22 ( V_17 ) ) )
return - V_219 ;
if ( V_6 -> V_53 ) {
if ( F_155 ( V_6 ) )
F_189 ( V_17 , true ) ;
F_293 ( V_17 , false , true , false , false ) ;
return 0 ;
}
F_51 ( V_6 -> V_48 , V_60 ) ;
if ( F_13 ( F_99 ( V_6 ) ) ) {
F_52 ( V_6 -> V_48 , V_60 ) ;
return - V_105 ;
}
F_185 ( F_186 ( V_17 ) ) ;
if ( F_152 ( V_17 -> V_43 ) )
V_182 = V_221 ;
F_188 ( V_6 , V_17 , V_182 ) ;
if ( V_182 == V_221 )
F_26 ( V_6 ) ;
F_52 ( V_6 -> V_48 , V_60 ) ;
return 0 ;
}
unsigned int F_294 ( const struct V_16 * V_17 )
{
unsigned int V_194 = V_17 -> V_43 & V_196 ;
unsigned int V_244 = 0 ;
struct V_30 * V_30 ;
if ( ! ( V_17 -> V_33 & V_276 ) )
return F_22 ( V_17 ) ;
for ( V_30 = V_17 -> V_30 ; V_30 ; V_30 = V_30 -> V_197 ) {
if ( ( V_30 -> V_195 & V_194 ) != V_194 )
break;
V_244 += V_30 -> V_36 . V_37 ;
}
F_185 ( F_22 ( V_17 ) && ! V_244 ) ;
return V_244 ;
}
void F_295 ( struct V_16 * V_193 , unsigned int V_244 )
{
if ( F_296 ( V_193 ) ) {
const int V_175 = F_297 ( V_193 ) ;
struct V_183 * V_29 ;
int V_20 ;
V_20 = F_298 () ;
V_29 = V_193 -> V_29 ;
F_299 ( V_20 , V_29 , V_277 [ V_175 ] , V_244 >> 9 ) ;
F_300 () ;
}
}
void F_301 ( struct V_16 * V_193 )
{
if ( F_296 ( V_193 ) && ! ( V_193 -> V_33 & V_38 ) ) {
unsigned long V_278 = V_28 - V_193 -> V_27 ;
const int V_175 = F_297 ( V_193 ) ;
struct V_183 * V_29 ;
int V_20 ;
V_20 = F_298 () ;
V_29 = V_193 -> V_29 ;
F_302 ( V_20 , V_29 , V_279 [ V_175 ] ) ;
F_299 ( V_20 , V_29 , V_280 [ V_175 ] , V_278 ) ;
F_194 ( V_20 , V_29 ) ;
F_303 ( V_29 , V_175 ) ;
F_304 ( V_29 ) ;
F_300 () ;
}
}
static struct V_16 * F_305 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( V_6 -> V_171 && ( V_6 -> V_281 == V_282 ||
( V_6 -> V_281 != V_283 && ! ( V_17 -> V_33 & V_191 ) ) ) )
return NULL ;
else
return V_17 ;
}
static inline struct V_16 * F_305 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
return V_17 ;
}
void F_189 ( struct V_16 * V_17 , bool V_284 )
{
struct V_183 * V_29 ;
int V_175 = F_297 ( V_17 ) ;
int V_20 ;
if ( ! F_296 ( V_17 ) )
return;
V_20 = F_298 () ;
if ( ! V_284 ) {
V_29 = V_17 -> V_29 ;
F_302 ( V_20 , V_29 , V_285 [ V_175 ] ) ;
} else {
V_29 = F_306 ( V_17 -> V_41 , F_19 ( V_17 ) ) ;
if ( ! F_307 ( V_29 ) ) {
V_29 = & V_17 -> V_41 -> V_190 ;
F_308 ( V_29 ) ;
}
F_194 ( V_20 , V_29 ) ;
F_309 ( V_29 , V_175 ) ;
V_17 -> V_29 = V_29 ;
}
F_300 () ;
}
struct V_16 * F_310 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
int V_101 ;
while ( ( V_17 = F_311 ( V_6 ) ) != NULL ) {
V_17 = F_305 ( V_6 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! ( V_17 -> V_33 & V_286 ) ) {
if ( V_17 -> V_33 & V_287 )
F_312 ( V_6 , V_17 ) ;
V_17 -> V_33 |= V_286 ;
F_313 ( V_6 , V_17 ) ;
}
if ( ! V_6 -> V_288 || V_6 -> V_288 == V_17 ) {
V_6 -> V_289 = F_314 ( V_17 ) ;
V_6 -> V_288 = NULL ;
}
if ( V_17 -> V_33 & V_290 )
break;
if ( V_6 -> V_291 && F_22 ( V_17 ) ) {
V_17 -> V_202 ++ ;
}
if ( ! V_6 -> V_292 )
break;
V_101 = V_6 -> V_292 ( V_6 , V_17 ) ;
if ( V_101 == V_293 ) {
break;
} else if ( V_101 == V_294 ) {
if ( V_6 -> V_291 && F_22 ( V_17 ) &&
! ( V_17 -> V_33 & V_290 ) ) {
-- V_17 -> V_202 ;
}
V_17 = NULL ;
break;
} else if ( V_101 == V_295 || V_101 == V_296 ) {
int V_251 = ( V_101 == V_296 ) ? - V_297 : - V_219 ;
V_17 -> V_33 |= V_34 ;
F_315 ( V_17 ) ;
F_316 ( V_17 , V_251 ) ;
} else {
F_18 ( V_253 L_17 , V_170 , V_101 ) ;
break;
}
}
return V_17 ;
}
void F_317 ( struct V_16 * V_17 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
F_185 ( F_59 ( & V_17 -> V_18 ) ) ;
F_185 ( F_203 ( V_17 ) ) ;
F_318 ( & V_17 -> V_18 ) ;
if ( F_319 ( V_17 ) ) {
V_6 -> V_70 [ F_320 ( V_17 ) ] ++ ;
F_321 ( V_17 ) ;
}
}
void F_315 ( struct V_16 * V_193 )
{
F_317 ( V_193 ) ;
if ( F_243 ( V_298 , & V_193 -> V_6 -> V_129 ) ) {
F_322 ( & V_193 -> V_180 ) ;
V_193 -> V_33 |= V_299 ;
F_323 ( V_193 -> V_6 -> V_179 , & V_193 -> V_180 ) ;
}
F_185 ( F_243 ( V_300 , & V_193 -> V_301 ) ) ;
F_324 ( V_193 ) ;
}
struct V_16 * F_325 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
V_17 = F_310 ( V_6 ) ;
if ( V_17 )
F_315 ( V_17 ) ;
return V_17 ;
}
bool F_326 ( struct V_16 * V_193 , int error , unsigned int V_302 )
{
int V_303 ;
F_327 ( V_193 -> V_6 , V_193 , V_302 ) ;
if ( ! V_193 -> V_30 )
return false ;
if ( ! F_328 ( V_193 ) )
V_193 -> V_216 = 0 ;
if ( error && ! F_328 ( V_193 ) &&
! ( V_193 -> V_33 & V_34 ) ) {
char * V_304 ;
switch ( error ) {
case - V_305 :
V_304 = L_18 ;
break;
case - V_297 :
V_304 = L_19 ;
break;
case - V_306 :
V_304 = L_20 ;
break;
case - V_307 :
V_304 = L_21 ;
break;
case - V_308 :
V_304 = L_22 ;
break;
case - V_309 :
V_304 = L_23 ;
break;
case - V_219 :
default:
V_304 = L_24 ;
break;
}
F_163 ( V_253 L_25 ,
V_170 , V_304 , V_193 -> V_41 ?
V_193 -> V_41 -> V_42 : L_2 ,
( unsigned long long ) F_19 ( V_193 ) ) ;
}
F_295 ( V_193 , V_302 ) ;
V_303 = 0 ;
while ( V_193 -> V_30 ) {
struct V_30 * V_30 = V_193 -> V_30 ;
unsigned V_310 = F_329 ( V_30 -> V_36 . V_37 , V_302 ) ;
if ( V_310 == V_30 -> V_36 . V_37 )
V_193 -> V_30 = V_30 -> V_197 ;
F_12 ( V_193 , V_30 , V_310 , error ) ;
V_303 += V_310 ;
V_302 -= V_310 ;
if ( ! V_302 )
break;
}
if ( ! V_193 -> V_30 ) {
V_193 -> V_176 = 0 ;
return false ;
}
F_69 ( V_193 -> V_33 & V_311 ) ;
V_193 -> V_176 -= V_303 ;
if ( ! F_328 ( V_193 ) )
V_193 -> V_21 += V_303 >> 9 ;
if ( V_193 -> V_33 & V_276 ) {
V_193 -> V_43 &= ~ V_196 ;
V_193 -> V_43 |= V_193 -> V_30 -> V_195 & V_196 ;
}
if ( F_22 ( V_193 ) < F_330 ( V_193 ) ) {
F_17 ( V_193 , L_26 ) ;
V_193 -> V_176 = F_330 ( V_193 ) ;
}
F_290 ( V_193 ) ;
return true ;
}
static bool F_331 ( struct V_16 * V_17 , int error ,
unsigned int V_302 ,
unsigned int V_312 )
{
if ( F_326 ( V_17 , error , V_302 ) )
return true ;
if ( F_13 ( F_332 ( V_17 ) ) &&
F_326 ( V_17 -> V_313 , error , V_312 ) )
return true ;
if ( F_333 ( V_17 -> V_6 ) )
F_334 ( V_17 -> V_41 ) ;
return false ;
}
void F_335 ( struct V_16 * V_193 )
{
struct V_11 * V_6 = V_193 -> V_6 ;
V_193 -> V_33 &= ~ V_290 ;
if ( V_6 -> V_314 )
V_6 -> V_314 ( V_6 , V_193 ) ;
}
void F_336 ( struct V_16 * V_193 , int error )
{
struct V_11 * V_6 = V_193 -> V_6 ;
if ( V_193 -> V_33 & V_299 )
F_337 ( & V_6 -> V_315 [ F_297 ( V_193 ) ] , V_193 ) ;
if ( V_193 -> V_33 & V_181 )
F_184 ( V_6 , V_193 ) ;
F_185 ( F_186 ( V_193 ) ) ;
if ( F_13 ( V_316 ) && ! F_328 ( V_193 ) )
F_338 ( V_193 -> V_6 -> V_8 ) ;
F_180 ( V_193 ) ;
if ( V_193 -> V_33 & V_290 )
F_335 ( V_193 ) ;
F_301 ( V_193 ) ;
if ( V_193 -> V_252 ) {
F_201 ( V_193 -> V_6 -> V_179 , & V_193 -> V_180 ) ;
V_193 -> V_252 ( V_193 , error ) ;
} else {
if ( F_332 ( V_193 ) )
F_198 ( V_193 -> V_313 -> V_6 , V_193 -> V_313 ) ;
F_198 ( V_6 , V_193 ) ;
}
}
static bool F_339 ( struct V_16 * V_17 , int error ,
unsigned int V_302 , unsigned int V_312 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
unsigned long V_60 ;
if ( F_331 ( V_17 , error , V_302 , V_312 ) )
return true ;
F_51 ( V_6 -> V_48 , V_60 ) ;
F_336 ( V_17 , error ) ;
F_52 ( V_6 -> V_48 , V_60 ) ;
return false ;
}
bool F_340 ( struct V_16 * V_17 , int error ,
unsigned int V_302 , unsigned int V_312 )
{
if ( F_331 ( V_17 , error , V_302 , V_312 ) )
return true ;
F_336 ( V_17 , error ) ;
return false ;
}
bool F_341 ( struct V_16 * V_17 , int error , unsigned int V_302 )
{
return F_339 ( V_17 , error , V_302 , 0 ) ;
}
void F_342 ( struct V_16 * V_17 , int error )
{
bool V_317 ;
unsigned int V_312 = 0 ;
if ( F_13 ( F_332 ( V_17 ) ) )
V_312 = F_22 ( V_17 -> V_313 ) ;
V_317 = F_339 ( V_17 , error , F_22 ( V_17 ) , V_312 ) ;
F_185 ( V_317 ) ;
}
bool F_343 ( struct V_16 * V_17 , int error )
{
return F_341 ( V_17 , error , F_330 ( V_17 ) ) ;
}
bool F_344 ( struct V_16 * V_17 , int error )
{
F_37 ( error >= 0 ) ;
return F_341 ( V_17 , error , F_294 ( V_17 ) ) ;
}
bool F_345 ( struct V_16 * V_17 , int error , unsigned int V_302 )
{
return F_340 ( V_17 , error , V_302 , 0 ) ;
}
void F_316 ( struct V_16 * V_17 , int error )
{
bool V_317 ;
unsigned int V_312 = 0 ;
if ( F_13 ( F_332 ( V_17 ) ) )
V_312 = F_22 ( V_17 -> V_313 ) ;
V_317 = F_340 ( V_17 , error , F_22 ( V_17 ) , V_312 ) ;
F_185 ( V_317 ) ;
}
bool F_346 ( struct V_16 * V_17 , int error )
{
return F_345 ( V_17 , error , F_330 ( V_17 ) ) ;
}
bool F_347 ( struct V_16 * V_17 , int error )
{
F_37 ( error >= 0 ) ;
return F_345 ( V_17 , error , F_294 ( V_17 ) ) ;
}
void F_228 ( struct V_11 * V_6 , struct V_16 * V_17 ,
struct V_30 * V_30 )
{
if ( F_281 ( V_30 ) )
V_17 -> V_202 = F_348 ( V_6 , V_30 ) ;
V_17 -> V_176 = V_30 -> V_36 . V_37 ;
V_17 -> V_30 = V_17 -> V_44 = V_30 ;
if ( V_30 -> V_232 )
V_17 -> V_41 = V_30 -> V_232 -> V_318 ;
}
void F_349 ( struct V_16 * V_17 )
{
struct V_319 V_320 ;
struct V_321 V_322 ;
F_350 (bvec, rq, iter)
F_351 ( V_322 . V_323 ) ;
}
int F_352 ( struct V_11 * V_6 )
{
if ( V_6 -> V_324 )
return V_6 -> V_324 ( V_6 ) ;
return 0 ;
}
void F_353 ( struct V_16 * V_17 )
{
struct V_30 * V_30 ;
while ( ( V_30 = V_17 -> V_30 ) != NULL ) {
V_17 -> V_30 = V_30 -> V_197 ;
F_354 ( V_30 ) ;
}
}
static void F_355 ( struct V_16 * V_325 , struct V_16 * V_326 )
{
V_325 -> V_20 = V_326 -> V_20 ;
V_325 -> V_21 = F_19 ( V_326 ) ;
V_325 -> V_176 = F_22 ( V_326 ) ;
V_325 -> V_202 = V_326 -> V_202 ;
V_325 -> V_198 = V_326 -> V_198 ;
V_325 -> V_327 = V_326 -> V_327 ;
}
int F_356 ( struct V_16 * V_17 , struct V_16 * V_328 ,
struct V_329 * V_330 , T_2 V_87 ,
int (* F_357)( struct V_30 * , struct V_30 * , void * ) ,
void * V_88 )
{
struct V_30 * V_30 , * V_331 ;
if ( ! V_330 )
V_330 = V_332 ;
F_358 (bio_src, rq_src) {
V_30 = F_359 ( V_331 , V_87 , V_330 ) ;
if ( ! V_30 )
goto V_333;
if ( F_357 && F_357 ( V_30 , V_331 , V_88 ) )
goto V_333;
if ( V_17 -> V_30 ) {
V_17 -> V_44 -> V_197 = V_30 ;
V_17 -> V_44 = V_30 ;
} else
V_17 -> V_30 = V_17 -> V_44 = V_30 ;
}
F_355 ( V_17 , V_328 ) ;
return 0 ;
V_333:
if ( V_30 )
F_354 ( V_30 ) ;
F_353 ( V_17 ) ;
return - V_98 ;
}
int F_104 ( struct V_45 * V_46 )
{
return F_360 ( V_50 , V_46 ) ;
}
int F_361 ( int V_20 , struct V_45 * V_46 )
{
return F_362 ( V_20 , V_50 , V_46 ) ;
}
int F_363 ( struct V_334 * V_335 ,
unsigned long V_336 )
{
return F_31 ( V_50 , V_335 , V_336 ) ;
}
int F_364 ( int V_20 , struct V_334 * V_335 ,
unsigned long V_336 )
{
return F_365 ( V_20 , V_50 , V_335 , V_336 ) ;
}
void F_366 ( struct V_205 * V_206 )
{
struct V_337 * V_338 = V_174 ;
if ( V_338 -> V_206 )
return;
F_8 ( & V_206 -> V_210 ) ;
F_8 ( & V_206 -> V_209 ) ;
F_8 ( & V_206 -> V_339 ) ;
V_338 -> V_206 = V_206 ;
}
static int F_367 ( void * V_340 , struct V_207 * V_341 , struct V_207 * V_239 )
{
struct V_16 * V_342 = F_24 ( V_341 , struct V_16 , V_18 ) ;
struct V_16 * V_343 = F_24 ( V_239 , struct V_16 , V_18 ) ;
return ! ( V_342 -> V_6 < V_343 -> V_6 ||
( V_342 -> V_6 == V_343 -> V_6 && F_19 ( V_342 ) < F_19 ( V_343 ) ) ) ;
}
static void F_368 ( struct V_11 * V_6 , unsigned int V_344 ,
bool V_345 )
__releases( V_6 -> V_48 )
{
F_369 ( V_6 , V_344 , ! V_345 ) ;
if ( V_345 )
F_35 ( V_6 ) ;
else
F_26 ( V_6 ) ;
F_370 ( V_6 -> V_48 ) ;
}
static void F_371 ( struct V_205 * V_206 , bool V_345 )
{
F_372 ( V_346 ) ;
while ( ! F_59 ( & V_206 -> V_339 ) ) {
F_373 ( & V_206 -> V_339 , & V_346 ) ;
while ( ! F_59 ( & V_346 ) ) {
struct V_347 * V_348 = F_374 ( & V_346 ,
struct V_347 ,
V_210 ) ;
F_375 ( & V_348 -> V_210 ) ;
V_348 -> V_349 ( V_348 , V_345 ) ;
}
}
}
struct V_347 * F_376 ( T_8 V_350 , void * V_88 ,
int V_351 )
{
struct V_205 * V_206 = V_174 -> V_206 ;
struct V_347 * V_348 ;
if ( ! V_206 )
return NULL ;
F_225 (cb, &plug->cb_list, list)
if ( V_348 -> V_349 == V_350 && V_348 -> V_88 == V_88 )
return V_348 ;
F_185 ( V_351 < sizeof( * V_348 ) ) ;
V_348 = F_377 ( V_351 , V_263 ) ;
if ( V_348 ) {
V_348 -> V_88 = V_88 ;
V_348 -> V_349 = V_350 ;
F_378 ( & V_348 -> V_210 , & V_206 -> V_339 ) ;
}
return V_348 ;
}
void F_247 ( struct V_205 * V_206 , bool V_345 )
{
struct V_11 * V_6 ;
unsigned long V_60 ;
struct V_16 * V_17 ;
F_372 ( V_210 ) ;
unsigned int V_344 ;
F_371 ( V_206 , V_345 ) ;
if ( ! F_59 ( & V_206 -> V_209 ) )
F_379 ( V_206 , V_345 ) ;
if ( F_59 ( & V_206 -> V_210 ) )
return;
F_373 ( & V_206 -> V_210 , & V_210 ) ;
F_380 ( NULL , & V_210 , F_367 ) ;
V_6 = NULL ;
V_344 = 0 ;
F_381 ( V_60 ) ;
while ( ! F_59 ( & V_210 ) ) {
V_17 = F_246 ( V_210 . V_352 ) ;
F_318 ( & V_17 -> V_18 ) ;
F_185 ( ! V_17 -> V_6 ) ;
if ( V_17 -> V_6 != V_6 ) {
if ( V_6 )
F_368 ( V_6 , V_344 , V_345 ) ;
V_6 = V_17 -> V_6 ;
V_344 = 0 ;
F_382 ( V_6 -> V_48 ) ;
}
if ( F_13 ( F_99 ( V_6 ) ) ) {
F_316 ( V_17 , - V_105 ) ;
continue;
}
if ( F_152 ( V_17 -> V_43 ) )
F_190 ( V_6 , V_17 , V_221 ) ;
else
F_190 ( V_6 , V_17 , V_353 ) ;
V_344 ++ ;
}
if ( V_6 )
F_368 ( V_6 , V_344 , V_345 ) ;
F_383 ( V_60 ) ;
}
void F_384 ( struct V_205 * V_206 )
{
if ( V_206 != V_174 -> V_206 )
return;
F_247 ( V_206 , false ) ;
V_174 -> V_206 = NULL ;
}
void F_385 ( struct V_11 * V_6 , struct V_354 * V_171 )
{
V_6 -> V_171 = V_171 ;
V_6 -> V_281 = V_283 ;
F_386 ( V_6 -> V_171 , - 1 ) ;
F_387 ( V_6 -> V_171 ) ;
}
int F_388 ( struct V_11 * V_6 )
{
int V_101 = 0 ;
if ( ! V_6 -> V_171 )
return V_101 ;
F_25 ( V_6 -> V_48 ) ;
if ( V_6 -> V_192 ) {
V_101 = - V_102 ;
F_197 ( V_6 -> V_171 ) ;
} else {
V_6 -> V_281 = V_355 ;
}
F_27 ( V_6 -> V_48 ) ;
return V_101 ;
}
void F_389 ( struct V_11 * V_6 , int V_251 )
{
if ( ! V_6 -> V_171 )
return;
F_25 ( V_6 -> V_48 ) ;
if ( ! V_251 ) {
V_6 -> V_281 = V_282 ;
} else {
V_6 -> V_281 = V_283 ;
F_197 ( V_6 -> V_171 ) ;
}
F_27 ( V_6 -> V_48 ) ;
}
void F_390 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_171 )
return;
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_281 = V_356 ;
F_27 ( V_6 -> V_48 ) ;
}
void F_391 ( struct V_11 * V_6 , int V_251 )
{
if ( ! V_6 -> V_171 )
return;
F_25 ( V_6 -> V_48 ) ;
if ( ! V_251 ) {
V_6 -> V_281 = V_283 ;
F_26 ( V_6 ) ;
F_197 ( V_6 -> V_171 ) ;
F_392 ( V_6 -> V_171 ) ;
} else {
V_6 -> V_281 = V_282 ;
}
F_27 ( V_6 -> V_48 ) ;
}
void F_393 ( struct V_11 * V_6 )
{
F_25 ( V_6 -> V_48 ) ;
V_6 -> V_281 = V_283 ;
F_197 ( V_6 -> V_171 ) ;
F_392 ( V_6 -> V_171 ) ;
F_27 ( V_6 -> V_48 ) ;
}
int T_6 F_394 ( void )
{
F_395 ( V_357 >= ( 1 << V_358 ) ) ;
F_395 ( V_358 + V_359 > 8 *
F_396 ( struct V_16 , V_43 ) ) ;
F_395 ( V_358 + V_359 > 8 *
F_396 ( struct V_30 , V_195 ) ) ;
V_50 = F_397 ( L_27 ,
V_360 | V_361 , 0 ) ;
if ( ! V_50 )
F_398 ( L_28 ) ;
V_89 = F_399 ( L_29 ,
sizeof( struct V_16 ) , 0 , V_362 , NULL ) ;
V_110 = F_399 ( L_30 ,
sizeof( struct V_11 ) , 0 , V_362 , NULL ) ;
#ifdef F_400
V_363 = F_401 ( L_5 , NULL ) ;
#endif
return 0 ;
}
