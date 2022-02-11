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
F_29 ( ! F_38 ( V_27 ) , L_15 ) ;
F_29 ( ! F_39 ( V_27 ) , L_16 ) ;
F_29 ( V_47 , L_17 ) ;
F_29 ( ( F_5 ( V_41 ) & V_43 ) ,
L_18 ) ;
F_29 ( V_2 -> V_19 . V_20 ,
L_19 ) ;
F_40 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
bool V_47 = F_37 ( V_2 ,
V_35 ) ;
if ( V_2 -> V_16 . V_37 )
return;
F_29 ( ! V_47 , L_20 ) ;
F_29 ( V_2 -> V_19 . V_20 ,
L_21 ) ;
}
static void F_42 ( struct V_1 * V_2 )
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
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_41 ( V_2 ) ;
F_2 ( L_23 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_43 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
F_29 ( ! F_38 ( V_27 ) , L_24 ) ;
F_29 ( ! F_39 ( V_27 ) , L_16 ) ;
F_29 ( F_5 ( V_49 ) & V_50 ,
L_25 ) ;
F_29 ( ( F_5 ( V_41 ) & V_51 ) ,
L_26 ) ;
F_40 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_37 )
return;
F_40 ( V_2 ) ;
F_29 ( ! ( F_5 ( V_41 ) & V_51 ) ,
L_27 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_44 ( V_2 ) ;
F_2 ( L_28 ) ;
F_35 ( V_2 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_48 ;
V_44 |= V_51 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_45 ( V_2 ) ;
F_2 ( L_29 ) ;
V_44 = F_5 ( V_41 ) ;
V_44 &= ~ V_51 ;
F_24 ( V_41 , V_44 ) ;
F_27 ( V_41 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
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
V_53 = F_49 ( V_4 -> V_34 ) ;
V_39 = V_40 & V_53 ;
V_54 = F_50 ( V_4 -> V_34 ) ;
V_17 = V_40 & V_54 ;
if ( V_7 ) {
if ( ! V_39 ) {
F_29 ( ( V_40 & V_54 ) &&
! F_5 ( V_64 ) ,
L_33 ) ;
if ( ( F_51 ( V_27 ) || F_52 ( V_27 ) ) &&
V_4 -> V_34 == V_35 ) {
if ( F_52 ( V_27 ) ) {
F_47 ( V_2 ) ;
if ( ! V_2 -> V_16 . V_37 )
F_22 ( V_27 ) ;
} else {
F_43 ( V_2 ) ;
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
F_24 ( V_10 , V_40 & ~ V_53 ) ;
F_27 ( V_10 ) ;
F_2 ( L_36 , V_4 -> V_5 ) ;
if ( ( F_51 ( V_27 ) || F_52 ( V_27 ) ) &&
V_4 -> V_34 == V_35 ) {
enum V_65 V_66 ;
F_25 ( ( V_66 = F_53 ( V_2 ) ) !=
V_67 , 1000 ) ;
if ( V_66 != V_68 )
F_26 ( L_37 ,
V_66 ) ;
else
if ( F_52 ( V_27 ) )
F_46 ( V_2 ) ;
else
F_42 ( V_2 ) ;
}
}
}
if ( V_55 ) {
if ( V_4 -> V_34 == V_36 ) {
if ( F_25 ( ( F_5 ( V_56 ) &
V_58 ) , 1 ) )
F_26 ( L_38 ) ;
} else if ( V_4 -> V_34 == V_35 ) {
if ( F_25 ( ( F_5 ( V_56 ) &
V_69 ) , 1 ) )
F_26 ( L_39 ) ;
}
}
if ( V_7 && ! V_17 )
F_21 ( V_2 , V_4 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
if ( F_5 ( V_64 ) & V_11 )
F_24 ( V_64 , 0 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , true ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_23 ( V_2 , V_4 , false ) ;
}
static bool F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_71 = F_49 ( V_4 -> V_34 ) |
F_50 ( V_4 -> V_34 ) ;
return ( F_5 ( V_10 ) & V_71 ) == V_71 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_48 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
F_24 ( V_64 , 0 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_48 ( V_2 , V_4 , true ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_48 ( V_2 , V_4 , false ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static bool F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return true ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_7 )
{
enum V_72 V_73 = V_4 -> V_34 ;
T_2 V_71 ;
T_2 V_66 ;
T_2 V_74 ;
V_71 = F_64 ( V_73 ) ;
V_66 = V_7 ? F_65 ( V_73 ) :
F_66 ( V_73 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
#define F_67 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_67 )
goto V_77;
V_74 = F_68 ( V_2 , V_78 ) ;
V_74 &= ~ V_71 ;
V_74 |= V_66 ;
F_69 ( V_2 , V_78 , V_74 ) ;
if ( F_25 ( F_67 , 100 ) )
F_26 ( L_40 ,
V_66 ,
F_68 ( V_2 , V_78 ) ) ;
#undef F_67
V_77:
F_10 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_63 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_63 ( V_2 , V_4 , true ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_63 ( V_2 , V_4 , false ) ;
}
static bool F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_73 = V_4 -> V_34 ;
bool V_79 = false ;
T_2 V_71 ;
T_2 V_66 ;
T_2 V_74 ;
V_71 = F_64 ( V_73 ) ;
V_74 = F_65 ( V_73 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
V_66 = F_68 ( V_2 , V_80 ) & V_71 ;
F_74 ( V_66 != F_65 ( V_73 ) &&
V_66 != F_66 ( V_73 ) ) ;
if ( V_66 == V_74 )
V_79 = true ;
V_74 = F_68 ( V_2 , V_78 ) & V_71 ;
F_74 ( V_74 != V_66 ) ;
F_10 ( & V_2 -> V_75 . V_76 ) ;
return V_79 ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_76 ( & V_2 -> V_81 ) ;
F_77 ( V_2 ) ;
F_78 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_16 . V_37 )
return;
F_79 ( V_2 ) ;
F_80 ( V_2 -> V_27 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_76 ( & V_2 -> V_81 ) ;
F_82 ( V_2 ) ;
F_78 ( & V_2 -> V_81 ) ;
F_83 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_82 ) ;
F_63 ( V_2 , V_4 , true ) ;
F_75 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_82 ) ;
F_81 ( V_2 ) ;
F_63 ( V_2 , V_4 , false ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_83 ) ;
F_24 ( F_88 ( V_33 ) , F_5 ( F_88 ( V_33 ) ) | V_84 |
V_85 | V_86 ) ;
F_89 ( 1 ) ;
F_63 ( V_2 , V_4 , true ) ;
F_24 ( V_87 , F_5 ( V_87 ) | V_88 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_89 V_89 ;
F_85 ( V_4 -> V_34 != V_83 ) ;
F_91 (dev_priv, pipe)
F_92 ( V_2 , V_89 ) ;
F_24 ( V_87 , F_5 ( V_87 ) & ~ V_88 ) ;
F_63 ( V_2 , V_4 , false ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_90 V_91 ;
F_85 ( V_4 -> V_34 != V_83 &&
V_4 -> V_34 != V_92 ) ;
if ( V_4 -> V_34 == V_83 ) {
V_91 = V_93 ;
F_24 ( F_88 ( V_33 ) , F_5 ( F_88 ( V_33 ) ) | V_84 |
V_85 ) ;
F_24 ( F_88 ( V_33 ) , F_5 ( F_88 ( V_33 ) ) | V_84 |
V_85 | V_86 ) ;
} else {
V_91 = V_94 ;
F_24 ( F_88 ( V_32 ) , F_5 ( F_88 ( V_32 ) ) | V_84 |
V_85 | V_86 ) ;
}
F_89 ( 1 ) ;
F_63 ( V_2 , V_4 , true ) ;
if ( F_25 ( F_5 ( V_95 ) & F_94 ( V_91 ) , 1 ) )
F_26 ( L_41 , V_91 ) ;
V_2 -> V_96 |= F_95 ( V_91 ) ;
F_24 ( V_97 , V_2 -> V_96 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_90 V_91 ;
F_85 ( V_4 -> V_34 != V_83 &&
V_4 -> V_34 != V_92 ) ;
if ( V_4 -> V_34 == V_83 ) {
V_91 = V_93 ;
F_92 ( V_2 , V_38 ) ;
F_92 ( V_2 , V_33 ) ;
} else {
V_91 = V_94 ;
F_92 ( V_2 , V_32 ) ;
}
V_2 -> V_96 &= ~ F_95 ( V_91 ) ;
F_24 ( V_97 , V_2 -> V_96 ) ;
F_63 ( V_2 , V_4 , false ) ;
}
static bool F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_89 V_89 = V_4 -> V_34 ;
bool V_79 ;
T_2 V_66 , V_74 ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
V_66 = F_68 ( V_2 , V_98 ) & F_98 ( V_89 ) ;
F_74 ( V_66 != F_99 ( V_89 ) && V_66 != F_100 ( V_89 ) ) ;
V_79 = V_66 == F_99 ( V_89 ) ;
V_74 = F_68 ( V_2 , V_98 ) & F_101 ( V_89 ) ;
F_74 ( V_74 << 16 != V_66 ) ;
F_10 ( & V_2 -> V_75 . V_76 ) ;
return V_79 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
enum V_89 V_89 = V_4 -> V_34 ;
T_2 V_66 ;
T_2 V_74 ;
V_66 = V_7 ? F_99 ( V_89 ) : F_100 ( V_89 ) ;
F_9 ( & V_2 -> V_75 . V_76 ) ;
#define F_67 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_67 )
goto V_77;
V_74 = F_68 ( V_2 , V_98 ) ;
V_74 &= ~ F_101 ( V_89 ) ;
V_74 |= V_7 ? F_103 ( V_89 ) : F_104 ( V_89 ) ;
F_69 ( V_2 , V_98 , V_74 ) ;
if ( F_25 ( F_67 , 100 ) )
F_26 ( L_40 ,
V_66 ,
F_68 ( V_2 , V_98 ) ) ;
#undef F_67
V_77:
F_10 ( & V_2 -> V_75 . V_76 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_38 ) ;
F_102 ( V_2 , V_4 , V_4 -> V_70 > 0 ) ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_38 ) ;
F_102 ( V_2 , V_4 , true ) ;
F_75 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_85 ( V_4 -> V_34 != V_38 ) ;
F_81 ( V_2 ) ;
F_102 ( V_2 , V_4 , false ) ;
}
void F_12 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_108 ( V_2 ) ;
V_16 = & V_2 -> V_16 ;
F_9 ( & V_16 -> V_23 ) ;
F_109 (i, power_well, BIT(domain), power_domains) {
if ( ! V_4 -> V_70 ++ )
F_1 ( V_2 , V_4 ) ;
}
V_16 -> V_99 [ V_14 ] ++ ;
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
F_74 ( ! V_16 -> V_99 [ V_14 ] ) ;
V_16 -> V_99 [ V_14 ] -- ;
F_7 (i, power_well, BIT(domain), power_domains) {
F_74 ( ! V_4 -> V_70 ) ;
if ( ! -- V_4 -> V_70 && V_100 . V_101 )
F_3 ( V_2 , V_4 ) ;
}
F_10 ( & V_16 -> V_23 ) ;
F_110 ( V_2 ) ;
}
static struct V_3 * F_111 ( struct V_1 * V_2 ,
int V_73 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_109 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_4 -> V_34 == V_73 )
return V_4 ;
}
return NULL ;
}
bool F_37 ( struct V_1 * V_2 ,
int V_73 )
{
struct V_3 * V_4 ;
bool V_22 ;
V_4 = F_111 ( V_2 , V_73 ) ;
V_22 = V_4 -> V_6 -> V_17 ( V_2 , V_4 ) ;
return V_22 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
F_113 ( & V_16 -> V_23 ) ;
if ( F_114 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_102 ) ;
} else if ( F_19 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_103 ) ;
} else if ( F_38 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_104 ) ;
} else if ( F_30 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_105 ) ;
} else if ( F_116 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_106 ) ;
} else if ( F_117 ( V_2 -> V_27 ) ) {
F_115 ( V_16 , V_107 ) ;
} else {
F_115 ( V_16 , V_108 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_109 * V_109 = & V_27 -> V_28 -> V_27 ;
if ( ! F_39 ( V_27 ) )
return;
if ( ! F_119 ( V_27 ) )
return;
F_120 ( V_109 ) ;
F_121 ( V_109 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
F_118 ( V_2 ) ;
F_11 ( V_2 , true ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_18 ;
F_9 ( & V_16 -> V_23 ) ;
F_109 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_4 -> V_6 -> V_110 ( V_2 , V_4 ) ;
V_4 -> V_8 = V_4 -> V_6 -> V_17 ( V_2 ,
V_4 ) ;
}
F_10 ( & V_16 -> V_23 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_3 * V_111 =
F_111 ( V_2 , V_83 ) ;
struct V_3 * V_112 =
F_111 ( V_2 , V_92 ) ;
V_2 -> V_96 =
F_125 ( V_113 , V_93 ) |
F_125 ( V_113 , V_94 ) |
F_126 ( V_114 , V_93 , V_115 ) |
F_126 ( V_114 , V_93 , V_116 ) |
F_126 ( V_114 , V_94 , V_115 ) ;
if ( V_111 -> V_6 -> V_17 ( V_2 , V_111 ) )
V_2 -> V_96 |= F_95 ( V_93 ) ;
if ( V_112 -> V_6 -> V_17 ( V_2 , V_112 ) )
V_2 -> V_96 |= F_95 ( V_94 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_3 * V_117 =
F_111 ( V_2 , V_83 ) ;
struct V_3 * V_118 =
F_111 ( V_2 , V_82 ) ;
if ( V_117 -> V_6 -> V_17 ( V_2 , V_117 ) &&
V_118 -> V_6 -> V_17 ( V_2 , V_118 ) &&
F_5 ( V_87 ) & V_88 )
return;
F_2 ( L_42 ) ;
V_118 -> V_6 -> V_7 ( V_2 , V_118 ) ;
V_117 -> V_6 -> V_9 ( V_2 , V_117 ) ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
V_16 -> V_37 = true ;
if ( F_116 ( V_27 ) ) {
F_124 ( V_2 ) ;
} else if ( F_117 ( V_27 ) ) {
F_9 ( & V_16 -> V_23 ) ;
F_127 ( V_2 ) ;
F_10 ( & V_16 -> V_23 ) ;
}
F_11 ( V_2 , true ) ;
F_123 ( V_2 ) ;
V_16 -> V_37 = false ;
}
void F_129 ( struct V_1 * V_2 )
{
F_108 ( V_2 ) ;
}
void F_130 ( struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_109 * V_109 = & V_27 -> V_28 -> V_27 ;
if ( ! F_39 ( V_27 ) )
return;
F_120 ( V_109 ) ;
F_29 ( V_2 -> V_19 . V_20 , L_43 ) ;
}
void F_131 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_109 * V_109 = & V_27 -> V_28 -> V_27 ;
if ( ! F_39 ( V_27 ) )
return;
F_29 ( V_2 -> V_19 . V_20 , L_44 ) ;
F_132 ( V_109 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_109 * V_109 = & V_27 -> V_28 -> V_27 ;
if ( ! F_39 ( V_27 ) )
return;
F_133 ( V_109 ) ;
F_134 ( V_109 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_109 * V_109 = & V_27 -> V_28 -> V_27 ;
if ( ! F_39 ( V_27 ) )
return;
F_136 ( V_109 ) ;
if ( ! F_119 ( V_27 ) ) {
F_137 ( L_45 ) ;
return;
}
F_138 ( V_109 , 10000 ) ;
F_133 ( V_109 ) ;
F_139 ( V_109 ) ;
F_134 ( V_109 ) ;
}
