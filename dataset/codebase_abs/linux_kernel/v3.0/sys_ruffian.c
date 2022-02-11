static void T_1
F_1 ( void )
{
* ( V_1 ) V_2 = 0x000000c0UL ; F_2 () ;
* ( V_1 ) V_3 = 0x00002064UL ; F_2 () ;
F_3 ( 0x11 , 0xA0 ) ;
F_3 ( 0x08 , 0xA1 ) ;
F_3 ( 0x02 , 0xA1 ) ;
F_3 ( 0x01 , 0xA1 ) ;
F_3 ( 0xFF , 0xA1 ) ;
F_3 ( 0x11 , 0x20 ) ;
F_3 ( 0x00 , 0x21 ) ;
F_3 ( 0x04 , 0x21 ) ;
F_3 ( 0x01 , 0x21 ) ;
F_3 ( 0xFF , 0x21 ) ;
F_3 ( 0x20 , 0xA0 ) ;
F_3 ( 0x20 , 0x20 ) ;
F_4 () ;
F_5 ( 0x16f0000 ) ;
F_6 () ;
}
static void T_1
F_7 ( void )
{
F_3 ( 0x34 , 0x43 ) ;
F_3 ( V_4 & 0xff , 0x40 ) ;
F_3 ( V_4 >> 8 , 0x40 ) ;
F_3 ( 0xb6 , 0x43 ) ;
F_3 ( 0x31 , 0x42 ) ;
F_3 ( 0x13 , 0x42 ) ;
F_8 ( 0 , & V_5 ) ;
}
static void
F_9 ( int V_6 )
{
F_10 ( V_6 ) ;
#if 0
*(vuip) PYXIS_RESET = 0x0000dead;
mb();
#endif
}
static int T_1
F_11 ( struct V_7 * V_8 , T_2 V_9 , T_2 V_10 )
{
static char V_11 [ 11 ] [ 5 ] V_12 = {
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 44 , 44 , 44 , 44 , 44 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 43 , 43 , 42 , 41 , 40 } ,
{ 19 , 19 , 18 , 17 , 16 } ,
{ 31 , 31 , 30 , 29 , 28 } ,
{ 27 , 27 , 26 , 25 , 24 } ,
{ 39 , 39 , 38 , 37 , 36 } ,
{ 35 , 35 , 34 , 33 , 32 } ,
{ 20 , 20 , 20 , 20 , 20 } ,
} ;
const long V_13 = 13 , V_14 = 23 , V_15 = 5 ;
return V_16 ;
}
static T_2 T_1
F_12 ( struct V_7 * V_8 , T_2 * V_17 )
{
int V_9 , V_10 = * V_17 ;
if ( V_8 -> V_18 -> V_19 == 0 ) {
V_9 = F_13 ( V_8 -> V_20 ) ;
}
else if ( F_13 ( V_8 -> V_18 -> V_21 -> V_20 ) == 13 ) {
V_9 = F_13 ( V_8 -> V_20 ) + 10 ;
}
else
{
do {
if ( F_13 ( V_8 -> V_18 -> V_21 -> V_20 ) == 13 ) {
V_9 = F_13 ( V_8 -> V_20 ) + 10 ;
break;
}
V_10 = F_14 ( V_8 , V_10 ) ;
V_8 = V_8 -> V_18 -> V_21 ;
V_9 = F_13 ( V_8 -> V_20 ) ;
} while ( V_8 -> V_18 -> V_21 );
}
* V_17 = V_10 ;
return V_9 ;
}
static unsigned long T_1
F_15 ( unsigned long V_22 )
{
unsigned long V_23 , V_24 , V_25 = 0 ;
V_23 = ( unsigned long ) V_26 + V_22 ;
V_24 = * ( V_1 ) V_23 ;
if ( V_24 & 0x01 ) {
static unsigned long V_27 [] V_12 = {
0x40000000UL ,
0x20000000UL ,
0x10000000UL ,
0x08000000UL ,
0x04000000UL ,
0x02000000UL ,
0x01000000UL ,
0x00800000UL ,
0x80000000UL ,
} ;
V_24 = ( V_24 & 0x1e ) >> 1 ;
if ( V_24 < F_16 ( V_27 ) )
V_25 = V_27 [ V_24 ] ;
}
return V_25 ;
}
