void T_1 * F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
void T_1 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 , V_8 ;
T_2 V_9 ;
#ifdef F_2
unsigned long V_10 = V_1 + V_2 - 1 ;
if ( ( V_1 >= 0x00080000 && V_10 < 0x000fffff ) ||
( V_1 >= 0x00500000 && V_10 < 0x03bfffff ) ) {
V_1 |= F_3 ( 0xfc000000 ) ;
V_3 |= V_11 ;
}
#endif
V_8 = V_1 + V_2 - 1 ;
if ( ! V_2 || V_8 < V_1 )
return NULL ;
if ( V_1 < F_4 ( V_12 ) ) {
char * V_13 , * V_14 ;
struct V_15 * V_15 ;
V_13 = F_5 ( V_1 ) ;
V_14 = V_13 + ( V_2 - 1 ) ;
for ( V_15 = F_6 ( V_13 ) ;
V_15 <= F_6 ( V_14 ) ; V_15 ++ ) {
if( ! F_7 ( V_15 ) )
return NULL ;
}
}
V_9 = F_8 ( V_16 | V_17 | V_18 |
V_19 | V_3 ) ;
V_7 = V_1 & ~ V_20 ;
V_1 &= V_20 ;
V_2 = F_9 ( V_8 + 1 ) - V_1 ;
V_6 = F_10 ( V_2 , V_21 ) ;
if ( ! V_6 )
return NULL ;
V_4 = ( void T_1 * ) V_6 -> V_4 ;
if ( F_11 ( ( unsigned long ) V_4 , ( unsigned long ) V_4 + V_2 ,
V_1 , V_9 ) ) {
F_12 ( V_4 ) ;
return NULL ;
}
return ( void T_1 * ) ( V_7 + ( char T_1 * ) V_4 ) ;
}
void F_13 ( const volatile void T_1 * V_4 )
{
if ( V_4 > V_12 )
return F_12 ( ( void * ) ( V_20 & ( unsigned long V_22 ) V_4 ) ) ;
}
