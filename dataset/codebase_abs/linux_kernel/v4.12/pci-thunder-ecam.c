static void F_1 ( T_1 V_1 , int V_2 , int V_3 , T_1 * V_4 )
{
int V_5 = ( V_2 & 3 ) * 8 ;
F_2 ( L_1 , ( unsigned ) ( V_2 & ~ 3 ) , V_1 ) ;
V_1 >>= V_5 ;
if ( V_3 == 1 )
V_1 &= 0xff ;
else if ( V_3 == 2 )
V_1 &= 0xffff ;
* V_4 = V_1 ;
}
static int F_3 ( T_1 V_6 , int V_7 , struct V_8 * V_9 ,
unsigned int V_10 , int V_2 , int V_3 , T_1 * V_4 )
{
void T_2 * V_11 ;
T_1 V_1 ;
int V_12 = V_2 & 0xc ;
if ( V_12 == 0 ) {
F_1 ( V_6 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0x4 ) {
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_7 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
V_1 &= ~ 0xf ;
V_1 |= 2 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0x8 ) {
T_1 V_17 ;
T_1 V_18 ;
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_7 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_17 = F_4 ( V_11 + 0 ) ;
F_5 ( 0xffffffff , V_11 + 0 ) ;
V_18 = F_4 ( V_11 + 0 ) ;
F_5 ( V_17 , V_11 + 0 ) ;
V_1 = ~ V_18 & ~ 3 ;
V_1 |= 0xc ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xc ) {
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_7 + 4 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
return V_16 ;
}
static int F_6 ( struct V_8 * V_9 , unsigned int V_10 ,
int V_2 , int V_3 , T_1 * V_4 )
{
struct V_19 * V_20 = V_9 -> V_21 ;
int V_12 = V_2 & ~ 3 ;
void T_2 * V_11 ;
T_1 V_22 ;
T_1 V_1 ;
switch ( V_12 ) {
case 0xa8 :
case 0xbc :
case 0xd0 :
case 0xe4 :
break;
default:
return F_7 ( V_9 , V_10 , V_2 , V_3 , V_4 ) ;
}
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_12 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
V_22 = ( V_20 -> V_23 . V_24 >> 32 ) & ( 1 << 12 ) ;
V_1 |= V_22 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
static int F_8 ( struct V_8 * V_9 , unsigned int V_10 ,
int V_2 , int V_3 , T_1 * V_4 )
{
T_1 V_1 ;
T_1 V_25 ;
T_1 V_26 ;
void T_2 * V_11 ;
int V_27 ;
int V_12 = V_2 & ~ 3 ;
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , 0xc ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
V_27 = ( V_1 >> 16 ) & 0x7f ;
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , 8 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_26 = F_4 ( V_11 ) ;
if ( V_26 == 0xffffffff )
goto V_28;
if ( ( V_26 & 0xff ) >= 8 ) {
if ( V_27 )
goto V_28;
return F_6 ( V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
}
if ( V_27 == 0 &&
( ( V_2 >= 0x10 && V_2 < 0x2c ) ||
( V_2 >= 0x1a4 && V_2 < 0x1bc ) ) ) {
* V_4 = 0 ;
return V_13 ;
}
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , 0 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_25 = F_4 ( V_11 ) ;
if ( V_25 == 0xffffffff )
goto V_28;
F_2 ( L_2 ,
V_25 & 0xffff , V_25 >> 16 , V_26 ,
( unsigned ) V_2 , V_10 ) ;
if ( V_27 == 0 ) {
bool V_29 ;
bool V_30 = ( V_25 == 0xa01e177d ) ;
bool V_31 = ( V_25 == 0xa01f177d ) ;
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , 0x70 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
V_29 = ( V_1 & 0xff00 ) != 0 ;
if ( ! V_29 && V_12 == 0x70 ) {
V_1 |= 0xbc00 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xb0 ) {
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_12 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
if ( V_1 & 0xff00 )
F_9 ( L_3 , V_1 ) ;
V_1 |= 0xbc00 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xbc ) {
if ( V_30 )
V_1 = 0x40014 ;
else if ( V_31 )
V_1 = 0x30014 ;
else if ( V_29 )
V_1 = 0x20014 ;
else
V_1 = 0x10014 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 >= 0xc0 && V_12 < 0xd0 )
return F_3 ( 0x80ff0003 ,
0x10 , V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
if ( V_12 >= 0xd0 && V_12 < 0xe0 && V_29 )
return F_3 ( 0x80ff0043 ,
0x20 , V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
if ( V_12 >= 0xe0 && V_12 < 0xf0 && V_31 )
return F_3 ( 0x80ff0023 ,
0x18 , V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
if ( V_12 >= 0xe0 && V_12 < 0xf0 && V_30 )
return F_3 ( 0x80ff0493 ,
0x1a4 , V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
if ( V_12 >= 0xf0 && V_12 < 0x100 && V_30 )
return F_3 ( 0x80ff04d3 ,
0x1b4 , V_9 , V_10 , V_2 ,
V_3 , V_4 ) ;
} else if ( V_27 == 1 ) {
bool V_32 = V_10 == 0x08 ;
bool V_33 = V_10 == 0xa0 ;
bool V_34 = V_10 == 0xa8 ;
bool V_35 = V_10 == 0xb0 ;
bool V_36 = V_10 == 0x10 ;
if ( V_12 == 0x70 ) {
V_11 = V_9 -> V_14 -> V_15 ( V_9 , V_10 , V_12 ) ;
if ( ! V_11 ) {
* V_4 = ~ 0 ;
return V_16 ;
}
V_1 = F_4 ( V_11 ) ;
if ( V_1 & 0xff00 )
F_9 ( L_4 , V_1 ) ;
V_1 |= 0xbc00 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xbc ) {
if ( V_36 )
V_1 = 0x10014 ;
else
V_1 = 0x00014 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xc0 ) {
if ( V_32 || V_36 )
V_1 = 0x0101 ;
else if ( V_33 )
V_1 = 0x0202 ;
else if ( V_34 )
V_1 = 0x0303 ;
else if ( V_35 )
V_1 = 0x0404 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xc4 && V_36 ) {
V_1 = 0x80ff0564 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xc8 && V_36 ) {
V_1 = 0x00000002 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xcc && V_36 ) {
V_1 = 0xfffffffe ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xd0 && V_36 ) {
V_1 = 0x00008430 ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
if ( V_12 == 0xd4 && V_36 ) {
V_1 = 0x0000000f ;
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_13 ;
}
}
V_28:
return F_7 ( V_9 , V_10 , V_2 , V_3 , V_4 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
int V_2 , int V_3 , T_1 V_4 )
{
if ( ( V_2 >= 0x10 && V_2 < 0x2c ) ||
( V_2 >= 0x1a4 && V_2 < 0x1bc ) )
return V_13 ;
return F_11 ( V_9 , V_10 , V_2 , V_3 , V_4 ) ;
}
static int F_12 ( struct V_37 * V_38 )
{
return F_13 ( V_38 , & V_39 ) ;
}
