static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 = 0 , V_7 = 0 ;
T_2 V_8 , V_9 , div , V_10 = 0 , V_11 = 0 ;
struct V_12 V_13 ;
int V_14 ;
F_2 ( V_2 , V_4 , & V_13 ) ;
V_8 = V_13 . V_15 ;
if ( V_8 < 4800 ) {
if ( F_3 ( V_2 ) ) {
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_10 = ( V_8 * 4 ) / div ;
V_9 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else if ( F_4 ( V_2 ) || F_5 ( V_2 ) ) {
V_10 = ( V_8 * 4 ) / 120 ;
V_9 = ( ( ( V_8 * 4 ) % 120 ) * 0x20000 ) / 120 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else if ( F_6 ( V_2 ) ) {
if ( V_2 -> V_16 ) {
V_10 = ( V_8 * 2 ) / 75 ;
V_9 = ( ( ( V_8 * 2 ) % 75 ) * 0x20000 ) / 75 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_7 ( V_8 ) >> 1 ;
}
} else if ( F_8 ( V_2 ) || F_9 ( V_2 ) ) {
if ( V_2 -> V_16 )
div = 75 ;
else
div = 120 ;
V_10 = ( V_8 * 4 ) / div ;
V_9 = ( ( ( V_8 * 4 ) % div ) * 0x20000 ) / div ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_7 ( V_8 ) ;
}
V_5 = 1 ;
} else {
if ( ( F_6 ( V_2 ) || F_8 ( V_2 ) || F_9 ( V_2 ) ) &&
V_2 -> V_16 ) {
V_10 = V_8 / 75 ;
V_9 = ( ( V_8 % 75 ) * 0x20000 ) / 75 ;
V_10 = ( V_10 << 17 ) | V_9 ;
} else {
V_10 = F_10 ( V_8 ) ;
V_10 >>= 1 ;
}
V_5 = 0 ;
}
V_6 = 1 ;
V_7 = 0 ;
V_14 = 0 ;
V_11 = ( V_5 << 29 ) ;
F_11 ( V_2 , V_17 , V_11 ) ;
F_12 ( V_2 , V_18 ,
V_19 , 1 ) ;
V_11 = ( V_10 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_14 << 31 ) ;
F_11 ( V_2 , V_20 , V_11 ) ;
V_14 = 1 ;
V_11 = ( V_10 << 2 ) | ( V_6 << 30 ) |
( V_7 << 28 ) | ( V_14 << 31 ) ;
F_11 ( V_2 , V_20 , V_11 ) ;
V_2 -> V_21 = V_4 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const T_2 V_22 [ 4 ] = { 2420 , 2440 , 2464 , 2480 } ;
int V_23 , V_24 = 0 , V_25 ;
int V_26 ;
int V_27 , V_28 , V_29 ;
T_3 * V_30 = F_14 ( V_2 , F_15 ( V_4 ) ) ;
if ( F_4 ( V_2 ) || F_6 ( V_2 ) || F_3 ( V_2 ) ||
F_8 ( V_2 ) ) {
if ( V_30 [ 0 ] == 0 )
return;
V_28 = 5 ;
if ( F_16 ( V_4 ) ) {
V_27 = 19 ;
if ( F_17 ( V_2 , V_31 ,
V_32 ) == 0 )
V_29 = V_4 -> V_33 + 10 ;
else
V_29 = V_4 -> V_33 - 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
} else {
V_27 = F_18 ( V_2 ) ? 5 : 10 ;
V_28 = 4 ;
V_29 = V_4 -> V_33 ;
}
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
if ( F_18 ( V_2 ) && ( V_26 == 0 || V_26 == 3 ) )
continue;
V_24 = 0 ;
if ( F_4 ( V_2 ) || F_6 ( V_2 ) || F_3 ( V_2 ) ||
F_8 ( V_2 ) )
V_23 = F_19 ( V_30 [ V_26 ] ,
F_15 ( V_4 ) ) ;
else
V_23 = V_22 [ V_26 ] ;
V_23 -= V_29 ;
if ( V_23 < 0 ) {
V_24 = 1 ;
V_23 = - V_23 ;
}
if ( V_23 < V_27 ) {
V_25 = ( int ) ( ( V_23 << 19 ) / 11 ) ;
if ( V_24 == 1 )
V_25 = - V_25 ;
V_25 = V_25 & 0xfffff ;
F_12 ( V_2 , V_34 ,
V_35 , 0x7 ) ;
F_12 ( V_2 , V_36 ,
V_37 , 0x7f ) ;
F_12 ( V_2 , V_36 ,
V_38 ,
0x2 ) ;
F_12 ( V_2 , V_36 ,
V_39 ,
0x1 ) ;
F_12 ( V_2 , V_36 ,
V_40 ,
V_25 ) ;
return;
}
}
F_12 ( V_2 , V_34 ,
V_35 , 0x5 ) ;
F_12 ( V_2 , V_36 ,
V_39 , 0x0 ) ;
F_12 ( V_2 , V_36 ,
V_40 , 0x0 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_41 ,
V_42 , 0 ) ;
F_12 ( V_2 , V_43 ,
V_44 , 0 ) ;
F_12 ( V_2 , V_43 ,
V_45 , 0 ) ;
F_12 ( V_2 , V_46 ,
V_47 , 0 ) ;
F_12 ( V_2 , V_43 ,
V_48 , 0 ) ;
F_12 ( V_2 , V_43 ,
V_49 , 0 ) ;
F_12 ( V_2 , V_41 ,
V_50 , 0 ) ;
F_12 ( V_2 , V_51 ,
V_52 , 0 ) ;
F_12 ( V_2 , V_51 ,
V_53 , 0 ) ;
F_12 ( V_2 , V_51 ,
V_54 , 0 ) ;
F_12 ( V_2 , V_41 ,
V_55 , 0 ) ;
F_12 ( V_2 , V_41 ,
V_56 , 0 ) ;
F_12 ( V_2 , V_57 ,
V_58 , 0 ) ;
F_12 ( V_2 , V_59 ,
V_60 , 0 ) ;
F_12 ( V_2 , V_61 ,
V_62 , 0 ) ;
F_12 ( V_2 , V_57 ,
V_63 , 0 ) ;
F_12 ( V_2 , V_61 ,
V_64 , 0 ) ;
F_12 ( V_2 , V_59 ,
V_65 , 0 ) ;
F_12 ( V_2 , V_51 ,
V_66 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_67 ,
int V_68 ,
int V_69 ,
int V_70 ,
int V_27 ,
int V_29 )
{
int V_71 = 0 ;
F_12 ( V_2 , V_41 ,
V_42 , 0x1 ) ;
F_12 ( V_2 , V_43 ,
V_44 , V_68 ) ;
F_12 ( V_2 , V_43 ,
V_45 , V_69 ) ;
F_12 ( V_2 , V_46 ,
V_47 , V_70 ) ;
F_12 ( V_2 , V_43 ,
V_48 , 0x1 ) ;
if ( ! ( F_5 ( V_2 ) && V_27 == 10 && V_29 == 2437 ) )
F_12 ( V_2 , V_43 ,
V_49 , 0x1 ) ;
F_12 ( V_2 , V_41 ,
V_50 , 0x1 ) ;
F_12 ( V_2 , V_51 ,
V_72 , 34 ) ;
F_12 ( V_2 , V_51 ,
V_52 , 1 ) ;
if ( ! F_6 ( V_2 ) &&
F_17 ( V_2 , V_73 ,
V_74 ) == 0x1 )
F_12 ( V_2 , V_51 ,
V_53 , 1 ) ;
V_71 = ( V_67 << 4 ) / 5 ;
if ( V_71 < 0 )
V_71 = V_71 - 1 ;
V_71 = V_71 & 0x7f ;
F_12 ( V_2 , V_51 ,
V_54 , 0x1 ) ;
F_12 ( V_2 , V_41 ,
V_55 , 0x1 ) ;
F_12 ( V_2 , V_41 ,
V_56 , 0x1 ) ;
F_12 ( V_2 , V_57 ,
V_58 , V_71 ) ;
F_12 ( V_2 , V_59 ,
V_60 , V_71 ) ;
F_12 ( V_2 , V_61 ,
V_62 , V_71 ) ;
F_12 ( V_2 , V_57 ,
V_63 , 0xc ) ;
F_12 ( V_2 , V_61 ,
V_64 , 0xc ) ;
F_12 ( V_2 , V_59 ,
V_65 , 0xa0 ) ;
F_12 ( V_2 , V_51 ,
V_66 , 0xff ) ;
}
static void F_22 ( struct V_1 * V_2 ,
int V_67 )
{
int V_71 = 0 ;
V_71 = ( V_67 << 4 ) / 5 ;
if ( V_71 < 0 )
V_71 = V_71 - 1 ;
V_71 = V_71 & 0x7f ;
F_12 ( V_2 , V_57 ,
V_75 ,
V_71 ) ;
F_12 ( V_2 , V_76 ,
V_60 ,
V_71 ) ;
F_12 ( V_2 , V_61 ,
V_77 ,
V_71 ) ;
F_12 ( V_2 , V_57 ,
V_78 , 0xe ) ;
F_12 ( V_2 , V_61 ,
V_79 , 0xe ) ;
F_12 ( V_2 , V_76 ,
V_65 , 0xa0 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_67 ,
int V_27 ,
int V_29 )
{
int V_68 = 0 ;
int V_70 = 0 ;
int V_69 = 0 ;
if ( F_16 ( V_4 ) ) {
if ( V_67 < 0 ) {
if ( F_17 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_70 = 1 ;
else
V_70 = 0 ;
V_68 = ( ( V_67 + 10 ) << 9 ) / 11 ;
} else {
if ( F_17 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_70 = 0 ;
else
V_70 = 1 ;
V_68 = ( ( V_67 - 10 ) << 9 ) / 11 ;
}
V_69 = ( V_67 << 17 ) / 5 ;
} else {
V_70 = 0 ;
V_68 = ( V_67 << 9 ) / 11 ;
V_69 = ( V_67 << 18 ) / 5 ;
}
V_68 = V_68 & 0x3ff ;
V_69 = V_69 & 0xfffff ;
F_21 ( V_2 ,
V_67 ,
V_68 ,
V_69 ,
V_70 ,
V_27 , V_29 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_29 ;
int V_27 = 10 ;
int V_67 = 0 ;
int V_80 ;
T_3 * V_81 ;
unsigned int V_26 ;
struct V_82 * V_83 = & V_2 -> V_84 . V_85 ;
if ( F_25 ( V_4 ) ) {
V_81 = & ( V_83 -> V_86 . V_87 [ 0 ] ) ;
V_80 = 0 ;
}
else {
V_81 = & ( V_83 -> V_88 . V_87 [ 0 ] ) ;
V_80 = 1 ;
}
if ( V_81 [ 0 ] == 0 )
return;
if ( F_16 ( V_4 ) ) {
V_27 = 19 ;
if ( F_17 ( V_2 , V_31 ,
V_32 ) == 0x0 )
V_29 = V_4 -> V_33 - 10 ;
else
V_29 = V_4 -> V_33 + 10 ;
} else {
V_27 = 10 ;
V_29 = V_4 -> V_33 ;
}
F_20 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_89 && V_81 [ V_26 ] ; V_26 ++ ) {
V_67 = F_19 ( V_81 [ V_26 ] , V_80 ) ;
V_67 -= V_29 ;
if ( abs ( V_67 ) < V_27 ) {
F_23 ( V_2 , V_4 , V_67 ,
V_27 , V_29 ) ;
if ( F_5 ( V_2 ) && ( V_26 < 4 ) ) {
V_67 = F_19 ( V_81 [ V_26 + 1 ] ,
V_80 ) ;
V_67 -= V_29 ;
if ( abs ( V_67 ) < V_27 )
F_22 ( V_2 , V_67 ) ;
}
break;
}
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_5 ( V_2 ) )
F_13 ( V_2 , V_4 ) ;
F_24 ( V_2 , V_4 ) ;
}
static T_2 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_90 ;
V_90 = F_28 ( 0x5 , V_91 ) ;
if ( V_4 && F_29 ( V_4 ) )
V_90 |= F_28 ( 0x1 , V_92 ) ;
else if ( V_4 && F_30 ( V_4 ) )
V_90 |= F_28 ( 0x2 , V_92 ) ;
V_90 |= F_28 ( 0x2c , V_93 ) ;
return V_90 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_94 ;
T_2 V_95 = 0 ;
V_95 =
( F_32 ( V_2 , V_31 ) & V_96 ) ;
V_94 = V_97 | V_98 |
V_99 | V_95 ;
if ( F_16 ( V_4 ) ) {
V_94 |= V_100 ;
if ( F_33 ( V_4 ) )
V_94 |= V_32 ;
}
V_94 |= F_32 ( V_2 , V_31 ) ;
V_94 &= ~ V_101 ;
F_11 ( V_2 , V_31 , V_94 ) ;
F_34 ( V_2 , V_4 ) ;
F_11 ( V_2 , V_102 , 25 << V_103 ) ;
F_11 ( V_2 , V_104 , 0xF << V_105 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_106 ;
V_106 = F_32 ( V_2 , V_107 ) & V_108 ;
F_11 ( V_2 , V_109 , V_110 ) ;
F_36 ( V_2 , V_4 , V_106 ) ;
}
void F_37 ( struct V_1 * V_2 , T_3 V_111 , T_3 V_112 )
{
if ( V_2 -> V_113 . V_114 == 5 || V_2 -> V_113 . V_115 == 5 )
F_38 ( V_2 , V_116 ,
V_117 ) ;
F_11 ( V_2 , V_118 , V_111 ) ;
F_11 ( V_2 , V_119 , V_111 ) ;
if ( ( V_2 -> V_113 . V_120 & V_121 ) && ( V_112 == 0x7 ) )
V_112 = 3 ;
F_11 ( V_2 , V_122 , V_112 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_2 V_123 ;
F_38 ( V_2 , V_124 , ( V_125 | V_126 ) ) ;
V_123 = F_32 ( V_2 , V_127 ) & ( ~ V_128 ) ;
V_123 |= V_129 |
V_130 |
V_131 ;
F_11 ( V_2 , V_127 , V_123 ) ;
if ( F_18 ( V_2 ) || F_5 ( V_2 ) ) {
F_11 ( V_2 , V_132 ,
V_133 ) ;
if ( F_17 ( V_2 , V_134 ,
V_135 ) )
V_2 -> V_136 |= V_137 ;
else
V_2 -> V_136 &= ~ V_137 ;
}
if ( F_32 ( V_2 , V_138 ) & V_139 )
V_2 -> V_136 |= V_140 ;
else
V_2 -> V_136 &= ~ V_140 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_141 * V_142 ,
int V_143 )
{
unsigned int V_26 , V_144 = 0 ;
if ( ! V_142 -> V_145 )
return;
if ( V_143 >= V_142 -> V_146 )
V_143 = 1 ;
for ( V_26 = 0 ; V_26 < V_142 -> V_147 ; V_26 ++ ) {
T_2 V_148 = F_41 ( V_142 , V_26 , 0 ) ;
T_2 V_123 = F_41 ( V_142 , V_26 , V_143 ) ;
F_11 ( V_2 , V_148 , V_123 ) ;
F_42 ( V_144 ) ;
}
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_149 ;
if ( F_15 ( V_4 ) ) {
if ( F_16 ( V_4 ) )
return 7 ;
else
return 8 ;
}
if ( V_4 -> V_33 <= 5350 )
V_149 = 1 ;
else if ( ( V_4 -> V_33 > 5350 ) && ( V_4 -> V_33 <= 5600 ) )
V_149 = 3 ;
else
V_149 = 5 ;
if ( F_16 ( V_4 ) )
V_149 ++ ;
return V_149 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 ) || F_46 ( V_2 ) || F_8 ( V_2 ) ) {
F_47 ( V_2 , V_150 ,
1 << V_151 |
1 << V_152 , 0 ) ;
F_47 ( V_2 , V_153 ,
1 << V_151 |
1 << V_152 , 0 ) ;
F_47 ( V_2 , V_154 ,
1 << V_151 |
1 << V_152 , 0 ) ;
F_48 ( 200 ) ;
F_49 ( V_2 , V_150 ,
V_155 ) ;
F_49 ( V_2 , V_153 ,
V_155 ) ;
F_49 ( V_2 , V_154 ,
V_155 ) ;
F_48 ( 1 ) ;
F_12 ( V_2 , V_150 ,
V_155 , 1 ) ;
F_12 ( V_2 , V_153 ,
V_155 , 1 ) ;
F_12 ( V_2 , V_154 ,
V_155 , 1 ) ;
F_48 ( 200 ) ;
F_12 ( V_2 , V_156 ,
V_157 , 0xf ) ;
F_47 ( V_2 , V_150 , 0 ,
1 << V_151 |
1 << V_152 ) ;
F_47 ( V_2 , V_153 , 0 ,
1 << V_151 |
1 << V_152 ) ;
F_47 ( V_2 , V_154 , 0 ,
1 << V_151 |
1 << V_152 ) ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_144 = 0 , V_26 ;
T_2 V_158 ;
if ( F_25 ( V_4 ) )
V_158 = F_16 ( V_4 ) ? 2 : 1 ;
else
V_158 = F_16 ( V_4 ) ? 3 : 4 ;
for ( V_26 = 0 ; V_26 < V_159 ; V_26 ++ ) {
F_40 ( V_2 , & V_2 -> V_160 [ V_26 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_161 [ V_26 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_162 [ V_26 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_163 [ V_26 ] , V_158 ) ;
if ( V_26 == V_164 && F_51 ( V_2 ) )
F_40 ( V_2 ,
& V_2 -> V_165 ,
V_158 ) ;
}
F_44 ( V_2 ) ;
F_52 ( & V_2 -> V_166 , 1 , V_144 ) ;
if ( F_51 ( V_2 ) ) {
if ( F_53 ( V_2 ) == 2 ) {
F_52 ( & V_2 -> V_167 ,
1 , V_144 ) ;
F_52 ( & V_2 -> V_168 ,
V_158 , V_144 ) ;
}
if ( ( F_53 ( V_2 ) == 2 ) ||
( F_53 ( V_2 ) == 3 ) ) {
F_52 ( & V_2 -> V_169 ,
V_158 , V_144 ) ;
}
}
if ( F_8 ( V_2 ) )
F_52 ( & V_2 -> V_170 , V_158 ,
V_144 ) ;
if ( F_8 ( V_2 ) || F_9 ( V_2 ) ) {
int V_171 = 1 ;
if ( F_8 ( V_2 ) )
V_171 = F_43 ( V_2 , V_4 ) ;
if ( V_171 < 0 )
return - V_172 ;
F_52 ( & V_2 -> V_173 , V_171 ,
V_144 ) ;
} else {
F_52 ( & V_2 -> V_173 , V_158 , V_144 ) ;
}
if ( F_54 ( V_2 , V_4 ) )
F_52 ( & V_2 -> V_174 ,
V_158 , V_144 ) ;
F_52 ( & V_2 -> V_175 , 1 , V_144 ) ;
if ( V_4 -> V_33 == 2484 )
F_40 ( V_2 , & V_2 -> V_176 , 1 ) ;
V_2 -> V_177 = V_158 ;
F_39 ( V_2 ) ;
F_31 ( V_2 , V_4 ) ;
F_37 ( V_2 , V_2 -> V_178 , V_2 -> V_179 ) ;
F_55 ( V_2 , V_4 , false ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_180 = 0 ;
if ( V_4 == NULL )
return;
if ( F_15 ( V_4 ) )
V_180 |= V_74 ;
else
V_180 |= V_181 ;
if ( F_54 ( V_2 , V_4 ) )
V_180 |= ( V_74 | V_182 ) ;
if ( F_30 ( V_4 ) )
V_180 |= V_183 ;
if ( F_29 ( V_4 ) )
V_180 |= V_184 ;
if ( V_180 & ( V_183 | V_184 ) )
F_12 ( V_2 , V_185 ,
V_186 , 3 ) ;
F_11 ( V_2 , V_73 , V_180 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_109 , V_187 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_188 , V_189 , V_190 ;
T_2 V_191 = 0x64000000 ;
struct V_12 V_13 ;
if ( F_29 ( V_4 ) )
V_191 = V_191 >> 1 ;
else if ( F_30 ( V_4 ) )
V_191 = V_191 >> 2 ;
F_2 ( V_2 , V_4 , & V_13 ) ;
V_188 = V_191 / V_13 . V_15 ;
F_59 ( V_2 , V_188 , & V_190 ,
& V_189 ) ;
F_12 ( V_2 , V_192 ,
V_193 , V_190 ) ;
F_12 ( V_2 , V_192 ,
V_194 , V_189 ) ;
V_188 = ( 9 * V_188 ) / 10 ;
F_59 ( V_2 , V_188 , & V_190 ,
& V_189 ) ;
F_12 ( V_2 , V_195 ,
V_196 , V_190 ) ;
F_12 ( V_2 , V_195 ,
V_197 , V_189 ) ;
}
static bool F_60 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_198 , V_199 ) ;
return F_61 ( V_2 , V_200 , V_201 ,
V_201 , V_202 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_2 V_106 = F_32 ( V_2 , V_107 ) & V_108 ;
F_36 ( V_2 , V_2 -> V_21 , V_106 ) ;
F_11 ( V_2 , V_198 , 0 ) ;
}
static bool F_63 ( struct V_1 * V_2 ,
enum V_203 V_204 , int V_205 )
{
struct V_206 * V_207 = F_64 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_208 * V_209 = & V_2 -> V_210 ;
int V_211 , V_212 ;
int V_213 , V_214 ;
int V_215 , V_216 ;
int V_217 , V_218 ;
int V_219 , V_220 ;
T_4 V_221 , V_222 ;
switch ( V_204 & V_2 -> V_223 ) {
case V_224 : {
T_2 V_225 = V_205 ? 1 : 0 ;
if ( F_18 ( V_2 ) || F_5 ( V_2 ) )
goto V_226;
V_211 = V_225 ?
V_209 -> V_227 . V_211 : V_228 ;
V_212 = V_225 ?
V_209 -> V_227 . V_212 : V_229 ;
V_213 = V_225 ?
V_209 -> V_227 . V_213 : V_230 ;
V_214 = V_225 ?
V_209 -> V_227 . V_214 : V_231 ;
V_215 = V_225 ?
V_209 -> V_227 . V_215 : V_232 ;
V_216 = V_225 ?
V_209 -> V_227 . V_216 : V_233 ;
V_217 = V_225 ?
V_209 -> V_227 . V_217 : V_234 ;
V_218 = V_225 ?
V_209 -> V_227 . V_218 : V_235 ;
V_219 = V_225 ?
V_209 -> V_227 . V_219 : V_236 ;
V_220 = V_225 ?
V_209 -> V_227 . V_220 : V_237 ;
F_12 ( V_2 , V_238 ,
V_239 ,
V_211 ) ;
F_12 ( V_2 , V_238 ,
V_240 ,
V_212 ) ;
F_12 ( V_2 , V_241 ,
V_242 ,
V_213 ) ;
F_12 ( V_2 , V_241 ,
V_243 ,
V_214 ) ;
F_12 ( V_2 , V_241 ,
V_244 ,
V_215 ) ;
F_12 ( V_2 , V_238 ,
V_245 ,
V_216 ) ;
F_12 ( V_2 , V_46 ,
V_246 ,
V_217 ) ;
F_12 ( V_2 , V_46 ,
V_247 ,
V_218 ) ;
F_12 ( V_2 , V_46 ,
V_248 ,
V_219 ) ;
F_12 ( V_2 , V_46 ,
V_249 ,
V_220 ) ;
V_226:
if ( V_225 )
F_38 ( V_2 , V_238 ,
V_250 ) ;
else
F_49 ( V_2 , V_238 ,
V_250 ) ;
if ( V_225 != V_209 -> V_251 ) {
F_65 ( V_207 , V_252 ,
L_1 ,
V_4 -> V_33 ,
V_209 -> V_251 ?
L_2 : L_3 ,
V_225 ? L_2 : L_3 ) ;
if ( V_225 )
V_2 -> V_253 . V_254 ++ ;
else
V_2 -> V_253 . V_255 ++ ;
V_209 -> V_251 = V_225 ;
}
break;
}
case V_256 : {
T_2 V_257 = V_205 ;
if ( V_257 >= F_66 ( V_258 ) ) {
F_65 ( V_207 , V_252 ,
L_4 ,
V_257 , F_66 ( V_258 ) ) ;
return false ;
}
V_221 = V_258 [ V_257 ] -
V_258 [ V_259 ] +
V_209 -> V_227 . V_260 ;
if ( V_221 < V_261 )
V_221 = V_261 ;
if ( V_221 > V_262 )
V_221 = V_262 ;
F_12 ( V_2 , V_263 ,
V_264 ,
V_221 ) ;
V_222 = V_258 [ V_257 ] -
V_258 [ V_259 ] +
V_209 -> V_227 . V_265 ;
if ( V_222 < V_261 )
V_222 = V_261 ;
if ( V_222 > V_262 )
V_222 = V_262 ;
F_12 ( V_2 , V_266 ,
V_267 , V_222 ) ;
if ( V_257 != V_209 -> V_268 ) {
F_65 ( V_207 , V_252 ,
L_5 ,
V_4 -> V_33 ,
V_209 -> V_268 ,
V_257 ,
V_259 ,
V_221 ,
V_209 -> V_227 . V_260 ) ;
F_65 ( V_207 , V_252 ,
L_6 ,
V_4 -> V_33 ,
V_209 -> V_268 ,
V_257 ,
V_259 ,
V_222 ,
V_209 -> V_227 . V_265 ) ;
if ( V_257 > V_209 -> V_268 )
V_2 -> V_253 . V_269 ++ ;
else if ( V_257 < V_209 -> V_268 )
V_2 -> V_253 . V_270 ++ ;
V_209 -> V_268 = V_257 ;
}
break;
}
case V_271 : {
T_2 V_257 = V_205 ;
if ( V_257 >= F_66 ( V_272 ) ) {
F_65 ( V_207 , V_252 ,
L_7 ,
V_257 , F_66 ( V_272 ) ) ;
return false ;
}
V_221 = V_272 [ V_257 ] -
V_272 [ V_273 ] +
V_209 -> V_227 . V_274 ;
if ( V_221 < V_275 )
V_221 = V_275 ;
if ( V_221 > V_276 )
V_221 = V_276 ;
F_12 ( V_2 , V_277 ,
V_278 ,
V_221 ) ;
V_222 = V_272 [ V_257 ] -
V_272 [ V_273 ] +
V_209 -> V_227 . V_279 ;
if ( V_222 < V_275 )
V_222 = V_275 ;
if ( V_222 > V_276 )
V_222 = V_276 ;
F_12 ( V_2 , V_280 ,
V_281 , V_222 ) ;
if ( V_257 != V_209 -> V_282 ) {
F_65 ( V_207 , V_252 ,
L_8 ,
V_4 -> V_33 ,
V_209 -> V_282 ,
V_257 ,
V_273 ,
V_221 ,
V_209 -> V_227 . V_274 ) ;
F_65 ( V_207 , V_252 ,
L_9 ,
V_4 -> V_33 ,
V_209 -> V_282 ,
V_257 ,
V_273 ,
V_222 ,
V_209 -> V_227 . V_279 ) ;
if ( V_257 > V_209 -> V_282 )
V_2 -> V_253 . V_283 ++ ;
else if ( V_257 < V_209 -> V_282 )
V_2 -> V_253 . V_284 ++ ;
V_209 -> V_282 = V_257 ;
}
break;
}
case V_285 : {
bool V_286 = V_205 ? 1 : 0 ;
if ( V_2 -> V_113 . V_115 == 1 )
break;
F_12 ( V_2 , V_287 ,
V_288 , V_286 ) ;
F_12 ( V_2 , V_287 ,
V_289 , V_286 ) ;
if ( V_286 != V_209 -> V_290 ) {
F_65 ( V_207 , V_252 , L_10 ,
V_4 -> V_33 ,
V_209 -> V_290 ? L_2 : L_3 ,
V_286 ? L_2 : L_3 ) ;
if ( V_286 )
V_2 -> V_253 . V_291 ++ ;
else
V_2 -> V_253 . V_292 ++ ;
V_209 -> V_290 = V_286 ;
}
break;
}
default:
F_65 ( V_207 , V_252 , L_11 , V_204 ) ;
return false ;
}
F_65 ( V_207 , V_252 ,
L_12 ,
V_209 -> V_282 ,
V_209 -> V_251 ? L_2 : L_3 ,
V_209 -> V_268 ,
V_209 -> V_290 ? L_2 : L_3 ,
V_209 -> V_293 ,
V_209 -> V_294 ,
V_209 -> V_295 ) ;
return true ;
}
static void F_67 ( struct V_1 * V_2 ,
T_5 V_296 [ V_297 ] )
{
#define F_68 0x1FF00000
#define F_69 20
#define F_70 0x01FF0000
#define F_71 16
T_5 V_298 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_299 ; V_26 ++ ) {
if ( V_2 -> V_178 & F_72 ( V_26 ) ) {
V_298 = F_73 ( F_32 ( V_2 , V_2 -> V_300 [ V_26 ] ) ,
F_68 ) ;
V_296 [ V_26 ] = F_74 ( V_298 , 8 ) ;
if ( F_16 ( V_2 -> V_21 ) ) {
T_3 V_301 = V_299 + V_26 ;
V_298 = F_73 ( F_32 ( V_2 , V_2 -> V_300 [ V_301 ] ) ,
F_70 ) ;
V_296 [ V_301 ] = F_74 ( V_298 , 8 ) ;
}
}
}
}
static void F_75 ( struct V_1 * V_2 )
{
V_2 -> V_302 . V_303 = V_304 ;
V_2 -> V_302 . V_305 = V_306 ;
V_2 -> V_302 . V_307 = V_308 ;
V_2 -> V_309 . V_303 = V_310 ;
V_2 -> V_309 . V_305 = V_311 ;
V_2 -> V_309 . V_307 = V_312 ;
if ( F_3 ( V_2 ) )
V_2 -> V_302 . V_307 = V_313 ;
if ( F_18 ( V_2 ) || F_5 ( V_2 ) ) {
V_2 -> V_302 . V_305 = V_314 ;
V_2 -> V_302 . V_307 = V_315 ;
V_2 -> V_309 . V_305 = V_316 ;
V_2 -> V_309 . V_307 = V_317 ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_208 * V_209 ;
struct V_206 * V_207 = F_64 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_318 * V_227 ;
T_2 V_123 ;
V_209 = & V_2 -> V_210 ;
V_227 = & V_209 -> V_227 ;
F_65 ( V_207 , V_252 , L_13 ,
V_2 -> V_319 . V_320 ,
V_2 -> V_319 . V_321 ,
V_2 -> V_322 ,
V_4 -> V_33 ) ;
V_123 = F_32 ( V_2 , V_241 ) ;
V_227 -> V_213 = F_73 ( V_123 , V_242 ) ;
V_227 -> V_214 = F_73 ( V_123 , V_243 ) ;
V_227 -> V_215 = F_73 ( V_123 , V_244 ) ;
V_123 = F_32 ( V_2 , V_238 ) ;
V_227 -> V_211 = F_73 ( V_123 , V_239 ) ;
V_227 -> V_212 = F_73 ( V_123 , V_240 ) ;
V_227 -> V_216 = F_73 ( V_123 , V_245 ) ;
V_123 = F_32 ( V_2 , V_46 ) ;
V_227 -> V_219 = F_73 ( V_123 , V_248 ) ;
V_227 -> V_220 = F_73 ( V_123 , V_249 ) ;
V_227 -> V_217 = F_73 ( V_123 , V_246 ) ;
V_227 -> V_218 = F_73 ( V_123 , V_247 ) ;
V_227 -> V_260 = F_17 ( V_2 ,
V_263 ,
V_264 ) ;
V_227 -> V_265 = F_17 ( V_2 ,
V_266 ,
V_267 ) ;
V_227 -> V_274 = F_17 ( V_2 ,
V_277 ,
V_278 ) ;
V_227 -> V_279 = F_17 ( V_2 ,
V_280 ,
V_281 ) ;
V_209 -> V_282 = V_273 ;
V_209 -> V_268 = V_259 ;
V_209 -> V_251 = true ;
V_209 -> V_290 = true ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_323 * V_324 )
{
unsigned int V_144 = 0 ;
T_2 V_325 = 0 , V_326 = 0 ;
if ( ! V_324 ) {
F_49 ( V_2 , V_327 , V_328 ) ;
return;
}
V_325 |= V_328 | V_329 ;
V_325 |= F_28 ( V_324 -> V_330 , V_331 ) ;
V_325 |= F_28 ( V_324 -> V_332 , V_333 ) ;
V_325 |= F_28 ( V_324 -> V_334 , V_335 ) ;
V_325 |= F_28 ( V_324 -> V_336 , V_337 ) ;
V_325 |= F_28 ( V_324 -> V_338 , V_339 ) ;
V_326 |= V_340 ;
V_326 |= V_341 ;
V_326 |= F_28 ( V_324 -> V_342 , V_343 ) ;
V_326 |= F_28 ( V_324 -> V_344 , V_345 ) ;
V_326 |= F_28 ( V_324 -> V_346 , V_347 ) ;
F_11 ( V_2 , V_327 , V_325 ) ;
F_11 ( V_2 , V_348 , V_326 ) ;
if ( V_324 -> V_349 )
F_38 ( V_2 , V_350 , V_351 ) ;
else
F_49 ( V_2 , V_350 , V_351 ) ;
if ( F_45 ( V_2 ) || F_6 ( V_2 ) || F_46 ( V_2 ) ) {
F_52 ( & V_2 -> V_352 ,
F_16 ( V_2 -> V_21 ) ? 2 : 1 , V_144 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_323 * V_324 = & V_2 -> V_353 ;
V_324 -> V_330 = - 28 ;
V_324 -> V_332 = 0 ;
V_324 -> V_334 = 10 ;
V_324 -> V_336 = 24 ;
V_324 -> V_338 = 8 ;
V_324 -> V_342 = 255 ;
V_324 -> V_344 = 12 ;
V_324 -> V_346 = 8 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_354 * V_355 )
{
T_2 V_356 ;
V_356 = F_32 ( V_2 , V_357 ) ;
V_355 -> V_358 = ( V_356 & V_359 ) >>
V_360 ;
V_355 -> V_361 = ( V_356 & V_362 ) >>
V_363 ;
V_355 -> V_364 = ( V_356 & V_365 ) >>
V_366 ;
if ( F_80 ( V_2 ) ) {
V_355 -> V_367 = - 1 ;
V_355 -> V_368 = - 9 ;
V_355 -> V_369 = 1 ;
} else if ( F_4 ( V_2 ) ) {
V_355 -> V_367 = - 1 ;
V_355 -> V_368 = - 9 ;
V_355 -> V_369 = 2 ;
} else if ( F_5 ( V_2 ) ) {
V_355 -> V_367 = 3 ;
V_355 -> V_368 = - 9 ;
V_355 -> V_369 = 3 ;
} else {
V_355 -> V_367 = - 1 ;
V_355 -> V_368 = - 3 ;
V_355 -> V_369 = 0 ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_354 * V_355 )
{
T_2 V_356 ;
V_356 = F_32 ( V_2 , V_357 ) ;
V_356 &= ~ ( V_359 |
V_362 |
V_365 |
V_370 |
V_371 ) ;
V_356 |= ( ( V_355 -> V_358 << V_360 )
& V_359 ) ;
V_356 |= ( ( V_355 -> V_361 << V_363 )
& V_362 ) ;
V_356 |= ( ( V_355 -> V_364 << V_366 )
& V_365 ) ;
V_356 |= ( ( V_355 -> V_372 << V_373 )
& V_370 ) ;
V_356 |= ( ( V_355 -> V_374 << V_375 )
& V_371 ) ;
F_11 ( V_2 , V_357 , V_356 ) ;
}
static void F_82 ( struct V_1 * V_2 , bool V_376 )
{
struct V_377 * V_378 = & V_2 -> V_113 ;
T_3 V_379 ;
T_2 V_356 ;
if ( ! F_4 ( V_2 ) && ! F_5 ( V_2 ) )
return;
if ( F_4 ( V_2 ) ) {
V_356 = F_83 ( V_2 ,
F_15 ( V_2 -> V_21 ) ) ;
if ( V_376 ) {
V_356 &= ~ V_380 ;
V_356 |= V_2 -> V_381 . V_382 ;
}
F_12 ( V_2 , V_383 ,
V_380 , V_356 ) ;
}
V_379 = V_2 -> V_384 -> V_385 ( V_2 , V_386 ) ;
V_356 = F_32 ( V_2 , V_357 ) ;
V_356 &= ( ~ V_387 ) ;
V_356 |= ( V_379 & 0x3f ) << V_388 ;
F_11 ( V_2 , V_357 , V_356 ) ;
if ( F_84 ( V_2 ) ) {
V_356 = F_32 ( V_2 , V_357 ) ;
V_356 &= ~ V_389 ;
V_356 |= ( ( V_379 >> 6 ) & 0x1 ) << V_390 ;
if ( V_376 )
V_356 |= V_391 ;
F_11 ( V_2 , V_357 , V_356 ) ;
V_356 = F_32 ( V_2 , V_392 ) ;
V_356 &= ~ V_393 ;
V_356 |= ( ( V_379 >> 7 ) & 0x1 ) << V_394 ;
if ( V_376 )
V_356 |= V_393 ;
F_11 ( V_2 , V_392 , V_356 ) ;
if ( V_378 -> V_120 & V_395 ) {
V_356 = F_32 ( V_2 , V_357 ) ;
V_356 &= ( ~ ( V_359 |
V_362 |
V_371 |
V_370 ) ) ;
V_356 |= ( V_396 <<
V_360 ) ;
V_356 |= ( V_397 <<
V_363 ) ;
F_11 ( V_2 , V_357 , V_356 ) ;
}
} else if ( F_5 ( V_2 ) ) {
if ( V_376 ) {
F_38 ( V_2 , V_357 ,
V_391 ) ;
F_38 ( V_2 , V_357 ,
( 1 << V_398 ) ) ;
F_38 ( V_2 , V_392 ,
V_393 ) ;
F_38 ( V_2 , V_399 ,
V_400 ) ;
F_38 ( V_2 , V_401 ,
V_402 ) ;
} else {
F_49 ( V_2 , V_357 ,
V_391 ) ;
F_49 ( V_2 , V_357 ,
( 1 << V_398 ) ) ;
F_49 ( V_2 , V_392 ,
V_393 ) ;
F_49 ( V_2 , V_399 ,
V_400 ) ;
F_49 ( V_2 , V_401 ,
V_402 ) ;
V_356 = F_32 ( V_2 , V_357 ) ;
V_356 &= ~ ( V_359 |
V_362 |
V_370 |
V_371 ) ;
V_356 |= ( V_396 <<
V_360 ) ;
V_356 |= ( V_397 <<
V_363 ) ;
F_11 ( V_2 , V_357 , V_356 ) ;
}
}
}
static int F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 * V_403 )
{
unsigned int V_144 = 0 ;
T_2 V_158 ;
if ( F_25 ( V_4 ) )
V_158 = F_16 ( V_4 ) ? 2 : 1 ;
else
V_158 = F_16 ( V_4 ) ? 3 : 4 ;
if ( V_158 == V_2 -> V_177 ) {
* V_403 = false ;
goto V_404;
}
F_40 ( V_2 , & V_2 -> V_160 [ V_164 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_161 [ V_164 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_162 [ V_164 ] , V_158 ) ;
F_40 ( V_2 , & V_2 -> V_163 [ V_164 ] , V_158 ) ;
if ( F_51 ( V_2 ) )
F_40 ( V_2 , & V_2 -> V_165 ,
V_158 ) ;
F_52 ( & V_2 -> V_173 , V_158 , V_144 ) ;
if ( F_51 ( V_2 ) ) {
if ( F_53 ( V_2 ) == 2 ) {
F_52 ( & V_2 -> V_167 ,
1 , V_144 ) ;
F_52 ( & V_2 -> V_168 ,
V_158 , V_144 ) ;
}
}
if ( F_54 ( V_2 , V_4 ) )
F_52 ( & V_2 -> V_174 , V_158 , V_144 ) ;
if ( F_5 ( V_2 ) )
F_52 ( & V_2 -> V_174 , 1 , V_144 ) ;
if ( V_4 -> V_33 == 2484 )
F_40 ( V_2 , & V_2 -> V_176 , 1 ) ;
V_2 -> V_177 = V_158 ;
* V_403 = true ;
V_404:
F_56 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_405 * V_205 )
{
T_3 V_406 ;
if ( ! V_205 -> V_407 ) {
F_49 ( V_2 , V_408 ,
V_409 ) ;
return;
}
F_38 ( V_2 , V_327 , V_329 ) ;
F_38 ( V_2 , V_408 , V_409 ) ;
V_406 = V_205 -> V_406 ;
if ( V_205 -> V_410 )
V_406 = 0 ;
else if ( V_205 -> V_406 == 0 )
V_406 = 1 ;
if ( V_205 -> V_411 )
F_38 ( V_2 , V_408 ,
V_412 ) ;
else
F_49 ( V_2 , V_408 ,
V_412 ) ;
F_12 ( V_2 , V_408 ,
V_413 , V_406 ) ;
F_12 ( V_2 , V_408 ,
V_414 , V_205 -> V_415 ) ;
F_12 ( V_2 , V_408 ,
V_416 , V_205 -> V_417 ) ;
return;
}
static void F_87 ( struct V_1 * V_2 )
{
F_38 ( V_2 , V_408 ,
V_418 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = F_64 ( V_2 ) ;
if ( ! F_61 ( V_2 , V_408 ,
V_418 ,
0 , V_202 ) ) {
F_89 ( V_207 , L_14 ) ;
return;
}
}
static void F_90 ( struct V_1 * V_2 , T_2 V_419 )
{
F_38 ( V_2 , V_420 , V_421 ) ;
F_38 ( V_2 , 0x9864 , 0x7f000 ) ;
F_38 ( V_2 , 0x9924 , 0x7f00fe ) ;
F_49 ( V_2 , V_124 , V_125 ) ;
F_11 ( V_2 , V_422 , V_423 ) ;
F_11 ( V_2 , F_91 ( V_419 ) , 0 ) ;
F_11 ( V_2 , V_424 , 20 ) ;
F_11 ( V_2 , V_425 , 20 ) ;
F_11 ( V_2 , V_426 , 0x00000400 ) ;
F_11 ( V_2 , F_92 ( V_419 ) , 0xffffffff ) ;
F_38 ( V_2 , F_93 ( V_419 ) , V_427 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_420 , V_421 ) ;
F_38 ( V_2 , V_124 , V_125 ) ;
}
static void F_95 ( struct V_1 * V_2 , T_3 V_428 )
{
static T_6 V_429 [ V_430 ] = { 0 } ;
unsigned int V_26 ;
if ( V_428 <= V_431 ) {
for ( V_26 = 0 ; V_26 < V_430 ; V_26 ++ )
V_429 [ V_26 ] = V_428 ;
} else {
for ( V_26 = 0 ; V_26 < V_430 ; V_26 ++ )
V_429 [ V_26 ] = V_431 ;
}
F_11 ( V_2 , 0xa458 , 0 ) ;
F_11 ( V_2 , 0xa3c0 ,
F_96 ( V_429 [ V_432 ] , 24 ) |
F_96 ( V_429 [ V_432 ] , 16 ) |
F_96 ( V_429 [ V_432 ] , 8 ) |
F_96 ( V_429 [ V_432 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3c4 ,
F_96 ( V_429 [ V_433 ] , 24 ) |
F_96 ( V_429 [ V_434 ] , 16 ) |
F_96 ( V_429 [ V_435 ] , 8 ) |
F_96 ( V_429 [ V_432 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3c8 ,
F_96 ( V_429 [ V_436 ] , 24 ) |
F_96 ( V_429 [ V_436 ] , 16 ) |
F_96 ( V_429 [ V_436 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3cc ,
F_96 ( V_429 [ V_437 ] , 24 ) |
F_96 ( V_429 [ V_438 ] , 16 ) |
F_96 ( V_429 [ V_439 ] , 8 ) |
F_96 ( V_429 [ V_436 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3d0 ,
F_96 ( V_429 [ V_440 ] , 24 ) |
F_96 ( V_429 [ V_441 ] , 16 ) |
F_96 ( V_429 [ V_442 ] , 8 ) |
F_96 ( V_429 [ V_443 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3d4 ,
F_96 ( V_429 [ V_444 ] , 24 ) |
F_96 ( V_429 [ V_445 ] , 16 ) |
F_96 ( V_429 [ V_446 ] , 8 ) |
F_96 ( V_429 [ V_447 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3e4 ,
F_96 ( V_429 [ V_448 ] , 24 ) |
F_96 ( V_429 [ V_449 ] , 16 ) |
F_96 ( V_429 [ V_450 ] , 8 ) |
F_96 ( V_429 [ V_451 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3e8 ,
F_96 ( V_429 [ V_452 ] , 24 ) |
F_96 ( V_429 [ V_453 ] , 16 ) |
F_96 ( V_429 [ V_454 ] , 8 ) |
F_96 ( V_429 [ V_455 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3d8 ,
F_96 ( V_429 [ V_456 ] , 24 ) |
F_96 ( V_429 [ V_457 ] , 16 ) |
F_96 ( V_429 [ V_458 ] , 8 ) |
F_96 ( V_429 [ V_459 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3dc ,
F_96 ( V_429 [ V_460 ] , 24 ) |
F_96 ( V_429 [ V_461 ] , 16 ) |
F_96 ( V_429 [ V_462 ] , 8 ) |
F_96 ( V_429 [ V_463 ] , 0 ) ) ;
F_11 ( V_2 , 0xa3ec ,
F_96 ( V_429 [ V_464 ] , 24 ) |
F_96 ( V_429 [ V_465 ] , 16 ) |
F_96 ( V_429 [ V_466 ] , 8 ) |
F_96 ( V_429 [ V_467 ] , 0 ) ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_468 * V_469 = F_98 ( V_2 ) ;
struct V_470 * V_471 = F_99 ( V_2 ) ;
static const T_2 V_472 [ 6 ] = {
V_473 ,
V_474 ,
V_475 ,
V_280 ,
V_476 ,
V_477 ,
} ;
V_469 -> V_478 = F_1 ;
V_469 -> V_479 = F_26 ;
V_469 -> V_480 = F_27 ;
V_469 -> V_481 = F_31 ;
V_469 -> V_482 = F_35 ;
V_469 -> V_483 = F_50 ;
V_469 -> V_404 = F_56 ;
V_469 -> V_484 = F_57 ;
V_469 -> V_485 = F_58 ;
V_469 -> V_486 = F_60 ;
V_469 -> V_487 = F_62 ;
V_469 -> V_488 = F_63 ;
V_469 -> V_489 = F_67 ;
V_469 -> V_490 = F_76 ;
V_469 -> V_491 = F_77 ;
V_469 -> V_492 = F_85 ;
V_471 -> V_493 = F_79 ;
V_471 -> V_494 = F_81 ;
V_471 -> V_495 = F_86 ;
V_471 -> V_496 = F_87 ;
V_471 -> V_497 = F_88 ;
#ifdef F_100
V_471 -> V_498 = F_82 ;
#endif
V_471 -> V_499 = F_90 ;
V_471 -> V_500 = F_94 ;
V_471 -> V_501 = F_95 ;
F_75 ( V_2 ) ;
F_78 ( V_2 ) ;
memcpy ( V_2 -> V_300 , V_472 , sizeof( V_2 -> V_300 ) ) ;
}
bool F_101 ( struct V_1 * V_2 )
{
T_2 V_123 ;
switch( V_2 -> V_502 ) {
case 0x04000539 :
V_123 = F_32 ( V_2 , V_327 ) ;
V_123 &= ( ~ V_331 ) ;
V_123 |= F_28 ( 0x7f , V_331 ) ;
F_11 ( V_2 , V_327 , V_123 ) ;
F_48 ( 1 ) ;
V_123 = F_32 ( V_2 , V_327 ) ;
V_123 &= ~ V_331 ;
V_123 |= F_28 ( V_503 , V_331 ) ;
F_11 ( V_2 , V_327 , V_123 ) ;
return false ;
case 0x1300000a :
return false ;
case 0x0400000a :
case 0x04000b09 :
return true ;
case 0x04000409 :
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
return false ;
else
return true ;
default:
return true ;
}
}
void F_102 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = F_64 ( V_2 ) ;
T_2 V_504 = V_2 -> V_505 ;
T_2 V_123 , V_506 ;
if ( ! V_504 ) {
F_11 ( V_2 , V_507 ,
F_32 ( V_2 , V_507 ) &
~ ( V_508 |
V_509 ) ) ;
F_11 ( V_2 , V_510 ,
F_32 ( V_2 , V_510 ) &
~ ( V_511 |
V_512 ) ) ;
F_65 ( V_207 , V_513 , L_15 ) ;
return;
}
V_123 = F_32 ( V_2 , V_507 ) & V_514 ;
F_11 ( V_2 , V_507 ,
( V_123 | V_509 ) &
~ V_508 ) ;
if ( V_504 > 10000 )
V_504 = 10000 ;
V_506 = ( 100 * V_504 ) / 74 ;
if ( V_2 -> V_21 && F_16 ( V_2 -> V_21 ) )
V_506 = ( 100 * V_504 ) / 37 ;
F_11 ( V_2 , V_510 ,
V_511 |
V_515 |
( V_516 & ( V_506 << 2 ) ) ) ;
F_65 ( V_207 , V_513 , L_16 ,
V_504 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
V_2 -> V_502 = F_32 ( V_2 , V_517 ) ;
F_11 ( V_2 , V_517 ,
V_2 -> V_502 & ~ V_518 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = F_64 ( V_2 ) ;
T_2 V_519 ;
if ( F_105 ( ! ( V_207 -> V_520 & V_521 ) ) )
return;
V_519 = V_2 -> V_502 ;
F_65 ( V_207 , V_513 ,
L_17 , V_519 ) ;
F_65 ( V_207 , V_513 ,
L_18 ,
F_73 ( V_519 , V_522 ) ,
F_73 ( V_519 , V_523 ) ,
F_73 ( V_519 , V_524 ) ,
F_73 ( V_519 , V_525 ) ,
F_73 ( V_519 , V_526 ) ,
F_73 ( V_519 , V_527 ) ,
F_73 ( V_519 , V_528 ) ,
F_73 ( V_519 , V_529 ) ,
F_73 ( V_519 , V_530 ) ) ;
F_65 ( V_207 , V_513 , L_19 ,
F_32 ( V_2 , V_510 ) ,
F_32 ( V_2 , V_507 ) ) ;
F_65 ( V_207 , V_513 , L_20 ,
F_32 ( V_2 , V_31 ) ) ;
#define F_106 ( T_7 ) (common->cc_survey._field * 100 / common->cc_survey.cycles)
if ( V_207 -> V_531 . V_532 )
F_65 ( V_207 , V_513 ,
L_21 ,
F_106 ( V_533 ) , F_106 ( V_534 ) , F_106 ( V_535 ) ) ;
F_65 ( V_207 , V_513 , L_22 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
T_3 V_536 ;
T_2 V_123 ;
V_536 = F_73 ( V_2 -> V_502 , V_525 ) ;
if ( ( V_536 == 0xb ) || V_2 -> V_537 ) {
V_2 -> V_537 = true ;
V_123 = F_32 ( V_2 , V_399 ) ;
V_123 &= ~ V_538 ;
F_11 ( V_2 , V_399 , V_123 ) ;
}
}
