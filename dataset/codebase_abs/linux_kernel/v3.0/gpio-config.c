int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned long V_5 ;
int V_6 ;
int V_7 ;
if ( ! V_4 )
return - V_8 ;
V_6 = V_1 - V_4 -> V_4 . V_9 ;
F_3 ( V_4 , V_5 ) ;
V_7 = F_4 ( V_4 , V_6 , V_2 ) ;
F_5 ( V_4 , V_5 ) ;
return V_7 ;
}
int F_6 ( unsigned int V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
int V_7 ;
for (; V_11 > 0 ; V_11 -- , V_10 ++ ) {
V_7 = F_1 ( V_10 , V_12 ) ;
if ( V_7 != 0 )
return V_7 ;
}
return 0 ;
}
int F_7 ( unsigned int V_10 , unsigned int V_11 ,
unsigned int V_12 , T_1 V_13 )
{
int V_7 ;
for (; V_11 > 0 ; V_11 -- , V_10 ++ ) {
F_8 ( V_10 , V_13 ) ;
V_7 = F_1 ( V_10 , V_12 ) ;
if ( V_7 != 0 )
return V_7 ;
}
return 0 ;
}
unsigned F_9 ( unsigned int V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned long V_5 ;
unsigned V_7 = 0 ;
int V_6 ;
if ( V_4 ) {
V_6 = V_1 - V_4 -> V_4 . V_9 ;
F_3 ( V_4 , V_5 ) ;
V_7 = F_10 ( V_4 , V_6 ) ;
F_5 ( V_4 , V_5 ) ;
}
return V_7 ;
}
int F_8 ( unsigned int V_1 , T_1 V_13 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned long V_5 ;
int V_6 , V_7 ;
if ( ! V_4 )
return - V_8 ;
V_6 = V_1 - V_4 -> V_4 . V_9 ;
F_3 ( V_4 , V_5 ) ;
V_7 = F_11 ( V_4 , V_6 , V_13 ) ;
F_5 ( V_4 , V_5 ) ;
return V_7 ;
}
T_1 F_12 ( unsigned int V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned long V_5 ;
int V_6 ;
T_2 V_14 = 0 ;
if ( V_4 ) {
V_6 = V_1 - V_4 -> V_4 . V_9 ;
F_3 ( V_4 , V_5 ) ;
V_14 = F_13 ( V_4 , V_6 ) ;
F_5 ( V_4 , V_5 ) ;
}
return ( V_15 T_1 ) V_14 ;
}
int F_14 ( struct V_3 * V_4 ,
unsigned int V_16 , unsigned int V_12 )
{
void T_3 * V_17 = V_4 -> V_9 ;
unsigned int V_18 = V_16 ;
T_2 V_19 ;
if ( F_15 ( V_12 ) ) {
V_12 &= 0xf ;
V_12 -= 1 ;
if ( V_12 > 1 )
return - V_8 ;
V_12 <<= V_18 ;
}
V_19 = F_16 ( V_17 ) ;
V_19 &= ~ ( 0x1 << V_18 ) ;
V_19 |= V_12 ;
F_17 ( V_19 , V_17 ) ;
return 0 ;
}
unsigned F_18 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
T_2 V_19 ;
V_19 = F_16 ( V_4 -> V_9 ) ;
V_19 >>= V_16 ;
V_19 &= 1 ;
V_19 ++ ;
return F_19 ( V_19 ) ;
}
int F_20 ( struct V_3 * V_4 ,
unsigned int V_16 , unsigned int V_12 )
{
void T_3 * V_17 = V_4 -> V_9 ;
unsigned int V_18 = V_16 * 2 ;
T_2 V_19 ;
if ( F_15 ( V_12 ) ) {
V_12 &= 0xf ;
if ( V_12 > 3 )
return - V_8 ;
V_12 <<= V_18 ;
}
V_19 = F_16 ( V_17 ) ;
V_19 &= ~ ( 0x3 << V_18 ) ;
V_19 |= V_12 ;
F_17 ( V_19 , V_17 ) ;
return 0 ;
}
unsigned int F_21 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
T_2 V_19 ;
V_19 = F_16 ( V_4 -> V_9 ) ;
V_19 >>= V_16 * 2 ;
V_19 &= 3 ;
return F_22 ( V_19 ) ;
}
int F_23 ( struct V_3 * V_4 ,
unsigned int V_16 , unsigned int V_12 )
{
void T_3 * V_17 = V_4 -> V_9 ;
unsigned int V_18 = ( V_16 & 7 ) * 4 ;
T_2 V_19 ;
if ( V_16 < 8 && V_4 -> V_4 . V_20 > 8 )
V_17 -= 4 ;
if ( F_15 ( V_12 ) ) {
V_12 &= 0xf ;
V_12 <<= V_18 ;
}
V_19 = F_16 ( V_17 ) ;
V_19 &= ~ ( 0xf << V_18 ) ;
V_19 |= V_12 ;
F_17 ( V_19 , V_17 ) ;
return 0 ;
}
unsigned F_24 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
void T_3 * V_17 = V_4 -> V_9 ;
unsigned int V_18 = ( V_16 & 7 ) * 4 ;
T_2 V_19 ;
if ( V_16 < 8 && V_4 -> V_4 . V_20 > 8 )
V_17 -= 4 ;
V_19 = F_16 ( V_17 ) ;
V_19 >>= V_18 ;
V_19 &= 0xf ;
return F_22 ( V_19 ) ;
}
int F_25 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_13 )
{
void T_3 * V_17 = V_4 -> V_9 + 0x08 ;
int V_18 = V_16 * 2 ;
T_2 V_14 ;
V_14 = F_16 ( V_17 ) ;
V_14 &= ~ ( 3 << V_18 ) ;
V_14 |= V_13 << V_18 ;
F_17 ( V_14 , V_17 ) ;
return 0 ;
}
T_1 F_26 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
void T_3 * V_17 = V_4 -> V_9 + 0x08 ;
int V_18 = V_16 * 2 ;
T_2 V_14 = F_16 ( V_17 ) ;
V_14 >>= V_18 ;
V_14 &= 0x3 ;
return ( V_15 T_1 ) V_14 ;
}
int F_27 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_13 )
{
switch ( V_13 ) {
case V_21 :
V_13 = 0x01 ;
break;
case V_22 :
V_13 = 0x00 ;
break;
case V_23 :
V_13 = 0x02 ;
break;
}
return F_25 ( V_4 , V_16 , V_13 ) ;
}
T_1 F_28 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
T_1 V_13 ;
V_13 = F_26 ( V_4 , V_16 ) ;
switch ( V_13 ) {
case 0x00 :
V_13 = V_22 ;
break;
case 0x01 :
case 0x03 :
V_13 = V_21 ;
break;
case 0x02 :
V_13 = V_23 ;
break;
}
return V_13 ;
}
static int F_29 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_13 ,
T_1 V_24 )
{
void T_3 * V_17 = V_4 -> V_9 + 0x08 ;
T_2 V_14 = F_16 ( V_17 ) ;
if ( V_13 == V_24 )
V_14 &= ~ ( 1 << V_16 ) ;
else if ( V_13 == V_21 )
V_14 |= ( 1 << V_16 ) ;
else
return - V_8 ;
F_17 ( V_14 , V_17 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_24 )
{
void T_3 * V_17 = V_4 -> V_9 + 0x08 ;
T_2 V_14 = F_16 ( V_17 ) ;
V_14 &= ( 1 << V_16 ) ;
return V_14 ? V_21 : V_24 ;
}
T_1 F_31 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
return F_30 ( V_4 , V_16 , V_22 ) ;
}
int F_32 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_13 )
{
return F_29 ( V_4 , V_16 , V_13 , V_22 ) ;
}
T_1 F_33 ( struct V_3 * V_4 ,
unsigned int V_16 )
{
return F_30 ( V_4 , V_16 , V_23 ) ;
}
int F_34 ( struct V_3 * V_4 ,
unsigned int V_16 , T_1 V_13 )
{
return F_29 ( V_4 , V_16 , V_13 , V_23 ) ;
}
T_4 F_35 ( unsigned int V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned int V_16 ;
void T_3 * V_17 ;
int V_18 ;
T_2 V_25 ;
if ( ! V_4 )
return - V_8 ;
V_16 = V_1 - V_4 -> V_4 . V_9 ;
V_18 = V_16 * 2 ;
V_17 = V_4 -> V_9 + 0x0C ;
V_25 = F_16 ( V_17 ) ;
V_25 = V_25 >> V_18 ;
V_25 &= 0x3 ;
return ( V_15 T_4 ) V_25 ;
}
int F_36 ( unsigned int V_1 , T_4 V_25 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned int V_16 ;
void T_3 * V_17 ;
int V_18 ;
T_2 V_26 ;
if ( ! V_4 )
return - V_8 ;
V_16 = V_1 - V_4 -> V_4 . V_9 ;
V_18 = V_16 * 2 ;
V_17 = V_4 -> V_9 + 0x0C ;
V_26 = F_16 ( V_17 ) ;
V_26 &= ~ ( 0x3 << V_18 ) ;
V_26 |= V_25 << V_18 ;
F_17 ( V_26 , V_17 ) ;
return 0 ;
}
