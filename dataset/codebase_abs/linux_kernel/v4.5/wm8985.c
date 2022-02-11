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
V_62 -> V_66 . V_67 . V_68 [ 0 ] = 1 ;
else
V_62 -> V_66 . V_67 . V_68 [ 0 ] = 0 ;
return 0 ;
}
static int F_5 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_3 ( V_60 ) ;
unsigned int V_69 , V_70 ;
unsigned int V_71 ;
if ( V_62 -> V_66 . V_67 . V_68 [ 0 ] != 0
&& V_62 -> V_66 . V_67 . V_68 [ 0 ] != 1 )
return - V_72 ;
V_71 = F_4 ( V_64 , V_21 ) ;
switch ( ( V_71 & V_65 ) >> V_73 ) {
case 0 :
if ( ! V_62 -> V_66 . V_67 . V_68 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_62 -> V_66 . V_67 . V_68 [ 0 ] )
return 0 ;
break;
}
V_69 = F_4 ( V_64 , V_6 ) ;
V_70 = F_4 ( V_64 , V_7 ) ;
F_6 ( V_64 , V_6 ,
V_74 | V_75 , 0 ) ;
F_6 ( V_64 , V_7 ,
V_76 | V_77 , 0 ) ;
F_6 ( V_64 , V_11 ,
V_78 , V_79 ) ;
F_6 ( V_64 , V_21 ,
V_80 ,
V_62 -> V_66 . V_67 . V_68 [ 0 ]
<< V_73 ) ;
F_7 ( V_64 , V_6 , V_69 ) ;
F_7 ( V_64 , V_7 , V_70 ) ;
return 0 ;
}
static int F_8 ( struct V_63 * V_64 )
{
return F_7 ( V_64 , V_4 , 0x0 ) ;
}
static int F_9 ( struct V_81 * V_82 , int V_83 )
{
struct V_63 * V_64 = V_82 -> V_64 ;
return F_6 ( V_64 , V_14 ,
V_84 ,
! ! V_83 << V_85 ) ;
}
static int F_10 ( struct V_81 * V_82 , unsigned int V_86 )
{
struct V_63 * V_64 ;
T_1 V_87 , V_88 , V_89 , V_90 ;
V_64 = V_82 -> V_64 ;
switch ( V_86 & V_91 ) {
case V_92 :
V_87 = 0x2 ;
break;
case V_93 :
V_87 = 0x0 ;
break;
case V_94 :
V_87 = 0x1 ;
break;
case V_95 :
case V_96 :
V_87 = 0x3 ;
break;
default:
F_11 ( V_82 -> V_2 , L_1 ) ;
return - V_72 ;
}
F_6 ( V_64 , V_8 ,
V_97 , V_87 << V_98 ) ;
switch ( V_86 & V_99 ) {
case V_100 :
V_88 = 1 ;
break;
case V_101 :
V_88 = 0 ;
break;
default:
F_11 ( V_82 -> V_2 , L_2 ) ;
return - V_72 ;
}
F_6 ( V_64 , V_10 ,
V_102 , V_88 << V_103 ) ;
switch ( V_86 & V_91 ) {
case V_95 :
case V_96 :
switch ( V_86 & V_104 ) {
case V_105 :
case V_106 :
return - V_72 ;
default:
break;
}
break;
default:
break;
}
V_89 = V_90 = 0 ;
switch ( V_86 & V_104 ) {
case V_107 :
break;
case V_105 :
V_89 = V_90 = 1 ;
break;
case V_108 :
V_89 = 1 ;
break;
case V_106 :
V_90 = 1 ;
break;
default:
F_11 ( V_82 -> V_2 , L_3 ) ;
return - V_72 ;
}
F_6 ( V_64 , V_8 ,
V_109 , V_90 << V_110 ) ;
F_6 ( V_64 , V_8 ,
V_111 , V_89 << V_112 ) ;
return 0 ;
}
static int F_12 ( struct V_113 * V_114 ,
struct V_115 * V_116 ,
struct V_81 * V_82 )
{
int V_117 ;
struct V_63 * V_64 ;
struct V_118 * V_119 ;
T_1 V_120 , V_121 ;
unsigned int V_122 ;
int V_123 ;
V_64 = V_82 -> V_64 ;
V_119 = F_13 ( V_64 ) ;
V_119 -> V_124 = F_14 ( V_116 ) ;
if ( ( int ) V_119 -> V_124 < 0 )
return V_119 -> V_124 ;
switch ( F_15 ( V_116 ) ) {
case 16 :
V_120 = 0x0 ;
break;
case 20 :
V_120 = 0x1 ;
break;
case 24 :
V_120 = 0x2 ;
break;
case 32 :
V_120 = 0x3 ;
break;
default:
F_11 ( V_82 -> V_2 , L_4 ,
F_15 ( V_116 ) ) ;
return - V_72 ;
}
F_6 ( V_64 , V_8 ,
V_125 , V_120 << V_126 ) ;
V_121 = 0 ;
V_123 = abs ( V_127 [ 0 ] - F_16 ( V_116 ) ) ;
for ( V_117 = 1 ; V_117 < F_17 ( V_127 ) ; ++ V_117 ) {
if ( abs ( V_127 [ V_117 ] - F_16 ( V_116 ) ) >= V_123 )
continue;
V_121 = V_117 ;
V_123 = abs ( V_127 [ V_117 ] - F_16 ( V_116 ) ) ;
}
F_18 ( V_82 -> V_2 , L_5 , V_127 [ V_121 ] ) ;
F_6 ( V_64 , V_11 ,
V_128 , V_121 << V_129 ) ;
F_18 ( V_82 -> V_2 , L_6 , V_119 -> V_124 ) ;
F_18 ( V_82 -> V_2 , L_7 , V_119 -> V_130 ) ;
for ( V_117 = 0 ; V_117 < F_17 ( V_131 ) ; ++ V_117 ) {
if ( V_119 -> V_130 / F_16 ( V_116 )
== V_131 [ V_117 ] . V_132 )
break;
}
if ( V_117 == F_17 ( V_131 ) ) {
F_11 ( V_82 -> V_2 , L_8 ,
V_119 -> V_130 , F_16 ( V_116 ) ) ;
return - V_72 ;
}
F_18 ( V_82 -> V_2 , L_9 , V_131 [ V_117 ] . V_132 ) ;
F_6 ( V_64 , V_10 ,
V_133 , V_117 << V_134 ) ;
V_122 = ( V_119 -> V_130 / V_131 [ V_117 ] . div ) * 10 ;
for ( V_117 = 0 ; V_117 < F_17 ( V_135 ) ; ++ V_117 ) {
if ( V_119 -> V_124 == V_122 / V_135 [ V_117 ] )
break;
}
if ( V_117 == F_17 ( V_135 ) ) {
F_11 ( V_82 -> V_2 , L_10 ) ;
return - V_72 ;
}
F_18 ( V_82 -> V_2 , L_11 , V_117 ) ;
F_6 ( V_64 , V_10 ,
V_136 , V_117 << V_137 ) ;
return 0 ;
}
static int F_19 ( struct V_138 * V_138 , unsigned int V_139 ,
unsigned int V_140 )
{
T_2 V_141 ;
unsigned long int V_142 , V_143 , V_144 ;
V_138 -> V_145 = 0 ;
V_143 = V_139 / V_140 ;
if ( V_143 < 6 ) {
V_140 >>= 1 ;
V_138 -> V_145 = 1 ;
V_143 = V_139 / V_140 ;
}
if ( V_143 < 6 || V_143 > 12 ) {
F_20 ( V_146 L_12
L_13 , V_147 , V_143 ) ;
return - V_72 ;
}
V_138 -> V_148 = V_143 ;
V_144 = V_139 % V_140 ;
V_141 = V_149 * ( T_2 ) V_144 ;
F_21 ( V_141 , V_140 ) ;
V_142 = V_141 & 0xffffffff ;
if ( ( V_142 % 10 ) >= 5 )
V_142 += 5 ;
V_142 /= 10 ;
V_138 -> V_150 = V_142 ;
return 0 ;
}
static int F_22 ( struct V_81 * V_82 , int V_151 ,
int V_140 , unsigned int V_152 ,
unsigned int V_153 )
{
int V_154 ;
struct V_63 * V_64 ;
struct V_138 V_138 ;
V_64 = V_82 -> V_64 ;
if ( ! V_152 || ! V_153 ) {
F_6 ( V_64 , V_5 ,
V_155 , 0 ) ;
} else {
V_154 = F_19 ( & V_138 , V_153 * 4 * 2 , V_152 ) ;
if ( V_154 )
return V_154 ;
F_7 ( V_64 , V_36 ,
( V_138 . V_145 << V_156 )
| V_138 . V_148 ) ;
F_7 ( V_64 , V_39 , V_138 . V_150 & 0x1ff ) ;
F_7 ( V_64 , V_38 , ( V_138 . V_150 >> 9 ) & 0x1ff ) ;
F_7 ( V_64 , V_37 , ( V_138 . V_150 >> 18 ) ) ;
F_6 ( V_64 , V_10 ,
V_157 , V_158 ) ;
F_6 ( V_64 , V_5 ,
V_155 , V_159 ) ;
}
return 0 ;
}
static int F_23 ( struct V_81 * V_82 ,
int V_160 , unsigned int V_161 , int V_162 )
{
struct V_63 * V_64 ;
struct V_118 * V_119 ;
V_64 = V_82 -> V_64 ;
V_119 = F_13 ( V_64 ) ;
switch ( V_160 ) {
case V_163 :
F_6 ( V_64 , V_10 ,
V_157 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_155 , 0 ) ;
break;
case V_164 :
F_6 ( V_64 , V_10 ,
V_157 , V_158 ) ;
break;
default:
F_11 ( V_82 -> V_2 , L_14 , V_160 ) ;
return - V_72 ;
}
V_119 -> V_130 = V_161 ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 ,
enum V_165 V_166 )
{
int V_154 ;
struct V_118 * V_119 ;
V_119 = F_13 ( V_64 ) ;
switch ( V_166 ) {
case V_167 :
case V_168 :
F_6 ( V_64 , V_5 ,
V_169 ,
1 << V_170 ) ;
break;
case V_171 :
if ( F_25 ( V_64 ) == V_172 ) {
V_154 = F_26 ( F_17 ( V_119 -> V_173 ) ,
V_119 -> V_173 ) ;
if ( V_154 ) {
F_11 ( V_64 -> V_2 ,
L_15 ,
V_154 ) ;
return V_154 ;
}
F_27 ( V_119 -> V_174 ) ;
F_6 ( V_64 , V_41 ,
V_175 ,
V_176 ) ;
F_6 ( V_64 , V_48 ,
V_177 , V_178 ) ;
F_6 ( V_64 , V_48 ,
V_179 ,
V_180 ) ;
F_6 ( V_64 , V_5 ,
V_181 , V_182 ) ;
F_6 ( V_64 , V_5 ,
V_169 ,
1 << V_170 ) ;
F_28 ( 500 ) ;
F_6 ( V_64 , V_41 ,
V_175 , 0 ) ;
}
F_6 ( V_64 , V_5 ,
V_169 ,
2 << V_170 ) ;
break;
case V_172 :
F_6 ( V_64 , V_48 ,
V_179 , 0 ) ;
F_6 ( V_64 , V_48 ,
V_177 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_169 | V_181 ,
0 ) ;
F_7 ( V_64 , V_5 , 0 ) ;
F_7 ( V_64 , V_6 , 0 ) ;
F_7 ( V_64 , V_7 , 0 ) ;
F_29 ( V_119 -> V_174 ) ;
F_30 ( F_17 ( V_119 -> V_173 ) ,
V_119 -> V_173 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_63 * V_64 )
{
T_3 V_117 ;
struct V_118 * V_119 ;
int V_154 ;
V_119 = F_13 ( V_64 ) ;
for ( V_117 = 0 ; V_117 < F_17 ( V_119 -> V_173 ) ; V_117 ++ )
V_119 -> V_173 [ V_117 ] . V_183 = V_184 [ V_117 ] ;
V_154 = F_32 ( V_64 -> V_2 , F_17 ( V_119 -> V_173 ) ,
V_119 -> V_173 ) ;
if ( V_154 ) {
F_11 ( V_64 -> V_2 , L_16 , V_154 ) ;
return V_154 ;
}
V_154 = F_26 ( F_17 ( V_119 -> V_173 ) ,
V_119 -> V_173 ) ;
if ( V_154 ) {
F_11 ( V_64 -> V_2 , L_15 , V_154 ) ;
return V_154 ;
}
V_154 = F_8 ( V_64 ) ;
if ( V_154 < 0 ) {
F_11 ( V_64 -> V_2 , L_17 , V_154 ) ;
goto V_185;
}
for ( V_117 = 0 ; V_117 < F_17 ( V_186 ) ; ++ V_117 )
F_6 ( V_64 , V_186 [ V_117 ] ,
0x100 , 0x100 ) ;
F_6 ( V_64 , V_58 , V_187 ,
V_187 ) ;
return 0 ;
V_185:
F_30 ( F_17 ( V_119 -> V_173 ) , V_119 -> V_173 ) ;
return V_154 ;
}
static int F_33 ( struct V_188 * V_189 )
{
struct V_118 * V_119 ;
int V_154 ;
V_119 = F_34 ( & V_189 -> V_2 , sizeof *V_119 , V_190 ) ;
if ( ! V_119 )
return - V_191 ;
F_35 ( V_189 , V_119 ) ;
V_119 -> V_174 = F_36 ( V_189 , & V_192 ) ;
if ( F_37 ( V_119 -> V_174 ) ) {
V_154 = F_38 ( V_119 -> V_174 ) ;
F_11 ( & V_189 -> V_2 , L_18 ,
V_154 ) ;
return V_154 ;
}
V_154 = F_39 ( & V_189 -> V_2 ,
& V_193 , & V_194 , 1 ) ;
return V_154 ;
}
static int F_40 ( struct V_188 * V_189 )
{
F_41 ( & V_189 -> V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_195 * V_196 ,
const struct V_197 * V_198 )
{
struct V_118 * V_119 ;
int V_154 ;
V_119 = F_34 ( & V_196 -> V_2 , sizeof *V_119 , V_190 ) ;
if ( ! V_119 )
return - V_191 ;
F_43 ( V_196 , V_119 ) ;
V_119 -> V_174 = F_44 ( V_196 , & V_192 ) ;
if ( F_37 ( V_119 -> V_174 ) ) {
V_154 = F_38 ( V_119 -> V_174 ) ;
F_11 ( & V_196 -> V_2 , L_18 ,
V_154 ) ;
return V_154 ;
}
V_154 = F_39 ( & V_196 -> V_2 ,
& V_193 , & V_194 , 1 ) ;
return V_154 ;
}
static int F_45 ( struct V_195 * V_196 )
{
F_41 ( & V_196 -> V_2 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
int V_154 = 0 ;
#if F_47 ( V_199 )
V_154 = F_48 ( & V_200 ) ;
if ( V_154 ) {
F_20 ( V_146 L_19 ,
V_154 ) ;
}
#endif
#if F_49 ( V_201 )
V_154 = F_50 ( & V_202 ) ;
if ( V_154 != 0 ) {
F_20 ( V_146 L_20 ,
V_154 ) ;
}
#endif
return V_154 ;
}
static void T_5 F_51 ( void )
{
#if F_47 ( V_199 )
F_52 ( & V_200 ) ;
#endif
#if F_49 ( V_201 )
F_53 ( & V_202 ) ;
#endif
}
