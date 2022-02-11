static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
F_2 () ;
asm volatile("msr csselr_el1, %x0" : : "r" (csselr));
F_3 () ;
asm volatile("mrs %0, ccsidr_el1" : "=r" (ccsidr));
F_4 () ;
return V_2 ;
}
static bool F_5 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_7 ( V_4 ) ;
return true ;
}
static bool F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
bool V_10 = F_9 ( V_4 ) ;
F_10 ( ! V_6 -> V_9 ) ;
if ( ! V_6 -> V_11 ) {
F_11 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
} else {
if ( ! V_6 -> V_14 )
F_12 ( V_4 , V_8 -> V_12 ) = F_13 ( V_6 -> V_13 ) ;
F_14 ( V_4 , V_8 -> V_12 ) = F_15 ( V_6 -> V_13 ) ;
}
F_16 ( V_4 , V_10 ) ;
return true ;
}
static bool F_17 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_18 ( V_4 , V_6 -> V_13 ) ;
return true ;
}
static bool F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return F_20 ( V_4 , V_6 ) ;
else
return F_21 ( V_4 , V_6 ) ;
}
static bool F_22 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
V_6 -> V_13 = ( 1 << 3 ) ;
return true ;
}
}
static bool F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_1 V_15 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
V_6 -> V_13 = V_15 ;
return true ;
}
}
static bool F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_11 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_8 -> V_12 ) ;
}
F_25 ( V_19 , V_8 -> V_12 , V_6 -> V_9 , V_6 -> V_13 ) ;
return true ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_20 )
{
T_2 V_15 = V_6 -> V_13 ;
if ( V_6 -> V_14 ) {
V_15 &= 0xffffffffUL ;
V_15 |= ( ( * V_20 >> 32 ) << 32 ) ;
}
* V_20 = V_15 ;
V_4 -> V_16 . V_17 |= V_18 ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_20 )
{
V_6 -> V_13 = * V_20 ;
if ( V_6 -> V_14 )
V_6 -> V_13 &= 0xffffffffUL ;
}
static bool F_28 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_29 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static bool F_35 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_36 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static bool F_39 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 ,
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ) ;
return true ;
}
static int F_40 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static bool F_43 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_44 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static void F_46 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static void F_47 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_31 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_11 ( V_4 , V_32 ) = V_31 ;
}
static void F_48 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_33 ;
V_33 = ( V_4 -> V_34 & 0x0f ) << F_49 ( 0 ) ;
V_33 |= ( ( V_4 -> V_34 >> 4 ) & 0xff ) << F_49 ( 1 ) ;
V_33 |= ( ( V_4 -> V_34 >> 12 ) & 0xff ) << F_49 ( 2 ) ;
F_11 ( V_4 , V_35 ) = ( 1ULL << 31 ) | V_33 ;
}
static void F_50 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_36 , V_15 ;
asm volatile("mrs %0, pmcr_el0\n" : "=r" (pmcr));
V_15 = ( ( V_36 & ~ V_37 )
| ( V_37 & 0xdecafbad ) ) & ( ~ V_38 ) ;
F_11 ( V_4 , V_39 ) = V_15 ;
}
static bool F_51 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_40 ) ;
return ! ( ( V_12 & V_41 ) || F_52 ( V_4 ) ) ;
}
static bool F_53 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_40 ) ;
return ! ( ( V_12 & ( V_42 | V_41 ) )
|| F_52 ( V_4 ) ) ;
}
static bool F_54 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_40 ) ;
return ! ( ( V_12 & ( V_43 | V_41 ) )
|| F_52 ( V_4 ) ) ;
}
static bool F_55 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_40 ) ;
return ! ( ( V_12 & ( V_44 | V_41 ) )
|| F_52 ( V_4 ) ) ;
}
static bool F_56 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_15 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_51 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
V_15 = F_11 ( V_4 , V_39 ) ;
V_15 &= ~ V_37 ;
V_15 |= V_6 -> V_13 & V_37 ;
F_11 ( V_4 , V_39 ) = V_15 ;
F_58 ( V_4 , V_15 ) ;
} else {
V_15 = F_11 ( V_4 , V_39 )
& ~ ( V_45 | V_46 ) ;
V_6 -> V_13 = V_15 ;
}
return true ;
}
static bool F_59 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_55 ( V_4 ) )
return false ;
if ( V_6 -> V_9 )
F_11 ( V_4 , V_47 ) = V_6 -> V_13 ;
else
V_6 -> V_13 = F_11 ( V_4 , V_47 )
& V_48 ;
return true ;
}
static bool F_60 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_49 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
F_10 ( V_6 -> V_9 ) ;
if ( F_51 ( V_4 ) )
return false ;
if ( ! ( V_6 -> V_50 & 1 ) )
asm volatile("mrs %0, pmceid0_el0\n" : "=r" (pmceid));
else
asm volatile("mrs %0, pmceid1_el0\n" : "=r" (pmceid));
V_6 -> V_13 = V_49 ;
return true ;
}
static bool F_61 ( struct V_3 * V_4 , T_2 V_51 )
{
T_2 V_36 , V_15 ;
V_36 = F_11 ( V_4 , V_39 ) ;
V_15 = ( V_36 >> V_52 ) & V_53 ;
if ( V_51 >= V_15 && V_51 != V_54 )
return false ;
return true ;
}
static bool F_62 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_51 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( V_8 -> V_55 == 9 && V_8 -> V_56 == 13 ) {
if ( V_8 -> V_50 == 2 ) {
if ( F_55 ( V_4 ) )
return false ;
V_51 = F_11 ( V_4 , V_47 )
& V_48 ;
} else if ( V_8 -> V_50 == 0 ) {
if ( F_54 ( V_4 ) )
return false ;
V_51 = V_54 ;
} else {
F_63 () ;
}
} else if ( V_8 -> V_55 == 14 && ( V_8 -> V_56 & 12 ) == 8 ) {
if ( F_55 ( V_4 ) )
return false ;
V_51 = ( ( V_8 -> V_56 & 3 ) << 3 ) | ( V_8 -> V_50 & 7 ) ;
} else {
F_63 () ;
}
if ( ! F_61 ( V_4 , V_51 ) )
return false ;
if ( V_6 -> V_9 ) {
if ( F_51 ( V_4 ) )
return false ;
F_64 ( V_4 , V_51 , V_6 -> V_13 ) ;
} else {
V_6 -> V_13 = F_65 ( V_4 , V_51 ) ;
}
return true ;
}
static bool F_66 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_51 , V_12 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_51 ( V_4 ) )
return false ;
if ( V_8 -> V_55 == 9 && V_8 -> V_56 == 13 && V_8 -> V_50 == 1 ) {
V_51 = F_11 ( V_4 , V_47 ) & V_48 ;
V_12 = V_57 + V_51 ;
} else if ( V_8 -> V_55 == 14 && ( V_8 -> V_56 & 12 ) == 12 ) {
V_51 = ( ( V_8 -> V_56 & 3 ) << 3 ) | ( V_8 -> V_50 & 7 ) ;
if ( V_51 == V_54 )
V_12 = V_58 ;
else
V_12 = V_57 + V_51 ;
} else {
F_63 () ;
}
if ( ! F_61 ( V_4 , V_51 ) )
return false ;
if ( V_6 -> V_9 ) {
F_67 ( V_4 , V_6 -> V_13 , V_51 ) ;
F_11 ( V_4 , V_12 ) = V_6 -> V_13 & V_59 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_12 ) & V_59 ;
}
return true ;
}
static bool F_68 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_15 , V_60 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_51 ( V_4 ) )
return false ;
V_60 = F_69 ( V_4 ) ;
if ( V_6 -> V_9 ) {
V_15 = V_6 -> V_13 & V_60 ;
if ( V_8 -> V_50 & 0x1 ) {
F_11 ( V_4 , V_61 ) |= V_15 ;
F_70 ( V_4 , V_15 ) ;
} else {
F_11 ( V_4 , V_61 ) &= ~ V_15 ;
F_71 ( V_4 , V_15 ) ;
}
} else {
V_6 -> V_13 = F_11 ( V_4 , V_61 ) & V_60 ;
}
return true ;
}
static bool F_72 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_60 = F_69 ( V_4 ) ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( ! F_52 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
T_2 V_15 = V_6 -> V_13 & V_60 ;
if ( V_8 -> V_50 & 0x1 )
F_11 ( V_4 , V_62 ) |= V_15 ;
else
F_11 ( V_4 , V_62 ) &= ~ V_15 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_62 ) & V_60 ;
}
return true ;
}
static bool F_73 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_60 = F_69 ( V_4 ) ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_51 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
if ( V_8 -> V_56 & 0x2 )
F_74 ( V_4 , V_6 -> V_13 & V_60 ) ;
else
F_11 ( V_4 , V_63 ) &= ~ ( V_6 -> V_13 & V_60 ) ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_63 ) & V_60 ;
}
return true ;
}
static bool F_75 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_60 ;
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( F_53 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
V_60 = F_69 ( V_4 ) ;
F_76 ( V_4 , V_6 -> V_13 & V_60 ) ;
return true ;
}
return false ;
}
static bool F_77 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! F_57 ( V_4 ) )
return F_19 ( V_4 , V_6 , V_8 ) ;
if ( V_6 -> V_9 ) {
if ( ! F_52 ( V_4 ) )
return false ;
F_11 ( V_4 , V_40 ) = V_6 -> V_13
& V_64 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_40 )
& V_64 ;
}
return true ;
}
static bool F_78 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_2 V_65 = F_79 ( V_66 ) ;
T_2 V_67 = F_79 ( V_68 ) ;
T_1 V_69 = ! ! F_80 ( V_67 , V_70 ) ;
V_6 -> V_13 = ( ( ( ( V_65 >> V_71 ) & 0xf ) << 28 ) |
( ( ( V_65 >> V_72 ) & 0xf ) << 24 ) |
( ( ( V_65 >> V_73 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_69 << 14 ) | ( V_69 << 12 ) ) ;
return true ;
}
}
static bool F_81 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_82 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = F_82 ( V_4 , V_8 -> V_12 ) ;
}
return true ;
}
static bool F_83 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 ) {
T_2 V_15 = * V_20 ;
V_15 &= 0xffffffffUL ;
V_15 |= V_6 -> V_13 << 32 ;
* V_20 = V_15 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = * V_20 >> 32 ;
}
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
void F_84 ( unsigned int V_74 ,
struct V_75 * V_76 )
{
V_77 [ V_74 ] = V_76 ;
}
static const struct V_7 * F_85 ( unsigned V_74 ,
bool V_78 ,
T_5 * V_79 )
{
struct V_75 * V_76 ;
V_76 = V_77 [ V_74 ] ;
if ( V_78 ) {
* V_79 = V_76 -> V_80 . V_79 ;
return V_76 -> V_80 . V_76 ;
} else {
* V_79 = V_76 -> V_81 . V_79 ;
return V_76 -> V_81 . V_76 ;
}
}
static int F_86 ( const void * V_82 , const void * V_83 )
{
const unsigned long V_84 = ( unsigned long ) V_82 ;
const struct V_7 * V_8 = V_83 ;
return V_84 - F_87 ( V_8 ) ;
}
static const struct V_7 * F_88 ( const struct V_5 * V_85 ,
const struct V_7 V_76 [] ,
unsigned int V_79 )
{
unsigned long V_84 = F_87 ( V_85 ) ;
return bsearch ( ( void * ) V_84 , V_76 , V_79 , sizeof( V_76 [ 0 ] ) , F_86 ) ;
}
int F_89 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
F_90 ( V_4 ) ;
return 1 ;
}
static int F_91 ( struct V_3 * V_4 ,
struct V_5 * V_85 ,
const struct V_7 * V_76 ,
T_5 V_79 )
{
const struct V_7 * V_8 ;
if ( ! V_76 )
return - 1 ;
V_8 = F_88 ( V_85 , V_76 , V_79 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_88 ) ;
if ( F_92 ( V_8 -> V_88 ( V_4 , V_85 , V_8 ) ) ) {
F_93 ( V_4 , F_94 ( V_4 ) ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_95 ( struct V_3 * V_4 ,
struct V_5 * V_85 )
{
T_6 V_89 = F_96 ( V_4 ) ;
int V_90 ;
switch( V_89 ) {
case V_91 :
case V_92 :
V_90 = 15 ;
break;
case V_93 :
case V_94 :
V_90 = 14 ;
break;
default:
F_97 ( ( V_90 = - 1 ) ) ;
}
F_98 ( L_1 ,
V_90 , * F_99 ( V_4 ) ) ;
F_100 ( V_85 ) ;
F_90 ( V_4 ) ;
}
static int F_101 ( struct V_3 * V_4 ,
const struct V_7 * V_95 ,
T_5 V_96 ,
const struct V_7 * V_97 ,
T_5 V_98 )
{
struct V_5 V_85 ;
T_1 V_99 = F_102 ( V_4 ) ;
int V_100 = ( V_99 >> 5 ) & 0xf ;
int V_101 = ( V_99 >> 10 ) & 0xf ;
V_85 . V_11 = true ;
V_85 . V_14 = false ;
V_85 . V_56 = ( V_99 >> 1 ) & 0xf ;
V_85 . V_9 = ( ( V_99 & 1 ) == 0 ) ;
V_85 . V_102 = 0 ;
V_85 . V_103 = ( V_99 >> 16 ) & 0xf ;
V_85 . V_50 = 0 ;
V_85 . V_55 = 0 ;
if ( V_85 . V_9 ) {
V_85 . V_13 = F_103 ( V_4 , V_100 ) & 0xffffffff ;
V_85 . V_13 |= F_103 ( V_4 , V_101 ) << 32 ;
}
if ( ! F_91 ( V_4 , & V_85 , V_97 , V_98 ) )
goto V_104;
if ( ! F_91 ( V_4 , & V_85 , V_95 , V_96 ) )
goto V_104;
F_95 ( V_4 , & V_85 ) ;
V_104:
if ( ! V_85 . V_9 ) {
F_104 ( V_4 , V_100 , F_15 ( V_85 . V_13 ) ) ;
F_104 ( V_4 , V_101 , F_13 ( V_85 . V_13 ) ) ;
}
return 1 ;
}
static int F_105 ( struct V_3 * V_4 ,
const struct V_7 * V_95 ,
T_5 V_96 ,
const struct V_7 * V_97 ,
T_5 V_98 )
{
struct V_5 V_85 ;
T_1 V_99 = F_102 ( V_4 ) ;
int V_100 = ( V_99 >> 5 ) & 0xf ;
V_85 . V_11 = true ;
V_85 . V_14 = true ;
V_85 . V_56 = ( V_99 >> 1 ) & 0xf ;
V_85 . V_13 = F_103 ( V_4 , V_100 ) ;
V_85 . V_9 = ( ( V_99 & 1 ) == 0 ) ;
V_85 . V_55 = ( V_99 >> 10 ) & 0xf ;
V_85 . V_102 = 0 ;
V_85 . V_103 = ( V_99 >> 14 ) & 0x7 ;
V_85 . V_50 = ( V_99 >> 17 ) & 0x7 ;
if ( ! F_91 ( V_4 , & V_85 , V_97 , V_98 ) ||
! F_91 ( V_4 , & V_85 , V_95 , V_96 ) ) {
if ( ! V_85 . V_9 )
F_104 ( V_4 , V_100 , V_85 . V_13 ) ;
return 1 ;
}
F_95 ( V_4 , & V_85 ) ;
return 1 ;
}
int F_106 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
const struct V_7 * V_97 ;
T_5 V_79 ;
V_97 = F_85 ( V_4 -> V_16 . V_74 , false , & V_79 ) ;
return F_101 ( V_4 ,
V_105 , F_107 ( V_105 ) ,
V_97 , V_79 ) ;
}
int F_108 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
const struct V_7 * V_97 ;
T_5 V_79 ;
V_97 = F_85 ( V_4 -> V_16 . V_74 , false , & V_79 ) ;
return F_105 ( V_4 ,
V_106 , F_107 ( V_106 ) ,
V_97 , V_79 ) ;
}
int F_109 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
return F_101 ( V_4 ,
V_107 , F_107 ( V_107 ) ,
NULL , 0 ) ;
}
int F_110 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
return F_105 ( V_4 ,
V_108 , F_107 ( V_108 ) ,
NULL , 0 ) ;
}
static int F_111 ( struct V_3 * V_4 ,
struct V_5 * V_85 )
{
T_5 V_79 ;
const struct V_7 * V_76 , * V_8 ;
V_76 = F_85 ( V_4 -> V_16 . V_74 , true , & V_79 ) ;
V_8 = F_88 ( V_85 , V_76 , V_79 ) ;
if ( ! V_8 )
V_8 = F_88 ( V_85 , V_109 , F_107 ( V_109 ) ) ;
if ( F_92 ( V_8 ) ) {
F_10 ( ! V_8 -> V_88 ) ;
if ( F_92 ( V_8 -> V_88 ( V_4 , V_85 , V_8 ) ) ) {
F_93 ( V_4 , F_94 ( V_4 ) ) ;
return 1 ;
}
} else {
F_98 ( L_2 ,
* F_99 ( V_4 ) ) ;
F_100 ( V_85 ) ;
}
F_90 ( V_4 ) ;
return 1 ;
}
static void F_112 ( struct V_3 * V_4 ,
const struct V_7 * V_76 , T_5 V_79 )
{
unsigned long V_110 ;
for ( V_110 = 0 ; V_110 < V_79 ; V_110 ++ )
if ( V_76 [ V_110 ] . V_111 )
V_76 [ V_110 ] . V_111 ( V_4 , & V_76 [ V_110 ] ) ;
}
int F_113 ( struct V_3 * V_4 , struct V_86 * V_87 )
{
struct V_5 V_85 ;
unsigned long V_112 = F_102 ( V_4 ) ;
int V_100 = ( V_112 >> 5 ) & 0x1f ;
int V_113 ;
F_114 ( V_112 ) ;
V_85 . V_11 = false ;
V_85 . V_14 = false ;
V_85 . V_102 = ( V_112 >> 20 ) & 3 ;
V_85 . V_103 = ( V_112 >> 14 ) & 0x7 ;
V_85 . V_55 = ( V_112 >> 10 ) & 0xf ;
V_85 . V_56 = ( V_112 >> 1 ) & 0xf ;
V_85 . V_50 = ( V_112 >> 17 ) & 0x7 ;
V_85 . V_13 = F_103 ( V_4 , V_100 ) ;
V_85 . V_9 = ! ( V_112 & 1 ) ;
V_113 = F_111 ( V_4 , & V_85 ) ;
if ( ! V_85 . V_9 )
F_104 ( V_4 , V_100 , V_85 . V_13 ) ;
return V_113 ;
}
static bool F_115 ( T_2 V_26 , struct V_5 * V_85 )
{
switch ( V_26 & V_114 ) {
case V_115 :
if ( V_26 & ~ ( V_116 | V_114
| V_117
| V_118
| V_119
| V_120
| V_121
| V_122 ) )
return false ;
V_85 -> V_102 = ( ( V_26 & V_118 )
>> V_123 ) ;
V_85 -> V_103 = ( ( V_26 & V_119 )
>> V_124 ) ;
V_85 -> V_55 = ( ( V_26 & V_120 )
>> V_125 ) ;
V_85 -> V_56 = ( ( V_26 & V_121 )
>> V_126 ) ;
V_85 -> V_50 = ( ( V_26 & V_122 )
>> V_127 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_116 ( struct V_3 * V_4 ,
T_2 V_26 )
{
T_5 V_79 ;
const struct V_7 * V_76 , * V_8 ;
struct V_5 V_85 ;
if ( ( V_26 & V_117 ) != V_128 )
return NULL ;
if ( ! F_115 ( V_26 , & V_85 ) )
return NULL ;
V_76 = F_85 ( V_4 -> V_16 . V_74 , true , & V_79 ) ;
V_8 = F_88 ( & V_85 , V_76 , V_79 ) ;
if ( ! V_8 )
V_8 = F_88 ( & V_85 , V_109 , F_107 ( V_109 ) ) ;
if ( V_8 && ! V_8 -> V_12 )
V_8 = NULL ;
return V_8 ;
}
static int F_117 ( T_2 * V_15 , const void T_3 * V_25 , T_2 V_26 )
{
if ( F_30 ( V_15 , V_25 , F_31 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_118 ( void T_3 * V_25 , const T_2 * V_15 , T_2 V_26 )
{
if ( F_33 ( V_25 , V_15 , F_31 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_119 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_85 ;
const struct V_7 * V_8 ;
if ( ! F_115 ( V_26 , & V_85 ) )
return - V_129 ;
V_8 = F_88 ( & V_85 , V_130 , F_107 ( V_130 ) ) ;
if ( ! V_8 )
return - V_129 ;
return F_118 ( V_25 , & V_8 -> V_15 , V_26 ) ;
}
static int F_120 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_85 ;
const struct V_7 * V_8 ;
int V_131 ;
T_2 V_15 = 0 ;
if ( ! F_115 ( V_26 , & V_85 ) )
return - V_129 ;
V_8 = F_88 ( & V_85 , V_130 , F_107 ( V_130 ) ) ;
if ( ! V_8 )
return - V_129 ;
V_131 = F_117 ( & V_15 , V_25 , V_26 ) ;
if ( V_131 )
return V_131 ;
if ( V_8 -> V_15 != V_15 )
return - V_132 ;
return 0 ;
}
static bool F_121 ( T_1 V_15 )
{
T_1 V_133 , V_134 ;
if ( V_15 >= V_135 )
return false ;
V_133 = ( V_15 >> 1 ) ;
V_134 = ( V_136 >> ( V_133 * 3 ) ) & 7 ;
switch ( V_134 ) {
case 0 :
return false ;
case 1 :
return ( V_15 & 1 ) ;
case 2 :
case 4 :
return ! ( V_15 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_122 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_15 ;
T_1 T_3 * V_137 = V_25 ;
if ( V_26 & ~ ( V_116 | V_114 | V_117
| ( ( 1 << V_138 ) - 1 ) ) )
return - V_129 ;
switch ( V_26 & V_139 ) {
case V_140 :
if ( F_31 ( V_26 ) != 4 )
return - V_129 ;
V_15 = ( V_26 & V_141 )
>> V_142 ;
if ( ! F_121 ( V_15 ) )
return - V_129 ;
return F_123 ( F_1 ( V_15 ) , V_137 ) ;
default:
return - V_129 ;
}
}
static int F_124 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_15 , V_143 ;
T_1 T_3 * V_137 = V_25 ;
if ( V_26 & ~ ( V_116 | V_114 | V_117
| ( ( 1 << V_138 ) - 1 ) ) )
return - V_129 ;
switch ( V_26 & V_139 ) {
case V_140 :
if ( F_31 ( V_26 ) != 4 )
return - V_129 ;
V_15 = ( V_26 & V_141 )
>> V_142 ;
if ( ! F_121 ( V_15 ) )
return - V_129 ;
if ( F_125 ( V_143 , V_137 ) )
return - V_27 ;
if ( V_143 != F_1 ( V_15 ) )
return - V_132 ;
return 0 ;
default:
return - V_129 ;
}
}
int F_126 ( struct V_3 * V_4 , const struct V_24 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_12 -> V_144 ;
if ( ( V_12 -> V_26 & V_117 ) == V_145 )
return F_122 ( V_12 -> V_26 , V_25 ) ;
if ( F_31 ( V_12 -> V_26 ) != sizeof( T_4 ) )
return - V_129 ;
V_8 = F_116 ( V_4 , V_12 -> V_26 ) ;
if ( ! V_8 )
return F_119 ( V_12 -> V_26 , V_25 ) ;
if ( V_8 -> F_125 )
return ( V_8 -> F_125 ) ( V_4 , V_8 , V_12 , V_25 ) ;
return F_118 ( V_25 , & F_11 ( V_4 , V_8 -> V_12 ) , V_12 -> V_26 ) ;
}
int F_127 ( struct V_3 * V_4 , const struct V_24 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_12 -> V_144 ;
if ( ( V_12 -> V_26 & V_117 ) == V_145 )
return F_124 ( V_12 -> V_26 , V_25 ) ;
if ( F_31 ( V_12 -> V_26 ) != sizeof( T_4 ) )
return - V_129 ;
V_8 = F_116 ( V_4 , V_12 -> V_26 ) ;
if ( ! V_8 )
return F_120 ( V_12 -> V_26 , V_25 ) ;
if ( V_8 -> V_146 )
return ( V_8 -> V_146 ) ( V_4 , V_8 , V_12 , V_25 ) ;
return F_117 ( & F_11 ( V_4 , V_8 -> V_12 ) , V_25 , V_12 -> V_26 ) ;
}
static unsigned int F_128 ( void )
{
unsigned int V_110 , V_147 = 0 ;
for ( V_110 = 0 ; V_110 < V_135 ; V_110 ++ )
if ( F_121 ( V_110 ) )
V_147 ++ ;
return V_147 ;
}
static int F_129 ( T_2 T_3 * V_148 )
{
T_2 V_15 = V_149 | V_150 | V_145 ;
unsigned int V_110 ;
V_15 |= V_140 ;
for ( V_110 = 0 ; V_110 < V_135 ; V_110 ++ ) {
if ( ! F_121 ( V_110 ) )
continue;
if ( F_123 ( V_15 | V_110 , V_148 ) )
return - V_27 ;
V_148 ++ ;
}
return 0 ;
}
static T_2 F_130 ( const struct V_7 * V_12 )
{
return ( V_149 | V_115 |
V_128 |
( V_12 -> V_102 << V_123 ) |
( V_12 -> V_103 << V_124 ) |
( V_12 -> V_55 << V_125 ) |
( V_12 -> V_56 << V_126 ) |
( V_12 -> V_50 << V_127 ) ) ;
}
static bool F_131 ( const struct V_7 * V_12 , T_2 T_3 * * V_151 )
{
if ( ! * V_151 )
return true ;
if ( F_123 ( F_130 ( V_12 ) , * V_151 ) )
return false ;
( * V_151 ) ++ ;
return true ;
}
static int F_132 ( struct V_3 * V_4 , T_2 T_3 * V_151 )
{
const struct V_7 * V_152 , * V_153 , * V_154 , * V_155 ;
unsigned int V_156 = 0 ;
T_5 V_79 ;
V_152 = F_85 ( V_4 -> V_16 . V_74 , true , & V_79 ) ;
V_154 = V_152 + V_79 ;
V_153 = V_109 ;
V_155 = V_109 + F_107 ( V_109 ) ;
F_10 ( V_152 == V_154 || V_153 == V_155 ) ;
while ( V_152 || V_153 ) {
int V_157 = F_133 ( V_152 , V_153 ) ;
if ( V_157 <= 0 ) {
if ( V_152 -> V_12 ) {
if ( ! F_131 ( V_152 , & V_151 ) )
return - V_27 ;
V_156 ++ ;
}
} else {
if ( V_153 -> V_12 ) {
if ( ! F_131 ( V_153 , & V_151 ) )
return - V_27 ;
V_156 ++ ;
}
}
if ( V_157 <= 0 && ++ V_152 == V_154 )
V_152 = NULL ;
if ( V_157 >= 0 && ++ V_153 == V_155 )
V_153 = NULL ;
}
return V_156 ;
}
unsigned long F_134 ( struct V_3 * V_4 )
{
return F_107 ( V_130 )
+ F_128 ()
+ F_132 ( V_4 , ( T_2 T_3 * ) NULL ) ;
}
int F_135 ( struct V_3 * V_4 , T_2 T_3 * V_148 )
{
unsigned int V_110 ;
int V_131 ;
for ( V_110 = 0 ; V_110 < F_107 ( V_130 ) ; V_110 ++ ) {
if ( F_123 ( F_130 ( & V_130 [ V_110 ] ) , V_148 ) )
return - V_27 ;
V_148 ++ ;
}
V_131 = F_132 ( V_4 , V_148 ) ;
if ( V_131 < 0 )
return V_131 ;
V_148 += V_131 ;
return F_129 ( V_148 ) ;
}
static int F_136 ( const struct V_7 * V_76 , unsigned int V_158 )
{
unsigned int V_110 ;
for ( V_110 = 1 ; V_110 < V_158 ; V_110 ++ ) {
if ( F_133 ( & V_76 [ V_110 - 1 ] , & V_76 [ V_110 ] ) >= 0 ) {
F_98 ( L_3 , V_76 , V_110 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_137 ( void )
{
unsigned int V_110 ;
struct V_7 V_159 ;
F_10 ( F_136 ( V_109 , F_107 ( V_109 ) ) ) ;
F_10 ( F_136 ( V_108 , F_107 ( V_108 ) ) ) ;
F_10 ( F_136 ( V_107 , F_107 ( V_107 ) ) ) ;
F_10 ( F_136 ( V_106 , F_107 ( V_106 ) ) ) ;
F_10 ( F_136 ( V_105 , F_107 ( V_105 ) ) ) ;
F_10 ( F_136 ( V_130 , F_107 ( V_130 ) ) ) ;
for ( V_110 = 0 ; V_110 < F_107 ( V_130 ) ; V_110 ++ )
V_130 [ V_110 ] . V_111 ( NULL , & V_130 [ V_110 ] ) ;
F_138 ( NULL , & V_159 ) ;
V_136 = V_159 . V_15 ;
for ( V_110 = 0 ; V_110 < 7 ; V_110 ++ )
if ( ( ( V_136 >> ( V_110 * 3 ) ) & 7 ) == 0 )
break;
V_136 &= ( 1 << ( V_110 * 3 ) ) - 1 ;
}
void F_139 ( struct V_3 * V_4 )
{
T_5 V_79 ;
const struct V_7 * V_76 ;
memset ( & V_4 -> V_16 . V_160 . V_161 , 0x42 , sizeof( V_4 -> V_16 . V_160 . V_161 ) ) ;
F_112 ( V_4 , V_109 , F_107 ( V_109 ) ) ;
V_76 = F_85 ( V_4 -> V_16 . V_74 , true , & V_79 ) ;
F_112 ( V_4 , V_76 , V_79 ) ;
for ( V_79 = 1 ; V_79 < V_162 ; V_79 ++ )
if ( F_11 ( V_4 , V_79 ) == 0x4242424242424242 )
F_140 ( L_4 , V_79 ) ;
}
