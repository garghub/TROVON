static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_7 ;
if ( ! F_3 ( V_2 ) )
return;
V_7 = F_4 () ;
if ( ! V_3 ) {
V_5 = V_2 -> V_5 ;
F_5 ( V_7 , V_5 , V_8 [ V_6 ] ) ;
} else {
V_5 = F_6 ( V_2 -> V_9 , F_7 ( V_2 ) ) ;
if ( ! F_8 ( V_5 ) ) {
V_5 = & V_2 -> V_9 -> V_10 ;
F_9 ( V_5 ) ;
}
F_10 ( V_7 , V_5 ) ;
F_11 ( V_5 , V_6 ) ;
V_2 -> V_5 = V_5 ;
}
F_12 () ;
}
void F_13 ( struct V_11 * V_12 )
{
int V_13 ;
V_13 = V_12 -> V_14 - ( V_12 -> V_14 / 8 ) + 1 ;
if ( V_13 > V_12 -> V_14 )
V_13 = V_12 -> V_14 ;
V_12 -> V_15 = V_13 ;
V_13 = V_12 -> V_14 - ( V_12 -> V_14 / 8 ) - ( V_12 -> V_14 / 16 ) - 1 ;
if ( V_13 < 1 )
V_13 = 1 ;
V_12 -> V_16 = V_13 ;
}
struct V_17 * F_14 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
struct V_11 * V_12 = F_15 ( V_19 ) ;
if ( V_12 )
V_20 = & V_12 -> V_17 ;
return V_20 ;
}
void F_16 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_17 ( & V_2 -> V_21 ) ;
F_17 ( & V_2 -> V_22 ) ;
V_2 -> V_7 = - 1 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = ( V_24 ) - 1 ;
F_18 ( & V_2 -> V_25 ) ;
F_19 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = V_2 -> V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = - 1 ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_34 ;
F_20 ( V_2 ) ;
V_2 -> V_5 = NULL ;
}
static void F_21 ( struct V_1 * V_2 , struct V_35 * V_35 ,
unsigned int V_36 , int error )
{
if ( error )
F_22 ( V_37 , & V_35 -> V_38 ) ;
else if ( ! F_23 ( V_37 , & V_35 -> V_38 ) )
error = - V_39 ;
if ( F_24 ( V_36 > V_35 -> V_40 ) ) {
F_25 ( V_41 L_1 ,
V_42 , V_36 , V_35 -> V_40 ) ;
V_36 = V_35 -> V_40 ;
}
if ( F_24 ( V_2 -> V_43 & V_44 ) )
F_26 ( V_45 , & V_35 -> V_38 ) ;
V_35 -> V_40 -= V_36 ;
V_35 -> V_46 += ( V_36 >> 9 ) ;
if ( F_27 ( V_35 ) )
F_28 ( V_35 , V_36 ) ;
if ( V_35 -> V_40 == 0 && ! ( V_2 -> V_43 & V_47 ) )
F_29 ( V_35 , error ) ;
}
void F_30 ( struct V_1 * V_2 , char * V_48 )
{
int V_49 ;
F_25 ( V_50 L_2 , V_48 ,
V_2 -> V_9 ? V_2 -> V_9 -> V_51 : L_3 , V_2 -> V_52 ,
V_2 -> V_43 ) ;
F_25 ( V_50 L_4 ,
( unsigned long long ) F_7 ( V_2 ) ,
F_31 ( V_2 ) , F_32 ( V_2 ) ) ;
F_25 ( V_50 L_5 ,
V_2 -> V_35 , V_2 -> V_53 , V_2 -> V_54 , F_33 ( V_2 ) ) ;
if ( V_2 -> V_52 == V_55 ) {
F_25 ( V_50 L_6 ) ;
for ( V_49 = 0 ; V_49 < V_30 ; V_49 ++ )
F_25 ( L_7 , V_2 -> V_27 [ V_49 ] ) ;
F_25 ( L_8 ) ;
}
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_11 * V_12 ;
V_12 = F_35 ( V_57 , struct V_11 , V_58 . V_57 ) ;
F_36 ( V_12 -> V_59 ) ;
F_37 ( V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_39 ( struct V_11 * V_12 , unsigned long V_60 )
{
F_40 ( V_61 , & V_12 -> V_58 ,
F_41 ( V_60 ) ) ;
}
void F_42 ( struct V_11 * V_12 )
{
F_43 ( ! F_44 () ) ;
F_45 ( V_62 , V_12 ) ;
F_37 ( V_12 ) ;
}
void F_46 ( struct V_11 * V_12 )
{
F_47 ( & V_12 -> V_58 ) ;
F_48 ( V_62 , V_12 ) ;
}
void F_49 ( struct V_11 * V_12 )
{
F_50 ( & V_12 -> V_63 ) ;
F_51 ( & V_12 -> V_58 ) ;
}
void F_37 ( struct V_11 * V_12 )
{
if ( F_24 ( F_52 ( V_12 ) ) )
return;
V_12 -> V_64 ( V_12 ) ;
}
void F_53 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_52 ( V_12 ) ) ) {
F_47 ( & V_12 -> V_58 ) ;
F_40 ( V_61 , & V_12 -> V_58 , 0 ) ;
}
}
void F_55 ( struct V_11 * V_12 )
{
unsigned long V_65 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
F_59 ( & V_12 -> V_66 ) ;
}
void F_60 ( struct V_11 * V_12 , bool V_67 )
{
int V_68 ;
while ( true ) {
bool V_69 = false ;
F_36 ( V_12 -> V_59 ) ;
if ( V_12 -> V_70 )
F_61 ( V_12 ) ;
F_62 ( V_12 ) ;
if ( ! F_63 ( & V_12 -> V_71 ) && V_12 -> V_64 )
F_37 ( V_12 ) ;
V_69 |= V_12 -> V_2 . V_72 ;
if ( V_67 ) {
V_69 |= ! F_63 ( & V_12 -> V_71 ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_69 |= V_12 -> V_2 . V_73 [ V_68 ] ;
V_69 |= V_12 -> V_74 [ V_68 ] ;
V_69 |= ! F_63 ( & V_12 -> V_75 [ V_68 ] ) ;
}
}
F_38 ( V_12 -> V_59 ) ;
if ( ! V_69 )
break;
F_64 ( 10 ) ;
}
if ( V_12 -> V_64 ) {
F_36 ( V_12 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < F_65 ( V_12 -> V_2 . V_76 ) ; V_68 ++ )
F_66 ( & V_12 -> V_2 . V_76 [ V_68 ] ) ;
F_38 ( V_12 -> V_59 ) ;
}
}
void F_67 ( struct V_11 * V_12 )
{
bool V_69 ;
F_36 ( V_12 -> V_59 ) ;
V_69 = ! V_12 -> V_77 ++ ;
F_48 ( V_78 , V_12 ) ;
F_38 ( V_12 -> V_59 ) ;
if ( V_69 ) {
F_60 ( V_12 , false ) ;
F_68 () ;
}
}
void F_69 ( struct V_11 * V_12 )
{
F_36 ( V_12 -> V_59 ) ;
if ( ! -- V_12 -> V_77 )
F_45 ( V_78 , V_12 ) ;
F_70 ( V_12 -> V_77 < 0 ) ;
F_38 ( V_12 -> V_59 ) ;
}
void F_71 ( struct V_11 * V_12 )
{
T_1 * V_79 = V_12 -> V_59 ;
F_72 ( & V_12 -> V_80 ) ;
F_73 ( V_81 , V_12 ) ;
F_36 ( V_79 ) ;
V_12 -> V_77 ++ ;
F_48 ( V_78 , V_12 ) ;
F_48 ( V_82 , V_12 ) ;
F_48 ( V_83 , V_12 ) ;
F_48 ( V_81 , V_12 ) ;
F_38 ( V_79 ) ;
F_74 ( & V_12 -> V_80 ) ;
F_60 ( V_12 , true ) ;
F_50 ( & V_12 -> V_17 . V_84 ) ;
F_49 ( V_12 ) ;
F_36 ( V_79 ) ;
if ( V_12 -> V_59 != & V_12 -> V_85 )
V_12 -> V_59 = & V_12 -> V_85 ;
F_38 ( V_79 ) ;
F_58 ( V_12 ) ;
}
static int F_75 ( struct V_11 * V_12 )
{
struct V_86 * V_87 = & V_12 -> V_2 ;
if ( F_24 ( V_87 -> V_88 ) )
return 0 ;
V_87 -> V_73 [ V_89 ] = V_87 -> V_73 [ V_90 ] = 0 ;
V_87 -> V_91 [ V_89 ] = V_87 -> V_91 [ V_90 ] = 0 ;
V_87 -> V_72 = 0 ;
F_76 ( & V_87 -> V_76 [ V_89 ] ) ;
F_76 ( & V_87 -> V_76 [ V_90 ] ) ;
V_87 -> V_88 = F_77 ( V_92 , V_93 ,
V_94 , V_95 , V_12 -> V_96 ) ;
if ( ! V_87 -> V_88 )
return - V_97 ;
return 0 ;
}
struct V_11 * F_78 ( T_2 V_98 )
{
return F_79 ( V_98 , - 1 ) ;
}
struct V_11 * F_79 ( T_2 V_98 , int V_99 )
{
struct V_11 * V_12 ;
int V_100 ;
V_12 = F_80 ( V_101 ,
V_98 | V_102 , V_99 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_103 = F_81 ( & V_104 , 0 , 0 , V_98 ) ;
if ( V_12 -> V_103 < 0 )
goto V_105;
V_12 -> V_17 . V_106 =
( V_107 * 1024 ) / V_108 ;
V_12 -> V_17 . V_109 = 0 ;
V_12 -> V_17 . V_110 = V_111 ;
V_12 -> V_17 . V_112 = L_9 ;
V_12 -> V_96 = V_99 ;
V_100 = F_82 ( & V_12 -> V_17 ) ;
if ( V_100 )
goto V_113;
F_83 ( & V_12 -> V_17 . V_84 ,
V_114 , ( unsigned long ) V_12 ) ;
F_83 ( & V_12 -> V_63 , V_115 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_71 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_116 ) ;
#ifdef F_84
F_17 ( & V_12 -> V_117 ) ;
#endif
F_17 ( & V_12 -> V_75 [ 0 ] ) ;
F_17 ( & V_12 -> V_75 [ 1 ] ) ;
F_17 ( & V_12 -> V_118 ) ;
F_85 ( & V_12 -> V_58 , F_34 ) ;
F_86 ( & V_12 -> V_66 , & V_119 ) ;
F_87 ( & V_12 -> V_80 ) ;
F_88 ( & V_12 -> V_85 ) ;
V_12 -> V_59 = & V_12 -> V_85 ;
V_12 -> V_77 = 1 ;
F_89 ( V_78 , & V_12 -> V_120 ) ;
if ( F_90 ( V_12 ) )
goto V_113;
return V_12 ;
V_113:
F_91 ( & V_104 , V_12 -> V_103 ) ;
V_105:
F_92 ( V_101 , V_12 ) ;
return NULL ;
}
struct V_11 * F_93 ( T_3 * V_121 , T_1 * V_79 )
{
return F_94 ( V_121 , V_79 , - 1 ) ;
}
struct V_11 *
F_94 ( T_3 * V_121 , T_1 * V_79 , int V_99 )
{
struct V_11 * V_122 , * V_12 ;
V_122 = F_79 ( V_123 , V_99 ) ;
if ( ! V_122 )
return NULL ;
V_12 = F_95 ( V_122 , V_121 , V_79 ) ;
if ( ! V_12 )
F_71 ( V_122 ) ;
return V_12 ;
}
struct V_11 *
F_95 ( struct V_11 * V_12 , T_3 * V_121 ,
T_1 * V_79 )
{
if ( ! V_12 )
return NULL ;
if ( F_75 ( V_12 ) )
return NULL ;
V_12 -> V_64 = V_121 ;
V_12 -> V_124 = NULL ;
V_12 -> V_125 = NULL ;
V_12 -> V_120 = V_126 ;
if ( V_79 )
V_12 -> V_59 = V_79 ;
F_96 ( V_12 , V_127 ) ;
V_12 -> V_128 = V_129 ;
if ( F_97 ( V_12 , NULL ) )
return NULL ;
F_13 ( V_12 ) ;
F_69 ( V_12 ) ;
return V_12 ;
}
bool F_98 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_99 ( V_12 ) ) ) {
F_100 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_101 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_130 ) {
F_102 ( V_12 , V_2 ) ;
if ( V_2 -> V_131 . V_132 )
F_103 ( V_2 -> V_131 . V_132 -> V_133 ) ;
}
F_104 ( V_2 , V_12 -> V_2 . V_88 ) ;
}
static inline int F_105 ( struct V_11 * V_12 , struct V_134 * V_133 )
{
if ( ! V_133 )
return 0 ;
return V_133 -> V_135 == V_12 -> V_136 ||
( V_133 -> V_135 > 0
&& F_106 ( V_34 , V_133 -> V_137 + V_138 ) ) ;
}
static void F_107 ( struct V_11 * V_12 , struct V_134 * V_133 )
{
if ( ! V_133 || F_105 ( V_12 , V_133 ) )
return;
V_133 -> V_135 = V_12 -> V_136 ;
V_133 -> V_137 = V_34 ;
}
static void F_108 ( struct V_11 * V_12 , int V_139 )
{
struct V_86 * V_87 = & V_12 -> V_2 ;
if ( V_87 -> V_73 [ V_139 ] < F_109 ( V_12 ) )
F_110 ( V_12 , V_139 ) ;
if ( V_87 -> V_73 [ V_139 ] + 1 <= V_12 -> V_14 ) {
if ( F_111 ( & V_87 -> V_76 [ V_139 ] ) )
F_112 ( & V_87 -> V_76 [ V_139 ] ) ;
F_113 ( V_12 , V_139 ) ;
}
}
static void F_114 ( struct V_11 * V_12 , unsigned int V_65 )
{
struct V_86 * V_87 = & V_12 -> V_2 ;
int V_139 = F_115 ( V_65 ) ;
V_87 -> V_73 [ V_139 ] -- ;
if ( V_65 & V_130 )
V_87 -> V_72 -- ;
F_108 ( V_12 , V_139 ) ;
if ( F_24 ( V_87 -> V_91 [ V_139 ^ 1 ] ) )
F_108 ( V_12 , V_139 ^ 1 ) ;
}
static bool F_116 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_140 & ( V_141 | V_142 ) )
return false ;
return true ;
}
static struct V_134 * F_117 ( struct V_35 * V_35 )
{
#ifdef F_84
if ( V_35 && V_35 -> V_143 )
return V_35 -> V_143 ;
#endif
return V_144 -> V_134 ;
}
static struct V_1 * F_118 ( struct V_11 * V_12 , int V_145 ,
struct V_35 * V_35 , T_2 V_98 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 = & V_12 -> V_2 ;
struct V_146 * V_147 ;
struct V_134 * V_133 ;
struct V_148 * V_132 = NULL ;
const bool V_149 = F_115 ( V_145 ) != 0 ;
bool V_150 = false ;
int V_151 ;
V_152:
V_147 = V_12 -> V_70 -> type ;
V_133 = F_117 ( V_35 ) ;
if ( F_24 ( F_99 ( V_12 ) ) )
return NULL ;
V_151 = F_119 ( V_12 , V_145 ) ;
if ( V_151 == V_153 )
goto V_154;
if ( V_87 -> V_73 [ V_149 ] + 1 >= F_120 ( V_12 ) ) {
if ( V_87 -> V_73 [ V_149 ] + 1 >= V_12 -> V_14 ) {
if ( ! V_133 && ! V_150 ) {
F_38 ( V_12 -> V_59 ) ;
F_121 ( V_98 , V_12 -> V_96 ) ;
F_36 ( V_12 -> V_59 ) ;
V_150 = true ;
goto V_152;
}
if ( ! F_122 ( V_12 , V_149 ) ) {
F_107 ( V_12 , V_133 ) ;
F_123 ( V_12 , V_149 ) ;
} else {
if ( V_151 != V_155
&& ! F_105 ( V_12 , V_133 ) ) {
return NULL ;
}
}
}
F_124 ( V_12 , V_149 ) ;
}
if ( V_87 -> V_73 [ V_149 ] >= ( 3 * V_12 -> V_14 / 2 ) )
return NULL ;
V_87 -> V_73 [ V_149 ] ++ ;
V_87 -> V_91 [ V_149 ] = 0 ;
if ( F_116 ( V_35 ) && ! F_125 ( V_12 ) ) {
V_145 |= V_130 ;
V_87 -> V_72 ++ ;
if ( V_147 -> V_156 && V_133 )
V_132 = F_126 ( V_133 , V_12 ) ;
}
if ( F_127 ( V_12 ) )
V_145 |= V_157 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_128 ( V_12 -> V_2 . V_88 , V_98 ) ;
if ( ! V_2 )
goto V_158;
F_16 ( V_12 , V_2 ) ;
V_2 -> V_43 = V_145 | V_159 ;
if ( V_145 & V_130 ) {
if ( F_24 ( V_147 -> V_156 && ! V_132 ) ) {
F_121 ( V_98 , V_12 -> V_96 ) ;
V_133 = F_117 ( V_35 ) ;
if ( ! V_133 )
goto V_160;
V_132 = F_129 ( V_133 , V_12 , V_98 ) ;
if ( ! V_132 )
goto V_160;
}
V_2 -> V_131 . V_132 = V_132 ;
if ( F_24 ( F_130 ( V_12 , V_2 , V_35 , V_98 ) ) )
goto V_160;
if ( V_132 )
F_131 ( V_132 -> V_133 ) ;
}
V_161:
if ( F_105 ( V_12 , V_133 ) )
V_133 -> V_135 -- ;
F_132 ( V_12 , V_35 , V_145 & 1 ) ;
return V_2 ;
V_160:
F_133 ( V_162 L_10 ,
F_134 ( V_12 -> V_17 . V_163 ) ) ;
V_2 -> V_43 &= ~ V_130 ;
V_2 -> V_131 . V_132 = NULL ;
F_36 ( V_12 -> V_59 ) ;
V_87 -> V_72 -- ;
F_38 ( V_12 -> V_59 ) ;
goto V_161;
V_158:
F_36 ( V_12 -> V_59 ) ;
F_114 ( V_12 , V_145 ) ;
V_154:
if ( F_24 ( V_87 -> V_73 [ V_149 ] == 0 ) )
V_87 -> V_91 [ V_149 ] = 1 ;
return NULL ;
}
static struct V_1 * F_135 ( struct V_11 * V_12 , int V_145 ,
struct V_35 * V_35 )
{
const bool V_149 = F_115 ( V_145 ) != 0 ;
struct V_1 * V_2 ;
V_2 = F_118 ( V_12 , V_145 , V_35 , V_164 ) ;
while ( ! V_2 ) {
F_136 ( V_76 ) ;
struct V_86 * V_87 = & V_12 -> V_2 ;
if ( F_24 ( F_99 ( V_12 ) ) )
return NULL ;
F_137 ( & V_87 -> V_76 [ V_149 ] , & V_76 ,
V_165 ) ;
F_138 ( V_12 , V_35 , V_145 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_139 () ;
F_121 ( V_164 , V_12 -> V_96 ) ;
F_107 ( V_12 , V_144 -> V_134 ) ;
F_36 ( V_12 -> V_59 ) ;
F_140 ( & V_87 -> V_76 [ V_149 ] , & V_76 ) ;
V_2 = F_118 ( V_12 , V_145 , V_35 , V_164 ) ;
} ;
return V_2 ;
}
struct V_1 * F_141 ( struct V_11 * V_12 , int V_6 , T_2 V_98 )
{
struct V_1 * V_2 ;
F_142 ( V_6 != V_166 && V_6 != V_167 ) ;
F_36 ( V_12 -> V_59 ) ;
if ( V_98 & V_168 )
V_2 = F_135 ( V_12 , V_6 , NULL ) ;
else
V_2 = F_118 ( V_12 , V_6 , NULL , V_98 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_143 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_98 )
{
struct V_1 * V_2 = F_141 ( V_12 , F_144 ( V_35 ) , V_98 ) ;
if ( F_24 ( ! V_2 ) )
return F_145 ( - V_97 ) ;
F_146 (bio) {
struct V_35 * V_169 = V_35 ;
int V_20 ;
F_147 ( V_12 , & V_169 ) ;
V_20 = F_148 ( V_12 , V_2 , V_169 ) ;
if ( F_24 ( V_20 ) ) {
F_149 ( V_2 ) ;
return F_145 ( V_20 ) ;
}
}
return V_2 ;
}
void F_150 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_153 ( V_12 , V_2 ) ;
if ( F_154 ( V_2 ) )
F_155 ( V_12 , V_2 ) ;
F_142 ( F_156 ( V_2 ) ) ;
F_157 ( V_12 , V_2 ) ;
}
static void F_158 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_170 )
{
F_1 ( V_2 , 1 ) ;
F_159 ( V_12 , V_2 , V_170 ) ;
}
static void F_160 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_171 )
{
if ( V_171 == V_5 -> V_172 )
return;
if ( F_161 ( V_5 ) ) {
F_162 ( V_7 , V_5 , V_173 ,
F_161 ( V_5 ) * ( V_171 - V_5 -> V_172 ) ) ;
F_162 ( V_7 , V_5 , V_174 , ( V_171 - V_5 -> V_172 ) ) ;
}
V_5 -> V_172 = V_171 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_171 = V_34 ;
if ( V_5 -> V_175 )
F_160 ( V_7 , & F_163 ( V_5 ) -> V_10 , V_171 ) ;
F_160 ( V_7 , V_5 , V_171 ) ;
}
void F_164 ( struct V_11 * V_12 , struct V_1 * V_176 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_176 -> V_32 ) )
return;
F_165 ( V_12 , V_176 ) ;
F_43 ( V_176 -> V_35 != NULL ) ;
if ( V_176 -> V_43 & V_159 ) {
unsigned int V_65 = V_176 -> V_43 ;
F_142 ( ! F_63 ( & V_176 -> V_21 ) ) ;
F_142 ( ! F_166 ( & V_176 -> V_25 ) ) ;
F_101 ( V_12 , V_176 ) ;
F_114 ( V_12 , V_65 ) ;
}
}
void F_149 ( struct V_1 * V_176 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_176 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_164 ( V_12 , V_176 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_167 ( struct V_1 * V_2 , struct V_177 * V_177 ,
unsigned int V_178 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_179 -> V_180 = V_177 ;
V_35 -> V_179 -> V_181 = 0 ;
V_35 -> V_179 -> V_182 = V_178 ;
V_35 -> V_40 = V_178 ;
V_35 -> V_183 = 1 ;
V_35 -> V_184 = 1 ;
V_2 -> V_185 = V_2 -> V_186 = V_178 ;
V_2 -> V_187 = 1 ;
V_2 -> V_54 = F_168 ( V_35 ) ;
}
static bool F_169 ( struct V_11 * V_12 , struct V_1 * V_176 ,
struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_140 & V_189 ;
if ( ! F_170 ( V_12 , V_176 , V_35 ) )
return false ;
F_171 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_172 ( V_176 ) ;
V_176 -> V_53 -> V_190 = V_35 ;
V_176 -> V_53 = V_35 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_173 ( V_176 -> V_191 , F_174 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_175 ( struct V_11 * V_12 ,
struct V_1 * V_176 , struct V_35 * V_35 )
{
const int V_188 = V_35 -> V_140 & V_189 ;
if ( ! F_176 ( V_12 , V_176 , V_35 ) )
return false ;
F_177 ( V_12 , V_35 ) ;
if ( ( V_176 -> V_43 & V_189 ) != V_188 )
F_172 ( V_176 ) ;
V_35 -> V_190 = V_176 -> V_35 ;
V_176 -> V_35 = V_35 ;
V_176 -> V_54 = F_168 ( V_35 ) ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_185 += V_35 -> V_40 ;
V_176 -> V_191 = F_173 ( V_176 -> V_191 , F_174 ( V_35 ) ) ;
F_1 ( V_176 , 0 ) ;
return true ;
}
static bool F_178 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_192 )
{
struct V_193 * V_194 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_194 = V_144 -> V_194 ;
if ( ! V_194 )
goto V_161;
* V_192 = 0 ;
F_179 (rq, &plug->list, queuelist) {
int V_195 ;
if ( V_2 -> V_12 == V_12 )
( * V_192 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_180 ( V_2 , V_35 ) )
continue;
V_195 = F_181 ( V_2 , V_35 ) ;
if ( V_195 == V_196 ) {
V_20 = F_169 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_195 == V_197 ) {
V_20 = F_175 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_161:
return V_20 ;
}
void F_182 ( struct V_1 * V_176 , struct V_35 * V_35 )
{
V_176 -> V_52 = V_198 ;
V_176 -> V_43 |= V_35 -> V_140 & V_199 ;
if ( V_35 -> V_140 & V_200 )
V_176 -> V_43 |= V_189 ;
V_176 -> V_201 = 0 ;
V_176 -> V_23 = V_35 -> V_46 ;
V_176 -> V_191 = F_174 ( V_35 ) ;
F_183 ( V_176 -> V_12 , V_176 , V_35 ) ;
}
void V_127 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_139 = ! ! ( V_35 -> V_140 & V_202 ) ;
struct V_193 * V_194 ;
int V_195 , V_145 , V_170 = V_203 ;
struct V_1 * V_176 ;
unsigned int V_192 = 0 ;
F_147 ( V_12 , & V_35 ) ;
if ( V_35 -> V_140 & ( V_141 | V_142 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_170 = V_204 ;
goto V_205;
}
if ( F_178 ( V_12 , V_35 , & V_192 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_195 = F_184 ( V_12 , & V_176 , V_35 ) ;
if ( V_195 == V_196 ) {
if ( F_169 ( V_12 , V_176 , V_35 ) ) {
F_185 ( V_12 , V_176 , V_35 ) ;
if ( ! F_186 ( V_12 , V_176 ) )
F_187 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
} else if ( V_195 == V_197 ) {
if ( F_175 ( V_12 , V_176 , V_35 ) ) {
F_185 ( V_12 , V_176 , V_35 ) ;
if ( ! F_188 ( V_12 , V_176 ) )
F_187 ( V_12 , V_176 , V_195 ) ;
goto V_206;
}
}
V_205:
V_145 = F_144 ( V_35 ) ;
if ( V_139 )
V_145 |= V_202 ;
V_176 = F_135 ( V_12 , V_145 , V_35 ) ;
if ( F_24 ( ! V_176 ) ) {
F_29 ( V_35 , - V_207 ) ;
goto V_206;
}
F_182 ( V_176 , V_35 ) ;
if ( F_23 ( V_208 , & V_12 -> V_120 ) )
V_176 -> V_7 = F_189 () ;
V_194 = V_144 -> V_194 ;
if ( V_194 ) {
if ( F_63 ( & V_194 -> V_209 ) )
F_190 ( V_12 ) ;
else {
if ( ! V_194 -> V_210 ) {
struct V_1 * V_211 ;
V_211 = F_191 ( V_194 -> V_209 . V_212 ) ;
if ( V_211 -> V_12 != V_12 )
V_194 -> V_210 = 1 ;
}
if ( V_192 >= V_213 ) {
F_192 ( V_194 , false ) ;
F_190 ( V_12 ) ;
}
}
F_193 ( & V_176 -> V_21 , & V_194 -> V_209 ) ;
F_1 ( V_176 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_158 ( V_12 , V_176 , V_170 ) ;
F_37 ( V_12 ) ;
V_206:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_194 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_214 ;
if ( F_195 ( V_35 ) && V_19 != V_19 -> V_215 ) {
struct V_4 * V_216 = V_19 -> V_217 ;
V_35 -> V_46 += V_216 -> V_218 ;
V_35 -> V_214 = V_19 -> V_215 ;
F_196 ( F_15 ( V_35 -> V_214 ) , V_35 ,
V_19 -> V_219 ,
V_35 -> V_46 - V_216 -> V_218 ) ;
}
}
static void F_197 ( struct V_35 * V_35 )
{
char V_220 [ V_221 ] ;
F_25 ( V_50 L_11 ) ;
F_25 ( V_50 L_12 ,
F_198 ( V_35 -> V_214 , V_220 ) ,
V_35 -> V_140 ,
( unsigned long long ) V_35 -> V_46 + F_195 ( V_35 ) ,
( long long ) ( F_199 ( V_35 -> V_214 -> V_222 ) >> 9 ) ) ;
F_26 ( V_223 , & V_35 -> V_38 ) ;
}
static int T_4 F_200 ( char * V_224 )
{
return F_201 ( & V_225 , V_224 ) ;
}
static bool F_202 ( struct V_4 * V_5 , unsigned int V_226 )
{
return V_5 -> V_227 && F_203 ( & V_225 , V_226 ) ;
}
static int T_4 F_204 ( void )
{
struct V_228 * V_229 = F_205 ( L_13 ,
NULL , & V_225 ) ;
return F_206 ( V_229 ) ? F_207 ( V_229 ) : 0 ;
}
static inline bool F_202 ( struct V_4 * V_5 ,
unsigned int V_226 )
{
return false ;
}
static inline int F_208 ( struct V_35 * V_35 , unsigned int V_230 )
{
V_24 V_231 ;
if ( ! V_230 )
return 0 ;
V_231 = F_199 ( V_35 -> V_214 -> V_222 ) >> 9 ;
if ( V_231 ) {
V_24 V_232 = V_35 -> V_46 ;
if ( V_231 < V_230 || V_231 - V_230 < V_232 ) {
F_197 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_209 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_230 = F_195 ( V_35 ) ;
int V_100 = - V_39 ;
char V_220 [ V_221 ] ;
struct V_4 * V_5 ;
F_210 () ;
if ( F_208 ( V_35 , V_230 ) )
goto V_233;
V_12 = F_15 ( V_35 -> V_214 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_14
L_15 ,
F_198 ( V_35 -> V_214 , V_220 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_233;
}
if ( F_24 ( ! ( V_35 -> V_140 & V_234 ) &&
V_230 > F_211 ( V_12 ) ) ) {
F_25 ( V_41 L_16 ,
F_198 ( V_35 -> V_214 , V_220 ) ,
F_195 ( V_35 ) ,
F_211 ( V_12 ) ) ;
goto V_233;
}
V_5 = V_35 -> V_214 -> V_217 ;
if ( F_202 ( V_5 , V_35 -> V_40 ) ||
F_202 ( & F_163 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_233;
F_194 ( V_35 ) ;
if ( F_212 ( V_35 ) && F_213 ( V_35 ) )
goto V_233;
if ( F_208 ( V_35 , V_230 ) )
goto V_233;
if ( ( V_35 -> V_140 & ( V_141 | V_142 ) ) && ! V_12 -> V_235 ) {
V_35 -> V_140 &= ~ ( V_141 | V_142 ) ;
if ( ! V_230 ) {
V_100 = 0 ;
goto V_233;
}
}
if ( ( V_35 -> V_140 & V_234 ) &&
( ! F_214 ( V_12 ) ||
( ( V_35 -> V_140 & V_236 ) &&
! F_215 ( V_12 ) ) ) ) {
V_100 = - V_237 ;
goto V_233;
}
if ( F_216 ( V_12 , V_35 ) )
return false ;
F_217 ( V_12 , V_35 ) ;
return true ;
V_233:
F_29 ( V_35 , V_100 ) ;
return false ;
}
void F_218 ( struct V_35 * V_35 )
{
struct V_238 V_239 ;
if ( ! F_209 ( V_35 ) )
return;
if ( V_144 -> V_238 ) {
F_219 ( V_144 -> V_238 , V_35 ) ;
return;
}
F_142 ( V_35 -> V_190 ) ;
F_220 ( & V_239 ) ;
V_144 -> V_238 = & V_239 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_214 ) ;
V_12 -> V_240 ( V_12 , V_35 ) ;
V_35 = F_221 ( V_144 -> V_238 ) ;
} while ( V_35 );
V_144 -> V_238 = NULL ;
}
void F_222 ( int V_6 , struct V_35 * V_35 )
{
int V_73 = F_195 ( V_35 ) ;
V_35 -> V_140 |= V_6 ;
if ( F_223 ( V_35 ) && ! ( V_6 & V_234 ) ) {
if ( V_6 & V_167 ) {
F_224 ( V_241 , V_73 ) ;
} else {
F_225 ( V_35 -> V_40 ) ;
F_224 ( V_242 , V_73 ) ;
}
if ( F_24 ( V_243 ) ) {
char V_220 [ V_221 ] ;
F_25 ( V_244 L_17 ,
V_144 -> V_245 , F_226 ( V_144 ) ,
( V_6 & V_167 ) ? L_18 : L_19 ,
( unsigned long long ) V_35 -> V_46 ,
F_198 ( V_35 -> V_214 , V_220 ) ,
V_73 ) ;
}
}
F_218 ( V_35 ) ;
}
int F_227 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_234 )
return 0 ;
if ( F_31 ( V_2 ) > F_228 ( V_12 ) ||
F_33 ( V_2 ) > F_211 ( V_12 ) << 9 ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
F_229 ( V_2 ) ;
if ( V_2 -> V_187 > F_230 ( V_12 ) ) {
F_25 ( V_41 L_21 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_231 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_170 = V_246 ;
if ( F_227 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_202 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_24 ( F_99 ( V_12 ) ) ) {
F_57 ( V_12 -> V_59 , V_65 ) ;
return - V_207 ;
}
F_142 ( F_156 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_141 | V_142 ) )
V_170 = V_204 ;
F_158 ( V_12 , V_2 , V_170 ) ;
if ( V_170 == V_204 )
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_232 ( const struct V_1 * V_2 )
{
unsigned int V_188 = V_2 -> V_43 & V_189 ;
unsigned int V_226 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_247 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_190 ) {
if ( ( V_35 -> V_140 & V_188 ) != V_188 )
break;
V_226 += V_35 -> V_40 ;
}
F_142 ( F_33 ( V_2 ) && ! V_226 ) ;
return V_226 ;
}
static void F_233 ( struct V_1 * V_176 , unsigned int V_226 )
{
if ( F_3 ( V_176 ) ) {
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_234 ( V_7 , V_5 , V_248 [ V_6 ] , V_226 >> 9 ) ;
F_12 () ;
}
}
static void F_235 ( struct V_1 * V_176 )
{
if ( F_3 ( V_176 ) && ! ( V_176 -> V_43 & V_47 ) ) {
unsigned long V_249 = V_34 - V_176 -> V_33 ;
const int V_6 = F_2 ( V_176 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_176 -> V_5 ;
F_5 ( V_7 , V_5 , V_250 [ V_6 ] ) ;
F_234 ( V_7 , V_5 , V_251 [ V_6 ] , V_249 ) ;
F_10 ( V_7 , V_5 ) ;
F_236 ( V_5 , V_6 ) ;
F_237 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_238 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_239 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_252 ) ) {
if ( V_2 -> V_43 & V_253 )
F_240 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_252 ;
F_241 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_254 || V_12 -> V_254 == V_2 ) {
V_12 -> V_255 = F_242 ( V_2 ) ;
V_12 -> V_254 = NULL ;
}
if ( V_2 -> V_43 & V_256 )
break;
if ( V_12 -> V_257 && F_33 ( V_2 ) ) {
V_2 -> V_187 ++ ;
}
if ( ! V_12 -> V_124 )
break;
V_20 = V_12 -> V_124 ( V_12 , V_2 ) ;
if ( V_20 == V_258 ) {
break;
} else if ( V_20 == V_259 ) {
if ( V_12 -> V_257 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_256 ) ) {
-- V_2 -> V_187 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_260 ) {
V_2 -> V_43 |= V_44 ;
F_243 ( V_2 ) ;
F_244 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_22 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_245 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_142 ( F_63 ( & V_2 -> V_21 ) ) ;
F_142 ( F_246 ( V_2 ) ) ;
F_247 ( & V_2 -> V_21 ) ;
if ( F_248 ( V_2 ) ) {
V_12 -> V_74 [ F_249 ( V_2 ) ] ++ ;
F_250 ( V_2 ) ;
}
}
void F_243 ( struct V_1 * V_176 )
{
F_245 ( V_176 ) ;
V_176 -> V_186 = F_33 ( V_176 ) ;
if ( F_24 ( F_251 ( V_176 ) ) )
V_176 -> V_261 -> V_186 = F_33 ( V_176 -> V_261 ) ;
F_252 ( V_176 ) ;
}
struct V_1 * F_253 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_238 ( V_12 ) ;
if ( V_2 )
F_243 ( V_2 ) ;
return V_2 ;
}
bool F_254 ( struct V_1 * V_176 , int error , unsigned int V_262 )
{
int V_263 , V_264 , V_265 = 0 ;
struct V_35 * V_35 ;
if ( ! V_176 -> V_35 )
return false ;
F_255 ( V_176 -> V_12 , V_176 ) ;
if ( V_176 -> V_52 == V_198 )
V_176 -> V_201 = 0 ;
if ( error && V_176 -> V_52 == V_198 &&
! ( V_176 -> V_43 & V_44 ) ) {
char * V_266 ;
switch ( error ) {
case - V_267 :
V_266 = L_23 ;
break;
case - V_268 :
V_266 = L_24 ;
break;
case - V_269 :
V_266 = L_25 ;
break;
case - V_39 :
default:
V_266 = L_26 ;
break;
}
F_25 ( V_41 L_27 ,
V_266 , V_176 -> V_9 ? V_176 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_176 ) ) ;
}
F_233 ( V_176 , V_262 ) ;
V_263 = V_264 = 0 ;
while ( ( V_35 = V_176 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_262 >= V_35 -> V_40 ) {
V_176 -> V_35 = V_35 -> V_190 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_176 , V_35 , V_36 , error ) ;
V_265 = 0 ;
V_264 = 0 ;
} else {
int V_270 = V_35 -> V_271 + V_265 ;
if ( F_24 ( V_270 >= V_35 -> V_183 ) ) {
F_30 ( V_176 , L_28 ) ;
F_25 ( V_41 L_29 ,
V_42 , V_270 , V_35 -> V_183 ) ;
break;
}
V_36 = F_256 ( V_35 , V_270 ) -> V_182 ;
F_257 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_262 ) ) {
V_264 += V_262 ;
V_263 += V_262 ;
break;
}
V_265 ++ ;
V_264 += V_36 ;
}
V_263 += V_36 ;
V_262 -= V_36 ;
V_35 = V_176 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_262 <= 0 ) )
break;
}
}
if ( ! V_176 -> V_35 ) {
V_176 -> V_185 = 0 ;
return false ;
}
if ( V_264 ) {
F_21 ( V_176 , V_35 , V_264 , error ) ;
V_35 -> V_271 += V_265 ;
F_258 ( V_35 ) -> V_181 += V_262 ;
F_258 ( V_35 ) -> V_182 -= V_262 ;
}
V_176 -> V_185 -= V_263 ;
V_176 -> V_54 = F_168 ( V_176 -> V_35 ) ;
if ( V_176 -> V_52 == V_198 || ( V_176 -> V_43 & V_234 ) )
V_176 -> V_23 += V_263 >> 9 ;
if ( V_176 -> V_43 & V_247 ) {
V_176 -> V_43 &= ~ V_189 ;
V_176 -> V_43 |= V_176 -> V_35 -> V_140 & V_189 ;
}
if ( F_33 ( V_176 ) < F_259 ( V_176 ) ) {
F_30 ( V_176 , L_30 ) ;
V_176 -> V_185 = F_259 ( V_176 ) ;
}
F_229 ( V_176 ) ;
return true ;
}
static bool F_260 ( struct V_1 * V_2 , int error ,
unsigned int V_262 ,
unsigned int V_272 )
{
if ( F_254 ( V_2 , error , V_262 ) )
return true ;
if ( F_24 ( F_251 ( V_2 ) ) &&
F_254 ( V_2 -> V_261 , error , V_272 ) )
return true ;
if ( F_261 ( V_2 -> V_12 ) )
F_262 ( V_2 -> V_9 ) ;
return false ;
}
void F_263 ( struct V_1 * V_176 )
{
struct V_11 * V_12 = V_176 -> V_12 ;
V_176 -> V_43 &= ~ V_256 ;
if ( V_12 -> V_125 )
V_12 -> V_125 ( V_12 , V_176 ) ;
}
static void F_264 ( struct V_1 * V_176 , int error )
{
if ( F_154 ( V_176 ) )
F_155 ( V_176 -> V_12 , V_176 ) ;
F_142 ( F_156 ( V_176 ) ) ;
if ( F_24 ( V_273 ) && V_176 -> V_52 == V_198 )
F_265 ( & V_176 -> V_12 -> V_17 ) ;
F_151 ( V_176 ) ;
if ( V_176 -> V_43 & V_256 )
F_263 ( V_176 ) ;
F_235 ( V_176 ) ;
if ( V_176 -> V_233 )
V_176 -> V_233 ( V_176 , error ) ;
else {
if ( F_251 ( V_176 ) )
F_164 ( V_176 -> V_261 -> V_12 , V_176 -> V_261 ) ;
F_164 ( V_176 -> V_12 , V_176 ) ;
}
}
static bool F_266 ( struct V_1 * V_2 , int error ,
unsigned int V_262 , unsigned int V_272 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_260 ( V_2 , error , V_262 , V_272 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_264 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_267 ( struct V_1 * V_2 , int error ,
unsigned int V_262 , unsigned int V_272 )
{
if ( F_260 ( V_2 , error , V_262 , V_272 ) )
return true ;
F_264 ( V_2 , error ) ;
return false ;
}
bool F_268 ( struct V_1 * V_2 , int error , unsigned int V_262 )
{
return F_266 ( V_2 , error , V_262 , 0 ) ;
}
void F_269 ( struct V_1 * V_2 , int error )
{
bool V_274 ;
unsigned int V_272 = 0 ;
if ( F_24 ( F_251 ( V_2 ) ) )
V_272 = F_33 ( V_2 -> V_261 ) ;
V_274 = F_266 ( V_2 , error , F_33 ( V_2 ) , V_272 ) ;
F_142 ( V_274 ) ;
}
bool F_270 ( struct V_1 * V_2 , int error )
{
return F_268 ( V_2 , error , F_259 ( V_2 ) ) ;
}
bool F_271 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_268 ( V_2 , error , F_232 ( V_2 ) ) ;
}
bool F_272 ( struct V_1 * V_2 , int error , unsigned int V_262 )
{
return F_267 ( V_2 , error , V_262 , 0 ) ;
}
void F_244 ( struct V_1 * V_2 , int error )
{
bool V_274 ;
unsigned int V_272 = 0 ;
if ( F_24 ( F_251 ( V_2 ) ) )
V_272 = F_33 ( V_2 -> V_261 ) ;
V_274 = F_267 ( V_2 , error , F_33 ( V_2 ) , V_272 ) ;
F_142 ( V_274 ) ;
}
bool F_273 ( struct V_1 * V_2 , int error )
{
return F_272 ( V_2 , error , F_259 ( V_2 ) ) ;
}
bool F_274 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_272 ( V_2 , error , F_232 ( V_2 ) ) ;
}
void F_183 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_140 & V_275 ;
if ( F_223 ( V_35 ) ) {
V_2 -> V_187 = F_275 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_168 ( V_35 ) ;
}
V_2 -> V_185 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_214 )
V_2 -> V_9 = V_35 -> V_214 -> V_276 ;
}
void F_276 ( struct V_1 * V_2 )
{
struct V_277 V_278 ;
struct V_279 * V_280 ;
F_277 (bvec, rq, iter)
F_278 ( V_280 -> V_180 ) ;
}
int F_279 ( struct V_11 * V_12 )
{
if ( V_12 -> V_281 )
return V_12 -> V_281 ( V_12 ) ;
return 0 ;
}
void F_280 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_190 ;
F_281 ( V_35 ) ;
}
}
static void F_282 ( struct V_1 * V_282 , struct V_1 * V_283 )
{
V_282 -> V_7 = V_283 -> V_7 ;
V_282 -> V_43 = ( V_283 -> V_43 & V_284 ) | V_285 ;
V_282 -> V_52 = V_283 -> V_52 ;
V_282 -> V_23 = F_7 ( V_283 ) ;
V_282 -> V_185 = F_33 ( V_283 ) ;
V_282 -> V_187 = V_283 -> V_187 ;
V_282 -> V_191 = V_283 -> V_191 ;
V_282 -> V_286 = V_283 -> V_286 ;
}
int F_283 ( struct V_1 * V_2 , struct V_1 * V_287 ,
struct V_288 * V_289 , T_2 V_98 ,
int (* F_284)( struct V_35 * , struct V_35 * , void * ) ,
void * V_290 )
{
struct V_35 * V_35 , * V_291 ;
if ( ! V_289 )
V_289 = V_292 ;
F_16 ( NULL , V_2 ) ;
F_285 (bio_src, rq_src) {
V_35 = F_286 ( V_98 , V_291 -> V_293 , V_289 ) ;
if ( ! V_35 )
goto V_294;
F_287 ( V_35 , V_291 ) ;
if ( F_27 ( V_291 ) &&
F_288 ( V_35 , V_291 , V_98 , V_289 ) )
goto V_294;
if ( F_284 && F_284 ( V_35 , V_291 , V_290 ) )
goto V_294;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_190 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_282 ( V_2 , V_287 ) ;
return 0 ;
V_294:
if ( V_35 )
F_289 ( V_35 , V_289 ) ;
F_280 ( V_2 ) ;
return - V_97 ;
}
int F_290 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_291 ( V_61 , V_57 ) ;
}
int F_292 ( struct V_11 * V_12 ,
struct V_295 * V_296 , unsigned long V_297 )
{
return F_40 ( V_61 , V_296 , V_297 ) ;
}
void F_293 ( struct V_193 * V_194 )
{
struct V_298 * V_299 = V_144 ;
V_194 -> V_300 = V_301 ;
F_17 ( & V_194 -> V_209 ) ;
F_17 ( & V_194 -> V_302 ) ;
V_194 -> V_210 = 0 ;
if ( ! V_299 -> V_194 ) {
V_299 -> V_194 = V_194 ;
}
}
static int F_294 ( void * V_303 , struct V_304 * V_305 , struct V_304 * V_220 )
{
struct V_1 * V_306 = F_35 ( V_305 , struct V_1 , V_21 ) ;
struct V_1 * V_307 = F_35 ( V_220 , struct V_1 , V_21 ) ;
return ! ( V_306 -> V_12 <= V_307 -> V_12 ) ;
}
static void F_295 ( struct V_11 * V_12 , unsigned int V_308 ,
bool V_309 )
__releases( V_12 -> V_59 )
{
F_296 ( V_12 , V_308 , ! V_309 ) ;
if ( F_24 ( F_99 ( V_12 ) ) ) {
F_297 ( V_12 -> V_59 ) ;
return;
}
if ( V_309 ) {
F_297 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_297 ( V_12 -> V_59 ) ;
}
}
static void F_298 ( struct V_193 * V_194 )
{
F_299 ( V_310 ) ;
if ( F_63 ( & V_194 -> V_302 ) )
return;
F_300 ( & V_194 -> V_302 , & V_310 ) ;
while ( ! F_63 ( & V_310 ) ) {
struct V_311 * V_312 = F_301 ( & V_310 ,
struct V_311 ,
V_209 ) ;
F_302 ( & V_312 -> V_209 ) ;
V_312 -> V_313 ( V_312 ) ;
}
}
void F_192 ( struct V_193 * V_194 , bool V_309 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_299 ( V_209 ) ;
unsigned int V_308 ;
F_142 ( V_194 -> V_300 != V_301 ) ;
F_298 ( V_194 ) ;
if ( F_63 ( & V_194 -> V_209 ) )
return;
F_300 ( & V_194 -> V_209 , & V_209 ) ;
if ( V_194 -> V_210 ) {
F_303 ( NULL , & V_209 , F_294 ) ;
V_194 -> V_210 = 0 ;
}
V_12 = NULL ;
V_308 = 0 ;
F_304 ( V_65 ) ;
while ( ! F_63 ( & V_209 ) ) {
V_2 = F_191 ( V_209 . V_314 ) ;
F_247 ( & V_2 -> V_21 ) ;
F_142 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_295 ( V_12 , V_308 , V_309 ) ;
V_12 = V_2 -> V_12 ;
V_308 = 0 ;
F_305 ( V_12 -> V_59 ) ;
}
if ( F_24 ( F_99 ( V_12 ) ) ) {
F_244 ( V_2 , - V_207 ) ;
continue;
}
if ( V_2 -> V_43 & ( V_141 | V_142 ) )
F_159 ( V_12 , V_2 , V_204 ) ;
else
F_159 ( V_12 , V_2 , V_315 ) ;
V_308 ++ ;
}
if ( V_12 )
F_295 ( V_12 , V_308 , V_309 ) ;
F_306 ( V_65 ) ;
}
void F_307 ( struct V_193 * V_194 )
{
F_192 ( V_194 , false ) ;
if ( V_194 == V_144 -> V_194 )
V_144 -> V_194 = NULL ;
}
int T_4 F_308 ( void )
{
F_309 ( V_316 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_310 ( L_31 ,
V_317 | V_318 , 0 ) ;
if ( ! V_61 )
F_311 ( L_32 ) ;
V_95 = F_312 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_319 , NULL ) ;
V_101 = F_312 ( L_34 ,
sizeof( struct V_11 ) , 0 , V_319 , NULL ) ;
return 0 ;
}
