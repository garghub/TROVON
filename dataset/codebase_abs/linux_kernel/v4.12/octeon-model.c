static T_1 T_2 F_1 ( int V_1 )
{
union V_2 V_3 ;
V_3 . V_4 = 0 ;
V_3 . V_5 . V_6 = V_1 ;
V_3 . V_5 . V_7 = 1 ;
F_2 ( V_8 , V_3 . V_4 ) ;
while ( ( V_3 . V_4 = F_3 ( V_8 ) )
&& V_3 . V_5 . V_7 )
;
return V_3 . V_5 . V_9 ;
}
static const char * T_2 F_4 ( T_3 V_10 ,
char * V_11 )
{
const char * V_12 ;
const char * V_13 ;
char V_14 [ 4 ] ;
int V_15 ;
const char * V_16 ;
int V_17 ;
union V_18 V_19 ;
union V_20 V_21 ;
char V_22 [ 10 ] ;
T_3 V_23 = 0 ;
T_4 V_24 = 0 ;
if ( F_5 ( V_25 ) || F_5 ( V_26 ) )
V_24 = ( F_3 ( V_27 ) >> 34 ) & 0x3 ;
V_19 . V_4 = F_3 ( V_28 ) ;
V_21 . V_4 = F_3 ( V_29 ) ;
V_17 = F_6 () ;
switch ( ( V_10 >> 8 ) & 0xff ) {
case 6 :
case 2 :
V_21 . V_5 . V_30 = 1 ;
V_21 . V_5 . V_31 = 1 ;
break;
case 4 :
V_21 . V_5 . V_30 = 1 ;
break;
default:
break;
}
if ( V_21 . V_5 . V_30 ) {
if ( V_19 . V_5 . V_32 )
V_16 = L_1 ;
else
V_16 = L_2 ;
} else if ( V_19 . V_5 . V_32 )
V_16 = L_3 ;
else
V_16 = L_4 ;
if ( ! V_19 . V_5 . V_32 )
V_33 |= V_34 ;
sprintf ( V_14 , L_5 , ( int ) ( ( V_10 >> 3 ) & 7 ) + 1 , ( int ) V_10 & 7 ) ;
switch ( V_17 ) {
case 48 :
V_13 = L_6 ;
break;
case 44 :
V_13 = L_7 ;
break;
case 40 :
V_13 = L_8 ;
break;
case 32 :
V_13 = L_9 ;
break;
case 24 :
V_13 = L_10 ;
break;
case 16 :
V_13 = L_11 ;
break;
case 15 :
V_13 = L_12 ;
break;
case 14 :
V_13 = L_13 ;
break;
case 13 :
V_13 = L_14 ;
break;
case 12 :
V_13 = L_15 ;
break;
case 11 :
V_13 = L_16 ;
break;
case 10 :
V_13 = L_17 ;
break;
case 9 :
V_13 = L_18 ;
break;
case 8 :
V_13 = L_19 ;
break;
case 7 :
V_13 = L_20 ;
break;
case 6 :
V_13 = L_21 ;
break;
case 5 :
V_13 = L_22 ;
break;
case 4 :
V_13 = L_23 ;
break;
case 3 :
V_13 = L_24 ;
break;
case 2 :
V_13 = L_25 ;
break;
case 1 :
V_13 = L_26 ;
break;
default:
V_13 = L_27 ;
break;
}
switch ( ( V_10 >> 8 ) & 0xff ) {
case 0 :
if ( V_24 ) {
if ( V_17 >= 16 )
V_12 = L_28 ;
else
V_12 = L_29 ;
} else
V_12 = L_20 ;
switch ( V_10 & 0xf ) {
case 0 :
strcpy ( V_14 , L_30 ) ;
break;
case 1 :
strcpy ( V_14 , L_31 ) ;
break;
case 3 :
strcpy ( V_14 , L_32 ) ;
break;
default:
strcpy ( V_14 , L_33 ) ;
break;
}
break;
case 1 :
if ( ( V_10 & 0x10 ) || V_24 )
V_12 = L_23 ;
else
V_12 = L_34 ;
switch ( V_10 & 0xf ) {
case 0 :
strcpy ( V_14 , L_35 ) ;
break;
case 2 :
strcpy ( V_14 , L_36 ) ;
break;
default:
strcpy ( V_14 , L_33 ) ;
break;
}
break;
case 2 :
V_12 = L_23 ;
if ( V_24 )
V_13 = L_37 ;
switch ( V_10 & 0xf ) {
case 0 :
strcpy ( V_14 , L_35 ) ;
break;
case 2 :
strcpy ( V_14 , L_36 ) ;
break;
default:
strcpy ( V_14 , L_33 ) ;
break;
}
break;
case 3 :
V_12 = L_12 ;
if ( ( V_17 == 4 ) && V_24 && ! strncmp ( V_16 , L_1 , 2 ) )
V_13 = L_38 ;
if ( ( V_10 & 0xFF ) < 0x8 ) {
switch ( V_10 & 0x3 ) {
case 0 :
strcpy ( V_14 , L_35 ) ;
break;
case 1 :
strcpy ( V_14 , L_36 ) ;
break;
case 3 :
strcpy ( V_14 , L_39 ) ;
break;
default:
strcpy ( V_14 , L_30 ) ;
break;
}
}
break;
case 4 :
if ( V_19 . V_35 . V_36 ) {
if ( V_24 )
V_12 = L_13 ;
else
V_12 = L_40 ;
if ( V_19 . V_35 . V_32 )
V_16 = L_41 ;
else
V_16 = L_42 ;
} else {
if ( V_19 . V_35 . V_32 )
V_16 = L_1 ;
else {
V_16 = L_4 ;
if ( V_21 . V_5 . V_31 )
V_16 = L_2 ;
if ( V_21 . V_35 . V_37 )
V_16 = L_43 ;
}
if ( V_24 )
V_12 = L_44 ;
else
V_12 = L_45 ;
}
break;
case 6 :
V_12 = L_15 ;
break;
case 7 :
if ( V_24 )
V_12 = L_46 ;
else
V_12 = L_14 ;
break;
case 0x93 :
V_12 = L_47 ;
if ( V_19 . V_38 . V_32 && V_19 . V_38 . V_39 )
V_16 = L_48 ;
if ( V_19 . V_38 . V_32 )
V_16 = L_1 ;
else if ( V_19 . V_38 . V_39 )
V_16 = L_49 ;
else if ( V_21 . V_38 . V_31 )
V_16 = L_2 ;
break;
case 0x90 :
V_12 = L_50 ;
if ( V_21 . V_5 . V_40 == 2 )
V_12 = L_51 ;
if ( V_17 == 6 )
V_13 = L_52 ;
if ( V_19 . V_41 . V_32 )
V_16 = L_1 ;
else if ( V_19 . V_41 . V_39 )
V_16 = L_49 ;
else if ( V_21 . V_41 . V_31 )
V_16 = L_2 ;
else
V_16 = L_53 ;
break;
case 0x92 :
V_12 = L_54 ;
if ( V_17 == 6 )
V_13 = L_52 ;
if ( V_19 . V_42 . V_32 && V_19 . V_42 . V_39 )
V_16 = L_48 ;
if ( V_19 . V_42 . V_32 )
V_16 = L_1 ;
else if ( V_19 . V_42 . V_39 )
V_16 = L_49 ;
else if ( V_21 . V_42 . V_31 )
V_16 = L_2 ;
else
V_16 = L_53 ;
break;
case 0x91 :
V_12 = L_55 ;
if ( V_19 . V_43 . V_32 && V_21 . V_43 . V_31 )
V_16 = L_1 ;
else if ( V_19 . V_43 . V_39 )
V_16 = L_49 ;
else if ( V_21 . V_43 . V_31 )
V_16 = L_2 ;
else if ( V_19 . V_43 . V_32 )
V_16 = L_41 ;
else
V_16 = L_53 ;
break;
case 0x94 :
V_12 = L_56 ;
if ( V_21 . V_44 . V_31 )
V_16 = L_2 ;
else
V_16 = L_53 ;
break;
case 0x95 :
if ( V_17 == 6 )
V_13 = L_52 ;
if ( F_5 ( V_45 ) )
V_12 = L_57 ;
else
V_12 = L_58 ;
if ( V_21 . V_46 . V_40 == 2 )
V_12 = L_59 ;
if ( V_21 . V_46 . V_31
&& V_21 . V_46 . V_30
&& V_21 . V_46 . V_47 ) {
if ( V_21 . V_46 . V_31 &&
! V_19 . V_46 . V_36 &&
V_21 . V_46 . V_47 ) {
V_16 = L_1 ;
} else {
V_16 = L_2 ;
}
} else if ( V_19 . V_46 . V_36 == 0 )
V_16 = L_60 ;
else
V_16 = L_53 ;
break;
case 0x96 :
V_12 = L_10 ;
if ( F_3 ( V_48 ) & ( 0x1ULL << 32 ) )
V_12 = L_61 ;
if ( V_19 . V_49 . V_32 )
V_16 = L_1 ;
else if ( V_21 . V_49 . V_30 )
V_16 = L_2 ;
else
V_16 = L_53 ;
break;
case 0x97 :
if ( V_17 == 6 )
V_13 = L_52 ;
V_12 = L_62 ;
if ( V_21 . V_50 . V_40 == 2 )
V_12 = L_63 ;
if ( V_21 . V_50 . V_31
&& V_21 . V_50 . V_30
&& V_21 . V_50 . V_47 ) {
if ( ! V_19 . V_50 . V_36 )
V_16 = L_1 ;
else
V_16 = L_2 ;
} else
V_16 = L_53 ;
break;
case 0x98 :
V_12 = L_64 ;
if ( V_21 . V_46 . V_31
&& V_21 . V_46 . V_30
&& V_21 . V_46 . V_47 )
V_16 = L_2 ;
else
V_16 = L_53 ;
break;
default:
V_12 = L_27 ;
V_13 = L_27 ;
strcpy ( V_14 , L_33 ) ;
V_16 = L_65 ;
break;
}
V_15 = F_7 () / 1000000 ;
if ( V_12 [ 0 ] != '3' ) {
int V_51 = 384 / 8 ;
if ( V_12 [ 0 ] == '6' )
V_51 = 832 / 8 ;
V_23 |= F_1 ( V_51 + 3 ) ;
V_23 = V_23 << 8 ;
V_23 |= F_1 ( V_51 + 2 ) ;
V_23 = V_23 << 8 ;
V_23 |= F_1 ( V_51 + 1 ) ;
V_23 = V_23 << 8 ;
V_23 |= F_1 ( V_51 ) ;
if ( V_23 & 0x7ffff ) {
int V_52 = V_23 & 0x3fff ;
int V_16 = ( V_23 >> 14 ) & 0x1f ;
if ( V_16 && V_52 ) {
sprintf ( V_22 , L_66 , V_52 , 'A' + V_16 - 1 ) ;
V_13 = L_67 ;
V_12 = V_22 ;
} else if ( V_16 && ! V_52 ) {
sprintf ( V_22 , L_68 , V_13 , 'A' + V_16 - 1 ) ;
V_13 = V_22 ;
} else {
sprintf ( V_22 , L_69 , V_52 ) ;
V_13 = L_67 ;
V_12 = V_22 ;
}
}
}
sprintf ( V_11 , L_70 , V_12 , V_13 , V_14 , V_15 , V_16 ) ;
return V_11 ;
}
const char * T_2 F_8 ( T_3 V_10 )
{
static char V_11 [ 32 ] ;
return F_4 ( V_10 , V_11 ) ;
}
