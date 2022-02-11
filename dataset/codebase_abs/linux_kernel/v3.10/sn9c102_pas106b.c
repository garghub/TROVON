static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 (cam, {0x00 , 0x10}, {0x00 , 0x11},
{0x00 , 0x14}, {0x20 , 0x17},
{0x20 , 0x19}, {0x09 , 0x18}) ;
V_3 += F_3 ( V_2 , 0x02 , 0x0c ) ;
V_3 += F_3 ( V_2 , 0x05 , 0x5a ) ;
V_3 += F_3 ( V_2 , 0x06 , 0x88 ) ;
V_3 += F_3 ( V_2 , 0x07 , 0x80 ) ;
V_3 += F_3 ( V_2 , 0x10 , 0x06 ) ;
V_3 += F_3 ( V_2 , 0x11 , 0x06 ) ;
V_3 += F_3 ( V_2 , 0x12 , 0x00 ) ;
V_3 += F_3 ( V_2 , 0x14 , 0x02 ) ;
V_3 += F_3 ( V_2 , 0x13 , 0x01 ) ;
F_4 ( 400 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case V_7 :
{
int V_8 = F_6 ( V_2 , 0x03 ) ,
V_9 = F_6 ( V_2 , 0x04 ) ;
if ( V_8 < 0 || V_9 < 0 )
return - V_10 ;
V_5 -> V_11 = ( V_8 << 4 ) | ( V_9 & 0x0f ) ;
}
return 0 ;
case V_12 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x0c ) ) < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x1f ;
return 0 ;
case V_13 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x09 ) ) < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x1f ;
return 0 ;
case V_14 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x0e ) ) < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x1f ;
return 0 ;
case V_15 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x0f ) ) < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x07 ;
return 0 ;
case V_16 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x0a ) ) < 0 )
return - V_10 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0x1f ) << 1 ;
return 0 ;
case V_17 :
if ( ( V_5 -> V_11 = F_6 ( V_2 , 0x08 ) ) < 0 )
return - V_10 ;
V_5 -> V_11 &= 0xf8 ;
return 0 ;
default:
return - V_18 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
int V_3 = 0 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 += F_3 ( V_2 , 0x03 , V_5 -> V_11 >> 4 ) ;
V_3 += F_3 ( V_2 , 0x04 , V_5 -> V_11 & 0x0f ) ;
break;
case V_12 :
V_3 += F_3 ( V_2 , 0x0c , V_5 -> V_11 ) ;
break;
case V_13 :
V_3 += F_3 ( V_2 , 0x09 , V_5 -> V_11 ) ;
break;
case V_14 :
V_3 += F_3 ( V_2 , 0x0e , V_5 -> V_11 ) ;
break;
case V_15 :
V_3 += F_3 ( V_2 , 0x0f , V_5 -> V_11 ) ;
break;
case V_16 :
V_3 += F_3 ( V_2 , 0x0a , V_5 -> V_11 >> 1 ) ;
V_3 += F_3 ( V_2 , 0x0b , V_5 -> V_11 >> 1 ) ;
break;
case V_17 :
V_3 += F_3 ( V_2 , 0x08 , V_5 -> V_11 << 3 ) ;
break;
default:
return - V_18 ;
}
V_3 += F_3 ( V_2 , 0x13 , 0x01 ) ;
return V_3 ? - V_10 : 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_21 * V_22 = F_9 ( V_2 ) ;
int V_3 = 0 ;
T_1 V_23 = ( T_1 ) ( V_20 -> V_24 - V_22 -> V_25 . V_26 . V_24 ) + 4 ,
V_27 = ( T_1 ) ( V_20 -> V_28 - V_22 -> V_25 . V_26 . V_28 ) + 3 ;
V_3 += F_10 ( V_2 , V_23 , 0x12 ) ;
V_3 += F_10 ( V_2 , V_27 , 0x13 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
int V_3 = 0 ;
if ( V_30 -> V_31 == V_32 )
V_3 += F_10 ( V_2 , 0x2c , 0x17 ) ;
else
V_3 += F_10 ( V_2 , 0x20 , 0x17 ) ;
return V_3 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_33 = 0 , V_8 = 0 ;
unsigned int V_34 = 0 ;
if ( F_2 (cam,
{0x01 , 0x01},
{0x00 , 0x01},
{0x28 , 0x17}) )
return - V_10 ;
V_33 = F_13 ( V_2 , & V_35 , 0x00 ) ;
V_8 = F_13 ( V_2 , & V_35 , 0x01 ) ;
if ( V_33 < 0 || V_8 < 0 )
return - V_10 ;
V_34 = ( V_33 << 11 ) | ( ( V_8 & 0xf0 ) >> 4 ) ;
if ( V_34 != 0x007 )
return - V_36 ;
F_14 ( V_2 , & V_35 ) ;
return 0 ;
}
