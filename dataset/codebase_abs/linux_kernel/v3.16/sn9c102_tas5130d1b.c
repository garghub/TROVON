static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 (cam, {0x01 , 0x01}, {0x20 , 0x17},
{0x04 , 0x01}, {0x01 , 0x10},
{0x00 , 0x11}, {0x00 , 0x14},
{0x60 , 0x17}, {0x07 , 0x18}) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
int V_3 = 0 ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 += F_4 ( V_2 , 0x20 , 0xf6 - V_5 -> V_8 ) ;
break;
case V_9 :
V_3 += F_4 ( V_2 , 0x40 , 0x47 - V_5 -> V_8 ) ;
break;
default:
return - V_10 ;
}
return V_3 ? - V_11 : 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
T_1 V_16 = ( T_1 ) ( V_13 -> V_17 - V_15 -> V_18 . V_19 . V_17 ) + 104 ,
V_20 = ( T_1 ) ( V_13 -> V_21 - V_15 -> V_18 . V_19 . V_21 ) + 12 ;
int V_3 = 0 ;
V_3 += F_7 ( V_2 , V_16 , 0x12 ) ;
V_3 += F_7 ( V_2 , V_20 , 0x13 ) ;
V_3 += F_7 ( V_2 , 0x1f , 0x1a ) ;
V_3 += F_7 ( V_2 , 0x1a , 0x1b ) ;
V_3 += F_7 ( V_2 , F_8 ( V_2 , 0x19 ) , 0x19 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
int V_3 = 0 ;
if ( V_23 -> V_24 == V_25 )
V_3 += F_7 ( V_2 , 0x63 , 0x19 ) ;
else
V_3 += F_7 ( V_2 , 0xf3 , 0x19 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_2 )
{
const struct V_26 V_27 [] = {
{ F_11 ( 0x0c45 , 0x6024 ) , } ,
{ F_11 ( 0x0c45 , 0x6025 ) , } ,
{ F_11 ( 0x0c45 , 0x60aa ) , } ,
{ }
} ;
if ( ! F_12 ( V_2 , V_27 ) )
return - V_28 ;
F_13 ( V_2 , & V_29 ) ;
return 0 ;
}
