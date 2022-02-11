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
V_6 &= ~ V_2 -> V_13 . V_14 ;
switch ( V_2 -> V_11 ) {
case V_15 :
V_6 |= V_2 -> V_13 . V_16 ;
break;
case V_17 :
V_6 |= V_2 -> V_13 . V_18 ;
break;
case V_19 :
V_6 |= V_2 -> V_13 . V_20 ;
break;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = V_21 ;
if ( V_2 -> V_22 )
V_6 &= ~ V_23 ;
if ( V_2 -> V_24 )
V_6 &= ~ V_25 ;
F_3 ( V_6 , V_4 + V_26 ) ;
#ifdef F_4
F_3 ( 0x0 , V_4 + V_27 ) ;
#endif
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_28 )
V_6 |= V_29 ;
else
V_6 &= ~ V_29 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_29 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 * V_30 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 55 ; V_31 ++ )
V_30 [ V_31 ] = F_2 ( V_4 + V_31 * 4 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned char * V_32 ,
unsigned int V_33 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_8 ( V_4 , V_32 , F_9 ( V_33 ) ,
F_10 ( V_33 ) ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char * V_32 ,
unsigned int V_33 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_12 ( V_4 , V_32 , F_9 ( V_33 ) ,
F_10 ( V_33 ) ) ;
}
static void F_13 ( void T_1 * V_4 , T_2 * V_34 ,
int V_35 )
{
int V_36 , V_37 ;
switch ( V_35 ) {
case 6 :
F_3 ( V_34 [ 0 ] , V_4 + V_38 ) ;
F_3 ( V_34 [ 1 ] , V_4 + V_39 ) ;
return;
break;
case 7 :
V_36 = 4 ;
break;
case 8 :
V_36 = 8 ;
break;
default:
F_14 ( L_1 ) ;
return;
break;
}
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
F_3 ( V_34 [ V_37 ] ,
V_4 + V_40 + V_37 * 4 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
void T_1 * V_4 = ( void T_1 * ) V_42 -> V_43 ;
unsigned int V_6 = 0 ;
unsigned int V_44 = V_2 -> V_45 ;
T_2 V_46 [ 8 ] ;
int V_35 = V_2 -> V_47 ;
F_14 ( L_2 , V_48 ,
F_16 ( V_42 ) , F_17 ( V_42 ) ) ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
if ( V_42 -> V_49 & V_50 ) {
V_6 = V_51 ;
} else if ( V_42 -> V_49 & V_52 ) {
V_6 = V_53 ;
} else if ( ! F_18 ( V_42 ) ) {
struct V_54 * V_55 ;
V_6 = V_56 ;
F_19 (ha, dev) {
int V_57 = F_20 ( ~ F_21 ( ~ 0 , V_55 -> V_32 ,
V_58 ) ) >>
( 32 - V_35 ) ;
V_46 [ V_57 >> 5 ] |= 1 << ( V_57 & 31 ) ;
}
}
F_13 ( V_4 , V_46 , V_35 ) ;
if ( F_17 ( V_42 ) > V_44 )
V_6 |= V_51 ;
else {
int V_59 = 1 ;
struct V_54 * V_55 ;
F_22 (ha, dev) {
F_8 ( V_4 , V_55 -> V_32 ,
F_9 ( V_59 ) ,
F_10 ( V_59 ) ) ;
V_59 ++ ;
}
}
#ifdef F_23
V_6 |= V_60 ;
#endif
F_3 ( V_6 , V_4 + V_61 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned int V_63 , unsigned int V_64 ,
T_2 V_65 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_66 = V_67 ;
F_14 ( L_3 ) ;
if ( V_63 & V_68 ) {
F_14 ( L_4 ) ;
V_66 |= V_69 ;
}
if ( V_63 & V_70 ) {
F_14 ( L_5 ) ;
V_66 |= V_71 ;
}
if ( V_62 ) {
F_14 ( L_6 , V_64 ) ;
V_66 |= ( V_64 << V_72 ) ;
}
F_3 ( V_66 , V_4 + V_73 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned long V_74 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_22 = 0 ;
if ( V_74 & V_75 ) {
F_14 ( L_7 ) ;
V_22 |= V_76 | V_77 ;
}
if ( V_74 & V_78 ) {
F_14 ( L_8 ) ;
V_22 |= V_76 | V_79 | V_80 ;
}
F_3 ( V_22 , V_4 + V_81 ) ;
}
static void F_26 ( void T_1 * V_4 , struct V_82 * V_83 )
{
T_2 V_84 ;
V_84 = F_2 ( V_4 + V_85 ) ;
V_83 -> V_86 ++ ;
if ( V_84 & V_87 ) {
int V_88 ;
V_83 -> V_89 = 1 ;
V_88 = ( ( V_84 & V_90 ) >>
V_91 ) ;
if ( V_88 == V_92 )
V_83 -> V_93 = V_15 ;
else if ( V_88 == V_94 )
V_83 -> V_93 = V_17 ;
else
V_83 -> V_93 = V_19 ;
V_83 -> V_95 = ( V_84 & V_96 ) ;
F_27 ( L_9 , ( int ) V_83 -> V_93 ,
V_83 -> V_95 ? L_10 : L_11 ) ;
} else {
V_83 -> V_89 = 0 ;
F_27 ( L_12 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_97 = F_2 ( V_4 + V_98 ) ;
T_2 V_99 = F_2 ( V_4 + V_26 ) ;
int V_100 = 0 ;
V_97 &= ~ V_99 ;
if ( ( V_97 & V_101 ) )
V_83 -> V_102 ++ ;
if ( F_29 ( V_97 & V_103 ) )
V_83 -> V_104 ++ ;
if ( F_29 ( V_97 & V_105 ) )
V_83 -> V_106 ++ ;
if ( F_29 ( V_97 & V_23 ) ) {
F_2 ( V_4 + V_81 ) ;
V_83 -> V_107 ++ ;
}
if ( V_97 & V_108 ) {
V_100 = F_2 ( V_4 + V_109 ) ;
if ( V_100 & V_110 )
V_83 -> V_111 ++ ;
if ( V_100 & V_112 )
V_83 -> V_113 ++ ;
if ( V_100 & V_114 )
V_83 -> V_115 ++ ;
if ( V_100 & V_116 )
V_83 -> V_117 ++ ;
}
F_30 ( V_4 , V_118 , V_97 , V_83 ) ;
if ( V_97 & V_119 )
F_26 ( V_4 , V_83 ) ;
return V_100 ;
}
static void F_31 ( struct V_1 * V_2 ,
bool V_120 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
V_6 |= V_121 | V_122 ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
V_6 &= ~ ( V_121 | V_122 ) ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_13 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_109 ) ;
if ( V_13 )
V_6 |= V_123 ;
else
V_6 &= ~ V_123 ;
F_3 ( V_6 , V_4 + V_109 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_124 , int V_125 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_125 & 0xffff ) ) | ( ( V_124 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_126 ) ;
}
static void F_35 ( void T_1 * V_4 , bool V_127 , bool V_128 ,
bool V_129 )
{
F_36 ( V_4 , V_118 , V_127 , V_128 , V_129 ) ;
}
static void F_37 ( void T_1 * V_4 , bool V_130 )
{
F_38 ( V_4 , V_118 , V_130 ) ;
}
static void F_39 ( void T_1 * V_4 , struct V_131 * V_132 )
{
F_40 ( V_4 , V_118 , V_132 ) ;
}
static void F_41 ( void T_1 * V_4 , struct V_82 * V_83 ,
T_2 V_133 , T_2 V_134 )
{
T_2 V_6 = F_2 ( V_4 + V_135 ) ;
if ( V_6 & V_136 )
V_83 -> V_137 ++ ;
if ( V_6 & V_138 )
V_83 -> V_139 ++ ;
if ( V_6 & V_140 )
V_83 -> V_141 ++ ;
if ( V_6 & V_142 ) {
T_2 V_143 = ( V_6 & V_142 )
>> V_144 ;
if ( V_143 == V_145 )
V_83 -> V_146 ++ ;
else if ( V_143 == V_147 )
V_83 -> V_148 ++ ;
else if ( V_143 == V_149 )
V_83 -> V_150 ++ ;
else
V_83 -> V_151 ++ ;
}
if ( V_6 & V_152 )
V_83 -> V_153 ++ ;
if ( V_6 & V_154 ) {
T_2 V_155 = ( V_6 & V_154 )
>> V_156 ;
if ( V_155 == V_157 )
V_83 -> V_158 ++ ;
else if ( V_155 == V_159 )
V_83 -> V_160 ++ ;
else if ( V_155 == V_161 )
V_83 -> V_162 ++ ;
else
V_83 -> V_163 ++ ;
}
if ( V_6 & V_164 )
V_83 -> V_165 ++ ;
if ( V_6 & V_166 ) {
T_2 V_167 = ( V_6 & V_166 )
>> V_168 ;
if ( V_167 == V_169 )
V_83 -> V_170 ++ ;
else if ( V_167 == V_171 )
V_83 -> V_172 ++ ;
else if ( V_167 == V_173 )
V_83 -> V_174 ++ ;
else
V_83 -> V_175 ++ ;
}
if ( V_6 & V_176 ) {
T_2 V_177 = ( V_6 & V_176 ) >>
V_168 ;
if ( V_177 == V_178 )
V_83 -> V_179 ++ ;
else if ( V_177 == V_180 )
V_83 -> V_181 ++ ;
else if ( V_177 == V_182 )
V_83 -> V_183 ++ ;
else
V_83 -> V_184 ++ ;
}
if ( V_6 & V_185 )
V_83 -> V_186 ++ ;
if ( V_6 & V_187 )
V_83 -> V_188 = ( V_6 & V_187 )
>> V_189 ;
if ( V_6 & V_190 )
V_83 -> V_191 ++ ;
}
struct V_1 * F_42 ( void T_1 * V_4 , int V_192 ,
int V_193 ,
int * V_194 )
{
struct V_1 * V_195 ;
T_2 V_196 = F_2 ( V_4 + V_197 ) ;
V_195 = F_43 ( sizeof( const struct V_1 ) , V_198 ) ;
if ( ! V_195 )
return NULL ;
V_195 -> V_5 = V_4 ;
V_195 -> V_199 = V_192 ;
V_195 -> V_45 = V_193 ;
V_195 -> V_47 = 0 ;
if ( V_195 -> V_199 )
V_195 -> V_47 = F_44 ( V_195 -> V_199 ) ;
V_195 -> V_195 = & V_200 ;
V_195 -> V_201 = & V_202 ;
V_195 -> V_13 . V_62 = V_203 ;
V_195 -> V_13 . V_20 = V_204 ;
V_195 -> V_13 . V_18 = V_204 | V_205 ;
V_195 -> V_13 . V_16 = 0 ;
V_195 -> V_13 . V_14 = V_204 | V_205 ;
V_195 -> V_206 . V_32 = V_207 ;
V_195 -> V_206 . V_208 = V_209 ;
V_195 -> V_206 . V_210 = 11 ;
V_195 -> V_206 . V_211 = 0x0000F800 ;
V_195 -> V_206 . V_212 = 6 ;
V_195 -> V_206 . V_213 = 0x000007C0 ;
V_195 -> V_206 . V_214 = 2 ;
V_195 -> V_206 . V_215 = F_45 ( 5 , 2 ) ;
* V_194 = F_46 ( V_196 ) ;
return V_195 ;
}
