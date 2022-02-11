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
asm volatile(".long 0x7c000224 | (%0 << 11) | (0 << 21)"
: : "r"(va) : "memory");
break;
default:
V_6 = V_11 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_11 [ V_3 ] . V_12 ) - 1 ) ;
V_5 |= V_6 << 12 ;
V_5 |= V_4 << 8 ;
V_5 |= ( V_1 & 0xfe ) ;
V_5 |= 1 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (1 << 21)"
: : "r"(va) : "memory");
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
V_31 = F_19 ( V_26 , V_2 , V_3 , V_4 ) | V_27 ;
if ( ! ( V_28 & V_33 ) ) {
F_16 ( L_3 ,
V_32 , V_30 , V_31 ) ;
}
V_21 -> V_36 = F_20 ( V_31 ) ;
F_21 () ;
V_21 -> V_23 = F_20 ( V_30 ) ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_32 | ( ! ! ( V_28 & V_37 ) << 3 ) ;
}
static long F_22 ( unsigned long V_25 )
{
struct V_20 * V_21 ;
int V_32 ;
int V_38 ;
unsigned long V_30 ;
F_16 ( L_4 , V_25 ) ;
V_38 = F_23 () & 0x7 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_25 + V_38 ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 ) && ! ( V_30 & V_33 ) ) {
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ( V_30 & V_35 )
&& ! ( V_30 & V_33 ) )
break;
F_13 ( V_21 ) ;
}
V_38 ++ ;
V_38 &= 0x7 ;
}
if ( V_32 == V_34 )
return - 1 ;
V_21 -> V_23 = 0 ;
return V_32 ;
}
static long F_24 ( unsigned long V_39 , unsigned long V_40 ,
unsigned long V_1 , int V_41 ,
int V_3 , int V_4 , unsigned long V_42 )
{
struct V_20 * V_21 = V_29 + V_39 ;
unsigned long V_30 , V_43 ;
int V_44 = 0 , V_13 = 0 ;
V_43 = F_25 ( V_1 , V_41 , V_4 ) ;
F_16 ( L_5 ,
V_1 , V_43 & V_45 , V_39 , V_40 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ! F_26 ( V_30 , V_43 ) || ! ( V_30 & V_35 ) ) {
F_16 ( L_6 ) ;
V_44 = - 1 ;
} else {
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_27 ( ! F_26 ( V_30 , V_43 ) ||
! ( V_30 & V_35 ) ) ) {
V_44 = - 1 ;
} else {
F_16 ( L_7 ) ;
V_21 -> V_36 = F_20 ( ( F_17 ( V_21 -> V_36 ) &
~ ( V_46 | V_47 ) ) |
( V_40 & ( V_46 | V_47 |
V_48 ) ) ) ;
}
F_13 ( V_21 ) ;
}
if ( V_42 & V_49 )
V_13 = 1 ;
if ( ! ( V_42 & V_50 ) )
F_5 ( V_1 , V_41 , V_3 , V_4 , V_13 ) ;
return V_44 ;
}
static long F_28 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_20 * V_21 ;
unsigned long V_51 ;
unsigned long V_32 ;
long V_39 ;
unsigned long V_43 , V_30 ;
V_51 = F_29 ( V_1 , V_11 [ V_2 ] . V_12 , V_4 ) ;
V_43 = F_25 ( V_1 , V_2 , V_4 ) ;
V_39 = ( V_51 & V_52 ) * V_34 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_21 = V_29 + V_39 ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( F_26 ( V_30 , V_43 ) && ( V_30 & V_35 ) )
return V_39 ;
++ V_39 ;
}
return - 1 ;
}
static void F_30 ( unsigned long V_40 , unsigned long V_53 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_54 ;
long V_39 ;
struct V_20 * V_21 ;
V_54 = F_31 ( V_53 , V_4 ) ;
V_1 = F_32 ( V_53 , V_54 , V_4 ) ;
V_39 = F_28 ( V_1 , V_2 , V_4 ) ;
if ( V_39 == - 1 )
F_33 ( L_8 ) ;
V_21 = V_29 + V_39 ;
V_21 -> V_36 = F_20 ( ( F_17 ( V_21 -> V_36 ) &
~ ( V_46 | V_47 ) ) |
( V_40 & ( V_46 | V_47 ) ) ) ;
F_5 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static void F_34 ( unsigned long V_39 , unsigned long V_1 ,
int V_41 , int V_3 , int V_4 , int V_13 )
{
struct V_20 * V_21 = V_29 + V_39 ;
unsigned long V_30 ;
unsigned long V_43 ;
unsigned long V_42 ;
F_35 ( V_42 ) ;
F_16 ( L_9 , V_1 , V_39 ) ;
V_43 = F_25 ( V_1 , V_41 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ! F_26 ( V_30 , V_43 ) || ! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_5 ( V_1 , V_41 , V_3 , V_4 , V_13 ) ;
F_36 ( V_42 ) ;
}
static void F_37 ( unsigned long V_54 ,
unsigned long V_55 ,
unsigned char * V_56 ,
int V_2 , int V_4 , int V_13 )
{
int V_32 ;
struct V_20 * V_21 ;
int V_57 = V_58 ;
unsigned int V_59 , V_60 ;
unsigned long V_42 , V_61 = V_55 ;
unsigned long V_30 , V_43 , V_12 ;
unsigned long V_62 , V_1 = 0 , V_51 , V_39 ;
V_12 = V_11 [ V_2 ] . V_12 ;
V_59 = 1U << ( V_63 - V_12 ) ;
F_35 ( V_42 ) ;
for ( V_32 = 0 ; V_32 < V_59 ; V_32 ++ ) {
V_60 = F_38 ( V_56 , V_32 ) ;
if ( ! V_60 )
continue;
V_62 = F_39 ( V_56 , V_32 ) ;
V_55 = V_61 + ( V_32 * ( 1ul << V_12 ) ) ;
V_1 = F_32 ( V_55 , V_54 , V_4 ) ;
V_51 = F_29 ( V_1 , V_12 , V_4 ) ;
if ( V_62 & V_64 )
V_51 = ~ V_51 ;
V_39 = ( V_51 & V_52 ) * V_34 ;
V_39 += V_62 & V_65 ;
V_21 = V_29 + V_39 ;
V_43 = F_25 ( V_1 , V_2 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ! F_26 ( V_30 , V_43 ) || ! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
F_5 ( V_1 , V_2 , V_57 , V_4 , V_13 ) ;
}
F_36 ( V_42 ) ;
}
static void F_37 ( unsigned long V_54 ,
unsigned long V_55 ,
unsigned char * V_56 ,
int V_2 , int V_4 , int V_13 )
{
F_40 ( 1 , L_10 , V_66 ) ;
}
static inline int F_41 ( unsigned int V_67 , int V_2 )
{
int V_32 , V_12 ;
unsigned int V_68 ;
for ( V_32 = 1 ; V_32 < V_69 ; V_32 ++ ) {
if ( V_11 [ V_2 ] . V_6 [ V_32 ] == - 1 )
continue;
V_12 = V_11 [ V_32 ] . V_12 - V_70 ;
if ( V_12 > V_71 )
V_12 = V_71 ;
V_68 = ( 1 << V_12 ) - 1 ;
if ( ( V_67 & V_68 ) == V_11 [ V_2 ] . V_6 [ V_32 ] )
return V_32 ;
}
return - 1 ;
}
static void F_42 ( struct V_20 * V_72 , unsigned long V_39 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_73 , V_74 , V_75 ;
unsigned long V_30 = F_17 ( V_72 -> V_23 ) ;
unsigned long V_31 = F_17 ( V_72 -> V_36 ) ;
unsigned long V_54 , V_76 ;
int V_77 , V_78 , V_12 ;
unsigned int V_67 = ( V_31 >> V_70 ) & ( ( 1 << V_71 ) - 1 ) ;
if ( ! ( V_30 & V_79 ) ) {
V_77 = V_10 ;
V_78 = V_10 ;
} else {
for ( V_77 = 0 ; V_77 < V_69 ; V_77 ++ ) {
if ( ! V_11 [ V_77 ] . V_12 )
continue;
V_78 = F_41 ( V_67 , V_77 ) ;
if ( V_78 != - 1 )
break;
}
}
if ( F_43 ( V_80 ) )
* V_4 = V_31 >> V_81 ;
else
* V_4 = V_30 >> V_82 ;
V_12 = V_11 [ V_77 ] . V_12 ;
V_73 = ( F_44 ( V_30 ) & ~ V_11 [ V_77 ] . V_83 ) ;
V_74 = V_39 / V_34 ;
if ( V_30 & V_37 )
V_74 = ~ V_74 ;
switch ( * V_4 ) {
case V_84 :
V_76 = ( V_73 & 0x1f ) << 23 ;
V_54 = V_73 >> 5 ;
if ( V_12 < 23 ) {
V_75 = ( V_54 ^ V_74 ) & V_52 ;
V_76 |= V_75 << V_12 ;
}
* V_1 = V_54 << ( V_85 - V_8 ) | V_76 >> V_8 ;
break;
case V_86 :
V_76 = ( V_73 & 0x1ffff ) << 23 ;
V_54 = V_73 >> 17 ;
if ( V_12 < 23 ) {
V_75 = ( V_54 ^ ( V_54 << 25 ) ^ V_74 ) & V_52 ;
V_76 |= V_75 << V_12 ;
}
* V_1 = V_54 << ( V_87 - V_8 ) | V_76 >> V_8 ;
break;
default:
* V_1 = V_77 = 0 ;
}
* V_2 = V_77 ;
* V_3 = V_78 ;
}
static void F_45 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_39 , V_88 ;
struct V_20 * V_21 = V_29 ;
unsigned long V_30 ;
unsigned long V_89 ;
int V_2 , V_3 , V_4 ;
V_89 = V_52 + 1 ;
V_88 = V_89 * V_34 ;
for ( V_39 = 0 ; V_39 < V_88 ; V_39 ++ , V_21 ++ ) {
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( V_30 & V_35 ) {
F_42 ( V_21 , V_39 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_21 -> V_23 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
}
static void F_46 ( unsigned long V_90 , int V_13 )
{
unsigned long V_1 ;
unsigned long V_51 , V_91 , V_62 , V_12 , V_39 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
unsigned long V_43 ;
unsigned long V_42 ;
T_1 V_92 ;
struct V_93 * V_94 = F_47 ( & V_93 ) ;
unsigned long V_2 = V_94 -> V_2 ;
int V_4 = V_94 -> V_4 ;
int V_32 ;
F_35 ( V_42 ) ;
for ( V_32 = 0 ; V_32 < V_90 ; V_32 ++ ) {
V_1 = V_94 -> V_1 [ V_32 ] ;
V_92 = V_94 -> V_92 [ V_32 ] ;
F_48 (pte, psize, vpn, index, shift) {
V_51 = F_29 ( V_1 , V_12 , V_4 ) ;
V_62 = F_49 ( V_92 , V_91 ) ;
if ( V_62 & V_64 )
V_51 = ~ V_51 ;
V_39 = ( V_51 & V_52 ) * V_34 ;
V_39 += V_62 & V_65 ;
V_21 = V_29 + V_39 ;
V_43 = F_25 ( V_1 , V_2 , V_4 ) ;
F_9 ( V_21 ) ;
V_30 = F_17 ( V_21 -> V_23 ) ;
if ( ! F_26 ( V_30 , V_43 ) ||
! ( V_30 & V_35 ) )
F_13 ( V_21 ) ;
else
V_21 -> V_23 = 0 ;
} F_50 () ;
}
if ( F_2 ( V_17 ) &&
V_11 [ V_2 ] . V_18 && V_13 ) {
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_90 ; V_32 ++ ) {
V_1 = V_94 -> V_1 [ V_32 ] ;
V_92 = V_94 -> V_92 [ V_32 ] ;
F_48 (pte, psize,
vpn, index, shift) {
F_4 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_50 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_15 = ! F_2 ( V_16 ) ;
if ( V_15 )
F_7 ( & V_19 ) ;
asm volatile("ptesync":::"memory");
for ( V_32 = 0 ; V_32 < V_90 ; V_32 ++ ) {
V_1 = V_94 -> V_1 [ V_32 ] ;
V_92 = V_94 -> V_92 [ V_32 ] ;
F_48 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_50 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_15 )
F_8 ( & V_19 ) ;
}
F_36 ( V_42 ) ;
}
static int F_51 ( unsigned long V_95 , unsigned long V_96 ,
unsigned long V_97 )
{
unsigned long V_98 = V_95 << 25 ;
V_98 |= ( V_96 << 5 ) ;
V_98 |= V_97 ;
V_99 -> V_98 = F_20 ( V_98 ) ;
return 0 ;
}
void T_2 F_52 ( void )
{
V_100 . V_101 = F_34 ;
V_100 . V_102 = F_24 ;
V_100 . V_103 = F_30 ;
V_100 . V_104 = F_15 ;
V_100 . V_105 = F_22 ;
V_100 . V_106 = F_45 ;
V_100 . V_107 = F_46 ;
V_100 . V_108 = F_37 ;
if ( F_43 ( V_80 ) )
V_109 = F_51 ;
}
