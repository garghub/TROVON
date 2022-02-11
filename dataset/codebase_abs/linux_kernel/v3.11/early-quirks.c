static void T_1 F_1 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 , V_2 , V_3 , 0x68 ) ;
if ( V_4 & ( 1 << 18 ) ) {
F_3 ( V_5 L_1
L_2 ) ;
if ( ( V_4 & ( 1 << 17 ) ) == 0 ) {
F_3 ( V_5 L_3
L_4 ) ;
F_3 ( V_5 L_5
L_6 ) ;
V_4 |= ( 1 << 17 ) ;
F_4 ( V_1 , V_2 , V_3 , 0x68 , V_4 ) ;
}
}
}
static void T_1 F_5 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_6
if ( ( V_6 > V_7 || V_8 ) &&
! V_9 ) {
F_3 ( V_5
L_7
L_8 ) ;
V_10 = 1 ;
}
#endif
}
static int T_1 F_7 ( struct V_11 * V_12 )
{
return 0 ;
}
static void T_1 F_8 ( int V_1 , int V_2 , int V_3 )
{
#ifdef F_9
#ifdef F_10
if ( V_13 )
return;
if ( F_11 ( V_14 , F_7 ) ) {
V_15 = 1 ;
F_3 ( V_5 L_9
L_10
L_11 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
#endif
#endif
}
static T_2 T_1 F_12 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
T_3 V_17 ;
V_17 = F_13 ( V_1 , V_2 , V_3 , 0xac ) ;
V_17 &= ~ ( 1 << 5 ) ;
F_14 ( V_1 , V_2 , V_3 , 0xac , V_17 ) ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x70 ) ;
V_16 |= 1 << 8 ;
F_4 ( V_1 , V_2 , V_3 , 0x70 , V_16 ) ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x8 ) ;
V_16 &= 0xff ;
return V_16 ;
}
static void T_1 F_15 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
T_3 V_17 ;
if ( V_13 )
return;
V_16 = F_12 ( V_1 , V_2 , V_3 ) ;
if ( V_16 < 0x82 )
V_15 = 1 ;
else {
F_16 ( 0x72 , 0xcd6 ) ; V_17 = F_17 ( 0xcd7 ) ;
if ( ! ( V_17 & 0x2 ) )
V_15 = 1 ;
}
if ( V_15 ) {
F_3 ( V_5 L_14 , V_16 ) ;
F_3 ( V_5 L_15 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
}
static T_2 T_1 F_18 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 ;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x8 ) ;
V_16 &= 0xff ;
return V_16 ;
}
static void T_1 F_19 ( int V_1 , int V_2 , int V_3 )
{
T_2 V_16 , V_18 ;
V_18 = F_18 ( V_1 , V_2 , V_3 ) ;
if ( V_18 >= 0x40 )
V_19 = 1 ;
if ( V_18 >= 0x39 )
return;
if ( V_13 )
return;
V_16 = F_2 ( V_1 , V_2 , V_3 , 0x64 ) ;
if ( ! ( V_16 & ( 1 << 14 ) ) )
V_15 = 1 ;
if ( V_15 ) {
F_3 ( V_5 L_16 , V_18 ) ;
F_3 ( V_5 L_15 ) ;
F_3 ( V_5 L_12
L_13 ) ;
}
}
static void T_1 F_15 ( int V_1 , int V_2 , int V_3 )
{
}
static void T_1 F_19 ( int V_1 , int V_2 , int V_3 )
{
}
static void T_1 F_20 ( int V_1 , int V_2 , int V_3 )
{
T_3 V_20 ;
T_4 V_21 ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
V_20 = F_13 ( V_1 , V_2 , V_3 , V_23 ) ;
if ( V_20 == 0x13 )
F_22 () ;
else if ( ( V_21 == 0x3405 ) &&
( ( V_20 == 0x12 ) ||
( V_20 == 0x22 ) ) )
F_22 () ;
}
static int T_1 F_23 ( int V_1 , int V_2 , int V_3 )
{
T_4 V_24 ;
T_4 V_25 ;
T_4 V_21 ;
T_3 type ;
int V_26 ;
V_24 = F_21 ( V_1 , V_2 , V_3 , V_27 ) ;
if ( V_24 == 0xffff )
return - 1 ;
V_25 = F_21 ( V_1 , V_2 , V_3 , V_28 ) ;
V_21 = F_21 ( V_1 , V_2 , V_3 , V_22 ) ;
for ( V_26 = 0 ; V_29 [ V_26 ] . V_30 != NULL ; V_26 ++ ) {
if ( ( ( V_29 [ V_26 ] . V_25 == V_31 ) ||
( V_29 [ V_26 ] . V_25 == V_25 ) ) &&
( ( V_29 [ V_26 ] . V_21 == V_31 ) ||
( V_29 [ V_26 ] . V_21 == V_21 ) ) &&
( ! ( ( V_29 [ V_26 ] . V_24 ^ V_24 ) &
V_29 [ V_26 ] . V_32 ) ) ) {
if ( ( V_29 [ V_26 ] . V_33 &
V_34 ) != V_34 )
V_29 [ V_26 ] . V_30 ( V_1 , V_2 , V_3 ) ;
V_29 [ V_26 ] . V_33 |= V_35 ;
}
}
type = F_13 ( V_1 , V_2 , V_3 ,
V_36 ) ;
if ( ! ( type & 0x80 ) )
return - 1 ;
return 0 ;
}
void T_1 F_24 ( void )
{
int V_2 , V_3 ;
if ( ! F_25 () )
return;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ )
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( F_23 ( 0 , V_2 , V_3 ) )
break;
}
}
