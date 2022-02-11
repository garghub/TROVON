T_1 F_1 (
T_2 * V_1 )
{
const T_3 * V_2 = NULL ;
T_1 V_3 = 0 ;
T_1 V_4 = 0 ;
if( ( V_1 -> V_5 . type != F_2 () ) ||
( V_1 -> V_6 . type != F_2 () ) ) {
return V_3 ; }
if( ( V_1 -> V_5 . V_7 != 20 ) ||
( V_1 -> V_6 . V_7 != 20 ) ) {
return V_3 ; }
V_2 = ( const T_3 * ) V_1 -> V_5 . V_8 ;
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
V_2 = ( const T_3 * ) V_1 -> V_6 . V_8 ;
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
int F_3 ( T_2 * V_1 V_9 )
{
int V_10 = V_11 ;
const T_3 * V_2 = NULL ;
T_1 V_4 = 0 ;
if( ( V_1 -> V_5 . type != F_2 () ) || ( V_1 -> V_6 . type != F_2 () ) ) {
return V_10 ; }
if( ( V_1 -> V_5 . V_7 != 20 ) || ( V_1 -> V_6 . V_7 != 20 ) ) {
return V_10 ; }
V_2 = ( const T_3 * ) V_1 -> V_5 . V_8 ;
V_4 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) | ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) || ( V_4 == 0x47002741 ) ) {
V_10 = V_12 ;
}
V_2 = ( const T_3 * ) V_1 -> V_6 . V_8 ;
V_4 = ( ( V_2 [ 0 ] << 24 ) | ( V_2 [ 1 ] << 16 ) | ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ) ;
if( ( V_4 == 0x470027c1 ) || ( V_4 == 0x47002741 ) ) {
V_10 = V_13 ;
}
return V_10 ;
}
T_4 * F_4 ( void ) {
return V_14 ;
}
T_5 * F_5 (
T_6 * V_15 ,
T_7 V_16 ,
T_6 * V_17 )
{
T_5 * V_18 = NULL ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
V_20 = F_6 ( V_20 , V_15 ) ;
V_19 = ( V_20 << 16 ) | V_16 ;
V_20 = F_6 ( V_20 , V_17 ) ;
V_19 = ( V_20 << 24 ) | V_19 ;
V_18 = ( T_5 * )
F_7 ( F_4 () , V_19 ) ;
return V_18 ;
}
T_5 * F_8 (
T_6 * V_15 ,
T_7 V_16 ,
T_6 * V_17 ,
T_5 * V_21 )
{
T_5 * V_18 = NULL ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
V_20 = F_6 ( V_20 , V_15 ) ;
V_19 = ( V_20 << 16 ) | V_16 ;
V_20 = F_6 ( V_20 , V_17 ) ;
V_19 = ( V_20 << 24 ) | V_19 ;
V_18 = ( T_5 * )
F_7 (
F_4 () ,
V_19 ) ;
if( V_18 ) {
return NULL ; }
F_9 (
F_4 () ,
V_19 ,
( void * ) V_21 ) ;
return V_21 ;
}
static int
F_10 (
T_8 * V_22 ,
T_2 * V_1 ,
T_9 * V_23 ,
void * V_8 V_9 )
{
int V_24 = 0 ;
T_10 * V_25 = NULL ;
T_9 * V_26 = NULL ;
T_3 V_27 = 0 ;
T_3 V_28 = 0 ;
T_7 V_29 = 0 ;
V_30 = V_23 ;
if ( ( int ) ( V_31 ) V_8 == FALSE )
{
V_25 = F_11 (
V_23 ,
V_32 ,
V_22 ,
0 ,
0 ,
V_33 ) ;
V_26 = F_12 (
V_25 ,
V_34 ) ;
F_13 (
V_22 ,
V_1 ,
V_26 , NULL ) ;
return V_24 +
F_14 ( V_22 , V_24 ) ;
}
if ( ( int ) ( V_31 ) V_8 == TRUE )
{
V_29 = F_15 ( V_22 , V_24 ) ;
V_26 = F_16 (
V_23 , V_22 , V_24 , 0 ,
V_35 , NULL , V_36 ) ;
V_28 = F_17 ( V_22 , V_24 ) ;
F_11 ( V_26 ,
V_37 ,
V_22 ,
V_24 ,
1 ,
V_38 ) ;
switch( V_28 & V_39 ) {
case V_40 :
case V_41 :
F_11 ( V_26 ,
V_42 ,
V_22 ,
V_24 ,
1 ,
V_38 ) ;
F_11 ( V_26 ,
V_43 ,
V_22 ,
V_24 ,
1 ,
V_38 ) ;
F_11 ( V_26 ,
V_44 ,
V_22 ,
V_24 ,
1 ,
V_38 ) ;
break;
default:
break;
}
V_24 ++ ;
V_26 = F_16 (
V_23 , V_22 , V_24 , 0 ,
V_45 , NULL , V_46 ) ;
V_27 = F_17 ( V_22 , V_24 ) ;
F_18 ( V_26 , V_47 ,
V_22 ,
V_24 ,
1 ,
V_29 ,
L_1 ,
F_19 ( V_29 & V_48 , V_49 , L_2 ) ,
V_27 ) ;
switch( V_28 & V_39 ) {
case V_40 :
case V_41 :
F_11 (
V_26 ,
V_50 ,
V_22 ,
V_24 ,
1 ,
V_38 ) ;
break;
default:
break;
}
V_24 ++ ;
V_26 = F_16 (
V_23 , V_22 , V_24 , 0 ,
V_51 , NULL , V_52 ) ;
F_20 (
F_21 ( V_22 , V_24 ) ,
V_1 ,
V_26 , NULL ) ;
return V_24 +
F_14 ( V_22 , V_24 ) ;
}
return V_24 ;
}
static T_11 F_22 (
T_8 * V_22 ,
T_2 * V_1 ,
T_9 * V_23 ,
void * V_8 V_9 )
{
if ( F_23 ( V_22 ) < 2 ) {
return FALSE ; }
switch( F_15 ( V_22 , 0 ) & 0xf8ff ) {
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
F_10 (
V_22 ,
V_1 ,
V_23 ,
( void * ) TRUE ) ;
return TRUE ;
default:
break;
}
switch( F_15 ( V_22 , 0 ) & 0xfff0 ) {
case 0x0020 :
case 0x00a0 :
F_10 ( V_22 , V_1 , V_23 , ( void * ) FALSE ) ;
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
void F_24 ( void )
{
static T_12 V_53 [] = {
#include "packet-atn-ulcs-hfarr.c"
{ & V_37 ,
{ L_3 ,
L_4 ,
V_54 ,
V_55 ,
F_25 ( V_56 ) ,
0xf8 ,
L_5 ,
V_57 } } ,
{ & V_42 ,
{ L_6 ,
L_7 ,
V_54 ,
V_55 ,
F_25 ( V_58 ) ,
V_59 ,
L_5 ,
V_57 } } ,
{ & V_44 ,
{ L_8 ,
L_9 ,
V_54 ,
V_55 ,
F_25 ( V_60 ) ,
0x01 ,
L_10 ,
V_57 } } ,
{ & V_43 ,
{ L_11 ,
L_12 ,
V_54 ,
V_55 ,
F_25 ( V_61 ) ,
0x02 ,
L_13 ,
V_57 } } ,
{ & V_50 ,
{ L_14 , L_15 ,
V_54 ,
V_55 ,
F_25 ( V_62 ) ,
V_63 ,
NULL ,
V_57 } } ,
{ & V_47 ,
{ L_16 , L_17 ,
V_54 ,
V_55 ,
NULL ,
V_48 ,
NULL ,
V_57 } } ,
} ;
static T_13 * V_64 [] = {
#include "packet-atn-ulcs-ettarr.c"
& V_35 ,
& V_45 ,
& V_51 ,
& V_34
} ;
V_32 = F_26 (
V_65 ,
L_18 ,
L_19 ) ;
F_27 (
V_32 ,
V_53 ,
F_28 ( V_53 ) ) ;
F_29 (
V_64 ,
F_28 ( V_64 ) ) ;
F_30 (
L_19 ,
F_10 ,
V_32 ) ;
V_66 = F_31 ( L_19 , V_32 ) ;
V_67 = F_32 ( F_33 () , F_34 () ) ;
V_14 = F_32 ( F_33 () , F_34 () ) ;
}
void F_35 ( void )
{
V_68 = F_36 ( L_20 , V_32 ) ;
V_69 = F_36 ( L_21 , V_32 ) ;
F_37 (
L_22 ,
F_22 ,
L_23 ,
L_24 ,
V_32 , V_70 ) ;
}
