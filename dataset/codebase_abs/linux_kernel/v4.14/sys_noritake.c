static inline void
F_1 ( int V_1 , int V_2 )
{
int V_3 = 0x54a ;
if ( V_1 >= 32 ) {
V_2 >>= 16 ;
V_3 = 0x54c ;
}
F_2 ( V_2 , V_3 ) ;
}
static void
F_3 ( struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 , V_6 |= 1 << ( V_5 -> V_1 - 16 ) ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 , V_6 &= ~ ( 1 << ( V_5 -> V_1 - 16 ) ) ) ;
}
static void
F_5 ( unsigned long V_7 )
{
unsigned long V_8 ;
unsigned int V_9 ;
V_8 = ( ( ( unsigned long ) F_6 ( 0x54c ) << 32 )
| ( ( unsigned long ) F_6 ( 0x54a ) << 16 )
| ( ( unsigned long ) F_7 ( 0xa0 ) << 8 )
| F_7 ( 0x20 ) ) ;
while ( V_8 ) {
V_9 = F_8 ( ~ V_8 ) ;
V_8 &= V_8 - 1 ;
if ( V_9 < 16 ) {
F_9 ( V_7 ) ;
} else {
F_10 ( V_9 ) ;
}
}
}
static void
F_11 ( unsigned long V_7 )
{
int V_1 ;
V_1 = ( V_7 - 0x800 ) >> 4 ;
if ( V_1 >= 16 )
V_1 = V_1 + 1 ;
F_10 ( V_1 ) ;
}
static void T_1
F_12 ( void )
{
long V_9 ;
if ( V_10 )
V_11 . V_12 = F_11 ;
F_2 ( 0 , 0x54a ) ;
F_2 ( 0 , 0x54c ) ;
for ( V_9 = 16 ; V_9 < 48 ; ++ V_9 ) {
F_13 ( V_9 , & V_13 ,
V_14 ) ;
F_14 ( V_9 , V_15 ) ;
}
F_15 () ;
F_16 () ;
}
static int
F_17 ( const struct V_16 * V_17 , T_2 V_18 , T_2 V_19 )
{
static char V_20 [ 15 ] [ 5 ] = {
{ 16 + 1 , 16 + 1 , 16 + 1 , 16 + 1 , 16 + 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 2 , 16 + 2 , 16 + 3 , 32 + 2 , 32 + 3 } ,
{ 16 + 4 , 16 + 4 , 16 + 5 , 32 + 4 , 32 + 5 } ,
{ 16 + 6 , 16 + 6 , 16 + 7 , 32 + 6 , 32 + 7 } ,
{ 16 + 8 , 16 + 8 , 16 + 9 , 32 + 8 , 32 + 9 } ,
{ 16 + 1 , 16 + 1 , 16 + 1 , 16 + 1 , 16 + 1 } ,
{ 16 + 8 , 16 + 8 , 16 + 9 , 32 + 8 , 32 + 9 } ,
{ 16 + 10 , 16 + 10 , 16 + 11 , 32 + 10 , 32 + 11 } ,
{ 16 + 12 , 16 + 12 , 16 + 13 , 32 + 12 , 32 + 13 } ,
{ 16 + 14 , 16 + 14 , 16 + 15 , 32 + 14 , 32 + 15 } ,
} ;
const long V_21 = 5 , V_22 = 19 , V_23 = 5 ;
return V_24 ;
}
static T_2
F_18 ( struct V_16 * V_17 , T_2 * V_25 )
{
int V_18 , V_19 = * V_25 ;
if ( V_17 -> V_26 -> V_27 == 0 ) {
V_18 = F_19 ( V_17 -> V_28 ) ;
}
else if ( F_19 ( V_17 -> V_26 -> V_29 -> V_28 ) == 8 ) {
V_18 = F_19 ( V_17 -> V_28 ) + 15 ;
}
else
{
do {
if ( F_19 ( V_17 -> V_26 -> V_29 -> V_28 ) == 8 ) {
V_18 = F_19 ( V_17 -> V_28 ) + 15 ;
break;
}
V_19 = F_20 ( V_17 , V_19 ) ;
V_17 = V_17 -> V_26 -> V_29 ;
V_18 = F_19 ( V_17 -> V_28 ) ;
} while ( V_17 -> V_26 -> V_29 );
}
* V_25 = V_19 ;
return V_18 ;
}
static void
F_21 ( unsigned long V_7 , unsigned long V_30 )
{
#define F_22 0x205U
#define F_23 0x204U
struct V_31 * V_32 ;
unsigned int V_33 ;
V_32 = (struct V_31 * ) V_30 ;
F_24 () ;
F_24 () ;
F_25 () ;
F_26 () ;
F_27 ( 0x7 ) ;
F_24 () ;
V_33 = V_32 -> V_33 ;
F_28 ( V_7 , V_30 , L_1 ,
( F_29 ( 0 )
&& ( V_33 == F_22
|| V_33 == F_23 ) ) ) ;
}
