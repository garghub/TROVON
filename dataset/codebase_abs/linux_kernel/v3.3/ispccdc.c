static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 ) ;
F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_10 ) ;
F_4 ( V_4 , V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_4 ( V_4 , V_13 ) ;
F_4 ( V_4 , V_14 ) ;
F_4 ( V_4 , V_15 ) ;
F_4 ( V_4 , V_16 ) ;
F_4 ( V_4 , V_17 ) ;
F_4 ( V_4 , V_18 ) ;
F_4 ( V_4 , V_19 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , V_21 ) ;
F_4 ( V_4 , V_22 ) ;
F_4 ( V_4 , V_23 ) ;
F_4 ( V_4 , V_24 ) ;
F_4 ( V_4 , V_25 ) ;
F_4 ( V_4 , V_26 ) ;
F_4 ( V_4 , V_27 ) ;
F_4 ( V_4 , V_28 ) ;
F_4 ( V_4 , V_29 ) ;
F_4 ( V_4 , V_30 ) ;
F_4 ( V_4 , V_31 ) ;
F_4 ( V_4 , V_32 ) ;
F_4 ( V_4 , V_33 ) ;
F_4 ( V_4 , V_34 ) ;
F_4 ( V_4 , V_35 ) ;
F_4 ( V_4 , V_36 ) ;
F_4 ( V_4 , V_37 ) ;
F_4 ( V_4 , V_38 ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 , V_39 , V_40 ) &
V_41 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_44 * V_45 ;
unsigned int V_46 , V_47 ;
unsigned int V_48 , V_49 ;
unsigned int V_50 , V_51 , V_52 ;
unsigned int V_53 , V_54 ;
V_48 = V_43 -> V_55 ;
V_49 = V_43 -> V_56 ;
if ( ( V_48 < 2 ) || ( V_48 > 6 ) ||
( V_49 < 2 ) || ( V_49 > 6 ) ) {
F_3 ( V_4 -> V_5 , L_3 ) ;
return - V_57 ;
}
if ( V_43 -> V_58 & 3 ) {
F_3 ( V_4 -> V_5 , L_4
L_5 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_59 & 1 ) || ( V_43 -> V_60 & 1 ) ) {
F_3 ( V_4 -> V_5 , L_6 ) ;
return - V_57 ;
}
V_45 = F_8 ( V_2 , NULL , V_61 ,
V_62 ) ;
V_53 = V_45 -> V_63 ;
V_54 = V_45 -> V_64 ;
V_46 = 1 << V_48 ;
V_50 = ( ( V_53 + V_43 -> V_59 + V_46 - 1 )
>> V_48 ) + 1 ;
V_47 = 1 << V_49 ;
V_51 = ( ( V_54 + V_43 -> V_60 + V_47 - 1 )
>> V_49 ) + 1 ;
V_52 = 4 * V_50 * V_51 ;
if ( V_52 > V_43 -> V_65 ) {
F_3 ( V_4 -> V_5 , L_7 ) ;
return - V_57 ;
}
if ( V_43 -> V_58 < ( V_50 * 4 ) ) {
F_3 ( V_4 -> V_5 , L_8 ) ;
return - V_57 ;
}
if ( ( V_43 -> V_65 / V_43 -> V_58 ) < V_51 ) {
F_3 ( V_4 -> V_5 , L_9 ) ;
return - V_57 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_66 )
{
F_10 ( F_2 ( V_2 ) , V_66 ,
V_39 , V_67 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_42 * V_68 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_69 ;
F_10 ( V_4 , V_68 -> V_58 , V_39 ,
V_70 ) ;
V_69 = 0 ;
V_69 |= V_68 -> V_56 << V_71 ;
V_69 |= V_68 -> V_55 << V_72 ;
V_69 |= V_68 -> V_73 << V_74 ;
F_10 ( V_4 , V_69 , V_39 , V_75 ) ;
V_69 = 0 ;
V_69 &= ~ V_76 ;
V_69 |= V_68 -> V_59 << V_77 ;
V_69 &= ~ V_78 ;
V_69 |= V_68 -> V_60 << V_79 ;
F_10 ( V_4 , V_69 , V_39 ,
V_80 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_81 ;
F_10 ( V_4 , V_82 ,
V_83 , V_84 ) ;
for ( V_81 = 0 ; V_81 < 1000 ; V_81 ++ ) {
if ( F_6 ( V_4 , V_83 , V_84 ) &
V_82 ) {
F_10 ( V_4 , V_82 ,
V_83 , V_84 ) ;
return 0 ;
}
F_13 () ;
F_14 ( 1 ) ;
}
return - V_85 ;
}
static int F_15 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_44 * V_45 =
F_8 ( V_2 , NULL , V_61 ,
V_62 ) ;
if ( ( V_45 -> V_87 != V_88 ) &&
( V_45 -> V_87 != V_89 ) &&
( V_45 -> V_87 != V_90 ) &&
( V_45 -> V_87 != V_91 ) )
return - V_57 ;
if ( V_86 )
F_16 ( V_4 , V_92 ) ;
F_17 ( V_4 , V_39 , V_75 ,
V_93 , V_86 ? V_93 : 0 ) ;
if ( V_86 ) {
if ( F_12 ( V_2 ) < 0 ) {
F_18 ( V_4 , V_39 ,
V_75 , V_93 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_19 ( F_20 ( V_2 ) , L_10 ) ;
return - V_85 ;
}
V_2 -> V_94 . V_95 = V_97 ;
} else {
V_2 -> V_94 . V_95 = V_98 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 , V_39 , V_75 ) &
V_99 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
if ( ! V_101 -> V_86 )
return - V_57 ;
if ( F_7 ( V_2 , & V_101 -> V_102 ) < 0 ) {
F_3 ( F_20 ( V_2 ) , L_11 ) ;
return - V_57 ;
}
if ( F_21 ( V_2 ) )
return - V_103 ;
F_11 ( V_2 , & V_101 -> V_102 ) ;
F_9 ( V_2 , V_101 -> V_104 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 , V_39 , V_75 ,
V_93 ) ;
V_2 -> V_94 . V_95 = V_96 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_101 == NULL )
return;
if ( V_101 -> V_105 )
F_25 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ;
if ( V_101 -> V_104 )
F_26 ( V_4 -> V_110 , V_4 -> V_5 , V_101 -> V_104 ) ;
F_27 ( V_101 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_100 * V_101 , * V_113 ;
unsigned long V_114 ;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
F_30 (req, n, queue, list) {
F_31 ( & V_101 -> V_116 ) ;
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
F_24 ( V_2 , V_101 ) ;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
}
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
}
static void F_33 ( struct V_117 * V_118 )
{
struct V_1 * V_2 ;
struct V_119 * V_94 ;
V_94 = F_34 ( V_118 , struct V_119 , V_120 ) ;
V_2 = F_34 ( V_94 , struct V_1 , V_94 ) ;
F_28 ( V_2 , & V_94 -> V_121 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_122 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
unsigned long V_114 ;
void * V_104 ;
T_2 V_123 ;
int V_124 ;
V_123 = V_102 -> V_123 &
( V_125 | V_126 ) ;
if ( ! V_123 )
return 0 ;
if ( V_123 != ( V_125 | V_126 ) ) {
F_3 ( F_20 ( V_2 ) , L_12
L_13 , V_127 ) ;
return - V_57 ;
}
V_101 = F_36 ( sizeof( * V_101 ) , V_128 ) ;
if ( V_101 == NULL )
return - V_129 ;
if ( V_102 -> V_130 & V_125 ) {
if ( F_37 ( & V_101 -> V_102 , V_102 -> V_43 ,
sizeof( V_101 -> V_102 ) ) ) {
V_124 = - V_131 ;
goto V_132;
}
V_101 -> V_86 = 1 ;
V_101 -> V_104 = F_38 ( V_4 -> V_110 , V_4 -> V_5 , 0 ,
V_101 -> V_102 . V_65 , V_133 ) ;
if ( F_39 ( V_101 -> V_104 ) ) {
V_101 -> V_104 = 0 ;
V_124 = - V_129 ;
goto V_132;
}
V_101 -> V_105 = F_40 ( V_4 -> V_5 , V_101 -> V_104 ) ;
if ( V_101 -> V_105 == NULL ) {
V_124 = - V_129 ;
goto V_132;
}
if ( ! F_41 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ) {
V_124 = - V_129 ;
V_101 -> V_105 = NULL ;
goto V_132;
}
F_42 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ;
V_104 = F_43 ( V_4 -> V_5 , V_101 -> V_104 ) ;
if ( F_37 ( V_104 , V_102 -> V_94 , V_101 -> V_102 . V_65 ) ) {
V_124 = - V_131 ;
goto V_132;
}
F_44 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ;
}
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
if ( V_2 -> V_94 . V_134 ) {
F_45 ( & V_2 -> V_94 . V_134 -> V_116 , & V_2 -> V_94 . V_121 ) ;
F_46 ( & V_2 -> V_94 . V_120 ) ;
}
V_2 -> V_94 . V_134 = V_101 ;
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
V_124 = 0 ;
V_132:
if ( V_124 < 0 )
F_24 ( V_2 , V_101 ) ;
return V_124 ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
if ( V_2 -> V_94 . V_135 ) {
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
return 1 ;
}
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_119 * V_94 = & V_2 -> V_94 ;
if ( V_94 -> V_95 != V_96 )
return - V_57 ;
if ( V_94 -> V_135 ) {
F_45 ( & V_94 -> V_135 -> V_116 , & V_94 -> V_121 ) ;
V_94 -> V_135 = NULL ;
}
if ( F_22 ( V_2 , V_94 -> V_134 ) < 0 ) {
F_49 ( F_2 ( V_2 ) ,
V_92 ) ;
F_45 ( & V_94 -> V_134 -> V_116 , & V_94 -> V_121 ) ;
V_94 -> V_134 = NULL ;
goto V_132;
}
V_94 -> V_135 = V_94 -> V_134 ;
V_94 -> V_134 = NULL ;
F_15 ( V_2 , 1 ) ;
V_132:
if ( ! F_50 ( & V_94 -> V_121 ) )
F_46 ( & V_94 -> V_120 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_136 ;
if ( V_2 -> V_137 ) {
V_136 = V_2 -> V_136 . V_138 << V_139 ;
V_136 |= V_2 -> V_136 . V_140 << V_141 ;
V_136 |= V_2 -> V_136 . V_142 << V_143 ;
V_136 |= V_2 -> V_136 . V_144 << V_145 ;
F_10 ( V_4 , V_136 , V_39 , V_146 ) ;
} else {
F_10 ( V_4 , V_2 -> V_136 . V_147 ,
V_39 , V_148 ) ;
}
F_17 ( V_4 , V_39 , V_146 ,
V_149 ,
V_2 -> V_137 ? V_149 : 0 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 , V_39 , V_150 , V_151 ) ;
if ( ! V_2 -> V_152 )
return;
F_10 ( V_4 , V_2 -> V_153 . V_154 , V_39 ,
V_155 ) ;
F_10 ( V_4 , ( V_2 -> V_153 . V_156 << V_157 ) ,
V_39 , V_150 ) ;
F_10 ( V_4 , ( V_2 -> V_153 . V_156 << V_157 ) |
V_151 , V_39 , V_150 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_158 ;
V_158 = V_2 -> V_158 . V_159 << V_160 ;
V_158 |= V_2 -> V_158 . V_161 << V_162 ;
V_158 |= V_2 -> V_158 . V_163 << V_164 ;
V_158 |= V_2 -> V_158 . V_165 << V_166 ;
F_10 ( V_4 , V_158 , V_39 , V_167 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_168 ,
V_169 ,
V_2 -> V_170 ? V_169 : 0 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_171 = 0 ;
switch ( V_2 -> V_172 . V_173 ) {
case 8 :
return;
case 10 :
V_171 = V_174 ;
break;
case 11 :
V_171 = V_175 ;
break;
case 12 :
V_171 = V_176 ;
break;
case 13 :
V_171 = V_177 ;
break;
}
if ( V_2 -> V_171 )
V_171 |= V_178 ;
F_10 ( V_4 , V_171 , V_39 , V_179 ) ;
}
static void F_56 ( struct V_1 * V_2 , T_1 V_180 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_180 , V_39 , V_181 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_122 * V_182 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_114 ;
F_29 ( & V_2 -> V_183 , V_114 ) ;
V_2 -> V_184 = 1 ;
F_32 ( & V_2 -> V_183 , V_114 ) ;
if ( V_185 & V_182 -> V_123 ) {
V_2 -> V_171 = ! ! ( V_185 & V_182 -> V_130 ) ;
V_2 -> V_123 |= V_185 ;
}
if ( V_186 & V_182 -> V_123 ) {
V_2 -> V_170 = ! ! ( V_186 & V_182 -> V_130 ) ;
V_2 -> V_123 |= V_186 ;
}
if ( V_187 & V_182 -> V_123 ) {
if ( F_37 ( & V_2 -> V_136 , V_182 -> V_188 ,
sizeof( V_2 -> V_136 ) ) ) {
V_2 -> V_184 = 0 ;
return - V_131 ;
}
V_2 -> V_137 = ! ! ( V_187 & V_182 -> V_130 ) ;
V_2 -> V_123 |= V_187 ;
}
if ( V_189 & V_182 -> V_123 ) {
if ( F_37 ( & V_2 -> V_158 , V_182 -> V_158 ,
sizeof( V_2 -> V_158 ) ) ) {
V_2 -> V_184 = 0 ;
return - V_131 ;
}
V_2 -> V_123 |= V_189 ;
}
V_2 -> V_184 = 0 ;
if ( V_190 & V_182 -> V_123 ) {
T_1 V_191 = 0 ;
T_1 V_192 ;
T_1 V_65 ;
if ( V_2 -> V_95 != V_193 )
return - V_103 ;
V_2 -> V_152 = ! ! ( V_190 & V_182 -> V_130 ) ;
if ( V_2 -> V_152 ) {
if ( F_37 ( & V_2 -> V_153 , V_182 -> V_153 ,
sizeof( V_2 -> V_153 ) ) )
return - V_131 ;
V_65 = V_2 -> V_153 . V_156 * 4 ;
V_192 = F_38 ( V_4 -> V_110 , V_4 -> V_5 ,
0 , V_65 , V_133 ) ;
if ( F_39 ( V_192 ) )
return - V_129 ;
if ( F_37 ( F_43 ( V_4 -> V_5 , V_192 ) ,
( V_194 void V_195 * )
V_2 -> V_153 . V_154 , V_65 ) ) {
F_26 ( V_4 -> V_110 , V_4 -> V_5 ,
V_192 ) ;
return - V_131 ;
}
V_191 = V_2 -> V_153 . V_154 ;
V_2 -> V_153 . V_154 = V_192 ;
}
F_52 ( V_2 ) ;
if ( V_191 != 0 )
F_26 ( V_4 -> V_110 , V_4 -> V_5 , V_191 ) ;
}
return F_35 ( V_2 , V_182 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_123 & V_185 ) {
F_55 ( V_2 ) ;
V_2 -> V_123 &= ~ V_185 ;
}
if ( V_2 -> V_123 & V_186 ) {
F_54 ( V_2 ) ;
V_2 -> V_123 &= ~ V_186 ;
}
if ( V_2 -> V_123 & V_187 ) {
F_51 ( V_2 ) ;
V_2 -> V_123 &= ~ V_187 ;
}
if ( V_2 -> V_123 & V_189 ) {
F_53 ( V_2 ) ;
V_2 -> V_123 &= ~ V_189 ;
}
}
void F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_196 ;
F_60 ( V_4 , V_39 , V_197 , V_198 ) ;
V_2 -> V_123 = V_185 | V_186
| V_187 | V_189 ;
F_58 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_62 ( & V_2 -> V_201 . V_202 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_203 = V_200 -> V_203 ;
unsigned int V_204 = V_4 -> V_205 == V_206 ? 64 : 8 ;
unsigned int div = 0 ;
T_1 V_207 ;
V_207 = F_6 ( V_4 , V_39 , V_208 )
& ~ ( V_209 | V_210 ) ;
switch ( V_2 -> V_172 . V_173 ) {
case 8 :
case 10 :
V_207 |= V_211 ;
break;
case 11 :
V_207 |= V_212 ;
break;
case 12 :
V_207 |= V_213 ;
break;
case 13 :
V_207 |= V_214 ;
break;
} ;
if ( V_200 -> V_215 )
div = F_63 ( V_203 , V_200 -> V_216 ) ;
else if ( V_2 -> V_217 . V_218 )
div = V_203 / V_2 -> V_217 . V_218 ;
div = V_136 ( div , 2U , V_204 ) ;
V_207 |= ( div - 2 ) << V_219 ;
F_10 ( V_4 , V_207 , V_39 , V_208 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_3 V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_208 ,
V_220 , V_86 ? V_220 : 0 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
T_1 V_58 , T_3 V_221 , T_3 V_222 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_58 & 0xffff ,
V_39 , V_223 ) ;
F_18 ( V_4 , V_39 , V_224 ,
V_225 ) ;
F_18 ( V_4 , V_39 , V_224 ,
V_226 ) ;
switch ( V_221 ) {
case V_227 :
F_60 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_228 ) ;
break;
case V_229 :
F_60 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_230 ) ;
break;
case V_231 :
F_60 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_232 ) ;
break;
case V_233 :
F_60 ( V_4 , V_39 , V_224 ,
( V_222 & 0x7 ) << V_234 ) ;
break;
default:
break;
}
}
static void F_66 ( struct V_1 * V_2 , T_1 V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_66 , V_39 , V_235 ) ;
}
void F_67 ( struct V_1 * V_2 ,
unsigned int * V_216 )
{
struct V_199 * V_200 = F_62 ( & V_2 -> V_201 . V_202 ) ;
unsigned int V_236 ;
if ( V_200 == NULL )
return;
if ( V_2 -> V_215 == V_237 )
V_236 = V_200 -> V_203 / 2 * 9 / 10 ;
else
V_236 = V_200 -> V_203 / 2 ;
* V_216 = F_68 ( * V_216 , V_236 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_238 * V_172 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_239 = F_6 ( V_4 , V_39 ,
V_168 ) ;
V_239 |= V_240 ;
if ( V_172 -> V_241 )
V_239 |= V_242 ;
else
V_239 &= ~ V_242 ;
V_239 &= ~ V_243 ;
switch ( V_172 -> V_173 ) {
case 8 :
V_239 |= V_244 ;
break;
case 10 :
V_239 |= V_245 ;
break;
case 11 :
V_239 |= V_246 ;
break;
case 12 :
V_239 |= V_247 ;
break;
} ;
if ( V_172 -> V_248 )
V_239 |= V_249 ;
else
V_239 &= ~ V_249 ;
if ( V_172 -> V_250 )
V_239 |= V_251 ;
else
V_239 &= ~ V_251 ;
if ( V_172 -> V_252 )
V_239 |= V_253 ;
else
V_239 &= ~ V_253 ;
if ( V_172 -> V_254 )
V_239 |= V_255 ;
else
V_239 &= ~ V_255 ;
if ( V_172 -> V_256 )
V_239 |= V_257 ;
else
V_239 &= ~ V_257 ;
if ( V_172 -> V_258 ) {
V_239 |= V_259 | V_260 ;
F_10 ( V_4 ,
V_172 -> V_261 << V_262
| V_172 -> V_263 << V_264 ,
V_39 ,
V_265 ) ;
F_10 ( V_4 ,
V_172 -> V_266 << V_267
| V_172 -> V_268 << V_269 ,
V_39 ,
V_270 ) ;
} else
V_239 &= ~ ( V_259 |
V_260 ) ;
F_10 ( V_4 , V_239 , V_39 , V_168 ) ;
if ( ! V_172 -> V_271 )
F_18 ( V_4 , V_39 , V_272 ,
V_273 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_274 * V_275 = NULL ;
struct V_276 * V_277 ;
struct V_44 * V_45 ;
const struct V_278 * V_279 ;
struct V_280 V_281 ;
unsigned int V_282 ;
unsigned int V_283 = 0 ;
struct V_284 * V_285 ;
unsigned long V_114 ;
unsigned int V_286 ;
T_1 V_239 ;
T_1 V_287 ;
V_285 = F_71 ( & V_2 -> V_288 [ V_61 ] ) ;
V_277 = F_72 ( V_285 -> V_202 ) ;
if ( V_2 -> V_215 == V_237 )
V_275 = & ( (struct V_289 * ) V_277 -> V_290 )
-> V_291 . V_292 ;
V_281 . V_285 = V_285 -> V_293 ;
V_281 . V_294 = V_62 ;
if ( ! F_73 ( V_277 , V_285 , V_295 , NULL , & V_281 ) ) {
V_279 = F_74 ( V_281 . V_45 . V_87 ) ;
V_283 = V_279 -> V_296 ;
}
V_279 = F_74
( V_4 -> V_196 . V_297 [ V_61 ] . V_87 ) ;
V_282 = V_279 -> V_296 ;
V_286 = V_283 - V_282 ;
F_75 ( V_4 , V_2 -> V_215 , V_275 , V_286 ) ;
V_2 -> V_172 . V_173 = V_282 ;
V_2 -> V_172 . V_254 = V_275 ? V_275 -> V_298 : 0 ;
V_2 -> V_172 . V_256 = V_275 ? V_275 -> V_299 : 0 ;
F_69 ( V_2 , & V_2 -> V_172 ) ;
V_45 = & V_2 -> V_297 [ V_61 ] ;
V_239 = F_6 ( V_4 , V_39 , V_168 ) ;
V_239 &= ~ V_300 ;
if ( V_2 -> V_301 & V_302 )
V_239 |= V_303 ;
else
V_239 &= ~ V_303 ;
if ( V_2 -> V_301 & V_304 )
V_239 |= V_305 ;
else
V_239 &= ~ V_305 ;
if ( F_74 ( V_45 -> V_87 ) -> V_296 <= 8 )
V_239 |= V_306 ;
else
V_239 &= ~ V_306 ;
F_10 ( V_4 , V_239 , V_39 , V_168 ) ;
switch ( V_45 -> V_87 ) {
case V_89 :
case V_307 :
V_287 = V_308 ;
break;
case V_90 :
case V_309 :
V_287 = V_310 ;
break;
case V_91 :
case V_311 :
V_287 = V_312 ;
break;
default:
V_287 = V_313 ;
break;
}
F_56 ( V_2 , V_287 ) ;
F_10 ( V_4 , ( ( V_45 -> V_64 - 2 ) << V_314 ) |
( ( V_45 -> V_64 * 2 / 3 ) << V_315 ) ,
V_39 , V_316 ) ;
V_45 = & V_2 -> V_297 [ V_317 ] ;
F_10 ( V_4 , ( 0 << V_318 ) |
( ( V_45 -> V_63 - 1 ) << V_319 ) ,
V_39 , V_320 ) ;
F_10 ( V_4 , 0 << V_321 ,
V_39 , V_322 ) ;
F_10 ( V_4 , ( V_45 -> V_64 - 1 )
<< V_323 ,
V_39 , V_324 ) ;
F_65 ( V_2 , V_2 -> V_325 . V_326 , 0 , 0 ) ;
V_45 = & V_2 -> V_297 [ V_327 ] ;
F_10 ( V_4 , ( 0 << V_328 ) |
( V_45 -> V_63 << V_329 ) ,
V_39 , V_330 ) ;
F_10 ( V_4 , ( 0 << V_331 ) |
( ( V_45 -> V_64 + 1 ) << V_332 ) ,
V_39 , V_333 ) ;
F_10 ( V_4 , ( V_45 -> V_63 << V_334 ) |
( V_45 -> V_64 << V_335 ) ,
V_39 , V_336 ) ;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
if ( V_2 -> V_94 . V_134 == NULL )
goto V_337;
F_76 ( V_2 -> V_94 . V_135 ) ;
if ( V_2 -> V_94 . V_135 == NULL &&
F_22 ( V_2 , V_2 -> V_94 . V_134 ) == 0 ) {
V_2 -> V_94 . V_135 = V_2 -> V_94 . V_134 ;
} else {
F_45 ( & V_2 -> V_94 . V_134 -> V_116 , & V_2 -> V_94 . V_121 ) ;
F_46 ( & V_2 -> V_94 . V_120 ) ;
}
V_2 -> V_94 . V_134 = NULL ;
V_337:
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
F_58 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_40 ,
V_338 , V_86 ? V_338 : 0 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
int V_124 = 0 ;
F_29 ( & V_2 -> V_183 , V_114 ) ;
if ( V_2 -> V_95 == V_339 )
V_2 -> V_340 = V_341 ;
F_32 ( & V_2 -> V_183 , V_114 ) ;
V_124 = F_79 ( V_2 -> V_81 ,
V_2 -> V_340 == V_342 ,
F_80 ( 2000 ) ) ;
if ( V_124 == 0 ) {
V_124 = - V_85 ;
F_19 ( F_20 ( V_2 ) , L_14 ) ;
}
F_49 ( F_2 ( V_2 ) , V_92 ) ;
F_81 ( & V_2 -> V_343 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_134 ) ;
V_2 -> V_94 . V_134 = V_2 -> V_94 . V_135 ;
V_2 -> V_94 . V_135 = NULL ;
F_82 ( & V_2 -> V_94 . V_120 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_121 ) ;
F_83 ( & V_2 -> V_343 ) ;
V_2 -> V_340 = V_344 ;
return V_124 > 0 ? 0 : V_124 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 ) )
F_15 ( V_2 , 1 ) ;
F_77 ( V_2 , 1 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( V_2 )
| ( F_6 ( V_4 , V_345 , V_346 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_348 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_349 ) &
V_347 )
| ( F_6 ( V_4 , V_345 , V_350 ) &
V_347 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
unsigned int V_351 )
{
unsigned int V_81 = 0 ;
if ( V_351 == 0 )
V_351 = 10000 ;
for ( V_81 = 0 ; V_81 <= V_351 ; V_81 ++ ) {
if ( ! F_85 ( V_2 ) )
return 0 ;
F_13 () ;
F_14 ( 1 ) ;
}
return - V_103 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_352 )
{
int V_353 = 0 ;
switch ( ( V_2 -> V_340 & 3 ) | V_352 ) {
case V_341 | V_354 :
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_77 ( V_2 , 0 ) ;
V_2 -> V_340 = V_355 ;
return 1 ;
case V_355 | V_356 :
V_2 -> V_340 |= V_357 ;
if ( V_2 -> V_94 . V_95 == V_96 )
V_2 -> V_340 |= V_358 ;
V_353 = 1 ;
break;
case V_355 | V_359 :
V_2 -> V_340 |= V_358 ;
V_353 = 1 ;
break;
case V_355 | V_354 :
return 1 ;
}
if ( V_2 -> V_340 == V_342 ) {
F_88 ( & V_2 -> V_81 ) ;
V_353 = 1 ;
}
return V_353 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_62 ( & V_2 -> V_201 . V_202 ) ;
struct V_360 * V_361 = V_2 -> V_201 . V_362 ;
struct V_363 V_352 ;
memset ( & V_352 , 0 , sizeof( V_352 ) ) ;
V_352 . type = V_364 ;
V_352 . V_365 . V_366 . V_367 = F_90 ( & V_200 -> V_368 ) ;
F_91 ( V_361 , & V_352 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_369 )
{
unsigned long V_114 ;
if ( V_369 & V_370 ) {
struct V_199 * V_200 =
F_62 ( & V_2 -> V_201 . V_202 ) ;
F_23 ( V_2 ) ;
V_200 -> error = true ;
F_3 ( F_20 ( V_2 ) , L_15 ) ;
}
if ( ! ( V_369 & V_371 ) )
return;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
if ( V_2 -> V_94 . V_95 == V_98 )
V_2 -> V_94 . V_95 = V_96 ;
if ( F_87 ( V_2 , V_359 ) )
goto V_132;
if ( V_2 -> V_94 . V_95 != V_372 )
goto V_132;
V_2 -> V_94 . V_95 = V_96 ;
if ( V_369 & V_373 )
goto V_132;
if ( V_2 -> V_94 . V_134 == NULL )
goto V_132;
F_48 ( V_2 ) ;
V_132:
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_199 * V_200 = F_62 ( & V_2 -> V_201 . V_202 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_374 * V_375 ;
int V_376 = 0 ;
if ( F_50 ( & V_2 -> V_325 . V_377 ) )
goto V_132;
if ( V_2 -> V_95 == V_339 && V_2 -> V_378 ) {
V_376 = 1 ;
V_2 -> V_378 = 0 ;
goto V_132;
}
if ( F_86 ( V_2 , 1000 ) ) {
F_94 ( V_4 -> V_5 , L_16 ) ;
goto V_132;
}
V_375 = F_95 ( & V_2 -> V_325 ) ;
if ( V_375 != NULL ) {
F_66 ( V_2 , V_375 -> V_379 ) ;
V_376 = 1 ;
}
V_200 -> V_95 |= V_380 ;
if ( V_2 -> V_95 == V_381 &&
F_96 ( V_200 ) )
F_97 ( V_200 ,
V_381 ) ;
V_132:
return V_376 ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
int V_376 = 0 ;
if ( V_2 -> V_301 & V_302 )
V_376 = F_93 ( V_2 ) ;
F_29 ( & V_2 -> V_183 , V_114 ) ;
if ( F_87 ( V_2 , V_356 ) ) {
F_32 ( & V_2 -> V_183 , V_114 ) ;
return;
}
if ( ! V_2 -> V_184 )
F_58 ( V_2 ) ;
F_32 ( & V_2 -> V_183 , V_114 ) ;
if ( V_376 )
F_84 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
F_29 ( & V_2 -> V_94 . V_115 , V_114 ) ;
switch ( V_2 -> V_95 ) {
case V_381 :
V_2 -> V_340 = V_341 ;
break;
case V_339 :
if ( V_2 -> V_301 & V_302 ) {
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_77 ( V_2 , 0 ) ;
}
break;
case V_193 :
break;
}
if ( F_87 ( V_2 , V_354 ) )
goto V_132;
if ( V_2 -> V_94 . V_134 == NULL )
goto V_132;
if ( V_2 -> V_94 . V_95 == V_97 ) {
F_15 ( V_2 , 0 ) ;
V_2 -> V_94 . V_95 = V_372 ;
goto V_132;
}
if ( V_2 -> V_94 . V_95 == V_96 )
F_48 ( V_2 ) ;
V_132:
F_32 ( & V_2 -> V_94 . V_115 , V_114 ) ;
}
int F_100 ( struct V_1 * V_2 , T_1 V_369 )
{
if ( V_2 -> V_95 == V_193 )
return 0 ;
if ( V_369 & V_382 )
F_99 ( V_2 ) ;
F_92 ( V_2 , V_369 ) ;
if ( V_369 & V_383 )
F_98 ( V_2 ) ;
if ( V_369 & V_373 )
F_89 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_384 * V_385 , struct V_374 * V_375 )
{
struct V_1 * V_2 = & V_385 -> V_4 -> V_196 ;
if ( ! ( V_2 -> V_301 & V_302 ) )
return - V_386 ;
F_66 ( V_2 , V_375 -> V_379 ) ;
V_2 -> V_378 = 1 ;
return 0 ;
}
static long F_102 ( struct V_276 * V_387 , unsigned int V_388 , void * V_389 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
int V_124 ;
switch ( V_388 ) {
case V_390 :
F_81 ( & V_2 -> V_343 ) ;
V_124 = F_57 ( V_2 , V_389 ) ;
F_83 ( & V_2 -> V_343 ) ;
break;
default:
return - V_391 ;
}
return V_124 ;
}
static int F_104 ( struct V_276 * V_387 , struct V_392 * V_393 ,
struct V_394 * V_395 )
{
if ( V_395 -> type != V_364 )
return - V_57 ;
if ( V_395 -> V_396 != 0 )
return - V_57 ;
return F_105 ( V_393 , V_395 , V_397 ) ;
}
static int F_106 ( struct V_276 * V_387 , struct V_392 * V_393 ,
struct V_394 * V_395 )
{
return F_107 ( V_393 , V_395 ) ;
}
static int F_108 ( struct V_276 * V_387 , int V_86 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_124 = 0 ;
if ( V_2 -> V_95 == V_193 ) {
if ( V_86 == V_193 )
return 0 ;
F_109 ( V_4 , V_398 ) ;
F_60 ( V_4 , V_39 , V_197 ,
V_198 ) ;
F_70 ( V_2 ) ;
F_61 ( V_2 ) ;
F_64 ( V_2 , 1 ) ;
F_1 ( V_2 ) ;
}
switch ( V_86 ) {
case V_339 :
if ( V_2 -> V_301 & V_302 )
F_16 ( V_4 , V_399 ) ;
if ( V_2 -> V_378 || ! ( V_2 -> V_301 & V_302 ) )
F_84 ( V_2 ) ;
V_2 -> V_378 = 0 ;
break;
case V_381 :
if ( V_2 -> V_301 & V_302 &&
V_2 -> V_95 != V_381 )
F_16 ( V_4 , V_399 ) ;
F_84 ( V_2 ) ;
break;
case V_193 :
V_124 = F_78 ( V_2 ) ;
if ( V_2 -> V_301 & V_302 )
F_49 ( V_4 , V_399 ) ;
F_110 ( V_4 , V_398 ) ;
V_2 -> V_378 = 0 ;
break;
}
V_2 -> V_95 = V_86 ;
return V_124 ;
}
static struct V_44 *
F_8 ( struct V_1 * V_2 , struct V_400 * V_393 ,
unsigned int V_285 , enum V_401 V_294 )
{
if ( V_294 == V_402 )
return F_111 ( V_393 , V_285 ) ;
else
return & V_2 -> V_297 [ V_285 ] ;
}
static void
F_112 ( struct V_1 * V_2 , struct V_400 * V_393 ,
unsigned int V_285 , struct V_44 * V_403 ,
enum V_401 V_294 )
{
struct V_44 * V_45 ;
const struct V_278 * V_404 ;
unsigned int V_63 = V_403 -> V_63 ;
unsigned int V_64 = V_403 -> V_64 ;
unsigned int V_405 ;
switch ( V_285 ) {
case V_61 :
for ( V_405 = 0 ; V_405 < F_113 ( V_406 ) ; V_405 ++ ) {
if ( V_403 -> V_87 == V_406 [ V_405 ] )
break;
}
if ( V_405 >= F_113 ( V_406 ) )
V_403 -> V_87 = V_88 ;
V_403 -> V_63 = F_114 ( T_1 , V_63 , 32 , 4096 ) ;
V_403 -> V_64 = F_114 ( T_1 , V_64 , 32 , 4096 ) ;
break;
case V_317 :
V_45 = F_8 ( V_2 , V_393 , V_61 , V_294 ) ;
memcpy ( V_403 , V_45 , sizeof( * V_403 ) ) ;
V_403 -> V_63 = F_114 ( T_1 , V_63 , 32 , V_403 -> V_63 + 15 ) ;
V_403 -> V_63 &= ~ 15 ;
V_403 -> V_64 = F_114 ( T_1 , V_64 , 32 , V_403 -> V_64 ) ;
break;
case V_327 :
V_45 = F_8 ( V_2 , V_393 , V_61 , V_294 ) ;
memcpy ( V_403 , V_45 , sizeof( * V_403 ) ) ;
V_404 = F_74 ( V_403 -> V_87 ) ;
V_403 -> V_87 = V_404 -> V_407 ;
V_403 -> V_63 = F_114 ( T_1 , V_63 , 32 , V_403 -> V_63 ) ;
V_403 -> V_64 = F_114 ( T_1 , V_64 , 32 , V_403 -> V_64 - 1 ) ;
break;
}
V_403 -> V_408 = V_409 ;
V_403 -> V_410 = V_411 ;
}
static int F_115 ( struct V_276 * V_387 ,
struct V_400 * V_393 ,
struct V_412 * V_87 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_44 * V_45 ;
switch ( V_87 -> V_285 ) {
case V_61 :
if ( V_87 -> V_293 >= F_113 ( V_406 ) )
return - V_57 ;
V_87 -> V_87 = V_406 [ V_87 -> V_293 ] ;
break;
case V_317 :
case V_327 :
if ( V_87 -> V_293 != 0 )
return - V_57 ;
V_45 = F_8 ( V_2 , V_393 , V_61 ,
V_402 ) ;
V_87 -> V_87 = V_45 -> V_87 ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_116 ( struct V_276 * V_387 ,
struct V_400 * V_393 ,
struct V_413 * V_414 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_44 V_45 ;
if ( V_414 -> V_293 != 0 )
return - V_57 ;
V_45 . V_87 = V_414 -> V_87 ;
V_45 . V_63 = 1 ;
V_45 . V_64 = 1 ;
F_112 ( V_2 , V_393 , V_414 -> V_285 , & V_45 , V_402 ) ;
V_414 -> V_50 = V_45 . V_63 ;
V_414 -> V_51 = V_45 . V_64 ;
if ( V_45 . V_87 != V_414 -> V_87 )
return - V_57 ;
V_45 . V_87 = V_414 -> V_87 ;
V_45 . V_63 = - 1 ;
V_45 . V_64 = - 1 ;
F_112 ( V_2 , V_393 , V_414 -> V_285 , & V_45 , V_402 ) ;
V_414 -> V_415 = V_45 . V_63 ;
V_414 -> V_416 = V_45 . V_64 ;
return 0 ;
}
static int F_117 ( struct V_276 * V_387 , struct V_400 * V_393 ,
struct V_280 * V_403 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_393 , V_403 -> V_285 , V_403 -> V_294 ) ;
if ( V_45 == NULL )
return - V_57 ;
V_403 -> V_45 = * V_45 ;
return 0 ;
}
static int F_118 ( struct V_276 * V_387 , struct V_400 * V_393 ,
struct V_280 * V_403 )
{
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_393 , V_403 -> V_285 , V_403 -> V_294 ) ;
if ( V_45 == NULL )
return - V_57 ;
F_112 ( V_2 , V_393 , V_403 -> V_285 , & V_403 -> V_45 , V_403 -> V_294 ) ;
* V_45 = V_403 -> V_45 ;
if ( V_403 -> V_285 == V_61 ) {
V_45 = F_8 ( V_2 , V_393 , V_317 ,
V_403 -> V_294 ) ;
* V_45 = V_403 -> V_45 ;
F_112 ( V_2 , V_393 , V_317 , V_45 ,
V_403 -> V_294 ) ;
V_45 = F_8 ( V_2 , V_393 , V_327 ,
V_403 -> V_294 ) ;
* V_45 = V_403 -> V_45 ;
F_112 ( V_2 , V_393 , V_327 , V_45 ,
V_403 -> V_294 ) ;
}
return 0 ;
}
static int F_119 ( struct V_276 * V_387 , struct V_400 * V_393 )
{
struct V_280 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_285 = V_61 ;
V_45 . V_294 = V_393 ? V_402 : V_62 ;
V_45 . V_45 . V_87 = V_88 ;
V_45 . V_45 . V_63 = 4096 ;
V_45 . V_45 . V_64 = 4096 ;
F_118 ( V_387 , V_393 , & V_45 ) ;
return 0 ;
}
static int F_120 ( struct V_417 * V_202 ,
const struct V_284 * V_418 ,
const struct V_284 * V_419 , T_1 V_114 )
{
struct V_276 * V_387 = F_72 ( V_202 ) ;
struct V_1 * V_2 = F_103 ( V_387 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_418 -> V_293 | F_121 ( V_419 -> V_202 ) ) {
case V_61 | V_420 :
if ( ! ( V_114 & V_421 ) ) {
V_2 -> V_215 = V_422 ;
break;
}
if ( V_2 -> V_215 != V_422 )
return - V_103 ;
if ( V_419 -> V_202 == & V_4 -> V_423 . V_201 . V_202 )
V_2 -> V_215 = V_424 ;
else if ( V_419 -> V_202 == & V_4 -> V_425 . V_201 . V_202 )
V_2 -> V_215 = V_426 ;
else if ( V_419 -> V_202 == & V_4 -> V_427 . V_201 . V_202 )
V_2 -> V_215 = V_428 ;
else
V_2 -> V_215 = V_237 ;
break;
case V_327 | V_420 :
if ( V_114 & V_421 ) {
if ( V_2 -> V_301 & ~ V_429 )
return - V_103 ;
V_2 -> V_301 |= V_429 ;
} else {
V_2 -> V_301 &= ~ V_429 ;
}
break;
case V_317 | V_430 :
if ( V_114 & V_421 ) {
if ( V_2 -> V_301 & ~ V_302 )
return - V_103 ;
V_2 -> V_301 |= V_302 ;
} else {
V_2 -> V_301 &= ~ V_302 ;
}
break;
case V_317 | V_420 :
if ( V_114 & V_421 ) {
if ( V_2 -> V_301 & ~ V_304 )
return - V_103 ;
V_2 -> V_301 |= V_304 ;
} else {
V_2 -> V_301 &= ~ V_304 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
void F_122 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_201 ) ;
F_124 ( & V_2 -> V_325 ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_431 * V_361 )
{
int V_124 ;
V_124 = F_126 ( V_361 , & V_2 -> V_201 ) ;
if ( V_124 < 0 )
goto error;
V_124 = F_127 ( & V_2 -> V_325 , V_361 ) ;
if ( V_124 < 0 )
goto error;
return 0 ;
error:
F_122 ( V_2 ) ;
return V_124 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_276 * V_387 = & V_2 -> V_201 ;
struct V_284 * V_288 = V_2 -> V_288 ;
struct V_417 * V_432 = & V_387 -> V_202 ;
int V_124 ;
V_2 -> V_215 = V_422 ;
F_129 ( V_387 , & V_433 ) ;
V_387 -> V_434 = & V_435 ;
F_130 ( V_387 -> V_436 , L_17 , sizeof( V_387 -> V_436 ) ) ;
V_387 -> V_437 = 1 << 16 ;
F_131 ( V_387 , V_2 ) ;
V_387 -> V_114 |= V_438 | V_439 ;
V_288 [ V_61 ] . V_114 = V_440 ;
V_288 [ V_327 ] . V_114 = V_441 ;
V_288 [ V_317 ] . V_114 = V_441 ;
V_432 -> V_442 = & V_443 ;
V_124 = F_132 ( V_432 , V_444 , V_288 , 0 ) ;
if ( V_124 < 0 )
return V_124 ;
F_119 ( V_387 , NULL ) ;
V_2 -> V_325 . type = V_445 ;
V_2 -> V_325 . V_442 = & V_446 ;
V_2 -> V_325 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_325 . V_447 = F_133 ( 4096 * 4096 ) * 3 ;
V_2 -> V_325 . V_448 = 32 ;
V_124 = F_134 ( & V_2 -> V_325 , L_18 ) ;
if ( V_124 < 0 )
goto V_449;
V_124 = F_135 ( & V_2 -> V_201 . V_202 , V_317 ,
& V_2 -> V_325 . V_385 . V_202 , 0 , 0 ) ;
if ( V_124 < 0 )
goto V_450;
return 0 ;
V_450:
F_136 ( & V_2 -> V_325 ) ;
V_449:
F_137 ( V_432 ) ;
return V_124 ;
}
int F_138 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_196 ;
int V_124 ;
F_139 ( & V_2 -> V_183 ) ;
F_140 ( & V_2 -> V_81 ) ;
F_141 ( & V_2 -> V_343 ) ;
V_2 -> V_340 = V_344 ;
F_142 ( & V_2 -> V_94 . V_120 , F_33 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_143 ( & V_2 -> V_94 . V_121 ) ;
F_139 ( & V_2 -> V_94 . V_115 ) ;
V_2 -> V_172 . V_258 = 0 ;
V_2 -> V_172 . V_250 = 0 ;
V_2 -> V_172 . V_173 = 0 ;
V_2 -> V_172 . V_248 = 0 ;
V_2 -> V_172 . V_451 = 0 ;
V_2 -> V_172 . V_252 = 0 ;
V_2 -> V_172 . V_241 = 0 ;
V_2 -> V_136 . V_140 = 0 ;
V_2 -> V_136 . V_147 = 0 ;
V_2 -> V_217 . V_218 = 0 ;
V_2 -> V_123 = V_187 ;
F_58 ( V_2 ) ;
V_124 = F_128 ( V_2 ) ;
if ( V_124 < 0 ) {
F_144 ( & V_2 -> V_343 ) ;
return V_124 ;
}
return 0 ;
}
void F_145 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_196 ;
F_136 ( & V_2 -> V_325 ) ;
F_137 ( & V_2 -> V_201 . V_202 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_134 ) ;
F_82 ( & V_2 -> V_94 . V_120 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_121 ) ;
if ( V_2 -> V_153 . V_154 != 0 )
F_26 ( V_4 -> V_110 , V_4 -> V_5 , V_2 -> V_153 . V_154 ) ;
F_144 ( & V_2 -> V_343 ) ;
}
