static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 )
F_2 ( F_3 ( 0 ) , 1 ) ;
else
F_2 ( F_3 ( 0 ) , 0 ) ;
}
static void T_1 F_4 ( void )
{
T_2 V_4 ;
F_5 ( NULL , 0 ) ;
F_6 ( 12000000 ) ;
F_7 ( V_5 , F_8 ( V_5 ) ) ;
F_9 ( V_6 , V_7 ) ;
V_4 = F_10 ( V_8 ) ;
V_4 &= ~ V_9 ;
V_4 |= V_10 ;
F_11 ( V_4 , V_8 ) ;
V_4 = F_10 ( V_11 ) ;
V_4 &= ~ V_12 ;
F_11 ( V_4 , V_11 ) ;
}
static int T_1 F_12 ( char * V_13 )
{
if ( V_13 )
F_13 ( V_14 , V_13 ,
sizeof( V_14 ) ) ;
return 1 ;
}
static void F_14 (
struct V_15 * V_16 ,
const char * V_17 )
{
const char * V_18 = V_17 ;
V_16 -> V_19 = 0 ;
V_16 -> V_20 = 0 ;
while ( * V_18 ) {
char V_21 = * V_18 ++ ;
switch ( V_21 ) {
case '0' ... '9' :
if ( V_16 -> V_19 & V_22 ) {
F_15 ( V_23 L_1
L_2 , V_21 ) ;
} else {
int V_24 = V_21 - '0' ;
if ( V_24 >= F_8 ( V_25 ) )
F_15 ( V_23 L_3
L_4 , V_21 ) ;
else {
V_16 -> V_20 = V_24 ;
}
}
V_16 -> V_19 |= V_22 ;
break;
}
}
}
static void T_1 F_16 ( void )
{
T_2 V_26 ;
struct V_15 V_16 = { 0 } ;
F_15 ( V_23 L_5 ,
V_14 ) ;
F_14 ( & V_16 , V_14 ) ;
F_15 ( V_23 L_6 ,
V_25 [ V_16 . V_20 ] . V_27 [ 0 ] -> V_28 ,
V_25 [ V_16 . V_20 ] . V_27 [ 0 ] -> V_29 ) ;
F_17 ( & V_30 ) ;
F_18 ( & V_25 [ V_16 . V_20 ] ) ;
F_19 ( NULL ) ;
V_26 = F_10 ( V_31 ) &
~ ( V_32 << V_33 ) ;
V_26 |= ( ( 1 << V_34 ) |
( 1 << V_35 ) |
( 1 << V_36 ) ) <<
V_33 ;
F_11 ( V_26 , V_31 ) ;
F_11 ( ( 0 << V_37 ) |
( 6 << V_38 ) |
( 4 << V_39 ) |
( 1 << V_40 ) |
( 13 << V_41 ) |
( 4 << V_42 ) |
( 0 << V_43 ) , V_44 ) ;
F_20 ( F_21 ( 15 ) , L_7 ) ;
F_20 ( F_3 ( 0 ) , L_7 ) ;
F_22 ( V_45 , F_8 ( V_45 ) ) ;
}
