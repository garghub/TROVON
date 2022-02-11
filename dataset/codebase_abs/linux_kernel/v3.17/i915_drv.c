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
if ( F_14 ( V_2 ) )
return false ;
#ifdef F_15
if ( F_2 ( V_2 ) -> V_26 == 6 && V_29 )
return false ;
#endif
return true ;
}
void F_16 ( struct V_3 * V_4 )
{
F_17 ( & V_4 -> V_30 ) ;
V_4 -> V_31 = 0 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 = 0 ;
F_18 ( & V_4 -> V_30 ) ;
F_19 ( & V_4 -> V_34 ) ;
F_19 ( & V_4 -> V_35 ) ;
F_20 ( & V_4 -> V_36 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_37 * V_38 ;
F_22 ( V_2 ) ;
F_23 (encoder, &dev->mode_config.encoder_list, head) {
struct V_39 * V_39 = F_24 ( V_38 ) ;
if ( V_39 -> V_40 )
V_39 -> V_40 ( V_39 ) ;
}
F_25 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_41 * V_42 ;
T_1 V_43 ;
F_27 ( & V_4 -> V_44 ) ;
V_4 -> V_45 = V_46 ;
F_28 ( & V_4 -> V_44 ) ;
F_29 ( V_4 , true ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 -> V_47 ) ;
if ( F_32 ( V_2 , V_48 ) ) {
int error ;
error = F_33 ( V_2 ) ;
if ( error ) {
F_34 ( & V_2 -> V_47 -> V_2 ,
L_9 ) ;
return error ;
}
F_22 ( V_2 ) ;
F_35 (dev, crtc)
F_36 ( V_42 , false ) ;
F_25 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_4 -> V_49 . V_50 ) ;
F_39 ( V_2 ) ;
F_16 ( V_4 ) ;
F_21 ( V_4 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
V_43 = V_51 ;
#if F_44 ( V_52 )
if ( F_45 () < V_53 )
V_43 = V_54 ;
#endif
F_46 ( V_2 , V_43 ) ;
F_47 ( V_2 , false ) ;
F_48 ( V_2 ) ;
F_49 () ;
F_50 ( V_2 , V_55 ) ;
F_51 () ;
V_4 -> V_56 ++ ;
F_29 ( V_4 , false ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_2 V_57 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_53 ( L_10 , V_2 ) ;
F_53 ( L_11 ) ;
return - V_58 ;
}
if ( V_57 . V_59 == V_60 )
return 0 ;
if ( V_2 -> V_61 == V_62 )
return 0 ;
error = F_26 ( V_2 ) ;
if ( error )
return error ;
if ( V_57 . V_59 == V_63 ) {
F_54 ( V_2 -> V_47 ) ;
F_55 ( V_2 -> V_47 , V_64 ) ;
}
return 0 ;
}
void F_56 ( struct V_65 * V_66 )
{
struct V_3 * V_4 =
F_57 ( V_66 , struct V_3 ,
V_67 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_49 () ;
F_50 ( V_2 , V_68 ) ;
F_51 () ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_9 ( V_2 ) || F_11 ( V_2 ) )
F_59 ( V_4 ) ;
F_60 ( V_2 , true ) ;
F_61 ( V_2 ) ;
F_62 ( V_4 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , bool V_69 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_32 ( V_2 , V_48 ) &&
V_69 ) {
F_27 ( & V_2 -> V_70 ) ;
F_64 ( V_2 ) ;
F_28 ( & V_2 -> V_70 ) ;
}
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( F_32 ( V_2 , V_48 ) ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
F_27 ( & V_2 -> V_70 ) ;
if ( F_69 ( V_2 ) ) {
F_53 ( L_12 ) ;
F_70 ( V_71 , & V_4 -> V_72 . V_73 ) ;
}
F_28 ( & V_2 -> V_70 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
{
unsigned long V_74 ;
F_73 ( & V_4 -> V_30 , V_74 ) ;
if ( V_4 -> V_75 . V_76 )
V_4 -> V_75 . V_76 ( V_2 ) ;
F_74 ( & V_4 -> V_30 , V_74 ) ;
}
F_75 ( V_2 ) ;
F_22 ( V_2 ) ;
F_76 ( V_2 , true ) ;
F_25 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
}
F_79 ( V_2 ) ;
if ( F_80 () ) {
F_50 ( V_2 , V_68 ) ;
F_51 () ;
} else {
F_81 ( & V_4 -> V_67 ) ;
}
F_27 ( & V_4 -> V_44 ) ;
V_4 -> V_45 = V_77 ;
F_28 ( & V_4 -> V_44 ) ;
F_46 ( V_2 , V_78 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 , V_48 ) )
F_83 ( V_2 ) ;
return F_63 ( V_2 , true ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 == V_62 )
return 0 ;
if ( F_85 ( V_2 -> V_47 ) )
return - V_79 ;
F_86 ( V_2 -> V_47 ) ;
return F_58 ( V_2 ) ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 ;
V_80 = F_63 ( V_2 , ! V_4 -> V_81 . V_82 ) ;
if ( V_80 )
return V_80 ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_83 ;
int V_80 ;
if ( ! V_27 . V_84 )
return 0 ;
F_27 ( & V_2 -> V_70 ) ;
F_91 ( V_2 ) ;
V_83 = V_4 -> V_72 . V_85 != 0 ;
V_80 = F_92 ( V_2 ) ;
if ( V_83 ) {
F_93 ( L_13 ) ;
V_4 -> V_72 . V_85 = 0 ;
if ( V_80 == - V_58 ) {
F_93 ( L_14
L_15 ) ;
V_80 = 0 ;
}
}
if ( V_80 ) {
F_53 ( L_16 , V_80 ) ;
F_28 ( & V_2 -> V_70 ) ;
return V_80 ;
}
if ( F_32 ( V_2 , V_48 ) ||
! V_4 -> V_86 . V_87 ) {
V_4 -> V_86 . V_87 = 0 ;
V_80 = F_69 ( V_2 ) ;
F_28 ( & V_2 -> V_70 ) ;
if ( V_80 ) {
F_53 ( L_17 , V_80 ) ;
return V_80 ;
}
if ( F_2 ( V_2 ) -> V_26 > 5 )
F_94 ( V_2 ) ;
F_77 ( V_2 ) ;
} else {
F_28 ( & V_2 -> V_70 ) ;
}
return 0 ;
}
static int F_95 ( struct V_6 * V_47 , const struct V_88 * V_89 )
{
struct V_90 * V_91 =
(struct V_90 * ) V_89 -> V_92 ;
if ( F_96 ( V_91 ) && ! V_27 . V_93 ) {
F_93 ( L_18
L_19 ) ;
return - V_58 ;
}
if ( F_97 ( V_47 -> V_94 ) )
return - V_58 ;
V_95 . V_96 &= ~ ( V_97 ) ;
return F_98 ( V_47 , V_89 , & V_95 ) ;
}
static void
F_99 ( struct V_6 * V_47 )
{
struct V_1 * V_2 = F_100 ( V_47 ) ;
F_101 ( V_2 ) ;
}
static int F_102 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
if ( ! V_98 || ! V_98 -> V_5 ) {
F_34 ( V_2 , L_11 ) ;
return - V_58 ;
}
if ( V_98 -> V_61 == V_62 )
return 0 ;
return F_26 ( V_98 ) ;
}
static int F_104 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
struct V_3 * V_4 = V_98 -> V_5 ;
if ( V_98 -> V_61 == V_62 )
return 0 ;
if ( F_9 ( V_98 ) || F_11 ( V_98 ) )
F_105 ( V_4 ) ;
F_54 ( V_47 ) ;
F_55 ( V_47 , V_64 ) ;
return 0 ;
}
static int F_106 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
return F_84 ( V_98 ) ;
}
static int F_107 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
return F_87 ( V_98 ) ;
}
static int F_108 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
if ( ! V_98 || ! V_98 -> V_5 ) {
F_34 ( V_2 , L_11 ) ;
return - V_58 ;
}
return F_26 ( V_98 ) ;
}
static int F_109 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
return F_58 ( V_98 ) ;
}
static int F_110 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
return F_82 ( V_98 ) ;
}
static int F_111 ( struct V_15 * V_2 )
{
struct V_6 * V_47 = F_103 ( V_2 ) ;
struct V_1 * V_98 = F_100 ( V_47 ) ;
return F_26 ( V_98 ) ;
}
static int F_112 ( struct V_3 * V_4 )
{
F_105 ( V_4 ) ;
return 0 ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_3 * V_4 )
{
F_59 ( V_4 ) ;
return 0 ;
}
static void F_115 ( struct V_3 * V_4 )
{
struct V_99 * V_100 = & V_4 -> V_99 ;
int V_101 ;
V_100 -> V_102 = F_116 ( V_103 ) ;
V_100 -> V_104 = F_116 ( V_105 ) ;
V_100 -> V_106 = F_116 ( V_107 ) ;
V_100 -> V_108 = F_116 ( V_109 ) ;
V_100 -> V_110 = F_116 ( V_111 ) ;
for ( V_101 = 0 ; V_101 < F_117 ( V_100 -> V_112 ) ; V_101 ++ )
V_100 -> V_112 [ V_101 ] = F_116 ( V_113 + V_101 * 4 ) ;
V_100 -> V_114 = F_116 ( V_115 ) ;
V_100 -> V_116 = F_116 ( V_115 ) ;
V_100 -> V_117 = F_116 ( V_118 ) ;
V_100 -> V_119 = F_116 ( V_120 ) ;
V_100 -> V_121 = F_116 ( V_122 ) ;
V_100 -> V_123 = F_116 ( V_124 ) ;
V_100 -> V_125 = F_116 ( V_126 ) ;
V_100 -> V_127 = F_116 ( V_128 ) ;
V_100 -> V_129 = F_116 ( V_130 ) ;
V_100 -> V_131 = F_116 ( V_132 ) ;
V_100 -> V_133 = F_116 ( V_134 ) ;
V_100 -> V_135 = F_116 ( V_136 ) ;
V_100 -> V_137 = F_116 ( V_138 ) ;
V_100 -> V_139 = F_116 ( V_140 ) ;
V_100 -> V_141 = F_116 ( V_142 ) ;
V_100 -> V_143 = F_116 ( V_144 ) ;
V_100 -> V_145 = F_116 ( V_146 ) ;
V_100 -> V_147 = F_116 ( V_148 ) ;
V_100 -> V_149 = F_116 ( V_150 ) ;
V_100 -> V_151 = F_116 ( V_152 ) ;
V_100 -> V_153 = F_116 ( V_154 ) ;
V_100 -> V_155 = F_116 ( V_156 ) ;
V_100 -> V_157 = F_116 ( V_158 ) ;
V_100 -> V_159 = F_116 ( V_160 ) ;
V_100 -> V_161 = F_116 ( V_162 ) ;
V_100 -> V_163 = F_116 ( V_164 ) ;
V_100 -> V_165 = F_116 ( V_166 ) ;
V_100 -> V_167 = F_116 ( V_168 ) ;
V_100 -> V_169 = F_116 ( V_170 ) ;
V_100 -> V_171 = F_116 ( V_172 ) ;
for ( V_101 = 0 ; V_101 < F_117 ( V_100 -> V_173 ) ; V_101 ++ )
V_100 -> V_173 [ V_101 ] = F_116 ( V_174 + V_101 * 4 ) ;
V_100 -> V_175 = F_116 ( V_176 ) ;
V_100 -> V_177 = F_116 ( V_178 ) ;
V_100 -> V_179 = F_116 ( V_180 ) ;
V_100 -> V_181 = F_116 ( V_182 ) ;
V_100 -> V_183 = F_116 ( V_184 ) ;
V_100 -> V_185 = F_116 ( V_186 ) ;
V_100 -> V_187 = F_116 ( V_188 ) ;
V_100 -> V_189 = F_116 ( V_190 ) ;
}
static void F_118 ( struct V_3 * V_4 )
{
struct V_99 * V_100 = & V_4 -> V_99 ;
T_3 V_191 ;
int V_101 ;
F_119 ( V_103 , V_100 -> V_102 ) ;
F_119 ( V_105 , V_100 -> V_104 ) ;
F_119 ( V_107 , V_100 -> V_106 | ( 0xffff << 16 ) ) ;
F_119 ( V_109 , V_100 -> V_108 ) ;
F_119 ( V_111 , V_100 -> V_110 ) ;
for ( V_101 = 0 ; V_101 < F_117 ( V_100 -> V_112 ) ; V_101 ++ )
F_119 ( V_113 + V_101 * 4 , V_100 -> V_112 [ V_101 ] ) ;
F_119 ( V_115 , V_100 -> V_114 ) ;
F_119 ( V_115 , V_100 -> V_116 ) ;
F_119 ( V_118 , V_100 -> V_117 ) ;
F_119 ( V_120 , V_100 -> V_119 ) ;
F_119 ( V_122 , V_100 -> V_121 ) ;
F_119 ( V_124 , V_100 -> V_123 ) ;
F_119 ( V_126 , V_100 -> V_125 ) ;
F_119 ( V_128 , V_100 -> V_127 ) ;
F_119 ( V_130 , V_100 -> V_129 ) ;
F_119 ( V_132 , V_100 -> V_131 ) ;
F_119 ( V_134 , V_100 -> V_133 ) ;
F_119 ( V_136 , V_100 -> V_135 ) ;
F_119 ( V_138 , V_100 -> V_137 ) ;
F_119 ( V_140 , V_100 -> V_139 ) ;
F_119 ( V_142 , V_100 -> V_141 ) ;
F_119 ( V_144 , V_100 -> V_143 ) ;
F_119 ( V_146 , V_100 -> V_145 ) ;
F_119 ( V_148 , V_100 -> V_147 ) ;
F_119 ( V_150 , V_100 -> V_149 ) ;
F_119 ( V_152 , V_100 -> V_151 ) ;
F_119 ( V_154 , V_100 -> V_153 ) ;
F_119 ( V_156 , V_100 -> V_155 ) ;
F_119 ( V_158 , V_100 -> V_157 ) ;
F_119 ( V_160 , V_100 -> V_159 ) ;
F_119 ( V_162 , V_100 -> V_161 ) ;
F_119 ( V_164 , V_100 -> V_163 ) ;
F_119 ( V_166 , V_100 -> V_165 ) ;
F_119 ( V_168 , V_100 -> V_167 ) ;
F_119 ( V_170 , V_100 -> V_169 ) ;
F_119 ( V_172 , V_100 -> V_171 ) ;
for ( V_101 = 0 ; V_101 < F_117 ( V_100 -> V_173 ) ; V_101 ++ )
F_119 ( V_174 + V_101 * 4 , V_100 -> V_173 [ V_101 ] ) ;
F_119 ( V_176 , V_100 -> V_175 ) ;
F_119 ( V_178 , V_100 -> V_177 ) ;
V_191 = F_116 ( V_180 ) ;
V_191 &= V_192 ;
V_191 |= V_100 -> V_179 & ~ V_192 ;
F_119 ( V_180 , V_191 ) ;
V_191 = F_116 ( V_182 ) ;
V_191 &= V_193 ;
V_191 |= V_100 -> V_181 & ~ V_193 ;
F_119 ( V_182 , V_191 ) ;
F_119 ( V_184 , V_100 -> V_183 ) ;
F_119 ( V_186 , V_100 -> V_185 ) ;
F_119 ( V_188 , V_100 -> V_187 ) ;
F_119 ( V_190 , V_100 -> V_189 ) ;
}
int F_120 ( struct V_3 * V_4 , bool V_194 )
{
T_3 V_191 ;
int V_195 ;
V_191 = F_116 ( V_182 ) ;
F_5 ( ! ! ( V_191 & V_193 ) == V_194 ) ;
#define F_121 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
if ( V_194 ) {
V_195 = F_122 ( ! F_121 , 20 ) ;
if ( V_195 ) {
F_53 ( L_20 ,
F_116 ( V_182 ) ) ;
return V_195 ;
}
}
V_191 = F_116 ( V_182 ) ;
V_191 &= ~ V_193 ;
if ( V_194 )
V_191 |= V_193 ;
F_119 ( V_182 , V_191 ) ;
if ( ! V_194 )
return 0 ;
V_195 = F_122 ( F_121 , 20 ) ;
if ( V_195 )
F_53 ( L_21 ,
F_116 ( V_182 ) ) ;
return V_195 ;
#undef F_121
}
static int F_123 ( struct V_3 * V_4 , bool V_196 )
{
T_3 V_191 ;
int V_195 = 0 ;
V_191 = F_116 ( V_180 ) ;
V_191 &= ~ V_192 ;
if ( V_196 )
V_191 |= V_192 ;
F_119 ( V_180 , V_191 ) ;
F_124 ( V_180 ) ;
#define F_121 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_195 = F_122 ( F_121 , 1 ) ;
if ( V_195 )
F_53 ( L_22 ) ;
return V_195 ;
#undef F_121
}
static int F_125 ( struct V_3 * V_4 ,
bool V_197 )
{
T_3 V_198 ;
T_3 V_191 ;
int V_195 ;
V_198 = V_199 | V_200 ;
V_191 = V_197 ? V_198 : 0 ;
#define F_121 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_121 )
return 0 ;
F_4 ( L_23 ,
V_197 ? L_24 : L_25 ,
F_116 ( V_201 ) ) ;
V_195 = F_122 ( F_121 , 3 ) ;
if ( V_195 )
F_53 ( L_26 ,
V_197 ? L_24 : L_25 ) ;
return V_195 ;
#undef F_121
}
static void F_126 ( struct V_3 * V_4 )
{
if ( ! ( F_116 ( V_201 ) & V_202 ) )
return;
F_53 ( L_27 ) ;
F_119 ( V_201 , V_202 ) ;
}
static int F_127 ( struct V_3 * V_4 )
{
T_3 V_198 ;
int V_195 ;
( void ) F_125 ( V_4 , false ) ;
V_198 = V_203 | V_204 ;
F_5 ( ( F_116 ( V_180 ) & V_198 ) != V_198 ) ;
F_126 ( V_4 ) ;
V_195 = F_120 ( V_4 , true ) ;
if ( V_195 )
goto V_205;
V_195 = F_123 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
F_115 ( V_4 ) ;
V_195 = F_120 ( V_4 , false ) ;
if ( V_195 )
goto V_206;
return 0 ;
V_206:
F_123 ( V_4 , true ) ;
V_205:
F_120 ( V_4 , false ) ;
return V_195 ;
}
static int F_128 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_195 ;
int V_80 ;
V_80 = F_120 ( V_4 , true ) ;
F_118 ( V_4 ) ;
V_195 = F_123 ( V_4 , true ) ;
if ( ! V_80 )
V_80 = V_195 ;
V_195 = F_120 ( V_4 , false ) ;
if ( ! V_80 )
V_80 = V_195 ;
F_126 ( V_4 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
return V_80 ;
}
static int F_131 ( struct V_15 * V_15 )
{
struct V_6 * V_47 = F_103 ( V_15 ) ;
struct V_1 * V_2 = F_100 ( V_47 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 ;
if ( F_132 ( ! ( V_4 -> V_49 . V_207 && F_133 ( V_2 ) ) ) )
return - V_58 ;
F_5 ( ! F_134 ( V_2 ) ) ;
F_135 ( V_4 ) ;
F_4 ( L_28 ) ;
if ( ! F_136 ( & V_2 -> V_70 ) ) {
F_4 ( L_29 ) ;
F_137 ( V_15 ) ;
return - V_208 ;
}
F_138 ( V_4 ) ;
F_28 ( & V_2 -> V_70 ) ;
F_19 ( & V_4 -> V_49 . V_66 ) ;
F_39 ( V_2 ) ;
if ( F_7 ( V_2 ) ) {
V_80 = 0 ;
} else if ( F_9 ( V_2 ) || F_11 ( V_2 ) ) {
V_80 = F_112 ( V_4 ) ;
} else if ( F_139 ( V_2 ) ) {
V_80 = F_127 ( V_4 ) ;
} else {
V_80 = - V_58 ;
F_5 ( 1 ) ;
}
if ( V_80 ) {
F_53 ( L_30 , V_80 ) ;
F_71 ( V_2 ) ;
return V_80 ;
}
F_140 ( & V_4 -> V_72 . V_209 ) ;
V_4 -> V_210 . V_211 = true ;
F_46 ( V_2 , V_54 ) ;
F_4 ( L_31 ) ;
return 0 ;
}
static int F_141 ( struct V_15 * V_15 )
{
struct V_6 * V_47 = F_103 ( V_15 ) ;
struct V_1 * V_2 = F_100 ( V_47 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_80 ;
F_5 ( ! F_134 ( V_2 ) ) ;
F_4 ( L_32 ) ;
F_46 ( V_2 , V_78 ) ;
V_4 -> V_210 . V_211 = false ;
if ( F_7 ( V_2 ) ) {
V_80 = F_113 ( V_4 ) ;
} else if ( F_9 ( V_2 ) || F_11 ( V_2 ) ) {
V_80 = F_114 ( V_4 ) ;
} else if ( F_139 ( V_2 ) ) {
V_80 = F_128 ( V_4 ) ;
} else {
F_5 ( 1 ) ;
V_80 = - V_58 ;
}
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
F_71 ( V_2 ) ;
F_94 ( V_2 ) ;
if ( V_80 )
F_53 ( L_33 , V_80 ) ;
else
F_4 ( L_34 ) ;
return V_80 ;
}
static int T_4 F_144 ( void )
{
V_95 . V_212 = V_213 ;
#if F_145 ( V_214 )
if ( V_27 . V_215 != 0 )
V_95 . V_96 |= V_48 ;
#endif
if ( V_27 . V_215 == 1 )
V_95 . V_96 |= V_48 ;
#ifdef F_146
if ( F_147 () && V_27 . V_215 == - 1 )
V_95 . V_96 &= ~ V_48 ;
#endif
if ( ! ( V_95 . V_96 & V_48 ) ) {
V_95 . V_216 = NULL ;
#ifndef F_148
F_149 ( L_35 ) ;
return 0 ;
#endif
}
return F_150 ( & V_95 , & V_217 ) ;
}
static void T_5 F_151 ( void )
{
#ifndef F_148
if ( ! ( V_95 . V_96 & V_48 ) )
return;
#endif
F_152 ( & V_95 , & V_217 ) ;
}
