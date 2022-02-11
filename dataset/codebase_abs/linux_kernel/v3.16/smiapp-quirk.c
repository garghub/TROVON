static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_2 ( V_2 , F_3 ( V_3 ) , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_5 ( & V_2 -> V_10 -> V_11 ) ;
int V_12 ;
for (; V_7 > 0 ; V_7 -- , V_6 ++ ) {
V_12 = F_1 ( V_2 , V_6 -> V_3 , V_6 -> V_4 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_9 -> V_13 ,
L_1 ,
V_12 , V_6 -> V_3 , V_6 -> V_4 ) ;
return V_12 ;
}
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 ,
T_3 V_14 , T_3 V_4 )
{
struct V_8 * V_9 = F_5 ( & V_2 -> V_10 -> V_11 ) ;
F_8 ( & V_9 -> V_13 , L_2 ,
V_15 [ V_14 ] . V_16 ,
V_15 [ V_14 ] . V_17 , V_4 , V_4 ) ;
V_2 -> V_18 [ V_14 ] = V_4 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_20 < 0x03 )
V_2 -> V_21 = 1 ;
F_7 ( V_2 , V_22 , 59 ) ;
F_7 (
V_2 , V_23 , 6000 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 V_6 [] = {
{ 0x30a3 , 0xd8 } ,
{ 0x30ae , 0x00 } ,
{ 0x30af , 0xd0 } ,
{ 0x322d , 0x04 } ,
{ 0x3255 , 0x0f } ,
{ 0x3256 , 0x15 } ,
{ 0x3258 , 0x70 } ,
{ 0x3259 , 0x70 } ,
{ 0x325f , 0x7c } ,
{ 0x3302 , 0x06 } ,
{ 0x3304 , 0x00 } ,
{ 0x3307 , 0x22 } ,
{ 0x3308 , 0x8d } ,
{ 0x331e , 0x0f } ,
{ 0x3320 , 0x30 } ,
{ 0x3321 , 0x11 } ,
{ 0x3322 , 0x98 } ,
{ 0x3323 , 0x64 } ,
{ 0x3325 , 0x83 } ,
{ 0x3330 , 0x18 } ,
{ 0x333c , 0x01 } ,
{ 0x3345 , 0x2f } ,
{ 0x33de , 0x38 } ,
{ 0x32e0 , 0x05 } ,
{ 0x32e1 , 0x05 } ,
{ 0x32e2 , 0x04 } ,
{ 0x32e5 , 0x04 } ,
{ 0x32e6 , 0x04 } ,
} ;
return F_4 ( V_2 , V_6 , F_11 ( V_6 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 V_6 [] = {
{ 0x3302 , 0x01 } ,
{ 0x302d , 0x00 } ,
{ 0x3b08 , 0x8c } ,
} ;
return F_4 ( V_2 , V_6 , F_11 ( V_6 ) ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_24 , 4271 ) ;
F_7 ( V_2 ,
V_25 , 184 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( & V_2 -> V_10 -> V_11 ) ;
int V_12 ;
struct V_5 V_6 [] = {
{ 0x3031 , 0xcd } ,
{ 0x30a3 , 0xd0 } ,
{ 0x3237 , 0x00 } ,
{ 0x3238 , 0x43 } ,
{ 0x3301 , 0x06 } ,
{ 0x3302 , 0x06 } ,
{ 0x3304 , 0x00 } ,
{ 0x3305 , 0x88 } ,
{ 0x332a , 0x14 } ,
{ 0x332c , 0x6b } ,
{ 0x3336 , 0x01 } ,
{ 0x333f , 0x1f } ,
{ 0x3355 , 0x00 } ,
{ 0x3356 , 0x20 } ,
{ 0x33bf , 0x20 } ,
{ 0x33c9 , 0x20 } ,
{ 0x33ce , 0x30 } ,
{ 0x33cf , 0xec } ,
{ 0x3328 , 0x80 } ,
} ;
struct V_5 V_26 [] = {
{ 0x30ae , 0x00 } ,
{ 0x30af , 0xd0 } ,
{ 0x30b0 , 0x01 } ,
} ;
V_12 = F_4 ( V_2 , V_6 , F_11 ( V_6 ) ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_2 -> V_27 -> V_28 ) {
case 9600000 :
return F_4 ( V_2 , V_26 ,
F_11 ( V_26 ) ) ;
default:
F_15 ( & V_9 -> V_13 , L_3 ,
V_2 -> V_27 -> V_28 ) ;
return 0 ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , 0x3328 , 0x00 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_1 ( V_2 , 0x3205 , 0x04 ) ;
if ( V_12 < 0 )
return V_12 ;
F_18 ( 2000 , 2000 ) ;
V_12 = F_1 ( V_2 , 0x3205 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_1 ( V_2 , 0x3328 , 0x80 ) ;
}
static unsigned long F_19 ( struct V_1 * V_2 )
{
return V_29 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_30 , 2700000 ) ;
return 0 ;
}
