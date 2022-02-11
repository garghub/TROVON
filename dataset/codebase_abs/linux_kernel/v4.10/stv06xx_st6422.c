static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 -> V_4 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
int V_7 = - V_8 ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_7 = F_3 ( V_6 , V_2 -> V_11 ) ;
break;
case V_12 :
V_7 = F_4 ( V_6 , V_2 -> V_11 ) ;
break;
case V_13 :
V_7 = F_5 ( V_6 , V_2 -> V_11 ) ;
break;
case V_14 :
V_7 = F_6 ( V_6 , V_2 -> V_11 ) ;
break;
}
if ( V_7 >= 0 )
V_7 = F_7 ( V_6 , 0x143f , 0x01 ) ;
V_6 -> V_3 . V_15 = V_7 ;
return V_7 ;
}
static int F_8 ( struct V_6 * V_6 )
{
struct V_16 * V_17 = & V_6 -> V_3 . V_5 ;
F_9 ( V_17 , 4 ) ;
F_10 ( V_17 , & V_18 ,
V_10 , 0 , 31 , 1 , 3 ) ;
F_10 ( V_17 , & V_18 ,
V_12 , 0 , 15 , 1 , 11 ) ;
F_10 ( V_17 , & V_18 ,
V_14 , 0 , 1023 , 1 , 256 ) ;
F_10 ( V_17 , & V_18 ,
V_13 , 0 , 255 , 1 , 64 ) ;
return V_17 -> error ;
}
static int F_11 ( struct V_6 * V_6 )
{
if ( V_6 -> V_19 != V_20 )
return - V_21 ;
F_12 ( L_1 ) ;
V_6 -> V_3 . V_22 . V_23 = V_24 ;
V_6 -> V_3 . V_22 . V_25 = F_13 ( V_24 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_6 )
{
int V_7 = 0 , V_26 ;
const T_1 V_27 [] [ 2 ] = {
{ V_28 , 0x00 } ,
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
for ( V_26 = 0 ; V_26 < F_13 ( V_27 ) && ! V_7 ; V_26 ++ ) {
V_7 = F_7 ( V_6 , V_27 [ V_26 ] [ 0 ] ,
V_27 [ V_26 ] [ 1 ] ) ;
}
return V_7 ;
}
static int F_3 ( struct V_6 * V_6 , T_2 V_11 )
{
return F_7 ( V_6 , 0x1432 , V_11 ) ;
}
static int F_4 ( struct V_6 * V_6 , T_2 V_11 )
{
return F_7 ( V_6 , 0x143a , V_11 | 0xf0 ) ;
}
static int F_5 ( struct V_6 * V_6 , T_3 V_29 )
{
int V_7 ;
V_7 = F_7 ( V_6 , 0x0509 , V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_6 , 0x050a , V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_6 , 0x050b , V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_6 , 0x050c , 0x2a ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_6 , 0x050d , 0x01 ) ;
}
static int F_6 ( struct V_6 * V_6 , T_4 V_30 )
{
int V_7 ;
V_7 = F_7 ( V_6 , 0x143d , V_30 & 0xff ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_6 , 0x143e , V_30 >> 8 ) ;
}
static int F_15 ( struct V_6 * V_6 )
{
int V_7 ;
struct V_22 * V_22 = & V_6 -> V_3 . V_22 ;
if ( V_22 -> V_23 [ V_6 -> V_3 . V_31 ] . V_32 )
V_7 = F_7 ( V_6 , 0x1505 , 0x0f ) ;
else
V_7 = F_7 ( V_6 , 0x1505 , 0x02 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_6 , 0x143f , 0x01 ) ;
return ( V_7 < 0 ) ? V_7 : 0 ;
}
static int F_16 ( struct V_6 * V_6 )
{
struct V_3 * V_3 = (struct V_3 * ) V_6 ;
F_17 ( V_33 , L_2 ) ;
return 0 ;
}
