static inline unsigned short F_1 ( unsigned long V_1 )
{
V_1 = ( V_1 & 0xffff ) + ( V_1 >> 16 ) ;
V_1 = ( V_1 & 0xffff ) + ( V_1 >> 16 ) ;
return V_1 ;
}
static unsigned long F_2 ( const unsigned char * V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned long V_6 = 0 ;
if ( V_3 <= 0 )
goto V_7;
V_4 = 1 & ( unsigned long ) V_2 ;
if ( V_4 ) {
V_6 = * V_2 ;
V_3 -- ;
V_2 ++ ;
}
V_5 = V_3 >> 1 ;
if ( V_5 ) {
if ( 2 & ( unsigned long ) V_2 ) {
V_6 += * ( unsigned short * ) V_2 ;
V_5 -- ;
V_3 -= 2 ;
V_2 += 2 ;
}
V_5 >>= 1 ;
if ( V_5 ) {
unsigned long V_8 = 0 ;
do {
unsigned long V_9 = * ( unsigned long * ) V_2 ;
V_5 -- ;
V_2 += 4 ;
V_6 += V_8 ;
V_6 += V_9 ;
V_8 = ( V_9 > V_6 ) ;
} while ( V_5 );
V_6 += V_8 ;
V_6 = ( V_6 & 0xffff ) + ( V_6 >> 16 ) ;
}
if ( V_3 & 2 ) {
V_6 += * ( unsigned short * ) V_2 ;
V_2 += 2 ;
}
}
if ( V_3 & 1 )
V_6 += ( * V_2 << 8 ) ;
V_6 = F_1 ( V_6 ) ;
if ( V_4 )
V_6 = ( ( V_6 >> 8 ) & 0xff ) | ( ( V_6 & 0xff ) << 8 ) ;
V_7:
return V_6 ;
}
T_1 F_3 ( const void * V_10 , unsigned int V_11 )
{
return ( V_12 T_1 ) ~ F_2 ( V_10 , V_11 * 4 ) ;
}
T_2 F_4 ( const void * V_2 , int V_3 , T_2 V_13 )
{
unsigned int V_6 = F_2 ( V_2 , V_3 ) ;
V_6 += ( V_12 V_14 ) V_13 ;
if ( ( V_12 V_14 ) V_13 > V_6 )
V_6 += 1 ;
return ( V_12 T_2 ) V_6 ;
}
T_2
F_5 ( const void T_3 * V_15 , void * V_16 ,
int V_3 , T_2 V_13 , int * V_17 )
{
if ( V_17 ) * V_17 = 0 ;
memcpy ( V_16 , ( V_12 const void * ) V_15 , V_3 ) ;
return F_4 ( V_16 , V_3 , V_13 ) ;
}
T_2
F_6 ( const void * V_15 , void * V_16 , int V_3 , T_2 V_13 )
{
memcpy ( V_16 , V_15 , V_3 ) ;
return F_4 ( V_16 , V_3 , V_13 ) ;
}
