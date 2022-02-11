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
if ( V_4 & 0x04000000 ) {
if ( ( V_4 >> 26 ) != 47 )
V_6 -> V_15 [ V_14 ] = V_11 ;
}
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
#ifdef F_17
int V_24 = V_12 ;
#endif
V_18 = 0 ;
for (; V_12 > 0 ; V_12 -= V_23 ) {
#ifdef F_17
V_23 = 1 ;
#endif
#ifdef F_18
V_23 = F_10 ( V_11 ) ;
#endif
if ( V_23 > V_12 )
V_23 = F_10 ( V_12 ) ;
V_20 = F_14 ( & V_22 , V_11 , V_23 ) ;
if ( V_20 )
return V_20 ;
V_18 = ( V_18 << ( 8 * V_23 ) ) + V_22 ;
V_11 += V_23 ;
}
#ifdef F_17
switch ( V_24 ) {
case 2 :
* V_19 = F_11 ( V_18 ) ;
break;
case 4 :
* V_19 = F_12 ( V_18 ) ;
break;
#ifdef F_2
case 8 :
* V_19 = F_13 ( V_18 ) ;
break;
#endif
}
#endif
#ifdef F_18
* V_19 = V_18 ;
#endif
return 0 ;
}
static int T_1 F_19 ( unsigned long * V_19 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_25 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_14 ( V_19 , V_11 , V_12 ) ;
return F_16 ( V_19 , V_11 , V_12 , V_6 ) ;
}
static int T_1 F_20 ( unsigned long V_2 , unsigned long V_11 ,
int V_12 )
{
int V_20 = 0 ;
switch ( V_12 ) {
case 1 :
V_20 = F_21 ( V_2 , ( unsigned char V_21 * ) V_11 ) ;
break;
case 2 :
V_20 = F_21 ( V_2 , ( unsigned short V_21 * ) V_11 ) ;
break;
case 4 :
V_20 = F_21 ( V_2 , ( unsigned int V_21 * ) V_11 ) ;
break;
#ifdef F_2
case 8 :
V_20 = F_21 ( V_2 , ( unsigned long V_21 * ) V_11 ) ;
break;
#endif
}
return V_20 ;
}
static int T_1 F_22 ( unsigned long V_2 , unsigned long V_11 ,
int V_12 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_23 ;
#ifdef F_17
switch ( V_12 ) {
case 2 :
V_2 = F_11 ( V_2 ) ;
break;
case 4 :
V_2 = F_12 ( V_2 ) ;
break;
#ifdef F_2
case 8 :
V_2 = F_13 ( V_2 ) ;
break;
#endif
}
#endif
for (; V_12 > 0 ; V_12 -= V_23 ) {
#ifdef F_17
V_23 = 1 ;
#endif
#ifdef F_18
V_23 = F_10 ( V_11 ) ;
#endif
if ( V_23 > V_12 )
V_23 = F_10 ( V_12 ) ;
V_20 = F_20 ( V_2 >> ( V_12 - V_23 ) * 8 , V_11 , V_23 ) ;
if ( V_20 )
return V_20 ;
V_11 += V_23 ;
}
return 0 ;
}
static int T_1 F_23 ( unsigned long V_2 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_25 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_20 ( V_2 , V_11 , V_12 ) ;
return F_22 ( V_2 , V_11 , V_12 , V_6 ) ;
}
static int T_1 F_24 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_20 ;
union {
double V_27 ;
unsigned long V_28 [ 2 ] ;
struct {
#ifdef F_18
unsigned V_29 ;
unsigned V_30 ;
#endif
#ifdef F_17
unsigned V_30 ;
unsigned V_29 ;
#endif
} V_31 ;
} V_32 ;
unsigned long V_33 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_25 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_26 , V_11 ) ;
V_33 = ( unsigned long ) & V_32 . V_28 ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
V_20 = F_16 ( & V_32 . V_28 [ 0 ] , V_11 , V_12 , V_6 ) ;
if ( V_12 == 4 )
V_33 = ( unsigned long ) & ( V_32 . V_31 . V_30 ) ;
} else {
V_20 = F_16 ( & V_32 . V_28 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_32 . V_28 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
if ( V_20 )
return V_20 ;
return (* F_25)( V_26 , V_33 ) ;
}
static int T_1 F_26 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_20 ;
union {
double V_27 ;
unsigned long V_28 [ 2 ] ;
struct {
#ifdef F_18
unsigned V_29 ;
unsigned V_30 ;
#endif
#ifdef F_17
unsigned V_30 ;
unsigned V_29 ;
#endif
} V_31 ;
} V_32 ;
unsigned long V_33 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_25 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_26 , V_11 ) ;
V_33 = ( unsigned long ) & V_32 . V_28 [ 0 ] ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
if ( V_12 == 4 )
V_33 = ( unsigned long ) & ( V_32 . V_31 . V_30 ) ;
V_20 = (* F_25)( V_26 , V_33 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_22 ( V_32 . V_28 [ 0 ] , V_11 , V_12 , V_6 ) ;
} else {
V_20 = (* F_25)( V_26 , V_33 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_22 ( V_32 . V_28 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_20 )
V_20 = F_22 ( V_32 . V_28 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
return V_20 ;
}
static int T_1 F_27 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_25 ;
return (* F_25)( V_26 , V_11 ) ;
}
static int T_1 F_28 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_25 ;
return (* F_25)( V_26 , V_11 ) ;
}
static int T_1 F_29 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_25 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_26 , V_11 ) ;
V_20 = F_16 ( & V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = F_16 ( & V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = (* F_25)( V_26 , ( unsigned long ) & V_2 [ 0 ] ) ;
return V_20 ;
}
static int T_1 F_30 ( int V_26 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_20 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_25 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_26 , V_11 ) ;
V_20 = (* F_25)( V_26 , ( unsigned long ) & V_2 [ 0 ] ) ;
if ( V_20 )
return V_20 ;
V_20 = F_22 ( V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_20 )
V_20 = F_22 ( V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
return V_20 ;
}
static void T_1 F_31 ( struct V_5 * V_6 , int V_34 )
{
long V_2 = V_6 -> V_15 [ V_34 ] ;
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) | ( ( V_6 -> V_35 >> 3 ) & 0x10000000 ) ;
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
static void T_1 F_32 ( struct V_5 * V_6 , int V_34 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long V_38 )
{
unsigned long V_2 = V_36 + V_37 ;
if ( V_38 )
++ V_2 ;
V_6 -> V_15 [ V_34 ] = V_2 ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) ) {
V_2 = ( unsigned int ) V_2 ;
V_36 = ( unsigned int ) V_36 ;
}
#endif
if ( V_2 < V_36 || ( V_38 && V_2 == V_36 ) )
V_6 -> V_35 |= V_39 ;
else
V_6 -> V_35 &= ~ V_39 ;
}
static void T_1 F_33 ( struct V_5 * V_6 , long V_40 , long V_41 ,
int V_42 )
{
unsigned int V_43 , V_44 ;
V_43 = ( V_6 -> V_35 >> 31 ) & 1 ;
if ( V_40 < V_41 )
V_43 |= 8 ;
else if ( V_40 > V_41 )
V_43 |= 4 ;
else
V_43 |= 2 ;
V_44 = ( 7 - V_42 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_44 ) ) | ( V_43 << V_44 ) ;
}
static void T_1 F_34 ( struct V_5 * V_6 , unsigned long V_40 ,
unsigned long V_41 , int V_42 )
{
unsigned int V_43 , V_44 ;
V_43 = ( V_6 -> V_35 >> 31 ) & 1 ;
if ( V_40 < V_41 )
V_43 |= 8 ;
else if ( V_40 > V_41 )
V_43 |= 4 ;
else
V_43 |= 2 ;
V_44 = ( 7 - V_42 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_44 ) ) | ( V_43 << V_44 ) ;
}
int T_1 F_35 ( struct V_5 * V_6 , unsigned int V_4 )
{
unsigned int V_45 , V_14 , V_17 , V_34 , V_46 , V_47 ;
unsigned long int V_48 ;
unsigned long int V_2 , V_37 ;
unsigned long int V_11 ;
unsigned int V_49 , V_50 , V_51 , V_52 ;
int V_20 ;
unsigned long V_53 , V_54 ;
long V_55 ;
V_45 = V_4 >> 26 ;
switch ( V_45 ) {
case 16 :
V_48 = ( signed short ) ( V_4 & 0xfffc ) ;
if ( ( V_4 & 2 ) == 0 )
V_48 += V_6 -> V_56 ;
V_6 -> V_56 += 4 ;
V_6 -> V_56 = F_1 ( V_6 -> V_1 , V_6 -> V_56 ) ;
if ( V_4 & 1 )
V_6 -> V_57 = V_6 -> V_56 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_56 = F_1 ( V_6 -> V_1 , V_48 ) ;
return 1 ;
#ifdef F_36
case 17 :
if ( V_6 -> V_15 [ 0 ] == 0x1ebe &&
F_37 ( V_58 ) ) {
V_6 -> V_1 ^= V_59 ;
goto V_60;
}
V_6 -> V_15 [ 9 ] = V_6 -> V_15 [ 13 ] ;
V_6 -> V_15 [ 10 ] = V_61 ;
V_6 -> V_15 [ 11 ] = V_6 -> V_56 + 4 ;
V_6 -> V_15 [ 12 ] = V_6 -> V_1 & V_62 ;
V_6 -> V_15 [ 13 ] = ( unsigned long ) F_38 () ;
V_6 -> V_56 = ( unsigned long ) & V_63 ;
V_6 -> V_1 = V_61 ;
return 1 ;
#endif
case 18 :
V_48 = V_4 & 0x03fffffc ;
if ( V_48 & 0x02000000 )
V_48 -= 0x04000000 ;
if ( ( V_4 & 2 ) == 0 )
V_48 += V_6 -> V_56 ;
if ( V_4 & 1 )
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_6 -> V_56 + 4 ) ;
V_48 = F_1 ( V_6 -> V_1 , V_48 ) ;
V_6 -> V_56 = V_48 ;
return 1 ;
case 19 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 16 :
case 528 :
V_48 = ( V_4 & 0x400 ) ? V_6 -> V_9 : V_6 -> V_57 ;
V_6 -> V_56 = F_1 ( V_6 -> V_1 , V_6 -> V_56 + 4 ) ;
V_48 = F_1 ( V_6 -> V_1 , V_48 ) ;
if ( V_4 & 1 )
V_6 -> V_57 = V_6 -> V_56 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_56 = V_48 ;
return 1 ;
case 18 :
return - 1 ;
case 150 :
F_39 () ;
goto V_60;
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
V_34 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_6 -> V_10 >> ( 31 - V_14 ) ) & 1 ;
V_17 = ( V_6 -> V_10 >> ( 31 - V_17 ) ) & 1 ;
V_2 = ( V_4 >> ( 6 + V_14 * 2 + V_17 ) ) & 1 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 1UL << ( 31 - V_34 ) ) ) |
( V_2 << ( 31 - V_34 ) ) ;
goto V_60;
}
break;
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 598 :
#ifdef F_2
switch ( ( V_4 >> 21 ) & 3 ) {
case 1 :
asm volatile("lwsync" : : : "memory");
goto V_60;
case 2 :
asm volatile("ptesync" : : : "memory");
goto V_60;
}
#endif
V_50 () ;
goto V_60;
case 854 :
F_40 () ;
goto V_60;
}
break;
}
if ( ! F_41 ( V_6 ) )
return 0 ;
V_34 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_17 = ( V_4 >> 11 ) & 0x1f ;
switch ( V_45 ) {
case 7 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_15 [ V_14 ] * ( short ) V_4 ;
goto V_60;
case 8 :
V_48 = ( short ) V_4 ;
F_32 ( V_6 , V_34 , ~ V_6 -> V_15 [ V_14 ] , V_48 , 1 ) ;
goto V_60;
case 10 :
V_48 = ( unsigned short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_34 & 1 ) == 0 )
V_2 = ( unsigned int ) V_2 ;
#endif
F_34 ( V_6 , V_2 , V_48 , V_34 >> 2 ) ;
goto V_60;
case 11 :
V_48 = ( short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_34 & 1 ) == 0 )
V_2 = ( int ) V_2 ;
#endif
F_33 ( V_6 , V_2 , V_48 , V_34 >> 2 ) ;
goto V_60;
case 12 :
V_48 = ( short ) V_4 ;
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] , V_48 , 0 ) ;
goto V_60;
case 13 :
V_48 = ( short ) V_4 ;
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] , V_48 , 0 ) ;
F_31 ( V_6 , V_34 ) ;
goto V_60;
case 14 :
V_48 = ( short ) V_4 ;
if ( V_14 )
V_48 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_34 ] = V_48 ;
goto V_60;
case 15 :
V_48 = ( ( short ) V_4 ) << 16 ;
if ( V_14 )
V_48 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_34 ] = V_48 ;
goto V_60;
case 20 :
V_50 = ( V_4 >> 6 ) & 0x1f ;
V_51 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_42 ( V_6 -> V_15 [ V_34 ] ) ;
V_48 = F_43 ( V_50 , V_51 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_48 ) | ( F_44 ( V_2 , V_17 ) & V_48 ) ;
goto V_64;
case 21 :
V_50 = ( V_4 >> 6 ) & 0x1f ;
V_51 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_42 ( V_6 -> V_15 [ V_34 ] ) ;
V_6 -> V_15 [ V_14 ] = F_44 ( V_2 , V_17 ) & F_43 ( V_50 , V_51 ) ;
goto V_64;
case 23 :
V_50 = ( V_4 >> 6 ) & 0x1f ;
V_51 = ( V_4 >> 1 ) & 0x1f ;
V_17 = V_6 -> V_15 [ V_17 ] & 0x1f ;
V_2 = F_42 ( V_6 -> V_15 [ V_34 ] ) ;
V_6 -> V_15 [ V_14 ] = F_44 ( V_2 , V_17 ) & F_43 ( V_50 , V_51 ) ;
goto V_64;
case 24 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] | V_48 ;
goto V_60;
case 25 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] | ( V_48 << 16 ) ;
goto V_60;
case 26 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] ^ V_48 ;
goto V_60;
case 27 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] ^ ( V_48 << 16 ) ;
goto V_60;
case 28 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] & V_48 ;
F_31 ( V_6 , V_14 ) ;
goto V_60;
case 29 :
V_48 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] & ( V_48 << 16 ) ;
F_31 ( V_6 , V_14 ) ;
goto V_60;
#ifdef F_2
case 30 :
V_50 = ( ( V_4 >> 6 ) & 0x1f ) | ( V_4 & 0x20 ) ;
V_2 = V_6 -> V_15 [ V_34 ] ;
if ( ( V_4 & 0x10 ) == 0 ) {
V_52 = V_17 | ( ( V_4 & 2 ) << 4 ) ;
V_2 = F_44 ( V_2 , V_52 ) ;
switch ( ( V_4 >> 2 ) & 3 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_45 ( V_50 ) ;
goto V_64;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_46 ( V_50 ) ;
goto V_64;
case 2 :
V_6 -> V_15 [ V_14 ] = V_2 & F_47 ( V_50 , 63 - V_52 ) ;
goto V_64;
case 3 :
V_48 = F_47 ( V_50 , 63 - V_52 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_48 ) |
( V_2 & V_48 ) ;
goto V_64;
}
} else {
V_52 = V_6 -> V_15 [ V_17 ] & 0x3f ;
V_2 = F_44 ( V_2 , V_52 ) ;
switch ( ( V_4 >> 1 ) & 7 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_45 ( V_50 ) ;
goto V_64;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_46 ( V_50 ) ;
goto V_64;
}
}
#endif
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 83 :
if ( V_6 -> V_1 & V_65 )
break;
V_6 -> V_15 [ V_34 ] = V_6 -> V_1 & V_62 ;
goto V_60;
case 146 :
if ( V_6 -> V_1 & V_65 )
break;
V_48 = V_6 -> V_15 [ V_34 ] ;
if ( ( V_48 & V_66 ) == 0 )
return - 1 ;
V_6 -> V_1 = V_48 ;
goto V_60;
#ifdef F_36
case 178 :
if ( V_6 -> V_1 & V_65 )
break;
V_48 = ( V_4 & 0x10000 ) ? 0x8002 : 0xefffffffffffefffUL ;
V_48 = ( V_6 -> V_1 & V_62 & ~ V_48 )
| ( V_6 -> V_15 [ V_34 ] & V_48 ) ;
if ( ( V_48 & V_66 ) == 0 )
return - 1 ;
V_6 -> V_1 = V_48 ;
goto V_60;
#endif
case 19 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_10 ;
V_6 -> V_15 [ V_34 ] &= 0xffffffffUL ;
goto V_60;
case 144 :
V_48 = 0xf0000000UL ;
V_2 = V_6 -> V_15 [ V_34 ] ;
for ( V_52 = 0 ; V_52 < 8 ; ++ V_52 ) {
if ( V_4 & ( 0x80000 >> V_52 ) )
V_6 -> V_10 = ( V_6 -> V_10 & ~ V_48 ) |
( V_2 & V_48 ) ;
V_48 >>= 4 ;
}
goto V_60;
case 339 :
V_46 = ( V_4 >> 11 ) & 0x3ff ;
switch ( V_46 ) {
case 0x20 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_35 ;
V_6 -> V_15 [ V_34 ] &= 0xffffffffUL ;
goto V_60;
case 0x100 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_57 ;
goto V_60;
case 0x120 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_9 ;
goto V_60;
}
break;
case 467 :
V_46 = ( V_4 >> 11 ) & 0x3ff ;
switch ( V_46 ) {
case 0x20 :
V_6 -> V_35 = ( V_6 -> V_15 [ V_34 ] & 0xffffffffUL ) ;
goto V_60;
case 0x100 :
V_6 -> V_57 = V_6 -> V_15 [ V_34 ] ;
goto V_60;
case 0x120 :
V_6 -> V_9 = V_6 -> V_15 [ V_34 ] ;
goto V_60;
}
break;
case 0 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_37 = V_6 -> V_15 [ V_17 ] ;
#ifdef F_2
if ( ( V_34 & 1 ) == 0 ) {
V_2 = ( int ) V_2 ;
V_37 = ( int ) V_37 ;
}
#endif
F_33 ( V_6 , V_2 , V_37 , V_34 >> 2 ) ;
goto V_60;
case 32 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_37 = V_6 -> V_15 [ V_17 ] ;
#ifdef F_2
if ( ( V_34 & 1 ) == 0 ) {
V_2 = ( unsigned int ) V_2 ;
V_37 = ( unsigned int ) V_37 ;
}
#endif
F_34 ( V_6 , V_2 , V_37 , V_34 >> 2 ) ;
goto V_60;
case 8 :
F_32 ( V_6 , V_34 , ~ V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_17 ] , 1 ) ;
goto V_67;
#ifdef F_2
case 9 :
asm("mulhdu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_67;
#endif
case 10 :
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_17 ] , 0 ) ;
goto V_67;
case 11 :
asm("mulhwu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_67;
case 40 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_15 [ V_17 ] - V_6 -> V_15 [ V_14 ] ;
goto V_67;
#ifdef F_2
case 73 :
asm("mulhd %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_67;
#endif
case 75 :
asm("mulhw %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_67;
case 104 :
V_6 -> V_15 [ V_34 ] = - V_6 -> V_15 [ V_14 ] ;
goto V_67;
case 136 :
F_32 ( V_6 , V_34 , ~ V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_17 ] ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
case 138 :
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_17 ] ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
case 200 :
F_32 ( V_6 , V_34 , ~ V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
case 202 :
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
case 232 :
F_32 ( V_6 , V_34 , ~ V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
#ifdef F_2
case 233 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_15 [ V_14 ] * V_6 -> V_15 [ V_17 ] ;
goto V_67;
#endif
case 234 :
F_32 ( V_6 , V_34 , V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_35 & V_39 ) ;
goto V_67;
case 235 :
V_6 -> V_15 [ V_34 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] *
( unsigned int ) V_6 -> V_15 [ V_17 ] ;
goto V_67;
case 266 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_15 [ V_14 ] + V_6 -> V_15 [ V_17 ] ;
goto V_67;
#ifdef F_2
case 457 :
V_6 -> V_15 [ V_34 ] = V_6 -> V_15 [ V_14 ] / V_6 -> V_15 [ V_17 ] ;
goto V_67;
#endif
case 459 :
V_6 -> V_15 [ V_34 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] /
( unsigned int ) V_6 -> V_15 [ V_17 ] ;
goto V_67;
#ifdef F_2
case 489 :
V_6 -> V_15 [ V_34 ] = ( long int ) V_6 -> V_15 [ V_14 ] /
( long int ) V_6 -> V_15 [ V_17 ] ;
goto V_67;
#endif
case 491 :
V_6 -> V_15 [ V_34 ] = ( int ) V_6 -> V_15 [ V_14 ] /
( int ) V_6 -> V_15 [ V_17 ] ;
goto V_67;
case 26 :
asm("cntlzw %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_64;
#ifdef F_2
case 58 :
asm("cntlzd %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_64;
#endif
case 28 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] & V_6 -> V_15 [ V_17 ] ;
goto V_64;
case 60 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] & ~ V_6 -> V_15 [ V_17 ] ;
goto V_64;
case 124 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_34 ] | V_6 -> V_15 [ V_17 ] ) ;
goto V_64;
case 284 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_34 ] ^ V_6 -> V_15 [ V_17 ] ) ;
goto V_64;
case 316 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] ^ V_6 -> V_15 [ V_17 ] ;
goto V_64;
case 412 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] | ~ V_6 -> V_15 [ V_17 ] ;
goto V_64;
case 444 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] | V_6 -> V_15 [ V_17 ] ;
goto V_64;
case 476 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_34 ] & V_6 -> V_15 [ V_17 ] ) ;
goto V_64;
case 922 :
V_6 -> V_15 [ V_14 ] = ( signed short ) V_6 -> V_15 [ V_34 ] ;
goto V_64;
case 954 :
V_6 -> V_15 [ V_14 ] = ( signed char ) V_6 -> V_15 [ V_34 ] ;
goto V_64;
#ifdef F_2
case 986 :
V_6 -> V_15 [ V_14 ] = ( signed int ) V_6 -> V_15 [ V_34 ] ;
goto V_64;
#endif
case 24 :
V_52 = V_6 -> V_15 [ V_17 ] & 0x3f ;
if ( V_52 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_34 ] << V_52 ) & 0xffffffffUL ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_64;
case 536 :
V_52 = V_6 -> V_15 [ V_17 ] & 0x3f ;
if ( V_52 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_34 ] & 0xffffffffUL ) >> V_52 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_64;
case 792 :
V_52 = V_6 -> V_15 [ V_17 ] & 0x3f ;
V_55 = ( signed int ) V_6 -> V_15 [ V_34 ] ;
V_6 -> V_15 [ V_14 ] = V_55 >> ( V_52 < 32 ? V_52 : 31 ) ;
if ( V_55 < 0 && ( V_52 >= 32 || ( V_55 & ( ( 1 << V_52 ) - 1 ) ) != 0 ) )
V_6 -> V_35 |= V_39 ;
else
V_6 -> V_35 &= ~ V_39 ;
goto V_64;
case 824 :
V_52 = V_17 ;
V_55 = ( signed int ) V_6 -> V_15 [ V_34 ] ;
V_6 -> V_15 [ V_14 ] = V_55 >> V_52 ;
if ( V_55 < 0 && ( V_55 & ( ( 1 << V_52 ) - 1 ) ) != 0 )
V_6 -> V_35 |= V_39 ;
else
V_6 -> V_35 &= ~ V_39 ;
goto V_64;
#ifdef F_2
case 27 :
V_52 = V_6 -> V_15 [ V_34 ] & 0x7f ;
if ( V_52 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] << V_52 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_64;
case 539 :
V_52 = V_6 -> V_15 [ V_17 ] & 0x7f ;
if ( V_52 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_34 ] >> V_52 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_64;
case 794 :
V_52 = V_6 -> V_15 [ V_17 ] & 0x7f ;
V_55 = ( signed long int ) V_6 -> V_15 [ V_34 ] ;
V_6 -> V_15 [ V_14 ] = V_55 >> ( V_52 < 64 ? V_52 : 63 ) ;
if ( V_55 < 0 && ( V_52 >= 64 || ( V_55 & ( ( 1 << V_52 ) - 1 ) ) != 0 ) )
V_6 -> V_35 |= V_39 ;
else
V_6 -> V_35 &= ~ V_39 ;
goto V_64;
case 826 :
case 827 :
V_52 = V_17 | ( ( V_4 & 2 ) << 4 ) ;
V_55 = ( signed long int ) V_6 -> V_15 [ V_34 ] ;
V_6 -> V_15 [ V_14 ] = V_55 >> V_52 ;
if ( V_55 < 0 && ( V_55 & ( ( 1 << V_52 ) - 1 ) ) != 0 )
V_6 -> V_35 |= V_39 ;
else
V_6 -> V_35 &= ~ V_39 ;
goto V_64;
#endif
case 54 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
return 0 ;
V_20 = 0 ;
F_48 ( V_11 , V_20 , L_1 ) ;
if ( V_20 )
return 0 ;
goto V_60;
case 86 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
return 0 ;
V_20 = 0 ;
F_48 ( V_11 , V_20 , L_2 ) ;
if ( V_20 )
return 0 ;
goto V_60;
case 246 :
if ( V_34 == 0 ) {
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
F_49 ( ( void * ) V_11 ) ;
}
goto V_60;
case 278 :
if ( V_34 == 0 ) {
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
F_50 ( ( void * ) V_11 ) ;
}
goto V_60;
}
break;
}
if ( V_6 -> V_1 & V_59 )
return 0 ;
V_53 = V_6 -> V_15 [ V_14 ] ;
switch ( V_45 ) {
case 31 :
V_47 = V_4 & 0x40 ;
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 20 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 3 )
break;
V_20 = - V_25 ;
if ( ! F_4 ( V_6 , V_11 , 4 ) )
goto V_68;
V_20 = 0 ;
F_51 ( V_2 , V_11 , V_20 , L_3 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = V_2 ;
goto V_68;
case 150 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 3 )
break;
V_20 = - V_25 ;
if ( ! F_4 ( V_6 , V_11 , 4 ) )
goto V_68;
V_20 = 0 ;
F_52 ( V_6 -> V_15 [ V_34 ] , V_11 , V_20 , L_4 , V_49 ) ;
if ( ! V_20 )
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) |
( V_49 & 0xe0000000 ) |
( ( V_6 -> V_35 >> 3 ) & 0x10000000 ) ;
goto V_68;
#ifdef F_2
case 84 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 7 )
break;
V_20 = - V_25 ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
goto V_68;
V_20 = 0 ;
F_51 ( V_2 , V_11 , V_20 , L_5 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = V_2 ;
goto V_68;
case 214 :
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
if ( V_11 & 7 )
break;
V_20 = - V_25 ;
if ( ! F_4 ( V_6 , V_11 , 8 ) )
goto V_68;
V_20 = 0 ;
F_52 ( V_6 -> V_15 [ V_34 ] , V_11 , V_20 , L_6 , V_49 ) ;
if ( ! V_20 )
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) |
( V_49 & 0xe0000000 ) |
( ( V_6 -> V_35 >> 3 ) & 0x10000000 ) ;
goto V_68;
case 21 :
case 53 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
8 , V_6 ) ;
goto V_68;
#endif
case 23 :
case 55 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
4 , V_6 ) ;
goto V_68;
case 87 :
case 119 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
1 , V_6 ) ;
goto V_68;
#ifdef F_53
case 103 :
case 359 :
if ( ! ( V_6 -> V_1 & V_69 ) )
break;
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
V_20 = F_27 ( V_34 , V_70 , V_11 , V_6 ) ;
goto V_68;
case 231 :
case 487 :
if ( ! ( V_6 -> V_1 & V_69 ) )
break;
V_11 = F_9 ( V_4 , V_6 , 0 ) ;
V_20 = F_28 ( V_34 , V_71 , V_11 , V_6 ) ;
goto V_68;
#endif
#ifdef F_2
case 149 :
case 181 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , V_47 ) , 8 , V_6 ) ;
goto V_68;
#endif
case 151 :
case 183 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , V_47 ) , 4 , V_6 ) ;
goto V_68;
case 215 :
case 247 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , V_47 ) , 1 , V_6 ) ;
goto V_68;
case 279 :
case 311 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
2 , V_6 ) ;
goto V_68;
#ifdef F_2
case 341 :
case 373 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = ( signed int ) V_6 -> V_15 [ V_34 ] ;
goto V_68;
#endif
case 343 :
case 375 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_9 ( V_4 , V_6 , V_47 ) ,
2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = ( signed short ) V_6 -> V_15 [ V_34 ] ;
goto V_68;
case 407 :
case 439 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , V_47 ) , 2 , V_6 ) ;
goto V_68;
#ifdef F_2
case 532 :
V_20 = F_19 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 8 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = F_13 ( V_2 ) ;
goto V_68;
#endif
case 534 :
V_20 = F_19 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = F_12 ( V_2 ) ;
goto V_68;
#ifdef F_54
case 535 :
case 567 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_24 ( V_34 , V_73 , V_11 , 4 , V_6 ) ;
goto V_68;
case 599 :
case 631 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_24 ( V_34 , V_74 , V_11 , 8 , V_6 ) ;
goto V_68;
case 663 :
case 695 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_26 ( V_34 , V_75 , V_11 , 4 , V_6 ) ;
goto V_68;
case 727 :
case 759 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_26 ( V_34 , V_76 , V_11 , 8 , V_6 ) ;
goto V_68;
#endif
#ifdef F_2
case 660 :
V_2 = F_13 ( V_6 -> V_15 [ V_34 ] ) ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 8 , V_6 ) ;
goto V_68;
#endif
case 662 :
V_2 = F_12 ( V_6 -> V_15 [ V_34 ] ) ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 4 , V_6 ) ;
goto V_68;
case 790 :
V_20 = F_19 ( & V_2 , F_9 ( V_4 , V_6 , 0 ) , 2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = F_11 ( V_2 ) ;
goto V_68;
case 918 :
V_2 = F_11 ( V_6 -> V_15 [ V_34 ] ) ;
V_20 = F_23 ( V_2 , F_9 ( V_4 , V_6 , 0 ) , 2 , V_6 ) ;
goto V_68;
#ifdef F_55
case 844 :
case 876 :
if ( ! ( V_6 -> V_1 & V_77 ) )
break;
V_34 |= ( V_4 & 1 ) << 5 ;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_29 ( V_34 , V_78 , V_11 , V_6 ) ;
goto V_68;
case 972 :
case 1004 :
if ( ! ( V_6 -> V_1 & V_77 ) )
break;
V_34 |= ( V_4 & 1 ) << 5 ;
V_11 = F_9 ( V_4 , V_6 , V_47 ) ;
V_20 = F_30 ( V_34 , V_79 , V_11 , V_6 ) ;
goto V_68;
#endif
}
break;
case 32 :
case 33 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_7 ( V_4 , V_6 ) , 4 , V_6 ) ;
goto V_68;
case 34 :
case 35 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_7 ( V_4 , V_6 ) , 1 , V_6 ) ;
goto V_68;
case 36 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_7 ( V_4 , V_6 ) , 4 , V_6 ) ;
goto V_68;
case 37 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_54 = F_7 ( V_4 , V_6 ) ;
if ( ( V_14 == 1 ) && ! ( V_6 -> V_1 & V_65 ) \
&& ( V_54 >= ( V_6 -> V_15 [ 1 ] - V_80 ) ) ) {
#ifdef F_56
if ( V_54 - V_80 <= V_81 -> V_82 . V_83 ) {
F_57 ( V_84 L_7 ) ;
V_20 = - V_85 ;
break;
}
#endif
F_58 ( F_59 ( V_86 ) ) ;
F_60 ( V_86 ) ;
V_20 = 0 ;
} else
V_20 = F_23 ( V_2 , V_54 , 4 , V_6 ) ;
goto V_68;
case 38 :
case 39 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_7 ( V_4 , V_6 ) , 1 , V_6 ) ;
goto V_68;
case 40 :
case 41 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
goto V_68;
case 42 :
case 43 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = ( signed short ) V_6 -> V_15 [ V_34 ] ;
goto V_68;
case 44 :
case 45 :
V_2 = V_6 -> V_15 [ V_34 ] ;
V_20 = F_23 ( V_2 , F_7 ( V_4 , V_6 ) , 2 , V_6 ) ;
goto V_68;
case 46 :
V_14 = ( V_4 >> 16 ) & 0x1f ;
if ( V_14 >= V_34 )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
do {
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , V_11 , 4 , V_6 ) ;
if ( V_20 )
return 0 ;
V_11 += 4 ;
} while ( ++ V_34 < 32 );
goto V_60;
case 47 :
V_11 = F_7 ( V_4 , V_6 ) ;
do {
V_20 = F_23 ( V_6 -> V_15 [ V_34 ] , V_11 , 4 , V_6 ) ;
if ( V_20 )
return 0 ;
V_11 += 4 ;
} while ( ++ V_34 < 32 );
goto V_60;
#ifdef F_61
case 48 :
case 49 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_24 ( V_34 , V_73 , V_11 , 4 , V_6 ) ;
goto V_68;
case 50 :
case 51 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_24 ( V_34 , V_74 , V_11 , 8 , V_6 ) ;
goto V_68;
case 52 :
case 53 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_26 ( V_34 , V_75 , V_11 , 4 , V_6 ) ;
goto V_68;
case 54 :
case 55 :
if ( ! ( V_6 -> V_1 & V_72 ) )
break;
V_11 = F_7 ( V_4 , V_6 ) ;
V_20 = F_26 ( V_34 , V_76 , V_11 , 8 , V_6 ) ;
goto V_68;
#endif
#ifdef F_2
case 58 :
switch ( V_4 & 3 ) {
case 0 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_8 ( V_4 , V_6 ) ,
8 , V_6 ) ;
goto V_68;
case 1 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_8 ( V_4 , V_6 ) ,
8 , V_6 ) ;
goto V_68;
case 2 :
V_20 = F_19 ( & V_6 -> V_15 [ V_34 ] , F_8 ( V_4 , V_6 ) ,
4 , V_6 ) ;
if ( ! V_20 )
V_6 -> V_15 [ V_34 ] = ( signed int ) V_6 -> V_15 [ V_34 ] ;
goto V_68;
}
break;
case 62 :
V_2 = V_6 -> V_15 [ V_34 ] ;
switch ( V_4 & 3 ) {
case 0 :
V_20 = F_23 ( V_2 , F_8 ( V_4 , V_6 ) , 8 , V_6 ) ;
goto V_68;
case 1 :
V_20 = F_23 ( V_2 , F_8 ( V_4 , V_6 ) , 8 , V_6 ) ;
goto V_68;
}
break;
#endif
}
V_20 = - V_85 ;
V_68:
if ( V_20 ) {
V_6 -> V_15 [ V_14 ] = V_53 ;
return 0 ;
}
V_60:
V_6 -> V_56 = F_1 ( V_6 -> V_1 , V_6 -> V_56 + 4 ) ;
return 1 ;
V_64:
if ( V_4 & 1 )
F_31 ( V_6 , V_14 ) ;
goto V_60;
V_67:
if ( V_4 & 1 )
F_31 ( V_6 , V_34 ) ;
goto V_60;
}
