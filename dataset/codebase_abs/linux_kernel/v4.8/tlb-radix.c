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
return;
}
static inline void F_5 ( unsigned long V_1 , unsigned long V_3 )
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
static inline void F_6 ( unsigned long V_9 , unsigned long V_1 ,
unsigned long V_10 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_9 & ~ ( F_7 ( 52 , 63 ) ) ;
V_4 |= V_10 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void F_8 ( unsigned long V_9 , unsigned long V_1 ,
unsigned long V_10 , unsigned long V_3 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
V_4 = V_9 & ~ ( F_7 ( 52 , 63 ) ) ;
V_4 |= V_10 << F_3 ( 58 ) ;
V_5 = V_1 << F_3 ( 31 ) ;
V_6 = 1 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_9 ( struct V_11 * V_12 )
{
unsigned long V_1 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( V_1 != V_15 )
F_4 ( V_1 , V_16 ) ;
F_11 () ;
}
void F_12 ( struct V_17 * V_18 , unsigned long V_19 )
{
unsigned long V_1 ;
struct V_11 * V_12 = V_18 -> V_12 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( V_1 != V_15 )
F_4 ( V_1 , V_20 ) ;
F_11 () ;
}
void F_13 ( struct V_11 * V_12 , unsigned long V_21 ,
int V_22 )
{
unsigned long V_1 ;
unsigned long V_10 = F_14 ( V_22 ) ;
F_10 () ;
V_1 = V_12 ? V_12 -> V_13 . V_14 : 0 ;
if ( V_1 != V_15 )
F_6 ( V_21 , V_1 , V_10 , V_23 ) ;
F_11 () ;
}
void F_15 ( struct V_24 * V_25 , unsigned long V_21 )
{
#ifdef F_16
if ( V_25 && F_17 ( V_25 ) )
return F_18 ( V_25 , V_21 ) ;
#endif
F_13 ( V_25 ? V_25 -> V_26 : NULL , V_21 ,
V_27 ) ;
}
void F_19 ( struct V_11 * V_12 )
{
unsigned long V_1 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( F_20 ( V_1 == V_15 ) )
goto V_28;
if ( ! F_21 ( V_12 ) ) {
int V_29 = ! F_22 ( V_30 ) ;
if ( V_29 )
F_23 ( & V_31 ) ;
F_5 ( V_1 , V_16 ) ;
if ( V_29 )
F_24 ( & V_31 ) ;
} else
F_4 ( V_1 , V_16 ) ;
V_28:
F_11 () ;
}
void F_25 ( struct V_17 * V_18 , unsigned long V_19 )
{
unsigned long V_1 ;
struct V_11 * V_12 = V_18 -> V_12 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( F_20 ( V_1 == V_15 ) )
goto V_28;
if ( ! F_21 ( V_12 ) ) {
int V_29 = ! F_22 ( V_30 ) ;
if ( V_29 )
F_23 ( & V_31 ) ;
F_5 ( V_1 , V_20 ) ;
if ( V_29 )
F_24 ( & V_31 ) ;
} else
F_4 ( V_1 , V_20 ) ;
V_28:
F_11 () ;
}
void F_26 ( struct V_11 * V_12 , unsigned long V_21 ,
int V_22 )
{
unsigned long V_1 ;
unsigned long V_10 = F_14 ( V_22 ) ;
F_10 () ;
V_1 = V_12 ? V_12 -> V_13 . V_14 : 0 ;
if ( F_20 ( V_1 == V_15 ) )
goto V_32;
if ( ! F_21 ( V_12 ) ) {
int V_29 = ! F_22 ( V_30 ) ;
if ( V_29 )
F_23 ( & V_31 ) ;
F_8 ( V_21 , V_1 , V_10 , V_23 ) ;
if ( V_29 )
F_24 ( & V_31 ) ;
} else
F_6 ( V_21 , V_1 , V_10 , V_23 ) ;
V_32:
F_11 () ;
}
void F_27 ( struct V_24 * V_25 , unsigned long V_21 )
{
#ifdef F_16
if ( V_25 && F_17 ( V_25 ) )
return F_28 ( V_25 , V_21 ) ;
#endif
F_26 ( V_25 ? V_25 -> V_26 : NULL , V_21 ,
V_27 ) ;
}
void F_29 ( unsigned long V_33 , unsigned long V_34 )
{
int V_29 = ! F_22 ( V_30 ) ;
if ( V_29 )
F_23 ( & V_31 ) ;
F_5 ( 0 , V_16 ) ;
if ( V_29 )
F_24 ( & V_31 ) ;
}
void F_30 ( struct V_24 * V_25 , unsigned long V_33 ,
unsigned long V_34 )
{
struct V_11 * V_12 = V_25 -> V_26 ;
F_19 ( V_12 ) ;
}
static int F_31 ( int V_35 )
{
int V_22 ;
if ( V_35 == ( 1UL << V_36 [ V_27 ] . V_37 ) )
V_22 = V_27 ;
else if ( V_35 == ( 1UL << V_36 [ V_38 ] . V_37 ) )
V_22 = V_38 ;
else if ( V_35 == ( 1UL << V_36 [ V_39 ] . V_37 ) )
V_22 = V_39 ;
else
return - 1 ;
return V_22 ;
}
void F_32 ( struct V_17 * V_18 )
{
int V_22 = 0 ;
struct V_11 * V_12 = V_18 -> V_12 ;
int V_35 = V_18 -> V_35 ;
V_22 = F_31 ( V_35 ) ;
if ( V_22 != - 1 && ! V_18 -> V_40 && ! V_18 -> V_41 )
F_33 ( V_12 , V_18 -> V_33 , V_18 -> V_34 , V_22 ) ;
else
F_19 ( V_12 ) ;
}
void F_33 ( struct V_11 * V_12 , unsigned long V_33 ,
unsigned long V_34 , int V_22 )
{
unsigned long V_1 ;
unsigned long V_19 ;
int V_42 = F_21 ( V_12 ) ;
unsigned long V_10 = F_14 ( V_22 ) ;
int V_29 = ! F_22 ( V_30 ) ;
unsigned long V_35 = 1UL << V_36 [ V_22 ] . V_37 ;
F_10 () ;
V_1 = V_12 ? V_12 -> V_13 . V_14 : 0 ;
if ( F_20 ( V_1 == V_15 ) )
goto V_43;
if ( V_34 == V_44 ||
( V_34 - V_33 ) > V_45 * V_35 ) {
if ( V_42 )
F_4 ( V_1 , V_23 ) ;
else
F_5 ( V_1 , V_23 ) ;
goto V_43;
}
for ( V_19 = V_33 ; V_19 < V_34 ; V_19 += V_35 ) {
if ( V_42 )
F_6 ( V_19 , V_1 , V_10 , V_23 ) ;
else {
if ( V_29 )
F_23 ( & V_31 ) ;
F_8 ( V_19 , V_1 , V_10 , V_23 ) ;
if ( V_29 )
F_24 ( & V_31 ) ;
}
}
V_43:
F_11 () ;
}
void F_34 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_35 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_10 ;
unsigned long V_3 = V_23 ;
V_10 = F_14 ( F_31 ( V_35 ) ) ;
V_4 = V_47 & ~ ( F_7 ( 52 , 63 ) ) ;
V_4 |= V_10 << F_3 ( 58 ) ;
V_5 = V_46 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_35 ( unsigned long V_46 )
{
unsigned long V_4 , V_5 , V_6 , V_7 ;
unsigned long V_3 = V_16 ;
V_4 = 0x2 << F_3 ( 53 ) ;
V_5 = V_46 & ( ( 1UL << 32 ) - 1 ) ;
V_6 = 0 ;
V_7 = 1 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void F_36 ( struct V_24 * V_25 ,
unsigned long V_33 , unsigned long V_34 )
{
F_33 ( V_25 -> V_26 , V_33 , V_34 , V_38 ) ;
}
