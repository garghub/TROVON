void F_1 ( struct V_1 * V_2 , unsigned long V_3 , T_1 V_4 )
{
unsigned long V_5 , V_6 , V_7 ;
if ( V_2 && V_8 -> V_9 != V_2 -> V_10 )
return;
F_2 ( V_5 ) ;
V_7 = V_3 & V_11 ;
F_3 ( V_7 , V_12 ) ;
F_3 ( F_4 () , V_13 ) ;
V_6 = V_4 . V_14 ;
#ifdef F_5
F_3 ( V_4 . V_15 , V_16 ) ;
#endif
V_6 &= V_17 ;
#ifdef F_6
V_6 |= V_18 ;
#endif
F_3 ( V_6 , V_19 ) ;
asm volatile("ldtlb": : : "memory");
F_7 ( V_5 ) ;
}
void F_8 ( unsigned long V_20 , unsigned long V_21 )
{
F_9 () ;
F_3 ( V_21 , V_22 | V_23 ) ;
F_3 ( V_20 , V_24 | V_23 ) ;
F_3 ( V_21 , V_25 | V_23 ) ;
F_3 ( V_20 , V_26 | V_23 ) ;
F_10 () ;
}
void F_11 ( void )
{
unsigned long V_5 , V_27 ;
int V_28 ;
F_2 ( V_5 ) ;
F_9 () ;
V_27 = F_12 ( V_29 ) ;
V_27 = ( ( V_27 & V_30 ) >> V_31 ) ;
if ( V_27 == 0 )
V_27 = V_32 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_3 ( 0x0 , V_22 | ( V_28 << 8 ) ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
F_3 ( 0x0 , V_25 | ( V_28 << 8 ) ) ;
F_10 () ;
F_13 () ;
F_7 ( V_5 ) ;
}
