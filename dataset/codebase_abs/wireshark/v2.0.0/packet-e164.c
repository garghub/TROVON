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
static T_5
F_4 ( T_6 V_16 , T_6 * V_17 )
{
T_5 V_18 = TRUE ;
T_6 V_19 = 0 ;
T_6 V_20 = 1 ;
while ( V_16 ) {
if ( ( V_16 & 0x0f ) > 9 )
V_18 = FALSE ;
V_19 += ( V_16 & 0x0f ) * V_20 ;
V_16 >>= 4 ;
V_20 *= 10 ;
}
* V_17 = V_19 ;
return V_18 ;
}
void
F_5 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_7 V_21 )
{
int V_22 ;
T_8 V_23 ;
T_6 V_24 = 0 ;
T_8 V_25 ;
T_8 V_4 ;
T_6 V_26 = 0 ;
T_5 V_27 = FALSE ;
T_4 * V_28 = NULL ;
V_22 = V_3 ;
V_23 = F_6 ( V_1 , V_22 ) ;
switch ( V_21 ) {
case V_29 :
while ( V_23 == 0 ) {
V_22 = V_22 + 1 ;
V_23 = F_6 ( V_1 , V_22 ) ;
}
V_26 = F_7 ( V_1 , V_22 ) ;
if ( ( V_23 & 0xf0 ) != 0 ) {
V_26 = V_26 >> 4 ;
}
break;
case V_30 :
V_26 = V_23 & 0x0f ;
V_26 = V_26 << 4 ;
V_26 = V_26 | ( V_23 & 0xf0 ) >> 4 ;
V_26 = V_26 << 4 ;
if ( F_8 ( V_1 , V_22 + 1 , 1 ) ) {
V_23 = F_6 ( V_1 , V_22 + 1 ) ;
V_26 = V_26 | ( V_23 & 0x0f ) ;
}
break;
case V_31 :
V_26 = ( F_6 ( V_1 , V_22 ) - '0' ) << 8 ;
V_26 |= ( F_6 ( V_1 , V_22 + 1 ) - '0' ) << 4 ;
V_26 |= ( F_6 ( V_1 , V_22 + 2 ) - '0' ) ;
break;
}
switch ( V_26 & 0x0f00 ) {
case 0x0 :
V_25 = 1 ;
break;
case 0x0100 :
V_25 = 1 ;
break;
case 0x0200 :
switch ( V_26 & 0x00f0 ) {
case 0 :
case 0x70 :
V_25 = 2 ;
break;
default:
V_25 = 3 ;
break;
}
break;
case 0x0300 :
switch ( V_26 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x60 :
case 0x90 :
V_25 = 2 ;
break;
default:
V_25 = 3 ;
break;
}
break;
case 0x0400 :
switch ( V_26 & 0x00f0 ) {
case 0x20 :
V_25 = 3 ;
break;
default:
V_25 = 2 ;
break;
}
break;
case 0x0500 :
switch ( V_26 & 0x00f0 ) {
case 0 :
case 0x90 :
V_25 = 3 ;
break;
default:
V_25 = 2 ;
break;
}
break;
case 0x0600 :
switch ( V_26 & 0x00f0 ) {
case 0x70 :
case 0x80 :
case 0x90 :
V_25 = 3 ;
break;
default:
V_25 = 2 ;
break;
}
break;
case 0x0700 :
V_25 = 1 ;
break;
case 0x0800 :
switch ( V_26 & 0x00f0 ) {
case 0x10 :
case 0x20 :
case 0x40 :
case 0x60 :
V_25 = 2 ;
break;
default:
V_25 = 3 ;
break;
}
break;
case 0x0900 :
switch ( V_26 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x50 :
case 0x80 :
V_25 = 2 ;
break;
default:
V_25 = 3 ;
break;
}
break;
default:
V_25 = 0 ;
break;
}
switch ( V_25 ) {
case 1 :
V_26 = V_26 >> 8 ;
V_4 = 1 ;
break;
case 2 :
V_26 = V_26 >> 4 ;
V_4 = 1 ;
break;
default:
V_4 = 2 ;
break;
}
V_27 = F_4 ( V_26 , & V_26 ) ;
if ( V_21 == V_31 )
V_28 = F_9 ( V_2 , V_32 , V_1 , V_22 , V_25 , V_26 ) ;
else
V_28 = F_9 ( V_2 , V_32 , V_1 , V_22 , V_4 , V_26 ) ;
if ( ! V_27 ) {
F_10 ( NULL , V_28 , & V_33 ) ;
}
switch ( V_26 ) {
case 881 :
switch ( V_21 ) {
case V_29 :
V_24 = F_6 ( V_1 , V_22 + 1 ) & 0x0f ;
break;
case V_30 :
V_24 = ( F_6 ( V_1 , V_22 + 1 ) & 0xf0 ) >> 4 ;
break;
case V_31 :
V_24 = F_6 ( V_1 , V_22 + V_25 ) - '0' ;
break;
}
V_27 = ( V_24 <= 9 ) ;
V_28 = F_11 ( V_2 , V_34 , V_1 , ( V_22 + 1 ) , 1 ,
V_24 , L_1 , V_24 , F_12 ( V_24 , V_35 , L_2 ) ) ;
if ( ! V_27 ) {
F_10 ( NULL , V_28 , & V_36 ) ;
}
break;
case 882 :
switch ( V_21 ) {
case V_29 :
V_24 = F_7 ( V_1 , V_22 + 1 ) ;
V_24 = ( V_24 & 0x0ff0 ) >> 4 ;
break;
case V_30 :
V_24 = F_6 ( V_1 , V_22 + 1 ) & 0xf0 ;
V_24 |= F_6 ( V_1 , V_22 + 2 ) & 0x0f ;
break;
case V_31 :
V_24 = ( F_6 ( V_1 , V_22 + V_25 ) - '0' ) << 4 ;
V_24 |= ( F_6 ( V_1 , V_22 + V_25 + 1 ) - '0' ) ;
break;
}
V_27 = F_4 ( V_24 , & V_24 ) ;
V_28 = F_11 ( V_2 , V_34 , V_1 , ( V_22 + 1 ) , 2 ,
V_24 , L_1 , V_24 , F_13 ( V_24 , & V_37 , L_2 ) ) ;
if ( ! V_27 ) {
F_10 ( NULL , V_28 , & V_36 ) ;
}
break;
case 883 :
switch ( V_21 ) {
case V_29 :
V_24 = F_7 ( V_1 , V_22 + 1 ) ;
V_24 = V_24 & 0x0fff ;
break;
case V_30 :
V_24 = ( F_6 ( V_1 , V_22 + 1 ) & 0xf0 ) << 4 ;
V_24 |= ( F_6 ( V_1 , V_22 + 2 ) & 0x0f ) << 4 ;
V_24 |= ( F_6 ( V_1 , V_22 + 2 ) & 0xf0 ) >> 4 ;
break;
case V_31 :
V_24 = ( F_6 ( V_1 , V_22 + V_25 ) - '0' ) << 8 ;
V_24 |= ( F_6 ( V_1 , V_22 + V_25 + 1 ) - '0' ) << 4 ;
V_24 |= ( F_6 ( V_1 , V_22 + V_25 + 2 ) - '0' ) ;
break;
}
if ( ( V_24 & 0x0ff0 ) == 0x510 ) {
switch ( V_21 ) {
case V_29 :
V_24 = ( V_24 << 4 ) | ( ( F_6 ( V_1 , V_22 + 3 ) & 0xf0 ) >> 4 ) ;
break;
case V_30 :
V_24 = ( V_24 << 4 ) | ( F_6 ( V_1 , V_22 + 3 ) & 0x0f ) ;
break;
case V_31 :
V_24 = ( V_24 << 4 ) | ( F_6 ( V_1 , V_22 + V_25 + 3 ) - '0' ) ;
break;
}
V_27 = F_4 ( V_24 , & V_24 ) ;
V_28 = F_11 ( V_2 , V_34 , V_1 , ( V_22 + 1 ) , 3 ,
V_24 , L_1 , V_24 , F_12 ( V_24 , V_38 , L_2 ) ) ;
if ( ! V_27 ) {
F_10 ( NULL , V_28 , & V_36 ) ;
}
} else {
V_27 = F_4 ( V_24 , & V_24 ) ;
V_28 = F_11 ( V_2 , V_34 , V_1 , ( V_22 + 1 ) , 2 ,
V_24 , L_1 , V_24 , F_12 ( V_24 , V_38 , L_2 ) ) ;
if ( ! V_27 ) {
F_10 ( NULL , V_28 , & V_36 ) ;
}
}
break;
default:
break;
}
}
const T_9 *
F_14 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , T_7 V_21 )
{
T_4 * V_6 ;
T_2 * V_39 ;
const T_9 * V_40 ;
switch ( V_21 ) {
case V_31 :
V_40 = F_15 ( F_16 () , V_1 , V_3 , V_4 , V_41 ) ;
break;
case V_30 :
V_40 = F_17 ( V_1 , V_3 , V_4 , NULL , FALSE ) ;
break;
case V_29 :
default:
F_18 () ;
}
V_6 = F_2 ( V_2 , V_15 , V_1 , V_3 , V_4 , V_40 ) ;
V_39 = F_19 ( V_6 , V_42 ) ;
F_5 ( V_1 , V_39 , V_3 , V_21 ) ;
return V_40 ;
}
void
F_20 ( void )
{
static T_10 V_43 [] = {
{ & V_9 ,
{ L_3 , L_4 ,
V_44 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_12 ,
{ L_5 , L_6 ,
V_44 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_15 ,
{ L_7 , L_8 ,
V_44 , V_45 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_34 ,
{ L_9 , L_10 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_46 } } ,
{ & V_32 ,
{ L_11 , L_12 ,
V_49 , V_48 | V_50 , & V_51 , 0x0 ,
NULL , V_46 } } ,
} ;
static T_11 * V_52 [] = {
& V_42 ,
} ;
static T_12 V_53 [] = {
{ & V_33 , { L_13 , V_54 , V_55 , L_14 , V_56 } } ,
{ & V_36 , { L_15 , V_54 , V_55 , L_16 , V_56 } } ,
} ;
T_13 * V_57 ;
V_58 = F_21 ( L_17 , L_18 , L_19 ) ;
F_22 ( V_58 , V_43 , F_23 ( V_43 ) ) ;
F_24 ( V_52 , F_23 ( V_52 ) ) ;
V_57 = F_25 ( V_58 ) ;
F_26 ( V_57 , V_53 , F_23 ( V_53 ) ) ;
}
