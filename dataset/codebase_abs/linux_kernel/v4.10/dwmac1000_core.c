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
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_26 ;
F_7 ( L_1 , V_4 ) ;
for ( V_26 = 0 ; V_26 < 55 ; V_26 ++ ) {
int V_27 = V_26 * 4 ;
F_7 ( L_2 , V_26 ,
V_27 , F_2 ( V_4 + V_27 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_28 ,
unsigned int V_29 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_28 , F_10 ( V_29 ) ,
F_11 ( V_29 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned char * V_28 ,
unsigned int V_29 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_13 ( V_4 , V_28 , F_10 ( V_29 ) ,
F_11 ( V_29 ) ) ;
}
static void F_14 ( void T_1 * V_4 , T_2 * V_30 ,
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
F_15 ( L_3 ) ;
return;
break;
}
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
F_3 ( V_30 [ V_33 ] ,
V_4 + V_36 + V_33 * 4 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
void T_1 * V_4 = ( void T_1 * ) V_38 -> V_39 ;
unsigned int V_6 = 0 ;
unsigned int V_40 = V_2 -> V_41 ;
T_2 V_42 [ 8 ] ;
int V_31 = V_2 -> V_43 ;
F_15 ( L_4 , V_44 ,
F_17 ( V_38 ) , F_18 ( V_38 ) ) ;
memset ( V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_38 -> V_45 & V_46 ) {
V_6 = V_47 ;
} else if ( V_38 -> V_45 & V_48 ) {
V_6 = V_49 ;
} else if ( ! F_19 ( V_38 ) ) {
struct V_50 * V_51 ;
V_6 = V_52 ;
F_20 (ha, dev) {
int V_53 = F_21 ( ~ F_22 ( ~ 0 , V_51 -> V_28 ,
V_54 ) ) >>
( 32 - V_31 ) ;
V_42 [ V_53 >> 5 ] |= 1 << ( V_53 & 31 ) ;
}
}
F_14 ( V_4 , V_42 , V_31 ) ;
if ( F_18 ( V_38 ) > V_40 )
V_6 |= V_47 ;
else {
int V_55 = 1 ;
struct V_50 * V_51 ;
F_23 (ha, dev) {
F_9 ( V_4 , V_51 -> V_28 ,
F_10 ( V_55 ) ,
F_11 ( V_55 ) ) ;
V_55 ++ ;
}
}
#ifdef F_24
V_6 |= V_56 ;
#endif
F_3 ( V_6 , V_4 + V_57 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_58 ,
unsigned int V_59 , unsigned int V_60 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_61 = V_62 ;
F_15 ( L_5 ) ;
if ( V_59 & V_63 ) {
F_15 ( L_6 ) ;
V_61 |= V_64 ;
}
if ( V_59 & V_65 ) {
F_15 ( L_7 ) ;
V_61 |= V_66 ;
}
if ( V_58 ) {
F_15 ( L_8 , V_60 ) ;
V_61 |= ( V_60 << V_67 ) ;
}
F_3 ( V_61 , V_4 + V_68 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_69 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_69 & V_70 ) {
F_15 ( L_9 ) ;
V_18 |= V_71 | V_72 ;
}
if ( V_69 & V_73 ) {
F_15 ( L_10 ) ;
V_18 |= V_71 | V_74 | V_75 ;
}
F_3 ( V_18 , V_4 + V_76 ) ;
}
static void F_27 ( void T_1 * V_4 , struct V_77 * V_78 )
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
F_7 ( L_11 , ( int ) V_78 -> V_88 ,
V_78 -> V_91 ? L_12 : L_13 ) ;
} else {
V_78 -> V_84 = 0 ;
F_7 ( L_14 ) ;
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
F_27 ( V_4 , V_78 ) ;
return V_96 ;
}
static void F_31 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
V_6 |= V_116 | V_117 ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
V_6 &= ~ ( V_116 | V_117 ) ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_118 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_105 ) ;
if ( V_118 )
V_6 |= V_119 ;
else
V_6 &= ~ V_119 ;
F_3 ( V_6 , V_4 + V_105 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_120 , int V_121 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_121 & 0xffff ) ) | ( ( V_120 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_122 ) ;
}
static void F_35 ( void T_1 * V_4 , bool V_123 , bool V_124 ,
bool V_125 )
{
F_36 ( V_4 , V_114 , V_123 , V_124 , V_125 ) ;
}
static void F_37 ( void T_1 * V_4 , bool V_126 )
{
F_38 ( V_4 , V_114 , V_126 ) ;
}
static void F_39 ( void T_1 * V_4 , struct V_127 * V_128 )
{
F_40 ( V_4 , V_114 , V_128 ) ;
}
static void F_41 ( void T_1 * V_4 , struct V_77 * V_78 )
{
T_2 V_6 = F_2 ( V_4 + V_129 ) ;
if ( V_6 & V_130 )
V_78 -> V_131 ++ ;
if ( V_6 & V_132 )
V_78 -> V_133 ++ ;
if ( V_6 & V_134 )
V_78 -> V_135 ++ ;
if ( V_6 & V_136 ) {
T_2 V_137 = ( V_6 & V_136 )
>> V_138 ;
if ( V_137 == V_139 )
V_78 -> V_140 ++ ;
else if ( V_137 == V_141 )
V_78 -> V_142 ++ ;
else if ( V_137 == V_143 )
V_78 -> V_144 ++ ;
else
V_78 -> V_145 ++ ;
}
if ( V_6 & V_146 )
V_78 -> V_147 ++ ;
if ( V_6 & V_148 ) {
T_2 V_149 = ( V_6 & V_148 )
>> V_150 ;
if ( V_149 == V_151 )
V_78 -> V_152 ++ ;
else if ( V_149 == V_153 )
V_78 -> V_154 ++ ;
else if ( V_149 == V_155 )
V_78 -> V_156 ++ ;
else
V_78 -> V_157 ++ ;
}
if ( V_6 & V_158 )
V_78 -> V_159 ++ ;
if ( V_6 & V_160 ) {
T_2 V_161 = ( V_6 & V_160 )
>> V_162 ;
if ( V_161 == V_163 )
V_78 -> V_164 ++ ;
else if ( V_161 == V_165 )
V_78 -> V_166 ++ ;
else if ( V_161 == V_167 )
V_78 -> V_168 ++ ;
else
V_78 -> V_169 ++ ;
}
if ( V_6 & V_170 ) {
T_2 V_171 = ( V_6 & V_170 ) >>
V_162 ;
if ( V_171 == V_172 )
V_78 -> V_173 ++ ;
else if ( V_171 == V_174 )
V_78 -> V_175 ++ ;
else if ( V_171 == V_176 )
V_78 -> V_177 ++ ;
else
V_78 -> V_178 ++ ;
}
if ( V_6 & V_179 )
V_78 -> V_180 ++ ;
if ( V_6 & V_181 )
V_78 -> V_182 = ( V_6 & V_181 )
>> V_183 ;
if ( V_6 & V_184 )
V_78 -> V_185 ++ ;
}
struct V_1 * F_42 ( void T_1 * V_4 , int V_186 ,
int V_187 ,
int * V_188 )
{
struct V_1 * V_189 ;
T_2 V_190 = F_2 ( V_4 + V_191 ) ;
V_189 = F_43 ( sizeof( const struct V_1 ) , V_192 ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_5 = V_4 ;
V_189 -> V_193 = V_186 ;
V_189 -> V_41 = V_187 ;
V_189 -> V_43 = 0 ;
if ( V_189 -> V_193 )
V_189 -> V_43 = F_44 ( V_189 -> V_193 ) ;
V_189 -> V_189 = & V_194 ;
V_189 -> V_195 = & V_196 ;
V_189 -> V_118 . V_197 = V_14 ;
V_189 -> V_118 . V_58 = V_198 ;
V_189 -> V_118 . V_199 = V_16 ;
V_189 -> V_200 . V_28 = V_201 ;
V_189 -> V_200 . V_202 = V_203 ;
V_189 -> V_200 . V_204 = 11 ;
V_189 -> V_200 . V_205 = 0x0000F800 ;
V_189 -> V_200 . V_206 = 6 ;
V_189 -> V_200 . V_207 = 0x000007C0 ;
V_189 -> V_200 . V_208 = 2 ;
V_189 -> V_200 . V_209 = F_45 ( 5 , 2 ) ;
* V_188 = F_46 ( V_190 ) ;
return V_189 ;
}
