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
static void F_9 ( struct V_8 * V_3 ,
struct V_19 * V_20 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_21 , V_16 , V_22 = 0 ;
int V_23 ;
if ( F_10 ( V_11 ) )
V_21 = V_24 ;
else
V_21 = V_25 ;
V_16 = F_5 ( V_21 ) ;
if ( V_16 & V_26 )
V_22 |= V_27 ;
else
V_22 |= V_28 ;
if ( V_16 & V_29 )
V_22 |= V_30 ;
else
V_22 |= V_31 ;
V_20 -> V_32 . V_22 |= V_22 ;
if ( F_11 ( V_11 ) -> V_33 < 4 ) {
V_16 = F_5 ( V_34 ) ;
V_20 -> V_35 . V_36 |= V_16 & V_37 ;
}
V_23 = V_20 -> V_38 ;
if ( F_10 ( V_13 -> V_11 ) )
F_12 ( V_20 , V_23 ) ;
V_20 -> V_32 . V_39 = V_23 ;
}
static void F_13 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_40 * V_41 = F_14 ( V_3 -> V_4 . V_41 ) ;
const struct V_42 * V_32 =
& V_41 -> V_43 . V_32 ;
int V_9 = V_41 -> V_9 ;
T_1 V_44 ;
if ( F_10 ( V_11 ) ) {
F_15 ( V_13 , V_9 ) ;
F_16 ( V_13 ,
F_17 ( V_41 ) ) ;
} else {
F_18 ( V_13 , V_9 ) ;
}
V_44 = F_5 ( V_15 -> V_17 ) ;
V_44 |= V_18 | V_45 ;
if ( F_6 ( V_11 ) ) {
V_44 &= ~ V_46 ;
V_44 |= F_19 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_44 |= V_47 ;
} else {
V_44 &= ~ V_47 ;
}
}
V_44 &= ~ V_48 ;
V_44 |= V_41 -> V_43 . V_35 . V_49 ;
if ( V_15 -> V_50 )
V_44 |= V_51 | V_52 ;
else
V_44 &= ~ ( V_51 | V_52 ) ;
if ( F_11 ( V_11 ) -> V_33 == 4 ) {
if ( V_41 -> V_43 . V_53 && V_41 -> V_43 . V_54 == 18 )
V_44 |= V_55 ;
else
V_44 &= ~ V_55 ;
}
V_44 &= ~ ( V_26 | V_29 ) ;
if ( V_32 -> V_22 & V_27 )
V_44 |= V_26 ;
if ( V_32 -> V_22 & V_30 )
V_44 |= V_29 ;
F_20 ( V_15 -> V_17 , V_44 ) ;
}
static void F_21 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_56 * V_56 =
& V_15 -> V_57 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_58 , V_59 ;
if ( F_10 ( V_11 ) ) {
V_58 = V_60 ;
V_59 = V_61 ;
} else {
V_58 = V_62 ;
V_59 = V_63 ;
}
F_20 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) | V_18 ) ;
F_20 ( V_58 , F_5 ( V_58 ) | V_64 ) ;
F_22 ( V_15 -> V_17 ) ;
if ( F_23 ( ( F_5 ( V_59 ) & V_65 ) != 0 , 1000 ) )
F_24 ( L_1 ) ;
F_25 ( V_56 ) ;
}
static void F_26 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_56 * V_56 =
& V_15 -> V_57 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_58 , V_59 ;
if ( F_10 ( V_11 ) ) {
V_58 = V_60 ;
V_59 = V_61 ;
} else {
V_58 = V_62 ;
V_59 = V_63 ;
}
F_27 ( V_56 ) ;
F_20 ( V_58 , F_5 ( V_58 ) & ~ V_64 ) ;
if ( F_23 ( ( F_5 ( V_59 ) & V_65 ) == 0 , 1000 ) )
F_24 ( L_2 ) ;
F_20 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) & ~ V_18 ) ;
F_22 ( V_15 -> V_17 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_42 * V_66 )
{
struct V_56 * V_56 = F_29 ( V_7 ) ;
struct V_42 * V_67 = V_56 -> V_68 . V_67 ;
if ( V_66 -> V_69 > V_67 -> V_69 )
return V_70 ;
if ( V_66 -> V_71 > V_67 -> V_71 )
return V_70 ;
return V_72 ;
}
static bool F_30 ( struct V_8 * V_8 ,
struct V_19 * V_20 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_56 * V_56 =
& V_15 -> V_57 -> V_4 ;
struct V_42 * V_32 = & V_20 -> V_32 ;
struct V_40 * V_40 = V_15 -> V_4 . V_73 ;
unsigned int V_74 ;
if ( F_11 ( V_11 ) -> V_33 < 4 && V_40 -> V_9 == 0 ) {
F_24 ( L_3 ) ;
return false ;
}
if ( ( F_5 ( V_15 -> V_17 ) & V_75 ) ==
V_76 )
V_74 = 8 * 3 ;
else
V_74 = 6 * 3 ;
if ( V_74 != V_20 -> V_54 && ! V_20 -> V_77 ) {
F_31 ( L_4 ,
V_20 -> V_54 , V_74 ) ;
V_20 -> V_54 = V_74 ;
}
F_32 ( V_56 -> V_68 . V_67 ,
V_32 ) ;
if ( F_10 ( V_11 ) ) {
V_20 -> V_78 = true ;
F_33 ( V_40 , V_20 ,
V_56 -> V_68 . V_79 ) ;
} else {
F_34 ( V_40 , V_20 ,
V_56 -> V_68 . V_79 ) ;
}
return true ;
}
static void F_35 ( struct V_8 * V_3 )
{
}
static enum V_80
F_36 ( struct V_6 * V_7 , bool V_81 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_80 V_82 ;
F_31 ( L_5 ,
V_7 -> V_4 . V_83 , F_37 ( V_7 ) ) ;
V_82 = F_38 ( V_11 ) ;
if ( V_82 != V_84 )
return V_82 ;
return V_85 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_5 * V_86 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_42 * V_66 ;
if ( ! F_40 ( V_86 -> V_4 . V_87 ) )
return F_41 ( V_7 , V_86 -> V_4 . V_87 ) ;
V_66 = F_42 ( V_11 , V_86 -> V_4 . V_68 . V_67 ) ;
if ( V_66 == NULL )
return 0 ;
F_43 ( V_7 , V_66 ) ;
return 1 ;
}
static int F_44 ( const struct V_88 * V_83 )
{
F_45 ( L_6 , V_83 -> V_89 ) ;
return 1 ;
}
static int F_46 ( struct V_90 * V_91 , unsigned long V_92 ,
void * V_93 )
{
struct V_5 * V_86 =
F_2 ( V_91 , struct V_5 , V_94 ) ;
struct V_6 * V_7 = & V_86 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_95 != V_96 )
return V_97 ;
F_47 ( & V_13 -> V_98 ) ;
if ( V_13 -> V_99 == V_100 )
goto exit;
V_7 -> V_82 = V_7 -> V_101 -> V_102 ( V_7 , false ) ;
if ( F_48 ( V_103 ) )
goto exit;
if ( ! F_49 () ) {
V_13 -> V_99 = V_104 ;
goto exit;
}
if ( V_13 -> V_99 == V_105 )
goto exit;
F_50 ( V_11 ) ;
F_51 ( V_11 , true ) ;
F_52 ( V_11 ) ;
V_13 -> V_99 = V_105 ;
exit:
F_53 ( & V_13 -> V_98 ) ;
return V_97 ;
}
static void F_54 ( struct V_6 * V_7 )
{
struct V_5 * V_86 =
F_3 ( V_7 ) ;
if ( V_86 -> V_94 . V_106 )
F_55 ( & V_86 -> V_94 ) ;
if ( ! F_40 ( V_86 -> V_4 . V_87 ) )
F_56 ( V_86 -> V_4 . V_87 ) ;
F_57 ( & V_86 -> V_4 . V_68 ) ;
F_58 ( V_7 ) ;
F_56 ( V_7 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_107 * V_108 ,
T_2 V_109 )
{
struct V_56 * V_56 = F_29 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_108 == V_11 -> V_110 . V_111 ) {
struct V_112 * V_41 ;
if ( V_109 == V_113 ) {
F_31 ( L_7 ) ;
return - V_114 ;
}
if ( V_56 -> V_68 . V_79 == V_109 ) {
return 0 ;
}
V_56 -> V_68 . V_79 = V_109 ;
V_41 = F_60 ( V_7 ) -> V_4 . V_41 ;
if ( V_41 && V_41 -> V_115 ) {
F_61 ( V_41 ) ;
}
}
return 0 ;
}
static int T_3 F_62 ( const struct V_88 * V_83 )
{
F_45 ( L_8 , V_83 -> V_89 ) ;
return 1 ;
}
static void F_63 ( struct V_10 * V_11 ,
struct V_42 * V_67 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_42 * V_116 ;
int V_117 ;
V_117 = V_67 -> clock ;
F_64 (scan, &connector->probed_modes, head) {
if ( V_116 -> V_69 == V_67 -> V_69 &&
V_116 -> V_118 == V_67 -> V_118 &&
V_116 -> V_119 == V_67 -> V_119 &&
V_116 -> V_120 == V_67 -> V_120 &&
V_116 -> V_71 == V_67 -> V_71 &&
V_116 -> V_121 == V_67 -> V_121 &&
V_116 -> V_122 == V_67 -> V_122 &&
V_116 -> V_123 == V_67 -> V_123 ) {
if ( V_116 -> clock < V_117 ) {
V_117 = V_116 -> clock ;
}
}
}
if ( V_117 < V_67 -> clock && V_124 ) {
V_13 -> V_125 = 1 ;
V_13 -> V_126 = V_117 ;
F_31 ( L_9
L_10 ,
V_67 -> clock , V_117 ) ;
}
}
static bool F_65 ( struct V_10 * V_11 ,
T_4 * V_127 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_128 ;
if ( ! V_13 -> V_129 . V_130 )
return true ;
for ( V_128 = 0 ; V_128 < V_13 -> V_129 . V_130 ; V_128 ++ ) {
union V_131 * V_132 = V_13 -> V_129 . V_133 + V_128 ;
struct V_134 * V_135 = & V_132 -> V_136 ;
if ( V_135 -> V_137 != V_138 &&
V_135 -> V_137 != V_139 )
continue;
if ( F_66 ( V_135 -> V_127 ) )
* V_127 = V_135 -> V_127 ;
if ( V_135 -> V_140 )
return true ;
if ( V_13 -> V_141 . V_129 )
return true ;
}
return false ;
}
static int F_67 ( const struct V_88 * V_83 )
{
F_45 ( L_11 , V_83 -> V_89 ) ;
return 1 ;
}
bool F_68 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_64 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_142 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_50 ;
}
}
return false ;
}
static bool F_69 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_92 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_143 > 0 )
return V_143 == 2 ;
if ( F_48 ( V_144 ) )
return true ;
V_92 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_92 & ~ ( V_145 | V_146 ) ) )
V_92 = V_13 -> V_129 . V_147 ;
return ( V_92 & V_148 ) == V_52 ;
}
static bool F_70 ( struct V_10 * V_11 )
{
if ( F_71 ( V_11 ) || F_6 ( V_11 ) )
return true ;
if ( F_11 ( V_11 ) -> V_33 <= 4 && F_72 ( V_11 ) && ! F_73 ( V_11 ) )
return true ;
return false ;
}
void F_74 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_86 ;
struct V_56 * V_56 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_42 * V_116 ;
struct V_42 * V_67 = NULL ;
struct V_87 * V_87 ;
struct V_112 * V_41 ;
T_1 V_149 ;
int V_9 ;
T_4 V_150 ;
if ( ! F_70 ( V_11 ) )
return;
if ( F_48 ( V_151 ) )
return;
V_150 = V_152 ;
if ( ! F_65 ( V_11 , & V_150 ) ) {
F_31 ( L_12 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
if ( ( F_5 ( V_24 ) & V_146 ) == 0 )
return;
if ( V_13 -> V_129 . V_153 ) {
F_31 ( L_13 ) ;
return;
}
}
V_15 = F_75 ( sizeof( * V_15 ) , V_154 ) ;
if ( ! V_15 )
return;
V_86 = F_75 ( sizeof( * V_86 ) , V_154 ) ;
if ( ! V_86 ) {
F_56 ( V_15 ) ;
return;
}
V_15 -> V_57 = V_86 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_56 = & V_86 -> V_4 ;
V_7 = & V_56 -> V_4 ;
F_76 ( V_11 , & V_56 -> V_4 , & V_155 ,
V_156 ) ;
F_77 ( V_11 , & V_8 -> V_4 , & V_157 ,
V_158 ) ;
V_8 -> V_159 = F_21 ;
V_8 -> V_160 = F_13 ;
V_8 -> V_161 = F_30 ;
V_8 -> V_162 = F_35 ;
V_8 -> V_163 = F_26 ;
V_8 -> V_164 = F_4 ;
V_8 -> V_165 = F_9 ;
V_56 -> V_164 = V_166 ;
F_78 ( V_56 , V_8 ) ;
V_8 -> type = V_142 ;
V_8 -> V_167 = false ;
if ( F_10 ( V_11 ) )
V_8 -> V_168 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_79 ( V_11 ) )
V_8 -> V_168 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_168 = ( 1 << 1 ) ;
F_80 ( V_7 , & V_169 ) ;
V_7 -> V_170 . V_171 = V_172 ;
V_7 -> V_173 = false ;
V_7 -> V_174 = false ;
if ( F_10 ( V_11 ) ) {
V_15 -> V_17 = V_24 ;
} else {
V_15 -> V_17 = V_25 ;
}
F_81 ( V_11 ) ;
F_82 ( & V_7 -> V_4 ,
V_11 -> V_110 . V_111 ,
V_175 ) ;
V_56 -> V_68 . V_79 = V_175 ;
V_87 = F_83 ( V_7 , F_84 ( V_13 , V_150 ) ) ;
if ( V_87 ) {
if ( F_41 ( V_7 , V_87 ) ) {
F_85 ( V_7 ,
V_87 ) ;
} else {
F_56 ( V_87 ) ;
V_87 = F_86 ( - V_114 ) ;
}
} else {
V_87 = F_86 ( - V_176 ) ;
}
V_86 -> V_4 . V_87 = V_87 ;
if ( F_40 ( V_87 ) ) {
V_7 -> V_170 . V_177 = 0 ;
V_7 -> V_170 . V_178 = 200 ;
V_7 -> V_170 . V_179 = 0 ;
V_7 -> V_170 . V_180 = 200 ;
}
F_64 (scan, &connector->probed_modes, head) {
if ( V_116 -> type & V_181 ) {
F_31 ( L_14 ) ;
F_87 ( V_116 ) ;
V_67 = F_42 ( V_11 , V_116 ) ;
if ( V_67 ) {
F_63 ( V_11 , V_67 ,
V_7 ) ;
goto V_182;
}
}
}
if ( V_13 -> V_129 . V_183 ) {
F_31 ( L_15 ) ;
F_87 ( V_13 -> V_129 . V_183 ) ;
V_67 = F_42 ( V_11 , V_13 -> V_129 . V_183 ) ;
if ( V_67 ) {
V_67 -> type |= V_181 ;
goto V_182;
}
}
if ( F_10 ( V_11 ) )
goto V_184;
V_149 = F_5 ( V_25 ) ;
V_9 = ( V_149 & V_47 ) ? 1 : 0 ;
V_41 = F_88 ( V_11 , V_9 ) ;
if ( V_41 && ( V_149 & V_18 ) ) {
V_67 = F_89 ( V_11 , V_41 ) ;
if ( V_67 ) {
F_31 ( L_16 ) ;
F_87 ( V_67 ) ;
V_67 -> type |= V_181 ;
goto V_182;
}
}
if ( ! V_67 )
goto V_184;
V_182:
V_15 -> V_50 = F_69 ( V_15 ) ;
F_31 ( L_17 ,
V_15 -> V_50 ? L_18 : L_19 ) ;
if ( F_10 ( V_11 ) ) {
F_20 ( V_60 ,
F_5 ( V_60 ) | V_185 ) ;
} else {
F_20 ( V_62 ,
F_5 ( V_62 ) | V_185 ) ;
}
V_86 -> V_94 . V_106 = F_46 ;
if ( F_90 ( & V_86 -> V_94 ) ) {
F_31 ( L_20 ) ;
V_86 -> V_94 . V_106 = NULL ;
}
F_91 ( V_7 ) ;
F_92 ( & V_56 -> V_68 , V_67 ) ;
F_93 ( V_7 ) ;
return;
V_184:
F_31 ( L_21 ) ;
F_58 ( V_7 ) ;
F_94 ( V_3 ) ;
if ( V_67 )
F_95 ( V_11 , V_67 ) ;
F_56 ( V_15 ) ;
F_56 ( V_86 ) ;
return;
}
