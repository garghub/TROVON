static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 = F_2 ( V_6 -> V_9 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 24 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x10 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 16 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x0c ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 8 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x08 ) ;
F_3 ( ( unsigned char ) ( ( V_7 [ 0 ] >> 0 ) & 0xff ) ,
V_2 -> V_10 + V_8 * 0x20 + 0x04 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned char V_11 , V_12 , V_13 , V_14 , V_15 ;
int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_16 ;
V_11 = F_5 ( V_2 -> V_10 + V_8 * 0x20 ) ;
V_12 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x04 ) ;
V_13 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x08 ) ;
V_14 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x0c ) ;
V_15 = F_5 ( V_2 -> V_10 + V_8 * 0x20 + 0x10 ) ;
V_16 = ( V_12 + ( V_13 * 256 ) + ( V_14 * 65536 ) ) ;
if ( V_15 > 0 )
V_16 = V_16 - V_4 -> V_17 ;
* V_7 = ( unsigned int ) V_16 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_19 * V_20 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_21 ;
V_2 -> V_22 = V_2 -> V_23 -> V_24 ;
V_21 = F_8 ( V_20 , V_2 -> V_22 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_10 = F_9 ( V_20 , 0 ) ;
V_21 = F_10 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_25 [ 0 ] ;
V_2 -> V_26 = V_4 ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 = 3 ;
V_4 -> V_17 = 0x00ffffff ;
V_4 -> V_31 = F_4 ;
V_4 -> V_32 = F_1 ;
F_3 ( 3 , V_2 -> V_10 + 248 ) ;
F_3 ( 0 , V_2 -> V_10 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x20 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x40 ) ;
F_11 ( V_2 -> V_33 , L_1 ,
V_2 -> V_23 -> V_24 , V_2 -> V_22 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_7 ( V_2 ) ;
if ( V_20 ) {
if ( V_2 -> V_10 )
F_13 ( V_20 ) ;
}
}
static int F_14 ( struct V_19 * V_2 ,
const struct V_34 * V_35 )
{
return F_15 ( V_2 , & V_36 ) ;
}
