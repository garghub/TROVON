static enum V_1 F_1 ( struct V_2 * V_3 )
{
enum V_1 V_4 = V_5 ;
if ( F_2 ( V_3 ) ) {
V_4 = V_6 ;
F_3 ( L_1 ) ;
} else if ( F_4 ( V_3 ) || F_5 ( V_3 ) ) {
V_4 = V_7 ;
F_3 ( L_2 ) ;
} else if ( F_6 ( V_3 ) || F_7 ( V_3 ) ) {
V_4 = V_8 ;
F_3 ( L_3 ) ;
} else if ( F_8 ( V_3 ) ) {
V_4 = V_9 ;
F_3 ( L_4 ) ;
}
return V_4 ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = NULL ;
if ( F_10 ( V_3 ) -> V_15 == 0 ) {
V_11 -> V_16 = V_5 ;
return;
}
while ( ( V_14 = F_11 ( V_17 << 8 , V_14 ) ) ) {
if ( V_14 -> V_18 == V_19 ) {
unsigned short V_20 = V_14 -> V_21 & V_22 ;
V_11 -> V_23 = V_20 ;
if ( V_20 == V_24 ) {
V_11 -> V_16 = V_6 ;
F_3 ( L_5 ) ;
F_12 ( ! F_2 ( V_3 ) ) ;
} else if ( V_20 == V_25 ) {
V_11 -> V_16 = V_7 ;
F_3 ( L_6 ) ;
F_12 ( ! ( F_4 ( V_3 ) || F_5 ( V_3 ) ) ) ;
} else if ( V_20 == V_26 ) {
V_11 -> V_16 = V_7 ;
F_3 ( L_7 ) ;
F_12 ( ! ( F_4 ( V_3 ) || F_5 ( V_3 ) ) ) ;
} else if ( V_20 == V_27 ) {
V_11 -> V_16 = V_8 ;
F_3 ( L_8 ) ;
F_12 ( ! F_6 ( V_3 ) && ! F_7 ( V_3 ) ) ;
F_12 ( F_13 ( V_3 ) || F_14 ( V_3 ) ) ;
} else if ( V_20 == V_28 ) {
V_11 -> V_16 = V_8 ;
F_3 ( L_9 ) ;
F_12 ( ! F_6 ( V_3 ) && ! F_7 ( V_3 ) ) ;
F_12 ( ! F_13 ( V_3 ) && ! F_14 ( V_3 ) ) ;
} else if ( V_20 == V_29 ) {
V_11 -> V_16 = V_9 ;
F_3 ( L_10 ) ;
F_12 ( ! F_8 ( V_3 ) ) ;
} else if ( V_20 == V_30 ) {
V_11 -> V_16 = V_9 ;
F_3 ( L_11 ) ;
F_12 ( ! F_8 ( V_3 ) ) ;
} else if ( V_20 == V_31 ) {
V_11 -> V_16 = F_1 ( V_3 ) ;
} else
continue;
break;
}
}
if ( ! V_14 )
F_3 ( L_12 ) ;
F_15 ( V_14 ) ;
}
bool F_16 ( struct V_2 * V_3 )
{
if ( F_10 ( V_3 ) -> V_32 < 6 )
return false ;
if ( V_33 . V_34 >= 0 )
return V_33 . V_34 ;
if ( V_33 . V_35 )
return false ;
if ( F_17 ( V_3 ) )
return false ;
#ifdef F_18
if ( F_10 ( V_3 ) -> V_32 == 6 && V_36 )
return false ;
#endif
return true ;
}
void F_19 ( const char * V_37 , int V_38 )
{
F_20 ( L_13 , V_37 , V_38 ) ;
if ( ! V_38 )
V_38 = - V_39 ;
if ( ! ( F_21 ( V_40 ) && V_38 == - V_39 ) )
return;
F_20 (
L_14
L_15
L_16 ) ;
}
static void F_22 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_41 * V_42 ;
F_23 ( V_3 ) ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
struct V_43 * V_43 = F_25 ( V_42 ) ;
if ( V_43 -> V_44 )
V_43 -> V_44 ( V_43 ) ;
}
F_26 ( V_3 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
T_1 V_45 ;
int error ;
F_28 ( & V_11 -> V_46 ) ;
V_11 -> V_47 = V_48 ;
F_29 ( & V_11 -> V_46 ) ;
F_30 ( V_11 , true ) ;
F_31 ( V_3 ) ;
F_32 ( V_3 -> V_49 ) ;
error = F_33 ( V_3 ) ;
if ( error ) {
F_34 ( & V_3 -> V_49 -> V_3 ,
L_17 ) ;
return error ;
}
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
F_23 ( V_3 ) ;
F_37 ( V_3 ) ;
F_26 ( V_3 ) ;
F_38 ( V_3 ) ;
F_39 ( V_11 ) ;
F_40 ( V_11 ) ;
F_22 ( V_11 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
V_45 = V_50 ;
#if F_44 ( V_51 )
if ( F_45 () < V_52 )
V_45 = V_53 ;
#endif
F_46 ( V_3 , V_45 ) ;
F_47 ( V_3 , false ) ;
F_48 ( V_3 ) ;
F_49 ( V_3 , V_54 , true ) ;
V_11 -> V_55 ++ ;
F_30 ( V_11 , false ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_56 , bool V_57 )
{
struct V_10 * V_11 = V_56 -> V_12 ;
int V_4 ;
V_4 = F_51 ( V_11 ) ;
if ( V_4 ) {
F_20 ( L_18 , V_4 ) ;
return V_4 ;
}
F_52 ( V_56 -> V_49 ) ;
if ( ! ( V_57 && F_10 ( V_11 ) -> V_32 < 6 ) )
F_53 ( V_56 -> V_49 , V_58 ) ;
return 0 ;
}
int F_54 ( struct V_2 * V_3 , T_2 V_59 )
{
int error ;
if ( ! V_3 || ! V_3 -> V_12 ) {
F_20 ( L_19 , V_3 ) ;
F_20 ( L_20 ) ;
return - V_60 ;
}
if ( F_55 ( V_59 . V_61 != V_62 &&
V_59 . V_61 != V_63 ) )
return - V_64 ;
if ( V_3 -> V_65 == V_66 )
return 0 ;
error = F_27 ( V_3 ) ;
if ( error )
return error ;
return F_50 ( V_3 , false ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
F_28 ( & V_3 -> V_67 ) ;
F_57 ( V_3 ) ;
F_29 ( & V_3 -> V_67 ) ;
F_58 ( V_3 ) ;
F_59 ( V_3 ) ;
F_60 ( V_3 ) ;
F_61 ( V_3 ) ;
F_62 ( V_11 ) ;
F_28 ( & V_3 -> V_67 ) ;
if ( F_63 ( V_3 ) ) {
F_20 ( L_21 ) ;
F_64 ( V_68 , & V_11 -> V_69 . V_70 ) ;
}
F_29 ( & V_3 -> V_67 ) ;
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
F_67 ( & V_11 -> V_71 ) ;
if ( V_11 -> V_72 . V_73 )
V_11 -> V_72 . V_73 ( V_3 ) ;
F_68 ( & V_11 -> V_71 ) ;
F_23 ( V_3 ) ;
F_69 ( V_3 ) ;
F_26 ( V_3 ) ;
F_70 ( V_3 ) ;
F_71 ( V_11 ) ;
F_72 ( V_3 ) ;
F_73 ( V_3 ) ;
F_49 ( V_3 , V_74 , false ) ;
F_28 ( & V_11 -> V_46 ) ;
V_11 -> V_47 = V_75 ;
F_29 ( & V_11 -> V_46 ) ;
F_46 ( V_3 , V_76 ) ;
F_74 ( V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 = 0 ;
if ( F_76 ( V_3 -> V_49 ) )
return - V_77 ;
F_77 ( V_3 -> V_49 ) ;
if ( F_78 ( V_11 ) )
V_4 = F_79 ( V_11 , false ) ;
if ( V_4 )
F_20 ( L_22 ,
V_4 ) ;
F_80 ( V_3 , true ) ;
if ( F_81 ( V_3 ) )
V_4 = F_82 ( V_11 ) ;
else if ( F_8 ( V_11 ) )
V_4 = F_83 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_84 ( V_11 ) ;
F_85 ( V_3 ) ;
F_86 ( V_11 ) ;
return V_4 ;
}
int F_87 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_3 -> V_65 == V_66 )
return 0 ;
V_4 = F_75 ( V_3 ) ;
if ( V_4 )
return V_4 ;
return F_56 ( V_3 ) ;
}
int F_88 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
bool V_78 ;
int V_4 ;
F_89 ( V_3 ) ;
F_28 ( & V_3 -> V_67 ) ;
F_90 ( V_3 ) ;
V_78 = V_11 -> V_69 . V_79 != 0 ;
V_4 = F_91 ( V_3 ) ;
if ( V_78 ) {
F_92 ( L_23 ) ;
V_11 -> V_69 . V_79 = 0 ;
if ( V_4 == - V_60 ) {
F_92 ( L_24
L_25 ) ;
V_4 = 0 ;
}
}
if ( F_93 ( V_11 ) )
F_94 ( L_26 ) ;
if ( V_4 ) {
F_20 ( L_27 , V_4 ) ;
F_29 ( & V_3 -> V_67 ) ;
return V_4 ;
}
F_95 ( V_11 ) ;
V_11 -> V_69 . V_80 = true ;
V_4 = F_63 ( V_3 ) ;
V_11 -> V_69 . V_80 = false ;
F_29 ( & V_3 -> V_67 ) ;
if ( V_4 ) {
F_20 ( L_28 , V_4 ) ;
return V_4 ;
}
if ( F_10 ( V_3 ) -> V_32 > 5 )
F_96 ( V_3 ) ;
return 0 ;
}
static int F_97 ( struct V_13 * V_49 , const struct V_81 * V_82 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_82 -> V_85 ;
if ( F_98 ( V_84 ) && ! V_33 . V_86 ) {
F_92 ( L_29
L_30 ) ;
return - V_60 ;
}
if ( F_99 ( V_49 -> V_87 ) )
return - V_60 ;
return F_100 ( V_49 , V_82 , & V_88 ) ;
}
static void
F_101 ( struct V_13 * V_49 )
{
struct V_2 * V_3 = F_102 ( V_49 ) ;
F_103 ( V_3 ) ;
}
static int F_104 ( struct V_21 * V_3 )
{
struct V_13 * V_49 = F_105 ( V_3 ) ;
struct V_2 * V_56 = F_102 ( V_49 ) ;
if ( ! V_56 || ! V_56 -> V_12 ) {
F_34 ( V_3 , L_20 ) ;
return - V_60 ;
}
if ( V_56 -> V_65 == V_66 )
return 0 ;
return F_27 ( V_56 ) ;
}
static int F_106 ( struct V_21 * V_3 )
{
struct V_2 * V_56 = F_107 ( V_3 ) -> V_3 ;
if ( V_56 -> V_65 == V_66 )
return 0 ;
return F_50 ( V_56 , false ) ;
}
static int F_108 ( struct V_21 * V_3 )
{
struct V_2 * V_56 = F_107 ( V_3 ) -> V_3 ;
if ( V_56 -> V_65 == V_66 )
return 0 ;
return F_50 ( V_56 , true ) ;
}
static int F_109 ( struct V_21 * V_3 )
{
struct V_2 * V_56 = F_107 ( V_3 ) -> V_3 ;
if ( V_56 -> V_65 == V_66 )
return 0 ;
return F_75 ( V_56 ) ;
}
static int F_110 ( struct V_21 * V_3 )
{
struct V_2 * V_56 = F_107 ( V_3 ) -> V_3 ;
if ( V_56 -> V_65 == V_66 )
return 0 ;
return F_56 ( V_56 ) ;
}
static int F_111 ( struct V_10 * V_11 )
{
F_112 ( V_11 ) ;
return 0 ;
}
static int F_113 ( struct V_10 * V_11 )
{
F_114 ( V_11 ) ;
return 0 ;
}
static int F_115 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_116 ( V_3 ) ;
F_117 ( V_3 ) ;
F_118 ( V_11 ) ;
return 0 ;
}
static int F_82 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_119 ( V_11 ) ;
F_120 ( V_3 ) ;
F_121 ( V_3 ) ;
F_122 ( V_3 ) ;
return 0 ;
}
static int F_83 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_123 ( V_11 ) ;
F_124 ( V_3 ) ;
return 0 ;
}
static void F_125 ( struct V_10 * V_11 )
{
struct V_89 * V_90 = & V_11 -> V_89 ;
int V_91 ;
V_90 -> V_92 = F_126 ( V_93 ) ;
V_90 -> V_94 = F_126 ( V_95 ) ;
V_90 -> V_96 = F_126 ( V_97 ) ;
V_90 -> V_98 = F_126 ( V_99 ) ;
V_90 -> V_100 = F_126 ( V_101 ) ;
for ( V_91 = 0 ; V_91 < F_127 ( V_90 -> V_102 ) ; V_91 ++ )
V_90 -> V_102 [ V_91 ] = F_126 ( F_128 ( V_91 ) ) ;
V_90 -> V_103 = F_126 ( V_104 ) ;
V_90 -> V_105 = F_126 ( V_106 ) ;
V_90 -> V_107 = F_126 ( V_108 ) ;
V_90 -> V_109 = F_126 ( V_110 ) ;
V_90 -> V_111 = F_126 ( V_112 ) ;
V_90 -> V_113 = F_126 ( V_114 ) ;
V_90 -> V_115 = F_126 ( V_116 ) ;
V_90 -> V_117 = F_126 ( V_118 ) ;
V_90 -> V_119 = F_126 ( V_120 ) ;
V_90 -> V_121 = F_126 ( V_122 ) ;
V_90 -> V_123 = F_126 ( V_124 ) ;
V_90 -> V_125 = F_126 ( V_126 ) ;
V_90 -> V_127 = F_126 ( V_128 ) ;
V_90 -> V_129 = F_126 ( V_130 ) ;
V_90 -> V_131 = F_126 ( V_132 ) ;
V_90 -> V_133 = F_126 ( V_134 ) ;
V_90 -> V_135 = F_126 ( V_136 ) ;
V_90 -> V_137 = F_126 ( V_138 ) ;
V_90 -> V_139 = F_126 ( V_140 ) ;
V_90 -> V_141 = F_126 ( V_142 ) ;
V_90 -> V_143 = F_126 ( V_144 ) ;
V_90 -> V_145 = F_126 ( V_146 ) ;
V_90 -> V_147 = F_126 ( V_148 ) ;
V_90 -> V_149 = F_126 ( V_150 ) ;
V_90 -> V_151 = F_126 ( V_152 ) ;
V_90 -> V_153 = F_126 ( V_154 ) ;
V_90 -> V_155 = F_126 ( V_156 ) ;
V_90 -> V_157 = F_126 ( V_158 ) ;
V_90 -> V_159 = F_126 ( V_160 ) ;
V_90 -> V_161 = F_126 ( V_162 ) ;
for ( V_91 = 0 ; V_91 < F_127 ( V_90 -> V_163 ) ; V_91 ++ )
V_90 -> V_163 [ V_91 ] = F_126 ( F_129 ( V_91 ) ) ;
V_90 -> V_164 = F_126 ( V_165 ) ;
V_90 -> V_166 = F_126 ( V_167 ) ;
V_90 -> V_168 = F_126 ( V_169 ) ;
V_90 -> V_170 = F_126 ( V_171 ) ;
V_90 -> V_172 = F_126 ( V_173 ) ;
V_90 -> V_174 = F_126 ( V_175 ) ;
V_90 -> V_176 = F_126 ( V_177 ) ;
V_90 -> V_178 = F_126 ( V_179 ) ;
V_90 -> V_180 = F_126 ( V_181 ) ;
}
static void F_130 ( struct V_10 * V_11 )
{
struct V_89 * V_90 = & V_11 -> V_89 ;
T_3 V_182 ;
int V_91 ;
F_131 ( V_93 , V_90 -> V_92 ) ;
F_131 ( V_95 , V_90 -> V_94 ) ;
F_131 ( V_97 , V_90 -> V_96 | ( 0xffff << 16 ) ) ;
F_131 ( V_99 , V_90 -> V_98 ) ;
F_131 ( V_101 , V_90 -> V_100 ) ;
for ( V_91 = 0 ; V_91 < F_127 ( V_90 -> V_102 ) ; V_91 ++ )
F_131 ( F_128 ( V_91 ) , V_90 -> V_102 [ V_91 ] ) ;
F_131 ( V_104 , V_90 -> V_103 ) ;
F_131 ( V_106 , V_90 -> V_105 ) ;
F_131 ( V_108 , V_90 -> V_107 ) ;
F_131 ( V_110 , V_90 -> V_109 ) ;
F_131 ( V_112 , V_90 -> V_111 ) ;
F_131 ( V_114 , V_90 -> V_113 ) ;
F_131 ( V_116 , V_90 -> V_115 ) ;
F_131 ( V_118 , V_90 -> V_117 ) ;
F_131 ( V_120 , V_90 -> V_119 ) ;
F_131 ( V_122 , V_90 -> V_121 ) ;
F_131 ( V_124 , V_90 -> V_123 ) ;
F_131 ( V_126 , V_90 -> V_125 ) ;
F_131 ( V_128 , V_90 -> V_127 ) ;
F_131 ( V_130 , V_90 -> V_129 ) ;
F_131 ( V_132 , V_90 -> V_131 ) ;
F_131 ( V_134 , V_90 -> V_133 ) ;
F_131 ( V_136 , V_90 -> V_135 ) ;
F_131 ( V_138 , V_90 -> V_137 ) ;
F_131 ( V_140 , V_90 -> V_139 ) ;
F_131 ( V_142 , V_90 -> V_141 ) ;
F_131 ( V_144 , V_90 -> V_143 ) ;
F_131 ( V_146 , V_90 -> V_145 ) ;
F_131 ( V_148 , V_90 -> V_147 ) ;
F_131 ( V_150 , V_90 -> V_149 ) ;
F_131 ( V_152 , V_90 -> V_151 ) ;
F_131 ( V_154 , V_90 -> V_153 ) ;
F_131 ( V_156 , V_90 -> V_155 ) ;
F_131 ( V_158 , V_90 -> V_157 ) ;
F_131 ( V_160 , V_90 -> V_159 ) ;
F_131 ( V_162 , V_90 -> V_161 ) ;
for ( V_91 = 0 ; V_91 < F_127 ( V_90 -> V_163 ) ; V_91 ++ )
F_131 ( F_129 ( V_91 ) , V_90 -> V_163 [ V_91 ] ) ;
F_131 ( V_165 , V_90 -> V_164 ) ;
F_131 ( V_167 , V_90 -> V_166 ) ;
V_182 = F_126 ( V_169 ) ;
V_182 &= V_183 ;
V_182 |= V_90 -> V_168 & ~ V_183 ;
F_131 ( V_169 , V_182 ) ;
V_182 = F_126 ( V_171 ) ;
V_182 &= V_184 ;
V_182 |= V_90 -> V_170 & ~ V_184 ;
F_131 ( V_171 , V_182 ) ;
F_131 ( V_173 , V_90 -> V_172 ) ;
F_131 ( V_175 , V_90 -> V_174 ) ;
F_131 ( V_177 , V_90 -> V_176 ) ;
F_131 ( V_179 , V_90 -> V_178 ) ;
F_131 ( V_181 , V_90 -> V_180 ) ;
}
int F_132 ( struct V_10 * V_11 , bool V_185 )
{
T_3 V_182 ;
int V_38 ;
#define F_133 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_182 = F_126 ( V_171 ) ;
V_182 &= ~ V_184 ;
if ( V_185 )
V_182 |= V_184 ;
F_131 ( V_171 , V_182 ) ;
if ( ! V_185 )
return 0 ;
V_38 = F_134 ( F_133 , 20 ) ;
if ( V_38 )
F_20 ( L_31 ,
F_126 ( V_171 ) ) ;
return V_38 ;
#undef F_133
}
static int F_135 ( struct V_10 * V_11 , bool V_186 )
{
T_3 V_182 ;
int V_38 = 0 ;
V_182 = F_126 ( V_169 ) ;
V_182 &= ~ V_183 ;
if ( V_186 )
V_182 |= V_183 ;
F_131 ( V_169 , V_182 ) ;
F_136 ( V_169 ) ;
#define F_133 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_38 = F_134 ( F_133 , 1 ) ;
if ( V_38 )
F_20 ( L_32 ) ;
return V_38 ;
#undef F_133
}
static int F_137 ( struct V_10 * V_11 ,
bool V_187 )
{
T_3 V_188 ;
T_3 V_182 ;
int V_38 ;
V_188 = V_189 | V_190 ;
V_182 = V_187 ? V_188 : 0 ;
#define F_133 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_133 )
return 0 ;
F_3 ( L_33 ,
V_187 ? L_34 : L_35 ,
F_126 ( V_191 ) ) ;
V_38 = F_134 ( F_133 , 3 ) ;
if ( V_38 )
F_20 ( L_36 ,
V_187 ? L_34 : L_35 ) ;
return V_38 ;
#undef F_133
}
static void F_138 ( struct V_10 * V_11 )
{
if ( ! ( F_126 ( V_191 ) & V_192 ) )
return;
F_20 ( L_37 ) ;
F_131 ( V_191 , V_192 ) ;
}
static int F_139 ( struct V_10 * V_11 )
{
T_3 V_188 ;
int V_38 ;
( void ) F_137 ( V_11 , false ) ;
V_188 = V_193 | V_194 ;
F_12 ( ( F_126 ( V_169 ) & V_188 ) != V_188 ) ;
F_138 ( V_11 ) ;
V_38 = F_132 ( V_11 , true ) ;
if ( V_38 )
goto V_195;
V_38 = F_135 ( V_11 , false ) ;
if ( V_38 )
goto V_196;
if ( ! F_140 ( V_11 -> V_3 ) )
F_125 ( V_11 ) ;
V_38 = F_132 ( V_11 , false ) ;
if ( V_38 )
goto V_196;
return 0 ;
V_196:
F_135 ( V_11 , true ) ;
V_195:
F_132 ( V_11 , false ) ;
return V_38 ;
}
static int F_79 ( struct V_10 * V_11 ,
bool V_197 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
int V_38 ;
int V_4 ;
V_4 = F_132 ( V_11 , true ) ;
if ( ! F_140 ( V_11 -> V_3 ) )
F_130 ( V_11 ) ;
V_38 = F_135 ( V_11 , true ) ;
if ( ! V_4 )
V_4 = V_38 ;
V_38 = F_132 ( V_11 , false ) ;
if ( ! V_4 )
V_4 = V_38 ;
F_138 ( V_11 ) ;
if ( V_197 ) {
F_141 ( V_3 ) ;
F_142 ( V_3 ) ;
}
return V_4 ;
}
static int F_143 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_105 ( V_21 ) ;
struct V_2 * V_3 = F_102 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
if ( F_55 ( ! ( V_11 -> V_198 . V_199 && F_144 ( V_3 ) ) ) )
return - V_60 ;
if ( F_55 ( ! F_145 ( V_3 ) ) )
return - V_60 ;
F_3 ( L_38 ) ;
if ( ! F_146 ( & V_3 -> V_67 ) ) {
F_3 ( L_39 ) ;
F_147 ( V_21 ) ;
return - V_200 ;
}
F_148 ( V_11 ) ;
F_29 ( & V_3 -> V_67 ) ;
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
F_39 ( V_11 ) ;
V_4 = F_51 ( V_11 ) ;
if ( V_4 ) {
F_20 ( L_40 , V_4 ) ;
F_62 ( V_11 ) ;
return V_4 ;
}
F_149 ( & V_11 -> V_69 . V_201 ) ;
F_47 ( V_3 , false ) ;
V_11 -> V_202 . V_203 = true ;
if ( F_7 ( V_3 ) ) {
F_46 ( V_3 , V_58 ) ;
} else {
F_46 ( V_3 , V_53 ) ;
}
F_150 ( V_11 ) ;
F_3 ( L_41 ) ;
return 0 ;
}
static int F_151 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_105 ( V_21 ) ;
struct V_2 * V_3 = F_102 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 = 0 ;
if ( F_55 ( ! F_145 ( V_3 ) ) )
return - V_60 ;
F_3 ( L_42 ) ;
F_46 ( V_3 , V_76 ) ;
V_11 -> V_202 . V_203 = false ;
F_65 ( V_3 ) ;
if ( F_4 ( V_11 ) )
F_60 ( V_3 ) ;
if ( F_81 ( V_3 ) )
V_4 = F_82 ( V_11 ) ;
else if ( F_8 ( V_3 ) )
V_4 = F_83 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_84 ( V_11 ) ;
else if ( F_78 ( V_11 ) )
V_4 = F_79 ( V_11 , true ) ;
F_152 ( V_3 ) ;
F_153 ( V_3 ) ;
F_62 ( V_11 ) ;
if ( ! F_78 ( V_11 ) )
F_71 ( V_11 ) ;
F_96 ( V_3 ) ;
if ( V_4 )
F_20 ( L_43 , V_4 ) ;
else
F_3 ( L_44 ) ;
return V_4 ;
}
static int F_51 ( struct V_10 * V_11 )
{
int V_4 ;
if ( F_81 ( V_11 ) )
V_4 = F_115 ( V_11 ) ;
else if ( F_8 ( V_11 ) )
V_4 = F_111 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
V_4 = F_113 ( V_11 ) ;
else if ( F_78 ( V_11 ) )
V_4 = F_139 ( V_11 ) ;
else
V_4 = 0 ;
return V_4 ;
}
static int T_4 F_154 ( void )
{
V_88 . V_204 = V_205 ;
if ( V_33 . V_206 == 0 )
V_88 . V_207 &= ~ V_208 ;
#ifdef F_155
if ( F_156 () && V_33 . V_206 == - 1 )
V_88 . V_207 &= ~ V_208 ;
#endif
if ( ! ( V_88 . V_207 & V_208 ) ) {
F_157 ( L_45 ) ;
return 0 ;
}
if ( V_33 . V_209 )
V_88 . V_207 |= V_210 ;
return F_158 ( & V_88 , & V_211 ) ;
}
static void T_5 F_159 ( void )
{
if ( ! ( V_88 . V_207 & V_208 ) )
return;
F_160 ( & V_88 , & V_211 ) ;
}
