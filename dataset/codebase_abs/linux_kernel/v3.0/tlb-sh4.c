void F_1 ( struct V_1 * V_2 , unsigned long V_3 , T_1 V_4 )
{
unsigned long V_5 , V_6 , V_7 ;
if ( V_2 && V_8 -> V_9 != V_2 -> V_10 )
return;
F_2 ( V_5 ) ;
V_7 = ( V_3 & V_11 ) | F_3 () ;
F_4 ( V_7 , V_12 ) ;
V_6 = V_4 . V_13 ;
#ifdef F_5
F_4 ( V_4 . V_14 , V_15 ) ;
#else
if ( V_16 -> V_5 & V_17 ) {
F_4 ( F_6 ( V_6 ) , V_15 ) ;
}
#endif
V_6 &= V_18 ;
#ifdef F_7
V_6 |= V_19 ;
#endif
F_4 ( V_6 , V_20 ) ;
asm volatile("ldtlb": : : "memory");
F_8 ( V_5 ) ;
}
void F_9 ( unsigned long V_21 , unsigned long V_22 )
{
unsigned long V_23 , V_24 ;
V_23 = V_25 | V_26 ;
V_24 = V_22 | V_21 ;
F_10 () ;
F_4 ( V_24 , V_23 ) ;
F_11 () ;
}
void F_12 ( void )
{
unsigned long V_5 , V_27 ;
int V_28 ;
F_2 ( V_5 ) ;
F_10 () ;
V_27 = F_13 ( V_29 ) ;
V_27 = ( ( V_27 & V_30 ) >> V_31 ) ;
if ( V_27 == 0 )
V_27 = V_32 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_4 ( 0x0 , V_25 | ( V_28 << 8 ) ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
F_4 ( 0x0 , V_33 | ( V_28 << 8 ) ) ;
F_11 () ;
F_14 () ;
F_8 ( V_5 ) ;
}
