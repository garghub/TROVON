static inline unsigned short F_1 ( unsigned V_1 )
{
unsigned short V_2 = V_1 >> 16 ;
asm("addw %w2,%w0\n\t"
"adcw $0,%w0\n"
: "=r" (b)
: "0" (b), "r" (a));
return V_2 ;
}
static unsigned F_2 ( const unsigned char * V_3 , unsigned V_4 )
{
unsigned V_5 , V_6 ;
unsigned long V_7 = 0 ;
if ( F_3 ( V_4 == 0 ) )
return V_7 ;
V_5 = 1 & ( unsigned long ) V_3 ;
if ( F_3 ( V_5 ) ) {
V_7 = * V_3 << 8 ;
V_4 -- ;
V_3 ++ ;
}
V_6 = V_4 >> 1 ;
if ( V_6 ) {
if ( 2 & ( unsigned long ) V_3 ) {
V_7 += * ( unsigned short * ) V_3 ;
V_6 -- ;
V_4 -= 2 ;
V_3 += 2 ;
}
V_6 >>= 1 ;
if ( V_6 ) {
unsigned long V_8 ;
unsigned V_9 ;
if ( 4 & ( unsigned long ) V_3 ) {
V_7 += * ( unsigned int * ) V_3 ;
V_6 -- ;
V_4 -= 4 ;
V_3 += 4 ;
}
V_6 >>= 1 ;
V_8 = 0 ;
V_9 = V_6 >> 3 ;
while ( V_9 ) {
asm("addq 0*8(%[src]),%[res]\n\t"
"adcq 1*8(%[src]),%[res]\n\t"
"adcq 2*8(%[src]),%[res]\n\t"
"adcq 3*8(%[src]),%[res]\n\t"
"adcq 4*8(%[src]),%[res]\n\t"
"adcq 5*8(%[src]),%[res]\n\t"
"adcq 6*8(%[src]),%[res]\n\t"
"adcq 7*8(%[src]),%[res]\n\t"
"adcq %[zero],%[res]"
: [res] "=r" (result)
: [src] "r" (buff), [zero] "r" (zero),
"[res]" (result));
V_3 += 64 ;
V_9 -- ;
}
V_6 %= 8 ;
while ( V_6 ) {
asm("addq %1,%0\n\t"
"adcq %2,%0\n"
: "=r" (result)
: "m" (*(unsigned long *)buff),
"r" (zero), "0" (result));
-- V_6 ;
V_3 += 8 ;
}
V_7 = F_4 ( V_7 >> 32 ,
V_7 & 0xffffffff ) ;
if ( V_4 & 4 ) {
V_7 += * ( unsigned int * ) V_3 ;
V_3 += 4 ;
}
}
if ( V_4 & 2 ) {
V_7 += * ( unsigned short * ) V_3 ;
V_3 += 2 ;
}
}
if ( V_4 & 1 )
V_7 += * V_3 ;
V_7 = F_4 ( V_7 >> 32 , V_7 & 0xffffffff ) ;
if ( F_3 ( V_5 ) ) {
V_7 = F_1 ( V_7 ) ;
V_7 = ( ( V_7 >> 8 ) & 0xff ) | ( ( V_7 & 0xff ) << 8 ) ;
}
return V_7 ;
}
T_1 F_5 ( const void * V_3 , int V_4 , T_1 V_10 )
{
return ( V_11 T_1 ) F_4 ( F_2 ( V_3 , V_4 ) ,
( V_11 V_12 ) V_10 ) ;
}
T_2 F_6 ( const void * V_3 , int V_4 )
{
return F_7 ( F_5 ( V_3 , V_4 , 0 ) ) ;
}
