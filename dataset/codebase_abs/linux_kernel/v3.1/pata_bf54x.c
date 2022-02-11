static unsigned short F_1 ( unsigned long V_1 ,
unsigned long V_2 )
{
unsigned long V_3 ;
unsigned short V_4 ;
V_3 = V_1 * ( V_2 / 1000 / 1000 ) / 1000 ;
V_4 = ( unsigned short ) V_3 ;
if ( ( V_3 * 1000 * 1000 ) < ( V_1 * ( V_2 / 1000 ) ) ) {
V_4 ++ ;
}
return V_4 ;
}
static void F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_9 = V_8 -> V_10 - V_11 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_2 = F_3 () ;
unsigned short V_15 , V_16 , V_17 ;
unsigned short V_18 , V_19 , V_20 ;
unsigned short V_21 , V_22 , V_23 = 5 ;
V_22 = F_1 ( V_23 , V_2 ) ;
if ( V_9 >= 0 && V_9 <= 4 && V_22 >= 1 ) {
F_4 ( V_8 -> V_24 -> V_6 -> V_25 , L_1 , V_9 , V_2 ) ;
while ( V_9 > 0 && V_26 [ V_9 ] > V_2 )
V_9 -- ;
V_16 = F_1 ( V_27 [ V_9 ] , V_2 ) ;
V_15 = F_1 ( V_28 [ V_9 ] , V_2 ) ;
V_21 = F_1 ( V_29 [ V_9 ] , V_2 ) ;
if ( V_16 + V_15 < V_21 )
V_16 = V_21 - V_15 ;
V_19 = F_1 ( V_30 [ V_9 ] , V_2 ) ;
V_17 = F_1 ( V_31 [ V_9 ] , V_2 ) ;
V_21 = F_1 ( V_32 [ V_9 ] , V_2 ) ;
if ( V_19 + V_17 < V_21 )
V_19 = V_21 - V_17 ;
V_20 = F_1 ( V_33 [ V_9 ] , V_2 ) ;
V_18 = F_1 ( V_34 [ V_9 ] , V_2 ) ;
F_5 ( V_12 , ( V_15 << 8 | V_16 ) ) ;
F_6 ( V_12 , ( V_18 << 12 | V_19 << 4 | V_20 ) ) ;
F_7 ( V_12 , V_17 ) ;
if ( V_9 > 2 ) {
F_8 ( V_12 ,
F_9 ( V_12 ) | V_35 ) ;
} else {
F_8 ( V_12 ,
F_9 ( V_12 ) & ~ V_35 ) ;
}
F_10 ( V_12 , F_11 ( V_12 )
& ~ ( V_36 | V_37 ) ) ;
F_12 () ;
}
}
static void F_13 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_9 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned long V_2 = F_3 () ;
unsigned short V_38 , V_39 , V_40 , V_41 , V_42 , V_43 , V_44 , V_45 ;
unsigned short V_46 , V_47 , V_48 , V_49 , V_50 , V_51 ;
unsigned short V_21 , V_52 , V_53 = 5 ;
unsigned short V_54 , V_55 ;
V_9 = V_8 -> V_56 - V_57 ;
if ( V_9 >= 0 && V_9 <= 5 ) {
F_4 ( V_8 -> V_24 -> V_6 -> V_25 , L_2 , V_9 ) ;
while ( V_9 > 0 && V_58 [ V_9 ] > V_2 )
V_9 -- ;
V_54 = F_1 ( V_59 [ V_9 ] , V_2 ) ;
if ( V_54 >= 1 ) {
V_41 = F_1 ( V_60 [ V_9 ] , V_2 ) ;
V_55 = F_1 ( V_61 [ V_9 ] , V_2 ) ;
V_40 = 2 ;
if ( V_41 + V_40 < V_55 )
V_40 = V_55 - V_41 ;
if ( V_40 < 2 )
V_40 = 2 ;
if ( V_41 < 2 )
V_41 = 2 ;
V_39 = F_1 ( V_62 , V_2 ) ;
V_43 = F_1 ( V_63 , V_2 ) ;
V_42 = F_1 ( V_64 , V_2 ) ;
V_45 = F_1 ( V_65 , V_2 ) ;
V_44 = F_1 ( V_66 [ V_9 ] , V_2 ) ;
V_38 = F_1 ( V_67 , V_2 ) ;
if ( V_38 <= V_68 [ V_9 ] ) {
F_14 ( V_12 , ( V_38 << 8 | V_39 ) ) ;
F_15 ( V_12 ,
( V_40 << 8 | V_41 ) ) ;
F_16 ( V_12 , ( V_42 << 8 | V_43 ) ) ;
F_17 ( V_12 , ( V_44 << 8 | V_45 ) ) ;
F_10 ( V_12 ,
F_11 ( V_12 )
| V_69
| V_70
| V_71
| V_72 ) ;
}
}
}
V_9 = V_8 -> V_56 - V_73 ;
if ( V_9 >= 0 && V_9 <= 2 ) {
F_4 ( V_8 -> V_24 -> V_6 -> V_25 , L_3 , V_9 ) ;
while ( V_9 > 0 && V_74 [ V_9 ] > V_2 )
V_9 -- ;
V_52 = F_1 ( V_53 , V_2 ) ;
if ( V_52 >= 1 ) {
V_47 = F_1 ( V_75 [ V_9 ] , V_2 ) ;
V_49 = F_1 ( V_76 [ V_9 ] , V_2 ) ;
V_21 = F_1 ( V_77 [ V_9 ] , V_2 ) ;
if ( V_49 + V_47 < V_21 )
V_49 = V_21 - V_47 ;
V_48 = F_1 ( V_78 [ V_9 ] , V_2 ) ;
V_46 = F_1 ( V_79 [ V_9 ] , V_2 ) ;
V_50 = F_1 ( V_80 [ V_9 ] , V_2 ) ;
V_51 = F_1 ( V_81 [ V_9 ] , V_2 ) ;
F_18 ( V_12 , ( V_46 << 8 | V_47 ) ) ;
F_19 ( V_12 , ( V_48 << 8 | V_49 ) ) ;
F_20 ( V_12 , ( V_50 << 8 | V_51 ) ) ;
F_10 ( V_12 , F_11 ( V_12 )
| V_82 | V_83 ) ;
F_12 () ;
}
}
return;
}
static inline void F_21 ( void T_1 * V_12 , unsigned short V_84 )
{
unsigned short V_85 ;
unsigned int V_86 = 0 ;
#define F_22 10000
for ( V_86 = 0 ; V_86 < F_22 ; V_86 ++ ) {
V_85 = F_23 ( V_12 ) & V_84 ;
if ( V_85 )
break;
}
F_24 ( V_12 , V_84 ) ;
}
static void F_25 ( void T_1 * V_12 ,
unsigned long V_87 , unsigned short V_88 )
{
F_26 ( V_12 , V_88 ) ;
F_27 ( V_12 , V_87 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_89 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_90 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_91 ) ) ;
F_21 ( V_12 , V_92 ) ;
}
static unsigned short F_28 ( void T_1 * V_12 ,
unsigned long V_87 )
{
F_27 ( V_12 , V_87 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_89 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_90 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_91 ) ) ;
F_21 ( V_12 , V_92 ) ;
return F_29 ( V_12 ) ;
}
static void F_30 ( void T_1 * V_12 ,
int V_93 , unsigned short * V_94 )
{
int V_86 ;
F_31 ( V_12 , 1 ) ;
F_27 ( V_12 , V_95 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_89 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_90 ) ) ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
F_26 ( V_12 , V_94 [ V_86 ] ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_91 ) ) ;
F_21 ( V_12 , V_92 ) ;
}
}
static void F_32 ( void T_1 * V_12 ,
int V_93 , unsigned short * V_94 )
{
int V_86 ;
F_31 ( V_12 , 1 ) ;
F_27 ( V_12 , V_95 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_89 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_90 ) ) ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
F_8 ( V_12 , ( F_9 ( V_12 ) | V_91 ) ) ;
F_21 ( V_12 , V_92 ) ;
V_94 [ V_86 ] = F_29 ( V_12 ) ;
}
}
static void F_33 ( struct V_5 * V_6 , const struct V_96 * V_97 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_98 = V_97 -> V_99 & V_100 ;
if ( V_97 -> V_101 != V_6 -> V_102 ) {
F_25 ( V_12 , V_103 , V_97 -> V_101 ) ;
V_6 -> V_102 = V_97 -> V_101 ;
F_34 ( V_6 ) ;
}
if ( V_98 ) {
if ( V_97 -> V_99 & V_104 ) {
F_25 ( V_12 , V_105 ,
V_97 -> V_106 ) ;
F_25 ( V_12 , V_107 ,
V_97 -> V_108 ) ;
F_25 ( V_12 , V_109 , V_97 -> V_110 ) ;
F_25 ( V_12 , V_111 , V_97 -> V_112 ) ;
F_25 ( V_12 , V_113 , V_97 -> V_114 ) ;
F_4 ( V_6 -> V_25 , L_4
L_5 ,
V_97 -> V_106 ,
V_97 -> V_108 ,
V_97 -> V_110 ,
V_97 -> V_112 ,
V_97 -> V_114 ) ;
}
F_25 ( V_12 , V_105 , V_97 -> V_115 ) ;
F_25 ( V_12 , V_107 , V_97 -> V_116 ) ;
F_25 ( V_12 , V_109 , V_97 -> V_117 ) ;
F_25 ( V_12 , V_111 , V_97 -> V_118 ) ;
F_25 ( V_12 , V_113 , V_97 -> V_119 ) ;
F_4 ( V_6 -> V_25 , L_6 ,
V_97 -> V_115 ,
V_97 -> V_116 ,
V_97 -> V_117 ,
V_97 -> V_118 ,
V_97 -> V_119 ) ;
}
if ( V_97 -> V_99 & V_120 ) {
F_25 ( V_12 , V_121 , V_97 -> V_122 ) ;
F_4 ( V_6 -> V_25 , L_7 , V_97 -> V_122 ) ;
}
F_34 ( V_6 ) ;
}
static T_2 F_35 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
return F_28 ( V_12 , V_123 ) ;
}
static void F_36 ( struct V_5 * V_6 , struct V_96 * V_97 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
V_97 -> V_124 = F_35 ( V_6 ) ;
V_97 -> V_115 = F_28 ( V_12 , V_125 ) ;
V_97 -> V_116 = F_28 ( V_12 , V_107 ) ;
V_97 -> V_117 = F_28 ( V_12 , V_109 ) ;
V_97 -> V_118 = F_28 ( V_12 , V_111 ) ;
V_97 -> V_119 = F_28 ( V_12 , V_113 ) ;
V_97 -> V_122 = F_28 ( V_12 , V_121 ) ;
if ( V_97 -> V_99 & V_104 ) {
F_25 ( V_12 , V_103 , V_97 -> V_101 | V_126 ) ;
V_97 -> V_106 = F_28 ( V_12 , V_125 ) ;
V_97 -> V_108 = F_28 ( V_12 , V_107 ) ;
V_97 -> V_110 = F_28 ( V_12 , V_109 ) ;
V_97 -> V_112 = F_28 ( V_12 , V_111 ) ;
V_97 -> V_114 = F_28 ( V_12 , V_113 ) ;
}
}
static void F_37 ( struct V_5 * V_6 ,
const struct V_96 * V_97 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_4 ( V_6 -> V_25 , L_8 , V_6 -> V_127 , V_97 -> V_124 ) ;
F_25 ( V_12 , V_128 , V_97 -> V_124 ) ;
F_38 ( V_6 ) ;
}
static T_2 F_39 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
return F_28 ( V_12 , V_129 ) ;
}
static void F_40 ( struct V_5 * V_6 , unsigned int V_122 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
T_2 V_3 ;
if ( V_122 == 0 )
V_3 = V_130 ;
else
V_3 = V_130 | V_131 ;
F_25 ( V_12 , V_121 , V_3 ) ;
F_38 ( V_6 ) ;
}
static void F_41 ( struct V_5 * V_6 , T_2 V_101 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_25 ( V_12 , V_103 , V_101 ) ;
}
static void F_42 ( struct V_132 * V_133 )
{
unsigned short V_134 = V_135 ;
struct V_136 * V_137 ;
unsigned int V_138 ;
F_4 ( V_133 -> V_6 -> V_25 , L_9 ) ;
if ( V_133 -> V_97 . V_99 & V_139 ) {
F_43 ( V_140 , V_134 ) ;
F_44 ( V_140 , 2 ) ;
F_45 (qc->sg, sg, qc->n_elem, si) {
F_46 ( V_140 , F_47 ( V_137 ) ) ;
F_48 ( V_140 , F_49 ( V_137 ) >> 1 ) ;
}
} else {
V_134 |= V_141 ;
F_43 ( V_142 , V_134 ) ;
F_44 ( V_142 , 2 ) ;
F_45 (qc->sg, sg, qc->n_elem, si) {
F_46 ( V_142 , F_47 ( V_137 ) ) ;
F_48 ( V_142 , F_49 ( V_137 ) >> 1 ) ;
}
}
}
static void F_50 ( struct V_132 * V_133 )
{
struct V_5 * V_6 = V_133 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
struct V_136 * V_137 ;
unsigned int V_138 ;
F_4 ( V_133 -> V_6 -> V_25 , L_10 ) ;
if ( ! ( V_6 -> V_143 || V_6 -> V_144 ) )
return;
if ( V_133 -> V_97 . V_99 & V_139 ) {
F_45 (qc->sg, sg, qc->n_elem, si) {
F_51 ( F_47 ( V_137 ) ,
F_47 ( V_137 ) + F_49 ( V_137 ) ) ;
}
F_52 ( V_140 ) ;
F_4 ( V_133 -> V_6 -> V_25 , L_11 ) ;
F_37 ( V_6 , & V_133 -> V_97 ) ;
F_8 ( V_12 , ( F_9 ( V_12 )
| V_89 ) ) ;
} else {
F_52 ( V_142 ) ;
F_4 ( V_133 -> V_6 -> V_25 , L_12 ) ;
F_37 ( V_6 , & V_133 -> V_97 ) ;
F_8 ( V_12 , ( F_9 ( V_12 )
& ~ V_89 ) ) ;
}
F_8 ( V_12 , F_9 ( V_12 ) | V_145 ) ;
F_8 ( V_12 , F_9 ( V_12 ) | V_146 ) ;
F_45 (qc->sg, sg, qc->n_elem, si) {
F_31 ( V_12 , ( F_49 ( V_137 ) >> 1 ) ) ;
}
if ( V_6 -> V_143 )
F_8 ( V_12 , F_9 ( V_12 )
| V_147 ) ;
else
F_8 ( V_12 , F_9 ( V_12 )
| V_148 ) ;
}
static void F_53 ( struct V_132 * V_133 )
{
struct V_5 * V_6 = V_133 -> V_6 ;
struct V_136 * V_137 ;
unsigned int V_138 ;
F_4 ( V_133 -> V_6 -> V_25 , L_13 ) ;
if ( ! ( V_6 -> V_143 || V_6 -> V_144 ) )
return;
if ( V_133 -> V_97 . V_99 & V_139 )
F_54 ( V_140 ) ;
else {
F_54 ( V_142 ) ;
if ( V_6 -> V_149 & V_150 ) {
F_45 (qc->sg, sg, qc->n_elem, si) {
F_55 (
F_47 ( V_137 ) ,
F_47 ( V_137 )
+ F_49 ( V_137 ) ) ;
}
}
}
}
static unsigned int F_56 ( struct V_5 * V_6 ,
unsigned int V_122 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
T_2 V_116 , V_117 ;
F_40 ( V_6 , V_122 ) ;
F_25 ( V_12 , V_107 , 0x55 ) ;
F_25 ( V_12 , V_109 , 0xaa ) ;
F_25 ( V_12 , V_107 , 0xaa ) ;
F_25 ( V_12 , V_109 , 0x55 ) ;
F_25 ( V_12 , V_107 , 0x55 ) ;
F_25 ( V_12 , V_109 , 0xaa ) ;
V_116 = F_28 ( V_12 , V_107 ) ;
V_117 = F_28 ( V_12 , V_109 ) ;
if ( ( V_116 == 0x55 ) && ( V_117 == 0xaa ) )
return 1 ;
return 0 ;
}
static void F_57 ( struct V_5 * V_6 , unsigned int V_151 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_152 = V_151 & ( 1 << 0 ) ;
unsigned int V_153 = V_151 & ( 1 << 1 ) ;
unsigned long V_154 ;
if ( V_152 )
F_58 ( V_6 , V_155 , V_156 ) ;
V_154 = F_59 ( V_157 , V_156 ) ;
while ( V_153 ) {
T_2 V_116 , V_117 ;
F_40 ( V_6 , 1 ) ;
V_116 = F_28 ( V_12 , V_107 ) ;
V_117 = F_28 ( V_12 , V_109 ) ;
if ( ( V_116 == 1 ) && ( V_117 == 1 ) )
break;
if ( F_60 ( V_157 , V_154 ) ) {
V_153 = 0 ;
break;
}
F_61 ( V_6 , 50 ) ;
}
if ( V_153 )
F_58 ( V_6 , V_155 , V_156 ) ;
F_40 ( V_6 , 0 ) ;
if ( V_153 )
F_40 ( V_6 , 1 ) ;
if ( V_152 )
F_40 ( V_6 , 0 ) ;
}
static unsigned int F_62 ( struct V_5 * V_6 ,
unsigned int V_151 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_25 ( V_12 , V_103 , V_6 -> V_101 ) ;
F_63 ( 20 ) ;
F_25 ( V_12 , V_103 , V_6 -> V_101 | V_158 ) ;
F_63 ( 20 ) ;
F_25 ( V_12 , V_103 , V_6 -> V_101 ) ;
F_61 ( V_6 , 150 ) ;
if ( F_35 ( V_6 ) == 0xFF )
return 0 ;
F_57 ( V_6 , V_151 ) ;
return 0 ;
}
static int F_64 ( struct V_159 * V_24 , unsigned int * V_160 ,
unsigned long V_154 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
unsigned int V_161 = V_6 -> V_99 & V_162 ;
unsigned int V_151 = 0 , V_163 ;
T_2 V_164 ;
if ( F_56 ( V_6 , 0 ) )
V_151 |= ( 1 << 0 ) ;
if ( V_161 && F_56 ( V_6 , 1 ) )
V_151 |= ( 1 << 1 ) ;
F_40 ( V_6 , 0 ) ;
V_163 = F_62 ( V_6 , V_151 ) ;
if ( V_163 ) {
F_65 ( V_6 , L_14 ,
V_163 ) ;
return - V_165 ;
}
V_160 [ 0 ] = F_66 ( & V_6 -> V_24 . V_122 [ 0 ] ,
V_151 & ( 1 << 0 ) , & V_164 ) ;
if ( V_161 && V_164 != 0x81 )
V_160 [ 1 ] = F_66 ( & V_6 -> V_24 . V_122 [ 1 ] ,
V_151 & ( 1 << 1 ) , & V_164 ) ;
return 0 ;
}
static unsigned char F_67 ( struct V_5 * V_6 )
{
unsigned char V_166 = 0 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned short V_167 = F_23 ( V_12 ) ;
if ( F_68 ( V_12 ) & ( V_168 | V_169 ) )
V_166 |= V_170 ;
if ( V_167 & ( V_171 | V_172 | V_173 |
V_174 ) )
V_166 |= V_175 ;
if ( V_167 & ( V_176 | V_177 | V_178 ) )
V_166 |= V_179 | V_175 ;
F_4 ( V_6 -> V_25 , L_15 , V_166 ) ;
return V_166 ;
}
static unsigned int F_69 ( struct V_7 * V_25 , unsigned char * V_94 ,
unsigned int V_180 , int V_181 )
{
struct V_5 * V_6 = V_25 -> V_24 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_182 = V_180 >> 1 ;
unsigned short * V_183 = ( V_184 * ) V_94 ;
if ( V_181 == V_185 )
F_32 ( V_12 , V_182 , V_183 ) ;
else
F_30 ( V_12 , V_182 , V_183 ) ;
if ( F_70 ( V_180 & 0x01 ) ) {
unsigned short V_186 [ 1 ] = { 0 } ;
unsigned char * V_187 = V_94 + V_180 - 1 ;
if ( V_181 == V_185 ) {
F_32 ( V_12 , 1 , V_186 ) ;
memcpy ( V_187 , V_186 , 1 ) ;
} else {
memcpy ( V_186 , V_187 , 1 ) ;
F_30 ( V_12 , 1 , V_186 ) ;
}
V_182 ++ ;
}
return V_182 << 1 ;
}
static void F_71 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_4 ( V_6 -> V_25 , L_16 ) ;
F_24 ( V_12 , F_23 ( V_12 ) | V_174
| V_171 | V_172 | V_173
| V_176 | V_177 | V_178 ) ;
}
void F_72 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_17 ) ;
F_35 ( V_6 ) ;
F_73 ( V_6 ) ;
}
static void F_74 ( struct V_159 * V_24 , unsigned int * V_160 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_73 ( V_6 ) ;
if ( V_160 [ 0 ] != V_188 )
F_40 ( V_6 , 1 ) ;
if ( V_160 [ 1 ] != V_188 )
F_40 ( V_6 , 0 ) ;
if ( V_160 [ 0 ] == V_188 && V_160 [ 1 ] == V_188 ) {
return;
}
F_25 ( V_12 , V_103 , V_6 -> V_101 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_18 ) ;
if ( V_6 -> V_143 != 0 || V_6 -> V_144 != 0 ) {
F_76 ( V_142 ) ;
F_76 ( V_140 ) ;
}
}
static int F_77 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_19 ) ;
if ( ! ( V_6 -> V_143 || V_6 -> V_144 ) )
return 0 ;
if ( F_78 ( V_142 , L_20 ) >= 0 ) {
if ( F_78 ( V_140 ,
L_21 ) >= 0 )
return 0 ;
F_76 ( V_142 ) ;
}
V_6 -> V_143 = 0 ;
V_6 -> V_144 = 0 ;
F_79 ( V_6 -> V_25 , L_22
L_23 ) ;
return 0 ;
}
static unsigned int F_80 ( struct V_5 * V_6 ,
struct V_132 * V_133 )
{
struct V_189 * V_190 = & V_6 -> V_24 . V_191 ;
T_2 V_85 , V_166 = 0 ;
F_81 ( L_24 ,
V_6 -> V_127 , V_133 -> V_97 . V_192 , V_6 -> V_149 ) ;
switch ( V_6 -> V_149 ) {
case V_193 :
if ( ! ( V_133 -> V_25 -> V_99 & V_194 ) )
goto V_195;
break;
case V_150 :
if ( V_133 -> V_97 . V_192 == V_196 ||
V_133 -> V_97 . V_192 == V_197 ) {
V_166 = V_6 -> V_198 -> V_199 ( V_6 ) ;
F_81 ( L_25 ,
V_6 -> V_127 , V_166 ) ;
if ( ! ( V_166 & V_175 ) )
goto V_195;
V_6 -> V_198 -> V_200 ( V_133 ) ;
if ( F_70 ( V_166 & V_179 ) ) {
V_133 -> V_163 |= V_201 ;
V_6 -> V_149 = V_202 ;
}
}
break;
case V_203 :
break;
default:
goto V_195;
}
V_85 = V_6 -> V_198 -> V_204 ( V_6 ) ;
if ( V_85 & V_205 )
goto V_206;
V_85 = V_6 -> V_198 -> V_207 ( V_6 ) ;
if ( F_70 ( V_85 & V_205 ) )
goto V_206;
V_6 -> V_198 -> V_208 ( V_6 ) ;
F_82 ( V_6 , V_133 , V_85 , 0 ) ;
if ( F_70 ( V_133 -> V_163 ) && ( V_133 -> V_97 . V_192 == V_196 ||
V_133 -> V_97 . V_192 == V_197 ) )
F_83 ( V_190 , L_26 , V_166 ) ;
V_206:
return 1 ;
V_195:
V_6 -> V_209 . V_195 ++ ;
#ifdef F_84
if ( ( V_6 -> V_209 . V_195 % 1000 ) == 0 ) {
V_6 -> V_198 -> V_210 ( V_6 , 0 ) ;
F_85 ( V_6 , L_27 ) ;
return 1 ;
}
#endif
return 0 ;
}
static T_3 F_86 ( int V_211 , void * V_212 )
{
struct V_213 * V_214 = V_212 ;
unsigned int V_86 ;
unsigned int V_215 = 0 ;
unsigned long V_99 ;
F_87 ( & V_214 -> V_216 , V_99 ) ;
for ( V_86 = 0 ; V_86 < V_214 -> V_217 ; V_86 ++ ) {
struct V_5 * V_6 = V_214 -> V_218 [ V_86 ] ;
struct V_132 * V_133 ;
V_133 = F_88 ( V_6 , V_6 -> V_24 . V_219 ) ;
if ( V_133 && ( ! ( V_133 -> V_97 . V_99 & V_220 ) ) )
V_215 |= F_80 ( V_6 , V_133 ) ;
}
F_89 ( & V_214 -> V_216 , V_99 ) ;
return F_90 ( V_215 ) ;
}
static int F_91 ( struct V_213 * V_214 )
{
void T_1 * V_12 = ( void T_1 * ) V_214 -> V_218 [ 0 ] -> V_13 . V_14 ;
int V_221 ;
unsigned short V_85 ;
F_10 ( V_12 , 0 ) ;
F_12 () ;
F_8 ( V_12 , F_9 ( V_12 ) | V_222 ) ;
F_63 ( 30 ) ;
F_8 ( V_12 , F_9 ( V_12 ) & ~ V_222 ) ;
F_92 ( 2 ) ;
V_221 = 10000000 ;
do {
V_85 = F_28 ( V_12 , V_123 ) ;
} while ( -- V_221 && ( V_85 & V_205 ) );
F_10 ( V_12 , 1 ) ;
F_12 () ;
return ( ! V_221 ) ;
}
static int T_4 F_93 ( struct V_223 * V_224 )
{
int V_225 = 0 ;
struct V_226 * V_227 ;
struct V_213 * V_214 ;
unsigned int V_2 = F_3 () ;
int V_228 = 5 ;
const struct V_229 * V_230 [] =
{ & V_231 [ V_225 ] , NULL } ;
if ( F_70 ( V_224 -> V_232 != 2 ) ) {
F_79 ( & V_224 -> V_25 , L_28 ) ;
return - V_233 ;
}
V_227 = F_94 ( V_224 , V_234 , 0 ) ;
if ( V_227 == NULL )
return - V_233 ;
while ( V_231 [ V_225 ] . V_143 > 0 &&
V_58 [ V_228 ] > V_2 ) {
V_228 -- ;
V_231 [ V_225 ] . V_143 >>= 1 ;
}
V_214 = F_95 ( & V_224 -> V_25 , V_230 , 1 ) ;
if ( ! V_214 )
return - V_235 ;
V_214 -> V_218 [ 0 ] -> V_13 . V_14 = ( void * ) V_227 -> V_236 ;
if ( F_96 ( V_237 , L_29 ) ) {
F_79 ( & V_224 -> V_25 , L_30 ) ;
return - V_238 ;
}
if ( F_91 ( V_214 ) ) {
F_97 ( V_237 ) ;
F_79 ( & V_224 -> V_25 , L_31 ) ;
return - V_238 ;
}
if ( F_98 ( V_214 , F_99 ( V_224 , 0 ) ,
F_86 , V_239 , & V_240 ) != 0 ) {
F_97 ( V_237 ) ;
F_79 ( & V_224 -> V_25 , L_32 ) ;
return - V_241 ;
}
F_100 ( & V_224 -> V_25 , V_214 ) ;
return 0 ;
}
static int T_5 F_101 ( struct V_223 * V_224 )
{
struct V_122 * V_25 = & V_224 -> V_25 ;
struct V_213 * V_214 = F_102 ( V_25 ) ;
F_103 ( V_214 ) ;
F_100 ( & V_224 -> V_25 , NULL ) ;
F_97 ( V_237 ) ;
return 0 ;
}
static int F_104 ( struct V_223 * V_224 , T_6 V_242 )
{
struct V_213 * V_214 = F_102 ( & V_224 -> V_25 ) ;
if ( V_214 )
return F_105 ( V_214 , V_242 ) ;
else
return 0 ;
}
static int F_106 ( struct V_223 * V_224 )
{
struct V_213 * V_214 = F_102 ( & V_224 -> V_25 ) ;
int V_243 ;
if ( V_214 ) {
V_243 = F_91 ( V_214 ) ;
if ( V_243 ) {
F_107 (KERN_ERR DRV_NAME L_33 ) ;
return V_243 ;
}
F_108 ( V_214 ) ;
}
return 0 ;
}
static int T_7 F_109 ( void )
{
F_110 ( L_34 ) ;
switch( V_244 [ 0 ] ) {
case 'p' :
case 'P' :
break;
case 'm' :
case 'M' :
V_231 [ 0 ] . V_144 = V_245 ;
break;
default:
V_231 [ 0 ] . V_143 = V_246 ;
} ;
return F_111 ( & V_247 ) ;
}
static void T_8 F_112 ( void )
{
F_113 ( & V_247 ) ;
}
