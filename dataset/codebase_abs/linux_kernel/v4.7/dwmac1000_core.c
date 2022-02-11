static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
V_6 |= V_8 ;
if ( V_3 > 1500 )
V_6 |= V_9 ;
if ( V_3 > 2000 )
V_6 |= V_10 ;
F_3 ( V_6 , V_4 + V_7 ) ;
F_3 ( 0x207 , V_4 + V_11 ) ;
#ifdef F_4
F_3 ( 0x0 , V_4 + V_12 ) ;
#endif
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_13 )
V_6 |= V_14 ;
else
V_6 &= ~ V_14 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_15 ;
F_7 ( L_1 , V_4 ) ;
for ( V_15 = 0 ; V_15 < 55 ; V_15 ++ ) {
int V_16 = V_15 * 4 ;
F_7 ( L_2 , V_15 ,
V_16 , F_2 ( V_4 + V_16 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_17 ,
unsigned int V_18 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_17 , F_10 ( V_18 ) ,
F_11 ( V_18 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned char * V_17 ,
unsigned int V_18 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_13 ( V_4 , V_17 , F_10 ( V_18 ) ,
F_11 ( V_18 ) ) ;
}
static void F_14 ( void T_1 * V_4 , T_2 * V_19 ,
int V_20 )
{
int V_21 , V_22 ;
switch ( V_20 ) {
case 6 :
F_3 ( V_19 [ 0 ] , V_4 + V_23 ) ;
F_3 ( V_19 [ 1 ] , V_4 + V_24 ) ;
return;
break;
case 7 :
V_21 = 4 ;
break;
case 8 :
V_21 = 8 ;
break;
default:
F_15 ( L_3 ) ;
return;
break;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
F_3 ( V_19 [ V_22 ] ,
V_4 + V_25 + V_22 * 4 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
void T_1 * V_4 = ( void T_1 * ) V_27 -> V_28 ;
unsigned int V_6 = 0 ;
unsigned int V_29 = V_2 -> V_30 ;
T_2 V_31 [ 8 ] ;
int V_20 = V_2 -> V_32 ;
F_15 ( L_4 , V_33 ,
F_17 ( V_27 ) , F_18 ( V_27 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
if ( V_27 -> V_34 & V_35 ) {
V_6 = V_36 ;
} else if ( V_27 -> V_34 & V_37 ) {
V_6 = V_38 ;
} else if ( ! F_19 ( V_27 ) ) {
struct V_39 * V_40 ;
V_6 = V_41 ;
F_20 (ha, dev) {
int V_42 = F_21 ( ~ F_22 ( ~ 0 , V_40 -> V_17 ,
V_43 ) ) >>
( 32 - V_20 ) ;
V_31 [ V_42 >> 5 ] |= 1 << ( V_42 & 31 ) ;
}
}
F_14 ( V_4 , V_31 , V_20 ) ;
if ( F_18 ( V_27 ) > V_29 )
V_6 |= V_36 ;
else {
int V_44 = 1 ;
struct V_39 * V_40 ;
F_23 (ha, dev) {
F_9 ( V_4 , V_40 -> V_17 ,
F_10 ( V_44 ) ,
F_11 ( V_44 ) ) ;
V_44 ++ ;
}
}
#ifdef F_24
V_6 |= V_45 ;
#endif
F_3 ( V_6 , V_4 + V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_47 ,
unsigned int V_48 , unsigned int V_49 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_50 = V_51 ;
F_15 ( L_5 ) ;
if ( V_48 & V_52 ) {
F_15 ( L_6 ) ;
V_50 |= V_53 ;
}
if ( V_48 & V_54 ) {
F_15 ( L_7 ) ;
V_50 |= V_55 ;
}
if ( V_47 ) {
F_15 ( L_8 , V_49 ) ;
V_50 |= ( V_49 << V_56 ) ;
}
F_3 ( V_50 , V_4 + V_57 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_58 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_59 = 0 ;
if ( V_58 & V_60 ) {
F_15 ( L_9 ) ;
V_59 |= V_61 | V_62 ;
}
if ( V_58 & V_63 ) {
F_15 ( L_10 ) ;
V_59 |= V_64 ;
}
F_3 ( V_59 , V_4 + V_65 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_68 = F_2 ( V_4 + V_69 ) ;
int V_70 = 0 ;
if ( ( V_68 & V_71 ) )
V_67 -> V_72 ++ ;
if ( F_28 ( V_68 & V_73 ) )
V_67 -> V_74 ++ ;
if ( F_28 ( V_68 & V_75 ) )
V_67 -> V_76 ++ ;
if ( F_28 ( V_68 & V_77 ) ) {
F_2 ( V_4 + V_65 ) ;
V_67 -> V_78 ++ ;
}
if ( V_68 & V_79 ) {
V_70 = F_2 ( V_4 + V_80 ) ;
if ( V_70 & V_81 )
V_67 -> V_82 ++ ;
if ( V_70 & V_83 )
V_67 -> V_84 ++ ;
if ( V_70 & V_85 )
V_67 -> V_86 ++ ;
if ( V_70 & V_87 )
V_67 -> V_88 ++ ;
}
if ( ( V_68 & V_89 ) || ( V_68 & V_90 ) ) {
F_2 ( V_4 + V_91 ) ;
V_67 -> V_92 ++ ;
}
if ( V_68 & V_93 ) {
T_2 V_94 = F_2 ( V_4 + V_95 ) ;
V_67 -> V_96 ++ ;
if ( V_94 & V_97 ) {
int V_98 = ( V_94 & V_99 ) >>
V_100 ;
V_67 -> V_101 = ( V_94 & V_102 ) ;
if ( V_98 == V_103 )
V_67 -> V_104 = V_105 ;
else if ( V_98 == V_106 )
V_67 -> V_104 = V_107 ;
else
V_67 -> V_104 = V_108 ;
V_67 -> V_109 = 1 ;
F_15 ( L_11 , V_33 ,
( int ) V_67 -> V_104 ,
V_67 -> V_101 ? L_12 : L_13 ) ;
} else {
V_67 -> V_109 = 0 ;
F_15 ( L_14 , V_33 ) ;
}
}
return V_70 ;
}
static void F_29 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_80 ) ;
V_6 |= V_110 | V_111 ;
F_3 ( V_6 , V_4 + V_80 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_80 ) ;
V_6 &= ~ ( V_110 | V_111 ) ;
F_3 ( V_6 , V_4 + V_80 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_112 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_80 ) ;
if ( V_112 )
V_6 |= V_113 ;
else
V_6 &= ~ V_113 ;
F_3 ( V_6 , V_4 + V_80 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_114 , int V_115 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_115 & 0xffff ) ) | ( ( V_114 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_116 ) ;
}
static void F_33 ( struct V_1 * V_2 , bool V_117 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = V_118 | V_119 ;
if ( V_117 )
V_6 |= V_120 ;
F_3 ( V_6 , V_4 + V_121 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_124 ) ;
if ( V_6 & V_125 )
V_123 -> V_47 = V_126 ;
if ( V_6 & V_127 )
V_123 -> V_47 |= V_128 ;
V_123 -> V_129 = ( V_6 & V_130 ) >> V_131 ;
V_6 = F_2 ( V_4 + V_132 ) ;
if ( V_6 & V_125 )
V_123 -> V_133 = V_126 ;
if ( V_6 & V_127 )
V_123 -> V_133 = V_128 ;
V_123 -> V_134 = ( V_6 & V_130 ) >> V_131 ;
}
static void F_35 ( void T_1 * V_4 , struct V_66 * V_67 )
{
T_2 V_6 = F_2 ( V_4 + V_135 ) ;
if ( V_6 & V_136 )
V_67 -> V_137 ++ ;
if ( V_6 & V_138 )
V_67 -> V_139 ++ ;
if ( V_6 & V_140 )
V_67 -> V_141 ++ ;
if ( V_6 & V_142 ) {
T_2 V_143 = ( V_6 & V_142 )
>> V_144 ;
if ( V_143 == V_145 )
V_67 -> V_146 ++ ;
else if ( V_143 == V_147 )
V_67 -> V_148 ++ ;
else if ( V_143 == V_149 )
V_67 -> V_150 ++ ;
else
V_67 -> V_151 ++ ;
}
if ( V_6 & V_152 )
V_67 -> V_153 ++ ;
if ( V_6 & V_154 ) {
T_2 V_155 = ( V_6 & V_154 )
>> V_156 ;
if ( V_155 == V_157 )
V_67 -> V_158 ++ ;
else if ( V_155 == V_159 )
V_67 -> V_160 ++ ;
else if ( V_155 == V_161 )
V_67 -> V_162 ++ ;
else
V_67 -> V_163 ++ ;
}
if ( V_6 & V_164 )
V_67 -> V_165 ++ ;
if ( V_6 & V_166 ) {
T_2 V_167 = ( V_6 & V_166 )
>> V_168 ;
if ( V_167 == V_169 )
V_67 -> V_170 ++ ;
else if ( V_167 == V_171 )
V_67 -> V_172 ++ ;
else if ( V_167 == V_173 )
V_67 -> V_174 ++ ;
else
V_67 -> V_175 ++ ;
}
if ( V_6 & V_176 ) {
T_2 V_177 = ( V_6 & V_176 ) >>
V_168 ;
if ( V_177 == V_178 )
V_67 -> V_179 ++ ;
else if ( V_177 == V_180 )
V_67 -> V_181 ++ ;
else if ( V_177 == V_182 )
V_67 -> V_183 ++ ;
else
V_67 -> V_184 ++ ;
}
if ( V_6 & V_185 )
V_67 -> V_186 ++ ;
if ( V_6 & V_187 )
V_67 -> V_188 = ( V_6 & V_187 )
>> V_189 ;
if ( V_6 & V_190 )
V_67 -> V_191 ++ ;
}
struct V_1 * F_36 ( void T_1 * V_4 , int V_192 ,
int V_193 ,
int * V_194 )
{
struct V_1 * V_195 ;
T_2 V_196 = F_2 ( V_4 + V_197 ) ;
V_195 = F_37 ( sizeof( const struct V_1 ) , V_198 ) ;
if ( ! V_195 )
return NULL ;
V_195 -> V_5 = V_4 ;
V_195 -> V_199 = V_192 ;
V_195 -> V_30 = V_193 ;
V_195 -> V_32 = 0 ;
if ( V_195 -> V_199 )
V_195 -> V_32 = F_38 ( V_195 -> V_199 ) ;
V_195 -> V_195 = & V_200 ;
V_195 -> V_201 = & V_202 ;
V_195 -> V_112 . V_203 = V_204 ;
V_195 -> V_112 . V_47 = V_205 ;
V_195 -> V_112 . V_206 = V_207 ;
V_195 -> V_208 . V_17 = V_209 ;
V_195 -> V_208 . V_210 = V_211 ;
* V_194 = F_39 ( V_196 ) ;
return V_195 ;
}
