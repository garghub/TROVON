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
V_6 |= V_19 ;
if ( V_2 -> V_20 )
V_6 |= V_21 ;
F_3 ( V_6 , V_4 + V_22 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_23 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_24 ) ;
V_6 &= F_5 ( V_23 ) ;
V_6 |= F_6 ( V_23 ) ;
F_3 ( V_6 , V_4 + V_24 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_2 * V_25 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
V_25 [ V_26 ] = F_2 ( V_4 + V_26 * 4 ) ;
}
static int F_8 ( struct V_1 * V_2 )
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
static void F_9 ( struct V_1 * V_2 , unsigned long V_30 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_30 & V_31 ) {
F_10 ( L_1 ) ;
V_18 |= V_32 | V_33 ;
}
if ( V_30 & V_34 ) {
F_10 ( L_2 ) ;
V_18 |= V_32 | V_35 | V_36 ;
}
F_3 ( V_18 , V_4 + V_37 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char * V_38 , unsigned int V_39 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_12 ( V_4 , V_38 , F_13 ( V_39 ) ,
F_14 ( V_39 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned char * V_38 , unsigned int V_39 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_16 ( V_4 , V_38 , F_13 ( V_39 ) ,
F_14 ( V_39 ) ) ;
}
static void F_17 ( struct V_1 * V_2 ,
bool V_40 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_41 ) ;
V_6 |= V_42 | V_43 ;
if ( V_40 )
V_6 |= V_44 ;
F_3 ( V_6 , V_4 + V_41 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_41 ) ;
V_6 &= ~ ( V_42 | V_43 ) ;
F_3 ( V_6 , V_4 + V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_45 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_41 ) ;
if ( V_45 )
V_6 |= V_46 ;
else
V_6 &= ~ V_46 ;
F_3 ( V_6 , V_4 + V_41 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_47 , int V_48 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_48 & 0xffff ) ) | ( ( V_47 & 0x3ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
void T_1 * V_4 = ( void T_1 * ) V_51 -> V_52 ;
unsigned int V_6 = 0 ;
if ( V_51 -> V_53 & V_54 ) {
V_6 = V_55 ;
} else if ( ( V_51 -> V_53 & V_56 ) ||
( F_22 ( V_51 ) > V_57 ) ) {
V_6 = V_58 ;
F_3 ( 0xffffffff , V_4 + V_59 ) ;
F_3 ( 0xffffffff , V_4 + V_60 ) ;
} else if ( ! F_23 ( V_51 ) ) {
T_2 V_61 [ 2 ] ;
struct V_62 * V_63 ;
V_6 = V_64 ;
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
F_24 (ha, dev) {
int V_65 =
( F_25 ( ~ F_26 ( ~ 0 , V_63 -> V_38 , 6 ) ) >> 26 ) ;
V_61 [ V_65 >> 5 ] |= ( 1 << ( V_65 & 0x1F ) ) ;
}
F_3 ( V_61 [ 0 ] , V_4 + V_59 ) ;
F_3 ( V_61 [ 1 ] , V_4 + V_60 ) ;
}
if ( F_27 ( V_51 ) > V_66 ) {
V_6 |= V_55 ;
} else if ( ! F_28 ( V_51 ) ) {
int V_67 = 1 ;
struct V_62 * V_63 ;
F_29 (ha, dev) {
F_11 ( V_2 , V_63 -> V_38 , V_67 ) ;
V_67 ++ ;
}
}
F_3 ( V_6 , V_4 + V_68 ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_69 ,
unsigned int V_70 , unsigned int V_71 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_72 = V_73 ;
unsigned int V_74 = 0 ;
F_10 ( L_3 ) ;
if ( V_70 & V_75 ) {
F_10 ( L_4 ) ;
V_74 |= V_76 ;
F_3 ( V_74 , V_4 + V_77 ) ;
}
if ( V_70 & V_78 ) {
F_10 ( L_5 ) ;
V_74 |= V_79 ;
F_3 ( V_74 , V_4 + F_31 ( V_72 ) ) ;
if ( V_69 ) {
F_10 ( L_6 , V_71 ) ;
V_74 |= ( V_71 << V_80 ) ;
F_3 ( V_74 , V_4 + F_31 ( V_72 ) ) ;
}
}
}
static void F_32 ( void T_1 * V_4 , bool V_81 , bool V_82 ,
bool V_83 )
{
F_33 ( V_4 , V_84 , V_81 , V_82 , V_83 ) ;
}
static void F_34 ( void T_1 * V_4 , bool V_85 )
{
F_35 ( V_4 , V_84 , V_85 ) ;
}
static void F_36 ( void T_1 * V_4 , struct V_86 * V_87 )
{
F_37 ( V_4 , V_84 , V_87 ) ;
}
static void F_38 ( void T_1 * V_4 , struct V_88 * V_89 )
{
T_2 V_90 ;
V_90 = F_2 ( V_4 + V_91 ) ;
V_89 -> V_92 ++ ;
if ( V_90 & V_93 ) {
int V_94 ;
V_89 -> V_95 = 1 ;
V_94 = ( ( V_90 & V_96 ) >>
V_97 ) ;
if ( V_94 == V_98 )
V_89 -> V_99 = V_13 ;
else if ( V_94 == V_100 )
V_89 -> V_99 = V_101 ;
else
V_89 -> V_99 = V_15 ;
V_89 -> V_102 = ( V_90 & V_103 ) ;
F_39 ( L_7 , ( int ) V_89 -> V_99 ,
V_89 -> V_102 ? L_8 : L_9 ) ;
} else {
V_89 -> V_95 = 0 ;
F_39 ( L_10 ) ;
}
}
static int F_40 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_104 ;
T_2 V_105 ;
int V_106 = 0 ;
V_105 = F_2 ( V_4 + V_107 ) ;
if ( ( V_105 & V_108 ) )
V_89 -> V_109 ++ ;
if ( F_41 ( V_105 & V_110 ) )
V_89 -> V_111 ++ ;
if ( F_41 ( V_105 & V_112 ) )
V_89 -> V_113 ++ ;
if ( F_41 ( V_105 & V_114 ) ) {
F_2 ( V_4 + V_37 ) ;
V_89 -> V_115 ++ ;
}
V_104 = F_2 ( V_4 + V_116 ) ;
if ( V_104 & V_117 ) {
T_2 V_90 = F_2 ( V_4 + F_42 ( V_73 ) ) ;
if ( V_90 & V_118 ) {
F_3 ( V_90 | V_118 ,
V_4 + F_42 ( V_73 ) ) ;
V_106 = V_119 ;
}
}
F_43 ( V_4 , V_84 , V_105 , V_89 ) ;
if ( V_105 & V_120 )
F_38 ( V_4 , V_89 ) ;
return V_106 ;
}
static void F_44 ( void T_1 * V_4 , struct V_88 * V_89 )
{
T_2 V_6 ;
V_6 = F_2 ( V_4 + F_45 ( V_73 ) ) ;
if ( V_6 & V_121 )
V_89 -> V_122 ++ ;
if ( V_6 & V_123 )
V_89 -> V_124 ++ ;
if ( V_6 & V_125 )
V_89 -> V_126 ++ ;
if ( V_6 & V_127 ) {
T_2 V_128 = ( V_6 & V_127 )
>> V_129 ;
if ( V_128 == V_130 )
V_89 -> V_131 ++ ;
else if ( V_128 == V_132 )
V_89 -> V_133 ++ ;
else if ( V_128 == V_134 )
V_89 -> V_135 ++ ;
else
V_89 -> V_136 ++ ;
}
if ( V_6 & V_137 )
V_89 -> V_138 ++ ;
V_6 = F_2 ( V_4 + F_46 ( V_73 ) ) ;
if ( V_6 & V_139 ) {
T_2 V_140 = ( V_6 & V_139 )
>> V_141 ;
if ( V_140 == V_142 )
V_89 -> V_143 ++ ;
else if ( V_140 == V_144 )
V_89 -> V_145 ++ ;
else if ( V_140 == V_146 )
V_89 -> V_147 ++ ;
else
V_89 -> V_148 ++ ;
}
if ( V_6 & V_149 ) {
T_2 V_150 = ( V_6 & V_149 ) >>
V_141 ;
if ( V_150 == V_151 )
V_89 -> V_152 ++ ;
else if ( V_150 == V_153 )
V_89 -> V_154 ++ ;
else if ( V_150 == V_155 )
V_89 -> V_156 ++ ;
else
V_89 -> V_157 ++ ;
}
if ( V_6 & V_158 )
V_89 -> V_159 ++ ;
V_6 = F_2 ( V_4 + V_160 ) ;
if ( V_6 & V_161 ) {
T_2 V_162 = ( V_6 & V_161 )
>> V_163 ;
if ( V_162 == V_164 )
V_89 -> V_165 ++ ;
else if ( V_162 == V_166 )
V_89 -> V_167 ++ ;
else if ( V_162 == V_168 )
V_89 -> V_169 ++ ;
else
V_89 -> V_170 ++ ;
}
if ( V_6 & V_171 )
V_89 -> V_172 ++ ;
if ( V_6 & V_173 )
V_89 -> V_174 = ( V_6 & V_173 )
>> V_175 ;
if ( V_6 & V_176 )
V_89 -> V_177 ++ ;
}
struct V_1 * F_47 ( void T_1 * V_4 , int V_178 ,
int V_179 , int * V_180 )
{
struct V_1 * V_181 ;
T_2 V_182 = F_2 ( V_4 + V_183 ) ;
V_181 = F_48 ( sizeof( const struct V_1 ) , V_184 ) ;
if ( ! V_181 )
return NULL ;
V_181 -> V_5 = V_4 ;
V_181 -> V_185 = V_178 ;
V_181 -> V_186 = V_179 ;
V_181 -> V_187 = 0 ;
if ( V_181 -> V_185 )
V_181 -> V_187 = F_49 ( V_181 -> V_185 ) ;
V_181 -> V_181 = & V_188 ;
V_181 -> V_45 . V_189 = V_14 ;
V_181 -> V_45 . V_69 = V_190 ;
V_181 -> V_45 . V_191 = V_16 ;
V_181 -> V_192 . V_38 = V_193 ;
V_181 -> V_192 . V_194 = V_195 ;
V_181 -> V_192 . V_196 = 21 ;
V_181 -> V_192 . V_197 = F_50 ( 25 , 21 ) ;
V_181 -> V_192 . V_198 = 16 ;
V_181 -> V_192 . V_199 = F_50 ( 20 , 16 ) ;
V_181 -> V_192 . V_200 = 8 ;
V_181 -> V_192 . V_201 = F_50 ( 11 , 8 ) ;
* V_180 = F_51 ( V_182 ) ;
if ( * V_180 > V_202 )
V_181 -> V_203 = & V_204 ;
else
V_181 -> V_203 = & V_205 ;
return V_181 ;
}
