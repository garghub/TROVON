static void
F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
* V_3 = * V_3 | V_4 ;
F_2 ( V_2 , V_5 , * V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
}
static void
F_5 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
* V_3 = * V_3 & ~ V_4 ;
F_2 ( V_2 , V_5 , * V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
T_2 V_6 ,
T_2 V_7 )
{
T_1 V_3 ;
T_1 V_8 ;
V_8 = 0x01 << ( V_7 - 1 ) ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_9 | V_10 ) ;
do {
V_3 &= ~ V_10 ;
if ( V_6 & V_8 )
V_3 |= V_10 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
F_1 ( V_2 , & V_3 ) ;
F_5 ( V_2 , & V_3 ) ;
V_8 = V_8 >> 1 ;
} while ( V_8 );
V_3 &= ~ V_10 ;
F_2 ( V_2 , V_5 , V_3 ) ;
}
static T_2
F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_11 ;
T_2 V_6 ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_9 | V_10 ) ;
V_6 = 0 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_6 = V_6 << 1 ;
F_1 ( V_2 , & V_3 ) ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_10 ) ;
if ( V_3 & V_9 )
V_6 |= 1 ;
F_5 ( V_2 , & V_3 ) ;
}
return V_6 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_4 | V_10 ) ;
F_2 ( V_2 , V_5 , V_3 ) ;
V_3 |= V_12 ;
F_2 ( V_2 , V_5 , V_3 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_12 | V_4 ) ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
V_3 |= V_4 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
V_3 |= V_12 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
V_3 &= ~ V_4 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 |= V_4 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
V_3 &= ~ V_4 ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( 50 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_5 ) ;
V_3 &= ~ ( V_12 | V_10 ) ;
F_2 ( V_2 , V_5 , V_3 ) ;
F_11 ( V_2 ) ;
}
static bool
F_13 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_11 ;
F_10 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 200 ; V_11 ++ ) {
V_3 = F_7 ( V_2 , V_5 ) ;
if ( V_3 & V_9 )
return true ;
F_4 ( 50 ) ;
}
ASSERT ( 0 ) ;
return false ;
}
bool
F_14 ( struct V_1 * V_2 )
{
T_2 V_13 = 0 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < ( V_14 + 1 ) ; V_11 ++ )
V_13 += F_15 ( V_2 , V_11 ) ;
if ( V_13 == ( T_2 ) V_15 )
return true ;
else
return false ;
}
void
F_16 ( struct V_1 * V_2 )
{
T_2 V_13 = 0 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
V_13 += F_15 ( V_2 , V_11 ) ;
V_13 = ( T_2 ) V_15 - V_13 ;
F_17 ( V_2 , V_14 , V_13 ) ;
}
void
F_17 ( struct V_1 * V_2 , T_2 V_16 , T_2 V_6 )
{
struct V_17 * V_18 = (struct V_17 * ) V_2 -> V_19 ;
F_9 ( V_2 ) ;
F_6 ( V_2 , V_20 , 5 ) ;
F_6 ( V_2 , 0 , 4 ) ;
F_10 ( V_2 ) ;
F_6 ( V_2 , V_21 , 3 ) ;
F_6 ( V_2 , V_16 , 6 ) ;
F_6 ( V_2 , V_6 , 16 ) ;
F_13 ( V_2 ) ;
F_10 ( V_2 ) ;
F_6 ( V_2 , V_22 , 5 ) ;
F_6 ( V_2 , 0 , 4 ) ;
F_12 ( V_2 ) ;
V_18 -> V_23 = F_18 ( V_24 ) ;
}
T_2
F_15 ( struct V_1 * V_2 ,
T_2 V_16 )
{
T_2 V_6 ;
F_9 ( V_2 ) ;
F_6 ( V_2 , V_25 , 3 ) ;
F_6 ( V_2 , V_16 , 6 ) ;
V_6 = F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_6 ;
}
bool
F_19 ( struct V_1 * V_2 )
{
T_2 V_11 ;
T_2 V_13 = 0 ;
struct V_17 * V_18 ;
F_20 () ;
V_18 = (struct V_17 * ) V_2 -> V_19 ;
F_21 ( L_1 ) ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ ) {
T_2 V_27 ;
V_27 = F_15 ( V_2 , V_11 ) ;
V_13 += V_27 ;
V_2 -> V_19 [ V_11 ] = F_18 ( V_27 ) ;
}
if ( V_13 != ( T_2 ) V_15 ) {
F_21 ( L_2 ) ;
V_18 -> V_23 = F_18 ( V_24 ) ;
return false ;
}
if ( ( V_18 -> V_23 & F_18 ( V_28 ) )
!= F_18 ( V_29 ) ) {
F_21 ( L_3 ) ;
return false ;
}
return true ;
}
static bool
F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = (struct V_17 * ) V_2 -> V_19 ;
if ( ( V_18 -> V_23 & F_18 ( V_28 ) )
== F_18 ( V_29 ) ) {
return true ;
} else {
return F_19 ( V_2 ) ;
}
}
T_3
F_23 ( struct V_1 * V_2 , T_2 V_30 )
{
if ( ( V_30 < V_26 ) &&
( F_22 ( V_2 ) == true ) ) {
return V_2 -> V_19 [ V_30 ] ;
}
return 0 ;
}
void
F_24 ( struct V_1 * V_2 ,
T_4 * V_31 )
{
int V_11 ;
struct V_17 * V_18 = (struct V_17 * ) V_2 -> V_19 ;
F_20 () ;
if ( F_22 ( V_2 ) == true ) {
for ( V_11 = 0 ; V_11 < V_32 ; V_11 ++ ) {
V_31 [ V_11 ] = V_18 -> V_31 [ V_11 ] ;
}
F_21 ( L_4 , V_31 ) ;
}
}
T_1
F_25 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 ) == true )
return F_26 ( V_2 -> V_19 [ V_33 ] )
| ( F_26 ( V_2 -> V_19 [ V_34 ] ) << 16 ) ;
return 0 ;
}
T_2
F_27 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = (struct V_17 * ) V_2 -> V_19 ;
if ( F_22 ( V_2 ) == true )
return F_26 ( V_18 -> V_35 ) ;
return 0 ;
}
