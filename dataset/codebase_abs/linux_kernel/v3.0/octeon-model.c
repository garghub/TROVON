const char * F_1 ( T_1 V_1 )
{
static char V_2 [ 32 ] ;
return F_2 ( V_1 , V_2 ) ;
}
const char * F_2 ( T_1 V_1 , char * V_2 )
{
const char * V_3 ;
const char * V_4 ;
char V_5 [ 4 ] ;
int V_6 ;
const char * V_7 ;
union V_8 V_9 ;
int V_10 ;
union V_11 V_12 ;
union V_13 V_14 ;
char V_15 [ 10 ] ;
T_1 V_16 = 0 ;
V_9 . V_17 = F_3 ( V_18 ) ;
V_12 . V_17 = F_3 ( V_19 ) ;
V_14 . V_17 = F_3 ( V_20 ) ;
V_10 = F_4 () ;
switch ( ( V_1 >> 8 ) & 0xff ) {
case 6 :
case 2 :
V_14 . V_21 . V_22 = 1 ;
V_14 . V_21 . V_23 = 1 ;
break;
case 4 :
V_14 . V_21 . V_22 = 1 ;
break;
default:
break;
}
if ( V_14 . V_21 . V_22 ) {
if ( V_12 . V_21 . V_24 )
V_7 = L_1 ;
else
V_7 = L_2 ;
} else if ( V_12 . V_21 . V_24 )
V_7 = L_3 ;
else
V_7 = L_4 ;
sprintf ( V_5 , L_5 , ( ( V_1 >> 3 ) & 7 ) + 1 , V_1 & 7 ) ;
switch ( V_10 ) {
case 16 :
V_4 = L_6 ;
break;
case 15 :
V_4 = L_7 ;
break;
case 14 :
V_4 = L_8 ;
break;
case 13 :
V_4 = L_9 ;
break;
case 12 :
V_4 = L_10 ;
break;
case 11 :
V_4 = L_11 ;
break;
case 10 :
V_4 = L_12 ;
break;
case 9 :
V_4 = L_13 ;
break;
case 8 :
V_4 = L_14 ;
break;
case 7 :
V_4 = L_15 ;
break;
case 6 :
V_4 = L_16 ;
break;
case 5 :
V_4 = L_17 ;
break;
case 4 :
V_4 = L_18 ;
break;
case 3 :
V_4 = L_19 ;
break;
case 2 :
V_4 = L_20 ;
break;
case 1 :
V_4 = L_21 ;
break;
default:
V_4 = L_22 ;
break;
}
switch ( ( V_1 >> 8 ) & 0xff ) {
case 0 :
if ( V_9 . V_25 . V_26 ) {
if ( V_10 >= 16 )
V_3 = L_23 ;
else
V_3 = L_24 ;
} else
V_3 = L_15 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_25 ) ;
break;
case 1 :
strcpy ( V_5 , L_26 ) ;
break;
case 3 :
strcpy ( V_5 , L_27 ) ;
break;
default:
strcpy ( V_5 , L_28 ) ;
break;
}
break;
case 1 :
if ( ( V_1 & 0x10 ) || V_9 . V_27 . V_28 )
V_3 = L_18 ;
else
V_3 = L_29 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_30 ) ;
break;
case 2 :
strcpy ( V_5 , L_31 ) ;
break;
default:
strcpy ( V_5 , L_28 ) ;
break;
}
break;
case 2 :
V_3 = L_18 ;
if ( V_9 . V_29 . V_30 )
V_4 = L_32 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_30 ) ;
break;
case 2 :
strcpy ( V_5 , L_31 ) ;
break;
default:
strcpy ( V_5 , L_28 ) ;
break;
}
break;
case 3 :
V_3 = L_7 ;
if ( ( V_10 == 4 ) && V_12 . V_25 . V_24 )
V_4 = L_33 ;
if ( ( V_1 & 0xFF ) < 0x8 ) {
switch ( V_1 & 0x3 ) {
case 0 :
strcpy ( V_5 , L_30 ) ;
break;
case 1 :
strcpy ( V_5 , L_31 ) ;
break;
case 3 :
strcpy ( V_5 , L_34 ) ;
break;
default:
strcpy ( V_5 , L_25 ) ;
break;
}
}
break;
case 4 :
if ( V_12 . V_31 . V_32 ) {
if ( V_9 . V_31 . V_33 )
V_3 = L_8 ;
else
V_3 = L_35 ;
if ( V_12 . V_31 . V_24 )
V_7 = L_36 ;
else
V_7 = L_37 ;
} else {
if ( V_12 . V_31 . V_24 )
V_7 = L_1 ;
else {
V_7 = L_4 ;
if ( V_14 . V_21 . V_23 )
V_7 = L_2 ;
}
if ( V_9 . V_31 . V_33 )
V_3 = L_38 ;
else
V_3 = L_39 ;
}
break;
case 6 :
V_3 = L_10 ;
break;
case 7 :
if ( V_9 . V_34 . V_35 )
V_3 = L_40 ;
else
V_3 = L_9 ;
break;
default:
V_3 = L_22 ;
V_4 = L_22 ;
strcpy ( V_5 , L_28 ) ;
V_7 = L_41 ;
break;
}
V_6 = F_5 () / 1000000 ;
if ( V_3 [ 0 ] != '3' ) {
V_16 |= F_6 ( 51 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_6 ( 50 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_6 ( 49 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_6 ( 48 ) ;
if ( V_16 & 0x7ffff ) {
int V_36 = V_16 & 0x3fff ;
int V_7 = ( V_16 >> 14 ) & 0x1f ;
if ( V_7 && V_36 ) {
sprintf ( V_15 , L_42 ,
V_36 , 'A' + V_7 - 1 ) ;
V_4 = L_43 ;
V_3 = V_15 ;
} else if ( V_7 && ! V_36 ) {
sprintf ( V_15 , L_44 , V_4 ,
'A' + V_7 - 1 ) ;
V_4 = V_15 ;
} else {
sprintf ( V_15 , L_45 , V_36 ) ;
V_4 = L_43 ;
V_3 = V_15 ;
}
}
}
sprintf ( V_2 , L_46 ,
V_3 , V_4 , V_5 , V_6 , V_7 ) ;
return V_2 ;
}
