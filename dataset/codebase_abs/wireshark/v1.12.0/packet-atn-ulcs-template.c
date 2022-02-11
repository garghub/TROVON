T_1 F_1 (
T_2 * V_1 )
{
const T_3 * V_2 = NULL ;
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
if( ( V_1 -> V_5 . type != V_6 ) ||
( V_1 -> V_7 . type != V_6 ) ) {
return V_3 ; }
if( ( V_1 -> V_5 . V_8 != 20 ) ||
( V_1 -> V_7 . V_8 != 20 ) ) {
return V_3 ; }
V_2 = ( const T_3 * ) V_1 -> V_5 . V_9 ;
V_4 =
( ( V_2 [ 0 ] << 24 ) |
( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) |
V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) ||
( V_4 == 0x47002741 ) ) {
V_3 = ( ( V_2 [ 8 ] ) << 16 ) |
( ( V_2 [ 9 ] ) << 8 ) |
( V_2 [ 10 ] ) ;
}
V_2 = ( const T_3 * ) V_1 -> V_7 . V_9 ;
V_4 = ( ( V_2 [ 0 ] << 24 ) |
( V_2 [ 1 ] << 16 ) |
( V_2 [ 2 ] << 8 ) |
V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) ||
( V_4 == 0x47002741 ) ) {
V_3 = ( ( V_2 [ 8 ] ) << 16 ) |
( ( V_2 [ 9 ] ) << 8 ) |
( V_2 [ 10 ] ) ;
}
return V_3 ;
}
int F_2 ( T_2 * V_1 V_10 )
{
int V_11 = V_12 ;
const T_3 * V_2 = NULL ;
T_1 V_4 = 0 ;
if( ( V_1 -> V_5 . type != V_6 ) || ( V_1 -> V_7 . type != V_6 ) ) {
return V_11 ; }
if( ( V_1 -> V_5 . V_8 != 20 ) || ( V_1 -> V_7 . V_8 != 20 ) ) {
return V_11 ; }
V_2 = ( const T_3 * ) V_1 -> V_5 . V_9 ;
V_4 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) | ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) || ( V_4 == 0x47002741 ) ) {
V_11 = V_13 ;
}
V_2 = ( const T_3 * ) V_1 -> V_7 . V_9 ;
V_4 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) | ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) || ( V_4 == 0x47002741 ) ) {
V_11 = V_14 ;
}
return V_11 ;
}
T_4 * F_3 ( void ) {
return V_15 ;
}
T_5 * F_4 (
T_6 * V_16 ,
T_7 V_17 ,
T_6 * V_18 )
{
T_5 * V_19 = NULL ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
F_5 ( V_21 , V_16 ) ;
V_20 = ( V_21 << 16 ) | V_17 ;
F_5 ( V_21 , V_18 ) ;
V_20 = ( V_21 << 24 ) | V_20 ;
V_19 = ( T_5 * )
F_6 ( F_3 () , V_20 ) ;
return V_19 ;
}
T_5 * F_7 (
T_6 * V_16 ,
T_7 V_17 ,
T_6 * V_18 ,
T_5 * V_22 )
{
T_5 * V_19 = NULL ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
F_5 ( V_21 , V_16 ) ;
V_20 = ( V_21 << 16 ) | V_17 ;
F_5 ( V_21 , V_18 ) ;
V_20 = ( V_21 << 24 ) | V_20 ;
V_19 = ( T_5 * )
F_6 (
F_3 () ,
V_20 ) ;
if( V_19 ) {
return NULL ; }
F_8 (
F_3 () ,
V_20 ,
( void * ) V_22 ) ;
return V_22 ;
}
static int
F_9 (
T_8 * V_23 ,
T_2 * V_1 ,
T_9 * V_24 ,
void * V_9 V_10 )
{
int V_25 = 0 ;
T_10 * V_26 = NULL ;
T_9 * V_27 = NULL ;
T_3 V_28 = 0 ;
T_3 V_29 = 0 ;
T_7 V_30 = 0 ;
V_31 = V_24 ;
if ( ( int ) ( V_32 ) V_9 == FALSE )
{
V_26 = F_10 (
V_24 ,
V_33 ,
V_23 ,
0 ,
0 ,
V_34 ) ;
V_27 = F_11 (
V_26 ,
V_35 ) ;
F_12 (
V_23 ,
V_1 ,
V_27 ) ;
return V_25 +
F_13 ( V_23 , V_25 ) ;
}
if ( ( int ) ( V_32 ) V_9 == TRUE )
{
V_30 = F_14 ( V_23 , V_25 ) ;
V_26 = F_15 (
V_24 ,
V_23 ,
V_25 ,
0 ,
V_36 ) ;
V_27 = F_11 (
V_26 ,
V_37 ) ;
V_29 = F_16 ( V_23 , V_25 ) ;
F_10 ( V_27 ,
V_38 ,
V_23 ,
V_25 ,
1 ,
V_39 ) ;
switch( V_29 & V_40 ) {
case V_41 :
case V_42 :
F_10 ( V_27 ,
V_43 ,
V_23 ,
V_25 ,
1 ,
V_39 ) ;
F_10 ( V_27 ,
V_44 ,
V_23 ,
V_25 ,
1 ,
V_39 ) ;
F_10 ( V_27 ,
V_45 ,
V_23 ,
V_25 ,
1 ,
V_39 ) ;
break;
default:
break;
}
V_25 ++ ;
V_26 = F_15 (
V_24 ,
V_23 ,
V_25 ,
0 ,
V_46 ) ;
V_27 = F_11 ( V_26 , V_47 ) ;
V_28 = F_16 ( V_23 , V_25 ) ;
F_15 ( V_27 ,
V_23 ,
V_25 ,
1 ,
L_1 ,
F_17 ( V_30 & V_48 , V_49 , L_2 ) ,
V_28 ) ;
switch( V_29 & V_40 ) {
case V_41 :
case V_42 :
F_10 (
V_27 ,
V_50 ,
V_23 ,
V_25 ,
1 ,
V_39 ) ;
break;
default:
break;
}
V_25 ++ ;
V_26 = F_15 (
V_24 ,
V_23 ,
V_25 ,
0 ,
V_51 ) ;
V_27 = F_11 (
V_26 ,
V_52 ) ;
F_18 (
F_19 ( V_23 , V_25 ) ,
V_1 ,
V_27 ) ;
return V_25 +
F_13 ( V_23 , V_25 ) ;
}
return V_25 ;
}
static T_11 F_20 (
T_8 * V_23 ,
T_2 * V_1 ,
T_9 * V_24 ,
void * V_9 V_10 )
{
if ( F_21 ( V_23 ) < 2 ) {
return FALSE ; }
switch( F_14 ( V_23 , 0 ) & 0xf8ff ) {
case 0xe802 :
case 0xf802 :
case 0xf002 :
case 0xd802 :
case 0xe002 :
case 0xe012 :
case 0xe022 :
case 0xe032 :
case 0xe042 :
case 0xe052 :
case 0xe062 :
case 0xe072 :
case 0xa002 :
case 0xa012 :
case 0xa022 :
case 0xa032 :
case 0xa042 :
case 0xa052 :
case 0xa062 :
case 0xa072 :
F_9 (
V_23 ,
V_1 ,
V_24 ,
( void * ) TRUE ) ;
return TRUE ;
default:
break;
}
switch( F_14 ( V_23 , 0 ) & 0xfff0 ) {
case 0x0020 :
case 0x00a0 :
F_9 ( V_23 , V_1 , V_24 , ( void * ) FALSE ) ;
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
void F_22 ( void )
{
static T_12 V_53 [] = {
#include "packet-atn-ulcs-hfarr.c"
{ & V_38 ,
{ L_3 ,
L_4 ,
V_54 ,
V_55 ,
F_23 ( V_56 ) ,
0xf8 ,
L_5 ,
V_57 } } ,
{ & V_43 ,
{ L_6 ,
L_7 ,
V_54 ,
V_55 ,
F_23 ( V_58 ) ,
V_59 ,
L_5 ,
V_57 } } ,
{ & V_45 ,
{ L_8 ,
L_9 ,
V_54 ,
V_55 ,
F_23 ( V_60 ) ,
0x01 ,
L_10 ,
V_57 } } ,
{ & V_44 ,
{ L_11 ,
L_12 ,
V_54 ,
V_55 ,
F_23 ( V_61 ) ,
0x02 ,
L_13 ,
V_57 } } ,
{ & V_50 ,
{ L_14 , L_15 ,
V_54 ,
V_55 ,
F_23 ( V_62 ) ,
V_63 ,
NULL ,
V_57 } } ,
} ;
static T_13 * V_64 [] = {
#include "packet-atn-ulcs-ettarr.c"
& V_37 ,
& V_47 ,
& V_52 ,
& V_35
} ;
V_33 = F_24 (
V_65 ,
L_16 ,
L_17 ) ;
F_25 (
V_33 ,
V_53 ,
F_26 ( V_53 ) ) ;
F_27 (
V_64 ,
F_26 ( V_64 ) ) ;
F_28 (
L_17 ,
F_9 ,
V_33 ) ;
V_66 = F_29 ( L_18 ) ;
V_67 = F_29 ( L_19 ) ;
F_30 (
L_17 ,
& V_68 ) ;
V_69 = F_31 ( F_32 () , F_33 () ) ;
V_15 = F_31 ( F_32 () , F_33 () ) ;
}
void F_34 ( void )
{
F_35 (
L_20 ,
F_20 ,
V_33 ) ;
}
