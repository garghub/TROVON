static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 (cam, {0x01 , 0x01}, {0x04 , 0x01},
{0x0a , 0x14}, {0x60 , 0x17},
{0x06 , 0x18}, {0xfb , 0x19}) ;
V_3 += F_3 ( V_2 , 0x9a , 0xca ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
int V_3 = 0 ;
T_1 V_8 = ( T_1 ) ( V_5 -> V_9 - V_7 -> V_10 . V_11 . V_9 ) + 69 ,
V_12 = ( T_1 ) ( V_5 -> V_13 - V_7 -> V_10 . V_11 . V_13 ) + 9 ;
V_3 += F_6 ( V_2 , V_8 , 0x12 ) ;
V_3 += F_6 ( V_2 , V_12 , 0x13 ) ;
V_3 += F_6 ( V_2 , 0x14 , 0x1a ) ;
V_3 += F_6 ( V_2 , 0x0a , 0x1b ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
int V_3 = 0 ;
if ( V_15 -> V_16 == V_17 )
V_3 += F_6 ( V_2 , 0x3b , 0x19 ) ;
else
V_3 += F_6 ( V_2 , 0xfb , 0x19 ) ;
return V_3 ;
}
int F_8 ( struct V_1 * V_2 )
{
const struct V_18 V_19 [] = {
{ F_9 ( 0x0c45 , 0x6007 ) , } ,
{ }
} ;
if ( ! F_10 ( V_2 , V_19 ) )
return - V_20 ;
F_11 ( V_2 , & V_21 ) ;
return 0 ;
}
