unsigned long F_1 ( const unsigned long * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
const unsigned long * V_4 = V_1 + F_2 ( V_3 ) ;
unsigned long V_5 = V_3 & ~ ( V_6 - 1 ) ;
unsigned long V_7 ;
if ( V_3 >= V_2 )
return V_2 ;
V_2 -= V_5 ;
V_3 %= V_6 ;
if ( V_3 ) {
V_7 = * ( V_4 ++ ) ;
V_7 &= ( ~ 0UL << V_3 ) ;
if ( V_2 < V_6 )
goto V_8;
if ( V_7 )
goto V_9;
V_2 -= V_6 ;
V_5 += V_6 ;
}
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ( V_7 = * ( V_4 ++ ) ) )
goto V_9;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = * V_4 ;
V_8:
V_7 &= ( ~ 0UL >> ( V_6 - V_2 ) ) ;
if ( V_7 == 0UL )
return V_5 + V_2 ;
V_9:
return V_5 + F_3 ( V_7 ) ;
}
unsigned long F_4 ( const unsigned long * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
const unsigned long * V_4 = V_1 + F_2 ( V_3 ) ;
unsigned long V_5 = V_3 & ~ ( V_6 - 1 ) ;
unsigned long V_7 ;
if ( V_3 >= V_2 )
return V_2 ;
V_2 -= V_5 ;
V_3 %= V_6 ;
if ( V_3 ) {
V_7 = * ( V_4 ++ ) ;
V_7 |= ~ 0UL >> ( V_6 - V_3 ) ;
if ( V_2 < V_6 )
goto V_8;
if ( ~ V_7 )
goto V_9;
V_2 -= V_6 ;
V_5 += V_6 ;
}
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ~ ( V_7 = * ( V_4 ++ ) ) )
goto V_9;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = * V_4 ;
V_8:
V_7 |= ~ 0UL << V_2 ;
if ( V_7 == ~ 0UL )
return V_5 + V_2 ;
V_9:
return V_5 + F_5 ( V_7 ) ;
}
unsigned long F_6 ( const unsigned long * V_1 , unsigned long V_2 )
{
const unsigned long * V_4 = V_1 ;
unsigned long V_5 = 0 ;
unsigned long V_7 ;
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ( V_7 = * ( V_4 ++ ) ) )
goto V_10;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = ( * V_4 ) & ( ~ 0UL >> ( V_6 - V_2 ) ) ;
if ( V_7 == 0UL )
return V_5 + V_2 ;
V_10:
return V_5 + F_3 ( V_7 ) ;
}
unsigned long F_7 ( const unsigned long * V_1 , unsigned long V_2 )
{
const unsigned long * V_4 = V_1 ;
unsigned long V_5 = 0 ;
unsigned long V_7 ;
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ~ ( V_7 = * ( V_4 ++ ) ) )
goto V_10;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = ( * V_4 ) | ( ~ 0UL << V_2 ) ;
if ( V_7 == ~ 0UL )
return V_5 + V_2 ;
V_10:
return V_5 + F_5 ( V_7 ) ;
}
static inline unsigned long F_8 ( const unsigned long * V_11 )
{
#if V_6 == 64
return ( unsigned long ) F_9 ( ( V_12 * ) V_11 ) ;
#elif V_6 == 32
return ( unsigned long ) F_10 ( ( V_13 * ) V_11 ) ;
#else
#error BITS_PER_LONG not defined
#endif
}
static inline unsigned long F_11 ( const unsigned long V_14 )
{
#if V_6 == 64
return ( unsigned long ) F_12 ( ( V_12 ) V_14 ) ;
#elif V_6 == 32
return ( unsigned long ) F_13 ( ( V_13 ) V_14 ) ;
#else
#error BITS_PER_LONG not defined
#endif
}
unsigned long F_14 ( const void * V_1 , unsigned
long V_2 , unsigned long V_3 )
{
const unsigned long * V_4 = V_1 ;
unsigned long V_5 = V_3 & ~ ( V_6 - 1 ) ;
unsigned long V_7 ;
if ( V_3 >= V_2 )
return V_2 ;
V_4 += F_2 ( V_3 ) ;
V_2 -= V_5 ;
V_3 &= ( V_6 - 1UL ) ;
if ( V_3 ) {
V_7 = F_8 ( V_4 ++ ) ;
V_7 |= ( ~ 0UL >> ( V_6 - V_3 ) ) ;
if ( V_2 < V_6 )
goto V_8;
if ( ~ V_7 )
goto V_9;
V_2 -= V_6 ;
V_5 += V_6 ;
}
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ~ ( V_7 = * ( V_4 ++ ) ) )
goto V_15;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = F_8 ( V_4 ) ;
V_8:
V_7 |= ~ 0UL << V_2 ;
if ( V_7 == ~ 0UL )
return V_5 + V_2 ;
V_9:
return V_5 + F_5 ( V_7 ) ;
V_15:
return V_5 + F_5 ( F_11 ( V_7 ) ) ;
}
unsigned long F_15 ( const void * V_1 , unsigned
long V_2 , unsigned long V_3 )
{
const unsigned long * V_4 = V_1 ;
unsigned long V_5 = V_3 & ~ ( V_6 - 1 ) ;
unsigned long V_7 ;
if ( V_3 >= V_2 )
return V_2 ;
V_4 += F_2 ( V_3 ) ;
V_2 -= V_5 ;
V_3 &= ( V_6 - 1UL ) ;
if ( V_3 ) {
V_7 = F_8 ( V_4 ++ ) ;
V_7 &= ( ~ 0UL << V_3 ) ;
if ( V_2 < V_6 )
goto V_8;
if ( V_7 )
goto V_9;
V_2 -= V_6 ;
V_5 += V_6 ;
}
while ( V_2 & ~ ( V_6 - 1 ) ) {
V_7 = * ( V_4 ++ ) ;
if ( V_7 )
goto V_15;
V_5 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_5 ;
V_7 = F_8 ( V_4 ) ;
V_8:
V_7 &= ( ~ 0UL >> ( V_6 - V_2 ) ) ;
if ( V_7 == 0UL )
return V_5 + V_2 ;
V_9:
return V_5 + F_3 ( V_7 ) ;
V_15:
return V_5 + F_3 ( F_11 ( V_7 ) ) ;
}
