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
static bool F_9 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return F_10 ( V_48 ) ==
( V_49 | V_50 ) ;
}
bool F_11 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_40 * V_41 ;
bool V_51 ;
if ( V_39 -> V_52 . V_53 )
return false ;
V_51 = true ;
F_12 (dev_priv, power_well, BIT_ULL(domain)) {
if ( V_41 -> V_54 )
continue;
if ( ! V_41 -> V_45 ) {
V_51 = false ;
break;
}
}
return V_51 ;
}
bool F_13 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_55 * V_56 ;
bool V_57 ;
V_56 = & V_39 -> V_56 ;
F_14 ( & V_56 -> V_58 ) ;
V_57 = F_11 ( V_39 , V_2 ) ;
F_15 ( & V_56 -> V_58 ) ;
return V_57 ;
}
void F_16 ( struct V_38 * V_39 ,
bool V_44 )
{
if ( V_39 -> V_56 . V_59 == V_44 )
return;
if ( V_44 )
F_17 ( V_39 , V_36 ) ;
else
F_18 ( V_39 , V_36 ) ;
V_39 -> V_56 . V_59 = V_44 ;
}
static void F_19 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
F_20 ( V_61 , V_63 ) ;
F_21 ( F_22 ( V_64 ) , V_65 ) ;
F_23 ( V_61 , V_63 ) ;
if ( F_24 ( V_39 ) )
F_25 ( V_39 ,
1 << V_66 | 1 << V_67 ) ;
}
static void F_26 ( struct V_38 * V_39 )
{
if ( F_24 ( V_39 ) )
F_27 ( V_39 ,
1 << V_66 | 1 << V_67 ) ;
}
static void F_28 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
if ( V_41 -> V_68 == V_69 ) {
F_20 ( V_61 , V_63 ) ;
F_21 ( F_22 ( V_64 ) , V_65 ) ;
F_23 ( V_61 , V_63 ) ;
F_25 ( V_39 ,
1 << V_66 | 1 << V_67 ) ;
}
}
static void F_29 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( V_41 -> V_68 == V_69 )
F_27 ( V_39 ,
1 << V_66 | 1 << V_67 ) ;
}
static void F_30 ( struct V_38 * V_39 ,
struct V_40 * V_41 , bool V_44 )
{
bool V_51 , V_70 ;
T_1 V_71 ;
V_71 = F_10 ( V_48 ) ;
V_51 = V_71 & V_50 ;
V_70 = V_71 & V_49 ;
if ( V_44 ) {
if ( ! V_70 )
F_31 ( V_48 ,
V_49 ) ;
if ( ! V_51 ) {
F_4 ( L_40 ) ;
if ( F_32 ( V_39 ,
V_48 ,
V_50 ,
V_50 ,
20 ) )
F_33 ( L_41 ) ;
F_19 ( V_39 ) ;
}
} else {
if ( V_70 ) {
F_26 ( V_39 ) ;
F_31 ( V_48 , 0 ) ;
F_34 ( V_48 ) ;
F_4 ( L_42 ) ;
}
}
}
static void F_35 ( struct V_38 * V_39 )
{
F_36 ( ( F_10 ( V_72 ) & V_73 ) ,
L_43 ) ;
F_36 ( F_10 ( V_72 ) & V_74 ,
L_44 ) ;
F_36 ( F_10 ( V_48 ) , L_45 ) ;
F_36 ( F_37 ( V_39 ) ,
L_46 ) ;
}
static void F_38 ( struct V_38 * V_39 )
{
F_36 ( F_37 ( V_39 ) ,
L_46 ) ;
F_36 ( F_10 ( V_72 ) & V_74 ,
L_47 ) ;
}
static void F_39 ( struct V_38 * V_39 ,
T_2 V_75 )
{
int V_76 = 0 ;
int V_77 = 0 ;
T_2 V_78 ;
F_31 ( V_72 , V_75 ) ;
do {
V_78 = F_10 ( V_72 ) ;
if ( V_78 != V_75 ) {
F_31 ( V_72 , V_75 ) ;
V_76 ++ ;
V_77 = 0 ;
} else if ( V_77 ++ > 5 ) {
break;
}
} while ( V_76 < 100 );
if ( V_78 != V_75 )
F_33 ( L_48 ,
V_75 , V_78 ) ;
if ( V_76 > 1 )
F_4 ( L_49 ,
V_75 , V_76 ) ;
}
static T_2 F_40 ( struct V_38 * V_39 )
{
T_2 V_79 ;
V_79 = V_74 ;
if ( F_41 ( V_39 ) )
V_79 |= V_73 ;
else
V_79 |= V_80 ;
return V_79 ;
}
void F_42 ( struct V_38 * V_39 )
{
T_2 V_81 ;
V_81 = F_10 ( V_72 ) & F_40 ( V_39 ) ;
F_4 ( L_50 ,
V_39 -> V_82 . V_83 , V_81 ) ;
V_39 -> V_82 . V_83 = V_81 ;
}
static void F_43 ( struct V_38 * V_39 , T_1 V_75 )
{
T_1 V_81 ;
T_1 V_79 ;
if ( F_44 ( V_75 & ~ V_39 -> V_82 . V_84 ) )
V_75 &= V_39 -> V_82 . V_84 ;
V_81 = F_10 ( V_72 ) ;
V_79 = F_40 ( V_39 ) ;
F_4 ( L_51 ,
V_81 & V_79 , V_75 ) ;
if ( ( V_81 & V_79 ) != V_39 -> V_82 . V_83 )
F_33 ( L_52 ,
V_39 -> V_82 . V_83 , V_81 & V_79 ) ;
V_81 &= ~ V_79 ;
V_81 |= V_75 ;
F_39 ( V_39 , V_81 ) ;
V_39 -> V_82 . V_83 = V_81 & V_79 ;
}
void F_45 ( struct V_38 * V_39 )
{
F_35 ( V_39 ) ;
F_4 ( L_53 ) ;
F_46 ( V_39 ) ;
F_43 ( V_39 , V_73 ) ;
}
void F_47 ( struct V_38 * V_39 )
{
F_38 ( V_39 ) ;
F_4 ( L_54 ) ;
F_43 ( V_39 , V_85 ) ;
F_48 ( V_39 ) ;
}
static void F_49 ( struct V_38 * V_39 )
{
F_36 ( ! F_10 ( F_50 ( 0 ) ) ,
L_55 ) ;
F_36 ( ! F_10 ( V_86 ) , L_56 ) ;
F_36 ( ! F_10 ( V_87 ) , L_57 ) ;
}
static void F_51 ( struct V_38 * V_39 )
{
bool V_88 = F_52 ( V_39 ,
V_69 ) ;
F_36 ( V_88 , L_58 ) ;
F_36 ( ( F_10 ( V_72 ) & V_74 ) ,
L_59 ) ;
F_53 ( V_39 ) ;
F_49 ( V_39 ) ;
}
void F_54 ( struct V_38 * V_39 )
{
F_51 ( V_39 ) ;
F_4 ( L_60 ) ;
F_43 ( V_39 , V_74 ) ;
}
static void F_55 ( struct V_38 * V_39 )
{
F_36 ( F_10 ( V_89 ) & V_90 ,
L_61 ) ;
F_36 ( ( F_10 ( V_72 ) & V_80 ) ,
L_62 ) ;
F_49 ( V_39 ) ;
}
void F_56 ( struct V_38 * V_39 )
{
F_55 ( V_39 ) ;
F_4 ( L_63 ) ;
F_43 ( V_39 , V_80 ) ;
}
void F_57 ( struct V_38 * V_39 )
{
F_4 ( L_64 ) ;
F_43 ( V_39 , V_85 ) ;
}
static void
F_58 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_91 V_92 = V_41 -> V_68 ;
T_2 V_81 ;
T_2 V_79 ;
V_79 = F_59 ( V_92 ) ;
V_81 = F_10 ( V_93 ) ;
if ( F_36 ( V_81 & V_79 , L_65 ,
V_41 -> V_42 ) )
F_31 ( V_93 , V_81 & ~ V_79 ) ;
V_81 = F_10 ( V_94 ) ;
V_81 |= F_10 ( V_95 ) ;
if ( ! ( V_81 & V_79 ) )
return;
if ( V_92 == V_96 ||
( F_60 ( V_39 ) &&
V_92 == V_97 ) )
F_61 ( L_66
L_67 , V_41 -> V_42 ) ;
else
F_36 ( 1 , L_68 ,
V_41 -> V_42 ) ;
F_31 ( V_94 , V_81 & ~ V_79 ) ;
F_31 ( V_95 , V_81 & ~ V_79 ) ;
}
static void F_62 ( struct V_38 * V_39 ,
struct V_40 * V_41 , bool V_44 )
{
T_1 V_71 , V_98 ;
T_1 V_99 , V_100 ;
bool V_51 , V_70 , V_101 = false ;
V_71 = F_10 ( V_48 ) ;
V_98 = F_10 ( V_102 ) ;
switch ( V_41 -> V_68 ) {
case V_96 :
if ( F_32 ( V_39 ,
V_102 ,
V_103 ,
V_103 ,
1 ) ) {
F_33 ( L_69 ) ;
return;
}
break;
case V_69 :
if ( ! ( V_98 & V_104 ) ) {
F_33 ( L_70 ) ;
return;
}
break;
case V_97 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
break;
default:
F_8 ( 1 , L_71 , V_41 -> V_68 ) ;
return;
}
V_99 = F_59 ( V_41 -> V_68 ) ;
V_70 = V_71 & V_99 ;
V_100 = F_63 ( V_41 -> V_68 ) ;
V_51 = V_71 & V_100 ;
if ( ! V_44 && V_70 )
F_29 ( V_39 , V_41 ) ;
if ( V_44 ) {
if ( ! V_70 ) {
F_8 ( ( V_71 & V_100 ) &&
! F_10 ( V_94 ) ,
L_72 ) ;
F_31 ( V_48 , V_71 | V_99 ) ;
}
if ( ! V_51 ) {
F_4 ( L_73 , V_41 -> V_42 ) ;
V_101 = true ;
}
} else {
if ( V_70 ) {
F_31 ( V_48 , V_71 & ~ V_99 ) ;
F_34 ( V_48 ) ;
F_4 ( L_74 , V_41 -> V_42 ) ;
}
F_58 ( V_39 , V_41 ) ;
}
if ( F_64 ( ! ! ( F_10 ( V_48 ) & V_100 ) == V_44 ,
1 ) )
F_33 ( L_75 ,
V_41 -> V_42 , V_44 ? L_76 : L_77 ) ;
if ( V_101 ) {
if ( V_41 -> V_68 == V_96 ) {
if ( F_32 ( V_39 ,
V_102 ,
V_104 ,
V_104 ,
1 ) )
F_33 ( L_78 ) ;
} else if ( V_41 -> V_68 == V_69 ) {
if ( F_32 ( V_39 ,
V_102 ,
V_113 ,
V_113 ,
1 ) )
F_33 ( L_79 ) ;
}
}
if ( V_44 && ! V_51 )
F_28 ( V_39 , V_41 ) ;
}
static void F_65 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( F_10 ( V_94 ) & V_49 ) {
if ( ! ( F_10 ( V_48 ) &
V_49 ) )
F_31 ( V_48 ,
V_49 ) ;
F_31 ( V_94 , 0 ) ;
}
}
static void F_66 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_30 ( V_39 , V_41 , true ) ;
}
static void F_67 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_30 ( V_39 , V_41 , false ) ;
}
static bool F_68 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
T_1 V_79 = F_59 ( V_41 -> V_68 ) |
F_63 ( V_41 -> V_68 ) ;
return ( F_10 ( V_48 ) & V_79 ) == V_79 ;
}
static void F_69 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
T_1 V_79 = F_59 ( V_41 -> V_68 ) ;
T_1 V_114 = F_10 ( V_94 ) ;
if ( V_114 & V_79 ) {
T_1 V_115 = F_10 ( V_48 ) ;
if ( ! ( V_115 & V_79 ) )
F_31 ( V_48 , V_115 | V_79 ) ;
F_31 ( V_94 , V_114 & ~ V_79 ) ;
}
}
static void F_70 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_62 ( V_39 , V_41 , true ) ;
}
static void F_71 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_62 ( V_39 , V_41 , false ) ;
}
static void F_72 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_73 ( V_39 , V_41 -> V_116 ) ;
}
static void F_74 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_75 ( V_39 , V_41 -> V_116 ) ;
}
static bool F_76 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return F_77 ( V_39 , V_41 -> V_116 ) ;
}
static void F_78 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
V_41 = F_79 ( V_39 , V_117 ) ;
if ( V_41 -> V_47 > 0 )
F_80 ( V_39 , V_41 -> V_116 ) ;
V_41 = F_79 ( V_39 , V_118 ) ;
if ( V_41 -> V_47 > 0 )
F_80 ( V_39 , V_41 -> V_116 ) ;
if ( F_81 ( V_39 ) ) {
V_41 = F_79 ( V_39 , V_119 ) ;
if ( V_41 -> V_47 > 0 )
F_80 ( V_39 , V_41 -> V_116 ) ;
}
}
static bool F_82 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return ( F_10 ( V_72 ) & V_120 ) == 0 ;
}
static void F_83 ( struct V_38 * V_39 )
{
T_2 V_71 = F_10 ( V_121 ) ;
F_8 ( ( V_71 & ( V_122 | V_123 ) ) !=
( V_122 | V_123 ) ,
L_80 , V_71 ) ;
}
static void F_84 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_124 V_125 = {} ;
F_43 ( V_39 , V_85 ) ;
V_39 -> V_126 . V_127 ( V_39 , & V_125 ) ;
F_85 ( ! F_86 ( & V_39 -> V_128 . V_129 , & V_125 ) ) ;
F_83 ( V_39 ) ;
if ( F_41 ( V_39 ) )
F_78 ( V_39 ) ;
}
static void F_87 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( ! V_39 -> V_82 . V_130 )
return;
if ( V_39 -> V_82 . V_84 & V_80 )
F_56 ( V_39 ) ;
else if ( V_39 -> V_82 . V_84 & V_74 )
F_54 ( V_39 ) ;
}
static void F_88 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
}
static void F_89 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
}
static bool F_90 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return true ;
}
static void F_91 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( ( F_10 ( F_92 ( V_131 ) ) & V_132 ) == 0 )
F_93 ( V_39 , V_131 ) ;
if ( ( F_10 ( F_92 ( V_67 ) ) & V_132 ) == 0 )
F_93 ( V_39 , V_67 ) ;
}
static void F_94 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_95 ( V_39 , V_67 ) ;
F_95 ( V_39 , V_131 ) ;
}
static bool F_96 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return F_10 ( F_92 ( V_131 ) ) & V_132 &&
F_10 ( F_92 ( V_67 ) ) & V_132 ;
}
static void F_97 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
if ( V_41 -> V_47 > 0 )
F_91 ( V_39 , V_41 ) ;
else
F_94 ( V_39 , V_41 ) ;
}
static void F_98 ( struct V_38 * V_39 ,
struct V_40 * V_41 , bool V_44 )
{
enum V_133 V_92 = V_41 -> V_68 ;
T_2 V_79 ;
T_2 V_75 ;
T_2 V_134 ;
V_79 = F_99 ( V_92 ) ;
V_75 = V_44 ? F_100 ( V_92 ) :
F_101 ( V_92 ) ;
F_14 ( & V_39 -> V_135 . V_136 ) ;
#define F_102 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_102 )
goto V_137;
V_134 = F_103 ( V_39 , V_138 ) ;
V_134 &= ~ V_79 ;
V_134 |= V_75 ;
F_104 ( V_39 , V_138 , V_134 ) ;
if ( F_64 ( F_102 , 100 ) )
F_33 ( L_81 ,
V_75 ,
F_103 ( V_39 , V_138 ) ) ;
#undef F_102
V_137:
F_15 ( & V_39 -> V_135 . V_136 ) ;
}
static void F_105 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_98 ( V_39 , V_41 , true ) ;
}
static void F_106 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_98 ( V_39 , V_41 , false ) ;
}
static bool F_107 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_92 = V_41 -> V_68 ;
bool V_139 = false ;
T_2 V_79 ;
T_2 V_75 ;
T_2 V_134 ;
V_79 = F_99 ( V_92 ) ;
V_134 = F_100 ( V_92 ) ;
F_14 ( & V_39 -> V_135 . V_136 ) ;
V_75 = F_103 ( V_39 , V_140 ) & V_79 ;
F_85 ( V_75 != F_100 ( V_92 ) &&
V_75 != F_101 ( V_92 ) ) ;
if ( V_75 == V_134 )
V_139 = true ;
V_134 = F_103 ( V_39 , V_138 ) & V_79 ;
F_85 ( V_134 != V_75 ) ;
F_15 ( & V_39 -> V_135 . V_136 ) ;
return V_139 ;
}
static void F_108 ( struct V_38 * V_39 )
{
T_2 V_81 ;
V_81 = F_10 ( V_141 ) ;
V_81 &= V_142 ;
V_81 |= V_143 ;
F_31 ( V_141 , V_81 ) ;
F_31 ( V_144 , V_145 ) ;
F_31 ( V_146 , 0 ) ;
F_85 ( V_39 -> V_147 == 0 ) ;
F_31 ( V_148 ,
F_109 ( V_39 -> V_147 , 1000 ) ) ;
}
static void F_110 ( struct V_38 * V_39 )
{
struct V_149 * V_150 ;
enum V_151 V_151 ;
F_111 (dev_priv, pipe) {
T_2 V_81 = F_10 ( F_112 ( V_151 ) ) ;
V_81 |= V_152 | V_153 ;
if ( V_151 != V_131 )
V_81 |= V_154 ;
F_31 ( F_112 ( V_151 ) , V_81 ) ;
}
F_108 ( V_39 ) ;
F_113 ( & V_39 -> V_155 ) ;
F_114 ( V_39 ) ;
F_115 ( & V_39 -> V_155 ) ;
if ( V_39 -> V_56 . V_156 )
return;
F_116 ( V_39 ) ;
F_117 (&dev_priv->drm, encoder) {
if ( V_150 -> type == V_157 )
F_118 ( & V_150 -> V_158 ) ;
}
F_119 ( V_39 ) ;
F_48 ( V_39 ) ;
}
static void F_120 ( struct V_38 * V_39 )
{
F_113 ( & V_39 -> V_155 ) ;
F_121 ( V_39 ) ;
F_115 ( & V_39 -> V_155 ) ;
F_122 ( V_39 -> V_62 . V_159 ) ;
F_46 ( V_39 ) ;
if ( ! V_39 -> V_62 . V_160 -> V_161 . V_162 )
F_123 ( V_39 ) ;
}
static void F_124 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_44 ( V_41 -> V_68 != V_163 ) ;
F_98 ( V_39 , V_41 , true ) ;
F_110 ( V_39 ) ;
}
static void F_125 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_44 ( V_41 -> V_68 != V_163 ) ;
F_120 ( V_39 ) ;
F_98 ( V_39 , V_41 , false ) ;
}
static void F_126 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_44 ( V_41 -> V_68 != V_164 ) ;
F_127 ( 1 ) ;
F_98 ( V_39 , V_41 , true ) ;
F_31 ( V_165 , F_10 ( V_165 ) | V_166 ) ;
}
static void F_128 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_151 V_151 ;
F_44 ( V_41 -> V_68 != V_164 ) ;
F_111 (dev_priv, pipe)
F_129 ( V_39 , V_151 ) ;
F_31 ( V_165 , F_10 ( V_165 ) & ~ V_166 ) ;
F_98 ( V_39 , V_41 , false ) ;
}
static struct V_40 * F_79 ( struct V_38 * V_39 ,
int V_92 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
int V_167 ;
for ( V_167 = 0 ; V_167 < V_56 -> V_168 ; V_167 ++ ) {
struct V_40 * V_41 ;
V_41 = & V_56 -> V_169 [ V_167 ] ;
if ( V_41 -> V_68 == V_92 )
return V_41 ;
}
return NULL ;
}
static void F_130 ( struct V_38 * V_39 )
{
struct V_40 * V_170 =
F_79 ( V_39 , V_164 ) ;
struct V_40 * V_171 =
F_79 ( V_39 , V_172 ) ;
T_2 V_173 = V_39 -> V_174 ;
T_2 V_175 = 0 ;
T_2 V_176 = 0xffffffff ;
if ( ! V_39 -> V_177 [ V_178 ] )
V_176 &= ~ ( F_131 ( V_178 , V_179 ) |
F_132 ( V_178 , V_179 , 0 ) |
F_132 ( V_178 , V_179 , 1 ) |
F_131 ( V_178 , V_180 ) |
F_132 ( V_178 , V_180 , 0 ) |
F_132 ( V_178 , V_180 , 1 ) ) ;
if ( ! V_39 -> V_177 [ V_181 ] )
V_176 &= ~ ( F_131 ( V_181 , V_179 ) |
F_132 ( V_181 , V_179 , 0 ) |
F_132 ( V_181 , V_179 , 1 ) ) ;
if ( V_170 -> V_43 -> V_51 ( V_39 , V_170 ) ) {
V_175 |= F_133 ( V_178 ) ;
if ( ( V_173 & F_134 ( V_178 , V_179 ) ) == 0 )
V_173 |= F_135 ( 0xf , V_178 , V_179 ) ;
if ( ( V_173 & F_134 ( V_178 , V_180 ) ) == 0 )
V_173 |= F_135 ( 0xf , V_178 , V_180 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xf , V_178 , V_179 ) |
F_135 ( 0xf , V_178 , V_180 ) ) )
V_175 |= F_131 ( V_178 , V_179 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xf , V_178 , V_180 ) ) &&
( F_10 ( F_112 ( V_67 ) ) & V_182 ) == 0 )
V_175 |= F_131 ( V_178 , V_180 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0x3 , V_178 , V_179 ) ) )
V_175 |= F_132 ( V_178 , V_179 , 0 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xc , V_178 , V_179 ) ) )
V_175 |= F_132 ( V_178 , V_179 , 1 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0x3 , V_178 , V_180 ) ) )
V_175 |= F_132 ( V_178 , V_180 , 0 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xc , V_178 , V_180 ) ) )
V_175 |= F_132 ( V_178 , V_180 , 1 ) ;
}
if ( V_171 -> V_43 -> V_51 ( V_39 , V_171 ) ) {
V_175 |= F_133 ( V_181 ) ;
if ( ( V_173 & F_134 ( V_181 , V_179 ) ) == 0 )
V_173 |= F_135 ( 0xf , V_181 , V_179 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xf , V_181 , V_179 ) ) )
V_175 |= F_131 ( V_181 , V_179 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0x3 , V_181 , V_179 ) ) )
V_175 |= F_132 ( V_181 , V_179 , 0 ) ;
if ( F_136 ( V_173 ,
F_135 ( 0xc , V_181 , V_179 ) ) )
V_175 |= F_132 ( V_181 , V_179 , 1 ) ;
}
V_175 &= V_176 ;
if ( F_32 ( V_39 ,
V_183 ,
V_176 ,
V_175 ,
10 ) )
F_33 ( L_82 ,
F_10 ( V_183 ) & V_176 ,
V_175 , V_39 -> V_174 ) ;
}
static void F_137 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_184 V_185 ;
enum V_151 V_151 ;
T_1 V_71 ;
F_44 ( V_41 -> V_68 != V_164 &&
V_41 -> V_68 != V_172 ) ;
if ( V_41 -> V_68 == V_164 ) {
V_151 = V_131 ;
V_185 = V_178 ;
} else {
V_151 = V_66 ;
V_185 = V_181 ;
}
F_127 ( 1 ) ;
F_98 ( V_39 , V_41 , true ) ;
if ( F_32 ( V_39 ,
V_183 ,
F_133 ( V_185 ) ,
F_133 ( V_185 ) ,
1 ) )
F_33 ( L_83 , V_185 ) ;
F_14 ( & V_39 -> V_186 ) ;
V_71 = F_138 ( V_39 , V_151 , V_187 ) ;
V_71 |= V_188 | V_189 |
V_190 ;
F_139 ( V_39 , V_151 , V_187 , V_71 ) ;
if ( V_41 -> V_68 == V_164 ) {
V_71 = F_138 ( V_39 , V_151 , V_191 ) ;
V_71 |= V_192 ;
F_139 ( V_39 , V_151 , V_191 , V_71 ) ;
} else {
V_71 = F_138 ( V_39 , V_151 , V_193 ) ;
V_71 |= V_194 ;
F_139 ( V_39 , V_151 , V_193 , V_71 ) ;
}
F_15 ( & V_39 -> V_186 ) ;
V_39 -> V_174 |= F_140 ( V_185 ) ;
F_31 ( V_195 , V_39 -> V_174 ) ;
F_4 ( L_84 ,
V_185 , V_39 -> V_174 ) ;
F_130 ( V_39 ) ;
}
static void F_141 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_184 V_185 ;
F_44 ( V_41 -> V_68 != V_164 &&
V_41 -> V_68 != V_172 ) ;
if ( V_41 -> V_68 == V_164 ) {
V_185 = V_178 ;
F_129 ( V_39 , V_131 ) ;
F_129 ( V_39 , V_67 ) ;
} else {
V_185 = V_181 ;
F_129 ( V_39 , V_66 ) ;
}
V_39 -> V_174 &= ~ F_140 ( V_185 ) ;
F_31 ( V_195 , V_39 -> V_174 ) ;
F_98 ( V_39 , V_41 , false ) ;
F_4 ( L_85 ,
V_185 , V_39 -> V_174 ) ;
V_39 -> V_177 [ V_185 ] = true ;
F_130 ( V_39 ) ;
}
static void F_142 ( struct V_38 * V_39 , enum V_184 V_185 ,
enum V_196 V_197 , bool V_198 , unsigned int V_79 )
{
enum V_151 V_151 = V_185 == V_178 ? V_131 : V_66 ;
T_2 V_199 , V_81 , V_200 , V_201 ;
if ( ! V_39 -> V_177 [ V_185 ] )
return;
if ( V_197 == V_179 )
V_199 = V_202 ;
else
V_199 = V_191 ;
F_14 ( & V_39 -> V_186 ) ;
V_81 = F_138 ( V_39 , V_151 , V_199 ) ;
F_15 ( & V_39 -> V_186 ) ;
if ( ! V_198 || V_79 == 0xf ) {
V_200 = V_203 | V_204 ;
if ( V_197 == V_180 && V_81 == 0 )
V_200 = 0 ;
} else if ( V_79 != 0x0 ) {
V_200 = V_204 ;
} else {
V_200 = 0 ;
}
if ( V_197 == V_179 )
V_201 = V_81 >> V_205 ;
else
V_201 = V_81 >> V_206 ;
V_201 &= V_203 | V_204 ;
F_8 ( V_201 != V_200 ,
L_86 ,
! ! ( V_201 & V_203 ) , ! ! ( V_201 & V_204 ) ,
! ! ( V_200 & V_203 ) , ! ! ( V_200 & V_204 ) ,
V_199 , V_81 ) ;
}
bool F_143 ( struct V_38 * V_39 , enum V_184 V_185 ,
enum V_196 V_197 , bool V_198 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
bool V_207 ;
F_14 ( & V_56 -> V_58 ) ;
V_207 = V_39 -> V_174 & F_134 ( V_185 , V_197 ) ;
if ( V_198 == V_207 )
goto V_137;
if ( V_198 )
V_39 -> V_174 |= F_134 ( V_185 , V_197 ) ;
else
V_39 -> V_174 &= ~ F_134 ( V_185 , V_197 ) ;
F_31 ( V_195 , V_39 -> V_174 ) ;
F_4 ( L_87 ,
V_185 , V_197 , V_39 -> V_174 ) ;
F_130 ( V_39 ) ;
V_137:
F_15 ( & V_56 -> V_58 ) ;
return V_207 ;
}
void F_144 ( struct V_149 * V_150 ,
bool V_198 , unsigned int V_79 )
{
struct V_38 * V_39 = F_145 ( V_150 -> V_158 . V_160 ) ;
struct V_55 * V_56 = & V_39 -> V_56 ;
enum V_184 V_185 = F_146 ( F_147 ( & V_150 -> V_158 ) ) ;
enum V_196 V_197 = F_148 ( F_147 ( & V_150 -> V_158 ) ) ;
F_14 ( & V_56 -> V_58 ) ;
V_39 -> V_174 &= ~ F_135 ( 0xf , V_185 , V_197 ) ;
V_39 -> V_174 |= F_135 ( V_79 , V_185 , V_197 ) ;
if ( V_198 )
V_39 -> V_174 |= F_134 ( V_185 , V_197 ) ;
else
V_39 -> V_174 &= ~ F_134 ( V_185 , V_197 ) ;
F_31 ( V_195 , V_39 -> V_174 ) ;
F_4 ( L_88 ,
V_185 , V_197 , V_79 , V_39 -> V_174 ) ;
F_130 ( V_39 ) ;
F_142 ( V_39 , V_185 , V_197 , V_198 , V_79 ) ;
F_15 ( & V_56 -> V_58 ) ;
}
static bool F_149 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
enum V_151 V_151 = V_41 -> V_68 ;
bool V_139 ;
T_2 V_75 , V_134 ;
F_14 ( & V_39 -> V_135 . V_136 ) ;
V_75 = F_103 ( V_39 , V_208 ) & F_150 ( V_151 ) ;
F_85 ( V_75 != F_151 ( V_151 ) && V_75 != F_152 ( V_151 ) ) ;
V_139 = V_75 == F_151 ( V_151 ) ;
V_134 = F_103 ( V_39 , V_208 ) & F_153 ( V_151 ) ;
F_85 ( V_134 << 16 != V_75 ) ;
F_15 ( & V_39 -> V_135 . V_136 ) ;
return V_139 ;
}
static void F_154 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
bool V_44 )
{
enum V_151 V_151 = V_41 -> V_68 ;
T_2 V_75 ;
T_2 V_134 ;
V_75 = V_44 ? F_151 ( V_151 ) : F_152 ( V_151 ) ;
F_14 ( & V_39 -> V_135 . V_136 ) ;
#define F_102 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_102 )
goto V_137;
V_134 = F_103 ( V_39 , V_208 ) ;
V_134 &= ~ F_153 ( V_151 ) ;
V_134 |= V_44 ? F_155 ( V_151 ) : F_156 ( V_151 ) ;
F_104 ( V_39 , V_208 , V_134 ) ;
if ( F_64 ( F_102 , 100 ) )
F_33 ( L_81 ,
V_75 ,
F_103 ( V_39 , V_208 ) ) ;
#undef F_102
V_137:
F_15 ( & V_39 -> V_135 . V_136 ) ;
}
static void F_157 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_44 ( V_41 -> V_68 != V_131 ) ;
F_154 ( V_39 , V_41 , true ) ;
F_110 ( V_39 ) ;
}
static void F_158 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_44 ( V_41 -> V_68 != V_131 ) ;
F_120 ( V_39 ) ;
F_154 ( V_39 , V_41 , false ) ;
}
static void
F_159 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_41 ;
F_160 (dev_priv, power_well, BIT_ULL(domain))
F_6 ( V_39 , V_41 ) ;
V_56 -> V_209 [ V_2 ] ++ ;
}
void F_17 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
F_161 ( V_39 ) ;
F_14 ( & V_56 -> V_58 ) ;
F_159 ( V_39 , V_2 ) ;
F_15 ( & V_56 -> V_58 ) ;
}
bool F_162 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
bool V_51 ;
if ( ! F_163 ( V_39 ) )
return false ;
F_14 ( & V_56 -> V_58 ) ;
if ( F_11 ( V_39 , V_2 ) ) {
F_159 ( V_39 , V_2 ) ;
V_51 = true ;
} else {
V_51 = false ;
}
F_15 ( & V_56 -> V_58 ) ;
if ( ! V_51 )
F_164 ( V_39 ) ;
return V_51 ;
}
void F_18 ( struct V_38 * V_39 ,
enum V_1 V_2 )
{
struct V_55 * V_56 ;
struct V_40 * V_41 ;
V_56 = & V_39 -> V_56 ;
F_14 ( & V_56 -> V_58 ) ;
F_8 ( ! V_56 -> V_209 [ V_2 ] ,
L_89 ,
F_1 ( V_2 ) ) ;
V_56 -> V_209 [ V_2 ] -- ;
F_12 (dev_priv, power_well, BIT_ULL(domain))
F_7 ( V_39 , V_41 ) ;
F_15 ( & V_56 -> V_58 ) ;
F_164 ( V_39 ) ;
}
bool F_52 ( struct V_38 * V_39 ,
int V_92 )
{
struct V_40 * V_41 ;
bool V_57 ;
V_41 = F_79 ( V_39 , V_92 ) ;
V_57 = V_41 -> V_43 -> V_51 ( V_39 , V_41 ) ;
return V_57 ;
}
static int
F_165 ( const struct V_38 * V_39 ,
int V_210 )
{
if ( V_210 >= 0 )
return ! ! V_210 ;
return 1 ;
}
static T_1 F_166 ( const struct V_38 * V_39 ,
int V_211 )
{
T_1 V_79 ;
int V_212 ;
int V_213 ;
if ( F_60 ( V_39 ) ) {
V_213 = 2 ;
V_79 = 0 ;
} else if ( F_41 ( V_39 ) ) {
V_213 = 1 ;
V_79 = V_73 ;
} else {
V_213 = 0 ;
V_79 = 0 ;
}
if ( ! V_214 . V_210 )
V_213 = 0 ;
if ( V_211 >= 0 && V_211 <= V_213 ) {
V_212 = V_211 ;
} else if ( V_211 == - 1 ) {
V_212 = V_213 ;
} else if ( V_211 > V_213 && V_211 <= 2 ) {
F_4 ( L_90 ,
V_211 , V_213 ) ;
V_212 = V_213 ;
} else {
F_33 ( L_91 , V_211 ) ;
V_212 = V_213 ;
}
if ( V_212 > 1 )
V_79 |= V_80 ;
if ( V_212 > 0 )
V_79 |= V_74 ;
F_4 ( L_92 , V_79 ) ;
return V_79 ;
}
int F_167 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
V_214 . V_210 = F_165 ( V_39 ,
V_214 . V_210 ) ;
V_39 -> V_82 . V_84 = F_166 ( V_39 ,
V_214 . V_211 ) ;
F_168 ( V_215 > 64 ) ;
F_169 ( & V_56 -> V_58 ) ;
if ( F_170 ( V_39 ) ) {
F_171 ( V_56 , V_216 ) ;
} else if ( F_24 ( V_39 ) ) {
F_171 ( V_56 , V_217 ) ;
} else if ( F_60 ( V_39 ) ) {
F_171 ( V_56 , V_218 ) ;
} else if ( F_172 ( V_39 ) ) {
F_171 ( V_56 , V_219 ) ;
} else if ( F_173 ( V_39 ) ) {
F_171 ( V_56 , V_220 ) ;
} else if ( F_81 ( V_39 ) ) {
F_171 ( V_56 , V_221 ) ;
} else if ( F_174 ( V_39 ) ) {
F_171 ( V_56 , V_222 ) ;
} else if ( F_175 ( V_39 ) ) {
F_171 ( V_56 , V_223 ) ;
} else if ( F_176 ( V_39 ) ) {
F_171 ( V_56 , V_224 ) ;
} else {
F_171 ( V_56 , V_225 ) ;
}
return 0 ;
}
void F_177 ( struct V_38 * V_39 )
{
struct V_226 * V_227 = & V_39 -> V_62 . V_61 -> V_160 ;
F_16 ( V_39 , true ) ;
if ( ! V_214 . V_210 )
F_18 ( V_39 , V_36 ) ;
if ( ! F_178 ( V_39 ) )
F_179 ( V_227 ) ;
}
static void F_180 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_41 ;
F_14 ( & V_56 -> V_58 ) ;
F_181 (dev_priv, power_well) {
V_41 -> V_43 -> V_228 ( V_39 , V_41 ) ;
V_41 -> V_45 = V_41 -> V_43 -> V_51 ( V_39 ,
V_41 ) ;
}
F_15 ( & V_56 -> V_58 ) ;
}
static void F_182 ( struct V_38 * V_39 )
{
F_31 ( V_121 , F_10 ( V_121 ) | V_123 ) ;
F_34 ( V_121 ) ;
F_127 ( 10 ) ;
if ( ! ( F_10 ( V_121 ) & V_122 ) )
F_33 ( L_93 ) ;
}
static void F_183 ( struct V_38 * V_39 )
{
F_31 ( V_121 , F_10 ( V_121 ) & ~ V_123 ) ;
F_34 ( V_121 ) ;
F_127 ( 10 ) ;
if ( F_10 ( V_121 ) & V_122 )
F_33 ( L_94 ) ;
}
static void F_184 ( struct V_38 * V_39 ,
bool V_229 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_230 ;
T_1 V_81 ;
F_43 ( V_39 , V_85 ) ;
V_81 = F_10 ( V_231 ) ;
F_31 ( V_231 , V_81 | V_232 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_3 ( V_39 , V_230 ) ;
V_230 = F_79 ( V_39 , V_97 ) ;
F_3 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
F_185 ( V_39 ) ;
F_182 ( V_39 ) ;
if ( V_229 && V_39 -> V_82 . V_130 )
F_186 ( V_39 ) ;
}
static void F_187 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_230 ;
F_43 ( V_39 , V_85 ) ;
F_183 ( V_39 ) ;
F_188 ( V_39 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_97 ) ;
F_5 ( V_39 , V_230 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_5 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
}
void F_189 ( struct V_38 * V_39 ,
bool V_229 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_230 ;
T_1 V_81 ;
F_43 ( V_39 , V_85 ) ;
V_81 = F_10 ( V_231 ) ;
V_81 &= ~ V_232 ;
F_31 ( V_231 , V_81 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_3 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
F_190 ( V_39 ) ;
F_182 ( V_39 ) ;
if ( V_229 && V_39 -> V_82 . V_130 )
F_186 ( V_39 ) ;
}
void F_191 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_230 ;
F_43 ( V_39 , V_85 ) ;
F_183 ( V_39 ) ;
F_192 ( V_39 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_5 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
}
static void F_193 ( struct V_38 * V_39 , bool V_229 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
const struct V_233 * V_234 ;
struct V_40 * V_230 ;
T_2 V_81 ;
F_43 ( V_39 , V_85 ) ;
V_81 = F_10 ( V_231 ) ;
V_81 |= V_232 ;
F_31 ( V_231 , V_81 ) ;
V_81 = F_10 ( V_235 ) ;
V_81 &= ~ V_236 ;
F_31 ( V_235 , V_81 ) ;
V_81 = F_10 ( V_237 ) ;
V_234 = & V_238 [ F_194 ( V_81 ) ] ;
F_85 ( V_234 -> V_239 == 0 ) ;
V_81 = F_10 ( V_240 ) ;
V_81 &= ~ ( ( 0xff << 16 ) | 0xff ) ;
V_81 |= V_234 -> V_241 ;
F_31 ( V_240 , V_81 ) ;
F_31 ( V_242 , V_234 -> V_243 ) ;
F_31 ( V_244 , V_234 -> V_239 ) ;
V_81 = F_10 ( V_245 ) ;
V_81 |= V_246 ;
F_31 ( V_245 , V_81 ) ;
V_81 = F_10 ( V_247 ) ;
V_81 |= V_248 ;
F_31 ( V_247 , V_81 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_3 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
F_195 ( V_39 ) ;
F_182 ( V_39 ) ;
}
static void F_196 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_230 ;
T_2 V_81 ;
F_43 ( V_39 , V_85 ) ;
F_183 ( V_39 ) ;
F_197 ( V_39 ) ;
F_14 ( & V_56 -> V_58 ) ;
V_230 = F_79 ( V_39 , V_96 ) ;
F_5 ( V_39 , V_230 ) ;
F_15 ( & V_56 -> V_58 ) ;
V_81 = F_10 ( V_235 ) ;
V_81 |= V_236 ;
F_31 ( V_235 , V_81 ) ;
}
static void F_198 ( struct V_38 * V_39 )
{
struct V_40 * V_170 =
F_79 ( V_39 , V_164 ) ;
struct V_40 * V_171 =
F_79 ( V_39 , V_172 ) ;
V_39 -> V_174 =
F_199 ( V_249 , V_178 ) |
F_199 ( V_249 , V_181 ) |
F_200 ( V_250 , V_178 , V_179 ) |
F_200 ( V_250 , V_178 , V_180 ) |
F_200 ( V_250 , V_181 , V_179 ) ;
if ( V_170 -> V_43 -> V_51 ( V_39 , V_170 ) ) {
T_1 V_251 = F_10 ( F_112 ( V_131 ) ) ;
unsigned int V_79 ;
V_79 = V_251 & V_252 ;
if ( V_79 == 0xf )
V_79 = 0x0 ;
else
V_39 -> V_174 |=
F_134 ( V_178 , V_179 ) ;
V_39 -> V_174 |=
F_135 ( V_79 , V_178 , V_179 ) ;
V_79 = ( V_251 & V_253 ) >> 4 ;
if ( V_79 == 0xf )
V_79 = 0x0 ;
else
V_39 -> V_174 |=
F_134 ( V_178 , V_180 ) ;
V_39 -> V_174 |=
F_135 ( V_79 , V_178 , V_180 ) ;
V_39 -> V_174 |= F_140 ( V_178 ) ;
V_39 -> V_177 [ V_178 ] = false ;
} else {
V_39 -> V_177 [ V_178 ] = true ;
}
if ( V_171 -> V_43 -> V_51 ( V_39 , V_171 ) ) {
T_1 V_251 = F_10 ( V_254 ) ;
unsigned int V_79 ;
V_79 = V_251 & V_255 ;
if ( V_79 == 0xf )
V_79 = 0x0 ;
else
V_39 -> V_174 |=
F_134 ( V_181 , V_179 ) ;
V_39 -> V_174 |=
F_135 ( V_79 , V_181 , V_179 ) ;
V_39 -> V_174 |= F_140 ( V_181 ) ;
V_39 -> V_177 [ V_181 ] = false ;
} else {
V_39 -> V_177 [ V_181 ] = true ;
}
F_31 ( V_195 , V_39 -> V_174 ) ;
F_4 ( L_95 ,
V_39 -> V_174 ) ;
}
static void F_201 ( struct V_38 * V_39 )
{
struct V_40 * V_256 =
F_79 ( V_39 , V_164 ) ;
struct V_40 * V_257 =
F_79 ( V_39 , V_163 ) ;
if ( V_256 -> V_43 -> V_51 ( V_39 , V_256 ) &&
V_257 -> V_43 -> V_51 ( V_39 , V_257 ) &&
F_10 ( V_165 ) & V_166 )
return;
F_4 ( L_96 ) ;
V_257 -> V_43 -> V_44 ( V_39 , V_257 ) ;
V_256 -> V_43 -> V_46 ( V_39 , V_256 ) ;
}
void F_202 ( struct V_38 * V_39 , bool V_229 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
V_56 -> V_156 = true ;
if ( F_172 ( V_39 ) ) {
F_193 ( V_39 , V_229 ) ;
} else if ( F_60 ( V_39 ) ) {
F_184 ( V_39 , V_229 ) ;
} else if ( F_41 ( V_39 ) ) {
F_189 ( V_39 , V_229 ) ;
} else if ( F_174 ( V_39 ) ) {
F_14 ( & V_56 -> V_58 ) ;
F_198 ( V_39 ) ;
F_15 ( & V_56 -> V_58 ) ;
} else if ( F_175 ( V_39 ) ) {
F_14 ( & V_56 -> V_58 ) ;
F_201 ( V_39 ) ;
F_15 ( & V_56 -> V_58 ) ;
}
F_16 ( V_39 , true ) ;
if ( ! V_214 . V_210 )
F_17 ( V_39 , V_36 ) ;
F_180 ( V_39 ) ;
V_56 -> V_156 = false ;
}
void F_203 ( struct V_38 * V_39 )
{
if ( ! V_214 . V_210 )
F_18 ( V_39 , V_36 ) ;
if ( F_172 ( V_39 ) )
F_196 ( V_39 ) ;
else if ( F_60 ( V_39 ) )
F_187 ( V_39 ) ;
else if ( F_41 ( V_39 ) )
F_191 ( V_39 ) ;
}
static void F_204 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_41 ;
F_181 (dev_priv, power_well) {
enum V_1 V_2 ;
F_61 ( L_97 ,
V_41 -> V_42 , V_41 -> V_47 ) ;
F_205 (domain, power_well->domains)
F_61 ( L_98 ,
F_1 ( V_2 ) ,
V_56 -> V_209 [ V_2 ] ) ;
}
}
void F_206 ( struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_39 -> V_56 ;
struct V_40 * V_41 ;
bool V_258 ;
F_14 ( & V_56 -> V_58 ) ;
V_258 = false ;
F_181 (dev_priv, power_well) {
enum V_1 V_2 ;
int V_259 ;
bool V_139 ;
if ( ! V_41 -> V_260 )
continue;
V_139 = V_41 -> V_43 -> V_51 ( V_39 , V_41 ) ;
if ( ( V_41 -> V_47 || V_41 -> V_54 ) != V_139 )
F_33 ( L_99 ,
V_41 -> V_42 , V_41 -> V_47 , V_139 ) ;
V_259 = 0 ;
F_205 (domain, power_well->domains)
V_259 += V_56 -> V_209 [ V_2 ] ;
if ( V_41 -> V_47 != V_259 ) {
F_33 ( L_100
L_101 ,
V_41 -> V_42 , V_41 -> V_47 ,
V_259 ) ;
V_258 = true ;
}
}
if ( V_258 ) {
static bool V_261 ;
if ( ! V_261 ) {
F_204 ( V_39 ) ;
V_261 = true ;
}
}
F_15 ( & V_56 -> V_58 ) ;
}
void F_161 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
struct V_226 * V_227 = & V_61 -> V_160 ;
int V_57 ;
V_57 = F_207 ( V_227 ) ;
F_36 ( V_57 < 0 , L_102 , V_57 ) ;
F_208 ( & V_39 -> V_52 . V_262 ) ;
F_53 ( V_39 ) ;
}
bool F_163 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
struct V_226 * V_227 = & V_61 -> V_160 ;
if ( F_209 ( V_263 ) ) {
int V_57 = F_210 ( V_227 ) ;
F_36 ( V_57 < 0 ,
L_103 , V_57 ) ;
if ( V_57 <= 0 )
return false ;
}
F_208 ( & V_39 -> V_52 . V_262 ) ;
F_53 ( V_39 ) ;
return true ;
}
void F_211 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
struct V_226 * V_227 = & V_61 -> V_160 ;
F_53 ( V_39 ) ;
F_212 ( V_227 ) ;
F_208 ( & V_39 -> V_52 . V_262 ) ;
}
void F_164 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
struct V_226 * V_227 = & V_61 -> V_160 ;
F_53 ( V_39 ) ;
F_213 ( & V_39 -> V_52 . V_262 ) ;
F_214 ( V_227 ) ;
F_215 ( V_227 ) ;
}
void F_216 ( struct V_38 * V_39 )
{
struct V_60 * V_61 = V_39 -> V_62 . V_61 ;
struct V_226 * V_227 = & V_61 -> V_160 ;
F_217 ( V_227 , 10000 ) ;
F_214 ( V_227 ) ;
if ( ! F_178 ( V_39 ) ) {
int V_57 ;
F_218 ( V_227 ) ;
V_57 = F_207 ( V_227 ) ;
F_8 ( V_57 < 0 , L_102 , V_57 ) ;
} else {
F_219 ( V_227 ) ;
}
F_215 ( V_227 ) ;
}
