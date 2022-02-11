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
static void F_4 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_23 ;
F_5 ( L_1 , V_4 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
int V_25 = V_23 * 4 ;
F_5 ( L_2 , V_23 ,
V_25 , F_2 ( V_4 + V_25 ) ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_26 )
V_6 |= V_27 ;
else
V_6 &= ~ V_27 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_27 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_28 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_18 = 0 ;
if ( V_28 & V_29 ) {
F_5 ( L_3 ) ;
V_18 |= V_30 | V_31 ;
}
if ( V_28 & V_32 ) {
F_5 ( L_4 ) ;
V_18 |= V_30 | V_33 | V_34 ;
}
F_3 ( V_18 , V_4 + V_35 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_36 , unsigned int V_37 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_36 , F_10 ( V_37 ) ,
F_11 ( V_37 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned char * V_36 , unsigned int V_37 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_13 ( V_4 , V_36 , F_10 ( V_37 ) ,
F_11 ( V_37 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
void T_1 * V_4 = ( void T_1 * ) V_39 -> V_40 ;
unsigned int V_6 = 0 ;
if ( V_39 -> V_41 & V_42 ) {
V_6 = V_43 ;
} else if ( ( V_39 -> V_41 & V_44 ) ||
( F_15 ( V_39 ) > V_45 ) ) {
V_6 = V_46 ;
F_3 ( 0xffffffff , V_4 + V_47 ) ;
F_3 ( 0xffffffff , V_4 + V_48 ) ;
} else if ( ! F_16 ( V_39 ) ) {
T_2 V_49 [ 2 ] ;
struct V_50 * V_51 ;
V_6 = V_52 ;
memset ( V_49 , 0 , sizeof( V_49 ) ) ;
F_17 (ha, dev) {
int V_53 =
( F_18 ( ~ F_19 ( ~ 0 , V_51 -> V_36 , 6 ) ) >> 26 ) ;
V_49 [ V_53 >> 5 ] |= ( 1 << ( V_53 & 0x1F ) ) ;
}
F_3 ( V_49 [ 0 ] , V_4 + V_47 ) ;
F_3 ( V_49 [ 1 ] , V_4 + V_48 ) ;
}
if ( F_20 ( V_39 ) > V_54 ) {
V_6 |= V_43 ;
} else if ( ! F_21 ( V_39 ) ) {
int V_55 = 1 ;
struct V_50 * V_51 ;
F_22 (ha, dev) {
F_8 ( V_2 , V_51 -> V_36 , V_55 ) ;
V_55 ++ ;
}
}
F_3 ( V_6 , V_4 + V_56 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_57 ,
unsigned int V_58 , unsigned int V_59 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_60 = V_61 ;
unsigned int V_62 = 0 ;
F_5 ( L_5 ) ;
if ( V_58 & V_63 ) {
F_5 ( L_6 ) ;
V_62 |= V_64 ;
F_3 ( V_62 , V_4 + V_65 ) ;
}
if ( V_58 & V_66 ) {
F_5 ( L_7 ) ;
V_62 |= V_67 ;
F_3 ( V_62 , V_4 + F_24 ( V_60 ) ) ;
if ( V_57 ) {
F_5 ( L_8 , V_59 ) ;
V_62 |= ( V_59 << V_68 ) ;
F_3 ( V_62 , V_4 + F_24 ( V_60 ) ) ;
}
}
}
static void F_25 ( void T_1 * V_4 , bool V_69 , bool V_70 ,
bool V_71 )
{
F_26 ( V_4 , V_72 , V_69 , V_70 , V_71 ) ;
}
static void F_27 ( void T_1 * V_4 , bool V_73 )
{
F_28 ( V_4 , V_72 , V_73 ) ;
}
static void F_29 ( void T_1 * V_4 , struct V_74 * V_75 )
{
F_30 ( V_4 , V_72 , V_75 ) ;
}
static void F_31 ( void T_1 * V_4 , struct V_76 * V_77 )
{
T_2 V_78 ;
V_78 = F_2 ( V_4 + V_79 ) ;
V_77 -> V_80 ++ ;
if ( V_78 & V_81 ) {
int V_82 ;
V_77 -> V_83 = 1 ;
V_82 = ( ( V_78 & V_84 ) >>
V_85 ) ;
if ( V_82 == V_86 )
V_77 -> V_87 = V_13 ;
else if ( V_82 == V_88 )
V_77 -> V_87 = V_89 ;
else
V_77 -> V_87 = V_15 ;
V_77 -> V_90 = ( V_78 & V_91 ) ;
F_32 ( L_9 , ( int ) V_77 -> V_87 ,
V_77 -> V_90 ? L_10 : L_11 ) ;
} else {
V_77 -> V_83 = 0 ;
F_32 ( L_12 ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_92 ;
T_2 V_93 ;
int V_94 = 0 ;
V_93 = F_2 ( V_4 + V_95 ) ;
if ( ( V_93 & V_96 ) )
V_77 -> V_97 ++ ;
if ( F_34 ( V_93 & V_98 ) )
V_77 -> V_99 ++ ;
if ( F_34 ( V_93 & V_100 ) )
V_77 -> V_101 ++ ;
if ( F_34 ( V_93 & V_102 ) ) {
F_2 ( V_4 + V_35 ) ;
V_77 -> V_103 ++ ;
}
V_92 = F_2 ( V_4 + V_104 ) ;
if ( V_92 & V_105 ) {
T_2 V_78 = F_2 ( V_4 + F_35 ( V_61 ) ) ;
if ( V_78 & V_106 ) {
F_3 ( V_78 | V_106 ,
V_4 + F_35 ( V_61 ) ) ;
V_94 = V_107 ;
}
}
F_36 ( V_4 , V_72 , V_93 , V_77 ) ;
if ( V_93 & V_108 )
F_31 ( V_4 , V_77 ) ;
return V_94 ;
}
static void F_37 ( void T_1 * V_4 , struct V_76 * V_77 )
{
T_2 V_6 ;
V_6 = F_2 ( V_4 + F_38 ( V_61 ) ) ;
if ( V_6 & V_109 )
V_77 -> V_110 ++ ;
if ( V_6 & V_111 )
V_77 -> V_112 ++ ;
if ( V_6 & V_113 )
V_77 -> V_114 ++ ;
if ( V_6 & V_115 ) {
T_2 V_116 = ( V_6 & V_115 )
>> V_117 ;
if ( V_116 == V_118 )
V_77 -> V_119 ++ ;
else if ( V_116 == V_120 )
V_77 -> V_121 ++ ;
else if ( V_116 == V_122 )
V_77 -> V_123 ++ ;
else
V_77 -> V_124 ++ ;
}
if ( V_6 & V_125 )
V_77 -> V_126 ++ ;
V_6 = F_2 ( V_4 + F_39 ( V_61 ) ) ;
if ( V_6 & V_127 ) {
T_2 V_128 = ( V_6 & V_127 )
>> V_129 ;
if ( V_128 == V_130 )
V_77 -> V_131 ++ ;
else if ( V_128 == V_132 )
V_77 -> V_133 ++ ;
else if ( V_128 == V_134 )
V_77 -> V_135 ++ ;
else
V_77 -> V_136 ++ ;
}
if ( V_6 & V_137 ) {
T_2 V_138 = ( V_6 & V_137 ) >>
V_129 ;
if ( V_138 == V_139 )
V_77 -> V_140 ++ ;
else if ( V_138 == V_141 )
V_77 -> V_142 ++ ;
else if ( V_138 == V_143 )
V_77 -> V_144 ++ ;
else
V_77 -> V_145 ++ ;
}
if ( V_6 & V_146 )
V_77 -> V_147 ++ ;
V_6 = F_2 ( V_4 + V_148 ) ;
if ( V_6 & V_149 ) {
T_2 V_150 = ( V_6 & V_149 )
>> V_151 ;
if ( V_150 == V_152 )
V_77 -> V_153 ++ ;
else if ( V_150 == V_154 )
V_77 -> V_155 ++ ;
else if ( V_150 == V_156 )
V_77 -> V_157 ++ ;
else
V_77 -> V_158 ++ ;
}
if ( V_6 & V_159 )
V_77 -> V_160 ++ ;
if ( V_6 & V_161 )
V_77 -> V_162 = ( V_6 & V_161 )
>> V_163 ;
if ( V_6 & V_164 )
V_77 -> V_165 ++ ;
}
struct V_1 * F_40 ( void T_1 * V_4 , int V_166 ,
int V_167 , int * V_168 )
{
struct V_1 * V_169 ;
T_2 V_170 = F_2 ( V_4 + V_171 ) ;
V_169 = F_41 ( sizeof( const struct V_1 ) , V_172 ) ;
if ( ! V_169 )
return NULL ;
V_169 -> V_5 = V_4 ;
V_169 -> V_173 = V_166 ;
V_169 -> V_174 = V_167 ;
V_169 -> V_175 = 0 ;
if ( V_169 -> V_173 )
V_169 -> V_175 = F_42 ( V_169 -> V_173 ) ;
V_169 -> V_169 = & V_176 ;
V_169 -> V_177 . V_178 = V_14 ;
V_169 -> V_177 . V_57 = V_179 ;
V_169 -> V_177 . V_180 = V_16 ;
V_169 -> V_181 . V_36 = V_182 ;
V_169 -> V_181 . V_183 = V_184 ;
* V_168 = F_43 ( V_170 ) ;
if ( * V_168 > V_185 )
V_169 -> V_186 = & V_187 ;
else
V_169 -> V_186 = & V_188 ;
return V_169 ;
}
