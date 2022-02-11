static inline int F_1 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 ;
}
static inline int F_2 ( unsigned long V_4 , unsigned long V_5 )
{
int V_6 = 0 ;
F_3 ( V_7 , V_5 << 16 ) ;
if ( F_4 ( V_8 ) ) {
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
return V_6 ;
}
void F_5 ( struct V_9 * V_10 , unsigned long V_4 , T_1 V_11 )
{
unsigned long V_12 , V_13 ;
T_2 V_14 ;
unsigned long V_1 , V_15 , V_16 ;
unsigned long V_17 ;
#ifdef F_6
int V_18 , V_19 , V_20 ;
struct V_21 * V_22 ;
#endif
if ( F_7 ( F_8 ( V_4 ) ) )
return;
#ifdef F_9
V_1 = F_1 ( F_10 ( V_10 , V_4 ) ) ;
V_15 = F_11 ( V_1 ) ;
V_16 = V_2 [ V_1 ] . V_16 ;
#else
V_22 = F_12 ( V_10 , V_4 ) ;
V_1 = F_13 ( V_22 ) ;
asm (PPC_CNTLZL "%0,%1" : "=r" (lz) : "r" (psize));
V_16 = 31 - V_19 ;
V_15 = 21 - V_19 ;
#endif
F_14 ( V_17 ) ;
if ( F_7 ( F_2 ( V_4 , V_10 -> V_23 . V_24 ) ) ) {
F_15 ( V_17 ) ;
return;
}
#ifdef F_6
V_20 = F_16 ( V_25 ) & V_26 ;
V_18 = F_17 ( V_27 ) ;
F_3 ( V_28 , F_18 ( V_18 ) | F_19 ( 1 ) ) ;
if ( F_7 ( V_18 == V_20 - 1 ) )
F_17 ( V_27 ) = V_29 ;
else
F_17 ( V_27 ) ++ ;
#endif
V_12 = V_30 | F_20 ( V_10 -> V_23 . V_24 ) | F_21 ( V_15 ) ;
V_13 = V_4 & ~ ( ( 1UL << V_16 ) - 1 ) ;
V_13 |= ( F_22 ( V_11 ) >> V_31 ) & V_32 ;
V_14 = ( T_2 ) F_23 ( V_11 ) << V_33 ;
V_14 |= ( F_22 ( V_11 ) >> V_34 ) & V_35 ;
if ( ! F_24 ( V_11 ) )
V_14 &= ~ ( V_36 | V_37 ) ;
F_3 ( V_38 , V_12 ) ;
F_3 ( V_39 , V_13 ) ;
if ( F_4 ( V_40 ) ) {
F_3 ( V_41 , V_14 ) ;
} else {
F_3 ( V_42 , F_25 ( V_14 ) ) ;
F_3 ( V_43 , F_26 ( V_14 ) ) ;
}
asm volatile ("tlbwe");
F_15 ( V_17 ) ;
}
void F_27 ( struct V_21 * V_22 , unsigned long V_44 )
{
struct V_45 * V_45 = F_28 ( V_22 -> V_46 ) ;
unsigned long V_15 = F_29 ( V_45 ) - 10 ;
F_30 ( V_22 ? V_22 -> V_47 : NULL , V_44 , V_15 , 0 ) ;
}
