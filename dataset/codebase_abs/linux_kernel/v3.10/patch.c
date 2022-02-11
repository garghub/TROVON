static T_1
F_1 ( T_1 V_1 )
{
T_1 * V_2 = ( T_1 * ) ( V_1 & - 16 ) ;
return ( ( V_2 [ 1 ] & 0x0800000000000000UL ) << 4 ) |
( ( V_2 [ 1 ] & 0x00000000007fffffUL ) << 40 ) |
( ( V_2 [ 0 ] & 0xffffc00000000000UL ) >> 24 ) |
( ( V_2 [ 1 ] & 0x0000100000000000UL ) >> 23 ) |
( ( V_2 [ 1 ] & 0x0003e00000000000UL ) >> 29 ) |
( ( V_2 [ 1 ] & 0x07fc000000000000UL ) >> 43 ) |
( ( V_2 [ 1 ] & 0x000007f000000000UL ) >> 36 ) ;
}
void
F_2 ( T_1 V_1 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , * V_11 = ( T_1 * ) ( V_1 & - 16 ) ;
# define F_3 ((1UL << 41) - 1)
unsigned long V_12 ;
V_9 = V_11 [ 0 ] ; V_10 = V_11 [ 1 ] ;
V_12 = 5 + 41 * ( V_1 % 16 ) ;
if ( V_12 >= 64 ) {
V_6 = V_3 << ( V_12 - 64 ) ;
V_8 = V_4 << ( V_12 - 64 ) ;
} else {
V_5 = V_3 << V_12 ; V_6 = V_3 >> ( 64 - V_12 ) ;
V_7 = V_4 << V_12 ; V_8 = V_4 >> ( 64 - V_12 ) ;
V_11 [ 0 ] = ( V_9 & ~ V_5 ) | ( V_7 & V_5 ) ;
}
V_11 [ 1 ] = ( V_10 & ~ V_6 ) | ( V_8 & V_6 ) ;
}
void
F_4 ( T_1 V_1 , T_1 V_4 )
{
V_1 &= - 16UL ;
F_2 ( V_1 + 2 ,
0x01fffefe000UL , ( ( ( V_4 & 0x8000000000000000UL ) >> 27 )
| ( ( V_4 & 0x0000000000200000UL ) << 0 )
| ( ( V_4 & 0x00000000001f0000UL ) << 6 )
| ( ( V_4 & 0x000000000000ff80UL ) << 20 )
| ( ( V_4 & 0x000000000000007fUL ) << 13 ) ) ) ;
F_2 ( V_1 + 1 , 0x1ffffffffffUL , V_4 >> 22 ) ;
}
void
F_5 ( T_1 V_1 , T_1 V_4 )
{
V_1 &= - 16UL ;
F_2 ( V_1 + 2 ,
0x011ffffe000UL , ( ( ( V_4 & 0x0800000000000000UL ) >> 23 )
| ( ( V_4 & 0x00000000000fffffUL ) << 13 ) ) ) ;
F_2 ( V_1 + 1 , 0x1fffffffffcUL , V_4 >> 18 ) ;
}
void T_2
F_6 ( unsigned long V_13 , unsigned long V_14 )
{
T_3 * V_15 = ( T_3 * ) V_13 ;
T_1 V_16 ;
while ( V_15 < ( T_3 * ) V_14 ) {
V_16 = ( T_1 ) V_15 + * V_15 ;
F_4 ( V_16 , F_7 ( F_1 ( V_16 ) ) ) ;
F_8 ( ( void * ) V_16 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
void T_2
F_11 ( unsigned long V_13 , unsigned long V_14 )
{
T_3 * V_15 = ( T_3 * ) V_13 ;
T_1 V_16 , * V_11 ;
while ( V_15 < ( T_3 * ) V_14 ) {
V_16 = ( T_1 ) V_15 + * V_15 ;
V_11 = ( T_1 * ) ( V_16 & - 16 ) ;
V_11 [ 1 ] &= ~ 0xf800000L ;
F_8 ( ( void * ) V_16 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
void T_2
F_12 ( unsigned long V_13 , unsigned long V_14 )
{
static int V_17 = 1 ;
int V_18 ;
T_3 * V_15 = ( T_3 * ) V_13 ;
T_1 * V_19 ;
V_18 = ( V_20 -> V_21 == 0x1f && V_20 -> V_22 == 0 ) ;
if ( V_17 ) {
V_17 = 0 ;
if ( V_18 )
F_13 ( V_23 L_1 ) ;
}
if ( V_18 )
return;
while ( V_15 < ( T_3 * ) V_14 ) {
V_19 = ( T_1 * ) F_14 ( ( char * ) V_15 + * V_15 ) ;
V_19 [ 0 ] = 0x0000000100000011UL ;
V_19 [ 1 ] = 0x0084006880000200UL ;
V_19 [ 2 ] = 0x0000000100000000UL ;
V_19 [ 3 ] = 0x0004000000000200UL ;
F_8 ( V_19 ) ; F_8 ( V_19 + 2 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
unsigned long * T_2
F_15 ( void )
{
return V_24 . V_25 ;
}
char * T_2
F_16 ( void )
{
return V_24 . V_26 ;
}
static void T_2
F_17 ( unsigned long V_13 , unsigned long V_14 )
{
T_1 V_25 = ( T_1 ) F_15 () ;
T_3 * V_15 = ( T_3 * ) V_13 ;
T_1 V_16 ;
while ( V_15 < ( T_3 * ) V_14 ) {
V_16 = ( T_1 ) F_14 ( ( char * ) V_15 + * V_15 ) ;
F_4 ( V_16 , V_25 ) ;
F_8 ( ( void * ) V_16 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
static void T_2
F_18 ( unsigned long V_13 , unsigned long V_14 )
{
T_1 V_26 = ( T_1 ) F_16 () ;
T_3 * V_15 = ( T_3 * ) V_13 ;
T_1 V_16 ;
while ( V_15 < ( T_3 * ) V_14 ) {
V_16 = ( T_1 ) V_15 + * V_15 ;
F_5 ( ( T_1 ) F_14 ( ( void * ) V_16 ) ,
( T_1 ) ( V_26 - ( V_16 & - 16 ) ) / 16 ) ;
F_8 ( ( void * ) V_16 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
void T_2
F_19 ( void )
{
# define F_20 ( T_4 ) paravirt_get_gate_patchlist(PV_GATE_START_##name)
# define F_21 ( T_4 ) paravirt_get_gate_patchlist(PV_GATE_END_##name)
F_17 ( F_20 ( V_27 ) , F_21 ( V_27 ) ) ;
F_18 ( F_20 ( V_28 ) , F_21 ( V_28 ) ) ;
F_6 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
F_12 ( F_20 ( V_30 ) , F_21 ( V_30 ) ) ;
}
void F_22 ( unsigned long V_4 )
{
T_3 * V_15 = ( T_3 * ) V_31 ;
T_3 * V_14 = ( T_3 * ) V_32 ;
T_1 V_16 , V_3 , V_33 ;
V_3 = ( 0x3fUL << 27 ) | ( 0x7f << 13 ) ;
V_33 = ( ( ( V_4 >> 7 ) & 0x3f ) << 27 ) | ( V_4 & 0x7f ) << 13 ;
while ( V_15 < V_14 ) {
V_16 = ( T_1 ) V_15 + * V_15 ;
F_2 ( V_16 , V_3 , V_33 ) ;
F_8 ( ( void * ) V_16 ) ;
++ V_15 ;
}
F_9 () ;
F_10 () ;
}
