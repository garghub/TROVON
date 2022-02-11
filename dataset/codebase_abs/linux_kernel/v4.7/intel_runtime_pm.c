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
static bool F_6 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return F_7 ( V_42 ) ==
( V_43 | V_44 ) ;
}
bool F_8 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 ;
struct V_35 * V_36 ;
bool V_47 ;
int V_48 ;
if ( V_34 -> V_49 . V_50 )
return false ;
V_46 = & V_34 -> V_46 ;
V_47 = true ;
F_9 (i, power_well, BIT(domain), power_domains) {
if ( V_36 -> V_51 )
continue;
if ( ! V_36 -> V_40 ) {
V_47 = false ;
break;
}
}
return V_47 ;
}
bool F_10 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 ;
bool V_52 ;
V_46 = & V_34 -> V_46 ;
F_11 ( & V_46 -> V_53 ) ;
V_52 = F_8 ( V_34 , V_2 ) ;
F_12 ( & V_46 -> V_53 ) ;
return V_52 ;
}
void F_13 ( struct V_33 * V_34 ,
bool V_39 )
{
if ( V_34 -> V_46 . V_54 == V_39 )
return;
if ( V_39 )
F_14 ( V_34 , V_31 ) ;
else
F_15 ( V_34 , V_31 ) ;
V_34 -> V_46 . V_54 = V_39 ;
}
static void F_16 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
F_17 ( V_56 -> V_57 , V_58 ) ;
F_18 ( F_19 ( V_59 ) , V_60 ) ;
F_20 ( V_56 -> V_57 , V_58 ) ;
if ( F_21 ( V_56 ) )
F_22 ( V_34 ,
1 << V_61 | 1 << V_62 ) ;
}
static void F_23 ( struct V_33 * V_34 )
{
if ( F_21 ( V_34 ) )
F_24 ( V_34 ,
1 << V_61 | 1 << V_62 ) ;
}
static void F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
if ( V_36 -> V_63 == V_64 ) {
F_17 ( V_56 -> V_57 , V_58 ) ;
F_18 ( F_19 ( V_59 ) , V_60 ) ;
F_20 ( V_56 -> V_57 , V_58 ) ;
F_22 ( V_34 ,
1 << V_61 | 1 << V_62 ) ;
}
}
static void F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_63 == V_64 )
F_24 ( V_34 ,
1 << V_61 | 1 << V_62 ) ;
}
static void F_27 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
bool V_47 , V_65 ;
T_1 V_66 ;
V_66 = F_7 ( V_42 ) ;
V_47 = V_66 & V_44 ;
V_65 = V_66 & V_43 ;
if ( V_39 ) {
if ( ! V_65 )
F_28 ( V_42 ,
V_43 ) ;
if ( ! V_47 ) {
F_4 ( L_34 ) ;
if ( F_29 ( ( F_7 ( V_42 ) &
V_44 ) , 20 ) )
F_30 ( L_35 ) ;
F_16 ( V_34 ) ;
}
} else {
if ( V_65 ) {
F_23 ( V_34 ) ;
F_28 ( V_42 , 0 ) ;
F_31 ( V_42 ) ;
F_4 ( L_36 ) ;
}
}
}
static void F_32 ( struct V_33 * V_34 )
{
F_33 ( ( F_7 ( V_67 ) & V_68 ) ,
L_37 ) ;
F_33 ( F_7 ( V_67 ) & V_69 ,
L_38 ) ;
F_33 ( F_7 ( V_42 ) , L_39 ) ;
F_33 ( F_34 ( V_34 ) ,
L_40 ) ;
}
static void F_35 ( struct V_33 * V_34 )
{
F_33 ( F_34 ( V_34 ) ,
L_40 ) ;
F_33 ( F_7 ( V_67 ) & V_69 ,
L_41 ) ;
}
static void F_36 ( struct V_33 * V_34 ,
T_2 V_70 )
{
int V_71 = 0 ;
int V_72 = 0 ;
T_2 V_73 ;
F_28 ( V_67 , V_70 ) ;
do {
V_73 = F_7 ( V_67 ) ;
if ( V_73 != V_70 ) {
F_28 ( V_67 , V_70 ) ;
V_71 ++ ;
V_72 = 0 ;
} else if ( V_72 ++ > 5 ) {
break;
}
} while ( V_71 < 100 );
if ( V_73 != V_70 )
F_30 ( L_42 ,
V_70 , V_73 ) ;
if ( V_71 > 1 )
F_4 ( L_43 ,
V_70 , V_71 ) ;
}
static T_2 F_37 ( struct V_33 * V_34 )
{
T_2 V_74 ;
V_74 = V_69 ;
if ( F_38 ( V_34 ) )
V_74 |= V_68 ;
else
V_74 |= V_75 ;
return V_74 ;
}
void F_39 ( struct V_33 * V_34 )
{
T_2 V_76 ;
V_76 = F_7 ( V_67 ) & F_37 ( V_34 ) ;
F_4 ( L_44 ,
V_34 -> V_77 . V_78 , V_76 ) ;
V_34 -> V_77 . V_78 = V_76 ;
}
static void F_40 ( struct V_33 * V_34 , T_1 V_70 )
{
T_1 V_76 ;
T_1 V_74 ;
if ( F_41 ( V_70 & ~ V_34 -> V_77 . V_79 ) )
V_70 &= V_34 -> V_77 . V_79 ;
V_76 = F_7 ( V_67 ) ;
V_74 = F_37 ( V_34 ) ;
F_4 ( L_45 ,
V_76 & V_74 , V_70 ) ;
if ( ( V_76 & V_74 ) != V_34 -> V_77 . V_78 )
F_30 ( L_46 ,
V_34 -> V_77 . V_78 , V_76 & V_74 ) ;
V_76 &= ~ V_74 ;
V_76 |= V_70 ;
F_36 ( V_34 , V_76 ) ;
V_34 -> V_77 . V_78 = V_76 & V_74 ;
}
void F_42 ( struct V_33 * V_34 )
{
F_32 ( V_34 ) ;
F_4 ( L_47 ) ;
F_40 ( V_34 , V_68 ) ;
}
void F_43 ( struct V_33 * V_34 )
{
F_35 ( V_34 ) ;
F_4 ( L_48 ) ;
F_40 ( V_34 , V_80 ) ;
}
static void F_44 ( struct V_33 * V_34 )
{
F_33 ( ! F_7 ( F_45 ( 0 ) ) ,
L_49 ) ;
F_33 ( ! F_7 ( V_81 ) , L_50 ) ;
F_33 ( ! F_7 ( V_82 ) , L_51 ) ;
}
static void F_46 ( struct V_33 * V_34 )
{
bool V_83 = F_47 ( V_34 ,
V_64 ) ;
F_33 ( V_83 , L_52 ) ;
F_33 ( ( F_7 ( V_67 ) & V_69 ) ,
L_53 ) ;
F_48 ( V_34 ) ;
F_44 ( V_34 ) ;
}
void F_49 ( struct V_33 * V_34 )
{
F_46 ( V_34 ) ;
F_4 ( L_54 ) ;
F_40 ( V_34 , V_69 ) ;
}
static void F_50 ( struct V_33 * V_34 )
{
F_33 ( F_7 ( V_84 ) & V_85 ,
L_55 ) ;
F_33 ( ( F_7 ( V_67 ) & V_75 ) ,
L_56 ) ;
F_44 ( V_34 ) ;
}
void F_51 ( struct V_33 * V_34 )
{
F_50 ( V_34 ) ;
F_4 ( L_57 ) ;
F_40 ( V_34 , V_75 ) ;
}
void F_52 ( struct V_33 * V_34 )
{
F_4 ( L_58 ) ;
F_40 ( V_34 , V_80 ) ;
}
static void
F_53 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_86 V_87 = V_36 -> V_63 ;
T_2 V_76 ;
T_2 V_74 ;
V_74 = F_54 ( V_87 ) ;
V_76 = F_7 ( V_88 ) ;
if ( F_33 ( V_76 & V_74 , L_59 ,
V_36 -> V_37 ) )
F_28 ( V_88 , V_76 & ~ V_74 ) ;
V_76 = F_7 ( V_89 ) ;
V_76 |= F_7 ( V_90 ) ;
if ( ! ( V_76 & V_74 ) )
return;
if ( V_87 == V_91 ||
( ( F_55 ( V_34 ) || F_56 ( V_34 ) ) &&
V_87 == V_92 ) )
F_57 ( L_60
L_61 , V_36 -> V_37 ) ;
else
F_33 ( 1 , L_62 ,
V_36 -> V_37 ) ;
F_28 ( V_89 , V_76 & ~ V_74 ) ;
F_28 ( V_90 , V_76 & ~ V_74 ) ;
}
static void F_58 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
T_1 V_66 , V_93 ;
T_1 V_94 , V_95 ;
bool V_47 , V_65 , V_96 = false ;
V_66 = F_7 ( V_42 ) ;
V_93 = F_7 ( V_97 ) ;
switch ( V_36 -> V_63 ) {
case V_91 :
if ( F_29 ( ( F_7 ( V_97 ) &
V_98 ) , 1 ) ) {
F_30 ( L_63 ) ;
return;
}
break;
case V_64 :
if ( ! ( V_93 & V_99 ) ) {
F_30 ( L_64 ) ;
return;
}
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_92 :
break;
default:
F_59 ( 1 , L_65 , V_36 -> V_63 ) ;
return;
}
V_94 = F_54 ( V_36 -> V_63 ) ;
V_65 = V_66 & V_94 ;
V_95 = F_60 ( V_36 -> V_63 ) ;
V_47 = V_66 & V_95 ;
if ( ! V_39 && V_65 )
F_26 ( V_34 , V_36 ) ;
if ( V_39 ) {
if ( ! V_65 ) {
F_59 ( ( V_66 & V_95 ) &&
! F_7 ( V_89 ) ,
L_66 ) ;
F_28 ( V_42 , V_66 | V_94 ) ;
}
if ( ! V_47 ) {
F_4 ( L_67 , V_36 -> V_37 ) ;
V_96 = true ;
}
} else {
if ( V_65 ) {
F_28 ( V_42 , V_66 & ~ V_94 ) ;
F_31 ( V_42 ) ;
F_4 ( L_68 , V_36 -> V_37 ) ;
}
if ( F_61 ( V_34 ) )
F_53 ( V_34 , V_36 ) ;
}
if ( F_29 ( ! ! ( F_7 ( V_42 ) & V_95 ) == V_39 ,
1 ) )
F_30 ( L_69 ,
V_36 -> V_37 , V_39 ? L_70 : L_71 ) ;
if ( V_96 ) {
if ( V_36 -> V_63 == V_91 ) {
if ( F_29 ( ( F_7 ( V_97 ) &
V_99 ) , 1 ) )
F_30 ( L_72 ) ;
} else if ( V_36 -> V_63 == V_64 ) {
if ( F_29 ( ( F_7 ( V_97 ) &
V_104 ) , 1 ) )
F_30 ( L_73 ) ;
}
}
if ( V_39 && ! V_47 )
F_25 ( V_34 , V_36 ) ;
}
static void F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_27 ( V_34 , V_36 , V_36 -> V_105 > 0 ) ;
if ( F_7 ( V_89 ) & V_43 )
F_28 ( V_89 , 0 ) ;
}
static void F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_27 ( V_34 , V_36 , true ) ;
}
static void F_64 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_27 ( V_34 , V_36 , false ) ;
}
static bool F_65 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
T_1 V_74 = F_54 ( V_36 -> V_63 ) |
F_60 ( V_36 -> V_63 ) ;
return ( F_7 ( V_42 ) & V_74 ) == V_74 ;
}
static void F_66 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_58 ( V_34 , V_36 , V_36 -> V_105 > 0 ) ;
F_28 ( V_89 , 0 ) ;
}
static void F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_58 ( V_34 , V_36 , true ) ;
}
static void F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_58 ( V_34 , V_36 , false ) ;
}
static bool F_69 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return ( F_7 ( V_67 ) & V_106 ) == 0 ;
}
static void F_70 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_40 ( V_34 , V_80 ) ;
if ( F_38 ( V_34 ) ) {
F_71 ( V_34 ) ;
F_72 ( V_34 ) ;
}
}
static void F_73 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( ! V_34 -> V_77 . V_107 )
return;
if ( V_34 -> V_77 . V_79 & V_75 )
F_51 ( V_34 ) ;
else if ( V_34 -> V_77 . V_79 & V_69 )
F_49 ( V_34 ) ;
}
static void F_74 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_105 > 0 )
F_70 ( V_34 , V_36 ) ;
else
F_73 ( V_34 , V_36 ) ;
}
static void F_75 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
}
static bool F_76 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
return true ;
}
static void F_77 ( struct V_33 * V_34 ,
struct V_35 * V_36 , bool V_39 )
{
enum V_108 V_87 = V_36 -> V_63 ;
T_2 V_74 ;
T_2 V_70 ;
T_2 V_109 ;
V_74 = F_78 ( V_87 ) ;
V_70 = V_39 ? F_79 ( V_87 ) :
F_80 ( V_87 ) ;
F_11 ( & V_34 -> V_110 . V_111 ) ;
#define F_81 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_81 )
goto V_112;
V_109 = F_82 ( V_34 , V_113 ) ;
V_109 &= ~ V_74 ;
V_109 |= V_70 ;
F_83 ( V_34 , V_113 , V_109 ) ;
if ( F_29 ( F_81 , 100 ) )
F_30 ( L_74 ,
V_70 ,
F_82 ( V_34 , V_113 ) ) ;
#undef F_81
V_112:
F_12 ( & V_34 -> V_110 . V_111 ) ;
}
static void F_84 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_77 ( V_34 , V_36 , V_36 -> V_105 > 0 ) ;
}
static void F_85 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_77 ( V_34 , V_36 , true ) ;
}
static void F_86 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_77 ( V_34 , V_36 , false ) ;
}
static bool F_87 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_87 = V_36 -> V_63 ;
bool V_114 = false ;
T_2 V_74 ;
T_2 V_70 ;
T_2 V_109 ;
V_74 = F_78 ( V_87 ) ;
V_109 = F_79 ( V_87 ) ;
F_11 ( & V_34 -> V_110 . V_111 ) ;
V_70 = F_82 ( V_34 , V_115 ) & V_74 ;
F_88 ( V_70 != F_79 ( V_87 ) &&
V_70 != F_80 ( V_87 ) ) ;
if ( V_70 == V_109 )
V_114 = true ;
V_109 = F_82 ( V_34 , V_113 ) & V_74 ;
F_88 ( V_109 != V_70 ) ;
F_12 ( & V_34 -> V_110 . V_111 ) ;
return V_114 ;
}
static void F_89 ( struct V_33 * V_34 )
{
F_28 ( V_116 , V_117 ) ;
F_28 ( V_118 , V_119 ) ;
F_28 ( V_120 , 0 ) ;
}
static void F_90 ( struct V_33 * V_34 )
{
enum V_121 V_121 ;
F_91 (dev_priv->dev, pipe) {
T_2 V_76 = F_7 ( F_92 ( V_121 ) ) ;
V_76 |= V_122 | V_123 ;
if ( V_121 != V_124 )
V_76 |= V_125 ;
F_28 ( F_92 ( V_121 ) , V_76 ) ;
}
F_89 ( V_34 ) ;
F_93 ( & V_34 -> V_126 ) ;
F_94 ( V_34 ) ;
F_95 ( & V_34 -> V_126 ) ;
if ( V_34 -> V_46 . V_127 )
return;
F_96 ( V_34 ) ;
F_97 ( V_34 -> V_56 ) ;
}
static void F_98 ( struct V_33 * V_34 )
{
F_93 ( & V_34 -> V_126 ) ;
F_99 ( V_34 ) ;
F_95 ( & V_34 -> V_126 ) ;
F_100 ( V_34 -> V_56 -> V_128 ) ;
F_101 ( V_34 ) ;
}
static void F_102 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_129 ) ;
F_77 ( V_34 , V_36 , true ) ;
F_90 ( V_34 ) ;
}
static void F_103 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_129 ) ;
F_98 ( V_34 ) ;
F_77 ( V_34 , V_36 , false ) ;
}
static void F_104 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_130 ) ;
F_105 ( 1 ) ;
F_77 ( V_34 , V_36 , true ) ;
F_28 ( V_131 , F_7 ( V_131 ) | V_132 ) ;
}
static void F_106 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_121 V_121 ;
F_41 ( V_36 -> V_63 != V_130 ) ;
F_91 (dev_priv, pipe)
F_107 ( V_34 , V_121 ) ;
F_28 ( V_131 , F_7 ( V_131 ) & ~ V_132 ) ;
F_77 ( V_34 , V_36 , false ) ;
}
static struct V_35 * F_108 ( struct V_33 * V_34 ,
int V_87 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_46 -> V_133 ; V_48 ++ ) {
struct V_35 * V_36 ;
V_36 = & V_46 -> V_134 [ V_48 ] ;
if ( V_36 -> V_63 == V_87 )
return V_36 ;
}
return NULL ;
}
static void F_109 ( struct V_33 * V_34 )
{
struct V_35 * V_135 =
F_108 ( V_34 , V_130 ) ;
struct V_35 * V_136 =
F_108 ( V_34 , V_137 ) ;
T_2 V_138 = V_34 -> V_139 ;
T_2 V_140 = 0 ;
T_2 V_141 = 0xffffffff ;
T_2 V_66 ;
if ( ! V_34 -> V_142 [ V_143 ] )
V_141 &= ~ ( F_110 ( V_143 , V_144 ) |
F_111 ( V_143 , V_144 , 0 ) |
F_111 ( V_143 , V_144 , 1 ) |
F_110 ( V_143 , V_145 ) |
F_111 ( V_143 , V_145 , 0 ) |
F_111 ( V_143 , V_145 , 1 ) ) ;
if ( ! V_34 -> V_142 [ V_146 ] )
V_141 &= ~ ( F_110 ( V_146 , V_144 ) |
F_111 ( V_146 , V_144 , 0 ) |
F_111 ( V_146 , V_144 , 1 ) ) ;
if ( V_135 -> V_38 -> V_47 ( V_34 , V_135 ) ) {
V_140 |= F_112 ( V_143 ) ;
if ( ( V_138 & F_113 ( V_143 , V_144 ) ) == 0 )
V_138 |= F_114 ( 0xf , V_143 , V_144 ) ;
if ( ( V_138 & F_113 ( V_143 , V_145 ) ) == 0 )
V_138 |= F_114 ( 0xf , V_143 , V_145 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xf , V_143 , V_144 ) |
F_114 ( 0xf , V_143 , V_145 ) ) )
V_140 |= F_110 ( V_143 , V_144 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xf , V_143 , V_145 ) ) &&
( F_7 ( F_92 ( V_62 ) ) & V_147 ) == 0 )
V_140 |= F_110 ( V_143 , V_145 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0x3 , V_143 , V_144 ) ) )
V_140 |= F_111 ( V_143 , V_144 , 0 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xc , V_143 , V_144 ) ) )
V_140 |= F_111 ( V_143 , V_144 , 1 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0x3 , V_143 , V_145 ) ) )
V_140 |= F_111 ( V_143 , V_145 , 0 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xc , V_143 , V_145 ) ) )
V_140 |= F_111 ( V_143 , V_145 , 1 ) ;
}
if ( V_136 -> V_38 -> V_47 ( V_34 , V_136 ) ) {
V_140 |= F_112 ( V_146 ) ;
if ( ( V_138 & F_113 ( V_146 , V_144 ) ) == 0 )
V_138 |= F_114 ( 0xf , V_146 , V_144 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xf , V_146 , V_144 ) ) )
V_140 |= F_110 ( V_146 , V_144 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0x3 , V_146 , V_144 ) ) )
V_140 |= F_111 ( V_146 , V_144 , 0 ) ;
if ( F_115 ( V_138 ,
F_114 ( 0xc , V_146 , V_144 ) ) )
V_140 |= F_111 ( V_146 , V_144 , 1 ) ;
}
V_140 &= V_141 ;
if ( F_29 ( ( V_66 = F_7 ( V_148 ) & V_141 ) == V_140 , 10 ) )
F_59 ( V_140 != V_66 ,
L_75 ,
V_66 , V_140 , V_34 -> V_139 ) ;
}
static void F_116 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_149 V_150 ;
enum V_121 V_121 ;
T_1 V_66 ;
F_41 ( V_36 -> V_63 != V_130 &&
V_36 -> V_63 != V_137 ) ;
if ( V_36 -> V_63 == V_130 ) {
V_121 = V_124 ;
V_150 = V_143 ;
} else {
V_121 = V_61 ;
V_150 = V_146 ;
}
F_105 ( 1 ) ;
F_77 ( V_34 , V_36 , true ) ;
if ( F_29 ( F_7 ( V_148 ) & F_112 ( V_150 ) , 1 ) )
F_30 ( L_76 , V_150 ) ;
F_11 ( & V_34 -> V_151 ) ;
V_66 = F_117 ( V_34 , V_121 , V_152 ) ;
V_66 |= V_153 | V_154 |
V_155 ;
F_118 ( V_34 , V_121 , V_152 , V_66 ) ;
if ( V_36 -> V_63 == V_130 ) {
V_66 = F_117 ( V_34 , V_121 , V_156 ) ;
V_66 |= V_157 ;
F_118 ( V_34 , V_121 , V_156 , V_66 ) ;
} else {
V_66 = F_117 ( V_34 , V_121 , V_158 ) ;
V_66 |= V_159 ;
F_118 ( V_34 , V_121 , V_158 , V_66 ) ;
}
F_12 ( & V_34 -> V_151 ) ;
V_34 -> V_139 |= F_119 ( V_150 ) ;
F_28 ( V_160 , V_34 -> V_139 ) ;
F_4 ( L_77 ,
V_150 , V_34 -> V_139 ) ;
F_109 ( V_34 ) ;
}
static void F_120 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_149 V_150 ;
F_41 ( V_36 -> V_63 != V_130 &&
V_36 -> V_63 != V_137 ) ;
if ( V_36 -> V_63 == V_130 ) {
V_150 = V_143 ;
F_107 ( V_34 , V_124 ) ;
F_107 ( V_34 , V_62 ) ;
} else {
V_150 = V_146 ;
F_107 ( V_34 , V_61 ) ;
}
V_34 -> V_139 &= ~ F_119 ( V_150 ) ;
F_28 ( V_160 , V_34 -> V_139 ) ;
F_77 ( V_34 , V_36 , false ) ;
F_4 ( L_78 ,
V_150 , V_34 -> V_139 ) ;
V_34 -> V_142 [ V_150 ] = true ;
F_109 ( V_34 ) ;
}
static void F_121 ( struct V_33 * V_34 , enum V_149 V_150 ,
enum V_161 V_162 , bool V_163 , unsigned int V_74 )
{
enum V_121 V_121 = V_150 == V_143 ? V_124 : V_61 ;
T_2 V_164 , V_76 , V_165 , V_166 ;
if ( ! V_34 -> V_142 [ V_150 ] )
return;
if ( V_162 == V_144 )
V_164 = V_167 ;
else
V_164 = V_156 ;
F_11 ( & V_34 -> V_151 ) ;
V_76 = F_117 ( V_34 , V_121 , V_164 ) ;
F_12 ( & V_34 -> V_151 ) ;
if ( ! V_163 || V_74 == 0xf ) {
V_165 = V_168 | V_169 ;
if ( V_162 == V_145 && V_76 == 0 )
V_165 = 0 ;
} else if ( V_74 != 0x0 ) {
V_165 = V_169 ;
} else {
V_165 = 0 ;
}
if ( V_162 == V_144 )
V_166 = V_76 >> V_170 ;
else
V_166 = V_76 >> V_171 ;
V_166 &= V_168 | V_169 ;
F_59 ( V_166 != V_165 ,
L_79 ,
! ! ( V_166 & V_168 ) , ! ! ( V_166 & V_169 ) ,
! ! ( V_165 & V_168 ) , ! ! ( V_165 & V_169 ) ,
V_164 , V_76 ) ;
}
bool F_122 ( struct V_33 * V_34 , enum V_149 V_150 ,
enum V_161 V_162 , bool V_163 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
bool V_172 ;
F_11 ( & V_46 -> V_53 ) ;
V_172 = V_34 -> V_139 & F_113 ( V_150 , V_162 ) ;
if ( V_163 == V_172 )
goto V_112;
if ( V_163 )
V_34 -> V_139 |= F_113 ( V_150 , V_162 ) ;
else
V_34 -> V_139 &= ~ F_113 ( V_150 , V_162 ) ;
F_28 ( V_160 , V_34 -> V_139 ) ;
F_4 ( L_80 ,
V_150 , V_162 , V_34 -> V_139 ) ;
F_109 ( V_34 ) ;
V_112:
F_12 ( & V_46 -> V_53 ) ;
return V_172 ;
}
void F_123 ( struct V_173 * V_174 ,
bool V_163 , unsigned int V_74 )
{
struct V_33 * V_34 = F_124 ( V_174 -> V_175 . V_56 ) ;
struct V_45 * V_46 = & V_34 -> V_46 ;
enum V_149 V_150 = F_125 ( F_126 ( & V_174 -> V_175 ) ) ;
enum V_161 V_162 = F_127 ( F_126 ( & V_174 -> V_175 ) ) ;
F_11 ( & V_46 -> V_53 ) ;
V_34 -> V_139 &= ~ F_114 ( 0xf , V_150 , V_162 ) ;
V_34 -> V_139 |= F_114 ( V_74 , V_150 , V_162 ) ;
if ( V_163 )
V_34 -> V_139 |= F_113 ( V_150 , V_162 ) ;
else
V_34 -> V_139 &= ~ F_113 ( V_150 , V_162 ) ;
F_28 ( V_160 , V_34 -> V_139 ) ;
F_4 ( L_81 ,
V_150 , V_162 , V_74 , V_34 -> V_139 ) ;
F_109 ( V_34 ) ;
F_121 ( V_34 , V_150 , V_162 , V_163 , V_74 ) ;
F_12 ( & V_46 -> V_53 ) ;
}
static bool F_128 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
enum V_121 V_121 = V_36 -> V_63 ;
bool V_114 ;
T_2 V_70 , V_109 ;
F_11 ( & V_34 -> V_110 . V_111 ) ;
V_70 = F_82 ( V_34 , V_176 ) & F_129 ( V_121 ) ;
F_88 ( V_70 != F_130 ( V_121 ) && V_70 != F_131 ( V_121 ) ) ;
V_114 = V_70 == F_130 ( V_121 ) ;
V_109 = F_82 ( V_34 , V_176 ) & F_132 ( V_121 ) ;
F_88 ( V_109 << 16 != V_70 ) ;
F_12 ( & V_34 -> V_110 . V_111 ) ;
return V_114 ;
}
static void F_133 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
bool V_39 )
{
enum V_121 V_121 = V_36 -> V_63 ;
T_2 V_70 ;
T_2 V_109 ;
V_70 = V_39 ? F_130 ( V_121 ) : F_131 ( V_121 ) ;
F_11 ( & V_34 -> V_110 . V_111 ) ;
#define F_81 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_81 )
goto V_112;
V_109 = F_82 ( V_34 , V_176 ) ;
V_109 &= ~ F_132 ( V_121 ) ;
V_109 |= V_39 ? F_134 ( V_121 ) : F_135 ( V_121 ) ;
F_83 ( V_34 , V_176 , V_109 ) ;
if ( F_29 ( F_81 , 100 ) )
F_30 ( L_74 ,
V_70 ,
F_82 ( V_34 , V_176 ) ) ;
#undef F_81
V_112:
F_12 ( & V_34 -> V_110 . V_111 ) ;
}
static void F_136 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_124 ) ;
F_133 ( V_34 , V_36 , V_36 -> V_105 > 0 ) ;
}
static void F_137 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_124 ) ;
F_133 ( V_34 , V_36 , true ) ;
F_90 ( V_34 ) ;
}
static void F_138 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_41 ( V_36 -> V_63 != V_124 ) ;
F_98 ( V_34 ) ;
F_133 ( V_34 , V_36 , false ) ;
}
static void
F_139 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_36 ;
int V_48 ;
F_140 (i, power_well, BIT(domain), power_domains) {
if ( ! V_36 -> V_105 ++ )
F_3 ( V_34 , V_36 ) ;
}
V_46 -> V_177 [ V_2 ] ++ ;
}
void F_14 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
F_141 ( V_34 ) ;
F_11 ( & V_46 -> V_53 ) ;
F_139 ( V_34 , V_2 ) ;
F_12 ( & V_46 -> V_53 ) ;
}
bool F_142 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
bool V_47 ;
if ( ! F_143 ( V_34 ) )
return false ;
F_11 ( & V_46 -> V_53 ) ;
if ( F_8 ( V_34 , V_2 ) ) {
F_139 ( V_34 , V_2 ) ;
V_47 = true ;
} else {
V_47 = false ;
}
F_12 ( & V_46 -> V_53 ) ;
if ( ! V_47 )
F_144 ( V_34 ) ;
return V_47 ;
}
void F_15 ( struct V_33 * V_34 ,
enum V_1 V_2 )
{
struct V_45 * V_46 ;
struct V_35 * V_36 ;
int V_48 ;
V_46 = & V_34 -> V_46 ;
F_11 ( & V_46 -> V_53 ) ;
F_59 ( ! V_46 -> V_177 [ V_2 ] ,
L_82 ,
F_1 ( V_2 ) ) ;
V_46 -> V_177 [ V_2 ] -- ;
F_9 (i, power_well, BIT(domain), power_domains) {
F_59 ( ! V_36 -> V_105 ,
L_83 ,
V_36 -> V_37 ) ;
if ( ! -- V_36 -> V_105 )
F_5 ( V_34 , V_36 ) ;
}
F_12 ( & V_46 -> V_53 ) ;
F_144 ( V_34 ) ;
}
bool F_47 ( struct V_33 * V_34 ,
int V_87 )
{
struct V_35 * V_36 ;
bool V_52 ;
V_36 = F_108 ( V_34 , V_87 ) ;
V_52 = V_36 -> V_38 -> V_47 ( V_34 , V_36 ) ;
return V_52 ;
}
static int
F_145 ( const struct V_33 * V_34 ,
int V_178 )
{
if ( V_178 >= 0 )
return ! ! V_178 ;
return 1 ;
}
static T_1 F_146 ( const struct V_33 * V_34 ,
int V_179 )
{
T_1 V_74 ;
int V_180 ;
int V_181 ;
if ( F_55 ( V_34 ) || F_56 ( V_34 ) ) {
V_181 = 2 ;
V_74 = 0 ;
} else if ( F_38 ( V_34 ) ) {
V_181 = 1 ;
V_74 = V_68 ;
} else {
V_181 = 0 ;
V_74 = 0 ;
}
if ( ! V_182 . V_178 )
V_181 = 0 ;
if ( V_179 >= 0 && V_179 <= V_181 ) {
V_180 = V_179 ;
} else if ( V_179 == - 1 ) {
V_180 = V_181 ;
} else if ( V_179 > V_181 && V_179 <= 2 ) {
F_4 ( L_84 ,
V_179 , V_181 ) ;
V_180 = V_181 ;
} else {
F_30 ( L_85 , V_179 ) ;
V_180 = V_181 ;
}
if ( V_180 > 1 )
V_74 |= V_75 ;
if ( V_180 > 0 )
V_74 |= V_69 ;
F_4 ( L_86 , V_74 ) ;
return V_74 ;
}
int F_147 ( struct V_33 * V_34 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
V_182 . V_178 = F_145 ( V_34 ,
V_182 . V_178 ) ;
V_34 -> V_77 . V_79 = F_146 ( V_34 ,
V_182 . V_179 ) ;
F_148 ( V_183 > 31 ) ;
F_149 ( & V_46 -> V_53 ) ;
if ( F_150 ( V_34 ) ) {
F_151 ( V_46 , V_184 ) ;
} else if ( F_21 ( V_34 ) ) {
F_151 ( V_46 , V_185 ) ;
} else if ( F_55 ( V_34 ) || F_56 ( V_34 ) ) {
F_151 ( V_46 , V_186 ) ;
} else if ( F_38 ( V_34 ) ) {
F_151 ( V_46 , V_187 ) ;
} else if ( F_152 ( V_34 ) ) {
F_151 ( V_46 , V_188 ) ;
} else if ( F_153 ( V_34 ) ) {
F_151 ( V_46 , V_189 ) ;
} else {
F_151 ( V_46 , V_190 ) ;
}
return 0 ;
}
void F_154 ( struct V_33 * V_34 )
{
struct V_191 * V_191 = & V_34 -> V_56 -> V_57 -> V_56 ;
F_13 ( V_34 , true ) ;
if ( ! V_182 . V_178 )
F_15 ( V_34 , V_31 ) ;
if ( ! F_155 ( V_34 ) )
F_156 ( V_191 ) ;
}
static void F_157 ( struct V_33 * V_34 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_36 ;
int V_48 ;
F_11 ( & V_46 -> V_53 ) ;
F_140 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_36 -> V_38 -> V_192 ( V_34 , V_36 ) ;
V_36 -> V_40 = V_36 -> V_38 -> V_47 ( V_34 ,
V_36 ) ;
}
F_12 ( & V_46 -> V_53 ) ;
}
static void F_158 ( struct V_33 * V_34 ,
bool V_193 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_194 ;
T_1 V_76 ;
F_40 ( V_34 , V_80 ) ;
V_76 = F_7 ( V_195 ) ;
F_28 ( V_195 , V_76 | V_196 ) ;
F_11 ( & V_46 -> V_53 ) ;
V_194 = F_108 ( V_34 , V_91 ) ;
F_3 ( V_34 , V_194 ) ;
V_194 = F_108 ( V_34 , V_92 ) ;
F_3 ( V_34 , V_194 ) ;
F_12 ( & V_46 -> V_53 ) ;
if ( ! V_193 )
return;
F_159 ( V_34 ) ;
if ( V_34 -> V_77 . V_107 )
F_160 ( V_34 ) ;
}
static void F_161 ( struct V_33 * V_34 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_194 ;
F_40 ( V_34 , V_80 ) ;
F_162 ( V_34 ) ;
F_11 ( & V_46 -> V_53 ) ;
V_194 = F_108 ( V_34 , V_92 ) ;
F_5 ( V_34 , V_194 ) ;
V_194 = F_108 ( V_34 , V_91 ) ;
F_5 ( V_34 , V_194 ) ;
F_12 ( & V_46 -> V_53 ) ;
}
void F_163 ( struct V_33 * V_34 ,
bool V_193 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_194 ;
T_1 V_76 ;
F_40 ( V_34 , V_80 ) ;
V_76 = F_7 ( V_195 ) ;
V_76 &= ~ V_196 ;
F_28 ( V_195 , V_76 ) ;
F_11 ( & V_46 -> V_53 ) ;
V_194 = F_108 ( V_34 , V_91 ) ;
F_3 ( V_34 , V_194 ) ;
F_12 ( & V_46 -> V_53 ) ;
F_164 ( V_34 ) ;
F_165 ( V_34 ) ;
F_71 ( V_34 ) ;
F_72 ( V_34 ) ;
if ( V_193 && V_34 -> V_77 . V_107 )
F_160 ( V_34 ) ;
}
void F_166 ( struct V_33 * V_34 )
{
struct V_45 * V_46 = & V_34 -> V_46 ;
struct V_35 * V_194 ;
F_40 ( V_34 , V_80 ) ;
F_167 ( V_34 ) ;
F_168 ( V_34 ) ;
F_11 ( & V_46 -> V_53 ) ;
V_194 = F_108 ( V_34 , V_91 ) ;
F_5 ( V_34 , V_194 ) ;
F_12 ( & V_46 -> V_53 ) ;
}
static void F_169 ( struct V_33 * V_34 )
{
struct V_35 * V_135 =
F_108 ( V_34 , V_130 ) ;
struct V_35 * V_136 =
F_108 ( V_34 , V_137 ) ;
V_34 -> V_139 =
F_170 ( V_197 , V_143 ) |
F_170 ( V_197 , V_146 ) |
F_171 ( V_198 , V_143 , V_144 ) |
F_171 ( V_198 , V_143 , V_145 ) |
F_171 ( V_198 , V_146 , V_144 ) ;
if ( V_135 -> V_38 -> V_47 ( V_34 , V_135 ) ) {
T_1 V_199 = F_7 ( F_92 ( V_124 ) ) ;
unsigned int V_74 ;
V_74 = V_199 & V_200 ;
if ( V_74 == 0xf )
V_74 = 0x0 ;
else
V_34 -> V_139 |=
F_113 ( V_143 , V_144 ) ;
V_34 -> V_139 |=
F_114 ( V_74 , V_143 , V_144 ) ;
V_74 = ( V_199 & V_201 ) >> 4 ;
if ( V_74 == 0xf )
V_74 = 0x0 ;
else
V_34 -> V_139 |=
F_113 ( V_143 , V_145 ) ;
V_34 -> V_139 |=
F_114 ( V_74 , V_143 , V_145 ) ;
V_34 -> V_139 |= F_119 ( V_143 ) ;
V_34 -> V_142 [ V_143 ] = false ;
} else {
V_34 -> V_142 [ V_143 ] = true ;
}
if ( V_136 -> V_38 -> V_47 ( V_34 , V_136 ) ) {
T_1 V_199 = F_7 ( V_202 ) ;
unsigned int V_74 ;
V_74 = V_199 & V_203 ;
if ( V_74 == 0xf )
V_74 = 0x0 ;
else
V_34 -> V_139 |=
F_113 ( V_146 , V_144 ) ;
V_34 -> V_139 |=
F_114 ( V_74 , V_146 , V_144 ) ;
V_34 -> V_139 |= F_119 ( V_146 ) ;
V_34 -> V_142 [ V_146 ] = false ;
} else {
V_34 -> V_142 [ V_146 ] = true ;
}
F_28 ( V_160 , V_34 -> V_139 ) ;
F_4 ( L_87 ,
V_34 -> V_139 ) ;
}
static void F_172 ( struct V_33 * V_34 )
{
struct V_35 * V_204 =
F_108 ( V_34 , V_130 ) ;
struct V_35 * V_205 =
F_108 ( V_34 , V_129 ) ;
if ( V_204 -> V_38 -> V_47 ( V_34 , V_204 ) &&
V_205 -> V_38 -> V_47 ( V_34 , V_205 ) &&
F_7 ( V_131 ) & V_132 )
return;
F_4 ( L_88 ) ;
V_205 -> V_38 -> V_39 ( V_34 , V_205 ) ;
V_204 -> V_38 -> V_41 ( V_34 , V_204 ) ;
}
void F_173 ( struct V_33 * V_34 , bool V_193 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_45 * V_46 = & V_34 -> V_46 ;
V_46 -> V_127 = true ;
if ( F_55 ( V_56 ) || F_56 ( V_56 ) ) {
F_158 ( V_34 , V_193 ) ;
} else if ( F_38 ( V_56 ) ) {
F_163 ( V_34 , V_193 ) ;
} else if ( F_152 ( V_56 ) ) {
F_11 ( & V_46 -> V_53 ) ;
F_169 ( V_34 ) ;
F_12 ( & V_46 -> V_53 ) ;
} else if ( F_153 ( V_56 ) ) {
F_11 ( & V_46 -> V_53 ) ;
F_172 ( V_34 ) ;
F_12 ( & V_46 -> V_53 ) ;
}
F_13 ( V_34 , true ) ;
if ( ! V_182 . V_178 )
F_14 ( V_34 , V_31 ) ;
F_157 ( V_34 ) ;
V_46 -> V_127 = false ;
}
void F_174 ( struct V_33 * V_34 )
{
if ( ! V_182 . V_178 )
F_15 ( V_34 , V_31 ) ;
if ( F_55 ( V_34 ) || F_56 ( V_34 ) )
F_161 ( V_34 ) ;
else if ( F_38 ( V_34 ) )
F_166 ( V_34 ) ;
}
void F_141 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_191 * V_191 = & V_56 -> V_57 -> V_56 ;
F_175 ( V_191 ) ;
F_176 ( & V_34 -> V_49 . V_206 ) ;
F_48 ( V_34 ) ;
}
bool F_143 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_191 * V_191 = & V_56 -> V_57 -> V_56 ;
if ( F_177 ( V_207 ) ) {
int V_52 = F_178 ( V_191 ) ;
F_41 ( V_52 < 0 ) ;
if ( V_52 <= 0 )
return false ;
}
F_176 ( & V_34 -> V_49 . V_206 ) ;
F_48 ( V_34 ) ;
return true ;
}
void F_179 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_191 * V_191 = & V_56 -> V_57 -> V_56 ;
F_48 ( V_34 ) ;
F_180 ( V_191 ) ;
F_176 ( & V_34 -> V_49 . V_206 ) ;
}
void F_144 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_191 * V_191 = & V_56 -> V_57 -> V_56 ;
F_48 ( V_34 ) ;
if ( F_181 ( & V_34 -> V_49 . V_206 ) )
F_176 ( & V_34 -> V_49 . V_208 ) ;
F_182 ( V_191 ) ;
F_183 ( V_191 ) ;
}
void F_184 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = V_34 -> V_56 ;
struct V_191 * V_191 = & V_56 -> V_57 -> V_56 ;
F_185 ( V_191 , 10000 ) ;
F_182 ( V_191 ) ;
if ( ! F_155 ( V_56 ) ) {
F_186 ( V_191 ) ;
F_175 ( V_191 ) ;
} else {
F_187 ( V_191 ) ;
}
F_183 ( V_191 ) ;
}
