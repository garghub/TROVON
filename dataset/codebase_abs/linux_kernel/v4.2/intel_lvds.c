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
enum V_16 V_17 ;
T_1 V_18 ;
V_17 = F_5 ( V_3 ) ;
if ( ! F_6 ( V_13 , V_17 ) )
return false ;
V_18 = F_7 ( V_15 -> V_19 ) ;
if ( ! ( V_18 & V_20 ) )
return false ;
if ( F_8 ( V_11 ) )
* V_9 = F_9 ( V_18 ) ;
else
* V_9 = F_10 ( V_18 ) ;
return true ;
}
static void F_11 ( struct V_8 * V_3 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_23 , V_18 , V_24 = 0 ;
int V_25 ;
if ( F_12 ( V_11 ) )
V_23 = V_26 ;
else
V_23 = V_27 ;
V_18 = F_7 ( V_23 ) ;
if ( V_18 & V_28 )
V_24 |= V_29 ;
else
V_24 |= V_30 ;
if ( V_18 & V_31 )
V_24 |= V_32 ;
else
V_24 |= V_33 ;
V_22 -> V_4 . V_34 . V_24 |= V_24 ;
if ( F_13 ( V_11 ) -> V_35 < 4 ) {
V_18 = F_7 ( V_36 ) ;
V_22 -> V_37 . V_38 |= V_18 & V_39 ;
}
V_25 = V_22 -> V_40 ;
if ( F_12 ( V_13 -> V_11 ) )
F_14 ( V_22 , V_25 ) ;
V_22 -> V_4 . V_34 . V_41 = V_25 ;
}
static void F_15 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_42 * V_43 = F_16 ( V_3 -> V_4 . V_43 ) ;
const struct V_44 * V_34 =
& V_43 -> V_45 -> V_4 . V_34 ;
int V_9 = V_43 -> V_9 ;
T_1 V_46 ;
if ( F_12 ( V_11 ) ) {
F_17 ( V_13 , V_9 ) ;
F_18 ( V_13 ,
F_19 ( V_43 ) ) ;
} else {
F_20 ( V_13 , V_9 ) ;
}
V_46 = F_7 ( V_15 -> V_19 ) ;
V_46 |= V_20 | V_47 ;
if ( F_8 ( V_11 ) ) {
V_46 &= ~ V_48 ;
V_46 |= F_21 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_46 |= V_49 ;
} else {
V_46 &= ~ V_49 ;
}
}
V_46 &= ~ V_50 ;
V_46 |= V_43 -> V_45 -> V_37 . V_51 ;
if ( V_15 -> V_52 )
V_46 |= V_53 | V_54 ;
else
V_46 &= ~ ( V_53 | V_54 ) ;
V_46 &= ~ V_55 ;
V_46 |= V_15 -> V_56 ;
if ( F_13 ( V_11 ) -> V_35 == 4 ) {
if ( V_43 -> V_45 -> V_57 && V_43 -> V_45 -> V_58 == 18 )
V_46 |= V_59 ;
else
V_46 &= ~ V_59 ;
}
V_46 &= ~ ( V_28 | V_31 ) ;
if ( V_34 -> V_24 & V_29 )
V_46 |= V_28 ;
if ( V_34 -> V_24 & V_32 )
V_46 |= V_31 ;
F_22 ( V_15 -> V_19 , V_46 ) ;
}
static void F_23 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_60 * V_60 =
& V_15 -> V_61 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_62 , V_63 ;
if ( F_12 ( V_11 ) ) {
V_62 = V_64 ;
V_63 = V_65 ;
} else {
V_62 = V_66 ;
V_63 = V_67 ;
}
F_22 ( V_15 -> V_19 , F_7 ( V_15 -> V_19 ) | V_20 ) ;
F_22 ( V_62 , F_7 ( V_62 ) | V_68 ) ;
F_24 ( V_15 -> V_19 ) ;
if ( F_25 ( ( F_7 ( V_63 ) & V_69 ) != 0 , 1000 ) )
F_26 ( L_1 ) ;
F_27 ( V_60 ) ;
}
static void F_28 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_60 * V_60 =
& V_15 -> V_61 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_62 , V_63 ;
if ( F_12 ( V_11 ) ) {
V_62 = V_64 ;
V_63 = V_65 ;
} else {
V_62 = V_66 ;
V_63 = V_67 ;
}
F_29 ( V_60 ) ;
F_22 ( V_62 , F_7 ( V_62 ) & ~ V_68 ) ;
if ( F_25 ( ( F_7 ( V_63 ) & V_69 ) == 0 , 1000 ) )
F_26 ( L_2 ) ;
F_22 ( V_15 -> V_19 , F_7 ( V_15 -> V_19 ) & ~ V_20 ) ;
F_24 ( V_15 -> V_19 ) ;
}
static enum V_70
F_30 ( struct V_6 * V_7 ,
struct V_44 * V_71 )
{
struct V_60 * V_60 = F_31 ( V_7 ) ;
struct V_44 * V_72 = V_60 -> V_73 . V_72 ;
if ( V_71 -> V_74 > V_72 -> V_74 )
return V_75 ;
if ( V_71 -> V_76 > V_72 -> V_76 )
return V_75 ;
return V_77 ;
}
static bool F_32 ( struct V_8 * V_8 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_60 * V_60 =
& V_15 -> V_61 -> V_4 ;
struct V_44 * V_34 = & V_22 -> V_4 . V_34 ;
struct V_42 * V_42 = F_16 ( V_22 -> V_4 . V_43 ) ;
unsigned int V_78 ;
if ( F_13 ( V_11 ) -> V_35 < 4 && V_42 -> V_9 == 0 ) {
F_26 ( L_3 ) ;
return false ;
}
if ( V_15 -> V_56 == V_79 )
V_78 = 8 * 3 ;
else
V_78 = 6 * 3 ;
if ( V_78 != V_22 -> V_58 && ! V_22 -> V_80 ) {
F_33 ( L_4 ,
V_22 -> V_58 , V_78 ) ;
V_22 -> V_58 = V_78 ;
}
F_34 ( V_60 -> V_73 . V_72 ,
V_34 ) ;
if ( F_12 ( V_11 ) ) {
V_22 -> V_81 = true ;
F_35 ( V_42 , V_22 ,
V_60 -> V_73 . V_82 ) ;
} else {
F_36 ( V_42 , V_22 ,
V_60 -> V_73 . V_82 ) ;
}
return true ;
}
static enum V_83
F_37 ( struct V_6 * V_7 , bool V_84 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_83 V_85 ;
F_33 ( L_5 ,
V_7 -> V_4 . V_86 , V_7 -> V_87 ) ;
V_85 = F_38 ( V_11 ) ;
if ( V_85 != V_88 )
return V_85 ;
return V_89 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_44 * V_71 ;
if ( ! F_40 ( V_90 -> V_4 . V_91 ) )
return F_41 ( V_7 , V_90 -> V_4 . V_91 ) ;
V_71 = F_42 ( V_11 , V_90 -> V_4 . V_73 . V_72 ) ;
if ( V_71 == NULL )
return 0 ;
F_43 ( V_7 , V_71 ) ;
return 1 ;
}
static int F_44 ( const struct V_92 * V_86 )
{
F_45 ( L_6 , V_86 -> V_93 ) ;
return 1 ;
}
static int F_46 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_5 * V_90 =
F_2 ( V_95 , struct V_5 , V_98 ) ;
struct V_6 * V_7 = & V_90 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_99 != V_100 )
return V_101 ;
F_47 ( & V_13 -> V_102 ) ;
if ( V_13 -> V_103 == V_104 )
goto exit;
V_7 -> V_85 = V_7 -> V_105 -> V_106 ( V_7 , false ) ;
if ( F_48 ( V_107 ) )
goto exit;
if ( ! F_49 () ) {
V_13 -> V_103 = V_108 ;
goto exit;
}
if ( V_13 -> V_103 == V_109 )
goto exit;
if ( ! F_12 ( V_11 ) ) {
F_50 ( V_11 ) ;
F_51 ( V_11 , true ) ;
F_52 ( V_11 ) ;
}
V_13 -> V_103 = V_109 ;
exit:
F_53 ( & V_13 -> V_102 ) ;
return V_101 ;
}
static void F_54 ( struct V_6 * V_7 )
{
struct V_5 * V_90 =
F_3 ( V_7 ) ;
if ( V_90 -> V_98 . V_110 )
F_55 ( & V_90 -> V_98 ) ;
if ( ! F_40 ( V_90 -> V_4 . V_91 ) )
F_56 ( V_90 -> V_4 . V_91 ) ;
F_57 ( & V_90 -> V_4 . V_73 ) ;
F_58 ( V_7 ) ;
F_56 ( V_7 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_111 * V_112 ,
T_2 V_113 )
{
struct V_60 * V_60 = F_31 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_112 == V_11 -> V_114 . V_115 ) {
struct V_116 * V_43 ;
if ( V_113 == V_117 ) {
F_33 ( L_7 ) ;
return - V_118 ;
}
if ( V_60 -> V_73 . V_82 == V_113 ) {
return 0 ;
}
V_60 -> V_73 . V_82 = V_113 ;
V_43 = F_60 ( V_7 ) -> V_4 . V_43 ;
if ( V_43 && V_43 -> V_119 -> V_120 ) {
F_61 ( V_43 ) ;
}
}
return 0 ;
}
static int F_62 ( const struct V_92 * V_86 )
{
F_45 ( L_8 , V_86 -> V_93 ) ;
return 1 ;
}
static bool F_63 ( struct V_10 * V_11 ,
T_3 * V_121 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_122 ;
if ( ! V_13 -> V_123 . V_124 )
return true ;
for ( V_122 = 0 ; V_122 < V_13 -> V_123 . V_124 ; V_122 ++ ) {
union V_125 * V_126 = V_13 -> V_123 . V_127 + V_122 ;
struct V_128 * V_129 = & V_126 -> V_130 ;
if ( V_129 -> V_131 != V_132 &&
V_129 -> V_131 != V_133 )
continue;
if ( F_64 ( V_13 , V_129 -> V_121 ) )
* V_121 = V_129 -> V_121 ;
if ( V_129 -> V_134 )
return true ;
if ( V_13 -> V_135 . V_123 )
return true ;
}
return false ;
}
static int F_65 ( const struct V_92 * V_86 )
{
F_45 ( L_9 , V_86 -> V_93 ) ;
return 1 ;
}
bool F_66 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_67 (dev, encoder) {
if ( V_3 -> type == V_136 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_52 ;
}
}
return false ;
}
static bool F_68 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_96 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_137 . V_138 > 0 )
return V_137 . V_138 == 2 ;
if ( V_15 -> V_61 -> V_4 . V_73 . V_72 -> clock
> 112999 )
return true ;
if ( F_48 ( V_139 ) )
return true ;
V_96 = F_7 ( V_15 -> V_19 ) ;
if ( ! ( V_96 & ~ ( V_140 | V_141 ) ) )
V_96 = V_13 -> V_123 . V_142 ;
return ( V_96 & V_143 ) == V_54 ;
}
static bool F_69 ( struct V_10 * V_11 )
{
if ( F_70 ( V_11 ) || F_8 ( V_11 ) )
return true ;
if ( F_13 ( V_11 ) -> V_35 <= 4 && F_71 ( V_11 ) && ! F_72 ( V_11 ) )
return true ;
return false ;
}
void F_73 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_90 ;
struct V_60 * V_60 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_44 * V_144 ;
struct V_44 * V_72 = NULL ;
struct V_44 * V_145 = NULL ;
struct V_91 * V_91 ;
struct V_116 * V_43 ;
T_1 V_146 ;
int V_9 ;
T_3 V_147 ;
if ( F_12 ( V_11 ) ) {
F_22 ( V_64 ,
F_7 ( V_64 ) | V_148 ) ;
} else {
F_22 ( V_66 ,
F_7 ( V_66 ) | V_148 ) ;
}
if ( ! F_69 ( V_11 ) )
return;
if ( F_48 ( V_149 ) )
return;
V_147 = V_150 ;
if ( ! F_63 ( V_11 , & V_147 ) ) {
F_33 ( L_10 ) ;
return;
}
if ( F_12 ( V_11 ) ) {
if ( ( F_7 ( V_26 ) & V_141 ) == 0 )
return;
if ( V_13 -> V_123 . V_151 ) {
F_33 ( L_11 ) ;
return;
}
}
V_15 = F_74 ( sizeof( * V_15 ) , V_152 ) ;
if ( ! V_15 )
return;
V_90 = F_74 ( sizeof( * V_90 ) , V_152 ) ;
if ( ! V_90 ) {
F_56 ( V_15 ) ;
return;
}
if ( F_75 ( & V_90 -> V_4 ) < 0 ) {
F_56 ( V_90 ) ;
F_56 ( V_15 ) ;
return;
}
V_15 -> V_61 = V_90 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_60 = & V_90 -> V_4 ;
V_7 = & V_60 -> V_4 ;
F_76 ( V_11 , & V_60 -> V_4 , & V_153 ,
V_154 ) ;
F_77 ( V_11 , & V_8 -> V_4 , & V_155 ,
V_156 ) ;
V_8 -> V_120 = F_23 ;
V_8 -> V_157 = F_15 ;
V_8 -> V_158 = F_32 ;
V_8 -> V_159 = F_28 ;
V_8 -> V_160 = F_4 ;
V_8 -> V_161 = F_11 ;
V_60 -> V_160 = V_162 ;
V_60 -> V_163 = V_164 ;
F_78 ( V_60 , V_8 ) ;
V_8 -> type = V_136 ;
V_8 -> V_165 = 0 ;
if ( F_12 ( V_11 ) )
V_8 -> V_166 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_79 ( V_11 ) )
V_8 -> V_166 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_166 = ( 1 << 1 ) ;
F_80 ( V_7 , & V_167 ) ;
V_7 -> V_168 . V_169 = V_170 ;
V_7 -> V_171 = false ;
V_7 -> V_172 = false ;
if ( F_12 ( V_11 ) ) {
V_15 -> V_19 = V_26 ;
} else {
V_15 -> V_19 = V_27 ;
}
F_81 ( V_11 ) ;
F_82 ( & V_7 -> V_4 ,
V_11 -> V_114 . V_115 ,
V_173 ) ;
V_60 -> V_73 . V_82 = V_173 ;
F_47 ( & V_11 -> V_114 . V_174 ) ;
V_91 = F_83 ( V_7 , F_84 ( V_13 , V_147 ) ) ;
if ( V_91 ) {
if ( F_41 ( V_7 , V_91 ) ) {
F_85 ( V_7 ,
V_91 ) ;
} else {
F_56 ( V_91 ) ;
V_91 = F_86 ( - V_118 ) ;
}
} else {
V_91 = F_86 ( - V_175 ) ;
}
V_90 -> V_4 . V_91 = V_91 ;
if ( F_40 ( V_91 ) ) {
V_7 -> V_168 . V_176 = 0 ;
V_7 -> V_168 . V_177 = 200 ;
V_7 -> V_168 . V_178 = 0 ;
V_7 -> V_168 . V_179 = 200 ;
}
F_87 (scan, &connector->probed_modes, head) {
if ( V_144 -> type & V_180 ) {
F_33 ( L_12 ) ;
F_88 ( V_144 ) ;
V_72 = F_42 ( V_11 , V_144 ) ;
if ( V_72 ) {
V_145 =
F_89 ( V_11 ,
V_72 , V_7 ) ;
if ( V_145 != NULL &&
V_137 . V_181 ) {
V_13 -> V_182 = true ;
V_13 -> V_181 =
V_145 -> clock ;
F_33 ( L_13
L_14
L_15 ,
V_72 -> clock ,
V_13 -> V_181 ) ;
}
goto V_183;
}
}
}
if ( V_13 -> V_123 . V_184 ) {
F_33 ( L_16 ) ;
F_88 ( V_13 -> V_123 . V_184 ) ;
V_72 = F_42 ( V_11 , V_13 -> V_123 . V_184 ) ;
if ( V_72 ) {
V_72 -> type |= V_180 ;
goto V_183;
}
}
if ( F_12 ( V_11 ) )
goto V_185;
V_146 = F_7 ( V_27 ) ;
V_9 = ( V_146 & V_49 ) ? 1 : 0 ;
V_43 = F_90 ( V_11 , V_9 ) ;
if ( V_43 && ( V_146 & V_20 ) ) {
V_72 = F_91 ( V_11 , V_43 ) ;
if ( V_72 ) {
F_33 ( L_17 ) ;
F_88 ( V_72 ) ;
V_72 -> type |= V_180 ;
goto V_183;
}
}
if ( ! V_72 )
goto V_185;
V_183:
F_53 ( & V_11 -> V_114 . V_174 ) ;
F_92 ( & V_60 -> V_73 , V_72 , V_145 ) ;
V_15 -> V_52 = F_68 ( V_15 ) ;
F_33 ( L_18 ,
V_15 -> V_52 ? L_19 : L_20 ) ;
V_15 -> V_56 = F_7 ( V_15 -> V_19 ) &
V_55 ;
V_90 -> V_98 . V_110 = F_46 ;
if ( F_93 ( & V_90 -> V_98 ) ) {
F_33 ( L_21 ) ;
V_90 -> V_98 . V_110 = NULL ;
}
F_94 ( V_7 ) ;
F_95 ( V_7 , V_186 ) ;
return;
V_185:
F_53 ( & V_11 -> V_114 . V_174 ) ;
F_33 ( L_22 ) ;
F_58 ( V_7 ) ;
F_96 ( V_3 ) ;
F_56 ( V_15 ) ;
F_56 ( V_90 ) ;
return;
}
