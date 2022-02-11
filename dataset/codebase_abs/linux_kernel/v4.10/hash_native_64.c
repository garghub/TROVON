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
}
static inline void F_4 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
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
}
static inline void F_5 ( unsigned long V_1 , int V_2 , int V_3 ,
int V_4 , int V_13 )
{
unsigned int V_14 ;
int V_15 = ! F_2 ( V_16 ) ;
V_14 = V_13 && F_2 ( V_17 ) && ! F_6 () ;
if ( V_14 )
V_14 = V_11 [ V_2 ] . V_18 ;
if ( V_15 && ! V_14 )
F_7 ( & V_19 ) ;
asm volatile("ptesync": : :"memory");
if ( V_14 ) {
F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_15 && ! V_14 )
F_8 ( & V_19 ) ;
}
static inline void F_9 ( struct V_20 * V_21 )
{
unsigned long * V_22 = ( unsigned long * ) & V_21 -> V_23 ;
while ( 1 ) {
if ( ! F_10 ( V_24 , V_22 ) )
break;
while( F_11 ( V_24 , V_22 ) )
F_12 () ;
}
}
static inline void F_13 ( struct V_20 * V_21 )
{
unsigned long * V_22 = ( unsigned long * ) & V_21 -> V_23 ;
F_14 ( V_24 , V_22 ) ;
}
static long F_15 ( unsigned long V_25 , unsigned long V_1 ,
unsigned long V_26 , unsigned long V_27 ,
unsigned long V_28 , int V_2 , int V_3 , int V_4 )
{
struct V_20 * V_21 = V_29 + V_25 ;
unsigned long V_30 , V_31 ;
int V_32 ;
if ( ! ( V_28 & V_33 ) ) {
F_16 ( L_1
L_2 ,
V_25 , V_1 , V_26 , V_27 , V_28 , V_2 ) ;
}
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
if ( ! ( F_17 ( V_21 -> V_23 ) & V_35 ) ) {
F_9 ( V_21 ) ;
if ( ! ( F_17 ( V_21 -> V_23 ) & V_35 ) )
break;
F_13 ( V_21 ) ;
}
V_21 ++ ;
}
if ( V_32 == V_34 )
return - 1 ;
V_30 = F_18 ( V_1 , V_2 , V_3 , V_4 ) | V_28 | V_35 ;
V_31 = F_19 ( V_26 , V_2 , V_3 ) | V_27 ;
if ( ! ( V_28 & V_33 ) ) {
F_16 ( L_3 ,
V_32 , V_30 , V_31 ) ;
}
if ( F_20 ( V_36 ) ) {
V_31 = F_21 ( V_30 , V_31 ) ;
V_30 = F_22 ( V_30 ) ;
}
V_21 -> V_37 = F_23 ( V_31 ) ;
F_24 () ;
V_21 -> V_23 = F_23 ( V_30 ) ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_32 | ( ! ! ( V_28 & V_38 ) << 3 ) ;
}
static long F_25 ( unsigned long V_25 )
{
struct V_20 * V_21 ;
int V_32 ;
int V_39 ;
unsigned long V_30 ;
F_16 ( L_4 , V_25 ) ;
V_39 = F_26 () & 0x7 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_25 + V_39 ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 ) && ! ( V_30 & V_33 ) ) {
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 )
&& ! ( V_30 & V_33 ) )
break;
F_13 ( V_21 ) ;
}
V_39 ++ ;
V_39 &= 0x7 ;
}
if ( V_32 == V_34 )
return - 1 ;
V_21 -> V_23 = 0 ;
return V_32 ;
}
static long F_27 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_1 , int V_42 ,
int V_3 , int V_4 , unsigned long V_43 )
{
struct V_20 * V_21 = V_29 + V_40 ;
unsigned long V_30 , V_44 ;
int V_45 = 0 , V_13 = 0 ;
V_44 = F_28 ( V_1 , V_42 , V_4 ) ;
F_16 ( L_5 ,
V_1 , V_44 & V_46 , V_40 , V_41 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 , F_17 ( V_21 -> V_37 ) ) ;
if ( ! F_30 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) ) {
F_16 ( L_6 ) ;
V_45 = - 1 ;
} else {
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 , F_17 ( V_21 -> V_37 ) ) ;
if ( F_31 ( ! F_30 ( V_30 , V_44 ) ||
! ( V_30 & V_35 ) ) ) {
V_45 = - 1 ;
} else {
F_16 ( L_7 ) ;
V_21 -> V_37 = F_23 ( ( F_17 ( V_21 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 |
V_49 ) ) ) ;
}
F_13 ( V_21 ) ;
}
if ( V_43 & V_50 )
V_13 = 1 ;
if ( ! ( V_43 & V_51 ) )
F_5 ( V_1 , V_42 , V_3 , V_4 , V_13 ) ;
return V_45 ;
}
static long F_32 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_20 * V_21 ;
unsigned long V_52 ;
unsigned long V_32 ;
long V_40 ;
unsigned long V_44 , V_30 ;
V_52 = F_33 ( V_1 , V_11 [ V_2 ] . V_12 , V_4 ) ;
V_44 = F_28 ( V_1 , V_2 , V_4 ) ;
V_40 = ( V_52 & V_53 ) * V_34 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_40 ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 , F_17 ( V_21 -> V_37 ) ) ;
if ( F_30 ( V_30 , V_44 ) && ( V_30 & V_35 ) )
return V_40 ;
++ V_40 ;
}
return - 1 ;
}
static void F_34 ( unsigned long V_41 , unsigned long V_54 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_55 ;
long V_40 ;
struct V_20 * V_21 ;
V_55 = F_35 ( V_54 , V_4 ) ;
V_1 = F_36 ( V_54 , V_55 , V_4 ) ;
V_40 = F_32 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
F_37 ( L_8 ) ;
V_21 = V_29 + V_40 ;
V_21 -> V_37 = F_23 ( ( F_17 ( V_21 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 ) ) ) ;
F_5 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static void F_38 ( unsigned long V_40 , unsigned long V_1 ,
int V_42 , int V_3 , int V_4 , int V_13 )
{
struct V_20 * V_21 = V_29 + V_40 ;
unsigned long V_30 ;
unsigned long V_44 ;
unsigned long V_43 ;
F_39 ( V_43 ) ;
F_16 ( L_9 , V_1 , V_40 ) ;
V_44 = F_28 ( V_1 , V_42 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 , F_17 ( V_21 -> V_37 ) ) ;
if ( ! F_30 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_5 ( V_1 , V_42 , V_3 , V_4 , V_13 ) ;
F_40 ( V_43 ) ;
}
static void F_41 ( unsigned long V_55 ,
unsigned long V_56 ,
unsigned char * V_57 ,
int V_2 , int V_4 , int V_13 )
{
int V_32 ;
struct V_20 * V_21 ;
int V_58 = V_59 ;
unsigned int V_60 , V_61 ;
unsigned long V_43 , V_62 = V_56 ;
unsigned long V_30 , V_44 , V_12 ;
unsigned long V_63 , V_1 = 0 , V_52 , V_40 ;
V_12 = V_11 [ V_2 ] . V_12 ;
V_60 = 1U << ( V_64 - V_12 ) ;
F_39 ( V_43 ) ;
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ ) {
V_61 = F_42 ( V_57 , V_32 ) ;
if ( ! V_61 )
continue;
V_63 = F_43 ( V_57 , V_32 ) ;
V_56 = V_62 + ( V_32 * ( 1ul << V_12 ) ) ;
V_1 = F_36 ( V_56 , V_55 , V_4 ) ;
V_52 = F_33 ( V_1 , V_12 , V_4 ) ;
if ( V_63 & V_65 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_34 ;
V_40 += V_63 & V_66 ;
V_21 = V_29 + V_40 ;
V_44 = F_28 ( V_1 , V_2 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 , F_17 ( V_21 -> V_37 ) ) ;
if ( ! F_30 ( V_30 , V_44 ) || ! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_5 ( V_1 , V_2 , V_58 , V_4 , V_13 ) ;
}
F_40 ( V_43 ) ;
}
static void F_41 ( unsigned long V_55 ,
unsigned long V_56 ,
unsigned char * V_57 ,
int V_2 , int V_4 , int V_13 )
{
F_44 ( 1 , L_10 , V_67 ) ;
}
static void F_45 ( struct V_20 * V_68 , unsigned long V_40 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_69 , V_70 , V_71 ;
unsigned long V_30 = F_17 ( V_68 -> V_23 ) ;
unsigned long V_31 = F_17 ( V_68 -> V_37 ) ;
unsigned long V_55 , V_72 ;
int V_73 , V_74 , V_12 ;
unsigned int V_75 = ( V_31 >> V_76 ) & ( ( 1 << V_77 ) - 1 ) ;
if ( F_20 ( V_36 ) ) {
V_30 = F_29 ( V_30 , V_31 ) ;
V_31 = F_46 ( V_31 ) ;
}
if ( ! ( V_30 & V_78 ) ) {
V_73 = V_10 ;
V_74 = V_10 ;
} else {
V_73 = V_79 [ V_75 ] & 0xf ;
V_74 = V_79 [ V_75 ] >> 4 ;
}
* V_4 = V_30 >> V_80 ;
V_12 = V_11 [ V_73 ] . V_12 ;
V_69 = ( F_47 ( V_30 ) & ~ V_11 [ V_73 ] . V_81 ) ;
V_70 = V_40 / V_34 ;
if ( V_30 & V_38 )
V_70 = ~ V_70 ;
switch ( * V_4 ) {
case V_82 :
V_72 = ( V_69 & 0x1f ) << 23 ;
V_55 = V_69 >> 5 ;
if ( V_12 < 23 ) {
V_71 = ( V_55 ^ V_70 ) & V_53 ;
V_72 |= V_71 << V_12 ;
}
* V_1 = V_55 << ( V_83 - V_8 ) | V_72 >> V_8 ;
break;
case V_84 :
V_72 = ( V_69 & 0x1ffff ) << 23 ;
V_55 = V_69 >> 17 ;
if ( V_12 < 23 ) {
V_71 = ( V_55 ^ ( V_55 << 25 ) ^ V_70 ) & V_53 ;
V_72 |= V_71 << V_12 ;
}
* V_1 = V_55 << ( V_85 - V_8 ) | V_72 >> V_8 ;
break;
default:
* V_1 = V_73 = 0 ;
}
* V_2 = V_73 ;
* V_3 = V_74 ;
}
static void F_48 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_40 , V_86 ;
struct V_20 * V_21 = V_29 ;
unsigned long V_30 ;
unsigned long V_87 ;
int V_2 , V_3 , V_4 ;
V_87 = V_53 + 1 ;
V_86 = V_87 * V_34 ;
for ( V_40 = 0 ; V_40 < V_86 ; V_40 ++ , V_21 ++ ) {
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( V_30 & V_35 ) {
F_45 ( V_21 , V_40 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_21 -> V_23 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
}
static void F_49 ( unsigned long V_88 , int V_13 )
{
unsigned long V_1 ;
unsigned long V_52 , V_89 , V_63 , V_12 , V_40 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
unsigned long V_44 ;
unsigned long V_43 ;
T_1 V_90 ;
struct V_91 * V_92 = F_50 ( & V_91 ) ;
unsigned long V_2 = V_92 -> V_2 ;
int V_4 = V_92 -> V_4 ;
int V_32 ;
F_39 ( V_43 ) ;
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ ) {
V_1 = V_92 -> V_1 [ V_32 ] ;
V_90 = V_92 -> V_90 [ V_32 ] ;
F_51 (pte, psize, vpn, index, shift) {
V_52 = F_33 ( V_1 , V_12 , V_4 ) ;
V_63 = F_52 ( V_90 , V_89 ) ;
if ( V_63 & V_65 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_34 ;
V_40 += V_63 & V_66 ;
V_21 = V_29 + V_40 ;
V_44 = F_28 ( V_1 , V_2 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_20 ( V_36 ) )
V_30 = F_29 ( V_30 ,
F_17 ( V_21 -> V_37 ) ) ;
if ( ! F_30 ( V_30 , V_44 ) ||
! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
} F_53 () ;
}
if ( F_2 ( V_17 ) &&
V_11 [ V_2 ] . V_18 && V_13 ) {
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ ) {
V_1 = V_92 -> V_1 [ V_32 ] ;
V_90 = V_92 -> V_90 [ V_32 ] ;
F_51 (pte, psize,
vpn, index, shift) {
F_4 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_53 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_15 = ! F_2 ( V_16 ) ;
if ( V_15 )
F_7 ( & V_19 ) ;
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ ) {
V_1 = V_92 -> V_1 [ V_32 ] ;
V_90 = V_92 -> V_90 [ V_32 ] ;
F_51 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_53 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_15 )
F_8 ( & V_19 ) ;
}
F_40 ( V_43 ) ;
}
static int F_54 ( unsigned long V_93 , unsigned long V_94 ,
unsigned long V_95 )
{
unsigned long V_96 = V_93 << 25 ;
V_96 |= ( V_94 << 5 ) ;
V_96 |= V_95 ;
V_97 -> V_96 = F_23 ( V_96 ) ;
return 0 ;
}
void T_2 F_55 ( void )
{
V_98 . V_99 = F_38 ;
V_98 . V_100 = F_27 ;
V_98 . V_101 = F_34 ;
V_98 . V_102 = F_15 ;
V_98 . V_103 = F_25 ;
V_98 . V_104 = F_48 ;
V_98 . V_105 = F_49 ;
V_98 . V_106 = F_41 ;
if ( F_20 ( V_36 ) )
V_107 = F_54 ;
}
