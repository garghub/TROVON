static int F_1 (
T_1 * T_2 V_1 ,
int T_3 V_1 ,
T_4 * T_5 V_1 ,
T_6 * T_7 V_1 ,
int T_8 V_1 )
{
T_3 = F_2 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ,
V_2 ,
V_3 ,
& T_5 -> V_4 . V_5 ) ;
return T_3 ;
}
T_9 F_3 (
T_1 * T_2 V_1 ,
T_9 T_3 ,
T_4 * T_5 ,
T_6 * T_7 V_1 ,
int T_8 V_1 ,
T_10 V_6 )
{
memset ( & T_5 -> V_4 , '\0' , sizeof( T_5 -> V_4 ) ) ;
T_5 -> V_4 . T_8 = - 1 ;
T_5 -> V_4 . V_5 = - 1 ;
T_5 -> V_4 . V_7 . V_8 . V_6 = V_6 ;
T_3 = F_1 (
T_2 ,
T_3 ,
T_5 ,
T_7 ,
T_8 ) ;
memset (
& T_5 -> V_4 ,
'\0' ,
sizeof( T_5 -> V_4 ) ) ;
T_5 -> V_4 . T_8 = - 1 ;
T_5 -> V_4 . V_5 = - 1 ;
return T_3 ;
}
T_9 F_4 (
T_11 * V_9 )
{
T_12 * V_10 = NULL ;
T_9 V_11 = 0 ;
T_9 V_12 = 0 ;
if( ( V_9 -> V_13 . type != V_14 ) ||
( V_9 -> V_15 . type != V_14 ) ) {
return V_11 ; }
if( ( V_9 -> V_13 . V_16 != 20 ) ||
( V_9 -> V_15 . V_16 != 20 ) ) {
return V_11 ; }
V_10 = ( T_12 * ) V_9 -> V_13 . V_17 ;
V_12 =
( ( V_10 [ 0 ] << 24 ) |
( V_10 [ 1 ] << 16 ) |
( V_10 [ 2 ] << 8 ) |
V_10 [ 3 ] ) ;
if( ( V_12 == 0x470027c1 ) ||
( V_12 == 0x47002741 ) ) {
V_11 = ( ( V_10 [ 8 ] ) << 16 ) |
( ( V_10 [ 9 ] ) << 8 ) |
( V_10 [ 10 ] ) ;
}
V_10 = ( T_12 * ) V_9 -> V_15 . V_17 ;
V_12 = ( ( V_10 [ 0 ] << 24 ) |
( V_10 [ 1 ] << 16 ) |
( V_10 [ 2 ] << 8 ) |
V_10 [ 3 ] ) ;
if( ( V_12 == 0x470027c1 ) ||
( V_12 == 0x47002741 ) ) {
V_11 = ( ( V_10 [ 8 ] ) << 16 ) |
( ( V_10 [ 9 ] ) << 8 ) |
( V_10 [ 10 ] ) ;
}
return V_11 ;
}
int F_5 ( T_11 * V_9 V_1 )
{
int V_18 = V_19 ;
T_12 * V_10 = NULL ;
T_9 V_12 = 0 ;
if( ( V_9 -> V_13 . type != V_14 ) || ( V_9 -> V_15 . type != V_14 ) ) {
return V_18 ; }
if( ( V_9 -> V_13 . V_16 != 20 ) || ( V_9 -> V_15 . V_16 != 20 ) ) {
return V_18 ; }
V_10 = ( T_12 * ) V_9 -> V_13 . V_17 ;
V_12 = ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
if( ( V_12 == 0x470027c1 ) || ( V_12 == 0x47002741 ) ) {
V_18 = V_20 ;
}
V_10 = ( T_12 * ) V_9 -> V_15 . V_17 ;
V_12 = ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
if( ( V_12 == 0x470027c1 ) || ( V_12 == 0x47002741 ) ) {
V_18 = V_21 ;
}
return V_18 ;
}
T_13 * F_6 ( void ) {
return V_22 ;
}
T_14 * F_7 (
T_15 * V_23 ,
T_16 V_24 ,
T_15 * V_25 )
{
T_14 * V_26 = NULL ;
T_9 V_27 = 0 ;
T_9 V_28 = 0 ;
F_8 ( V_28 , V_23 ) ;
V_27 = ( V_28 << 16 ) | V_24 ;
F_8 ( V_28 , V_25 ) ;
V_27 = ( V_28 << 24 ) | V_27 ;
V_26 = ( T_14 * )
F_9 ( F_6 () , V_27 ) ;
return V_26 ;
}
T_14 * F_10 (
T_15 * V_23 ,
T_16 V_24 ,
T_15 * V_25 ,
T_14 * V_29 )
{
T_14 * V_26 = NULL ;
T_9 V_27 = 0 ;
T_9 V_28 = 0 ;
F_8 ( V_28 , V_23 ) ;
V_27 = ( V_28 << 16 ) | V_24 ;
F_8 ( V_28 , V_25 ) ;
V_27 = ( V_28 << 24 ) | V_27 ;
V_26 = ( T_14 * )
F_9 (
F_6 () ,
V_27 ) ;
if( V_26 ) {
return NULL ; }
F_11 (
F_6 () ,
V_27 ,
( void * ) V_29 ) ;
return V_29 ;
}
static int
F_12 (
T_1 * T_2 ,
T_11 * V_9 ,
T_6 * T_7 ,
void * V_17 V_1 )
{
int T_3 = 0 ;
T_17 * V_30 = NULL ;
T_6 * V_31 = NULL ;
T_12 V_32 = 0 ;
T_12 V_33 = 0 ;
T_16 V_34 = 0 ;
V_35 = T_7 ;
if ( ( int ) ( V_36 ) V_17 == FALSE )
{
V_30 = F_13 (
T_7 ,
V_37 ,
T_2 ,
0 ,
0 ,
FALSE ) ;
V_31 = F_14 (
V_30 ,
V_38 ) ;
F_15 (
T_2 ,
V_9 ,
V_31 ) ;
return T_3 +
F_16 ( T_2 , T_3 ) ;
}
if ( ( int ) ( V_36 ) V_17 == TRUE )
{
V_34 = F_17 ( T_2 , T_3 ) ;
V_30 = F_18 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_39 ) ;
V_31 = F_14 (
V_30 ,
V_40 ) ;
V_33 = F_19 ( T_2 , T_3 ) ;
F_13 ( V_31 ,
V_41 ,
T_2 ,
T_3 ,
1 ,
V_42 ) ;
switch( V_33 & V_43 ) {
case V_44 :
case V_45 :
F_13 ( V_31 ,
V_46 ,
T_2 ,
T_3 ,
1 ,
V_42 ) ;
F_13 ( V_31 ,
V_47 ,
T_2 ,
T_3 ,
1 ,
V_42 ) ;
F_13 ( V_31 ,
V_48 ,
T_2 ,
T_3 ,
1 ,
V_42 ) ;
break;
default:
break;
}
T_3 ++ ;
V_30 = F_18 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_49 ) ;
V_31 = F_14 ( V_30 , V_50 ) ;
V_32 = F_19 ( T_2 , T_3 ) ;
F_18 ( V_31 ,
T_2 ,
T_3 ,
1 ,
L_1 ,
F_20 ( V_34 & V_51 , V_52 , L_2 ) ,
V_32 ) ;
switch( V_33 & V_43 ) {
case V_44 :
case V_45 :
F_13 (
V_31 ,
V_53 ,
T_2 ,
T_3 ,
1 ,
V_42 ) ;
break;
default:
break;
}
T_3 ++ ;
V_30 = F_18 (
T_7 ,
T_2 ,
T_3 ,
0 ,
V_54 ) ;
V_31 = F_14 (
V_30 ,
V_55 ) ;
F_21 (
F_22 ( T_2 , T_3 ) ,
V_9 ,
V_31 ) ;
return T_3 +
F_16 ( T_2 , T_3 ) ;
}
return T_3 ;
}
static T_18 F_23 (
T_1 * T_2 ,
T_11 * V_9 ,
T_6 * T_7 ,
void * V_17 V_1 )
{
if ( F_16 ( T_2 , 0 ) < 2 ) {
return FALSE ; }
switch( F_17 ( T_2 , 0 ) & 0xf8ff ) {
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
F_12 (
T_2 ,
V_9 ,
T_7 ,
( void * ) TRUE ) ;
return TRUE ;
default:
break;
}
switch( F_17 ( T_2 , 0 ) & 0xfff0 ) {
case 0x0020 :
case 0x00a0 :
F_12 ( T_2 , V_9 , T_7 , ( void * ) FALSE ) ;
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
void F_24 ( void )
{
static T_19 V_56 [] = {
#include "packet-atn-ulcs-hfarr.c"
{ & V_41 ,
{ L_3 ,
L_4 ,
V_57 ,
V_58 ,
F_25 ( V_59 ) ,
0xf8 ,
L_5 ,
V_60 } } ,
{ & V_46 ,
{ L_6 ,
L_7 ,
V_57 ,
V_58 ,
F_25 ( V_61 ) ,
V_62 ,
L_5 ,
V_60 } } ,
{ & V_48 ,
{ L_8 ,
L_9 ,
V_57 ,
V_58 ,
F_25 ( V_63 ) ,
0x01 ,
L_10 ,
V_60 } } ,
{ & V_47 ,
{ L_11 ,
L_12 ,
V_57 ,
V_58 ,
F_25 ( V_64 ) ,
0x02 ,
L_13 ,
V_60 } } ,
{ & V_53 ,
{ L_14 , L_15 ,
V_57 ,
V_58 ,
F_25 ( V_65 ) ,
V_66 ,
NULL ,
V_60 } } ,
} ;
static T_20 * V_67 [] = {
#include "packet-atn-ulcs-ettarr.c"
& V_40 ,
& V_50 ,
& V_55 ,
& V_38
} ;
V_37 = F_26 (
V_68 ,
L_16 ,
L_17 ) ;
F_27 (
V_37 ,
V_56 ,
F_28 ( V_56 ) ) ;
F_29 (
V_67 ,
F_28 ( V_67 ) ) ;
F_30 (
L_17 ,
F_12 ,
V_37 ) ;
V_69 = F_31 ( L_18 ) ;
V_70 = F_31 ( L_19 ) ;
F_32 (
L_17 ,
& V_71 ) ;
V_72 = F_33 ( F_34 () , F_35 () ) ;
V_22 = F_33 ( F_34 () , F_35 () ) ;
}
void F_36 ( void )
{
F_37 (
L_20 ,
F_23 ,
V_37 ) ;
}
