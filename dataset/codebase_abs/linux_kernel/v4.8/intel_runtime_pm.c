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
struct V_56 * V_57 = & V_34 -> V_58 ;
F_20 ( V_57 -> V_59 , V_60 ) ;
F_21 ( F_22 ( V_61 ) , V_62 ) ;
F_23 ( V_57 -> V_59 , V_60 ) ;
if ( F_24 ( V_57 ) )
F_25 ( V_34 ,
1 << V_63 | 1 << V_64 ) ;
}
static void F_26 ( struct V_33 * V_34 )
{
if ( F_24 ( V_34 ) )
F_27 ( V_34 ,
1 << V_63 | 1 << V_64 ) ;
}
static void F_28 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
if ( V_36 -> V_65 == V_66 ) {
F_20 ( V_57 -> V_59 , V_60 ) ;
F_21 ( F_22 ( V_61 ) , V_62 ) ;
F_23 ( V_57 -> V_59 , V_60 ) ;
F_25 ( V_34 ,
1 << V_63 | 1 << V_64 ) ;
}
}
static void F_29 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_65 == V_66 )
F_27 ( V_34 ,
1 << V_63 | 1 << V_64 ) ;
}
static void F_30 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
bool V_48 , V_67 ;
T_1 V_68 ;
V_68 = F_10 ( V_43 ) ;
V_48 = V_68 & V_45 ;
V_67 = V_68 & V_44 ;
if ( V_39 ) {
if ( ! V_67 )
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
if ( V_67 ) {
F_26 ( V_34 ) ;
F_31 ( V_43 , 0 ) ;
F_34 ( V_43 ) ;
F_4 ( L_37 ) ;
}
}
}
static void F_35 ( struct V_33 * V_34 )
{
F_36 ( ( F_10 ( V_69 ) & V_70 ) ,
L_38 ) ;
F_36 ( F_10 ( V_69 ) & V_71 ,
L_39 ) ;
F_36 ( F_10 ( V_43 ) , L_40 ) ;
F_36 ( F_37 ( V_34 ) ,
L_41 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
F_36 ( F_37 ( V_34 ) ,
L_41 ) ;
F_36 ( F_10 ( V_69 ) & V_71 ,
L_42 ) ;
}
static void F_39 ( struct V_33 * V_34 ,
T_2 V_72 )
{
int V_73 = 0 ;
int V_74 = 0 ;
T_2 V_75 ;
F_31 ( V_69 , V_72 ) ;
do {
V_75 = F_10 ( V_69 ) ;
if ( V_75 != V_72 ) {
F_31 ( V_69 , V_72 ) ;
V_73 ++ ;
V_74 = 0 ;
} else if ( V_74 ++ > 5 ) {
break;
}
} while ( V_73 < 100 );
if ( V_75 != V_72 )
F_33 ( L_43 ,
V_72 , V_75 ) ;
if ( V_73 > 1 )
F_4 ( L_44 ,
V_72 , V_73 ) ;
}
static T_2 F_40 ( struct V_33 * V_34 )
{
T_2 V_76 ;
V_76 = V_71 ;
if ( F_41 ( V_34 ) )
V_76 |= V_70 ;
else
V_76 |= V_77 ;
return V_76 ;
}
void F_42 ( struct V_33 * V_34 )
{
T_2 V_78 ;
V_78 = F_10 ( V_69 ) & F_40 ( V_34 ) ;
F_4 ( L_45 ,
V_34 -> V_79 . V_80 , V_78 ) ;
V_34 -> V_79 . V_80 = V_78 ;
}
static void F_43 ( struct V_33 * V_34 , T_1 V_72 )
{
T_1 V_78 ;
T_1 V_76 ;
if ( F_44 ( V_72 & ~ V_34 -> V_79 . V_81 ) )
V_72 &= V_34 -> V_79 . V_81 ;
V_78 = F_10 ( V_69 ) ;
V_76 = F_40 ( V_34 ) ;
F_4 ( L_46 ,
V_78 & V_76 , V_72 ) ;
if ( ( V_78 & V_76 ) != V_34 -> V_79 . V_80 )
F_33 ( L_47 ,
V_34 -> V_79 . V_80 , V_78 & V_76 ) ;
V_78 &= ~ V_76 ;
V_78 |= V_72 ;
F_39 ( V_34 , V_78 ) ;
V_34 -> V_79 . V_80 = V_78 & V_76 ;
}
void F_45 ( struct V_33 * V_34 )
{
F_35 ( V_34 ) ;
F_4 ( L_48 ) ;
F_46 ( V_34 ) ;
F_43 ( V_34 , V_70 ) ;
}
void F_47 ( struct V_33 * V_34 )
{
F_38 ( V_34 ) ;
F_4 ( L_49 ) ;
F_43 ( V_34 , V_82 ) ;
}
static void F_48 ( struct V_33 * V_34 )
{
F_36 ( ! F_10 ( F_49 ( 0 ) ) ,
L_50 ) ;
F_36 ( ! F_10 ( V_83 ) , L_51 ) ;
F_36 ( ! F_10 ( V_84 ) , L_52 ) ;
}
static void F_50 ( struct V_33 * V_34 )
{
bool V_85 = F_51 ( V_34 ,
V_66 ) ;
F_36 ( V_85 , L_53 ) ;
F_36 ( ( F_10 ( V_69 ) & V_71 ) ,
L_54 ) ;
F_52 ( V_34 ) ;
F_48 ( V_34 ) ;
}
void F_53 ( struct V_33 * V_34 )
{
F_50 ( V_34 ) ;
F_4 ( L_55 ) ;
F_43 ( V_34 , V_71 ) ;
}
static void F_54 ( struct V_33 * V_34 )
{
F_36 ( F_10 ( V_86 ) & V_87 ,
L_56 ) ;
F_36 ( ( F_10 ( V_69 ) & V_77 ) ,
L_57 ) ;
F_48 ( V_34 ) ;
}
void F_55 ( struct V_33 * V_34 )
{
F_54 ( V_34 ) ;
F_4 ( L_58 ) ;
F_43 ( V_34 , V_77 ) ;
}
void F_56 ( struct V_33 * V_34 )
{
F_4 ( L_59 ) ;
F_43 ( V_34 , V_82 ) ;
}
static void
F_57 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_88 V_89 = V_36 -> V_65 ;
T_2 V_78 ;
T_2 V_76 ;
V_76 = F_58 ( V_89 ) ;
V_78 = F_10 ( V_90 ) ;
if ( F_36 ( V_78 & V_76 , L_60 ,
V_36 -> V_37 ) )
F_31 ( V_90 , V_78 & ~ V_76 ) ;
V_78 = F_10 ( V_91 ) ;
V_78 |= F_10 ( V_92 ) ;
if ( ! ( V_78 & V_76 ) )
return;
if ( V_89 == V_93 ||
( ( F_59 ( V_34 ) || F_60 ( V_34 ) ) &&
V_89 == V_94 ) )
F_61 ( L_61
L_62 , V_36 -> V_37 ) ;
else
F_36 ( 1 , L_63 ,
V_36 -> V_37 ) ;
F_31 ( V_91 , V_78 & ~ V_76 ) ;
F_31 ( V_92 , V_78 & ~ V_76 ) ;
}
static void F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
T_1 V_68 , V_95 ;
T_1 V_96 , V_97 ;
bool V_48 , V_67 , V_98 = false ;
V_68 = F_10 ( V_43 ) ;
V_95 = F_10 ( V_99 ) ;
switch ( V_36 -> V_65 ) {
case V_93 :
if ( F_32 ( V_34 ,
V_99 ,
V_100 ,
V_100 ,
1 ) ) {
F_33 ( L_64 ) ;
return;
}
break;
case V_66 :
if ( ! ( V_95 & V_101 ) ) {
F_33 ( L_65 ) ;
return;
}
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_94 :
break;
default:
F_8 ( 1 , L_66 , V_36 -> V_65 ) ;
return;
}
V_96 = F_58 ( V_36 -> V_65 ) ;
V_67 = V_68 & V_96 ;
V_97 = F_63 ( V_36 -> V_65 ) ;
V_48 = V_68 & V_97 ;
if ( ! V_39 && V_67 )
F_29 ( V_34 , V_36 ) ;
if ( V_39 ) {
if ( ! V_67 ) {
F_8 ( ( V_68 & V_97 ) &&
! F_10 ( V_91 ) ,
L_67 ) ;
F_31 ( V_43 , V_68 | V_96 ) ;
}
if ( ! V_48 ) {
F_4 ( L_68 , V_36 -> V_37 ) ;
V_98 = true ;
}
} else {
if ( V_67 ) {
F_31 ( V_43 , V_68 & ~ V_96 ) ;
F_34 ( V_43 ) ;
F_4 ( L_69 , V_36 -> V_37 ) ;
}
if ( F_64 ( V_34 ) )
F_57 ( V_34 , V_36 ) ;
}
if ( F_65 ( ! ! ( F_10 ( V_43 ) & V_97 ) == V_39 ,
1 ) )
F_33 ( L_70 ,
V_36 -> V_37 , V_39 ? L_71 : L_72 ) ;
if ( V_98 ) {
if ( V_36 -> V_65 == V_93 ) {
if ( F_32 ( V_34 ,
V_99 ,
V_101 ,
V_101 ,
1 ) )
F_33 ( L_73 ) ;
} else if ( V_36 -> V_65 == V_66 ) {
if ( F_32 ( V_34 ,
V_99 ,
V_106 ,
V_106 ,
1 ) )
F_33 ( L_74 ) ;
}
}
if ( V_39 && ! V_48 )
F_28 ( V_34 , V_36 ) ;
}
static void F_66 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
if ( F_10 ( V_91 ) & V_44 )
F_31 ( V_91 , 0 ) ;
}
static void F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , true ) ;
}
static void F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_30 ( V_34 , V_36 , false ) ;
}
static bool F_69 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
T_1 V_76 = F_58 ( V_36 -> V_65 ) |
F_63 ( V_36 -> V_65 ) ;
return ( F_10 ( V_43 ) & V_76 ) == V_76 ;
}
static void F_70 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_62 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
F_31 ( V_91 , 0 ) ;
}
static void F_71 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_62 ( V_34 , V_36 , true ) ;
}
static void F_72 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_62 ( V_34 , V_36 , false ) ;
}
static enum V_107 F_73 ( struct V_35 * V_36 )
{
enum V_88 V_89 = V_36 -> V_65 ;
return V_89 == V_108 ? V_109 : V_110 ;
}
static void F_74 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_88 V_89 = V_36 -> V_65 ;
struct V_35 * V_111 ;
if ( V_89 == V_112 ) {
V_111 = F_75 ( V_34 , V_108 ) ;
F_6 ( V_34 , V_111 ) ;
}
F_76 ( V_34 , F_73 ( V_36 ) ) ;
if ( V_89 == V_112 )
F_7 ( V_34 , V_111 ) ;
}
static void F_77 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_78 ( V_34 , F_73 ( V_36 ) ) ;
}
static bool F_79 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return F_80 ( V_34 ,
F_73 ( V_36 ) ) ;
}
static void F_81 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_42 > 0 )
F_74 ( V_34 , V_36 ) ;
else
F_77 ( V_34 , V_36 ) ;
}
static void F_82 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_75 ( V_34 , V_108 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 ,
F_73 ( V_36 ) ) ;
V_36 = F_75 ( V_34 , V_112 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 ,
F_73 ( V_36 ) ) ;
}
static bool F_84 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return ( F_10 ( V_69 ) & V_113 ) == 0 ;
}
static void F_85 ( struct V_33 * V_34 )
{
T_2 V_68 = F_10 ( V_114 ) ;
F_8 ( ( V_68 & ( V_115 | V_116 ) ) !=
( V_115 | V_116 ) ,
L_75 , V_68 ) ;
}
static void F_86 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_43 ( V_34 , V_82 ) ;
F_87 ( V_34 -> V_117 !=
V_34 -> V_118 . V_119 ( & V_34 -> V_58 ) ) ;
F_85 ( V_34 ) ;
if ( F_41 ( V_34 ) )
F_82 ( V_34 ) ;
}
static void F_88 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( ! V_34 -> V_79 . V_120 )
return;
if ( V_34 -> V_79 . V_81 & V_77 )
F_55 ( V_34 ) ;
else if ( V_34 -> V_79 . V_81 & V_71 )
F_53 ( V_34 ) ;
}
static void F_89 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_42 > 0 )
F_86 ( V_34 , V_36 ) ;
else
F_88 ( V_34 , V_36 ) ;
}
static void F_90 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
}
static bool F_91 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return true ;
}
static void F_92 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
enum V_121 V_89 = V_36 -> V_65 ;
T_2 V_76 ;
T_2 V_72 ;
T_2 V_122 ;
V_76 = F_93 ( V_89 ) ;
V_72 = V_39 ? F_94 ( V_89 ) :
F_95 ( V_89 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
#define F_96 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_96 )
goto V_125;
V_122 = F_97 ( V_34 , V_126 ) ;
V_122 &= ~ V_76 ;
V_122 |= V_72 ;
F_98 ( V_34 , V_126 , V_122 ) ;
if ( F_65 ( F_96 , 100 ) )
F_33 ( L_76 ,
V_72 ,
F_97 ( V_34 , V_126 ) ) ;
#undef F_96
V_125:
F_15 ( & V_34 -> V_123 . V_124 ) ;
}
static void F_99 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_92 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
}
static void F_100 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_92 ( V_34 , V_36 , true ) ;
}
static void F_101 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_92 ( V_34 , V_36 , false ) ;
}
static bool F_102 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_89 = V_36 -> V_65 ;
bool V_127 = false ;
T_2 V_76 ;
T_2 V_72 ;
T_2 V_122 ;
V_76 = F_93 ( V_89 ) ;
V_122 = F_94 ( V_89 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
V_72 = F_97 ( V_34 , V_128 ) & V_76 ;
F_87 ( V_72 != F_94 ( V_89 ) &&
V_72 != F_95 ( V_89 ) ) ;
if ( V_72 == V_122 )
V_127 = true ;
V_122 = F_97 ( V_34 , V_126 ) & V_76 ;
F_87 ( V_122 != V_72 ) ;
F_15 ( & V_34 -> V_123 . V_124 ) ;
return V_127 ;
}
static void F_103 ( struct V_33 * V_34 )
{
F_31 ( V_129 , V_130 ) ;
F_31 ( V_131 , V_132 ) ;
F_31 ( V_133 , 0 ) ;
F_87 ( V_34 -> V_134 == 0 ) ;
F_31 ( V_135 ,
F_104 ( V_34 -> V_134 , 1000 ) ) ;
}
static void F_105 ( struct V_33 * V_34 )
{
struct V_136 * V_137 ;
enum V_138 V_138 ;
F_106 (&dev_priv->drm, pipe) {
T_2 V_78 = F_10 ( F_107 ( V_138 ) ) ;
V_78 |= V_139 | V_140 ;
if ( V_138 != V_141 )
V_78 |= V_142 ;
F_31 ( F_107 ( V_138 ) , V_78 ) ;
}
F_103 ( V_34 ) ;
F_108 ( & V_34 -> V_143 ) ;
F_109 ( V_34 ) ;
F_110 ( & V_34 -> V_143 ) ;
if ( V_34 -> V_47 . V_144 )
return;
F_111 ( V_34 ) ;
F_112 (&dev_priv->drm, encoder) {
if ( V_137 -> type == V_145 )
F_113 ( & V_137 -> V_146 ) ;
}
F_114 ( & V_34 -> V_58 ) ;
}
static void F_115 ( struct V_33 * V_34 )
{
F_108 ( & V_34 -> V_143 ) ;
F_116 ( V_34 ) ;
F_110 ( & V_34 -> V_143 ) ;
F_117 ( V_34 -> V_58 . V_147 ) ;
F_46 ( V_34 ) ;
F_118 ( V_34 ) ;
}
static void F_119 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_148 ) ;
F_92 ( V_34 , V_36 , true ) ;
F_105 ( V_34 ) ;
}
static void F_120 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_148 ) ;
F_115 ( V_34 ) ;
F_92 ( V_34 , V_36 , false ) ;
}
static void F_121 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_149 ) ;
F_122 ( 1 ) ;
F_92 ( V_34 , V_36 , true ) ;
F_31 ( V_150 , F_10 ( V_150 ) | V_151 ) ;
}
static void F_123 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_138 V_138 ;
F_44 ( V_36 -> V_65 != V_149 ) ;
F_106 (dev_priv, pipe)
F_124 ( V_34 , V_138 ) ;
F_31 ( V_150 , F_10 ( V_150 ) & ~ V_151 ) ;
F_92 ( V_34 , V_36 , false ) ;
}
static struct V_35 * F_75 ( struct V_33 * V_34 ,
int V_89 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_47 -> V_152 ; V_49 ++ ) {
struct V_35 * V_36 ;
V_36 = & V_47 -> V_153 [ V_49 ] ;
if ( V_36 -> V_65 == V_89 )
return V_36 ;
}
return NULL ;
}
static void F_125 ( struct V_33 * V_34 )
{
struct V_35 * V_154 =
F_75 ( V_34 , V_149 ) ;
struct V_35 * V_155 =
F_75 ( V_34 , V_156 ) ;
T_2 V_157 = V_34 -> V_158 ;
T_2 V_159 = 0 ;
T_2 V_160 = 0xffffffff ;
if ( ! V_34 -> V_161 [ V_110 ] )
V_160 &= ~ ( F_126 ( V_110 , V_162 ) |
F_127 ( V_110 , V_162 , 0 ) |
F_127 ( V_110 , V_162 , 1 ) |
F_126 ( V_110 , V_163 ) |
F_127 ( V_110 , V_163 , 0 ) |
F_127 ( V_110 , V_163 , 1 ) ) ;
if ( ! V_34 -> V_161 [ V_109 ] )
V_160 &= ~ ( F_126 ( V_109 , V_162 ) |
F_127 ( V_109 , V_162 , 0 ) |
F_127 ( V_109 , V_162 , 1 ) ) ;
if ( V_154 -> V_38 -> V_48 ( V_34 , V_154 ) ) {
V_159 |= F_128 ( V_110 ) ;
if ( ( V_157 & F_129 ( V_110 , V_162 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_110 , V_162 ) ;
if ( ( V_157 & F_129 ( V_110 , V_163 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_110 , V_163 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_110 , V_162 ) |
F_130 ( 0xf , V_110 , V_163 ) ) )
V_159 |= F_126 ( V_110 , V_162 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_110 , V_163 ) ) &&
( F_10 ( F_107 ( V_64 ) ) & V_164 ) == 0 )
V_159 |= F_126 ( V_110 , V_163 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_110 , V_162 ) ) )
V_159 |= F_127 ( V_110 , V_162 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_110 , V_162 ) ) )
V_159 |= F_127 ( V_110 , V_162 , 1 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_110 , V_163 ) ) )
V_159 |= F_127 ( V_110 , V_163 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_110 , V_163 ) ) )
V_159 |= F_127 ( V_110 , V_163 , 1 ) ;
}
if ( V_155 -> V_38 -> V_48 ( V_34 , V_155 ) ) {
V_159 |= F_128 ( V_109 ) ;
if ( ( V_157 & F_129 ( V_109 , V_162 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_109 , V_162 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_109 , V_162 ) ) )
V_159 |= F_126 ( V_109 , V_162 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_109 , V_162 ) ) )
V_159 |= F_127 ( V_109 , V_162 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_109 , V_162 ) ) )
V_159 |= F_127 ( V_109 , V_162 , 1 ) ;
}
V_159 &= V_160 ;
if ( F_32 ( V_34 ,
V_165 ,
V_160 ,
V_159 ,
10 ) )
F_33 ( L_77 ,
F_10 ( V_165 ) & V_160 ,
V_159 , V_34 -> V_158 ) ;
}
static void F_132 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_107 V_166 ;
enum V_138 V_138 ;
T_1 V_68 ;
F_44 ( V_36 -> V_65 != V_149 &&
V_36 -> V_65 != V_156 ) ;
if ( V_36 -> V_65 == V_149 ) {
V_138 = V_141 ;
V_166 = V_110 ;
} else {
V_138 = V_63 ;
V_166 = V_109 ;
}
F_122 ( 1 ) ;
F_92 ( V_34 , V_36 , true ) ;
if ( F_32 ( V_34 ,
V_165 ,
F_128 ( V_166 ) ,
F_128 ( V_166 ) ,
1 ) )
F_33 ( L_78 , V_166 ) ;
F_14 ( & V_34 -> V_167 ) ;
V_68 = F_133 ( V_34 , V_138 , V_168 ) ;
V_68 |= V_169 | V_170 |
V_171 ;
F_134 ( V_34 , V_138 , V_168 , V_68 ) ;
if ( V_36 -> V_65 == V_149 ) {
V_68 = F_133 ( V_34 , V_138 , V_172 ) ;
V_68 |= V_173 ;
F_134 ( V_34 , V_138 , V_172 , V_68 ) ;
} else {
V_68 = F_133 ( V_34 , V_138 , V_174 ) ;
V_68 |= V_175 ;
F_134 ( V_34 , V_138 , V_174 , V_68 ) ;
}
F_15 ( & V_34 -> V_167 ) ;
V_34 -> V_158 |= F_135 ( V_166 ) ;
F_31 ( V_176 , V_34 -> V_158 ) ;
F_4 ( L_79 ,
V_166 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
}
static void F_136 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_107 V_166 ;
F_44 ( V_36 -> V_65 != V_149 &&
V_36 -> V_65 != V_156 ) ;
if ( V_36 -> V_65 == V_149 ) {
V_166 = V_110 ;
F_124 ( V_34 , V_141 ) ;
F_124 ( V_34 , V_64 ) ;
} else {
V_166 = V_109 ;
F_124 ( V_34 , V_63 ) ;
}
V_34 -> V_158 &= ~ F_135 ( V_166 ) ;
F_31 ( V_176 , V_34 -> V_158 ) ;
F_92 ( V_34 , V_36 , false ) ;
F_4 ( L_80 ,
V_166 , V_34 -> V_158 ) ;
V_34 -> V_161 [ V_166 ] = true ;
F_125 ( V_34 ) ;
}
static void F_137 ( struct V_33 * V_34 , enum V_107 V_166 ,
enum V_177 V_178 , bool V_179 , unsigned int V_76 )
{
enum V_138 V_138 = V_166 == V_110 ? V_141 : V_63 ;
T_2 V_180 , V_78 , V_181 , V_182 ;
if ( ! V_34 -> V_161 [ V_166 ] )
return;
if ( V_178 == V_162 )
V_180 = V_183 ;
else
V_180 = V_172 ;
F_14 ( & V_34 -> V_167 ) ;
V_78 = F_133 ( V_34 , V_138 , V_180 ) ;
F_15 ( & V_34 -> V_167 ) ;
if ( ! V_179 || V_76 == 0xf ) {
V_181 = V_184 | V_185 ;
if ( V_178 == V_163 && V_78 == 0 )
V_181 = 0 ;
} else if ( V_76 != 0x0 ) {
V_181 = V_185 ;
} else {
V_181 = 0 ;
}
if ( V_178 == V_162 )
V_182 = V_78 >> V_186 ;
else
V_182 = V_78 >> V_187 ;
V_182 &= V_184 | V_185 ;
F_8 ( V_182 != V_181 ,
L_81 ,
! ! ( V_182 & V_184 ) , ! ! ( V_182 & V_185 ) ,
! ! ( V_181 & V_184 ) , ! ! ( V_181 & V_185 ) ,
V_180 , V_78 ) ;
}
bool F_138 ( struct V_33 * V_34 , enum V_107 V_166 ,
enum V_177 V_178 , bool V_179 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
bool V_188 ;
F_14 ( & V_47 -> V_54 ) ;
V_188 = V_34 -> V_158 & F_129 ( V_166 , V_178 ) ;
if ( V_179 == V_188 )
goto V_125;
if ( V_179 )
V_34 -> V_158 |= F_129 ( V_166 , V_178 ) ;
else
V_34 -> V_158 &= ~ F_129 ( V_166 , V_178 ) ;
F_31 ( V_176 , V_34 -> V_158 ) ;
F_4 ( L_82 ,
V_166 , V_178 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
V_125:
F_15 ( & V_47 -> V_54 ) ;
return V_188 ;
}
void F_139 ( struct V_136 * V_137 ,
bool V_179 , unsigned int V_76 )
{
struct V_33 * V_34 = F_140 ( V_137 -> V_146 . V_57 ) ;
struct V_46 * V_47 = & V_34 -> V_47 ;
enum V_107 V_166 = F_141 ( F_142 ( & V_137 -> V_146 ) ) ;
enum V_177 V_178 = F_143 ( F_142 ( & V_137 -> V_146 ) ) ;
F_14 ( & V_47 -> V_54 ) ;
V_34 -> V_158 &= ~ F_130 ( 0xf , V_166 , V_178 ) ;
V_34 -> V_158 |= F_130 ( V_76 , V_166 , V_178 ) ;
if ( V_179 )
V_34 -> V_158 |= F_129 ( V_166 , V_178 ) ;
else
V_34 -> V_158 &= ~ F_129 ( V_166 , V_178 ) ;
F_31 ( V_176 , V_34 -> V_158 ) ;
F_4 ( L_83 ,
V_166 , V_178 , V_76 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
F_137 ( V_34 , V_166 , V_178 , V_179 , V_76 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static bool F_144 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_138 V_138 = V_36 -> V_65 ;
bool V_127 ;
T_2 V_72 , V_122 ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
V_72 = F_97 ( V_34 , V_189 ) & F_145 ( V_138 ) ;
F_87 ( V_72 != F_146 ( V_138 ) && V_72 != F_147 ( V_138 ) ) ;
V_127 = V_72 == F_146 ( V_138 ) ;
V_122 = F_97 ( V_34 , V_189 ) & F_148 ( V_138 ) ;
F_87 ( V_122 << 16 != V_72 ) ;
F_15 ( & V_34 -> V_123 . V_124 ) ;
return V_127 ;
}
static void F_149 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
bool V_39 )
{
enum V_138 V_138 = V_36 -> V_65 ;
T_2 V_72 ;
T_2 V_122 ;
V_72 = V_39 ? F_146 ( V_138 ) : F_147 ( V_138 ) ;
F_14 ( & V_34 -> V_123 . V_124 ) ;
#define F_96 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_96 )
goto V_125;
V_122 = F_97 ( V_34 , V_189 ) ;
V_122 &= ~ F_148 ( V_138 ) ;
V_122 |= V_39 ? F_150 ( V_138 ) : F_151 ( V_138 ) ;
F_98 ( V_34 , V_189 , V_122 ) ;
if ( F_65 ( F_96 , 100 ) )
F_33 ( L_76 ,
V_72 ,
F_97 ( V_34 , V_189 ) ) ;
#undef F_96
V_125:
F_15 ( & V_34 -> V_123 . V_124 ) ;
}
static void F_152 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_141 ) ;
F_149 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
}
static void F_153 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_141 ) ;
F_149 ( V_34 , V_36 , true ) ;
F_105 ( V_34 ) ;
}
static void F_154 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_65 != V_141 ) ;
F_115 ( V_34 ) ;
F_149 ( V_34 , V_36 , false ) ;
}
static void
F_155 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_36 ;
int V_49 ;
F_156 (i, power_well, BIT(domain), power_domains)
F_6 ( V_34 , V_36 ) ;
V_47 -> V_190 [ V_2 ] ++ ;
}
void F_17 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
F_157 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
F_155 ( V_34 , V_2 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
bool F_158 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
bool V_48 ;
if ( ! F_159 ( V_34 ) )
return false ;
F_14 ( & V_47 -> V_54 ) ;
if ( F_11 ( V_34 , V_2 ) ) {
F_155 ( V_34 , V_2 ) ;
V_48 = true ;
} else {
V_48 = false ;
}
F_15 ( & V_47 -> V_54 ) ;
if ( ! V_48 )
F_160 ( V_34 ) ;
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
F_8 ( ! V_47 -> V_190 [ V_2 ] ,
L_84 ,
F_1 ( V_2 ) ) ;
V_47 -> V_190 [ V_2 ] -- ;
F_12 (i, power_well, BIT(domain), power_domains)
F_7 ( V_34 , V_36 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_160 ( V_34 ) ;
}
bool F_51 ( struct V_33 * V_34 ,
int V_89 )
{
struct V_35 * V_36 ;
bool V_53 ;
V_36 = F_75 ( V_34 , V_89 ) ;
V_53 = V_36 -> V_38 -> V_48 ( V_34 , V_36 ) ;
return V_53 ;
}
static int
F_161 ( const struct V_33 * V_34 ,
int V_191 )
{
if ( V_191 >= 0 )
return ! ! V_191 ;
return 1 ;
}
static T_1 F_162 ( const struct V_33 * V_34 ,
int V_192 )
{
T_1 V_76 ;
int V_193 ;
int V_194 ;
if ( F_59 ( V_34 ) || F_60 ( V_34 ) ) {
V_194 = 2 ;
V_76 = 0 ;
} else if ( F_41 ( V_34 ) ) {
V_194 = 1 ;
V_76 = V_70 ;
} else {
V_194 = 0 ;
V_76 = 0 ;
}
if ( ! V_195 . V_191 )
V_194 = 0 ;
if ( V_192 >= 0 && V_192 <= V_194 ) {
V_193 = V_192 ;
} else if ( V_192 == - 1 ) {
V_193 = V_194 ;
} else if ( V_192 > V_194 && V_192 <= 2 ) {
F_4 ( L_85 ,
V_192 , V_194 ) ;
V_193 = V_194 ;
} else {
F_33 ( L_86 , V_192 ) ;
V_193 = V_194 ;
}
if ( V_193 > 1 )
V_76 |= V_77 ;
if ( V_193 > 0 )
V_76 |= V_71 ;
F_4 ( L_87 , V_76 ) ;
return V_76 ;
}
int F_163 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
V_195 . V_191 = F_161 ( V_34 ,
V_195 . V_191 ) ;
V_34 -> V_79 . V_81 = F_162 ( V_34 ,
V_195 . V_192 ) ;
F_164 ( V_196 > 31 ) ;
F_165 ( & V_47 -> V_54 ) ;
if ( F_166 ( V_34 ) ) {
F_167 ( V_47 , V_197 ) ;
} else if ( F_24 ( V_34 ) ) {
F_167 ( V_47 , V_198 ) ;
} else if ( F_59 ( V_34 ) || F_60 ( V_34 ) ) {
F_167 ( V_47 , V_199 ) ;
} else if ( F_41 ( V_34 ) ) {
F_167 ( V_47 , V_200 ) ;
} else if ( F_168 ( V_34 ) ) {
F_167 ( V_47 , V_201 ) ;
} else if ( F_169 ( V_34 ) ) {
F_167 ( V_47 , V_202 ) ;
} else {
F_167 ( V_47 , V_203 ) ;
}
return 0 ;
}
void F_170 ( struct V_33 * V_34 )
{
struct V_204 * V_204 = & V_34 -> V_58 . V_59 -> V_57 ;
F_16 ( V_34 , true ) ;
if ( ! V_195 . V_191 )
F_18 ( V_34 , V_31 ) ;
if ( ! F_171 ( V_34 ) )
F_172 ( V_204 ) ;
}
static void F_173 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_36 ;
int V_49 ;
F_14 ( & V_47 -> V_54 ) ;
F_156 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_36 -> V_38 -> V_205 ( V_34 , V_36 ) ;
V_36 -> V_40 = V_36 -> V_38 -> V_48 ( V_34 ,
V_36 ) ;
}
F_15 ( & V_47 -> V_54 ) ;
}
static void F_174 ( struct V_33 * V_34 )
{
F_31 ( V_114 , F_10 ( V_114 ) | V_116 ) ;
F_34 ( V_114 ) ;
F_122 ( 10 ) ;
if ( ! ( F_10 ( V_114 ) & V_115 ) )
F_33 ( L_88 ) ;
}
static void F_175 ( struct V_33 * V_34 )
{
F_31 ( V_114 , F_10 ( V_114 ) & ~ V_116 ) ;
F_34 ( V_114 ) ;
F_122 ( 10 ) ;
if ( F_10 ( V_114 ) & V_115 )
F_33 ( L_89 ) ;
}
static void F_176 ( struct V_33 * V_34 ,
bool V_206 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_207 ;
T_1 V_78 ;
F_43 ( V_34 , V_82 ) ;
V_78 = F_10 ( V_208 ) ;
F_31 ( V_208 , V_78 | V_209 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_207 = F_75 ( V_34 , V_93 ) ;
F_3 ( V_34 , V_207 ) ;
V_207 = F_75 ( V_34 , V_94 ) ;
F_3 ( V_34 , V_207 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_177 ( V_34 ) ;
F_174 ( V_34 ) ;
if ( V_206 && V_34 -> V_79 . V_120 )
F_178 ( V_34 ) ;
}
static void F_179 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_207 ;
F_43 ( V_34 , V_82 ) ;
F_175 ( V_34 ) ;
F_180 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_207 = F_75 ( V_34 , V_94 ) ;
F_5 ( V_34 , V_207 ) ;
V_207 = F_75 ( V_34 , V_93 ) ;
F_5 ( V_34 , V_207 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
void F_181 ( struct V_33 * V_34 ,
bool V_206 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_207 ;
T_1 V_78 ;
F_43 ( V_34 , V_82 ) ;
V_78 = F_10 ( V_208 ) ;
V_78 &= ~ V_209 ;
F_31 ( V_208 , V_78 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_207 = F_75 ( V_34 , V_93 ) ;
F_3 ( V_34 , V_207 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_182 ( V_34 ) ;
F_174 ( V_34 ) ;
if ( V_206 && V_34 -> V_79 . V_120 )
F_178 ( V_34 ) ;
}
void F_183 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_207 ;
F_43 ( V_34 , V_82 ) ;
F_175 ( V_34 ) ;
F_184 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_207 = F_75 ( V_34 , V_93 ) ;
F_5 ( V_34 , V_207 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static void F_185 ( struct V_33 * V_34 )
{
struct V_35 * V_154 =
F_75 ( V_34 , V_149 ) ;
struct V_35 * V_155 =
F_75 ( V_34 , V_156 ) ;
V_34 -> V_158 =
F_186 ( V_210 , V_110 ) |
F_186 ( V_210 , V_109 ) |
F_187 ( V_211 , V_110 , V_162 ) |
F_187 ( V_211 , V_110 , V_163 ) |
F_187 ( V_211 , V_109 , V_162 ) ;
if ( V_154 -> V_38 -> V_48 ( V_34 , V_154 ) ) {
T_1 V_212 = F_10 ( F_107 ( V_141 ) ) ;
unsigned int V_76 ;
V_76 = V_212 & V_213 ;
if ( V_76 == 0xf )
V_76 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_110 , V_162 ) ;
V_34 -> V_158 |=
F_130 ( V_76 , V_110 , V_162 ) ;
V_76 = ( V_212 & V_214 ) >> 4 ;
if ( V_76 == 0xf )
V_76 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_110 , V_163 ) ;
V_34 -> V_158 |=
F_130 ( V_76 , V_110 , V_163 ) ;
V_34 -> V_158 |= F_135 ( V_110 ) ;
V_34 -> V_161 [ V_110 ] = false ;
} else {
V_34 -> V_161 [ V_110 ] = true ;
}
if ( V_155 -> V_38 -> V_48 ( V_34 , V_155 ) ) {
T_1 V_212 = F_10 ( V_215 ) ;
unsigned int V_76 ;
V_76 = V_212 & V_216 ;
if ( V_76 == 0xf )
V_76 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_109 , V_162 ) ;
V_34 -> V_158 |=
F_130 ( V_76 , V_109 , V_162 ) ;
V_34 -> V_158 |= F_135 ( V_109 ) ;
V_34 -> V_161 [ V_109 ] = false ;
} else {
V_34 -> V_161 [ V_109 ] = true ;
}
F_31 ( V_176 , V_34 -> V_158 ) ;
F_4 ( L_90 ,
V_34 -> V_158 ) ;
}
static void F_188 ( struct V_33 * V_34 )
{
struct V_35 * V_217 =
F_75 ( V_34 , V_149 ) ;
struct V_35 * V_218 =
F_75 ( V_34 , V_148 ) ;
if ( V_217 -> V_38 -> V_48 ( V_34 , V_217 ) &&
V_218 -> V_38 -> V_48 ( V_34 , V_218 ) &&
F_10 ( V_150 ) & V_151 )
return;
F_4 ( L_91 ) ;
V_218 -> V_38 -> V_39 ( V_34 , V_218 ) ;
V_217 -> V_38 -> V_41 ( V_34 , V_217 ) ;
}
void F_189 ( struct V_33 * V_34 , bool V_206 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_46 * V_47 = & V_34 -> V_47 ;
V_47 -> V_144 = true ;
if ( F_59 ( V_57 ) || F_60 ( V_57 ) ) {
F_176 ( V_34 , V_206 ) ;
} else if ( F_41 ( V_57 ) ) {
F_181 ( V_34 , V_206 ) ;
} else if ( F_168 ( V_57 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_185 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
} else if ( F_169 ( V_57 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_188 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
F_16 ( V_34 , true ) ;
if ( ! V_195 . V_191 )
F_17 ( V_34 , V_31 ) ;
F_173 ( V_34 ) ;
V_47 -> V_144 = false ;
}
void F_190 ( struct V_33 * V_34 )
{
if ( ! V_195 . V_191 )
F_18 ( V_34 , V_31 ) ;
if ( F_59 ( V_34 ) || F_60 ( V_34 ) )
F_179 ( V_34 ) ;
else if ( F_41 ( V_34 ) )
F_183 ( V_34 ) ;
}
void F_157 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_204 * V_204 = & V_57 -> V_59 -> V_57 ;
F_191 ( V_204 ) ;
F_192 ( & V_34 -> V_50 . V_219 ) ;
F_52 ( V_34 ) ;
}
bool F_159 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_204 * V_204 = & V_57 -> V_59 -> V_57 ;
if ( F_193 ( V_220 ) ) {
int V_53 = F_194 ( V_204 ) ;
F_44 ( V_53 < 0 ) ;
if ( V_53 <= 0 )
return false ;
}
F_192 ( & V_34 -> V_50 . V_219 ) ;
F_52 ( V_34 ) ;
return true ;
}
void F_195 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_204 * V_204 = & V_57 -> V_59 -> V_57 ;
F_52 ( V_34 ) ;
F_196 ( V_204 ) ;
F_192 ( & V_34 -> V_50 . V_219 ) ;
}
void F_160 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_204 * V_204 = & V_57 -> V_59 -> V_57 ;
F_52 ( V_34 ) ;
if ( F_197 ( & V_34 -> V_50 . V_219 ) )
F_192 ( & V_34 -> V_50 . V_221 ) ;
F_198 ( V_204 ) ;
F_199 ( V_204 ) ;
}
void F_200 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = & V_34 -> V_58 ;
struct V_204 * V_204 = & V_57 -> V_59 -> V_57 ;
F_201 ( V_204 , 10000 ) ;
F_198 ( V_204 ) ;
if ( ! F_171 ( V_57 ) ) {
F_202 ( V_204 ) ;
F_191 ( V_204 ) ;
} else {
F_203 ( V_204 ) ;
}
F_199 ( V_204 ) ;
}
