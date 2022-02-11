void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long long V_3 , V_4 = 0 , V_5 ;
unsigned long V_6 ;
V_5 = F_2 ( V_2 ) ;
V_3 = ( V_1 << V_7 ) | V_8 ;
V_3 |= V_5 ;
F_3 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if ( V_4 == V_3 ) {
F_4 ( V_6 ) ;
break;
}
}
F_5 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if ( V_4 == V_3 ) {
F_4 ( V_6 ) ;
break;
}
}
}
void F_6 ( struct V_9 * V_10 , unsigned long V_2 )
{
unsigned long V_11 ;
if ( V_10 -> V_12 ) {
V_2 &= V_13 ;
F_7 ( V_11 ) ;
F_1 ( F_8 () , V_2 ) ;
F_9 ( V_11 ) ;
}
}
void F_10 ( struct V_9 * V_10 , unsigned long V_14 ,
unsigned long V_15 )
{
unsigned long V_11 ;
unsigned long long V_3 , V_4 = 0 , V_16 , V_17 ;
unsigned long V_6 ;
unsigned int V_18 = F_11 () ;
struct V_19 * V_20 ;
V_20 = V_10 -> V_12 ;
if ( F_12 ( V_18 , V_20 ) == V_21 )
return;
F_7 ( V_11 ) ;
V_14 &= V_13 ;
V_15 &= V_13 ;
V_3 = ( F_13 ( V_18 , V_20 ) << V_7 ) | V_8 ;
F_3 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
V_16 = V_4 & V_13 ;
V_17 = V_4 & ~ V_13 ;
if ( V_17 == V_3 && V_16 >= V_14 && V_16 <= V_15 )
F_4 ( V_6 ) ;
}
F_5 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
V_16 = V_4 & V_13 ;
V_17 = V_4 & ~ V_13 ;
if ( V_17 == V_3 && V_16 >= V_14 && V_16 <= V_15 )
F_4 ( V_6 ) ;
}
F_9 ( V_11 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
unsigned long V_11 ;
unsigned int V_18 = F_11 () ;
if ( F_12 ( V_18 , V_20 ) == V_21 )
return;
F_7 ( V_11 ) ;
F_12 ( V_18 , V_20 ) = V_21 ;
if ( V_20 == V_22 -> V_20 )
F_15 ( V_20 , V_18 ) ;
F_9 ( V_11 ) ;
}
void F_16 ( void )
{
unsigned long V_11 , V_6 ;
F_7 ( V_11 ) ;
F_3 (tlb)
F_4 ( V_6 ) ;
F_5 (tlb)
F_4 ( V_6 ) ;
F_9 ( V_11 ) ;
}
void F_17 ( unsigned long V_14 , unsigned long V_15 )
{
F_18 () ;
}
void F_19 ( void )
{
F_18 () ;
}
