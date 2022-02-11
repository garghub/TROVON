static unsigned long
F_1 ( unsigned long V_1 , unsigned long V_2 , bool V_3 )
{
unsigned long V_4 , j1 , V_5 , V_6 , V_7 , V_8 , V_9 ;
unsigned long V_10 , V_11 ;
long V_12 ;
V_12 = ( long ) V_2 - ( long ) ( V_1 + 4 ) ;
if ( V_12 < - 16777216 || V_12 > 16777214 ) {
F_2 ( 1 ) ;
return 0 ;
}
V_4 = ( V_12 >> 24 ) & 0x1 ;
V_6 = ( V_12 >> 23 ) & 0x1 ;
V_7 = ( V_12 >> 22 ) & 0x1 ;
V_8 = ( V_12 >> 12 ) & 0x3ff ;
V_9 = ( V_12 >> 1 ) & 0x7ff ;
j1 = ( ! V_6 ) ^ V_4 ;
V_5 = ( ! V_7 ) ^ V_4 ;
V_10 = 0xf000 | ( V_4 << 10 ) | V_8 ;
V_11 = 0x9000 | ( j1 << 13 ) | ( V_5 << 11 ) | V_9 ;
if ( V_3 )
V_11 |= 1 << 14 ;
return F_3 ( V_10 , V_11 ) ;
}
static unsigned long
F_4 ( unsigned long V_1 , unsigned long V_2 , bool V_3 )
{
unsigned long V_13 = 0xea000000 ;
long V_12 ;
if ( V_3 )
V_13 |= 1 << 24 ;
V_12 = ( long ) V_2 - ( long ) ( V_1 + 8 ) ;
if ( F_5 ( V_12 < - 33554432 || V_12 > 33554428 ) ) {
F_2 ( 1 ) ;
return 0 ;
}
V_12 = ( V_12 >> 2 ) & 0x00ffffff ;
return V_13 | V_12 ;
}
unsigned long
F_6 ( unsigned long V_1 , unsigned long V_2 , bool V_3 )
{
if ( F_7 ( V_14 ) )
return F_1 ( V_1 , V_2 , V_3 ) ;
else
return F_4 ( V_1 , V_2 , V_3 ) ;
}
