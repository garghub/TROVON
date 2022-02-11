static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
F_3 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static T_1 F_4 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_5 ( V_6 -> V_9 + V_7 ) ;
}
static void F_6 ( struct V_5 * V_6 , T_1 V_10 ,
T_1 V_11 , T_1 V_12 )
{
T_1 V_13 ;
switch ( V_12 ) {
default:
case V_14 :
V_13 = V_15 | V_16 ;
break;
case V_17 :
V_13 = V_18 | V_16 ;
break;
case V_19 :
V_13 = V_20 | V_16 ;
break;
case V_21 :
V_13 = V_22 | V_16 ;
break;
case V_23 :
V_13 = V_24 | V_16 ;
break;
}
F_2 ( V_6 , V_25 , V_26 ) ;
V_13 |= ( ( V_10 - 1 ) << V_27 ) &
V_28 ;
V_13 |= ( ( V_11 - 1 ) << V_29 )
& V_30 ;
F_2 ( V_6 , V_31 , V_13 ) ;
}
static bool F_7 ( struct V_32 * V_33 ,
const T_1 V_34 )
{
switch ( V_34 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
return true ;
default:
return false ;
}
}
static T_2 F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_40 ) {
struct V_41 * V_42 = & V_6 -> V_40 -> V_43 ;
struct V_44 * V_45 = V_6 -> V_40 ;
F_9 ( & V_45 -> V_46 ) ;
F_10 ( & V_42 -> V_47 ) ;
V_42 -> V_48 = V_6 -> V_48 ++ ;
F_11 ( & V_42 -> V_49 , V_50 ) ;
}
if ( F_12 ( & V_6 -> V_51 ) ) {
V_6 -> V_40 = NULL ;
} else {
V_6 -> V_40 = F_13 ( V_6 -> V_51 . V_52 ,
struct V_44 , V_46 ) ;
F_2 ( V_6 , V_53 ,
( T_1 ) V_6 -> V_40 -> V_54 -> V_55 ) ;
F_2 ( V_6 , V_56 ,
V_57 | V_58 ) ;
F_2 ( V_6 , V_59 , V_60 ) ;
}
return V_61 ;
}
static T_2 F_14 ( int V_62 , void * V_63 )
{
struct V_5 * V_6 = V_63 ;
T_1 V_64 , V_65 , V_66 ;
T_2 V_67 = V_68 ;
F_15 ( & V_6 -> V_69 ) ;
V_64 = F_4 ( V_6 , V_70 ) ;
V_65 = F_4 ( V_6 , V_71 ) ;
V_66 = V_64 & V_65 ;
if ( V_66 & V_72 ) {
F_16 ( & V_6 -> F_16 ) ;
F_2 ( V_6 , V_73 , V_72 ) ;
V_67 = V_61 ;
} else if ( V_66 & V_26 ) {
F_16 ( & V_6 -> F_16 ) ;
F_2 ( V_6 , V_73 , V_26 ) ;
V_67 = V_61 ;
} else {
if ( F_17 ( V_66 & V_74 ) )
V_67 = F_8 ( V_6 ) ;
}
F_18 ( & V_6 -> V_69 ) ;
return V_67 ;
}
static int F_19 ( struct V_5 * V_6 , int V_75 )
{
unsigned long V_76 ;
F_20 ( & V_6 -> F_16 ) ;
if ( V_75 ) {
F_2 ( V_6 , V_77 , V_72 ) ;
F_2 ( V_6 , V_25 , V_72 ) ;
} else {
F_2 ( V_6 , V_77 , V_26 ) ;
F_2 ( V_6 , V_25 , V_26 ) ;
}
V_76 = F_21 ( & V_6 -> F_16 ,
F_22 ( 500 ) ) ;
if ( V_76 == 0 )
return - V_78 ;
return 0 ;
}
static int F_23 ( struct V_79 * V_80 , const void * V_81 ,
unsigned int * V_82 , unsigned int * V_83 ,
unsigned int V_84 [] , void * V_85 [] )
{
struct V_32 * V_33 = F_24 ( V_80 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
unsigned long V_90 ;
V_90 = V_33 -> V_91 ;
if ( ! * V_82 || * V_82 > V_92 )
* V_82 = V_92 ;
if ( V_90 * * V_82 > V_93 )
* V_82 = V_93 / V_90 ;
* V_83 = 1 ;
V_84 [ 0 ] = V_90 ;
V_85 [ 0 ] = V_6 -> V_94 ;
V_6 -> V_48 = 0 ;
V_6 -> V_40 = NULL ;
F_26 ( V_33 -> V_88 , L_1 , V_95 ,
* V_82 , V_90 ) ;
return 0 ;
}
static int F_27 ( struct V_96 * V_43 )
{
struct V_41 * V_42 = F_28 ( V_43 ) ;
struct V_44 * V_45 = F_29 ( V_42 , struct V_44 , V_43 ) ;
V_45 -> V_54 = NULL ;
F_30 ( & V_45 -> V_46 ) ;
return 0 ;
}
static int F_31 ( struct V_96 * V_43 )
{
struct V_41 * V_42 = F_28 ( V_43 ) ;
struct V_32 * V_33 = F_24 ( V_43 -> V_79 ) ;
struct V_44 * V_45 = F_29 ( V_42 , struct V_44 , V_43 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
unsigned long V_90 ;
struct V_97 * V_98 ;
V_90 = V_33 -> V_91 ;
if ( F_32 ( V_43 , 0 ) < V_90 ) {
F_33 ( V_33 -> V_88 , L_2 ,
V_95 , F_32 ( V_43 , 0 ) , V_90 ) ;
return - V_99 ;
}
F_34 ( V_43 , 0 , V_90 ) ;
if ( ! V_45 -> V_54 ) {
if ( F_12 ( & V_6 -> V_100 ) ) {
F_33 ( V_33 -> V_88 , L_3 ) ;
return - V_99 ;
} else {
V_98 = F_13 ( V_6 -> V_100 . V_52 ,
struct V_97 , V_46 ) ;
F_9 ( & V_98 -> V_46 ) ;
V_98 -> V_101 -> V_102 =
F_35 ( V_43 , 0 ) ;
V_98 -> V_101 -> V_103 = 0 ;
F_1 ( V_98 -> V_101 , V_104 ) ;
V_45 -> V_54 = V_98 ;
}
}
return 0 ;
}
static void F_36 ( struct V_96 * V_43 )
{
struct V_41 * V_42 = F_28 ( V_43 ) ;
struct V_32 * V_33 = F_24 ( V_43 -> V_79 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
struct V_44 * V_45 = F_29 ( V_42 , struct V_44 , V_43 ) ;
if ( V_45 -> V_54 )
F_37 ( & V_45 -> V_54 -> V_46 , & V_6 -> V_100 ) ;
}
static void F_38 ( struct V_5 * V_6 , struct V_44 * V_105 )
{
T_1 V_3 , V_106 ;
V_106 = F_4 ( V_6 , V_107 ) ;
F_2 ( V_6 , V_77 ,
V_74 | V_108 ) ;
if ( F_4 ( V_6 , V_70 ) & V_109 ) {
F_33 ( V_6 -> V_110 . V_33 -> V_88 , L_4 ) ;
return;
}
F_2 ( V_6 , V_53 , ( T_1 ) V_105 -> V_54 -> V_55 ) ;
F_2 ( V_6 , V_56 , V_57 | V_58 ) ;
F_2 ( V_6 , V_59 , V_60 ) ;
V_106 &= ~ V_111 ;
V_106 |= V_6 -> V_112 . V_113 | V_114 ;
V_3 = V_109 | V_115 ;
F_2 ( V_6 , V_25 , V_3 ) ;
F_2 ( V_6 , V_107 , V_106 ) ;
}
static void F_39 ( struct V_96 * V_43 )
{
struct V_41 * V_42 = F_28 ( V_43 ) ;
struct V_32 * V_33 = F_24 ( V_43 -> V_79 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
struct V_44 * V_45 = F_29 ( V_42 , struct V_44 , V_43 ) ;
unsigned long V_116 = 0 ;
F_40 ( & V_6 -> V_69 , V_116 ) ;
F_41 ( & V_45 -> V_46 , & V_6 -> V_51 ) ;
if ( V_6 -> V_40 == NULL ) {
V_6 -> V_40 = V_45 ;
if ( F_42 ( V_43 -> V_79 ) )
F_38 ( V_6 , V_45 ) ;
}
F_43 ( & V_6 -> V_69 , V_116 ) ;
}
static int F_44 ( struct V_79 * V_80 , unsigned int V_117 )
{
struct V_32 * V_33 = F_24 ( V_80 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
int V_67 ;
F_45 ( V_87 -> V_118 . V_119 ) ;
V_67 = F_19 ( V_6 , V_120 ) ;
if ( V_67 < 0 ) {
F_33 ( V_33 -> V_88 , L_5 ) ;
F_46 ( V_87 -> V_118 . V_119 ) ;
return V_67 ;
}
F_2 ( V_6 , V_73 , ( T_1 ) ~ 0UL ) ;
F_6 ( V_6 , V_33 -> V_121 , V_33 -> V_122 ,
V_33 -> V_123 -> V_12 ) ;
F_47 ( & V_6 -> V_69 ) ;
F_4 ( V_6 , V_70 ) ;
if ( V_117 )
F_38 ( V_6 , V_6 -> V_40 ) ;
F_48 ( & V_6 -> V_69 ) ;
return 0 ;
}
static void F_49 ( struct V_79 * V_80 )
{
struct V_32 * V_33 = F_24 ( V_80 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
struct V_44 * V_45 , * V_124 ;
int V_67 = 0 ;
unsigned long V_76 ;
F_47 ( & V_6 -> V_69 ) ;
V_6 -> V_40 = NULL ;
F_50 (buf, node, &isi->video_buffer_list, list) {
F_9 ( & V_45 -> V_46 ) ;
F_11 ( & V_45 -> V_43 . V_49 , V_125 ) ;
}
F_48 ( & V_6 -> V_69 ) ;
V_76 = V_126 + V_127 * V_128 ;
while ( ( F_4 ( V_6 , V_70 ) & V_109 ) &&
F_51 ( V_126 , V_76 ) )
F_52 ( 1 ) ;
if ( F_53 ( V_126 , V_76 ) )
F_33 ( V_33 -> V_88 ,
L_6 ) ;
F_2 ( V_6 , V_73 ,
V_74 | V_108 ) ;
V_67 = F_19 ( V_6 , V_129 ) ;
if ( V_67 < 0 )
F_33 ( V_33 -> V_88 , L_7 ) ;
F_46 ( V_87 -> V_118 . V_119 ) ;
}
static int F_54 ( struct V_79 * V_130 ,
struct V_32 * V_33 )
{
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
V_130 -> type = V_131 ;
V_130 -> V_132 = V_133 ;
V_130 -> V_134 = V_33 ;
V_130 -> V_135 = sizeof( struct V_44 ) ;
V_130 -> V_136 = & V_137 ;
V_130 -> V_138 = & V_139 ;
V_130 -> V_140 = V_141 ;
V_130 -> V_69 = & V_87 -> V_142 ;
return F_55 ( V_130 ) ;
}
static int F_56 ( struct V_32 * V_33 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 = F_57 ( V_33 ) ;
const struct V_147 * V_148 ;
struct V_149 * V_150 = & V_144 -> V_151 . V_150 ;
struct V_152 V_153 = {
. V_154 = V_155 ,
} ;
struct V_156 * V_157 = & V_153 . V_153 ;
int V_67 ;
if ( ! F_7 ( V_33 , V_150 -> V_158 ) )
V_150 -> V_158 = V_36 ;
V_148 = F_58 ( V_33 , V_150 -> V_158 ) ;
if ( ! V_148 ) {
F_59 ( V_33 -> V_88 , L_8 ,
V_150 -> V_158 ) ;
return - V_99 ;
}
F_26 ( V_33 -> V_88 , L_9 ,
V_150 -> V_10 , V_150 -> V_11 ) ;
V_157 -> V_10 = V_150 -> V_10 ;
V_157 -> V_11 = V_150 -> V_11 ;
V_157 -> V_159 = V_150 -> V_159 ;
V_157 -> V_160 = V_150 -> V_160 ;
V_157 -> V_12 = V_148 -> V_12 ;
V_67 = F_60 ( V_146 , V_161 , V_162 , NULL , & V_153 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_157 -> V_12 != V_148 -> V_12 )
return - V_99 ;
V_150 -> V_10 = V_157 -> V_10 ;
V_150 -> V_11 = V_157 -> V_11 ;
V_150 -> V_159 = V_157 -> V_159 ;
V_150 -> V_160 = V_157 -> V_160 ;
V_33 -> V_123 = V_148 ;
F_26 ( V_33 -> V_88 , L_10 ,
V_150 -> V_10 , V_150 -> V_11 ) ;
return V_67 ;
}
static int F_61 ( struct V_32 * V_33 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 = F_57 ( V_33 ) ;
const struct V_147 * V_148 ;
struct V_149 * V_150 = & V_144 -> V_151 . V_150 ;
struct V_163 V_164 ;
struct V_152 V_153 = {
. V_154 = V_165 ,
} ;
struct V_156 * V_157 = & V_153 . V_153 ;
T_1 V_166 = V_150 -> V_158 ;
int V_67 ;
if ( ! F_7 ( V_33 , V_150 -> V_158 ) )
V_150 -> V_158 = V_36 ;
V_148 = F_58 ( V_33 , V_166 ) ;
if ( V_166 && ! V_148 ) {
F_59 ( V_33 -> V_88 , L_8 , V_166 ) ;
return - V_99 ;
}
if ( V_150 -> V_11 > V_167 )
V_150 -> V_11 = V_167 ;
if ( V_150 -> V_10 > V_168 )
V_150 -> V_10 = V_168 ;
V_157 -> V_10 = V_150 -> V_10 ;
V_157 -> V_11 = V_150 -> V_11 ;
V_157 -> V_159 = V_150 -> V_159 ;
V_157 -> V_160 = V_150 -> V_160 ;
V_157 -> V_12 = V_148 -> V_12 ;
V_67 = F_60 ( V_146 , V_161 , V_162 , & V_164 , & V_153 ) ;
if ( V_67 < 0 )
return V_67 ;
V_150 -> V_10 = V_157 -> V_10 ;
V_150 -> V_11 = V_157 -> V_11 ;
V_150 -> V_160 = V_157 -> V_160 ;
switch ( V_157 -> V_159 ) {
case V_169 :
V_150 -> V_159 = V_170 ;
break;
case V_170 :
break;
default:
F_33 ( V_33 -> V_88 , L_11 ,
V_157 -> V_159 ) ;
V_67 = - V_99 ;
}
return V_67 ;
}
static bool F_62 ( const struct V_171 * V_151 )
{
return V_151 -> V_172 == V_173 ||
( V_151 -> V_174 == 8 &&
V_151 -> V_172 == V_175 ) ||
( V_151 -> V_174 > 8 &&
V_151 -> V_172 == V_176 ) ;
}
static int F_63 ( struct V_32 * V_33 ,
unsigned char V_177 )
{
struct V_145 * V_146 = F_57 ( V_33 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
struct V_178 V_179 = { . type = V_180 ,} ;
unsigned long V_181 ;
int V_67 ;
V_67 = F_60 ( V_146 , V_182 , V_183 , & V_179 ) ;
if ( ! V_67 ) {
V_181 = F_64 ( & V_179 ,
V_184 ) ;
if ( ! V_181 ) {
F_59 ( V_33 -> V_88 ,
L_12 ,
V_179 . V_116 , V_184 ) ;
return - V_99 ;
}
} else if ( V_67 != - V_185 ) {
return V_67 ;
}
if ( ( 1 << ( V_177 - 1 ) ) & V_6 -> V_186 )
return 0 ;
return - V_99 ;
}
static int F_65 ( struct V_32 * V_33 ,
unsigned int V_187 ,
struct V_147 * V_148 )
{
struct V_145 * V_146 = F_57 ( V_33 ) ;
int V_188 = 0 , V_67 ;
struct V_189 V_12 = {
. V_154 = V_155 ,
. V_190 = V_187 ,
} ;
const struct V_171 * V_151 ;
V_67 = F_60 ( V_146 , V_161 , V_191 , NULL , & V_12 ) ;
if ( V_67 < 0 )
return 0 ;
V_151 = F_66 ( V_12 . V_12 ) ;
if ( ! V_151 ) {
F_33 ( V_33 -> V_88 ,
L_13 , V_187 , V_12 . V_12 ) ;
return 0 ;
}
V_67 = F_63 ( V_33 , V_151 -> V_174 ) ;
if ( V_67 < 0 ) {
F_33 ( V_33 -> V_88 ,
L_14 ) ;
return 0 ;
}
switch ( V_12 . V_12 ) {
case V_19 :
case V_17 :
case V_23 :
case V_21 :
V_188 ++ ;
if ( V_148 ) {
V_148 -> V_192 = & V_193 [ 0 ] ;
V_148 -> V_12 = V_12 . V_12 ;
V_148 ++ ;
F_26 ( V_33 -> V_88 , L_15 ,
V_193 [ 0 ] . V_194 , V_12 . V_12 ) ;
}
break;
default:
if ( ! F_62 ( V_151 ) )
return 0 ;
if ( V_148 )
F_26 ( V_33 -> V_88 ,
L_16 ,
V_151 -> V_194 ) ;
}
V_188 ++ ;
if ( V_148 ) {
V_148 -> V_192 = V_151 ;
V_148 -> V_12 = V_12 . V_12 ;
V_148 ++ ;
}
return V_188 ;
}
static int F_67 ( struct V_32 * V_33 )
{
F_26 ( V_33 -> V_88 , L_17 ,
V_33 -> V_195 ) ;
return 0 ;
}
static void F_68 ( struct V_32 * V_33 )
{
F_26 ( V_33 -> V_88 , L_18 ,
V_33 -> V_195 ) ;
}
static unsigned int F_69 ( struct V_196 * V_196 , T_3 * V_197 )
{
struct V_32 * V_33 = V_196 -> V_198 ;
return F_70 ( & V_33 -> V_199 , V_196 , V_197 ) ;
}
static int F_71 ( struct V_86 * V_87 ,
struct V_200 * V_201 )
{
strcpy ( V_201 -> V_202 , L_19 ) ;
strcpy ( V_201 -> V_203 , L_20 ) ;
V_201 -> V_204 = V_205 | V_206 ;
V_201 -> V_207 = V_201 -> V_204 | V_208 ;
return 0 ;
}
static int F_72 ( struct V_32 * V_33 )
{
struct V_145 * V_146 = F_57 ( V_33 ) ;
struct V_86 * V_87 = F_25 ( V_33 -> V_88 ) ;
struct V_5 * V_6 = V_87 -> V_89 ;
struct V_178 V_179 = { . type = V_180 ,} ;
unsigned long V_181 ;
int V_67 ;
T_1 V_106 = 0 ;
V_67 = F_60 ( V_146 , V_182 , V_183 , & V_179 ) ;
if ( ! V_67 ) {
V_181 = F_64 ( & V_179 ,
V_184 ) ;
if ( ! V_181 ) {
F_59 ( V_33 -> V_88 ,
L_12 ,
V_179 . V_116 , V_184 ) ;
return - V_99 ;
}
} else if ( V_67 != - V_185 ) {
return V_67 ;
} else {
V_181 = V_184 ;
}
F_26 ( V_33 -> V_88 , L_21 ,
V_179 . V_116 , V_184 , V_181 ) ;
if ( ( V_181 & V_209 ) &&
( V_181 & V_210 ) ) {
if ( V_6 -> V_112 . V_211 )
V_181 &= ~ V_209 ;
else
V_181 &= ~ V_210 ;
}
if ( ( V_181 & V_212 ) &&
( V_181 & V_213 ) ) {
if ( V_6 -> V_112 . V_214 )
V_181 &= ~ V_212 ;
else
V_181 &= ~ V_213 ;
}
if ( ( V_181 & V_215 ) &&
( V_181 & V_216 ) ) {
if ( V_6 -> V_112 . V_217 )
V_181 &= ~ V_215 ;
else
V_181 &= ~ V_216 ;
}
V_179 . V_116 = V_181 ;
V_67 = F_60 ( V_146 , V_182 , V_218 , & V_179 ) ;
if ( V_67 < 0 && V_67 != - V_185 ) {
F_26 ( V_33 -> V_88 , L_22 ,
V_181 , V_67 ) ;
return V_67 ;
}
if ( V_181 & V_210 )
V_106 |= V_219 ;
if ( V_181 & V_213 )
V_106 |= V_220 ;
if ( V_181 & V_216 )
V_106 |= V_221 ;
F_26 ( V_33 -> V_88 , L_23 ,
V_181 & V_213 ? L_24 : L_25 ,
V_181 & V_210 ? L_24 : L_25 ,
V_181 & V_216 ? L_26 : L_27 ) ;
if ( V_6 -> V_112 . V_222 )
V_106 |= V_223 ;
if ( V_6 -> V_112 . V_224 )
V_106 |= V_225 ;
V_106 |= V_226 ;
F_45 ( V_87 -> V_118 . V_119 ) ;
F_2 ( V_6 , V_25 , V_26 ) ;
F_2 ( V_6 , V_107 , V_106 ) ;
F_46 ( V_87 -> V_118 . V_119 ) ;
return 0 ;
}
static int F_73 ( struct V_227 * V_228 )
{
struct V_86 * V_110 = F_25 ( & V_228 -> V_119 ) ;
struct V_5 * V_6 = F_29 ( V_110 ,
struct V_5 , V_110 ) ;
F_74 ( V_110 ) ;
F_75 ( V_6 -> V_94 ) ;
F_76 ( & V_228 -> V_119 ,
sizeof( struct V_1 ) * V_92 ,
V_6 -> V_229 ,
V_6 -> V_230 ) ;
F_77 ( & V_228 -> V_119 ) ;
return 0 ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_227 * V_228 )
{
struct V_231 * V_232 = V_228 -> V_119 . V_233 ;
struct V_234 V_235 ;
int V_236 ;
V_6 -> V_112 . V_224 = 1 ;
V_6 -> V_112 . V_113 = V_237 ;
V_232 = F_79 ( V_232 , NULL ) ;
if ( ! V_232 ) {
F_33 ( & V_228 -> V_119 , L_28 ) ;
return - V_99 ;
}
V_236 = F_80 ( V_232 , & V_235 ) ;
F_81 ( V_232 ) ;
if ( V_236 ) {
F_33 ( & V_228 -> V_119 , L_29 ) ;
return V_236 ;
}
switch ( V_235 . V_238 . V_239 . V_240 ) {
case 8 :
V_6 -> V_112 . V_241 = V_242 ;
break;
case 10 :
V_6 -> V_112 . V_241 =
V_242 | V_243 ;
break;
default:
F_33 ( & V_228 -> V_119 , L_30 ,
V_235 . V_238 . V_239 . V_240 ) ;
return - V_99 ;
}
if ( V_235 . V_238 . V_239 . V_116 & V_210 )
V_6 -> V_112 . V_211 = true ;
if ( V_235 . V_238 . V_239 . V_116 & V_213 )
V_6 -> V_112 . V_214 = true ;
if ( V_235 . V_238 . V_239 . V_116 & V_216 )
V_6 -> V_112 . V_217 = true ;
if ( V_235 . V_244 == V_245 )
V_6 -> V_112 . V_222 = true ;
return 0 ;
}
static int F_82 ( struct V_227 * V_228 )
{
unsigned int V_62 ;
struct V_5 * V_6 ;
struct V_246 * V_9 ;
int V_67 , V_247 ;
struct V_86 * V_110 ;
V_6 = F_83 ( & V_228 -> V_119 , sizeof( struct V_5 ) , V_248 ) ;
if ( ! V_6 ) {
F_33 ( & V_228 -> V_119 , L_31 ) ;
return - V_249 ;
}
V_6 -> V_250 = F_84 ( & V_228 -> V_119 , L_32 ) ;
if ( F_85 ( V_6 -> V_250 ) )
return F_86 ( V_6 -> V_250 ) ;
V_67 = F_78 ( V_6 , V_228 ) ;
if ( V_67 )
return V_67 ;
V_6 -> V_40 = NULL ;
F_87 ( & V_6 -> V_69 ) ;
F_30 ( & V_6 -> V_51 ) ;
F_30 ( & V_6 -> V_100 ) ;
V_6 -> V_229 = F_88 ( & V_228 -> V_119 ,
sizeof( struct V_1 ) * V_92 ,
& V_6 -> V_230 ,
V_248 ) ;
if ( ! V_6 -> V_229 ) {
F_33 ( & V_228 -> V_119 , L_33 ) ;
return - V_249 ;
}
for ( V_247 = 0 ; V_247 < V_92 ; V_247 ++ ) {
V_6 -> V_251 [ V_247 ] . V_101 = V_6 -> V_229 + V_247 ;
V_6 -> V_251 [ V_247 ] . V_55 = V_6 -> V_230 +
V_247 * sizeof( struct V_1 ) ;
F_37 ( & V_6 -> V_251 [ V_247 ] . V_46 , & V_6 -> V_100 ) ;
}
V_6 -> V_94 = F_89 ( & V_228 -> V_119 ) ;
if ( F_85 ( V_6 -> V_94 ) ) {
V_67 = F_86 ( V_6 -> V_94 ) ;
goto V_252;
}
V_9 = F_90 ( V_228 , V_253 , 0 ) ;
V_6 -> V_9 = F_91 ( & V_228 -> V_119 , V_9 ) ;
if ( F_85 ( V_6 -> V_9 ) ) {
V_67 = F_86 ( V_6 -> V_9 ) ;
goto V_254;
}
if ( V_6 -> V_112 . V_241 & V_242 )
V_6 -> V_186 = 1 << 7 ;
if ( V_6 -> V_112 . V_241 & V_243 )
V_6 -> V_186 |= 1 << 9 ;
V_62 = F_92 ( V_228 , 0 ) ;
if ( F_93 ( V_62 ) ) {
V_67 = V_62 ;
goto V_255;
}
V_67 = F_94 ( & V_228 -> V_119 , V_62 , F_14 , 0 , L_34 , V_6 ) ;
if ( V_67 ) {
F_33 ( & V_228 -> V_119 , L_35 , V_62 ) ;
goto V_255;
}
V_6 -> V_62 = V_62 ;
V_110 = & V_6 -> V_110 ;
V_110 -> V_256 = L_36 ;
V_110 -> V_136 = & V_257 ;
V_110 -> V_89 = V_6 ;
V_110 -> V_118 . V_119 = & V_228 -> V_119 ;
V_110 -> V_258 = V_228 -> V_259 ;
F_95 ( & V_228 -> V_119 , true ) ;
F_96 ( & V_228 -> V_119 ) ;
V_67 = F_97 ( V_110 ) ;
if ( V_67 ) {
F_33 ( & V_228 -> V_119 , L_37 ) ;
goto V_260;
}
return 0 ;
V_260:
F_77 ( & V_228 -> V_119 ) ;
V_255:
V_254:
F_75 ( V_6 -> V_94 ) ;
V_252:
F_76 ( & V_228 -> V_119 ,
sizeof( struct V_1 ) * V_92 ,
V_6 -> V_229 ,
V_6 -> V_230 ) ;
return V_67 ;
}
static int F_98 ( struct V_261 * V_119 )
{
struct V_86 * V_110 = F_25 ( V_119 ) ;
struct V_5 * V_6 = F_29 ( V_110 ,
struct V_5 , V_110 ) ;
F_99 ( V_6 -> V_250 ) ;
return 0 ;
}
static int F_100 ( struct V_261 * V_119 )
{
struct V_86 * V_110 = F_25 ( V_119 ) ;
struct V_5 * V_6 = F_29 ( V_110 ,
struct V_5 , V_110 ) ;
return F_101 ( V_6 -> V_250 ) ;
}
