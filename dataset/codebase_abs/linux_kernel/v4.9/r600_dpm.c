void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( L_1 ) ;
switch ( V_1 & V_3 ) {
case V_4 :
default:
F_2 ( L_2 ) ;
break;
case V_5 :
F_2 ( L_3 ) ;
break;
case V_6 :
F_2 ( L_4 ) ;
break;
case V_7 :
F_2 ( L_5 ) ;
break;
}
F_2 ( L_6 ) ;
if ( ( ( V_1 & ~ V_3 ) == 0 ) &&
( V_2 == 0 ) )
F_2 ( L_7 ) ;
else {
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
if ( V_1 & V_9 )
F_2 ( L_9 ) ;
if ( V_1 & V_10 )
F_2 ( L_10 ) ;
if ( V_1 & V_11 )
F_2 ( L_11 ) ;
if ( V_1 & V_12 )
F_2 ( L_12 ) ;
if ( V_1 & V_13 )
F_2 ( L_13 ) ;
if ( V_1 & V_14 )
F_2 ( L_14 ) ;
if ( V_1 & V_15 )
F_2 ( L_15 ) ;
if ( V_1 & V_16 )
F_2 ( L_16 ) ;
if ( V_1 & V_17 )
F_2 ( L_17 ) ;
if ( V_1 & V_18 )
F_2 ( L_18 ) ;
if ( V_1 & V_19 )
F_2 ( L_19 ) ;
if ( V_1 & V_20 )
F_2 ( L_20 ) ;
if ( V_2 & V_21 )
F_2 ( L_21 ) ;
if ( V_2 & V_22 )
F_2 ( L_22 ) ;
if ( V_2 & V_23 )
F_2 ( L_23 ) ;
}
F_2 ( L_24 ) ;
}
void F_3 ( T_1 V_24 )
{
F_2 ( L_25 ) ;
if ( V_24 & V_25 )
F_2 ( L_26 ) ;
if ( V_24 & V_26 )
F_2 ( L_27 ) ;
if ( V_24 & V_27 )
F_2 ( L_28 ) ;
F_2 ( L_24 ) ;
}
void F_4 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
F_2 ( L_29 ) ;
if ( V_31 == V_29 -> V_32 . V_33 . V_34 )
F_2 ( L_30 ) ;
if ( V_31 == V_29 -> V_32 . V_33 . V_35 )
F_2 ( L_31 ) ;
if ( V_31 == V_29 -> V_32 . V_33 . V_36 )
F_2 ( L_32 ) ;
F_2 ( L_24 ) ;
}
T_1 F_5 ( struct V_28 * V_29 )
{
struct V_37 * V_38 = V_29 -> V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_42 ;
T_1 V_43 ;
T_1 V_44 = 0xffffffff ;
if ( V_29 -> V_45 && V_29 -> V_46 . V_47 ) {
F_6 (crtc, &dev->mode_config.crtc_list, head) {
V_42 = F_7 ( V_41 ) ;
if ( V_41 -> V_48 && V_42 -> V_48 && V_42 -> V_49 . clock ) {
V_43 =
V_42 -> V_49 . V_50 *
( V_42 -> V_49 . V_51 -
V_42 -> V_49 . V_52 +
( V_42 -> V_53 * 2 ) ) ;
V_44 = V_43 * 1000 / V_42 -> V_49 . clock ;
break;
}
}
}
return V_44 ;
}
T_1 F_8 ( struct V_28 * V_29 )
{
struct V_37 * V_38 = V_29 -> V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_42 ;
T_1 V_54 = 0 ;
if ( V_29 -> V_45 && V_29 -> V_46 . V_47 ) {
F_6 (crtc, &dev->mode_config.crtc_list, head) {
V_42 = F_7 ( V_41 ) ;
if ( V_41 -> V_48 && V_42 -> V_48 && V_42 -> V_49 . clock ) {
V_54 = F_9 ( & V_42 -> V_49 ) ;
break;
}
}
}
return V_54 ;
}
void F_10 ( T_1 V_55 , T_1 V_56 , T_1 V_57 ,
T_1 * V_58 , T_1 * V_59 )
{
T_1 V_60 = 0 ;
T_1 V_61 ;
T_1 V_62 ;
V_61 = ( V_55 * V_56 ) / 100 ;
V_62 = V_61 >> V_57 ;
while ( V_62 ) {
V_60 ++ ;
V_62 >>= 1 ;
}
* V_59 = ( V_60 + 1 ) / 2 ;
* V_58 = V_61 / ( 1 << ( 2 * ( * V_59 ) ) ) ;
}
int F_11 ( T_1 V_63 , T_1 V_64 , T_1 V_65 , T_1 V_66 , T_1 * V_67 , T_1 * V_68 )
{
T_1 V_69 , V_70 , V_71 , V_72 ;
T_1 V_73 ;
if ( ( V_66 == 0 ) || ( V_65 == 0 ) || ( V_66 > V_65 ) )
return - V_74 ;
V_69 = ( 100 * V_65 ) / V_66 ;
V_73 = ( V_63 * ( V_69 - 100 ) ) ;
V_70 = ( 1000 * ( 100 * V_64 + V_73 ) ) / ( 10000 + ( V_73 / 100 ) ) ;
V_70 = ( V_70 + 5 ) / 10 ;
V_71 = ( ( V_70 * V_63 ) + 5000 ) / 10000 ;
V_72 = V_70 - V_71 ;
* V_68 = V_63 - V_71 ;
* V_67 = V_63 + V_72 ;
return 0 ;
}
void F_12 ( struct V_28 * V_29 , bool V_75 )
{
int V_55 ;
if ( V_75 ) {
F_13 ( V_76 , V_77 , ~ V_77 ) ;
} else {
F_13 ( V_76 , 0 , ~ V_77 ) ;
F_14 ( V_78 , 0x2 ) ;
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( ( ( F_15 ( V_78 ) & V_80 ) >> V_81 ) == 1 )
break;
F_16 ( 1 ) ;
}
F_14 ( V_78 , 0x0 ) ;
F_14 ( V_82 , 0x1 ) ;
F_15 ( V_82 ) ;
}
}
void F_17 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_83 , V_84 , ~ V_84 ) ;
else
F_13 ( V_83 , 0 , ~ V_84 ) ;
}
void F_18 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_83 , 0 , ~ V_85 ) ;
else
F_13 ( V_83 , V_85 , ~ V_85 ) ;
}
void F_19 ( struct V_28 * V_29 )
{
F_13 ( V_83 , V_86 , ~ V_86 ) ;
}
void F_20 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_83 , V_87 , ~ V_87 ) ;
else
F_13 ( V_83 , 0 , ~ V_87 ) ;
}
bool F_21 ( struct V_28 * V_29 )
{
if ( F_15 ( V_83 ) & V_84 )
return true ;
else
return false ;
}
void F_22 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_76 , 0 , ~ V_88 ) ;
else
F_13 ( V_76 , V_88 , ~ V_88 ) ;
}
void F_23 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_89 , 0 , ~ V_90 ) ;
else
F_13 ( V_89 , V_90 , ~ V_90 ) ;
}
void F_24 ( struct V_28 * V_29 , bool V_75 )
{
if ( V_75 )
F_13 ( V_91 , V_92 , ~ V_92 ) ;
else
F_13 ( V_91 , 0 , ~ V_92 ) ;
}
void F_25 ( struct V_28 * V_29 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( F_15 ( V_91 ) & V_93 )
break;
F_16 ( 1 ) ;
}
}
void F_26 ( struct V_28 * V_29 , T_1 V_59 , T_1 V_58 )
{
F_14 ( V_94 , F_27 ( V_58 ) | F_28 ( V_59 ) ) ;
}
void F_29 ( struct V_28 * V_29 ,
T_1 V_95 , T_1 V_96 ,
T_1 V_97 , T_1 V_98 )
{
F_14 ( V_99 , F_30 ( V_95 ) | F_31 ( V_96 ) ) ;
F_14 ( V_100 , F_32 ( V_97 ) | F_31 ( V_98 ) ) ;
}
void F_33 ( struct V_28 * V_29 ,
T_1 V_101 , T_1 V_102 , T_1 V_103 )
{
F_14 ( V_104 + ( V_101 * 4 ) , F_34 ( V_102 ) | F_35 ( V_103 ) ) ;
}
void F_36 ( struct V_28 * V_29 ,
enum V_105 V_106 )
{
if ( V_106 == V_107 )
F_13 ( V_76 , 0 , ~ V_108 ) ;
else
F_13 ( V_76 , V_108 , ~ V_108 ) ;
if ( V_106 == V_109 )
F_13 ( V_76 , 0 , ~ V_110 ) ;
if ( V_106 == V_111 )
F_13 ( V_76 , V_110 , ~ V_110 ) ;
}
void F_37 ( struct V_28 * V_29 , T_1 V_112 )
{
F_14 ( V_113 , V_112 ) ;
}
void F_38 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_114 , F_39 ( V_59 ) , ~ V_115 ) ;
}
void F_40 ( struct V_28 * V_29 , T_1 V_116 )
{
F_13 ( V_114 , F_41 ( V_116 ) , ~ V_117 ) ;
}
void F_42 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_118 , F_43 ( V_59 ) , ~ V_119 ) ;
}
void F_44 ( struct V_28 * V_29 , T_1 V_63 )
{
F_13 ( V_118 , F_45 ( V_63 ) , ~ V_120 ) ;
}
void F_46 ( struct V_28 * V_29 , T_1 V_63 )
{
F_13 ( V_121 , F_47 ( V_63 ) , ~ V_122 ) ;
}
void F_48 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_123 , F_49 ( V_59 ) , ~ V_124 ) ;
}
void F_50 ( struct V_28 * V_29 , T_1 V_63 )
{
F_13 ( V_123 , F_51 ( V_63 ) , ~ V_125 ) ;
}
void F_52 ( struct V_28 * V_29 , T_1 V_58 )
{
F_13 ( V_126 , F_53 ( V_58 ) , ~ V_127 ) ;
}
void F_54 ( struct V_28 * V_29 , T_1 V_128 )
{
F_13 ( V_126 , F_55 ( V_128 ) , ~ V_129 ) ;
}
void F_56 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_130 , F_57 ( V_59 ) , ~ V_131 ) ;
}
void F_58 ( struct V_28 * V_29 , T_1 V_58 )
{
F_13 ( V_130 , F_53 ( V_58 ) , ~ V_127 ) ;
}
void F_59 ( struct V_28 * V_29 , T_1 V_128 )
{
F_13 ( V_130 , F_55 ( V_128 ) , ~ V_129 ) ;
}
void F_60 ( struct V_28 * V_29 , T_1 V_132 )
{
F_13 ( V_133 , F_61 ( V_132 ) , ~ V_134 ) ;
}
void F_62 ( struct V_28 * V_29 , T_1 V_135 )
{
F_13 ( V_133 , F_63 ( V_135 ) , ~ V_136 ) ;
}
void F_64 ( struct V_28 * V_29 ,
T_1 V_101 , bool V_75 )
{
if ( V_75 )
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
V_138 , ~ V_138 ) ;
else
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
0 , ~ V_138 ) ;
}
void F_65 ( struct V_28 * V_29 ,
T_1 V_101 , bool V_75 )
{
if ( V_75 )
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
V_139 , ~ V_139 ) ;
else
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
0 , ~ V_139 ) ;
}
void F_66 ( struct V_28 * V_29 ,
T_1 V_101 , bool V_75 )
{
if ( V_75 )
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
V_140 , ~ V_140 ) ;
else
F_13 ( V_137 + ( V_101 * 4 * 2 ) ,
0 , ~ V_140 ) ;
}
void F_67 ( struct V_28 * V_29 ,
T_1 V_101 , T_1 V_141 )
{
F_13 ( V_142 + ( V_101 * 4 * 2 ) ,
F_68 ( V_141 ) , ~ V_143 ) ;
}
void F_69 ( struct V_28 * V_29 ,
T_1 V_101 , T_1 V_141 )
{
F_13 ( V_142 + ( V_101 * 4 * 2 ) ,
F_70 ( V_141 ) , ~ V_144 ) ;
}
void F_71 ( struct V_28 * V_29 ,
T_1 V_101 , T_1 V_141 )
{
F_13 ( V_142 + ( V_101 * 4 * 2 ) ,
F_72 ( V_141 ) , ~ V_145 ) ;
}
void F_73 ( struct V_28 * V_29 ,
T_1 V_101 , T_1 V_146 )
{
F_13 ( V_142 + ( V_101 * 4 * 2 ) ,
F_74 ( V_146 ) , ~ V_147 ) ;
}
void F_75 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_148 , F_76 ( V_59 ) , ~ V_149 ) ;
}
void F_77 ( struct V_28 * V_29 , T_1 V_59 )
{
F_13 ( V_148 , F_78 ( V_59 ) , ~ V_150 ) ;
}
void F_79 ( struct V_28 * V_29 , T_1 V_151 )
{
F_13 ( V_148 , F_80 ( V_151 ) , ~ V_152 ) ;
}
void F_81 ( struct V_28 * V_29 ,
T_2 V_153 )
{
F_14 ( V_154 , V_153 & 0xffffffff ) ;
F_14 ( V_155 , F_82 ( V_153 ) ) ;
}
void F_83 ( struct V_28 * V_29 ,
enum V_156 V_101 , T_2 V_157 )
{
T_1 V_62 , V_153 ;
T_1 V_158 = 3 - ( 3 & V_101 ) ;
F_14 ( V_159 + ( V_158 * 4 ) , V_157 & 0xffffffff ) ;
V_153 = 7 << ( 3 * V_158 ) ;
V_62 = F_15 ( V_160 ) ;
V_62 = ( V_62 & ~ V_153 ) | ( ( V_157 >> ( 32 - ( 3 * V_158 ) ) ) & V_153 ) ;
F_14 ( V_160 , V_62 ) ;
}
void F_84 ( struct V_28 * V_29 ,
T_2 V_153 )
{
T_1 V_161 ;
V_161 = F_15 ( V_162 ) ;
V_161 &= ~ V_153 ;
F_14 ( V_162 , V_161 ) ;
V_161 = F_15 ( V_163 ) ;
V_161 &= ~ V_153 ;
F_14 ( V_163 , V_161 ) ;
V_161 = F_15 ( V_164 ) ;
V_161 &= ~ V_153 ;
F_14 ( V_164 , V_161 ) ;
}
void F_85 ( struct V_28 * V_29 ,
enum V_156 V_101 , bool V_75 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
if ( V_75 )
F_13 ( V_165 + ( V_158 * 4 ) , V_166 ,
~ V_166 ) ;
else
F_13 ( V_165 + ( V_158 * 4 ) , 0 ,
~ V_166 ) ;
}
void F_86 ( struct V_28 * V_29 ,
enum V_156 V_101 , T_1 V_167 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
F_13 ( V_165 + ( V_158 * 4 ) ,
F_87 ( V_167 ) , ~ V_168 ) ;
}
void F_88 ( struct V_28 * V_29 ,
enum V_156 V_101 , T_1 V_169 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
F_13 ( V_165 + ( V_158 * 4 ) ,
F_89 ( V_169 ) , ~ V_170 ) ;
}
void F_90 ( struct V_28 * V_29 ,
enum V_156 V_101 , T_1 V_171 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
F_13 ( V_165 + ( V_158 * 4 ) ,
F_91 ( V_171 ) , ~ V_172 ) ;
}
void F_92 ( struct V_28 * V_29 ,
enum V_156 V_101 ,
enum V_173 V_174 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
T_1 V_62 = 0 ;
if ( V_174 == V_175 )
V_62 = V_176 ;
F_13 ( V_165 + ( V_158 * 4 ) , V_62 , ~ V_176 ) ;
}
void F_93 ( struct V_28 * V_29 ,
enum V_156 V_101 , bool V_177 )
{
T_1 V_158 = 3 - ( 3 & V_101 ) ;
T_1 V_62 = 0 ;
if ( V_177 )
V_62 = V_178 ;
F_13 ( V_165 + ( V_158 * 4 ) , V_62 , ~ V_178 ) ;
}
enum V_156 F_94 ( struct V_28 * V_29 )
{
T_1 V_62 ;
V_62 = F_15 ( V_179 ) & V_180 ;
V_62 >>= V_181 ;
return V_62 ;
}
enum V_156 F_95 ( struct V_28 * V_29 )
{
T_1 V_62 ;
V_62 = F_15 ( V_179 ) & V_182 ;
V_62 >>= V_183 ;
return V_62 ;
}
void F_96 ( struct V_28 * V_29 ,
enum V_156 V_101 )
{
F_13 ( V_179 , F_97 ( V_101 ) ,
~ V_184 ) ;
}
void F_98 ( struct V_28 * V_29 ,
enum V_156 V_101 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( F_95 ( V_29 ) != V_101 )
break;
F_16 ( 1 ) ;
}
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( F_94 ( V_29 ) != V_101 )
break;
F_16 ( 1 ) ;
}
}
void F_99 ( struct V_28 * V_29 ,
enum V_156 V_101 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( F_95 ( V_29 ) == V_101 )
break;
F_16 ( 1 ) ;
}
for ( V_55 = 0 ; V_55 < V_29 -> V_79 ; V_55 ++ ) {
if ( F_94 ( V_29 ) == V_101 )
break;
F_16 ( 1 ) ;
}
}
void F_100 ( struct V_28 * V_29 )
{
F_22 ( V_29 , false ) ;
F_23 ( V_29 , false ) ;
F_17 ( V_29 , true ) ;
F_101 ( V_29 , 0 ) ;
F_101 ( V_29 , 1 ) ;
F_24 ( V_29 , true ) ;
F_25 ( V_29 ) ;
F_24 ( V_29 , false ) ;
F_25 ( V_29 ) ;
F_24 ( V_29 , true ) ;
F_25 ( V_29 ) ;
F_24 ( V_29 , false ) ;
F_25 ( V_29 ) ;
F_22 ( V_29 , true ) ;
F_23 ( V_29 , true ) ;
}
void F_102 ( struct V_28 * V_29 )
{
F_17 ( V_29 , false ) ;
}
int F_103 ( struct V_28 * V_29 )
{
return 0 ;
}
void F_104 ( struct V_28 * V_29 )
{
}
bool F_105 ( T_1 V_1 , T_1 V_2 )
{
if ( V_1 & V_15 )
return true ;
if ( V_1 & V_18 )
return true ;
if ( V_1 & V_19 )
return true ;
if ( V_1 & V_20 )
return true ;
if ( V_2 & V_23 )
return true ;
return false ;
}
static int F_106 ( struct V_28 * V_29 ,
int V_185 , int V_186 )
{
int V_187 = 0 * 1000 ;
int V_188 = 255 * 1000 ;
if ( V_187 < V_185 )
V_187 = V_185 ;
if ( V_188 > V_186 )
V_188 = V_186 ;
if ( V_188 < V_187 ) {
F_107 ( L_33 , V_187 , V_188 ) ;
return - V_74 ;
}
F_13 ( V_189 , F_108 ( V_188 / 1000 ) , ~ V_190 ) ;
F_13 ( V_189 , F_109 ( V_187 / 1000 ) , ~ V_191 ) ;
F_13 ( V_192 , F_110 ( V_188 / 1000 ) , ~ V_193 ) ;
V_29 -> V_32 . V_33 . V_194 . V_185 = V_187 ;
V_29 -> V_32 . V_33 . V_194 . V_186 = V_188 ;
return 0 ;
}
bool F_111 ( enum V_195 V_196 )
{
switch ( V_196 ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
return true ;
case V_205 :
case V_206 :
return false ;
case V_207 :
case V_208 :
case V_209 :
default:
return false ;
}
}
int F_112 ( struct V_28 * V_29 )
{
int V_210 ;
if ( V_29 -> V_211 . V_212 &&
F_111 ( V_29 -> V_32 . V_213 ) ) {
V_210 = F_106 ( V_29 , V_214 , V_215 ) ;
if ( V_210 )
return V_210 ;
V_29 -> V_211 . V_216 = true ;
F_113 ( V_29 ) ;
}
return 0 ;
}
static int F_114 ( struct V_217 * V_218 ,
T_3 * V_219 )
{
T_1 V_220 = V_219 -> V_221 *
sizeof( struct V_222 ) ;
int V_55 ;
T_4 * V_223 ;
V_218 -> V_224 = F_115 ( V_220 , V_225 ) ;
if ( ! V_218 -> V_224 )
return - V_226 ;
V_223 = & V_219 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_219 -> V_221 ; V_55 ++ ) {
V_218 -> V_224 [ V_55 ] . V_227 = F_116 ( V_223 -> V_228 ) |
( V_223 -> V_229 << 16 ) ;
V_218 -> V_224 [ V_55 ] . V_230 = F_116 ( V_223 -> V_231 ) ;
V_223 = ( T_4 * )
( ( V_232 * ) V_223 + sizeof( T_4 ) ) ;
}
V_218 -> V_233 = V_219 -> V_221 ;
return 0 ;
}
int F_117 ( struct V_28 * V_29 )
{
struct V_234 * V_46 = & V_29 -> V_46 ;
union V_235 * V_235 ;
int V_101 = F_118 ( V_236 , V_237 ) ;
T_5 V_238 ;
V_232 V_239 , V_240 ;
if ( ! F_119 ( V_46 -> V_241 , V_101 , NULL ,
& V_239 , & V_240 , & V_238 ) )
return - V_74 ;
V_235 = (union V_235 * ) ( V_46 -> V_241 -> V_242 + V_238 ) ;
V_29 -> V_32 . V_33 . V_243 = F_120 ( V_235 -> V_244 . V_245 ) ;
V_29 -> V_32 . V_33 . V_246 = F_116 ( V_235 -> V_244 . V_247 ) ;
V_29 -> V_32 . V_33 . V_248 = F_116 ( V_235 -> V_244 . V_249 ) ;
return 0 ;
}
int F_121 ( struct V_28 * V_29 )
{
struct V_234 * V_46 = & V_29 -> V_46 ;
union V_235 * V_235 ;
union V_250 * V_250 ;
T_3 * V_251 ;
int V_101 = F_118 ( V_236 , V_237 ) ;
T_5 V_238 ;
V_232 V_239 , V_240 ;
int V_210 , V_55 ;
if ( ! F_119 ( V_46 -> V_241 , V_101 , NULL ,
& V_239 , & V_240 , & V_238 ) )
return - V_74 ;
V_235 = (union V_235 * ) ( V_46 -> V_241 -> V_242 + V_238 ) ;
if ( F_116 ( V_235 -> V_244 . V_252 ) >=
sizeof( struct V_253 ) ) {
if ( V_235 -> V_254 . V_255 ) {
V_250 = (union V_250 * ) ( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_254 . V_255 ) ) ;
V_29 -> V_32 . V_33 . V_256 . V_257 = V_250 -> V_256 . V_258 ;
V_29 -> V_32 . V_33 . V_256 . V_259 = F_116 ( V_250 -> V_256 . V_260 ) ;
V_29 -> V_32 . V_33 . V_256 . V_261 = F_116 ( V_250 -> V_256 . V_262 ) ;
V_29 -> V_32 . V_33 . V_256 . V_263 = F_116 ( V_250 -> V_256 . V_264 ) ;
V_29 -> V_32 . V_33 . V_256 . V_265 = F_116 ( V_250 -> V_256 . V_266 ) ;
V_29 -> V_32 . V_33 . V_256 . V_267 = F_116 ( V_250 -> V_256 . V_268 ) ;
V_29 -> V_32 . V_33 . V_256 . V_269 = F_116 ( V_250 -> V_256 . V_270 ) ;
if ( V_250 -> V_256 . V_271 >= 2 )
V_29 -> V_32 . V_33 . V_256 . V_272 = F_116 ( V_250 -> V_273 . V_274 ) ;
else
V_29 -> V_32 . V_33 . V_256 . V_272 = 10900 ;
V_29 -> V_32 . V_33 . V_256 . V_275 = 100000 ;
if ( V_250 -> V_256 . V_271 >= 3 ) {
V_29 -> V_32 . V_33 . V_256 . V_276 = V_250 -> V_277 . V_278 ;
V_29 -> V_32 . V_33 . V_256 . V_279 =
F_116 ( V_250 -> V_277 . V_280 ) ;
V_29 -> V_32 . V_33 . V_256 . V_281 = 4836 ;
V_29 -> V_32 . V_33 . V_256 . V_282 =
F_116 ( V_250 -> V_277 . V_283 ) ;
}
V_29 -> V_32 . V_33 . V_256 . V_284 = true ;
}
}
if ( F_116 ( V_235 -> V_244 . V_252 ) >=
sizeof( struct V_285 ) ) {
if ( V_235 -> V_286 . V_287 ) {
V_251 = ( T_3 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_287 ) ) ;
V_210 = F_114 ( & V_29 -> V_32 . V_33 . V_288 . V_289 ,
V_251 ) ;
if ( V_210 )
return V_210 ;
}
if ( V_235 -> V_286 . V_290 ) {
V_251 = ( T_3 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_290 ) ) ;
V_210 = F_114 ( & V_29 -> V_32 . V_33 . V_288 . V_291 ,
V_251 ) ;
if ( V_210 ) {
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_289 . V_224 ) ;
return V_210 ;
}
}
if ( V_235 -> V_286 . V_292 ) {
V_251 = ( T_3 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_292 ) ) ;
V_210 = F_114 ( & V_29 -> V_32 . V_33 . V_288 . V_293 ,
V_251 ) ;
if ( V_210 ) {
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_289 . V_224 ) ;
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_291 . V_224 ) ;
return V_210 ;
}
}
if ( V_235 -> V_286 . V_294 ) {
V_251 = ( T_3 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_294 ) ) ;
V_210 = F_114 ( & V_29 -> V_32 . V_33 . V_288 . V_295 ,
V_251 ) ;
if ( V_210 ) {
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_289 . V_224 ) ;
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_291 . V_224 ) ;
F_122 ( V_29 -> V_32 . V_33 . V_288 . V_293 . V_224 ) ;
return V_210 ;
}
}
if ( V_235 -> V_286 . V_296 ) {
T_6 * V_297 =
( T_6 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_296 ) ) ;
if ( V_297 -> V_221 ) {
V_29 -> V_32 . V_33 . V_288 . V_298 . V_299 =
F_116 ( V_297 -> V_224 [ 0 ] . V_300 ) |
( V_297 -> V_224 [ 0 ] . V_301 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_298 . V_302 =
F_116 ( V_297 -> V_224 [ 0 ] . V_303 ) |
( V_297 -> V_224 [ 0 ] . V_304 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_298 . V_305 =
F_116 ( V_297 -> V_224 [ 0 ] . V_306 ) ;
V_29 -> V_32 . V_33 . V_288 . V_298 . V_307 =
F_116 ( V_297 -> V_224 [ 0 ] . V_308 ) ;
}
}
if ( V_235 -> V_286 . V_309 ) {
T_7 * V_310 =
( T_7 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_286 . V_309 ) ) ;
T_8 * V_223 ;
V_29 -> V_32 . V_33 . V_288 . V_311 . V_224 =
F_115 ( V_310 -> V_221 *
sizeof( struct V_312 ) ,
V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_311 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_223 = & V_310 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_310 -> V_221 ; V_55 ++ ) {
V_29 -> V_32 . V_33 . V_288 . V_311 . V_224 [ V_55 ] . V_299 =
F_116 ( V_223 -> V_300 ) | ( V_223 -> V_301 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_311 . V_224 [ V_55 ] . V_302 =
F_116 ( V_223 -> V_303 ) | ( V_223 -> V_304 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_311 . V_224 [ V_55 ] . V_313 =
F_116 ( V_223 -> V_231 ) ;
V_223 = ( T_8 * )
( ( V_232 * ) V_223 + sizeof( T_8 ) ) ;
}
V_29 -> V_32 . V_33 . V_288 . V_311 . V_233 =
V_310 -> V_221 ;
}
}
if ( F_116 ( V_235 -> V_244 . V_252 ) >=
sizeof( struct V_314 ) ) {
V_29 -> V_32 . V_33 . V_315 = F_120 ( V_235 -> V_316 . V_317 ) ;
V_29 -> V_32 . V_33 . V_318 = F_120 ( V_235 -> V_316 . V_319 ) ;
V_29 -> V_32 . V_33 . V_320 = V_29 -> V_32 . V_33 . V_318 ;
V_29 -> V_32 . V_33 . V_321 = F_116 ( V_235 -> V_316 . V_322 ) ;
if ( V_29 -> V_32 . V_33 . V_321 )
V_29 -> V_32 . V_33 . V_323 = true ;
else
V_29 -> V_32 . V_33 . V_323 = false ;
V_29 -> V_32 . V_33 . V_324 = 0 ;
V_29 -> V_32 . V_33 . V_325 = F_120 ( V_235 -> V_316 . V_326 ) ;
V_29 -> V_32 . V_33 . V_327 = F_120 ( V_235 -> V_316 . V_328 ) ;
V_29 -> V_32 . V_33 . V_329 = F_116 ( V_235 -> V_316 . V_330 ) ;
if ( V_235 -> V_316 . V_331 ) {
T_9 * V_332 =
( T_9 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_316 . V_331 ) ) ;
T_10 * V_223 ;
T_1 V_220 = V_332 -> V_221 * sizeof( struct V_333 ) ;
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 = F_115 ( V_220 , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_223 = & V_332 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_332 -> V_221 ; V_55 ++ ) {
if ( V_29 -> V_32 . V_33 . V_243 & V_335 ) {
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 [ V_55 ] . V_336 =
F_116 ( V_223 -> V_337 ) ;
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 [ V_55 ] . V_338 =
F_116 ( V_223 -> V_339 ) ;
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 [ V_55 ] . V_340 =
F_116 ( V_223 -> V_341 ) ;
} else {
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 [ V_55 ] . V_305 =
F_116 ( V_223 -> V_306 ) ;
V_29 -> V_32 . V_33 . V_288 . V_334 . V_224 [ V_55 ] . V_342 =
F_120 ( V_223 -> V_343 ) ;
}
V_223 = ( T_10 * )
( ( V_232 * ) V_223 + sizeof( T_10 ) ) ;
}
V_29 -> V_32 . V_33 . V_288 . V_334 . V_233 = V_332 -> V_221 ;
}
}
if ( F_116 ( V_235 -> V_244 . V_252 ) >=
sizeof( struct V_253 ) ) {
T_11 * V_344 = ( T_11 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_235 -> V_254 . V_345 ) ) ;
if ( ( F_116 ( V_344 -> V_346 ) >= V_347 ) &&
V_344 -> V_348 ) {
T_12 * V_349 = ( T_12 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_348 ) + 1 ) ;
T_13 * V_350 =
( T_13 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_348 ) + 1 +
1 + V_349 -> V_221 * sizeof( V_351 ) ) ;
T_14 * V_352 =
( T_14 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_348 ) + 1 +
1 + ( V_349 -> V_221 * sizeof ( V_351 ) ) +
1 + ( V_350 -> V_353 * sizeof( V_354 ) ) ) ;
V_354 * V_223 ;
T_15 * V_355 ;
V_351 * V_356 ;
T_1 V_220 = V_350 -> V_353 *
sizeof( struct V_357 ) ;
V_29 -> V_32 . V_33 . V_288 . V_358 . V_224 =
F_115 ( V_220 , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_358 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_29 -> V_32 . V_33 . V_288 . V_358 . V_233 =
V_350 -> V_353 ;
V_223 = & V_350 -> V_224 [ 0 ] ;
V_355 = & V_352 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_350 -> V_353 ; V_55 ++ ) {
V_356 = ( V_351 * )
( ( V_232 * ) & V_349 -> V_224 [ 0 ] +
( V_223 -> V_359 * sizeof( V_351 ) ) ) ;
V_29 -> V_32 . V_33 . V_288 . V_358 . V_224 [ V_55 ] . V_360 =
F_116 ( V_356 -> V_361 ) | ( V_356 -> V_362 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_358 . V_224 [ V_55 ] . V_363 =
F_116 ( V_356 -> V_364 ) | ( V_356 -> V_365 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_358 . V_224 [ V_55 ] . V_230 =
F_116 ( V_223 -> V_231 ) ;
V_223 = ( V_354 * )
( ( V_232 * ) V_223 + sizeof( V_354 ) ) ;
}
for ( V_55 = 0 ; V_55 < V_352 -> V_353 ; V_55 ++ ) {
if ( V_55 >= V_366 )
break;
V_356 = ( V_351 * )
( ( V_232 * ) & V_349 -> V_224 [ 0 ] +
( V_355 -> V_359 * sizeof( V_351 ) ) ) ;
V_29 -> V_32 . V_33 . V_367 [ V_55 ] . V_360 =
F_116 ( V_356 -> V_361 ) | ( V_356 -> V_362 << 16 ) ;
V_29 -> V_32 . V_33 . V_367 [ V_55 ] . V_363 =
F_116 ( V_356 -> V_364 ) | ( V_356 -> V_365 << 16 ) ;
V_29 -> V_32 . V_33 . V_367 [ V_55 ] . V_368 =
V_355 -> V_369 & 0x3f ;
V_29 -> V_32 . V_33 . V_367 [ V_55 ] . V_370 =
( V_355 -> V_369 & 0xc0 ) >> 6 ;
V_355 = ( T_15 * )
( ( V_232 * ) V_355 + sizeof( T_15 ) ) ;
}
}
if ( ( F_116 ( V_344 -> V_346 ) >= V_371 ) &&
V_344 -> V_372 ) {
T_16 * V_349 = ( T_16 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_372 ) + 1 ) ;
T_17 * V_350 =
( T_17 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_372 ) + 1 +
1 + ( V_349 -> V_221 * sizeof ( V_373 ) ) ) ;
T_18 * V_223 ;
T_1 V_220 = V_350 -> V_353 *
sizeof( struct V_374 ) ;
V_29 -> V_32 . V_33 . V_288 . V_375 . V_224 =
F_115 ( V_220 , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_375 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_29 -> V_32 . V_33 . V_288 . V_375 . V_233 =
V_350 -> V_353 ;
V_223 = & V_350 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_350 -> V_353 ; V_55 ++ ) {
V_373 * V_376 = ( V_373 * )
( ( V_232 * ) & V_349 -> V_224 [ 0 ] +
( V_223 -> V_377 * sizeof( V_373 ) ) ) ;
V_29 -> V_32 . V_33 . V_288 . V_375 . V_224 [ V_55 ] . V_378 =
F_116 ( V_376 -> V_379 ) | ( V_376 -> V_380 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_375 . V_224 [ V_55 ] . V_381 =
F_116 ( V_376 -> V_382 ) | ( V_376 -> V_383 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_375 . V_224 [ V_55 ] . V_230 =
F_116 ( V_223 -> V_231 ) ;
V_223 = ( T_18 * )
( ( V_232 * ) V_223 + sizeof( T_18 ) ) ;
}
}
if ( ( F_116 ( V_344 -> V_346 ) >= V_384 ) &&
V_344 -> V_385 ) {
T_19 * V_350 =
( T_19 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_385 ) + 1 ) ;
T_20 * V_223 ;
T_1 V_220 = V_350 -> V_353 *
sizeof( struct V_222 ) ;
V_29 -> V_32 . V_33 . V_288 . V_386 . V_224 =
F_115 ( V_220 , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_386 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_29 -> V_32 . V_33 . V_288 . V_386 . V_233 =
V_350 -> V_353 ;
V_223 = & V_350 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_350 -> V_353 ; V_55 ++ ) {
V_29 -> V_32 . V_33 . V_288 . V_386 . V_224 [ V_55 ] . V_227 =
F_116 ( V_223 -> V_387 ) | ( V_223 -> V_388 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_386 . V_224 [ V_55 ] . V_230 =
F_116 ( V_223 -> V_231 ) ;
V_223 = ( T_20 * )
( ( V_232 * ) V_223 + sizeof( T_20 ) ) ;
}
}
if ( ( F_116 ( V_344 -> V_346 ) >= V_389 ) &&
V_344 -> V_390 ) {
T_21 * V_391 = ( T_21 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_390 ) ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 =
F_115 ( sizeof( struct V_393 ) , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_392 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_394 = V_391 -> V_395 ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_396 =
F_116 ( V_391 -> V_397 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_398 =
F_120 ( V_391 -> V_399 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_400 =
F_120 ( V_391 -> V_401 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_402 =
F_120 ( V_391 -> V_403 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_404 =
F_120 ( V_391 -> V_405 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_406 =
F_120 ( V_391 -> V_407 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_408 =
F_120 ( V_391 -> V_409 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_410 =
F_120 ( V_391 -> V_411 ) ;
V_29 -> V_32 . V_33 . V_288 . V_392 -> V_412 =
F_120 ( V_391 -> V_413 ) ;
}
if ( ( F_116 ( V_344 -> V_346 ) >= V_414 ) &&
V_344 -> V_415 ) {
T_22 * V_350 =
( T_22 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_415 ) + 1 ) ;
T_23 * V_223 ;
T_1 V_220 = V_350 -> V_353 *
sizeof( struct V_222 ) ;
V_29 -> V_32 . V_33 . V_288 . V_416 . V_224 =
F_115 ( V_220 , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_416 . V_224 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
V_29 -> V_32 . V_33 . V_288 . V_416 . V_233 =
V_350 -> V_353 ;
V_223 = & V_350 -> V_224 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_350 -> V_353 ; V_55 ++ ) {
V_29 -> V_32 . V_33 . V_288 . V_416 . V_224 [ V_55 ] . V_227 =
F_116 ( V_223 -> V_417 ) | ( V_223 -> V_418 << 16 ) ;
V_29 -> V_32 . V_33 . V_288 . V_416 . V_224 [ V_55 ] . V_230 =
F_116 ( V_223 -> V_231 ) ;
V_223 = ( T_23 * )
( ( V_232 * ) V_223 + sizeof( T_23 ) ) ;
}
}
if ( ( F_116 ( V_344 -> V_346 ) >= V_419 ) &&
V_344 -> V_420 ) {
V_232 V_421 = * ( V_232 * ) ( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_420 ) ) ;
T_24 * V_422 ;
V_29 -> V_32 . V_33 . V_288 . V_423 =
F_115 ( sizeof( struct V_424 ) , V_225 ) ;
if ( ! V_29 -> V_32 . V_33 . V_288 . V_423 ) {
F_123 ( V_29 ) ;
return - V_226 ;
}
if ( V_421 > 0 ) {
T_25 * V_425 = ( T_25 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_420 ) ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_426 =
F_116 ( V_425 -> V_427 ) ;
V_422 = & V_425 -> V_428 ;
} else {
T_26 * V_425 = ( T_26 * )
( V_46 -> V_241 -> V_242 + V_238 +
F_116 ( V_344 -> V_420 ) ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_426 = 255 ;
V_422 = & V_425 -> V_428 ;
}
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_429 = F_116 ( V_422 -> V_430 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_431 =
F_116 ( V_422 -> V_432 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_433 = F_116 ( V_422 -> V_434 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_435 =
F_116 ( V_422 -> V_436 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_437 =
F_116 ( V_422 -> V_438 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_439 =
F_116 ( V_422 -> V_440 ) ;
V_29 -> V_32 . V_33 . V_288 . V_423 -> V_441 =
F_116 ( V_422 -> V_442 ) ;
}
}
return 0 ;
}
void F_123 ( struct V_28 * V_29 )
{
struct V_443 * V_288 = & V_29 -> V_32 . V_33 . V_288 ;
F_122 ( V_288 -> V_289 . V_224 ) ;
F_122 ( V_288 -> V_291 . V_224 ) ;
F_122 ( V_288 -> V_293 . V_224 ) ;
F_122 ( V_288 -> V_295 . V_224 ) ;
F_122 ( V_288 -> V_334 . V_224 ) ;
F_122 ( V_288 -> V_311 . V_224 ) ;
F_122 ( V_288 -> V_392 ) ;
F_122 ( V_288 -> V_423 ) ;
F_122 ( V_288 -> V_358 . V_224 ) ;
F_122 ( V_288 -> V_375 . V_224 ) ;
F_122 ( V_288 -> V_386 . V_224 ) ;
F_122 ( V_288 -> V_416 . V_224 ) ;
}
enum V_444 F_124 ( struct V_28 * V_29 ,
T_1 V_445 ,
enum V_444 V_446 ,
enum V_444 V_447 )
{
switch ( V_446 ) {
case V_448 :
return V_448 ;
case V_449 :
return V_449 ;
case V_450 :
return V_450 ;
default:
if ( ( V_445 & V_451 ) && ( V_447 == V_450 ) )
return V_450 ;
else if ( ( V_445 & V_452 ) && ( V_447 == V_449 ) )
return V_449 ;
else
return V_448 ;
}
return V_448 ;
}
T_5 F_125 ( struct V_28 * V_29 ,
T_5 V_453 ,
T_5 V_454 )
{
switch ( V_453 ) {
case 0 :
default:
return V_454 ;
case 1 :
return 1 ;
case 2 :
return 2 ;
case 4 :
return 4 ;
case 8 :
return 8 ;
case 12 :
return 12 ;
case 16 :
return 16 ;
}
}
V_232 F_126 ( T_1 V_455 )
{
V_232 V_456 [] = { 0 , 1 , 2 , 0 , 3 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 5 , 0 , 0 , 0 , 6 } ;
if ( V_455 > 16 )
return 0 ;
return V_456 [ V_455 ] ;
}
