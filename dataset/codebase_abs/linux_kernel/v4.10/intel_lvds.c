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
enum V_15 V_16 ;
T_1 V_17 ;
bool V_18 ;
V_16 = F_6 ( V_3 ) ;
if ( ! F_7 ( V_13 , V_16 ) )
return false ;
V_18 = false ;
V_17 = F_8 ( V_14 -> V_19 ) ;
if ( ! ( V_17 & V_20 ) )
goto V_21;
if ( F_9 ( V_13 ) )
* V_9 = F_10 ( V_17 ) ;
else
* V_9 = F_11 ( V_17 ) ;
V_18 = true ;
V_21:
F_12 ( V_13 , V_16 ) ;
return V_18 ;
}
static void F_13 ( struct V_8 * V_3 ,
struct V_22 * V_23 )
{
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_17 , V_24 = 0 ;
V_17 = F_8 ( V_14 -> V_19 ) ;
if ( V_17 & V_25 )
V_24 |= V_26 ;
else
V_24 |= V_27 ;
if ( V_17 & V_28 )
V_24 |= V_29 ;
else
V_24 |= V_30 ;
V_23 -> V_4 . V_31 . V_24 |= V_24 ;
if ( F_14 ( V_13 ) < 5 )
V_23 -> V_32 . V_33 =
V_17 & V_34 ;
if ( F_14 ( V_13 ) < 4 ) {
V_17 = F_8 ( V_35 ) ;
V_23 -> V_32 . V_36 |= V_17 & V_37 ;
}
V_23 -> V_4 . V_31 . V_38 = V_23 -> V_39 ;
}
static void F_15 ( struct V_12 * V_13 ,
struct V_40 * V_41 )
{
T_1 V_42 ;
V_41 -> V_43 = F_8 ( F_16 ( 0 ) ) & V_44 ;
V_42 = F_8 ( F_17 ( 0 ) ) ;
V_41 -> V_45 = ( V_42 & V_46 ) >>
V_47 ;
V_41 -> V_48 = ( V_42 & V_49 ) >>
V_50 ;
V_41 -> V_51 = ( V_42 & V_52 ) >>
V_53 ;
V_42 = F_8 ( F_18 ( 0 ) ) ;
V_41 -> V_54 = ( V_42 & V_55 ) >>
V_56 ;
V_41 -> V_57 = ( V_42 & V_58 ) >>
V_59 ;
V_42 = F_8 ( F_19 ( 0 ) ) ;
V_41 -> V_60 = ( V_42 & V_61 ) >>
V_62 ;
V_42 = ( V_42 & V_63 ) >>
V_64 ;
if ( V_42 )
V_42 -- ;
V_41 -> V_65 = V_42 * 1000 ;
if ( F_20 ( V_13 ) -> V_66 <= 4 &&
V_41 -> V_48 == 0 && V_41 -> V_51 == 0 && V_41 -> V_54 == 0 && V_41 -> V_57 == 0 ) {
F_21 ( L_1
L_2 ) ;
V_41 -> V_48 = 40 * 10 ;
V_41 -> V_51 = 200 * 10 ;
V_41 -> V_54 = 35 * 10 ;
V_41 -> V_57 = 200 * 10 ;
}
F_22 ( L_3
L_4 ,
V_41 -> V_48 , V_41 -> V_54 , V_41 -> V_65 , V_41 -> V_51 , V_41 -> V_57 ,
V_41 -> V_60 , V_41 -> V_45 , V_41 -> V_43 ) ;
}
static void F_23 ( struct V_12 * V_13 ,
struct V_40 * V_41 )
{
T_1 V_42 ;
V_42 = F_8 ( F_16 ( 0 ) ) ;
F_24 ( ( V_42 & V_67 ) != V_68 ) ;
if ( V_41 -> V_43 )
V_42 |= V_44 ;
F_25 ( F_16 ( 0 ) , V_42 ) ;
F_25 ( F_17 ( 0 ) , ( V_41 -> V_45 << V_47 ) |
( V_41 -> V_48 << V_50 ) |
( V_41 -> V_51 << V_53 ) ) ;
F_25 ( F_18 ( 0 ) , ( V_41 -> V_54 << V_56 ) |
( V_41 -> V_57 << V_59 ) ) ;
V_42 = V_41 -> V_60 << V_62 ;
V_42 |= ( F_26 ( V_41 -> V_65 , 1000 ) + 1 ) <<
V_64 ;
F_25 ( F_19 ( 0 ) , V_42 ) ;
}
static void F_27 ( struct V_8 * V_3 ,
struct V_22 * V_23 ,
struct V_69 * V_70 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
struct V_71 * V_72 = F_28 ( V_23 -> V_4 . V_72 ) ;
const struct V_73 * V_31 = & V_23 -> V_4 . V_31 ;
int V_9 = V_72 -> V_9 ;
T_1 V_74 ;
if ( F_29 ( V_13 ) ) {
F_30 ( V_13 , V_9 ) ;
F_31 ( V_13 ,
V_23 -> V_75 ) ;
} else {
F_32 ( V_13 , V_9 ) ;
}
F_23 ( V_13 , & V_14 -> V_76 ) ;
V_74 = V_14 -> V_77 ;
V_74 |= V_20 | V_78 ;
if ( F_9 ( V_13 ) ) {
V_74 &= ~ V_79 ;
V_74 |= F_33 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_74 |= V_80 ;
} else {
V_74 &= ~ V_80 ;
}
}
V_74 &= ~ V_34 ;
V_74 |= V_23 -> V_32 . V_33 ;
if ( V_14 -> V_81 )
V_74 |= V_82 | V_83 ;
else
V_74 &= ~ ( V_82 | V_83 ) ;
V_74 &= ~ V_84 ;
V_74 |= V_14 -> V_85 ;
if ( F_34 ( V_13 ) ) {
if ( V_23 -> V_86 && V_23 -> V_87 == 18 )
V_74 |= V_88 ;
else
V_74 &= ~ V_88 ;
}
V_74 &= ~ ( V_25 | V_28 ) ;
if ( V_31 -> V_24 & V_26 )
V_74 |= V_25 ;
if ( V_31 -> V_24 & V_29 )
V_74 |= V_28 ;
F_25 ( V_14 -> V_19 , V_74 ) ;
}
static void F_35 ( struct V_8 * V_3 ,
struct V_22 * V_23 ,
struct V_69 * V_70 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_89 * V_89 =
& V_14 -> V_90 -> V_4 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_25 ( V_14 -> V_19 , F_8 ( V_14 -> V_19 ) | V_20 ) ;
F_25 ( F_16 ( 0 ) , F_8 ( F_16 ( 0 ) ) | V_91 ) ;
F_36 ( V_14 -> V_19 ) ;
if ( F_37 ( V_13 , F_38 ( 0 ) , V_92 , V_92 , 1000 ) )
F_39 ( L_5 ) ;
F_40 ( V_89 ) ;
}
static void F_41 ( struct V_8 * V_3 ,
struct V_22 * V_93 ,
struct V_69 * V_94 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = F_5 ( V_3 -> V_4 . V_11 ) ;
F_25 ( F_16 ( 0 ) , F_8 ( F_16 ( 0 ) ) & ~ V_91 ) ;
if ( F_37 ( V_13 , F_38 ( 0 ) , V_92 , 0 , 1000 ) )
F_39 ( L_6 ) ;
F_25 ( V_14 -> V_19 , F_8 ( V_14 -> V_19 ) & ~ V_20 ) ;
F_36 ( V_14 -> V_19 ) ;
}
static void F_42 ( struct V_8 * V_3 ,
struct V_22 * V_93 ,
struct V_69 * V_94 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_89 * V_89 =
& V_14 -> V_90 -> V_4 ;
F_43 ( V_89 ) ;
F_41 ( V_3 , V_93 , V_94 ) ;
}
static void F_44 ( struct V_8 * V_3 ,
struct V_22 * V_93 ,
struct V_69 * V_94 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_89 * V_89 =
& V_14 -> V_90 -> V_4 ;
F_43 ( V_89 ) ;
}
static void F_45 ( struct V_8 * V_3 ,
struct V_22 * V_93 ,
struct V_69 * V_94 )
{
F_41 ( V_3 , V_93 , V_94 ) ;
}
static enum V_95
F_46 ( struct V_6 * V_7 ,
struct V_73 * V_96 )
{
struct V_89 * V_89 = F_47 ( V_7 ) ;
struct V_73 * V_97 = V_89 -> V_98 . V_97 ;
int V_99 = F_5 ( V_7 -> V_11 ) -> V_100 ;
if ( V_96 -> V_101 > V_97 -> V_101 )
return V_102 ;
if ( V_96 -> V_103 > V_97 -> V_103 )
return V_102 ;
if ( V_97 -> clock > V_99 )
return V_104 ;
return V_105 ;
}
static bool F_48 ( struct V_8 * V_8 ,
struct V_22 * V_23 ,
struct V_69 * V_70 )
{
struct V_12 * V_13 = F_5 ( V_8 -> V_4 . V_11 ) ;
struct V_1 * V_14 =
F_1 ( & V_8 -> V_4 ) ;
struct V_89 * V_89 =
& V_14 -> V_90 -> V_4 ;
struct V_73 * V_31 = & V_23 -> V_4 . V_31 ;
struct V_71 * V_71 = F_28 ( V_23 -> V_4 . V_72 ) ;
unsigned int V_106 ;
if ( F_14 ( V_13 ) < 4 && V_71 -> V_9 == 0 ) {
F_39 ( L_7 ) ;
return false ;
}
if ( V_14 -> V_85 == V_107 )
V_106 = 8 * 3 ;
else
V_106 = 6 * 3 ;
if ( V_106 != V_23 -> V_87 && ! V_23 -> V_108 ) {
F_21 ( L_8 ,
V_23 -> V_87 , V_106 ) ;
V_23 -> V_87 = V_106 ;
}
F_49 ( V_89 -> V_98 . V_97 ,
V_31 ) ;
if ( F_29 ( V_13 ) ) {
V_23 -> V_109 = true ;
F_50 ( V_71 , V_23 ,
V_89 -> V_98 . V_110 ) ;
} else {
F_51 ( V_71 , V_23 ,
V_89 -> V_98 . V_110 ) ;
}
return true ;
}
static enum V_111
F_52 ( struct V_6 * V_7 , bool V_112 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_111 V_113 ;
F_21 ( L_9 ,
V_7 -> V_4 . V_114 , V_7 -> V_115 ) ;
V_113 = F_53 ( V_11 ) ;
if ( V_113 != V_116 )
return V_113 ;
return V_117 ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_5 * V_118 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_73 * V_96 ;
if ( ! F_55 ( V_118 -> V_4 . V_119 ) )
return F_56 ( V_7 , V_118 -> V_4 . V_119 ) ;
V_96 = F_57 ( V_11 , V_118 -> V_4 . V_98 . V_97 ) ;
if ( V_96 == NULL )
return 0 ;
F_58 ( V_7 , V_96 ) ;
return 1 ;
}
static int F_59 ( const struct V_120 * V_114 )
{
F_60 ( L_10 , V_114 -> V_121 ) ;
return 1 ;
}
static int F_61 ( struct V_122 * V_123 , unsigned long V_42 ,
void * V_124 )
{
struct V_5 * V_118 =
F_2 ( V_123 , struct V_5 , V_125 ) ;
struct V_6 * V_7 = & V_118 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_11 -> V_126 != V_127 )
return V_128 ;
F_62 ( & V_13 -> V_129 ) ;
if ( V_13 -> V_130 == V_131 )
goto exit;
V_7 -> V_113 = V_7 -> V_132 -> V_133 ( V_7 , false ) ;
if ( F_63 ( V_134 ) )
goto exit;
if ( ! F_64 () ) {
V_13 -> V_130 = V_135 ;
goto exit;
}
if ( V_13 -> V_130 == V_136 )
goto exit;
if ( ! F_29 ( V_13 ) )
F_65 ( V_11 ) ;
V_13 -> V_130 = V_136 ;
exit:
F_66 ( & V_13 -> V_129 ) ;
return V_128 ;
}
static void F_67 ( struct V_6 * V_7 )
{
struct V_5 * V_118 =
F_3 ( V_7 ) ;
if ( V_118 -> V_125 . V_137 )
F_68 ( & V_118 -> V_125 ) ;
if ( ! F_55 ( V_118 -> V_4 . V_119 ) )
F_69 ( V_118 -> V_4 . V_119 ) ;
F_70 ( & V_118 -> V_4 . V_98 ) ;
F_71 ( V_7 ) ;
F_69 ( V_7 ) ;
}
static int F_72 ( struct V_6 * V_7 ,
struct V_138 * V_139 ,
T_2 V_140 )
{
struct V_89 * V_89 = F_47 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_139 == V_11 -> V_141 . V_142 ) {
struct V_143 * V_72 ;
if ( V_140 == V_144 ) {
F_21 ( L_11 ) ;
return - V_145 ;
}
if ( V_89 -> V_98 . V_110 == V_140 ) {
return 0 ;
}
V_89 -> V_98 . V_110 = V_140 ;
V_72 = F_73 ( V_7 ) -> V_4 . V_72 ;
if ( V_72 && V_72 -> V_146 -> V_147 ) {
F_74 ( V_72 ) ;
}
}
return 0 ;
}
static int F_75 ( const struct V_120 * V_114 )
{
F_60 ( L_12 , V_114 -> V_121 ) ;
return 1 ;
}
static int F_76 ( const struct V_120 * V_114 )
{
F_60 ( L_13 , V_114 -> V_121 ) ;
return 1 ;
}
struct V_8 * F_77 ( struct V_10 * V_11 )
{
struct V_8 * V_8 ;
F_78 (dev, intel_encoder)
if ( V_8 -> type == V_148 )
return V_8 ;
return NULL ;
}
bool F_79 ( struct V_10 * V_11 )
{
struct V_8 * V_3 = F_77 ( V_11 ) ;
return V_3 && F_1 ( & V_3 -> V_4 ) -> V_81 ;
}
static bool F_80 ( struct V_1 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_4 . V_4 . V_11 ;
unsigned int V_42 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_149 . V_150 > 0 )
return V_149 . V_150 == 2 ;
if ( V_14 -> V_90 -> V_4 . V_98 . V_97 -> clock
> 112999 )
return true ;
if ( F_63 ( V_151 ) )
return true ;
V_42 = F_8 ( V_14 -> V_19 ) ;
if ( ! ( V_42 & ~ ( V_152 | V_153 ) ) )
V_42 = V_13 -> V_154 . V_155 ;
return ( V_42 & V_156 ) == V_83 ;
}
static bool F_81 ( struct V_12 * V_13 )
{
if ( F_82 ( V_13 ) || F_9 ( V_13 ) )
return true ;
if ( F_14 ( V_13 ) <= 4 &&
F_83 ( V_13 ) && ! F_84 ( V_13 ) )
return true ;
return false ;
}
void F_85 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_1 * V_14 ;
struct V_8 * V_8 ;
struct V_5 * V_118 ;
struct V_89 * V_89 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_73 * V_157 ;
struct V_73 * V_97 = NULL ;
struct V_73 * V_158 = NULL ;
struct V_119 * V_119 ;
struct V_71 * V_72 ;
T_3 V_159 ;
T_1 V_160 ;
int V_9 ;
T_4 V_161 ;
if ( ! F_81 ( V_13 ) )
return;
if ( F_63 ( V_162 ) )
return;
if ( F_29 ( V_13 ) )
V_159 = V_163 ;
else
V_159 = V_164 ;
V_160 = F_8 ( V_159 ) ;
if ( F_29 ( V_13 ) ) {
if ( ( V_160 & V_153 ) == 0 )
return;
if ( V_13 -> V_154 . V_165 . V_166 ) {
F_21 ( L_14 ) ;
return;
}
}
V_161 = V_167 ;
if ( ! F_86 ( V_13 , & V_161 ) ) {
if ( ( V_160 & V_20 ) == 0 ) {
F_21 ( L_15 ) ;
return;
}
F_21 ( L_16 ) ;
}
V_14 = F_87 ( sizeof( * V_14 ) , V_168 ) ;
if ( ! V_14 )
return;
V_118 = F_87 ( sizeof( * V_118 ) , V_168 ) ;
if ( ! V_118 ) {
F_69 ( V_14 ) ;
return;
}
if ( F_88 ( & V_118 -> V_4 ) < 0 ) {
F_69 ( V_118 ) ;
F_69 ( V_14 ) ;
return;
}
V_14 -> V_90 = V_118 ;
V_8 = & V_14 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_89 = & V_118 -> V_4 ;
V_7 = & V_89 -> V_4 ;
F_89 ( V_11 , & V_89 -> V_4 , & V_169 ,
V_170 ) ;
F_90 ( V_11 , & V_8 -> V_4 , & V_171 ,
V_172 , L_17 ) ;
V_8 -> V_147 = F_35 ;
V_8 -> V_173 = F_27 ;
V_8 -> V_174 = F_48 ;
if ( F_29 ( V_13 ) ) {
V_8 -> V_175 = F_44 ;
V_8 -> V_176 = F_45 ;
} else {
V_8 -> V_175 = F_42 ;
}
V_8 -> V_177 = F_4 ;
V_8 -> V_178 = F_13 ;
V_89 -> V_177 = V_179 ;
F_91 ( V_89 , V_8 ) ;
V_8 -> type = V_148 ;
V_8 -> V_45 = V_180 ;
V_8 -> V_181 = 0 ;
if ( F_29 ( V_13 ) )
V_8 -> V_182 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_34 ( V_13 ) )
V_8 -> V_182 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_182 = ( 1 << 1 ) ;
F_92 ( V_7 , & V_183 ) ;
V_7 -> V_184 . V_185 = V_186 ;
V_7 -> V_187 = false ;
V_7 -> V_188 = false ;
V_14 -> V_19 = V_159 ;
F_93 ( V_11 ) ;
F_94 ( & V_7 -> V_4 ,
V_11 -> V_141 . V_142 ,
V_189 ) ;
V_89 -> V_98 . V_110 = V_189 ;
F_15 ( V_13 , & V_14 -> V_76 ) ;
V_14 -> V_77 = V_160 ;
F_62 ( & V_11 -> V_141 . V_190 ) ;
if ( F_95 () & V_191 )
V_119 = F_96 ( V_7 ,
F_97 ( V_13 , V_161 ) ) ;
else
V_119 = F_98 ( V_7 ,
F_97 ( V_13 , V_161 ) ) ;
if ( V_119 ) {
if ( F_56 ( V_7 , V_119 ) ) {
F_99 ( V_7 ,
V_119 ) ;
} else {
F_69 ( V_119 ) ;
V_119 = F_100 ( - V_145 ) ;
}
} else {
V_119 = F_100 ( - V_192 ) ;
}
V_118 -> V_4 . V_119 = V_119 ;
F_101 (scan, &connector->probed_modes, head) {
if ( V_157 -> type & V_193 ) {
F_21 ( L_18 ) ;
F_102 ( V_157 ) ;
V_97 = F_57 ( V_11 , V_157 ) ;
if ( V_97 )
goto V_21;
}
}
if ( V_13 -> V_154 . V_194 ) {
F_21 ( L_19 ) ;
F_102 ( V_13 -> V_154 . V_194 ) ;
V_97 = F_57 ( V_11 , V_13 -> V_154 . V_194 ) ;
if ( V_97 ) {
V_97 -> type |= V_193 ;
V_7 -> V_184 . V_195 = V_97 -> V_195 ;
V_7 -> V_184 . V_196 = V_97 -> V_196 ;
goto V_21;
}
}
if ( F_29 ( V_13 ) )
goto V_197;
V_9 = ( V_160 & V_80 ) ? 1 : 0 ;
V_72 = F_103 ( V_13 , V_9 ) ;
if ( V_72 && ( V_160 & V_20 ) ) {
V_97 = F_104 ( V_11 , & V_72 -> V_4 ) ;
if ( V_97 ) {
F_21 ( L_20 ) ;
F_102 ( V_97 ) ;
V_97 -> type |= V_193 ;
goto V_21;
}
}
if ( ! V_97 )
goto V_197;
V_21:
F_66 ( & V_11 -> V_141 . V_190 ) ;
F_105 ( & V_89 -> V_98 , V_97 , V_158 ) ;
F_106 ( V_7 , V_198 ) ;
V_14 -> V_81 = F_80 ( V_14 ) ;
F_21 ( L_21 ,
V_14 -> V_81 ? L_22 : L_23 ) ;
V_14 -> V_85 = V_160 & V_84 ;
V_118 -> V_125 . V_137 = F_61 ;
if ( F_107 ( & V_118 -> V_125 ) ) {
F_21 ( L_24 ) ;
V_118 -> V_125 . V_137 = NULL ;
}
return;
V_197:
F_66 ( & V_11 -> V_141 . V_190 ) ;
F_21 ( L_25 ) ;
F_71 ( V_7 ) ;
F_108 ( V_3 ) ;
F_69 ( V_14 ) ;
F_69 ( V_118 ) ;
return;
}
