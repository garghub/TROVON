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
void F_18 ( const char * V_34 , int V_35 )
{
F_19 ( L_9 , V_34 , V_35 ) ;
if ( ! V_35 )
V_35 = - V_36 ;
if ( ! ( F_20 ( V_37 ) && V_35 == - V_36 ) )
return;
F_19 (
L_10
L_11
L_12 ) ;
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
T_1 V_42 ;
int error ;
F_27 ( & V_4 -> V_43 ) ;
V_4 -> V_44 = V_45 ;
F_28 ( & V_4 -> V_43 ) ;
F_29 ( V_4 , true ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 -> V_46 ) ;
error = F_32 ( V_2 ) ;
if ( error ) {
F_33 ( & V_2 -> V_46 -> V_2 ,
L_13 ) ;
return error ;
}
F_34 ( V_2 ) ;
F_22 ( V_2 ) ;
F_35 ( V_2 ) ;
F_25 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
F_21 ( V_4 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_42 = V_47 ;
#if F_42 ( V_48 )
if ( F_43 () < V_49 )
V_42 = V_50 ;
#endif
F_44 ( V_2 , V_42 ) ;
F_45 ( V_2 , false ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 , V_51 , true ) ;
V_4 -> V_52 ++ ;
F_29 ( V_4 , false ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_53 , bool V_54 )
{
struct V_3 * V_4 = V_53 -> V_5 ;
int V_55 ;
V_55 = F_49 ( V_4 ) ;
if ( V_55 ) {
F_19 ( L_14 , V_55 ) ;
return V_55 ;
}
F_50 ( V_53 -> V_46 ) ;
if ( ! ( V_54 && F_2 ( V_4 ) -> V_29 < 6 ) )
F_51 ( V_53 -> V_46 , V_56 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_2 V_57 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_19 ( L_15 , V_2 ) ;
F_19 ( L_16 ) ;
return - V_58 ;
}
if ( F_53 ( V_57 . V_59 != V_60 &&
V_57 . V_59 != V_61 ) )
return - V_62 ;
if ( V_2 -> V_63 == V_64 )
return 0 ;
error = F_26 ( V_2 ) ;
if ( error )
return error ;
return F_48 ( V_2 , false ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_27 ( & V_2 -> V_65 ) ;
F_55 ( V_2 ) ;
F_28 ( & V_2 -> V_65 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_4 ) ;
F_27 ( & V_2 -> V_65 ) ;
if ( F_61 ( V_2 ) ) {
F_19 ( L_17 ) ;
F_62 ( V_66 , & V_4 -> V_67 . V_68 ) ;
}
F_28 ( & V_2 -> V_65 ) ;
F_63 ( V_2 ) ;
F_64 ( & V_4 -> V_69 ) ;
if ( V_4 -> V_70 . V_71 )
V_4 -> V_70 . V_71 ( V_2 ) ;
F_65 ( & V_4 -> V_69 ) ;
F_22 ( V_2 ) ;
F_66 ( V_2 ) ;
F_25 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_4 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_47 ( V_2 , V_72 , false ) ;
F_27 ( & V_4 -> V_43 ) ;
V_4 -> V_44 = V_73 ;
F_28 ( & V_4 -> V_43 ) ;
F_44 ( V_2 , V_74 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_55 = 0 ;
if ( F_73 ( V_2 -> V_46 ) )
return - V_75 ;
F_74 ( V_2 -> V_46 ) ;
if ( F_75 ( V_4 ) )
V_55 = F_76 ( V_4 , false ) ;
if ( V_55 )
F_19 ( L_18 ,
V_55 ) ;
F_77 ( V_2 , true ) ;
if ( F_78 ( V_2 ) )
V_55 = F_79 ( V_4 ) ;
else if ( F_13 ( V_4 ) )
V_55 = F_80 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_81 ( V_4 ) ;
F_82 ( V_2 ) ;
F_83 ( V_4 ) ;
return V_55 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_55 ;
if ( V_2 -> V_63 == V_64 )
return 0 ;
V_55 = F_72 ( V_2 ) ;
if ( V_55 )
return V_55 ;
return F_54 ( V_2 ) ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_76 ;
int V_55 ;
F_86 ( V_2 ) ;
F_27 ( & V_2 -> V_65 ) ;
F_87 ( V_2 ) ;
V_76 = V_4 -> V_67 . V_77 != 0 ;
V_55 = F_88 ( V_2 ) ;
if ( V_76 ) {
F_89 ( L_19 ) ;
V_4 -> V_67 . V_77 = 0 ;
if ( V_55 == - V_58 ) {
F_89 ( L_20
L_21 ) ;
V_55 = 0 ;
}
}
if ( F_90 ( V_4 ) )
F_91 ( L_22 ) ;
if ( V_55 ) {
F_19 ( L_23 , V_55 ) ;
F_28 ( & V_2 -> V_65 ) ;
return V_55 ;
}
F_92 ( V_4 ) ;
V_4 -> V_67 . V_78 = true ;
V_55 = F_61 ( V_2 ) ;
V_4 -> V_67 . V_78 = false ;
F_28 ( & V_2 -> V_65 ) ;
if ( V_55 ) {
F_19 ( L_24 , V_55 ) ;
return V_55 ;
}
if ( F_2 ( V_2 ) -> V_29 > 5 )
F_93 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_46 , const struct V_79 * V_80 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_80 -> V_83 ;
if ( F_95 ( V_82 ) && ! V_30 . V_84 ) {
F_89 ( L_25
L_26 ) ;
return - V_58 ;
}
if ( F_96 ( V_46 -> V_85 ) )
return - V_58 ;
return F_97 ( V_46 , V_80 , & V_86 ) ;
}
static void
F_98 ( struct V_6 * V_46 )
{
struct V_1 * V_2 = F_99 ( V_46 ) ;
F_100 ( V_2 ) ;
}
static int F_101 ( struct V_15 * V_2 )
{
struct V_6 * V_46 = F_102 ( V_2 ) ;
struct V_1 * V_53 = F_99 ( V_46 ) ;
if ( ! V_53 || ! V_53 -> V_5 ) {
F_33 ( V_2 , L_16 ) ;
return - V_58 ;
}
if ( V_53 -> V_63 == V_64 )
return 0 ;
return F_26 ( V_53 ) ;
}
static int F_103 ( struct V_15 * V_2 )
{
struct V_1 * V_53 = F_104 ( V_2 ) -> V_2 ;
if ( V_53 -> V_63 == V_64 )
return 0 ;
return F_48 ( V_53 , false ) ;
}
static int F_105 ( struct V_15 * V_2 )
{
struct V_1 * V_53 = F_104 ( V_2 ) -> V_2 ;
if ( V_53 -> V_63 == V_64 )
return 0 ;
return F_48 ( V_53 , true ) ;
}
static int F_106 ( struct V_15 * V_2 )
{
struct V_1 * V_53 = F_104 ( V_2 ) -> V_2 ;
if ( V_53 -> V_63 == V_64 )
return 0 ;
return F_72 ( V_53 ) ;
}
static int F_107 ( struct V_15 * V_2 )
{
struct V_1 * V_53 = F_104 ( V_2 ) -> V_2 ;
if ( V_53 -> V_63 == V_64 )
return 0 ;
return F_54 ( V_53 ) ;
}
static int F_108 ( struct V_3 * V_4 )
{
F_109 ( V_4 , V_87 ) ;
F_110 ( V_4 ) ;
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
F_112 ( V_4 ) ;
return 0 ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
F_116 ( V_4 ) ;
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_117 ( V_4 ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_121 ( V_4 ) ;
F_122 ( V_2 ) ;
return 0 ;
}
static void F_123 ( struct V_3 * V_4 )
{
struct V_88 * V_89 = & V_4 -> V_88 ;
int V_90 ;
V_89 -> V_91 = F_124 ( V_92 ) ;
V_89 -> V_93 = F_124 ( V_94 ) ;
V_89 -> V_95 = F_124 ( V_96 ) ;
V_89 -> V_97 = F_124 ( V_98 ) ;
V_89 -> V_99 = F_124 ( V_100 ) ;
for ( V_90 = 0 ; V_90 < F_125 ( V_89 -> V_101 ) ; V_90 ++ )
V_89 -> V_101 [ V_90 ] = F_124 ( V_102 + V_90 * 4 ) ;
V_89 -> V_103 = F_124 ( V_104 ) ;
V_89 -> V_105 = F_124 ( V_106 ) ;
V_89 -> V_107 = F_124 ( V_108 ) ;
V_89 -> V_109 = F_124 ( V_110 ) ;
V_89 -> V_111 = F_124 ( V_112 ) ;
V_89 -> V_113 = F_124 ( V_114 ) ;
V_89 -> V_115 = F_124 ( V_116 ) ;
V_89 -> V_117 = F_124 ( V_118 ) ;
V_89 -> V_119 = F_124 ( V_120 ) ;
V_89 -> V_121 = F_124 ( V_122 ) ;
V_89 -> V_123 = F_124 ( V_124 ) ;
V_89 -> V_125 = F_124 ( V_126 ) ;
V_89 -> V_127 = F_124 ( V_128 ) ;
V_89 -> V_129 = F_124 ( V_130 ) ;
V_89 -> V_131 = F_124 ( V_132 ) ;
V_89 -> V_133 = F_124 ( V_134 ) ;
V_89 -> V_135 = F_124 ( V_136 ) ;
V_89 -> V_137 = F_124 ( V_138 ) ;
V_89 -> V_139 = F_124 ( V_140 ) ;
V_89 -> V_141 = F_124 ( V_142 ) ;
V_89 -> V_143 = F_124 ( V_144 ) ;
V_89 -> V_145 = F_124 ( V_146 ) ;
V_89 -> V_147 = F_124 ( V_148 ) ;
V_89 -> V_149 = F_124 ( V_150 ) ;
V_89 -> V_151 = F_124 ( V_152 ) ;
V_89 -> V_153 = F_124 ( V_154 ) ;
V_89 -> V_155 = F_124 ( V_156 ) ;
V_89 -> V_157 = F_124 ( V_158 ) ;
V_89 -> V_159 = F_124 ( V_160 ) ;
V_89 -> V_161 = F_124 ( V_162 ) ;
for ( V_90 = 0 ; V_90 < F_125 ( V_89 -> V_163 ) ; V_90 ++ )
V_89 -> V_163 [ V_90 ] = F_124 ( V_164 + V_90 * 4 ) ;
V_89 -> V_165 = F_124 ( V_166 ) ;
V_89 -> V_167 = F_124 ( V_168 ) ;
V_89 -> V_169 = F_124 ( V_170 ) ;
V_89 -> V_171 = F_124 ( V_172 ) ;
V_89 -> V_173 = F_124 ( V_174 ) ;
V_89 -> V_175 = F_124 ( V_176 ) ;
V_89 -> V_177 = F_124 ( V_178 ) ;
V_89 -> V_179 = F_124 ( V_180 ) ;
V_89 -> V_181 = F_124 ( V_182 ) ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_88 * V_89 = & V_4 -> V_88 ;
T_3 V_183 ;
int V_90 ;
F_127 ( V_92 , V_89 -> V_91 ) ;
F_127 ( V_94 , V_89 -> V_93 ) ;
F_127 ( V_96 , V_89 -> V_95 | ( 0xffff << 16 ) ) ;
F_127 ( V_98 , V_89 -> V_97 ) ;
F_127 ( V_100 , V_89 -> V_99 ) ;
for ( V_90 = 0 ; V_90 < F_125 ( V_89 -> V_101 ) ; V_90 ++ )
F_127 ( V_102 + V_90 * 4 , V_89 -> V_101 [ V_90 ] ) ;
F_127 ( V_104 , V_89 -> V_103 ) ;
F_127 ( V_106 , V_89 -> V_105 ) ;
F_127 ( V_108 , V_89 -> V_107 ) ;
F_127 ( V_110 , V_89 -> V_109 ) ;
F_127 ( V_112 , V_89 -> V_111 ) ;
F_127 ( V_114 , V_89 -> V_113 ) ;
F_127 ( V_116 , V_89 -> V_115 ) ;
F_127 ( V_118 , V_89 -> V_117 ) ;
F_127 ( V_120 , V_89 -> V_119 ) ;
F_127 ( V_122 , V_89 -> V_121 ) ;
F_127 ( V_124 , V_89 -> V_123 ) ;
F_127 ( V_126 , V_89 -> V_125 ) ;
F_127 ( V_128 , V_89 -> V_127 ) ;
F_127 ( V_130 , V_89 -> V_129 ) ;
F_127 ( V_132 , V_89 -> V_131 ) ;
F_127 ( V_134 , V_89 -> V_133 ) ;
F_127 ( V_136 , V_89 -> V_135 ) ;
F_127 ( V_138 , V_89 -> V_137 ) ;
F_127 ( V_140 , V_89 -> V_139 ) ;
F_127 ( V_142 , V_89 -> V_141 ) ;
F_127 ( V_144 , V_89 -> V_143 ) ;
F_127 ( V_146 , V_89 -> V_145 ) ;
F_127 ( V_148 , V_89 -> V_147 ) ;
F_127 ( V_150 , V_89 -> V_149 ) ;
F_127 ( V_152 , V_89 -> V_151 ) ;
F_127 ( V_154 , V_89 -> V_153 ) ;
F_127 ( V_156 , V_89 -> V_155 ) ;
F_127 ( V_158 , V_89 -> V_157 ) ;
F_127 ( V_160 , V_89 -> V_159 ) ;
F_127 ( V_162 , V_89 -> V_161 ) ;
for ( V_90 = 0 ; V_90 < F_125 ( V_89 -> V_163 ) ; V_90 ++ )
F_127 ( V_164 + V_90 * 4 , V_89 -> V_163 [ V_90 ] ) ;
F_127 ( V_166 , V_89 -> V_165 ) ;
F_127 ( V_168 , V_89 -> V_167 ) ;
V_183 = F_124 ( V_170 ) ;
V_183 &= V_184 ;
V_183 |= V_89 -> V_169 & ~ V_184 ;
F_127 ( V_170 , V_183 ) ;
V_183 = F_124 ( V_172 ) ;
V_183 &= V_185 ;
V_183 |= V_89 -> V_171 & ~ V_185 ;
F_127 ( V_172 , V_183 ) ;
F_127 ( V_174 , V_89 -> V_173 ) ;
F_127 ( V_176 , V_89 -> V_175 ) ;
F_127 ( V_178 , V_89 -> V_177 ) ;
F_127 ( V_180 , V_89 -> V_179 ) ;
F_127 ( V_182 , V_89 -> V_181 ) ;
}
int F_128 ( struct V_3 * V_4 , bool V_186 )
{
T_3 V_183 ;
int V_35 ;
#define F_129 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_183 = F_124 ( V_172 ) ;
V_183 &= ~ V_185 ;
if ( V_186 )
V_183 |= V_185 ;
F_127 ( V_172 , V_183 ) ;
if ( ! V_186 )
return 0 ;
V_35 = F_130 ( F_129 , 20 ) ;
if ( V_35 )
F_19 ( L_27 ,
F_124 ( V_172 ) ) ;
return V_35 ;
#undef F_129
}
static int F_131 ( struct V_3 * V_4 , bool V_187 )
{
T_3 V_183 ;
int V_35 = 0 ;
V_183 = F_124 ( V_170 ) ;
V_183 &= ~ V_184 ;
if ( V_187 )
V_183 |= V_184 ;
F_127 ( V_170 , V_183 ) ;
F_132 ( V_170 ) ;
#define F_129 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_35 = F_130 ( F_129 , 1 ) ;
if ( V_35 )
F_19 ( L_28 ) ;
return V_35 ;
#undef F_129
}
static int F_133 ( struct V_3 * V_4 ,
bool V_188 )
{
T_3 V_189 ;
T_3 V_183 ;
int V_35 ;
V_189 = V_190 | V_191 ;
V_183 = V_188 ? V_189 : 0 ;
#define F_129 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_129 )
return 0 ;
F_4 ( L_29 ,
V_188 ? L_30 : L_31 ,
F_124 ( V_192 ) ) ;
V_35 = F_130 ( F_129 , 3 ) ;
if ( V_35 )
F_19 ( L_32 ,
V_188 ? L_30 : L_31 ) ;
return V_35 ;
#undef F_129
}
static void F_134 ( struct V_3 * V_4 )
{
if ( ! ( F_124 ( V_192 ) & V_193 ) )
return;
F_19 ( L_33 ) ;
F_127 ( V_192 , V_193 ) ;
}
static int F_135 ( struct V_3 * V_4 )
{
T_3 V_189 ;
int V_35 ;
( void ) F_133 ( V_4 , false ) ;
V_189 = V_194 | V_195 ;
F_5 ( ( F_124 ( V_170 ) & V_189 ) != V_189 ) ;
F_134 ( V_4 ) ;
V_35 = F_128 ( V_4 , true ) ;
if ( V_35 )
goto V_196;
V_35 = F_131 ( V_4 , false ) ;
if ( V_35 )
goto V_197;
if ( ! F_136 ( V_4 -> V_2 ) )
F_123 ( V_4 ) ;
V_35 = F_128 ( V_4 , false ) ;
if ( V_35 )
goto V_197;
return 0 ;
V_197:
F_131 ( V_4 , true ) ;
V_196:
F_128 ( V_4 , false ) ;
return V_35 ;
}
static int F_76 ( struct V_3 * V_4 ,
bool V_198 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_35 ;
int V_55 ;
V_55 = F_128 ( V_4 , true ) ;
if ( ! F_136 ( V_4 -> V_2 ) )
F_126 ( V_4 ) ;
V_35 = F_131 ( V_4 , true ) ;
if ( ! V_55 )
V_55 = V_35 ;
V_35 = F_128 ( V_4 , false ) ;
if ( ! V_55 )
V_55 = V_35 ;
F_134 ( V_4 ) ;
if ( V_198 ) {
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
}
return V_55 ;
}
static int F_139 ( struct V_15 * V_15 )
{
struct V_6 * V_46 = F_102 ( V_15 ) ;
struct V_1 * V_2 = F_99 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_55 ;
if ( F_53 ( ! ( V_4 -> V_199 . V_200 && F_140 ( V_2 ) ) ) )
return - V_58 ;
if ( F_53 ( ! F_141 ( V_2 ) ) )
return - V_58 ;
F_4 ( L_34 ) ;
if ( ! F_142 ( & V_2 -> V_65 ) ) {
F_4 ( L_35 ) ;
F_143 ( V_15 ) ;
return - V_201 ;
}
F_144 ( V_4 ) ;
F_28 ( & V_2 -> V_65 ) ;
F_34 ( V_2 ) ;
F_37 ( V_4 ) ;
V_55 = F_49 ( V_4 ) ;
if ( V_55 ) {
F_19 ( L_36 , V_55 ) ;
F_60 ( V_4 ) ;
return V_55 ;
}
F_145 ( & V_4 -> V_67 . V_202 ) ;
F_45 ( V_2 , false ) ;
V_4 -> V_203 . V_204 = true ;
if ( F_10 ( V_2 ) ) {
F_44 ( V_2 , V_56 ) ;
} else {
F_44 ( V_2 , V_50 ) ;
}
F_146 ( V_4 ) ;
F_4 ( L_37 ) ;
return 0 ;
}
static int F_147 ( struct V_15 * V_15 )
{
struct V_6 * V_46 = F_102 ( V_15 ) ;
struct V_1 * V_2 = F_99 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_55 = 0 ;
if ( F_53 ( ! F_141 ( V_2 ) ) )
return - V_58 ;
F_4 ( L_38 ) ;
F_44 ( V_2 , V_74 ) ;
V_4 -> V_203 . V_204 = false ;
if ( F_7 ( V_4 ) )
F_58 ( V_2 ) ;
if ( F_78 ( V_2 ) )
V_55 = F_79 ( V_4 ) ;
else if ( F_13 ( V_2 ) )
V_55 = F_80 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
F_81 ( V_4 ) ;
else if ( F_75 ( V_4 ) )
V_55 = F_76 ( V_4 , true ) ;
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
F_60 ( V_4 ) ;
F_93 ( V_2 ) ;
if ( V_55 )
F_19 ( L_39 , V_55 ) ;
else
F_4 ( L_40 ) ;
return V_55 ;
}
static int F_49 ( struct V_3 * V_4 )
{
int V_55 ;
if ( F_78 ( V_4 ) )
V_55 = F_113 ( V_4 ) ;
else if ( F_13 ( V_4 ) )
V_55 = F_108 ( V_4 ) ;
else if ( F_9 ( V_4 ) || F_10 ( V_4 ) )
V_55 = F_111 ( V_4 ) ;
else if ( F_75 ( V_4 ) )
V_55 = F_135 ( V_4 ) ;
else
V_55 = 0 ;
return V_55 ;
}
static int T_4 F_150 ( void )
{
V_86 . V_205 = V_206 ;
V_86 . V_207 |= V_208 ;
if ( V_30 . V_209 == 0 )
V_86 . V_207 &= ~ V_208 ;
#ifdef F_151
if ( F_152 () && V_30 . V_209 == - 1 )
V_86 . V_207 &= ~ V_208 ;
#endif
if ( ! ( V_86 . V_207 & V_208 ) ) {
V_86 . V_210 = NULL ;
F_153 ( L_41 ) ;
return 0 ;
}
if ( V_86 . V_207 & V_208 )
V_86 . V_207 |= V_211 ;
return F_154 ( & V_86 , & V_212 ) ;
}
static void T_5 F_155 ( void )
{
if ( ! ( V_86 . V_207 & V_208 ) )
return;
F_156 ( & V_86 , & V_212 ) ;
}
