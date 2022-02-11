static void F_1 ( void T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
F_3 ( V_1 + V_3 [ V_2 ] . V_4 ,
V_3 [ V_2 ] . V_5 ,
V_3 [ V_2 ] . V_6 ) ;
}
for ( V_2 = 0 ; V_2 < F_2 ( V_7 ) ; V_2 ++ ) {
F_3 ( V_1 + V_7 [ V_2 ] . V_4 ,
V_7 [ V_2 ] . V_5 ,
V_7 [ V_2 ] . V_6 ) ;
}
}
static void F_4 (
void T_1 * V_1 , int V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_9 ) ; V_2 ++ ) {
F_3 ( V_1 +
V_9 [ V_2 ] . V_4 +
( 0x200 * V_8 ) ,
V_9 [ V_2 ] . V_5 ,
V_9 [ V_2 ] . V_6 ) ;
}
F_3 ( V_1 + ( 0x200 * V_8 ) + 0x0380 ,
0x00000000 , 0x00000010 ) ;
F_3 ( V_1 + ( 0x200 * V_8 ) + 0x03c0 ,
0x00000000 , 0x00000200 ) ;
}
static void F_5 ( void T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_10 ) ; V_2 ++ ) {
F_3 ( V_1 + V_10 [ V_2 ] . V_4 ,
V_10 [ V_2 ] . V_5 ,
V_10 [ V_2 ] . V_6 ) ;
}
}
static void F_6 (
void T_1 * V_1 , int V_8 )
{
F_7 ( 0xe0e9e038 , V_1 + 0x1fe0 + ( 4 * V_8 ) ) ;
}
static void F_8 ( void T_1 * V_1 )
{
F_3 ( V_1 + 0x0a00 , 0x0000001f , 0x000000ff ) ;
}
static void F_9 ( void T_1 * V_1 )
{
F_7 ( 0x88000000 , V_1 + 0x1ff4 ) ;
}
static void F_10 ( void T_1 * V_1 )
{
F_8 ( V_1 ) ;
F_7 ( 0xee000000 , V_1 + 0x1ff4 ) ;
}
static int F_11 ( void T_1 * V_11 )
{
unsigned long V_12 ;
int V_13 = 0 ;
T_2 V_14 , V_15 ;
V_12 = V_16 + F_12 ( 500 ) ;
do {
V_15 = ( F_13 ( V_11 + V_17 ) & F_14 ( 4 ) ) ;
V_14 = ( F_13 ( V_11 + V_18 ) & F_14 ( 4 ) ) ;
if ( V_14 && V_15 )
return 0 ;
if ( F_15 ( V_16 , V_12 ) ) {
V_13 = - V_19 ;
break;
}
F_16 () ;
} while ( true );
F_17 ( L_1 ) ;
return V_13 ;
}
static void F_18 ( void T_1 * V_11 )
{
F_7 ( 0x03 , V_11 + V_20 ) ;
}
static T_2 F_19 ( void T_1 * V_1 )
{
T_2 V_21 ;
if ( F_20 ( V_1 ) ) {
V_21 = ( F_13 ( V_1 + 0x0ec ) >> 24 ) & 0x0ff ;
V_21 |= ( ( F_13 ( V_1 + 0x0fc ) >> 16 ) & 0x00f00 ) ;
} else {
V_21 = ( F_13 ( V_1 + 0x0f8 ) >> 16 ) & 0x0fff ;
}
return V_21 ;
}
static void F_21 ( void T_1 * V_1 ,
int V_22 , int V_4 )
{
if ( F_20 ( V_1 ) ) {
F_3 ( V_1 + 0x0008 , ( ( V_22 << 5 ) + V_4 ) << 24 ,
~ 0x00ffffff ) ;
return;
}
switch ( V_22 ) {
case 1 :
V_22 = 2 ;
break;
case 2 :
V_22 = 3 ;
break;
default:
return;
}
F_3 ( V_1 + 0x00fc , ( ( V_22 << 8 ) + V_4 ) << 16 , ~ 0xf800ffff ) ;
}
static T_2 F_22 ( void T_1 * V_1 ,
int V_22 , int V_4 )
{
F_21 ( V_1 , V_22 , V_4 ) ;
return F_19 ( V_1 ) ;
}
static void F_23 ( void T_1 * V_1 ,
void T_1 * V_23 , int V_8 )
{
T_2 V_21 , V_24 , V_25 ;
V_21 = F_22 (
V_1 , V_8 + 1 , 5 ) ;
V_24 = V_21 >> 2 ;
if ( V_24 < 400 || V_24 > 700 ) {
F_3 ( V_23 , F_24 ( 2 , 1 ) , F_25 ( 2 , 1 ) ) ;
F_26 ( 1 ) ;
F_3 ( V_23 , F_24 ( 0 , 1 ) , F_25 ( 2 , 1 ) ) ;
} else {
V_25 = F_22 ( V_1 , V_8 +
1 , 0xe ) ;
F_27 ( L_2 ,
V_21 >> 2 , V_21 & 3 , ( V_25 >> 2 ) & 3 ) ;
}
}
static int F_28 ( void T_1 * V_1 ,
void T_1 * V_11 , T_2 V_26 ,
T_2 * V_27 , T_2 * V_28 )
{
void T_1 * V_29 = V_11 + 0x0600 ;
void T_1 * V_23 ;
T_2 V_30 , V_31 , V_32 ;
int V_33 , V_2 , V_34 = 1 ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ ) {
V_33 = F_13 ( V_1 + 0x1fc0 + 0x20 + ( V_2 * 0x04 ) ) & 0x1 ;
V_30 = F_13 ( V_29 + 0x0c + ( V_2 * 0x80 ) ) ;
V_31 = ( V_30 >> 30 ) & 0x1 ;
V_32 = ( V_30 >> 16 ) & 0x0ff ;
V_23 = V_1 + ( V_2 * 0x200 ) + 0x200 + 0x04 ;
if ( V_32 == 0x0ff )
V_31 = 0 ;
switch ( V_27 [ V_2 ] ) {
case 0 :
if ( ! V_33 && V_31 ) {
F_27 ( L_3 , V_2 ) ;
F_3 ( V_23 , F_24 ( 3 , 1 ) ,
F_25 ( 2 , 1 ) ) ;
V_27 [ V_2 ] = 1 ;
} else if ( ! V_31 ) {
F_27 ( L_4 , V_2 ) ;
F_23 ( V_1 ,
V_23 , V_2 ) ;
}
break;
case 1 :
if ( ! V_31 ) {
V_28 [ V_2 ] = 1 ;
V_27 [ V_2 ] = 2 ;
}
break;
case 2 :
if ( V_31 )
V_27 [ V_2 ] = 1 ;
else {
F_23 ( V_1 ,
V_23 , V_2 ) ;
V_27 [ V_2 ] = 0 ;
}
break;
default:
F_17 ( L_5 ,
V_2 , V_27 [ V_2 ] ) ;
break;
}
if ( V_32 > 0 ) {
F_3 ( V_29 + 0x08 + ( V_2 * 0x80 ) , F_24 ( 0x19 , 0 ) ,
F_25 ( 8 , 0 ) ) ;
F_3 ( V_29 + 0x08 + ( V_2 * 0x80 ) , F_24 ( 0x00 , 0 ) ,
F_25 ( 8 , 0 ) ) ;
}
V_34 &= ( V_27 [ V_2 ] == 1 ) ;
}
return V_34 ;
}
static int F_29 ( void T_1 * V_1 ,
void T_1 * V_11 )
{
T_2 V_27 [ 2 ] = { 0 , 0 } ;
int V_35 = 0 , V_36 ;
T_2 V_28 [ 2 ] ;
do {
V_28 [ 0 ] = 0 ;
V_28 [ 1 ] = 0 ;
V_36 = F_28 ( V_1 , V_11 , 2 ,
V_27 ,
V_28 ) ;
if ( V_36 )
break;
if ( V_28 [ 0 ] )
F_27 ( L_6 ) ;
if ( V_28 [ 1 ] )
F_27 ( L_7 ) ;
if ( ++ V_35 > 1 ) {
F_27 ( L_8 ) ;
return - V_19 ;
}
F_26 ( 100 ) ;
} while ( ! V_36 );
F_27 ( L_9 ) ;
return 0 ;
}
static void F_30 ( void T_1 * V_1 ,
int V_8 , int V_37 , int V_38 , int V_39 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_40 ) ; V_2 ++ ) {
F_3 ( V_1 + V_40 [ V_2 ] . V_4 + ( 0x200 * V_8 ) ,
V_40 [ V_2 ] . V_5 ,
V_40 [ V_2 ] . V_6 ) ;
}
}
static void F_31 ( void T_1 * V_1 )
{
F_3 ( V_1 + V_41 , V_42 , V_42 ) ;
F_32 ( 10 , 100 ) ;
F_3 ( V_1 + V_41 , 0 , V_42 ) ;
F_32 ( 10 , 100 ) ;
}
static int F_33 ( void T_1 * V_1 ,
void T_1 * V_11 )
{
T_2 V_13 , V_2 ;
F_9 ( V_1 ) ;
F_1 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ )
F_4 ( V_1 , V_2 ) ;
F_5 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ )
F_30 ( V_1 , V_2 , 0 , 0 , 5 ) ;
F_10 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ )
F_6 ( V_1 , V_2 ) ;
V_13 = F_11 ( V_11 ) ;
if ( V_13 )
return V_13 ;
F_18 ( V_11 ) ;
F_29 ( V_1 , V_11 ) ;
return V_13 ;
}
int F_34 ( void T_1 * V_1 , void T_1 * V_43 )
{
T_2 V_5 ;
V_5 = F_13 ( V_1 + 0xa00 ) ;
if ( V_5 & 0x1f ) {
F_27 ( L_10 ) ;
F_31 ( V_1 ) ;
}
return F_33 ( V_1 , V_43 ) ;
}
