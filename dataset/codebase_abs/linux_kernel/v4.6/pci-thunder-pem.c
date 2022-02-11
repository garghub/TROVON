static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 16 ) | V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_14 , T_3 * V_15 )
{
T_4 V_16 ;
struct V_17 * V_18 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_18 = F_3 ( V_6 , struct V_17 , V_5 ) ;
if ( V_3 != 0 || V_4 >= 2048 ) {
* V_15 = ~ 0 ;
return V_19 ;
}
V_16 = V_4 & ~ 3ull ;
F_4 ( V_16 , V_18 -> V_20 + V_21 ) ;
V_16 = F_5 ( V_18 -> V_20 + V_21 ) ;
V_16 >>= 32 ;
switch ( V_4 & ~ 3 ) {
case 0x40 :
V_16 &= 0xffff00ff ;
V_16 |= 0x00007000 ;
break;
case 0x70 :
V_16 |= ( 2u << 25 ) ;
break;
case 0xb0 :
V_16 &= 0xc00000ff ;
V_16 |= 0x0003bc00 ;
break;
case 0xb4 :
V_16 = 0x00000000 ;
break;
case 0xb8 :
V_16 = 0x000f0000 ;
break;
case 0xbc :
V_16 = 0x00010014 ;
break;
case 0xc0 :
V_16 = 0x00000000 ;
break;
case 0xc4 :
V_16 = 0x80ff0003 ;
break;
case 0xc8 :
V_16 = V_18 -> V_22 [ 0 ] ;
break;
case 0xcc :
V_16 = V_18 -> V_22 [ 1 ] ;
break;
case 0xd0 :
V_16 = V_18 -> V_22 [ 2 ] ;
break;
default:
break;
}
V_16 >>= ( 8 * ( V_4 & 3 ) ) ;
switch ( V_14 ) {
case 1 :
V_16 &= 0xff ;
break;
case 2 :
V_16 &= 0xffff ;
break;
default:
break;
}
* V_15 = V_16 ;
return V_23 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_14 , T_3 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_9 < V_6 -> V_10 . V_11 -> V_12 ||
V_2 -> V_9 > V_6 -> V_10 . V_11 -> V_24 )
return V_19 ;
if ( V_2 -> V_9 == V_6 -> V_10 . V_11 -> V_12 )
return F_2 ( V_2 , V_3 , V_4 , V_14 , V_15 ) ;
return F_7 ( V_2 , V_3 , V_4 , V_14 , V_15 ) ;
}
static T_3 F_8 ( int V_4 )
{
T_3 V_25 = 0 ;
switch ( V_4 & ~ 3 ) {
case 0x04 :
case 0x1c :
V_25 = 0xff000000 ;
break;
case 0x44 :
V_25 = 0xfffffe00 ;
break;
case 0x78 :
case 0x80 :
case 0x88 :
case 0x90 :
case 0xa0 :
V_25 = 0xffff0000 ;
break;
case 0x104 :
case 0x110 :
case 0x130 :
case 0x160 :
V_25 = 0xffffffff ;
break;
default:
break;
}
return V_25 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_14 , T_3 V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
T_4 V_26 , V_16 ;
T_3 V_27 = 0 ;
V_18 = F_3 ( V_6 , struct V_17 , V_5 ) ;
if ( V_3 != 0 || V_4 >= 2048 )
return V_19 ;
switch ( V_14 ) {
case 1 :
V_16 = V_4 & ~ 3ull ;
F_4 ( V_16 , V_18 -> V_20 + V_21 ) ;
V_16 = F_5 ( V_18 -> V_20 + V_21 ) ;
V_16 >>= 32 ;
V_27 = ~ ( 0xff << ( 8 * ( V_4 & 3 ) ) ) ;
V_16 &= V_27 ;
V_15 = ( V_15 & 0xff ) << ( 8 * ( V_4 & 3 ) ) ;
V_15 |= ( T_3 ) V_16 ;
break;
case 2 :
V_16 = V_4 & ~ 3ull ;
F_4 ( V_16 , V_18 -> V_20 + V_21 ) ;
V_16 = F_5 ( V_18 -> V_20 + V_21 ) ;
V_16 >>= 32 ;
V_27 = ~ ( 0xffff << ( 8 * ( V_4 & 3 ) ) ) ;
V_16 &= V_27 ;
V_15 = ( V_15 & 0xffff ) << ( 8 * ( V_4 & 3 ) ) ;
V_15 |= ( T_3 ) V_16 ;
break;
default:
break;
}
if ( V_27 ) {
T_3 V_25 = F_8 ( V_4 ) ;
if ( V_25 ) {
V_27 &= V_25 ;
V_15 &= ~ V_27 ;
}
}
V_26 = V_4 & ~ 3ull ;
V_26 |= ( ( ( T_4 ) V_15 ) << 32 ) ;
F_4 ( V_26 , V_18 -> V_20 + V_28 ) ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_14 , T_3 V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_9 < V_6 -> V_10 . V_11 -> V_12 ||
V_2 -> V_9 > V_6 -> V_10 . V_11 -> V_24 )
return V_19 ;
if ( V_2 -> V_9 == V_6 -> V_10 . V_11 -> V_12 )
return F_9 ( V_2 , V_3 , V_4 , V_14 , V_15 ) ;
return F_11 ( V_2 , V_3 , V_4 , V_14 , V_15 ) ;
}
static int F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_30 -> V_32 ;
const struct V_33 * V_34 ;
T_2 V_35 ;
struct V_36 * V_37 ;
struct V_17 * V_18 ;
V_18 = F_13 ( V_32 , sizeof( * V_18 ) , V_38 ) ;
if ( ! V_18 )
return - V_39 ;
V_34 = F_14 ( V_40 , V_32 -> V_41 ) ;
V_18 -> V_5 . V_10 . V_42 = (struct V_43 * ) V_34 -> V_44 ;
V_37 = F_15 ( V_30 , V_45 , 1 ) ;
if ( ! V_37 ) {
F_16 ( V_32 , L_1 ) ;
return - V_46 ;
}
V_18 -> V_20 = F_17 ( V_32 , V_37 -> V_12 , 0x10000 ) ;
if ( ! V_18 -> V_20 )
return - V_39 ;
V_35 = V_37 -> V_12 + 0xf00000 ;
V_18 -> V_22 [ 0 ] = ( T_3 ) V_35 | 2 ;
V_18 -> V_22 [ 1 ] = ( T_3 ) ( V_37 -> V_24 - V_35 ) & ~ 3u ;
V_18 -> V_22 [ 2 ] = ( T_3 ) ( V_35 >> 32 ) ;
return F_18 ( V_30 , & V_18 -> V_5 ) ;
}
