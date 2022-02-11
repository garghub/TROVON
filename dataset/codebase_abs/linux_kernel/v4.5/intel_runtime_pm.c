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
default:
F_2 ( V_2 ) ;
return L_29 ;
}
}
static void F_3 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_4 ( L_30 , V_34 -> V_35 ) ;
V_34 -> V_36 -> V_37 ( V_32 , V_34 ) ;
V_34 -> V_38 = true ;
}
static void F_5 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_4 ( L_31 , V_34 -> V_35 ) ;
V_34 -> V_38 = false ;
V_34 -> V_36 -> V_39 ( V_32 , V_34 ) ;
}
static bool F_6 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return F_7 ( V_40 ) ==
( V_41 | V_42 ) ;
}
bool F_8 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 ;
struct V_33 * V_34 ;
bool V_45 ;
int V_46 ;
if ( V_32 -> V_47 . V_48 )
return false ;
V_44 = & V_32 -> V_44 ;
V_45 = true ;
F_9 (i, power_well, BIT(domain), power_domains) {
if ( V_34 -> V_49 )
continue;
if ( ! V_34 -> V_38 ) {
V_45 = false ;
break;
}
}
return V_45 ;
}
bool F_10 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 ;
bool V_50 ;
V_44 = & V_32 -> V_44 ;
F_11 ( & V_44 -> V_51 ) ;
V_50 = F_8 ( V_32 , V_2 ) ;
F_12 ( & V_44 -> V_51 ) ;
return V_50 ;
}
void F_13 ( struct V_31 * V_32 ,
bool V_37 )
{
if ( V_32 -> V_44 . V_52 == V_37 )
return;
if ( V_37 )
F_14 ( V_32 , V_29 ) ;
else
F_15 ( V_32 , V_29 ) ;
V_32 -> V_44 . V_52 = V_37 ;
}
static void F_16 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
F_17 ( V_54 -> V_55 , V_56 ) ;
F_18 ( F_19 ( V_57 ) , V_58 ) ;
F_20 ( V_54 -> V_55 , V_56 ) ;
if ( F_21 ( V_54 ) )
F_22 ( V_32 ,
1 << V_59 | 1 << V_60 ) ;
}
static void F_23 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
if ( V_34 -> V_61 == V_62 ) {
F_17 ( V_54 -> V_55 , V_56 ) ;
F_18 ( F_19 ( V_57 ) , V_58 ) ;
F_20 ( V_54 -> V_55 , V_56 ) ;
F_22 ( V_32 ,
1 << V_59 | 1 << V_60 ) ;
}
}
static void F_24 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
bool V_45 , V_63 ;
T_1 V_64 ;
V_64 = F_7 ( V_40 ) ;
V_45 = V_64 & V_42 ;
V_63 = V_64 & V_41 ;
if ( V_37 ) {
if ( ! V_63 )
F_25 ( V_40 ,
V_41 ) ;
if ( ! V_45 ) {
F_4 ( L_32 ) ;
if ( F_26 ( ( F_7 ( V_40 ) &
V_42 ) , 20 ) )
F_27 ( L_33 ) ;
F_16 ( V_32 ) ;
}
} else {
if ( V_63 ) {
F_25 ( V_40 , 0 ) ;
F_28 ( V_40 ) ;
F_4 ( L_34 ) ;
}
}
}
static void F_29 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
F_30 ( ! F_31 ( V_54 ) , L_35 ) ;
F_30 ( ( F_7 ( V_65 ) & V_66 ) ,
L_36 ) ;
F_30 ( F_7 ( V_65 ) & V_67 ,
L_37 ) ;
F_30 ( F_7 ( V_40 ) , L_38 ) ;
F_30 ( F_32 ( V_32 ) , L_39 ) ;
}
static void F_33 ( struct V_31 * V_32 )
{
F_30 ( F_32 ( V_32 ) , L_39 ) ;
F_30 ( ! ( F_7 ( V_65 ) & V_66 ) ,
L_40 ) ;
F_30 ( F_7 ( V_65 ) & V_67 ,
L_41 ) ;
}
static void F_34 (
struct V_31 * V_32 )
{
T_1 V_68 ;
V_68 = F_7 ( V_69 ) ;
if ( ! ( V_68 & V_70 ) ) {
V_68 |= V_70 ;
F_25 ( V_69 , V_68 ) ;
F_28 ( V_69 ) ;
}
}
static void F_35 ( struct V_31 * V_32 ,
T_2 V_71 )
{
int V_72 = 0 ;
int V_73 = 0 ;
T_2 V_74 ;
F_25 ( V_65 , V_71 ) ;
do {
V_74 = F_7 ( V_65 ) ;
if ( V_74 != V_71 ) {
F_25 ( V_65 , V_71 ) ;
V_72 ++ ;
V_73 = 0 ;
} else if ( V_73 ++ > 5 ) {
break;
}
} while ( V_72 < 100 );
if ( V_74 != V_71 )
F_27 ( L_42 ,
V_71 , V_74 ) ;
if ( V_72 > 1 )
F_4 ( L_43 ,
V_71 , V_72 ) ;
}
static void F_36 ( struct V_31 * V_32 , T_1 V_71 )
{
T_1 V_68 ;
T_1 V_75 ;
V_75 = V_67 ;
if ( F_31 ( V_32 ) )
V_75 |= V_66 ;
else
V_75 |= V_76 ;
F_37 ( V_71 & ~ V_75 ) ;
if ( V_77 . V_78 == 0 )
V_71 = V_79 ;
else if ( V_77 . V_78 == 1 && V_71 > V_67 )
V_71 = V_67 ;
if ( V_71 & V_80 )
F_34 ( V_32 ) ;
V_68 = F_7 ( V_65 ) ;
F_4 ( L_44 ,
V_68 & V_75 , V_71 ) ;
if ( ( V_68 & V_75 ) != V_32 -> V_81 . V_82 )
F_27 ( L_45 ,
V_32 -> V_81 . V_82 , V_68 & V_75 ) ;
V_68 &= ~ V_75 ;
V_68 |= V_71 ;
F_35 ( V_32 , V_68 ) ;
V_32 -> V_81 . V_82 = V_68 & V_75 ;
}
void F_38 ( struct V_31 * V_32 )
{
F_29 ( V_32 ) ;
F_4 ( L_46 ) ;
F_36 ( V_32 , V_66 ) ;
}
void F_39 ( struct V_31 * V_32 )
{
F_33 ( V_32 ) ;
F_4 ( L_47 ) ;
F_36 ( V_32 , V_79 ) ;
}
static void F_40 ( struct V_31 * V_32 )
{
F_41 ( ! F_7 ( F_42 ( 0 ) ) ,
L_48 ) ;
F_41 ( ! F_7 ( V_83 ) , L_49 ) ;
F_41 ( ! F_7 ( V_84 ) , L_50 ) ;
}
static void F_43 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
bool V_85 = F_44 ( V_32 ,
V_62 ) ;
F_41 ( ! F_45 ( V_54 ) , L_51 ) ;
F_41 ( ! F_46 ( V_54 ) , L_52 ) ;
F_41 ( V_85 , L_53 ) ;
F_41 ( ( F_7 ( V_65 ) & V_67 ) ,
L_54 ) ;
F_47 ( V_32 ) ;
F_40 ( V_32 ) ;
}
static void F_48 ( struct V_31 * V_32 )
{
if ( V_32 -> V_44 . V_86 )
return;
F_47 ( V_32 ) ;
}
static void F_49 ( struct V_31 * V_32 )
{
F_43 ( V_32 ) ;
F_4 ( L_55 ) ;
F_36 ( V_32 , V_67 ) ;
}
static void F_50 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
F_41 ( ! F_45 ( V_54 ) , L_56 ) ;
F_41 ( ! F_46 ( V_54 ) , L_52 ) ;
F_41 ( F_7 ( V_87 ) & V_88 ,
L_57 ) ;
F_41 ( ( F_7 ( V_65 ) & V_76 ) ,
L_58 ) ;
F_40 ( V_32 ) ;
}
static void F_51 ( struct V_31 * V_32 )
{
if ( V_32 -> V_44 . V_86 )
return;
F_41 ( ! ( F_7 ( V_65 ) & V_76 ) ,
L_59 ) ;
}
static void F_52 ( struct V_31 * V_32 )
{
F_48 ( V_32 ) ;
if ( F_45 ( V_32 ) && V_77 . V_78 != 0 && V_77 . V_78 != 1 )
F_51 ( V_32 ) ;
F_36 ( V_32 , V_79 ) ;
}
void F_53 ( struct V_31 * V_32 )
{
F_50 ( V_32 ) ;
F_4 ( L_60 ) ;
F_36 ( V_32 , V_76 ) ;
}
void F_54 ( struct V_31 * V_32 )
{
F_51 ( V_32 ) ;
F_4 ( L_61 ) ;
F_36 ( V_32 , V_79 ) ;
}
static void F_55 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
T_1 V_64 , V_89 ;
T_1 V_90 , V_91 ;
bool V_45 , V_63 , V_92 = false ;
V_64 = F_7 ( V_40 ) ;
V_89 = F_7 ( V_93 ) ;
switch ( V_34 -> V_61 ) {
case V_94 :
if ( F_26 ( ( F_7 ( V_93 ) &
V_95 ) , 1 ) ) {
F_27 ( L_62 ) ;
return;
}
break;
case V_62 :
if ( ! ( V_89 & V_96 ) ) {
F_27 ( L_63 ) ;
return;
}
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
break;
default:
F_30 ( 1 , L_64 , V_34 -> V_61 ) ;
return;
}
V_90 = F_56 ( V_34 -> V_61 ) ;
V_63 = V_64 & V_90 ;
V_91 = F_57 ( V_34 -> V_61 ) ;
V_45 = V_64 & V_91 ;
if ( V_37 ) {
if ( ! V_63 ) {
F_30 ( ( V_64 & V_91 ) &&
! F_7 ( V_102 ) ,
L_65 ) ;
if ( V_34 -> V_61 == V_62 ) {
if ( ! V_32 -> V_44 . V_86 )
F_58 ( V_54 ) ;
}
F_25 ( V_40 , V_64 | V_90 ) ;
}
if ( ! V_45 ) {
F_4 ( L_66 , V_34 -> V_35 ) ;
if ( F_26 ( ( F_7 ( V_40 ) &
V_91 ) , 1 ) )
F_27 ( L_67 ,
V_34 -> V_35 ) ;
V_92 = true ;
}
} else {
if ( V_63 ) {
F_25 ( V_40 , V_64 & ~ V_90 ) ;
F_28 ( V_40 ) ;
F_4 ( L_68 , V_34 -> V_35 ) ;
}
}
if ( V_92 ) {
if ( V_34 -> V_61 == V_94 ) {
if ( F_26 ( ( F_7 ( V_93 ) &
V_96 ) , 1 ) )
F_27 ( L_69 ) ;
} else if ( V_34 -> V_61 == V_62 ) {
if ( F_26 ( ( F_7 ( V_93 ) &
V_103 ) , 1 ) )
F_27 ( L_70 ) ;
}
}
if ( V_37 && ! V_45 )
F_23 ( V_32 , V_34 ) ;
}
static void F_59 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_24 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
if ( F_7 ( V_102 ) & V_41 )
F_25 ( V_102 , 0 ) ;
}
static void F_60 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_24 ( V_32 , V_34 , true ) ;
}
static void F_61 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_24 ( V_32 , V_34 , false ) ;
}
static bool F_62 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
T_1 V_75 = F_56 ( V_34 -> V_61 ) |
F_57 ( V_34 -> V_61 ) ;
return ( F_7 ( V_40 ) & V_75 ) == V_75 ;
}
static void F_63 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_55 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
F_25 ( V_102 , 0 ) ;
}
static void F_64 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_55 ( V_32 , V_34 , true ) ;
}
static void F_65 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_55 ( V_32 , V_34 , false ) ;
}
static bool F_66 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return ( F_7 ( V_65 ) & V_80 ) == 0 ;
}
static void F_67 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_52 ( V_32 ) ;
}
static void F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( F_45 ( V_32 ) && V_77 . V_78 != 0 && V_77 . V_78 != 1 )
F_53 ( V_32 ) ;
else
F_49 ( V_32 ) ;
}
static void F_69 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_104 > 0 ) {
F_36 ( V_32 , V_79 ) ;
} else {
if ( F_45 ( V_32 ) && V_77 . V_78 != 0 &&
V_77 . V_78 != 1 )
F_36 ( V_32 , V_76 ) ;
else
F_36 ( V_32 , V_67 ) ;
}
}
static void F_70 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
}
static bool F_71 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return true ;
}
static void F_72 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
enum V_105 V_106 = V_34 -> V_61 ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_107 ;
V_75 = F_73 ( V_106 ) ;
V_71 = V_37 ? F_74 ( V_106 ) :
F_75 ( V_106 ) ;
F_11 ( & V_32 -> V_108 . V_109 ) ;
#define F_76 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_76 )
goto V_110;
V_107 = F_77 ( V_32 , V_111 ) ;
V_107 &= ~ V_75 ;
V_107 |= V_71 ;
F_78 ( V_32 , V_111 , V_107 ) ;
if ( F_26 ( F_76 , 100 ) )
F_27 ( L_71 ,
V_71 ,
F_77 ( V_32 , V_111 ) ) ;
#undef F_76
V_110:
F_12 ( & V_32 -> V_108 . V_109 ) ;
}
static void F_79 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_72 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
}
static void F_80 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_72 ( V_32 , V_34 , true ) ;
}
static void F_81 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_72 ( V_32 , V_34 , false ) ;
}
static bool F_82 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_106 = V_34 -> V_61 ;
bool V_112 = false ;
T_2 V_75 ;
T_2 V_71 ;
T_2 V_107 ;
V_75 = F_73 ( V_106 ) ;
V_107 = F_74 ( V_106 ) ;
F_11 ( & V_32 -> V_108 . V_109 ) ;
V_71 = F_77 ( V_32 , V_113 ) & V_75 ;
F_83 ( V_71 != F_74 ( V_106 ) &&
V_71 != F_75 ( V_106 ) ) ;
if ( V_71 == V_107 )
V_112 = true ;
V_107 = F_77 ( V_32 , V_111 ) & V_75 ;
F_83 ( V_107 != V_71 ) ;
F_12 ( & V_32 -> V_108 . V_109 ) ;
return V_112 ;
}
static void F_84 ( struct V_31 * V_32 )
{
enum V_114 V_114 ;
F_85 (dev_priv->dev, pipe) {
T_2 V_68 = F_7 ( F_86 ( V_114 ) ) ;
V_68 |= V_115 | V_116 ;
if ( V_114 != V_117 )
V_68 |= V_118 ;
F_25 ( F_86 ( V_114 ) , V_68 ) ;
}
F_87 ( & V_32 -> V_119 ) ;
F_88 ( V_32 ) ;
F_89 ( & V_32 -> V_119 ) ;
if ( V_32 -> V_44 . V_86 )
return;
F_90 ( V_32 ) ;
F_91 ( V_32 -> V_54 ) ;
}
static void F_92 ( struct V_31 * V_32 )
{
F_87 ( & V_32 -> V_119 ) ;
F_93 ( V_32 ) ;
F_89 ( & V_32 -> V_119 ) ;
F_94 ( V_32 ) ;
}
static void F_95 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_120 ) ;
F_72 ( V_32 , V_34 , true ) ;
F_84 ( V_32 ) ;
}
static void F_96 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_120 ) ;
F_92 ( V_32 ) ;
F_72 ( V_32 , V_34 , false ) ;
}
static void F_97 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_121 ) ;
F_98 ( 1 ) ;
F_72 ( V_32 , V_34 , true ) ;
F_25 ( V_122 , F_7 ( V_122 ) | V_123 ) ;
}
static void F_99 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_114 V_114 ;
F_37 ( V_34 -> V_61 != V_121 ) ;
F_85 (dev_priv, pipe)
F_100 ( V_32 , V_114 ) ;
F_25 ( V_122 , F_7 ( V_122 ) & ~ V_123 ) ;
F_72 ( V_32 , V_34 , false ) ;
}
static struct V_33 * F_101 ( struct V_31 * V_32 ,
int V_106 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_124 ; V_46 ++ ) {
struct V_33 * V_34 ;
V_34 = & V_44 -> V_125 [ V_46 ] ;
if ( V_34 -> V_61 == V_106 )
return V_34 ;
}
return NULL ;
}
static void F_102 ( struct V_31 * V_32 )
{
struct V_33 * V_126 =
F_101 ( V_32 , V_121 ) ;
struct V_33 * V_127 =
F_101 ( V_32 , V_128 ) ;
T_2 V_129 = V_32 -> V_130 ;
T_2 V_131 = 0 ;
T_2 V_132 = 0xffffffff ;
T_2 V_64 ;
if ( ! V_32 -> V_133 [ V_134 ] )
V_132 &= ~ ( F_103 ( V_134 , V_135 ) |
F_104 ( V_134 , V_135 , 0 ) |
F_104 ( V_134 , V_135 , 1 ) |
F_103 ( V_134 , V_136 ) |
F_104 ( V_134 , V_136 , 0 ) |
F_104 ( V_134 , V_136 , 1 ) ) ;
if ( ! V_32 -> V_133 [ V_137 ] )
V_132 &= ~ ( F_103 ( V_137 , V_135 ) |
F_104 ( V_137 , V_135 , 0 ) |
F_104 ( V_137 , V_135 , 1 ) ) ;
if ( V_126 -> V_36 -> V_45 ( V_32 , V_126 ) ) {
V_131 |= F_105 ( V_134 ) ;
if ( ( V_129 & F_106 ( V_134 , V_135 ) ) == 0 )
V_129 |= F_107 ( 0xf , V_134 , V_135 ) ;
if ( ( V_129 & F_106 ( V_134 , V_136 ) ) == 0 )
V_129 |= F_107 ( 0xf , V_134 , V_136 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xf , V_134 , V_135 ) |
F_107 ( 0xf , V_134 , V_136 ) ) )
V_131 |= F_103 ( V_134 , V_135 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xf , V_134 , V_136 ) ) &&
( F_7 ( F_86 ( V_60 ) ) & V_138 ) == 0 )
V_131 |= F_103 ( V_134 , V_136 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0x3 , V_134 , V_135 ) ) )
V_131 |= F_104 ( V_134 , V_135 , 0 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xc , V_134 , V_135 ) ) )
V_131 |= F_104 ( V_134 , V_135 , 1 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0x3 , V_134 , V_136 ) ) )
V_131 |= F_104 ( V_134 , V_136 , 0 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xc , V_134 , V_136 ) ) )
V_131 |= F_104 ( V_134 , V_136 , 1 ) ;
}
if ( V_127 -> V_36 -> V_45 ( V_32 , V_127 ) ) {
V_131 |= F_105 ( V_137 ) ;
if ( ( V_129 & F_106 ( V_137 , V_135 ) ) == 0 )
V_129 |= F_107 ( 0xf , V_137 , V_135 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xf , V_137 , V_135 ) ) )
V_131 |= F_103 ( V_137 , V_135 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0x3 , V_137 , V_135 ) ) )
V_131 |= F_104 ( V_137 , V_135 , 0 ) ;
if ( F_108 ( V_129 ,
F_107 ( 0xc , V_137 , V_135 ) ) )
V_131 |= F_104 ( V_137 , V_135 , 1 ) ;
}
V_131 &= V_132 ;
if ( F_26 ( ( V_64 = F_7 ( V_139 ) & V_132 ) == V_131 , 10 ) )
F_30 ( V_131 != V_64 ,
L_72 ,
V_64 , V_131 , V_32 -> V_130 ) ;
}
static void F_109 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_140 V_141 ;
enum V_114 V_114 ;
T_1 V_64 ;
F_37 ( V_34 -> V_61 != V_121 &&
V_34 -> V_61 != V_128 ) ;
if ( V_34 -> V_61 == V_121 ) {
V_114 = V_117 ;
V_141 = V_134 ;
} else {
V_114 = V_59 ;
V_141 = V_137 ;
}
F_98 ( 1 ) ;
F_72 ( V_32 , V_34 , true ) ;
if ( F_26 ( F_7 ( V_139 ) & F_105 ( V_141 ) , 1 ) )
F_27 ( L_73 , V_141 ) ;
F_11 ( & V_32 -> V_142 ) ;
V_64 = F_110 ( V_32 , V_114 , V_143 ) ;
V_64 |= V_144 | V_145 |
V_146 ;
F_111 ( V_32 , V_114 , V_143 , V_64 ) ;
if ( V_34 -> V_61 == V_121 ) {
V_64 = F_110 ( V_32 , V_114 , V_147 ) ;
V_64 |= V_148 ;
F_111 ( V_32 , V_114 , V_147 , V_64 ) ;
} else {
V_64 = F_110 ( V_32 , V_114 , V_149 ) ;
V_64 |= V_150 ;
F_111 ( V_32 , V_114 , V_149 , V_64 ) ;
}
F_12 ( & V_32 -> V_142 ) ;
V_32 -> V_130 |= F_112 ( V_141 ) ;
F_25 ( V_151 , V_32 -> V_130 ) ;
F_4 ( L_74 ,
V_141 , V_32 -> V_130 ) ;
F_102 ( V_32 ) ;
}
static void F_113 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_140 V_141 ;
F_37 ( V_34 -> V_61 != V_121 &&
V_34 -> V_61 != V_128 ) ;
if ( V_34 -> V_61 == V_121 ) {
V_141 = V_134 ;
F_100 ( V_32 , V_117 ) ;
F_100 ( V_32 , V_60 ) ;
} else {
V_141 = V_137 ;
F_100 ( V_32 , V_59 ) ;
}
V_32 -> V_130 &= ~ F_112 ( V_141 ) ;
F_25 ( V_151 , V_32 -> V_130 ) ;
F_72 ( V_32 , V_34 , false ) ;
F_4 ( L_75 ,
V_141 , V_32 -> V_130 ) ;
V_32 -> V_133 [ V_141 ] = true ;
F_102 ( V_32 ) ;
}
static void F_114 ( struct V_31 * V_32 , enum V_140 V_141 ,
enum V_152 V_153 , bool V_154 , unsigned int V_75 )
{
enum V_114 V_114 = V_141 == V_134 ? V_117 : V_59 ;
T_2 V_155 , V_68 , V_156 , V_157 ;
if ( ! V_32 -> V_133 [ V_141 ] )
return;
if ( V_153 == V_135 )
V_155 = V_158 ;
else
V_155 = V_147 ;
F_11 ( & V_32 -> V_142 ) ;
V_68 = F_110 ( V_32 , V_114 , V_155 ) ;
F_12 ( & V_32 -> V_142 ) ;
if ( ! V_154 || V_75 == 0xf ) {
V_156 = V_159 | V_160 ;
if ( V_153 == V_136 && V_68 == 0 )
V_156 = 0 ;
} else if ( V_75 != 0x0 ) {
V_156 = V_160 ;
} else {
V_156 = 0 ;
}
if ( V_153 == V_135 )
V_157 = V_68 >> V_161 ;
else
V_157 = V_68 >> V_162 ;
V_157 &= V_159 | V_160 ;
F_30 ( V_157 != V_156 ,
L_76 ,
! ! ( V_157 & V_159 ) , ! ! ( V_157 & V_160 ) ,
! ! ( V_156 & V_159 ) , ! ! ( V_156 & V_160 ) ,
V_155 , V_68 ) ;
}
bool F_115 ( struct V_31 * V_32 , enum V_140 V_141 ,
enum V_152 V_153 , bool V_154 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
bool V_163 ;
F_11 ( & V_44 -> V_51 ) ;
V_163 = V_32 -> V_130 & F_106 ( V_141 , V_153 ) ;
if ( V_154 == V_163 )
goto V_110;
if ( V_154 )
V_32 -> V_130 |= F_106 ( V_141 , V_153 ) ;
else
V_32 -> V_130 &= ~ F_106 ( V_141 , V_153 ) ;
F_25 ( V_151 , V_32 -> V_130 ) ;
F_4 ( L_77 ,
V_141 , V_153 , V_32 -> V_130 ) ;
F_102 ( V_32 ) ;
V_110:
F_12 ( & V_44 -> V_51 ) ;
return V_163 ;
}
void F_116 ( struct V_164 * V_165 ,
bool V_154 , unsigned int V_75 )
{
struct V_31 * V_32 = F_117 ( V_165 -> V_166 . V_54 ) ;
struct V_43 * V_44 = & V_32 -> V_44 ;
enum V_140 V_141 = F_118 ( F_119 ( & V_165 -> V_166 ) ) ;
enum V_152 V_153 = F_120 ( F_119 ( & V_165 -> V_166 ) ) ;
F_11 ( & V_44 -> V_51 ) ;
V_32 -> V_130 &= ~ F_107 ( 0xf , V_141 , V_153 ) ;
V_32 -> V_130 |= F_107 ( V_75 , V_141 , V_153 ) ;
if ( V_154 )
V_32 -> V_130 |= F_106 ( V_141 , V_153 ) ;
else
V_32 -> V_130 &= ~ F_106 ( V_141 , V_153 ) ;
F_25 ( V_151 , V_32 -> V_130 ) ;
F_4 ( L_78 ,
V_141 , V_153 , V_75 , V_32 -> V_130 ) ;
F_102 ( V_32 ) ;
F_114 ( V_32 , V_141 , V_153 , V_154 , V_75 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
static bool F_121 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_114 V_114 = V_34 -> V_61 ;
bool V_112 ;
T_2 V_71 , V_107 ;
F_11 ( & V_32 -> V_108 . V_109 ) ;
V_71 = F_77 ( V_32 , V_167 ) & F_122 ( V_114 ) ;
F_83 ( V_71 != F_123 ( V_114 ) && V_71 != F_124 ( V_114 ) ) ;
V_112 = V_71 == F_123 ( V_114 ) ;
V_107 = F_77 ( V_32 , V_167 ) & F_125 ( V_114 ) ;
F_83 ( V_107 << 16 != V_71 ) ;
F_12 ( & V_32 -> V_108 . V_109 ) ;
return V_112 ;
}
static void F_126 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
bool V_37 )
{
enum V_114 V_114 = V_34 -> V_61 ;
T_2 V_71 ;
T_2 V_107 ;
V_71 = V_37 ? F_123 ( V_114 ) : F_124 ( V_114 ) ;
F_11 ( & V_32 -> V_108 . V_109 ) ;
#define F_76 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_76 )
goto V_110;
V_107 = F_77 ( V_32 , V_167 ) ;
V_107 &= ~ F_125 ( V_114 ) ;
V_107 |= V_37 ? F_127 ( V_114 ) : F_128 ( V_114 ) ;
F_78 ( V_32 , V_167 , V_107 ) ;
if ( F_26 ( F_76 , 100 ) )
F_27 ( L_71 ,
V_71 ,
F_77 ( V_32 , V_167 ) ) ;
#undef F_76
V_110:
F_12 ( & V_32 -> V_108 . V_109 ) ;
}
static void F_129 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_117 ) ;
F_126 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
}
static void F_130 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_117 ) ;
F_126 ( V_32 , V_34 , true ) ;
F_84 ( V_32 ) ;
}
static void F_131 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_37 ( V_34 -> V_61 != V_117 ) ;
F_92 ( V_32 ) ;
F_126 ( V_32 , V_34 , false ) ;
}
static void
F_132 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
struct V_33 * V_34 ;
int V_46 ;
F_133 (i, power_well, BIT(domain), power_domains) {
if ( ! V_34 -> V_104 ++ )
F_3 ( V_32 , V_34 ) ;
}
V_44 -> V_168 [ V_2 ] ++ ;
}
void F_14 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
F_134 ( V_32 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_132 ( V_32 , V_2 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
bool F_135 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
bool V_45 ;
if ( ! F_136 ( V_32 ) )
return false ;
F_11 ( & V_44 -> V_51 ) ;
if ( F_8 ( V_32 , V_2 ) ) {
F_132 ( V_32 , V_2 ) ;
V_45 = true ;
} else {
V_45 = false ;
}
F_12 ( & V_44 -> V_51 ) ;
if ( ! V_45 )
F_137 ( V_32 ) ;
return V_45 ;
}
void F_15 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 ;
struct V_33 * V_34 ;
int V_46 ;
V_44 = & V_32 -> V_44 ;
F_11 ( & V_44 -> V_51 ) ;
F_30 ( ! V_44 -> V_168 [ V_2 ] ,
L_79 ,
F_1 ( V_2 ) ) ;
V_44 -> V_168 [ V_2 ] -- ;
F_9 (i, power_well, BIT(domain), power_domains) {
F_30 ( ! V_34 -> V_104 ,
L_80 ,
V_34 -> V_35 ) ;
if ( ! -- V_34 -> V_104 )
F_5 ( V_32 , V_34 ) ;
}
F_12 ( & V_44 -> V_51 ) ;
F_137 ( V_32 ) ;
}
bool F_44 ( struct V_31 * V_32 ,
int V_106 )
{
struct V_33 * V_34 ;
bool V_50 ;
V_34 = F_101 ( V_32 , V_106 ) ;
V_50 = V_34 -> V_36 -> V_45 ( V_32 , V_34 ) ;
return V_50 ;
}
void F_138 ( struct V_31 * V_32 )
{
struct V_33 * V_169 ;
if ( ! F_45 ( V_32 ) )
return;
V_169 = F_101 ( V_32 , V_94 ) ;
F_3 ( V_32 , V_169 ) ;
V_169 = F_101 ( V_32 , V_101 ) ;
F_3 ( V_32 , V_169 ) ;
}
void F_139 ( struct V_31 * V_32 )
{
struct V_33 * V_169 ;
if ( ! F_45 ( V_32 ) )
return;
V_169 = F_101 ( V_32 , V_94 ) ;
F_5 ( V_32 , V_169 ) ;
V_169 = F_101 ( V_32 , V_101 ) ;
F_5 ( V_32 , V_169 ) ;
}
static int
F_140 ( const struct V_31 * V_32 ,
int V_170 )
{
if ( V_170 >= 0 )
return ! ! V_170 ;
if ( F_31 ( V_32 ) ) {
F_4 ( L_81 ) ;
return 0 ;
}
return 1 ;
}
int F_141 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
V_77 . V_170 = F_140 ( V_32 ,
V_77 . V_170 ) ;
F_142 ( V_171 > 31 ) ;
F_143 ( & V_44 -> V_51 ) ;
if ( F_144 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_172 ) ;
} else if ( F_21 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_173 ) ;
} else if ( F_45 ( V_32 -> V_54 ) || F_146 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_174 ) ;
} else if ( F_31 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_175 ) ;
} else if ( F_147 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_176 ) ;
} else if ( F_148 ( V_32 -> V_54 ) ) {
F_145 ( V_44 , V_177 ) ;
} else {
F_145 ( V_44 , V_178 ) ;
}
return 0 ;
}
void F_149 ( struct V_31 * V_32 )
{
struct V_179 * V_179 = & V_32 -> V_54 -> V_55 -> V_54 ;
F_13 ( V_32 , true ) ;
if ( ! V_77 . V_170 )
F_15 ( V_32 , V_29 ) ;
if ( ! F_46 ( V_32 ) )
F_150 ( V_179 ) ;
}
static void F_151 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
struct V_33 * V_34 ;
int V_46 ;
F_11 ( & V_44 -> V_51 ) ;
F_133 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_34 -> V_36 -> V_180 ( V_32 , V_34 ) ;
V_34 -> V_38 = V_34 -> V_36 -> V_45 ( V_32 ,
V_34 ) ;
}
F_12 ( & V_44 -> V_51 ) ;
}
static void F_152 ( struct V_31 * V_32 ,
bool V_181 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
T_1 V_68 ;
F_36 ( V_32 , V_79 ) ;
V_68 = F_7 ( V_182 ) ;
F_25 ( V_182 , V_68 | V_183 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_138 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
if ( ! V_181 )
return;
F_153 ( V_32 ) ;
if ( V_32 -> V_81 . V_184 )
F_154 ( V_32 ) ;
}
static void F_155 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
F_36 ( V_32 , V_79 ) ;
F_156 ( V_32 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_139 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
static void F_157 ( struct V_31 * V_32 )
{
struct V_33 * V_126 =
F_101 ( V_32 , V_121 ) ;
struct V_33 * V_127 =
F_101 ( V_32 , V_128 ) ;
V_32 -> V_130 =
F_158 ( V_185 , V_134 ) |
F_158 ( V_185 , V_137 ) |
F_159 ( V_186 , V_134 , V_135 ) |
F_159 ( V_186 , V_134 , V_136 ) |
F_159 ( V_186 , V_137 , V_135 ) ;
if ( V_126 -> V_36 -> V_45 ( V_32 , V_126 ) ) {
T_1 V_187 = F_7 ( F_86 ( V_117 ) ) ;
unsigned int V_75 ;
V_75 = V_187 & V_188 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_32 -> V_130 |=
F_106 ( V_134 , V_135 ) ;
V_32 -> V_130 |=
F_107 ( V_75 , V_134 , V_135 ) ;
V_75 = ( V_187 & V_189 ) >> 4 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_32 -> V_130 |=
F_106 ( V_134 , V_136 ) ;
V_32 -> V_130 |=
F_107 ( V_75 , V_134 , V_136 ) ;
V_32 -> V_130 |= F_112 ( V_134 ) ;
V_32 -> V_133 [ V_134 ] = false ;
} else {
V_32 -> V_133 [ V_134 ] = true ;
}
if ( V_127 -> V_36 -> V_45 ( V_32 , V_127 ) ) {
T_1 V_187 = F_7 ( V_190 ) ;
unsigned int V_75 ;
V_75 = V_187 & V_191 ;
if ( V_75 == 0xf )
V_75 = 0x0 ;
else
V_32 -> V_130 |=
F_106 ( V_137 , V_135 ) ;
V_32 -> V_130 |=
F_107 ( V_75 , V_137 , V_135 ) ;
V_32 -> V_130 |= F_112 ( V_137 ) ;
V_32 -> V_133 [ V_137 ] = false ;
} else {
V_32 -> V_133 [ V_137 ] = true ;
}
F_25 ( V_151 , V_32 -> V_130 ) ;
F_4 ( L_82 ,
V_32 -> V_130 ) ;
}
static void F_160 ( struct V_31 * V_32 )
{
struct V_33 * V_192 =
F_101 ( V_32 , V_121 ) ;
struct V_33 * V_193 =
F_101 ( V_32 , V_120 ) ;
if ( V_192 -> V_36 -> V_45 ( V_32 , V_192 ) &&
V_193 -> V_36 -> V_45 ( V_32 , V_193 ) &&
F_7 ( V_122 ) & V_123 )
return;
F_4 ( L_83 ) ;
V_193 -> V_36 -> V_37 ( V_32 , V_193 ) ;
V_192 -> V_36 -> V_39 ( V_32 , V_192 ) ;
}
void F_161 ( struct V_31 * V_32 , bool V_181 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_43 * V_44 = & V_32 -> V_44 ;
V_44 -> V_86 = true ;
if ( F_45 ( V_54 ) || F_146 ( V_54 ) ) {
F_152 ( V_32 , V_181 ) ;
} else if ( F_147 ( V_54 ) ) {
F_11 ( & V_44 -> V_51 ) ;
F_157 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
} else if ( F_148 ( V_54 ) ) {
F_11 ( & V_44 -> V_51 ) ;
F_160 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
F_13 ( V_32 , true ) ;
if ( ! V_77 . V_170 )
F_14 ( V_32 , V_29 ) ;
F_151 ( V_32 ) ;
V_44 -> V_86 = false ;
}
void F_162 ( struct V_31 * V_32 )
{
if ( ! V_77 . V_170 )
F_15 ( V_32 , V_29 ) ;
if ( F_45 ( V_32 ) || F_146 ( V_32 ) )
F_155 ( V_32 ) ;
}
void F_134 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_179 * V_179 = & V_54 -> V_55 -> V_54 ;
F_163 ( V_179 ) ;
F_164 ( & V_32 -> V_47 . V_194 ) ;
F_47 ( V_32 ) ;
}
bool F_136 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_179 * V_179 = & V_54 -> V_55 -> V_54 ;
if ( F_165 ( V_195 ) ) {
int V_50 = F_166 ( V_179 ) ;
F_37 ( V_50 < 0 ) ;
if ( V_50 <= 0 )
return false ;
}
F_164 ( & V_32 -> V_47 . V_194 ) ;
F_47 ( V_32 ) ;
return true ;
}
void F_167 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_179 * V_179 = & V_54 -> V_55 -> V_54 ;
F_47 ( V_32 ) ;
F_168 ( V_179 ) ;
F_164 ( & V_32 -> V_47 . V_194 ) ;
}
void F_137 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_179 * V_179 = & V_54 -> V_55 -> V_54 ;
F_47 ( V_32 ) ;
if ( F_169 ( & V_32 -> V_47 . V_194 ) )
F_164 ( & V_32 -> V_47 . V_196 ) ;
F_170 ( V_179 ) ;
F_171 ( V_179 ) ;
}
void F_172 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_179 * V_179 = & V_54 -> V_55 -> V_54 ;
F_173 ( V_179 , 10000 ) ;
F_170 ( V_179 ) ;
if ( ! F_46 ( V_54 ) ) {
F_174 ( V_179 ) ;
F_163 ( V_179 ) ;
} else {
F_175 ( V_179 ) ;
}
F_171 ( V_179 ) ;
}
