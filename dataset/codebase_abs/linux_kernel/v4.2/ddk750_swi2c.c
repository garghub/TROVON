static void F_1 ( void )
{
#if 0
while (peekIO(0x3ce, 0x61) & 0x10);
#else
int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < 600 ; V_1 ++ ) {
V_2 = V_1 ;
V_2 += V_1 ;
}
#endif
}
void F_2 ( unsigned char V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
V_5 = F_3 ( V_6 ) ;
if ( V_3 ) {
V_5 &= ~ ( 1 << V_7 ) ;
F_4 ( V_6 , V_5 ) ;
} else {
V_4 = F_3 ( V_8 ) ;
V_4 &= ~ ( 1 << V_7 ) ;
F_4 ( V_8 , V_4 ) ;
V_5 |= ( 1 << V_7 ) ;
F_4 ( V_6 , V_5 ) ;
}
}
void F_5 ( unsigned char V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
V_5 = F_3 ( V_9 ) ;
if ( V_3 ) {
V_5 &= ~ ( 1 << V_10 ) ;
F_4 ( V_9 , V_5 ) ;
} else {
V_4 = F_3 ( V_11 ) ;
V_4 &= ~ ( 1 << V_10 ) ;
F_4 ( V_11 , V_4 ) ;
V_5 |= ( 1 << V_10 ) ;
F_4 ( V_9 , V_5 ) ;
}
}
static unsigned char F_6 ( void )
{
unsigned long V_5 ;
unsigned long V_4 ;
V_5 = F_3 ( V_9 ) ;
if ( ( V_5 & ( 1 << V_10 ) ) != ( ~ ( 1 << V_10 ) ) ) {
V_5 &= ~ ( 1 << V_10 ) ;
F_4 ( V_9 , V_5 ) ;
}
V_4 = F_3 ( V_11 ) ;
if ( V_4 & ( 1 << V_10 ) )
return 1 ;
else
return 0 ;
}
static void F_7 ( void )
{
return;
}
static void F_8 ( void )
{
F_5 ( 1 ) ;
F_2 ( 1 ) ;
F_5 ( 0 ) ;
}
static void F_9 ( void )
{
F_2 ( 1 ) ;
F_5 ( 0 ) ;
F_5 ( 1 ) ;
}
static long F_10 ( unsigned char V_12 )
{
unsigned char V_3 = V_12 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
F_2 ( 0 ) ;
if ( ( V_3 & 0x80 ) != 0 )
F_5 ( 1 ) ;
else
F_5 ( 0 ) ;
F_1 () ;
F_2 ( 1 ) ;
F_1 () ;
V_3 = V_3 << 1 ;
}
F_2 ( 0 ) ;
F_5 ( 1 ) ;
F_1 () ;
F_2 ( 1 ) ;
F_1 () ;
for ( V_1 = 0 ; V_1 < 0xff ; V_1 ++ ) {
if ( ! F_6 () )
break;
F_2 ( 0 ) ;
F_1 () ;
F_2 ( 1 ) ;
F_1 () ;
}
F_2 ( 0 ) ;
F_5 ( 1 ) ;
if ( V_1 < 0xff )
return 0 ;
else
return - 1 ;
}
static unsigned char F_11 ( unsigned char V_13 )
{
int V_1 ;
unsigned char V_12 = 0 ;
for ( V_1 = 7 ; V_1 >= 0 ; V_1 -- ) {
F_2 ( 0 ) ;
F_5 ( 1 ) ;
F_1 () ;
F_2 ( 1 ) ;
F_1 () ;
V_12 |= ( F_6 () << V_1 ) ;
}
if ( V_13 )
F_7 () ;
F_2 ( 0 ) ;
F_5 ( 1 ) ;
return V_12 ;
}
static long F_12 ( unsigned char V_14 ,
unsigned char V_15 )
{
int V_1 ;
V_8 = V_16 ;
V_6 = V_17 ;
V_7 = V_14 ;
V_11 = V_16 ;
V_9 = V_17 ;
V_10 = V_15 ;
for ( V_1 = 0 ; V_1 < 9 ; V_1 ++ )
F_9 () ;
return 0 ;
}
long F_13 (
unsigned char V_14 ,
unsigned char V_15
)
{
int V_1 ;
if ( ( V_14 > 31 ) || ( V_15 > 31 ) )
return - 1 ;
if ( F_14 () == V_18 )
return F_12 ( V_14 , V_15 ) ;
V_19 = V_20 ;
V_8 = V_21 ;
V_6 = V_22 ;
V_7 = V_14 ;
V_23 = V_20 ;
V_11 = V_21 ;
V_9 = V_22 ;
V_10 = V_15 ;
F_4 ( V_19 ,
F_3 ( V_19 ) & ~ ( 1 << V_7 ) ) ;
F_4 ( V_23 ,
F_3 ( V_23 ) & ~ ( 1 << V_10 ) ) ;
F_15 ( 1 ) ;
for ( V_1 = 0 ; V_1 < 9 ; V_1 ++ )
F_9 () ;
return 0 ;
}
unsigned char F_16 (
unsigned char V_24 ,
unsigned char V_25
)
{
unsigned char V_12 ;
F_8 () ;
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
F_8 () ;
F_10 ( V_24 + 1 ) ;
V_12 = F_11 ( 1 ) ;
F_9 () ;
return V_12 ;
}
long F_17 (
unsigned char V_24 ,
unsigned char V_25 ,
unsigned char V_12
)
{
long V_26 = 0 ;
F_8 () ;
if ( ( F_10 ( V_24 ) != 0 ) ||
( F_10 ( V_25 ) != 0 ) ||
( F_10 ( V_12 ) != 0 ) ) {
V_26 = - 1 ;
}
F_9 () ;
return V_26 ;
}
