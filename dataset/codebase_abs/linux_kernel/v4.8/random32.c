static inline void F_1 ( void )
{
}
T_1 F_2 ( struct V_1 * V_2 )
{
#define F_3 ( T_2 , T_3 , T_4 , T_5 , T_6 ) ((s & c) << d) ^ (((s << a) ^ s) >> b)
V_2 -> V_3 = F_3 ( V_2 -> V_3 , 6U , 13U , 4294967294U , 18U ) ;
V_2 -> V_4 = F_3 ( V_2 -> V_4 , 2U , 27U , 4294967288U , 2U ) ;
V_2 -> V_5 = F_3 ( V_2 -> V_5 , 13U , 21U , 4294967280U , 7U ) ;
V_2 -> V_6 = F_3 ( V_2 -> V_6 , 3U , 12U , 4294967168U , 13U ) ;
return ( V_2 -> V_3 ^ V_2 -> V_4 ^ V_2 -> V_5 ^ V_2 -> V_6 ) ;
}
T_1 F_4 ( void )
{
struct V_1 * V_2 = & F_5 ( V_7 ) ;
T_1 V_8 ;
V_8 = F_2 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_8 ;
}
void F_7 ( struct V_1 * V_2 , void * V_9 , T_7 V_10 )
{
T_8 * V_11 = V_9 ;
while ( V_10 >= sizeof( T_1 ) ) {
F_8 ( F_2 ( V_2 ) , ( T_1 * ) V_11 ) ;
V_11 += sizeof( T_1 ) ;
V_10 -= sizeof( T_1 ) ;
}
if ( V_10 > 0 ) {
T_1 V_12 = F_2 ( V_2 ) ;
do {
* V_11 ++ = ( T_8 ) V_12 ;
V_10 -- ;
V_12 >>= V_13 ;
} while ( V_10 > 0 );
}
}
void F_9 ( void * V_9 , T_7 V_10 )
{
struct V_1 * V_2 = & F_5 ( V_7 ) ;
F_7 ( V_2 , V_9 , V_10 ) ;
F_6 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 ) ;
}
static T_1 F_11 ( void )
{
unsigned int V_14 = 0 ;
( void ) ( F_12 ( & V_14 ) ||
F_13 ( & V_14 ) ) ;
return V_14 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_15 ,
bool V_16 )
{
#define F_15 ( T_9 ) ((x) * 69069U)
#define F_16 () (mix_with_hwseed ? __extract_hwseed() : 0)
V_2 -> V_3 = F_17 ( F_16 () ^ F_15 ( V_15 ) , 2U ) ;
V_2 -> V_4 = F_17 ( F_16 () ^ F_15 ( V_2 -> V_3 ) , 8U ) ;
V_2 -> V_5 = F_17 ( F_16 () ^ F_15 ( V_2 -> V_4 ) , 16U ) ;
V_2 -> V_6 = F_17 ( F_16 () ^ F_15 ( V_2 -> V_5 ) , 128U ) ;
}
void F_18 ( T_1 V_17 )
{
int V_18 ;
F_19 (i) {
struct V_1 * V_2 = & F_20 ( V_7 , V_18 ) ;
V_2 -> V_3 = F_17 ( V_2 -> V_3 ^ V_17 , 2U ) ;
F_10 ( V_2 ) ;
}
}
static int T_10 F_21 ( void )
{
int V_18 ;
F_1 () ;
F_19 (i) {
struct V_1 * V_2 = & F_20 ( V_7 , V_18 ) ;
T_1 V_19 = ( V_18 + V_20 ) ^ F_22 () ;
F_14 ( V_2 , V_19 , true ) ;
F_10 ( V_2 ) ;
}
return 0 ;
}
static void F_23 ( unsigned long V_21 )
{
T_1 V_17 ;
unsigned long V_22 ;
F_24 ( & V_17 , sizeof( V_17 ) ) ;
F_18 ( V_17 ) ;
V_22 = 40 + F_25 ( 40 ) ;
V_23 . V_22 = V_20 + F_26 ( V_22 * V_24 ) ;
F_27 ( & V_23 ) ;
}
static void T_10 F_28 ( void )
{
V_23 . V_22 = V_20 + F_26 ( 40 * V_24 ) ;
F_27 ( & V_23 ) ;
}
void F_29 ( struct V_1 T_11 * V_25 )
{
int V_18 ;
F_19 (i) {
struct V_1 * V_2 = F_30 ( V_25 , V_18 ) ;
T_1 V_26 [ 4 ] ;
F_24 ( & V_26 , sizeof( V_26 ) ) ;
V_2 -> V_3 = F_17 ( V_26 [ 0 ] , 2U ) ;
V_2 -> V_4 = F_17 ( V_26 [ 1 ] , 8U ) ;
V_2 -> V_5 = F_17 ( V_26 [ 2 ] , 16U ) ;
V_2 -> V_6 = F_17 ( V_26 [ 3 ] , 128U ) ;
F_10 ( V_2 ) ;
}
}
static void F_31 ( bool V_27 )
{
unsigned long V_28 ;
static bool V_29 = false ;
static F_32 ( V_30 ) ;
if ( ! F_33 ( & V_30 , V_28 ) )
return;
if ( V_29 && ! V_27 )
goto V_31;
V_29 = true ;
F_29 ( & V_7 ) ;
V_31:
F_34 ( & V_30 , V_28 ) ;
}
void F_35 ( void )
{
F_31 ( true ) ;
}
static int T_10 F_36 ( void )
{
F_31 ( false ) ;
F_28 () ;
return 0 ;
}
static void T_10 F_1 ( void )
{
int V_18 , V_32 , V_33 = 0 , V_34 = 0 ;
bool error = false ;
for ( V_18 = 0 ; V_18 < F_37 ( V_35 ) ; V_18 ++ ) {
struct V_1 V_2 ;
F_14 ( & V_2 , V_35 [ V_18 ] . V_15 , false ) ;
F_10 ( & V_2 ) ;
if ( V_35 [ V_18 ] . V_36 != F_2 ( & V_2 ) )
error = true ;
}
if ( error )
F_38 ( L_1 ) ;
else
F_39 ( L_2 ) ;
for ( V_18 = 0 ; V_18 < F_37 ( V_37 ) ; V_18 ++ ) {
struct V_1 V_2 ;
F_14 ( & V_2 , V_37 [ V_18 ] . V_15 , false ) ;
F_10 ( & V_2 ) ;
for ( V_32 = 0 ; V_32 < V_37 [ V_18 ] . V_38 - 1 ; V_32 ++ )
F_2 ( & V_2 ) ;
if ( V_37 [ V_18 ] . V_36 != F_2 ( & V_2 ) )
V_33 ++ ;
V_34 ++ ;
F_40 () ;
}
if ( V_33 )
F_38 ( L_3 , V_33 , V_34 ) ;
else
F_39 ( L_4 , V_34 ) ;
}
