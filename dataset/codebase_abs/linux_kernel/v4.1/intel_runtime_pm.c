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
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
T_1 V_36 , V_37 ;
T_1 V_38 , V_39 ;
bool V_12 , V_35 , V_40 = false ;
V_36 = F_2 ( V_5 ) ;
V_37 = F_2 ( V_41 ) ;
switch ( V_4 -> V_31 ) {
case V_33 :
if ( F_23 ( ( F_2 ( V_41 ) &
V_42 ) , 1 ) ) {
F_24 ( L_4 ) ;
return;
}
break;
case V_32 :
if ( ! ( V_37 & V_43 ) ) {
F_24 ( L_5 ) ;
return;
}
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
break;
default:
F_27 ( 1 , L_6 , V_4 -> V_31 ) ;
return;
}
V_38 = F_28 ( V_4 -> V_31 ) ;
V_35 = V_36 & V_38 ;
V_39 = F_29 ( V_4 -> V_31 ) ;
V_12 = V_36 & V_39 ;
if ( V_20 ) {
if ( ! V_35 ) {
F_21 ( V_5 , V_36 | V_38 ) ;
}
if ( ! V_12 ) {
F_22 ( L_7 , V_4 -> V_49 ) ;
if ( F_23 ( ( F_2 ( V_5 ) &
V_39 ) , 1 ) )
F_24 ( L_8 ,
V_4 -> V_49 ) ;
V_40 = true ;
}
} else {
if ( V_35 ) {
F_21 ( V_5 , V_36 & ~ V_38 ) ;
F_25 ( V_5 ) ;
F_22 ( L_9 , V_4 -> V_49 ) ;
}
}
if ( V_40 ) {
if ( V_4 -> V_31 == V_33 ) {
if ( F_23 ( ( F_2 ( V_41 ) &
V_43 ) , 1 ) )
F_24 ( L_10 ) ;
} else if ( V_4 -> V_31 == V_32 ) {
if ( F_23 ( ( F_2 ( V_41 ) &
V_50 ) , 1 ) )
F_24 ( L_11 ) ;
}
}
if ( V_20 && ! V_12 )
F_18 ( V_2 , V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , V_4 -> V_51 > 0 ) ;
if ( F_2 ( V_52 ) & V_6 )
F_21 ( V_52 , 0 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , true ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 , false ) ;
}
static bool F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_53 = F_28 ( V_4 -> V_31 ) |
F_29 ( V_4 -> V_31 ) ;
return ( F_2 ( V_5 ) & V_53 ) == V_53 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_26 ( V_2 , V_4 , V_4 -> V_51 > 0 ) ;
F_21 ( V_52 , 0 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_26 ( V_2 , V_4 , true ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_26 ( V_2 , V_4 , false ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return true ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
enum V_54 V_55 = V_4 -> V_31 ;
T_2 V_53 ;
T_2 V_56 ;
T_2 V_57 ;
V_53 = F_40 ( V_55 ) ;
V_56 = V_20 ? F_41 ( V_55 ) :
F_42 ( V_55 ) ;
F_6 ( & V_2 -> V_58 . V_59 ) ;
#define F_43 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_43 )
goto V_60;
V_57 = F_44 ( V_2 , V_61 ) ;
V_57 &= ~ V_53 ;
V_57 |= V_56 ;
F_45 ( V_2 , V_61 , V_57 ) ;
if ( F_23 ( F_43 , 100 ) )
F_24 ( L_12 ,
V_56 ,
F_44 ( V_2 , V_61 ) ) ;
#undef F_43
V_60:
F_7 ( & V_2 -> V_58 . V_59 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_39 ( V_2 , V_4 , V_4 -> V_51 > 0 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_39 ( V_2 , V_4 , true ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_39 ( V_2 , V_4 , false ) ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_55 = V_4 -> V_31 ;
bool V_62 = false ;
T_2 V_53 ;
T_2 V_56 ;
T_2 V_57 ;
V_53 = F_40 ( V_55 ) ;
V_57 = F_41 ( V_55 ) ;
F_6 ( & V_2 -> V_58 . V_59 ) ;
V_56 = F_44 ( V_2 , V_63 ) & V_53 ;
F_50 ( V_56 != F_41 ( V_55 ) &&
V_56 != F_42 ( V_55 ) ) ;
if ( V_56 == V_57 )
V_62 = true ;
V_57 = F_44 ( V_2 , V_61 ) & V_53 ;
F_50 ( V_57 != V_56 ) ;
F_7 ( & V_2 -> V_58 . V_59 ) ;
return V_62 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_31 != V_64 ) ;
F_39 ( V_2 , V_4 , true ) ;
F_53 ( & V_2 -> V_65 ) ;
F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_11 . V_66 )
return;
F_56 ( V_2 ) ;
F_57 ( V_2 -> V_24 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_31 != V_64 ) ;
F_53 ( & V_2 -> V_65 ) ;
F_59 ( V_2 ) ;
F_55 ( & V_2 -> V_65 ) ;
F_39 ( V_2 , V_4 , false ) ;
F_60 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_31 != V_67 ) ;
F_21 ( F_62 ( V_30 ) , F_2 ( F_62 ( V_30 ) ) |
V_68 | V_69 ) ;
F_63 ( 1 ) ;
F_39 ( V_2 , V_4 , true ) ;
F_21 ( V_70 , F_2 ( V_70 ) | V_71 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_72 V_72 ;
F_52 ( V_4 -> V_31 != V_67 ) ;
F_65 (dev_priv, pipe)
F_66 ( V_2 , V_72 ) ;
F_21 ( V_70 , F_2 ( V_70 ) & ~ V_71 ) ;
F_39 ( V_2 , V_4 , false ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_73 V_74 ;
F_52 ( V_4 -> V_31 != V_67 &&
V_4 -> V_31 != V_75 ) ;
if ( V_4 -> V_31 == V_67 ) {
V_74 = V_76 ;
F_21 ( F_62 ( V_30 ) , F_2 ( F_62 ( V_30 ) ) |
V_68 ) ;
F_21 ( F_62 ( V_30 ) , F_2 ( F_62 ( V_30 ) ) |
V_68 | V_69 ) ;
} else {
V_74 = V_77 ;
F_21 ( F_62 ( V_29 ) , F_2 ( F_62 ( V_29 ) ) |
V_68 | V_69 ) ;
}
F_63 ( 1 ) ;
F_39 ( V_2 , V_4 , true ) ;
if ( F_23 ( F_2 ( V_78 ) & F_68 ( V_74 ) , 1 ) )
F_24 ( L_13 , V_74 ) ;
F_21 ( V_79 , F_2 ( V_79 ) |
F_69 ( V_74 ) ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_73 V_74 ;
F_52 ( V_4 -> V_31 != V_67 &&
V_4 -> V_31 != V_75 ) ;
if ( V_4 -> V_31 == V_67 ) {
V_74 = V_76 ;
F_66 ( V_2 , V_34 ) ;
F_66 ( V_2 , V_30 ) ;
} else {
V_74 = V_77 ;
F_66 ( V_2 , V_29 ) ;
}
F_21 ( V_79 , F_2 ( V_79 ) &
~ F_69 ( V_74 ) ) ;
F_39 ( V_2 , V_4 , false ) ;
}
static bool F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_72 V_72 = V_4 -> V_31 ;
bool V_62 ;
T_2 V_56 , V_57 ;
F_6 ( & V_2 -> V_58 . V_59 ) ;
V_56 = F_44 ( V_2 , V_80 ) & F_72 ( V_72 ) ;
F_50 ( V_56 != F_73 ( V_72 ) && V_56 != F_74 ( V_72 ) ) ;
V_62 = V_56 == F_73 ( V_72 ) ;
V_57 = F_44 ( V_2 , V_80 ) & F_75 ( V_72 ) ;
F_50 ( V_57 << 16 != V_56 ) ;
F_7 ( & V_2 -> V_58 . V_59 ) ;
return V_62 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_20 )
{
enum V_72 V_72 = V_4 -> V_31 ;
T_2 V_56 ;
T_2 V_57 ;
V_56 = V_20 ? F_73 ( V_72 ) : F_74 ( V_72 ) ;
F_6 ( & V_2 -> V_58 . V_59 ) ;
#define F_43 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_43 )
goto V_60;
V_57 = F_44 ( V_2 , V_80 ) ;
V_57 &= ~ F_75 ( V_72 ) ;
V_57 |= V_20 ? F_77 ( V_72 ) : F_78 ( V_72 ) ;
F_45 ( V_2 , V_80 , V_57 ) ;
if ( F_23 ( F_43 , 100 ) )
F_24 ( L_12 ,
V_56 ,
F_44 ( V_2 , V_80 ) ) ;
#undef F_43
V_60:
F_7 ( & V_2 -> V_58 . V_59 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_76 ( V_2 , V_4 , V_4 -> V_51 > 0 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_31 != V_34 &&
V_4 -> V_31 != V_30 &&
V_4 -> V_31 != V_29 ) ;
F_76 ( V_2 , V_4 , true ) ;
if ( V_4 -> V_31 == V_34 ) {
F_53 ( & V_2 -> V_65 ) ;
F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_11 . V_66 )
return;
F_56 ( V_2 ) ;
F_57 ( V_2 -> V_24 ) ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_31 != V_34 &&
V_4 -> V_31 != V_30 &&
V_4 -> V_31 != V_29 ) ;
if ( V_4 -> V_31 == V_34 ) {
F_53 ( & V_2 -> V_65 ) ;
F_59 ( V_2 ) ;
F_55 ( & V_2 -> V_65 ) ;
}
F_76 ( V_2 , V_4 , false ) ;
if ( V_4 -> V_31 == V_34 )
F_60 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_82 ( V_2 ) ;
V_11 = & V_2 -> V_11 ;
F_6 ( & V_11 -> V_19 ) ;
F_83 (i, power_well, BIT(domain), power_domains) {
if ( ! V_4 -> V_51 ++ ) {
F_22 ( L_14 , V_4 -> V_49 ) ;
V_4 -> V_81 -> V_20 ( V_2 , V_4 ) ;
V_4 -> V_17 = true ;
}
}
V_11 -> V_82 [ V_9 ] ++ ;
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
F_50 ( ! V_11 -> V_82 [ V_9 ] ) ;
V_11 -> V_82 [ V_9 ] -- ;
F_4 (i, power_well, BIT(domain), power_domains) {
F_50 ( ! V_4 -> V_51 ) ;
if ( ! -- V_4 -> V_51 && V_83 . V_84 ) {
F_22 ( L_15 , V_4 -> V_49 ) ;
V_4 -> V_17 = false ;
V_4 -> V_81 -> V_85 ( V_2 , V_4 ) ;
}
}
F_7 ( & V_11 -> V_19 ) ;
F_84 ( V_2 ) ;
}
static struct V_3 * F_85 ( struct V_1 * V_2 ,
enum V_54 V_55 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_83 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_4 -> V_31 == V_55 )
return V_4 ;
}
return NULL ;
}
int F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
F_87 ( & V_11 -> V_19 ) ;
if ( F_88 ( V_2 -> V_24 ) ) {
F_89 ( V_11 , V_86 ) ;
} else if ( F_16 ( V_2 -> V_24 ) ) {
F_89 ( V_11 , V_87 ) ;
} else if ( F_90 ( V_2 -> V_24 ) ) {
F_89 ( V_11 , V_88 ) ;
} else if ( F_91 ( V_2 -> V_24 ) ) {
F_89 ( V_11 , V_89 ) ;
} else if ( F_92 ( V_2 -> V_24 ) ) {
F_89 ( V_11 , V_90 ) ;
} else {
F_89 ( V_11 , V_91 ) ;
}
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_92 * V_92 = & V_24 -> V_25 -> V_24 ;
if ( ! F_94 ( V_24 ) )
return;
if ( ! F_95 ( V_24 ) )
return;
F_96 ( V_92 ) ;
F_97 ( V_92 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
F_93 ( V_2 ) ;
F_8 ( V_2 , true ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_6 ( & V_11 -> V_19 ) ;
F_83 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_4 -> V_81 -> V_93 ( V_2 , V_4 ) ;
V_4 -> V_17 = V_4 -> V_81 -> V_12 ( V_2 ,
V_4 ) ;
}
F_7 ( & V_11 -> V_19 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_94 =
F_85 ( V_2 , V_67 ) ;
struct V_3 * V_95 =
F_85 ( V_2 , V_64 ) ;
if ( V_94 -> V_81 -> V_12 ( V_2 , V_94 ) &&
V_95 -> V_81 -> V_12 ( V_2 , V_95 ) &&
F_2 ( V_70 ) & V_71 )
return;
F_22 ( L_16 ) ;
V_95 -> V_81 -> V_20 ( V_2 , V_95 ) ;
V_94 -> V_81 -> V_85 ( V_2 , V_94 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
V_11 -> V_66 = true ;
if ( F_92 ( V_24 ) && ! F_91 ( V_24 ) ) {
F_6 ( & V_11 -> V_19 ) ;
F_100 ( V_2 ) ;
F_7 ( & V_11 -> V_19 ) ;
}
F_8 ( V_2 , true ) ;
F_99 ( V_2 ) ;
V_11 -> V_66 = false ;
}
void F_102 ( struct V_1 * V_2 )
{
F_82 ( V_2 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_92 * V_92 = & V_24 -> V_25 -> V_24 ;
if ( ! F_94 ( V_24 ) )
return;
F_96 ( V_92 ) ;
F_27 ( V_2 -> V_14 . V_15 , L_17 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_92 * V_92 = & V_24 -> V_25 -> V_24 ;
if ( ! F_94 ( V_24 ) )
return;
F_27 ( V_2 -> V_14 . V_15 , L_18 ) ;
F_105 ( V_92 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_92 * V_92 = & V_24 -> V_25 -> V_24 ;
if ( ! F_94 ( V_24 ) )
return;
F_106 ( V_92 ) ;
F_107 ( V_92 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_92 * V_92 = & V_24 -> V_25 -> V_24 ;
if ( ! F_94 ( V_24 ) )
return;
F_109 ( V_92 ) ;
if ( ! F_95 ( V_24 ) ) {
F_110 ( L_19 ) ;
return;
}
F_111 ( V_92 , 10000 ) ;
F_106 ( V_92 ) ;
F_112 ( V_92 ) ;
F_107 ( V_92 ) ;
}
