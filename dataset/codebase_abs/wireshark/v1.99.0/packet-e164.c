void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , T_3 V_5 )
{
T_4 * V_6 ;
switch ( V_5 . V_7 ) {
case V_8 :
F_2 ( V_2 , V_9 , V_1 , V_3 ,
V_4 , V_5 . V_10 ) ;
break;
case V_11 :
F_2 ( V_2 , V_12 , V_1 , V_3 ,
V_4 , V_5 . V_10 ) ;
break;
default:
break;
}
if ( V_5 . V_13 == V_14 ) {
V_6 = F_2 ( V_2 , V_15 , V_1 , V_3 , V_4 , V_5 . V_10 ) ;
F_3 ( V_6 ) ;
}
}
void
F_4 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_5 V_16 )
{
int V_17 ;
T_6 V_18 ;
T_7 V_19 = 0 ;
T_6 V_20 ;
T_6 V_4 ;
T_7 V_21 = 0 ;
V_17 = V_3 ;
V_18 = F_5 ( V_1 , V_17 ) ;
switch ( V_16 ) {
case V_22 :
while ( V_18 == 0 ) {
V_17 = V_17 + 1 ;
V_18 = F_5 ( V_1 , V_17 ) ;
}
V_21 = F_6 ( V_1 , V_17 ) ;
if ( ( V_18 & 0xf0 ) != 0 ) {
V_21 = V_21 >> 4 ;
}
break;
case V_23 :
V_21 = V_18 & 0x0f ;
V_21 = V_21 << 4 ;
V_21 = V_21 | ( V_18 & 0xf0 ) >> 4 ;
V_21 = V_21 << 4 ;
if ( F_7 ( V_1 , V_17 + 1 , 1 ) ) {
V_18 = F_5 ( V_1 , V_17 + 1 ) ;
V_21 = V_21 | ( V_18 & 0x0f ) ;
}
break;
case V_24 :
V_21 = ( F_5 ( V_1 , V_17 ) - '0' ) << 8 ;
V_21 |= ( F_5 ( V_1 , V_17 + 1 ) - '0' ) << 4 ;
V_21 |= ( F_5 ( V_1 , V_17 + 2 ) - '0' ) ;
break;
}
switch ( V_21 & 0x0f00 ) {
case 0x0 :
V_20 = 1 ;
break;
case 0x0100 :
V_20 = 1 ;
break;
case 0x0200 :
switch ( V_21 & 0x00f0 ) {
case 0 :
case 0x70 :
V_20 = 2 ;
break;
default:
V_20 = 3 ;
break;
}
break;
case 0x0300 :
switch ( V_21 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x60 :
case 0x90 :
V_20 = 2 ;
break;
default:
V_20 = 3 ;
break;
}
break;
case 0x0400 :
switch ( V_21 & 0x00f0 ) {
case 0x20 :
V_20 = 3 ;
break;
default:
V_20 = 2 ;
break;
}
break;
case 0x0500 :
switch ( V_21 & 0x00f0 ) {
case 0 :
case 0x90 :
V_20 = 3 ;
break;
default:
V_20 = 2 ;
break;
}
break;
case 0x0600 :
switch ( V_21 & 0x00f0 ) {
case 0x70 :
case 0x80 :
case 0x90 :
V_20 = 3 ;
break;
default:
V_20 = 2 ;
break;
}
break;
case 0x0700 :
V_20 = 1 ;
break;
case 0x0800 :
switch ( V_21 & 0x00f0 ) {
case 0x10 :
case 0x20 :
case 0x40 :
case 0x60 :
V_20 = 2 ;
break;
default:
V_20 = 3 ;
break;
}
break;
case 0x0900 :
switch ( V_21 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x50 :
case 0x80 :
V_20 = 2 ;
break;
default:
V_20 = 3 ;
break;
}
break;
default:
V_20 = 0 ;
break;
}
switch ( V_20 ) {
case 1 :
V_21 = V_21 >> 8 ;
V_4 = 1 ;
break;
case 2 :
V_21 = V_21 >> 4 ;
V_4 = 1 ;
break;
default:
V_4 = 2 ;
break;
}
if ( V_16 == V_24 )
F_8 ( V_2 , V_25 , V_1 , V_17 , V_20 , V_21 ) ;
else
F_8 ( V_2 , V_25 , V_1 , V_17 , V_4 , V_21 ) ;
switch ( V_21 ) {
case 0x881 :
switch ( V_16 ) {
case V_22 :
V_19 = F_5 ( V_1 , V_17 + 1 ) & 0x0f ;
break;
case V_23 :
V_19 = ( F_5 ( V_1 , V_17 + 1 ) & 0xf0 ) >> 4 ;
break;
case V_24 :
V_19 = F_5 ( V_1 , V_17 + V_20 ) - '0' ;
break;
}
F_9 ( V_2 , V_26 , V_1 , ( V_17 + 1 ) , 1 ,
V_19 , L_1 , V_19 , F_10 ( V_19 , V_27 , L_2 ) ) ;
break;
case 0x882 :
switch ( V_16 ) {
case V_22 :
V_19 = F_6 ( V_1 , V_17 + 1 ) ;
V_19 = ( V_19 & 0x0ff0 ) >> 4 ;
break;
case V_23 :
V_19 = F_5 ( V_1 , V_17 + 1 ) & 0xf0 ;
V_19 |= F_5 ( V_1 , V_17 + 2 ) & 0x0f ;
break;
case V_24 :
V_19 = ( F_5 ( V_1 , V_17 + V_20 ) - '0' ) << 4 ;
V_19 |= ( F_5 ( V_1 , V_17 + V_20 + 1 ) - '0' ) ;
break;
}
F_9 ( V_2 , V_26 , V_1 , ( V_17 + 1 ) , 2 ,
V_19 , L_1 , V_19 , F_11 ( V_19 , & V_28 , L_2 ) ) ;
break;
case 0x883 :
switch ( V_16 ) {
case V_22 :
V_19 = F_6 ( V_1 , V_17 + 1 ) ;
V_19 = V_19 & 0x0fff ;
break;
case V_23 :
V_19 = ( F_5 ( V_1 , V_17 + 1 ) & 0xf0 ) << 4 ;
V_19 |= ( F_5 ( V_1 , V_17 + 2 ) & 0x0f ) << 4 ;
V_19 |= ( F_5 ( V_1 , V_17 + 2 ) & 0xf0 ) >> 4 ;
break;
case V_24 :
V_19 = ( F_5 ( V_1 , V_17 + V_20 ) - '0' ) << 8 ;
V_19 |= ( F_5 ( V_1 , V_17 + V_20 + 1 ) - '0' ) << 4 ;
V_19 |= ( F_5 ( V_1 , V_17 + V_20 + 2 ) - '0' ) ;
break;
}
if ( ( V_19 & 0x0ff0 ) == 0x510 ) {
switch ( V_16 ) {
case V_22 :
V_19 = ( V_19 << 4 ) | ( ( F_5 ( V_1 , V_17 + 3 ) & 0xf0 ) >> 4 ) ;
break;
case V_23 :
V_19 = ( V_19 << 4 ) | ( F_5 ( V_1 , V_17 + 3 ) & 0x0f ) ;
break;
case V_24 :
V_19 = ( V_19 << 4 ) | ( F_5 ( V_1 , V_17 + V_20 + 3 ) - '0' ) ;
break;
}
F_9 ( V_2 , V_26 , V_1 , ( V_17 + 1 ) , 3 ,
V_19 , L_1 , V_19 , F_10 ( V_19 , V_29 , L_2 ) ) ;
} else {
F_9 ( V_2 , V_26 , V_1 , ( V_17 + 1 ) , 2 ,
V_19 , L_1 , V_19 , F_10 ( V_19 , V_29 , L_2 ) ) ;
}
break;
default:
break;
}
}
const T_8 *
F_12 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , T_5 V_16 )
{
T_4 * V_6 ;
T_2 * V_30 ;
const T_8 * V_31 ;
switch ( V_16 ) {
case V_24 :
V_31 = F_13 ( F_14 () , V_1 , V_3 , V_4 , V_32 ) ;
break;
case V_23 :
V_31 = F_15 ( V_1 , V_3 , V_4 , NULL , FALSE ) ;
break;
case V_22 :
default:
F_16 () ;
}
V_6 = F_2 ( V_2 , V_15 , V_1 , V_3 , V_4 , V_31 ) ;
V_30 = F_17 ( V_6 , V_33 ) ;
F_4 ( V_1 , V_30 , V_3 , V_16 ) ;
return V_31 ;
}
void
F_18 ( void )
{
static T_9 V_34 [] = {
{ & V_9 ,
{ L_3 , L_4 ,
V_35 , V_36 , NULL , 0x0 ,
NULL , V_37 } } ,
{ & V_12 ,
{ L_5 , L_6 ,
V_35 , V_36 , NULL , 0x0 ,
NULL , V_37 } } ,
{ & V_15 ,
{ L_7 , L_8 ,
V_35 , V_36 , NULL , 0x0 ,
NULL , V_37 } } ,
{ & V_26 ,
{ L_9 , L_10 ,
V_38 , V_39 , NULL , 0x0 ,
NULL , V_37 } } ,
{ & V_25 ,
{ L_11 , L_12 ,
V_40 , V_39 | V_41 , & V_42 , 0x0 ,
NULL , V_37 } } ,
} ;
static T_10 * V_43 [] = {
& V_33 ,
} ;
V_44 = F_19 ( L_13 , L_14 , L_15 ) ;
F_20 ( V_44 , V_34 , F_21 ( V_34 ) ) ;
F_22 ( V_43 , F_21 ( V_43 ) ) ;
}
