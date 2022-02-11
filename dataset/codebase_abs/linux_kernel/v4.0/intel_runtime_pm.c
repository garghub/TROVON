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
if ( F_16 ( V_24 ) || ( F_17 ( V_24 ) -> V_29 >= 9 ) )
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
bool V_12 , V_30 ;
T_1 V_31 ;
V_31 = F_2 ( V_5 ) ;
V_12 = V_31 & V_7 ;
V_30 = V_31 & V_6 ;
if ( V_20 ) {
if ( ! V_30 )
F_20 ( V_5 ,
V_6 ) ;
if ( ! V_12 ) {
F_21 ( L_1 ) ;
if ( F_22 ( ( F_2 ( V_5 ) &
V_7 ) , 20 ) )
F_23 ( L_2 ) ;
F_11 ( V_2 ) ;
}
} else {
if ( V_30 ) {
F_20 ( V_5 , 0 ) ;
F_24 ( V_5 ) ;
F_21 ( L_3 ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_19 ( V_2 , V_4 , V_4 -> V_32 > 0 ) ;
if ( F_2 ( V_33 ) & V_6 )
F_20 ( V_33 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_19 ( V_2 , V_4 , true ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_19 ( V_2 , V_4 , false ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return true ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_20 )
{
enum V_34 V_35 = V_4 -> V_36 ;
T_2 V_37 ;
T_2 V_38 ;
T_2 V_39 ;
V_37 = F_31 ( V_35 ) ;
V_38 = V_20 ? F_32 ( V_35 ) :
F_33 ( V_35 ) ;
F_6 ( & V_2 -> V_40 . V_41 ) ;
#define F_34 \
((vlv_punit_read(dev_priv, PUNIT_REG_PWRGT_STATUS) & mask) == state)
if ( F_34 )
goto V_42;
V_39 = F_35 ( V_2 , V_43 ) ;
V_39 &= ~ V_37 ;
V_39 |= V_38 ;
F_36 ( V_2 , V_43 , V_39 ) ;
if ( F_22 ( F_34 , 100 ) )
F_23 ( L_4 ,
V_38 ,
F_35 ( V_2 , V_43 ) ) ;
#undef F_34
V_42:
F_7 ( & V_2 -> V_40 . V_41 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( V_2 , V_4 , V_4 -> V_32 > 0 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( V_2 , V_4 , true ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( V_2 , V_4 , false ) ;
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_35 = V_4 -> V_36 ;
bool V_44 = false ;
T_2 V_37 ;
T_2 V_38 ;
T_2 V_39 ;
V_37 = F_31 ( V_35 ) ;
V_39 = F_32 ( V_35 ) ;
F_6 ( & V_2 -> V_40 . V_41 ) ;
V_38 = F_35 ( V_2 , V_45 ) & V_37 ;
F_41 ( V_38 != F_32 ( V_35 ) &&
V_38 != F_33 ( V_35 ) ) ;
if ( V_38 == V_39 )
V_44 = true ;
V_39 = F_35 ( V_2 , V_43 ) & V_37 ;
F_41 ( V_39 != V_38 ) ;
F_7 ( & V_2 -> V_40 . V_41 ) ;
return V_44 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_43 ( V_4 -> V_36 != V_46 ) ;
F_30 ( V_2 , V_4 , true ) ;
F_44 ( & V_2 -> V_47 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_11 . V_48 )
return;
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_24 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_43 ( V_4 -> V_36 != V_46 ) ;
F_44 ( & V_2 -> V_47 ) ;
F_50 ( V_2 ) ;
F_46 ( & V_2 -> V_47 ) ;
F_30 ( V_2 , V_4 , false ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_43 ( V_4 -> V_36 != V_49 ) ;
F_20 ( F_53 ( V_50 ) , F_2 ( F_53 ( V_50 ) ) |
V_51 | V_52 ) ;
F_54 ( 1 ) ;
F_30 ( V_2 , V_4 , true ) ;
F_20 ( V_53 , F_2 ( V_53 ) | V_54 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_55 V_55 ;
F_43 ( V_4 -> V_36 != V_49 ) ;
F_56 (dev_priv, pipe)
F_57 ( V_2 , V_55 ) ;
F_20 ( V_53 , F_2 ( V_53 ) & ~ V_54 ) ;
F_30 ( V_2 , V_4 , false ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_56 V_57 ;
F_43 ( V_4 -> V_36 != V_49 &&
V_4 -> V_36 != V_58 ) ;
if ( V_4 -> V_36 == V_49 ) {
V_57 = V_59 ;
F_20 ( F_53 ( V_50 ) , F_2 ( F_53 ( V_50 ) ) |
V_51 ) ;
F_20 ( F_53 ( V_50 ) , F_2 ( F_53 ( V_50 ) ) |
V_51 | V_52 ) ;
} else {
V_57 = V_60 ;
F_20 ( F_53 ( V_61 ) , F_2 ( F_53 ( V_61 ) ) |
V_51 | V_52 ) ;
}
F_54 ( 1 ) ;
F_30 ( V_2 , V_4 , true ) ;
if ( F_22 ( F_2 ( V_62 ) & F_59 ( V_57 ) , 1 ) )
F_23 ( L_5 , V_57 ) ;
F_20 ( V_63 , F_2 ( V_63 ) |
F_60 ( V_57 ) ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_56 V_57 ;
F_43 ( V_4 -> V_36 != V_49 &&
V_4 -> V_36 != V_58 ) ;
if ( V_4 -> V_36 == V_49 ) {
V_57 = V_59 ;
F_57 ( V_2 , V_64 ) ;
F_57 ( V_2 , V_50 ) ;
} else {
V_57 = V_60 ;
F_57 ( V_2 , V_61 ) ;
}
F_20 ( V_63 , F_2 ( V_63 ) &
~ F_60 ( V_57 ) ) ;
F_30 ( V_2 , V_4 , false ) ;
}
static bool F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_55 V_55 = V_4 -> V_36 ;
bool V_44 ;
T_2 V_38 , V_39 ;
F_6 ( & V_2 -> V_40 . V_41 ) ;
V_38 = F_35 ( V_2 , V_65 ) & F_63 ( V_55 ) ;
F_41 ( V_38 != F_64 ( V_55 ) && V_38 != F_65 ( V_55 ) ) ;
V_44 = V_38 == F_64 ( V_55 ) ;
V_39 = F_35 ( V_2 , V_65 ) & F_66 ( V_55 ) ;
F_41 ( V_39 << 16 != V_38 ) ;
F_7 ( & V_2 -> V_40 . V_41 ) ;
return V_44 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_20 )
{
enum V_55 V_55 = V_4 -> V_36 ;
T_2 V_38 ;
T_2 V_39 ;
V_38 = V_20 ? F_64 ( V_55 ) : F_65 ( V_55 ) ;
F_6 ( & V_2 -> V_40 . V_41 ) ;
#define F_34 \
((vlv_punit_read(dev_priv, PUNIT_REG_DSPFREQ) & DP_SSS_MASK(pipe)) == state)
if ( F_34 )
goto V_42;
V_39 = F_35 ( V_2 , V_65 ) ;
V_39 &= ~ F_66 ( V_55 ) ;
V_39 |= V_20 ? F_68 ( V_55 ) : F_69 ( V_55 ) ;
F_36 ( V_2 , V_65 , V_39 ) ;
if ( F_22 ( F_34 , 100 ) )
F_23 ( L_4 ,
V_38 ,
F_35 ( V_2 , V_65 ) ) ;
#undef F_34
V_42:
F_7 ( & V_2 -> V_40 . V_41 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_67 ( V_2 , V_4 , V_4 -> V_32 > 0 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_43 ( V_4 -> V_36 != V_64 &&
V_4 -> V_36 != V_50 &&
V_4 -> V_36 != V_61 ) ;
F_67 ( V_2 , V_4 , true ) ;
if ( V_4 -> V_36 == V_64 ) {
F_44 ( & V_2 -> V_47 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_11 . V_48 )
return;
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_24 ) ;
}
}
static void F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_43 ( V_4 -> V_36 != V_64 &&
V_4 -> V_36 != V_50 &&
V_4 -> V_36 != V_61 ) ;
if ( V_4 -> V_36 == V_64 ) {
F_44 ( & V_2 -> V_47 ) ;
F_50 ( V_2 ) ;
F_46 ( & V_2 -> V_47 ) ;
}
F_67 ( V_2 , V_4 , false ) ;
if ( V_4 -> V_36 == V_64 )
F_51 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_73 ( V_2 ) ;
V_11 = & V_2 -> V_11 ;
F_6 ( & V_11 -> V_19 ) ;
F_74 (i, power_well, BIT(domain), power_domains) {
if ( ! V_4 -> V_32 ++ ) {
F_21 ( L_6 , V_4 -> V_66 ) ;
V_4 -> V_67 -> V_20 ( V_2 , V_4 ) ;
V_4 -> V_17 = true ;
}
}
V_11 -> V_68 [ V_9 ] ++ ;
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
F_41 ( ! V_11 -> V_68 [ V_9 ] ) ;
V_11 -> V_68 [ V_9 ] -- ;
F_4 (i, power_well, BIT(domain), power_domains) {
F_41 ( ! V_4 -> V_32 ) ;
if ( ! -- V_4 -> V_32 && V_69 . V_70 ) {
F_21 ( L_7 , V_4 -> V_66 ) ;
V_4 -> V_17 = false ;
V_4 -> V_67 -> V_71 ( V_2 , V_4 ) ;
}
}
F_7 ( & V_11 -> V_19 ) ;
F_75 ( V_2 ) ;
}
static struct V_3 * F_76 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_74 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
if ( V_4 -> V_36 == V_35 )
return V_4 ;
}
return NULL ;
}
int F_77 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
F_78 ( & V_11 -> V_19 ) ;
if ( F_79 ( V_2 -> V_24 ) ) {
F_80 ( V_11 , V_72 ) ;
} else if ( F_16 ( V_2 -> V_24 ) ) {
F_80 ( V_11 , V_73 ) ;
} else if ( F_81 ( V_2 -> V_24 ) ) {
F_80 ( V_11 , V_74 ) ;
} else if ( F_82 ( V_2 -> V_24 ) ) {
F_80 ( V_11 , V_75 ) ;
} else {
F_80 ( V_11 , V_76 ) ;
}
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_77 * V_77 = & V_24 -> V_25 -> V_24 ;
if ( ! F_84 ( V_24 ) )
return;
if ( ! F_85 ( V_24 ) )
return;
F_86 ( V_77 ) ;
F_87 ( V_77 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_83 ( V_2 ) ;
F_8 ( V_2 , true ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_13 ;
F_6 ( & V_11 -> V_19 ) ;
F_74 (i, power_well, POWER_DOMAIN_MASK, power_domains) {
V_4 -> V_67 -> V_78 ( V_2 , V_4 ) ;
V_4 -> V_17 = V_4 -> V_67 -> V_12 ( V_2 ,
V_4 ) ;
}
F_7 ( & V_11 -> V_19 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_79 =
F_76 ( V_2 , V_49 ) ;
struct V_3 * V_80 =
F_76 ( V_2 , V_46 ) ;
if ( V_79 -> V_67 -> V_12 ( V_2 , V_79 ) &&
V_80 -> V_67 -> V_12 ( V_2 , V_80 ) &&
F_2 ( V_53 ) & V_54 )
return;
F_21 ( L_8 ) ;
V_80 -> V_67 -> V_20 ( V_2 , V_80 ) ;
V_79 -> V_67 -> V_71 ( V_2 , V_79 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
V_11 -> V_48 = true ;
if ( F_82 ( V_24 ) && ! F_81 ( V_24 ) ) {
F_6 ( & V_11 -> V_19 ) ;
F_90 ( V_2 ) ;
F_7 ( & V_11 -> V_19 ) ;
}
F_8 ( V_2 , true ) ;
F_89 ( V_2 ) ;
V_11 -> V_48 = false ;
}
void F_92 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_77 * V_77 = & V_24 -> V_25 -> V_24 ;
if ( ! F_84 ( V_24 ) )
return;
F_86 ( V_77 ) ;
F_94 ( V_2 -> V_14 . V_15 , L_9 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_77 * V_77 = & V_24 -> V_25 -> V_24 ;
if ( ! F_84 ( V_24 ) )
return;
F_94 ( V_2 -> V_14 . V_15 , L_10 ) ;
F_96 ( V_77 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_77 * V_77 = & V_24 -> V_25 -> V_24 ;
if ( ! F_84 ( V_24 ) )
return;
F_97 ( V_77 ) ;
F_98 ( V_77 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_77 * V_77 = & V_24 -> V_25 -> V_24 ;
if ( ! F_84 ( V_24 ) )
return;
F_100 ( V_77 ) ;
if ( ! F_85 ( V_24 ) ) {
F_101 ( L_11 ) ;
return;
}
F_102 ( V_77 , 10000 ) ;
F_97 ( V_77 ) ;
F_103 ( V_77 ) ;
F_98 ( V_77 ) ;
}
