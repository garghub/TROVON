static inline void F_1 ( unsigned long V_1 , int V_2 , int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
V_4 = V_1 << V_6 ;
V_4 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_7 :
V_4 |= V_3 << 8 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,0", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_5 = V_8 [ V_2 ] . V_5 ;
V_4 &= ~ ( ( 1ul << V_8 [ V_2 ] . V_9 ) - 1 ) ;
V_4 |= V_5 << 12 ;
V_4 |= V_3 << 8 ;
V_4 |= 1 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,1", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
}
}
static inline void F_2 ( unsigned long V_1 , int V_2 , int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
V_4 = V_1 << V_6 ;
V_4 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_7 :
V_4 |= V_3 << 8 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (0 << 21)"
: : "r"(va) : "memory");
break;
default:
V_5 = V_8 [ V_2 ] . V_5 ;
V_4 &= ~ ( ( 1ul << V_8 [ V_2 ] . V_9 ) - 1 ) ;
V_4 |= V_5 << 12 ;
V_4 |= V_3 << 8 ;
V_4 |= 1 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (1 << 21)"
: : "r"(va) : "memory");
break;
}
}
static inline void F_3 ( unsigned long V_1 , int V_2 , int V_3 , int V_10 )
{
unsigned int V_11 = V_10 && F_4 ( V_12 ) ;
int V_13 = ! F_4 ( V_14 ) ;
if ( V_11 )
V_11 = V_8 [ V_2 ] . V_15 ;
if ( V_13 && ! V_11 )
F_5 ( & V_16 ) ;
asm volatile("ptesync": : :"memory");
if ( V_11 ) {
F_2 ( V_1 , V_2 , V_3 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_13 && ! V_11 )
F_6 ( & V_16 ) ;
}
static inline void F_7 ( struct V_17 * V_18 )
{
unsigned long * V_19 = & V_18 -> V_20 ;
while ( 1 ) {
if ( ! F_8 ( V_21 , V_19 ) )
break;
while( F_9 ( V_21 , V_19 ) )
F_10 () ;
}
}
static inline void F_11 ( struct V_17 * V_18 )
{
unsigned long * V_19 = & V_18 -> V_20 ;
F_12 ( V_21 , V_19 ) ;
}
static long F_13 ( unsigned long V_22 , unsigned long V_1 ,
unsigned long V_23 , unsigned long V_24 ,
unsigned long V_25 , int V_2 , int V_3 )
{
struct V_17 * V_18 = V_26 + V_22 ;
unsigned long V_27 , V_28 ;
int V_29 ;
if ( ! ( V_25 & V_30 ) ) {
F_14 ( L_1
L_2 ,
V_22 , V_1 , V_23 , V_24 , V_25 , V_2 ) ;
}
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
if ( ! ( V_18 -> V_20 & V_32 ) ) {
F_7 ( V_18 ) ;
if ( ! ( V_18 -> V_20 & V_32 ) )
break;
F_11 ( V_18 ) ;
}
V_18 ++ ;
}
if ( V_29 == V_31 )
return - 1 ;
V_27 = F_15 ( V_1 , V_2 , V_3 ) | V_25 | V_32 ;
V_28 = F_16 ( V_23 , V_2 ) | V_24 ;
if ( ! ( V_25 & V_30 ) ) {
F_14 ( L_3 ,
V_29 , V_27 , V_28 ) ;
}
V_18 -> V_33 = V_28 ;
F_17 () ;
V_18 -> V_20 = V_27 ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_29 | ( ! ! ( V_25 & V_34 ) << 3 ) ;
}
static long F_18 ( unsigned long V_22 )
{
struct V_17 * V_18 ;
int V_29 ;
int V_35 ;
unsigned long V_27 ;
F_14 ( L_4 , V_22 ) ;
V_35 = F_19 () & 0x7 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_18 = V_26 + V_22 + V_35 ;
V_27 = V_18 -> V_20 ;
if ( ( V_27 & V_32 ) && ! ( V_27 & V_30 ) ) {
F_7 ( V_18 ) ;
V_27 = V_18 -> V_20 ;
if ( ( V_27 & V_32 )
&& ! ( V_27 & V_30 ) )
break;
F_11 ( V_18 ) ;
}
V_35 ++ ;
V_35 &= 0x7 ;
}
if ( V_29 == V_31 )
return - 1 ;
V_18 -> V_20 = 0 ;
return V_29 ;
}
static long F_20 ( unsigned long V_36 , unsigned long V_37 ,
unsigned long V_1 , int V_2 , int V_3 ,
int V_10 )
{
struct V_17 * V_18 = V_26 + V_36 ;
unsigned long V_27 , V_38 ;
int V_39 = 0 ;
V_38 = F_15 ( V_1 , V_2 , V_3 ) ;
F_14 ( L_5 ,
V_1 , V_38 & V_40 , V_36 , V_37 ) ;
F_7 ( V_18 ) ;
V_27 = V_18 -> V_20 ;
if ( ! F_21 ( V_27 , V_38 ) || ! ( V_27 & V_32 ) ) {
F_14 ( L_6 ) ;
V_39 = - 1 ;
} else {
F_14 ( L_7 ) ;
V_18 -> V_33 = ( V_18 -> V_33 & ~ ( V_41 | V_42 ) ) |
( V_37 & ( V_41 | V_42 | V_43 ) ) ;
}
F_11 ( V_18 ) ;
F_3 ( V_1 , V_2 , V_3 , V_10 ) ;
return V_39 ;
}
static long F_22 ( unsigned long V_1 , int V_2 , int V_3 )
{
struct V_17 * V_18 ;
unsigned long V_44 ;
unsigned long V_29 ;
long V_36 ;
unsigned long V_38 , V_27 ;
V_44 = F_23 ( V_1 , V_8 [ V_2 ] . V_9 , V_3 ) ;
V_38 = F_15 ( V_1 , V_2 , V_3 ) ;
V_36 = ( V_44 & V_45 ) * V_31 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_18 = V_26 + V_36 ;
V_27 = V_18 -> V_20 ;
if ( F_21 ( V_27 , V_38 ) && ( V_27 & V_32 ) )
return V_36 ;
++ V_36 ;
}
return - 1 ;
}
static void F_24 ( unsigned long V_37 , unsigned long V_46 ,
int V_2 , int V_3 )
{
unsigned long V_1 ;
unsigned long V_47 ;
long V_36 ;
struct V_17 * V_18 ;
V_47 = F_25 ( V_46 , V_3 ) ;
V_1 = F_26 ( V_46 , V_47 , V_3 ) ;
V_36 = F_22 ( V_1 , V_2 , V_3 ) ;
if ( V_36 == - 1 )
F_27 ( L_8 ) ;
V_18 = V_26 + V_36 ;
V_18 -> V_33 = ( V_18 -> V_33 & ~ ( V_41 | V_42 ) ) |
( V_37 & ( V_41 | V_42 ) ) ;
F_3 ( V_1 , V_2 , V_3 , 0 ) ;
}
static void F_28 ( unsigned long V_36 , unsigned long V_1 ,
int V_2 , int V_3 , int V_10 )
{
struct V_17 * V_18 = V_26 + V_36 ;
unsigned long V_27 ;
unsigned long V_38 ;
unsigned long V_48 ;
F_29 ( V_48 ) ;
F_14 ( L_9 , V_1 , V_36 ) ;
V_38 = F_15 ( V_1 , V_2 , V_3 ) ;
F_7 ( V_18 ) ;
V_27 = V_18 -> V_20 ;
if ( ! F_21 ( V_27 , V_38 ) || ! ( V_27 & V_32 ) )
F_11 ( V_18 ) ;
else
V_18 -> V_20 = 0 ;
F_3 ( V_1 , V_2 , V_3 , V_10 ) ;
F_30 ( V_48 ) ;
}
static void F_31 ( struct V_17 * V_49 , unsigned long V_36 ,
int * V_2 , int * V_3 , unsigned long * V_1 )
{
unsigned long V_50 , V_51 , V_52 ;
unsigned long V_28 = V_49 -> V_33 ;
unsigned long V_27 = V_49 -> V_20 ;
unsigned long V_47 , V_53 ;
int V_29 , V_54 , V_9 , V_5 ;
if ( ! ( V_27 & V_55 ) )
V_54 = V_7 ;
else {
for ( V_29 = 0 ; V_29 < V_56 ; V_29 ++ ) {
if ( ( V_28 & F_32 ( V_29 + 1 ) ) == F_32 ( V_29 + 1 ) )
break;
}
V_5 = F_32 ( V_29 + 1 ) >> V_57 ;
for ( V_54 = 0 ; V_54 < V_58 ; V_54 ++ ) {
if ( V_54 == V_7 )
continue;
if ( ! V_8 [ V_54 ] . V_9 )
continue;
if ( V_5 == V_8 [ V_54 ] . V_5 )
break;
}
}
* V_3 = V_27 >> V_59 ;
V_9 = V_8 [ V_54 ] . V_9 ;
V_50 = ( F_33 ( V_27 ) & ~ V_8 [ V_54 ] . V_60 ) ;
V_51 = V_36 / V_31 ;
if ( V_27 & V_34 )
V_51 = ~ V_51 ;
switch ( * V_3 ) {
case V_61 :
V_53 = ( V_50 & 0x1f ) << 23 ;
V_47 = V_50 >> 5 ;
if ( V_9 < 23 ) {
V_52 = ( V_47 ^ V_51 ) & V_45 ;
V_53 |= V_52 << V_9 ;
}
* V_1 = V_47 << ( V_62 - V_6 ) | V_53 >> V_6 ;
case V_63 :
V_53 = ( V_50 & 0x1ffff ) << 23 ;
V_47 = V_50 >> 17 ;
if ( V_9 < 23 ) {
V_52 = ( V_47 ^ ( V_47 << 25 ) ^ V_51 ) & V_45 ;
V_53 |= V_52 << V_9 ;
}
* V_1 = V_47 << ( V_64 - V_6 ) | V_53 >> V_6 ;
default:
* V_1 = V_54 = 0 ;
}
* V_2 = V_54 ;
}
static void F_34 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_36 , V_65 , V_48 ;
struct V_17 * V_18 = V_26 ;
unsigned long V_27 ;
unsigned long V_66 ;
int V_2 , V_3 ;
V_66 = V_45 + 1 ;
F_29 ( V_48 ) ;
F_5 ( & V_16 ) ;
V_65 = V_66 * V_31 ;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ , V_18 ++ ) {
V_27 = V_18 -> V_20 ;
if ( V_27 & V_32 ) {
F_31 ( V_18 , V_36 , & V_2 , & V_3 , & V_1 ) ;
V_18 -> V_20 = 0 ;
F_1 ( V_1 , V_2 , V_3 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
F_6 ( & V_16 ) ;
F_30 ( V_48 ) ;
}
static void F_35 ( unsigned long V_67 , int V_10 )
{
unsigned long V_1 ;
unsigned long V_44 , V_68 , V_69 , V_9 , V_36 ;
struct V_17 * V_18 ;
unsigned long V_27 ;
unsigned long V_38 ;
unsigned long V_48 ;
T_1 V_70 ;
struct V_71 * V_72 = & F_36 ( V_71 ) ;
unsigned long V_2 = V_72 -> V_2 ;
int V_3 = V_72 -> V_3 ;
int V_29 ;
F_29 ( V_48 ) ;
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
V_1 = V_72 -> V_1 [ V_29 ] ;
V_70 = V_72 -> V_70 [ V_29 ] ;
F_37 (pte, psize, vpn, index, shift) {
V_44 = F_23 ( V_1 , V_9 , V_3 ) ;
V_69 = F_38 ( V_70 , V_68 ) ;
if ( V_69 & V_73 )
V_44 = ~ V_44 ;
V_36 = ( V_44 & V_45 ) * V_31 ;
V_36 += V_69 & V_74 ;
V_18 = V_26 + V_36 ;
V_38 = F_15 ( V_1 , V_2 , V_3 ) ;
F_7 ( V_18 ) ;
V_27 = V_18 -> V_20 ;
if ( ! F_21 ( V_27 , V_38 ) ||
! ( V_27 & V_32 ) )
F_11 ( V_18 ) ;
else
V_18 -> V_20 = 0 ;
} F_39 () ;
}
if ( F_4 ( V_12 ) &&
V_8 [ V_2 ] . V_15 && V_10 ) {
asm volatile("ptesync":::"memory");
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
V_1 = V_72 -> V_1 [ V_29 ] ;
V_70 = V_72 -> V_70 [ V_29 ] ;
F_37 (pte, psize,
vpn, index, shift) {
F_2 ( V_1 , V_2 , V_3 ) ;
} F_39 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_13 = ! F_4 ( V_14 ) ;
if ( V_13 )
F_5 ( & V_16 ) ;
asm volatile("ptesync":::"memory");
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
V_1 = V_72 -> V_1 [ V_29 ] ;
V_70 = V_72 -> V_70 [ V_29 ] ;
F_37 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_3 ) ;
} F_39 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_13 )
F_6 ( & V_16 ) ;
}
F_30 ( V_48 ) ;
}
void T_2 F_40 ( void )
{
V_75 . V_76 = F_28 ;
V_75 . V_77 = F_20 ;
V_75 . V_78 = F_24 ;
V_75 . V_79 = F_13 ;
V_75 . V_80 = F_18 ;
V_75 . V_81 = F_34 ;
V_75 . V_82 = F_35 ;
}
