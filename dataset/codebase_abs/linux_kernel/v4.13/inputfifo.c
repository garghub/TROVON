static unsigned F_1 (
unsigned V_1 )
{
return V_1 |
( V_2 << V_3 ) |
( V_4 << V_5 ) ;
}
T_1 void
F_2 ( unsigned V_6 )
{
while ( ! F_3 ( V_7 ) )
F_4 () ;
F_5 ( V_7 , V_6 ) ;
return;
}
static void F_6 (
unsigned int V_8 )
{
unsigned int V_6 = ( 1 << V_9 ) |
( V_8 << V_10 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_7 (
unsigned int V_8 )
{
unsigned int V_6 = ( 1 << V_11 ) |
( V_8 << V_12 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_8 (
unsigned int V_13 ,
unsigned int V_14 )
{
unsigned int V_6 = ( ( 1 << V_9 ) |
( 1 << V_11 ) |
( V_13 << V_10 ) |
( V_14 << V_12 ) ) ;
F_2 ( V_6 ) ;
return;
}
static void F_9 ( void )
{
T_2 V_6 = F_1 (
1 << V_15 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_10 ( void )
{
T_2 V_6 = F_1 (
1 << V_16 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_11 ( void )
{
T_2 V_6 = F_1 (
1 << V_17 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_12 ( void )
{
T_2 V_6 = F_1 (
1 << V_18 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_13 (
unsigned int V_19 )
{
T_2 V_6 ;
V_2 = V_19 & V_20 ;
V_6 = F_1 ( 0 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_14 (
unsigned int V_21 )
{
T_2 V_6 ;
V_4 = V_21 & V_22 ;
V_6 = F_1 ( 0 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_15 (
unsigned int V_19 ,
unsigned int V_21 )
{
T_2 V_6 ;
V_2 = V_19 & V_20 ;
V_4 = V_21 & V_22 ;
V_6 = F_1 ( 0 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_16 ( void )
{
T_2 V_6 = F_1 ( 0 ) ;
F_2 ( V_6 ) ;
return;
}
static void F_17 (
unsigned int V_19 ,
unsigned int V_21 )
{
F_15 ( V_19 , V_21 ) ;
F_11 () ;
return;
}
static void F_18 (
unsigned int V_23 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
F_16 () ;
F_12 () ;
return;
}
static void F_19 (
const unsigned short * V_8 ,
unsigned int V_25 ,
const unsigned short * V_26 ,
unsigned int V_27 ,
unsigned int V_28 ,
unsigned int V_23 ,
unsigned int V_29 ,
enum V_30 type )
{
unsigned int V_24 , V_31 = 0 , V_32 = 0 ;
assert ( V_8 != NULL ) ;
assert ( ( V_26 != NULL ) || ( V_27 == 0 ) ) ;
if ( type == V_33 )
V_31 = 1 ;
if ( type == V_34 )
V_32 = 1 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_16 () ;
F_9 () ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ )
F_16 () ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ , V_8 ++ ) {
unsigned int V_35 = V_29 ;
if ( ( V_31 || V_32 ) && ( V_24 % 3 == 2 ) )
V_35 = 0 ;
if ( V_35 ) {
if ( V_24 + 1 == V_25 ) {
F_8 (
V_8 [ 0 ] , 0 ) ;
} else {
F_8 (
V_8 [ 0 ] , V_8 [ 1 ] ) ;
}
V_8 ++ ;
V_24 ++ ;
} else if ( V_29 && V_32 ) {
F_7 ( V_8 [ 0 ] ) ;
} else {
F_6 ( V_8 [ 0 ] ) ;
}
}
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ , V_26 ++ ) {
unsigned int V_35 = V_29 ;
if ( ( V_31 || V_32 ) && ( V_24 % 3 == 2 ) )
V_35 = 0 ;
if ( V_35 ) {
if ( V_24 + 1 == V_27 ) {
F_8 (
V_26 [ 0 ] , 0 ) ;
} else {
F_8 (
V_26 [ 0 ] , V_26 [ 1 ] ) ;
}
V_26 ++ ;
V_24 ++ ;
} else if ( V_29 && V_32 ) {
F_7 ( V_26 [ 0 ] ) ;
} else {
F_6 ( V_26 [ 0 ] ) ;
}
}
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
F_16 () ;
F_10 () ;
return;
}
static void
F_20 ( const unsigned short * V_8 ,
unsigned int V_25 ,
unsigned int V_28 ,
unsigned int V_23 ,
unsigned int V_29 ,
enum V_30 type )
{
assert ( V_8 != NULL ) ;
F_19 ( V_8 , V_25 , NULL , 0 ,
V_28 ,
V_23 ,
V_29 ,
type ) ;
}
static void F_21 (
const unsigned short * V_8 ,
unsigned int V_25 ,
unsigned int V_36 ,
unsigned int V_19 ,
unsigned int V_21 ,
unsigned int V_28 ,
unsigned int V_23 ,
unsigned int V_29 ,
enum V_30 type )
{
unsigned int V_24 ;
assert ( V_8 != NULL ) ;
F_17 ( V_19 , V_21 ) ;
for ( V_24 = 0 ; V_24 < V_36 ; V_24 ++ ) {
if ( ( type == V_37 ) &&
( V_24 & 1 ) == 1 ) {
F_20 ( V_8 , 2 * V_25 ,
V_28 ,
V_23 ,
V_29 , type ) ;
V_8 += 2 * V_25 ;
} else {
F_20 ( V_8 , V_25 ,
V_28 ,
V_23 ,
V_29 , type ) ;
V_8 += V_25 ;
}
}
F_18 ( V_23 ) ;
return;
}
static enum V_30 F_22 (
enum V_38 V_39 )
{
enum V_30 type ;
type = V_40 ;
if ( V_39 == V_41 ) {
type =
V_34 ;
} else if ( V_39 == V_42 ||
V_39 == V_43 ||
V_39 == V_44 ) {
type =
V_37 ;
} else if ( V_39 >= V_45 &&
V_39 <= V_46 ) {
type =
V_33 ;
}
return type ;
}
static struct V_47 * F_23 (
unsigned int V_19 )
{
return & V_48 [ V_19 ] ;
}
void F_24 (
const unsigned short * V_8 ,
unsigned int V_25 ,
unsigned int V_36 ,
unsigned int V_19 ,
enum V_38 V_39 ,
bool V_29 )
{
unsigned int V_21 , V_28 , V_23 ;
enum V_30 type ;
assert ( V_8 != NULL ) ;
V_28 = V_49 ;
V_23 = V_50 ;
F_25 ( V_39 ,
V_51 ,
& V_21 ) ;
type = F_22 ( V_39 ) ;
F_21 ( V_8 , V_25 , V_36 ,
V_19 , V_21 , V_28 , V_23 ,
V_29 , type ) ;
}
void F_26 (
unsigned int V_19 ,
enum V_38 V_39 ,
bool V_29 )
{
struct V_47 * V_52 ;
V_52 = F_23 ( V_19 ) ;
V_52 -> V_19 = V_19 ;
F_25 ( V_39 ,
V_51 ,
& V_52 -> V_21 ) ;
V_52 -> V_29 = V_29 ;
V_52 -> type = F_22 ( V_39 ) ;
V_52 -> V_28 = V_49 ;
V_52 -> V_23 = V_50 ;
V_52 -> V_53 = true ;
F_17 ( V_19 , V_52 -> V_21 ) ;
return;
}
void F_27 (
unsigned int V_19 ,
const unsigned short * V_8 ,
unsigned int V_25 ,
const unsigned short * V_26 ,
unsigned int V_27 )
{
struct V_47 * V_52 ;
assert ( V_8 != NULL ) ;
assert ( ( V_26 != NULL ) || ( V_27 == 0 ) ) ;
V_52 = F_23 ( V_19 ) ;
V_2 = ( V_52 -> V_19 ) & V_20 ;
V_4 = ( V_52 -> V_21 ) & V_22 ;
F_19 ( V_8 , V_25 , V_26 , V_27 ,
V_52 -> V_28 ,
V_52 -> V_23 ,
V_52 -> V_29 ,
V_52 -> type ) ;
}
void F_28 (
unsigned int V_19 ,
enum V_38 V_54 ,
const unsigned short * V_8 ,
unsigned int V_25 )
{
struct V_47 * V_52 ;
unsigned int V_21 ;
assert ( V_8 != NULL ) ;
V_52 = F_23 ( V_19 ) ;
F_25 ( V_54 ,
V_51 , & V_21 ) ;
V_4 = V_21 & V_22 ;
F_20 ( V_8 , V_25 , V_52 -> V_28 , V_52 -> V_23 ,
V_52 -> V_29 , V_40 ) ;
}
void F_29 (
unsigned int V_19 )
{
struct V_47 * V_52 ;
V_52 = F_23 ( V_19 ) ;
V_2 = ( V_52 -> V_19 ) & V_20 ;
V_4 = ( V_52 -> V_21 ) & V_22 ;
F_18 ( V_52 -> V_23 ) ;
V_52 -> V_53 = false ;
return;
}
