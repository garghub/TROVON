static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = {
V_6 , V_7 , V_8 , V_9 ,
V_10 , V_11 , V_12 , V_13 ,
}
} ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {
. V_5 = {
V_14 , V_15 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_21 ,
}
} ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 * V_22 ,
unsigned int V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_24 = V_4 -> V_25 % V_26 ;
V_4 -> V_25 += V_23 ;
if ( ( V_24 + V_23 ) >= V_26 ) {
int V_27 ;
if ( V_24 ) {
int V_28 = V_26 - V_24 ;
memcpy ( V_4 -> V_29 + V_24 , V_22 , V_28 ) ;
V_22 += V_28 ;
V_23 -= V_28 ;
}
V_27 = V_23 / V_26 ;
V_23 %= V_26 ;
F_5 ( 28 ) ;
F_6 ( V_27 , V_22 , V_4 -> V_5 ,
V_24 ? V_4 -> V_29 : NULL , 0 ) ;
F_7 () ;
V_22 += V_27 * V_26 ;
V_24 = 0 ;
}
if ( V_23 )
memcpy ( V_4 -> V_29 + V_24 , V_22 , V_23 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
static const T_1 V_30 [ V_26 ] = { 0x80 , } ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_31 = F_9 ( V_4 -> V_25 << 3 ) ;
T_3 V_32 = V_26
- ( ( V_4 -> V_25 + sizeof( V_31 ) ) % V_26 ) ;
F_4 ( V_2 , V_30 , V_32 ) ;
F_4 ( V_2 , ( const T_1 * ) & V_31 , sizeof( V_31 ) ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 * V_34 = ( T_4 * ) V_33 ;
int V_35 ;
F_8 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_36 / sizeof( T_4 ) ; V_35 ++ )
F_11 ( V_4 -> V_5 [ V_35 ] , V_34 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 * V_34 = ( T_4 * ) V_33 ;
int V_35 ;
F_8 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_37 / sizeof( T_4 ) ; V_35 ++ )
F_11 ( V_4 -> V_5 [ V_35 ] , V_34 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , const T_1 * V_22 ,
unsigned int V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_27 ;
if ( V_4 -> V_25 || ! V_23 || ( V_23 % V_26 ) ) {
F_4 ( V_2 , V_22 , V_23 ) ;
F_8 ( V_2 ) ;
return;
}
V_27 = V_23 / V_26 ;
F_5 ( 28 ) ;
F_6 ( V_27 , V_22 , V_4 -> V_5 , NULL , V_23 ) ;
F_7 () ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 * V_22 ,
unsigned int V_23 , T_1 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 * V_34 = ( T_4 * ) V_33 ;
int V_35 ;
F_13 ( V_2 , V_22 , V_23 ) ;
for ( V_35 = 0 ; V_35 < V_36 / sizeof( T_4 ) ; V_35 ++ )
F_11 ( V_4 -> V_5 [ V_35 ] , V_34 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_22 ,
unsigned int V_23 , T_1 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 * V_34 = ( T_4 * ) V_33 ;
int V_35 ;
F_13 ( V_2 , V_22 , V_23 ) ;
for ( V_35 = 0 ; V_35 < V_37 / sizeof( T_4 ) ; V_35 ++ )
F_11 ( V_4 -> V_5 [ V_35 ] , V_34 ++ ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_34 = V_33 ;
* V_34 = * V_4 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 const * V_39 = V_38 ;
* V_4 = * V_39 ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( V_40 , F_20 ( V_40 ) ) ;
}
static void T_6 F_21 ( void )
{
F_22 ( V_40 , F_20 ( V_40 ) ) ;
}
