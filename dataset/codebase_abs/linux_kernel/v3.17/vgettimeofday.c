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
int F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
T_1 V_12 ;
unsigned long V_13 , V_14 , V_15 ;
volatile struct V_16 * V_16 ;
V_16 = (struct V_16 * ) F_4 () ;
if ( F_3 ( V_11 != NULL ) ) {
while ( 1 ) {
V_13 = V_16 -> V_17 ;
if ( V_13 & 1 )
continue;
V_11 -> V_18 = V_16 -> V_18 ;
V_11 -> V_19 = V_16 -> V_19 ;
if ( V_13 == V_16 -> V_17 )
break;
}
}
if ( F_3 ( V_9 == NULL ) )
return 0 ;
while ( 1 ) {
V_13 = V_16 -> V_20 ;
if ( V_13 & 1 )
continue;
V_14 = V_16 -> V_21 ;
V_12 = F_6 () - V_16 -> V_22 ;
V_15 = ( V_12 * V_16 -> V_23 ) + V_16 -> V_24 ;
V_15 >>= V_16 -> V_25 ;
if ( V_15 >= V_26 ) {
V_15 -= V_26 ;
V_14 += 1 ;
}
if ( V_13 == V_16 -> V_20 )
break;
}
V_9 -> V_27 = V_14 ;
V_9 -> V_28 = V_15 / 1000 ;
return 0 ;
}
