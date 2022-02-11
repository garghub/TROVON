static void T_1 F_1 ( void )
{
F_2 ( 50000000 ) ;
}
static void T_1 F_3 ( void )
{
* V_1 &= ~ ( V_2 | V_3 ) ;
}
static void T_1 F_4 ( void )
{
volatile T_2 * V_4 ;
F_5 ( V_5 L_1
L_2 ) ;
V_4 = F_6 ( 0 , V_6 ,
V_7 ) ;
do {
* V_4 = 0xffffffff ;
F_7 () ;
} while ( * V_4 != 0xfe000008 );
V_4 = F_6 ( 0 , V_6 ,
V_8 ) ;
do {
* V_4 = 0xffffffff ;
F_7 () ;
} while ( * V_4 != 0xc0000008 );
* V_4 = 0x40000008 ;
}
static void T_1 F_8 ( void )
{
F_5 ( V_5 L_3 ) ;
while ( ( * V_1 & V_2 ) == 0 )
F_7 () ;
}
void T_1 F_9 ( void )
{
F_5 ( L_4 ) ;
* V_9 = 0x0001e000 ;
if ( ! F_10 () )
F_3 () ;
* V_10 = ( 0x2000000 - 1 ) & ~ 0x3ffff ;
* V_11 = ( 0x40000000 - 1 ) & ~ 0xfffff ;
F_11 () ;
if ( F_10 () ) {
F_4 () ;
* V_12 = 0x00000008 ;
} else {
F_8 () ;
F_12 ( L_5 ) ;
}
}
static void T_3 F_13 ( struct V_13 * V_14 )
{
if ( F_14 () ) {
V_14 -> V_15 [ 2 ] . V_16 = 0 ;
V_14 -> V_15 [ 2 ] . V_17 = 0 ;
V_14 -> V_15 [ 2 ] . V_18 = 0 ;
}
}
static int T_1 F_15 ( int V_19 , struct V_20 * V_21 )
{
V_21 -> V_22 = 0x00000000 ;
F_16 ( V_19 , V_21 ) ;
return 1 ;
}
static int T_1 F_17 ( const struct V_13 * V_14 , T_4 V_23 ,
T_4 V_24 )
{
if ( F_10 () ) {
if( ! V_14 -> V_25 -> V_26 ) {
if( V_14 -> V_27 == V_6 )
return V_28 ;
return - 1 ;
}
if( V_14 -> V_25 -> V_26 -> V_27 == V_29 &&
V_14 -> V_25 -> V_30 -> V_26 -> V_27 == V_31 &&
! V_14 -> V_25 -> V_30 -> V_26 -> V_25 -> V_30 )
return V_32 ;
if( V_14 -> V_25 -> V_26 -> V_27 == V_31 ) {
switch( V_14 -> V_27 ) {
case V_29 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
}
}
return - 1 ;
} else return V_37 ;
}
static void T_1 F_18 ( void )
{
volatile T_2 * V_4 ;
F_5 ( V_5 L_6 ) ;
V_4 = ( volatile T_2 * ) F_6 ( 0 ,
V_6 ,
V_38 ) ;
* V_4 |= V_2 ;
}
static void T_1 F_19 ( void )
{
volatile T_2 * V_4 ;
F_5 ( V_5 L_7 ) ;
V_4 = ( volatile T_2 * ) F_6 ( 0 ,
V_6 ,
V_38 ) ;
while ( ( * V_4 & V_3 ) == 0 )
F_7 () ;
}
static void T_1 F_20 ( void )
{
F_5 ( V_5 L_8 ) ;
* V_1 |= V_3 ;
}
static void T_1 F_21 ( void )
{
if ( ! F_10 () ) {
F_22 () ;
F_20 () ;
}
}
int T_1 F_23 ( void )
{
if ( F_14 () ) {
struct V_13 * V_14 ;
F_24 ( & V_39 ) ;
if ( F_10 () ) {
V_14 = F_25 ( 1 , V_40 ) ;
F_26 ( V_14 ) ;
F_27 ( V_14 ) ;
F_18 () ;
F_19 () ;
} else {
V_14 = F_25 ( 1 , V_33 ) ;
F_26 ( V_14 ) ;
F_27 ( V_14 ) ;
}
}
return 0 ;
}
void T_1 F_28 ( void )
{
F_29 ( V_41 , V_42 , V_43 ) ;
}
