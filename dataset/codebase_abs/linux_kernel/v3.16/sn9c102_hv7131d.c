static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 (cam, {0x00 , 0x10}, {0x00 , 0x11},
{0x00 , 0x14}, {0x60 , 0x17},
{0x0e , 0x18}, {0xf2 , 0x19}) ;
V_3 += F_3 ( V_2 , 0x01 , 0x04 ) ;
V_3 += F_3 ( V_2 , 0x02 , 0x00 ) ;
V_3 += F_3 ( V_2 , 0x28 , 0x00 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case V_7 :
{
int V_8 = F_5 ( V_2 , 0x26 ) ,
V_9 = F_5 ( V_2 , 0x27 ) ;
if ( V_8 < 0 || V_9 < 0 )
return - V_10 ;
V_5 -> V_11 = ( V_8 << 8 ) | ( V_9 & 0xff ) ;
}
return 0 ;
case V_12 :
V_5 -> V_11 = F_5 ( V_2 , 0x31 ) ;
if ( V_5 -> V_11 < 0 )
return - V_10 ;
V_5 -> V_11 = 0x3f - ( V_5 -> V_11 & 0x3f ) ;
return 0 ;
case V_13 :
V_5 -> V_11 = F_5 ( V_2 , 0x33 ) ;
if ( V_5 -> V_11 < 0 )
return - V_10 ;
V_5 -> V_11 = 0x3f - ( V_5 -> V_11 & 0x3f ) ;
return 0 ;
case V_14 :
V_5 -> V_11 = F_5 ( V_2 , 0x32 ) ;
if ( V_5 -> V_11 < 0 )
return - V_10 ;
V_5 -> V_11 = 0x3f - ( V_5 -> V_11 & 0x3f ) ;
return 0 ;
case V_15 :
V_5 -> V_11 = F_5 ( V_2 , 0x30 ) ;
if ( V_5 -> V_11 < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x3f ;
return 0 ;
case V_16 :
V_5 -> V_11 = F_5 ( V_2 , 0x34 ) ;
if ( V_5 -> V_11 < 0 )
return - V_10 ;
V_5 -> V_11 &= 0x07 ;
return 0 ;
default:
return - V_17 ;
}
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
int V_3 = 0 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 += F_3 ( V_2 , 0x26 , V_5 -> V_11 >> 8 ) ;
V_3 += F_3 ( V_2 , 0x27 , V_5 -> V_11 & 0xff ) ;
break;
case V_12 :
V_3 += F_3 ( V_2 , 0x31 , 0x3f - V_5 -> V_11 ) ;
break;
case V_13 :
V_3 += F_3 ( V_2 , 0x33 , 0x3f - V_5 -> V_11 ) ;
break;
case V_14 :
V_3 += F_3 ( V_2 , 0x32 , 0x3f - V_5 -> V_11 ) ;
break;
case V_15 :
V_3 += F_3 ( V_2 , 0x30 , V_5 -> V_11 ) ;
break;
case V_16 :
V_3 += F_3 ( V_2 , 0x34 , V_5 -> V_11 ) ;
break;
default:
return - V_17 ;
}
return V_3 ? - V_10 : 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
int V_3 = 0 ;
T_1 V_22 = ( T_1 ) ( V_19 -> V_23 - V_21 -> V_24 . V_25 . V_23 ) + 2 ,
V_26 = ( T_1 ) ( V_19 -> V_27 - V_21 -> V_24 . V_25 . V_27 ) + 2 ;
V_3 += F_9 ( V_2 , V_22 , 0x12 ) ;
V_3 += F_9 ( V_2 , V_26 , 0x13 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
int V_3 = 0 ;
if ( V_29 -> V_30 == V_31 )
V_3 += F_9 ( V_2 , 0x42 , 0x19 ) ;
else
V_3 += F_9 ( V_2 , 0xf2 , 0x19 ) ;
return V_3 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_32 = 0 , V_8 = 0 , V_3 ;
V_3 = F_2 (cam, {0x01 , 0x01}, {0x00 , 0x01},
{0x28 , 0x17}) ;
V_32 = F_12 ( V_2 , & V_33 , 0x00 ) ;
V_8 = F_12 ( V_2 , & V_33 , 0x01 ) ;
if ( V_3 || V_32 < 0 || V_8 < 0 )
return - V_10 ;
if ( ( V_32 != 0x00 && V_32 != 0x01 ) || V_8 != 0x04 )
return - V_34 ;
F_13 ( V_2 , & V_33 ) ;
return 0 ;
}
