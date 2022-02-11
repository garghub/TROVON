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
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_3 ( V_60 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_64 , V_21 ) ;
if ( V_3 & V_65 )
V_62 -> V_66 . integer . V_66 [ 0 ] = 1 ;
else
V_62 -> V_66 . integer . V_66 [ 0 ] = 0 ;
return 0 ;
}
static int F_5 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_3 ( V_60 ) ;
unsigned int V_67 , V_68 ;
unsigned int V_69 ;
if ( V_62 -> V_66 . integer . V_66 [ 0 ] != 0
&& V_62 -> V_66 . integer . V_66 [ 0 ] != 1 )
return - V_70 ;
V_69 = F_4 ( V_64 , V_21 ) ;
switch ( ( V_69 & V_65 ) >> V_71 ) {
case 0 :
if ( ! V_62 -> V_66 . integer . V_66 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_62 -> V_66 . integer . V_66 [ 0 ] )
return 0 ;
break;
}
V_67 = F_4 ( V_64 , V_6 ) ;
V_68 = F_4 ( V_64 , V_7 ) ;
F_6 ( V_64 , V_6 ,
V_72 | V_73 , 0 ) ;
F_6 ( V_64 , V_7 ,
V_74 | V_75 , 0 ) ;
F_6 ( V_64 , V_11 ,
V_76 , V_77 ) ;
F_6 ( V_64 , V_21 ,
V_78 ,
V_62 -> V_66 . integer . V_66 [ 0 ]
<< V_71 ) ;
F_7 ( V_64 , V_6 , V_67 ) ;
F_7 ( V_64 , V_7 , V_68 ) ;
return 0 ;
}
static int F_8 ( struct V_63 * V_64 )
{
return F_7 ( V_64 , V_4 , 0x0 ) ;
}
static int F_9 ( struct V_79 * V_80 , int V_81 )
{
struct V_63 * V_64 = V_80 -> V_64 ;
return F_6 ( V_64 , V_14 ,
V_82 ,
! ! V_81 << V_83 ) ;
}
static int F_10 ( struct V_79 * V_80 , unsigned int V_84 )
{
struct V_63 * V_64 ;
T_1 V_85 , V_86 , V_87 , V_88 ;
V_64 = V_80 -> V_64 ;
switch ( V_84 & V_89 ) {
case V_90 :
V_85 = 0x2 ;
break;
case V_91 :
V_85 = 0x0 ;
break;
case V_92 :
V_85 = 0x1 ;
break;
case V_93 :
case V_94 :
V_85 = 0x3 ;
break;
default:
F_11 ( V_80 -> V_2 , L_1 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_95 , V_85 << V_96 ) ;
switch ( V_84 & V_97 ) {
case V_98 :
V_86 = 1 ;
break;
case V_99 :
V_86 = 0 ;
break;
default:
F_11 ( V_80 -> V_2 , L_2 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_10 ,
V_100 , V_86 << V_101 ) ;
switch ( V_84 & V_89 ) {
case V_93 :
case V_94 :
switch ( V_84 & V_102 ) {
case V_103 :
case V_104 :
return - V_70 ;
default:
break;
}
break;
default:
break;
}
V_87 = V_88 = 0 ;
switch ( V_84 & V_102 ) {
case V_105 :
break;
case V_103 :
V_87 = V_88 = 1 ;
break;
case V_106 :
V_87 = 1 ;
break;
case V_104 :
V_88 = 1 ;
break;
default:
F_11 ( V_80 -> V_2 , L_3 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_107 , V_88 << V_108 ) ;
F_6 ( V_64 , V_8 ,
V_109 , V_87 << V_110 ) ;
return 0 ;
}
static int F_12 ( struct V_111 * V_112 ,
struct V_113 * V_114 ,
struct V_79 * V_80 )
{
int V_115 ;
struct V_63 * V_64 ;
struct V_116 * V_117 ;
T_1 V_118 , V_119 ;
unsigned int V_120 ;
int V_121 ;
V_64 = V_80 -> V_64 ;
V_117 = F_13 ( V_64 ) ;
V_117 -> V_122 = F_14 ( V_114 ) ;
if ( ( int ) V_117 -> V_122 < 0 )
return V_117 -> V_122 ;
switch ( F_15 ( V_114 ) ) {
case 16 :
V_118 = 0x0 ;
break;
case 20 :
V_118 = 0x1 ;
break;
case 24 :
V_118 = 0x2 ;
break;
case 32 :
V_118 = 0x3 ;
break;
default:
F_11 ( V_80 -> V_2 , L_4 ,
F_15 ( V_114 ) ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_123 , V_118 << V_124 ) ;
V_119 = 0 ;
V_121 = abs ( V_125 [ 0 ] - F_16 ( V_114 ) ) ;
for ( V_115 = 1 ; V_115 < F_17 ( V_125 ) ; ++ V_115 ) {
if ( abs ( V_125 [ V_115 ] - F_16 ( V_114 ) ) >= V_121 )
continue;
V_119 = V_115 ;
V_121 = abs ( V_125 [ V_115 ] - F_16 ( V_114 ) ) ;
}
F_18 ( V_80 -> V_2 , L_5 , V_125 [ V_119 ] ) ;
F_6 ( V_64 , V_11 ,
V_126 , V_119 << V_127 ) ;
F_18 ( V_80 -> V_2 , L_6 , V_117 -> V_122 ) ;
F_18 ( V_80 -> V_2 , L_7 , V_117 -> V_128 ) ;
for ( V_115 = 0 ; V_115 < F_17 ( V_129 ) ; ++ V_115 ) {
if ( V_117 -> V_128 / F_16 ( V_114 )
== V_129 [ V_115 ] . V_130 )
break;
}
if ( V_115 == F_17 ( V_129 ) ) {
F_11 ( V_80 -> V_2 , L_8 ,
V_117 -> V_128 , F_16 ( V_114 ) ) ;
return - V_70 ;
}
F_18 ( V_80 -> V_2 , L_9 , V_129 [ V_115 ] . V_130 ) ;
F_6 ( V_64 , V_10 ,
V_131 , V_115 << V_132 ) ;
V_120 = ( V_117 -> V_128 / V_129 [ V_115 ] . div ) * 10 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_133 ) ; ++ V_115 ) {
if ( V_117 -> V_122 == V_120 / V_133 [ V_115 ] )
break;
}
if ( V_115 == F_17 ( V_133 ) ) {
F_11 ( V_80 -> V_2 , L_10 ) ;
return - V_70 ;
}
F_18 ( V_80 -> V_2 , L_11 , V_115 ) ;
F_6 ( V_64 , V_10 ,
V_134 , V_115 << V_135 ) ;
return 0 ;
}
static int F_19 ( struct V_136 * V_136 , unsigned int V_137 ,
unsigned int V_138 )
{
T_2 V_139 ;
unsigned long int V_140 , V_141 , V_142 ;
V_136 -> V_143 = 0 ;
V_141 = V_137 / V_138 ;
if ( V_141 < 6 ) {
V_138 >>= 1 ;
V_136 -> V_143 = 1 ;
V_141 = V_137 / V_138 ;
}
if ( V_141 < 6 || V_141 > 12 ) {
F_20 ( V_144 L_12
L_13 , V_145 , V_141 ) ;
return - V_70 ;
}
V_136 -> V_146 = V_141 ;
V_142 = V_137 % V_138 ;
V_139 = V_147 * ( T_2 ) V_142 ;
F_21 ( V_139 , V_138 ) ;
V_140 = V_139 & 0xffffffff ;
if ( ( V_140 % 10 ) >= 5 )
V_140 += 5 ;
V_140 /= 10 ;
V_136 -> V_148 = V_140 ;
return 0 ;
}
static int F_22 ( struct V_79 * V_80 , int V_149 ,
int V_138 , unsigned int V_150 ,
unsigned int V_151 )
{
int V_152 ;
struct V_63 * V_64 ;
struct V_136 V_136 ;
V_64 = V_80 -> V_64 ;
if ( ! V_150 || ! V_151 ) {
F_6 ( V_64 , V_5 ,
V_153 , 0 ) ;
} else {
V_152 = F_19 ( & V_136 , V_151 * 4 * 2 , V_150 ) ;
if ( V_152 )
return V_152 ;
F_7 ( V_64 , V_36 ,
( V_136 . V_143 << V_154 )
| V_136 . V_146 ) ;
F_7 ( V_64 , V_39 , V_136 . V_148 & 0x1ff ) ;
F_7 ( V_64 , V_38 , ( V_136 . V_148 >> 9 ) & 0x1ff ) ;
F_7 ( V_64 , V_37 , ( V_136 . V_148 >> 18 ) ) ;
F_6 ( V_64 , V_10 ,
V_155 , V_156 ) ;
F_6 ( V_64 , V_5 ,
V_153 , V_157 ) ;
}
return 0 ;
}
static int F_23 ( struct V_79 * V_80 ,
int V_158 , unsigned int V_159 , int V_160 )
{
struct V_63 * V_64 ;
struct V_116 * V_117 ;
V_64 = V_80 -> V_64 ;
V_117 = F_13 ( V_64 ) ;
switch ( V_158 ) {
case V_161 :
F_6 ( V_64 , V_10 ,
V_155 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_153 , 0 ) ;
break;
case V_162 :
F_6 ( V_64 , V_10 ,
V_155 , V_156 ) ;
break;
default:
F_11 ( V_80 -> V_2 , L_14 , V_158 ) ;
return - V_70 ;
}
V_117 -> V_128 = V_159 ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 ,
enum V_163 V_164 )
{
int V_152 ;
struct V_116 * V_117 ;
V_117 = F_13 ( V_64 ) ;
switch ( V_164 ) {
case V_165 :
case V_166 :
F_6 ( V_64 , V_5 ,
V_167 ,
1 << V_168 ) ;
break;
case V_169 :
if ( F_25 ( V_64 ) == V_170 ) {
V_152 = F_26 ( F_17 ( V_117 -> V_171 ) ,
V_117 -> V_171 ) ;
if ( V_152 ) {
F_11 ( V_64 -> V_2 ,
L_15 ,
V_152 ) ;
return V_152 ;
}
F_27 ( V_117 -> V_172 ) ;
F_6 ( V_64 , V_41 ,
V_173 ,
V_174 ) ;
F_6 ( V_64 , V_48 ,
V_175 , V_176 ) ;
F_6 ( V_64 , V_48 ,
V_177 ,
V_178 ) ;
F_6 ( V_64 , V_5 ,
V_179 , V_180 ) ;
F_6 ( V_64 , V_5 ,
V_167 ,
1 << V_168 ) ;
F_28 ( 500 ) ;
F_6 ( V_64 , V_41 ,
V_173 , 0 ) ;
}
F_6 ( V_64 , V_5 ,
V_167 ,
2 << V_168 ) ;
break;
case V_170 :
F_6 ( V_64 , V_48 ,
V_177 , 0 ) ;
F_6 ( V_64 , V_48 ,
V_175 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_167 | V_179 ,
0 ) ;
F_7 ( V_64 , V_5 , 0 ) ;
F_7 ( V_64 , V_6 , 0 ) ;
F_7 ( V_64 , V_7 , 0 ) ;
F_29 ( V_117 -> V_172 ) ;
F_30 ( F_17 ( V_117 -> V_171 ) ,
V_117 -> V_171 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_63 * V_64 )
{
T_3 V_115 ;
struct V_116 * V_117 ;
int V_152 ;
V_117 = F_13 ( V_64 ) ;
for ( V_115 = 0 ; V_115 < F_17 ( V_117 -> V_171 ) ; V_115 ++ )
V_117 -> V_171 [ V_115 ] . V_181 = V_182 [ V_115 ] ;
V_152 = F_32 ( V_64 -> V_2 , F_17 ( V_117 -> V_171 ) ,
V_117 -> V_171 ) ;
if ( V_152 ) {
F_11 ( V_64 -> V_2 , L_16 , V_152 ) ;
return V_152 ;
}
V_152 = F_26 ( F_17 ( V_117 -> V_171 ) ,
V_117 -> V_171 ) ;
if ( V_152 ) {
F_11 ( V_64 -> V_2 , L_15 , V_152 ) ;
return V_152 ;
}
V_152 = F_8 ( V_64 ) ;
if ( V_152 < 0 ) {
F_11 ( V_64 -> V_2 , L_17 , V_152 ) ;
goto V_183;
}
for ( V_115 = 0 ; V_115 < F_17 ( V_184 ) ; ++ V_115 )
F_6 ( V_64 , V_184 [ V_115 ] ,
0x100 , 0x100 ) ;
F_6 ( V_64 , V_58 , V_185 ,
V_185 ) ;
return 0 ;
V_183:
F_30 ( F_17 ( V_117 -> V_171 ) , V_117 -> V_171 ) ;
return V_152 ;
}
static int F_33 ( struct V_186 * V_187 )
{
struct V_116 * V_117 ;
int V_152 ;
V_117 = F_34 ( & V_187 -> V_2 , sizeof *V_117 , V_188 ) ;
if ( ! V_117 )
return - V_189 ;
F_35 ( V_187 , V_117 ) ;
V_117 -> V_172 = F_36 ( V_187 , & V_190 ) ;
if ( F_37 ( V_117 -> V_172 ) ) {
V_152 = F_38 ( V_117 -> V_172 ) ;
F_11 ( & V_187 -> V_2 , L_18 ,
V_152 ) ;
return V_152 ;
}
V_152 = F_39 ( & V_187 -> V_2 ,
& V_191 , & V_192 , 1 ) ;
return V_152 ;
}
static int F_40 ( struct V_186 * V_187 )
{
F_41 ( & V_187 -> V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_193 * V_194 ,
const struct V_195 * V_196 )
{
struct V_116 * V_117 ;
int V_152 ;
V_117 = F_34 ( & V_194 -> V_2 , sizeof *V_117 , V_188 ) ;
if ( ! V_117 )
return - V_189 ;
F_43 ( V_194 , V_117 ) ;
V_117 -> V_172 = F_44 ( V_194 , & V_190 ) ;
if ( F_37 ( V_117 -> V_172 ) ) {
V_152 = F_38 ( V_117 -> V_172 ) ;
F_11 ( & V_194 -> V_2 , L_18 ,
V_152 ) ;
return V_152 ;
}
V_152 = F_39 ( & V_194 -> V_2 ,
& V_191 , & V_192 , 1 ) ;
return V_152 ;
}
static int F_45 ( struct V_193 * V_194 )
{
F_41 ( & V_194 -> V_2 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
int V_152 = 0 ;
#if F_47 ( V_197 )
V_152 = F_48 ( & V_198 ) ;
if ( V_152 ) {
F_20 ( V_144 L_19 ,
V_152 ) ;
}
#endif
#if F_49 ( V_199 )
V_152 = F_50 ( & V_200 ) ;
if ( V_152 != 0 ) {
F_20 ( V_144 L_20 ,
V_152 ) ;
}
#endif
return V_152 ;
}
static void T_5 F_51 ( void )
{
#if F_47 ( V_197 )
F_52 ( & V_198 ) ;
#endif
#if F_49 ( V_199 )
F_53 ( & V_200 ) ;
#endif
}
