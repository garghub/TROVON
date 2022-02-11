static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 , T_2 V_5 )
{
int V_6 ;
T_2 V_7 [ 3 ] ;
struct V_8 V_9 [ 2 ] = {
{ . V_10 = V_2 -> V_11 , . V_12 = 0 ,
. V_13 = V_7 , . V_14 = sizeof( V_7 ) } ,
{ . V_10 = V_2 -> V_11 , . V_12 = V_15 ,
. V_13 = V_4 , . V_14 = V_5 }
} ;
V_7 [ 0 ] = ( T_2 ) ( V_3 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( T_2 ) ( V_3 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( T_2 ) V_3 & 0xff ;
V_7 [ 0 ] |= 0x80 ;
V_6 = F_2 ( V_2 -> V_16 , V_9 , 2 ) ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_6 ;
T_2 V_7 [ 1 ] ;
V_6 = F_1 ( V_2 , V_3 , & V_7 [ 0 ] , sizeof( V_7 ) ) ;
return ( V_6 < 0 ) ? - V_17 : V_7 [ 0 ] ;
}
static int F_4 ( struct V_1 * V_2 ,
T_2 V_18 , T_1 V_3 , T_2 V_13 [] , T_2 V_5 )
{
T_2 V_7 [ 256 ] ;
struct V_8 V_9 [ 1 ] = {
{ . V_10 = V_2 -> V_11 , . V_12 = 0 ,
. V_13 = V_7 , . V_14 = 3 + V_5 }
} ;
int V_6 ;
V_7 [ 0 ] = ( T_2 ) ( V_3 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( T_2 ) ( V_3 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( T_2 ) V_3 & 0xff ;
memcpy ( & V_7 [ 3 ] , V_13 , V_5 ) ;
if ( V_18 == V_19 )
V_7 [ 0 ] |= 0x80 ;
V_6 = F_2 ( V_2 -> V_16 , V_9 , 1 ) ;
if ( V_6 < 0 )
return - V_20 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_18 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
T_2 V_7 [ 4 ] ;
T_2 V_21 ;
V_7 [ 0 ] = V_4 >> 24 ;
V_7 [ 1 ] = ( V_4 >> 16 ) & 0xff ;
V_7 [ 2 ] = ( V_4 >> 8 ) & 0xff ;
V_7 [ 3 ] = V_4 & 0xff ;
if ( V_4 < 0x100 )
V_21 = 3 ;
else if ( V_4 < 0x1000 )
V_21 = 2 ;
else if ( V_4 < 0x100000 )
V_21 = 1 ;
else
V_21 = 0 ;
V_6 = F_4 ( V_2 , V_18 , V_3 , & V_7 [ V_21 ] , sizeof( V_7 ) - V_21 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
int V_6 , V_24 ;
if ( V_23 == NULL )
return - V_25 ;
for ( V_24 = 0 ; V_24 < 1000 ; ++ V_24 ) {
if ( V_23 [ V_24 ] . V_18 == 0xff )
break;
V_6 = F_4 ( V_2 , V_23 [ V_24 ] . V_18 ,
V_23 [ V_24 ] . V_26 ,
V_23 [ V_24 ] . V_3 , V_23 [ V_24 ] . V_5 ) ;
if ( V_6 < 0 )
return - V_17 ;
}
return 0 ;
}
static int F_7 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 , V_24 , V_3 ;
T_2 V_30 , V_31 ;
T_2 V_32 [] = { 48 , 32 , 24 , 16 , 12 , 8 , 6 , 4 , 2 } ;
T_2 V_7 [ 2 ] ;
V_3 = F_3 ( V_2 , 0xec86 ) ;
switch ( V_3 ) {
case 0 :
V_2 -> V_33 = V_3 ;
V_2 -> V_34 = 2000 ;
V_2 -> V_35 = 3 ;
V_30 = 16 ;
break;
case - V_17 :
return - V_17 ;
case 1 :
default:
V_2 -> V_33 = V_3 ;
V_2 -> V_34 = 640 ;
V_2 -> V_35 = 1 ;
V_30 = 6 ;
break;
}
V_3 = F_3 ( V_2 , 0xed03 ) ;
if ( V_3 < 0 )
return - V_17 ;
else if ( V_3 < F_8 ( V_32 ) )
V_31 = V_32 [ V_3 ] ;
else
V_31 = 2 ;
for ( V_24 = 0 ; V_24 < 50 ; V_24 ++ ) {
V_6 = F_1 ( V_2 , 0xed23 , & V_7 [ 0 ] , sizeof( V_7 ) ) ;
V_3 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
if ( V_3 > 0 )
break;
if ( V_6 < 0 )
return - V_17 ;
F_9 ( 2000 ) ;
}
V_2 -> V_36 = V_2 -> V_34 * V_3 ;
V_2 -> V_36 /= ( V_2 -> V_35 * V_31 ) ;
F_10 ( & V_2 -> V_16 -> V_37 , L_1 , V_38 ,
V_2 -> V_36 ) ;
if ( V_2 -> V_39 > 1 )
F_11 ( 50 ) ;
else {
for ( V_24 = 0 ; V_24 < 50 ; V_24 ++ ) {
V_3 = F_3 ( V_2 , 0xec82 ) ;
if ( V_3 > 0 )
break;
if ( V_3 < 0 )
return - V_17 ;
F_9 ( 2000 ) ;
}
}
V_6 = F_5 ( V_2 , V_19 , 0xec40 , 0x1 ) ;
V_6 |= F_5 ( V_2 , V_19 , 0xfba8 , 0x0 ) ;
V_6 |= F_5 ( V_2 , V_19 , 0xec57 , 0x0 ) ;
V_6 |= F_5 ( V_2 , V_19 , 0xec58 , 0x0 ) ;
return F_5 ( V_2 , V_19 , 0xed81 , V_30 ) ;
}
static int F_12 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_22 * V_40 = V_41 ;
struct V_42 * V_43 = & V_28 -> V_44 ;
T_1 V_45 = V_43 -> V_46 ;
T_1 V_47 = V_43 -> V_48 ;
int V_6 , V_3 ;
T_1 V_48 = V_47 / 1000 ;
T_1 V_49 , V_50 , V_51 ;
T_3 V_52 ;
T_3 V_53 ;
T_2 V_54 ;
T_2 V_55 ;
T_2 V_56 ;
T_2 V_57 ;
if ( V_2 -> V_58 == 1 )
V_40 = V_59 ;
else
V_40 = V_41 ;
F_10 ( & V_2 -> V_16 -> V_37 , L_2 ,
V_38 , V_48 , V_45 ) ;
if ( V_48 >= 51000 && V_48 <= 440000 ) {
V_55 = 0 ;
V_56 = 0 ;
} else if ( V_48 > 440000 && V_48 <= 484000 ) {
V_55 = 1 ;
V_56 = 1 ;
} else if ( V_48 > 484000 && V_48 <= 533000 ) {
V_55 = 1 ;
V_56 = 2 ;
} else if ( V_48 > 533000 && V_48 <= 587000 ) {
V_55 = 1 ;
V_56 = 3 ;
} else if ( V_48 > 587000 && V_48 <= 645000 ) {
V_55 = 1 ;
V_56 = 4 ;
} else if ( V_48 > 645000 && V_48 <= 710000 ) {
V_55 = 1 ;
V_56 = 5 ;
} else if ( V_48 > 710000 && V_48 <= 782000 ) {
V_55 = 1 ;
V_56 = 6 ;
} else if ( V_48 > 782000 && V_48 <= 860000 ) {
V_55 = 1 ;
V_56 = 7 ;
} else if ( V_48 > 1450000 && V_48 <= 1492000 ) {
V_55 = 1 ;
V_56 = 0 ;
} else if ( V_48 > 1660000 && V_48 <= 1685000 ) {
V_55 = 1 ;
V_56 = 1 ;
} else
return - V_25 ;
V_40 [ 0 ] . V_3 [ 0 ] = V_56 ;
switch ( V_45 ) {
case 5000000 :
V_57 = 0 ;
break;
case 6000000 :
V_57 = 2 ;
break;
case 7000000 :
V_57 = 4 ;
break;
default:
case 8000000 :
V_57 = 6 ;
break;
}
V_40 [ 1 ] . V_3 [ 0 ] = V_57 ;
V_40 [ 2 ] . V_3 [ 0 ] = 0xa0 | ( V_55 << 3 ) ;
if ( V_48 > 53000 && V_48 <= 74000 ) {
V_53 = 48 ;
V_54 = 0 ;
} else if ( V_48 > 74000 && V_48 <= 111000 ) {
V_53 = 32 ;
V_54 = 1 ;
} else if ( V_48 > 111000 && V_48 <= 148000 ) {
V_53 = 24 ;
V_54 = 2 ;
} else if ( V_48 > 148000 && V_48 <= 222000 ) {
V_53 = 16 ;
V_54 = 3 ;
} else if ( V_48 > 222000 && V_48 <= 296000 ) {
V_53 = 12 ;
V_54 = 4 ;
} else if ( V_48 > 296000 && V_48 <= 445000 ) {
V_53 = 8 ;
V_54 = 5 ;
} else if ( V_48 > 445000 && V_48 <= V_2 -> V_36 ) {
V_53 = 6 ;
V_54 = 6 ;
} else if ( V_48 > V_2 -> V_36 && V_48 <= 950000 ) {
V_53 = 4 ;
V_54 = 7 ;
} else if ( V_48 > 1450000 && V_48 <= 1680000 ) {
V_53 = 2 ;
V_54 = 0 ;
} else
return - V_25 ;
V_3 = F_3 ( V_2 , 0xed81 ) ;
V_52 = ( T_3 ) V_3 * V_53 ;
if ( V_3 < 0x20 ) {
if ( V_2 -> V_33 == 0 )
V_52 = ( V_52 * 9 ) >> 5 ;
else
V_52 >>= 1 ;
} else {
V_52 = 0x40 - V_52 ;
if ( V_2 -> V_33 == 0 )
V_52 = ~ ( ( V_52 * 9 ) >> 5 ) ;
else
V_52 = ~ ( V_52 >> 1 ) ;
}
V_50 = V_48 * ( T_1 ) V_53 * ( T_1 ) V_2 -> V_35 ;
V_49 = V_50 / V_2 -> V_34 ;
V_51 = V_49 * V_2 -> V_34 ;
if ( ( V_50 - V_51 ) >= ( V_2 -> V_34 >> 1 ) )
V_49 ++ ;
V_49 += ( T_1 ) V_54 << 13 ;
V_50 = V_49 + ( T_1 ) V_52 ;
V_40 [ 3 ] . V_3 [ 0 ] = V_50 & 0xff ;
V_40 [ 4 ] . V_3 [ 0 ] = ( V_50 >> 8 ) & 0xff ;
F_10 ( & V_2 -> V_16 -> V_37 , L_3 ,
V_38 , V_50 ) ;
V_40 [ 5 ] . V_3 [ 0 ] = V_49 & 0xff ;
V_40 [ 6 ] . V_3 [ 0 ] = ( V_49 >> 8 ) & 0xff ;
F_10 ( & V_2 -> V_16 -> V_37 , L_4 ,
V_38 , V_49 ) ;
V_6 = F_6 ( V_2 , V_40 ) ;
return ( V_6 < 0 ) ? - V_17 : 0 ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
return F_6 ( V_2 , V_60 ) ;
}
static int F_14 ( struct V_27 * V_28 )
{
F_15 ( V_28 -> V_29 ) ;
return 0 ;
}
struct V_27 * F_16 ( struct V_27 * V_28 ,
struct V_61 * V_16 , T_2 V_11 , T_2 V_62 )
{
struct V_1 * V_2 = NULL ;
int V_6 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_63 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_11 = V_11 ;
switch ( V_62 ) {
case V_64 :
case V_65 :
case V_66 :
V_2 -> V_39 = 0x01 ;
break;
case V_67 :
case V_68 :
case V_69 :
V_2 -> V_39 = 0x02 ;
break;
default:
F_10 ( & V_16 -> V_37 ,
L_5 , V_38 , V_62 ) ;
goto error;
}
V_2 -> V_70 = V_62 ;
V_2 -> V_58 = 1 ;
V_6 = F_5 ( V_2 , V_19 , 0xec4c , 0x68 ) ;
if ( V_6 < 0 )
goto error;
V_28 -> V_29 = V_2 ;
memcpy ( & V_28 -> V_71 . V_72 , & V_73 ,
sizeof( struct V_74 ) ) ;
F_18 ( & V_16 -> V_37 ,
L_6 ,
V_75 ) ;
F_10 ( & V_16 -> V_37 , L_7 ,
V_38 , V_62 , V_2 -> V_39 ) ;
return V_28 ;
error:
F_15 ( V_2 ) ;
return NULL ;
}
