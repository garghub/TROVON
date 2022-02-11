T_1 F_1 ( struct V_1 * V_2 )
{
#define F_2 ( T_2 , T_3 , T_4 , T_5 , T_6 ) ((s&c)<<d) ^ (((s <<a) ^ s)>>b)
V_2 -> V_3 = F_2 ( V_2 -> V_3 , 6U , 13U , 4294967294U , 18U ) ;
V_2 -> V_4 = F_2 ( V_2 -> V_4 , 2U , 27U , 4294967288U , 2U ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_5 , 13U , 21U , 4294967280U , 7U ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_6 , 3U , 12U , 4294967168U , 13U ) ;
return ( V_2 -> V_3 ^ V_2 -> V_4 ^ V_2 -> V_5 ^ V_2 -> V_6 ) ;
}
T_1 F_3 ( void )
{
unsigned long V_7 ;
struct V_1 * V_2 = & F_4 ( V_8 ) ;
V_7 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
return V_7 ;
}
void F_6 ( struct V_1 * V_2 , void * V_9 , int V_10 )
{
unsigned char * V_11 = V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_7 ( V_10 , sizeof( T_1 ) ) ; V_12 += sizeof( T_1 ) ) {
T_1 V_13 = F_1 ( V_2 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < sizeof( T_1 ) ; V_14 ++ ) {
V_11 [ V_12 + V_14 ] = V_13 ;
V_13 >>= V_15 ;
}
}
if ( V_12 < V_10 ) {
T_1 V_13 = F_1 ( V_2 ) ;
for (; V_12 < V_10 ; V_12 ++ ) {
V_11 [ V_12 ] = V_13 ;
V_13 >>= V_15 ;
}
}
}
void F_8 ( void * V_9 , int V_10 )
{
struct V_1 * V_2 = & F_4 ( V_8 ) ;
F_6 ( V_2 , V_9 , V_10 ) ;
F_5 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_16 )
{
#define F_11 ( T_7 ) ((x) * 69069U)
V_2 -> V_3 = F_12 ( F_11 ( V_16 ) , 2U ) ;
V_2 -> V_4 = F_12 ( F_11 ( V_2 -> V_3 ) , 8U ) ;
V_2 -> V_5 = F_12 ( F_11 ( V_2 -> V_4 ) , 16U ) ;
V_2 -> V_6 = F_12 ( F_11 ( V_2 -> V_5 ) , 128U ) ;
}
void F_13 ( T_1 V_17 )
{
int V_12 ;
F_14 (i) {
struct V_1 * V_2 = & F_15 ( V_8 , V_12 ) ;
V_2 -> V_3 = F_12 ( V_2 -> V_3 ^ V_17 , 2U ) ;
F_9 ( V_2 ) ;
}
}
static int T_8 F_16 ( void )
{
int V_12 ;
#ifdef F_17
F_18 () ;
#endif
F_14 (i) {
struct V_1 * V_2 = & F_15 ( V_8 , V_12 ) ;
F_10 ( V_2 , ( V_12 + V_18 ) ^ F_19 () ) ;
F_9 ( V_2 ) ;
}
return 0 ;
}
static void F_20 ( unsigned long V_19 )
{
T_1 V_17 ;
unsigned long V_20 ;
F_21 ( & V_17 , sizeof( V_17 ) ) ;
F_13 ( V_17 ) ;
V_20 = 40 + ( F_3 () % 40 ) ;
V_21 . V_20 = V_18 + F_22 ( V_20 * V_22 ) ;
F_23 ( & V_21 ) ;
}
static void T_8 F_24 ( void )
{
F_25 ( & V_21 , V_23 ) ;
V_21 . V_20 = V_18 + F_22 ( 40 * V_22 ) ;
F_23 ( & V_21 ) ;
}
static void F_26 ( bool V_24 )
{
int V_12 ;
unsigned long V_25 ;
static bool V_26 = false ;
static F_27 ( V_27 ) ;
F_28 ( & V_27 , V_25 ) ;
if ( V_26 && ! V_24 )
goto V_28;
V_26 = true ;
F_14 (i) {
struct V_1 * V_2 = & F_15 ( V_8 , V_12 ) ;
T_1 V_29 [ 4 ] ;
F_21 ( & V_29 , sizeof( V_29 ) ) ;
V_2 -> V_3 = F_12 ( V_29 [ 0 ] , 2U ) ;
V_2 -> V_4 = F_12 ( V_29 [ 1 ] , 8U ) ;
V_2 -> V_5 = F_12 ( V_29 [ 2 ] , 16U ) ;
V_2 -> V_6 = F_12 ( V_29 [ 3 ] , 128U ) ;
F_9 ( V_2 ) ;
}
V_28:
F_29 ( & V_27 , V_25 ) ;
}
void F_30 ( void )
{
F_26 ( true ) ;
}
static int T_8 F_31 ( void )
{
F_26 ( false ) ;
F_24 () ;
return 0 ;
}
static void T_8 F_18 ( void )
{
int V_12 , V_14 , V_30 = 0 , V_31 = 0 ;
bool error = false ;
for ( V_12 = 0 ; V_12 < F_32 ( V_32 ) ; V_12 ++ ) {
struct V_1 V_2 ;
F_10 ( & V_2 , V_32 [ V_12 ] . V_16 ) ;
F_9 ( & V_2 ) ;
if ( V_32 [ V_12 ] . V_33 != F_1 ( & V_2 ) )
error = true ;
}
if ( error )
F_33 ( L_1 ) ;
else
F_34 ( L_2 ) ;
for ( V_12 = 0 ; V_12 < F_32 ( V_34 ) ; V_12 ++ ) {
struct V_1 V_2 ;
F_10 ( & V_2 , V_34 [ V_12 ] . V_16 ) ;
F_9 ( & V_2 ) ;
for ( V_14 = 0 ; V_14 < V_34 [ V_12 ] . V_35 - 1 ; V_14 ++ )
F_1 ( & V_2 ) ;
if ( V_34 [ V_12 ] . V_33 != F_1 ( & V_2 ) )
V_30 ++ ;
V_31 ++ ;
F_35 () ;
}
if ( V_30 )
F_33 ( L_3 , V_30 , V_31 ) ;
else
F_34 ( L_4 , V_31 ) ;
}
