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
V_9 . V_17 = 0 ;
if ( ! F_3 ( V_18 ) )
V_9 . V_17 = F_4 ( V_19 ) ;
V_12 . V_17 = F_4 ( V_20 ) ;
V_14 . V_17 = F_4 ( V_21 ) ;
V_10 = F_5 ( F_4 ( V_22 ) ) ;
switch ( ( V_1 >> 8 ) & 0xff ) {
case 6 :
case 2 :
V_14 . V_23 . V_24 = 1 ;
V_14 . V_23 . V_25 = 1 ;
break;
case 4 :
V_14 . V_23 . V_24 = 1 ;
break;
default:
break;
}
if ( V_14 . V_23 . V_24 ) {
if ( V_12 . V_23 . V_26 )
V_7 = L_1 ;
else
V_7 = L_2 ;
} else if ( V_12 . V_23 . V_26 )
V_7 = L_3 ;
else
V_7 = L_4 ;
sprintf ( V_5 , L_5 , ( int ) ( ( V_1 >> 3 ) & 7 ) + 1 , ( int ) V_1 & 7 ) ;
switch ( V_10 ) {
case 32 :
V_4 = L_6 ;
break;
case 24 :
V_4 = L_7 ;
break;
case 16 :
V_4 = L_8 ;
break;
case 15 :
V_4 = L_9 ;
break;
case 14 :
V_4 = L_10 ;
break;
case 13 :
V_4 = L_11 ;
break;
case 12 :
V_4 = L_12 ;
break;
case 11 :
V_4 = L_13 ;
break;
case 10 :
V_4 = L_14 ;
break;
case 9 :
V_4 = L_15 ;
break;
case 8 :
V_4 = L_16 ;
break;
case 7 :
V_4 = L_17 ;
break;
case 6 :
V_4 = L_18 ;
break;
case 5 :
V_4 = L_19 ;
break;
case 4 :
V_4 = L_20 ;
break;
case 3 :
V_4 = L_21 ;
break;
case 2 :
V_4 = L_22 ;
break;
case 1 :
V_4 = L_23 ;
break;
default:
V_4 = L_24 ;
break;
}
switch ( ( V_1 >> 8 ) & 0xff ) {
case 0 :
if ( V_9 . V_27 . V_28 ) {
if ( V_10 >= 16 )
V_3 = L_25 ;
else
V_3 = L_26 ;
} else
V_3 = L_17 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_27 ) ;
break;
case 1 :
strcpy ( V_5 , L_28 ) ;
break;
case 3 :
strcpy ( V_5 , L_29 ) ;
break;
default:
strcpy ( V_5 , L_30 ) ;
break;
}
break;
case 1 :
if ( ( V_1 & 0x10 ) || V_9 . V_29 . V_30 )
V_3 = L_20 ;
else
V_3 = L_31 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_32 ) ;
break;
case 2 :
strcpy ( V_5 , L_33 ) ;
break;
default:
strcpy ( V_5 , L_30 ) ;
break;
}
break;
case 2 :
V_3 = L_20 ;
if ( V_9 . V_31 . V_32 )
V_4 = L_34 ;
switch ( V_1 & 0xf ) {
case 0 :
strcpy ( V_5 , L_32 ) ;
break;
case 2 :
strcpy ( V_5 , L_33 ) ;
break;
default:
strcpy ( V_5 , L_30 ) ;
break;
}
break;
case 3 :
V_3 = L_9 ;
if ( ( V_10 == 4 ) && V_9 . V_33 . V_34 && ! strncmp ( V_7 , L_1 , 2 ) )
V_4 = L_35 ;
if ( ( V_1 & 0xFF ) < 0x8 ) {
switch ( V_1 & 0x3 ) {
case 0 :
strcpy ( V_5 , L_32 ) ;
break;
case 1 :
strcpy ( V_5 , L_33 ) ;
break;
case 3 :
strcpy ( V_5 , L_36 ) ;
break;
default:
strcpy ( V_5 , L_27 ) ;
break;
}
}
break;
case 4 :
if ( V_12 . V_35 . V_36 ) {
if ( V_9 . V_35 . V_34 )
V_3 = L_10 ;
else
V_3 = L_37 ;
if ( V_12 . V_35 . V_26 )
V_7 = L_38 ;
else
V_7 = L_39 ;
} else {
if ( V_12 . V_35 . V_26 )
V_7 = L_1 ;
else {
V_7 = L_4 ;
if ( V_14 . V_23 . V_25 )
V_7 = L_2 ;
if ( V_14 . V_23 . V_37 )
V_7 = L_40 ;
}
if ( V_9 . V_35 . V_34 )
V_3 = L_41 ;
else
V_3 = L_42 ;
}
break;
case 6 :
V_3 = L_12 ;
break;
case 7 :
if ( V_9 . V_38 . V_39 )
V_3 = L_43 ;
else
V_3 = L_11 ;
break;
case 0x93 :
V_3 = L_44 ;
if ( V_12 . V_40 . V_26 && V_12 . V_40 . V_41 )
V_7 = L_45 ;
if ( V_12 . V_40 . V_26 )
V_7 = L_1 ;
else if ( V_12 . V_40 . V_41 )
V_7 = L_46 ;
else if ( V_14 . V_40 . V_25 )
V_7 = L_2 ;
break;
case 0x90 :
V_3 = L_47 ;
if ( V_14 . V_23 . V_42 == 2 )
V_3 = L_48 ;
if ( V_10 == 6 )
V_4 = L_49 ;
if ( V_12 . V_43 . V_26 )
V_7 = L_1 ;
else if ( V_12 . V_43 . V_41 )
V_7 = L_46 ;
else if ( V_14 . V_43 . V_25 )
V_7 = L_2 ;
else
V_7 = L_50 ;
break;
case 0x92 :
V_3 = L_51 ;
if ( V_10 == 6 )
V_4 = L_49 ;
if ( V_12 . V_44 . V_26 && V_12 . V_44 . V_41 )
V_7 = L_45 ;
if ( V_12 . V_44 . V_26 )
V_7 = L_1 ;
else if ( V_12 . V_44 . V_41 )
V_7 = L_46 ;
else if ( V_14 . V_44 . V_25 )
V_7 = L_2 ;
else
V_7 = L_50 ;
break;
case 0x91 :
V_3 = L_52 ;
if ( V_12 . V_45 . V_26 && V_14 . V_45 . V_25 )
V_7 = L_1 ;
else if ( V_12 . V_45 . V_41 )
V_7 = L_46 ;
else if ( V_14 . V_45 . V_25 )
V_7 = L_2 ;
else if ( V_12 . V_45 . V_26 )
V_7 = L_38 ;
else
V_7 = L_50 ;
break;
default:
V_3 = L_24 ;
V_4 = L_24 ;
strcpy ( V_5 , L_30 ) ;
V_7 = L_53 ;
break;
}
V_6 = F_6 () / 1000000 ;
if ( V_3 [ 0 ] != '3' ) {
int V_46 = 384 / 8 ;
if ( V_3 [ 0 ] == '6' )
V_46 = 832 / 8 ;
V_16 |= F_7 ( V_46 + 3 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_7 ( V_46 + 2 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_7 ( V_46 + 1 ) ;
V_16 = V_16 << 8 ;
V_16 |= F_7 ( V_46 ) ;
if ( V_16 & 0x7ffff ) {
int V_47 = V_16 & 0x3fff ;
int V_7 = ( V_16 >> 14 ) & 0x1f ;
if ( V_7 && V_47 ) {
sprintf ( V_15 , L_54 , V_47 , 'A' + V_7 - 1 ) ;
V_4 = L_55 ;
V_3 = V_15 ;
} else if ( V_7 && ! V_47 ) {
sprintf ( V_15 , L_56 , V_4 , 'A' + V_7 - 1 ) ;
V_4 = V_15 ;
} else {
sprintf ( V_15 , L_57 , V_47 ) ;
V_4 = L_55 ;
V_3 = V_15 ;
}
}
}
sprintf ( V_2 , L_58 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
return V_2 ;
}
