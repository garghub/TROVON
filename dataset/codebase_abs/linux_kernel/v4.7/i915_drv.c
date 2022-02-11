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
} else if ( V_20 == V_31 ) {
V_11 -> V_16 = V_32 ;
F_3 ( L_12 ) ;
F_13 ( ! F_9 ( V_3 ) ) ;
} else if ( ( V_20 == V_33 ) ||
( V_20 == V_34 ) ||
( ( V_20 == V_35 ) &&
V_14 -> V_36 == 0x1af4 &&
V_14 -> V_37 == 0x1100 ) ) {
V_11 -> V_16 = F_1 ( V_3 ) ;
} else
continue;
break;
}
}
if ( ! V_14 )
F_3 ( L_13 ) ;
F_16 ( V_14 ) ;
}
bool F_17 ( struct V_2 * V_3 )
{
if ( F_11 ( V_3 ) -> V_38 < 6 )
return false ;
if ( V_39 . V_40 >= 0 )
return V_39 . V_40 ;
if ( V_39 . V_41 )
return false ;
if ( F_18 ( V_3 ) )
return false ;
#ifdef F_19
if ( F_11 ( V_3 ) -> V_38 == 6 && V_42 )
return false ;
#endif
return true ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_43 * V_44 ;
F_21 ( V_3 ) ;
F_22 (dev, encoder)
if ( V_44 -> V_45 )
V_44 -> V_45 ( V_44 ) ;
F_23 ( V_3 ) ;
}
static bool F_24 ( struct V_10 * V_11 )
{
#if F_25 ( V_46 )
if ( F_26 () < V_47 )
return true ;
#endif
return false ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
T_1 V_48 ;
int error ;
F_28 ( & V_11 -> V_49 ) ;
V_11 -> V_50 = V_51 ;
F_29 ( & V_11 -> V_49 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 , true ) ;
F_32 ( V_3 ) ;
F_33 ( V_3 -> V_52 ) ;
error = F_34 ( V_3 ) ;
if ( error ) {
F_35 ( & V_3 -> V_52 -> V_3 ,
L_14 ) ;
goto V_53;
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
V_48 = F_24 ( V_11 ) ? V_54 : V_55 ;
F_45 ( V_3 , V_48 ) ;
F_46 ( V_3 , false ) ;
F_47 ( V_3 ) ;
F_48 ( V_3 , V_56 , true ) ;
V_11 -> V_57 ++ ;
F_31 ( V_11 , false ) ;
F_49 ( V_11 ) ;
V_53:
F_50 ( V_11 ) ;
return error ;
}
static int F_51 ( struct V_2 * V_58 , bool V_59 )
{
struct V_10 * V_11 = V_58 -> V_12 ;
bool V_60 ;
int V_4 ;
F_30 ( V_11 ) ;
V_60 = ! F_52 ( V_11 ) &&
F_24 ( V_11 ) && V_11 -> V_61 . V_62 ;
if ( ! V_60 )
F_53 ( V_11 ) ;
V_4 = 0 ;
if ( F_52 ( V_11 ) )
F_54 ( V_11 ) ;
else if ( F_6 ( V_11 ) || F_7 ( V_11 ) )
F_55 ( V_11 ) ;
else if ( F_56 ( V_11 ) || F_57 ( V_11 ) )
V_4 = F_58 ( V_11 ) ;
if ( V_4 ) {
F_59 ( L_15 , V_4 ) ;
if ( ! V_60 )
F_60 ( V_11 , true ) ;
goto V_53;
}
F_61 ( V_58 -> V_52 ) ;
if ( ! ( V_59 && F_11 ( V_11 ) -> V_38 < 6 ) )
F_62 ( V_58 -> V_52 , V_63 ) ;
V_11 -> V_64 = F_24 ( V_11 ) ;
V_53:
F_50 ( V_11 ) ;
return V_4 ;
}
int F_63 ( struct V_2 * V_3 , T_2 V_65 )
{
int error ;
if ( ! V_3 || ! V_3 -> V_12 ) {
F_59 ( L_16 , V_3 ) ;
F_59 ( L_17 ) ;
return - V_66 ;
}
if ( F_64 ( V_65 . V_67 != V_68 &&
V_65 . V_67 != V_69 ) )
return - V_70 ;
if ( V_3 -> V_71 == V_72 )
return 0 ;
error = F_27 ( V_3 ) ;
if ( error )
return error ;
return F_51 ( V_3 , false ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
F_30 ( V_11 ) ;
V_4 = F_66 ( V_3 ) ;
if ( V_4 )
F_59 ( L_18 ) ;
F_67 ( V_11 ) ;
F_28 ( & V_3 -> V_73 ) ;
F_68 ( V_3 ) ;
F_29 ( & V_3 -> V_73 ) ;
F_69 ( V_3 ) ;
F_70 ( V_3 ) ;
F_71 ( V_3 ) ;
F_72 ( V_3 ) ;
F_73 ( V_11 ) ;
F_28 ( & V_3 -> V_73 ) ;
if ( F_74 ( V_3 ) ) {
F_59 ( L_19 ) ;
F_75 ( V_74 , & V_11 -> V_75 . V_76 ) ;
}
F_29 ( & V_3 -> V_73 ) ;
F_76 ( V_3 ) ;
F_77 ( V_3 ) ;
F_78 ( & V_11 -> V_77 ) ;
if ( V_11 -> V_78 . V_79 )
V_11 -> V_78 . V_79 ( V_3 ) ;
F_79 ( & V_11 -> V_77 ) ;
F_80 ( V_3 ) ;
F_81 ( V_3 ) ;
F_82 ( V_11 ) ;
F_83 ( V_3 ) ;
F_84 ( V_3 ) ;
F_48 ( V_3 , V_80 , false ) ;
F_28 ( & V_11 -> V_49 ) ;
V_11 -> V_50 = V_81 ;
F_29 ( & V_11 -> V_49 ) ;
F_45 ( V_3 , V_82 ) ;
F_85 ( V_3 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
V_4 = F_62 ( V_3 -> V_52 , V_82 ) ;
if ( V_4 ) {
F_59 ( L_20 , V_4 ) ;
goto V_53;
}
if ( F_87 ( V_3 -> V_52 ) ) {
V_4 = - V_83 ;
goto V_53;
}
F_88 ( V_3 -> V_52 ) ;
F_30 ( V_11 ) ;
if ( F_56 ( V_11 ) || F_57 ( V_11 ) )
V_4 = F_89 ( V_11 , false ) ;
if ( V_4 )
F_59 ( L_21 ,
V_4 ) ;
F_90 ( V_3 , true ) ;
if ( F_52 ( V_3 ) ) {
if ( ! V_11 -> V_64 )
F_91 ( V_11 ) ;
F_92 ( V_11 ) ;
} else if ( F_6 ( V_11 ) || F_7 ( V_11 ) ) {
F_93 ( V_11 ) ;
}
F_94 ( V_3 ) ;
if ( F_52 ( V_11 ) ||
! ( V_11 -> V_64 && V_11 -> V_61 . V_62 ) )
F_60 ( V_11 , true ) ;
F_50 ( V_11 ) ;
V_53:
V_11 -> V_64 = false ;
return V_4 ;
}
int F_95 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_3 -> V_71 == V_72 )
return 0 ;
V_4 = F_86 ( V_3 ) ;
if ( V_4 )
return V_4 ;
return F_65 ( V_3 ) ;
}
int F_96 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_84 * error = & V_11 -> V_75 ;
unsigned V_76 ;
int V_4 ;
F_97 ( V_3 ) ;
F_28 ( & V_3 -> V_73 ) ;
F_98 ( V_74 , & error -> V_76 ) ;
V_76 = F_99 ( & error -> V_76 ) ;
if ( F_13 ( F_100 ( V_76 ) ) ) {
V_4 = - V_83 ;
goto error;
}
F_101 ( V_3 ) ;
V_4 = F_102 ( V_3 , V_85 ) ;
if ( error -> V_86 != 0 ) {
F_103 ( L_22 ) ;
error -> V_86 = 0 ;
if ( V_4 == - V_66 ) {
F_103 ( L_23
L_24 ) ;
V_4 = 0 ;
}
}
if ( F_104 ( V_11 ) )
F_105 ( L_25 ) ;
if ( V_4 ) {
if ( V_4 != - V_66 )
F_59 ( L_26 , V_4 ) ;
else
F_106 ( L_27 ) ;
goto error;
}
F_107 ( V_11 ) ;
V_4 = F_74 ( V_3 ) ;
if ( V_4 ) {
F_59 ( L_28 , V_4 ) ;
goto error;
}
F_29 ( & V_3 -> V_73 ) ;
if ( F_11 ( V_3 ) -> V_38 > 5 )
F_108 ( V_3 ) ;
return 0 ;
error:
F_75 ( V_74 , & error -> V_76 ) ;
F_29 ( & V_3 -> V_73 ) ;
return V_4 ;
}
static int F_109 ( struct V_13 * V_52 , const struct V_87 * V_88 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_88 -> V_91 ;
if ( F_110 ( V_90 ) && ! V_39 . V_92 ) {
F_103 ( L_29
L_30 ) ;
return - V_66 ;
}
if ( F_111 ( V_52 -> V_93 ) )
return - V_66 ;
if ( F_25 ( V_94 ) && F_25 ( V_95 ) &&
F_112 () && V_52 != F_113 () &&
! F_114 () )
return - V_96 ;
return F_115 ( V_52 , V_88 , & V_97 ) ;
}
static void
F_116 ( struct V_13 * V_52 )
{
struct V_2 * V_3 = F_117 ( V_52 ) ;
F_118 ( V_3 ) ;
}
static int F_119 ( struct V_21 * V_3 )
{
struct V_13 * V_52 = F_120 ( V_3 ) ;
struct V_2 * V_58 = F_117 ( V_52 ) ;
if ( ! V_58 || ! V_58 -> V_12 ) {
F_35 ( V_3 , L_17 ) ;
return - V_66 ;
}
if ( V_58 -> V_71 == V_72 )
return 0 ;
return F_27 ( V_58 ) ;
}
static int F_121 ( struct V_21 * V_3 )
{
struct V_2 * V_58 = F_122 ( V_3 ) -> V_3 ;
if ( V_58 -> V_71 == V_72 )
return 0 ;
return F_51 ( V_58 , false ) ;
}
static int F_123 ( struct V_21 * V_3 )
{
struct V_2 * V_58 = F_122 ( V_3 ) -> V_3 ;
if ( V_58 -> V_71 == V_72 )
return 0 ;
return F_51 ( V_58 , true ) ;
}
static int F_124 ( struct V_21 * V_3 )
{
struct V_2 * V_58 = F_122 ( V_3 ) -> V_3 ;
if ( V_58 -> V_71 == V_72 )
return 0 ;
return F_86 ( V_58 ) ;
}
static int F_125 ( struct V_21 * V_3 )
{
struct V_2 * V_58 = F_122 ( V_3 ) -> V_3 ;
if ( V_58 -> V_71 == V_72 )
return 0 ;
return F_65 ( V_58 ) ;
}
static void F_126 ( struct V_10 * V_11 )
{
struct V_98 * V_99 = & V_11 -> V_98 ;
int V_100 ;
V_99 -> V_101 = F_127 ( V_102 ) ;
V_99 -> V_103 = F_127 ( V_104 ) ;
V_99 -> V_105 = F_127 ( V_106 ) ;
V_99 -> V_107 = F_127 ( V_108 ) ;
V_99 -> V_109 = F_127 ( V_110 ) ;
for ( V_100 = 0 ; V_100 < F_128 ( V_99 -> V_111 ) ; V_100 ++ )
V_99 -> V_111 [ V_100 ] = F_127 ( F_129 ( V_100 ) ) ;
V_99 -> V_112 = F_127 ( V_113 ) ;
V_99 -> V_114 = F_127 ( V_115 ) ;
V_99 -> V_116 = F_127 ( V_117 ) ;
V_99 -> V_118 = F_127 ( V_119 ) ;
V_99 -> V_120 = F_127 ( V_121 ) ;
V_99 -> V_122 = F_127 ( V_123 ) ;
V_99 -> V_124 = F_127 ( V_125 ) ;
V_99 -> V_126 = F_127 ( V_127 ) ;
V_99 -> V_128 = F_127 ( V_129 ) ;
V_99 -> V_130 = F_127 ( V_131 ) ;
V_99 -> V_132 = F_127 ( V_133 ) ;
V_99 -> V_134 = F_127 ( V_135 ) ;
V_99 -> V_136 = F_127 ( V_137 ) ;
V_99 -> V_138 = F_127 ( V_139 ) ;
V_99 -> V_140 = F_127 ( V_141 ) ;
V_99 -> V_142 = F_127 ( V_143 ) ;
V_99 -> V_144 = F_127 ( V_145 ) ;
V_99 -> V_146 = F_127 ( V_147 ) ;
V_99 -> V_148 = F_127 ( V_149 ) ;
V_99 -> V_150 = F_127 ( V_151 ) ;
V_99 -> V_152 = F_127 ( V_153 ) ;
V_99 -> V_154 = F_127 ( V_155 ) ;
V_99 -> V_156 = F_127 ( V_157 ) ;
V_99 -> V_158 = F_127 ( V_159 ) ;
V_99 -> V_160 = F_127 ( V_161 ) ;
V_99 -> V_162 = F_127 ( V_163 ) ;
V_99 -> V_164 = F_127 ( V_165 ) ;
V_99 -> V_166 = F_127 ( V_167 ) ;
V_99 -> V_168 = F_127 ( V_169 ) ;
V_99 -> V_170 = F_127 ( V_171 ) ;
for ( V_100 = 0 ; V_100 < F_128 ( V_99 -> V_172 ) ; V_100 ++ )
V_99 -> V_172 [ V_100 ] = F_127 ( F_130 ( V_100 ) ) ;
V_99 -> V_173 = F_127 ( V_174 ) ;
V_99 -> V_175 = F_127 ( V_176 ) ;
V_99 -> V_177 = F_127 ( V_178 ) ;
V_99 -> V_179 = F_127 ( V_180 ) ;
V_99 -> V_181 = F_127 ( V_182 ) ;
V_99 -> V_183 = F_127 ( V_184 ) ;
V_99 -> V_185 = F_127 ( V_186 ) ;
V_99 -> V_187 = F_127 ( V_188 ) ;
V_99 -> V_189 = F_127 ( V_190 ) ;
}
static void F_131 ( struct V_10 * V_11 )
{
struct V_98 * V_99 = & V_11 -> V_98 ;
T_3 V_191 ;
int V_100 ;
F_132 ( V_102 , V_99 -> V_101 ) ;
F_132 ( V_104 , V_99 -> V_103 ) ;
F_132 ( V_106 , V_99 -> V_105 | ( 0xffff << 16 ) ) ;
F_132 ( V_108 , V_99 -> V_107 ) ;
F_132 ( V_110 , V_99 -> V_109 ) ;
for ( V_100 = 0 ; V_100 < F_128 ( V_99 -> V_111 ) ; V_100 ++ )
F_132 ( F_129 ( V_100 ) , V_99 -> V_111 [ V_100 ] ) ;
F_132 ( V_113 , V_99 -> V_112 ) ;
F_132 ( V_115 , V_99 -> V_114 ) ;
F_132 ( V_117 , V_99 -> V_116 ) ;
F_132 ( V_119 , V_99 -> V_118 ) ;
F_132 ( V_121 , V_99 -> V_120 ) ;
F_132 ( V_123 , V_99 -> V_122 ) ;
F_132 ( V_125 , V_99 -> V_124 ) ;
F_132 ( V_127 , V_99 -> V_126 ) ;
F_132 ( V_129 , V_99 -> V_128 ) ;
F_132 ( V_131 , V_99 -> V_130 ) ;
F_132 ( V_133 , V_99 -> V_132 ) ;
F_132 ( V_135 , V_99 -> V_134 ) ;
F_132 ( V_137 , V_99 -> V_136 ) ;
F_132 ( V_139 , V_99 -> V_138 ) ;
F_132 ( V_141 , V_99 -> V_140 ) ;
F_132 ( V_143 , V_99 -> V_142 ) ;
F_132 ( V_145 , V_99 -> V_144 ) ;
F_132 ( V_147 , V_99 -> V_146 ) ;
F_132 ( V_149 , V_99 -> V_148 ) ;
F_132 ( V_151 , V_99 -> V_150 ) ;
F_132 ( V_153 , V_99 -> V_152 ) ;
F_132 ( V_155 , V_99 -> V_154 ) ;
F_132 ( V_157 , V_99 -> V_156 ) ;
F_132 ( V_159 , V_99 -> V_158 ) ;
F_132 ( V_161 , V_99 -> V_160 ) ;
F_132 ( V_163 , V_99 -> V_162 ) ;
F_132 ( V_165 , V_99 -> V_164 ) ;
F_132 ( V_167 , V_99 -> V_166 ) ;
F_132 ( V_169 , V_99 -> V_168 ) ;
F_132 ( V_171 , V_99 -> V_170 ) ;
for ( V_100 = 0 ; V_100 < F_128 ( V_99 -> V_172 ) ; V_100 ++ )
F_132 ( F_130 ( V_100 ) , V_99 -> V_172 [ V_100 ] ) ;
F_132 ( V_174 , V_99 -> V_173 ) ;
F_132 ( V_176 , V_99 -> V_175 ) ;
V_191 = F_127 ( V_178 ) ;
V_191 &= V_192 ;
V_191 |= V_99 -> V_177 & ~ V_192 ;
F_132 ( V_178 , V_191 ) ;
V_191 = F_127 ( V_180 ) ;
V_191 &= V_193 ;
V_191 |= V_99 -> V_179 & ~ V_193 ;
F_132 ( V_180 , V_191 ) ;
F_132 ( V_182 , V_99 -> V_181 ) ;
F_132 ( V_184 , V_99 -> V_183 ) ;
F_132 ( V_186 , V_99 -> V_185 ) ;
F_132 ( V_188 , V_99 -> V_187 ) ;
F_132 ( V_190 , V_99 -> V_189 ) ;
}
int F_133 ( struct V_10 * V_11 , bool V_194 )
{
T_3 V_191 ;
int V_195 ;
#define F_134 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
V_191 = F_127 ( V_180 ) ;
V_191 &= ~ V_193 ;
if ( V_194 )
V_191 |= V_193 ;
F_132 ( V_180 , V_191 ) ;
if ( ! V_194 )
return 0 ;
V_195 = F_135 ( F_134 , 20 ) ;
if ( V_195 )
F_59 ( L_31 ,
F_127 ( V_180 ) ) ;
return V_195 ;
#undef F_134
}
static int F_136 ( struct V_10 * V_11 , bool V_196 )
{
T_3 V_191 ;
int V_195 = 0 ;
V_191 = F_127 ( V_178 ) ;
V_191 &= ~ V_192 ;
if ( V_196 )
V_191 |= V_192 ;
F_132 ( V_178 , V_191 ) ;
F_137 ( V_178 ) ;
#define F_134 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_195 = F_135 ( F_134 , 1 ) ;
if ( V_195 )
F_59 ( L_32 ) ;
return V_195 ;
#undef F_134
}
static int F_138 ( struct V_10 * V_11 ,
bool V_197 )
{
T_3 V_198 ;
T_3 V_191 ;
int V_195 ;
V_198 = V_199 | V_200 ;
V_191 = V_197 ? V_198 : 0 ;
#define F_134 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_134 )
return 0 ;
F_3 ( L_33 ,
F_139 ( V_197 ) ,
F_127 ( V_201 ) ) ;
V_195 = F_135 ( F_134 , 3 ) ;
if ( V_195 )
F_59 ( L_34 ,
F_139 ( V_197 ) ) ;
return V_195 ;
#undef F_134
}
static void F_140 ( struct V_10 * V_11 )
{
if ( ! ( F_127 ( V_201 ) & V_202 ) )
return;
F_106 ( L_35 ) ;
F_132 ( V_201 , V_202 ) ;
}
static int F_58 ( struct V_10 * V_11 )
{
T_3 V_198 ;
int V_195 ;
( void ) F_138 ( V_11 , false ) ;
V_198 = V_203 | V_204 ;
F_13 ( ( F_127 ( V_178 ) & V_198 ) != V_198 ) ;
F_140 ( V_11 ) ;
V_195 = F_133 ( V_11 , true ) ;
if ( V_195 )
goto V_205;
V_195 = F_136 ( V_11 , false ) ;
if ( V_195 )
goto V_206;
if ( ! F_57 ( V_11 ) )
F_126 ( V_11 ) ;
V_195 = F_133 ( V_11 , false ) ;
if ( V_195 )
goto V_206;
return 0 ;
V_206:
F_136 ( V_11 , true ) ;
V_205:
F_133 ( V_11 , false ) ;
return V_195 ;
}
static int F_89 ( struct V_10 * V_11 ,
bool V_207 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
int V_195 ;
int V_4 ;
V_4 = F_133 ( V_11 , true ) ;
if ( ! F_57 ( V_11 ) )
F_131 ( V_11 ) ;
V_195 = F_136 ( V_11 , true ) ;
if ( ! V_4 )
V_4 = V_195 ;
V_195 = F_133 ( V_11 , false ) ;
if ( ! V_4 )
V_4 = V_195 ;
F_140 ( V_11 ) ;
if ( V_207 ) {
F_141 ( V_3 ) ;
F_142 ( V_3 ) ;
}
return V_4 ;
}
static int F_143 ( struct V_21 * V_21 )
{
struct V_13 * V_52 = F_120 ( V_21 ) ;
struct V_2 * V_3 = F_117 ( V_52 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 ;
if ( F_64 ( ! ( V_11 -> V_208 . V_209 && F_144 ( V_3 ) ) ) )
return - V_66 ;
if ( F_64 ( ! F_145 ( V_3 ) ) )
return - V_66 ;
F_3 ( L_36 ) ;
if ( ! F_146 ( & V_3 -> V_73 ) ) {
F_3 ( L_37 ) ;
F_147 ( V_21 ) ;
return - V_210 ;
}
F_30 ( V_11 ) ;
F_148 ( V_11 ) ;
F_29 ( & V_3 -> V_73 ) ;
F_149 ( & V_11 -> V_75 . V_211 ) ;
F_36 ( V_3 ) ;
F_37 ( V_3 ) ;
F_40 ( V_11 ) ;
V_4 = 0 ;
if ( F_52 ( V_11 ) ) {
F_150 ( V_11 ) ;
F_54 ( V_11 ) ;
} else if ( F_6 ( V_11 ) || F_7 ( V_11 ) ) {
F_55 ( V_11 ) ;
} else if ( F_56 ( V_11 ) || F_57 ( V_11 ) ) {
V_4 = F_58 ( V_11 ) ;
}
if ( V_4 ) {
F_59 ( L_38 , V_4 ) ;
F_73 ( V_11 ) ;
F_50 ( V_11 ) ;
return V_4 ;
}
F_46 ( V_3 , false ) ;
F_50 ( V_11 ) ;
F_64 ( F_151 ( & V_11 -> V_212 . V_213 ) ) ;
if ( F_152 ( V_11 ) )
F_59 ( L_39 ) ;
V_11 -> V_212 . V_214 = true ;
if ( F_7 ( V_3 ) ) {
F_45 ( V_3 , V_63 ) ;
} else {
F_45 ( V_3 , V_54 ) ;
}
F_153 ( V_11 ) ;
F_3 ( L_40 ) ;
return 0 ;
}
static int F_154 ( struct V_21 * V_21 )
{
struct V_13 * V_52 = F_120 ( V_21 ) ;
struct V_2 * V_3 = F_117 ( V_52 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
int V_4 = 0 ;
if ( F_64 ( ! F_145 ( V_3 ) ) )
return - V_66 ;
F_3 ( L_41 ) ;
F_64 ( F_151 ( & V_11 -> V_212 . V_213 ) ) ;
F_30 ( V_11 ) ;
F_45 ( V_3 , V_82 ) ;
V_11 -> V_212 . V_214 = false ;
if ( F_155 ( V_11 ) )
F_106 ( L_42 ) ;
F_76 ( V_3 ) ;
if ( F_4 ( V_11 ) )
F_71 ( V_3 ) ;
if ( F_52 ( V_3 ) ) {
F_92 ( V_11 ) ;
F_156 ( V_11 , true ) ;
if ( V_11 -> V_61 . V_62 &&
( V_11 -> V_61 . V_215 & V_216 ) )
F_157 ( V_11 ) ;
} else if ( F_6 ( V_11 ) || F_7 ( V_11 ) ) {
F_93 ( V_11 ) ;
} else if ( F_56 ( V_11 ) || F_57 ( V_11 ) ) {
V_4 = F_89 ( V_11 , true ) ;
}
F_158 ( V_3 ) ;
F_159 ( V_3 ) ;
F_73 ( V_11 ) ;
if ( ! F_56 ( V_11 ) && ! F_57 ( V_11 ) )
F_82 ( V_11 ) ;
F_108 ( V_3 ) ;
F_50 ( V_11 ) ;
if ( V_4 )
F_59 ( L_43 , V_4 ) ;
else
F_3 ( L_44 ) ;
return V_4 ;
}
static int T_4 F_160 ( void )
{
V_97 . V_217 = V_218 ;
if ( V_39 . V_219 == 0 )
V_97 . V_220 &= ~ V_221 ;
if ( F_161 () && V_39 . V_219 == - 1 )
V_97 . V_220 &= ~ V_221 ;
if ( ! ( V_97 . V_220 & V_221 ) ) {
F_106 ( L_45 ) ;
return 0 ;
}
if ( V_39 . V_222 )
V_97 . V_220 |= V_223 ;
return F_162 ( & V_97 , & V_224 ) ;
}
static void T_5 F_163 ( void )
{
if ( ! ( V_97 . V_220 & V_221 ) )
return;
F_164 ( & V_97 , & V_224 ) ;
}
