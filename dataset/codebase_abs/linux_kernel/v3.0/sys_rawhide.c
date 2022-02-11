static inline void
F_1 ( int V_1 , int V_2 )
{
* ( V_3 ) F_2 ( F_3 ( V_1 ) ) = V_2 ;
F_4 () ;
* ( V_3 ) F_2 ( F_3 ( V_1 ) ) ;
}
static inline void
F_5 ( struct V_4 * V_5 )
{
unsigned int V_2 , V_1 ;
unsigned int V_6 = V_5 -> V_6 ;
V_6 -= 16 ;
V_1 = V_6 / 24 ;
if ( ! F_6 ( V_1 ) )
return;
V_6 -= V_1 * 24 ;
V_2 = 1 << V_6 ;
F_7 ( & V_7 ) ;
V_2 |= V_8 [ V_1 ] ;
V_8 [ V_1 ] = V_2 ;
F_1 ( V_1 , V_2 ) ;
F_8 ( & V_7 ) ;
}
static void
F_9 ( struct V_4 * V_5 )
{
unsigned int V_2 , V_1 ;
unsigned int V_6 = V_5 -> V_6 ;
V_6 -= 16 ;
V_1 = V_6 / 24 ;
if ( ! F_6 ( V_1 ) )
return;
V_6 -= V_1 * 24 ;
V_2 = ~ ( 1 << V_6 ) | V_9 [ V_1 ] ;
F_7 ( & V_7 ) ;
V_2 &= V_8 [ V_1 ] ;
V_8 [ V_1 ] = V_2 ;
F_1 ( V_1 , V_2 ) ;
F_8 ( & V_7 ) ;
}
static void
F_10 ( struct V_4 * V_5 )
{
unsigned int V_2 , V_10 , V_1 ;
unsigned int V_6 = V_5 -> V_6 ;
V_6 -= 16 ;
V_1 = V_6 / 24 ;
if ( ! F_6 ( V_1 ) )
return;
V_6 -= V_1 * 24 ;
V_10 = 1 << V_6 ;
V_2 = ~ V_10 | V_9 [ V_1 ] ;
F_7 ( & V_7 ) ;
V_2 &= V_8 [ V_1 ] ;
V_8 [ V_1 ] = V_2 ;
F_1 ( V_1 , V_2 ) ;
* ( V_3 ) F_11 ( F_3 ( V_1 ) ) = V_10 ;
F_8 ( & V_7 ) ;
}
static void
F_12 ( unsigned long V_11 )
{
int V_6 ;
V_6 = ( V_11 - 0x800 ) >> 4 ;
if ( V_6 == 52 ) {
V_6 = 72 ;
}
V_6 -= ( ( V_6 + 16 ) >> 2 ) & 0x38 ;
F_13 ( V_6 ) ;
}
static void T_1
F_14 ( void )
{
struct V_12 * V_1 ;
long V_13 ;
F_15 () ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) V_8 [ V_13 ] = 0 ;
for ( V_1 = V_15 ; V_1 ; V_1 = V_1 -> V_16 ) {
unsigned int V_17 = V_1 -> V_18 ;
unsigned int V_2 = V_9 [ V_17 ] ;
V_8 [ V_17 ] = V_2 ;
* ( V_3 ) F_2 ( F_3 ( V_17 ) ) = V_2 ;
* ( V_3 ) F_16 ( F_3 ( V_17 ) ) = 0 ;
}
for ( V_13 = 16 ; V_13 < 128 ; ++ V_13 ) {
F_17 ( V_13 , & V_19 ,
V_20 ) ;
F_18 ( V_13 , V_21 ) ;
}
F_19 () ;
F_20 () ;
}
static int T_1
F_21 ( struct V_22 * V_23 , T_2 V_24 , T_2 V_25 )
{
static char V_26 [ 5 ] [ 5 ] V_27 = {
{ 16 + 16 , 16 + 16 , 16 + 16 , 16 + 16 , 16 + 16 } ,
{ 16 + 0 , 16 + 0 , 16 + 1 , 16 + 2 , 16 + 3 } ,
{ 16 + 4 , 16 + 4 , 16 + 5 , 16 + 6 , 16 + 7 } ,
{ 16 + 8 , 16 + 8 , 16 + 9 , 16 + 10 , 16 + 11 } ,
{ 16 + 12 , 16 + 12 , 16 + 13 , 16 + 14 , 16 + 15 }
} ;
const long V_28 = 1 , V_29 = 5 , V_30 = 5 ;
struct V_12 * V_1 = V_23 -> V_31 ;
int V_6 = V_32 ;
if ( V_6 >= 0 )
V_6 += 24 * V_1 -> V_18 ;
return V_6 ;
}
