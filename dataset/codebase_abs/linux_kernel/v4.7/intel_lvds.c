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
bool V_19 ;
V_17 = F_5 ( V_3 ) ;
if ( ! F_6 ( V_13 , V_17 ) )
return false ;
V_19 = false ;
V_18 = F_7 ( V_15 -> V_20 ) ;
if ( ! ( V_18 & V_21 ) )
goto V_22;
if ( F_8 ( V_11 ) )
* V_9 = F_9 ( V_18 ) ;
else
* V_9 = F_10 ( V_18 ) ;
V_19 = true ;
V_22:
F_11 ( V_13 , V_17 ) ;
return V_19 ;
}
static void F_12 ( struct V_8 * V_3 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 , V_25 = 0 ;
V_18 = F_7 ( V_15 -> V_20 ) ;
if ( V_18 & V_26 )
V_25 |= V_27 ;
else
V_25 |= V_28 ;
if ( V_18 & V_29 )
V_25 |= V_30 ;
else
V_25 |= V_31 ;
V_24 -> V_4 . V_32 . V_25 |= V_25 ;
if ( F_13 ( V_11 ) -> V_33 < 5 )
V_24 -> V_34 . V_35 =
V_18 & V_36 ;
if ( F_13 ( V_11 ) -> V_33 < 4 ) {
V_18 = F_7 ( V_37 ) ;
V_24 -> V_34 . V_38 |= V_18 & V_39 ;
}
V_24 -> V_4 . V_32 . V_40 = V_24 -> V_41 ;
}
static void F_14 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_42 * V_43 = F_15 ( V_3 -> V_4 . V_43 ) ;
const struct V_44 * V_32 = & V_43 -> V_45 -> V_4 . V_32 ;
int V_9 = V_43 -> V_9 ;
T_1 V_46 ;
if ( F_16 ( V_11 ) ) {
F_17 ( V_13 , V_9 ) ;
F_18 ( V_13 ,
V_43 -> V_45 -> V_47 ) ;
} else {
F_19 ( V_13 , V_9 ) ;
}
V_46 = F_7 ( V_15 -> V_20 ) ;
V_46 |= V_21 | V_48 ;
if ( F_8 ( V_11 ) ) {
V_46 &= ~ V_49 ;
V_46 |= F_20 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_46 |= V_50 ;
} else {
V_46 &= ~ V_50 ;
}
}
V_46 &= ~ V_36 ;
V_46 |= V_43 -> V_45 -> V_34 . V_35 ;
if ( V_15 -> V_51 )
V_46 |= V_52 | V_53 ;
else
V_46 &= ~ ( V_52 | V_53 ) ;
V_46 &= ~ V_54 ;
V_46 |= V_15 -> V_55 ;
if ( F_13 ( V_11 ) -> V_33 == 4 ) {
if ( V_43 -> V_45 -> V_56 && V_43 -> V_45 -> V_57 == 18 )
V_46 |= V_58 ;
else
V_46 &= ~ V_58 ;
}
V_46 &= ~ ( V_26 | V_29 ) ;
if ( V_32 -> V_25 & V_27 )
V_46 |= V_26 ;
if ( V_32 -> V_25 & V_30 )
V_46 |= V_29 ;
F_21 ( V_15 -> V_20 , V_46 ) ;
}
static void F_22 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_2 V_61 , V_62 ;
if ( F_16 ( V_11 ) ) {
V_61 = V_63 ;
V_62 = V_64 ;
} else {
V_61 = V_65 ;
V_62 = V_66 ;
}
F_21 ( V_15 -> V_20 , F_7 ( V_15 -> V_20 ) | V_21 ) ;
F_21 ( V_61 , F_7 ( V_61 ) | V_67 ) ;
F_23 ( V_15 -> V_20 ) ;
if ( F_24 ( ( F_7 ( V_62 ) & V_68 ) != 0 , 1000 ) )
F_25 ( L_1 ) ;
F_26 ( V_59 ) ;
}
static void F_27 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_2 V_61 , V_62 ;
if ( F_16 ( V_11 ) ) {
V_61 = V_63 ;
V_62 = V_64 ;
} else {
V_61 = V_65 ;
V_62 = V_66 ;
}
F_21 ( V_61 , F_7 ( V_61 ) & ~ V_67 ) ;
if ( F_24 ( ( F_7 ( V_62 ) & V_68 ) == 0 , 1000 ) )
F_25 ( L_2 ) ;
F_21 ( V_15 -> V_20 , F_7 ( V_15 -> V_20 ) & ~ V_21 ) ;
F_23 ( V_15 -> V_20 ) ;
}
static void F_28 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
F_29 ( V_59 ) ;
F_27 ( V_3 ) ;
}
static void F_30 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
F_29 ( V_59 ) ;
}
static void F_31 ( struct V_8 * V_3 )
{
F_27 ( V_3 ) ;
}
static enum V_69
F_32 ( struct V_6 * V_7 ,
struct V_44 * V_70 )
{
struct V_59 * V_59 = F_33 ( V_7 ) ;
struct V_44 * V_71 = V_59 -> V_72 . V_71 ;
int V_73 = F_34 ( V_7 -> V_11 ) -> V_74 ;
if ( V_70 -> V_75 > V_71 -> V_75 )
return V_76 ;
if ( V_70 -> V_77 > V_71 -> V_77 )
return V_76 ;
if ( V_71 -> clock > V_73 )
return V_78 ;
return V_79 ;
}
static bool F_35 ( struct V_8 * V_8 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
struct V_44 * V_32 = & V_24 -> V_4 . V_32 ;
struct V_42 * V_42 = F_15 ( V_24 -> V_4 . V_43 ) ;
unsigned int V_80 ;
if ( F_13 ( V_11 ) -> V_33 < 4 && V_42 -> V_9 == 0 ) {
F_25 ( L_3 ) ;
return false ;
}
if ( V_15 -> V_55 == V_81 )
V_80 = 8 * 3 ;
else
V_80 = 6 * 3 ;
if ( V_80 != V_24 -> V_57 && ! V_24 -> V_82 ) {
F_36 ( L_4 ,
V_24 -> V_57 , V_80 ) ;
V_24 -> V_57 = V_80 ;
}
F_37 ( V_59 -> V_72 . V_71 ,
V_32 ) ;
if ( F_16 ( V_11 ) ) {
V_24 -> V_83 = true ;
F_38 ( V_42 , V_24 ,
V_59 -> V_72 . V_84 ) ;
} else {
F_39 ( V_42 , V_24 ,
V_59 -> V_72 . V_84 ) ;
}
return true ;
}
static enum V_85
F_40 ( struct V_6 * V_7 , bool V_86 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_85 V_87 ;
F_36 ( L_5 ,
V_7 -> V_4 . V_88 , V_7 -> V_89 ) ;
V_87 = F_41 ( V_11 ) ;
if ( V_87 != V_90 )
return V_87 ;
return V_91 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_5 * V_92 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_44 * V_70 ;
if ( ! F_43 ( V_92 -> V_4 . V_93 ) )
return F_44 ( V_7 , V_92 -> V_4 . V_93 ) ;
V_70 = F_45 ( V_11 , V_92 -> V_4 . V_72 . V_71 ) ;
if ( V_70 == NULL )
return 0 ;
F_46 ( V_7 , V_70 ) ;
return 1 ;
}
static int F_47 ( const struct V_94 * V_88 )
{
F_48 ( L_6 , V_88 -> V_95 ) ;
return 1 ;
}
static int F_49 ( struct V_96 * V_97 , unsigned long V_98 ,
void * V_99 )
{
struct V_5 * V_92 =
F_2 ( V_97 , struct V_5 , V_100 ) ;
struct V_6 * V_7 = & V_92 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_101 != V_102 )
return V_103 ;
F_50 ( & V_13 -> V_104 ) ;
if ( V_13 -> V_105 == V_106 )
goto exit;
V_7 -> V_87 = V_7 -> V_107 -> V_108 ( V_7 , false ) ;
if ( F_51 ( V_109 ) )
goto exit;
if ( ! F_52 () ) {
V_13 -> V_105 = V_110 ;
goto exit;
}
if ( V_13 -> V_105 == V_111 )
goto exit;
if ( ! F_16 ( V_11 ) )
F_53 ( V_11 ) ;
V_13 -> V_105 = V_111 ;
exit:
F_54 ( & V_13 -> V_104 ) ;
return V_103 ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_5 * V_92 =
F_3 ( V_7 ) ;
if ( V_92 -> V_100 . V_112 )
F_56 ( & V_92 -> V_100 ) ;
if ( ! F_43 ( V_92 -> V_4 . V_93 ) )
F_57 ( V_92 -> V_4 . V_93 ) ;
F_58 ( & V_92 -> V_4 . V_72 ) ;
F_59 ( V_7 ) ;
F_57 ( V_7 ) ;
}
static int F_60 ( struct V_6 * V_7 ,
struct V_113 * V_114 ,
T_3 V_115 )
{
struct V_59 * V_59 = F_33 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_114 == V_11 -> V_116 . V_117 ) {
struct V_118 * V_43 ;
if ( V_115 == V_119 ) {
F_36 ( L_7 ) ;
return - V_120 ;
}
if ( V_59 -> V_72 . V_84 == V_115 ) {
return 0 ;
}
V_59 -> V_72 . V_84 = V_115 ;
V_43 = F_61 ( V_7 ) -> V_4 . V_43 ;
if ( V_43 && V_43 -> V_121 -> V_122 ) {
F_62 ( V_43 ) ;
}
}
return 0 ;
}
static int F_63 ( const struct V_94 * V_88 )
{
F_48 ( L_8 , V_88 -> V_95 ) ;
return 1 ;
}
static int F_64 ( const struct V_94 * V_88 )
{
F_48 ( L_9 , V_88 -> V_95 ) ;
return 1 ;
}
bool F_65 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_66 (dev, encoder) {
if ( V_3 -> type == V_123 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_51 ;
}
}
return false ;
}
static bool F_67 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_98 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_124 . V_125 > 0 )
return V_124 . V_125 == 2 ;
if ( V_15 -> V_60 -> V_4 . V_72 . V_71 -> clock
> 112999 )
return true ;
if ( F_51 ( V_126 ) )
return true ;
V_98 = F_7 ( V_15 -> V_20 ) ;
if ( ! ( V_98 & ~ ( V_127 | V_128 ) ) )
V_98 = V_13 -> V_129 . V_130 ;
return ( V_98 & V_131 ) == V_53 ;
}
static bool F_68 ( struct V_10 * V_11 )
{
if ( F_69 ( V_11 ) || F_8 ( V_11 ) )
return true ;
if ( F_13 ( V_11 ) -> V_33 <= 4 && F_70 ( V_11 ) && ! F_71 ( V_11 ) )
return true ;
return false ;
}
void F_72 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_92 ;
struct V_59 * V_59 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_44 * V_132 ;
struct V_44 * V_71 = NULL ;
struct V_44 * V_133 = NULL ;
struct V_93 * V_93 ;
struct V_118 * V_43 ;
T_2 V_134 ;
T_1 V_135 ;
int V_9 ;
T_4 V_136 ;
if ( F_16 ( V_11 ) ) {
F_21 ( V_63 ,
F_7 ( V_63 ) | V_137 ) ;
} else if ( F_13 ( V_13 ) -> V_33 < 5 ) {
F_21 ( V_65 ,
F_7 ( V_65 ) | V_137 ) ;
}
if ( ! F_68 ( V_11 ) )
return;
if ( F_51 ( V_138 ) )
return;
if ( F_16 ( V_11 ) )
V_134 = V_139 ;
else
V_134 = V_140 ;
V_135 = F_7 ( V_134 ) ;
if ( F_16 ( V_11 ) ) {
if ( ( V_135 & V_128 ) == 0 )
return;
if ( V_13 -> V_129 . V_141 . V_142 ) {
F_36 ( L_10 ) ;
return;
}
}
V_136 = V_143 ;
if ( ! F_73 ( V_13 , & V_136 ) ) {
if ( ( V_135 & V_21 ) == 0 ) {
F_36 ( L_11 ) ;
return;
}
F_36 ( L_12 ) ;
}
if ( F_13 ( V_13 ) -> V_33 < 5 &&
F_7 ( V_144 ) == 0 && F_7 ( V_145 ) == 0 ) {
F_21 ( V_144 , 0x019007d0 ) ;
F_21 ( V_145 , 0x015e07d0 ) ;
F_36 ( L_13 ) ;
}
V_15 = F_74 ( sizeof( * V_15 ) , V_146 ) ;
if ( ! V_15 )
return;
V_92 = F_74 ( sizeof( * V_92 ) , V_146 ) ;
if ( ! V_92 ) {
F_57 ( V_15 ) ;
return;
}
if ( F_75 ( & V_92 -> V_4 ) < 0 ) {
F_57 ( V_92 ) ;
F_57 ( V_15 ) ;
return;
}
V_15 -> V_60 = V_92 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_59 = & V_92 -> V_4 ;
V_7 = & V_59 -> V_4 ;
F_76 ( V_11 , & V_59 -> V_4 , & V_147 ,
V_148 ) ;
F_77 ( V_11 , & V_8 -> V_4 , & V_149 ,
V_150 , NULL ) ;
V_8 -> V_122 = F_22 ;
V_8 -> V_151 = F_14 ;
V_8 -> V_152 = F_35 ;
if ( F_16 ( V_13 ) ) {
V_8 -> V_153 = F_30 ;
V_8 -> V_154 = F_31 ;
} else {
V_8 -> V_153 = F_28 ;
}
V_8 -> V_155 = F_4 ;
V_8 -> V_156 = F_12 ;
V_59 -> V_155 = V_157 ;
V_59 -> V_158 = V_159 ;
F_78 ( V_59 , V_8 ) ;
V_8 -> type = V_123 ;
V_8 -> V_160 = 0 ;
if ( F_16 ( V_11 ) )
V_8 -> V_161 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_79 ( V_11 ) )
V_8 -> V_161 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_161 = ( 1 << 1 ) ;
F_80 ( V_7 , & V_162 ) ;
V_7 -> V_163 . V_164 = V_165 ;
V_7 -> V_166 = false ;
V_7 -> V_167 = false ;
V_15 -> V_20 = V_134 ;
F_81 ( V_11 ) ;
F_82 ( & V_7 -> V_4 ,
V_11 -> V_116 . V_117 ,
V_168 ) ;
V_59 -> V_72 . V_84 = V_168 ;
F_50 ( & V_11 -> V_116 . V_169 ) ;
if ( F_83 () & V_170 )
V_93 = F_84 ( V_7 ,
F_85 ( V_13 , V_136 ) ) ;
else
V_93 = F_86 ( V_7 ,
F_85 ( V_13 , V_136 ) ) ;
if ( V_93 ) {
if ( F_44 ( V_7 , V_93 ) ) {
F_87 ( V_7 ,
V_93 ) ;
} else {
F_57 ( V_93 ) ;
V_93 = F_88 ( - V_120 ) ;
}
} else {
V_93 = F_88 ( - V_171 ) ;
}
V_92 -> V_4 . V_93 = V_93 ;
if ( F_43 ( V_93 ) ) {
V_7 -> V_163 . V_172 = 0 ;
V_7 -> V_163 . V_173 = 200 ;
V_7 -> V_163 . V_174 = 0 ;
V_7 -> V_163 . V_175 = 200 ;
}
F_89 (scan, &connector->probed_modes, head) {
if ( V_132 -> type & V_176 ) {
F_36 ( L_14 ) ;
F_90 ( V_132 ) ;
V_71 = F_45 ( V_11 , V_132 ) ;
if ( V_71 )
goto V_22;
}
}
if ( V_13 -> V_129 . V_177 ) {
F_36 ( L_15 ) ;
F_90 ( V_13 -> V_129 . V_177 ) ;
V_71 = F_45 ( V_11 , V_13 -> V_129 . V_177 ) ;
if ( V_71 ) {
V_71 -> type |= V_176 ;
V_7 -> V_163 . V_178 = V_71 -> V_178 ;
V_7 -> V_163 . V_179 = V_71 -> V_179 ;
goto V_22;
}
}
if ( F_16 ( V_11 ) )
goto V_180;
V_9 = ( V_135 & V_50 ) ? 1 : 0 ;
V_43 = F_91 ( V_11 , V_9 ) ;
if ( V_43 && ( V_135 & V_21 ) ) {
V_71 = F_92 ( V_11 , V_43 ) ;
if ( V_71 ) {
F_36 ( L_16 ) ;
F_90 ( V_71 ) ;
V_71 -> type |= V_176 ;
goto V_22;
}
}
if ( ! V_71 )
goto V_180;
V_22:
F_54 ( & V_11 -> V_116 . V_169 ) ;
F_93 ( & V_59 -> V_72 , V_71 , V_133 ) ;
V_15 -> V_51 = F_67 ( V_15 ) ;
F_36 ( L_17 ,
V_15 -> V_51 ? L_18 : L_19 ) ;
V_15 -> V_55 = V_135 & V_54 ;
V_92 -> V_100 . V_112 = F_49 ;
if ( F_94 ( & V_92 -> V_100 ) ) {
F_36 ( L_20 ) ;
V_92 -> V_100 . V_112 = NULL ;
}
F_95 ( V_7 ) ;
F_96 ( V_7 , V_181 ) ;
return;
V_180:
F_54 ( & V_11 -> V_116 . V_169 ) ;
F_36 ( L_21 ) ;
F_59 ( V_7 ) ;
F_97 ( V_3 ) ;
F_57 ( V_15 ) ;
F_57 ( V_92 ) ;
return;
}
