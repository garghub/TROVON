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
bool V_68 = false ;
int V_69 ;
F_36 ( V_12 -> V_59 ) ;
F_61 ( V_12 ) ;
if ( V_67 )
F_62 ( V_12 ) ;
if ( ! F_63 ( & V_12 -> V_70 ) )
F_37 ( V_12 ) ;
V_68 |= V_12 -> V_2 . V_71 ;
if ( V_67 ) {
V_68 |= ! F_63 ( & V_12 -> V_70 ) ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
V_68 |= V_12 -> V_2 . V_72 [ V_69 ] ;
V_68 |= V_12 -> V_73 [ V_69 ] ;
V_68 |= ! F_63 ( & V_12 -> V_74 [ V_69 ] ) ;
}
}
F_38 ( V_12 -> V_59 ) ;
if ( ! V_68 )
break;
F_64 ( 10 ) ;
}
}
void F_65 ( struct V_11 * V_12 )
{
T_1 * V_75 = V_12 -> V_59 ;
F_66 ( & V_12 -> V_76 ) ;
F_67 ( V_77 , V_12 ) ;
F_36 ( V_75 ) ;
F_48 ( V_78 , V_12 ) ;
F_48 ( V_79 , V_12 ) ;
F_48 ( V_77 , V_12 ) ;
if ( V_12 -> V_59 != & V_12 -> V_80 )
V_12 -> V_59 = & V_12 -> V_80 ;
F_38 ( V_75 ) ;
F_68 ( & V_12 -> V_76 ) ;
if ( V_12 -> V_81 )
F_60 ( V_12 , true ) ;
F_50 ( & V_12 -> V_17 . V_82 ) ;
F_49 ( V_12 ) ;
F_58 ( V_12 ) ;
}
static int F_69 ( struct V_11 * V_12 )
{
struct V_83 * V_84 = & V_12 -> V_2 ;
if ( F_24 ( V_84 -> V_85 ) )
return 0 ;
V_84 -> V_72 [ V_86 ] = V_84 -> V_72 [ V_87 ] = 0 ;
V_84 -> V_88 [ V_86 ] = V_84 -> V_88 [ V_87 ] = 0 ;
V_84 -> V_71 = 0 ;
F_70 ( & V_84 -> V_89 [ V_86 ] ) ;
F_70 ( & V_84 -> V_89 [ V_87 ] ) ;
V_84 -> V_85 = F_71 ( V_90 , V_91 ,
V_92 , V_93 , V_12 -> V_94 ) ;
if ( ! V_84 -> V_85 )
return - V_95 ;
return 0 ;
}
struct V_11 * F_72 ( T_2 V_96 )
{
return F_73 ( V_96 , - 1 ) ;
}
struct V_11 * F_73 ( T_2 V_96 , int V_97 )
{
struct V_11 * V_12 ;
int V_98 ;
V_12 = F_74 ( V_99 ,
V_96 | V_100 , V_97 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_101 = F_75 ( & V_102 , 0 , 0 , V_96 ) ;
if ( V_12 -> V_101 < 0 )
goto V_103;
V_12 -> V_17 . V_104 =
( V_105 * 1024 ) / V_106 ;
V_12 -> V_17 . V_107 = 0 ;
V_12 -> V_17 . V_108 = V_109 ;
V_12 -> V_17 . V_110 = L_9 ;
V_12 -> V_94 = V_97 ;
V_98 = F_76 ( & V_12 -> V_17 ) ;
if ( V_98 )
goto V_111;
if ( F_77 ( V_12 ) )
goto V_111;
F_78 ( & V_12 -> V_17 . V_82 ,
V_112 , ( unsigned long ) V_12 ) ;
F_78 ( & V_12 -> V_63 , V_113 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_22 ) ;
F_17 ( & V_12 -> V_114 ) ;
F_17 ( & V_12 -> V_74 [ 0 ] ) ;
F_17 ( & V_12 -> V_74 [ 1 ] ) ;
F_17 ( & V_12 -> V_115 ) ;
F_79 ( & V_12 -> V_58 , F_34 ) ;
F_80 ( & V_12 -> V_66 , & V_116 ) ;
F_81 ( & V_12 -> V_76 ) ;
F_82 ( & V_12 -> V_80 ) ;
V_12 -> V_59 = & V_12 -> V_80 ;
return V_12 ;
V_111:
F_83 ( & V_102 , V_12 -> V_101 ) ;
V_103:
F_84 ( V_99 , V_12 ) ;
return NULL ;
}
struct V_11 * F_85 ( T_3 * V_117 , T_1 * V_75 )
{
return F_86 ( V_117 , V_75 , - 1 ) ;
}
struct V_11 *
F_86 ( T_3 * V_117 , T_1 * V_75 , int V_97 )
{
struct V_11 * V_118 , * V_12 ;
V_118 = F_73 ( V_119 , V_97 ) ;
if ( ! V_118 )
return NULL ;
V_12 = F_87 ( V_118 , V_117 , V_75 ) ;
if ( ! V_12 )
F_65 ( V_118 ) ;
return V_12 ;
}
struct V_11 *
F_87 ( struct V_11 * V_12 , T_3 * V_117 ,
T_1 * V_75 )
{
if ( ! V_12 )
return NULL ;
if ( F_69 ( V_12 ) )
return NULL ;
V_12 -> V_64 = V_117 ;
V_12 -> V_120 = NULL ;
V_12 -> V_121 = NULL ;
V_12 -> V_122 = V_123 ;
if ( V_75 )
V_12 -> V_59 = V_75 ;
F_88 ( V_12 , V_124 ) ;
V_12 -> V_125 = V_126 ;
if ( ! F_89 ( V_12 , NULL ) ) {
F_13 ( V_12 ) ;
return V_12 ;
}
return NULL ;
}
bool F_90 ( struct V_11 * V_12 )
{
if ( F_54 ( ! F_91 ( V_12 ) ) ) {
F_92 ( V_12 ) ;
return true ;
}
return false ;
}
static inline void F_93 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_127 ) {
F_94 ( V_12 , V_2 ) ;
if ( V_2 -> V_128 . V_129 )
F_95 ( V_2 -> V_128 . V_129 -> V_130 ) ;
}
F_96 ( V_2 , V_12 -> V_2 . V_85 ) ;
}
static struct V_1 *
F_97 ( struct V_11 * V_12 , struct V_131 * V_129 ,
unsigned int V_65 , T_2 V_96 )
{
struct V_1 * V_2 = F_98 ( V_12 -> V_2 . V_85 , V_96 ) ;
if ( ! V_2 )
return NULL ;
F_16 ( V_12 , V_2 ) ;
V_2 -> V_43 = V_65 | V_132 ;
if ( V_65 & V_127 ) {
V_2 -> V_128 . V_129 = V_129 ;
if ( F_24 ( F_99 ( V_12 , V_2 , V_96 ) ) ) {
F_96 ( V_2 , V_12 -> V_2 . V_85 ) ;
return NULL ;
}
if ( V_129 )
F_100 ( V_129 -> V_130 ) ;
}
return V_2 ;
}
static inline int F_101 ( struct V_11 * V_12 , struct V_133 * V_130 )
{
if ( ! V_130 )
return 0 ;
return V_130 -> V_134 == V_12 -> V_135 ||
( V_130 -> V_134 > 0
&& F_102 ( V_34 , V_130 -> V_136 + V_137 ) ) ;
}
static void F_103 ( struct V_11 * V_12 , struct V_133 * V_130 )
{
if ( ! V_130 || F_101 ( V_12 , V_130 ) )
return;
V_130 -> V_134 = V_12 -> V_135 ;
V_130 -> V_136 = V_34 ;
}
static void F_104 ( struct V_11 * V_12 , int V_138 )
{
struct V_83 * V_84 = & V_12 -> V_2 ;
if ( V_84 -> V_72 [ V_138 ] < F_105 ( V_12 ) )
F_106 ( V_12 , V_138 ) ;
if ( V_84 -> V_72 [ V_138 ] + 1 <= V_12 -> V_14 ) {
if ( F_107 ( & V_84 -> V_89 [ V_138 ] ) )
F_108 ( & V_84 -> V_89 [ V_138 ] ) ;
F_109 ( V_12 , V_138 ) ;
}
}
static void F_110 ( struct V_11 * V_12 , unsigned int V_65 )
{
struct V_83 * V_84 = & V_12 -> V_2 ;
int V_138 = F_111 ( V_65 ) ;
V_84 -> V_72 [ V_138 ] -- ;
if ( V_65 & V_127 )
V_84 -> V_71 -- ;
F_104 ( V_12 , V_138 ) ;
if ( F_24 ( V_84 -> V_88 [ V_138 ^ 1 ] ) )
F_104 ( V_12 , V_138 ^ 1 ) ;
}
static bool F_112 ( struct V_35 * V_35 )
{
if ( ! V_35 )
return true ;
if ( V_35 -> V_139 & ( V_140 | V_141 ) )
return false ;
return true ;
}
static struct V_1 * F_113 ( struct V_11 * V_12 , int V_142 ,
struct V_35 * V_35 , T_2 V_96 )
{
struct V_1 * V_2 = NULL ;
struct V_83 * V_84 = & V_12 -> V_2 ;
struct V_143 * V_144 ;
struct V_133 * V_130 ;
struct V_131 * V_129 = NULL ;
const bool V_145 = F_111 ( V_142 ) != 0 ;
bool V_146 = false ;
int V_147 ;
V_148:
V_144 = V_12 -> V_81 -> type ;
V_130 = V_149 -> V_133 ;
if ( F_24 ( F_91 ( V_12 ) ) )
return NULL ;
V_147 = F_114 ( V_12 , V_142 ) ;
if ( V_147 == V_150 )
goto V_151;
if ( V_84 -> V_72 [ V_145 ] + 1 >= F_115 ( V_12 ) ) {
if ( V_84 -> V_72 [ V_145 ] + 1 >= V_12 -> V_14 ) {
if ( ! V_130 && ! V_146 ) {
F_38 ( V_12 -> V_59 ) ;
F_116 ( V_149 , V_96 , V_12 -> V_94 ) ;
F_36 ( V_12 -> V_59 ) ;
V_146 = true ;
goto V_148;
}
if ( ! F_117 ( V_12 , V_145 ) ) {
F_103 ( V_12 , V_130 ) ;
F_118 ( V_12 , V_145 ) ;
} else {
if ( V_147 != V_152
&& ! F_101 ( V_12 , V_130 ) ) {
goto V_153;
}
}
}
F_119 ( V_12 , V_145 ) ;
}
if ( V_84 -> V_72 [ V_145 ] >= ( 3 * V_12 -> V_14 / 2 ) )
goto V_153;
V_84 -> V_72 [ V_145 ] ++ ;
V_84 -> V_88 [ V_145 ] = 0 ;
if ( F_112 ( V_35 ) &&
! F_23 ( V_154 , & V_12 -> V_122 ) ) {
V_142 |= V_127 ;
V_84 -> V_71 ++ ;
if ( V_144 -> V_155 && V_130 )
V_129 = F_120 ( V_130 , V_12 ) ;
}
if ( F_121 ( V_12 ) )
V_142 |= V_156 ;
F_38 ( V_12 -> V_59 ) ;
if ( ( V_142 & V_127 ) && F_24 ( V_144 -> V_155 && ! V_129 ) ) {
V_129 = F_122 ( V_12 , V_96 ) ;
if ( ! V_129 )
goto V_157;
}
V_2 = F_97 ( V_12 , V_129 , V_142 , V_96 ) ;
V_157:
if ( F_24 ( ! V_2 ) ) {
F_36 ( V_12 -> V_59 ) ;
F_110 ( V_12 , V_142 ) ;
V_151:
if ( F_24 ( V_84 -> V_72 [ V_145 ] == 0 ) )
V_84 -> V_88 [ V_145 ] = 1 ;
goto V_153;
}
if ( F_101 ( V_12 , V_130 ) )
V_130 -> V_134 -- ;
F_123 ( V_12 , V_35 , V_142 & 1 ) ;
V_153:
return V_2 ;
}
static struct V_1 * F_124 ( struct V_11 * V_12 , int V_142 ,
struct V_35 * V_35 )
{
const bool V_145 = F_111 ( V_142 ) != 0 ;
struct V_1 * V_2 ;
V_2 = F_113 ( V_12 , V_142 , V_35 , V_158 ) ;
while ( ! V_2 ) {
F_125 ( V_89 ) ;
struct V_83 * V_84 = & V_12 -> V_2 ;
if ( F_24 ( F_91 ( V_12 ) ) )
return NULL ;
F_126 ( & V_84 -> V_89 [ V_145 ] , & V_89 ,
V_159 ) ;
F_127 ( V_12 , V_35 , V_142 & 1 ) ;
F_38 ( V_12 -> V_59 ) ;
F_128 () ;
F_116 ( V_149 , V_158 , V_12 -> V_94 ) ;
F_103 ( V_12 , V_149 -> V_133 ) ;
F_36 ( V_12 -> V_59 ) ;
F_129 ( & V_84 -> V_89 [ V_145 ] , & V_89 ) ;
V_2 = F_113 ( V_12 , V_142 , V_35 , V_158 ) ;
} ;
return V_2 ;
}
struct V_1 * F_130 ( struct V_11 * V_12 , int V_6 , T_2 V_96 )
{
struct V_1 * V_2 ;
F_131 ( V_6 != V_160 && V_6 != V_161 ) ;
F_36 ( V_12 -> V_59 ) ;
if ( V_96 & V_162 )
V_2 = F_124 ( V_12 , V_6 , NULL ) ;
else
V_2 = F_113 ( V_12 , V_6 , NULL , V_96 ) ;
if ( ! V_2 )
F_38 ( V_12 -> V_59 ) ;
return V_2 ;
}
struct V_1 * F_132 ( struct V_11 * V_12 , struct V_35 * V_35 ,
T_2 V_96 )
{
struct V_1 * V_2 = F_130 ( V_12 , F_133 ( V_35 ) , V_96 ) ;
if ( F_24 ( ! V_2 ) )
return F_134 ( - V_95 ) ;
F_135 (bio) {
struct V_35 * V_163 = V_35 ;
int V_20 ;
F_136 ( V_12 , & V_163 ) ;
V_20 = F_137 ( V_12 , V_2 , V_163 ) ;
if ( F_24 ( V_20 ) ) {
F_138 ( V_2 ) ;
return F_134 ( V_20 ) ;
}
}
return V_2 ;
}
void F_139 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
F_142 ( V_12 , V_2 ) ;
if ( F_143 ( V_2 ) )
F_144 ( V_12 , V_2 ) ;
F_131 ( F_145 ( V_2 ) ) ;
F_146 ( V_12 , V_2 ) ;
}
static void F_147 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_164 )
{
F_1 ( V_2 , 1 ) ;
F_148 ( V_12 , V_2 , V_164 ) ;
}
static void F_149 ( int V_7 , struct V_4 * V_5 ,
unsigned long V_165 )
{
if ( V_165 == V_5 -> V_166 )
return;
if ( F_150 ( V_5 ) ) {
F_151 ( V_7 , V_5 , V_167 ,
F_150 ( V_5 ) * ( V_165 - V_5 -> V_166 ) ) ;
F_151 ( V_7 , V_5 , V_168 , ( V_165 - V_5 -> V_166 ) ) ;
}
V_5 -> V_166 = V_165 ;
}
void F_10 ( int V_7 , struct V_4 * V_5 )
{
unsigned long V_165 = V_34 ;
if ( V_5 -> V_169 )
F_149 ( V_7 , & F_152 ( V_5 ) -> V_10 , V_165 ) ;
F_149 ( V_7 , V_5 , V_165 ) ;
}
void F_153 ( struct V_11 * V_12 , struct V_1 * V_170 )
{
if ( F_24 ( ! V_12 ) )
return;
if ( F_24 ( -- V_170 -> V_32 ) )
return;
F_154 ( V_12 , V_170 ) ;
F_43 ( V_170 -> V_35 != NULL ) ;
if ( V_170 -> V_43 & V_132 ) {
unsigned int V_65 = V_170 -> V_43 ;
F_131 ( ! F_63 ( & V_170 -> V_21 ) ) ;
F_131 ( ! F_155 ( & V_170 -> V_25 ) ) ;
F_93 ( V_12 , V_170 ) ;
F_110 ( V_12 , V_65 ) ;
}
}
void F_138 ( struct V_1 * V_170 )
{
unsigned long V_65 ;
struct V_11 * V_12 = V_170 -> V_12 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_153 ( V_12 , V_170 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
}
void F_156 ( struct V_1 * V_2 , struct V_171 * V_171 ,
unsigned int V_172 )
{
struct V_35 * V_35 = V_2 -> V_35 ;
V_35 -> V_173 -> V_174 = V_171 ;
V_35 -> V_173 -> V_175 = 0 ;
V_35 -> V_173 -> V_176 = V_172 ;
V_35 -> V_40 = V_172 ;
V_35 -> V_177 = 1 ;
V_35 -> V_178 = 1 ;
V_2 -> V_179 = V_2 -> V_180 = V_172 ;
V_2 -> V_181 = 1 ;
V_2 -> V_54 = F_157 ( V_35 ) ;
}
static bool F_158 ( struct V_11 * V_12 , struct V_1 * V_170 ,
struct V_35 * V_35 )
{
const int V_182 = V_35 -> V_139 & V_183 ;
if ( ! F_159 ( V_12 , V_170 , V_35 ) )
return false ;
F_160 ( V_12 , V_35 ) ;
if ( ( V_170 -> V_43 & V_183 ) != V_182 )
F_161 ( V_170 ) ;
V_170 -> V_53 -> V_184 = V_35 ;
V_170 -> V_53 = V_35 ;
V_170 -> V_179 += V_35 -> V_40 ;
V_170 -> V_185 = F_162 ( V_170 -> V_185 , F_163 ( V_35 ) ) ;
F_1 ( V_170 , 0 ) ;
return true ;
}
static bool F_164 ( struct V_11 * V_12 ,
struct V_1 * V_170 , struct V_35 * V_35 )
{
const int V_182 = V_35 -> V_139 & V_183 ;
if ( ! F_165 ( V_12 , V_170 , V_35 ) )
return false ;
F_166 ( V_12 , V_35 ) ;
if ( ( V_170 -> V_43 & V_183 ) != V_182 )
F_161 ( V_170 ) ;
V_35 -> V_184 = V_170 -> V_35 ;
V_170 -> V_35 = V_35 ;
V_170 -> V_54 = F_157 ( V_35 ) ;
V_170 -> V_23 = V_35 -> V_46 ;
V_170 -> V_179 += V_35 -> V_40 ;
V_170 -> V_185 = F_162 ( V_170 -> V_185 , F_163 ( V_35 ) ) ;
F_1 ( V_170 , 0 ) ;
return true ;
}
static bool F_167 ( struct V_11 * V_12 , struct V_35 * V_35 ,
unsigned int * V_186 )
{
struct V_187 * V_188 ;
struct V_1 * V_2 ;
bool V_20 = false ;
V_188 = V_149 -> V_188 ;
if ( ! V_188 )
goto V_153;
* V_186 = 0 ;
F_168 (rq, &plug->list, queuelist) {
int V_189 ;
if ( V_2 -> V_12 == V_12 )
( * V_186 ) ++ ;
if ( V_2 -> V_12 != V_12 || ! F_169 ( V_2 , V_35 ) )
continue;
V_189 = F_170 ( V_2 , V_35 ) ;
if ( V_189 == V_190 ) {
V_20 = F_158 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
} else if ( V_189 == V_191 ) {
V_20 = F_164 ( V_12 , V_2 , V_35 ) ;
if ( V_20 )
break;
}
}
V_153:
return V_20 ;
}
void F_171 ( struct V_1 * V_170 , struct V_35 * V_35 )
{
V_170 -> V_52 = V_192 ;
V_170 -> V_43 |= V_35 -> V_139 & V_193 ;
if ( V_35 -> V_139 & V_194 )
V_170 -> V_43 |= V_183 ;
V_170 -> V_195 = 0 ;
V_170 -> V_23 = V_35 -> V_46 ;
V_170 -> V_185 = F_163 ( V_35 ) ;
F_172 ( V_170 -> V_12 , V_170 , V_35 ) ;
}
void V_124 ( struct V_11 * V_12 , struct V_35 * V_35 )
{
const bool V_138 = ! ! ( V_35 -> V_139 & V_196 ) ;
struct V_187 * V_188 ;
int V_189 , V_142 , V_164 = V_197 ;
struct V_1 * V_170 ;
unsigned int V_186 = 0 ;
F_136 ( V_12 , & V_35 ) ;
if ( V_35 -> V_139 & ( V_140 | V_141 ) ) {
F_36 ( V_12 -> V_59 ) ;
V_164 = V_198 ;
goto V_199;
}
if ( F_167 ( V_12 , V_35 , & V_186 ) )
return;
F_36 ( V_12 -> V_59 ) ;
V_189 = F_173 ( V_12 , & V_170 , V_35 ) ;
if ( V_189 == V_190 ) {
if ( F_158 ( V_12 , V_170 , V_35 ) ) {
F_174 ( V_12 , V_170 , V_35 ) ;
if ( ! F_175 ( V_12 , V_170 ) )
F_176 ( V_12 , V_170 , V_189 ) ;
goto V_200;
}
} else if ( V_189 == V_191 ) {
if ( F_164 ( V_12 , V_170 , V_35 ) ) {
F_174 ( V_12 , V_170 , V_35 ) ;
if ( ! F_177 ( V_12 , V_170 ) )
F_176 ( V_12 , V_170 , V_189 ) ;
goto V_200;
}
}
V_199:
V_142 = F_133 ( V_35 ) ;
if ( V_138 )
V_142 |= V_196 ;
V_170 = F_124 ( V_12 , V_142 , V_35 ) ;
if ( F_24 ( ! V_170 ) ) {
F_29 ( V_35 , - V_201 ) ;
goto V_200;
}
F_171 ( V_170 , V_35 ) ;
if ( F_23 ( V_202 , & V_12 -> V_122 ) )
V_170 -> V_7 = F_178 () ;
V_188 = V_149 -> V_188 ;
if ( V_188 ) {
if ( F_63 ( & V_188 -> V_203 ) )
F_179 ( V_12 ) ;
else {
if ( ! V_188 -> V_204 ) {
struct V_1 * V_205 ;
V_205 = F_180 ( V_188 -> V_203 . V_206 ) ;
if ( V_205 -> V_12 != V_12 )
V_188 -> V_204 = 1 ;
}
if ( V_186 >= V_207 ) {
F_181 ( V_188 , false ) ;
F_179 ( V_12 ) ;
}
}
F_182 ( & V_170 -> V_21 , & V_188 -> V_203 ) ;
F_1 ( V_170 , 1 ) ;
} else {
F_36 ( V_12 -> V_59 ) ;
F_147 ( V_12 , V_170 , V_164 ) ;
F_37 ( V_12 ) ;
V_200:
F_38 ( V_12 -> V_59 ) ;
}
}
static inline void F_183 ( struct V_35 * V_35 )
{
struct V_18 * V_19 = V_35 -> V_208 ;
if ( F_184 ( V_35 ) && V_19 != V_19 -> V_209 ) {
struct V_4 * V_210 = V_19 -> V_211 ;
V_35 -> V_46 += V_210 -> V_212 ;
V_35 -> V_208 = V_19 -> V_209 ;
F_185 ( F_15 ( V_35 -> V_208 ) , V_35 ,
V_19 -> V_213 ,
V_35 -> V_46 - V_210 -> V_212 ) ;
}
}
static void F_186 ( struct V_35 * V_35 )
{
char V_214 [ V_215 ] ;
F_25 ( V_50 L_10 ) ;
F_25 ( V_50 L_11 ,
F_187 ( V_35 -> V_208 , V_214 ) ,
V_35 -> V_139 ,
( unsigned long long ) V_35 -> V_46 + F_184 ( V_35 ) ,
( long long ) ( F_188 ( V_35 -> V_208 -> V_216 ) >> 9 ) ) ;
F_26 ( V_217 , & V_35 -> V_38 ) ;
}
static int T_4 F_189 ( char * V_218 )
{
return F_190 ( & V_219 , V_218 ) ;
}
static bool F_191 ( struct V_4 * V_5 , unsigned int V_220 )
{
return V_5 -> V_221 && F_192 ( & V_219 , V_220 ) ;
}
static int T_4 F_193 ( void )
{
struct V_222 * V_223 = F_194 ( L_12 ,
NULL , & V_219 ) ;
return F_195 ( V_223 ) ? F_196 ( V_223 ) : 0 ;
}
static inline bool F_191 ( struct V_4 * V_5 ,
unsigned int V_220 )
{
return false ;
}
static inline int F_197 ( struct V_35 * V_35 , unsigned int V_224 )
{
V_24 V_225 ;
if ( ! V_224 )
return 0 ;
V_225 = F_188 ( V_35 -> V_208 -> V_216 ) >> 9 ;
if ( V_225 ) {
V_24 V_226 = V_35 -> V_46 ;
if ( V_225 < V_224 || V_225 - V_224 < V_226 ) {
F_186 ( V_35 ) ;
return 1 ;
}
}
return 0 ;
}
static T_5 bool
F_198 ( struct V_35 * V_35 )
{
struct V_11 * V_12 ;
int V_224 = F_184 ( V_35 ) ;
int V_98 = - V_39 ;
char V_214 [ V_215 ] ;
struct V_4 * V_5 ;
F_199 () ;
if ( F_197 ( V_35 , V_224 ) )
goto V_227;
V_12 = F_15 ( V_35 -> V_208 ) ;
if ( F_24 ( ! V_12 ) ) {
F_25 ( V_41
L_13
L_14 ,
F_187 ( V_35 -> V_208 , V_214 ) ,
( long long ) V_35 -> V_46 ) ;
goto V_227;
}
if ( F_24 ( ! ( V_35 -> V_139 & V_228 ) &&
V_224 > F_200 ( V_12 ) ) ) {
F_25 ( V_41 L_15 ,
F_187 ( V_35 -> V_208 , V_214 ) ,
F_184 ( V_35 ) ,
F_200 ( V_12 ) ) ;
goto V_227;
}
V_5 = V_35 -> V_208 -> V_211 ;
if ( F_191 ( V_5 , V_35 -> V_40 ) ||
F_191 ( & F_152 ( V_5 ) -> V_10 ,
V_35 -> V_40 ) )
goto V_227;
F_183 ( V_35 ) ;
if ( F_201 ( V_35 ) && F_202 ( V_35 ) )
goto V_227;
if ( F_197 ( V_35 , V_224 ) )
goto V_227;
if ( ( V_35 -> V_139 & ( V_140 | V_141 ) ) && ! V_12 -> V_229 ) {
V_35 -> V_139 &= ~ ( V_140 | V_141 ) ;
if ( ! V_224 ) {
V_98 = 0 ;
goto V_227;
}
}
if ( ( V_35 -> V_139 & V_228 ) &&
( ! F_203 ( V_12 ) ||
( ( V_35 -> V_139 & V_230 ) &&
! F_204 ( V_12 ) ) ) ) {
V_98 = - V_231 ;
goto V_227;
}
if ( F_205 ( V_12 , V_35 ) )
return false ;
F_206 ( V_12 , V_35 ) ;
return true ;
V_227:
F_29 ( V_35 , V_98 ) ;
return false ;
}
void F_207 ( struct V_35 * V_35 )
{
struct V_232 V_233 ;
if ( ! F_198 ( V_35 ) )
return;
if ( V_149 -> V_232 ) {
F_208 ( V_149 -> V_232 , V_35 ) ;
return;
}
F_131 ( V_35 -> V_184 ) ;
F_209 ( & V_233 ) ;
V_149 -> V_232 = & V_233 ;
do {
struct V_11 * V_12 = F_15 ( V_35 -> V_208 ) ;
V_12 -> V_234 ( V_12 , V_35 ) ;
V_35 = F_210 ( V_149 -> V_232 ) ;
} while ( V_35 );
V_149 -> V_232 = NULL ;
}
void F_211 ( int V_6 , struct V_35 * V_35 )
{
int V_72 = F_184 ( V_35 ) ;
V_35 -> V_139 |= V_6 ;
if ( F_212 ( V_35 ) && ! ( V_6 & V_228 ) ) {
if ( V_6 & V_161 ) {
F_213 ( V_235 , V_72 ) ;
} else {
F_214 ( V_35 -> V_40 ) ;
F_213 ( V_236 , V_72 ) ;
}
if ( F_24 ( V_237 ) ) {
char V_214 [ V_215 ] ;
F_25 ( V_238 L_16 ,
V_149 -> V_239 , F_215 ( V_149 ) ,
( V_6 & V_161 ) ? L_17 : L_18 ,
( unsigned long long ) V_35 -> V_46 ,
F_187 ( V_35 -> V_208 , V_214 ) ,
V_72 ) ;
}
}
F_207 ( V_35 ) ;
}
int F_216 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_228 )
return 0 ;
if ( F_31 ( V_2 ) > F_217 ( V_12 ) ||
F_33 ( V_2 ) > F_200 ( V_12 ) << 9 ) {
F_25 ( V_41 L_19 , V_42 ) ;
return - V_39 ;
}
F_218 ( V_2 ) ;
if ( V_2 -> V_181 > F_219 ( V_12 ) ) {
F_25 ( V_41 L_20 , V_42 ) ;
return - V_39 ;
}
return 0 ;
}
int F_220 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
unsigned long V_65 ;
int V_164 = V_240 ;
if ( F_216 ( V_12 , V_2 ) )
return - V_39 ;
if ( V_2 -> V_9 &&
F_191 ( & V_2 -> V_9 -> V_10 , F_33 ( V_2 ) ) )
return - V_39 ;
F_56 ( V_12 -> V_59 , V_65 ) ;
if ( F_24 ( F_91 ( V_12 ) ) ) {
F_57 ( V_12 -> V_59 , V_65 ) ;
return - V_201 ;
}
F_131 ( F_145 ( V_2 ) ) ;
if ( V_2 -> V_43 & ( V_140 | V_141 ) )
V_164 = V_198 ;
F_147 ( V_12 , V_2 , V_164 ) ;
if ( V_164 == V_198 )
F_37 ( V_12 ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return 0 ;
}
unsigned int F_221 ( const struct V_1 * V_2 )
{
unsigned int V_182 = V_2 -> V_43 & V_183 ;
unsigned int V_220 = 0 ;
struct V_35 * V_35 ;
if ( ! ( V_2 -> V_43 & V_241 ) )
return F_33 ( V_2 ) ;
for ( V_35 = V_2 -> V_35 ; V_35 ; V_35 = V_35 -> V_184 ) {
if ( ( V_35 -> V_139 & V_182 ) != V_182 )
break;
V_220 += V_35 -> V_40 ;
}
F_131 ( F_33 ( V_2 ) && ! V_220 ) ;
return V_220 ;
}
static void F_222 ( struct V_1 * V_170 , unsigned int V_220 )
{
if ( F_3 ( V_170 ) ) {
const int V_6 = F_2 ( V_170 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_170 -> V_5 ;
F_223 ( V_7 , V_5 , V_242 [ V_6 ] , V_220 >> 9 ) ;
F_12 () ;
}
}
static void F_224 ( struct V_1 * V_170 )
{
if ( F_3 ( V_170 ) && ! ( V_170 -> V_43 & V_47 ) ) {
unsigned long V_243 = V_34 - V_170 -> V_33 ;
const int V_6 = F_2 ( V_170 ) ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_4 () ;
V_5 = V_170 -> V_5 ;
F_5 ( V_7 , V_5 , V_244 [ V_6 ] ) ;
F_223 ( V_7 , V_5 , V_245 [ V_6 ] , V_243 ) ;
F_10 ( V_7 , V_5 ) ;
F_225 ( V_5 , V_6 ) ;
F_226 ( V_5 ) ;
F_12 () ;
}
}
struct V_1 * F_227 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
int V_20 ;
while ( ( V_2 = F_228 ( V_12 ) ) != NULL ) {
if ( ! ( V_2 -> V_43 & V_246 ) ) {
if ( V_2 -> V_43 & V_247 )
F_229 ( V_12 , V_2 ) ;
V_2 -> V_43 |= V_246 ;
F_230 ( V_12 , V_2 ) ;
}
if ( ! V_12 -> V_248 || V_12 -> V_248 == V_2 ) {
V_12 -> V_249 = F_231 ( V_2 ) ;
V_12 -> V_248 = NULL ;
}
if ( V_2 -> V_43 & V_250 )
break;
if ( V_12 -> V_251 && F_33 ( V_2 ) ) {
V_2 -> V_181 ++ ;
}
if ( ! V_12 -> V_120 )
break;
V_20 = V_12 -> V_120 ( V_12 , V_2 ) ;
if ( V_20 == V_252 ) {
break;
} else if ( V_20 == V_253 ) {
if ( V_12 -> V_251 && F_33 ( V_2 ) &&
! ( V_2 -> V_43 & V_250 ) ) {
-- V_2 -> V_181 ;
}
V_2 = NULL ;
break;
} else if ( V_20 == V_254 ) {
V_2 -> V_43 |= V_44 ;
F_232 ( V_2 ) ;
F_233 ( V_2 , - V_39 ) ;
} else {
F_25 ( V_41 L_21 , V_42 , V_20 ) ;
break;
}
}
return V_2 ;
}
void F_234 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
F_131 ( F_63 ( & V_2 -> V_21 ) ) ;
F_131 ( F_235 ( V_2 ) ) ;
F_236 ( & V_2 -> V_21 ) ;
if ( F_237 ( V_2 ) ) {
V_12 -> V_73 [ F_238 ( V_2 ) ] ++ ;
F_239 ( V_2 ) ;
}
}
void F_232 ( struct V_1 * V_170 )
{
F_234 ( V_170 ) ;
V_170 -> V_180 = F_33 ( V_170 ) ;
if ( F_24 ( F_240 ( V_170 ) ) )
V_170 -> V_255 -> V_180 = F_33 ( V_170 -> V_255 ) ;
F_241 ( V_170 ) ;
}
struct V_1 * F_242 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_227 ( V_12 ) ;
if ( V_2 )
F_232 ( V_2 ) ;
return V_2 ;
}
bool F_243 ( struct V_1 * V_170 , int error , unsigned int V_256 )
{
int V_257 , V_258 , V_259 = 0 ;
struct V_35 * V_35 ;
if ( ! V_170 -> V_35 )
return false ;
F_244 ( V_170 -> V_12 , V_170 ) ;
if ( V_170 -> V_52 == V_192 )
V_170 -> V_195 = 0 ;
if ( error && V_170 -> V_52 == V_192 &&
! ( V_170 -> V_43 & V_44 ) ) {
char * V_260 ;
switch ( error ) {
case - V_261 :
V_260 = L_22 ;
break;
case - V_262 :
V_260 = L_23 ;
break;
case - V_263 :
V_260 = L_24 ;
break;
case - V_39 :
default:
V_260 = L_25 ;
break;
}
F_25 ( V_41 L_26 ,
V_260 , V_170 -> V_9 ? V_170 -> V_9 -> V_51 : L_3 ,
( unsigned long long ) F_7 ( V_170 ) ) ;
}
F_222 ( V_170 , V_256 ) ;
V_257 = V_258 = 0 ;
while ( ( V_35 = V_170 -> V_35 ) != NULL ) {
int V_36 ;
if ( V_256 >= V_35 -> V_40 ) {
V_170 -> V_35 = V_35 -> V_184 ;
V_36 = V_35 -> V_40 ;
F_21 ( V_170 , V_35 , V_36 , error ) ;
V_259 = 0 ;
V_258 = 0 ;
} else {
int V_264 = V_35 -> V_265 + V_259 ;
if ( F_24 ( V_264 >= V_35 -> V_177 ) ) {
F_30 ( V_170 , L_27 ) ;
F_25 ( V_41 L_28 ,
V_42 , V_264 , V_35 -> V_177 ) ;
break;
}
V_36 = F_245 ( V_35 , V_264 ) -> V_176 ;
F_246 ( V_36 > V_35 -> V_40 ) ;
if ( F_24 ( V_36 > V_256 ) ) {
V_258 += V_256 ;
V_257 += V_256 ;
break;
}
V_259 ++ ;
V_258 += V_36 ;
}
V_257 += V_36 ;
V_256 -= V_36 ;
V_35 = V_170 -> V_35 ;
if ( V_35 ) {
if ( F_24 ( V_256 <= 0 ) )
break;
}
}
if ( ! V_170 -> V_35 ) {
V_170 -> V_179 = 0 ;
return false ;
}
if ( V_258 ) {
F_21 ( V_170 , V_35 , V_258 , error ) ;
V_35 -> V_265 += V_259 ;
F_247 ( V_35 ) -> V_175 += V_256 ;
F_247 ( V_35 ) -> V_176 -= V_256 ;
}
V_170 -> V_179 -= V_257 ;
V_170 -> V_54 = F_157 ( V_170 -> V_35 ) ;
if ( V_170 -> V_52 == V_192 || ( V_170 -> V_43 & V_228 ) )
V_170 -> V_23 += V_257 >> 9 ;
if ( V_170 -> V_43 & V_241 ) {
V_170 -> V_43 &= ~ V_183 ;
V_170 -> V_43 |= V_170 -> V_35 -> V_139 & V_183 ;
}
if ( F_33 ( V_170 ) < F_248 ( V_170 ) ) {
F_30 ( V_170 , L_29 ) ;
V_170 -> V_179 = F_248 ( V_170 ) ;
}
F_218 ( V_170 ) ;
return true ;
}
static bool F_249 ( struct V_1 * V_2 , int error ,
unsigned int V_256 ,
unsigned int V_266 )
{
if ( F_243 ( V_2 , error , V_256 ) )
return true ;
if ( F_24 ( F_240 ( V_2 ) ) &&
F_243 ( V_2 -> V_255 , error , V_266 ) )
return true ;
if ( F_250 ( V_2 -> V_12 ) )
F_251 ( V_2 -> V_9 ) ;
return false ;
}
void F_252 ( struct V_1 * V_170 )
{
struct V_11 * V_12 = V_170 -> V_12 ;
V_170 -> V_43 &= ~ V_250 ;
if ( V_12 -> V_121 )
V_12 -> V_121 ( V_12 , V_170 ) ;
}
static void F_253 ( struct V_1 * V_170 , int error )
{
if ( F_143 ( V_170 ) )
F_144 ( V_170 -> V_12 , V_170 ) ;
F_131 ( F_145 ( V_170 ) ) ;
if ( F_24 ( V_267 ) && V_170 -> V_52 == V_192 )
F_254 ( & V_170 -> V_12 -> V_17 ) ;
F_140 ( V_170 ) ;
if ( V_170 -> V_43 & V_250 )
F_252 ( V_170 ) ;
F_224 ( V_170 ) ;
if ( V_170 -> V_227 )
V_170 -> V_227 ( V_170 , error ) ;
else {
if ( F_240 ( V_170 ) )
F_153 ( V_170 -> V_255 -> V_12 , V_170 -> V_255 ) ;
F_153 ( V_170 -> V_12 , V_170 ) ;
}
}
static bool F_255 ( struct V_1 * V_2 , int error ,
unsigned int V_256 , unsigned int V_266 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned long V_65 ;
if ( F_249 ( V_2 , error , V_256 , V_266 ) )
return true ;
F_56 ( V_12 -> V_59 , V_65 ) ;
F_253 ( V_2 , error ) ;
F_57 ( V_12 -> V_59 , V_65 ) ;
return false ;
}
bool F_256 ( struct V_1 * V_2 , int error ,
unsigned int V_256 , unsigned int V_266 )
{
if ( F_249 ( V_2 , error , V_256 , V_266 ) )
return true ;
F_253 ( V_2 , error ) ;
return false ;
}
bool F_257 ( struct V_1 * V_2 , int error , unsigned int V_256 )
{
return F_255 ( V_2 , error , V_256 , 0 ) ;
}
void F_258 ( struct V_1 * V_2 , int error )
{
bool V_268 ;
unsigned int V_266 = 0 ;
if ( F_24 ( F_240 ( V_2 ) ) )
V_266 = F_33 ( V_2 -> V_255 ) ;
V_268 = F_255 ( V_2 , error , F_33 ( V_2 ) , V_266 ) ;
F_131 ( V_268 ) ;
}
bool F_259 ( struct V_1 * V_2 , int error )
{
return F_257 ( V_2 , error , F_248 ( V_2 ) ) ;
}
bool F_260 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_257 ( V_2 , error , F_221 ( V_2 ) ) ;
}
bool F_261 ( struct V_1 * V_2 , int error , unsigned int V_256 )
{
return F_256 ( V_2 , error , V_256 , 0 ) ;
}
void F_233 ( struct V_1 * V_2 , int error )
{
bool V_268 ;
unsigned int V_266 = 0 ;
if ( F_24 ( F_240 ( V_2 ) ) )
V_266 = F_33 ( V_2 -> V_255 ) ;
V_268 = F_256 ( V_2 , error , F_33 ( V_2 ) , V_266 ) ;
F_131 ( V_268 ) ;
}
bool F_262 ( struct V_1 * V_2 , int error )
{
return F_261 ( V_2 , error , F_248 ( V_2 ) ) ;
}
bool F_263 ( struct V_1 * V_2 , int error )
{
F_43 ( error >= 0 ) ;
return F_261 ( V_2 , error , F_221 ( V_2 ) ) ;
}
void F_172 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_35 * V_35 )
{
V_2 -> V_43 |= V_35 -> V_139 & V_269 ;
if ( F_212 ( V_35 ) ) {
V_2 -> V_181 = F_264 ( V_12 , V_35 ) ;
V_2 -> V_54 = F_157 ( V_35 ) ;
}
V_2 -> V_179 = V_35 -> V_40 ;
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
if ( V_35 -> V_208 )
V_2 -> V_9 = V_35 -> V_208 -> V_270 ;
}
void F_265 ( struct V_1 * V_2 )
{
struct V_271 V_272 ;
struct V_273 * V_274 ;
F_266 (bvec, rq, iter)
F_267 ( V_274 -> V_174 ) ;
}
int F_268 ( struct V_11 * V_12 )
{
if ( V_12 -> V_275 )
return V_12 -> V_275 ( V_12 ) ;
return 0 ;
}
void F_269 ( struct V_1 * V_2 )
{
struct V_35 * V_35 ;
while ( ( V_35 = V_2 -> V_35 ) != NULL ) {
V_2 -> V_35 = V_35 -> V_184 ;
F_270 ( V_35 ) ;
}
}
static void F_271 ( struct V_1 * V_276 , struct V_1 * V_277 )
{
V_276 -> V_7 = V_277 -> V_7 ;
V_276 -> V_43 = ( V_277 -> V_43 & V_278 ) | V_279 ;
V_276 -> V_52 = V_277 -> V_52 ;
V_276 -> V_23 = F_7 ( V_277 ) ;
V_276 -> V_179 = F_33 ( V_277 ) ;
V_276 -> V_181 = V_277 -> V_181 ;
V_276 -> V_185 = V_277 -> V_185 ;
V_276 -> V_280 = V_277 -> V_280 ;
}
int F_272 ( struct V_1 * V_2 , struct V_1 * V_281 ,
struct V_282 * V_283 , T_2 V_96 ,
int (* F_273)( struct V_35 * , struct V_35 * , void * ) ,
void * V_284 )
{
struct V_35 * V_35 , * V_285 ;
if ( ! V_283 )
V_283 = V_286 ;
F_16 ( NULL , V_2 ) ;
F_274 (bio_src, rq_src) {
V_35 = F_275 ( V_96 , V_285 -> V_287 , V_283 ) ;
if ( ! V_35 )
goto V_288;
F_276 ( V_35 , V_285 ) ;
if ( F_27 ( V_285 ) &&
F_277 ( V_35 , V_285 , V_96 , V_283 ) )
goto V_288;
if ( F_273 && F_273 ( V_35 , V_285 , V_284 ) )
goto V_288;
if ( V_2 -> V_35 ) {
V_2 -> V_53 -> V_184 = V_35 ;
V_2 -> V_53 = V_35 ;
} else
V_2 -> V_35 = V_2 -> V_53 = V_35 ;
}
F_271 ( V_2 , V_281 ) ;
return 0 ;
V_288:
if ( V_35 )
F_278 ( V_35 , V_283 ) ;
F_269 ( V_2 ) ;
return - V_95 ;
}
int F_279 ( struct V_11 * V_12 , struct V_56 * V_57 )
{
return F_280 ( V_61 , V_57 ) ;
}
int F_281 ( struct V_11 * V_12 ,
struct V_289 * V_290 , unsigned long V_291 )
{
return F_40 ( V_61 , V_290 , V_291 ) ;
}
void F_282 ( struct V_187 * V_188 )
{
struct V_292 * V_293 = V_149 ;
V_188 -> V_294 = V_295 ;
F_17 ( & V_188 -> V_203 ) ;
F_17 ( & V_188 -> V_296 ) ;
V_188 -> V_204 = 0 ;
if ( ! V_293 -> V_188 ) {
V_293 -> V_188 = V_188 ;
}
}
static int F_283 ( void * V_297 , struct V_298 * V_299 , struct V_298 * V_214 )
{
struct V_1 * V_300 = F_35 ( V_299 , struct V_1 , V_21 ) ;
struct V_1 * V_301 = F_35 ( V_214 , struct V_1 , V_21 ) ;
return ! ( V_300 -> V_12 <= V_301 -> V_12 ) ;
}
static void F_284 ( struct V_11 * V_12 , unsigned int V_302 ,
bool V_303 )
__releases( V_12 -> V_59 )
{
F_285 ( V_12 , V_302 , ! V_303 ) ;
if ( F_24 ( F_91 ( V_12 ) ) ) {
F_286 ( V_12 -> V_59 ) ;
return;
}
if ( V_303 ) {
F_286 ( V_12 -> V_59 ) ;
F_53 ( V_12 ) ;
} else {
F_37 ( V_12 ) ;
F_286 ( V_12 -> V_59 ) ;
}
}
static void F_287 ( struct V_187 * V_188 )
{
F_288 ( V_304 ) ;
if ( F_63 ( & V_188 -> V_296 ) )
return;
F_289 ( & V_188 -> V_296 , & V_304 ) ;
while ( ! F_63 ( & V_304 ) ) {
struct V_305 * V_306 = F_290 ( & V_304 ,
struct V_305 ,
V_203 ) ;
F_291 ( & V_306 -> V_203 ) ;
V_306 -> V_307 ( V_306 ) ;
}
}
void F_181 ( struct V_187 * V_188 , bool V_303 )
{
struct V_11 * V_12 ;
unsigned long V_65 ;
struct V_1 * V_2 ;
F_288 ( V_203 ) ;
unsigned int V_302 ;
F_131 ( V_188 -> V_294 != V_295 ) ;
F_287 ( V_188 ) ;
if ( F_63 ( & V_188 -> V_203 ) )
return;
F_289 ( & V_188 -> V_203 , & V_203 ) ;
if ( V_188 -> V_204 ) {
F_292 ( NULL , & V_203 , F_283 ) ;
V_188 -> V_204 = 0 ;
}
V_12 = NULL ;
V_302 = 0 ;
F_293 ( V_65 ) ;
while ( ! F_63 ( & V_203 ) ) {
V_2 = F_180 ( V_203 . V_308 ) ;
F_236 ( & V_2 -> V_21 ) ;
F_131 ( ! V_2 -> V_12 ) ;
if ( V_2 -> V_12 != V_12 ) {
if ( V_12 )
F_284 ( V_12 , V_302 , V_303 ) ;
V_12 = V_2 -> V_12 ;
V_302 = 0 ;
F_294 ( V_12 -> V_59 ) ;
}
if ( F_24 ( F_91 ( V_12 ) ) ) {
F_233 ( V_2 , - V_201 ) ;
continue;
}
if ( V_2 -> V_43 & ( V_140 | V_141 ) )
F_148 ( V_12 , V_2 , V_198 ) ;
else
F_148 ( V_12 , V_2 , V_309 ) ;
V_302 ++ ;
}
if ( V_12 )
F_284 ( V_12 , V_302 , V_303 ) ;
F_295 ( V_65 ) ;
}
void F_296 ( struct V_187 * V_188 )
{
F_181 ( V_188 , false ) ;
if ( V_188 == V_149 -> V_188 )
V_149 -> V_188 = NULL ;
}
int T_4 F_297 ( void )
{
F_298 ( V_310 > 8 *
sizeof( ( (struct V_1 * ) 0 ) -> V_43 ) ) ;
V_61 = F_299 ( L_30 ,
V_311 | V_312 , 0 ) ;
if ( ! V_61 )
F_300 ( L_31 ) ;
V_93 = F_301 ( L_32 ,
sizeof( struct V_1 ) , 0 , V_313 , NULL ) ;
V_99 = F_301 ( L_33 ,
sizeof( struct V_11 ) , 0 , V_313 , NULL ) ;
return 0 ;
}
