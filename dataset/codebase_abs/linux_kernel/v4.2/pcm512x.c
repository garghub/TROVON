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
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_76 -> V_81 . integer . V_81 [ 0 ] = V_80 -> V_82 ;
return 0 ;
}
static int F_6 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( F_7 ( V_78 ) ) {
case V_83 :
case V_84 :
break;
default:
return - V_85 ;
}
V_80 -> V_82 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_8 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_76 -> V_81 . integer . V_81 [ 0 ] = V_80 -> V_86 ;
return 0 ;
}
static int F_9 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( F_7 ( V_78 ) ) {
case V_83 :
case V_84 :
break;
default:
return - V_85 ;
}
V_80 -> V_86 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_10 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_76 -> V_81 . integer . V_81 [ 0 ] = V_80 -> V_87 ;
return 0 ;
}
static int F_11 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( F_7 ( V_78 ) ) {
case V_83 :
case V_84 :
break;
default:
return - V_85 ;
}
V_80 -> V_87 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static unsigned long F_12 ( struct V_79 * V_80 )
{
return 25000000 + 25000000 * V_80 -> V_82 / 100 ;
}
static unsigned long F_13 ( struct V_79 * V_80 )
{
return 50000000 + 50000000 * V_80 -> V_86 / 100 ;
}
static unsigned long F_14 ( struct V_79 * V_80 ,
unsigned long V_88 )
{
return V_88 + V_88 * V_80 -> V_87 / 100 ;
}
static unsigned long F_15 ( struct V_79 * V_80 )
{
if ( ! V_80 -> V_89 )
return 25000000 ;
return F_12 ( V_80 ) ;
}
static unsigned long F_16 ( struct V_79 * V_80 ,
unsigned long V_90 )
{
if ( V_90 <= 6144000 )
return 1536000 ;
return F_14 ( V_80 , 1536000 ) ;
}
static int F_17 ( struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_79 * V_80 = V_94 -> V_95 ;
struct V_96 V_97 [ 2 ] ;
int V_98 ;
V_98 = F_18 ( V_92 ) ;
if ( V_98 < 0 )
return V_98 ;
switch ( V_98 ) {
case 32 :
return 0 ;
case 48 :
case 64 :
memset ( V_97 , 0 , sizeof( V_97 ) ) ;
V_97 [ 0 ] . V_99 = 8000 ;
V_97 [ 0 ] . V_100 = F_15 ( V_80 ) / V_98 / 2 ;
V_97 [ 1 ] . V_99 = F_19 ( 16000000 , V_98 ) ;
V_97 [ 1 ] . V_100 = 384000 ;
break;
default:
return - V_101 ;
}
return F_20 ( F_21 ( V_92 , V_94 -> V_102 ) ,
F_22 ( V_97 ) , V_97 , 0 ) ;
}
static int F_23 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
if ( F_24 ( V_80 -> V_111 ) ) {
F_25 ( V_2 , L_1 ,
F_26 ( V_80 -> V_111 ) ) ;
return F_26 ( V_80 -> V_111 ) ;
}
if ( V_80 -> V_89 )
return F_27 ( V_104 -> V_112 , 0 ,
V_113 ,
F_17 ,
V_80 ,
V_114 ,
V_115 , - 1 ) ;
V_108 = F_28 ( V_2 , sizeof( * V_108 ) ,
V_116 ) ;
if ( ! V_108 )
return - V_117 ;
V_108 -> V_118 = 1 ;
V_110 = F_28 ( V_2 , sizeof( * V_110 ) , V_116 ) ;
if ( ! V_110 )
return - V_117 ;
V_108 -> V_119 = V_110 ;
V_110 -> V_120 = F_29 ( V_80 -> V_111 ) / 64 ;
V_110 -> V_121 = 1 ;
V_110 -> V_122 = 128 ;
V_110 -> V_123 = 1 ;
return V_107 ( V_104 -> V_112 , 0 ,
V_113 ,
V_108 ) ;
}
static int F_30 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_124 * V_124 = V_80 -> V_124 ;
if ( F_24 ( V_80 -> V_111 ) ) {
F_31 ( V_2 , L_2 ,
F_26 ( V_80 -> V_111 ) ) ;
F_32 ( V_124 , V_33 ,
V_125 , V_125 ) ;
F_32 ( V_124 , V_14 ,
V_126 , V_127 ) ;
}
return F_33 ( V_104 -> V_112 , 0 ,
V_113 ,
& V_128 ) ;
}
static int F_34 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( V_80 -> V_129 & V_130 ) {
case V_131 :
case V_132 :
return F_23 ( V_104 , V_106 ) ;
case V_133 :
return F_30 ( V_104 , V_106 ) ;
default:
return - V_101 ;
}
}
static int F_35 ( struct V_77 * V_78 ,
enum V_134 V_135 )
{
struct V_79 * V_80 = F_36 ( V_78 -> V_2 ) ;
int V_136 ;
switch ( V_135 ) {
case V_137 :
case V_138 :
break;
case V_84 :
V_136 = F_32 ( V_80 -> V_124 , V_5 ,
V_139 , 0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_3 ,
V_136 ) ;
return V_136 ;
}
break;
case V_83 :
V_136 = F_32 ( V_80 -> V_124 , V_5 ,
V_139 , V_139 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_4 ,
V_136 ) ;
return V_136 ;
}
break;
}
return 0 ;
}
static unsigned long F_37 ( struct V_105 * V_106 ,
unsigned long V_140 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_141 ;
int V_142 ;
V_142 = 1 << F_38 ( ( F_12 ( V_80 ) - 16000000 ) / V_140 ) ;
for (; V_142 ; V_142 >>= 1 ) {
V_141 = F_39 ( F_12 ( V_80 ) ,
V_140 * V_142 ) ;
if ( V_141 >= 16000000 )
break;
}
if ( ! V_142 ) {
F_25 ( V_2 , L_5 ) ;
return 0 ;
}
F_40 ( V_2 , L_6 , V_141 ) ;
return V_141 ;
}
static int F_41 ( struct V_105 * V_106 ,
unsigned long V_143 ,
unsigned long V_144 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_145 ;
int V_146 , V_147 , V_148 , V_149 ;
unsigned long V_150 ;
unsigned long V_120 ;
unsigned long V_151 ;
V_145 = F_42 ( V_144 , V_143 ) ;
F_40 ( V_2 , L_7 ,
V_144 , V_143 , V_145 ) ;
V_120 = V_144 / V_145 ;
V_151 = V_143 / V_145 ;
if ( V_143 / V_151 > 20000000 && V_120 < 8 ) {
V_120 *= F_19 ( V_143 / V_151 , 20000000 ) ;
V_151 *= F_19 ( V_143 / V_151 , 20000000 ) ;
}
F_40 ( V_2 , L_8 , V_120 , V_151 ) ;
V_149 = V_151 ;
if ( V_151 <= 15 && V_120 <= 16 * 63
&& 1000000 <= V_143 / V_149 && V_143 / V_149 <= 20000000 ) {
V_148 = 0 ;
for ( V_146 = 16 ; V_146 ; V_146 -- ) {
if ( V_120 % V_146 )
continue;
V_147 = V_120 / V_146 ;
if ( V_147 == 0 || V_147 > 63 )
continue;
F_40 ( V_2 , L_9 , V_146 , V_147 , V_149 ) ;
V_80 -> V_152 = V_144 ;
goto V_153;
}
}
V_146 = 1 ;
if ( V_120 > 0xffffffffUL / 10000 )
goto V_154;
V_145 = F_42 ( 10000 * V_120 , V_151 ) ;
V_120 = 10000 * V_120 / V_145 ;
V_151 /= V_145 ;
F_40 ( V_2 , L_10 , V_120 , V_151 , V_145 ) ;
for ( V_149 = V_151 ; V_149 <= 15 ; V_149 ++ ) {
if ( V_143 / V_149 < 6667000 || 200000000 < V_143 / V_149 )
continue;
if ( V_120 * V_149 % V_151 )
continue;
V_150 = V_120 * V_149 / V_151 ;
if ( V_150 < 40000 || V_150 > 120000 )
continue;
V_147 = V_150 / 10000 ;
V_148 = V_150 % 10000 ;
F_40 ( V_2 , L_11 , V_147 , V_148 , V_149 ) ;
V_80 -> V_152 = V_144 ;
goto V_153;
}
V_154:
V_149 = F_19 ( V_143 , 20000000 ) ;
if ( ! V_149 )
V_149 = 1 ;
else if ( V_149 > 15 ) {
F_25 ( V_2 , L_12 ) ;
return - V_101 ;
}
if ( V_143 / V_149 < 6667000 ) {
F_25 ( V_2 , L_13 ) ;
return - V_101 ;
}
V_150 = F_43 ( 10000ULL * V_144 * V_149 , V_143 ) ;
if ( V_150 < 40000 )
V_150 = 40000 ;
if ( V_150 > 120000 )
V_150 = 120000 ;
V_147 = V_150 / 10000 ;
V_148 = V_150 % 10000 ;
F_40 ( V_2 , L_14 , V_147 , V_148 , V_149 ) ;
V_80 -> V_152 = F_44 ( ( V_155 ) V_150 * V_143 , 10000 * V_149 ) ;
V_153:
V_80 -> V_156 = V_146 ;
V_80 -> V_157 = V_147 ;
V_80 -> V_158 = V_148 ;
V_80 -> V_159 = V_149 ;
return 0 ;
}
static unsigned long F_45 ( struct V_105 * V_106 ,
unsigned long V_160 ,
unsigned long V_143 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_90 ;
if ( ! V_80 -> V_89 )
return 0 ;
if ( V_143 % V_160 )
return 0 ;
for ( V_90 = F_39 ( F_14 ( V_80 , 6144000 ) , V_160 ) ;
V_90 ;
V_90 -= V_160 ) {
if ( V_143 / V_90 > 128 )
return 0 ;
if ( ! ( V_143 % V_90 ) )
return V_90 ;
V_90 -= V_160 ;
}
return 0 ;
}
static int F_46 ( struct V_105 * V_106 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_143 = 0 ;
unsigned long V_144 ;
unsigned long V_141 ;
unsigned long V_161 ;
unsigned long V_140 ;
unsigned long V_162 ;
unsigned long V_160 ;
unsigned long V_163 ;
int V_164 ;
int V_165 ;
int V_166 ;
int V_167 ;
unsigned long V_90 ;
int V_168 ;
int V_169 ;
int V_136 ;
int V_170 ;
int V_171 ;
int V_172 ;
V_165 = F_18 ( V_92 ) ;
if ( V_165 == 0 ) {
F_25 ( V_2 , L_15 ) ;
return - V_101 ;
}
if ( ! V_80 -> V_89 ) {
V_141 = F_29 ( V_80 -> V_111 ) ;
V_164 = V_92 -> V_173 * 64 / V_165 ;
V_140 = F_47 ( V_141 , V_164 ) ;
V_161 = V_141 ;
} else {
V_136 = F_48 ( V_92 ) ;
if ( V_136 < 0 ) {
F_25 ( V_2 , L_16 , V_136 ) ;
return V_136 ;
}
if ( V_136 == 0 ) {
F_25 ( V_2 , L_17 ) ;
return - V_101 ;
}
V_140 = V_136 ;
V_143 = F_29 ( V_80 -> V_111 ) ;
V_141 = F_37 ( V_106 , V_140 ) ;
if ( ! V_141 )
return - V_101 ;
V_144 = 4 * V_141 ;
V_136 = F_41 ( V_106 , V_143 , V_144 ) ;
if ( V_136 != 0 )
return V_136 ;
V_136 = F_49 ( V_80 -> V_124 ,
V_19 , V_80 -> V_159 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_18 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_20 , V_80 -> V_157 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_19 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_21 , V_80 -> V_158 >> 8 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_20 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_22 , V_80 -> V_158 & 0xff ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_21 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_23 , V_80 -> V_156 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_22 , V_136 ) ;
return V_136 ;
}
V_161 = V_80 -> V_152 ;
V_164 = F_47 ( V_141 , V_140 ) ;
}
if ( V_164 > 128 ) {
F_25 ( V_2 , L_23 ) ;
return - V_101 ;
}
V_162 = V_141 / V_164 / V_165 ;
V_160 = 16 * V_162 ;
V_166 = V_161 > F_13 ( V_80 ) ? 2 : 1 ;
V_90 = F_45 ( V_106 , V_160 , V_143 ) ;
if ( V_90 ) {
F_40 ( V_2 , L_24 ) ;
V_136 = F_32 ( V_80 -> V_124 , V_15 ,
V_174 , V_175 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_25 , V_136 ) ;
return V_136 ;
}
V_172 = V_176 + V_80 -> V_177 - 1 ;
V_136 = F_32 ( V_80 -> V_124 , V_16 ,
V_178 , V_172 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_26 ,
V_80 -> V_177 , V_136 ) ;
return V_136 ;
}
V_163 = V_143 ;
} else {
unsigned long V_179 = F_14 ( V_80 , 6144000 )
/ V_160 ;
unsigned long V_180 = V_141 / V_160 ;
for (; V_179 ; V_179 -- ) {
if ( ! ( V_180 % V_179 ) )
break;
}
if ( ! V_179 ) {
F_25 ( V_2 , L_27 ) ;
return - V_101 ;
}
V_90 = V_179 * V_160 ;
F_40 ( V_2 , L_28 ,
V_90 , V_162 ) ;
V_136 = F_32 ( V_80 -> V_124 , V_15 ,
V_174 , V_181 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_29 , V_136 ) ;
return V_136 ;
}
V_163 = V_141 ;
}
V_169 = F_47 ( V_90 , V_160 ) ;
if ( V_169 > 128 ) {
F_25 ( V_2 , L_30 ) ;
return - V_101 ;
}
V_167 = F_47 ( V_163 , V_90 ) ;
if ( V_167 > 128 ) {
F_25 ( V_2 , L_31 ) ;
return - V_101 ;
}
V_90 = V_163 / V_167 ;
V_168 = F_47 ( V_90 ,
F_16 ( V_80 , V_90 ) ) ;
if ( V_168 > 128 || V_90 / V_168 > 2048000 ) {
V_168 = F_19 ( V_90 , 2048000 ) ;
if ( V_168 > 128 ) {
F_25 ( V_2 , L_32 ) ;
return - V_101 ;
}
}
V_170 = V_161 / ( V_166 * V_162 ) ;
V_136 = F_49 ( V_80 -> V_124 , V_24 , V_166 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_33 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_25 , V_167 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_34 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_26 , V_168 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_35 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_27 , V_169 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_36 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_28 , V_164 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_37 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 ,
V_29 , V_165 - 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_38 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_31 , V_170 >> 8 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_39 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_32 , V_170 & 0xff ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_40 , V_136 ) ;
return V_136 ;
}
if ( V_162 <= F_14 ( V_80 , 48000 ) )
V_171 = V_182 ;
else if ( V_162 <= F_14 ( V_80 , 96000 ) )
V_171 = V_183 ;
else if ( V_162 <= F_14 ( V_80 , 192000 ) )
V_171 = V_184 ;
else
V_171 = V_185 ;
V_136 = F_32 ( V_80 -> V_124 , V_30 ,
V_186 , V_171 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_41 , V_136 ) ;
return V_136 ;
}
F_40 ( V_78 -> V_2 , L_42 , V_166 ) ;
F_40 ( V_78 -> V_2 , L_43 , V_167 ) ;
F_40 ( V_78 -> V_2 , L_44 , V_168 ) ;
F_40 ( V_78 -> V_2 , L_45 , V_169 ) ;
F_40 ( V_78 -> V_2 , L_46 , V_164 ) ;
F_40 ( V_78 -> V_2 , L_47 , V_165 ) ;
F_40 ( V_78 -> V_2 , L_48 , V_170 ) ;
F_40 ( V_78 -> V_2 , L_49 , 1 << V_171 ) ;
return 0 ;
}
static int F_50 ( struct V_103 * V_104 ,
struct V_91 * V_92 ,
struct V_105 * V_106 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
int V_187 ;
int V_172 ;
int V_188 ;
int V_189 ;
int V_136 ;
F_40 ( V_78 -> V_2 , L_50 ,
F_51 ( V_92 ) ,
F_52 ( V_92 ) ) ;
switch ( F_53 ( F_54 ( V_92 ) ) ) {
case 16 :
V_187 = V_190 ;
break;
case 20 :
V_187 = V_191 ;
break;
case 24 :
V_187 = V_192 ;
break;
case 32 :
V_187 = V_193 ;
break;
default:
F_25 ( V_78 -> V_2 , L_51 ,
F_53 ( F_54 ( V_92 ) ) ) ;
return - V_101 ;
}
switch ( V_80 -> V_129 & V_130 ) {
case V_133 :
V_136 = F_32 ( V_80 -> V_124 ,
V_11 ,
V_194
| V_195 | V_196 ,
0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_52 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_33 ,
V_197 , 0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_53 ,
V_136 ) ;
return V_136 ;
}
return 0 ;
case V_131 :
V_188 = V_195 | V_196 ;
V_189 = V_198 | V_199 ;
break;
case V_132 :
V_188 = V_195 ;
V_189 = V_199 ;
break;
default:
return - V_101 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_34 ,
V_200 , V_187 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_54 , V_136 ) ;
return V_136 ;
}
if ( V_80 -> V_89 ) {
V_136 = F_49 ( V_80 -> V_124 , V_71 , 0x11 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_55 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_80 -> V_124 , V_72 , 0xff ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_56 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_33 ,
V_201 | V_202
| V_203 | V_125
| V_204 | V_197
| V_205 ,
V_201 | V_202
| V_203 | V_125
| V_197 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_57 ,
V_136 ) ;
return V_136 ;
}
} else {
V_136 = F_32 ( V_80 -> V_124 , V_33 ,
V_201 | V_202
| V_203 | V_125
| V_204 | V_197
| V_205 ,
V_201 | V_202
| V_203 | V_125
| V_197 | V_205 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_57 ,
V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_7 ,
V_206 , 0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_58 , V_136 ) ;
return V_136 ;
}
}
V_136 = F_46 ( V_106 , V_92 ) ;
if ( V_136 != 0 )
return V_136 ;
if ( V_80 -> V_89 ) {
V_136 = F_32 ( V_80 -> V_124 , V_14 ,
V_126 , V_207 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_59 , V_136 ) ;
return V_136 ;
}
V_172 = V_176 + V_80 -> V_177 - 1 ;
V_136 = F_32 ( V_80 -> V_124 , V_17 ,
V_178 , V_172 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 ,
L_60 ,
V_80 -> V_177 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_7 ,
V_206 , V_206 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_61 , V_136 ) ;
return V_136 ;
}
}
V_136 = F_32 ( V_80 -> V_124 , V_11 ,
V_194 | V_195 | V_196 ,
V_188 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_62 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_13 ,
V_198 | V_199 ,
V_189 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_63 , V_136 ) ;
return V_136 ;
}
if ( V_80 -> V_89 ) {
V_172 = V_208 << ( V_80 -> V_89 - 1 ) ;
V_136 = F_32 ( V_80 -> V_124 , V_10 ,
V_172 , V_172 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_64 ,
V_80 -> V_89 , V_136 ) ;
return V_136 ;
}
V_172 = V_46 + V_80 -> V_89 - 1 ;
V_136 = F_32 ( V_80 -> V_124 , V_172 ,
V_209 , V_210 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_65 ,
V_136 , V_80 -> V_89 ) ;
return V_136 ;
}
}
V_136 = F_32 ( V_80 -> V_124 , V_18 ,
V_211 , V_212 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_66 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_18 ,
V_211 , V_213 ) ;
if ( V_136 != 0 ) {
F_25 ( V_78 -> V_2 , L_67 , V_136 ) ;
return V_136 ;
}
return 0 ;
}
static int F_55 ( struct V_105 * V_106 , unsigned int V_129 )
{
struct V_77 * V_78 = V_106 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_80 -> V_129 = V_129 ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , struct V_124 * V_124 )
{
struct V_79 * V_80 ;
int V_214 , V_136 ;
V_80 = F_28 ( V_2 , sizeof( struct V_79 ) , V_116 ) ;
if ( ! V_80 )
return - V_117 ;
F_57 ( V_2 , V_80 ) ;
V_80 -> V_124 = V_124 ;
for ( V_214 = 0 ; V_214 < F_22 ( V_80 -> V_215 ) ; V_214 ++ )
V_80 -> V_215 [ V_214 ] . V_216 = V_217 [ V_214 ] ;
V_136 = F_58 ( V_2 , F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_68 , V_136 ) ;
return V_136 ;
}
V_80 -> V_218 [ 0 ] . V_219 = V_220 ;
V_80 -> V_218 [ 1 ] . V_219 = V_221 ;
V_80 -> V_218 [ 2 ] . V_219 = V_222 ;
for ( V_214 = 0 ; V_214 < F_22 ( V_80 -> V_215 ) ; V_214 ++ ) {
V_136 = F_59 ( V_80 -> V_215 [ V_214 ] . V_223 ,
& V_80 -> V_218 [ V_214 ] ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 ,
L_69 ,
V_136 ) ;
}
}
V_136 = F_60 ( F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_70 , V_136 ) ;
return V_136 ;
}
V_136 = F_49 ( V_124 , V_4 ,
V_224 | V_225 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_71 , V_136 ) ;
goto V_226;
}
V_136 = F_49 ( V_124 , V_4 , 0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_71 , V_136 ) ;
goto V_226;
}
V_80 -> V_111 = F_61 ( V_2 , NULL ) ;
if ( F_26 ( V_80 -> V_111 ) == - V_227 )
return - V_227 ;
if ( ! F_24 ( V_80 -> V_111 ) ) {
V_136 = F_62 ( V_80 -> V_111 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_72 , V_136 ) ;
return V_136 ;
}
}
V_136 = F_32 ( V_80 -> V_124 , V_5 ,
V_139 , V_139 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_4 ,
V_136 ) ;
goto V_228;
}
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
#ifdef F_66
if ( V_2 -> V_229 ) {
const struct V_230 * V_231 = V_2 -> V_229 ;
T_1 V_232 ;
if ( F_67 ( V_231 , L_73 , & V_232 ) >= 0 ) {
if ( V_232 > 6 ) {
F_25 ( V_2 , L_74 ) ;
V_136 = - V_101 ;
goto V_228;
}
V_80 -> V_177 = V_232 ;
}
if ( F_67 ( V_231 , L_75 , & V_232 ) >= 0 ) {
if ( V_232 > 6 ) {
F_25 ( V_2 , L_76 ) ;
V_136 = - V_101 ;
goto V_228;
}
V_80 -> V_89 = V_232 ;
}
if ( ! V_80 -> V_177 != ! V_80 -> V_89 ) {
F_25 ( V_2 ,
L_77 ) ;
V_136 = - V_101 ;
goto V_228;
}
if ( V_80 -> V_177 && V_80 -> V_177 == V_80 -> V_89 ) {
F_25 ( V_2 , L_78 ) ;
V_136 = - V_101 ;
goto V_228;
}
}
#endif
V_136 = F_68 ( V_2 , & V_233 ,
& V_234 , 1 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_79 , V_136 ) ;
goto V_235;
}
return 0 ;
V_235:
F_69 ( V_2 ) ;
V_228:
if ( ! F_24 ( V_80 -> V_111 ) )
F_70 ( V_80 -> V_111 ) ;
V_226:
F_71 ( F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
return V_136 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_36 ( V_2 ) ;
F_73 ( V_2 ) ;
F_69 ( V_2 ) ;
if ( ! F_24 ( V_80 -> V_111 ) )
F_70 ( V_80 -> V_111 ) ;
F_71 ( F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_36 ( V_2 ) ;
int V_136 ;
V_136 = F_32 ( V_80 -> V_124 , V_5 ,
V_236 , V_236 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_80 , V_136 ) ;
return V_136 ;
}
V_136 = F_71 ( F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_81 , V_136 ) ;
return V_136 ;
}
if ( ! F_24 ( V_80 -> V_111 ) )
F_70 ( V_80 -> V_111 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_36 ( V_2 ) ;
int V_136 ;
if ( ! F_24 ( V_80 -> V_111 ) ) {
V_136 = F_62 ( V_80 -> V_111 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_72 , V_136 ) ;
return V_136 ;
}
}
V_136 = F_60 ( F_22 ( V_80 -> V_215 ) ,
V_80 -> V_215 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_70 , V_136 ) ;
return V_136 ;
}
F_76 ( V_80 -> V_124 , false ) ;
V_136 = F_77 ( V_80 -> V_124 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_82 , V_136 ) ;
return V_136 ;
}
V_136 = F_32 ( V_80 -> V_124 , V_5 ,
V_236 , 0 ) ;
if ( V_136 != 0 ) {
F_25 ( V_2 , L_83 , V_136 ) ;
return V_136 ;
}
return 0 ;
}
