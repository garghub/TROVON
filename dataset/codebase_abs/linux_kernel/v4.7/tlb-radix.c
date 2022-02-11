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
asm volatile(".long 0x7c000224 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
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
asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
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
asm volatile(".long 0x7c000224 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
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
asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
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
unsigned long V_10 , int V_22 )
{
unsigned long V_1 ;
F_10 () ;
V_1 = V_12 ? V_12 -> V_13 . V_14 : 0 ;
if ( V_1 != V_15 )
F_6 ( V_21 , V_1 , V_10 , V_23 ) ;
F_11 () ;
}
void F_14 ( struct V_24 * V_25 , unsigned long V_21 )
{
#ifdef F_15
if ( V_25 && F_16 ( V_25 ) )
return F_17 ( V_25 , V_21 ) ;
#endif
F_13 ( V_25 ? V_25 -> V_26 : NULL , V_21 ,
F_18 ( V_27 ) , 0 ) ;
}
static int F_19 ( struct V_11 * V_12 )
{
return F_20 ( F_21 ( V_12 ) ,
F_22 ( F_23 () ) ) ;
}
void F_24 ( struct V_11 * V_12 )
{
unsigned long V_1 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( F_25 ( V_1 == V_15 ) )
goto V_28;
if ( ! F_19 ( V_12 ) ) {
int V_29 = ! F_26 ( V_30 ) ;
if ( V_29 )
F_27 ( & V_31 ) ;
F_5 ( V_1 , V_16 ) ;
if ( V_29 )
F_28 ( & V_31 ) ;
} else
F_4 ( V_1 , V_16 ) ;
V_28:
F_11 () ;
}
void F_29 ( struct V_17 * V_18 , unsigned long V_19 )
{
unsigned long V_1 ;
struct V_11 * V_12 = V_18 -> V_12 ;
F_10 () ;
V_1 = V_12 -> V_13 . V_14 ;
if ( F_25 ( V_1 == V_15 ) )
goto V_28;
if ( ! F_19 ( V_12 ) ) {
int V_29 = ! F_26 ( V_30 ) ;
if ( V_29 )
F_27 ( & V_31 ) ;
F_5 ( V_1 , V_20 ) ;
if ( V_29 )
F_28 ( & V_31 ) ;
} else
F_4 ( V_1 , V_20 ) ;
V_28:
F_11 () ;
}
void F_30 ( struct V_11 * V_12 , unsigned long V_21 ,
unsigned long V_10 , int V_22 )
{
unsigned long V_1 ;
F_10 () ;
V_1 = V_12 ? V_12 -> V_13 . V_14 : 0 ;
if ( F_25 ( V_1 == V_15 ) )
goto V_32;
if ( ! F_19 ( V_12 ) ) {
int V_29 = ! F_26 ( V_30 ) ;
if ( V_29 )
F_27 ( & V_31 ) ;
F_8 ( V_21 , V_1 , V_10 , V_23 ) ;
if ( V_29 )
F_28 ( & V_31 ) ;
} else
F_6 ( V_21 , V_1 , V_10 , V_23 ) ;
V_32:
F_11 () ;
}
void F_31 ( struct V_24 * V_25 , unsigned long V_21 )
{
#ifdef F_15
if ( V_25 && F_16 ( V_25 ) )
return F_32 ( V_25 , V_21 ) ;
#endif
F_30 ( V_25 ? V_25 -> V_26 : NULL , V_21 ,
F_18 ( V_27 ) , 0 ) ;
}
void F_33 ( unsigned long V_33 , unsigned long V_34 )
{
int V_29 = ! F_26 ( V_30 ) ;
if ( V_29 )
F_27 ( & V_31 ) ;
F_5 ( 0 , V_16 ) ;
if ( V_29 )
F_28 ( & V_31 ) ;
}
void F_34 ( struct V_24 * V_25 , unsigned long V_33 ,
unsigned long V_34 )
{
struct V_11 * V_12 = V_25 -> V_26 ;
F_24 ( V_12 ) ;
}
void F_35 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = V_18 -> V_12 ;
F_24 ( V_12 ) ;
}
