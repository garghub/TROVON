void F_1 ( struct V_1 * V_2 , unsigned long V_3 , T_1 V_4 )
{
unsigned long V_5 , V_6 , V_7 ;
if ( V_2 && V_8 -> V_9 != V_2 -> V_10 )
return;
F_2 ( V_5 ) ;
V_7 = ( V_3 & V_11 ) | F_3 () ;
F_4 ( V_7 , V_12 ) ;
V_6 = F_5 ( V_4 ) ;
V_6 &= V_13 ;
F_4 ( V_6 , V_14 ) ;
asm volatile("ldtlb": : : "memory");
F_6 ( V_5 ) ;
}
void F_7 ( unsigned long V_15 , unsigned long V_16 )
{
unsigned long V_17 , V_18 ;
int V_19 , V_20 = V_21 ;
V_17 = V_22 | ( V_16 & 0x1F000 ) ;
V_18 = ( V_16 & 0xfffe0000 ) | V_15 ;
if ( ( V_23 . V_5 & V_24 ) ) {
V_17 |= V_25 ;
V_20 = 1 ;
}
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_4 ( V_18 , V_17 + ( V_19 << 8 ) ) ;
}
void F_8 ( void )
{
unsigned long V_5 , V_26 ;
F_2 ( V_5 ) ;
V_26 = F_9 ( V_27 ) ;
V_26 |= 0x04 ;
F_4 ( V_26 , V_27 ) ;
F_10 () ;
F_6 ( V_5 ) ;
}
