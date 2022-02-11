static inline void F_1 ( unsigned long V_1 , int V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = F_2 ( 53 ) ;
V_4 |= V_2 << F_3 ( 51 ) ;
V_5 = ( ( unsigned long ) V_1 ) << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void F_4 ( unsigned long V_1 , unsigned long V_3 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
F_1 ( V_1 , V_2 , V_3 ) ;
}
if ( F_5 ( V_9 ) )
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
return;
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
static inline void F_7 ( unsigned long V_10 , unsigned long V_1 ,
unsigned long V_11 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_10 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_11 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
if ( F_5 ( V_9 ) )
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
}
static inline void F_9 ( unsigned long V_10 , unsigned long V_1 ,
unsigned long V_11 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_10 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_11 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_10 ( struct V_12 * V_13 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_13 -> V_14 . V_15 ;
if ( V_1 != V_16 )
F_4 ( V_1 , V_17 ) ;
F_12 () ;
}
void F_13 ( struct V_18 * V_19 , unsigned long V_20 )
{
unsigned long V_1 ;
struct V_12 * V_13 = V_19 -> V_13 ;
F_11 () ;
V_1 = V_13 -> V_14 . V_15 ;
if ( V_1 != V_16 )
F_4 ( V_1 , V_21 ) ;
F_12 () ;
}
void F_14 ( struct V_12 * V_13 , unsigned long V_22 ,
int V_23 )
{
unsigned long V_1 ;
unsigned long V_11 = F_15 ( V_23 ) ;
F_11 () ;
V_1 = V_13 ? V_13 -> V_14 . V_15 : 0 ;
if ( V_1 != V_16 )
F_7 ( V_22 , V_1 , V_11 , V_24 ) ;
F_12 () ;
}
void F_16 ( struct V_25 * V_26 , unsigned long V_22 )
{
#ifdef F_17
if ( V_26 && F_18 ( V_26 ) )
return F_19 ( V_26 , V_22 ) ;
#endif
F_14 ( V_26 ? V_26 -> V_27 : NULL , V_22 ,
V_28 ) ;
}
void F_20 ( struct V_12 * V_13 )
{
unsigned long V_1 ;
F_11 () ;
V_1 = V_13 -> V_14 . V_15 ;
if ( F_21 ( V_1 == V_16 ) )
goto V_29;
if ( ! F_22 ( V_13 ) ) {
int V_30 = ! F_23 ( V_31 ) ;
if ( V_30 )
F_24 ( & V_32 ) ;
F_6 ( V_1 , V_17 ) ;
if ( V_30 )
F_25 ( & V_32 ) ;
} else
F_4 ( V_1 , V_17 ) ;
V_29:
F_12 () ;
}
void F_26 ( struct V_18 * V_19 , unsigned long V_20 )
{
unsigned long V_1 ;
struct V_12 * V_13 = V_19 -> V_13 ;
F_11 () ;
V_1 = V_13 -> V_14 . V_15 ;
if ( F_21 ( V_1 == V_16 ) )
goto V_29;
if ( ! F_22 ( V_13 ) ) {
int V_30 = ! F_23 ( V_31 ) ;
if ( V_30 )
F_24 ( & V_32 ) ;
F_6 ( V_1 , V_21 ) ;
if ( V_30 )
F_25 ( & V_32 ) ;
} else
F_4 ( V_1 , V_21 ) ;
V_29:
F_12 () ;
}
void F_27 ( struct V_12 * V_13 , unsigned long V_22 ,
int V_23 )
{
unsigned long V_1 ;
unsigned long V_11 = F_15 ( V_23 ) ;
F_11 () ;
V_1 = V_13 ? V_13 -> V_14 . V_15 : 0 ;
if ( F_21 ( V_1 == V_16 ) )
goto V_33;
if ( ! F_22 ( V_13 ) ) {
int V_30 = ! F_23 ( V_31 ) ;
if ( V_30 )
F_24 ( & V_32 ) ;
F_9 ( V_22 , V_1 , V_11 , V_24 ) ;
if ( V_30 )
F_25 ( & V_32 ) ;
} else
F_7 ( V_22 , V_1 , V_11 , V_24 ) ;
V_33:
F_12 () ;
}
void F_28 ( struct V_25 * V_26 , unsigned long V_22 )
{
#ifdef F_17
if ( V_26 && F_18 ( V_26 ) )
return F_29 ( V_26 , V_22 ) ;
#endif
F_27 ( V_26 ? V_26 -> V_27 : NULL , V_22 ,
V_28 ) ;
}
void F_30 ( unsigned long V_34 , unsigned long V_35 )
{
int V_30 = ! F_23 ( V_31 ) ;
if ( V_30 )
F_24 ( & V_32 ) ;
F_6 ( 0 , V_17 ) ;
if ( V_30 )
F_25 ( & V_32 ) ;
}
void F_31 ( struct V_25 * V_26 , unsigned long V_34 ,
unsigned long V_35 )
{
struct V_12 * V_13 = V_26 -> V_27 ;
F_20 ( V_13 ) ;
}
static int F_32 ( int V_36 )
{
int V_23 ;
if ( V_36 == ( 1UL << V_37 [ V_28 ] . V_38 ) )
V_23 = V_28 ;
else if ( V_36 == ( 1UL << V_37 [ V_39 ] . V_38 ) )
V_23 = V_39 ;
else if ( V_36 == ( 1UL << V_37 [ V_40 ] . V_38 ) )
V_23 = V_40 ;
else
return - 1 ;
return V_23 ;
}
void F_33 ( struct V_18 * V_19 )
{
int V_23 = 0 ;
struct V_12 * V_13 = V_19 -> V_13 ;
int V_36 = V_19 -> V_36 ;
V_23 = F_32 ( V_36 ) ;
if ( V_23 != - 1 && ! V_19 -> V_41 && ! V_19 -> V_42 )
F_34 ( V_13 , V_19 -> V_34 , V_19 -> V_35 , V_23 ) ;
else
F_20 ( V_13 ) ;
}
void F_34 ( struct V_12 * V_13 , unsigned long V_34 ,
unsigned long V_35 , int V_23 )
{
unsigned long V_1 ;
unsigned long V_20 ;
int V_43 = F_22 ( V_13 ) ;
unsigned long V_11 = F_15 ( V_23 ) ;
int V_30 = ! F_23 ( V_31 ) ;
unsigned long V_36 = 1UL << V_37 [ V_23 ] . V_38 ;
F_11 () ;
V_1 = V_13 ? V_13 -> V_14 . V_15 : 0 ;
if ( F_21 ( V_1 == V_16 ) )
goto V_44;
if ( V_35 == V_45 ||
( V_35 - V_34 ) > V_46 * V_36 ) {
if ( V_43 )
F_4 ( V_1 , V_24 ) ;
else
F_6 ( V_1 , V_24 ) ;
goto V_44;
}
for ( V_20 = V_34 ; V_20 < V_35 ; V_20 += V_36 ) {
if ( V_43 )
F_7 ( V_20 , V_1 , V_11 , V_24 ) ;
else {
if ( V_30 )
F_24 ( & V_32 ) ;
F_9 ( V_20 , V_1 , V_11 , V_24 ) ;
if ( V_30 )
F_25 ( & V_32 ) ;
}
}
V_44:
F_12 () ;
}
void F_35 ( unsigned long V_47 , unsigned long V_48 ,
unsigned long V_36 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_11 ;
unsigned long V_3 = V_24 ;
V_11 = F_15 ( F_32 ( V_36 ) ) ;
V_4 = V_48 & ~ ( F_8 ( 52 , 63 ) ) ;
V_4 |= V_11 << F_3 ( 58 ) ;
V_5 = V_47 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_36 ( unsigned long V_47 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_3 = V_17 ;
V_4 = 0x2 << F_3 ( 53 ) ;
V_5 = V_47 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_37 ( struct V_25 * V_26 ,
unsigned long V_34 , unsigned long V_35 )
{
F_34 ( V_26 -> V_27 , V_34 , V_35 , V_39 ) ;
}
void F_38 ( void )
{
unsigned long V_4 , V_6 , V_7 , V_5 ;
unsigned long V_3 = V_17 ;
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
