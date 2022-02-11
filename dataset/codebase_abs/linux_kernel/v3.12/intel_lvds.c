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
struct V_37 * V_38 = F_13 ( V_3 -> V_4 . V_38 ) ;
const struct V_39 * V_31 =
& V_38 -> V_40 . V_31 ;
int V_9 = V_38 -> V_9 ;
T_1 V_41 ;
if ( F_10 ( V_11 ) ) {
F_14 ( V_13 , V_9 ) ;
F_15 ( V_13 ,
F_16 ( V_38 ) ) ;
} else {
F_17 ( V_13 , V_9 ) ;
}
V_41 = F_5 ( V_15 -> V_17 ) ;
V_41 |= V_18 | V_42 ;
if ( F_6 ( V_11 ) ) {
V_41 &= ~ V_43 ;
V_41 |= F_18 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_41 |= V_44 ;
} else {
V_41 &= ~ V_44 ;
}
}
V_41 &= ~ V_45 ;
V_41 |= V_38 -> V_40 . V_34 . V_46 ;
if ( V_15 -> V_47 )
V_41 |= V_48 | V_49 ;
else
V_41 &= ~ ( V_48 | V_49 ) ;
if ( F_11 ( V_11 ) -> V_32 == 4 ) {
if ( V_38 -> V_40 . V_50 && V_38 -> V_40 . V_51 == 18 )
V_41 |= V_52 ;
else
V_41 &= ~ V_52 ;
}
V_41 &= ~ ( V_25 | V_28 ) ;
if ( V_31 -> V_22 & V_26 )
V_41 |= V_25 ;
if ( V_31 -> V_22 & V_29 )
V_41 |= V_28 ;
F_19 ( V_15 -> V_17 , V_41 ) ;
}
static void F_20 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_37 * V_37 = F_13 ( V_3 -> V_4 . V_38 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_53 , V_54 ;
if ( F_10 ( V_11 ) ) {
V_53 = V_55 ;
V_54 = V_56 ;
} else {
V_53 = V_57 ;
V_54 = V_58 ;
}
F_19 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) | V_18 ) ;
F_19 ( V_53 , F_5 ( V_53 ) | V_59 ) ;
F_21 ( V_15 -> V_17 ) ;
if ( F_22 ( ( F_5 ( V_54 ) & V_60 ) != 0 , 1000 ) )
F_23 ( L_1 ) ;
F_24 ( V_11 , V_37 -> V_9 ) ;
}
static void F_25 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_53 , V_54 ;
if ( F_10 ( V_11 ) ) {
V_53 = V_55 ;
V_54 = V_56 ;
} else {
V_53 = V_57 ;
V_54 = V_58 ;
}
F_26 ( V_11 ) ;
F_19 ( V_53 , F_5 ( V_53 ) & ~ V_59 ) ;
if ( F_22 ( ( F_5 ( V_54 ) & V_60 ) == 0 , 1000 ) )
F_23 ( L_2 ) ;
F_19 ( V_15 -> V_17 , F_5 ( V_15 -> V_17 ) & ~ V_18 ) ;
F_21 ( V_15 -> V_17 ) ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_39 * V_61 )
{
struct V_62 * V_62 = F_28 ( V_7 ) ;
struct V_39 * V_63 = V_62 -> V_64 . V_63 ;
if ( V_61 -> V_65 > V_63 -> V_65 )
return V_66 ;
if ( V_61 -> V_67 > V_63 -> V_67 )
return V_66 ;
return V_68 ;
}
static bool F_29 ( struct V_8 * V_8 ,
struct V_19 * V_20 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_62 * V_62 =
& V_15 -> V_69 -> V_4 ;
struct V_39 * V_31 = & V_20 -> V_31 ;
struct V_37 * V_37 = V_15 -> V_4 . V_70 ;
unsigned int V_71 ;
if ( F_11 ( V_11 ) -> V_32 < 4 && V_37 -> V_9 == 0 ) {
F_23 ( L_3 ) ;
return false ;
}
if ( ( F_5 ( V_15 -> V_17 ) & V_72 ) ==
V_73 )
V_71 = 8 * 3 ;
else
V_71 = 6 * 3 ;
if ( V_71 != V_20 -> V_51 && ! V_20 -> V_74 ) {
F_30 ( L_4 ,
V_20 -> V_51 , V_71 ) ;
V_20 -> V_51 = V_71 ;
}
F_31 ( V_62 -> V_64 . V_63 ,
V_31 ) ;
if ( F_10 ( V_11 ) ) {
V_20 -> V_75 = true ;
F_32 ( V_37 , V_20 ,
V_62 -> V_64 . V_76 ) ;
} else {
F_33 ( V_37 , V_20 ,
V_62 -> V_64 . V_76 ) ;
}
return true ;
}
static void F_34 ( struct V_8 * V_3 )
{
}
static enum V_77
F_35 ( struct V_6 * V_7 , bool V_78 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_77 V_79 ;
F_30 ( L_5 ,
V_7 -> V_4 . V_80 , F_36 ( V_7 ) ) ;
V_79 = F_37 ( V_11 ) ;
if ( V_79 != V_81 )
return V_79 ;
return V_82 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_5 * V_83 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_39 * V_61 ;
if ( ! F_39 ( V_83 -> V_4 . V_84 ) )
return F_40 ( V_7 , V_83 -> V_4 . V_84 ) ;
V_61 = F_41 ( V_11 , V_83 -> V_4 . V_64 . V_63 ) ;
if ( V_61 == NULL )
return 0 ;
F_42 ( V_7 , V_61 ) ;
return 1 ;
}
static int F_43 ( const struct V_85 * V_80 )
{
F_44 ( L_6 , V_80 -> V_86 ) ;
return 1 ;
}
static int F_45 ( struct V_87 * V_88 , unsigned long V_89 ,
void * V_90 )
{
struct V_5 * V_83 =
F_2 ( V_88 , struct V_5 , V_91 ) ;
struct V_6 * V_7 = & V_83 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_92 != V_93 )
return V_94 ;
F_46 ( & V_13 -> V_95 ) ;
if ( V_13 -> V_96 == V_97 )
goto exit;
V_7 -> V_79 = V_7 -> V_98 -> V_99 ( V_7 , false ) ;
if ( F_47 ( V_100 ) )
goto exit;
if ( ! F_48 () ) {
V_13 -> V_96 = V_101 ;
goto exit;
}
if ( V_13 -> V_96 == V_102 )
goto exit;
F_49 ( V_11 ) ;
F_50 ( V_11 , true ) ;
F_51 ( V_11 ) ;
V_13 -> V_96 = V_102 ;
exit:
F_52 ( & V_13 -> V_95 ) ;
return V_94 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_5 * V_83 =
F_3 ( V_7 ) ;
if ( V_83 -> V_91 . V_103 )
F_54 ( & V_83 -> V_91 ) ;
if ( ! F_39 ( V_83 -> V_4 . V_84 ) )
F_55 ( V_83 -> V_4 . V_84 ) ;
F_56 ( & V_83 -> V_4 . V_64 ) ;
F_57 ( V_7 ) ;
F_58 ( V_7 ) ;
F_55 ( V_7 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_104 * V_105 ,
T_2 V_106 )
{
struct V_62 * V_62 = F_28 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_105 == V_11 -> V_107 . V_108 ) {
struct V_109 * V_38 ;
if ( V_106 == V_110 ) {
F_30 ( L_7 ) ;
return - V_111 ;
}
if ( V_62 -> V_64 . V_76 == V_106 ) {
return 0 ;
}
V_62 -> V_64 . V_76 = V_106 ;
V_38 = F_60 ( V_7 ) -> V_4 . V_38 ;
if ( V_38 && V_38 -> V_112 ) {
F_61 ( V_38 ) ;
}
}
return 0 ;
}
static int T_3 F_62 ( const struct V_85 * V_80 )
{
F_44 ( L_8 , V_80 -> V_86 ) ;
return 1 ;
}
static void F_63 ( struct V_10 * V_11 ,
struct V_39 * V_63 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_39 * V_113 ;
int V_114 ;
V_114 = V_63 -> clock ;
F_64 (scan, &connector->probed_modes, head) {
if ( V_113 -> V_65 == V_63 -> V_65 &&
V_113 -> V_115 == V_63 -> V_115 &&
V_113 -> V_116 == V_63 -> V_116 &&
V_113 -> V_117 == V_63 -> V_117 &&
V_113 -> V_67 == V_63 -> V_67 &&
V_113 -> V_118 == V_63 -> V_118 &&
V_113 -> V_119 == V_63 -> V_119 &&
V_113 -> V_120 == V_63 -> V_120 ) {
if ( V_113 -> clock < V_114 ) {
V_114 = V_113 -> clock ;
}
}
}
if ( V_114 < V_63 -> clock && V_121 ) {
V_13 -> V_122 = 1 ;
V_13 -> V_123 = V_114 ;
F_30 ( L_9
L_10 ,
V_63 -> clock , V_114 ) ;
}
}
static bool F_65 ( struct V_10 * V_11 ,
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
if ( F_66 ( V_129 -> V_124 ) )
* V_124 = V_129 -> V_124 ;
if ( V_129 -> V_134 )
return true ;
if ( V_13 -> V_135 . V_126 )
return true ;
}
return false ;
}
static int F_67 ( const struct V_85 * V_80 )
{
F_44 ( L_11 , V_80 -> V_86 ) ;
return 1 ;
}
bool F_68 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_64 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( V_3 -> type == V_136 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_47 ;
}
}
return false ;
}
static bool F_69 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_89 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_137 > 0 )
return V_137 == 2 ;
if ( F_47 ( V_138 ) )
return true ;
V_89 = F_5 ( V_15 -> V_17 ) ;
if ( ! ( V_89 & ~ ( V_139 | V_140 ) ) )
V_89 = V_13 -> V_126 . V_141 ;
return ( V_89 & V_142 ) == V_49 ;
}
static bool F_70 ( struct V_10 * V_11 )
{
if ( F_71 ( V_11 ) || F_6 ( V_11 ) )
return true ;
if ( F_11 ( V_11 ) -> V_32 <= 4 && F_72 ( V_11 ) && ! F_73 ( V_11 ) )
return true ;
return false ;
}
void F_74 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_83 ;
struct V_62 * V_62 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_39 * V_113 ;
struct V_39 * V_63 = NULL ;
struct V_84 * V_84 ;
struct V_109 * V_38 ;
T_1 V_143 ;
int V_9 ;
T_4 V_144 ;
if ( ! F_70 ( V_11 ) )
return;
if ( F_47 ( V_145 ) )
return;
V_144 = V_146 ;
if ( ! F_65 ( V_11 , & V_144 ) ) {
F_30 ( L_12 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
if ( ( F_5 ( V_23 ) & V_140 ) == 0 )
return;
if ( V_13 -> V_126 . V_147 ) {
F_30 ( L_13 ) ;
return;
}
}
V_15 = F_75 ( sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_15 )
return;
V_83 = F_75 ( sizeof( struct V_5 ) , V_148 ) ;
if ( ! V_83 ) {
F_55 ( V_15 ) ;
return;
}
V_15 -> V_69 = V_83 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_62 = & V_83 -> V_4 ;
V_7 = & V_62 -> V_4 ;
F_76 ( V_11 , & V_62 -> V_4 , & V_149 ,
V_150 ) ;
F_77 ( V_11 , & V_8 -> V_4 , & V_151 ,
V_152 ) ;
V_8 -> V_153 = F_20 ;
V_8 -> V_154 = F_12 ;
V_8 -> V_155 = F_29 ;
V_8 -> V_156 = F_34 ;
V_8 -> V_157 = F_25 ;
V_8 -> V_158 = F_4 ;
V_8 -> V_159 = F_9 ;
V_62 -> V_158 = V_160 ;
F_78 ( V_62 , V_8 ) ;
V_8 -> type = V_136 ;
V_8 -> V_161 = false ;
if ( F_10 ( V_11 ) )
V_8 -> V_162 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_79 ( V_11 ) )
V_8 -> V_162 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_162 = ( 1 << 1 ) ;
F_80 ( V_7 , & V_163 ) ;
V_7 -> V_164 . V_165 = V_166 ;
V_7 -> V_167 = false ;
V_7 -> V_168 = false ;
if ( F_10 ( V_11 ) ) {
V_15 -> V_17 = V_23 ;
} else {
V_15 -> V_17 = V_24 ;
}
F_81 ( V_11 ) ;
F_82 ( & V_7 -> V_4 ,
V_11 -> V_107 . V_108 ,
V_169 ) ;
V_62 -> V_64 . V_76 = V_169 ;
V_84 = F_83 ( V_7 , F_84 ( V_13 , V_144 ) ) ;
if ( V_84 ) {
if ( F_40 ( V_7 , V_84 ) ) {
F_85 ( V_7 ,
V_84 ) ;
} else {
F_55 ( V_84 ) ;
V_84 = F_86 ( - V_111 ) ;
}
} else {
V_84 = F_86 ( - V_170 ) ;
}
V_83 -> V_4 . V_84 = V_84 ;
if ( F_39 ( V_84 ) ) {
V_7 -> V_164 . V_171 = 0 ;
V_7 -> V_164 . V_172 = 200 ;
V_7 -> V_164 . V_173 = 0 ;
V_7 -> V_164 . V_174 = 200 ;
}
F_64 (scan, &connector->probed_modes, head) {
if ( V_113 -> type & V_175 ) {
F_30 ( L_14 ) ;
F_87 ( V_113 ) ;
V_63 = F_41 ( V_11 , V_113 ) ;
if ( V_63 ) {
F_63 ( V_11 , V_63 ,
V_7 ) ;
goto V_176;
}
}
}
if ( V_13 -> V_126 . V_177 ) {
F_30 ( L_15 ) ;
F_87 ( V_13 -> V_126 . V_177 ) ;
V_63 = F_41 ( V_11 , V_13 -> V_126 . V_177 ) ;
if ( V_63 ) {
V_63 -> type |= V_175 ;
goto V_176;
}
}
if ( F_10 ( V_11 ) )
goto V_178;
V_143 = F_5 ( V_24 ) ;
V_9 = ( V_143 & V_44 ) ? 1 : 0 ;
V_38 = F_88 ( V_11 , V_9 ) ;
if ( V_38 && ( V_143 & V_18 ) ) {
V_63 = F_89 ( V_11 , V_38 ) ;
if ( V_63 ) {
F_30 ( L_16 ) ;
F_87 ( V_63 ) ;
V_63 -> type |= V_175 ;
goto V_176;
}
}
if ( ! V_63 )
goto V_178;
V_176:
V_15 -> V_47 = F_69 ( V_15 ) ;
F_30 ( L_17 ,
V_15 -> V_47 ? L_18 : L_19 ) ;
if ( F_10 ( V_11 ) ) {
F_19 ( V_55 ,
F_5 ( V_55 ) | V_179 ) ;
} else {
F_19 ( V_57 ,
F_5 ( V_57 ) | V_179 ) ;
}
V_83 -> V_91 . V_103 = F_45 ;
if ( F_90 ( & V_83 -> V_91 ) ) {
F_30 ( L_20 ) ;
V_83 -> V_91 . V_103 = NULL ;
}
F_91 ( V_7 ) ;
F_92 ( & V_62 -> V_64 , V_63 ) ;
F_93 ( V_7 ) ;
return;
V_178:
F_30 ( L_21 ) ;
F_58 ( V_7 ) ;
F_94 ( V_3 ) ;
if ( V_63 )
F_95 ( V_11 , V_63 ) ;
F_55 ( V_15 ) ;
F_55 ( V_83 ) ;
return;
}
