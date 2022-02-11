static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
T_2 V_7 , V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
if ( V_3 != 0 || V_4 >= 2048 ) {
* V_6 = ~ 0 ;
return V_15 ;
}
V_7 = V_4 & ~ 3ull ;
F_2 ( V_7 , V_13 -> V_16 + V_17 ) ;
V_7 = F_3 ( V_13 -> V_16 + V_17 ) ;
V_7 >>= 32 ;
switch ( V_4 & ~ 3 ) {
case 0x40 :
V_7 &= 0xffff00ff ;
V_7 |= 0x00007000 ;
break;
case 0x70 :
if ( ! ( V_7 & ( 0x1f << 25 ) ) )
V_7 |= ( 2u << 25 ) ;
break;
case 0xb0 :
V_7 &= 0xc00000ff ;
F_2 ( 0x70 , V_13 -> V_16 + V_17 ) ;
V_8 = F_3 ( V_13 -> V_16 + V_17 ) ;
V_8 >>= 32 ;
if ( ! ( V_8 & ( 0x1f << 25 ) ) )
V_7 |= 0x0003bc00 ;
else
V_7 |= 0x0001bc00 ;
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
V_7 = V_13 -> V_18 [ 0 ] ;
break;
case 0xcc :
V_7 = V_13 -> V_18 [ 1 ] ;
break;
case 0xd0 :
V_7 = V_13 -> V_18 [ 2 ] ;
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
return V_19 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_2 -> V_20 < V_10 -> V_21 . V_22 ||
V_2 -> V_20 > V_10 -> V_21 . V_23 )
return V_15 ;
if ( V_2 -> V_20 == V_10 -> V_21 . V_22 )
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return F_5 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_6 ( T_2 V_24 )
{
T_1 V_25 = 0 ;
switch ( V_24 ) {
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
static T_1 F_7 ( T_2 V_24 )
{
T_1 V_26 ;
switch ( V_24 ) {
case 0x1c :
V_26 = 0x0101 ;
break;
case 0x24 :
V_26 = 0x00010001 ;
break;
default:
V_26 = 0 ;
break;
}
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_27 , V_7 ;
T_2 V_24 = V_4 & ~ 3ull ;
T_1 V_28 = 0 ;
if ( V_3 != 0 || V_4 >= 2048 )
return V_15 ;
switch ( V_5 ) {
case 1 :
F_2 ( V_24 , V_13 -> V_16 + V_17 ) ;
V_7 = F_3 ( V_13 -> V_16 + V_17 ) ;
V_7 >>= 32 ;
V_28 = ~ ( 0xff << ( 8 * ( V_4 & 3 ) ) ) ;
V_7 &= V_28 ;
V_6 = ( V_6 & 0xff ) << ( 8 * ( V_4 & 3 ) ) ;
V_6 |= ( T_1 ) V_7 ;
break;
case 2 :
F_2 ( V_24 , V_13 -> V_16 + V_17 ) ;
V_7 = F_3 ( V_13 -> V_16 + V_17 ) ;
V_7 >>= 32 ;
V_28 = ~ ( 0xffff << ( 8 * ( V_4 & 3 ) ) ) ;
V_7 &= V_28 ;
V_6 = ( V_6 & 0xffff ) << ( 8 * ( V_4 & 3 ) ) ;
V_6 |= ( T_1 ) V_7 ;
break;
default:
break;
}
if ( V_28 ) {
T_1 V_25 = F_6 ( V_4 ) ;
if ( V_25 ) {
V_28 &= V_25 ;
V_6 &= ~ V_28 ;
}
}
V_6 |= F_7 ( V_24 ) ;
V_27 = ( ( ( T_2 ) V_6 ) << 32 ) | V_24 ;
F_2 ( V_27 , V_13 -> V_16 + V_29 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_2 -> V_20 < V_10 -> V_21 . V_22 ||
V_2 -> V_20 > V_10 -> V_21 . V_23 )
return V_15 ;
if ( V_2 -> V_20 == V_10 -> V_21 . V_22 )
return F_8 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return F_10 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_11 ( struct V_30 * V_31 , struct V_9 * V_10 ,
struct V_32 * V_33 )
{
struct V_12 * V_13 ;
T_3 V_34 ;
V_13 = F_12 ( V_31 , sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
return - V_36 ;
V_13 -> V_16 = F_13 ( V_31 , V_33 -> V_22 , 0x10000 ) ;
if ( ! V_13 -> V_16 )
return - V_36 ;
V_34 = V_33 -> V_22 + 0xf00000 ;
V_13 -> V_18 [ 0 ] = ( T_1 ) V_34 | 2 ;
V_13 -> V_18 [ 1 ] = ( T_1 ) ( V_33 -> V_23 - V_34 ) & ~ 3u ;
V_13 -> V_18 [ 2 ] = ( T_1 ) ( V_34 >> 32 ) ;
V_10 -> V_14 = V_13 ;
return 0 ;
}
static void F_14 ( struct V_30 * V_31 , int V_37 ,
struct V_32 * V_38 )
{
T_3 V_22 = V_38 -> V_22 , V_23 = V_38 -> V_23 ;
struct V_32 * V_39 ;
const char * V_40 ;
V_40 = F_15 ( V_35 , L_1 , V_37 ) ;
if ( ! V_40 )
return;
V_39 = F_16 ( V_22 , V_23 - V_22 + 1 , V_40 ) ;
if ( V_39 )
V_39 -> V_41 &= ~ V_42 ;
else
F_17 ( V_40 ) ;
F_18 ( V_31 , L_2 , V_38 ,
V_39 ? L_3 : L_4 ) ;
}
static void F_19 ( struct V_43 * V_44 ,
struct V_32 * V_33 )
{
int V_45 = F_20 ( V_44 -> V_30 -> V_46 ) ;
int V_47 ;
if ( V_45 == V_48 )
V_45 = 0 ;
V_47 = V_44 -> V_49 - V_50 ;
V_47 -= V_45 * V_51 ;
V_33 -> V_22 = V_52 | F_21 ( V_53 , V_45 ) |
F_21 ( V_54 , V_47 ) ;
V_33 -> V_41 = V_55 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_56 ;
struct V_57 * V_58 = F_23 ( V_31 ) ;
struct V_43 * V_44 = F_24 ( V_58 ) ;
struct V_32 * V_33 ;
int V_59 ;
V_33 = F_12 ( & V_58 -> V_31 , sizeof( * V_33 ) , V_35 ) ;
if ( ! V_33 )
return - V_36 ;
V_59 = F_25 ( V_31 , L_5 , V_44 -> V_49 , V_33 ) ;
if ( V_59 ) {
F_19 ( V_44 , V_33 ) ;
V_33 -> V_23 = V_33 -> V_22 + V_60 - 1 ;
F_14 ( V_31 , V_44 -> V_49 , V_33 ) ;
V_33 -> V_23 = V_33 -> V_22 + V_61 - 1 ;
F_14 ( V_31 , V_44 -> V_49 , & V_10 -> V_39 ) ;
}
return F_11 ( V_31 , V_10 , V_33 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_30 * V_31 = V_10 -> V_56 ;
struct V_62 * V_63 = F_27 ( V_31 ) ;
struct V_32 * V_33 ;
if ( ! V_31 -> V_64 )
return - V_65 ;
V_33 = F_28 ( V_63 , V_55 , 1 ) ;
if ( ! V_33 ) {
F_29 ( V_31 , L_6 ) ;
return - V_65 ;
}
return F_11 ( V_31 , V_10 , V_33 ) ;
}
static int F_30 ( struct V_62 * V_63 )
{
return F_31 ( V_63 , & V_66 ) ;
}
