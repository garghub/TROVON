static inline void F_1 ( unsigned long V_1 , int V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = F_2 ( 53 ) ;
V_4 |= V_2 << F_3 ( 51 ) ;
V_5 = ( ( unsigned long ) V_1 ) << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
F_4 ( 0 , 1 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
static inline void F_5 ( unsigned long V_1 , unsigned long V_3 )
{
int V_2 ;
asm volatile("ptesync": : :"memory");
F_1 ( V_1 , 0 , V_3 ) ;
if ( V_3 == V_8 ) {
asm volatile("ptesync": : :"memory");
return;
}
for ( V_2 = 1 ; V_2 < V_9 ; V_2 ++ )
F_1 ( V_1 , V_2 , V_10 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_INVALIDATE_ERAT "; isync" : : :"memory");
}
static inline void F_6 ( unsigned long V_1 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = F_2 ( 53 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( 0 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
static inline void F_7 ( unsigned long V_11 , unsigned long V_1 ,
unsigned long V_12 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_11 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_12 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
F_4 ( 0 , 1 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
static inline void F_9 ( unsigned long V_11 , unsigned long V_1 ,
unsigned long V_12 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_11 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_12 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( 0 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_10 ( struct V_13 * V_14 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_14 -> V_15 . V_16 ;
if ( V_1 != V_17 )
F_5 ( V_1 , V_10 ) ;
F_12 () ;
}
static void F_13 ( struct V_13 * V_14 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_14 -> V_15 . V_16 ;
if ( V_1 != V_17 )
F_5 ( V_1 , V_18 ) ;
F_12 () ;
}
void F_14 ( struct V_13 * V_14 , unsigned long V_19 ,
int V_20 )
{
unsigned long V_1 ;
unsigned long V_12 = F_15 ( V_20 ) ;
F_11 () ;
V_1 = V_14 ? V_14 -> V_15 . V_16 : 0 ;
if ( V_1 != V_17 )
F_7 ( V_19 , V_1 , V_12 , V_10 ) ;
F_12 () ;
}
void F_16 ( struct V_21 * V_22 , unsigned long V_19 )
{
#ifdef F_17
if ( V_22 && F_18 ( V_22 ) )
return F_19 ( V_22 , V_19 ) ;
#endif
F_14 ( V_22 ? V_22 -> V_23 : NULL , V_19 ,
V_24 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_14 -> V_15 . V_16 ;
if ( F_21 ( V_1 == V_17 ) )
goto V_25;
if ( ! F_22 ( V_14 ) )
F_6 ( V_1 , V_10 ) ;
else
F_5 ( V_1 , V_10 ) ;
V_25:
F_12 () ;
}
static void F_23 ( struct V_13 * V_14 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_14 -> V_15 . V_16 ;
if ( F_21 ( V_1 == V_17 ) )
goto V_25;
if ( ! F_22 ( V_14 ) )
F_6 ( V_1 , V_18 ) ;
else
F_5 ( V_1 , V_18 ) ;
V_25:
F_12 () ;
}
void F_24 ( struct V_26 * V_27 , unsigned long V_28 )
{
V_27 -> V_29 = 1 ;
}
void F_25 ( struct V_13 * V_14 , unsigned long V_19 ,
int V_20 )
{
unsigned long V_1 ;
unsigned long V_12 = F_15 ( V_20 ) ;
F_11 () ;
V_1 = V_14 ? V_14 -> V_15 . V_16 : 0 ;
if ( F_21 ( V_1 == V_17 ) )
goto V_30;
if ( ! F_22 ( V_14 ) )
F_9 ( V_19 , V_1 , V_12 , V_10 ) ;
else
F_7 ( V_19 , V_1 , V_12 , V_10 ) ;
V_30:
F_12 () ;
}
void F_26 ( struct V_21 * V_22 , unsigned long V_19 )
{
#ifdef F_17
if ( V_22 && F_18 ( V_22 ) )
return F_27 ( V_22 , V_19 ) ;
#endif
F_25 ( V_22 ? V_22 -> V_23 : NULL , V_19 ,
V_24 ) ;
}
void F_28 ( unsigned long V_31 , unsigned long V_32 )
{
F_6 ( 0 , V_18 ) ;
}
void F_29 ( struct V_21 * V_22 , unsigned long V_31 ,
unsigned long V_32 )
{
struct V_13 * V_14 = V_22 -> V_23 ;
F_20 ( V_14 ) ;
}
static int F_30 ( int V_33 )
{
int V_20 ;
if ( V_33 == ( 1UL << V_34 [ V_24 ] . V_35 ) )
V_20 = V_24 ;
else if ( V_33 == ( 1UL << V_34 [ V_36 ] . V_35 ) )
V_20 = V_36 ;
else if ( V_33 == ( 1UL << V_34 [ V_37 ] . V_35 ) )
V_20 = V_37 ;
else
return - 1 ;
return V_20 ;
}
void F_31 ( struct V_26 * V_27 )
{
int V_20 = 0 ;
struct V_13 * V_14 = V_27 -> V_14 ;
int V_33 = V_27 -> V_33 ;
V_20 = F_30 ( V_33 ) ;
if ( V_20 != - 1 && ! V_27 -> V_38 && ! V_27 -> V_29 )
F_32 ( V_14 , V_27 -> V_31 , V_27 -> V_32 , V_20 ) ;
else if ( V_27 -> V_29 ) {
V_27 -> V_29 = 0 ;
F_23 ( V_14 ) ;
} else
F_20 ( V_14 ) ;
}
void F_32 ( struct V_13 * V_14 , unsigned long V_31 ,
unsigned long V_32 , int V_20 )
{
unsigned long V_1 ;
unsigned long V_28 ;
int V_39 = F_22 ( V_14 ) ;
unsigned long V_12 = F_15 ( V_20 ) ;
unsigned long V_33 = 1UL << V_34 [ V_20 ] . V_35 ;
F_11 () ;
V_1 = V_14 ? V_14 -> V_15 . V_16 : 0 ;
if ( F_21 ( V_1 == V_17 ) )
goto V_40;
if ( V_32 == V_41 ||
( V_32 - V_31 ) > V_42 * V_33 ) {
if ( V_39 )
F_5 ( V_1 , V_10 ) ;
else
F_6 ( V_1 , V_10 ) ;
goto V_40;
}
for ( V_28 = V_31 ; V_28 < V_32 ; V_28 += V_33 ) {
if ( V_39 )
F_7 ( V_28 , V_1 , V_12 , V_10 ) ;
else
F_9 ( V_28 , V_1 , V_12 , V_10 ) ;
}
V_40:
F_12 () ;
}
void F_33 ( struct V_13 * V_14 , unsigned long V_28 )
{
int V_39 = F_22 ( V_14 ) ;
unsigned long V_12 = F_15 ( V_24 ) ;
unsigned long V_1 , V_32 ;
V_1 = V_14 ? V_14 -> V_15 . V_16 : 0 ;
F_11 () ;
if ( F_21 ( V_1 == V_17 ) )
goto V_25;
if ( V_43 == 0x1000 ) {
F_23 ( V_14 ) ;
F_12 () ;
return;
}
if ( V_39 )
F_5 ( V_1 , V_8 ) ;
else
F_6 ( V_1 , V_8 ) ;
V_32 = V_28 + V_44 ;
for (; V_28 < V_32 ; V_28 += V_43 ) {
if ( V_39 )
F_7 ( V_28 , V_1 , V_12 , V_10 ) ;
else
F_9 ( V_28 , V_1 , V_12 , V_10 ) ;
}
V_25:
F_12 () ;
}
void F_34 ( unsigned long V_45 , unsigned long V_46 ,
unsigned long V_33 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_12 ;
unsigned long V_3 = V_10 ;
V_12 = F_15 ( F_30 ( V_33 ) ) ;
V_4 = V_46 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_12 << F_3 ( 58 ) ;
V_5 = V_45 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( V_45 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_35 ( unsigned long V_45 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_3 = V_18 ;
V_4 = 0x2 << F_3 ( 53 ) ;
V_5 = V_45 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( V_45 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_36 ( struct V_21 * V_22 ,
unsigned long V_31 , unsigned long V_32 )
{
F_32 ( V_22 -> V_23 , V_31 , V_32 , V_36 ) ;
}
void F_37 ( void )
{
unsigned long V_4 , V_6 , V_7 , V_5 ;
unsigned long V_3 = V_18 ;
V_4 = 0x3 << F_3 ( 53 ) ;
V_6 = 0 ;
V_7 = 1 ;
V_5 = 1 & ( ( 1UL << 32 ) - 1 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(1), "i"(ric), "r"(rs) : "memory");
F_4 ( 0 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( 0 , 0 , V_4 , 0 , V_3 , V_6 , V_7 ) ;
}
void F_38 ( unsigned long V_47 , struct V_13 * V_14 ,
unsigned long V_48 )
{
if ( ! F_39 ( V_49 ) ) {
F_40 ( 1 ) ;
return;
}
if ( V_47 & V_50 )
F_25 ( V_14 , V_48 , V_36 ) ;
else
F_25 ( V_14 , V_48 , V_24 ) ;
}
extern void F_41 ( struct V_13 * V_14 )
{
unsigned int V_1 = V_14 -> V_15 . V_16 ;
if ( F_21 ( V_1 == V_17 ) )
return;
if ( F_39 ( V_51 ) && F_42 () ) {
int V_52 = F_43 () ;
int V_53 = F_44 ( V_52 ) ;
bool V_54 = false ;
for (; V_53 <= F_45 ( V_52 ) && ! V_54 ; V_53 ++ ) {
if ( V_53 == V_52 )
continue;
if ( V_55 [ V_53 ] . V_56 . V_57 )
V_54 = true ;
}
if ( V_54 )
F_5 ( V_1 , V_18 ) ;
}
}
