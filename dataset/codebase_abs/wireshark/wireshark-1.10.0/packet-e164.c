void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 , T_3 V_5 )
{
switch ( V_5 . V_6 ) {
case V_7 :
F_2 ( V_2 , V_8 , V_1 , V_3 ,
V_4 , V_5 . V_9 ) ;
break;
case V_10 :
F_2 ( V_2 , V_11 , V_1 , V_3 ,
V_4 , V_5 . V_9 ) ;
break;
default:
break;
}
}
void
F_3 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_4 V_12 ) {
int V_13 ;
T_5 V_14 ;
T_6 V_15 ;
T_5 V_16 ;
T_5 V_4 ;
T_6 V_17 ;
V_13 = V_3 ;
V_14 = F_4 ( V_1 , V_13 ) ;
if( ! V_12 ) {
while ( V_14 == 0 ) {
V_13 = V_13 + 1 ;
V_14 = F_4 ( V_1 , V_13 ) ;
}
V_17 = F_5 ( V_1 , V_13 ) ;
if ( ( V_14 & 0xf0 ) != 0 ) {
V_17 = V_17 >> 4 ;
}
} else{
V_17 = V_14 & 0x0f ;
V_17 = V_17 << 4 ;
V_17 = V_17 | ( V_14 & 0xf0 ) >> 4 ;
V_17 = V_17 << 4 ;
if ( F_6 ( V_1 , V_13 + 1 , 1 ) ) {
V_14 = F_4 ( V_1 , V_13 + 1 ) ;
V_17 = V_17 | ( V_14 & 0x0f ) ;
}
}
switch ( V_17 & 0x0f00 ) {
case 0x0 :
V_16 = 1 ;
break;
case 0x0100 :
V_16 = 1 ;
break;
case 0x0200 :
switch ( V_17 & 0x00f0 ) {
case 0 :
case 0x70 :
V_16 = 2 ;
break;
default :
V_16 = 3 ;
break;
}
break;
case 0x0300 :
switch ( V_17 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x60 :
case 0x90 :
V_16 = 2 ;
break;
default :
V_16 = 3 ;
break;
}
break;
case 0x0400 :
switch ( V_17 & 0x00f0 ) {
case 0x20 :
V_16 = 3 ;
break;
default :
V_16 = 2 ;
break;
}
break;
case 0x0500 :
switch ( V_17 & 0x00f0 ) {
case 0 :
case 0x90 :
V_16 = 3 ;
break;
default :
V_16 = 2 ;
break;
}
break;
case 0x0600 :
switch ( V_17 & 0x00f0 ) {
case 0x70 :
case 0x80 :
case 0x90 :
V_16 = 3 ;
break;
default :
V_16 = 2 ;
break;
}
break;
case 0x0700 :
V_16 = 1 ;
break;
case 0x0800 :
switch ( V_17 & 0x00f0 ) {
case 0x10 :
case 0x20 :
case 0x40 :
case 0x60 :
V_16 = 2 ;
break;
default :
V_16 = 3 ;
break;
}
break;
case 0x0900 :
switch ( V_17 & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x50 :
case 0x80 :
V_16 = 2 ;
break;
default :
V_16 = 3 ;
break;
}
break;
default :
V_16 = 0 ;
break;
}
switch ( V_16 ) {
case 1 :
V_17 = V_17 >> 8 ;
V_4 = 1 ;
break;
case 2 :
V_17 = V_17 >> 4 ;
V_4 = 1 ;
break;
default:
V_4 = 2 ;
break;
}
F_7 ( V_2 , V_1 , V_13 , V_4 , L_1 , V_17 ,
F_8 ( V_17 , & V_18 , L_2 ) , V_16 ) ;
switch ( V_17 ) {
case 0x881 :
if ( ! V_12 ) {
V_15 = F_4 ( V_1 , V_13 + 1 ) & 0x0f ;
} else {
V_15 = ( F_4 ( V_1 , V_13 + 1 ) & 0xf0 ) >> 4 ;
}
F_7 ( V_2 , V_1 , ( V_13 + 1 ) , 1 , L_3 , V_15 ,
F_9 ( V_15 , V_19 , L_2 ) ) ;
break;
case 0x882 :
if ( ! V_12 ) {
V_15 = F_5 ( V_1 , V_13 + 1 ) ;
V_15 = ( V_15 & 0x0ff0 ) >> 4 ;
} else {
V_15 = F_4 ( V_1 , V_13 + 1 ) & 0xf0 ;
V_15 |= F_4 ( V_1 , V_13 + 2 ) & 0x0f ;
}
F_7 ( V_2 , V_1 , ( V_13 + 1 ) , 2 , L_3 , V_15 ,
F_8 ( V_15 , & V_20 , L_2 ) ) ;
break;
case 0x883 :
if ( ! V_12 ) {
V_15 = F_5 ( V_1 , V_13 + 1 ) ;
V_15 = V_15 & 0x0fff ;
} else {
V_15 = ( F_4 ( V_1 , V_13 + 1 ) & 0xf0 ) << 4 ;
V_15 |= ( F_4 ( V_1 , V_13 + 2 ) & 0x0f ) << 4 ;
V_15 |= ( F_4 ( V_1 , V_13 + 2 ) & 0xf0 ) >> 4 ;
}
if ( ( V_15 & 0x0ff0 ) == 0x510 ) {
if ( ! V_12 ) {
V_15 = ( V_15 << 4 ) | ( ( F_4 ( V_1 , V_13 + 3 ) & 0xf0 ) >> 4 ) ;
} else {
V_15 = ( V_15 << 4 ) | ( F_4 ( V_1 , V_13 + 3 ) & 0x0f ) ;
}
F_7 ( V_2 , V_1 , ( V_13 + 1 ) , 3 , L_3 , V_15 ,
F_9 ( V_15 , V_21 , L_2 ) ) ;
} else {
F_7 ( V_2 , V_1 , ( V_13 + 1 ) , 2 , L_3 , V_15 ,
F_9 ( V_15 , V_21 , L_2 ) ) ;
}
break;
default:
break;
}
}
void
F_10 ( void )
{
static T_7 V_22 [] = {
{ & V_8 ,
{ L_4 , L_5 ,
V_23 , V_24 , NULL , 0x0 ,
NULL , V_25 } } ,
{ & V_11 ,
{ L_6 , L_7 ,
V_23 , V_24 , NULL , 0x0 ,
NULL , V_25 } }
} ;
V_26 = F_11 (
L_8 ,
L_9 ,
L_10 ) ;
F_12 ( V_26 , V_22 , F_13 ( V_22 ) ) ;
}
