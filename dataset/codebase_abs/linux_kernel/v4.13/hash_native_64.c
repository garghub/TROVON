static inline void F_1 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
V_5 = V_1 << V_8 ;
if ( F_2 ( V_9 ) )
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_10 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_7 = F_3 ( V_3 ) ;
V_5 |= V_7 << 5 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,0", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_6 = V_11 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_11 [ V_3 ] . V_12 ) - 1 ) ;
V_5 |= V_6 << 12 ;
V_5 |= V_4 << 8 ;
V_5 |= ( V_1 & 0xfe ) ;
V_5 |= 1 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,1", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
}
F_4 ( 0 , 0 , V_5 , 0 , 0 , 0 , 0 ) ;
}
static inline void F_5 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
V_5 = V_1 << V_8 ;
if ( F_2 ( V_9 ) )
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_10 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_7 = F_3 ( V_3 ) ;
V_5 |= V_7 << 5 ;
asm volatile(ASM_FTR_IFSET("tlbiel %0", "tlbiel %0,0", %1)
: : "r" (va), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_6 = V_11 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_11 [ V_3 ] . V_12 ) - 1 ) ;
V_5 |= V_6 << 12 ;
V_5 |= V_4 << 8 ;
V_5 |= ( V_1 & 0xfe ) ;
V_5 |= 1 ;
asm volatile(ASM_FTR_IFSET("tlbiel %0", "tlbiel %0,1", %1)
: : "r" (va), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
}
F_4 ( 0 , 1 , V_5 , 0 , 0 , 0 , 0 ) ;
}
static inline void F_6 ( unsigned long V_1 , int V_2 , int V_3 ,
int V_4 , int V_13 )
{
unsigned int V_14 ;
int V_15 = ! F_2 ( V_16 ) ;
V_14 = V_13 && F_2 ( V_17 ) && ! F_7 () ;
if ( V_14 )
V_14 = V_11 [ V_2 ] . V_18 ;
if ( V_15 && ! V_14 )
F_8 ( & V_19 ) ;
asm volatile("ptesync": : :"memory");
if ( V_14 ) {
F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_15 && ! V_14 )
F_9 ( & V_19 ) ;
}
static inline void F_10 ( struct V_20 * V_21 )
{
unsigned long * V_22 = ( unsigned long * ) & V_21 -> V_23 ;
while ( 1 ) {
if ( ! F_11 ( V_24 , V_22 ) )
break;
F_12 () ;
while( F_13 ( V_24 , V_22 ) )
F_14 () ;
F_15 () ;
}
}
static inline void F_16 ( struct V_20 * V_21 )
{
unsigned long * V_22 = ( unsigned long * ) & V_21 -> V_23 ;
F_17 ( V_24 , V_22 ) ;
}
static long F_18 ( unsigned long V_25 , unsigned long V_1 ,
unsigned long V_26 , unsigned long V_27 ,
unsigned long V_28 , int V_2 , int V_3 , int V_4 )
{
struct V_20 * V_21 = V_29 + V_25 ;
unsigned long V_30 , V_31 ;
int V_32 ;
if ( ! ( V_28 & V_33 ) ) {
F_19 ( L_1
L_2 ,
V_25 , V_1 , V_26 , V_27 , V_28 , V_2 ) ;
}
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
if ( ! ( F_20 ( V_21 -> V_23 ) & V_35 ) ) {
F_10 ( V_21 ) ;
if ( ! ( F_20 ( V_21 -> V_23 ) & V_35 ) )
break;
F_16 ( V_21 ) ;
}
V_21 ++ ;
}
if ( V_32 == V_34 )
return - 1 ;
V_30 = F_21 ( V_1 , V_2 , V_3 , V_4 ) | V_28 | V_35 ;
V_31 = F_22 ( V_26 , V_2 , V_3 ) | V_27 ;
if ( ! ( V_28 & V_33 ) ) {
F_19 ( L_3 ,
V_32 , V_30 , V_31 ) ;
}
if ( F_23 ( V_36 ) ) {
V_31 = F_24 ( V_30 , V_31 ) ;
V_30 = F_25 ( V_30 ) ;
}
V_21 -> V_37 = F_26 ( V_31 ) ;
F_27 () ;
V_21 -> V_23 = F_26 ( V_30 ) ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_32 | ( ! ! ( V_28 & V_38 ) << 3 ) ;
}
static long F_28 ( unsigned long V_25 )
{
struct V_20 * V_21 ;
int V_32 ;
int V_39 ;
unsigned long V_30 ;
F_19 ( L_4 , V_25 ) ;
V_39 = F_29 () & 0x7 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_25 + V_39 ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 ) && ! ( V_30 & V_33 ) ) {
F_10 ( V_21 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 )
&& ! ( V_30 & V_33 ) )
break;
F_16 ( V_21 ) ;
}
V_39 ++ ;
V_39 &= 0x7 ;
}
if ( V_32 == V_34 )
return - 1 ;
V_21 -> V_23 = 0 ;
return V_32 ;
}
static long F_30 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_1 , int V_42 ,
int V_3 , int V_4 , unsigned long V_43 )
{
struct V_20 * V_21 = V_29 + V_40 ;
unsigned long V_30 , V_44 ;
int V_45 = 0 , V_13 = 0 ;
V_44 = F_31 ( V_1 , V_42 , V_4 ) ;
F_19 ( L_5 ,
V_1 , V_44 & V_46 , V_40 , V_41 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 , F_20 ( V_21 -> V_37 ) ) ;
if ( ! F_33 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) ) {
F_19 ( L_6 ) ;
V_45 = - 1 ;
} else {
F_10 ( V_21 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 , F_20 ( V_21 -> V_37 ) ) ;
if ( F_34 ( ! F_33 ( V_30 , V_44 ) ||
! ( V_30 & V_35 ) ) ) {
V_45 = - 1 ;
} else {
F_19 ( L_7 ) ;
V_21 -> V_37 = F_26 ( ( F_20 ( V_21 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 |
V_49 ) ) ) ;
}
F_16 ( V_21 ) ;
}
if ( V_43 & V_50 )
V_13 = 1 ;
if ( ! ( V_43 & V_51 ) )
F_6 ( V_1 , V_42 , V_3 , V_4 , V_13 ) ;
return V_45 ;
}
static long F_35 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_20 * V_21 ;
unsigned long V_52 ;
unsigned long V_32 ;
long V_40 ;
unsigned long V_44 , V_30 ;
V_52 = F_36 ( V_1 , V_11 [ V_2 ] . V_12 , V_4 ) ;
V_44 = F_31 ( V_1 , V_2 , V_4 ) ;
V_40 = ( V_52 & V_53 ) * V_34 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_40 ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 , F_20 ( V_21 -> V_37 ) ) ;
if ( F_33 ( V_30 , V_44 ) && ( V_30 & V_35 ) )
return V_40 ;
++ V_40 ;
}
return - 1 ;
}
static void F_37 ( unsigned long V_41 , unsigned long V_54 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_55 ;
long V_40 ;
struct V_20 * V_21 ;
V_55 = F_38 ( V_54 , V_4 ) ;
V_1 = F_39 ( V_54 , V_55 , V_4 ) ;
V_40 = F_35 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
F_40 ( L_8 ) ;
V_21 = V_29 + V_40 ;
V_21 -> V_37 = F_26 ( ( F_20 ( V_21 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 ) ) ) ;
F_6 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static int F_41 ( unsigned long V_54 , int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_55 ;
long V_40 ;
struct V_20 * V_21 ;
V_55 = F_38 ( V_54 , V_4 ) ;
V_1 = F_39 ( V_54 , V_55 , V_4 ) ;
V_40 = F_35 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
return - V_56 ;
V_21 = V_29 + V_40 ;
F_42 ( ! ( F_20 ( V_21 -> V_23 ) & V_33 ) ) ;
V_21 -> V_23 = 0 ;
F_6 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
return 0 ;
}
static void F_43 ( unsigned long V_40 , unsigned long V_1 ,
int V_42 , int V_3 , int V_4 , int V_13 )
{
struct V_20 * V_21 = V_29 + V_40 ;
unsigned long V_30 ;
unsigned long V_44 ;
unsigned long V_43 ;
F_44 ( V_43 ) ;
F_19 ( L_9 , V_1 , V_40 ) ;
V_44 = F_31 ( V_1 , V_42 , V_4 ) ;
F_10 ( V_21 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 , F_20 ( V_21 -> V_37 ) ) ;
if ( ! F_33 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) )
F_16 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_6 ( V_1 , V_42 , V_3 , V_4 , V_13 ) ;
F_45 ( V_43 ) ;
}
static void F_46 ( unsigned long V_55 ,
unsigned long V_57 ,
unsigned char * V_58 ,
int V_2 , int V_4 , int V_13 )
{
int V_32 ;
struct V_20 * V_21 ;
int V_59 = V_60 ;
unsigned int V_61 , V_62 ;
unsigned long V_43 , V_63 = V_57 ;
unsigned long V_30 , V_44 , V_12 ;
unsigned long V_64 , V_1 = 0 , V_52 , V_40 ;
V_12 = V_11 [ V_2 ] . V_12 ;
V_61 = 1U << ( V_65 - V_12 ) ;
F_44 ( V_43 ) ;
for ( V_32 = 0 ; V_32 < V_61 ; V_32 ++ ) {
V_62 = F_47 ( V_58 , V_32 ) ;
if ( ! V_62 )
continue;
V_64 = F_48 ( V_58 , V_32 ) ;
V_57 = V_63 + ( V_32 * ( 1ul << V_12 ) ) ;
V_1 = F_39 ( V_57 , V_55 , V_4 ) ;
V_52 = F_36 ( V_1 , V_12 , V_4 ) ;
if ( V_64 & V_66 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_34 ;
V_40 += V_64 & V_67 ;
V_21 = V_29 + V_40 ;
V_44 = F_31 ( V_1 , V_2 , V_4 ) ;
F_10 ( V_21 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 , F_20 ( V_21 -> V_37 ) ) ;
if ( ! F_33 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) )
F_16 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_6 ( V_1 , V_2 , V_59 , V_4 , V_13 ) ;
}
F_45 ( V_43 ) ;
}
static void F_46 ( unsigned long V_55 ,
unsigned long V_57 ,
unsigned char * V_58 ,
int V_2 , int V_4 , int V_13 )
{
F_49 ( 1 , L_10 , V_68 ) ;
}
static void F_50 ( struct V_20 * V_69 , unsigned long V_40 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_70 , V_71 , V_72 ;
unsigned long V_30 = F_20 ( V_69 -> V_23 ) ;
unsigned long V_31 = F_20 ( V_69 -> V_37 ) ;
unsigned long V_55 , V_73 ;
int V_74 , V_75 , V_12 ;
unsigned int V_76 = ( V_31 >> V_77 ) & ( ( 1 << V_78 ) - 1 ) ;
if ( F_23 ( V_36 ) ) {
V_30 = F_32 ( V_30 , V_31 ) ;
V_31 = F_51 ( V_31 ) ;
}
if ( ! ( V_30 & V_79 ) ) {
V_74 = V_10 ;
V_75 = V_10 ;
} else {
V_74 = V_80 [ V_76 ] & 0xf ;
V_75 = V_80 [ V_76 ] >> 4 ;
}
* V_4 = V_30 >> V_81 ;
V_12 = V_11 [ V_74 ] . V_12 ;
V_70 = ( F_52 ( V_30 ) & ~ V_11 [ V_74 ] . V_82 ) ;
V_71 = V_40 / V_34 ;
if ( V_30 & V_38 )
V_71 = ~ V_71 ;
switch ( * V_4 ) {
case V_83 :
V_73 = ( V_70 & 0x1f ) << 23 ;
V_55 = V_70 >> 5 ;
if ( V_12 < 23 ) {
V_72 = ( V_55 ^ V_71 ) & V_53 ;
V_73 |= V_72 << V_12 ;
}
* V_1 = V_55 << ( V_84 - V_8 ) | V_73 >> V_8 ;
break;
case V_85 :
V_73 = ( V_70 & 0x1ffff ) << 23 ;
V_55 = V_70 >> 17 ;
if ( V_12 < 23 ) {
V_72 = ( V_55 ^ ( V_55 << 25 ) ^ V_71 ) & V_53 ;
V_73 |= V_72 << V_12 ;
}
* V_1 = V_55 << ( V_86 - V_8 ) | V_73 >> V_8 ;
break;
default:
* V_1 = V_74 = 0 ;
}
* V_2 = V_74 ;
* V_3 = V_75 ;
}
static void F_53 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_40 , V_87 ;
struct V_20 * V_21 = V_29 ;
unsigned long V_30 ;
unsigned long V_88 ;
int V_2 , V_3 , V_4 ;
V_88 = V_53 + 1 ;
V_87 = V_88 * V_34 ;
for ( V_40 = 0 ; V_40 < V_87 ; V_40 ++ , V_21 ++ ) {
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( V_30 & V_35 ) {
F_50 ( V_21 , V_40 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_21 -> V_23 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
}
static void F_54 ( unsigned long V_89 , int V_13 )
{
unsigned long V_1 ;
unsigned long V_52 , V_90 , V_64 , V_12 , V_40 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
unsigned long V_44 ;
unsigned long V_43 ;
T_1 V_91 ;
struct V_92 * V_93 = F_55 ( & V_92 ) ;
unsigned long V_2 = V_93 -> V_2 ;
int V_4 = V_93 -> V_4 ;
int V_32 ;
unsigned int V_14 ;
V_14 = V_13 && F_2 ( V_17 ) &&
V_11 [ V_2 ] . V_18 && ! F_7 () ;
F_44 ( V_43 ) ;
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
V_1 = V_93 -> V_1 [ V_32 ] ;
V_91 = V_93 -> V_91 [ V_32 ] ;
F_56 (pte, psize, vpn, index, shift) {
V_52 = F_36 ( V_1 , V_12 , V_4 ) ;
V_64 = F_57 ( V_91 , V_90 ) ;
if ( V_64 & V_66 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_34 ;
V_40 += V_64 & V_67 ;
V_21 = V_29 + V_40 ;
V_44 = F_31 ( V_1 , V_2 , V_4 ) ;
F_10 ( V_21 ) ;
V_30 = F_20 ( V_21 -> V_23 ) ;
if ( F_23 ( V_36 ) )
V_30 = F_32 ( V_30 ,
F_20 ( V_21 -> V_37 ) ) ;
if ( ! F_33 ( V_30 , V_44 ) ||
! ( V_30 & V_35 ) )
F_16 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
} F_58 () ;
}
if ( V_14 ) {
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
V_1 = V_93 -> V_1 [ V_32 ] ;
V_91 = V_93 -> V_91 [ V_32 ] ;
F_56 (pte, psize,
vpn, index, shift) {
F_5 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_58 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_15 = ! F_2 ( V_16 ) ;
if ( V_15 )
F_8 ( & V_19 ) ;
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_89 ; V_32 ++ ) {
V_1 = V_93 -> V_1 [ V_32 ] ;
V_91 = V_93 -> V_91 [ V_32 ] ;
F_56 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_58 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_15 )
F_9 ( & V_19 ) ;
}
F_45 ( V_43 ) ;
}
static int F_59 ( unsigned long V_94 , unsigned long V_95 ,
unsigned long V_96 )
{
unsigned long V_97 = V_94 << 25 ;
V_97 |= ( V_95 << 5 ) ;
V_97 |= V_96 ;
V_98 -> V_97 = F_26 ( V_97 ) ;
return 0 ;
}
void T_2 F_60 ( void )
{
V_99 . V_100 = F_43 ;
V_99 . V_101 = F_30 ;
V_99 . V_102 = F_37 ;
V_99 . V_103 = F_41 ;
V_99 . V_104 = F_18 ;
V_99 . V_105 = F_28 ;
V_99 . V_106 = F_53 ;
V_99 . V_107 = F_54 ;
V_99 . V_108 = F_46 ;
if ( F_23 ( V_36 ) )
V_109 = F_59 ;
}
