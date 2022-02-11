static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
if ( V_2 -> V_6 && V_3 ) {
switch ( ( V_3 & 0x7 ) | ( V_4 << 4 ) ) {
case 0x5 :
V_7 -> V_8 |= V_9 ;
break;
case 0x6 :
V_7 -> V_8 |= V_10 ;
break;
case 0x7 :
V_7 -> V_8 |= V_11 ;
break;
case 0x65 :
V_7 -> V_8 |= V_12 ;
break;
case 0x76 :
V_7 -> V_8 |= V_13 ;
break;
case 0x57 :
V_7 -> V_8 |= V_14 ;
break;
default:
F_2 ( V_2 -> V_15 , L_1
L_2
L_3 ) ;
return - V_16 ;
break;
}
if ( F_3 ( V_3 , V_2 -> V_17 -> V_18 ) ) {
F_2 ( V_2 -> V_15 , L_4 ,
V_3 ) ;
return - V_16 ;
}
V_7 -> V_3 = V_3 ;
V_7 -> V_19 = V_3 ;
if ( V_4 ) {
if ( F_3 ( V_4 , V_2 -> V_17 -> V_18 ) ) {
F_2 ( V_2 -> V_15 , L_4 ,
V_4 ) ;
return - V_16 ;
}
V_7 -> V_4 = V_4 ;
}
V_7 -> V_20 = F_4 ( V_21 , V_22 | V_23 ) ;
if ( V_7 -> V_20 == NULL )
return - V_24 ;
V_7 -> V_25 = V_7 -> V_20 ;
if ( V_4 ) {
V_7 -> V_26 =
F_4 ( V_21 , V_22 | V_23 ) ;
if ( V_7 -> V_26 == NULL )
return - V_24 ;
}
V_5 = F_5 () ;
F_6 ( V_7 -> V_3 ) ;
F_7 ( V_7 -> V_3 , V_27 ) ;
if ( V_4 ) {
F_6 ( V_7 -> V_4 ) ;
F_7 ( V_7 -> V_4 , V_27 ) ;
}
F_8 ( V_5 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 ;
unsigned long V_32 = V_29 -> V_33 [ 0 ] ;
unsigned int V_6 = V_29 -> V_33 [ 1 ] ;
unsigned int V_3 = V_29 -> V_33 [ 2 ] ;
unsigned int V_4 = V_29 -> V_33 [ 3 ] ;
unsigned long V_34 ;
int V_35 ;
int V_36 ;
if ( F_10 ( V_2 , sizeof( struct V_37 ) ) < 0 )
return - V_24 ;
F_11 ( V_38 L_5 , V_2 -> V_39 ,
V_2 -> V_17 -> V_18 , V_32 ) ;
if ( V_6 ) {
F_11 ( V_40 L_6 , V_6 ) ;
if ( V_3 ) {
F_11 ( V_40 L_7 , V_3 ) ;
if ( V_4 )
F_11 ( V_40 L_8 , V_4 ) ;
}
}
F_11 ( V_40 L_9 ) ;
if ( V_32 == 0 ) {
F_2 ( V_2 -> V_15 , L_10 ) ;
return - V_16 ;
}
if ( ! F_12 ( V_32 , V_41 , V_2 -> V_17 -> V_18 ) ) {
F_11
( L_11 ,
V_32 , V_32 + V_41 - 1 ) ;
return - V_42 ;
}
V_2 -> V_32 = V_32 ;
V_35 = F_13 ( V_2 ) ;
if ( V_35 < 0 ) {
F_2 ( V_2 -> V_15 , L_12 ) ;
return - V_43 ;
}
V_2 -> V_44 = V_45 + V_35 ;
V_2 -> V_46 = V_47 -> V_48 ;
if ( V_47 -> V_49 == 2 ) {
V_34 = V_32 + V_50 ;
if ( ! F_12 ( V_34 , V_41 ,
V_2 -> V_17 -> V_18 ) ) {
F_11
( L_11 ,
V_34 , V_34 + V_41 - 1 ) ;
return - V_42 ;
}
V_7 -> V_34 = V_34 ;
}
if ( V_6 ) {
if ( F_14 ( V_6 , V_51 , 0 ,
V_2 -> V_17 -> V_18 , V_2 ) ) {
F_15 ( V_2 -> V_15 , L_13 ,
V_6 ) ;
return - V_16 ;
}
}
V_2 -> V_6 = V_6 ;
switch ( V_6 ) {
case 0 :
break;
case 3 :
V_7 -> V_52 |= 0x8 ;
break;
case 5 :
V_7 -> V_52 |= 0x10 ;
break;
case 7 :
V_7 -> V_52 |= 0x18 ;
break;
case 10 :
V_7 -> V_52 |= 0x28 ;
break;
case 11 :
V_7 -> V_52 |= 0x30 ;
break;
case 15 :
V_7 -> V_52 |= 0x38 ;
break;
default:
F_2 ( V_2 -> V_15 , L_14 ) ;
return - V_16 ;
break;
}
V_36 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_7 -> V_20 == NULL ) {
V_7 -> V_20 =
F_4 ( V_53 * sizeof( V_54 ) , V_22 ) ;
if ( V_7 -> V_20 == NULL )
return - V_24 ;
}
if ( F_16 ( V_2 , 4 ) < 0 )
return - V_24 ;
V_31 = V_2 -> V_55 + 0 ;
V_2 -> V_56 = V_31 ;
V_31 -> type = V_57 ;
V_31 -> V_58 = V_59 | V_60 | V_61 | V_62 ;
if ( V_47 -> V_63 )
V_31 -> V_58 |= V_64 ;
V_31 -> V_65 = V_47 -> V_66 ;
V_31 -> V_67 = V_47 -> V_66 ;
V_31 -> V_68 = ( 1 << V_47 -> V_69 ) - 1 ;
V_31 -> V_70 = V_47 -> V_71 ;
V_31 -> V_72 = V_73 ;
V_31 -> V_74 = V_75 ;
V_31 -> V_76 = V_77 ;
V_31 -> V_78 = V_79 ;
V_31 -> V_80 = V_81 ;
V_31 = V_2 -> V_55 + 1 ;
if ( V_47 -> V_49 == 1 ) {
V_31 -> type = V_82 ;
V_31 -> V_58 = V_83 ;
V_31 -> V_65 = V_47 -> V_84 ;
V_31 -> V_68 = ( 1 << V_47 -> V_69 ) - 1 ;
V_31 -> V_70 = & V_85 ;
V_31 -> V_86 = V_87 ;
} else {
V_31 -> type = V_88 ;
}
V_31 = V_2 -> V_55 + 2 ;
V_31 -> type = V_89 ;
V_31 -> V_58 = V_59 ;
V_31 -> V_65 = 4 ;
V_31 -> V_68 = 1 ;
V_31 -> V_70 = & V_90 ;
V_31 -> V_91 = V_92 ;
V_31 = V_2 -> V_55 + 3 ;
V_31 -> type = V_93 ;
V_31 -> V_58 = V_83 | V_59 ;
V_31 -> V_65 = V_47 -> V_94 ;
V_31 -> V_68 = 1 ;
V_31 -> V_70 = & V_90 ;
V_31 -> V_91 = V_95 ;
V_81 ( V_2 , V_2 -> V_56 ) ;
F_17 ( V_7 -> V_96 , V_2 -> V_32 + V_97 ) ;
if ( V_47 -> V_49 == 1 ) {
F_17 ( F_18 ( V_47 -> V_84 - 1 ) ,
V_2 -> V_32 + V_98 ) ;
F_19 ( V_7 -> V_99 , V_2 -> V_32 + V_100 ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 )
F_21 ( V_2 -> V_32 , V_41 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 -> V_6 , V_2 ) ;
if ( V_2 -> V_101 ) {
if ( V_7 -> V_34 )
F_21 ( V_7 -> V_34 , V_41 ) ;
if ( V_7 -> V_3 )
F_23 ( V_7 -> V_3 ) ;
if ( V_7 -> V_4 )
F_23 ( V_7 -> V_4 ) ;
F_24 ( V_7 -> V_20 ) ;
F_24 ( V_7 -> V_26 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
int V_102 ;
int V_35 ;
V_102 = ( F_25 ( V_2 -> V_32 + V_97 ) >> 4 ) & 0xf ;
V_35 = ( (struct V_103 * ) V_2 -> V_44 ) - V_45 ;
switch ( V_102 ) {
case 0x3 :
if ( V_35 == V_104 || V_35 == V_105 ||
V_35 == V_106 || V_35 == V_107 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_16 ) ;
return V_108 ;
break;
case 0x4 :
if ( V_35 == V_109 || V_35 == V_110 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_17 ) ;
return V_111 ;
break;
case 0x5 :
if ( V_35 == V_112 || V_35 == V_113 ||
V_35 == V_114 || V_35 == V_115 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_18 ) ;
return V_112 ;
break;
case 0x6 :
if ( V_35 == V_111 || V_35 == V_116 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_19 ) ;
return V_111 ;
break;
case 0x7 :
if ( V_35 == V_108 || V_35 == V_117 ||
V_35 == V_118 || V_35 == V_119 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_20 ) ;
return V_108 ;
break;
case 0x8 :
if ( V_35 == V_120 || V_35 == V_121 ) {
F_15 ( V_2 -> V_15 , L_15 ,
V_45 [ V_35 ] . V_48 ) ;
return V_35 ;
}
F_11
( L_21 ) ;
return V_120 ;
break;
default:
F_11
( L_22 ,
V_102 ) ;
return V_35 ;
break;
}
return - 1 ;
}
static int V_79 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
unsigned long V_5 ;
F_26 ( & V_2 -> V_122 , V_5 ) ;
F_27 ( V_2 ) ;
F_28 ( & V_2 -> V_122 , V_5 ) ;
return V_31 -> V_123 -> V_124 - V_31 -> V_123 -> V_125 ;
}
static T_1 V_51 ( int V_6 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
unsigned int V_127 ;
if ( V_2 -> V_128 == 0 ) {
F_29 ( V_2 , L_23 ) ;
return V_129 ;
}
F_30 ( & V_2 -> V_122 ) ;
V_127 = F_25 ( V_2 -> V_32 + V_130 ) ;
if ( ! ( V_127 & INT ) ) {
F_31 ( & V_2 -> V_122 ) ;
return V_131 ;
}
F_17 ( V_132 & ~ INT , V_2 -> V_32 + V_130 ) ;
F_27 ( V_2 ) ;
F_31 ( & V_2 -> V_122 ) ;
return V_129 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_55 + 0 ;
struct V_133 * V_123 = V_31 -> V_123 ;
struct V_134 * V_135 = & V_123 -> V_135 ;
unsigned int V_127 = F_25 ( V_2 -> V_32 + V_130 ) ;
V_123 -> V_136 = 0 ;
F_17 ( V_137 , V_2 -> V_32 + V_98 ) ;
if ( V_7 -> V_52 & V_138 ) {
F_32 ( V_2 , V_31 , V_127 ) ;
} else if ( V_127 & V_139 ) {
F_33 ( V_2 , V_31 ) ;
} else if ( V_127 & V_140 ) {
F_34 ( V_2 , V_31 ) ;
}
V_123 -> V_136 |= V_141 ;
if ( V_127 & V_142 ) {
F_17 ( V_132 & ~ V_142 , V_2 -> V_32 + V_130 ) ;
F_29 ( V_2 , L_24 ) ;
V_81 ( V_2 , V_31 ) ;
V_123 -> V_136 |= V_143 | V_144 ;
F_35 ( V_2 , V_31 ) ;
return;
}
if ( V_127 & V_145 ) {
F_17 ( V_132 & ~ V_145 , V_2 -> V_32 + V_130 ) ;
if ( V_7 -> V_52 & V_138 )
F_36 ( V_2 , V_31 ) ;
else
F_34 ( V_2 , V_31 ) ;
V_81 ( V_2 , V_31 ) ;
V_123 -> V_136 |= V_144 ;
} else if ( V_135 -> V_146 == V_147 && V_7 -> V_148 == 0 ) {
V_81 ( V_2 , V_31 ) ;
V_123 -> V_136 |= V_144 ;
}
F_35 ( V_2 , V_31 ) ;
return;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_30 * V_31 , unsigned int V_127 )
{
unsigned long V_5 ;
const int V_149 = V_7 -> V_52 & V_150 ;
V_5 = F_5 () ;
F_37 ( V_2 , V_31 , V_7 -> V_19 ,
V_7 -> V_25 ) ;
F_38 ( V_7 -> V_19 ,
F_39 ( V_7 -> V_25 ) ) ;
F_40 ( V_7 -> V_19 , V_7 -> V_151 ) ;
F_41 ( V_7 -> V_19 ) ;
F_8 ( V_5 ) ;
if ( V_127 & V_152 ) {
F_17 ( V_132 & ~ V_152 , V_2 -> V_32 + V_130 ) ;
if ( V_149 ) {
if ( V_7 -> V_19 == V_7 -> V_3 ) {
V_7 -> V_19 = V_7 -> V_4 ;
V_7 -> V_25 = V_7 -> V_26 ;
} else {
V_7 -> V_19 = V_7 -> V_3 ;
V_7 -> V_25 = V_7 -> V_20 ;
}
}
}
return;
}
static inline V_54 F_42 ( const struct V_1 * V_2 ,
V_54 V_153 )
{
V_153 += 1 << ( V_47 -> V_69 - 1 ) ;
return V_153 ;
}
static void F_43 ( struct V_1 * V_2 , V_54 * V_154 ,
unsigned int V_155 )
{
unsigned int V_156 ;
int V_157 ;
V_157 = F_25 ( V_2 -> V_32 + V_158 ) & V_159 ;
if ( ! V_157 ) {
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ )
V_154 [ V_156 ] = F_42 ( V_2 , V_154 [ V_156 ] ) ;
}
}
static void F_37 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
unsigned int V_160 , V_54 * V_161 )
{
unsigned int V_162 , V_163 ;
struct V_134 * V_135 = & V_31 -> V_123 -> V_135 ;
F_6 ( V_160 ) ;
F_44 ( V_160 ) ;
V_162 = V_7 -> V_151 - F_45 ( V_160 ) ;
V_163 = V_162 / sizeof( short ) ;
if ( V_135 -> V_146 == V_147 && V_7 -> V_148 < V_163 )
V_163 = V_7 -> V_148 ;
F_43 ( V_2 , V_161 , V_163 ) ;
F_46 ( V_31 , V_161 , V_162 ) ;
if ( V_31 -> V_123 -> V_135 . V_146 == V_147 )
V_7 -> V_148 -= V_163 ;
return;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
unsigned long V_5 ;
const int V_149 = V_7 -> V_52 & V_150 ;
V_5 = F_5 () ;
F_37 ( V_2 , V_31 , V_7 -> V_19 ,
V_7 -> V_25 ) ;
if ( V_149 ) {
if ( V_7 -> V_19 == V_7 -> V_3 ) {
V_7 -> V_19 = V_7 -> V_4 ;
V_7 -> V_25 = V_7 -> V_26 ;
} else {
V_7 -> V_19 = V_7 -> V_3 ;
V_7 -> V_25 = V_7 -> V_20 ;
}
F_37 ( V_2 , V_31 , V_7 -> V_19 ,
V_7 -> V_25 ) ;
}
F_8 ( V_5 ) ;
F_34 ( V_2 , V_31 ) ;
return;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_164 = 0 ;
struct V_134 * V_135 = & V_31 -> V_123 -> V_135 ;
V_164 = V_53 / 2 ;
if ( V_135 -> V_146 == V_147 && V_7 -> V_148 < V_164 )
V_164 = V_7 -> V_148 ;
F_47 ( V_2 -> V_32 + V_165 , V_7 -> V_20 , V_164 ) ;
F_43 ( V_2 , V_7 -> V_20 , V_164 ) ;
F_46 ( V_31 , V_7 -> V_20 ,
V_164 * sizeof( V_7 -> V_20 [ 0 ] ) ) ;
if ( V_135 -> V_146 == V_147 )
V_7 -> V_148 -= V_164 ;
return;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
short V_166 ;
int V_157 ;
struct V_134 * V_135 = & V_31 -> V_123 -> V_135 ;
V_157 = F_25 ( V_2 -> V_32 + V_158 ) & V_159 ;
while ( F_25 ( V_2 -> V_32 + V_130 ) & V_140 ) {
if ( V_135 -> V_146 == V_147 && V_7 -> V_148 == 0 )
break;
V_166 = F_48 ( V_2 -> V_32 + V_165 ) ;
if ( ! V_157 )
;
V_166 = F_42 ( V_2 , V_166 ) ;
F_49 ( V_31 , V_166 ) ;
if ( V_135 -> V_146 == V_147 )
V_7 -> V_148 -- ;
}
return;
}
static int V_81 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
F_17 ( 0x0 , V_2 -> V_32 + V_130 ) ;
F_17 ( 0x0 , V_2 -> V_32 + V_167 ) ;
F_17 ( 0x0 , V_2 -> V_32 + V_168 ) ;
if ( V_7 -> V_3 )
F_6 ( V_7 -> V_3 ) ;
if ( V_7 -> V_4 )
F_6 ( V_7 -> V_4 ) ;
return 0 ;
}
static int V_75 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_134 * V_135 )
{
int V_169 = 0 ;
int V_170 ;
unsigned int V_171 ;
int V_156 ;
int V_157 ;
V_170 = V_135 -> V_172 ;
V_135 -> V_172 &= V_173 | V_174 ;
if ( ! V_135 -> V_172 || V_170 != V_135 -> V_172 )
V_169 ++ ;
V_170 = V_135 -> V_175 ;
V_135 -> V_175 &= V_176 | V_177 | V_174 ;
if ( ! V_135 -> V_175 || V_170 != V_135 -> V_175 )
V_169 ++ ;
V_170 = V_135 -> V_178 ;
V_135 -> V_178 &= V_177 | V_174 ;
if ( ! V_135 -> V_178 || V_170 != V_135 -> V_178 )
V_169 ++ ;
V_170 = V_135 -> V_179 ;
V_135 -> V_179 &= V_147 ;
if ( ! V_135 -> V_179 || V_170 != V_135 -> V_179 )
V_169 ++ ;
V_170 = V_135 -> V_146 ;
V_135 -> V_146 &= V_147 | V_174 | V_180 ;
if ( ! V_135 -> V_146 || V_170 != V_135 -> V_146 )
V_169 ++ ;
if ( V_169 )
return 1 ;
if ( V_135 -> V_172 != V_173 && V_135 -> V_172 != V_174 )
V_169 ++ ;
if ( V_135 -> V_175 != V_176 &&
V_135 -> V_175 != V_177 &&
V_135 -> V_175 != V_174 )
V_169 ++ ;
if ( V_135 -> V_178 != V_177 && V_135 -> V_178 != V_174 )
V_169 ++ ;
if ( V_135 -> V_146 != V_147 &&
V_135 -> V_146 != V_180 && V_135 -> V_146 != V_174 )
V_169 ++ ;
if ( V_135 -> V_175 != V_176 &&
V_135 -> V_178 != V_177 )
V_169 ++ ;
if ( V_169 )
return 2 ;
if ( V_135 -> V_181 != 0 ) {
V_135 -> V_181 = 0 ;
V_169 ++ ;
}
if ( V_135 -> V_178 == V_177 ) {
if ( V_135 -> V_182 < V_47 -> V_183 ) {
V_135 -> V_182 = V_47 -> V_183 ;
V_169 ++ ;
}
}
if ( ! V_135 -> V_184 ) {
V_135 -> V_184 = 1 ;
V_169 ++ ;
}
if ( V_135 -> V_185 != V_135 -> V_184 ) {
V_135 -> V_185 = V_135 -> V_184 ;
V_169 ++ ;
}
switch ( V_135 -> V_146 ) {
case V_147 :
if ( ! V_135 -> V_186 ) {
V_135 -> V_186 = 1 ;
V_169 ++ ;
}
break;
case V_180 :
if ( V_135 -> V_186 != 0 ) {
V_135 -> V_186 = 0 ;
V_169 ++ ;
}
break;
default:
break;
}
if ( V_169 )
return 3 ;
if ( V_135 -> V_178 == V_177 ) {
if ( V_135 -> V_175 == V_176 ) {
V_171 = V_135 -> V_182 ;
F_50 ( V_187 ,
& ( V_7 -> V_188 ) ,
& ( V_7 -> V_189 ) ,
& ( V_135 -> V_182 ) ,
V_135 ->
V_5 & V_190 ) ;
if ( V_171 != V_135 -> V_182 )
V_169 ++ ;
}
else {
V_171 = V_135 -> V_182 ;
V_135 -> V_182 =
F_51 ( V_135 -> V_182 ,
V_135 -> V_5 & V_190 ) ;
if ( V_171 != V_135 -> V_182 )
V_169 ++ ;
if ( V_135 -> V_175 == V_177 ) {
if ( V_135 -> V_182 * V_135 -> V_184 >
V_135 -> V_191 ) {
V_135 -> V_191 =
V_135 -> V_182 *
V_135 -> V_184 ;
V_169 ++ ;
}
V_171 = V_135 -> V_191 ;
F_50 ( V_187 ,
& ( V_7 ->
V_188 ) ,
& ( V_7 ->
V_189 ) ,
& ( V_135 ->
V_191 ) ,
V_135 ->
V_5 &
V_190 ) ;
if ( V_171 != V_135 -> V_191 )
V_169 ++ ;
}
}
}
if ( V_169 )
return 4 ;
if ( V_135 -> V_192 ) {
V_157 = F_52 ( V_135 -> V_192 [ 0 ] ) & V_193 ;
for ( V_156 = 1 ; V_156 < V_135 -> V_184 ; V_156 ++ ) {
if ( V_157 != ( F_52 ( V_135 -> V_192 [ V_156 ] ) & V_193 ) ) {
F_29 ( V_2 ,
L_25 ) ;
V_169 ++ ;
break;
}
}
}
if ( V_169 )
return 5 ;
return 0 ;
}
static int F_53 ( struct V_134 V_135 )
{
int V_194 ;
V_194 = V_195 ;
if ( V_135 . V_146 == V_174 )
V_194 |= V_196 ;
switch ( V_135 . V_172 ) {
case V_174 :
V_194 |= V_197 | V_198 ;
break;
case V_173 :
V_194 |= V_199 ;
break;
default:
break;
}
return V_194 ;
}
static int F_54 ( struct V_134 V_135 )
{
int V_200 ;
int V_201 ;
V_201 = F_55 ( V_135 . V_192 [ 0 ] ) ;
V_200 = V_202 ;
if ( V_201 != V_203 )
V_200 |= V_204 ;
if ( V_201 == V_205 )
V_200 |= V_206 ;
if ( F_52 ( V_135 . V_192 [ 0 ] ) & V_193 )
V_200 |= V_159 ;
switch ( V_135 . V_175 ) {
case V_176 :
switch ( V_135 . V_178 ) {
case V_177 :
V_200 |= V_207 ;
break;
case V_174 :
V_200 |= V_208 ;
break;
default:
break;
}
break;
case V_177 :
V_200 |= V_209 | V_207 ;
break;
case V_174 :
V_200 |= V_209 | V_208 ;
break;
default:
break;
}
return V_200 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_134 V_135 )
{
switch ( V_135 . V_175 ) {
case V_176 :
if ( V_135 . V_178 == V_177 ) {
F_50 ( V_187 ,
& ( V_7 -> V_188 ) ,
& ( V_7 -> V_189 ) ,
& ( V_135 . V_182 ) ,
V_135 .
V_5 & V_190 ) ;
if ( F_57 ( V_2 ) < 0 )
return - 1 ;
}
break;
case V_177 :
F_50 ( V_187 , & ( V_7 -> V_188 ) ,
& ( V_7 -> V_189 ) ,
& ( V_135 . V_191 ) ,
V_135 . V_5 & V_190 ) ;
if ( F_57 ( V_2 ) < 0 )
return - 1 ;
break;
default:
break;
}
if ( V_135 . V_146 == V_174 ) {
F_58 ( V_2 -> V_32 + V_210 , 0 , 0 , 1 , 0 ) ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_134 V_135 )
{
unsigned long V_211 ;
const int V_149 = V_7 -> V_52 & V_150 ;
if ( ( V_7 -> V_52 & V_138 ) == 0 )
return;
V_7 -> V_151 = F_60 ( & V_135 ) ;
V_211 = F_5 () ;
F_6 ( V_7 -> V_3 ) ;
F_44 ( V_7 -> V_3 ) ;
F_38 ( V_7 -> V_3 , F_39 ( V_7 -> V_20 ) ) ;
F_40 ( V_7 -> V_3 , V_7 -> V_151 ) ;
V_7 -> V_19 = V_7 -> V_3 ;
V_7 -> V_25 = V_7 -> V_20 ;
F_41 ( V_7 -> V_3 ) ;
if ( V_149 ) {
F_6 ( V_7 -> V_4 ) ;
F_44 ( V_7 -> V_4 ) ;
F_38 ( V_7 -> V_4 , F_39 ( V_7 -> V_26 ) ) ;
F_40 ( V_7 -> V_4 , V_7 -> V_151 ) ;
F_41 ( V_7 -> V_4 ) ;
}
F_8 ( V_211 ) ;
return;
}
static void F_61 ( struct V_1 * V_2 , struct V_134 V_135 )
{
int V_156 , V_212 , V_213 ;
unsigned long V_214 ;
const int V_215 = 0x3 ;
const int V_216 = 8 ;
V_212 = V_135 . V_184 ;
F_26 ( & V_2 -> V_122 , V_214 ) ;
F_17 ( V_217 , V_2 -> V_32 + V_98 ) ;
F_17 ( V_212 - 1 , V_2 -> V_32 + V_218 ) ;
for ( V_156 = 0 ; V_156 < V_212 ; V_156 ++ ) {
V_213 =
F_62 ( V_135 .
V_192 [ V_156 ] ) | ( ( F_52 ( V_135 . V_192 [ V_156 ] ) &
V_215 ) << V_216 ) ;
F_19 ( V_213 , V_2 -> V_32 + V_219 ) ;
}
F_17 ( V_212 - 1 , V_2 -> V_32 + V_218 ) ;
F_28 ( & V_2 -> V_122 , V_214 ) ;
return;
}
static int V_73 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_220 ;
int V_194 , V_200 ;
struct V_133 * V_123 = V_31 -> V_123 ;
struct V_134 V_135 = V_123 -> V_135 ;
if ( ! V_2 -> V_6 ) {
F_29 ( V_2 ,
L_26 ) ;
return - 1 ;
}
if ( V_135 . V_5 & ( V_221 | V_222 ) )
V_7 -> V_52 &= ~ V_138 ;
else
V_7 -> V_52 |= V_7 -> V_8 ;
if ( V_135 . V_5 & V_221 ) {
V_7 -> V_52 &= ~ V_223 ;
} else {
V_7 -> V_52 |= V_223 ;
}
if ( V_135 . V_146 == V_147 )
V_7 -> V_148 = V_135 . V_186 * V_135 . V_184 ;
V_81 ( V_2 , V_31 ) ;
V_194 = F_53 ( V_135 ) ;
V_200 = F_54 ( V_135 ) ;
F_61 ( V_2 , V_135 ) ;
V_220 = F_56 ( V_2 , V_135 ) ;
if ( V_220 < 0 ) {
F_29 ( V_2 , L_27 ) ;
return V_220 ;
}
F_59 ( V_2 , V_135 ) ;
F_17 ( V_200 , V_2 -> V_32 + V_158 ) ;
if ( V_200 & V_209 ) {
F_17 ( V_135 . V_182 / 1000 - 1 ,
V_2 -> V_32 + V_224 ) ;
F_17 ( V_135 . V_184 - 1 , V_2 -> V_32 + V_225 ) ;
}
F_17 ( V_7 -> V_52 , V_2 -> V_32 + V_167 ) ;
F_17 ( V_194 , V_2 -> V_32 + V_168 ) ;
F_17 ( V_226 , V_2 -> V_32 + V_130 ) ;
return 0 ;
}
static int V_77 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_227 * V_228 , unsigned int * V_229 )
{
int V_156 , V_212 ;
int V_230 , V_231 , V_201 , V_213 ;
int V_232 = 1000 ;
short V_166 ;
int V_233 = 0 ;
unsigned long V_214 ;
V_201 = F_55 ( V_228 -> V_234 ) ;
V_233 |= V_202 ;
if ( V_201 != V_203 )
V_233 |= V_204 ;
if ( V_201 == V_205 )
V_233 |= V_206 ;
if ( F_52 ( V_228 -> V_234 ) & V_193 )
V_233 |= V_159 ;
F_17 ( V_233 , V_2 -> V_32 + V_158 ) ;
F_17 ( V_226 , V_2 -> V_32 + V_130 ) ;
F_17 ( 0x0 , V_2 -> V_32 + V_168 ) ;
F_17 ( V_195 , V_2 -> V_32 + V_168 ) ;
V_230 = F_62 ( V_228 -> V_234 ) ;
V_231 = F_52 ( V_228 -> V_234 ) & 0x3 ;
V_213 = V_230 | ( V_231 << 8 ) ;
F_26 ( & V_2 -> V_122 , V_214 ) ;
F_17 ( V_217 , V_2 -> V_32 + V_98 ) ;
F_17 ( 0x0 , V_2 -> V_32 + V_218 ) ;
F_19 ( V_213 , V_2 -> V_32 + V_219 ) ;
F_17 ( 0x0 , V_2 -> V_32 + V_218 ) ;
F_17 ( V_137 , V_2 -> V_32 + V_98 ) ;
for ( V_212 = 0 ; V_212 < V_228 -> V_212 ; V_212 ++ ) {
F_17 ( 0 , V_2 -> V_32 + V_165 ) ;
for ( V_156 = 0 ; V_156 < V_232 ; V_156 ++ ) {
if ( F_25 ( V_2 -> V_32 + V_130 ) & V_140 )
break;
}
if ( V_156 == V_232 ) {
F_29 ( V_2 , L_28 ) ;
V_212 = - V_235 ;
goto exit;
}
V_166 = F_48 ( V_2 -> V_32 + V_165 ) ;
if ( ( V_233 & V_159 ) == 0 )
V_166 += 1 << ( V_47 -> V_69 - 1 ) ;
V_229 [ V_212 ] = V_166 ;
}
exit:
F_28 ( & V_2 -> V_122 , V_214 ) ;
return V_212 ;
}
static int V_87 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_227 * V_228 , unsigned int * V_229 )
{
int V_230 = F_62 ( V_228 -> V_234 ) ;
int V_236 = V_47 -> V_84 - 1 ;
short V_237 ;
unsigned long V_214 ;
V_237 = V_229 [ 0 ] - ( 1 << ( V_47 -> V_69 - 1 ) ) ;
if ( V_230 == V_236 )
V_7 -> V_99 = V_237 ;
F_26 ( & V_2 -> V_122 , V_214 ) ;
F_17 ( F_18 ( V_230 ) , V_2 -> V_32 + V_98 ) ;
F_19 ( V_237 , V_2 -> V_32 + V_100 ) ;
if ( V_230 != V_236 ) {
F_17 ( F_18 ( V_236 ) , V_2 -> V_32 + V_98 ) ;
F_19 ( V_7 -> V_99 , V_2 -> V_32 + V_100 ) ;
}
F_28 ( & V_2 -> V_122 , V_214 ) ;
return 1 ;
}
static int V_92 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_227 * V_228 , unsigned int * V_229 )
{
V_229 [ 1 ] = F_25 ( V_2 -> V_32 + V_97 ) & 0xf ;
V_229 [ 0 ] = 0 ;
return 2 ;
}
static int V_95 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_227 * V_228 , unsigned int * V_229 )
{
unsigned int V_238 ;
V_229 [ 0 ] &= ( 1 << V_31 -> V_65 ) - 1 ;
V_238 = V_7 -> V_96 ;
V_238 &= ~ V_229 [ 0 ] ;
V_238 |= V_229 [ 0 ] & V_229 [ 1 ] ;
V_7 -> V_96 = V_238 ;
F_17 ( V_7 -> V_96 , V_2 -> V_32 + V_97 ) ;
V_229 [ 1 ] = V_7 -> V_96 ;
return 2 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_169 = 0 ;
if ( F_58 ( V_2 -> V_32 + V_210 , 0 , 1 , V_7 -> V_188 ,
2 ) )
V_169 ++ ;
if ( F_58 ( V_2 -> V_32 + V_210 , 0 , 2 , V_7 -> V_189 ,
2 ) )
V_169 ++ ;
if ( V_169 )
return - 1 ;
return 0 ;
}
static unsigned int F_51 ( unsigned int V_182 , int V_239 )
{
unsigned int V_240 ;
if ( V_182 > 64000 )
V_182 = 64000 ;
switch ( V_239 ) {
case V_241 :
default:
V_240 = ( V_182 + 500 ) / 1000 ;
break;
case V_242 :
V_240 = V_182 / 1000 ;
break;
case V_243 :
V_240 = ( V_182 - 1 ) / 1000 + 1 ;
break;
}
return V_240 * 1000 ;
}
static unsigned int F_60 ( struct V_134 * V_135 )
{
unsigned int V_244 = V_21 ;
static const int V_245 = 2 ;
unsigned int V_246 = 300000000 ;
unsigned int V_247 ;
switch ( V_135 -> V_175 ) {
case V_176 :
if ( V_135 -> V_178 == V_177 )
V_244 = ( V_246 / V_135 -> V_182 ) * V_245 ;
break;
case V_177 :
V_244 = ( V_246 / ( V_135 -> V_191 * V_135 -> V_184 ) ) *
V_245 ;
break;
default:
V_244 = V_21 ;
break;
}
V_247 = V_21 ;
if ( V_135 -> V_146 == V_147 &&
V_135 -> V_186 * V_135 -> V_184 * V_245 < V_247 )
V_247 = V_135 -> V_186 * V_135 -> V_184 * V_245 ;
if ( V_244 > V_247 )
V_244 = V_247 ;
if ( V_244 < V_245 )
V_244 = V_245 ;
return V_244 ;
}
