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
if ( F_10 ( V_11 ) )
V_21 = V_23 ;
else
V_21 = V_24 ;
V_16 = F_5 ( V_21 ) ;
if ( V_16 & V_25 )
V_22 |= V_26 ;
else
V_22 |= V_27 ;
if ( V_16 & V_28 )
V_22 |= V_29 ;
else
V_22 |= V_30 ;
V_20 -> V_31 . V_22 |= V_22 ;
if ( F_11 ( V_11 ) -> V_32 < 4 ) {
V_16 = F_5 ( V_33 ) ;
V_20 -> V_34 . V_35 |= V_16 & V_36 ;
}
}
static void F_12 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_37 * V_37 = F_13 ( V_3 -> V_4 . V_38 ) ;
struct V_39 * V_40 =
V_15 -> V_41 -> V_4 . V_42 . V_40 ;
int V_9 = V_37 -> V_9 ;
T_1 V_43 ;
V_43 = F_5 ( V_15 -> V_17 ) ;
V_43 |= V_18 | V_44 ;
if ( F_6 ( V_11 ) ) {
V_43 &= ~ V_45 ;
V_43 |= F_14 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_43 |= V_46 ;
} else {
V_43 &= ~ V_46 ;
}
}
V_43 &= ~ V_47 ;
V_43 |= V_37 -> V_48 . V_34 . V_49 ;
if ( V_15 -> V_50 )
V_43 |= V_51 | V_52 ;
else
V_43 &= ~ ( V_51 | V_52 ) ;
if ( F_11 ( V_11 ) -> V_32 == 4 ) {
if ( V_37 -> V_48 . V_53 &&
V_37 -> V_48 . V_54 == 18 )
V_43 |= V_55 ;
else
V_43 &= ~ V_55 ;
}
V_43 &= ~ ( V_25 | V_28 ) ;
if ( V_40 -> V_22 & V_26 )
V_43 |= V_25 ;
if ( V_40 -> V_22 & V_29 )
V_43 |= V_28 ;
F_15 ( V_15 -> V_17 , V_43 ) ;
}
static void F_16 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_37 * V_37 = F_13 ( V_3 -> V_4 . V_38 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_56 , V_57 ;
if ( F_10 ( V_11 ) ) {
V_56 = V_58 ;
V_57 = V_59 ;
} else {
V_56 = V_60 ;
V_57 = V_61 ;
}
F_15 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) | V_18 ) ;
F_15 ( V_56 , F_5 ( V_56 ) | V_62 ) ;
F_17 ( V_15 -> V_17 ) ;
if ( F_18 ( ( F_5 ( V_57 ) & V_63 ) != 0 , 1000 ) )
F_19 ( L_1 ) ;
F_20 ( V_11 , V_37 -> V_9 ) ;
}
static void F_21 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_56 , V_57 ;
if ( F_10 ( V_11 ) ) {
V_56 = V_58 ;
V_57 = V_59 ;
} else {
V_56 = V_60 ;
V_57 = V_61 ;
}
F_22 ( V_11 ) ;
F_15 ( V_56 , F_5 ( V_56 ) & ~ V_62 ) ;
if ( F_18 ( ( F_5 ( V_57 ) & V_63 ) == 0 , 1000 ) )
F_19 ( L_2 ) ;
F_15 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) & ~ V_18 ) ;
F_17 ( V_15 -> V_17 ) ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_39 * V_64 )
{
struct V_65 * V_65 = F_24 ( V_7 ) ;
struct V_39 * V_40 = V_65 -> V_42 . V_40 ;
if ( V_64 -> V_66 > V_40 -> V_66 )
return V_67 ;
if ( V_64 -> V_68 > V_40 -> V_68 )
return V_67 ;
return V_69 ;
}
static bool F_25 ( struct V_8 * V_8 ,
struct V_19 * V_20 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_65 * V_65 =
& V_15 -> V_41 -> V_4 ;
struct V_39 * V_31 = & V_20 -> V_31 ;
struct V_37 * V_37 = V_15 -> V_4 . V_70 ;
unsigned int V_71 ;
if ( F_11 ( V_11 ) -> V_32 < 4 && V_37 -> V_9 == 0 ) {
F_19 ( L_3 ) ;
return false ;
}
if ( ( F_5 ( V_15 -> V_17 ) & V_72 ) ==
V_73 )
V_71 = 8 * 3 ;
else
V_71 = 6 * 3 ;
if ( V_71 != V_20 -> V_54 && ! V_20 -> V_74 ) {
F_26 ( L_4 ,
V_20 -> V_54 , V_71 ) ;
V_20 -> V_54 = V_71 ;
}
F_27 ( V_65 -> V_42 . V_40 ,
V_31 ) ;
if ( F_10 ( V_11 ) ) {
V_20 -> V_75 = true ;
F_28 ( V_37 , V_20 ,
V_65 -> V_42 . V_76 ) ;
} else {
F_29 ( V_37 , V_20 ,
V_65 -> V_42 . V_76 ) ;
}
return true ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_39 * V_64 ,
struct V_39 * V_31 )
{
}
static enum V_77
F_31 ( struct V_6 * V_7 , bool V_78 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_77 V_79 ;
V_79 = F_32 ( V_11 ) ;
if ( V_79 != V_80 )
return V_79 ;
return V_81 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_5 * V_82 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_39 * V_64 ;
if ( ! F_34 ( V_82 -> V_4 . V_83 ) )
return F_35 ( V_7 , V_82 -> V_4 . V_83 ) ;
V_64 = F_36 ( V_11 , V_82 -> V_4 . V_42 . V_40 ) ;
if ( V_64 == NULL )
return 0 ;
F_37 ( V_7 , V_64 ) ;
return 1 ;
}
static int F_38 ( const struct V_84 * V_85 )
{
F_39 ( L_5 , V_85 -> V_86 ) ;
return 1 ;
}
static int F_40 ( struct V_87 * V_88 , unsigned long V_89 ,
void * V_90 )
{
struct V_5 * V_82 =
F_2 ( V_88 , struct V_5 , V_91 ) ;
struct V_6 * V_7 = & V_82 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_92 != V_93 )
return V_94 ;
F_41 ( & V_13 -> V_95 ) ;
if ( V_13 -> V_96 == V_97 )
goto exit;
V_7 -> V_79 = V_7 -> V_98 -> V_99 ( V_7 , false ) ;
if ( F_42 ( V_100 ) )
goto exit;
if ( ! F_43 () ) {
V_13 -> V_96 = V_101 ;
goto exit;
}
if ( V_13 -> V_96 == V_102 )
goto exit;
F_44 ( V_11 ) ;
F_45 ( V_11 , true ) ;
F_46 ( V_11 ) ;
V_13 -> V_96 = V_102 ;
exit:
F_47 ( & V_13 -> V_95 ) ;
return V_94 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_5 * V_82 =
F_3 ( V_7 ) ;
if ( V_82 -> V_91 . V_103 )
F_49 ( & V_82 -> V_91 ) ;
if ( ! F_34 ( V_82 -> V_4 . V_83 ) )
F_50 ( V_82 -> V_4 . V_83 ) ;
F_51 ( & V_82 -> V_4 . V_42 ) ;
F_52 ( V_7 ) ;
F_53 ( V_7 ) ;
F_50 ( V_7 ) ;
}
static int F_54 ( struct V_6 * V_7 ,
struct V_104 * V_105 ,
T_2 V_106 )
{
struct V_65 * V_65 = F_24 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_105 == V_11 -> V_107 . V_108 ) {
struct V_109 * V_38 ;
if ( V_106 == V_110 ) {
F_26 ( L_6 ) ;
return - V_111 ;
}
if ( V_65 -> V_42 . V_76 == V_106 ) {
return 0 ;
}
V_65 -> V_42 . V_76 = V_106 ;
V_38 = F_55 ( V_7 ) -> V_4 . V_38 ;
if ( V_38 && V_38 -> V_112 ) {
F_56 ( V_38 ) ;
}
}
return 0 ;
}
static int T_3 F_57 ( const struct V_84 * V_85 )
{
F_39 ( L_7 , V_85 -> V_86 ) ;
return 1 ;
}
static void F_58 ( struct V_10 * V_11 ,
struct V_39 * V_40 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_39 * V_113 ;
int V_114 ;
V_114 = V_40 -> clock ;
F_59 (scan, &connector->probed_modes, head) {
if ( V_113 -> V_66 == V_40 -> V_66 &&
V_113 -> V_115 == V_40 -> V_115 &&
V_113 -> V_116 == V_40 -> V_116 &&
V_113 -> V_117 == V_40 -> V_117 &&
V_113 -> V_68 == V_40 -> V_68 &&
V_113 -> V_118 == V_40 -> V_118 &&
V_113 -> V_119 == V_40 -> V_119 &&
V_113 -> V_120 == V_40 -> V_120 ) {
if ( V_113 -> clock < V_114 ) {
V_114 = V_113 -> clock ;
}
}
}
if ( V_114 < V_40 -> clock && V_121 ) {
V_13 -> V_122 = 1 ;
V_13 -> V_123 = V_114 ;
F_26 ( L_8
L_9 ,
V_40 -> clock , V_114 ) ;
}
}
static bool F_60 ( struct V_10 * V_11 ,
T_4 * V_124 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_125 ;
if ( ! V_13 -> V_126 . V_127 )
return true ;
for ( V_125 = 0 ; V_125 < V_13 -> V_126 . V_127 ; V_125 ++ ) {
struct V_128 * V_129 = V_13 -> V_126 . V_130 + V_125 ;
if ( V_129 -> V_131 != V_132 &&
V_129 -> V_131 != V_133 )
continue;
if ( F_61 ( V_129 -> V_124 ) )
* V_124 = V_129 -> V_124 ;
if ( V_129 -> V_134 )
return true ;
if ( V_13 -> V_135 . V_126 )
return true ;
}
return false ;
}
static int F_62 ( const struct V_84 * V_85 )
{
F_39 ( L_10 , V_85 -> V_86 ) ;
return 1 ;
}
bool F_63 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_59 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_136 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_50 ;
}
}
return false ;
}
static bool F_64 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_89 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_137 > 0 )
return V_137 == 2 ;
if ( F_42 ( V_138 ) )
return true ;
V_89 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_89 & ~ ( V_139 | V_140 ) ) )
V_89 = V_13 -> V_126 . V_141 ;
return ( V_89 & V_142 ) == V_52 ;
}
static bool F_65 ( struct V_10 * V_11 )
{
if ( F_66 ( V_11 ) || F_6 ( V_11 ) )
return true ;
if ( F_11 ( V_11 ) -> V_32 <= 4 && F_67 ( V_11 ) && ! F_68 ( V_11 ) )
return true ;
return false ;
}
void F_69 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_82 ;
struct V_65 * V_65 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_39 * V_113 ;
struct V_39 * V_40 = NULL ;
struct V_83 * V_83 ;
struct V_109 * V_38 ;
T_1 V_143 ;
int V_9 ;
T_4 V_144 ;
if ( ! F_65 ( V_11 ) )
return;
if ( F_42 ( V_145 ) )
return;
V_144 = V_146 ;
if ( ! F_60 ( V_11 , & V_144 ) ) {
F_26 ( L_11 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
if ( ( F_5 ( V_23 ) & V_140 ) == 0 )
return;
if ( V_13 -> V_126 . V_147 ) {
F_26 ( L_12 ) ;
return;
}
}
V_15 = F_70 ( sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_15 )
return;
V_82 = F_70 ( sizeof( struct V_5 ) , V_148 ) ;
if ( ! V_82 ) {
F_50 ( V_15 ) ;
return;
}
V_15 -> V_41 = V_82 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_65 = & V_82 -> V_4 ;
V_7 = & V_65 -> V_4 ;
F_71 ( V_11 , & V_65 -> V_4 , & V_149 ,
V_150 ) ;
F_72 ( V_11 , & V_8 -> V_4 , & V_151 ,
V_152 ) ;
V_8 -> V_153 = F_16 ;
V_8 -> V_154 = F_12 ;
V_8 -> V_155 = F_25 ;
V_8 -> V_156 = F_21 ;
V_8 -> V_157 = F_4 ;
V_8 -> V_158 = F_9 ;
V_65 -> V_157 = V_159 ;
F_73 ( V_65 , V_8 ) ;
V_8 -> type = V_136 ;
V_8 -> V_160 = false ;
if ( F_10 ( V_11 ) )
V_8 -> V_161 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_74 ( V_11 ) )
V_8 -> V_161 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_161 = ( 1 << 1 ) ;
F_75 ( V_3 , & V_162 ) ;
F_76 ( V_7 , & V_163 ) ;
V_7 -> V_164 . V_165 = V_166 ;
V_7 -> V_167 = false ;
V_7 -> V_168 = false ;
if ( F_10 ( V_11 ) ) {
V_15 -> V_17 = V_23 ;
} else {
V_15 -> V_17 = V_24 ;
}
F_77 ( V_11 ) ;
F_78 ( & V_7 -> V_4 ,
V_11 -> V_107 . V_108 ,
V_169 ) ;
V_65 -> V_42 . V_76 = V_169 ;
V_83 = F_79 ( V_7 , F_80 ( V_13 , V_144 ) ) ;
if ( V_83 ) {
if ( F_35 ( V_7 , V_83 ) ) {
F_81 ( V_7 ,
V_83 ) ;
} else {
F_50 ( V_83 ) ;
V_83 = F_82 ( - V_111 ) ;
}
} else {
V_83 = F_82 ( - V_170 ) ;
}
V_82 -> V_4 . V_83 = V_83 ;
if ( F_34 ( V_83 ) ) {
V_7 -> V_164 . V_171 = 0 ;
V_7 -> V_164 . V_172 = 200 ;
V_7 -> V_164 . V_173 = 0 ;
V_7 -> V_164 . V_174 = 200 ;
}
F_59 (scan, &connector->probed_modes, head) {
if ( V_113 -> type & V_175 ) {
F_26 ( L_13 ) ;
F_83 ( V_113 ) ;
V_40 = F_36 ( V_11 , V_113 ) ;
if ( V_40 ) {
F_58 ( V_11 , V_40 ,
V_7 ) ;
goto V_176;
}
}
}
if ( V_13 -> V_126 . V_177 ) {
F_26 ( L_14 ) ;
F_83 ( V_13 -> V_126 . V_177 ) ;
V_40 = F_36 ( V_11 , V_13 -> V_126 . V_177 ) ;
if ( V_40 ) {
V_40 -> type |= V_175 ;
goto V_176;
}
}
if ( F_10 ( V_11 ) )
goto V_178;
V_143 = F_5 ( V_24 ) ;
V_9 = ( V_143 & V_46 ) ? 1 : 0 ;
V_38 = F_84 ( V_11 , V_9 ) ;
if ( V_38 && ( V_143 & V_18 ) ) {
V_40 = F_85 ( V_11 , V_38 ) ;
if ( V_40 ) {
F_26 ( L_15 ) ;
F_83 ( V_40 ) ;
V_40 -> type |= V_175 ;
goto V_176;
}
}
if ( ! V_40 )
goto V_178;
V_176:
V_15 -> V_50 = F_64 ( V_15 ) ;
F_26 ( L_16 ,
V_15 -> V_50 ? L_17 : L_18 ) ;
if ( F_10 ( V_11 ) ) {
F_15 ( V_58 ,
F_5 ( V_58 ) | V_179 ) ;
} else {
F_15 ( V_60 ,
F_5 ( V_60 ) | V_179 ) ;
}
V_82 -> V_91 . V_103 = F_40 ;
if ( F_86 ( & V_82 -> V_91 ) ) {
F_26 ( L_19 ) ;
V_82 -> V_91 . V_103 = NULL ;
}
F_87 ( V_7 ) ;
F_88 ( & V_65 -> V_42 , V_40 ) ;
F_89 ( V_7 ) ;
return;
V_178:
F_26 ( L_20 ) ;
F_53 ( V_7 ) ;
F_90 ( V_3 ) ;
if ( V_40 )
F_91 ( V_11 , V_40 ) ;
F_50 ( V_15 ) ;
F_50 ( V_82 ) ;
return;
}
