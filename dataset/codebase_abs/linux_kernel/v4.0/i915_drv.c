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
F_29 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = V_50 ;
F_30 ( & V_4 -> V_48 ) ;
F_31 ( V_4 , true ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 -> V_51 ) ;
if ( F_34 ( V_2 , V_52 ) ) {
int error ;
error = F_35 ( V_2 ) ;
if ( error ) {
F_36 ( & V_2 -> V_51 -> V_2 ,
L_9 ) ;
return error ;
}
F_37 ( V_2 ) ;
F_24 ( V_2 ) ;
F_38 (dev, crtc)
F_39 ( V_46 , false ) ;
F_27 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_4 ) ;
F_18 ( V_4 ) ;
F_23 ( V_4 ) ;
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
V_47 = V_53 ;
#if F_45 ( V_54 )
if ( F_46 () < V_55 )
V_47 = V_56 ;
#endif
F_47 ( V_2 , V_47 ) ;
F_48 ( V_2 , false ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 , V_57 , true ) ;
V_4 -> V_58 ++ ;
F_31 ( V_4 , false ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_59 , bool V_60 )
{
struct V_3 * V_4 = V_59 -> V_5 ;
int V_61 ;
V_61 = F_52 ( V_4 ) ;
if ( V_61 ) {
F_53 ( L_10 , V_61 ) ;
return V_61 ;
}
F_54 ( V_59 -> V_51 ) ;
if ( ! ( V_60 &&
V_59 -> V_51 -> V_62 == V_63 &&
F_2 ( V_4 ) -> V_29 == 4 ) )
F_55 ( V_59 -> V_51 , V_64 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , T_2 V_65 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_53 ( L_11 , V_2 ) ;
F_53 ( L_12 ) ;
return - V_66 ;
}
if ( F_57 ( V_65 . V_67 != V_68 &&
V_65 . V_67 != V_69 ) )
return - V_70 ;
if ( V_2 -> V_71 == V_72 )
return 0 ;
error = F_28 ( V_2 ) ;
if ( error )
return error ;
return F_51 ( V_2 , false ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_34 ( V_2 , V_52 ) ) {
F_29 ( & V_2 -> V_73 ) ;
F_59 ( V_2 ) ;
F_30 ( & V_2 -> V_73 ) ;
}
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( F_34 ( V_2 , V_52 ) ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_29 ( & V_2 -> V_73 ) ;
if ( F_64 ( V_2 ) ) {
F_53 ( L_13 ) ;
F_65 ( V_74 , & V_4 -> V_75 . V_76 ) ;
}
F_30 ( & V_2 -> V_73 ) ;
F_66 ( V_4 ) ;
F_67 ( V_2 ) ;
F_19 ( & V_4 -> V_34 ) ;
if ( V_4 -> V_77 . V_78 )
V_4 -> V_77 . V_78 ( V_2 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_24 ( V_2 ) ;
F_68 ( V_2 , true ) ;
F_27 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_4 ) ;
F_71 ( V_2 ) ;
}
F_72 ( V_2 ) ;
F_50 ( V_2 , V_79 , false ) ;
F_29 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = V_80 ;
F_30 ( & V_4 -> V_48 ) ;
F_47 ( V_2 , V_81 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_61 = 0 ;
if ( F_75 ( V_2 -> V_51 ) )
return - V_82 ;
F_76 ( V_2 -> V_51 ) ;
if ( F_77 ( V_4 ) )
V_61 = F_78 ( V_4 , false ) ;
if ( V_61 )
F_53 ( L_14 , V_61 ) ;
F_79 ( V_2 , true ) ;
if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_80 ( V_4 ) ;
F_81 ( V_2 ) ;
F_82 ( V_4 ) ;
return V_61 ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_61 ;
if ( V_2 -> V_71 == V_72 )
return 0 ;
V_61 = F_74 ( V_2 ) ;
if ( V_61 )
return V_61 ;
return F_58 ( V_2 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_83 ;
int V_61 ;
if ( ! V_30 . V_84 )
return 0 ;
F_85 ( V_2 ) ;
F_29 ( & V_2 -> V_73 ) ;
F_86 ( V_2 ) ;
V_83 = V_4 -> V_75 . V_85 != 0 ;
V_61 = F_87 ( V_2 ) ;
if ( V_83 ) {
F_88 ( L_15 ) ;
V_4 -> V_75 . V_85 = 0 ;
if ( V_61 == - V_66 ) {
F_88 ( L_16
L_17 ) ;
V_61 = 0 ;
}
}
if ( F_89 ( V_4 ) )
F_90 ( L_18 ) ;
if ( V_61 ) {
F_53 ( L_19 , V_61 ) ;
F_30 ( & V_2 -> V_73 ) ;
return V_61 ;
}
F_91 ( V_4 ) ;
if ( F_34 ( V_2 , V_52 ) ) {
V_4 -> V_75 . V_86 = true ;
V_61 = F_64 ( V_2 ) ;
V_4 -> V_75 . V_86 = false ;
F_30 ( & V_2 -> V_73 ) ;
if ( V_61 ) {
F_53 ( L_20 , V_61 ) ;
return V_61 ;
}
if ( F_2 ( V_2 ) -> V_29 > 5 )
F_92 ( V_2 ) ;
} else {
F_30 ( & V_2 -> V_73 ) ;
}
return 0 ;
}
static int F_93 ( struct V_6 * V_51 , const struct V_87 * V_88 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_88 -> V_91 ;
if ( F_94 ( V_90 ) && ! V_30 . V_92 ) {
F_88 ( L_21
L_22 ) ;
return - V_66 ;
}
if ( F_95 ( V_51 -> V_93 ) )
return - V_66 ;
V_94 . V_95 &= ~ ( V_96 ) ;
return F_96 ( V_51 , V_88 , & V_94 ) ;
}
static void
F_97 ( struct V_6 * V_51 )
{
struct V_1 * V_2 = F_98 ( V_51 ) ;
F_99 ( V_2 ) ;
}
static int F_100 ( struct V_15 * V_2 )
{
struct V_6 * V_51 = F_101 ( V_2 ) ;
struct V_1 * V_59 = F_98 ( V_51 ) ;
if ( ! V_59 || ! V_59 -> V_5 ) {
F_36 ( V_2 , L_12 ) ;
return - V_66 ;
}
if ( V_59 -> V_71 == V_72 )
return 0 ;
return F_28 ( V_59 ) ;
}
static int F_102 ( struct V_15 * V_2 )
{
struct V_1 * V_59 = F_103 ( V_2 ) -> V_2 ;
if ( V_59 -> V_71 == V_72 )
return 0 ;
return F_51 ( V_59 , false ) ;
}
static int F_104 ( struct V_15 * V_2 )
{
struct V_1 * V_59 = F_103 ( V_2 ) -> V_2 ;
if ( V_59 -> V_71 == V_72 )
return 0 ;
return F_51 ( V_59 , true ) ;
}
static int F_105 ( struct V_15 * V_2 )
{
struct V_1 * V_59 = F_103 ( V_2 ) -> V_2 ;
if ( V_59 -> V_71 == V_72 )
return 0 ;
return F_74 ( V_59 ) ;
}
static int F_106 ( struct V_15 * V_2 )
{
struct V_1 * V_59 = F_103 ( V_2 ) -> V_2 ;
if ( V_59 -> V_71 == V_72 )
return 0 ;
return F_58 ( V_59 ) ;
}
static int F_107 ( struct V_3 * V_4 )
{
F_108 ( V_4 ) ;
return 0 ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_97 * V_98 = & V_4 -> V_97 ;
int V_99 ;
V_98 -> V_100 = F_110 ( V_101 ) ;
V_98 -> V_102 = F_110 ( V_103 ) ;
V_98 -> V_104 = F_110 ( V_105 ) ;
V_98 -> V_106 = F_110 ( V_107 ) ;
V_98 -> V_108 = F_110 ( V_109 ) ;
for ( V_99 = 0 ; V_99 < F_111 ( V_98 -> V_110 ) ; V_99 ++ )
V_98 -> V_110 [ V_99 ] = F_110 ( V_111 + V_99 * 4 ) ;
V_98 -> V_112 = F_110 ( V_113 ) ;
V_98 -> V_114 = F_110 ( V_113 ) ;
V_98 -> V_115 = F_110 ( V_116 ) ;
V_98 -> V_117 = F_110 ( V_118 ) ;
V_98 -> V_119 = F_110 ( V_120 ) ;
V_98 -> V_121 = F_110 ( V_122 ) ;
V_98 -> V_123 = F_110 ( V_124 ) ;
V_98 -> V_125 = F_110 ( V_126 ) ;
V_98 -> V_127 = F_110 ( V_128 ) ;
V_98 -> V_129 = F_110 ( V_130 ) ;
V_98 -> V_131 = F_110 ( V_132 ) ;
V_98 -> V_133 = F_110 ( V_134 ) ;
V_98 -> V_135 = F_110 ( V_136 ) ;
V_98 -> V_137 = F_110 ( V_138 ) ;
V_98 -> V_139 = F_110 ( V_140 ) ;
V_98 -> V_141 = F_110 ( V_142 ) ;
V_98 -> V_143 = F_110 ( V_144 ) ;
V_98 -> V_145 = F_110 ( V_146 ) ;
V_98 -> V_147 = F_110 ( V_148 ) ;
V_98 -> V_149 = F_110 ( V_150 ) ;
V_98 -> V_151 = F_110 ( V_152 ) ;
V_98 -> V_153 = F_110 ( V_154 ) ;
V_98 -> V_155 = F_110 ( V_156 ) ;
V_98 -> V_157 = F_110 ( V_158 ) ;
V_98 -> V_159 = F_110 ( V_160 ) ;
V_98 -> V_161 = F_110 ( V_162 ) ;
V_98 -> V_163 = F_110 ( V_164 ) ;
V_98 -> V_165 = F_110 ( V_166 ) ;
V_98 -> V_167 = F_110 ( V_168 ) ;
V_98 -> V_169 = F_110 ( V_170 ) ;
for ( V_99 = 0 ; V_99 < F_111 ( V_98 -> V_171 ) ; V_99 ++ )
V_98 -> V_171 [ V_99 ] = F_110 ( V_172 + V_99 * 4 ) ;
V_98 -> V_173 = F_110 ( V_174 ) ;
V_98 -> V_175 = F_110 ( V_176 ) ;
V_98 -> V_177 = F_110 ( V_178 ) ;
V_98 -> V_179 = F_110 ( V_180 ) ;
V_98 -> V_181 = F_110 ( V_182 ) ;
V_98 -> V_183 = F_110 ( V_184 ) ;
V_98 -> V_185 = F_110 ( V_186 ) ;
V_98 -> V_187 = F_110 ( V_188 ) ;
V_98 -> V_189 = F_110 ( V_190 ) ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_97 * V_98 = & V_4 -> V_97 ;
T_3 V_191 ;
int V_99 ;
F_113 ( V_101 , V_98 -> V_100 ) ;
F_113 ( V_103 , V_98 -> V_102 ) ;
F_113 ( V_105 , V_98 -> V_104 | ( 0xffff << 16 ) ) ;
F_113 ( V_107 , V_98 -> V_106 ) ;
F_113 ( V_109 , V_98 -> V_108 ) ;
for ( V_99 = 0 ; V_99 < F_111 ( V_98 -> V_110 ) ; V_99 ++ )
F_113 ( V_111 + V_99 * 4 , V_98 -> V_110 [ V_99 ] ) ;
F_113 ( V_113 , V_98 -> V_112 ) ;
F_113 ( V_113 , V_98 -> V_114 ) ;
F_113 ( V_116 , V_98 -> V_115 ) ;
F_113 ( V_118 , V_98 -> V_117 ) ;
F_113 ( V_120 , V_98 -> V_119 ) ;
F_113 ( V_122 , V_98 -> V_121 ) ;
F_113 ( V_124 , V_98 -> V_123 ) ;
F_113 ( V_126 , V_98 -> V_125 ) ;
F_113 ( V_128 , V_98 -> V_127 ) ;
F_113 ( V_130 , V_98 -> V_129 ) ;
F_113 ( V_132 , V_98 -> V_131 ) ;
F_113 ( V_134 , V_98 -> V_133 ) ;
F_113 ( V_136 , V_98 -> V_135 ) ;
F_113 ( V_138 , V_98 -> V_137 ) ;
F_113 ( V_140 , V_98 -> V_139 ) ;
F_113 ( V_142 , V_98 -> V_141 ) ;
F_113 ( V_144 , V_98 -> V_143 ) ;
F_113 ( V_146 , V_98 -> V_145 ) ;
F_113 ( V_148 , V_98 -> V_147 ) ;
F_113 ( V_150 , V_98 -> V_149 ) ;
F_113 ( V_152 , V_98 -> V_151 ) ;
F_113 ( V_154 , V_98 -> V_153 ) ;
F_113 ( V_156 , V_98 -> V_155 ) ;
F_113 ( V_158 , V_98 -> V_157 ) ;
F_113 ( V_160 , V_98 -> V_159 ) ;
F_113 ( V_162 , V_98 -> V_161 ) ;
F_113 ( V_164 , V_98 -> V_163 ) ;
F_113 ( V_166 , V_98 -> V_165 ) ;
F_113 ( V_168 , V_98 -> V_167 ) ;
F_113 ( V_170 , V_98 -> V_169 ) ;
for ( V_99 = 0 ; V_99 < F_111 ( V_98 -> V_171 ) ; V_99 ++ )
F_113 ( V_172 + V_99 * 4 , V_98 -> V_171 [ V_99 ] ) ;
F_113 ( V_174 , V_98 -> V_173 ) ;
F_113 ( V_176 , V_98 -> V_175 ) ;
V_191 = F_110 ( V_178 ) ;
V_191 &= V_192 ;
V_191 |= V_98 -> V_177 & ~ V_192 ;
F_113 ( V_178 , V_191 ) ;
V_191 = F_110 ( V_180 ) ;
V_191 &= V_193 ;
V_191 |= V_98 -> V_179 & ~ V_193 ;
F_113 ( V_180 , V_191 ) ;
F_113 ( V_182 , V_98 -> V_181 ) ;
F_113 ( V_184 , V_98 -> V_183 ) ;
F_113 ( V_186 , V_98 -> V_185 ) ;
F_113 ( V_188 , V_98 -> V_187 ) ;
F_113 ( V_190 , V_98 -> V_189 ) ;
}
int F_114 ( struct V_3 * V_4 , bool V_194 )
{
T_3 V_191 ;
int V_195 ;
#define F_115 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_191 = F_110 ( V_180 ) ;
V_191 &= ~ V_193 ;
if ( V_194 )
V_191 |= V_193 ;
F_113 ( V_180 , V_191 ) ;
if ( ! V_194 )
return 0 ;
V_195 = F_116 ( F_115 , 20 ) ;
if ( V_195 )
F_53 ( L_23 ,
F_110 ( V_180 ) ) ;
return V_195 ;
#undef F_115
}
static int F_117 ( struct V_3 * V_4 , bool V_196 )
{
T_3 V_191 ;
int V_195 = 0 ;
V_191 = F_110 ( V_178 ) ;
V_191 &= ~ V_192 ;
if ( V_196 )
V_191 |= V_192 ;
F_113 ( V_178 , V_191 ) ;
F_118 ( V_178 ) ;
#define F_115 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_195 = F_116 ( F_115 , 1 ) ;
if ( V_195 )
F_53 ( L_24 ) ;
return V_195 ;
#undef F_115
}
static int F_119 ( struct V_3 * V_4 ,
bool V_197 )
{
T_3 V_198 ;
T_3 V_191 ;
int V_195 ;
V_198 = V_199 | V_200 ;
V_191 = V_197 ? V_198 : 0 ;
#define F_115 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_115 )
return 0 ;
F_4 ( L_25 ,
V_197 ? L_26 : L_27 ,
F_110 ( V_201 ) ) ;
V_195 = F_116 ( F_115 , 3 ) ;
if ( V_195 )
F_53 ( L_28 ,
V_197 ? L_26 : L_27 ) ;
return V_195 ;
#undef F_115
}
static void F_120 ( struct V_3 * V_4 )
{
if ( ! ( F_110 ( V_201 ) & V_202 ) )
return;
F_53 ( L_29 ) ;
F_113 ( V_201 , V_202 ) ;
}
static int F_121 ( struct V_3 * V_4 )
{
T_3 V_198 ;
int V_195 ;
( void ) F_119 ( V_4 , false ) ;
V_198 = V_203 | V_204 ;
F_5 ( ( F_110 ( V_178 ) & V_198 ) != V_198 ) ;
F_120 ( V_4 ) ;
V_195 = F_114 ( V_4 , true ) ;
if ( V_195 )
goto V_205;
V_195 = F_117 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
if ( ! F_122 ( V_4 -> V_2 ) )
F_109 ( V_4 ) ;
V_195 = F_114 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
return 0 ;
V_206:
F_117 ( V_4 , true ) ;
V_205:
F_114 ( V_4 , false ) ;
return V_195 ;
}
static int F_78 ( struct V_3 * V_4 ,
bool V_207 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_195 ;
int V_61 ;
V_61 = F_114 ( V_4 , true ) ;
if ( ! F_122 ( V_4 -> V_2 ) )
F_112 ( V_4 ) ;
V_195 = F_117 ( V_4 , true ) ;
if ( ! V_61 )
V_61 = V_195 ;
V_195 = F_114 ( V_4 , false ) ;
if ( ! V_61 )
V_61 = V_195 ;
F_120 ( V_4 ) ;
if ( V_207 ) {
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
}
return V_61 ;
}
static int F_125 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_101 ( V_15 ) ;
struct V_1 * V_2 = F_98 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_61 ;
if ( F_57 ( ! ( V_4 -> V_208 . V_209 && F_126 ( V_2 ) ) ) )
return - V_66 ;
if ( F_57 ( ! F_127 ( V_2 ) ) )
return - V_66 ;
F_4 ( L_30 ) ;
if ( ! F_128 ( & V_2 -> V_73 ) ) {
F_4 ( L_31 ) ;
F_129 ( V_15 ) ;
return - V_210 ;
}
F_130 ( V_4 ) ;
F_30 ( & V_2 -> V_73 ) ;
F_37 ( V_2 ) ;
F_41 ( V_4 ) ;
V_61 = F_52 ( V_4 ) ;
if ( V_61 ) {
F_53 ( L_32 , V_61 ) ;
F_66 ( V_4 ) ;
return V_61 ;
}
F_22 ( & V_4 -> V_75 . V_211 ) ;
F_48 ( V_2 , false ) ;
V_4 -> V_212 . V_213 = true ;
if ( F_9 ( V_2 ) ) {
F_47 ( V_2 , V_56 ) ;
} else {
F_47 ( V_2 , V_64 ) ;
}
F_131 ( V_4 ) ;
F_4 ( L_33 ) ;
return 0 ;
}
static int F_132 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_101 ( V_15 ) ;
struct V_1 * V_2 = F_98 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_61 = 0 ;
if ( F_57 ( ! F_127 ( V_2 ) ) )
return - V_66 ;
F_4 ( L_34 ) ;
F_47 ( V_2 , V_81 ) ;
V_4 -> V_212 . V_213 = false ;
if ( F_7 ( V_4 ) )
F_62 ( V_2 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_80 ( V_4 ) ;
else if ( F_77 ( V_4 ) )
V_61 = F_78 ( V_4 , true ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
F_66 ( V_4 ) ;
F_92 ( V_2 ) ;
if ( V_61 )
F_53 ( L_35 , V_61 ) ;
else
F_4 ( L_36 ) ;
return V_61 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_61 ;
if ( F_9 ( V_2 ) || F_10 ( V_2 ) )
V_61 = F_107 ( V_4 ) ;
else if ( F_77 ( V_2 ) )
V_61 = F_121 ( V_4 ) ;
else
V_61 = 0 ;
return V_61 ;
}
static int T_4 F_135 ( void )
{
V_94 . V_214 = V_215 ;
#if F_136 ( V_216 )
if ( V_30 . V_217 != 0 )
V_94 . V_95 |= V_52 ;
#endif
if ( V_30 . V_217 == 1 )
V_94 . V_95 |= V_52 ;
#ifdef F_137
if ( F_138 () && V_30 . V_217 == - 1 )
V_94 . V_95 &= ~ V_52 ;
#endif
if ( ! ( V_94 . V_95 & V_52 ) ) {
V_94 . V_218 = NULL ;
#ifndef F_139
F_140 ( L_37 ) ;
return 0 ;
#endif
}
if ( V_30 . V_219 )
V_94 . V_95 |= V_220 ;
return F_141 ( & V_94 , & V_221 ) ;
}
static void T_5 F_142 ( void )
{
#ifndef F_139
if ( ! ( V_94 . V_95 & V_52 ) )
return;
#endif
F_143 ( & V_94 , & V_221 ) ;
}
