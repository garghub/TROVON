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
struct V_41 * V_34 = V_2 -> V_34 ;
T_1 V_42 ;
F_3 ( V_2 , V_43 , V_44 , & V_42 ) ;
if ( V_40 )
V_42 |= V_45 ;
else
V_42 &= ~ V_45 ;
F_2 ( V_2 , V_43 , V_44 , V_42 ) ;
if ( V_34 -> V_46 -> V_47 ( V_34 ) == V_48 ) {
F_3 ( V_2 , V_43 , V_49 , & V_42 ) ;
V_42 |= V_50 ;
F_2 ( V_2 , V_43 , V_49 , V_42 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , bool V_40 )
{
T_1 V_42 , V_51 , V_52 , V_53 = 0 , V_54 ;
F_3 ( V_2 , V_43 , V_44 , & V_42 ) ;
F_3 ( V_2 , V_22 , V_55 , & V_51 ) ;
F_3 ( V_2 , V_22 , V_56 , & V_52 ) ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
F_3 ( V_2 , V_22 , V_57 , & V_53 ) ;
F_3 ( V_2 , V_22 , V_58 , & V_54 ) ;
} else if ( F_16 ( V_2 ) ) {
F_3 ( V_2 , V_22 , V_59 , & V_53 ) ;
F_3 ( V_2 , V_22 , V_60 , & V_54 ) ;
} else {
F_3 ( V_2 , V_22 , V_61 , & V_53 ) ;
F_3 ( V_2 , V_22 , V_62 , & V_54 ) ;
}
V_42 &= ~ V_63 ;
if ( V_40 ) {
V_51 |= V_64 | V_65 | V_66 ;
V_52 |= V_67 | V_68 ;
V_53 &= ~ V_69 ;
V_53 |= V_70 << V_71 ;
V_54 |= V_72 ;
if ( F_6 ( V_2 ) )
V_51 &= ~ V_73 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_52 |= V_74 ;
} else {
V_51 &= ~ ( V_64 | V_65 | V_66 ) ;
V_52 &= ~ ( V_67 | V_68 ) ;
V_53 &= ~ V_69 ;
V_54 &= ~ V_72 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_53 |= V_75 << V_71 ;
else
V_53 |= V_76 << V_71 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_52 &= ~ V_74 ;
}
if ( ! F_6 ( V_2 ) && ! F_9 ( V_2 ) )
V_54 &= ~ V_77 ;
F_2 ( V_2 , V_22 , V_55 , V_51 ) ;
F_2 ( V_2 , V_22 , V_56 , V_52 ) ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
if ( F_6 ( V_2 ) && V_40 )
F_2 ( V_2 , V_22 , V_78 ,
V_79 ) ;
else
F_2 ( V_2 , V_22 , V_78 , 0 ) ;
F_2 ( V_2 , V_22 , V_57 , V_53 ) ;
F_2 ( V_2 , V_22 , V_58 , V_54 ) ;
} else if ( F_16 ( V_2 ) ) {
F_8 ( V_2 , V_22 , V_80 , 0 ) ;
F_2 ( V_2 , V_22 , V_59 , V_53 ) ;
F_2 ( V_2 , V_22 , V_60 , V_54 ) ;
} else {
F_8 ( V_2 , V_22 , V_78 , 0 ) ;
F_2 ( V_2 , V_22 , V_61 , V_53 ) ;
F_2 ( V_2 , V_22 , V_62 , V_54 ) ;
}
F_2 ( V_2 , V_43 , V_44 , V_42 ) ;
}
static int F_17 ( struct V_1 * V_2 , bool V_40 , bool V_81 )
{
T_3 V_82 = 0 ;
T_2 V_83 = V_84 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
return - V_85 ;
if ( V_40 ) {
V_82 = V_2 -> V_86 ;
V_83 = V_87 ;
if ( V_81 )
V_82 |= V_88 ;
}
F_7 ( V_2 , V_89 , V_2 -> V_90 , V_82 ) ;
return F_8 ( V_2 , V_89 , V_2 -> V_91 , V_83 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_92 )
{
unsigned int V_4 ;
F_2 ( V_2 , V_43 , V_93 ,
V_94 | V_95 | V_92 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
T_1 V_96 ;
F_3 ( V_2 , V_43 , V_93 ,
& V_96 ) ;
if ( ! ( V_96 & V_94 ) )
goto V_97;
F_19 ( 1 ) ;
}
return - V_98 ;
V_97:
F_2 ( V_2 , V_43 , V_93 , V_95 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_99 )
{
F_2 ( V_2 , V_43 , V_100 , V_99 ) ;
return F_18 ( V_2 , V_101 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_10 )
{
F_8 ( V_2 , V_43 , V_102 , V_10 ) ;
return F_18 ( V_2 , V_103 ) ;
}
static void F_22 ( struct V_41 * V_34 , int V_104 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
unsigned int V_4 ;
T_2 V_106 ;
F_23 (dev, i) {
F_13 ( V_2 , V_107 , F_24 ( V_4 ) , & V_106 ) ;
V_106 |= F_25 ( V_104 ) ;
F_8 ( V_2 , V_107 , F_24 ( V_4 ) , V_106 ) ;
}
}
static int F_26 ( struct V_41 * V_34 , int V_99 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
unsigned int V_104 = V_2 -> V_104 ;
T_2 V_106 ;
F_2 ( V_2 , V_43 , F_27 ( V_99 ) , 0 ) ;
F_13 ( V_2 , V_107 , F_24 ( V_99 ) , & V_106 ) ;
V_106 &= ~ 0x1ff ;
V_106 |= F_25 ( V_99 ) ;
V_106 |= V_2 -> V_110 [ V_99 ] . V_111 ;
F_8 ( V_2 , V_107 , F_24 ( V_99 ) , V_106 ) ;
F_22 ( V_34 , V_104 ) ;
return 0 ;
}
static void F_28 ( struct V_41 * V_34 , int V_99 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_1 V_112 ;
F_3 ( V_2 , V_43 , F_27 ( V_99 ) , & V_112 ) ;
V_112 |= V_113 | V_114 ;
F_2 ( V_2 , V_43 , F_27 ( V_99 ) , V_112 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned int V_104 = V_2 -> V_104 ;
T_1 V_115 ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_104 == V_116 )
V_104 = V_117 ;
V_115 = V_118 |
V_119 |
V_120 ;
F_2 ( V_2 , V_43 , F_27 ( V_104 ) , V_115 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_121 ;
F_3 ( V_2 , V_122 , V_123 , & V_121 ) ;
V_121 &= ~ ( V_124 | V_125 ) ;
F_2 ( V_2 , V_122 , V_123 , V_121 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_11 V_126 = { 0 } ;
int V_4 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) ) {
for ( V_4 = 1 ; V_4 < V_2 -> V_127 ; V_4 ++ )
F_5 ( V_2 , V_4 , & V_126 ) ;
} else {
F_1 ( V_2 , V_128 ) ;
}
F_15 ( V_2 , false ) ;
F_23 (dev, i)
F_8 ( V_2 , V_22 ,
F_32 ( V_4 ) , 1 ) ;
if ( ! F_6 ( V_2 ) && ! F_9 ( V_2 ) )
F_17 ( V_2 , V_2 -> V_129 , false ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_130 = V_2 -> V_131 ;
if ( V_130 < 0 )
return;
F_34 ( V_130 , 0 ) ;
F_35 ( 50 ) ;
F_34 ( V_130 , 1 ) ;
F_35 ( 20 ) ;
V_2 -> V_132 = 0xff ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_133 = 1000 ;
T_1 V_42 , V_112 ;
F_33 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
F_2 ( V_2 , V_43 , V_134 , 0x83 ) ;
F_2 ( V_2 , V_43 , V_134 , 0x00 ) ;
}
if ( V_2 -> V_135 == V_136 ) {
F_3 ( V_2 , V_43 , V_134 , & V_112 ) ;
V_112 |= V_137 | V_138 | V_139 ;
F_2 ( V_2 , V_43 , V_134 , V_112 ) ;
do {
F_3 ( V_2 , V_43 , V_134 , & V_112 ) ;
if ( ! ( V_112 & V_137 ) )
break;
F_4 ( 1000 , 2000 ) ;
} while ( V_133 -- > 0 );
if ( V_133 == 0 )
return - V_98 ;
}
F_3 ( V_2 , V_43 , V_44 , & V_42 ) ;
if ( ! ( V_42 & V_45 ) ) {
V_42 &= ~ V_63 ;
V_42 |= V_45 ;
F_2 ( V_2 , V_43 , V_44 , V_42 ) ;
F_3 ( V_2 , V_43 , V_44 , & V_42 ) ;
if ( ! ( V_42 & V_45 ) ) {
F_38 ( V_2 -> V_2 , L_2 ) ;
return - V_85 ;
}
}
F_30 ( V_2 ) ;
return F_18 ( V_2 , V_140 ) ;
}
static int F_39 ( struct V_41 * V_34 , int V_141 , int V_112 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
T_2 V_142 = 0 ;
int V_143 ;
if ( V_105 -> V_46 -> V_144 )
V_143 = V_105 -> V_46 -> V_144 ( V_105 , V_141 , V_112 , & V_142 ) ;
else
V_143 = F_13 ( V_105 , F_40 ( V_141 ) ,
V_112 * 2 , & V_142 ) ;
return V_143 ? V_143 : V_142 ;
}
static int F_41 ( struct V_41 * V_34 , int V_141 , int V_112 , T_2 V_145 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
if ( V_105 -> V_46 -> V_146 )
return V_105 -> V_46 -> V_146 ( V_105 , V_141 , V_112 , V_145 ) ;
return F_8 ( V_105 , F_40 ( V_141 ) , V_112 * 2 , V_145 ) ;
}
static int F_42 ( struct V_1 * V_105 )
{
V_105 -> V_129 = false ;
memset ( V_105 -> V_147 , 0 , sizeof( * V_105 -> V_147 ) * V_105 -> V_127 ) ;
memset ( V_105 -> V_110 , 0 , sizeof( * V_105 -> V_110 ) * V_105 -> V_148 ) ;
return F_36 ( V_105 ) ;
}
static int F_43 ( struct V_1 * V_105 )
{
F_14 ( V_105 , 0 ) ;
F_31 ( V_105 ) ;
F_14 ( V_105 , 1 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_105 )
{
T_1 V_121 ;
F_3 ( V_105 , V_122 , V_123 , & V_121 ) ;
F_2 ( V_105 , V_122 , V_123 , V_121 | V_124 ) ;
F_19 ( 1 ) ;
F_2 ( V_105 , V_122 , V_123 , V_121 & ~ V_124 ) ;
F_19 ( 1 ) ;
}
static const struct V_149 * F_45 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_150 ;
else if ( F_16 ( V_2 ) )
return V_151 ;
else if ( F_46 ( V_2 ) )
return V_152 ;
else
return V_153 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
return V_154 ;
else if ( F_16 ( V_2 ) )
return V_155 ;
else if ( F_46 ( V_2 ) )
return V_156 ;
else
return V_157 ;
}
void F_48 ( struct V_41 * V_34 , int V_99 , T_4 * V_158 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
const struct V_149 * V_159 = F_45 ( V_2 ) ;
unsigned int V_160 = F_47 ( V_2 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_160 ; V_4 ++ )
memcpy ( V_158 + V_4 * V_161 ,
V_159 [ V_4 ] . V_162 , V_161 ) ;
}
void F_49 ( struct V_41 * V_34 , int V_99 , T_5 * V_158 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
const struct V_149 * V_159 = F_45 ( V_2 ) ;
unsigned int V_160 = F_47 ( V_2 ) ;
const struct V_149 * V_163 ;
unsigned int V_4 ;
T_6 V_145 = 0 ;
if ( F_9 ( V_2 ) && V_99 == 5 )
V_99 = 8 ;
F_50 ( & V_2 -> V_164 ) ;
for ( V_4 = 0 ; V_4 < V_160 ; V_4 ++ ) {
V_163 = & V_159 [ V_4 ] ;
if ( V_163 -> V_165 == 8 ) {
F_51 ( V_2 , F_52 ( V_99 ) , V_163 -> V_166 , & V_145 ) ;
} else {
T_3 V_167 ;
F_12 ( V_2 , F_52 ( V_99 ) , V_163 -> V_166 ,
& V_167 ) ;
V_145 = V_167 ;
}
V_158 [ V_4 ] = ( T_6 ) V_145 ;
}
F_53 ( & V_2 -> V_164 ) ;
}
int F_54 ( struct V_41 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
return F_47 ( V_2 ) ;
}
static int F_55 ( struct V_41 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
unsigned int V_99 ;
int V_143 ;
V_143 = F_42 ( V_2 ) ;
if ( V_143 ) {
F_38 ( V_34 -> V_2 , L_3 ) ;
return V_143 ;
}
F_44 ( V_2 ) ;
V_143 = F_43 ( V_2 ) ;
if ( V_143 )
F_38 ( V_34 -> V_2 , L_4 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_148 ; V_99 ++ ) {
if ( F_25 ( V_99 ) & V_34 -> V_168 )
F_26 ( V_34 , V_99 , NULL ) ;
else if ( F_56 ( V_34 , V_99 ) )
F_29 ( V_2 ) ;
else
F_28 ( V_34 , V_99 , NULL ) ;
}
return V_143 ;
}
static void F_57 ( struct V_41 * V_34 , int V_99 ,
struct V_108 * V_169 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_1 V_170 = 0 , V_112 = 0 , V_171 ;
if ( ! F_58 ( V_169 ) )
return;
if ( V_99 == V_2 -> V_104 ) {
V_171 = V_172 ;
V_112 = V_173 ;
} else {
V_171 = F_59 ( V_99 ) ;
V_112 = V_174 ;
}
if ( V_169 -> V_175 )
V_112 |= V_176 ;
if ( V_169 -> V_177 == V_178 )
V_112 |= V_179 ;
switch ( V_169 -> V_180 ) {
case 2000 :
V_112 |= V_181 ;
case V_182 :
V_112 |= V_183 ;
break;
case V_184 :
V_112 |= V_185 ;
break;
case V_186 :
V_112 |= V_187 ;
break;
default:
F_38 ( V_34 -> V_2 , L_5 , V_169 -> V_180 ) ;
return;
}
if ( F_60 ( V_2 ) && V_99 == V_2 -> V_104 )
V_112 |= V_188 | V_189 ;
if ( V_169 -> V_190 ) {
if ( V_169 -> V_191 )
V_112 |= V_189 ;
V_112 |= V_188 ;
}
F_2 ( V_2 , V_43 , V_171 , V_112 ) ;
if ( F_61 ( V_2 ) && F_62 ( V_169 ) ) {
if ( V_99 == 8 )
V_171 = V_192 ;
else
V_171 = F_63 ( V_99 ) ;
F_3 ( V_2 , V_43 , V_171 , & V_170 ) ;
V_170 &= ~ ( V_193 | V_194 |
V_195 ) ;
if ( V_169 -> V_196 == V_197 )
V_170 |= V_194 ;
if ( V_169 -> V_196 == V_198 )
V_170 |= V_194 | V_193 ;
V_170 |= V_195 ;
F_2 ( V_2 , V_43 , V_171 , V_170 ) ;
F_64 ( V_34 -> V_2 , L_6 , V_99 ,
F_65 ( V_169 -> V_196 ) ) ;
}
if ( F_6 ( V_2 ) ) {
F_3 ( V_2 , V_43 , V_172 ,
& V_112 ) ;
if ( ! ( V_112 & V_199 ) ) {
F_2 ( V_2 , V_43 , V_172 ,
V_112 | V_199 ) ;
F_3 ( V_2 , V_43 , V_172 ,
& V_112 ) ;
if ( ! ( V_112 & V_199 ) ) {
F_38 ( V_34 -> V_2 ,
L_7 ) ;
return;
}
}
} else if ( F_60 ( V_2 ) ) {
if ( V_99 != V_2 -> V_104 ) {
T_1 V_200 = F_59 ( V_2 -> V_104 ) ;
T_1 V_201 ;
F_3 ( V_2 , V_43 , V_200 , & V_201 ) ;
V_201 |= V_202 |
V_203 |
V_204 |
V_174 |
V_205 ;
F_2 ( V_2 , V_43 , V_200 , V_201 ) ;
}
}
}
int F_66 ( struct V_41 * V_34 , int V_99 , bool V_206 )
{
return 0 ;
}
int F_67 ( struct V_41 * V_34 , int V_99 ,
const struct V_207 * V_12 ,
struct V_208 * V_209 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
if ( ( F_6 ( V_2 ) || F_9 ( V_2 ) ) && V_12 -> V_210 == 0 )
return - V_211 ;
if ( V_12 -> V_212 > V_2 -> V_127 )
return - V_213 ;
F_15 ( V_2 , true ) ;
return 0 ;
}
void F_68 ( struct V_41 * V_34 , int V_99 ,
const struct V_207 * V_12 ,
struct V_208 * V_209 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
bool V_214 = V_12 -> V_215 & V_216 ;
bool V_217 = V_12 -> V_215 & V_218 ;
unsigned int V_104 = V_2 -> V_104 ;
struct V_11 * V_126 ;
T_2 V_10 ;
for ( V_10 = V_12 -> V_210 ; V_10 <= V_12 -> V_212 ; ++ V_10 ) {
V_126 = & V_2 -> V_147 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_126 ) ;
V_126 -> V_14 |= F_25 ( V_99 ) | F_25 ( V_104 ) ;
if ( V_214 )
V_126 -> V_15 |= F_25 ( V_99 ) ;
else
V_126 -> V_15 &= ~ F_25 ( V_99 ) ;
V_126 -> V_15 &= ~ F_25 ( V_104 ) ;
F_5 ( V_2 , V_10 , V_126 ) ;
F_21 ( V_2 , V_10 ) ;
}
if ( V_217 ) {
F_8 ( V_2 , V_22 , F_32 ( V_99 ) ,
V_12 -> V_212 ) ;
F_21 ( V_2 , V_10 ) ;
}
}
int F_69 ( struct V_41 * V_34 , int V_99 ,
const struct V_207 * V_12 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
bool V_214 = V_12 -> V_215 & V_216 ;
struct V_11 * V_126 ;
T_2 V_10 ;
T_2 V_217 ;
F_13 ( V_2 , V_22 , F_32 ( V_99 ) , & V_217 ) ;
for ( V_10 = V_12 -> V_210 ; V_10 <= V_12 -> V_212 ; ++ V_10 ) {
V_126 = & V_2 -> V_147 [ V_10 ] ;
F_11 ( V_2 , V_10 , V_126 ) ;
V_126 -> V_14 &= ~ F_25 ( V_99 ) ;
if ( V_217 == V_10 ) {
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_217 = 1 ;
else
V_217 = 0 ;
}
if ( V_214 )
V_126 -> V_15 &= ~ ( F_25 ( V_99 ) ) ;
F_5 ( V_2 , V_10 , V_126 ) ;
F_21 ( V_2 , V_10 ) ;
}
F_8 ( V_2 , V_22 , F_32 ( V_99 ) , V_217 ) ;
F_21 ( V_2 , V_217 ) ;
return 0 ;
}
int F_70 ( struct V_41 * V_34 , int V_99 ,
struct V_207 * V_12 ,
T_7 * V_219 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_2 V_10 , V_220 = 0 , V_217 ;
struct V_11 * V_126 ;
int V_221 = 0 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_220 = 1 ;
F_13 ( V_2 , V_22 , F_32 ( V_99 ) , & V_217 ) ;
for ( V_10 = V_220 ; V_10 < V_2 -> V_127 ; V_10 ++ ) {
V_126 = & V_2 -> V_147 [ V_10 ] ;
if ( ! V_126 -> V_36 )
continue;
if ( ! ( V_126 -> V_14 & F_25 ( V_99 ) ) )
continue;
V_12 -> V_210 = V_12 -> V_212 = V_10 ;
V_12 -> V_215 = 0 ;
if ( V_126 -> V_15 & F_25 ( V_99 ) )
V_12 -> V_215 |= V_216 ;
if ( V_217 == V_10 )
V_12 -> V_215 |= V_218 ;
V_221 = V_219 ( & V_12 -> V_222 ) ;
if ( V_221 )
break;
}
return V_221 ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned int V_133 = 10 ;
T_1 V_112 ;
do {
F_3 ( V_2 , V_5 , V_223 , & V_112 ) ;
if ( ! ( V_112 & V_224 ) )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_133 -- );
F_72 ( V_2 -> V_2 , L_8 , V_112 ) ;
return - V_98 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_112 ;
if ( V_3 > V_225 )
return - V_85 ;
F_3 ( V_2 , V_5 , V_223 , & V_112 ) ;
V_112 |= V_224 ;
if ( V_3 )
V_112 |= V_225 ;
else
V_112 &= ~ V_225 ;
F_2 ( V_2 , V_5 , V_223 , V_112 ) ;
return F_71 ( V_2 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_6 V_226 ,
T_2 V_10 , struct V_227 * V_228 , T_1 * V_229 ,
bool V_230 )
{
unsigned int V_4 ;
int V_143 ;
V_143 = F_71 ( V_2 ) ;
if ( V_143 )
return V_143 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_231 ; V_4 ++ ) {
T_6 V_232 ;
T_3 V_233 ;
F_51 ( V_2 , V_5 ,
F_75 ( V_4 ) , & V_232 ) ;
F_12 ( V_2 , V_5 ,
F_76 ( V_4 ) , & V_233 ) ;
F_77 ( V_228 , V_232 , V_233 ) ;
if ( ! ( V_233 & V_234 ) )
continue;
if ( ( V_232 & V_235 ) != V_226 )
continue;
* V_229 = V_4 ;
}
return - V_236 ;
}
static int F_78 ( struct V_1 * V_2 , int V_3 , int V_99 ,
const unsigned char * V_141 , T_2 V_10 , bool V_230 )
{
struct V_227 V_228 ;
T_3 V_233 ;
T_6 V_226 , V_232 = 0 ;
T_1 V_229 = 0 ;
int V_143 ;
V_226 = F_79 ( V_141 ) ;
F_80 ( V_2 , V_5 , V_237 , V_226 ) ;
F_8 ( V_2 , V_5 , V_238 , V_10 ) ;
V_143 = F_73 ( V_2 , 1 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_74 ( V_2 , V_226 , V_10 , & V_228 , & V_229 , V_230 ) ;
if ( V_3 )
return V_143 ;
if ( V_143 ) {
V_233 = 0 ;
V_229 = 1 ;
}
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_99 = V_99 ;
V_228 . V_230 = V_230 ;
V_228 . V_10 = V_10 ;
V_228 . V_239 = true ;
memcpy ( V_228 . V_226 , V_141 , V_240 ) ;
F_81 ( & V_232 , & V_233 , & V_228 ) ;
F_82 ( V_2 , V_5 ,
F_75 ( V_229 ) , V_232 ) ;
F_7 ( V_2 , V_5 ,
F_76 ( V_229 ) , V_233 ) ;
return F_73 ( V_2 , 0 ) ;
}
int F_83 ( struct V_41 * V_34 , int V_99 ,
const struct V_241 * V_242 ,
struct V_208 * V_209 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
if ( F_6 ( V_105 ) || F_9 ( V_105 ) )
return - V_211 ;
return 0 ;
}
void F_84 ( struct V_41 * V_34 , int V_99 ,
const struct V_241 * V_242 ,
struct V_208 * V_209 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
if ( F_78 ( V_105 , 0 , V_99 , V_242 -> V_141 , V_242 -> V_10 , true ) )
F_85 ( L_9 , V_243 ) ;
}
int F_86 ( struct V_41 * V_34 , int V_99 ,
const struct V_241 * V_242 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
return F_78 ( V_105 , 0 , V_99 , V_242 -> V_141 , V_242 -> V_10 , false ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
unsigned int V_133 = 1000 ;
T_1 V_112 ;
do {
F_3 ( V_2 , V_5 , V_244 , & V_112 ) ;
if ( ! ( V_112 & V_245 ) )
return 0 ;
if ( V_112 & V_246 )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_133 -- );
return - V_98 ;
}
static void F_88 ( struct V_1 * V_2 , T_1 V_229 ,
struct V_227 * V_228 )
{
T_6 V_232 ;
T_3 V_233 ;
F_51 ( V_2 , V_5 ,
F_89 ( V_229 ) , & V_232 ) ;
F_12 ( V_2 , V_5 ,
F_90 ( V_229 ) , & V_233 ) ;
F_77 ( V_228 , V_232 , V_233 ) ;
}
static int F_91 ( int V_99 , const struct V_227 * V_228 ,
struct V_241 * V_242 ,
T_7 * V_219 )
{
if ( ! V_228 -> V_230 )
return 0 ;
if ( V_99 != V_228 -> V_99 )
return 0 ;
F_92 ( V_242 -> V_141 , V_228 -> V_226 ) ;
V_242 -> V_10 = V_228 -> V_10 ;
V_242 -> V_247 = V_228 -> V_239 ? V_248 : V_249 ;
return V_219 ( & V_242 -> V_222 ) ;
}
int F_93 ( struct V_41 * V_34 , int V_99 ,
struct V_241 * V_242 ,
T_7 * V_219 )
{
struct V_1 * V_105 = V_34 -> V_105 ;
struct V_227 V_250 [ 2 ] ;
unsigned int V_251 = 0 ;
int V_143 ;
T_1 V_112 ;
V_112 = V_245 ;
F_2 ( V_105 , V_5 , V_244 , V_112 ) ;
do {
V_143 = F_87 ( V_105 ) ;
if ( V_143 )
return V_143 ;
F_88 ( V_105 , 0 , & V_250 [ 0 ] ) ;
V_143 = F_91 ( V_99 , & V_250 [ 0 ] , V_242 , V_219 ) ;
if ( V_143 )
return V_143 ;
if ( V_105 -> V_231 > 2 ) {
F_88 ( V_105 , 1 , & V_250 [ 1 ] ) ;
V_143 = F_91 ( V_99 , & V_250 [ 1 ] , V_242 , V_219 ) ;
if ( V_143 )
return V_143 ;
if ( ! V_250 [ 0 ] . V_230 && ! V_250 [ 1 ] . V_230 )
break;
}
} while ( V_251 ++ < 1024 );
return 0 ;
}
int F_94 ( struct V_41 * V_34 , int V_99 , struct V_252 * V_253 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_8 V_104 = V_34 -> V_254 -> V_255 -> V_256 ;
T_2 V_106 , V_112 ;
unsigned int V_4 ;
if ( F_46 ( V_2 ) ) {
F_13 ( V_2 , V_22 , V_257 , & V_112 ) ;
V_112 &= ~ F_25 ( V_99 ) ;
if ( ( V_112 & F_25 ( V_104 ) ) == F_25 ( V_104 ) )
V_112 &= ~ F_25 ( V_104 ) ;
F_8 ( V_2 , V_22 , V_257 , V_112 ) ;
}
F_13 ( V_2 , V_107 , F_24 ( V_99 ) , & V_106 ) ;
F_23 (dev, i) {
if ( V_34 -> V_110 [ V_4 ] . V_258 != V_253 )
continue;
F_13 ( V_2 , V_107 , F_24 ( V_4 ) , & V_112 ) ;
V_112 |= F_25 ( V_99 ) ;
F_8 ( V_2 , V_107 , F_24 ( V_4 ) , V_112 ) ;
V_2 -> V_110 [ V_4 ] . V_111 = V_112 ;
V_106 |= F_25 ( V_4 ) ;
}
F_8 ( V_2 , V_107 , F_24 ( V_99 ) , V_106 ) ;
V_2 -> V_110 [ V_99 ] . V_111 = V_106 ;
return 0 ;
}
void F_95 ( struct V_41 * V_34 , int V_99 , struct V_252 * V_253 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
struct V_11 * V_126 = & V_2 -> V_147 [ 0 ] ;
T_8 V_104 = V_34 -> V_254 -> V_255 -> V_256 ;
unsigned int V_4 ;
T_2 V_106 , V_112 , V_217 ;
F_13 ( V_2 , V_107 , F_24 ( V_99 ) , & V_106 ) ;
F_23 (dev, i) {
if ( V_34 -> V_110 [ V_4 ] . V_258 != V_253 )
continue;
F_13 ( V_2 , V_107 , F_24 ( V_4 ) , & V_112 ) ;
V_112 &= ~ F_25 ( V_99 ) ;
F_8 ( V_2 , V_107 , F_24 ( V_4 ) , V_112 ) ;
V_2 -> V_110 [ V_99 ] . V_111 = V_112 ;
if ( V_99 != V_4 )
V_106 &= ~ F_25 ( V_4 ) ;
}
F_8 ( V_2 , V_107 , F_24 ( V_99 ) , V_106 ) ;
V_2 -> V_110 [ V_99 ] . V_111 = V_106 ;
if ( F_6 ( V_2 ) || F_9 ( V_2 ) )
V_217 = 1 ;
else
V_217 = 0 ;
if ( F_46 ( V_2 ) ) {
F_13 ( V_2 , V_22 , V_257 , & V_112 ) ;
V_112 |= F_25 ( V_99 ) ;
if ( ! ( V_112 & F_25 ( V_104 ) ) )
V_112 |= F_25 ( V_104 ) ;
F_8 ( V_2 , V_22 , V_257 , V_112 ) ;
} else {
F_11 ( V_2 , V_217 , V_126 ) ;
V_126 -> V_14 |= F_25 ( V_99 ) | F_25 ( V_2 -> V_104 ) ;
V_126 -> V_15 |= F_25 ( V_99 ) | F_25 ( V_2 -> V_104 ) ;
F_5 ( V_2 , V_217 , V_126 ) ;
}
}
void F_96 ( struct V_41 * V_34 , int V_99 , T_1 V_259 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_1 V_260 ;
T_1 V_112 ;
switch ( V_259 ) {
case V_261 :
V_260 = V_262 ;
break;
case V_263 :
V_260 = V_264 ;
break;
case V_265 :
V_260 = V_266 ;
break;
case V_267 :
V_260 = V_268 ;
break;
case V_269 :
V_260 = V_270 ;
break;
default:
F_38 ( V_34 -> V_2 , L_10 , V_259 ) ;
return;
}
F_3 ( V_2 , V_43 , F_27 ( V_99 ) , & V_112 ) ;
V_112 &= ~ V_271 ;
V_112 |= V_260 ;
F_2 ( V_2 , V_43 , F_27 ( V_99 ) , V_112 ) ;
}
void F_97 ( struct V_41 * V_34 , int V_99 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
if ( F_20 ( V_2 , V_99 ) )
F_38 ( V_34 -> V_2 , L_11 ) ;
}
static enum V_272 F_98 ( struct V_41 * V_34 )
{
return V_48 ;
}
int F_99 ( struct V_41 * V_34 , int V_99 ,
struct V_273 * V_274 , bool V_275 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
T_2 V_112 , V_276 ;
if ( V_275 )
V_276 = V_277 ;
else
V_276 = V_278 ;
F_13 ( V_2 , V_122 , V_276 , & V_112 ) ;
V_112 &= ~ V_279 ;
V_112 |= F_25 ( V_99 ) ;
F_8 ( V_2 , V_122 , V_276 , V_112 ) ;
F_13 ( V_2 , V_122 , V_280 , & V_112 ) ;
V_112 &= ~ V_281 ;
V_112 |= V_274 -> V_282 ;
V_112 |= V_283 ;
F_8 ( V_2 , V_122 , V_280 , V_112 ) ;
return 0 ;
}
void F_100 ( struct V_41 * V_34 , int V_99 ,
struct V_273 * V_274 )
{
struct V_1 * V_2 = V_34 -> V_105 ;
bool V_284 = false , V_285 = false ;
T_2 V_112 , V_276 ;
if ( V_274 -> V_275 )
V_276 = V_277 ;
else
V_276 = V_278 ;
F_13 ( V_2 , V_122 , V_276 , & V_112 ) ;
V_112 &= ~ F_25 ( V_99 ) ;
if ( ! ( V_112 & V_279 ) )
V_284 = true ;
F_8 ( V_2 , V_122 , V_276 , V_112 ) ;
if ( V_274 -> V_275 )
F_13 ( V_2 , V_122 , V_278 , & V_112 ) ;
else
F_13 ( V_2 , V_122 , V_277 , & V_112 ) ;
if ( ! ( V_112 & V_279 ) )
V_285 = true ;
F_13 ( V_2 , V_122 , V_280 , & V_112 ) ;
if ( V_284 && V_285 ) {
V_112 &= ~ V_283 ;
V_112 &= ~ V_274 -> V_282 ;
}
F_8 ( V_2 , V_122 , V_280 , V_112 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
int V_143 ;
for ( V_4 = 0 ; V_4 < F_102 ( V_286 ) ; V_4 ++ ) {
const struct V_287 * V_288 = & V_286 [ V_4 ] ;
if ( V_288 -> V_135 == V_2 -> V_135 ) {
if ( ! V_2 -> V_86 )
V_2 -> V_86 = V_288 -> V_86 ;
V_2 -> V_162 = V_288 -> V_289 ;
V_2 -> V_290 = V_288 -> V_290 ;
V_2 -> V_6 [ 0 ] = V_288 -> V_6 [ 0 ] ;
V_2 -> V_6 [ 1 ] = V_288 -> V_6 [ 1 ] ;
V_2 -> V_6 [ 2 ] = V_288 -> V_6 [ 2 ] ;
V_2 -> V_90 = V_288 -> V_90 ;
V_2 -> V_104 = V_288 -> V_104 ;
V_2 -> V_127 = V_288 -> V_147 ;
V_2 -> V_231 = V_288 -> V_291 ;
break;
}
}
if ( F_6 ( V_2 ) ) {
T_1 V_53 ;
F_3 ( V_2 , V_22 , V_57 , & V_53 ) ;
switch ( V_53 & 3 ) {
case 1 :
break;
case 3 :
V_2 -> V_86 &= ~ F_25 ( 4 ) ;
break;
default:
#ifndef F_103
return - V_85 ;
#else
break;
#endif
}
} else if ( V_2 -> V_135 == V_292 ) {
T_6 V_293 ;
F_104 ( V_2 , V_294 , V_295 , & V_293 ) ;
if ( V_293 & V_296 )
V_2 -> V_104 = 5 ;
}
V_2 -> V_148 = V_2 -> V_104 + 1 ;
V_2 -> V_86 |= F_25 ( V_2 -> V_104 ) ;
V_2 -> V_110 = F_105 ( V_2 -> V_2 ,
sizeof( struct V_297 ) * V_2 -> V_148 ,
V_298 ) ;
if ( ! V_2 -> V_110 )
return - V_299 ;
V_2 -> V_147 = F_105 ( V_2 -> V_2 ,
sizeof( struct V_11 ) * V_2 -> V_127 ,
V_298 ) ;
if ( ! V_2 -> V_147 )
return - V_299 ;
V_2 -> V_131 = F_106 ( V_2 ) ;
if ( V_2 -> V_131 >= 0 ) {
V_143 = F_107 ( V_2 -> V_2 , V_2 -> V_131 ,
V_300 , L_12 ) ;
if ( V_143 )
return V_143 ;
}
return 0 ;
}
struct V_1 * F_108 ( struct V_301 * V_302 ,
const struct V_303 * V_46 ,
void * V_105 )
{
struct V_41 * V_34 ;
struct V_1 * V_2 ;
V_34 = F_109 ( V_302 , V_304 ) ;
if ( ! V_34 )
return NULL ;
V_2 = F_105 ( V_302 , sizeof( * V_2 ) , V_298 ) ;
if ( ! V_2 )
return NULL ;
V_34 -> V_105 = V_2 ;
V_2 -> V_2 = V_302 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_46 = V_46 ;
V_34 -> V_46 = & V_305 ;
F_110 ( & V_2 -> V_306 ) ;
F_110 ( & V_2 -> V_164 ) ;
return V_2 ;
}
int F_111 ( struct V_1 * V_2 )
{
T_3 V_307 ;
T_2 V_308 ;
T_1 V_309 ;
int V_143 ;
V_143 = F_3 ( V_2 , V_122 , V_310 , & V_309 ) ;
if ( V_143 )
return V_143 ;
switch ( V_309 ) {
case 0 :
F_8 ( V_2 , V_22 , V_24 , 0xf ) ;
F_13 ( V_2 , V_22 , V_24 , & V_308 ) ;
if ( V_308 == 0xf )
V_2 -> V_135 = V_311 ;
else
V_2 -> V_135 = V_312 ;
break;
case V_313 :
case V_314 :
case V_315 :
V_2 -> V_135 = V_309 ;
break;
default:
V_143 = F_12 ( V_2 , V_122 , V_310 , & V_307 ) ;
if ( V_143 )
return V_143 ;
switch ( V_307 ) {
case V_292 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
V_2 -> V_135 = V_307 ;
break;
default:
F_85 ( L_13 ,
V_309 , V_307 ) ;
return - V_323 ;
}
}
if ( V_2 -> V_135 == V_311 )
return F_3 ( V_2 , V_294 , V_324 ,
& V_2 -> V_18 ) ;
else
return F_3 ( V_2 , V_122 , V_325 ,
& V_2 -> V_18 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_143 ;
if ( V_2 -> V_326 ) {
V_2 -> V_135 = V_2 -> V_326 -> V_135 ;
V_2 -> V_86 = V_2 -> V_326 -> V_86 ;
}
if ( ! V_2 -> V_135 && F_111 ( V_2 ) )
return - V_85 ;
V_143 = F_101 ( V_2 ) ;
if ( V_143 )
return V_143 ;
F_113 ( L_14 , V_2 -> V_162 , V_2 -> V_18 ) ;
return F_114 ( V_2 -> V_34 ) ;
}
