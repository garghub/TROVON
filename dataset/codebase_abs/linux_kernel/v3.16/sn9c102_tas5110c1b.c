static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 (cam, {0x01 , 0x01}, {0x44 , 0x01},
{0x00 , 0x10}, {0x00 , 0x11},
{0x0a , 0x14}, {0x60 , 0x17},
{0x06 , 0x18}, {0xfb , 0x19}) ;
V_3 += F_3 ( V_2 , 0xc0 , 0x80 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
int V_3 = 0 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 += F_3 ( V_2 , 0x20 , 0xf6 - V_5 -> V_8 ) ;
break;
default:
return - V_9 ;
}
return V_3 ? - V_10 : 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
int V_3 = 0 ;
T_1 V_15 = ( T_1 ) ( V_12 -> V_16 - V_14 -> V_17 . V_18 . V_16 ) + 69 ,
V_19 = ( T_1 ) ( V_12 -> V_20 - V_14 -> V_17 . V_18 . V_20 ) + 9 ;
V_3 += F_7 ( V_2 , V_15 , 0x12 ) ;
V_3 += F_7 ( V_2 , V_19 , 0x13 ) ;
V_3 += F_7 ( V_2 , 0x14 , 0x1a ) ;
V_3 += F_7 ( V_2 , 0x0a , 0x1b ) ;
V_3 += F_7 ( V_2 , F_8 ( V_2 , 0x19 ) , 0x19 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
int V_3 = 0 ;
if ( V_22 -> V_23 == V_24 )
V_3 += F_7 ( V_2 , 0x2b , 0x19 ) ;
else
V_3 += F_7 ( V_2 , 0xfb , 0x19 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_2 )
{
const struct V_25 V_26 [] = {
{ F_11 ( 0x0c45 , 0x6001 ) , } ,
{ F_11 ( 0x0c45 , 0x6005 ) , } ,
{ F_11 ( 0x0c45 , 0x60ab ) , } ,
{ }
} ;
if ( ! F_12 ( V_2 , V_26 ) )
return - V_27 ;
F_13 ( V_2 , & V_28 ) ;
return 0 ;
}
