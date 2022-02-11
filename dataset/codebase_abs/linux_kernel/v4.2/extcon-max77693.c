static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_11 ,
time << V_12 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_15 , bool V_16 )
{
int V_4 = 0 ;
unsigned int V_17 , V_18 = 0 ;
if ( V_16 )
V_17 = V_15 ;
else
V_17 = V_19 ;
V_4 = F_5 ( V_2 -> V_9 -> V_10 ,
V_20 , V_21 , V_17 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
if ( V_16 )
V_18 |= V_22 ;
else
V_18 |= V_23 ;
V_4 = F_5 ( V_2 -> V_9 -> V_10 ,
V_24 ,
V_23 | V_22 , V_18 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
F_6 ( V_2 -> V_13 ,
L_4 ,
V_17 , V_18 , V_16 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_25 V_26 , bool * V_16 )
{
int V_27 = 0 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
switch ( V_26 ) {
case V_33 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
if ( V_28 == V_37 ) {
* V_16 = false ;
V_27 = V_2 -> V_38 ;
V_2 -> V_38 = V_37 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_38 = V_28 ;
}
break;
case V_39 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
if ( V_28 == V_37 ) {
* V_16 = false ;
V_27 = V_2 -> V_40 ;
V_2 -> V_40 = V_37 ;
} else {
* V_16 = true ;
V_30 = V_2 -> V_34 [ 0 ] & V_41 ;
V_30 >>= V_42 ;
V_29 = V_2 -> V_34 [ 0 ] & V_43 ;
V_29 >>= V_44 ;
V_31 = V_2 -> V_34 [ 1 ] & V_45 ;
V_31 >>= V_46 ;
V_27 = ( ( 0x1 << 8 )
| ( V_31 << 2 )
| ( V_30 << 1 )
| V_29 ) ;
V_2 -> V_38 = V_28 ;
V_2 -> V_40 = V_27 ;
}
break;
case V_47 :
V_32 = V_2 -> V_34 [ 1 ] & V_48 ;
V_32 >>= V_49 ;
if ( V_32 == V_50 ) {
* V_16 = false ;
V_27 = V_2 -> V_51 ;
V_2 -> V_51 = V_50 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_51 = V_32 ;
}
break;
case V_52 :
V_28 = V_2 -> V_34 [ 0 ] & V_35 ;
V_28 >>= V_36 ;
V_32 = V_2 -> V_34 [ 1 ] & V_48 ;
V_32 >>= V_49 ;
if ( V_28 == V_37
&& V_32 == V_50 )
* V_16 = false ;
else
* V_16 = true ;
V_31 = V_2 -> V_34 [ 1 ] & V_45 ;
V_31 >>= V_46 ;
V_27 = V_31 ;
break;
default:
F_3 ( V_2 -> V_13 , L_7 , V_26 ) ;
V_27 = - V_14 ;
break;
}
return V_27 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
int V_4 = 0 ;
int V_31 ;
bool V_53 ;
unsigned int V_54 ;
F_6 ( V_2 -> V_13 ,
L_8 ,
V_16 ? L_5 : L_6 , V_27 ) ;
switch ( V_27 ) {
case V_55 :
V_31 = F_7 ( V_2 ,
V_52 , & V_53 ) ;
if ( V_16 && ! V_31 ) {
F_9 ( V_2 -> V_13 ,
L_9 ) ;
return 0 ;
}
V_4 = F_4 ( V_2 , V_2 -> V_56 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_58 , V_16 ) ;
F_10 ( V_2 -> V_57 , V_59 , V_16 ) ;
goto V_60;
case V_61 :
V_54 = V_58 ;
break;
case V_62 :
V_54 = V_58 ;
if ( ! V_16 )
F_10 ( V_2 -> V_57 , V_63 , false ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_10 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
V_4 = F_4 ( V_2 , V_64 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_54 , V_16 ) ;
V_60:
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_65 , bool V_16 )
{
struct V_66 * V_67 = V_2 -> V_67 ;
unsigned int V_68 ;
switch ( V_65 ) {
case V_69 - 1
... V_69 + 1 :
V_68 = V_70 ;
break;
case V_71 - 1
... V_71 + 1 :
V_68 = V_72 ;
break;
case V_73 :
V_68 = V_74 ;
break;
case V_75 :
V_68 = V_76 ;
break;
case V_77 - 1
... V_77 + 1 :
V_68 = V_78 ;
break;
default:
F_3 ( V_2 -> V_13 ,
L_11 ,
V_16 ? L_12 : L_13 , V_65 ) ;
return - V_14 ;
}
F_12 ( V_67 , V_79 , V_68 , V_16 ) ;
F_13 ( V_67 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_80 ;
int V_4 = 0 ;
bool V_16 ;
V_80 = F_7 ( V_2 ,
V_39 , & V_16 ) ;
switch ( V_80 ) {
case V_81 :
case V_82 :
V_4 = F_4 ( V_2 , V_83 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_84 , V_16 ) ;
break;
case V_85 :
V_4 = F_4 ( V_2 , V_64 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_63 , V_16 ) ;
break;
case V_86 :
case V_87 :
F_10 ( V_2 -> V_57 , V_59 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_14 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
int V_4 = 0 ;
T_1 V_88 = V_19 ;
F_6 ( V_2 -> V_13 ,
L_8 ,
V_16 ? L_5 : L_6 , V_27 ) ;
switch ( V_27 ) {
case V_89 :
case V_90 :
V_88 = V_83 ;
break;
case V_91 :
case V_92 :
V_88 = V_93 ;
break;
default:
F_3 ( V_2 -> V_13 , L_15 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
V_4 = F_4 ( V_2 , V_88 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_94 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_27 ;
int V_65 ;
bool V_16 ;
int V_4 = 0 ;
V_27 = F_7 ( V_2 ,
V_33 , & V_16 ) ;
F_6 ( V_2 -> V_13 ,
L_16 ,
V_16 ? L_5 : L_6 , V_27 ,
V_2 -> V_38 ) ;
switch ( V_27 ) {
case V_95 :
F_14 ( V_2 ) ;
break;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_4 = F_15 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_55 :
case V_61 :
case V_62 :
V_4 = F_8 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_69 :
case V_71 :
case V_73 :
case V_75 :
case V_77 :
if ( V_16 )
V_65 = V_2 -> V_96 = V_27 ;
else
V_65 = V_2 -> V_96 ;
V_4 = F_11 ( V_2 , V_65 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_6 ( V_2 -> V_13 ,
L_17 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_115 ;
default:
F_3 ( V_2 -> V_13 ,
L_18 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_32 ;
int V_80 ;
int V_27 ;
bool V_16 ;
bool V_53 ;
int V_4 = 0 ;
V_32 = F_7 ( V_2 ,
V_47 , & V_16 ) ;
F_6 ( V_2 -> V_13 ,
L_19 ,
V_16 ? L_5 : L_6 ,
V_32 , V_2 -> V_51 ) ;
switch ( V_32 ) {
case V_116 :
case V_117 :
case V_50 :
V_80 = F_7 ( V_2 ,
V_39 ,
& V_53 ) ;
switch ( V_80 ) {
case V_86 :
case V_87 :
F_10 ( V_2 -> V_57 , V_118 , V_16 ) ;
if ( ! V_53 )
F_10 ( V_2 -> V_57 , V_59 ,
V_53 ) ;
break;
}
V_27 = F_7 ( V_2 ,
V_33 ,
& V_53 ) ;
switch ( V_27 ) {
case V_62 :
F_10 ( V_2 -> V_57 , V_63 ,
V_16 ) ;
if ( ! V_53 )
F_10 ( V_2 -> V_57 , V_58 ,
V_53 ) ;
break;
case V_55 :
V_4 = F_4 ( V_2 , V_2 -> V_56 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_58 ,
V_16 ) ;
F_10 ( V_2 -> V_57 , V_59 ,
V_16 ) ;
break;
}
switch ( V_32 ) {
case V_50 :
break;
case V_116 :
V_4 = F_4 ( V_2 , V_2 -> V_56 ,
V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( V_2 -> V_57 , V_63 ,
V_16 ) ;
break;
case V_117 :
F_10 ( V_2 -> V_57 , V_118 , V_16 ) ;
break;
}
break;
case V_119 :
F_10 ( V_2 -> V_57 , V_120 ,
V_16 ) ;
break;
case V_121 :
F_10 ( V_2 -> V_57 , V_122 ,
V_16 ) ;
break;
case V_123 :
F_10 ( V_2 -> V_57 , V_124 ,
V_16 ) ;
break;
case V_125 :
break;
default:
F_3 ( V_2 -> V_13 ,
L_20 ,
V_16 ? L_5 : L_6 , V_32 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_18 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_19 ( V_127 ,
struct V_1 , V_128 ) ;
int V_129 = - 1 ;
int V_130 , V_4 = 0 ;
if ( ! V_2 -> V_57 )
return;
F_20 ( & V_2 -> V_131 ) ;
for ( V_130 = 0 ; V_130 < F_21 ( V_132 ) ; V_130 ++ )
if ( V_2 -> V_133 == V_132 [ V_130 ] . V_134 )
V_129 = V_132 [ V_130 ] . V_133 ;
V_4 = F_22 ( V_2 -> V_9 -> V_10 ,
V_135 , V_2 -> V_34 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_21 ) ;
F_23 ( & V_2 -> V_131 ) ;
return;
}
switch ( V_129 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_4 = F_16 ( V_2 ) ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_4 = F_17 ( V_2 ) ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
break;
default:
F_3 ( V_2 -> V_13 , L_22 ,
V_129 ) ;
F_23 ( & V_2 -> V_131 ) ;
return;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_23 ) ;
F_23 ( & V_2 -> V_131 ) ;
}
static T_2 F_24 ( int V_133 , void * V_152 )
{
struct V_1 * V_2 = V_152 ;
V_2 -> V_133 = V_133 ;
F_25 ( & V_2 -> V_128 ) ;
return V_153 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_28 ;
int V_32 ;
bool V_16 ;
F_20 ( & V_2 -> V_131 ) ;
V_4 = F_22 ( V_2 -> V_9 -> V_10 ,
V_135 , V_2 -> V_34 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_21 ) ;
F_23 ( & V_2 -> V_131 ) ;
return V_4 ;
}
V_28 = F_7 ( V_2 , V_33 ,
& V_16 ) ;
if ( V_16 && V_28 != V_37 ) {
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_24 ) ;
F_23 ( & V_2 -> V_131 ) ;
return V_4 ;
}
}
V_32 = F_7 ( V_2 , V_47 ,
& V_16 ) ;
if ( V_16 && V_32 != V_50 ) {
V_4 = F_17 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_25 ) ;
F_23 ( & V_2 -> V_131 ) ;
return V_4 ;
}
}
F_23 ( & V_2 -> V_131 ) ;
return 0 ;
}
static void F_27 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_19 ( F_28 ( V_127 ) ,
struct V_1 , V_154 ) ;
F_26 ( V_2 ) ;
}
static int F_29 ( struct V_155 * V_156 )
{
struct V_157 * V_9 = F_30 ( V_156 -> V_13 . V_158 ) ;
struct V_159 * V_160 = F_31 ( V_9 -> V_13 ) ;
struct V_1 * V_2 ;
struct V_161 * V_162 ;
int V_163 ;
int V_164 ;
int V_4 ;
int V_130 ;
unsigned int V_165 ;
V_2 = F_32 ( & V_156 -> V_13 , sizeof( struct V_1 ) ,
V_166 ) ;
if ( ! V_2 )
return - V_167 ;
V_2 -> V_13 = & V_156 -> V_13 ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_9 -> V_10 ) {
F_33 ( & V_156 -> V_13 , L_26 ) ;
} else {
V_2 -> V_9 -> V_10 = F_34 (
V_2 -> V_9 -> V_168 ,
& V_169 ) ;
if ( F_35 ( V_2 -> V_9 -> V_10 ) ) {
V_4 = F_36 ( V_2 -> V_9 -> V_10 ) ;
F_3 ( V_9 -> V_13 ,
L_27 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_67 = F_37 ( & V_156 -> V_13 ) ;
if ( ! V_2 -> V_67 ) {
F_3 ( & V_156 -> V_13 , L_28 , V_170 ) ;
return - V_167 ;
}
V_2 -> V_67 -> V_171 = L_29 ;
V_2 -> V_67 -> V_172 = L_30 ;
V_2 -> V_67 -> V_13 . V_158 = & V_156 -> V_13 ;
F_38 ( V_173 , V_2 -> V_67 -> V_174 ) ;
F_39 ( V_2 -> V_67 , V_79 , V_76 ) ;
F_39 ( V_2 -> V_67 , V_79 , V_74 ) ;
F_39 ( V_2 -> V_67 , V_79 , V_78 ) ;
F_39 ( V_2 -> V_67 , V_79 , V_70 ) ;
F_39 ( V_2 -> V_67 , V_79 , V_72 ) ;
V_4 = F_40 ( V_2 -> V_67 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_156 -> V_13 , L_31 ,
V_4 ) ;
return V_4 ;
}
F_41 ( V_156 , V_2 ) ;
F_42 ( & V_2 -> V_131 ) ;
F_43 ( & V_2 -> V_128 , F_18 ) ;
for ( V_130 = 0 ; V_130 < F_21 ( V_132 ) ; V_130 ++ ) {
struct V_175 * V_176 = & V_132 [ V_130 ] ;
unsigned int V_134 = 0 ;
V_134 = F_44 ( V_9 -> V_177 ,
V_176 -> V_133 ) ;
if ( ! V_134 )
return - V_14 ;
V_176 -> V_134 = V_134 ;
V_4 = F_45 ( & V_156 -> V_13 , V_134 , NULL ,
F_24 ,
V_178 ,
V_176 -> V_171 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_156 -> V_13 ,
L_32 ,
V_176 -> V_133 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_57 = F_46 ( & V_156 -> V_13 ,
V_179 ) ;
if ( F_35 ( V_2 -> V_57 ) ) {
F_3 ( & V_156 -> V_13 , L_33 ) ;
return - V_167 ;
}
V_4 = F_47 ( & V_156 -> V_13 , V_2 -> V_57 ) ;
if ( V_4 ) {
F_3 ( & V_156 -> V_13 , L_34 ) ;
return V_4 ;
}
if ( V_160 && V_160 -> V_180 ) {
V_162 = V_160 -> V_180 -> V_162 ;
V_163 = V_160 -> V_180 -> V_163 ;
} else {
V_162 = V_181 ;
V_163 = F_21 ( V_181 ) ;
}
for ( V_130 = 0 ; V_130 < V_163 ; V_130 ++ ) {
enum V_182 V_183
= V_184 ;
F_2 ( V_2 -> V_9 -> V_10 ,
V_162 [ V_130 ] . V_185 ,
V_162 [ V_130 ] . V_152 ) ;
switch ( V_162 [ V_130 ] . V_185 ) {
case V_186 :
V_183 = V_187 ;
break;
case V_188 :
V_183 = V_189 ;
break;
case V_190 :
V_183 = V_191 ;
break;
}
if ( V_183 < V_184 )
V_2 -> V_9 -> V_192 [ V_183 ]
= V_162 [ V_130 ] . V_152 ;
}
if ( V_160 && V_160 -> V_180 ) {
struct V_193 * V_194
= V_160 -> V_180 ;
if ( V_194 -> V_195 )
V_2 -> V_195 = V_194 -> V_195 ;
else
V_2 -> V_195 = V_93 ;
if ( V_194 -> V_56 )
V_2 -> V_56 = V_194 -> V_56 ;
else
V_2 -> V_56 = V_83 ;
if ( V_194 -> V_196 )
V_164 =
F_48 ( V_194 -> V_196 ) ;
else
V_164 = F_48 ( V_197 ) ;
} else {
V_2 -> V_56 = V_83 ;
V_2 -> V_195 = V_93 ;
V_164 = F_48 ( V_197 ) ;
}
F_4 ( V_2 , V_2 -> V_195 , true ) ;
V_4 = F_49 ( V_2 -> V_9 -> V_10 ,
V_198 , & V_165 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_156 -> V_13 , L_35 ) ;
return V_4 ;
}
F_6 ( V_2 -> V_13 , L_36 , V_165 ) ;
F_1 ( V_2 , V_7 ) ;
F_50 ( & V_2 -> V_154 , F_27 ) ;
F_51 ( V_199 , & V_2 -> V_154 ,
V_164 ) ;
return V_4 ;
}
static int F_52 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = F_53 ( V_156 ) ;
F_54 ( & V_2 -> V_128 ) ;
F_55 ( V_2 -> V_67 ) ;
return 0 ;
}
