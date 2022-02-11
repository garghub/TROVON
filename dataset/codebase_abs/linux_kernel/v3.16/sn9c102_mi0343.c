static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_5 = F_3 (cam, {0x00 , 0x10}, {0x00 , 0x11},
{0x0a , 0x14}, {0x40 , 0x01},
{0x20 , 0x17}, {0x07 , 0x18},
{0xa0 , 0x19}) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x0d ,
0x00 , 0x01 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x0d ,
0x00 , 0x00 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x03 ,
0x01 , 0xe1 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x04 ,
0x02 , 0x81 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x05 ,
0x00 , 0x17 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x06 ,
0x00 , 0x11 , 0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 , 0x62 ,
0x04 , 0x9a , 0 , 0 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_9 [ 2 ] ;
switch ( V_8 -> V_10 ) {
case V_11 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x09 , 2 ,
V_9 ) < 0 )
return - V_12 ;
V_8 -> V_13 = V_9 [ 0 ] ;
return 0 ;
case V_14 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x35 , 2 ,
V_9 ) < 0 )
return - V_12 ;
break;
case V_15 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x20 , 2 ,
V_9 ) < 0 )
return - V_12 ;
V_8 -> V_13 = V_9 [ 1 ] & 0x20 ? 1 : 0 ;
return 0 ;
case V_16 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x20 , 2 ,
V_9 ) < 0 )
return - V_12 ;
V_8 -> V_13 = V_9 [ 1 ] & 0x80 ? 1 : 0 ;
return 0 ;
case V_17 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x2d , 2 ,
V_9 ) < 0 )
return - V_12 ;
break;
case V_18 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x2c , 2 ,
V_9 ) < 0 )
return - V_12 ;
break;
case V_19 :
if ( F_6 ( V_2 , V_4 , V_4 -> V_6 , 0x2e , 2 ,
V_9 ) < 0 )
return - V_12 ;
break;
default:
return - V_20 ;
}
switch ( V_8 -> V_10 ) {
case V_14 :
case V_17 :
case V_18 :
case V_19 :
V_8 -> V_13 = V_9 [ 1 ] | ( V_9 [ 0 ] << 8 ) ;
if ( V_8 -> V_13 >= 0x10 && V_8 -> V_13 <= 0x3f )
V_8 -> V_13 -= 0x10 ;
else if ( V_8 -> V_13 >= 0x60 && V_8 -> V_13 <= 0x7f )
V_8 -> V_13 -= 0x60 ;
else if ( V_8 -> V_13 >= 0xe0 && V_8 -> V_13 <= 0xff )
V_8 -> V_13 -= 0xe0 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_7 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_21 = 0 ;
int V_5 = 0 ;
switch ( V_8 -> V_10 ) {
case V_14 :
case V_17 :
case V_18 :
case V_19 :
if ( V_8 -> V_13 <= ( 0x3f - 0x10 ) )
V_21 = 0x10 + V_8 -> V_13 ;
else if ( V_8 -> V_13 <= ( ( 0x3f - 0x10 ) + ( 0x7f - 0x60 ) ) )
V_21 = 0x60 + ( V_8 -> V_13 - ( 0x3f - 0x10 ) ) ;
else
V_21 = 0xe0 + ( V_8 -> V_13 - ( 0x3f - 0x10 ) - ( 0x7f - 0x60 ) ) ;
break;
}
switch ( V_8 -> V_10 ) {
case V_11 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x09 , V_8 -> V_13 , 0x00 ,
0 , 0 ) ;
break;
case V_14 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x35 , V_21 >> 8 , V_21 & 0xff ,
0 , 0 ) ;
break;
case V_15 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x20 , V_8 -> V_13 ? 0x40 : 0x00 ,
V_8 -> V_13 ? 0x20 : 0x00 ,
0 , 0 ) ;
break;
case V_16 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x20 , V_8 -> V_13 ? 0x80 : 0x00 ,
V_8 -> V_13 ? 0x80 : 0x00 ,
0 , 0 ) ;
break;
case V_17 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x2d , V_21 >> 8 , V_21 & 0xff ,
0 , 0 ) ;
break;
case V_18 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x2c , V_21 >> 8 , V_21 & 0xff ,
0 , 0 ) ;
break;
case V_19 :
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x2b , V_21 >> 8 , V_21 & 0xff ,
0 , 0 ) ;
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x2e , V_21 >> 8 , V_21 & 0xff ,
0 , 0 ) ;
break;
default:
return - V_20 ;
}
return V_5 ? - V_12 : 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
T_1 V_24 = ( T_1 ) ( V_23 -> V_25 - V_4 -> V_26 . V_27 . V_25 ) + 0 ,
V_28 = ( T_1 ) ( V_23 -> V_29 - V_4 -> V_26 . V_27 . V_29 ) + 2 ;
V_5 += F_9 ( V_2 , V_24 , 0x12 ) ;
V_5 += F_9 ( V_2 , V_28 , 0x13 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( V_31 -> V_32 == V_33 ) {
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x0a , 0x00 , 0x03 , 0 , 0 ) ;
V_5 += F_9 ( V_2 , 0x20 , 0x19 ) ;
} else {
V_5 += F_4 ( V_2 , V_4 , 4 , V_4 -> V_6 ,
0x0a , 0x00 , 0x05 , 0 , 0 ) ;
V_5 += F_9 ( V_2 , 0xa0 , 0x19 ) ;
}
return V_5 ;
}
int F_11 ( struct V_1 * V_2 )
{
T_1 V_9 [ 2 ] ;
if ( F_3 (cam, {0x01 , 0x01}, {0x00 , 0x01},
{0x28 , 0x17}) )
return - V_12 ;
if ( F_6 ( V_2 , & V_34 , V_34 . V_6 , 0x00 ,
2 , V_9 ) < 0 )
return - V_12 ;
if ( V_9 [ 1 ] != 0x42 || V_9 [ 0 ] != 0xe3 )
return - V_35 ;
F_12 ( V_2 , & V_34 ) ;
return 0 ;
}
