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
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 ;
F_17 ( V_4 ) ;
F_18 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_34 ;
F_19 ( & V_4 -> V_32 ) ;
F_20 ( V_4 , true ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_35 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
int error ;
error = F_24 ( V_2 ) ;
if ( error ) {
F_25 ( & V_2 -> V_35 -> V_2 ,
L_9 ) ;
return error ;
}
F_26 ( V_2 ) ;
V_4 -> V_37 = false ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 (dev, crtc) {
V_4 -> V_38 . V_39 ( V_31 ) ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
}
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 () ;
F_37 ( V_2 , V_40 ) ;
F_38 () ;
V_4 -> V_41 ++ ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_42 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_40 ( L_10 , V_2 ) ;
F_40 ( L_11 ) ;
return - V_43 ;
}
if ( V_42 . V_44 == V_45 )
return 0 ;
if ( V_2 -> V_46 == V_47 )
return 0 ;
error = F_16 ( V_2 ) ;
if ( error )
return error ;
if ( V_42 . V_44 == V_48 ) {
F_41 ( V_2 -> V_35 ) ;
F_42 ( V_2 -> V_35 , V_49 ) ;
}
return 0 ;
}
void F_43 ( struct V_50 * V_51 )
{
struct V_3 * V_4 =
F_44 ( V_51 , struct V_3 ,
V_52 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_36 () ;
F_37 ( V_2 , V_53 ) ;
F_38 () ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , bool V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_23 ( V_2 , V_36 ) &&
V_54 ) {
F_18 ( & V_2 -> V_55 ) ;
F_50 ( V_2 ) ;
F_19 ( & V_2 -> V_55 ) ;
}
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_18 ( & V_2 -> V_55 ) ;
if ( F_55 ( V_2 ) ) {
F_40 ( L_12 ) ;
F_56 ( V_56 , & V_4 -> V_57 . V_58 ) ;
}
F_19 ( & V_2 -> V_55 ) ;
F_57 ( V_2 , V_2 -> V_35 -> V_59 ) ;
F_58 ( V_2 ) ;
F_28 ( V_2 ) ;
F_59 ( V_2 , true ) ;
F_30 ( V_2 ) ;
F_60 ( V_2 ) ;
V_4 -> V_37 = true ;
F_61 ( V_2 ) ;
}
F_62 ( V_2 ) ;
if ( F_63 () ) {
F_37 ( V_2 , V_53 ) ;
F_38 () ;
} else {
F_64 ( & V_4 -> V_52 ) ;
}
F_18 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_60 ;
F_19 ( & V_4 -> V_32 ) ;
F_65 ( V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_36 ) )
F_67 ( V_2 ) ;
return F_49 ( V_2 , true ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 == V_47 )
return 0 ;
if ( F_69 ( V_2 -> V_35 ) )
return - V_61 ;
F_70 ( V_2 -> V_35 ) ;
return F_45 ( V_2 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_62 ;
V_62 = F_49 ( V_2 , ! V_4 -> V_63 . V_64 ) ;
if ( V_62 )
return V_62 ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_65 ;
int V_62 ;
if ( ! V_27 . V_66 )
return 0 ;
F_18 ( & V_2 -> V_55 ) ;
F_75 ( V_2 ) ;
V_65 = V_4 -> V_57 . V_67 != 0 ;
V_62 = F_76 ( V_2 ) ;
if ( V_65 ) {
F_77 ( L_13 ) ;
V_4 -> V_57 . V_67 = 0 ;
if ( V_62 == - V_43 ) {
F_77 ( L_14
L_15 ) ;
V_62 = 0 ;
}
}
if ( V_62 ) {
F_40 ( L_16 , V_62 ) ;
F_19 ( & V_2 -> V_55 ) ;
return V_62 ;
}
if ( F_23 ( V_2 , V_36 ) ||
! V_4 -> V_68 . V_69 ) {
V_4 -> V_68 . V_69 = 0 ;
V_62 = F_55 ( V_2 ) ;
F_19 ( & V_2 -> V_55 ) ;
if ( V_62 ) {
F_40 ( L_17 , V_62 ) ;
return V_62 ;
}
if ( F_2 ( V_2 ) -> V_26 > 5 )
F_78 ( V_2 ) ;
F_60 ( V_2 ) ;
} else {
F_19 ( & V_2 -> V_55 ) ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_35 , const struct V_70 * V_71 )
{
struct V_72 * V_73 =
(struct V_72 * ) V_71 -> V_74 ;
if ( F_80 ( V_73 ) && ! V_27 . V_75 ) {
F_77 ( L_18
L_19 ) ;
return - V_43 ;
}
if ( F_81 ( V_35 -> V_76 ) )
return - V_43 ;
V_77 . V_78 &= ~ ( V_79 ) ;
return F_82 ( V_35 , V_71 , & V_77 ) ;
}
static void
F_83 ( struct V_6 * V_35 )
{
struct V_1 * V_2 = F_84 ( V_35 ) ;
F_85 ( V_2 ) ;
}
static int F_86 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
if ( ! V_80 || ! V_80 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_43 ;
}
if ( V_80 -> V_46 == V_47 )
return 0 ;
return F_16 ( V_80 ) ;
}
static int F_88 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
if ( V_80 -> V_46 == V_47 )
return 0 ;
F_41 ( V_35 ) ;
F_42 ( V_35 , V_49 ) ;
return 0 ;
}
static int F_89 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
return F_68 ( V_80 ) ;
}
static int F_90 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
return F_71 ( V_80 ) ;
}
static int F_91 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
if ( ! V_80 || ! V_80 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_43 ;
}
return F_16 ( V_80 ) ;
}
static int F_92 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
return F_45 ( V_80 ) ;
}
static int F_93 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
return F_66 ( V_80 ) ;
}
static int F_94 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_80 = F_84 ( V_35 ) ;
return F_16 ( V_80 ) ;
}
static int F_95 ( struct V_3 * V_4 )
{
F_96 ( V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
return 0 ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_81 * V_82 = & V_4 -> V_81 ;
int V_83 ;
V_82 -> V_84 = F_101 ( V_85 ) ;
V_82 -> V_86 = F_101 ( V_87 ) ;
V_82 -> V_88 = F_101 ( V_89 ) ;
V_82 -> V_90 = F_101 ( V_91 ) ;
V_82 -> V_92 = F_101 ( V_93 ) ;
for ( V_83 = 0 ; V_83 < F_102 ( V_82 -> V_94 ) ; V_83 ++ )
V_82 -> V_94 [ V_83 ] = F_101 ( V_95 + V_83 * 4 ) ;
V_82 -> V_96 = F_101 ( V_97 ) ;
V_82 -> V_98 = F_101 ( V_97 ) ;
V_82 -> V_99 = F_101 ( V_100 ) ;
V_82 -> V_101 = F_101 ( V_102 ) ;
V_82 -> V_103 = F_101 ( V_104 ) ;
V_82 -> V_105 = F_101 ( V_106 ) ;
V_82 -> V_107 = F_101 ( V_108 ) ;
V_82 -> V_109 = F_101 ( V_110 ) ;
V_82 -> V_111 = F_101 ( V_112 ) ;
V_82 -> V_113 = F_101 ( V_114 ) ;
V_82 -> V_115 = F_101 ( V_116 ) ;
V_82 -> V_117 = F_101 ( V_118 ) ;
V_82 -> V_119 = F_101 ( V_120 ) ;
V_82 -> V_121 = F_101 ( V_122 ) ;
V_82 -> V_123 = F_101 ( V_124 ) ;
V_82 -> V_125 = F_101 ( V_126 ) ;
V_82 -> V_127 = F_101 ( V_128 ) ;
V_82 -> V_129 = F_101 ( V_130 ) ;
V_82 -> V_131 = F_101 ( V_132 ) ;
V_82 -> V_133 = F_101 ( V_134 ) ;
V_82 -> V_135 = F_101 ( V_136 ) ;
V_82 -> V_137 = F_101 ( V_138 ) ;
V_82 -> V_139 = F_101 ( V_140 ) ;
V_82 -> V_141 = F_101 ( V_142 ) ;
V_82 -> V_143 = F_101 ( V_144 ) ;
V_82 -> V_145 = F_101 ( V_146 ) ;
V_82 -> V_147 = F_101 ( V_148 ) ;
V_82 -> V_149 = F_101 ( V_150 ) ;
V_82 -> V_151 = F_101 ( V_152 ) ;
V_82 -> V_153 = F_101 ( V_154 ) ;
for ( V_83 = 0 ; V_83 < F_102 ( V_82 -> V_155 ) ; V_83 ++ )
V_82 -> V_155 [ V_83 ] = F_101 ( V_156 + V_83 * 4 ) ;
V_82 -> V_157 = F_101 ( V_158 ) ;
V_82 -> V_159 = F_101 ( V_160 ) ;
V_82 -> V_161 = F_101 ( V_162 ) ;
V_82 -> V_163 = F_101 ( V_164 ) ;
V_82 -> V_165 = F_101 ( V_166 ) ;
V_82 -> V_167 = F_101 ( V_168 ) ;
V_82 -> V_169 = F_101 ( V_170 ) ;
V_82 -> V_171 = F_101 ( V_172 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_81 * V_82 = & V_4 -> V_81 ;
T_2 V_173 ;
int V_83 ;
F_104 ( V_85 , V_82 -> V_84 ) ;
F_104 ( V_87 , V_82 -> V_86 ) ;
F_104 ( V_89 , V_82 -> V_88 | ( 0xffff << 16 ) ) ;
F_104 ( V_91 , V_82 -> V_90 ) ;
F_104 ( V_93 , V_82 -> V_92 ) ;
for ( V_83 = 0 ; V_83 < F_102 ( V_82 -> V_94 ) ; V_83 ++ )
F_104 ( V_95 + V_83 * 4 , V_82 -> V_94 [ V_83 ] ) ;
F_104 ( V_97 , V_82 -> V_96 ) ;
F_104 ( V_97 , V_82 -> V_98 ) ;
F_104 ( V_100 , V_82 -> V_99 ) ;
F_104 ( V_102 , V_82 -> V_101 ) ;
F_104 ( V_104 , V_82 -> V_103 ) ;
F_104 ( V_106 , V_82 -> V_105 ) ;
F_104 ( V_108 , V_82 -> V_107 ) ;
F_104 ( V_110 , V_82 -> V_109 ) ;
F_104 ( V_112 , V_82 -> V_111 ) ;
F_104 ( V_114 , V_82 -> V_113 ) ;
F_104 ( V_116 , V_82 -> V_115 ) ;
F_104 ( V_118 , V_82 -> V_117 ) ;
F_104 ( V_120 , V_82 -> V_119 ) ;
F_104 ( V_122 , V_82 -> V_121 ) ;
F_104 ( V_124 , V_82 -> V_123 ) ;
F_104 ( V_126 , V_82 -> V_125 ) ;
F_104 ( V_128 , V_82 -> V_127 ) ;
F_104 ( V_130 , V_82 -> V_129 ) ;
F_104 ( V_132 , V_82 -> V_131 ) ;
F_104 ( V_134 , V_82 -> V_133 ) ;
F_104 ( V_136 , V_82 -> V_135 ) ;
F_104 ( V_138 , V_82 -> V_137 ) ;
F_104 ( V_140 , V_82 -> V_139 ) ;
F_104 ( V_142 , V_82 -> V_141 ) ;
F_104 ( V_144 , V_82 -> V_143 ) ;
F_104 ( V_146 , V_82 -> V_145 ) ;
F_104 ( V_148 , V_82 -> V_147 ) ;
F_104 ( V_150 , V_82 -> V_149 ) ;
F_104 ( V_152 , V_82 -> V_151 ) ;
F_104 ( V_154 , V_82 -> V_153 ) ;
for ( V_83 = 0 ; V_83 < F_102 ( V_82 -> V_155 ) ; V_83 ++ )
F_104 ( V_156 + V_83 * 4 , V_82 -> V_155 [ V_83 ] ) ;
F_104 ( V_158 , V_82 -> V_157 ) ;
F_104 ( V_160 , V_82 -> V_159 ) ;
V_173 = F_101 ( V_162 ) ;
V_173 &= V_174 ;
V_173 |= V_82 -> V_161 & ~ V_174 ;
F_104 ( V_162 , V_173 ) ;
V_173 = F_101 ( V_164 ) ;
V_173 &= V_175 ;
V_173 |= V_82 -> V_163 & ~ V_175 ;
F_104 ( V_164 , V_173 ) ;
F_104 ( V_166 , V_82 -> V_165 ) ;
F_104 ( V_168 , V_82 -> V_167 ) ;
F_104 ( V_170 , V_82 -> V_169 ) ;
F_104 ( V_172 , V_82 -> V_171 ) ;
}
int F_105 ( struct V_3 * V_4 , bool V_176 )
{
T_2 V_173 ;
int V_177 ;
V_173 = F_101 ( V_164 ) ;
F_5 ( ! ! ( V_173 & V_175 ) == V_176 ) ;
#define F_106 (I915_READ(VLV_GTLC_SURVIVABILITY_REG) & VLV_GFX_CLK_STATUS_BIT)
if ( V_176 ) {
V_177 = F_107 ( ! F_106 , 20 ) ;
if ( V_177 ) {
F_40 ( L_20 ,
F_101 ( V_164 ) ) ;
return V_177 ;
}
}
V_173 = F_101 ( V_164 ) ;
V_173 &= ~ V_175 ;
if ( V_176 )
V_173 |= V_175 ;
F_104 ( V_164 , V_173 ) ;
if ( ! V_176 )
return 0 ;
V_177 = F_107 ( F_106 , 20 ) ;
if ( V_177 )
F_40 ( L_21 ,
F_101 ( V_164 ) ) ;
return V_177 ;
#undef F_106
}
static int F_108 ( struct V_3 * V_4 , bool V_178 )
{
T_2 V_173 ;
int V_177 = 0 ;
V_173 = F_101 ( V_162 ) ;
V_173 &= ~ V_174 ;
if ( V_178 )
V_173 |= V_174 ;
F_104 ( V_162 , V_173 ) ;
F_109 ( V_162 ) ;
#define F_106 (!!(I915_READ(VLV_GTLC_PW_STATUS) & VLV_GTLC_ALLOWWAKEACK) == \
allow)
V_177 = F_107 ( F_106 , 1 ) ;
if ( V_177 )
F_40 ( L_22 ) ;
return V_177 ;
#undef F_106
}
static int F_110 ( struct V_3 * V_4 ,
bool V_179 )
{
T_2 V_180 ;
T_2 V_173 ;
int V_177 ;
V_180 = V_181 | V_182 ;
V_173 = V_179 ? V_180 : 0 ;
#define F_106 ((I915_READ(VLV_GTLC_PW_STATUS) & mask) == val)
if ( F_106 )
return 0 ;
F_4 ( L_23 ,
V_179 ? L_24 : L_25 ,
F_101 ( V_183 ) ) ;
V_177 = F_107 ( F_106 , 3 ) ;
if ( V_177 )
F_40 ( L_26 ,
V_179 ? L_24 : L_25 ) ;
return V_177 ;
#undef F_106
}
static void F_111 ( struct V_3 * V_4 )
{
if ( ! ( F_101 ( V_183 ) & V_184 ) )
return;
F_40 ( L_27 ) ;
F_104 ( V_183 , V_184 ) ;
}
static int F_112 ( struct V_3 * V_4 )
{
T_2 V_180 ;
int V_177 ;
( void ) F_110 ( V_4 , false ) ;
V_180 = V_185 | V_186 ;
F_5 ( ( F_101 ( V_162 ) & V_180 ) != V_180 ) ;
F_111 ( V_4 ) ;
V_177 = F_105 ( V_4 , true ) ;
if ( V_177 )
goto V_187;
V_177 = F_108 ( V_4 , false ) ;
if ( V_177 )
goto V_188;
F_100 ( V_4 ) ;
V_177 = F_105 ( V_4 , false ) ;
if ( V_177 )
goto V_188;
return 0 ;
V_188:
F_108 ( V_4 , true ) ;
V_187:
F_105 ( V_4 , false ) ;
return V_177 ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_177 ;
int V_62 ;
V_62 = F_105 ( V_4 , true ) ;
F_103 ( V_4 ) ;
V_177 = F_108 ( V_4 , true ) ;
if ( ! V_62 )
V_62 = V_177 ;
V_177 = F_105 ( V_4 , false ) ;
if ( ! V_62 )
V_62 = V_177 ;
F_111 ( V_4 ) ;
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
return V_62 ;
}
static int F_116 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_87 ( V_15 ) ;
struct V_1 * V_2 = F_84 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_62 ;
if ( F_117 ( ! ( V_4 -> V_189 . V_190 && F_118 ( V_2 ) ) ) )
return - V_43 ;
F_5 ( ! F_119 ( V_2 ) ) ;
F_120 ( V_4 ) ;
F_4 ( L_28 ) ;
if ( ! F_121 ( & V_2 -> V_55 ) ) {
F_4 ( L_29 ) ;
F_122 ( V_15 ) ;
return - V_191 ;
}
F_123 ( V_4 ) ;
F_19 ( & V_2 -> V_55 ) ;
F_124 ( & V_4 -> V_189 . V_51 ) ;
F_125 ( V_2 ) ;
if ( F_7 ( V_2 ) ) {
V_62 = 0 ;
} else if ( F_9 ( V_2 ) || F_11 ( V_2 ) ) {
V_62 = F_95 ( V_4 ) ;
} else if ( F_126 ( V_2 ) ) {
V_62 = F_112 ( V_4 ) ;
} else {
V_62 = - V_43 ;
F_5 ( 1 ) ;
}
if ( V_62 ) {
F_40 ( L_30 , V_62 ) ;
F_127 ( V_2 ) ;
return V_62 ;
}
F_128 ( & V_4 -> V_57 . V_192 ) ;
V_4 -> V_193 . V_194 = true ;
F_129 ( V_2 , V_195 ) ;
F_4 ( L_31 ) ;
return 0 ;
}
static int F_130 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_87 ( V_15 ) ;
struct V_1 * V_2 = F_84 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_62 ;
F_5 ( ! F_119 ( V_2 ) ) ;
F_4 ( L_32 ) ;
F_129 ( V_2 , V_196 ) ;
V_4 -> V_193 . V_194 = false ;
if ( F_7 ( V_2 ) ) {
V_62 = F_97 ( V_4 ) ;
} else if ( F_9 ( V_2 ) || F_11 ( V_2 ) ) {
V_62 = F_98 ( V_4 ) ;
} else if ( F_126 ( V_2 ) ) {
V_62 = F_113 ( V_4 ) ;
} else {
F_5 ( 1 ) ;
V_62 = - V_43 ;
}
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_127 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_62 )
F_40 ( L_33 , V_62 ) ;
else
F_4 ( L_34 ) ;
return V_62 ;
}
static int T_3 F_133 ( void )
{
V_77 . V_197 = V_198 ;
#if F_134 ( V_199 )
if ( V_27 . V_200 != 0 )
V_77 . V_78 |= V_36 ;
#endif
if ( V_27 . V_200 == 1 )
V_77 . V_78 |= V_36 ;
#ifdef F_135
if ( F_136 () && V_27 . V_200 == - 1 )
V_77 . V_78 &= ~ V_36 ;
#endif
if ( ! ( V_77 . V_78 & V_36 ) ) {
V_77 . V_201 = NULL ;
#ifndef F_137
F_138 ( L_35 ) ;
return 0 ;
#endif
}
return F_139 ( & V_77 , & V_202 ) ;
}
static void T_4 F_140 ( void )
{
#ifndef F_137
if ( ! ( V_77 . V_78 & V_36 ) )
return;
#endif
F_141 ( & V_77 , & V_202 ) ;
}
