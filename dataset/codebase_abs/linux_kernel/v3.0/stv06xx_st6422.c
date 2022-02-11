static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
if ( V_1 -> V_4 != V_5 )
return - V_6 ;
F_2 ( L_1 ) ;
V_3 = F_3 ( sizeof *V_3 , V_7 ) ;
if ( ! V_3 )
return - V_8 ;
V_1 -> V_9 . V_10 . V_11 = V_12 ;
V_1 -> V_9 . V_10 . V_13 = F_4 ( V_12 ) ;
V_1 -> V_9 . V_10 . V_14 = V_3 -> V_14 ;
V_1 -> V_15 . V_14 = V_16 ;
V_1 -> V_15 . V_17 = F_4 ( V_16 ) ;
V_1 -> V_18 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_19 = 0 , V_20 ;
const T_1 V_21 [] [ 2 ] = {
{ V_22 , 0x00 } ,
{ 0x1436 , 0x00 } ,
{ 0x1432 , 0x03 } ,
{ 0x143a , 0xf9 } ,
{ 0x0509 , 0x38 } ,
{ 0x050a , 0x38 } ,
{ 0x050b , 0x38 } ,
{ 0x050c , 0x2a } ,
{ 0x050d , 0x01 } ,
{ 0x1431 , 0x00 } ,
{ 0x1433 , 0x34 } ,
{ 0x1438 , 0x18 } ,
{ 0x1439 , 0x00 } ,
{ 0x143b , 0x05 } ,
{ 0x143c , 0x00 } ,
{ 0x143e , 0x01 } ,
{ 0x143d , 0x00 } ,
{ 0x1442 , 0xe2 } ,
{ 0x1500 , 0xd0 } ,
{ 0x1500 , 0xd0 } ,
{ 0x1500 , 0x50 } ,
{ 0x1501 , 0xaf } ,
{ 0x1502 , 0xc2 } ,
{ 0x1503 , 0x45 } ,
{ 0x1505 , 0x02 } ,
{ 0x150e , 0x8e } ,
{ 0x150f , 0x37 } ,
{ 0x15c0 , 0x00 } ,
{ 0x15c3 , 0x08 } ,
{ 0x143f , 0x01 } ,
} ;
for ( V_20 = 0 ; V_20 < F_4 ( V_21 ) && ! V_19 ; V_20 ++ ) {
V_19 = F_6 ( V_1 , V_21 [ V_20 ] [ 0 ] ,
V_21 [ V_20 ] [ 1 ] ) ;
}
return V_19 ;
}
static void F_7 ( struct V_1 * V_1 )
{
V_1 -> V_23 = NULL ;
F_8 ( V_1 -> V_18 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_18 ;
return F_6 ( V_1 , 0x1432 ,
V_3 -> V_14 [ V_24 ] . V_25 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_18 ;
return F_6 ( V_1 , 0x143a ,
V_3 -> V_14 [ V_26 ] . V_25 | 0xf0 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_18 ;
T_2 V_27 ;
int V_19 ;
V_27 = V_3 -> V_14 [ V_28 ] . V_25 ;
V_19 = F_6 ( V_1 , 0x0509 , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_1 , 0x050a , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_1 , 0x050b , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_1 , 0x050c , 0x2a ) ;
if ( V_19 < 0 )
return V_19 ;
return F_6 ( V_1 , 0x050d , 0x01 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_18 ;
T_1 V_29 ;
int V_19 ;
V_29 = V_3 -> V_14 [ V_30 ] . V_25 ;
V_19 = F_6 ( V_1 , 0x143d , V_29 & 0xff ) ;
if ( V_19 < 0 )
return V_19 ;
return F_6 ( V_1 , 0x143e , V_29 >> 8 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_19 ;
struct V_10 * V_10 = & V_1 -> V_9 . V_10 ;
if ( V_10 -> V_11 [ V_1 -> V_9 . V_31 ] . V_32 )
V_19 = F_6 ( V_1 , 0x1505 , 0x0f ) ;
else
V_19 = F_6 ( V_1 , 0x1505 , 0x02 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_9 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_10 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_12 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_11 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_1 , 0x143f , 0x01 ) ;
return ( V_19 < 0 ) ? V_19 : 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
F_15 ( V_33 , L_2 ) ;
return 0 ;
}
static void F_16 ( struct V_9 * V_9 )
{
int V_19 ;
struct V_1 * V_1 = (struct V_1 * ) V_9 ;
V_19 = F_9 ( V_1 ) ;
if ( V_19 >= 0 )
V_19 = F_6 ( V_1 , 0x143f , 0x01 ) ;
V_9 -> V_34 = V_19 ;
}
static void F_17 ( struct V_9 * V_9 )
{
int V_19 ;
struct V_1 * V_1 = (struct V_1 * ) V_9 ;
V_19 = F_10 ( V_1 ) ;
if ( V_19 >= 0 )
V_19 = F_6 ( V_1 , 0x143f , 0x01 ) ;
V_9 -> V_34 = V_19 ;
}
static void F_18 ( struct V_9 * V_9 )
{
int V_19 ;
struct V_1 * V_1 = (struct V_1 * ) V_9 ;
V_19 = F_11 ( V_1 ) ;
if ( V_19 >= 0 )
V_19 = F_6 ( V_1 , 0x143f , 0x01 ) ;
V_9 -> V_34 = V_19 ;
}
static void F_19 ( struct V_9 * V_9 )
{
int V_19 ;
struct V_1 * V_1 = (struct V_1 * ) V_9 ;
V_19 = F_12 ( V_1 ) ;
if ( V_19 >= 0 )
V_19 = F_6 ( V_1 , 0x143f , 0x01 ) ;
V_9 -> V_34 = V_19 ;
}
