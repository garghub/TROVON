static unsigned int F_1 ( struct V_1
* V_2 )
{
return ( V_2 -> V_3 . V_4 >= 0 ) ;
}
static unsigned int F_2 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return F_3 ( V_6 -> V_8 + V_7 ) ;
}
static void F_4 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_9 )
{
F_5 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static void F_6 ( struct V_5 * V_10 )
{
F_7 ( V_10 -> V_8 ) ;
}
static int F_8 ( struct V_5 * V_10 )
{
V_10 -> V_8 = F_9 ( V_10 -> V_11 , V_12 ) ;
if ( F_10 ( ! V_10 -> V_8 ) )
return - V_13 ;
F_4 ( V_10 , V_14 , V_15 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
if ( V_17 -> V_20 < 0 || V_17 -> V_20 >= V_21 ) {
F_12 ( V_22 L_1 , V_17 -> V_20 ) ;
return - V_23 ;
}
V_2 = & V_24 [ V_17 -> V_20 ] ;
V_19 = V_2 -> V_6 . V_19 ;
F_13 ( V_19 , V_2 -> V_25 . V_26 , sizeof( V_27 ) ,
V_28 ) ;
F_14 ( V_2 -> V_25 . V_29 , V_2 -> V_25 . V_30 ,
V_2 -> V_25 . V_31 ) ;
F_15 ( V_2 -> V_25 . V_29 ) ;
F_13 ( V_19 , V_2 -> V_25 . V_32 , sizeof( V_33 * ) ,
V_28 ) ;
F_13 ( V_19 , V_2 -> V_34 . V_35 , sizeof( V_33 * ) ,
V_28 ) ;
F_13 ( V_19 , V_2 -> V_34 . V_26 , sizeof( V_27 ) ,
V_28 ) ;
F_16 ( & V_36 , & V_2 -> V_6 ) ;
F_17 ( V_2 -> V_37 ) ;
F_18 ( V_2 -> V_34 . V_38 ) ;
F_18 ( V_2 -> V_34 . V_39 ) ;
F_18 ( V_2 -> V_25 . V_38 ) ;
F_18 ( V_2 -> V_25 . V_39 ) ;
F_7 ( V_2 -> V_6 . V_8 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
int V_40 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
V_40 = F_21 ( V_2 -> V_37 ) ;
if ( V_40 ) {
F_12 ( V_22 L_2 ) ;
return V_40 ;
}
V_40 = F_22 ( V_2 -> V_37 , V_6 -> V_41 ) ;
if ( V_40 ) {
F_12 ( V_42 L_3 ) ;
F_23 ( V_2 -> V_37 ) ;
return V_40 ;
}
V_2 -> V_43 = V_44 ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 , unsigned int V_45 ,
unsigned int V_46 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
if ( F_1 ( V_2 ) ||
V_2 -> V_47 )
return;
switch ( V_45 ) {
case 0 :
F_21 ( V_2 -> V_37 ) ;
break;
case 3 :
F_23 ( V_2 -> V_37 ) ;
break;
default:
F_25 ( V_6 -> V_19 , L_4 ,
V_45 ) ;
}
}
static void F_26 ( struct V_5 * V_6 ,
unsigned int V_48 )
{
unsigned long V_49 ;
unsigned long V_50 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
switch ( V_48 ) {
case 300 :
F_4 ( V_6 , V_51 , V_52 ) ;
V_49 = 1 ;
break;
case 600 :
F_4 ( V_6 , V_51 , V_53 ) ;
V_49 = 1 ;
break;
case 1200 :
F_4 ( V_6 , V_51 , V_54 ) ;
V_49 = 1 ;
break;
case 2400 :
F_4 ( V_6 , V_51 , V_55 ) ;
V_49 = 1 ;
break;
case 4800 :
F_4 ( V_6 , V_51 , V_56 ) ;
V_49 = 1 ;
break;
case 9600 :
F_4 ( V_6 , V_51 , V_57 ) ;
V_49 = 2 ;
break;
case 14400 :
F_4 ( V_6 , V_51 , V_58 ) ;
V_49 = 3 ;
break;
case 19200 :
F_4 ( V_6 , V_51 , V_59 ) ;
V_49 = 4 ;
break;
case 28800 :
F_4 ( V_6 , V_51 , V_60 ) ;
V_49 = 6 ;
break;
case 38400 :
F_4 ( V_6 , V_51 , V_61 ) ;
V_49 = 8 ;
break;
case 57600 :
F_4 ( V_6 , V_51 , V_62 ) ;
V_49 = 16 ;
break;
case 76800 :
F_4 ( V_6 , V_51 , V_63 ) ;
V_49 = 16 ;
break;
case 115200 :
F_4 ( V_6 , V_51 , V_64 ) ;
V_49 = 31 ;
break;
case 230400 :
F_4 ( V_6 , V_51 , V_65 ) ;
V_49 = 31 ;
break;
case 460800 :
F_4 ( V_6 , V_51 , V_66 ) ;
V_49 = 31 ;
break;
case 4000000 :
case 3686400 :
case 3200000 :
case 3500000 :
case 3000000 :
case 2500000 :
case 1500000 :
case 1152000 :
case 1000000 :
case 921600 :
F_4 ( V_6 , V_51 , V_66 ) ;
V_49 = 31 ;
break;
default:
F_4 ( V_6 , V_51 , V_57 ) ;
V_48 = 9600 ;
V_49 = 2 ;
break;
}
if ( V_48 > 460800 )
V_6 -> V_41 = V_48 * 16 ;
else
V_6 -> V_41 = V_67 ;
if ( F_22 ( V_2 -> V_37 , V_6 -> V_41 ) ) {
F_12 ( V_42 L_3 ) ;
return;
}
V_50 = V_49 & V_68 ;
V_50 |= V_69 & ( V_49 << 2 ) ;
F_4 ( V_6 , V_70 , V_50 ) ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_71 * V_72 ,
struct V_71 * V_73 )
{
unsigned int V_48 ;
unsigned long V_50 ;
unsigned long V_74 ;
unsigned int V_75 = V_72 -> V_75 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_21 ( V_2 -> V_37 ) ;
V_48 = F_29 ( V_6 , V_72 , V_73 , 200 , 4000000 ) ;
if ( V_48 == 200 )
V_48 = 3200000 ;
F_26 ( V_6 , V_48 ) ;
V_50 = F_2 ( V_6 , V_77 ) ;
V_50 &= ~ V_78 ;
if ( V_79 == ( V_75 & V_79 ) ) {
if ( V_80 == ( V_75 & V_80 ) )
V_50 |= V_81 ;
else if ( V_82 == ( V_75 & V_82 ) )
V_50 |= V_83 ;
else
V_50 |= V_84 ;
}
V_50 &= ~ V_85 ;
switch ( V_75 & V_86 ) {
case V_87 :
V_50 |= V_88 ;
break;
case V_89 :
V_50 |= V_90 ;
break;
case V_91 :
V_50 |= V_92 ;
break;
default:
V_50 |= V_93 ;
break;
}
if ( V_75 & V_94 ) {
V_50 |= V_95 ;
} else {
V_50 |= V_96 ;
}
V_50 |= V_97 ;
F_4 ( V_6 , V_77 , V_50 ) ;
V_50 = F_2 ( V_6 , V_98 ) ;
V_50 &= ~ ( V_99 | V_100 ) ;
if ( V_75 & V_101 ) {
V_50 |= V_99 ;
V_50 |= V_100 ;
}
F_4 ( V_6 , V_98 , V_50 ) ;
V_6 -> V_102 = V_72 -> V_103 & V_104 ;
V_6 -> V_102 |= V_72 -> V_103 & V_105 ;
V_6 -> V_106 = ( V_72 -> V_75 & V_107 ) ;
F_4 ( V_6 , V_108 , 0 ) ;
F_30 ( V_6 , V_75 , V_48 ) ;
F_4 ( V_6 , V_14 , V_109 ) ;
F_4 ( V_6 , V_14 , V_110 ) ;
if ( V_2 -> V_25 . V_111 == V_112 ) {
V_2 -> V_25 . V_111 = V_113 ;
F_31 ( V_2 -> V_114 , NULL , 1 ) ;
}
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
F_23 ( V_2 -> V_37 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
}
static unsigned int F_33 ( struct V_5 * V_6 )
{
unsigned int V_50 ;
unsigned int V_40 = 0 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 -> V_37 ) ;
V_50 = F_2 ( V_6 , V_116 ) ;
if ( V_50 & V_117 )
V_40 = V_118 ;
F_23 ( V_2 -> V_37 ) ;
return V_40 ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
V_2 -> V_34 . V_119 = 0 ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
unsigned int V_50 ;
F_21 ( V_2 -> V_37 ) ;
V_50 = F_2 ( V_6 , V_120 ) ;
V_50 &= ~ V_121 ;
F_4 ( V_6 , V_120 , V_50 ) ;
if ( V_2 -> V_25 . V_111 == V_112 )
F_31 ( V_2 -> V_114 , NULL , 1 ) ;
if ( V_2 -> V_25 . V_111 != V_122 )
V_2 -> V_25 . V_111 = V_123 ;
F_23 ( V_2 -> V_37 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
int V_124 ;
int V_125 ;
T_2 V_126 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
struct V_127 * V_34 = & V_2 -> V_34 ;
struct V_128 * V_129 = & V_2 -> V_6 . V_45 -> V_130 ;
if ( F_37 ( V_129 ) || V_6 -> V_45 -> V_10 . V_131 -> V_132 ) {
F_34 ( V_6 ) ;
return;
}
V_34 -> V_133 = 1 ;
V_125 = F_38 ( V_129 ) ;
if ( V_134 < V_125 )
V_125 = V_134 ;
V_124 = V_135 - V_129 -> V_136 ;
if ( V_125 > V_124 )
V_125 = V_124 ;
V_126 = V_34 -> V_137 + V_129 -> V_136 ;
F_39 ( V_6 -> V_19 , V_126 , V_125 ,
V_28 ) ;
V_34 -> V_38 -> V_138 = ( ( ( V_125 + 15 ) >> 4 ) << 16 ) |
( ( V_125 + 15 ) >> 4 ) ;
V_34 -> V_38 -> V_139 = V_126 ;
F_39 ( V_6 -> V_19 , V_34 -> V_26 ,
sizeof( V_27 ) , V_28 ) ;
* V_34 -> V_39 = V_140 | F_40 ( V_34 -> V_26 ) ;
F_39 ( V_6 -> V_19 , V_34 -> V_35 ,
sizeof( V_33 * ) , V_28 ) ;
V_34 -> V_125 = V_125 ;
F_4 ( V_6 , V_141 , V_125 ) ;
V_2 -> V_115 &= ~ V_142 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
F_41 ( V_2 -> V_143 , & V_34 -> V_144 ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_4 ( V_6 , V_14 , V_145 ) ;
F_4 ( V_6 , V_146 , V_147 ) ;
F_4 ( V_6 , V_14 , V_148 ) ;
V_2 -> V_115 |= V_149 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
V_2 -> V_25 . V_111 = V_112 ;
F_41 ( V_2 -> V_114 , & V_2 -> V_25 . V_144 ) ;
F_43 ( & V_2 -> V_150 , V_2 -> V_151 ,
V_152 ) ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 -> V_37 ) ;
if ( V_2 -> V_47 )
V_2 -> V_47 ( V_6 ) ;
if ( V_2 -> V_34 . V_119 == 0 ) {
V_2 -> V_34 . V_119 = 1 ;
F_36 ( V_6 ) ;
}
F_23 ( V_2 -> V_37 ) ;
}
static void F_45 ( struct V_153 * V_154 ,
unsigned int V_155 ,
struct V_156 * V_157 )
{
unsigned long V_74 ;
struct V_1 * V_2 ;
F_46 ( ( ( ( V_155 & V_158 ) >> 28 ) == 1 ) &&
! ( V_155 & V_159 ) ) ;
V_2 = F_47 ( V_154 , struct V_1 , V_34 . V_144 ) ;
F_28 ( & V_2 -> V_6 . V_76 , V_74 ) ;
F_21 ( V_2 -> V_37 ) ;
V_2 -> V_115 |= V_142 ;
F_4 ( & V_2 -> V_6 , V_108 , V_2 -> V_115 ) ;
F_23 ( V_2 -> V_37 ) ;
F_32 ( & V_2 -> V_6 . V_76 , V_74 ) ;
}
static void F_48 ( struct V_153 * V_154 ,
unsigned int V_155 ,
struct V_156 * V_157 )
{
int V_160 ;
int V_161 ;
unsigned long V_162 ;
unsigned int V_163 = 0 ;
unsigned long V_74 ;
unsigned int V_111 ;
struct V_164 * V_131 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_47 ( V_154 , struct V_1 , V_25 . V_144 ) ;
V_6 = & V_2 -> V_6 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_21 ( V_2 -> V_37 ) ;
V_131 = V_6 -> V_45 -> V_10 . V_131 ;
F_4 ( V_6 , V_14 , V_165 ) ;
V_162 = F_2 ( V_6 , V_116 ) ;
if ( F_10 ( ( V_162 & V_166 ) &&
( V_6 -> V_106 & V_107 ) ) ) {
F_49 ( V_131 , 0 , V_167 ) ;
V_6 -> V_168 . V_169 ++ ;
V_163 = 1 ;
}
if ( ! ( V_6 -> V_102 & V_104 ) )
V_162 = V_162 & ~ ( V_170 ) ;
if ( F_10 ( V_162 & V_170 ) ) {
V_6 -> V_168 . V_171 ++ ;
V_163 = 1 ;
if ( V_6 -> V_102 & V_105 )
F_49 ( V_131 , 0 , V_172 ) ;
}
if ( V_163 )
F_4 ( V_6 , V_14 , V_173 ) ;
if ( V_2 -> V_174 == V_175 )
V_2 -> V_174 = V_176 ;
V_111 = V_2 -> V_25 . V_111 ;
if ( V_111 == V_113 )
F_42 ( V_6 ) ;
if ( V_111 == V_123 )
V_2 -> V_25 . V_111 = V_122 ;
if ( V_111 >= V_177 )
goto V_178;
V_161 = F_2 ( V_6 , V_179 ) ;
if ( 0 != ( V_6 -> V_106 & V_107 ) ) {
V_160 = F_50 ( V_131 , V_2 -> V_25 . V_30 ,
V_161 ) ;
F_51 ( V_160 != V_161 ) ;
}
F_42 ( V_6 ) ;
V_178:
F_23 ( V_2 -> V_37 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
if ( V_111 < V_177 )
F_52 ( V_180 , & V_2 -> V_25 . V_181 ) ;
}
static void F_53 ( struct V_182 * V_183 )
{
struct V_1 * V_2 =
F_47 ( V_183 , struct V_1 , V_25 . V_181 ) ;
struct V_164 * V_131 = V_2 -> V_6 . V_45 -> V_10 . V_131 ;
F_54 ( V_131 ) ;
}
static unsigned int F_55 ( struct V_5 * V_6 )
{
return V_184 | V_185 | V_186 ;
}
static void F_56 ( struct V_5 * V_6 , int V_187 )
{
unsigned int V_50 ;
V_50 = F_2 ( V_6 , V_98 ) ;
if ( V_187 ) {
V_50 |= V_100 ;
F_4 ( V_6 , V_98 , V_50 ) ;
} else {
V_50 &= ~ V_100 ;
F_4 ( V_6 , V_98 , V_50 ) ;
F_4 ( V_6 , V_14 , V_188 ) ;
}
}
static void F_57 ( struct V_5 * V_6 ,
unsigned int V_189 )
{
unsigned int V_187 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 -> V_37 ) ;
V_187 = V_190 & V_189 ? 1 : 0 ;
F_56 ( V_6 , V_187 ) ;
F_23 ( V_2 -> V_37 ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 -> V_37 ) ;
V_2 -> V_115 |= V_191 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
F_23 ( V_2 -> V_37 ) ;
}
static void F_59 ( struct V_5 * V_6 , int V_192 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 -> V_37 ) ;
F_4 ( V_6 , V_14 , V_192 ? V_193 : V_194 ) ;
F_23 ( V_2 -> V_37 ) ;
}
static void F_60 ( struct V_5 * V_6 , int V_195 )
{
unsigned long V_74 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
if ( V_195 & V_196 ) {
V_6 -> type = V_197 ;
F_8 ( V_6 ) ;
}
F_32 ( & V_6 -> V_76 , V_74 ) ;
}
static void F_61 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_21 ( V_2 -> V_37 ) ;
F_4 ( V_6 , V_14 , V_198 ) ;
V_6 -> V_168 . V_199 ++ ;
F_23 ( V_2 -> V_37 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
F_62 ( & V_6 -> V_45 -> V_10 . V_200 ) ;
}
static int F_63 ( struct V_5 * V_6 )
{
unsigned long V_201 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
struct V_128 * V_129 = & V_6 -> V_45 -> V_130 ;
if ( V_2 -> V_43 != V_202 ||
! F_37 ( V_129 ) || V_2 -> V_34 . V_133 ||
( V_2 -> V_115 & V_203 ) ||
! ( V_2 -> V_115 & V_149 ) ) {
return - 1 ;
}
V_201 = F_2 ( V_6 , V_116 ) ;
if ( ! ( V_201 & V_117 ) )
return 0 ;
switch ( V_2 -> V_174 ) {
case V_204 :
V_2 -> V_174 = V_205 ;
F_4 ( V_6 , V_14 , V_206 ) ;
return 0 ;
case V_205 :
case V_175 :
return 0 ;
case V_176 :
break;
}
if ( V_2 -> V_25 . V_111 != V_122 ) {
if ( V_2 -> V_25 . V_111 == V_112 )
F_35 ( V_6 ) ;
return 0 ;
}
F_23 ( V_2 -> V_37 ) ;
V_2 -> V_43 = V_207 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_3 . V_208 = 1 ;
F_64 ( V_2 -> V_3 . V_4 ) ;
}
return 1 ;
}
static enum V_209 F_65 ( struct V_210 * V_211 )
{
unsigned long V_74 ;
int V_40 = V_212 ;
struct V_1 * V_2 = F_47 ( V_211 , struct V_1 ,
V_150 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
if ( ! F_63 ( V_6 ) ) {
F_66 ( V_211 , V_2 -> V_151 ) ;
V_40 = V_213 ;
}
F_32 ( & V_6 -> V_76 , V_74 ) ;
return V_40 ;
}
static T_3 F_67 ( int V_4 , void * V_19 )
{
unsigned long V_74 ;
unsigned long V_214 ;
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_128 * V_129 = & V_6 -> V_45 -> V_130 ;
struct V_127 * V_34 = & V_2 -> V_34 ;
struct V_215 * V_25 = & V_2 -> V_25 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
V_214 = F_2 ( V_6 , V_216 ) ;
if ( V_214 & V_149 ) {
V_2 -> V_115 &= ~ V_149 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
}
if ( V_214 & V_217 ) {
F_4 ( V_6 , V_14 , V_165 ) ;
F_4 ( V_6 , V_14 , V_145 ) ;
if ( V_2 -> V_174 == V_205 )
V_2 -> V_174 =
V_175 ;
if ( V_25 -> V_111 == V_112 ) {
V_25 -> V_111 = V_218 ;
F_31 ( V_2 -> V_114 , NULL , 1 ) ;
}
}
if ( V_214 & V_142 ) {
F_4 ( V_6 , V_14 , V_219 ) ;
if ( V_2 -> V_43 == V_202 ) {
V_2 -> V_115 |= V_203 ;
F_4 ( V_6 , V_108 ,
V_2 -> V_115 ) ;
}
V_129 -> V_136 = ( V_129 -> V_136 + V_34 -> V_125 ) & ~ V_135 ;
V_34 -> V_133 = 0 ;
V_6 -> V_168 . V_34 += V_34 -> V_125 ;
if ( V_34 -> V_119 )
F_36 ( V_6 ) ;
if ( F_38 ( V_129 ) < V_220 )
F_68 ( V_6 ) ;
}
if ( V_214 & V_203 ) {
V_2 -> V_115 &= ~ V_203 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
if ( ! F_63 ( V_6 ) )
F_43 ( & V_2 -> V_150 ,
V_2 -> V_151 ,
V_152 ) ;
}
if ( V_214 & V_191 )
F_61 ( V_6 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
return V_221 ;
}
void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
if ( V_2 -> V_43 == V_44 ) {
V_2 -> V_43 = V_202 ;
V_2 -> V_174 = V_204 ;
if ( ! F_1 ( V_2 ) )
F_56 ( V_6 , 0 ) ;
V_2 -> V_115 |= V_203 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
}
}
void F_70 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_69 ( V_6 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
}
void F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
unsigned int V_50 ;
switch ( V_2 -> V_43 ) {
case V_207 :
F_21 ( V_2 -> V_37 ) ;
F_72 ( V_2 -> V_3 . V_4 ) ;
case V_202 :
if ( V_2 -> V_25 . V_111 == V_123 ||
V_2 -> V_25 . V_111 == V_122 ) {
F_4 ( V_6 , V_14 , V_109 ) ;
V_50 = F_2 ( V_6 , V_120 ) ;
V_50 |= V_121 ;
F_4 ( V_6 , V_120 , V_50 ) ;
}
F_73 ( & V_2 -> V_150 ) ;
if ( V_2 -> V_25 . V_111 == V_122 )
F_42 ( V_6 ) ;
if ( ! F_1 ( V_2 ) )
F_56 ( V_6 , 1 ) ;
if ( V_2 -> V_25 . V_111 == V_123 )
V_2 -> V_25 . V_111 = V_113 ;
V_2 -> V_43 = V_44 ;
break;
case V_44 :
break;
case V_222 :
break;
}
}
void F_74 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_71 ( V_6 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
}
static T_3 F_75 ( int V_4 , void * V_19 )
{
unsigned int V_223 = 0 ;
unsigned long V_74 ;
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_164 * V_131 = NULL ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
if ( V_2 -> V_43 == V_207 ) {
if ( V_2 -> V_3 . V_208 )
V_2 -> V_3 . V_208 = 0 ;
else
V_223 = 1 ;
}
if ( V_223 ) {
F_71 ( V_6 ) ;
if ( V_2 -> V_3 . V_224 ) {
V_131 = V_6 -> V_45 -> V_10 . V_131 ;
F_49 ( V_131 ,
V_2 -> V_3 . V_225 ,
V_226 ) ;
F_52 ( V_180 , & V_2 -> V_25 . V_181 ) ;
}
}
F_32 ( & V_6 -> V_76 , V_74 ) ;
return V_221 ;
}
static const char * F_76 ( struct V_5 * V_10 )
{
return ( V_10 -> type == V_197 ) ? L_5 : NULL ;
}
static int F_77 ( struct V_5 * V_6 )
{
int V_40 ;
int V_227 ;
unsigned long V_74 ;
unsigned int V_50 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
struct V_128 * V_129 = & V_6 -> V_45 -> V_130 ;
struct V_127 * V_34 = & V_2 -> V_34 ;
struct V_215 * V_25 = & V_2 -> V_25 ;
V_227 = V_6 -> V_228 ;
if ( V_227 > 16 )
V_227 -= 16 ;
V_34 -> V_137 = F_78 ( V_6 -> V_19 , V_129 -> V_229 , V_135 ,
V_28 ) ;
V_6 -> V_45 -> V_10 . V_131 -> V_230 = 1 ;
V_40 = F_19 ( V_6 ) ;
if ( F_10 ( V_40 ) ) {
F_12 ( V_22 L_6 ) ;
goto V_231;
}
V_50 = F_2 ( V_6 , V_98 ) ;
V_50 &= ~ V_232 ;
V_50 &= ~ V_233 ;
V_50 |= ( V_232 & ( V_227 << 2 ) ) ;
V_50 |= ( V_233 & V_227 ) ;
F_4 ( V_6 , V_98 , V_50 ) ;
V_50 = F_2 ( V_6 , V_70 ) ;
if ( ! V_50 ) {
V_50 |= 0x1f & V_68 ;
F_4 ( V_6 , V_70 , V_50 ) ;
}
V_50 = V_234 | V_121 ;
F_4 ( V_6 , V_120 , V_50 ) ;
F_4 ( V_6 , V_14 , V_110 ) ;
F_4 ( V_6 , V_14 , V_109 ) ;
F_4 ( V_6 , V_14 , V_173 ) ;
F_4 ( V_6 , V_14 , V_235 ) ;
F_4 ( V_6 , V_14 , V_145 ) ;
F_4 ( V_6 , V_14 , V_198 ) ;
F_4 ( V_6 , V_14 , V_236 ) ;
F_4 ( V_6 , V_14 , V_237 ) ;
F_4 ( V_6 , V_14 , V_238 ) ;
V_34 -> V_119 = 0 ;
V_34 -> V_133 = 0 ;
V_34 -> V_144 . V_239 = F_45 ;
V_34 -> V_144 . V_240 = NULL ;
V_34 -> V_38 -> V_241 = V_242 |
F_79 ( V_2 -> V_243 ) | V_244 ;
V_34 -> V_38 -> V_245 = ( V_246 << 16 )
| ( V_246 ) ;
V_34 -> V_38 -> V_247 = ( V_246 << 16 ) ;
V_34 -> V_38 -> V_248 =
V_2 -> V_6 . V_11 + V_249 ;
V_25 -> V_144 . V_239 = F_48 ;
V_25 -> V_144 . V_240 = NULL ;
V_25 -> V_38 -> V_241 = V_242 |
F_80 ( V_2 -> V_250 ) | V_244 ;
V_25 -> V_38 -> V_245 = ( V_246 << 16 )
| ( V_246 ) ;
V_25 -> V_38 -> V_247 = V_246 ;
V_25 -> V_38 -> V_139 = V_6 -> V_11 + V_251 ;
V_2 -> V_115 |= V_217 ;
V_2 -> V_115 |= V_252 ;
F_4 ( V_6 , V_253 , 0 ) ;
V_40 = F_81 ( V_6 -> V_4 , F_67 , V_254 ,
L_7 , V_2 ) ;
if ( F_10 ( V_40 ) ) {
F_12 ( V_22 L_8 ) ;
goto V_255;
}
if ( F_1 ( V_2 ) ) {
V_40 = F_81 ( V_2 -> V_3 . V_4 ,
F_75 ,
V_256 ,
L_9 , V_2 ) ;
if ( F_10 ( V_40 ) ) {
F_12 ( V_22 L_10 ) ;
F_82 ( V_6 -> V_4 , V_2 ) ;
goto V_255;
}
F_83 ( V_2 -> V_3 . V_4 ) ;
}
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_4 ( V_6 , V_257 , 0 ) ;
F_42 ( V_6 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
V_40 = F_84 ( V_6 -> V_19 ) ;
if ( V_40 )
F_25 ( V_6 -> V_19 , L_11 , V_40 ) ;
F_85 ( V_6 -> V_19 ) ;
return 0 ;
V_255:
V_231:
F_13 ( V_6 -> V_19 , V_34 -> V_137 ,
V_135 , V_28 ) ;
return V_40 ;
}
static int T_4 F_86 ( struct V_5 * V_6 )
{
int V_40 = 0 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
struct V_127 * V_34 = & V_2 -> V_34 ;
struct V_215 * V_25 = & V_2 -> V_25 ;
V_34 -> V_38 = F_87 ( sizeof( V_27 ) , V_258 | V_259 ) ;
if ( ! V_34 -> V_38 )
return - V_13 ;
V_34 -> V_39 = F_87 ( sizeof( V_33 * ) , V_258 | V_259 ) ;
if ( ! V_34 -> V_39 ) {
V_40 = - V_13 ;
goto V_260;
}
V_34 -> V_26 = F_78 ( V_6 -> V_19 , V_34 -> V_38 ,
sizeof( V_27 ) , V_28 ) ;
V_34 -> V_35 = F_78 ( V_6 -> V_19 ,
V_34 -> V_39 ,
sizeof( V_33 * ) , V_28 ) ;
V_34 -> V_144 . V_261 = F_40 ( V_34 -> V_35 ) ;
F_88 ( & V_25 -> V_262 ) ;
V_25 -> V_29 = F_89 ( L_12 , V_6 -> V_19 ,
V_147 , 16 , 0 ) ;
if ( ! V_25 -> V_29 ) {
F_90 ( L_13 , V_263 ) ;
V_40 = - V_13 ;
goto V_264;
}
V_25 -> V_30 = F_91 ( V_25 -> V_29 , V_258 , & V_25 -> V_31 ) ;
if ( ! V_25 -> V_30 ) {
F_90 ( L_14 , V_263 ) ;
V_40 = - V_13 ;
goto V_265;
}
V_25 -> V_38 = F_87 ( sizeof( V_27 ) , V_258 | V_259 ) ;
if ( ! V_25 -> V_38 ) {
F_90 ( L_15 , V_263 ) ;
V_40 = - V_13 ;
goto V_266;
}
V_25 -> V_39 = F_87 ( sizeof( V_33 * ) , V_258 | V_259 ) ;
if ( ! V_25 -> V_39 ) {
F_90 ( L_16 , V_263 ) ;
V_40 = - V_13 ;
goto V_267;
}
V_25 -> V_38 -> V_138 = ( ( V_147 >> 4 ) << 16 ) |
( V_147 >> 4 ) ;
V_25 -> V_38 -> V_248 = V_25 -> V_31 ;
V_25 -> V_26 = F_78 ( V_6 -> V_19 , V_25 -> V_38 ,
sizeof( V_27 ) , V_28 ) ;
* V_25 -> V_39 = V_140 | F_40 ( V_25 -> V_26 ) ;
V_25 -> V_32 = F_78 ( V_6 -> V_19 , V_25 -> V_39 ,
sizeof( V_33 * ) , V_28 ) ;
V_25 -> V_144 . V_261 = F_40 ( V_25 -> V_32 ) ;
F_92 ( & V_25 -> V_181 , F_53 ) ;
return V_40 ;
V_267:
F_18 ( V_25 -> V_38 ) ;
V_266:
F_14 ( V_2 -> V_25 . V_29 , V_2 -> V_25 . V_30 ,
V_2 -> V_25 . V_31 ) ;
V_265:
F_15 ( V_2 -> V_25 . V_29 ) ;
V_264:
F_13 ( V_6 -> V_19 , V_2 -> V_34 . V_35 ,
sizeof( V_33 * ) , V_28 ) ;
F_13 ( V_6 -> V_19 , V_2 -> V_34 . V_26 ,
sizeof( V_27 ) , V_28 ) ;
F_18 ( V_2 -> V_34 . V_39 ) ;
V_260:
F_18 ( V_2 -> V_34 . V_38 ) ;
return V_40 ;
}
static int T_4 F_93 ( struct V_16 * V_17 )
{
int V_40 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_268 * V_268 ;
const struct V_269 * V_270 =
V_17 -> V_19 . V_271 ;
if ( V_17 -> V_20 < 0 || V_17 -> V_20 >= V_21 ) {
F_12 ( V_22 L_1 , V_17 -> V_20 ) ;
return - V_23 ;
}
V_2 = & V_24 [ V_17 -> V_20 ] ;
V_6 = & V_2 -> V_6 ;
V_6 -> V_19 = & V_17 -> V_19 ;
V_268 = F_94 ( V_17 , V_272 , 0 ) ;
if ( F_10 ( ! V_268 ) )
return - V_273 ;
V_6 -> V_11 = V_268 -> V_274 ;
V_6 -> V_4 = F_95 ( V_17 , 0 ) ;
if ( F_10 ( V_6 -> V_4 < 0 ) )
return - V_273 ;
if ( F_10 ( F_96 ( V_6 -> V_4 , 1 ) ) )
return - V_273 ;
if ( V_270 == NULL || V_270 -> V_275 < 0 )
V_2 -> V_3 . V_4 = - 1 ;
else {
V_2 -> V_3 . V_4 = V_270 -> V_275 ;
V_2 -> V_3 . V_208 = 1 ;
V_2 -> V_3 . V_224 = V_270 -> V_276 ;
V_2 -> V_3 . V_225 = V_270 -> V_225 ;
if ( F_10 ( V_2 -> V_3 . V_4 < 0 ) )
return - V_273 ;
if ( F_10 ( F_96 ( V_2 -> V_3 . V_4 , 1 ) ) )
return - V_273 ;
}
if ( V_270 == NULL )
V_2 -> V_47 = NULL ;
else
V_2 -> V_47 = V_270 -> V_47 ;
V_268 = F_97 ( V_17 , V_277 ,
L_17 ) ;
if ( F_10 ( ! V_268 ) )
return - V_273 ;
V_2 -> V_143 = V_268 -> V_274 ;
V_2 -> V_114 = V_268 -> V_278 ;
V_268 = F_97 ( V_17 , V_277 ,
L_18 ) ;
if ( F_10 ( ! V_268 ) )
return - V_273 ;
V_2 -> V_243 = V_268 -> V_274 ;
V_2 -> V_250 = V_268 -> V_278 ;
V_6 -> V_279 = V_280 ;
V_6 -> V_228 = V_281 ;
V_6 -> V_282 = & V_283 ;
V_6 -> V_74 = V_284 ;
V_6 -> V_41 = V_67 ;
V_2 -> V_115 = 0x0 ;
V_2 -> V_37 = F_98 ( & V_17 -> V_19 , L_19 ) ;
if ( F_99 ( V_2 -> V_37 ) )
return F_100 ( V_2 -> V_37 ) ;
V_40 = F_86 ( V_6 ) ;
if ( F_10 ( V_40 ) )
return V_40 ;
V_2 -> V_43 = V_222 ;
F_101 ( & V_2 -> V_150 , V_285 ,
V_152 ) ;
V_2 -> V_150 . V_286 = F_65 ;
V_2 -> V_151 = F_102 ( 0 , 1000000 ) ;
V_6 -> line = V_17 -> V_20 ;
return F_103 ( & V_36 , V_6 ) ;
}
static int T_5 F_104 ( void )
{
int V_40 , V_287 ;
for ( V_287 = 0 ; V_287 < V_21 ; V_287 ++ )
V_24 [ V_287 ] . V_6 . type = V_288 ;
V_180 = F_105 ( L_20 ) ;
if ( F_10 ( ! V_180 ) )
return - V_13 ;
V_40 = F_106 ( & V_36 ) ;
if ( F_10 ( V_40 ) ) {
F_12 ( V_22 L_21 , V_263 ) ;
goto V_289;
}
V_40 = F_107 ( & V_290 ) ;
if ( V_40 ) {
F_12 ( V_22 L_21 , V_263 ) ;
goto V_291;
}
return V_40 ;
V_291:
F_108 ( & V_36 ) ;
V_289:
F_109 ( V_180 ) ;
return V_40 ;
}
static void F_110 ( struct V_5 * V_6 )
{
unsigned long V_74 ;
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_51 ( V_2 -> V_25 . V_111 < V_123 ) ;
F_28 ( & V_6 -> V_76 , V_74 ) ;
F_21 ( V_2 -> V_37 ) ;
F_4 ( V_6 , V_14 , V_292 ) ;
F_4 ( V_6 , V_14 , V_293 ) ;
F_111 ( V_6 -> V_19 ) ;
F_112 ( V_6 -> V_19 ) ;
F_82 ( V_6 -> V_4 , V_2 ) ;
if ( F_1 ( V_2 ) )
F_82 ( V_2 -> V_3 . V_4 , V_2 ) ;
V_2 -> V_115 = 0 ;
F_4 ( V_6 , V_108 , V_2 -> V_115 ) ;
F_113 ( V_2 -> V_25 . V_262 , V_2 -> V_25 . V_111 == V_122 ) ;
F_23 ( V_2 -> V_37 ) ;
if ( V_2 -> V_43 != V_207 )
F_23 ( V_2 -> V_37 ) ;
V_2 -> V_43 = V_222 ;
F_13 ( V_6 -> V_19 , V_2 -> V_34 . V_137 ,
V_135 , V_28 ) ;
F_32 ( & V_6 -> V_76 , V_74 ) ;
if ( F_114 ( & V_2 -> V_25 . V_181 ) )
F_53 ( & V_2 -> V_25 . V_181 ) ;
}
static void T_6 F_115 ( void )
{
F_116 ( V_180 ) ;
F_109 ( V_180 ) ;
F_117 ( & V_290 ) ;
F_108 ( & V_36 ) ;
}
static int F_118 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_119 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = F_47 ( V_19 , struct
V_16 , V_19 ) ;
struct V_1 * V_2 = & V_24 [ V_17 -> V_20 ] ;
F_74 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = F_47 ( V_19 , struct
V_16 , V_19 ) ;
struct V_1 * V_2 = & V_24 [ V_17 -> V_20 ] ;
F_70 ( & V_2 -> V_6 ) ;
return 0 ;
}
