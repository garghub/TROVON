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
while ( true ) {
int V_68 ;
F_36 ( V_12 -> V_59 ) ;
F_61 ( V_12 ) ;
if ( V_67 )
F_62 ( V_12 ) ;
if ( ! F_63 ( & V_12 -> V_69 ) )
F_37 ( V_12 ) ;
if ( V_67 )
V_68 = V_12 -> V_2 . V_70 [ 0 ] + V_12 -> V_2 . V_70 [ 1 ] ;
else
V_68 = V_12 -> V_2 . V_71 ;
F_38 ( V_12 -> V_59 ) ;
if ( ! V_68 )
break;
F_64 ( 10 ) ;
}
}
void F_65 ( struct V_11 * V_12 )
{
T_1 * V_72 = V_12 -> V_59 ;
F_66 ( & V_12 -> V_73 ) ;
F_67 ( V_74 , V_12 ) ;
F_36 ( V_72 ) ;
F_48 ( V_75 , V_12 ) ;
F_48 ( V_76 , V_12 ) ;
F_48 ( V_74 , V_12 ) ;
if ( V_12 -> V_59 != & V_12 -> V_77 )
V_12 -> V_59 = & V_12 -> V_77 ;
F_38 ( V_72 ) ;
F_68 ( & V_12 -> V_73 ) ;
if ( V_12 -> V_78 )
F_60 ( V_12 , true ) ;
F_50 ( & V_12 -> V_17 . V_79 ) ;
F_49 ( V_12 ) ;
F_58 ( V_12 ) ;
}
static int F_69 ( struct V_11 * V_12 )
{
struct V_80 * V_81 = & V_12 -> V_2 ;
if ( F_24 ( V_81 -> V_82 ) )
return 0 ;
V_81 -> V_70 [ V_83 ] = V_81 -> V_70 [ V_84 ] = 0 ;
V_81 -> V_85 [ V_83 ] = V_81 -> V_85 [ V_84 ] = 0 ;
V_81 -> V_71 = 0 ;
F_70 ( & V_81 -> V_86 [ V_83 ] ) ;
F_70 ( & V_81 -> V_86 [ V_84 ] ) ;
V_81 -> V_82 = F_71 ( V_87 , V_88 ,
V_89 , V_90 , V_12 -> V_91 ) ;
if ( ! V_81 -> V_82 )
return - V_92 ;
return 0 ;
}
struct V_11 * F_72 ( T_2 V_93 )
{
return F_73 ( V_93 , - 1 ) ;
}
struct V_11 * F_73 ( T_2 V_93 , int V_94 )
{
struct V_11 * V_12 ;
int V_95 ;
V_12 = F_74 ( V_96 ,
V_93 | V_97 , V_94 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_17 . V_98 =
( V_99 * 1024 ) / V_100 ;
V_12 -> V_17 . V_101 = 0 ;
V_12 -> V_17 . V_102 = V_103 ;
V_12 -> V_17 . V_104 = L_9 ;
V_12 -> V_91 = V_94 ;
V_95 = F_75 ( & V_12 -> V_17 ) ;
if ( V_95 ) {
F_76 ( V_96 , V_12 ) ;
return NULL ;
}
if ( F_77 ( V_12 ) ) {
F_76 ( V_96 , V_12 ) ;
return NULL ;
}
F_78 ( & V_12 -> V_17 . V_79 ,
V_105 , ( unsigned long ) V_12 ) ;
F_78 ( & V_12 -> V_63 , V_106 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_107 [ 0 ] ) ;
F_17 ( & V_12 -> V_107 [ 1 ] ) ;
F_17 ( & V_12 -> V_108 ) ;
F_79 ( & V_12 -> V_58 , F_34 ) ;
F_80 ( & V_12 -> V_66 , & V_109 ) ;
F_81 ( & V_12 -> V_73 ) ;
F_82 ( & V_12 -> V_77 ) ;
V_12 -> V_59 = & V_12 -> V_77 ;
return V_12 ;
}
struct V_11 * F_83 ( T_3 * V_110 , T_1 * V_72 )
{
return F_84 ( V_110 , V_72 , - 1 ) ;
}
struct V_11 *
F_84 ( T_3 * V_110 , T_1 * V_72 , int V_94 )
{
struct V_11 * V_111 , * V_12 ;
V_111 = F_73 ( V_112 , V_94 ) ;
if ( ! V_111 )
return NULL ;
V_12 = F_85 ( V_111 , V_110 , V_72 ) ;
if ( ! V_12 )
F_65 ( V_111 ) ;
return V_12 ;
}
struct V_11 *
F_85 ( struct V_11 * V_12 , T_3 * V_110 ,
T_1 * V_72 )
{
if ( ! V_12 )
return NULL ;
if ( F_69 ( V_12 ) )
return NULL ;
V_12 -> V_64 = V_110 ;
V_12 -> V_113 = NULL ;
V_12 -> V_114 = NULL ;
V_12 -> V_115 = V_116 ;
if ( V_72 )
V_12 -> V_59 = V_72 ;
F_86 ( V_12 , V_117 ) ;
V_12 -> V_118 = V_119 ;
if ( ! F_87 ( V_12 , NULL ) ) {
F_13 ( V_12 ) ;
return V_12 ;
}
return NULL ;
}
int F_88 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_23 ( V_74 , & V_12 -> V_115 ) ) ) {
F_89 ( & V_12 -> V_66 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_90 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_120 )
F_91 ( V_12 , V_2 ) ;
F_92 ( V_2 , V_12 -> V_2 . V_82 ) ;
}
static struct V_1 *
F_93 ( struct V_11 * V_12 , unsigned int V_65 , T_2 V_93 )
{
struct V_1 * V_2 = F_94 ( V_12 -> V_2 . V_82 , V_93 ) ;
if ( ! V_2 )
return NULL ;
F_16 ( V_12 , V_2 ) ;
V_2 -> V_43 = V_65 | V_121 ;
if ( ( V_65 & V_120 ) &&
F_24 ( F_95 ( V_12 , V_2 , V_93 ) ) ) {
F_92 ( V_2 , V_12 -> V_2 . V_82 ) ;
return NULL ;
}
return V_2 ;
}
static inline int F_96 ( struct V_11 * V_12 , struct V_122 * V_123 )
{
if ( ! V_123 )
return 0 ;
return V_123 -> V_124 == V_12 -> V_125 ||
( V_123 -> V_124 > 0
&& F_97 ( V_34 , V_123 -> V_126 + V_127 ) ) ;
}
static void F_98 ( struct V_11 * V_12 , struct V_122 * V_123 )
{
if ( ! V_123 || F_96 ( V_12 , V_123 ) )
return;
V_123 -> V_124 = V_12 -> V_125 ;
V_123 -> V_126 = V_34 ;
}
static void F_99 ( struct V_11 * V_12 , int V_128 )
{
struct V_80 * V_81 = & V_12 -> V_2 ;
if ( V_81 -> V_70 [ V_128 ] < F_100 ( V_12 ) )
F_101 ( V_12 , V_128 ) ;
if ( V_81 -> V_70 [ V_128 ] + 1 <= V_12 -> V_14 ) {
if ( F_102 ( & V_81 -> V_86 [ V_128 ] ) )
F_103 ( & V_81 -> V_86 [ V_128 ] ) ;
F_104 ( V_12 , V_128 ) ;
}
}
static void F_105 ( struct V_11 * V_12 , unsigned int V_65 )
{
struct V_80 * V_81 = & V_12 -> V_2 ;
int V_128 = F_106 ( V_65 ) ;
V_81 -> V_70 [ V_128 ] -- ;
if ( V_65 & V_120 )
V_81 -> V_71 -- ;
F_99 ( V_12 , V_128 ) ;
if ( F_24 ( V_81 -> V_85 [ V_128 ^ 1 ] ) )
F_99 ( V_12 , V_128 ^ 1 ) ;
}
static bool F_107 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_129 & ( V_130 | V_131 ) )
return false ;
return true ;
}
static struct V_1 * F_108 ( struct V_11 * V_12 , int V_132 ,
struct V_35 * V_35 , T_2 V_93 )
{
struct V_1 * V_2 = NULL ;
struct V_80 * V_81 = & V_12 -> V_2 ;
struct V_122 * V_123 = NULL ;
const bool V_133 = F_106 ( V_132 ) != 0 ;
int V_134 ;
if ( F_24 ( F_23 ( V_74 , & V_12 -> V_115 ) ) )
return NULL ;
V_134 = F_109 ( V_12 , V_132 ) ;
if ( V_134 == V_135 )
goto V_136;
if ( V_81 -> V_70 [ V_133 ] + 1 >= F_110 ( V_12 ) ) {
if ( V_81 -> V_70 [ V_133 ] + 1 >= V_12 -> V_14 ) {
V_123 = F_111 ( V_137 , V_12 -> V_91 ) ;
if ( ! F_112 ( V_12 , V_133 ) ) {
F_98 ( V_12 , V_123 ) ;
F_113 ( V_12 , V_133 ) ;
} else {
if ( V_134 != V_138
&& ! F_96 ( V_12 , V_123 ) ) {
goto V_139;
}
}
}
F_114 ( V_12 , V_133 ) ;
}
if ( V_81 -> V_70 [ V_133 ] >= ( 3 * V_12 -> V_14 / 2 ) )
goto V_139;
V_81 -> V_70 [ V_133 ] ++ ;
V_81 -> V_85 [ V_133 ] = 0 ;
if ( F_107 ( V_35 ) &&
! F_23 ( V_140 , & V_12 -> V_115 ) ) {
V_132 |= V_120 ;
V_81 -> V_71 ++ ;
}
if ( F_115 ( V_12 ) )
V_132 |= V_141 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_93 ( V_12 , V_132 , V_93 ) ;
if ( F_24 ( ! V_2 ) ) {
F_36 ( V_12 -> V_59 ) ;
F_105 ( V_12 , V_132 ) ;
V_136:
if ( F_24 ( V_81 -> V_70 [ V_133 ] == 0 ) )
V_81 -> V_85 [ V_133 ] = 1 ;
goto V_139;
}
if ( F_96 ( V_12 , V_123 ) )
V_123 -> V_124 -- ;
F_116 ( V_12 , V_35 , V_132 & 1 ) ;
V_139:
return V_2 ;
}
static struct V_1 * F_117 ( struct V_11 * V_12 , int V_132 ,
struct V_35 * V_35 )
{
const bool V_133 = F_106 ( V_132 ) != 0 ;
struct V_1 * V_2 ;
V_2 = F_108 ( V_12 , V_132 , V_35 , V_142 ) ;
while ( ! V_2 ) {
F_118 ( V_86 ) ;
struct V_122 * V_123 ;
struct V_80 * V_81 = & V_12 -> V_2 ;
if ( F_24 ( F_23 ( V_74 , & V_12 -> V_115 ) ) )
return NULL ;
F_119 ( & V_81 -> V_86 [ V_133 ] , & V_86 ,
V_143 ) ;
F_120 ( V_12 , V_35 , V_132 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_121 () ;
V_123 = F_111 ( V_142 , V_12 -> V_91 ) ;
F_98 ( V_12 , V_123 ) ;
F_36 ( V_12 -> V_59 ) ;
F_122 ( & V_81 -> V_86 [ V_133 ] , & V_86 ) ;
V_2 = F_108 ( V_12 , V_132 , V_35 , V_142 ) ;
} ;
return V_2 ;
}
struct V_1 * F_123 ( struct V_11 * V_12 , int V_6 , T_2 V_93 )
{
struct V_1 * V_2 ;
F_124 ( V_6 != V_144 && V_6 != V_145 ) ;
F_36 ( V_12 -> V_59 ) ;
if ( V_93 & V_146 )
V_2 = F_117 ( V_12 , V_6 , NULL ) ;
else
V_2 = F_108 ( V_12 , V_6 , NULL , V_93 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_125 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_93 )
{
struct V_1 * V_2 = F_123 ( V_12 , F_126 ( V_35 ) , V_93 ) ;
if ( F_24 ( ! V_2 ) )
return F_127 ( - V_92 ) ;
F_128 (bio) {
struct V_35 * V_147 = V_35 ;
int V_20 ;
F_129 ( V_12 , & V_147 ) ;
V_20 = F_130 ( V_12 , V_2 , V_147 ) ;
if ( F_24 ( V_20 ) ) {
F_131 ( V_2 ) ;
return F_127 ( V_20 ) ;
}
}
return V_2 ;
}
void F_132 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_135 ( V_12 , V_2 ) ;
if ( F_136 ( V_2 ) )
F_137 ( V_12 , V_2 ) ;
F_124 ( F_138 ( V_2 ) ) ;
F_139 ( V_12 , V_2 ) ;
}
static void F_140 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_148 )
{
F_1 ( V_2 , 1 ) ;
F_141 ( V_12 , V_2 , V_148 ) ;
}
void F_142 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_149 , void * V_150 )
{
int V_148 = V_149 ? V_151 : V_152 ;
unsigned long V_65 ;
V_2 -> V_52 = V_153 ;
V_2 -> V_154 = V_150 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_136 ( V_2 ) )
F_137 ( V_12 , V_2 ) ;
F_140 ( V_12 , V_2 , V_148 ) ;
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
static void F_143 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_155 )
{
if ( V_155 == V_5 -> V_156 )
return;
if ( F_144 ( V_5 ) ) {
F_145 ( V_7 , V_5 , V_157 ,
F_144 ( V_5 ) * ( V_155 - V_5 -> V_156 ) ) ;
F_145 ( V_7 , V_5 , V_158 , ( V_155 - V_5 -> V_156 ) ) ;
}
V_5 -> V_156 = V_155 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_155 = V_34 ;
if ( V_5 -> V_159 )
F_143 ( V_7 , & F_146 ( V_5 ) -> V_10 , V_155 ) ;
F_143 ( V_7 , V_5 , V_155 ) ;
}
void F_147 ( struct V_11 * V_12 , struct V_1 * V_160 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_160 -> V_32 ) )
return;
F_148 ( V_12 , V_160 ) ;
F_43 ( V_160 -> V_35 != NULL ) ;
if ( V_160 -> V_43 & V_121 ) {
unsigned int V_65 = V_160 -> V_43 ;
F_124 ( ! F_63 ( & V_160 -> V_21 ) ) ;
F_124 ( ! F_149 ( & V_160 -> V_25 ) ) ;
F_90 ( V_12 , V_160 ) ;
F_105 ( V_12 , V_65 ) ;
}
}
void F_131 ( struct V_1 * V_160 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_160 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_147 ( V_12 , V_160 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_150 ( struct V_1 * V_2 , struct V_161 * V_161 ,
unsigned int V_162 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_163 -> V_164 = V_161 ;
V_35 -> V_163 -> V_165 = 0 ;
V_35 -> V_163 -> V_166 = V_162 ;
V_35 -> V_40 = V_162 ;
V_35 -> V_167 = 1 ;
V_35 -> V_168 = 1 ;
V_2 -> V_169 = V_2 -> V_170 = V_162 ;
V_2 -> V_171 = 1 ;
V_2 -> V_54 = F_151 ( V_35 ) ;
}
static bool F_152 ( struct V_11 * V_12 , struct V_1 * V_160 ,
struct V_35 * V_35 )
{
const int V_172 = V_35 -> V_129 & V_173 ;
if ( ! F_153 ( V_12 , V_160 , V_35 ) )
return false ;
F_154 ( V_12 , V_35 ) ;
if ( ( V_160 -> V_43 & V_173 ) != V_172 )
F_155 ( V_160 ) ;
V_160 -> V_53 -> V_174 = V_35 ;
V_160 -> V_53 = V_35 ;
V_160 -> V_169 += V_35 -> V_40 ;
V_160 -> V_175 = F_156 ( V_160 -> V_175 , F_157 ( V_35 ) ) ;
F_1 ( V_160 , 0 ) ;
F_158 ( V_12 , V_160 , V_35 ) ;
return true ;
}
static bool F_159 ( struct V_11 * V_12 ,
struct V_1 * V_160 , struct V_35 * V_35 )
{
const int V_172 = V_35 -> V_129 & V_173 ;
if ( ! F_160 ( V_12 , V_160 , V_35 ) )
return false ;
F_161 ( V_12 , V_35 ) ;
if ( ( V_160 -> V_43 & V_173 ) != V_172 )
F_155 ( V_160 ) ;
V_35 -> V_174 = V_160 -> V_35 ;
V_160 -> V_35 = V_35 ;
V_160 -> V_54 = F_151 ( V_35 ) ;
V_160 -> V_23 = V_35 -> V_46 ;
V_160 -> V_169 += V_35 -> V_40 ;
V_160 -> V_175 = F_156 ( V_160 -> V_175 , F_157 ( V_35 ) ) ;
F_1 ( V_160 , 0 ) ;
F_158 ( V_12 , V_160 , V_35 ) ;
return true ;
}
static bool F_162 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_176 )
{
struct V_177 * V_178 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_178 = V_179 -> V_178 ;
if ( ! V_178 )
goto V_139;
* V_176 = 0 ;
F_163 (rq, &plug->list, queuelist) {
int V_180 ;
( * V_176 ) ++ ;
if ( V_2 -> V_12 != V_12 )
continue;
V_180 = F_164 ( V_2 , V_35 ) ;
if ( V_180 == V_181 ) {
V_20 = F_152 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_180 == V_182 ) {
V_20 = F_159 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_139:
return V_20 ;
}
void F_165 ( struct V_1 * V_160 , struct V_35 * V_35 )
{
V_160 -> V_52 = V_183 ;
V_160 -> V_43 |= V_35 -> V_129 & V_184 ;
if ( V_35 -> V_129 & V_185 )
V_160 -> V_43 |= V_173 ;
V_160 -> V_186 = 0 ;
V_160 -> V_23 = V_35 -> V_46 ;
V_160 -> V_175 = F_157 ( V_35 ) ;
F_166 ( V_160 -> V_12 , V_160 , V_35 ) ;
}
void V_117 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_128 = ! ! ( V_35 -> V_129 & V_187 ) ;
struct V_177 * V_178 ;
int V_180 , V_132 , V_148 = V_188 ;
struct V_1 * V_160 ;
unsigned int V_176 = 0 ;
F_129 ( V_12 , & V_35 ) ;
if ( V_35 -> V_129 & ( V_130 | V_131 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_148 = V_189 ;
goto V_190;
}
if ( F_162 ( V_12 , V_35 , & V_176 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_180 = F_167 ( V_12 , & V_160 , V_35 ) ;
if ( V_180 == V_181 ) {
if ( F_152 ( V_12 , V_160 , V_35 ) ) {
if ( ! F_168 ( V_12 , V_160 ) )
F_169 ( V_12 , V_160 , V_180 ) ;
goto V_191;
}
} else if ( V_180 == V_182 ) {
if ( F_159 ( V_12 , V_160 , V_35 ) ) {
if ( ! F_170 ( V_12 , V_160 ) )
F_169 ( V_12 , V_160 , V_180 ) ;
goto V_191;
}
}
V_190:
V_132 = F_126 ( V_35 ) ;
if ( V_128 )
V_132 |= V_187 ;
V_160 = F_117 ( V_12 , V_132 , V_35 ) ;
if ( F_24 ( ! V_160 ) ) {
F_29 ( V_35 , - V_192 ) ;
goto V_191;
}
F_165 ( V_160 , V_35 ) ;
if ( F_23 ( V_193 , & V_12 -> V_115 ) )
V_160 -> V_7 = F_171 () ;
V_178 = V_179 -> V_178 ;
if ( V_178 ) {
if ( F_63 ( & V_178 -> V_194 ) )
F_172 ( V_12 ) ;
else {
if ( ! V_178 -> V_195 ) {
struct V_1 * V_196 ;
V_196 = F_173 ( V_178 -> V_194 . V_197 ) ;
if ( V_196 -> V_12 != V_12 )
V_178 -> V_195 = 1 ;
}
if ( V_176 >= V_198 ) {
F_174 ( V_178 , false ) ;
F_172 ( V_12 ) ;
}
}
F_175 ( & V_160 -> V_21 , & V_178 -> V_194 ) ;
F_1 ( V_160 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_140 ( V_12 , V_160 , V_148 ) ;
F_37 ( V_12 ) ;
V_191:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_176 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_199 ;
if ( F_177 ( V_35 ) && V_19 != V_19 -> V_200 ) {
struct V_4 * V_201 = V_19 -> V_202 ;
V_35 -> V_46 += V_201 -> V_203 ;
V_35 -> V_199 = V_19 -> V_200 ;
F_178 ( F_15 ( V_35 -> V_199 ) , V_35 ,
V_19 -> V_204 ,
V_35 -> V_46 - V_201 -> V_203 ) ;
}
}
static void F_179 ( struct V_35 * V_35 )
{
char V_205 [ V_206 ] ;
F_25 ( V_50 L_10 ) ;
F_25 ( V_50 L_11 ,
F_180 ( V_35 -> V_199 , V_205 ) ,
V_35 -> V_129 ,
( unsigned long long ) V_35 -> V_46 + F_177 ( V_35 ) ,
( long long ) ( F_181 ( V_35 -> V_199 -> V_207 ) >> 9 ) ) ;
F_26 ( V_208 , & V_35 -> V_38 ) ;
}
static int T_4 F_182 ( char * V_209 )
{
return F_183 ( & V_210 , V_209 ) ;
}
static bool F_184 ( struct V_4 * V_5 , unsigned int V_211 )
{
return V_5 -> V_212 && F_185 ( & V_210 , V_211 ) ;
}
static int T_4 F_186 ( void )
{
struct V_213 * V_214 = F_187 ( L_12 ,
NULL , & V_210 ) ;
return F_188 ( V_214 ) ? F_189 ( V_214 ) : 0 ;
}
static inline bool F_184 ( struct V_4 * V_5 ,
unsigned int V_211 )
{
return false ;
}
static inline int F_190 ( struct V_35 * V_35 , unsigned int V_215 )
{
V_24 V_216 ;
if ( ! V_215 )
return 0 ;
V_216 = F_181 ( V_35 -> V_199 -> V_207 ) >> 9 ;
if ( V_216 ) {
V_24 V_217 = V_35 -> V_46 ;
if ( V_216 < V_215 || V_216 - V_215 < V_217 ) {
F_179 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_191 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_215 = F_177 ( V_35 ) ;
int V_95 = - V_39 ;
char V_205 [ V_206 ] ;
struct V_4 * V_5 ;
F_192 () ;
if ( F_190 ( V_35 , V_215 ) )
goto V_218;
V_12 = F_15 ( V_35 -> V_199 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_13
L_14 ,
F_180 ( V_35 -> V_199 , V_205 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_218;
}
if ( F_24 ( ! ( V_35 -> V_129 & V_219 ) &&
V_215 > F_193 ( V_12 ) ) ) {
F_25 ( V_41 L_15 ,
F_180 ( V_35 -> V_199 , V_205 ) ,
F_177 ( V_35 ) ,
F_193 ( V_12 ) ) ;
goto V_218;
}
V_5 = V_35 -> V_199 -> V_202 ;
if ( F_184 ( V_5 , V_35 -> V_40 ) ||
F_184 ( & F_146 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_218;
F_176 ( V_35 ) ;
if ( F_194 ( V_35 ) && F_195 ( V_35 ) )
goto V_218;
if ( F_190 ( V_35 , V_215 ) )
goto V_218;
if ( ( V_35 -> V_129 & ( V_130 | V_131 ) ) && ! V_12 -> V_220 ) {
V_35 -> V_129 &= ~ ( V_130 | V_131 ) ;
if ( ! V_215 ) {
V_95 = 0 ;
goto V_218;
}
}
if ( ( V_35 -> V_129 & V_219 ) &&
( ! F_196 ( V_12 ) ||
( ( V_35 -> V_129 & V_221 ) &&
! F_197 ( V_12 ) ) ) ) {
V_95 = - V_222 ;
goto V_218;
}
if ( F_198 ( V_12 , V_35 ) )
return false ;
F_199 ( V_12 , V_35 ) ;
return true ;
V_218:
F_29 ( V_35 , V_95 ) ;
return false ;
}
void F_200 ( struct V_35 * V_35 )
{
struct V_223 V_224 ;
if ( ! F_191 ( V_35 ) )
return;
if ( V_179 -> V_223 ) {
F_201 ( V_179 -> V_223 , V_35 ) ;
return;
}
F_124 ( V_35 -> V_174 ) ;
F_202 ( & V_224 ) ;
V_179 -> V_223 = & V_224 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_199 ) ;
V_12 -> V_225 ( V_12 , V_35 ) ;
V_35 = F_203 ( V_179 -> V_223 ) ;
} while ( V_35 );
V_179 -> V_223 = NULL ;
}
void F_204 ( int V_6 , struct V_35 * V_35 )
{
int V_70 = F_177 ( V_35 ) ;
V_35 -> V_129 |= V_6 ;
if ( F_205 ( V_35 ) && ! ( V_6 & V_219 ) ) {
if ( V_6 & V_145 ) {
F_206 ( V_226 , V_70 ) ;
} else {
F_207 ( V_35 -> V_40 ) ;
F_206 ( V_227 , V_70 ) ;
}
if ( F_24 ( V_228 ) ) {
char V_205 [ V_206 ] ;
F_25 ( V_229 L_16 ,
V_179 -> V_230 , F_208 ( V_179 ) ,
( V_6 & V_145 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_46 ,
F_180 ( V_35 -> V_199 , V_205 ) ,
V_70 ) ;
}
}
F_200 ( V_35 ) ;
}
int F_209 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_219 )
return 0 ;
if ( F_31 ( V_2 ) > F_210 ( V_12 ) ||
F_33 ( V_2 ) > F_193 ( V_12 ) << 9 ) {
F_25 ( V_41 L_19 , V_42 ) ;
return - V_39 ;
}
F_211 ( V_2 ) ;
if ( V_2 -> V_171 > F_212 ( V_12 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_213 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_148 = V_152 ;
if ( F_209 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_184 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_124 ( F_138 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_130 | V_131 ) )
V_148 = V_189 ;
F_140 ( V_12 , V_2 , V_148 ) ;
if ( V_148 == V_189 )
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_214 ( const struct V_1 * V_2 )
{
unsigned int V_172 = V_2 -> V_43 & V_173 ;
unsigned int V_211 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_231 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_174 ) {
if ( ( V_35 -> V_129 & V_172 ) != V_172 )
break;
V_211 += V_35 -> V_40 ;
}
F_124 ( F_33 ( V_2 ) && ! V_211 ) ;
return V_211 ;
}
static void F_215 ( struct V_1 * V_160 , unsigned int V_211 )
{
if ( F_3 ( V_160 ) ) {
const int V_6 = F_2 ( V_160 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_160 -> V_5 ;
F_216 ( V_7 , V_5 , V_232 [ V_6 ] , V_211 >> 9 ) ;
F_12 () ;
}
}
static void F_217 ( struct V_1 * V_160 )
{
if ( F_3 ( V_160 ) && ! ( V_160 -> V_43 & V_47 ) ) {
unsigned long V_233 = V_34 - V_160 -> V_33 ;
const int V_6 = F_2 ( V_160 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_160 -> V_5 ;
F_5 ( V_7 , V_5 , V_234 [ V_6 ] ) ;
F_216 ( V_7 , V_5 , V_235 [ V_6 ] , V_233 ) ;
F_10 ( V_7 , V_5 ) ;
F_218 ( V_5 , V_6 ) ;
F_219 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_220 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_221 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_236 ) ) {
if ( V_2 -> V_43 & V_237 )
F_222 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_236 ;
F_223 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_238 || V_12 -> V_238 == V_2 ) {
V_12 -> V_239 = F_224 ( V_2 ) ;
V_12 -> V_238 = NULL ;
}
if ( V_2 -> V_43 & V_240 )
break;
if ( V_12 -> V_241 && F_33 ( V_2 ) ) {
V_2 -> V_171 ++ ;
}
if ( ! V_12 -> V_113 )
break;
V_20 = V_12 -> V_113 ( V_12 , V_2 ) ;
if ( V_20 == V_242 ) {
break;
} else if ( V_20 == V_243 ) {
if ( V_12 -> V_241 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_240 ) ) {
-- V_2 -> V_171 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_244 ) {
V_2 -> V_43 |= V_44 ;
F_225 ( V_2 ) ;
F_226 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_21 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_227 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_124 ( F_63 ( & V_2 -> V_21 ) ) ;
F_124 ( F_228 ( V_2 ) ) ;
F_229 ( & V_2 -> V_21 ) ;
if ( F_230 ( V_2 ) ) {
V_12 -> V_245 [ F_231 ( V_2 ) ] ++ ;
F_232 ( V_2 ) ;
}
}
void F_225 ( struct V_1 * V_160 )
{
F_227 ( V_160 ) ;
V_160 -> V_170 = F_33 ( V_160 ) ;
if ( F_24 ( F_233 ( V_160 ) ) )
V_160 -> V_246 -> V_170 = F_33 ( V_160 -> V_246 ) ;
F_234 ( V_160 ) ;
}
struct V_1 * F_235 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_220 ( V_12 ) ;
if ( V_2 )
F_225 ( V_2 ) ;
return V_2 ;
}
bool F_236 ( struct V_1 * V_160 , int error , unsigned int V_247 )
{
int V_248 , V_249 , V_250 = 0 ;
struct V_35 * V_35 ;
if ( ! V_160 -> V_35 )
return false ;
F_237 ( V_160 -> V_12 , V_160 ) ;
if ( V_160 -> V_52 == V_183 )
V_160 -> V_186 = 0 ;
if ( error && V_160 -> V_52 == V_183 &&
! ( V_160 -> V_43 & V_44 ) ) {
char * V_251 ;
switch ( error ) {
case - V_252 :
V_251 = L_22 ;
break;
case - V_253 :
V_251 = L_23 ;
break;
case - V_254 :
V_251 = L_24 ;
break;
case - V_39 :
default:
V_251 = L_25 ;
break;
}
F_25 ( V_41 L_26 ,
V_251 , V_160 -> V_9 ? V_160 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_160 ) ) ;
}
F_215 ( V_160 , V_247 ) ;
V_248 = V_249 = 0 ;
while ( ( V_35 = V_160 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_247 >= V_35 -> V_40 ) {
V_160 -> V_35 = V_35 -> V_174 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_160 , V_35 , V_36 , error ) ;
V_250 = 0 ;
V_249 = 0 ;
} else {
int V_255 = V_35 -> V_256 + V_250 ;
if ( F_24 ( V_255 >= V_35 -> V_167 ) ) {
F_30 ( V_160 , L_27 ) ;
F_25 ( V_41 L_28 ,
V_42 , V_255 , V_35 -> V_167 ) ;
break;
}
V_36 = F_238 ( V_35 , V_255 ) -> V_166 ;
F_239 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_247 ) ) {
V_249 += V_247 ;
V_248 += V_247 ;
break;
}
V_250 ++ ;
V_249 += V_36 ;
}
V_248 += V_36 ;
V_247 -= V_36 ;
V_35 = V_160 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_247 <= 0 ) )
break;
}
}
if ( ! V_160 -> V_35 ) {
V_160 -> V_169 = 0 ;
return false ;
}
if ( V_249 ) {
F_21 ( V_160 , V_35 , V_249 , error ) ;
V_35 -> V_256 += V_250 ;
F_240 ( V_35 ) -> V_165 += V_247 ;
F_240 ( V_35 ) -> V_166 -= V_247 ;
}
V_160 -> V_169 -= V_248 ;
V_160 -> V_54 = F_151 ( V_160 -> V_35 ) ;
if ( V_160 -> V_52 == V_183 || ( V_160 -> V_43 & V_219 ) )
V_160 -> V_23 += V_248 >> 9 ;
if ( V_160 -> V_43 & V_231 ) {
V_160 -> V_43 &= ~ V_173 ;
V_160 -> V_43 |= V_160 -> V_35 -> V_129 & V_173 ;
}
if ( F_33 ( V_160 ) < F_241 ( V_160 ) ) {
F_30 ( V_160 , L_29 ) ;
V_160 -> V_169 = F_241 ( V_160 ) ;
}
F_211 ( V_160 ) ;
return true ;
}
static bool F_242 ( struct V_1 * V_2 , int error ,
unsigned int V_247 ,
unsigned int V_257 )
{
if ( F_236 ( V_2 , error , V_247 ) )
return true ;
if ( F_24 ( F_233 ( V_2 ) ) &&
F_236 ( V_2 -> V_246 , error , V_257 ) )
return true ;
if ( F_243 ( V_2 -> V_12 ) )
F_244 ( V_2 -> V_9 ) ;
return false ;
}
void F_245 ( struct V_1 * V_160 )
{
struct V_11 * V_12 = V_160 -> V_12 ;
V_160 -> V_43 &= ~ V_240 ;
if ( V_12 -> V_114 )
V_12 -> V_114 ( V_12 , V_160 ) ;
}
static void F_246 ( struct V_1 * V_160 , int error )
{
if ( F_136 ( V_160 ) )
F_137 ( V_160 -> V_12 , V_160 ) ;
F_124 ( F_138 ( V_160 ) ) ;
if ( F_24 ( V_258 ) && V_160 -> V_52 == V_183 )
F_247 ( & V_160 -> V_12 -> V_17 ) ;
F_133 ( V_160 ) ;
if ( V_160 -> V_43 & V_240 )
F_245 ( V_160 ) ;
F_217 ( V_160 ) ;
if ( V_160 -> V_218 )
V_160 -> V_218 ( V_160 , error ) ;
else {
if ( F_233 ( V_160 ) )
F_147 ( V_160 -> V_246 -> V_12 , V_160 -> V_246 ) ;
F_147 ( V_160 -> V_12 , V_160 ) ;
}
}
static bool F_248 ( struct V_1 * V_2 , int error ,
unsigned int V_247 , unsigned int V_257 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_242 ( V_2 , error , V_247 , V_257 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_246 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_249 ( struct V_1 * V_2 , int error ,
unsigned int V_247 , unsigned int V_257 )
{
if ( F_242 ( V_2 , error , V_247 , V_257 ) )
return true ;
F_246 ( V_2 , error ) ;
return false ;
}
bool F_250 ( struct V_1 * V_2 , int error , unsigned int V_247 )
{
return F_248 ( V_2 , error , V_247 , 0 ) ;
}
void F_251 ( struct V_1 * V_2 , int error )
{
bool V_259 ;
unsigned int V_257 = 0 ;
if ( F_24 ( F_233 ( V_2 ) ) )
V_257 = F_33 ( V_2 -> V_246 ) ;
V_259 = F_248 ( V_2 , error , F_33 ( V_2 ) , V_257 ) ;
F_124 ( V_259 ) ;
}
bool F_252 ( struct V_1 * V_2 , int error )
{
return F_250 ( V_2 , error , F_241 ( V_2 ) ) ;
}
bool F_253 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_250 ( V_2 , error , F_214 ( V_2 ) ) ;
}
bool F_254 ( struct V_1 * V_2 , int error , unsigned int V_247 )
{
return F_249 ( V_2 , error , V_247 , 0 ) ;
}
void F_226 ( struct V_1 * V_2 , int error )
{
bool V_259 ;
unsigned int V_257 = 0 ;
if ( F_24 ( F_233 ( V_2 ) ) )
V_257 = F_33 ( V_2 -> V_246 ) ;
V_259 = F_249 ( V_2 , error , F_33 ( V_2 ) , V_257 ) ;
F_124 ( V_259 ) ;
}
bool F_255 ( struct V_1 * V_2 , int error )
{
return F_254 ( V_2 , error , F_241 ( V_2 ) ) ;
}
bool F_256 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_254 ( V_2 , error , F_214 ( V_2 ) ) ;
}
void F_166 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_129 & V_260 ;
if ( F_205 ( V_35 ) ) {
V_2 -> V_171 = F_257 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_151 ( V_35 ) ;
}
V_2 -> V_169 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_199 )
V_2 -> V_9 = V_35 -> V_199 -> V_261 ;
}
void F_258 ( struct V_1 * V_2 )
{
struct V_262 V_263 ;
struct V_264 * V_265 ;
F_259 (bvec, rq, iter)
F_260 ( V_265 -> V_164 ) ;
}
int F_261 ( struct V_11 * V_12 )
{
if ( V_12 -> V_266 )
return V_12 -> V_266 ( V_12 ) ;
return 0 ;
}
void F_262 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_174 ;
F_263 ( V_35 ) ;
}
}
static void F_264 ( struct V_1 * V_267 , struct V_1 * V_268 )
{
V_267 -> V_7 = V_268 -> V_7 ;
V_267 -> V_43 = ( V_268 -> V_43 & V_269 ) | V_270 ;
V_267 -> V_52 = V_268 -> V_52 ;
V_267 -> V_23 = F_7 ( V_268 ) ;
V_267 -> V_169 = F_33 ( V_268 ) ;
V_267 -> V_171 = V_268 -> V_171 ;
V_267 -> V_175 = V_268 -> V_175 ;
V_267 -> V_271 = V_268 -> V_271 ;
}
int F_265 ( struct V_1 * V_2 , struct V_1 * V_272 ,
struct V_273 * V_274 , T_2 V_93 ,
int (* F_266)( struct V_35 * , struct V_35 * , void * ) ,
void * V_150 )
{
struct V_35 * V_35 , * V_275 ;
if ( ! V_274 )
V_274 = V_276 ;
F_16 ( NULL , V_2 ) ;
F_267 (bio_src, rq_src) {
V_35 = F_268 ( V_93 , V_275 -> V_277 , V_274 ) ;
if ( ! V_35 )
goto V_278;
F_269 ( V_35 , V_275 ) ;
if ( F_27 ( V_275 ) &&
F_270 ( V_35 , V_275 , V_93 , V_274 ) )
goto V_278;
if ( F_266 && F_266 ( V_35 , V_275 , V_150 ) )
goto V_278;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_174 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_264 ( V_2 , V_272 ) ;
return 0 ;
V_278:
if ( V_35 )
F_271 ( V_35 , V_274 ) ;
F_262 ( V_2 ) ;
return - V_92 ;
}
int F_272 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_273 ( V_61 , V_57 ) ;
}
int F_274 ( struct V_11 * V_12 ,
struct V_279 * V_280 , unsigned long V_281 )
{
return F_40 ( V_61 , V_280 , V_281 ) ;
}
void F_275 ( struct V_177 * V_178 )
{
struct V_282 * V_283 = V_179 ;
V_178 -> V_284 = V_285 ;
F_17 ( & V_178 -> V_194 ) ;
F_17 ( & V_178 -> V_286 ) ;
V_178 -> V_195 = 0 ;
if ( ! V_283 -> V_178 ) {
V_283 -> V_178 = V_178 ;
}
}
static int F_276 ( void * V_287 , struct V_288 * V_289 , struct V_288 * V_205 )
{
struct V_1 * V_290 = F_35 ( V_289 , struct V_1 , V_21 ) ;
struct V_1 * V_291 = F_35 ( V_205 , struct V_1 , V_21 ) ;
return ! ( V_290 -> V_12 <= V_291 -> V_12 ) ;
}
static void F_277 ( struct V_11 * V_12 , unsigned int V_292 ,
bool V_293 )
__releases( V_12 -> V_59 )
{
F_278 ( V_12 , V_292 , ! V_293 ) ;
if ( V_293 ) {
F_279 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_279 ( V_12 -> V_59 ) ;
}
}
static void F_280 ( struct V_177 * V_178 )
{
F_281 ( V_294 ) ;
if ( F_63 ( & V_178 -> V_286 ) )
return;
F_282 ( & V_178 -> V_286 , & V_294 ) ;
while ( ! F_63 ( & V_294 ) ) {
struct V_295 * V_296 = F_283 ( & V_294 ,
struct V_295 ,
V_194 ) ;
F_284 ( & V_296 -> V_194 ) ;
V_296 -> V_297 ( V_296 ) ;
}
}
void F_174 ( struct V_177 * V_178 , bool V_293 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_281 ( V_194 ) ;
unsigned int V_292 ;
F_124 ( V_178 -> V_284 != V_285 ) ;
F_280 ( V_178 ) ;
if ( F_63 ( & V_178 -> V_194 ) )
return;
F_282 ( & V_178 -> V_194 , & V_194 ) ;
if ( V_178 -> V_195 ) {
F_285 ( NULL , & V_194 , F_276 ) ;
V_178 -> V_195 = 0 ;
}
V_12 = NULL ;
V_292 = 0 ;
F_286 ( V_65 ) ;
while ( ! F_63 ( & V_194 ) ) {
V_2 = F_173 ( V_194 . V_298 ) ;
F_229 ( & V_2 -> V_21 ) ;
F_124 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_277 ( V_12 , V_292 , V_293 ) ;
V_12 = V_2 -> V_12 ;
V_292 = 0 ;
F_287 ( V_12 -> V_59 ) ;
}
if ( V_2 -> V_43 & ( V_130 | V_131 ) )
F_141 ( V_12 , V_2 , V_189 ) ;
else
F_141 ( V_12 , V_2 , V_299 ) ;
V_292 ++ ;
}
if ( V_12 )
F_277 ( V_12 , V_292 , V_293 ) ;
F_288 ( V_65 ) ;
}
void F_289 ( struct V_177 * V_178 )
{
F_174 ( V_178 , false ) ;
if ( V_178 == V_179 -> V_178 )
V_179 -> V_178 = NULL ;
}
int T_4 F_290 ( void )
{
F_291 ( V_300 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_292 ( L_30 ,
V_301 | V_302 , 0 ) ;
if ( ! V_61 )
F_293 ( L_31 ) ;
V_90 = F_294 ( L_32 ,
sizeof( struct V_1 ) , 0 , V_303 , NULL ) ;
V_96 = F_294 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_303 , NULL ) ;
return 0 ;
}
