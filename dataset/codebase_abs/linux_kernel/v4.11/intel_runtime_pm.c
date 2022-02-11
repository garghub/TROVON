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
default:
F_2 ( V_2 ) ;
return L_31 ;
}
}
static void F_3 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_4 ( L_32 , V_36 -> V_37 ) ;
V_36 -> V_38 -> V_39 ( V_34 , V_36 ) ;
V_36 -> V_40 = true ;
}
static void F_5 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_4 ( L_33 , V_36 -> V_37 ) ;
V_36 -> V_40 = false ;
V_36 -> V_38 -> V_41 ( V_34 , V_36 ) ;
}
static void F_6 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( ! V_36 -> V_42 ++ )
F_3 ( V_34 , V_36 ) ;
}
static void F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_8 ( ! V_36 -> V_42 , L_34 ,
V_36 -> V_37 ) ;
if ( ! -- V_36 -> V_42 )
F_5 ( V_34 , V_36 ) ;
}
static bool F_9 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return F_10 ( V_43 ) ==
( V_44 | V_45 ) ;
}
bool F_11 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 ;
struct V_35 * V_36 ;
bool V_48 ;
int V_49 ;
if ( V_34 -> V_50 . V_51 )
return false ;
V_47 = & V_34 -> V_47 ;
V_48 = true ;
F_12 (i, power_well, BIT(domain), power_domains) {
if ( V_36 -> V_52 )
continue;
if ( ! V_36 -> V_40 ) {
V_48 = false ;
break;
}
}
return V_48 ;
}
bool F_13 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 ;
bool V_53 ;
V_47 = & V_34 -> V_47 ;
F_14 ( & V_47 -> V_54 ) ;
V_53 = F_11 ( V_34 , V_2 ) ;
F_15 ( & V_47 -> V_54 ) ;
return V_53 ;
}
void F_16 ( struct V_33 * V_34 ,
bool V_39 )
{
if ( V_34 -> V_47 . V_55 == V_39 )
return;
if ( V_39 )
F_17 ( V_34 , V_31 ) ;
else
F_18 ( V_34 , V_31 ) ;
V_34 -> V_47 . V_55 = V_39 ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
F_20 ( V_57 , V_59 ) ;
F_21 ( F_22 ( V_60 ) , V_61 ) ;
F_23 ( V_57 , V_59 ) ;
if ( F_24 ( V_34 ) )
F_25 ( V_34 ,
1 << V_62 | 1 << V_63 ) ;
}
static void F_26 ( struct V_33 * V_34 )
{
if ( F_24 ( V_34 ) )
F_27 ( V_34 ,
1 << V_62 | 1 << V_63 ) ;
}
static void F_28 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
if ( V_36 -> V_64 == V_65 ) {
F_20 ( V_57 , V_59 ) ;
F_21 ( F_22 ( V_60 ) , V_61 ) ;
F_23 ( V_57 , V_59 ) ;
F_25 ( V_34 ,
1 << V_62 | 1 << V_63 ) ;
}
}
static void F_29 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_64 == V_65 )
F_27 ( V_34 ,
1 << V_62 | 1 << V_63 ) ;
}
static void F_30 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
bool V_48 , V_66 ;
T_1 V_67 ;
V_67 = F_10 ( V_43 ) ;
V_48 = V_67 & V_45 ;
V_66 = V_67 & V_44 ;
if ( V_39 ) {
if ( ! V_66 )
F_31 ( V_43 ,
V_44 ) ;
if ( ! V_48 ) {
F_4 ( L_35 ) ;
if ( F_32 ( V_34 ,
V_43 ,
V_45 ,
V_45 ,
20 ) )
F_33 ( L_36 ) ;
F_19 ( V_34 ) ;
}
} else {
if ( V_66 ) {
F_26 ( V_34 ) ;
F_31 ( V_43 , 0 ) ;
F_34 ( V_43 ) ;
F_4 ( L_37 ) ;
}
}
}
static void F_35 ( struct V_33 * V_34 )
{
F_36 ( ( F_10 ( V_68 ) & V_69 ) ,
L_38 ) ;
F_36 ( F_10 ( V_68 ) & V_70 ,
L_39 ) ;
F_36 ( F_10 ( V_43 ) , L_40 ) ;
F_36 ( F_37 ( V_34 ) ,
L_41 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
F_36 ( F_37 ( V_34 ) ,
L_41 ) ;
F_36 ( F_10 ( V_68 ) & V_70 ,
L_42 ) ;
}
static void F_39 ( struct V_33 * V_34 ,
T_2 V_71 )
{
int V_72 = 0 ;
int V_73 = 0 ;
T_2 V_74 ;
F_31 ( V_68 , V_71 ) ;
do {
V_74 = F_10 ( V_68 ) ;
if ( V_74 != V_71 ) {
F_31 ( V_68 , V_71 ) ;
V_72 ++ ;
V_73 = 0 ;
} else if ( V_73 ++ > 5 ) {
break;
}
} while ( V_72 < 100 );
if ( V_74 != V_71 )
F_33 ( L_43 ,
V_71 , V_74 ) ;
if ( V_72 > 1 )
F_4 ( L_44 ,
V_71 , V_72 ) ;
}
static T_2 F_40 ( struct V_33 * V_34 )
{
T_2 V_75 ;
V_75 = V_70 ;
if ( F_41 ( V_34 ) )
V_75 |= V_69 ;
else
V_75 |= V_76 ;
return V_75 ;
}
void F_42 ( struct V_33 * V_34 )
{
T_2 V_77 ;
V_77 = F_10 ( V_68 ) & F_40 ( V_34 ) ;
F_4 ( L_45 ,
V_34 -> V_78 . V_79 , V_77 ) ;
V_34 -> V_78 . V_79 = V_77 ;
}
static void F_43 ( struct V_33 * V_34 , T_1 V_71 )
{
T_1 V_77 ;
T_1 V_75 ;
if ( F_44 ( V_71 & ~ V_34 -> V_78 . V_80 ) )
V_71 &= V_34 -> V_78 . V_80 ;
V_77 = F_10 ( V_68 ) ;
V_75 = F_40 ( V_34 ) ;
F_4 ( L_46 ,
V_77 & V_75 , V_71 ) ;
if ( ( V_77 & V_75 ) != V_34 -> V_78 . V_79 )
F_33 ( L_47 ,
V_34 -> V_78 . V_79 , V_77 & V_75 ) ;
V_77 &= ~ V_75 ;
V_77 |= V_71 ;
F_39 ( V_34 , V_77 ) ;
V_34 -> V_78 . V_79 = V_77 & V_75 ;
}
void F_45 ( struct V_33 * V_34 )
{
F_35 ( V_34 ) ;
F_4 ( L_48 ) ;
F_46 ( V_34 ) ;
F_43 ( V_34 , V_69 ) ;
}
void F_47 ( struct V_33 * V_34 )
{
F_38 ( V_34 ) ;
F_4 ( L_49 ) ;
F_43 ( V_34 , V_81 ) ;
F_48 ( V_34 ) ;
}
static void F_49 ( struct V_33 * V_34 )
{
F_36 ( ! F_10 ( F_50 ( 0 ) ) ,
L_50 ) ;
F_36 ( ! F_10 ( V_82 ) , L_51 ) ;
F_36 ( ! F_10 ( V_83 ) , L_52 ) ;
}
static void F_51 ( struct V_33 * V_34 )
{
bool V_84 = F_52 ( V_34 ,
V_65 ) ;
F_36 ( V_84 , L_53 ) ;
F_36 ( ( F_10 ( V_68 ) & V_70 ) ,
L_54 ) ;
F_53 ( V_34 ) ;
F_49 ( V_34 ) ;
}
void F_54 ( struct V_33 * V_34 )
{
F_51 ( V_34 ) ;
F_4 ( L_55 ) ;
F_43 ( V_34 , V_70 ) ;
}
static void F_55 ( struct V_33 * V_34 )
{
F_36 ( F_10 ( V_85 ) & V_86 ,
L_56 ) ;
F_36 ( ( F_10 ( V_68 ) & V_76 ) ,
L_57 ) ;
F_49 ( V_34 ) ;
}
void F_56 ( struct V_33 * V_34 )
{
F_55 ( V_34 ) ;
F_4 ( L_58 ) ;
F_43 ( V_34 , V_76 ) ;
}
void F_57 ( struct V_33 * V_34 )
{
F_4 ( L_59 ) ;
F_43 ( V_34 , V_81 ) ;
}
static void
F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_87 V_88 = V_36 -> V_64 ;
T_2 V_77 ;
T_2 V_75 ;
V_75 = F_59 ( V_88 ) ;
V_77 = F_10 ( V_89 ) ;
if ( F_36 ( V_77 & V_75 , L_60 ,
V_36 -> V_37 ) )
F_31 ( V_89 , V_77 & ~ V_75 ) ;
V_77 = F_10 ( V_90 ) ;
V_77 |= F_10 ( V_91 ) ;
if ( ! ( V_77 & V_75 ) )
return;
if ( V_88 == V_92 ||
( ( F_60 ( V_34 ) || F_61 ( V_34 ) ) &&
V_88 == V_93 ) )
F_62 ( L_61
L_62 , V_36 -> V_37 ) ;
else
F_36 ( 1 , L_63 ,
V_36 -> V_37 ) ;
F_31 ( V_90 , V_77 & ~ V_75 ) ;
F_31 ( V_91 , V_77 & ~ V_75 ) ;
}
static void F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
T_1 V_67 , V_94 ;
T_1 V_95 , V_96 ;
bool V_48 , V_66 , V_97 = false ;
V_67 = F_10 ( V_43 ) ;
V_94 = F_10 ( V_98 ) ;
switch ( V_36 -> V_64 ) {
case V_92 :
if ( F_32 ( V_34 ,
V_98 ,
V_99 ,
V_99 ,
1 ) ) {
F_33 ( L_64 ) ;
return;
}
break;
case V_65 :
if ( ! ( V_94 & V_100 ) ) {
F_33 ( L_65 ) ;
return;
}
break;
case V_93 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
break;
default:
F_8 ( 1 , L_66 , V_36 -> V_64 ) ;
return;
}
V_95 = F_59 ( V_36 -> V_64 ) ;
V_66 = V_67 & V_95 ;
V_96 = F_64 ( V_36 -> V_64 ) ;
V_48 = V_67 & V_96 ;
if ( ! V_39 && V_66 )
F_29 ( V_34 , V_36 ) ;
if ( V_39 ) {
if ( ! V_66 ) {
F_8 ( ( V_67 & V_96 ) &&
! F_10 ( V_90 ) ,
L_67 ) ;
F_31 ( V_43 , V_67 | V_95 ) ;
}
if ( ! V_48 ) {
F_4 ( L_68 , V_36 -> V_37 ) ;
V_97 = true ;
}
} else {
if ( V_66 ) {
F_31 ( V_43 , V_67 & ~ V_95 ) ;
F_34 ( V_43 ) ;
F_4 ( L_69 , V_36 -> V_37 ) ;
}
if ( F_65 ( V_34 ) )
F_58 ( V_34 , V_36 ) ;
}
if ( F_66 ( ! ! ( F_10 ( V_43 ) & V_96 ) == V_39 ,
1 ) )
F_33 ( L_70 ,
V_36 -> V_37 , V_39 ? L_71 : L_72 ) ;
if ( V_97 ) {
if ( V_36 -> V_64 == V_92 ) {
if ( F_32 ( V_34 ,
V_98 ,
V_100 ,
V_100 ,
1 ) )
F_33 ( L_73 ) ;
} else if ( V_36 -> V_64 == V_65 ) {
if ( F_32 ( V_34 ,
V_98 ,
V_108 ,
V_108 ,
1 ) )
F_33 ( L_74 ) ;
}
}
if ( V_39 && ! V_48 )
F_28 ( V_34 , V_36 ) ;
}
static void F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
if ( F_10 ( V_90 ) & V_44 )
F_31 ( V_90 , 0 ) ;
}
static void F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , true ) ;
}
static void F_69 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , false ) ;
}
static bool F_70 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
T_1 V_75 = F_59 ( V_36 -> V_64 ) |
F_64 ( V_36 -> V_64 ) ;
return ( F_10 ( V_43 ) & V_75 ) == V_75 ;
}
static void F_71 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_63 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
F_31 ( V_90 , 0 ) ;
}
static void F_72 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_63 ( V_34 , V_36 , true ) ;
}
static void F_73 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_63 ( V_34 , V_36 , false ) ;
}
static void F_74 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_75 ( V_34 , V_36 -> V_109 ) ;
}
static void F_76 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_77 ( V_34 , V_36 -> V_109 ) ;
}
static bool F_78 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return F_79 ( V_34 , V_36 -> V_109 ) ;
}
static void F_80 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_42 > 0 )
F_74 ( V_34 , V_36 ) ;
else
F_76 ( V_34 , V_36 ) ;
}
static void F_81 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_82 ( V_34 , V_110 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 , V_36 -> V_109 ) ;
V_36 = F_82 ( V_34 , V_111 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 , V_36 -> V_109 ) ;
if ( F_84 ( V_34 ) ) {
V_36 = F_82 ( V_34 , V_112 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 , V_36 -> V_109 ) ;
}
}
static bool F_85 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return ( F_10 ( V_68 ) & V_113 ) == 0 ;
}
static void F_86 ( struct V_33 * V_34 )
{
T_2 V_67 = F_10 ( V_114 ) ;
F_8 ( ( V_67 & ( V_115 | V_116 ) ) !=
( V_115 | V_116 ) ,
L_75 , V_67 ) ;
}
static void F_87 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_43 ( V_34 , V_81 ) ;
F_88 ( V_34 -> V_117 !=
V_34 -> V_118 . V_119 ( V_34 ) ) ;
F_86 ( V_34 ) ;
if ( F_41 ( V_34 ) )
F_81 ( V_34 ) ;
}
static void F_89 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( ! V_34 -> V_78 . V_120 )
return;
if ( V_34 -> V_78 . V_80 & V_76 )
F_56 ( V_34 ) ;
else if ( V_34 -> V_78 . V_80 & V_70 )
F_54 ( V_34 ) ;
}
static void F_90 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_42 > 0 )
F_87 ( V_34 , V_36 ) ;
else
F_89 ( V_34 , V_36 ) ;
}
static void F_91 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
}
static bool F_92 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return true ;
}
static void F_93 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
enum V_121 V_88 = V_36 -> V_64 ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_122 ;
V_75 = F_94 ( V_88 ) ;
V_71 = V_39 ? F_95 ( V_88 ) :
F_96 ( V_88 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
#define F_97 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_97 )
goto V_125;
V_122 = F_98 ( V_34 , V_126 ) ;
V_122 &= ~ V_75 ;
V_122 |= V_71 ;
F_99 ( V_34 , V_126 , V_122 ) ;
if ( F_66 ( F_97 , 100 ) )
F_33 ( L_76 ,
V_71 ,
F_98 ( V_34 , V_126 ) ) ;
#undef F_97
V_125:
F_15 ( & V_34 -> V_123 . V_124 ) ;
}
static void F_100 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_93 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
}
static void F_101 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_93 ( V_34 , V_36 , true ) ;
}
static void F_102 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_93 ( V_34 , V_36 , false ) ;
}
static bool F_103 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_88 = V_36 -> V_64 ;
bool V_127 = false ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_122 ;
V_75 = F_94 ( V_88 ) ;
V_122 = F_95 ( V_88 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
V_71 = F_98 ( V_34 , V_128 ) & V_75 ;
F_88 ( V_71 != F_95 ( V_88 ) &&
V_71 != F_96 ( V_88 ) ) ;
if ( V_71 == V_122 )
V_127 = true ;
V_122 = F_98 ( V_34 , V_126 ) & V_75 ;
F_88 ( V_122 != V_71 ) ;
F_15 ( & V_34 -> V_123 . V_124 ) ;
return V_127 ;
}
static void F_104 ( struct V_33 * V_34 )
{
T_2 V_77 ;
V_77 = F_10 ( V_129 ) ;
V_77 &= V_130 ;
V_77 |= V_131 ;
F_31 ( V_129 , V_77 ) ;
F_31 ( V_132 , V_133 ) ;
F_31 ( V_134 , 0 ) ;
F_88 ( V_34 -> V_135 == 0 ) ;
F_31 ( V_136 ,
F_105 ( V_34 -> V_135 , 1000 ) ) ;
}
static void F_106 ( struct V_33 * V_34 )
{
struct V_137 * V_138 ;
enum V_139 V_139 ;
F_107 (dev_priv, pipe) {
T_2 V_77 = F_10 ( F_108 ( V_139 ) ) ;
V_77 |= V_140 | V_141 ;
if ( V_139 != V_142 )
V_77 |= V_143 ;
F_31 ( F_108 ( V_139 ) , V_77 ) ;
}
F_104 ( V_34 ) ;
F_109 ( & V_34 -> V_144 ) ;
F_110 ( V_34 ) ;
F_111 ( & V_34 -> V_144 ) ;
if ( V_34 -> V_47 . V_145 )
return;
F_112 ( V_34 ) ;
F_113 (&dev_priv->drm, encoder) {
if ( V_138 -> type == V_146 )
F_114 ( & V_138 -> V_147 ) ;
}
F_115 ( V_34 ) ;
F_48 ( V_34 ) ;
}
static void F_116 ( struct V_33 * V_34 )
{
F_109 ( & V_34 -> V_144 ) ;
F_117 ( V_34 ) ;
F_111 ( & V_34 -> V_144 ) ;
F_118 ( V_34 -> V_58 . V_148 ) ;
F_46 ( V_34 ) ;
if ( ! V_34 -> V_58 . V_149 -> V_150 . V_151 )
F_119 ( V_34 ) ;
}
static void F_120 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_152 ) ;
F_93 ( V_34 , V_36 , true ) ;
F_106 ( V_34 ) ;
}
static void F_121 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_152 ) ;
F_116 ( V_34 ) ;
F_93 ( V_34 , V_36 , false ) ;
}
static void F_122 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_153 ) ;
F_123 ( 1 ) ;
F_93 ( V_34 , V_36 , true ) ;
F_31 ( V_154 , F_10 ( V_154 ) | V_155 ) ;
}
static void F_124 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_139 V_139 ;
F_44 ( V_36 -> V_64 != V_153 ) ;
F_107 (dev_priv, pipe)
F_125 ( V_34 , V_139 ) ;
F_31 ( V_154 , F_10 ( V_154 ) & ~ V_155 ) ;
F_93 ( V_34 , V_36 , false ) ;
}
static struct V_35 * F_82 ( struct V_33 * V_34 ,
int V_88 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_47 -> V_156 ; V_49 ++ ) {
struct V_35 * V_36 ;
V_36 = & V_47 -> V_157 [ V_49 ] ;
if ( V_36 -> V_64 == V_88 )
return V_36 ;
}
return NULL ;
}
static void F_126 ( struct V_33 * V_34 )
{
struct V_35 * V_158 =
F_82 ( V_34 , V_153 ) ;
struct V_35 * V_159 =
F_82 ( V_34 , V_160 ) ;
T_2 V_161 = V_34 -> V_162 ;
T_2 V_163 = 0 ;
T_2 V_164 = 0xffffffff ;
if ( ! V_34 -> V_165 [ V_166 ] )
V_164 &= ~ ( F_127 ( V_166 , V_167 ) |
F_128 ( V_166 , V_167 , 0 ) |
F_128 ( V_166 , V_167 , 1 ) |
F_127 ( V_166 , V_168 ) |
F_128 ( V_166 , V_168 , 0 ) |
F_128 ( V_166 , V_168 , 1 ) ) ;
if ( ! V_34 -> V_165 [ V_169 ] )
V_164 &= ~ ( F_127 ( V_169 , V_167 ) |
F_128 ( V_169 , V_167 , 0 ) |
F_128 ( V_169 , V_167 , 1 ) ) ;
if ( V_158 -> V_38 -> V_48 ( V_34 , V_158 ) ) {
V_163 |= F_129 ( V_166 ) ;
if ( ( V_161 & F_130 ( V_166 , V_167 ) ) == 0 )
V_161 |= F_131 ( 0xf , V_166 , V_167 ) ;
if ( ( V_161 & F_130 ( V_166 , V_168 ) ) == 0 )
V_161 |= F_131 ( 0xf , V_166 , V_168 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xf , V_166 , V_167 ) |
F_131 ( 0xf , V_166 , V_168 ) ) )
V_163 |= F_127 ( V_166 , V_167 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xf , V_166 , V_168 ) ) &&
( F_10 ( F_108 ( V_63 ) ) & V_170 ) == 0 )
V_163 |= F_127 ( V_166 , V_168 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0x3 , V_166 , V_167 ) ) )
V_163 |= F_128 ( V_166 , V_167 , 0 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xc , V_166 , V_167 ) ) )
V_163 |= F_128 ( V_166 , V_167 , 1 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0x3 , V_166 , V_168 ) ) )
V_163 |= F_128 ( V_166 , V_168 , 0 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xc , V_166 , V_168 ) ) )
V_163 |= F_128 ( V_166 , V_168 , 1 ) ;
}
if ( V_159 -> V_38 -> V_48 ( V_34 , V_159 ) ) {
V_163 |= F_129 ( V_169 ) ;
if ( ( V_161 & F_130 ( V_169 , V_167 ) ) == 0 )
V_161 |= F_131 ( 0xf , V_169 , V_167 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xf , V_169 , V_167 ) ) )
V_163 |= F_127 ( V_169 , V_167 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0x3 , V_169 , V_167 ) ) )
V_163 |= F_128 ( V_169 , V_167 , 0 ) ;
if ( F_132 ( V_161 ,
F_131 ( 0xc , V_169 , V_167 ) ) )
V_163 |= F_128 ( V_169 , V_167 , 1 ) ;
}
V_163 &= V_164 ;
if ( F_32 ( V_34 ,
V_171 ,
V_164 ,
V_163 ,
10 ) )
F_33 ( L_77 ,
F_10 ( V_171 ) & V_164 ,
V_163 , V_34 -> V_162 ) ;
}
static void F_133 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_172 V_173 ;
enum V_139 V_139 ;
T_1 V_67 ;
F_44 ( V_36 -> V_64 != V_153 &&
V_36 -> V_64 != V_160 ) ;
if ( V_36 -> V_64 == V_153 ) {
V_139 = V_142 ;
V_173 = V_166 ;
} else {
V_139 = V_62 ;
V_173 = V_169 ;
}
F_123 ( 1 ) ;
F_93 ( V_34 , V_36 , true ) ;
if ( F_32 ( V_34 ,
V_171 ,
F_129 ( V_173 ) ,
F_129 ( V_173 ) ,
1 ) )
F_33 ( L_78 , V_173 ) ;
F_14 ( & V_34 -> V_174 ) ;
V_67 = F_134 ( V_34 , V_139 , V_175 ) ;
V_67 |= V_176 | V_177 |
V_178 ;
F_135 ( V_34 , V_139 , V_175 , V_67 ) ;
if ( V_36 -> V_64 == V_153 ) {
V_67 = F_134 ( V_34 , V_139 , V_179 ) ;
V_67 |= V_180 ;
F_135 ( V_34 , V_139 , V_179 , V_67 ) ;
} else {
V_67 = F_134 ( V_34 , V_139 , V_181 ) ;
V_67 |= V_182 ;
F_135 ( V_34 , V_139 , V_181 , V_67 ) ;
}
F_15 ( & V_34 -> V_174 ) ;
V_34 -> V_162 |= F_136 ( V_173 ) ;
F_31 ( V_183 , V_34 -> V_162 ) ;
F_4 ( L_79 ,
V_173 , V_34 -> V_162 ) ;
F_126 ( V_34 ) ;
}
static void F_137 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_172 V_173 ;
F_44 ( V_36 -> V_64 != V_153 &&
V_36 -> V_64 != V_160 ) ;
if ( V_36 -> V_64 == V_153 ) {
V_173 = V_166 ;
F_125 ( V_34 , V_142 ) ;
F_125 ( V_34 , V_63 ) ;
} else {
V_173 = V_169 ;
F_125 ( V_34 , V_62 ) ;
}
V_34 -> V_162 &= ~ F_136 ( V_173 ) ;
F_31 ( V_183 , V_34 -> V_162 ) ;
F_93 ( V_34 , V_36 , false ) ;
F_4 ( L_80 ,
V_173 , V_34 -> V_162 ) ;
V_34 -> V_165 [ V_173 ] = true ;
F_126 ( V_34 ) ;
}
static void F_138 ( struct V_33 * V_34 , enum V_172 V_173 ,
enum V_184 V_185 , bool V_186 , unsigned int V_75 )
{
enum V_139 V_139 = V_173 == V_166 ? V_142 : V_62 ;
T_2 V_187 , V_77 , V_188 , V_189 ;
if ( ! V_34 -> V_165 [ V_173 ] )
return;
if ( V_185 == V_167 )
V_187 = V_190 ;
else
V_187 = V_179 ;
F_14 ( & V_34 -> V_174 ) ;
V_77 = F_134 ( V_34 , V_139 , V_187 ) ;
F_15 ( & V_34 -> V_174 ) ;
if ( ! V_186 || V_75 == 0xf ) {
V_188 = V_191 | V_192 ;
if ( V_185 == V_168 && V_77 == 0 )
V_188 = 0 ;
} else if ( V_75 != 0x0 ) {
V_188 = V_192 ;
} else {
V_188 = 0 ;
}
if ( V_185 == V_167 )
V_189 = V_77 >> V_193 ;
else
V_189 = V_77 >> V_194 ;
V_189 &= V_191 | V_192 ;
F_8 ( V_189 != V_188 ,
L_81 ,
! ! ( V_189 & V_191 ) , ! ! ( V_189 & V_192 ) ,
! ! ( V_188 & V_191 ) , ! ! ( V_188 & V_192 ) ,
V_187 , V_77 ) ;
}
bool F_139 ( struct V_33 * V_34 , enum V_172 V_173 ,
enum V_184 V_185 , bool V_186 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
bool V_195 ;
F_14 ( & V_47 -> V_54 ) ;
V_195 = V_34 -> V_162 & F_130 ( V_173 , V_185 ) ;
if ( V_186 == V_195 )
goto V_125;
if ( V_186 )
V_34 -> V_162 |= F_130 ( V_173 , V_185 ) ;
else
V_34 -> V_162 &= ~ F_130 ( V_173 , V_185 ) ;
F_31 ( V_183 , V_34 -> V_162 ) ;
F_4 ( L_82 ,
V_173 , V_185 , V_34 -> V_162 ) ;
F_126 ( V_34 ) ;
V_125:
F_15 ( & V_47 -> V_54 ) ;
return V_195 ;
}
void F_140 ( struct V_137 * V_138 ,
bool V_186 , unsigned int V_75 )
{
struct V_33 * V_34 = F_141 ( V_138 -> V_147 . V_149 ) ;
struct V_46 * V_47 = & V_34 -> V_47 ;
enum V_172 V_173 = F_142 ( F_143 ( & V_138 -> V_147 ) ) ;
enum V_184 V_185 = F_144 ( F_143 ( & V_138 -> V_147 ) ) ;
F_14 ( & V_47 -> V_54 ) ;
V_34 -> V_162 &= ~ F_131 ( 0xf , V_173 , V_185 ) ;
V_34 -> V_162 |= F_131 ( V_75 , V_173 , V_185 ) ;
if ( V_186 )
V_34 -> V_162 |= F_130 ( V_173 , V_185 ) ;
else
V_34 -> V_162 &= ~ F_130 ( V_173 , V_185 ) ;
F_31 ( V_183 , V_34 -> V_162 ) ;
F_4 ( L_83 ,
V_173 , V_185 , V_75 , V_34 -> V_162 ) ;
F_126 ( V_34 ) ;
F_138 ( V_34 , V_173 , V_185 , V_186 , V_75 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static bool F_145 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_139 V_139 = V_36 -> V_64 ;
bool V_127 ;
T_2 V_71 , V_122 ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
V_71 = F_98 ( V_34 , V_196 ) & F_146 ( V_139 ) ;
F_88 ( V_71 != F_147 ( V_139 ) && V_71 != F_148 ( V_139 ) ) ;
V_127 = V_71 == F_147 ( V_139 ) ;
V_122 = F_98 ( V_34 , V_196 ) & F_149 ( V_139 ) ;
F_88 ( V_122 << 16 != V_71 ) ;
F_15 ( & V_34 -> V_123 . V_124 ) ;
return V_127 ;
}
static void F_150 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
bool V_39 )
{
enum V_139 V_139 = V_36 -> V_64 ;
T_2 V_71 ;
T_2 V_122 ;
V_71 = V_39 ? F_147 ( V_139 ) : F_148 ( V_139 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
#define F_97 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_97 )
goto V_125;
V_122 = F_98 ( V_34 , V_196 ) ;
V_122 &= ~ F_149 ( V_139 ) ;
V_122 |= V_39 ? F_151 ( V_139 ) : F_152 ( V_139 ) ;
F_99 ( V_34 , V_196 , V_122 ) ;
if ( F_66 ( F_97 , 100 ) )
F_33 ( L_76 ,
V_71 ,
F_98 ( V_34 , V_196 ) ) ;
#undef F_97
V_125:
F_15 ( & V_34 -> V_123 . V_124 ) ;
}
static void F_153 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_142 ) ;
F_150 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
}
static void F_154 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_142 ) ;
F_150 ( V_34 , V_36 , true ) ;
F_106 ( V_34 ) ;
}
static void F_155 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_142 ) ;
F_116 ( V_34 ) ;
F_150 ( V_34 , V_36 , false ) ;
}
static void
F_156 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_36 ;
int V_49 ;
F_157 (i, power_well, BIT(domain), power_domains)
F_6 ( V_34 , V_36 ) ;
V_47 -> V_197 [ V_2 ] ++ ;
}
void F_17 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
F_158 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
F_156 ( V_34 , V_2 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
bool F_159 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
bool V_48 ;
if ( ! F_160 ( V_34 ) )
return false ;
F_14 ( & V_47 -> V_54 ) ;
if ( F_11 ( V_34 , V_2 ) ) {
F_156 ( V_34 , V_2 ) ;
V_48 = true ;
} else {
V_48 = false ;
}
F_15 ( & V_47 -> V_54 ) ;
if ( ! V_48 )
F_161 ( V_34 ) ;
return V_48 ;
}
void F_18 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 ;
struct V_35 * V_36 ;
int V_49 ;
V_47 = & V_34 -> V_47 ;
F_14 ( & V_47 -> V_54 ) ;
F_8 ( ! V_47 -> V_197 [ V_2 ] ,
L_84 ,
F_1 ( V_2 ) ) ;
V_47 -> V_197 [ V_2 ] -- ;
F_12 (i, power_well, BIT(domain), power_domains)
F_7 ( V_34 , V_36 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_161 ( V_34 ) ;
}
bool F_52 ( struct V_33 * V_34 ,
int V_88 )
{
struct V_35 * V_36 ;
bool V_53 ;
V_36 = F_82 ( V_34 , V_88 ) ;
V_53 = V_36 -> V_38 -> V_48 ( V_34 , V_36 ) ;
return V_53 ;
}
static int
F_162 ( const struct V_33 * V_34 ,
int V_198 )
{
if ( V_198 >= 0 )
return ! ! V_198 ;
return 1 ;
}
static T_1 F_163 ( const struct V_33 * V_34 ,
int V_199 )
{
T_1 V_75 ;
int V_200 ;
int V_201 ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
V_201 = 2 ;
V_75 = 0 ;
} else if ( F_41 ( V_34 ) ) {
V_201 = 1 ;
V_75 = V_69 ;
} else {
V_201 = 0 ;
V_75 = 0 ;
}
if ( ! V_202 . V_198 )
V_201 = 0 ;
if ( V_199 >= 0 && V_199 <= V_201 ) {
V_200 = V_199 ;
} else if ( V_199 == - 1 ) {
V_200 = V_201 ;
} else if ( V_199 > V_201 && V_199 <= 2 ) {
F_4 ( L_85 ,
V_199 , V_201 ) ;
V_200 = V_201 ;
} else {
F_33 ( L_86 , V_199 ) ;
V_200 = V_201 ;
}
if ( V_200 > 1 )
V_75 |= V_76 ;
if ( V_200 > 0 )
V_75 |= V_70 ;
F_4 ( L_87 , V_75 ) ;
return V_75 ;
}
int F_164 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
V_202 . V_198 = F_162 ( V_34 ,
V_202 . V_198 ) ;
V_34 -> V_78 . V_80 = F_163 ( V_34 ,
V_202 . V_199 ) ;
F_165 ( V_203 > 31 ) ;
F_166 ( & V_47 -> V_54 ) ;
if ( F_167 ( V_34 ) ) {
F_168 ( V_47 , V_204 ) ;
} else if ( F_24 ( V_34 ) ) {
F_168 ( V_47 , V_205 ) ;
} else if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
F_168 ( V_47 , V_206 ) ;
} else if ( F_169 ( V_34 ) ) {
F_168 ( V_47 , V_207 ) ;
} else if ( F_84 ( V_34 ) ) {
F_168 ( V_47 , V_208 ) ;
} else if ( F_170 ( V_34 ) ) {
F_168 ( V_47 , V_209 ) ;
} else if ( F_171 ( V_34 ) ) {
F_168 ( V_47 , V_210 ) ;
} else {
F_168 ( V_47 , V_211 ) ;
}
return 0 ;
}
void F_172 ( struct V_33 * V_34 )
{
struct V_212 * V_213 = & V_34 -> V_58 . V_57 -> V_149 ;
F_16 ( V_34 , true ) ;
if ( ! V_202 . V_198 )
F_18 ( V_34 , V_31 ) ;
if ( ! F_173 ( V_34 ) )
F_174 ( V_213 ) ;
}
static void F_175 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_36 ;
int V_49 ;
F_14 ( & V_47 -> V_54 ) ;
F_157 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_36 -> V_38 -> V_214 ( V_34 , V_36 ) ;
V_36 -> V_40 = V_36 -> V_38 -> V_48 ( V_34 ,
V_36 ) ;
}
F_15 ( & V_47 -> V_54 ) ;
}
static void F_176 ( struct V_33 * V_34 )
{
F_31 ( V_114 , F_10 ( V_114 ) | V_116 ) ;
F_34 ( V_114 ) ;
F_123 ( 10 ) ;
if ( ! ( F_10 ( V_114 ) & V_115 ) )
F_33 ( L_88 ) ;
}
static void F_177 ( struct V_33 * V_34 )
{
F_31 ( V_114 , F_10 ( V_114 ) & ~ V_116 ) ;
F_34 ( V_114 ) ;
F_123 ( 10 ) ;
if ( F_10 ( V_114 ) & V_115 )
F_33 ( L_89 ) ;
}
static void F_178 ( struct V_33 * V_34 ,
bool V_215 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_216 ;
T_1 V_77 ;
F_43 ( V_34 , V_81 ) ;
V_77 = F_10 ( V_217 ) ;
F_31 ( V_217 , V_77 | V_218 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_216 = F_82 ( V_34 , V_92 ) ;
F_3 ( V_34 , V_216 ) ;
V_216 = F_82 ( V_34 , V_93 ) ;
F_3 ( V_34 , V_216 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_179 ( V_34 ) ;
F_176 ( V_34 ) ;
if ( V_215 && V_34 -> V_78 . V_120 )
F_180 ( V_34 ) ;
}
static void F_181 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_216 ;
F_43 ( V_34 , V_81 ) ;
F_177 ( V_34 ) ;
F_182 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_216 = F_82 ( V_34 , V_93 ) ;
F_5 ( V_34 , V_216 ) ;
V_216 = F_82 ( V_34 , V_92 ) ;
F_5 ( V_34 , V_216 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
void F_183 ( struct V_33 * V_34 ,
bool V_215 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_216 ;
T_1 V_77 ;
F_43 ( V_34 , V_81 ) ;
V_77 = F_10 ( V_217 ) ;
V_77 &= ~ V_218 ;
F_31 ( V_217 , V_77 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_216 = F_82 ( V_34 , V_92 ) ;
F_3 ( V_34 , V_216 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_184 ( V_34 ) ;
F_176 ( V_34 ) ;
if ( V_215 && V_34 -> V_78 . V_120 )
F_180 ( V_34 ) ;
}
void F_185 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_216 ;
F_43 ( V_34 , V_81 ) ;
F_177 ( V_34 ) ;
F_186 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_216 = F_82 ( V_34 , V_92 ) ;
F_5 ( V_34 , V_216 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static void F_187 ( struct V_33 * V_34 )
{
struct V_35 * V_158 =
F_82 ( V_34 , V_153 ) ;
struct V_35 * V_159 =
F_82 ( V_34 , V_160 ) ;
V_34 -> V_162 =
F_188 ( V_219 , V_166 ) |
F_188 ( V_219 , V_169 ) |
F_189 ( V_220 , V_166 , V_167 ) |
F_189 ( V_220 , V_166 , V_168 ) |
F_189 ( V_220 , V_169 , V_167 ) ;
if ( V_158 -> V_38 -> V_48 ( V_34 , V_158 ) ) {
T_1 V_221 = F_10 ( F_108 ( V_142 ) ) ;
unsigned int V_75 ;
V_75 = V_221 & V_222 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_162 |=
F_130 ( V_166 , V_167 ) ;
V_34 -> V_162 |=
F_131 ( V_75 , V_166 , V_167 ) ;
V_75 = ( V_221 & V_223 ) >> 4 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_162 |=
F_130 ( V_166 , V_168 ) ;
V_34 -> V_162 |=
F_131 ( V_75 , V_166 , V_168 ) ;
V_34 -> V_162 |= F_136 ( V_166 ) ;
V_34 -> V_165 [ V_166 ] = false ;
} else {
V_34 -> V_165 [ V_166 ] = true ;
}
if ( V_159 -> V_38 -> V_48 ( V_34 , V_159 ) ) {
T_1 V_221 = F_10 ( V_224 ) ;
unsigned int V_75 ;
V_75 = V_221 & V_225 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_162 |=
F_130 ( V_169 , V_167 ) ;
V_34 -> V_162 |=
F_131 ( V_75 , V_169 , V_167 ) ;
V_34 -> V_162 |= F_136 ( V_169 ) ;
V_34 -> V_165 [ V_169 ] = false ;
} else {
V_34 -> V_165 [ V_169 ] = true ;
}
F_31 ( V_183 , V_34 -> V_162 ) ;
F_4 ( L_90 ,
V_34 -> V_162 ) ;
}
static void F_190 ( struct V_33 * V_34 )
{
struct V_35 * V_226 =
F_82 ( V_34 , V_153 ) ;
struct V_35 * V_227 =
F_82 ( V_34 , V_152 ) ;
if ( V_226 -> V_38 -> V_48 ( V_34 , V_226 ) &&
V_227 -> V_38 -> V_48 ( V_34 , V_227 ) &&
F_10 ( V_154 ) & V_155 )
return;
F_4 ( L_91 ) ;
V_227 -> V_38 -> V_39 ( V_34 , V_227 ) ;
V_226 -> V_38 -> V_41 ( V_34 , V_226 ) ;
}
void F_191 ( struct V_33 * V_34 , bool V_215 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
V_47 -> V_145 = true ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
F_178 ( V_34 , V_215 ) ;
} else if ( F_41 ( V_34 ) ) {
F_183 ( V_34 , V_215 ) ;
} else if ( F_170 ( V_34 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_187 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
} else if ( F_171 ( V_34 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_190 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
F_16 ( V_34 , true ) ;
if ( ! V_202 . V_198 )
F_17 ( V_34 , V_31 ) ;
F_175 ( V_34 ) ;
V_47 -> V_145 = false ;
}
void F_192 ( struct V_33 * V_34 )
{
if ( ! V_202 . V_198 )
F_18 ( V_34 , V_31 ) ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) )
F_181 ( V_34 ) ;
else if ( F_41 ( V_34 ) )
F_185 ( V_34 ) ;
}
void F_158 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_212 * V_213 = & V_57 -> V_149 ;
F_193 ( V_213 ) ;
F_194 ( & V_34 -> V_50 . V_228 ) ;
F_53 ( V_34 ) ;
}
bool F_160 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_212 * V_213 = & V_57 -> V_149 ;
if ( F_195 ( V_229 ) ) {
int V_53 = F_196 ( V_213 ) ;
F_44 ( V_53 < 0 ) ;
if ( V_53 <= 0 )
return false ;
}
F_194 ( & V_34 -> V_50 . V_228 ) ;
F_53 ( V_34 ) ;
return true ;
}
void F_197 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_212 * V_213 = & V_57 -> V_149 ;
F_53 ( V_34 ) ;
F_198 ( V_213 ) ;
F_194 ( & V_34 -> V_50 . V_228 ) ;
}
void F_161 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_212 * V_213 = & V_57 -> V_149 ;
F_53 ( V_34 ) ;
F_199 ( & V_34 -> V_50 . V_228 ) ;
F_200 ( V_213 ) ;
F_201 ( V_213 ) ;
}
void F_202 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_212 * V_213 = & V_57 -> V_149 ;
F_203 ( V_213 , 10000 ) ;
F_200 ( V_213 ) ;
if ( ! F_173 ( V_34 ) ) {
F_204 ( V_213 ) ;
F_193 ( V_213 ) ;
} else {
F_205 ( V_213 ) ;
}
F_201 ( V_213 ) ;
}
