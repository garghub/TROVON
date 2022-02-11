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
unsigned int V_59 , unsigned int V_60 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_61 = V_62 ;
F_14 ( L_3 ) ;
if ( V_59 & V_63 ) {
F_14 ( L_4 ) ;
V_61 |= V_64 ;
}
if ( V_59 & V_65 ) {
F_14 ( L_5 ) ;
V_61 |= V_66 ;
}
if ( V_58 ) {
F_14 ( L_6 , V_60 ) ;
V_61 |= ( V_60 << V_67 ) ;
}
F_3 ( V_61 , V_4 + V_68 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned long V_69 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_69 & V_70 ) {
F_14 ( L_7 ) ;
V_18 |= V_71 | V_72 ;
}
if ( V_69 & V_73 ) {
F_14 ( L_8 ) ;
V_18 |= V_71 | V_74 | V_75 ;
}
F_3 ( V_18 , V_4 + V_76 ) ;
}
static void F_26 ( void T_1 * V_4 , struct V_77 * V_78 )
{
T_2 V_79 ;
V_79 = F_2 ( V_4 + V_80 ) ;
V_78 -> V_81 ++ ;
if ( V_79 & V_82 ) {
int V_83 ;
V_78 -> V_84 = 1 ;
V_83 = ( ( V_79 & V_85 ) >>
V_86 ) ;
if ( V_83 == V_87 )
V_78 -> V_88 = V_13 ;
else if ( V_83 == V_89 )
V_78 -> V_88 = V_90 ;
else
V_78 -> V_88 = V_15 ;
V_78 -> V_91 = ( V_79 & V_92 ) ;
F_27 ( L_9 , ( int ) V_78 -> V_88 ,
V_78 -> V_91 ? L_10 : L_11 ) ;
} else {
V_78 -> V_84 = 0 ;
F_27 ( L_12 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_93 = F_2 ( V_4 + V_94 ) ;
T_2 V_95 = F_2 ( V_4 + V_22 ) ;
int V_96 = 0 ;
V_93 &= ~ V_95 ;
if ( ( V_93 & V_97 ) )
V_78 -> V_98 ++ ;
if ( F_29 ( V_93 & V_99 ) )
V_78 -> V_100 ++ ;
if ( F_29 ( V_93 & V_101 ) )
V_78 -> V_102 ++ ;
if ( F_29 ( V_93 & V_19 ) ) {
F_2 ( V_4 + V_76 ) ;
V_78 -> V_103 ++ ;
}
if ( V_93 & V_104 ) {
V_96 = F_2 ( V_4 + V_105 ) ;
if ( V_96 & V_106 )
V_78 -> V_107 ++ ;
if ( V_96 & V_108 )
V_78 -> V_109 ++ ;
if ( V_96 & V_110 )
V_78 -> V_111 ++ ;
if ( V_96 & V_112 )
V_78 -> V_113 ++ ;
}
F_30 ( V_4 , V_114 , V_93 , V_78 ) ;
if ( V_93 & V_115 )
F_26 ( V_4 , V_78 ) ;
return V_96 ;
}
static void F_31 ( struct V_1 * V_2 ,
bool V_116 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
V_6 |= V_117 | V_118 ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
V_6 &= ~ ( V_117 | V_118 ) ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_119 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
if ( V_119 )
V_6 |= V_120 ;
else
V_6 &= ~ V_120 ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_121 , int V_122 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_122 & 0xffff ) ) | ( ( V_121 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_123 ) ;
}
static void F_35 ( void T_1 * V_4 , bool V_124 , bool V_125 ,
bool V_126 )
{
F_36 ( V_4 , V_114 , V_124 , V_125 , V_126 ) ;
}
static void F_37 ( void T_1 * V_4 , bool V_127 )
{
F_38 ( V_4 , V_114 , V_127 ) ;
}
static void F_39 ( void T_1 * V_4 , struct V_128 * V_129 )
{
F_40 ( V_4 , V_114 , V_129 ) ;
}
static void F_41 ( void T_1 * V_4 , struct V_77 * V_78 )
{
T_2 V_6 = F_2 ( V_4 + V_130 ) ;
if ( V_6 & V_131 )
V_78 -> V_132 ++ ;
if ( V_6 & V_133 )
V_78 -> V_134 ++ ;
if ( V_6 & V_135 )
V_78 -> V_136 ++ ;
if ( V_6 & V_137 ) {
T_2 V_138 = ( V_6 & V_137 )
>> V_139 ;
if ( V_138 == V_140 )
V_78 -> V_141 ++ ;
else if ( V_138 == V_142 )
V_78 -> V_143 ++ ;
else if ( V_138 == V_144 )
V_78 -> V_145 ++ ;
else
V_78 -> V_146 ++ ;
}
if ( V_6 & V_147 )
V_78 -> V_148 ++ ;
if ( V_6 & V_149 ) {
T_2 V_150 = ( V_6 & V_149 )
>> V_151 ;
if ( V_150 == V_152 )
V_78 -> V_153 ++ ;
else if ( V_150 == V_154 )
V_78 -> V_155 ++ ;
else if ( V_150 == V_156 )
V_78 -> V_157 ++ ;
else
V_78 -> V_158 ++ ;
}
if ( V_6 & V_159 )
V_78 -> V_160 ++ ;
if ( V_6 & V_161 ) {
T_2 V_162 = ( V_6 & V_161 )
>> V_163 ;
if ( V_162 == V_164 )
V_78 -> V_165 ++ ;
else if ( V_162 == V_166 )
V_78 -> V_167 ++ ;
else if ( V_162 == V_168 )
V_78 -> V_169 ++ ;
else
V_78 -> V_170 ++ ;
}
if ( V_6 & V_171 ) {
T_2 V_172 = ( V_6 & V_171 ) >>
V_163 ;
if ( V_172 == V_173 )
V_78 -> V_174 ++ ;
else if ( V_172 == V_175 )
V_78 -> V_176 ++ ;
else if ( V_172 == V_177 )
V_78 -> V_178 ++ ;
else
V_78 -> V_179 ++ ;
}
if ( V_6 & V_180 )
V_78 -> V_181 ++ ;
if ( V_6 & V_182 )
V_78 -> V_183 = ( V_6 & V_182 )
>> V_184 ;
if ( V_6 & V_185 )
V_78 -> V_186 ++ ;
}
struct V_1 * F_42 ( void T_1 * V_4 , int V_187 ,
int V_188 ,
int * V_189 )
{
struct V_1 * V_190 ;
T_2 V_191 = F_2 ( V_4 + V_192 ) ;
V_190 = F_43 ( sizeof( const struct V_1 ) , V_193 ) ;
if ( ! V_190 )
return NULL ;
V_190 -> V_5 = V_4 ;
V_190 -> V_194 = V_187 ;
V_190 -> V_41 = V_188 ;
V_190 -> V_43 = 0 ;
if ( V_190 -> V_194 )
V_190 -> V_43 = F_44 ( V_190 -> V_194 ) ;
V_190 -> V_190 = & V_195 ;
V_190 -> V_196 = & V_197 ;
V_190 -> V_119 . V_198 = V_14 ;
V_190 -> V_119 . V_58 = V_199 ;
V_190 -> V_119 . V_200 = V_16 ;
V_190 -> V_201 . V_28 = V_202 ;
V_190 -> V_201 . V_203 = V_204 ;
V_190 -> V_201 . V_205 = 11 ;
V_190 -> V_201 . V_206 = 0x0000F800 ;
V_190 -> V_201 . V_207 = 6 ;
V_190 -> V_201 . V_208 = 0x000007C0 ;
V_190 -> V_201 . V_209 = 2 ;
V_190 -> V_201 . V_210 = F_45 ( 5 , 2 ) ;
* V_189 = F_46 ( V_191 ) ;
return V_190 ;
}
