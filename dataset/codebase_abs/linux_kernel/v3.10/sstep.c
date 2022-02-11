static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
#ifdef F_2
if ( ( V_1 & V_3 ) == 0 )
V_2 &= 0xffffffffUL ;
#endif
return V_2 ;
}
static int T_1 F_3 ( unsigned int V_4 , struct V_5 * V_6 )
{
unsigned int V_7 = ( V_4 >> 21 ) & 0x1f ;
unsigned int V_8 ;
if ( ( V_7 & 4 ) == 0 ) {
-- V_6 -> V_9 ;
if ( ( ( V_7 >> 1 ) & 1 ) ^ ( V_6 -> V_9 == 0 ) )
return 0 ;
}
if ( ( V_7 & 0x10 ) == 0 ) {
V_8 = ( V_4 >> 16 ) & 0x1f ;
if ( ( ( V_6 -> V_10 >> ( 31 - V_8 ) ) & 1 ) != ( ( V_7 >> 3 ) & 1 ) )
return 0 ;
}
return 1 ;
}
static long T_1 F_4 ( struct V_5 * V_6 , unsigned long V_11 , int V_12 )
{
if ( ! F_5 ( V_6 ) )
return 1 ;
return F_6 ( V_11 , V_12 , V_13 ) ;
}
static unsigned long T_1 F_7 ( unsigned int V_4 , struct V_5 * V_6 )
{
int V_14 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_11 = ( signed short ) V_4 ;
if ( V_14 ) {
V_11 += V_6 -> V_15 [ V_14 ] ;
if ( V_4 & 0x04000000 )
V_6 -> V_15 [ V_14 ] = V_11 ;
}
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static unsigned long T_1 F_8 ( unsigned int V_4 , struct V_5 * V_6 )
{
int V_14 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_11 = ( signed short ) ( V_4 & ~ 3 ) ;
if ( V_14 ) {
V_11 += V_6 -> V_15 [ V_14 ] ;
if ( ( V_4 & 3 ) == 1 )
V_6 -> V_15 [ V_14 ] = V_11 ;
}
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static unsigned long T_1 F_9 ( unsigned int V_4 , struct V_5 * V_6 ,
int V_16 )
{
int V_14 , V_17 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_17 = ( V_4 >> 11 ) & 0x1f ;
V_11 = V_6 -> V_15 [ V_17 ] ;
if ( V_14 ) {
V_11 += V_6 -> V_15 [ V_14 ] ;
if ( V_16 )
V_6 -> V_15 [ V_14 ] = V_11 ;
}
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static inline unsigned long F_10 ( unsigned long V_18 )
{
V_18 |= sizeof( unsigned long ) ;
return V_18 & - V_18 ;
}
static inline unsigned long F_11 ( unsigned long V_18 )
{
return ( ( V_18 >> 8 ) & 0xff ) | ( ( V_18 & 0xff ) << 8 ) ;
}
static inline unsigned long F_12 ( unsigned long V_18 )
{
return ( ( V_18 >> 24 ) & 0xff ) | ( ( V_18 >> 8 ) & 0xff00 ) |
( ( V_18 & 0xff00 ) << 8 ) | ( ( V_18 & 0xff ) << 24 ) ;
}
static inline unsigned long F_13 ( unsigned long V_18 )
{
return ( F_12 ( V_18 ) << 32 ) | F_12 ( V_18 >> 32 ) ;
}
static int T_1 F_14 ( unsigned long * V_19 , unsigned long V_11 ,
int V_12 )
{
int V_20 = 0 ;
unsigned long V_18 = 0 ;
switch ( V_12 ) {
case 1 :
V_20 = F_15 ( V_18 , ( unsigned char V_21 * ) V_11 ) ;
break;
case 2 :
V_20 = F_15 ( V_18 , ( unsigned short V_21 * ) V_11 ) ;
break;
case 4 :
V_20 = F_15 ( V_18 , ( unsigned int V_21 * ) V_11 ) ;
break;
#ifdef F_2
case 8 :
V_20 = F_15 ( V_18 , ( unsigned long V_21 * ) V_11 ) ;
break;
#endif
}
if ( ! V_20 )
* V_19 = V_18 ;
return V_20 ;
}
static int T_1 F_16 ( unsigned long * V_19 , unsigned long V_11 ,
int V_12 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_18 , V_22 , V_23 ;
V_18 = 0 ;
for (; V_12 > 0 ; V_12 -= V_23 ) {
V_23 = F_10 ( V_11 ) ;
if ( V_23 > V_12 )
V_23 = F_10 ( V_12 ) ;
V_20 = F_14 ( & V_22 , V_11 , V_23 ) ;
if ( V_20 )
return V_20 ;
V_18 = ( V_18 << ( 8 * V_23 ) ) + V_22 ;
V_11 += V_23 ;
}
* V_19 = V_18 ;
return 0 ;
}
static int T_1 F_17 ( unsigned long * V_19 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_14 ( V_19 , V_11 , V_12 ) ;
return F_16 ( V_19 , V_11 , V_12 , V_6 ) ;
}
static int T_1 F_18 ( unsigned long V_2 , unsigned long V_11 ,
int V_12 )
{
int V_20 = 0 ;
switch ( V_12 ) {
case 1 :
V_20 = F_19 ( V_2 , ( unsigned char V_21 * ) V_11 ) ;
break;
case 2 :
V_20 = F_19 ( V_2 , ( unsigned short V_21 * ) V_11 ) ;
break;
case 4 :
V_20 = F_19 ( V_2 , ( unsigned int V_21 * ) V_11 ) ;
break;
#ifdef F_2
case 8 :
V_20 = F_19 ( V_2 , ( unsigned long V_21 * ) V_11 ) ;
break;
#endif
}
return V_20 ;
}
static int T_1 F_20 ( unsigned long V_2 , unsigned long V_11 ,
int V_12 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_23 ;
for (; V_12 > 0 ; V_12 -= V_23 ) {
V_23 = F_10 ( V_11 ) ;
if ( V_23 > V_12 )
V_23 = F_10 ( V_12 ) ;
V_20 = F_18 ( V_2 >> ( V_12 - V_23 ) * 8 , V_11 , V_23 ) ;
if ( V_20 )
return V_20 ;
++ V_11 ;
}
return 0 ;
}
static int T_1 F_21 ( unsigned long V_2 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_18 ( V_2 , V_11 , V_12 ) ;
return F_20 ( V_2 , V_11 , V_12 , V_6 ) ;
}
static int T_1 F_22 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ sizeof( double ) / sizeof( long ) ] ;
unsigned long V_26 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_23)( V_25 , V_11 ) ;
V_26 = ( unsigned long ) & V_2 [ 0 ] ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
V_20 = F_16 ( & V_2 [ 0 ] , V_11 , V_12 , V_6 ) ;
V_26 += sizeof( unsigned long ) - V_12 ;
} else {
V_20 = F_16 ( & V_2 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_2 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
if ( V_20 )
return V_20 ;
return (* F_23)( V_25 , V_26 ) ;
}
static int T_1 F_24 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ sizeof( double ) / sizeof( long ) ] ;
unsigned long V_26 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_23)( V_25 , V_11 ) ;
V_26 = ( unsigned long ) & V_2 [ 0 ] ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
V_26 += sizeof( unsigned long ) - V_12 ;
V_20 = (* F_23)( V_25 , V_26 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_20 ( V_2 [ 0 ] , V_11 , V_12 , V_6 ) ;
} else {
V_20 = (* F_23)( V_25 , V_26 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_20 ( V_2 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_20 )
V_20 = F_20 ( V_2 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
return V_20 ;
}
static int T_1 F_25 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_24 ;
return (* F_23)( V_25 , V_11 ) ;
}
static int T_1 F_26 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_24 ;
return (* F_23)( V_25 , V_11 ) ;
}
static int T_1 F_27 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_23)( V_25 , V_11 ) ;
V_20 = F_16 ( & V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = (* F_23)( V_25 , ( unsigned long ) & V_2 [ 0 ] ) ;
return V_20 ;
}
static int T_1 F_28 ( int V_25 , int (* F_23)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_23)( V_25 , V_11 ) ;
V_20 = (* F_23)( V_25 , ( unsigned long ) & V_2 [ 0 ] ) ;
if ( V_20 )
return V_20 ;
V_20 = F_20 ( V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = F_20 ( V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
return V_20 ;
}
static void T_1 F_29 ( struct V_5 * V_6 , int V_27 )
{
long V_2 = V_6 -> V_15 [ V_27 ] ;
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) | ( ( V_6 -> V_28 >> 3 ) & 0x10000000 ) ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) )
V_2 = ( int ) V_2 ;
#endif
if ( V_2 < 0 )
V_6 -> V_10 |= 0x80000000 ;
else if ( V_2 > 0 )
V_6 -> V_10 |= 0x40000000 ;
else
V_6 -> V_10 |= 0x20000000 ;
}
static void T_1 F_30 ( struct V_5 * V_6 , int V_27 ,
unsigned long V_29 , unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_2 = V_29 + V_30 ;
if ( V_31 )
++ V_2 ;
V_6 -> V_15 [ V_27 ] = V_2 ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) ) {
V_2 = ( unsigned int ) V_2 ;
V_29 = ( unsigned int ) V_29 ;
}
#endif
if ( V_2 < V_29 || ( V_31 && V_2 == V_29 ) )
V_6 -> V_28 |= V_32 ;
else
V_6 -> V_28 &= ~ V_32 ;
}
static void T_1 F_31 ( struct V_5 * V_6 , long V_33 , long V_34 ,
int V_35 )
{
unsigned int V_36 , V_37 ;
V_36 = ( V_6 -> V_28 >> 31 ) & 1 ;
if ( V_33 < V_34 )
V_36 |= 8 ;
else if ( V_33 > V_34 )
V_36 |= 4 ;
else
V_36 |= 2 ;
V_37 = ( 7 - V_35 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_37 ) ) | ( V_36 << V_37 ) ;
}
static void T_1 F_32 ( struct V_5 * V_6 , unsigned long V_33 ,
unsigned long V_34 , int V_35 )
{
unsigned int V_36 , V_37 ;
V_36 = ( V_6 -> V_28 >> 31 ) & 1 ;
if ( V_33 < V_34 )
V_36 |= 8 ;
else if ( V_33 > V_34 )
V_36 |= 4 ;
else
V_36 |= 2 ;
V_37 = ( 7 - V_35 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_37 ) ) | ( V_36 << V_37 ) ;
}
int T_1 F_33 ( struct V_5 * V_6 , unsigned int V_4 )
{
unsigned int V_38 , V_14 , V_17 , V_27 , V_39 , V_40 ;
unsigned long int V_41 ;
unsigned long int V_2 , V_30 ;
unsigned long int V_11 ;
unsigned int V_42 , V_43 , V_44 , V_45 ;
int V_20 ;
unsigned long V_46 , V_47 ;
long V_48 ;
V_38 = V_4 >> 26 ;
switch ( V_38 ) {
case 16 :
V_41 = ( signed short ) ( V_4 & 0xfffc ) ;
if ( ( V_4 & 2 ) == 0 )
V_41 += V_6 -> V_49 ;
V_6 -> V_49 += 4 ;
V_6 -> V_49 = F_1 ( V_6 -> V_1 , V_6 -> V_49 ) ;
if ( V_4 & 1 )
V_6 -> V_50 = V_6 -> V_49 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_49 = V_41 ;
return 1 ;
#ifdef F_34
case 17 :
if ( V_6 -> V_15 [ 0 ] == 0x1ebe &&
F_35 ( V_51 ) ) {
V_6 -> V_1 ^= V_52 ;
goto V_53;
}
V_6 -> V_15 [ 9 ] = V_6 -> V_15 [ 13 ] ;
V_6 -> V_15 [ 10 ] = V_54 ;
V_6 -> V_15 [ 11 ] = V_6 -> V_49 + 4 ;
V_6 -> V_15 [ 12 ] = V_6 -> V_1 & V_55 ;
V_6 -> V_15 [ 13 ] = ( unsigned long ) F_36 () ;
V_6 -> V_49 = ( unsigned long ) & V_56 ;
V_6 -> V_1 = V_54 ;
return 1 ;
#endif
case 18 :
V_41 = V_4 & 0x03fffffc ;
if ( V_41 & 0x02000000 )
V_41 -= 0x04000000 ;
if ( ( V_4 & 2 ) == 0 )
V_41 += V_6 -> V_49 ;
if ( V_4 & 1 )
V_6 -> V_50 = F_1 ( V_6 -> V_1 , V_6 -> V_49 + 4 ) ;
V_41 = F_1 ( V_6 -> V_1 , V_41 ) ;
V_6 -> V_49 = V_41 ;
return 1 ;
case 19 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 16 :
case 528 :
V_41 = ( V_4 & 0x400 ) ? V_6 -> V_9 : V_6 -> V_50 ;
V_6 -> V_49 = F_1 ( V_6 -> V_1 , V_6 -> V_49 + 4 ) ;
V_41 = F_1 ( V_6 -> V_1 , V_41 ) ;
if ( V_4 & 1 )
V_6 -> V_50 = V_6 -> V_49 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_49 = V_41 ;
return 1 ;
case 18 :
return - 1 ;
case 150 :
F_37 () ;
goto V_53;
case 33 :
case 129 :
case 193 :
case 225 :
case 257 :
case 289 :
case 417 :
case 449 :
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_17 = ( V_4 >> 11 ) & 0x1f ;
V_27 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_6 -> V_10 >> ( 31 - V_14 ) ) & 1 ;
V_17 = ( V_6 -> V_10 >> ( 31 - V_17 ) ) & 1 ;
V_2 = ( V_4 >> ( 6 + V_14 * 2 + V_17 ) ) & 1 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 1UL << ( 31 - V_27 ) ) ) |
( V_2 << ( 31 - V_27 ) ) ;
goto V_53;
}
break;
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 598 :
#ifdef F_2
switch ( ( V_4 >> 21 ) & 3 ) {
case 1 :
asm volatile("lwsync" : : : "memory");
goto V_53;
case 2 :
asm volatile("ptesync" : : : "memory");
goto V_53;
}
#endif
V_43 () ;
goto V_53;
case 854 :
F_38 () ;
goto V_53;
}
break;
}
if ( ! F_39 ( V_6 ) )
return 0 ;
V_27 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_17 = ( V_4 >> 11 ) & 0x1f ;
switch ( V_38 ) {
case 7 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_15 [ V_14 ] * ( short ) V_4 ;
goto V_53;
case 8 :
V_41 = ( short ) V_4 ;
F_30 ( V_6 , V_27 , ~ V_6 -> V_15 [ V_14 ] , V_41 , 1 ) ;
goto V_53;
case 10 :
V_41 = ( unsigned short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_27 & 1 ) == 0 )
V_2 = ( unsigned int ) V_2 ;
#endif
F_32 ( V_6 , V_2 , V_41 , V_27 >> 2 ) ;
goto V_53;
case 11 :
V_41 = ( short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_27 & 1 ) == 0 )
V_2 = ( int ) V_2 ;
#endif
F_31 ( V_6 , V_2 , V_41 , V_27 >> 2 ) ;
goto V_53;
case 12 :
V_41 = ( short ) V_4 ;
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] , V_41 , 0 ) ;
goto V_53;
case 13 :
V_41 = ( short ) V_4 ;
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] , V_41 , 0 ) ;
F_29 ( V_6 , V_27 ) ;
goto V_53;
case 14 :
V_41 = ( short ) V_4 ;
if ( V_14 )
V_41 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_27 ] = V_41 ;
goto V_53;
case 15 :
V_41 = ( ( short ) V_4 ) << 16 ;
if ( V_14 )
V_41 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_27 ] = V_41 ;
goto V_53;
case 20 :
V_43 = ( V_4 >> 6 ) & 0x1f ;
V_44 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_40 ( V_6 -> V_15 [ V_27 ] ) ;
V_41 = F_41 ( V_43 , V_44 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_41 ) | ( F_42 ( V_2 , V_17 ) & V_41 ) ;
goto V_57;
case 21 :
V_43 = ( V_4 >> 6 ) & 0x1f ;
V_44 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_40 ( V_6 -> V_15 [ V_27 ] ) ;
V_6 -> V_15 [ V_14 ] = F_42 ( V_2 , V_17 ) & F_41 ( V_43 , V_44 ) ;
goto V_57;
case 23 :
V_43 = ( V_4 >> 6 ) & 0x1f ;
V_44 = ( V_4 >> 1 ) & 0x1f ;
V_17 = V_6 -> V_15 [ V_17 ] & 0x1f ;
V_2 = F_40 ( V_6 -> V_15 [ V_27 ] ) ;
V_6 -> V_15 [ V_14 ] = F_42 ( V_2 , V_17 ) & F_41 ( V_43 , V_44 ) ;
goto V_57;
case 24 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] | V_41 ;
goto V_53;
case 25 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] | ( V_41 << 16 ) ;
goto V_53;
case 26 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] ^ V_41 ;
goto V_53;
case 27 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] ^ ( V_41 << 16 ) ;
goto V_53;
case 28 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] & V_41 ;
F_29 ( V_6 , V_14 ) ;
goto V_53;
case 29 :
V_41 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] & ( V_41 << 16 ) ;
F_29 ( V_6 , V_14 ) ;
goto V_53;
#ifdef F_2
case 30 :
V_43 = ( ( V_4 >> 6 ) & 0x1f ) | ( V_4 & 0x20 ) ;
V_2 = V_6 -> V_15 [ V_27 ] ;
if ( ( V_4 & 0x10 ) == 0 ) {
V_45 = V_17 | ( ( V_4 & 2 ) << 4 ) ;
V_2 = F_42 ( V_2 , V_45 ) ;
switch ( ( V_4 >> 2 ) & 3 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_43 ( V_43 ) ;
goto V_57;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_44 ( V_43 ) ;
goto V_57;
case 2 :
V_6 -> V_15 [ V_14 ] = V_2 & F_45 ( V_43 , 63 - V_45 ) ;
goto V_57;
case 3 :
V_41 = F_45 ( V_43 , 63 - V_45 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_41 ) |
( V_2 & V_41 ) ;
goto V_57;
}
} else {
V_45 = V_6 -> V_15 [ V_17 ] & 0x3f ;
V_2 = F_42 ( V_2 , V_45 ) ;
switch ( ( V_4 >> 1 ) & 7 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_43 ( V_43 ) ;
goto V_57;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_44 ( V_43 ) ;
goto V_57;
}
}
#endif
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 83 :
if ( V_6 -> V_1 & V_58 )
break;
V_6 -> V_15 [ V_27 ] = V_6 -> V_1 & V_55 ;
goto V_53;
case 146 :
if ( V_6 -> V_1 & V_58 )
break;
V_41 = V_6 -> V_15 [ V_27 ] ;
if ( ( V_41 & V_59 ) == 0 )
return - 1 ;
V_6 -> V_1 = V_41 ;
goto V_53;
#ifdef F_34
case 178 :
if ( V_6 -> V_1 & V_58 )
break;
V_41 = ( V_4 & 0x10000 ) ? 0x8002 : 0xefffffffffffefffUL ;
V_41 = ( V_6 -> V_1 & V_55 & ~ V_41 )
| ( V_6 -> V_15 [ V_27 ] & V_41 ) ;
if ( ( V_41 & V_59 ) == 0 )
return - 1 ;
V_6 -> V_1 = V_41 ;
goto V_53;
#endif
case 19 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_10 ;
V_6 -> V_15 [ V_27 ] &= 0xffffffffUL ;
goto V_53;
case 144 :
V_41 = 0xf0000000UL ;
V_2 = V_6 -> V_15 [ V_27 ] ;
for ( V_45 = 0 ; V_45 < 8 ; ++ V_45 ) {
if ( V_4 & ( 0x80000 >> V_45 ) )
V_6 -> V_10 = ( V_6 -> V_10 & ~ V_41 ) |
( V_2 & V_41 ) ;
V_41 >>= 4 ;
}
goto V_53;
case 339 :
V_39 = ( V_4 >> 11 ) & 0x3ff ;
switch ( V_39 ) {
case 0x20 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_28 ;
V_6 -> V_15 [ V_27 ] &= 0xffffffffUL ;
goto V_53;
case 0x100 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_50 ;
goto V_53;
case 0x120 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_9 ;
goto V_53;
}
break;
case 467 :
V_39 = ( V_4 >> 11 ) & 0x3ff ;
switch ( V_39 ) {
case 0x20 :
V_6 -> V_28 = ( V_6 -> V_15 [ V_27 ] & 0xffffffffUL ) ;
goto V_53;
case 0x100 :
V_6 -> V_50 = V_6 -> V_15 [ V_27 ] ;
goto V_53;
case 0x120 :
V_6 -> V_9 = V_6 -> V_15 [ V_27 ] ;
goto V_53;
}
break;
case 0 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_30 = V_6 -> V_15 [ V_17 ] ;
#ifdef F_2
if ( ( V_27 & 1 ) == 0 ) {
V_2 = ( int ) V_2 ;
V_30 = ( int ) V_30 ;
}
#endif
F_31 ( V_6 , V_2 , V_30 , V_27 >> 2 ) ;
goto V_53;
case 32 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_30 = V_6 -> V_15 [ V_17 ] ;
#ifdef F_2
if ( ( V_27 & 1 ) == 0 ) {
V_2 = ( unsigned int ) V_2 ;
V_30 = ( unsigned int ) V_30 ;
}
#endif
F_32 ( V_6 , V_2 , V_30 , V_27 >> 2 ) ;
goto V_53;
case 8 :
F_30 ( V_6 , V_27 , ~ V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_17 ] , 1 ) ;
goto V_60;
#ifdef F_2
case 9 :
asm("mulhdu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_60;
#endif
case 10 :
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_17 ] , 0 ) ;
goto V_60;
case 11 :
asm("mulhwu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_60;
case 40 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_15 [ V_17 ] - V_6 -> V_15 [ V_14 ] ;
goto V_60;
#ifdef F_2
case 73 :
asm("mulhd %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_60;
#endif
case 75 :
asm("mulhw %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_60;
case 104 :
V_6 -> V_15 [ V_27 ] = - V_6 -> V_15 [ V_14 ] ;
goto V_60;
case 136 :
F_30 ( V_6 , V_27 , ~ V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_17 ] ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
case 138 :
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_17 ] ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
case 200 :
F_30 ( V_6 , V_27 , ~ V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
case 202 :
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
case 232 :
F_30 ( V_6 , V_27 , ~ V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
#ifdef F_2
case 233 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_15 [ V_14 ] * V_6 -> V_15 [ V_17 ] ;
goto V_60;
#endif
case 234 :
F_30 ( V_6 , V_27 , V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_28 & V_32 ) ;
goto V_60;
case 235 :
V_6 -> V_15 [ V_27 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] *
( unsigned int ) V_6 -> V_15 [ V_17 ] ;
goto V_60;
case 266 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_15 [ V_14 ] + V_6 -> V_15 [ V_17 ] ;
goto V_60;
#ifdef F_2
case 457 :
V_6 -> V_15 [ V_27 ] = V_6 -> V_15 [ V_14 ] / V_6 -> V_15 [ V_17 ] ;
goto V_60;
#endif
case 459 :
V_6 -> V_15 [ V_27 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] /
( unsigned int ) V_6 -> V_15 [ V_17 ] ;
goto V_60;
#ifdef F_2
case 489 :
V_6 -> V_15 [ V_27 ] = ( long int ) V_6 -> V_15 [ V_14 ] /
( long int ) V_6 -> V_15 [ V_17 ] ;
goto V_60;
#endif
case 491 :
V_6 -> V_15 [ V_27 ] = ( int ) V_6 -> V_15 [ V_14 ] /
( int ) V_6 -> V_15 [ V_17 ] ;
goto V_60;
case 26 :
asm("cntlzw %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_57;
#ifdef F_2
case 58 :
asm("cntlzd %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_57;
#endif
case 28 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] & V_6 -> V_15 [ V_17 ] ;
goto V_57;
case 60 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] & ~ V_6 -> V_15 [ V_17 ] ;
goto V_57;
case 124 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_27 ] | V_6 -> V_15 [ V_17 ] ) ;
goto V_57;
case 284 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_27 ] ^ V_6 -> V_15 [ V_17 ] ) ;
goto V_57;
case 316 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] ^ V_6 -> V_15 [ V_17 ] ;
goto V_57;
case 412 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] | ~ V_6 -> V_15 [ V_17 ] ;
goto V_57;
case 444 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] | V_6 -> V_15 [ V_17 ] ;
goto V_57;
case 476 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_27 ] & V_6 -> V_15 [ V_17 ] ) ;
goto V_57;
case 922 :
V_6 -> V_15 [ V_14 ] = ( signed short ) V_6 -> V_15 [ V_27 ] ;
goto V_57;
case 954 :
V_6 -> V_15 [ V_14 ] = ( signed char ) V_6 -> V_15 [ V_27 ] ;
goto V_57;
#ifdef F_2
case 986 :
V_6 -> V_15 [ V_14 ] = ( signed int ) V_6 -> V_15 [ V_27 ] ;
goto V_57;
#endif
case 24 :
V_45 = V_6 -> V_15 [ V_17 ] & 0x3f ;
if ( V_45 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_27 ] << V_45 ) & 0xffffffffUL ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_57;
case 536 :
V_45 = V_6 -> V_15 [ V_17 ] & 0x3f ;
if ( V_45 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_27 ] & 0xffffffffUL ) >> V_45 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_57;
case 792 :
V_45 = V_6 -> V_15 [ V_17 ] & 0x3f ;
V_48 = ( signed int ) V_6 -> V_15 [ V_27 ] ;
V_6 -> V_15 [ V_14 ] = V_48 >> ( V_45 < 32 ? V_45 : 31 ) ;
if ( V_48 < 0 && ( V_45 >= 32 || ( V_48 & ( ( 1 << V_45 ) - 1 ) ) != 0 ) )
V_6 -> V_28 |= V_32 ;
else
V_6 -> V_28 &= ~ V_32 ;
goto V_57;
case 824 :
V_45 = V_17 ;
V_48 = ( signed int ) V_6 -> V_15 [ V_27 ] ;
V_6 -> V_15 [ V_14 ] = V_48 >> V_45 ;
if ( V_48 < 0 && ( V_48 & ( ( 1 << V_45 ) - 1 ) ) != 0 )
V_6 -> V_28 |= V_32 ;
else
V_6 -> V_28 &= ~ V_32 ;
goto V_57;
#ifdef F_2
case 27 :
V_45 = V_6 -> V_15 [ V_27 ] & 0x7f ;
if ( V_45 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] << V_45 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_57;
case 539 :
V_45 = V_6 -> V_15 [ V_17 ] & 0x7f ;
if ( V_45 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_27 ] >> V_45 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_57;
case 794 :
V_45 = V_6 -> V_15 [ V_17 ] & 0x7f ;
V_48 = ( signed long int ) V_6 -> V_15 [ V_27 ] ;
V_6 -> V_15 [ V_14 ] = V_48 >> ( V_45 < 64 ? V_45 : 63 ) ;
if ( V_48 < 0 && ( V_45 >= 64 || ( V_48 & ( ( 1 << V_45 ) - 1 ) ) != 0 ) )
V_6 -> V_28 |= V_32 ;
else
V_6 -> V_28 &= ~ V_32 ;
goto V_57;
case 826 :
case 827 :
V_45 = V_17 | ( ( V_4 & 2 ) << 4 ) ;
V_48 = ( signed long int ) V_6 -> V_15 [ V_27 ] ;
V_6 -> V_15 [ V_14 ] = V_48 >> V_45 ;
if ( V_48 < 0 && ( V_48 & ( ( 1 << V_45 ) - 1 ) ) != 0 )
V_6 -> V_28 |= V_32 ;
else
V_6 -> V_28 &= ~ V_32 ;
goto V_57;
#endif
case 54 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
return 0 ;
V_20 = 0 ;
F_46 ( V_11 , V_20 , L_1 ) ;
if ( V_20 )
return 0 ;
goto V_53;
case 86 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
return 0 ;
V_20 = 0 ;
F_46 ( V_11 , V_20 , L_2 ) ;
if ( V_20 )
return 0 ;
goto V_53;
case 246 :
if ( V_27 == 0 ) {
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
F_47 ( ( void * ) V_11 ) ;
}
goto V_53;
case 278 :
if ( V_27 == 0 ) {
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
F_48 ( ( void * ) V_11 ) ;
}
goto V_53;
}
break;
}
if ( V_6 -> V_1 & V_52 )
return 0 ;
V_46 = V_6 -> V_15 [ V_14 ] ;
switch ( V_38 ) {
case 31 :
V_40 = V_4 & 0x40 ;
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 20 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 3 )
break;
V_20 = - V_24 ;
if ( ! F_4 ( V_6 , V_11 , 4 ) )
goto V_61;
V_20 = 0 ;
F_49 ( V_2 , V_11 , V_20 , L_3 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = V_2 ;
goto V_61;
case 150 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 3 )
break;
V_20 = - V_24 ;
if ( ! F_4 ( V_6 , V_11 , 4 ) )
goto V_61;
V_20 = 0 ;
F_50 ( V_6 -> V_15 [ V_27 ] , V_11 , V_20 , L_4 , V_42 ) ;
if ( ! V_20 )
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) |
( V_42 & 0xe0000000 ) |
( ( V_6 -> V_28 >> 3 ) & 0x10000000 ) ;
goto V_61;
#ifdef F_2
case 84 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 7 )
break;
V_20 = - V_24 ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
goto V_61;
V_20 = 0 ;
F_49 ( V_2 , V_11 , V_20 , L_5 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = V_2 ;
goto V_61;
case 214 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 7 )
break;
V_20 = - V_24 ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
goto V_61;
V_20 = 0 ;
F_50 ( V_6 -> V_15 [ V_27 ] , V_11 , V_20 , L_6 , V_42 ) ;
if ( ! V_20 )
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) |
( V_42 & 0xe0000000 ) |
( ( V_6 -> V_28 >> 3 ) & 0x10000000 ) ;
goto V_61;
case 21 :
case 53 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
8 , V_6 ) ;
goto V_61;
#endif
case 23 :
case 55 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
4 , V_6 ) ;
goto V_61;
case 87 :
case 119 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
1 , V_6 ) ;
goto V_61;
#ifdef F_51
case 103 :
case 359 :
if ( ! ( V_6 -> V_1 & V_62 ) )
break;
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
V_20 = F_25 ( V_27 , V_63 , V_11 , V_6 ) ;
goto V_61;
case 231 :
case 487 :
if ( ! ( V_6 -> V_1 & V_62 ) )
break;
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
V_20 = F_26 ( V_27 , V_64 , V_11 , V_6 ) ;
goto V_61;
#endif
#ifdef F_2
case 149 :
case 181 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , V_40 ) , 8 , V_6 ) ;
goto V_61;
#endif
case 151 :
case 183 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , V_40 ) , 4 , V_6 ) ;
goto V_61;
case 215 :
case 247 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , V_40 ) , 1 , V_6 ) ;
goto V_61;
case 279 :
case 311 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
2 , V_6 ) ;
goto V_61;
#ifdef F_2
case 341 :
case 373 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = ( signed int ) V_6 -> V_15 [ V_27 ] ;
goto V_61;
#endif
case 343 :
case 375 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_9 ( V_4 , V_6 , V_40 ) ,
2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = ( signed short ) V_6 -> V_15 [ V_27 ] ;
goto V_61;
case 407 :
case 439 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , V_40 ) , 2 , V_6 ) ;
goto V_61;
#ifdef F_2
case 532 :
V_20 = F_17 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 8 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = F_13 ( V_2 ) ;
goto V_61;
#endif
case 534 :
V_20 = F_17 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = F_12 ( V_2 ) ;
goto V_61;
#ifdef F_52
case 535 :
case 567 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_22 ( V_27 , V_66 , V_11 , 4 , V_6 ) ;
goto V_61;
case 599 :
case 631 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_22 ( V_27 , V_67 , V_11 , 8 , V_6 ) ;
goto V_61;
case 663 :
case 695 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_24 ( V_27 , V_68 , V_11 , 4 , V_6 ) ;
goto V_61;
case 727 :
case 759 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_24 ( V_27 , V_69 , V_11 , 8 , V_6 ) ;
goto V_61;
#endif
#ifdef F_2
case 660 :
V_2 = F_13 ( V_6 -> V_15 [ V_27 ] ) ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 8 , V_6 ) ;
goto V_61;
#endif
case 662 :
V_2 = F_12 ( V_6 -> V_15 [ V_27 ] ) ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 4 , V_6 ) ;
goto V_61;
case 790 :
V_20 = F_17 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = F_11 ( V_2 ) ;
goto V_61;
case 918 :
V_2 = F_11 ( V_6 -> V_15 [ V_27 ] ) ;
V_20 = F_21 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 2 , V_6 ) ;
goto V_61;
#ifdef F_53
case 844 :
case 876 :
if ( ! ( V_6 -> V_1 & V_70 ) )
break;
V_27 |= ( V_4 & 1 ) << 5 ;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_27 ( V_27 , V_71 , V_11 , V_6 ) ;
goto V_61;
case 972 :
case 1004 :
if ( ! ( V_6 -> V_1 & V_70 ) )
break;
V_27 |= ( V_4 & 1 ) << 5 ;
V_11 = F_9 ( V_4 , V_6 , V_40 ) ;
V_20 = F_28 ( V_27 , V_72 , V_11 , V_6 ) ;
goto V_61;
#endif
}
break;
case 32 :
case 33 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_7 ( V_4 , V_6 ) , 4 , V_6 ) ;
goto V_61;
case 34 :
case 35 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_7 ( V_4 , V_6 ) , 1 , V_6 ) ;
goto V_61;
case 36 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_7 ( V_4 , V_6 ) , 4 , V_6 ) ;
goto V_61;
case 37 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_47 = F_7 ( V_4 , V_6 ) ;
if ( ( V_14 == 1 ) && ! ( V_6 -> V_1 & V_58 ) \
&& ( V_47 >= ( V_6 -> V_15 [ 1 ] - V_73 ) ) ) {
if ( V_47 - V_73 <= V_74 -> V_75 . V_76 ) {
F_54 ( V_77 L_7 ) ;
V_20 = - V_78 ;
break;
}
F_55 ( F_56 ( V_79 ) ) ;
F_57 ( V_79 ) ;
V_20 = 0 ;
} else
V_20 = F_21 ( V_2 , V_47 , 4 , V_6 ) ;
goto V_61;
case 38 :
case 39 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_7 ( V_4 , V_6 ) , 1 , V_6 ) ;
goto V_61;
case 40 :
case 41 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
goto V_61;
case 42 :
case 43 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = ( signed short ) V_6 -> V_15 [ V_27 ] ;
goto V_61;
case 44 :
case 45 :
V_2 = V_6 -> V_15 [ V_27 ] ;
V_20 = F_21 ( V_2 , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
goto V_61;
case 46 :
V_14 = ( V_4 >> 16 ) & 0x1f ;
if ( V_14 >= V_27 )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
do {
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , V_11 , 4 , V_6 ) ;
if ( V_20 )
return 0 ;
V_11 += 4 ;
} while ( ++ V_27 < 32 );
goto V_53;
case 47 :
V_11 = F_7 ( V_4 , V_6 ) ;
do {
V_20 = F_21 ( V_6 -> V_15 [ V_27 ] , V_11 , 4 , V_6 ) ;
if ( V_20 )
return 0 ;
V_11 += 4 ;
} while ( ++ V_27 < 32 );
goto V_53;
#ifdef F_58
case 48 :
case 49 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_22 ( V_27 , V_66 , V_11 , 4 , V_6 ) ;
goto V_61;
case 50 :
case 51 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_22 ( V_27 , V_67 , V_11 , 8 , V_6 ) ;
goto V_61;
case 52 :
case 53 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_24 ( V_27 , V_68 , V_11 , 4 , V_6 ) ;
goto V_61;
case 54 :
case 55 :
if ( ! ( V_6 -> V_1 & V_65 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_24 ( V_27 , V_69 , V_11 , 8 , V_6 ) ;
goto V_61;
#endif
#ifdef F_2
case 58 :
switch ( V_4 & 3 ) {
case 0 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_8 ( V_4 , V_6 ) ,
8 , V_6 ) ;
goto V_61;
case 1 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_8 ( V_4 , V_6 ) ,
8 , V_6 ) ;
goto V_61;
case 2 :
V_20 = F_17 ( & V_6 -> V_15 [ V_27 ] , F_8 ( V_4 , V_6 ) ,
4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_27 ] = ( signed int ) V_6 -> V_15 [ V_27 ] ;
goto V_61;
}
break;
case 62 :
V_2 = V_6 -> V_15 [ V_27 ] ;
switch ( V_4 & 3 ) {
case 0 :
V_20 = F_21 ( V_2 , F_8 ( V_4 , V_6 ) , 8 , V_6 ) ;
goto V_61;
case 1 :
V_20 = F_21 ( V_2 , F_8 ( V_4 , V_6 ) , 8 , V_6 ) ;
goto V_61;
}
break;
#endif
}
V_20 = - V_78 ;
V_61:
if ( V_20 ) {
V_6 -> V_15 [ V_14 ] = V_46 ;
return 0 ;
}
V_53:
V_6 -> V_49 = F_1 ( V_6 -> V_1 , V_6 -> V_49 + 4 ) ;
return 1 ;
V_57:
if ( V_4 & 1 )
F_29 ( V_6 , V_14 ) ;
goto V_53;
V_60:
if ( V_4 & 1 )
F_29 ( V_6 , V_27 ) ;
goto V_53;
}
