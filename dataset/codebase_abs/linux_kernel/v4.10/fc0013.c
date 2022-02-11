static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 , . V_9 = 0 , . V_5 = V_5 , . V_10 = 2
} ;
if ( F_2 ( V_2 -> V_11 , & V_7 , 1 ) != 1 ) {
F_3 ( L_1 , V_3 , V_4 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_6 V_7 [ 2 ] = {
{ . V_8 = V_2 -> V_8 , . V_9 = 0 , . V_5 = & V_3 , . V_10 = 1 } ,
{ . V_8 = V_2 -> V_8 , . V_9 = V_13 , . V_5 = V_4 , . V_10 = 1 } ,
} ;
if ( F_2 ( V_2 -> V_11 , V_7 , 2 ) != 2 ) {
F_3 ( L_2 , V_3 ) ;
return - V_12 ;
}
return 0 ;
}
static void F_5 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 , V_18 = 0 ;
unsigned char V_3 [] = {
0x00 ,
0x09 ,
0x16 ,
0x00 ,
0x00 ,
0x17 ,
0x02 ,
0x0a ,
0xff ,
0x6f ,
0xb8 ,
0x82 ,
0xfc ,
0x01 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x50 ,
0x01 ,
} ;
switch ( V_2 -> V_19 ) {
case V_20 :
case V_21 :
V_3 [ 0x07 ] |= 0x20 ;
break;
case V_22 :
default:
break;
}
if ( V_2 -> V_23 )
V_3 [ 0x0c ] |= 0x02 ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
for ( V_17 = 1 ; V_17 < sizeof( V_3 ) ; V_17 ++ ) {
V_18 = F_1 ( V_2 , V_17 , V_3 [ V_17 ] ) ;
if ( V_18 )
break;
}
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
if ( V_18 )
F_3 ( L_3 , V_18 ) ;
return V_18 ;
}
static int F_8 ( struct V_14 * V_15 )
{
return 0 ;
}
int F_9 ( struct V_14 * V_15 , int V_26 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_18 ;
T_1 V_27 ;
int V_4 ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
V_18 = F_1 ( V_2 , 0x10 , 0x00 ) ;
if ( V_18 )
goto V_28;
V_18 = F_4 ( V_2 , 0x10 , & V_27 ) ;
if ( V_18 )
goto V_28;
V_27 &= 0x0f ;
V_4 = ( int ) V_27 + V_26 ;
V_18 = F_1 ( V_2 , 0x0d , 0x11 ) ;
if ( V_18 )
goto V_28;
if ( V_4 > 15 )
V_18 = F_1 ( V_2 , 0x10 , 0x0f ) ;
else if ( V_4 < 0 )
V_18 = F_1 ( V_2 , 0x10 , 0x00 ) ;
else
V_18 = F_1 ( V_2 , 0x10 , ( T_1 ) V_4 ) ;
V_28:
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
return V_18 ;
}
int F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_18 ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
V_18 = F_1 ( V_2 , 0x0d , 0x01 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x10 , 0x00 ) ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_29 )
{
int V_18 ;
T_1 V_30 ;
V_18 = F_4 ( V_2 , 0x1d , & V_30 ) ;
if ( V_18 )
goto V_28;
V_30 &= 0xe3 ;
if ( V_29 <= 177500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x1c ) ;
} else if ( V_29 <= 184500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x18 ) ;
} else if ( V_29 <= 191500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x14 ) ;
} else if ( V_29 <= 198500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x10 ) ;
} else if ( V_29 <= 205500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x0c ) ;
} else if ( V_29 <= 219500 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x08 ) ;
} else if ( V_29 < 300000 ) {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x04 ) ;
} else {
V_18 = F_1 ( V_2 , 0x1d , V_30 | 0x1c ) ;
}
V_28:
return V_18 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 , V_18 = 0 ;
struct V_31 * V_32 = & V_15 -> V_33 ;
T_2 V_29 = V_32 -> V_34 / 1000 ;
T_2 V_35 = V_32 -> V_36 ;
unsigned char V_3 [ 7 ] , V_37 , V_38 , V_39 , V_30 ;
unsigned long V_40 ;
unsigned short V_41 , V_42 , V_43 ;
bool V_44 = false ;
if ( V_15 -> V_45 ) {
V_18 = V_15 -> V_45 ( V_2 -> V_11 , V_46 ,
V_47 , ( V_29 > 300000 ? 0 : 1 ) ) ;
if ( V_18 )
goto exit;
}
switch ( V_2 -> V_19 ) {
case V_20 :
V_41 = 27000 / 2 ;
break;
case V_22 :
V_41 = 36000 / 2 ;
break;
case V_21 :
default:
V_41 = 28800 / 2 ;
break;
}
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
V_18 = F_11 ( V_2 , V_29 ) ;
if ( V_18 )
goto exit;
if ( V_29 < 300000 ) {
V_18 = F_4 ( V_2 , 0x07 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x07 , V_30 | 0x10 ) ;
if ( V_18 )
goto exit;
V_18 = F_4 ( V_2 , 0x14 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x14 , V_30 & 0x1f ) ;
if ( V_18 )
goto exit;
} else if ( V_29 <= 862000 ) {
V_18 = F_4 ( V_2 , 0x07 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x07 , V_30 & 0xef ) ;
if ( V_18 )
goto exit;
V_18 = F_4 ( V_2 , 0x14 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x14 , ( V_30 & 0x1f ) | 0x40 ) ;
if ( V_18 )
goto exit;
} else {
V_18 = F_4 ( V_2 , 0x07 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x07 , V_30 & 0xef ) ;
if ( V_18 )
goto exit;
V_18 = F_4 ( V_2 , 0x14 , & V_30 ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x14 , ( V_30 & 0x1f ) | 0x20 ) ;
if ( V_18 )
goto exit;
}
if ( V_29 < 37084 ) {
V_39 = 96 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 55625 ) {
V_39 = 64 ;
V_3 [ 5 ] = 0x02 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 74167 ) {
V_39 = 48 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 111250 ) {
V_39 = 32 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 148334 ) {
V_39 = 24 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 222500 ) {
V_39 = 16 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 296667 ) {
V_39 = 12 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 445000 ) {
V_39 = 8 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 593334 ) {
V_39 = 6 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 950000 ) {
V_39 = 4 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x02 ;
} else {
V_39 = 2 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x02 ;
}
V_40 = V_29 * V_39 ;
if ( V_40 >= 3060000 ) {
V_3 [ 6 ] |= 0x08 ;
V_44 = true ;
}
if ( V_29 >= 45000 ) {
V_43 = ( unsigned short ) ( V_40 / V_41 ) ;
if ( ( V_40 - V_43 * V_41 ) >= ( V_41 / 2 ) )
V_43 ++ ;
V_38 = ( unsigned char ) ( V_43 / 8 ) ;
V_37 = ( unsigned char ) ( V_43 - ( 8 * V_38 ) ) ;
if ( V_37 < 2 ) {
V_3 [ 1 ] = V_37 + 8 ;
V_3 [ 2 ] = V_38 - 1 ;
} else {
V_3 [ 1 ] = V_37 ;
V_3 [ 2 ] = V_38 ;
}
} else {
V_3 [ 1 ] = 0x06 ;
V_3 [ 2 ] = 0x11 ;
}
V_3 [ 6 ] |= 0x20 ;
V_42 = ( unsigned short ) ( V_40 - ( V_40 / V_41 ) * V_41 ) ;
V_42 = ( V_42 << 15 ) / V_41 ;
if ( V_42 >= 16384 )
V_42 += 32768 ;
V_3 [ 3 ] = V_42 >> 8 ;
V_3 [ 4 ] = V_42 & 0xff ;
if ( V_35 == V_48 ) {
V_3 [ 6 ] &= 0x3f ;
switch ( V_32 -> V_49 ) {
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
F_3 ( L_4 , V_50 ) ;
return - V_51 ;
}
V_3 [ 5 ] |= 0x07 ;
for ( V_17 = 1 ; V_17 <= 6 ; V_17 ++ ) {
V_18 = F_1 ( V_2 , V_17 , V_3 [ V_17 ] ) ;
if ( V_18 )
goto exit;
}
V_18 = F_4 ( V_2 , 0x11 , & V_30 ) ;
if ( V_18 )
goto exit;
if ( V_39 == 64 )
V_18 = F_1 ( V_2 , 0x11 , V_30 | 0x04 ) ;
else
V_18 = F_1 ( V_2 , 0x11 , V_30 & 0xfb ) ;
if ( V_18 )
goto exit;
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_18 ) {
F_13 ( 10 ) ;
V_18 = F_4 ( V_2 , 0x0e , & V_30 ) ;
}
if ( V_18 )
goto exit;
V_30 &= 0x3f ;
if ( V_44 ) {
if ( V_30 > 0x3c ) {
V_3 [ 6 ] &= ~ 0x08 ;
V_18 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
} else {
if ( V_30 < 0x02 ) {
V_3 [ 6 ] |= 0x08 ;
V_18 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
}
V_2 -> V_34 = V_32 -> V_34 ;
V_2 -> V_52 = V_32 -> V_49 ;
exit:
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
if ( V_18 )
F_14 ( L_5 , V_50 , V_18 ) ;
return V_18 ;
}
static int F_15 ( struct V_14 * V_15 , T_2 * V_34 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_34 = V_2 -> V_34 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 , T_2 * V_34 )
{
* V_34 = 0 ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , T_2 * V_52 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_52 = V_2 -> V_52 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , T_3 * V_53 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_18 ;
unsigned char V_30 ;
int V_54 , V_55 , V_56 , V_57 , V_58 ;
const int V_59 [] = {
- 63 , - 58 , - 99 , - 73 ,
- 63 , - 65 , - 54 , - 60 ,
71 , 70 , 68 , 67 ,
65 , 63 , 61 , 58 ,
197 , 191 , 188 , 186 ,
184 , 182 , 181 , 179 ,
} ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
V_18 = F_1 ( V_2 , 0x13 , 0x00 ) ;
if ( V_18 )
goto F_3;
V_18 = F_4 ( V_2 , 0x13 , & V_30 ) ;
if ( V_18 )
goto F_3;
V_54 = V_30 ;
V_18 = F_4 ( V_2 , 0x14 , & V_30 ) ;
if ( V_18 )
goto F_3;
V_55 = V_30 & 0x1f ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
if ( V_55 < F_19 ( V_59 ) ) {
V_56 = V_59 [ V_55 ] ;
V_57 = ( abs ( ( V_54 >> 5 ) - 7 ) - 2 +
( V_54 & 0x1f ) ) * 2 ;
V_58 = V_60 - V_57 - V_56 / 10 ;
if ( V_58 >= 45 )
* V_53 = 255 ;
else if ( V_58 < - 95 )
* V_53 = 0 ;
else
* V_53 = ( V_58 + 95 ) * 255 / 140 ;
* V_53 |= * V_53 << 8 ;
} else {
V_18 = - 1 ;
}
goto exit;
F_3:
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
exit:
if ( V_18 )
F_14 ( L_5 , V_50 , V_18 ) ;
return V_18 ;
}
struct V_14 * F_20 ( struct V_14 * V_15 ,
struct V_61 * V_11 , T_1 V_62 , int V_23 ,
enum V_63 V_19 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_62 ;
V_2 -> V_19 = V_19 ;
F_22 ( L_6 ) ;
V_15 -> V_16 = V_2 ;
memcpy ( & V_15 -> V_24 . V_65 , & V_66 ,
sizeof( struct V_67 ) ) ;
return V_15 ;
}
