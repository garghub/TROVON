static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 , V_5 , V_2 -> V_6 [ 0 ] , V_7 | V_3 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_1 V_8 ;
F_3 ( V_2 , V_5 , V_2 -> V_6 [ 0 ] , & V_8 ) ;
if ( ! ( V_8 & V_7 ) )
return 0 ;
F_4 ( 100 , 200 ) ;
}
return - V_9 ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_10 ,
struct V_11 * V_12 )
{
if ( F_6 ( V_2 ) ) {
T_3 V_13 = 0 ;
if ( V_12 -> V_14 ) {
V_13 = ( ( V_12 -> V_15 & V_16 ) <<
V_17 ) | V_12 -> V_14 ;
if ( V_2 -> V_18 >= 3 )
V_13 |= V_19 | V_10 << V_20 ;
else
V_13 |= V_21 ;
}
F_7 ( V_2 , V_22 , V_23 , V_13 ) ;
F_8 ( V_2 , V_22 , V_24 , V_10 |
V_25 | V_26 ) ;
} else if ( F_9 ( V_2 ) ) {
T_2 V_13 = 0 ;
if ( V_12 -> V_14 )
V_13 = ( ( V_12 -> V_15 & V_27 ) <<
V_28 ) | V_12 -> V_14 | V_29 ;
F_8 ( V_2 , V_22 , V_30 , V_13 ) ;
F_8 ( V_2 , V_22 , V_31 , V_10 |
V_25 | V_26 ) ;
} else {
F_8 ( V_2 , V_5 , V_2 -> V_6 [ 1 ] , V_10 ) ;
F_7 ( V_2 , V_5 , V_2 -> V_6 [ 2 ] ,
( V_12 -> V_15 << V_32 ) | V_12 -> V_14 ) ;
F_1 ( V_2 , V_33 ) ;
}
F_10 ( V_2 -> V_34 -> V_2 , L_1 ,
V_10 , V_12 -> V_14 , V_12 -> V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_2 V_10 ,
struct V_11 * V_12 )
{
if ( F_6 ( V_2 ) ) {
T_3 V_13 = 0 ;
F_8 ( V_2 , V_22 , V_24 , V_10 |
V_35 | V_26 ) ;
F_12 ( V_2 , V_22 , V_23 , & V_13 ) ;
if ( V_2 -> V_18 >= 3 )
V_12 -> V_36 = ! ! ( V_13 & V_19 ) ;
else
V_12 -> V_36 = ! ! ( V_13 & V_21 ) ;
V_12 -> V_14 = V_13 & V_37 ;
V_12 -> V_15 = ( V_13 >> V_17 ) & V_16 ;
} else if ( F_9 ( V_2 ) ) {
T_2 V_13 = 0 ;
F_8 ( V_2 , V_22 , V_31 , V_10 |
V_25 | V_26 ) ;
F_13 ( V_2 , V_22 , V_30 , & V_13 ) ;
V_12 -> V_36 = ! ! ( V_13 & V_29 ) ;
V_12 -> V_14 = V_13 & V_37 ;
V_12 -> V_15 = ( V_13 >> V_28 ) & V_27 ;
} else {
T_3 V_13 = 0 ;
F_8 ( V_2 , V_5 , V_2 -> V_6 [ 1 ] , V_10 ) ;
F_1 ( V_2 , V_38 ) ;
F_12 ( V_2 , V_5 , V_2 -> V_6 [ 2 ] , & V_13 ) ;
V_12 -> V_14 = V_13 & V_39 ;
V_12 -> V_15 = ( V_13 >> V_32 ) & V_39 ;
V_12 -> V_36 = true ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_40 )
{
T_1 V_41 ;
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
if ( V_40 )
V_41 |= V_44 ;
else
V_41 &= ~ V_44 ;
F_2 ( V_2 , V_42 , V_43 , V_41 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_40 )
{
T_1 V_41 , V_45 , V_46 , V_47 = 0 , V_48 ;
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
F_3 ( V_2 , V_22 , V_49 , & V_45 ) ;
F_3 ( V_2 , V_22 , V_50 , & V_46 ) ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
F_3 ( V_2 , V_22 , V_51 , & V_47 ) ;
F_3 ( V_2 , V_22 , V_52 , & V_48 ) ;
} else if ( F_16 ( V_2 ) ) {
F_3 ( V_2 , V_22 , V_53 , & V_47 ) ;
F_3 ( V_2 , V_22 , V_54 , & V_48 ) ;
} else {
F_3 ( V_2 , V_22 , V_55 , & V_47 ) ;
F_3 ( V_2 , V_22 , V_56 , & V_48 ) ;
}
V_41 &= ~ V_57 ;
if ( V_40 ) {
V_45 |= V_58 | V_59 | V_60 ;
V_46 |= V_61 | V_62 ;
V_47 &= ~ V_63 ;
V_47 |= V_64 << V_65 ;
V_48 |= V_66 ;
if ( F_6 ( V_2 ) )
V_45 &= ~ V_67 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_46 |= V_68 ;
} else {
V_45 &= ~ ( V_58 | V_59 | V_60 ) ;
V_46 &= ~ ( V_61 | V_62 ) ;
V_47 &= ~ V_63 ;
V_48 &= ~ V_66 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_47 |= V_69 << V_65 ;
else
V_47 |= V_70 << V_65 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_46 &= ~ V_68 ;
}
if ( ! F_6 ( V_2 ) && ! F_9 ( V_2 ) )
V_48 &= ~ V_71 ;
F_2 ( V_2 , V_22 , V_49 , V_45 ) ;
F_2 ( V_2 , V_22 , V_50 , V_46 ) ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
if ( F_6 ( V_2 ) && V_40 )
F_2 ( V_2 , V_22 , V_72 ,
V_73 ) ;
else
F_2 ( V_2 , V_22 , V_72 , 0 ) ;
F_2 ( V_2 , V_22 , V_51 , V_47 ) ;
F_2 ( V_2 , V_22 , V_52 , V_48 ) ;
} else if ( F_16 ( V_2 ) ) {
F_8 ( V_2 , V_22 , V_74 , 0 ) ;
F_2 ( V_2 , V_22 , V_53 , V_47 ) ;
F_2 ( V_2 , V_22 , V_54 , V_48 ) ;
} else {
F_8 ( V_2 , V_22 , V_72 , 0 ) ;
F_2 ( V_2 , V_22 , V_55 , V_47 ) ;
F_2 ( V_2 , V_22 , V_56 , V_48 ) ;
}
F_2 ( V_2 , V_42 , V_43 , V_41 ) ;
}
static int F_17 ( struct V_1 * V_2 , bool V_40 , bool V_75 )
{
T_3 V_76 = 0 ;
T_2 V_77 = V_78 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
return - V_79 ;
if ( V_40 ) {
V_76 = V_2 -> V_80 ;
V_77 = V_81 ;
if ( V_75 )
V_76 |= V_82 ;
}
F_7 ( V_2 , V_83 , V_2 -> V_84 , V_76 ) ;
return F_8 ( V_2 , V_83 , V_2 -> V_85 , V_77 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_86 )
{
unsigned int V_4 ;
F_2 ( V_2 , V_42 , V_87 ,
V_88 | V_89 | V_86 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_1 V_90 ;
F_3 ( V_2 , V_42 , V_87 ,
& V_90 ) ;
if ( ! ( V_90 & V_88 ) )
goto V_91;
F_19 ( 1 ) ;
}
return - V_92 ;
V_91:
F_2 ( V_2 , V_42 , V_87 , V_89 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_93 )
{
F_2 ( V_2 , V_42 , V_94 , V_93 ) ;
return F_18 ( V_2 , V_95 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_10 )
{
F_8 ( V_2 , V_42 , V_96 , V_10 ) ;
return F_18 ( V_2 , V_97 ) ;
}
static void F_22 ( struct V_98 * V_34 , int V_99 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
unsigned int V_4 ;
T_2 V_100 ;
F_24 (dev, i) {
F_13 ( V_2 , V_101 , F_25 ( V_4 ) , & V_100 ) ;
V_100 |= F_26 ( V_99 ) ;
F_8 ( V_2 , V_101 , F_25 ( V_4 ) , V_100 ) ;
}
}
static int F_27 ( struct V_98 * V_34 , int V_93 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
unsigned int V_99 = V_2 -> V_99 ;
T_2 V_100 ;
F_2 ( V_2 , V_42 , F_28 ( V_93 ) , 0 ) ;
F_13 ( V_2 , V_101 , F_25 ( V_93 ) , & V_100 ) ;
V_100 &= ~ 0x1ff ;
V_100 |= F_26 ( V_93 ) ;
V_100 |= V_2 -> V_104 [ V_93 ] . V_105 ;
F_8 ( V_2 , V_101 , F_25 ( V_93 ) , V_100 ) ;
F_22 ( V_34 , V_99 ) ;
return 0 ;
}
static void F_29 ( struct V_98 * V_34 , int V_93 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
T_1 V_106 ;
F_3 ( V_2 , V_42 , F_28 ( V_93 ) , & V_106 ) ;
V_106 |= V_107 | V_108 ;
F_2 ( V_2 , V_42 , F_28 ( V_93 ) , V_106 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_99 = V_2 -> V_99 ;
T_1 V_109 ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_99 == V_110 )
V_99 = V_111 ;
V_109 = V_112 |
V_113 |
V_114 ;
F_2 ( V_2 , V_42 , F_28 ( V_99 ) , V_109 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_115 ;
F_3 ( V_2 , V_116 , V_117 , & V_115 ) ;
V_115 &= ~ ( V_118 | V_119 ) ;
F_2 ( V_2 , V_116 , V_117 , V_115 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_11 V_120 = { 0 } ;
int V_4 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
for ( V_4 = 1 ; V_4 < V_2 -> V_121 ; V_4 ++ )
F_5 ( V_2 , V_4 , & V_120 ) ;
} else {
F_1 ( V_2 , V_122 ) ;
}
F_15 ( V_2 , false ) ;
F_24 (dev, i)
F_8 ( V_2 , V_22 ,
F_33 ( V_4 ) , 1 ) ;
if ( ! F_6 ( V_2 ) && ! F_9 ( V_2 ) )
F_17 ( V_2 , V_2 -> V_123 , false ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_124 = V_2 -> V_125 ;
if ( V_124 < 0 )
return;
F_35 ( V_124 , 0 ) ;
F_36 ( 50 ) ;
F_35 ( V_124 , 1 ) ;
F_36 ( 20 ) ;
V_2 -> V_126 = 0xff ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_41 ;
F_34 ( V_2 ) ;
if ( F_38 ( V_2 ) ) {
F_2 ( V_2 , V_42 , V_127 , 0x83 ) ;
F_2 ( V_2 , V_42 , V_127 , 0x00 ) ;
}
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
if ( ! ( V_41 & V_44 ) ) {
V_41 &= ~ V_57 ;
V_41 |= V_44 ;
F_2 ( V_2 , V_42 , V_43 , V_41 ) ;
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
if ( ! ( V_41 & V_44 ) ) {
F_39 ( V_2 -> V_2 , L_2 ) ;
return - V_79 ;
}
}
F_31 ( V_2 ) ;
return F_18 ( V_2 , V_128 ) ;
}
static int F_40 ( struct V_98 * V_34 , int V_129 , int V_106 )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
T_2 V_131 = 0 ;
int V_132 ;
if ( V_130 -> V_133 -> V_134 )
V_132 = V_130 -> V_133 -> V_134 ( V_130 , V_129 , V_106 , & V_131 ) ;
else
V_132 = F_13 ( V_130 , F_41 ( V_129 ) ,
V_106 * 2 , & V_131 ) ;
return V_132 ? V_132 : V_131 ;
}
static int F_42 ( struct V_98 * V_34 , int V_129 , int V_106 , T_2 V_135 )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
if ( V_130 -> V_133 -> V_136 )
return V_130 -> V_133 -> V_136 ( V_130 , V_129 , V_106 , V_135 ) ;
return F_8 ( V_130 , F_41 ( V_129 ) , V_106 * 2 , V_135 ) ;
}
static int F_43 ( struct V_1 * V_130 )
{
V_130 -> V_123 = false ;
memset ( V_130 -> V_137 , 0 , sizeof( * V_130 -> V_137 ) * V_130 -> V_121 ) ;
memset ( V_130 -> V_104 , 0 , sizeof( * V_130 -> V_104 ) * V_130 -> V_138 ) ;
return F_37 ( V_130 ) ;
}
static int F_44 ( struct V_1 * V_130 )
{
F_14 ( V_130 , 0 ) ;
F_32 ( V_130 ) ;
F_14 ( V_130 , 1 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_130 )
{
T_1 V_115 ;
F_3 ( V_130 , V_116 , V_117 , & V_115 ) ;
F_2 ( V_130 , V_116 , V_117 , V_115 | V_118 ) ;
F_19 ( 1 ) ;
F_2 ( V_130 , V_116 , V_117 , V_115 & ~ V_118 ) ;
F_19 ( 1 ) ;
}
static const struct V_139 * F_46 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_140 ;
else if ( F_16 ( V_2 ) )
return V_141 ;
else
return V_142 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_143 ;
else if ( F_16 ( V_2 ) )
return V_144 ;
else
return V_145 ;
}
static void F_48 ( struct V_98 * V_34 , int V_93 , T_4 * V_146 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
const struct V_139 * V_147 = F_46 ( V_2 ) ;
unsigned int V_148 = F_47 ( V_2 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_148 ; V_4 ++ )
memcpy ( V_146 + V_4 * V_149 ,
V_147 [ V_4 ] . V_150 , V_149 ) ;
}
static void F_49 ( struct V_98 * V_34 , int V_93 ,
T_5 * V_146 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
const struct V_139 * V_147 = F_46 ( V_2 ) ;
unsigned int V_148 = F_47 ( V_2 ) ;
const struct V_139 * V_151 ;
unsigned int V_4 ;
T_6 V_135 = 0 ;
if ( F_9 ( V_2 ) && V_93 == 5 )
V_93 = 8 ;
F_50 ( & V_2 -> V_152 ) ;
for ( V_4 = 0 ; V_4 < V_148 ; V_4 ++ ) {
V_151 = & V_147 [ V_4 ] ;
if ( V_151 -> V_153 == 8 ) {
F_51 ( V_2 , F_52 ( V_93 ) , V_151 -> V_154 , & V_135 ) ;
} else {
T_3 V_155 ;
F_12 ( V_2 , F_52 ( V_93 ) , V_151 -> V_154 ,
& V_155 ) ;
V_135 = V_155 ;
}
V_146 [ V_4 ] = ( T_6 ) V_135 ;
}
F_53 ( & V_2 -> V_152 ) ;
}
static int F_54 ( struct V_98 * V_34 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
return F_47 ( V_2 ) ;
}
static int F_55 ( struct V_98 * V_34 , T_1 * V_129 )
{
return 0 ;
}
static int F_56 ( struct V_98 * V_34 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
unsigned int V_93 ;
int V_132 ;
V_132 = F_43 ( V_2 ) ;
if ( V_132 ) {
F_39 ( V_34 -> V_2 , L_3 ) ;
return V_132 ;
}
F_45 ( V_2 ) ;
V_132 = F_44 ( V_2 ) ;
if ( V_132 )
F_39 ( V_34 -> V_2 , L_4 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_138 ; V_93 ++ ) {
if ( F_26 ( V_93 ) & V_34 -> V_156 )
F_27 ( V_34 , V_93 , NULL ) ;
else if ( F_57 ( V_34 , V_93 ) )
F_30 ( V_2 ) ;
else
F_29 ( V_34 , V_93 , NULL ) ;
}
return V_132 ;
}
static void F_58 ( struct V_98 * V_34 , int V_93 ,
struct V_102 * V_157 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
T_1 V_158 = 0 , V_106 = 0 , V_159 ;
if ( ! F_59 ( V_157 ) )
return;
if ( V_93 == V_2 -> V_99 ) {
V_159 = V_160 ;
V_106 = V_161 ;
} else {
V_159 = F_60 ( V_93 ) ;
V_106 = V_162 ;
}
if ( V_157 -> V_163 )
V_106 |= V_164 ;
if ( V_157 -> V_165 == V_166 )
V_106 |= V_167 ;
switch ( V_157 -> V_168 ) {
case 2000 :
V_106 |= V_169 ;
case V_170 :
V_106 |= V_171 ;
break;
case V_172 :
V_106 |= V_173 ;
break;
case V_174 :
V_106 |= V_175 ;
break;
default:
F_39 ( V_34 -> V_2 , L_5 , V_157 -> V_168 ) ;
return;
}
if ( F_61 ( V_2 ) && V_93 == V_2 -> V_99 )
V_106 |= V_176 | V_177 ;
if ( V_157 -> V_178 ) {
if ( V_157 -> V_179 )
V_106 |= V_177 ;
V_106 |= V_176 ;
}
F_2 ( V_2 , V_42 , V_159 , V_106 ) ;
if ( F_62 ( V_2 ) && F_63 ( V_157 ) ) {
if ( V_93 == 8 )
V_159 = V_180 ;
else
V_159 = F_64 ( V_93 ) ;
F_3 ( V_2 , V_42 , V_159 , & V_158 ) ;
V_158 &= ~ ( V_181 | V_182 |
V_183 ) ;
if ( V_157 -> V_184 == V_185 )
V_158 |= V_182 ;
if ( V_157 -> V_184 == V_186 )
V_158 |= V_182 | V_181 ;
V_158 |= V_183 ;
F_2 ( V_2 , V_42 , V_159 , V_158 ) ;
F_65 ( V_34 -> V_2 , L_6 , V_93 ,
F_66 ( V_157 -> V_184 ) ) ;
}
if ( F_6 ( V_2 ) ) {
F_3 ( V_2 , V_42 , V_160 ,
& V_106 ) ;
if ( ! ( V_106 & V_187 ) ) {
F_2 ( V_2 , V_42 , V_160 ,
V_106 | V_187 ) ;
F_3 ( V_2 , V_42 , V_160 ,
& V_106 ) ;
if ( ! ( V_106 & V_187 ) ) {
F_39 ( V_34 -> V_2 ,
L_7 ) ;
return;
}
}
} else if ( F_61 ( V_2 ) ) {
if ( V_93 != V_2 -> V_99 ) {
T_1 V_188 = F_60 ( V_2 -> V_99 ) ;
T_1 V_189 ;
F_3 ( V_2 , V_42 , V_188 , & V_189 ) ;
V_189 |= V_190 |
V_191 |
V_192 |
V_162 |
V_193 ;
F_2 ( V_2 , V_42 , V_188 , V_189 ) ;
}
}
}
static int F_67 ( struct V_98 * V_34 , int V_93 ,
bool V_194 )
{
return 0 ;
}
static int F_68 ( struct V_98 * V_34 , int V_93 ,
const struct V_195 * V_12 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_12 -> V_198 == 0 )
return - V_199 ;
if ( V_12 -> V_200 > V_2 -> V_121 )
return - V_201 ;
F_15 ( V_2 , true ) ;
return 0 ;
}
static void F_69 ( struct V_98 * V_34 , int V_93 ,
const struct V_195 * V_12 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
bool V_202 = V_12 -> V_203 & V_204 ;
bool V_205 = V_12 -> V_203 & V_206 ;
unsigned int V_99 = V_2 -> V_99 ;
struct V_11 * V_120 ;
T_2 V_10 ;
for ( V_10 = V_12 -> V_198 ; V_10 <= V_12 -> V_200 ; ++ V_10 ) {
V_120 = & V_2 -> V_137 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_120 ) ;
V_120 -> V_14 |= F_26 ( V_93 ) | F_26 ( V_99 ) ;
if ( V_202 )
V_120 -> V_15 |= F_26 ( V_93 ) | F_26 ( V_99 ) ;
else
V_120 -> V_15 &= ~ ( F_26 ( V_93 ) | F_26 ( V_99 ) ) ;
F_5 ( V_2 , V_10 , V_120 ) ;
F_21 ( V_2 , V_10 ) ;
}
if ( V_205 ) {
F_8 ( V_2 , V_22 , F_33 ( V_93 ) ,
V_12 -> V_200 ) ;
F_8 ( V_2 , V_22 , F_33 ( V_99 ) ,
V_12 -> V_200 ) ;
F_21 ( V_2 , V_10 ) ;
}
}
static int F_70 ( struct V_98 * V_34 , int V_93 ,
const struct V_195 * V_12 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
bool V_202 = V_12 -> V_203 & V_204 ;
unsigned int V_99 = V_2 -> V_99 ;
struct V_11 * V_120 ;
T_2 V_10 ;
T_2 V_205 ;
F_13 ( V_2 , V_22 , F_33 ( V_93 ) , & V_205 ) ;
for ( V_10 = V_12 -> V_198 ; V_10 <= V_12 -> V_200 ; ++ V_10 ) {
V_120 = & V_2 -> V_137 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_120 ) ;
V_120 -> V_14 &= ~ F_26 ( V_93 ) ;
if ( ( V_120 -> V_14 & F_26 ( V_99 ) ) == F_26 ( V_99 ) )
V_120 -> V_14 = 0 ;
if ( V_205 == V_10 ) {
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_205 = 1 ;
else
V_205 = 0 ;
}
if ( V_202 ) {
V_120 -> V_15 &= ~ ( F_26 ( V_93 ) ) ;
if ( ( V_120 -> V_15 & F_26 ( V_99 ) ) == F_26 ( V_99 ) )
V_120 -> V_15 = 0 ;
}
F_5 ( V_2 , V_10 , V_120 ) ;
F_21 ( V_2 , V_10 ) ;
}
F_8 ( V_2 , V_22 , F_33 ( V_93 ) , V_205 ) ;
F_8 ( V_2 , V_22 , F_33 ( V_99 ) , V_205 ) ;
F_21 ( V_2 , V_205 ) ;
return 0 ;
}
static int F_71 ( struct V_98 * V_34 , int V_93 ,
struct V_195 * V_12 ,
int (* F_72)( struct V_207 * V_208 ) )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
T_2 V_10 , V_209 = 0 , V_205 ;
struct V_11 * V_120 ;
int V_210 = 0 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_209 = 1 ;
F_13 ( V_2 , V_22 , F_33 ( V_93 ) , & V_205 ) ;
for ( V_10 = V_209 ; V_10 < V_2 -> V_121 ; V_10 ++ ) {
V_120 = & V_2 -> V_137 [ V_10 ] ;
if ( ! V_120 -> V_36 )
continue;
if ( ! ( V_120 -> V_14 & F_26 ( V_93 ) ) )
continue;
V_12 -> V_198 = V_12 -> V_200 = V_10 ;
V_12 -> V_203 = 0 ;
if ( V_120 -> V_15 & F_26 ( V_93 ) )
V_12 -> V_203 |= V_204 ;
if ( V_205 == V_10 )
V_12 -> V_203 |= V_206 ;
V_210 = F_72 ( & V_12 -> V_208 ) ;
if ( V_210 )
break;
}
return V_210 ;
}
static int F_73 ( struct V_1 * V_2 )
{
unsigned int V_211 = 10 ;
T_1 V_106 ;
do {
F_3 ( V_2 , V_5 , V_212 , & V_106 ) ;
if ( ! ( V_106 & V_213 ) )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_211 -- );
F_74 ( V_2 -> V_2 , L_8 , V_106 ) ;
return - V_92 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_106 ;
if ( V_3 > V_214 )
return - V_79 ;
F_3 ( V_2 , V_5 , V_212 , & V_106 ) ;
V_106 |= V_213 ;
if ( V_3 )
V_106 |= V_214 ;
else
V_106 &= ~ V_214 ;
F_2 ( V_2 , V_5 , V_212 , V_106 ) ;
return F_73 ( V_2 ) ;
}
static int F_76 ( struct V_1 * V_2 , T_6 V_215 ,
T_2 V_10 , struct V_216 * V_217 , T_1 * V_218 ,
bool V_219 )
{
unsigned int V_4 ;
int V_132 ;
V_132 = F_73 ( V_2 ) ;
if ( V_132 )
return V_132 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_220 ; V_4 ++ ) {
T_6 V_221 ;
T_3 V_222 ;
F_51 ( V_2 , V_5 ,
F_77 ( V_4 ) , & V_221 ) ;
F_12 ( V_2 , V_5 ,
F_78 ( V_4 ) , & V_222 ) ;
F_79 ( V_217 , V_221 , V_222 ) ;
if ( ! ( V_222 & V_223 ) )
continue;
if ( ( V_221 & V_224 ) != V_215 )
continue;
* V_218 = V_4 ;
}
return - V_225 ;
}
static int F_80 ( struct V_1 * V_2 , int V_3 , int V_93 ,
const unsigned char * V_129 , T_2 V_10 , bool V_219 )
{
struct V_216 V_217 ;
T_3 V_222 ;
T_6 V_215 , V_221 = 0 ;
T_1 V_218 = 0 ;
int V_132 ;
V_215 = F_81 ( V_129 ) ;
F_82 ( V_2 , V_5 , V_226 , V_215 ) ;
F_8 ( V_2 , V_5 , V_227 , V_10 ) ;
V_132 = F_75 ( V_2 , 1 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_76 ( V_2 , V_215 , V_10 , & V_217 , & V_218 , V_219 ) ;
if ( V_3 )
return V_132 ;
if ( V_132 ) {
V_222 = 0 ;
V_218 = 1 ;
}
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_217 . V_93 = V_93 ;
V_217 . V_219 = V_219 ;
V_217 . V_10 = V_10 ;
V_217 . V_228 = true ;
memcpy ( V_217 . V_215 , V_129 , V_229 ) ;
F_83 ( & V_221 , & V_222 , & V_217 ) ;
F_84 ( V_2 , V_5 ,
F_77 ( V_218 ) , V_221 ) ;
F_7 ( V_2 , V_5 ,
F_78 ( V_218 ) , V_222 ) ;
return F_75 ( V_2 , 0 ) ;
}
static int F_85 ( struct V_98 * V_34 , int V_93 ,
const struct V_230 * V_231 ,
struct V_196 * V_197 )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
if ( F_6 ( V_130 ) || F_9 ( V_130 ) )
return - V_199 ;
return 0 ;
}
static void F_86 ( struct V_98 * V_34 , int V_93 ,
const struct V_230 * V_231 ,
struct V_196 * V_197 )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
if ( F_80 ( V_130 , 0 , V_93 , V_231 -> V_129 , V_231 -> V_10 , true ) )
F_87 ( L_9 , V_232 ) ;
}
static int F_88 ( struct V_98 * V_34 , int V_93 ,
const struct V_230 * V_231 )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
return F_80 ( V_130 , 0 , V_93 , V_231 -> V_129 , V_231 -> V_10 , false ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned int V_211 = 1000 ;
T_1 V_106 ;
do {
F_3 ( V_2 , V_5 , V_233 , & V_106 ) ;
if ( ! ( V_106 & V_234 ) )
return 0 ;
if ( V_106 & V_235 )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_211 -- );
return - V_92 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_218 ,
struct V_216 * V_217 )
{
T_6 V_221 ;
T_3 V_222 ;
F_51 ( V_2 , V_5 ,
F_91 ( V_218 ) , & V_221 ) ;
F_12 ( V_2 , V_5 ,
F_92 ( V_218 ) , & V_222 ) ;
F_79 ( V_217 , V_221 , V_222 ) ;
}
static int F_93 ( struct V_236 * V_2 , int V_93 ,
const struct V_216 * V_217 ,
struct V_230 * V_231 ,
int (* F_72)( struct V_207 * V_208 ) )
{
if ( ! V_217 -> V_219 )
return 0 ;
if ( V_93 != V_217 -> V_93 )
return 0 ;
F_94 ( V_231 -> V_129 , V_217 -> V_215 ) ;
V_231 -> V_10 = V_217 -> V_10 ;
V_231 -> V_237 = V_217 -> V_228 ? V_238 : V_239 ;
return F_72 ( & V_231 -> V_208 ) ;
}
static int F_95 ( struct V_98 * V_34 , int V_93 ,
struct V_230 * V_231 ,
int (* F_72)( struct V_207 * V_208 ) )
{
struct V_1 * V_130 = F_23 ( V_34 ) ;
struct V_236 * V_2 = V_34 -> V_104 [ V_93 ] . V_240 ;
struct V_216 V_241 [ 2 ] ;
unsigned int V_242 = 0 ;
int V_132 ;
T_1 V_106 ;
V_106 = V_234 ;
F_2 ( V_130 , V_5 , V_233 , V_106 ) ;
do {
V_132 = F_89 ( V_130 ) ;
if ( V_132 )
return V_132 ;
F_90 ( V_130 , 0 , & V_241 [ 0 ] ) ;
V_132 = F_93 ( V_2 , V_93 , & V_241 [ 0 ] , V_231 , F_72 ) ;
if ( V_132 )
return V_132 ;
if ( V_130 -> V_220 > 2 ) {
F_90 ( V_130 , 1 , & V_241 [ 1 ] ) ;
V_132 = F_93 ( V_2 , V_93 , & V_241 [ 1 ] , V_231 , F_72 ) ;
if ( V_132 )
return V_132 ;
if ( ! V_241 [ 0 ] . V_219 && ! V_241 [ 1 ] . V_219 )
break;
}
} while ( V_242 ++ < 1024 );
return 0 ;
}
static int F_96 ( struct V_98 * V_34 , int V_93 ,
struct V_236 * V_243 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
T_2 V_100 , V_106 ;
unsigned int V_4 ;
V_2 -> V_104 [ V_93 ] . V_244 = V_243 ;
F_13 ( V_2 , V_101 , F_25 ( V_93 ) , & V_100 ) ;
F_24 (dev, i) {
if ( V_2 -> V_104 [ V_4 ] . V_244 != V_243 )
continue;
F_13 ( V_2 , V_101 , F_25 ( V_4 ) , & V_106 ) ;
V_106 |= F_26 ( V_93 ) ;
F_8 ( V_2 , V_101 , F_25 ( V_4 ) , V_106 ) ;
V_2 -> V_104 [ V_4 ] . V_105 = V_106 ;
V_100 |= F_26 ( V_4 ) ;
}
F_8 ( V_2 , V_101 , F_25 ( V_93 ) , V_100 ) ;
V_2 -> V_104 [ V_93 ] . V_105 = V_100 ;
return 0 ;
}
static void F_97 ( struct V_98 * V_34 , int V_93 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
struct V_236 * V_243 = V_2 -> V_104 [ V_93 ] . V_244 ;
struct V_11 * V_120 = & V_2 -> V_137 [ 0 ] ;
unsigned int V_4 ;
T_2 V_100 , V_106 , V_205 ;
F_13 ( V_2 , V_101 , F_25 ( V_93 ) , & V_100 ) ;
F_24 (dev, i) {
if ( V_2 -> V_104 [ V_4 ] . V_244 != V_243 )
continue;
F_13 ( V_2 , V_101 , F_25 ( V_4 ) , & V_106 ) ;
V_106 &= ~ F_26 ( V_93 ) ;
F_8 ( V_2 , V_101 , F_25 ( V_4 ) , V_106 ) ;
V_2 -> V_104 [ V_93 ] . V_105 = V_106 ;
if ( V_93 != V_4 )
V_100 &= ~ F_26 ( V_4 ) ;
}
F_8 ( V_2 , V_101 , F_25 ( V_93 ) , V_100 ) ;
V_2 -> V_104 [ V_93 ] . V_105 = V_100 ;
V_2 -> V_104 [ V_93 ] . V_244 = NULL ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_205 = 1 ;
else
V_205 = 0 ;
F_11 ( V_2 , V_205 , V_120 ) ;
V_120 -> V_14 |= F_26 ( V_93 ) | F_26 ( V_2 -> V_99 ) ;
V_120 -> V_15 |= F_26 ( V_93 ) | F_26 ( V_2 -> V_99 ) ;
F_5 ( V_2 , V_205 , V_120 ) ;
}
static void F_98 ( struct V_98 * V_34 , int V_93 ,
T_1 V_245 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
T_1 V_246 , V_247 ;
T_1 V_106 ;
F_3 ( V_2 , V_42 , F_28 ( V_93 ) , & V_106 ) ;
V_247 = V_106 & V_248 ;
switch ( V_245 ) {
case V_249 :
V_246 = V_250 ;
break;
case V_251 :
V_246 = V_252 ;
break;
case V_253 :
V_246 = V_254 ;
break;
case V_255 :
V_246 = V_256 ;
break;
case V_257 :
V_246 = V_258 ;
break;
default:
F_39 ( V_34 -> V_2 , L_10 , V_245 ) ;
return;
}
if ( V_247 != V_246 ) {
if ( V_247 >= V_254 &&
V_246 <= V_252 ) {
if ( F_20 ( V_2 , V_93 ) ) {
F_39 ( V_34 -> V_2 , L_11 ) ;
return;
}
}
}
F_3 ( V_2 , V_42 , F_28 ( V_93 ) , & V_106 ) ;
V_106 &= ~ V_248 ;
V_106 |= V_246 ;
F_2 ( V_2 , V_42 , F_28 ( V_93 ) , V_106 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_98 * V_34 = V_2 -> V_34 ;
unsigned int V_4 ;
int V_132 ;
for ( V_4 = 0 ; V_4 < F_100 ( V_259 ) ; V_4 ++ ) {
const struct V_260 * V_261 = & V_259 [ V_4 ] ;
if ( V_261 -> V_262 == V_2 -> V_262 ) {
if ( ! V_2 -> V_80 )
V_2 -> V_80 = V_261 -> V_80 ;
V_2 -> V_150 = V_261 -> V_263 ;
V_2 -> V_264 = V_261 -> V_264 ;
V_2 -> V_6 [ 0 ] = V_261 -> V_6 [ 0 ] ;
V_2 -> V_6 [ 1 ] = V_261 -> V_6 [ 1 ] ;
V_2 -> V_6 [ 2 ] = V_261 -> V_6 [ 2 ] ;
V_2 -> V_84 = V_261 -> V_84 ;
V_34 -> V_265 = & V_266 ;
V_2 -> V_99 = V_261 -> V_99 ;
V_2 -> V_121 = V_261 -> V_137 ;
V_2 -> V_220 = V_261 -> V_267 ;
break;
}
}
if ( F_6 ( V_2 ) ) {
T_1 V_47 ;
F_3 ( V_2 , V_22 , V_51 , & V_47 ) ;
switch ( V_47 & 3 ) {
case 1 :
break;
case 3 :
V_2 -> V_80 &= ~ F_26 ( 4 ) ;
break;
default:
#ifndef F_101
return - V_79 ;
#else
break;
#endif
}
} else if ( V_2 -> V_262 == V_268 ) {
T_6 V_269 ;
F_102 ( V_2 , V_270 , V_271 , & V_269 ) ;
if ( V_269 & V_272 )
V_2 -> V_99 = 5 ;
}
V_2 -> V_138 = V_2 -> V_99 + 1 ;
V_2 -> V_80 |= F_26 ( V_2 -> V_99 ) ;
V_2 -> V_104 = F_103 ( V_2 -> V_2 ,
sizeof( struct V_273 ) * V_2 -> V_138 ,
V_274 ) ;
if ( ! V_2 -> V_104 )
return - V_275 ;
V_2 -> V_137 = F_103 ( V_2 -> V_2 ,
sizeof( struct V_11 ) * V_2 -> V_121 ,
V_274 ) ;
if ( ! V_2 -> V_137 )
return - V_275 ;
V_2 -> V_125 = F_104 ( V_2 ) ;
if ( V_2 -> V_125 >= 0 ) {
V_132 = F_105 ( V_2 -> V_2 , V_2 -> V_125 ,
V_276 , L_12 ) ;
if ( V_132 )
return V_132 ;
}
return 0 ;
}
struct V_1 * F_106 ( struct V_277 * V_278 , struct V_279 * V_133 ,
void * V_130 )
{
struct V_98 * V_34 ;
struct V_1 * V_2 ;
V_34 = F_103 ( V_278 , sizeof( * V_34 ) + sizeof( * V_2 ) , V_274 ) ;
if ( ! V_34 )
return NULL ;
V_2 = (struct V_1 * ) ( V_34 + 1 ) ;
V_34 -> V_130 = V_2 ;
V_34 -> V_2 = V_278 ;
V_2 -> V_2 = V_278 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_130 = V_130 ;
V_2 -> V_133 = V_133 ;
F_107 ( & V_2 -> V_280 ) ;
F_107 ( & V_2 -> V_152 ) ;
return V_2 ;
}
int F_108 ( struct V_1 * V_2 )
{
T_3 V_281 ;
T_2 V_282 ;
T_1 V_283 ;
int V_132 ;
V_132 = F_3 ( V_2 , V_116 , V_284 , & V_283 ) ;
if ( V_132 )
return V_132 ;
switch ( V_283 ) {
case 0 :
F_8 ( V_2 , V_22 , V_24 , 0xf ) ;
F_13 ( V_2 , V_22 , V_24 , & V_282 ) ;
if ( V_282 == 0xf )
V_2 -> V_262 = V_285 ;
else
V_2 -> V_262 = V_286 ;
break;
case V_287 :
case V_288 :
case V_289 :
V_2 -> V_262 = V_283 ;
break;
default:
V_132 = F_12 ( V_2 , V_116 , V_284 , & V_281 ) ;
if ( V_132 )
return V_132 ;
switch ( V_281 ) {
case V_268 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
V_2 -> V_262 = V_281 ;
break;
default:
F_87 ( L_13 ,
V_283 , V_281 ) ;
return - V_297 ;
}
}
if ( V_2 -> V_262 == V_285 )
return F_3 ( V_2 , V_270 , V_298 ,
& V_2 -> V_18 ) ;
else
return F_3 ( V_2 , V_116 , V_299 ,
& V_2 -> V_18 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_2 -> V_300 ) {
V_2 -> V_262 = V_2 -> V_300 -> V_262 ;
V_2 -> V_80 = V_2 -> V_300 -> V_80 ;
}
if ( ! V_2 -> V_262 && F_108 ( V_2 ) )
return - V_79 ;
V_132 = F_99 ( V_2 ) ;
if ( V_132 )
return V_132 ;
F_110 ( L_14 , V_2 -> V_150 , V_2 -> V_18 ) ;
return F_111 ( V_2 -> V_34 , V_2 -> V_34 -> V_2 -> V_301 ) ;
}
