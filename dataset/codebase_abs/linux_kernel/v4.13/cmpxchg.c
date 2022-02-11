unsigned long F_1 ( volatile void * V_1 , unsigned long V_2 , unsigned int V_3 )
{
T_1 V_4 , V_5 , V_6 , V_7 ;
volatile T_1 * V_8 ;
unsigned int V_9 ;
F_2 ( ( unsigned long ) V_1 & ( V_3 - 1 ) ) ;
V_7 = F_3 ( ( V_3 * V_10 ) - 1 , 0 ) ;
V_2 &= V_7 ;
V_9 = ( unsigned long ) V_1 & 0x3 ;
if ( F_4 ( V_11 ) )
V_9 ^= sizeof( T_1 ) - V_3 ;
V_9 *= V_10 ;
V_7 <<= V_9 ;
V_8 = ( volatile T_1 * ) ( ( unsigned long ) V_1 & ~ 0x3 ) ;
V_6 = * V_8 ;
do {
V_4 = V_6 ;
V_5 = ( V_6 & ~ V_7 ) | ( V_2 << V_9 ) ;
V_6 = F_5 ( V_8 , V_4 , V_5 ) ;
} while ( V_6 != V_4 );
return ( V_6 & V_7 ) >> V_9 ;
}
unsigned long F_6 ( volatile void * V_1 , unsigned long V_12 ,
unsigned long V_13 , unsigned int V_3 )
{
T_1 V_7 , V_4 , V_5 , V_6 ;
volatile T_1 * V_8 ;
unsigned int V_9 ;
T_2 V_14 ;
F_2 ( ( unsigned long ) V_1 & ( V_3 - 1 ) ) ;
V_7 = F_3 ( ( V_3 * V_10 ) - 1 , 0 ) ;
V_12 &= V_7 ;
V_13 &= V_7 ;
V_9 = ( unsigned long ) V_1 & 0x3 ;
if ( F_4 ( V_11 ) )
V_9 ^= sizeof( T_1 ) - V_3 ;
V_9 *= V_10 ;
V_7 <<= V_9 ;
V_8 = ( volatile T_1 * ) ( ( unsigned long ) V_1 & ~ 0x3 ) ;
V_6 = * V_8 ;
while ( true ) {
V_14 = ( V_6 & V_7 ) >> V_9 ;
if ( V_14 != V_12 )
return V_14 ;
V_4 = ( V_6 & ~ V_7 ) | ( V_12 << V_9 ) ;
V_5 = ( V_6 & ~ V_7 ) | ( V_13 << V_9 ) ;
V_6 = F_5 ( V_8 , V_4 , V_5 ) ;
if ( V_6 == V_4 )
return V_12 ;
}
}
