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
T_1 F_12 ( int V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_13 ( V_32 ) ; V_31 ++ ) {
if ( V_32 [ V_31 ] . V_30 == V_30 )
return ( V_33 T_1 ) V_31 ;
}
return V_34 ;
}
int F_14 ( T_1 V_35 )
{
int V_36 = ( V_33 int ) V_35 ;
if ( F_15 ( V_36 >= F_13 ( V_32 ) ) )
return - V_37 ;
return V_32 [ V_36 ] . V_30 ;
}
static void F_16 ( struct V_16 * V_38 , T_1 V_35 )
{
int V_36 = ( V_33 int ) V_35 ;
if ( F_15 ( V_36 >= F_13 ( V_32 ) ) )
return;
F_17 ( V_39 L_1 ,
V_40 , V_32 [ V_36 ] . V_41 , V_38 -> V_42 ?
V_38 -> V_42 -> V_43 : L_2 ,
( unsigned long long ) F_18 ( V_38 ) ) ;
}
static void F_19 ( struct V_16 * V_17 , struct V_44 * V_44 ,
unsigned int V_45 , T_1 error )
{
if ( error )
V_44 -> V_46 = error ;
if ( F_20 ( V_17 -> V_47 & V_48 ) )
F_21 ( V_44 , V_49 ) ;
F_22 ( V_44 , V_45 ) ;
if ( V_44 -> V_50 . V_51 == 0 && ! ( V_17 -> V_47 & V_52 ) )
F_23 ( V_44 ) ;
}
void F_24 ( struct V_16 * V_17 , char * V_53 )
{
F_25 ( V_54 L_3 , V_53 ,
V_17 -> V_42 ? V_17 -> V_42 -> V_43 : L_2 ,
( unsigned long long ) V_17 -> V_55 ) ;
F_25 ( V_54 L_4 ,
( unsigned long long ) F_18 ( V_17 ) ,
F_26 ( V_17 ) , F_27 ( V_17 ) ) ;
F_25 ( V_54 L_5 ,
V_17 -> V_44 , V_17 -> V_56 , F_28 ( V_17 ) ) ;
}
static void F_29 ( struct V_57 * V_58 )
{
struct V_11 * V_6 ;
V_6 = F_30 ( V_58 , struct V_11 , V_59 . V_58 ) ;
F_31 ( V_6 -> V_60 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 -> V_60 ) ;
}
void F_34 ( struct V_11 * V_6 , unsigned long V_61 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( F_36 ( ! F_37 ( V_6 ) ) )
F_38 ( V_63 , & V_6 -> V_59 ,
F_39 ( V_61 ) ) ;
}
void F_40 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
F_41 ( V_64 , V_6 ) ;
F_42 ( V_6 ) ;
}
void F_43 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_44 ( ! F_45 () ) ;
F_15 ( V_6 -> V_62 ) ;
F_41 ( V_64 , V_6 ) ;
F_32 ( V_6 ) ;
}
void F_46 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
F_47 ( & V_6 -> V_59 ) ;
F_48 ( V_64 , V_6 ) ;
}
void F_49 ( struct V_11 * V_6 )
{
F_50 ( & V_6 -> V_65 ) ;
if ( V_6 -> V_62 ) {
struct V_66 * V_67 ;
int V_31 ;
F_51 (q, hctx, i)
F_52 ( & V_67 -> V_68 ) ;
} else {
F_52 ( & V_6 -> V_59 ) ;
}
}
inline void F_53 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( F_20 ( F_37 ( V_6 ) ) )
return;
V_6 -> V_69 ++ ;
V_6 -> V_70 ( V_6 ) ;
V_6 -> V_69 -- ;
}
void F_32 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( F_20 ( F_54 ( V_6 ) ) )
return;
F_53 ( V_6 ) ;
}
void F_42 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( F_36 ( ! F_54 ( V_6 ) && ! F_37 ( V_6 ) ) )
F_55 ( V_63 , & V_6 -> V_59 , 0 ) ;
}
void F_56 ( struct V_11 * V_6 )
{
unsigned long V_71 ;
F_15 ( V_6 -> V_62 ) ;
F_57 ( V_6 -> V_60 , V_71 ) ;
F_32 ( V_6 ) ;
F_58 ( V_6 -> V_60 , V_71 ) ;
}
void F_59 ( struct V_11 * V_6 )
{
F_60 ( & V_6 -> V_72 ) ;
}
static void F_61 ( struct V_11 * V_6 , bool V_73 )
__releases( V_6 -> V_60 )
__acquires( V_6 -> V_60 )
{
int V_31 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
while ( true ) {
bool V_74 = false ;
if ( V_6 -> V_75 )
F_62 ( V_6 ) ;
F_63 ( V_6 ) ;
if ( ! F_64 ( & V_6 -> V_76 ) && V_6 -> V_70 )
F_32 ( V_6 ) ;
V_74 |= V_6 -> V_77 ;
V_74 |= V_6 -> V_69 ;
if ( V_73 ) {
struct V_78 * V_79 = F_65 ( V_6 , NULL ) ;
V_74 |= ! F_64 ( & V_6 -> V_76 ) ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_74 |= V_6 -> V_80 [ V_31 ] ;
V_74 |= V_6 -> V_81 [ V_31 ] ;
if ( V_79 )
V_74 |= ! F_64 ( & V_79 -> V_82 [ V_31 ] ) ;
}
}
if ( ! V_74 )
break;
F_33 ( V_6 -> V_60 ) ;
F_66 ( 10 ) ;
F_31 ( V_6 -> V_60 ) ;
}
if ( V_6 -> V_70 ) {
struct V_1 * V_2 ;
F_67 (rl, q)
for ( V_31 = 0 ; V_31 < F_13 ( V_2 -> V_83 ) ; V_31 ++ )
F_68 ( & V_2 -> V_83 [ V_31 ] ) ;
}
}
void F_69 ( struct V_11 * V_6 )
{
F_15 ( V_6 -> V_62 ) ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_84 ++ ;
F_48 ( V_85 , V_6 ) ;
F_33 ( V_6 -> V_60 ) ;
if ( F_70 ( V_6 ) ) {
F_31 ( V_6 -> V_60 ) ;
F_61 ( V_6 , false ) ;
F_33 ( V_6 -> V_60 ) ;
F_71 () ;
}
}
void F_72 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
if ( ! -- V_6 -> V_84 )
F_41 ( V_85 , V_6 ) ;
F_15 ( V_6 -> V_84 < 0 ) ;
F_33 ( V_6 -> V_60 ) ;
}
void F_73 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
F_48 ( V_86 , V_6 ) ;
F_33 ( V_6 -> V_60 ) ;
F_74 ( V_6 ) ;
if ( V_6 -> V_62 )
F_75 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_31 ( V_6 -> V_60 ) ;
F_67 (rl, q) {
if ( V_2 -> V_87 ) {
F_76 ( & V_2 -> V_83 [ V_88 ] ) ;
F_76 ( & V_2 -> V_83 [ V_89 ] ) ;
}
}
F_33 ( V_6 -> V_60 ) ;
}
}
void F_77 ( struct V_11 * V_6 )
{
T_2 * V_90 = V_6 -> V_60 ;
F_78 ( & V_6 -> V_91 ) ;
F_73 ( V_6 ) ;
F_31 ( V_90 ) ;
V_6 -> V_84 ++ ;
F_48 ( V_85 , V_6 ) ;
F_48 ( V_92 , V_6 ) ;
F_48 ( V_93 , V_6 ) ;
F_48 ( V_86 , V_6 ) ;
F_33 ( V_90 ) ;
F_79 ( & V_6 -> V_91 ) ;
F_80 ( V_6 ) ;
F_31 ( V_90 ) ;
if ( ! V_6 -> V_62 )
F_61 ( V_6 , true ) ;
F_48 ( V_94 , V_6 ) ;
F_33 ( V_90 ) ;
F_81 () ;
F_50 ( & V_6 -> V_8 -> V_95 ) ;
F_49 ( V_6 ) ;
if ( V_6 -> V_62 )
F_82 ( V_6 ) ;
F_83 ( & V_6 -> V_96 ) ;
F_31 ( V_90 ) ;
if ( V_6 -> V_60 != & V_6 -> V_97 )
V_6 -> V_60 = & V_6 -> V_97 ;
F_33 ( V_90 ) ;
F_59 ( V_6 ) ;
}
static void * F_84 ( T_3 V_98 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
return F_85 ( V_100 , V_98 , V_6 -> V_101 ) ;
}
static void F_86 ( void * V_102 , void * V_99 )
{
F_87 ( V_100 , V_102 ) ;
}
static void * F_88 ( T_3 V_98 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
struct V_16 * V_17 ;
V_17 = F_89 ( sizeof( struct V_16 ) + V_6 -> V_103 , V_98 ,
V_6 -> V_101 ) ;
if ( V_17 && V_6 -> V_104 && V_6 -> V_104 ( V_6 , V_17 , V_98 ) < 0 ) {
F_90 ( V_17 ) ;
V_17 = NULL ;
}
return V_17 ;
}
static void F_91 ( void * V_102 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
if ( V_6 -> V_105 )
V_6 -> V_105 ( V_6 , V_102 ) ;
F_90 ( V_102 ) ;
}
int F_92 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_3 V_98 )
{
if ( F_20 ( V_2 -> V_87 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_106 [ V_88 ] = V_2 -> V_106 [ V_89 ] = 0 ;
V_2 -> V_107 [ V_88 ] = V_2 -> V_107 [ V_89 ] = 0 ;
F_93 ( & V_2 -> V_83 [ V_88 ] ) ;
F_93 ( & V_2 -> V_83 [ V_89 ] ) ;
if ( V_6 -> V_103 ) {
V_2 -> V_87 = F_94 ( V_108 ,
F_88 , F_91 ,
V_6 , V_98 , V_6 -> V_101 ) ;
} else {
V_2 -> V_87 = F_94 ( V_108 ,
F_84 , F_86 ,
V_6 , V_98 , V_6 -> V_101 ) ;
}
if ( ! V_2 -> V_87 )
return - V_109 ;
if ( V_2 != & V_6 -> V_7 )
F_15 ( ! F_95 ( V_6 ) ) ;
return 0 ;
}
void F_96 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_97 ( V_2 -> V_87 ) ;
if ( V_2 != & V_6 -> V_7 )
F_59 ( V_6 ) ;
}
}
struct V_11 * F_98 ( T_3 V_98 )
{
return F_99 ( V_98 , V_110 ) ;
}
int F_100 ( struct V_11 * V_6 , bool V_111 )
{
while ( true ) {
int V_112 ;
if ( F_101 ( & V_6 -> V_96 ) )
return 0 ;
if ( V_111 )
return - V_113 ;
F_102 () ;
V_112 = F_103 ( V_6 -> V_114 ,
! F_104 ( & V_6 -> V_115 ) ||
F_105 ( V_6 ) ) ;
if ( F_105 ( V_6 ) )
return - V_116 ;
if ( V_112 )
return V_112 ;
}
}
void F_106 ( struct V_11 * V_6 )
{
F_107 ( & V_6 -> V_96 ) ;
}
static void F_108 ( struct V_117 * V_118 )
{
struct V_11 * V_6 =
F_30 ( V_118 , struct V_11 , V_96 ) ;
F_68 ( & V_6 -> V_114 ) ;
}
static void F_109 ( unsigned long V_99 )
{
struct V_11 * V_6 = (struct V_11 * ) V_99 ;
F_110 ( & V_6 -> V_119 ) ;
}
struct V_11 * F_99 ( T_3 V_98 , int V_120 )
{
struct V_11 * V_6 ;
V_6 = F_85 ( V_121 ,
V_98 | V_122 , V_120 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_123 = F_111 ( & V_124 , 0 , 0 , V_98 ) ;
if ( V_6 -> V_123 < 0 )
goto V_125;
V_6 -> V_126 = F_112 ( V_127 , 0 , V_128 ) ;
if ( ! V_6 -> V_126 )
goto V_129;
V_6 -> V_8 = F_113 ( V_98 , V_120 ) ;
if ( ! V_6 -> V_8 )
goto V_130;
V_6 -> V_131 = F_114 () ;
if ( ! V_6 -> V_131 )
goto V_132;
V_6 -> V_8 -> V_133 =
( V_134 * 1024 ) / V_135 ;
V_6 -> V_8 -> V_136 = V_137 ;
V_6 -> V_8 -> V_41 = L_6 ;
V_6 -> V_101 = V_120 ;
F_115 ( & V_6 -> V_8 -> V_95 ,
V_138 , ( unsigned long ) V_6 ) ;
F_115 ( & V_6 -> V_65 , F_109 , ( unsigned long ) V_6 ) ;
F_8 ( & V_6 -> V_76 ) ;
F_8 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_139 ) ;
#ifdef F_116
F_8 ( & V_6 -> V_140 ) ;
#endif
F_117 ( & V_6 -> V_59 , F_29 ) ;
F_118 ( & V_6 -> V_72 , & V_141 ) ;
F_119 ( & V_6 -> V_91 ) ;
F_120 ( & V_6 -> V_97 ) ;
V_6 -> V_60 = & V_6 -> V_97 ;
V_6 -> V_84 = 1 ;
F_121 ( V_85 , & V_6 -> V_142 ) ;
F_93 ( & V_6 -> V_114 ) ;
if ( F_122 ( & V_6 -> V_96 ,
F_108 ,
V_143 , V_144 ) )
goto V_145;
if ( F_123 ( V_6 ) )
goto V_146;
return V_6 ;
V_146:
F_83 ( & V_6 -> V_96 ) ;
V_145:
F_124 ( V_6 -> V_131 ) ;
V_132:
F_125 ( V_6 -> V_8 ) ;
V_130:
F_126 ( V_6 -> V_126 ) ;
V_129:
F_127 ( & V_124 , V_6 -> V_123 ) ;
V_125:
F_87 ( V_121 , V_6 ) ;
return NULL ;
}
struct V_11 * F_128 ( T_4 * V_147 , T_2 * V_90 )
{
return F_129 ( V_147 , V_90 , V_110 ) ;
}
struct V_11 *
F_129 ( T_4 * V_147 , T_2 * V_90 , int V_120 )
{
struct V_11 * V_6 ;
V_6 = F_99 ( V_144 , V_120 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_70 = V_147 ;
if ( V_90 )
V_6 -> V_60 = V_90 ;
if ( F_130 ( V_6 ) < 0 ) {
F_77 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
int F_130 ( struct V_11 * V_6 )
{
F_15 ( V_6 -> V_62 ) ;
V_6 -> V_79 = F_131 ( V_6 , V_110 , V_6 -> V_103 ) ;
if ( ! V_6 -> V_79 )
return - V_109 ;
if ( V_6 -> V_104 && V_6 -> V_104 ( V_6 , V_6 -> V_79 -> V_148 , V_144 ) )
goto V_149;
if ( F_92 ( & V_6 -> V_7 , V_6 , V_144 ) )
goto V_150;
F_132 ( & V_6 -> V_119 , V_151 ) ;
V_6 -> V_142 |= V_152 ;
F_133 ( V_6 , V_153 ) ;
V_6 -> V_154 = V_155 ;
F_78 ( & V_6 -> V_91 ) ;
if ( F_134 ( V_6 , NULL ) ) {
F_79 ( & V_6 -> V_91 ) ;
goto V_150;
}
F_79 ( & V_6 -> V_91 ) ;
return 0 ;
V_150:
if ( V_6 -> V_105 )
V_6 -> V_105 ( V_6 , V_6 -> V_79 -> V_148 ) ;
V_149:
F_135 ( V_6 -> V_79 ) ;
return - V_109 ;
}
bool F_95 ( struct V_11 * V_6 )
{
if ( F_36 ( ! F_105 ( V_6 ) ) ) {
F_136 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_137 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_47 & V_156 ) {
F_138 ( V_2 -> V_6 , V_17 ) ;
if ( V_17 -> V_157 . V_158 )
F_139 ( V_17 -> V_157 . V_158 -> V_159 ) ;
}
F_140 ( V_17 , V_2 -> V_87 ) ;
}
static inline int F_141 ( struct V_11 * V_6 , struct V_160 * V_159 )
{
if ( ! V_159 )
return 0 ;
return V_159 -> V_161 == V_6 -> V_162 ||
( V_159 -> V_161 > 0
&& F_142 ( V_28 , V_159 -> V_163 + V_164 ) ) ;
}
static void F_143 ( struct V_11 * V_6 , struct V_160 * V_159 )
{
if ( ! V_159 || F_141 ( V_6 , V_159 ) )
return;
V_159 -> V_161 = V_6 -> V_162 ;
V_159 -> V_163 = V_28 ;
}
static void F_144 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_106 [ V_3 ] < F_145 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_106 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_146 ( & V_2 -> V_83 [ V_3 ] ) )
F_76 ( & V_2 -> V_83 [ V_3 ] ) ;
F_147 ( V_2 , V_3 ) ;
}
}
static void F_148 ( struct V_1 * V_2 , bool V_3 ,
T_5 V_47 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
V_6 -> V_80 [ V_3 ] -- ;
V_2 -> V_106 [ V_3 ] -- ;
if ( V_47 & V_156 )
V_6 -> V_77 -- ;
F_144 ( V_2 , V_3 ) ;
if ( F_20 ( V_2 -> V_107 [ V_3 ^ 1 ] ) )
F_144 ( V_2 , V_3 ^ 1 ) ;
}
int F_149 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_165 , V_166 ;
F_15 ( V_6 -> V_62 ) ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_165 = F_150 ( V_6 ) ;
V_166 = F_145 ( V_6 ) ;
F_67 (rl, q) {
if ( V_2 -> V_106 [ V_88 ] >= V_165 )
F_4 ( V_2 , V_88 ) ;
else if ( V_2 -> V_106 [ V_88 ] < V_166 )
F_1 ( V_2 , V_88 ) ;
if ( V_2 -> V_106 [ V_89 ] >= V_165 )
F_4 ( V_2 , V_89 ) ;
else if ( V_2 -> V_106 [ V_89 ] < V_166 )
F_1 ( V_2 , V_89 ) ;
if ( V_2 -> V_106 [ V_88 ] >= V_6 -> V_13 ) {
F_151 ( V_2 , V_88 ) ;
} else {
F_147 ( V_2 , V_88 ) ;
F_76 ( & V_2 -> V_83 [ V_88 ] ) ;
}
if ( V_2 -> V_106 [ V_89 ] >= V_6 -> V_13 ) {
F_151 ( V_2 , V_89 ) ;
} else {
F_147 ( V_2 , V_89 ) ;
F_76 ( & V_2 -> V_83 [ V_89 ] ) ;
}
}
F_33 ( V_6 -> V_60 ) ;
return 0 ;
}
static struct V_16 * F_152 ( struct V_1 * V_2 , unsigned int V_167 ,
struct V_44 * V_44 , T_3 V_98 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 ;
struct V_168 * V_169 = V_6 -> V_75 -> type ;
struct V_160 * V_159 = F_153 ( V_44 ) ;
struct V_170 * V_158 = NULL ;
const bool V_171 = F_154 ( V_167 ) ;
int V_172 ;
T_5 V_47 = V_173 ;
F_35 ( V_6 -> V_60 ) ;
if ( F_20 ( F_105 ( V_6 ) ) )
return F_155 ( - V_116 ) ;
V_172 = F_156 ( V_6 , V_167 ) ;
if ( V_172 == V_174 )
goto V_175;
if ( V_2 -> V_106 [ V_171 ] + 1 >= F_150 ( V_6 ) ) {
if ( V_2 -> V_106 [ V_171 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_157 ( V_2 , V_171 ) ) {
F_143 ( V_6 , V_159 ) ;
F_151 ( V_2 , V_171 ) ;
} else {
if ( V_172 != V_176
&& ! F_141 ( V_6 , V_159 ) ) {
return F_155 ( - V_109 ) ;
}
}
}
F_4 ( V_2 , V_171 ) ;
}
if ( V_2 -> V_106 [ V_171 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_155 ( - V_109 ) ;
V_6 -> V_80 [ V_171 ] ++ ;
V_2 -> V_106 [ V_171 ] ++ ;
V_2 -> V_107 [ V_171 ] = 0 ;
if ( ! F_158 ( V_167 ) && ! F_159 ( V_6 ) ) {
V_47 |= V_156 ;
V_6 -> V_77 ++ ;
if ( V_169 -> V_177 && V_159 )
V_158 = F_160 ( V_159 , V_6 ) ;
}
if ( F_161 ( V_6 ) )
V_47 |= V_178 ;
F_33 ( V_6 -> V_60 ) ;
V_17 = F_162 ( V_2 -> V_87 , V_98 ) ;
if ( ! V_17 )
goto V_179;
F_7 ( V_6 , V_17 ) ;
F_163 ( V_17 , V_2 ) ;
V_17 -> V_55 = V_167 ;
V_17 -> V_47 = V_47 ;
if ( V_47 & V_156 ) {
if ( F_20 ( V_169 -> V_177 && ! V_158 ) ) {
if ( V_159 )
V_158 = F_164 ( V_159 , V_6 , V_98 ) ;
if ( ! V_158 )
goto V_180;
}
V_17 -> V_157 . V_158 = V_158 ;
if ( F_20 ( F_165 ( V_6 , V_17 , V_44 , V_98 ) ) )
goto V_180;
if ( V_158 )
F_166 ( V_158 -> V_159 ) ;
}
V_181:
if ( F_141 ( V_6 , V_159 ) )
V_159 -> V_161 -- ;
F_167 ( V_6 , V_44 , V_167 ) ;
return V_17 ;
V_180:
F_17 ( V_182 L_7 ,
V_40 , F_168 ( V_6 -> V_8 -> V_183 ) ) ;
V_17 -> V_47 &= ~ V_156 ;
V_17 -> V_157 . V_158 = NULL ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_77 -- ;
F_33 ( V_6 -> V_60 ) ;
goto V_181;
V_179:
F_31 ( V_6 -> V_60 ) ;
F_148 ( V_2 , V_171 , V_47 ) ;
V_175:
if ( F_20 ( V_2 -> V_106 [ V_171 ] == 0 ) )
V_2 -> V_107 [ V_171 ] = 1 ;
return F_155 ( - V_109 ) ;
}
static struct V_16 * F_169 ( struct V_11 * V_6 , unsigned int V_167 ,
struct V_44 * V_44 , T_3 V_98 )
{
const bool V_171 = F_154 ( V_167 ) ;
F_170 ( V_83 ) ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
V_2 = F_171 ( V_6 , V_44 ) ;
V_184:
V_17 = F_152 ( V_2 , V_167 , V_44 , V_98 ) ;
if ( ! F_172 ( V_17 ) )
return V_17 ;
if ( V_167 & V_185 ) {
F_173 ( V_2 ) ;
return F_155 ( - V_186 ) ;
}
if ( ! F_174 ( V_98 ) || F_20 ( F_105 ( V_6 ) ) ) {
F_173 ( V_2 ) ;
return V_17 ;
}
F_175 ( & V_2 -> V_83 [ V_171 ] , & V_83 ,
V_187 ) ;
F_176 ( V_6 , V_44 , V_167 ) ;
F_33 ( V_6 -> V_60 ) ;
F_177 () ;
F_143 ( V_6 , V_188 -> V_160 ) ;
F_31 ( V_6 -> V_60 ) ;
F_178 ( & V_2 -> V_83 [ V_171 ] , & V_83 ) ;
goto V_184;
}
static struct V_16 * F_179 ( struct V_11 * V_6 ,
unsigned int V_167 , T_3 V_98 )
{
struct V_16 * V_17 ;
F_15 ( V_6 -> V_62 ) ;
F_180 ( V_98 , V_6 -> V_101 ) ;
F_31 ( V_6 -> V_60 ) ;
V_17 = F_169 ( V_6 , V_167 , NULL , V_98 ) ;
if ( F_172 ( V_17 ) ) {
F_33 ( V_6 -> V_60 ) ;
return V_17 ;
}
V_17 -> V_189 = 0 ;
V_17 -> V_21 = ( V_22 ) - 1 ;
V_17 -> V_44 = V_17 -> V_56 = NULL ;
return V_17 ;
}
struct V_16 * F_181 ( struct V_11 * V_6 , unsigned int V_167 ,
T_3 V_98 )
{
struct V_16 * V_38 ;
if ( V_6 -> V_62 ) {
V_38 = F_182 ( V_6 , V_167 ,
( V_98 & V_190 ) ?
0 : V_191 ) ;
if ( ! F_172 ( V_38 ) && V_6 -> V_62 -> V_192 )
V_6 -> V_62 -> V_192 ( V_38 ) ;
} else {
V_38 = F_179 ( V_6 , V_167 , V_98 ) ;
if ( ! F_172 ( V_38 ) && V_6 -> V_192 )
V_6 -> V_192 ( V_38 ) ;
}
return V_38 ;
}
void F_183 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
F_184 ( V_17 ) ;
F_185 ( V_17 ) ;
F_186 ( V_6 , V_17 ) ;
F_187 ( V_6 -> V_193 , & V_17 -> V_194 ) ;
if ( V_17 -> V_47 & V_195 )
F_188 ( V_6 , V_17 ) ;
F_189 ( F_190 ( V_17 ) ) ;
F_191 ( V_6 , V_17 ) ;
}
static void F_192 ( struct V_11 * V_6 , struct V_16 * V_17 ,
int V_196 )
{
F_193 ( V_17 , true ) ;
F_194 ( V_6 , V_17 , V_196 ) ;
}
static void F_195 ( int V_20 , struct V_197 * V_29 ,
unsigned long V_198 )
{
int V_199 ;
if ( V_198 == V_29 -> V_200 )
return;
V_199 = F_196 ( V_29 ) ;
if ( V_199 ) {
F_197 ( V_20 , V_29 , V_201 ,
V_199 * ( V_198 - V_29 -> V_200 ) ) ;
F_197 ( V_20 , V_29 , V_202 , ( V_198 - V_29 -> V_200 ) ) ;
}
V_29 -> V_200 = V_198 ;
}
void F_198 ( int V_20 , struct V_197 * V_29 )
{
unsigned long V_198 = V_28 ;
if ( V_29 -> V_203 )
F_195 ( V_20 , & F_199 ( V_29 ) -> V_204 , V_198 ) ;
F_195 ( V_20 , V_29 , V_198 ) ;
}
static void F_200 ( struct V_16 * V_17 )
{
if ( V_17 -> V_6 -> V_183 && ! ( V_17 -> V_47 & V_205 ) && ! -- V_17 -> V_6 -> V_206 )
F_201 ( V_17 -> V_6 -> V_183 ) ;
}
static inline void F_200 ( struct V_16 * V_17 ) {}
void F_202 ( struct V_11 * V_6 , struct V_16 * V_38 )
{
T_5 V_47 = V_38 -> V_47 ;
if ( F_20 ( ! V_6 ) )
return;
if ( V_6 -> V_62 ) {
F_203 ( V_38 ) ;
return;
}
F_35 ( V_6 -> V_60 ) ;
F_200 ( V_38 ) ;
F_204 ( V_6 , V_38 ) ;
F_44 ( V_38 -> V_44 != NULL ) ;
F_205 ( V_6 -> V_193 , & V_38 -> V_194 ) ;
if ( V_47 & V_173 ) {
struct V_1 * V_2 = F_206 ( V_38 ) ;
bool V_3 = F_154 ( V_38 -> V_55 ) ;
F_189 ( ! F_64 ( & V_38 -> V_18 ) ) ;
F_189 ( F_207 ( V_38 ) ) ;
F_137 ( V_2 , V_38 ) ;
F_148 ( V_2 , V_3 , V_47 ) ;
F_173 ( V_2 ) ;
}
}
void F_208 ( struct V_16 * V_38 )
{
struct V_11 * V_6 = V_38 -> V_6 ;
if ( V_6 -> V_62 )
F_203 ( V_38 ) ;
else {
unsigned long V_71 ;
F_57 ( V_6 -> V_60 , V_71 ) ;
F_202 ( V_6 , V_38 ) ;
F_58 ( V_6 -> V_60 , V_71 ) ;
}
}
bool F_209 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
const int V_207 = V_44 -> V_208 & V_209 ;
if ( ! F_210 ( V_6 , V_38 , V_44 ) )
return false ;
F_211 ( V_6 , V_38 , V_44 ) ;
if ( ( V_38 -> V_55 & V_209 ) != V_207 )
F_212 ( V_38 ) ;
V_38 -> V_56 -> V_210 = V_44 ;
V_38 -> V_56 = V_44 ;
V_38 -> V_189 += V_44 -> V_50 . V_51 ;
V_38 -> V_211 = F_213 ( V_38 -> V_211 , F_214 ( V_44 ) ) ;
F_193 ( V_38 , false ) ;
return true ;
}
bool F_215 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
const int V_207 = V_44 -> V_208 & V_209 ;
if ( ! F_216 ( V_6 , V_38 , V_44 ) )
return false ;
F_217 ( V_6 , V_38 , V_44 ) ;
if ( ( V_38 -> V_55 & V_209 ) != V_207 )
F_212 ( V_38 ) ;
V_44 -> V_210 = V_38 -> V_44 ;
V_38 -> V_44 = V_44 ;
V_38 -> V_21 = V_44 -> V_50 . V_212 ;
V_38 -> V_189 += V_44 -> V_50 . V_51 ;
V_38 -> V_211 = F_213 ( V_38 -> V_211 , F_214 ( V_44 ) ) ;
F_193 ( V_38 , false ) ;
return true ;
}
bool F_218 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
unsigned short V_213 = F_219 ( V_38 ) ;
if ( V_213 >= F_220 ( V_6 ) )
goto V_214;
if ( F_26 ( V_38 ) + F_221 ( V_44 ) >
F_222 ( V_38 , F_18 ( V_38 ) ) )
goto V_214;
V_38 -> V_56 -> V_210 = V_44 ;
V_38 -> V_56 = V_44 ;
V_38 -> V_189 += V_44 -> V_50 . V_51 ;
V_38 -> V_211 = F_213 ( V_38 -> V_211 , F_214 ( V_44 ) ) ;
V_38 -> V_215 = V_213 + 1 ;
F_193 ( V_38 , false ) ;
return true ;
V_214:
F_223 ( V_6 , V_38 ) ;
return false ;
}
bool F_224 ( struct V_11 * V_6 , struct V_44 * V_44 ,
unsigned int * V_216 ,
struct V_16 * * V_217 )
{
struct V_218 * V_219 ;
struct V_16 * V_17 ;
struct V_220 * V_221 ;
V_219 = V_188 -> V_219 ;
if ( ! V_219 )
return false ;
* V_216 = 0 ;
if ( V_6 -> V_62 )
V_221 = & V_219 -> V_222 ;
else
V_221 = & V_219 -> V_223 ;
F_225 (rq, plug_list, queuelist) {
bool V_224 = false ;
if ( V_17 -> V_6 == V_6 ) {
( * V_216 ) ++ ;
if ( V_217 )
* V_217 = V_17 ;
}
if ( V_17 -> V_6 != V_6 || ! F_226 ( V_17 , V_44 ) )
continue;
switch ( F_227 ( V_17 , V_44 ) ) {
case V_225 :
V_224 = F_209 ( V_6 , V_17 , V_44 ) ;
break;
case V_226 :
V_224 = F_215 ( V_6 , V_17 , V_44 ) ;
break;
case V_227 :
V_224 = F_218 ( V_6 , V_17 , V_44 ) ;
break;
default:
break;
}
if ( V_224 )
return true ;
}
return false ;
}
unsigned int F_228 ( struct V_11 * V_6 )
{
struct V_218 * V_219 ;
struct V_16 * V_17 ;
struct V_220 * V_221 ;
unsigned int V_112 = 0 ;
V_219 = V_188 -> V_219 ;
if ( ! V_219 )
goto V_181;
if ( V_6 -> V_62 )
V_221 = & V_219 -> V_222 ;
else
V_221 = & V_219 -> V_223 ;
F_229 (rq, plug_list, queuelist) {
if ( V_17 -> V_6 == V_6 )
V_112 ++ ;
}
V_181:
return V_112 ;
}
void F_230 ( struct V_16 * V_38 , struct V_44 * V_44 )
{
struct V_160 * V_159 = F_153 ( V_44 ) ;
if ( V_44 -> V_208 & V_228 )
V_38 -> V_55 |= V_209 ;
V_38 -> V_21 = V_44 -> V_50 . V_212 ;
if ( F_231 ( F_214 ( V_44 ) ) )
V_38 -> V_211 = F_214 ( V_44 ) ;
else if ( V_159 )
V_38 -> V_211 = V_159 -> V_211 ;
else
V_38 -> V_211 = F_232 ( V_229 , 0 ) ;
V_38 -> V_230 = V_44 -> V_231 ;
F_233 ( V_38 -> V_6 , V_38 , V_44 ) ;
}
static T_6 V_153 ( struct V_11 * V_6 , struct V_44 * V_44 )
{
struct V_218 * V_219 ;
int V_196 = V_232 ;
struct V_16 * V_38 , * free ;
unsigned int V_216 = 0 ;
unsigned int V_233 ;
F_234 ( V_6 , & V_44 ) ;
F_235 ( V_6 , & V_44 ) ;
if ( ! F_236 ( V_44 ) )
return V_234 ;
if ( F_158 ( V_44 -> V_208 ) ) {
F_31 ( V_6 -> V_60 ) ;
V_196 = V_235 ;
goto V_236;
}
if ( ! F_237 ( V_6 ) ) {
if ( F_224 ( V_6 , V_44 , & V_216 , NULL ) )
return V_234 ;
} else
V_216 = F_228 ( V_6 ) ;
F_31 ( V_6 -> V_60 ) ;
switch ( F_238 ( V_6 , & V_38 , V_44 ) ) {
case V_225 :
if ( ! F_209 ( V_6 , V_38 , V_44 ) )
break;
F_239 ( V_6 , V_38 , V_44 ) ;
free = F_240 ( V_6 , V_38 ) ;
if ( free )
F_202 ( V_6 , free ) ;
else
F_241 ( V_6 , V_38 , V_225 ) ;
goto V_237;
case V_226 :
if ( ! F_215 ( V_6 , V_38 , V_44 ) )
break;
F_239 ( V_6 , V_38 , V_44 ) ;
free = F_242 ( V_6 , V_38 ) ;
if ( free )
F_202 ( V_6 , free ) ;
else
F_241 ( V_6 , V_38 , V_226 ) ;
goto V_237;
default:
break;
}
V_236:
V_233 = F_243 ( V_6 -> V_193 , V_44 , V_6 -> V_60 ) ;
V_38 = F_169 ( V_6 , V_44 -> V_208 , V_44 , V_238 ) ;
if ( F_172 ( V_38 ) ) {
F_244 ( V_6 -> V_193 , V_233 ) ;
if ( F_245 ( V_38 ) == - V_109 )
V_44 -> V_46 = V_239 ;
else
V_44 -> V_46 = V_34 ;
F_23 ( V_44 ) ;
goto V_237;
}
F_246 ( & V_38 -> V_194 , V_233 ) ;
F_230 ( V_38 , V_44 ) ;
if ( F_247 ( V_240 , & V_6 -> V_142 ) )
V_38 -> V_20 = F_248 () ;
V_219 = V_188 -> V_219 ;
if ( V_219 ) {
if ( ! V_216 || F_64 ( & V_219 -> V_223 ) )
F_249 ( V_6 ) ;
else {
struct V_16 * V_241 = F_250 ( V_219 -> V_223 . V_242 ) ;
if ( V_216 >= V_243 ||
F_28 ( V_241 ) >= V_244 ) {
F_251 ( V_219 , false ) ;
F_249 ( V_6 ) ;
}
}
F_252 ( & V_38 -> V_18 , & V_219 -> V_223 ) ;
F_193 ( V_38 , true ) ;
} else {
F_31 ( V_6 -> V_60 ) ;
F_192 ( V_6 , V_38 , V_196 ) ;
F_32 ( V_6 ) ;
V_237:
F_33 ( V_6 -> V_60 ) ;
}
return V_234 ;
}
static inline void F_253 ( struct V_44 * V_44 )
{
struct V_245 * V_246 = V_44 -> V_247 ;
if ( V_246 != V_246 -> V_248 &&
( F_221 ( V_44 ) || F_254 ( V_44 ) == V_249 ) ) {
struct V_197 * V_250 = V_246 -> V_251 ;
V_44 -> V_50 . V_212 += V_250 -> V_252 ;
V_44 -> V_247 = V_246 -> V_248 ;
F_255 ( F_256 ( V_44 -> V_247 ) , V_44 ,
V_246 -> V_253 ,
V_44 -> V_50 . V_212 - V_250 -> V_252 ) ;
}
}
static void F_257 ( struct V_44 * V_44 )
{
char V_254 [ V_255 ] ;
F_25 ( V_54 L_8 ) ;
F_25 ( V_54 L_9 ,
F_258 ( V_44 -> V_247 , V_254 ) ,
V_44 -> V_208 ,
( unsigned long long ) F_259 ( V_44 ) ,
( long long ) ( F_260 ( V_44 -> V_247 -> V_256 ) >> 9 ) ) ;
}
static int T_7 F_261 ( char * V_257 )
{
return F_262 ( & V_258 , V_257 ) ;
}
static bool F_263 ( struct V_197 * V_29 , unsigned int V_259 )
{
return V_29 -> V_260 && F_264 ( & V_258 , V_259 ) ;
}
static int T_7 F_265 ( void )
{
struct V_261 * V_262 = F_266 ( L_10 ,
NULL , & V_258 ) ;
return F_267 ( V_262 ) ;
}
static inline bool F_263 ( struct V_197 * V_29 ,
unsigned int V_259 )
{
return false ;
}
static inline int F_268 ( struct V_44 * V_44 , unsigned int V_263 )
{
V_22 V_264 ;
if ( ! V_263 )
return 0 ;
V_264 = F_260 ( V_44 -> V_247 -> V_256 ) >> 9 ;
if ( V_264 ) {
V_22 V_265 = V_44 -> V_50 . V_212 ;
if ( V_264 < V_263 || V_264 - V_263 < V_265 ) {
F_257 ( V_44 ) ;
return 1 ;
}
}
return 0 ;
}
static T_8 bool
F_269 ( struct V_44 * V_44 )
{
struct V_11 * V_6 ;
int V_263 = F_221 ( V_44 ) ;
T_1 V_35 = V_34 ;
char V_254 [ V_255 ] ;
struct V_197 * V_29 ;
F_270 () ;
if ( F_268 ( V_44 , V_263 ) )
goto V_266;
V_6 = F_256 ( V_44 -> V_247 ) ;
if ( F_20 ( ! V_6 ) ) {
F_25 ( V_39
L_11
L_12 ,
F_258 ( V_44 -> V_247 , V_254 ) ,
( long long ) V_44 -> V_50 . V_212 ) ;
goto V_266;
}
if ( ( V_44 -> V_208 & V_185 ) && ! F_271 ( V_6 ) )
goto V_267;
V_29 = V_44 -> V_247 -> V_251 ;
if ( F_263 ( V_29 , V_44 -> V_50 . V_51 ) ||
F_263 ( & F_199 ( V_29 ) -> V_204 ,
V_44 -> V_50 . V_51 ) )
goto V_266;
F_253 ( V_44 ) ;
if ( F_268 ( V_44 , V_263 ) )
goto V_266;
if ( F_158 ( V_44 -> V_208 ) &&
! F_247 ( V_268 , & V_6 -> V_142 ) ) {
V_44 -> V_208 &= ~ ( V_269 | V_270 ) ;
if ( ! V_263 ) {
V_35 = V_271 ;
goto V_266;
}
}
switch ( F_254 ( V_44 ) ) {
case V_272 :
if ( ! F_272 ( V_6 ) )
goto V_267;
break;
case V_273 :
if ( ! F_273 ( V_6 ) )
goto V_267;
break;
case V_274 :
if ( ! F_274 ( V_44 -> V_247 ) )
goto V_267;
break;
case V_275 :
case V_249 :
if ( ! F_275 ( V_44 -> V_247 ) )
goto V_267;
break;
case V_276 :
if ( ! F_276 ( V_44 -> V_247 ) )
goto V_267;
break;
default:
break;
}
F_180 ( V_277 , V_6 -> V_101 ) ;
if ( ! F_277 ( V_6 , V_44 ) )
return false ;
if ( ! F_278 ( V_44 , V_278 ) ) {
F_279 ( V_6 , V_44 ) ;
F_21 ( V_44 , V_278 ) ;
}
return true ;
V_267:
V_35 = V_279 ;
V_266:
V_44 -> V_46 = V_35 ;
F_23 ( V_44 ) ;
return false ;
}
T_6 F_280 ( struct V_44 * V_44 )
{
struct V_280 V_281 [ 2 ] ;
T_6 V_112 = V_234 ;
if ( ! F_269 ( V_44 ) )
goto V_181;
if ( V_188 -> V_280 ) {
F_281 ( & V_188 -> V_280 [ 0 ] , V_44 ) ;
goto V_181;
}
F_189 ( V_44 -> V_210 ) ;
F_282 ( & V_281 [ 0 ] ) ;
V_188 -> V_280 = V_281 ;
do {
struct V_11 * V_6 = F_256 ( V_44 -> V_247 ) ;
if ( F_36 ( F_100 ( V_6 , V_44 -> V_208 & V_185 ) == 0 ) ) {
struct V_280 V_282 , V_283 ;
V_281 [ 1 ] = V_281 [ 0 ] ;
F_282 ( & V_281 [ 0 ] ) ;
V_112 = V_6 -> V_284 ( V_6 , V_44 ) ;
F_106 ( V_6 ) ;
F_282 ( & V_282 ) ;
F_282 ( & V_283 ) ;
while ( ( V_44 = F_283 ( & V_281 [ 0 ] ) ) != NULL )
if ( V_6 == F_256 ( V_44 -> V_247 ) )
F_281 ( & V_283 , V_44 ) ;
else
F_281 ( & V_282 , V_44 ) ;
F_284 ( & V_281 [ 0 ] , & V_282 ) ;
F_284 ( & V_281 [ 0 ] , & V_283 ) ;
F_284 ( & V_281 [ 0 ] , & V_281 [ 1 ] ) ;
} else {
if ( F_20 ( ! F_105 ( V_6 ) &&
( V_44 -> V_208 & V_185 ) ) )
F_285 ( V_44 ) ;
else
F_286 ( V_44 ) ;
}
V_44 = F_283 ( & V_281 [ 0 ] ) ;
} while ( V_44 );
V_188 -> V_280 = NULL ;
V_181:
return V_112 ;
}
T_6 F_287 ( struct V_44 * V_44 )
{
if ( F_288 ( V_44 ) ) {
unsigned int V_106 ;
if ( F_20 ( F_254 ( V_44 ) == V_274 ) )
V_106 = F_289 ( V_44 -> V_247 ) >> 9 ;
else
V_106 = F_221 ( V_44 ) ;
if ( F_290 ( F_254 ( V_44 ) ) ) {
F_291 ( V_285 , V_106 ) ;
} else {
F_292 ( V_44 -> V_50 . V_51 ) ;
F_291 ( V_286 , V_106 ) ;
}
if ( F_20 ( V_287 ) ) {
char V_254 [ V_255 ] ;
F_25 ( V_288 L_13 ,
V_188 -> V_289 , F_293 ( V_188 ) ,
F_290 ( F_254 ( V_44 ) ) ? L_14 : L_15 ,
( unsigned long long ) V_44 -> V_50 . V_212 ,
F_258 ( V_44 -> V_247 , V_254 ) ,
V_106 ) ;
}
}
return F_280 ( V_44 ) ;
}
static int F_294 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( F_26 ( V_17 ) > F_295 ( V_6 , F_296 ( V_17 ) ) ) {
F_25 ( V_39 L_16 , V_40 ) ;
return - V_37 ;
}
F_297 ( V_17 ) ;
if ( V_17 -> V_215 > F_298 ( V_6 ) ) {
F_25 ( V_39 L_17 , V_40 ) ;
return - V_37 ;
}
return 0 ;
}
T_1 F_299 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
unsigned long V_71 ;
int V_196 = V_290 ;
if ( F_294 ( V_6 , V_17 ) )
return V_34 ;
if ( V_17 -> V_42 &&
F_263 ( & V_17 -> V_42 -> V_204 , F_28 ( V_17 ) ) )
return V_34 ;
if ( V_6 -> V_62 ) {
if ( F_161 ( V_6 ) )
F_193 ( V_17 , true ) ;
F_300 ( V_17 , false , true , false , false ) ;
return V_271 ;
}
F_57 ( V_6 -> V_60 , V_71 ) ;
if ( F_20 ( F_105 ( V_6 ) ) ) {
F_58 ( V_6 -> V_60 , V_71 ) ;
return V_34 ;
}
F_189 ( F_190 ( V_17 ) ) ;
if ( F_158 ( V_17 -> V_55 ) )
V_196 = V_235 ;
F_192 ( V_6 , V_17 , V_196 ) ;
if ( V_196 == V_235 )
F_32 ( V_6 ) ;
F_58 ( V_6 -> V_60 , V_71 ) ;
return V_271 ;
}
unsigned int F_301 ( const struct V_16 * V_17 )
{
unsigned int V_207 = V_17 -> V_55 & V_209 ;
unsigned int V_259 = 0 ;
struct V_44 * V_44 ;
if ( ! ( V_17 -> V_47 & V_291 ) )
return F_28 ( V_17 ) ;
for ( V_44 = V_17 -> V_44 ; V_44 ; V_44 = V_44 -> V_210 ) {
if ( ( V_44 -> V_208 & V_207 ) != V_207 )
break;
V_259 += V_44 -> V_50 . V_51 ;
}
F_189 ( F_28 ( V_17 ) && ! V_259 ) ;
return V_259 ;
}
void F_302 ( struct V_16 * V_38 , unsigned int V_259 )
{
if ( F_303 ( V_38 ) ) {
const int V_292 = F_304 ( V_38 ) ;
struct V_197 * V_29 ;
int V_20 ;
V_20 = F_305 () ;
V_29 = V_38 -> V_29 ;
F_306 ( V_20 , V_29 , V_293 [ V_292 ] , V_259 >> 9 ) ;
F_307 () ;
}
}
void F_308 ( struct V_16 * V_38 )
{
if ( F_303 ( V_38 ) && ! ( V_38 -> V_47 & V_52 ) ) {
unsigned long V_294 = V_28 - V_38 -> V_27 ;
const int V_292 = F_304 ( V_38 ) ;
struct V_197 * V_29 ;
int V_20 ;
V_20 = F_305 () ;
V_29 = V_38 -> V_29 ;
F_309 ( V_20 , V_29 , V_295 [ V_292 ] ) ;
F_306 ( V_20 , V_29 , V_296 [ V_292 ] , V_294 ) ;
F_198 ( V_20 , V_29 ) ;
F_310 ( V_29 , V_292 ) ;
F_311 ( V_29 ) ;
F_307 () ;
}
}
static struct V_16 * F_312 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( V_6 -> V_183 && ( V_6 -> V_297 == V_298 ||
( V_6 -> V_297 != V_299 && ! ( V_17 -> V_47 & V_205 ) ) ) )
return NULL ;
else
return V_17 ;
}
static inline struct V_16 * F_312 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
return V_17 ;
}
void F_193 ( struct V_16 * V_17 , bool V_300 )
{
struct V_197 * V_29 ;
int V_292 = F_304 ( V_17 ) ;
int V_20 ;
if ( ! F_303 ( V_17 ) )
return;
V_20 = F_305 () ;
if ( ! V_300 ) {
V_29 = V_17 -> V_29 ;
F_309 ( V_20 , V_29 , V_301 [ V_292 ] ) ;
} else {
V_29 = F_313 ( V_17 -> V_42 , F_18 ( V_17 ) ) ;
if ( ! F_314 ( V_29 ) ) {
V_29 = & V_17 -> V_42 -> V_204 ;
F_315 ( V_29 ) ;
}
F_198 ( V_20 , V_29 ) ;
F_316 ( V_29 , V_292 ) ;
V_17 -> V_29 = V_29 ;
}
F_307 () ;
}
struct V_16 * F_317 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
int V_112 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
while ( ( V_17 = F_318 ( V_6 ) ) != NULL ) {
V_17 = F_312 ( V_6 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! ( V_17 -> V_47 & V_302 ) ) {
if ( V_17 -> V_47 & V_303 )
F_319 ( V_6 , V_17 ) ;
V_17 -> V_47 |= V_302 ;
F_320 ( V_6 , V_17 ) ;
}
if ( ! V_6 -> V_304 || V_6 -> V_304 == V_17 ) {
V_6 -> V_305 = F_321 ( V_17 ) ;
V_6 -> V_304 = NULL ;
}
if ( V_17 -> V_47 & V_306 )
break;
if ( V_6 -> V_307 && F_28 ( V_17 ) ) {
V_17 -> V_215 ++ ;
}
if ( ! V_6 -> V_308 )
break;
V_112 = V_6 -> V_308 ( V_6 , V_17 ) ;
if ( V_112 == V_309 ) {
break;
} else if ( V_112 == V_310 ) {
if ( V_6 -> V_307 && F_28 ( V_17 ) &&
! ( V_17 -> V_47 & V_306 ) ) {
-- V_17 -> V_215 ;
}
V_17 = NULL ;
break;
} else if ( V_112 == V_311 || V_112 == V_312 ) {
V_17 -> V_47 |= V_48 ;
F_322 ( V_17 ) ;
F_323 ( V_17 , V_112 == V_312 ?
V_313 : V_34 ) ;
} else {
F_25 ( V_39 L_18 , V_40 , V_112 ) ;
break;
}
}
return V_17 ;
}
void F_324 ( struct V_16 * V_17 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
F_189 ( F_64 ( & V_17 -> V_18 ) ) ;
F_189 ( F_207 ( V_17 ) ) ;
F_325 ( & V_17 -> V_18 ) ;
if ( F_326 ( V_17 ) ) {
V_6 -> V_81 [ F_327 ( V_17 ) ] ++ ;
F_328 ( V_17 ) ;
}
}
void F_322 ( struct V_16 * V_38 )
{
F_35 ( V_38 -> V_6 -> V_60 ) ;
F_15 ( V_38 -> V_6 -> V_62 ) ;
F_324 ( V_38 ) ;
if ( F_247 ( V_314 , & V_38 -> V_6 -> V_142 ) ) {
F_329 ( & V_38 -> V_194 , F_26 ( V_38 ) ) ;
V_38 -> V_47 |= V_315 ;
F_330 ( V_38 -> V_6 -> V_193 , & V_38 -> V_194 ) ;
}
F_189 ( F_247 ( V_316 , & V_38 -> V_317 ) ) ;
F_331 ( V_38 ) ;
}
struct V_16 * F_332 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
V_17 = F_317 ( V_6 ) ;
if ( V_17 )
F_322 ( V_17 ) ;
return V_17 ;
}
bool F_333 ( struct V_16 * V_38 , T_1 error ,
unsigned int V_318 )
{
int V_319 ;
F_334 ( V_38 , F_14 ( error ) , V_318 ) ;
if ( ! V_38 -> V_44 )
return false ;
if ( F_20 ( error && ! F_335 ( V_38 ) &&
! ( V_38 -> V_47 & V_48 ) ) )
F_16 ( V_38 , error ) ;
F_302 ( V_38 , V_318 ) ;
V_319 = 0 ;
while ( V_38 -> V_44 ) {
struct V_44 * V_44 = V_38 -> V_44 ;
unsigned V_320 = F_336 ( V_44 -> V_50 . V_51 , V_318 ) ;
if ( V_320 == V_44 -> V_50 . V_51 )
V_38 -> V_44 = V_44 -> V_210 ;
F_337 ( V_44 , V_278 ) ;
F_19 ( V_38 , V_44 , V_320 , error ) ;
V_319 += V_320 ;
V_318 -= V_320 ;
if ( ! V_318 )
break;
}
if ( ! V_38 -> V_44 ) {
V_38 -> V_189 = 0 ;
return false ;
}
V_38 -> V_189 -= V_319 ;
if ( ! F_335 ( V_38 ) )
V_38 -> V_21 += V_319 >> 9 ;
if ( V_38 -> V_47 & V_291 ) {
V_38 -> V_55 &= ~ V_209 ;
V_38 -> V_55 |= V_38 -> V_44 -> V_208 & V_209 ;
}
if ( ! ( V_38 -> V_47 & V_321 ) ) {
if ( F_28 ( V_38 ) < F_338 ( V_38 ) ) {
F_24 ( V_38 , L_19 ) ;
V_38 -> V_189 = F_338 ( V_38 ) ;
}
F_297 ( V_38 ) ;
}
return true ;
}
static bool F_339 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_318 ,
unsigned int V_322 )
{
if ( F_333 ( V_17 , error , V_318 ) )
return true ;
if ( F_20 ( F_340 ( V_17 ) ) &&
F_333 ( V_17 -> V_323 , error , V_322 ) )
return true ;
if ( F_341 ( V_17 -> V_6 ) )
F_342 ( V_17 -> V_42 ) ;
return false ;
}
void F_343 ( struct V_16 * V_38 )
{
struct V_11 * V_6 = V_38 -> V_6 ;
V_38 -> V_47 &= ~ V_306 ;
if ( V_6 -> V_324 )
V_6 -> V_324 ( V_6 , V_38 ) ;
}
void F_344 ( struct V_16 * V_38 , T_1 error )
{
struct V_11 * V_6 = V_38 -> V_6 ;
F_35 ( V_38 -> V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( V_38 -> V_47 & V_315 )
F_345 ( V_38 ) ;
if ( V_38 -> V_47 & V_195 )
F_188 ( V_6 , V_38 ) ;
F_189 ( F_190 ( V_38 ) ) ;
if ( F_20 ( V_325 ) && ! F_335 ( V_38 ) )
F_346 ( V_38 -> V_6 -> V_8 ) ;
F_184 ( V_38 ) ;
if ( V_38 -> V_47 & V_306 )
F_343 ( V_38 ) ;
F_308 ( V_38 ) ;
if ( V_38 -> V_266 ) {
F_205 ( V_38 -> V_6 -> V_193 , & V_38 -> V_194 ) ;
V_38 -> V_266 ( V_38 , error ) ;
} else {
if ( F_340 ( V_38 ) )
F_202 ( V_38 -> V_323 -> V_6 , V_38 -> V_323 ) ;
F_202 ( V_6 , V_38 ) ;
}
}
static bool F_347 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_318 , unsigned int V_322 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
unsigned long V_71 ;
F_15 ( V_6 -> V_62 ) ;
if ( F_339 ( V_17 , error , V_318 , V_322 ) )
return true ;
F_57 ( V_6 -> V_60 , V_71 ) ;
F_344 ( V_17 , error ) ;
F_58 ( V_6 -> V_60 , V_71 ) ;
return false ;
}
static bool F_348 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_318 , unsigned int V_322 )
{
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
if ( F_339 ( V_17 , error , V_318 , V_322 ) )
return true ;
F_344 ( V_17 , error ) ;
return false ;
}
bool F_349 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_318 )
{
F_15 ( V_17 -> V_6 -> V_62 ) ;
return F_347 ( V_17 , error , V_318 , 0 ) ;
}
void F_350 ( struct V_16 * V_17 , T_1 error )
{
bool V_326 ;
unsigned int V_322 = 0 ;
if ( F_20 ( F_340 ( V_17 ) ) )
V_322 = F_28 ( V_17 -> V_323 ) ;
V_326 = F_347 ( V_17 , error , F_28 ( V_17 ) , V_322 ) ;
F_189 ( V_326 ) ;
}
bool F_351 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_318 )
{
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
return F_348 ( V_17 , error , V_318 , 0 ) ;
}
void F_323 ( struct V_16 * V_17 , T_1 error )
{
bool V_326 ;
unsigned int V_322 = 0 ;
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
if ( F_20 ( F_340 ( V_17 ) ) )
V_322 = F_28 ( V_17 -> V_323 ) ;
V_326 = F_348 ( V_17 , error , F_28 ( V_17 ) , V_322 ) ;
F_189 ( V_326 ) ;
}
bool F_352 ( struct V_16 * V_17 , T_1 error )
{
return F_351 ( V_17 , error , F_338 ( V_17 ) ) ;
}
void F_233 ( struct V_11 * V_6 , struct V_16 * V_17 ,
struct V_44 * V_44 )
{
if ( F_288 ( V_44 ) )
V_17 -> V_215 = F_353 ( V_6 , V_44 ) ;
V_17 -> V_189 = V_44 -> V_50 . V_51 ;
V_17 -> V_44 = V_17 -> V_56 = V_44 ;
if ( V_44 -> V_247 )
V_17 -> V_42 = V_44 -> V_247 -> V_327 ;
}
void F_354 ( struct V_16 * V_17 )
{
struct V_328 V_329 ;
struct V_330 V_331 ;
F_355 (bvec, rq, iter)
F_356 ( V_331 . V_332 ) ;
}
int F_357 ( struct V_11 * V_6 )
{
if ( V_6 -> V_333 )
return V_6 -> V_333 ( V_6 ) ;
return 0 ;
}
void F_358 ( struct V_16 * V_17 )
{
struct V_44 * V_44 ;
while ( ( V_44 = V_17 -> V_44 ) != NULL ) {
V_17 -> V_44 = V_44 -> V_210 ;
F_359 ( V_44 ) ;
}
}
static void F_360 ( struct V_16 * V_334 , struct V_16 * V_335 )
{
V_334 -> V_20 = V_335 -> V_20 ;
V_334 -> V_21 = F_18 ( V_335 ) ;
V_334 -> V_189 = F_28 ( V_335 ) ;
V_334 -> V_215 = V_335 -> V_215 ;
V_334 -> V_211 = V_335 -> V_211 ;
V_334 -> V_336 = V_335 -> V_336 ;
}
int F_361 ( struct V_16 * V_17 , struct V_16 * V_337 ,
struct V_338 * V_339 , T_3 V_98 ,
int (* F_362)( struct V_44 * , struct V_44 * , void * ) ,
void * V_99 )
{
struct V_44 * V_44 , * V_340 ;
if ( ! V_339 )
V_339 = V_341 ;
F_363 (bio_src, rq_src) {
V_44 = F_364 ( V_340 , V_98 , V_339 ) ;
if ( ! V_44 )
goto V_342;
if ( F_362 && F_362 ( V_44 , V_340 , V_99 ) )
goto V_342;
if ( V_17 -> V_44 ) {
V_17 -> V_56 -> V_210 = V_44 ;
V_17 -> V_56 = V_44 ;
} else
V_17 -> V_44 = V_17 -> V_56 = V_44 ;
}
F_360 ( V_17 , V_337 ) ;
return 0 ;
V_342:
if ( V_44 )
F_359 ( V_44 ) ;
F_358 ( V_17 ) ;
return - V_109 ;
}
int F_110 ( struct V_57 * V_58 )
{
return F_365 ( V_63 , V_58 ) ;
}
int F_366 ( int V_20 , struct V_57 * V_58 )
{
return F_367 ( V_20 , V_63 , V_58 ) ;
}
int F_368 ( int V_20 , struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_369 ( V_20 , V_63 , V_344 , V_345 ) ;
}
int F_370 ( struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_38 ( V_63 , V_344 , V_345 ) ;
}
int F_371 ( int V_20 , struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_372 ( V_20 , V_63 , V_344 , V_345 ) ;
}
void F_373 ( struct V_218 * V_219 )
{
struct V_346 * V_347 = V_188 ;
if ( V_347 -> V_219 )
return;
F_8 ( & V_219 -> V_223 ) ;
F_8 ( & V_219 -> V_222 ) ;
F_8 ( & V_219 -> V_348 ) ;
V_347 -> V_219 = V_219 ;
}
static int F_374 ( void * V_349 , struct V_220 * V_350 , struct V_220 * V_254 )
{
struct V_16 * V_351 = F_30 ( V_350 , struct V_16 , V_18 ) ;
struct V_16 * V_352 = F_30 ( V_254 , struct V_16 , V_18 ) ;
return ! ( V_351 -> V_6 < V_352 -> V_6 ||
( V_351 -> V_6 == V_352 -> V_6 && F_18 ( V_351 ) < F_18 ( V_352 ) ) ) ;
}
static void F_375 ( struct V_11 * V_6 , unsigned int V_353 ,
bool V_354 )
__releases( V_6 -> V_60 )
{
F_35 ( V_6 -> V_60 ) ;
F_376 ( V_6 , V_353 , ! V_354 ) ;
if ( V_354 )
F_42 ( V_6 ) ;
else
F_32 ( V_6 ) ;
F_377 ( V_6 -> V_60 ) ;
}
static void F_378 ( struct V_218 * V_219 , bool V_354 )
{
F_379 ( V_355 ) ;
while ( ! F_64 ( & V_219 -> V_348 ) ) {
F_380 ( & V_219 -> V_348 , & V_355 ) ;
while ( ! F_64 ( & V_355 ) ) {
struct V_356 * V_357 = F_381 ( & V_355 ,
struct V_356 ,
V_223 ) ;
F_382 ( & V_357 -> V_223 ) ;
V_357 -> V_358 ( V_357 , V_354 ) ;
}
}
}
struct V_356 * F_383 ( T_9 V_359 , void * V_99 ,
int V_360 )
{
struct V_218 * V_219 = V_188 -> V_219 ;
struct V_356 * V_357 ;
if ( ! V_219 )
return NULL ;
F_229 (cb, &plug->cb_list, list)
if ( V_357 -> V_358 == V_359 && V_357 -> V_99 == V_99 )
return V_357 ;
F_189 ( V_360 < sizeof( * V_357 ) ) ;
V_357 = F_384 ( V_360 , V_277 ) ;
if ( V_357 ) {
V_357 -> V_99 = V_99 ;
V_357 -> V_358 = V_359 ;
F_385 ( & V_357 -> V_223 , & V_219 -> V_348 ) ;
}
return V_357 ;
}
void F_251 ( struct V_218 * V_219 , bool V_354 )
{
struct V_11 * V_6 ;
unsigned long V_71 ;
struct V_16 * V_17 ;
F_379 ( V_223 ) ;
unsigned int V_353 ;
F_378 ( V_219 , V_354 ) ;
if ( ! F_64 ( & V_219 -> V_222 ) )
F_386 ( V_219 , V_354 ) ;
if ( F_64 ( & V_219 -> V_223 ) )
return;
F_380 ( & V_219 -> V_223 , & V_223 ) ;
F_387 ( NULL , & V_223 , F_374 ) ;
V_6 = NULL ;
V_353 = 0 ;
F_388 ( V_71 ) ;
while ( ! F_64 ( & V_223 ) ) {
V_17 = F_250 ( V_223 . V_361 ) ;
F_325 ( & V_17 -> V_18 ) ;
F_189 ( ! V_17 -> V_6 ) ;
if ( V_17 -> V_6 != V_6 ) {
if ( V_6 )
F_375 ( V_6 , V_353 , V_354 ) ;
V_6 = V_17 -> V_6 ;
V_353 = 0 ;
F_389 ( V_6 -> V_60 ) ;
}
if ( F_20 ( F_105 ( V_6 ) ) ) {
F_323 ( V_17 , V_34 ) ;
continue;
}
if ( F_158 ( V_17 -> V_55 ) )
F_194 ( V_6 , V_17 , V_235 ) ;
else
F_194 ( V_6 , V_17 , V_362 ) ;
V_353 ++ ;
}
if ( V_6 )
F_375 ( V_6 , V_353 , V_354 ) ;
F_390 ( V_71 ) ;
}
void F_391 ( struct V_218 * V_219 )
{
if ( V_219 != V_188 -> V_219 )
return;
F_251 ( V_219 , false ) ;
V_188 -> V_219 = NULL ;
}
void F_392 ( struct V_11 * V_6 , struct V_363 * V_183 )
{
if ( V_6 -> V_62 )
return;
V_6 -> V_183 = V_183 ;
V_6 -> V_297 = V_299 ;
F_393 ( V_6 -> V_183 , - 1 ) ;
F_394 ( V_6 -> V_183 ) ;
}
int F_395 ( struct V_11 * V_6 )
{
int V_112 = 0 ;
if ( ! V_6 -> V_183 )
return V_112 ;
F_31 ( V_6 -> V_60 ) ;
if ( V_6 -> V_206 ) {
V_112 = - V_113 ;
F_201 ( V_6 -> V_183 ) ;
} else {
V_6 -> V_297 = V_364 ;
}
F_33 ( V_6 -> V_60 ) ;
return V_112 ;
}
void F_396 ( struct V_11 * V_6 , int V_365 )
{
if ( ! V_6 -> V_183 )
return;
F_31 ( V_6 -> V_60 ) ;
if ( ! V_365 ) {
V_6 -> V_297 = V_298 ;
} else {
V_6 -> V_297 = V_299 ;
F_201 ( V_6 -> V_183 ) ;
}
F_33 ( V_6 -> V_60 ) ;
}
void F_397 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_183 )
return;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_297 = V_366 ;
F_33 ( V_6 -> V_60 ) ;
}
void F_398 ( struct V_11 * V_6 , int V_365 )
{
if ( ! V_6 -> V_183 )
return;
F_31 ( V_6 -> V_60 ) ;
if ( ! V_365 ) {
V_6 -> V_297 = V_299 ;
F_32 ( V_6 ) ;
F_201 ( V_6 -> V_183 ) ;
F_399 ( V_6 -> V_183 ) ;
} else {
V_6 -> V_297 = V_298 ;
}
F_33 ( V_6 -> V_60 ) ;
}
void F_400 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_297 = V_299 ;
F_201 ( V_6 -> V_183 ) ;
F_399 ( V_6 -> V_183 ) ;
F_33 ( V_6 -> V_60 ) ;
}
int T_7 F_401 ( void )
{
F_402 ( V_367 >= ( 1 << V_368 ) ) ;
F_402 ( V_368 + V_369 > 8 *
F_403 ( struct V_16 , V_55 ) ) ;
F_402 ( V_368 + V_369 > 8 *
F_403 ( struct V_44 , V_208 ) ) ;
V_63 = F_404 ( L_20 ,
V_370 | V_371 , 0 ) ;
if ( ! V_63 )
F_405 ( L_21 ) ;
V_100 = F_406 ( L_22 ,
sizeof( struct V_16 ) , 0 , V_372 , NULL ) ;
V_121 = F_406 ( L_23 ,
sizeof( struct V_11 ) , 0 , V_372 , NULL ) ;
#ifdef F_407
V_373 = F_408 ( L_6 , NULL ) ;
#endif
return 0 ;
}
