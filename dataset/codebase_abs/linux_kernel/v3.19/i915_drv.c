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
static int F_51 ( struct V_1 * V_59 )
{
struct V_3 * V_4 = V_59 -> V_5 ;
int V_60 ;
V_60 = F_52 ( V_4 ) ;
if ( V_60 ) {
F_53 ( L_10 , V_60 ) ;
return V_60 ;
}
F_54 ( V_59 -> V_51 ) ;
F_55 ( V_59 -> V_51 , V_61 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , T_2 V_62 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_53 ( L_11 , V_2 ) ;
F_53 ( L_12 ) ;
return - V_63 ;
}
if ( F_57 ( V_62 . V_64 != V_65 &&
V_62 . V_64 != V_66 ) )
return - V_67 ;
if ( V_2 -> V_68 == V_69 )
return 0 ;
error = F_28 ( V_2 ) ;
if ( error )
return error ;
return F_51 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_34 ( V_2 , V_52 ) ) {
F_29 ( & V_2 -> V_70 ) ;
F_59 ( V_2 ) ;
F_30 ( & V_2 -> V_70 ) ;
}
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( F_34 ( V_2 , V_52 ) ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_29 ( & V_2 -> V_70 ) ;
if ( F_64 ( V_2 ) ) {
F_53 ( L_13 ) ;
F_65 ( V_71 , & V_4 -> V_72 . V_73 ) ;
}
F_30 ( & V_2 -> V_70 ) ;
F_66 ( V_4 ) ;
F_67 ( V_2 ) ;
F_19 ( & V_4 -> V_34 ) ;
if ( V_4 -> V_74 . V_75 )
V_4 -> V_74 . V_75 ( V_2 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_24 ( V_2 ) ;
F_68 ( V_2 , true ) ;
F_27 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_4 ) ;
F_71 ( V_2 ) ;
}
F_72 ( V_2 ) ;
F_50 ( V_2 , V_76 , false ) ;
F_29 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = V_77 ;
F_30 ( & V_4 -> V_48 ) ;
F_47 ( V_2 , V_78 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 = 0 ;
if ( F_75 ( V_2 -> V_51 ) )
return - V_79 ;
F_76 ( V_2 -> V_51 ) ;
if ( F_77 ( V_4 ) )
V_60 = F_78 ( V_4 , false ) ;
if ( V_60 )
F_53 ( L_14 , V_60 ) ;
F_79 ( V_2 , true ) ;
if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_80 ( V_4 ) ;
F_81 ( V_2 ) ;
F_82 ( V_4 ) ;
return V_60 ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_60 ;
if ( V_2 -> V_68 == V_69 )
return 0 ;
V_60 = F_74 ( V_2 ) ;
if ( V_60 )
return V_60 ;
return F_58 ( V_2 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_80 ;
int V_60 ;
if ( ! V_30 . V_81 )
return 0 ;
F_85 ( V_2 ) ;
F_29 ( & V_2 -> V_70 ) ;
F_86 ( V_2 ) ;
V_80 = V_4 -> V_72 . V_82 != 0 ;
V_60 = F_87 ( V_2 ) ;
if ( V_80 ) {
F_88 ( L_15 ) ;
V_4 -> V_72 . V_82 = 0 ;
if ( V_60 == - V_63 ) {
F_88 ( L_16
L_17 ) ;
V_60 = 0 ;
}
}
if ( F_89 ( V_4 ) )
F_90 ( L_18 ) ;
if ( V_60 ) {
F_53 ( L_19 , V_60 ) ;
F_30 ( & V_2 -> V_70 ) ;
return V_60 ;
}
if ( F_34 ( V_2 , V_52 ) ) {
V_4 -> V_72 . V_83 = true ;
V_60 = F_64 ( V_2 ) ;
V_4 -> V_72 . V_83 = false ;
F_30 ( & V_2 -> V_70 ) ;
if ( V_60 ) {
F_53 ( L_20 , V_60 ) ;
return V_60 ;
}
if ( F_2 ( V_2 ) -> V_29 > 5 )
F_91 ( V_2 ) ;
} else {
F_30 ( & V_2 -> V_70 ) ;
}
return 0 ;
}
static int F_92 ( struct V_6 * V_51 , const struct V_84 * V_85 )
{
struct V_86 * V_87 =
(struct V_86 * ) V_85 -> V_88 ;
if ( F_93 ( V_87 ) && ! V_30 . V_89 ) {
F_88 ( L_21
L_22 ) ;
return - V_63 ;
}
if ( F_94 ( V_51 -> V_90 ) )
return - V_63 ;
V_91 . V_92 &= ~ ( V_93 ) ;
return F_95 ( V_51 , V_85 , & V_91 ) ;
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
struct V_1 * V_59 = F_97 ( V_51 ) ;
if ( ! V_59 || ! V_59 -> V_5 ) {
F_36 ( V_2 , L_12 ) ;
return - V_63 ;
}
if ( V_59 -> V_68 == V_69 )
return 0 ;
return F_28 ( V_59 ) ;
}
static int F_101 ( struct V_15 * V_2 )
{
struct V_6 * V_51 = F_100 ( V_2 ) ;
struct V_1 * V_59 = F_97 ( V_51 ) ;
if ( V_59 -> V_68 == V_69 )
return 0 ;
return F_51 ( V_59 ) ;
}
static int F_102 ( struct V_15 * V_2 )
{
struct V_6 * V_51 = F_100 ( V_2 ) ;
struct V_1 * V_59 = F_97 ( V_51 ) ;
if ( V_59 -> V_68 == V_69 )
return 0 ;
return F_74 ( V_59 ) ;
}
static int F_103 ( struct V_15 * V_2 )
{
struct V_6 * V_51 = F_100 ( V_2 ) ;
struct V_1 * V_59 = F_97 ( V_51 ) ;
if ( V_59 -> V_68 == V_69 )
return 0 ;
return F_58 ( V_59 ) ;
}
static int F_104 ( struct V_3 * V_4 )
{
F_105 ( V_4 ) ;
return 0 ;
}
static void F_106 ( struct V_3 * V_4 )
{
struct V_94 * V_95 = & V_4 -> V_94 ;
int V_96 ;
V_95 -> V_97 = F_107 ( V_98 ) ;
V_95 -> V_99 = F_107 ( V_100 ) ;
V_95 -> V_101 = F_107 ( V_102 ) ;
V_95 -> V_103 = F_107 ( V_104 ) ;
V_95 -> V_105 = F_107 ( V_106 ) ;
for ( V_96 = 0 ; V_96 < F_108 ( V_95 -> V_107 ) ; V_96 ++ )
V_95 -> V_107 [ V_96 ] = F_107 ( V_108 + V_96 * 4 ) ;
V_95 -> V_109 = F_107 ( V_110 ) ;
V_95 -> V_111 = F_107 ( V_110 ) ;
V_95 -> V_112 = F_107 ( V_113 ) ;
V_95 -> V_114 = F_107 ( V_115 ) ;
V_95 -> V_116 = F_107 ( V_117 ) ;
V_95 -> V_118 = F_107 ( V_119 ) ;
V_95 -> V_120 = F_107 ( V_121 ) ;
V_95 -> V_122 = F_107 ( V_123 ) ;
V_95 -> V_124 = F_107 ( V_125 ) ;
V_95 -> V_126 = F_107 ( V_127 ) ;
V_95 -> V_128 = F_107 ( V_129 ) ;
V_95 -> V_130 = F_107 ( V_131 ) ;
V_95 -> V_132 = F_107 ( V_133 ) ;
V_95 -> V_134 = F_107 ( V_135 ) ;
V_95 -> V_136 = F_107 ( V_137 ) ;
V_95 -> V_138 = F_107 ( V_139 ) ;
V_95 -> V_140 = F_107 ( V_141 ) ;
V_95 -> V_142 = F_107 ( V_143 ) ;
V_95 -> V_144 = F_107 ( V_145 ) ;
V_95 -> V_146 = F_107 ( V_147 ) ;
V_95 -> V_148 = F_107 ( V_149 ) ;
V_95 -> V_150 = F_107 ( V_151 ) ;
V_95 -> V_152 = F_107 ( V_153 ) ;
V_95 -> V_154 = F_107 ( V_155 ) ;
V_95 -> V_156 = F_107 ( V_157 ) ;
V_95 -> V_158 = F_107 ( V_159 ) ;
V_95 -> V_160 = F_107 ( V_161 ) ;
V_95 -> V_162 = F_107 ( V_163 ) ;
V_95 -> V_164 = F_107 ( V_165 ) ;
V_95 -> V_166 = F_107 ( V_167 ) ;
for ( V_96 = 0 ; V_96 < F_108 ( V_95 -> V_168 ) ; V_96 ++ )
V_95 -> V_168 [ V_96 ] = F_107 ( V_169 + V_96 * 4 ) ;
V_95 -> V_170 = F_107 ( V_171 ) ;
V_95 -> V_172 = F_107 ( V_173 ) ;
V_95 -> V_174 = F_107 ( V_175 ) ;
V_95 -> V_176 = F_107 ( V_177 ) ;
V_95 -> V_178 = F_107 ( V_179 ) ;
V_95 -> V_180 = F_107 ( V_181 ) ;
V_95 -> V_182 = F_107 ( V_183 ) ;
V_95 -> V_184 = F_107 ( V_185 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_94 * V_95 = & V_4 -> V_94 ;
T_3 V_186 ;
int V_96 ;
F_110 ( V_98 , V_95 -> V_97 ) ;
F_110 ( V_100 , V_95 -> V_99 ) ;
F_110 ( V_102 , V_95 -> V_101 | ( 0xffff << 16 ) ) ;
F_110 ( V_104 , V_95 -> V_103 ) ;
F_110 ( V_106 , V_95 -> V_105 ) ;
for ( V_96 = 0 ; V_96 < F_108 ( V_95 -> V_107 ) ; V_96 ++ )
F_110 ( V_108 + V_96 * 4 , V_95 -> V_107 [ V_96 ] ) ;
F_110 ( V_110 , V_95 -> V_109 ) ;
F_110 ( V_110 , V_95 -> V_111 ) ;
F_110 ( V_113 , V_95 -> V_112 ) ;
F_110 ( V_115 , V_95 -> V_114 ) ;
F_110 ( V_117 , V_95 -> V_116 ) ;
F_110 ( V_119 , V_95 -> V_118 ) ;
F_110 ( V_121 , V_95 -> V_120 ) ;
F_110 ( V_123 , V_95 -> V_122 ) ;
F_110 ( V_125 , V_95 -> V_124 ) ;
F_110 ( V_127 , V_95 -> V_126 ) ;
F_110 ( V_129 , V_95 -> V_128 ) ;
F_110 ( V_131 , V_95 -> V_130 ) ;
F_110 ( V_133 , V_95 -> V_132 ) ;
F_110 ( V_135 , V_95 -> V_134 ) ;
F_110 ( V_137 , V_95 -> V_136 ) ;
F_110 ( V_139 , V_95 -> V_138 ) ;
F_110 ( V_141 , V_95 -> V_140 ) ;
F_110 ( V_143 , V_95 -> V_142 ) ;
F_110 ( V_145 , V_95 -> V_144 ) ;
F_110 ( V_147 , V_95 -> V_146 ) ;
F_110 ( V_149 , V_95 -> V_148 ) ;
F_110 ( V_151 , V_95 -> V_150 ) ;
F_110 ( V_153 , V_95 -> V_152 ) ;
F_110 ( V_155 , V_95 -> V_154 ) ;
F_110 ( V_157 , V_95 -> V_156 ) ;
F_110 ( V_159 , V_95 -> V_158 ) ;
F_110 ( V_161 , V_95 -> V_160 ) ;
F_110 ( V_163 , V_95 -> V_162 ) ;
F_110 ( V_165 , V_95 -> V_164 ) ;
F_110 ( V_167 , V_95 -> V_166 ) ;
for ( V_96 = 0 ; V_96 < F_108 ( V_95 -> V_168 ) ; V_96 ++ )
F_110 ( V_169 + V_96 * 4 , V_95 -> V_168 [ V_96 ] ) ;
F_110 ( V_171 , V_95 -> V_170 ) ;
F_110 ( V_173 , V_95 -> V_172 ) ;
V_186 = F_107 ( V_175 ) ;
V_186 &= V_187 ;
V_186 |= V_95 -> V_174 & ~ V_187 ;
F_110 ( V_175 , V_186 ) ;
V_186 = F_107 ( V_177 ) ;
V_186 &= V_188 ;
V_186 |= V_95 -> V_176 & ~ V_188 ;
F_110 ( V_177 , V_186 ) ;
F_110 ( V_179 , V_95 -> V_178 ) ;
F_110 ( V_181 , V_95 -> V_180 ) ;
F_110 ( V_183 , V_95 -> V_182 ) ;
F_110 ( V_185 , V_95 -> V_184 ) ;
}
int F_111 ( struct V_3 * V_4 , bool V_189 )
{
T_3 V_186 ;
int V_190 ;
V_186 = F_107 ( V_177 ) ;
F_5 ( ! ! ( V_186 & V_188 ) == V_189 ) ;
#define F_112 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
if ( V_189 ) {
V_190 = F_113 ( ! F_112 , 20 ) ;
if ( V_190 ) {
F_53 ( L_23 ,
F_107 ( V_177 ) ) ;
return V_190 ;
}
}
V_186 = F_107 ( V_177 ) ;
V_186 &= ~ V_188 ;
if ( V_189 )
V_186 |= V_188 ;
F_110 ( V_177 , V_186 ) ;
if ( ! V_189 )
return 0 ;
V_190 = F_113 ( F_112 , 20 ) ;
if ( V_190 )
F_53 ( L_24 ,
F_107 ( V_177 ) ) ;
return V_190 ;
#undef F_112
}
static int F_114 ( struct V_3 * V_4 , bool V_191 )
{
T_3 V_186 ;
int V_190 = 0 ;
V_186 = F_107 ( V_175 ) ;
V_186 &= ~ V_187 ;
if ( V_191 )
V_186 |= V_187 ;
F_110 ( V_175 , V_186 ) ;
F_115 ( V_175 ) ;
#define F_112 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_190 = F_113 ( F_112 , 1 ) ;
if ( V_190 )
F_53 ( L_25 ) ;
return V_190 ;
#undef F_112
}
static int F_116 ( struct V_3 * V_4 ,
bool V_192 )
{
T_3 V_193 ;
T_3 V_186 ;
int V_190 ;
V_193 = V_194 | V_195 ;
V_186 = V_192 ? V_193 : 0 ;
#define F_112 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_112 )
return 0 ;
F_4 ( L_26 ,
V_192 ? L_27 : L_28 ,
F_107 ( V_196 ) ) ;
V_190 = F_113 ( F_112 , 3 ) ;
if ( V_190 )
F_53 ( L_29 ,
V_192 ? L_27 : L_28 ) ;
return V_190 ;
#undef F_112
}
static void F_117 ( struct V_3 * V_4 )
{
if ( ! ( F_107 ( V_196 ) & V_197 ) )
return;
F_53 ( L_30 ) ;
F_110 ( V_196 , V_197 ) ;
}
static int F_118 ( struct V_3 * V_4 )
{
T_3 V_193 ;
int V_190 ;
( void ) F_116 ( V_4 , false ) ;
V_193 = V_198 | V_199 ;
F_5 ( ( F_107 ( V_175 ) & V_193 ) != V_193 ) ;
F_117 ( V_4 ) ;
V_190 = F_111 ( V_4 , true ) ;
if ( V_190 )
goto V_200;
V_190 = F_114 ( V_4 , false ) ;
if ( V_190 )
goto V_201;
F_106 ( V_4 ) ;
V_190 = F_111 ( V_4 , false ) ;
if ( V_190 )
goto V_201;
return 0 ;
V_201:
F_114 ( V_4 , true ) ;
V_200:
F_111 ( V_4 , false ) ;
return V_190 ;
}
static int F_78 ( struct V_3 * V_4 ,
bool V_202 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_190 ;
int V_60 ;
V_60 = F_111 ( V_4 , true ) ;
F_109 ( V_4 ) ;
V_190 = F_114 ( V_4 , true ) ;
if ( ! V_60 )
V_60 = V_190 ;
V_190 = F_111 ( V_4 , false ) ;
if ( ! V_60 )
V_60 = V_190 ;
F_117 ( V_4 ) ;
if ( V_202 ) {
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
}
return V_60 ;
}
static int F_121 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_100 ( V_15 ) ;
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 ;
if ( F_57 ( ! ( V_4 -> V_203 . V_204 && F_122 ( V_2 ) ) ) )
return - V_63 ;
if ( F_57 ( ! F_123 ( V_2 ) ) )
return - V_63 ;
F_124 ( V_4 ) ;
F_4 ( L_31 ) ;
if ( ! F_125 ( & V_2 -> V_70 ) ) {
F_4 ( L_32 ) ;
F_126 ( V_15 ) ;
return - V_205 ;
}
F_127 ( V_4 ) ;
F_30 ( & V_2 -> V_70 ) ;
F_37 ( V_2 ) ;
F_41 ( V_4 ) ;
V_60 = F_52 ( V_4 ) ;
if ( V_60 ) {
F_53 ( L_33 , V_60 ) ;
F_66 ( V_4 ) ;
return V_60 ;
}
F_128 ( & V_4 -> V_72 . V_206 ) ;
V_4 -> V_207 . V_208 = true ;
if ( F_9 ( V_2 ) ) {
F_47 ( V_2 , V_56 ) ;
} else {
F_47 ( V_2 , V_61 ) ;
}
F_4 ( L_34 ) ;
return 0 ;
}
static int F_129 ( struct V_15 * V_15 )
{
struct V_6 * V_51 = F_100 ( V_15 ) ;
struct V_1 * V_2 = F_97 ( V_51 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_60 = 0 ;
if ( F_57 ( ! F_123 ( V_2 ) ) )
return - V_63 ;
F_4 ( L_35 ) ;
F_47 ( V_2 , V_78 ) ;
V_4 -> V_207 . V_208 = false ;
if ( F_7 ( V_4 ) )
F_62 ( V_2 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_80 ( V_4 ) ;
else if ( F_77 ( V_4 ) )
V_60 = F_78 ( V_4 , true ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
F_66 ( V_4 ) ;
F_91 ( V_2 ) ;
if ( V_60 )
F_53 ( L_36 , V_60 ) ;
else
F_4 ( L_37 ) ;
return V_60 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_60 ;
if ( F_9 ( V_2 ) || F_10 ( V_2 ) )
V_60 = F_104 ( V_4 ) ;
else if ( F_77 ( V_2 ) )
V_60 = F_118 ( V_4 ) ;
else
V_60 = 0 ;
return V_60 ;
}
static int T_4 F_132 ( void )
{
V_91 . V_209 = V_210 ;
#if F_133 ( V_211 )
if ( V_30 . V_212 != 0 )
V_91 . V_92 |= V_52 ;
#endif
if ( V_30 . V_212 == 1 )
V_91 . V_92 |= V_52 ;
#ifdef F_134
if ( F_135 () && V_30 . V_212 == - 1 )
V_91 . V_92 &= ~ V_52 ;
#endif
if ( ! ( V_91 . V_92 & V_52 ) ) {
V_91 . V_213 = NULL ;
#ifndef F_136
F_137 ( L_38 ) ;
return 0 ;
#endif
}
return F_138 ( & V_91 , & V_214 ) ;
}
static void T_5 F_139 ( void )
{
#ifndef F_136
if ( ! ( V_91 . V_92 & V_52 ) )
return;
#endif
F_140 ( & V_91 , & V_214 ) ;
}
