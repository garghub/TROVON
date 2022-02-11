static inline void F_1 ( unsigned long V_1 , int V_2 , int V_3 , int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
V_5 = V_1 << V_7 ;
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_8 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_5 |= V_9 [ V_3 ] . V_10 << 6 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,0", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_6 = V_9 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_9 [ V_3 ] . V_11 ) - 1 ) ;
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
V_5 = V_1 << V_7 ;
V_5 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_8 :
V_5 &= ~ ( ( 1ul << ( 64 - 52 ) ) - 1 ) ;
V_5 |= V_4 << 8 ;
V_5 |= V_9 [ V_3 ] . V_10 << 6 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (0 << 21)"
: : "r"(va) : "memory");
break;
default:
V_6 = V_9 [ V_2 ] . V_6 [ V_3 ] ;
V_5 &= ~ ( ( 1ul << V_9 [ V_3 ] . V_11 ) - 1 ) ;
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
int V_4 , int V_12 )
{
unsigned int V_13 = V_12 && F_4 ( V_14 ) ;
int V_15 = ! F_4 ( V_16 ) ;
if ( V_13 )
V_13 = V_9 [ V_2 ] . V_17 ;
if ( V_15 && ! V_13 )
F_5 ( & V_18 ) ;
asm volatile("ptesync": : :"memory");
if ( V_13 ) {
F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_15 && ! V_13 )
F_6 ( & V_18 ) ;
}
static inline void F_7 ( struct V_19 * V_20 )
{
unsigned long * V_21 = & V_20 -> V_22 ;
while ( 1 ) {
if ( ! F_8 ( V_23 , V_21 ) )
break;
while( F_9 ( V_23 , V_21 ) )
F_10 () ;
}
}
static inline void F_11 ( struct V_19 * V_20 )
{
unsigned long * V_21 = & V_20 -> V_22 ;
F_12 ( V_23 , V_21 ) ;
}
static long F_13 ( unsigned long V_24 , unsigned long V_1 ,
unsigned long V_25 , unsigned long V_26 ,
unsigned long V_27 , int V_2 , int V_3 , int V_4 )
{
struct V_19 * V_20 = V_28 + V_24 ;
unsigned long V_29 , V_30 ;
int V_31 ;
if ( ! ( V_27 & V_32 ) ) {
F_14 ( L_1
L_2 ,
V_24 , V_1 , V_25 , V_26 , V_27 , V_2 ) ;
}
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if ( ! ( V_20 -> V_22 & V_34 ) ) {
F_7 ( V_20 ) ;
if ( ! ( V_20 -> V_22 & V_34 ) )
break;
F_11 ( V_20 ) ;
}
V_20 ++ ;
}
if ( V_31 == V_33 )
return - 1 ;
V_29 = F_15 ( V_1 , V_2 , V_3 , V_4 ) | V_27 | V_34 ;
V_30 = F_16 ( V_25 , V_2 , V_3 ) | V_26 ;
if ( ! ( V_27 & V_32 ) ) {
F_14 ( L_3 ,
V_31 , V_29 , V_30 ) ;
}
V_20 -> V_35 = V_30 ;
F_17 () ;
V_20 -> V_22 = V_29 ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_31 | ( ! ! ( V_27 & V_36 ) << 3 ) ;
}
static long F_18 ( unsigned long V_24 )
{
struct V_19 * V_20 ;
int V_31 ;
int V_37 ;
unsigned long V_29 ;
F_14 ( L_4 , V_24 ) ;
V_37 = F_19 () & 0x7 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
V_20 = V_28 + V_24 + V_37 ;
V_29 = V_20 -> V_22 ;
if ( ( V_29 & V_34 ) && ! ( V_29 & V_32 ) ) {
F_7 ( V_20 ) ;
V_29 = V_20 -> V_22 ;
if ( ( V_29 & V_34 )
&& ! ( V_29 & V_32 ) )
break;
F_11 ( V_20 ) ;
}
V_37 ++ ;
V_37 &= 0x7 ;
}
if ( V_31 == V_33 )
return - 1 ;
V_20 -> V_22 = 0 ;
return V_31 ;
}
static inline int F_20 ( unsigned int V_38 , int V_2 )
{
int V_31 , V_11 ;
unsigned int V_39 ;
for ( V_31 = 1 ; V_31 < V_40 ; V_31 ++ ) {
if ( V_9 [ V_2 ] . V_6 [ V_31 ] == - 1 )
continue;
V_11 = V_9 [ V_31 ] . V_11 - V_41 ;
if ( V_11 > V_42 )
V_11 = V_42 ;
V_39 = ( 1 << V_11 ) - 1 ;
if ( ( V_38 & V_39 ) == V_9 [ V_2 ] . V_6 [ V_31 ] )
return V_31 ;
}
return - 1 ;
}
static inline int F_21 ( struct V_19 * V_20 , int V_2 )
{
unsigned int V_38 = ( V_20 -> V_35 >> V_41 ) & ( ( 1 << V_42 ) - 1 ) ;
if ( ! ( V_20 -> V_22 & V_34 ) )
return - 1 ;
if ( ! ( V_20 -> V_22 & V_43 ) )
return V_8 ;
return F_20 ( V_38 , V_2 ) ;
}
static long F_22 ( unsigned long V_44 , unsigned long V_45 ,
unsigned long V_1 , int V_2 , int V_4 ,
int V_12 )
{
struct V_19 * V_20 = V_28 + V_44 ;
unsigned long V_29 , V_46 ;
int V_47 = 0 ;
int V_48 ;
V_46 = F_23 ( V_1 , V_2 , V_4 ) ;
F_14 ( L_5 ,
V_1 , V_46 & V_49 , V_44 , V_45 ) ;
F_7 ( V_20 ) ;
V_29 = V_20 -> V_22 ;
V_48 = F_21 ( V_20 , V_2 ) ;
if ( V_48 < 0 ) {
V_48 = V_2 ;
V_47 = - 1 ;
goto V_50;
}
if ( ! F_24 ( V_29 , V_46 ) ) {
F_14 ( L_6 ) ;
V_47 = - 1 ;
} else {
F_14 ( L_7 ) ;
V_20 -> V_35 = ( V_20 -> V_35 & ~ ( V_51 | V_52 ) ) |
( V_45 & ( V_51 | V_52 | V_53 ) ) ;
}
V_50:
F_11 ( V_20 ) ;
F_3 ( V_1 , V_2 , V_48 , V_4 , V_12 ) ;
return V_47 ;
}
static long F_25 ( unsigned long V_1 , int V_2 , int V_4 )
{
struct V_19 * V_20 ;
unsigned long V_54 ;
unsigned long V_31 ;
long V_44 ;
unsigned long V_46 , V_29 ;
V_54 = F_26 ( V_1 , V_9 [ V_2 ] . V_11 , V_4 ) ;
V_46 = F_23 ( V_1 , V_2 , V_4 ) ;
V_44 = ( V_54 & V_55 ) * V_33 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
V_20 = V_28 + V_44 ;
V_29 = V_20 -> V_22 ;
if ( F_24 ( V_29 , V_46 ) && ( V_29 & V_34 ) )
return V_44 ;
++ V_44 ;
}
return - 1 ;
}
static void F_27 ( unsigned long V_45 , unsigned long V_56 ,
int V_2 , int V_4 )
{
int V_48 ;
unsigned long V_1 ;
unsigned long V_57 ;
long V_44 ;
struct V_19 * V_20 ;
V_57 = F_28 ( V_56 , V_4 ) ;
V_1 = F_29 ( V_56 , V_57 , V_4 ) ;
V_44 = F_25 ( V_1 , V_2 , V_4 ) ;
if ( V_44 == - 1 )
F_30 ( L_8 ) ;
V_20 = V_28 + V_44 ;
V_48 = F_21 ( V_20 , V_2 ) ;
if ( V_48 < 0 )
V_48 = V_2 ;
V_20 -> V_35 = ( V_20 -> V_35 & ~ ( V_51 | V_52 ) ) |
( V_45 & ( V_51 | V_52 ) ) ;
F_3 ( V_1 , V_2 , V_48 , V_4 , 0 ) ;
}
static void F_31 ( unsigned long V_44 , unsigned long V_1 ,
int V_2 , int V_4 , int V_12 )
{
struct V_19 * V_20 = V_28 + V_44 ;
unsigned long V_29 ;
unsigned long V_46 ;
unsigned long V_58 ;
int V_48 ;
F_32 ( V_58 ) ;
F_14 ( L_9 , V_1 , V_44 ) ;
V_46 = F_23 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_20 ) ;
V_29 = V_20 -> V_22 ;
V_48 = F_21 ( V_20 , V_2 ) ;
if ( V_48 < 0 ) {
V_48 = V_2 ;
F_11 ( V_20 ) ;
goto V_50;
}
if ( ! F_24 ( V_29 , V_46 ) )
F_11 ( V_20 ) ;
else
V_20 -> V_22 = 0 ;
V_50:
F_3 ( V_1 , V_2 , V_48 , V_4 , V_12 ) ;
F_33 ( V_58 ) ;
}
static void F_34 ( struct V_19 * V_59 , unsigned long V_44 ,
int * V_2 , int * V_3 , int * V_4 , unsigned long * V_1 )
{
unsigned long V_60 , V_61 , V_62 ;
unsigned long V_29 = V_59 -> V_22 ;
unsigned long V_57 , V_63 ;
int V_64 , V_65 , V_11 ;
unsigned int V_38 = ( V_59 -> V_35 >> V_41 ) & ( ( 1 << V_42 ) - 1 ) ;
if ( ! ( V_29 & V_43 ) ) {
V_64 = V_8 ;
V_65 = V_8 ;
} else {
for ( V_64 = 0 ; V_64 < V_40 ; V_64 ++ ) {
if ( ! V_9 [ V_64 ] . V_11 )
continue;
V_65 = F_20 ( V_38 , V_64 ) ;
if ( V_65 != - 1 )
break;
}
}
* V_4 = V_29 >> V_66 ;
V_11 = V_9 [ V_64 ] . V_11 ;
V_60 = ( F_35 ( V_29 ) & ~ V_9 [ V_64 ] . V_67 ) ;
V_61 = V_44 / V_33 ;
if ( V_29 & V_36 )
V_61 = ~ V_61 ;
switch ( * V_4 ) {
case V_68 :
V_63 = ( V_60 & 0x1f ) << 23 ;
V_57 = V_60 >> 5 ;
if ( V_11 < 23 ) {
V_62 = ( V_57 ^ V_61 ) & V_55 ;
V_63 |= V_62 << V_11 ;
}
* V_1 = V_57 << ( V_69 - V_7 ) | V_63 >> V_7 ;
case V_70 :
V_63 = ( V_60 & 0x1ffff ) << 23 ;
V_57 = V_60 >> 17 ;
if ( V_11 < 23 ) {
V_62 = ( V_57 ^ ( V_57 << 25 ) ^ V_61 ) & V_55 ;
V_63 |= V_62 << V_11 ;
}
* V_1 = V_57 << ( V_71 - V_7 ) | V_63 >> V_7 ;
default:
* V_1 = V_64 = 0 ;
}
* V_2 = V_64 ;
* V_3 = V_65 ;
}
static void F_36 ( void )
{
unsigned long V_1 = 0 ;
unsigned long V_44 , V_72 , V_58 ;
struct V_19 * V_20 = V_28 ;
unsigned long V_29 ;
unsigned long V_73 ;
int V_2 , V_3 , V_4 ;
V_73 = V_55 + 1 ;
F_32 ( V_58 ) ;
F_5 ( & V_18 ) ;
V_72 = V_73 * V_33 ;
for ( V_44 = 0 ; V_44 < V_72 ; V_44 ++ , V_20 ++ ) {
V_29 = V_20 -> V_22 ;
if ( V_29 & V_34 ) {
F_34 ( V_20 , V_44 , & V_2 , & V_3 , & V_4 , & V_1 ) ;
V_20 -> V_22 = 0 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
F_6 ( & V_18 ) ;
F_33 ( V_58 ) ;
}
static void F_37 ( unsigned long V_74 , int V_12 )
{
unsigned long V_1 ;
unsigned long V_54 , V_75 , V_76 , V_11 , V_44 ;
struct V_19 * V_20 ;
unsigned long V_29 ;
unsigned long V_46 ;
unsigned long V_58 ;
T_1 V_77 ;
struct V_78 * V_79 = & F_38 ( V_78 ) ;
unsigned long V_2 = V_79 -> V_2 ;
int V_4 = V_79 -> V_4 ;
int V_31 ;
F_32 ( V_58 ) ;
for ( V_31 = 0 ; V_31 < V_74 ; V_31 ++ ) {
V_1 = V_79 -> V_1 [ V_31 ] ;
V_77 = V_79 -> V_77 [ V_31 ] ;
F_39 (pte, psize, vpn, index, shift) {
V_54 = F_26 ( V_1 , V_11 , V_4 ) ;
V_76 = F_40 ( V_77 , V_75 ) ;
if ( V_76 & V_80 )
V_54 = ~ V_54 ;
V_44 = ( V_54 & V_55 ) * V_33 ;
V_44 += V_76 & V_81 ;
V_20 = V_28 + V_44 ;
V_46 = F_23 ( V_1 , V_2 , V_4 ) ;
F_7 ( V_20 ) ;
V_29 = V_20 -> V_22 ;
if ( ! F_24 ( V_29 , V_46 ) ||
! ( V_29 & V_34 ) )
F_11 ( V_20 ) ;
else
V_20 -> V_22 = 0 ;
} F_41 () ;
}
if ( F_4 ( V_14 ) &&
V_9 [ V_2 ] . V_17 && V_12 ) {
asm volatile("ptesync":::"memory");
for ( V_31 = 0 ; V_31 < V_74 ; V_31 ++ ) {
V_1 = V_79 -> V_1 [ V_31 ] ;
V_77 = V_79 -> V_77 [ V_31 ] ;
F_39 (pte, psize,
vpn, index, shift) {
F_2 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_41 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_15 = ! F_4 ( V_16 ) ;
if ( V_15 )
F_5 ( & V_18 ) ;
asm volatile("ptesync":::"memory");
for ( V_31 = 0 ; V_31 < V_74 ; V_31 ++ ) {
V_1 = V_79 -> V_1 [ V_31 ] ;
V_77 = V_79 -> V_77 [ V_31 ] ;
F_39 (pte, psize,
vpn, index, shift) {
F_1 ( V_1 , V_2 , V_2 , V_4 ) ;
} F_41 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_15 )
F_6 ( & V_18 ) ;
}
F_33 ( V_58 ) ;
}
void T_2 F_42 ( void )
{
V_82 . V_83 = F_31 ;
V_82 . V_84 = F_22 ;
V_82 . V_85 = F_27 ;
V_82 . V_86 = F_13 ;
V_82 . V_87 = F_18 ;
V_82 . V_88 = F_36 ;
V_82 . V_89 = F_37 ;
}
