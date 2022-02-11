static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
unsigned int V_7 ;
T_1 V_8 , V_9 , V_10 [ 2 ] ;
static const T_1 V_11 [] = { 48 , 32 , 24 , 16 , 12 , 8 , 6 , 4 , 2 } ;
unsigned long V_12 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_1 , V_4 -> V_14 ) ;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec4c , 0x68 ) ;
if ( V_6 )
goto V_16;
F_4 ( 10000 , 100000 ) ;
V_6 = F_5 ( V_4 -> V_15 , 0x80ec86 , & V_7 ) ;
if ( V_6 )
goto V_16;
switch ( V_7 ) {
case 0 :
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = 2000 ;
V_4 -> V_19 = 3 ;
V_8 = 16 ;
break;
case 1 :
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = 640 ;
V_4 -> V_19 = 1 ;
V_8 = 6 ;
break;
default:
F_6 ( & V_4 -> V_13 -> V_4 , L_2 , V_7 ) ;
goto V_16;
}
V_6 = F_5 ( V_4 -> V_15 , 0x80ed03 , & V_7 ) ;
if ( V_6 )
goto V_16;
else if ( V_7 < F_7 ( V_11 ) )
V_9 = V_11 [ V_7 ] ;
else
V_9 = 2 ;
#define F_8 50
V_12 = V_20 + F_9 ( F_8 ) ;
while ( ! F_10 ( V_20 , V_12 ) ) {
V_6 = F_11 ( V_4 -> V_15 , 0x80ed23 , V_10 , 2 ) ;
if ( V_6 )
goto V_16;
V_7 = ( V_10 [ 1 ] << 8 ) | ( V_10 [ 0 ] << 0 ) ;
if ( V_7 )
break;
}
F_2 ( & V_4 -> V_13 -> V_4 , L_3 ,
F_12 ( V_20 ) -
( F_12 ( V_12 ) - F_8 ) , V_7 ) ;
V_4 -> V_21 = V_4 -> V_18 * V_7 ;
V_4 -> V_21 /= ( V_4 -> V_19 * V_9 ) ;
V_4 -> V_21 *= 1000 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_4 , V_4 -> V_21 ) ;
if ( V_4 -> V_22 == 1 ) {
#define F_8 50
V_12 = V_20 + F_9 ( F_8 ) ;
while ( ! F_10 ( V_20 , V_12 ) ) {
V_6 = F_5 ( V_4 -> V_15 , 0x80ec82 , & V_7 ) ;
if ( V_6 )
goto V_16;
if ( V_7 )
break;
}
F_2 ( & V_4 -> V_13 -> V_4 , L_5 ,
F_12 ( V_20 ) -
( F_12 ( V_12 ) - F_8 ) , V_7 ) ;
} else {
F_13 ( 50 ) ;
}
V_6 = F_3 ( V_4 -> V_15 , 0x80ed81 , V_8 ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec57 , 0x00 ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec58 , 0x00 ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec40 , 0x01 ) ;
if ( V_6 )
goto V_16;
V_4 -> V_23 = true ;
return 0 ;
V_16:
F_2 ( & V_4 -> V_13 -> V_4 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_24 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_1 , V_4 -> V_14 ) ;
V_4 -> V_23 = false ;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec40 , L_7 , 1 ) ;
if ( V_6 )
goto V_16;
if ( V_4 -> V_14 == V_25 )
V_24 = 4 ;
else
V_24 = 15 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_8 , V_4 -> V_14 , V_24 ) ;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec02 ,
L_9 ,
V_24 ) ;
if ( V_6 )
goto V_16;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec12 , L_10 , 4 ) ;
if ( V_6 )
goto V_16;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec17 ,
L_11 , 9 ) ;
if ( V_6 )
goto V_16;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec22 ,
L_12 , 10 ) ;
if ( V_6 )
goto V_16;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec20 , L_7 , 1 ) ;
if ( V_6 )
goto V_16;
V_6 = F_15 ( V_4 -> V_15 , 0x80ec3f , L_13 , 1 ) ;
if ( V_6 )
goto V_16;
return 0 ;
V_16:
F_2 ( & V_4 -> V_13 -> V_4 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 = & V_2 -> V_28 ;
int V_6 ;
unsigned int V_7 ;
T_2 V_29 , V_30 ;
T_3 V_8 , V_31 ;
T_1 V_32 , V_33 , V_34 , V_35 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_14 ,
V_4 -> V_14 , V_27 -> V_36 , V_27 -> V_37 ) ;
if ( ! V_4 -> V_23 ) {
V_6 = - V_38 ;
goto V_16;
}
if ( V_27 -> V_36 <= 74000000 ) {
V_31 = 48 ;
V_33 = 0 ;
} else if ( V_27 -> V_36 <= 111000000 ) {
V_31 = 32 ;
V_33 = 1 ;
} else if ( V_27 -> V_36 <= 148000000 ) {
V_31 = 24 ;
V_33 = 2 ;
} else if ( V_27 -> V_36 <= 222000000 ) {
V_31 = 16 ;
V_33 = 3 ;
} else if ( V_27 -> V_36 <= 296000000 ) {
V_31 = 12 ;
V_33 = 4 ;
} else if ( V_27 -> V_36 <= 445000000 ) {
V_31 = 8 ;
V_33 = 5 ;
} else if ( V_27 -> V_36 <= V_4 -> V_21 ) {
V_31 = 6 ;
V_33 = 6 ;
} else if ( V_27 -> V_36 <= 950000000 ) {
V_31 = 4 ;
V_33 = 7 ;
} else {
V_31 = 2 ;
V_33 = 0 ;
}
V_6 = F_5 ( V_4 -> V_15 , 0x80ed81 , & V_7 ) ;
if ( V_6 )
goto V_16;
V_8 = V_7 * V_31 ;
if ( V_7 < 0x20 ) {
if ( V_4 -> V_17 == 0 )
V_8 = ( V_8 * 9 ) >> 5 ;
else
V_8 >>= 1 ;
} else {
V_8 = 0x40 - V_8 ;
if ( V_4 -> V_17 == 0 )
V_8 = ~ ( ( V_8 * 9 ) >> 5 ) ;
else
V_8 = ~ ( V_8 >> 1 ) ;
}
V_30 = ( V_27 -> V_36 / 1000 ) * V_31 * V_4 -> V_19 ;
V_29 = V_30 / V_4 -> V_18 ;
V_7 = V_29 * V_4 -> V_18 ;
if ( ( V_30 - V_7 ) >= ( V_4 -> V_18 >> 1 ) )
V_29 ++ ;
V_29 += ( T_2 ) V_33 << 13 ;
V_30 = V_29 + ( T_2 ) V_8 ;
F_2 ( & V_4 -> V_13 -> V_4 , L_15 ,
V_30 , V_29 ) ;
if ( V_27 -> V_36 <= 440000000 ) {
V_34 = 0 ;
V_35 = 0 ;
} else if ( V_27 -> V_36 <= 484000000 ) {
V_34 = 1 ;
V_35 = 1 ;
} else if ( V_27 -> V_36 <= 533000000 ) {
V_34 = 1 ;
V_35 = 2 ;
} else if ( V_27 -> V_36 <= 587000000 ) {
V_34 = 1 ;
V_35 = 3 ;
} else if ( V_27 -> V_36 <= 645000000 ) {
V_34 = 1 ;
V_35 = 4 ;
} else if ( V_27 -> V_36 <= 710000000 ) {
V_34 = 1 ;
V_35 = 5 ;
} else if ( V_27 -> V_36 <= 782000000 ) {
V_34 = 1 ;
V_35 = 6 ;
} else if ( V_27 -> V_36 <= 860000000 ) {
V_34 = 1 ;
V_35 = 7 ;
} else if ( V_27 -> V_36 <= 1492000000 ) {
V_34 = 1 ;
V_35 = 0 ;
} else if ( V_27 -> V_36 <= 1685000000 ) {
V_34 = 1 ;
V_35 = 1 ;
} else {
V_6 = - V_38 ;
goto V_16;
}
V_6 = F_3 ( V_4 -> V_15 , 0x80ee06 , V_35 ) ;
if ( V_6 )
goto V_16;
if ( V_27 -> V_37 <= 5000000 )
V_32 = 0 ;
else if ( V_27 -> V_37 <= 6000000 )
V_32 = 2 ;
else if ( V_27 -> V_37 <= 7000000 )
V_32 = 4 ;
else
V_32 = 6 ;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec56 , V_32 ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec4c , 0xa0 | ( V_34 << 3 ) ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec4d , ( V_30 >> 0 ) & 0xff ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80ec4e , ( V_30 >> 8 ) & 0xff ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80011e , ( V_29 >> 0 ) & 0xff ) ;
if ( V_6 )
goto V_16;
V_6 = F_3 ( V_4 -> V_15 , 0x80011f , ( V_29 >> 8 ) & 0xff ) ;
if ( V_6 )
goto V_16;
return 0 ;
V_16:
F_2 ( & V_4 -> V_13 -> V_4 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_39 * V_13 ,
const struct V_40 * V_41 )
{
struct V_42 * V_43 = V_13 -> V_4 . V_44 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_3 * V_4 ;
int V_6 ;
char * V_45 ;
static const struct V_46 V_46 = {
. V_47 = 24 ,
. V_48 = 8 ,
} ;
V_4 = F_18 ( sizeof( struct V_3 ) , V_49 ) ;
if ( V_4 == NULL ) {
V_6 = - V_50 ;
F_6 ( & V_13 -> V_4 , L_16 ) ;
goto V_16;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_2 = V_43 -> V_2 ;
V_4 -> V_22 = V_43 -> V_22 ;
V_4 -> V_14 = V_43 -> V_14 ;
V_4 -> V_15 = F_19 ( V_13 , & V_46 ) ;
if ( F_20 ( V_4 -> V_15 ) ) {
V_6 = F_21 ( V_4 -> V_15 ) ;
goto V_51;
}
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_52 . V_53 , & V_54 ,
sizeof( struct V_55 ) ) ;
F_22 ( V_13 , V_4 ) ;
if ( V_4 -> V_22 == 1 )
V_45 = L_17 ;
else if ( V_4 -> V_22 == 2 )
V_45 = L_18 ;
else
V_45 = L_19 ;
F_23 ( & V_4 -> V_13 -> V_4 , L_20 ,
V_45 ) ;
F_2 ( & V_4 -> V_13 -> V_4 , L_21 ,
V_4 -> V_22 , V_4 -> V_14 ) ;
return 0 ;
V_51:
F_24 ( V_4 ) ;
V_16:
F_2 ( & V_13 -> V_4 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_39 * V_13 )
{
struct V_3 * V_4 = F_26 ( V_13 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_2 ( & V_13 -> V_4 , L_22 ) ;
memset ( & V_2 -> V_52 . V_53 , 0 , sizeof( struct V_55 ) ) ;
V_2 -> V_5 = NULL ;
F_27 ( V_4 -> V_15 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
