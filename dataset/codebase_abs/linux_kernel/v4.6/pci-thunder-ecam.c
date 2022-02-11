static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 12 ) | V_4 ) ;
}
static void F_2 ( T_3 V_14 , int V_4 , int V_15 , T_3 * V_16 )
{
int V_17 = ( V_4 & 3 ) * 8 ;
F_3 ( L_1 , ( unsigned ) ( V_4 & ~ 3 ) , V_14 ) ;
V_14 >>= V_17 ;
if ( V_15 == 1 )
V_14 &= 0xff ;
else if ( V_15 == 2 )
V_14 &= 0xffff ;
* V_16 = V_14 ;
}
static int F_4 ( T_3 V_18 , int V_19 , struct V_1 * V_2 ,
unsigned int V_3 , int V_4 , int V_15 , T_3 * V_16 )
{
void T_1 * V_20 ;
T_3 V_14 ;
int V_21 = V_4 & 0xc ;
if ( V_21 == 0 ) {
F_2 ( V_18 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0x4 ) {
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_19 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
V_14 &= ~ 0xf ;
V_14 |= 2 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0x8 ) {
T_3 V_26 ;
T_3 V_27 ;
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_19 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_26 = F_5 ( V_20 + 0 ) ;
F_6 ( 0xffffffff , V_20 + 0 ) ;
V_27 = F_5 ( V_20 + 0 ) ;
F_6 ( V_26 , V_20 + 0 ) ;
V_14 = ~ V_27 & ~ 3 ;
V_14 |= 0xc ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xc ) {
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_19 + 4 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_15 , T_3 * V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_21 = V_4 & ~ 3 ;
void T_1 * V_20 ;
T_3 V_28 ;
T_3 V_14 ;
switch ( V_21 ) {
case 0xa8 :
case 0xbc :
case 0xd0 :
case 0xe4 :
break;
default:
return F_8 ( V_2 , V_3 , V_4 , V_15 , V_16 ) ;
}
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_21 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
V_28 = ( V_6 -> V_10 . V_29 . V_12 >> 32 ) & ( 1 << 12 ) ;
V_14 |= V_28 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_15 , T_3 * V_16 )
{
T_3 V_14 ;
T_3 V_30 ;
T_3 V_31 ;
void T_1 * V_20 ;
int V_32 ;
int V_21 = V_4 & ~ 3 ;
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , 0xc ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
V_32 = ( V_14 >> 16 ) & 0x7f ;
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , 8 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_31 = F_5 ( V_20 ) ;
if ( V_31 == 0xffffffff )
goto V_33;
if ( ( V_31 & 0xff ) >= 8 ) {
if ( V_32 )
goto V_33;
return F_7 ( V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
}
if ( V_32 == 0 &&
( ( V_4 >= 0x10 && V_4 < 0x2c ) ||
( V_4 >= 0x1a4 && V_4 < 0x1bc ) ) ) {
* V_16 = 0 ;
return V_22 ;
}
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , 0 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_30 = F_5 ( V_20 ) ;
if ( V_30 == 0xffffffff )
goto V_33;
F_3 ( L_2 ,
V_30 & 0xffff , V_30 >> 16 , V_31 ,
( unsigned ) V_4 , V_3 ) ;
if ( V_32 == 0 ) {
bool V_34 ;
bool V_35 = ( V_30 == 0xa01e177d ) ;
bool V_36 = ( V_30 == 0xa01f177d ) ;
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , 0x70 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
V_34 = ( V_14 & 0xff00 ) != 0 ;
if ( ! V_34 && V_21 == 0x70 ) {
V_14 |= 0xbc00 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xb0 ) {
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_21 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
if ( V_14 & 0xff00 )
F_10 ( L_3 , V_14 ) ;
V_14 |= 0xbc00 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xbc ) {
if ( V_35 )
V_14 = 0x40014 ;
else if ( V_36 )
V_14 = 0x30014 ;
else if ( V_34 )
V_14 = 0x20014 ;
else
V_14 = 0x10014 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 >= 0xc0 && V_21 < 0xd0 )
return F_4 ( 0x80ff0003 ,
0x10 , V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
if ( V_21 >= 0xd0 && V_21 < 0xe0 && V_34 )
return F_4 ( 0x80ff0043 ,
0x20 , V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
if ( V_21 >= 0xe0 && V_21 < 0xf0 && V_36 )
return F_4 ( 0x80ff0023 ,
0x18 , V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
if ( V_21 >= 0xe0 && V_21 < 0xf0 && V_35 )
return F_4 ( 0x80ff0493 ,
0x1a4 , V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
if ( V_21 >= 0xf0 && V_21 < 0x100 && V_35 )
return F_4 ( 0x80ff04d3 ,
0x1b4 , V_2 , V_3 , V_4 ,
V_15 , V_16 ) ;
} else if ( V_32 == 1 ) {
bool V_37 = V_3 == 0x08 ;
bool V_38 = V_3 == 0xa0 ;
bool V_39 = V_3 == 0xa8 ;
bool V_40 = V_3 == 0xb0 ;
bool V_41 = V_3 == 0x10 ;
if ( V_21 == 0x70 ) {
V_20 = V_2 -> V_23 -> V_24 ( V_2 , V_3 , V_21 ) ;
if ( ! V_20 ) {
* V_16 = ~ 0 ;
return V_25 ;
}
V_14 = F_5 ( V_20 ) ;
if ( V_14 & 0xff00 )
F_10 ( L_4 , V_14 ) ;
V_14 |= 0xbc00 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xbc ) {
if ( V_41 )
V_14 = 0x10014 ;
else
V_14 = 0x00014 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xc0 ) {
if ( V_37 || V_41 )
V_14 = 0x0101 ;
else if ( V_38 )
V_14 = 0x0202 ;
else if ( V_39 )
V_14 = 0x0303 ;
else if ( V_40 )
V_14 = 0x0404 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xc4 && V_41 ) {
V_14 = 0x80ff0564 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xc8 && V_41 ) {
V_14 = 0x00000002 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xcc && V_41 ) {
V_14 = 0xfffffffe ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xd0 && V_41 ) {
V_14 = 0x00008430 ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
if ( V_21 == 0xd4 && V_41 ) {
V_14 = 0x0000000f ;
F_2 ( V_14 , V_4 , V_15 , V_16 ) ;
return V_22 ;
}
}
V_33:
return F_8 ( V_2 , V_3 , V_4 , V_15 , V_16 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_15 , T_3 V_16 )
{
if ( ( V_4 >= 0x10 && V_4 < 0x2c ) ||
( V_4 >= 0x1a4 && V_4 < 0x1bc ) )
return V_22 ;
return F_12 ( V_2 , V_3 , V_4 , V_15 , V_16 ) ;
}
static int F_13 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = & V_43 -> V_45 ;
const struct V_46 * V_47 ;
struct V_5 * V_6 = F_14 ( V_45 , sizeof( * V_6 ) , V_48 ) ;
if ( ! V_6 )
return - V_49 ;
V_47 = F_15 ( V_50 , V_45 -> V_51 ) ;
V_6 -> V_10 . V_23 = (struct V_52 * ) V_47 -> V_53 ;
return F_16 ( V_43 , V_6 ) ;
}
