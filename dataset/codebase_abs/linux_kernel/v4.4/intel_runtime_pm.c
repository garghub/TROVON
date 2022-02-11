static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , V_4 -> V_5 ) ;
V_4 -> V_6 -> V_7 ( V_2 , V_4 ) ;
V_4 -> V_8 = true ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_2 , V_4 -> V_5 ) ;
V_4 -> V_8 = false ;
V_4 -> V_6 -> V_9 ( V_2 , V_4 ) ;
}
static bool F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_5 ( V_10 ) ==
( V_11 | V_12 ) ;
}
bool F_6 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
bool V_17 ;
int V_18 ;
if ( V_2 -> V_19 . V_20 )
return false ;
V_16 = & V_2 -> V_16 ;
V_17 = true ;
F_7 (i, power_well, BIT(domain), power_domains) {
if ( V_4 -> V_21 )
continue;
if ( ! V_4 -> V_8 ) {
V_17 = false ;
break;
}
}
return V_17 ;
}
bool F_8 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
struct V_15 * V_16 ;
bool V_22 ;
V_16 = & V_2 -> V_16 ;
F_9 ( & V_16 -> V_23 ) ;
V_22 = F_6 ( V_2 , V_14 ) ;
F_10 ( & V_16 -> V_23 ) ;
return V_22 ;
}
void F_11 ( struct V_1 * V_2 ,
bool V_7 )
{
if ( V_2 -> V_16 . V_24 == V_7 )
return;
if ( V_7 )
F_12 ( V_2 , V_25 ) ;
else
F_13 ( V_2 , V_25 ) ;
V_2 -> V_16 . V_24 = V_7 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_15 ( V_27 -> V_28 , V_29 ) ;
F_16 ( F_17 ( V_30 ) , V_31 ) ;
F_18 ( V_27 -> V_28 , V_29 ) ;
if ( F_19 ( V_27 ) )
F_20 ( V_2 ,
1 << V_32 | 1 << V_33 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_4 -> V_34 == V_35 ) {
F_15 ( V_27 -> V_28 , V_29 ) ;
F_16 ( F_17 ( V_30 ) , V_31 ) ;
F_18 ( V_27 -> V_28 , V_29 ) ;
F_20 ( V_2 ,
1 << V_32 | 1 << V_33 ) ;
}
if ( V_4 -> V_34 == V_36 ) {
if ( ! V_2 -> V_16 . V_37 )
F_22 ( V_27 ) ;
F_20 ( V_2 , 1 << V_38 ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_7 )
{
bool V_17 , V_39 ;
T_1 V_40 ;
V_40 = F_5 ( V_10 ) ;
V_17 = V_40 & V_12 ;
V_39 = V_40 & V_11 ;
if ( V_7 ) {
if ( ! V_39 )
F_24 ( V_10 ,
V_11 ) ;
if ( ! V_17 ) {
F_2 ( L_3 ) ;
if ( F_25 ( ( F_5 ( V_10 ) &
V_12 ) , 20 ) )
F_26 ( L_4 ) ;
F_14 ( V_2 ) ;
}
} else {
if ( V_39 ) {
F_24 ( V_10 , 0 ) ;
F_27 ( V_10 ) ;
F_2 ( L_5 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_29 ( ! F_30 ( V_27 ) , L_6 ) ;
F_29 ( ( F_5 ( V_41 ) & V_42 ) ,
L_7 ) ;
F_29 ( F_5 ( V_41 ) & V_43 ,
L_8 ) ;
F_29 ( F_5 ( V_10 ) , L_9 ) ;
F_29 ( F_31 ( V_2 ) , L_10 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_29 ( F_31 ( V_2 ) , L_10 ) ;
F_29 ( ! ( F_5 ( V_41 ) & V_42 ) ,
L_11 ) ;
F_29 ( F_5 ( V_41 ) & V_43 ,
L_12 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_28 ( V_2 ) ;
F_2 ( L_13 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 |= V_42 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_32 ( V_2 ) ;
F_2 ( L_14 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_42 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_35 (
struct V_1 * V_2 )
{
T_1 V_44 ;
V_44 = F_5 ( V_45 ) ;
if ( ! ( V_44 & V_46 ) ) {
V_44 |= V_46 ;
F_24 ( V_45 , V_44 ) ;
F_27 ( V_45 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
bool V_47 = F_37 ( V_2 ,
V_35 ) ;
F_38 ( ! F_39 ( V_27 ) , L_15 ) ;
F_38 ( ! F_40 ( V_27 ) , L_16 ) ;
F_38 ( V_47 , L_17 ) ;
F_38 ( ( F_5 ( V_41 ) & V_43 ) ,
L_18 ) ;
F_38 ( V_2 -> V_19 . V_20 ,
L_19 ) ;
F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
bool V_47 = F_37 ( V_2 ,
V_35 ) ;
if ( V_2 -> V_16 . V_37 )
return;
F_38 ( ! V_47 , L_20 ) ;
F_38 ( V_2 -> V_19 . V_20 ,
L_21 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_36 ( V_2 ) ;
F_2 ( L_22 ) ;
F_35 ( V_2 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_48 ;
V_44 |= V_43 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_42 ( V_2 ) ;
F_2 ( L_23 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_43 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_38 ( ! F_39 ( V_27 ) , L_24 ) ;
F_38 ( ! F_40 ( V_27 ) , L_16 ) ;
F_38 ( F_5 ( V_49 ) & V_50 ,
L_25 ) ;
F_38 ( ( F_5 ( V_41 ) & V_51 ) ,
L_26 ) ;
F_41 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_37 )
return;
F_41 ( V_2 ) ;
F_38 ( ! ( F_5 ( V_41 ) & V_51 ) ,
L_27 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_45 ( V_2 ) ;
F_2 ( L_28 ) ;
F_35 ( V_2 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_48 ;
V_44 |= V_51 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_46 ( V_2 ) ;
F_2 ( L_29 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_51 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
T_1 V_40 , V_52 ;
T_1 V_53 , V_54 ;
bool V_17 , V_39 , V_55 = false ;
V_40 = F_5 ( V_10 ) ;
V_52 = F_5 ( V_56 ) ;
switch ( V_4 -> V_34 ) {
case V_36 :
if ( F_25 ( ( F_5 ( V_56 ) &
V_57 ) , 1 ) ) {
F_26 ( L_30 ) ;
return;
}
break;
case V_35 :
if ( ! ( V_52 & V_58 ) ) {
F_26 ( L_31 ) ;
return;
}
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
break;
default:
F_29 ( 1 , L_32 , V_4 -> V_34 ) ;
return;
}
V_53 = F_50 ( V_4 -> V_34 ) ;
V_39 = V_40 & V_53 ;
V_54 = F_51 ( V_4 -> V_34 ) ;
V_17 = V_40 & V_54 ;
if ( V_7 ) {
if ( ! V_39 ) {
F_29 ( ( V_40 & V_54 ) &&
! F_5 ( V_64 ) ,
L_33 ) ;
if ( ( F_52 ( V_27 ) || F_53 ( V_27 ) ) &&
V_4 -> V_34 == V_35 ) {
if ( F_53 ( V_27 ) ) {
F_48 ( V_2 ) ;
if ( ! V_2 -> V_16 . V_37 )
F_22 ( V_27 ) ;
} else {
F_44 ( V_2 ) ;
}
}
F_24 ( V_10 , V_40 | V_53 ) ;
}
if ( ! V_17 ) {
F_2 ( L_34 , V_4 -> V_5 ) ;
if ( F_25 ( ( F_5 ( V_10 ) &
V_54 ) , 1 ) )
F_26 ( L_35 ,
V_4 -> V_5 ) ;
V_55 = true ;
}
} else {
if ( V_39 ) {
if ( F_39 ( V_27 ) &&
( V_4 -> V_34 == V_36 ) &&
( F_54 ( V_2 ) == V_65 ) )
F_2 ( L_36 ) ;
else {
F_24 ( V_10 , V_40 & ~ V_53 ) ;
F_27 ( V_10 ) ;
F_2 ( L_37 , V_4 -> V_5 ) ;
}
if ( ( F_52 ( V_27 ) || F_53 ( V_27 ) ) &&
V_4 -> V_34 == V_35 ) {
enum V_66 V_67 ;
F_25 ( ( V_67 = F_54 ( V_2 ) ) !=
V_68 , 1000 ) ;
if ( V_67 != V_65 )
F_55 ( L_38 ,
V_67 ) ;
else
if ( F_53 ( V_27 ) )
F_47 ( V_2 ) ;
else
F_43 ( V_2 ) ;
}
}
}
if ( V_55 ) {
if ( V_4 -> V_34 == V_36 ) {
if ( F_25 ( ( F_5 ( V_56 ) &
V_58 ) , 1 ) )
F_26 ( L_39 ) ;
} else if ( V_4 -> V_34 == V_35 ) {
if ( F_25 ( ( F_5 ( V_56 ) &
V_69 ) , 1 ) )
F_26 ( L_40 ) ;
}
}
if ( V_7 && ! V_17 )
F_21 ( V_2 , V_4 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
if ( F_5 ( V_64 ) & V_11 )
F_24 ( V_64 , 0 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , true ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , false ) ;
}
static bool F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_71 = F_50 ( V_4 -> V_34 ) |
F_51 ( V_4 -> V_34 ) ;
return ( F_5 ( V_10 ) & V_71 ) == V_71 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_49 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
F_24 ( V_64 , 0 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_49 ( V_2 , V_4 , true ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_49 ( V_2 , V_4 , false ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static bool F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return true ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_7 )
{
enum V_72 V_73 = V_4 -> V_34 ;
T_2 V_71 ;
T_2 V_67 ;
T_2 V_74 ;
V_71 = F_66 ( V_73 ) ;
V_67 = V_7 ? F_67 ( V_73 ) :
F_68 ( V_73 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
#define F_69 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_69 )
goto V_77;
V_74 = F_70 ( V_2 , V_78 ) ;
V_74 &= ~ V_71 ;
V_74 |= V_67 ;
F_71 ( V_2 , V_78 , V_74 ) ;
if ( F_25 ( F_69 , 100 ) )
F_26 ( L_41 ,
V_67 ,
F_70 ( V_2 , V_78 ) ) ;
#undef F_69
V_77:
F_10 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_65 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_65 ( V_2 , V_4 , true ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_65 ( V_2 , V_4 , false ) ;
}
static bool F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_73 = V_4 -> V_34 ;
bool V_79 = false ;
T_2 V_71 ;
T_2 V_67 ;
T_2 V_74 ;
V_71 = F_66 ( V_73 ) ;
V_74 = F_67 ( V_73 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
V_67 = F_70 ( V_2 , V_80 ) & V_71 ;
F_76 ( V_67 != F_67 ( V_73 ) &&
V_67 != F_68 ( V_73 ) ) ;
if ( V_67 == V_74 )
V_79 = true ;
V_74 = F_70 ( V_2 , V_78 ) & V_71 ;
F_76 ( V_74 != V_67 ) ;
F_10 ( & V_2 -> V_75 . V_76 ) ;
return V_79 ;
}
static void F_77 ( struct V_1 * V_2 )
{
enum V_81 V_81 ;
F_78 (dev_priv->dev, pipe) {
T_2 V_44 = F_5 ( F_79 ( V_81 ) ) ;
V_44 |= V_82 | V_83 ;
if ( V_81 != V_38 )
V_44 |= V_84 ;
F_24 ( F_79 ( V_81 ) , V_44 ) ;
}
F_80 ( & V_2 -> V_85 ) ;
F_81 ( V_2 ) ;
F_82 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_16 . V_37 )
return;
F_83 ( V_2 ) ;
F_84 ( V_2 -> V_27 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_80 ( & V_2 -> V_85 ) ;
F_86 ( V_2 ) ;
F_82 ( & V_2 -> V_85 ) ;
F_87 ( V_2 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_86 ) ;
F_65 ( V_2 , V_4 , true ) ;
F_77 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_86 ) ;
F_85 ( V_2 ) ;
F_65 ( V_2 , V_4 , false ) ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_87 ) ;
F_92 ( 1 ) ;
F_65 ( V_2 , V_4 , true ) ;
F_24 ( V_88 , F_5 ( V_88 ) | V_89 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_81 V_81 ;
F_89 ( V_4 -> V_34 != V_87 ) ;
F_78 (dev_priv, pipe)
F_94 ( V_2 , V_81 ) ;
F_24 ( V_88 , F_5 ( V_88 ) & ~ V_89 ) ;
F_65 ( V_2 , V_4 , false ) ;
}
static struct V_3 * F_95 ( struct V_1 * V_2 ,
int V_73 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_96 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_4 -> V_34 == V_73 )
return V_4 ;
}
return NULL ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_90 =
F_95 ( V_2 , V_87 ) ;
struct V_3 * V_91 =
F_95 ( V_2 , V_92 ) ;
T_2 V_93 = V_2 -> V_94 ;
T_2 V_95 = 0 ;
T_2 V_96 = 0xffffffff ;
T_2 V_40 ;
if ( ! V_2 -> V_97 [ V_98 ] )
V_96 &= ~ ( F_98 ( V_98 , V_99 ) |
F_99 ( V_98 , V_99 , 0 ) |
F_99 ( V_98 , V_99 , 1 ) |
F_98 ( V_98 , V_100 ) |
F_99 ( V_98 , V_100 , 0 ) |
F_99 ( V_98 , V_100 , 1 ) ) ;
if ( ! V_2 -> V_97 [ V_101 ] )
V_96 &= ~ ( F_98 ( V_101 , V_99 ) |
F_99 ( V_101 , V_99 , 0 ) |
F_99 ( V_101 , V_99 , 1 ) ) ;
if ( V_90 -> V_6 -> V_17 ( V_2 , V_90 ) ) {
V_95 |= F_100 ( V_98 ) ;
if ( ( V_93 & F_101 ( V_98 , V_99 ) ) == 0 )
V_93 |= F_102 ( 0xf , V_98 , V_99 ) ;
if ( ( V_93 & F_101 ( V_98 , V_100 ) ) == 0 )
V_93 |= F_102 ( 0xf , V_98 , V_100 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xf , V_98 , V_99 ) |
F_102 ( 0xf , V_98 , V_100 ) ) )
V_95 |= F_98 ( V_98 , V_99 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xf , V_98 , V_100 ) ) &&
( F_5 ( F_79 ( V_33 ) ) & V_102 ) == 0 )
V_95 |= F_98 ( V_98 , V_100 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0x3 , V_98 , V_99 ) ) )
V_95 |= F_99 ( V_98 , V_99 , 0 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xc , V_98 , V_99 ) ) )
V_95 |= F_99 ( V_98 , V_99 , 1 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0x3 , V_98 , V_100 ) ) )
V_95 |= F_99 ( V_98 , V_100 , 0 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xc , V_98 , V_100 ) ) )
V_95 |= F_99 ( V_98 , V_100 , 1 ) ;
}
if ( V_91 -> V_6 -> V_17 ( V_2 , V_91 ) ) {
V_95 |= F_100 ( V_101 ) ;
if ( ( V_93 & F_101 ( V_101 , V_99 ) ) == 0 )
V_93 |= F_102 ( 0xf , V_101 , V_99 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xf , V_101 , V_99 ) ) )
V_95 |= F_98 ( V_101 , V_99 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0x3 , V_101 , V_99 ) ) )
V_95 |= F_99 ( V_101 , V_99 , 0 ) ;
if ( F_103 ( V_93 ,
F_102 ( 0xc , V_101 , V_99 ) ) )
V_95 |= F_99 ( V_101 , V_99 , 1 ) ;
}
V_95 &= V_96 ;
if ( F_25 ( ( V_40 = F_5 ( V_103 ) & V_96 ) == V_95 , 10 ) )
F_29 ( V_95 != V_40 ,
L_42 ,
V_40 , V_95 , V_2 -> V_94 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_104 V_105 ;
enum V_81 V_81 ;
T_1 V_40 ;
F_89 ( V_4 -> V_34 != V_87 &&
V_4 -> V_34 != V_92 ) ;
if ( V_4 -> V_34 == V_87 ) {
V_81 = V_38 ;
V_105 = V_98 ;
} else {
V_81 = V_32 ;
V_105 = V_101 ;
}
F_92 ( 1 ) ;
F_65 ( V_2 , V_4 , true ) ;
if ( F_25 ( F_5 ( V_103 ) & F_100 ( V_105 ) , 1 ) )
F_26 ( L_43 , V_105 ) ;
F_9 ( & V_2 -> V_106 ) ;
V_40 = F_105 ( V_2 , V_81 , V_107 ) ;
V_40 |= V_108 | V_109 |
V_110 ;
F_106 ( V_2 , V_81 , V_107 , V_40 ) ;
if ( V_4 -> V_34 == V_87 ) {
V_40 = F_105 ( V_2 , V_81 , V_111 ) ;
V_40 |= V_112 ;
F_106 ( V_2 , V_81 , V_111 , V_40 ) ;
} else {
V_40 = F_105 ( V_2 , V_81 , V_113 ) ;
V_40 |= V_114 ;
F_106 ( V_2 , V_81 , V_113 , V_40 ) ;
}
F_10 ( & V_2 -> V_106 ) ;
V_2 -> V_94 |= F_107 ( V_105 ) ;
F_24 ( V_115 , V_2 -> V_94 ) ;
F_2 ( L_44 ,
V_105 , V_2 -> V_94 ) ;
F_97 ( V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_104 V_105 ;
F_89 ( V_4 -> V_34 != V_87 &&
V_4 -> V_34 != V_92 ) ;
if ( V_4 -> V_34 == V_87 ) {
V_105 = V_98 ;
F_94 ( V_2 , V_38 ) ;
F_94 ( V_2 , V_33 ) ;
} else {
V_105 = V_101 ;
F_94 ( V_2 , V_32 ) ;
}
V_2 -> V_94 &= ~ F_107 ( V_105 ) ;
F_24 ( V_115 , V_2 -> V_94 ) ;
F_65 ( V_2 , V_4 , false ) ;
F_2 ( L_45 ,
V_105 , V_2 -> V_94 ) ;
V_2 -> V_97 [ V_105 ] = true ;
F_97 ( V_2 ) ;
}
static void F_109 ( struct V_1 * V_2 , enum V_104 V_105 ,
enum V_116 V_117 , bool V_118 , unsigned int V_71 )
{
enum V_81 V_81 = V_105 == V_98 ? V_38 : V_32 ;
T_2 V_119 , V_44 , V_120 , V_121 ;
if ( ! V_2 -> V_97 [ V_105 ] )
return;
if ( V_117 == V_99 )
V_119 = V_122 ;
else
V_119 = V_111 ;
F_9 ( & V_2 -> V_106 ) ;
V_44 = F_105 ( V_2 , V_81 , V_119 ) ;
F_10 ( & V_2 -> V_106 ) ;
if ( ! V_118 || V_71 == 0xf ) {
V_120 = V_123 | V_124 ;
if ( V_117 == V_100 && V_44 == 0 )
V_120 = 0 ;
} else if ( V_71 != 0x0 ) {
V_120 = V_124 ;
} else {
V_120 = 0 ;
}
if ( V_117 == V_99 )
V_121 = V_44 >> V_125 ;
else
V_121 = V_44 >> V_126 ;
V_121 &= V_123 | V_124 ;
F_29 ( V_121 != V_120 ,
L_46 ,
! ! ( V_121 & V_123 ) , ! ! ( V_121 & V_124 ) ,
! ! ( V_120 & V_123 ) , ! ! ( V_120 & V_124 ) ,
V_119 , V_44 ) ;
}
bool F_110 ( struct V_1 * V_2 , enum V_104 V_105 ,
enum V_116 V_117 , bool V_118 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
bool V_127 ;
F_9 ( & V_16 -> V_23 ) ;
V_127 = V_2 -> V_94 & F_101 ( V_105 , V_117 ) ;
if ( V_118 == V_127 )
goto V_77;
if ( V_118 )
V_2 -> V_94 |= F_101 ( V_105 , V_117 ) ;
else
V_2 -> V_94 &= ~ F_101 ( V_105 , V_117 ) ;
F_24 ( V_115 , V_2 -> V_94 ) ;
F_2 ( L_47 ,
V_105 , V_117 , V_2 -> V_94 ) ;
F_97 ( V_2 ) ;
V_77:
F_10 ( & V_16 -> V_23 ) ;
return V_127 ;
}
void F_111 ( struct V_128 * V_129 ,
bool V_118 , unsigned int V_71 )
{
struct V_1 * V_2 = F_112 ( V_129 -> V_130 . V_27 ) ;
struct V_15 * V_16 = & V_2 -> V_16 ;
enum V_104 V_105 = F_113 ( F_114 ( & V_129 -> V_130 ) ) ;
enum V_116 V_117 = F_115 ( F_114 ( & V_129 -> V_130 ) ) ;
F_9 ( & V_16 -> V_23 ) ;
V_2 -> V_94 &= ~ F_102 ( 0xf , V_105 , V_117 ) ;
V_2 -> V_94 |= F_102 ( V_71 , V_105 , V_117 ) ;
if ( V_118 )
V_2 -> V_94 |= F_101 ( V_105 , V_117 ) ;
else
V_2 -> V_94 &= ~ F_101 ( V_105 , V_117 ) ;
F_24 ( V_115 , V_2 -> V_94 ) ;
F_2 ( L_48 ,
V_105 , V_117 , V_71 , V_2 -> V_94 ) ;
F_97 ( V_2 ) ;
F_109 ( V_2 , V_105 , V_117 , V_118 , V_71 ) ;
F_10 ( & V_16 -> V_23 ) ;
}
static bool F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_81 V_81 = V_4 -> V_34 ;
bool V_79 ;
T_2 V_67 , V_74 ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
V_67 = F_70 ( V_2 , V_131 ) & F_117 ( V_81 ) ;
F_76 ( V_67 != F_118 ( V_81 ) && V_67 != F_119 ( V_81 ) ) ;
V_79 = V_67 == F_118 ( V_81 ) ;
V_74 = F_70 ( V_2 , V_131 ) & F_120 ( V_81 ) ;
F_76 ( V_74 << 16 != V_67 ) ;
F_10 ( & V_2 -> V_75 . V_76 ) ;
return V_79 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
enum V_81 V_81 = V_4 -> V_34 ;
T_2 V_67 ;
T_2 V_74 ;
V_67 = V_7 ? F_118 ( V_81 ) : F_119 ( V_81 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
#define F_69 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_69 )
goto V_77;
V_74 = F_70 ( V_2 , V_131 ) ;
V_74 &= ~ F_120 ( V_81 ) ;
V_74 |= V_7 ? F_122 ( V_81 ) : F_123 ( V_81 ) ;
F_71 ( V_2 , V_131 , V_74 ) ;
if ( F_25 ( F_69 , 100 ) )
F_26 ( L_41 ,
V_67 ,
F_70 ( V_2 , V_131 ) ) ;
#undef F_69
V_77:
F_10 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_38 ) ;
F_121 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_38 ) ;
F_121 ( V_2 , V_4 , true ) ;
F_77 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_89 ( V_4 -> V_34 != V_38 ) ;
F_85 ( V_2 ) ;
F_121 ( V_2 , V_4 , false ) ;
}
void F_12 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_127 ( V_2 ) ;
V_16 = & V_2 -> V_16 ;
F_9 ( & V_16 -> V_23 ) ;
F_96 (i, power_well, BIT(domain), power_domains) {
if ( ! V_4 -> V_70 ++ )
F_1 ( V_2 , V_4 ) ;
}
V_16 -> V_132 [ V_14 ] ++ ;
F_10 ( & V_16 -> V_23 ) ;
}
void F_13 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_18 ;
V_16 = & V_2 -> V_16 ;
F_9 ( & V_16 -> V_23 ) ;
F_76 ( ! V_16 -> V_132 [ V_14 ] ) ;
V_16 -> V_132 [ V_14 ] -- ;
F_7 (i, power_well, BIT(domain), power_domains) {
F_76 ( ! V_4 -> V_70 ) ;
if ( ! -- V_4 -> V_70 && V_133 . V_134 )
F_3 ( V_2 , V_4 ) ;
}
F_10 ( & V_16 -> V_23 ) ;
F_128 ( V_2 ) ;
}
bool F_37 ( struct V_1 * V_2 ,
int V_73 )
{
struct V_3 * V_4 ;
bool V_22 ;
V_4 = F_95 ( V_2 , V_73 ) ;
V_22 = V_4 -> V_6 -> V_17 ( V_2 , V_4 ) ;
return V_22 ;
}
static int
F_129 ( const struct V_1 * V_2 ,
int V_134 )
{
if ( V_134 >= 0 )
return ! ! V_134 ;
if ( F_39 ( V_2 ) ) {
F_2 ( L_49 ) ;
return 0 ;
}
return 1 ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
V_133 . V_134 = F_129 ( V_2 ,
V_133 . V_134 ) ;
F_131 ( V_135 > 31 ) ;
F_132 ( & V_16 -> V_23 ) ;
if ( F_133 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_136 ) ;
} else if ( F_19 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_137 ) ;
} else if ( F_39 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_138 ) ;
} else if ( F_30 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_139 ) ;
} else if ( F_135 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_140 ) ;
} else if ( F_136 ( V_2 -> V_27 ) ) {
F_134 ( V_16 , V_141 ) ;
} else {
F_134 ( V_16 , V_142 ) ;
}
return 0 ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_143 * V_143 = & V_27 -> V_28 -> V_27 ;
if ( ! F_40 ( V_27 ) )
return;
if ( ! F_138 ( V_27 ) )
return;
F_139 ( V_143 ) ;
}
void F_140 ( struct V_1 * V_2 )
{
F_137 ( V_2 ) ;
F_11 ( V_2 , true ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_9 ( & V_16 -> V_23 ) ;
F_96 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_4 -> V_6 -> V_144 ( V_2 , V_4 ) ;
V_4 -> V_8 = V_4 -> V_6 -> V_17 ( V_2 ,
V_4 ) ;
}
F_10 ( & V_16 -> V_23 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_90 =
F_95 ( V_2 , V_87 ) ;
struct V_3 * V_91 =
F_95 ( V_2 , V_92 ) ;
V_2 -> V_94 =
F_143 ( V_145 , V_98 ) |
F_143 ( V_145 , V_101 ) |
F_144 ( V_146 , V_98 , V_99 ) |
F_144 ( V_146 , V_98 , V_100 ) |
F_144 ( V_146 , V_101 , V_99 ) ;
if ( V_90 -> V_6 -> V_17 ( V_2 , V_90 ) ) {
T_1 V_147 = F_5 ( F_79 ( V_38 ) ) ;
unsigned int V_71 ;
V_71 = V_147 & V_148 ;
if ( V_71 == 0xf )
V_71 = 0x0 ;
else
V_2 -> V_94 |=
F_101 ( V_98 , V_99 ) ;
V_2 -> V_94 |=
F_102 ( V_71 , V_98 , V_99 ) ;
V_71 = ( V_147 & V_149 ) >> 4 ;
if ( V_71 == 0xf )
V_71 = 0x0 ;
else
V_2 -> V_94 |=
F_101 ( V_98 , V_100 ) ;
V_2 -> V_94 |=
F_102 ( V_71 , V_98 , V_100 ) ;
V_2 -> V_94 |= F_107 ( V_98 ) ;
V_2 -> V_97 [ V_98 ] = false ;
} else {
V_2 -> V_97 [ V_98 ] = true ;
}
if ( V_91 -> V_6 -> V_17 ( V_2 , V_91 ) ) {
T_1 V_147 = F_5 ( V_150 ) ;
unsigned int V_71 ;
V_71 = V_147 & V_151 ;
if ( V_71 == 0xf )
V_71 = 0x0 ;
else
V_2 -> V_94 |=
F_101 ( V_101 , V_99 ) ;
V_2 -> V_94 |=
F_102 ( V_71 , V_101 , V_99 ) ;
V_2 -> V_94 |= F_107 ( V_101 ) ;
V_2 -> V_97 [ V_101 ] = false ;
} else {
V_2 -> V_97 [ V_101 ] = true ;
}
F_24 ( V_115 , V_2 -> V_94 ) ;
F_2 ( L_50 ,
V_2 -> V_94 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_3 * V_152 =
F_95 ( V_2 , V_87 ) ;
struct V_3 * V_153 =
F_95 ( V_2 , V_86 ) ;
if ( V_152 -> V_6 -> V_17 ( V_2 , V_152 ) &&
V_153 -> V_6 -> V_17 ( V_2 , V_153 ) &&
F_5 ( V_88 ) & V_89 )
return;
F_2 ( L_51 ) ;
V_153 -> V_6 -> V_7 ( V_2 , V_153 ) ;
V_152 -> V_6 -> V_9 ( V_2 , V_152 ) ;
}
void F_146 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_37 = true ;
if ( F_135 ( V_27 ) ) {
F_9 ( & V_16 -> V_23 ) ;
F_142 ( V_2 ) ;
F_10 ( & V_16 -> V_23 ) ;
} else if ( F_136 ( V_27 ) ) {
F_9 ( & V_16 -> V_23 ) ;
F_145 ( V_2 ) ;
F_10 ( & V_16 -> V_23 ) ;
}
F_11 ( V_2 , true ) ;
F_141 ( V_2 ) ;
V_16 -> V_37 = false ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_143 * V_143 = & V_27 -> V_28 -> V_27 ;
if ( ! F_40 ( V_27 ) )
return;
F_139 ( V_143 ) ;
F_29 ( V_2 -> V_19 . V_20 , L_52 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_143 * V_143 = & V_27 -> V_28 -> V_27 ;
if ( ! F_40 ( V_27 ) )
return;
F_29 ( V_2 -> V_19 . V_20 , L_53 ) ;
F_148 ( V_143 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_143 * V_143 = & V_27 -> V_28 -> V_27 ;
if ( ! F_40 ( V_27 ) )
return;
F_149 ( V_143 ) ;
F_150 ( V_143 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_143 * V_143 = & V_27 -> V_28 -> V_27 ;
if ( ! F_40 ( V_27 ) )
return;
if ( ! F_138 ( V_27 ) ) {
F_152 ( L_54 ) ;
return;
}
F_153 ( V_143 , 10000 ) ;
F_149 ( V_143 ) ;
F_154 ( V_143 ) ;
F_150 ( V_143 ) ;
}
