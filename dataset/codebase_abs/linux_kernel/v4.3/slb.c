static void F_1 ( unsigned long V_1 )
{
F_2 ( V_1 ) ;
}
static inline unsigned long F_3 ( unsigned long V_1 , int V_2 ,
unsigned long V_3 )
{
return ( V_1 & F_4 ( V_2 ) ) | V_4 | V_3 ;
}
static inline unsigned long F_5 ( unsigned long V_1 , int V_2 ,
unsigned long V_5 )
{
return ( F_6 ( V_1 , V_2 ) << F_7 ( V_2 ) ) | V_5 |
( ( unsigned long ) V_2 << V_6 ) ;
}
static inline void F_8 ( unsigned long V_1 , int V_2 ,
unsigned long V_5 ,
unsigned long V_3 )
{
F_9 () -> V_7 [ V_3 ] . V_8 = 0 ;
F_9 () -> V_7 [ V_3 ] . V_9 =
F_10 ( F_5 ( V_1 , V_2 , V_5 ) ) ;
F_9 () -> V_7 [ V_3 ] . V_8 =
F_10 ( F_3 ( V_1 , V_2 , V_3 ) ) ;
}
static inline void F_11 ( unsigned long V_3 )
{
F_9 () -> V_7 [ V_3 ] . V_8 = 0 ;
}
static inline void F_12 ( unsigned long V_1 , int V_2 ,
unsigned long V_5 ,
unsigned long V_3 )
{
F_8 ( V_1 , V_2 , V_5 , V_3 ) ;
asm volatile("slbmte %0,%1" :
: "r" (mk_vsid_data(ea, ssize, flags)),
"r" (mk_esid_data(ea, ssize, entry))
: "memory" );
}
static void F_13 ( void )
{
unsigned long V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 , V_15 ;
V_10 = V_16 [ V_17 ] . V_18 ;
V_11 = V_16 [ V_19 ] . V_18 ;
V_12 = V_20 | V_10 ;
V_13 = V_20 | V_11 ;
V_14 = F_3 ( F_14 () -> V_21 , V_22 , 2 ) ;
if ( ( V_14 & ~ 0xfffffffUL ) <= V_23 ) {
V_14 &= ~ V_4 ;
V_15 = 0 ;
F_11 ( 2 ) ;
} else {
F_8 ( F_14 () -> V_21 , V_22 , V_12 , 2 ) ;
V_15 =
F_15 ( F_9 () -> V_7 [ 2 ] . V_9 ) ;
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
F_14 () -> V_24 = 0 ;
}
void F_20 ( void )
{
unsigned long V_13 ;
V_13 = V_20 | V_16 [ V_19 ] . V_18 ;
F_8 ( V_25 , V_22 , V_13 , 1 ) ;
F_16 () ;
}
static inline int F_21 ( unsigned long V_26 , unsigned long V_27 )
{
int V_28 ;
if ( ! F_22 ( V_29 ) )
return ( F_23 ( V_26 ) == F_23 ( V_27 ) ) ;
V_28 = ( ( ( V_26 >> V_30 ) != 0 ) +
( ( V_27 >> V_30 ) != 0 ) ) ;
if ( V_28 == 0 )
return ( F_23 ( V_26 ) == F_23 ( V_27 ) ) ;
if ( V_28 == 1 )
return 0 ;
return ( F_24 ( V_26 ) == F_24 ( V_27 ) ) ;
}
void F_25 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
unsigned long V_35 ;
unsigned long V_36 = 0 ;
unsigned long V_37 = F_26 ( V_32 ) ;
unsigned long V_38 = F_27 ( V_32 ) ;
unsigned long V_39 ;
F_19 () ;
V_35 = F_14 () -> V_24 ;
if ( ! F_22 ( V_40 ) &&
V_35 <= V_41 ) {
int V_42 ;
asm volatile("isync" : : : "memory");
for ( V_42 = 0 ; V_42 < V_35 ; V_42 ++ ) {
V_36 = ( unsigned long ) F_14 () -> V_43 [ V_42 ]
<< V_44 ;
V_36 |= F_28 ( V_36 )
<< V_45 ;
V_36 |= V_46 ;
asm volatile("slbie %0" : : "r" (slbie_data));
}
asm volatile("isync" : : : "memory");
} else {
F_13 () ;
}
if ( V_35 == 1 || V_35 > V_41 )
asm volatile("slbie %0" : : "r" (slbie_data));
F_14 () -> V_24 = 0 ;
F_14 () -> V_47 = V_34 -> V_47 ;
V_39 = 0x10000000 ;
if ( F_29 ( V_37 ) || F_29 ( V_38 ) ||
F_29 ( V_39 ) )
return;
F_1 ( V_37 ) ;
if ( ! F_21 ( V_37 , V_38 ) )
F_1 ( V_38 ) ;
if ( ! F_21 ( V_37 , V_39 ) &&
! F_21 ( V_38 , V_39 ) )
F_1 ( V_39 ) ;
}
static inline void F_30 ( unsigned int * V_48 ,
unsigned int V_49 )
{
unsigned int V_50 = ( * V_48 & 0xffff0000 ) | V_49 ;
F_31 ( V_48 , V_50 ) ;
}
void F_32 ( T_1 V_51 )
{
if ( V_52 == V_51 )
return;
V_52 = V_51 ;
F_30 ( V_53 , V_52 ) ;
}
void F_33 ( void )
{
unsigned long V_10 , V_11 , V_54 ;
unsigned long V_12 , V_13 ;
static int V_55 ;
#ifdef F_34
unsigned long V_56 ;
#endif
V_10 = V_16 [ V_17 ] . V_18 ;
V_54 = V_16 [ V_57 ] . V_18 ;
V_11 = V_16 [ V_19 ] . V_18 ;
F_14 () -> V_58 = V_20 | V_11 ;
#ifdef F_34
V_56 = V_16 [ V_59 ] . V_18 ;
#endif
if ( ! V_55 ) {
V_55 = 1 ;
F_30 ( V_60 ,
V_20 | V_10 ) ;
F_30 ( V_61 ,
V_20 | V_54 ) ;
F_30 ( V_53 ,
V_52 ) ;
F_35 ( L_1 , V_10 ) ;
F_35 ( L_2 , V_54 ) ;
#ifdef F_34
F_30 ( V_62 ,
V_20 | V_56 ) ;
F_35 ( L_3 , V_56 ) ;
#endif
}
F_14 () -> V_63 = V_64 ;
V_12 = V_20 | V_10 ;
V_13 = V_20 | V_11 ;
asm volatile("isync":::"memory");
asm volatile("slbmte %0,%0"::"r" (0) : "memory");
asm volatile("isync; slbia; isync":::"memory");
F_12 ( V_23 , V_22 , V_12 , 0 ) ;
F_12 ( V_25 , V_22 , V_13 , 1 ) ;
F_11 ( 2 ) ;
if ( F_36 () != V_65 &&
( F_14 () -> V_21 & F_4 ( V_22 ) ) > V_23 )
F_12 ( F_14 () -> V_21 ,
V_22 , V_12 , 2 ) ;
asm volatile("isync":::"memory");
}
