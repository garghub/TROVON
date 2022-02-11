static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( 1 , L_1 ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
return false ;
}
static T_1 F_5 ( T_1 V_5 )
{
T_1 V_6 ;
F_6 () ;
F_7 ( V_5 , V_7 ) ;
F_8 () ;
V_6 = F_9 ( V_8 ) ;
F_10 () ;
return V_6 ;
}
static bool F_11 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( ! V_9 -> V_12 )
return F_1 ( V_2 , V_9 ) ;
F_12 ( V_2 ) ;
return true ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
bool V_13 = F_14 ( V_2 ) ;
F_15 ( ! V_9 -> V_12 ) ;
if ( ! V_9 -> V_14 ) {
F_16 ( V_2 , V_11 -> V_15 ) = V_9 -> V_16 ;
} else {
if ( ! V_9 -> V_17 )
F_17 ( V_2 , V_11 -> V_15 ) = F_18 ( V_9 -> V_16 ) ;
F_19 ( V_2 , V_11 -> V_15 ) = F_20 ( V_9 -> V_16 ) ;
}
F_21 ( V_2 , V_13 ) ;
return true ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( ! V_9 -> V_12 )
return F_1 ( V_2 , V_9 ) ;
F_23 ( V_2 , V_9 -> V_16 ) ;
return true ;
}
static bool F_24 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 )
return F_25 ( V_2 , V_9 ) ;
V_9 -> V_16 = V_2 -> V_18 . V_19 . V_20 . V_21 ;
return true ;
}
static bool F_26 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 )
return F_25 ( V_2 , V_9 ) ;
else
return F_27 ( V_2 , V_9 ) ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
return F_25 ( V_2 , V_9 ) ;
} else {
V_9 -> V_16 = ( 1 << 3 ) ;
return true ;
}
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
return F_25 ( V_2 , V_9 ) ;
} else {
V_9 -> V_16 = F_9 ( V_22 ) ;
return true ;
}
}
static bool F_30 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
F_16 ( V_2 , V_11 -> V_15 ) = V_9 -> V_16 ;
V_2 -> V_18 . V_23 |= V_24 ;
} else {
V_9 -> V_16 = F_16 ( V_2 , V_11 -> V_15 ) ;
}
F_31 ( V_25 , V_11 -> V_15 , V_9 -> V_12 , V_9 -> V_16 ) ;
return true ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
T_2 * V_26 )
{
T_2 V_27 = V_9 -> V_16 ;
if ( V_9 -> V_17 ) {
V_27 &= 0xffffffffUL ;
V_27 |= ( ( * V_26 >> 32 ) << 32 ) ;
}
* V_26 = V_27 ;
V_2 -> V_18 . V_23 |= V_24 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
T_2 * V_26 )
{
V_9 -> V_16 = * V_26 ;
if ( V_9 -> V_17 )
V_9 -> V_16 &= 0xffffffffUL ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_28 )
{
T_2 * V_26 = & V_2 -> V_18 . V_29 . V_30 [ V_28 -> V_15 ] ;
if ( V_9 -> V_12 )
F_32 ( V_2 , V_9 , V_26 ) ;
else
F_33 ( V_2 , V_9 , V_26 ) ;
F_31 ( V_25 , V_28 -> V_15 , V_9 -> V_12 , * V_26 ) ;
return true ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_30 [ V_28 -> V_15 ] ;
if ( F_36 ( V_11 , V_32 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_30 [ V_28 -> V_15 ] ;
if ( F_39 ( V_32 , V_11 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
const struct V_10 * V_28 )
{
V_2 -> V_18 . V_29 . V_30 [ V_28 -> V_15 ] = V_28 -> V_27 ;
}
static bool F_41 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_28 )
{
T_2 * V_26 = & V_2 -> V_18 . V_29 . V_35 [ V_28 -> V_15 ] ;
if ( V_9 -> V_12 )
F_32 ( V_2 , V_9 , V_26 ) ;
else
F_33 ( V_2 , V_9 , V_26 ) ;
F_31 ( V_25 , V_28 -> V_15 , V_9 -> V_12 , * V_26 ) ;
return true ;
}
static int F_42 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_35 [ V_28 -> V_15 ] ;
if ( F_36 ( V_11 , V_32 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_35 [ V_28 -> V_15 ] ;
if ( F_39 ( V_32 , V_11 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
const struct V_10 * V_28 )
{
V_2 -> V_18 . V_29 . V_35 [ V_28 -> V_15 ] = V_28 -> V_27 ;
}
static bool F_45 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_28 )
{
T_2 * V_26 = & V_2 -> V_18 . V_29 . V_36 [ V_28 -> V_15 ] ;
if ( V_9 -> V_12 )
F_32 ( V_2 , V_9 , V_26 ) ;
else
F_33 ( V_2 , V_9 , V_26 ) ;
F_31 ( V_25 , V_28 -> V_15 , V_9 -> V_12 ,
V_2 -> V_18 . V_29 . V_36 [ V_28 -> V_15 ] ) ;
return true ;
}
static int F_46 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_36 [ V_28 -> V_15 ] ;
if ( F_36 ( V_11 , V_32 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_36 [ V_28 -> V_15 ] ;
if ( F_39 ( V_32 , V_11 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_10 * V_28 )
{
V_2 -> V_18 . V_29 . V_36 [ V_28 -> V_15 ] = V_28 -> V_27 ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_28 )
{
T_2 * V_26 = & V_2 -> V_18 . V_29 . V_37 [ V_28 -> V_15 ] ;
if ( V_9 -> V_12 )
F_32 ( V_2 , V_9 , V_26 ) ;
else
F_33 ( V_2 , V_9 , V_26 ) ;
F_31 ( V_25 , V_28 -> V_15 , V_9 -> V_12 , * V_26 ) ;
return true ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_37 [ V_28 -> V_15 ] ;
if ( F_36 ( V_11 , V_32 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_10 * V_28 ,
const struct V_31 * V_15 , void T_3 * V_32 )
{
T_4 * V_11 = & V_2 -> V_18 . V_29 . V_37 [ V_28 -> V_15 ] ;
if ( F_39 ( V_32 , V_11 , F_37 ( V_15 -> V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
const struct V_10 * V_28 )
{
V_2 -> V_18 . V_29 . V_37 [ V_28 -> V_15 ] = V_28 -> V_27 ;
}
static void F_53 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
F_16 ( V_2 , V_38 ) = F_9 ( V_39 ) ;
}
static void F_54 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
T_2 V_40 ;
V_40 = ( V_2 -> V_41 & 0x0f ) << F_55 ( 0 ) ;
V_40 |= ( ( V_2 -> V_41 >> 4 ) & 0xff ) << F_55 ( 1 ) ;
V_40 |= ( ( V_2 -> V_41 >> 12 ) & 0xff ) << F_55 ( 2 ) ;
F_16 ( V_2 , V_42 ) = ( 1ULL << 31 ) | V_40 ;
}
static void F_56 ( struct V_1 * V_2 , const struct V_10 * V_11 )
{
T_2 V_43 , V_27 ;
V_43 = F_9 ( V_44 ) ;
V_27 = ( ( V_43 & ~ V_45 )
| ( V_45 & 0xdecafbad ) ) & ( ~ V_46 ) ;
F_16 ( V_2 , V_47 ) = V_27 ;
}
static bool F_57 ( struct V_1 * V_2 , T_2 V_48 )
{
T_2 V_15 = F_16 ( V_2 , V_49 ) ;
bool V_50 = ( V_15 & V_48 ) || F_58 ( V_2 ) ;
if ( ! V_50 )
F_4 ( V_2 ) ;
return ! V_50 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_51 ) ;
}
static bool F_60 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_52 | V_51 ) ;
}
static bool F_61 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_53 | V_51 ) ;
}
static bool F_62 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , V_54 | V_51 ) ;
}
static bool F_63 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_27 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( F_59 ( V_2 ) )
return false ;
if ( V_9 -> V_12 ) {
V_27 = F_16 ( V_2 , V_47 ) ;
V_27 &= ~ V_45 ;
V_27 |= V_9 -> V_16 & V_45 ;
F_16 ( V_2 , V_47 ) = V_27 ;
F_65 ( V_2 , V_27 ) ;
} else {
V_27 = F_16 ( V_2 , V_47 )
& ~ ( V_55 | V_56 ) ;
V_9 -> V_16 = V_27 ;
}
return true ;
}
static bool F_66 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( F_62 ( V_2 ) )
return false ;
if ( V_9 -> V_12 )
F_16 ( V_2 , V_57 ) = V_9 -> V_16 ;
else
V_9 -> V_16 = F_16 ( V_2 , V_57 )
& V_58 ;
return true ;
}
static bool F_67 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_59 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
F_15 ( V_9 -> V_12 ) ;
if ( F_59 ( V_2 ) )
return false ;
if ( ! ( V_9 -> V_60 & 1 ) )
V_59 = F_9 ( V_61 ) ;
else
V_59 = F_9 ( V_62 ) ;
V_9 -> V_16 = V_59 ;
return true ;
}
static bool F_68 ( struct V_1 * V_2 , T_2 V_63 )
{
T_2 V_43 , V_27 ;
V_43 = F_16 ( V_2 , V_47 ) ;
V_27 = ( V_43 >> V_64 ) & V_65 ;
if ( V_63 >= V_27 && V_63 != V_66 ) {
F_4 ( V_2 ) ;
return false ;
}
return true ;
}
static bool F_69 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_63 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( V_11 -> V_67 == 9 && V_11 -> V_68 == 13 ) {
if ( V_11 -> V_60 == 2 ) {
if ( F_62 ( V_2 ) )
return false ;
V_63 = F_16 ( V_2 , V_57 )
& V_58 ;
} else if ( V_11 -> V_60 == 0 ) {
if ( F_61 ( V_2 ) )
return false ;
V_63 = V_66 ;
} else {
return false ;
}
} else if ( V_11 -> V_67 == 0 && V_11 -> V_68 == 9 ) {
if ( F_62 ( V_2 ) )
return false ;
V_63 = V_66 ;
} else if ( V_11 -> V_67 == 14 && ( V_11 -> V_68 & 12 ) == 8 ) {
if ( F_62 ( V_2 ) )
return false ;
V_63 = ( ( V_11 -> V_68 & 3 ) << 3 ) | ( V_11 -> V_60 & 7 ) ;
} else {
return false ;
}
if ( ! F_68 ( V_2 , V_63 ) )
return false ;
if ( V_9 -> V_12 ) {
if ( F_59 ( V_2 ) )
return false ;
F_70 ( V_2 , V_63 , V_9 -> V_16 ) ;
} else {
V_9 -> V_16 = F_71 ( V_2 , V_63 ) ;
}
return true ;
}
static bool F_72 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_63 , V_15 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( F_59 ( V_2 ) )
return false ;
if ( V_11 -> V_67 == 9 && V_11 -> V_68 == 13 && V_11 -> V_60 == 1 ) {
V_63 = F_16 ( V_2 , V_57 ) & V_58 ;
V_15 = V_69 + V_63 ;
} else if ( V_11 -> V_67 == 14 && ( V_11 -> V_68 & 12 ) == 12 ) {
V_63 = ( ( V_11 -> V_68 & 3 ) << 3 ) | ( V_11 -> V_60 & 7 ) ;
if ( V_63 == V_66 )
V_15 = V_70 ;
else
V_15 = V_69 + V_63 ;
} else {
F_73 () ;
}
if ( ! F_68 ( V_2 , V_63 ) )
return false ;
if ( V_9 -> V_12 ) {
F_74 ( V_2 , V_9 -> V_16 , V_63 ) ;
F_16 ( V_2 , V_15 ) = V_9 -> V_16 & V_71 ;
} else {
V_9 -> V_16 = F_16 ( V_2 , V_15 ) & V_71 ;
}
return true ;
}
static bool F_75 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_27 , V_72 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( F_59 ( V_2 ) )
return false ;
V_72 = F_76 ( V_2 ) ;
if ( V_9 -> V_12 ) {
V_27 = V_9 -> V_16 & V_72 ;
if ( V_11 -> V_60 & 0x1 ) {
F_16 ( V_2 , V_73 ) |= V_27 ;
F_77 ( V_2 , V_27 ) ;
} else {
F_16 ( V_2 , V_73 ) &= ~ V_27 ;
F_78 ( V_2 , V_27 ) ;
}
} else {
V_9 -> V_16 = F_16 ( V_2 , V_73 ) & V_72 ;
}
return true ;
}
static bool F_79 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_72 = F_76 ( V_2 ) ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( ! F_58 ( V_2 ) ) {
F_4 ( V_2 ) ;
return false ;
}
if ( V_9 -> V_12 ) {
T_2 V_27 = V_9 -> V_16 & V_72 ;
if ( V_11 -> V_60 & 0x1 )
F_16 ( V_2 , V_74 ) |= V_27 ;
else
F_16 ( V_2 , V_74 ) &= ~ V_27 ;
} else {
V_9 -> V_16 = F_16 ( V_2 , V_74 ) & V_72 ;
}
return true ;
}
static bool F_80 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_72 = F_76 ( V_2 ) ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( F_59 ( V_2 ) )
return false ;
if ( V_9 -> V_12 ) {
if ( V_11 -> V_68 & 0x2 )
F_81 ( V_2 , V_9 -> V_16 & V_72 ) ;
else
F_16 ( V_2 , V_75 ) &= ~ ( V_9 -> V_16 & V_72 ) ;
} else {
V_9 -> V_16 = F_16 ( V_2 , V_75 ) & V_72 ;
}
return true ;
}
static bool F_82 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
T_2 V_72 ;
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( ! V_9 -> V_12 )
return F_1 ( V_2 , V_9 ) ;
if ( F_60 ( V_2 ) )
return false ;
V_72 = F_76 ( V_2 ) ;
F_83 ( V_2 , V_9 -> V_16 & V_72 ) ;
return true ;
}
static bool F_84 ( struct V_1 * V_2 , struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( ! F_64 ( V_2 ) )
return F_26 ( V_2 , V_9 , V_11 ) ;
if ( V_9 -> V_12 ) {
if ( ! F_58 ( V_2 ) ) {
F_4 ( V_2 ) ;
return false ;
}
F_16 ( V_2 , V_49 ) = V_9 -> V_16
& V_76 ;
} else {
V_9 -> V_16 = F_16 ( V_2 , V_49 )
& V_76 ;
}
return true ;
}
static bool F_85 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
struct V_77 * V_78 = F_86 ( V_2 ) ;
T_2 V_79 = F_87 () ;
if ( V_9 -> V_12 )
V_78 -> V_80 = V_9 -> V_16 + V_79 ;
else
V_9 -> V_16 = V_78 -> V_80 - V_79 ;
return true ;
}
static bool F_88 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
struct V_77 * V_78 = F_86 ( V_2 ) ;
if ( V_9 -> V_12 ) {
V_78 -> V_81 = V_9 -> V_16 & ~ V_82 ;
} else {
T_2 V_79 = F_87 () ;
V_9 -> V_16 = V_78 -> V_81 ;
if ( V_78 -> V_80 <= V_79 )
V_9 -> V_16 |= V_82 ;
}
return true ;
}
static bool F_89 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
struct V_77 * V_78 = F_86 ( V_2 ) ;
if ( V_9 -> V_12 )
V_78 -> V_80 = V_9 -> V_16 ;
else
V_9 -> V_16 = V_78 -> V_80 ;
return true ;
}
static bool F_90 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
return F_25 ( V_2 , V_9 ) ;
} else {
T_2 V_83 = F_91 ( V_84 ) ;
T_2 V_85 = F_91 ( V_86 ) ;
T_1 V_87 = ! ! F_92 ( V_85 , V_88 ) ;
V_9 -> V_16 = ( ( ( ( V_83 >> V_89 ) & 0xf ) << 28 ) |
( ( ( V_83 >> V_90 ) & 0xf ) << 24 ) |
( ( ( V_83 >> V_91 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_87 << 14 ) | ( V_87 << 12 ) ) ;
return true ;
}
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 -> V_12 ) {
F_94 ( V_2 , V_11 -> V_15 ) = V_9 -> V_16 ;
V_2 -> V_18 . V_23 |= V_24 ;
} else {
V_9 -> V_16 = F_94 ( V_2 , V_11 -> V_15 ) ;
}
return true ;
}
static bool F_95 ( struct V_1 * V_2 ,
struct V_3 * V_9 ,
const struct V_10 * V_28 )
{
T_2 * V_26 = & V_2 -> V_18 . V_29 . V_30 [ V_28 -> V_15 ] ;
if ( V_9 -> V_12 ) {
T_2 V_27 = * V_26 ;
V_27 &= 0xffffffffUL ;
V_27 |= V_9 -> V_16 << 32 ;
* V_26 = V_27 ;
V_2 -> V_18 . V_23 |= V_24 ;
} else {
V_9 -> V_16 = * V_26 >> 32 ;
}
F_31 ( V_25 , V_28 -> V_15 , V_9 -> V_12 , * V_26 ) ;
return true ;
}
void F_96 ( unsigned int V_92 ,
struct V_93 * V_94 )
{
V_95 [ V_92 ] = V_94 ;
}
static const struct V_10 * F_97 ( unsigned V_92 ,
bool V_96 ,
T_5 * V_97 )
{
struct V_93 * V_94 ;
V_94 = V_95 [ V_92 ] ;
if ( V_96 ) {
* V_97 = V_94 -> V_98 . V_97 ;
return V_94 -> V_98 . V_94 ;
} else {
* V_97 = V_94 -> V_99 . V_97 ;
return V_94 -> V_99 . V_94 ;
}
}
static int F_98 ( const void * V_100 , const void * V_101 )
{
const unsigned long V_102 = ( unsigned long ) V_100 ;
const struct V_10 * V_11 = V_101 ;
return V_102 - F_99 ( V_11 ) ;
}
static const struct V_10 * F_100 ( const struct V_3 * V_4 ,
const struct V_10 V_94 [] ,
unsigned int V_97 )
{
unsigned long V_102 = F_99 ( V_4 ) ;
return bsearch ( ( void * ) V_102 , V_94 , V_97 , sizeof( V_94 [ 0 ] ) , F_98 ) ;
}
int F_101 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
F_4 ( V_2 ) ;
return 1 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_10 * V_11 )
{
F_15 ( ! V_11 -> V_105 ) ;
if ( F_103 ( V_11 -> V_105 ( V_2 , V_4 , V_11 ) ) )
F_104 ( V_2 , F_105 ( V_2 ) ) ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_10 * V_94 ,
T_5 V_97 )
{
const struct V_10 * V_11 ;
if ( ! V_94 )
return - 1 ;
V_11 = F_100 ( V_4 , V_94 , V_97 ) ;
if ( V_11 ) {
F_102 ( V_2 , V_4 , V_11 ) ;
return 0 ;
}
return - 1 ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_6 V_106 = F_108 ( V_2 ) ;
int V_107 = - 1 ;
switch( V_106 ) {
case V_108 :
case V_109 :
V_107 = 15 ;
break;
case V_110 :
case V_111 :
V_107 = 14 ;
break;
default:
F_109 ( 1 ) ;
}
F_110 ( L_2 ,
V_107 , * F_111 ( V_2 ) ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
}
static int F_112 ( struct V_1 * V_2 ,
const struct V_10 * V_112 ,
T_5 V_113 ,
const struct V_10 * V_114 ,
T_5 V_115 )
{
struct V_3 V_4 ;
T_1 V_116 = F_113 ( V_2 ) ;
int V_117 = F_114 ( V_2 ) ;
int V_118 = ( V_116 >> 10 ) & 0x1f ;
V_4 . V_14 = true ;
V_4 . V_17 = false ;
V_4 . V_68 = ( V_116 >> 1 ) & 0xf ;
V_4 . V_12 = ( ( V_116 & 1 ) == 0 ) ;
V_4 . V_119 = 0 ;
V_4 . V_120 = ( V_116 >> 16 ) & 0xf ;
V_4 . V_60 = 0 ;
V_4 . V_67 = 0 ;
if ( V_4 . V_12 ) {
V_4 . V_16 = F_115 ( V_2 , V_117 ) & 0xffffffff ;
V_4 . V_16 |= F_115 ( V_2 , V_118 ) << 32 ;
}
if ( ! F_106 ( V_2 , & V_4 , V_114 , V_115 ) ||
! F_106 ( V_2 , & V_4 , V_112 , V_113 ) ) {
if ( ! V_4 . V_12 ) {
F_116 ( V_2 , V_117 , F_20 ( V_4 . V_16 ) ) ;
F_116 ( V_2 , V_118 , F_18 ( V_4 . V_16 ) ) ;
}
return 1 ;
}
F_107 ( V_2 , & V_4 ) ;
return 1 ;
}
static int F_117 ( struct V_1 * V_2 ,
const struct V_10 * V_112 ,
T_5 V_113 ,
const struct V_10 * V_114 ,
T_5 V_115 )
{
struct V_3 V_4 ;
T_1 V_116 = F_113 ( V_2 ) ;
int V_117 = F_114 ( V_2 ) ;
V_4 . V_14 = true ;
V_4 . V_17 = true ;
V_4 . V_68 = ( V_116 >> 1 ) & 0xf ;
V_4 . V_16 = F_115 ( V_2 , V_117 ) ;
V_4 . V_12 = ( ( V_116 & 1 ) == 0 ) ;
V_4 . V_67 = ( V_116 >> 10 ) & 0xf ;
V_4 . V_119 = 0 ;
V_4 . V_120 = ( V_116 >> 14 ) & 0x7 ;
V_4 . V_60 = ( V_116 >> 17 ) & 0x7 ;
if ( ! F_106 ( V_2 , & V_4 , V_114 , V_115 ) ||
! F_106 ( V_2 , & V_4 , V_112 , V_113 ) ) {
if ( ! V_4 . V_12 )
F_116 ( V_2 , V_117 , V_4 . V_16 ) ;
return 1 ;
}
F_107 ( V_2 , & V_4 ) ;
return 1 ;
}
int F_118 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
const struct V_10 * V_114 ;
T_5 V_97 ;
V_114 = F_97 ( V_2 -> V_18 . V_92 , false , & V_97 ) ;
return F_112 ( V_2 ,
V_121 , F_119 ( V_121 ) ,
V_114 , V_97 ) ;
}
int F_120 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
const struct V_10 * V_114 ;
T_5 V_97 ;
V_114 = F_97 ( V_2 -> V_18 . V_92 , false , & V_97 ) ;
return F_117 ( V_2 ,
V_122 , F_119 ( V_122 ) ,
V_114 , V_97 ) ;
}
int F_121 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
return F_112 ( V_2 ,
V_123 , F_119 ( V_123 ) ,
NULL , 0 ) ;
}
int F_122 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
return F_117 ( V_2 ,
V_124 , F_119 ( V_124 ) ,
NULL , 0 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_97 ;
const struct V_10 * V_94 , * V_11 ;
V_94 = F_97 ( V_2 -> V_18 . V_92 , true , & V_97 ) ;
V_11 = F_100 ( V_4 , V_94 , V_97 ) ;
if ( ! V_11 )
V_11 = F_100 ( V_4 , V_125 , F_119 ( V_125 ) ) ;
if ( F_103 ( V_11 ) ) {
F_102 ( V_2 , V_4 , V_11 ) ;
} else {
F_110 ( L_3 ,
* F_111 ( V_2 ) ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
}
return 1 ;
}
static void F_124 ( struct V_1 * V_2 ,
const struct V_10 * V_94 , T_5 V_97 )
{
unsigned long V_126 ;
for ( V_126 = 0 ; V_126 < V_97 ; V_126 ++ )
if ( V_94 [ V_126 ] . V_127 )
V_94 [ V_126 ] . V_127 ( V_2 , & V_94 [ V_126 ] ) ;
}
int F_125 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_3 V_4 ;
unsigned long V_128 = F_113 ( V_2 ) ;
int V_117 = F_114 ( V_2 ) ;
int V_129 ;
F_126 ( V_128 ) ;
V_4 . V_14 = false ;
V_4 . V_17 = false ;
V_4 . V_119 = ( V_128 >> 20 ) & 3 ;
V_4 . V_120 = ( V_128 >> 14 ) & 0x7 ;
V_4 . V_67 = ( V_128 >> 10 ) & 0xf ;
V_4 . V_68 = ( V_128 >> 1 ) & 0xf ;
V_4 . V_60 = ( V_128 >> 17 ) & 0x7 ;
V_4 . V_16 = F_115 ( V_2 , V_117 ) ;
V_4 . V_12 = ! ( V_128 & 1 ) ;
V_129 = F_123 ( V_2 , & V_4 ) ;
if ( ! V_4 . V_12 )
F_116 ( V_2 , V_117 , V_4 . V_16 ) ;
return V_129 ;
}
static bool F_127 ( T_2 V_33 , struct V_3 * V_4 )
{
switch ( V_33 & V_130 ) {
case V_131 :
if ( V_33 & ~ ( V_132 | V_130
| V_133
| V_134
| V_135
| V_136
| V_137
| V_138 ) )
return false ;
V_4 -> V_119 = ( ( V_33 & V_134 )
>> V_139 ) ;
V_4 -> V_120 = ( ( V_33 & V_135 )
>> V_140 ) ;
V_4 -> V_67 = ( ( V_33 & V_136 )
>> V_141 ) ;
V_4 -> V_68 = ( ( V_33 & V_137 )
>> V_142 ) ;
V_4 -> V_60 = ( ( V_33 & V_138 )
>> V_143 ) ;
return true ;
default:
return false ;
}
}
const struct V_10 * F_128 ( T_2 V_33 ,
struct V_3 * V_4 ,
const struct V_10 V_94 [] ,
unsigned int V_97 )
{
if ( ! F_127 ( V_33 , V_4 ) )
return NULL ;
return F_100 ( V_4 , V_94 , V_97 ) ;
}
static const struct V_10 * F_129 ( struct V_1 * V_2 ,
T_2 V_33 )
{
T_5 V_97 ;
const struct V_10 * V_94 , * V_11 ;
struct V_3 V_4 ;
if ( ( V_33 & V_133 ) != V_144 )
return NULL ;
V_94 = F_97 ( V_2 -> V_18 . V_92 , true , & V_97 ) ;
V_11 = F_128 ( V_33 , & V_4 , V_94 , V_97 ) ;
if ( ! V_11 )
V_11 = F_100 ( & V_4 , V_125 , F_119 ( V_125 ) ) ;
if ( V_11 && ! V_11 -> V_15 )
V_11 = NULL ;
return V_11 ;
}
static int F_130 ( T_2 * V_27 , const void T_3 * V_32 , T_2 V_33 )
{
if ( F_36 ( V_27 , V_32 , F_37 ( V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_131 ( void T_3 * V_32 , const T_2 * V_27 , T_2 V_33 )
{
if ( F_39 ( V_32 , V_27 , F_37 ( V_33 ) ) != 0 )
return - V_34 ;
return 0 ;
}
static int F_132 ( T_2 V_33 , void T_3 * V_32 )
{
struct V_3 V_4 ;
const struct V_10 * V_11 ;
V_11 = F_128 ( V_33 , & V_4 , V_145 ,
F_119 ( V_145 ) ) ;
if ( ! V_11 )
return - V_146 ;
return F_131 ( V_32 , & V_11 -> V_27 , V_33 ) ;
}
static int F_133 ( T_2 V_33 , void T_3 * V_32 )
{
struct V_3 V_4 ;
const struct V_10 * V_11 ;
int V_147 ;
T_2 V_27 = 0 ;
V_11 = F_128 ( V_33 , & V_4 , V_145 ,
F_119 ( V_145 ) ) ;
if ( ! V_11 )
return - V_146 ;
V_147 = F_130 ( & V_27 , V_32 , V_33 ) ;
if ( V_147 )
return V_147 ;
if ( V_11 -> V_27 != V_27 )
return - V_148 ;
return 0 ;
}
static bool F_134 ( T_1 V_27 )
{
T_1 V_149 , V_150 ;
if ( V_27 >= V_151 )
return false ;
V_149 = ( V_27 >> 1 ) ;
V_150 = ( V_152 >> ( V_149 * 3 ) ) & 7 ;
switch ( V_150 ) {
case 0 :
return false ;
case 1 :
return ( V_27 & 1 ) ;
case 2 :
case 4 :
return ! ( V_27 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_135 ( T_2 V_33 , void T_3 * V_32 )
{
T_1 V_27 ;
T_1 T_3 * V_153 = V_32 ;
if ( V_33 & ~ ( V_132 | V_130 | V_133
| ( ( 1 << V_154 ) - 1 ) ) )
return - V_146 ;
switch ( V_33 & V_155 ) {
case V_156 :
if ( F_37 ( V_33 ) != 4 )
return - V_146 ;
V_27 = ( V_33 & V_157 )
>> V_158 ;
if ( ! F_134 ( V_27 ) )
return - V_146 ;
return F_136 ( F_5 ( V_27 ) , V_153 ) ;
default:
return - V_146 ;
}
}
static int F_137 ( T_2 V_33 , void T_3 * V_32 )
{
T_1 V_27 , V_159 ;
T_1 T_3 * V_153 = V_32 ;
if ( V_33 & ~ ( V_132 | V_130 | V_133
| ( ( 1 << V_154 ) - 1 ) ) )
return - V_146 ;
switch ( V_33 & V_155 ) {
case V_156 :
if ( F_37 ( V_33 ) != 4 )
return - V_146 ;
V_27 = ( V_33 & V_157 )
>> V_158 ;
if ( ! F_134 ( V_27 ) )
return - V_146 ;
if ( F_138 ( V_159 , V_153 ) )
return - V_34 ;
if ( V_159 != F_5 ( V_27 ) )
return - V_148 ;
return 0 ;
default:
return - V_146 ;
}
}
int F_139 ( struct V_1 * V_2 , const struct V_31 * V_15 )
{
const struct V_10 * V_11 ;
void T_3 * V_32 = ( void T_3 * ) ( unsigned long ) V_15 -> V_160 ;
if ( ( V_15 -> V_33 & V_133 ) == V_161 )
return F_135 ( V_15 -> V_33 , V_32 ) ;
if ( F_37 ( V_15 -> V_33 ) != sizeof( T_4 ) )
return - V_146 ;
V_11 = F_129 ( V_2 , V_15 -> V_33 ) ;
if ( ! V_11 )
return F_132 ( V_15 -> V_33 , V_32 ) ;
if ( V_11 -> F_138 )
return ( V_11 -> F_138 ) ( V_2 , V_11 , V_15 , V_32 ) ;
return F_131 ( V_32 , & F_16 ( V_2 , V_11 -> V_15 ) , V_15 -> V_33 ) ;
}
int F_140 ( struct V_1 * V_2 , const struct V_31 * V_15 )
{
const struct V_10 * V_11 ;
void T_3 * V_32 = ( void T_3 * ) ( unsigned long ) V_15 -> V_160 ;
if ( ( V_15 -> V_33 & V_133 ) == V_161 )
return F_137 ( V_15 -> V_33 , V_32 ) ;
if ( F_37 ( V_15 -> V_33 ) != sizeof( T_4 ) )
return - V_146 ;
V_11 = F_129 ( V_2 , V_15 -> V_33 ) ;
if ( ! V_11 )
return F_133 ( V_15 -> V_33 , V_32 ) ;
if ( V_11 -> V_162 )
return ( V_11 -> V_162 ) ( V_2 , V_11 , V_15 , V_32 ) ;
return F_130 ( & F_16 ( V_2 , V_11 -> V_15 ) , V_32 , V_15 -> V_33 ) ;
}
static unsigned int F_141 ( void )
{
unsigned int V_126 , V_163 = 0 ;
for ( V_126 = 0 ; V_126 < V_151 ; V_126 ++ )
if ( F_134 ( V_126 ) )
V_163 ++ ;
return V_163 ;
}
static int F_142 ( T_2 T_3 * V_164 )
{
T_2 V_27 = V_165 | V_166 | V_161 ;
unsigned int V_126 ;
V_27 |= V_156 ;
for ( V_126 = 0 ; V_126 < V_151 ; V_126 ++ ) {
if ( ! F_134 ( V_126 ) )
continue;
if ( F_136 ( V_27 | V_126 , V_164 ) )
return - V_34 ;
V_164 ++ ;
}
return 0 ;
}
static T_2 F_143 ( const struct V_10 * V_15 )
{
return ( V_165 | V_131 |
V_144 |
( V_15 -> V_119 << V_139 ) |
( V_15 -> V_120 << V_140 ) |
( V_15 -> V_67 << V_141 ) |
( V_15 -> V_68 << V_142 ) |
( V_15 -> V_60 << V_143 ) ) ;
}
static bool F_144 ( const struct V_10 * V_15 , T_2 T_3 * * V_167 )
{
if ( ! * V_167 )
return true ;
if ( F_136 ( F_143 ( V_15 ) , * V_167 ) )
return false ;
( * V_167 ) ++ ;
return true ;
}
static int F_145 ( struct V_1 * V_2 , T_2 T_3 * V_167 )
{
const struct V_10 * V_168 , * V_169 , * V_170 , * V_171 ;
unsigned int V_172 = 0 ;
T_5 V_97 ;
V_168 = F_97 ( V_2 -> V_18 . V_92 , true , & V_97 ) ;
V_170 = V_168 + V_97 ;
V_169 = V_125 ;
V_171 = V_125 + F_119 ( V_125 ) ;
F_15 ( V_168 == V_170 || V_169 == V_171 ) ;
while ( V_168 || V_169 ) {
int V_173 = F_146 ( V_168 , V_169 ) ;
if ( V_173 <= 0 ) {
if ( V_168 -> V_15 ) {
if ( ! F_144 ( V_168 , & V_167 ) )
return - V_34 ;
V_172 ++ ;
}
} else {
if ( V_169 -> V_15 ) {
if ( ! F_144 ( V_169 , & V_167 ) )
return - V_34 ;
V_172 ++ ;
}
}
if ( V_173 <= 0 && ++ V_168 == V_170 )
V_168 = NULL ;
if ( V_173 >= 0 && ++ V_169 == V_171 )
V_169 = NULL ;
}
return V_172 ;
}
unsigned long F_147 ( struct V_1 * V_2 )
{
return F_119 ( V_145 )
+ F_141 ()
+ F_145 ( V_2 , ( T_2 T_3 * ) NULL ) ;
}
int F_148 ( struct V_1 * V_2 , T_2 T_3 * V_164 )
{
unsigned int V_126 ;
int V_147 ;
for ( V_126 = 0 ; V_126 < F_119 ( V_145 ) ; V_126 ++ ) {
if ( F_136 ( F_143 ( & V_145 [ V_126 ] ) , V_164 ) )
return - V_34 ;
V_164 ++ ;
}
V_147 = F_145 ( V_2 , V_164 ) ;
if ( V_147 < 0 )
return V_147 ;
V_164 += V_147 ;
return F_142 ( V_164 ) ;
}
static int F_149 ( const struct V_10 * V_94 , unsigned int V_174 )
{
unsigned int V_126 ;
for ( V_126 = 1 ; V_126 < V_174 ; V_126 ++ ) {
if ( F_146 ( & V_94 [ V_126 - 1 ] , & V_94 [ V_126 ] ) >= 0 ) {
F_110 ( L_4 , V_94 , V_126 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_150 ( void )
{
unsigned int V_126 ;
struct V_10 V_175 ;
F_15 ( F_149 ( V_125 , F_119 ( V_125 ) ) ) ;
F_15 ( F_149 ( V_124 , F_119 ( V_124 ) ) ) ;
F_15 ( F_149 ( V_123 , F_119 ( V_123 ) ) ) ;
F_15 ( F_149 ( V_122 , F_119 ( V_122 ) ) ) ;
F_15 ( F_149 ( V_121 , F_119 ( V_121 ) ) ) ;
F_15 ( F_149 ( V_145 , F_119 ( V_145 ) ) ) ;
for ( V_126 = 0 ; V_126 < F_119 ( V_145 ) ; V_126 ++ )
V_145 [ V_126 ] . V_127 ( NULL , & V_145 [ V_126 ] ) ;
F_151 ( NULL , & V_175 ) ;
V_152 = V_175 . V_27 ;
for ( V_126 = 0 ; V_126 < 7 ; V_126 ++ )
if ( ( ( V_152 >> ( V_126 * 3 ) ) & 7 ) == 0 )
break;
V_152 &= ( 1 << ( V_126 * 3 ) ) - 1 ;
}
void F_152 ( struct V_1 * V_2 )
{
T_5 V_97 ;
const struct V_10 * V_94 ;
memset ( & V_2 -> V_18 . V_176 . V_177 , 0x42 , sizeof( V_2 -> V_18 . V_176 . V_177 ) ) ;
F_124 ( V_2 , V_125 , F_119 ( V_125 ) ) ;
V_94 = F_97 ( V_2 -> V_18 . V_92 , true , & V_97 ) ;
F_124 ( V_2 , V_94 , V_97 ) ;
for ( V_97 = 1 ; V_97 < V_178 ; V_97 ++ )
if ( F_16 ( V_2 , V_97 ) == 0x4242424242424242 )
F_153 ( L_5 , V_97 ) ;
}
