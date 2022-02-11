static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = { V_6 , V_7 , V_8 , V_9 , V_10 } ,
} ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 = V_4 -> V_14 % V_15 ;
V_4 -> V_14 += V_12 ;
if ( ( V_13 + V_12 ) >= V_15 ) {
int V_16 ;
if ( V_13 ) {
int V_17 = V_15 - V_13 ;
memcpy ( V_4 -> V_18 + V_13 , V_11 , V_17 ) ;
V_11 += V_17 ;
V_12 -= V_17 ;
}
V_16 = V_12 / V_15 ;
V_12 %= V_15 ;
F_4 ( 16 ) ;
F_5 ( V_16 , V_11 , V_4 -> V_5 ,
V_13 ? V_4 -> V_18 : NULL , 0 ) ;
F_6 () ;
V_11 += V_16 * V_15 ;
V_13 = 0 ;
}
if ( V_12 )
memcpy ( V_4 -> V_18 + V_13 , V_11 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_19 )
{
static const T_1 V_20 [ V_15 ] = { 0x80 , } ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_21 = F_8 ( V_4 -> V_14 << 3 ) ;
T_3 * V_22 = ( T_3 * ) V_19 ;
int V_23 ;
T_4 V_24 = V_15
- ( ( V_4 -> V_14 + sizeof( V_21 ) ) % V_15 ) ;
F_3 ( V_2 , V_20 , V_24 ) ;
F_3 ( V_2 , ( const T_1 * ) & V_21 , sizeof( V_21 ) ) ;
for ( V_23 = 0 ; V_23 < V_25 / sizeof( T_3 ) ; V_23 ++ )
F_9 ( V_4 -> V_5 [ V_23 ] , V_22 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 * V_22 = ( T_3 * ) V_19 ;
int V_16 ;
int V_23 ;
if ( V_4 -> V_14 || ! V_12 || ( V_12 % V_15 ) ) {
F_3 ( V_2 , V_11 , V_12 ) ;
return F_7 ( V_2 , V_19 ) ;
}
V_16 = V_12 / V_15 ;
F_4 ( 16 ) ;
F_5 ( V_16 , V_11 , V_4 -> V_5 , NULL , V_12 ) ;
F_6 () ;
for ( V_23 = 0 ; V_23 < V_25 / sizeof( T_3 ) ; V_23 ++ )
F_9 ( V_4 -> V_5 [ V_23 ] , V_22 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_22 = V_19 ;
* V_22 = * V_4 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , const void * V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 const * V_27 = V_26 ;
* V_4 = * V_27 ;
return 0 ;
}
static int T_5 F_13 ( void )
{
return F_14 ( & V_28 ) ;
}
static void T_6 F_15 ( void )
{
F_16 ( & V_28 ) ;
}
