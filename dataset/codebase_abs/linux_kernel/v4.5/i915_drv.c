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
F_21 ( V_3 ) ;
F_38 ( V_3 ) ;
F_23 ( V_3 ) ;
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
F_21 ( V_3 ) ;
F_74 ( V_3 ) ;
F_23 ( V_3 ) ;
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
int V_4 = 0 ;
if ( F_81 ( V_3 -> V_49 ) ) {
V_4 = - V_81 ;
goto V_50;
}
F_82 ( V_3 -> V_49 ) ;
F_30 ( V_11 ) ;
if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_85 ( V_11 , false ) ;
if ( V_4 )
F_55 ( L_18 ,
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
F_96 ( L_19 ) ;
V_11 -> V_73 . V_83 = 0 ;
if ( V_4 == - V_64 ) {
F_96 ( L_20
L_21 ) ;
V_4 = 0 ;
}
}
if ( F_97 ( V_11 ) )
F_98 ( L_22 ) ;
if ( V_4 ) {
F_55 ( L_23 , V_4 ) ;
F_29 ( & V_3 -> V_71 ) ;
return V_4 ;
}
F_99 ( V_11 ) ;
V_11 -> V_73 . V_84 = true ;
V_4 = F_68 ( V_3 ) ;
V_11 -> V_73 . V_84 = false ;
F_29 ( & V_3 -> V_71 ) ;
if ( V_4 ) {
F_55 ( L_24 , V_4 ) ;
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
F_96 ( L_25
L_26 ) ;
return - V_64 ;
}
if ( F_103 ( V_49 -> V_91 ) )
return - V_64 ;
return F_104 ( V_49 , V_86 , & V_92 ) ;
}
static void
F_105 ( struct V_13 * V_49 )
{
struct V_2 * V_3 = F_106 ( V_49 ) ;
F_107 ( V_3 ) ;
}
static int F_108 ( struct V_21 * V_3 )
{
struct V_13 * V_49 = F_109 ( V_3 ) ;
struct V_2 * V_57 = F_106 ( V_49 ) ;
if ( ! V_57 || ! V_57 -> V_12 ) {
F_35 ( V_3 , L_16 ) ;
return - V_64 ;
}
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_27 ( V_57 ) ;
}
static int F_110 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_111 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_52 ( V_57 , false ) ;
}
static int F_112 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_111 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_52 ( V_57 , true ) ;
}
static int F_113 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_111 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_80 ( V_57 ) ;
}
static int F_114 ( struct V_21 * V_3 )
{
struct V_2 * V_57 = F_111 ( V_3 ) -> V_3 ;
if ( V_57 -> V_69 == V_70 )
return 0 ;
return F_61 ( V_57 ) ;
}
static int F_115 ( struct V_10 * V_11 )
{
F_116 ( V_11 ) ;
return 0 ;
}
static int F_117 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_118 ( V_3 ) ;
F_119 ( V_3 ) ;
F_120 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
F_121 ( V_11 ) ;
F_122 ( V_3 ) ;
F_123 ( V_3 ) ;
F_124 ( V_3 ) ;
return 0 ;
}
static void F_125 ( struct V_10 * V_11 )
{
struct V_93 * V_94 = & V_11 -> V_93 ;
int V_95 ;
V_94 -> V_96 = F_126 ( V_97 ) ;
V_94 -> V_98 = F_126 ( V_99 ) ;
V_94 -> V_100 = F_126 ( V_101 ) ;
V_94 -> V_102 = F_126 ( V_103 ) ;
V_94 -> V_104 = F_126 ( V_105 ) ;
for ( V_95 = 0 ; V_95 < F_127 ( V_94 -> V_106 ) ; V_95 ++ )
V_94 -> V_106 [ V_95 ] = F_126 ( F_128 ( V_95 ) ) ;
V_94 -> V_107 = F_126 ( V_108 ) ;
V_94 -> V_109 = F_126 ( V_110 ) ;
V_94 -> V_111 = F_126 ( V_112 ) ;
V_94 -> V_113 = F_126 ( V_114 ) ;
V_94 -> V_115 = F_126 ( V_116 ) ;
V_94 -> V_117 = F_126 ( V_118 ) ;
V_94 -> V_119 = F_126 ( V_120 ) ;
V_94 -> V_121 = F_126 ( V_122 ) ;
V_94 -> V_123 = F_126 ( V_124 ) ;
V_94 -> V_125 = F_126 ( V_126 ) ;
V_94 -> V_127 = F_126 ( V_128 ) ;
V_94 -> V_129 = F_126 ( V_130 ) ;
V_94 -> V_131 = F_126 ( V_132 ) ;
V_94 -> V_133 = F_126 ( V_134 ) ;
V_94 -> V_135 = F_126 ( V_136 ) ;
V_94 -> V_137 = F_126 ( V_138 ) ;
V_94 -> V_139 = F_126 ( V_140 ) ;
V_94 -> V_141 = F_126 ( V_142 ) ;
V_94 -> V_143 = F_126 ( V_144 ) ;
V_94 -> V_145 = F_126 ( V_146 ) ;
V_94 -> V_147 = F_126 ( V_148 ) ;
V_94 -> V_149 = F_126 ( V_150 ) ;
V_94 -> V_151 = F_126 ( V_152 ) ;
V_94 -> V_153 = F_126 ( V_154 ) ;
V_94 -> V_155 = F_126 ( V_156 ) ;
V_94 -> V_157 = F_126 ( V_158 ) ;
V_94 -> V_159 = F_126 ( V_160 ) ;
V_94 -> V_161 = F_126 ( V_162 ) ;
V_94 -> V_163 = F_126 ( V_164 ) ;
V_94 -> V_165 = F_126 ( V_166 ) ;
for ( V_95 = 0 ; V_95 < F_127 ( V_94 -> V_167 ) ; V_95 ++ )
V_94 -> V_167 [ V_95 ] = F_126 ( F_129 ( V_95 ) ) ;
V_94 -> V_168 = F_126 ( V_169 ) ;
V_94 -> V_170 = F_126 ( V_171 ) ;
V_94 -> V_172 = F_126 ( V_173 ) ;
V_94 -> V_174 = F_126 ( V_175 ) ;
V_94 -> V_176 = F_126 ( V_177 ) ;
V_94 -> V_178 = F_126 ( V_179 ) ;
V_94 -> V_180 = F_126 ( V_181 ) ;
V_94 -> V_182 = F_126 ( V_183 ) ;
V_94 -> V_184 = F_126 ( V_185 ) ;
}
static void F_130 ( struct V_10 * V_11 )
{
struct V_93 * V_94 = & V_11 -> V_93 ;
T_3 V_186 ;
int V_95 ;
F_131 ( V_97 , V_94 -> V_96 ) ;
F_131 ( V_99 , V_94 -> V_98 ) ;
F_131 ( V_101 , V_94 -> V_100 | ( 0xffff << 16 ) ) ;
F_131 ( V_103 , V_94 -> V_102 ) ;
F_131 ( V_105 , V_94 -> V_104 ) ;
for ( V_95 = 0 ; V_95 < F_127 ( V_94 -> V_106 ) ; V_95 ++ )
F_131 ( F_128 ( V_95 ) , V_94 -> V_106 [ V_95 ] ) ;
F_131 ( V_108 , V_94 -> V_107 ) ;
F_131 ( V_110 , V_94 -> V_109 ) ;
F_131 ( V_112 , V_94 -> V_111 ) ;
F_131 ( V_114 , V_94 -> V_113 ) ;
F_131 ( V_116 , V_94 -> V_115 ) ;
F_131 ( V_118 , V_94 -> V_117 ) ;
F_131 ( V_120 , V_94 -> V_119 ) ;
F_131 ( V_122 , V_94 -> V_121 ) ;
F_131 ( V_124 , V_94 -> V_123 ) ;
F_131 ( V_126 , V_94 -> V_125 ) ;
F_131 ( V_128 , V_94 -> V_127 ) ;
F_131 ( V_130 , V_94 -> V_129 ) ;
F_131 ( V_132 , V_94 -> V_131 ) ;
F_131 ( V_134 , V_94 -> V_133 ) ;
F_131 ( V_136 , V_94 -> V_135 ) ;
F_131 ( V_138 , V_94 -> V_137 ) ;
F_131 ( V_140 , V_94 -> V_139 ) ;
F_131 ( V_142 , V_94 -> V_141 ) ;
F_131 ( V_144 , V_94 -> V_143 ) ;
F_131 ( V_146 , V_94 -> V_145 ) ;
F_131 ( V_148 , V_94 -> V_147 ) ;
F_131 ( V_150 , V_94 -> V_149 ) ;
F_131 ( V_152 , V_94 -> V_151 ) ;
F_131 ( V_154 , V_94 -> V_153 ) ;
F_131 ( V_156 , V_94 -> V_155 ) ;
F_131 ( V_158 , V_94 -> V_157 ) ;
F_131 ( V_160 , V_94 -> V_159 ) ;
F_131 ( V_162 , V_94 -> V_161 ) ;
F_131 ( V_164 , V_94 -> V_163 ) ;
F_131 ( V_166 , V_94 -> V_165 ) ;
for ( V_95 = 0 ; V_95 < F_127 ( V_94 -> V_167 ) ; V_95 ++ )
F_131 ( F_129 ( V_95 ) , V_94 -> V_167 [ V_95 ] ) ;
F_131 ( V_169 , V_94 -> V_168 ) ;
F_131 ( V_171 , V_94 -> V_170 ) ;
V_186 = F_126 ( V_173 ) ;
V_186 &= V_187 ;
V_186 |= V_94 -> V_172 & ~ V_187 ;
F_131 ( V_173 , V_186 ) ;
V_186 = F_126 ( V_175 ) ;
V_186 &= V_188 ;
V_186 |= V_94 -> V_174 & ~ V_188 ;
F_131 ( V_175 , V_186 ) ;
F_131 ( V_177 , V_94 -> V_176 ) ;
F_131 ( V_179 , V_94 -> V_178 ) ;
F_131 ( V_181 , V_94 -> V_180 ) ;
F_131 ( V_183 , V_94 -> V_182 ) ;
F_131 ( V_185 , V_94 -> V_184 ) ;
}
int F_132 ( struct V_10 * V_11 , bool V_189 )
{
T_3 V_186 ;
int V_190 ;
#define F_133 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_186 = F_126 ( V_175 ) ;
V_186 &= ~ V_188 ;
if ( V_189 )
V_186 |= V_188 ;
F_131 ( V_175 , V_186 ) ;
if ( ! V_189 )
return 0 ;
V_190 = F_134 ( F_133 , 20 ) ;
if ( V_190 )
F_55 ( L_27 ,
F_126 ( V_175 ) ) ;
return V_190 ;
#undef F_133
}
static int F_135 ( struct V_10 * V_11 , bool V_191 )
{
T_3 V_186 ;
int V_190 = 0 ;
V_186 = F_126 ( V_173 ) ;
V_186 &= ~ V_187 ;
if ( V_191 )
V_186 |= V_187 ;
F_131 ( V_173 , V_186 ) ;
F_136 ( V_173 ) ;
#define F_133 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_190 = F_134 ( F_133 , 1 ) ;
if ( V_190 )
F_55 ( L_28 ) ;
return V_190 ;
#undef F_133
}
static int F_137 ( struct V_10 * V_11 ,
bool V_192 )
{
T_3 V_193 ;
T_3 V_186 ;
int V_190 ;
V_193 = V_194 | V_195 ;
V_186 = V_192 ? V_193 : 0 ;
#define F_133 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_133 )
return 0 ;
F_3 ( L_29 ,
V_192 ? L_30 : L_31 ,
F_126 ( V_196 ) ) ;
V_190 = F_134 ( F_133 , 3 ) ;
if ( V_190 )
F_55 ( L_32 ,
V_192 ? L_30 : L_31 ) ;
return V_190 ;
#undef F_133
}
static void F_138 ( struct V_10 * V_11 )
{
if ( ! ( F_126 ( V_196 ) & V_197 ) )
return;
F_55 ( L_33 ) ;
F_131 ( V_196 , V_197 ) ;
}
static int F_139 ( struct V_10 * V_11 )
{
T_3 V_193 ;
int V_190 ;
( void ) F_137 ( V_11 , false ) ;
V_193 = V_198 | V_199 ;
F_13 ( ( F_126 ( V_173 ) & V_193 ) != V_193 ) ;
F_138 ( V_11 ) ;
V_190 = F_132 ( V_11 , true ) ;
if ( V_190 )
goto V_200;
V_190 = F_135 ( V_11 , false ) ;
if ( V_190 )
goto V_201;
if ( ! F_84 ( V_11 -> V_3 ) )
F_125 ( V_11 ) ;
V_190 = F_132 ( V_11 , false ) ;
if ( V_190 )
goto V_201;
return 0 ;
V_201:
F_135 ( V_11 , true ) ;
V_200:
F_132 ( V_11 , false ) ;
return V_190 ;
}
static int F_85 ( struct V_10 * V_11 ,
bool V_202 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
int V_190 ;
int V_4 ;
V_4 = F_132 ( V_11 , true ) ;
if ( ! F_84 ( V_11 -> V_3 ) )
F_130 ( V_11 ) ;
V_190 = F_135 ( V_11 , true ) ;
if ( ! V_4 )
V_4 = V_190 ;
V_190 = F_132 ( V_11 , false ) ;
if ( ! V_4 )
V_4 = V_190 ;
F_138 ( V_11 ) ;
if ( V_202 ) {
F_140 ( V_3 ) ;
F_141 ( V_3 ) ;
}
return V_4 ;
}
static int F_142 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_109 ( V_21 ) ;
struct V_2 * V_3 = F_106 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
if ( F_60 ( ! ( V_11 -> V_203 . V_204 && F_143 ( V_3 ) ) ) )
return - V_64 ;
if ( F_60 ( ! F_144 ( V_3 ) ) )
return - V_64 ;
F_3 ( L_34 ) ;
if ( ! F_145 ( & V_3 -> V_71 ) ) {
F_3 ( L_35 ) ;
F_146 ( V_21 ) ;
return - V_205 ;
}
F_30 ( V_11 ) ;
F_147 ( V_11 ) ;
F_29 ( & V_3 -> V_71 ) ;
F_148 ( & V_11 -> V_73 . V_206 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
F_40 ( V_11 ) ;
V_4 = F_54 ( V_11 ) ;
if ( V_4 ) {
F_55 ( L_36 , V_4 ) ;
F_67 ( V_11 ) ;
F_51 ( V_11 ) ;
return V_4 ;
}
F_46 ( V_3 , false ) ;
F_51 ( V_11 ) ;
F_60 ( F_149 ( & V_11 -> V_207 . V_208 ) ) ;
V_11 -> V_207 . V_209 = true ;
if ( F_7 ( V_3 ) ) {
F_45 ( V_3 , V_61 ) ;
} else {
F_45 ( V_3 , V_51 ) ;
}
F_150 ( V_11 ) ;
F_3 ( L_37 ) ;
return 0 ;
}
static int F_151 ( struct V_21 * V_21 )
{
struct V_13 * V_49 = F_109 ( V_21 ) ;
struct V_2 * V_3 = F_106 ( V_49 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 = 0 ;
if ( F_60 ( ! F_144 ( V_3 ) ) )
return - V_64 ;
F_3 ( L_38 ) ;
F_60 ( F_149 ( & V_11 -> V_207 . V_208 ) ) ;
F_30 ( V_11 ) ;
F_45 ( V_3 , V_80 ) ;
V_11 -> V_207 . V_209 = false ;
F_70 ( V_3 ) ;
if ( F_4 ( V_11 ) )
F_65 ( V_3 ) ;
if ( F_87 ( V_3 ) )
V_4 = F_88 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_89 ( V_11 ) ;
else if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_85 ( V_11 , true ) ;
F_152 ( V_3 ) ;
F_153 ( V_3 ) ;
F_67 ( V_11 ) ;
if ( ! F_83 ( V_11 ) && ! F_84 ( V_11 ) )
F_76 ( V_11 ) ;
F_100 ( V_3 ) ;
F_51 ( V_11 ) ;
if ( V_4 )
F_55 ( L_39 , V_4 ) ;
else
F_3 ( L_40 ) ;
return V_4 ;
}
static int F_54 ( struct V_10 * V_11 )
{
int V_4 ;
if ( F_87 ( V_11 ) )
V_4 = F_117 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
V_4 = F_115 ( V_11 ) ;
else if ( F_83 ( V_11 ) || F_84 ( V_11 ) )
V_4 = F_139 ( V_11 ) ;
else
V_4 = 0 ;
return V_4 ;
}
static int T_4 F_154 ( void )
{
V_92 . V_210 = V_211 ;
if ( V_36 . V_212 == 0 )
V_92 . V_213 &= ~ V_214 ;
#ifdef F_155
if ( F_156 () && V_36 . V_212 == - 1 )
V_92 . V_213 &= ~ V_214 ;
#endif
if ( ! ( V_92 . V_213 & V_214 ) ) {
F_157 ( L_41 ) ;
return 0 ;
}
if ( V_36 . V_215 )
V_92 . V_213 |= V_216 ;
return F_158 ( & V_92 , & V_217 ) ;
}
static void T_5 F_159 ( void )
{
if ( ! ( V_92 . V_213 & V_214 ) )
return;
F_160 ( & V_92 , & V_217 ) ;
}
