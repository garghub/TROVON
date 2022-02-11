static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( V_5 ) ==
( V_6 | V_7 ) ;
}
bool F_3 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
bool V_12 ;
int V_13 ;
if ( V_2 -> V_14 . V_15 )
return false ;
V_11 = & V_2 -> V_11 ;
V_12 = true ;
F_4 (i, power_well, BIT(domain), power_domains) {
if ( V_4 -> V_16 )
continue;
if ( ! V_4 -> V_17 ) {
V_12 = false ;
break;
}
}
return V_12 ;
}
bool F_5 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
bool V_18 ;
V_11 = & V_2 -> V_11 ;
F_6 ( & V_11 -> V_19 ) ;
V_18 = F_3 ( V_2 , V_9 ) ;
F_7 ( & V_11 -> V_19 ) ;
return V_18 ;
}
void F_8 ( struct V_1 * V_2 ,
bool V_20 )
{
if ( V_2 -> V_11 . V_21 == V_20 )
return;
if ( V_20 )
F_9 ( V_2 , V_22 ) ;
else
F_10 ( V_2 , V_22 ) ;
V_2 -> V_11 . V_21 = V_20 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
F_12 ( V_24 -> V_25 , V_26 ) ;
F_13 ( F_14 ( V_27 ) , V_28 ) ;
F_15 ( V_24 -> V_25 , V_26 ) ;
if ( F_16 ( V_24 ) )
F_17 ( V_2 ,
1 << V_29 | 1 << V_30 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_4 -> V_31 == V_32 ) {
F_12 ( V_24 -> V_25 , V_26 ) ;
F_13 ( F_14 ( V_27 ) , V_28 ) ;
F_15 ( V_24 -> V_25 , V_26 ) ;
F_17 ( V_2 ,
1 << V_29 | 1 << V_30 ) ;
}
if ( V_4 -> V_31 == V_33 ) {
F_19 ( V_24 ) ;
F_17 ( V_2 , 1 << V_34 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
bool V_12 , V_35 ;
T_1 V_36 ;
V_36 = F_2 ( V_5 ) ;
V_12 = V_36 & V_7 ;
V_35 = V_36 & V_6 ;
if ( V_20 ) {
if ( ! V_35 )
F_21 ( V_5 ,
V_6 ) ;
if ( ! V_12 ) {
F_22 ( L_1 ) ;
if ( F_23 ( ( F_2 ( V_5 ) &
V_7 ) , 20 ) )
F_24 ( L_2 ) ;
F_11 ( V_2 ) ;
}
} else {
if ( V_35 ) {
F_21 ( V_5 , 0 ) ;
F_25 ( V_5 ) ;
F_22 ( L_3 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
F_27 ( ! F_28 ( V_24 ) , L_4 ) ;
F_27 ( ( F_2 ( V_37 ) & V_38 ) ,
L_5 ) ;
F_27 ( F_2 ( V_37 ) & V_39 ,
L_6 ) ;
F_27 ( F_2 ( V_5 ) , L_7 ) ;
F_27 ( F_29 ( V_2 ) , L_8 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_27 ( F_29 ( V_2 ) , L_8 ) ;
F_27 ( ! ( F_2 ( V_37 ) & V_38 ) ,
L_9 ) ;
F_27 ( F_2 ( V_37 ) & V_39 ,
L_10 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_26 ( V_2 ) ;
F_22 ( L_11 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 |= V_38 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_30 ( V_2 ) ;
F_22 ( L_12 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 &= ~ V_38 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
static void F_33 (
struct V_1 * V_2 )
{
T_1 V_40 ;
V_40 = F_2 ( V_41 ) ;
if ( ! ( V_40 & V_42 ) ) {
V_40 |= V_42 ;
F_21 ( V_41 , V_40 ) ;
F_25 ( V_41 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
bool V_43 = F_35 ( V_2 ,
V_32 ) ;
F_27 ( ! F_36 ( V_24 ) , L_13 ) ;
F_27 ( ! F_37 ( V_24 ) , L_14 ) ;
F_27 ( V_43 , L_15 ) ;
F_27 ( ( F_2 ( V_37 ) & V_39 ) ,
L_16 ) ;
F_27 ( V_2 -> V_14 . V_15 ,
L_17 ) ;
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
bool V_43 = F_35 ( V_2 ,
V_32 ) ;
if ( V_2 -> V_11 . V_44 )
return;
F_27 ( ! V_43 , L_18 ) ;
F_27 ( V_2 -> V_14 . V_15 ,
L_19 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_34 ( V_2 ) ;
F_22 ( L_20 ) ;
F_33 ( V_2 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 &= ~ V_45 ;
V_40 |= V_39 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_39 ( V_2 ) ;
F_22 ( L_21 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 &= ~ V_39 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
F_27 ( ! F_36 ( V_24 ) , L_22 ) ;
F_27 ( ! F_37 ( V_24 ) , L_14 ) ;
F_27 ( F_2 ( V_46 ) & V_47 ,
L_23 ) ;
F_27 ( ( F_2 ( V_37 ) & V_48 ) ,
L_24 ) ;
F_38 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_44 )
return;
F_38 ( V_2 ) ;
F_27 ( ! ( F_2 ( V_37 ) & V_48 ) ,
L_25 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_42 ( V_2 ) ;
F_22 ( L_26 ) ;
F_33 ( V_2 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 &= ~ V_45 ;
V_40 |= V_48 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_40 ;
F_43 ( V_2 ) ;
F_22 ( L_27 ) ;
V_40 = F_2 ( V_37 ) ;
V_40 &= ~ V_48 ;
F_21 ( V_37 , V_40 ) ;
F_25 ( V_37 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_36 , V_49 ;
T_1 V_50 , V_51 ;
bool V_12 , V_35 , V_52 = false ;
V_36 = F_2 ( V_5 ) ;
V_49 = F_2 ( V_53 ) ;
switch ( V_4 -> V_31 ) {
case V_33 :
if ( F_23 ( ( F_2 ( V_53 ) &
V_54 ) , 1 ) ) {
F_24 ( L_28 ) ;
return;
}
break;
case V_32 :
if ( ! ( V_49 & V_55 ) ) {
F_24 ( L_29 ) ;
return;
}
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
break;
default:
F_27 ( 1 , L_30 , V_4 -> V_31 ) ;
return;
}
V_50 = F_47 ( V_4 -> V_31 ) ;
V_35 = V_36 & V_50 ;
V_51 = F_48 ( V_4 -> V_31 ) ;
V_12 = V_36 & V_51 ;
if ( V_20 ) {
if ( ! V_35 ) {
F_27 ( ( V_36 & V_51 ) &&
! F_2 ( V_61 ) ,
L_31 ) ;
if ( ( F_49 ( V_24 ) || F_50 ( V_24 ) ) &&
V_4 -> V_31 == V_32 ) {
if ( F_50 ( V_24 ) ) {
F_45 ( V_2 ) ;
if ( ! V_2 -> V_11 . V_44 )
F_19 ( V_24 ) ;
} else {
F_41 ( V_2 ) ;
}
}
F_21 ( V_5 , V_36 | V_50 ) ;
}
if ( ! V_12 ) {
F_22 ( L_32 , V_4 -> V_62 ) ;
if ( F_23 ( ( F_2 ( V_5 ) &
V_51 ) , 1 ) )
F_24 ( L_33 ,
V_4 -> V_62 ) ;
V_52 = true ;
}
} else {
if ( V_35 ) {
F_21 ( V_5 , V_36 & ~ V_50 ) ;
F_25 ( V_5 ) ;
F_22 ( L_34 , V_4 -> V_62 ) ;
if ( ( F_49 ( V_24 ) || F_50 ( V_24 ) ) &&
V_4 -> V_31 == V_32 ) {
enum V_63 V_64 ;
F_23 ( ( V_64 = F_51 ( V_2 ) ) !=
V_65 , 1000 ) ;
if ( V_64 != V_66 )
F_24 ( L_35 ,
V_64 ) ;
else
if ( F_50 ( V_24 ) )
F_44 ( V_2 ) ;
else
F_40 ( V_2 ) ;
}
}
}
if ( V_52 ) {
if ( V_4 -> V_31 == V_33 ) {
if ( F_23 ( ( F_2 ( V_53 ) &
V_55 ) , 1 ) )
F_24 ( L_36 ) ;
} else if ( V_4 -> V_31 == V_32 ) {
if ( F_23 ( ( F_2 ( V_53 ) &
V_67 ) , 1 ) )
F_24 ( L_37 ) ;
}
}
if ( V_20 && ! V_12 )
F_18 ( V_2 , V_4 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , V_4 -> V_68 > 0 ) ;
if ( F_2 ( V_61 ) & V_6 )
F_21 ( V_61 , 0 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , true ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , false ) ;
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_69 = F_47 ( V_4 -> V_31 ) |
F_48 ( V_4 -> V_31 ) ;
return ( F_2 ( V_5 ) & V_69 ) == V_69 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_46 ( V_2 , V_4 , V_4 -> V_68 > 0 ) ;
F_21 ( V_61 , 0 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_46 ( V_2 , V_4 , true ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_46 ( V_2 , V_4 , false ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static bool F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return true ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
enum V_70 V_71 = V_4 -> V_31 ;
T_2 V_69 ;
T_2 V_64 ;
T_2 V_72 ;
V_69 = F_62 ( V_71 ) ;
V_64 = V_20 ? F_63 ( V_71 ) :
F_64 ( V_71 ) ;
F_6 ( & V_2 -> V_73 . V_74 ) ;
#define F_65 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_65 )
goto V_75;
V_72 = F_66 ( V_2 , V_76 ) ;
V_72 &= ~ V_69 ;
V_72 |= V_64 ;
F_67 ( V_2 , V_76 , V_72 ) ;
if ( F_23 ( F_65 , 100 ) )
F_24 ( L_38 ,
V_64 ,
F_66 ( V_2 , V_76 ) ) ;
#undef F_65
V_75:
F_7 ( & V_2 -> V_73 . V_74 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_61 ( V_2 , V_4 , V_4 -> V_68 > 0 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_61 ( V_2 , V_4 , true ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_61 ( V_2 , V_4 , false ) ;
}
static bool F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_71 = V_4 -> V_31 ;
bool V_77 = false ;
T_2 V_69 ;
T_2 V_64 ;
T_2 V_72 ;
V_69 = F_62 ( V_71 ) ;
V_72 = F_63 ( V_71 ) ;
F_6 ( & V_2 -> V_73 . V_74 ) ;
V_64 = F_66 ( V_2 , V_78 ) & V_69 ;
F_72 ( V_64 != F_63 ( V_71 ) &&
V_64 != F_64 ( V_71 ) ) ;
if ( V_64 == V_72 )
V_77 = true ;
V_72 = F_66 ( V_2 , V_76 ) & V_69 ;
F_72 ( V_72 != V_64 ) ;
F_7 ( & V_2 -> V_73 . V_74 ) ;
return V_77 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_74 ( V_4 -> V_31 != V_79 ) ;
F_61 ( V_2 , V_4 , true ) ;
F_75 ( & V_2 -> V_80 ) ;
F_76 ( V_2 ) ;
F_77 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_11 . V_44 )
return;
F_78 ( V_2 ) ;
F_79 ( V_2 -> V_24 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_74 ( V_4 -> V_31 != V_79 ) ;
F_75 ( & V_2 -> V_80 ) ;
F_81 ( V_2 ) ;
F_77 ( & V_2 -> V_80 ) ;
F_61 ( V_2 , V_4 , false ) ;
F_82 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_74 ( V_4 -> V_31 != V_81 ) ;
F_21 ( F_84 ( V_30 ) , F_2 ( F_84 ( V_30 ) ) |
V_82 | V_83 ) ;
F_85 ( 1 ) ;
F_61 ( V_2 , V_4 , true ) ;
F_21 ( V_84 , F_2 ( V_84 ) | V_85 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_86 V_86 ;
F_74 ( V_4 -> V_31 != V_81 ) ;
F_87 (dev_priv, pipe)
F_88 ( V_2 , V_86 ) ;
F_21 ( V_84 , F_2 ( V_84 ) & ~ V_85 ) ;
F_61 ( V_2 , V_4 , false ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_87 V_88 ;
F_74 ( V_4 -> V_31 != V_81 &&
V_4 -> V_31 != V_89 ) ;
if ( V_4 -> V_31 == V_81 ) {
V_88 = V_90 ;
F_21 ( F_84 ( V_30 ) , F_2 ( F_84 ( V_30 ) ) |
V_82 ) ;
F_21 ( F_84 ( V_30 ) , F_2 ( F_84 ( V_30 ) ) |
V_82 | V_83 ) ;
} else {
V_88 = V_91 ;
F_21 ( F_84 ( V_29 ) , F_2 ( F_84 ( V_29 ) ) |
V_82 | V_83 ) ;
}
F_85 ( 1 ) ;
F_61 ( V_2 , V_4 , true ) ;
if ( F_23 ( F_2 ( V_92 ) & F_90 ( V_88 ) , 1 ) )
F_24 ( L_39 , V_88 ) ;
V_2 -> V_93 |= F_91 ( V_88 ) ;
F_21 ( V_94 , V_2 -> V_93 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_87 V_88 ;
F_74 ( V_4 -> V_31 != V_81 &&
V_4 -> V_31 != V_89 ) ;
if ( V_4 -> V_31 == V_81 ) {
V_88 = V_90 ;
F_88 ( V_2 , V_34 ) ;
F_88 ( V_2 , V_30 ) ;
} else {
V_88 = V_91 ;
F_88 ( V_2 , V_29 ) ;
}
V_2 -> V_93 &= ~ F_91 ( V_88 ) ;
F_21 ( V_94 , V_2 -> V_93 ) ;
F_61 ( V_2 , V_4 , false ) ;
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_86 V_86 = V_4 -> V_31 ;
bool V_77 ;
T_2 V_64 , V_72 ;
F_6 ( & V_2 -> V_73 . V_74 ) ;
V_64 = F_66 ( V_2 , V_95 ) & F_94 ( V_86 ) ;
F_72 ( V_64 != F_95 ( V_86 ) && V_64 != F_96 ( V_86 ) ) ;
V_77 = V_64 == F_95 ( V_86 ) ;
V_72 = F_66 ( V_2 , V_95 ) & F_97 ( V_86 ) ;
F_72 ( V_72 << 16 != V_64 ) ;
F_7 ( & V_2 -> V_73 . V_74 ) ;
return V_77 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_20 )
{
enum V_86 V_86 = V_4 -> V_31 ;
T_2 V_64 ;
T_2 V_72 ;
V_64 = V_20 ? F_95 ( V_86 ) : F_96 ( V_86 ) ;
F_6 ( & V_2 -> V_73 . V_74 ) ;
#define F_65 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_65 )
goto V_75;
V_72 = F_66 ( V_2 , V_95 ) ;
V_72 &= ~ F_97 ( V_86 ) ;
V_72 |= V_20 ? F_99 ( V_86 ) : F_100 ( V_86 ) ;
F_67 ( V_2 , V_95 , V_72 ) ;
if ( F_23 ( F_65 , 100 ) )
F_24 ( L_38 ,
V_64 ,
F_66 ( V_2 , V_95 ) ) ;
#undef F_65
V_75:
F_7 ( & V_2 -> V_73 . V_74 ) ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_98 ( V_2 , V_4 , V_4 -> V_68 > 0 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_74 ( V_4 -> V_31 != V_34 &&
V_4 -> V_31 != V_30 &&
V_4 -> V_31 != V_29 ) ;
F_98 ( V_2 , V_4 , true ) ;
if ( V_4 -> V_31 == V_34 ) {
F_75 ( & V_2 -> V_80 ) ;
F_76 ( V_2 ) ;
F_77 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_11 . V_44 )
return;
F_78 ( V_2 ) ;
F_79 ( V_2 -> V_24 ) ;
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_74 ( V_4 -> V_31 != V_34 &&
V_4 -> V_31 != V_30 &&
V_4 -> V_31 != V_29 ) ;
if ( V_4 -> V_31 == V_34 ) {
F_75 ( & V_2 -> V_80 ) ;
F_81 ( V_2 ) ;
F_77 ( & V_2 -> V_80 ) ;
}
F_98 ( V_2 , V_4 , false ) ;
if ( V_4 -> V_31 == V_34 )
F_82 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_104 ( V_2 ) ;
V_11 = & V_2 -> V_11 ;
F_6 ( & V_11 -> V_19 ) ;
F_105 (i, power_well, BIT(domain), power_domains) {
if ( ! V_4 -> V_68 ++ ) {
F_22 ( L_40 , V_4 -> V_62 ) ;
V_4 -> V_96 -> V_20 ( V_2 , V_4 ) ;
V_4 -> V_17 = true ;
}
}
V_11 -> V_97 [ V_9 ] ++ ;
F_7 ( & V_11 -> V_19 ) ;
}
void F_10 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_13 ;
V_11 = & V_2 -> V_11 ;
F_6 ( & V_11 -> V_19 ) ;
F_72 ( ! V_11 -> V_97 [ V_9 ] ) ;
V_11 -> V_97 [ V_9 ] -- ;
F_4 (i, power_well, BIT(domain), power_domains) {
F_72 ( ! V_4 -> V_68 ) ;
if ( ! -- V_4 -> V_68 && V_98 . V_99 ) {
F_22 ( L_41 , V_4 -> V_62 ) ;
V_4 -> V_17 = false ;
V_4 -> V_96 -> V_100 ( V_2 , V_4 ) ;
}
}
F_7 ( & V_11 -> V_19 ) ;
F_106 ( V_2 ) ;
}
static struct V_3 * F_107 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_105 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_4 -> V_31 == V_71 )
return V_4 ;
}
return NULL ;
}
bool F_35 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_3 * V_4 ;
bool V_18 ;
V_4 = F_107 ( V_2 , V_71 ) ;
V_18 = V_4 -> V_96 -> V_12 ( V_2 , V_4 ) ;
return V_18 ;
}
int F_108 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
F_109 ( & V_11 -> V_19 ) ;
if ( F_110 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_101 ) ;
} else if ( F_16 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_102 ) ;
} else if ( F_36 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_103 ) ;
} else if ( F_28 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_104 ) ;
} else if ( F_112 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_105 ) ;
} else if ( F_113 ( V_2 -> V_24 ) ) {
F_111 ( V_11 , V_106 ) ;
} else {
F_111 ( V_11 , V_107 ) ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_108 * V_108 = & V_24 -> V_25 -> V_24 ;
if ( ! F_37 ( V_24 ) )
return;
if ( ! F_115 ( V_24 ) )
return;
F_116 ( V_108 ) ;
F_117 ( V_108 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_114 ( V_2 ) ;
F_8 ( V_2 , true ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_6 ( & V_11 -> V_19 ) ;
F_105 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_4 -> V_96 -> V_109 ( V_2 , V_4 ) ;
V_4 -> V_17 = V_4 -> V_96 -> V_12 ( V_2 ,
V_4 ) ;
}
F_7 ( & V_11 -> V_19 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_110 =
F_107 ( V_2 , V_81 ) ;
struct V_3 * V_111 =
F_107 ( V_2 , V_89 ) ;
V_2 -> V_93 =
F_121 ( V_112 , V_90 ) |
F_121 ( V_112 , V_91 ) |
F_122 ( V_113 , V_90 , V_114 ) |
F_122 ( V_113 , V_90 , V_115 ) |
F_122 ( V_113 , V_91 , V_114 ) ;
if ( V_110 -> V_96 -> V_12 ( V_2 , V_110 ) )
V_2 -> V_93 |= F_91 ( V_90 ) ;
if ( V_111 -> V_96 -> V_12 ( V_2 , V_111 ) )
V_2 -> V_93 |= F_91 ( V_91 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_3 * V_116 =
F_107 ( V_2 , V_81 ) ;
struct V_3 * V_117 =
F_107 ( V_2 , V_79 ) ;
if ( V_116 -> V_96 -> V_12 ( V_2 , V_116 ) &&
V_117 -> V_96 -> V_12 ( V_2 , V_117 ) &&
F_2 ( V_84 ) & V_85 )
return;
F_22 ( L_42 ) ;
V_117 -> V_96 -> V_20 ( V_2 , V_117 ) ;
V_116 -> V_96 -> V_100 ( V_2 , V_116 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
V_11 -> V_44 = true ;
if ( F_112 ( V_24 ) ) {
F_120 ( V_2 ) ;
} else if ( F_113 ( V_24 ) ) {
F_6 ( & V_11 -> V_19 ) ;
F_123 ( V_2 ) ;
F_7 ( & V_11 -> V_19 ) ;
}
F_8 ( V_2 , true ) ;
F_119 ( V_2 ) ;
V_11 -> V_44 = false ;
}
void F_125 ( struct V_1 * V_2 )
{
F_104 ( V_2 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
F_106 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_108 * V_108 = & V_24 -> V_25 -> V_24 ;
if ( ! F_37 ( V_24 ) )
return;
F_116 ( V_108 ) ;
F_27 ( V_2 -> V_14 . V_15 , L_43 ) ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_108 * V_108 = & V_24 -> V_25 -> V_24 ;
if ( ! F_37 ( V_24 ) )
return;
F_27 ( V_2 -> V_14 . V_15 , L_44 ) ;
F_128 ( V_108 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_108 * V_108 = & V_24 -> V_25 -> V_24 ;
if ( ! F_37 ( V_24 ) )
return;
F_129 ( V_108 ) ;
F_130 ( V_108 ) ;
}
void F_131 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_108 * V_108 = & V_24 -> V_25 -> V_24 ;
if ( ! F_37 ( V_24 ) )
return;
F_132 ( V_108 ) ;
if ( ! F_115 ( V_24 ) ) {
F_133 ( L_45 ) ;
return;
}
F_134 ( V_108 , 10000 ) ;
F_129 ( V_108 ) ;
F_135 ( V_108 ) ;
F_130 ( V_108 ) ;
}
