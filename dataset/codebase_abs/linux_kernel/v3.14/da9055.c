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
case 16 :
V_68 = V_71 ;
break;
case 20 :
V_68 = V_72 ;
break;
case 24 :
V_68 = V_73 ;
break;
case 32 :
V_68 = V_74 ;
break;
default:
return - V_75 ;
}
F_6 ( V_2 , V_76 , V_77 ,
V_68 ) ;
switch ( F_12 ( V_63 ) ) {
case 8000 :
V_69 = V_78 ;
V_70 = 3072000 ;
break;
case 11025 :
V_69 = V_79 ;
V_70 = 2822400 ;
break;
case 12000 :
V_69 = V_80 ;
V_70 = 3072000 ;
break;
case 16000 :
V_69 = V_81 ;
V_70 = 3072000 ;
break;
case 22050 :
V_69 = V_82 ;
V_70 = 2822400 ;
break;
case 32000 :
V_69 = V_83 ;
V_70 = 3072000 ;
break;
case 44100 :
V_69 = V_84 ;
V_70 = 2822400 ;
break;
case 48000 :
V_69 = V_85 ;
V_70 = 3072000 ;
break;
case 88200 :
V_69 = V_86 ;
V_70 = 2822400 ;
break;
case 96000 :
V_69 = V_87 ;
V_70 = 3072000 ;
break;
default:
return - V_75 ;
}
if ( V_67 -> V_88 ) {
F_2 ( V_2 , V_89 , V_69 ) ;
} else {
F_2 ( V_2 , V_89 , V_85 ) ;
}
if ( V_67 -> V_88 && ( V_67 -> V_88 != V_70 ) ) {
if ( ! V_67 -> V_90 ) {
F_6 ( V_2 , V_91 ,
V_92 | V_93 ,
V_92 | V_93 ) ;
} else {
F_6 ( V_2 , V_91 ,
V_92 , V_92 ) ;
}
} else {
F_6 ( V_2 , V_91 , V_92 , 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_64 * V_94 , unsigned int V_95 )
{
struct V_1 * V_2 = V_94 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
T_1 V_96 , V_68 , V_97 ;
switch ( V_95 & V_98 ) {
case V_99 :
V_97 = 1 ;
V_96 = V_100 ;
break;
case V_101 :
V_97 = 0 ;
V_96 = V_102 ;
break;
default:
return - V_75 ;
}
if ( ( F_3 ( V_2 , V_91 ) & V_92 ) &&
( V_67 -> V_90 != V_97 ) )
return - V_75 ;
V_67 -> V_90 = V_97 ;
switch ( V_95 & V_103 ) {
case V_104 :
V_68 = V_105 ;
break;
case V_106 :
V_68 = V_107 ;
break;
case V_108 :
V_68 = V_109 ;
break;
case V_110 :
V_68 = V_111 ;
break;
default:
return - V_75 ;
}
V_96 |= V_112 ;
F_6 ( V_2 , V_113 ,
( V_114 | V_115 ) ,
V_96 ) ;
F_6 ( V_2 , V_76 , V_116 ,
V_68 ) ;
return 0 ;
}
static int F_14 ( struct V_64 * V_65 , int V_117 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
if ( V_117 ) {
F_6 ( V_2 , V_118 ,
V_119 , V_119 ) ;
F_6 ( V_2 , V_120 ,
V_121 , V_121 ) ;
} else {
F_6 ( V_2 , V_118 ,
V_119 , 0 ) ;
F_6 ( V_2 , V_120 ,
V_121 , 0 ) ;
}
return 0 ;
}
static int F_15 ( struct V_64 * V_94 ,
int V_122 , unsigned int V_123 , int V_124 )
{
struct V_1 * V_2 = V_94 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
switch ( V_122 ) {
case V_125 :
switch ( V_123 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 13000000 :
case 13500000 :
case 14400000 :
case 19200000 :
case 19680000 :
case 19800000 :
V_67 -> V_88 = V_123 ;
return 0 ;
default:
F_16 ( V_94 -> V_43 , L_1 ,
V_123 ) ;
return - V_75 ;
}
break;
default:
F_16 ( V_94 -> V_43 , L_2 , V_122 ) ;
return - V_75 ;
}
}
static int F_17 ( struct V_64 * V_94 , int V_126 ,
int V_127 , unsigned int V_128 , unsigned int V_129 )
{
struct V_1 * V_2 = V_94 -> V_2 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
T_1 V_130 , V_131 , V_132 , V_133 ;
F_6 ( V_2 , V_91 , V_92 , 0 ) ;
if ( ! V_67 -> V_90 && ( V_129 != 2822400 ) )
goto V_134;
for ( V_133 = 0 ; V_133 < F_18 ( V_135 ) ; V_133 ++ ) {
if ( ( V_128 == V_135 [ V_133 ] . V_128 ) &&
( V_67 -> V_90 == V_135 [ V_133 ] . V_97 ) &&
( V_129 == V_135 [ V_133 ] . V_129 ) ) {
V_130 = V_135 [ V_133 ] . V_136 ;
V_131 = V_135 [ V_133 ] . V_137 ;
V_132 = V_135 [ V_133 ] . integer ;
break;
}
}
if ( V_133 >= F_18 ( V_135 ) )
goto V_134;
F_2 ( V_2 , V_138 , V_130 ) ;
F_2 ( V_2 , V_139 , V_131 ) ;
F_2 ( V_2 , V_140 , V_132 ) ;
return 0 ;
V_134:
F_16 ( V_94 -> V_43 , L_3 ) ;
return - V_75 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_141 V_142 )
{
switch ( V_142 ) {
case V_143 :
case V_144 :
break;
case V_145 :
if ( V_2 -> V_146 . V_147 == V_148 ) {
F_6 ( V_2 , V_149 ,
V_150 | V_151 ,
V_150 | V_151 ) ;
}
break;
case V_148 :
F_6 ( V_2 , V_149 ,
V_150 | V_151 , 0 ) ;
break;
}
V_2 -> V_146 . V_147 = V_142 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_152 ;
struct V_66 * V_67 = F_10 ( V_2 ) ;
V_2 -> V_153 = V_67 -> V_154 ;
V_152 = F_21 ( V_2 , 8 , 8 , V_155 ) ;
if ( V_152 < 0 ) {
F_16 ( V_2 -> V_43 , L_4 , V_152 ) ;
return V_152 ;
}
F_6 ( V_2 , V_156 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_158 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_159 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_160 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_30 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_31 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_118 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_120 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_161 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_162 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_163 ,
V_157 , V_157 ) ;
F_6 ( V_2 , V_159 ,
V_164 , V_164 ) ;
F_6 ( V_2 , V_160 ,
V_165 , V_165 ) ;
F_6 ( V_2 , V_166 ,
V_167 , V_167 ) ;
F_6 ( V_2 , V_168 ,
V_169 , V_169 ) ;
F_2 ( V_2 , V_91 , V_170 ) ;
if ( V_67 -> V_171 ) {
if ( V_67 -> V_171 -> V_172 ) {
F_6 ( V_2 , V_173 ,
V_174 ,
V_174 ) ;
} else {
F_6 ( V_2 , V_173 ,
V_174 , 0 ) ;
}
switch ( V_67 -> V_171 -> V_175 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
F_6 ( V_2 , V_180 ,
V_181 ,
( V_67 -> V_171 -> V_175 ) << 4 ) ;
break;
}
}
return 0 ;
}
static int F_22 ( struct V_182 * V_183 ,
const struct V_184 * V_185 )
{
struct V_66 * V_67 ;
struct V_186 * V_171 = F_23 ( & V_183 -> V_43 ) ;
int V_152 ;
V_67 = F_24 ( & V_183 -> V_43 , sizeof( struct V_66 ) ,
V_187 ) ;
if ( ! V_67 )
return - V_188 ;
if ( V_171 )
V_67 -> V_171 = V_171 ;
F_25 ( V_183 , V_67 ) ;
V_67 -> V_154 = F_26 ( V_183 , & V_189 ) ;
if ( F_27 ( V_67 -> V_154 ) ) {
V_152 = F_28 ( V_67 -> V_154 ) ;
F_16 ( & V_183 -> V_43 , L_5 , V_152 ) ;
return V_152 ;
}
V_152 = F_29 ( & V_183 -> V_43 ,
& V_190 , & V_191 , 1 ) ;
if ( V_152 < 0 ) {
F_16 ( & V_183 -> V_43 , L_6 ,
V_152 ) ;
}
return V_152 ;
}
static int F_30 ( struct V_182 * V_192 )
{
F_31 ( & V_192 -> V_43 ) ;
return 0 ;
}
