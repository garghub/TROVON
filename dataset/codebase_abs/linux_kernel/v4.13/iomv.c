void * F_1 ( unsigned long V_1 )
{
if ( ! F_2 () ) {
if ( F_3 ( V_1 ) )
return ( F_4 ( V_1 ) ) ;
if ( V_1 < ( 64 * 1024 ) )
return NULL ;
if ( F_5 () )
return ( F_4 ( V_1 ) ) ;
else
return ( ( void * ) ( V_1 | V_2 ) ) ;
} else {
unsigned long V_3 ;
V_3 = ( F_6 () ? 0xc00000028c000000UL : 0xc0000087cc000000UL ) | ( ( V_1 >> 2 ) << 12 ) ;
if ( ( V_1 >= 0x1f0 && V_1 <= 0x1f7 ) || V_1 == 0x3f6 || V_1 == 0x3f7 )
V_3 |= V_1 ;
return ( void * ) V_3 ;
}
}
void F_7 ( void )
{
volatile unsigned long * V_4 = V_5 -> V_6 ;
unsigned long V_7 = V_5 -> V_8 ;
while ( ( * V_4 & V_9 ) != V_7 )
F_8 () ;
}
