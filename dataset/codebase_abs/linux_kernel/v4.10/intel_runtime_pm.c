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
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_93 :
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
V_105 ,
V_105 ,
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
F_75 ( V_34 , V_36 -> V_106 ) ;
}
static void F_76 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_77 ( V_34 , V_36 -> V_106 ) ;
}
static bool F_78 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return F_79 ( V_34 , V_36 -> V_106 ) ;
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
V_36 = F_82 ( V_34 , V_107 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 , V_36 -> V_106 ) ;
V_36 = F_82 ( V_34 , V_108 ) ;
if ( V_36 -> V_42 > 0 )
F_83 ( V_34 , V_36 -> V_106 ) ;
}
static bool F_84 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return ( F_10 ( V_68 ) & V_109 ) == 0 ;
}
static void F_85 ( struct V_33 * V_34 )
{
T_2 V_67 = F_10 ( V_110 ) ;
F_8 ( ( V_67 & ( V_111 | V_112 ) ) !=
( V_111 | V_112 ) ,
L_75 , V_67 ) ;
}
static void F_86 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_43 ( V_34 , V_81 ) ;
F_87 ( V_34 -> V_113 !=
V_34 -> V_114 . V_115 ( V_34 ) ) ;
F_85 ( V_34 ) ;
if ( F_41 ( V_34 ) )
F_81 ( V_34 ) ;
}
static void F_88 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( ! V_34 -> V_78 . V_116 )
return;
if ( V_34 -> V_78 . V_80 & V_76 )
F_56 ( V_34 ) ;
else if ( V_34 -> V_78 . V_80 & V_70 )
F_54 ( V_34 ) ;
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
enum V_117 V_88 = V_36 -> V_64 ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_118 ;
V_75 = F_93 ( V_88 ) ;
V_71 = V_39 ? F_94 ( V_88 ) :
F_95 ( V_88 ) ;
F_14 ( & V_34 -> V_119 . V_120 ) ;
#define F_96 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_96 )
goto V_121;
V_118 = F_97 ( V_34 , V_122 ) ;
V_118 &= ~ V_75 ;
V_118 |= V_71 ;
F_98 ( V_34 , V_122 , V_118 ) ;
if ( F_66 ( F_96 , 100 ) )
F_33 ( L_76 ,
V_71 ,
F_97 ( V_34 , V_122 ) ) ;
#undef F_96
V_121:
F_15 ( & V_34 -> V_119 . V_120 ) ;
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
int V_88 = V_36 -> V_64 ;
bool V_123 = false ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_118 ;
V_75 = F_93 ( V_88 ) ;
V_118 = F_94 ( V_88 ) ;
F_14 ( & V_34 -> V_119 . V_120 ) ;
V_71 = F_97 ( V_34 , V_124 ) & V_75 ;
F_87 ( V_71 != F_94 ( V_88 ) &&
V_71 != F_95 ( V_88 ) ) ;
if ( V_71 == V_118 )
V_123 = true ;
V_118 = F_97 ( V_34 , V_122 ) & V_75 ;
F_87 ( V_118 != V_71 ) ;
F_15 ( & V_34 -> V_119 . V_120 ) ;
return V_123 ;
}
static void F_103 ( struct V_33 * V_34 )
{
T_2 V_77 ;
V_77 = F_10 ( V_125 ) ;
V_77 &= V_126 ;
V_77 |= V_127 ;
F_31 ( V_125 , V_77 ) ;
F_31 ( V_128 , V_129 ) ;
F_31 ( V_130 , 0 ) ;
F_87 ( V_34 -> V_131 == 0 ) ;
F_31 ( V_132 ,
F_104 ( V_34 -> V_131 , 1000 ) ) ;
}
static void F_105 ( struct V_33 * V_34 )
{
struct V_133 * V_134 ;
enum V_135 V_135 ;
F_106 (dev_priv, pipe) {
T_2 V_77 = F_10 ( F_107 ( V_135 ) ) ;
V_77 |= V_136 | V_137 ;
if ( V_135 != V_138 )
V_77 |= V_139 ;
F_31 ( F_107 ( V_135 ) , V_77 ) ;
}
F_103 ( V_34 ) ;
F_108 ( & V_34 -> V_140 ) ;
F_109 ( V_34 ) ;
F_110 ( & V_34 -> V_140 ) ;
if ( V_34 -> V_47 . V_141 )
return;
F_111 ( V_34 ) ;
F_112 (&dev_priv->drm, encoder) {
if ( V_134 -> type == V_142 )
F_113 ( & V_134 -> V_143 ) ;
}
F_114 ( V_34 ) ;
F_48 ( V_34 ) ;
}
static void F_115 ( struct V_33 * V_34 )
{
F_108 ( & V_34 -> V_140 ) ;
F_116 ( V_34 ) ;
F_110 ( & V_34 -> V_140 ) ;
F_117 ( V_34 -> V_58 . V_144 ) ;
F_46 ( V_34 ) ;
if ( ! V_34 -> V_58 . V_145 -> V_146 . V_147 )
F_118 ( V_34 ) ;
}
static void F_119 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_148 ) ;
F_92 ( V_34 , V_36 , true ) ;
F_105 ( V_34 ) ;
}
static void F_120 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_148 ) ;
F_115 ( V_34 ) ;
F_92 ( V_34 , V_36 , false ) ;
}
static void F_121 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_149 ) ;
F_122 ( 1 ) ;
F_92 ( V_34 , V_36 , true ) ;
F_31 ( V_150 , F_10 ( V_150 ) | V_151 ) ;
}
static void F_123 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_135 V_135 ;
F_44 ( V_36 -> V_64 != V_149 ) ;
F_106 (dev_priv, pipe)
F_124 ( V_34 , V_135 ) ;
F_31 ( V_150 , F_10 ( V_150 ) & ~ V_151 ) ;
F_92 ( V_34 , V_36 , false ) ;
}
static struct V_35 * F_82 ( struct V_33 * V_34 ,
int V_88 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_47 -> V_152 ; V_49 ++ ) {
struct V_35 * V_36 ;
V_36 = & V_47 -> V_153 [ V_49 ] ;
if ( V_36 -> V_64 == V_88 )
return V_36 ;
}
return NULL ;
}
static void F_125 ( struct V_33 * V_34 )
{
struct V_35 * V_154 =
F_82 ( V_34 , V_149 ) ;
struct V_35 * V_155 =
F_82 ( V_34 , V_156 ) ;
T_2 V_157 = V_34 -> V_158 ;
T_2 V_159 = 0 ;
T_2 V_160 = 0xffffffff ;
if ( ! V_34 -> V_161 [ V_162 ] )
V_160 &= ~ ( F_126 ( V_162 , V_163 ) |
F_127 ( V_162 , V_163 , 0 ) |
F_127 ( V_162 , V_163 , 1 ) |
F_126 ( V_162 , V_164 ) |
F_127 ( V_162 , V_164 , 0 ) |
F_127 ( V_162 , V_164 , 1 ) ) ;
if ( ! V_34 -> V_161 [ V_165 ] )
V_160 &= ~ ( F_126 ( V_165 , V_163 ) |
F_127 ( V_165 , V_163 , 0 ) |
F_127 ( V_165 , V_163 , 1 ) ) ;
if ( V_154 -> V_38 -> V_48 ( V_34 , V_154 ) ) {
V_159 |= F_128 ( V_162 ) ;
if ( ( V_157 & F_129 ( V_162 , V_163 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_162 , V_163 ) ;
if ( ( V_157 & F_129 ( V_162 , V_164 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_162 , V_164 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_162 , V_163 ) |
F_130 ( 0xf , V_162 , V_164 ) ) )
V_159 |= F_126 ( V_162 , V_163 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_162 , V_164 ) ) &&
( F_10 ( F_107 ( V_63 ) ) & V_166 ) == 0 )
V_159 |= F_126 ( V_162 , V_164 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_162 , V_163 ) ) )
V_159 |= F_127 ( V_162 , V_163 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_162 , V_163 ) ) )
V_159 |= F_127 ( V_162 , V_163 , 1 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_162 , V_164 ) ) )
V_159 |= F_127 ( V_162 , V_164 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_162 , V_164 ) ) )
V_159 |= F_127 ( V_162 , V_164 , 1 ) ;
}
if ( V_155 -> V_38 -> V_48 ( V_34 , V_155 ) ) {
V_159 |= F_128 ( V_165 ) ;
if ( ( V_157 & F_129 ( V_165 , V_163 ) ) == 0 )
V_157 |= F_130 ( 0xf , V_165 , V_163 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xf , V_165 , V_163 ) ) )
V_159 |= F_126 ( V_165 , V_163 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0x3 , V_165 , V_163 ) ) )
V_159 |= F_127 ( V_165 , V_163 , 0 ) ;
if ( F_131 ( V_157 ,
F_130 ( 0xc , V_165 , V_163 ) ) )
V_159 |= F_127 ( V_165 , V_163 , 1 ) ;
}
V_159 &= V_160 ;
if ( F_32 ( V_34 ,
V_167 ,
V_160 ,
V_159 ,
10 ) )
F_33 ( L_77 ,
F_10 ( V_167 ) & V_160 ,
V_159 , V_34 -> V_158 ) ;
}
static void F_132 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_168 V_169 ;
enum V_135 V_135 ;
T_1 V_67 ;
F_44 ( V_36 -> V_64 != V_149 &&
V_36 -> V_64 != V_156 ) ;
if ( V_36 -> V_64 == V_149 ) {
V_135 = V_138 ;
V_169 = V_162 ;
} else {
V_135 = V_62 ;
V_169 = V_165 ;
}
F_122 ( 1 ) ;
F_92 ( V_34 , V_36 , true ) ;
if ( F_32 ( V_34 ,
V_167 ,
F_128 ( V_169 ) ,
F_128 ( V_169 ) ,
1 ) )
F_33 ( L_78 , V_169 ) ;
F_14 ( & V_34 -> V_170 ) ;
V_67 = F_133 ( V_34 , V_135 , V_171 ) ;
V_67 |= V_172 | V_173 |
V_174 ;
F_134 ( V_34 , V_135 , V_171 , V_67 ) ;
if ( V_36 -> V_64 == V_149 ) {
V_67 = F_133 ( V_34 , V_135 , V_175 ) ;
V_67 |= V_176 ;
F_134 ( V_34 , V_135 , V_175 , V_67 ) ;
} else {
V_67 = F_133 ( V_34 , V_135 , V_177 ) ;
V_67 |= V_178 ;
F_134 ( V_34 , V_135 , V_177 , V_67 ) ;
}
F_15 ( & V_34 -> V_170 ) ;
V_34 -> V_158 |= F_135 ( V_169 ) ;
F_31 ( V_179 , V_34 -> V_158 ) ;
F_4 ( L_79 ,
V_169 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
}
static void F_136 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_168 V_169 ;
F_44 ( V_36 -> V_64 != V_149 &&
V_36 -> V_64 != V_156 ) ;
if ( V_36 -> V_64 == V_149 ) {
V_169 = V_162 ;
F_124 ( V_34 , V_138 ) ;
F_124 ( V_34 , V_63 ) ;
} else {
V_169 = V_165 ;
F_124 ( V_34 , V_62 ) ;
}
V_34 -> V_158 &= ~ F_135 ( V_169 ) ;
F_31 ( V_179 , V_34 -> V_158 ) ;
F_92 ( V_34 , V_36 , false ) ;
F_4 ( L_80 ,
V_169 , V_34 -> V_158 ) ;
V_34 -> V_161 [ V_169 ] = true ;
F_125 ( V_34 ) ;
}
static void F_137 ( struct V_33 * V_34 , enum V_168 V_169 ,
enum V_180 V_181 , bool V_182 , unsigned int V_75 )
{
enum V_135 V_135 = V_169 == V_162 ? V_138 : V_62 ;
T_2 V_183 , V_77 , V_184 , V_185 ;
if ( ! V_34 -> V_161 [ V_169 ] )
return;
if ( V_181 == V_163 )
V_183 = V_186 ;
else
V_183 = V_175 ;
F_14 ( & V_34 -> V_170 ) ;
V_77 = F_133 ( V_34 , V_135 , V_183 ) ;
F_15 ( & V_34 -> V_170 ) ;
if ( ! V_182 || V_75 == 0xf ) {
V_184 = V_187 | V_188 ;
if ( V_181 == V_164 && V_77 == 0 )
V_184 = 0 ;
} else if ( V_75 != 0x0 ) {
V_184 = V_188 ;
} else {
V_184 = 0 ;
}
if ( V_181 == V_163 )
V_185 = V_77 >> V_189 ;
else
V_185 = V_77 >> V_190 ;
V_185 &= V_187 | V_188 ;
F_8 ( V_185 != V_184 ,
L_81 ,
! ! ( V_185 & V_187 ) , ! ! ( V_185 & V_188 ) ,
! ! ( V_184 & V_187 ) , ! ! ( V_184 & V_188 ) ,
V_183 , V_77 ) ;
}
bool F_138 ( struct V_33 * V_34 , enum V_168 V_169 ,
enum V_180 V_181 , bool V_182 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
bool V_191 ;
F_14 ( & V_47 -> V_54 ) ;
V_191 = V_34 -> V_158 & F_129 ( V_169 , V_181 ) ;
if ( V_182 == V_191 )
goto V_121;
if ( V_182 )
V_34 -> V_158 |= F_129 ( V_169 , V_181 ) ;
else
V_34 -> V_158 &= ~ F_129 ( V_169 , V_181 ) ;
F_31 ( V_179 , V_34 -> V_158 ) ;
F_4 ( L_82 ,
V_169 , V_181 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
V_121:
F_15 ( & V_47 -> V_54 ) ;
return V_191 ;
}
void F_139 ( struct V_133 * V_134 ,
bool V_182 , unsigned int V_75 )
{
struct V_33 * V_34 = F_140 ( V_134 -> V_143 . V_145 ) ;
struct V_46 * V_47 = & V_34 -> V_47 ;
enum V_168 V_169 = F_141 ( F_142 ( & V_134 -> V_143 ) ) ;
enum V_180 V_181 = F_143 ( F_142 ( & V_134 -> V_143 ) ) ;
F_14 ( & V_47 -> V_54 ) ;
V_34 -> V_158 &= ~ F_130 ( 0xf , V_169 , V_181 ) ;
V_34 -> V_158 |= F_130 ( V_75 , V_169 , V_181 ) ;
if ( V_182 )
V_34 -> V_158 |= F_129 ( V_169 , V_181 ) ;
else
V_34 -> V_158 &= ~ F_129 ( V_169 , V_181 ) ;
F_31 ( V_179 , V_34 -> V_158 ) ;
F_4 ( L_83 ,
V_169 , V_181 , V_75 , V_34 -> V_158 ) ;
F_125 ( V_34 ) ;
F_137 ( V_34 , V_169 , V_181 , V_182 , V_75 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static bool F_144 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_135 V_135 = V_36 -> V_64 ;
bool V_123 ;
T_2 V_71 , V_118 ;
F_14 ( & V_34 -> V_119 . V_120 ) ;
V_71 = F_97 ( V_34 , V_192 ) & F_145 ( V_135 ) ;
F_87 ( V_71 != F_146 ( V_135 ) && V_71 != F_147 ( V_135 ) ) ;
V_123 = V_71 == F_146 ( V_135 ) ;
V_118 = F_97 ( V_34 , V_192 ) & F_148 ( V_135 ) ;
F_87 ( V_118 << 16 != V_71 ) ;
F_15 ( & V_34 -> V_119 . V_120 ) ;
return V_123 ;
}
static void F_149 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
bool V_39 )
{
enum V_135 V_135 = V_36 -> V_64 ;
T_2 V_71 ;
T_2 V_118 ;
V_71 = V_39 ? F_146 ( V_135 ) : F_147 ( V_135 ) ;
F_14 ( & V_34 -> V_119 . V_120 ) ;
#define F_96 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_96 )
goto V_121;
V_118 = F_97 ( V_34 , V_192 ) ;
V_118 &= ~ F_148 ( V_135 ) ;
V_118 |= V_39 ? F_150 ( V_135 ) : F_151 ( V_135 ) ;
F_98 ( V_34 , V_192 , V_118 ) ;
if ( F_66 ( F_96 , 100 ) )
F_33 ( L_76 ,
V_71 ,
F_97 ( V_34 , V_192 ) ) ;
#undef F_96
V_121:
F_15 ( & V_34 -> V_119 . V_120 ) ;
}
static void F_152 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_138 ) ;
F_149 ( V_34 , V_36 , V_36 -> V_42 > 0 ) ;
}
static void F_153 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_138 ) ;
F_149 ( V_34 , V_36 , true ) ;
F_105 ( V_34 ) ;
}
static void F_154 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_44 ( V_36 -> V_64 != V_138 ) ;
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
V_47 -> V_193 [ V_2 ] ++ ;
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
F_8 ( ! V_47 -> V_193 [ V_2 ] ,
L_84 ,
F_1 ( V_2 ) ) ;
V_47 -> V_193 [ V_2 ] -- ;
F_12 (i, power_well, BIT(domain), power_domains)
F_7 ( V_34 , V_36 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_160 ( V_34 ) ;
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
F_161 ( const struct V_33 * V_34 ,
int V_194 )
{
if ( V_194 >= 0 )
return ! ! V_194 ;
return 1 ;
}
static T_1 F_162 ( const struct V_33 * V_34 ,
int V_195 )
{
T_1 V_75 ;
int V_196 ;
int V_197 ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
V_197 = 2 ;
V_75 = 0 ;
} else if ( F_41 ( V_34 ) ) {
V_197 = 1 ;
V_75 = V_69 ;
} else {
V_197 = 0 ;
V_75 = 0 ;
}
if ( ! V_198 . V_194 )
V_197 = 0 ;
if ( V_195 >= 0 && V_195 <= V_197 ) {
V_196 = V_195 ;
} else if ( V_195 == - 1 ) {
V_196 = V_197 ;
} else if ( V_195 > V_197 && V_195 <= 2 ) {
F_4 ( L_85 ,
V_195 , V_197 ) ;
V_196 = V_197 ;
} else {
F_33 ( L_86 , V_195 ) ;
V_196 = V_197 ;
}
if ( V_196 > 1 )
V_75 |= V_76 ;
if ( V_196 > 0 )
V_75 |= V_70 ;
F_4 ( L_87 , V_75 ) ;
return V_75 ;
}
int F_163 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
V_198 . V_194 = F_161 ( V_34 ,
V_198 . V_194 ) ;
V_34 -> V_78 . V_80 = F_162 ( V_34 ,
V_198 . V_195 ) ;
F_164 ( V_199 > 31 ) ;
F_165 ( & V_47 -> V_54 ) ;
if ( F_166 ( V_34 ) ) {
F_167 ( V_47 , V_200 ) ;
} else if ( F_24 ( V_34 ) ) {
F_167 ( V_47 , V_201 ) ;
} else if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
F_167 ( V_47 , V_202 ) ;
} else if ( F_41 ( V_34 ) ) {
F_167 ( V_47 , V_203 ) ;
} else if ( F_168 ( V_34 ) ) {
F_167 ( V_47 , V_204 ) ;
} else if ( F_169 ( V_34 ) ) {
F_167 ( V_47 , V_205 ) ;
} else {
F_167 ( V_47 , V_206 ) ;
}
return 0 ;
}
void F_170 ( struct V_33 * V_34 )
{
struct V_207 * V_208 = & V_34 -> V_58 . V_57 -> V_145 ;
F_16 ( V_34 , true ) ;
if ( ! V_198 . V_194 )
F_18 ( V_34 , V_31 ) ;
if ( ! F_171 ( V_34 ) )
F_172 ( V_208 ) ;
}
static void F_173 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_36 ;
int V_49 ;
F_14 ( & V_47 -> V_54 ) ;
F_156 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_36 -> V_38 -> V_209 ( V_34 , V_36 ) ;
V_36 -> V_40 = V_36 -> V_38 -> V_48 ( V_34 ,
V_36 ) ;
}
F_15 ( & V_47 -> V_54 ) ;
}
static void F_174 ( struct V_33 * V_34 )
{
F_31 ( V_110 , F_10 ( V_110 ) | V_112 ) ;
F_34 ( V_110 ) ;
F_122 ( 10 ) ;
if ( ! ( F_10 ( V_110 ) & V_111 ) )
F_33 ( L_88 ) ;
}
static void F_175 ( struct V_33 * V_34 )
{
F_31 ( V_110 , F_10 ( V_110 ) & ~ V_112 ) ;
F_34 ( V_110 ) ;
F_122 ( 10 ) ;
if ( F_10 ( V_110 ) & V_111 )
F_33 ( L_89 ) ;
}
static void F_176 ( struct V_33 * V_34 ,
bool V_210 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_211 ;
T_1 V_77 ;
F_43 ( V_34 , V_81 ) ;
V_77 = F_10 ( V_212 ) ;
F_31 ( V_212 , V_77 | V_213 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_211 = F_82 ( V_34 , V_92 ) ;
F_3 ( V_34 , V_211 ) ;
V_211 = F_82 ( V_34 , V_93 ) ;
F_3 ( V_34 , V_211 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_177 ( V_34 ) ;
F_174 ( V_34 ) ;
if ( V_210 && V_34 -> V_78 . V_116 )
F_178 ( V_34 ) ;
}
static void F_179 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_211 ;
F_43 ( V_34 , V_81 ) ;
F_175 ( V_34 ) ;
F_180 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_211 = F_82 ( V_34 , V_93 ) ;
F_5 ( V_34 , V_211 ) ;
V_211 = F_82 ( V_34 , V_92 ) ;
F_5 ( V_34 , V_211 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
void F_181 ( struct V_33 * V_34 ,
bool V_210 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_211 ;
T_1 V_77 ;
F_43 ( V_34 , V_81 ) ;
V_77 = F_10 ( V_212 ) ;
V_77 &= ~ V_213 ;
F_31 ( V_212 , V_77 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_211 = F_82 ( V_34 , V_92 ) ;
F_3 ( V_34 , V_211 ) ;
F_15 ( & V_47 -> V_54 ) ;
F_182 ( V_34 ) ;
F_174 ( V_34 ) ;
if ( V_210 && V_34 -> V_78 . V_116 )
F_178 ( V_34 ) ;
}
void F_183 ( struct V_33 * V_34 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
struct V_35 * V_211 ;
F_43 ( V_34 , V_81 ) ;
F_175 ( V_34 ) ;
F_184 ( V_34 ) ;
F_14 ( & V_47 -> V_54 ) ;
V_211 = F_82 ( V_34 , V_92 ) ;
F_5 ( V_34 , V_211 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
static void F_185 ( struct V_33 * V_34 )
{
struct V_35 * V_154 =
F_82 ( V_34 , V_149 ) ;
struct V_35 * V_155 =
F_82 ( V_34 , V_156 ) ;
V_34 -> V_158 =
F_186 ( V_214 , V_162 ) |
F_186 ( V_214 , V_165 ) |
F_187 ( V_215 , V_162 , V_163 ) |
F_187 ( V_215 , V_162 , V_164 ) |
F_187 ( V_215 , V_165 , V_163 ) ;
if ( V_154 -> V_38 -> V_48 ( V_34 , V_154 ) ) {
T_1 V_216 = F_10 ( F_107 ( V_138 ) ) ;
unsigned int V_75 ;
V_75 = V_216 & V_217 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_162 , V_163 ) ;
V_34 -> V_158 |=
F_130 ( V_75 , V_162 , V_163 ) ;
V_75 = ( V_216 & V_218 ) >> 4 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_162 , V_164 ) ;
V_34 -> V_158 |=
F_130 ( V_75 , V_162 , V_164 ) ;
V_34 -> V_158 |= F_135 ( V_162 ) ;
V_34 -> V_161 [ V_162 ] = false ;
} else {
V_34 -> V_161 [ V_162 ] = true ;
}
if ( V_155 -> V_38 -> V_48 ( V_34 , V_155 ) ) {
T_1 V_216 = F_10 ( V_219 ) ;
unsigned int V_75 ;
V_75 = V_216 & V_220 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_34 -> V_158 |=
F_129 ( V_165 , V_163 ) ;
V_34 -> V_158 |=
F_130 ( V_75 , V_165 , V_163 ) ;
V_34 -> V_158 |= F_135 ( V_165 ) ;
V_34 -> V_161 [ V_165 ] = false ;
} else {
V_34 -> V_161 [ V_165 ] = true ;
}
F_31 ( V_179 , V_34 -> V_158 ) ;
F_4 ( L_90 ,
V_34 -> V_158 ) ;
}
static void F_188 ( struct V_33 * V_34 )
{
struct V_35 * V_221 =
F_82 ( V_34 , V_149 ) ;
struct V_35 * V_222 =
F_82 ( V_34 , V_148 ) ;
if ( V_221 -> V_38 -> V_48 ( V_34 , V_221 ) &&
V_222 -> V_38 -> V_48 ( V_34 , V_222 ) &&
F_10 ( V_150 ) & V_151 )
return;
F_4 ( L_91 ) ;
V_222 -> V_38 -> V_39 ( V_34 , V_222 ) ;
V_221 -> V_38 -> V_41 ( V_34 , V_221 ) ;
}
void F_189 ( struct V_33 * V_34 , bool V_210 )
{
struct V_46 * V_47 = & V_34 -> V_47 ;
V_47 -> V_141 = true ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) ) {
F_176 ( V_34 , V_210 ) ;
} else if ( F_41 ( V_34 ) ) {
F_181 ( V_34 , V_210 ) ;
} else if ( F_168 ( V_34 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_185 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
} else if ( F_169 ( V_34 ) ) {
F_14 ( & V_47 -> V_54 ) ;
F_188 ( V_34 ) ;
F_15 ( & V_47 -> V_54 ) ;
}
F_16 ( V_34 , true ) ;
if ( ! V_198 . V_194 )
F_17 ( V_34 , V_31 ) ;
F_173 ( V_34 ) ;
V_47 -> V_141 = false ;
}
void F_190 ( struct V_33 * V_34 )
{
if ( ! V_198 . V_194 )
F_18 ( V_34 , V_31 ) ;
if ( F_60 ( V_34 ) || F_61 ( V_34 ) )
F_179 ( V_34 ) ;
else if ( F_41 ( V_34 ) )
F_183 ( V_34 ) ;
}
void F_157 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_207 * V_208 = & V_57 -> V_145 ;
F_191 ( V_208 ) ;
F_192 ( & V_34 -> V_50 . V_223 ) ;
F_53 ( V_34 ) ;
}
bool F_159 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_207 * V_208 = & V_57 -> V_145 ;
if ( F_193 ( V_224 ) ) {
int V_53 = F_194 ( V_208 ) ;
F_44 ( V_53 < 0 ) ;
if ( V_53 <= 0 )
return false ;
}
F_192 ( & V_34 -> V_50 . V_223 ) ;
F_53 ( V_34 ) ;
return true ;
}
void F_195 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_207 * V_208 = & V_57 -> V_145 ;
F_53 ( V_34 ) ;
F_196 ( V_208 ) ;
F_192 ( & V_34 -> V_50 . V_223 ) ;
}
void F_160 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_207 * V_208 = & V_57 -> V_145 ;
F_53 ( V_34 ) ;
F_197 ( & V_34 -> V_50 . V_223 ) ;
F_198 ( V_208 ) ;
F_199 ( V_208 ) ;
}
void F_200 ( struct V_33 * V_34 )
{
struct V_56 * V_57 = V_34 -> V_58 . V_57 ;
struct V_207 * V_208 = & V_57 -> V_145 ;
F_201 ( V_208 , 10000 ) ;
F_198 ( V_208 ) ;
if ( ! F_171 ( V_34 ) ) {
F_202 ( V_208 ) ;
F_191 ( V_208 ) ;
} else {
F_203 ( V_208 ) ;
}
F_199 ( V_208 ) ;
}
