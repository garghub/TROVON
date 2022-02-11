const char *
F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
case V_9 :
return L_7 ;
case V_10 :
return L_8 ;
case V_11 :
return L_9 ;
case V_12 :
return L_10 ;
case V_13 :
return L_11 ;
case V_14 :
return L_12 ;
case V_15 :
return L_13 ;
case V_16 :
return L_14 ;
case V_17 :
return L_15 ;
case V_18 :
return L_16 ;
case V_19 :
return L_17 ;
case V_20 :
return L_18 ;
case V_21 :
return L_19 ;
case V_22 :
return L_20 ;
case V_23 :
return L_21 ;
case V_24 :
return L_22 ;
case V_25 :
return L_23 ;
case V_26 :
return L_24 ;
case V_27 :
return L_25 ;
case V_28 :
return L_26 ;
case V_29 :
return L_27 ;
case V_30 :
return L_28 ;
case V_31 :
return L_29 ;
case V_32 :
return L_30 ;
case V_33 :
return L_31 ;
case V_34 :
return L_32 ;
case V_35 :
return L_33 ;
case V_36 :
return L_34 ;
case V_37 :
return L_35 ;
default:
F_2 ( V_2 ) ;
return L_36 ;
}
}
static void F_3 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_4 ( L_37 , V_41 -> V_42 ) ;
V_41 -> V_43 -> V_44 ( V_39 , V_41 ) ;
V_41 -> V_45 = true ;
}
static void F_5 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_4 ( L_38 , V_41 -> V_42 ) ;
V_41 -> V_45 = false ;
V_41 -> V_43 -> V_46 ( V_39 , V_41 ) ;
}
static void F_6 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( ! V_41 -> V_47 ++ )
F_3 ( V_39 , V_41 ) ;
}
static void F_7 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_8 ( ! V_41 -> V_47 , L_39 ,
V_41 -> V_42 ) ;
if ( ! -- V_41 -> V_47 )
F_5 ( V_39 , V_41 ) ;
}
bool F_9 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_40 * V_41 ;
bool V_48 ;
if ( V_39 -> V_49 . V_50 )
return false ;
V_48 = true ;
F_10 (dev_priv, power_well, BIT_ULL(domain)) {
if ( V_41 -> V_51 )
continue;
if ( ! V_41 -> V_45 ) {
V_48 = false ;
break;
}
}
return V_48 ;
}
bool F_11 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_52 * V_53 ;
bool V_54 ;
V_53 = & V_39 -> V_53 ;
F_12 ( & V_53 -> V_55 ) ;
V_54 = F_9 ( V_39 , V_2 ) ;
F_13 ( & V_53 -> V_55 ) ;
return V_54 ;
}
void F_14 ( struct V_38 * V_39 ,
bool V_44 )
{
if ( V_39 -> V_53 . V_56 == V_44 )
return;
if ( V_44 )
F_15 ( V_39 , V_36 ) ;
else
F_16 ( V_39 , V_36 ) ;
V_39 -> V_53 . V_56 = V_44 ;
}
static void F_17 ( struct V_38 * V_39 ,
T_1 V_57 , bool V_58 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
if ( V_58 ) {
F_18 ( V_60 , V_62 ) ;
F_19 ( F_20 ( V_63 ) , V_64 ) ;
F_21 ( V_60 , V_62 ) ;
}
if ( V_57 )
F_22 ( V_39 , V_57 ) ;
}
static void F_23 ( struct V_38 * V_39 ,
T_1 V_57 )
{
if ( V_57 )
F_24 ( V_39 , V_57 ) ;
}
static void F_25 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
F_26 ( F_27 ( V_39 ,
F_28 ( V_66 ) ,
F_29 ( V_66 ) ,
F_29 ( V_66 ) ,
1 ) ) ;
}
static T_2 F_30 ( struct V_38 * V_39 ,
enum V_65 V_66 )
{
T_2 V_67 = F_31 ( V_66 ) ;
T_2 V_54 ;
V_54 = F_32 ( F_33 ( V_66 ) ) & V_67 ? 1 : 0 ;
V_54 |= F_32 ( F_28 ( V_66 ) ) & V_67 ? 2 : 0 ;
V_54 |= F_32 ( V_68 ) & V_67 ? 4 : 0 ;
V_54 |= F_32 ( F_34 ( V_66 ) ) & V_67 ? 8 : 0 ;
return V_54 ;
}
static void F_35 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
bool V_69 ;
T_2 V_70 ;
F_36 ( ( V_69 = ! ( F_32 ( F_28 ( V_66 ) ) &
F_29 ( V_66 ) ) ) ||
( V_70 = F_30 ( V_39 , V_66 ) ) , 1 ) ;
if ( V_69 )
return;
F_4 ( L_40 ,
V_41 -> V_42 ,
! ! ( V_70 & 1 ) , ! ! ( V_70 & 2 ) , ! ! ( V_70 & 4 ) , ! ! ( V_70 & 8 ) ) ;
}
static void F_37 ( struct V_38 * V_39 ,
enum V_71 V_72 )
{
F_26 ( F_27 ( V_39 , V_73 ,
F_38 ( V_72 ) ,
F_38 ( V_72 ) , 1 ) ) ;
}
static void F_39 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
bool V_74 = V_41 -> V_75 . V_76 ;
enum V_71 V_77 ( V_72 ) ;
T_2 V_78 ;
if ( V_74 ) {
V_72 = F_40 ( V_66 ) ;
if ( V_72 == V_79 )
F_37 ( V_39 , V_80 ) ;
}
V_78 = F_32 ( F_28 ( V_66 ) ) ;
F_41 ( F_28 ( V_66 ) , V_78 | F_31 ( V_66 ) ) ;
F_25 ( V_39 , V_41 ) ;
if ( V_74 )
F_37 ( V_39 , V_72 ) ;
F_17 ( V_39 , V_41 -> V_75 . V_57 ,
V_41 -> V_75 . V_58 ) ;
}
static void F_42 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
T_2 V_78 ;
F_23 ( V_39 , V_41 -> V_75 . V_57 ) ;
V_78 = F_32 ( F_28 ( V_66 ) ) ;
F_41 ( F_28 ( V_66 ) ,
V_78 & ~ F_31 ( V_66 ) ) ;
F_35 ( V_39 , V_41 ) ;
}
static bool F_43 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
T_2 V_81 = F_31 ( V_66 ) | F_29 ( V_66 ) ;
return ( F_32 ( F_28 ( V_66 ) ) & V_81 ) == V_81 ;
}
static void F_44 ( struct V_38 * V_39 )
{
enum V_65 V_66 = V_82 ;
F_45 ( ( F_32 ( V_83 ) & V_84 ) ,
L_41 ) ;
F_45 ( F_32 ( V_83 ) & V_85 ,
L_42 ) ;
F_45 ( F_32 ( F_28 ( V_66 ) ) &
F_31 ( V_66 ) ,
L_43 ) ;
F_45 ( F_46 ( V_39 ) ,
L_44 ) ;
}
static void F_47 ( struct V_38 * V_39 )
{
F_45 ( F_46 ( V_39 ) ,
L_44 ) ;
F_45 ( F_32 ( V_83 ) & V_85 ,
L_45 ) ;
}
static void F_48 ( struct V_38 * V_39 ,
T_2 V_86 )
{
int V_87 = 0 ;
int V_88 = 0 ;
T_2 V_89 ;
F_41 ( V_83 , V_86 ) ;
do {
V_89 = F_32 ( V_83 ) ;
if ( V_89 != V_86 ) {
F_41 ( V_83 , V_86 ) ;
V_87 ++ ;
V_88 = 0 ;
} else if ( V_88 ++ > 5 ) {
break;
}
} while ( V_87 < 100 );
if ( V_89 != V_86 )
F_49 ( L_46 ,
V_86 , V_89 ) ;
if ( V_87 > 1 )
F_4 ( L_47 ,
V_86 , V_87 ) ;
}
static T_2 F_50 ( struct V_38 * V_39 )
{
T_2 V_81 ;
V_81 = V_85 ;
if ( F_51 ( V_39 ) )
V_81 |= V_84 ;
else
V_81 |= V_90 ;
return V_81 ;
}
void F_52 ( struct V_38 * V_39 )
{
T_2 V_78 ;
V_78 = F_32 ( V_83 ) & F_50 ( V_39 ) ;
F_4 ( L_48 ,
V_39 -> V_91 . V_92 , V_78 ) ;
V_39 -> V_91 . V_92 = V_78 ;
}
static void F_53 ( struct V_38 * V_39 , T_3 V_86 )
{
T_3 V_78 ;
T_3 V_81 ;
if ( F_54 ( V_86 & ~ V_39 -> V_91 . V_93 ) )
V_86 &= V_39 -> V_91 . V_93 ;
V_78 = F_32 ( V_83 ) ;
V_81 = F_50 ( V_39 ) ;
F_4 ( L_49 ,
V_78 & V_81 , V_86 ) ;
if ( ( V_78 & V_81 ) != V_39 -> V_91 . V_92 )
F_49 ( L_50 ,
V_39 -> V_91 . V_92 , V_78 & V_81 ) ;
V_78 &= ~ V_81 ;
V_78 |= V_86 ;
F_48 ( V_39 , V_78 ) ;
V_39 -> V_91 . V_92 = V_78 & V_81 ;
}
void F_55 ( struct V_38 * V_39 )
{
F_44 ( V_39 ) ;
F_4 ( L_51 ) ;
F_56 ( V_39 ) ;
F_53 ( V_39 , V_84 ) ;
}
void F_57 ( struct V_38 * V_39 )
{
F_47 ( V_39 ) ;
F_4 ( L_52 ) ;
F_53 ( V_39 , V_94 ) ;
F_58 ( V_39 ) ;
}
static void F_59 ( struct V_38 * V_39 )
{
F_45 ( ! F_32 ( F_60 ( 0 ) ) ,
L_53 ) ;
F_45 ( ! F_32 ( V_95 ) , L_54 ) ;
F_45 ( ! F_32 ( V_96 ) , L_55 ) ;
}
static void F_61 ( struct V_38 * V_39 )
{
bool V_97 = F_62 ( V_39 ,
V_82 ) ;
F_45 ( V_97 , L_56 ) ;
F_45 ( ( F_32 ( V_83 ) & V_85 ) ,
L_57 ) ;
F_63 ( V_39 ) ;
F_59 ( V_39 ) ;
}
void F_64 ( struct V_38 * V_39 )
{
F_61 ( V_39 ) ;
F_4 ( L_58 ) ;
F_53 ( V_39 , V_85 ) ;
}
static void F_65 ( struct V_38 * V_39 )
{
F_45 ( F_32 ( V_98 ) & V_99 ,
L_59 ) ;
F_45 ( ( F_32 ( V_83 ) & V_90 ) ,
L_60 ) ;
F_59 ( V_39 ) ;
}
void F_66 ( struct V_38 * V_39 )
{
F_65 ( V_39 ) ;
F_4 ( L_61 ) ;
F_53 ( V_39 , V_90 ) ;
}
void F_67 ( struct V_38 * V_39 )
{
F_4 ( L_62 ) ;
F_53 ( V_39 , V_94 ) ;
}
static void F_68 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_66 = V_41 -> V_66 ;
T_2 V_81 = F_31 ( V_66 ) ;
T_2 V_100 = F_32 ( F_33 ( V_66 ) ) ;
if ( V_100 & V_81 ) {
T_2 V_101 = F_32 ( F_28 ( V_66 ) ) ;
if ( ! ( V_101 & V_81 ) )
F_41 ( F_28 ( V_66 ) , V_101 | V_81 ) ;
F_41 ( F_33 ( V_66 ) , V_100 & ~ V_81 ) ;
}
}
static void F_69 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_70 ( V_39 , V_41 -> V_102 . V_103 ) ;
}
static void F_71 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_72 ( V_39 , V_41 -> V_102 . V_103 ) ;
}
static bool F_73 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return F_74 ( V_39 , V_41 -> V_102 . V_103 ) ;
}
static void F_75 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
V_41 = F_76 ( V_39 , V_104 ) ;
if ( V_41 -> V_47 > 0 )
F_77 ( V_39 , V_41 -> V_102 . V_103 ) ;
V_41 = F_76 ( V_39 , V_105 ) ;
if ( V_41 -> V_47 > 0 )
F_77 ( V_39 , V_41 -> V_102 . V_103 ) ;
if ( F_78 ( V_39 ) ) {
V_41 = F_76 ( V_39 , V_106 ) ;
if ( V_41 -> V_47 > 0 )
F_77 ( V_39 , V_41 -> V_102 . V_103 ) ;
}
}
static bool F_79 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return ( F_32 ( V_83 ) & V_107 ) == 0 ;
}
static void F_80 ( struct V_38 * V_39 )
{
T_2 V_108 = F_32 ( V_109 ) ;
F_8 ( ( V_108 & ( V_110 | V_111 ) ) !=
( V_110 | V_111 ) ,
L_63 , V_108 ) ;
}
static void F_81 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_112 V_113 = {} ;
F_53 ( V_39 , V_94 ) ;
V_39 -> V_114 . V_115 ( V_39 , & V_113 ) ;
F_26 ( ! F_82 ( & V_39 -> V_116 . V_117 , & V_113 ) ) ;
F_80 ( V_39 ) ;
if ( F_51 ( V_39 ) )
F_75 ( V_39 ) ;
}
static void F_83 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( ! V_39 -> V_91 . V_118 )
return;
if ( V_39 -> V_91 . V_93 & V_90 )
F_66 ( V_39 ) ;
else if ( V_39 -> V_91 . V_93 & V_85 )
F_64 ( V_39 ) ;
}
static void F_84 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
}
static void F_85 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
}
static bool F_86 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return true ;
}
static void F_87 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( ( F_32 ( F_88 ( V_119 ) ) & V_120 ) == 0 )
F_89 ( V_39 , V_119 ) ;
if ( ( F_32 ( F_88 ( V_121 ) ) & V_120 ) == 0 )
F_89 ( V_39 , V_121 ) ;
}
static void F_90 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_91 ( V_39 , V_121 ) ;
F_91 ( V_39 , V_119 ) ;
}
static bool F_92 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return F_32 ( F_88 ( V_119 ) ) & V_120 &&
F_32 ( F_88 ( V_121 ) ) & V_120 ;
}
static void F_93 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( V_41 -> V_47 > 0 )
F_87 ( V_39 , V_41 ) ;
else
F_90 ( V_39 , V_41 ) ;
}
static void F_94 ( struct V_38 * V_39 ,
struct V_40 * V_41 , bool V_44 )
{
enum V_65 V_122 = V_41 -> V_66 ;
T_2 V_81 ;
T_2 V_86 ;
T_2 V_123 ;
V_81 = F_95 ( V_122 ) ;
V_86 = V_44 ? F_96 ( V_122 ) :
F_97 ( V_122 ) ;
F_12 ( & V_39 -> V_124 . V_125 ) ;
#define F_98 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_98 )
goto V_126;
V_123 = F_99 ( V_39 , V_127 ) ;
V_123 &= ~ V_81 ;
V_123 |= V_86 ;
F_100 ( V_39 , V_127 , V_123 ) ;
if ( F_36 ( F_98 , 100 ) )
F_49 ( L_64 ,
V_86 ,
F_99 ( V_39 , V_127 ) ) ;
#undef F_98
V_126:
F_13 ( & V_39 -> V_124 . V_125 ) ;
}
static void F_101 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_94 ( V_39 , V_41 , true ) ;
}
static void F_102 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_94 ( V_39 , V_41 , false ) ;
}
static bool F_103 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_65 V_122 = V_41 -> V_66 ;
bool V_128 = false ;
T_2 V_81 ;
T_2 V_86 ;
T_2 V_123 ;
V_81 = F_95 ( V_122 ) ;
V_123 = F_96 ( V_122 ) ;
F_12 ( & V_39 -> V_124 . V_125 ) ;
V_86 = F_99 ( V_39 , V_129 ) & V_81 ;
F_26 ( V_86 != F_96 ( V_122 ) &&
V_86 != F_97 ( V_122 ) ) ;
if ( V_86 == V_123 )
V_128 = true ;
V_123 = F_99 ( V_39 , V_127 ) & V_81 ;
F_26 ( V_123 != V_86 ) ;
F_13 ( & V_39 -> V_124 . V_125 ) ;
return V_128 ;
}
static void F_104 ( struct V_38 * V_39 )
{
T_2 V_78 ;
V_78 = F_32 ( V_130 ) ;
V_78 &= V_131 ;
V_78 |= V_132 ;
F_41 ( V_130 , V_78 ) ;
F_41 ( V_133 , V_134 ) ;
F_41 ( V_135 , 0 ) ;
F_26 ( V_39 -> V_136 == 0 ) ;
F_41 ( V_137 ,
F_105 ( V_39 -> V_136 , 1000 ) ) ;
}
static void F_106 ( struct V_38 * V_39 )
{
struct V_138 * V_139 ;
enum V_140 V_140 ;
F_107 (dev_priv, pipe) {
T_2 V_78 = F_32 ( F_108 ( V_140 ) ) ;
V_78 |= V_141 | V_142 ;
if ( V_140 != V_119 )
V_78 |= V_143 ;
F_41 ( F_108 ( V_140 ) , V_78 ) ;
}
F_104 ( V_39 ) ;
F_109 ( & V_39 -> V_144 ) ;
F_110 ( V_39 ) ;
F_111 ( & V_39 -> V_144 ) ;
if ( V_39 -> V_53 . V_145 )
return;
F_112 ( V_39 ) ;
F_113 (&dev_priv->drm, encoder) {
if ( V_139 -> type == V_146 )
F_114 ( & V_139 -> V_147 ) ;
}
F_115 ( V_39 ) ;
F_58 ( V_39 ) ;
}
static void F_116 ( struct V_38 * V_39 )
{
F_109 ( & V_39 -> V_144 ) ;
F_117 ( V_39 ) ;
F_111 ( & V_39 -> V_144 ) ;
F_118 ( V_39 -> V_61 . V_148 ) ;
F_56 ( V_39 ) ;
if ( ! V_39 -> V_61 . V_149 -> V_150 . V_151 )
F_119 ( V_39 ) ;
}
static void F_120 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_54 ( V_41 -> V_66 != V_152 ) ;
F_94 ( V_39 , V_41 , true ) ;
F_106 ( V_39 ) ;
}
static void F_121 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_54 ( V_41 -> V_66 != V_152 ) ;
F_116 ( V_39 ) ;
F_94 ( V_39 , V_41 , false ) ;
}
static void F_122 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_54 ( V_41 -> V_66 != V_153 ) ;
F_123 ( 1 ) ;
F_94 ( V_39 , V_41 , true ) ;
F_41 ( V_154 , F_32 ( V_154 ) | V_155 ) ;
}
static void F_124 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_140 V_140 ;
F_54 ( V_41 -> V_66 != V_153 ) ;
F_107 (dev_priv, pipe)
F_125 ( V_39 , V_140 ) ;
F_41 ( V_154 , F_32 ( V_154 ) & ~ V_155 ) ;
F_94 ( V_39 , V_41 , false ) ;
}
static struct V_40 *
F_76 ( struct V_38 * V_39 ,
enum V_65 V_122 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
int V_156 ;
for ( V_156 = 0 ; V_156 < V_53 -> V_157 ; V_156 ++ ) {
struct V_40 * V_41 ;
V_41 = & V_53 -> V_158 [ V_156 ] ;
if ( V_41 -> V_66 == V_122 )
return V_41 ;
}
return NULL ;
}
static void F_126 ( struct V_38 * V_39 )
{
struct V_40 * V_159 =
F_76 ( V_39 , V_153 ) ;
struct V_40 * V_160 =
F_76 ( V_39 , V_161 ) ;
T_2 V_162 = V_39 -> V_163 ;
T_2 V_164 = 0 ;
T_2 V_165 = 0xffffffff ;
if ( ! V_39 -> V_166 [ V_167 ] )
V_165 &= ~ ( F_127 ( V_167 , V_168 ) |
F_128 ( V_167 , V_168 , 0 ) |
F_128 ( V_167 , V_168 , 1 ) |
F_127 ( V_167 , V_169 ) |
F_128 ( V_167 , V_169 , 0 ) |
F_128 ( V_167 , V_169 , 1 ) ) ;
if ( ! V_39 -> V_166 [ V_170 ] )
V_165 &= ~ ( F_127 ( V_170 , V_168 ) |
F_128 ( V_170 , V_168 , 0 ) |
F_128 ( V_170 , V_168 , 1 ) ) ;
if ( V_159 -> V_43 -> V_48 ( V_39 , V_159 ) ) {
V_164 |= F_129 ( V_167 ) ;
if ( ( V_162 & F_130 ( V_167 , V_168 ) ) == 0 )
V_162 |= F_131 ( 0xf , V_167 , V_168 ) ;
if ( ( V_162 & F_130 ( V_167 , V_169 ) ) == 0 )
V_162 |= F_131 ( 0xf , V_167 , V_169 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xf , V_167 , V_168 ) |
F_131 ( 0xf , V_167 , V_169 ) ) )
V_164 |= F_127 ( V_167 , V_168 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xf , V_167 , V_169 ) ) &&
( F_32 ( F_108 ( V_121 ) ) & V_171 ) == 0 )
V_164 |= F_127 ( V_167 , V_169 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0x3 , V_167 , V_168 ) ) )
V_164 |= F_128 ( V_167 , V_168 , 0 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xc , V_167 , V_168 ) ) )
V_164 |= F_128 ( V_167 , V_168 , 1 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0x3 , V_167 , V_169 ) ) )
V_164 |= F_128 ( V_167 , V_169 , 0 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xc , V_167 , V_169 ) ) )
V_164 |= F_128 ( V_167 , V_169 , 1 ) ;
}
if ( V_160 -> V_43 -> V_48 ( V_39 , V_160 ) ) {
V_164 |= F_129 ( V_170 ) ;
if ( ( V_162 & F_130 ( V_170 , V_168 ) ) == 0 )
V_162 |= F_131 ( 0xf , V_170 , V_168 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xf , V_170 , V_168 ) ) )
V_164 |= F_127 ( V_170 , V_168 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0x3 , V_170 , V_168 ) ) )
V_164 |= F_128 ( V_170 , V_168 , 0 ) ;
if ( F_132 ( V_162 ,
F_131 ( 0xc , V_170 , V_168 ) ) )
V_164 |= F_128 ( V_170 , V_168 , 1 ) ;
}
V_164 &= V_165 ;
if ( F_27 ( V_39 ,
V_172 ,
V_165 ,
V_164 ,
10 ) )
F_49 ( L_65 ,
F_32 ( V_172 ) & V_165 ,
V_164 , V_39 -> V_163 ) ;
}
static void F_133 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_173 V_103 ;
enum V_140 V_140 ;
T_3 V_108 ;
F_54 ( V_41 -> V_66 != V_153 &&
V_41 -> V_66 != V_161 ) ;
if ( V_41 -> V_66 == V_153 ) {
V_140 = V_119 ;
V_103 = V_167 ;
} else {
V_140 = V_174 ;
V_103 = V_170 ;
}
F_123 ( 1 ) ;
F_94 ( V_39 , V_41 , true ) ;
if ( F_27 ( V_39 ,
V_172 ,
F_129 ( V_103 ) ,
F_129 ( V_103 ) ,
1 ) )
F_49 ( L_66 , V_103 ) ;
F_12 ( & V_39 -> V_175 ) ;
V_108 = F_134 ( V_39 , V_140 , V_176 ) ;
V_108 |= V_177 | V_178 |
V_179 ;
F_135 ( V_39 , V_140 , V_176 , V_108 ) ;
if ( V_41 -> V_66 == V_153 ) {
V_108 = F_134 ( V_39 , V_140 , V_180 ) ;
V_108 |= V_181 ;
F_135 ( V_39 , V_140 , V_180 , V_108 ) ;
} else {
V_108 = F_134 ( V_39 , V_140 , V_182 ) ;
V_108 |= V_183 ;
F_135 ( V_39 , V_140 , V_182 , V_108 ) ;
}
F_13 ( & V_39 -> V_175 ) ;
V_39 -> V_163 |= F_136 ( V_103 ) ;
F_41 ( V_184 , V_39 -> V_163 ) ;
F_4 ( L_67 ,
V_103 , V_39 -> V_163 ) ;
F_126 ( V_39 ) ;
}
static void F_137 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_173 V_103 ;
F_54 ( V_41 -> V_66 != V_153 &&
V_41 -> V_66 != V_161 ) ;
if ( V_41 -> V_66 == V_153 ) {
V_103 = V_167 ;
F_125 ( V_39 , V_119 ) ;
F_125 ( V_39 , V_121 ) ;
} else {
V_103 = V_170 ;
F_125 ( V_39 , V_174 ) ;
}
V_39 -> V_163 &= ~ F_136 ( V_103 ) ;
F_41 ( V_184 , V_39 -> V_163 ) ;
F_94 ( V_39 , V_41 , false ) ;
F_4 ( L_68 ,
V_103 , V_39 -> V_163 ) ;
V_39 -> V_166 [ V_103 ] = true ;
F_126 ( V_39 ) ;
}
static void F_138 ( struct V_38 * V_39 , enum V_173 V_103 ,
enum V_185 V_186 , bool V_187 , unsigned int V_81 )
{
enum V_140 V_140 = V_103 == V_167 ? V_119 : V_174 ;
T_2 V_188 , V_78 , V_189 , V_190 ;
if ( ! V_39 -> V_166 [ V_103 ] )
return;
if ( V_186 == V_168 )
V_188 = V_191 ;
else
V_188 = V_180 ;
F_12 ( & V_39 -> V_175 ) ;
V_78 = F_134 ( V_39 , V_140 , V_188 ) ;
F_13 ( & V_39 -> V_175 ) ;
if ( ! V_187 || V_81 == 0xf ) {
V_189 = V_192 | V_193 ;
if ( V_186 == V_169 && V_78 == 0 )
V_189 = 0 ;
} else if ( V_81 != 0x0 ) {
V_189 = V_193 ;
} else {
V_189 = 0 ;
}
if ( V_186 == V_168 )
V_190 = V_78 >> V_194 ;
else
V_190 = V_78 >> V_195 ;
V_190 &= V_192 | V_193 ;
F_8 ( V_190 != V_189 ,
L_69 ,
! ! ( V_190 & V_192 ) , ! ! ( V_190 & V_193 ) ,
! ! ( V_189 & V_192 ) , ! ! ( V_189 & V_193 ) ,
V_188 , V_78 ) ;
}
bool F_139 ( struct V_38 * V_39 , enum V_173 V_103 ,
enum V_185 V_186 , bool V_187 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
bool V_196 ;
F_12 ( & V_53 -> V_55 ) ;
V_196 = V_39 -> V_163 & F_130 ( V_103 , V_186 ) ;
if ( V_187 == V_196 )
goto V_126;
if ( V_187 )
V_39 -> V_163 |= F_130 ( V_103 , V_186 ) ;
else
V_39 -> V_163 &= ~ F_130 ( V_103 , V_186 ) ;
F_41 ( V_184 , V_39 -> V_163 ) ;
F_4 ( L_70 ,
V_103 , V_186 , V_39 -> V_163 ) ;
F_126 ( V_39 ) ;
V_126:
F_13 ( & V_53 -> V_55 ) ;
return V_196 ;
}
void F_140 ( struct V_138 * V_139 ,
bool V_187 , unsigned int V_81 )
{
struct V_38 * V_39 = F_141 ( V_139 -> V_147 . V_149 ) ;
struct V_52 * V_53 = & V_39 -> V_53 ;
enum V_173 V_103 = F_142 ( F_143 ( & V_139 -> V_147 ) ) ;
enum V_185 V_186 = F_144 ( F_143 ( & V_139 -> V_147 ) ) ;
F_12 ( & V_53 -> V_55 ) ;
V_39 -> V_163 &= ~ F_131 ( 0xf , V_103 , V_186 ) ;
V_39 -> V_163 |= F_131 ( V_81 , V_103 , V_186 ) ;
if ( V_187 )
V_39 -> V_163 |= F_130 ( V_103 , V_186 ) ;
else
V_39 -> V_163 &= ~ F_130 ( V_103 , V_186 ) ;
F_41 ( V_184 , V_39 -> V_163 ) ;
F_4 ( L_71 ,
V_103 , V_186 , V_81 , V_39 -> V_163 ) ;
F_126 ( V_39 ) ;
F_138 ( V_39 , V_103 , V_186 , V_187 , V_81 ) ;
F_13 ( & V_53 -> V_55 ) ;
}
static bool F_145 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_140 V_140 = V_119 ;
bool V_128 ;
T_2 V_86 , V_123 ;
F_12 ( & V_39 -> V_124 . V_125 ) ;
V_86 = F_99 ( V_39 , V_197 ) & F_146 ( V_140 ) ;
F_26 ( V_86 != F_147 ( V_140 ) && V_86 != F_148 ( V_140 ) ) ;
V_128 = V_86 == F_147 ( V_140 ) ;
V_123 = F_99 ( V_39 , V_197 ) & F_149 ( V_140 ) ;
F_26 ( V_123 << 16 != V_86 ) ;
F_13 ( & V_39 -> V_124 . V_125 ) ;
return V_128 ;
}
static void F_150 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
bool V_44 )
{
enum V_140 V_140 = V_119 ;
T_2 V_86 ;
T_2 V_123 ;
V_86 = V_44 ? F_147 ( V_140 ) : F_148 ( V_140 ) ;
F_12 ( & V_39 -> V_124 . V_125 ) ;
#define F_98 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_98 )
goto V_126;
V_123 = F_99 ( V_39 , V_197 ) ;
V_123 &= ~ F_149 ( V_140 ) ;
V_123 |= V_44 ? F_151 ( V_140 ) : F_152 ( V_140 ) ;
F_100 ( V_39 , V_197 , V_123 ) ;
if ( F_36 ( F_98 , 100 ) )
F_49 ( L_64 ,
V_86 ,
F_99 ( V_39 , V_197 ) ) ;
#undef F_98
V_126:
F_13 ( & V_39 -> V_124 . V_125 ) ;
}
static void F_153 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_54 ( V_41 -> V_66 != V_198 ) ;
F_150 ( V_39 , V_41 , true ) ;
F_106 ( V_39 ) ;
}
static void F_154 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_54 ( V_41 -> V_66 != V_198 ) ;
F_116 ( V_39 ) ;
F_150 ( V_39 , V_41 , false ) ;
}
static void
F_155 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_41 ;
F_156 (dev_priv, power_well, BIT_ULL(domain))
F_6 ( V_39 , V_41 ) ;
V_53 -> V_199 [ V_2 ] ++ ;
}
void F_15 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
F_157 ( V_39 ) ;
F_12 ( & V_53 -> V_55 ) ;
F_155 ( V_39 , V_2 ) ;
F_13 ( & V_53 -> V_55 ) ;
}
bool F_158 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
bool V_48 ;
if ( ! F_159 ( V_39 ) )
return false ;
F_12 ( & V_53 -> V_55 ) ;
if ( F_9 ( V_39 , V_2 ) ) {
F_155 ( V_39 , V_2 ) ;
V_48 = true ;
} else {
V_48 = false ;
}
F_13 ( & V_53 -> V_55 ) ;
if ( ! V_48 )
F_160 ( V_39 ) ;
return V_48 ;
}
void F_16 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_52 * V_53 ;
struct V_40 * V_41 ;
V_53 = & V_39 -> V_53 ;
F_12 ( & V_53 -> V_55 ) ;
F_8 ( ! V_53 -> V_199 [ V_2 ] ,
L_72 ,
F_1 ( V_2 ) ) ;
V_53 -> V_199 [ V_2 ] -- ;
F_10 (dev_priv, power_well, BIT_ULL(domain))
F_7 ( V_39 , V_41 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_160 ( V_39 ) ;
}
bool F_62 ( struct V_38 * V_39 ,
enum V_65 V_122 )
{
struct V_40 * V_41 ;
bool V_54 ;
V_41 = F_76 ( V_39 , V_122 ) ;
V_54 = V_41 -> V_43 -> V_48 ( V_39 , V_41 ) ;
return V_54 ;
}
static int
F_161 ( const struct V_38 * V_39 ,
int V_200 )
{
if ( V_200 >= 0 )
return ! ! V_200 ;
return 1 ;
}
static T_3 F_162 ( const struct V_38 * V_39 ,
int V_201 )
{
T_3 V_81 ;
int V_202 ;
int V_203 ;
if ( F_163 ( V_39 ) || F_164 ( V_39 ) ) {
V_203 = 2 ;
V_81 = 0 ;
} else if ( F_51 ( V_39 ) ) {
V_203 = 1 ;
V_81 = V_84 ;
} else {
V_203 = 0 ;
V_81 = 0 ;
}
if ( ! V_204 . V_200 )
V_203 = 0 ;
if ( V_201 >= 0 && V_201 <= V_203 ) {
V_202 = V_201 ;
} else if ( V_201 == - 1 ) {
V_202 = V_203 ;
} else if ( V_201 > V_203 && V_201 <= 2 ) {
F_4 ( L_73 ,
V_201 , V_203 ) ;
V_202 = V_203 ;
} else {
F_49 ( L_74 , V_201 ) ;
V_202 = V_203 ;
}
if ( V_202 > 1 )
V_81 |= V_90 ;
if ( V_202 > 0 )
V_81 |= V_85 ;
F_4 ( L_75 , V_81 ) ;
return V_81 ;
}
static void F_165 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
T_4 V_205 ;
int V_156 ;
V_205 = 0 ;
for ( V_156 = 0 ; V_156 < V_53 -> V_157 ; V_156 ++ ) {
enum V_65 V_66 = V_53 -> V_158 [ V_156 ] . V_66 ;
F_26 ( V_66 >= sizeof( V_205 ) * 8 ) ;
F_26 ( V_205 & F_166 ( V_66 ) ) ;
V_205 |= F_166 ( V_66 ) ;
}
}
int F_167 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
V_204 . V_200 = F_161 ( V_39 ,
V_204 . V_200 ) ;
V_39 -> V_91 . V_93 = F_162 ( V_39 ,
V_204 . V_201 ) ;
F_168 ( V_206 > 64 ) ;
F_169 ( & V_53 -> V_55 ) ;
if ( F_170 ( V_39 ) ) {
F_171 ( V_53 , V_207 ) ;
} else if ( F_172 ( V_39 ) ) {
F_171 ( V_53 , V_208 ) ;
} else if ( F_163 ( V_39 ) ) {
F_171 ( V_53 , V_209 ) ;
} else if ( F_164 ( V_39 ) ) {
F_171 ( V_53 , V_210 ) ;
} else if ( F_173 ( V_39 ) ) {
F_171 ( V_53 , V_211 ) ;
} else if ( F_78 ( V_39 ) ) {
F_171 ( V_53 , V_212 ) ;
} else if ( F_174 ( V_39 ) ) {
F_171 ( V_53 , V_213 ) ;
} else if ( F_175 ( V_39 ) ) {
F_171 ( V_53 , V_214 ) ;
} else if ( F_176 ( V_39 ) ) {
F_171 ( V_53 , V_215 ) ;
} else {
F_171 ( V_53 , V_216 ) ;
}
F_165 ( V_39 ) ;
return 0 ;
}
void F_177 ( struct V_38 * V_39 )
{
struct V_217 * V_218 = & V_39 -> V_61 . V_60 -> V_149 ;
F_14 ( V_39 , true ) ;
if ( ! V_204 . V_200 )
F_16 ( V_39 , V_36 ) ;
if ( ! F_178 ( V_39 ) )
F_179 ( V_218 ) ;
}
static void F_180 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_41 ;
F_12 ( & V_53 -> V_55 ) ;
F_181 (dev_priv, power_well) {
V_41 -> V_43 -> V_219 ( V_39 , V_41 ) ;
V_41 -> V_45 = V_41 -> V_43 -> V_48 ( V_39 ,
V_41 ) ;
}
F_13 ( & V_53 -> V_55 ) ;
}
static void F_182 ( struct V_38 * V_39 )
{
F_41 ( V_109 , F_32 ( V_109 ) | V_111 ) ;
F_183 ( V_109 ) ;
F_123 ( 10 ) ;
if ( ! ( F_32 ( V_109 ) & V_110 ) )
F_49 ( L_76 ) ;
}
static void F_184 ( struct V_38 * V_39 )
{
F_41 ( V_109 , F_32 ( V_109 ) & ~ V_111 ) ;
F_183 ( V_109 ) ;
F_123 ( 10 ) ;
if ( F_32 ( V_109 ) & V_110 )
F_49 ( L_77 ) ;
}
static void F_185 ( struct V_38 * V_39 ,
bool V_220 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_221 ;
T_3 V_78 ;
F_53 ( V_39 , V_94 ) ;
V_78 = F_32 ( V_222 ) ;
F_41 ( V_222 , V_78 | V_223 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_3 ( V_39 , V_221 ) ;
V_221 = F_76 ( V_39 , V_225 ) ;
F_3 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_186 ( V_39 ) ;
F_182 ( V_39 ) ;
if ( V_220 && V_39 -> V_91 . V_118 )
F_187 ( V_39 ) ;
}
static void F_188 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_221 ;
F_53 ( V_39 , V_94 ) ;
F_184 ( V_39 ) ;
F_189 ( V_39 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_5 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_190 ( 10 , 30 ) ;
}
void F_191 ( struct V_38 * V_39 ,
bool V_220 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_221 ;
T_3 V_78 ;
F_53 ( V_39 , V_94 ) ;
V_78 = F_32 ( V_222 ) ;
V_78 &= ~ V_223 ;
F_41 ( V_222 , V_78 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_3 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_192 ( V_39 ) ;
F_182 ( V_39 ) ;
if ( V_220 && V_39 -> V_91 . V_118 )
F_187 ( V_39 ) ;
}
void F_193 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_221 ;
F_53 ( V_39 , V_94 ) ;
F_184 ( V_39 ) ;
F_194 ( V_39 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_5 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_190 ( 10 , 30 ) ;
}
static void F_195 ( struct V_38 * V_39 , bool V_220 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
const struct V_226 * V_227 ;
struct V_40 * V_221 ;
T_2 V_78 ;
F_53 ( V_39 , V_94 ) ;
V_78 = F_32 ( V_222 ) ;
V_78 |= V_223 ;
F_41 ( V_222 , V_78 ) ;
V_78 = F_32 ( V_228 ) ;
V_78 &= ~ V_229 ;
F_41 ( V_228 , V_78 ) ;
V_78 = F_32 ( V_230 ) ;
V_227 = & V_231 [ F_196 ( V_78 ) ] ;
F_26 ( V_227 -> V_232 == 0 ) ;
V_78 = F_32 ( V_233 ) ;
V_78 &= ~ ( ( 0xff << 16 ) | 0xff ) ;
V_78 |= V_227 -> V_234 ;
F_41 ( V_233 , V_78 ) ;
F_41 ( V_235 , V_227 -> V_236 ) ;
F_41 ( V_237 , V_227 -> V_232 ) ;
V_78 = F_32 ( V_238 ) ;
V_78 |= V_239 ;
F_41 ( V_238 , V_78 ) ;
V_78 = F_32 ( V_240 ) ;
V_78 |= V_241 ;
F_41 ( V_240 , V_78 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_3 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_197 ( V_39 ) ;
F_182 ( V_39 ) ;
if ( V_220 && V_39 -> V_91 . V_118 )
F_187 ( V_39 ) ;
}
static void F_198 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_221 ;
T_2 V_78 ;
F_53 ( V_39 , V_94 ) ;
F_184 ( V_39 ) ;
F_199 ( V_39 ) ;
F_12 ( & V_53 -> V_55 ) ;
V_221 = F_76 ( V_39 , V_224 ) ;
F_5 ( V_39 , V_221 ) ;
F_13 ( & V_53 -> V_55 ) ;
F_190 ( 10 , 30 ) ;
V_78 = F_32 ( V_228 ) ;
V_78 |= V_229 ;
F_41 ( V_228 , V_78 ) ;
}
static void F_200 ( struct V_38 * V_39 )
{
struct V_40 * V_159 =
F_76 ( V_39 , V_153 ) ;
struct V_40 * V_160 =
F_76 ( V_39 , V_161 ) ;
V_39 -> V_163 =
F_201 ( V_242 , V_167 ) |
F_201 ( V_242 , V_170 ) |
F_202 ( V_243 , V_167 , V_168 ) |
F_202 ( V_243 , V_167 , V_169 ) |
F_202 ( V_243 , V_170 , V_168 ) ;
if ( V_159 -> V_43 -> V_48 ( V_39 , V_159 ) ) {
T_3 V_244 = F_32 ( F_108 ( V_119 ) ) ;
unsigned int V_81 ;
V_81 = V_244 & V_245 ;
if ( V_81 == 0xf )
V_81 = 0x0 ;
else
V_39 -> V_163 |=
F_130 ( V_167 , V_168 ) ;
V_39 -> V_163 |=
F_131 ( V_81 , V_167 , V_168 ) ;
V_81 = ( V_244 & V_246 ) >> 4 ;
if ( V_81 == 0xf )
V_81 = 0x0 ;
else
V_39 -> V_163 |=
F_130 ( V_167 , V_169 ) ;
V_39 -> V_163 |=
F_131 ( V_81 , V_167 , V_169 ) ;
V_39 -> V_163 |= F_136 ( V_167 ) ;
V_39 -> V_166 [ V_167 ] = false ;
} else {
V_39 -> V_166 [ V_167 ] = true ;
}
if ( V_160 -> V_43 -> V_48 ( V_39 , V_160 ) ) {
T_3 V_244 = F_32 ( V_247 ) ;
unsigned int V_81 ;
V_81 = V_244 & V_248 ;
if ( V_81 == 0xf )
V_81 = 0x0 ;
else
V_39 -> V_163 |=
F_130 ( V_170 , V_168 ) ;
V_39 -> V_163 |=
F_131 ( V_81 , V_170 , V_168 ) ;
V_39 -> V_163 |= F_136 ( V_170 ) ;
V_39 -> V_166 [ V_170 ] = false ;
} else {
V_39 -> V_166 [ V_170 ] = true ;
}
F_41 ( V_184 , V_39 -> V_163 ) ;
F_4 ( L_78 ,
V_39 -> V_163 ) ;
}
static void F_203 ( struct V_38 * V_39 )
{
struct V_40 * V_249 =
F_76 ( V_39 , V_153 ) ;
struct V_40 * V_250 =
F_76 ( V_39 , V_152 ) ;
if ( V_249 -> V_43 -> V_48 ( V_39 , V_249 ) &&
V_250 -> V_43 -> V_48 ( V_39 , V_250 ) &&
F_32 ( V_154 ) & V_155 )
return;
F_4 ( L_79 ) ;
V_250 -> V_43 -> V_44 ( V_39 , V_250 ) ;
V_249 -> V_43 -> V_46 ( V_39 , V_249 ) ;
}
void F_204 ( struct V_38 * V_39 , bool V_220 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
V_53 -> V_145 = true ;
if ( F_164 ( V_39 ) ) {
F_195 ( V_39 , V_220 ) ;
} else if ( F_163 ( V_39 ) ) {
F_185 ( V_39 , V_220 ) ;
} else if ( F_51 ( V_39 ) ) {
F_191 ( V_39 , V_220 ) ;
} else if ( F_174 ( V_39 ) ) {
F_12 ( & V_53 -> V_55 ) ;
F_200 ( V_39 ) ;
F_13 ( & V_53 -> V_55 ) ;
} else if ( F_175 ( V_39 ) ) {
F_12 ( & V_53 -> V_55 ) ;
F_203 ( V_39 ) ;
F_13 ( & V_53 -> V_55 ) ;
}
F_14 ( V_39 , true ) ;
if ( ! V_204 . V_200 )
F_15 ( V_39 , V_36 ) ;
F_180 ( V_39 ) ;
V_53 -> V_145 = false ;
}
void F_205 ( struct V_38 * V_39 )
{
if ( ! V_204 . V_200 )
F_16 ( V_39 , V_36 ) ;
if ( F_164 ( V_39 ) )
F_198 ( V_39 ) ;
else if ( F_163 ( V_39 ) )
F_188 ( V_39 ) ;
else if ( F_51 ( V_39 ) )
F_193 ( V_39 ) ;
}
static void F_206 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_41 ;
F_181 (dev_priv, power_well) {
enum V_1 V_2 ;
F_207 ( L_80 ,
V_41 -> V_42 , V_41 -> V_47 ) ;
F_208 (domain, power_well->domains)
F_207 ( L_81 ,
F_1 ( V_2 ) ,
V_53 -> V_199 [ V_2 ] ) ;
}
}
void F_209 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = & V_39 -> V_53 ;
struct V_40 * V_41 ;
bool V_251 ;
F_12 ( & V_53 -> V_55 ) ;
V_251 = false ;
F_181 (dev_priv, power_well) {
enum V_1 V_2 ;
int V_252 ;
bool V_128 ;
if ( ! V_41 -> V_253 )
continue;
V_128 = V_41 -> V_43 -> V_48 ( V_39 , V_41 ) ;
if ( ( V_41 -> V_47 || V_41 -> V_51 ) != V_128 )
F_49 ( L_82 ,
V_41 -> V_42 , V_41 -> V_47 , V_128 ) ;
V_252 = 0 ;
F_208 (domain, power_well->domains)
V_252 += V_53 -> V_199 [ V_2 ] ;
if ( V_41 -> V_47 != V_252 ) {
F_49 ( L_83
L_84 ,
V_41 -> V_42 , V_41 -> V_47 ,
V_252 ) ;
V_251 = true ;
}
}
if ( V_251 ) {
static bool V_254 ;
if ( ! V_254 ) {
F_206 ( V_39 ) ;
V_254 = true ;
}
}
F_13 ( & V_53 -> V_55 ) ;
}
void F_157 ( struct V_38 * V_39 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
struct V_217 * V_218 = & V_60 -> V_149 ;
int V_54 ;
V_54 = F_210 ( V_218 ) ;
F_45 ( V_54 < 0 , L_85 , V_54 ) ;
F_211 ( & V_39 -> V_49 . V_255 ) ;
F_63 ( V_39 ) ;
}
bool F_159 ( struct V_38 * V_39 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
struct V_217 * V_218 = & V_60 -> V_149 ;
if ( F_212 ( V_256 ) ) {
int V_54 = F_213 ( V_218 ) ;
F_45 ( V_54 < 0 ,
L_86 , V_54 ) ;
if ( V_54 <= 0 )
return false ;
}
F_211 ( & V_39 -> V_49 . V_255 ) ;
F_63 ( V_39 ) ;
return true ;
}
void F_214 ( struct V_38 * V_39 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
struct V_217 * V_218 = & V_60 -> V_149 ;
F_63 ( V_39 ) ;
F_215 ( V_218 ) ;
F_211 ( & V_39 -> V_49 . V_255 ) ;
}
void F_160 ( struct V_38 * V_39 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
struct V_217 * V_218 = & V_60 -> V_149 ;
F_63 ( V_39 ) ;
F_216 ( & V_39 -> V_49 . V_255 ) ;
F_217 ( V_218 ) ;
F_218 ( V_218 ) ;
}
void F_219 ( struct V_38 * V_39 )
{
struct V_59 * V_60 = V_39 -> V_61 . V_60 ;
struct V_217 * V_218 = & V_60 -> V_149 ;
F_220 ( V_218 , 10000 ) ;
F_217 ( V_218 ) ;
if ( ! F_178 ( V_39 ) ) {
int V_54 ;
F_221 ( V_218 ) ;
V_54 = F_210 ( V_218 ) ;
F_8 ( V_54 < 0 , L_85 , V_54 ) ;
} else {
F_222 ( V_218 ) ;
}
F_218 ( V_218 ) ;
}
