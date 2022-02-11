static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 ;
unsigned int V_9 ;
T_1 V_10 , V_11 , V_12 [ 2 ] ;
static const T_1 V_13 [] = { 48 , 32 , 24 , 16 , 12 , 8 , 6 , 4 , 2 } ;
unsigned long V_14 ;
F_2 ( & V_7 -> V_4 , L_1 , V_4 -> V_15 ) ;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec4c , 0x68 ) ;
if ( V_8 )
goto V_17;
F_4 ( 10000 , 100000 ) ;
V_8 = F_5 ( V_4 -> V_16 , 0x80ec86 , & V_9 ) ;
if ( V_8 )
goto V_17;
switch ( V_9 ) {
case 0 :
V_4 -> V_18 = V_9 ;
V_4 -> V_19 = 2000 ;
V_4 -> V_20 = 3 ;
V_10 = 16 ;
break;
case 1 :
V_4 -> V_18 = V_9 ;
V_4 -> V_19 = 640 ;
V_4 -> V_20 = 1 ;
V_10 = 6 ;
break;
default:
F_6 ( & V_7 -> V_4 , L_2 , V_9 ) ;
goto V_17;
}
V_8 = F_5 ( V_4 -> V_16 , 0x80ed03 , & V_9 ) ;
if ( V_8 )
goto V_17;
else if ( V_9 < F_7 ( V_13 ) )
V_11 = V_13 [ V_9 ] ;
else
V_11 = 2 ;
#define F_8 50
V_14 = V_21 + F_9 ( F_8 ) ;
while ( ! F_10 ( V_21 , V_14 ) ) {
V_8 = F_11 ( V_4 -> V_16 , 0x80ed23 , V_12 , 2 ) ;
if ( V_8 )
goto V_17;
V_9 = ( V_12 [ 1 ] << 8 ) | ( V_12 [ 0 ] << 0 ) ;
if ( V_9 )
break;
}
F_2 ( & V_7 -> V_4 , L_3 ,
F_12 ( V_21 ) -
( F_12 ( V_14 ) - F_8 ) , V_9 ) ;
V_4 -> V_22 = V_4 -> V_19 * V_9 ;
V_4 -> V_22 /= ( V_4 -> V_20 * V_11 ) ;
V_4 -> V_22 *= 1000 ;
F_2 ( & V_7 -> V_4 , L_4 , V_4 -> V_22 ) ;
if ( V_4 -> V_23 == 1 ) {
#define F_8 50
V_14 = V_21 + F_9 ( F_8 ) ;
while ( ! F_10 ( V_21 , V_14 ) ) {
V_8 = F_5 ( V_4 -> V_16 , 0x80ec82 , & V_9 ) ;
if ( V_8 )
goto V_17;
if ( V_9 )
break;
}
F_2 ( & V_7 -> V_4 , L_5 ,
F_12 ( V_21 ) -
( F_12 ( V_14 ) - F_8 ) , V_9 ) ;
} else {
F_13 ( 50 ) ;
}
V_8 = F_3 ( V_4 -> V_16 , 0x80ed81 , V_10 ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec57 , 0x00 ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec58 , 0x00 ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec40 , 0x01 ) ;
if ( V_8 )
goto V_17;
V_4 -> V_24 = true ;
return 0 ;
V_17:
F_2 ( & V_7 -> V_4 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 , V_25 ;
F_2 ( & V_7 -> V_4 , L_1 , V_4 -> V_15 ) ;
V_4 -> V_24 = false ;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec40 , L_7 , 1 ) ;
if ( V_8 )
goto V_17;
if ( V_4 -> V_15 == V_26 )
V_25 = 4 ;
else
V_25 = 15 ;
F_2 ( & V_7 -> V_4 , L_8 , V_4 -> V_15 , V_25 ) ;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec02 ,
L_9 ,
V_25 ) ;
if ( V_8 )
goto V_17;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec12 , L_10 , 4 ) ;
if ( V_8 )
goto V_17;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec17 ,
L_11 , 9 ) ;
if ( V_8 )
goto V_17;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec22 ,
L_12 , 10 ) ;
if ( V_8 )
goto V_17;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec20 , L_7 , 1 ) ;
if ( V_8 )
goto V_17;
V_8 = F_15 ( V_4 -> V_16 , 0x80ec3f , L_13 , 1 ) ;
if ( V_8 )
goto V_17;
return 0 ;
V_17:
F_2 ( & V_7 -> V_4 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_27 * V_28 = & V_2 -> V_29 ;
int V_8 ;
unsigned int V_9 ;
T_2 V_30 , V_31 ;
T_3 V_10 , V_32 ;
T_1 V_33 , V_34 , V_35 , V_36 ;
F_2 ( & V_7 -> V_4 , L_14 ,
V_4 -> V_15 , V_28 -> V_37 , V_28 -> V_38 ) ;
if ( ! V_4 -> V_24 ) {
V_8 = - V_39 ;
goto V_17;
}
if ( V_28 -> V_37 <= 74000000 ) {
V_32 = 48 ;
V_34 = 0 ;
} else if ( V_28 -> V_37 <= 111000000 ) {
V_32 = 32 ;
V_34 = 1 ;
} else if ( V_28 -> V_37 <= 148000000 ) {
V_32 = 24 ;
V_34 = 2 ;
} else if ( V_28 -> V_37 <= 222000000 ) {
V_32 = 16 ;
V_34 = 3 ;
} else if ( V_28 -> V_37 <= 296000000 ) {
V_32 = 12 ;
V_34 = 4 ;
} else if ( V_28 -> V_37 <= 445000000 ) {
V_32 = 8 ;
V_34 = 5 ;
} else if ( V_28 -> V_37 <= V_4 -> V_22 ) {
V_32 = 6 ;
V_34 = 6 ;
} else if ( V_28 -> V_37 <= 950000000 ) {
V_32 = 4 ;
V_34 = 7 ;
} else {
V_32 = 2 ;
V_34 = 0 ;
}
V_8 = F_5 ( V_4 -> V_16 , 0x80ed81 , & V_9 ) ;
if ( V_8 )
goto V_17;
V_10 = V_9 * V_32 ;
if ( V_9 < 0x20 ) {
if ( V_4 -> V_18 == 0 )
V_10 = ( V_10 * 9 ) >> 5 ;
else
V_10 >>= 1 ;
} else {
V_10 = 0x40 - V_10 ;
if ( V_4 -> V_18 == 0 )
V_10 = ~ ( ( V_10 * 9 ) >> 5 ) ;
else
V_10 = ~ ( V_10 >> 1 ) ;
}
V_31 = ( V_28 -> V_37 / 1000 ) * V_32 * V_4 -> V_20 ;
V_30 = V_31 / V_4 -> V_19 ;
V_9 = V_30 * V_4 -> V_19 ;
if ( ( V_31 - V_9 ) >= ( V_4 -> V_19 >> 1 ) )
V_30 ++ ;
V_30 += ( T_2 ) V_34 << 13 ;
V_31 = V_30 + ( T_2 ) V_10 ;
F_2 ( & V_7 -> V_4 , L_15 ,
V_31 , V_30 ) ;
if ( V_28 -> V_37 <= 440000000 ) {
V_35 = 0 ;
V_36 = 0 ;
} else if ( V_28 -> V_37 <= 484000000 ) {
V_35 = 1 ;
V_36 = 1 ;
} else if ( V_28 -> V_37 <= 533000000 ) {
V_35 = 1 ;
V_36 = 2 ;
} else if ( V_28 -> V_37 <= 587000000 ) {
V_35 = 1 ;
V_36 = 3 ;
} else if ( V_28 -> V_37 <= 645000000 ) {
V_35 = 1 ;
V_36 = 4 ;
} else if ( V_28 -> V_37 <= 710000000 ) {
V_35 = 1 ;
V_36 = 5 ;
} else if ( V_28 -> V_37 <= 782000000 ) {
V_35 = 1 ;
V_36 = 6 ;
} else if ( V_28 -> V_37 <= 860000000 ) {
V_35 = 1 ;
V_36 = 7 ;
} else if ( V_28 -> V_37 <= 1492000000 ) {
V_35 = 1 ;
V_36 = 0 ;
} else if ( V_28 -> V_37 <= 1685000000 ) {
V_35 = 1 ;
V_36 = 1 ;
} else {
V_8 = - V_39 ;
goto V_17;
}
V_8 = F_3 ( V_4 -> V_16 , 0x80ee06 , V_36 ) ;
if ( V_8 )
goto V_17;
if ( V_28 -> V_38 <= 5000000 )
V_33 = 0 ;
else if ( V_28 -> V_38 <= 6000000 )
V_33 = 2 ;
else if ( V_28 -> V_38 <= 7000000 )
V_33 = 4 ;
else
V_33 = 6 ;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec56 , V_33 ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec4c , 0xa0 | ( V_35 << 3 ) ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec4d , ( V_31 >> 0 ) & 0xff ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80ec4e , ( V_31 >> 8 ) & 0xff ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80011e , ( V_30 >> 0 ) & 0xff ) ;
if ( V_8 )
goto V_17;
V_8 = F_3 ( V_4 -> V_16 , 0x80011f , ( V_30 >> 8 ) & 0xff ) ;
if ( V_8 )
goto V_17;
return 0 ;
V_17:
F_2 ( & V_7 -> V_4 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = V_7 -> V_4 . V_42 ;
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_3 * V_4 ;
const struct V_43 * V_44 = F_18 ( V_7 ) ;
int V_8 ;
char * V_45 ;
V_4 = F_19 ( sizeof( struct V_3 ) , V_46 ) ;
if ( V_4 == NULL ) {
V_8 = - V_47 ;
F_6 ( & V_7 -> V_4 , L_16 ) ;
goto V_17;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_16 = V_41 -> V_16 ;
V_4 -> V_2 = V_41 -> V_2 ;
V_4 -> V_23 = V_44 -> V_48 ;
V_4 -> V_15 = V_41 -> V_15 ;
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_49 . V_50 , & V_51 ,
sizeof( struct V_52 ) ) ;
F_20 ( V_7 , V_4 ) ;
if ( V_4 -> V_23 == 1 )
V_45 = L_17 ;
else if ( V_4 -> V_23 == 2 )
V_45 = L_18 ;
else
V_45 = L_19 ;
F_21 ( & V_7 -> V_4 , L_20 ,
V_45 ) ;
F_2 ( & V_7 -> V_4 , L_21 , V_4 -> V_23 , V_4 -> V_15 ) ;
return 0 ;
V_17:
F_2 ( & V_7 -> V_4 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_23 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_2 ( & V_7 -> V_4 , L_22 ) ;
memset ( & V_2 -> V_49 . V_50 , 0 , sizeof( struct V_52 ) ) ;
V_2 -> V_5 = NULL ;
F_24 ( V_4 ) ;
return 0 ;
}
