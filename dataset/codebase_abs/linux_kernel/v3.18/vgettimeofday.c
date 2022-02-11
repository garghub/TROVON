static inline T_1 F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
unsigned int V_3 = F_2 ( V_4 ) ;
unsigned int V_5 = F_2 ( V_2 ) ;
while ( F_3 ( V_1 != V_5 ) ) {
V_3 = F_2 ( V_4 ) ;
V_1 = V_5 ;
V_5 = F_2 ( V_2 ) ;
}
return ( ( ( T_1 ) V_1 ) << 32 ) | V_3 ;
}
inline unsigned long F_4 ( void )
{
unsigned long V_6 ;
asm volatile ("lnk %0" : "=r"(ret));
V_6 &= ~ ( V_7 - 1 ) ;
V_6 += V_7 ;
return V_6 ;
}
static inline T_2 F_5 ( struct V_8 * V_9 )
{
return ( ( F_6 () - V_9 -> V_10 ) & V_9 -> V_11 ) * V_9 -> V_12 ;
}
static inline int F_7 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
unsigned V_15 ;
T_2 V_16 ;
do {
V_15 = F_8 ( & V_9 -> V_17 ) ;
V_14 -> V_18 = V_9 -> V_19 ;
V_16 = V_9 -> V_20 ;
V_16 += F_5 ( V_9 ) ;
V_16 >>= V_9 -> V_21 ;
} while ( F_3 ( F_9 ( & V_9 -> V_17 , V_15 ) ) );
V_14 -> V_18 += F_10 ( V_16 , V_22 , & V_16 ) ;
V_14 -> V_23 = V_16 ;
return 0 ;
}
static inline int F_11 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
unsigned V_15 ;
T_2 V_16 ;
do {
V_15 = F_8 ( & V_9 -> V_17 ) ;
V_14 -> V_18 = V_9 -> V_24 ;
V_16 = V_9 -> V_25 ;
V_16 += F_5 ( V_9 ) ;
V_16 >>= V_9 -> V_21 ;
} while ( F_3 ( F_9 ( & V_9 -> V_17 , V_15 ) ) );
V_14 -> V_18 += F_10 ( V_16 , V_22 , & V_16 ) ;
V_14 -> V_23 = V_16 ;
return 0 ;
}
static inline int F_12 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
unsigned V_15 ;
do {
V_15 = F_8 ( & V_9 -> V_17 ) ;
V_14 -> V_18 = V_9 -> V_26 ;
V_14 -> V_23 = V_9 -> V_27 ;
} while ( F_3 ( F_9 ( & V_9 -> V_17 , V_15 ) ) );
return 0 ;
}
static inline int F_13 ( struct V_8 * V_9 ,
struct V_13 * V_14 )
{
unsigned V_15 ;
do {
V_15 = F_8 ( & V_9 -> V_17 ) ;
V_14 -> V_18 = V_9 -> V_28 ;
V_14 -> V_23 = V_9 -> V_29 ;
} while ( F_3 ( F_9 ( & V_9 -> V_17 , V_15 ) ) );
return 0 ;
}
struct V_30 F_14 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_30 V_6 = { 0 , 0 } ;
unsigned V_15 ;
struct V_8 * V_9 = (struct V_8 * ) F_4 () ;
if ( F_3 ( V_34 != NULL ) ) {
do {
V_15 = F_8 ( & V_9 -> V_35 ) ;
V_34 -> V_36 = V_9 -> V_36 ;
V_34 -> V_37 = V_9 -> V_37 ;
} while ( F_3 ( F_9 ( & V_9 -> V_35 , V_15 ) ) );
}
if ( F_3 ( V_32 == NULL ) )
return V_6 ;
F_7 ( V_9 , (struct V_13 * ) V_32 ) ;
V_32 -> V_38 /= 1000 ;
return V_6 ;
}
static struct V_30 F_15 ( long clock ,
struct V_13 * V_14 )
{
struct V_30 V_6 ;
__asm__ __volatile__ (
"swint1"
: "=R00" (ret.value), "=R01" (ret.error)
: "R10" (__NR_clock_gettime), "R00" (clock), "R01" (ts)
: "r2", "r3", "r4", "r5", "r6", "r7",
"r8", "r9", "r11", "r12", "r13", "r14", "r15",
"r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",
"r24", "r25", "r26", "r27", "r28", "r29", "memory");
return V_6 ;
}
struct V_30 F_16 ( T_3 clock ,
struct V_13 * V_14 )
{
struct V_8 * V_9 = (struct V_8 * ) F_4 () ;
struct V_30 V_6 = { 0 , 0 } ;
switch ( clock ) {
case V_39 :
F_7 ( V_9 , V_14 ) ;
return V_6 ;
case V_40 :
F_11 ( V_9 , V_14 ) ;
return V_6 ;
case V_41 :
F_12 ( V_9 , V_14 ) ;
return V_6 ;
case V_42 :
F_13 ( V_9 , V_14 ) ;
return V_6 ;
default:
return F_15 ( clock , V_14 ) ;
}
}
