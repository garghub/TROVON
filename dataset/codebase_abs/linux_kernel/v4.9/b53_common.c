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
struct V_1 * V_2 = V_34 -> V_100 ;
unsigned int V_4 ;
T_2 V_101 ;
F_23 (dev, i) {
F_13 ( V_2 , V_102 , F_24 ( V_4 ) , & V_101 ) ;
V_101 |= F_25 ( V_99 ) ;
F_8 ( V_2 , V_102 , F_24 ( V_4 ) , V_101 ) ;
}
}
static int F_26 ( struct V_98 * V_34 , int V_93 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
unsigned int V_99 = V_2 -> V_99 ;
T_2 V_101 ;
F_2 ( V_2 , V_42 , F_27 ( V_93 ) , 0 ) ;
F_13 ( V_2 , V_102 , F_24 ( V_93 ) , & V_101 ) ;
V_101 &= ~ 0x1ff ;
V_101 |= F_25 ( V_93 ) ;
V_101 |= V_2 -> V_105 [ V_93 ] . V_106 ;
F_8 ( V_2 , V_102 , F_24 ( V_93 ) , V_101 ) ;
F_22 ( V_34 , V_99 ) ;
return 0 ;
}
static void F_28 ( struct V_98 * V_34 , int V_93 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
T_1 V_107 ;
F_3 ( V_2 , V_42 , F_27 ( V_93 ) , & V_107 ) ;
V_107 |= V_108 | V_109 ;
F_2 ( V_2 , V_42 , F_27 ( V_93 ) , V_107 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned int V_99 = V_2 -> V_99 ;
T_1 V_110 ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_99 == V_111 )
V_99 = V_112 ;
V_110 = V_113 |
V_114 |
V_115 ;
F_2 ( V_2 , V_42 , F_27 ( V_99 ) , V_110 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_116 ;
F_3 ( V_2 , V_117 , V_118 , & V_116 ) ;
V_116 &= ~ ( V_119 | V_120 ) ;
F_2 ( V_2 , V_117 , V_118 , V_116 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_11 V_121 = { 0 } ;
int V_4 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
for ( V_4 = 1 ; V_4 < V_2 -> V_122 ; V_4 ++ )
F_5 ( V_2 , V_4 , & V_121 ) ;
} else {
F_1 ( V_2 , V_123 ) ;
}
F_15 ( V_2 , false ) ;
F_23 (dev, i)
F_8 ( V_2 , V_22 ,
F_32 ( V_4 ) , 1 ) ;
if ( ! F_6 ( V_2 ) && ! F_9 ( V_2 ) )
F_17 ( V_2 , V_2 -> V_124 , false ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_125 = V_2 -> V_126 ;
if ( V_125 < 0 )
return;
F_34 ( V_125 , 0 ) ;
F_35 ( 50 ) ;
F_34 ( V_125 , 1 ) ;
F_35 ( 20 ) ;
V_2 -> V_127 = 0xff ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_41 ;
F_33 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
F_2 ( V_2 , V_42 , V_128 , 0x83 ) ;
F_2 ( V_2 , V_42 , V_128 , 0x00 ) ;
}
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
if ( ! ( V_41 & V_44 ) ) {
V_41 &= ~ V_57 ;
V_41 |= V_44 ;
F_2 ( V_2 , V_42 , V_43 , V_41 ) ;
F_3 ( V_2 , V_42 , V_43 , & V_41 ) ;
if ( ! ( V_41 & V_44 ) ) {
F_38 ( V_2 -> V_2 , L_2 ) ;
return - V_79 ;
}
}
F_30 ( V_2 ) ;
return F_18 ( V_2 , V_129 ) ;
}
static int F_39 ( struct V_98 * V_34 , int V_130 , int V_107 )
{
struct V_1 * V_100 = V_34 -> V_100 ;
T_2 V_131 = 0 ;
int V_132 ;
if ( V_100 -> V_133 -> V_134 )
V_132 = V_100 -> V_133 -> V_134 ( V_100 , V_130 , V_107 , & V_131 ) ;
else
V_132 = F_13 ( V_100 , F_40 ( V_130 ) ,
V_107 * 2 , & V_131 ) ;
return V_132 ? V_132 : V_131 ;
}
static int F_41 ( struct V_98 * V_34 , int V_130 , int V_107 , T_2 V_135 )
{
struct V_1 * V_100 = V_34 -> V_100 ;
if ( V_100 -> V_133 -> V_136 )
return V_100 -> V_133 -> V_136 ( V_100 , V_130 , V_107 , V_135 ) ;
return F_8 ( V_100 , F_40 ( V_130 ) , V_107 * 2 , V_135 ) ;
}
static int F_42 ( struct V_1 * V_100 )
{
V_100 -> V_124 = false ;
memset ( V_100 -> V_137 , 0 , sizeof( * V_100 -> V_137 ) * V_100 -> V_122 ) ;
memset ( V_100 -> V_105 , 0 , sizeof( * V_100 -> V_105 ) * V_100 -> V_138 ) ;
return F_36 ( V_100 ) ;
}
static int F_43 ( struct V_1 * V_100 )
{
F_14 ( V_100 , 0 ) ;
F_31 ( V_100 ) ;
F_14 ( V_100 , 1 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_100 )
{
T_1 V_116 ;
F_3 ( V_100 , V_117 , V_118 , & V_116 ) ;
F_2 ( V_100 , V_117 , V_118 , V_116 | V_119 ) ;
F_19 ( 1 ) ;
F_2 ( V_100 , V_117 , V_118 , V_116 & ~ V_119 ) ;
F_19 ( 1 ) ;
}
static const struct V_139 * F_45 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_140 ;
else if ( F_16 ( V_2 ) )
return V_141 ;
else if ( F_46 ( V_2 ) )
return V_142 ;
else
return V_143 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_144 ;
else if ( F_16 ( V_2 ) )
return V_145 ;
else if ( F_46 ( V_2 ) )
return V_146 ;
else
return V_147 ;
}
static void F_48 ( struct V_98 * V_34 , int V_93 , T_4 * V_148 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
const struct V_139 * V_149 = F_45 ( V_2 ) ;
unsigned int V_150 = F_47 ( V_2 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_150 ; V_4 ++ )
memcpy ( V_148 + V_4 * V_151 ,
V_149 [ V_4 ] . V_152 , V_151 ) ;
}
static void F_49 ( struct V_98 * V_34 , int V_93 ,
T_5 * V_148 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
const struct V_139 * V_149 = F_45 ( V_2 ) ;
unsigned int V_150 = F_47 ( V_2 ) ;
const struct V_139 * V_153 ;
unsigned int V_4 ;
T_6 V_135 = 0 ;
if ( F_9 ( V_2 ) && V_93 == 5 )
V_93 = 8 ;
F_50 ( & V_2 -> V_154 ) ;
for ( V_4 = 0 ; V_4 < V_150 ; V_4 ++ ) {
V_153 = & V_149 [ V_4 ] ;
if ( V_153 -> V_155 == 8 ) {
F_51 ( V_2 , F_52 ( V_93 ) , V_153 -> V_156 , & V_135 ) ;
} else {
T_3 V_157 ;
F_12 ( V_2 , F_52 ( V_93 ) , V_153 -> V_156 ,
& V_157 ) ;
V_135 = V_157 ;
}
V_148 [ V_4 ] = ( T_6 ) V_135 ;
}
F_53 ( & V_2 -> V_154 ) ;
}
static int F_54 ( struct V_98 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
return F_47 ( V_2 ) ;
}
static int F_55 ( struct V_98 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
unsigned int V_93 ;
int V_132 ;
V_132 = F_42 ( V_2 ) ;
if ( V_132 ) {
F_38 ( V_34 -> V_2 , L_3 ) ;
return V_132 ;
}
F_44 ( V_2 ) ;
V_132 = F_43 ( V_2 ) ;
if ( V_132 )
F_38 ( V_34 -> V_2 , L_4 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_138 ; V_93 ++ ) {
if ( F_25 ( V_93 ) & V_34 -> V_158 )
F_26 ( V_34 , V_93 , NULL ) ;
else if ( F_56 ( V_34 , V_93 ) )
F_29 ( V_2 ) ;
else
F_28 ( V_34 , V_93 , NULL ) ;
}
return V_132 ;
}
static void F_57 ( struct V_98 * V_34 , int V_93 ,
struct V_103 * V_159 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
T_1 V_160 = 0 , V_107 = 0 , V_161 ;
if ( ! F_58 ( V_159 ) )
return;
if ( V_93 == V_2 -> V_99 ) {
V_161 = V_162 ;
V_107 = V_163 ;
} else {
V_161 = F_59 ( V_93 ) ;
V_107 = V_164 ;
}
if ( V_159 -> V_165 )
V_107 |= V_166 ;
if ( V_159 -> V_167 == V_168 )
V_107 |= V_169 ;
switch ( V_159 -> V_170 ) {
case 2000 :
V_107 |= V_171 ;
case V_172 :
V_107 |= V_173 ;
break;
case V_174 :
V_107 |= V_175 ;
break;
case V_176 :
V_107 |= V_177 ;
break;
default:
F_38 ( V_34 -> V_2 , L_5 , V_159 -> V_170 ) ;
return;
}
if ( F_60 ( V_2 ) && V_93 == V_2 -> V_99 )
V_107 |= V_178 | V_179 ;
if ( V_159 -> V_180 ) {
if ( V_159 -> V_181 )
V_107 |= V_179 ;
V_107 |= V_178 ;
}
F_2 ( V_2 , V_42 , V_161 , V_107 ) ;
if ( F_61 ( V_2 ) && F_62 ( V_159 ) ) {
if ( V_93 == 8 )
V_161 = V_182 ;
else
V_161 = F_63 ( V_93 ) ;
F_3 ( V_2 , V_42 , V_161 , & V_160 ) ;
V_160 &= ~ ( V_183 | V_184 |
V_185 ) ;
if ( V_159 -> V_186 == V_187 )
V_160 |= V_184 ;
if ( V_159 -> V_186 == V_188 )
V_160 |= V_184 | V_183 ;
V_160 |= V_185 ;
F_2 ( V_2 , V_42 , V_161 , V_160 ) ;
F_64 ( V_34 -> V_2 , L_6 , V_93 ,
F_65 ( V_159 -> V_186 ) ) ;
}
if ( F_6 ( V_2 ) ) {
F_3 ( V_2 , V_42 , V_162 ,
& V_107 ) ;
if ( ! ( V_107 & V_189 ) ) {
F_2 ( V_2 , V_42 , V_162 ,
V_107 | V_189 ) ;
F_3 ( V_2 , V_42 , V_162 ,
& V_107 ) ;
if ( ! ( V_107 & V_189 ) ) {
F_38 ( V_34 -> V_2 ,
L_7 ) ;
return;
}
}
} else if ( F_60 ( V_2 ) ) {
if ( V_93 != V_2 -> V_99 ) {
T_1 V_190 = F_59 ( V_2 -> V_99 ) ;
T_1 V_191 ;
F_3 ( V_2 , V_42 , V_190 , & V_191 ) ;
V_191 |= V_192 |
V_193 |
V_194 |
V_164 |
V_195 ;
F_2 ( V_2 , V_42 , V_190 , V_191 ) ;
}
}
}
static int F_66 ( struct V_98 * V_34 , int V_93 ,
bool V_196 )
{
return 0 ;
}
static int F_67 ( struct V_98 * V_34 , int V_93 ,
const struct V_197 * V_12 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_12 -> V_200 == 0 )
return - V_201 ;
if ( V_12 -> V_202 > V_2 -> V_122 )
return - V_203 ;
F_15 ( V_2 , true ) ;
return 0 ;
}
static void F_68 ( struct V_98 * V_34 , int V_93 ,
const struct V_197 * V_12 ,
struct V_198 * V_199 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
bool V_204 = V_12 -> V_205 & V_206 ;
bool V_207 = V_12 -> V_205 & V_208 ;
unsigned int V_99 = V_2 -> V_99 ;
struct V_11 * V_121 ;
T_2 V_10 ;
for ( V_10 = V_12 -> V_200 ; V_10 <= V_12 -> V_202 ; ++ V_10 ) {
V_121 = & V_2 -> V_137 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_121 ) ;
V_121 -> V_14 |= F_25 ( V_93 ) | F_25 ( V_99 ) ;
if ( V_204 )
V_121 -> V_15 |= F_25 ( V_93 ) ;
else
V_121 -> V_15 &= ~ F_25 ( V_93 ) ;
V_121 -> V_15 &= ~ F_25 ( V_99 ) ;
F_5 ( V_2 , V_10 , V_121 ) ;
F_21 ( V_2 , V_10 ) ;
}
if ( V_207 ) {
F_8 ( V_2 , V_22 , F_32 ( V_93 ) ,
V_12 -> V_202 ) ;
F_21 ( V_2 , V_10 ) ;
}
}
static int F_69 ( struct V_98 * V_34 , int V_93 ,
const struct V_197 * V_12 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
bool V_204 = V_12 -> V_205 & V_206 ;
struct V_11 * V_121 ;
T_2 V_10 ;
T_2 V_207 ;
F_13 ( V_2 , V_22 , F_32 ( V_93 ) , & V_207 ) ;
for ( V_10 = V_12 -> V_200 ; V_10 <= V_12 -> V_202 ; ++ V_10 ) {
V_121 = & V_2 -> V_137 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_121 ) ;
V_121 -> V_14 &= ~ F_25 ( V_93 ) ;
if ( V_207 == V_10 ) {
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_207 = 1 ;
else
V_207 = 0 ;
}
if ( V_204 )
V_121 -> V_15 &= ~ ( F_25 ( V_93 ) ) ;
F_5 ( V_2 , V_10 , V_121 ) ;
F_21 ( V_2 , V_10 ) ;
}
F_8 ( V_2 , V_22 , F_32 ( V_93 ) , V_207 ) ;
F_21 ( V_2 , V_207 ) ;
return 0 ;
}
static int F_70 ( struct V_98 * V_34 , int V_93 ,
struct V_197 * V_12 ,
int (* F_71)( struct V_209 * V_210 ) )
{
struct V_1 * V_2 = V_34 -> V_100 ;
T_2 V_10 , V_211 = 0 , V_207 ;
struct V_11 * V_121 ;
int V_212 = 0 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_211 = 1 ;
F_13 ( V_2 , V_22 , F_32 ( V_93 ) , & V_207 ) ;
for ( V_10 = V_211 ; V_10 < V_2 -> V_122 ; V_10 ++ ) {
V_121 = & V_2 -> V_137 [ V_10 ] ;
if ( ! V_121 -> V_36 )
continue;
if ( ! ( V_121 -> V_14 & F_25 ( V_93 ) ) )
continue;
V_12 -> V_200 = V_12 -> V_202 = V_10 ;
V_12 -> V_205 = 0 ;
if ( V_121 -> V_15 & F_25 ( V_93 ) )
V_12 -> V_205 |= V_206 ;
if ( V_207 == V_10 )
V_12 -> V_205 |= V_208 ;
V_212 = F_71 ( & V_12 -> V_210 ) ;
if ( V_212 )
break;
}
return V_212 ;
}
static int F_72 ( struct V_1 * V_2 )
{
unsigned int V_213 = 10 ;
T_1 V_107 ;
do {
F_3 ( V_2 , V_5 , V_214 , & V_107 ) ;
if ( ! ( V_107 & V_215 ) )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_213 -- );
F_73 ( V_2 -> V_2 , L_8 , V_107 ) ;
return - V_92 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_107 ;
if ( V_3 > V_216 )
return - V_79 ;
F_3 ( V_2 , V_5 , V_214 , & V_107 ) ;
V_107 |= V_215 ;
if ( V_3 )
V_107 |= V_216 ;
else
V_107 &= ~ V_216 ;
F_2 ( V_2 , V_5 , V_214 , V_107 ) ;
return F_72 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 , T_6 V_217 ,
T_2 V_10 , struct V_218 * V_219 , T_1 * V_220 ,
bool V_221 )
{
unsigned int V_4 ;
int V_132 ;
V_132 = F_72 ( V_2 ) ;
if ( V_132 )
return V_132 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_222 ; V_4 ++ ) {
T_6 V_223 ;
T_3 V_224 ;
F_51 ( V_2 , V_5 ,
F_76 ( V_4 ) , & V_223 ) ;
F_12 ( V_2 , V_5 ,
F_77 ( V_4 ) , & V_224 ) ;
F_78 ( V_219 , V_223 , V_224 ) ;
if ( ! ( V_224 & V_225 ) )
continue;
if ( ( V_223 & V_226 ) != V_217 )
continue;
* V_220 = V_4 ;
}
return - V_227 ;
}
static int F_79 ( struct V_1 * V_2 , int V_3 , int V_93 ,
const unsigned char * V_130 , T_2 V_10 , bool V_221 )
{
struct V_218 V_219 ;
T_3 V_224 ;
T_6 V_217 , V_223 = 0 ;
T_1 V_220 = 0 ;
int V_132 ;
V_217 = F_80 ( V_130 ) ;
F_81 ( V_2 , V_5 , V_228 , V_217 ) ;
F_8 ( V_2 , V_5 , V_229 , V_10 ) ;
V_132 = F_74 ( V_2 , 1 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_75 ( V_2 , V_217 , V_10 , & V_219 , & V_220 , V_221 ) ;
if ( V_3 )
return V_132 ;
if ( V_132 ) {
V_224 = 0 ;
V_220 = 1 ;
}
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
V_219 . V_93 = V_93 ;
V_219 . V_221 = V_221 ;
V_219 . V_10 = V_10 ;
V_219 . V_230 = true ;
memcpy ( V_219 . V_217 , V_130 , V_231 ) ;
F_82 ( & V_223 , & V_224 , & V_219 ) ;
F_83 ( V_2 , V_5 ,
F_76 ( V_220 ) , V_223 ) ;
F_7 ( V_2 , V_5 ,
F_77 ( V_220 ) , V_224 ) ;
return F_74 ( V_2 , 0 ) ;
}
static int F_84 ( struct V_98 * V_34 , int V_93 ,
const struct V_232 * V_233 ,
struct V_198 * V_199 )
{
struct V_1 * V_100 = V_34 -> V_100 ;
if ( F_6 ( V_100 ) || F_9 ( V_100 ) )
return - V_201 ;
return 0 ;
}
static void F_85 ( struct V_98 * V_34 , int V_93 ,
const struct V_232 * V_233 ,
struct V_198 * V_199 )
{
struct V_1 * V_100 = V_34 -> V_100 ;
if ( F_79 ( V_100 , 0 , V_93 , V_233 -> V_130 , V_233 -> V_10 , true ) )
F_86 ( L_9 , V_234 ) ;
}
static int F_87 ( struct V_98 * V_34 , int V_93 ,
const struct V_232 * V_233 )
{
struct V_1 * V_100 = V_34 -> V_100 ;
return F_79 ( V_100 , 0 , V_93 , V_233 -> V_130 , V_233 -> V_10 , false ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
unsigned int V_213 = 1000 ;
T_1 V_107 ;
do {
F_3 ( V_2 , V_5 , V_235 , & V_107 ) ;
if ( ! ( V_107 & V_236 ) )
return 0 ;
if ( V_107 & V_237 )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_213 -- );
return - V_92 ;
}
static void F_89 ( struct V_1 * V_2 , T_1 V_220 ,
struct V_218 * V_219 )
{
T_6 V_223 ;
T_3 V_224 ;
F_51 ( V_2 , V_5 ,
F_90 ( V_220 ) , & V_223 ) ;
F_12 ( V_2 , V_5 ,
F_91 ( V_220 ) , & V_224 ) ;
F_78 ( V_219 , V_223 , V_224 ) ;
}
static int F_92 ( struct V_238 * V_2 , int V_93 ,
const struct V_218 * V_219 ,
struct V_232 * V_233 ,
int (* F_71)( struct V_209 * V_210 ) )
{
if ( ! V_219 -> V_221 )
return 0 ;
if ( V_93 != V_219 -> V_93 )
return 0 ;
F_93 ( V_233 -> V_130 , V_219 -> V_217 ) ;
V_233 -> V_10 = V_219 -> V_10 ;
V_233 -> V_239 = V_219 -> V_230 ? V_240 : V_241 ;
return F_71 ( & V_233 -> V_210 ) ;
}
static int F_94 ( struct V_98 * V_34 , int V_93 ,
struct V_232 * V_233 ,
int (* F_71)( struct V_209 * V_210 ) )
{
struct V_1 * V_100 = V_34 -> V_100 ;
struct V_238 * V_2 = V_34 -> V_105 [ V_93 ] . V_242 ;
struct V_218 V_243 [ 2 ] ;
unsigned int V_244 = 0 ;
int V_132 ;
T_1 V_107 ;
V_107 = V_236 ;
F_2 ( V_100 , V_5 , V_235 , V_107 ) ;
do {
V_132 = F_88 ( V_100 ) ;
if ( V_132 )
return V_132 ;
F_89 ( V_100 , 0 , & V_243 [ 0 ] ) ;
V_132 = F_92 ( V_2 , V_93 , & V_243 [ 0 ] , V_233 , F_71 ) ;
if ( V_132 )
return V_132 ;
if ( V_100 -> V_222 > 2 ) {
F_89 ( V_100 , 1 , & V_243 [ 1 ] ) ;
V_132 = F_92 ( V_2 , V_93 , & V_243 [ 1 ] , V_233 , F_71 ) ;
if ( V_132 )
return V_132 ;
if ( ! V_243 [ 0 ] . V_221 && ! V_243 [ 1 ] . V_221 )
break;
}
} while ( V_244 ++ < 1024 );
return 0 ;
}
static int F_95 ( struct V_98 * V_34 , int V_93 ,
struct V_238 * V_245 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
T_7 V_99 = V_34 -> V_246 -> V_99 ;
T_2 V_101 , V_107 ;
unsigned int V_4 ;
if ( F_46 ( V_2 ) ) {
F_13 ( V_2 , V_22 , V_247 , & V_107 ) ;
V_107 &= ~ F_25 ( V_93 ) ;
if ( ( V_107 & F_25 ( V_99 ) ) == F_25 ( V_99 ) )
V_107 &= ~ F_25 ( V_99 ) ;
F_8 ( V_2 , V_22 , V_247 , V_107 ) ;
}
V_2 -> V_105 [ V_93 ] . V_248 = V_245 ;
F_13 ( V_2 , V_102 , F_24 ( V_93 ) , & V_101 ) ;
F_23 (dev, i) {
if ( V_2 -> V_105 [ V_4 ] . V_248 != V_245 )
continue;
F_13 ( V_2 , V_102 , F_24 ( V_4 ) , & V_107 ) ;
V_107 |= F_25 ( V_93 ) ;
F_8 ( V_2 , V_102 , F_24 ( V_4 ) , V_107 ) ;
V_2 -> V_105 [ V_4 ] . V_106 = V_107 ;
V_101 |= F_25 ( V_4 ) ;
}
F_8 ( V_2 , V_102 , F_24 ( V_93 ) , V_101 ) ;
V_2 -> V_105 [ V_93 ] . V_106 = V_101 ;
return 0 ;
}
static void F_96 ( struct V_98 * V_34 , int V_93 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
struct V_238 * V_245 = V_2 -> V_105 [ V_93 ] . V_248 ;
struct V_11 * V_121 = & V_2 -> V_137 [ 0 ] ;
T_7 V_99 = V_34 -> V_246 -> V_99 ;
unsigned int V_4 ;
T_2 V_101 , V_107 , V_207 ;
F_13 ( V_2 , V_102 , F_24 ( V_93 ) , & V_101 ) ;
F_23 (dev, i) {
if ( V_2 -> V_105 [ V_4 ] . V_248 != V_245 )
continue;
F_13 ( V_2 , V_102 , F_24 ( V_4 ) , & V_107 ) ;
V_107 &= ~ F_25 ( V_93 ) ;
F_8 ( V_2 , V_102 , F_24 ( V_4 ) , V_107 ) ;
V_2 -> V_105 [ V_93 ] . V_106 = V_107 ;
if ( V_93 != V_4 )
V_101 &= ~ F_25 ( V_4 ) ;
}
F_8 ( V_2 , V_102 , F_24 ( V_93 ) , V_101 ) ;
V_2 -> V_105 [ V_93 ] . V_106 = V_101 ;
V_2 -> V_105 [ V_93 ] . V_248 = NULL ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_207 = 1 ;
else
V_207 = 0 ;
if ( F_46 ( V_2 ) ) {
F_13 ( V_2 , V_22 , V_247 , & V_107 ) ;
V_107 |= F_25 ( V_93 ) ;
if ( ! ( V_107 & F_25 ( V_99 ) ) )
V_107 |= F_25 ( V_99 ) ;
F_8 ( V_2 , V_22 , V_247 , V_107 ) ;
} else {
F_11 ( V_2 , V_207 , V_121 ) ;
V_121 -> V_14 |= F_25 ( V_93 ) | F_25 ( V_2 -> V_99 ) ;
V_121 -> V_15 |= F_25 ( V_93 ) | F_25 ( V_2 -> V_99 ) ;
F_5 ( V_2 , V_207 , V_121 ) ;
}
}
static void F_97 ( struct V_98 * V_34 , int V_93 , T_1 V_249 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
T_1 V_250 ;
T_1 V_107 ;
switch ( V_249 ) {
case V_251 :
V_250 = V_252 ;
break;
case V_253 :
V_250 = V_254 ;
break;
case V_255 :
V_250 = V_256 ;
break;
case V_257 :
V_250 = V_258 ;
break;
case V_259 :
V_250 = V_260 ;
break;
default:
F_38 ( V_34 -> V_2 , L_10 , V_249 ) ;
return;
}
F_3 ( V_2 , V_42 , F_27 ( V_93 ) , & V_107 ) ;
V_107 &= ~ V_261 ;
V_107 |= V_250 ;
F_2 ( V_2 , V_42 , F_27 ( V_93 ) , V_107 ) ;
}
static void F_98 ( struct V_98 * V_34 , int V_93 )
{
struct V_1 * V_2 = V_34 -> V_100 ;
if ( F_20 ( V_2 , V_93 ) )
F_38 ( V_34 -> V_2 , L_11 ) ;
}
static enum V_262 F_99 ( struct V_98 * V_34 )
{
return V_263 ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
int V_132 ;
for ( V_4 = 0 ; V_4 < F_101 ( V_264 ) ; V_4 ++ ) {
const struct V_265 * V_266 = & V_264 [ V_4 ] ;
if ( V_266 -> V_267 == V_2 -> V_267 ) {
if ( ! V_2 -> V_80 )
V_2 -> V_80 = V_266 -> V_80 ;
V_2 -> V_152 = V_266 -> V_268 ;
V_2 -> V_269 = V_266 -> V_269 ;
V_2 -> V_6 [ 0 ] = V_266 -> V_6 [ 0 ] ;
V_2 -> V_6 [ 1 ] = V_266 -> V_6 [ 1 ] ;
V_2 -> V_6 [ 2 ] = V_266 -> V_6 [ 2 ] ;
V_2 -> V_84 = V_266 -> V_84 ;
V_2 -> V_99 = V_266 -> V_99 ;
V_2 -> V_122 = V_266 -> V_137 ;
V_2 -> V_222 = V_266 -> V_270 ;
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
V_2 -> V_80 &= ~ F_25 ( 4 ) ;
break;
default:
#ifndef F_102
return - V_79 ;
#else
break;
#endif
}
} else if ( V_2 -> V_267 == V_271 ) {
T_6 V_272 ;
F_103 ( V_2 , V_273 , V_274 , & V_272 ) ;
if ( V_272 & V_275 )
V_2 -> V_99 = 5 ;
}
V_2 -> V_138 = V_2 -> V_99 + 1 ;
V_2 -> V_80 |= F_25 ( V_2 -> V_99 ) ;
V_2 -> V_105 = F_104 ( V_2 -> V_2 ,
sizeof( struct V_276 ) * V_2 -> V_138 ,
V_277 ) ;
if ( ! V_2 -> V_105 )
return - V_278 ;
V_2 -> V_137 = F_104 ( V_2 -> V_2 ,
sizeof( struct V_11 ) * V_2 -> V_122 ,
V_277 ) ;
if ( ! V_2 -> V_137 )
return - V_278 ;
V_2 -> V_126 = F_105 ( V_2 ) ;
if ( V_2 -> V_126 >= 0 ) {
V_132 = F_106 ( V_2 -> V_2 , V_2 -> V_126 ,
V_279 , L_12 ) ;
if ( V_132 )
return V_132 ;
}
return 0 ;
}
struct V_1 * F_107 ( struct V_280 * V_281 ,
const struct V_282 * V_133 ,
void * V_100 )
{
struct V_98 * V_34 ;
struct V_1 * V_2 ;
V_34 = F_104 ( V_281 , sizeof( * V_34 ) + sizeof( * V_2 ) , V_277 ) ;
if ( ! V_34 )
return NULL ;
V_2 = (struct V_1 * ) ( V_34 + 1 ) ;
V_34 -> V_100 = V_2 ;
V_34 -> V_2 = V_281 ;
V_2 -> V_2 = V_281 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_133 = V_133 ;
V_34 -> V_133 = & V_283 ;
F_108 ( & V_2 -> V_284 ) ;
F_108 ( & V_2 -> V_154 ) ;
return V_2 ;
}
int F_109 ( struct V_1 * V_2 )
{
T_3 V_285 ;
T_2 V_286 ;
T_1 V_287 ;
int V_132 ;
V_132 = F_3 ( V_2 , V_117 , V_288 , & V_287 ) ;
if ( V_132 )
return V_132 ;
switch ( V_287 ) {
case 0 :
F_8 ( V_2 , V_22 , V_24 , 0xf ) ;
F_13 ( V_2 , V_22 , V_24 , & V_286 ) ;
if ( V_286 == 0xf )
V_2 -> V_267 = V_289 ;
else
V_2 -> V_267 = V_290 ;
break;
case V_291 :
case V_292 :
case V_293 :
V_2 -> V_267 = V_287 ;
break;
default:
V_132 = F_12 ( V_2 , V_117 , V_288 , & V_285 ) ;
if ( V_132 )
return V_132 ;
switch ( V_285 ) {
case V_271 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
V_2 -> V_267 = V_285 ;
break;
default:
F_86 ( L_13 ,
V_287 , V_285 ) ;
return - V_301 ;
}
}
if ( V_2 -> V_267 == V_289 )
return F_3 ( V_2 , V_273 , V_302 ,
& V_2 -> V_18 ) ;
else
return F_3 ( V_2 , V_117 , V_303 ,
& V_2 -> V_18 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_2 -> V_304 ) {
V_2 -> V_267 = V_2 -> V_304 -> V_267 ;
V_2 -> V_80 = V_2 -> V_304 -> V_80 ;
}
if ( ! V_2 -> V_267 && F_109 ( V_2 ) )
return - V_79 ;
V_132 = F_100 ( V_2 ) ;
if ( V_132 )
return V_132 ;
F_111 ( L_14 , V_2 -> V_152 , V_2 -> V_18 ) ;
return F_112 ( V_2 -> V_34 , V_2 -> V_34 -> V_2 -> V_305 ) ;
}
