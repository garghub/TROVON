static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
T_2 V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
if ( V_3 != 0 || V_4 >= 2048 ) {
* V_6 = ~ 0 ;
return V_14 ;
}
V_7 = V_4 & ~ 3ull ;
F_2 ( V_7 , V_12 -> V_15 + V_16 ) ;
V_7 = F_3 ( V_12 -> V_15 + V_16 ) ;
V_7 >>= 32 ;
switch ( V_4 & ~ 3 ) {
case 0x40 :
V_7 &= 0xffff00ff ;
V_7 |= 0x00007000 ;
break;
case 0x70 :
V_7 |= ( 2u << 25 ) ;
break;
case 0xb0 :
V_7 &= 0xc00000ff ;
V_7 |= 0x0003bc00 ;
break;
case 0xb4 :
V_7 = 0x00000000 ;
break;
case 0xb8 :
V_7 = 0x000f0000 ;
break;
case 0xbc :
V_7 = 0x00010014 ;
break;
case 0xc0 :
V_7 = 0x00000000 ;
break;
case 0xc4 :
V_7 = 0x80ff0003 ;
break;
case 0xc8 :
V_7 = V_12 -> V_17 [ 0 ] ;
break;
case 0xcc :
V_7 = V_12 -> V_17 [ 1 ] ;
break;
case 0xd0 :
V_7 = V_12 -> V_17 [ 2 ] ;
break;
default:
break;
}
V_7 >>= ( 8 * ( V_4 & 3 ) ) ;
switch ( V_5 ) {
case 1 :
V_7 &= 0xff ;
break;
case 2 :
V_7 &= 0xffff ;
break;
default:
break;
}
* V_6 = V_7 ;
return V_18 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_2 -> V_19 < V_9 -> V_20 . V_21 ||
V_2 -> V_19 > V_9 -> V_20 . V_22 )
return V_14 ;
if ( V_2 -> V_19 == V_9 -> V_20 . V_21 )
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return F_5 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_6 ( T_2 V_23 )
{
T_1 V_24 = 0 ;
switch ( V_23 ) {
case 0x04 :
case 0x1c :
V_24 = 0xff000000 ;
break;
case 0x44 :
V_24 = 0xfffffe00 ;
break;
case 0x78 :
case 0x80 :
case 0x88 :
case 0x90 :
case 0xa0 :
V_24 = 0xffff0000 ;
break;
case 0x104 :
case 0x110 :
case 0x130 :
case 0x160 :
V_24 = 0xffffffff ;
break;
default:
break;
}
return V_24 ;
}
static T_1 F_7 ( T_2 V_23 )
{
T_1 V_25 ;
switch ( V_23 ) {
case 0x1c :
V_25 = 0x0101 ;
break;
case 0x24 :
V_25 = 0x00010001 ;
break;
default:
V_25 = 0 ;
break;
}
return V_25 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
T_2 V_26 , V_7 ;
T_2 V_23 = V_4 & ~ 3ull ;
T_1 V_27 = 0 ;
if ( V_3 != 0 || V_4 >= 2048 )
return V_14 ;
switch ( V_5 ) {
case 1 :
F_2 ( V_23 , V_12 -> V_15 + V_16 ) ;
V_7 = F_3 ( V_12 -> V_15 + V_16 ) ;
V_7 >>= 32 ;
V_27 = ~ ( 0xff << ( 8 * ( V_4 & 3 ) ) ) ;
V_7 &= V_27 ;
V_6 = ( V_6 & 0xff ) << ( 8 * ( V_4 & 3 ) ) ;
V_6 |= ( T_1 ) V_7 ;
break;
case 2 :
F_2 ( V_23 , V_12 -> V_15 + V_16 ) ;
V_7 = F_3 ( V_12 -> V_15 + V_16 ) ;
V_7 >>= 32 ;
V_27 = ~ ( 0xffff << ( 8 * ( V_4 & 3 ) ) ) ;
V_7 &= V_27 ;
V_6 = ( V_6 & 0xffff ) << ( 8 * ( V_4 & 3 ) ) ;
V_6 |= ( T_1 ) V_7 ;
break;
default:
break;
}
if ( V_27 ) {
T_1 V_24 = F_6 ( V_4 ) ;
if ( V_24 ) {
V_27 &= V_24 ;
V_6 &= ~ V_27 ;
}
}
V_6 |= F_7 ( V_23 ) ;
V_26 = ( ( ( T_2 ) V_6 ) << 32 ) | V_23 ;
F_2 ( V_26 , V_12 -> V_15 + V_28 ) ;
return V_18 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_2 -> V_19 < V_9 -> V_20 . V_21 ||
V_2 -> V_19 > V_9 -> V_20 . V_22 )
return V_14 ;
if ( V_2 -> V_19 == V_9 -> V_20 . V_21 )
return F_8 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return F_10 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_11 ( struct V_29 * V_30 , struct V_8 * V_9 ,
struct V_31 * V_32 )
{
struct V_11 * V_12 ;
T_3 V_33 ;
V_12 = F_12 ( V_30 , sizeof( * V_12 ) , V_34 ) ;
if ( ! V_12 )
return - V_35 ;
V_12 -> V_15 = F_13 ( V_30 , V_32 -> V_21 , 0x10000 ) ;
if ( ! V_12 -> V_15 )
return - V_35 ;
V_33 = V_32 -> V_21 + 0xf00000 ;
V_12 -> V_17 [ 0 ] = ( T_1 ) V_33 | 2 ;
V_12 -> V_17 [ 1 ] = ( T_1 ) ( V_32 -> V_22 - V_33 ) & ~ 3u ;
V_12 -> V_17 [ 2 ] = ( T_1 ) ( V_33 >> 32 ) ;
V_9 -> V_13 = V_12 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_29 * V_30 = V_9 -> V_36 ;
struct V_37 * V_38 = F_15 ( V_30 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_31 * V_32 ;
int V_41 ;
V_32 = F_12 ( & V_38 -> V_30 , sizeof( * V_32 ) , V_34 ) ;
if ( ! V_32 )
return - V_35 ;
V_41 = F_17 ( V_30 , L_1 , V_40 -> V_42 , V_32 ) ;
if ( V_41 ) {
F_18 ( V_30 , L_2 ) ;
return V_41 ;
}
return F_11 ( V_30 , V_9 , V_32 ) ;
}
static int F_19 ( struct V_8 * V_9 )
{
struct V_29 * V_30 = V_9 -> V_36 ;
struct V_43 * V_44 = F_20 ( V_30 ) ;
struct V_31 * V_32 ;
if ( ! V_30 -> V_45 )
return - V_46 ;
V_32 = F_21 ( V_44 , V_47 , 1 ) ;
if ( ! V_32 ) {
F_18 ( V_30 , L_3 ) ;
return - V_46 ;
}
return F_11 ( V_30 , V_9 , V_32 ) ;
}
static int F_22 ( struct V_43 * V_44 )
{
return F_23 ( V_44 , & V_48 ) ;
}
