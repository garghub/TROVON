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
unsigned int V_15 ;
int V_16 = ! F_4 ( V_17 ) ;
V_15 = V_14 && F_4 ( V_18 ) && ! F_5 () ;
if ( V_15 )
V_15 = V_10 [ V_2 ] . V_19 ;
if ( V_16 && ! V_15 )
F_6 ( & V_20 ) ;
asm volatile("ptesync": : :"memory");
if ( V_15 ) {
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_16 && ! V_15 )
F_7 ( & V_20 ) ;
}
static inline void F_8 ( struct V_21 * V_22 )
{
unsigned long * V_23 = ( unsigned long * ) & V_22 -> V_24 ;
while ( 1 ) {
if ( ! F_9 ( V_25 , V_23 ) )
break;
while( F_10 ( V_25 , V_23 ) )
F_11 () ;
}
}
static inline void F_12 ( struct V_21 * V_22 )
{
unsigned long * V_23 = ( unsigned long * ) & V_22 -> V_24 ;
F_13 ( V_25 , V_23 ) ;
}
static long F_14 ( unsigned long V_26 , unsigned long V_1 ,
unsigned long V_27 , unsigned long V_28 ,
unsigned long V_29 , int V_2 , int V_3 , int V_4 )
{
struct V_21 * V_22 = V_30 + V_26 ;
unsigned long V_31 , V_32 ;
int V_33 ;
if ( ! ( V_29 & V_34 ) ) {
F_15 ( L_1
L_2 ,
V_26 , V_1 , V_27 , V_28 , V_29 , V_2 ) ;
}
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
if ( ! ( F_16 ( V_22 -> V_24 ) & V_36 ) ) {
F_8 ( V_22 ) ;
if ( ! ( F_16 ( V_22 -> V_24 ) & V_36 ) )
break;
F_12 ( V_22 ) ;
}
V_22 ++ ;
}
if ( V_33 == V_35 )
return - 1 ;
V_31 = F_17 ( V_1 , V_2 , V_3 , V_4 ) | V_29 | V_36 ;
V_32 = F_18 ( V_27 , V_2 , V_3 ) | V_28 ;
if ( ! ( V_29 & V_34 ) ) {
F_15 ( L_3 ,
V_33 , V_31 , V_32 ) ;
}
V_22 -> V_37 = F_19 ( V_32 ) ;
F_20 () ;
V_22 -> V_24 = F_19 ( V_31 ) ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_33 | ( ! ! ( V_29 & V_38 ) << 3 ) ;
}
static long F_21 ( unsigned long V_26 )
{
struct V_21 * V_22 ;
int V_33 ;
int V_39 ;
unsigned long V_31 ;
F_15 ( L_4 , V_26 ) ;
V_39 = F_22 () & 0x7 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_26 + V_39 ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ( V_31 & V_36 ) && ! ( V_31 & V_34 ) ) {
F_8 ( V_22 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ( V_31 & V_36 )
&& ! ( V_31 & V_34 ) )
break;
F_12 ( V_22 ) ;
}
V_39 ++ ;
V_39 &= 0x7 ;
}
if ( V_33 == V_35 )
return - 1 ;
V_22 -> V_24 = 0 ;
return V_33 ;
}
static long F_23 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_1 , int V_42 ,
int V_3 , int V_4 , unsigned long V_43 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 , V_44 ;
int V_45 = 0 , V_14 = 0 ;
V_44 = F_24 ( V_1 , V_42 , V_4 ) ;
F_15 ( L_5 ,
V_1 , V_44 & V_46 , V_40 , V_41 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ! F_25 ( V_31 , V_44 ) || ! ( V_31 & V_36 ) ) {
F_15 ( L_6 ) ;
V_45 = - 1 ;
} else {
F_8 ( V_22 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( F_26 ( ! F_25 ( V_31 , V_44 ) ||
! ( V_31 & V_36 ) ) ) {
V_45 = - 1 ;
} else {
F_15 ( L_7 ) ;
V_22 -> V_37 = F_19 ( ( F_16 ( V_22 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 |
V_49 ) ) ) ;
}
F_12 ( V_22 ) ;
}
if ( V_43 & V_50 )
V_14 = 1 ;
if ( ! ( V_43 & V_51 ) )
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
return V_45 ;
}
static long F_27 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_21 * V_22 ;
unsigned long V_52 ;
unsigned long V_33 ;
long V_40 ;
unsigned long V_44 , V_31 ;
V_52 = F_28 ( V_1 , V_10 [ V_2 ] . V_13 , V_4 ) ;
V_44 = F_24 ( V_1 , V_2 , V_4 ) ;
V_40 = ( V_52 & V_53 ) * V_35 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_22 = V_30 + V_40 ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( F_25 ( V_31 , V_44 ) && ( V_31 & V_36 ) )
return V_40 ;
++ V_40 ;
}
return - 1 ;
}
static void F_29 ( unsigned long V_41 , unsigned long V_54 ,
int V_2 , int V_4 )
{
unsigned long V_1 ;
unsigned long V_55 ;
long V_40 ;
struct V_21 * V_22 ;
V_55 = F_30 ( V_54 , V_4 ) ;
V_1 = F_31 ( V_54 , V_55 , V_4 ) ;
V_40 = F_27 ( V_1 , V_2 , V_4 ) ;
if ( V_40 == - 1 )
F_32 ( L_8 ) ;
V_22 = V_30 + V_40 ;
V_22 -> V_37 = F_19 ( ( F_16 ( V_22 -> V_37 ) &
~ ( V_47 | V_48 ) ) |
( V_41 & ( V_47 | V_48 ) ) ) ;
F_3 ( V_1 , V_2 , V_2 , V_4 , 0 ) ;
}
static void F_33 ( unsigned long V_40 , unsigned long V_1 ,
int V_42 , int V_3 , int V_4 , int V_14 )
{
struct V_21 * V_22 = V_30 + V_40 ;
unsigned long V_31 ;
unsigned long V_44 ;
unsigned long V_43 ;
F_34 ( V_43 ) ;
F_15 ( L_9 , V_1 , V_40 ) ;
V_44 = F_24 ( V_1 , V_42 , V_4 ) ;
F_8 ( V_22 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ! F_25 ( V_31 , V_44 ) || ! ( V_31 & V_36 ) )
F_12 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
F_3 ( V_1 , V_42 , V_3 , V_4 , V_14 ) ;
F_35 ( V_43 ) ;
}
static void F_36 ( unsigned long V_55 ,
unsigned long V_56 ,
unsigned char * V_57 ,
int V_2 , int V_4 , int V_14 )
{
int V_33 ;
struct V_21 * V_22 ;
int V_58 = V_59 ;
unsigned int V_60 , V_61 ;
unsigned long V_43 , V_62 = V_56 ;
unsigned long V_31 , V_44 , V_13 ;
unsigned long V_63 , V_1 = 0 , V_52 , V_40 ;
V_13 = V_10 [ V_2 ] . V_13 ;
V_60 = 1U << ( V_64 - V_13 ) ;
F_34 ( V_43 ) ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_61 = F_37 ( V_57 , V_33 ) ;
if ( ! V_61 )
continue;
V_63 = F_38 ( V_57 , V_33 ) ;
V_56 = V_62 + ( V_33 * ( 1ul << V_13 ) ) ;
V_1 = F_31 ( V_56 , V_55 , V_4 ) ;
V_52 = F_28 ( V_1 , V_13 , V_4 ) ;
if ( V_63 & V_65 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_35 ;
V_40 += V_63 & V_66 ;
V_22 = V_30 + V_40 ;
V_44 = F_24 ( V_1 , V_2 , V_4 ) ;
F_8 ( V_22 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ! F_25 ( V_31 , V_44 ) || ! ( V_31 & V_36 ) )
F_12 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
F_3 ( V_1 , V_2 , V_58 , V_4 , V_14 ) ;
}
F_35 ( V_43 ) ;
}
static void F_36 ( unsigned long V_55 ,
unsigned long V_56 ,
unsigned char * V_57 ,
int V_2 , int V_4 , int V_14 )
{
F_39 ( 1 , L_10 , V_67 ) ;
}
static inline int F_40 ( unsigned int V_68 , int V_2 )
{
int V_33 , V_13 ;
unsigned int V_69 ;
for ( V_33 = 1 ; V_33 < V_70 ; V_33 ++ ) {
if ( V_10 [ V_2 ] . V_6 [ V_33 ] == - 1 )
continue;
V_13 = V_10 [ V_33 ] . V_13 - V_71 ;
if ( V_13 > V_72 )
V_13 = V_72 ;
V_69 = ( 1 << V_13 ) - 1 ;
if ( ( V_68 & V_69 ) == V_10 [ V_2 ] . V_6 [ V_33 ] )
return V_33 ;
}
return - 1 ;
}
static void F_41 ( struct V_21 * V_73 , unsigned long V_40 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_74 , V_75 , V_76 ;
unsigned long V_31 = F_16 ( V_73 -> V_24 ) ;
unsigned long V_32 = F_16 ( V_73 -> V_37 ) ;
unsigned long V_55 , V_77 ;
int V_78 , V_79 , V_13 ;
unsigned int V_68 = ( V_32 >> V_71 ) & ( ( 1 << V_72 ) - 1 ) ;
if ( ! ( V_31 & V_80 ) ) {
V_78 = V_9 ;
V_79 = V_9 ;
} else {
for ( V_78 = 0 ; V_78 < V_70 ; V_78 ++ ) {
if ( ! V_10 [ V_78 ] . V_13 )
continue;
V_79 = F_40 ( V_68 , V_78 ) ;
if ( V_79 != - 1 )
break;
}
}
* V_4 = V_31 >> V_81 ;
V_13 = V_10 [ V_78 ] . V_13 ;
V_74 = ( F_42 ( V_31 ) & ~ V_10 [ V_78 ] . V_82 ) ;
V_75 = V_40 / V_35 ;
if ( V_31 & V_38 )
V_75 = ~ V_75 ;
switch ( * V_4 ) {
case V_83 :
V_77 = ( V_74 & 0x1f ) << 23 ;
V_55 = V_74 >> 5 ;
if ( V_13 < 23 ) {
V_76 = ( V_55 ^ V_75 ) & V_53 ;
V_77 |= V_76 << V_13 ;
}
* V_1 = V_55 << ( V_84 - V_8 ) | V_77 >> V_8 ;
break;
case V_85 :
V_77 = ( V_74 & 0x1ffff ) << 23 ;
V_55 = V_74 >> 17 ;
if ( V_13 < 23 ) {
V_76 = ( V_55 ^ ( V_55 << 25 ) ^ V_75 ) & V_53 ;
V_77 |= V_76 << V_13 ;
}
* V_1 = V_55 << ( V_86 - V_8 ) | V_77 >> V_8 ;
break;
default:
* V_1 = V_78 = 0 ;
}
* V_2 = V_78 ;
* V_3 = V_79 ;
}
static void F_43 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_40 , V_87 ;
struct V_21 * V_22 = V_30 ;
unsigned long V_31 ;
unsigned long V_88 ;
int V_2 , V_3 , V_4 ;
V_88 = V_53 + 1 ;
V_87 = V_88 * V_35 ;
for ( V_40 = 0 ; V_40 < V_87 ; V_40 ++ , V_22 ++ ) {
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( V_31 & V_36 ) {
F_41 ( V_22 , V_40 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_22 -> V_24 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
}
static void F_44 ( unsigned long V_89 , int V_14 )
{
unsigned long V_1 ;
unsigned long V_52 , V_90 , V_63 , V_13 , V_40 ;
struct V_21 * V_22 ;
unsigned long V_31 ;
unsigned long V_44 ;
unsigned long V_43 ;
T_1 V_91 ;
struct V_92 * V_93 = F_45 ( & V_92 ) ;
unsigned long V_2 = V_93 -> V_2 ;
int V_4 = V_93 -> V_4 ;
int V_33 ;
F_34 ( V_43 ) ;
for ( V_33 = 0 ; V_33 < V_89 ; V_33 ++ ) {
V_1 = V_93 -> V_1 [ V_33 ] ;
V_91 = V_93 -> V_91 [ V_33 ] ;
F_46 (pte, psize, vpn, index, shift) {
V_52 = F_28 ( V_1 , V_13 , V_4 ) ;
V_63 = F_47 ( V_91 , V_90 ) ;
if ( V_63 & V_65 )
V_52 = ~ V_52 ;
V_40 = ( V_52 & V_53 ) * V_35 ;
V_40 += V_63 & V_66 ;
V_22 = V_30 + V_40 ;
V_44 = F_24 ( V_1 , V_2 , V_4 ) ;
F_8 ( V_22 ) ;
V_31 = F_16 ( V_22 -> V_24 ) ;
if ( ! F_25 ( V_31 , V_44 ) ||
! ( V_31 & V_36 ) )
F_12 ( V_22 ) ;
else
V_22 -> V_24 = 0 ;
} F_48 () ;
}
if ( F_4 ( V_18 ) &&
V_10 [ V_2 ] . V_19 && V_14 ) {
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_89 ; V_33 ++ ) {
V_1 = V_93 -> V_1 [ V_33 ] ;
V_91 = V_93 -> V_91 [ V_33 ] ;
F_46 (pte, psize,
vpn, index, shift) {
F_2 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_48 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_16 = ! F_4 ( V_17 ) ;
if ( V_16 )
F_6 ( & V_20 ) ;
asm volatile("ptesync":::"memory");
for ( V_33 = 0 ; V_33 < V_89 ; V_33 ++ ) {
V_1 = V_93 -> V_1 [ V_33 ] ;
V_91 = V_93 -> V_91 [ V_33 ] ;
F_46 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_48 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_16 )
F_7 ( & V_20 ) ;
}
F_35 ( V_43 ) ;
}
void T_2 F_49 ( void )
{
V_94 . V_95 = F_33 ;
V_94 . V_96 = F_23 ;
V_94 . V_97 = F_29 ;
V_94 . V_98 = F_14 ;
V_94 . V_99 = F_21 ;
V_94 . V_100 = F_43 ;
V_94 . V_101 = F_44 ;
V_94 . V_102 = F_36 ;
}
