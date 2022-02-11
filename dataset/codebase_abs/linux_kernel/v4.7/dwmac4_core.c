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
F_3 ( V_11 , V_4 + V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_13 ;
F_5 ( L_1 , V_4 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
int V_15 = V_13 * 4 ;
F_5 ( L_2 , V_13 ,
V_15 , F_2 ( V_4 + V_15 ) ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_16 )
V_6 |= V_17 ;
else
V_6 &= ~ V_17 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_18 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_19 = 0 ;
if ( V_18 & V_20 ) {
F_5 ( L_3 ) ;
V_19 |= V_21 | V_22 ;
}
if ( V_18 & V_23 ) {
F_5 ( L_4 ) ;
V_19 |= V_24 ;
}
F_3 ( V_19 , V_4 + V_25 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_26 , unsigned int V_27 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_26 , F_10 ( V_27 ) ,
F_11 ( V_27 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned char * V_26 , unsigned int V_27 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_13 ( V_4 , V_26 , F_10 ( V_27 ) ,
F_11 ( V_27 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
void T_1 * V_4 = ( void T_1 * ) V_29 -> V_30 ;
unsigned int V_6 = 0 ;
if ( V_29 -> V_31 & V_32 ) {
V_6 = V_33 ;
} else if ( ( V_29 -> V_31 & V_34 ) ||
( F_15 ( V_29 ) > V_35 ) ) {
V_6 = V_36 ;
F_3 ( 0xffffffff , V_4 + V_37 ) ;
F_3 ( 0xffffffff , V_4 + V_38 ) ;
} else if ( ! F_16 ( V_29 ) ) {
T_2 V_39 [ 2 ] ;
struct V_40 * V_41 ;
V_6 = V_42 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
F_17 (ha, dev) {
int V_43 =
( F_18 ( ~ F_19 ( ~ 0 , V_41 -> V_26 , 6 ) ) >> 26 ) ;
V_39 [ V_43 >> 5 ] |= ( 1 << ( V_43 & 0x1F ) ) ;
}
F_3 ( V_39 [ 0 ] , V_4 + V_37 ) ;
F_3 ( V_39 [ 1 ] , V_4 + V_38 ) ;
}
if ( F_20 ( V_29 ) > V_44 ) {
V_6 |= V_33 ;
} else if ( ! F_21 ( V_29 ) ) {
int V_45 = 1 ;
struct V_40 * V_41 ;
F_22 (ha, dev) {
F_8 ( V_2 , V_41 -> V_26 , V_45 ) ;
V_45 ++ ;
}
}
F_3 ( V_6 , V_4 + V_46 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_47 ,
unsigned int V_48 , unsigned int V_49 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_50 = V_51 ;
unsigned int V_52 = 0 ;
F_5 ( L_5 ) ;
if ( V_48 & V_53 ) {
F_5 ( L_6 ) ;
V_52 |= V_54 ;
F_3 ( V_52 , V_4 + V_55 ) ;
}
if ( V_48 & V_56 ) {
F_5 ( L_7 ) ;
V_52 |= V_57 ;
F_3 ( V_52 , V_4 + F_24 ( V_50 ) ) ;
if ( V_47 ) {
F_5 ( L_8 , V_49 ) ;
V_52 |= ( V_49 << V_58 ) ;
F_3 ( V_52 , V_4 + F_24 ( V_50 ) ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 , bool V_59 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = V_60 | V_61 ;
if ( V_59 )
V_6 |= V_62 ;
F_3 ( V_6 , V_4 + V_63 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_66 ) ;
if ( V_6 & V_67 )
V_65 -> V_47 = V_68 ;
if ( V_6 & V_69 )
V_65 -> V_47 |= V_70 ;
V_65 -> V_71 = ( V_6 & V_72 ) >> V_73 ;
V_6 = F_2 ( V_4 + V_74 ) ;
if ( V_6 & V_67 )
V_65 -> V_75 = V_68 ;
if ( V_6 & V_69 )
V_65 -> V_75 = V_70 ;
V_65 -> V_76 = ( V_6 & V_72 ) >> V_73 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_79 ;
T_2 V_80 ;
int V_81 = 0 ;
V_80 = F_2 ( V_4 + V_82 ) ;
if ( ( V_80 & V_83 ) )
V_78 -> V_84 ++ ;
if ( F_28 ( V_80 & V_85 ) )
V_78 -> V_86 ++ ;
if ( F_28 ( V_80 & V_87 ) )
V_78 -> V_88 ++ ;
if ( F_28 ( V_80 & V_89 ) ) {
F_2 ( V_4 + V_25 ) ;
V_78 -> V_90 ++ ;
}
if ( ( V_80 & V_91 ) || ( V_80 & V_92 ) ) {
F_2 ( V_4 + V_93 ) ;
V_78 -> V_94 ++ ;
}
V_79 = F_2 ( V_4 + V_95 ) ;
if ( V_79 & V_96 ) {
T_2 V_97 = F_2 ( V_4 + F_29 ( V_51 ) ) ;
if ( V_97 & V_98 ) {
F_3 ( V_97 | V_98 ,
V_4 + F_29 ( V_51 ) ) ;
V_81 = V_99 ;
}
}
return V_81 ;
}
static void F_30 ( void T_1 * V_4 , struct V_77 * V_78 )
{
T_2 V_6 ;
V_6 = F_2 ( V_4 + F_31 ( V_51 ) ) ;
if ( V_6 & V_100 )
V_78 -> V_101 ++ ;
if ( V_6 & V_102 )
V_78 -> V_103 ++ ;
if ( V_6 & V_104 )
V_78 -> V_105 ++ ;
if ( V_6 & V_106 ) {
T_2 V_107 = ( V_6 & V_106 )
>> V_108 ;
if ( V_107 == V_109 )
V_78 -> V_110 ++ ;
else if ( V_107 == V_111 )
V_78 -> V_112 ++ ;
else if ( V_107 == V_113 )
V_78 -> V_114 ++ ;
else
V_78 -> V_115 ++ ;
}
if ( V_6 & V_116 )
V_78 -> V_117 ++ ;
V_6 = F_2 ( V_4 + F_32 ( V_51 ) ) ;
if ( V_6 & V_118 ) {
T_2 V_119 = ( V_6 & V_118 )
>> V_120 ;
if ( V_119 == V_121 )
V_78 -> V_122 ++ ;
else if ( V_119 == V_123 )
V_78 -> V_124 ++ ;
else if ( V_119 == V_125 )
V_78 -> V_126 ++ ;
else
V_78 -> V_127 ++ ;
}
if ( V_6 & V_128 ) {
T_2 V_129 = ( V_6 & V_128 ) >>
V_120 ;
if ( V_129 == V_130 )
V_78 -> V_131 ++ ;
else if ( V_129 == V_132 )
V_78 -> V_133 ++ ;
else if ( V_129 == V_134 )
V_78 -> V_135 ++ ;
else
V_78 -> V_136 ++ ;
}
if ( V_6 & V_137 )
V_78 -> V_138 ++ ;
V_6 = F_2 ( V_4 + V_139 ) ;
if ( V_6 & V_140 ) {
T_2 V_141 = ( V_6 & V_140 )
>> V_142 ;
if ( V_141 == V_143 )
V_78 -> V_144 ++ ;
else if ( V_141 == V_145 )
V_78 -> V_146 ++ ;
else if ( V_141 == V_147 )
V_78 -> V_148 ++ ;
else
V_78 -> V_149 ++ ;
}
if ( V_6 & V_150 )
V_78 -> V_151 ++ ;
if ( V_6 & V_152 )
V_78 -> V_153 = ( V_6 & V_152 )
>> V_154 ;
if ( V_6 & V_155 )
V_78 -> V_156 ++ ;
}
struct V_1 * F_33 ( void T_1 * V_4 , int V_157 ,
int V_158 , int * V_159 )
{
struct V_1 * V_160 ;
T_2 V_161 = F_2 ( V_4 + V_162 ) ;
V_160 = F_34 ( sizeof( const struct V_1 ) , V_163 ) ;
if ( ! V_160 )
return NULL ;
V_160 -> V_5 = V_4 ;
V_160 -> V_164 = V_157 ;
V_160 -> V_165 = V_158 ;
V_160 -> V_166 = 0 ;
if ( V_160 -> V_164 )
V_160 -> V_166 = F_35 ( V_160 -> V_164 ) ;
V_160 -> V_160 = & V_167 ;
V_160 -> V_168 . V_169 = V_170 ;
V_160 -> V_168 . V_47 = V_171 ;
V_160 -> V_168 . V_172 = V_173 ;
V_160 -> V_174 . V_26 = V_175 ;
V_160 -> V_174 . V_176 = V_177 ;
* V_159 = F_36 ( V_161 ) ;
if ( * V_159 > V_178 )
V_160 -> V_179 = & V_180 ;
else
V_160 -> V_179 = & V_181 ;
return V_160 ;
}
