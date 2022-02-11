static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
switch ( F_2 ( V_2 ) ) {
case V_4 :
case V_5 :
V_3 = F_3 (cam, {0x00 , 0x10}, {0x00 , 0x11},
{0x00 , 0x14}, {0x20 , 0x17},
{0x30 , 0x19}, {0x09 , 0x18}) ;
break;
case V_6 :
V_3 = F_3 (cam, {0x00 , 0x02}, {0x00 , 0x03},
{0x1a , 0x04}, {0x20 , 0x05},
{0x20 , 0x06}, {0x20 , 0x07},
{0x00 , 0x10}, {0x00 , 0x11},
{0x00 , 0x14}, {0x20 , 0x17},
{0x30 , 0x19}, {0x09 , 0x18},
{0x02 , 0x1c}, {0x03 , 0x1d},
{0x0f , 0x1e}, {0x0c , 0x1f},
{0x00 , 0x20}, {0x10 , 0x21},
{0x20 , 0x22}, {0x30 , 0x23},
{0x40 , 0x24}, {0x50 , 0x25},
{0x60 , 0x26}, {0x70 , 0x27},
{0x80 , 0x28}, {0x90 , 0x29},
{0xa0 , 0x2a}, {0xb0 , 0x2b},
{0xc0 , 0x2c}, {0xd0 , 0x2d},
{0xe0 , 0x2e}, {0xf0 , 0x2f},
{0xff , 0x30}) ;
break;
default:
break;
}
V_3 += F_4 ( V_2 , 0x02 , 0x14 ) ;
V_3 += F_4 ( V_2 , 0x03 , 0x40 ) ;
V_3 += F_4 ( V_2 , 0x0d , 0x2c ) ;
V_3 += F_4 ( V_2 , 0x0e , 0x01 ) ;
V_3 += F_4 ( V_2 , 0x0f , 0xa9 ) ;
V_3 += F_4 ( V_2 , 0x10 , 0x08 ) ;
V_3 += F_4 ( V_2 , 0x13 , 0x63 ) ;
V_3 += F_4 ( V_2 , 0x15 , 0x70 ) ;
V_3 += F_4 ( V_2 , 0x11 , 0x01 ) ;
F_5 ( 400 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
switch ( V_8 -> V_9 ) {
case V_10 :
{
int V_11 = F_7 ( V_2 , 0x04 ) ,
V_12 = F_7 ( V_2 , 0x05 ) ;
if ( V_11 < 0 || V_12 < 0 )
return - V_13 ;
V_8 -> V_14 = ( V_11 << 6 ) | ( V_12 & 0x3f ) ;
}
return 0 ;
case V_15 :
V_8 -> V_14 = F_7 ( V_2 , 0x09 ) ;
if ( V_8 -> V_14 < 0 )
return - V_13 ;
V_8 -> V_14 &= 0x0f ;
return 0 ;
case V_16 :
V_8 -> V_14 = F_7 ( V_2 , 0x07 ) ;
if ( V_8 -> V_14 < 0 )
return - V_13 ;
V_8 -> V_14 &= 0x0f ;
return 0 ;
case V_17 :
V_8 -> V_14 = F_7 ( V_2 , 0x10 ) ;
if ( V_8 -> V_14 < 0 )
return - V_13 ;
V_8 -> V_14 &= 0x1f ;
return 0 ;
case V_18 :
V_8 -> V_14 = F_7 ( V_2 , 0x08 ) ;
if ( V_8 -> V_14 < 0 )
return - V_13 ;
V_8 -> V_14 &= 0x0f ;
return 0 ;
case V_19 :
V_8 -> V_14 = F_7 ( V_2 , 0x0c ) ;
if ( V_8 -> V_14 < 0 )
return - V_13 ;
return 0 ;
default:
return - V_20 ;
}
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
int V_3 = 0 ;
if ( V_22 -> V_23 == V_24 )
V_3 += F_9 ( V_2 , 0x28 , 0x17 ) ;
else
V_3 += F_9 ( V_2 , 0x20 , 0x17 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_7 * V_8 )
{
int V_3 = 0 ;
switch ( V_8 -> V_9 ) {
case V_10 :
V_3 += F_4 ( V_2 , 0x04 , V_8 -> V_14 >> 6 ) ;
V_3 += F_4 ( V_2 , 0x05 , V_8 -> V_14 & 0x3f ) ;
break;
case V_15 :
V_3 += F_4 ( V_2 , 0x09 , V_8 -> V_14 ) ;
break;
case V_16 :
V_3 += F_4 ( V_2 , 0x07 , V_8 -> V_14 ) ;
break;
case V_17 :
V_3 += F_4 ( V_2 , 0x10 , V_8 -> V_14 ) ;
break;
case V_18 :
V_3 += F_4 ( V_2 , 0x08 , V_8 -> V_14 ) ;
break;
case V_19 :
V_3 += F_4 ( V_2 , 0x0c , V_8 -> V_14 ) ;
break;
default:
return - V_20 ;
}
V_3 += F_4 ( V_2 , 0x11 , 0x01 ) ;
return V_3 ? - V_13 : 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_12 ( V_2 ) ;
int V_3 = 0 ;
T_1 V_29 = 0 ,
V_30 = ( T_1 ) ( V_26 -> V_31 - V_28 -> V_32 . V_33 . V_31 ) + 3 ;
switch ( F_2 ( V_2 ) ) {
case V_4 :
case V_5 :
V_29 = ( T_1 ) ( V_26 -> V_34 - V_28 -> V_32 . V_33 . V_34 ) + 4 ;
break;
case V_6 :
V_29 = ( T_1 ) ( V_26 -> V_34 - V_28 -> V_32 . V_33 . V_34 ) + 3 ;
break;
default:
break;
}
V_3 += F_9 ( V_2 , V_29 , 0x12 ) ;
V_3 += F_9 ( V_2 , V_30 , 0x13 ) ;
return V_3 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_35 = 0 , V_11 = 0 , V_3 = 0 ;
unsigned int V_36 = 0 ;
switch ( F_2 ( V_2 ) ) {
case V_4 :
case V_5 :
V_3 = F_3 (cam,
{0x01 , 0x01},
{0x40 , 0x01},
{0x28 , 0x17}) ;
break;
case V_6 :
V_3 = F_3 (cam, {0x09 , 0x01}, {0x44 , 0x01},
{0x44 , 0x02}, {0x29 , 0x17}) ;
break;
default:
break;
}
V_35 = F_14 ( V_2 , & V_37 , 0x00 ) ;
V_11 = F_14 ( V_2 , & V_37 , 0x01 ) ;
if ( V_3 || V_35 < 0 || V_11 < 0 )
return - V_13 ;
V_36 = ( V_35 << 4 ) | ( ( V_11 & 0xf0 ) >> 4 ) ;
if ( V_36 != 0x017 )
return - V_38 ;
F_15 ( V_2 , & V_37 ) ;
return 0 ;
}
