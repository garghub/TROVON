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
switch ( V_78 -> V_83 . V_84 ) {
case V_85 :
case V_86 :
break;
default:
return - V_87 ;
}
V_80 -> V_82 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_7 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_76 -> V_81 . integer . V_81 [ 0 ] = V_80 -> V_88 ;
return 0 ;
}
static int F_8 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( V_78 -> V_83 . V_84 ) {
case V_85 :
case V_86 :
break;
default:
return - V_87 ;
}
V_80 -> V_88 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static int F_9 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_76 -> V_81 . integer . V_81 [ 0 ] = V_80 -> V_89 ;
return 0 ;
}
static int F_10 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 = F_4 ( V_74 ) ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( V_78 -> V_83 . V_84 ) {
case V_85 :
case V_86 :
break;
default:
return - V_87 ;
}
V_80 -> V_89 = V_76 -> V_81 . integer . V_81 [ 0 ] ;
return 0 ;
}
static unsigned long F_11 ( struct V_79 * V_80 )
{
return 25000000 + 25000000 * V_80 -> V_82 / 100 ;
}
static unsigned long F_12 ( struct V_79 * V_80 )
{
return 50000000 + 50000000 * V_80 -> V_88 / 100 ;
}
static unsigned long F_13 ( struct V_79 * V_80 ,
unsigned long V_90 )
{
return V_90 + V_90 * V_80 -> V_89 / 100 ;
}
static unsigned long F_14 ( struct V_79 * V_80 )
{
if ( ! V_80 -> V_91 )
return 25000000 ;
return F_11 ( V_80 ) ;
}
static unsigned long F_15 ( struct V_79 * V_80 ,
unsigned long V_92 )
{
if ( V_92 <= 6144000 )
return 1536000 ;
return F_13 ( V_80 , 1536000 ) ;
}
static int F_16 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_79 * V_80 = V_96 -> V_97 ;
struct V_98 V_99 [ 2 ] ;
int V_100 ;
V_100 = F_17 ( V_94 ) ;
if ( V_100 < 0 )
return V_100 ;
switch ( V_100 ) {
case 32 :
return 0 ;
case 48 :
case 64 :
memset ( V_99 , 0 , sizeof( V_99 ) ) ;
V_99 [ 0 ] . V_101 = 8000 ;
V_99 [ 0 ] . V_102 = F_14 ( V_80 ) / V_100 / 2 ;
V_99 [ 1 ] . V_101 = F_18 ( 16000000 , V_100 ) ;
V_99 [ 1 ] . V_102 = 384000 ;
break;
default:
return - V_103 ;
}
return F_19 ( F_20 ( V_94 , V_96 -> V_104 ) ,
F_21 ( V_99 ) , V_99 , 0 ) ;
}
static int F_22 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
if ( F_23 ( V_80 -> V_113 ) ) {
F_24 ( V_2 , L_1 ,
F_25 ( V_80 -> V_113 ) ) ;
return F_25 ( V_80 -> V_113 ) ;
}
if ( V_80 -> V_91 )
return F_26 ( V_106 -> V_114 , 0 ,
V_115 ,
F_16 ,
V_80 ,
V_116 ,
V_117 , - 1 ) ;
V_110 = F_27 ( V_2 , sizeof( * V_110 ) ,
V_118 ) ;
if ( ! V_110 )
return - V_119 ;
V_110 -> V_120 = 1 ;
V_112 = F_27 ( V_2 , sizeof( * V_112 ) , V_118 ) ;
if ( ! V_112 )
return - V_119 ;
V_110 -> V_121 = V_112 ;
V_112 -> V_122 = F_28 ( V_80 -> V_113 ) / 64 ;
V_112 -> V_123 = 1 ;
V_112 -> V_124 = 128 ;
V_112 -> V_125 = 1 ;
return V_109 ( V_106 -> V_114 , 0 ,
V_115 ,
V_110 ) ;
}
static int F_29 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_126 * V_126 = V_80 -> V_126 ;
if ( F_23 ( V_80 -> V_113 ) ) {
F_30 ( V_2 , L_2 ,
F_25 ( V_80 -> V_113 ) ) ;
F_31 ( V_126 , V_33 ,
V_127 , V_127 ) ;
F_31 ( V_126 , V_14 ,
V_128 , V_129 ) ;
}
return F_32 ( V_106 -> V_114 , 0 ,
V_115 ,
& V_130 ) ;
}
static int F_33 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
switch ( V_80 -> V_131 & V_132 ) {
case V_133 :
case V_134 :
return F_22 ( V_106 , V_108 ) ;
case V_135 :
return F_29 ( V_106 , V_108 ) ;
default:
return - V_103 ;
}
}
static int F_34 ( struct V_77 * V_78 ,
enum V_136 V_137 )
{
struct V_79 * V_80 = F_35 ( V_78 -> V_2 ) ;
int V_138 ;
switch ( V_137 ) {
case V_139 :
case V_140 :
break;
case V_86 :
V_138 = F_31 ( V_80 -> V_126 , V_5 ,
V_141 , 0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_3 ,
V_138 ) ;
return V_138 ;
}
break;
case V_85 :
V_138 = F_31 ( V_80 -> V_126 , V_5 ,
V_141 , V_141 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_4 ,
V_138 ) ;
return V_138 ;
}
break;
}
V_78 -> V_83 . V_84 = V_137 ;
return 0 ;
}
static unsigned long F_36 ( struct V_107 * V_108 ,
unsigned long V_142 )
{
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_143 ;
int V_144 ;
V_144 = 1 << F_37 ( ( F_11 ( V_80 ) - 16000000 ) / V_142 ) ;
for (; V_144 ; V_144 >>= 1 ) {
V_143 = F_38 ( F_11 ( V_80 ) ,
V_142 * V_144 ) ;
if ( V_143 >= 16000000 )
break;
}
if ( ! V_144 ) {
F_24 ( V_2 , L_5 ) ;
return 0 ;
}
F_39 ( V_2 , L_6 , V_143 ) ;
return V_143 ;
}
static int F_40 ( struct V_107 * V_108 ,
unsigned long V_145 ,
unsigned long V_146 )
{
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_147 ;
int V_148 , V_149 , V_150 , V_151 ;
unsigned long V_152 ;
unsigned long V_122 ;
unsigned long V_153 ;
V_147 = F_41 ( V_146 , V_145 ) ;
F_39 ( V_2 , L_7 ,
V_146 , V_145 , V_147 ) ;
V_122 = V_146 / V_147 ;
V_153 = V_145 / V_147 ;
if ( V_145 / V_153 > 20000000 && V_122 < 8 ) {
V_122 *= F_18 ( V_145 / V_153 , 20000000 ) ;
V_153 *= F_18 ( V_145 / V_153 , 20000000 ) ;
}
F_39 ( V_2 , L_8 , V_122 , V_153 ) ;
V_151 = V_153 ;
if ( V_153 <= 15 && V_122 <= 16 * 63
&& 1000000 <= V_145 / V_151 && V_145 / V_151 <= 20000000 ) {
V_150 = 0 ;
for ( V_148 = 16 ; V_148 ; V_148 -- ) {
if ( V_122 % V_148 )
continue;
V_149 = V_122 / V_148 ;
if ( V_149 == 0 || V_149 > 63 )
continue;
F_39 ( V_2 , L_9 , V_148 , V_149 , V_151 ) ;
V_80 -> V_154 = V_146 ;
goto V_155;
}
}
V_148 = 1 ;
if ( V_122 > 0xffffffffUL / 10000 )
goto V_156;
V_147 = F_41 ( 10000 * V_122 , V_153 ) ;
V_122 = 10000 * V_122 / V_147 ;
V_153 /= V_147 ;
F_39 ( V_2 , L_10 , V_122 , V_153 , V_147 ) ;
for ( V_151 = V_153 ; V_151 <= 15 ; V_151 ++ ) {
if ( V_145 / V_151 < 6667000 || 200000000 < V_145 / V_151 )
continue;
if ( V_122 * V_151 % V_153 )
continue;
V_152 = V_122 * V_151 / V_153 ;
if ( V_152 < 40000 || V_152 > 120000 )
continue;
V_149 = V_152 / 10000 ;
V_150 = V_152 % 10000 ;
F_39 ( V_2 , L_11 , V_149 , V_150 , V_151 ) ;
V_80 -> V_154 = V_146 ;
goto V_155;
}
V_156:
V_151 = F_18 ( V_145 , 20000000 ) ;
if ( ! V_151 )
V_151 = 1 ;
else if ( V_151 > 15 ) {
F_24 ( V_2 , L_12 ) ;
return - V_103 ;
}
if ( V_145 / V_151 < 6667000 ) {
F_24 ( V_2 , L_13 ) ;
return - V_103 ;
}
V_152 = F_42 ( 10000ULL * V_146 * V_151 , V_145 ) ;
if ( V_152 < 40000 )
V_152 = 40000 ;
if ( V_152 > 120000 )
V_152 = 120000 ;
V_149 = V_152 / 10000 ;
V_150 = V_152 % 10000 ;
F_39 ( V_2 , L_14 , V_149 , V_150 , V_151 ) ;
V_80 -> V_154 = F_43 ( ( V_157 ) V_152 * V_145 , 10000 * V_151 ) ;
V_155:
V_80 -> V_158 = V_148 ;
V_80 -> V_159 = V_149 ;
V_80 -> V_160 = V_150 ;
V_80 -> V_161 = V_151 ;
return 0 ;
}
static unsigned long F_44 ( struct V_107 * V_108 ,
unsigned long V_162 ,
unsigned long V_145 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_92 ;
if ( ! V_80 -> V_91 )
return 0 ;
if ( V_145 % V_162 )
return 0 ;
for ( V_92 = F_38 ( F_13 ( V_80 , 6144000 ) , V_162 ) ;
V_92 ;
V_92 -= V_162 ) {
if ( V_145 / V_92 > 128 )
return 0 ;
if ( ! ( V_145 % V_92 ) )
return V_92 ;
V_92 -= V_162 ;
}
return 0 ;
}
static int F_45 ( struct V_107 * V_108 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
unsigned long V_145 = 0 ;
unsigned long V_146 ;
unsigned long V_143 ;
unsigned long V_163 ;
unsigned long V_142 ;
unsigned long V_164 ;
unsigned long V_162 ;
unsigned long V_165 ;
int V_166 ;
int V_167 ;
int V_168 ;
int V_169 ;
unsigned long V_92 ;
int V_170 ;
int V_171 ;
int V_138 ;
int V_172 ;
int V_173 ;
int V_174 ;
V_167 = F_17 ( V_94 ) ;
if ( V_167 == 0 ) {
F_24 ( V_2 , L_15 ) ;
return - V_103 ;
}
if ( ! V_80 -> V_91 ) {
V_143 = F_28 ( V_80 -> V_113 ) ;
V_166 = V_94 -> V_175 * 64 / V_167 ;
V_142 = F_46 ( V_143 , V_166 ) ;
V_163 = V_143 ;
} else {
V_138 = F_47 ( V_94 ) ;
if ( V_138 < 0 ) {
F_24 ( V_2 , L_16 , V_138 ) ;
return V_138 ;
}
if ( V_138 == 0 ) {
F_24 ( V_2 , L_17 ) ;
return - V_103 ;
}
V_142 = V_138 ;
V_145 = F_28 ( V_80 -> V_113 ) ;
V_143 = F_36 ( V_108 , V_142 ) ;
if ( ! V_143 )
return - V_103 ;
V_146 = 4 * V_143 ;
V_138 = F_40 ( V_108 , V_145 , V_146 ) ;
if ( V_138 != 0 )
return V_138 ;
V_138 = F_48 ( V_80 -> V_126 ,
V_19 , V_80 -> V_161 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_18 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_20 , V_80 -> V_159 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_19 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_21 , V_80 -> V_160 >> 8 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_20 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_22 , V_80 -> V_160 & 0xff ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_21 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_23 , V_80 -> V_158 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_22 , V_138 ) ;
return V_138 ;
}
V_163 = V_80 -> V_154 ;
V_166 = F_46 ( V_143 , V_142 ) ;
}
if ( V_166 > 128 ) {
F_24 ( V_2 , L_23 ) ;
return - V_103 ;
}
V_164 = V_143 / V_166 / V_167 ;
V_162 = 16 * V_164 ;
V_168 = V_163 > F_12 ( V_80 ) ? 2 : 1 ;
V_92 = F_44 ( V_108 , V_162 , V_145 ) ;
if ( V_92 ) {
F_39 ( V_2 , L_24 ) ;
V_138 = F_31 ( V_80 -> V_126 , V_15 ,
V_176 , V_177 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_25 , V_138 ) ;
return V_138 ;
}
V_174 = V_178 + V_80 -> V_179 - 1 ;
V_138 = F_31 ( V_80 -> V_126 , V_16 ,
V_180 , V_174 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_26 ,
V_80 -> V_179 , V_138 ) ;
return V_138 ;
}
V_165 = V_145 ;
} else {
unsigned long V_181 = F_13 ( V_80 , 6144000 )
/ V_162 ;
unsigned long V_182 = V_143 / V_162 ;
for (; V_181 ; V_181 -- ) {
if ( ! ( V_182 % V_181 ) )
break;
}
if ( ! V_181 ) {
F_24 ( V_2 , L_27 ) ;
return - V_103 ;
}
V_92 = V_181 * V_162 ;
F_39 ( V_2 , L_28 ,
V_92 , V_164 ) ;
V_138 = F_31 ( V_80 -> V_126 , V_15 ,
V_176 , V_183 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_29 , V_138 ) ;
return V_138 ;
}
V_165 = V_143 ;
}
V_171 = F_46 ( V_92 , V_162 ) ;
if ( V_171 > 128 ) {
F_24 ( V_2 , L_30 ) ;
return - V_103 ;
}
V_169 = F_46 ( V_165 , V_92 ) ;
if ( V_169 > 128 ) {
F_24 ( V_2 , L_31 ) ;
return - V_103 ;
}
V_92 = V_165 / V_169 ;
V_170 = F_46 ( V_92 ,
F_15 ( V_80 , V_92 ) ) ;
if ( V_170 > 128 || V_92 / V_170 > 2048000 ) {
V_170 = F_18 ( V_92 , 2048000 ) ;
if ( V_170 > 128 ) {
F_24 ( V_2 , L_32 ) ;
return - V_103 ;
}
}
V_172 = V_163 / ( V_168 * V_164 ) ;
V_138 = F_48 ( V_80 -> V_126 , V_24 , V_168 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_33 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_25 , V_169 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_34 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_26 , V_170 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_35 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_27 , V_171 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_36 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_28 , V_166 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_37 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 ,
V_29 , V_167 - 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_38 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_31 , V_172 >> 8 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_39 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_32 , V_172 & 0xff ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_40 , V_138 ) ;
return V_138 ;
}
if ( V_164 <= F_13 ( V_80 , 48000 ) )
V_173 = V_184 ;
else if ( V_164 <= F_13 ( V_80 , 96000 ) )
V_173 = V_185 ;
else if ( V_164 <= F_13 ( V_80 , 192000 ) )
V_173 = V_186 ;
else
V_173 = V_187 ;
V_138 = F_31 ( V_80 -> V_126 , V_30 ,
V_188 , V_173 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_41 , V_138 ) ;
return V_138 ;
}
F_39 ( V_78 -> V_2 , L_42 , V_168 ) ;
F_39 ( V_78 -> V_2 , L_43 , V_169 ) ;
F_39 ( V_78 -> V_2 , L_44 , V_170 ) ;
F_39 ( V_78 -> V_2 , L_45 , V_171 ) ;
F_39 ( V_78 -> V_2 , L_46 , V_166 ) ;
F_39 ( V_78 -> V_2 , L_47 , V_167 ) ;
F_39 ( V_78 -> V_2 , L_48 , V_172 ) ;
F_39 ( V_78 -> V_2 , L_49 , 1 << V_173 ) ;
return 0 ;
}
static int F_49 ( struct V_105 * V_106 ,
struct V_93 * V_94 ,
struct V_107 * V_108 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
int V_189 ;
int V_174 ;
int V_190 ;
int V_191 ;
int V_138 ;
F_39 ( V_78 -> V_2 , L_50 ,
F_50 ( V_94 ) ,
F_51 ( V_94 ) ) ;
switch ( F_52 ( F_53 ( V_94 ) ) ) {
case 16 :
V_189 = V_192 ;
break;
case 20 :
V_189 = V_193 ;
break;
case 24 :
V_189 = V_194 ;
break;
case 32 :
V_189 = V_195 ;
break;
default:
F_24 ( V_78 -> V_2 , L_51 ,
F_52 ( F_53 ( V_94 ) ) ) ;
return - V_103 ;
}
switch ( V_80 -> V_131 & V_132 ) {
case V_135 :
V_138 = F_31 ( V_80 -> V_126 ,
V_11 ,
V_196
| V_197 | V_198 ,
0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_52 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_33 ,
V_199 , 0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_53 ,
V_138 ) ;
return V_138 ;
}
return 0 ;
case V_133 :
V_190 = V_197 | V_198 ;
V_191 = V_200 | V_201 ;
break;
case V_134 :
V_190 = V_197 ;
V_191 = V_201 ;
break;
default:
return - V_103 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_34 ,
V_202 , V_189 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_54 , V_138 ) ;
return V_138 ;
}
if ( V_80 -> V_91 ) {
V_138 = F_48 ( V_80 -> V_126 , V_71 , 0x11 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_55 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_80 -> V_126 , V_72 , 0xff ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_56 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_33 ,
V_203 | V_204
| V_205 | V_127
| V_206 | V_199
| V_207 ,
V_203 | V_204
| V_205 | V_127
| V_199 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_57 ,
V_138 ) ;
return V_138 ;
}
} else {
V_138 = F_31 ( V_80 -> V_126 , V_33 ,
V_203 | V_204
| V_205 | V_127
| V_206 | V_199
| V_207 ,
V_203 | V_204
| V_205 | V_127
| V_199 | V_207 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_57 ,
V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_7 ,
V_208 , 0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_58 , V_138 ) ;
return V_138 ;
}
}
V_138 = F_45 ( V_108 , V_94 ) ;
if ( V_138 != 0 )
return V_138 ;
if ( V_80 -> V_91 ) {
V_138 = F_31 ( V_80 -> V_126 , V_14 ,
V_128 , V_209 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_59 , V_138 ) ;
return V_138 ;
}
V_174 = V_178 + V_80 -> V_179 - 1 ;
V_138 = F_31 ( V_80 -> V_126 , V_17 ,
V_180 , V_174 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 ,
L_60 ,
V_80 -> V_179 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_7 ,
V_208 , V_208 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_61 , V_138 ) ;
return V_138 ;
}
}
V_138 = F_31 ( V_80 -> V_126 , V_11 ,
V_196 | V_197 | V_198 ,
V_190 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_62 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_13 ,
V_200 | V_201 ,
V_191 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_63 , V_138 ) ;
return V_138 ;
}
if ( V_80 -> V_91 ) {
V_174 = V_210 << ( V_80 -> V_91 - 1 ) ;
V_138 = F_31 ( V_80 -> V_126 , V_10 ,
V_174 , V_174 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_64 ,
V_80 -> V_91 , V_138 ) ;
return V_138 ;
}
V_174 = V_46 + V_80 -> V_91 - 1 ;
V_138 = F_31 ( V_80 -> V_126 , V_174 ,
V_211 , V_212 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_65 ,
V_138 , V_80 -> V_91 ) ;
return V_138 ;
}
}
V_138 = F_31 ( V_80 -> V_126 , V_18 ,
V_213 , V_214 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_66 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_18 ,
V_213 , V_215 ) ;
if ( V_138 != 0 ) {
F_24 ( V_78 -> V_2 , L_67 , V_138 ) ;
return V_138 ;
}
return 0 ;
}
static int F_54 ( struct V_107 * V_108 , unsigned int V_131 )
{
struct V_77 * V_78 = V_108 -> V_78 ;
struct V_79 * V_80 = F_5 ( V_78 ) ;
V_80 -> V_131 = V_131 ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_126 * V_126 )
{
struct V_79 * V_80 ;
int V_216 , V_138 ;
V_80 = F_27 ( V_2 , sizeof( struct V_79 ) , V_118 ) ;
if ( ! V_80 )
return - V_119 ;
F_56 ( V_2 , V_80 ) ;
V_80 -> V_126 = V_126 ;
for ( V_216 = 0 ; V_216 < F_21 ( V_80 -> V_217 ) ; V_216 ++ )
V_80 -> V_217 [ V_216 ] . V_218 = V_219 [ V_216 ] ;
V_138 = F_57 ( V_2 , F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_68 , V_138 ) ;
return V_138 ;
}
V_80 -> V_220 [ 0 ] . V_221 = V_222 ;
V_80 -> V_220 [ 1 ] . V_221 = V_223 ;
V_80 -> V_220 [ 2 ] . V_221 = V_224 ;
for ( V_216 = 0 ; V_216 < F_21 ( V_80 -> V_217 ) ; V_216 ++ ) {
V_138 = F_58 ( V_80 -> V_217 [ V_216 ] . V_225 ,
& V_80 -> V_220 [ V_216 ] ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 ,
L_69 ,
V_138 ) ;
}
}
V_138 = F_59 ( F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_70 , V_138 ) ;
return V_138 ;
}
V_138 = F_48 ( V_126 , V_4 ,
V_226 | V_227 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_71 , V_138 ) ;
goto V_228;
}
V_138 = F_48 ( V_126 , V_4 , 0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_71 , V_138 ) ;
goto V_228;
}
V_80 -> V_113 = F_60 ( V_2 , NULL ) ;
if ( F_25 ( V_80 -> V_113 ) == - V_229 )
return - V_229 ;
if ( ! F_23 ( V_80 -> V_113 ) ) {
V_138 = F_61 ( V_80 -> V_113 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_72 , V_138 ) ;
return V_138 ;
}
}
V_138 = F_31 ( V_80 -> V_126 , V_5 ,
V_141 , V_141 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_4 ,
V_138 ) ;
goto V_230;
}
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
#ifdef F_65
if ( V_2 -> V_231 ) {
const struct V_232 * V_233 = V_2 -> V_231 ;
T_1 V_234 ;
if ( F_66 ( V_233 , L_73 , & V_234 ) >= 0 ) {
if ( V_234 > 6 ) {
F_24 ( V_2 , L_74 ) ;
V_138 = - V_103 ;
goto V_230;
}
V_80 -> V_179 = V_234 ;
}
if ( F_66 ( V_233 , L_75 , & V_234 ) >= 0 ) {
if ( V_234 > 6 ) {
F_24 ( V_2 , L_76 ) ;
V_138 = - V_103 ;
goto V_230;
}
V_80 -> V_91 = V_234 ;
}
if ( ! V_80 -> V_179 != ! V_80 -> V_91 ) {
F_24 ( V_2 ,
L_77 ) ;
V_138 = - V_103 ;
goto V_230;
}
if ( V_80 -> V_179 && V_80 -> V_179 == V_80 -> V_91 ) {
F_24 ( V_2 , L_78 ) ;
V_138 = - V_103 ;
goto V_230;
}
}
#endif
V_138 = F_67 ( V_2 , & V_235 ,
& V_236 , 1 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_79 , V_138 ) ;
goto V_237;
}
return 0 ;
V_237:
F_68 ( V_2 ) ;
V_230:
if ( ! F_23 ( V_80 -> V_113 ) )
F_69 ( V_80 -> V_113 ) ;
V_228:
F_70 ( F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
return V_138 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_35 ( V_2 ) ;
F_72 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( ! F_23 ( V_80 -> V_113 ) )
F_69 ( V_80 -> V_113 ) ;
F_70 ( F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_35 ( V_2 ) ;
int V_138 ;
V_138 = F_31 ( V_80 -> V_126 , V_5 ,
V_238 , V_238 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_80 , V_138 ) ;
return V_138 ;
}
V_138 = F_70 ( F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_81 , V_138 ) ;
return V_138 ;
}
if ( ! F_23 ( V_80 -> V_113 ) )
F_69 ( V_80 -> V_113 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = F_35 ( V_2 ) ;
int V_138 ;
if ( ! F_23 ( V_80 -> V_113 ) ) {
V_138 = F_61 ( V_80 -> V_113 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_72 , V_138 ) ;
return V_138 ;
}
}
V_138 = F_59 ( F_21 ( V_80 -> V_217 ) ,
V_80 -> V_217 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_70 , V_138 ) ;
return V_138 ;
}
F_75 ( V_80 -> V_126 , false ) ;
V_138 = F_76 ( V_80 -> V_126 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_82 , V_138 ) ;
return V_138 ;
}
V_138 = F_31 ( V_80 -> V_126 , V_5 ,
V_238 , 0 ) ;
if ( V_138 != 0 ) {
F_24 ( V_2 , L_83 , V_138 ) ;
return V_138 ;
}
return 0 ;
}
