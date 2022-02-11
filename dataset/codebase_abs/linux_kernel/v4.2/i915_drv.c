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
void F_23 ( const char * V_41 , int V_42 )
{
F_24 ( L_9 , V_41 , V_42 ) ;
if ( ! V_42 )
V_42 = - V_43 ;
if ( ! ( F_25 ( V_44 ) && V_42 == - V_43 ) )
return;
F_24 (
L_10
L_11
L_12 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_45 * V_46 ;
F_27 ( V_2 ) ;
F_28 (encoder, &dev->mode_config.encoder_list, head) {
struct V_47 * V_47 = F_29 ( V_46 ) ;
if ( V_47 -> V_48 )
V_47 -> V_48 ( V_47 ) ;
}
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_49 * V_50 ;
T_1 V_51 ;
int error ;
F_32 ( & V_4 -> V_52 ) ;
V_4 -> V_53 = V_54 ;
F_33 ( & V_4 -> V_52 ) ;
F_34 ( V_4 , true ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_55 ) ;
error = F_37 ( V_2 ) ;
if ( error ) {
F_38 ( & V_2 -> V_55 -> V_2 ,
L_13 ) ;
return error ;
}
F_39 ( V_2 ) ;
F_27 ( V_2 ) ;
F_40 (dev, crtc)
F_41 ( V_50 , false ) ;
F_30 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_4 ) ;
F_18 ( V_4 ) ;
F_26 ( V_4 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
V_51 = V_56 ;
#if F_47 ( V_57 )
if ( F_48 () < V_58 )
V_51 = V_59 ;
#endif
F_49 ( V_2 , V_51 ) ;
F_50 ( V_2 , false ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 , V_60 , true ) ;
V_4 -> V_61 ++ ;
F_34 ( V_4 , false ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_62 , bool V_63 )
{
struct V_3 * V_4 = V_62 -> V_5 ;
int V_64 ;
V_64 = F_54 ( V_4 ) ;
if ( V_64 ) {
F_24 ( L_14 , V_64 ) ;
return V_64 ;
}
F_55 ( V_62 -> V_55 ) ;
if ( ! ( V_63 &&
V_62 -> V_55 -> V_65 == V_66 &&
F_2 ( V_4 ) -> V_29 == 4 ) )
F_56 ( V_62 -> V_55 , V_67 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , T_2 V_68 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_24 ( L_15 , V_2 ) ;
F_24 ( L_16 ) ;
return - V_69 ;
}
if ( F_58 ( V_68 . V_70 != V_71 &&
V_68 . V_70 != V_72 ) )
return - V_73 ;
if ( V_2 -> V_74 == V_75 )
return 0 ;
error = F_31 ( V_2 ) ;
if ( error )
return error ;
return F_53 ( V_2 , false ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_32 ( & V_2 -> V_76 ) ;
F_60 ( V_2 ) ;
F_33 ( & V_2 -> V_76 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_4 ) ;
F_32 ( & V_2 -> V_76 ) ;
if ( F_66 ( V_2 ) ) {
F_24 ( L_17 ) ;
F_67 ( V_77 , & V_4 -> V_78 . V_79 ) ;
}
F_33 ( & V_2 -> V_76 ) ;
F_68 ( V_2 ) ;
F_19 ( & V_4 -> V_34 ) ;
if ( V_4 -> V_80 . V_81 )
V_4 -> V_80 . V_81 ( V_2 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_27 ( V_2 ) ;
F_69 ( V_2 , true ) ;
F_30 ( V_2 ) ;
F_70 ( V_2 ) ;
F_71 ( V_4 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_52 ( V_2 , V_82 , false ) ;
F_32 ( & V_4 -> V_52 ) ;
V_4 -> V_53 = V_83 ;
F_33 ( & V_4 -> V_52 ) ;
F_49 ( V_2 , V_84 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 = 0 ;
if ( F_76 ( V_2 -> V_55 ) )
return - V_85 ;
F_77 ( V_2 -> V_55 ) ;
if ( F_78 ( V_4 ) )
V_64 = F_79 ( V_4 , false ) ;
if ( V_64 )
F_24 ( L_18 ,
V_64 ) ;
F_80 ( V_2 , true ) ;
if ( F_81 ( V_2 ) )
V_64 = F_82 ( V_4 ) ;
else if ( F_13 ( V_4 ) )
V_64 = F_83 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_84 ( V_4 ) ;
F_85 ( V_2 ) ;
F_86 ( V_4 ) ;
return V_64 ;
}
int F_87 ( struct V_1 * V_2 )
{
int V_64 ;
if ( V_2 -> V_74 == V_75 )
return 0 ;
V_64 = F_75 ( V_2 ) ;
if ( V_64 )
return V_64 ;
return F_59 ( V_2 ) ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_86 ;
int V_64 ;
if ( ! V_30 . V_87 )
return 0 ;
F_89 ( V_2 ) ;
F_32 ( & V_2 -> V_76 ) ;
F_90 ( V_2 ) ;
V_86 = V_4 -> V_78 . V_88 != 0 ;
V_64 = F_91 ( V_2 ) ;
if ( V_86 ) {
F_92 ( L_19 ) ;
V_4 -> V_78 . V_88 = 0 ;
if ( V_64 == - V_69 ) {
F_92 ( L_20
L_21 ) ;
V_64 = 0 ;
}
}
if ( F_93 ( V_4 ) )
F_94 ( L_22 ) ;
if ( V_64 ) {
F_24 ( L_23 , V_64 ) ;
F_33 ( & V_2 -> V_76 ) ;
return V_64 ;
}
F_95 ( V_4 ) ;
V_4 -> V_78 . V_89 = true ;
V_64 = F_66 ( V_2 ) ;
V_4 -> V_78 . V_89 = false ;
F_33 ( & V_2 -> V_76 ) ;
if ( V_64 ) {
F_24 ( L_24 , V_64 ) ;
return V_64 ;
}
if ( F_2 ( V_2 ) -> V_29 > 5 )
F_96 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_6 * V_55 , const struct V_90 * V_91 )
{
struct V_92 * V_93 =
(struct V_92 * ) V_91 -> V_94 ;
if ( F_98 ( V_93 ) && ! V_30 . V_95 ) {
F_92 ( L_25
L_26 ) ;
return - V_69 ;
}
if ( F_99 ( V_55 -> V_96 ) )
return - V_69 ;
V_97 . V_98 &= ~ ( V_99 ) ;
return F_100 ( V_55 , V_91 , & V_97 ) ;
}
static void
F_101 ( struct V_6 * V_55 )
{
struct V_1 * V_2 = F_102 ( V_55 ) ;
F_103 ( V_2 ) ;
}
static int F_104 ( struct V_15 * V_2 )
{
struct V_6 * V_55 = F_105 ( V_2 ) ;
struct V_1 * V_62 = F_102 ( V_55 ) ;
if ( ! V_62 || ! V_62 -> V_5 ) {
F_38 ( V_2 , L_16 ) ;
return - V_69 ;
}
if ( V_62 -> V_74 == V_75 )
return 0 ;
return F_31 ( V_62 ) ;
}
static int F_106 ( struct V_15 * V_2 )
{
struct V_1 * V_62 = F_107 ( V_2 ) -> V_2 ;
if ( V_62 -> V_74 == V_75 )
return 0 ;
return F_53 ( V_62 , false ) ;
}
static int F_108 ( struct V_15 * V_2 )
{
struct V_1 * V_62 = F_107 ( V_2 ) -> V_2 ;
if ( V_62 -> V_74 == V_75 )
return 0 ;
return F_53 ( V_62 , true ) ;
}
static int F_109 ( struct V_15 * V_2 )
{
struct V_1 * V_62 = F_107 ( V_2 ) -> V_2 ;
if ( V_62 -> V_74 == V_75 )
return 0 ;
return F_75 ( V_62 ) ;
}
static int F_110 ( struct V_15 * V_2 )
{
struct V_1 * V_62 = F_107 ( V_2 ) -> V_2 ;
if ( V_62 -> V_74 == V_75 )
return 0 ;
return F_59 ( V_62 ) ;
}
static int F_111 ( struct V_3 * V_4 )
{
F_112 ( V_4 , V_100 ) ;
F_113 ( V_4 ) ;
return 0 ;
}
static int F_114 ( struct V_3 * V_4 )
{
F_115 ( V_4 ) ;
return 0 ;
}
static int F_116 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_117 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( V_4 ) ;
return 0 ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_120 ( V_4 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_124 ( V_4 ) ;
F_125 ( V_2 ) ;
return 0 ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_101 * V_102 = & V_4 -> V_101 ;
int V_103 ;
V_102 -> V_104 = F_127 ( V_105 ) ;
V_102 -> V_106 = F_127 ( V_107 ) ;
V_102 -> V_108 = F_127 ( V_109 ) ;
V_102 -> V_110 = F_127 ( V_111 ) ;
V_102 -> V_112 = F_127 ( V_113 ) ;
for ( V_103 = 0 ; V_103 < F_128 ( V_102 -> V_114 ) ; V_103 ++ )
V_102 -> V_114 [ V_103 ] = F_127 ( V_115 + V_103 * 4 ) ;
V_102 -> V_116 = F_127 ( V_117 ) ;
V_102 -> V_118 = F_127 ( V_119 ) ;
V_102 -> V_120 = F_127 ( V_121 ) ;
V_102 -> V_122 = F_127 ( V_123 ) ;
V_102 -> V_124 = F_127 ( V_125 ) ;
V_102 -> V_126 = F_127 ( V_127 ) ;
V_102 -> V_128 = F_127 ( V_129 ) ;
V_102 -> V_130 = F_127 ( V_131 ) ;
V_102 -> V_132 = F_127 ( V_133 ) ;
V_102 -> V_134 = F_127 ( V_135 ) ;
V_102 -> V_136 = F_127 ( V_137 ) ;
V_102 -> V_138 = F_127 ( V_139 ) ;
V_102 -> V_140 = F_127 ( V_141 ) ;
V_102 -> V_142 = F_127 ( V_143 ) ;
V_102 -> V_144 = F_127 ( V_145 ) ;
V_102 -> V_146 = F_127 ( V_147 ) ;
V_102 -> V_148 = F_127 ( V_149 ) ;
V_102 -> V_150 = F_127 ( V_151 ) ;
V_102 -> V_152 = F_127 ( V_153 ) ;
V_102 -> V_154 = F_127 ( V_155 ) ;
V_102 -> V_156 = F_127 ( V_157 ) ;
V_102 -> V_158 = F_127 ( V_159 ) ;
V_102 -> V_160 = F_127 ( V_161 ) ;
V_102 -> V_162 = F_127 ( V_163 ) ;
V_102 -> V_164 = F_127 ( V_165 ) ;
V_102 -> V_166 = F_127 ( V_167 ) ;
V_102 -> V_168 = F_127 ( V_169 ) ;
V_102 -> V_170 = F_127 ( V_171 ) ;
V_102 -> V_172 = F_127 ( V_173 ) ;
V_102 -> V_174 = F_127 ( V_175 ) ;
for ( V_103 = 0 ; V_103 < F_128 ( V_102 -> V_176 ) ; V_103 ++ )
V_102 -> V_176 [ V_103 ] = F_127 ( V_177 + V_103 * 4 ) ;
V_102 -> V_178 = F_127 ( V_179 ) ;
V_102 -> V_180 = F_127 ( V_181 ) ;
V_102 -> V_182 = F_127 ( V_183 ) ;
V_102 -> V_184 = F_127 ( V_185 ) ;
V_102 -> V_186 = F_127 ( V_187 ) ;
V_102 -> V_188 = F_127 ( V_189 ) ;
V_102 -> V_190 = F_127 ( V_191 ) ;
V_102 -> V_192 = F_127 ( V_193 ) ;
V_102 -> V_194 = F_127 ( V_195 ) ;
}
static void F_129 ( struct V_3 * V_4 )
{
struct V_101 * V_102 = & V_4 -> V_101 ;
T_3 V_196 ;
int V_103 ;
F_130 ( V_105 , V_102 -> V_104 ) ;
F_130 ( V_107 , V_102 -> V_106 ) ;
F_130 ( V_109 , V_102 -> V_108 | ( 0xffff << 16 ) ) ;
F_130 ( V_111 , V_102 -> V_110 ) ;
F_130 ( V_113 , V_102 -> V_112 ) ;
for ( V_103 = 0 ; V_103 < F_128 ( V_102 -> V_114 ) ; V_103 ++ )
F_130 ( V_115 + V_103 * 4 , V_102 -> V_114 [ V_103 ] ) ;
F_130 ( V_117 , V_102 -> V_116 ) ;
F_130 ( V_119 , V_102 -> V_118 ) ;
F_130 ( V_121 , V_102 -> V_120 ) ;
F_130 ( V_123 , V_102 -> V_122 ) ;
F_130 ( V_125 , V_102 -> V_124 ) ;
F_130 ( V_127 , V_102 -> V_126 ) ;
F_130 ( V_129 , V_102 -> V_128 ) ;
F_130 ( V_131 , V_102 -> V_130 ) ;
F_130 ( V_133 , V_102 -> V_132 ) ;
F_130 ( V_135 , V_102 -> V_134 ) ;
F_130 ( V_137 , V_102 -> V_136 ) ;
F_130 ( V_139 , V_102 -> V_138 ) ;
F_130 ( V_141 , V_102 -> V_140 ) ;
F_130 ( V_143 , V_102 -> V_142 ) ;
F_130 ( V_145 , V_102 -> V_144 ) ;
F_130 ( V_147 , V_102 -> V_146 ) ;
F_130 ( V_149 , V_102 -> V_148 ) ;
F_130 ( V_151 , V_102 -> V_150 ) ;
F_130 ( V_153 , V_102 -> V_152 ) ;
F_130 ( V_155 , V_102 -> V_154 ) ;
F_130 ( V_157 , V_102 -> V_156 ) ;
F_130 ( V_159 , V_102 -> V_158 ) ;
F_130 ( V_161 , V_102 -> V_160 ) ;
F_130 ( V_163 , V_102 -> V_162 ) ;
F_130 ( V_165 , V_102 -> V_164 ) ;
F_130 ( V_167 , V_102 -> V_166 ) ;
F_130 ( V_169 , V_102 -> V_168 ) ;
F_130 ( V_171 , V_102 -> V_170 ) ;
F_130 ( V_173 , V_102 -> V_172 ) ;
F_130 ( V_175 , V_102 -> V_174 ) ;
for ( V_103 = 0 ; V_103 < F_128 ( V_102 -> V_176 ) ; V_103 ++ )
F_130 ( V_177 + V_103 * 4 , V_102 -> V_176 [ V_103 ] ) ;
F_130 ( V_179 , V_102 -> V_178 ) ;
F_130 ( V_181 , V_102 -> V_180 ) ;
V_196 = F_127 ( V_183 ) ;
V_196 &= V_197 ;
V_196 |= V_102 -> V_182 & ~ V_197 ;
F_130 ( V_183 , V_196 ) ;
V_196 = F_127 ( V_185 ) ;
V_196 &= V_198 ;
V_196 |= V_102 -> V_184 & ~ V_198 ;
F_130 ( V_185 , V_196 ) ;
F_130 ( V_187 , V_102 -> V_186 ) ;
F_130 ( V_189 , V_102 -> V_188 ) ;
F_130 ( V_191 , V_102 -> V_190 ) ;
F_130 ( V_193 , V_102 -> V_192 ) ;
F_130 ( V_195 , V_102 -> V_194 ) ;
}
int F_131 ( struct V_3 * V_4 , bool V_199 )
{
T_3 V_196 ;
int V_42 ;
#define F_132 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_196 = F_127 ( V_185 ) ;
V_196 &= ~ V_198 ;
if ( V_199 )
V_196 |= V_198 ;
F_130 ( V_185 , V_196 ) ;
if ( ! V_199 )
return 0 ;
V_42 = F_133 ( F_132 , 20 ) ;
if ( V_42 )
F_24 ( L_27 ,
F_127 ( V_185 ) ) ;
return V_42 ;
#undef F_132
}
static int F_134 ( struct V_3 * V_4 , bool V_200 )
{
T_3 V_196 ;
int V_42 = 0 ;
V_196 = F_127 ( V_183 ) ;
V_196 &= ~ V_197 ;
if ( V_200 )
V_196 |= V_197 ;
F_130 ( V_183 , V_196 ) ;
F_135 ( V_183 ) ;
#define F_132 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_42 = F_133 ( F_132 , 1 ) ;
if ( V_42 )
F_24 ( L_28 ) ;
return V_42 ;
#undef F_132
}
static int F_136 ( struct V_3 * V_4 ,
bool V_201 )
{
T_3 V_202 ;
T_3 V_196 ;
int V_42 ;
V_202 = V_203 | V_204 ;
V_196 = V_201 ? V_202 : 0 ;
#define F_132 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_132 )
return 0 ;
F_4 ( L_29 ,
V_201 ? L_30 : L_31 ,
F_127 ( V_205 ) ) ;
V_42 = F_133 ( F_132 , 3 ) ;
if ( V_42 )
F_24 ( L_32 ,
V_201 ? L_30 : L_31 ) ;
return V_42 ;
#undef F_132
}
static void F_137 ( struct V_3 * V_4 )
{
if ( ! ( F_127 ( V_205 ) & V_206 ) )
return;
F_24 ( L_33 ) ;
F_130 ( V_205 , V_206 ) ;
}
static int F_138 ( struct V_3 * V_4 )
{
T_3 V_202 ;
int V_42 ;
( void ) F_136 ( V_4 , false ) ;
V_202 = V_207 | V_208 ;
F_5 ( ( F_127 ( V_183 ) & V_202 ) != V_202 ) ;
F_137 ( V_4 ) ;
V_42 = F_131 ( V_4 , true ) ;
if ( V_42 )
goto V_209;
V_42 = F_134 ( V_4 , false ) ;
if ( V_42 )
goto V_210;
if ( ! F_139 ( V_4 -> V_2 ) )
F_126 ( V_4 ) ;
V_42 = F_131 ( V_4 , false ) ;
if ( V_42 )
goto V_210;
return 0 ;
V_210:
F_134 ( V_4 , true ) ;
V_209:
F_131 ( V_4 , false ) ;
return V_42 ;
}
static int F_79 ( struct V_3 * V_4 ,
bool V_211 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_42 ;
int V_64 ;
V_64 = F_131 ( V_4 , true ) ;
if ( ! F_139 ( V_4 -> V_2 ) )
F_129 ( V_4 ) ;
V_42 = F_134 ( V_4 , true ) ;
if ( ! V_64 )
V_64 = V_42 ;
V_42 = F_131 ( V_4 , false ) ;
if ( ! V_64 )
V_64 = V_42 ;
F_137 ( V_4 ) ;
if ( V_211 ) {
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
}
return V_64 ;
}
static int F_142 ( struct V_15 * V_15 )
{
struct V_6 * V_55 = F_105 ( V_15 ) ;
struct V_1 * V_2 = F_102 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( F_58 ( ! ( V_4 -> V_212 . V_213 && F_143 ( V_2 ) ) ) )
return - V_69 ;
if ( F_58 ( ! F_144 ( V_2 ) ) )
return - V_69 ;
F_4 ( L_34 ) ;
if ( ! F_145 ( & V_2 -> V_76 ) ) {
F_4 ( L_35 ) ;
F_146 ( V_15 ) ;
return - V_214 ;
}
F_147 ( V_4 ) ;
F_33 ( & V_2 -> V_76 ) ;
F_39 ( V_2 ) ;
F_43 ( V_4 ) ;
V_64 = F_54 ( V_4 ) ;
if ( V_64 ) {
F_24 ( L_36 , V_64 ) ;
F_65 ( V_4 ) ;
return V_64 ;
}
F_22 ( & V_4 -> V_78 . V_215 ) ;
F_50 ( V_2 , false ) ;
V_4 -> V_216 . V_217 = true ;
if ( F_9 ( V_2 ) ) {
F_49 ( V_2 , V_59 ) ;
} else {
F_49 ( V_2 , V_67 ) ;
}
F_148 ( V_4 ) ;
F_4 ( L_37 ) ;
return 0 ;
}
static int F_149 ( struct V_15 * V_15 )
{
struct V_6 * V_55 = F_105 ( V_15 ) ;
struct V_1 * V_2 = F_102 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 = 0 ;
if ( F_58 ( ! F_144 ( V_2 ) ) )
return - V_69 ;
F_4 ( L_38 ) ;
F_49 ( V_2 , V_84 ) ;
V_4 -> V_216 . V_217 = false ;
if ( F_7 ( V_4 ) )
F_63 ( V_2 ) ;
if ( F_81 ( V_2 ) )
V_64 = F_82 ( V_4 ) ;
else if ( F_13 ( V_2 ) )
V_64 = F_83 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_84 ( V_4 ) ;
else if ( F_78 ( V_4 ) )
V_64 = F_79 ( V_4 , true ) ;
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
F_65 ( V_4 ) ;
F_96 ( V_2 ) ;
if ( V_64 )
F_24 ( L_39 , V_64 ) ;
else
F_4 ( L_40 ) ;
return V_64 ;
}
static int F_54 ( struct V_3 * V_4 )
{
int V_64 ;
if ( F_81 ( V_4 ) )
V_64 = F_116 ( V_4 ) ;
else if ( F_13 ( V_4 ) )
V_64 = F_111 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
V_64 = F_114 ( V_4 ) ;
else if ( F_78 ( V_4 ) )
V_64 = F_138 ( V_4 ) ;
else
V_64 = 0 ;
return V_64 ;
}
static int T_4 F_152 ( void )
{
V_97 . V_218 = V_219 ;
#if F_153 ( V_220 )
if ( V_30 . V_221 != 0 )
V_97 . V_98 |= V_222 ;
#endif
if ( V_30 . V_221 == 1 )
V_97 . V_98 |= V_222 ;
#ifdef F_154
if ( F_155 () && V_30 . V_221 == - 1 )
V_97 . V_98 &= ~ V_222 ;
#endif
if ( ! ( V_97 . V_98 & V_222 ) ) {
V_97 . V_223 = NULL ;
F_156 ( L_41 ) ;
return 0 ;
}
if ( V_30 . V_224 )
V_97 . V_98 |= V_225 ;
return F_157 ( & V_97 , & V_226 ) ;
}
static void T_5 F_158 ( void )
{
if ( ! ( V_97 . V_98 & V_222 ) )
return;
F_159 ( & V_97 , & V_226 ) ;
}
