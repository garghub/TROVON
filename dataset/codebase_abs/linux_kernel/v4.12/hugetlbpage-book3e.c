static inline int F_1 ( void )
{
struct V_1 * V_2 = F_2 () ;
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = V_2 -> V_7 ;
V_5 = V_4 -> V_8 ;
V_6 = V_5 + 1 ;
if ( V_6 >= V_4 -> V_9 )
V_6 = V_4 -> V_10 ;
V_4 -> V_8 = V_6 ;
return V_5 ;
}
static inline int F_1 ( void )
{
int V_11 , V_12 ;
V_12 = F_3 ( V_13 ) & V_14 ;
V_11 = F_4 ( V_15 ) ;
if ( F_5 ( V_11 == V_12 - 1 ) )
F_6 ( V_15 , V_16 ) ;
else
F_7 ( V_15 ) ;
return V_11 ;
}
static inline int F_8 ( int V_17 )
{
return V_18 [ V_17 ] . V_19 ;
}
static inline void F_9 ( void )
{
struct V_1 * V_2 = F_2 () ;
unsigned long V_20 ;
int V_21 = F_10 () + 1 ;
if ( ! F_11 ( V_22 ) )
return;
asm volatile("1: lbarx %0, 0, %1;"
"cmpwi %0, 0;"
"bne 2f;"
"stbcx. %2, 0, %1;"
"bne 1b;"
"b 3f;"
"2: lbzx %0, 0, %1;"
"cmpwi %0, 0;"
"bne 2b;"
"b 1b;"
"3:"
: "=&r" (tmp)
: "r" (&paca->tcd_ptr->lock), "r" (token)
: "memory");
}
static inline void F_12 ( void )
{
struct V_1 * V_2 = F_2 () ;
if ( ! F_11 ( V_22 ) )
return;
F_13 () ;
V_2 -> V_7 -> V_23 = 0 ;
}
static inline void F_9 ( void )
{
}
static inline void F_12 ( void )
{
}
static inline int F_14 ( unsigned long V_24 , unsigned long V_25 )
{
int V_26 = 0 ;
F_15 ( V_27 , V_25 << 16 ) ;
if ( F_16 ( V_28 ) ) {
asm volatile(
"li %0,0\n"
"tlbsx. 0,%1\n"
"bne 1f\n"
"li %0,1\n"
"1:\n"
: "=&r"(found) : "r"(ea));
} else {
asm volatile(
"tlbsx 0,%1\n"
"mfspr %0,0x271\n"
"srwi %0,%0,31\n"
: "=&r"(found) : "r"(ea));
}
return V_26 ;
}
void F_17 ( struct V_29 * V_30 , unsigned long V_24 ,
T_1 V_31 )
{
unsigned long V_32 , V_33 ;
T_2 V_34 ;
unsigned long V_17 , V_35 , V_36 ;
unsigned long V_37 ;
struct V_38 * V_39 ;
#ifdef F_18
int V_11 ;
#endif
if ( F_5 ( F_19 ( V_24 ) ) )
return;
V_39 = V_30 -> V_40 ;
V_17 = F_20 ( V_30 ) ;
V_36 = F_21 ( V_17 ) ;
V_35 = V_36 - 10 ;
F_22 ( V_37 ) ;
F_9 () ;
if ( F_5 ( F_14 ( V_24 , V_39 -> V_41 . V_42 ) ) ) {
F_12 () ;
F_23 ( V_37 ) ;
return;
}
#ifdef F_18
V_11 = F_1 () ;
F_15 ( V_43 , F_24 ( V_11 ) | F_25 ( 1 ) ) ;
#endif
V_32 = V_44 | F_26 ( V_39 -> V_41 . V_42 ) | F_27 ( V_35 ) ;
V_33 = V_24 & ~ ( ( 1UL << V_36 ) - 1 ) ;
V_33 |= ( F_28 ( V_31 ) >> V_45 ) & V_46 ;
V_34 = ( T_2 ) F_29 ( V_31 ) << V_47 ;
V_34 |= ( F_28 ( V_31 ) >> V_48 ) & V_49 ;
if ( ! F_30 ( V_31 ) )
V_34 &= ~ ( V_50 | V_51 ) ;
F_15 ( V_52 , V_32 ) ;
F_15 ( V_53 , V_33 ) ;
if ( F_16 ( V_54 ) ) {
F_15 ( V_55 , V_34 ) ;
} else {
if ( F_16 ( V_56 ) )
F_15 ( V_57 , F_31 ( V_34 ) ) ;
F_15 ( V_58 , F_32 ( V_34 ) ) ;
}
asm volatile ("tlbwe");
F_12 () ;
F_23 ( V_37 ) ;
}
void F_33 ( struct V_29 * V_30 , unsigned long V_59 )
{
struct V_60 * V_60 = F_34 ( V_30 -> V_61 ) ;
unsigned long V_35 = F_35 ( V_60 ) - 10 ;
F_36 ( V_30 -> V_40 , V_59 , V_35 , 0 ) ;
}
