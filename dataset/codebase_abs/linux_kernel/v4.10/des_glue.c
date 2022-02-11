static void F_1 ( T_1 * V_1 , const T_1 * V_2 )
{
const T_1 * V_3 = V_2 + ( V_4 / 2 ) - 1 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 / 2 ; V_5 ++ )
* V_1 ++ = * V_3 -- ;
}
static int F_2 ( struct V_6 * V_7 , const T_2 * V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_3 * V_12 = & V_7 -> V_13 ;
T_3 V_14 [ V_4 ] ;
int V_15 ;
V_15 = F_4 ( V_14 , V_8 ) ;
if ( F_5 ( V_15 == 0 ) && ( * V_12 & V_16 ) ) {
* V_12 |= V_17 ;
return - V_18 ;
}
F_6 ( ( const T_3 * ) V_8 , & V_11 -> V_19 [ 0 ] ) ;
F_1 ( & V_11 -> V_20 [ 0 ] , & V_11 -> V_19 [ 0 ] ) ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 , T_2 * V_21 , const T_2 * V_22 )
{
struct V_10 * V_23 = F_3 ( V_7 ) ;
const T_1 * V_24 = V_23 -> V_19 ;
F_8 ( V_24 , ( const T_1 * ) V_22 , ( T_1 * ) V_21 ) ;
}
static void F_9 ( struct V_6 * V_7 , T_2 * V_21 , const T_2 * V_22 )
{
struct V_10 * V_23 = F_3 ( V_7 ) ;
const T_1 * V_24 = V_23 -> V_20 ;
F_8 ( V_24 , ( const T_1 * ) V_22 , ( T_1 * ) V_21 ) ;
}
static int F_10 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 , bool V_29 )
{
struct V_10 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
if ( V_29 )
F_14 ( & V_23 -> V_19 [ 0 ] ) ;
else
F_14 ( & V_23 -> V_20 [ 0 ] ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
F_16 ( ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static int F_19 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
return F_10 ( V_26 , V_21 , V_22 , V_28 , true ) ;
}
static int F_20 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
return F_10 ( V_26 , V_21 , V_22 , V_28 , false ) ;
}
static int F_21 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_10 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
F_14 ( & V_23 -> V_19 [ 0 ] ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
F_22 ( ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 , ( T_1 * ) V_31 . V_39 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static int F_23 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_10 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
F_14 ( & V_23 -> V_20 [ 0 ] ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
F_24 ( ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 , ( T_1 * ) V_31 . V_39 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static int F_25 ( struct V_6 * V_7 , const T_2 * V_8 ,
unsigned int V_9 )
{
struct V_40 * V_11 = F_3 ( V_7 ) ;
const T_3 * V_24 = ( const T_3 * ) V_8 ;
T_3 * V_12 = & V_7 -> V_13 ;
T_1 V_41 [ V_4 / 2 ] ;
T_1 V_42 [ V_4 / 2 ] ;
T_1 V_43 [ V_4 / 2 ] ;
if ( F_5 ( ! ( ( V_24 [ 0 ] ^ V_24 [ 2 ] ) | ( V_24 [ 1 ] ^ V_24 [ 3 ] ) ) ||
! ( ( V_24 [ 2 ] ^ V_24 [ 4 ] ) | ( V_24 [ 3 ] ^ V_24 [ 5 ] ) ) ) &&
( * V_12 & V_16 ) ) {
* V_12 |= V_17 ;
return - V_18 ;
}
F_6 ( ( const T_3 * ) V_8 , V_41 ) ;
V_8 += V_44 ;
F_6 ( ( const T_3 * ) V_8 , V_42 ) ;
V_8 += V_44 ;
F_6 ( ( const T_3 * ) V_8 , V_43 ) ;
memcpy ( & V_11 -> V_19 [ 0 ] , & V_41 [ 0 ] , sizeof( V_41 ) ) ;
F_1 ( & V_11 -> V_19 [ V_4 / 2 ] , & V_42 [ 0 ] ) ;
memcpy ( & V_11 -> V_19 [ ( V_4 / 2 ) * 2 ] ,
& V_43 [ 0 ] , sizeof( V_43 ) ) ;
F_1 ( & V_11 -> V_20 [ 0 ] , & V_43 [ 0 ] ) ;
memcpy ( & V_11 -> V_20 [ V_4 / 2 ] ,
& V_42 [ 0 ] , sizeof( V_42 ) ) ;
F_1 ( & V_11 -> V_20 [ ( V_4 / 2 ) * 2 ] ,
& V_41 [ 0 ] ) ;
return 0 ;
}
static void F_26 ( struct V_6 * V_7 , T_2 * V_21 , const T_2 * V_22 )
{
struct V_40 * V_23 = F_3 ( V_7 ) ;
const T_1 * V_24 = V_23 -> V_19 ;
F_27 ( V_24 , ( const T_1 * ) V_22 , ( T_1 * ) V_21 ) ;
}
static void F_28 ( struct V_6 * V_7 , T_2 * V_21 , const T_2 * V_22 )
{
struct V_40 * V_23 = F_3 ( V_7 ) ;
const T_1 * V_24 = V_23 -> V_20 ;
F_27 ( V_24 , ( const T_1 * ) V_22 , ( T_1 * ) V_21 ) ;
}
static int F_29 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 , bool V_29 )
{
struct V_40 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
const T_1 * V_24 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
if ( V_29 )
V_24 = & V_23 -> V_19 [ 0 ] ;
else
V_24 = & V_23 -> V_20 [ 0 ] ;
F_30 ( V_24 ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
const T_1 * V_45 = ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ;
F_31 ( V_24 , V_45 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static int F_32 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
return F_29 ( V_26 , V_21 , V_22 , V_28 , true ) ;
}
static int F_33 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
return F_29 ( V_26 , V_21 , V_22 , V_28 , false ) ;
}
static int F_34 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_40 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
const T_1 * V_24 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
V_24 = & V_23 -> V_19 [ 0 ] ;
F_30 ( V_24 ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
const T_1 * V_45 = ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ;
F_35 ( V_24 , V_45 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 ,
( T_1 * ) V_31 . V_39 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static int F_36 ( struct V_25 * V_26 ,
struct V_27 * V_21 , struct V_27 * V_22 ,
unsigned int V_28 )
{
struct V_40 * V_23 = F_11 ( V_26 -> V_7 ) ;
struct V_30 V_31 ;
const T_1 * V_24 ;
int V_32 ;
F_12 ( & V_31 , V_21 , V_22 , V_28 ) ;
V_32 = F_13 ( V_26 , & V_31 ) ;
V_26 -> V_12 &= ~ V_33 ;
V_24 = & V_23 -> V_20 [ 0 ] ;
F_30 ( V_24 ) ;
while ( ( V_28 = V_31 . V_28 ) ) {
unsigned int V_34 = V_28 & V_35 ;
if ( F_15 ( V_34 ) ) {
const T_1 * V_45 = ( const T_1 * ) V_31 . V_22 . V_36 . V_37 ;
F_37 ( V_24 , V_45 ,
( T_1 * ) V_31 . V_21 . V_36 . V_37 ,
V_34 ,
( T_1 * ) V_31 . V_39 ) ;
}
V_28 &= V_38 - 1 ;
V_32 = F_17 ( V_26 , & V_31 , V_28 ) ;
}
F_18 ( 0 ) ;
return V_32 ;
}
static bool T_4 F_38 ( void )
{
unsigned long V_46 ;
if ( ! ( V_47 & V_48 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_46 & V_49 ) )
return false ;
return true ;
}
static int T_4 F_39 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_40 ( V_50 ) ; V_5 ++ )
F_41 ( & V_50 [ V_5 ] . V_51 ) ;
if ( F_38 () ) {
F_42 ( L_1 ) ;
return F_43 ( V_50 , F_40 ( V_50 ) ) ;
}
F_42 ( L_2 ) ;
return - V_52 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_50 , F_40 ( V_50 ) ) ;
}
