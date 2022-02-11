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
static void F_23 ( struct V_31 * V_32 )
{
if ( F_21 ( V_32 ) )
F_24 ( V_32 ,
1 << V_59 | 1 << V_60 ) ;
}
static void F_25 ( struct V_31 * V_32 ,
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
static void F_26 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_61 == V_62 )
F_24 ( V_32 ,
1 << V_59 | 1 << V_60 ) ;
}
static void F_27 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
bool V_45 , V_63 ;
T_1 V_64 ;
V_64 = F_7 ( V_40 ) ;
V_45 = V_64 & V_42 ;
V_63 = V_64 & V_41 ;
if ( V_37 ) {
if ( ! V_63 )
F_28 ( V_40 ,
V_41 ) ;
if ( ! V_45 ) {
F_4 ( L_32 ) ;
if ( F_29 ( ( F_7 ( V_40 ) &
V_42 ) , 20 ) )
F_30 ( L_33 ) ;
F_16 ( V_32 ) ;
}
} else {
if ( V_63 ) {
F_23 ( V_32 ) ;
F_28 ( V_40 , 0 ) ;
F_31 ( V_40 ) ;
F_4 ( L_34 ) ;
}
}
}
static void F_32 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
F_33 ( ! F_34 ( V_54 ) , L_35 ) ;
F_33 ( ( F_7 ( V_65 ) & V_66 ) ,
L_36 ) ;
F_33 ( F_7 ( V_65 ) & V_67 ,
L_37 ) ;
F_33 ( F_7 ( V_40 ) , L_38 ) ;
F_33 ( F_35 ( V_32 ) , L_39 ) ;
}
static void F_36 ( struct V_31 * V_32 )
{
F_33 ( F_35 ( V_32 ) , L_39 ) ;
F_33 ( ! ( F_7 ( V_65 ) & V_66 ) ,
L_40 ) ;
F_33 ( F_7 ( V_65 ) & V_67 ,
L_41 ) ;
}
static void F_37 ( struct V_31 * V_32 )
{
T_1 V_68 , V_69 ;
V_69 = V_70 ;
if ( F_34 ( V_32 ) )
V_69 |= V_71 ;
V_68 = F_7 ( V_72 ) ;
if ( ( V_68 & V_69 ) != V_69 ) {
V_68 |= V_69 ;
F_28 ( V_72 , V_68 ) ;
F_31 ( V_72 ) ;
}
}
static void F_38 ( struct V_31 * V_32 ,
T_2 V_73 )
{
int V_74 = 0 ;
int V_75 = 0 ;
T_2 V_76 ;
F_28 ( V_65 , V_73 ) ;
do {
V_76 = F_7 ( V_65 ) ;
if ( V_76 != V_73 ) {
F_28 ( V_65 , V_73 ) ;
V_74 ++ ;
V_75 = 0 ;
} else if ( V_75 ++ > 5 ) {
break;
}
} while ( V_74 < 100 );
if ( V_76 != V_73 )
F_30 ( L_42 ,
V_73 , V_76 ) ;
if ( V_74 > 1 )
F_4 ( L_43 ,
V_73 , V_74 ) ;
}
static void F_39 ( struct V_31 * V_32 , T_1 V_73 )
{
T_1 V_68 ;
T_1 V_69 ;
V_69 = V_67 ;
if ( F_34 ( V_32 ) )
V_69 |= V_66 ;
else
V_69 |= V_77 ;
F_40 ( V_73 & ~ V_69 ) ;
if ( V_78 . V_79 == 0 )
V_73 = V_80 ;
else if ( V_78 . V_79 == 1 && V_73 > V_67 )
V_73 = V_67 ;
V_68 = F_7 ( V_65 ) ;
F_4 ( L_44 ,
V_68 & V_69 , V_73 ) ;
if ( ( V_68 & V_69 ) != V_32 -> V_81 . V_82 )
F_30 ( L_45 ,
V_32 -> V_81 . V_82 , V_68 & V_69 ) ;
V_68 &= ~ V_69 ;
V_68 |= V_73 ;
F_38 ( V_32 , V_68 ) ;
V_32 -> V_81 . V_82 = V_68 & V_69 ;
}
void F_41 ( struct V_31 * V_32 )
{
F_32 ( V_32 ) ;
F_4 ( L_46 ) ;
F_39 ( V_32 , V_66 ) ;
}
void F_42 ( struct V_31 * V_32 )
{
F_36 ( V_32 ) ;
F_4 ( L_47 ) ;
F_39 ( V_32 , V_80 ) ;
}
static void F_43 ( struct V_31 * V_32 )
{
F_44 ( ! F_7 ( F_45 ( 0 ) ) ,
L_48 ) ;
F_44 ( ! F_7 ( V_83 ) , L_49 ) ;
F_44 ( ! F_7 ( V_84 ) , L_50 ) ;
}
static void F_46 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
bool V_85 = F_47 ( V_32 ,
V_62 ) ;
F_44 ( ! F_48 ( V_54 ) && ! F_49 ( V_54 ) ,
L_51 ) ;
F_44 ( ! F_50 ( V_54 ) , L_52 ) ;
F_44 ( V_85 , L_53 ) ;
F_44 ( ( F_7 ( V_65 ) & V_67 ) ,
L_54 ) ;
F_51 ( V_32 ) ;
F_43 ( V_32 ) ;
}
static void F_52 ( struct V_31 * V_32 )
{
if ( V_32 -> V_44 . V_86 )
return;
F_51 ( V_32 ) ;
}
static void F_53 ( struct V_31 * V_32 )
{
F_46 ( V_32 ) ;
F_4 ( L_55 ) ;
F_39 ( V_32 , V_67 ) ;
}
static void F_54 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
F_44 ( ! F_48 ( V_54 ) && ! F_49 ( V_54 ) ,
L_56 ) ;
F_44 ( ! F_50 ( V_54 ) , L_52 ) ;
F_44 ( F_7 ( V_87 ) & V_88 ,
L_57 ) ;
F_44 ( ( F_7 ( V_65 ) & V_77 ) ,
L_58 ) ;
F_43 ( V_32 ) ;
}
static void F_55 ( struct V_31 * V_32 )
{
if ( V_32 -> V_44 . V_86 )
return;
F_44 ( ! ( F_7 ( V_65 ) & V_77 ) ,
L_59 ) ;
}
static void F_56 ( struct V_31 * V_32 )
{
F_52 ( V_32 ) ;
if ( ( F_48 ( V_32 ) || F_49 ( V_32 ) ) &&
V_78 . V_79 != 0 && V_78 . V_79 != 1 )
F_55 ( V_32 ) ;
F_39 ( V_32 , V_80 ) ;
}
void F_57 ( struct V_31 * V_32 )
{
F_54 ( V_32 ) ;
F_4 ( L_60 ) ;
F_39 ( V_32 , V_77 ) ;
}
void F_58 ( struct V_31 * V_32 )
{
F_55 ( V_32 ) ;
F_4 ( L_61 ) ;
F_39 ( V_32 , V_80 ) ;
}
static void F_59 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
T_1 V_64 , V_89 ;
T_1 V_90 , V_91 ;
bool V_45 , V_63 , V_92 = false ;
V_64 = F_7 ( V_40 ) ;
V_89 = F_7 ( V_93 ) ;
switch ( V_34 -> V_61 ) {
case V_94 :
if ( F_29 ( ( F_7 ( V_93 ) &
V_95 ) , 1 ) ) {
F_30 ( L_62 ) ;
return;
}
break;
case V_62 :
if ( ! ( V_89 & V_96 ) ) {
F_30 ( L_63 ) ;
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
F_33 ( 1 , L_64 , V_34 -> V_61 ) ;
return;
}
V_90 = F_60 ( V_34 -> V_61 ) ;
V_63 = V_64 & V_90 ;
V_91 = F_61 ( V_34 -> V_61 ) ;
V_45 = V_64 & V_91 ;
if ( ! V_37 && V_63 )
F_26 ( V_32 , V_34 ) ;
if ( V_37 ) {
if ( ! V_63 ) {
F_33 ( ( V_64 & V_91 ) &&
! F_7 ( V_102 ) ,
L_65 ) ;
F_28 ( V_40 , V_64 | V_90 ) ;
}
if ( ! V_45 ) {
F_4 ( L_66 , V_34 -> V_35 ) ;
if ( F_29 ( ( F_7 ( V_40 ) &
V_91 ) , 1 ) )
F_30 ( L_67 ,
V_34 -> V_35 ) ;
V_92 = true ;
}
} else {
if ( V_63 ) {
F_28 ( V_40 , V_64 & ~ V_90 ) ;
F_31 ( V_40 ) ;
F_4 ( L_68 , V_34 -> V_35 ) ;
}
}
if ( V_92 ) {
if ( V_34 -> V_61 == V_94 ) {
if ( F_29 ( ( F_7 ( V_93 ) &
V_96 ) , 1 ) )
F_30 ( L_69 ) ;
} else if ( V_34 -> V_61 == V_62 ) {
if ( F_29 ( ( F_7 ( V_93 ) &
V_103 ) , 1 ) )
F_30 ( L_70 ) ;
}
}
if ( V_37 && ! V_45 )
F_25 ( V_32 , V_34 ) ;
}
static void F_62 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_27 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
if ( F_7 ( V_102 ) & V_41 )
F_28 ( V_102 , 0 ) ;
}
static void F_63 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_27 ( V_32 , V_34 , true ) ;
}
static void F_64 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_27 ( V_32 , V_34 , false ) ;
}
static bool F_65 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
T_1 V_69 = F_60 ( V_34 -> V_61 ) |
F_61 ( V_34 -> V_61 ) ;
return ( F_7 ( V_40 ) & V_69 ) == V_69 ;
}
static void F_66 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_59 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
F_28 ( V_102 , 0 ) ;
}
static void F_67 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_59 ( V_32 , V_34 , true ) ;
}
static void F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_59 ( V_32 , V_34 , false ) ;
}
static bool F_69 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return ( F_7 ( V_65 ) & V_105 ) == 0 ;
}
static void F_70 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_56 ( V_32 ) ;
}
static void F_71 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( ( F_48 ( V_32 ) || F_49 ( V_32 ) ) &&
V_78 . V_79 != 0 && V_78 . V_79 != 1 )
F_57 ( V_32 ) ;
else
F_53 ( V_32 ) ;
}
static void F_72 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_104 > 0 ) {
F_39 ( V_32 , V_80 ) ;
} else {
if ( ( F_48 ( V_32 ) || F_49 ( V_32 ) ) &&
V_78 . V_79 != 0 &&
V_78 . V_79 != 1 )
F_39 ( V_32 , V_77 ) ;
else
F_39 ( V_32 , V_67 ) ;
}
}
static void F_73 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
}
static bool F_74 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return true ;
}
static void F_75 ( struct V_31 * V_32 ,
struct V_33 * V_34 , bool V_37 )
{
enum V_106 V_107 = V_34 -> V_61 ;
T_2 V_69 ;
T_2 V_73 ;
T_2 V_108 ;
V_69 = F_76 ( V_107 ) ;
V_73 = V_37 ? F_77 ( V_107 ) :
F_78 ( V_107 ) ;
F_11 ( & V_32 -> V_109 . V_110 ) ;
#define F_79 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_79 )
goto V_111;
V_108 = F_80 ( V_32 , V_112 ) ;
V_108 &= ~ V_69 ;
V_108 |= V_73 ;
F_81 ( V_32 , V_112 , V_108 ) ;
if ( F_29 ( F_79 , 100 ) )
F_30 ( L_71 ,
V_73 ,
F_80 ( V_32 , V_112 ) ) ;
#undef F_79
V_111:
F_12 ( & V_32 -> V_109 . V_110 ) ;
}
static void F_82 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_75 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
}
static void F_83 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_75 ( V_32 , V_34 , true ) ;
}
static void F_84 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_75 ( V_32 , V_34 , false ) ;
}
static bool F_85 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_107 = V_34 -> V_61 ;
bool V_113 = false ;
T_2 V_69 ;
T_2 V_73 ;
T_2 V_108 ;
V_69 = F_76 ( V_107 ) ;
V_108 = F_77 ( V_107 ) ;
F_11 ( & V_32 -> V_109 . V_110 ) ;
V_73 = F_80 ( V_32 , V_114 ) & V_69 ;
F_86 ( V_73 != F_77 ( V_107 ) &&
V_73 != F_78 ( V_107 ) ) ;
if ( V_73 == V_108 )
V_113 = true ;
V_108 = F_80 ( V_32 , V_112 ) & V_69 ;
F_86 ( V_108 != V_73 ) ;
F_12 ( & V_32 -> V_109 . V_110 ) ;
return V_113 ;
}
static void F_87 ( struct V_31 * V_32 )
{
enum V_115 V_115 ;
F_88 (dev_priv->dev, pipe) {
T_2 V_68 = F_7 ( F_89 ( V_115 ) ) ;
V_68 |= V_116 | V_117 ;
if ( V_115 != V_118 )
V_68 |= V_119 ;
F_28 ( F_89 ( V_115 ) , V_68 ) ;
}
F_90 ( & V_32 -> V_120 ) ;
F_91 ( V_32 ) ;
F_92 ( & V_32 -> V_120 ) ;
if ( V_32 -> V_44 . V_86 )
return;
F_93 ( V_32 ) ;
F_94 ( V_32 -> V_54 ) ;
}
static void F_95 ( struct V_31 * V_32 )
{
F_90 ( & V_32 -> V_120 ) ;
F_96 ( V_32 ) ;
F_92 ( & V_32 -> V_120 ) ;
F_97 ( V_32 -> V_54 -> V_121 ) ;
F_98 ( V_32 ) ;
}
static void F_99 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_122 ) ;
F_75 ( V_32 , V_34 , true ) ;
F_87 ( V_32 ) ;
}
static void F_100 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_122 ) ;
F_95 ( V_32 ) ;
F_75 ( V_32 , V_34 , false ) ;
}
static void F_101 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_123 ) ;
F_102 ( 1 ) ;
F_75 ( V_32 , V_34 , true ) ;
F_28 ( V_124 , F_7 ( V_124 ) | V_125 ) ;
}
static void F_103 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_115 V_115 ;
F_40 ( V_34 -> V_61 != V_123 ) ;
F_88 (dev_priv, pipe)
F_104 ( V_32 , V_115 ) ;
F_28 ( V_124 , F_7 ( V_124 ) & ~ V_125 ) ;
F_75 ( V_32 , V_34 , false ) ;
}
static struct V_33 * F_105 ( struct V_31 * V_32 ,
int V_107 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_126 ; V_46 ++ ) {
struct V_33 * V_34 ;
V_34 = & V_44 -> V_127 [ V_46 ] ;
if ( V_34 -> V_61 == V_107 )
return V_34 ;
}
return NULL ;
}
static void F_106 ( struct V_31 * V_32 )
{
struct V_33 * V_128 =
F_105 ( V_32 , V_123 ) ;
struct V_33 * V_129 =
F_105 ( V_32 , V_130 ) ;
T_2 V_131 = V_32 -> V_132 ;
T_2 V_133 = 0 ;
T_2 V_134 = 0xffffffff ;
T_2 V_64 ;
if ( ! V_32 -> V_135 [ V_136 ] )
V_134 &= ~ ( F_107 ( V_136 , V_137 ) |
F_108 ( V_136 , V_137 , 0 ) |
F_108 ( V_136 , V_137 , 1 ) |
F_107 ( V_136 , V_138 ) |
F_108 ( V_136 , V_138 , 0 ) |
F_108 ( V_136 , V_138 , 1 ) ) ;
if ( ! V_32 -> V_135 [ V_139 ] )
V_134 &= ~ ( F_107 ( V_139 , V_137 ) |
F_108 ( V_139 , V_137 , 0 ) |
F_108 ( V_139 , V_137 , 1 ) ) ;
if ( V_128 -> V_36 -> V_45 ( V_32 , V_128 ) ) {
V_133 |= F_109 ( V_136 ) ;
if ( ( V_131 & F_110 ( V_136 , V_137 ) ) == 0 )
V_131 |= F_111 ( 0xf , V_136 , V_137 ) ;
if ( ( V_131 & F_110 ( V_136 , V_138 ) ) == 0 )
V_131 |= F_111 ( 0xf , V_136 , V_138 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xf , V_136 , V_137 ) |
F_111 ( 0xf , V_136 , V_138 ) ) )
V_133 |= F_107 ( V_136 , V_137 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xf , V_136 , V_138 ) ) &&
( F_7 ( F_89 ( V_60 ) ) & V_140 ) == 0 )
V_133 |= F_107 ( V_136 , V_138 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0x3 , V_136 , V_137 ) ) )
V_133 |= F_108 ( V_136 , V_137 , 0 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xc , V_136 , V_137 ) ) )
V_133 |= F_108 ( V_136 , V_137 , 1 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0x3 , V_136 , V_138 ) ) )
V_133 |= F_108 ( V_136 , V_138 , 0 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xc , V_136 , V_138 ) ) )
V_133 |= F_108 ( V_136 , V_138 , 1 ) ;
}
if ( V_129 -> V_36 -> V_45 ( V_32 , V_129 ) ) {
V_133 |= F_109 ( V_139 ) ;
if ( ( V_131 & F_110 ( V_139 , V_137 ) ) == 0 )
V_131 |= F_111 ( 0xf , V_139 , V_137 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xf , V_139 , V_137 ) ) )
V_133 |= F_107 ( V_139 , V_137 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0x3 , V_139 , V_137 ) ) )
V_133 |= F_108 ( V_139 , V_137 , 0 ) ;
if ( F_112 ( V_131 ,
F_111 ( 0xc , V_139 , V_137 ) ) )
V_133 |= F_108 ( V_139 , V_137 , 1 ) ;
}
V_133 &= V_134 ;
if ( F_29 ( ( V_64 = F_7 ( V_141 ) & V_134 ) == V_133 , 10 ) )
F_33 ( V_133 != V_64 ,
L_72 ,
V_64 , V_133 , V_32 -> V_132 ) ;
}
static void F_113 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_142 V_143 ;
enum V_115 V_115 ;
T_1 V_64 ;
F_40 ( V_34 -> V_61 != V_123 &&
V_34 -> V_61 != V_130 ) ;
if ( V_34 -> V_61 == V_123 ) {
V_115 = V_118 ;
V_143 = V_136 ;
} else {
V_115 = V_59 ;
V_143 = V_139 ;
}
F_102 ( 1 ) ;
F_75 ( V_32 , V_34 , true ) ;
if ( F_29 ( F_7 ( V_141 ) & F_109 ( V_143 ) , 1 ) )
F_30 ( L_73 , V_143 ) ;
F_11 ( & V_32 -> V_144 ) ;
V_64 = F_114 ( V_32 , V_115 , V_145 ) ;
V_64 |= V_146 | V_147 |
V_148 ;
F_115 ( V_32 , V_115 , V_145 , V_64 ) ;
if ( V_34 -> V_61 == V_123 ) {
V_64 = F_114 ( V_32 , V_115 , V_149 ) ;
V_64 |= V_150 ;
F_115 ( V_32 , V_115 , V_149 , V_64 ) ;
} else {
V_64 = F_114 ( V_32 , V_115 , V_151 ) ;
V_64 |= V_152 ;
F_115 ( V_32 , V_115 , V_151 , V_64 ) ;
}
F_12 ( & V_32 -> V_144 ) ;
V_32 -> V_132 |= F_116 ( V_143 ) ;
F_28 ( V_153 , V_32 -> V_132 ) ;
F_4 ( L_74 ,
V_143 , V_32 -> V_132 ) ;
F_106 ( V_32 ) ;
}
static void F_117 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_142 V_143 ;
F_40 ( V_34 -> V_61 != V_123 &&
V_34 -> V_61 != V_130 ) ;
if ( V_34 -> V_61 == V_123 ) {
V_143 = V_136 ;
F_104 ( V_32 , V_118 ) ;
F_104 ( V_32 , V_60 ) ;
} else {
V_143 = V_139 ;
F_104 ( V_32 , V_59 ) ;
}
V_32 -> V_132 &= ~ F_116 ( V_143 ) ;
F_28 ( V_153 , V_32 -> V_132 ) ;
F_75 ( V_32 , V_34 , false ) ;
F_4 ( L_75 ,
V_143 , V_32 -> V_132 ) ;
V_32 -> V_135 [ V_143 ] = true ;
F_106 ( V_32 ) ;
}
static void F_118 ( struct V_31 * V_32 , enum V_142 V_143 ,
enum V_154 V_155 , bool V_156 , unsigned int V_69 )
{
enum V_115 V_115 = V_143 == V_136 ? V_118 : V_59 ;
T_2 V_157 , V_68 , V_158 , V_159 ;
if ( ! V_32 -> V_135 [ V_143 ] )
return;
if ( V_155 == V_137 )
V_157 = V_160 ;
else
V_157 = V_149 ;
F_11 ( & V_32 -> V_144 ) ;
V_68 = F_114 ( V_32 , V_115 , V_157 ) ;
F_12 ( & V_32 -> V_144 ) ;
if ( ! V_156 || V_69 == 0xf ) {
V_158 = V_161 | V_162 ;
if ( V_155 == V_138 && V_68 == 0 )
V_158 = 0 ;
} else if ( V_69 != 0x0 ) {
V_158 = V_162 ;
} else {
V_158 = 0 ;
}
if ( V_155 == V_137 )
V_159 = V_68 >> V_163 ;
else
V_159 = V_68 >> V_164 ;
V_159 &= V_161 | V_162 ;
F_33 ( V_159 != V_158 ,
L_76 ,
! ! ( V_159 & V_161 ) , ! ! ( V_159 & V_162 ) ,
! ! ( V_158 & V_161 ) , ! ! ( V_158 & V_162 ) ,
V_157 , V_68 ) ;
}
bool F_119 ( struct V_31 * V_32 , enum V_142 V_143 ,
enum V_154 V_155 , bool V_156 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
bool V_165 ;
F_11 ( & V_44 -> V_51 ) ;
V_165 = V_32 -> V_132 & F_110 ( V_143 , V_155 ) ;
if ( V_156 == V_165 )
goto V_111;
if ( V_156 )
V_32 -> V_132 |= F_110 ( V_143 , V_155 ) ;
else
V_32 -> V_132 &= ~ F_110 ( V_143 , V_155 ) ;
F_28 ( V_153 , V_32 -> V_132 ) ;
F_4 ( L_77 ,
V_143 , V_155 , V_32 -> V_132 ) ;
F_106 ( V_32 ) ;
V_111:
F_12 ( & V_44 -> V_51 ) ;
return V_165 ;
}
void F_120 ( struct V_166 * V_167 ,
bool V_156 , unsigned int V_69 )
{
struct V_31 * V_32 = F_121 ( V_167 -> V_168 . V_54 ) ;
struct V_43 * V_44 = & V_32 -> V_44 ;
enum V_142 V_143 = F_122 ( F_123 ( & V_167 -> V_168 ) ) ;
enum V_154 V_155 = F_124 ( F_123 ( & V_167 -> V_168 ) ) ;
F_11 ( & V_44 -> V_51 ) ;
V_32 -> V_132 &= ~ F_111 ( 0xf , V_143 , V_155 ) ;
V_32 -> V_132 |= F_111 ( V_69 , V_143 , V_155 ) ;
if ( V_156 )
V_32 -> V_132 |= F_110 ( V_143 , V_155 ) ;
else
V_32 -> V_132 &= ~ F_110 ( V_143 , V_155 ) ;
F_28 ( V_153 , V_32 -> V_132 ) ;
F_4 ( L_78 ,
V_143 , V_155 , V_69 , V_32 -> V_132 ) ;
F_106 ( V_32 ) ;
F_118 ( V_32 , V_143 , V_155 , V_156 , V_69 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
static bool F_125 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
enum V_115 V_115 = V_34 -> V_61 ;
bool V_113 ;
T_2 V_73 , V_108 ;
F_11 ( & V_32 -> V_109 . V_110 ) ;
V_73 = F_80 ( V_32 , V_169 ) & F_126 ( V_115 ) ;
F_86 ( V_73 != F_127 ( V_115 ) && V_73 != F_128 ( V_115 ) ) ;
V_113 = V_73 == F_127 ( V_115 ) ;
V_108 = F_80 ( V_32 , V_169 ) & F_129 ( V_115 ) ;
F_86 ( V_108 << 16 != V_73 ) ;
F_12 ( & V_32 -> V_109 . V_110 ) ;
return V_113 ;
}
static void F_130 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
bool V_37 )
{
enum V_115 V_115 = V_34 -> V_61 ;
T_2 V_73 ;
T_2 V_108 ;
V_73 = V_37 ? F_127 ( V_115 ) : F_128 ( V_115 ) ;
F_11 ( & V_32 -> V_109 . V_110 ) ;
#define F_79 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_79 )
goto V_111;
V_108 = F_80 ( V_32 , V_169 ) ;
V_108 &= ~ F_129 ( V_115 ) ;
V_108 |= V_37 ? F_131 ( V_115 ) : F_132 ( V_115 ) ;
F_81 ( V_32 , V_169 , V_108 ) ;
if ( F_29 ( F_79 , 100 ) )
F_30 ( L_71 ,
V_73 ,
F_80 ( V_32 , V_169 ) ) ;
#undef F_79
V_111:
F_12 ( & V_32 -> V_109 . V_110 ) ;
}
static void F_133 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_118 ) ;
F_130 ( V_32 , V_34 , V_34 -> V_104 > 0 ) ;
}
static void F_134 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_118 ) ;
F_130 ( V_32 , V_34 , true ) ;
F_87 ( V_32 ) ;
}
static void F_135 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_40 ( V_34 -> V_61 != V_118 ) ;
F_95 ( V_32 ) ;
F_130 ( V_32 , V_34 , false ) ;
}
static void
F_136 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
struct V_33 * V_34 ;
int V_46 ;
F_137 (i, power_well, BIT(domain), power_domains) {
if ( ! V_34 -> V_104 ++ )
F_3 ( V_32 , V_34 ) ;
}
V_44 -> V_170 [ V_2 ] ++ ;
}
void F_14 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
F_138 ( V_32 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_136 ( V_32 , V_2 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
bool F_139 ( struct V_31 * V_32 ,
enum V_1 V_2 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
bool V_45 ;
if ( ! F_140 ( V_32 ) )
return false ;
F_11 ( & V_44 -> V_51 ) ;
if ( F_8 ( V_32 , V_2 ) ) {
F_136 ( V_32 , V_2 ) ;
V_45 = true ;
} else {
V_45 = false ;
}
F_12 ( & V_44 -> V_51 ) ;
if ( ! V_45 )
F_141 ( V_32 ) ;
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
F_33 ( ! V_44 -> V_170 [ V_2 ] ,
L_79 ,
F_1 ( V_2 ) ) ;
V_44 -> V_170 [ V_2 ] -- ;
F_9 (i, power_well, BIT(domain), power_domains) {
F_33 ( ! V_34 -> V_104 ,
L_80 ,
V_34 -> V_35 ) ;
if ( ! -- V_34 -> V_104 )
F_5 ( V_32 , V_34 ) ;
}
F_12 ( & V_44 -> V_51 ) ;
F_141 ( V_32 ) ;
}
bool F_47 ( struct V_31 * V_32 ,
int V_107 )
{
struct V_33 * V_34 ;
bool V_50 ;
V_34 = F_105 ( V_32 , V_107 ) ;
V_50 = V_34 -> V_36 -> V_45 ( V_32 , V_34 ) ;
return V_50 ;
}
void F_142 ( struct V_31 * V_32 )
{
struct V_33 * V_171 ;
if ( ! ( F_48 ( V_32 ) || F_49 ( V_32 ) ) )
return;
V_171 = F_105 ( V_32 , V_94 ) ;
F_3 ( V_32 , V_171 ) ;
V_171 = F_105 ( V_32 , V_101 ) ;
F_3 ( V_32 , V_171 ) ;
}
void F_143 ( struct V_31 * V_32 )
{
struct V_33 * V_171 ;
if ( ! ( F_48 ( V_32 ) || F_49 ( V_32 ) ) )
return;
V_171 = F_105 ( V_32 , V_94 ) ;
F_5 ( V_32 , V_171 ) ;
V_171 = F_105 ( V_32 , V_101 ) ;
F_5 ( V_32 , V_171 ) ;
}
static int
F_144 ( const struct V_31 * V_32 ,
int V_172 )
{
if ( V_172 >= 0 )
return ! ! V_172 ;
if ( F_34 ( V_32 ) ) {
F_4 ( L_81 ) ;
return 0 ;
}
return 1 ;
}
int F_145 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
V_78 . V_172 = F_144 ( V_32 ,
V_78 . V_172 ) ;
F_146 ( V_173 > 31 ) ;
F_147 ( & V_44 -> V_51 ) ;
if ( F_148 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_174 ) ;
} else if ( F_21 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_175 ) ;
} else if ( F_48 ( V_32 -> V_54 ) || F_49 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_176 ) ;
} else if ( F_34 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_177 ) ;
} else if ( F_150 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_178 ) ;
} else if ( F_151 ( V_32 -> V_54 ) ) {
F_149 ( V_44 , V_179 ) ;
} else {
F_149 ( V_44 , V_180 ) ;
}
return 0 ;
}
void F_152 ( struct V_31 * V_32 )
{
struct V_181 * V_181 = & V_32 -> V_54 -> V_55 -> V_54 ;
F_13 ( V_32 , true ) ;
if ( ! V_78 . V_172 )
F_15 ( V_32 , V_29 ) ;
if ( ! F_50 ( V_32 ) )
F_153 ( V_181 ) ;
}
static void F_154 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
struct V_33 * V_34 ;
int V_46 ;
F_11 ( & V_44 -> V_51 ) ;
F_137 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_34 -> V_36 -> V_182 ( V_32 , V_34 ) ;
V_34 -> V_38 = V_34 -> V_36 -> V_45 ( V_32 ,
V_34 ) ;
}
F_12 ( & V_44 -> V_51 ) ;
}
static void F_155 ( struct V_31 * V_32 ,
bool V_183 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
T_1 V_68 ;
F_39 ( V_32 , V_80 ) ;
V_68 = F_7 ( V_184 ) ;
F_28 ( V_184 , V_68 | V_185 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_142 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
if ( ! V_183 )
return;
F_156 ( V_32 ) ;
if ( V_32 -> V_81 . V_186 && F_157 ( V_32 ) )
F_37 ( V_32 ) ;
}
static void F_158 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = & V_32 -> V_44 ;
F_39 ( V_32 , V_80 ) ;
F_159 ( V_32 ) ;
F_11 ( & V_44 -> V_51 ) ;
F_143 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
static void F_160 ( struct V_31 * V_32 )
{
struct V_33 * V_128 =
F_105 ( V_32 , V_123 ) ;
struct V_33 * V_129 =
F_105 ( V_32 , V_130 ) ;
V_32 -> V_132 =
F_161 ( V_187 , V_136 ) |
F_161 ( V_187 , V_139 ) |
F_162 ( V_188 , V_136 , V_137 ) |
F_162 ( V_188 , V_136 , V_138 ) |
F_162 ( V_188 , V_139 , V_137 ) ;
if ( V_128 -> V_36 -> V_45 ( V_32 , V_128 ) ) {
T_1 V_189 = F_7 ( F_89 ( V_118 ) ) ;
unsigned int V_69 ;
V_69 = V_189 & V_190 ;
if ( V_69 == 0xf )
V_69 = 0x0 ;
else
V_32 -> V_132 |=
F_110 ( V_136 , V_137 ) ;
V_32 -> V_132 |=
F_111 ( V_69 , V_136 , V_137 ) ;
V_69 = ( V_189 & V_191 ) >> 4 ;
if ( V_69 == 0xf )
V_69 = 0x0 ;
else
V_32 -> V_132 |=
F_110 ( V_136 , V_138 ) ;
V_32 -> V_132 |=
F_111 ( V_69 , V_136 , V_138 ) ;
V_32 -> V_132 |= F_116 ( V_136 ) ;
V_32 -> V_135 [ V_136 ] = false ;
} else {
V_32 -> V_135 [ V_136 ] = true ;
}
if ( V_129 -> V_36 -> V_45 ( V_32 , V_129 ) ) {
T_1 V_189 = F_7 ( V_192 ) ;
unsigned int V_69 ;
V_69 = V_189 & V_193 ;
if ( V_69 == 0xf )
V_69 = 0x0 ;
else
V_32 -> V_132 |=
F_110 ( V_139 , V_137 ) ;
V_32 -> V_132 |=
F_111 ( V_69 , V_139 , V_137 ) ;
V_32 -> V_132 |= F_116 ( V_139 ) ;
V_32 -> V_135 [ V_139 ] = false ;
} else {
V_32 -> V_135 [ V_139 ] = true ;
}
F_28 ( V_153 , V_32 -> V_132 ) ;
F_4 ( L_82 ,
V_32 -> V_132 ) ;
}
static void F_163 ( struct V_31 * V_32 )
{
struct V_33 * V_194 =
F_105 ( V_32 , V_123 ) ;
struct V_33 * V_195 =
F_105 ( V_32 , V_122 ) ;
if ( V_194 -> V_36 -> V_45 ( V_32 , V_194 ) &&
V_195 -> V_36 -> V_45 ( V_32 , V_195 ) &&
F_7 ( V_124 ) & V_125 )
return;
F_4 ( L_83 ) ;
V_195 -> V_36 -> V_37 ( V_32 , V_195 ) ;
V_194 -> V_36 -> V_39 ( V_32 , V_194 ) ;
}
void F_164 ( struct V_31 * V_32 , bool V_183 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_43 * V_44 = & V_32 -> V_44 ;
V_44 -> V_86 = true ;
if ( F_48 ( V_54 ) || F_49 ( V_54 ) ) {
F_155 ( V_32 , V_183 ) ;
} else if ( F_150 ( V_54 ) ) {
F_11 ( & V_44 -> V_51 ) ;
F_160 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
} else if ( F_151 ( V_54 ) ) {
F_11 ( & V_44 -> V_51 ) ;
F_163 ( V_32 ) ;
F_12 ( & V_44 -> V_51 ) ;
}
F_13 ( V_32 , true ) ;
if ( ! V_78 . V_172 )
F_14 ( V_32 , V_29 ) ;
F_154 ( V_32 ) ;
V_44 -> V_86 = false ;
}
void F_165 ( struct V_31 * V_32 )
{
if ( ! V_78 . V_172 )
F_15 ( V_32 , V_29 ) ;
if ( F_48 ( V_32 ) || F_49 ( V_32 ) )
F_158 ( V_32 ) ;
}
void F_138 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_181 * V_181 = & V_54 -> V_55 -> V_54 ;
F_166 ( V_181 ) ;
F_167 ( & V_32 -> V_47 . V_196 ) ;
F_51 ( V_32 ) ;
}
bool F_140 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_181 * V_181 = & V_54 -> V_55 -> V_54 ;
if ( F_168 ( V_197 ) ) {
int V_50 = F_169 ( V_181 ) ;
F_40 ( V_50 < 0 ) ;
if ( V_50 <= 0 )
return false ;
}
F_167 ( & V_32 -> V_47 . V_196 ) ;
F_51 ( V_32 ) ;
return true ;
}
void F_170 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_181 * V_181 = & V_54 -> V_55 -> V_54 ;
F_51 ( V_32 ) ;
F_171 ( V_181 ) ;
F_167 ( & V_32 -> V_47 . V_196 ) ;
}
void F_141 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_181 * V_181 = & V_54 -> V_55 -> V_54 ;
F_51 ( V_32 ) ;
if ( F_172 ( & V_32 -> V_47 . V_196 ) )
F_167 ( & V_32 -> V_47 . V_198 ) ;
F_173 ( V_181 ) ;
F_174 ( V_181 ) ;
}
void F_175 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = V_32 -> V_54 ;
struct V_181 * V_181 = & V_54 -> V_55 -> V_54 ;
F_176 ( V_181 , 10000 ) ;
F_173 ( V_181 ) ;
if ( ! F_50 ( V_54 ) ) {
F_177 ( V_181 ) ;
F_166 ( V_181 ) ;
} else {
F_178 ( V_181 ) ;
}
F_174 ( V_181 ) ;
}
