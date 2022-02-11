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
V_4 = F_9 ( V_6 ) ;
V_4 &= ~ V_7 ;
V_4 |= V_8 ;
F_10 ( V_4 , V_6 ) ;
V_4 = F_9 ( V_9 ) ;
V_4 &= ~ V_10 ;
F_10 ( V_4 , V_9 ) ;
}
static int T_1 F_11 ( char * V_11 )
{
if ( V_11 )
F_12 ( V_12 , V_11 ,
sizeof( V_12 ) ) ;
return 1 ;
}
static void F_13 (
struct V_13 * V_14 ,
const char * V_15 )
{
const char * V_16 = V_15 ;
V_14 -> V_17 = 0 ;
V_14 -> V_18 = 0 ;
while ( * V_16 ) {
char V_19 = * V_16 ++ ;
switch ( V_19 ) {
case '0' ... '9' :
if ( V_14 -> V_17 & V_20 ) {
F_14 ( V_21 L_1
L_2 , V_19 ) ;
} else {
int V_22 = V_19 - '0' ;
if ( V_22 >= F_8 ( V_23 ) )
F_14 ( V_21 L_3
L_4 , V_19 ) ;
else {
V_14 -> V_18 = V_22 ;
}
}
V_14 -> V_17 |= V_20 ;
break;
}
}
}
static void T_1 F_15 ( void )
{
T_2 V_24 ;
struct V_13 V_14 = { 0 } ;
F_14 ( V_21 L_5 ,
V_12 ) ;
F_13 ( & V_14 , V_12 ) ;
V_25 . V_26 [ 0 ] = & V_23 [ V_14 . V_18 ] ;
F_14 ( V_21 L_6 ,
V_25 . V_26 [ 0 ] -> V_27 . V_28 ,
V_25 . V_26 [ 0 ] -> V_27 . V_29 ) ;
F_16 ( & V_30 ) ;
F_17 ( & V_25 ) ;
F_18 ( NULL ) ;
V_24 = F_9 ( V_31 ) &
~ ( V_32 << V_33 ) ;
V_24 |= ( ( 1 << V_34 ) |
( 1 << V_35 ) |
( 1 << V_36 ) ) <<
V_33 ;
F_10 ( V_24 , V_31 ) ;
F_10 ( ( 0 << V_37 ) |
( 6 << V_38 ) |
( 4 << V_39 ) |
( 1 << V_40 ) |
( 13 << V_41 ) |
( 4 << V_42 ) |
( 0 << V_43 ) , V_44 ) ;
F_19 ( F_20 ( 15 ) , L_7 ) ;
F_19 ( F_3 ( 0 ) , L_7 ) ;
F_21 ( V_45 , F_8 ( V_45 ) ) ;
}
