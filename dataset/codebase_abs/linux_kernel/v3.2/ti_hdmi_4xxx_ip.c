static inline void F_1 ( void T_1 * V_1 ,
const T_2 V_2 , T_3 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_3 F_3 ( void T_1 * V_1 ,
const T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void T_1 * F_5 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ;
}
static inline void T_1 * F_6 ( struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_7 ;
}
static inline void T_1 * F_7 ( struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_8 ;
}
static inline void T_1 * F_8 ( struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_9 ;
}
static inline void T_1 * F_9 ( struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_10 ;
}
static inline int F_10 ( void T_1 * V_1 ,
const T_2 V_2 ,
int V_11 , int V_12 , T_3 V_3 )
{
T_3 V_13 = 0 ;
while ( V_3 != F_11 ( V_1 , V_2 , V_11 , V_12 ) ) {
F_12 ( 1 ) ;
if ( V_13 ++ > 10000 )
return ! V_3 ;
}
return V_3 ;
}
static int F_13 ( struct V_4 * V_5 )
{
T_3 V_14 ;
void T_1 * V_15 = F_7 ( V_5 ) ;
struct V_16 * V_17 = & V_5 -> V_18 ;
F_14 ( V_15 , V_19 , 0x0 , 0 , 0 ) ;
V_14 = F_3 ( V_15 , V_20 ) ;
V_14 = F_15 ( V_14 , V_17 -> V_21 , 20 , 9 ) ;
V_14 = F_15 ( V_14 , V_17 -> V_22 - 1 , 8 , 1 ) ;
F_1 ( V_15 , V_20 , V_14 ) ;
V_14 = F_3 ( V_15 , V_23 ) ;
V_14 = F_15 ( V_14 , 0x0 , 12 , 12 ) ;
V_14 = F_15 ( V_14 , 0x1 , 13 , 13 ) ;
V_14 = F_15 ( V_14 , 0x0 , 14 , 14 ) ;
V_14 = F_15 ( V_14 , V_17 -> V_24 , 22 , 21 ) ;
if ( V_17 -> V_25 ) {
F_14 ( V_15 , V_26 , V_17 -> V_27 , 17 , 10 ) ;
V_14 = F_15 ( V_14 , 0x4 , 3 , 1 ) ;
} else {
V_14 = F_15 ( V_14 , 0x2 , 3 , 1 ) ;
}
F_1 ( V_15 , V_23 , V_14 ) ;
V_14 = F_3 ( V_15 , V_28 ) ;
V_14 = F_15 ( V_14 , V_17 -> V_29 , 24 , 18 ) ;
V_14 = F_15 ( V_14 , V_17 -> V_30 , 17 , 0 ) ;
F_1 ( V_15 , V_28 , V_14 ) ;
F_14 ( V_15 , V_31 , 0x1 , 0 , 0 ) ;
if ( F_10 ( V_15 , V_31 ,
0 , 0 , 1 ) != 1 ) {
F_16 ( L_1 ) ;
return - V_32 ;
}
if ( F_10 ( V_15 ,
V_33 , 1 , 1 , 1 ) != 1 ) {
F_16 ( L_2 ) ;
F_16 ( L_3 ,
F_3 ( V_15 , V_20 ) ) ;
F_16 ( L_4 ,
F_3 ( V_15 , V_23 ) ) ;
F_16 ( L_5 ,
F_3 ( V_15 , V_28 ) ) ;
return - V_32 ;
}
F_17 ( L_6 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , enum V_34 V_3 )
{
F_14 ( F_5 ( V_5 ) , V_35 , V_3 , 7 , 6 ) ;
if ( F_10 ( F_5 ( V_5 ) ,
V_35 , 5 , 4 , V_3 ) != V_3 ) {
F_16 ( L_7 , V_3 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , enum V_36 V_3 )
{
F_14 ( F_5 ( V_5 ) , V_35 , V_3 , 3 , 2 ) ;
if ( F_10 ( F_5 ( V_5 ) , V_35 ,
1 , 0 , V_3 ) != V_3 ) {
F_16 ( L_8 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
F_14 ( F_7 ( V_5 ) , V_19 , 0x0 , 3 , 3 ) ;
if ( F_10 ( F_7 ( V_5 ) ,
V_33 , 0 , 0 , 1 ) != 1 ) {
F_16 ( L_9 ) ;
return - V_32 ;
}
return 0 ;
}
int F_21 ( struct V_4 * V_5 )
{
T_2 V_14 = 0 ;
V_14 = F_19 ( V_5 , V_37 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_19 ( V_5 , V_38 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_20 ( V_5 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_13 ( V_5 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
void F_22 ( struct V_4 * V_5 )
{
F_19 ( V_5 , V_37 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
T_2 V_14 = 0 ;
void T_1 * V_39 = F_6 ( V_5 ) ;
V_14 = F_18 ( V_5 , V_40 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_18 ( V_5 , V_41 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_39 , V_42 ) ;
F_14 ( V_39 , V_42 , 0x1 , 31 , 30 ) ;
F_1 ( V_39 , V_43 , 0xF0000000 ) ;
F_14 ( V_39 , V_44 , 0xB , 3 , 0 ) ;
F_14 ( V_39 , V_45 , 0x1 , 27 , 27 ) ;
return 0 ;
}
void F_24 ( struct V_4 * V_5 )
{
F_18 ( V_5 , V_46 ) ;
}
static int F_25 ( struct V_4 * V_5 )
{
void T_1 * V_47 = F_9 ( V_5 ) ;
F_14 ( V_47 , V_48 , 0x7 , 2 , 0 ) ;
if ( F_11 ( V_47 , V_49 , 4 , 4 ) == 1 ) {
F_14 ( V_47 , V_50 , 0xf , 3 , 0 ) ;
if ( F_10 ( V_47 , V_49 ,
4 , 4 , 0 ) != 0 ) {
F_26 ( L_10 ) ;
return - V_32 ;
}
}
F_14 ( V_47 , V_50 , 0xA , 3 , 0 ) ;
if ( F_10 ( V_47 , V_49 ,
4 , 4 , 0 ) != 0 ) {
F_26 ( L_11 ) ;
return - V_32 ;
}
F_14 ( V_47 , V_50 , 0x9 , 3 , 0 ) ;
if ( F_10 ( V_47 , V_49 ,
4 , 4 , 0 ) != 0 ) {
F_26 ( L_12 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_27 ( struct V_4 * V_5 ,
T_4 * V_51 , int V_52 )
{
void T_1 * V_47 = F_9 ( V_5 ) ;
T_3 V_53 ;
char V_54 ;
T_3 V_55 = 0 ;
if ( F_10 ( V_47 , V_49 ,
4 , 4 , 0 ) != 0 ) {
F_26 ( L_13 ) ;
return - V_32 ;
}
if ( V_52 % 2 != 0 )
V_55 = 0x80 ;
F_14 ( V_47 , V_56 , V_52 / 2 , 7 , 0 ) ;
F_14 ( V_47 , V_57 , 0xA0 >> 1 , 7 , 1 ) ;
F_14 ( V_47 , V_58 , V_55 , 7 , 0 ) ;
F_14 ( V_47 , V_59 , 0x80 , 7 , 0 ) ;
F_14 ( V_47 , V_60 , 0x0 , 1 , 0 ) ;
if ( V_52 )
F_14 ( V_47 , V_50 , 0x4 , 3 , 0 ) ;
else
F_14 ( V_47 , V_50 , 0x2 , 3 , 0 ) ;
if ( F_11 ( V_47 , V_49 , 6 , 6 ) == 1 ) {
F_16 ( L_14 ) ;
return - V_61 ;
}
if ( F_11 ( V_47 , V_49 , 5 , 5 ) == 1 ) {
F_16 ( L_15 ) ;
return - V_61 ;
}
for ( V_53 = 0 ; V_53 < 0x80 ; ++ V_53 ) {
int V_13 ;
if ( F_11 ( V_47 , V_49 , 4 , 4 ) == 0 ) {
F_26 ( L_16 ) ;
return - V_61 ;
}
V_13 = 0 ;
while ( F_11 ( V_47 , V_49 , 2 , 2 ) == 1 ) {
if ( V_13 ++ > 10000 ) {
F_26 ( L_17 ) ;
return - V_32 ;
}
F_12 ( 1 ) ;
}
V_51 [ V_53 ] = F_11 ( V_47 , V_62 , 7 , 0 ) ;
}
V_54 = 0 ;
for ( V_53 = 0 ; V_53 < 0x80 ; ++ V_53 )
V_54 += V_51 [ V_53 ] ;
if ( V_54 != 0 ) {
F_16 ( L_18 ) ;
return - V_61 ;
}
return 0 ;
}
int F_28 ( struct V_4 * V_5 ,
T_4 * V_63 , int V_64 )
{
int V_14 , V_65 ;
if ( V_64 < 128 )
return - V_66 ;
V_14 = F_25 ( V_5 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_27 ( V_5 , V_63 , 0 ) ;
if ( V_14 )
return V_14 ;
V_65 = 128 ;
if ( V_64 >= 128 * 2 && V_63 [ 0x7e ] > 0 ) {
V_14 = F_27 ( V_5 , V_63 + 0x80 , 1 ) ;
if ( V_14 )
return V_14 ;
V_65 += 128 ;
}
return V_65 ;
}
bool F_29 ( struct V_4 * V_5 )
{
int V_14 ;
void T_1 * V_47 = F_9 ( V_5 ) ;
V_14 = F_11 ( V_47 , V_67 , 1 , 1 ) ;
return V_14 == 1 ;
}
static void F_30 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
F_17 ( L_19 ) ;
V_69 -> V_74 = V_75 ;
V_69 -> V_76 = V_77 ;
V_69 -> V_78 = V_79 ;
V_69 -> V_80 = V_81 ;
V_69 -> V_82 = V_83 ;
V_69 -> V_84 = V_85 ;
V_71 -> V_86 = 0 ;
V_71 -> V_87 = 0 ;
V_71 -> V_88 = 0 ;
V_71 -> V_89 = 0 ;
V_71 -> V_90 = 0 ;
V_71 -> V_91 = 0 ;
V_71 -> V_92 = 0 ;
V_71 -> V_93 = 0 ;
V_71 -> V_94 = 0 ;
V_71 -> V_95 = 0 ;
V_71 -> V_96 = 0 ;
V_71 -> V_97 = 0 ;
V_71 -> V_98 = 0 ;
V_71 -> V_99 = 0 ;
V_71 -> V_100 = 0 ;
V_71 -> V_101 = 0 ;
V_71 -> V_102 = 0 ;
V_73 -> V_103 = 0 ;
V_73 -> V_104 = 0 ;
V_73 -> V_105 = 0 ;
V_73 -> V_106 = 0 ;
V_73 -> V_107 = 0 ;
V_73 -> V_108 = 0 ;
V_73 -> V_109 = 0 ;
V_73 -> V_110 = 0 ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_17 ( L_20 ) ;
F_14 ( F_9 ( V_5 ) , V_111 , 0x0 , 0 , 0 ) ;
}
static void F_32 ( struct V_4 * V_5 )
{
F_17 ( L_21 ) ;
F_14 ( F_9 ( V_5 ) , V_112 , 0x0 , 0 , 0 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
F_17 ( L_22 ) ;
F_14 ( F_9 ( V_5 ) , V_112 , 0x1 , 0 , 0 ) ;
}
static void V_68 ( struct V_4 * V_5 ,
struct V_68 * V_113 )
{
T_3 V_14 = 0 ;
void T_1 * V_114 = F_9 ( V_5 ) ;
V_14 = F_3 ( V_114 , V_111 ) ;
V_14 = F_15 ( V_14 , V_115 , 5 , 5 ) ;
V_14 = F_15 ( V_14 , V_116 , 4 , 4 ) ;
V_14 = F_15 ( V_14 , V_117 , 2 , 2 ) ;
V_14 = F_15 ( V_14 , V_118 , 1 , 1 ) ;
F_1 ( V_114 , V_111 , V_14 ) ;
F_14 ( V_114 ,
V_119 , V_113 -> V_74 , 7 , 6 ) ;
V_14 = F_3 ( V_114 , V_120 ) ;
if ( V_113 -> V_76 > V_121 ) {
V_14 = F_15 ( V_14 , V_113 -> V_76 - 3 , 7 , 6 ) ;
V_14 = F_15 ( V_14 , 1 , 5 , 5 ) ;
} else {
V_14 = F_15 ( V_14 , V_113 -> V_76 , 7 , 6 ) ;
V_14 = F_15 ( V_14 , 0 , 5 , 5 ) ;
}
F_1 ( V_114 , V_120 , V_14 ) ;
V_14 = F_3 ( F_8 ( V_5 ) , V_122 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_78 , 6 , 6 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_80 , 5 , 3 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_82 , 0 , 0 ) ;
F_1 ( F_8 ( V_5 ) , V_122 , V_14 ) ;
F_14 ( V_114 ,
V_123 , V_113 -> V_84 , 6 , 5 ) ;
}
static void F_34 ( struct V_4 * V_5 ,
struct V_70 V_124 )
{
T_3 V_3 ;
char V_125 = 0 , V_54 = 0 ;
void T_1 * V_126 = F_8 ( V_5 ) ;
V_125 += 0x82 + 0x002 + 0x00D ;
F_1 ( V_126 , V_127 , 0x082 ) ;
F_1 ( V_126 , V_128 , 0x002 ) ;
F_1 ( V_126 , V_129 , 0x00D ) ;
V_3 = ( V_124 . V_86 << 5 ) |
( V_124 . V_87 << 4 ) |
( V_124 . V_88 << 2 ) |
( V_124 . V_89 ) ;
F_1 ( V_126 , F_35 ( 0 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( V_124 . V_90 << 6 ) |
( V_124 . V_91 << 4 ) |
( V_124 . V_92 ) ;
F_1 ( V_126 , F_35 ( 1 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( V_124 . V_93 << 7 ) |
( V_124 . V_94 << 4 ) |
( V_124 . V_95 << 2 ) |
( V_124 . V_96 ) ;
F_1 ( V_126 , F_35 ( 2 ) , V_3 ) ;
V_125 += V_3 ;
F_1 ( V_126 , F_35 ( 3 ) ,
V_124 . V_97 ) ;
V_125 += V_124 . V_97 ;
V_3 = V_124 . V_98 ;
F_1 ( V_126 , F_35 ( 4 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = V_124 . V_99 & 0x00FF ;
F_1 ( V_126 , F_35 ( 5 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( ( V_124 . V_99 >> 8 ) & 0x00FF ) ;
F_1 ( V_126 , F_35 ( 6 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = V_124 . V_100 & 0x00FF ;
F_1 ( V_126 , F_35 ( 7 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( ( V_124 . V_100 >> 8 ) & 0x00FF ) ;
F_1 ( V_126 , F_35 ( 8 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = V_124 . V_101 & 0x00FF ;
F_1 ( V_126 , F_35 ( 9 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( ( V_124 . V_101 >> 8 ) & 0x00FF ) ;
F_1 ( V_126 , F_35 ( 10 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = V_124 . V_102 & 0x00FF ;
F_1 ( V_126 , F_35 ( 11 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( ( V_124 . V_102 >> 8 ) & 0x00FF ) ;
F_1 ( V_126 , F_35 ( 12 ) , V_3 ) ;
V_125 += V_3 ;
V_54 = 0x100 - V_125 ;
F_1 ( V_126 , V_130 , V_54 ) ;
}
static void F_36 ( struct V_4 * V_5 ,
struct V_72 V_73 )
{
F_1 ( F_8 ( V_5 ) , V_131 ,
( V_73 . V_103 << 5 ) |
( V_73 . V_104 << 4 ) |
( V_73 . V_105 << 1 ) |
( V_73 . V_106 ) ) ;
F_1 ( F_8 ( V_5 ) , V_132 ,
( V_73 . V_107 << 3 ) |
( V_73 . V_108 << 2 ) |
( V_73 . V_109 << 1 ) |
( V_73 . V_110 ) ) ;
}
static void F_37 ( struct V_133 * V_134 ,
struct V_135 * V_136 ,
struct V_137 * V_138 )
{
F_17 ( L_23 ) ;
V_134 -> V_139 = 0 ;
V_134 -> V_140 = 0 ;
V_134 -> V_141 = 0 ;
V_134 -> V_142 = 0 ;
V_134 -> V_143 = 0 ;
V_134 -> V_144 = 0 ;
V_136 -> V_145 = V_146 ;
V_136 -> V_147 = 0 ;
V_136 -> V_148 = 0 ;
V_138 -> V_149 = 0 ;
V_138 -> V_150 = 0 ;
V_138 -> V_151 = 0 ;
V_138 -> V_152 = 0 ;
}
void F_38 ( struct V_4 * V_5 , bool V_153 )
{
F_14 ( F_5 ( V_5 ) , V_154 , V_153 , 31 , 31 ) ;
}
static void F_39 ( struct V_135 * V_136 ,
struct V_133 * V_134 , struct V_155 * V_156 )
{
F_17 ( L_24 ) ;
V_136 -> V_147 = V_156 -> V_134 . V_134 . V_147 ;
V_136 -> V_148 = V_156 -> V_134 . V_134 . V_148 ;
V_134 -> V_139 = V_156 -> V_134 . V_134 . V_139 ;
V_134 -> V_140 = V_156 -> V_134 . V_134 . V_140 ;
V_134 -> V_141 = V_156 -> V_134 . V_134 . V_141 ;
V_134 -> V_142 = V_156 -> V_134 . V_134 . V_142 ;
V_134 -> V_143 = V_156 -> V_134 . V_134 . V_143 ;
V_134 -> V_144 = V_156 -> V_134 . V_134 . V_144 ;
}
static void F_40 ( struct V_4 * V_5 ,
struct V_135 * V_136 )
{
T_3 V_65 = 0 ;
F_14 ( F_5 ( V_5 ) , V_154 ,
V_136 -> V_145 , 10 , 8 ) ;
V_65 |= F_41 ( V_136 -> V_147 , 31 , 16 ) ;
V_65 |= F_41 ( V_136 -> V_148 , 15 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_157 , V_65 ) ;
}
static void F_42 ( struct V_4 * V_5 ,
struct V_137 * V_138 )
{
T_3 V_14 ;
F_17 ( L_25 ) ;
V_14 = F_3 ( F_5 ( V_5 ) , V_154 ) ;
V_14 = F_15 ( V_14 , V_138 -> V_149 , 7 , 7 ) ;
V_14 = F_15 ( V_14 , V_138 -> V_150 , 6 , 6 ) ;
V_14 = F_15 ( V_14 , V_138 -> V_151 , 3 , 3 ) ;
V_14 = F_15 ( V_14 , V_138 -> V_152 , 1 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_154 , V_14 ) ;
}
static void F_43 ( struct V_4 * V_5 ,
struct V_133 * V_134 )
{
T_3 V_158 = 0 ;
T_3 V_159 = 0 ;
F_17 ( L_26 ) ;
V_158 |= F_41 ( V_134 -> V_139 , 31 , 20 ) ;
V_158 |= F_41 ( V_134 -> V_140 , 19 , 8 ) ;
V_158 |= F_41 ( V_134 -> V_141 , 7 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_160 , V_158 ) ;
V_159 |= F_41 ( V_134 -> V_142 , 31 , 20 ) ;
V_159 |= F_41 ( V_134 -> V_143 , 19 , 8 ) ;
V_159 |= F_41 ( V_134 -> V_144 , 7 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_161 , V_159 ) ;
}
void F_44 ( struct V_4 * V_5 )
{
struct V_133 V_162 ;
struct V_135 V_163 ;
struct V_137 V_164 ;
struct V_70 V_71 ;
struct V_68 V_165 ;
struct V_72 V_73 ;
struct V_155 * V_113 = & V_5 -> V_113 ;
F_37 ( & V_162 , & V_163 ,
& V_164 ) ;
F_30 ( & V_165 ,
& V_71 ,
& V_73 ) ;
F_39 ( & V_163 , & V_162 , V_113 ) ;
F_43 ( V_5 , & V_162 ) ;
V_163 . V_145 = V_166 ;
F_40 ( V_5 , & V_163 ) ;
V_164 . V_149 = V_113 -> V_134 . V_167 ;
V_164 . V_150 = V_113 -> V_134 . V_168 ;
V_164 . V_151 = V_113 -> V_169 ;
V_164 . V_152 = 1 ;
F_42 ( V_5 , & V_164 ) ;
F_33 ( V_5 ) ;
F_31 ( V_5 ) ;
V_165 . V_80 = V_170 ;
V_165 . V_82 = V_113 -> V_171 . V_172 ;
V_68 ( V_5 , & V_165 ) ;
F_32 ( V_5 ) ;
V_71 . V_86 = V_173 ;
V_71 . V_87 =
V_174 ;
V_71 . V_88 = V_175 ;
V_71 . V_89 = V_176 ;
V_71 . V_90 = V_177 ;
V_71 . V_91 = V_178 ;
V_71 . V_92 = V_179 ;
V_71 . V_93 = V_180 ;
V_71 . V_94 = V_181 ;
V_71 . V_95 = V_182 ;
V_71 . V_96 = V_183 ;
V_71 . V_97 = V_113 -> V_171 . V_184 ;
V_71 . V_98 = V_185 ;
V_71 . V_99 = 0 ;
V_71 . V_100 = 0 ;
V_71 . V_101 = 0 ;
V_71 . V_102 = 0 ;
F_34 ( V_5 , V_71 ) ;
V_73 . V_105 = V_186 ;
V_73 . V_106 = V_187 ;
V_73 . V_103 = V_186 ;
V_73 . V_104 = V_187 ;
F_36 ( V_5 , V_73 ) ;
}
void F_45 ( struct V_4 * V_5 , struct V_188 * V_189 )
{
#define F_46 ( V_14 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(hdmi_wp_base(ip_data), r))
F_46 ( V_190 ) ;
F_46 ( V_191 ) ;
F_46 ( V_192 ) ;
F_46 ( V_193 ) ;
F_46 ( V_35 ) ;
F_46 ( V_194 ) ;
F_46 ( V_154 ) ;
F_46 ( V_157 ) ;
F_46 ( V_160 ) ;
F_46 ( V_161 ) ;
F_46 ( V_195 ) ;
F_46 ( V_196 ) ;
F_46 ( V_197 ) ;
F_46 ( V_198 ) ;
F_46 ( V_199 ) ;
}
void F_47 ( struct V_4 * V_5 , struct V_188 * V_189 )
{
#define F_48 ( V_14 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(hdmi_pll_base(ip_data), r))
F_48 ( V_19 ) ;
F_48 ( V_33 ) ;
F_48 ( V_31 ) ;
F_48 ( V_20 ) ;
F_48 ( V_23 ) ;
F_48 ( V_26 ) ;
F_48 ( V_28 ) ;
}
void F_49 ( struct V_4 * V_5 , struct V_188 * V_189 )
{
int V_53 ;
#define F_50 ( V_53 , T_5 ) name(i)
#define F_51 ( V_14 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(hdmi_pll_base(ip_data), r))
#define F_52 ( V_53 , V_14 ) seq_printf(s, "%s[%d]%*s %08x\n", #r, i, \
(i < 10) ? 32 - strlen(#r) : 31 - strlen(#r), " ", \
hdmi_read_reg(hdmi_pll_base(ip_data), CORE_REG(i, r)))
F_51 ( V_200 ) ;
F_51 ( V_201 ) ;
F_51 ( V_202 ) ;
F_51 ( V_203 ) ;
F_51 ( V_112 ) ;
F_51 ( V_111 ) ;
F_51 ( V_67 ) ;
F_51 ( V_119 ) ;
F_51 ( V_120 ) ;
F_51 ( V_204 ) ;
F_51 ( V_205 ) ;
F_51 ( V_206 ) ;
F_51 ( V_207 ) ;
F_51 ( V_208 ) ;
F_51 ( V_209 ) ;
F_51 ( V_123 ) ;
F_51 ( V_210 ) ;
F_51 ( V_211 ) ;
F_51 ( V_212 ) ;
F_51 ( V_213 ) ;
F_51 ( V_214 ) ;
F_51 ( V_215 ) ;
F_51 ( V_216 ) ;
F_51 ( V_50 ) ;
F_51 ( V_49 ) ;
F_51 ( V_57 ) ;
F_51 ( V_58 ) ;
F_51 ( V_59 ) ;
F_51 ( V_60 ) ;
F_51 ( V_62 ) ;
F_51 ( V_56 ) ;
F_51 ( V_122 ) ;
F_51 ( V_48 ) ;
F_51 ( V_131 ) ;
F_51 ( V_132 ) ;
F_51 ( V_127 ) ;
F_51 ( V_128 ) ;
F_51 ( V_129 ) ;
F_51 ( V_130 ) ;
for ( V_53 = 0 ; V_53 < V_217 ; V_53 ++ )
F_52 ( V_53 , F_35 ) ;
for ( V_53 = 0 ; V_53 < V_218 ; V_53 ++ )
F_52 ( V_53 , V_219 ) ;
for ( V_53 = 0 ; V_53 < V_220 ; V_53 ++ )
F_52 ( V_53 , V_221 ) ;
for ( V_53 = 0 ; V_53 < V_222 ; V_53 ++ )
F_52 ( V_53 , V_223 ) ;
for ( V_53 = 0 ; V_53 < V_224 ; V_53 ++ )
F_52 ( V_53 , V_225 ) ;
for ( V_53 = 0 ; V_53 < V_226 ; V_53 ++ )
F_52 ( V_53 , V_227 ) ;
F_51 ( V_228 ) ;
F_51 ( V_229 ) ;
F_51 ( V_230 ) ;
F_51 ( V_231 ) ;
F_51 ( V_232 ) ;
F_51 ( V_233 ) ;
F_51 ( V_234 ) ;
F_51 ( V_235 ) ;
F_51 ( V_236 ) ;
F_51 ( V_237 ) ;
F_51 ( V_238 ) ;
F_51 ( V_239 ) ;
F_51 ( V_240 ) ;
F_51 ( V_241 ) ;
F_51 ( V_242 ) ;
F_51 ( V_243 ) ;
F_51 ( V_244 ) ;
F_51 ( V_245 ) ;
F_51 ( V_246 ) ;
F_51 ( V_247 ) ;
F_51 ( V_248 ) ;
F_51 ( V_249 ) ;
F_51 ( V_250 ) ;
F_51 ( V_251 ) ;
F_51 ( V_252 ) ;
F_51 ( V_122 ) ;
F_51 ( V_253 ) ;
F_51 ( V_254 ) ;
F_51 ( V_255 ) ;
F_51 ( V_256 ) ;
F_51 ( V_257 ) ;
F_51 ( V_48 ) ;
F_51 ( V_131 ) ;
F_51 ( V_132 ) ;
F_51 ( V_127 ) ;
F_51 ( V_128 ) ;
F_51 ( V_129 ) ;
F_51 ( V_130 ) ;
F_51 ( V_258 ) ;
F_51 ( V_259 ) ;
F_51 ( V_260 ) ;
F_51 ( V_261 ) ;
F_51 ( V_262 ) ;
F_51 ( V_263 ) ;
F_51 ( V_264 ) ;
F_51 ( V_265 ) ;
F_51 ( V_266 ) ;
F_51 ( V_267 ) ;
F_51 ( V_268 ) ;
F_51 ( V_269 ) ;
F_51 ( V_270 ) ;
F_51 ( V_271 ) ;
}
void F_53 ( struct V_4 * V_5 , struct V_188 * V_189 )
{
#define F_54 ( V_14 ) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(hdmi_phy_base(ip_data), r))
F_54 ( V_42 ) ;
F_54 ( V_43 ) ;
F_54 ( V_44 ) ;
F_54 ( V_45 ) ;
}
void F_55 ( struct V_4 * V_5 ,
struct V_272 * V_273 )
{
T_3 V_14 ;
F_56 ( L_27 ) ;
V_14 = F_3 ( F_5 ( V_5 ) , V_196 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_274 , 26 , 24 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_275 , 23 , 16 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_276 , 5 , 5 ) ;
V_14 = F_15 ( V_14 , V_273 -> type , 4 , 4 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_277 , 3 , 3 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_278 , 2 , 2 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_279 , 1 , 1 ) ;
V_14 = F_15 ( V_14 , V_273 -> V_280 , 0 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_196 , V_14 ) ;
}
void F_57 ( struct V_4 * V_5 ,
struct V_281 * V_282 )
{
T_3 V_14 ;
F_56 ( L_28 ) ;
V_14 = F_3 ( F_5 ( V_5 ) , V_197 ) ;
V_14 = F_15 ( V_14 , V_282 -> V_283 , 15 , 8 ) ;
V_14 = F_15 ( V_14 , V_282 -> V_284 , 7 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_197 , V_14 ) ;
V_14 = F_3 ( F_5 ( V_5 ) , V_198 ) ;
V_14 = F_15 ( V_14 , V_282 -> V_172 , 9 , 9 ) ;
V_14 = F_15 ( V_14 , V_282 -> V_285 , 8 , 0 ) ;
F_1 ( F_5 ( V_5 ) , V_198 , V_14 ) ;
}
void F_58 ( struct V_4 * V_5 ,
struct F_58 * V_113 )
{
T_3 V_14 ;
void T_1 * V_126 = F_8 ( V_5 ) ;
V_14 = F_3 ( V_126 , V_228 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_286 , 2 , 2 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_287 , 1 , 1 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_288 , 0 , 0 ) ;
F_1 ( V_126 , V_228 , V_14 ) ;
F_14 ( V_126 , V_230 , V_113 -> V_289 , 7 , 0 ) ;
F_14 ( V_126 , V_231 , V_113 -> V_289 >> 8 , 7 , 0 ) ;
F_14 ( V_126 , V_232 , V_113 -> V_289 >> 16 , 7 , 0 ) ;
if ( V_113 -> V_288 == V_290 ) {
F_14 ( V_126 , V_233 , V_113 -> V_291 , 7 , 0 ) ;
F_14 ( V_126 ,
V_234 , V_113 -> V_291 >> 8 , 7 , 0 ) ;
F_14 ( V_126 ,
V_235 , V_113 -> V_291 >> 16 , 7 , 0 ) ;
} else {
F_14 ( V_126 ,
V_229 , V_113 -> V_292 , 2 , 0 ) ;
F_14 ( V_126 , V_254 ,
V_113 -> V_293 , 7 , 0 ) ;
F_14 ( V_126 , V_255 ,
( V_113 -> V_293 >> 8 ) , 7 , 0 ) ;
F_14 ( V_126 , V_256 ,
( V_113 -> V_293 >> 16 ) , 7 , 0 ) ;
}
F_14 ( V_126 , V_240 ,
V_113 -> V_294 , 1 , 1 ) ;
F_14 ( V_126 , V_249 ,
V_113 -> V_295 , 3 , 0 ) ;
V_14 = F_3 ( V_126 , V_245 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_297 , 7 , 7 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_298 , 6 , 6 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_299 , 5 , 5 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_300 , 4 , 4 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_301 , 3 , 3 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_277 , 2 , 2 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_302 , 1 , 1 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_303 , 0 , 0 ) ;
F_1 ( V_126 , V_245 , V_14 ) ;
V_14 = F_3 ( V_126 , V_250 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_295 , 7 , 4 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_304 , 3 , 1 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_305 , 0 , 0 ) ;
F_1 ( V_126 , V_250 , V_14 ) ;
F_14 ( V_126 , V_252 ,
V_113 -> V_296 . V_306 , 3 , 0 ) ;
F_14 ( V_126 , V_122 , V_113 -> V_307 , 2 , 1 ) ;
V_14 = F_3 ( V_126 , V_239 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_296 . V_308 , 7 , 4 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_309 , 3 , 3 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_310 , 2 , 2 ) ;
V_14 = F_15 ( V_14 , V_113 -> V_311 , 1 , 1 ) ;
F_1 ( V_126 , V_239 , V_14 ) ;
}
void F_59 ( struct V_4 * V_5 ,
struct V_312 * V_313 )
{
T_4 V_3 ;
T_4 V_125 = 0 , V_54 = 0 ;
void T_1 * V_126 = F_8 ( V_5 ) ;
F_1 ( V_126 , V_262 , 0x84 ) ;
F_1 ( V_126 , V_263 , 0x01 ) ;
F_1 ( V_126 , V_264 , 0x0a ) ;
V_125 += 0x84 + 0x001 + 0x00a ;
V_3 = ( V_313 -> V_314 << 4 )
| ( V_313 -> V_315 - 1 ) ;
F_1 ( V_126 , V_221 ( 0 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( V_313 -> V_316 << 2 ) | V_313 -> V_317 ;
F_1 ( V_126 , V_221 ( 1 ) , V_3 ) ;
V_125 += V_3 ;
F_1 ( V_126 , V_221 ( 2 ) , 0x00 ) ;
V_3 = V_313 -> V_318 ;
F_1 ( V_126 , V_221 ( 3 ) , V_3 ) ;
V_125 += V_3 ;
V_3 = ( V_313 -> V_319 << 7 ) | ( V_313 -> V_320 << 3 ) ;
F_1 ( V_126 , V_221 ( 4 ) , V_3 ) ;
V_125 += V_3 ;
F_1 ( V_126 , V_221 ( 5 ) , 0x00 ) ;
F_1 ( V_126 , V_221 ( 6 ) , 0x00 ) ;
F_1 ( V_126 , V_221 ( 7 ) , 0x00 ) ;
F_1 ( V_126 , V_221 ( 8 ) , 0x00 ) ;
F_1 ( V_126 , V_221 ( 9 ) , 0x00 ) ;
V_54 = 0x100 - V_125 ;
F_1 ( V_126 ,
V_265 , V_54 ) ;
}
int F_60 ( struct V_4 * V_5 ,
T_3 V_321 , T_3 * V_289 , T_3 * V_291 )
{
T_3 V_14 ;
T_3 V_322 = 0 ;
T_3 V_323 = V_5 -> V_113 . V_134 . V_134 . V_324 ;
if ( V_289 == NULL || V_291 == NULL )
return - V_66 ;
V_14 = F_11 ( F_5 ( V_5 ) , V_154 , 1 , 0 ) ;
switch ( V_14 ) {
case 1 :
V_322 = 100 ;
break;
case 2 :
V_322 = 125 ;
break;
case 3 :
V_322 = 150 ;
break;
default:
return - V_66 ;
}
switch ( V_321 ) {
case 32000 :
if ( ( V_322 == 125 ) && ( ( V_323 == 54054 )
|| ( V_323 == 74250 ) ) )
* V_289 = 8192 ;
else
* V_289 = 4096 ;
break;
case 44100 :
* V_289 = 6272 ;
break;
case 48000 :
if ( ( V_322 == 125 ) && ( ( V_323 == 54054 )
|| ( V_323 == 74250 ) ) )
* V_289 = 8192 ;
else
* V_289 = 6144 ;
break;
default:
* V_289 = 0 ;
return - V_66 ;
}
* V_291 = V_323 * ( * V_289 / 128 ) * V_322 / ( V_321 / 10 ) ;
return 0 ;
}
int F_61 ( struct V_4 * V_5 ,
struct V_325 * V_326 , int V_327 ,
struct V_328 * V_329 )
{
int V_330 = 0 ;
switch ( V_327 ) {
case V_331 :
case V_332 :
case V_333 :
F_14 ( F_8 ( V_5 ) ,
V_239 , 1 , 0 , 0 ) ;
F_14 ( F_5 ( V_5 ) ,
V_198 , 1 , 31 , 31 ) ;
F_14 ( F_5 ( V_5 ) ,
V_198 , 1 , 30 , 30 ) ;
break;
case V_334 :
case V_335 :
case V_336 :
F_14 ( F_8 ( V_5 ) ,
V_239 , 0 , 0 , 0 ) ;
F_14 ( F_5 ( V_5 ) ,
V_198 , 0 , 30 , 30 ) ;
F_14 ( F_5 ( V_5 ) ,
V_198 , 0 , 31 , 31 ) ;
break;
default:
V_330 = - V_66 ;
}
return V_330 ;
}
