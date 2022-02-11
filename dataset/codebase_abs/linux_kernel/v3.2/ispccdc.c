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
F_26 ( V_4 -> V_110 , V_4 -> V_111 , V_101 -> V_104 ) ;
F_27 ( V_101 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_100 * V_101 , * V_114 ;
unsigned long V_115 ;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
F_30 (req, n, queue, list) {
F_31 ( & V_101 -> V_117 ) ;
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
F_24 ( V_2 , V_101 ) ;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
}
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
}
static void F_33 ( struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_120 * V_94 ;
V_94 = F_34 ( V_119 , struct V_120 , V_121 ) ;
V_2 = F_34 ( V_94 , struct V_1 , V_94 ) ;
F_28 ( V_2 , & V_94 -> V_122 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_123 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
unsigned long V_115 ;
void * V_104 ;
T_2 V_124 ;
int V_125 ;
V_124 = V_102 -> V_124 &
( V_126 | V_127 ) ;
if ( ! V_124 )
return 0 ;
if ( V_124 != ( V_126 | V_127 ) ) {
F_3 ( F_20 ( V_2 ) , L_12
L_13 , V_128 ) ;
return - V_57 ;
}
V_101 = F_36 ( sizeof( * V_101 ) , V_129 ) ;
if ( V_101 == NULL )
return - V_130 ;
if ( V_102 -> V_131 & V_126 ) {
if ( F_37 ( & V_101 -> V_102 , V_102 -> V_43 ,
sizeof( V_101 -> V_102 ) ) ) {
V_125 = - V_132 ;
goto V_133;
}
V_101 -> V_86 = 1 ;
V_101 -> V_104 = F_38 ( V_4 -> V_110 , V_4 -> V_111 , 0 ,
V_101 -> V_102 . V_65 , V_134 ) ;
if ( F_39 ( V_101 -> V_104 ) ) {
V_101 -> V_104 = 0 ;
V_125 = - V_130 ;
goto V_133;
}
V_101 -> V_105 = F_40 ( V_4 -> V_111 , V_101 -> V_104 ) ;
if ( V_101 -> V_105 == NULL ) {
V_125 = - V_130 ;
goto V_133;
}
if ( ! F_41 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ) {
V_125 = - V_130 ;
V_101 -> V_105 = NULL ;
goto V_133;
}
F_42 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ;
V_104 = F_43 ( V_4 -> V_111 , V_101 -> V_104 ) ;
if ( F_37 ( V_104 , V_102 -> V_94 , V_101 -> V_102 . V_65 ) ) {
V_125 = - V_132 ;
goto V_133;
}
F_44 ( V_4 -> V_5 , V_101 -> V_105 -> V_106 -> V_107 ,
V_101 -> V_105 -> V_106 -> V_108 , V_109 ) ;
}
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
if ( V_2 -> V_94 . V_135 ) {
F_45 ( & V_2 -> V_94 . V_135 -> V_117 , & V_2 -> V_94 . V_122 ) ;
F_46 ( & V_2 -> V_94 . V_121 ) ;
}
V_2 -> V_94 . V_135 = V_101 ;
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
V_125 = 0 ;
V_133:
if ( V_125 < 0 )
F_24 ( V_2 , V_101 ) ;
return V_125 ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
if ( V_2 -> V_94 . V_136 ) {
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
return 1 ;
}
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_120 * V_94 = & V_2 -> V_94 ;
if ( V_94 -> V_95 != V_96 )
return - V_57 ;
if ( V_94 -> V_136 ) {
F_45 ( & V_94 -> V_136 -> V_117 , & V_94 -> V_122 ) ;
V_94 -> V_136 = NULL ;
}
if ( F_22 ( V_2 , V_94 -> V_135 ) < 0 ) {
F_49 ( F_2 ( V_2 ) ,
V_92 ) ;
F_45 ( & V_94 -> V_135 -> V_117 , & V_94 -> V_122 ) ;
V_94 -> V_135 = NULL ;
goto V_133;
}
V_94 -> V_136 = V_94 -> V_135 ;
V_94 -> V_135 = NULL ;
F_15 ( V_2 , 1 ) ;
V_133:
if ( ! F_50 ( & V_94 -> V_122 ) )
F_46 ( & V_94 -> V_121 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_137 ;
if ( V_2 -> V_138 ) {
V_137 = V_2 -> V_137 . V_139 << V_140 ;
V_137 |= V_2 -> V_137 . V_141 << V_142 ;
V_137 |= V_2 -> V_137 . V_143 << V_144 ;
V_137 |= V_2 -> V_137 . V_145 << V_146 ;
F_10 ( V_4 , V_137 , V_39 , V_147 ) ;
} else {
F_10 ( V_4 , V_2 -> V_137 . V_148 ,
V_39 , V_149 ) ;
}
F_17 ( V_4 , V_39 , V_147 ,
V_150 ,
V_2 -> V_138 ? V_150 : 0 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 , V_39 , V_151 , V_152 ) ;
if ( ! V_2 -> V_153 )
return;
F_10 ( V_4 , V_2 -> V_154 . V_155 , V_39 ,
V_156 ) ;
F_10 ( V_4 , ( V_2 -> V_154 . V_157 << V_158 ) ,
V_39 , V_151 ) ;
F_10 ( V_4 , ( V_2 -> V_154 . V_157 << V_158 ) |
V_152 , V_39 , V_151 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_159 ;
V_159 = V_2 -> V_159 . V_160 << V_161 ;
V_159 |= V_2 -> V_159 . V_162 << V_163 ;
V_159 |= V_2 -> V_159 . V_164 << V_165 ;
V_159 |= V_2 -> V_159 . V_166 << V_167 ;
F_10 ( V_4 , V_159 , V_39 , V_168 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_169 ,
V_170 ,
V_2 -> V_171 ? V_170 : 0 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_172 = 0 ;
switch ( V_2 -> V_173 . V_174 ) {
case 8 :
return;
case 10 :
V_172 = V_175 ;
break;
case 11 :
V_172 = V_176 ;
break;
case 12 :
V_172 = V_177 ;
break;
case 13 :
V_172 = V_178 ;
break;
}
if ( V_2 -> V_172 )
V_172 |= V_179 ;
F_10 ( V_4 , V_172 , V_39 , V_180 ) ;
}
static void F_56 ( struct V_1 * V_2 , T_1 V_181 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_181 , V_39 , V_182 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_123 * V_183 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_115 ;
F_29 ( & V_2 -> V_184 , V_115 ) ;
V_2 -> V_185 = 1 ;
F_32 ( & V_2 -> V_184 , V_115 ) ;
if ( V_186 & V_183 -> V_124 ) {
V_2 -> V_172 = ! ! ( V_186 & V_183 -> V_131 ) ;
V_2 -> V_124 |= V_186 ;
}
if ( V_187 & V_183 -> V_124 ) {
V_2 -> V_171 = ! ! ( V_187 & V_183 -> V_131 ) ;
V_2 -> V_124 |= V_187 ;
}
if ( V_188 & V_183 -> V_124 ) {
if ( F_37 ( & V_2 -> V_137 , V_183 -> V_189 ,
sizeof( V_2 -> V_137 ) ) ) {
V_2 -> V_185 = 0 ;
return - V_132 ;
}
V_2 -> V_138 = ! ! ( V_188 & V_183 -> V_131 ) ;
V_2 -> V_124 |= V_188 ;
}
if ( V_190 & V_183 -> V_124 ) {
if ( F_37 ( & V_2 -> V_159 , V_183 -> V_159 ,
sizeof( V_2 -> V_159 ) ) ) {
V_2 -> V_185 = 0 ;
return - V_132 ;
}
V_2 -> V_124 |= V_190 ;
}
V_2 -> V_185 = 0 ;
if ( V_191 & V_183 -> V_124 ) {
T_1 V_192 = 0 ;
T_1 V_193 ;
T_1 V_65 ;
if ( V_2 -> V_95 != V_194 )
return - V_103 ;
V_2 -> V_153 = ! ! ( V_191 & V_183 -> V_131 ) ;
if ( V_2 -> V_153 ) {
if ( F_37 ( & V_2 -> V_154 , V_183 -> V_154 ,
sizeof( V_2 -> V_154 ) ) )
return - V_132 ;
V_65 = V_2 -> V_154 . V_157 * 4 ;
V_193 = F_38 ( V_4 -> V_110 , V_4 -> V_111 ,
0 , V_65 , V_134 ) ;
if ( F_39 ( V_193 ) )
return - V_130 ;
if ( F_37 ( F_43 ( V_4 -> V_111 , V_193 ) ,
( V_195 void V_196 * )
V_2 -> V_154 . V_155 , V_65 ) ) {
F_26 ( V_4 -> V_110 , V_4 -> V_111 ,
V_193 ) ;
return - V_132 ;
}
V_192 = V_2 -> V_154 . V_155 ;
V_2 -> V_154 . V_155 = V_193 ;
}
F_52 ( V_2 ) ;
if ( V_192 != 0 )
F_26 ( V_4 -> V_110 , V_4 -> V_111 , V_192 ) ;
}
return F_35 ( V_2 , V_183 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_124 & V_186 ) {
F_55 ( V_2 ) ;
V_2 -> V_124 &= ~ V_186 ;
}
if ( V_2 -> V_124 & V_187 ) {
F_54 ( V_2 ) ;
V_2 -> V_124 &= ~ V_187 ;
}
if ( V_2 -> V_124 & V_188 ) {
F_51 ( V_2 ) ;
V_2 -> V_124 &= ~ V_188 ;
}
if ( V_2 -> V_124 & V_190 ) {
F_53 ( V_2 ) ;
V_2 -> V_124 &= ~ V_190 ;
}
}
void F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
F_60 ( V_4 , V_39 , V_198 , V_199 ) ;
V_2 -> V_124 = V_186 | V_187
| V_188 | V_190 ;
F_58 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_62 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_204 = V_201 -> V_204 ;
unsigned int V_205 = V_4 -> V_206 == V_207 ? 64 : 8 ;
unsigned int div = 0 ;
T_1 V_208 ;
V_208 = F_6 ( V_4 , V_39 , V_209 )
& ~ ( V_210 | V_211 ) ;
switch ( V_2 -> V_173 . V_174 ) {
case 8 :
case 10 :
V_208 |= V_212 ;
break;
case 11 :
V_208 |= V_213 ;
break;
case 12 :
V_208 |= V_214 ;
break;
case 13 :
V_208 |= V_215 ;
break;
} ;
if ( V_201 -> V_216 )
div = F_63 ( V_204 , V_201 -> V_217 ) ;
else if ( V_2 -> V_218 . V_219 )
div = V_204 / V_2 -> V_218 . V_219 ;
div = V_137 ( div , 2U , V_205 ) ;
V_208 |= ( div - 2 ) << V_220 ;
F_10 ( V_4 , V_208 , V_39 , V_209 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_3 V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_209 ,
V_221 , V_86 ? V_221 : 0 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
T_1 V_58 , T_3 V_222 , T_3 V_223 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_58 & 0xffff ,
V_39 , V_224 ) ;
F_18 ( V_4 , V_39 , V_225 ,
V_226 ) ;
F_18 ( V_4 , V_39 , V_225 ,
V_227 ) ;
switch ( V_222 ) {
case V_228 :
F_60 ( V_4 , V_39 , V_225 ,
( V_223 & 0x7 ) << V_229 ) ;
break;
case V_230 :
F_60 ( V_4 , V_39 , V_225 ,
( V_223 & 0x7 ) << V_231 ) ;
break;
case V_232 :
F_60 ( V_4 , V_39 , V_225 ,
( V_223 & 0x7 ) << V_233 ) ;
break;
case V_234 :
F_60 ( V_4 , V_39 , V_225 ,
( V_223 & 0x7 ) << V_235 ) ;
break;
default:
break;
}
}
static void F_66 ( struct V_1 * V_2 , T_1 V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 , V_66 , V_39 , V_236 ) ;
}
void F_67 ( struct V_1 * V_2 ,
unsigned int * V_217 )
{
struct V_200 * V_201 = F_62 ( & V_2 -> V_202 . V_203 ) ;
unsigned int V_237 ;
if ( V_201 == NULL )
return;
if ( V_2 -> V_216 == V_238 )
V_237 = V_201 -> V_204 / 2 * 9 / 10 ;
else
V_237 = V_201 -> V_204 / 2 ;
* V_217 = F_68 ( * V_217 , V_237 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_239 * V_173 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_240 = F_6 ( V_4 , V_39 ,
V_169 ) ;
V_240 |= V_241 ;
if ( V_173 -> V_242 )
V_240 |= V_243 ;
else
V_240 &= ~ V_243 ;
V_240 &= ~ V_244 ;
switch ( V_173 -> V_174 ) {
case 8 :
V_240 |= V_245 ;
break;
case 10 :
V_240 |= V_246 ;
break;
case 11 :
V_240 |= V_247 ;
break;
case 12 :
V_240 |= V_248 ;
break;
} ;
if ( V_173 -> V_249 )
V_240 |= V_250 ;
else
V_240 &= ~ V_250 ;
if ( V_173 -> V_251 )
V_240 |= V_252 ;
else
V_240 &= ~ V_252 ;
if ( V_173 -> V_253 )
V_240 |= V_254 ;
else
V_240 &= ~ V_254 ;
if ( V_173 -> V_255 )
V_240 |= V_256 ;
else
V_240 &= ~ V_256 ;
if ( V_173 -> V_257 )
V_240 |= V_258 ;
else
V_240 &= ~ V_258 ;
if ( V_173 -> V_259 ) {
V_240 |= V_260 | V_261 ;
F_10 ( V_4 ,
V_173 -> V_262 << V_263
| V_173 -> V_264 << V_265 ,
V_39 ,
V_266 ) ;
F_10 ( V_4 ,
V_173 -> V_267 << V_268
| V_173 -> V_269 << V_270 ,
V_39 ,
V_271 ) ;
} else
V_240 &= ~ ( V_260 |
V_261 ) ;
F_10 ( V_4 , V_240 , V_39 , V_169 ) ;
if ( ! V_173 -> V_272 )
F_18 ( V_4 , V_39 , V_273 ,
V_274 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_275 * V_276 = NULL ;
struct V_277 * V_278 ;
struct V_44 * V_45 ;
const struct V_279 * V_280 ;
struct V_281 V_282 ;
unsigned int V_283 ;
unsigned int V_284 = 0 ;
struct V_285 * V_286 ;
unsigned long V_115 ;
unsigned int V_287 ;
T_1 V_240 ;
T_1 V_288 ;
V_286 = F_71 ( & V_2 -> V_289 [ V_61 ] ) ;
V_278 = F_72 ( V_286 -> V_203 ) ;
if ( V_2 -> V_216 == V_238 )
V_276 = & ( (struct V_290 * ) V_278 -> V_291 )
-> V_292 . V_293 ;
V_282 . V_286 = V_286 -> V_294 ;
V_282 . V_295 = V_62 ;
if ( ! F_73 ( V_278 , V_286 , V_296 , NULL , & V_282 ) ) {
V_280 = F_74 ( V_282 . V_45 . V_87 ) ;
V_284 = V_280 -> V_297 ;
}
V_280 = F_74
( V_4 -> V_197 . V_298 [ V_61 ] . V_87 ) ;
V_283 = V_280 -> V_297 ;
V_287 = V_284 - V_283 ;
F_75 ( V_4 , V_2 -> V_216 , V_276 , V_287 ) ;
V_2 -> V_173 . V_174 = V_283 ;
V_2 -> V_173 . V_255 = V_276 ? V_276 -> V_299 : 0 ;
V_2 -> V_173 . V_257 = V_276 ? V_276 -> V_300 : 0 ;
F_69 ( V_2 , & V_2 -> V_173 ) ;
V_45 = & V_2 -> V_298 [ V_61 ] ;
V_240 = F_6 ( V_4 , V_39 , V_169 ) ;
V_240 &= ~ V_301 ;
if ( V_2 -> V_302 & V_303 )
V_240 |= V_304 ;
else
V_240 &= ~ V_304 ;
if ( V_2 -> V_302 & V_305 )
V_240 |= V_306 ;
else
V_240 &= ~ V_306 ;
if ( F_74 ( V_45 -> V_87 ) -> V_297 <= 8 )
V_240 |= V_307 ;
else
V_240 &= ~ V_307 ;
F_10 ( V_4 , V_240 , V_39 , V_169 ) ;
switch ( V_45 -> V_87 ) {
case V_89 :
case V_308 :
V_288 = V_309 ;
break;
case V_90 :
case V_310 :
V_288 = V_311 ;
break;
case V_91 :
case V_312 :
V_288 = V_313 ;
break;
default:
V_288 = V_314 ;
break;
}
F_56 ( V_2 , V_288 ) ;
F_10 ( V_4 , ( ( V_45 -> V_64 - 2 ) << V_315 ) |
( ( V_45 -> V_64 * 2 / 3 ) << V_316 ) ,
V_39 , V_317 ) ;
V_45 = & V_2 -> V_298 [ V_318 ] ;
F_10 ( V_4 , ( 0 << V_319 ) |
( ( V_45 -> V_63 - 1 ) << V_320 ) ,
V_39 , V_321 ) ;
F_10 ( V_4 , 0 << V_322 ,
V_39 , V_323 ) ;
F_10 ( V_4 , ( V_45 -> V_64 - 1 )
<< V_324 ,
V_39 , V_325 ) ;
F_65 ( V_2 , V_2 -> V_326 . V_327 , 0 , 0 ) ;
V_45 = & V_2 -> V_298 [ V_328 ] ;
F_10 ( V_4 , ( 0 << V_329 ) |
( V_45 -> V_63 << V_330 ) ,
V_39 , V_331 ) ;
F_10 ( V_4 , ( 0 << V_332 ) |
( ( V_45 -> V_64 + 1 ) << V_333 ) ,
V_39 , V_334 ) ;
F_10 ( V_4 , ( V_45 -> V_63 << V_335 ) |
( V_45 -> V_64 << V_336 ) ,
V_39 , V_337 ) ;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
if ( V_2 -> V_94 . V_135 == NULL )
goto V_338;
F_76 ( V_2 -> V_94 . V_136 ) ;
if ( V_2 -> V_94 . V_136 == NULL &&
F_22 ( V_2 , V_2 -> V_94 . V_135 ) == 0 ) {
V_2 -> V_94 . V_136 = V_2 -> V_94 . V_135 ;
} else {
F_45 ( & V_2 -> V_94 . V_135 -> V_117 , & V_2 -> V_94 . V_122 ) ;
F_46 ( & V_2 -> V_94 . V_121 ) ;
}
V_2 -> V_94 . V_135 = NULL ;
V_338:
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
F_58 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 , V_39 , V_40 ,
V_339 , V_86 ? V_339 : 0 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
int V_125 = 0 ;
F_29 ( & V_2 -> V_184 , V_115 ) ;
if ( V_2 -> V_95 == V_340 )
V_2 -> V_341 = V_342 ;
F_32 ( & V_2 -> V_184 , V_115 ) ;
V_125 = F_79 ( V_2 -> V_81 ,
V_2 -> V_341 == V_343 ,
F_80 ( 2000 ) ) ;
if ( V_125 == 0 ) {
V_125 = - V_85 ;
F_19 ( F_20 ( V_2 ) , L_14 ) ;
}
F_49 ( F_2 ( V_2 ) , V_92 ) ;
F_81 ( & V_2 -> V_344 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_135 ) ;
V_2 -> V_94 . V_135 = V_2 -> V_94 . V_136 ;
V_2 -> V_94 . V_136 = NULL ;
F_82 ( & V_2 -> V_94 . V_121 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_122 ) ;
F_83 ( & V_2 -> V_344 ) ;
V_2 -> V_341 = V_345 ;
return V_125 > 0 ? 0 : V_125 ;
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
| ( F_6 ( V_4 , V_346 , V_347 ) &
V_348 )
| ( F_6 ( V_4 , V_346 , V_349 ) &
V_348 )
| ( F_6 ( V_4 , V_346 , V_350 ) &
V_348 )
| ( F_6 ( V_4 , V_346 , V_351 ) &
V_348 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
unsigned int V_352 )
{
unsigned int V_81 = 0 ;
if ( V_352 == 0 )
V_352 = 10000 ;
for ( V_81 = 0 ; V_81 <= V_352 ; V_81 ++ ) {
if ( ! F_85 ( V_2 ) )
return 0 ;
F_13 () ;
F_14 ( 1 ) ;
}
return - V_103 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_353 )
{
int V_354 = 0 ;
switch ( ( V_2 -> V_341 & 3 ) | V_353 ) {
case V_342 | V_355 :
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_77 ( V_2 , 0 ) ;
V_2 -> V_341 = V_356 ;
return 1 ;
case V_356 | V_357 :
V_2 -> V_341 |= V_358 ;
if ( V_2 -> V_94 . V_95 == V_96 )
V_2 -> V_341 |= V_359 ;
V_354 = 1 ;
break;
case V_356 | V_360 :
V_2 -> V_341 |= V_359 ;
V_354 = 1 ;
break;
case V_356 | V_355 :
return 1 ;
}
if ( V_2 -> V_341 == V_343 ) {
F_88 ( & V_2 -> V_81 ) ;
V_354 = 1 ;
}
return V_354 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_200 * V_201 =
F_62 ( & V_2 -> V_326 . V_361 . V_203 ) ;
struct V_362 * V_363 = V_2 -> V_202 . V_364 ;
struct V_365 V_353 ;
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
V_353 . type = V_366 ;
V_353 . V_367 . V_368 . V_369 = F_90 ( & V_201 -> V_370 ) ;
F_91 ( V_363 , & V_353 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_371 )
{
unsigned long V_115 ;
if ( V_371 & V_372 ) {
F_23 ( V_2 ) ;
V_2 -> error = 1 ;
F_3 ( F_20 ( V_2 ) , L_15 ) ;
}
if ( ! ( V_371 & V_373 ) )
return;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
if ( V_2 -> V_94 . V_95 == V_98 )
V_2 -> V_94 . V_95 = V_96 ;
if ( F_87 ( V_2 , V_360 ) )
goto V_133;
if ( V_2 -> V_94 . V_95 != V_374 )
goto V_133;
V_2 -> V_94 . V_95 = V_96 ;
if ( V_371 & V_375 )
goto V_133;
if ( V_2 -> V_94 . V_135 == NULL )
goto V_133;
F_48 ( V_2 ) ;
V_133:
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_200 * V_201 = F_62 ( & V_2 -> V_202 . V_203 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_376 * V_377 ;
int V_378 = 0 ;
if ( F_50 ( & V_2 -> V_326 . V_379 ) )
goto V_133;
if ( V_2 -> V_95 == V_340 && V_2 -> V_380 ) {
V_378 = 1 ;
V_2 -> V_380 = 0 ;
goto V_133;
}
if ( F_86 ( V_2 , 1000 ) ) {
F_94 ( V_4 -> V_5 , L_16 ) ;
goto V_133;
}
V_377 = F_95 ( & V_2 -> V_326 , V_2 -> error ) ;
if ( V_377 != NULL ) {
F_66 ( V_2 , V_377 -> V_381 ) ;
V_378 = 1 ;
}
V_201 -> V_95 |= V_382 ;
if ( V_2 -> V_95 == V_383 &&
F_96 ( V_201 ) )
F_97 ( V_201 ,
V_383 ) ;
V_133:
V_2 -> error = 0 ;
return V_378 ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
int V_378 = 0 ;
if ( V_2 -> V_302 & V_303 )
V_378 = F_93 ( V_2 ) ;
F_29 ( & V_2 -> V_184 , V_115 ) ;
if ( F_87 ( V_2 , V_357 ) ) {
F_32 ( & V_2 -> V_184 , V_115 ) ;
return;
}
if ( ! V_2 -> V_185 )
F_58 ( V_2 ) ;
F_32 ( & V_2 -> V_184 , V_115 ) ;
if ( V_378 )
F_84 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
F_29 ( & V_2 -> V_94 . V_116 , V_115 ) ;
switch ( V_2 -> V_95 ) {
case V_383 :
V_2 -> V_341 = V_342 ;
break;
case V_340 :
if ( V_2 -> V_302 & V_303 ) {
if ( V_2 -> V_94 . V_95 != V_96 )
F_15 ( V_2 , 0 ) ;
F_77 ( V_2 , 0 ) ;
}
break;
case V_194 :
break;
}
if ( F_87 ( V_2 , V_355 ) )
goto V_133;
if ( V_2 -> V_94 . V_135 == NULL )
goto V_133;
if ( V_2 -> V_94 . V_95 == V_97 ) {
F_15 ( V_2 , 0 ) ;
V_2 -> V_94 . V_95 = V_374 ;
goto V_133;
}
if ( V_2 -> V_94 . V_95 == V_96 )
F_48 ( V_2 ) ;
V_133:
F_32 ( & V_2 -> V_94 . V_116 , V_115 ) ;
}
int F_100 ( struct V_1 * V_2 , T_1 V_371 )
{
if ( V_2 -> V_95 == V_194 )
return 0 ;
if ( V_371 & V_384 )
F_99 ( V_2 ) ;
F_92 ( V_2 , V_371 ) ;
if ( V_371 & V_385 )
F_98 ( V_2 ) ;
if ( V_371 & V_375 )
F_89 ( V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_386 * V_361 , struct V_376 * V_377 )
{
struct V_1 * V_2 = & V_361 -> V_4 -> V_197 ;
if ( ! ( V_2 -> V_302 & V_303 ) )
return - V_387 ;
F_66 ( V_2 , V_377 -> V_381 ) ;
V_2 -> V_380 = 1 ;
return 0 ;
}
static long F_102 ( struct V_277 * V_388 , unsigned int V_389 , void * V_390 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
int V_125 ;
switch ( V_389 ) {
case V_391 :
F_81 ( & V_2 -> V_344 ) ;
V_125 = F_57 ( V_2 , V_390 ) ;
F_83 ( & V_2 -> V_344 ) ;
break;
default:
return - V_392 ;
}
return V_125 ;
}
static int F_104 ( struct V_277 * V_388 , struct V_393 * V_394 ,
struct V_395 * V_396 )
{
if ( V_396 -> type != V_366 )
return - V_57 ;
if ( V_396 -> V_397 != 0 )
return - V_57 ;
return F_105 ( V_394 , V_396 , V_398 ) ;
}
static int F_106 ( struct V_277 * V_388 , struct V_393 * V_394 ,
struct V_395 * V_396 )
{
return F_107 ( V_394 , V_396 ) ;
}
static int F_108 ( struct V_277 * V_388 , int V_86 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_125 = 0 ;
if ( V_2 -> V_95 == V_194 ) {
if ( V_86 == V_194 )
return 0 ;
F_109 ( V_4 , V_399 ) ;
F_60 ( V_4 , V_39 , V_198 ,
V_199 ) ;
F_70 ( V_2 ) ;
F_61 ( V_2 ) ;
F_64 ( V_2 , 1 ) ;
V_2 -> error = 0 ;
F_1 ( V_2 ) ;
}
switch ( V_86 ) {
case V_340 :
if ( V_2 -> V_302 & V_303 )
F_16 ( V_4 , V_400 ) ;
if ( V_2 -> V_380 || ! ( V_2 -> V_302 & V_303 ) )
F_84 ( V_2 ) ;
V_2 -> V_380 = 0 ;
break;
case V_383 :
if ( V_2 -> V_302 & V_303 &&
V_2 -> V_95 != V_383 )
F_16 ( V_4 , V_400 ) ;
F_84 ( V_2 ) ;
break;
case V_194 :
V_125 = F_78 ( V_2 ) ;
if ( V_2 -> V_302 & V_303 )
F_49 ( V_4 , V_400 ) ;
F_110 ( V_4 , V_399 ) ;
V_2 -> V_380 = 0 ;
break;
}
V_2 -> V_95 = V_86 ;
return V_125 ;
}
static struct V_44 *
F_8 ( struct V_1 * V_2 , struct V_401 * V_394 ,
unsigned int V_286 , enum V_402 V_295 )
{
if ( V_295 == V_403 )
return F_111 ( V_394 , V_286 ) ;
else
return & V_2 -> V_298 [ V_286 ] ;
}
static void
F_112 ( struct V_1 * V_2 , struct V_401 * V_394 ,
unsigned int V_286 , struct V_44 * V_404 ,
enum V_402 V_295 )
{
struct V_44 * V_45 ;
const struct V_279 * V_405 ;
unsigned int V_63 = V_404 -> V_63 ;
unsigned int V_64 = V_404 -> V_64 ;
unsigned int V_406 ;
switch ( V_286 ) {
case V_61 :
for ( V_406 = 0 ; V_406 < F_113 ( V_407 ) ; V_406 ++ ) {
if ( V_404 -> V_87 == V_407 [ V_406 ] )
break;
}
if ( V_406 >= F_113 ( V_407 ) )
V_404 -> V_87 = V_88 ;
V_404 -> V_63 = F_114 ( T_1 , V_63 , 32 , 4096 ) ;
V_404 -> V_64 = F_114 ( T_1 , V_64 , 32 , 4096 ) ;
break;
case V_318 :
V_45 = F_8 ( V_2 , V_394 , V_61 , V_295 ) ;
memcpy ( V_404 , V_45 , sizeof( * V_404 ) ) ;
V_404 -> V_63 = F_114 ( T_1 , V_63 , 32 , V_404 -> V_63 + 15 ) ;
V_404 -> V_63 &= ~ 15 ;
V_404 -> V_64 = F_114 ( T_1 , V_64 , 32 , V_404 -> V_64 ) ;
break;
case V_328 :
V_45 = F_8 ( V_2 , V_394 , V_61 , V_295 ) ;
memcpy ( V_404 , V_45 , sizeof( * V_404 ) ) ;
V_405 = F_74 ( V_404 -> V_87 ) ;
V_404 -> V_87 = V_405 -> V_408 ;
V_404 -> V_63 = F_114 ( T_1 , V_63 , 32 , V_404 -> V_63 ) ;
V_404 -> V_64 = F_114 ( T_1 , V_64 , 32 , V_404 -> V_64 - 1 ) ;
break;
}
V_404 -> V_409 = V_410 ;
V_404 -> V_411 = V_412 ;
}
static int F_115 ( struct V_277 * V_388 ,
struct V_401 * V_394 ,
struct V_413 * V_87 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_44 * V_45 ;
switch ( V_87 -> V_286 ) {
case V_61 :
if ( V_87 -> V_294 >= F_113 ( V_407 ) )
return - V_57 ;
V_87 -> V_87 = V_407 [ V_87 -> V_294 ] ;
break;
case V_318 :
case V_328 :
if ( V_87 -> V_294 != 0 )
return - V_57 ;
V_45 = F_8 ( V_2 , V_394 , V_61 ,
V_403 ) ;
V_87 -> V_87 = V_45 -> V_87 ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_116 ( struct V_277 * V_388 ,
struct V_401 * V_394 ,
struct V_414 * V_415 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_44 V_45 ;
if ( V_415 -> V_294 != 0 )
return - V_57 ;
V_45 . V_87 = V_415 -> V_87 ;
V_45 . V_63 = 1 ;
V_45 . V_64 = 1 ;
F_112 ( V_2 , V_394 , V_415 -> V_286 , & V_45 , V_403 ) ;
V_415 -> V_50 = V_45 . V_63 ;
V_415 -> V_51 = V_45 . V_64 ;
if ( V_45 . V_87 != V_415 -> V_87 )
return - V_57 ;
V_45 . V_87 = V_415 -> V_87 ;
V_45 . V_63 = - 1 ;
V_45 . V_64 = - 1 ;
F_112 ( V_2 , V_394 , V_415 -> V_286 , & V_45 , V_403 ) ;
V_415 -> V_416 = V_45 . V_63 ;
V_415 -> V_417 = V_45 . V_64 ;
return 0 ;
}
static int F_117 ( struct V_277 * V_388 , struct V_401 * V_394 ,
struct V_281 * V_404 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_394 , V_404 -> V_286 , V_404 -> V_295 ) ;
if ( V_45 == NULL )
return - V_57 ;
V_404 -> V_45 = * V_45 ;
return 0 ;
}
static int F_118 ( struct V_277 * V_388 , struct V_401 * V_394 ,
struct V_281 * V_404 )
{
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_44 * V_45 ;
V_45 = F_8 ( V_2 , V_394 , V_404 -> V_286 , V_404 -> V_295 ) ;
if ( V_45 == NULL )
return - V_57 ;
F_112 ( V_2 , V_394 , V_404 -> V_286 , & V_404 -> V_45 , V_404 -> V_295 ) ;
* V_45 = V_404 -> V_45 ;
if ( V_404 -> V_286 == V_61 ) {
V_45 = F_8 ( V_2 , V_394 , V_318 ,
V_404 -> V_295 ) ;
* V_45 = V_404 -> V_45 ;
F_112 ( V_2 , V_394 , V_318 , V_45 ,
V_404 -> V_295 ) ;
V_45 = F_8 ( V_2 , V_394 , V_328 ,
V_404 -> V_295 ) ;
* V_45 = V_404 -> V_45 ;
F_112 ( V_2 , V_394 , V_328 , V_45 ,
V_404 -> V_295 ) ;
}
return 0 ;
}
static int F_119 ( struct V_277 * V_388 , struct V_401 * V_394 )
{
struct V_281 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_286 = V_61 ;
V_45 . V_295 = V_394 ? V_403 : V_62 ;
V_45 . V_45 . V_87 = V_88 ;
V_45 . V_45 . V_63 = 4096 ;
V_45 . V_45 . V_64 = 4096 ;
F_118 ( V_388 , V_394 , & V_45 ) ;
return 0 ;
}
static int F_120 ( struct V_418 * V_203 ,
const struct V_285 * V_419 ,
const struct V_285 * V_420 , T_1 V_115 )
{
struct V_277 * V_388 = F_72 ( V_203 ) ;
struct V_1 * V_2 = F_103 ( V_388 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_419 -> V_294 | F_121 ( V_420 -> V_203 ) ) {
case V_61 | V_421 :
if ( ! ( V_115 & V_422 ) ) {
V_2 -> V_216 = V_423 ;
break;
}
if ( V_2 -> V_216 != V_423 )
return - V_103 ;
if ( V_420 -> V_203 == & V_4 -> V_424 . V_202 . V_203 )
V_2 -> V_216 = V_425 ;
else if ( V_420 -> V_203 == & V_4 -> V_426 . V_202 . V_203 )
V_2 -> V_216 = V_427 ;
else if ( V_420 -> V_203 == & V_4 -> V_428 . V_202 . V_203 )
V_2 -> V_216 = V_429 ;
else
V_2 -> V_216 = V_238 ;
break;
case V_328 | V_421 :
if ( V_115 & V_422 ) {
if ( V_2 -> V_302 & ~ V_430 )
return - V_103 ;
V_2 -> V_302 |= V_430 ;
} else {
V_2 -> V_302 &= ~ V_430 ;
}
break;
case V_318 | V_431 :
if ( V_115 & V_422 ) {
if ( V_2 -> V_302 & ~ V_303 )
return - V_103 ;
V_2 -> V_302 |= V_303 ;
} else {
V_2 -> V_302 &= ~ V_303 ;
}
break;
case V_318 | V_421 :
if ( V_115 & V_422 ) {
if ( V_2 -> V_302 & ~ V_305 )
return - V_103 ;
V_2 -> V_302 |= V_305 ;
} else {
V_2 -> V_302 &= ~ V_305 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
void F_122 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_202 ) ;
F_124 ( & V_2 -> V_326 ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_432 * V_363 )
{
int V_125 ;
V_125 = F_126 ( V_363 , & V_2 -> V_202 ) ;
if ( V_125 < 0 )
goto error;
V_125 = F_127 ( & V_2 -> V_326 , V_363 ) ;
if ( V_125 < 0 )
goto error;
return 0 ;
error:
F_122 ( V_2 ) ;
return V_125 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_277 * V_388 = & V_2 -> V_202 ;
struct V_285 * V_289 = V_2 -> V_289 ;
struct V_418 * V_433 = & V_388 -> V_203 ;
int V_125 ;
V_2 -> V_216 = V_423 ;
F_129 ( V_388 , & V_434 ) ;
V_388 -> V_435 = & V_436 ;
F_130 ( V_388 -> V_437 , L_17 , sizeof( V_388 -> V_437 ) ) ;
V_388 -> V_438 = 1 << 16 ;
F_131 ( V_388 , V_2 ) ;
V_388 -> V_115 |= V_439 | V_440 ;
V_289 [ V_61 ] . V_115 = V_441 ;
V_289 [ V_328 ] . V_115 = V_442 ;
V_289 [ V_318 ] . V_115 = V_442 ;
V_433 -> V_443 = & V_444 ;
V_125 = F_132 ( V_433 , V_445 , V_289 , 0 ) ;
if ( V_125 < 0 )
return V_125 ;
F_119 ( V_388 , NULL ) ;
V_2 -> V_326 . type = V_446 ;
V_2 -> V_326 . V_443 = & V_447 ;
V_2 -> V_326 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_326 . V_448 = F_133 ( 4096 * 4096 ) * 3 ;
V_2 -> V_326 . V_449 = 32 ;
V_125 = F_134 ( & V_2 -> V_326 , L_18 ) ;
if ( V_125 < 0 )
goto V_450;
V_125 = F_135 ( & V_2 -> V_202 . V_203 , V_318 ,
& V_2 -> V_326 . V_361 . V_203 , 0 , 0 ) ;
if ( V_125 < 0 )
goto V_451;
return 0 ;
V_451:
F_136 ( & V_2 -> V_326 ) ;
V_450:
F_137 ( V_433 ) ;
return V_125 ;
}
int F_138 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
int V_125 ;
F_139 ( & V_2 -> V_184 ) ;
F_140 ( & V_2 -> V_81 ) ;
F_141 ( & V_2 -> V_344 ) ;
V_2 -> V_341 = V_345 ;
F_142 ( & V_2 -> V_94 . V_121 , F_33 ) ;
V_2 -> V_94 . V_95 = V_96 ;
F_143 ( & V_2 -> V_94 . V_122 ) ;
F_139 ( & V_2 -> V_94 . V_116 ) ;
V_2 -> V_173 . V_259 = 0 ;
V_2 -> V_173 . V_251 = 0 ;
V_2 -> V_173 . V_174 = 0 ;
V_2 -> V_173 . V_249 = 0 ;
V_2 -> V_173 . V_452 = 0 ;
V_2 -> V_173 . V_253 = 0 ;
V_2 -> V_173 . V_242 = 0 ;
V_2 -> V_137 . V_141 = 0 ;
V_2 -> V_137 . V_148 = 0 ;
V_2 -> V_218 . V_219 = 0 ;
V_2 -> V_124 = V_188 ;
F_58 ( V_2 ) ;
V_125 = F_128 ( V_2 ) ;
if ( V_125 < 0 ) {
F_144 ( & V_2 -> V_344 ) ;
return V_125 ;
}
return 0 ;
}
void F_145 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_197 ;
F_136 ( & V_2 -> V_326 ) ;
F_137 ( & V_2 -> V_202 . V_203 ) ;
F_24 ( V_2 , V_2 -> V_94 . V_135 ) ;
F_82 ( & V_2 -> V_94 . V_121 ) ;
F_28 ( V_2 , & V_2 -> V_94 . V_122 ) ;
if ( V_2 -> V_154 . V_155 != 0 )
F_26 ( V_4 -> V_110 , V_4 -> V_111 , V_2 -> V_154 . V_155 ) ;
F_144 ( & V_2 -> V_344 ) ;
}
