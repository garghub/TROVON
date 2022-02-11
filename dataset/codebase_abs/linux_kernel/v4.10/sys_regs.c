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
if ( V_8 -> V_11 ) {
return F_22 ( V_6 , V_8 ) ;
} else {
T_2 V_74 = F_82 ( V_75 ) ;
T_2 V_76 = F_82 ( V_77 ) ;
T_1 V_78 = ! ! F_83 ( V_76 , V_79 ) ;
V_8 -> V_15 = ( ( ( ( V_74 >> V_80 ) & 0xf ) << 28 ) |
( ( ( V_74 >> V_81 ) & 0xf ) << 24 ) |
( ( ( V_74 >> V_82 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_78 << 14 ) | ( V_78 << 12 ) ) ;
return true ;
}
}
static bool F_84 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_11 ) {
F_85 ( V_6 , V_10 -> V_14 ) = V_8 -> V_15 ;
V_6 -> V_17 . V_22 |= V_23 ;
} else {
V_8 -> V_15 = F_85 ( V_6 , V_10 -> V_14 ) ;
}
return true ;
}
static bool F_86 ( struct V_5 * V_6 ,
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
void F_87 ( unsigned int V_83 ,
struct V_84 * V_85 )
{
V_86 [ V_83 ] = V_85 ;
}
static const struct V_9 * F_88 ( unsigned V_83 ,
bool V_87 ,
T_5 * V_88 )
{
struct V_84 * V_85 ;
V_85 = V_86 [ V_83 ] ;
if ( V_87 ) {
* V_88 = V_85 -> V_89 . V_88 ;
return V_85 -> V_89 . V_85 ;
} else {
* V_88 = V_85 -> V_90 . V_88 ;
return V_85 -> V_90 . V_85 ;
}
}
static int F_89 ( const void * V_91 , const void * V_92 )
{
const unsigned long V_93 = ( unsigned long ) V_91 ;
const struct V_9 * V_10 = V_92 ;
return V_93 - F_90 ( V_10 ) ;
}
static const struct V_9 * F_91 ( const struct V_7 * V_94 ,
const struct V_9 V_85 [] ,
unsigned int V_88 )
{
unsigned long V_93 = F_90 ( V_94 ) ;
return bsearch ( ( void * ) V_93 , V_85 , V_88 , sizeof( V_85 [ 0 ] ) , F_89 ) ;
}
int F_92 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
F_93 ( V_6 ) ;
return 1 ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_7 * V_94 ,
const struct V_9 * V_85 ,
T_5 V_88 )
{
const struct V_9 * V_10 ;
if ( ! V_85 )
return - 1 ;
V_10 = F_91 ( V_94 , V_85 , V_88 ) ;
if ( V_10 ) {
F_12 ( ! V_10 -> V_97 ) ;
if ( F_95 ( V_10 -> V_97 ( V_6 , V_94 , V_10 ) ) ) {
F_96 ( V_6 , F_97 ( V_6 ) ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_98 ( struct V_5 * V_6 ,
struct V_7 * V_94 )
{
T_6 V_98 = F_99 ( V_6 ) ;
int V_99 = - 1 ;
switch( V_98 ) {
case V_100 :
case V_101 :
V_99 = 15 ;
break;
case V_102 :
case V_103 :
V_99 = 14 ;
break;
default:
F_100 ( 1 ) ;
}
F_101 ( L_1 ,
V_99 , * F_102 ( V_6 ) ) ;
F_103 ( V_94 ) ;
F_93 ( V_6 ) ;
}
static int F_104 ( struct V_5 * V_6 ,
const struct V_9 * V_104 ,
T_5 V_105 ,
const struct V_9 * V_106 ,
T_5 V_107 )
{
struct V_7 V_94 ;
T_1 V_108 = F_105 ( V_6 ) ;
int V_109 = ( V_108 >> 5 ) & 0xf ;
int V_110 = ( V_108 >> 10 ) & 0xf ;
V_94 . V_13 = true ;
V_94 . V_16 = false ;
V_94 . V_65 = ( V_108 >> 1 ) & 0xf ;
V_94 . V_11 = ( ( V_108 & 1 ) == 0 ) ;
V_94 . V_111 = 0 ;
V_94 . V_112 = ( V_108 >> 16 ) & 0xf ;
V_94 . V_57 = 0 ;
V_94 . V_64 = 0 ;
if ( V_94 . V_11 ) {
V_94 . V_15 = F_106 ( V_6 , V_109 ) & 0xffffffff ;
V_94 . V_15 |= F_106 ( V_6 , V_110 ) << 32 ;
}
if ( ! F_94 ( V_6 , & V_94 , V_106 , V_107 ) )
goto V_113;
if ( ! F_94 ( V_6 , & V_94 , V_104 , V_105 ) )
goto V_113;
F_98 ( V_6 , & V_94 ) ;
V_113:
if ( ! V_94 . V_11 ) {
F_107 ( V_6 , V_109 , F_17 ( V_94 . V_15 ) ) ;
F_107 ( V_6 , V_110 , F_15 ( V_94 . V_15 ) ) ;
}
return 1 ;
}
static int F_108 ( struct V_5 * V_6 ,
const struct V_9 * V_104 ,
T_5 V_105 ,
const struct V_9 * V_106 ,
T_5 V_107 )
{
struct V_7 V_94 ;
T_1 V_108 = F_105 ( V_6 ) ;
int V_109 = ( V_108 >> 5 ) & 0xf ;
V_94 . V_13 = true ;
V_94 . V_16 = true ;
V_94 . V_65 = ( V_108 >> 1 ) & 0xf ;
V_94 . V_15 = F_106 ( V_6 , V_109 ) ;
V_94 . V_11 = ( ( V_108 & 1 ) == 0 ) ;
V_94 . V_64 = ( V_108 >> 10 ) & 0xf ;
V_94 . V_111 = 0 ;
V_94 . V_112 = ( V_108 >> 14 ) & 0x7 ;
V_94 . V_57 = ( V_108 >> 17 ) & 0x7 ;
if ( ! F_94 ( V_6 , & V_94 , V_106 , V_107 ) ||
! F_94 ( V_6 , & V_94 , V_104 , V_105 ) ) {
if ( ! V_94 . V_11 )
F_107 ( V_6 , V_109 , V_94 . V_15 ) ;
return 1 ;
}
F_98 ( V_6 , & V_94 ) ;
return 1 ;
}
int F_109 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
const struct V_9 * V_106 ;
T_5 V_88 ;
V_106 = F_88 ( V_6 -> V_17 . V_83 , false , & V_88 ) ;
return F_104 ( V_6 ,
V_114 , F_110 ( V_114 ) ,
V_106 , V_88 ) ;
}
int F_111 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
const struct V_9 * V_106 ;
T_5 V_88 ;
V_106 = F_88 ( V_6 -> V_17 . V_83 , false , & V_88 ) ;
return F_108 ( V_6 ,
V_115 , F_110 ( V_115 ) ,
V_106 , V_88 ) ;
}
int F_112 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
return F_104 ( V_6 ,
V_116 , F_110 ( V_116 ) ,
NULL , 0 ) ;
}
int F_113 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
return F_108 ( V_6 ,
V_117 , F_110 ( V_117 ) ,
NULL , 0 ) ;
}
static int F_114 ( struct V_5 * V_6 ,
struct V_7 * V_94 )
{
T_5 V_88 ;
const struct V_9 * V_85 , * V_10 ;
V_85 = F_88 ( V_6 -> V_17 . V_83 , true , & V_88 ) ;
V_10 = F_91 ( V_94 , V_85 , V_88 ) ;
if ( ! V_10 )
V_10 = F_91 ( V_94 , V_118 , F_110 ( V_118 ) ) ;
if ( F_95 ( V_10 ) ) {
F_12 ( ! V_10 -> V_97 ) ;
if ( F_95 ( V_10 -> V_97 ( V_6 , V_94 , V_10 ) ) ) {
F_96 ( V_6 , F_97 ( V_6 ) ) ;
return 1 ;
}
} else {
F_101 ( L_2 ,
* F_102 ( V_6 ) ) ;
F_103 ( V_94 ) ;
}
F_93 ( V_6 ) ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
const struct V_9 * V_85 , T_5 V_88 )
{
unsigned long V_119 ;
for ( V_119 = 0 ; V_119 < V_88 ; V_119 ++ )
if ( V_85 [ V_119 ] . V_120 )
V_85 [ V_119 ] . V_120 ( V_6 , & V_85 [ V_119 ] ) ;
}
int F_116 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
struct V_7 V_94 ;
unsigned long V_121 = F_105 ( V_6 ) ;
int V_109 = ( V_121 >> 5 ) & 0x1f ;
int V_122 ;
F_117 ( V_121 ) ;
V_94 . V_13 = false ;
V_94 . V_16 = false ;
V_94 . V_111 = ( V_121 >> 20 ) & 3 ;
V_94 . V_112 = ( V_121 >> 14 ) & 0x7 ;
V_94 . V_64 = ( V_121 >> 10 ) & 0xf ;
V_94 . V_65 = ( V_121 >> 1 ) & 0xf ;
V_94 . V_57 = ( V_121 >> 17 ) & 0x7 ;
V_94 . V_15 = F_106 ( V_6 , V_109 ) ;
V_94 . V_11 = ! ( V_121 & 1 ) ;
V_122 = F_114 ( V_6 , & V_94 ) ;
if ( ! V_94 . V_11 )
F_107 ( V_6 , V_109 , V_94 . V_15 ) ;
return V_122 ;
}
static bool F_118 ( T_2 V_32 , struct V_7 * V_94 )
{
switch ( V_32 & V_123 ) {
case V_124 :
if ( V_32 & ~ ( V_125 | V_123
| V_126
| V_127
| V_128
| V_129
| V_130
| V_131 ) )
return false ;
V_94 -> V_111 = ( ( V_32 & V_127 )
>> V_132 ) ;
V_94 -> V_112 = ( ( V_32 & V_128 )
>> V_133 ) ;
V_94 -> V_64 = ( ( V_32 & V_129 )
>> V_134 ) ;
V_94 -> V_65 = ( ( V_32 & V_130 )
>> V_135 ) ;
V_94 -> V_57 = ( ( V_32 & V_131 )
>> V_136 ) ;
return true ;
default:
return false ;
}
}
static const struct V_9 * F_119 ( struct V_5 * V_6 ,
T_2 V_32 )
{
T_5 V_88 ;
const struct V_9 * V_85 , * V_10 ;
struct V_7 V_94 ;
if ( ( V_32 & V_126 ) != V_137 )
return NULL ;
if ( ! F_118 ( V_32 , & V_94 ) )
return NULL ;
V_85 = F_88 ( V_6 -> V_17 . V_83 , true , & V_88 ) ;
V_10 = F_91 ( & V_94 , V_85 , V_88 ) ;
if ( ! V_10 )
V_10 = F_91 ( & V_94 , V_118 , F_110 ( V_118 ) ) ;
if ( V_10 && ! V_10 -> V_14 )
V_10 = NULL ;
return V_10 ;
}
static int F_120 ( T_2 * V_26 , const void T_3 * V_31 , T_2 V_32 )
{
if ( F_33 ( V_26 , V_31 , F_34 ( V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_121 ( void T_3 * V_31 , const T_2 * V_26 , T_2 V_32 )
{
if ( F_36 ( V_31 , V_26 , F_34 ( V_32 ) ) != 0 )
return - V_33 ;
return 0 ;
}
static int F_122 ( T_2 V_32 , void T_3 * V_31 )
{
struct V_7 V_94 ;
const struct V_9 * V_10 ;
if ( ! F_118 ( V_32 , & V_94 ) )
return - V_138 ;
V_10 = F_91 ( & V_94 , V_139 , F_110 ( V_139 ) ) ;
if ( ! V_10 )
return - V_138 ;
return F_121 ( V_31 , & V_10 -> V_26 , V_32 ) ;
}
static int F_123 ( T_2 V_32 , void T_3 * V_31 )
{
struct V_7 V_94 ;
const struct V_9 * V_10 ;
int V_140 ;
T_2 V_26 = 0 ;
if ( ! F_118 ( V_32 , & V_94 ) )
return - V_138 ;
V_10 = F_91 ( & V_94 , V_139 , F_110 ( V_139 ) ) ;
if ( ! V_10 )
return - V_138 ;
V_140 = F_120 ( & V_26 , V_31 , V_32 ) ;
if ( V_140 )
return V_140 ;
if ( V_10 -> V_26 != V_26 )
return - V_141 ;
return 0 ;
}
static bool F_124 ( T_1 V_26 )
{
T_1 V_142 , V_143 ;
if ( V_26 >= V_144 )
return false ;
V_142 = ( V_26 >> 1 ) ;
V_143 = ( V_145 >> ( V_142 * 3 ) ) & 7 ;
switch ( V_143 ) {
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
static int F_125 ( T_2 V_32 , void T_3 * V_31 )
{
T_1 V_26 ;
T_1 T_3 * V_146 = V_31 ;
if ( V_32 & ~ ( V_125 | V_123 | V_126
| ( ( 1 << V_147 ) - 1 ) ) )
return - V_138 ;
switch ( V_32 & V_148 ) {
case V_149 :
if ( F_34 ( V_32 ) != 4 )
return - V_138 ;
V_26 = ( V_32 & V_150 )
>> V_151 ;
if ( ! F_124 ( V_26 ) )
return - V_138 ;
return F_126 ( F_1 ( V_26 ) , V_146 ) ;
default:
return - V_138 ;
}
}
static int F_127 ( T_2 V_32 , void T_3 * V_31 )
{
T_1 V_26 , V_152 ;
T_1 T_3 * V_146 = V_31 ;
if ( V_32 & ~ ( V_125 | V_123 | V_126
| ( ( 1 << V_147 ) - 1 ) ) )
return - V_138 ;
switch ( V_32 & V_148 ) {
case V_149 :
if ( F_34 ( V_32 ) != 4 )
return - V_138 ;
V_26 = ( V_32 & V_150 )
>> V_151 ;
if ( ! F_124 ( V_26 ) )
return - V_138 ;
if ( F_128 ( V_152 , V_146 ) )
return - V_33 ;
if ( V_152 != F_1 ( V_26 ) )
return - V_141 ;
return 0 ;
default:
return - V_138 ;
}
}
int F_129 ( struct V_5 * V_6 , const struct V_30 * V_14 )
{
const struct V_9 * V_10 ;
void T_3 * V_31 = ( void T_3 * ) ( unsigned long ) V_14 -> V_153 ;
if ( ( V_14 -> V_32 & V_126 ) == V_154 )
return F_125 ( V_14 -> V_32 , V_31 ) ;
if ( F_34 ( V_14 -> V_32 ) != sizeof( T_4 ) )
return - V_138 ;
V_10 = F_119 ( V_6 , V_14 -> V_32 ) ;
if ( ! V_10 )
return F_122 ( V_14 -> V_32 , V_31 ) ;
if ( V_10 -> F_128 )
return ( V_10 -> F_128 ) ( V_6 , V_10 , V_14 , V_31 ) ;
return F_121 ( V_31 , & F_13 ( V_6 , V_10 -> V_14 ) , V_14 -> V_32 ) ;
}
int F_130 ( struct V_5 * V_6 , const struct V_30 * V_14 )
{
const struct V_9 * V_10 ;
void T_3 * V_31 = ( void T_3 * ) ( unsigned long ) V_14 -> V_153 ;
if ( ( V_14 -> V_32 & V_126 ) == V_154 )
return F_127 ( V_14 -> V_32 , V_31 ) ;
if ( F_34 ( V_14 -> V_32 ) != sizeof( T_4 ) )
return - V_138 ;
V_10 = F_119 ( V_6 , V_14 -> V_32 ) ;
if ( ! V_10 )
return F_123 ( V_14 -> V_32 , V_31 ) ;
if ( V_10 -> V_155 )
return ( V_10 -> V_155 ) ( V_6 , V_10 , V_14 , V_31 ) ;
return F_120 ( & F_13 ( V_6 , V_10 -> V_14 ) , V_31 , V_14 -> V_32 ) ;
}
static unsigned int F_131 ( void )
{
unsigned int V_119 , V_156 = 0 ;
for ( V_119 = 0 ; V_119 < V_144 ; V_119 ++ )
if ( F_124 ( V_119 ) )
V_156 ++ ;
return V_156 ;
}
static int F_132 ( T_2 T_3 * V_157 )
{
T_2 V_26 = V_158 | V_159 | V_154 ;
unsigned int V_119 ;
V_26 |= V_149 ;
for ( V_119 = 0 ; V_119 < V_144 ; V_119 ++ ) {
if ( ! F_124 ( V_119 ) )
continue;
if ( F_126 ( V_26 | V_119 , V_157 ) )
return - V_33 ;
V_157 ++ ;
}
return 0 ;
}
static T_2 F_133 ( const struct V_9 * V_14 )
{
return ( V_158 | V_124 |
V_137 |
( V_14 -> V_111 << V_132 ) |
( V_14 -> V_112 << V_133 ) |
( V_14 -> V_64 << V_134 ) |
( V_14 -> V_65 << V_135 ) |
( V_14 -> V_57 << V_136 ) ) ;
}
static bool F_134 ( const struct V_9 * V_14 , T_2 T_3 * * V_160 )
{
if ( ! * V_160 )
return true ;
if ( F_126 ( F_133 ( V_14 ) , * V_160 ) )
return false ;
( * V_160 ) ++ ;
return true ;
}
static int F_135 ( struct V_5 * V_6 , T_2 T_3 * V_160 )
{
const struct V_9 * V_161 , * V_162 , * V_163 , * V_164 ;
unsigned int V_165 = 0 ;
T_5 V_88 ;
V_161 = F_88 ( V_6 -> V_17 . V_83 , true , & V_88 ) ;
V_163 = V_161 + V_88 ;
V_162 = V_118 ;
V_164 = V_118 + F_110 ( V_118 ) ;
F_12 ( V_161 == V_163 || V_162 == V_164 ) ;
while ( V_161 || V_162 ) {
int V_166 = F_136 ( V_161 , V_162 ) ;
if ( V_166 <= 0 ) {
if ( V_161 -> V_14 ) {
if ( ! F_134 ( V_161 , & V_160 ) )
return - V_33 ;
V_165 ++ ;
}
} else {
if ( V_162 -> V_14 ) {
if ( ! F_134 ( V_162 , & V_160 ) )
return - V_33 ;
V_165 ++ ;
}
}
if ( V_166 <= 0 && ++ V_161 == V_163 )
V_161 = NULL ;
if ( V_166 >= 0 && ++ V_162 == V_164 )
V_162 = NULL ;
}
return V_165 ;
}
unsigned long F_137 ( struct V_5 * V_6 )
{
return F_110 ( V_139 )
+ F_131 ()
+ F_135 ( V_6 , ( T_2 T_3 * ) NULL ) ;
}
int F_138 ( struct V_5 * V_6 , T_2 T_3 * V_157 )
{
unsigned int V_119 ;
int V_140 ;
for ( V_119 = 0 ; V_119 < F_110 ( V_139 ) ; V_119 ++ ) {
if ( F_126 ( F_133 ( & V_139 [ V_119 ] ) , V_157 ) )
return - V_33 ;
V_157 ++ ;
}
V_140 = F_135 ( V_6 , V_157 ) ;
if ( V_140 < 0 )
return V_140 ;
V_157 += V_140 ;
return F_132 ( V_157 ) ;
}
static int F_139 ( const struct V_9 * V_85 , unsigned int V_167 )
{
unsigned int V_119 ;
for ( V_119 = 1 ; V_119 < V_167 ; V_119 ++ ) {
if ( F_136 ( & V_85 [ V_119 - 1 ] , & V_85 [ V_119 ] ) >= 0 ) {
F_101 ( L_3 , V_85 , V_119 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_140 ( void )
{
unsigned int V_119 ;
struct V_9 V_168 ;
F_12 ( F_139 ( V_118 , F_110 ( V_118 ) ) ) ;
F_12 ( F_139 ( V_117 , F_110 ( V_117 ) ) ) ;
F_12 ( F_139 ( V_116 , F_110 ( V_116 ) ) ) ;
F_12 ( F_139 ( V_115 , F_110 ( V_115 ) ) ) ;
F_12 ( F_139 ( V_114 , F_110 ( V_114 ) ) ) ;
F_12 ( F_139 ( V_139 , F_110 ( V_139 ) ) ) ;
for ( V_119 = 0 ; V_119 < F_110 ( V_139 ) ; V_119 ++ )
V_139 [ V_119 ] . V_120 ( NULL , & V_139 [ V_119 ] ) ;
F_141 ( NULL , & V_168 ) ;
V_145 = V_168 . V_26 ;
for ( V_119 = 0 ; V_119 < 7 ; V_119 ++ )
if ( ( ( V_145 >> ( V_119 * 3 ) ) & 7 ) == 0 )
break;
V_145 &= ( 1 << ( V_119 * 3 ) ) - 1 ;
}
void F_142 ( struct V_5 * V_6 )
{
T_5 V_88 ;
const struct V_9 * V_85 ;
memset ( & V_6 -> V_17 . V_169 . V_170 , 0x42 , sizeof( V_6 -> V_17 . V_169 . V_170 ) ) ;
F_115 ( V_6 , V_118 , F_110 ( V_118 ) ) ;
V_85 = F_88 ( V_6 -> V_17 . V_83 , true , & V_88 ) ;
F_115 ( V_6 , V_85 , V_88 ) ;
for ( V_88 = 1 ; V_88 < V_171 ; V_88 ++ )
if ( F_13 ( V_6 , V_88 ) == 0x4242424242424242 )
F_143 ( L_4 , V_88 ) ;
}
