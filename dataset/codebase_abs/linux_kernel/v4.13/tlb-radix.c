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
if ( V_3 == V_8 )
V_3 = V_9 ;
for ( V_2 = 1 ; V_2 < V_10 ; V_2 ++ )
F_1 ( V_1 , V_2 , V_3 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_INVALIDATE_ERAT "; isync" : : :"memory");
}
static inline void F_6 ( unsigned long V_1 )
{
asm volatile("ptesync": : :"memory");
F_1 ( V_1 , 0 , V_11 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_INVALIDATE_ERAT "; isync" : : :"memory");
}
static inline void F_7 ( unsigned long V_1 , unsigned long V_3 )
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
static inline void F_8 ( unsigned long V_12 , unsigned long V_1 ,
unsigned long V_13 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_12 & ~ ( F_9 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
F_4 ( 0 , 1 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
static inline void F_10 ( unsigned long V_12 , unsigned long V_1 ,
unsigned long V_13 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_12 & ~ ( F_9 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( 0 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_11 ( struct V_14 * V_15 )
{
unsigned long V_1 ;
F_12 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( V_1 != V_18 )
F_5 ( V_1 , V_8 ) ;
F_13 () ;
}
void F_14 ( struct V_19 * V_20 , unsigned long V_21 )
{
unsigned long V_1 ;
struct V_14 * V_15 = V_20 -> V_15 ;
if ( V_20 -> V_22 )
return;
F_12 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( V_1 != V_18 )
F_6 ( V_1 ) ;
F_13 () ;
}
void F_15 ( struct V_14 * V_15 , unsigned long V_23 ,
int V_24 )
{
unsigned long V_1 ;
unsigned long V_13 = F_16 ( V_24 ) ;
F_12 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( V_1 != V_18 )
F_8 ( V_23 , V_1 , V_13 , V_9 ) ;
F_13 () ;
}
void F_17 ( struct V_25 * V_26 , unsigned long V_23 )
{
#ifdef F_18
if ( V_26 && F_19 ( V_26 ) )
return F_20 ( V_26 , V_23 ) ;
#endif
F_15 ( V_26 ? V_26 -> V_27 : NULL , V_23 ,
V_28 ) ;
}
void F_21 ( struct V_14 * V_15 )
{
unsigned long V_1 ;
F_12 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( F_22 ( V_1 == V_18 ) )
goto V_29;
if ( ! F_23 ( V_15 ) )
F_7 ( V_1 , V_8 ) ;
else
F_5 ( V_1 , V_8 ) ;
V_29:
F_13 () ;
}
void F_24 ( struct V_19 * V_20 , unsigned long V_21 )
{
unsigned long V_1 ;
struct V_14 * V_15 = V_20 -> V_15 ;
if ( V_20 -> V_22 )
return;
F_12 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( F_22 ( V_1 == V_18 ) )
goto V_29;
if ( ! F_23 ( V_15 ) )
F_7 ( V_1 , V_11 ) ;
else
F_6 ( V_1 ) ;
V_29:
F_13 () ;
}
void F_25 ( struct V_14 * V_15 , unsigned long V_23 ,
int V_24 )
{
unsigned long V_1 ;
unsigned long V_13 = F_16 ( V_24 ) ;
F_12 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( F_22 ( V_1 == V_18 ) )
goto V_30;
if ( ! F_23 ( V_15 ) )
F_10 ( V_23 , V_1 , V_13 , V_9 ) ;
else
F_8 ( V_23 , V_1 , V_13 , V_9 ) ;
V_30:
F_13 () ;
}
void F_26 ( struct V_25 * V_26 , unsigned long V_23 )
{
#ifdef F_18
if ( V_26 && F_19 ( V_26 ) )
return F_27 ( V_26 , V_23 ) ;
#endif
F_25 ( V_26 ? V_26 -> V_27 : NULL , V_23 ,
V_28 ) ;
}
void F_28 ( unsigned long V_31 , unsigned long V_32 )
{
F_7 ( 0 , V_8 ) ;
}
void F_29 ( struct V_25 * V_26 , unsigned long V_31 ,
unsigned long V_32 )
{
struct V_14 * V_15 = V_26 -> V_27 ;
F_21 ( V_15 ) ;
}
static int F_30 ( int V_33 )
{
int V_24 ;
if ( V_33 == ( 1UL << V_34 [ V_28 ] . V_35 ) )
V_24 = V_28 ;
else if ( V_33 == ( 1UL << V_34 [ V_36 ] . V_35 ) )
V_24 = V_36 ;
else if ( V_33 == ( 1UL << V_34 [ V_37 ] . V_35 ) )
V_24 = V_37 ;
else
return - 1 ;
return V_24 ;
}
void F_31 ( struct V_19 * V_20 )
{
int V_24 = 0 ;
struct V_14 * V_15 = V_20 -> V_15 ;
int V_33 = V_20 -> V_33 ;
V_24 = F_30 ( V_33 ) ;
if ( V_24 != - 1 && ! V_20 -> V_22 && ! V_20 -> V_38 )
F_32 ( V_15 , V_20 -> V_31 , V_20 -> V_32 , V_24 ) ;
else
F_21 ( V_15 ) ;
}
void F_32 ( struct V_14 * V_15 , unsigned long V_31 ,
unsigned long V_32 , int V_24 )
{
unsigned long V_1 ;
unsigned long V_21 ;
int V_39 = F_23 ( V_15 ) ;
unsigned long V_13 = F_16 ( V_24 ) ;
unsigned long V_33 = 1UL << V_34 [ V_24 ] . V_35 ;
F_12 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( F_22 ( V_1 == V_18 ) )
goto V_40;
if ( V_32 == V_41 ||
( V_32 - V_31 ) > V_42 * V_33 ) {
if ( V_39 )
F_5 ( V_1 , V_9 ) ;
else
F_7 ( V_1 , V_9 ) ;
goto V_40;
}
for ( V_21 = V_31 ; V_21 < V_32 ; V_21 += V_33 ) {
if ( V_39 )
F_8 ( V_21 , V_1 , V_13 , V_9 ) ;
else
F_10 ( V_21 , V_1 , V_13 , V_9 ) ;
}
V_40:
F_13 () ;
}
void F_33 ( unsigned long V_43 , unsigned long V_44 ,
unsigned long V_33 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_13 ;
unsigned long V_3 = V_9 ;
V_13 = F_16 ( F_30 ( V_33 ) ) ;
V_4 = V_44 & ~ ( F_9 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_43 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( V_43 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_34 ( unsigned long V_43 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_3 = V_8 ;
V_4 = 0x2 << F_3 ( 53 ) ;
V_5 = V_43 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
F_4 ( V_43 , 0 , V_4 , V_5 , V_3 , V_6 , V_7 ) ;
}
void F_35 ( struct V_25 * V_26 ,
unsigned long V_31 , unsigned long V_32 )
{
F_32 ( V_26 -> V_27 , V_31 , V_32 , V_36 ) ;
}
void F_36 ( void )
{
unsigned long V_4 , V_6 , V_7 , V_5 ;
unsigned long V_3 = V_8 ;
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
void F_37 ( unsigned long V_45 , struct V_14 * V_15 ,
unsigned long V_46 )
{
if ( ! F_38 ( V_47 ) ) {
F_39 ( 1 ) ;
return;
}
if ( V_45 & V_48 )
F_25 ( V_15 , V_46 , V_36 ) ;
else
F_25 ( V_15 , V_46 , V_28 ) ;
}
extern void F_40 ( struct V_14 * V_15 )
{
unsigned int V_1 = V_15 -> V_16 . V_17 ;
if ( F_22 ( V_1 == V_18 ) )
return;
if ( F_38 ( V_49 ) && F_41 () ) {
int V_50 = F_42 () ;
int V_51 = F_43 ( V_50 ) ;
bool V_52 = false ;
for (; V_51 <= F_44 ( V_50 ) && ! V_52 ; V_51 ++ ) {
if ( V_51 == V_50 )
continue;
if ( V_53 [ V_51 ] . V_54 . V_55 )
V_52 = true ;
}
if ( V_52 )
F_5 ( V_1 , V_8 ) ;
}
}
