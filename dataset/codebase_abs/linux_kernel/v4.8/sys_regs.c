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
V_6 -> V_13 = V_4 -> V_15 . V_16 . V_17 . V_18 ;
return true ;
}
static bool F_21 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return F_20 ( V_4 , V_6 ) ;
else
return F_22 ( V_4 , V_6 ) ;
}
static bool F_23 ( struct V_3 * V_4 ,
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
static bool F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_1 V_19 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
V_6 -> V_13 = V_19 ;
return true ;
}
}
static bool F_25 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_11 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_15 . V_20 |= V_21 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_8 -> V_12 ) ;
}
F_26 ( V_22 , V_8 -> V_12 , V_6 -> V_9 , V_6 -> V_13 ) ;
return true ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_23 )
{
T_2 V_19 = V_6 -> V_13 ;
if ( V_6 -> V_14 ) {
V_19 &= 0xffffffffUL ;
V_19 |= ( ( * V_23 >> 32 ) << 32 ) ;
}
* V_23 = V_19 ;
V_4 -> V_15 . V_20 |= V_21 ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_23 )
{
V_6 -> V_13 = * V_23 ;
if ( V_6 -> V_14 )
V_6 -> V_13 &= 0xffffffffUL ;
}
static bool F_29 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_24 )
{
T_2 * V_23 = & V_4 -> V_15 . V_25 . V_26 [ V_24 -> V_12 ] ;
if ( V_6 -> V_9 )
F_27 ( V_4 , V_6 , V_23 ) ;
else
F_28 ( V_4 , V_6 , V_23 ) ;
F_26 ( V_22 , V_24 -> V_12 , V_6 -> V_9 , * V_23 ) ;
return true ;
}
static int F_30 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_26 [ V_24 -> V_12 ] ;
if ( F_31 ( V_8 , V_28 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_26 [ V_24 -> V_12 ] ;
if ( F_34 ( V_28 , V_8 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 ,
const struct V_7 * V_24 )
{
V_4 -> V_15 . V_25 . V_26 [ V_24 -> V_12 ] = V_24 -> V_19 ;
}
static bool F_36 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_24 )
{
T_2 * V_23 = & V_4 -> V_15 . V_25 . V_31 [ V_24 -> V_12 ] ;
if ( V_6 -> V_9 )
F_27 ( V_4 , V_6 , V_23 ) ;
else
F_28 ( V_4 , V_6 , V_23 ) ;
F_26 ( V_22 , V_24 -> V_12 , V_6 -> V_9 , * V_23 ) ;
return true ;
}
static int F_37 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_31 [ V_24 -> V_12 ] ;
if ( F_31 ( V_8 , V_28 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_31 [ V_24 -> V_12 ] ;
if ( F_34 ( V_28 , V_8 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 ,
const struct V_7 * V_24 )
{
V_4 -> V_15 . V_25 . V_31 [ V_24 -> V_12 ] = V_24 -> V_19 ;
}
static bool F_40 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_24 )
{
T_2 * V_23 = & V_4 -> V_15 . V_25 . V_32 [ V_24 -> V_12 ] ;
if ( V_6 -> V_9 )
F_27 ( V_4 , V_6 , V_23 ) ;
else
F_28 ( V_4 , V_6 , V_23 ) ;
F_26 ( V_22 , V_24 -> V_12 , V_6 -> V_9 ,
V_4 -> V_15 . V_25 . V_32 [ V_24 -> V_12 ] ) ;
return true ;
}
static int F_41 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_32 [ V_24 -> V_12 ] ;
if ( F_31 ( V_8 , V_28 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_32 [ V_24 -> V_12 ] ;
if ( F_34 ( V_28 , V_8 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 ,
const struct V_7 * V_24 )
{
V_4 -> V_15 . V_25 . V_32 [ V_24 -> V_12 ] = V_24 -> V_19 ;
}
static bool F_44 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_24 )
{
T_2 * V_23 = & V_4 -> V_15 . V_25 . V_33 [ V_24 -> V_12 ] ;
if ( V_6 -> V_9 )
F_27 ( V_4 , V_6 , V_23 ) ;
else
F_28 ( V_4 , V_6 , V_23 ) ;
F_26 ( V_22 , V_24 -> V_12 , V_6 -> V_9 , * V_23 ) ;
return true ;
}
static int F_45 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_33 [ V_24 -> V_12 ] ;
if ( F_31 ( V_8 , V_28 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , const struct V_7 * V_24 ,
const struct V_27 * V_12 , void T_3 * V_28 )
{
T_4 * V_8 = & V_4 -> V_15 . V_25 . V_33 [ V_24 -> V_12 ] ;
if ( F_34 ( V_28 , V_8 , F_32 ( V_12 -> V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 ,
const struct V_7 * V_24 )
{
V_4 -> V_15 . V_25 . V_33 [ V_24 -> V_12 ] = V_24 -> V_19 ;
}
static void F_48 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_34 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_11 ( V_4 , V_35 ) = V_34 ;
}
static void F_49 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_36 ;
V_36 = ( V_4 -> V_37 & 0x0f ) << F_50 ( 0 ) ;
V_36 |= ( ( V_4 -> V_37 >> 4 ) & 0xff ) << F_50 ( 1 ) ;
V_36 |= ( ( V_4 -> V_37 >> 12 ) & 0xff ) << F_50 ( 2 ) ;
F_11 ( V_4 , V_38 ) = ( 1ULL << 31 ) | V_36 ;
}
static void F_51 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_39 , V_19 ;
asm volatile("mrs %0, pmcr_el0\n" : "=r" (pmcr));
V_19 = ( ( V_39 & ~ V_40 )
| ( V_40 & 0xdecafbad ) ) & ( ~ V_41 ) ;
F_11 ( V_4 , V_42 ) = V_19 ;
}
static bool F_52 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_43 ) ;
return ! ( ( V_12 & V_44 ) || F_53 ( V_4 ) ) ;
}
static bool F_54 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_43 ) ;
return ! ( ( V_12 & ( V_45 | V_44 ) )
|| F_53 ( V_4 ) ) ;
}
static bool F_55 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_43 ) ;
return ! ( ( V_12 & ( V_46 | V_44 ) )
|| F_53 ( V_4 ) ) ;
}
static bool F_56 ( struct V_3 * V_4 )
{
T_2 V_12 = F_11 ( V_4 , V_43 ) ;
return ! ( ( V_12 & ( V_47 | V_44 ) )
|| F_53 ( V_4 ) ) ;
}
static bool F_57 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_19 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_52 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
V_19 = F_11 ( V_4 , V_42 ) ;
V_19 &= ~ V_40 ;
V_19 |= V_6 -> V_13 & V_40 ;
F_11 ( V_4 , V_42 ) = V_19 ;
F_59 ( V_4 , V_19 ) ;
} else {
V_19 = F_11 ( V_4 , V_42 )
& ~ ( V_48 | V_49 ) ;
V_6 -> V_13 = V_19 ;
}
return true ;
}
static bool F_60 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_56 ( V_4 ) )
return false ;
if ( V_6 -> V_9 )
F_11 ( V_4 , V_50 ) = V_6 -> V_13 ;
else
V_6 -> V_13 = F_11 ( V_4 , V_50 )
& V_51 ;
return true ;
}
static bool F_61 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_52 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
F_10 ( V_6 -> V_9 ) ;
if ( F_52 ( V_4 ) )
return false ;
if ( ! ( V_6 -> V_53 & 1 ) )
asm volatile("mrs %0, pmceid0_el0\n" : "=r" (pmceid));
else
asm volatile("mrs %0, pmceid1_el0\n" : "=r" (pmceid));
V_6 -> V_13 = V_52 ;
return true ;
}
static bool F_62 ( struct V_3 * V_4 , T_2 V_54 )
{
T_2 V_39 , V_19 ;
V_39 = F_11 ( V_4 , V_42 ) ;
V_19 = ( V_39 >> V_55 ) & V_56 ;
if ( V_54 >= V_19 && V_54 != V_57 )
return false ;
return true ;
}
static bool F_63 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_54 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( V_8 -> V_58 == 9 && V_8 -> V_59 == 13 ) {
if ( V_8 -> V_53 == 2 ) {
if ( F_56 ( V_4 ) )
return false ;
V_54 = F_11 ( V_4 , V_50 )
& V_51 ;
} else if ( V_8 -> V_53 == 0 ) {
if ( F_55 ( V_4 ) )
return false ;
V_54 = V_57 ;
} else {
F_64 () ;
}
} else if ( V_8 -> V_58 == 14 && ( V_8 -> V_59 & 12 ) == 8 ) {
if ( F_56 ( V_4 ) )
return false ;
V_54 = ( ( V_8 -> V_59 & 3 ) << 3 ) | ( V_8 -> V_53 & 7 ) ;
} else {
F_64 () ;
}
if ( ! F_62 ( V_4 , V_54 ) )
return false ;
if ( V_6 -> V_9 ) {
if ( F_52 ( V_4 ) )
return false ;
F_65 ( V_4 , V_54 , V_6 -> V_13 ) ;
} else {
V_6 -> V_13 = F_66 ( V_4 , V_54 ) ;
}
return true ;
}
static bool F_67 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_54 , V_12 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_52 ( V_4 ) )
return false ;
if ( V_8 -> V_58 == 9 && V_8 -> V_59 == 13 && V_8 -> V_53 == 1 ) {
V_54 = F_11 ( V_4 , V_50 ) & V_51 ;
V_12 = V_60 + V_54 ;
} else if ( V_8 -> V_58 == 14 && ( V_8 -> V_59 & 12 ) == 12 ) {
V_54 = ( ( V_8 -> V_59 & 3 ) << 3 ) | ( V_8 -> V_53 & 7 ) ;
if ( V_54 == V_57 )
V_12 = V_61 ;
else
V_12 = V_60 + V_54 ;
} else {
F_64 () ;
}
if ( ! F_62 ( V_4 , V_54 ) )
return false ;
if ( V_6 -> V_9 ) {
F_68 ( V_4 , V_6 -> V_13 , V_54 ) ;
F_11 ( V_4 , V_12 ) = V_6 -> V_13 & V_62 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_12 ) & V_62 ;
}
return true ;
}
static bool F_69 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_19 , V_63 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_52 ( V_4 ) )
return false ;
V_63 = F_70 ( V_4 ) ;
if ( V_6 -> V_9 ) {
V_19 = V_6 -> V_13 & V_63 ;
if ( V_8 -> V_53 & 0x1 ) {
F_11 ( V_4 , V_64 ) |= V_19 ;
F_71 ( V_4 , V_19 ) ;
} else {
F_11 ( V_4 , V_64 ) &= ~ V_19 ;
F_72 ( V_4 , V_19 ) ;
}
} else {
V_6 -> V_13 = F_11 ( V_4 , V_64 ) & V_63 ;
}
return true ;
}
static bool F_73 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_63 = F_70 ( V_4 ) ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( ! F_53 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
T_2 V_19 = V_6 -> V_13 & V_63 ;
if ( V_8 -> V_53 & 0x1 )
F_11 ( V_4 , V_65 ) |= V_19 ;
else
F_11 ( V_4 , V_65 ) &= ~ V_19 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_65 ) & V_63 ;
}
return true ;
}
static bool F_74 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_63 = F_70 ( V_4 ) ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_52 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
if ( V_8 -> V_59 & 0x2 )
F_75 ( V_4 , V_6 -> V_13 & V_63 ) ;
else
F_11 ( V_4 , V_66 ) &= ~ ( V_6 -> V_13 & V_63 ) ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_66 ) & V_63 ;
}
return true ;
}
static bool F_76 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_63 ;
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( F_54 ( V_4 ) )
return false ;
if ( V_6 -> V_9 ) {
V_63 = F_70 ( V_4 ) ;
F_77 ( V_4 , V_6 -> V_13 & V_63 ) ;
return true ;
}
return false ;
}
static bool F_78 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! F_58 ( V_4 ) )
return F_21 ( V_4 , V_6 , V_8 ) ;
if ( V_6 -> V_9 ) {
if ( ! F_53 ( V_4 ) )
return false ;
F_11 ( V_4 , V_43 ) = V_6 -> V_13
& V_67 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_43 )
& V_67 ;
}
return true ;
}
static bool F_79 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_2 V_68 = F_80 ( V_69 ) ;
T_2 V_70 = F_80 ( V_71 ) ;
T_1 V_72 = ! ! F_81 ( V_70 , V_73 ) ;
V_6 -> V_13 = ( ( ( ( V_68 >> V_74 ) & 0xf ) << 28 ) |
( ( ( V_68 >> V_75 ) & 0xf ) << 24 ) |
( ( ( V_68 >> V_76 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_72 << 14 ) | ( V_72 << 12 ) ) ;
return true ;
}
}
static bool F_82 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_83 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_15 . V_20 |= V_21 ;
} else {
V_6 -> V_13 = F_83 ( V_4 , V_8 -> V_12 ) ;
}
return true ;
}
static bool F_84 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_24 )
{
T_2 * V_23 = & V_4 -> V_15 . V_25 . V_26 [ V_24 -> V_12 ] ;
if ( V_6 -> V_9 ) {
T_2 V_19 = * V_23 ;
V_19 &= 0xffffffffUL ;
V_19 |= V_6 -> V_13 << 32 ;
* V_23 = V_19 ;
V_4 -> V_15 . V_20 |= V_21 ;
} else {
V_6 -> V_13 = * V_23 >> 32 ;
}
F_26 ( V_22 , V_24 -> V_12 , V_6 -> V_9 , * V_23 ) ;
return true ;
}
void F_85 ( unsigned int V_77 ,
struct V_78 * V_79 )
{
V_80 [ V_77 ] = V_79 ;
}
static const struct V_7 * F_86 ( unsigned V_77 ,
bool V_81 ,
T_5 * V_82 )
{
struct V_78 * V_79 ;
V_79 = V_80 [ V_77 ] ;
if ( V_81 ) {
* V_82 = V_79 -> V_83 . V_82 ;
return V_79 -> V_83 . V_79 ;
} else {
* V_82 = V_79 -> V_84 . V_82 ;
return V_79 -> V_84 . V_79 ;
}
}
static int F_87 ( const void * V_85 , const void * V_86 )
{
const unsigned long V_87 = ( unsigned long ) V_85 ;
const struct V_7 * V_8 = V_86 ;
return V_87 - F_88 ( V_8 ) ;
}
static const struct V_7 * F_89 ( const struct V_5 * V_88 ,
const struct V_7 V_79 [] ,
unsigned int V_82 )
{
unsigned long V_87 = F_88 ( V_88 ) ;
return bsearch ( ( void * ) V_87 , V_79 , V_82 , sizeof( V_79 [ 0 ] ) , F_87 ) ;
}
int F_90 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
F_91 ( V_4 ) ;
return 1 ;
}
static int F_92 ( struct V_3 * V_4 ,
struct V_5 * V_88 ,
const struct V_7 * V_79 ,
T_5 V_82 )
{
const struct V_7 * V_8 ;
if ( ! V_79 )
return - 1 ;
V_8 = F_89 ( V_88 , V_79 , V_82 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_91 ) ;
if ( F_93 ( V_8 -> V_91 ( V_4 , V_88 , V_8 ) ) ) {
F_94 ( V_4 , F_95 ( V_4 ) ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_96 ( struct V_3 * V_4 ,
struct V_5 * V_88 )
{
T_6 V_92 = F_97 ( V_4 ) ;
int V_93 = - 1 ;
switch( V_92 ) {
case V_94 :
case V_95 :
V_93 = 15 ;
break;
case V_96 :
case V_97 :
V_93 = 14 ;
break;
default:
F_98 ( 1 ) ;
}
F_99 ( L_1 ,
V_93 , * F_100 ( V_4 ) ) ;
F_101 ( V_88 ) ;
F_91 ( V_4 ) ;
}
static int F_102 ( struct V_3 * V_4 ,
const struct V_7 * V_98 ,
T_5 V_99 ,
const struct V_7 * V_100 ,
T_5 V_101 )
{
struct V_5 V_88 ;
T_1 V_102 = F_103 ( V_4 ) ;
int V_103 = ( V_102 >> 5 ) & 0xf ;
int V_104 = ( V_102 >> 10 ) & 0xf ;
V_88 . V_11 = true ;
V_88 . V_14 = false ;
V_88 . V_59 = ( V_102 >> 1 ) & 0xf ;
V_88 . V_9 = ( ( V_102 & 1 ) == 0 ) ;
V_88 . V_105 = 0 ;
V_88 . V_106 = ( V_102 >> 16 ) & 0xf ;
V_88 . V_53 = 0 ;
V_88 . V_58 = 0 ;
if ( V_88 . V_9 ) {
V_88 . V_13 = F_104 ( V_4 , V_103 ) & 0xffffffff ;
V_88 . V_13 |= F_104 ( V_4 , V_104 ) << 32 ;
}
if ( ! F_92 ( V_4 , & V_88 , V_100 , V_101 ) )
goto V_107;
if ( ! F_92 ( V_4 , & V_88 , V_98 , V_99 ) )
goto V_107;
F_96 ( V_4 , & V_88 ) ;
V_107:
if ( ! V_88 . V_9 ) {
F_105 ( V_4 , V_103 , F_15 ( V_88 . V_13 ) ) ;
F_105 ( V_4 , V_104 , F_13 ( V_88 . V_13 ) ) ;
}
return 1 ;
}
static int F_106 ( struct V_3 * V_4 ,
const struct V_7 * V_98 ,
T_5 V_99 ,
const struct V_7 * V_100 ,
T_5 V_101 )
{
struct V_5 V_88 ;
T_1 V_102 = F_103 ( V_4 ) ;
int V_103 = ( V_102 >> 5 ) & 0xf ;
V_88 . V_11 = true ;
V_88 . V_14 = true ;
V_88 . V_59 = ( V_102 >> 1 ) & 0xf ;
V_88 . V_13 = F_104 ( V_4 , V_103 ) ;
V_88 . V_9 = ( ( V_102 & 1 ) == 0 ) ;
V_88 . V_58 = ( V_102 >> 10 ) & 0xf ;
V_88 . V_105 = 0 ;
V_88 . V_106 = ( V_102 >> 14 ) & 0x7 ;
V_88 . V_53 = ( V_102 >> 17 ) & 0x7 ;
if ( ! F_92 ( V_4 , & V_88 , V_100 , V_101 ) ||
! F_92 ( V_4 , & V_88 , V_98 , V_99 ) ) {
if ( ! V_88 . V_9 )
F_105 ( V_4 , V_103 , V_88 . V_13 ) ;
return 1 ;
}
F_96 ( V_4 , & V_88 ) ;
return 1 ;
}
int F_107 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
const struct V_7 * V_100 ;
T_5 V_82 ;
V_100 = F_86 ( V_4 -> V_15 . V_77 , false , & V_82 ) ;
return F_102 ( V_4 ,
V_108 , F_108 ( V_108 ) ,
V_100 , V_82 ) ;
}
int F_109 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
const struct V_7 * V_100 ;
T_5 V_82 ;
V_100 = F_86 ( V_4 -> V_15 . V_77 , false , & V_82 ) ;
return F_106 ( V_4 ,
V_109 , F_108 ( V_109 ) ,
V_100 , V_82 ) ;
}
int F_110 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
return F_102 ( V_4 ,
V_110 , F_108 ( V_110 ) ,
NULL , 0 ) ;
}
int F_111 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
return F_106 ( V_4 ,
V_111 , F_108 ( V_111 ) ,
NULL , 0 ) ;
}
static int F_112 ( struct V_3 * V_4 ,
struct V_5 * V_88 )
{
T_5 V_82 ;
const struct V_7 * V_79 , * V_8 ;
V_79 = F_86 ( V_4 -> V_15 . V_77 , true , & V_82 ) ;
V_8 = F_89 ( V_88 , V_79 , V_82 ) ;
if ( ! V_8 )
V_8 = F_89 ( V_88 , V_112 , F_108 ( V_112 ) ) ;
if ( F_93 ( V_8 ) ) {
F_10 ( ! V_8 -> V_91 ) ;
if ( F_93 ( V_8 -> V_91 ( V_4 , V_88 , V_8 ) ) ) {
F_94 ( V_4 , F_95 ( V_4 ) ) ;
return 1 ;
}
} else {
F_99 ( L_2 ,
* F_100 ( V_4 ) ) ;
F_101 ( V_88 ) ;
}
F_91 ( V_4 ) ;
return 1 ;
}
static void F_113 ( struct V_3 * V_4 ,
const struct V_7 * V_79 , T_5 V_82 )
{
unsigned long V_113 ;
for ( V_113 = 0 ; V_113 < V_82 ; V_113 ++ )
if ( V_79 [ V_113 ] . V_114 )
V_79 [ V_113 ] . V_114 ( V_4 , & V_79 [ V_113 ] ) ;
}
int F_114 ( struct V_3 * V_4 , struct V_89 * V_90 )
{
struct V_5 V_88 ;
unsigned long V_115 = F_103 ( V_4 ) ;
int V_103 = ( V_115 >> 5 ) & 0x1f ;
int V_116 ;
F_115 ( V_115 ) ;
V_88 . V_11 = false ;
V_88 . V_14 = false ;
V_88 . V_105 = ( V_115 >> 20 ) & 3 ;
V_88 . V_106 = ( V_115 >> 14 ) & 0x7 ;
V_88 . V_58 = ( V_115 >> 10 ) & 0xf ;
V_88 . V_59 = ( V_115 >> 1 ) & 0xf ;
V_88 . V_53 = ( V_115 >> 17 ) & 0x7 ;
V_88 . V_13 = F_104 ( V_4 , V_103 ) ;
V_88 . V_9 = ! ( V_115 & 1 ) ;
V_116 = F_112 ( V_4 , & V_88 ) ;
if ( ! V_88 . V_9 )
F_105 ( V_4 , V_103 , V_88 . V_13 ) ;
return V_116 ;
}
static bool F_116 ( T_2 V_29 , struct V_5 * V_88 )
{
switch ( V_29 & V_117 ) {
case V_118 :
if ( V_29 & ~ ( V_119 | V_117
| V_120
| V_121
| V_122
| V_123
| V_124
| V_125 ) )
return false ;
V_88 -> V_105 = ( ( V_29 & V_121 )
>> V_126 ) ;
V_88 -> V_106 = ( ( V_29 & V_122 )
>> V_127 ) ;
V_88 -> V_58 = ( ( V_29 & V_123 )
>> V_128 ) ;
V_88 -> V_59 = ( ( V_29 & V_124 )
>> V_129 ) ;
V_88 -> V_53 = ( ( V_29 & V_125 )
>> V_130 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_117 ( struct V_3 * V_4 ,
T_2 V_29 )
{
T_5 V_82 ;
const struct V_7 * V_79 , * V_8 ;
struct V_5 V_88 ;
if ( ( V_29 & V_120 ) != V_131 )
return NULL ;
if ( ! F_116 ( V_29 , & V_88 ) )
return NULL ;
V_79 = F_86 ( V_4 -> V_15 . V_77 , true , & V_82 ) ;
V_8 = F_89 ( & V_88 , V_79 , V_82 ) ;
if ( ! V_8 )
V_8 = F_89 ( & V_88 , V_112 , F_108 ( V_112 ) ) ;
if ( V_8 && ! V_8 -> V_12 )
V_8 = NULL ;
return V_8 ;
}
static int F_118 ( T_2 * V_19 , const void T_3 * V_28 , T_2 V_29 )
{
if ( F_31 ( V_19 , V_28 , F_32 ( V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_119 ( void T_3 * V_28 , const T_2 * V_19 , T_2 V_29 )
{
if ( F_34 ( V_28 , V_19 , F_32 ( V_29 ) ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_120 ( T_2 V_29 , void T_3 * V_28 )
{
struct V_5 V_88 ;
const struct V_7 * V_8 ;
if ( ! F_116 ( V_29 , & V_88 ) )
return - V_132 ;
V_8 = F_89 ( & V_88 , V_133 , F_108 ( V_133 ) ) ;
if ( ! V_8 )
return - V_132 ;
return F_119 ( V_28 , & V_8 -> V_19 , V_29 ) ;
}
static int F_121 ( T_2 V_29 , void T_3 * V_28 )
{
struct V_5 V_88 ;
const struct V_7 * V_8 ;
int V_134 ;
T_2 V_19 = 0 ;
if ( ! F_116 ( V_29 , & V_88 ) )
return - V_132 ;
V_8 = F_89 ( & V_88 , V_133 , F_108 ( V_133 ) ) ;
if ( ! V_8 )
return - V_132 ;
V_134 = F_118 ( & V_19 , V_28 , V_29 ) ;
if ( V_134 )
return V_134 ;
if ( V_8 -> V_19 != V_19 )
return - V_135 ;
return 0 ;
}
static bool F_122 ( T_1 V_19 )
{
T_1 V_136 , V_137 ;
if ( V_19 >= V_138 )
return false ;
V_136 = ( V_19 >> 1 ) ;
V_137 = ( V_139 >> ( V_136 * 3 ) ) & 7 ;
switch ( V_137 ) {
case 0 :
return false ;
case 1 :
return ( V_19 & 1 ) ;
case 2 :
case 4 :
return ! ( V_19 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_123 ( T_2 V_29 , void T_3 * V_28 )
{
T_1 V_19 ;
T_1 T_3 * V_140 = V_28 ;
if ( V_29 & ~ ( V_119 | V_117 | V_120
| ( ( 1 << V_141 ) - 1 ) ) )
return - V_132 ;
switch ( V_29 & V_142 ) {
case V_143 :
if ( F_32 ( V_29 ) != 4 )
return - V_132 ;
V_19 = ( V_29 & V_144 )
>> V_145 ;
if ( ! F_122 ( V_19 ) )
return - V_132 ;
return F_124 ( F_1 ( V_19 ) , V_140 ) ;
default:
return - V_132 ;
}
}
static int F_125 ( T_2 V_29 , void T_3 * V_28 )
{
T_1 V_19 , V_146 ;
T_1 T_3 * V_140 = V_28 ;
if ( V_29 & ~ ( V_119 | V_117 | V_120
| ( ( 1 << V_141 ) - 1 ) ) )
return - V_132 ;
switch ( V_29 & V_142 ) {
case V_143 :
if ( F_32 ( V_29 ) != 4 )
return - V_132 ;
V_19 = ( V_29 & V_144 )
>> V_145 ;
if ( ! F_122 ( V_19 ) )
return - V_132 ;
if ( F_126 ( V_146 , V_140 ) )
return - V_30 ;
if ( V_146 != F_1 ( V_19 ) )
return - V_135 ;
return 0 ;
default:
return - V_132 ;
}
}
int F_127 ( struct V_3 * V_4 , const struct V_27 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_28 = ( void T_3 * ) ( unsigned long ) V_12 -> V_147 ;
if ( ( V_12 -> V_29 & V_120 ) == V_148 )
return F_123 ( V_12 -> V_29 , V_28 ) ;
if ( F_32 ( V_12 -> V_29 ) != sizeof( T_4 ) )
return - V_132 ;
V_8 = F_117 ( V_4 , V_12 -> V_29 ) ;
if ( ! V_8 )
return F_120 ( V_12 -> V_29 , V_28 ) ;
if ( V_8 -> F_126 )
return ( V_8 -> F_126 ) ( V_4 , V_8 , V_12 , V_28 ) ;
return F_119 ( V_28 , & F_11 ( V_4 , V_8 -> V_12 ) , V_12 -> V_29 ) ;
}
int F_128 ( struct V_3 * V_4 , const struct V_27 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_28 = ( void T_3 * ) ( unsigned long ) V_12 -> V_147 ;
if ( ( V_12 -> V_29 & V_120 ) == V_148 )
return F_125 ( V_12 -> V_29 , V_28 ) ;
if ( F_32 ( V_12 -> V_29 ) != sizeof( T_4 ) )
return - V_132 ;
V_8 = F_117 ( V_4 , V_12 -> V_29 ) ;
if ( ! V_8 )
return F_121 ( V_12 -> V_29 , V_28 ) ;
if ( V_8 -> V_149 )
return ( V_8 -> V_149 ) ( V_4 , V_8 , V_12 , V_28 ) ;
return F_118 ( & F_11 ( V_4 , V_8 -> V_12 ) , V_28 , V_12 -> V_29 ) ;
}
static unsigned int F_129 ( void )
{
unsigned int V_113 , V_150 = 0 ;
for ( V_113 = 0 ; V_113 < V_138 ; V_113 ++ )
if ( F_122 ( V_113 ) )
V_150 ++ ;
return V_150 ;
}
static int F_130 ( T_2 T_3 * V_151 )
{
T_2 V_19 = V_152 | V_153 | V_148 ;
unsigned int V_113 ;
V_19 |= V_143 ;
for ( V_113 = 0 ; V_113 < V_138 ; V_113 ++ ) {
if ( ! F_122 ( V_113 ) )
continue;
if ( F_124 ( V_19 | V_113 , V_151 ) )
return - V_30 ;
V_151 ++ ;
}
return 0 ;
}
static T_2 F_131 ( const struct V_7 * V_12 )
{
return ( V_152 | V_118 |
V_131 |
( V_12 -> V_105 << V_126 ) |
( V_12 -> V_106 << V_127 ) |
( V_12 -> V_58 << V_128 ) |
( V_12 -> V_59 << V_129 ) |
( V_12 -> V_53 << V_130 ) ) ;
}
static bool F_132 ( const struct V_7 * V_12 , T_2 T_3 * * V_154 )
{
if ( ! * V_154 )
return true ;
if ( F_124 ( F_131 ( V_12 ) , * V_154 ) )
return false ;
( * V_154 ) ++ ;
return true ;
}
static int F_133 ( struct V_3 * V_4 , T_2 T_3 * V_154 )
{
const struct V_7 * V_155 , * V_156 , * V_157 , * V_158 ;
unsigned int V_159 = 0 ;
T_5 V_82 ;
V_155 = F_86 ( V_4 -> V_15 . V_77 , true , & V_82 ) ;
V_157 = V_155 + V_82 ;
V_156 = V_112 ;
V_158 = V_112 + F_108 ( V_112 ) ;
F_10 ( V_155 == V_157 || V_156 == V_158 ) ;
while ( V_155 || V_156 ) {
int V_160 = F_134 ( V_155 , V_156 ) ;
if ( V_160 <= 0 ) {
if ( V_155 -> V_12 ) {
if ( ! F_132 ( V_155 , & V_154 ) )
return - V_30 ;
V_159 ++ ;
}
} else {
if ( V_156 -> V_12 ) {
if ( ! F_132 ( V_156 , & V_154 ) )
return - V_30 ;
V_159 ++ ;
}
}
if ( V_160 <= 0 && ++ V_155 == V_157 )
V_155 = NULL ;
if ( V_160 >= 0 && ++ V_156 == V_158 )
V_156 = NULL ;
}
return V_159 ;
}
unsigned long F_135 ( struct V_3 * V_4 )
{
return F_108 ( V_133 )
+ F_129 ()
+ F_133 ( V_4 , ( T_2 T_3 * ) NULL ) ;
}
int F_136 ( struct V_3 * V_4 , T_2 T_3 * V_151 )
{
unsigned int V_113 ;
int V_134 ;
for ( V_113 = 0 ; V_113 < F_108 ( V_133 ) ; V_113 ++ ) {
if ( F_124 ( F_131 ( & V_133 [ V_113 ] ) , V_151 ) )
return - V_30 ;
V_151 ++ ;
}
V_134 = F_133 ( V_4 , V_151 ) ;
if ( V_134 < 0 )
return V_134 ;
V_151 += V_134 ;
return F_130 ( V_151 ) ;
}
static int F_137 ( const struct V_7 * V_79 , unsigned int V_161 )
{
unsigned int V_113 ;
for ( V_113 = 1 ; V_113 < V_161 ; V_113 ++ ) {
if ( F_134 ( & V_79 [ V_113 - 1 ] , & V_79 [ V_113 ] ) >= 0 ) {
F_99 ( L_3 , V_79 , V_113 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_138 ( void )
{
unsigned int V_113 ;
struct V_7 V_162 ;
F_10 ( F_137 ( V_112 , F_108 ( V_112 ) ) ) ;
F_10 ( F_137 ( V_111 , F_108 ( V_111 ) ) ) ;
F_10 ( F_137 ( V_110 , F_108 ( V_110 ) ) ) ;
F_10 ( F_137 ( V_109 , F_108 ( V_109 ) ) ) ;
F_10 ( F_137 ( V_108 , F_108 ( V_108 ) ) ) ;
F_10 ( F_137 ( V_133 , F_108 ( V_133 ) ) ) ;
for ( V_113 = 0 ; V_113 < F_108 ( V_133 ) ; V_113 ++ )
V_133 [ V_113 ] . V_114 ( NULL , & V_133 [ V_113 ] ) ;
F_139 ( NULL , & V_162 ) ;
V_139 = V_162 . V_19 ;
for ( V_113 = 0 ; V_113 < 7 ; V_113 ++ )
if ( ( ( V_139 >> ( V_113 * 3 ) ) & 7 ) == 0 )
break;
V_139 &= ( 1 << ( V_113 * 3 ) ) - 1 ;
}
void F_140 ( struct V_3 * V_4 )
{
T_5 V_82 ;
const struct V_7 * V_79 ;
memset ( & V_4 -> V_15 . V_163 . V_164 , 0x42 , sizeof( V_4 -> V_15 . V_163 . V_164 ) ) ;
F_113 ( V_4 , V_112 , F_108 ( V_112 ) ) ;
V_79 = F_86 ( V_4 -> V_15 . V_77 , true , & V_82 ) ;
F_113 ( V_4 , V_79 , V_82 ) ;
for ( V_82 = 1 ; V_82 < V_165 ; V_82 ++ )
if ( F_11 ( V_4 , V_82 ) == 0x4242424242424242 )
F_141 ( L_4 , V_82 ) ;
}
