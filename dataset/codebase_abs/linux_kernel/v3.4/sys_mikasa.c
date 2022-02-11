static inline void
F_1 ( int V_1 )
{
F_2 ( V_1 , 0x536 ) ;
}
static inline void
F_3 ( struct V_2 * V_3 )
{
F_1 ( V_4 |= 1 << ( V_3 -> V_5 - 16 ) ) ;
}
static void
F_4 ( struct V_2 * V_3 )
{
F_1 ( V_4 &= ~ ( 1 << ( V_3 -> V_5 - 16 ) ) ) ;
}
static void
F_5 ( unsigned long V_6 )
{
unsigned long V_7 ;
unsigned int V_8 ;
V_7 = ( ( ( ~ F_6 ( 0x534 ) & 0x0000ffffUL ) << 16 )
| ( ( ( unsigned long ) F_7 ( 0xa0 ) ) << 8 )
| F_7 ( 0x20 ) ) ;
while ( V_7 ) {
V_8 = F_8 ( ~ V_7 ) ;
V_7 &= V_7 - 1 ;
if ( V_8 < 16 ) {
F_9 ( V_6 ) ;
} else {
F_10 ( V_8 ) ;
}
}
}
static void T_1
F_11 ( void )
{
long V_8 ;
if ( V_9 )
V_10 . V_11 = V_12 ;
F_1 ( 0 ) ;
for ( V_8 = 16 ; V_8 < 32 ; ++ V_8 ) {
F_12 ( V_8 , & V_13 ,
V_14 ) ;
F_13 ( V_8 , V_15 ) ;
}
F_14 () ;
F_15 () ;
}
static int T_1
F_16 ( const struct V_16 * V_17 , T_2 V_18 , T_2 V_19 )
{
static char V_20 [ 8 ] [ 5 ] V_21 = {
{ 16 + 12 , 16 + 12 , 16 + 12 , 16 + 12 , 16 + 12 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 0 , 16 + 0 , 16 + 1 , 16 + 2 , 16 + 3 } ,
{ 16 + 4 , 16 + 4 , 16 + 5 , 16 + 6 , 16 + 7 } ,
{ 16 + 8 , 16 + 8 , 16 + 9 , 16 + 10 , 16 + 11 } ,
} ;
const long V_22 = 6 , V_23 = 13 , V_24 = 5 ;
return V_25 ;
}
static void
F_17 ( unsigned long V_6 , unsigned long V_26 )
{
#define F_18 0x205U
#define F_19 0x204U
struct V_27 * V_28 ;
unsigned int V_29 ;
V_28 = (struct V_27 * ) V_26 ;
F_20 () ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 ( 0x7 ) ;
F_20 () ;
V_29 = V_28 -> V_29 ;
F_24 ( V_6 , V_26 , L_1 ,
( F_25 ( 0 )
&& ( V_29 == F_18
|| V_29 == F_19 ) ) ) ;
}
