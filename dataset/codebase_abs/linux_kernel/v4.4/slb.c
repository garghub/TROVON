static void F_1 ( unsigned long V_1 )
{
F_2 ( V_1 ) ;
}
static inline unsigned long F_3 ( unsigned long V_1 , int V_2 ,
enum V_3 V_4 )
{
return ( V_1 & F_4 ( V_2 ) ) | V_5 | V_4 ;
}
static inline unsigned long F_5 ( unsigned long V_1 , int V_2 ,
unsigned long V_6 )
{
return ( F_6 ( V_1 , V_2 ) << F_7 ( V_2 ) ) | V_6 |
( ( unsigned long ) V_2 << V_7 ) ;
}
static inline void F_8 ( unsigned long V_1 , int V_2 ,
unsigned long V_6 ,
enum V_3 V_4 )
{
struct V_8 * V_9 = F_9 () ;
V_9 -> V_10 [ V_4 ] . V_11 = 0 ;
V_9 -> V_10 [ V_4 ] . V_12 = F_10 ( F_5 ( V_1 , V_2 , V_6 ) ) ;
V_9 -> V_10 [ V_4 ] . V_11 = F_10 ( F_3 ( V_1 , V_2 , V_4 ) ) ;
}
static inline void F_11 ( enum V_3 V_4 )
{
F_9 () -> V_10 [ V_4 ] . V_11 = 0 ;
}
static inline void F_12 ( unsigned long V_1 , int V_2 ,
unsigned long V_6 ,
enum V_3 V_4 )
{
F_8 ( V_1 , V_2 , V_6 , V_4 ) ;
asm volatile("slbmte %0,%1" :
: "r" (mk_vsid_data(ea, ssize, flags)),
"r" (mk_esid_data(ea, ssize, index))
: "memory" );
}
static void F_13 ( void )
{
unsigned long V_13 , V_14 , V_15 , V_16 ;
unsigned long V_17 , V_18 ;
V_13 = V_19 [ V_20 ] . V_21 ;
V_14 = V_19 [ V_22 ] . V_21 ;
V_15 = V_23 | V_13 ;
V_16 = V_23 | V_14 ;
V_17 = F_3 ( F_14 () -> V_24 , V_25 , V_26 ) ;
if ( ( V_17 & ~ 0xfffffffUL ) <= V_27 ) {
V_17 &= ~ V_5 ;
V_18 = 0 ;
F_11 ( V_26 ) ;
} else {
F_8 ( F_14 () -> V_24 , V_25 , V_15 , V_26 ) ;
V_18 =
F_15 ( F_9 () -> V_10 [ V_26 ] . V_12 ) ;
}
asm volatile("isync\n"
"slbia\n"
"slbmte %0,%1\n"
"slbmte %2,%3\n"
"isync"
:: "r"(mk_vsid_data(VMALLOC_START, mmu_kernel_ssize, vflags)),
"r"(mk_esid_data(VMALLOC_START, mmu_kernel_ssize, 1)),
"r"(ksp_vsid_data),
"r"(ksp_esid_data)
: "memory");
}
void F_16 ( void )
{
F_17 ( ! F_18 () ) ;
F_19 () ;
F_13 () ;
F_14 () -> V_28 = 0 ;
}
void F_20 ( void )
{
unsigned long V_16 ;
V_16 = V_23 | V_19 [ V_22 ] . V_21 ;
F_8 ( V_29 , V_25 , V_16 , V_30 ) ;
F_16 () ;
}
static inline int F_21 ( unsigned long V_31 , unsigned long V_32 )
{
int V_33 ;
if ( ! F_22 ( V_34 ) )
return ( F_23 ( V_31 ) == F_23 ( V_32 ) ) ;
V_33 = ( ( ( V_31 >> V_35 ) != 0 ) +
( ( V_32 >> V_35 ) != 0 ) ) ;
if ( V_33 == 0 )
return ( F_23 ( V_31 ) == F_23 ( V_32 ) ) ;
if ( V_33 == 1 )
return 0 ;
return ( F_24 ( V_31 ) == F_24 ( V_32 ) ) ;
}
void F_25 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
unsigned long V_40 ;
unsigned long V_41 = 0 ;
unsigned long V_42 = F_26 ( V_37 ) ;
unsigned long V_43 = F_27 ( V_37 ) ;
unsigned long V_44 ;
F_19 () ;
V_40 = F_14 () -> V_28 ;
if ( ! F_22 ( V_45 ) &&
V_40 <= V_46 ) {
int V_47 ;
asm volatile("isync" : : : "memory");
for ( V_47 = 0 ; V_47 < V_40 ; V_47 ++ ) {
V_41 = ( unsigned long ) F_14 () -> V_48 [ V_47 ]
<< V_49 ;
V_41 |= F_28 ( V_41 )
<< V_50 ;
V_41 |= V_51 ;
asm volatile("slbie %0" : : "r" (slbie_data));
}
asm volatile("isync" : : : "memory");
} else {
F_13 () ;
}
if ( V_40 == 1 || V_40 > V_46 )
asm volatile("slbie %0" : : "r" (slbie_data));
F_14 () -> V_28 = 0 ;
F_14 () -> V_52 = V_39 -> V_52 ;
V_44 = 0x10000000 ;
if ( F_29 ( V_42 ) || F_29 ( V_43 ) ||
F_29 ( V_44 ) )
return;
F_1 ( V_42 ) ;
if ( ! F_21 ( V_42 , V_43 ) )
F_1 ( V_43 ) ;
if ( ! F_21 ( V_42 , V_44 ) &&
! F_21 ( V_43 , V_44 ) )
F_1 ( V_44 ) ;
}
static inline void F_30 ( unsigned int * V_53 ,
unsigned int V_54 )
{
unsigned int V_55 = ( * V_53 & 0xffff0000 ) | V_54 ;
F_31 ( V_53 , V_55 ) ;
}
void F_32 ( T_1 V_56 )
{
if ( V_57 == V_56 )
return;
V_57 = V_56 ;
F_30 ( V_58 , V_57 ) ;
}
void F_33 ( void )
{
unsigned long V_13 , V_14 , V_59 ;
unsigned long V_15 , V_16 ;
static int V_60 ;
#ifdef F_34
unsigned long V_61 ;
#endif
V_13 = V_19 [ V_20 ] . V_21 ;
V_59 = V_19 [ V_62 ] . V_21 ;
V_14 = V_19 [ V_22 ] . V_21 ;
F_14 () -> V_63 = V_23 | V_14 ;
#ifdef F_34
V_61 = V_19 [ V_64 ] . V_21 ;
#endif
if ( ! V_60 ) {
V_60 = 1 ;
F_30 ( V_65 ,
V_23 | V_13 ) ;
F_30 ( V_66 ,
V_23 | V_59 ) ;
F_30 ( V_58 ,
V_57 ) ;
F_35 ( L_1 , V_13 ) ;
F_35 ( L_2 , V_59 ) ;
#ifdef F_34
F_30 ( V_67 ,
V_23 | V_61 ) ;
F_35 ( L_3 , V_61 ) ;
#endif
}
F_14 () -> V_68 = V_69 ;
V_15 = V_23 | V_13 ;
V_16 = V_23 | V_14 ;
asm volatile("isync":::"memory");
asm volatile("slbmte %0,%0"::"r" (0) : "memory");
asm volatile("isync; slbia; isync":::"memory");
F_12 ( V_27 , V_25 , V_15 , V_70 ) ;
F_12 ( V_29 , V_25 , V_16 , V_30 ) ;
F_11 ( V_26 ) ;
if ( F_36 () != V_71 &&
( F_14 () -> V_24 & F_4 ( V_25 ) ) > V_27 )
F_12 ( F_14 () -> V_24 ,
V_25 , V_15 , V_26 ) ;
asm volatile("isync":::"memory");
}
