static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
V_6 |= V_8 ;
if ( V_3 > 1500 )
V_6 |= V_9 ;
if ( V_3 > 2000 )
V_6 |= V_10 ;
if ( V_2 -> V_11 ) {
V_6 |= V_12 ;
if ( V_2 -> V_11 == V_13 ) {
V_6 &= ~ V_14 ;
} else {
V_6 |= V_14 ;
if ( V_2 -> V_11 == V_15 )
V_6 &= ~ V_16 ;
else
V_6 |= V_16 ;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = V_17 ;
if ( V_2 -> V_18 )
V_6 &= ~ V_19 ;
if ( V_2 -> V_20 )
V_6 &= ~ V_21 ;
F_3 ( V_6 , V_4 + V_22 ) ;
#ifdef F_4
F_3 ( 0x0 , V_4 + V_23 ) ;
#endif
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_24 )
V_6 |= V_25 ;
else
V_6 &= ~ V_25 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_25 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 * V_26 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 55 ; V_27 ++ )
V_26 [ V_27 ] = F_2 ( V_4 + V_27 * 4 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned char * V_28 ,
unsigned int V_29 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_8 ( V_4 , V_28 , F_9 ( V_29 ) ,
F_10 ( V_29 ) ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char * V_28 ,
unsigned int V_29 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_12 ( V_4 , V_28 , F_9 ( V_29 ) ,
F_10 ( V_29 ) ) ;
}
static void F_13 ( void T_1 * V_4 , T_2 * V_30 ,
int V_31 )
{
int V_32 , V_33 ;
switch ( V_31 ) {
case 6 :
F_3 ( V_30 [ 0 ] , V_4 + V_34 ) ;
F_3 ( V_30 [ 1 ] , V_4 + V_35 ) ;
return;
break;
case 7 :
V_32 = 4 ;
break;
case 8 :
V_32 = 8 ;
break;
default:
F_14 ( L_1 ) ;
return;
break;
}
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
F_3 ( V_30 [ V_33 ] ,
V_4 + V_36 + V_33 * 4 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
void T_1 * V_4 = ( void T_1 * ) V_38 -> V_39 ;
unsigned int V_6 = 0 ;
unsigned int V_40 = V_2 -> V_41 ;
T_2 V_42 [ 8 ] ;
int V_31 = V_2 -> V_43 ;
F_14 ( L_2 , V_44 ,
F_16 ( V_38 ) , F_17 ( V_38 ) ) ;
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_38 -> V_45 & V_46 ) {
V_6 = V_47 ;
} else if ( V_38 -> V_45 & V_48 ) {
V_6 = V_49 ;
} else if ( ! F_18 ( V_38 ) ) {
struct V_50 * V_51 ;
V_6 = V_52 ;
F_19 (ha, dev) {
int V_53 = F_20 ( ~ F_21 ( ~ 0 , V_51 -> V_28 ,
V_54 ) ) >>
( 32 - V_31 ) ;
V_42 [ V_53 >> 5 ] |= 1 << ( V_53 & 31 ) ;
}
}
F_13 ( V_4 , V_42 , V_31 ) ;
if ( F_17 ( V_38 ) > V_40 )
V_6 |= V_47 ;
else {
int V_55 = 1 ;
struct V_50 * V_51 ;
F_22 (ha, dev) {
F_8 ( V_4 , V_51 -> V_28 ,
F_9 ( V_55 ) ,
F_10 ( V_55 ) ) ;
V_55 ++ ;
}
}
#ifdef F_23
V_6 |= V_56 ;
#endif
F_3 ( V_6 , V_4 + V_57 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_58 ,
unsigned int V_59 , unsigned int V_60 ,
T_2 V_61 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_62 = V_63 ;
F_14 ( L_3 ) ;
if ( V_59 & V_64 ) {
F_14 ( L_4 ) ;
V_62 |= V_65 ;
}
if ( V_59 & V_66 ) {
F_14 ( L_5 ) ;
V_62 |= V_67 ;
}
if ( V_58 ) {
F_14 ( L_6 , V_60 ) ;
V_62 |= ( V_60 << V_68 ) ;
}
F_3 ( V_62 , V_4 + V_69 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned long V_70 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_70 & V_71 ) {
F_14 ( L_7 ) ;
V_18 |= V_72 | V_73 ;
}
if ( V_70 & V_74 ) {
F_14 ( L_8 ) ;
V_18 |= V_72 | V_75 | V_76 ;
}
F_3 ( V_18 , V_4 + V_77 ) ;
}
static void F_26 ( void T_1 * V_4 , struct V_78 * V_79 )
{
T_2 V_80 ;
V_80 = F_2 ( V_4 + V_81 ) ;
V_79 -> V_82 ++ ;
if ( V_80 & V_83 ) {
int V_84 ;
V_79 -> V_85 = 1 ;
V_84 = ( ( V_80 & V_86 ) >>
V_87 ) ;
if ( V_84 == V_88 )
V_79 -> V_89 = V_13 ;
else if ( V_84 == V_90 )
V_79 -> V_89 = V_91 ;
else
V_79 -> V_89 = V_15 ;
V_79 -> V_92 = ( V_80 & V_93 ) ;
F_27 ( L_9 , ( int ) V_79 -> V_89 ,
V_79 -> V_92 ? L_10 : L_11 ) ;
} else {
V_79 -> V_85 = 0 ;
F_27 ( L_12 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_94 = F_2 ( V_4 + V_95 ) ;
T_2 V_96 = F_2 ( V_4 + V_22 ) ;
int V_97 = 0 ;
V_94 &= ~ V_96 ;
if ( ( V_94 & V_98 ) )
V_79 -> V_99 ++ ;
if ( F_29 ( V_94 & V_100 ) )
V_79 -> V_101 ++ ;
if ( F_29 ( V_94 & V_102 ) )
V_79 -> V_103 ++ ;
if ( F_29 ( V_94 & V_19 ) ) {
F_2 ( V_4 + V_77 ) ;
V_79 -> V_104 ++ ;
}
if ( V_94 & V_105 ) {
V_97 = F_2 ( V_4 + V_106 ) ;
if ( V_97 & V_107 )
V_79 -> V_108 ++ ;
if ( V_97 & V_109 )
V_79 -> V_110 ++ ;
if ( V_97 & V_111 )
V_79 -> V_112 ++ ;
if ( V_97 & V_113 )
V_79 -> V_114 ++ ;
}
F_30 ( V_4 , V_115 , V_94 , V_79 ) ;
if ( V_94 & V_116 )
F_26 ( V_4 , V_79 ) ;
return V_97 ;
}
static void F_31 ( struct V_1 * V_2 ,
bool V_117 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_106 ) ;
V_6 |= V_118 | V_119 ;
F_3 ( V_6 , V_4 + V_106 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_106 ) ;
V_6 &= ~ ( V_118 | V_119 ) ;
F_3 ( V_6 , V_4 + V_106 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_120 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_106 ) ;
if ( V_120 )
V_6 |= V_121 ;
else
V_6 &= ~ V_121 ;
F_3 ( V_6 , V_4 + V_106 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_122 , int V_123 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_123 & 0xffff ) ) | ( ( V_122 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_124 ) ;
}
static void F_35 ( void T_1 * V_4 , bool V_125 , bool V_126 ,
bool V_127 )
{
F_36 ( V_4 , V_115 , V_125 , V_126 , V_127 ) ;
}
static void F_37 ( void T_1 * V_4 , bool V_128 )
{
F_38 ( V_4 , V_115 , V_128 ) ;
}
static void F_39 ( void T_1 * V_4 , struct V_129 * V_130 )
{
F_40 ( V_4 , V_115 , V_130 ) ;
}
static void F_41 ( void T_1 * V_4 , struct V_78 * V_79 ,
T_2 V_131 , T_2 V_132 )
{
T_2 V_6 = F_2 ( V_4 + V_133 ) ;
if ( V_6 & V_134 )
V_79 -> V_135 ++ ;
if ( V_6 & V_136 )
V_79 -> V_137 ++ ;
if ( V_6 & V_138 )
V_79 -> V_139 ++ ;
if ( V_6 & V_140 ) {
T_2 V_141 = ( V_6 & V_140 )
>> V_142 ;
if ( V_141 == V_143 )
V_79 -> V_144 ++ ;
else if ( V_141 == V_145 )
V_79 -> V_146 ++ ;
else if ( V_141 == V_147 )
V_79 -> V_148 ++ ;
else
V_79 -> V_149 ++ ;
}
if ( V_6 & V_150 )
V_79 -> V_151 ++ ;
if ( V_6 & V_152 ) {
T_2 V_153 = ( V_6 & V_152 )
>> V_154 ;
if ( V_153 == V_155 )
V_79 -> V_156 ++ ;
else if ( V_153 == V_157 )
V_79 -> V_158 ++ ;
else if ( V_153 == V_159 )
V_79 -> V_160 ++ ;
else
V_79 -> V_161 ++ ;
}
if ( V_6 & V_162 )
V_79 -> V_163 ++ ;
if ( V_6 & V_164 ) {
T_2 V_165 = ( V_6 & V_164 )
>> V_166 ;
if ( V_165 == V_167 )
V_79 -> V_168 ++ ;
else if ( V_165 == V_169 )
V_79 -> V_170 ++ ;
else if ( V_165 == V_171 )
V_79 -> V_172 ++ ;
else
V_79 -> V_173 ++ ;
}
if ( V_6 & V_174 ) {
T_2 V_175 = ( V_6 & V_174 ) >>
V_166 ;
if ( V_175 == V_176 )
V_79 -> V_177 ++ ;
else if ( V_175 == V_178 )
V_79 -> V_179 ++ ;
else if ( V_175 == V_180 )
V_79 -> V_181 ++ ;
else
V_79 -> V_182 ++ ;
}
if ( V_6 & V_183 )
V_79 -> V_184 ++ ;
if ( V_6 & V_185 )
V_79 -> V_186 = ( V_6 & V_185 )
>> V_187 ;
if ( V_6 & V_188 )
V_79 -> V_189 ++ ;
}
struct V_1 * F_42 ( void T_1 * V_4 , int V_190 ,
int V_191 ,
int * V_192 )
{
struct V_1 * V_193 ;
T_2 V_194 = F_2 ( V_4 + V_195 ) ;
V_193 = F_43 ( sizeof( const struct V_1 ) , V_196 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_5 = V_4 ;
V_193 -> V_197 = V_190 ;
V_193 -> V_41 = V_191 ;
V_193 -> V_43 = 0 ;
if ( V_193 -> V_197 )
V_193 -> V_43 = F_44 ( V_193 -> V_197 ) ;
V_193 -> V_193 = & V_198 ;
V_193 -> V_199 = & V_200 ;
V_193 -> V_120 . V_201 = V_14 ;
V_193 -> V_120 . V_58 = V_202 ;
V_193 -> V_120 . V_203 = V_16 ;
V_193 -> V_204 . V_28 = V_205 ;
V_193 -> V_204 . V_206 = V_207 ;
V_193 -> V_204 . V_208 = 11 ;
V_193 -> V_204 . V_209 = 0x0000F800 ;
V_193 -> V_204 . V_210 = 6 ;
V_193 -> V_204 . V_211 = 0x000007C0 ;
V_193 -> V_204 . V_212 = 2 ;
V_193 -> V_204 . V_213 = F_45 ( 5 , 2 ) ;
* V_192 = F_46 ( V_194 ) ;
return V_193 ;
}
