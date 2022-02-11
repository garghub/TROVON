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
}
static inline void F_4 ( unsigned long V_1 , unsigned long V_3 )
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
static inline void F_5 ( unsigned long V_1 )
{
asm volatile("ptesync": : :"memory");
F_1 ( V_1 , 0 , V_11 ) ;
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
}
static inline void F_7 ( unsigned long V_12 , unsigned long V_1 ,
unsigned long V_13 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_12 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void F_9 ( unsigned long V_12 , unsigned long V_1 ,
unsigned long V_13 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_12 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_10 ( struct V_14 * V_15 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( V_1 != V_18 )
F_4 ( V_1 , V_8 ) ;
F_12 () ;
}
void F_13 ( struct V_19 * V_20 , unsigned long V_21 )
{
unsigned long V_1 ;
struct V_14 * V_15 = V_20 -> V_15 ;
if ( V_20 -> V_22 )
return;
F_11 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( V_1 != V_18 )
F_5 ( V_1 ) ;
F_12 () ;
}
void F_14 ( struct V_14 * V_15 , unsigned long V_23 ,
int V_24 )
{
unsigned long V_1 ;
unsigned long V_13 = F_15 ( V_24 ) ;
F_11 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( V_1 != V_18 )
F_7 ( V_23 , V_1 , V_13 , V_9 ) ;
F_12 () ;
}
void F_16 ( struct V_25 * V_26 , unsigned long V_23 )
{
#ifdef F_17
if ( V_26 && F_18 ( V_26 ) )
return F_19 ( V_26 , V_23 ) ;
#endif
F_14 ( V_26 ? V_26 -> V_27 : NULL , V_23 ,
V_28 ) ;
}
void F_20 ( struct V_14 * V_15 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( F_21 ( V_1 == V_18 ) )
goto V_29;
if ( ! F_22 ( V_15 ) )
F_6 ( V_1 , V_8 ) ;
else
F_4 ( V_1 , V_8 ) ;
V_29:
F_12 () ;
}
void F_23 ( struct V_19 * V_20 , unsigned long V_21 )
{
unsigned long V_1 ;
struct V_14 * V_15 = V_20 -> V_15 ;
if ( V_20 -> V_22 )
return;
F_11 () ;
V_1 = V_15 -> V_16 . V_17 ;
if ( F_21 ( V_1 == V_18 ) )
goto V_29;
if ( ! F_22 ( V_15 ) )
F_6 ( V_1 , V_11 ) ;
else
F_5 ( V_1 ) ;
V_29:
F_12 () ;
}
void F_24 ( struct V_14 * V_15 , unsigned long V_23 ,
int V_24 )
{
unsigned long V_1 ;
unsigned long V_13 = F_15 ( V_24 ) ;
F_11 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( F_21 ( V_1 == V_18 ) )
goto V_30;
if ( ! F_22 ( V_15 ) )
F_9 ( V_23 , V_1 , V_13 , V_9 ) ;
else
F_7 ( V_23 , V_1 , V_13 , V_9 ) ;
V_30:
F_12 () ;
}
void F_25 ( struct V_25 * V_26 , unsigned long V_23 )
{
#ifdef F_17
if ( V_26 && F_18 ( V_26 ) )
return F_26 ( V_26 , V_23 ) ;
#endif
F_24 ( V_26 ? V_26 -> V_27 : NULL , V_23 ,
V_28 ) ;
}
void F_27 ( unsigned long V_31 , unsigned long V_32 )
{
F_6 ( 0 , V_8 ) ;
}
void F_28 ( struct V_25 * V_26 , unsigned long V_31 ,
unsigned long V_32 )
{
struct V_14 * V_15 = V_26 -> V_27 ;
F_20 ( V_15 ) ;
}
static int F_29 ( int V_33 )
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
void F_30 ( struct V_19 * V_20 )
{
int V_24 = 0 ;
struct V_14 * V_15 = V_20 -> V_15 ;
int V_33 = V_20 -> V_33 ;
V_24 = F_29 ( V_33 ) ;
if ( V_24 != - 1 && ! V_20 -> V_22 && ! V_20 -> V_38 )
F_31 ( V_15 , V_20 -> V_31 , V_20 -> V_32 , V_24 ) ;
else
F_20 ( V_15 ) ;
}
void F_31 ( struct V_14 * V_15 , unsigned long V_31 ,
unsigned long V_32 , int V_24 )
{
unsigned long V_1 ;
unsigned long V_21 ;
int V_39 = F_22 ( V_15 ) ;
unsigned long V_13 = F_15 ( V_24 ) ;
unsigned long V_33 = 1UL << V_34 [ V_24 ] . V_35 ;
F_11 () ;
V_1 = V_15 ? V_15 -> V_16 . V_17 : 0 ;
if ( F_21 ( V_1 == V_18 ) )
goto V_40;
if ( V_32 == V_41 ||
( V_32 - V_31 ) > V_42 * V_33 ) {
if ( V_39 )
F_4 ( V_1 , V_9 ) ;
else
F_6 ( V_1 , V_9 ) ;
goto V_40;
}
for ( V_21 = V_31 ; V_21 < V_32 ; V_21 += V_33 ) {
if ( V_39 )
F_7 ( V_21 , V_1 , V_13 , V_9 ) ;
else
F_9 ( V_21 , V_1 , V_13 , V_9 ) ;
}
V_40:
F_12 () ;
}
void F_32 ( unsigned long V_43 , unsigned long V_44 ,
unsigned long V_33 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_13 ;
unsigned long V_3 = V_9 ;
V_13 = F_15 ( F_29 ( V_33 ) ) ;
V_4 = V_44 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_13 << F_3 ( 58 ) ;
V_5 = V_43 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_33 ( unsigned long V_43 )
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
}
void F_34 ( struct V_25 * V_26 ,
unsigned long V_31 , unsigned long V_32 )
{
F_31 ( V_26 -> V_27 , V_31 , V_32 , V_36 ) ;
}
void F_35 ( void )
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
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_36 ( unsigned long V_45 , struct V_14 * V_15 ,
unsigned long V_46 )
{
if ( ! F_37 ( V_47 ) ) {
F_38 ( 1 ) ;
return;
}
if ( V_45 & V_48 )
F_24 ( V_15 , V_46 , V_36 ) ;
else
F_24 ( V_15 , V_46 , V_28 ) ;
}
