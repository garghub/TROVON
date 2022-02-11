static unsigned long F_1 ( const unsigned long * V_1 ,
unsigned long V_2 , unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
if ( ! V_2 || V_3 >= V_2 )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
V_5 &= F_2 ( V_3 ) ;
V_3 = F_3 ( V_3 , V_6 ) ;
while ( ! V_5 ) {
V_3 += V_6 ;
if ( V_3 >= V_2 )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
}
return F_4 ( V_3 + F_5 ( V_5 ) , V_2 ) ;
}
unsigned long F_6 ( const unsigned long * V_1 , unsigned long V_7 ,
unsigned long V_8 )
{
return F_1 ( V_1 , V_7 , V_8 , 0UL ) ;
}
unsigned long F_7 ( const unsigned long * V_1 , unsigned long V_7 ,
unsigned long V_8 )
{
return F_1 ( V_1 , V_7 , V_8 , ~ 0UL ) ;
}
unsigned long F_8 ( const unsigned long * V_1 , unsigned long V_7 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 * V_6 < V_7 ; V_9 ++ ) {
if ( V_1 [ V_9 ] )
return F_4 ( V_9 * V_6 + F_5 ( V_1 [ V_9 ] ) , V_7 ) ;
}
return V_7 ;
}
unsigned long F_9 ( const unsigned long * V_1 , unsigned long V_7 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 * V_6 < V_7 ; V_9 ++ ) {
if ( V_1 [ V_9 ] != ~ 0UL )
return F_4 ( V_9 * V_6 + F_10 ( V_1 [ V_9 ] ) , V_7 ) ;
}
return V_7 ;
}
unsigned long F_11 ( const unsigned long * V_1 , unsigned long V_7 )
{
if ( V_7 ) {
unsigned long V_10 = F_12 ( V_7 ) ;
unsigned long V_9 = ( V_7 - 1 ) / V_6 ;
do {
V_10 &= V_1 [ V_9 ] ;
if ( V_10 )
return V_9 * V_6 + F_13 ( V_10 ) ;
V_10 = ~ 0ul ;
} while ( V_9 -- );
}
return V_7 ;
}
static inline unsigned long F_14 ( const unsigned long V_11 )
{
#if V_6 == 64
return ( unsigned long ) F_15 ( ( V_12 ) V_11 ) ;
#elif V_6 == 32
return ( unsigned long ) F_16 ( ( V_13 ) V_11 ) ;
#else
#error BITS_PER_LONG not defined
#endif
}
static unsigned long F_17 ( const unsigned long * V_1 ,
unsigned long V_2 , unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
if ( ! V_2 || V_3 >= V_2 )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
V_5 &= F_14 ( F_2 ( V_3 ) ) ;
V_3 = F_3 ( V_3 , V_6 ) ;
while ( ! V_5 ) {
V_3 += V_6 ;
if ( V_3 >= V_2 )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
}
return F_4 ( V_3 + F_5 ( F_14 ( V_5 ) ) , V_2 ) ;
}
unsigned long F_18 ( const void * V_1 , unsigned
long V_7 , unsigned long V_8 )
{
return F_17 ( V_1 , V_7 , V_8 , ~ 0UL ) ;
}
unsigned long F_19 ( const void * V_1 , unsigned
long V_7 , unsigned long V_8 )
{
return F_17 ( V_1 , V_7 , V_8 , 0UL ) ;
}
