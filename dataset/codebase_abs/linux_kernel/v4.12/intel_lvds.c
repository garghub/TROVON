static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 . V_4 ) ;
}
static bool F_4 ( struct V_8 * V_3 ,
enum V_9 * V_9 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_15 ;
bool V_16 ;
if ( ! F_6 ( V_13 ,
V_3 -> V_17 ) )
return false ;
V_16 = false ;
V_15 = F_7 ( V_14 -> V_18 ) ;
if ( ! ( V_15 & V_19 ) )
goto V_20;
if ( F_8 ( V_13 ) )
* V_9 = F_9 ( V_15 ) ;
else
* V_9 = F_10 ( V_15 ) ;
V_16 = true ;
V_20:
F_11 ( V_13 , V_3 -> V_17 ) ;
return V_16 ;
}
static void F_12 ( struct V_8 * V_3 ,
struct V_21 * V_22 )
{
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_15 , V_23 = 0 ;
V_15 = F_7 ( V_14 -> V_18 ) ;
if ( V_15 & V_24 )
V_23 |= V_25 ;
else
V_23 |= V_26 ;
if ( V_15 & V_27 )
V_23 |= V_28 ;
else
V_23 |= V_29 ;
V_22 -> V_4 . V_30 . V_23 |= V_23 ;
if ( F_13 ( V_13 ) < 5 )
V_22 -> V_31 . V_32 =
V_15 & V_33 ;
if ( F_13 ( V_13 ) < 4 ) {
V_15 = F_7 ( V_34 ) ;
V_22 -> V_31 . V_35 |= V_15 & V_36 ;
}
V_22 -> V_4 . V_30 . V_37 = V_22 -> V_38 ;
}
static void F_14 ( struct V_12 * V_13 ,
struct V_39 * V_40 )
{
T_1 V_41 ;
V_40 -> V_42 = F_7 ( F_15 ( 0 ) ) & V_43 ;
V_41 = F_7 ( F_16 ( 0 ) ) ;
V_40 -> V_44 = ( V_41 & V_45 ) >>
V_46 ;
V_40 -> V_47 = ( V_41 & V_48 ) >>
V_49 ;
V_40 -> V_50 = ( V_41 & V_51 ) >>
V_52 ;
V_41 = F_7 ( F_17 ( 0 ) ) ;
V_40 -> V_53 = ( V_41 & V_54 ) >>
V_55 ;
V_40 -> V_56 = ( V_41 & V_57 ) >>
V_58 ;
V_41 = F_7 ( F_18 ( 0 ) ) ;
V_40 -> V_59 = ( V_41 & V_60 ) >>
V_61 ;
V_41 = ( V_41 & V_62 ) >>
V_63 ;
if ( V_41 )
V_41 -- ;
V_40 -> V_64 = V_41 * 1000 ;
if ( F_19 ( V_13 ) -> V_65 <= 4 &&
V_40 -> V_47 == 0 && V_40 -> V_50 == 0 && V_40 -> V_53 == 0 && V_40 -> V_56 == 0 ) {
F_20 ( L_1
L_2 ) ;
V_40 -> V_47 = 40 * 10 ;
V_40 -> V_50 = 200 * 10 ;
V_40 -> V_53 = 35 * 10 ;
V_40 -> V_56 = 200 * 10 ;
}
F_21 ( L_3
L_4 ,
V_40 -> V_47 , V_40 -> V_53 , V_40 -> V_64 , V_40 -> V_50 , V_40 -> V_56 ,
V_40 -> V_59 , V_40 -> V_44 , V_40 -> V_42 ) ;
}
static void F_22 ( struct V_12 * V_13 ,
struct V_39 * V_40 )
{
T_1 V_41 ;
V_41 = F_7 ( F_15 ( 0 ) ) ;
F_23 ( ( V_41 & V_66 ) != V_67 ) ;
if ( V_40 -> V_42 )
V_41 |= V_43 ;
F_24 ( F_15 ( 0 ) , V_41 ) ;
F_24 ( F_16 ( 0 ) , ( V_40 -> V_44 << V_46 ) |
( V_40 -> V_47 << V_49 ) |
( V_40 -> V_50 << V_52 ) ) ;
F_24 ( F_17 ( 0 ) , ( V_40 -> V_53 << V_55 ) |
( V_40 -> V_56 << V_58 ) ) ;
V_41 = V_40 -> V_59 << V_61 ;
V_41 |= ( F_25 ( V_40 -> V_64 , 1000 ) + 1 ) <<
V_63 ;
F_24 ( F_18 ( 0 ) , V_41 ) ;
}
static void F_26 ( struct V_8 * V_3 ,
struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
struct V_70 * V_71 = F_27 ( V_22 -> V_4 . V_71 ) ;
const struct V_72 * V_30 = & V_22 -> V_4 . V_30 ;
int V_9 = V_71 -> V_9 ;
T_1 V_73 ;
if ( F_28 ( V_13 ) ) {
F_29 ( V_13 , V_9 ) ;
F_30 ( V_13 ,
V_22 -> V_74 ) ;
} else {
F_31 ( V_13 , V_9 ) ;
}
F_22 ( V_13 , & V_14 -> V_75 ) ;
V_73 = V_14 -> V_76 ;
V_73 |= V_19 | V_77 ;
if ( F_8 ( V_13 ) ) {
V_73 &= ~ V_78 ;
V_73 |= F_32 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_73 |= V_79 ;
} else {
V_73 &= ~ V_79 ;
}
}
V_73 &= ~ V_33 ;
V_73 |= V_22 -> V_31 . V_32 ;
if ( V_14 -> V_80 )
V_73 |= V_81 | V_82 ;
else
V_73 &= ~ ( V_81 | V_82 ) ;
V_73 &= ~ V_83 ;
V_73 |= V_14 -> V_84 ;
if ( F_33 ( V_13 ) ) {
if ( V_22 -> V_85 && V_22 -> V_86 == 18 )
V_73 |= V_87 ;
else
V_73 &= ~ V_87 ;
}
V_73 &= ~ ( V_24 | V_27 ) ;
if ( V_30 -> V_23 & V_25 )
V_73 |= V_24 ;
if ( V_30 -> V_23 & V_28 )
V_73 |= V_27 ;
F_24 ( V_14 -> V_18 , V_73 ) ;
}
static void F_34 ( struct V_8 * V_3 ,
struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_88 * V_88 =
& V_14 -> V_89 -> V_4 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_24 ( V_14 -> V_18 , F_7 ( V_14 -> V_18 ) | V_19 ) ;
F_24 ( F_15 ( 0 ) , F_7 ( F_15 ( 0 ) ) | V_90 ) ;
F_35 ( V_14 -> V_18 ) ;
if ( F_36 ( V_13 , F_37 ( 0 ) , V_91 , V_91 , 1000 ) )
F_38 ( L_5 ) ;
F_39 ( V_88 ) ;
}
static void F_40 ( struct V_8 * V_3 ,
struct V_21 * V_92 ,
struct V_68 * V_93 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
F_24 ( F_15 ( 0 ) , F_7 ( F_15 ( 0 ) ) & ~ V_90 ) ;
if ( F_36 ( V_13 , F_37 ( 0 ) , V_91 , 0 , 1000 ) )
F_38 ( L_6 ) ;
F_24 ( V_14 -> V_18 , F_7 ( V_14 -> V_18 ) & ~ V_19 ) ;
F_35 ( V_14 -> V_18 ) ;
}
static void F_41 ( struct V_8 * V_3 ,
struct V_21 * V_92 ,
struct V_68 * V_93 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_88 * V_88 =
& V_14 -> V_89 -> V_4 ;
F_42 ( V_88 ) ;
F_40 ( V_3 , V_92 , V_93 ) ;
}
static void F_43 ( struct V_8 * V_3 ,
struct V_21 * V_92 ,
struct V_68 * V_93 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_88 * V_88 =
& V_14 -> V_89 -> V_4 ;
F_42 ( V_88 ) ;
}
static void F_44 ( struct V_8 * V_3 ,
struct V_21 * V_92 ,
struct V_68 * V_93 )
{
F_40 ( V_3 , V_92 , V_93 ) ;
}
static enum V_94
F_45 ( struct V_6 * V_7 ,
struct V_72 * V_95 )
{
struct V_88 * V_88 = F_46 ( V_7 ) ;
struct V_72 * V_96 = V_88 -> V_97 . V_96 ;
int V_98 = F_5 ( V_7 -> V_11 ) -> V_99 ;
if ( V_95 -> V_100 > V_96 -> V_100 )
return V_101 ;
if ( V_95 -> V_102 > V_96 -> V_102 )
return V_101 ;
if ( V_96 -> clock > V_98 )
return V_103 ;
return V_104 ;
}
static bool F_47 ( struct V_8 * V_8 ,
struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_12 * V_13 = F_5 ( V_8 -> V_4 . V_11 ) ;
struct V_1 * V_14 =
F_1 ( & V_8 -> V_4 ) ;
struct V_88 * V_88 =
& V_14 -> V_89 -> V_4 ;
struct V_72 * V_30 = & V_22 -> V_4 . V_30 ;
struct V_70 * V_70 = F_27 ( V_22 -> V_4 . V_71 ) ;
unsigned int V_105 ;
if ( F_13 ( V_13 ) < 4 && V_70 -> V_9 == 0 ) {
F_38 ( L_7 ) ;
return false ;
}
if ( V_14 -> V_84 == V_106 )
V_105 = 8 * 3 ;
else
V_105 = 6 * 3 ;
if ( V_105 != V_22 -> V_86 && ! V_22 -> V_107 ) {
F_20 ( L_8 ,
V_22 -> V_86 , V_105 ) ;
V_22 -> V_86 = V_105 ;
}
F_48 ( V_88 -> V_97 . V_96 ,
V_30 ) ;
if ( F_28 ( V_13 ) ) {
V_22 -> V_108 = true ;
F_49 ( V_70 , V_22 ,
V_88 -> V_97 . V_109 ) ;
} else {
F_50 ( V_70 , V_22 ,
V_88 -> V_97 . V_109 ) ;
}
return true ;
}
static enum V_110
F_51 ( struct V_6 * V_7 , bool V_111 )
{
struct V_12 * V_13 = F_5 ( V_7 -> V_11 ) ;
enum V_110 V_112 ;
F_20 ( L_9 ,
V_7 -> V_4 . V_113 , V_7 -> V_114 ) ;
V_112 = F_52 ( V_13 ) ;
if ( V_112 != V_115 )
return V_112 ;
return V_116 ;
}
static int F_53 ( struct V_6 * V_7 )
{
struct V_5 * V_117 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_72 * V_95 ;
if ( ! F_54 ( V_117 -> V_4 . V_118 ) )
return F_55 ( V_7 , V_117 -> V_4 . V_118 ) ;
V_95 = F_56 ( V_11 , V_117 -> V_4 . V_97 . V_96 ) ;
if ( V_95 == NULL )
return 0 ;
F_57 ( V_7 , V_95 ) ;
return 1 ;
}
static int F_58 ( const struct V_119 * V_113 )
{
F_59 ( L_10 , V_113 -> V_120 ) ;
return 1 ;
}
static int F_60 ( struct V_121 * V_122 , unsigned long V_41 ,
void * V_123 )
{
struct V_5 * V_117 =
F_2 ( V_122 , struct V_5 , V_124 ) ;
struct V_6 * V_7 = & V_117 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_11 -> V_125 != V_126 )
return V_127 ;
F_61 ( & V_13 -> V_128 ) ;
if ( V_13 -> V_129 == V_130 )
goto exit;
V_7 -> V_112 = V_7 -> V_131 -> V_132 ( V_7 , false ) ;
if ( F_62 ( V_133 ) )
goto exit;
if ( ! F_63 () ) {
V_13 -> V_129 = V_134 ;
goto exit;
}
if ( V_13 -> V_129 == V_135 )
goto exit;
if ( ! F_28 ( V_13 ) )
F_64 ( V_11 ) ;
V_13 -> V_129 = V_135 ;
exit:
F_65 ( & V_13 -> V_128 ) ;
return V_127 ;
}
static void F_66 ( struct V_6 * V_7 )
{
struct V_5 * V_117 =
F_3 ( V_7 ) ;
if ( V_117 -> V_124 . V_136 )
F_67 ( & V_117 -> V_124 ) ;
if ( ! F_54 ( V_117 -> V_4 . V_118 ) )
F_68 ( V_117 -> V_4 . V_118 ) ;
F_69 ( & V_117 -> V_4 . V_97 ) ;
F_70 ( V_7 ) ;
F_68 ( V_7 ) ;
}
static int F_71 ( struct V_6 * V_7 ,
struct V_137 * V_138 ,
T_2 V_139 )
{
struct V_88 * V_88 = F_46 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_138 == V_11 -> V_140 . V_141 ) {
struct V_142 * V_71 ;
if ( V_139 == V_143 ) {
F_20 ( L_11 ) ;
return - V_144 ;
}
if ( V_88 -> V_97 . V_109 == V_139 ) {
return 0 ;
}
V_88 -> V_97 . V_109 = V_139 ;
V_71 = F_72 ( V_7 ) -> V_4 . V_71 ;
if ( V_71 && V_71 -> V_145 -> V_146 ) {
F_73 ( V_71 ) ;
}
}
return 0 ;
}
static int F_74 ( const struct V_119 * V_113 )
{
F_59 ( L_12 , V_113 -> V_120 ) ;
return 1 ;
}
static int F_75 ( const struct V_119 * V_113 )
{
F_59 ( L_13 , V_113 -> V_120 ) ;
return 1 ;
}
struct V_8 * F_76 ( struct V_10 * V_11 )
{
struct V_8 * V_8 ;
F_77 (dev, intel_encoder)
if ( V_8 -> type == V_147 )
return V_8 ;
return NULL ;
}
bool F_78 ( struct V_10 * V_11 )
{
struct V_8 * V_3 = F_76 ( V_11 ) ;
return V_3 && F_1 ( & V_3 -> V_4 ) -> V_80 ;
}
static bool F_79 ( struct V_1 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_4 . V_4 . V_11 ;
unsigned int V_41 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_148 . V_149 > 0 )
return V_148 . V_149 == 2 ;
if ( V_14 -> V_89 -> V_4 . V_97 . V_96 -> clock
> 112999 )
return true ;
if ( F_62 ( V_150 ) )
return true ;
V_41 = F_7 ( V_14 -> V_18 ) ;
if ( ! ( V_41 & ~ ( V_151 | V_152 ) ) )
V_41 = V_13 -> V_153 . V_154 ;
return ( V_41 & V_155 ) == V_82 ;
}
static bool F_80 ( struct V_12 * V_13 )
{
if ( F_81 ( V_13 ) || F_8 ( V_13 ) )
return true ;
if ( F_13 ( V_13 ) <= 4 &&
F_82 ( V_13 ) && ! F_83 ( V_13 ) )
return true ;
return false ;
}
void F_84 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = & V_13 -> V_156 ;
struct V_1 * V_14 ;
struct V_8 * V_8 ;
struct V_5 * V_117 ;
struct V_88 * V_88 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_72 * V_157 ;
struct V_72 * V_96 = NULL ;
struct V_72 * V_158 = NULL ;
struct V_118 * V_118 ;
struct V_70 * V_71 ;
T_3 V_159 ;
T_1 V_160 ;
int V_9 ;
T_4 V_161 ;
if ( ! F_80 ( V_13 ) )
return;
if ( F_62 ( V_162 ) )
return;
if ( F_28 ( V_13 ) )
V_159 = V_163 ;
else
V_159 = V_164 ;
V_160 = F_7 ( V_159 ) ;
if ( F_28 ( V_13 ) ) {
if ( ( V_160 & V_152 ) == 0 )
return;
if ( V_13 -> V_153 . V_165 . V_166 ) {
F_20 ( L_14 ) ;
return;
}
}
V_161 = V_167 ;
if ( ! F_85 ( V_13 , & V_161 ) ) {
if ( ( V_160 & V_19 ) == 0 ) {
F_20 ( L_15 ) ;
return;
}
F_20 ( L_16 ) ;
}
V_14 = F_86 ( sizeof( * V_14 ) , V_168 ) ;
if ( ! V_14 )
return;
V_117 = F_86 ( sizeof( * V_117 ) , V_168 ) ;
if ( ! V_117 ) {
F_68 ( V_14 ) ;
return;
}
if ( F_87 ( & V_117 -> V_4 ) < 0 ) {
F_68 ( V_117 ) ;
F_68 ( V_14 ) ;
return;
}
V_14 -> V_89 = V_117 ;
V_8 = & V_14 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_88 = & V_117 -> V_4 ;
V_7 = & V_88 -> V_4 ;
F_88 ( V_11 , & V_88 -> V_4 , & V_169 ,
V_170 ) ;
F_89 ( V_11 , & V_8 -> V_4 , & V_171 ,
V_172 , L_17 ) ;
V_8 -> V_146 = F_34 ;
V_8 -> V_173 = F_26 ;
V_8 -> V_174 = F_47 ;
if ( F_28 ( V_13 ) ) {
V_8 -> V_175 = F_43 ;
V_8 -> V_176 = F_44 ;
} else {
V_8 -> V_175 = F_41 ;
}
V_8 -> V_177 = F_4 ;
V_8 -> V_178 = F_12 ;
V_88 -> V_177 = V_179 ;
F_90 ( V_88 , V_8 ) ;
V_8 -> type = V_147 ;
V_8 -> V_17 = V_180 ;
V_8 -> V_44 = V_181 ;
V_8 -> V_182 = 0 ;
if ( F_28 ( V_13 ) )
V_8 -> V_183 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_33 ( V_13 ) )
V_8 -> V_183 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_183 = ( 1 << 1 ) ;
F_91 ( V_7 , & V_184 ) ;
V_7 -> V_185 . V_186 = V_187 ;
V_7 -> V_188 = false ;
V_7 -> V_189 = false ;
V_14 -> V_18 = V_159 ;
F_92 ( V_11 ) ;
F_93 ( & V_7 -> V_4 ,
V_11 -> V_140 . V_141 ,
V_190 ) ;
V_88 -> V_97 . V_109 = V_190 ;
F_14 ( V_13 , & V_14 -> V_75 ) ;
V_14 -> V_76 = V_160 ;
F_61 ( & V_11 -> V_140 . V_191 ) ;
if ( F_94 () & V_192 )
V_118 = F_95 ( V_7 ,
F_96 ( V_13 , V_161 ) ) ;
else
V_118 = F_97 ( V_7 ,
F_96 ( V_13 , V_161 ) ) ;
if ( V_118 ) {
if ( F_55 ( V_7 , V_118 ) ) {
F_98 ( V_7 ,
V_118 ) ;
} else {
F_68 ( V_118 ) ;
V_118 = F_99 ( - V_144 ) ;
}
} else {
V_118 = F_99 ( - V_193 ) ;
}
V_117 -> V_4 . V_118 = V_118 ;
F_100 (scan, &connector->probed_modes, head) {
if ( V_157 -> type & V_194 ) {
F_20 ( L_18 ) ;
F_101 ( V_157 ) ;
V_96 = F_56 ( V_11 , V_157 ) ;
if ( V_96 )
goto V_20;
}
}
if ( V_13 -> V_153 . V_195 ) {
F_20 ( L_19 ) ;
F_101 ( V_13 -> V_153 . V_195 ) ;
V_96 = F_56 ( V_11 , V_13 -> V_153 . V_195 ) ;
if ( V_96 ) {
V_96 -> type |= V_194 ;
V_7 -> V_185 . V_196 = V_96 -> V_196 ;
V_7 -> V_185 . V_197 = V_96 -> V_197 ;
goto V_20;
}
}
if ( F_28 ( V_13 ) )
goto V_198;
V_9 = ( V_160 & V_79 ) ? 1 : 0 ;
V_71 = F_102 ( V_13 , V_9 ) ;
if ( V_71 && ( V_160 & V_19 ) ) {
V_96 = F_103 ( V_11 , & V_71 -> V_4 ) ;
if ( V_96 ) {
F_20 ( L_20 ) ;
F_101 ( V_96 ) ;
V_96 -> type |= V_194 ;
goto V_20;
}
}
if ( ! V_96 )
goto V_198;
V_20:
F_65 ( & V_11 -> V_140 . V_191 ) ;
F_104 ( & V_88 -> V_97 , V_96 , V_158 ) ;
F_105 ( V_7 , V_199 ) ;
V_14 -> V_80 = F_79 ( V_14 ) ;
F_20 ( L_21 ,
V_14 -> V_80 ? L_22 : L_23 ) ;
V_14 -> V_84 = V_160 & V_83 ;
V_117 -> V_124 . V_136 = F_60 ;
if ( F_106 ( & V_117 -> V_124 ) ) {
F_20 ( L_24 ) ;
V_117 -> V_124 . V_136 = NULL ;
}
return;
V_198:
F_65 ( & V_11 -> V_140 . V_191 ) ;
F_20 ( L_25 ) ;
F_70 ( V_7 ) ;
F_107 ( V_3 ) ;
F_68 ( V_14 ) ;
F_68 ( V_117 ) ;
return;
}
