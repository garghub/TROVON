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
F_44 ( ! F_45 () && ! F_46 () ) ;
F_15 ( V_6 -> V_62 ) ;
F_41 ( V_64 , V_6 ) ;
F_32 ( V_6 ) ;
}
void F_47 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
F_48 ( & V_6 -> V_59 ) ;
F_49 ( V_64 , V_6 ) ;
}
void F_50 ( struct V_11 * V_6 )
{
F_51 ( & V_6 -> V_65 ) ;
if ( V_6 -> V_62 ) {
struct V_66 * V_67 ;
int V_31 ;
F_52 (q, hctx, i)
F_53 ( & V_67 -> V_68 ) ;
} else {
F_53 ( & V_6 -> V_59 ) ;
}
}
inline void F_54 ( struct V_11 * V_6 )
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
if ( F_20 ( F_55 ( V_6 ) ) )
return;
F_54 ( V_6 ) ;
}
void F_42 ( struct V_11 * V_6 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( F_36 ( ! F_55 ( V_6 ) && ! F_37 ( V_6 ) ) )
F_56 ( V_63 , & V_6 -> V_59 , 0 ) ;
}
void F_57 ( struct V_11 * V_6 )
{
unsigned long V_71 ;
F_15 ( V_6 -> V_62 ) ;
F_58 ( V_6 -> V_60 , V_71 ) ;
F_32 ( V_6 ) ;
F_59 ( V_6 -> V_60 , V_71 ) ;
}
void F_60 ( struct V_11 * V_6 )
{
F_61 ( & V_6 -> V_72 ) ;
}
static void F_62 ( struct V_11 * V_6 , bool V_73 )
__releases( V_6 -> V_60 )
__acquires( V_6 -> V_60 )
{
int V_31 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
while ( true ) {
bool V_74 = false ;
if ( V_6 -> V_75 )
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
if ( ! F_65 ( & V_6 -> V_76 ) && V_6 -> V_70 )
F_32 ( V_6 ) ;
V_74 |= V_6 -> V_77 ;
V_74 |= V_6 -> V_69 ;
if ( V_73 ) {
struct V_78 * V_79 = F_66 ( V_6 , NULL ) ;
V_74 |= ! F_65 ( & V_6 -> V_76 ) ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_74 |= V_6 -> V_80 [ V_31 ] ;
V_74 |= V_6 -> V_81 [ V_31 ] ;
if ( V_79 )
V_74 |= ! F_65 ( & V_79 -> V_82 [ V_31 ] ) ;
}
}
if ( ! V_74 )
break;
F_33 ( V_6 -> V_60 ) ;
F_67 ( 10 ) ;
F_31 ( V_6 -> V_60 ) ;
}
if ( V_6 -> V_70 ) {
struct V_1 * V_2 ;
F_68 (rl, q)
for ( V_31 = 0 ; V_31 < F_13 ( V_2 -> V_83 ) ; V_31 ++ )
F_69 ( & V_2 -> V_83 [ V_31 ] ) ;
}
}
void F_70 ( struct V_11 * V_6 )
{
F_15 ( V_6 -> V_62 ) ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_84 ++ ;
F_49 ( V_85 , V_6 ) ;
F_33 ( V_6 -> V_60 ) ;
if ( F_71 ( V_6 ) ) {
F_31 ( V_6 -> V_60 ) ;
F_62 ( V_6 , false ) ;
F_33 ( V_6 -> V_60 ) ;
F_72 () ;
}
}
void F_73 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
if ( ! -- V_6 -> V_84 )
F_41 ( V_85 , V_6 ) ;
F_15 ( V_6 -> V_84 < 0 ) ;
F_33 ( V_6 -> V_60 ) ;
}
void F_74 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
F_49 ( V_86 , V_6 ) ;
F_33 ( V_6 -> V_60 ) ;
F_75 ( V_6 ) ;
if ( V_6 -> V_62 )
F_76 ( V_6 ) ;
else {
struct V_1 * V_2 ;
F_31 ( V_6 -> V_60 ) ;
F_68 (rl, q) {
if ( V_2 -> V_87 ) {
F_77 ( & V_2 -> V_83 [ V_88 ] ) ;
F_77 ( & V_2 -> V_83 [ V_89 ] ) ;
}
}
F_33 ( V_6 -> V_60 ) ;
}
}
void F_78 ( struct V_11 * V_6 )
{
T_2 * V_90 = V_6 -> V_60 ;
F_79 ( & V_6 -> V_91 ) ;
F_74 ( V_6 ) ;
F_31 ( V_90 ) ;
V_6 -> V_84 ++ ;
F_49 ( V_85 , V_6 ) ;
F_49 ( V_92 , V_6 ) ;
F_49 ( V_93 , V_6 ) ;
F_49 ( V_86 , V_6 ) ;
F_33 ( V_90 ) ;
F_80 ( & V_6 -> V_91 ) ;
F_81 ( V_6 ) ;
F_31 ( V_90 ) ;
if ( ! V_6 -> V_62 )
F_62 ( V_6 , true ) ;
F_49 ( V_94 , V_6 ) ;
F_33 ( V_90 ) ;
F_82 () ;
F_51 ( & V_6 -> V_8 -> V_95 ) ;
F_50 ( V_6 ) ;
if ( V_6 -> V_62 )
F_83 ( V_6 ) ;
F_84 ( & V_6 -> V_96 ) ;
F_31 ( V_90 ) ;
if ( V_6 -> V_60 != & V_6 -> V_97 )
V_6 -> V_60 = & V_6 -> V_97 ;
F_33 ( V_90 ) ;
F_60 ( V_6 ) ;
}
static void * F_85 ( T_3 V_98 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
return F_86 ( V_100 , V_98 , V_6 -> V_101 ) ;
}
static void F_87 ( void * V_102 , void * V_99 )
{
F_88 ( V_100 , V_102 ) ;
}
static void * F_89 ( T_3 V_98 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
struct V_16 * V_17 ;
V_17 = F_90 ( sizeof( struct V_16 ) + V_6 -> V_103 , V_98 ,
V_6 -> V_101 ) ;
if ( V_17 && V_6 -> V_104 && V_6 -> V_104 ( V_6 , V_17 , V_98 ) < 0 ) {
F_91 ( V_17 ) ;
V_17 = NULL ;
}
return V_17 ;
}
static void F_92 ( void * V_102 , void * V_99 )
{
struct V_11 * V_6 = V_99 ;
if ( V_6 -> V_105 )
V_6 -> V_105 ( V_6 , V_102 ) ;
F_91 ( V_102 ) ;
}
int F_93 ( struct V_1 * V_2 , struct V_11 * V_6 ,
T_3 V_98 )
{
if ( F_20 ( V_2 -> V_87 ) )
return 0 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_106 [ V_88 ] = V_2 -> V_106 [ V_89 ] = 0 ;
V_2 -> V_107 [ V_88 ] = V_2 -> V_107 [ V_89 ] = 0 ;
F_94 ( & V_2 -> V_83 [ V_88 ] ) ;
F_94 ( & V_2 -> V_83 [ V_89 ] ) ;
if ( V_6 -> V_103 ) {
V_2 -> V_87 = F_95 ( V_108 ,
F_89 , F_92 ,
V_6 , V_98 , V_6 -> V_101 ) ;
} else {
V_2 -> V_87 = F_95 ( V_108 ,
F_85 , F_87 ,
V_6 , V_98 , V_6 -> V_101 ) ;
}
if ( ! V_2 -> V_87 )
return - V_109 ;
if ( V_2 != & V_6 -> V_7 )
F_15 ( ! F_96 ( V_6 ) ) ;
return 0 ;
}
void F_97 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_98 ( V_2 -> V_87 ) ;
if ( V_2 != & V_6 -> V_7 )
F_60 ( V_6 ) ;
}
}
struct V_11 * F_99 ( T_3 V_98 )
{
return F_100 ( V_98 , V_110 ) ;
}
int F_101 ( struct V_11 * V_6 , bool V_111 )
{
while ( true ) {
int V_112 ;
if ( F_102 ( & V_6 -> V_96 ) )
return 0 ;
if ( V_111 )
return - V_113 ;
F_103 () ;
V_112 = F_104 ( V_6 -> V_114 ,
! F_105 ( & V_6 -> V_115 ) ||
F_106 ( V_6 ) ) ;
if ( F_106 ( V_6 ) )
return - V_116 ;
if ( V_112 )
return V_112 ;
}
}
void F_107 ( struct V_11 * V_6 )
{
F_108 ( & V_6 -> V_96 ) ;
}
static void F_109 ( struct V_117 * V_118 )
{
struct V_11 * V_6 =
F_30 ( V_118 , struct V_11 , V_96 ) ;
F_69 ( & V_6 -> V_114 ) ;
}
static void F_110 ( unsigned long V_99 )
{
struct V_11 * V_6 = (struct V_11 * ) V_99 ;
F_111 ( & V_6 -> V_119 ) ;
}
struct V_11 * F_100 ( T_3 V_98 , int V_120 )
{
struct V_11 * V_6 ;
V_6 = F_86 ( V_121 ,
V_98 | V_122 , V_120 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_123 = F_112 ( & V_124 , 0 , 0 , V_98 ) ;
if ( V_6 -> V_123 < 0 )
goto V_125;
V_6 -> V_126 = F_113 ( V_127 , 0 , V_128 ) ;
if ( ! V_6 -> V_126 )
goto V_129;
V_6 -> V_8 = F_114 ( V_98 , V_120 ) ;
if ( ! V_6 -> V_8 )
goto V_130;
V_6 -> V_131 = F_115 () ;
if ( ! V_6 -> V_131 )
goto V_132;
V_6 -> V_8 -> V_133 =
( V_134 * 1024 ) / V_135 ;
V_6 -> V_8 -> V_136 = V_137 ;
V_6 -> V_8 -> V_41 = L_6 ;
V_6 -> V_101 = V_120 ;
F_116 ( & V_6 -> V_8 -> V_95 ,
V_138 , ( unsigned long ) V_6 ) ;
F_116 ( & V_6 -> V_65 , F_110 , ( unsigned long ) V_6 ) ;
F_8 ( & V_6 -> V_76 ) ;
F_8 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_139 ) ;
#ifdef F_117
F_8 ( & V_6 -> V_140 ) ;
#endif
F_118 ( & V_6 -> V_59 , F_29 ) ;
F_119 ( & V_6 -> V_72 , & V_141 ) ;
#ifdef F_120
F_121 ( & V_6 -> V_142 ) ;
#endif
F_121 ( & V_6 -> V_91 ) ;
F_122 ( & V_6 -> V_97 ) ;
V_6 -> V_60 = & V_6 -> V_97 ;
V_6 -> V_84 = 1 ;
F_123 ( V_85 , & V_6 -> V_143 ) ;
F_94 ( & V_6 -> V_114 ) ;
if ( F_124 ( & V_6 -> V_96 ,
F_109 ,
V_144 , V_145 ) )
goto V_146;
if ( F_125 ( V_6 ) )
goto V_147;
return V_6 ;
V_147:
F_84 ( & V_6 -> V_96 ) ;
V_146:
F_126 ( V_6 -> V_131 ) ;
V_132:
F_127 ( V_6 -> V_8 ) ;
V_130:
F_128 ( V_6 -> V_126 ) ;
V_129:
F_129 ( & V_124 , V_6 -> V_123 ) ;
V_125:
F_88 ( V_121 , V_6 ) ;
return NULL ;
}
struct V_11 * F_130 ( T_4 * V_148 , T_2 * V_90 )
{
return F_131 ( V_148 , V_90 , V_110 ) ;
}
struct V_11 *
F_131 ( T_4 * V_148 , T_2 * V_90 , int V_120 )
{
struct V_11 * V_6 ;
V_6 = F_100 ( V_145 , V_120 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_70 = V_148 ;
if ( V_90 )
V_6 -> V_60 = V_90 ;
if ( F_132 ( V_6 ) < 0 ) {
F_78 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
int F_132 ( struct V_11 * V_6 )
{
F_15 ( V_6 -> V_62 ) ;
V_6 -> V_79 = F_133 ( V_6 , V_110 , V_6 -> V_103 ) ;
if ( ! V_6 -> V_79 )
return - V_109 ;
if ( V_6 -> V_104 && V_6 -> V_104 ( V_6 , V_6 -> V_79 -> V_149 , V_145 ) )
goto V_150;
if ( F_93 ( & V_6 -> V_7 , V_6 , V_145 ) )
goto V_151;
F_134 ( & V_6 -> V_119 , V_152 ) ;
V_6 -> V_143 |= V_153 ;
F_135 ( V_6 , V_154 ) ;
V_6 -> V_155 = V_156 ;
F_79 ( & V_6 -> V_91 ) ;
if ( F_136 ( V_6 , NULL ) ) {
F_80 ( & V_6 -> V_91 ) ;
goto V_151;
}
F_80 ( & V_6 -> V_91 ) ;
return 0 ;
V_151:
if ( V_6 -> V_105 )
V_6 -> V_105 ( V_6 , V_6 -> V_79 -> V_149 ) ;
V_150:
F_137 ( V_6 -> V_79 ) ;
return - V_109 ;
}
bool F_96 ( struct V_11 * V_6 )
{
if ( F_36 ( ! F_106 ( V_6 ) ) ) {
F_138 ( V_6 ) ;
return true ;
}
return false ;
}
static inline void F_139 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_47 & V_157 ) {
F_140 ( V_2 -> V_6 , V_17 ) ;
if ( V_17 -> V_158 . V_159 )
F_141 ( V_17 -> V_158 . V_159 -> V_160 ) ;
}
F_142 ( V_17 , V_2 -> V_87 ) ;
}
static inline int F_143 ( struct V_11 * V_6 , struct V_161 * V_160 )
{
if ( ! V_160 )
return 0 ;
return V_160 -> V_162 == V_6 -> V_163 ||
( V_160 -> V_162 > 0
&& F_144 ( V_28 , V_160 -> V_164 + V_165 ) ) ;
}
static void F_145 ( struct V_11 * V_6 , struct V_161 * V_160 )
{
if ( ! V_160 || F_143 ( V_6 , V_160 ) )
return;
V_160 -> V_162 = V_6 -> V_163 ;
V_160 -> V_164 = V_28 ;
}
static void F_146 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_106 [ V_3 ] < F_147 ( V_6 ) )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_106 [ V_3 ] + 1 <= V_6 -> V_13 ) {
if ( F_148 ( & V_2 -> V_83 [ V_3 ] ) )
F_77 ( & V_2 -> V_83 [ V_3 ] ) ;
F_149 ( V_2 , V_3 ) ;
}
}
static void F_150 ( struct V_1 * V_2 , bool V_3 ,
T_5 V_47 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
V_6 -> V_80 [ V_3 ] -- ;
V_2 -> V_106 [ V_3 ] -- ;
if ( V_47 & V_157 )
V_6 -> V_77 -- ;
F_146 ( V_2 , V_3 ) ;
if ( F_20 ( V_2 -> V_107 [ V_3 ^ 1 ] ) )
F_146 ( V_2 , V_3 ^ 1 ) ;
}
int F_151 ( struct V_11 * V_6 , unsigned int V_12 )
{
struct V_1 * V_2 ;
int V_166 , V_167 ;
F_15 ( V_6 -> V_62 ) ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_13 = V_12 ;
F_6 ( V_6 ) ;
V_166 = F_152 ( V_6 ) ;
V_167 = F_147 ( V_6 ) ;
F_68 (rl, q) {
if ( V_2 -> V_106 [ V_88 ] >= V_166 )
F_4 ( V_2 , V_88 ) ;
else if ( V_2 -> V_106 [ V_88 ] < V_167 )
F_1 ( V_2 , V_88 ) ;
if ( V_2 -> V_106 [ V_89 ] >= V_166 )
F_4 ( V_2 , V_89 ) ;
else if ( V_2 -> V_106 [ V_89 ] < V_167 )
F_1 ( V_2 , V_89 ) ;
if ( V_2 -> V_106 [ V_88 ] >= V_6 -> V_13 ) {
F_153 ( V_2 , V_88 ) ;
} else {
F_149 ( V_2 , V_88 ) ;
F_77 ( & V_2 -> V_83 [ V_88 ] ) ;
}
if ( V_2 -> V_106 [ V_89 ] >= V_6 -> V_13 ) {
F_153 ( V_2 , V_89 ) ;
} else {
F_149 ( V_2 , V_89 ) ;
F_77 ( & V_2 -> V_83 [ V_89 ] ) ;
}
}
F_33 ( V_6 -> V_60 ) ;
return 0 ;
}
static struct V_16 * F_154 ( struct V_1 * V_2 , unsigned int V_168 ,
struct V_44 * V_44 , T_3 V_98 )
{
struct V_11 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 ;
struct V_169 * V_170 = V_6 -> V_75 -> type ;
struct V_161 * V_160 = F_155 ( V_44 ) ;
struct V_171 * V_159 = NULL ;
const bool V_172 = F_156 ( V_168 ) ;
int V_173 ;
T_5 V_47 = V_174 ;
F_35 ( V_6 -> V_60 ) ;
if ( F_20 ( F_106 ( V_6 ) ) )
return F_157 ( - V_116 ) ;
V_173 = F_158 ( V_6 , V_168 ) ;
if ( V_173 == V_175 )
goto V_176;
if ( V_2 -> V_106 [ V_172 ] + 1 >= F_152 ( V_6 ) ) {
if ( V_2 -> V_106 [ V_172 ] + 1 >= V_6 -> V_13 ) {
if ( ! F_159 ( V_2 , V_172 ) ) {
F_145 ( V_6 , V_160 ) ;
F_153 ( V_2 , V_172 ) ;
} else {
if ( V_173 != V_177
&& ! F_143 ( V_6 , V_160 ) ) {
return F_157 ( - V_109 ) ;
}
}
}
F_4 ( V_2 , V_172 ) ;
}
if ( V_2 -> V_106 [ V_172 ] >= ( 3 * V_6 -> V_13 / 2 ) )
return F_157 ( - V_109 ) ;
V_6 -> V_80 [ V_172 ] ++ ;
V_2 -> V_106 [ V_172 ] ++ ;
V_2 -> V_107 [ V_172 ] = 0 ;
if ( ! F_160 ( V_168 ) && ! F_161 ( V_6 ) ) {
V_47 |= V_157 ;
V_6 -> V_77 ++ ;
if ( V_170 -> V_178 && V_160 )
V_159 = F_162 ( V_160 , V_6 ) ;
}
if ( F_163 ( V_6 ) )
V_47 |= V_179 ;
F_33 ( V_6 -> V_60 ) ;
V_17 = F_164 ( V_2 -> V_87 , V_98 ) ;
if ( ! V_17 )
goto V_180;
F_7 ( V_6 , V_17 ) ;
F_165 ( V_17 , V_2 ) ;
V_17 -> V_55 = V_168 ;
V_17 -> V_47 = V_47 ;
if ( V_47 & V_157 ) {
if ( F_20 ( V_170 -> V_178 && ! V_159 ) ) {
if ( V_160 )
V_159 = F_166 ( V_160 , V_6 , V_98 ) ;
if ( ! V_159 )
goto V_181;
}
V_17 -> V_158 . V_159 = V_159 ;
if ( F_20 ( F_167 ( V_6 , V_17 , V_44 , V_98 ) ) )
goto V_181;
if ( V_159 )
F_168 ( V_159 -> V_160 ) ;
}
V_182:
if ( F_143 ( V_6 , V_160 ) )
V_160 -> V_162 -- ;
F_169 ( V_6 , V_44 , V_168 ) ;
return V_17 ;
V_181:
F_17 ( V_183 L_7 ,
V_40 , F_170 ( V_6 -> V_8 -> V_184 ) ) ;
V_17 -> V_47 &= ~ V_157 ;
V_17 -> V_158 . V_159 = NULL ;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_77 -- ;
F_33 ( V_6 -> V_60 ) ;
goto V_182;
V_180:
F_31 ( V_6 -> V_60 ) ;
F_150 ( V_2 , V_172 , V_47 ) ;
V_176:
if ( F_20 ( V_2 -> V_106 [ V_172 ] == 0 ) )
V_2 -> V_107 [ V_172 ] = 1 ;
return F_157 ( - V_109 ) ;
}
static struct V_16 * F_171 ( struct V_11 * V_6 , unsigned int V_168 ,
struct V_44 * V_44 , T_3 V_98 )
{
const bool V_172 = F_156 ( V_168 ) ;
F_172 ( V_83 ) ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
V_2 = F_173 ( V_6 , V_44 ) ;
V_185:
V_17 = F_154 ( V_2 , V_168 , V_44 , V_98 ) ;
if ( ! F_174 ( V_17 ) )
return V_17 ;
if ( V_168 & V_186 ) {
F_175 ( V_2 ) ;
return F_157 ( - V_187 ) ;
}
if ( ! F_176 ( V_98 ) || F_20 ( F_106 ( V_6 ) ) ) {
F_175 ( V_2 ) ;
return V_17 ;
}
F_177 ( & V_2 -> V_83 [ V_172 ] , & V_83 ,
V_188 ) ;
F_178 ( V_6 , V_44 , V_168 ) ;
F_33 ( V_6 -> V_60 ) ;
F_179 () ;
F_145 ( V_6 , V_189 -> V_161 ) ;
F_31 ( V_6 -> V_60 ) ;
F_180 ( & V_2 -> V_83 [ V_172 ] , & V_83 ) ;
goto V_185;
}
static struct V_16 * F_181 ( struct V_11 * V_6 ,
unsigned int V_168 , T_3 V_98 )
{
struct V_16 * V_17 ;
F_15 ( V_6 -> V_62 ) ;
F_182 ( V_98 , V_6 -> V_101 ) ;
F_31 ( V_6 -> V_60 ) ;
V_17 = F_171 ( V_6 , V_168 , NULL , V_98 ) ;
if ( F_174 ( V_17 ) ) {
F_33 ( V_6 -> V_60 ) ;
return V_17 ;
}
V_17 -> V_190 = 0 ;
V_17 -> V_21 = ( V_22 ) - 1 ;
V_17 -> V_44 = V_17 -> V_56 = NULL ;
return V_17 ;
}
struct V_16 * F_183 ( struct V_11 * V_6 , unsigned int V_168 ,
T_3 V_98 )
{
struct V_16 * V_38 ;
if ( V_6 -> V_62 ) {
V_38 = F_184 ( V_6 , V_168 ,
( V_98 & V_191 ) ?
0 : V_192 ) ;
if ( ! F_174 ( V_38 ) && V_6 -> V_62 -> V_193 )
V_6 -> V_62 -> V_193 ( V_38 ) ;
} else {
V_38 = F_181 ( V_6 , V_168 , V_98 ) ;
if ( ! F_174 ( V_38 ) && V_6 -> V_193 )
V_6 -> V_193 ( V_38 ) ;
}
return V_38 ;
}
void F_185 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
F_186 ( V_17 ) ;
F_187 ( V_17 ) ;
F_188 ( V_6 , V_17 ) ;
F_189 ( V_6 -> V_194 , & V_17 -> V_195 ) ;
if ( V_17 -> V_47 & V_196 )
F_190 ( V_6 , V_17 ) ;
F_191 ( F_192 ( V_17 ) ) ;
F_193 ( V_6 , V_17 ) ;
}
static void F_194 ( struct V_11 * V_6 , struct V_16 * V_17 ,
int V_197 )
{
F_195 ( V_17 , true ) ;
F_196 ( V_6 , V_17 , V_197 ) ;
}
static void F_197 ( struct V_11 * V_6 , int V_20 ,
struct V_198 * V_29 , unsigned long V_199 ,
unsigned int V_200 )
{
if ( V_200 ) {
F_198 ( V_20 , V_29 , V_201 ,
V_200 * ( V_199 - V_29 -> V_202 ) ) ;
F_198 ( V_20 , V_29 , V_203 , ( V_199 - V_29 -> V_202 ) ) ;
}
V_29 -> V_202 = V_199 ;
}
void F_199 ( struct V_11 * V_6 , int V_20 , struct V_198 * V_29 )
{
struct V_198 * V_204 = NULL ;
unsigned long V_199 = V_28 ;
unsigned int V_200 [ 2 ] ;
int V_131 = 0 ;
if ( V_29 -> V_202 != V_199 )
V_131 |= 1 ;
if ( V_29 -> V_205 ) {
V_204 = & F_200 ( V_29 ) -> V_206 ;
if ( V_204 -> V_202 != V_199 )
V_131 |= 2 ;
}
if ( ! V_131 )
return;
F_201 ( V_6 , V_29 , V_200 ) ;
if ( V_131 & 2 )
F_197 ( V_6 , V_20 , V_204 , V_199 , V_200 [ 1 ] ) ;
if ( V_131 & 1 )
F_197 ( V_6 , V_20 , V_29 , V_199 , V_200 [ 0 ] ) ;
}
static void F_202 ( struct V_16 * V_17 )
{
if ( V_17 -> V_6 -> V_184 && ! ( V_17 -> V_47 & V_207 ) && ! -- V_17 -> V_6 -> V_208 )
F_203 ( V_17 -> V_6 -> V_184 ) ;
}
static inline void F_202 ( struct V_16 * V_17 ) {}
void F_204 ( struct V_11 * V_6 , struct V_16 * V_38 )
{
T_5 V_47 = V_38 -> V_47 ;
if ( F_20 ( ! V_6 ) )
return;
if ( V_6 -> V_62 ) {
F_205 ( V_38 ) ;
return;
}
F_35 ( V_6 -> V_60 ) ;
F_202 ( V_38 ) ;
F_206 ( V_6 , V_38 ) ;
F_44 ( V_38 -> V_44 != NULL ) ;
F_207 ( V_6 -> V_194 , & V_38 -> V_195 ) ;
if ( V_47 & V_174 ) {
struct V_1 * V_2 = F_208 ( V_38 ) ;
bool V_3 = F_156 ( V_38 -> V_55 ) ;
F_191 ( ! F_65 ( & V_38 -> V_18 ) ) ;
F_191 ( F_209 ( V_38 ) ) ;
F_139 ( V_2 , V_38 ) ;
F_150 ( V_2 , V_3 , V_47 ) ;
F_175 ( V_2 ) ;
}
}
void F_210 ( struct V_16 * V_38 )
{
struct V_11 * V_6 = V_38 -> V_6 ;
if ( V_6 -> V_62 )
F_205 ( V_38 ) ;
else {
unsigned long V_71 ;
F_58 ( V_6 -> V_60 , V_71 ) ;
F_204 ( V_6 , V_38 ) ;
F_59 ( V_6 -> V_60 , V_71 ) ;
}
}
bool F_211 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
const int V_209 = V_44 -> V_210 & V_211 ;
if ( ! F_212 ( V_6 , V_38 , V_44 ) )
return false ;
F_213 ( V_6 , V_38 , V_44 ) ;
if ( ( V_38 -> V_55 & V_211 ) != V_209 )
F_214 ( V_38 ) ;
V_38 -> V_56 -> V_212 = V_44 ;
V_38 -> V_56 = V_44 ;
V_38 -> V_190 += V_44 -> V_50 . V_51 ;
V_38 -> V_213 = F_215 ( V_38 -> V_213 , F_216 ( V_44 ) ) ;
F_195 ( V_38 , false ) ;
return true ;
}
bool F_217 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
const int V_209 = V_44 -> V_210 & V_211 ;
if ( ! F_218 ( V_6 , V_38 , V_44 ) )
return false ;
F_219 ( V_6 , V_38 , V_44 ) ;
if ( ( V_38 -> V_55 & V_211 ) != V_209 )
F_214 ( V_38 ) ;
V_44 -> V_212 = V_38 -> V_44 ;
V_38 -> V_44 = V_44 ;
V_38 -> V_21 = V_44 -> V_50 . V_214 ;
V_38 -> V_190 += V_44 -> V_50 . V_51 ;
V_38 -> V_213 = F_215 ( V_38 -> V_213 , F_216 ( V_44 ) ) ;
F_195 ( V_38 , false ) ;
return true ;
}
bool F_220 ( struct V_11 * V_6 , struct V_16 * V_38 ,
struct V_44 * V_44 )
{
unsigned short V_215 = F_221 ( V_38 ) ;
if ( V_215 >= F_222 ( V_6 ) )
goto V_216;
if ( F_26 ( V_38 ) + F_223 ( V_44 ) >
F_224 ( V_38 , F_18 ( V_38 ) ) )
goto V_216;
V_38 -> V_56 -> V_212 = V_44 ;
V_38 -> V_56 = V_44 ;
V_38 -> V_190 += V_44 -> V_50 . V_51 ;
V_38 -> V_213 = F_215 ( V_38 -> V_213 , F_216 ( V_44 ) ) ;
V_38 -> V_217 = V_215 + 1 ;
F_195 ( V_38 , false ) ;
return true ;
V_216:
F_225 ( V_6 , V_38 ) ;
return false ;
}
bool F_226 ( struct V_11 * V_6 , struct V_44 * V_44 ,
unsigned int * V_218 ,
struct V_16 * * V_219 )
{
struct V_220 * V_221 ;
struct V_16 * V_17 ;
struct V_222 * V_223 ;
V_221 = V_189 -> V_221 ;
if ( ! V_221 )
return false ;
* V_218 = 0 ;
if ( V_6 -> V_62 )
V_223 = & V_221 -> V_224 ;
else
V_223 = & V_221 -> V_225 ;
F_227 (rq, plug_list, queuelist) {
bool V_226 = false ;
if ( V_17 -> V_6 == V_6 ) {
( * V_218 ) ++ ;
if ( V_219 )
* V_219 = V_17 ;
}
if ( V_17 -> V_6 != V_6 || ! F_228 ( V_17 , V_44 ) )
continue;
switch ( F_229 ( V_17 , V_44 ) ) {
case V_227 :
V_226 = F_211 ( V_6 , V_17 , V_44 ) ;
break;
case V_228 :
V_226 = F_217 ( V_6 , V_17 , V_44 ) ;
break;
case V_229 :
V_226 = F_220 ( V_6 , V_17 , V_44 ) ;
break;
default:
break;
}
if ( V_226 )
return true ;
}
return false ;
}
unsigned int F_230 ( struct V_11 * V_6 )
{
struct V_220 * V_221 ;
struct V_16 * V_17 ;
struct V_222 * V_223 ;
unsigned int V_112 = 0 ;
V_221 = V_189 -> V_221 ;
if ( ! V_221 )
goto V_182;
if ( V_6 -> V_62 )
V_223 = & V_221 -> V_224 ;
else
V_223 = & V_221 -> V_225 ;
F_231 (rq, plug_list, queuelist) {
if ( V_17 -> V_6 == V_6 )
V_112 ++ ;
}
V_182:
return V_112 ;
}
void F_232 ( struct V_16 * V_38 , struct V_44 * V_44 )
{
struct V_161 * V_160 = F_155 ( V_44 ) ;
if ( V_44 -> V_210 & V_230 )
V_38 -> V_55 |= V_211 ;
V_38 -> V_21 = V_44 -> V_50 . V_214 ;
if ( F_233 ( F_216 ( V_44 ) ) )
V_38 -> V_213 = F_216 ( V_44 ) ;
else if ( V_160 )
V_38 -> V_213 = V_160 -> V_213 ;
else
V_38 -> V_213 = F_234 ( V_231 , 0 ) ;
V_38 -> V_232 = V_44 -> V_233 ;
F_235 ( V_38 -> V_6 , V_38 , V_44 ) ;
}
static T_6 V_154 ( struct V_11 * V_6 , struct V_44 * V_44 )
{
struct V_220 * V_221 ;
int V_197 = V_234 ;
struct V_16 * V_38 , * free ;
unsigned int V_218 = 0 ;
unsigned int V_235 ;
F_236 ( V_6 , & V_44 ) ;
F_237 ( V_6 , & V_44 ) ;
if ( ! F_238 ( V_44 ) )
return V_236 ;
if ( F_160 ( V_44 -> V_210 ) ) {
F_31 ( V_6 -> V_60 ) ;
V_197 = V_237 ;
goto V_238;
}
if ( ! F_239 ( V_6 ) ) {
if ( F_226 ( V_6 , V_44 , & V_218 , NULL ) )
return V_236 ;
} else
V_218 = F_230 ( V_6 ) ;
F_31 ( V_6 -> V_60 ) ;
switch ( F_240 ( V_6 , & V_38 , V_44 ) ) {
case V_227 :
if ( ! F_211 ( V_6 , V_38 , V_44 ) )
break;
F_241 ( V_6 , V_38 , V_44 ) ;
free = F_242 ( V_6 , V_38 ) ;
if ( free )
F_204 ( V_6 , free ) ;
else
F_243 ( V_6 , V_38 , V_227 ) ;
goto V_239;
case V_228 :
if ( ! F_217 ( V_6 , V_38 , V_44 ) )
break;
F_241 ( V_6 , V_38 , V_44 ) ;
free = F_244 ( V_6 , V_38 ) ;
if ( free )
F_204 ( V_6 , free ) ;
else
F_243 ( V_6 , V_38 , V_228 ) ;
goto V_239;
default:
break;
}
V_238:
V_235 = F_245 ( V_6 -> V_194 , V_44 , V_6 -> V_60 ) ;
V_38 = F_171 ( V_6 , V_44 -> V_210 , V_44 , V_240 ) ;
if ( F_174 ( V_38 ) ) {
F_246 ( V_6 -> V_194 , V_235 ) ;
if ( F_247 ( V_38 ) == - V_109 )
V_44 -> V_46 = V_241 ;
else
V_44 -> V_46 = V_34 ;
F_23 ( V_44 ) ;
goto V_239;
}
F_248 ( & V_38 -> V_195 , V_235 ) ;
F_232 ( V_38 , V_44 ) ;
if ( F_249 ( V_242 , & V_6 -> V_143 ) )
V_38 -> V_20 = F_250 () ;
V_221 = V_189 -> V_221 ;
if ( V_221 ) {
if ( ! V_218 || F_65 ( & V_221 -> V_225 ) )
F_251 ( V_6 ) ;
else {
struct V_16 * V_243 = F_252 ( V_221 -> V_225 . V_244 ) ;
if ( V_218 >= V_245 ||
F_28 ( V_243 ) >= V_246 ) {
F_253 ( V_221 , false ) ;
F_251 ( V_6 ) ;
}
}
F_254 ( & V_38 -> V_18 , & V_221 -> V_225 ) ;
F_195 ( V_38 , true ) ;
} else {
F_31 ( V_6 -> V_60 ) ;
F_194 ( V_6 , V_38 , V_197 ) ;
F_32 ( V_6 ) ;
V_239:
F_33 ( V_6 -> V_60 ) ;
}
return V_236 ;
}
static void F_255 ( struct V_44 * V_44 )
{
char V_247 [ V_248 ] ;
F_25 ( V_54 L_8 ) ;
F_25 ( V_54 L_9 ,
F_256 ( V_44 , V_247 ) , V_44 -> V_210 ,
( unsigned long long ) F_257 ( V_44 ) ,
( long long ) F_258 ( V_44 -> V_249 ) ) ;
}
static int T_7 F_259 ( char * V_250 )
{
return F_260 ( & V_251 , V_250 ) ;
}
static bool F_261 ( struct V_198 * V_29 , unsigned int V_252 )
{
return V_29 -> V_253 && F_262 ( & V_251 , V_252 ) ;
}
static int T_7 F_263 ( void )
{
struct V_254 * V_255 = F_264 ( L_10 ,
NULL , & V_251 ) ;
return F_265 ( V_255 ) ;
}
static inline bool F_261 ( struct V_198 * V_29 ,
unsigned int V_252 )
{
return false ;
}
static inline int F_266 ( struct V_44 * V_44 )
{
struct V_198 * V_256 ;
int V_112 = 0 ;
if ( ! V_44 -> V_257 ||
( ! F_223 ( V_44 ) && F_267 ( V_44 ) != V_258 ) )
return 0 ;
F_268 () ;
V_256 = F_269 ( V_44 -> V_249 , V_44 -> V_257 ) ;
if ( F_36 ( V_256 && ! F_261 ( V_256 , V_44 -> V_50 . V_51 ) ) ) {
V_44 -> V_50 . V_214 += V_256 -> V_259 ;
V_44 -> V_257 = 0 ;
F_270 ( V_44 -> V_249 -> V_260 , V_44 , F_271 ( V_256 ) ,
V_44 -> V_50 . V_214 - V_256 -> V_259 ) ;
} else {
F_25 ( L_11 , V_40 , V_44 -> V_257 ) ;
V_112 = - V_37 ;
}
F_272 () ;
return V_112 ;
}
static inline int F_273 ( struct V_44 * V_44 , unsigned int V_261 )
{
V_22 V_262 ;
if ( ! V_261 )
return 0 ;
V_262 = F_258 ( V_44 -> V_249 ) ;
if ( V_262 ) {
V_22 V_263 = V_44 -> V_50 . V_214 ;
if ( V_262 < V_261 || V_262 - V_261 < V_263 ) {
F_255 ( V_44 ) ;
return 1 ;
}
}
return 0 ;
}
static T_8 bool
F_274 ( struct V_44 * V_44 )
{
struct V_11 * V_6 ;
int V_261 = F_223 ( V_44 ) ;
T_1 V_35 = V_34 ;
char V_247 [ V_248 ] ;
F_275 () ;
if ( F_273 ( V_44 , V_261 ) )
goto V_264;
V_6 = V_44 -> V_249 -> V_260 ;
if ( F_20 ( ! V_6 ) ) {
F_25 ( V_39
L_12
L_13 ,
F_256 ( V_44 , V_247 ) , ( long long ) V_44 -> V_50 . V_214 ) ;
goto V_264;
}
if ( ( V_44 -> V_210 & V_186 ) && ! F_276 ( V_6 ) )
goto V_265;
if ( F_261 ( & V_44 -> V_249 -> V_206 , V_44 -> V_50 . V_51 ) )
goto V_264;
if ( F_266 ( V_44 ) )
goto V_264;
if ( F_273 ( V_44 , V_261 ) )
goto V_264;
if ( F_160 ( V_44 -> V_210 ) &&
! F_249 ( V_266 , & V_6 -> V_143 ) ) {
V_44 -> V_210 &= ~ ( V_267 | V_268 ) ;
if ( ! V_261 ) {
V_35 = V_269 ;
goto V_264;
}
}
switch ( F_267 ( V_44 ) ) {
case V_270 :
if ( ! F_277 ( V_6 ) )
goto V_265;
break;
case V_271 :
if ( ! F_278 ( V_6 ) )
goto V_265;
break;
case V_272 :
if ( ! V_6 -> V_273 . V_274 )
goto V_265;
break;
case V_275 :
case V_258 :
if ( ! F_279 ( V_6 ) )
goto V_265;
break;
case V_276 :
if ( ! V_6 -> V_273 . V_277 )
goto V_265;
break;
default:
break;
}
F_182 ( V_278 , V_6 -> V_101 ) ;
if ( ! F_280 ( V_6 , V_44 ) )
return false ;
if ( ! F_281 ( V_44 , V_279 ) ) {
F_282 ( V_6 , V_44 ) ;
F_21 ( V_44 , V_279 ) ;
}
return true ;
V_265:
V_35 = V_280 ;
V_264:
V_44 -> V_46 = V_35 ;
F_23 ( V_44 ) ;
return false ;
}
T_6 F_283 ( struct V_44 * V_44 )
{
struct V_281 V_282 [ 2 ] ;
T_6 V_112 = V_236 ;
if ( ! F_274 ( V_44 ) )
goto V_182;
if ( V_189 -> V_281 ) {
F_284 ( & V_189 -> V_281 [ 0 ] , V_44 ) ;
goto V_182;
}
F_191 ( V_44 -> V_212 ) ;
F_285 ( & V_282 [ 0 ] ) ;
V_189 -> V_281 = V_282 ;
do {
struct V_11 * V_6 = V_44 -> V_249 -> V_260 ;
if ( F_36 ( F_101 ( V_6 , V_44 -> V_210 & V_186 ) == 0 ) ) {
struct V_281 V_283 , V_284 ;
V_282 [ 1 ] = V_282 [ 0 ] ;
F_285 ( & V_282 [ 0 ] ) ;
V_112 = V_6 -> V_285 ( V_6 , V_44 ) ;
F_107 ( V_6 ) ;
F_285 ( & V_283 ) ;
F_285 ( & V_284 ) ;
while ( ( V_44 = F_286 ( & V_282 [ 0 ] ) ) != NULL )
if ( V_6 == V_44 -> V_249 -> V_260 )
F_284 ( & V_284 , V_44 ) ;
else
F_284 ( & V_283 , V_44 ) ;
F_287 ( & V_282 [ 0 ] , & V_283 ) ;
F_287 ( & V_282 [ 0 ] , & V_284 ) ;
F_287 ( & V_282 [ 0 ] , & V_282 [ 1 ] ) ;
} else {
if ( F_20 ( ! F_106 ( V_6 ) &&
( V_44 -> V_210 & V_186 ) ) )
F_288 ( V_44 ) ;
else
F_289 ( V_44 ) ;
}
V_44 = F_286 ( & V_282 [ 0 ] ) ;
} while ( V_44 );
V_189 -> V_281 = NULL ;
V_182:
return V_112 ;
}
T_6 F_290 ( struct V_44 * V_44 )
{
if ( F_291 ( V_44 ) ) {
unsigned int V_106 ;
if ( F_20 ( F_267 ( V_44 ) == V_272 ) )
V_106 = F_292 ( V_44 -> V_249 -> V_260 ) ;
else
V_106 = F_223 ( V_44 ) ;
if ( F_293 ( F_267 ( V_44 ) ) ) {
F_294 ( V_286 , V_106 ) ;
} else {
F_295 ( V_44 -> V_50 . V_51 ) ;
F_294 ( V_287 , V_106 ) ;
}
if ( F_20 ( V_288 ) ) {
char V_247 [ V_248 ] ;
F_25 ( V_289 L_14 ,
V_189 -> V_290 , F_296 ( V_189 ) ,
F_293 ( F_267 ( V_44 ) ) ? L_15 : L_16 ,
( unsigned long long ) V_44 -> V_50 . V_214 ,
F_256 ( V_44 , V_247 ) , V_106 ) ;
}
}
return F_283 ( V_44 ) ;
}
static int F_297 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( F_26 ( V_17 ) > F_298 ( V_6 , F_299 ( V_17 ) ) ) {
F_25 ( V_39 L_17 , V_40 ) ;
return - V_37 ;
}
F_300 ( V_17 ) ;
if ( V_17 -> V_217 > F_301 ( V_6 ) ) {
F_25 ( V_39 L_18 , V_40 ) ;
return - V_37 ;
}
return 0 ;
}
T_1 F_302 ( struct V_11 * V_6 , struct V_16 * V_17 )
{
unsigned long V_71 ;
int V_197 = V_291 ;
if ( F_297 ( V_6 , V_17 ) )
return V_34 ;
if ( V_17 -> V_42 &&
F_261 ( & V_17 -> V_42 -> V_206 , F_28 ( V_17 ) ) )
return V_34 ;
if ( V_6 -> V_62 ) {
if ( F_163 ( V_6 ) )
F_195 ( V_17 , true ) ;
F_303 ( V_17 ) ;
return V_269 ;
}
F_58 ( V_6 -> V_60 , V_71 ) ;
if ( F_20 ( F_106 ( V_6 ) ) ) {
F_59 ( V_6 -> V_60 , V_71 ) ;
return V_34 ;
}
F_191 ( F_192 ( V_17 ) ) ;
if ( F_160 ( V_17 -> V_55 ) )
V_197 = V_237 ;
F_194 ( V_6 , V_17 , V_197 ) ;
if ( V_197 == V_237 )
F_32 ( V_6 ) ;
F_59 ( V_6 -> V_60 , V_71 ) ;
return V_269 ;
}
unsigned int F_304 ( const struct V_16 * V_17 )
{
unsigned int V_209 = V_17 -> V_55 & V_211 ;
unsigned int V_252 = 0 ;
struct V_44 * V_44 ;
if ( ! ( V_17 -> V_47 & V_292 ) )
return F_28 ( V_17 ) ;
for ( V_44 = V_17 -> V_44 ; V_44 ; V_44 = V_44 -> V_212 ) {
if ( ( V_44 -> V_210 & V_209 ) != V_209 )
break;
V_252 += V_44 -> V_50 . V_51 ;
}
F_191 ( F_28 ( V_17 ) && ! V_252 ) ;
return V_252 ;
}
void F_305 ( struct V_16 * V_38 , unsigned int V_252 )
{
if ( F_306 ( V_38 ) ) {
const int V_293 = F_307 ( V_38 ) ;
struct V_198 * V_29 ;
int V_20 ;
V_20 = F_308 () ;
V_29 = V_38 -> V_29 ;
F_309 ( V_20 , V_29 , V_294 [ V_293 ] , V_252 >> 9 ) ;
F_310 () ;
}
}
void F_311 ( struct V_16 * V_38 )
{
if ( F_306 ( V_38 ) && ! ( V_38 -> V_47 & V_52 ) ) {
unsigned long V_295 = V_28 - V_38 -> V_27 ;
const int V_293 = F_307 ( V_38 ) ;
struct V_198 * V_29 ;
int V_20 ;
V_20 = F_308 () ;
V_29 = V_38 -> V_29 ;
F_312 ( V_20 , V_29 , V_296 [ V_293 ] ) ;
F_309 ( V_20 , V_29 , V_297 [ V_293 ] , V_295 ) ;
F_199 ( V_38 -> V_6 , V_20 , V_29 ) ;
F_313 ( V_38 -> V_6 , V_29 , V_293 ) ;
F_314 ( V_29 ) ;
F_310 () ;
}
}
static struct V_16 * F_315 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
if ( V_6 -> V_184 && ( V_6 -> V_298 == V_299 ||
( V_6 -> V_298 != V_300 && ! ( V_17 -> V_47 & V_207 ) ) ) )
return NULL ;
else
return V_17 ;
}
static inline struct V_16 * F_315 ( struct V_11 * V_6 ,
struct V_16 * V_17 )
{
return V_17 ;
}
void F_195 ( struct V_16 * V_17 , bool V_301 )
{
struct V_198 * V_29 ;
int V_293 = F_307 ( V_17 ) ;
int V_20 ;
if ( ! F_306 ( V_17 ) )
return;
V_20 = F_308 () ;
if ( ! V_301 ) {
V_29 = V_17 -> V_29 ;
F_312 ( V_20 , V_29 , V_302 [ V_293 ] ) ;
} else {
V_29 = F_316 ( V_17 -> V_42 , F_18 ( V_17 ) ) ;
if ( ! F_317 ( V_29 ) ) {
V_29 = & V_17 -> V_42 -> V_206 ;
F_318 ( V_29 ) ;
}
F_199 ( V_17 -> V_6 , V_20 , V_29 ) ;
F_319 ( V_17 -> V_6 , V_29 , V_293 ) ;
V_17 -> V_29 = V_29 ;
}
F_310 () ;
}
struct V_16 * F_320 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
int V_112 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
while ( ( V_17 = F_321 ( V_6 ) ) != NULL ) {
V_17 = F_315 ( V_6 , V_17 ) ;
if ( ! V_17 )
break;
if ( ! ( V_17 -> V_47 & V_303 ) ) {
if ( V_17 -> V_47 & V_304 )
F_322 ( V_6 , V_17 ) ;
V_17 -> V_47 |= V_303 ;
F_323 ( V_6 , V_17 ) ;
}
if ( ! V_6 -> V_305 || V_6 -> V_305 == V_17 ) {
V_6 -> V_306 = F_324 ( V_17 ) ;
V_6 -> V_305 = NULL ;
}
if ( V_17 -> V_47 & V_307 )
break;
if ( V_6 -> V_308 && F_28 ( V_17 ) ) {
V_17 -> V_217 ++ ;
}
if ( ! V_6 -> V_309 )
break;
V_112 = V_6 -> V_309 ( V_6 , V_17 ) ;
if ( V_112 == V_310 ) {
break;
} else if ( V_112 == V_311 ) {
if ( V_6 -> V_308 && F_28 ( V_17 ) &&
! ( V_17 -> V_47 & V_307 ) ) {
-- V_17 -> V_217 ;
}
V_17 = NULL ;
break;
} else if ( V_112 == V_312 || V_112 == V_313 ) {
V_17 -> V_47 |= V_48 ;
F_325 ( V_17 ) ;
F_326 ( V_17 , V_112 == V_313 ?
V_314 : V_34 ) ;
} else {
F_25 ( V_39 L_19 , V_40 , V_112 ) ;
break;
}
}
return V_17 ;
}
static void F_327 ( struct V_16 * V_17 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
F_191 ( F_65 ( & V_17 -> V_18 ) ) ;
F_191 ( F_209 ( V_17 ) ) ;
F_328 ( & V_17 -> V_18 ) ;
if ( F_329 ( V_17 ) ) {
V_6 -> V_81 [ F_330 ( V_17 ) ] ++ ;
F_331 ( V_17 ) ;
}
}
void F_325 ( struct V_16 * V_38 )
{
F_35 ( V_38 -> V_6 -> V_60 ) ;
F_15 ( V_38 -> V_6 -> V_62 ) ;
F_327 ( V_38 ) ;
if ( F_249 ( V_315 , & V_38 -> V_6 -> V_143 ) ) {
F_332 ( & V_38 -> V_195 , F_26 ( V_38 ) ) ;
V_38 -> V_47 |= V_316 ;
F_333 ( V_38 -> V_6 -> V_194 , & V_38 -> V_195 ) ;
}
F_191 ( F_249 ( V_317 , & V_38 -> V_318 ) ) ;
F_334 ( V_38 ) ;
}
struct V_16 * F_335 ( struct V_11 * V_6 )
{
struct V_16 * V_17 ;
F_35 ( V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
V_17 = F_320 ( V_6 ) ;
if ( V_17 )
F_325 ( V_17 ) ;
return V_17 ;
}
bool F_336 ( struct V_16 * V_38 , T_1 error ,
unsigned int V_319 )
{
int V_320 ;
F_337 ( V_38 , F_14 ( error ) , V_319 ) ;
if ( ! V_38 -> V_44 )
return false ;
if ( F_20 ( error && ! F_338 ( V_38 ) &&
! ( V_38 -> V_47 & V_48 ) ) )
F_16 ( V_38 , error ) ;
F_305 ( V_38 , V_319 ) ;
V_320 = 0 ;
while ( V_38 -> V_44 ) {
struct V_44 * V_44 = V_38 -> V_44 ;
unsigned V_321 = F_339 ( V_44 -> V_50 . V_51 , V_319 ) ;
if ( V_321 == V_44 -> V_50 . V_51 )
V_38 -> V_44 = V_44 -> V_212 ;
F_340 ( V_44 , V_279 ) ;
F_19 ( V_38 , V_44 , V_321 , error ) ;
V_320 += V_321 ;
V_319 -= V_321 ;
if ( ! V_319 )
break;
}
if ( ! V_38 -> V_44 ) {
V_38 -> V_190 = 0 ;
return false ;
}
V_38 -> V_190 -= V_320 ;
if ( ! F_338 ( V_38 ) )
V_38 -> V_21 += V_320 >> 9 ;
if ( V_38 -> V_47 & V_292 ) {
V_38 -> V_55 &= ~ V_211 ;
V_38 -> V_55 |= V_38 -> V_44 -> V_210 & V_211 ;
}
if ( ! ( V_38 -> V_47 & V_322 ) ) {
if ( F_28 ( V_38 ) < F_341 ( V_38 ) ) {
F_24 ( V_38 , L_20 ) ;
V_38 -> V_190 = F_341 ( V_38 ) ;
}
F_300 ( V_38 ) ;
}
return true ;
}
static bool F_342 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_319 ,
unsigned int V_323 )
{
if ( F_336 ( V_17 , error , V_319 ) )
return true ;
if ( F_20 ( F_343 ( V_17 ) ) &&
F_336 ( V_17 -> V_324 , error , V_323 ) )
return true ;
if ( F_344 ( V_17 -> V_6 ) )
F_345 ( V_17 -> V_42 ) ;
return false ;
}
void F_346 ( struct V_16 * V_38 )
{
struct V_11 * V_6 = V_38 -> V_6 ;
V_38 -> V_47 &= ~ V_307 ;
if ( V_6 -> V_325 )
V_6 -> V_325 ( V_6 , V_38 ) ;
}
void F_347 ( struct V_16 * V_38 , T_1 error )
{
struct V_11 * V_6 = V_38 -> V_6 ;
F_35 ( V_38 -> V_6 -> V_60 ) ;
F_15 ( V_6 -> V_62 ) ;
if ( V_38 -> V_47 & V_316 )
F_348 ( V_38 ) ;
if ( V_38 -> V_47 & V_196 )
F_190 ( V_6 , V_38 ) ;
F_191 ( F_192 ( V_38 ) ) ;
if ( F_20 ( V_326 ) && ! F_338 ( V_38 ) )
F_349 ( V_38 -> V_6 -> V_8 ) ;
F_186 ( V_38 ) ;
if ( V_38 -> V_47 & V_307 )
F_346 ( V_38 ) ;
F_311 ( V_38 ) ;
if ( V_38 -> V_264 ) {
F_207 ( V_38 -> V_6 -> V_194 , & V_38 -> V_195 ) ;
V_38 -> V_264 ( V_38 , error ) ;
} else {
if ( F_343 ( V_38 ) )
F_204 ( V_38 -> V_324 -> V_6 , V_38 -> V_324 ) ;
F_204 ( V_6 , V_38 ) ;
}
}
static bool F_350 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_319 , unsigned int V_323 )
{
struct V_11 * V_6 = V_17 -> V_6 ;
unsigned long V_71 ;
F_15 ( V_6 -> V_62 ) ;
if ( F_342 ( V_17 , error , V_319 , V_323 ) )
return true ;
F_58 ( V_6 -> V_60 , V_71 ) ;
F_347 ( V_17 , error ) ;
F_59 ( V_6 -> V_60 , V_71 ) ;
return false ;
}
static bool F_351 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_319 , unsigned int V_323 )
{
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
if ( F_342 ( V_17 , error , V_319 , V_323 ) )
return true ;
F_347 ( V_17 , error ) ;
return false ;
}
bool F_352 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_319 )
{
F_15 ( V_17 -> V_6 -> V_62 ) ;
return F_350 ( V_17 , error , V_319 , 0 ) ;
}
void F_353 ( struct V_16 * V_17 , T_1 error )
{
bool V_327 ;
unsigned int V_323 = 0 ;
if ( F_20 ( F_343 ( V_17 ) ) )
V_323 = F_28 ( V_17 -> V_324 ) ;
V_327 = F_350 ( V_17 , error , F_28 ( V_17 ) , V_323 ) ;
F_191 ( V_327 ) ;
}
bool F_354 ( struct V_16 * V_17 , T_1 error ,
unsigned int V_319 )
{
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
return F_351 ( V_17 , error , V_319 , 0 ) ;
}
void F_326 ( struct V_16 * V_17 , T_1 error )
{
bool V_327 ;
unsigned int V_323 = 0 ;
F_35 ( V_17 -> V_6 -> V_60 ) ;
F_15 ( V_17 -> V_6 -> V_62 ) ;
if ( F_20 ( F_343 ( V_17 ) ) )
V_323 = F_28 ( V_17 -> V_324 ) ;
V_327 = F_351 ( V_17 , error , F_28 ( V_17 ) , V_323 ) ;
F_191 ( V_327 ) ;
}
bool F_355 ( struct V_16 * V_17 , T_1 error )
{
return F_354 ( V_17 , error , F_341 ( V_17 ) ) ;
}
void F_235 ( struct V_11 * V_6 , struct V_16 * V_17 ,
struct V_44 * V_44 )
{
if ( F_291 ( V_44 ) )
V_17 -> V_217 = F_356 ( V_6 , V_44 ) ;
V_17 -> V_190 = V_44 -> V_50 . V_51 ;
V_17 -> V_44 = V_17 -> V_56 = V_44 ;
if ( V_44 -> V_249 )
V_17 -> V_42 = V_44 -> V_249 ;
}
void F_357 ( struct V_16 * V_17 )
{
struct V_328 V_329 ;
struct V_330 V_331 ;
F_358 (bvec, rq, iter)
F_359 ( V_331 . V_332 ) ;
}
int F_360 ( struct V_11 * V_6 )
{
if ( V_6 -> V_333 )
return V_6 -> V_333 ( V_6 ) ;
return 0 ;
}
void F_361 ( struct V_16 * V_17 )
{
struct V_44 * V_44 ;
while ( ( V_44 = V_17 -> V_44 ) != NULL ) {
V_17 -> V_44 = V_44 -> V_212 ;
F_362 ( V_44 ) ;
}
}
static void F_363 ( struct V_16 * V_334 , struct V_16 * V_335 )
{
V_334 -> V_20 = V_335 -> V_20 ;
V_334 -> V_21 = F_18 ( V_335 ) ;
V_334 -> V_190 = F_28 ( V_335 ) ;
V_334 -> V_217 = V_335 -> V_217 ;
V_334 -> V_213 = V_335 -> V_213 ;
V_334 -> V_336 = V_335 -> V_336 ;
}
int F_364 ( struct V_16 * V_17 , struct V_16 * V_337 ,
struct V_338 * V_339 , T_3 V_98 ,
int (* F_365)( struct V_44 * , struct V_44 * , void * ) ,
void * V_99 )
{
struct V_44 * V_44 , * V_340 ;
if ( ! V_339 )
V_339 = V_341 ;
F_366 (bio_src, rq_src) {
V_44 = F_367 ( V_340 , V_98 , V_339 ) ;
if ( ! V_44 )
goto V_342;
if ( F_365 && F_365 ( V_44 , V_340 , V_99 ) )
goto V_342;
if ( V_17 -> V_44 ) {
V_17 -> V_56 -> V_212 = V_44 ;
V_17 -> V_56 = V_44 ;
} else
V_17 -> V_44 = V_17 -> V_56 = V_44 ;
}
F_363 ( V_17 , V_337 ) ;
return 0 ;
V_342:
if ( V_44 )
F_362 ( V_44 ) ;
F_361 ( V_17 ) ;
return - V_109 ;
}
int F_111 ( struct V_57 * V_58 )
{
return F_368 ( V_63 , V_58 ) ;
}
int F_369 ( int V_20 , struct V_57 * V_58 )
{
return F_370 ( V_20 , V_63 , V_58 ) ;
}
int F_371 ( int V_20 , struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_372 ( V_20 , V_63 , V_344 , V_345 ) ;
}
int F_373 ( struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_38 ( V_63 , V_344 , V_345 ) ;
}
int F_374 ( int V_20 , struct V_343 * V_344 ,
unsigned long V_345 )
{
return F_375 ( V_20 , V_63 , V_344 , V_345 ) ;
}
void F_376 ( struct V_220 * V_221 )
{
struct V_346 * V_347 = V_189 ;
if ( V_347 -> V_221 )
return;
F_8 ( & V_221 -> V_225 ) ;
F_8 ( & V_221 -> V_224 ) ;
F_8 ( & V_221 -> V_348 ) ;
V_347 -> V_221 = V_221 ;
}
static int F_377 ( void * V_349 , struct V_222 * V_350 , struct V_222 * V_247 )
{
struct V_16 * V_351 = F_30 ( V_350 , struct V_16 , V_18 ) ;
struct V_16 * V_352 = F_30 ( V_247 , struct V_16 , V_18 ) ;
return ! ( V_351 -> V_6 < V_352 -> V_6 ||
( V_351 -> V_6 == V_352 -> V_6 && F_18 ( V_351 ) < F_18 ( V_352 ) ) ) ;
}
static void F_378 ( struct V_11 * V_6 , unsigned int V_353 ,
bool V_354 )
__releases( V_6 -> V_60 )
{
F_35 ( V_6 -> V_60 ) ;
F_379 ( V_6 , V_353 , ! V_354 ) ;
if ( V_354 )
F_42 ( V_6 ) ;
else
F_32 ( V_6 ) ;
F_380 ( V_6 -> V_60 ) ;
}
static void F_381 ( struct V_220 * V_221 , bool V_354 )
{
F_382 ( V_355 ) ;
while ( ! F_65 ( & V_221 -> V_348 ) ) {
F_383 ( & V_221 -> V_348 , & V_355 ) ;
while ( ! F_65 ( & V_355 ) ) {
struct V_356 * V_357 = F_384 ( & V_355 ,
struct V_356 ,
V_225 ) ;
F_385 ( & V_357 -> V_225 ) ;
V_357 -> V_358 ( V_357 , V_354 ) ;
}
}
}
struct V_356 * F_386 ( T_9 V_359 , void * V_99 ,
int V_360 )
{
struct V_220 * V_221 = V_189 -> V_221 ;
struct V_356 * V_357 ;
if ( ! V_221 )
return NULL ;
F_231 (cb, &plug->cb_list, list)
if ( V_357 -> V_358 == V_359 && V_357 -> V_99 == V_99 )
return V_357 ;
F_191 ( V_360 < sizeof( * V_357 ) ) ;
V_357 = F_387 ( V_360 , V_278 ) ;
if ( V_357 ) {
V_357 -> V_99 = V_99 ;
V_357 -> V_358 = V_359 ;
F_388 ( & V_357 -> V_225 , & V_221 -> V_348 ) ;
}
return V_357 ;
}
void F_253 ( struct V_220 * V_221 , bool V_354 )
{
struct V_11 * V_6 ;
unsigned long V_71 ;
struct V_16 * V_17 ;
F_382 ( V_225 ) ;
unsigned int V_353 ;
F_381 ( V_221 , V_354 ) ;
if ( ! F_65 ( & V_221 -> V_224 ) )
F_389 ( V_221 , V_354 ) ;
if ( F_65 ( & V_221 -> V_225 ) )
return;
F_383 ( & V_221 -> V_225 , & V_225 ) ;
F_390 ( NULL , & V_225 , F_377 ) ;
V_6 = NULL ;
V_353 = 0 ;
F_391 ( V_71 ) ;
while ( ! F_65 ( & V_225 ) ) {
V_17 = F_252 ( V_225 . V_361 ) ;
F_328 ( & V_17 -> V_18 ) ;
F_191 ( ! V_17 -> V_6 ) ;
if ( V_17 -> V_6 != V_6 ) {
if ( V_6 )
F_378 ( V_6 , V_353 , V_354 ) ;
V_6 = V_17 -> V_6 ;
V_353 = 0 ;
F_392 ( V_6 -> V_60 ) ;
}
if ( F_20 ( F_106 ( V_6 ) ) ) {
F_326 ( V_17 , V_34 ) ;
continue;
}
if ( F_160 ( V_17 -> V_55 ) )
F_196 ( V_6 , V_17 , V_237 ) ;
else
F_196 ( V_6 , V_17 , V_362 ) ;
V_353 ++ ;
}
if ( V_6 )
F_378 ( V_6 , V_353 , V_354 ) ;
F_393 ( V_71 ) ;
}
void F_394 ( struct V_220 * V_221 )
{
if ( V_221 != V_189 -> V_221 )
return;
F_253 ( V_221 , false ) ;
V_189 -> V_221 = NULL ;
}
void F_395 ( struct V_11 * V_6 , struct V_363 * V_184 )
{
if ( V_6 -> V_62 )
return;
V_6 -> V_184 = V_184 ;
V_6 -> V_298 = V_300 ;
F_396 ( V_6 -> V_184 , - 1 ) ;
F_397 ( V_6 -> V_184 ) ;
}
int F_398 ( struct V_11 * V_6 )
{
int V_112 = 0 ;
if ( ! V_6 -> V_184 )
return V_112 ;
F_31 ( V_6 -> V_60 ) ;
if ( V_6 -> V_208 ) {
V_112 = - V_113 ;
F_203 ( V_6 -> V_184 ) ;
} else {
V_6 -> V_298 = V_364 ;
}
F_33 ( V_6 -> V_60 ) ;
return V_112 ;
}
void F_399 ( struct V_11 * V_6 , int V_365 )
{
if ( ! V_6 -> V_184 )
return;
F_31 ( V_6 -> V_60 ) ;
if ( ! V_365 ) {
V_6 -> V_298 = V_299 ;
} else {
V_6 -> V_298 = V_300 ;
F_203 ( V_6 -> V_184 ) ;
}
F_33 ( V_6 -> V_60 ) ;
}
void F_400 ( struct V_11 * V_6 )
{
if ( ! V_6 -> V_184 )
return;
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_298 = V_366 ;
F_33 ( V_6 -> V_60 ) ;
}
void F_401 ( struct V_11 * V_6 , int V_365 )
{
if ( ! V_6 -> V_184 )
return;
F_31 ( V_6 -> V_60 ) ;
if ( ! V_365 ) {
V_6 -> V_298 = V_300 ;
F_32 ( V_6 ) ;
F_203 ( V_6 -> V_184 ) ;
F_402 ( V_6 -> V_184 ) ;
} else {
V_6 -> V_298 = V_299 ;
}
F_33 ( V_6 -> V_60 ) ;
}
void F_403 ( struct V_11 * V_6 )
{
F_31 ( V_6 -> V_60 ) ;
V_6 -> V_298 = V_300 ;
F_203 ( V_6 -> V_184 ) ;
F_402 ( V_6 -> V_184 ) ;
F_33 ( V_6 -> V_60 ) ;
}
int T_7 F_404 ( void )
{
F_405 ( V_367 >= ( 1 << V_368 ) ) ;
F_405 ( V_368 + V_369 > 8 *
F_406 ( struct V_16 , V_55 ) ) ;
F_405 ( V_368 + V_369 > 8 *
F_406 ( struct V_44 , V_210 ) ) ;
V_63 = F_407 ( L_21 ,
V_370 | V_371 , 0 ) ;
if ( ! V_63 )
F_408 ( L_22 ) ;
V_100 = F_409 ( L_23 ,
sizeof( struct V_16 ) , 0 , V_372 , NULL ) ;
V_121 = F_409 ( L_24 ,
sizeof( struct V_11 ) , 0 , V_372 , NULL ) ;
#ifdef F_410
V_373 = F_411 ( L_6 , NULL ) ;
#endif
return 0 ;
}
