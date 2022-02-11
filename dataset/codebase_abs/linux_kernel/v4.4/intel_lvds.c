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
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 , V_23 = 0 ;
int V_24 ;
V_18 = F_7 ( V_15 -> V_19 ) ;
if ( V_18 & V_25 )
V_23 |= V_26 ;
else
V_23 |= V_27 ;
if ( V_18 & V_28 )
V_23 |= V_29 ;
else
V_23 |= V_30 ;
V_22 -> V_4 . V_31 . V_23 |= V_23 ;
if ( F_12 ( V_11 ) -> V_32 < 4 ) {
V_18 = F_7 ( V_33 ) ;
V_22 -> V_34 . V_35 |= V_18 & V_36 ;
}
V_24 = V_22 -> V_37 ;
if ( F_13 ( V_13 -> V_11 ) )
F_14 ( V_22 , V_24 ) ;
V_22 -> V_4 . V_31 . V_38 = V_24 ;
}
static void F_15 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_39 * V_40 = F_16 ( V_3 -> V_4 . V_40 ) ;
const struct V_41 * V_31 = & V_40 -> V_42 -> V_4 . V_31 ;
int V_9 = V_40 -> V_9 ;
T_1 V_43 ;
if ( F_13 ( V_11 ) ) {
F_17 ( V_13 , V_9 ) ;
F_18 ( V_13 ,
F_19 ( V_40 ) ) ;
} else {
F_20 ( V_13 , V_9 ) ;
}
V_43 = F_7 ( V_15 -> V_19 ) ;
V_43 |= V_20 | V_44 ;
if ( F_8 ( V_11 ) ) {
V_43 &= ~ V_45 ;
V_43 |= F_21 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_43 |= V_46 ;
} else {
V_43 &= ~ V_46 ;
}
}
V_43 &= ~ V_47 ;
V_43 |= V_40 -> V_42 -> V_34 . V_48 ;
if ( V_15 -> V_49 )
V_43 |= V_50 | V_51 ;
else
V_43 &= ~ ( V_50 | V_51 ) ;
V_43 &= ~ V_52 ;
V_43 |= V_15 -> V_53 ;
if ( F_12 ( V_11 ) -> V_32 == 4 ) {
if ( V_40 -> V_42 -> V_54 && V_40 -> V_42 -> V_55 == 18 )
V_43 |= V_56 ;
else
V_43 &= ~ V_56 ;
}
V_43 &= ~ ( V_25 | V_28 ) ;
if ( V_31 -> V_23 & V_26 )
V_43 |= V_25 ;
if ( V_31 -> V_23 & V_29 )
V_43 |= V_28 ;
F_22 ( V_15 -> V_19 , V_43 ) ;
}
static void F_23 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_57 * V_57 =
& V_15 -> V_58 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_59 , V_60 ;
if ( F_13 ( V_11 ) ) {
V_59 = V_61 ;
V_60 = V_62 ;
} else {
V_59 = V_63 ;
V_60 = V_64 ;
}
F_22 ( V_15 -> V_19 , F_7 ( V_15 -> V_19 ) | V_20 ) ;
F_22 ( V_59 , F_7 ( V_59 ) | V_65 ) ;
F_24 ( V_15 -> V_19 ) ;
if ( F_25 ( ( F_7 ( V_60 ) & V_66 ) != 0 , 1000 ) )
F_26 ( L_1 ) ;
F_27 ( V_57 ) ;
}
static void F_28 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_59 , V_60 ;
if ( F_13 ( V_11 ) ) {
V_59 = V_61 ;
V_60 = V_62 ;
} else {
V_59 = V_63 ;
V_60 = V_64 ;
}
F_22 ( V_59 , F_7 ( V_59 ) & ~ V_65 ) ;
if ( F_25 ( ( F_7 ( V_60 ) & V_66 ) == 0 , 1000 ) )
F_26 ( L_2 ) ;
F_22 ( V_15 -> V_19 , F_7 ( V_15 -> V_19 ) & ~ V_20 ) ;
F_24 ( V_15 -> V_19 ) ;
}
static void F_29 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_57 * V_57 =
& V_15 -> V_58 -> V_4 ;
F_30 ( V_57 ) ;
F_28 ( V_3 ) ;
}
static void F_31 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_57 * V_57 =
& V_15 -> V_58 -> V_4 ;
F_30 ( V_57 ) ;
}
static void F_32 ( struct V_8 * V_3 )
{
F_28 ( V_3 ) ;
}
static enum V_67
F_33 ( struct V_6 * V_7 ,
struct V_41 * V_68 )
{
struct V_57 * V_57 = F_34 ( V_7 ) ;
struct V_41 * V_69 = V_57 -> V_70 . V_69 ;
int V_71 = F_35 ( V_7 -> V_11 ) -> V_72 ;
if ( V_68 -> V_73 > V_69 -> V_73 )
return V_74 ;
if ( V_68 -> V_75 > V_69 -> V_75 )
return V_74 ;
if ( V_69 -> clock > V_71 )
return V_76 ;
return V_77 ;
}
static bool F_36 ( struct V_8 * V_8 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_57 * V_57 =
& V_15 -> V_58 -> V_4 ;
struct V_41 * V_31 = & V_22 -> V_4 . V_31 ;
struct V_39 * V_39 = F_16 ( V_22 -> V_4 . V_40 ) ;
unsigned int V_78 ;
if ( F_12 ( V_11 ) -> V_32 < 4 && V_39 -> V_9 == 0 ) {
F_26 ( L_3 ) ;
return false ;
}
if ( V_15 -> V_53 == V_79 )
V_78 = 8 * 3 ;
else
V_78 = 6 * 3 ;
if ( V_78 != V_22 -> V_55 && ! V_22 -> V_80 ) {
F_37 ( L_4 ,
V_22 -> V_55 , V_78 ) ;
V_22 -> V_55 = V_78 ;
}
F_38 ( V_57 -> V_70 . V_69 ,
V_31 ) ;
if ( F_13 ( V_11 ) ) {
V_22 -> V_81 = true ;
F_39 ( V_39 , V_22 ,
V_57 -> V_70 . V_82 ) ;
} else {
F_40 ( V_39 , V_22 ,
V_57 -> V_70 . V_82 ) ;
}
return true ;
}
static enum V_83
F_41 ( struct V_6 * V_7 , bool V_84 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_83 V_85 ;
F_37 ( L_5 ,
V_7 -> V_4 . V_86 , V_7 -> V_87 ) ;
V_85 = F_42 ( V_11 ) ;
if ( V_85 != V_88 )
return V_85 ;
return V_89 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_41 * V_68 ;
if ( ! F_44 ( V_90 -> V_4 . V_91 ) )
return F_45 ( V_7 , V_90 -> V_4 . V_91 ) ;
V_68 = F_46 ( V_11 , V_90 -> V_4 . V_70 . V_69 ) ;
if ( V_68 == NULL )
return 0 ;
F_47 ( V_7 , V_68 ) ;
return 1 ;
}
static int F_48 ( const struct V_92 * V_86 )
{
F_49 ( L_6 , V_86 -> V_93 ) ;
return 1 ;
}
static int F_50 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_5 * V_90 =
F_2 ( V_95 , struct V_5 , V_98 ) ;
struct V_6 * V_7 = & V_90 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_99 != V_100 )
return V_101 ;
F_51 ( & V_13 -> V_102 ) ;
if ( V_13 -> V_103 == V_104 )
goto exit;
V_7 -> V_85 = V_7 -> V_105 -> V_106 ( V_7 , false ) ;
if ( F_52 ( V_107 ) )
goto exit;
if ( ! F_53 () ) {
V_13 -> V_103 = V_108 ;
goto exit;
}
if ( V_13 -> V_103 == V_109 )
goto exit;
if ( ! F_13 ( V_11 ) ) {
F_54 ( V_11 ) ;
F_55 ( V_11 ) ;
F_56 ( V_11 ) ;
}
V_13 -> V_103 = V_109 ;
exit:
F_57 ( & V_13 -> V_102 ) ;
return V_101 ;
}
static void F_58 ( struct V_6 * V_7 )
{
struct V_5 * V_90 =
F_3 ( V_7 ) ;
if ( V_90 -> V_98 . V_110 )
F_59 ( & V_90 -> V_98 ) ;
if ( ! F_44 ( V_90 -> V_4 . V_91 ) )
F_60 ( V_90 -> V_4 . V_91 ) ;
F_61 ( & V_90 -> V_4 . V_70 ) ;
F_62 ( V_7 ) ;
F_60 ( V_7 ) ;
}
static int F_63 ( struct V_6 * V_7 ,
struct V_111 * V_112 ,
T_2 V_113 )
{
struct V_57 * V_57 = F_34 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_112 == V_11 -> V_114 . V_115 ) {
struct V_116 * V_40 ;
if ( V_113 == V_117 ) {
F_37 ( L_7 ) ;
return - V_118 ;
}
if ( V_57 -> V_70 . V_82 == V_113 ) {
return 0 ;
}
V_57 -> V_70 . V_82 = V_113 ;
V_40 = F_64 ( V_7 ) -> V_4 . V_40 ;
if ( V_40 && V_40 -> V_119 -> V_120 ) {
F_65 ( V_40 ) ;
}
}
return 0 ;
}
static int F_66 ( const struct V_92 * V_86 )
{
F_49 ( L_8 , V_86 -> V_93 ) ;
return 1 ;
}
static bool F_67 ( struct V_10 * V_11 ,
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
if ( F_68 ( V_13 , V_129 -> V_121 ) )
* V_121 = V_129 -> V_121 ;
if ( V_129 -> V_134 )
return true ;
if ( V_13 -> V_135 . V_123 )
return true ;
}
return false ;
}
static int F_69 ( const struct V_92 * V_86 )
{
F_49 ( L_9 , V_86 -> V_93 ) ;
return 1 ;
}
bool F_70 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_71 (dev, encoder) {
if ( V_3 -> type == V_136 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_49 ;
}
}
return false ;
}
static bool F_72 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_96 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_137 . V_138 > 0 )
return V_137 . V_138 == 2 ;
if ( V_15 -> V_58 -> V_4 . V_70 . V_69 -> clock
> 112999 )
return true ;
if ( F_52 ( V_139 ) )
return true ;
V_96 = F_7 ( V_15 -> V_19 ) ;
if ( ! ( V_96 & ~ ( V_140 | V_141 ) ) )
V_96 = V_13 -> V_123 . V_142 ;
return ( V_96 & V_143 ) == V_51 ;
}
static bool F_73 ( struct V_10 * V_11 )
{
if ( F_74 ( V_11 ) || F_8 ( V_11 ) )
return true ;
if ( F_12 ( V_11 ) -> V_32 <= 4 && F_75 ( V_11 ) && ! F_76 ( V_11 ) )
return true ;
return false ;
}
void F_77 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_90 ;
struct V_57 * V_57 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_41 * V_144 ;
struct V_41 * V_69 = NULL ;
struct V_41 * V_145 = NULL ;
struct V_91 * V_91 ;
struct V_116 * V_40 ;
T_1 V_146 ;
T_1 V_147 ;
int V_9 ;
T_3 V_148 ;
if ( F_13 ( V_11 ) ) {
F_22 ( V_61 ,
F_7 ( V_61 ) | V_149 ) ;
} else if ( F_12 ( V_13 ) -> V_32 < 5 ) {
F_22 ( V_63 ,
F_7 ( V_63 ) | V_149 ) ;
}
if ( ! F_73 ( V_11 ) )
return;
if ( F_52 ( V_150 ) )
return;
if ( F_13 ( V_11 ) )
V_146 = V_151 ;
else
V_146 = V_152 ;
V_147 = F_7 ( V_146 ) ;
if ( F_13 ( V_11 ) ) {
if ( ( V_147 & V_141 ) == 0 )
return;
if ( V_13 -> V_123 . V_153 ) {
F_37 ( L_10 ) ;
return;
}
}
V_148 = V_154 ;
if ( ! F_67 ( V_11 , & V_148 ) ) {
if ( ( V_147 & V_20 ) == 0 ) {
F_37 ( L_11 ) ;
return;
}
F_37 ( L_12 ) ;
}
if ( F_12 ( V_13 ) -> V_32 < 5 &&
F_7 ( V_155 ) == 0 && F_7 ( V_156 ) == 0 ) {
F_22 ( V_155 , 0x019007d0 ) ;
F_22 ( V_156 , 0x015e07d0 ) ;
F_37 ( L_13 ) ;
}
V_15 = F_78 ( sizeof( * V_15 ) , V_157 ) ;
if ( ! V_15 )
return;
V_90 = F_78 ( sizeof( * V_90 ) , V_157 ) ;
if ( ! V_90 ) {
F_60 ( V_15 ) ;
return;
}
if ( F_79 ( & V_90 -> V_4 ) < 0 ) {
F_60 ( V_90 ) ;
F_60 ( V_15 ) ;
return;
}
V_15 -> V_58 = V_90 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_57 = & V_90 -> V_4 ;
V_7 = & V_57 -> V_4 ;
F_80 ( V_11 , & V_57 -> V_4 , & V_158 ,
V_159 ) ;
F_81 ( V_11 , & V_8 -> V_4 , & V_160 ,
V_161 ) ;
V_8 -> V_120 = F_23 ;
V_8 -> V_162 = F_15 ;
V_8 -> V_163 = F_36 ;
if ( F_13 ( V_13 ) ) {
V_8 -> V_164 = F_31 ;
V_8 -> V_165 = F_32 ;
} else {
V_8 -> V_164 = F_29 ;
}
V_8 -> V_166 = F_4 ;
V_8 -> V_167 = F_11 ;
V_57 -> V_166 = V_168 ;
V_57 -> V_169 = V_170 ;
F_82 ( V_57 , V_8 ) ;
V_8 -> type = V_136 ;
V_8 -> V_171 = 0 ;
if ( F_13 ( V_11 ) )
V_8 -> V_172 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_83 ( V_11 ) )
V_8 -> V_172 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_172 = ( 1 << 1 ) ;
F_84 ( V_7 , & V_173 ) ;
V_7 -> V_174 . V_175 = V_176 ;
V_7 -> V_177 = false ;
V_7 -> V_178 = false ;
V_15 -> V_19 = V_146 ;
F_85 ( V_11 ) ;
F_86 ( & V_7 -> V_4 ,
V_11 -> V_114 . V_115 ,
V_179 ) ;
V_57 -> V_70 . V_82 = V_179 ;
F_51 ( & V_11 -> V_114 . V_180 ) ;
V_91 = F_87 ( V_7 , F_88 ( V_13 , V_148 ) ) ;
if ( V_91 ) {
if ( F_45 ( V_7 , V_91 ) ) {
F_89 ( V_7 ,
V_91 ) ;
} else {
F_60 ( V_91 ) ;
V_91 = F_90 ( - V_118 ) ;
}
} else {
V_91 = F_90 ( - V_181 ) ;
}
V_90 -> V_4 . V_91 = V_91 ;
if ( F_44 ( V_91 ) ) {
V_7 -> V_174 . V_182 = 0 ;
V_7 -> V_174 . V_183 = 200 ;
V_7 -> V_174 . V_184 = 0 ;
V_7 -> V_174 . V_185 = 200 ;
}
F_91 (scan, &connector->probed_modes, head) {
if ( V_144 -> type & V_186 ) {
F_37 ( L_14 ) ;
F_92 ( V_144 ) ;
V_69 = F_46 ( V_11 , V_144 ) ;
if ( V_69 )
goto V_187;
}
}
if ( V_13 -> V_123 . V_188 ) {
F_37 ( L_15 ) ;
F_92 ( V_13 -> V_123 . V_188 ) ;
V_69 = F_46 ( V_11 , V_13 -> V_123 . V_188 ) ;
if ( V_69 ) {
V_69 -> type |= V_186 ;
goto V_187;
}
}
if ( F_13 ( V_11 ) )
goto V_189;
V_9 = ( V_147 & V_46 ) ? 1 : 0 ;
V_40 = F_93 ( V_11 , V_9 ) ;
if ( V_40 && ( V_147 & V_20 ) ) {
V_69 = F_94 ( V_11 , V_40 ) ;
if ( V_69 ) {
F_37 ( L_16 ) ;
F_92 ( V_69 ) ;
V_69 -> type |= V_186 ;
goto V_187;
}
}
if ( ! V_69 )
goto V_189;
V_187:
F_57 ( & V_11 -> V_114 . V_180 ) ;
F_95 ( & V_57 -> V_70 , V_69 , V_145 ) ;
V_15 -> V_49 = F_72 ( V_15 ) ;
F_37 ( L_17 ,
V_15 -> V_49 ? L_18 : L_19 ) ;
V_15 -> V_53 = F_7 ( V_15 -> V_19 ) &
V_52 ;
V_90 -> V_98 . V_110 = F_50 ;
if ( F_96 ( & V_90 -> V_98 ) ) {
F_37 ( L_20 ) ;
V_90 -> V_98 . V_110 = NULL ;
}
F_97 ( V_7 ) ;
F_98 ( V_7 , V_190 ) ;
return;
V_189:
F_57 ( & V_11 -> V_114 . V_180 ) ;
F_37 ( L_21 ) ;
F_62 ( V_7 ) ;
F_99 ( V_3 ) ;
F_60 ( V_15 ) ;
F_60 ( V_90 ) ;
return;
}
