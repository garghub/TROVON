static inline void F_1 ( unsigned long V_1 , int V_2 , int V_3 )
{
unsigned int V_4 ;
V_1 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_5 :
V_1 &= ~ 0xffful ;
V_1 |= V_3 << 8 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,0", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
default:
V_4 = V_6 [ V_2 ] . V_4 ;
V_1 &= ~ ( ( 1ul << V_6 [ V_2 ] . V_7 ) - 1 ) ;
V_1 |= V_4 << 12 ;
V_1 |= V_3 << 8 ;
V_1 |= 1 ;
asm volatile(ASM_FTR_IFCLR("tlbie %0,1", PPC_TLBIE(%1,%0), %2)
: : "r" (va), "r"(0), "i" (CPU_FTR_ARCH_206)
: "memory");
break;
}
}
static inline void F_2 ( unsigned long V_1 , int V_2 , int V_3 )
{
unsigned int V_4 ;
V_1 &= ~ ( 0xffffULL << 48 ) ;
switch ( V_2 ) {
case V_5 :
V_1 &= ~ 0xffful ;
V_1 |= V_3 << 8 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (0 << 21)"
: : "r"(va) : "memory");
break;
default:
V_4 = V_6 [ V_2 ] . V_4 ;
V_1 &= ~ ( ( 1ul << V_6 [ V_2 ] . V_7 ) - 1 ) ;
V_1 |= V_4 << 12 ;
V_1 |= V_3 << 8 ;
V_1 |= 1 ;
asm volatile(".long 0x7c000224 | (%0 << 11) | (1 << 21)"
: : "r"(va) : "memory");
break;
}
}
static inline void F_3 ( unsigned long V_1 , int V_2 , int V_3 , int V_8 )
{
unsigned int V_9 = V_8 && F_4 ( V_10 ) ;
int V_11 = ! F_4 ( V_12 ) ;
if ( V_9 )
V_9 = V_6 [ V_2 ] . V_13 ;
if ( V_11 && ! V_9 )
F_5 ( & V_14 ) ;
asm volatile("ptesync": : :"memory");
if ( V_9 ) {
F_2 ( V_1 , V_2 , V_3 ) ;
asm volatile("ptesync": : :"memory");
} else {
F_1 ( V_1 , V_2 , V_3 ) ;
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
if ( V_11 && ! V_9 )
F_6 ( & V_14 ) ;
}
static inline void F_7 ( struct V_15 * V_16 )
{
unsigned long * V_17 = & V_16 -> V_18 ;
while ( 1 ) {
if ( ! F_8 ( V_19 , V_17 ) )
break;
while( F_9 ( V_19 , V_17 ) )
F_10 () ;
}
}
static inline void F_11 ( struct V_15 * V_16 )
{
unsigned long * V_17 = & V_16 -> V_18 ;
F_12 ( V_19 , V_17 ) ;
}
static long F_13 ( unsigned long V_20 , unsigned long V_1 ,
unsigned long V_21 , unsigned long V_22 ,
unsigned long V_23 , int V_2 , int V_3 )
{
struct V_15 * V_16 = V_24 + V_20 ;
unsigned long V_25 , V_26 ;
int V_27 ;
if ( ! ( V_23 & V_28 ) ) {
F_14 ( L_1
L_2 ,
V_20 , V_1 , V_21 , V_22 , V_23 , V_2 ) ;
}
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ! ( V_16 -> V_18 & V_30 ) ) {
F_7 ( V_16 ) ;
if ( ! ( V_16 -> V_18 & V_30 ) )
break;
F_11 ( V_16 ) ;
}
V_16 ++ ;
}
if ( V_27 == V_29 )
return - 1 ;
V_25 = F_15 ( V_1 , V_2 , V_3 ) | V_23 | V_30 ;
V_26 = F_16 ( V_21 , V_2 ) | V_22 ;
if ( ! ( V_23 & V_28 ) ) {
F_14 ( L_3 ,
V_27 , V_25 , V_26 ) ;
}
V_16 -> V_31 = V_26 ;
F_17 () ;
V_16 -> V_18 = V_25 ;
__asm__ __volatile__ ("ptesync" : : : "memory");
return V_27 | ( ! ! ( V_23 & V_32 ) << 3 ) ;
}
static long F_18 ( unsigned long V_20 )
{
struct V_15 * V_16 ;
int V_27 ;
int V_33 ;
unsigned long V_25 ;
F_14 ( L_4 , V_20 ) ;
V_33 = F_19 () & 0x7 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_16 = V_24 + V_20 + V_33 ;
V_25 = V_16 -> V_18 ;
if ( ( V_25 & V_30 ) && ! ( V_25 & V_28 ) ) {
F_7 ( V_16 ) ;
V_25 = V_16 -> V_18 ;
if ( ( V_25 & V_30 )
&& ! ( V_25 & V_28 ) )
break;
F_11 ( V_16 ) ;
}
V_33 ++ ;
V_33 &= 0x7 ;
}
if ( V_27 == V_29 )
return - 1 ;
V_16 -> V_18 = 0 ;
return V_27 ;
}
static long F_20 ( unsigned long V_34 , unsigned long V_35 ,
unsigned long V_1 , int V_2 , int V_3 ,
int V_8 )
{
struct V_15 * V_16 = V_24 + V_34 ;
unsigned long V_25 , V_36 ;
int V_37 = 0 ;
V_36 = F_15 ( V_1 , V_2 , V_3 ) ;
F_14 ( L_5 ,
V_1 , V_36 & V_38 , V_34 , V_35 ) ;
F_7 ( V_16 ) ;
V_25 = V_16 -> V_18 ;
if ( ! F_21 ( V_25 , V_36 ) || ! ( V_25 & V_30 ) ) {
F_14 ( L_6 ) ;
V_37 = - 1 ;
} else {
F_14 ( L_7 ) ;
V_16 -> V_31 = ( V_16 -> V_31 & ~ ( V_39 | V_40 ) ) |
( V_35 & ( V_39 | V_40 | V_41 ) ) ;
}
F_11 ( V_16 ) ;
F_3 ( V_1 , V_2 , V_3 , V_8 ) ;
return V_37 ;
}
static long F_22 ( unsigned long V_1 , int V_2 , int V_3 )
{
struct V_15 * V_16 ;
unsigned long V_42 ;
unsigned long V_27 ;
long V_34 ;
unsigned long V_36 , V_25 ;
V_42 = F_23 ( V_1 , V_6 [ V_2 ] . V_7 , V_3 ) ;
V_36 = F_15 ( V_1 , V_2 , V_3 ) ;
V_34 = ( V_42 & V_43 ) * V_29 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_16 = V_24 + V_34 ;
V_25 = V_16 -> V_18 ;
if ( F_21 ( V_25 , V_36 ) && ( V_25 & V_30 ) )
return V_34 ;
++ V_34 ;
}
return - 1 ;
}
static void F_24 ( unsigned long V_35 , unsigned long V_44 ,
int V_2 , int V_3 )
{
unsigned long V_45 , V_1 ;
long V_34 ;
struct V_15 * V_16 ;
V_45 = F_25 ( V_44 , V_3 ) ;
V_1 = F_26 ( V_44 , V_45 , V_3 ) ;
V_34 = F_22 ( V_1 , V_2 , V_3 ) ;
if ( V_34 == - 1 )
F_27 ( L_8 ) ;
V_16 = V_24 + V_34 ;
V_16 -> V_31 = ( V_16 -> V_31 & ~ ( V_39 | V_40 ) ) |
( V_35 & ( V_39 | V_40 ) ) ;
F_3 ( V_1 , V_2 , V_3 , 0 ) ;
}
static void F_28 ( unsigned long V_34 , unsigned long V_1 ,
int V_2 , int V_3 , int V_8 )
{
struct V_15 * V_16 = V_24 + V_34 ;
unsigned long V_25 ;
unsigned long V_36 ;
unsigned long V_46 ;
F_29 ( V_46 ) ;
F_14 ( L_9 , V_1 , V_34 ) ;
V_36 = F_15 ( V_1 , V_2 , V_3 ) ;
F_7 ( V_16 ) ;
V_25 = V_16 -> V_18 ;
if ( ! F_21 ( V_25 , V_36 ) || ! ( V_25 & V_30 ) )
F_11 ( V_16 ) ;
else
V_16 -> V_18 = 0 ;
F_3 ( V_1 , V_2 , V_3 , V_8 ) ;
F_30 ( V_46 ) ;
}
static void F_31 ( struct V_15 * V_47 , unsigned long V_34 ,
int * V_2 , int * V_3 , unsigned long * V_1 )
{
unsigned long V_26 = V_47 -> V_31 ;
unsigned long V_25 = V_47 -> V_18 ;
unsigned long V_48 ;
int V_27 , V_49 , V_7 , V_4 ;
if ( ! ( V_25 & V_50 ) )
V_49 = V_5 ;
else {
for ( V_27 = 0 ; V_27 < V_51 ; V_27 ++ ) {
if ( ( V_26 & F_32 ( V_27 + 1 ) ) == F_32 ( V_27 + 1 ) )
break;
}
V_4 = F_32 ( V_27 + 1 ) >> V_52 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
if ( V_49 == V_5 )
continue;
if ( ! V_6 [ V_49 ] . V_7 )
continue;
if ( V_4 == V_6 [ V_49 ] . V_4 )
break;
}
}
V_7 = V_6 [ V_49 ] . V_7 ;
V_48 = ( F_33 ( V_25 ) & ~ V_6 [ V_49 ] . V_54 ) << 23 ;
if ( V_7 < 23 ) {
unsigned long V_55 , V_45 , V_56 ;
V_56 = V_34 / V_29 ;
if ( V_25 & V_32 )
V_56 = ~ V_56 ;
switch ( V_25 >> V_57 ) {
case V_58 :
V_55 = ( ( V_48 >> 28 ) ^ V_56 ) & V_43 ;
break;
case V_59 :
V_45 = V_48 >> 40 ;
V_55 = ( V_45 ^ ( V_45 << 25 ) ^ V_56 ) & V_43 ;
break;
default:
V_48 = V_55 = V_49 = 0 ;
}
V_48 |= ( V_55 << V_6 [ V_49 ] . V_7 ) ;
}
* V_1 = V_48 ;
* V_2 = V_49 ;
* V_3 = V_25 >> V_57 ;
}
static void F_34 ( void )
{
unsigned long V_34 , V_60 , V_46 ;
struct V_15 * V_16 = V_24 ;
unsigned long V_25 , V_1 ;
unsigned long V_61 ;
int V_2 , V_3 ;
V_61 = V_43 + 1 ;
F_29 ( V_46 ) ;
F_5 ( & V_14 ) ;
V_60 = V_61 * V_29 ;
for ( V_34 = 0 ; V_34 < V_60 ; V_34 ++ , V_16 ++ ) {
V_25 = V_16 -> V_18 ;
if ( V_25 & V_30 ) {
F_31 ( V_16 , V_34 , & V_2 , & V_3 , & V_1 ) ;
V_16 -> V_18 = 0 ;
F_1 ( V_1 , V_2 , V_3 ) ;
}
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
F_6 ( & V_14 ) ;
F_30 ( V_46 ) ;
}
static void F_35 ( unsigned long V_62 , int V_8 )
{
unsigned long V_1 , V_42 , V_63 , V_64 , V_7 , V_34 ;
struct V_15 * V_16 ;
unsigned long V_25 ;
unsigned long V_36 ;
unsigned long V_46 ;
T_1 V_65 ;
struct V_66 * V_67 = & F_36 ( V_66 ) ;
unsigned long V_2 = V_67 -> V_2 ;
int V_3 = V_67 -> V_3 ;
int V_27 ;
F_29 ( V_46 ) ;
for ( V_27 = 0 ; V_27 < V_62 ; V_27 ++ ) {
V_1 = V_67 -> V_68 [ V_27 ] ;
V_65 = V_67 -> V_65 [ V_27 ] ;
F_37 (pte, psize, va, index, shift) {
V_42 = F_23 ( V_1 , V_7 , V_3 ) ;
V_64 = F_38 ( V_65 , V_63 ) ;
if ( V_64 & V_69 )
V_42 = ~ V_42 ;
V_34 = ( V_42 & V_43 ) * V_29 ;
V_34 += V_64 & V_70 ;
V_16 = V_24 + V_34 ;
V_36 = F_15 ( V_1 , V_2 , V_3 ) ;
F_7 ( V_16 ) ;
V_25 = V_16 -> V_18 ;
if ( ! F_21 ( V_25 , V_36 ) ||
! ( V_25 & V_30 ) )
F_11 ( V_16 ) ;
else
V_16 -> V_18 = 0 ;
} F_39 () ;
}
if ( F_4 ( V_10 ) &&
V_6 [ V_2 ] . V_13 && V_8 ) {
asm volatile("ptesync":::"memory");
for ( V_27 = 0 ; V_27 < V_62 ; V_27 ++ ) {
V_1 = V_67 -> V_68 [ V_27 ] ;
V_65 = V_67 -> V_65 [ V_27 ] ;
F_37 (pte, psize, va, index,
shift) {
F_2 ( V_1 , V_2 , V_3 ) ;
} F_39 () ;
}
asm volatile("ptesync":::"memory");
} else {
int V_11 = ! F_4 ( V_12 ) ;
if ( V_11 )
F_5 ( & V_14 ) ;
asm volatile("ptesync":::"memory");
for ( V_27 = 0 ; V_27 < V_62 ; V_27 ++ ) {
V_1 = V_67 -> V_68 [ V_27 ] ;
V_65 = V_67 -> V_65 [ V_27 ] ;
F_37 (pte, psize, va, index,
shift) {
F_1 ( V_1 , V_2 , V_3 ) ;
} F_39 () ;
}
asm volatile("eieio; tlbsync; ptesync":::"memory");
if ( V_11 )
F_6 ( & V_14 ) ;
}
F_30 ( V_46 ) ;
}
static inline int F_40 ( void )
{
struct V_71 * V_72 = F_41 ( L_10 ) ;
int V_73 = 1 ;
if ( V_72 ) {
const char * V_74 = F_42 ( V_72 , L_11 , NULL ) ;
if ( V_74 && ! strcmp ( V_74 , L_12 ) )
V_73 = 0 ;
F_43 ( V_72 ) ;
}
return V_73 ;
}
static inline int F_40 ( void )
{
return 1 ;
}
void T_2 F_44 ( void )
{
V_75 . V_76 = F_28 ;
V_75 . V_77 = F_20 ;
V_75 . V_78 = F_24 ;
V_75 . V_79 = F_13 ;
V_75 . V_80 = F_18 ;
V_75 . V_81 = F_34 ;
if ( F_40 () )
V_75 . V_82 = F_35 ;
}
