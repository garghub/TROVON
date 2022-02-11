int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_7 -> V_10 = L_1 ;
V_7 -> V_11 = V_12 |
V_13 |
V_14 |
V_15 |
V_16 ;
V_7 -> V_11 |= V_17 |
V_18 ;
if ( F_2 ( V_2 ) -> V_19 & V_20 )
V_7 -> V_11 |= V_21 |
V_22 ;
if ( V_4 -> V_11 & V_23 )
V_7 -> V_11 |= V_24 ;
V_7 -> V_25 = sizeof( struct V_26 ) ;
V_7 -> V_27 = sizeof( struct V_28 ) ;
F_3 (priv, ctx) {
V_7 -> V_29 -> V_30 |= V_9 -> V_30 ;
V_7 -> V_29 -> V_30 |= V_9 -> V_31 ;
}
F_4 ( V_32 != 2 ) ;
if ( V_7 -> V_29 -> V_30 & F_5 ( V_33 ) ) {
V_7 -> V_29 -> V_34 = V_35 ;
V_7 -> V_29 -> V_36 =
F_6 ( V_35 ) ;
} else if ( V_7 -> V_29 -> V_30 & F_5 ( V_37 ) ) {
V_7 -> V_29 -> V_34 =
V_38 ;
V_7 -> V_29 -> V_36 =
F_6 ( V_38 ) ;
}
V_7 -> V_29 -> V_39 = 1000 ;
V_7 -> V_29 -> V_11 |= V_40 |
V_41 |
V_42 ;
if ( F_7 ( V_2 ) -> V_43 . V_44 . V_45 &&
F_8 ( F_9 ( V_2 ) -> V_46 ) ) {
V_7 -> V_29 -> V_47 . V_11 = V_48 |
V_49 |
V_50 |
V_51 ;
if ( ! V_52 . V_53 )
V_7 -> V_29 -> V_47 . V_11 |=
V_54 |
V_55 ;
V_7 -> V_29 -> V_47 . V_56 = V_57 ;
V_7 -> V_29 -> V_47 . V_58 =
V_59 ;
V_7 -> V_29 -> V_47 . V_60 =
V_61 ;
}
if ( V_52 . V_62 )
V_7 -> V_29 -> V_11 |= V_63 ;
else
V_7 -> V_29 -> V_11 &= ~ V_63 ;
V_7 -> V_29 -> V_64 = V_65 ;
V_7 -> V_29 -> V_66 = V_4 -> V_67 - 24 - 2 ;
V_7 -> V_68 = 4 ;
V_7 -> V_69 = V_70 ;
if ( V_2 -> V_71 [ V_72 ] . V_73 )
V_2 -> V_7 -> V_29 -> V_71 [ V_72 ] =
& V_2 -> V_71 [ V_72 ] ;
if ( V_2 -> V_71 [ V_74 ] . V_73 )
V_2 -> V_7 -> V_29 -> V_71 [ V_74 ] =
& V_2 -> V_71 [ V_74 ] ;
V_7 -> V_29 -> V_75 = F_10 ( F_9 ( V_2 ) ) ;
F_11 ( V_2 ) ;
V_5 = F_12 ( V_2 -> V_7 ) ;
if ( V_5 ) {
F_13 ( V_2 , L_2 , V_5 ) ;
return V_5 ;
}
V_2 -> V_76 = 1 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_76 )
return;
F_15 ( V_2 ) ;
F_16 ( V_2 -> V_7 ) ;
V_2 -> V_76 = 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_5 ;
F_18 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_19 ( V_79 , & V_2 -> V_77 -> V_80 ) ) {
F_20 ( V_2 , L_3 ) ;
return - V_81 ;
}
F_3 (priv, ctx) {
V_5 = F_21 ( V_2 , V_9 ) ;
if ( V_5 ) {
F_22 ( V_2 ) ;
return V_5 ;
}
}
V_5 = F_23 ( F_7 ( V_2 ) ) ;
if ( V_5 ) {
F_13 ( V_2 , L_4 , V_5 ) ;
goto error;
}
V_5 = F_24 ( F_7 ( V_2 ) , V_82 ) ;
if ( V_5 ) {
F_13 ( V_2 , L_5 , V_5 ) ;
goto error;
}
V_5 = F_25 ( V_2 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_26 ( V_79 , & V_2 -> V_77 -> V_80 ) ;
F_27 ( V_2 ) ;
F_28 ( V_79 , & V_2 -> V_77 -> V_80 ) ;
F_13 ( V_2 , L_6 ) ;
return V_5 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_5 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
V_5 = F_17 ( V_2 ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
if ( V_5 )
return V_5 ;
F_33 ( V_2 , L_8 ) ;
if ( F_34 ( ! F_19 ( V_83 , & V_2 -> V_77 -> V_80 ) ) )
V_5 = - V_81 ;
F_35 ( V_2 ) ;
V_2 -> V_84 = 1 ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_30 ( V_2 , L_7 ) ;
if ( ! V_2 -> V_84 )
return;
V_2 -> V_84 = 0 ;
F_37 ( V_2 ) ;
F_38 ( V_2 -> V_77 -> V_85 ) ;
F_39 ( F_9 ( V_2 ) , V_86 , 0xFFFFFFFF ) ;
F_40 ( V_2 ) ;
F_30 ( V_2 , L_9 ) ;
}
static void F_41 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_52 . V_53 )
return;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( V_2 -> V_91 [ V_92 ] . V_88 != V_88 )
goto V_93;
memcpy ( V_2 -> V_94 , V_90 -> V_94 , V_95 ) ;
memcpy ( V_2 -> V_96 , V_90 -> V_96 , V_97 ) ;
V_2 -> V_98 =
F_42 ( F_43 ( ( V_99 * ) & V_90 -> V_98 ) ) ;
V_2 -> V_100 = true ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_44 ( struct V_6 * V_7 ,
struct V_101 * V_47 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_91 [ V_92 ] ;
int V_5 ;
if ( F_34 ( ! V_47 ) )
return - V_102 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( ! V_9 -> V_88 || V_9 -> V_88 -> type != V_103 ||
! F_45 ( V_9 ) ) {
V_5 = 1 ;
goto V_93;
}
V_5 = F_46 ( V_2 , V_7 , V_47 ) ;
if ( V_5 )
goto error;
F_47 ( F_9 ( V_2 ) -> V_46 , true ) ;
F_39 ( F_9 ( V_2 ) , V_104 ,
V_105 ) ;
goto V_93;
error:
V_2 -> V_77 -> V_47 = false ;
F_48 ( V_2 ) ;
F_49 ( V_2 -> V_7 ) ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_91 [ V_92 ] ;
struct V_87 * V_88 ;
unsigned long V_11 ;
T_1 V_106 , V_80 = 0xffffffff ;
int V_5 = - V_81 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_39 ( F_9 ( V_2 ) , V_107 ,
V_105 ) ;
V_106 = V_2 -> V_77 -> V_108 . V_109 ;
if ( F_51 ( V_106 ) ) {
F_52 ( & F_9 ( V_2 ) -> V_110 , V_11 ) ;
V_5 = F_53 ( F_9 ( V_2 ) ) ;
if ( V_5 == 0 ) {
F_39 ( F_9 ( V_2 ) , V_111 , V_106 ) ;
V_80 = F_54 ( F_9 ( V_2 ) , V_112 ) ;
F_55 ( F_9 ( V_2 ) ) ;
}
F_56 ( & F_9 ( V_2 ) -> V_110 , V_11 ) ;
#ifdef F_57
if ( V_5 == 0 ) {
struct V_113 * F_7 = F_7 ( V_2 ) ;
if ( ! V_2 -> V_114 )
V_2 -> V_114 =
F_58 ( F_7 -> V_43 . V_90 . V_45 ,
V_115 ) ;
if ( V_2 -> V_114 )
F_59 (
F_9 ( V_2 ) , 0x800000 , V_2 -> V_114 ,
F_7 -> V_43 . V_90 . V_45 / 4 ) ;
}
#endif
}
V_88 = V_9 -> V_88 ;
V_2 -> V_77 -> V_47 = false ;
F_47 ( F_9 ( V_2 ) -> V_46 , false ) ;
F_48 ( V_2 ) ;
memset ( ( void * ) & V_9 -> V_116 , 0 , sizeof( V_9 -> V_116 ) ) ;
F_60 ( V_2 , V_9 ) ;
F_61 ( V_2 , V_9 ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
F_62 ( V_88 ) ;
return 1 ;
}
static void F_63 ( struct V_6 * V_7 , struct V_117 * V_118 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_64 ( V_2 , L_10 , V_118 -> V_45 ,
F_65 ( V_7 , F_66 ( V_118 ) ) -> V_119 ) ;
if ( F_67 ( V_2 , V_118 ) )
F_68 ( V_118 ) ;
}
static void F_69 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
T_1 V_124 , T_2 * V_125 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_70 ( V_2 , V_88 , V_121 , V_123 , V_124 , V_125 ) ;
}
static int F_71 ( struct V_6 * V_7 , enum V_126 V_127 ,
struct V_87 * V_88 ,
struct V_122 * V_123 ,
struct V_120 * V_128 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
struct V_8 * V_9 = V_129 -> V_9 ;
int V_5 ;
bool V_131 = false ;
F_30 ( V_2 , L_7 ) ;
if ( V_52 . V_53 ) {
F_30 ( V_2 , L_11 ) ;
return - V_132 ;
}
switch ( V_128 -> V_133 ) {
case V_134 :
V_128 -> V_11 |= V_135 ;
case V_136 :
V_128 -> V_11 |= V_137 ;
break;
default:
break;
}
if ( V_88 -> type == V_138 &&
! ( V_128 -> V_11 & V_139 ) ) {
V_128 -> V_140 = V_141 ;
return 0 ;
}
if ( V_127 == V_142 && V_128 -> V_140 == V_141 )
return 0 ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_72 ( V_2 , 100 ) ;
F_4 ( V_141 == V_143 ) ;
if ( ( V_128 -> V_133 == V_144 ||
V_128 -> V_133 == V_145 ) && ! V_123 ) {
if ( V_127 == V_146 )
V_131 = ! V_9 -> V_147 ;
else
V_131 =
V_128 -> V_140 == V_143 ;
}
switch ( V_127 ) {
case V_146 :
if ( V_131 ) {
V_5 = F_73 ( V_2 , V_129 -> V_9 , V_128 ) ;
break;
}
V_5 = F_74 ( V_2 , V_129 -> V_9 , V_128 , V_123 ) ;
if ( V_5 ) {
V_5 = 0 ;
V_128 -> V_140 = V_141 ;
}
F_30 ( V_2 , L_12 ) ;
break;
case V_142 :
if ( V_131 )
V_5 = F_75 ( V_2 , V_9 , V_128 ) ;
else
V_5 = F_76 ( V_2 , V_9 , V_128 , V_123 ) ;
F_30 ( V_2 , L_13 ) ;
break;
default:
V_5 = - V_102 ;
}
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
enum V_148 V_149 ,
struct V_122 * V_123 , T_2 V_150 , T_2 * V_151 ,
T_3 V_152 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_5 = - V_102 ;
struct V_26 * V_153 = ( void * ) V_123 -> V_130 ;
F_78 ( V_2 , L_14 ,
V_123 -> V_154 , V_150 ) ;
if ( ! ( F_2 ( V_2 ) -> V_19 & V_20 ) )
return - V_155 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
switch ( V_149 ) {
case V_156 :
if ( V_52 . V_157 & V_158 )
break;
F_78 ( V_2 , L_15 ) ;
V_5 = F_79 ( V_2 , V_123 , V_150 , * V_151 ) ;
break;
case V_159 :
F_78 ( V_2 , L_16 ) ;
V_5 = F_80 ( V_2 , V_123 , V_150 ) ;
if ( F_19 ( V_79 , & V_2 -> V_77 -> V_80 ) )
V_5 = 0 ;
break;
case V_160 :
if ( V_52 . V_157 & V_161 )
break;
F_78 ( V_2 , L_17 ) ;
V_5 = F_81 ( V_2 , V_88 , V_123 , V_150 , V_151 ) ;
break;
case V_162 :
F_78 ( V_2 , L_18 ) ;
V_5 = F_82 ( V_2 , V_88 , V_123 , V_150 ) ;
if ( ( V_5 == 0 ) && ( V_2 -> V_163 > 0 ) ) {
V_2 -> V_163 -- ;
F_78 ( V_2 , L_19 ,
V_2 -> V_163 ) ;
}
if ( F_19 ( V_79 , & V_2 -> V_77 -> V_80 ) )
V_5 = 0 ;
if ( ! V_2 -> V_163 && F_2 ( V_2 ) -> V_164 &&
F_2 ( V_2 ) -> V_164 -> V_165 ) {
V_153 -> V_166 . V_167 . V_168 . V_11 &=
~ V_169 ;
F_83 ( V_2 , F_84 ( V_88 ) ,
& V_153 -> V_166 . V_167 , V_170 , false ) ;
}
break;
case V_171 :
V_5 = F_85 ( V_2 , V_88 , V_123 , V_150 , V_152 ) ;
break;
}
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_26 * V_153 = ( void * ) V_123 -> V_130 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
bool V_172 = V_88 -> type == V_103 ;
int V_5 = 0 ;
T_3 V_173 ;
F_30 ( V_2 , L_20 ,
V_123 -> V_154 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_33 ( V_2 , L_21 ,
V_123 -> V_154 ) ;
V_153 -> V_173 = V_174 ;
F_87 ( & V_153 -> V_175 , 0 ) ;
if ( V_88 -> type == V_37 )
V_153 -> V_176 = true ;
V_5 = F_88 ( V_2 , V_129 -> V_9 , V_123 -> V_154 ,
V_172 , V_123 , & V_173 ) ;
if ( V_5 ) {
F_13 ( V_2 , L_22 ,
V_123 -> V_154 , V_5 ) ;
goto V_93;
}
V_153 -> V_173 = V_173 ;
F_33 ( V_2 , L_23 ,
V_123 -> V_154 ) ;
F_89 ( V_2 , V_123 , V_173 ) ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_90 ( struct V_6 * V_7 ,
struct V_177 * V_178 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_179 * V_180 ;
struct V_181 * V_182 = & V_7 -> V_182 ;
struct V_183 * V_184 = V_178 -> V_184 ;
struct V_185 * V_186 = & V_2 -> V_187 ;
struct V_8 * V_9 = & V_2 -> V_91 [ V_92 ] ;
T_2 V_188 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_91 ( V_2 -> V_77 ) )
goto V_93;
if ( F_19 ( V_79 , & V_2 -> V_77 -> V_80 ) ||
F_19 ( V_189 , & V_2 -> V_77 -> V_80 ) ||
F_19 ( V_190 , & V_2 -> V_77 -> V_80 ) )
goto V_93;
if ( ! F_45 ( V_9 ) )
goto V_93;
if ( ! F_2 ( V_2 ) -> V_191 -> V_192 )
goto V_93;
V_188 = V_184 -> V_193 ;
if ( F_92 ( V_9 -> V_116 . V_184 ) == V_188 )
goto V_93;
V_180 = F_93 ( V_2 , V_184 -> V_194 , V_188 ) ;
if ( ! F_94 ( V_180 ) ) {
F_30 ( V_2 , L_24 ) ;
goto V_93;
}
F_95 ( & V_2 -> V_77 -> V_195 ) ;
V_2 -> V_187 . V_196 = V_182 -> V_197 ;
V_9 -> V_198 . V_199 = F_96 ( V_182 ) ;
if ( V_9 -> V_198 . V_199 )
F_97 ( V_182 , V_9 ) ;
else
V_9 -> V_198 . V_200 = false ;
if ( ( F_92 ( V_9 -> V_201 . V_184 ) != V_188 ) )
V_9 -> V_201 . V_11 = 0 ;
F_98 ( V_2 , V_184 , V_9 ) ;
F_99 ( V_2 , V_186 ) ;
F_100 ( V_2 , V_9 , V_184 -> V_194 , V_9 -> V_88 ) ;
F_101 ( & V_2 -> V_77 -> V_195 ) ;
F_102 ( V_2 ) ;
F_26 ( V_190 , & V_2 -> V_77 -> V_80 ) ;
V_2 -> V_202 = F_103 ( V_188 ) ;
if ( F_2 ( V_2 ) -> V_191 -> V_192 ( V_2 , V_178 ) ) {
F_28 ( V_190 , & V_2 -> V_77 -> V_80 ) ;
V_2 -> V_202 = 0 ;
F_104 ( V_9 -> V_88 , false ) ;
}
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static void F_105 ( struct V_6 * V_7 ,
unsigned int V_203 ,
unsigned int * V_204 ,
T_4 V_205 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_5 V_206 = 0 , V_207 = 0 ;
struct V_8 * V_9 ;
#define F_106 ( T_6 , T_7 ) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
F_30 ( V_2 , L_25 ,
V_203 , * V_204 ) ;
F_106 ( V_208 | V_209 , V_210 ) ;
F_106 ( V_211 , V_212 | V_210 ) ;
F_106 ( V_213 , V_214 ) ;
#undef F_106
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_3 (priv, ctx) {
V_9 -> V_201 . V_215 &= ~ V_207 ;
V_9 -> V_201 . V_215 |= V_206 ;
}
F_32 ( & V_2 -> V_77 -> V_78 ) ;
* V_204 &= V_208 | V_216 | V_209 |
V_213 | V_211 ;
}
static void F_107 ( struct V_6 * V_7 , bool V_217 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_7 ) ;
if ( F_19 ( V_79 , & V_2 -> V_77 -> V_80 ) ) {
F_64 ( V_2 , L_26 ) ;
goto V_218;
}
if ( F_91 ( V_2 -> V_77 ) ) {
F_64 ( V_2 , L_27 ) ;
goto V_218;
}
if ( V_217 ) {
F_30 ( V_2 , L_28 ) ;
if ( F_108 ( V_2 , V_219 ) ) {
F_13 ( V_2 , L_29 ) ;
goto V_218;
}
}
F_30 ( V_2 , L_30 ) ;
F_109 ( F_7 ( V_2 ) ) ;
V_218:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_183 * V_184 ,
enum V_220 V_221 ,
int V_222 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_91 [ V_223 ] ;
int V_224 = 0 ;
if ( ! ( V_2 -> V_77 -> V_225 & F_5 ( V_223 ) ) )
return - V_132 ;
if ( ! ( V_9 -> V_30 & F_5 ( V_33 ) ) )
return - V_132 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_19 ( V_226 , & V_2 -> V_77 -> V_80 ) ) {
V_224 = - V_227 ;
goto V_93;
}
V_2 -> V_228 = V_184 ;
V_2 -> V_229 = V_221 ;
V_2 -> V_230 = F_111 ( 1000 * V_222 , 1024 ) ;
V_2 -> V_231 = false ;
F_112 ( & V_2 -> V_232 ) ;
if ( ! V_9 -> V_233 ) {
static const struct V_234 V_235 = {
. V_236 = {
. V_237 [ 0 ] = {
. V_238 = F_103 ( 3 ) ,
. V_239 = F_103 ( 7 ) ,
. V_240 = 2 ,
. V_241 = F_103 ( 1504 ) ,
} ,
. V_237 [ 1 ] = {
. V_238 = F_103 ( 7 ) ,
. V_239 = F_103 ( 15 ) ,
. V_240 = 2 ,
. V_241 = F_103 ( 3008 ) ,
} ,
. V_237 [ 2 ] = {
. V_238 = F_103 ( 15 ) ,
. V_239 = F_103 ( 1023 ) ,
. V_240 = 3 ,
} ,
. V_237 [ 3 ] = {
. V_238 = F_103 ( 15 ) ,
. V_239 = F_103 ( 1023 ) ,
. V_240 = 7 ,
} ,
} ,
} ;
V_9 -> V_233 = true ;
V_9 -> V_242 = V_235 ;
V_9 -> V_201 . V_243 = V_244 ;
memcpy ( V_9 -> V_201 . V_245 ,
V_2 -> V_91 [ V_92 ] . V_201 . V_245 ,
V_246 ) ;
memcpy ( V_9 -> V_201 . V_247 ,
V_2 -> V_91 [ V_92 ] . V_201 . V_245 ,
V_246 ) ;
V_224 = F_113 ( V_2 , V_9 ) ;
if ( V_224 )
goto V_93;
V_9 -> V_201 . V_215 |= V_248 |
V_210 |
V_212 ;
V_224 = F_113 ( V_2 , V_9 ) ;
if ( V_224 ) {
F_114 ( V_2 ) ;
goto V_93;
}
V_2 -> V_249 = true ;
}
V_224 = F_115 ( V_2 , V_9 -> V_88 , V_250 , V_184 -> V_194 ) ;
if ( V_224 )
F_114 ( V_2 ) ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_224 ;
}
static int F_116 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! ( V_2 -> V_77 -> V_225 & F_5 ( V_223 ) ) )
return - V_132 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_72 ( V_2 , V_2 -> V_230 ) ;
F_114 ( V_2 ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_117 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
const T_3 * V_251 ,
enum V_252 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
struct V_8 * V_9 = V_129 -> V_9 ;
int V_5 ;
T_3 V_173 ;
if ( V_9 -> V_253 != V_223 )
return 0 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_45 ( V_9 ) ) {
V_5 = 0 ;
goto V_93;
}
if ( V_9 -> V_254 || F_19 ( V_226 ,
& V_2 -> V_77 -> V_80 ) ) {
V_5 = - V_227 ;
goto V_93;
}
V_5 = F_88 ( V_2 , V_9 , V_251 , true , NULL , & V_173 ) ;
if ( V_5 )
goto V_93;
if ( F_34 ( V_173 != V_9 -> V_255 ) ) {
V_5 = - V_81 ;
goto V_256;
}
memcpy ( V_9 -> V_251 , V_251 , V_246 ) ;
V_9 -> V_254 = true ;
V_5 = F_113 ( V_2 , V_9 ) ;
if ( V_5 == 0 )
goto V_93;
V_256:
F_118 ( V_2 , V_173 , V_251 ) ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_119 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
const T_3 * V_251 ,
enum V_252 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
struct V_8 * V_9 = V_129 -> V_9 ;
if ( V_9 -> V_253 != V_223 )
return;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_45 ( V_9 ) )
goto V_93;
F_118 ( V_2 , V_9 -> V_255 , V_251 ) ;
V_9 -> V_254 = false ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static void F_120 ( struct V_6 * V_7 ,
enum V_257 V_258 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_2 ( V_2 ) -> V_259 &&
F_2 ( V_2 ) -> V_259 -> V_260 ) {
if ( V_258 == V_261 )
V_2 -> V_262 = true ;
else if ( V_258 == V_263 )
V_2 -> V_262 = false ;
F_121 ( V_2 ) ;
} else {
F_30 ( V_2 , L_31
L_32 ) ;
}
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_122 ( struct V_6 * V_7 ,
struct V_122 * V_123 , bool V_264 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_123 ( V_2 -> V_77 -> V_85 , & V_2 -> V_265 ) ;
return 0 ;
}
static int F_124 ( struct V_6 * V_7 ,
struct V_87 * V_88 , T_2 V_266 ,
const struct V_267 * V_268 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
struct V_8 * V_9 = V_129 -> V_9 ;
unsigned long V_11 ;
int V_269 ;
if ( F_34 ( ! V_9 ) )
return - V_102 ;
F_30 ( V_2 , L_7 ) ;
if ( ! F_125 ( V_2 -> V_77 ) ) {
F_30 ( V_2 , L_33 ) ;
return - V_81 ;
}
if ( V_266 >= V_270 ) {
F_30 ( V_2 , L_34 , V_266 ) ;
return 0 ;
}
V_269 = V_270 - 1 - V_266 ;
F_52 ( & V_2 -> V_77 -> V_195 , V_11 ) ;
V_9 -> V_242 . V_236 . V_237 [ V_269 ] . V_238 =
F_103 ( V_268 -> V_238 ) ;
V_9 -> V_242 . V_236 . V_237 [ V_269 ] . V_239 =
F_103 ( V_268 -> V_239 ) ;
V_9 -> V_242 . V_236 . V_237 [ V_269 ] . V_240 = V_268 -> V_271 ;
V_9 -> V_242 . V_236 . V_237 [ V_269 ] . V_241 =
F_103 ( ( V_268 -> V_272 * 32 ) ) ;
V_9 -> V_242 . V_236 . V_237 [ V_269 ] . V_273 = 0 ;
F_56 ( & V_2 -> V_77 -> V_195 , V_11 ) ;
F_30 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
return V_2 -> V_274 == V_275 ;
}
static int F_127 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_60 ( V_2 , V_9 ) ;
F_61 ( V_2 , V_9 ) ;
return F_113 ( V_2 , V_9 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_87 * V_88 = V_9 -> V_88 ;
int V_224 ;
F_18 ( & V_2 -> V_77 -> V_78 ) ;
V_2 -> V_276 = V_88 -> type ;
V_9 -> V_233 = true ;
V_224 = F_127 ( V_2 , V_9 ) ;
if ( V_224 ) {
if ( ! V_9 -> V_277 )
V_9 -> V_233 = false ;
return V_224 ;
}
if ( F_2 ( V_2 ) -> V_259 && F_2 ( V_2 ) -> V_259 -> V_260 &&
V_88 -> type == V_138 ) {
V_2 -> V_278 = V_279 ;
}
return 0 ;
}
static int F_129 ( struct V_6 * V_7 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_28 * V_129 = ( void * ) V_88 -> V_130 ;
struct V_8 * V_280 , * V_9 = NULL ;
int V_224 ;
enum V_281 V_282 = F_130 ( V_88 ) ;
F_30 ( V_2 , L_35 ,
V_282 , V_88 -> V_154 ) ;
F_131 ( & V_2 -> V_232 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_114 ( V_2 ) ;
if ( ! F_125 ( V_2 -> V_77 ) ) {
F_20 ( V_2 , L_36 ) ;
V_224 = - V_102 ;
goto V_93;
}
F_3 (priv, tmp) {
T_1 V_283 =
V_280 -> V_30 | V_280 -> V_31 ;
if ( V_280 -> V_88 ) {
if ( V_280 -> V_31 &
F_5 ( V_280 -> V_88 -> type ) ) {
V_224 = - V_102 ;
goto V_93;
}
continue;
}
if ( ! ( V_283 & F_5 ( V_282 ) ) )
continue;
V_9 = V_280 ;
break;
}
if ( ! V_9 ) {
V_224 = - V_132 ;
goto V_93;
}
V_129 -> V_9 = V_9 ;
V_9 -> V_88 = V_88 ;
V_224 = F_128 ( V_2 , V_9 ) ;
if ( ! V_224 )
goto V_93;
V_9 -> V_88 = NULL ;
V_2 -> V_276 = V_103 ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_224 ;
}
static void F_132 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
bool V_284 )
{
struct V_8 * V_9 = F_84 ( V_88 ) ;
F_18 ( & V_2 -> V_77 -> V_78 ) ;
if ( V_2 -> V_285 == V_88 ) {
F_72 ( V_2 , 200 ) ;
F_133 ( V_2 ) ;
}
if ( ! V_284 ) {
F_127 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_277 )
V_9 -> V_233 = false ;
}
if ( V_88 -> type == V_138 )
V_2 -> V_278 = V_2 -> V_286 ;
}
static void F_134 ( struct V_6 * V_7 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_84 ( V_88 ) ;
F_30 ( V_2 , L_7 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( F_34 ( V_9 -> V_88 != V_88 ) ) {
struct V_8 * V_280 ;
F_13 ( V_2 , L_37 , V_9 -> V_88 , V_88 ) ;
F_3 (priv, tmp)
F_13 ( V_2 , L_38 ,
V_280 -> V_253 , V_280 , V_280 -> V_88 ) ;
}
V_9 -> V_88 = NULL ;
F_132 ( V_2 , V_88 , false ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
}
static int F_135 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
enum V_281 V_287 , bool V_288 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_84 ( V_88 ) ;
struct V_8 * V_289 = & V_2 -> V_91 [ V_92 ] ;
struct V_8 * V_280 ;
enum V_281 V_290 = V_287 ;
T_1 V_30 ;
int V_224 ;
F_30 ( V_2 , L_7 ) ;
V_287 = F_136 ( V_287 , V_288 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( ! V_9 -> V_88 || ! F_125 ( V_2 -> V_77 ) ) {
V_224 = - V_227 ;
goto V_93;
}
V_30 = V_9 -> V_30 | V_9 -> V_31 ;
if ( ! ( V_30 & F_5 ( V_287 ) ) ) {
V_224 = - V_227 ;
goto V_93;
}
if ( V_9 -> V_253 == V_223 && ! V_289 -> V_88 &&
( V_289 -> V_30 & F_5 ( V_287 ) ||
V_289 -> V_31 & F_5 ( V_287 ) ) ) {
F_4 ( V_32 != 2 ) ;
V_224 = - V_227 ;
goto V_93;
}
if ( V_9 -> V_31 & F_5 ( V_287 ) ) {
F_3 (priv, tmp) {
if ( V_9 == V_280 )
continue;
if ( ! V_280 -> V_88 )
continue;
V_224 = - V_227 ;
goto V_93;
}
}
F_132 ( V_2 , V_88 , true ) ;
V_88 -> type = V_290 ;
V_88 -> V_291 = V_288 ;
V_224 = F_128 ( V_2 , V_9 ) ;
F_34 ( V_224 ) ;
V_224 = 0 ;
V_93:
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_224 ;
}
static int F_137 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
struct V_292 * V_293 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_5 ;
F_30 ( V_2 , L_7 ) ;
if ( V_293 -> V_73 == 0 )
return - V_102 ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
if ( V_2 -> V_294 != V_295 ) {
F_138 ( V_2 ,
L_39 ) ;
V_2 -> V_296 = V_293 ;
V_2 -> V_285 = V_88 ;
V_5 = 0 ;
} else {
V_2 -> V_296 = V_293 ;
V_2 -> V_285 = V_88 ;
V_5 = F_115 ( V_2 , V_88 , V_295 ,
V_293 -> V_297 [ 0 ] -> V_194 ) ;
if ( V_5 ) {
V_2 -> V_296 = NULL ;
V_2 -> V_285 = NULL ;
}
}
F_30 ( V_2 , L_9 ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
return V_5 ;
}
static int F_139 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_26 * V_153 = ( void * ) V_123 -> V_130 ;
int V_5 ;
F_30 ( V_2 , L_40
L_41 , V_123 -> V_154 ) ;
F_31 ( & V_2 -> V_77 -> V_78 ) ;
F_33 ( V_2 , L_42 ,
V_123 -> V_154 ) ;
V_5 = F_118 ( V_2 , V_153 -> V_173 , V_123 -> V_154 ) ;
if ( V_5 )
F_140 ( V_2 , L_43 ,
V_123 -> V_154 ) ;
F_32 ( & V_2 -> V_77 -> V_78 ) ;
F_30 ( V_2 , L_9 ) ;
return V_5 ;
}
static void F_141 ( struct V_1 * V_2 , int V_173 )
{
unsigned long V_11 ;
F_52 ( & V_2 -> V_77 -> V_298 , V_11 ) ;
V_2 -> V_299 [ V_173 ] . V_123 . V_300 &= ~ V_301 ;
V_2 -> V_299 [ V_173 ] . V_123 . V_302 = V_301 ;
V_2 -> V_299 [ V_173 ] . V_123 . V_123 . V_303 = 0 ;
V_2 -> V_299 [ V_173 ] . V_123 . V_304 = 0 ;
V_2 -> V_299 [ V_173 ] . V_123 . V_305 = V_306 ;
F_142 ( V_2 , & V_2 -> V_299 [ V_173 ] . V_123 , V_170 ) ;
F_56 ( & V_2 -> V_77 -> V_298 , V_11 ) ;
}
static void F_143 ( struct V_6 * V_7 ,
struct V_87 * V_88 ,
enum V_307 V_127 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_26 * V_153 = ( void * ) V_123 -> V_130 ;
int V_173 ;
F_30 ( V_2 , L_7 ) ;
switch ( V_127 ) {
case V_308 :
F_34 ( ! V_153 -> V_176 ) ;
V_153 -> V_309 = true ;
if ( F_144 ( & V_153 -> V_175 ) > 0 )
F_145 ( V_7 , V_123 , true ) ;
break;
case V_310 :
F_34 ( ! V_153 -> V_176 ) ;
if ( ! V_153 -> V_309 )
break;
V_153 -> V_309 = false ;
V_173 = F_146 ( V_123 ) ;
if ( V_173 != V_174 )
F_141 ( V_2 , V_173 ) ;
break;
default:
break;
}
F_30 ( V_2 , L_9 ) ;
}
struct V_6 * F_147 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_7 = F_148 ( sizeof( struct V_1 ) , & V_311 ) ;
if ( ! V_7 )
goto V_93;
V_2 = V_7 -> V_2 ;
V_2 -> V_7 = V_7 ;
V_93:
return V_7 ;
}
