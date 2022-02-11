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
} else if ( F_8 ( V_3 ) || F_9 ( V_3 ) ) {
V_4 = V_9 ;
F_3 ( L_4 ) ;
}
return V_4 ;
}
void F_10 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = NULL ;
if ( F_11 ( V_3 ) -> V_15 == 0 ) {
V_11 -> V_16 = V_5 ;
return;
}
while ( ( V_14 = F_12 ( V_17 << 8 , V_14 ) ) ) {
if ( V_14 -> V_18 == V_19 ) {
unsigned short V_20 = V_14 -> V_21 & V_22 ;
V_11 -> V_23 = V_20 ;
if ( V_20 == V_24 ) {
V_11 -> V_16 = V_6 ;
F_3 ( L_5 ) ;
F_13 ( ! F_2 ( V_3 ) ) ;
} else if ( V_20 == V_25 ) {
V_11 -> V_16 = V_7 ;
F_3 ( L_6 ) ;
F_13 ( ! ( F_4 ( V_3 ) || F_5 ( V_3 ) ) ) ;
} else if ( V_20 == V_26 ) {
V_11 -> V_16 = V_7 ;
F_3 ( L_7 ) ;
F_13 ( ! ( F_4 ( V_3 ) || F_5 ( V_3 ) ) ) ;
} else if ( V_20 == V_27 ) {
V_11 -> V_16 = V_8 ;
F_3 ( L_8 ) ;
F_13 ( ! F_6 ( V_3 ) && ! F_7 ( V_3 ) ) ;
F_13 ( F_14 ( V_3 ) || F_15 ( V_3 ) ) ;
} else if ( V_20 == V_28 ) {
V_11 -> V_16 = V_8 ;
F_3 ( L_9 ) ;
F_13 ( ! F_6 ( V_3 ) && ! F_7 ( V_3 ) ) ;
F_13 ( ! F_14 ( V_3 ) && ! F_15 ( V_3 ) ) ;
} else if ( V_20 == V_29 ) {
V_11 -> V_16 = V_9 ;
F_3 ( L_10 ) ;
F_13 ( ! F_8 ( V_3 ) &&
! F_9 ( V_3 ) ) ;
} else if ( V_20 == V_30 ) {
V_11 -> V_16 = V_9 ;
F_3 ( L_11 ) ;
F_13 ( ! F_8 ( V_3 ) &&
! F_9 ( V_3 ) ) ;
} else if ( ( V_20 == V_31 ) ||
( ( V_20 == V_32 ) &&
V_14 -> V_33 == 0x1af4 &&
V_14 -> V_34 == 0x1100 ) ) {
V_11 -> V_16 = F_1 ( V_3 ) ;
} else
continue;
break;
}
}
if ( ! V_14 )
F_3 ( L_12 ) ;
F_16 ( V_14 ) ;
}
bool F_17 ( struct V_2 * V_3 )
{
if ( F_11 ( V_3 ) -> V_35 < 6 )
return false ;
if ( V_36 . V_37 >= 0 )
return V_36 . V_37 ;
if ( V_36 . V_38 )
return false ;
if ( F_18 ( V_3 ) )
return false ;
#ifdef F_19
if ( F_11 ( V_3 ) -> V_35 == 6 && V_39 )
return false ;
#endif
return true ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_40 * V_41 ;
F_21 ( V_3 ) ;
F_22 (dev, encoder)
if ( V_41 -> V_42 )
V_41 -> V_42 ( V_41 ) ;
F_23 ( V_3 ) ;
}
static bool F_24 ( struct V_10 * V_11 )
{
#if F_25 ( V_43 )
if ( F_26 () < V_44 )
return true ;
#endif
return false ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
T_1 V_45 ;
int error ;
F_28 ( & V_11 -> V_46 ) ;
V_11 -> V_47 = V_48 ;
F_29 ( & V_11 -> V_46 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 , true ) ;
F_32 ( V_3 ) ;
F_33 ( V_3 -> V_49 ) ;
error = F_34 ( V_3 ) ;
if ( error ) {
F_35 ( & V_3 -> V_49 -> V_3 ,
L_13 ) ;
goto V_50;
}
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
F_40 ( V_11 ) ;
F_41 ( V_11 ) ;
F_20 ( V_11 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
V_45 = F_24 ( V_11 ) ? V_51 : V_52 ;
F_45 ( V_3 , V_45 ) ;
F_46 ( V_3 , false ) ;
F_47 ( V_3 ) ;
F_48 ( V_3 , V_53 , true ) ;
V_11 -> V_54 ++ ;
F_31 ( V_11 , false ) ;
if ( F_49 ( V_11 ) )
F_50 ( & V_11 -> V_55 . V_56 ) ;
V_50:
F_51 ( V_11 ) ;
return error ;
}
static int F_52 ( struct V_2 * V_57 , bool V_58 )
{
struct V_10 * V_11 = V_57 -> V_12 ;
bool V_59 ;
int V_4 ;
F_30 ( V_11 ) ;
V_59 = F_24 ( V_11 ) && V_11 -> V_55 . V_60 ;
if ( ! V_59 )
F_53 ( V_11 ) ;
V_4 = F_54 ( V_11 ) ;
if ( V_4 ) {
F_55 ( L_14 , V_4 ) ;
if ( ! V_59 )
F_56 ( V_11 , true ) ;
goto V_50;
}
F_57 ( V_57 -> V_49 ) ;
if ( ! ( V_58 && F_11 ( V_11 ) -> V_35 < 6 ) )
F_58 ( V_57 -> V_49 , V_61 ) ;
V_11 -> V_62 = F_24 ( V_11 ) ;
V_50:
F_51 ( V_11 ) ;
return V_4 ;
}
int F_59 ( struct V_2 * V_3 , T_2 V_63 )
{
int error ;
if ( ! V_3 || ! V_3 -> V_12 ) {
F_55 ( L_15 , V_3 ) ;
F_55 ( L_16 ) ;
return - V_64 ;
}
if ( F_60 ( V_63 . V_65 != V_66 &&
V_63 . V_65 != V_67 ) )
return - V_68 ;
if ( V_3 -> V_69 == V_70 )
return 0 ;
error = F_27 ( V_3 ) ;
if ( error )
return error ;
return F_52 ( V_3 , false ) ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
F_30 ( V_11 ) ;
F_28 ( & V_3 -> V_71 ) ;
F_62 ( V_3 ) ;
F_29 ( & V_3 -> V_71 ) ;
F_63 ( V_3 ) ;
F_64 ( V_3 ) ;
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
F_67 ( V_11 ) ;
F_28 ( & V_3 -> V_71 ) ;
if ( F_68 ( V_3 ) ) {
F_55 ( L_17 ) ;
F_69 ( V_72 , & V_11 -> V_73 . V_74 ) ;
}
F_29 ( & V_3 -> V_71 ) ;
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
F_72 ( & V_11 -> V_75 ) ;
if ( V_11 -> V_76 . V_77 )
V_11 -> V_76 . V_77 ( V_3 ) ;
F_73 ( & V_11 -> V_75 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
F_76 ( V_11 ) ;
F_77 ( V_3 ) ;
F_78 ( V_3 ) ;
F_48 ( V_3 , V_78 , false ) ;
F_28 ( & V_11 -> V_46 ) ;
V_11 -> V_47 = V_79 ;
F_29 ( & V_11 -> V_46 ) ;
F_45 ( V_3 , V_80 ) ;
F_79 ( V_3 ) ;
F_51 ( V_11 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
V_4 = F_58 ( V_3 -> V_49 , V_80 ) ;
if ( V_4 ) {
F_55 ( L_18 , V_4 ) ;
goto V_50;
}
if ( F_81 ( V_3 -> V_49 ) ) {
V_4 = - V_81 ;
goto V_50;
}
F_82 ( V_3 -> V_49 ) ;
F_30 ( V_11 ) ;
if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_85 ( V_11 , false ) ;
if ( V_4 )
F_55 ( L_19 ,
V_4 ) ;
F_86 ( V_3 , true ) ;
if ( F_87 ( V_3 ) )
V_4 = F_88 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_89 ( V_11 ) ;
F_90 ( V_3 ) ;
if ( ! ( V_11 -> V_62 && V_11 -> V_55 . V_60 ) )
F_56 ( V_11 , true ) ;
V_50:
V_11 -> V_62 = false ;
F_51 ( V_11 ) ;
return V_4 ;
}
int F_91 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_3 -> V_69 == V_70 )
return 0 ;
V_4 = F_80 ( V_3 ) ;
if ( V_4 )
return V_4 ;
return F_61 ( V_3 ) ;
}
int F_92 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
bool V_82 ;
int V_4 ;
F_93 ( V_3 ) ;
F_28 ( & V_3 -> V_71 ) ;
F_94 ( V_3 ) ;
V_82 = V_11 -> V_73 . V_83 != 0 ;
V_4 = F_95 ( V_3 ) ;
if ( V_82 ) {
F_96 ( L_20 ) ;
V_11 -> V_73 . V_83 = 0 ;
if ( V_4 == - V_64 ) {
F_96 ( L_21
L_22 ) ;
V_4 = 0 ;
}
}
if ( F_97 ( V_11 ) )
F_98 ( L_23 ) ;
if ( V_4 ) {
F_55 ( L_24 , V_4 ) ;
F_29 ( & V_3 -> V_71 ) ;
return V_4 ;
}
F_99 ( V_11 ) ;
V_11 -> V_73 . V_84 = true ;
V_4 = F_68 ( V_3 ) ;
V_11 -> V_73 . V_84 = false ;
F_29 ( & V_3 -> V_71 ) ;
if ( V_4 ) {
F_55 ( L_25 , V_4 ) ;
return V_4 ;
}
if ( F_11 ( V_3 ) -> V_35 > 5 )
F_100 ( V_3 ) ;
return 0 ;
}
static int F_101 ( struct V_13 * V_49 , const struct V_85 * V_86 )
{
struct V_87 * V_88 =
(struct V_87 * ) V_86 -> V_89 ;
if ( F_102 ( V_88 ) && ! V_36 . V_90 ) {
F_96 ( L_26
L_27 ) ;
return - V_64 ;
}
if ( F_103 ( V_49 -> V_91 ) )
return - V_64 ;
if ( F_25 ( V_92 ) && F_25 ( V_93 ) &&
F_104 () && V_49 != F_105 () &&
! F_106 () )
return - V_94 ;
return F_107 ( V_49 , V_86 , & V_95 ) ;
}
static void
F_108 ( struct V_13 * V_49 )
{
struct V_2 * V_3 = F_109 ( V_49 ) ;
F_110 ( V_3 ) ;
}
static int F_111 ( struct V_21 * V_3 )
{
struct V_13 * V_49 = F_112 ( V_3 ) ;
struct V_2 * V_57 = F_109 ( V_49 ) ;
if ( ! V_57 || ! V_57 -> V_12 ) {
F_35 ( V_3 , L_16 ) ;
return - V_64 ;
}
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_27 ( V_57 ) ;
}
static int F_113 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_114 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_52 ( V_57 , false ) ;
}
static int F_115 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_114 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_52 ( V_57 , true ) ;
}
static int F_116 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_114 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_80 ( V_57 ) ;
}
static int F_117 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_114 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_61 ( V_57 ) ;
}
static int F_118 ( struct V_10 * V_11 )
{
F_119 ( V_11 ) ;
return 0 ;
}
static int F_120 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_121 ( V_3 ) ;
F_122 ( V_3 ) ;
F_123 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_124 ( V_11 ) ;
F_125 ( V_3 ) ;
F_126 ( V_3 ) ;
return 0 ;
}
static void F_127 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = & V_11 -> V_96 ;
int V_98 ;
V_97 -> V_99 = F_128 ( V_100 ) ;
V_97 -> V_101 = F_128 ( V_102 ) ;
V_97 -> V_103 = F_128 ( V_104 ) ;
V_97 -> V_105 = F_128 ( V_106 ) ;
V_97 -> V_107 = F_128 ( V_108 ) ;
for ( V_98 = 0 ; V_98 < F_129 ( V_97 -> V_109 ) ; V_98 ++ )
V_97 -> V_109 [ V_98 ] = F_128 ( F_130 ( V_98 ) ) ;
V_97 -> V_110 = F_128 ( V_111 ) ;
V_97 -> V_112 = F_128 ( V_113 ) ;
V_97 -> V_114 = F_128 ( V_115 ) ;
V_97 -> V_116 = F_128 ( V_117 ) ;
V_97 -> V_118 = F_128 ( V_119 ) ;
V_97 -> V_120 = F_128 ( V_121 ) ;
V_97 -> V_122 = F_128 ( V_123 ) ;
V_97 -> V_124 = F_128 ( V_125 ) ;
V_97 -> V_126 = F_128 ( V_127 ) ;
V_97 -> V_128 = F_128 ( V_129 ) ;
V_97 -> V_130 = F_128 ( V_131 ) ;
V_97 -> V_132 = F_128 ( V_133 ) ;
V_97 -> V_134 = F_128 ( V_135 ) ;
V_97 -> V_136 = F_128 ( V_137 ) ;
V_97 -> V_138 = F_128 ( V_139 ) ;
V_97 -> V_140 = F_128 ( V_141 ) ;
V_97 -> V_142 = F_128 ( V_143 ) ;
V_97 -> V_144 = F_128 ( V_145 ) ;
V_97 -> V_146 = F_128 ( V_147 ) ;
V_97 -> V_148 = F_128 ( V_149 ) ;
V_97 -> V_150 = F_128 ( V_151 ) ;
V_97 -> V_152 = F_128 ( V_153 ) ;
V_97 -> V_154 = F_128 ( V_155 ) ;
V_97 -> V_156 = F_128 ( V_157 ) ;
V_97 -> V_158 = F_128 ( V_159 ) ;
V_97 -> V_160 = F_128 ( V_161 ) ;
V_97 -> V_162 = F_128 ( V_163 ) ;
V_97 -> V_164 = F_128 ( V_165 ) ;
V_97 -> V_166 = F_128 ( V_167 ) ;
V_97 -> V_168 = F_128 ( V_169 ) ;
for ( V_98 = 0 ; V_98 < F_129 ( V_97 -> V_170 ) ; V_98 ++ )
V_97 -> V_170 [ V_98 ] = F_128 ( F_131 ( V_98 ) ) ;
V_97 -> V_171 = F_128 ( V_172 ) ;
V_97 -> V_173 = F_128 ( V_174 ) ;
V_97 -> V_175 = F_128 ( V_176 ) ;
V_97 -> V_177 = F_128 ( V_178 ) ;
V_97 -> V_179 = F_128 ( V_180 ) ;
V_97 -> V_181 = F_128 ( V_182 ) ;
V_97 -> V_183 = F_128 ( V_184 ) ;
V_97 -> V_185 = F_128 ( V_186 ) ;
V_97 -> V_187 = F_128 ( V_188 ) ;
}
static void F_132 ( struct V_10 * V_11 )
{
struct V_96 * V_97 = & V_11 -> V_96 ;
T_3 V_189 ;
int V_98 ;
F_133 ( V_100 , V_97 -> V_99 ) ;
F_133 ( V_102 , V_97 -> V_101 ) ;
F_133 ( V_104 , V_97 -> V_103 | ( 0xffff << 16 ) ) ;
F_133 ( V_106 , V_97 -> V_105 ) ;
F_133 ( V_108 , V_97 -> V_107 ) ;
for ( V_98 = 0 ; V_98 < F_129 ( V_97 -> V_109 ) ; V_98 ++ )
F_133 ( F_130 ( V_98 ) , V_97 -> V_109 [ V_98 ] ) ;
F_133 ( V_111 , V_97 -> V_110 ) ;
F_133 ( V_113 , V_97 -> V_112 ) ;
F_133 ( V_115 , V_97 -> V_114 ) ;
F_133 ( V_117 , V_97 -> V_116 ) ;
F_133 ( V_119 , V_97 -> V_118 ) ;
F_133 ( V_121 , V_97 -> V_120 ) ;
F_133 ( V_123 , V_97 -> V_122 ) ;
F_133 ( V_125 , V_97 -> V_124 ) ;
F_133 ( V_127 , V_97 -> V_126 ) ;
F_133 ( V_129 , V_97 -> V_128 ) ;
F_133 ( V_131 , V_97 -> V_130 ) ;
F_133 ( V_133 , V_97 -> V_132 ) ;
F_133 ( V_135 , V_97 -> V_134 ) ;
F_133 ( V_137 , V_97 -> V_136 ) ;
F_133 ( V_139 , V_97 -> V_138 ) ;
F_133 ( V_141 , V_97 -> V_140 ) ;
F_133 ( V_143 , V_97 -> V_142 ) ;
F_133 ( V_145 , V_97 -> V_144 ) ;
F_133 ( V_147 , V_97 -> V_146 ) ;
F_133 ( V_149 , V_97 -> V_148 ) ;
F_133 ( V_151 , V_97 -> V_150 ) ;
F_133 ( V_153 , V_97 -> V_152 ) ;
F_133 ( V_155 , V_97 -> V_154 ) ;
F_133 ( V_157 , V_97 -> V_156 ) ;
F_133 ( V_159 , V_97 -> V_158 ) ;
F_133 ( V_161 , V_97 -> V_160 ) ;
F_133 ( V_163 , V_97 -> V_162 ) ;
F_133 ( V_165 , V_97 -> V_164 ) ;
F_133 ( V_167 , V_97 -> V_166 ) ;
F_133 ( V_169 , V_97 -> V_168 ) ;
for ( V_98 = 0 ; V_98 < F_129 ( V_97 -> V_170 ) ; V_98 ++ )
F_133 ( F_131 ( V_98 ) , V_97 -> V_170 [ V_98 ] ) ;
F_133 ( V_172 , V_97 -> V_171 ) ;
F_133 ( V_174 , V_97 -> V_173 ) ;
V_189 = F_128 ( V_176 ) ;
V_189 &= V_190 ;
V_189 |= V_97 -> V_175 & ~ V_190 ;
F_133 ( V_176 , V_189 ) ;
V_189 = F_128 ( V_178 ) ;
V_189 &= V_191 ;
V_189 |= V_97 -> V_177 & ~ V_191 ;
F_133 ( V_178 , V_189 ) ;
F_133 ( V_180 , V_97 -> V_179 ) ;
F_133 ( V_182 , V_97 -> V_181 ) ;
F_133 ( V_184 , V_97 -> V_183 ) ;
F_133 ( V_186 , V_97 -> V_185 ) ;
F_133 ( V_188 , V_97 -> V_187 ) ;
}
int F_134 ( struct V_10 * V_11 , bool V_192 )
{
T_3 V_189 ;
int V_193 ;
#define F_135 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_189 = F_128 ( V_178 ) ;
V_189 &= ~ V_191 ;
if ( V_192 )
V_189 |= V_191 ;
F_133 ( V_178 , V_189 ) ;
if ( ! V_192 )
return 0 ;
V_193 = F_136 ( F_135 , 20 ) ;
if ( V_193 )
F_55 ( L_28 ,
F_128 ( V_178 ) ) ;
return V_193 ;
#undef F_135
}
static int F_137 ( struct V_10 * V_11 , bool V_194 )
{
T_3 V_189 ;
int V_193 = 0 ;
V_189 = F_128 ( V_176 ) ;
V_189 &= ~ V_190 ;
if ( V_194 )
V_189 |= V_190 ;
F_133 ( V_176 , V_189 ) ;
F_138 ( V_176 ) ;
#define F_135 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_193 = F_136 ( F_135 , 1 ) ;
if ( V_193 )
F_55 ( L_29 ) ;
return V_193 ;
#undef F_135
}
static int F_139 ( struct V_10 * V_11 ,
bool V_195 )
{
T_3 V_196 ;
T_3 V_189 ;
int V_193 ;
V_196 = V_197 | V_198 ;
V_189 = V_195 ? V_196 : 0 ;
#define F_135 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_135 )
return 0 ;
F_3 ( L_30 ,
F_140 ( V_195 ) ,
F_128 ( V_199 ) ) ;
V_193 = F_136 ( F_135 , 3 ) ;
if ( V_193 )
F_55 ( L_31 ,
F_140 ( V_195 ) ) ;
return V_193 ;
#undef F_135
}
static void F_141 ( struct V_10 * V_11 )
{
if ( ! ( F_128 ( V_199 ) & V_200 ) )
return;
F_142 ( L_32 ) ;
F_133 ( V_199 , V_200 ) ;
}
static int F_143 ( struct V_10 * V_11 )
{
T_3 V_196 ;
int V_193 ;
( void ) F_139 ( V_11 , false ) ;
V_196 = V_201 | V_202 ;
F_13 ( ( F_128 ( V_176 ) & V_196 ) != V_196 ) ;
F_141 ( V_11 ) ;
V_193 = F_134 ( V_11 , true ) ;
if ( V_193 )
goto V_203;
V_193 = F_137 ( V_11 , false ) ;
if ( V_193 )
goto V_204;
if ( ! F_84 ( V_11 -> V_3 ) )
F_127 ( V_11 ) ;
V_193 = F_134 ( V_11 , false ) ;
if ( V_193 )
goto V_204;
return 0 ;
V_204:
F_137 ( V_11 , true ) ;
V_203:
F_134 ( V_11 , false ) ;
return V_193 ;
}
static int F_85 ( struct V_10 * V_11 ,
bool V_205 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
int V_193 ;
int V_4 ;
V_4 = F_134 ( V_11 , true ) ;
if ( ! F_84 ( V_11 -> V_3 ) )
F_132 ( V_11 ) ;
V_193 = F_137 ( V_11 , true ) ;
if ( ! V_4 )
V_4 = V_193 ;
V_193 = F_134 ( V_11 , false ) ;
if ( ! V_4 )
V_4 = V_193 ;
F_141 ( V_11 ) ;
if ( V_205 ) {
F_144 ( V_3 ) ;
F_145 ( V_3 ) ;
}
return V_4 ;
}
static int F_146 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_112 ( V_21 ) ;
struct V_2 * V_3 = F_109 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
if ( F_60 ( ! ( V_11 -> V_206 . V_207 && F_147 ( V_3 ) ) ) )
return - V_64 ;
if ( F_60 ( ! F_148 ( V_3 ) ) )
return - V_64 ;
F_3 ( L_33 ) ;
if ( ! F_149 ( & V_3 -> V_71 ) ) {
F_3 ( L_34 ) ;
F_150 ( V_21 ) ;
return - V_208 ;
}
F_30 ( V_11 ) ;
F_151 ( V_11 ) ;
F_29 ( & V_3 -> V_71 ) ;
F_152 ( & V_11 -> V_73 . V_209 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
F_40 ( V_11 ) ;
V_4 = F_54 ( V_11 ) ;
if ( V_4 ) {
F_55 ( L_35 , V_4 ) ;
F_67 ( V_11 ) ;
F_51 ( V_11 ) ;
return V_4 ;
}
F_46 ( V_3 , false ) ;
F_51 ( V_11 ) ;
F_60 ( F_153 ( & V_11 -> V_210 . V_211 ) ) ;
if ( F_154 ( V_11 ) )
F_55 ( L_36 ) ;
V_11 -> V_210 . V_212 = true ;
if ( F_7 ( V_3 ) ) {
F_45 ( V_3 , V_61 ) ;
} else {
F_45 ( V_3 , V_51 ) ;
}
F_155 ( V_11 ) ;
F_3 ( L_37 ) ;
return 0 ;
}
static int F_156 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_112 ( V_21 ) ;
struct V_2 * V_3 = F_109 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 = 0 ;
if ( F_60 ( ! F_148 ( V_3 ) ) )
return - V_64 ;
F_3 ( L_38 ) ;
F_60 ( F_153 ( & V_11 -> V_210 . V_211 ) ) ;
F_30 ( V_11 ) ;
F_45 ( V_3 , V_80 ) ;
V_11 -> V_210 . V_212 = false ;
if ( F_157 ( V_11 ) )
F_142 ( L_39 ) ;
F_70 ( V_3 ) ;
if ( F_4 ( V_11 ) )
F_65 ( V_3 ) ;
if ( F_87 ( V_3 ) )
V_4 = F_88 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_89 ( V_11 ) ;
else if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_85 ( V_11 , true ) ;
F_158 ( V_3 ) ;
F_159 ( V_3 ) ;
F_67 ( V_11 ) ;
if ( ! F_83 ( V_11 ) && ! F_84 ( V_11 ) )
F_76 ( V_11 ) ;
F_100 ( V_3 ) ;
F_51 ( V_11 ) ;
if ( V_4 )
F_55 ( L_40 , V_4 ) ;
else
F_3 ( L_41 ) ;
return V_4 ;
}
static int F_54 ( struct V_10 * V_11 )
{
int V_4 ;
if ( F_87 ( V_11 ) )
V_4 = F_120 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
V_4 = F_118 ( V_11 ) ;
else if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_143 ( V_11 ) ;
else
V_4 = 0 ;
return V_4 ;
}
static int T_4 F_160 ( void )
{
V_95 . V_213 = V_214 ;
if ( V_36 . V_215 == 0 )
V_95 . V_216 &= ~ V_217 ;
#ifdef F_161
if ( F_162 () && V_36 . V_215 == - 1 )
V_95 . V_216 &= ~ V_217 ;
#endif
if ( ! ( V_95 . V_216 & V_217 ) ) {
F_142 ( L_42 ) ;
return 0 ;
}
if ( V_36 . V_218 )
V_95 . V_216 |= V_219 ;
return F_163 ( & V_95 , & V_220 ) ;
}
static void T_5 F_164 ( void )
{
if ( ! ( V_95 . V_216 & V_217 ) )
return;
F_165 ( & V_95 , & V_220 ) ;
}
