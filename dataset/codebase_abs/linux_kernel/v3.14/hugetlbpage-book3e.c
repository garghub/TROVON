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
F_4 ( V_15 ) = V_16 ;
else
F_4 ( V_15 ) ++ ;
return V_11 ;
}
static inline int F_6 ( int V_17 )
{
return V_18 [ V_17 ] . V_19 ;
}
static inline int F_7 ( unsigned long V_20 , unsigned long V_21 )
{
int V_22 = 0 ;
F_8 ( V_23 , V_21 << 16 ) ;
if ( F_9 ( V_24 ) ) {
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
return V_22 ;
}
void F_10 ( struct V_25 * V_26 , unsigned long V_20 ,
T_1 V_27 )
{
unsigned long V_28 , V_29 ;
T_2 V_30 ;
unsigned long V_17 , V_31 , V_32 ;
unsigned long V_33 ;
struct V_34 * V_35 ;
#ifdef F_11
int V_11 ;
#endif
if ( F_5 ( F_12 ( V_20 ) ) )
return;
V_35 = V_26 -> V_36 ;
#ifdef F_13
V_17 = F_14 ( V_35 , V_20 ) ;
V_31 = F_6 ( V_17 ) ;
V_32 = V_18 [ V_17 ] . V_32 ;
#else
V_17 = F_15 ( V_26 ) ;
V_32 = F_16 ( V_17 ) ;
V_31 = V_32 - 10 ;
#endif
F_17 ( V_33 ) ;
if ( F_5 ( F_7 ( V_20 , V_35 -> V_37 . V_38 ) ) ) {
F_18 ( V_33 ) ;
return;
}
#ifdef F_11
V_11 = F_1 () ;
F_8 ( V_39 , F_19 ( V_11 ) | F_20 ( 1 ) ) ;
#endif
V_28 = V_40 | F_21 ( V_35 -> V_37 . V_38 ) | F_22 ( V_31 ) ;
V_29 = V_20 & ~ ( ( 1UL << V_32 ) - 1 ) ;
V_29 |= ( F_23 ( V_27 ) >> V_41 ) & V_42 ;
V_30 = ( T_2 ) F_24 ( V_27 ) << V_43 ;
V_30 |= ( F_23 ( V_27 ) >> V_44 ) & V_45 ;
if ( ! F_25 ( V_27 ) )
V_30 &= ~ ( V_46 | V_47 ) ;
F_8 ( V_48 , V_28 ) ;
F_8 ( V_49 , V_29 ) ;
if ( F_9 ( V_50 ) ) {
F_8 ( V_51 , V_30 ) ;
} else {
if ( F_9 ( V_52 ) )
F_8 ( V_53 , F_26 ( V_30 ) ) ;
F_8 ( V_54 , F_27 ( V_30 ) ) ;
}
asm volatile ("tlbwe");
F_18 ( V_33 ) ;
}
void F_28 ( struct V_25 * V_26 , unsigned long V_55 )
{
struct V_56 * V_56 = F_29 ( V_26 -> V_57 ) ;
unsigned long V_31 = F_30 ( V_56 ) - 10 ;
F_31 ( V_26 -> V_36 , V_55 , V_31 , 0 ) ;
}
