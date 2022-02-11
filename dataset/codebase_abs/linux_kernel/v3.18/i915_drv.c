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
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( F_10 ( V_2 ) ) ;
} else if ( F_11 ( V_2 ) ) {
V_4 -> V_9 = V_24 ;
V_4 -> V_17 =
V_25 ;
F_4 ( L_5
L_6 ) ;
} else if ( V_14 == V_25 ) {
V_4 -> V_9 = V_24 ;
F_4 ( L_7 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( ! F_10 ( V_2 ) ) ;
} else
continue;
break;
}
}
if ( ! V_7 )
F_4 ( L_8 ) ;
F_12 ( V_7 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_26 < 6 )
return false ;
if ( V_27 . V_28 >= 0 )
return V_27 . V_28 ;
if ( V_27 . V_29 )
return false ;
if ( F_14 ( V_2 ) )
return false ;
#ifdef F_15
if ( F_2 ( V_2 ) -> V_26 == 6 && V_30 )
return false ;
#endif
return true ;
}
void F_16 ( struct V_3 * V_4 )
{
F_17 ( & V_4 -> V_31 ) ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = 0 ;
F_18 ( & V_4 -> V_31 ) ;
F_19 ( & V_4 -> V_35 ) ;
F_19 ( & V_4 -> V_36 ) ;
F_20 ( & V_4 -> V_37 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_38 * V_39 ;
F_22 ( V_2 ) ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_40 * V_40 = F_24 ( V_39 ) ;
if ( V_40 -> V_41 )
V_40 -> V_41 ( V_40 ) ;
}
F_25 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 ;
T_1 V_44 ;
F_27 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_47 ;
F_28 ( & V_4 -> V_45 ) ;
F_29 ( V_4 , true ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 -> V_48 ) ;
if ( F_32 ( V_2 , V_49 ) ) {
int error ;
error = F_33 ( V_2 ) ;
if ( error ) {
F_34 ( & V_2 -> V_48 -> V_2 ,
L_9 ) ;
return error ;
}
F_22 ( V_2 ) ;
F_35 (dev, crtc)
F_36 ( V_43 , false ) ;
F_25 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_4 -> V_50 . V_51 ) ;
F_39 ( V_2 ) ;
F_16 ( V_4 ) ;
F_21 ( V_4 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
V_44 = V_52 ;
#if F_44 ( V_53 )
if ( F_45 () < V_54 )
V_44 = V_55 ;
#endif
F_46 ( V_2 , V_44 ) ;
F_47 ( V_2 , false ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 , V_56 , true ) ;
V_4 -> V_57 ++ ;
F_29 ( V_4 , false ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_58 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_51 ( L_10 , V_2 ) ;
F_51 ( L_11 ) ;
return - V_59 ;
}
if ( V_58 . V_60 == V_61 )
return 0 ;
if ( V_2 -> V_62 == V_63 )
return 0 ;
error = F_26 ( V_2 ) ;
if ( error )
return error ;
if ( V_58 . V_60 == V_64 ) {
F_52 ( V_2 -> V_48 ) ;
F_53 ( V_2 -> V_48 , V_65 ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
V_66 = F_55 ( V_4 , false ) ;
if ( V_66 )
F_51 ( L_12 , V_66 ) ;
F_56 ( V_2 , true ) ;
F_57 ( V_2 ) ;
F_58 ( V_4 ) ;
return V_66 ;
}
static int F_59 ( struct V_1 * V_2 , bool V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_32 ( V_2 , V_49 ) &&
V_67 ) {
F_27 ( & V_2 -> V_68 ) ;
F_60 ( V_2 ) ;
F_28 ( & V_2 -> V_68 ) ;
}
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
if ( F_32 ( V_2 , V_49 ) ) {
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_27 ( & V_2 -> V_68 ) ;
if ( F_65 ( V_2 ) ) {
F_51 ( L_13 ) ;
F_66 ( V_69 , & V_4 -> V_70 . V_71 ) ;
}
F_28 ( & V_2 -> V_68 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
{
unsigned long V_72 ;
F_69 ( & V_4 -> V_31 , V_72 ) ;
if ( V_4 -> V_73 . V_74 )
V_4 -> V_73 . V_74 ( V_2 ) ;
F_70 ( & V_4 -> V_31 , V_72 ) ;
}
F_71 ( V_2 ) ;
F_22 ( V_2 ) ;
F_72 ( V_2 , true ) ;
F_25 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
}
F_75 ( V_2 ) ;
F_49 ( V_2 , V_75 , false ) ;
F_27 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_76 ;
F_28 ( & V_4 -> V_45 ) ;
F_46 ( V_2 , V_77 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 , V_49 ) )
F_77 ( V_2 ) ;
return F_59 ( V_2 , true ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 == V_63 )
return 0 ;
if ( F_79 ( V_2 -> V_48 ) )
return - V_78 ;
F_80 ( V_2 -> V_48 ) ;
return F_54 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
V_66 = F_59 ( V_2 , ! V_4 -> V_79 . V_80 ) ;
if ( V_66 )
return V_66 ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_81 ;
int V_66 ;
if ( ! V_27 . V_82 )
return 0 ;
F_27 ( & V_2 -> V_68 ) ;
F_85 ( V_2 ) ;
V_81 = V_4 -> V_70 . V_83 != 0 ;
V_66 = F_86 ( V_2 ) ;
if ( V_81 ) {
F_87 ( L_14 ) ;
V_4 -> V_70 . V_83 = 0 ;
if ( V_66 == - V_59 ) {
F_87 ( L_15
L_16 ) ;
V_66 = 0 ;
}
}
if ( V_66 ) {
F_51 ( L_17 , V_66 ) ;
F_28 ( & V_2 -> V_68 ) ;
return V_66 ;
}
if ( F_32 ( V_2 , V_49 ) ||
! V_4 -> V_84 . V_85 ) {
V_4 -> V_84 . V_85 = 0 ;
V_4 -> V_70 . V_86 = true ;
V_66 = F_65 ( V_2 ) ;
V_4 -> V_70 . V_86 = false ;
F_28 ( & V_2 -> V_68 ) ;
if ( V_66 ) {
F_51 ( L_18 , V_66 ) ;
return V_66 ;
}
if ( F_2 ( V_2 ) -> V_26 > 5 )
F_88 ( V_2 ) ;
} else {
F_28 ( & V_2 -> V_68 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_48 , const struct V_87 * V_88 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_88 -> V_91 ;
if ( F_90 ( V_90 ) && ! V_27 . V_92 ) {
F_87 ( L_19
L_20 ) ;
return - V_59 ;
}
if ( F_91 ( V_48 -> V_93 ) )
return - V_59 ;
V_94 . V_95 &= ~ ( V_96 ) ;
return F_92 ( V_48 , V_88 , & V_94 ) ;
}
static void
F_93 ( struct V_6 * V_48 )
{
struct V_1 * V_2 = F_94 ( V_48 ) ;
F_95 ( V_2 ) ;
}
static int F_96 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
if ( ! V_97 || ! V_97 -> V_5 ) {
F_34 ( V_2 , L_11 ) ;
return - V_59 ;
}
if ( V_97 -> V_62 == V_63 )
return 0 ;
return F_26 ( V_97 ) ;
}
static int F_98 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
struct V_3 * V_4 = V_97 -> V_5 ;
int V_66 ;
if ( V_97 -> V_62 == V_63 )
return 0 ;
V_66 = F_99 ( V_4 ) ;
if ( V_66 )
F_51 ( L_21 , V_66 ) ;
else {
F_52 ( V_48 ) ;
F_53 ( V_48 , V_65 ) ;
}
return V_66 ;
}
static int F_100 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
return F_78 ( V_97 ) ;
}
static int F_101 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
return F_81 ( V_97 ) ;
}
static int F_102 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
if ( ! V_97 || ! V_97 -> V_5 ) {
F_34 ( V_2 , L_11 ) ;
return - V_59 ;
}
return F_26 ( V_97 ) ;
}
static int F_103 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
struct V_3 * V_4 = V_97 -> V_5 ;
return F_99 ( V_4 ) ;
}
static int F_104 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
return F_54 ( V_97 ) ;
}
static int F_105 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
return F_76 ( V_97 ) ;
}
static int F_106 ( struct V_15 * V_2 )
{
struct V_6 * V_48 = F_97 ( V_2 ) ;
struct V_1 * V_97 = F_94 ( V_48 ) ;
return F_26 ( V_97 ) ;
}
static int F_107 ( struct V_3 * V_4 )
{
F_108 ( V_4 ) ;
return 0 ;
}
static int F_109 ( struct V_3 * V_4 ,
bool V_98 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_98 )
F_63 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_3 * V_4 ,
bool V_98 )
{
F_111 ( V_4 ) ;
return 0 ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_99 * V_100 = & V_4 -> V_99 ;
int V_101 ;
V_100 -> V_102 = F_113 ( V_103 ) ;
V_100 -> V_104 = F_113 ( V_105 ) ;
V_100 -> V_106 = F_113 ( V_107 ) ;
V_100 -> V_108 = F_113 ( V_109 ) ;
V_100 -> V_110 = F_113 ( V_111 ) ;
for ( V_101 = 0 ; V_101 < F_114 ( V_100 -> V_112 ) ; V_101 ++ )
V_100 -> V_112 [ V_101 ] = F_113 ( V_113 + V_101 * 4 ) ;
V_100 -> V_114 = F_113 ( V_115 ) ;
V_100 -> V_116 = F_113 ( V_115 ) ;
V_100 -> V_117 = F_113 ( V_118 ) ;
V_100 -> V_119 = F_113 ( V_120 ) ;
V_100 -> V_121 = F_113 ( V_122 ) ;
V_100 -> V_123 = F_113 ( V_124 ) ;
V_100 -> V_125 = F_113 ( V_126 ) ;
V_100 -> V_127 = F_113 ( V_128 ) ;
V_100 -> V_129 = F_113 ( V_130 ) ;
V_100 -> V_131 = F_113 ( V_132 ) ;
V_100 -> V_133 = F_113 ( V_134 ) ;
V_100 -> V_135 = F_113 ( V_136 ) ;
V_100 -> V_137 = F_113 ( V_138 ) ;
V_100 -> V_139 = F_113 ( V_140 ) ;
V_100 -> V_141 = F_113 ( V_142 ) ;
V_100 -> V_143 = F_113 ( V_144 ) ;
V_100 -> V_145 = F_113 ( V_146 ) ;
V_100 -> V_147 = F_113 ( V_148 ) ;
V_100 -> V_149 = F_113 ( V_150 ) ;
V_100 -> V_151 = F_113 ( V_152 ) ;
V_100 -> V_153 = F_113 ( V_154 ) ;
V_100 -> V_155 = F_113 ( V_156 ) ;
V_100 -> V_157 = F_113 ( V_158 ) ;
V_100 -> V_159 = F_113 ( V_160 ) ;
V_100 -> V_161 = F_113 ( V_162 ) ;
V_100 -> V_163 = F_113 ( V_164 ) ;
V_100 -> V_165 = F_113 ( V_166 ) ;
V_100 -> V_167 = F_113 ( V_168 ) ;
V_100 -> V_169 = F_113 ( V_170 ) ;
V_100 -> V_171 = F_113 ( V_172 ) ;
for ( V_101 = 0 ; V_101 < F_114 ( V_100 -> V_173 ) ; V_101 ++ )
V_100 -> V_173 [ V_101 ] = F_113 ( V_174 + V_101 * 4 ) ;
V_100 -> V_175 = F_113 ( V_176 ) ;
V_100 -> V_177 = F_113 ( V_178 ) ;
V_100 -> V_179 = F_113 ( V_180 ) ;
V_100 -> V_181 = F_113 ( V_182 ) ;
V_100 -> V_183 = F_113 ( V_184 ) ;
V_100 -> V_185 = F_113 ( V_186 ) ;
V_100 -> V_187 = F_113 ( V_188 ) ;
V_100 -> V_189 = F_113 ( V_190 ) ;
}
static void F_115 ( struct V_3 * V_4 )
{
struct V_99 * V_100 = & V_4 -> V_99 ;
T_3 V_191 ;
int V_101 ;
F_116 ( V_103 , V_100 -> V_102 ) ;
F_116 ( V_105 , V_100 -> V_104 ) ;
F_116 ( V_107 , V_100 -> V_106 | ( 0xffff << 16 ) ) ;
F_116 ( V_109 , V_100 -> V_108 ) ;
F_116 ( V_111 , V_100 -> V_110 ) ;
for ( V_101 = 0 ; V_101 < F_114 ( V_100 -> V_112 ) ; V_101 ++ )
F_116 ( V_113 + V_101 * 4 , V_100 -> V_112 [ V_101 ] ) ;
F_116 ( V_115 , V_100 -> V_114 ) ;
F_116 ( V_115 , V_100 -> V_116 ) ;
F_116 ( V_118 , V_100 -> V_117 ) ;
F_116 ( V_120 , V_100 -> V_119 ) ;
F_116 ( V_122 , V_100 -> V_121 ) ;
F_116 ( V_124 , V_100 -> V_123 ) ;
F_116 ( V_126 , V_100 -> V_125 ) ;
F_116 ( V_128 , V_100 -> V_127 ) ;
F_116 ( V_130 , V_100 -> V_129 ) ;
F_116 ( V_132 , V_100 -> V_131 ) ;
F_116 ( V_134 , V_100 -> V_133 ) ;
F_116 ( V_136 , V_100 -> V_135 ) ;
F_116 ( V_138 , V_100 -> V_137 ) ;
F_116 ( V_140 , V_100 -> V_139 ) ;
F_116 ( V_142 , V_100 -> V_141 ) ;
F_116 ( V_144 , V_100 -> V_143 ) ;
F_116 ( V_146 , V_100 -> V_145 ) ;
F_116 ( V_148 , V_100 -> V_147 ) ;
F_116 ( V_150 , V_100 -> V_149 ) ;
F_116 ( V_152 , V_100 -> V_151 ) ;
F_116 ( V_154 , V_100 -> V_153 ) ;
F_116 ( V_156 , V_100 -> V_155 ) ;
F_116 ( V_158 , V_100 -> V_157 ) ;
F_116 ( V_160 , V_100 -> V_159 ) ;
F_116 ( V_162 , V_100 -> V_161 ) ;
F_116 ( V_164 , V_100 -> V_163 ) ;
F_116 ( V_166 , V_100 -> V_165 ) ;
F_116 ( V_168 , V_100 -> V_167 ) ;
F_116 ( V_170 , V_100 -> V_169 ) ;
F_116 ( V_172 , V_100 -> V_171 ) ;
for ( V_101 = 0 ; V_101 < F_114 ( V_100 -> V_173 ) ; V_101 ++ )
F_116 ( V_174 + V_101 * 4 , V_100 -> V_173 [ V_101 ] ) ;
F_116 ( V_176 , V_100 -> V_175 ) ;
F_116 ( V_178 , V_100 -> V_177 ) ;
V_191 = F_113 ( V_180 ) ;
V_191 &= V_192 ;
V_191 |= V_100 -> V_179 & ~ V_192 ;
F_116 ( V_180 , V_191 ) ;
V_191 = F_113 ( V_182 ) ;
V_191 &= V_193 ;
V_191 |= V_100 -> V_181 & ~ V_193 ;
F_116 ( V_182 , V_191 ) ;
F_116 ( V_184 , V_100 -> V_183 ) ;
F_116 ( V_186 , V_100 -> V_185 ) ;
F_116 ( V_188 , V_100 -> V_187 ) ;
F_116 ( V_190 , V_100 -> V_189 ) ;
}
int F_117 ( struct V_3 * V_4 , bool V_194 )
{
T_3 V_191 ;
int V_195 ;
V_191 = F_113 ( V_182 ) ;
F_5 ( ! ! ( V_191 & V_193 ) == V_194 ) ;
#define F_118 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
if ( V_194 ) {
V_195 = F_119 ( ! F_118 , 20 ) ;
if ( V_195 ) {
F_51 ( L_22 ,
F_113 ( V_182 ) ) ;
return V_195 ;
}
}
V_191 = F_113 ( V_182 ) ;
V_191 &= ~ V_193 ;
if ( V_194 )
V_191 |= V_193 ;
F_116 ( V_182 , V_191 ) ;
if ( ! V_194 )
return 0 ;
V_195 = F_119 ( F_118 , 20 ) ;
if ( V_195 )
F_51 ( L_23 ,
F_113 ( V_182 ) ) ;
return V_195 ;
#undef F_118
}
static int F_120 ( struct V_3 * V_4 , bool V_196 )
{
T_3 V_191 ;
int V_195 = 0 ;
V_191 = F_113 ( V_180 ) ;
V_191 &= ~ V_192 ;
if ( V_196 )
V_191 |= V_192 ;
F_116 ( V_180 , V_191 ) ;
F_121 ( V_180 ) ;
#define F_118 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_195 = F_119 ( F_118 , 1 ) ;
if ( V_195 )
F_51 ( L_24 ) ;
return V_195 ;
#undef F_118
}
static int F_122 ( struct V_3 * V_4 ,
bool V_197 )
{
T_3 V_198 ;
T_3 V_191 ;
int V_195 ;
V_198 = V_199 | V_200 ;
V_191 = V_197 ? V_198 : 0 ;
#define F_118 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_118 )
return 0 ;
F_4 ( L_25 ,
V_197 ? L_26 : L_27 ,
F_113 ( V_201 ) ) ;
V_195 = F_119 ( F_118 , 3 ) ;
if ( V_195 )
F_51 ( L_28 ,
V_197 ? L_26 : L_27 ) ;
return V_195 ;
#undef F_118
}
static void F_123 ( struct V_3 * V_4 )
{
if ( ! ( F_113 ( V_201 ) & V_202 ) )
return;
F_51 ( L_29 ) ;
F_116 ( V_201 , V_202 ) ;
}
static int F_124 ( struct V_3 * V_4 )
{
T_3 V_198 ;
int V_195 ;
( void ) F_122 ( V_4 , false ) ;
V_198 = V_203 | V_204 ;
F_5 ( ( F_113 ( V_180 ) & V_198 ) != V_198 ) ;
F_123 ( V_4 ) ;
V_195 = F_117 ( V_4 , true ) ;
if ( V_195 )
goto V_205;
V_195 = F_120 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
F_112 ( V_4 ) ;
V_195 = F_117 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
return 0 ;
V_206:
F_120 ( V_4 , true ) ;
V_205:
F_117 ( V_4 , false ) ;
return V_195 ;
}
static int F_125 ( struct V_3 * V_4 ,
bool V_98 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_195 ;
int V_66 ;
V_66 = F_117 ( V_4 , true ) ;
F_115 ( V_4 ) ;
V_195 = F_120 ( V_4 , true ) ;
if ( ! V_66 )
V_66 = V_195 ;
V_195 = F_117 ( V_4 , false ) ;
if ( ! V_66 )
V_66 = V_195 ;
F_123 ( V_4 ) ;
if ( V_98 ) {
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
}
return V_66 ;
}
static int F_128 ( struct V_15 * V_15 )
{
struct V_6 * V_48 = F_97 ( V_15 ) ;
struct V_1 * V_2 = F_94 ( V_48 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
if ( F_129 ( ! ( V_4 -> V_50 . V_207 && F_130 ( V_2 ) ) ) )
return - V_59 ;
if ( F_129 ( ! F_131 ( V_2 ) ) )
return - V_59 ;
F_132 ( V_4 ) ;
F_4 ( L_30 ) ;
if ( ! F_133 ( & V_2 -> V_68 ) ) {
F_4 ( L_31 ) ;
F_134 ( V_15 ) ;
return - V_208 ;
}
F_135 ( V_4 ) ;
F_28 ( & V_2 -> V_68 ) ;
F_19 ( & V_4 -> V_50 . V_209 ) ;
F_39 ( V_2 ) ;
V_66 = F_99 ( V_4 ) ;
if ( V_66 ) {
F_51 ( L_32 , V_66 ) ;
F_67 ( V_2 ) ;
return V_66 ;
}
F_136 ( & V_4 -> V_70 . V_210 ) ;
V_4 -> V_211 . V_212 = true ;
if ( F_9 ( V_2 ) ) {
F_46 ( V_2 , V_55 ) ;
} else {
F_46 ( V_2 , V_65 ) ;
}
F_4 ( L_33 ) ;
return 0 ;
}
static int F_137 ( struct V_15 * V_15 )
{
struct V_6 * V_48 = F_97 ( V_15 ) ;
struct V_1 * V_2 = F_94 ( V_48 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
if ( F_129 ( ! F_131 ( V_2 ) ) )
return - V_59 ;
F_4 ( L_34 ) ;
F_46 ( V_2 , V_77 ) ;
V_4 -> V_211 . V_212 = false ;
V_66 = F_55 ( V_4 , true ) ;
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
F_67 ( V_2 ) ;
F_88 ( V_2 ) ;
if ( V_66 )
F_51 ( L_35 , V_66 ) ;
else
F_4 ( L_36 ) ;
return V_66 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_66 ;
if ( F_9 ( V_2 ) || F_11 ( V_2 ) )
V_66 = F_107 ( V_4 ) ;
else if ( F_140 ( V_2 ) )
V_66 = F_124 ( V_4 ) ;
else
V_66 = 0 ;
return V_66 ;
}
static int F_55 ( struct V_3 * V_4 ,
bool V_98 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_66 ;
if ( F_7 ( V_2 ) )
V_66 = F_109 ( V_4 , V_98 ) ;
else if ( F_9 ( V_2 ) || F_11 ( V_2 ) )
V_66 = F_110 ( V_4 , V_98 ) ;
else if ( F_140 ( V_2 ) )
V_66 = F_125 ( V_4 , V_98 ) ;
else
V_66 = 0 ;
return V_66 ;
}
static int T_4 F_141 ( void )
{
V_94 . V_213 = V_214 ;
#if F_142 ( V_215 )
if ( V_27 . V_216 != 0 )
V_94 . V_95 |= V_49 ;
#endif
if ( V_27 . V_216 == 1 )
V_94 . V_95 |= V_49 ;
#ifdef F_143
if ( F_144 () && V_27 . V_216 == - 1 )
V_94 . V_95 &= ~ V_49 ;
#endif
if ( ! ( V_94 . V_95 & V_49 ) ) {
V_94 . V_217 = NULL ;
#ifndef F_145
F_146 ( L_37 ) ;
return 0 ;
#endif
}
return F_147 ( & V_94 , & V_218 ) ;
}
static void T_5 F_148 ( void )
{
#ifndef F_145
if ( ! ( V_94 . V_95 & V_49 ) )
return;
#endif
F_149 ( & V_94 , & V_218 ) ;
}
