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
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
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
case V_13 :
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
case V_14 :
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
case V_73 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_15 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_74 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = F_5 ( V_75 -> V_81 ) ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
int V_84 ;
switch ( V_78 ) {
case V_85 :
if ( V_83 -> V_86 )
F_7 ( V_83 -> V_87 , V_18 ,
V_88 , 0x00 ) ;
V_84 = F_7 ( V_83 -> V_87 , V_16 ,
V_89 , 0 ) ;
if ( V_84 < 0 ) {
F_8 ( V_80 -> V_2 , L_1 , V_84 ) ;
return V_84 ;
}
F_9 ( 5000 , 5100 ) ;
break;
case V_90 :
if ( V_83 -> V_86 ) {
F_7 ( V_83 -> V_87 , V_18 ,
V_88 , V_88 ) ;
}
V_84 = F_7 ( V_83 -> V_87 , V_16 ,
V_89 , V_89 ) ;
break;
default:
F_10 ( L_2 , V_78 ) ;
}
return 0 ;
}
static int F_11 ( struct V_91 * V_92 , unsigned int V_93 ,
unsigned int V_94 , int V_95 , int V_96 )
{
struct V_79 * V_80 = V_92 -> V_80 ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
unsigned int V_3 , V_97 ;
int V_98 , V_99 ;
if ( V_96 != 8 )
return - V_100 ;
V_83 -> V_86 = true ;
V_98 = F_12 ( V_94 ) - 1 ;
if ( V_98 >= 0 )
F_13 ( V_80 , V_62 ,
V_101 , V_98 ) ;
V_98 = F_12 ( V_93 ) - 1 ;
V_99 = 0 ;
F_13 ( V_80 , V_54 ,
V_102 | V_101 ,
V_102 | V_101 ) ;
F_13 ( V_80 , V_55 ,
V_102 | V_101 ,
V_102 | V_101 ) ;
while ( V_98 >= 0 ) {
if ( V_99 == 0 )
F_13 ( V_80 , V_52 ,
V_102 | V_101 , V_98 ) ;
if ( V_99 == 4 ) {
F_13 ( V_80 , V_53 ,
V_102 | V_101 , V_98 ) ;
}
if ( V_99 == 3 ) {
F_13 ( V_80 , V_54 ,
V_102 | V_101 , V_98 ) ;
}
if ( V_99 == 7 ) {
F_13 ( V_80 ,
V_55 ,
V_102 | V_101 , V_98 ) ;
}
V_3 = V_61 - ( V_98 / 8 ) ;
V_97 = V_98 - ( ( V_98 / 8 ) * ( 8 ) ) ;
F_13 ( V_80 , V_3 ,
1 << V_97 , 1 << V_97 ) ;
V_93 &= ~ ( 1 << V_98 ) ;
V_98 = F_12 ( V_93 ) - 1 ;
V_99 ++ ;
}
return 0 ;
}
static int F_14 ( struct V_74 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = F_5 ( V_75 -> V_81 ) ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
switch ( V_78 ) {
case V_103 :
F_7 ( V_83 -> V_87 , V_27 ,
V_104 , V_83 -> V_105 . V_106 ) ;
F_9 ( 5000 , 5100 ) ;
F_7 ( V_83 -> V_87 , V_25 ,
V_107 , 0 ) ;
break;
case V_90 :
F_7 ( V_83 -> V_87 , V_27 ,
V_104 , 0 ) ;
F_7 ( V_83 -> V_87 , V_25 ,
V_107 , V_107 ) ;
F_9 ( 5000 , 5100 ) ;
break;
default:
F_10 ( L_2 , V_78 ) ;
}
return 0 ;
}
static int F_15 ( struct V_74 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
struct V_79 * V_80 = F_5 ( V_75 -> V_81 ) ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
int V_84 , V_108 ;
unsigned int V_3 ;
switch ( V_78 ) {
case V_109 :
V_84 = F_16 ( V_83 -> V_87 , V_22 ,
& V_3 ) ;
if ( V_84 != 0 ) {
F_10 ( L_3 , V_110 , V_84 ) ;
return V_84 ;
}
if ( V_3 & V_111 )
F_17 ( 40 ) ;
else
F_9 ( 2000 , 2100 ) ;
for ( V_108 = 0 ; V_108 < V_112 ; V_108 ++ ) {
V_84 = F_16 ( V_83 -> V_87 , V_10 ,
& V_3 ) ;
if ( V_84 != 0 ) {
F_10 ( L_3 ,
V_110 , V_84 ) ;
return V_84 ;
}
if ( V_3 & V_113 )
break;
F_9 ( 5000 , 5100 ) ;
}
if ( V_108 == V_112 )
F_10 ( L_4 ,
V_110 ) ;
break;
default:
F_10 ( L_2 , V_78 ) ;
break;
}
return 0 ;
}
static int F_18 ( int V_114 , int V_115 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < F_19 ( V_116 ) ; V_108 ++ ) {
if ( V_116 [ V_108 ] . V_114 == V_114 &&
V_116 [ V_108 ] . V_115 == V_115 )
return V_108 ;
}
return - V_100 ;
}
static int F_20 ( struct V_91 * V_117 , unsigned int V_118 )
{
struct V_79 * V_80 = V_117 -> V_80 ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
switch ( V_118 & V_119 ) {
case V_120 :
F_7 ( V_83 -> V_87 , V_19 ,
0x80 , 0x80 ) ;
break;
case V_121 :
F_7 ( V_83 -> V_87 , V_19 ,
0x80 , 0x00 ) ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_21 ( struct V_122 * V_123 ,
struct V_124 * V_125 ,
struct V_91 * V_92 )
{
struct V_79 * V_80 = V_92 -> V_80 ;
struct V_82 * V_83 = F_6 ( V_80 ) ;
int V_115 = F_22 ( V_125 ) ;
int V_84 ;
int V_126 = F_18 ( V_83 -> V_127 , V_115 ) ;
if ( V_126 < 0 ) {
F_8 ( V_80 -> V_2 , L_5 ,
V_83 -> V_127 , V_115 ) ;
return V_126 ;
}
V_84 = F_7 ( V_83 -> V_87 , V_19 ,
V_128 , V_116 [ V_126 ] . V_129 ) ;
if ( V_84 != 0 )
F_8 ( V_80 -> V_2 , L_6 , V_84 ) ;
return V_84 ;
}
static int F_23 ( struct V_122 * V_123 ,
struct V_91 * V_92 )
{
F_24 ( V_123 -> V_130 , 0 ,
V_131 , & V_132 ) ;
return 0 ;
}
static int F_25 ( struct V_91 * V_92 , int V_133 )
{
struct V_79 * V_80 = V_92 -> V_80 ;
if ( V_133 )
F_13 ( V_80 , V_18 ,
V_134 , V_134 ) ;
else
F_13 ( V_80 , V_18 ,
V_134 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_91 * V_92 ,
int V_135 , unsigned int V_136 , int V_137 )
{
struct V_79 * V_80 = V_92 -> V_80 ;
struct V_82 * V_138 = F_6 ( V_80 ) ;
unsigned int V_139 ;
switch ( V_136 ) {
case V_140 :
V_139 = V_141 ;
V_138 -> V_127 = V_136 ;
break;
case V_142 :
V_139 = V_143 ;
V_138 -> V_127 = V_136 ;
break;
case V_144 :
V_139 = V_145 ;
V_138 -> V_127 = V_136 ;
break;
case V_146 :
V_139 = V_147 | V_141 ;
V_138 -> V_127 = V_136 / 2 ;
break;
case V_148 :
V_139 = V_147 | V_143 ;
V_138 -> V_127 = V_136 / 2 ;
break;
case V_149 :
V_139 = V_147 | V_145 ;
V_138 -> V_127 = V_136 / 2 ;
break;
default:
F_8 ( V_80 -> V_2 , L_7 , V_136 ) ;
V_138 -> V_127 = 0 ;
return - V_100 ;
}
F_7 ( V_138 -> V_87 , V_20 ,
V_147 | V_150 , V_139 ) ;
return 0 ;
}
static int F_27 ( struct V_82 * V_138 ,
unsigned int V_151 )
{
struct V_79 * V_80 = V_138 -> V_80 ;
switch ( V_151 ) {
case 1000 :
F_28 ( V_138 -> V_87 , V_30 , 0x24 ) ;
F_28 ( V_138 -> V_87 , V_31 , 0x24 ) ;
F_28 ( V_138 -> V_87 , V_32 ,
0x4E ) ;
F_28 ( V_138 -> V_87 , V_33 , 0 ) ;
break;
case 1200 :
F_28 ( V_138 -> V_87 , V_30 , 0x20 ) ;
F_28 ( V_138 -> V_87 , V_31 , 0x20 ) ;
F_28 ( V_138 -> V_87 , V_32 ,
0x47 ) ;
F_28 ( V_138 -> V_87 , V_33 , 1 ) ;
break;
case 1500 :
F_28 ( V_138 -> V_87 , V_30 , 0x20 ) ;
F_28 ( V_138 -> V_87 , V_31 , 0x20 ) ;
F_28 ( V_138 -> V_87 , V_32 ,
0x3C ) ;
F_28 ( V_138 -> V_87 , V_33 , 2 ) ;
break;
case 2200 :
F_28 ( V_138 -> V_87 , V_30 , 0x19 ) ;
F_28 ( V_138 -> V_87 , V_31 , 0x25 ) ;
F_28 ( V_138 -> V_87 , V_32 ,
0x23 ) ;
F_28 ( V_138 -> V_87 , V_33 , 3 ) ;
break;
default:
F_8 ( V_80 -> V_2 , L_8 ,
V_110 , V_151 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_29 ( struct V_79 * V_80 )
{
int V_84 = 0 ;
struct V_82 * V_138 = F_6 ( V_80 ) ;
F_30 ( V_80 -> V_2 ) ;
F_7 ( V_138 -> V_87 , V_25 ,
V_152 , 0x8 ) ;
F_28 ( V_138 -> V_87 , V_17 , 0xFD ) ;
F_28 ( V_138 -> V_87 , V_18 , 0x1F ) ;
F_7 ( V_138 -> V_87 , V_25 ,
V_107 , V_107 ) ;
if ( V_138 -> V_105 . V_153 )
F_7 ( V_138 -> V_87 , V_28 ,
V_154 ,
V_138 -> V_105 . V_153 ) ;
if ( V_138 -> V_105 . V_155 )
F_7 ( V_138 -> V_87 , V_25 ,
V_156 , 0 ) ;
else
F_7 ( V_138 -> V_87 , V_25 ,
V_156 , V_156 ) ;
if ( V_138 -> V_105 . V_157 )
F_7 ( V_138 -> V_87 , V_19 ,
V_158 , 0 ) ;
if ( V_138 -> V_105 . V_159 )
F_7 ( V_138 -> V_87 , V_22 ,
V_111 , 0 ) ;
if ( V_138 -> V_105 . V_160 )
F_7 ( V_138 -> V_87 , V_22 ,
V_161 , V_161 ) ;
if ( V_138 -> V_105 . V_162 )
V_84 = F_27 ( V_138 , V_138 -> V_105 . V_162 ) ;
if ( V_138 -> V_105 . V_163 )
F_7 ( V_138 -> V_87 , V_50 ,
V_164 ,
V_138 -> V_105 . V_163 << V_165 ) ;
if ( V_138 -> V_105 . V_166 )
F_7 ( V_138 -> V_87 , V_51 ,
1 , 1 ) ;
F_31 ( V_80 -> V_2 ) ;
return V_84 ;
}
static int F_32 ( struct V_167 * V_167 ,
struct V_168 * V_105 )
{
struct V_169 * V_170 = V_167 -> V_2 . V_171 ;
unsigned int V_172 ;
if ( F_33 ( V_170 , L_9 ,
& V_172 ) >= 0 ) {
if ( V_172 > 8000 || ( V_172 < 3300 && V_172 > 0 ) ) {
F_8 ( & V_167 -> V_2 ,
L_10 , V_172 ) ;
return - V_100 ;
}
if ( V_172 == 0 )
V_105 -> V_106 = 0 ;
else
V_105 -> V_106 = ( ( V_172 - 3300 ) / 100 ) + 1 ;
} else {
F_34 ( & V_167 -> V_2 ,
L_11 ) ;
}
if ( F_33 ( V_170 , L_12 , & V_172 ) >= 0 ) {
V_105 -> V_162 = V_172 ;
} else {
F_8 ( & V_167 -> V_2 , L_13 ) ;
return - V_100 ;
}
if ( F_33 ( V_170 , L_14 , & V_172 ) >= 0 ) {
if ( V_172 > 3840 || V_172 < 1200 ) {
F_8 ( & V_167 -> V_2 ,
L_15 , V_172 ) ;
return - V_100 ;
}
V_105 -> V_153 = ( ( V_172 - 1200 ) / 80 ) + 1 ;
}
V_105 -> V_157 = F_35 ( V_170 ,
L_16 ) ;
V_105 -> V_159 = F_35 ( V_170 ,
L_17 ) ;
V_105 -> V_155 = F_35 ( V_170 ,
L_18 ) ;
V_105 -> V_160 = F_35 ( V_170 , L_19 ) ;
if ( F_33 ( V_170 , L_20 , & V_172 ) >= 0 )
V_105 -> V_163 = V_172 ;
if ( F_33 ( V_170 , L_21 , & V_172 ) >= 0 )
V_105 -> V_166 = V_172 ;
return 0 ;
}
static T_1 F_36 ( int V_173 , void * V_174 )
{
struct V_82 * V_138 = V_174 ;
struct V_79 * V_80 = V_138 -> V_80 ;
unsigned int V_175 , V_176 , V_177 , V_178 ;
unsigned int V_179 , V_180 , V_181 , V_182 , V_183 ;
F_16 ( V_138 -> V_87 , V_12 , & V_178 ) ;
F_16 ( V_138 -> V_87 , V_11 , & V_177 ) ;
F_16 ( V_138 -> V_87 , V_10 , & V_176 ) ;
F_16 ( V_138 -> V_87 , V_9 , & V_175 ) ;
F_16 ( V_138 -> V_87 , V_73 , & V_182 ) ;
F_16 ( V_138 -> V_87 , V_72 , & V_181 ) ;
F_16 ( V_138 -> V_87 , V_71 , & V_180 ) ;
F_16 ( V_138 -> V_87 , V_70 , & V_179 ) ;
if ( ! ( V_175 & ~ V_179 ) && ! ( V_176 & ~ V_180 ) && ! ( V_177 & ~ V_181 )
&& ! ( V_178 & ~ V_182 ) )
return V_184 ;
F_16 ( V_138 -> V_87 , V_9 , & V_183 ) ;
if ( V_175 & V_185 ) {
F_8 ( V_80 -> V_2 , L_22 ) ;
if ( ! ( V_183 & V_185 ) ) {
F_37 ( V_80 -> V_2 , L_23 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_186 , 0 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_186 ,
V_186 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_186 , 0 ) ;
}
}
if ( V_175 & V_187 )
F_8 ( V_80 -> V_2 , L_24 ) ;
if ( V_175 & V_188 ) {
F_38 ( V_80 -> V_2 , L_25 ) ;
if ( ! ( V_183 & V_188 ) ) {
F_37 ( V_80 -> V_2 ,
L_26 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_189 , 0 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_189 ,
V_189 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_189 , 0 ) ;
}
}
if ( V_175 & V_190 ) {
F_38 ( V_80 -> V_2 , L_27 ) ;
if ( ! ( V_183 & V_190 ) ) {
F_37 ( V_80 -> V_2 ,
L_28 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_191 , 0 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_191 ,
V_191 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_191 , 0 ) ;
}
}
if ( V_175 & V_192 ) {
F_38 ( V_80 -> V_2 , L_29 ) ;
if ( ! ( V_183 & V_192 ) ) {
F_37 ( V_80 -> V_2 ,
L_30 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_193 , 0 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_193 ,
V_193 ) ;
F_7 ( V_138 -> V_87 ,
V_66 ,
V_193 , 0 ) ;
}
}
if ( V_177 & V_194 ) {
F_38 ( V_80 -> V_2 , L_31 ) ;
F_7 ( V_138 -> V_87 , V_17 ,
V_195 , V_195 ) ;
F_7 ( V_138 -> V_87 , V_16 ,
V_89 , V_89 ) ;
}
if ( V_177 & V_196 ) {
F_38 ( V_80 -> V_2 , L_32 ) ;
F_7 ( V_138 -> V_87 , V_17 ,
V_195 , V_195 ) ;
F_7 ( V_138 -> V_87 , V_16 ,
V_89 , V_89 ) ;
}
return V_197 ;
}
static int F_39 ( struct V_167 * V_167 ,
const struct V_198 * V_199 )
{
struct V_82 * V_138 ;
struct V_168 * V_105 =
F_40 ( & V_167 -> V_2 ) ;
int V_108 ;
int V_84 ;
unsigned int V_200 = 0 ;
unsigned int V_3 ;
V_138 = F_41 ( & V_167 -> V_2 ,
sizeof( struct V_82 ) ,
V_201 ) ;
if ( ! V_138 ) {
F_8 ( & V_167 -> V_2 , L_33 ) ;
return - V_202 ;
}
F_42 ( V_167 , V_138 ) ;
V_138 -> V_87 = F_43 ( V_167 , & V_203 ) ;
if ( F_44 ( V_138 -> V_87 ) ) {
V_84 = F_45 ( V_138 -> V_87 ) ;
F_8 ( & V_167 -> V_2 , L_34 , V_84 ) ;
return V_84 ;
}
V_138 -> V_204 = F_19 ( V_205 ) ;
for ( V_108 = 0 ; V_108 < F_19 ( V_205 ) ; V_108 ++ )
V_138 -> V_206 [ V_108 ] . V_207 = V_205 [ V_108 ] ;
V_84 = F_46 ( & V_167 -> V_2 ,
V_138 -> V_204 ,
V_138 -> V_206 ) ;
if ( V_84 != 0 ) {
F_8 ( & V_167 -> V_2 ,
L_35 , V_84 ) ;
return V_84 ;
}
V_84 = F_47 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
if ( V_84 != 0 ) {
F_8 ( & V_167 -> V_2 ,
L_36 , V_84 ) ;
return V_84 ;
}
if ( V_105 ) {
V_138 -> V_105 = * V_105 ;
} else {
V_105 = F_41 ( & V_167 -> V_2 ,
sizeof( struct V_168 ) ,
V_201 ) ;
if ( ! V_105 ) {
F_8 ( & V_167 -> V_2 ,
L_37 ) ;
return - V_202 ;
}
if ( V_167 -> V_2 . V_171 ) {
V_84 = F_32 ( V_167 , V_105 ) ;
if ( V_84 != 0 )
return V_84 ;
}
V_138 -> V_105 = * V_105 ;
}
V_84 = F_48 ( & V_167 -> V_2 , V_167 -> V_173 , NULL ,
F_36 , V_208 | V_209 ,
L_38 , V_138 ) ;
if ( V_84 != 0 )
F_8 ( & V_167 -> V_2 , L_39 , V_84 ) ;
V_138 -> V_210 = F_49 ( & V_167 -> V_2 ,
L_40 , V_211 ) ;
if ( F_44 ( V_138 -> V_210 ) )
return F_45 ( V_138 -> V_210 ) ;
F_50 ( V_138 -> V_210 , 1 ) ;
F_17 ( V_212 ) ;
V_84 = F_16 ( V_138 -> V_87 , V_4 , & V_3 ) ;
V_200 = ( V_3 & 0xFF ) << 12 ;
V_84 = F_16 ( V_138 -> V_87 , V_5 , & V_3 ) ;
V_200 |= ( V_3 & 0xFF ) << 4 ;
V_84 = F_16 ( V_138 -> V_87 , V_6 , & V_3 ) ;
V_200 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_200 != V_213 ) {
F_8 ( & V_167 -> V_2 ,
L_41 ,
V_200 , V_213 ) ;
V_84 = - V_214 ;
goto V_215;
}
V_84 = F_16 ( V_138 -> V_87 , V_8 , & V_3 ) ;
if ( V_84 < 0 ) {
F_8 ( & V_167 -> V_2 , L_42 ) ;
goto V_215;
}
F_51 ( & V_167 -> V_2 ,
L_43 , V_200 ,
V_3 & 0xFF ) ;
F_7 ( V_138 -> V_87 , V_70 ,
V_216 | V_217 |
V_218 | V_219 |
V_220 , 0 ) ;
F_7 ( V_138 -> V_87 , V_72 ,
V_221 | V_222 , 0 ) ;
F_52 ( & V_167 -> V_2 , 100 ) ;
F_53 ( & V_167 -> V_2 ) ;
F_54 ( & V_167 -> V_2 ) ;
F_55 ( & V_167 -> V_2 ) ;
V_84 = F_56 ( & V_167 -> V_2 ,
& V_223 , & V_224 , 1 ) ;
if ( V_84 < 0 ) {
F_8 ( & V_167 -> V_2 ,
L_44 , V_110 ) ;
goto V_215;
}
return 0 ;
V_215:
F_57 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
return V_84 ;
}
static int F_58 ( struct V_167 * V_225 )
{
struct V_82 * V_138 = F_59 ( V_225 ) ;
F_60 ( & V_225 -> V_2 ) ;
F_50 ( V_138 -> V_210 , 0 ) ;
F_61 ( & V_225 -> V_2 ) ;
F_57 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
return 0 ;
}
static int T_2 F_62 ( struct V_1 * V_2 )
{
struct V_82 * V_138 = F_63 ( V_2 ) ;
int V_84 ;
V_84 = F_47 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
if ( V_84 != 0 ) {
F_8 ( V_2 , L_36 ,
V_84 ) ;
return V_84 ;
}
F_64 ( V_138 -> V_87 , false ) ;
F_50 ( V_138 -> V_210 , 1 ) ;
F_17 ( V_212 ) ;
V_84 = F_65 ( V_138 -> V_87 ) ;
if ( V_84 != 0 ) {
F_8 ( V_2 , L_45 ) ;
goto V_226;
}
return 0 ;
V_226:
F_64 ( V_138 -> V_87 , true ) ;
F_57 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
return V_84 ;
}
static int T_2 F_66 ( struct V_1 * V_2 )
{
struct V_82 * V_138 = F_63 ( V_2 ) ;
F_64 ( V_138 -> V_87 , true ) ;
F_67 ( V_138 -> V_87 ) ;
F_50 ( V_138 -> V_210 , 0 ) ;
F_57 ( V_138 -> V_204 ,
V_138 -> V_206 ) ;
return 0 ;
}
static int T_3 F_68 ( void )
{
int V_84 ;
V_84 = F_69 ( & V_227 ) ;
if ( V_84 != 0 ) {
F_10 ( L_46 , V_84 ) ;
return V_84 ;
}
return 0 ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_227 ) ;
}
