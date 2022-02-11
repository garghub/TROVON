static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
F_2 () ;
F_3 ( V_1 , V_3 ) ;
F_4 () ;
V_2 = F_5 ( V_4 ) ;
F_6 () ;
return V_2 ;
}
static bool F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( ! V_8 -> V_11 )
return F_8 ( V_6 , V_8 ) ;
F_9 ( V_6 ) ;
return true ;
}
static bool F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
bool V_12 = F_11 ( V_6 ) ;
F_12 ( ! V_8 -> V_11 ) ;
if ( ! V_8 -> V_13 ) {
F_13 ( V_6 , V_10 -> V_14 ) = V_8 -> V_15 ;
} else {
if ( ! V_8 -> V_16 )
F_14 ( V_6 , V_10 -> V_14 ) = F_15 ( V_8 -> V_15 ) ;
F_16 ( V_6 , V_10 -> V_14 ) = F_17 ( V_8 -> V_15 ) ;
}
F_18 ( V_6 , V_12 ) ;
return true ;
}
static bool F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( ! V_8 -> V_11 )
return F_8 ( V_6 , V_8 ) ;
F_20 ( V_6 , V_8 -> V_15 ) ;
return true ;
}
static bool F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 )
return F_22 ( V_6 , V_8 ) ;
V_8 -> V_15 = V_6 -> V_17 . V_18 . V_19 . V_20 ;
return true ;
}
static bool F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 )
return F_22 ( V_6 , V_8 ) ;
else
return F_24 ( V_6 , V_8 ) ;
}
static bool F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
return F_22 ( V_6 , V_8 ) ;
} else {
V_8 -> V_15 = ( 1 << 3 ) ;
return true ;
}
}
static bool F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
return F_22 ( V_6 , V_8 ) ;
} else {
V_8 -> V_15 = F_5 ( V_21 ) ;
return true ;
}
}
static bool F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
F_13 ( V_6 , V_10 -> V_14 ) = V_8 -> V_15 ;
V_6 -> V_17 . V_22 |= V_23 ;
} else {
V_8 -> V_15 = F_13 ( V_6 , V_10 -> V_14 ) ;
}
F_28 ( V_24 , V_10 -> V_14 , V_8 -> V_11 , V_8 -> V_15 ) ;
return true ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_2 * V_25 )
{
T_2 V_26 = V_8 -> V_15 ;
if ( V_8 -> V_16 ) {
V_26 &= 0xffffffffUL ;
V_26 |= ( ( * V_25 >> 32 ) << 32 ) ;
}
* V_25 = V_26 ;
V_6 -> V_17 . V_22 |= V_23 ;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_2 * V_25 )
{
V_8 -> V_15 = * V_25 ;
if ( V_8 -> V_16 )
V_8 -> V_15 &= 0xffffffffUL ;
}
static bool F_31 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_27 )
{
T_2 * V_25 = & V_6 -> V_17 . V_28 . V_29 [ V_27 -> V_14 ] ;
if ( V_8 -> V_11 )
F_29 ( V_6 , V_8 , V_25 ) ;
else
F_30 ( V_6 , V_8 , V_25 ) ;
F_28 ( V_24 , V_27 -> V_14 , V_8 -> V_11 , * V_25 ) ;
return true ;
}
static int F_32 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_29 [ V_27 -> V_14 ] ;
if ( F_33 ( V_10 , V_31 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_29 [ V_27 -> V_14 ] ;
if ( F_36 ( V_31 , V_10 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static void F_37 ( struct V_5 * V_6 ,
const struct V_9 * V_27 )
{
V_6 -> V_17 . V_28 . V_29 [ V_27 -> V_14 ] = V_27 -> V_26 ;
}
static bool F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_27 )
{
T_2 * V_25 = & V_6 -> V_17 . V_28 . V_34 [ V_27 -> V_14 ] ;
if ( V_8 -> V_11 )
F_29 ( V_6 , V_8 , V_25 ) ;
else
F_30 ( V_6 , V_8 , V_25 ) ;
F_28 ( V_24 , V_27 -> V_14 , V_8 -> V_11 , * V_25 ) ;
return true ;
}
static int F_39 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_34 [ V_27 -> V_14 ] ;
if ( F_33 ( V_10 , V_31 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_34 [ V_27 -> V_14 ] ;
if ( F_36 ( V_31 , V_10 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 ,
const struct V_9 * V_27 )
{
V_6 -> V_17 . V_28 . V_34 [ V_27 -> V_14 ] = V_27 -> V_26 ;
}
static bool F_42 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_27 )
{
T_2 * V_25 = & V_6 -> V_17 . V_28 . V_35 [ V_27 -> V_14 ] ;
if ( V_8 -> V_11 )
F_29 ( V_6 , V_8 , V_25 ) ;
else
F_30 ( V_6 , V_8 , V_25 ) ;
F_28 ( V_24 , V_27 -> V_14 , V_8 -> V_11 ,
V_6 -> V_17 . V_28 . V_35 [ V_27 -> V_14 ] ) ;
return true ;
}
static int F_43 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_35 [ V_27 -> V_14 ] ;
if ( F_33 ( V_10 , V_31 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_35 [ V_27 -> V_14 ] ;
if ( F_36 ( V_31 , V_10 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static void F_45 ( struct V_5 * V_6 ,
const struct V_9 * V_27 )
{
V_6 -> V_17 . V_28 . V_35 [ V_27 -> V_14 ] = V_27 -> V_26 ;
}
static bool F_46 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_27 )
{
T_2 * V_25 = & V_6 -> V_17 . V_28 . V_36 [ V_27 -> V_14 ] ;
if ( V_8 -> V_11 )
F_29 ( V_6 , V_8 , V_25 ) ;
else
F_30 ( V_6 , V_8 , V_25 ) ;
F_28 ( V_24 , V_27 -> V_14 , V_8 -> V_11 , * V_25 ) ;
return true ;
}
static int F_47 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_36 [ V_27 -> V_14 ] ;
if ( F_33 ( V_10 , V_31 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , const struct V_9 * V_27 ,
const struct V_30 * V_14 , void T_3 * V_31 )
{
T_4 * V_10 = & V_6 -> V_17 . V_28 . V_36 [ V_27 -> V_14 ] ;
if ( F_36 ( V_31 , V_10 , F_34 ( V_14 -> V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 ,
const struct V_9 * V_27 )
{
V_6 -> V_17 . V_28 . V_36 [ V_27 -> V_14 ] = V_27 -> V_26 ;
}
static void F_50 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
F_13 ( V_6 , V_37 ) = F_5 ( V_38 ) ;
}
static void F_51 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
T_2 V_39 ;
V_39 = ( V_6 -> V_40 & 0x0f ) << F_52 ( 0 ) ;
V_39 |= ( ( V_6 -> V_40 >> 4 ) & 0xff ) << F_52 ( 1 ) ;
V_39 |= ( ( V_6 -> V_40 >> 12 ) & 0xff ) << F_52 ( 2 ) ;
F_13 ( V_6 , V_41 ) = ( 1ULL << 31 ) | V_39 ;
}
static void F_53 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
T_2 V_42 , V_26 ;
V_42 = F_5 ( V_43 ) ;
V_26 = ( ( V_42 & ~ V_44 )
| ( V_44 & 0xdecafbad ) ) & ( ~ V_45 ) ;
F_13 ( V_6 , V_46 ) = V_26 ;
}
static bool F_54 ( struct V_5 * V_6 )
{
T_2 V_14 = F_13 ( V_6 , V_47 ) ;
return ! ( ( V_14 & V_48 ) || F_55 ( V_6 ) ) ;
}
static bool F_56 ( struct V_5 * V_6 )
{
T_2 V_14 = F_13 ( V_6 , V_47 ) ;
return ! ( ( V_14 & ( V_49 | V_48 ) )
|| F_55 ( V_6 ) ) ;
}
static bool F_57 ( struct V_5 * V_6 )
{
T_2 V_14 = F_13 ( V_6 , V_47 ) ;
return ! ( ( V_14 & ( V_50 | V_48 ) )
|| F_55 ( V_6 ) ) ;
}
static bool F_58 ( struct V_5 * V_6 )
{
T_2 V_14 = F_13 ( V_6 , V_47 ) ;
return ! ( ( V_14 & ( V_51 | V_48 ) )
|| F_55 ( V_6 ) ) ;
}
static bool F_59 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_26 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_54 ( V_6 ) )
return false ;
if ( V_8 -> V_11 ) {
V_26 = F_13 ( V_6 , V_46 ) ;
V_26 &= ~ V_44 ;
V_26 |= V_8 -> V_15 & V_44 ;
F_13 ( V_6 , V_46 ) = V_26 ;
F_61 ( V_6 , V_26 ) ;
} else {
V_26 = F_13 ( V_6 , V_46 )
& ~ ( V_52 | V_53 ) ;
V_8 -> V_15 = V_26 ;
}
return true ;
}
static bool F_62 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_58 ( V_6 ) )
return false ;
if ( V_8 -> V_11 )
F_13 ( V_6 , V_54 ) = V_8 -> V_15 ;
else
V_8 -> V_15 = F_13 ( V_6 , V_54 )
& V_55 ;
return true ;
}
static bool F_63 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_56 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
F_12 ( V_8 -> V_11 ) ;
if ( F_54 ( V_6 ) )
return false ;
if ( ! ( V_8 -> V_57 & 1 ) )
V_56 = F_5 ( V_58 ) ;
else
V_56 = F_5 ( V_59 ) ;
V_8 -> V_15 = V_56 ;
return true ;
}
static bool F_64 ( struct V_5 * V_6 , T_2 V_60 )
{
T_2 V_42 , V_26 ;
V_42 = F_13 ( V_6 , V_46 ) ;
V_26 = ( V_42 >> V_61 ) & V_62 ;
if ( V_60 >= V_26 && V_60 != V_63 )
return false ;
return true ;
}
static bool F_65 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_60 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( V_10 -> V_64 == 9 && V_10 -> V_65 == 13 ) {
if ( V_10 -> V_57 == 2 ) {
if ( F_58 ( V_6 ) )
return false ;
V_60 = F_13 ( V_6 , V_54 )
& V_55 ;
} else if ( V_10 -> V_57 == 0 ) {
if ( F_57 ( V_6 ) )
return false ;
V_60 = V_63 ;
} else {
return false ;
}
} else if ( V_10 -> V_64 == 0 && V_10 -> V_65 == 9 ) {
if ( F_58 ( V_6 ) )
return false ;
V_60 = V_63 ;
} else if ( V_10 -> V_64 == 14 && ( V_10 -> V_65 & 12 ) == 8 ) {
if ( F_58 ( V_6 ) )
return false ;
V_60 = ( ( V_10 -> V_65 & 3 ) << 3 ) | ( V_10 -> V_57 & 7 ) ;
} else {
return false ;
}
if ( ! F_64 ( V_6 , V_60 ) )
return false ;
if ( V_8 -> V_11 ) {
if ( F_54 ( V_6 ) )
return false ;
F_66 ( V_6 , V_60 , V_8 -> V_15 ) ;
} else {
V_8 -> V_15 = F_67 ( V_6 , V_60 ) ;
}
return true ;
}
static bool F_68 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_60 , V_14 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_54 ( V_6 ) )
return false ;
if ( V_10 -> V_64 == 9 && V_10 -> V_65 == 13 && V_10 -> V_57 == 1 ) {
V_60 = F_13 ( V_6 , V_54 ) & V_55 ;
V_14 = V_66 + V_60 ;
} else if ( V_10 -> V_64 == 14 && ( V_10 -> V_65 & 12 ) == 12 ) {
V_60 = ( ( V_10 -> V_65 & 3 ) << 3 ) | ( V_10 -> V_57 & 7 ) ;
if ( V_60 == V_63 )
V_14 = V_67 ;
else
V_14 = V_66 + V_60 ;
} else {
F_69 () ;
}
if ( ! F_64 ( V_6 , V_60 ) )
return false ;
if ( V_8 -> V_11 ) {
F_70 ( V_6 , V_8 -> V_15 , V_60 ) ;
F_13 ( V_6 , V_14 ) = V_8 -> V_15 & V_68 ;
} else {
V_8 -> V_15 = F_13 ( V_6 , V_14 ) & V_68 ;
}
return true ;
}
static bool F_71 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_26 , V_69 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_54 ( V_6 ) )
return false ;
V_69 = F_72 ( V_6 ) ;
if ( V_8 -> V_11 ) {
V_26 = V_8 -> V_15 & V_69 ;
if ( V_10 -> V_57 & 0x1 ) {
F_13 ( V_6 , V_70 ) |= V_26 ;
F_73 ( V_6 , V_26 ) ;
} else {
F_13 ( V_6 , V_70 ) &= ~ V_26 ;
F_74 ( V_6 , V_26 ) ;
}
} else {
V_8 -> V_15 = F_13 ( V_6 , V_70 ) & V_69 ;
}
return true ;
}
static bool F_75 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_69 = F_72 ( V_6 ) ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( ! F_55 ( V_6 ) )
return false ;
if ( V_8 -> V_11 ) {
T_2 V_26 = V_8 -> V_15 & V_69 ;
if ( V_10 -> V_57 & 0x1 )
F_13 ( V_6 , V_71 ) |= V_26 ;
else
F_13 ( V_6 , V_71 ) &= ~ V_26 ;
} else {
V_8 -> V_15 = F_13 ( V_6 , V_71 ) & V_69 ;
}
return true ;
}
static bool F_76 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_69 = F_72 ( V_6 ) ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_54 ( V_6 ) )
return false ;
if ( V_8 -> V_11 ) {
if ( V_10 -> V_65 & 0x2 )
F_77 ( V_6 , V_8 -> V_15 & V_69 ) ;
else
F_13 ( V_6 , V_72 ) &= ~ ( V_8 -> V_15 & V_69 ) ;
} else {
V_8 -> V_15 = F_13 ( V_6 , V_72 ) & V_69 ;
}
return true ;
}
static bool F_78 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
T_2 V_69 ;
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( F_56 ( V_6 ) )
return false ;
if ( V_8 -> V_11 ) {
V_69 = F_72 ( V_6 ) ;
F_79 ( V_6 , V_8 -> V_15 & V_69 ) ;
return true ;
}
return false ;
}
static bool F_80 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( ! F_60 ( V_6 ) )
return F_23 ( V_6 , V_8 , V_10 ) ;
if ( V_8 -> V_11 ) {
if ( ! F_55 ( V_6 ) )
return false ;
F_13 ( V_6 , V_47 ) = V_8 -> V_15
& V_73 ;
} else {
V_8 -> V_15 = F_13 ( V_6 , V_47 )
& V_73 ;
}
return true ;
}
static bool F_81 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_74 * V_75 = F_82 ( V_6 ) ;
T_2 V_76 = F_83 () ;
if ( V_8 -> V_11 )
V_75 -> V_77 = V_8 -> V_15 + V_76 ;
else
V_8 -> V_15 = V_75 -> V_77 - V_76 ;
return true ;
}
static bool F_84 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_74 * V_75 = F_82 ( V_6 ) ;
if ( V_8 -> V_11 ) {
V_75 -> V_78 = V_8 -> V_15 & ~ V_79 ;
} else {
T_2 V_76 = F_83 () ;
V_8 -> V_15 = V_75 -> V_78 ;
if ( V_75 -> V_77 <= V_76 )
V_8 -> V_15 |= V_79 ;
}
return true ;
}
static bool F_85 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_74 * V_75 = F_82 ( V_6 ) ;
if ( V_8 -> V_11 )
V_75 -> V_77 = V_8 -> V_15 ;
else
V_8 -> V_15 = V_75 -> V_77 ;
return true ;
}
static bool F_86 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
return F_22 ( V_6 , V_8 ) ;
} else {
T_2 V_80 = F_87 ( V_81 ) ;
T_2 V_82 = F_87 ( V_83 ) ;
T_1 V_84 = ! ! F_88 ( V_82 , V_85 ) ;
V_8 -> V_15 = ( ( ( ( V_80 >> V_86 ) & 0xf ) << 28 ) |
( ( ( V_80 >> V_87 ) & 0xf ) << 24 ) |
( ( ( V_80 >> V_88 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_84 << 14 ) | ( V_84 << 12 ) ) ;
return true ;
}
}
static bool F_89 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
F_90 ( V_6 , V_10 -> V_14 ) = V_8 -> V_15 ;
V_6 -> V_17 . V_22 |= V_23 ;
} else {
V_8 -> V_15 = F_90 ( V_6 , V_10 -> V_14 ) ;
}
return true ;
}
static bool F_91 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_27 )
{
T_2 * V_25 = & V_6 -> V_17 . V_28 . V_29 [ V_27 -> V_14 ] ;
if ( V_8 -> V_11 ) {
T_2 V_26 = * V_25 ;
V_26 &= 0xffffffffUL ;
V_26 |= V_8 -> V_15 << 32 ;
* V_25 = V_26 ;
V_6 -> V_17 . V_22 |= V_23 ;
} else {
V_8 -> V_15 = * V_25 >> 32 ;
}
F_28 ( V_24 , V_27 -> V_14 , V_8 -> V_11 , * V_25 ) ;
return true ;
}
void F_92 ( unsigned int V_89 ,
struct V_90 * V_91 )
{
V_92 [ V_89 ] = V_91 ;
}
static const struct V_9 * F_93 ( unsigned V_89 ,
bool V_93 ,
T_5 * V_94 )
{
struct V_90 * V_91 ;
V_91 = V_92 [ V_89 ] ;
if ( V_93 ) {
* V_94 = V_91 -> V_95 . V_94 ;
return V_91 -> V_95 . V_91 ;
} else {
* V_94 = V_91 -> V_96 . V_94 ;
return V_91 -> V_96 . V_91 ;
}
}
static int F_94 ( const void * V_97 , const void * V_98 )
{
const unsigned long V_99 = ( unsigned long ) V_97 ;
const struct V_9 * V_10 = V_98 ;
return V_99 - F_95 ( V_10 ) ;
}
static const struct V_9 * F_96 ( const struct V_7 * V_100 ,
const struct V_9 V_91 [] ,
unsigned int V_94 )
{
unsigned long V_99 = F_95 ( V_100 ) ;
return bsearch ( ( void * ) V_99 , V_91 , V_94 , sizeof( V_91 [ 0 ] ) , F_94 ) ;
}
int F_97 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
F_98 ( V_6 ) ;
return 1 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_7 * V_100 ,
const struct V_9 * V_91 ,
T_5 V_94 )
{
const struct V_9 * V_10 ;
if ( ! V_91 )
return - 1 ;
V_10 = F_96 ( V_100 , V_91 , V_94 ) ;
if ( V_10 ) {
F_12 ( ! V_10 -> V_103 ) ;
if ( F_100 ( V_10 -> V_103 ( V_6 , V_100 , V_10 ) ) ) {
F_101 ( V_6 , F_102 ( V_6 ) ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_103 ( struct V_5 * V_6 ,
struct V_7 * V_100 )
{
T_6 V_104 = F_104 ( V_6 ) ;
int V_105 = - 1 ;
switch( V_104 ) {
case V_106 :
case V_107 :
V_105 = 15 ;
break;
case V_108 :
case V_109 :
V_105 = 14 ;
break;
default:
F_105 ( 1 ) ;
}
F_106 ( L_1 ,
V_105 , * F_107 ( V_6 ) ) ;
F_108 ( V_100 ) ;
F_98 ( V_6 ) ;
}
static int F_109 ( struct V_5 * V_6 ,
const struct V_9 * V_110 ,
T_5 V_111 ,
const struct V_9 * V_112 ,
T_5 V_113 )
{
struct V_7 V_100 ;
T_1 V_114 = F_110 ( V_6 ) ;
int V_115 = ( V_114 >> 5 ) & 0xf ;
int V_116 = ( V_114 >> 10 ) & 0xf ;
V_100 . V_13 = true ;
V_100 . V_16 = false ;
V_100 . V_65 = ( V_114 >> 1 ) & 0xf ;
V_100 . V_11 = ( ( V_114 & 1 ) == 0 ) ;
V_100 . V_117 = 0 ;
V_100 . V_118 = ( V_114 >> 16 ) & 0xf ;
V_100 . V_57 = 0 ;
V_100 . V_64 = 0 ;
if ( V_100 . V_11 ) {
V_100 . V_15 = F_111 ( V_6 , V_115 ) & 0xffffffff ;
V_100 . V_15 |= F_111 ( V_6 , V_116 ) << 32 ;
}
if ( ! F_99 ( V_6 , & V_100 , V_112 , V_113 ) )
goto V_119;
if ( ! F_99 ( V_6 , & V_100 , V_110 , V_111 ) )
goto V_119;
F_103 ( V_6 , & V_100 ) ;
V_119:
if ( ! V_100 . V_11 ) {
F_112 ( V_6 , V_115 , F_17 ( V_100 . V_15 ) ) ;
F_112 ( V_6 , V_116 , F_15 ( V_100 . V_15 ) ) ;
}
return 1 ;
}
static int F_113 ( struct V_5 * V_6 ,
const struct V_9 * V_110 ,
T_5 V_111 ,
const struct V_9 * V_112 ,
T_5 V_113 )
{
struct V_7 V_100 ;
T_1 V_114 = F_110 ( V_6 ) ;
int V_115 = ( V_114 >> 5 ) & 0xf ;
V_100 . V_13 = true ;
V_100 . V_16 = true ;
V_100 . V_65 = ( V_114 >> 1 ) & 0xf ;
V_100 . V_15 = F_111 ( V_6 , V_115 ) ;
V_100 . V_11 = ( ( V_114 & 1 ) == 0 ) ;
V_100 . V_64 = ( V_114 >> 10 ) & 0xf ;
V_100 . V_117 = 0 ;
V_100 . V_118 = ( V_114 >> 14 ) & 0x7 ;
V_100 . V_57 = ( V_114 >> 17 ) & 0x7 ;
if ( ! F_99 ( V_6 , & V_100 , V_112 , V_113 ) ||
! F_99 ( V_6 , & V_100 , V_110 , V_111 ) ) {
if ( ! V_100 . V_11 )
F_112 ( V_6 , V_115 , V_100 . V_15 ) ;
return 1 ;
}
F_103 ( V_6 , & V_100 ) ;
return 1 ;
}
int F_114 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
const struct V_9 * V_112 ;
T_5 V_94 ;
V_112 = F_93 ( V_6 -> V_17 . V_89 , false , & V_94 ) ;
return F_109 ( V_6 ,
V_120 , F_115 ( V_120 ) ,
V_112 , V_94 ) ;
}
int F_116 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
const struct V_9 * V_112 ;
T_5 V_94 ;
V_112 = F_93 ( V_6 -> V_17 . V_89 , false , & V_94 ) ;
return F_113 ( V_6 ,
V_121 , F_115 ( V_121 ) ,
V_112 , V_94 ) ;
}
int F_117 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
return F_109 ( V_6 ,
V_122 , F_115 ( V_122 ) ,
NULL , 0 ) ;
}
int F_118 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
return F_113 ( V_6 ,
V_123 , F_115 ( V_123 ) ,
NULL , 0 ) ;
}
static int F_119 ( struct V_5 * V_6 ,
struct V_7 * V_100 )
{
T_5 V_94 ;
const struct V_9 * V_91 , * V_10 ;
V_91 = F_93 ( V_6 -> V_17 . V_89 , true , & V_94 ) ;
V_10 = F_96 ( V_100 , V_91 , V_94 ) ;
if ( ! V_10 )
V_10 = F_96 ( V_100 , V_124 , F_115 ( V_124 ) ) ;
if ( F_100 ( V_10 ) ) {
F_12 ( ! V_10 -> V_103 ) ;
if ( F_100 ( V_10 -> V_103 ( V_6 , V_100 , V_10 ) ) ) {
F_101 ( V_6 , F_102 ( V_6 ) ) ;
return 1 ;
}
} else {
F_106 ( L_2 ,
* F_107 ( V_6 ) ) ;
F_108 ( V_100 ) ;
}
F_98 ( V_6 ) ;
return 1 ;
}
static void F_120 ( struct V_5 * V_6 ,
const struct V_9 * V_91 , T_5 V_94 )
{
unsigned long V_125 ;
for ( V_125 = 0 ; V_125 < V_94 ; V_125 ++ )
if ( V_91 [ V_125 ] . V_126 )
V_91 [ V_125 ] . V_126 ( V_6 , & V_91 [ V_125 ] ) ;
}
int F_121 ( struct V_5 * V_6 , struct V_101 * V_102 )
{
struct V_7 V_100 ;
unsigned long V_127 = F_110 ( V_6 ) ;
int V_115 = ( V_127 >> 5 ) & 0x1f ;
int V_128 ;
F_122 ( V_127 ) ;
V_100 . V_13 = false ;
V_100 . V_16 = false ;
V_100 . V_117 = ( V_127 >> 20 ) & 3 ;
V_100 . V_118 = ( V_127 >> 14 ) & 0x7 ;
V_100 . V_64 = ( V_127 >> 10 ) & 0xf ;
V_100 . V_65 = ( V_127 >> 1 ) & 0xf ;
V_100 . V_57 = ( V_127 >> 17 ) & 0x7 ;
V_100 . V_15 = F_111 ( V_6 , V_115 ) ;
V_100 . V_11 = ! ( V_127 & 1 ) ;
V_128 = F_119 ( V_6 , & V_100 ) ;
if ( ! V_100 . V_11 )
F_112 ( V_6 , V_115 , V_100 . V_15 ) ;
return V_128 ;
}
static bool F_123 ( T_2 V_32 , struct V_7 * V_100 )
{
switch ( V_32 & V_129 ) {
case V_130 :
if ( V_32 & ~ ( V_131 | V_129
| V_132
| V_133
| V_134
| V_135
| V_136
| V_137 ) )
return false ;
V_100 -> V_117 = ( ( V_32 & V_133 )
>> V_138 ) ;
V_100 -> V_118 = ( ( V_32 & V_134 )
>> V_139 ) ;
V_100 -> V_64 = ( ( V_32 & V_135 )
>> V_140 ) ;
V_100 -> V_65 = ( ( V_32 & V_136 )
>> V_141 ) ;
V_100 -> V_57 = ( ( V_32 & V_137 )
>> V_142 ) ;
return true ;
default:
return false ;
}
}
const struct V_9 * F_124 ( T_2 V_32 ,
struct V_7 * V_100 ,
const struct V_9 V_91 [] ,
unsigned int V_94 )
{
if ( ! F_123 ( V_32 , V_100 ) )
return NULL ;
return F_96 ( V_100 , V_91 , V_94 ) ;
}
static const struct V_9 * F_125 ( struct V_5 * V_6 ,
T_2 V_32 )
{
T_5 V_94 ;
const struct V_9 * V_91 , * V_10 ;
struct V_7 V_100 ;
if ( ( V_32 & V_132 ) != V_143 )
return NULL ;
V_91 = F_93 ( V_6 -> V_17 . V_89 , true , & V_94 ) ;
V_10 = F_124 ( V_32 , & V_100 , V_91 , V_94 ) ;
if ( ! V_10 )
V_10 = F_96 ( & V_100 , V_124 , F_115 ( V_124 ) ) ;
if ( V_10 && ! V_10 -> V_14 )
V_10 = NULL ;
return V_10 ;
}
static int F_126 ( T_2 * V_26 , const void T_3 * V_31 , T_2 V_32 )
{
if ( F_33 ( V_26 , V_31 , F_34 ( V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_127 ( void T_3 * V_31 , const T_2 * V_26 , T_2 V_32 )
{
if ( F_36 ( V_31 , V_26 , F_34 ( V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_128 ( T_2 V_32 , void T_3 * V_31 )
{
struct V_7 V_100 ;
const struct V_9 * V_10 ;
V_10 = F_124 ( V_32 , & V_100 , V_144 ,
F_115 ( V_144 ) ) ;
if ( ! V_10 )
return - V_145 ;
return F_127 ( V_31 , & V_10 -> V_26 , V_32 ) ;
}
static int F_129 ( T_2 V_32 , void T_3 * V_31 )
{
struct V_7 V_100 ;
const struct V_9 * V_10 ;
int V_146 ;
T_2 V_26 = 0 ;
V_10 = F_124 ( V_32 , & V_100 , V_144 ,
F_115 ( V_144 ) ) ;
if ( ! V_10 )
return - V_145 ;
V_146 = F_126 ( & V_26 , V_31 , V_32 ) ;
if ( V_146 )
return V_146 ;
if ( V_10 -> V_26 != V_26 )
return - V_147 ;
return 0 ;
}
static bool F_130 ( T_1 V_26 )
{
T_1 V_148 , V_149 ;
if ( V_26 >= V_150 )
return false ;
V_148 = ( V_26 >> 1 ) ;
V_149 = ( V_151 >> ( V_148 * 3 ) ) & 7 ;
switch ( V_149 ) {
case 0 :
return false ;
case 1 :
return ( V_26 & 1 ) ;
case 2 :
case 4 :
return ! ( V_26 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_131 ( T_2 V_32 , void T_3 * V_31 )
{
T_1 V_26 ;
T_1 T_3 * V_152 = V_31 ;
if ( V_32 & ~ ( V_131 | V_129 | V_132
| ( ( 1 << V_153 ) - 1 ) ) )
return - V_145 ;
switch ( V_32 & V_154 ) {
case V_155 :
if ( F_34 ( V_32 ) != 4 )
return - V_145 ;
V_26 = ( V_32 & V_156 )
>> V_157 ;
if ( ! F_130 ( V_26 ) )
return - V_145 ;
return F_132 ( F_1 ( V_26 ) , V_152 ) ;
default:
return - V_145 ;
}
}
static int F_133 ( T_2 V_32 , void T_3 * V_31 )
{
T_1 V_26 , V_158 ;
T_1 T_3 * V_152 = V_31 ;
if ( V_32 & ~ ( V_131 | V_129 | V_132
| ( ( 1 << V_153 ) - 1 ) ) )
return - V_145 ;
switch ( V_32 & V_154 ) {
case V_155 :
if ( F_34 ( V_32 ) != 4 )
return - V_145 ;
V_26 = ( V_32 & V_156 )
>> V_157 ;
if ( ! F_130 ( V_26 ) )
return - V_145 ;
if ( F_134 ( V_158 , V_152 ) )
return - V_33 ;
if ( V_158 != F_1 ( V_26 ) )
return - V_147 ;
return 0 ;
default:
return - V_145 ;
}
}
int F_135 ( struct V_5 * V_6 , const struct V_30 * V_14 )
{
const struct V_9 * V_10 ;
void T_3 * V_31 = ( void T_3 * ) ( unsigned long ) V_14 -> V_159 ;
if ( ( V_14 -> V_32 & V_132 ) == V_160 )
return F_131 ( V_14 -> V_32 , V_31 ) ;
if ( F_34 ( V_14 -> V_32 ) != sizeof( T_4 ) )
return - V_145 ;
V_10 = F_125 ( V_6 , V_14 -> V_32 ) ;
if ( ! V_10 )
return F_128 ( V_14 -> V_32 , V_31 ) ;
if ( V_10 -> F_134 )
return ( V_10 -> F_134 ) ( V_6 , V_10 , V_14 , V_31 ) ;
return F_127 ( V_31 , & F_13 ( V_6 , V_10 -> V_14 ) , V_14 -> V_32 ) ;
}
int F_136 ( struct V_5 * V_6 , const struct V_30 * V_14 )
{
const struct V_9 * V_10 ;
void T_3 * V_31 = ( void T_3 * ) ( unsigned long ) V_14 -> V_159 ;
if ( ( V_14 -> V_32 & V_132 ) == V_160 )
return F_133 ( V_14 -> V_32 , V_31 ) ;
if ( F_34 ( V_14 -> V_32 ) != sizeof( T_4 ) )
return - V_145 ;
V_10 = F_125 ( V_6 , V_14 -> V_32 ) ;
if ( ! V_10 )
return F_129 ( V_14 -> V_32 , V_31 ) ;
if ( V_10 -> V_161 )
return ( V_10 -> V_161 ) ( V_6 , V_10 , V_14 , V_31 ) ;
return F_126 ( & F_13 ( V_6 , V_10 -> V_14 ) , V_31 , V_14 -> V_32 ) ;
}
static unsigned int F_137 ( void )
{
unsigned int V_125 , V_162 = 0 ;
for ( V_125 = 0 ; V_125 < V_150 ; V_125 ++ )
if ( F_130 ( V_125 ) )
V_162 ++ ;
return V_162 ;
}
static int F_138 ( T_2 T_3 * V_163 )
{
T_2 V_26 = V_164 | V_165 | V_160 ;
unsigned int V_125 ;
V_26 |= V_155 ;
for ( V_125 = 0 ; V_125 < V_150 ; V_125 ++ ) {
if ( ! F_130 ( V_125 ) )
continue;
if ( F_132 ( V_26 | V_125 , V_163 ) )
return - V_33 ;
V_163 ++ ;
}
return 0 ;
}
static T_2 F_139 ( const struct V_9 * V_14 )
{
return ( V_164 | V_130 |
V_143 |
( V_14 -> V_117 << V_138 ) |
( V_14 -> V_118 << V_139 ) |
( V_14 -> V_64 << V_140 ) |
( V_14 -> V_65 << V_141 ) |
( V_14 -> V_57 << V_142 ) ) ;
}
static bool F_140 ( const struct V_9 * V_14 , T_2 T_3 * * V_166 )
{
if ( ! * V_166 )
return true ;
if ( F_132 ( F_139 ( V_14 ) , * V_166 ) )
return false ;
( * V_166 ) ++ ;
return true ;
}
static int F_141 ( struct V_5 * V_6 , T_2 T_3 * V_166 )
{
const struct V_9 * V_167 , * V_168 , * V_169 , * V_170 ;
unsigned int V_171 = 0 ;
T_5 V_94 ;
V_167 = F_93 ( V_6 -> V_17 . V_89 , true , & V_94 ) ;
V_169 = V_167 + V_94 ;
V_168 = V_124 ;
V_170 = V_124 + F_115 ( V_124 ) ;
F_12 ( V_167 == V_169 || V_168 == V_170 ) ;
while ( V_167 || V_168 ) {
int V_172 = F_142 ( V_167 , V_168 ) ;
if ( V_172 <= 0 ) {
if ( V_167 -> V_14 ) {
if ( ! F_140 ( V_167 , & V_166 ) )
return - V_33 ;
V_171 ++ ;
}
} else {
if ( V_168 -> V_14 ) {
if ( ! F_140 ( V_168 , & V_166 ) )
return - V_33 ;
V_171 ++ ;
}
}
if ( V_172 <= 0 && ++ V_167 == V_169 )
V_167 = NULL ;
if ( V_172 >= 0 && ++ V_168 == V_170 )
V_168 = NULL ;
}
return V_171 ;
}
unsigned long F_143 ( struct V_5 * V_6 )
{
return F_115 ( V_144 )
+ F_137 ()
+ F_141 ( V_6 , ( T_2 T_3 * ) NULL ) ;
}
int F_144 ( struct V_5 * V_6 , T_2 T_3 * V_163 )
{
unsigned int V_125 ;
int V_146 ;
for ( V_125 = 0 ; V_125 < F_115 ( V_144 ) ; V_125 ++ ) {
if ( F_132 ( F_139 ( & V_144 [ V_125 ] ) , V_163 ) )
return - V_33 ;
V_163 ++ ;
}
V_146 = F_141 ( V_6 , V_163 ) ;
if ( V_146 < 0 )
return V_146 ;
V_163 += V_146 ;
return F_138 ( V_163 ) ;
}
static int F_145 ( const struct V_9 * V_91 , unsigned int V_173 )
{
unsigned int V_125 ;
for ( V_125 = 1 ; V_125 < V_173 ; V_125 ++ ) {
if ( F_142 ( & V_91 [ V_125 - 1 ] , & V_91 [ V_125 ] ) >= 0 ) {
F_106 ( L_3 , V_91 , V_125 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_146 ( void )
{
unsigned int V_125 ;
struct V_9 V_174 ;
F_12 ( F_145 ( V_124 , F_115 ( V_124 ) ) ) ;
F_12 ( F_145 ( V_123 , F_115 ( V_123 ) ) ) ;
F_12 ( F_145 ( V_122 , F_115 ( V_122 ) ) ) ;
F_12 ( F_145 ( V_121 , F_115 ( V_121 ) ) ) ;
F_12 ( F_145 ( V_120 , F_115 ( V_120 ) ) ) ;
F_12 ( F_145 ( V_144 , F_115 ( V_144 ) ) ) ;
for ( V_125 = 0 ; V_125 < F_115 ( V_144 ) ; V_125 ++ )
V_144 [ V_125 ] . V_126 ( NULL , & V_144 [ V_125 ] ) ;
F_147 ( NULL , & V_174 ) ;
V_151 = V_174 . V_26 ;
for ( V_125 = 0 ; V_125 < 7 ; V_125 ++ )
if ( ( ( V_151 >> ( V_125 * 3 ) ) & 7 ) == 0 )
break;
V_151 &= ( 1 << ( V_125 * 3 ) ) - 1 ;
}
void F_148 ( struct V_5 * V_6 )
{
T_5 V_94 ;
const struct V_9 * V_91 ;
memset ( & V_6 -> V_17 . V_175 . V_176 , 0x42 , sizeof( V_6 -> V_17 . V_175 . V_176 ) ) ;
F_120 ( V_6 , V_124 , F_115 ( V_124 ) ) ;
V_91 = F_93 ( V_6 -> V_17 . V_89 , true , & V_94 ) ;
F_120 ( V_6 , V_91 , V_94 ) ;
for ( V_94 = 1 ; V_94 < V_177 ; V_94 ++ )
if ( F_13 ( V_6 , V_94 ) == 0x4242424242424242 )
F_149 ( L_4 , V_94 ) ;
}
