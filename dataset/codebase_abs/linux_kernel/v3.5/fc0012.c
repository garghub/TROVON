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
static int F_5 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_16 ) ;
V_15 -> V_16 = NULL ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 , V_18 = 0 ;
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
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_17 , V_18 = 0 ;
struct V_26 * V_27 = & V_15 -> V_28 ;
T_2 V_29 = V_27 -> V_30 / 1000 ;
T_2 V_31 = V_27 -> V_32 ;
unsigned char V_3 [ 7 ] , V_33 , V_34 , V_35 , V_36 ;
unsigned long V_37 ;
unsigned short V_38 , V_39 , V_40 ;
int V_41 = false ;
if ( V_15 -> V_42 ) {
V_18 = V_15 -> V_42 ( V_2 -> V_11 , V_43 ,
V_44 , ( V_29 > 300000 ? 0 : 1 ) ) ;
if ( V_18 )
goto exit;
}
switch ( V_2 -> V_19 ) {
case V_20 :
V_38 = 27000 / 2 ;
break;
case V_22 :
V_38 = 36000 / 2 ;
break;
case V_21 :
default:
V_38 = 28800 / 2 ;
break;
}
if ( V_29 < 37084 ) {
V_35 = 96 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 55625 ) {
V_35 = 64 ;
V_3 [ 5 ] = 0x82 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 74167 ) {
V_35 = 48 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 111250 ) {
V_35 = 32 ;
V_3 [ 5 ] = 0x42 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 148334 ) {
V_35 = 24 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 222500 ) {
V_35 = 16 ;
V_3 [ 5 ] = 0x22 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 296667 ) {
V_35 = 12 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x00 ;
} else if ( V_29 < 445000 ) {
V_35 = 8 ;
V_3 [ 5 ] = 0x12 ;
V_3 [ 6 ] = 0x02 ;
} else if ( V_29 < 593334 ) {
V_35 = 6 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x00 ;
} else {
V_35 = 4 ;
V_3 [ 5 ] = 0x0a ;
V_3 [ 6 ] = 0x02 ;
}
V_37 = V_29 * V_35 ;
if ( V_37 >= 3060000 ) {
V_3 [ 6 ] |= 0x08 ;
V_41 = true ;
}
if ( V_29 >= 45000 ) {
V_40 = ( unsigned short ) ( V_37 / V_38 ) ;
if ( ( V_37 - V_40 * V_38 ) >= ( V_38 / 2 ) )
V_40 ++ ;
V_34 = ( unsigned char ) ( V_40 / 8 ) ;
V_33 = ( unsigned char ) ( V_40 - ( 8 * V_34 ) ) ;
if ( V_33 < 2 ) {
V_3 [ 1 ] = V_33 + 8 ;
V_3 [ 2 ] = V_34 - 1 ;
} else {
V_3 [ 1 ] = V_33 ;
V_3 [ 2 ] = V_34 ;
}
} else {
V_3 [ 1 ] = 0x06 ;
V_3 [ 2 ] = 0x11 ;
}
V_3 [ 6 ] |= 0x20 ;
V_39 = ( unsigned short ) ( V_37 - ( V_37 / V_38 ) * V_38 ) ;
V_39 = ( V_39 << 15 ) / V_38 ;
if ( V_39 >= 16384 )
V_39 += 32768 ;
V_3 [ 3 ] = V_39 >> 8 ;
V_3 [ 4 ] = V_39 & 0xff ;
if ( V_31 == V_45 ) {
V_3 [ 6 ] &= 0x3f ;
switch ( V_27 -> V_46 ) {
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
F_3 ( L_4 , V_47 ) ;
return - V_48 ;
}
V_3 [ 5 ] |= 0x07 ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
for ( V_17 = 1 ; V_17 <= 6 ; V_17 ++ ) {
V_18 = F_1 ( V_2 , V_17 , V_3 [ V_17 ] ) ;
if ( V_18 )
goto exit;
}
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
if ( ! V_18 ) {
F_10 ( 10 ) ;
V_18 = F_4 ( V_2 , 0x0e , & V_36 ) ;
}
if ( V_18 )
goto exit;
V_36 &= 0x3f ;
if ( V_41 ) {
if ( V_36 > 0x3c ) {
V_3 [ 6 ] &= ~ 0x08 ;
V_18 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
} else {
if ( V_36 < 0x02 ) {
V_3 [ 6 ] |= 0x08 ;
V_18 = F_1 ( V_2 , 0x06 , V_3 [ 6 ] ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x80 ) ;
if ( ! V_18 )
V_18 = F_1 ( V_2 , 0x0e , 0x00 ) ;
}
}
V_2 -> V_30 = V_27 -> V_30 ;
V_2 -> V_49 = V_27 -> V_46 ;
exit:
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
if ( V_18 )
F_11 ( L_5 , V_47 , V_18 ) ;
return V_18 ;
}
static int F_12 ( struct V_14 * V_15 , T_2 * V_30 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_30 = V_2 -> V_30 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , T_2 * V_30 )
{
* V_30 = 0 ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 , T_2 * V_49 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_49 = V_2 -> V_49 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , T_3 * V_50 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_18 ;
unsigned char V_36 ;
int V_51 , V_52 , V_53 , V_54 , V_55 ;
const int V_56 [] = {
- 63 , - 58 , - 99 , - 73 ,
- 63 , - 65 , - 54 , - 60 ,
71 , 70 , 68 , 67 ,
65 , 63 , 61 , 58 ,
197 , 191 , 188 , 186 ,
184 , 182 , 181 , 179 ,
} ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 1 ) ;
V_18 = F_1 ( V_2 , 0x12 , 0x00 ) ;
if ( V_18 )
goto F_3;
V_18 = F_4 ( V_2 , 0x12 , & V_36 ) ;
if ( V_18 )
goto F_3;
V_51 = V_36 ;
V_18 = F_4 ( V_2 , 0x13 , & V_36 ) ;
if ( V_18 )
goto F_3;
V_52 = V_36 & 0x1f ;
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
if ( V_52 < F_16 ( V_56 ) ) {
V_53 = V_56 [ V_52 ] ;
V_54 = ( abs ( ( V_51 >> 5 ) - 7 ) - 2 +
( V_51 & 0x1f ) ) * 2 ;
V_55 = V_57 - V_54 - V_53 / 10 ;
if ( V_55 >= 45 )
* V_50 = 255 ;
else if ( V_55 < - 95 )
* V_50 = 0 ;
else
* V_50 = ( V_55 + 95 ) * 255 / 140 ;
* V_50 |= * V_50 << 8 ;
} else {
V_18 = - 1 ;
}
goto exit;
F_3:
if ( V_15 -> V_24 . V_25 )
V_15 -> V_24 . V_25 ( V_15 , 0 ) ;
exit:
if ( V_18 )
F_11 ( L_5 , V_47 , V_18 ) ;
return V_18 ;
}
struct V_14 * F_17 ( struct V_14 * V_15 ,
struct V_58 * V_11 , T_1 V_59 , int V_23 ,
enum V_60 V_19 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_61 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_59 ;
V_2 -> V_19 = V_19 ;
F_19 ( L_6 ) ;
V_15 -> V_16 = V_2 ;
memcpy ( & V_15 -> V_24 . V_62 , & V_63 ,
sizeof( struct V_64 ) ) ;
return V_15 ;
}
