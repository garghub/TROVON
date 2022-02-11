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
void F_60 ( struct V_11 * V_12 )
{
F_49 ( V_12 ) ;
F_50 ( & V_12 -> V_17 . V_67 ) ;
F_61 ( & V_12 -> V_68 ) ;
F_62 ( V_69 , V_12 ) ;
F_63 ( & V_12 -> V_68 ) ;
if ( V_12 -> V_70 )
F_64 ( V_12 -> V_70 ) ;
F_65 ( V_12 ) ;
F_58 ( V_12 ) ;
}
static int F_66 ( struct V_11 * V_12 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
if ( F_24 ( V_72 -> V_73 ) )
return 0 ;
V_72 -> V_74 [ V_75 ] = V_72 -> V_74 [ V_76 ] = 0 ;
V_72 -> V_77 [ V_75 ] = V_72 -> V_77 [ V_76 ] = 0 ;
V_72 -> V_78 = 0 ;
F_67 ( & V_72 -> V_79 [ V_75 ] ) ;
F_67 ( & V_72 -> V_79 [ V_76 ] ) ;
V_72 -> V_73 = F_68 ( V_80 , V_81 ,
V_82 , V_83 , V_12 -> V_84 ) ;
if ( ! V_72 -> V_73 )
return - V_85 ;
return 0 ;
}
struct V_11 * F_69 ( T_1 V_86 )
{
return F_70 ( V_86 , - 1 ) ;
}
struct V_11 * F_70 ( T_1 V_86 , int V_87 )
{
struct V_11 * V_12 ;
int V_88 ;
V_12 = F_71 ( V_89 ,
V_86 | V_90 , V_87 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_17 . V_91 =
( V_92 * 1024 ) / V_93 ;
V_12 -> V_17 . V_94 = 0 ;
V_12 -> V_17 . V_95 = V_96 ;
V_12 -> V_17 . V_97 = L_9 ;
V_88 = F_72 ( & V_12 -> V_17 ) ;
if ( V_88 ) {
F_73 ( V_89 , V_12 ) ;
return NULL ;
}
if ( F_74 ( V_12 ) ) {
F_73 ( V_89 , V_12 ) ;
return NULL ;
}
F_75 ( & V_12 -> V_17 . V_67 ,
V_98 , ( unsigned long ) V_12 ) ;
F_75 ( & V_12 -> V_63 , V_99 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_100 [ 0 ] ) ;
F_17 ( & V_12 -> V_100 [ 1 ] ) ;
F_17 ( & V_12 -> V_101 ) ;
F_76 ( & V_12 -> V_58 , F_34 ) ;
F_77 ( & V_12 -> V_66 , & V_102 ) ;
F_78 ( & V_12 -> V_68 ) ;
F_79 ( & V_12 -> V_103 ) ;
V_12 -> V_59 = & V_12 -> V_103 ;
return V_12 ;
}
struct V_11 * F_80 ( T_2 * V_104 , T_3 * V_105 )
{
return F_81 ( V_104 , V_105 , - 1 ) ;
}
struct V_11 *
F_81 ( T_2 * V_104 , T_3 * V_105 , int V_87 )
{
struct V_11 * V_106 , * V_12 ;
V_106 = F_70 ( V_107 , V_87 ) ;
if ( ! V_106 )
return NULL ;
V_12 = F_82 ( V_106 , V_104 , V_105 , V_87 ) ;
if ( ! V_12 )
F_60 ( V_106 ) ;
return V_12 ;
}
struct V_11 *
F_83 ( struct V_11 * V_12 , T_2 * V_104 ,
T_3 * V_105 )
{
return F_82 ( V_12 , V_104 , V_105 , - 1 ) ;
}
struct V_11 *
F_82 ( struct V_11 * V_12 , T_2 * V_104 ,
T_3 * V_105 , int V_87 )
{
if ( ! V_12 )
return NULL ;
V_12 -> V_84 = V_87 ;
if ( F_66 ( V_12 ) )
return NULL ;
V_12 -> V_64 = V_104 ;
V_12 -> V_108 = NULL ;
V_12 -> V_109 = NULL ;
V_12 -> V_110 = V_111 ;
if ( V_105 )
V_12 -> V_59 = V_105 ;
F_84 ( V_12 , V_112 ) ;
V_12 -> V_113 = V_114 ;
if ( ! F_85 ( V_12 , NULL ) ) {
F_13 ( V_12 ) ;
return V_12 ;
}
return NULL ;
}
int F_86 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_23 ( V_69 , & V_12 -> V_110 ) ) ) {
F_87 ( & V_12 -> V_66 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_88 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_115 )
F_89 ( V_12 , V_2 ) ;
F_90 ( V_2 , V_12 -> V_2 . V_73 ) ;
}
static struct V_1 *
F_91 ( struct V_11 * V_12 , int V_65 , int V_116 , T_1 V_86 )
{
struct V_1 * V_2 = F_92 ( V_12 -> V_2 . V_73 , V_86 ) ;
if ( ! V_2 )
return NULL ;
F_16 ( V_12 , V_2 ) ;
V_2 -> V_43 = V_65 | V_117 ;
if ( V_116 ) {
if ( F_24 ( F_93 ( V_12 , V_2 , V_86 ) ) ) {
F_90 ( V_2 , V_12 -> V_2 . V_73 ) ;
return NULL ;
}
V_2 -> V_43 |= V_115 ;
}
return V_2 ;
}
static inline int F_94 ( struct V_11 * V_12 , struct V_118 * V_119 )
{
if ( ! V_119 )
return 0 ;
return V_119 -> V_120 == V_12 -> V_121 ||
( V_119 -> V_120 > 0
&& F_95 ( V_34 , V_119 -> V_122 + V_123 ) ) ;
}
static void F_96 ( struct V_11 * V_12 , struct V_118 * V_119 )
{
if ( ! V_119 || F_94 ( V_12 , V_119 ) )
return;
V_119 -> V_120 = V_12 -> V_121 ;
V_119 -> V_122 = V_34 ;
}
static void F_97 ( struct V_11 * V_12 , int V_124 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
if ( V_72 -> V_74 [ V_124 ] < F_98 ( V_12 ) )
F_99 ( V_12 , V_124 ) ;
if ( V_72 -> V_74 [ V_124 ] + 1 <= V_12 -> V_14 ) {
if ( F_100 ( & V_72 -> V_79 [ V_124 ] ) )
F_101 ( & V_72 -> V_79 [ V_124 ] ) ;
F_102 ( V_12 , V_124 ) ;
}
}
static void F_103 ( struct V_11 * V_12 , int V_124 , int V_116 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
V_72 -> V_74 [ V_124 ] -- ;
if ( V_116 )
V_72 -> V_78 -- ;
F_97 ( V_12 , V_124 ) ;
if ( F_24 ( V_72 -> V_77 [ V_124 ^ 1 ] ) )
F_97 ( V_12 , V_124 ^ 1 ) ;
}
static bool F_104 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_125 & ( V_126 | V_127 ) )
return false ;
return true ;
}
static struct V_1 * F_105 ( struct V_11 * V_12 , int V_128 ,
struct V_35 * V_35 , T_1 V_86 )
{
struct V_1 * V_2 = NULL ;
struct V_71 * V_72 = & V_12 -> V_2 ;
struct V_118 * V_119 = NULL ;
const bool V_129 = F_106 ( V_128 ) != 0 ;
int V_130 , V_116 = 0 ;
V_130 = F_107 ( V_12 , V_128 ) ;
if ( V_130 == V_131 )
goto V_132;
if ( V_72 -> V_74 [ V_129 ] + 1 >= F_108 ( V_12 ) ) {
if ( V_72 -> V_74 [ V_129 ] + 1 >= V_12 -> V_14 ) {
V_119 = F_109 ( V_133 , V_12 -> V_84 ) ;
if ( ! F_110 ( V_12 , V_129 ) ) {
F_96 ( V_12 , V_119 ) ;
F_111 ( V_12 , V_129 ) ;
} else {
if ( V_130 != V_134
&& ! F_94 ( V_12 , V_119 ) ) {
goto V_135;
}
}
}
F_112 ( V_12 , V_129 ) ;
}
if ( V_72 -> V_74 [ V_129 ] >= ( 3 * V_12 -> V_14 / 2 ) )
goto V_135;
V_72 -> V_74 [ V_129 ] ++ ;
V_72 -> V_77 [ V_129 ] = 0 ;
if ( F_104 ( V_35 ) ) {
V_116 = ! F_23 ( V_136 , & V_12 -> V_110 ) ;
if ( V_116 )
V_72 -> V_78 ++ ;
}
if ( F_113 ( V_12 ) )
V_128 |= V_137 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_91 ( V_12 , V_128 , V_116 , V_86 ) ;
if ( F_24 ( ! V_2 ) ) {
F_36 ( V_12 -> V_59 ) ;
F_103 ( V_12 , V_129 , V_116 ) ;
V_132:
if ( F_24 ( V_72 -> V_74 [ V_129 ] == 0 ) )
V_72 -> V_77 [ V_129 ] = 1 ;
goto V_135;
}
if ( F_94 ( V_12 , V_119 ) )
V_119 -> V_120 -- ;
F_114 ( V_12 , V_35 , V_128 & 1 ) ;
V_135:
return V_2 ;
}
static struct V_1 * F_115 ( struct V_11 * V_12 , int V_128 ,
struct V_35 * V_35 )
{
const bool V_129 = F_106 ( V_128 ) != 0 ;
struct V_1 * V_2 ;
V_2 = F_105 ( V_12 , V_128 , V_35 , V_138 ) ;
while ( ! V_2 ) {
F_116 ( V_79 ) ;
struct V_118 * V_119 ;
struct V_71 * V_72 = & V_12 -> V_2 ;
F_117 ( & V_72 -> V_79 [ V_129 ] , & V_79 ,
V_139 ) ;
F_118 ( V_12 , V_35 , V_128 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_119 () ;
V_119 = F_109 ( V_138 , V_12 -> V_84 ) ;
F_96 ( V_12 , V_119 ) ;
F_36 ( V_12 -> V_59 ) ;
F_120 ( & V_72 -> V_79 [ V_129 ] , & V_79 ) ;
V_2 = F_105 ( V_12 , V_128 , V_35 , V_138 ) ;
} ;
return V_2 ;
}
struct V_1 * F_121 ( struct V_11 * V_12 , int V_6 , T_1 V_86 )
{
struct V_1 * V_2 ;
F_122 ( V_6 != V_140 && V_6 != V_141 ) ;
F_36 ( V_12 -> V_59 ) ;
if ( V_86 & V_142 ) {
V_2 = F_115 ( V_12 , V_6 , NULL ) ;
} else {
V_2 = F_105 ( V_12 , V_6 , NULL , V_86 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
}
return V_2 ;
}
struct V_1 * F_123 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_1 V_86 )
{
struct V_1 * V_2 = F_121 ( V_12 , F_124 ( V_35 ) , V_86 ) ;
if ( F_24 ( ! V_2 ) )
return F_125 ( - V_85 ) ;
F_126 (bio) {
struct V_35 * V_143 = V_35 ;
int V_20 ;
F_127 ( V_12 , & V_143 ) ;
V_20 = F_128 ( V_12 , V_2 , V_143 ) ;
if ( F_24 ( V_20 ) ) {
F_129 ( V_2 ) ;
return F_125 ( V_20 ) ;
}
}
return V_2 ;
}
void F_130 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_12 , V_2 ) ;
if ( F_134 ( V_2 ) )
F_135 ( V_12 , V_2 ) ;
F_122 ( F_136 ( V_2 ) ) ;
F_137 ( V_12 , V_2 ) ;
}
static void F_138 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_144 )
{
F_1 ( V_2 , 1 ) ;
F_139 ( V_12 , V_2 , V_144 ) ;
}
void F_140 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_145 , void * V_146 )
{
int V_144 = V_145 ? V_147 : V_148 ;
unsigned long V_65 ;
V_2 -> V_52 = V_149 ;
V_2 -> V_150 = V_146 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_134 ( V_2 ) )
F_135 ( V_12 , V_2 ) ;
F_138 ( V_12 , V_2 , V_144 ) ;
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
static void F_141 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_151 )
{
if ( V_151 == V_5 -> V_152 )
return;
if ( F_142 ( V_5 ) ) {
F_143 ( V_7 , V_5 , V_153 ,
F_142 ( V_5 ) * ( V_151 - V_5 -> V_152 ) ) ;
F_143 ( V_7 , V_5 , V_154 , ( V_151 - V_5 -> V_152 ) ) ;
}
V_5 -> V_152 = V_151 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_151 = V_34 ;
if ( V_5 -> V_155 )
F_141 ( V_7 , & F_144 ( V_5 ) -> V_10 , V_151 ) ;
F_141 ( V_7 , V_5 , V_151 ) ;
}
void F_145 ( struct V_11 * V_12 , struct V_1 * V_156 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_156 -> V_32 ) )
return;
F_146 ( V_12 , V_156 ) ;
F_43 ( V_156 -> V_35 != NULL ) ;
if ( V_156 -> V_43 & V_117 ) {
int V_129 = F_147 ( V_156 ) != 0 ;
int V_116 = V_156 -> V_43 & V_115 ;
F_122 ( ! F_148 ( & V_156 -> V_21 ) ) ;
F_122 ( ! F_149 ( & V_156 -> V_25 ) ) ;
F_88 ( V_12 , V_156 ) ;
F_103 ( V_12 , V_129 , V_116 ) ;
}
}
void F_129 ( struct V_1 * V_156 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_156 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_145 ( V_12 , V_156 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_150 ( struct V_1 * V_2 , struct V_157 * V_157 ,
unsigned int V_158 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_159 -> V_160 = V_157 ;
V_35 -> V_159 -> V_161 = 0 ;
V_35 -> V_159 -> V_162 = V_158 ;
V_35 -> V_40 = V_158 ;
V_35 -> V_163 = 1 ;
V_35 -> V_164 = 1 ;
V_2 -> V_165 = V_2 -> V_166 = V_158 ;
V_2 -> V_167 = 1 ;
V_2 -> V_54 = F_151 ( V_35 ) ;
}
static bool F_152 ( struct V_11 * V_12 , struct V_1 * V_156 ,
struct V_35 * V_35 )
{
const int V_168 = V_35 -> V_125 & V_169 ;
if ( ! F_153 ( V_12 , V_156 , V_35 ) )
return false ;
F_154 ( V_12 , V_35 ) ;
if ( ( V_156 -> V_43 & V_169 ) != V_168 )
F_155 ( V_156 ) ;
V_156 -> V_53 -> V_170 = V_35 ;
V_156 -> V_53 = V_35 ;
V_156 -> V_165 += V_35 -> V_40 ;
V_156 -> V_171 = F_156 ( V_156 -> V_171 , F_157 ( V_35 ) ) ;
F_1 ( V_156 , 0 ) ;
F_158 ( V_12 , V_156 , V_35 ) ;
return true ;
}
static bool F_159 ( struct V_11 * V_12 ,
struct V_1 * V_156 , struct V_35 * V_35 )
{
const int V_168 = V_35 -> V_125 & V_169 ;
if ( ! F_160 ( V_12 , V_156 , V_35 ) )
return false ;
F_161 ( V_12 , V_35 ) ;
if ( ( V_156 -> V_43 & V_169 ) != V_168 )
F_155 ( V_156 ) ;
V_35 -> V_170 = V_156 -> V_35 ;
V_156 -> V_35 = V_35 ;
V_156 -> V_54 = F_151 ( V_35 ) ;
V_156 -> V_23 = V_35 -> V_46 ;
V_156 -> V_165 += V_35 -> V_40 ;
V_156 -> V_171 = F_156 ( V_156 -> V_171 , F_157 ( V_35 ) ) ;
F_1 ( V_156 , 0 ) ;
F_158 ( V_12 , V_156 , V_35 ) ;
return true ;
}
static bool F_162 ( struct V_172 * V_173 , struct V_11 * V_12 ,
struct V_35 * V_35 )
{
struct V_174 * V_175 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_175 = V_173 -> V_175 ;
if ( ! V_175 )
goto V_135;
F_163 (rq, &plug->list, queuelist) {
int V_176 ;
if ( V_2 -> V_12 != V_12 )
continue;
V_176 = F_164 ( V_2 , V_35 ) ;
if ( V_176 == V_177 ) {
V_20 = F_152 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_176 == V_178 ) {
V_20 = F_159 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_135:
return V_20 ;
}
void F_165 ( struct V_1 * V_156 , struct V_35 * V_35 )
{
V_156 -> V_7 = V_35 -> V_179 ;
V_156 -> V_52 = V_180 ;
V_156 -> V_43 |= V_35 -> V_125 & V_181 ;
if ( V_35 -> V_125 & V_182 )
V_156 -> V_43 |= V_169 ;
V_156 -> V_183 = 0 ;
V_156 -> V_23 = V_35 -> V_46 ;
V_156 -> V_171 = F_157 ( V_35 ) ;
F_166 ( V_156 -> V_12 , V_156 , V_35 ) ;
}
static int V_112 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_124 = ! ! ( V_35 -> V_125 & V_184 ) ;
struct V_174 * V_175 ;
int V_176 , V_128 , V_144 = V_185 ;
struct V_1 * V_156 ;
F_127 ( V_12 , & V_35 ) ;
if ( V_35 -> V_125 & ( V_126 | V_127 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_144 = V_186 ;
goto V_187;
}
if ( F_162 ( V_188 , V_12 , V_35 ) )
goto V_135;
F_36 ( V_12 -> V_59 ) ;
V_176 = F_167 ( V_12 , & V_156 , V_35 ) ;
if ( V_176 == V_177 ) {
if ( F_152 ( V_12 , V_156 , V_35 ) ) {
if ( ! F_168 ( V_12 , V_156 ) )
F_169 ( V_12 , V_156 , V_176 ) ;
goto V_189;
}
} else if ( V_176 == V_178 ) {
if ( F_159 ( V_12 , V_156 , V_35 ) ) {
if ( ! F_170 ( V_12 , V_156 ) )
F_169 ( V_12 , V_156 , V_176 ) ;
goto V_189;
}
}
V_187:
V_128 = F_124 ( V_35 ) ;
if ( V_124 )
V_128 |= V_184 ;
V_156 = F_115 ( V_12 , V_128 , V_35 ) ;
F_165 ( V_156 , V_35 ) ;
if ( F_23 ( V_190 , & V_12 -> V_110 ) ||
F_171 ( V_35 , V_191 ) ) {
V_156 -> V_7 = F_172 ( F_173 () ) ;
F_174 () ;
}
V_175 = V_188 -> V_175 ;
if ( V_175 ) {
if ( F_148 ( & V_175 -> V_192 ) )
F_175 ( V_12 ) ;
else if ( ! V_175 -> V_193 ) {
struct V_1 * V_194 ;
V_194 = F_176 ( V_175 -> V_192 . V_195 ) ;
if ( V_194 -> V_12 != V_12 )
V_175 -> V_193 = 1 ;
}
F_177 ( & V_156 -> V_21 , & V_175 -> V_192 ) ;
F_1 ( V_156 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_138 ( V_12 , V_156 , V_144 ) ;
F_37 ( V_12 ) ;
V_189:
F_38 ( V_12 -> V_59 ) ;
}
V_135:
return 0 ;
}
static inline void F_178 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_196 ;
if ( F_179 ( V_35 ) && V_19 != V_19 -> V_197 ) {
struct V_4 * V_198 = V_19 -> V_199 ;
V_35 -> V_46 += V_198 -> V_200 ;
V_35 -> V_196 = V_19 -> V_197 ;
F_180 ( F_15 ( V_35 -> V_196 ) , V_35 ,
V_19 -> V_201 ,
V_35 -> V_46 - V_198 -> V_200 ) ;
}
}
static void F_181 ( struct V_35 * V_35 )
{
char V_202 [ V_203 ] ;
F_25 ( V_50 L_10 ) ;
F_25 ( V_50 L_11 ,
F_182 ( V_35 -> V_196 , V_202 ) ,
V_35 -> V_125 ,
( unsigned long long ) V_35 -> V_46 + F_179 ( V_35 ) ,
( long long ) ( F_183 ( V_35 -> V_196 -> V_204 ) >> 9 ) ) ;
F_26 ( V_205 , & V_35 -> V_38 ) ;
}
static int T_4 F_184 ( char * V_206 )
{
return F_185 ( & V_207 , V_206 ) ;
}
static int F_186 ( struct V_35 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_196 -> V_199 ;
if ( F_144 ( V_5 ) -> V_10 . V_208 || V_5 -> V_208 )
return F_187 ( & V_207 , V_35 -> V_40 ) ;
return 0 ;
}
static int T_4 F_188 ( void )
{
return F_189 ( & V_207 ,
L_12 ) ;
}
static inline int F_186 ( struct V_35 * V_35 )
{
return 0 ;
}
static inline int F_190 ( struct V_35 * V_35 , unsigned int V_209 )
{
V_24 V_210 ;
if ( ! V_209 )
return 0 ;
V_210 = F_183 ( V_35 -> V_196 -> V_204 ) >> 9 ;
if ( V_210 ) {
V_24 V_211 = V_35 -> V_46 ;
if ( V_210 < V_209 || V_210 - V_209 < V_211 ) {
F_181 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static inline void F_191 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
V_24 V_212 ;
int V_20 , V_209 = F_179 ( V_35 ) ;
T_5 V_213 ;
int V_88 = - V_39 ;
F_192 () ;
if ( F_190 ( V_35 , V_209 ) )
goto V_214;
V_212 = - 1 ;
V_213 = 0 ;
do {
char V_202 [ V_203 ] ;
V_12 = F_15 ( V_35 -> V_196 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_13
L_14 ,
F_182 ( V_35 -> V_196 , V_202 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_214;
}
if ( F_24 ( ! ( V_35 -> V_125 & V_215 ) &&
V_209 > F_193 ( V_12 ) ) ) {
F_25 ( V_41 L_15 ,
F_182 ( V_35 -> V_196 , V_202 ) ,
F_179 ( V_35 ) ,
F_193 ( V_12 ) ) ;
goto V_214;
}
if ( F_24 ( F_23 ( V_69 , & V_12 -> V_110 ) ) )
goto V_214;
if ( F_186 ( V_35 ) )
goto V_214;
F_178 ( V_35 ) ;
if ( F_194 ( V_35 ) && F_195 ( V_35 ) )
goto V_214;
if ( V_212 != - 1 )
F_180 ( V_12 , V_35 , V_213 , V_212 ) ;
V_212 = V_35 -> V_46 ;
V_213 = V_35 -> V_196 -> V_201 ;
if ( F_190 ( V_35 , V_209 ) )
goto V_214;
if ( ( V_35 -> V_125 & ( V_126 | V_127 ) ) && ! V_12 -> V_216 ) {
V_35 -> V_125 &= ~ ( V_126 | V_127 ) ;
if ( ! V_209 ) {
V_88 = 0 ;
goto V_214;
}
}
if ( ( V_35 -> V_125 & V_215 ) &&
( ! F_196 ( V_12 ) ||
( ( V_35 -> V_125 & V_217 ) &&
! F_197 ( V_12 ) ) ) ) {
V_88 = - V_218 ;
goto V_214;
}
if ( F_198 ( V_12 , & V_35 ) )
goto V_214;
if ( ! V_35 )
break;
F_199 ( V_12 , V_35 ) ;
V_20 = V_12 -> V_219 ( V_12 , V_35 ) ;
} while ( V_20 );
return;
V_214:
F_29 ( V_35 , V_88 ) ;
}
void F_200 ( struct V_35 * V_35 )
{
struct V_220 V_221 ;
if ( V_188 -> V_220 ) {
F_201 ( V_188 -> V_220 , V_35 ) ;
return;
}
F_122 ( V_35 -> V_170 ) ;
F_202 ( & V_221 ) ;
V_188 -> V_220 = & V_221 ;
do {
F_191 ( V_35 ) ;
V_35 = F_203 ( V_188 -> V_220 ) ;
} while ( V_35 );
V_188 -> V_220 = NULL ;
}
void F_204 ( int V_6 , struct V_35 * V_35 )
{
int V_74 = F_179 ( V_35 ) ;
V_35 -> V_125 |= V_6 ;
if ( F_205 ( V_35 ) && ! ( V_6 & V_215 ) ) {
if ( V_6 & V_141 ) {
F_206 ( V_222 , V_74 ) ;
} else {
F_207 ( V_35 -> V_40 ) ;
F_206 ( V_223 , V_74 ) ;
}
if ( F_24 ( V_224 ) ) {
char V_202 [ V_203 ] ;
F_25 ( V_225 L_16 ,
V_188 -> V_226 , F_208 ( V_188 ) ,
( V_6 & V_141 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_46 ,
F_182 ( V_35 -> V_196 , V_202 ) ,
V_74 ) ;
}
}
F_200 ( V_35 ) ;
}
int F_209 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_215 )
return 0 ;
if ( F_31 ( V_2 ) > F_210 ( V_12 ) ||
F_33 ( V_2 ) > F_193 ( V_12 ) << 9 ) {
F_25 ( V_41 L_19 , V_42 ) ;
return - V_39 ;
}
F_211 ( V_2 ) ;
if ( V_2 -> V_167 > F_212 ( V_12 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_213 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
if ( F_209 ( V_12 , V_2 ) )
return - V_39 ;
#ifdef F_214
if ( V_2 -> V_9 && V_2 -> V_9 -> V_10 . V_208 &&
F_187 ( & V_207 , F_33 ( V_2 ) ) )
return - V_39 ;
#endif
F_56 ( V_12 -> V_59 , V_65 ) ;
F_122 ( F_136 ( V_2 ) ) ;
F_138 ( V_12 , V_2 , V_148 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_215 ( const struct V_1 * V_2 )
{
unsigned int V_168 = V_2 -> V_43 & V_169 ;
unsigned int V_227 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_228 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_170 ) {
if ( ( V_35 -> V_125 & V_168 ) != V_168 )
break;
V_227 += V_35 -> V_40 ;
}
F_122 ( F_33 ( V_2 ) && ! V_227 ) ;
return V_227 ;
}
static void F_216 ( struct V_1 * V_156 , unsigned int V_227 )
{
if ( F_3 ( V_156 ) ) {
const int V_6 = F_2 ( V_156 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_156 -> V_5 ;
F_217 ( V_7 , V_5 , V_229 [ V_6 ] , V_227 >> 9 ) ;
F_12 () ;
}
}
static void F_218 ( struct V_1 * V_156 )
{
if ( F_3 ( V_156 ) && ! ( V_156 -> V_43 & V_47 ) ) {
unsigned long V_230 = V_34 - V_156 -> V_33 ;
const int V_6 = F_2 ( V_156 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_156 -> V_5 ;
F_5 ( V_7 , V_5 , V_231 [ V_6 ] ) ;
F_217 ( V_7 , V_5 , V_232 [ V_6 ] , V_230 ) ;
F_10 ( V_7 , V_5 ) ;
F_219 ( V_5 , V_6 ) ;
F_220 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_221 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_222 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_233 ) ) {
if ( V_2 -> V_43 & V_234 )
F_223 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_233 ;
F_224 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_235 || V_12 -> V_235 == V_2 ) {
V_12 -> V_236 = F_225 ( V_2 ) ;
V_12 -> V_235 = NULL ;
}
if ( V_2 -> V_43 & V_237 )
break;
if ( V_12 -> V_238 && F_33 ( V_2 ) ) {
V_2 -> V_167 ++ ;
}
if ( ! V_12 -> V_108 )
break;
V_20 = V_12 -> V_108 ( V_12 , V_2 ) ;
if ( V_20 == V_239 ) {
break;
} else if ( V_20 == V_240 ) {
if ( V_12 -> V_238 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_237 ) ) {
-- V_2 -> V_167 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_241 ) {
V_2 -> V_43 |= V_44 ;
F_226 ( V_2 ) ;
F_227 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_21 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_228 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_122 ( F_148 ( & V_2 -> V_21 ) ) ;
F_122 ( F_229 ( V_2 ) ) ;
F_230 ( & V_2 -> V_21 ) ;
if ( F_231 ( V_2 ) ) {
V_12 -> V_242 [ F_147 ( V_2 ) ] ++ ;
F_232 ( V_2 ) ;
}
}
void F_226 ( struct V_1 * V_156 )
{
F_228 ( V_156 ) ;
V_156 -> V_166 = F_33 ( V_156 ) ;
if ( F_24 ( F_233 ( V_156 ) ) )
V_156 -> V_243 -> V_166 = F_33 ( V_156 -> V_243 ) ;
F_234 ( V_156 ) ;
}
struct V_1 * F_235 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_221 ( V_12 ) ;
if ( V_2 )
F_226 ( V_2 ) ;
return V_2 ;
}
bool F_236 ( struct V_1 * V_156 , int error , unsigned int V_244 )
{
int V_245 , V_246 , V_247 = 0 ;
struct V_35 * V_35 ;
if ( ! V_156 -> V_35 )
return false ;
F_237 ( V_156 -> V_12 , V_156 ) ;
if ( V_156 -> V_52 == V_180 )
V_156 -> V_183 = 0 ;
if ( error && V_156 -> V_52 == V_180 &&
! ( V_156 -> V_43 & V_44 ) ) {
char * V_248 ;
switch ( error ) {
case - V_249 :
V_248 = L_22 ;
break;
case - V_250 :
V_248 = L_23 ;
break;
case - V_251 :
V_248 = L_24 ;
break;
case - V_39 :
default:
V_248 = L_25 ;
break;
}
F_25 ( V_41 L_26 ,
V_248 , V_156 -> V_9 ? V_156 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_156 ) ) ;
}
F_216 ( V_156 , V_244 ) ;
V_245 = V_246 = 0 ;
while ( ( V_35 = V_156 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_244 >= V_35 -> V_40 ) {
V_156 -> V_35 = V_35 -> V_170 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_156 , V_35 , V_36 , error ) ;
V_247 = 0 ;
V_246 = 0 ;
} else {
int V_252 = V_35 -> V_253 + V_247 ;
if ( F_24 ( V_252 >= V_35 -> V_163 ) ) {
F_30 ( V_156 , L_27 ) ;
F_25 ( V_41 L_28 ,
V_42 , V_252 , V_35 -> V_163 ) ;
break;
}
V_36 = F_238 ( V_35 , V_252 ) -> V_162 ;
F_239 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_244 ) ) {
V_246 += V_244 ;
V_245 += V_244 ;
break;
}
V_247 ++ ;
V_246 += V_36 ;
}
V_245 += V_36 ;
V_244 -= V_36 ;
V_35 = V_156 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_244 <= 0 ) )
break;
}
}
if ( ! V_156 -> V_35 ) {
V_156 -> V_165 = 0 ;
return false ;
}
if ( V_246 ) {
F_21 ( V_156 , V_35 , V_246 , error ) ;
V_35 -> V_253 += V_247 ;
F_240 ( V_35 ) -> V_161 += V_244 ;
F_240 ( V_35 ) -> V_162 -= V_244 ;
}
V_156 -> V_165 -= V_245 ;
V_156 -> V_54 = F_151 ( V_156 -> V_35 ) ;
if ( V_156 -> V_52 == V_180 || ( V_156 -> V_43 & V_215 ) )
V_156 -> V_23 += V_245 >> 9 ;
if ( V_156 -> V_43 & V_228 ) {
V_156 -> V_43 &= ~ V_169 ;
V_156 -> V_43 |= V_156 -> V_35 -> V_125 & V_169 ;
}
if ( F_33 ( V_156 ) < F_241 ( V_156 ) ) {
F_30 ( V_156 , L_29 ) ;
V_156 -> V_165 = F_241 ( V_156 ) ;
}
F_211 ( V_156 ) ;
return true ;
}
static bool F_242 ( struct V_1 * V_2 , int error ,
unsigned int V_244 ,
unsigned int V_254 )
{
if ( F_236 ( V_2 , error , V_244 ) )
return true ;
if ( F_24 ( F_233 ( V_2 ) ) &&
F_236 ( V_2 -> V_243 , error , V_254 ) )
return true ;
if ( F_243 ( V_2 -> V_12 ) )
F_244 ( V_2 -> V_9 ) ;
return false ;
}
void F_245 ( struct V_1 * V_156 )
{
struct V_11 * V_12 = V_156 -> V_12 ;
V_156 -> V_43 &= ~ V_237 ;
if ( V_12 -> V_109 )
V_12 -> V_109 ( V_12 , V_156 ) ;
}
static void F_246 ( struct V_1 * V_156 , int error )
{
if ( F_134 ( V_156 ) )
F_135 ( V_156 -> V_12 , V_156 ) ;
F_122 ( F_136 ( V_156 ) ) ;
if ( F_24 ( V_255 ) && V_156 -> V_52 == V_180 )
F_247 ( & V_156 -> V_12 -> V_17 ) ;
F_131 ( V_156 ) ;
if ( V_156 -> V_43 & V_237 )
F_245 ( V_156 ) ;
F_218 ( V_156 ) ;
if ( V_156 -> V_214 )
V_156 -> V_214 ( V_156 , error ) ;
else {
if ( F_233 ( V_156 ) )
F_145 ( V_156 -> V_243 -> V_12 , V_156 -> V_243 ) ;
F_145 ( V_156 -> V_12 , V_156 ) ;
}
}
static bool F_248 ( struct V_1 * V_2 , int error ,
unsigned int V_244 , unsigned int V_254 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_242 ( V_2 , error , V_244 , V_254 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_246 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
static bool F_249 ( struct V_1 * V_2 , int error ,
unsigned int V_244 , unsigned int V_254 )
{
if ( F_242 ( V_2 , error , V_244 , V_254 ) )
return true ;
F_246 ( V_2 , error ) ;
return false ;
}
bool F_250 ( struct V_1 * V_2 , int error , unsigned int V_244 )
{
return F_248 ( V_2 , error , V_244 , 0 ) ;
}
void F_251 ( struct V_1 * V_2 , int error )
{
bool V_256 ;
unsigned int V_254 = 0 ;
if ( F_24 ( F_233 ( V_2 ) ) )
V_254 = F_33 ( V_2 -> V_243 ) ;
V_256 = F_248 ( V_2 , error , F_33 ( V_2 ) , V_254 ) ;
F_122 ( V_256 ) ;
}
bool F_252 ( struct V_1 * V_2 , int error )
{
return F_250 ( V_2 , error , F_241 ( V_2 ) ) ;
}
bool F_253 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_250 ( V_2 , error , F_215 ( V_2 ) ) ;
}
bool F_254 ( struct V_1 * V_2 , int error , unsigned int V_244 )
{
return F_249 ( V_2 , error , V_244 , 0 ) ;
}
void F_227 ( struct V_1 * V_2 , int error )
{
bool V_256 ;
unsigned int V_254 = 0 ;
if ( F_24 ( F_233 ( V_2 ) ) )
V_254 = F_33 ( V_2 -> V_243 ) ;
V_256 = F_249 ( V_2 , error , F_33 ( V_2 ) , V_254 ) ;
F_122 ( V_256 ) ;
}
bool F_255 ( struct V_1 * V_2 , int error )
{
return F_254 ( V_2 , error , F_241 ( V_2 ) ) ;
}
bool F_256 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_254 ( V_2 , error , F_215 ( V_2 ) ) ;
}
void F_166 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_125 & V_257 ;
if ( F_205 ( V_35 ) ) {
V_2 -> V_167 = F_257 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_151 ( V_35 ) ;
}
V_2 -> V_165 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_196 )
V_2 -> V_9 = V_35 -> V_196 -> V_258 ;
}
void F_258 ( struct V_1 * V_2 )
{
struct V_259 V_260 ;
struct V_261 * V_262 ;
F_259 (bvec, rq, iter)
F_260 ( V_262 -> V_160 ) ;
}
int F_261 ( struct V_11 * V_12 )
{
if ( V_12 -> V_263 )
return V_12 -> V_263 ( V_12 ) ;
return 0 ;
}
void F_262 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_170 ;
F_263 ( V_35 ) ;
}
}
static void F_264 ( struct V_1 * V_264 , struct V_1 * V_265 )
{
V_264 -> V_7 = V_265 -> V_7 ;
V_264 -> V_43 = ( V_265 -> V_43 & V_266 ) | V_267 ;
V_264 -> V_52 = V_265 -> V_52 ;
V_264 -> V_23 = F_7 ( V_265 ) ;
V_264 -> V_165 = F_33 ( V_265 ) ;
V_264 -> V_167 = V_265 -> V_167 ;
V_264 -> V_171 = V_265 -> V_171 ;
V_264 -> V_268 = V_265 -> V_268 ;
}
int F_265 ( struct V_1 * V_2 , struct V_1 * V_269 ,
struct V_270 * V_271 , T_1 V_86 ,
int (* F_266)( struct V_35 * , struct V_35 * , void * ) ,
void * V_146 )
{
struct V_35 * V_35 , * V_272 ;
if ( ! V_271 )
V_271 = V_273 ;
F_16 ( NULL , V_2 ) ;
F_267 (bio_src, rq_src) {
V_35 = F_268 ( V_86 , V_272 -> V_274 , V_271 ) ;
if ( ! V_35 )
goto V_275;
F_269 ( V_35 , V_272 ) ;
if ( F_27 ( V_272 ) &&
F_270 ( V_35 , V_272 , V_86 , V_271 ) )
goto V_275;
if ( F_266 && F_266 ( V_35 , V_272 , V_146 ) )
goto V_275;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_170 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_264 ( V_2 , V_269 ) ;
return 0 ;
V_275:
if ( V_35 )
F_271 ( V_35 , V_271 ) ;
F_262 ( V_2 ) ;
return - V_85 ;
}
int F_272 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_273 ( V_61 , V_57 ) ;
}
int F_274 ( struct V_11 * V_12 ,
struct V_276 * V_277 , unsigned long V_278 )
{
return F_40 ( V_61 , V_277 , V_278 ) ;
}
void F_275 ( struct V_174 * V_175 )
{
struct V_172 * V_173 = V_188 ;
V_175 -> V_279 = V_280 ;
F_17 ( & V_175 -> V_192 ) ;
F_17 ( & V_175 -> V_281 ) ;
V_175 -> V_193 = 0 ;
if ( ! V_173 -> V_175 ) {
V_173 -> V_175 = V_175 ;
}
}
static int F_276 ( void * V_116 , struct V_282 * V_283 , struct V_282 * V_202 )
{
struct V_1 * V_284 = F_35 ( V_283 , struct V_1 , V_21 ) ;
struct V_1 * V_285 = F_35 ( V_202 , struct V_1 , V_21 ) ;
return ! ( V_284 -> V_12 <= V_285 -> V_12 ) ;
}
static void F_277 ( struct V_11 * V_12 , unsigned int V_286 ,
bool V_287 )
__releases( V_12 -> V_59 )
{
F_278 ( V_12 , V_286 , ! V_287 ) ;
if ( V_287 ) {
F_279 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_279 ( V_12 -> V_59 ) ;
}
}
static void F_280 ( struct V_174 * V_175 )
{
F_281 ( V_288 ) ;
if ( F_148 ( & V_175 -> V_281 ) )
return;
F_282 ( & V_175 -> V_281 , & V_288 ) ;
while ( ! F_148 ( & V_288 ) ) {
struct V_289 * V_290 = F_283 ( & V_288 ,
struct V_289 ,
V_192 ) ;
F_284 ( & V_290 -> V_192 ) ;
V_290 -> V_291 ( V_290 ) ;
}
}
void F_285 ( struct V_174 * V_175 , bool V_287 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_281 ( V_192 ) ;
unsigned int V_286 ;
F_122 ( V_175 -> V_279 != V_280 ) ;
F_280 ( V_175 ) ;
if ( F_148 ( & V_175 -> V_192 ) )
return;
F_282 ( & V_175 -> V_192 , & V_192 ) ;
if ( V_175 -> V_193 ) {
F_286 ( NULL , & V_192 , F_276 ) ;
V_175 -> V_193 = 0 ;
}
V_12 = NULL ;
V_286 = 0 ;
F_287 ( V_65 ) ;
while ( ! F_148 ( & V_192 ) ) {
V_2 = F_176 ( V_192 . V_292 ) ;
F_230 ( & V_2 -> V_21 ) ;
F_122 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_277 ( V_12 , V_286 , V_287 ) ;
V_12 = V_2 -> V_12 ;
V_286 = 0 ;
F_288 ( V_12 -> V_59 ) ;
}
if ( V_2 -> V_43 & ( V_126 | V_127 ) )
F_139 ( V_12 , V_2 , V_186 ) ;
else
F_139 ( V_12 , V_2 , V_293 ) ;
V_286 ++ ;
}
if ( V_12 )
F_277 ( V_12 , V_286 , V_287 ) ;
F_289 ( V_65 ) ;
}
void F_290 ( struct V_174 * V_175 )
{
F_285 ( V_175 , false ) ;
if ( V_175 == V_188 -> V_175 )
V_188 -> V_175 = NULL ;
}
int T_4 F_291 ( void )
{
F_292 ( V_294 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_293 ( L_30 ,
V_295 | V_296 , 0 ) ;
if ( ! V_61 )
F_294 ( L_31 ) ;
V_83 = F_295 ( L_32 ,
sizeof( struct V_1 ) , 0 , V_297 , NULL ) ;
V_89 = F_295 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_297 , NULL ) ;
return 0 ;
}
