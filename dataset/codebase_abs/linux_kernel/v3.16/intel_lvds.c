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
static enum V_66
F_28 ( struct V_6 * V_7 ,
struct V_42 * V_67 )
{
struct V_56 * V_56 = F_29 ( V_7 ) ;
struct V_42 * V_68 = V_56 -> V_69 . V_68 ;
if ( V_67 -> V_70 > V_68 -> V_70 )
return V_71 ;
if ( V_67 -> V_72 > V_68 -> V_72 )
return V_71 ;
return V_73 ;
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
struct V_40 * V_40 = V_15 -> V_4 . V_74 ;
unsigned int V_75 ;
if ( F_11 ( V_11 ) -> V_33 < 4 && V_40 -> V_9 == 0 ) {
F_24 ( L_3 ) ;
return false ;
}
if ( ( F_5 ( V_15 -> V_17 ) & V_76 ) ==
V_77 )
V_75 = 8 * 3 ;
else
V_75 = 6 * 3 ;
if ( V_75 != V_20 -> V_54 && ! V_20 -> V_78 ) {
F_31 ( L_4 ,
V_20 -> V_54 , V_75 ) ;
V_20 -> V_54 = V_75 ;
}
F_32 ( V_56 -> V_69 . V_68 ,
V_32 ) ;
if ( F_10 ( V_11 ) ) {
V_20 -> V_79 = true ;
F_33 ( V_40 , V_20 ,
V_56 -> V_69 . V_80 ) ;
} else {
F_34 ( V_40 , V_20 ,
V_56 -> V_69 . V_80 ) ;
}
return true ;
}
static enum V_81
F_35 ( struct V_6 * V_7 , bool V_82 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_81 V_83 ;
F_31 ( L_5 ,
V_7 -> V_4 . V_84 , V_7 -> V_85 ) ;
V_83 = F_36 ( V_11 ) ;
if ( V_83 != V_86 )
return V_83 ;
return V_87 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_5 * V_88 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_42 * V_67 ;
if ( ! F_38 ( V_88 -> V_4 . V_89 ) )
return F_39 ( V_7 , V_88 -> V_4 . V_89 ) ;
V_67 = F_40 ( V_11 , V_88 -> V_4 . V_69 . V_68 ) ;
if ( V_67 == NULL )
return 0 ;
F_41 ( V_7 , V_67 ) ;
return 1 ;
}
static int F_42 ( const struct V_90 * V_84 )
{
F_43 ( L_6 , V_84 -> V_91 ) ;
return 1 ;
}
static int F_44 ( struct V_92 * V_93 , unsigned long V_94 ,
void * V_95 )
{
struct V_5 * V_88 =
F_2 ( V_93 , struct V_5 , V_96 ) ;
struct V_6 * V_7 = & V_88 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_97 != V_98 )
return V_99 ;
F_45 ( & V_13 -> V_100 ) ;
if ( V_13 -> V_101 == V_102 )
goto exit;
V_7 -> V_83 = V_7 -> V_103 -> V_104 ( V_7 , false ) ;
if ( F_46 ( V_105 ) )
goto exit;
if ( ! F_47 () ) {
V_13 -> V_101 = V_106 ;
goto exit;
}
if ( V_13 -> V_101 == V_107 )
goto exit;
if ( ! F_10 ( V_11 ) ) {
F_48 ( V_11 ) ;
F_49 ( V_11 , true ) ;
F_50 ( V_11 ) ;
}
V_13 -> V_101 = V_107 ;
exit:
F_51 ( & V_13 -> V_100 ) ;
return V_99 ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_5 * V_88 =
F_3 ( V_7 ) ;
if ( V_88 -> V_96 . V_108 )
F_53 ( & V_88 -> V_96 ) ;
if ( ! F_38 ( V_88 -> V_4 . V_89 ) )
F_54 ( V_88 -> V_4 . V_89 ) ;
F_55 ( & V_88 -> V_4 . V_69 ) ;
F_56 ( V_7 ) ;
F_54 ( V_7 ) ;
}
static int F_57 ( struct V_6 * V_7 ,
struct V_109 * V_110 ,
T_2 V_111 )
{
struct V_56 * V_56 = F_29 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_110 == V_11 -> V_112 . V_113 ) {
struct V_114 * V_41 ;
if ( V_111 == V_115 ) {
F_31 ( L_7 ) ;
return - V_116 ;
}
if ( V_56 -> V_69 . V_80 == V_111 ) {
return 0 ;
}
V_56 -> V_69 . V_80 = V_111 ;
V_41 = F_58 ( V_7 ) -> V_4 . V_41 ;
if ( V_41 && V_41 -> V_117 ) {
F_59 ( V_41 ) ;
}
}
return 0 ;
}
static int T_3 F_60 ( const struct V_90 * V_84 )
{
F_43 ( L_8 , V_84 -> V_91 ) ;
return 1 ;
}
static bool F_61 ( struct V_10 * V_11 ,
T_4 * V_118 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_119 ;
if ( ! V_13 -> V_120 . V_121 )
return true ;
for ( V_119 = 0 ; V_119 < V_13 -> V_120 . V_121 ; V_119 ++ ) {
union V_122 * V_123 = V_13 -> V_120 . V_124 + V_119 ;
struct V_125 * V_126 = & V_123 -> V_127 ;
if ( V_126 -> V_128 != V_129 &&
V_126 -> V_128 != V_130 )
continue;
if ( F_62 ( V_126 -> V_118 ) )
* V_118 = V_126 -> V_118 ;
if ( V_126 -> V_131 )
return true ;
if ( V_13 -> V_132 . V_120 )
return true ;
}
return false ;
}
static int F_63 ( const struct V_90 * V_84 )
{
F_43 ( L_9 , V_84 -> V_91 ) ;
return 1 ;
}
bool F_64 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_65 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_133 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_50 ;
}
}
return false ;
}
static bool F_66 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_94 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_134 . V_135 > 0 )
return V_134 . V_135 == 2 ;
if ( F_46 ( V_136 ) )
return true ;
V_94 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_94 & ~ ( V_137 | V_138 ) ) )
V_94 = V_13 -> V_120 . V_139 ;
return ( V_94 & V_140 ) == V_52 ;
}
static bool F_67 ( struct V_10 * V_11 )
{
if ( F_68 ( V_11 ) || F_6 ( V_11 ) )
return true ;
if ( F_11 ( V_11 ) -> V_33 <= 4 && F_69 ( V_11 ) && ! F_70 ( V_11 ) )
return true ;
return false ;
}
void F_71 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_88 ;
struct V_56 * V_56 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_42 * V_141 ;
struct V_42 * V_68 = NULL ;
struct V_42 * V_142 = NULL ;
struct V_89 * V_89 ;
struct V_114 * V_41 ;
T_1 V_143 ;
int V_9 ;
T_4 V_144 ;
if ( ! F_67 ( V_11 ) )
return;
if ( F_46 ( V_145 ) )
return;
V_144 = V_146 ;
if ( ! F_61 ( V_11 , & V_144 ) ) {
F_31 ( L_10 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
if ( ( F_5 ( V_24 ) & V_138 ) == 0 )
return;
if ( V_13 -> V_120 . V_147 ) {
F_31 ( L_11 ) ;
return;
}
}
V_15 = F_72 ( sizeof( * V_15 ) , V_148 ) ;
if ( ! V_15 )
return;
V_88 = F_72 ( sizeof( * V_88 ) , V_148 ) ;
if ( ! V_88 ) {
F_54 ( V_15 ) ;
return;
}
V_15 -> V_57 = V_88 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_56 = & V_88 -> V_4 ;
V_7 = & V_56 -> V_4 ;
F_73 ( V_11 , & V_56 -> V_4 , & V_149 ,
V_150 ) ;
F_74 ( V_11 , & V_8 -> V_4 , & V_151 ,
V_152 ) ;
V_8 -> V_153 = F_21 ;
V_8 -> V_154 = F_13 ;
V_8 -> V_155 = F_30 ;
V_8 -> V_156 = F_26 ;
V_8 -> V_157 = F_4 ;
V_8 -> V_158 = F_9 ;
V_56 -> V_157 = V_159 ;
V_56 -> V_160 = V_161 ;
F_75 ( V_56 , V_8 ) ;
V_8 -> type = V_133 ;
V_8 -> V_162 = 0 ;
if ( F_10 ( V_11 ) )
V_8 -> V_163 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_76 ( V_11 ) )
V_8 -> V_163 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_163 = ( 1 << 1 ) ;
F_77 ( V_7 , & V_164 ) ;
V_7 -> V_165 . V_166 = V_167 ;
V_7 -> V_168 = false ;
V_7 -> V_169 = false ;
if ( F_10 ( V_11 ) ) {
V_15 -> V_17 = V_24 ;
} else {
V_15 -> V_17 = V_25 ;
}
F_78 ( V_11 ) ;
F_79 ( & V_7 -> V_4 ,
V_11 -> V_112 . V_113 ,
V_170 ) ;
V_56 -> V_69 . V_80 = V_170 ;
F_45 ( & V_11 -> V_112 . V_171 ) ;
V_89 = F_80 ( V_7 , F_81 ( V_13 , V_144 ) ) ;
if ( V_89 ) {
if ( F_39 ( V_7 , V_89 ) ) {
F_82 ( V_7 ,
V_89 ) ;
} else {
F_54 ( V_89 ) ;
V_89 = F_83 ( - V_116 ) ;
}
} else {
V_89 = F_83 ( - V_172 ) ;
}
V_88 -> V_4 . V_89 = V_89 ;
if ( F_38 ( V_89 ) ) {
V_7 -> V_165 . V_173 = 0 ;
V_7 -> V_165 . V_174 = 200 ;
V_7 -> V_165 . V_175 = 0 ;
V_7 -> V_165 . V_176 = 200 ;
}
F_65 (scan, &connector->probed_modes, head) {
if ( V_141 -> type & V_177 ) {
F_31 ( L_12 ) ;
F_84 ( V_141 ) ;
V_68 = F_40 ( V_11 , V_141 ) ;
if ( V_68 ) {
V_142 =
F_85 ( V_11 ,
V_68 , V_7 ) ;
if ( V_142 != NULL &&
V_134 . V_178 ) {
V_13 -> V_179 = true ;
V_13 -> V_178 =
V_142 -> clock ;
F_31 ( L_13
L_14
L_15 ,
V_68 -> clock ,
V_13 -> V_178 ) ;
}
goto V_180;
}
}
}
if ( V_13 -> V_120 . V_181 ) {
F_31 ( L_16 ) ;
F_84 ( V_13 -> V_120 . V_181 ) ;
V_68 = F_40 ( V_11 , V_13 -> V_120 . V_181 ) ;
if ( V_68 ) {
V_68 -> type |= V_177 ;
goto V_180;
}
}
if ( F_10 ( V_11 ) )
goto V_182;
V_143 = F_5 ( V_25 ) ;
V_9 = ( V_143 & V_47 ) ? 1 : 0 ;
V_41 = F_86 ( V_11 , V_9 ) ;
if ( V_41 && ( V_143 & V_18 ) ) {
V_68 = F_87 ( V_11 , V_41 ) ;
if ( V_68 ) {
F_31 ( L_17 ) ;
F_84 ( V_68 ) ;
V_68 -> type |= V_177 ;
goto V_180;
}
}
if ( ! V_68 )
goto V_182;
V_180:
F_51 ( & V_11 -> V_112 . V_171 ) ;
V_15 -> V_50 = F_66 ( V_15 ) ;
F_31 ( L_18 ,
V_15 -> V_50 ? L_19 : L_20 ) ;
if ( F_10 ( V_11 ) ) {
F_20 ( V_60 ,
F_5 ( V_60 ) | V_183 ) ;
} else {
F_20 ( V_62 ,
F_5 ( V_62 ) | V_183 ) ;
}
V_88 -> V_96 . V_108 = F_44 ;
if ( F_88 ( & V_88 -> V_96 ) ) {
F_31 ( L_21 ) ;
V_88 -> V_96 . V_108 = NULL ;
}
F_89 ( V_7 ) ;
F_90 ( & V_56 -> V_69 , V_68 , V_142 ) ;
F_91 ( V_7 ) ;
return;
V_182:
F_51 ( & V_11 -> V_112 . V_171 ) ;
F_31 ( L_22 ) ;
F_56 ( V_7 ) ;
F_92 ( V_3 ) ;
F_54 ( V_15 ) ;
F_54 ( V_88 ) ;
return;
}
