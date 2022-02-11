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
if ( F_9 ( V_11 ) )
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
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
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
if ( F_14 ( V_11 ) -> V_32 < 5 )
V_23 -> V_33 . V_34 =
V_17 & V_35 ;
if ( F_14 ( V_11 ) -> V_32 < 4 ) {
V_17 = F_8 ( V_36 ) ;
V_23 -> V_33 . V_37 |= V_17 & V_38 ;
}
V_23 -> V_4 . V_31 . V_39 = V_23 -> V_40 ;
}
static void F_15 ( struct V_8 * V_3 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_41 * V_42 = F_16 ( V_3 -> V_4 . V_42 ) ;
const struct V_43 * V_31 = & V_42 -> V_44 -> V_4 . V_31 ;
int V_9 = V_42 -> V_9 ;
T_1 V_45 ;
if ( F_17 ( V_11 ) ) {
F_18 ( V_13 , V_9 ) ;
F_19 ( V_13 ,
V_42 -> V_44 -> V_46 ) ;
} else {
F_20 ( V_13 , V_9 ) ;
}
V_45 = F_8 ( V_14 -> V_19 ) ;
V_45 |= V_20 | V_47 ;
if ( F_9 ( V_11 ) ) {
V_45 &= ~ V_48 ;
V_45 |= F_21 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_45 |= V_49 ;
} else {
V_45 &= ~ V_49 ;
}
}
V_45 &= ~ V_35 ;
V_45 |= V_42 -> V_44 -> V_33 . V_34 ;
if ( V_14 -> V_50 )
V_45 |= V_51 | V_52 ;
else
V_45 &= ~ ( V_51 | V_52 ) ;
V_45 &= ~ V_53 ;
V_45 |= V_14 -> V_54 ;
if ( F_22 ( V_13 ) ) {
if ( V_42 -> V_44 -> V_55 && V_42 -> V_44 -> V_56 == 18 )
V_45 |= V_57 ;
else
V_45 &= ~ V_57 ;
}
V_45 &= ~ ( V_25 | V_28 ) ;
if ( V_31 -> V_24 & V_26 )
V_45 |= V_25 ;
if ( V_31 -> V_24 & V_29 )
V_45 |= V_28 ;
F_23 ( V_14 -> V_19 , V_45 ) ;
}
static void F_24 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_58 * V_58 =
& V_14 -> V_59 -> V_4 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_2 V_60 , V_61 ;
if ( F_17 ( V_11 ) ) {
V_60 = V_62 ;
V_61 = V_63 ;
} else {
V_60 = V_64 ;
V_61 = V_65 ;
}
F_23 ( V_14 -> V_19 , F_8 ( V_14 -> V_19 ) | V_20 ) ;
F_23 ( V_60 , F_8 ( V_60 ) | V_66 ) ;
F_25 ( V_14 -> V_19 ) ;
if ( F_26 ( V_13 , V_61 , V_67 , V_67 , 1000 ) )
F_27 ( L_1 ) ;
F_28 ( V_58 ) ;
}
static void F_29 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_2 V_60 , V_61 ;
if ( F_17 ( V_11 ) ) {
V_60 = V_62 ;
V_61 = V_63 ;
} else {
V_60 = V_64 ;
V_61 = V_65 ;
}
F_23 ( V_60 , F_8 ( V_60 ) & ~ V_66 ) ;
if ( F_26 ( V_13 , V_61 , V_67 , 0 , 1000 ) )
F_27 ( L_2 ) ;
F_23 ( V_14 -> V_19 , F_8 ( V_14 -> V_19 ) & ~ V_20 ) ;
F_25 ( V_14 -> V_19 ) ;
}
static void F_30 ( struct V_8 * V_3 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_58 * V_58 =
& V_14 -> V_59 -> V_4 ;
F_31 ( V_58 ) ;
F_29 ( V_3 ) ;
}
static void F_32 ( struct V_8 * V_3 )
{
struct V_1 * V_14 = F_1 ( & V_3 -> V_4 ) ;
struct V_58 * V_58 =
& V_14 -> V_59 -> V_4 ;
F_31 ( V_58 ) ;
}
static void F_33 ( struct V_8 * V_3 )
{
F_29 ( V_3 ) ;
}
static enum V_68
F_34 ( struct V_6 * V_7 ,
struct V_43 * V_69 )
{
struct V_58 * V_58 = F_35 ( V_7 ) ;
struct V_43 * V_70 = V_58 -> V_71 . V_70 ;
int V_72 = F_5 ( V_7 -> V_11 ) -> V_73 ;
if ( V_69 -> V_74 > V_70 -> V_74 )
return V_75 ;
if ( V_69 -> V_76 > V_70 -> V_76 )
return V_75 ;
if ( V_70 -> clock > V_72 )
return V_77 ;
return V_78 ;
}
static bool F_36 ( struct V_8 * V_8 ,
struct V_22 * V_23 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_1 * V_14 =
F_1 ( & V_8 -> V_4 ) ;
struct V_58 * V_58 =
& V_14 -> V_59 -> V_4 ;
struct V_43 * V_31 = & V_23 -> V_4 . V_31 ;
struct V_41 * V_41 = F_16 ( V_23 -> V_4 . V_42 ) ;
unsigned int V_79 ;
if ( F_14 ( V_11 ) -> V_32 < 4 && V_41 -> V_9 == 0 ) {
F_27 ( L_3 ) ;
return false ;
}
if ( V_14 -> V_54 == V_80 )
V_79 = 8 * 3 ;
else
V_79 = 6 * 3 ;
if ( V_79 != V_23 -> V_56 && ! V_23 -> V_81 ) {
F_37 ( L_4 ,
V_23 -> V_56 , V_79 ) ;
V_23 -> V_56 = V_79 ;
}
F_38 ( V_58 -> V_71 . V_70 ,
V_31 ) ;
if ( F_17 ( V_11 ) ) {
V_23 -> V_82 = true ;
F_39 ( V_41 , V_23 ,
V_58 -> V_71 . V_83 ) ;
} else {
F_40 ( V_41 , V_23 ,
V_58 -> V_71 . V_83 ) ;
}
return true ;
}
static enum V_84
F_41 ( struct V_6 * V_7 , bool V_85 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_84 V_86 ;
F_37 ( L_5 ,
V_7 -> V_4 . V_87 , V_7 -> V_88 ) ;
V_86 = F_42 ( V_11 ) ;
if ( V_86 != V_89 )
return V_86 ;
return V_90 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_5 * V_91 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_43 * V_69 ;
if ( ! F_44 ( V_91 -> V_4 . V_92 ) )
return F_45 ( V_7 , V_91 -> V_4 . V_92 ) ;
V_69 = F_46 ( V_11 , V_91 -> V_4 . V_71 . V_70 ) ;
if ( V_69 == NULL )
return 0 ;
F_47 ( V_7 , V_69 ) ;
return 1 ;
}
static int F_48 ( const struct V_93 * V_87 )
{
F_49 ( L_6 , V_87 -> V_94 ) ;
return 1 ;
}
static int F_50 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
struct V_5 * V_91 =
F_2 ( V_96 , struct V_5 , V_99 ) ;
struct V_6 * V_7 = & V_91 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_11 -> V_100 != V_101 )
return V_102 ;
F_51 ( & V_13 -> V_103 ) ;
if ( V_13 -> V_104 == V_105 )
goto exit;
V_7 -> V_86 = V_7 -> V_106 -> V_107 ( V_7 , false ) ;
if ( F_52 ( V_108 ) )
goto exit;
if ( ! F_53 () ) {
V_13 -> V_104 = V_109 ;
goto exit;
}
if ( V_13 -> V_104 == V_110 )
goto exit;
if ( ! F_17 ( V_11 ) )
F_54 ( V_11 ) ;
V_13 -> V_104 = V_110 ;
exit:
F_55 ( & V_13 -> V_103 ) ;
return V_102 ;
}
static void F_56 ( struct V_6 * V_7 )
{
struct V_5 * V_91 =
F_3 ( V_7 ) ;
if ( V_91 -> V_99 . V_111 )
F_57 ( & V_91 -> V_99 ) ;
if ( ! F_44 ( V_91 -> V_4 . V_92 ) )
F_58 ( V_91 -> V_4 . V_92 ) ;
F_59 ( & V_91 -> V_4 . V_71 ) ;
F_60 ( V_7 ) ;
F_58 ( V_7 ) ;
}
static int F_61 ( struct V_6 * V_7 ,
struct V_112 * V_113 ,
T_3 V_114 )
{
struct V_58 * V_58 = F_35 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_113 == V_11 -> V_115 . V_116 ) {
struct V_117 * V_42 ;
if ( V_114 == V_118 ) {
F_37 ( L_7 ) ;
return - V_119 ;
}
if ( V_58 -> V_71 . V_83 == V_114 ) {
return 0 ;
}
V_58 -> V_71 . V_83 = V_114 ;
V_42 = F_62 ( V_7 ) -> V_4 . V_42 ;
if ( V_42 && V_42 -> V_120 -> V_121 ) {
F_63 ( V_42 ) ;
}
}
return 0 ;
}
static int F_64 ( const struct V_93 * V_87 )
{
F_49 ( L_8 , V_87 -> V_94 ) ;
return 1 ;
}
static int F_65 ( const struct V_93 * V_87 )
{
F_49 ( L_9 , V_87 -> V_94 ) ;
return 1 ;
}
struct V_8 * F_66 ( struct V_10 * V_11 )
{
struct V_8 * V_8 ;
F_67 (dev, intel_encoder)
if ( V_8 -> type == V_122 )
return V_8 ;
return NULL ;
}
bool F_68 ( struct V_10 * V_11 )
{
struct V_8 * V_3 = F_66 ( V_11 ) ;
return V_3 && F_1 ( & V_3 -> V_4 ) -> V_50 ;
}
static bool F_69 ( struct V_1 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_4 . V_4 . V_11 ;
unsigned int V_97 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_123 . V_124 > 0 )
return V_123 . V_124 == 2 ;
if ( V_14 -> V_59 -> V_4 . V_71 . V_70 -> clock
> 112999 )
return true ;
if ( F_52 ( V_125 ) )
return true ;
V_97 = F_8 ( V_14 -> V_19 ) ;
if ( ! ( V_97 & ~ ( V_126 | V_127 ) ) )
V_97 = V_13 -> V_128 . V_129 ;
return ( V_97 & V_130 ) == V_52 ;
}
static bool F_70 ( struct V_10 * V_11 )
{
if ( F_71 ( V_11 ) || F_9 ( V_11 ) )
return true ;
if ( F_14 ( V_11 ) -> V_32 <= 4 && F_72 ( V_11 ) && ! F_73 ( V_11 ) )
return true ;
return false ;
}
void F_74 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_1 * V_14 ;
struct V_8 * V_8 ;
struct V_5 * V_91 ;
struct V_58 * V_58 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_43 * V_131 ;
struct V_43 * V_70 = NULL ;
struct V_43 * V_132 = NULL ;
struct V_92 * V_92 ;
struct V_117 * V_42 ;
T_2 V_133 ;
T_1 V_134 ;
int V_9 ;
T_4 V_135 ;
if ( F_17 ( V_11 ) ) {
F_23 ( V_62 ,
F_8 ( V_62 ) | V_136 ) ;
} else if ( F_14 ( V_13 ) -> V_32 < 5 ) {
F_23 ( V_64 ,
F_8 ( V_64 ) | V_136 ) ;
}
if ( ! F_70 ( V_11 ) )
return;
if ( F_52 ( V_137 ) )
return;
if ( F_17 ( V_11 ) )
V_133 = V_138 ;
else
V_133 = V_139 ;
V_134 = F_8 ( V_133 ) ;
if ( F_17 ( V_11 ) ) {
if ( ( V_134 & V_127 ) == 0 )
return;
if ( V_13 -> V_128 . V_140 . V_141 ) {
F_37 ( L_10 ) ;
return;
}
}
V_135 = V_142 ;
if ( ! F_75 ( V_13 , & V_135 ) ) {
if ( ( V_134 & V_20 ) == 0 ) {
F_37 ( L_11 ) ;
return;
}
F_37 ( L_12 ) ;
}
if ( F_14 ( V_13 ) -> V_32 < 5 &&
F_8 ( V_143 ) == 0 && F_8 ( V_144 ) == 0 ) {
F_23 ( V_143 , 0x019007d0 ) ;
F_23 ( V_144 , 0x015e07d0 ) ;
F_37 ( L_13 ) ;
}
V_14 = F_76 ( sizeof( * V_14 ) , V_145 ) ;
if ( ! V_14 )
return;
V_91 = F_76 ( sizeof( * V_91 ) , V_145 ) ;
if ( ! V_91 ) {
F_58 ( V_14 ) ;
return;
}
if ( F_77 ( & V_91 -> V_4 ) < 0 ) {
F_58 ( V_91 ) ;
F_58 ( V_14 ) ;
return;
}
V_14 -> V_59 = V_91 ;
V_8 = & V_14 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_58 = & V_91 -> V_4 ;
V_7 = & V_58 -> V_4 ;
F_78 ( V_11 , & V_58 -> V_4 , & V_146 ,
V_147 ) ;
F_79 ( V_11 , & V_8 -> V_4 , & V_148 ,
V_149 , L_14 ) ;
V_8 -> V_121 = F_24 ;
V_8 -> V_150 = F_15 ;
V_8 -> V_151 = F_36 ;
if ( F_17 ( V_13 ) ) {
V_8 -> V_152 = F_32 ;
V_8 -> V_153 = F_33 ;
} else {
V_8 -> V_152 = F_30 ;
}
V_8 -> V_154 = F_4 ;
V_8 -> V_155 = F_13 ;
V_58 -> V_154 = V_156 ;
F_80 ( V_58 , V_8 ) ;
V_8 -> type = V_122 ;
V_8 -> V_157 = 0 ;
if ( F_17 ( V_11 ) )
V_8 -> V_158 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_22 ( V_11 ) )
V_8 -> V_158 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_158 = ( 1 << 1 ) ;
F_81 ( V_7 , & V_159 ) ;
V_7 -> V_160 . V_161 = V_162 ;
V_7 -> V_163 = false ;
V_7 -> V_164 = false ;
V_14 -> V_19 = V_133 ;
F_82 ( V_11 ) ;
F_83 ( & V_7 -> V_4 ,
V_11 -> V_115 . V_116 ,
V_165 ) ;
V_58 -> V_71 . V_83 = V_165 ;
F_51 ( & V_11 -> V_115 . V_166 ) ;
if ( F_84 () & V_167 )
V_92 = F_85 ( V_7 ,
F_86 ( V_13 , V_135 ) ) ;
else
V_92 = F_87 ( V_7 ,
F_86 ( V_13 , V_135 ) ) ;
if ( V_92 ) {
if ( F_45 ( V_7 , V_92 ) ) {
F_88 ( V_7 ,
V_92 ) ;
} else {
F_58 ( V_92 ) ;
V_92 = F_89 ( - V_119 ) ;
}
} else {
V_92 = F_89 ( - V_168 ) ;
}
V_91 -> V_4 . V_92 = V_92 ;
if ( F_44 ( V_92 ) ) {
V_7 -> V_160 . V_169 = 0 ;
V_7 -> V_160 . V_170 = 200 ;
V_7 -> V_160 . V_171 = 0 ;
V_7 -> V_160 . V_172 = 200 ;
}
F_90 (scan, &connector->probed_modes, head) {
if ( V_131 -> type & V_173 ) {
F_37 ( L_15 ) ;
F_91 ( V_131 ) ;
V_70 = F_46 ( V_11 , V_131 ) ;
if ( V_70 )
goto V_21;
}
}
if ( V_13 -> V_128 . V_174 ) {
F_37 ( L_16 ) ;
F_91 ( V_13 -> V_128 . V_174 ) ;
V_70 = F_46 ( V_11 , V_13 -> V_128 . V_174 ) ;
if ( V_70 ) {
V_70 -> type |= V_173 ;
V_7 -> V_160 . V_175 = V_70 -> V_175 ;
V_7 -> V_160 . V_176 = V_70 -> V_176 ;
goto V_21;
}
}
if ( F_17 ( V_11 ) )
goto V_177;
V_9 = ( V_134 & V_49 ) ? 1 : 0 ;
V_42 = F_92 ( V_11 , V_9 ) ;
if ( V_42 && ( V_134 & V_20 ) ) {
V_70 = F_93 ( V_11 , V_42 ) ;
if ( V_70 ) {
F_37 ( L_17 ) ;
F_91 ( V_70 ) ;
V_70 -> type |= V_173 ;
goto V_21;
}
}
if ( ! V_70 )
goto V_177;
V_21:
F_55 ( & V_11 -> V_115 . V_166 ) ;
F_94 ( & V_58 -> V_71 , V_70 , V_132 ) ;
F_95 ( V_7 , V_178 ) ;
V_14 -> V_50 = F_69 ( V_14 ) ;
F_37 ( L_18 ,
V_14 -> V_50 ? L_19 : L_20 ) ;
V_14 -> V_54 = V_134 & V_53 ;
V_91 -> V_99 . V_111 = F_50 ;
if ( F_96 ( & V_91 -> V_99 ) ) {
F_37 ( L_21 ) ;
V_91 -> V_99 . V_111 = NULL ;
}
return;
V_177:
F_55 ( & V_11 -> V_115 . V_166 ) ;
F_37 ( L_22 ) ;
F_60 ( V_7 ) ;
F_97 ( V_3 ) ;
F_58 ( V_14 ) ;
F_58 ( V_91 ) ;
return;
}
