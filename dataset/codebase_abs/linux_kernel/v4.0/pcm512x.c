static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
return true ;
default:
return V_3 < 0xff ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_70 :
return true ;
default:
return V_3 < 0xff ;
}
}
static int F_3 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 V_78 [ 2 ] ;
int V_79 ;
V_79 = F_4 ( V_74 ) ;
if ( V_79 < 0 )
return V_79 ;
switch ( V_79 ) {
case 32 :
return 0 ;
case 48 :
case 64 :
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
V_78 [ 0 ] . V_80 = 8000 ;
V_78 [ 0 ] . V_81 = 25000000 / V_79 / 2 ;
V_78 [ 1 ] . V_80 = F_5 ( 16000000 , V_79 ) ;
V_78 [ 1 ] . V_81 = 384000 ;
break;
default:
return - V_82 ;
}
return F_6 ( F_7 ( V_74 , V_76 -> V_83 ) ,
F_8 ( V_78 ) , V_78 , 0 ) ;
}
static int F_9 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
if ( F_11 ( V_91 -> V_96 ) ) {
F_12 ( V_2 , L_1 ,
F_13 ( V_91 -> V_96 ) ) ;
return F_13 ( V_91 -> V_96 ) ;
}
if ( V_91 -> V_97 )
return F_14 ( V_85 -> V_98 , 0 ,
V_99 ,
F_3 ,
NULL ,
V_100 ,
V_101 , - 1 ) ;
V_93 = F_15 ( V_2 , sizeof( * V_93 ) ,
V_102 ) ;
if ( ! V_93 )
return - V_103 ;
V_93 -> V_104 = 1 ;
V_95 = F_15 ( V_2 , sizeof( * V_95 ) , V_102 ) ;
if ( ! V_95 )
return - V_103 ;
V_93 -> V_105 = V_95 ;
V_95 -> V_106 = F_16 ( V_91 -> V_96 ) / 64 ;
V_95 -> V_107 = 1 ;
V_95 -> V_108 = 128 ;
V_95 -> V_109 = 1 ;
return V_92 ( V_85 -> V_98 , 0 ,
V_99 ,
V_93 ) ;
}
static int F_17 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_110 * V_110 = V_91 -> V_110 ;
if ( F_11 ( V_91 -> V_96 ) ) {
F_18 ( V_2 , L_2 ,
F_13 ( V_91 -> V_96 ) ) ;
F_19 ( V_110 , V_33 ,
V_111 , V_111 ) ;
F_19 ( V_110 , V_14 ,
V_112 , V_113 ) ;
}
return F_20 ( V_85 -> V_98 , 0 ,
V_99 ,
& V_114 ) ;
}
static int F_21 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
switch ( V_91 -> V_115 & V_116 ) {
case V_117 :
case V_118 :
return F_9 ( V_85 , V_87 ) ;
case V_119 :
return F_17 ( V_85 , V_87 ) ;
default:
return - V_82 ;
}
}
static int F_22 ( struct V_88 * V_89 ,
enum V_120 V_121 )
{
struct V_90 * V_91 = F_23 ( V_89 -> V_2 ) ;
int V_122 ;
switch ( V_121 ) {
case V_123 :
case V_124 :
break;
case V_125 :
V_122 = F_19 ( V_91 -> V_110 , V_5 ,
V_126 , 0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_3 ,
V_122 ) ;
return V_122 ;
}
break;
case V_127 :
V_122 = F_19 ( V_91 -> V_110 , V_5 ,
V_126 , V_126 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_4 ,
V_122 ) ;
return V_122 ;
}
break;
}
V_89 -> V_128 . V_129 = V_121 ;
return 0 ;
}
static unsigned long F_24 ( struct V_86 * V_87 ,
unsigned long V_130 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
unsigned long V_131 ;
int V_132 ;
V_132 = 1 << F_25 ( ( 25000000 - 16000000 ) / V_130 ) ;
for (; V_132 ; V_132 >>= 1 ) {
V_131 = F_26 ( 25000000 , V_130 * V_132 ) ;
if ( V_131 >= 16000000 )
break;
}
if ( ! V_132 ) {
F_12 ( V_2 , L_5 ) ;
return 0 ;
}
F_27 ( V_2 , L_6 , V_131 ) ;
return V_131 ;
}
static int F_28 ( struct V_86 * V_87 ,
unsigned long V_133 ,
unsigned long V_134 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
unsigned long V_135 ;
int V_136 , V_137 , V_138 , V_139 ;
unsigned long V_140 ;
unsigned long V_106 ;
unsigned long V_141 ;
V_135 = F_29 ( V_134 , V_133 ) ;
F_27 ( V_2 , L_7 ,
V_134 , V_133 , V_135 ) ;
V_106 = V_134 / V_135 ;
V_141 = V_133 / V_135 ;
if ( V_133 / V_141 > 20000000 && V_106 < 8 ) {
V_106 *= 20000000 / ( V_133 / V_141 ) ;
V_141 *= 20000000 / ( V_133 / V_141 ) ;
}
F_27 ( V_2 , L_8 , V_106 , V_141 ) ;
V_139 = V_141 ;
if ( V_141 <= 15 && V_106 <= 16 * 63
&& 1000000 <= V_133 / V_139 && V_133 / V_139 <= 20000000 ) {
V_138 = 0 ;
for ( V_136 = 16 ; V_136 ; V_136 -- ) {
if ( V_106 % V_136 )
continue;
V_137 = V_106 / V_136 ;
if ( V_137 == 0 || V_137 > 63 )
continue;
F_27 ( V_2 , L_9 , V_136 , V_137 , V_139 ) ;
V_91 -> V_142 = V_134 ;
goto V_143;
}
}
V_136 = 1 ;
if ( V_106 > 0xffffffffUL / 10000 )
goto V_144;
V_135 = F_29 ( 10000 * V_106 , V_141 ) ;
V_106 = 10000 * V_106 / V_135 ;
V_141 /= V_135 ;
F_27 ( V_2 , L_10 , V_106 , V_141 , V_135 ) ;
for ( V_139 = V_141 ; V_139 <= 15 ; V_139 ++ ) {
if ( V_133 / V_139 < 6667000 || 200000000 < V_133 / V_139 )
continue;
if ( V_106 * V_139 % V_141 )
continue;
V_140 = V_106 * V_139 / V_141 ;
if ( V_140 < 40000 || V_140 > 120000 )
continue;
V_137 = V_140 / 10000 ;
V_138 = V_140 % 10000 ;
F_27 ( V_2 , L_11 , V_137 , V_138 , V_139 ) ;
V_91 -> V_142 = V_134 ;
goto V_143;
}
V_144:
V_139 = F_5 ( V_133 , 20000000 ) ;
if ( ! V_139 )
V_139 = 1 ;
else if ( V_139 > 15 ) {
F_12 ( V_2 , L_12 ) ;
return - V_82 ;
}
if ( V_133 / V_139 < 6667000 ) {
F_12 ( V_2 , L_13 ) ;
return - V_82 ;
}
V_140 = F_30 ( 10000ULL * V_134 * V_139 , V_133 ) ;
if ( V_140 < 40000 )
V_140 = 40000 ;
if ( V_140 > 120000 )
V_140 = 120000 ;
V_137 = V_140 / 10000 ;
V_138 = V_140 % 10000 ;
F_27 ( V_2 , L_14 , V_137 , V_138 , V_139 ) ;
V_91 -> V_142 = F_31 ( ( V_145 ) V_140 * V_133 , 10000 * V_139 ) ;
V_143:
V_91 -> V_146 = V_136 ;
V_91 -> V_147 = V_137 ;
V_91 -> V_148 = V_138 ;
V_91 -> V_149 = V_139 ;
return 0 ;
}
static unsigned long F_32 ( struct V_86 * V_87 ,
unsigned long V_150 ,
unsigned long V_133 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
unsigned long V_151 ;
if ( ! V_91 -> V_97 )
return 0 ;
if ( V_133 % V_150 )
return 0 ;
for ( V_151 = F_26 ( 6144000 , V_150 ) ;
V_151 ;
V_151 -= V_150 ) {
if ( V_133 / V_151 > 128 )
return 0 ;
if ( ! ( V_133 % V_151 ) )
return V_151 ;
V_151 -= V_150 ;
}
return 0 ;
}
static int F_33 ( struct V_86 * V_87 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
unsigned long V_133 = 0 ;
unsigned long V_134 ;
unsigned long V_131 ;
unsigned long V_152 ;
unsigned long V_130 ;
unsigned long V_153 ;
unsigned long V_150 ;
unsigned long V_154 ;
int V_155 ;
int V_156 ;
int V_157 ;
int V_158 ;
unsigned long V_151 ;
int V_159 ;
int V_160 ;
int V_122 ;
int V_161 ;
int V_162 ;
int V_163 ;
V_156 = F_4 ( V_74 ) ;
if ( V_156 == 0 ) {
F_12 ( V_2 , L_15 ) ;
return - V_82 ;
}
if ( ! V_91 -> V_97 ) {
V_131 = F_16 ( V_91 -> V_96 ) ;
V_155 = V_74 -> V_164 * 64 / V_156 ;
V_130 = F_34 ( V_131 , V_155 ) ;
V_152 = V_131 ;
} else {
V_122 = F_35 ( V_74 ) ;
if ( V_122 < 0 ) {
F_12 ( V_2 , L_16 , V_122 ) ;
return V_122 ;
}
if ( V_122 == 0 ) {
F_12 ( V_2 , L_17 ) ;
return - V_82 ;
}
V_130 = V_122 ;
V_133 = F_16 ( V_91 -> V_96 ) ;
V_131 = F_24 ( V_87 , V_130 ) ;
if ( ! V_131 )
return - V_82 ;
V_134 = 4 * V_131 ;
V_122 = F_28 ( V_87 , V_133 , V_134 ) ;
if ( V_122 != 0 )
return V_122 ;
V_122 = F_36 ( V_91 -> V_110 ,
V_19 , V_91 -> V_149 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_18 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_20 , V_91 -> V_147 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_19 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_21 , V_91 -> V_148 >> 8 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_20 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_22 , V_91 -> V_148 & 0xff ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_21 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_23 , V_91 -> V_146 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_22 , V_122 ) ;
return V_122 ;
}
V_152 = V_91 -> V_142 ;
V_155 = F_34 ( V_131 , V_130 ) ;
}
if ( V_155 > 128 ) {
F_12 ( V_2 , L_23 ) ;
return - V_82 ;
}
V_153 = V_131 / V_155 / V_156 ;
V_150 = 16 * V_153 ;
V_157 = V_152 > 50000000 ? 2 : 1 ;
V_151 = F_32 ( V_87 , V_150 , V_133 ) ;
if ( V_151 ) {
F_27 ( V_2 , L_24 ) ;
V_122 = F_19 ( V_91 -> V_110 , V_15 ,
V_165 , V_166 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_25 , V_122 ) ;
return V_122 ;
}
V_163 = V_167 + V_91 -> V_168 - 1 ;
V_122 = F_19 ( V_91 -> V_110 , V_16 ,
V_169 , V_163 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_26 ,
V_91 -> V_168 , V_122 ) ;
return V_122 ;
}
V_154 = V_133 ;
} else {
unsigned long V_170 = 6144000 / V_150 ;
unsigned long V_171 = V_131 / V_150 ;
for (; V_170 ; V_170 -- ) {
if ( ! ( V_171 % V_170 ) )
break;
}
if ( ! V_170 ) {
F_12 ( V_2 , L_27 ) ;
return - V_82 ;
}
V_151 = V_170 * V_150 ;
F_27 ( V_2 , L_28 ,
V_151 , V_153 ) ;
V_122 = F_19 ( V_91 -> V_110 , V_15 ,
V_165 , V_172 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_29 , V_122 ) ;
return V_122 ;
}
V_154 = V_131 ;
}
V_158 = F_34 ( V_154 , V_151 ) ;
if ( V_158 > 128 ) {
F_12 ( V_2 , L_30 ) ;
return - V_82 ;
}
V_159 = F_34 ( V_154 / V_158 , 1536000 ) ;
if ( V_159 > 128 || V_154 / V_158 / V_159 > 2048000 ) {
V_159 = F_5 ( V_154 / V_158 , 2048000 ) ;
if ( V_159 > 128 ) {
F_12 ( V_2 , L_31 ) ;
return - V_82 ;
}
}
V_160 = F_34 ( V_151 , V_150 ) ;
if ( V_160 > 128 ) {
F_12 ( V_2 , L_32 ) ;
return - V_82 ;
}
V_161 = V_152 / ( V_157 * V_153 ) ;
V_122 = F_36 ( V_91 -> V_110 , V_24 , V_157 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_33 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_25 , V_158 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_34 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_26 , V_159 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_35 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_27 , V_160 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_36 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_28 , V_155 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_37 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 ,
V_29 , V_156 - 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_38 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_31 , V_161 >> 8 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_39 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_32 , V_161 & 0xff ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_40 , V_122 ) ;
return V_122 ;
}
if ( V_153 <= 48000 )
V_162 = V_173 ;
else if ( V_153 <= 96000 )
V_162 = V_174 ;
else if ( V_153 <= 192000 )
V_162 = V_175 ;
else
V_162 = V_176 ;
V_122 = F_19 ( V_91 -> V_110 , V_30 ,
V_177 , V_162 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_41 , V_122 ) ;
return V_122 ;
}
F_27 ( V_89 -> V_2 , L_42 , V_157 ) ;
F_27 ( V_89 -> V_2 , L_43 , V_158 ) ;
F_27 ( V_89 -> V_2 , L_44 , V_159 ) ;
F_27 ( V_89 -> V_2 , L_45 , V_160 ) ;
F_27 ( V_89 -> V_2 , L_46 , V_155 ) ;
F_27 ( V_89 -> V_2 , L_47 , V_156 ) ;
F_27 ( V_89 -> V_2 , L_48 , V_161 ) ;
F_27 ( V_89 -> V_2 , L_49 , 1 << V_162 ) ;
return 0 ;
}
static int F_37 ( struct V_84 * V_85 ,
struct V_73 * V_74 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
int V_178 ;
int V_163 ;
int V_179 ;
int V_180 ;
int V_122 ;
F_27 ( V_89 -> V_2 , L_50 ,
F_38 ( V_74 ) ,
F_39 ( V_74 ) ) ;
switch ( F_40 ( F_41 ( V_74 ) ) ) {
case 16 :
V_178 = V_181 ;
break;
case 20 :
V_178 = V_182 ;
break;
case 24 :
V_178 = V_183 ;
break;
case 32 :
V_178 = V_184 ;
break;
default:
F_12 ( V_89 -> V_2 , L_51 ,
F_40 ( F_41 ( V_74 ) ) ) ;
return - V_82 ;
}
switch ( V_91 -> V_115 & V_116 ) {
case V_119 :
V_122 = F_19 ( V_91 -> V_110 ,
V_11 ,
V_185
| V_186 | V_187 ,
0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_52 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_33 ,
V_188 , 0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_53 ,
V_122 ) ;
return V_122 ;
}
return 0 ;
case V_117 :
V_179 = V_186 | V_187 ;
V_180 = V_189 | V_190 ;
break;
case V_118 :
V_179 = V_186 ;
V_180 = V_190 ;
break;
default:
return - V_82 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_34 ,
V_191 , V_178 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_54 , V_122 ) ;
return V_122 ;
}
if ( V_91 -> V_97 ) {
V_122 = F_36 ( V_91 -> V_110 , V_71 , 0x11 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_55 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_91 -> V_110 , V_72 , 0xff ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_56 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_33 ,
V_192 | V_193
| V_194 | V_111
| V_195 | V_188
| V_196 ,
V_192 | V_193
| V_194 | V_111
| V_188 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_57 ,
V_122 ) ;
return V_122 ;
}
} else {
V_122 = F_19 ( V_91 -> V_110 , V_33 ,
V_192 | V_193
| V_194 | V_111
| V_195 | V_188
| V_196 ,
V_192 | V_193
| V_194 | V_111
| V_188 | V_196 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_57 ,
V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_7 ,
V_197 , 0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_58 , V_122 ) ;
return V_122 ;
}
}
V_122 = F_33 ( V_87 , V_74 ) ;
if ( V_122 != 0 )
return V_122 ;
if ( V_91 -> V_97 ) {
V_122 = F_19 ( V_91 -> V_110 , V_14 ,
V_112 , V_198 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_59 , V_122 ) ;
return V_122 ;
}
V_163 = V_167 + V_91 -> V_168 - 1 ;
V_122 = F_19 ( V_91 -> V_110 , V_17 ,
V_169 , V_163 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 ,
L_60 ,
V_91 -> V_168 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_7 ,
V_197 , V_197 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_61 , V_122 ) ;
return V_122 ;
}
}
V_122 = F_19 ( V_91 -> V_110 , V_11 ,
V_185 | V_186 | V_187 ,
V_179 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_62 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_13 ,
V_189 | V_190 ,
V_180 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_63 , V_122 ) ;
return V_122 ;
}
if ( V_91 -> V_97 ) {
V_163 = V_199 << ( V_91 -> V_97 - 1 ) ;
V_122 = F_19 ( V_91 -> V_110 , V_10 ,
V_163 , V_163 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_64 ,
V_91 -> V_97 , V_122 ) ;
return V_122 ;
}
V_163 = V_46 + V_91 -> V_97 - 1 ;
V_122 = F_19 ( V_91 -> V_110 , V_163 ,
V_200 , V_201 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_65 ,
V_122 , V_91 -> V_97 ) ;
return V_122 ;
}
}
V_122 = F_19 ( V_91 -> V_110 , V_18 ,
V_202 , V_203 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_66 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_18 ,
V_202 , V_204 ) ;
if ( V_122 != 0 ) {
F_12 ( V_89 -> V_2 , L_67 , V_122 ) ;
return V_122 ;
}
return 0 ;
}
static int F_42 ( struct V_86 * V_87 , unsigned int V_115 )
{
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_90 * V_91 = F_10 ( V_89 ) ;
V_91 -> V_115 = V_115 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , struct V_110 * V_110 )
{
struct V_90 * V_91 ;
int V_205 , V_122 ;
V_91 = F_15 ( V_2 , sizeof( struct V_90 ) , V_102 ) ;
if ( ! V_91 )
return - V_103 ;
F_44 ( V_2 , V_91 ) ;
V_91 -> V_110 = V_110 ;
for ( V_205 = 0 ; V_205 < F_8 ( V_91 -> V_206 ) ; V_205 ++ )
V_91 -> V_206 [ V_205 ] . V_207 = V_208 [ V_205 ] ;
V_122 = F_45 ( V_2 , F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_68 , V_122 ) ;
return V_122 ;
}
V_91 -> V_209 [ 0 ] . V_210 = V_211 ;
V_91 -> V_209 [ 1 ] . V_210 = V_212 ;
V_91 -> V_209 [ 2 ] . V_210 = V_213 ;
for ( V_205 = 0 ; V_205 < F_8 ( V_91 -> V_206 ) ; V_205 ++ ) {
V_122 = F_46 ( V_91 -> V_206 [ V_205 ] . V_214 ,
& V_91 -> V_209 [ V_205 ] ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 ,
L_69 ,
V_122 ) ;
}
}
V_122 = F_47 ( F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_70 , V_122 ) ;
return V_122 ;
}
V_122 = F_36 ( V_110 , V_4 ,
V_215 | V_216 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_71 , V_122 ) ;
goto V_217;
}
V_122 = F_36 ( V_110 , V_4 , 0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_71 , V_122 ) ;
goto V_217;
}
V_91 -> V_96 = F_48 ( V_2 , NULL ) ;
if ( F_13 ( V_91 -> V_96 ) == - V_218 )
return - V_218 ;
if ( ! F_11 ( V_91 -> V_96 ) ) {
V_122 = F_49 ( V_91 -> V_96 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_72 , V_122 ) ;
return V_122 ;
}
}
V_122 = F_19 ( V_91 -> V_110 , V_5 ,
V_126 , V_126 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_4 ,
V_122 ) ;
goto V_219;
}
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
#ifdef F_53
if ( V_2 -> V_220 ) {
const struct V_221 * V_222 = V_2 -> V_220 ;
T_1 V_223 ;
if ( F_54 ( V_222 , L_73 , & V_223 ) >= 0 ) {
if ( V_223 > 6 ) {
F_12 ( V_2 , L_74 ) ;
V_122 = - V_82 ;
goto V_219;
}
V_91 -> V_168 = V_223 ;
}
if ( F_54 ( V_222 , L_75 , & V_223 ) >= 0 ) {
if ( V_223 > 6 ) {
F_12 ( V_2 , L_76 ) ;
V_122 = - V_82 ;
goto V_219;
}
V_91 -> V_97 = V_223 ;
}
if ( ! V_91 -> V_168 != ! V_91 -> V_97 ) {
F_12 ( V_2 ,
L_77 ) ;
V_122 = - V_82 ;
goto V_219;
}
if ( V_91 -> V_168 && V_91 -> V_168 == V_91 -> V_97 ) {
F_12 ( V_2 , L_78 ) ;
V_122 = - V_82 ;
goto V_219;
}
}
#endif
V_122 = F_55 ( V_2 , & V_224 ,
& V_225 , 1 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_79 , V_122 ) ;
goto V_226;
}
return 0 ;
V_226:
F_56 ( V_2 ) ;
V_219:
if ( ! F_11 ( V_91 -> V_96 ) )
F_57 ( V_91 -> V_96 ) ;
V_217:
F_58 ( F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
return V_122 ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_23 ( V_2 ) ;
F_60 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( ! F_11 ( V_91 -> V_96 ) )
F_57 ( V_91 -> V_96 ) ;
F_58 ( F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_23 ( V_2 ) ;
int V_122 ;
V_122 = F_19 ( V_91 -> V_110 , V_5 ,
V_227 , V_227 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_80 , V_122 ) ;
return V_122 ;
}
V_122 = F_58 ( F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_81 , V_122 ) ;
return V_122 ;
}
if ( ! F_11 ( V_91 -> V_96 ) )
F_57 ( V_91 -> V_96 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_23 ( V_2 ) ;
int V_122 ;
if ( ! F_11 ( V_91 -> V_96 ) ) {
V_122 = F_49 ( V_91 -> V_96 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_72 , V_122 ) ;
return V_122 ;
}
}
V_122 = F_47 ( F_8 ( V_91 -> V_206 ) ,
V_91 -> V_206 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_70 , V_122 ) ;
return V_122 ;
}
F_63 ( V_91 -> V_110 , false ) ;
V_122 = F_64 ( V_91 -> V_110 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_82 , V_122 ) ;
return V_122 ;
}
V_122 = F_19 ( V_91 -> V_110 , V_5 ,
V_227 , 0 ) ;
if ( V_122 != 0 ) {
F_12 ( V_2 , L_83 , V_122 ) ;
return V_122 ;
}
return 0 ;
}
