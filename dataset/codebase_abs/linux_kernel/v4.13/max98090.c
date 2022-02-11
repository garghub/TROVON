static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 ... V_8 :
case V_9 ... 0xD1 :
case V_7 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_10 * V_11 )
{
int V_12 ;
V_12 = F_4 ( V_11 -> V_13 , V_4 ,
V_14 ) ;
if ( V_12 < 0 ) {
F_5 ( V_11 -> V_15 -> V_2 ,
L_1 , V_12 ) ;
return V_12 ;
}
F_6 ( 20 ) ;
return V_12 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_15 = F_8 ( V_17 ) ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_21 * V_22 =
(struct V_21 * ) V_17 -> V_23 ;
unsigned int V_24 = ( 1 << F_10 ( V_22 -> V_25 ) ) - 1 ;
unsigned int V_26 = F_11 ( V_15 , V_22 -> V_3 ) ;
unsigned int * V_27 ;
switch ( V_22 -> V_3 ) {
case V_28 :
V_27 = & ( V_11 -> V_29 ) ;
break;
case V_30 :
V_27 = & ( V_11 -> V_31 ) ;
break;
case V_32 :
V_27 = & ( V_11 -> V_33 ) ;
break;
default:
return - V_34 ;
}
V_26 = ( V_26 >> V_22 -> V_35 ) & V_24 ;
if ( V_26 >= 1 ) {
V_26 = V_26 - 1 ;
* V_27 = V_26 ;
} else {
V_26 = * V_27 ;
}
V_19 -> V_36 . integer . V_36 [ 0 ] = V_26 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_15 = F_8 ( V_17 ) ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_21 * V_22 =
(struct V_21 * ) V_17 -> V_23 ;
unsigned int V_24 = ( 1 << F_10 ( V_22 -> V_25 ) ) - 1 ;
unsigned int V_37 = V_19 -> V_36 . integer . V_36 [ 0 ] ;
unsigned int V_26 = F_11 ( V_15 , V_22 -> V_3 ) ;
unsigned int * V_27 ;
switch ( V_22 -> V_3 ) {
case V_28 :
V_27 = & ( V_11 -> V_29 ) ;
break;
case V_30 :
V_27 = & ( V_11 -> V_31 ) ;
break;
case V_32 :
V_27 = & ( V_11 -> V_33 ) ;
break;
default:
return - V_34 ;
}
V_26 = ( V_26 >> V_22 -> V_35 ) & V_24 ;
* V_27 = V_37 ;
if ( V_26 >= 1 ) {
V_37 = V_37 + 1 ;
} else {
V_37 = V_26 ;
}
F_13 ( V_15 , V_22 -> V_3 ,
V_24 << V_22 -> V_35 ,
V_37 << V_22 -> V_35 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
struct V_16 * V_17 , int V_40 )
{
struct V_20 * V_15 = F_15 ( V_39 -> V_41 ) ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
unsigned int V_26 = F_11 ( V_15 , V_39 -> V_3 ) ;
if ( V_39 -> V_3 == V_28 )
V_26 = ( V_26 & V_42 ) >> V_43 ;
else
V_26 = ( V_26 & V_44 ) >> V_45 ;
if ( V_26 >= 1 ) {
if ( V_39 -> V_3 == V_28 ) {
V_11 -> V_29 = V_26 - 1 ;
} else {
V_11 -> V_31 = V_26 - 1 ;
}
}
switch ( V_40 ) {
case V_46 :
if ( V_39 -> V_3 == V_28 )
V_26 = V_11 -> V_29 + 1 ;
else
V_26 = V_11 -> V_31 + 1 ;
break;
case V_47 :
V_26 = 0 ;
break;
default:
return - V_34 ;
}
if ( V_39 -> V_3 == V_28 )
F_13 ( V_15 , V_39 -> V_3 , V_42 ,
V_26 << V_43 ) ;
else
F_13 ( V_15 , V_39 -> V_3 , V_44 ,
V_26 << V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_16 * V_17 , int V_40 )
{
struct V_20 * V_15 = F_15 ( V_39 -> V_41 ) ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
if ( V_40 & V_46 )
V_11 -> V_48 = true ;
return 0 ;
}
static int F_17 ( struct V_20 * V_15 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_49 * V_41 = F_18 ( V_15 ) ;
F_19 ( V_15 , V_50 ,
F_20 ( V_50 ) ) ;
if ( V_11 -> V_51 == V_52 ) {
F_19 ( V_15 , V_53 ,
F_20 ( V_53 ) ) ;
}
F_21 ( V_41 , V_54 ,
F_20 ( V_54 ) ) ;
F_22 ( V_41 , V_55 ,
F_20 ( V_55 ) ) ;
if ( V_11 -> V_51 == V_52 ) {
F_21 ( V_41 , V_56 ,
F_20 ( V_56 ) ) ;
F_22 ( V_41 , V_57 ,
F_20 ( V_57 ) ) ;
}
return 0 ;
}
static void F_23 ( struct V_20 * V_15 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
unsigned long long V_58 ;
int V_59 ;
if ( ! V_11 -> V_60 ) {
F_5 ( V_15 -> V_2 , L_2 ) ;
return;
}
if ( ! V_11 -> V_61 || ! V_11 -> V_62 ) {
F_5 ( V_15 -> V_2 , L_3 ) ;
return;
}
if ( ! ( F_11 ( V_15 , V_63 ) &
V_64 ) ) {
return;
}
for ( V_59 = 0 ; V_59 < F_20 ( V_65 ) ; V_59 ++ ) {
if ( ( V_65 [ V_59 ] == V_11 -> V_60 ) &&
( V_66 [ V_59 ] == V_11 -> V_62 ) ) {
F_24 ( V_15 -> V_2 ,
L_4 ,
V_59 + 0x8 ) ;
F_13 ( V_15 , V_67 ,
V_68 ,
( V_59 + 0x8 ) << V_69 ) ;
F_13 ( V_15 , V_67 ,
V_70 , 0 ) ;
return;
}
}
for ( V_59 = 0 ; V_59 < F_20 ( V_71 ) ; V_59 ++ ) {
if ( ( V_71 [ V_59 ] == V_11 -> V_60 ) &&
( V_72 [ V_59 ] == V_11 -> V_62 ) ) {
F_24 ( V_15 -> V_2 ,
L_5 ) ;
F_24 ( V_15 -> V_2 , L_6 ,
V_59 , V_73 [ V_59 ] , V_74 [ V_59 ] ) ;
F_13 ( V_15 , V_67 ,
V_68 , 0 ) ;
F_13 ( V_15 , V_67 ,
V_70 ,
1 << V_75 ) ;
F_25 ( V_15 , V_76 ,
( V_73 [ V_59 ] >> 8 ) & 0x7F ) ;
F_25 ( V_15 , V_77 ,
V_73 [ V_59 ] & 0xFF ) ;
F_25 ( V_15 , V_78 ,
( V_74 [ V_59 ] >> 8 ) & 0x7F ) ;
F_25 ( V_15 , V_79 ,
V_74 [ V_59 ] & 0xFF ) ;
return;
}
}
F_13 ( V_15 , V_67 ,
V_68 , 0 ) ;
F_13 ( V_15 , V_67 ,
V_70 , 0 ) ;
V_58 = 65536ULL * ( V_11 -> V_62 < 50000 ? 96ULL : 48ULL )
* ( unsigned long long int ) V_11 -> V_62 ;
F_26 ( V_58 , ( unsigned long long int ) V_11 -> V_60 ) ;
F_27 ( V_15 -> V_2 , L_7 ) ;
F_27 ( V_15 -> V_2 , L_8 , V_58 ) ;
F_25 ( V_15 , V_76 ,
( V_58 >> 8 ) & 0x7F ) ;
F_25 ( V_15 , V_77 , V_58 & 0xFF ) ;
}
static int F_28 ( struct V_80 * V_81 ,
unsigned int V_82 )
{
struct V_20 * V_15 = V_81 -> V_15 ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_83 * V_84 ;
T_1 V_85 ;
V_11 -> V_86 = V_82 ;
V_84 = & V_11 -> V_87 [ 0 ] ;
if ( V_82 != V_84 -> V_82 ) {
V_84 -> V_82 = V_82 ;
V_85 = 0 ;
switch ( V_82 & V_88 ) {
case V_89 :
F_25 ( V_15 ,
V_76 , 0x00 ) ;
F_25 ( V_15 ,
V_77 , 0x00 ) ;
F_13 ( V_15 , V_67 ,
V_70 , 0 ) ;
V_11 -> V_90 = false ;
break;
case V_91 :
if ( V_11 -> V_92 == 4 ) {
V_85 |= V_64 |
V_93 ;
} else if ( V_11 -> V_92 == 3 ) {
V_85 |= V_64 |
V_94 ;
} else {
V_85 |= V_64 |
V_95 ;
}
V_11 -> V_90 = true ;
break;
case V_96 :
case V_97 :
default:
F_5 ( V_15 -> V_2 , L_9 ) ;
return - V_34 ;
}
F_25 ( V_15 , V_63 , V_85 ) ;
V_85 = 0 ;
switch ( V_82 & V_98 ) {
case V_99 :
V_85 |= V_100 ;
break;
case V_101 :
break;
case V_102 :
V_85 |= V_103 ;
break;
case V_104 :
default:
F_5 ( V_15 -> V_2 , L_10 ) ;
return - V_34 ;
}
switch ( V_82 & V_105 ) {
case V_106 :
break;
case V_107 :
V_85 |= V_108 ;
break;
case V_109 :
V_85 |= V_110 ;
break;
case V_111 :
V_85 |= V_110 | V_108 ;
break;
default:
F_5 ( V_15 -> V_2 , L_11 ) ;
return - V_34 ;
}
if ( V_11 -> V_92 > 1 )
V_85 ^= V_110 ;
F_25 ( V_15 ,
V_112 , V_85 ) ;
}
return 0 ;
}
static int F_29 ( struct V_80 * V_81 ,
unsigned int V_113 , unsigned int V_114 , int V_115 , int V_116 )
{
struct V_20 * V_15 = V_81 -> V_15 ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_83 * V_84 ;
V_84 = & V_11 -> V_87 [ 0 ] ;
if ( V_115 < 0 || V_115 > 4 )
return - V_34 ;
V_11 -> V_92 = V_115 ;
V_11 -> V_117 = V_116 ;
if ( V_11 -> V_92 > 1 ) {
F_25 ( V_15 , V_118 ,
0 << V_119 |
1 << V_120 |
0 << V_121 ) ;
F_13 ( V_15 , V_122 ,
V_123 ,
V_123 ) ;
}
V_84 -> V_82 = 0 ;
F_28 ( V_81 , V_11 -> V_86 ) ;
return 0 ;
}
static int F_30 ( struct V_20 * V_15 ,
enum V_124 V_125 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
int V_12 ;
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
if ( F_31 ( V_11 -> V_128 ) )
break;
if ( F_32 ( V_15 ) == V_126 ) {
F_33 ( V_11 -> V_128 ) ;
} else {
V_12 = F_34 ( V_11 -> V_128 ) ;
if ( V_12 )
return V_12 ;
}
break;
case V_129 :
if ( F_32 ( V_15 ) == V_130 ) {
V_12 = F_35 ( V_11 -> V_13 ) ;
if ( V_12 != 0 ) {
F_5 ( V_15 -> V_2 ,
L_12 , V_12 ) ;
return V_12 ;
}
}
break;
case V_130 :
F_13 ( V_15 , V_131 ,
V_132 , V_132 ) ;
F_36 ( V_11 -> V_13 ) ;
break;
}
return 0 ;
}
static int F_37 ( int V_133 , int V_134 )
{
int V_135 = V_136 ;
int V_137 = V_136 ;
int V_138 = 0 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_20 ( V_139 ) ; V_59 ++ ) {
V_137 = abs ( V_133 - ( V_134 / V_139 [ V_59 ] ) ) ;
if ( V_137 < V_135 ) {
V_135 = V_137 ;
V_138 = V_59 ;
}
}
return V_138 ;
}
static int F_38 ( int V_134 )
{
int V_140 ;
int V_141 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_20 ( V_142 ) ; V_59 ++ ) {
if ( V_134 == V_142 [ V_59 ] . V_134 )
return V_59 ;
if ( V_134 < V_142 [ V_59 ] . V_134 ) {
if ( V_59 == 0 )
return V_59 ;
V_140 = V_134 - V_142 [ V_59 - 1 ] . V_134 ;
V_141 = V_142 [ V_59 ] . V_134 - V_134 ;
if ( V_140 < V_141 )
return V_59 - 1 ;
else
return V_59 ;
}
}
return - V_34 ;
}
static int F_39 ( struct V_10 * V_11 ,
int V_143 , int V_134 , int V_144 )
{
int V_145 ;
int V_146 ;
int V_147 ;
int V_148 ;
int V_59 ;
V_146 = F_38 ( V_134 ) ;
if ( V_146 < 0 )
return V_146 ;
V_145 = F_37 ( V_143 , V_134 ) ;
for ( V_59 = 0 ; V_59 < F_20 ( V_149 ) - 1 ; V_59 ++ ) {
if ( V_144 <= ( V_149 [ V_59 ] + V_149 [ V_59 + 1 ] ) / 2 )
break;
}
V_147 = V_142 [ V_146 ] . V_150 [ V_145 ] . V_151 ;
V_148 = V_142 [ V_146 ] . V_150 [ V_145 ] . V_152 [ V_59 ] ;
F_40 ( V_11 -> V_13 , V_153 ,
V_154 ,
V_145 << V_155 ) ;
F_40 ( V_11 -> V_13 , V_156 ,
V_157 | V_158 ,
V_148 << V_159 |
V_147 << V_160 ) ;
return 0 ;
}
static int F_41 ( struct V_161 * V_162 ,
struct V_163 * V_164 ,
struct V_80 * V_87 )
{
struct V_20 * V_15 = V_87 -> V_15 ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_83 * V_84 ;
V_84 = & V_11 -> V_87 [ 0 ] ;
V_11 -> V_61 = F_42 ( V_164 ) ;
if ( F_43 ( V_164 ) == 1 )
V_11 -> V_61 *= 2 ;
V_11 -> V_62 = F_44 ( V_164 ) ;
switch ( F_45 ( V_164 ) ) {
case 16 :
F_13 ( V_15 , V_112 ,
V_165 , 0 ) ;
break;
default:
return - V_34 ;
}
if ( V_11 -> V_90 )
F_23 ( V_15 ) ;
V_84 -> V_166 = V_11 -> V_62 ;
if ( V_11 -> V_62 < 24000 )
F_13 ( V_15 , V_167 ,
V_168 , 0 ) ;
else
F_13 ( V_15 , V_167 ,
V_168 , V_168 ) ;
if ( V_11 -> V_62 < 50000 )
F_13 ( V_15 , V_167 ,
V_169 , 0 ) ;
else
F_13 ( V_15 , V_167 ,
V_169 , V_169 ) ;
F_39 ( V_11 , V_11 -> V_147 , V_11 -> V_134 ,
V_11 -> V_62 ) ;
return 0 ;
}
static int F_46 ( struct V_80 * V_87 ,
int V_170 , unsigned int V_151 , int V_171 )
{
struct V_20 * V_15 = V_87 -> V_15 ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
if ( V_151 == V_11 -> V_60 )
return 0 ;
if ( ! F_31 ( V_11 -> V_128 ) ) {
V_151 = F_47 ( V_11 -> V_128 , V_151 ) ;
F_48 ( V_11 -> V_128 , V_151 ) ;
}
if ( ( V_151 >= 10000000 ) && ( V_151 <= 20000000 ) ) {
F_25 ( V_15 , V_172 ,
V_173 ) ;
V_11 -> V_134 = V_151 ;
} else if ( ( V_151 > 20000000 ) && ( V_151 <= 40000000 ) ) {
F_25 ( V_15 , V_172 ,
V_174 ) ;
V_11 -> V_134 = V_151 >> 1 ;
} else if ( ( V_151 > 40000000 ) && ( V_151 <= 60000000 ) ) {
F_25 ( V_15 , V_172 ,
V_175 ) ;
V_11 -> V_134 = V_151 >> 2 ;
} else {
F_5 ( V_15 -> V_2 , L_13 ) ;
return - V_34 ;
}
V_11 -> V_60 = V_151 ;
return 0 ;
}
static int F_49 ( struct V_80 * V_81 , int V_176 )
{
struct V_20 * V_15 = V_81 -> V_15 ;
int V_85 ;
V_85 = V_176 ? V_177 : 0 ;
F_13 ( V_15 , V_178 ,
V_177 , V_85 ) ;
return 0 ;
}
static int F_50 ( struct V_161 * V_162 , int V_179 ,
struct V_80 * V_87 )
{
struct V_20 * V_15 = V_87 -> V_15 ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
switch ( V_179 ) {
case V_180 :
case V_181 :
case V_182 :
if ( ! V_11 -> V_90 && V_87 -> V_183 == 1 )
F_51 ( V_184 ,
& V_11 -> V_185 ,
F_52 ( 10 ) ) ;
break;
case V_186 :
case V_187 :
case V_188 :
if ( ! V_11 -> V_90 && V_87 -> V_183 == 1 )
F_53 ( & V_11 -> V_189 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_54 ( struct V_190 * V_191 )
{
struct V_10 * V_11 =
F_55 ( V_191 , struct V_10 ,
V_185 . V_191 ) ;
struct V_20 * V_15 = V_11 -> V_15 ;
unsigned int V_192 , V_24 ;
F_56 ( V_11 -> V_13 , V_5 , & V_192 ) ;
F_56 ( V_11 -> V_13 , V_8 , & V_24 ) ;
V_192 &= V_24 ;
if ( V_192 & V_193 )
F_51 ( V_184 ,
& V_11 -> V_194 ,
F_52 ( 100 ) ) ;
F_13 ( V_15 , V_8 ,
V_195 ,
1 << V_196 ) ;
}
static void F_57 ( struct V_190 * V_191 )
{
struct V_10 * V_11 =
F_55 ( V_191 , struct V_10 , V_189 ) ;
struct V_20 * V_15 = V_11 -> V_15 ;
F_58 ( & V_11 -> V_185 ) ;
F_13 ( V_15 , V_8 ,
V_195 , 0 ) ;
}
static void F_59 ( struct V_190 * V_191 )
{
struct V_10 * V_11 =
F_55 ( V_191 , struct V_10 , V_197 ) ;
struct V_20 * V_15 = V_11 -> V_15 ;
if ( ! F_60 ( V_15 ) )
return;
F_27 ( V_15 -> V_2 , L_14 ) ;
F_13 ( V_15 , V_198 ,
V_199 , 0 ) ;
F_6 ( 10 ) ;
F_13 ( V_15 , V_198 ,
V_199 , V_199 ) ;
F_6 ( 10 ) ;
}
static void F_61 ( struct V_190 * V_191 )
{
struct V_10 * V_11 = F_55 ( V_191 ,
struct V_10 ,
V_194 . V_191 ) ;
struct V_20 * V_15 = V_11 -> V_15 ;
int V_192 = 0 ;
int V_3 ;
if ( V_11 -> V_200 == V_201 ) {
F_13 ( V_15 , V_131 ,
V_132 , 0 ) ;
F_6 ( 50 ) ;
V_3 = F_11 ( V_15 , V_6 ) ;
F_13 ( V_15 , V_131 ,
V_132 , V_132 ) ;
} else {
V_3 = F_11 ( V_15 , V_6 ) ;
}
V_3 = F_11 ( V_15 , V_6 ) ;
switch ( V_3 & ( V_202 | V_203 ) ) {
case V_202 | V_203 :
F_24 ( V_15 -> V_2 , L_15 ) ;
V_11 -> V_200 = V_201 ;
V_192 |= 0 ;
break;
case 0 :
if ( V_11 -> V_200 ==
V_204 ) {
F_24 ( V_15 -> V_2 ,
L_16 ) ;
V_192 |= V_205 ;
V_192 |= V_206 ;
break;
}
F_24 ( V_15 -> V_2 , L_17 ) ;
V_11 -> V_200 = V_207 ;
V_192 |= V_208 ;
break;
case V_203 :
F_24 ( V_15 -> V_2 , L_18 ) ;
V_11 -> V_200 = V_204 ;
V_192 |= V_205 ;
break;
default:
F_24 ( V_15 -> V_2 , L_19 ) ;
break;
}
F_62 ( V_11 -> V_209 , V_192 ,
V_205 | V_206 ) ;
}
static T_2 F_63 ( int V_210 , void * V_211 )
{
struct V_10 * V_11 = V_211 ;
struct V_20 * V_15 = V_11 -> V_15 ;
int V_12 ;
unsigned int V_24 ;
unsigned int V_183 ;
if ( V_15 == NULL )
return V_212 ;
F_24 ( V_15 -> V_2 , L_20 ) ;
V_12 = F_56 ( V_11 -> V_13 , V_8 , & V_24 ) ;
if ( V_12 != 0 ) {
F_5 ( V_15 -> V_2 ,
L_21 ,
V_12 ) ;
return V_212 ;
}
V_12 = F_56 ( V_11 -> V_13 , V_5 , & V_183 ) ;
if ( V_12 != 0 ) {
F_5 ( V_15 -> V_2 ,
L_22 ,
V_12 ) ;
return V_212 ;
}
F_24 ( V_15 -> V_2 , L_23 ,
V_183 , V_24 , V_183 & V_24 ) ;
V_183 &= V_24 ;
if ( ! V_183 )
return V_212 ;
if ( V_183 & V_213 )
F_5 ( V_15 -> V_2 , L_24 ) ;
if ( V_183 & V_214 )
F_24 ( V_15 -> V_2 , L_25 ) ;
if ( V_183 & V_215 ) {
F_24 ( V_15 -> V_2 , L_26 ) ;
F_53 ( & V_11 -> V_197 ) ;
}
if ( V_183 & V_193 ) {
F_24 ( V_15 -> V_2 , L_27 ) ;
F_64 ( V_15 -> V_2 , 100 ) ;
F_51 ( V_184 ,
& V_11 -> V_194 ,
F_52 ( 100 ) ) ;
}
if ( V_183 & V_216 )
F_24 ( V_15 -> V_2 , L_28 ) ;
if ( V_183 & V_217 )
F_5 ( V_15 -> V_2 , L_29 ) ;
return V_218 ;
}
int F_65 ( struct V_20 * V_15 ,
struct V_219 * V_209 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
F_24 ( V_15 -> V_2 , L_30 ) ;
V_11 -> V_209 = V_209 ;
if ( V_209 ) {
F_13 ( V_15 , V_8 ,
V_220 ,
1 << V_221 ) ;
} else {
F_13 ( V_15 , V_8 ,
V_220 ,
0 ) ;
}
F_62 ( V_11 -> V_209 , 0 ,
V_205 | V_206 ) ;
F_51 ( V_184 ,
& V_11 -> V_194 ,
F_52 ( 100 ) ) ;
return 0 ;
}
static int F_66 ( struct V_20 * V_15 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
struct V_83 * V_84 ;
enum V_222 V_51 ;
int V_12 = 0 ;
int V_223 ;
unsigned int V_224 ;
F_24 ( V_15 -> V_2 , L_31 ) ;
V_11 -> V_128 = F_67 ( V_15 -> V_2 , L_32 ) ;
if ( F_68 ( V_11 -> V_128 ) == - V_225 )
return - V_225 ;
V_11 -> V_15 = V_15 ;
F_3 ( V_11 ) ;
V_11 -> V_60 = ( unsigned ) - 1 ;
V_11 -> V_134 = ( unsigned ) - 1 ;
V_11 -> V_90 = false ;
V_84 = & V_11 -> V_87 [ 0 ] ;
V_84 -> V_166 = ( unsigned ) - 1 ;
V_84 -> V_82 = ( unsigned ) - 1 ;
V_11 -> V_226 = 0 ;
V_11 -> V_29 = 0 ;
V_11 -> V_31 = 0 ;
V_12 = F_11 ( V_15 , V_7 ) ;
if ( V_12 < 0 ) {
F_5 ( V_15 -> V_2 , L_33 ,
V_12 ) ;
goto V_227;
}
if ( ( V_12 >= V_228 ) && ( V_12 <= V_228 + 0x0f ) ) {
V_51 = V_229 ;
F_27 ( V_15 -> V_2 , L_34 , V_12 ) ;
} else if ( ( V_12 >= V_230 ) && ( V_12 <= V_230 + 0x0f ) ) {
V_51 = V_52 ;
F_27 ( V_15 -> V_2 , L_35 , V_12 ) ;
} else {
V_51 = V_229 ;
F_5 ( V_15 -> V_2 , L_36 , V_12 ) ;
}
if ( V_11 -> V_51 != V_51 ) {
F_69 ( V_15 -> V_2 , L_37 ) ;
V_11 -> V_51 = V_51 ;
}
V_11 -> V_200 = V_201 ;
F_70 ( & V_11 -> V_194 , F_61 ) ;
F_70 ( & V_11 -> V_185 ,
F_54 ) ;
F_71 ( & V_11 -> V_189 ,
F_57 ) ;
F_71 ( & V_11 -> V_197 , F_59 ) ;
F_25 ( V_15 , V_131 ,
V_231 | V_232 ) ;
F_11 ( V_15 , V_5 ) ;
F_13 ( V_15 , V_233 ,
V_234 ,
1 << V_235 ) ;
F_13 ( V_15 , V_233 ,
V_236 ,
0 << V_237 ) ;
F_13 ( V_15 , V_238 ,
V_239 ,
1 << V_240 ) ;
F_25 ( V_15 , V_241 ,
V_242 ) ;
V_223 = F_72 ( V_15 -> V_2 , L_38 , & V_224 ) ;
if ( V_223 ) {
V_224 = V_243 ;
F_27 ( V_15 -> V_2 , L_39 ) ;
} else if ( V_224 > V_243 ) {
F_5 ( V_15 -> V_2 , L_40 , V_224 ) ;
V_224 = V_243 ;
}
F_13 ( V_15 , V_244 ,
V_245 , V_224 ) ;
F_17 ( V_15 ) ;
V_227:
return V_12 ;
}
static int F_73 ( struct V_20 * V_15 )
{
struct V_10 * V_11 = F_9 ( V_15 ) ;
F_58 ( & V_11 -> V_194 ) ;
F_58 ( & V_11 -> V_185 ) ;
F_74 ( & V_11 -> V_189 ) ;
F_74 ( & V_11 -> V_197 ) ;
V_11 -> V_15 = NULL ;
return 0 ;
}
static void F_75 ( struct V_49 * V_41 ,
enum V_246 V_40 , int V_247 )
{
struct V_20 * V_15 = F_15 ( V_41 ) ;
struct V_10 * V_11 = F_9 ( V_15 ) ;
if ( V_11 -> V_48 ) {
F_13 ( V_15 , V_198 ,
V_199 , 0 ) ;
F_6 ( 40 ) ;
F_13 ( V_15 , V_198 ,
V_199 , V_199 ) ;
V_11 -> V_48 = false ;
}
}
static int F_76 ( struct V_248 * V_249 ,
const struct V_250 * V_251 )
{
struct V_10 * V_11 ;
const struct V_252 * V_253 ;
T_3 V_254 = 0 ;
int V_12 ;
F_77 ( L_41 ) ;
V_11 = F_78 ( & V_249 -> V_2 , sizeof( struct V_10 ) ,
V_255 ) ;
if ( V_11 == NULL )
return - V_256 ;
if ( F_79 ( & V_249 -> V_2 ) ) {
V_253 = F_80 ( V_249 -> V_2 . V_257 -> V_258 ,
& V_249 -> V_2 ) ;
if ( ! V_253 ) {
F_5 ( & V_249 -> V_2 , L_42 ) ;
return - V_34 ;
}
V_254 = V_253 -> V_254 ;
} else if ( V_251 ) {
V_254 = V_251 -> V_254 ;
}
V_11 -> V_51 = V_254 ;
F_81 ( V_249 , V_11 ) ;
V_11 -> V_259 = V_249 -> V_2 . V_260 ;
V_12 = F_82 ( V_249 -> V_2 . V_261 , L_43 ,
& V_11 -> V_147 ) ;
if ( V_12 < 0 )
V_11 -> V_147 = V_262 ;
V_11 -> V_13 = F_83 ( V_249 , & V_263 ) ;
if ( F_31 ( V_11 -> V_13 ) ) {
V_12 = F_68 ( V_11 -> V_13 ) ;
F_5 ( & V_249 -> V_2 , L_44 , V_12 ) ;
goto V_264;
}
V_12 = F_84 ( & V_249 -> V_2 , V_249 -> V_210 , NULL ,
F_63 , V_265 | V_266 ,
L_45 , V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_249 -> V_2 , L_46 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_85 ( & V_249 -> V_2 ,
& V_267 , V_268 ,
F_20 ( V_268 ) ) ;
V_264:
return V_12 ;
}
static void F_86 ( struct V_248 * V_249 )
{
struct V_10 * V_11 = F_87 ( & V_249 -> V_2 ) ;
F_4 ( V_11 -> V_13 ,
V_269 , V_270 ) ;
F_4 ( V_11 -> V_13 ,
V_198 , 0x00 ) ;
F_6 ( 40 ) ;
}
static int F_88 ( struct V_248 * V_271 )
{
F_86 ( V_271 ) ;
F_89 ( & V_271 -> V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_87 ( V_2 ) ;
F_91 ( V_11 -> V_13 , false ) ;
F_3 ( V_11 ) ;
F_35 ( V_11 -> V_13 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_87 ( V_2 ) ;
F_91 ( V_11 -> V_13 , true ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_87 ( V_2 ) ;
unsigned int V_192 ;
F_36 ( V_11 -> V_13 ) ;
F_3 ( V_11 ) ;
F_56 ( V_11 -> V_13 , V_5 , & V_192 ) ;
F_35 ( V_11 -> V_13 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
return 0 ;
}
