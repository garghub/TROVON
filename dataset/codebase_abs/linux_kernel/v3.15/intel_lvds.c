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
static void F_35 ( struct V_8 * V_3 )
{
}
static enum V_81
F_36 ( struct V_6 * V_7 , bool V_82 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_81 V_83 ;
F_31 ( L_5 ,
V_7 -> V_4 . V_84 , F_37 ( V_7 ) ) ;
V_83 = F_38 ( V_11 ) ;
if ( V_83 != V_85 )
return V_83 ;
return V_86 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_5 * V_87 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_42 * V_67 ;
if ( ! F_40 ( V_87 -> V_4 . V_88 ) )
return F_41 ( V_7 , V_87 -> V_4 . V_88 ) ;
V_67 = F_42 ( V_11 , V_87 -> V_4 . V_69 . V_68 ) ;
if ( V_67 == NULL )
return 0 ;
F_43 ( V_7 , V_67 ) ;
return 1 ;
}
static int F_44 ( const struct V_89 * V_84 )
{
F_45 ( L_6 , V_84 -> V_90 ) ;
return 1 ;
}
static int F_46 ( struct V_91 * V_92 , unsigned long V_93 ,
void * V_94 )
{
struct V_5 * V_87 =
F_2 ( V_92 , struct V_5 , V_95 ) ;
struct V_6 * V_7 = & V_87 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_96 != V_97 )
return V_98 ;
F_47 ( & V_13 -> V_99 ) ;
if ( V_13 -> V_100 == V_101 )
goto exit;
V_7 -> V_83 = V_7 -> V_102 -> V_103 ( V_7 , false ) ;
if ( F_48 ( V_104 ) )
goto exit;
if ( ! F_49 () ) {
V_13 -> V_100 = V_105 ;
goto exit;
}
if ( V_13 -> V_100 == V_106 )
goto exit;
if ( ! F_10 ( V_11 ) ) {
F_50 ( V_11 ) ;
F_51 ( V_11 , true ) ;
F_52 ( V_11 ) ;
}
V_13 -> V_100 = V_106 ;
exit:
F_53 ( & V_13 -> V_99 ) ;
return V_98 ;
}
static void F_54 ( struct V_6 * V_7 )
{
struct V_5 * V_87 =
F_3 ( V_7 ) ;
if ( V_87 -> V_95 . V_107 )
F_55 ( & V_87 -> V_95 ) ;
if ( ! F_40 ( V_87 -> V_4 . V_88 ) )
F_56 ( V_87 -> V_4 . V_88 ) ;
F_57 ( & V_87 -> V_4 . V_69 ) ;
F_58 ( V_7 ) ;
F_56 ( V_7 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_108 * V_109 ,
T_2 V_110 )
{
struct V_56 * V_56 = F_29 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_109 == V_11 -> V_111 . V_112 ) {
struct V_113 * V_41 ;
if ( V_110 == V_114 ) {
F_31 ( L_7 ) ;
return - V_115 ;
}
if ( V_56 -> V_69 . V_80 == V_110 ) {
return 0 ;
}
V_56 -> V_69 . V_80 = V_110 ;
V_41 = F_60 ( V_7 ) -> V_4 . V_41 ;
if ( V_41 && V_41 -> V_116 ) {
F_61 ( V_41 ) ;
}
}
return 0 ;
}
static int T_3 F_62 ( const struct V_89 * V_84 )
{
F_45 ( L_8 , V_84 -> V_90 ) ;
return 1 ;
}
static bool F_63 ( struct V_10 * V_11 ,
T_4 * V_117 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_118 ;
if ( ! V_13 -> V_119 . V_120 )
return true ;
for ( V_118 = 0 ; V_118 < V_13 -> V_119 . V_120 ; V_118 ++ ) {
union V_121 * V_122 = V_13 -> V_119 . V_123 + V_118 ;
struct V_124 * V_125 = & V_122 -> V_126 ;
if ( V_125 -> V_127 != V_128 &&
V_125 -> V_127 != V_129 )
continue;
if ( F_64 ( V_125 -> V_117 ) )
* V_117 = V_125 -> V_117 ;
if ( V_125 -> V_130 )
return true ;
if ( V_13 -> V_131 . V_119 )
return true ;
}
return false ;
}
static int F_65 ( const struct V_89 * V_84 )
{
F_45 ( L_9 , V_84 -> V_90 ) ;
return 1 ;
}
bool F_66 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_67 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_132 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_50 ;
}
}
return false ;
}
static bool F_68 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_93 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_133 . V_134 > 0 )
return V_133 . V_134 == 2 ;
if ( F_48 ( V_135 ) )
return true ;
V_93 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_93 & ~ ( V_136 | V_137 ) ) )
V_93 = V_13 -> V_119 . V_138 ;
return ( V_93 & V_139 ) == V_52 ;
}
static bool F_69 ( struct V_10 * V_11 )
{
if ( F_70 ( V_11 ) || F_6 ( V_11 ) )
return true ;
if ( F_11 ( V_11 ) -> V_33 <= 4 && F_71 ( V_11 ) && ! F_72 ( V_11 ) )
return true ;
return false ;
}
void F_73 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_87 ;
struct V_56 * V_56 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_42 * V_140 ;
struct V_42 * V_68 = NULL ;
struct V_42 * V_141 = NULL ;
struct V_88 * V_88 ;
struct V_113 * V_41 ;
T_1 V_142 ;
int V_9 ;
T_4 V_143 ;
if ( ! F_69 ( V_11 ) )
return;
if ( F_48 ( V_144 ) )
return;
V_143 = V_145 ;
if ( ! F_63 ( V_11 , & V_143 ) ) {
F_31 ( L_10 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
if ( ( F_5 ( V_24 ) & V_137 ) == 0 )
return;
if ( V_13 -> V_119 . V_146 ) {
F_31 ( L_11 ) ;
return;
}
}
V_15 = F_74 ( sizeof( * V_15 ) , V_147 ) ;
if ( ! V_15 )
return;
V_87 = F_74 ( sizeof( * V_87 ) , V_147 ) ;
if ( ! V_87 ) {
F_56 ( V_15 ) ;
return;
}
V_15 -> V_57 = V_87 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_56 = & V_87 -> V_4 ;
V_7 = & V_56 -> V_4 ;
F_75 ( V_11 , & V_56 -> V_4 , & V_148 ,
V_149 ) ;
F_76 ( V_11 , & V_8 -> V_4 , & V_150 ,
V_151 ) ;
V_8 -> V_152 = F_21 ;
V_8 -> V_153 = F_13 ;
V_8 -> V_154 = F_30 ;
V_8 -> V_155 = F_35 ;
V_8 -> V_156 = F_26 ;
V_8 -> V_157 = F_4 ;
V_8 -> V_158 = F_9 ;
V_56 -> V_157 = V_159 ;
V_56 -> V_160 = V_161 ;
F_77 ( V_56 , V_8 ) ;
V_8 -> type = V_132 ;
V_8 -> V_162 = 0 ;
if ( F_10 ( V_11 ) )
V_8 -> V_163 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_78 ( V_11 ) )
V_8 -> V_163 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_163 = ( 1 << 1 ) ;
F_79 ( V_7 , & V_164 ) ;
V_7 -> V_165 . V_166 = V_167 ;
V_7 -> V_168 = false ;
V_7 -> V_169 = false ;
if ( F_10 ( V_11 ) ) {
V_15 -> V_17 = V_24 ;
} else {
V_15 -> V_17 = V_25 ;
}
F_80 ( V_11 ) ;
F_81 ( & V_7 -> V_4 ,
V_11 -> V_111 . V_112 ,
V_170 ) ;
V_56 -> V_69 . V_80 = V_170 ;
F_47 ( & V_11 -> V_111 . V_171 ) ;
V_88 = F_82 ( V_7 , F_83 ( V_13 , V_143 ) ) ;
if ( V_88 ) {
if ( F_41 ( V_7 , V_88 ) ) {
F_84 ( V_7 ,
V_88 ) ;
} else {
F_56 ( V_88 ) ;
V_88 = F_85 ( - V_115 ) ;
}
} else {
V_88 = F_85 ( - V_172 ) ;
}
V_87 -> V_4 . V_88 = V_88 ;
if ( F_40 ( V_88 ) ) {
V_7 -> V_165 . V_173 = 0 ;
V_7 -> V_165 . V_174 = 200 ;
V_7 -> V_165 . V_175 = 0 ;
V_7 -> V_165 . V_176 = 200 ;
}
F_67 (scan, &connector->probed_modes, head) {
if ( V_140 -> type & V_177 ) {
F_31 ( L_12 ) ;
F_86 ( V_140 ) ;
V_68 = F_42 ( V_11 , V_140 ) ;
if ( V_68 ) {
V_141 =
F_87 ( V_11 ,
V_68 , V_7 ) ;
if ( V_141 != NULL &&
V_133 . V_178 ) {
V_13 -> V_179 = true ;
V_13 -> V_178 =
V_141 -> clock ;
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
if ( V_13 -> V_119 . V_181 ) {
F_31 ( L_16 ) ;
F_86 ( V_13 -> V_119 . V_181 ) ;
V_68 = F_42 ( V_11 , V_13 -> V_119 . V_181 ) ;
if ( V_68 ) {
V_68 -> type |= V_177 ;
goto V_180;
}
}
if ( F_10 ( V_11 ) )
goto V_182;
V_142 = F_5 ( V_25 ) ;
V_9 = ( V_142 & V_47 ) ? 1 : 0 ;
V_41 = F_88 ( V_11 , V_9 ) ;
if ( V_41 && ( V_142 & V_18 ) ) {
V_68 = F_89 ( V_11 , V_41 ) ;
if ( V_68 ) {
F_31 ( L_17 ) ;
F_86 ( V_68 ) ;
V_68 -> type |= V_177 ;
goto V_180;
}
}
if ( ! V_68 )
goto V_182;
V_180:
F_53 ( & V_11 -> V_111 . V_171 ) ;
V_15 -> V_50 = F_68 ( V_15 ) ;
F_31 ( L_18 ,
V_15 -> V_50 ? L_19 : L_20 ) ;
if ( F_10 ( V_11 ) ) {
F_20 ( V_60 ,
F_5 ( V_60 ) | V_183 ) ;
} else {
F_20 ( V_62 ,
F_5 ( V_62 ) | V_183 ) ;
}
V_87 -> V_95 . V_107 = F_46 ;
if ( F_90 ( & V_87 -> V_95 ) ) {
F_31 ( L_21 ) ;
V_87 -> V_95 . V_107 = NULL ;
}
F_91 ( V_7 ) ;
F_92 ( & V_56 -> V_69 , V_68 , V_141 ) ;
F_93 ( V_7 ) ;
return;
V_182:
F_53 ( & V_11 -> V_111 . V_171 ) ;
F_31 ( L_22 ) ;
F_58 ( V_7 ) ;
F_94 ( V_3 ) ;
F_56 ( V_15 ) ;
F_56 ( V_87 ) ;
return;
}
