static T_1 unsigned long F_1 ( unsigned long V_1 ,
unsigned long V_2 )
{
#ifdef F_2
if ( ( V_1 & V_3 ) == 0 )
V_2 &= 0xffffffffUL ;
#endif
return V_2 ;
}
static T_1 int F_3 ( unsigned int V_4 , struct V_5 * V_6 )
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
static T_1 long F_4 ( struct V_5 * V_6 , unsigned long V_11 , int V_12 )
{
if ( ! F_5 ( V_6 ) )
return 1 ;
return F_6 ( V_11 , V_12 , V_13 ) ;
}
static T_1 unsigned long F_7 ( unsigned int V_4 , struct V_5 * V_6 )
{
int V_14 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_11 = ( signed short ) V_4 ;
if ( V_14 )
V_11 += V_6 -> V_15 [ V_14 ] ;
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static T_1 unsigned long F_8 ( unsigned int V_4 , struct V_5 * V_6 )
{
int V_14 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_11 = ( signed short ) ( V_4 & ~ 3 ) ;
if ( V_14 )
V_11 += V_6 -> V_15 [ V_14 ] ;
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static T_1 unsigned long F_9 ( unsigned int V_4 ,
struct V_5 * V_6 )
{
int V_14 , V_16 ;
unsigned long V_11 ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_16 = ( V_4 >> 11 ) & 0x1f ;
V_11 = V_6 -> V_15 [ V_16 ] ;
if ( V_14 )
V_11 += V_6 -> V_15 [ V_14 ] ;
return F_1 ( V_6 -> V_1 , V_11 ) ;
}
static T_1 unsigned long F_10 ( unsigned long V_17 )
{
V_17 |= sizeof( unsigned long ) ;
return V_17 & - V_17 ;
}
static T_1 unsigned long F_11 ( unsigned long V_17 )
{
return ( ( V_17 >> 8 ) & 0xff ) | ( ( V_17 & 0xff ) << 8 ) ;
}
static T_1 unsigned long F_12 ( unsigned long V_17 )
{
return ( ( V_17 >> 24 ) & 0xff ) | ( ( V_17 >> 8 ) & 0xff00 ) |
( ( V_17 & 0xff00 ) << 8 ) | ( ( V_17 & 0xff ) << 24 ) ;
}
static T_1 unsigned long F_13 ( unsigned long V_17 )
{
return ( F_12 ( V_17 ) << 32 ) | F_12 ( V_17 >> 32 ) ;
}
static T_1 int F_14 ( unsigned long * V_18 ,
unsigned long V_11 , int V_12 )
{
int V_19 = 0 ;
unsigned long V_17 = 0 ;
switch ( V_12 ) {
case 1 :
V_19 = F_15 ( V_17 , ( unsigned char V_20 * ) V_11 ) ;
break;
case 2 :
V_19 = F_15 ( V_17 , ( unsigned short V_20 * ) V_11 ) ;
break;
case 4 :
V_19 = F_15 ( V_17 , ( unsigned int V_20 * ) V_11 ) ;
break;
#ifdef F_2
case 8 :
V_19 = F_15 ( V_17 , ( unsigned long V_20 * ) V_11 ) ;
break;
#endif
}
if ( ! V_19 )
* V_18 = V_17 ;
return V_19 ;
}
static T_1 int F_16 ( unsigned long * V_18 ,
unsigned long V_11 , int V_12 , struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_17 , V_21 , V_22 ;
#ifdef F_17
int V_23 = V_12 ;
#endif
V_17 = 0 ;
for (; V_12 > 0 ; V_12 -= V_22 ) {
#ifdef F_17
V_22 = 1 ;
#endif
#ifdef F_18
V_22 = F_10 ( V_11 ) ;
#endif
if ( V_22 > V_12 )
V_22 = F_10 ( V_12 ) ;
V_19 = F_14 ( & V_21 , V_11 , V_22 ) ;
if ( V_19 )
return V_19 ;
V_17 = ( V_17 << ( 8 * V_22 ) ) + V_21 ;
V_11 += V_22 ;
}
#ifdef F_17
switch ( V_23 ) {
case 2 :
* V_18 = F_11 ( V_17 ) ;
break;
case 4 :
* V_18 = F_12 ( V_17 ) ;
break;
#ifdef F_2
case 8 :
* V_18 = F_13 ( V_17 ) ;
break;
#endif
}
#endif
#ifdef F_18
* V_18 = V_17 ;
#endif
return 0 ;
}
static int F_19 ( unsigned long * V_18 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_14 ( V_18 , V_11 , V_12 ) ;
return F_16 ( V_18 , V_11 , V_12 , V_6 ) ;
}
static T_1 int F_20 ( unsigned long V_2 ,
unsigned long V_11 , int V_12 )
{
int V_19 = 0 ;
switch ( V_12 ) {
case 1 :
V_19 = F_21 ( V_2 , ( unsigned char V_20 * ) V_11 ) ;
break;
case 2 :
V_19 = F_21 ( V_2 , ( unsigned short V_20 * ) V_11 ) ;
break;
case 4 :
V_19 = F_21 ( V_2 , ( unsigned int V_20 * ) V_11 ) ;
break;
#ifdef F_2
case 8 :
V_19 = F_21 ( V_2 , ( unsigned long V_20 * ) V_11 ) ;
break;
#endif
}
return V_19 ;
}
static T_1 int F_22 ( unsigned long V_2 ,
unsigned long V_11 , int V_12 , struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_22 ;
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
for (; V_12 > 0 ; V_12 -= V_22 ) {
#ifdef F_17
V_22 = 1 ;
#endif
#ifdef F_18
V_22 = F_10 ( V_11 ) ;
#endif
if ( V_22 > V_12 )
V_22 = F_10 ( V_12 ) ;
V_19 = F_20 ( V_2 >> ( V_12 - V_22 ) * 8 , V_11 , V_22 ) ;
if ( V_19 )
return V_19 ;
V_11 += V_22 ;
}
return 0 ;
}
static int F_23 ( unsigned long V_2 , unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & ( V_12 - 1 ) ) == 0 )
return F_20 ( V_2 , V_11 , V_12 ) ;
return F_22 ( V_2 , V_11 , V_12 , V_6 ) ;
}
static int F_24 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_19 ;
union {
double V_26 ;
unsigned long V_27 [ 2 ] ;
struct {
#ifdef F_18
unsigned V_28 ;
unsigned V_29 ;
#endif
#ifdef F_17
unsigned V_29 ;
unsigned V_28 ;
#endif
} V_30 ;
} V_31 ;
unsigned long V_32 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_25 , V_11 ) ;
V_32 = ( unsigned long ) & V_31 . V_27 ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
V_19 = F_16 ( & V_31 . V_27 [ 0 ] , V_11 , V_12 , V_6 ) ;
if ( V_12 == 4 )
V_32 = ( unsigned long ) & ( V_31 . V_30 . V_29 ) ;
} else {
V_19 = F_16 ( & V_31 . V_27 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_19 )
V_19 = F_16 ( & V_31 . V_27 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
if ( V_19 )
return V_19 ;
return (* F_25)( V_25 , V_32 ) ;
}
static int F_26 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , int V_12 ,
struct V_5 * V_6 )
{
int V_19 ;
union {
double V_26 ;
unsigned long V_27 [ 2 ] ;
struct {
#ifdef F_18
unsigned V_28 ;
unsigned V_29 ;
#endif
#ifdef F_17
unsigned V_29 ;
unsigned V_28 ;
#endif
} V_30 ;
} V_31 ;
unsigned long V_32 ;
if ( ! F_4 ( V_6 , V_11 , V_12 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_25 , V_11 ) ;
V_32 = ( unsigned long ) & V_31 . V_27 [ 0 ] ;
if (sizeof( unsigned long ) == 8 || V_12 == 4 ) {
if ( V_12 == 4 )
V_32 = ( unsigned long ) & ( V_31 . V_30 . V_29 ) ;
V_19 = (* F_25)( V_25 , V_32 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_22 ( V_31 . V_27 [ 0 ] , V_11 , V_12 , V_6 ) ;
} else {
V_19 = (* F_25)( V_25 , V_32 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_22 ( V_31 . V_27 [ 0 ] , V_11 , 4 , V_6 ) ;
if ( ! V_19 )
V_19 = F_22 ( V_31 . V_27 [ 1 ] , V_11 + 4 , 4 , V_6 ) ;
}
return V_19 ;
}
static T_1 int F_27 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_24 ;
return (* F_25)( V_25 , V_11 ) ;
}
static T_1 int F_28 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_11 & ~ 0xfUL , 16 ) )
return - V_24 ;
return (* F_25)( V_25 , V_11 ) ;
}
static T_1 int F_29 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_25 , V_11 ) ;
V_19 = F_16 ( & V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_19 )
V_19 = F_16 ( & V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
if ( ! V_19 )
V_19 = (* F_25)( V_25 , ( unsigned long ) & V_2 [ 0 ] ) ;
return V_19 ;
}
static T_1 int F_30 ( int V_25 , int (* F_25)( int , unsigned long ) ,
unsigned long V_11 , struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_2 [ 2 ] ;
if ( ! F_4 ( V_6 , V_11 , 16 ) )
return - V_24 ;
if ( ( V_11 & 3 ) == 0 )
return (* F_25)( V_25 , V_11 ) ;
V_19 = (* F_25)( V_25 , ( unsigned long ) & V_2 [ 0 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_22 ( V_2 [ 0 ] , V_11 , 8 , V_6 ) ;
if ( ! V_19 )
V_19 = F_22 ( V_2 [ 1 ] , V_11 + 8 , 8 , V_6 ) ;
return V_19 ;
}
static T_1 void F_31 ( struct V_5 * V_6 , int V_33 )
{
long V_2 = V_6 -> V_15 [ V_33 ] ;
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) | ( ( V_6 -> V_34 >> 3 ) & 0x10000000 ) ;
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
static T_1 void F_32 ( struct V_5 * V_6 , int V_33 ,
unsigned long V_35 , unsigned long V_36 ,
unsigned long V_37 )
{
unsigned long V_2 = V_35 + V_36 ;
if ( V_37 )
++ V_2 ;
V_6 -> V_15 [ V_33 ] = V_2 ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) ) {
V_2 = ( unsigned int ) V_2 ;
V_35 = ( unsigned int ) V_35 ;
}
#endif
if ( V_2 < V_35 || ( V_37 && V_2 == V_35 ) )
V_6 -> V_34 |= V_38 ;
else
V_6 -> V_34 &= ~ V_38 ;
}
static T_1 void F_33 ( struct V_5 * V_6 , long V_39 , long V_40 ,
int V_41 )
{
unsigned int V_42 , V_43 ;
V_42 = ( V_6 -> V_34 >> 31 ) & 1 ;
if ( V_39 < V_40 )
V_42 |= 8 ;
else if ( V_39 > V_40 )
V_42 |= 4 ;
else
V_42 |= 2 ;
V_43 = ( 7 - V_41 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_43 ) ) | ( V_42 << V_43 ) ;
}
static T_1 void F_34 ( struct V_5 * V_6 , unsigned long V_39 ,
unsigned long V_40 , int V_41 )
{
unsigned int V_42 , V_43 ;
V_42 = ( V_6 -> V_34 >> 31 ) & 1 ;
if ( V_39 < V_40 )
V_42 |= 8 ;
else if ( V_39 > V_40 )
V_42 |= 4 ;
else
V_42 |= 2 ;
V_43 = ( 7 - V_41 ) * 4 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xf << V_43 ) ) | ( V_42 << V_43 ) ;
}
static T_1 int F_35 ( long V_39 , long V_40 )
{
int V_44 = 0 ;
if ( V_39 < V_40 )
V_44 |= 0x10 ;
else if ( V_39 > V_40 )
V_44 |= 0x08 ;
else
V_44 |= 0x04 ;
if ( ( unsigned long ) V_39 < ( unsigned long ) V_40 )
V_44 |= 0x02 ;
else if ( ( unsigned long ) V_39 > ( unsigned long ) V_40 )
V_44 |= 0x01 ;
return V_44 ;
}
int F_36 ( struct V_45 * V_46 , struct V_5 * V_6 ,
unsigned int V_4 )
{
unsigned int V_47 , V_14 , V_16 , V_33 , V_48 , V_49 ;
unsigned long int V_50 ;
unsigned long int V_2 , V_36 ;
unsigned int V_51 , V_52 , V_53 ;
long V_54 ;
V_46 -> type = V_55 ;
V_47 = V_4 >> 26 ;
switch ( V_47 ) {
case 16 :
V_46 -> type = V_56 ;
V_50 = ( signed short ) ( V_4 & 0xfffc ) ;
if ( ( V_4 & 2 ) == 0 )
V_50 += V_6 -> V_57 ;
V_6 -> V_57 += 4 ;
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_6 -> V_57 ) ;
if ( V_4 & 1 )
V_6 -> V_58 = V_6 -> V_57 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_50 ) ;
return 1 ;
#ifdef F_37
case 17 :
if ( ( V_4 & 0xfe2 ) == 2 )
V_46 -> type = V_59 ;
else
V_46 -> type = V_60 ;
return 0 ;
#endif
case 18 :
V_46 -> type = V_56 ;
V_50 = V_4 & 0x03fffffc ;
if ( V_50 & 0x02000000 )
V_50 -= 0x04000000 ;
if ( ( V_4 & 2 ) == 0 )
V_50 += V_6 -> V_57 ;
if ( V_4 & 1 )
V_6 -> V_58 = F_1 ( V_6 -> V_1 , V_6 -> V_57 + 4 ) ;
V_50 = F_1 ( V_6 -> V_1 , V_50 ) ;
V_6 -> V_57 = V_50 ;
return 1 ;
case 19 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 0 :
V_33 = ( V_4 >> 21 ) & 0x1c ;
V_14 = ( V_4 >> 16 ) & 0x1c ;
V_2 = ( V_6 -> V_10 >> V_14 ) & 0xf ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 0xfUL << V_33 ) ) | ( V_2 << V_33 ) ;
goto V_61;
case 16 :
case 528 :
V_46 -> type = V_56 ;
V_50 = ( V_4 & 0x400 ) ? V_6 -> V_9 : V_6 -> V_58 ;
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_6 -> V_57 + 4 ) ;
V_50 = F_1 ( V_6 -> V_1 , V_50 ) ;
if ( V_4 & 1 )
V_6 -> V_58 = V_6 -> V_57 ;
if ( F_3 ( V_4 , V_6 ) )
V_6 -> V_57 = V_50 ;
return 1 ;
case 18 :
if ( V_6 -> V_1 & V_62 )
goto V_63;
V_46 -> type = V_64 ;
return 0 ;
case 150 :
V_46 -> type = V_65 ;
F_38 () ;
goto V_61;
case 33 :
case 129 :
case 193 :
case 225 :
case 257 :
case 289 :
case 417 :
case 449 :
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_16 = ( V_4 >> 11 ) & 0x1f ;
V_33 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_6 -> V_10 >> ( 31 - V_14 ) ) & 1 ;
V_16 = ( V_6 -> V_10 >> ( 31 - V_16 ) ) & 1 ;
V_2 = ( V_4 >> ( 6 + V_14 * 2 + V_16 ) ) & 1 ;
V_6 -> V_10 = ( V_6 -> V_10 & ~ ( 1UL << ( 31 - V_33 ) ) ) |
( V_2 << ( 31 - V_33 ) ) ;
goto V_61;
}
break;
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 598 :
V_46 -> type = V_65 ;
#ifdef F_2
switch ( ( V_4 >> 21 ) & 3 ) {
case 1 :
asm volatile("lwsync" : : : "memory");
goto V_61;
case 2 :
asm volatile("ptesync" : : : "memory");
goto V_61;
}
#endif
V_51 () ;
goto V_61;
case 854 :
V_46 -> type = V_65 ;
F_39 () ;
goto V_61;
}
break;
}
if ( ! F_40 ( V_6 ) )
return 0 ;
V_33 = ( V_4 >> 21 ) & 0x1f ;
V_14 = ( V_4 >> 16 ) & 0x1f ;
V_16 = ( V_4 >> 11 ) & 0x1f ;
switch ( V_47 ) {
#ifdef F_2
case 2 :
if ( V_33 & F_35 ( V_6 -> V_15 [ V_14 ] , ( short ) V_4 ) )
goto V_66;
goto V_61;
#endif
case 3 :
if ( V_33 & F_35 ( ( int ) V_6 -> V_15 [ V_14 ] , ( short ) V_4 ) )
goto V_66;
goto V_61;
case 7 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_15 [ V_14 ] * ( short ) V_4 ;
goto V_61;
case 8 :
V_50 = ( short ) V_4 ;
F_32 ( V_6 , V_33 , ~ V_6 -> V_15 [ V_14 ] , V_50 , 1 ) ;
goto V_61;
case 10 :
V_50 = ( unsigned short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_33 & 1 ) == 0 )
V_2 = ( unsigned int ) V_2 ;
#endif
F_34 ( V_6 , V_2 , V_50 , V_33 >> 2 ) ;
goto V_61;
case 11 :
V_50 = ( short ) V_4 ;
V_2 = V_6 -> V_15 [ V_14 ] ;
#ifdef F_2
if ( ( V_33 & 1 ) == 0 )
V_2 = ( int ) V_2 ;
#endif
F_33 ( V_6 , V_2 , V_50 , V_33 >> 2 ) ;
goto V_61;
case 12 :
V_50 = ( short ) V_4 ;
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] , V_50 , 0 ) ;
goto V_61;
case 13 :
V_50 = ( short ) V_4 ;
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] , V_50 , 0 ) ;
F_31 ( V_6 , V_33 ) ;
goto V_61;
case 14 :
V_50 = ( short ) V_4 ;
if ( V_14 )
V_50 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_33 ] = V_50 ;
goto V_61;
case 15 :
V_50 = ( ( short ) V_4 ) << 16 ;
if ( V_14 )
V_50 += V_6 -> V_15 [ V_14 ] ;
V_6 -> V_15 [ V_33 ] = V_50 ;
goto V_61;
case 20 :
V_51 = ( V_4 >> 6 ) & 0x1f ;
V_52 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_41 ( V_6 -> V_15 [ V_33 ] ) ;
V_50 = F_42 ( V_51 , V_52 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_50 ) | ( F_43 ( V_2 , V_16 ) & V_50 ) ;
goto V_67;
case 21 :
V_51 = ( V_4 >> 6 ) & 0x1f ;
V_52 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_41 ( V_6 -> V_15 [ V_33 ] ) ;
V_6 -> V_15 [ V_14 ] = F_43 ( V_2 , V_16 ) & F_42 ( V_51 , V_52 ) ;
goto V_67;
case 23 :
V_51 = ( V_4 >> 6 ) & 0x1f ;
V_52 = ( V_4 >> 1 ) & 0x1f ;
V_16 = V_6 -> V_15 [ V_16 ] & 0x1f ;
V_2 = F_41 ( V_6 -> V_15 [ V_33 ] ) ;
V_6 -> V_15 [ V_14 ] = F_43 ( V_2 , V_16 ) & F_42 ( V_51 , V_52 ) ;
goto V_67;
case 24 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] | V_50 ;
goto V_61;
case 25 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] | ( V_50 << 16 ) ;
goto V_61;
case 26 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] ^ V_50 ;
goto V_61;
case 27 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] ^ ( V_50 << 16 ) ;
goto V_61;
case 28 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] & V_50 ;
F_31 ( V_6 , V_14 ) ;
goto V_61;
case 29 :
V_50 = ( unsigned short ) V_4 ;
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] & ( V_50 << 16 ) ;
F_31 ( V_6 , V_14 ) ;
goto V_61;
#ifdef F_2
case 30 :
V_51 = ( ( V_4 >> 6 ) & 0x1f ) | ( V_4 & 0x20 ) ;
V_2 = V_6 -> V_15 [ V_33 ] ;
if ( ( V_4 & 0x10 ) == 0 ) {
V_53 = V_16 | ( ( V_4 & 2 ) << 4 ) ;
V_2 = F_43 ( V_2 , V_53 ) ;
switch ( ( V_4 >> 2 ) & 3 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_44 ( V_51 ) ;
goto V_67;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_45 ( V_51 ) ;
goto V_67;
case 2 :
V_6 -> V_15 [ V_14 ] = V_2 & F_46 ( V_51 , 63 - V_53 ) ;
goto V_67;
case 3 :
V_50 = F_46 ( V_51 , 63 - V_53 ) ;
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_14 ] & ~ V_50 ) |
( V_2 & V_50 ) ;
goto V_67;
}
} else {
V_53 = V_6 -> V_15 [ V_16 ] & 0x3f ;
V_2 = F_43 ( V_2 , V_53 ) ;
switch ( ( V_4 >> 1 ) & 7 ) {
case 0 :
V_6 -> V_15 [ V_14 ] = V_2 & F_44 ( V_51 ) ;
goto V_67;
case 1 :
V_6 -> V_15 [ V_14 ] = V_2 & F_45 ( V_51 ) ;
goto V_67;
}
}
#endif
break;
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 4 :
if ( V_33 == 0x1f ||
( V_33 & F_35 ( ( int ) V_6 -> V_15 [ V_14 ] ,
( int ) V_6 -> V_15 [ V_16 ] ) ) )
goto V_66;
goto V_61;
#ifdef F_2
case 68 :
if ( V_33 & F_35 ( V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_16 ] ) )
goto V_66;
goto V_61;
#endif
case 83 :
if ( V_6 -> V_1 & V_62 )
goto V_63;
V_46 -> type = V_68 ;
V_46 -> V_69 = V_33 ;
return 0 ;
case 146 :
if ( V_6 -> V_1 & V_62 )
goto V_63;
V_46 -> type = V_70 ;
V_46 -> V_69 = V_33 ;
V_46 -> V_2 = 0xffffffff & ~ ( V_71 | V_72 ) ;
return 0 ;
#ifdef F_37
case 178 :
if ( V_6 -> V_1 & V_62 )
goto V_63;
V_46 -> type = V_70 ;
V_46 -> V_69 = V_33 ;
V_50 = ( V_4 & 0x10000 ) ? 0x8002 : 0xefffffffffffeffeUL ;
V_46 -> V_2 = V_50 ;
return 0 ;
#endif
case 19 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_10 ;
V_6 -> V_15 [ V_33 ] &= 0xffffffffUL ;
goto V_61;
case 144 :
V_50 = 0xf0000000UL ;
V_2 = V_6 -> V_15 [ V_33 ] ;
for ( V_53 = 0 ; V_53 < 8 ; ++ V_53 ) {
if ( V_4 & ( 0x80000 >> V_53 ) )
V_6 -> V_10 = ( V_6 -> V_10 & ~ V_50 ) |
( V_2 & V_50 ) ;
V_50 >>= 4 ;
}
goto V_61;
case 339 :
V_48 = ( ( V_4 >> 16 ) & 0x1f ) | ( ( V_4 >> 6 ) & 0x3e0 ) ;
switch ( V_48 ) {
case V_73 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_34 ;
V_6 -> V_15 [ V_33 ] &= 0xffffffffUL ;
goto V_61;
case V_74 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_58 ;
goto V_61;
case V_75 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_9 ;
goto V_61;
default:
V_46 -> type = V_76 ;
V_46 -> V_69 = V_33 ;
V_46 -> V_48 = V_48 ;
return 0 ;
}
break;
case 467 :
V_48 = ( ( V_4 >> 16 ) & 0x1f ) | ( ( V_4 >> 6 ) & 0x3e0 ) ;
switch ( V_48 ) {
case V_73 :
V_6 -> V_34 = ( V_6 -> V_15 [ V_33 ] & 0xffffffffUL ) ;
goto V_61;
case V_74 :
V_6 -> V_58 = V_6 -> V_15 [ V_33 ] ;
goto V_61;
case V_75 :
V_6 -> V_9 = V_6 -> V_15 [ V_33 ] ;
goto V_61;
default:
V_46 -> type = V_77 ;
V_46 -> V_2 = V_6 -> V_15 [ V_33 ] ;
V_46 -> V_48 = V_48 ;
return 0 ;
}
break;
case 0 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_36 = V_6 -> V_15 [ V_16 ] ;
#ifdef F_2
if ( ( V_33 & 1 ) == 0 ) {
V_2 = ( int ) V_2 ;
V_36 = ( int ) V_36 ;
}
#endif
F_33 ( V_6 , V_2 , V_36 , V_33 >> 2 ) ;
goto V_61;
case 32 :
V_2 = V_6 -> V_15 [ V_14 ] ;
V_36 = V_6 -> V_15 [ V_16 ] ;
#ifdef F_2
if ( ( V_33 & 1 ) == 0 ) {
V_2 = ( unsigned int ) V_2 ;
V_36 = ( unsigned int ) V_36 ;
}
#endif
F_34 ( V_6 , V_2 , V_36 , V_33 >> 2 ) ;
goto V_61;
case 8 :
F_32 ( V_6 , V_33 , ~ V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_16 ] , 1 ) ;
goto V_78;
#ifdef F_2
case 9 :
asm("mulhdu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_78;
#endif
case 10 :
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] ,
V_6 -> V_15 [ V_16 ] , 0 ) ;
goto V_78;
case 11 :
asm("mulhwu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_78;
case 40 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_15 [ V_16 ] - V_6 -> V_15 [ V_14 ] ;
goto V_78;
#ifdef F_2
case 73 :
asm("mulhd %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_78;
#endif
case 75 :
asm("mulhw %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_78;
case 104 :
V_6 -> V_15 [ V_33 ] = - V_6 -> V_15 [ V_14 ] ;
goto V_78;
case 136 :
F_32 ( V_6 , V_33 , ~ V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_16 ] ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
case 138 :
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] , V_6 -> V_15 [ V_16 ] ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
case 200 :
F_32 ( V_6 , V_33 , ~ V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
case 202 :
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] , 0L ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
case 232 :
F_32 ( V_6 , V_33 , ~ V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
#ifdef F_2
case 233 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_15 [ V_14 ] * V_6 -> V_15 [ V_16 ] ;
goto V_78;
#endif
case 234 :
F_32 ( V_6 , V_33 , V_6 -> V_15 [ V_14 ] , - 1L ,
V_6 -> V_34 & V_38 ) ;
goto V_78;
case 235 :
V_6 -> V_15 [ V_33 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] *
( unsigned int ) V_6 -> V_15 [ V_16 ] ;
goto V_78;
case 266 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_15 [ V_14 ] + V_6 -> V_15 [ V_16 ] ;
goto V_78;
#ifdef F_2
case 457 :
V_6 -> V_15 [ V_33 ] = V_6 -> V_15 [ V_14 ] / V_6 -> V_15 [ V_16 ] ;
goto V_78;
#endif
case 459 :
V_6 -> V_15 [ V_33 ] = ( unsigned int ) V_6 -> V_15 [ V_14 ] /
( unsigned int ) V_6 -> V_15 [ V_16 ] ;
goto V_78;
#ifdef F_2
case 489 :
V_6 -> V_15 [ V_33 ] = ( long int ) V_6 -> V_15 [ V_14 ] /
( long int ) V_6 -> V_15 [ V_16 ] ;
goto V_78;
#endif
case 491 :
V_6 -> V_15 [ V_33 ] = ( int ) V_6 -> V_15 [ V_14 ] /
( int ) V_6 -> V_15 [ V_16 ] ;
goto V_78;
case 26 :
asm("cntlzw %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_67;
#ifdef F_2
case 58 :
asm("cntlzd %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto V_67;
#endif
case 28 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] & V_6 -> V_15 [ V_16 ] ;
goto V_67;
case 60 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] & ~ V_6 -> V_15 [ V_16 ] ;
goto V_67;
case 124 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_33 ] | V_6 -> V_15 [ V_16 ] ) ;
goto V_67;
case 284 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_33 ] ^ V_6 -> V_15 [ V_16 ] ) ;
goto V_67;
case 316 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] ^ V_6 -> V_15 [ V_16 ] ;
goto V_67;
case 412 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] | ~ V_6 -> V_15 [ V_16 ] ;
goto V_67;
case 444 :
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] | V_6 -> V_15 [ V_16 ] ;
goto V_67;
case 476 :
V_6 -> V_15 [ V_14 ] = ~ ( V_6 -> V_15 [ V_33 ] & V_6 -> V_15 [ V_16 ] ) ;
goto V_67;
case 922 :
V_6 -> V_15 [ V_14 ] = ( signed short ) V_6 -> V_15 [ V_33 ] ;
goto V_67;
case 954 :
V_6 -> V_15 [ V_14 ] = ( signed char ) V_6 -> V_15 [ V_33 ] ;
goto V_67;
#ifdef F_2
case 986 :
V_6 -> V_15 [ V_14 ] = ( signed int ) V_6 -> V_15 [ V_33 ] ;
goto V_67;
#endif
case 24 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x3f ;
if ( V_53 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_33 ] << V_53 ) & 0xffffffffUL ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_67;
case 536 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x3f ;
if ( V_53 < 32 )
V_6 -> V_15 [ V_14 ] = ( V_6 -> V_15 [ V_33 ] & 0xffffffffUL ) >> V_53 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_67;
case 792 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x3f ;
V_54 = ( signed int ) V_6 -> V_15 [ V_33 ] ;
V_6 -> V_15 [ V_14 ] = V_54 >> ( V_53 < 32 ? V_53 : 31 ) ;
if ( V_54 < 0 && ( V_53 >= 32 || ( V_54 & ( ( 1ul << V_53 ) - 1 ) ) != 0 ) )
V_6 -> V_34 |= V_38 ;
else
V_6 -> V_34 &= ~ V_38 ;
goto V_67;
case 824 :
V_53 = V_16 ;
V_54 = ( signed int ) V_6 -> V_15 [ V_33 ] ;
V_6 -> V_15 [ V_14 ] = V_54 >> V_53 ;
if ( V_54 < 0 && ( V_54 & ( ( 1ul << V_53 ) - 1 ) ) != 0 )
V_6 -> V_34 |= V_38 ;
else
V_6 -> V_34 &= ~ V_38 ;
goto V_67;
#ifdef F_2
case 27 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x7f ;
if ( V_53 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] << V_53 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_67;
case 539 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x7f ;
if ( V_53 < 64 )
V_6 -> V_15 [ V_14 ] = V_6 -> V_15 [ V_33 ] >> V_53 ;
else
V_6 -> V_15 [ V_14 ] = 0 ;
goto V_67;
case 794 :
V_53 = V_6 -> V_15 [ V_16 ] & 0x7f ;
V_54 = ( signed long int ) V_6 -> V_15 [ V_33 ] ;
V_6 -> V_15 [ V_14 ] = V_54 >> ( V_53 < 64 ? V_53 : 63 ) ;
if ( V_54 < 0 && ( V_53 >= 64 || ( V_54 & ( ( 1ul << V_53 ) - 1 ) ) != 0 ) )
V_6 -> V_34 |= V_38 ;
else
V_6 -> V_34 &= ~ V_38 ;
goto V_67;
case 826 :
case 827 :
V_53 = V_16 | ( ( V_4 & 2 ) << 4 ) ;
V_54 = ( signed long int ) V_6 -> V_15 [ V_33 ] ;
V_6 -> V_15 [ V_14 ] = V_54 >> V_53 ;
if ( V_54 < 0 && ( V_54 & ( ( 1ul << V_53 ) - 1 ) ) != 0 )
V_6 -> V_34 |= V_38 ;
else
V_6 -> V_34 &= ~ V_38 ;
goto V_67;
#endif
case 54 :
V_46 -> type = F_47 ( V_79 , V_80 , 0 ) ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
return 0 ;
case 86 :
V_46 -> type = F_47 ( V_79 , V_81 , 0 ) ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
return 0 ;
case 246 :
V_46 -> type = F_47 ( V_79 , V_82 , 0 ) ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
V_46 -> V_69 = V_33 ;
return 0 ;
case 278 :
V_46 -> type = F_47 ( V_79 , V_82 , 0 ) ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
V_46 -> V_69 = V_33 ;
return 0 ;
case 982 :
V_46 -> type = F_47 ( V_79 , V_83 , 0 ) ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
return 0 ;
}
break;
}
V_46 -> type = V_60 ;
V_46 -> V_84 = V_14 ;
V_46 -> V_69 = V_33 ;
V_46 -> V_2 = V_6 -> V_15 [ V_33 ] ;
V_49 = ( V_4 >> 20 ) & V_85 ;
switch ( V_47 ) {
case 31 :
V_49 = V_4 & V_85 ;
V_46 -> V_11 = F_9 ( V_4 , V_6 ) ;
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 20 :
V_46 -> type = F_47 ( V_86 , 0 , 4 ) ;
break;
case 150 :
V_46 -> type = F_47 ( V_87 , 0 , 4 ) ;
break;
#ifdef F_2
case 84 :
V_46 -> type = F_47 ( V_86 , 0 , 8 ) ;
break;
case 214 :
V_46 -> type = F_47 ( V_87 , 0 , 8 ) ;
break;
case 21 :
case 53 :
V_46 -> type = F_47 ( V_88 , V_49 , 8 ) ;
break;
#endif
case 23 :
case 55 :
V_46 -> type = F_47 ( V_88 , V_49 , 4 ) ;
break;
case 87 :
case 119 :
V_46 -> type = F_47 ( V_88 , V_49 , 1 ) ;
break;
#ifdef F_48
case 103 :
case 359 :
if ( ! ( V_6 -> V_1 & V_89 ) )
goto V_90;
V_46 -> type = F_47 ( V_91 , 0 , 16 ) ;
break;
case 231 :
case 487 :
if ( ! ( V_6 -> V_1 & V_89 ) )
goto V_90;
V_46 -> type = F_47 ( V_92 , 0 , 16 ) ;
break;
#endif
#ifdef F_2
case 149 :
case 181 :
V_46 -> type = F_47 ( V_93 , V_49 , 8 ) ;
break;
#endif
case 151 :
case 183 :
V_46 -> type = F_47 ( V_93 , V_49 , 4 ) ;
break;
case 215 :
case 247 :
V_46 -> type = F_47 ( V_93 , V_49 , 1 ) ;
break;
case 279 :
case 311 :
V_46 -> type = F_47 ( V_88 , V_49 , 2 ) ;
break;
#ifdef F_2
case 341 :
case 373 :
V_46 -> type = F_47 ( V_88 , V_94 | V_49 , 4 ) ;
break;
#endif
case 343 :
case 375 :
V_46 -> type = F_47 ( V_88 , V_94 | V_49 , 2 ) ;
break;
case 407 :
case 439 :
V_46 -> type = F_47 ( V_93 , V_49 , 2 ) ;
break;
#ifdef F_2
case 532 :
V_46 -> type = F_47 ( V_88 , V_95 , 8 ) ;
break;
#endif
case 533 :
V_46 -> type = F_47 ( V_96 , 0 , V_6 -> V_34 & 0x7f ) ;
break;
case 534 :
V_46 -> type = F_47 ( V_88 , V_95 , 4 ) ;
break;
case 597 :
if ( V_16 == 0 )
V_16 = 32 ;
V_46 -> type = F_47 ( V_96 , 0 , V_16 ) ;
V_46 -> V_11 = 0 ;
if ( V_14 )
V_46 -> V_11 = F_1 ( V_6 -> V_1 ,
V_6 -> V_15 [ V_14 ] ) ;
break;
#ifdef F_49
case 535 :
case 567 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_99 , V_49 , 4 ) ;
break;
case 599 :
case 631 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_99 , V_49 , 8 ) ;
break;
case 663 :
case 695 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_100 , V_49 , 4 ) ;
break;
case 727 :
case 759 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_100 , V_49 , 8 ) ;
break;
#endif
#ifdef F_2
case 660 :
V_46 -> type = F_47 ( V_93 , V_95 , 8 ) ;
V_46 -> V_2 = F_13 ( V_6 -> V_15 [ V_33 ] ) ;
break;
#endif
case 661 :
V_46 -> type = F_47 ( V_101 , 0 , V_6 -> V_34 & 0x7f ) ;
break;
case 662 :
V_46 -> type = F_47 ( V_93 , V_95 , 4 ) ;
V_46 -> V_2 = F_12 ( V_6 -> V_15 [ V_33 ] ) ;
break;
case 725 :
if ( V_16 == 0 )
V_16 = 32 ;
V_46 -> type = F_47 ( V_101 , 0 , V_16 ) ;
V_46 -> V_11 = 0 ;
if ( V_14 )
V_46 -> V_11 = F_1 ( V_6 -> V_1 ,
V_6 -> V_15 [ V_14 ] ) ;
break;
case 790 :
V_46 -> type = F_47 ( V_88 , V_95 , 2 ) ;
break;
case 918 :
V_46 -> type = F_47 ( V_93 , V_95 , 2 ) ;
V_46 -> V_2 = F_11 ( V_6 -> V_15 [ V_33 ] ) ;
break;
#ifdef F_50
case 844 :
case 876 :
if ( ! ( V_6 -> V_1 & V_102 ) )
goto V_103;
V_46 -> V_69 = V_33 | ( ( V_4 & 1 ) << 5 ) ;
V_46 -> type = F_47 ( V_104 , V_49 , 16 ) ;
break;
case 972 :
case 1004 :
if ( ! ( V_6 -> V_1 & V_102 ) )
goto V_103;
V_46 -> V_69 = V_33 | ( ( V_4 & 1 ) << 5 ) ;
V_46 -> type = F_47 ( V_105 , V_49 , 16 ) ;
break;
#endif
}
break;
case 32 :
case 33 :
V_46 -> type = F_47 ( V_88 , V_49 , 4 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 34 :
case 35 :
V_46 -> type = F_47 ( V_88 , V_49 , 1 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 36 :
case 37 :
V_46 -> type = F_47 ( V_93 , V_49 , 4 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 38 :
case 39 :
V_46 -> type = F_47 ( V_93 , V_49 , 1 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 40 :
case 41 :
V_46 -> type = F_47 ( V_88 , V_49 , 2 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 42 :
case 43 :
V_46 -> type = F_47 ( V_88 , V_94 | V_49 , 2 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 44 :
case 45 :
V_46 -> type = F_47 ( V_93 , V_49 , 2 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 46 :
if ( V_14 >= V_33 )
break;
V_46 -> type = F_47 ( V_96 , 0 , 4 * ( 32 - V_33 ) ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 47 :
V_46 -> type = F_47 ( V_101 , 0 , 4 * ( 32 - V_33 ) ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
#ifdef F_49
case 48 :
case 49 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_99 , V_49 , 4 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 50 :
case 51 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_99 , V_49 , 8 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 52 :
case 53 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_100 , V_49 , 4 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
case 54 :
case 55 :
if ( ! ( V_6 -> V_1 & V_97 ) )
goto V_98;
V_46 -> type = F_47 ( V_100 , V_49 , 8 ) ;
V_46 -> V_11 = F_7 ( V_4 , V_6 ) ;
break;
#endif
#ifdef F_2
case 58 :
V_46 -> V_11 = F_8 ( V_4 , V_6 ) ;
switch ( V_4 & 3 ) {
case 0 :
V_46 -> type = F_47 ( V_88 , 0 , 8 ) ;
break;
case 1 :
V_46 -> type = F_47 ( V_88 , V_85 , 8 ) ;
break;
case 2 :
V_46 -> type = F_47 ( V_88 , V_94 , 4 ) ;
break;
}
break;
case 62 :
V_46 -> V_11 = F_8 ( V_4 , V_6 ) ;
switch ( V_4 & 3 ) {
case 0 :
V_46 -> type = F_47 ( V_93 , 0 , 8 ) ;
break;
case 1 :
V_46 -> type = F_47 ( V_93 , V_85 , 8 ) ;
break;
}
break;
#endif
}
return 0 ;
V_67:
if ( V_4 & 1 )
F_31 ( V_6 , V_14 ) ;
goto V_61;
V_78:
if ( V_4 & 1 )
F_31 ( V_6 , V_33 ) ;
V_61:
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_6 -> V_57 + 4 ) ;
return 1 ;
V_63:
V_46 -> type = V_106 | 0x700 ;
V_46 -> V_2 = V_107 ;
return 0 ;
V_66:
V_46 -> type = V_106 | 0x700 ;
V_46 -> V_2 = V_108 ;
return 0 ;
#ifdef F_49
V_98:
V_46 -> type = V_106 | 0x800 ;
return 0 ;
#endif
#ifdef F_48
V_90:
V_46 -> type = V_106 | 0xf20 ;
return 0 ;
#endif
#ifdef F_50
V_103:
V_46 -> type = V_106 | 0xf40 ;
return 0 ;
#endif
}
static T_1 int F_51 ( unsigned long V_11 , struct V_5 * V_6 )
{
#ifdef F_52
if ( V_11 - V_109 <= V_110 -> V_111 . V_112 ) {
F_53 ( V_113 L_1 ) ;
return - V_114 ;
}
#endif
F_54 ( F_55 ( V_115 ) ) ;
F_56 ( V_115 ) ;
return 0 ;
}
static T_1 void F_57 ( unsigned long * V_116 , int V_117 )
{
switch ( V_117 ) {
case 2 :
* V_116 = ( signed short ) * V_116 ;
break;
case 4 :
* V_116 = ( signed int ) * V_116 ;
break;
}
}
static T_1 void F_58 ( unsigned long * V_116 , int V_117 )
{
switch ( V_117 ) {
case 2 :
* V_116 = F_11 ( * V_116 ) ;
break;
case 4 :
* V_116 = F_12 ( * V_116 ) ;
break;
#ifdef F_2
case 8 :
* V_116 = F_13 ( * V_116 ) ;
break;
#endif
}
}
int F_59 ( struct V_5 * V_6 , unsigned int V_4 )
{
struct V_45 V_46 ;
int V_118 , V_19 , V_117 ;
unsigned long V_2 ;
unsigned int V_119 ;
int V_120 , V_33 , V_12 ;
V_118 = F_36 ( & V_46 , V_6 , V_4 ) ;
if ( V_118 != 0 )
return V_118 ;
V_19 = 0 ;
V_117 = F_60 ( V_46 . type ) ;
switch ( V_46 . type & V_121 ) {
case V_79 :
if ( ! F_4 ( V_6 , V_46 . V_11 , 8 ) )
return 0 ;
switch ( V_46 . type & V_122 ) {
case V_80 :
F_61 ( V_46 . V_11 , V_19 , L_2 ) ;
break;
case V_81 :
F_61 ( V_46 . V_11 , V_19 , L_3 ) ;
break;
case V_82 :
if ( V_46 . V_69 == 0 )
F_62 ( ( void * ) V_46 . V_11 ) ;
break;
case V_123 :
if ( V_46 . V_69 == 0 )
F_63 ( ( void * ) V_46 . V_11 ) ;
break;
case V_83 :
F_61 ( V_46 . V_11 , V_19 , L_4 ) ;
break;
}
if ( V_19 )
return 0 ;
goto V_61;
case V_86 :
if ( V_46 . V_11 & ( V_117 - 1 ) )
break;
if ( ! F_4 ( V_6 , V_46 . V_11 , V_117 ) )
return 0 ;
V_19 = 0 ;
switch ( V_117 ) {
case 4 :
F_64 ( V_2 , V_46 . V_11 , V_19 , L_5 ) ;
break;
#ifdef F_2
case 8 :
F_64 ( V_2 , V_46 . V_11 , V_19 , L_6 ) ;
break;
#endif
default:
return 0 ;
}
if ( ! V_19 )
V_6 -> V_15 [ V_46 . V_69 ] = V_2 ;
goto V_124;
case V_87 :
if ( V_46 . V_11 & ( V_117 - 1 ) )
break;
if ( ! F_4 ( V_6 , V_46 . V_11 , V_117 ) )
return 0 ;
V_19 = 0 ;
switch ( V_117 ) {
case 4 :
F_65 ( V_46 . V_2 , V_46 . V_11 , V_19 , L_7 , V_119 ) ;
break;
#ifdef F_2
case 8 :
F_65 ( V_46 . V_2 , V_46 . V_11 , V_19 , L_8 , V_119 ) ;
break;
#endif
default:
return 0 ;
}
if ( ! V_19 )
V_6 -> V_10 = ( V_6 -> V_10 & 0x0fffffff ) |
( V_119 & 0xe0000000 ) |
( ( V_6 -> V_34 >> 3 ) & 0x10000000 ) ;
goto V_124;
case V_88 :
V_19 = F_19 ( & V_6 -> V_15 [ V_46 . V_69 ] , V_46 . V_11 , V_117 , V_6 ) ;
if ( ! V_19 ) {
if ( V_46 . type & V_94 )
F_57 ( & V_6 -> V_15 [ V_46 . V_69 ] , V_117 ) ;
if ( V_46 . type & V_95 )
F_58 ( & V_6 -> V_15 [ V_46 . V_69 ] , V_117 ) ;
}
goto V_124;
#ifdef F_49
case V_99 :
if ( V_117 == 4 )
V_19 = F_24 ( V_46 . V_69 , V_125 , V_46 . V_11 , V_117 , V_6 ) ;
else
V_19 = F_24 ( V_46 . V_69 , V_126 , V_46 . V_11 , V_117 , V_6 ) ;
goto V_124;
#endif
#ifdef F_48
case V_91 :
V_19 = F_27 ( V_46 . V_69 , V_127 , V_46 . V_11 & ~ 0xfUL , V_6 ) ;
goto V_124;
#endif
#ifdef F_50
case V_104 :
V_19 = F_29 ( V_46 . V_69 , V_128 , V_46 . V_11 , V_6 ) ;
goto V_124;
#endif
case V_96 :
if ( V_6 -> V_1 & V_72 )
return 0 ;
V_33 = V_46 . V_69 ;
for ( V_120 = 0 ; V_120 < V_117 ; V_120 += 4 ) {
V_12 = V_117 - V_120 ;
if ( V_12 > 4 )
V_12 = 4 ;
V_19 = F_19 ( & V_6 -> V_15 [ V_33 ] , V_46 . V_11 , V_12 , V_6 ) ;
if ( V_19 )
return 0 ;
if ( V_12 < 4 )
V_6 -> V_15 [ V_33 ] <<= 32 - 8 * V_12 ;
V_46 . V_11 += 4 ;
++ V_33 ;
}
goto V_61;
case V_93 :
if ( ( V_46 . type & V_85 ) && V_117 == sizeof( long ) &&
V_46 . V_69 == 1 && V_46 . V_84 == 1 &&
! ( V_6 -> V_1 & V_62 ) &&
V_46 . V_11 >= V_6 -> V_15 [ 1 ] - V_109 ) {
V_19 = F_51 ( V_46 . V_11 , V_6 ) ;
goto V_124;
}
V_19 = F_23 ( V_46 . V_2 , V_46 . V_11 , V_117 , V_6 ) ;
goto V_124;
#ifdef F_49
case V_100 :
if ( V_117 == 4 )
V_19 = F_26 ( V_46 . V_69 , V_129 , V_46 . V_11 , V_117 , V_6 ) ;
else
V_19 = F_26 ( V_46 . V_69 , V_130 , V_46 . V_11 , V_117 , V_6 ) ;
goto V_124;
#endif
#ifdef F_48
case V_92 :
V_19 = F_28 ( V_46 . V_69 , V_131 , V_46 . V_11 & ~ 0xfUL , V_6 ) ;
goto V_124;
#endif
#ifdef F_50
case V_105 :
V_19 = F_30 ( V_46 . V_69 , V_132 , V_46 . V_11 , V_6 ) ;
goto V_124;
#endif
case V_101 :
if ( V_6 -> V_1 & V_72 )
return 0 ;
V_33 = V_46 . V_69 ;
for ( V_120 = 0 ; V_120 < V_117 ; V_120 += 4 ) {
V_2 = V_6 -> V_15 [ V_33 ] ;
V_12 = V_117 - V_120 ;
if ( V_12 > 4 )
V_12 = 4 ;
else
V_2 >>= 32 - 8 * V_12 ;
V_19 = F_23 ( V_2 , V_46 . V_11 , V_12 , V_6 ) ;
if ( V_19 )
return 0 ;
V_46 . V_11 += 4 ;
++ V_33 ;
}
goto V_61;
case V_68 :
V_6 -> V_15 [ V_46 . V_69 ] = V_6 -> V_1 & V_133 ;
goto V_61;
case V_70 :
V_2 = V_6 -> V_15 [ V_46 . V_69 ] ;
if ( ( V_2 & V_134 ) == 0 )
return - 1 ;
V_6 -> V_1 = ( V_6 -> V_1 & ~ V_46 . V_2 ) | ( V_2 & V_46 . V_2 ) ;
goto V_61;
#ifdef F_37
case V_59 :
if ( V_6 -> V_15 [ 0 ] == 0x1ebe &&
F_66 ( V_135 ) ) {
V_6 -> V_1 ^= V_72 ;
goto V_61;
}
V_6 -> V_15 [ 9 ] = V_6 -> V_15 [ 13 ] ;
V_6 -> V_15 [ 10 ] = V_136 ;
V_6 -> V_15 [ 11 ] = V_6 -> V_57 + 4 ;
V_6 -> V_15 [ 12 ] = V_6 -> V_1 & V_133 ;
V_6 -> V_15 [ 13 ] = ( unsigned long ) F_67 () ;
V_6 -> V_57 = ( unsigned long ) & V_137 ;
V_6 -> V_1 = V_136 ;
return 1 ;
case V_64 :
return - 1 ;
#endif
}
return 0 ;
V_124:
if ( V_19 )
return 0 ;
if ( V_46 . type & V_85 )
V_6 -> V_15 [ V_46 . V_84 ] = V_46 . V_11 ;
V_61:
V_6 -> V_57 = F_1 ( V_6 -> V_1 , V_6 -> V_57 + 4 ) ;
return 1 ;
}
