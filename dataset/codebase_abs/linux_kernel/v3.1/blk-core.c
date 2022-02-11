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
if ( V_12 -> V_59 != & V_12 -> V_70 )
V_12 -> V_59 = & V_12 -> V_70 ;
F_58 ( V_12 ) ;
}
static int F_64 ( struct V_11 * V_12 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
if ( F_24 ( V_72 -> V_73 ) )
return 0 ;
V_72 -> V_74 [ V_75 ] = V_72 -> V_74 [ V_76 ] = 0 ;
V_72 -> V_77 [ V_75 ] = V_72 -> V_77 [ V_76 ] = 0 ;
V_72 -> V_78 = 0 ;
F_65 ( & V_72 -> V_79 [ V_75 ] ) ;
F_65 ( & V_72 -> V_79 [ V_76 ] ) ;
V_72 -> V_73 = F_66 ( V_80 , V_81 ,
V_82 , V_83 , V_12 -> V_84 ) ;
if ( ! V_72 -> V_73 )
return - V_85 ;
return 0 ;
}
struct V_11 * F_67 ( T_1 V_86 )
{
return F_68 ( V_86 , - 1 ) ;
}
struct V_11 * F_68 ( T_1 V_86 , int V_87 )
{
struct V_11 * V_12 ;
int V_88 ;
V_12 = F_69 ( V_89 ,
V_86 | V_90 , V_87 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_17 . V_91 =
( V_92 * 1024 ) / V_93 ;
V_12 -> V_17 . V_94 = 0 ;
V_12 -> V_17 . V_95 = V_96 ;
V_12 -> V_17 . V_97 = L_9 ;
V_88 = F_70 ( & V_12 -> V_17 ) ;
if ( V_88 ) {
F_71 ( V_89 , V_12 ) ;
return NULL ;
}
if ( F_72 ( V_12 ) ) {
F_71 ( V_89 , V_12 ) ;
return NULL ;
}
F_73 ( & V_12 -> V_17 . V_67 ,
V_98 , ( unsigned long ) V_12 ) ;
F_73 ( & V_12 -> V_63 , V_99 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_100 [ 0 ] ) ;
F_17 ( & V_12 -> V_100 [ 1 ] ) ;
F_17 ( & V_12 -> V_101 ) ;
F_74 ( & V_12 -> V_58 , F_34 ) ;
F_75 ( & V_12 -> V_66 , & V_102 ) ;
F_76 ( & V_12 -> V_68 ) ;
F_77 ( & V_12 -> V_70 ) ;
V_12 -> V_59 = & V_12 -> V_70 ;
return V_12 ;
}
struct V_11 * F_78 ( T_2 * V_103 , T_3 * V_104 )
{
return F_79 ( V_103 , V_104 , - 1 ) ;
}
struct V_11 *
F_79 ( T_2 * V_103 , T_3 * V_104 , int V_87 )
{
struct V_11 * V_105 , * V_12 ;
V_105 = F_68 ( V_106 , V_87 ) ;
if ( ! V_105 )
return NULL ;
V_12 = F_80 ( V_105 , V_103 , V_104 , V_87 ) ;
if ( ! V_12 )
F_60 ( V_105 ) ;
return V_12 ;
}
struct V_11 *
F_81 ( struct V_11 * V_12 , T_2 * V_103 ,
T_3 * V_104 )
{
return F_80 ( V_12 , V_103 , V_104 , - 1 ) ;
}
struct V_11 *
F_80 ( struct V_11 * V_12 , T_2 * V_103 ,
T_3 * V_104 , int V_87 )
{
if ( ! V_12 )
return NULL ;
V_12 -> V_84 = V_87 ;
if ( F_64 ( V_12 ) )
return NULL ;
V_12 -> V_64 = V_103 ;
V_12 -> V_107 = NULL ;
V_12 -> V_108 = NULL ;
V_12 -> V_109 = V_110 ;
if ( V_104 )
V_12 -> V_59 = V_104 ;
F_82 ( V_12 , V_111 ) ;
V_12 -> V_112 = V_113 ;
if ( ! F_83 ( V_12 , NULL ) ) {
F_13 ( V_12 ) ;
return V_12 ;
}
return NULL ;
}
int F_84 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_23 ( V_69 , & V_12 -> V_109 ) ) ) {
F_85 ( & V_12 -> V_66 ) ;
return 0 ;
}
return 1 ;
}
static inline void F_86 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_114 )
F_87 ( V_12 , V_2 ) ;
F_88 ( V_2 , V_12 -> V_2 . V_73 ) ;
}
static struct V_1 *
F_89 ( struct V_11 * V_12 , int V_65 , int V_115 , T_1 V_86 )
{
struct V_1 * V_2 = F_90 ( V_12 -> V_2 . V_73 , V_86 ) ;
if ( ! V_2 )
return NULL ;
F_16 ( V_12 , V_2 ) ;
V_2 -> V_43 = V_65 | V_116 ;
if ( V_115 ) {
if ( F_24 ( F_91 ( V_12 , V_2 , V_86 ) ) ) {
F_88 ( V_2 , V_12 -> V_2 . V_73 ) ;
return NULL ;
}
V_2 -> V_43 |= V_114 ;
}
return V_2 ;
}
static inline int F_92 ( struct V_11 * V_12 , struct V_117 * V_118 )
{
if ( ! V_118 )
return 0 ;
return V_118 -> V_119 == V_12 -> V_120 ||
( V_118 -> V_119 > 0
&& F_93 ( V_34 , V_118 -> V_121 + V_122 ) ) ;
}
static void F_94 ( struct V_11 * V_12 , struct V_117 * V_118 )
{
if ( ! V_118 || F_92 ( V_12 , V_118 ) )
return;
V_118 -> V_119 = V_12 -> V_120 ;
V_118 -> V_121 = V_34 ;
}
static void F_95 ( struct V_11 * V_12 , int V_123 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
if ( V_72 -> V_74 [ V_123 ] < F_96 ( V_12 ) )
F_97 ( V_12 , V_123 ) ;
if ( V_72 -> V_74 [ V_123 ] + 1 <= V_12 -> V_14 ) {
if ( F_98 ( & V_72 -> V_79 [ V_123 ] ) )
F_99 ( & V_72 -> V_79 [ V_123 ] ) ;
F_100 ( V_12 , V_123 ) ;
}
}
static void F_101 ( struct V_11 * V_12 , int V_123 , int V_115 )
{
struct V_71 * V_72 = & V_12 -> V_2 ;
V_72 -> V_74 [ V_123 ] -- ;
if ( V_115 )
V_72 -> V_78 -- ;
F_95 ( V_12 , V_123 ) ;
if ( F_24 ( V_72 -> V_77 [ V_123 ^ 1 ] ) )
F_95 ( V_12 , V_123 ^ 1 ) ;
}
static bool F_102 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_124 & ( V_125 | V_126 ) )
return false ;
return true ;
}
static struct V_1 * F_103 ( struct V_11 * V_12 , int V_127 ,
struct V_35 * V_35 , T_1 V_86 )
{
struct V_1 * V_2 = NULL ;
struct V_71 * V_72 = & V_12 -> V_2 ;
struct V_117 * V_118 = NULL ;
const bool V_128 = F_104 ( V_127 ) != 0 ;
int V_129 , V_115 = 0 ;
V_129 = F_105 ( V_12 , V_127 ) ;
if ( V_129 == V_130 )
goto V_131;
if ( V_72 -> V_74 [ V_128 ] + 1 >= F_106 ( V_12 ) ) {
if ( V_72 -> V_74 [ V_128 ] + 1 >= V_12 -> V_14 ) {
V_118 = F_107 ( V_132 , V_12 -> V_84 ) ;
if ( ! F_108 ( V_12 , V_128 ) ) {
F_94 ( V_12 , V_118 ) ;
F_109 ( V_12 , V_128 ) ;
} else {
if ( V_129 != V_133
&& ! F_92 ( V_12 , V_118 ) ) {
goto V_134;
}
}
}
F_110 ( V_12 , V_128 ) ;
}
if ( V_72 -> V_74 [ V_128 ] >= ( 3 * V_12 -> V_14 / 2 ) )
goto V_134;
V_72 -> V_74 [ V_128 ] ++ ;
V_72 -> V_77 [ V_128 ] = 0 ;
if ( F_102 ( V_35 ) ) {
V_115 = ! F_23 ( V_135 , & V_12 -> V_109 ) ;
if ( V_115 )
V_72 -> V_78 ++ ;
}
if ( F_111 ( V_12 ) )
V_127 |= V_136 ;
F_38 ( V_12 -> V_59 ) ;
V_2 = F_89 ( V_12 , V_127 , V_115 , V_86 ) ;
if ( F_24 ( ! V_2 ) ) {
F_36 ( V_12 -> V_59 ) ;
F_101 ( V_12 , V_128 , V_115 ) ;
V_131:
if ( F_24 ( V_72 -> V_74 [ V_128 ] == 0 ) )
V_72 -> V_77 [ V_128 ] = 1 ;
goto V_134;
}
if ( F_92 ( V_12 , V_118 ) )
V_118 -> V_119 -- ;
F_112 ( V_12 , V_35 , V_127 & 1 ) ;
V_134:
return V_2 ;
}
static struct V_1 * F_113 ( struct V_11 * V_12 , int V_127 ,
struct V_35 * V_35 )
{
const bool V_128 = F_104 ( V_127 ) != 0 ;
struct V_1 * V_2 ;
V_2 = F_103 ( V_12 , V_127 , V_35 , V_137 ) ;
while ( ! V_2 ) {
F_114 ( V_79 ) ;
struct V_117 * V_118 ;
struct V_71 * V_72 = & V_12 -> V_2 ;
F_115 ( & V_72 -> V_79 [ V_128 ] , & V_79 ,
V_138 ) ;
F_116 ( V_12 , V_35 , V_127 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_117 () ;
V_118 = F_107 ( V_137 , V_12 -> V_84 ) ;
F_94 ( V_12 , V_118 ) ;
F_36 ( V_12 -> V_59 ) ;
F_118 ( & V_72 -> V_79 [ V_128 ] , & V_79 ) ;
V_2 = F_103 ( V_12 , V_127 , V_35 , V_137 ) ;
} ;
return V_2 ;
}
struct V_1 * F_119 ( struct V_11 * V_12 , int V_6 , T_1 V_86 )
{
struct V_1 * V_2 ;
if ( F_24 ( F_23 ( V_69 , & V_12 -> V_109 ) ) )
return NULL ;
F_120 ( V_6 != V_139 && V_6 != V_140 ) ;
F_36 ( V_12 -> V_59 ) ;
if ( V_86 & V_141 ) {
V_2 = F_113 ( V_12 , V_6 , NULL ) ;
} else {
V_2 = F_103 ( V_12 , V_6 , NULL , V_86 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
}
return V_2 ;
}
struct V_1 * F_121 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_1 V_86 )
{
struct V_1 * V_2 = F_119 ( V_12 , F_122 ( V_35 ) , V_86 ) ;
if ( F_24 ( ! V_2 ) )
return F_123 ( - V_85 ) ;
F_124 (bio) {
struct V_35 * V_142 = V_35 ;
int V_20 ;
F_125 ( V_12 , & V_142 ) ;
V_20 = F_126 ( V_12 , V_2 , V_142 ) ;
if ( F_24 ( V_20 ) ) {
F_127 ( V_2 ) ;
return F_123 ( V_20 ) ;
}
}
return V_2 ;
}
void F_128 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
F_131 ( V_12 , V_2 ) ;
if ( F_132 ( V_2 ) )
F_133 ( V_12 , V_2 ) ;
F_120 ( F_134 ( V_2 ) ) ;
F_135 ( V_12 , V_2 ) ;
}
static void F_136 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_143 )
{
F_1 ( V_2 , 1 ) ;
F_137 ( V_12 , V_2 , V_143 ) ;
}
void F_138 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_144 , void * V_145 )
{
int V_143 = V_144 ? V_146 : V_147 ;
unsigned long V_65 ;
V_2 -> V_52 = V_148 ;
V_2 -> V_149 = V_145 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_132 ( V_2 ) )
F_133 ( V_12 , V_2 ) ;
F_136 ( V_12 , V_2 , V_143 ) ;
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
static void F_139 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_150 )
{
if ( V_150 == V_5 -> V_151 )
return;
if ( F_140 ( V_5 ) ) {
F_141 ( V_7 , V_5 , V_152 ,
F_140 ( V_5 ) * ( V_150 - V_5 -> V_151 ) ) ;
F_141 ( V_7 , V_5 , V_153 , ( V_150 - V_5 -> V_151 ) ) ;
}
V_5 -> V_151 = V_150 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_150 = V_34 ;
if ( V_5 -> V_154 )
F_139 ( V_7 , & F_142 ( V_5 ) -> V_10 , V_150 ) ;
F_139 ( V_7 , V_5 , V_150 ) ;
}
void F_143 ( struct V_11 * V_12 , struct V_1 * V_155 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_155 -> V_32 ) )
return;
F_144 ( V_12 , V_155 ) ;
F_43 ( V_155 -> V_35 != NULL ) ;
if ( V_155 -> V_43 & V_116 ) {
int V_128 = F_145 ( V_155 ) != 0 ;
int V_115 = V_155 -> V_43 & V_114 ;
F_120 ( ! F_146 ( & V_155 -> V_21 ) ) ;
F_120 ( ! F_147 ( & V_155 -> V_25 ) ) ;
F_86 ( V_12 , V_155 ) ;
F_101 ( V_12 , V_128 , V_115 ) ;
}
}
void F_127 ( struct V_1 * V_155 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_155 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_143 ( V_12 , V_155 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_148 ( struct V_1 * V_2 , struct V_156 * V_156 ,
unsigned int V_157 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_158 -> V_159 = V_156 ;
V_35 -> V_158 -> V_160 = 0 ;
V_35 -> V_158 -> V_161 = V_157 ;
V_35 -> V_40 = V_157 ;
V_35 -> V_162 = 1 ;
V_35 -> V_163 = 1 ;
V_2 -> V_164 = V_2 -> V_165 = V_157 ;
V_2 -> V_166 = 1 ;
V_2 -> V_54 = F_149 ( V_35 ) ;
}
static bool F_150 ( struct V_11 * V_12 , struct V_1 * V_155 ,
struct V_35 * V_35 )
{
const int V_167 = V_35 -> V_124 & V_168 ;
if ( ! F_151 ( V_12 , V_155 , V_35 ) )
return false ;
F_152 ( V_12 , V_35 ) ;
if ( ( V_155 -> V_43 & V_168 ) != V_167 )
F_153 ( V_155 ) ;
V_155 -> V_53 -> V_169 = V_35 ;
V_155 -> V_53 = V_35 ;
V_155 -> V_164 += V_35 -> V_40 ;
V_155 -> V_170 = F_154 ( V_155 -> V_170 , F_155 ( V_35 ) ) ;
F_1 ( V_155 , 0 ) ;
F_156 ( V_12 , V_155 , V_35 ) ;
return true ;
}
static bool F_157 ( struct V_11 * V_12 ,
struct V_1 * V_155 , struct V_35 * V_35 )
{
const int V_167 = V_35 -> V_124 & V_168 ;
if ( ! F_158 ( V_12 , V_155 , V_35 ) )
return false ;
F_159 ( V_12 , V_35 ) ;
if ( ( V_155 -> V_43 & V_168 ) != V_167 )
F_153 ( V_155 ) ;
V_35 -> V_169 = V_155 -> V_35 ;
V_155 -> V_35 = V_35 ;
V_155 -> V_54 = F_149 ( V_35 ) ;
V_155 -> V_23 = V_35 -> V_46 ;
V_155 -> V_164 += V_35 -> V_40 ;
V_155 -> V_170 = F_154 ( V_155 -> V_170 , F_155 ( V_35 ) ) ;
F_1 ( V_155 , 0 ) ;
F_156 ( V_12 , V_155 , V_35 ) ;
return true ;
}
static bool F_160 ( struct V_171 * V_172 , struct V_11 * V_12 ,
struct V_35 * V_35 , unsigned int * V_173 )
{
struct V_174 * V_175 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_175 = V_172 -> V_175 ;
if ( ! V_175 )
goto V_134;
* V_173 = 0 ;
F_161 (rq, &plug->list, queuelist) {
int V_176 ;
( * V_173 ) ++ ;
if ( V_2 -> V_12 != V_12 )
continue;
V_176 = F_162 ( V_2 , V_35 ) ;
if ( V_176 == V_177 ) {
V_20 = F_150 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_176 == V_178 ) {
V_20 = F_157 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_134:
return V_20 ;
}
void F_163 ( struct V_1 * V_155 , struct V_35 * V_35 )
{
V_155 -> V_7 = V_35 -> V_179 ;
V_155 -> V_52 = V_180 ;
V_155 -> V_43 |= V_35 -> V_124 & V_181 ;
if ( V_35 -> V_124 & V_182 )
V_155 -> V_43 |= V_168 ;
V_155 -> V_183 = 0 ;
V_155 -> V_23 = V_35 -> V_46 ;
V_155 -> V_170 = F_155 ( V_35 ) ;
F_164 ( V_155 -> V_12 , V_155 , V_35 ) ;
}
static int V_111 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_123 = ! ! ( V_35 -> V_124 & V_184 ) ;
struct V_174 * V_175 ;
int V_176 , V_127 , V_143 = V_185 ;
struct V_1 * V_155 ;
unsigned int V_173 = 0 ;
F_125 ( V_12 , & V_35 ) ;
if ( V_35 -> V_124 & ( V_125 | V_126 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_143 = V_186 ;
goto V_187;
}
if ( F_160 ( V_188 , V_12 , V_35 , & V_173 ) )
goto V_134;
F_36 ( V_12 -> V_59 ) ;
V_176 = F_165 ( V_12 , & V_155 , V_35 ) ;
if ( V_176 == V_177 ) {
if ( F_150 ( V_12 , V_155 , V_35 ) ) {
if ( ! F_166 ( V_12 , V_155 ) )
F_167 ( V_12 , V_155 , V_176 ) ;
goto V_189;
}
} else if ( V_176 == V_178 ) {
if ( F_157 ( V_12 , V_155 , V_35 ) ) {
if ( ! F_168 ( V_12 , V_155 ) )
F_167 ( V_12 , V_155 , V_176 ) ;
goto V_189;
}
}
V_187:
V_127 = F_122 ( V_35 ) ;
if ( V_123 )
V_127 |= V_184 ;
V_155 = F_113 ( V_12 , V_127 , V_35 ) ;
F_163 ( V_155 , V_35 ) ;
if ( F_23 ( V_190 , & V_12 -> V_109 ) ||
F_169 ( V_35 , V_191 ) )
V_155 -> V_7 = F_170 () ;
V_175 = V_188 -> V_175 ;
if ( V_175 ) {
if ( F_146 ( & V_175 -> V_192 ) )
F_171 ( V_12 ) ;
else if ( ! V_175 -> V_193 ) {
struct V_1 * V_194 ;
V_194 = F_172 ( V_175 -> V_192 . V_195 ) ;
if ( V_194 -> V_12 != V_12 )
V_175 -> V_193 = 1 ;
}
if ( V_173 >= V_196 )
F_173 ( V_175 , false ) ;
F_174 ( & V_155 -> V_21 , & V_175 -> V_192 ) ;
F_1 ( V_155 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_136 ( V_12 , V_155 , V_143 ) ;
F_37 ( V_12 ) ;
V_189:
F_38 ( V_12 -> V_59 ) ;
}
V_134:
return 0 ;
}
static inline void F_175 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_197 ;
if ( F_176 ( V_35 ) && V_19 != V_19 -> V_198 ) {
struct V_4 * V_199 = V_19 -> V_200 ;
V_35 -> V_46 += V_199 -> V_201 ;
V_35 -> V_197 = V_19 -> V_198 ;
F_177 ( F_15 ( V_35 -> V_197 ) , V_35 ,
V_19 -> V_202 ,
V_35 -> V_46 - V_199 -> V_201 ) ;
}
}
static void F_178 ( struct V_35 * V_35 )
{
char V_203 [ V_204 ] ;
F_25 ( V_50 L_10 ) ;
F_25 ( V_50 L_11 ,
F_179 ( V_35 -> V_197 , V_203 ) ,
V_35 -> V_124 ,
( unsigned long long ) V_35 -> V_46 + F_176 ( V_35 ) ,
( long long ) ( F_180 ( V_35 -> V_197 -> V_205 ) >> 9 ) ) ;
F_26 ( V_206 , & V_35 -> V_38 ) ;
}
static int T_4 F_181 ( char * V_207 )
{
return F_182 ( & V_208 , V_207 ) ;
}
static bool F_183 ( struct V_4 * V_5 , unsigned int V_209 )
{
return V_5 -> V_210 && F_184 ( & V_208 , V_209 ) ;
}
static int T_4 F_185 ( void )
{
struct V_211 * V_212 = F_186 ( L_12 ,
NULL , & V_208 ) ;
return F_187 ( V_212 ) ? F_188 ( V_212 ) : 0 ;
}
static inline bool F_183 ( struct V_4 * V_5 ,
unsigned int V_209 )
{
return false ;
}
static inline int F_189 ( struct V_35 * V_35 , unsigned int V_213 )
{
V_24 V_214 ;
if ( ! V_213 )
return 0 ;
V_214 = F_180 ( V_35 -> V_197 -> V_205 ) >> 9 ;
if ( V_214 ) {
V_24 V_215 = V_35 -> V_46 ;
if ( V_214 < V_213 || V_214 - V_213 < V_215 ) {
F_178 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static inline void F_190 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
V_24 V_216 ;
int V_20 , V_213 = F_176 ( V_35 ) ;
T_5 V_217 ;
int V_88 = - V_39 ;
F_191 () ;
if ( F_189 ( V_35 , V_213 ) )
goto V_218;
V_216 = - 1 ;
V_217 = 0 ;
do {
char V_203 [ V_204 ] ;
struct V_4 * V_5 ;
V_12 = F_15 ( V_35 -> V_197 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_13
L_14 ,
F_179 ( V_35 -> V_197 , V_203 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_218;
}
if ( F_24 ( ! ( V_35 -> V_124 & V_219 ) &&
V_213 > F_192 ( V_12 ) ) ) {
F_25 ( V_41 L_15 ,
F_179 ( V_35 -> V_197 , V_203 ) ,
F_176 ( V_35 ) ,
F_192 ( V_12 ) ) ;
goto V_218;
}
if ( F_24 ( F_23 ( V_69 , & V_12 -> V_109 ) ) )
goto V_218;
V_5 = V_35 -> V_197 -> V_200 ;
if ( F_183 ( V_5 , V_35 -> V_40 ) ||
F_183 ( & F_142 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_218;
F_175 ( V_35 ) ;
if ( F_193 ( V_35 ) && F_194 ( V_35 ) )
goto V_218;
if ( V_216 != - 1 )
F_177 ( V_12 , V_35 , V_217 , V_216 ) ;
V_216 = V_35 -> V_46 ;
V_217 = V_35 -> V_197 -> V_202 ;
if ( F_189 ( V_35 , V_213 ) )
goto V_218;
if ( ( V_35 -> V_124 & ( V_125 | V_126 ) ) && ! V_12 -> V_220 ) {
V_35 -> V_124 &= ~ ( V_125 | V_126 ) ;
if ( ! V_213 ) {
V_88 = 0 ;
goto V_218;
}
}
if ( ( V_35 -> V_124 & V_219 ) &&
( ! F_195 ( V_12 ) ||
( ( V_35 -> V_124 & V_221 ) &&
! F_196 ( V_12 ) ) ) ) {
V_88 = - V_222 ;
goto V_218;
}
if ( F_197 ( V_12 , & V_35 ) )
goto V_218;
if ( ! V_35 )
break;
F_198 ( V_12 , V_35 ) ;
V_20 = V_12 -> V_223 ( V_12 , V_35 ) ;
} while ( V_20 );
return;
V_218:
F_29 ( V_35 , V_88 ) ;
}
void F_199 ( struct V_35 * V_35 )
{
struct V_224 V_225 ;
if ( V_188 -> V_224 ) {
F_200 ( V_188 -> V_224 , V_35 ) ;
return;
}
F_120 ( V_35 -> V_169 ) ;
F_201 ( & V_225 ) ;
V_188 -> V_224 = & V_225 ;
do {
F_190 ( V_35 ) ;
V_35 = F_202 ( V_188 -> V_224 ) ;
} while ( V_35 );
V_188 -> V_224 = NULL ;
}
void F_203 ( int V_6 , struct V_35 * V_35 )
{
int V_74 = F_176 ( V_35 ) ;
V_35 -> V_124 |= V_6 ;
if ( F_204 ( V_35 ) && ! ( V_6 & V_219 ) ) {
if ( V_6 & V_140 ) {
F_205 ( V_226 , V_74 ) ;
} else {
F_206 ( V_35 -> V_40 ) ;
F_205 ( V_227 , V_74 ) ;
}
if ( F_24 ( V_228 ) ) {
char V_203 [ V_204 ] ;
F_25 ( V_229 L_16 ,
V_188 -> V_230 , F_207 ( V_188 ) ,
( V_6 & V_140 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_46 ,
F_179 ( V_35 -> V_197 , V_203 ) ,
V_74 ) ;
}
}
F_199 ( V_35 ) ;
}
int F_208 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_219 )
return 0 ;
if ( F_31 ( V_2 ) > F_209 ( V_12 ) ||
F_33 ( V_2 ) > F_192 ( V_12 ) << 9 ) {
F_25 ( V_41 L_19 , V_42 ) ;
return - V_39 ;
}
F_210 ( V_2 ) ;
if ( V_2 -> V_166 > F_211 ( V_12 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_212 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_143 = V_147 ;
if ( F_208 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_183 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_120 ( F_134 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_125 | V_126 ) )
V_143 = V_186 ;
F_136 ( V_12 , V_2 , V_143 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_213 ( const struct V_1 * V_2 )
{
unsigned int V_167 = V_2 -> V_43 & V_168 ;
unsigned int V_209 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_231 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_169 ) {
if ( ( V_35 -> V_124 & V_167 ) != V_167 )
break;
V_209 += V_35 -> V_40 ;
}
F_120 ( F_33 ( V_2 ) && ! V_209 ) ;
return V_209 ;
}
static void F_214 ( struct V_1 * V_155 , unsigned int V_209 )
{
if ( F_3 ( V_155 ) ) {
const int V_6 = F_2 ( V_155 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_155 -> V_5 ;
F_215 ( V_7 , V_5 , V_232 [ V_6 ] , V_209 >> 9 ) ;
F_12 () ;
}
}
static void F_216 ( struct V_1 * V_155 )
{
if ( F_3 ( V_155 ) && ! ( V_155 -> V_43 & V_47 ) ) {
unsigned long V_233 = V_34 - V_155 -> V_33 ;
const int V_6 = F_2 ( V_155 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_155 -> V_5 ;
F_5 ( V_7 , V_5 , V_234 [ V_6 ] ) ;
F_215 ( V_7 , V_5 , V_235 [ V_6 ] , V_233 ) ;
F_10 ( V_7 , V_5 ) ;
F_217 ( V_5 , V_6 ) ;
F_218 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_219 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_220 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_236 ) ) {
if ( V_2 -> V_43 & V_237 )
F_221 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_236 ;
F_222 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_238 || V_12 -> V_238 == V_2 ) {
V_12 -> V_239 = F_223 ( V_2 ) ;
V_12 -> V_238 = NULL ;
}
if ( V_2 -> V_43 & V_240 )
break;
if ( V_12 -> V_241 && F_33 ( V_2 ) ) {
V_2 -> V_166 ++ ;
}
if ( ! V_12 -> V_107 )
break;
V_20 = V_12 -> V_107 ( V_12 , V_2 ) ;
if ( V_20 == V_242 ) {
break;
} else if ( V_20 == V_243 ) {
if ( V_12 -> V_241 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_240 ) ) {
-- V_2 -> V_166 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_244 ) {
V_2 -> V_43 |= V_44 ;
F_224 ( V_2 ) ;
F_225 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_21 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_226 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_120 ( F_146 ( & V_2 -> V_21 ) ) ;
F_120 ( F_227 ( V_2 ) ) ;
F_228 ( & V_2 -> V_21 ) ;
if ( F_229 ( V_2 ) ) {
V_12 -> V_245 [ F_145 ( V_2 ) ] ++ ;
F_230 ( V_2 ) ;
}
}
void F_224 ( struct V_1 * V_155 )
{
F_226 ( V_155 ) ;
V_155 -> V_165 = F_33 ( V_155 ) ;
if ( F_24 ( F_231 ( V_155 ) ) )
V_155 -> V_246 -> V_165 = F_33 ( V_155 -> V_246 ) ;
F_232 ( V_155 ) ;
}
struct V_1 * F_233 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_219 ( V_12 ) ;
if ( V_2 )
F_224 ( V_2 ) ;
return V_2 ;
}
bool F_234 ( struct V_1 * V_155 , int error , unsigned int V_247 )
{
int V_248 , V_249 , V_250 = 0 ;
struct V_35 * V_35 ;
if ( ! V_155 -> V_35 )
return false ;
F_235 ( V_155 -> V_12 , V_155 ) ;
if ( V_155 -> V_52 == V_180 )
V_155 -> V_183 = 0 ;
if ( error && V_155 -> V_52 == V_180 &&
! ( V_155 -> V_43 & V_44 ) ) {
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
V_251 , V_155 -> V_9 ? V_155 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_155 ) ) ;
}
F_214 ( V_155 , V_247 ) ;
V_248 = V_249 = 0 ;
while ( ( V_35 = V_155 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_247 >= V_35 -> V_40 ) {
V_155 -> V_35 = V_35 -> V_169 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_155 , V_35 , V_36 , error ) ;
V_250 = 0 ;
V_249 = 0 ;
} else {
int V_255 = V_35 -> V_256 + V_250 ;
if ( F_24 ( V_255 >= V_35 -> V_162 ) ) {
F_30 ( V_155 , L_27 ) ;
F_25 ( V_41 L_28 ,
V_42 , V_255 , V_35 -> V_162 ) ;
break;
}
V_36 = F_236 ( V_35 , V_255 ) -> V_161 ;
F_237 ( V_36 > V_35 -> V_40 ) ;
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
V_35 = V_155 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_247 <= 0 ) )
break;
}
}
if ( ! V_155 -> V_35 ) {
V_155 -> V_164 = 0 ;
return false ;
}
if ( V_249 ) {
F_21 ( V_155 , V_35 , V_249 , error ) ;
V_35 -> V_256 += V_250 ;
F_238 ( V_35 ) -> V_160 += V_247 ;
F_238 ( V_35 ) -> V_161 -= V_247 ;
}
V_155 -> V_164 -= V_248 ;
V_155 -> V_54 = F_149 ( V_155 -> V_35 ) ;
if ( V_155 -> V_52 == V_180 || ( V_155 -> V_43 & V_219 ) )
V_155 -> V_23 += V_248 >> 9 ;
if ( V_155 -> V_43 & V_231 ) {
V_155 -> V_43 &= ~ V_168 ;
V_155 -> V_43 |= V_155 -> V_35 -> V_124 & V_168 ;
}
if ( F_33 ( V_155 ) < F_239 ( V_155 ) ) {
F_30 ( V_155 , L_29 ) ;
V_155 -> V_164 = F_239 ( V_155 ) ;
}
F_210 ( V_155 ) ;
return true ;
}
static bool F_240 ( struct V_1 * V_2 , int error ,
unsigned int V_247 ,
unsigned int V_257 )
{
if ( F_234 ( V_2 , error , V_247 ) )
return true ;
if ( F_24 ( F_231 ( V_2 ) ) &&
F_234 ( V_2 -> V_246 , error , V_257 ) )
return true ;
if ( F_241 ( V_2 -> V_12 ) )
F_242 ( V_2 -> V_9 ) ;
return false ;
}
void F_243 ( struct V_1 * V_155 )
{
struct V_11 * V_12 = V_155 -> V_12 ;
V_155 -> V_43 &= ~ V_240 ;
if ( V_12 -> V_108 )
V_12 -> V_108 ( V_12 , V_155 ) ;
}
static void F_244 ( struct V_1 * V_155 , int error )
{
if ( F_132 ( V_155 ) )
F_133 ( V_155 -> V_12 , V_155 ) ;
F_120 ( F_134 ( V_155 ) ) ;
if ( F_24 ( V_258 ) && V_155 -> V_52 == V_180 )
F_245 ( & V_155 -> V_12 -> V_17 ) ;
F_129 ( V_155 ) ;
if ( V_155 -> V_43 & V_240 )
F_243 ( V_155 ) ;
F_216 ( V_155 ) ;
if ( V_155 -> V_218 )
V_155 -> V_218 ( V_155 , error ) ;
else {
if ( F_231 ( V_155 ) )
F_143 ( V_155 -> V_246 -> V_12 , V_155 -> V_246 ) ;
F_143 ( V_155 -> V_12 , V_155 ) ;
}
}
static bool F_246 ( struct V_1 * V_2 , int error ,
unsigned int V_247 , unsigned int V_257 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_240 ( V_2 , error , V_247 , V_257 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_244 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_247 ( struct V_1 * V_2 , int error ,
unsigned int V_247 , unsigned int V_257 )
{
if ( F_240 ( V_2 , error , V_247 , V_257 ) )
return true ;
F_244 ( V_2 , error ) ;
return false ;
}
bool F_248 ( struct V_1 * V_2 , int error , unsigned int V_247 )
{
return F_246 ( V_2 , error , V_247 , 0 ) ;
}
void F_249 ( struct V_1 * V_2 , int error )
{
bool V_259 ;
unsigned int V_257 = 0 ;
if ( F_24 ( F_231 ( V_2 ) ) )
V_257 = F_33 ( V_2 -> V_246 ) ;
V_259 = F_246 ( V_2 , error , F_33 ( V_2 ) , V_257 ) ;
F_120 ( V_259 ) ;
}
bool F_250 ( struct V_1 * V_2 , int error )
{
return F_248 ( V_2 , error , F_239 ( V_2 ) ) ;
}
bool F_251 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_248 ( V_2 , error , F_213 ( V_2 ) ) ;
}
bool F_252 ( struct V_1 * V_2 , int error , unsigned int V_247 )
{
return F_247 ( V_2 , error , V_247 , 0 ) ;
}
void F_225 ( struct V_1 * V_2 , int error )
{
bool V_259 ;
unsigned int V_257 = 0 ;
if ( F_24 ( F_231 ( V_2 ) ) )
V_257 = F_33 ( V_2 -> V_246 ) ;
V_259 = F_247 ( V_2 , error , F_33 ( V_2 ) , V_257 ) ;
F_120 ( V_259 ) ;
}
bool F_253 ( struct V_1 * V_2 , int error )
{
return F_252 ( V_2 , error , F_239 ( V_2 ) ) ;
}
bool F_254 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_252 ( V_2 , error , F_213 ( V_2 ) ) ;
}
void F_164 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_124 & V_260 ;
if ( F_204 ( V_35 ) ) {
V_2 -> V_166 = F_255 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_149 ( V_35 ) ;
}
V_2 -> V_164 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_197 )
V_2 -> V_9 = V_35 -> V_197 -> V_261 ;
}
void F_256 ( struct V_1 * V_2 )
{
struct V_262 V_263 ;
struct V_264 * V_265 ;
F_257 (bvec, rq, iter)
F_258 ( V_265 -> V_159 ) ;
}
int F_259 ( struct V_11 * V_12 )
{
if ( V_12 -> V_266 )
return V_12 -> V_266 ( V_12 ) ;
return 0 ;
}
void F_260 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_169 ;
F_261 ( V_35 ) ;
}
}
static void F_262 ( struct V_1 * V_267 , struct V_1 * V_268 )
{
V_267 -> V_7 = V_268 -> V_7 ;
V_267 -> V_43 = ( V_268 -> V_43 & V_269 ) | V_270 ;
V_267 -> V_52 = V_268 -> V_52 ;
V_267 -> V_23 = F_7 ( V_268 ) ;
V_267 -> V_164 = F_33 ( V_268 ) ;
V_267 -> V_166 = V_268 -> V_166 ;
V_267 -> V_170 = V_268 -> V_170 ;
V_267 -> V_271 = V_268 -> V_271 ;
}
int F_263 ( struct V_1 * V_2 , struct V_1 * V_272 ,
struct V_273 * V_274 , T_1 V_86 ,
int (* F_264)( struct V_35 * , struct V_35 * , void * ) ,
void * V_145 )
{
struct V_35 * V_35 , * V_275 ;
if ( ! V_274 )
V_274 = V_276 ;
F_16 ( NULL , V_2 ) ;
F_265 (bio_src, rq_src) {
V_35 = F_266 ( V_86 , V_275 -> V_277 , V_274 ) ;
if ( ! V_35 )
goto V_278;
F_267 ( V_35 , V_275 ) ;
if ( F_27 ( V_275 ) &&
F_268 ( V_35 , V_275 , V_86 , V_274 ) )
goto V_278;
if ( F_264 && F_264 ( V_35 , V_275 , V_145 ) )
goto V_278;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_169 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_262 ( V_2 , V_272 ) ;
return 0 ;
V_278:
if ( V_35 )
F_269 ( V_35 , V_274 ) ;
F_260 ( V_2 ) ;
return - V_85 ;
}
int F_270 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_271 ( V_61 , V_57 ) ;
}
int F_272 ( struct V_11 * V_12 ,
struct V_279 * V_280 , unsigned long V_281 )
{
return F_40 ( V_61 , V_280 , V_281 ) ;
}
void F_273 ( struct V_174 * V_175 )
{
struct V_171 * V_172 = V_188 ;
V_175 -> V_282 = V_283 ;
F_17 ( & V_175 -> V_192 ) ;
F_17 ( & V_175 -> V_284 ) ;
V_175 -> V_193 = 0 ;
if ( ! V_172 -> V_175 ) {
V_172 -> V_175 = V_175 ;
}
}
static int F_274 ( void * V_115 , struct V_285 * V_286 , struct V_285 * V_203 )
{
struct V_1 * V_287 = F_35 ( V_286 , struct V_1 , V_21 ) ;
struct V_1 * V_288 = F_35 ( V_203 , struct V_1 , V_21 ) ;
return ! ( V_287 -> V_12 <= V_288 -> V_12 ) ;
}
static void F_275 ( struct V_11 * V_12 , unsigned int V_289 ,
bool V_290 )
__releases( V_12 -> V_59 )
{
F_276 ( V_12 , V_289 , ! V_290 ) ;
if ( V_290 ) {
F_277 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_277 ( V_12 -> V_59 ) ;
}
}
static void F_278 ( struct V_174 * V_175 )
{
F_279 ( V_291 ) ;
if ( F_146 ( & V_175 -> V_284 ) )
return;
F_280 ( & V_175 -> V_284 , & V_291 ) ;
while ( ! F_146 ( & V_291 ) ) {
struct V_292 * V_293 = F_281 ( & V_291 ,
struct V_292 ,
V_192 ) ;
F_282 ( & V_293 -> V_192 ) ;
V_293 -> V_294 ( V_293 ) ;
}
}
void F_173 ( struct V_174 * V_175 , bool V_290 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_279 ( V_192 ) ;
unsigned int V_289 ;
F_120 ( V_175 -> V_282 != V_283 ) ;
F_278 ( V_175 ) ;
if ( F_146 ( & V_175 -> V_192 ) )
return;
F_280 ( & V_175 -> V_192 , & V_192 ) ;
if ( V_175 -> V_193 ) {
F_283 ( NULL , & V_192 , F_274 ) ;
V_175 -> V_193 = 0 ;
}
V_12 = NULL ;
V_289 = 0 ;
F_284 ( V_65 ) ;
while ( ! F_146 ( & V_192 ) ) {
V_2 = F_172 ( V_192 . V_295 ) ;
F_228 ( & V_2 -> V_21 ) ;
F_120 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_275 ( V_12 , V_289 , V_290 ) ;
V_12 = V_2 -> V_12 ;
V_289 = 0 ;
F_285 ( V_12 -> V_59 ) ;
}
if ( V_2 -> V_43 & ( V_125 | V_126 ) )
F_137 ( V_12 , V_2 , V_186 ) ;
else
F_137 ( V_12 , V_2 , V_296 ) ;
V_289 ++ ;
}
if ( V_12 )
F_275 ( V_12 , V_289 , V_290 ) ;
F_286 ( V_65 ) ;
}
void F_287 ( struct V_174 * V_175 )
{
F_173 ( V_175 , false ) ;
if ( V_175 == V_188 -> V_175 )
V_188 -> V_175 = NULL ;
}
int T_4 F_288 ( void )
{
F_289 ( V_297 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_290 ( L_30 ,
V_298 | V_299 , 0 ) ;
if ( ! V_61 )
F_291 ( L_31 ) ;
V_83 = F_292 ( L_32 ,
sizeof( struct V_1 ) , 0 , V_300 , NULL ) ;
V_89 = F_292 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_300 , NULL ) ;
return 0 ;
}
