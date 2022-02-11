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
unsigned long V_7 )
{
F_9 () -> V_8 [ V_7 ] . V_9 = 0 ;
F_9 () -> V_8 [ V_7 ] . V_10 =
F_10 ( F_5 ( V_1 , V_2 , V_5 ) ) ;
F_9 () -> V_8 [ V_7 ] . V_9 =
F_10 ( F_3 ( V_1 , V_2 , V_7 ) ) ;
}
static inline void F_11 ( unsigned long V_7 )
{
F_9 () -> V_8 [ V_7 ] . V_9 = 0 ;
}
static inline void F_12 ( unsigned long V_1 , int V_2 ,
unsigned long V_5 ,
unsigned long V_7 )
{
F_8 ( V_1 , V_2 , V_5 , V_7 ) ;
asm volatile("slbmte %0,%1" :
: "r" (mk_vsid_data(ea, ssize, flags)),
"r" (mk_esid_data(ea, ssize, entry))
: "memory" );
}
static void F_13 ( void )
{
unsigned long V_11 , V_12 , V_13 , V_14 ;
unsigned long V_15 , V_16 ;
V_11 = V_17 [ V_18 ] . V_19 ;
V_12 = V_17 [ V_20 ] . V_19 ;
V_13 = V_21 | V_11 ;
V_14 = V_21 | V_12 ;
V_15 = F_3 ( F_14 () -> V_22 , V_23 , 2 ) ;
if ( ( V_15 & ~ 0xfffffffUL ) <= V_24 ) {
V_15 &= ~ V_4 ;
V_16 = 0 ;
F_11 ( 2 ) ;
} else {
F_8 ( F_14 () -> V_22 , V_23 , V_13 , 2 ) ;
V_16 =
F_15 ( F_9 () -> V_8 [ 2 ] . V_10 ) ;
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
F_14 () -> V_25 = 0 ;
}
void F_20 ( void )
{
unsigned long V_14 ;
V_14 = V_21 | V_17 [ V_20 ] . V_19 ;
F_8 ( V_26 , V_23 , V_14 , 1 ) ;
F_16 () ;
}
static inline int F_21 ( unsigned long V_27 , unsigned long V_28 )
{
int V_29 ;
if ( ! F_22 ( V_30 ) )
return ( F_23 ( V_27 ) == F_23 ( V_28 ) ) ;
V_29 = ( ( ( V_27 >> V_31 ) != 0 ) +
( ( V_28 >> V_31 ) != 0 ) ) ;
if ( V_29 == 0 )
return ( F_23 ( V_27 ) == F_23 ( V_28 ) ) ;
if ( V_29 == 1 )
return 0 ;
return ( F_24 ( V_27 ) == F_24 ( V_28 ) ) ;
}
void F_25 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
unsigned long V_36 ;
unsigned long V_37 = 0 ;
unsigned long V_38 = F_26 ( V_33 ) ;
unsigned long V_39 = F_27 ( V_33 ) ;
unsigned long V_40 ;
F_19 () ;
V_36 = F_14 () -> V_25 ;
if ( ! F_22 ( V_41 ) &&
V_36 <= V_42 ) {
int V_43 ;
asm volatile("isync" : : : "memory");
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ ) {
V_37 = ( unsigned long ) F_14 () -> V_44 [ V_43 ]
<< V_45 ;
V_37 |= F_28 ( V_37 )
<< V_46 ;
V_37 |= V_47 ;
asm volatile("slbie %0" : : "r" (slbie_data));
}
asm volatile("isync" : : : "memory");
} else {
F_13 () ;
}
if ( V_36 == 1 || V_36 > V_42 )
asm volatile("slbie %0" : : "r" (slbie_data));
F_14 () -> V_25 = 0 ;
F_14 () -> V_48 = V_35 -> V_48 ;
V_40 = 0x10000000 ;
if ( F_29 ( V_38 ) || F_29 ( V_39 ) ||
F_29 ( V_40 ) )
return;
F_1 ( V_38 ) ;
if ( ! F_21 ( V_38 , V_39 ) )
F_1 ( V_39 ) ;
if ( ! F_21 ( V_38 , V_40 ) &&
! F_21 ( V_39 , V_40 ) )
F_1 ( V_40 ) ;
}
static inline void F_30 ( unsigned int * V_49 ,
unsigned int V_50 )
{
int V_51 = ( * V_49 & 0xffff0000 ) | V_50 ;
F_31 ( V_49 , V_51 ) ;
}
void F_32 ( T_1 V_52 )
{
extern unsigned int * V_53 ;
if ( V_54 == V_52 )
return;
V_54 = V_52 ;
F_30 ( V_53 , V_54 ) ;
}
void F_33 ( void )
{
unsigned long V_11 , V_12 , V_55 ;
unsigned long V_13 , V_14 ;
static int V_56 ;
extern unsigned int * V_57 ;
extern unsigned int * V_58 ;
extern unsigned int * V_53 ;
#ifdef F_34
extern unsigned int * V_59 ;
unsigned long V_60 ;
#endif
V_11 = V_17 [ V_18 ] . V_19 ;
V_55 = V_17 [ V_61 ] . V_19 ;
V_12 = V_17 [ V_20 ] . V_19 ;
F_14 () -> V_62 = V_21 | V_12 ;
#ifdef F_34
V_60 = V_17 [ V_63 ] . V_19 ;
#endif
if ( ! V_56 ) {
V_56 = 1 ;
F_30 ( V_57 ,
V_21 | V_11 ) ;
F_30 ( V_58 ,
V_21 | V_55 ) ;
F_30 ( V_53 ,
V_54 ) ;
F_35 ( L_1 , V_11 ) ;
F_35 ( L_2 , V_55 ) ;
#ifdef F_34
F_30 ( V_59 ,
V_21 | V_60 ) ;
F_35 ( L_3 , V_60 ) ;
#endif
}
F_14 () -> V_64 = V_65 ;
V_13 = V_21 | V_11 ;
V_14 = V_21 | V_12 ;
asm volatile("isync":::"memory");
asm volatile("slbmte %0,%0"::"r" (0) : "memory");
asm volatile("isync; slbia; isync":::"memory");
F_12 ( V_24 , V_23 , V_13 , 0 ) ;
F_12 ( V_26 , V_23 , V_14 , 1 ) ;
F_11 ( 2 ) ;
if ( F_36 () != V_66 &&
( F_14 () -> V_22 & F_4 ( V_23 ) ) > V_24 )
F_12 ( F_14 () -> V_22 ,
V_23 , V_13 , 2 ) ;
asm volatile("isync":::"memory");
}
