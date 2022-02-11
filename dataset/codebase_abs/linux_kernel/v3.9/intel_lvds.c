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
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_16 ;
V_16 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_16 & V_18 ) )
return false ;
if ( F_6 ( V_11 ) )
* V_9 = F_7 ( V_16 ) ;
else
* V_9 = F_8 ( V_16 ) ;
return true ;
}
static void F_9 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_19 * V_19 = F_10 ( V_3 -> V_4 . V_20 ) ;
struct V_21 * V_22 =
V_15 -> V_23 -> V_4 . V_24 . V_22 ;
int V_9 = V_19 -> V_9 ;
T_1 V_25 ;
V_25 = F_5 ( V_15 -> V_17 ) ;
V_25 |= V_18 | V_26 ;
if ( F_6 ( V_11 ) ) {
V_25 &= ~ V_27 ;
V_25 |= F_11 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_25 |= V_28 ;
} else {
V_25 &= ~ V_28 ;
}
}
V_25 |= V_13 -> V_29 ;
if ( V_15 -> V_30 )
V_25 |= V_31 | V_32 ;
else
V_25 &= ~ ( V_31 | V_32 ) ;
if ( F_12 ( V_11 ) -> V_33 == 4 ) {
if ( V_13 -> V_34 )
V_25 |= V_35 ;
else
V_25 &= ~ V_35 ;
}
V_25 &= ~ ( V_36 | V_37 ) ;
if ( V_22 -> V_38 & V_39 )
V_25 |= V_36 ;
if ( V_22 -> V_38 & V_40 )
V_25 |= V_37 ;
F_13 ( V_15 -> V_17 , V_25 ) ;
}
static void F_14 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_41 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( F_15 ( V_11 ) || ! V_41 -> V_42 )
return;
F_16 ( L_1 ,
V_41 -> V_42 ,
V_41 -> V_43 ) ;
F_13 ( V_44 , V_41 -> V_43 ) ;
F_13 ( V_45 , V_41 -> V_42 ) ;
}
static void F_17 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_19 * V_19 = F_10 ( V_3 -> V_4 . V_20 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_46 , V_47 ;
if ( F_15 ( V_11 ) ) {
V_46 = V_48 ;
V_47 = V_49 ;
} else {
V_46 = V_50 ;
V_47 = V_51 ;
}
F_13 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) | V_18 ) ;
F_13 ( V_46 , F_5 ( V_46 ) | V_52 ) ;
F_18 ( V_15 -> V_17 ) ;
if ( F_19 ( ( F_5 ( V_47 ) & V_53 ) != 0 , 1000 ) )
F_20 ( L_2 ) ;
F_21 ( V_11 , V_19 -> V_9 ) ;
}
static void F_22 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_46 , V_47 ;
if ( F_15 ( V_11 ) ) {
V_46 = V_48 ;
V_47 = V_49 ;
} else {
V_46 = V_50 ;
V_47 = V_51 ;
}
F_23 ( V_11 ) ;
F_13 ( V_46 , F_5 ( V_46 ) & ~ V_52 ) ;
if ( F_19 ( ( F_5 ( V_47 ) & V_53 ) == 0 , 1000 ) )
F_20 ( L_3 ) ;
F_13 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) & ~ V_18 ) ;
F_18 ( V_15 -> V_17 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_21 * V_54 )
{
struct V_55 * V_55 = F_25 ( V_7 ) ;
struct V_21 * V_22 = V_55 -> V_24 . V_22 ;
if ( V_54 -> V_56 > V_22 -> V_56 )
return V_57 ;
if ( V_54 -> V_58 > V_22 -> V_58 )
return V_57 ;
return V_59 ;
}
static void
F_26 ( struct V_21 * V_54 ,
int V_60 )
{
T_1 V_61 , V_62 , V_63 , V_64 ;
V_64 = V_54 -> V_65 - V_54 -> V_66 ;
V_63 = V_54 -> V_67 - V_54 -> V_68 ;
V_62 = ( V_63 - V_64 + 1 ) / 2 ;
V_61 = ( V_54 -> V_56 - V_60 + 1 ) / 2 ;
V_61 += V_61 & 1 ;
V_54 -> V_69 = V_60 ;
V_54 -> V_68 = V_60 + V_61 ;
V_54 -> V_67 = V_54 -> V_68 + V_63 ;
V_54 -> V_66 = V_54 -> V_68 + V_62 ;
V_54 -> V_65 = V_54 -> V_66 + V_64 ;
V_54 -> V_70 |= V_71 ;
}
static void
F_27 ( struct V_21 * V_54 ,
int V_72 )
{
T_1 V_61 , V_62 , V_63 , V_64 ;
V_64 = V_54 -> V_73 - V_54 -> V_74 ;
V_63 = V_54 -> V_75 - V_54 -> V_76 ;
V_62 = ( V_63 - V_64 + 1 ) / 2 ;
V_61 = ( V_54 -> V_58 - V_72 + 1 ) / 2 ;
V_54 -> V_77 = V_72 ;
V_54 -> V_76 = V_72 + V_61 ;
V_54 -> V_75 = V_54 -> V_76 + V_63 ;
V_54 -> V_74 = V_54 -> V_76 + V_62 ;
V_54 -> V_73 = V_54 -> V_74 + V_64 ;
V_54 -> V_70 |= V_71 ;
}
static inline T_1 F_28 ( T_1 V_78 , T_1 V_79 )
{
#define F_29 12
#define F_30 (1 << ACCURACY)
T_1 V_80 = V_78 * F_30 / V_79 ;
return ( F_30 * V_80 + F_30 / 2 ) / F_30 ;
}
static bool F_31 ( struct V_2 * V_3 ,
const struct V_21 * V_54 ,
struct V_21 * V_81 )
{
struct V_10 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_55 * V_55 =
& V_15 -> V_23 -> V_4 ;
struct V_19 * V_19 = V_15 -> V_4 . V_82 ;
T_1 V_42 = 0 , V_43 = 0 , V_61 = 0 ;
int V_9 ;
if ( F_12 ( V_11 ) -> V_33 < 4 && V_19 -> V_9 == 0 ) {
F_20 ( L_4 ) ;
return false ;
}
if ( F_32 ( & V_15 -> V_4 ) )
return false ;
F_33 ( V_55 -> V_24 . V_22 ,
V_81 ) ;
if ( F_15 ( V_11 ) ) {
F_34 ( V_11 ,
V_55 -> V_24 . V_83 ,
V_54 , V_81 ) ;
return true ;
}
if ( V_81 -> V_56 == V_54 -> V_56 &&
V_81 -> V_58 == V_54 -> V_58 )
goto V_84;
if ( F_12 ( V_11 ) -> V_33 >= 4 )
V_42 |= ( ( V_19 -> V_9 << V_85 ) |
V_86 ) ;
F_35 (pipe)
F_13 ( F_36 ( V_9 ) , 0 ) ;
F_37 ( V_81 , 0 ) ;
switch ( V_55 -> V_24 . V_83 ) {
case V_87 :
F_26 ( V_81 , V_54 -> V_56 ) ;
F_27 ( V_81 , V_54 -> V_58 ) ;
V_61 = V_88 ;
break;
case V_89 :
if ( F_12 ( V_11 ) -> V_33 >= 4 ) {
T_1 V_90 = V_81 -> V_56 * V_54 -> V_58 ;
T_1 V_91 = V_54 -> V_56 * V_81 -> V_58 ;
if ( V_90 > V_91 )
V_42 |= V_92 | V_93 ;
else if ( V_90 < V_91 )
V_42 |= V_92 | V_94 ;
else if ( V_81 -> V_56 != V_54 -> V_56 )
V_42 |= V_92 | V_95 ;
} else {
T_1 V_90 = V_81 -> V_56 * V_54 -> V_58 ;
T_1 V_91 = V_54 -> V_56 * V_81 -> V_58 ;
if ( V_90 > V_91 ) {
F_26 ( V_81 , V_91 / V_54 -> V_58 ) ;
V_61 = V_88 ;
if ( V_54 -> V_58 != V_81 -> V_58 ) {
T_1 V_96 = F_28 ( V_54 -> V_58 , V_81 -> V_58 ) ;
V_43 |= ( V_96 << V_97 |
V_96 << V_98 ) ;
V_42 |= ( V_92 |
V_99 |
V_100 ) ;
}
} else if ( V_90 < V_91 ) {
F_27 ( V_81 , V_90 / V_54 -> V_56 ) ;
V_61 = V_88 ;
if ( V_54 -> V_56 != V_81 -> V_56 ) {
T_1 V_96 = F_28 ( V_54 -> V_56 , V_81 -> V_56 ) ;
V_43 |= ( V_96 << V_97 |
V_96 << V_98 ) ;
V_42 |= ( V_92 |
V_99 |
V_100 ) ;
}
} else
V_42 |= ( V_92 |
V_101 | V_102 |
V_99 |
V_100 ) ;
}
break;
case V_103 :
if ( V_54 -> V_58 != V_81 -> V_58 ||
V_54 -> V_56 != V_81 -> V_56 ) {
V_42 |= V_92 ;
if ( F_12 ( V_11 ) -> V_33 >= 4 )
V_42 |= V_95 ;
else
V_42 |= ( V_101 |
V_99 |
V_102 |
V_100 ) ;
}
break;
default:
break;
}
V_84:
if ( ( V_42 & V_92 ) == 0 ) {
V_42 = 0 ;
V_43 = 0 ;
}
if ( F_12 ( V_11 ) -> V_33 < 4 && V_13 -> V_34 )
V_42 |= V_104 ;
if ( V_42 != V_15 -> V_42 ||
V_43 != V_15 -> V_43 ) {
V_15 -> V_42 = V_42 ;
V_15 -> V_43 = V_43 ;
}
V_13 -> V_29 = V_61 ;
return true ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_21 * V_54 ,
struct V_21 * V_81 )
{
}
static enum V_105
F_39 ( struct V_6 * V_7 , bool V_106 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_105 V_107 ;
V_107 = F_40 ( V_11 ) ;
if ( V_107 != V_108 )
return V_107 ;
return V_109 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_5 * V_110 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_21 * V_54 ;
if ( ! F_42 ( V_110 -> V_4 . V_111 ) )
return F_43 ( V_7 , V_110 -> V_4 . V_111 ) ;
V_54 = F_44 ( V_11 , V_110 -> V_4 . V_24 . V_22 ) ;
if ( V_54 == NULL )
return 0 ;
F_45 ( V_7 , V_54 ) ;
return 1 ;
}
static int F_46 ( const struct V_112 * V_113 )
{
F_47 ( L_5 , V_113 -> V_114 ) ;
return 1 ;
}
static int F_48 ( struct V_115 * V_116 , unsigned long V_117 ,
void * V_118 )
{
struct V_5 * V_110 =
F_2 ( V_116 , struct V_5 , V_119 ) ;
struct V_6 * V_7 = & V_110 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_120 != V_121 )
return V_122 ;
F_49 ( & V_13 -> V_123 ) ;
if ( V_13 -> V_124 == V_125 )
goto exit;
V_7 -> V_107 = V_7 -> V_126 -> V_127 ( V_7 , false ) ;
if ( F_50 ( V_128 ) )
goto exit;
if ( ! F_51 () ) {
V_13 -> V_124 = V_129 ;
goto exit;
}
if ( V_13 -> V_124 == V_130 )
goto exit;
F_52 ( V_11 ) ;
F_53 ( V_11 , true ) ;
F_54 ( V_11 ) ;
V_13 -> V_124 = V_130 ;
exit:
F_55 ( & V_13 -> V_123 ) ;
return V_122 ;
}
static void F_56 ( struct V_6 * V_7 )
{
struct V_5 * V_110 =
F_3 ( V_7 ) ;
if ( V_110 -> V_119 . V_131 )
F_57 ( & V_110 -> V_119 ) ;
if ( ! F_42 ( V_110 -> V_4 . V_111 ) )
F_58 ( V_110 -> V_4 . V_111 ) ;
F_59 ( V_7 -> V_11 ) ;
F_60 ( & V_110 -> V_4 . V_24 ) ;
F_61 ( V_7 ) ;
F_62 ( V_7 ) ;
F_58 ( V_7 ) ;
}
static int F_63 ( struct V_6 * V_7 ,
struct V_132 * V_133 ,
T_2 V_134 )
{
struct V_55 * V_55 = F_25 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_133 == V_11 -> V_135 . V_136 ) {
struct V_137 * V_20 ;
if ( V_134 == V_138 ) {
F_16 ( L_6 ) ;
return - V_139 ;
}
if ( V_55 -> V_24 . V_83 == V_134 ) {
return 0 ;
}
V_55 -> V_24 . V_83 = V_134 ;
V_20 = F_64 ( V_7 ) -> V_4 . V_20 ;
if ( V_20 && V_20 -> V_140 ) {
F_65 ( V_20 ) ;
}
}
return 0 ;
}
static int T_3 F_66 ( const struct V_112 * V_113 )
{
F_47 ( L_7 , V_113 -> V_114 ) ;
return 1 ;
}
static void F_67 ( struct V_10 * V_11 ,
struct V_21 * V_22 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_21 * V_141 ;
int V_142 ;
V_142 = V_22 -> clock ;
F_68 (scan, &connector->probed_modes, head) {
if ( V_141 -> V_56 == V_22 -> V_56 &&
V_141 -> V_143 == V_22 -> V_143 &&
V_141 -> V_144 == V_22 -> V_144 &&
V_141 -> V_145 == V_22 -> V_145 &&
V_141 -> V_58 == V_22 -> V_58 &&
V_141 -> V_146 == V_22 -> V_146 &&
V_141 -> V_147 == V_22 -> V_147 &&
V_141 -> V_148 == V_22 -> V_148 ) {
if ( V_141 -> clock < V_142 ) {
V_142 = V_141 -> clock ;
}
}
}
if ( V_142 < V_22 -> clock && V_149 ) {
V_13 -> V_150 = 1 ;
V_13 -> V_151 = V_142 ;
F_16 ( L_8
L_9 ,
V_22 -> clock , V_142 ) ;
}
}
static bool F_69 ( struct V_10 * V_11 ,
T_4 * V_152 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_153 ;
if ( ! V_13 -> V_154 )
return true ;
for ( V_153 = 0 ; V_153 < V_13 -> V_154 ; V_153 ++ ) {
struct V_155 * V_156 = V_13 -> V_157 + V_153 ;
if ( V_156 -> V_158 != V_159 &&
V_156 -> V_158 != V_160 )
continue;
if ( F_70 ( V_156 -> V_152 ) )
* V_152 = V_156 -> V_152 ;
if ( V_156 -> V_161 )
return true ;
if ( V_13 -> V_162 . V_163 )
return true ;
}
return false ;
}
static int F_71 ( const struct V_112 * V_113 )
{
F_47 ( L_10 , V_113 -> V_114 ) ;
return 1 ;
}
bool F_72 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_68 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_164 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_30 ;
}
}
return false ;
}
static bool F_73 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_117 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_165 > 0 )
return V_165 == 2 ;
if ( F_50 ( V_166 ) )
return true ;
V_117 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_117 & ~ ( V_167 | V_168 ) ) )
V_117 = V_13 -> V_169 ;
return ( V_117 & V_170 ) == V_32 ;
}
static bool F_74 ( struct V_10 * V_11 )
{
if ( F_15 ( V_11 ) )
return true ;
return F_75 ( V_11 ) && ! F_76 ( V_11 ) ;
}
bool F_77 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_110 ;
struct V_55 * V_55 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_21 * V_141 ;
struct V_21 * V_22 = NULL ;
struct V_111 * V_111 ;
struct V_137 * V_20 ;
T_1 V_171 ;
int V_9 ;
T_4 V_172 ;
if ( ! F_74 ( V_11 ) )
return false ;
if ( F_50 ( V_173 ) )
return false ;
V_172 = V_174 ;
if ( ! F_69 ( V_11 , & V_172 ) ) {
F_16 ( L_11 ) ;
return false ;
}
if ( F_15 ( V_11 ) ) {
if ( ( F_5 ( V_175 ) & V_168 ) == 0 )
return false ;
if ( V_13 -> V_176 . V_177 ) {
F_16 ( L_12 ) ;
return false ;
}
}
V_15 = F_78 ( sizeof( struct V_1 ) , V_178 ) ;
if ( ! V_15 )
return false ;
V_110 = F_78 ( sizeof( struct V_5 ) , V_178 ) ;
if ( ! V_110 ) {
F_58 ( V_15 ) ;
return false ;
}
V_15 -> V_23 = V_110 ;
if ( ! F_15 ( V_11 ) ) {
V_15 -> V_42 = F_5 ( V_45 ) ;
}
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_55 = & V_110 -> V_4 ;
V_7 = & V_55 -> V_4 ;
F_79 ( V_11 , & V_55 -> V_4 , & V_179 ,
V_180 ) ;
F_80 ( V_11 , & V_8 -> V_4 , & V_181 ,
V_182 ) ;
V_8 -> V_183 = F_17 ;
V_8 -> V_184 = F_14 ;
V_8 -> V_185 = F_9 ;
V_8 -> V_186 = F_22 ;
V_8 -> V_187 = F_4 ;
V_55 -> V_187 = V_188 ;
F_81 ( V_55 , V_8 ) ;
V_8 -> type = V_164 ;
V_8 -> V_189 = false ;
if ( F_15 ( V_11 ) )
V_8 -> V_190 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_82 ( V_11 ) )
V_8 -> V_190 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_190 = ( 1 << 1 ) ;
F_83 ( V_3 , & V_191 ) ;
F_84 ( V_7 , & V_192 ) ;
V_7 -> V_193 . V_194 = V_195 ;
V_7 -> V_196 = false ;
V_7 -> V_197 = false ;
if ( F_15 ( V_11 ) ) {
V_15 -> V_17 = V_175 ;
} else {
V_15 -> V_17 = V_198 ;
}
F_85 ( V_11 ) ;
F_86 ( & V_7 -> V_4 ,
V_11 -> V_135 . V_136 ,
V_89 ) ;
V_55 -> V_24 . V_83 = V_89 ;
V_111 = F_87 ( V_7 , F_88 ( V_13 , V_172 ) ) ;
if ( V_111 ) {
if ( F_43 ( V_7 , V_111 ) ) {
F_89 ( V_7 ,
V_111 ) ;
} else {
F_58 ( V_111 ) ;
V_111 = F_90 ( - V_139 ) ;
}
} else {
V_111 = F_90 ( - V_199 ) ;
}
V_110 -> V_4 . V_111 = V_111 ;
if ( F_42 ( V_111 ) ) {
V_7 -> V_193 . V_200 = 0 ;
V_7 -> V_193 . V_201 = 200 ;
V_7 -> V_193 . V_202 = 0 ;
V_7 -> V_193 . V_203 = 200 ;
}
F_68 (scan, &connector->probed_modes, head) {
if ( V_141 -> type & V_204 ) {
F_16 ( L_13 ) ;
F_91 ( V_141 ) ;
V_22 = F_44 ( V_11 , V_141 ) ;
if ( V_22 ) {
F_67 ( V_11 , V_22 ,
V_7 ) ;
goto V_84;
}
}
}
if ( V_13 -> V_205 ) {
F_16 ( L_14 ) ;
F_91 ( V_13 -> V_205 ) ;
V_22 = F_44 ( V_11 , V_13 -> V_205 ) ;
if ( V_22 ) {
V_22 -> type |= V_204 ;
goto V_84;
}
}
if ( F_15 ( V_11 ) )
goto V_206;
V_171 = F_5 ( V_198 ) ;
V_9 = ( V_171 & V_28 ) ? 1 : 0 ;
V_20 = F_92 ( V_11 , V_9 ) ;
if ( V_20 && ( V_171 & V_18 ) ) {
V_22 = F_93 ( V_11 , V_20 ) ;
if ( V_22 ) {
F_16 ( L_15 ) ;
F_91 ( V_22 ) ;
V_22 -> type |= V_204 ;
goto V_84;
}
}
if ( ! V_22 )
goto V_206;
V_84:
V_15 -> V_30 = F_73 ( V_15 ) ;
F_16 ( L_16 ,
V_15 -> V_30 ? L_17 : L_18 ) ;
if ( F_15 ( V_11 ) ) {
F_13 ( V_48 ,
F_5 ( V_48 ) | V_207 ) ;
} else {
F_13 ( V_50 ,
F_5 ( V_50 ) | V_207 ) ;
}
V_110 -> V_119 . V_131 = F_48 ;
if ( F_94 ( & V_110 -> V_119 ) ) {
F_16 ( L_19 ) ;
V_110 -> V_119 . V_131 = NULL ;
}
F_95 ( V_7 ) ;
F_96 ( & V_55 -> V_24 , V_22 ) ;
F_97 ( V_7 ) ;
return true ;
V_206:
F_16 ( L_20 ) ;
F_62 ( V_7 ) ;
F_98 ( V_3 ) ;
if ( V_22 )
F_99 ( V_11 , V_22 ) ;
F_58 ( V_15 ) ;
F_58 ( V_110 ) ;
return false ;
}
