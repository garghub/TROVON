static inline void F_1 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
V_5 = V_1 << V_8 ;
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_9 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_7 = ( ( V_10 [ V_3 ] . V_7 & V_11 ) >> 6 ) |
( ( V_10 [ V_3 ] . V_7 & V_12 ) >> 4 ) ;
V_5 |= V_7 << 5 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,0", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_6 = V_10 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_10 [ V_3 ] . V_13 ) - 1 ) ;
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
static inline void F_2 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
V_5 = V_1 << V_8 ;
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_9 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_7 = ( ( V_10 [ V_3 ] . V_7 & V_11 ) >> 6 ) |
( ( V_10 [ V_3 ] . V_7 & V_12 ) >> 4 ) ;
V_5 |= V_7 << 5 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (0 << 21)"
: : "r"(va) : "memory");
break;
default:
V_6 = V_10 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_10 [ V_3 ] . V_13 ) - 1 ) ;
V_5 |= V_6 << 12 ;
V_5 |= V_4 << 8 ;
V_5 |= ( V_1 & 0xfe ) ;
V_5 |= 1 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (1 << 21)"
: : "r"(va) : "memory");
break;
}
}
static inline void F_3 ( unsigned long V_1 , int V_2 , int V_3 ,
int V_4 , int V_14 )
{
unsigned int V_15 = V_14 && F_4 ( V_16 ) ;
int V_17 = ! F_4 ( V_18 ) ;
if ( V_15 )
V_15 = V_10 [ V_2 ] . V_19 ;
if ( V_17 && ! V_15 )
F_5 ( & V_20 ) ;
asm volatile("ptesync": : :"memory");
if ( V_15 ) {
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_17 && ! V_15 )
F_6 ( & V_20 ) ;
}
static inline void F_7 ( struct V_21 * V_22 )
{
unsigned long * V_23 = ( unsigned long * ) & V_22 -> V_24 ;
while ( 1 ) {
if ( ! F_8 ( V_25 , V_23 ) )
break;
while( F_9 ( V_25 , V_23 ) )
F_10 () ;
}
}
static inline void F_11 ( struct V_21 * V_22 )
{
unsigned long * V_23 = ( unsigned long * ) & V_22 -> V_24 ;
F_12 ( V_25 , V_23 ) ;
}
static long F_13 ( unsigned long V_26 , unsigned long V_1 ,
unsigned long V_27 , unsigned long V_28 ,
unsigned long V_29 , int V_2 , int V_3 , int V_4 )
{
struct V_21 * V_22 = V_30 + V_26 ;
unsigned long V_31 , V_32 ;
int V_33 ;
if ( ! ( V_29 & V_34 ) ) {
F_14 ( L_1
L_2 ,
V_26 , V_1 , V_27 , V_28 , V_29 , V_2 ) ;
}
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
if ( ! ( F_15 ( V_22 -> V_24 ) & V_36 ) ) {
F_7 ( V_22 ) ;
if ( ! ( F_15 ( V_22 -> V_24 ) & V_36 ) )
break;
F_11 ( V_22 ) ;
}
V_22 ++ ;
}
if ( V_33 == V_35 )
return - 1 ;
V_31 = F_16 ( V_1 , V_2 , V_3 , V_4 ) | V_29 | V_36 ;
V_32 = F_17 ( V_27 , V_2 , V_3 ) | V_28 ;
if ( ! ( V_29 & V_34 ) ) {
F_14 ( L_3 ,
V_33 , V_31 , V_32 ) ;
}
V_22 -> V_37 = F_18 ( V_32 ) ;
F_19 () ;
V_22 -> V_24 = F_18 ( V_31 ) ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_33 | ( ! ! ( V_29 & V_38 ) << 3 ) ;
}
static long F_20 ( unsigned long V_26 )
{
struct V_21 * V_22 ;
int V_33 ;
int V_39 ;
unsigned long V_31 ;
F_14 ( L_4 , V_26 ) ;
V_39 = F_21 () & 0x7 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_26 + V_39 ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ( V_31 & V_36 ) && ! ( V_31 & V_34 ) ) {
F_7 ( V_22 ) ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ( V_31 & V_36 )
&& ! ( V_31 & V_34 ) )
break;
F_11 ( V_22 ) ;
}
V_39 ++ ;
V_39 &= 0x7 ;
}
if ( V_33 == V_35 )
return - 1 ;
V_22 -> V_24 = 0 ;
return V_33 ;
}
static long F_22 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_1 , int V_42 ,
int V_3 , int V_4 , int V_14 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 , V_43 ;
int V_44 = 0 ;
V_43 = F_23 ( V_1 , V_42 , V_4 ) ;
F_14 ( L_5 ,
V_1 , V_43 & V_45 , V_40 , V_41 ) ;
F_7 ( V_22 ) ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ! F_24 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) ) {
F_14 ( L_6 ) ;
V_44 = - 1 ;
} else {
F_14 ( L_7 ) ;
V_22 -> V_37 = F_18 ( ( F_15 ( V_22 -> V_37 ) & ~ ( V_46 | V_47 ) ) |
( V_41 & ( V_46 | V_47 | V_48 ) ) ) ;
}
F_11 ( V_22 ) ;
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
return V_44 ;
}
static long F_25 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_21 * V_22 ;
unsigned long V_49 ;
unsigned long V_33 ;
long V_40 ;
unsigned long V_43 , V_31 ;
V_49 = F_26 ( V_1 , V_10 [ V_2 ] . V_13 , V_4 ) ;
V_43 = F_23 ( V_1 , V_2 , V_4 ) ;
V_40 = ( V_49 & V_50 ) * V_35 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_40 ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( F_24 ( V_31 , V_43 ) && ( V_31 & V_36 ) )
return V_40 ;
++ V_40 ;
}
return - 1 ;
}
static void F_27 ( unsigned long V_41 , unsigned long V_51 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_52 ;
long V_40 ;
struct V_21 * V_22 ;
V_52 = F_28 ( V_51 , V_4 ) ;
V_1 = F_29 ( V_51 , V_52 , V_4 ) ;
V_40 = F_25 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
F_30 ( L_8 ) ;
V_22 = V_30 + V_40 ;
V_22 -> V_37 = F_18 ( ( F_15 ( V_22 -> V_37 ) &
~ ( V_46 | V_47 ) ) |
( V_41 & ( V_46 | V_47 ) ) ) ;
F_3 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static void F_31 ( unsigned long V_40 , unsigned long V_1 ,
int V_42 , int V_3 , int V_4 , int V_14 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 ;
unsigned long V_43 ;
unsigned long V_53 ;
F_32 ( V_53 ) ;
F_14 ( L_9 , V_1 , V_40 ) ;
V_43 = F_23 ( V_1 , V_42 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ! F_24 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
F_33 ( V_53 ) ;
}
static void F_34 ( unsigned long V_52 ,
unsigned long V_54 ,
unsigned char * V_55 ,
int V_2 , int V_4 )
{
int V_33 ;
struct V_21 * V_22 ;
int V_56 = V_57 ;
unsigned int V_58 , V_59 ;
unsigned long V_53 , V_60 = V_54 ;
unsigned long V_31 , V_43 , V_13 ;
unsigned long V_61 , V_1 = 0 , V_49 , V_40 ;
V_13 = V_10 [ V_2 ] . V_13 ;
V_58 = 1U << ( V_62 - V_13 ) ;
F_32 ( V_53 ) ;
for ( V_33 = 0 ; V_33 < V_58 ; V_33 ++ ) {
V_59 = F_35 ( V_55 , V_33 ) ;
if ( ! V_59 )
continue;
V_61 = F_36 ( V_55 , V_33 ) ;
V_54 = V_60 + ( V_33 * ( 1ul << V_13 ) ) ;
V_1 = F_29 ( V_54 , V_52 , V_4 ) ;
V_49 = F_26 ( V_1 , V_13 , V_4 ) ;
if ( V_61 & V_63 )
V_49 = ~ V_49 ;
V_40 = ( V_49 & V_50 ) * V_35 ;
V_40 += V_61 & V_64 ;
V_22 = V_30 + V_40 ;
V_43 = F_23 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ! F_24 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
F_3 ( V_1 , V_2 , V_56 , V_4 , 0 ) ;
}
F_33 ( V_53 ) ;
}
static inline int F_37 ( unsigned int V_65 , int V_2 )
{
int V_33 , V_13 ;
unsigned int V_66 ;
for ( V_33 = 1 ; V_33 < V_67 ; V_33 ++ ) {
if ( V_10 [ V_2 ] . V_6 [ V_33 ] == - 1 )
continue;
V_13 = V_10 [ V_33 ] . V_13 - V_68 ;
if ( V_13 > V_69 )
V_13 = V_69 ;
V_66 = ( 1 << V_13 ) - 1 ;
if ( ( V_65 & V_66 ) == V_10 [ V_2 ] . V_6 [ V_33 ] )
return V_33 ;
}
return - 1 ;
}
static void F_38 ( struct V_21 * V_70 , unsigned long V_40 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_71 , V_72 , V_73 ;
unsigned long V_31 = F_15 ( V_70 -> V_24 ) ;
unsigned long V_32 = F_15 ( V_70 -> V_37 ) ;
unsigned long V_52 , V_74 ;
int V_75 , V_76 , V_13 ;
unsigned int V_65 = ( V_32 >> V_68 ) & ( ( 1 << V_69 ) - 1 ) ;
if ( ! ( V_31 & V_77 ) ) {
V_75 = V_9 ;
V_76 = V_9 ;
} else {
for ( V_75 = 0 ; V_75 < V_67 ; V_75 ++ ) {
if ( ! V_10 [ V_75 ] . V_13 )
continue;
V_76 = F_37 ( V_65 , V_75 ) ;
if ( V_76 != - 1 )
break;
}
}
* V_4 = V_31 >> V_78 ;
V_13 = V_10 [ V_75 ] . V_13 ;
V_71 = ( F_39 ( V_31 ) & ~ V_10 [ V_75 ] . V_79 ) ;
V_72 = V_40 / V_35 ;
if ( V_31 & V_38 )
V_72 = ~ V_72 ;
switch ( * V_4 ) {
case V_80 :
V_74 = ( V_71 & 0x1f ) << 23 ;
V_52 = V_71 >> 5 ;
if ( V_13 < 23 ) {
V_73 = ( V_52 ^ V_72 ) & V_50 ;
V_74 |= V_73 << V_13 ;
}
* V_1 = V_52 << ( V_81 - V_8 ) | V_74 >> V_8 ;
break;
case V_82 :
V_74 = ( V_71 & 0x1ffff ) << 23 ;
V_52 = V_71 >> 17 ;
if ( V_13 < 23 ) {
V_73 = ( V_52 ^ ( V_52 << 25 ) ^ V_72 ) & V_50 ;
V_74 |= V_73 << V_13 ;
}
* V_1 = V_52 << ( V_83 - V_8 ) | V_74 >> V_8 ;
break;
default:
* V_1 = V_75 = 0 ;
}
* V_2 = V_75 ;
* V_3 = V_76 ;
}
static void F_40 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_40 , V_84 , V_53 ;
struct V_21 * V_22 = V_30 ;
unsigned long V_31 ;
unsigned long V_85 ;
int V_2 , V_3 , V_4 ;
V_85 = V_50 + 1 ;
F_32 ( V_53 ) ;
F_5 ( & V_20 ) ;
V_84 = V_85 * V_35 ;
for ( V_40 = 0 ; V_40 < V_84 ; V_40 ++ , V_22 ++ ) {
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( V_31 & V_36 ) {
F_38 ( V_22 , V_40 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_22 -> V_24 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
F_6 ( & V_20 ) ;
F_33 ( V_53 ) ;
}
static void F_41 ( unsigned long V_86 , int V_14 )
{
unsigned long V_1 ;
unsigned long V_49 , V_87 , V_61 , V_13 , V_40 ;
struct V_21 * V_22 ;
unsigned long V_31 ;
unsigned long V_43 ;
unsigned long V_53 ;
T_1 V_88 ;
struct V_89 * V_90 = & F_42 ( V_89 ) ;
unsigned long V_2 = V_90 -> V_2 ;
int V_4 = V_90 -> V_4 ;
int V_33 ;
F_32 ( V_53 ) ;
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
V_1 = V_90 -> V_1 [ V_33 ] ;
V_88 = V_90 -> V_88 [ V_33 ] ;
F_43 (pte, psize, vpn, index, shift) {
V_49 = F_26 ( V_1 , V_13 , V_4 ) ;
V_61 = F_44 ( V_88 , V_87 ) ;
if ( V_61 & V_63 )
V_49 = ~ V_49 ;
V_40 = ( V_49 & V_50 ) * V_35 ;
V_40 += V_61 & V_64 ;
V_22 = V_30 + V_40 ;
V_43 = F_23 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = F_15 ( V_22 -> V_24 ) ;
if ( ! F_24 ( V_31 , V_43 ) ||
! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
} F_45 () ;
}
if ( F_4 ( V_16 ) &&
V_10 [ V_2 ] . V_19 && V_14 ) {
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
V_1 = V_90 -> V_1 [ V_33 ] ;
V_88 = V_90 -> V_88 [ V_33 ] ;
F_43 (pte, psize,
vpn, index, shift) {
F_2 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_45 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_17 = ! F_4 ( V_18 ) ;
if ( V_17 )
F_5 ( & V_20 ) ;
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
V_1 = V_90 -> V_1 [ V_33 ] ;
V_88 = V_90 -> V_88 [ V_33 ] ;
F_43 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_45 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_17 )
F_6 ( & V_20 ) ;
}
F_33 ( V_53 ) ;
}
void T_2 F_46 ( void )
{
V_91 . V_92 = F_31 ;
V_91 . V_93 = F_22 ;
V_91 . V_94 = F_27 ;
V_91 . V_95 = F_13 ;
V_91 . V_96 = F_20 ;
V_91 . V_97 = F_40 ;
V_91 . V_98 = F_41 ;
V_91 . V_99 = F_34 ;
}
