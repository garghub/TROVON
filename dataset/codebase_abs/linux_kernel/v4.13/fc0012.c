static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2
} ;
if ( F_2 ( V_2 -> V_13 , & V_7 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_1 ,
V_15 , V_3 , V_4 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_6 V_7 [ 2 ] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 ,
. V_5 = & V_3 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_17 ,
. V_5 = V_4 , . V_12 = 1 } ,
} ;
if ( F_2 ( V_2 -> V_13 , V_7 , 2 ) != 2 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_2 ,
V_15 , V_3 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_5 ( struct V_18 * V_19 )
{
F_6 ( V_19 -> V_20 ) ;
V_19 -> V_20 = NULL ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_21 , V_22 = 0 ;
unsigned char V_3 [] = {
0x00 ,
0x05 ,
0x10 ,
0x00 ,
0x00 ,
0x0f ,
0x00 ,
0x00 ,
0xff ,
0x6e ,
0xb8 ,
0x82 ,
0xfc ,
0x02 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x1f ,
0x08 ,
0x00 ,
0x04 ,
} ;
switch ( V_2 -> V_9 -> V_23 ) {
case V_24 :
case V_25 :
V_3 [ 0x07 ] |= 0x20 ;
break;
case V_26 :
default:
break;
}
if ( V_2 -> V_9 -> V_27 )
V_3 [ 0x0c ] |= 0x02 ;
if ( V_2 -> V_9 -> V_28 )
V_3 [ 0x09 ] |= 0x01 ;
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 1 ) ;
for ( V_21 = 1 ; V_21 < sizeof( V_3 ) ; V_21 ++ ) {
V_22 = F_1 ( V_2 , V_21 , V_3 [ V_21 ] ) ;
if ( V_22 )
break;
}
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 0 ) ;
if ( V_22 )
F_3 ( & V_2 -> V_13 -> V_14 , L_3 ,
V_15 , V_22 ) ;
return V_22 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_21 , V_22 = 0 ;
struct V_31 * V_32 = & V_19 -> V_33 ;
T_2 V_34 = V_32 -> V_35 / 1000 ;
T_2 V_36 = V_32 -> V_37 ;
unsigned char V_3 [ 7 ] , V_38 , V_39 , V_40 , V_41 ;
unsigned long V_42 ;
unsigned short V_43 , V_44 , V_45 ;
bool V_46 = false ;
if ( V_19 -> V_47 ) {
V_22 = V_19 -> V_47 ( V_2 -> V_13 , V_48 ,
V_49 , ( V_34 > 300000 ? 0 : 1 ) ) ;
if ( V_22 )
goto exit;
}
switch ( V_2 -> V_9 -> V_23 ) {
case V_24 :
V_43 = 27000 / 2 ;
break;
case V_26 :
V_43 = 36000 / 2 ;
break;
case V_25 :
default:
V_43 = 28800 / 2 ;
break;
}
if ( V_34 < 37084 ) {
V_40 = 96 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_34 < 55625 ) {
V_40 = 64 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_34 < 74167 ) {
V_40 = 48 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_34 < 111250 ) {
V_40 = 32 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_34 < 148334 ) {
V_40 = 24 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_34 < 222500 ) {
V_40 = 16 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_34 < 296667 ) {
V_40 = 12 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_34 < 445000 ) {
V_40 = 8 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_34 < 593334 ) {
V_40 = 6 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x00 ;
} else {
V_40 = 4 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x02 ;
}
V_42 = V_34 * V_40 ;
if ( V_42 >= 3060000 ) {
V_3 [ 6 ] |= 0x08 ;
V_46 = true ;
}
if ( V_34 >= 45000 ) {
V_45 = ( unsigned short ) ( V_42 / V_43 ) ;
if ( ( V_42 - V_45 * V_43 ) >= ( V_43 / 2 ) )
V_45 ++ ;
V_39 = ( unsigned char ) ( V_45 / 8 ) ;
V_38 = ( unsigned char ) ( V_45 - ( 8 * V_39 ) ) ;
if ( V_38 < 2 ) {
V_3 [ 1 ] = V_38 + 8 ;
V_3 [ 2 ] = V_39 - 1 ;
} else {
V_3 [ 1 ] = V_38 ;
V_3 [ 2 ] = V_39 ;
}
} else {
V_3 [ 1 ] = 0x06 ;
V_3 [ 2 ] = 0x11 ;
}
V_3 [ 6 ] |= 0x20 ;
V_44 = ( unsigned short ) ( V_42 - ( V_42 / V_43 ) * V_43 ) ;
V_44 = ( V_44 << 15 ) / V_43 ;
if ( V_44 >= 16384 )
V_44 += 32768 ;
V_3 [ 3 ] = V_44 >> 8 ;
V_3 [ 4 ] = V_44 & 0xff ;
if ( V_36 == V_50 ) {
V_3 [ 6 ] &= 0x3f ;
switch ( V_32 -> V_51 ) {
case 6000000 :
V_3 [ 6 ] |= 0x80 ;
break;
case 7000000 :
V_3 [ 6 ] |= 0x40 ;
break;
case 8000000 :
default:
break;
}
} else {
F_3 ( & V_2 -> V_13 -> V_14 , L_4 ,
V_15 ) ;
return - V_52 ;
}
V_3 [ 5 ] |= 0x07 ;
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 1 ) ;
for ( V_21 = 1 ; V_21 <= 6 ; V_21 ++ ) {
V_22 = F_1 ( V_2 , V_21 , V_3 [ V_21 ] ) ;
if ( V_22 )
goto exit;
}
V_22 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_22 ) {
F_9 ( 10 ) ;
V_22 = F_4 ( V_2 , 0x0e , & V_41 ) ;
}
if ( V_22 )
goto exit;
V_41 &= 0x3f ;
if ( V_46 ) {
if ( V_41 > 0x3c ) {
V_3 [ 6 ] &= ~ 0x08 ;
V_22 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
} else {
if ( V_41 < 0x02 ) {
V_3 [ 6 ] |= 0x08 ;
V_22 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_22 )
V_22 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
}
V_2 -> V_35 = V_32 -> V_35 ;
V_2 -> V_53 = V_32 -> V_51 ;
exit:
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 0 ) ;
if ( V_22 )
F_10 ( & V_2 -> V_13 -> V_14 , L_5 ,
V_15 , V_54 , V_22 ) ;
return V_22 ;
}
static int F_11 ( struct V_18 * V_19 , T_2 * V_35 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
* V_35 = V_2 -> V_35 ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 , T_2 * V_35 )
{
* V_35 = 0 ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 , T_2 * V_53 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
* V_53 = V_2 -> V_53 ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 , T_3 * V_55 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_22 ;
unsigned char V_41 ;
int V_56 , V_57 , V_58 , V_59 , V_60 ;
const int V_61 [] = {
- 63 , - 58 , - 99 , - 73 ,
- 63 , - 65 , - 54 , - 60 ,
71 , 70 , 68 , 67 ,
65 , 63 , 61 , 58 ,
197 , 191 , 188 , 186 ,
184 , 182 , 181 , 179 ,
} ;
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 1 ) ;
V_22 = F_1 ( V_2 , 0x12 , 0x00 ) ;
if ( V_22 )
goto V_62;
V_22 = F_4 ( V_2 , 0x12 , & V_41 ) ;
if ( V_22 )
goto V_62;
V_56 = V_41 ;
V_22 = F_4 ( V_2 , 0x13 , & V_41 ) ;
if ( V_22 )
goto V_62;
V_57 = V_41 & 0x1f ;
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 0 ) ;
if ( V_57 < F_15 ( V_61 ) ) {
V_58 = V_61 [ V_57 ] ;
V_59 = ( abs ( ( V_56 >> 5 ) - 7 ) - 2 +
( V_56 & 0x1f ) ) * 2 ;
V_60 = V_63 - V_59 - V_58 / 10 ;
if ( V_60 >= 45 )
* V_55 = 255 ;
else if ( V_60 < - 95 )
* V_55 = 0 ;
else
* V_55 = ( V_60 + 95 ) * 255 / 140 ;
* V_55 |= * V_55 << 8 ;
} else {
V_22 = - 1 ;
}
goto exit;
V_62:
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 0 ) ;
exit:
if ( V_22 )
F_10 ( & V_2 -> V_13 -> V_14 , L_5 ,
V_15 , V_54 , V_22 ) ;
return V_22 ;
}
struct V_18 * F_16 ( struct V_18 * V_19 ,
struct V_64 * V_13 , const struct V_65 * V_9 )
{
struct V_1 * V_2 ;
int V_22 ;
T_1 V_66 ;
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 1 ) ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 ) {
V_22 = - V_68 ;
F_3 ( & V_13 -> V_14 , L_6 , V_15 ) ;
goto V_62;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_13 = V_13 ;
V_22 = F_4 ( V_2 , 0x00 , & V_66 ) ;
if ( V_22 < 0 )
goto V_62;
F_18 ( & V_13 -> V_14 , L_7 , V_54 , V_66 ) ;
switch ( V_66 ) {
case 0xa1 :
break;
default:
V_22 = - V_69 ;
goto V_62;
}
F_19 ( & V_13 -> V_14 , L_8 ,
V_15 ) ;
if ( V_2 -> V_9 -> V_28 ) {
V_22 = F_1 ( V_2 , 0x09 , 0x6f ) ;
if ( V_22 < 0 )
goto V_62;
}
if ( V_2 -> V_9 -> V_70 ) {
V_22 = F_1 ( V_2 , 0x0b , 0x82 ) ;
if ( V_22 < 0 )
goto V_62;
}
V_19 -> V_20 = V_2 ;
memcpy ( & V_19 -> V_29 . V_71 , & V_72 ,
sizeof( struct V_73 ) ) ;
V_62:
if ( V_19 -> V_29 . V_30 )
V_19 -> V_29 . V_30 ( V_19 , 0 ) ;
if ( V_22 ) {
F_18 ( & V_13 -> V_14 , L_9 , V_54 , V_22 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
return V_19 ;
}
