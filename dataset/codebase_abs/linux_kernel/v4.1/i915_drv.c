void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = NULL ;
if ( F_2 ( V_2 ) -> V_8 == 0 ) {
V_4 -> V_9 = V_10 ;
return;
}
while ( ( V_7 = F_3 ( V_11 << 8 , V_7 ) ) ) {
if ( V_7 -> V_12 == V_13 ) {
unsigned short V_14 = V_7 -> V_15 & V_16 ;
V_4 -> V_17 = V_14 ;
if ( V_14 == V_18 ) {
V_4 -> V_9 = V_19 ;
F_4 ( L_1 ) ;
F_5 ( ! F_6 ( V_2 ) ) ;
} else if ( V_14 == V_20 ) {
V_4 -> V_9 = V_21 ;
F_4 ( L_2 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_14 == V_22 ) {
V_4 -> V_9 = V_21 ;
F_4 ( L_3 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_14 == V_23 ) {
V_4 -> V_9 = V_24 ;
F_4 ( L_4 ) ;
F_5 ( ! F_9 ( V_2 ) && ! F_10 ( V_2 ) ) ;
F_5 ( F_11 ( V_2 ) || F_12 ( V_2 ) ) ;
} else if ( V_14 == V_25 ) {
V_4 -> V_9 = V_24 ;
F_4 ( L_5 ) ;
F_5 ( ! F_9 ( V_2 ) && ! F_10 ( V_2 ) ) ;
F_5 ( ! F_11 ( V_2 ) && ! F_12 ( V_2 ) ) ;
} else if ( V_14 == V_26 ) {
V_4 -> V_9 = V_27 ;
F_4 ( L_6 ) ;
F_5 ( ! F_13 ( V_2 ) ) ;
} else if ( V_14 == V_28 ) {
V_4 -> V_9 = V_27 ;
F_4 ( L_7 ) ;
F_5 ( ! F_13 ( V_2 ) ) ;
} else
continue;
break;
}
}
if ( ! V_7 )
F_4 ( L_8 ) ;
F_14 ( V_7 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_29 < 6 )
return false ;
if ( V_30 . V_31 >= 0 )
return V_30 . V_31 ;
if ( V_30 . V_32 )
return false ;
if ( F_16 ( V_2 ) )
return false ;
#ifdef F_17
if ( F_2 ( V_2 ) -> V_29 == 6 && V_33 )
return false ;
#endif
return true ;
}
void F_18 ( struct V_3 * V_4 )
{
F_19 ( & V_4 -> V_34 ) ;
V_4 -> V_35 = 0 ;
V_4 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
F_20 ( & V_4 -> V_34 ) ;
F_21 ( & V_4 -> V_38 ) ;
F_21 ( & V_4 -> V_39 ) ;
F_22 ( & V_4 -> V_40 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_41 * V_42 ;
F_24 ( V_2 ) ;
F_25 (encoder, &dev->mode_config.encoder_list, head) {
struct V_43 * V_43 = F_26 ( V_42 ) ;
if ( V_43 -> V_44 )
V_43 -> V_44 ( V_43 ) ;
}
F_27 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_45 * V_46 ;
T_1 V_47 ;
int error ;
F_29 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = V_50 ;
F_30 ( & V_4 -> V_48 ) ;
F_31 ( V_4 , true ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_51 ) ;
error = F_34 ( V_2 ) ;
if ( error ) {
F_35 ( & V_2 -> V_51 -> V_2 ,
L_9 ) ;
return error ;
}
F_36 ( V_2 ) ;
F_24 ( V_2 ) ;
F_37 (dev, crtc)
F_38 ( V_46 , false ) ;
F_27 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_4 ) ;
F_18 ( V_4 ) ;
F_23 ( V_4 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
V_47 = V_52 ;
#if F_44 ( V_53 )
if ( F_45 () < V_54 )
V_47 = V_55 ;
#endif
F_46 ( V_2 , V_47 ) ;
F_47 ( V_2 , false ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 , V_56 , true ) ;
V_4 -> V_57 ++ ;
F_31 ( V_4 , false ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_58 , bool V_59 )
{
struct V_3 * V_4 = V_58 -> V_5 ;
int V_60 ;
V_60 = F_51 ( V_4 ) ;
if ( V_60 ) {
F_52 ( L_10 , V_60 ) ;
return V_60 ;
}
F_53 ( V_58 -> V_51 ) ;
if ( ! ( V_59 &&
V_58 -> V_51 -> V_61 == V_62 &&
F_2 ( V_4 ) -> V_29 == 4 ) )
F_54 ( V_58 -> V_51 , V_63 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , T_2 V_64 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_52 ( L_11 , V_2 ) ;
F_52 ( L_12 ) ;
return - V_65 ;
}
if ( F_56 ( V_64 . V_66 != V_67 &&
V_64 . V_66 != V_68 ) )
return - V_69 ;
if ( V_2 -> V_70 == V_71 )
return 0 ;
error = F_28 ( V_2 ) ;
if ( error )
return error ;
return F_50 ( V_2 , false ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_29 ( & V_2 -> V_72 ) ;
F_58 ( V_2 ) ;
F_30 ( & V_2 -> V_72 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_4 ) ;
F_29 ( & V_2 -> V_72 ) ;
if ( F_64 ( V_2 ) ) {
F_52 ( L_13 ) ;
F_65 ( V_73 , & V_4 -> V_74 . V_75 ) ;
}
F_30 ( & V_2 -> V_72 ) ;
F_66 ( V_2 ) ;
F_19 ( & V_4 -> V_34 ) ;
if ( V_4 -> V_76 . V_77 )
V_4 -> V_76 . V_77 ( V_2 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_24 ( V_2 ) ;
F_67 ( V_2 , true ) ;
F_27 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_4 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_49 ( V_2 , V_78 , false ) ;
F_29 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = V_79 ;
F_30 ( & V_4 -> V_48 ) ;
F_46 ( V_2 , V_80 ) ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 = 0 ;
if ( F_74 ( V_2 -> V_51 ) )
return - V_81 ;
F_75 ( V_2 -> V_51 ) ;
if ( F_76 ( V_4 ) )
V_60 = F_77 ( V_4 , false ) ;
if ( V_60 )
F_52 ( L_14 , V_60 ) ;
F_78 ( V_2 , true ) ;
if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_79 ( V_4 ) ;
F_80 ( V_2 ) ;
F_81 ( V_4 ) ;
return V_60 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_60 ;
if ( V_2 -> V_70 == V_71 )
return 0 ;
V_60 = F_73 ( V_2 ) ;
if ( V_60 )
return V_60 ;
return F_57 ( V_2 ) ;
}
int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_82 ;
int V_60 ;
if ( ! V_30 . V_83 )
return 0 ;
F_84 ( V_2 ) ;
F_29 ( & V_2 -> V_72 ) ;
F_85 ( V_2 ) ;
V_82 = V_4 -> V_74 . V_84 != 0 ;
V_60 = F_86 ( V_2 ) ;
if ( V_82 ) {
F_87 ( L_15 ) ;
V_4 -> V_74 . V_84 = 0 ;
if ( V_60 == - V_65 ) {
F_87 ( L_16
L_17 ) ;
V_60 = 0 ;
}
}
if ( F_88 ( V_4 ) )
F_89 ( L_18 ) ;
if ( V_60 ) {
F_52 ( L_19 , V_60 ) ;
F_30 ( & V_2 -> V_72 ) ;
return V_60 ;
}
F_90 ( V_4 ) ;
V_4 -> V_74 . V_85 = true ;
V_60 = F_64 ( V_2 ) ;
V_4 -> V_74 . V_85 = false ;
F_30 ( & V_2 -> V_72 ) ;
if ( V_60 ) {
F_52 ( L_20 , V_60 ) ;
return V_60 ;
}
if ( F_2 ( V_2 ) -> V_29 > 5 )
F_91 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_6 * V_51 , const struct V_86 * V_87 )
{
struct V_88 * V_89 =
(struct V_88 * ) V_87 -> V_90 ;
if ( F_93 ( V_89 ) && ! V_30 . V_91 ) {
F_87 ( L_21
L_22 ) ;
return - V_65 ;
}
if ( F_94 ( V_51 -> V_92 ) )
return - V_65 ;
V_93 . V_94 &= ~ ( V_95 ) ;
return F_95 ( V_51 , V_87 , & V_93 ) ;
}
static void
F_96 ( struct V_6 * V_51 )
{
struct V_1 * V_2 = F_97 ( V_51 ) ;
F_98 ( V_2 ) ;
}
static int F_99 ( struct V_15 * V_2 )
{
struct V_6 * V_51 = F_100 ( V_2 ) ;
struct V_1 * V_58 = F_97 ( V_51 ) ;
if ( ! V_58 || ! V_58 -> V_5 ) {
F_35 ( V_2 , L_12 ) ;
return - V_65 ;
}
if ( V_58 -> V_70 == V_71 )
return 0 ;
return F_28 ( V_58 ) ;
}
static int F_101 ( struct V_15 * V_2 )
{
struct V_1 * V_58 = F_102 ( V_2 ) -> V_2 ;
if ( V_58 -> V_70 == V_71 )
return 0 ;
return F_50 ( V_58 , false ) ;
}
static int F_103 ( struct V_15 * V_2 )
{
struct V_1 * V_58 = F_102 ( V_2 ) -> V_2 ;
if ( V_58 -> V_70 == V_71 )
return 0 ;
return F_50 ( V_58 , true ) ;
}
static int F_104 ( struct V_15 * V_2 )
{
struct V_1 * V_58 = F_102 ( V_2 ) -> V_2 ;
if ( V_58 -> V_70 == V_71 )
return 0 ;
return F_73 ( V_58 ) ;
}
static int F_105 ( struct V_15 * V_2 )
{
struct V_1 * V_58 = F_102 ( V_2 ) -> V_2 ;
if ( V_58 -> V_70 == V_71 )
return 0 ;
return F_57 ( V_58 ) ;
}
static int F_106 ( struct V_3 * V_4 )
{
F_107 ( V_4 ) ;
return 0 ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_96 * V_97 = & V_4 -> V_96 ;
int V_98 ;
V_97 -> V_99 = F_109 ( V_100 ) ;
V_97 -> V_101 = F_109 ( V_102 ) ;
V_97 -> V_103 = F_109 ( V_104 ) ;
V_97 -> V_105 = F_109 ( V_106 ) ;
V_97 -> V_107 = F_109 ( V_108 ) ;
for ( V_98 = 0 ; V_98 < F_110 ( V_97 -> V_109 ) ; V_98 ++ )
V_97 -> V_109 [ V_98 ] = F_109 ( V_110 + V_98 * 4 ) ;
V_97 -> V_111 = F_109 ( V_112 ) ;
V_97 -> V_113 = F_109 ( V_114 ) ;
V_97 -> V_115 = F_109 ( V_116 ) ;
V_97 -> V_117 = F_109 ( V_118 ) ;
V_97 -> V_119 = F_109 ( V_120 ) ;
V_97 -> V_121 = F_109 ( V_122 ) ;
V_97 -> V_123 = F_109 ( V_124 ) ;
V_97 -> V_125 = F_109 ( V_126 ) ;
V_97 -> V_127 = F_109 ( V_128 ) ;
V_97 -> V_129 = F_109 ( V_130 ) ;
V_97 -> V_131 = F_109 ( V_132 ) ;
V_97 -> V_133 = F_109 ( V_134 ) ;
V_97 -> V_135 = F_109 ( V_136 ) ;
V_97 -> V_137 = F_109 ( V_138 ) ;
V_97 -> V_139 = F_109 ( V_140 ) ;
V_97 -> V_141 = F_109 ( V_142 ) ;
V_97 -> V_143 = F_109 ( V_144 ) ;
V_97 -> V_145 = F_109 ( V_146 ) ;
V_97 -> V_147 = F_109 ( V_148 ) ;
V_97 -> V_149 = F_109 ( V_150 ) ;
V_97 -> V_151 = F_109 ( V_152 ) ;
V_97 -> V_153 = F_109 ( V_154 ) ;
V_97 -> V_155 = F_109 ( V_156 ) ;
V_97 -> V_157 = F_109 ( V_158 ) ;
V_97 -> V_159 = F_109 ( V_160 ) ;
V_97 -> V_161 = F_109 ( V_162 ) ;
V_97 -> V_163 = F_109 ( V_164 ) ;
V_97 -> V_165 = F_109 ( V_166 ) ;
V_97 -> V_167 = F_109 ( V_168 ) ;
V_97 -> V_169 = F_109 ( V_170 ) ;
for ( V_98 = 0 ; V_98 < F_110 ( V_97 -> V_171 ) ; V_98 ++ )
V_97 -> V_171 [ V_98 ] = F_109 ( V_172 + V_98 * 4 ) ;
V_97 -> V_173 = F_109 ( V_174 ) ;
V_97 -> V_175 = F_109 ( V_176 ) ;
V_97 -> V_177 = F_109 ( V_178 ) ;
V_97 -> V_179 = F_109 ( V_180 ) ;
V_97 -> V_181 = F_109 ( V_182 ) ;
V_97 -> V_183 = F_109 ( V_184 ) ;
V_97 -> V_185 = F_109 ( V_186 ) ;
V_97 -> V_187 = F_109 ( V_188 ) ;
V_97 -> V_189 = F_109 ( V_190 ) ;
}
static void F_111 ( struct V_3 * V_4 )
{
struct V_96 * V_97 = & V_4 -> V_96 ;
T_3 V_191 ;
int V_98 ;
F_112 ( V_100 , V_97 -> V_99 ) ;
F_112 ( V_102 , V_97 -> V_101 ) ;
F_112 ( V_104 , V_97 -> V_103 | ( 0xffff << 16 ) ) ;
F_112 ( V_106 , V_97 -> V_105 ) ;
F_112 ( V_108 , V_97 -> V_107 ) ;
for ( V_98 = 0 ; V_98 < F_110 ( V_97 -> V_109 ) ; V_98 ++ )
F_112 ( V_110 + V_98 * 4 , V_97 -> V_109 [ V_98 ] ) ;
F_112 ( V_112 , V_97 -> V_111 ) ;
F_112 ( V_114 , V_97 -> V_113 ) ;
F_112 ( V_116 , V_97 -> V_115 ) ;
F_112 ( V_118 , V_97 -> V_117 ) ;
F_112 ( V_120 , V_97 -> V_119 ) ;
F_112 ( V_122 , V_97 -> V_121 ) ;
F_112 ( V_124 , V_97 -> V_123 ) ;
F_112 ( V_126 , V_97 -> V_125 ) ;
F_112 ( V_128 , V_97 -> V_127 ) ;
F_112 ( V_130 , V_97 -> V_129 ) ;
F_112 ( V_132 , V_97 -> V_131 ) ;
F_112 ( V_134 , V_97 -> V_133 ) ;
F_112 ( V_136 , V_97 -> V_135 ) ;
F_112 ( V_138 , V_97 -> V_137 ) ;
F_112 ( V_140 , V_97 -> V_139 ) ;
F_112 ( V_142 , V_97 -> V_141 ) ;
F_112 ( V_144 , V_97 -> V_143 ) ;
F_112 ( V_146 , V_97 -> V_145 ) ;
F_112 ( V_148 , V_97 -> V_147 ) ;
F_112 ( V_150 , V_97 -> V_149 ) ;
F_112 ( V_152 , V_97 -> V_151 ) ;
F_112 ( V_154 , V_97 -> V_153 ) ;
F_112 ( V_156 , V_97 -> V_155 ) ;
F_112 ( V_158 , V_97 -> V_157 ) ;
F_112 ( V_160 , V_97 -> V_159 ) ;
F_112 ( V_162 , V_97 -> V_161 ) ;
F_112 ( V_164 , V_97 -> V_163 ) ;
F_112 ( V_166 , V_97 -> V_165 ) ;
F_112 ( V_168 , V_97 -> V_167 ) ;
F_112 ( V_170 , V_97 -> V_169 ) ;
for ( V_98 = 0 ; V_98 < F_110 ( V_97 -> V_171 ) ; V_98 ++ )
F_112 ( V_172 + V_98 * 4 , V_97 -> V_171 [ V_98 ] ) ;
F_112 ( V_174 , V_97 -> V_173 ) ;
F_112 ( V_176 , V_97 -> V_175 ) ;
V_191 = F_109 ( V_178 ) ;
V_191 &= V_192 ;
V_191 |= V_97 -> V_177 & ~ V_192 ;
F_112 ( V_178 , V_191 ) ;
V_191 = F_109 ( V_180 ) ;
V_191 &= V_193 ;
V_191 |= V_97 -> V_179 & ~ V_193 ;
F_112 ( V_180 , V_191 ) ;
F_112 ( V_182 , V_97 -> V_181 ) ;
F_112 ( V_184 , V_97 -> V_183 ) ;
F_112 ( V_186 , V_97 -> V_185 ) ;
F_112 ( V_188 , V_97 -> V_187 ) ;
F_112 ( V_190 , V_97 -> V_189 ) ;
}
int F_113 ( struct V_3 * V_4 , bool V_194 )
{
T_3 V_191 ;
int V_195 ;
#define F_114 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_191 = F_109 ( V_180 ) ;
V_191 &= ~ V_193 ;
if ( V_194 )
V_191 |= V_193 ;
F_112 ( V_180 , V_191 ) ;
if ( ! V_194 )
return 0 ;
V_195 = F_115 ( F_114 , 20 ) ;
if ( V_195 )
F_52 ( L_23 ,
F_109 ( V_180 ) ) ;
return V_195 ;
#undef F_114
}
static int F_116 ( struct V_3 * V_4 , bool V_196 )
{
T_3 V_191 ;
int V_195 = 0 ;
V_191 = F_109 ( V_178 ) ;
V_191 &= ~ V_192 ;
if ( V_196 )
V_191 |= V_192 ;
F_112 ( V_178 , V_191 ) ;
F_117 ( V_178 ) ;
#define F_114 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_195 = F_115 ( F_114 , 1 ) ;
if ( V_195 )
F_52 ( L_24 ) ;
return V_195 ;
#undef F_114
}
static int F_118 ( struct V_3 * V_4 ,
bool V_197 )
{
T_3 V_198 ;
T_3 V_191 ;
int V_195 ;
V_198 = V_199 | V_200 ;
V_191 = V_197 ? V_198 : 0 ;
#define F_114 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_114 )
return 0 ;
F_4 ( L_25 ,
V_197 ? L_26 : L_27 ,
F_109 ( V_201 ) ) ;
V_195 = F_115 ( F_114 , 3 ) ;
if ( V_195 )
F_52 ( L_28 ,
V_197 ? L_26 : L_27 ) ;
return V_195 ;
#undef F_114
}
static void F_119 ( struct V_3 * V_4 )
{
if ( ! ( F_109 ( V_201 ) & V_202 ) )
return;
F_52 ( L_29 ) ;
F_112 ( V_201 , V_202 ) ;
}
static int F_120 ( struct V_3 * V_4 )
{
T_3 V_198 ;
int V_195 ;
( void ) F_118 ( V_4 , false ) ;
V_198 = V_203 | V_204 ;
F_5 ( ( F_109 ( V_178 ) & V_198 ) != V_198 ) ;
F_119 ( V_4 ) ;
V_195 = F_113 ( V_4 , true ) ;
if ( V_195 )
goto V_205;
V_195 = F_116 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
if ( ! F_121 ( V_4 -> V_2 ) )
F_108 ( V_4 ) ;
V_195 = F_113 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
return 0 ;
V_206:
F_116 ( V_4 , true ) ;
V_205:
F_113 ( V_4 , false ) ;
return V_195 ;
}
static int F_77 ( struct V_3 * V_4 ,
bool V_207 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_195 ;
int V_60 ;
V_60 = F_113 ( V_4 , true ) ;
if ( ! F_121 ( V_4 -> V_2 ) )
F_111 ( V_4 ) ;
V_195 = F_116 ( V_4 , true ) ;
if ( ! V_60 )
V_60 = V_195 ;
V_195 = F_113 ( V_4 , false ) ;
if ( ! V_60 )
V_60 = V_195 ;
F_119 ( V_4 ) ;
if ( V_207 ) {
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
}
return V_60 ;
}
static int F_124 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_100 ( V_15 ) ;
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 ;
if ( F_56 ( ! ( V_4 -> V_208 . V_209 && F_125 ( V_2 ) ) ) )
return - V_65 ;
if ( F_56 ( ! F_126 ( V_2 ) ) )
return - V_65 ;
F_4 ( L_30 ) ;
if ( ! F_127 ( & V_2 -> V_72 ) ) {
F_4 ( L_31 ) ;
F_128 ( V_15 ) ;
return - V_210 ;
}
F_129 ( V_4 ) ;
F_30 ( & V_2 -> V_72 ) ;
F_36 ( V_2 ) ;
F_40 ( V_4 ) ;
V_60 = F_51 ( V_4 ) ;
if ( V_60 ) {
F_52 ( L_32 , V_60 ) ;
F_63 ( V_4 ) ;
return V_60 ;
}
F_22 ( & V_4 -> V_74 . V_211 ) ;
F_47 ( V_2 , false ) ;
V_4 -> V_212 . V_213 = true ;
if ( F_9 ( V_2 ) ) {
F_46 ( V_2 , V_55 ) ;
} else {
F_46 ( V_2 , V_63 ) ;
}
F_130 ( V_4 ) ;
F_4 ( L_33 ) ;
return 0 ;
}
static int F_131 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_100 ( V_15 ) ;
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 = 0 ;
if ( F_56 ( ! F_126 ( V_2 ) ) )
return - V_65 ;
F_4 ( L_34 ) ;
F_46 ( V_2 , V_80 ) ;
V_4 -> V_212 . V_213 = false ;
if ( F_7 ( V_4 ) )
F_61 ( V_2 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_79 ( V_4 ) ;
else if ( F_76 ( V_4 ) )
V_60 = F_77 ( V_4 , true ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
F_63 ( V_4 ) ;
F_91 ( V_2 ) ;
if ( V_60 )
F_52 ( L_35 , V_60 ) ;
else
F_4 ( L_36 ) ;
return V_60 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_60 ;
if ( F_9 ( V_2 ) || F_10 ( V_2 ) )
V_60 = F_106 ( V_4 ) ;
else if ( F_76 ( V_2 ) )
V_60 = F_120 ( V_4 ) ;
else
V_60 = 0 ;
return V_60 ;
}
static int T_4 F_134 ( void )
{
V_93 . V_214 = V_215 ;
#if F_135 ( V_216 )
if ( V_30 . V_217 != 0 )
V_93 . V_94 |= V_218 ;
#endif
if ( V_30 . V_217 == 1 )
V_93 . V_94 |= V_218 ;
#ifdef F_136
if ( F_137 () && V_30 . V_217 == - 1 )
V_93 . V_94 &= ~ V_218 ;
#endif
if ( ! ( V_93 . V_94 & V_218 ) ) {
V_93 . V_219 = NULL ;
F_138 ( L_37 ) ;
return 0 ;
}
if ( V_30 . V_220 )
V_93 . V_94 |= V_221 ;
return F_139 ( & V_93 , & V_222 ) ;
}
static void T_5 F_140 ( void )
{
if ( ! ( V_93 . V_94 & V_218 ) )
return;
F_141 ( & V_93 , & V_222 ) ;
}
