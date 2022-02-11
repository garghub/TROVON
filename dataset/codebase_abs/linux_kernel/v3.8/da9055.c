static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 , V_5 ;
int V_6 = 0 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ;
V_7 ++ ) {
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
V_4 = F_3 ( V_2 , V_11 ) ;
F_2 ( V_2 , V_9 ,
V_3 | V_12 ) ;
V_5 = F_3 ( V_2 , V_11 ) ;
V_6 += ( ( V_4 << 8 ) | ( V_5 << 16 ) ) ;
}
return V_6 / V_8 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
T_1 V_3 , V_17 , V_18 , V_19 , V_20 ;
int V_21 , V_22 , V_23 , V_24 ;
if ( V_16 -> V_25 . integer . V_25 [ 0 ] ) {
V_19 = F_3 ( V_2 , V_26 ) ;
V_20 = F_3 ( V_2 , V_27 ) ;
F_6 ( V_2 , V_26 ,
V_28 , V_28 ) ;
F_6 ( V_2 , V_27 ,
V_29 , V_29 ) ;
V_17 = F_3 ( V_2 , V_30 ) ;
V_18 = F_3 ( V_2 , V_31 ) ;
F_6 ( V_2 , V_30 ,
V_32 , V_32 ) ;
F_6 ( V_2 , V_31 ,
V_33 , V_33 ) ;
V_21 = F_1 ( V_2 ,
V_34 ) ;
V_22 = F_1 ( V_2 ,
V_35 ) ;
V_23 = - V_21 ;
V_24 = - V_22 ;
V_3 = ( V_23 & V_36 ) >> 8 ;
F_2 ( V_2 , V_37 , V_3 ) ;
V_3 = ( V_23 & V_38 ) >> 16 ;
F_2 ( V_2 , V_39 , V_3 ) ;
V_3 = ( V_24 & V_36 ) >> 8 ;
F_2 ( V_2 , V_40 , V_3 ) ;
V_3 = ( V_24 & V_38 ) >> 16 ;
F_2 ( V_2 , V_41 , V_3 ) ;
F_2 ( V_2 , V_30 , V_17 ) ;
F_2 ( V_2 , V_31 , V_18 ) ;
F_2 ( V_2 , V_26 , V_19 ) ;
F_2 ( V_2 , V_27 , V_20 ) ;
}
return F_7 ( V_14 , V_16 ) ;
}
static bool F_8 ( struct V_42 * V_43 ,
unsigned int V_44 )
{
switch ( V_44 ) {
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
case V_11 :
return 1 ;
default:
return 0 ;
}
}
static int F_9 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
T_1 V_68 , V_69 ;
T_2 V_70 ;
switch ( F_11 ( V_63 ) ) {
case V_71 :
V_68 = V_72 ;
break;
case V_73 :
V_68 = V_74 ;
break;
case V_75 :
V_68 = V_76 ;
break;
case V_77 :
V_68 = V_78 ;
break;
default:
return - V_79 ;
}
F_6 ( V_2 , V_80 , V_81 ,
V_68 ) ;
switch ( F_12 ( V_63 ) ) {
case 8000 :
V_69 = V_82 ;
V_70 = 3072000 ;
break;
case 11025 :
V_69 = V_83 ;
V_70 = 2822400 ;
break;
case 12000 :
V_69 = V_84 ;
V_70 = 3072000 ;
break;
case 16000 :
V_69 = V_85 ;
V_70 = 3072000 ;
break;
case 22050 :
V_69 = V_86 ;
V_70 = 2822400 ;
break;
case 32000 :
V_69 = V_87 ;
V_70 = 3072000 ;
break;
case 44100 :
V_69 = V_88 ;
V_70 = 2822400 ;
break;
case 48000 :
V_69 = V_89 ;
V_70 = 3072000 ;
break;
case 88200 :
V_69 = V_90 ;
V_70 = 2822400 ;
break;
case 96000 :
V_69 = V_91 ;
V_70 = 3072000 ;
break;
default:
return - V_79 ;
}
if ( V_67 -> V_92 ) {
F_2 ( V_2 , V_93 , V_69 ) ;
} else {
F_2 ( V_2 , V_93 , V_89 ) ;
}
if ( V_67 -> V_92 && ( V_67 -> V_92 != V_70 ) ) {
if ( ! V_67 -> V_94 ) {
F_6 ( V_2 , V_95 ,
V_96 | V_97 ,
V_96 | V_97 ) ;
} else {
F_6 ( V_2 , V_95 ,
V_96 , V_96 ) ;
}
} else {
F_6 ( V_2 , V_95 , V_96 , 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_64 * V_98 , unsigned int V_99 )
{
struct V_1 * V_2 = V_98 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
T_1 V_100 , V_68 , V_101 ;
switch ( V_99 & V_102 ) {
case V_103 :
V_101 = 1 ;
V_100 = V_104 ;
break;
case V_105 :
V_101 = 0 ;
V_100 = V_106 ;
break;
default:
return - V_79 ;
}
if ( ( F_3 ( V_2 , V_95 ) & V_96 ) &&
( V_67 -> V_94 != V_101 ) )
return - V_79 ;
V_67 -> V_94 = V_101 ;
switch ( V_99 & V_107 ) {
case V_108 :
V_68 = V_109 ;
break;
case V_110 :
V_68 = V_111 ;
break;
case V_112 :
V_68 = V_113 ;
break;
case V_114 :
V_68 = V_115 ;
break;
default:
return - V_79 ;
}
V_100 |= V_116 ;
F_6 ( V_2 , V_117 ,
( V_118 | V_119 ) ,
V_100 ) ;
F_6 ( V_2 , V_80 , V_120 ,
V_68 ) ;
return 0 ;
}
static int F_14 ( struct V_64 * V_65 , int V_121 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
if ( V_121 ) {
F_6 ( V_2 , V_122 ,
V_123 , V_123 ) ;
F_6 ( V_2 , V_124 ,
V_125 , V_125 ) ;
} else {
F_6 ( V_2 , V_122 ,
V_123 , 0 ) ;
F_6 ( V_2 , V_124 ,
V_125 , 0 ) ;
}
return 0 ;
}
static int F_15 ( struct V_64 * V_98 ,
int V_126 , unsigned int V_127 , int V_128 )
{
struct V_1 * V_2 = V_98 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
switch ( V_126 ) {
case V_129 :
switch ( V_127 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 13000000 :
case 13500000 :
case 14400000 :
case 19200000 :
case 19680000 :
case 19800000 :
V_67 -> V_92 = V_127 ;
return 0 ;
default:
F_16 ( V_98 -> V_43 , L_1 ,
V_127 ) ;
return - V_79 ;
}
break;
default:
F_16 ( V_98 -> V_43 , L_2 , V_126 ) ;
return - V_79 ;
}
}
static int F_17 ( struct V_64 * V_98 , int V_130 ,
int V_131 , unsigned int V_132 , unsigned int V_133 )
{
struct V_1 * V_2 = V_98 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
T_1 V_134 , V_135 , V_136 , V_137 ;
F_6 ( V_2 , V_95 , V_96 , 0 ) ;
if ( ! V_67 -> V_94 && ( V_133 != 2822400 ) )
goto V_138;
for ( V_137 = 0 ; V_137 < F_18 ( V_139 ) ; V_137 ++ ) {
if ( ( V_132 == V_139 [ V_137 ] . V_132 ) &&
( V_67 -> V_94 == V_139 [ V_137 ] . V_101 ) &&
( V_133 == V_139 [ V_137 ] . V_133 ) ) {
V_134 = V_139 [ V_137 ] . V_140 ;
V_135 = V_139 [ V_137 ] . V_141 ;
V_136 = V_139 [ V_137 ] . integer ;
break;
}
}
if ( V_137 >= F_18 ( V_139 ) )
goto V_138;
F_2 ( V_2 , V_142 , V_134 ) ;
F_2 ( V_2 , V_143 , V_135 ) ;
F_2 ( V_2 , V_144 , V_136 ) ;
return 0 ;
V_138:
F_16 ( V_98 -> V_43 , L_3 ) ;
return - V_79 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_145 V_146 )
{
switch ( V_146 ) {
case V_147 :
case V_148 :
break;
case V_149 :
if ( V_2 -> V_150 . V_151 == V_152 ) {
F_6 ( V_2 , V_153 ,
V_154 | V_155 ,
V_154 | V_155 ) ;
}
break;
case V_152 :
F_6 ( V_2 , V_153 ,
V_154 | V_155 , 0 ) ;
break;
}
V_2 -> V_150 . V_151 = V_146 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_156 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
V_2 -> V_157 = V_67 -> V_158 ;
V_156 = F_21 ( V_2 , 8 , 8 , V_159 ) ;
if ( V_156 < 0 ) {
F_16 ( V_2 -> V_43 , L_4 , V_156 ) ;
return V_156 ;
}
F_6 ( V_2 , V_160 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_162 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_163 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_164 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_30 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_31 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_122 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_124 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_165 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_166 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_167 ,
V_161 , V_161 ) ;
F_6 ( V_2 , V_163 ,
V_168 , V_168 ) ;
F_6 ( V_2 , V_164 ,
V_169 , V_169 ) ;
F_6 ( V_2 , V_170 ,
V_171 , V_171 ) ;
F_6 ( V_2 , V_172 ,
V_173 , V_173 ) ;
F_2 ( V_2 , V_95 , V_174 ) ;
if ( V_67 -> V_175 ) {
if ( V_67 -> V_175 -> V_176 ) {
F_6 ( V_2 , V_177 ,
V_178 ,
V_178 ) ;
} else {
F_6 ( V_2 , V_177 ,
V_178 , 0 ) ;
}
switch ( V_67 -> V_175 -> V_179 ) {
case V_180 :
case V_181 :
case V_182 :
case V_183 :
F_6 ( V_2 , V_184 ,
V_185 ,
( V_67 -> V_175 -> V_179 ) << 4 ) ;
break;
}
}
return 0 ;
}
static int F_22 ( struct V_186 * V_187 ,
const struct V_188 * V_189 )
{
struct V_66 * V_67 ;
struct V_190 * V_175 = F_23 ( & V_187 -> V_43 ) ;
int V_156 ;
V_67 = F_24 ( & V_187 -> V_43 , sizeof( struct V_66 ) ,
V_191 ) ;
if ( ! V_67 )
return - V_192 ;
if ( V_175 )
V_67 -> V_175 = V_175 ;
F_25 ( V_187 , V_67 ) ;
V_67 -> V_158 = F_26 ( V_187 , & V_193 ) ;
if ( F_27 ( V_67 -> V_158 ) ) {
V_156 = F_28 ( V_67 -> V_158 ) ;
F_16 ( & V_187 -> V_43 , L_5 , V_156 ) ;
return V_156 ;
}
V_156 = F_29 ( & V_187 -> V_43 ,
& V_194 , & V_195 , 1 ) ;
if ( V_156 < 0 ) {
F_16 ( & V_187 -> V_43 , L_6 ,
V_156 ) ;
}
return V_156 ;
}
static int F_30 ( struct V_186 * V_196 )
{
F_31 ( & V_196 -> V_43 ) ;
return 0 ;
}
