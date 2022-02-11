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
static const void * F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_7 ( V_23 ) ; V_22 ++ ) {
V_21 = & V_23 [ V_22 ] ;
if ( V_21 -> V_24 == V_19 -> V_25 )
return V_21 ;
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
struct V_3 * V_4 ;
int V_26 ;
F_9 ( V_2 , & V_19 -> V_2 ) ;
V_21 = F_6 ( V_2 , V_19 ) ;
if ( ! V_21 )
return - V_27 ;
V_2 -> V_28 = V_21 ;
V_2 -> V_29 = V_21 -> V_30 ;
V_26 = F_10 ( V_19 , V_2 -> V_29 ) ;
if ( V_26 )
return V_26 ;
V_2 -> V_10 = F_11 ( V_19 , 0 ) ;
V_26 = F_12 ( V_2 , 1 ) ;
if ( V_26 )
return V_26 ;
V_4 = & V_2 -> V_31 [ 0 ] ;
V_2 -> V_32 = V_4 ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = V_21 -> V_37 ;
V_4 -> V_17 = ( 1 << V_21 -> V_38 ) - 1 ;
V_4 -> V_39 = F_4 ;
V_4 -> V_40 = F_1 ;
F_3 ( 3 , V_2 -> V_10 + 248 ) ;
F_3 ( 0 , V_2 -> V_10 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x20 ) ;
F_3 ( 0 , V_2 -> V_10 + 0x40 ) ;
F_13 ( V_2 -> V_41 , L_1 ,
V_2 -> V_42 -> V_43 , V_2 -> V_29 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_15 ( V_2 ) ;
if ( V_19 ) {
if ( V_2 -> V_10 )
F_16 ( V_19 ) ;
}
}
static int T_1 F_17 ( struct V_18 * V_2 ,
const struct V_44 * V_45 )
{
return F_18 ( V_2 , & V_46 ) ;
}
static void T_2 F_19 ( struct V_18 * V_2 )
{
F_20 ( V_2 ) ;
}
