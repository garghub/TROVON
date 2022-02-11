static void F_1 ( unsigned long V_1 )
{
* V_2 -> V_3 = V_1 ;
}
static unsigned long F_2 ( void )
{
unsigned long V_4 = * V_2 -> V_3 ;
return V_4 ;
}
static unsigned long F_3 ( void )
{
unsigned long V_4 = * V_2 -> V_5 ;
return V_4 ;
}
static void F_4 ( void )
{
F_1 ( F_2 () | V_2 -> V_6 ) ;
}
static void F_5 ( void )
{
F_1 ( F_2 () & ~ V_2 -> V_6 ) ;
}
static void F_6 ( unsigned long V_7 )
{
V_7 |= V_2 -> V_8 ;
F_1 ( V_7 ) ;
F_7 ( 250 ) ;
if ( V_2 -> V_9 )
V_7 &= ~ V_2 -> V_7 ;
else
V_7 |= V_2 -> V_7 ;
V_7 &= ~ V_2 -> V_8 ;
F_1 ( V_7 ) ;
F_7 ( 250 + V_2 -> V_10 ) ;
}
static void F_8 ( unsigned int V_11 )
{
unsigned long V_7 = F_2 () ;
if ( V_2 -> V_9 )
V_11 = ! V_11 ;
if ( V_11 )
V_7 |= V_2 -> V_7 ;
else
V_7 &= ~ V_2 -> V_7 ;
F_1 ( V_7 ) ;
F_7 ( 50 + V_2 -> V_10 ) ;
F_6 ( V_7 ) ;
}
static unsigned int F_9 ( void )
{
unsigned int V_7 ;
V_7 = ( F_3 () & ( 1 << V_2 -> V_12 ) )
>> V_2 -> V_12 ;
F_6 ( F_2 () ) ;
return V_7 ;
}
static void F_10 ( unsigned int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 <= 7 ; V_14 ++ ) {
F_8 ( V_13 & 1L ) ;
V_13 >>= 1 ;
}
}
static void F_11 ( unsigned long V_15 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 <= 31 ; V_14 ++ ) {
F_8 ( V_15 & 1L ) ;
V_15 >>= 1 ;
}
}
static unsigned long F_12 ( void )
{
int V_14 ;
unsigned long V_15 = 0 ;
unsigned long V_16 = 0 ;
for ( V_14 = 0 ; V_14 <= 31 ; V_14 ++ ) {
V_15 |= F_9 () << V_16 ;
V_16 ++ ;
}
return V_15 ;
}
static void F_13 ( void )
{
F_4 () ;
F_1 ( F_2 () & ~ V_2 -> V_8 ) ;
F_7 ( 50 ) ;
}
static void F_14 ( void )
{
F_5 () ;
F_7 ( 1000 ) ;
}
void F_15 ( struct V_17 * V_18 )
{
unsigned long V_15 ;
unsigned long V_19 ;
F_16 ( & V_20 , V_19 ) ;
F_13 () ;
F_10 ( V_21 ) ;
V_15 = F_12 () ;
F_14 () ;
F_17 ( & V_20 , V_19 ) ;
V_18 -> V_22 = V_15 ;
V_18 -> V_23 = 0 ;
}
int F_18 ( unsigned long time )
{
unsigned long V_19 ;
F_16 ( & V_20 , V_19 ) ;
F_13 () ;
F_10 ( V_24 ) ;
F_11 ( time ) ;
F_14 () ;
F_17 ( & V_20 , V_19 ) ;
return 0 ;
}
void F_19 ( unsigned int V_25 )
{
F_13 () ;
F_10 ( ( ( V_25 << V_26 ) & V_27 )
| ( V_28 ) ) ;
F_14 () ;
}
void F_20 ( void )
{
F_19 ( V_29 ) ;
}
void F_21 ( void )
{
F_19 ( V_30 ) ;
}
