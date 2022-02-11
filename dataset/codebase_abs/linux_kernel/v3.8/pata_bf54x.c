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
}
}
}
V_9 = V_8 -> V_56 - V_69 ;
if ( V_9 >= 0 && V_9 <= 2 ) {
F_4 ( V_8 -> V_24 -> V_6 -> V_25 , L_3 , V_9 ) ;
while ( V_9 > 0 && V_70 [ V_9 ] > V_2 )
V_9 -- ;
V_52 = F_1 ( V_53 , V_2 ) ;
if ( V_52 >= 1 ) {
V_47 = F_1 ( V_71 [ V_9 ] , V_2 ) ;
V_49 = F_1 ( V_72 [ V_9 ] , V_2 ) ;
V_21 = F_1 ( V_73 [ V_9 ] , V_2 ) ;
if ( V_49 + V_47 < V_21 )
V_49 = V_21 - V_47 ;
V_48 = F_1 ( V_74 [ V_9 ] , V_2 ) ;
V_46 = F_1 ( V_75 [ V_9 ] , V_2 ) ;
V_50 = F_1 ( V_76 [ V_9 ] , V_2 ) ;
V_51 = F_1 ( V_77 [ V_9 ] , V_2 ) ;
F_18 ( V_12 , ( V_46 << 8 | V_47 ) ) ;
F_19 ( V_12 , ( V_48 << 8 | V_49 ) ) ;
F_20 ( V_12 , ( V_50 << 8 | V_51 ) ) ;
F_12 () ;
}
}
return;
}
static inline void F_21 ( void T_1 * V_12 , unsigned short V_78 )
{
unsigned short V_79 ;
unsigned int V_80 = 0 ;
#define F_22 10000
for ( V_80 = 0 ; V_80 < F_22 ; V_80 ++ ) {
V_79 = F_23 ( V_12 ) & V_78 ;
if ( V_79 )
break;
}
F_24 ( V_12 , V_78 ) ;
}
static void F_25 ( void T_1 * V_12 ,
unsigned long V_81 , unsigned short V_82 )
{
F_26 ( V_12 , V_82 ) ;
F_27 ( V_12 , V_81 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_83 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_84 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_85 ) ) ;
F_21 ( V_12 , V_86 ) ;
}
static unsigned short F_28 ( void T_1 * V_12 ,
unsigned long V_81 )
{
F_27 ( V_12 , V_81 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_83 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_84 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_85 ) ) ;
F_21 ( V_12 , V_86 ) ;
return F_29 ( V_12 ) ;
}
static void F_30 ( void T_1 * V_12 ,
int V_87 , unsigned short * V_88 )
{
int V_80 ;
F_31 ( V_12 , 1 ) ;
F_27 ( V_12 , V_89 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_83 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_84 ) ) ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_26 ( V_12 , V_88 [ V_80 ] ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) | V_85 ) ) ;
F_21 ( V_12 , V_86 ) ;
}
}
static void F_32 ( void T_1 * V_12 ,
int V_87 , unsigned short * V_88 )
{
int V_80 ;
F_31 ( V_12 , 1 ) ;
F_27 ( V_12 , V_89 ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_83 ) ) ;
F_8 ( V_12 , ( F_9 ( V_12 ) & ~ V_84 ) ) ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_8 ( V_12 , ( F_9 ( V_12 ) | V_85 ) ) ;
F_21 ( V_12 , V_86 ) ;
V_88 [ V_80 ] = F_29 ( V_12 ) ;
}
}
static void F_33 ( struct V_5 * V_6 , const struct V_90 * V_91 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_92 = V_91 -> V_93 & V_94 ;
if ( V_91 -> V_95 != V_6 -> V_96 ) {
F_25 ( V_12 , V_97 , V_91 -> V_95 ) ;
V_6 -> V_96 = V_91 -> V_95 ;
F_34 ( V_6 ) ;
}
if ( V_92 ) {
if ( V_91 -> V_93 & V_98 ) {
F_25 ( V_12 , V_99 ,
V_91 -> V_100 ) ;
F_25 ( V_12 , V_101 ,
V_91 -> V_102 ) ;
F_25 ( V_12 , V_103 , V_91 -> V_104 ) ;
F_25 ( V_12 , V_105 , V_91 -> V_106 ) ;
F_25 ( V_12 , V_107 , V_91 -> V_108 ) ;
F_4 ( V_6 -> V_25 , L_4
L_5 ,
V_91 -> V_100 ,
V_91 -> V_102 ,
V_91 -> V_104 ,
V_91 -> V_106 ,
V_91 -> V_108 ) ;
}
F_25 ( V_12 , V_99 , V_91 -> V_109 ) ;
F_25 ( V_12 , V_101 , V_91 -> V_110 ) ;
F_25 ( V_12 , V_103 , V_91 -> V_111 ) ;
F_25 ( V_12 , V_105 , V_91 -> V_112 ) ;
F_25 ( V_12 , V_107 , V_91 -> V_113 ) ;
F_4 ( V_6 -> V_25 , L_6 ,
V_91 -> V_109 ,
V_91 -> V_110 ,
V_91 -> V_111 ,
V_91 -> V_112 ,
V_91 -> V_113 ) ;
}
if ( V_91 -> V_93 & V_114 ) {
F_25 ( V_12 , V_115 , V_91 -> V_116 ) ;
F_4 ( V_6 -> V_25 , L_7 , V_91 -> V_116 ) ;
}
F_34 ( V_6 ) ;
}
static T_2 F_35 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
return F_28 ( V_12 , V_117 ) ;
}
static void F_36 ( struct V_5 * V_6 , struct V_90 * V_91 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
V_91 -> V_118 = F_35 ( V_6 ) ;
V_91 -> V_109 = F_28 ( V_12 , V_119 ) ;
V_91 -> V_110 = F_28 ( V_12 , V_101 ) ;
V_91 -> V_111 = F_28 ( V_12 , V_103 ) ;
V_91 -> V_112 = F_28 ( V_12 , V_105 ) ;
V_91 -> V_113 = F_28 ( V_12 , V_107 ) ;
V_91 -> V_116 = F_28 ( V_12 , V_115 ) ;
if ( V_91 -> V_93 & V_98 ) {
F_25 ( V_12 , V_97 , V_91 -> V_95 | V_120 ) ;
V_91 -> V_100 = F_28 ( V_12 , V_119 ) ;
V_91 -> V_102 = F_28 ( V_12 , V_101 ) ;
V_91 -> V_104 = F_28 ( V_12 , V_103 ) ;
V_91 -> V_106 = F_28 ( V_12 , V_105 ) ;
V_91 -> V_108 = F_28 ( V_12 , V_107 ) ;
}
}
static void F_37 ( struct V_5 * V_6 ,
const struct V_90 * V_91 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_4 ( V_6 -> V_25 , L_8 , V_6 -> V_121 , V_91 -> V_118 ) ;
F_25 ( V_12 , V_122 , V_91 -> V_118 ) ;
F_38 ( V_6 ) ;
}
static T_2 F_39 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
return F_28 ( V_12 , V_123 ) ;
}
static void F_40 ( struct V_5 * V_6 , unsigned int V_116 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
T_2 V_3 ;
if ( V_116 == 0 )
V_3 = V_124 ;
else
V_3 = V_124 | V_125 ;
F_25 ( V_12 , V_115 , V_3 ) ;
F_38 ( V_6 ) ;
}
static void F_41 ( struct V_5 * V_6 , T_2 V_95 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_25 ( V_12 , V_97 , V_95 ) ;
}
static void F_42 ( struct V_126 * V_127 )
{
struct V_5 * V_6 = V_127 -> V_6 ;
struct V_128 * V_129 = (struct V_128 * ) V_6 -> V_130 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned short V_131 = V_132 | V_133 | V_134 | V_135 | V_136 ;
struct V_137 * V_138 ;
unsigned int V_139 ;
unsigned int V_140 ;
unsigned int V_141 ;
unsigned int V_142 = 0 ;
F_4 ( V_127 -> V_6 -> V_25 , L_9 ) ;
if ( V_127 -> V_91 . V_93 & V_143 ) {
V_140 = V_144 ;
V_141 = V_145 ;
} else {
V_140 = V_146 ;
V_141 = V_147 ;
V_131 |= V_148 ;
}
F_43 ( V_6 -> V_25 , V_127 -> V_138 , V_127 -> V_149 , V_141 ) ;
F_44 (qc->sg, sg, qc->n_elem, si) {
V_129 [ V_139 ] . V_150 = F_45 ( V_138 ) ;
V_129 [ V_139 ] . V_151 = V_131 ;
V_129 [ V_139 ] . V_152 = F_46 ( V_138 ) >> 1 ;
V_129 [ V_139 ] . V_153 = 2 ;
V_142 += F_46 ( V_138 ) ;
}
V_129 [ V_127 -> V_149 - 1 ] . V_151 &= ~ ( V_154 | V_155 ) ;
F_47 ( ( unsigned int ) V_129 ,
( unsigned int ) V_129 +
V_127 -> V_149 * sizeof( struct V_128 ) ) ;
F_48 ( V_140 , ( unsigned long * ) V_6 -> V_156 ) ;
F_49 ( V_140 , 0 ) ;
F_50 ( V_140 , 0 ) ;
F_51 ( V_140 , V_131 ) ;
F_12 () ;
F_37 ( V_6 , & V_127 -> V_91 ) ;
if ( V_127 -> V_91 . V_93 & V_143 ) {
F_8 ( V_12 , ( F_9 ( V_12 )
| V_83 ) ) ;
} else {
F_8 ( V_12 , ( F_9 ( V_12 )
& ~ V_83 ) ) ;
}
F_8 ( V_12 , F_9 ( V_12 ) | V_157 ) ;
F_8 ( V_12 , F_9 ( V_12 ) | V_158 ) ;
F_31 ( V_12 , V_142 >> 1 ) ;
}
static void F_52 ( struct V_126 * V_127 )
{
struct V_5 * V_6 = V_127 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_4 ( V_127 -> V_6 -> V_25 , L_10 ) ;
if ( ! ( V_6 -> V_159 || V_6 -> V_160 ) )
return;
if ( V_6 -> V_159 )
F_8 ( V_12 , F_9 ( V_12 )
| V_161 ) ;
else
F_8 ( V_12 , F_9 ( V_12 )
| V_162 ) ;
}
static void F_53 ( struct V_126 * V_127 )
{
struct V_5 * V_6 = V_127 -> V_6 ;
unsigned int V_141 ;
F_4 ( V_127 -> V_6 -> V_25 , L_11 ) ;
if ( ! ( V_6 -> V_159 || V_6 -> V_160 ) )
return;
if ( V_127 -> V_91 . V_93 & V_143 ) {
V_141 = V_145 ;
F_54 ( V_144 ) ;
} else {
V_141 = V_147 ;
F_54 ( V_146 ) ;
}
F_55 ( V_6 -> V_25 , V_127 -> V_138 , V_127 -> V_149 , V_141 ) ;
}
static unsigned int F_56 ( struct V_5 * V_6 ,
unsigned int V_116 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
T_2 V_110 , V_111 ;
F_40 ( V_6 , V_116 ) ;
F_25 ( V_12 , V_101 , 0x55 ) ;
F_25 ( V_12 , V_103 , 0xaa ) ;
F_25 ( V_12 , V_101 , 0xaa ) ;
F_25 ( V_12 , V_103 , 0x55 ) ;
F_25 ( V_12 , V_101 , 0x55 ) ;
F_25 ( V_12 , V_103 , 0xaa ) ;
V_110 = F_28 ( V_12 , V_101 ) ;
V_111 = F_28 ( V_12 , V_103 ) ;
if ( ( V_110 == 0x55 ) && ( V_111 == 0xaa ) )
return 1 ;
return 0 ;
}
static void F_57 ( struct V_5 * V_6 , unsigned int V_163 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_164 = V_163 & ( 1 << 0 ) ;
unsigned int V_165 = V_163 & ( 1 << 1 ) ;
unsigned long V_166 ;
if ( V_164 )
F_58 ( V_6 , V_167 , V_168 ) ;
V_166 = F_59 ( V_169 , V_168 ) ;
while ( V_165 ) {
T_2 V_110 , V_111 ;
F_40 ( V_6 , 1 ) ;
V_110 = F_28 ( V_12 , V_101 ) ;
V_111 = F_28 ( V_12 , V_103 ) ;
if ( ( V_110 == 1 ) && ( V_111 == 1 ) )
break;
if ( F_60 ( V_169 , V_166 ) ) {
V_165 = 0 ;
break;
}
F_61 ( V_6 , 50 ) ;
}
if ( V_165 )
F_58 ( V_6 , V_167 , V_168 ) ;
F_40 ( V_6 , 0 ) ;
if ( V_165 )
F_40 ( V_6 , 1 ) ;
if ( V_164 )
F_40 ( V_6 , 0 ) ;
}
static unsigned int F_62 ( struct V_5 * V_6 ,
unsigned int V_163 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_25 ( V_12 , V_97 , V_6 -> V_95 ) ;
F_63 ( 20 ) ;
F_25 ( V_12 , V_97 , V_6 -> V_95 | V_170 ) ;
F_63 ( 20 ) ;
F_25 ( V_12 , V_97 , V_6 -> V_95 ) ;
F_61 ( V_6 , 150 ) ;
if ( F_35 ( V_6 ) == 0xFF )
return 0 ;
F_57 ( V_6 , V_163 ) ;
return 0 ;
}
static int F_64 ( struct V_171 * V_24 , unsigned int * V_172 ,
unsigned long V_166 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
unsigned int V_173 = V_6 -> V_93 & V_174 ;
unsigned int V_163 = 0 , V_175 ;
T_2 V_176 ;
if ( F_56 ( V_6 , 0 ) )
V_163 |= ( 1 << 0 ) ;
if ( V_173 && F_56 ( V_6 , 1 ) )
V_163 |= ( 1 << 1 ) ;
F_40 ( V_6 , 0 ) ;
V_175 = F_62 ( V_6 , V_163 ) ;
if ( V_175 ) {
F_65 ( V_6 , L_12 ,
V_175 ) ;
return - V_177 ;
}
V_172 [ 0 ] = F_66 ( & V_6 -> V_24 . V_116 [ 0 ] ,
V_163 & ( 1 << 0 ) , & V_176 ) ;
if ( V_173 && V_176 != 0x81 )
V_172 [ 1 ] = F_66 ( & V_6 -> V_24 . V_116 [ 1 ] ,
V_163 & ( 1 << 1 ) , & V_176 ) ;
return 0 ;
}
static unsigned char F_67 ( struct V_5 * V_6 )
{
unsigned char V_178 = 0 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
if ( F_68 ( V_12 ) & ( V_179 | V_180 ) )
V_178 |= V_181 ;
if ( F_23 ( V_12 ) & V_182 )
V_178 |= V_183 ;
F_4 ( V_6 -> V_25 , L_13 , V_178 ) ;
return V_178 ;
}
static unsigned int F_69 ( struct V_7 * V_25 , unsigned char * V_88 ,
unsigned int V_184 , int V_185 )
{
struct V_5 * V_6 = V_25 -> V_24 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
unsigned int V_186 = V_184 >> 1 ;
unsigned short * V_187 = ( V_188 * ) V_88 ;
if ( V_185 == V_189 )
F_32 ( V_12 , V_186 , V_187 ) ;
else
F_30 ( V_12 , V_186 , V_187 ) ;
if ( F_70 ( V_184 & 0x01 ) ) {
unsigned short V_190 [ 1 ] = { 0 } ;
unsigned char * V_191 = V_88 + V_184 - 1 ;
if ( V_185 == V_189 ) {
F_32 ( V_12 , 1 , V_190 ) ;
memcpy ( V_191 , V_190 , 1 ) ;
} else {
memcpy ( V_190 , V_191 , 1 ) ;
F_30 ( V_12 , 1 , V_190 ) ;
}
V_186 ++ ;
}
return V_186 << 1 ;
}
static void F_71 ( struct V_5 * V_6 )
{
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_4 ( V_6 -> V_25 , L_14 ) ;
F_24 ( V_12 , F_23 ( V_12 ) | V_182
| V_192 | V_193 | V_194
| V_195 | V_196 | V_197 ) ;
}
void F_72 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_15 ) ;
F_35 ( V_6 ) ;
F_73 ( V_6 ) ;
}
static void F_74 ( struct V_171 * V_24 , unsigned int * V_172 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
void T_1 * V_12 = ( void T_1 * ) V_6 -> V_13 . V_14 ;
F_73 ( V_6 ) ;
if ( V_172 [ 0 ] != V_198 )
F_40 ( V_6 , 1 ) ;
if ( V_172 [ 1 ] != V_198 )
F_40 ( V_6 , 0 ) ;
if ( V_172 [ 0 ] == V_198 && V_172 [ 1 ] == V_198 ) {
return;
}
F_25 ( V_12 , V_97 , V_6 -> V_95 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_16 ) ;
if ( V_6 -> V_159 != 0 || V_6 -> V_160 != 0 ) {
F_76 ( V_6 -> V_25 ,
V_199 * sizeof( struct V_128 ) ,
V_6 -> V_130 ,
V_6 -> V_156 ) ;
F_77 ( V_146 ) ;
F_77 ( V_144 ) ;
}
}
static int F_78 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_25 , L_17 ) ;
if ( ! ( V_6 -> V_159 || V_6 -> V_160 ) )
return 0 ;
V_6 -> V_130 = F_79 ( V_6 -> V_25 ,
V_199 * sizeof( struct V_128 ) ,
& V_6 -> V_156 ,
V_200 ) ;
if ( V_6 -> V_130 == NULL ) {
F_80 ( V_6 -> V_25 , L_18 ) ;
goto V_201;
}
if ( F_81 ( V_146 , L_19 ) >= 0 ) {
if ( F_81 ( V_144 ,
L_20 ) >= 0 )
return 0 ;
F_77 ( V_146 ) ;
F_76 ( V_6 -> V_25 ,
V_199 * sizeof( struct V_128 ) ,
V_6 -> V_130 ,
V_6 -> V_156 ) ;
}
V_201:
V_6 -> V_159 = 0 ;
V_6 -> V_160 = 0 ;
F_82 ( V_6 -> V_25 , L_21
L_22 ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_5 * V_6 ,
struct V_126 * V_127 )
{
struct V_202 * V_203 = & V_6 -> V_24 . V_204 ;
T_2 V_79 , V_178 = 0 ;
F_84 ( L_23 ,
V_6 -> V_121 , V_127 -> V_91 . V_205 , V_6 -> V_206 ) ;
switch ( V_6 -> V_206 ) {
case V_207 :
if ( ! ( V_127 -> V_25 -> V_93 & V_208 ) )
goto V_209;
break;
case V_210 :
if ( V_127 -> V_91 . V_205 == V_211 ||
V_127 -> V_91 . V_205 == V_212 ) {
V_178 = V_6 -> V_213 -> V_214 ( V_6 ) ;
F_84 ( L_24 ,
V_6 -> V_121 , V_178 ) ;
if ( ! ( V_178 & V_183 ) )
goto V_209;
V_6 -> V_213 -> V_215 ( V_127 ) ;
if ( F_70 ( V_178 & V_216 ) ) {
V_127 -> V_175 |= V_217 ;
V_6 -> V_206 = V_218 ;
}
}
break;
case V_219 :
break;
default:
goto V_209;
}
V_79 = V_6 -> V_213 -> V_220 ( V_6 ) ;
if ( V_79 & V_221 )
goto V_222;
V_79 = V_6 -> V_213 -> V_223 ( V_6 ) ;
if ( F_70 ( V_79 & V_221 ) )
goto V_222;
V_6 -> V_213 -> V_224 ( V_6 ) ;
F_85 ( V_6 , V_127 , V_79 , 0 ) ;
if ( F_70 ( V_127 -> V_175 ) && ( V_127 -> V_91 . V_205 == V_211 ||
V_127 -> V_91 . V_205 == V_212 ) )
F_86 ( V_203 , L_25 , V_178 ) ;
V_222:
return 1 ;
V_209:
V_6 -> V_225 . V_209 ++ ;
#ifdef F_87
if ( ( V_6 -> V_225 . V_209 % 1000 ) == 0 ) {
V_6 -> V_213 -> V_226 ( V_6 , 0 ) ;
F_88 ( V_6 , L_26 ) ;
return 1 ;
}
#endif
return 0 ;
}
static T_3 F_89 ( int V_227 , void * V_228 )
{
struct V_229 * V_230 = V_228 ;
unsigned int V_80 ;
unsigned int V_231 = 0 ;
unsigned long V_93 ;
F_90 ( & V_230 -> V_232 , V_93 ) ;
for ( V_80 = 0 ; V_80 < V_230 -> V_233 ; V_80 ++ ) {
struct V_5 * V_6 = V_230 -> V_234 [ V_80 ] ;
struct V_126 * V_127 ;
V_127 = F_91 ( V_6 , V_6 -> V_24 . V_235 ) ;
if ( V_127 && ( ! ( V_127 -> V_91 . V_93 & V_236 ) ) )
V_231 |= F_83 ( V_6 , V_127 ) ;
}
F_92 ( & V_230 -> V_232 , V_93 ) ;
return F_93 ( V_231 ) ;
}
static int F_94 ( struct V_229 * V_230 )
{
void T_1 * V_12 = ( void T_1 * ) V_230 -> V_234 [ 0 ] -> V_13 . V_14 ;
int V_237 ;
unsigned short V_79 ;
F_10 ( V_12 , 0 ) ;
F_12 () ;
F_8 ( V_12 , F_9 ( V_12 ) | V_238 ) ;
F_63 ( 30 ) ;
F_8 ( V_12 , F_9 ( V_12 ) & ~ V_238 ) ;
F_95 ( 2 ) ;
V_237 = 10000000 ;
do {
V_79 = F_28 ( V_12 , V_117 ) ;
} while ( -- V_237 && ( V_79 & V_221 ) );
F_10 ( V_12 , 1 ) ;
F_12 () ;
return ( ! V_237 ) ;
}
static int F_96 ( struct V_239 * V_240 )
{
int V_241 = 0 ;
struct V_242 * V_243 ;
struct V_229 * V_230 ;
unsigned int V_2 = F_3 () ;
int V_244 = 5 ;
const struct V_245 * V_246 [] =
{ & V_247 [ V_241 ] , NULL } ;
if ( F_70 ( V_240 -> V_248 != 2 ) ) {
F_82 ( & V_240 -> V_25 , L_27 ) ;
return - V_249 ;
}
V_243 = F_97 ( V_240 , V_250 , 0 ) ;
if ( V_243 == NULL )
return - V_249 ;
while ( V_247 [ V_241 ] . V_159 > 0 &&
V_58 [ V_244 ] > V_2 ) {
V_244 -- ;
V_247 [ V_241 ] . V_159 >>= 1 ;
}
V_230 = F_98 ( & V_240 -> V_25 , V_246 , 1 ) ;
if ( ! V_230 )
return - V_251 ;
V_230 -> V_234 [ 0 ] -> V_13 . V_14 = ( void * ) V_243 -> V_252 ;
if ( F_99 ( V_253 , L_28 ) ) {
F_82 ( & V_240 -> V_25 , L_29 ) ;
return - V_254 ;
}
if ( F_94 ( V_230 ) ) {
F_100 ( V_253 ) ;
F_82 ( & V_240 -> V_25 , L_30 ) ;
return - V_254 ;
}
if ( F_101 ( V_230 , F_102 ( V_240 , 0 ) ,
F_89 , V_255 , & V_256 ) != 0 ) {
F_100 ( V_253 ) ;
F_82 ( & V_240 -> V_25 , L_31 ) ;
return - V_257 ;
}
F_103 ( & V_240 -> V_25 , V_230 ) ;
return 0 ;
}
static int F_104 ( struct V_239 * V_240 )
{
struct V_116 * V_25 = & V_240 -> V_25 ;
struct V_229 * V_230 = F_105 ( V_25 ) ;
F_106 ( V_230 ) ;
F_103 ( & V_240 -> V_25 , NULL ) ;
F_100 ( V_253 ) ;
return 0 ;
}
static int F_107 ( struct V_239 * V_240 , T_4 V_258 )
{
struct V_229 * V_230 = F_105 ( & V_240 -> V_25 ) ;
if ( V_230 )
return F_108 ( V_230 , V_258 ) ;
else
return 0 ;
}
static int F_109 ( struct V_239 * V_240 )
{
struct V_229 * V_230 = F_105 ( & V_240 -> V_25 ) ;
int V_259 ;
if ( V_230 ) {
V_259 = F_94 ( V_230 ) ;
if ( V_259 ) {
F_110 (KERN_ERR DRV_NAME L_32 ) ;
return V_259 ;
}
F_111 ( V_230 ) ;
}
return 0 ;
}
static int T_5 F_112 ( void )
{
F_113 ( L_33 ) ;
switch( V_260 [ 0 ] ) {
case 'p' :
case 'P' :
break;
case 'm' :
case 'M' :
V_247 [ 0 ] . V_160 = V_261 ;
break;
default:
V_247 [ 0 ] . V_159 = V_262 ;
} ;
return F_114 ( & V_263 ) ;
}
static void T_6 F_115 ( void )
{
F_116 ( & V_263 ) ;
}
