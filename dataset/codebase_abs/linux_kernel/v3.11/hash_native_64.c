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
if ( V_2 != V_3 ) {
V_5 |= ( V_1 & 0xfe ) ;
}
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
if ( V_2 != V_3 ) {
V_5 |= ( V_1 & 0xfe ) ;
}
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
unsigned long * V_23 = & V_22 -> V_24 ;
while ( 1 ) {
if ( ! F_8 ( V_25 , V_23 ) )
break;
while( F_9 ( V_25 , V_23 ) )
F_10 () ;
}
}
static inline void F_11 ( struct V_21 * V_22 )
{
unsigned long * V_23 = & V_22 -> V_24 ;
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
if ( ! ( V_22 -> V_24 & V_36 ) ) {
F_7 ( V_22 ) ;
if ( ! ( V_22 -> V_24 & V_36 ) )
break;
F_11 ( V_22 ) ;
}
V_22 ++ ;
}
if ( V_33 == V_35 )
return - 1 ;
V_31 = F_15 ( V_1 , V_2 , V_3 , V_4 ) | V_29 | V_36 ;
V_32 = F_16 ( V_27 , V_2 , V_3 ) | V_28 ;
if ( ! ( V_29 & V_34 ) ) {
F_14 ( L_3 ,
V_33 , V_31 , V_32 ) ;
}
V_22 -> V_37 = V_32 ;
F_17 () ;
V_22 -> V_24 = V_31 ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_33 | ( ! ! ( V_29 & V_38 ) << 3 ) ;
}
static long F_18 ( unsigned long V_26 )
{
struct V_21 * V_22 ;
int V_33 ;
int V_39 ;
unsigned long V_31 ;
F_14 ( L_4 , V_26 ) ;
V_39 = F_19 () & 0x7 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_26 + V_39 ;
V_31 = V_22 -> V_24 ;
if ( ( V_31 & V_36 ) && ! ( V_31 & V_34 ) ) {
F_7 ( V_22 ) ;
V_31 = V_22 -> V_24 ;
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
static long F_20 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_1 , int V_42 ,
int V_3 , int V_4 , int V_14 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 , V_43 ;
int V_44 = 0 ;
V_43 = F_21 ( V_1 , V_42 , V_4 ) ;
F_14 ( L_5 ,
V_1 , V_43 & V_45 , V_40 , V_41 ) ;
F_7 ( V_22 ) ;
V_31 = V_22 -> V_24 ;
if ( ! F_22 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) ) {
F_14 ( L_6 ) ;
V_44 = - 1 ;
} else {
F_14 ( L_7 ) ;
V_22 -> V_37 = ( V_22 -> V_37 & ~ ( V_46 | V_47 ) ) |
( V_41 & ( V_46 | V_47 | V_48 ) ) ;
}
F_11 ( V_22 ) ;
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
return V_44 ;
}
static long F_23 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_21 * V_22 ;
unsigned long V_49 ;
unsigned long V_33 ;
long V_40 ;
unsigned long V_43 , V_31 ;
V_49 = F_24 ( V_1 , V_10 [ V_2 ] . V_13 , V_4 ) ;
V_43 = F_21 ( V_1 , V_2 , V_4 ) ;
V_40 = ( V_49 & V_50 ) * V_35 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_40 ;
V_31 = V_22 -> V_24 ;
if ( F_22 ( V_31 , V_43 ) && ( V_31 & V_36 ) )
return V_40 ;
++ V_40 ;
}
return - 1 ;
}
static void F_25 ( unsigned long V_41 , unsigned long V_51 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_52 ;
long V_40 ;
struct V_21 * V_22 ;
V_52 = F_26 ( V_51 , V_4 ) ;
V_1 = F_27 ( V_51 , V_52 , V_4 ) ;
V_40 = F_23 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
F_28 ( L_8 ) ;
V_22 = V_30 + V_40 ;
V_22 -> V_37 = ( V_22 -> V_37 & ~ ( V_46 | V_47 ) ) |
( V_41 & ( V_46 | V_47 ) ) ;
F_3 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static void F_29 ( unsigned long V_40 , unsigned long V_1 ,
int V_42 , int V_3 , int V_4 , int V_14 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 ;
unsigned long V_43 ;
unsigned long V_53 ;
F_30 ( V_53 ) ;
F_14 ( L_9 , V_1 , V_40 ) ;
V_43 = F_21 ( V_1 , V_42 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = V_22 -> V_24 ;
if ( ! F_22 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
F_31 ( V_53 ) ;
}
static void F_32 ( struct V_54 * V_55 ,
unsigned char * V_56 ,
unsigned long V_57 , int V_2 )
{
int V_4 = 0 , V_33 ;
int V_17 ;
struct V_21 * V_22 ;
int V_58 = V_59 ;
unsigned int V_60 , V_61 ;
unsigned long V_53 , V_62 = V_57 ;
unsigned long V_31 , V_43 , V_13 ;
unsigned long V_63 , V_1 = 0 , V_52 , V_49 , V_40 ;
V_13 = V_10 [ V_2 ] . V_13 ;
V_60 = 1U << ( V_64 - V_13 ) ;
F_30 ( V_53 ) ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_61 = F_33 ( V_56 , V_33 ) ;
if ( ! V_61 )
continue;
V_63 = F_34 ( V_56 , V_33 ) ;
V_57 = V_62 + ( V_33 * ( 1ul << V_13 ) ) ;
if ( ! F_35 ( V_57 ) ) {
V_4 = F_36 ( V_57 ) ;
V_52 = F_37 ( V_55 -> V_65 . V_66 , V_57 , V_4 ) ;
F_38 ( V_52 == 0 ) ;
} else {
V_52 = F_26 ( V_57 , V_67 ) ;
V_4 = V_67 ;
}
V_1 = F_27 ( V_57 , V_52 , V_4 ) ;
V_49 = F_24 ( V_1 , V_13 , V_4 ) ;
if ( V_63 & V_68 )
V_49 = ~ V_49 ;
V_40 = ( V_49 & V_50 ) * V_35 ;
V_40 += V_63 & V_69 ;
V_22 = V_30 + V_40 ;
V_43 = F_21 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = V_22 -> V_24 ;
if ( ! F_22 ( V_31 , V_43 ) || ! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
}
V_17 = ! F_4 ( V_18 ) ;
if ( V_17 )
F_5 ( & V_20 ) ;
asm volatile("ptesync":::"memory");
F_1 ( V_1 , V_2 , V_58 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_17 )
F_6 ( & V_20 ) ;
F_31 ( V_53 ) ;
}
static inline int F_39 ( unsigned int V_70 , int V_2 )
{
int V_33 , V_13 ;
unsigned int V_71 ;
for ( V_33 = 1 ; V_33 < V_72 ; V_33 ++ ) {
if ( V_10 [ V_2 ] . V_6 [ V_33 ] == - 1 )
continue;
V_13 = V_10 [ V_33 ] . V_13 - V_73 ;
if ( V_13 > V_74 )
V_13 = V_74 ;
V_71 = ( 1 << V_13 ) - 1 ;
if ( ( V_70 & V_71 ) == V_10 [ V_2 ] . V_6 [ V_33 ] )
return V_33 ;
}
return - 1 ;
}
static void F_40 ( struct V_21 * V_75 , unsigned long V_40 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_76 , V_77 , V_78 ;
unsigned long V_31 = V_75 -> V_24 ;
unsigned long V_52 , V_79 ;
int V_80 , V_81 , V_13 ;
unsigned int V_70 = ( V_75 -> V_37 >> V_73 ) & ( ( 1 << V_74 ) - 1 ) ;
if ( ! ( V_31 & V_82 ) ) {
V_80 = V_9 ;
V_81 = V_9 ;
} else {
for ( V_80 = 0 ; V_80 < V_72 ; V_80 ++ ) {
if ( ! V_10 [ V_80 ] . V_13 )
continue;
V_81 = F_39 ( V_70 , V_80 ) ;
if ( V_81 != - 1 )
break;
}
}
* V_4 = V_31 >> V_83 ;
V_13 = V_10 [ V_80 ] . V_13 ;
V_76 = ( F_41 ( V_31 ) & ~ V_10 [ V_80 ] . V_84 ) ;
V_77 = V_40 / V_35 ;
if ( V_31 & V_38 )
V_77 = ~ V_77 ;
switch ( * V_4 ) {
case V_85 :
V_79 = ( V_76 & 0x1f ) << 23 ;
V_52 = V_76 >> 5 ;
if ( V_13 < 23 ) {
V_78 = ( V_52 ^ V_77 ) & V_50 ;
V_79 |= V_78 << V_13 ;
}
* V_1 = V_52 << ( V_86 - V_8 ) | V_79 >> V_8 ;
break;
case V_87 :
V_79 = ( V_76 & 0x1ffff ) << 23 ;
V_52 = V_76 >> 17 ;
if ( V_13 < 23 ) {
V_78 = ( V_52 ^ ( V_52 << 25 ) ^ V_77 ) & V_50 ;
V_79 |= V_78 << V_13 ;
}
* V_1 = V_52 << ( V_88 - V_8 ) | V_79 >> V_8 ;
break;
default:
* V_1 = V_80 = 0 ;
}
* V_2 = V_80 ;
* V_3 = V_81 ;
}
static void F_42 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_40 , V_89 , V_53 ;
struct V_21 * V_22 = V_30 ;
unsigned long V_31 ;
unsigned long V_90 ;
int V_2 , V_3 , V_4 ;
V_90 = V_50 + 1 ;
F_30 ( V_53 ) ;
F_5 ( & V_20 ) ;
V_89 = V_90 * V_35 ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ , V_22 ++ ) {
V_31 = V_22 -> V_24 ;
if ( V_31 & V_36 ) {
F_40 ( V_22 , V_40 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_22 -> V_24 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
F_6 ( & V_20 ) ;
F_31 ( V_53 ) ;
}
static void F_43 ( unsigned long V_91 , int V_14 )
{
unsigned long V_1 ;
unsigned long V_49 , V_92 , V_63 , V_13 , V_40 ;
struct V_21 * V_22 ;
unsigned long V_31 ;
unsigned long V_43 ;
unsigned long V_53 ;
T_1 V_93 ;
struct V_94 * V_95 = & F_44 ( V_94 ) ;
unsigned long V_2 = V_95 -> V_2 ;
int V_4 = V_95 -> V_4 ;
int V_33 ;
F_30 ( V_53 ) ;
for ( V_33 = 0 ; V_33 < V_91 ; V_33 ++ ) {
V_1 = V_95 -> V_1 [ V_33 ] ;
V_93 = V_95 -> V_93 [ V_33 ] ;
F_45 (pte, psize, vpn, index, shift) {
V_49 = F_24 ( V_1 , V_13 , V_4 ) ;
V_63 = F_46 ( V_93 , V_92 ) ;
if ( V_63 & V_68 )
V_49 = ~ V_49 ;
V_40 = ( V_49 & V_50 ) * V_35 ;
V_40 += V_63 & V_69 ;
V_22 = V_30 + V_40 ;
V_43 = F_21 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_22 ) ;
V_31 = V_22 -> V_24 ;
if ( ! F_22 ( V_31 , V_43 ) ||
! ( V_31 & V_36 ) )
F_11 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
} F_47 () ;
}
if ( F_4 ( V_16 ) &&
V_10 [ V_2 ] . V_19 && V_14 ) {
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_91 ; V_33 ++ ) {
V_1 = V_95 -> V_1 [ V_33 ] ;
V_93 = V_95 -> V_93 [ V_33 ] ;
F_45 (pte, psize,
vpn, index, shift) {
F_2 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_47 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_17 = ! F_4 ( V_18 ) ;
if ( V_17 )
F_5 ( & V_20 ) ;
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_91 ; V_33 ++ ) {
V_1 = V_95 -> V_1 [ V_33 ] ;
V_93 = V_95 -> V_93 [ V_33 ] ;
F_45 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_47 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_17 )
F_6 ( & V_20 ) ;
}
F_31 ( V_53 ) ;
}
void T_2 F_48 ( void )
{
V_96 . V_97 = F_29 ;
V_96 . V_98 = F_20 ;
V_96 . V_99 = F_25 ;
V_96 . V_100 = F_13 ;
V_96 . V_101 = F_18 ;
V_96 . V_102 = F_42 ;
V_96 . V_103 = F_43 ;
V_96 . V_104 = F_32 ;
}
