static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
volatile void T_2 * V_9 ;
T_3 V_10 = 0 ;
T_1 V_11 , V_12 ;
if ( V_8 -> V_13 & V_14 ) {
if ( V_2 -> V_15 != V_8 -> V_16 )
return V_17 ;
if ( V_3 != 0 )
return V_17 ;
}
if ( V_8 -> V_13 & V_18 )
if ( V_2 -> V_15 != V_8 -> V_16 )
V_10 = 1 ;
V_11 = ( V_2 -> V_15 == V_8 -> V_16 ) ?
V_8 -> V_19 : V_2 -> V_15 ;
if ( V_8 -> V_13 & V_20 )
V_12 = ( ( V_4 & 0xf00 ) << 16 ) | ( V_4 & 0xfc ) ;
else
V_12 = V_4 & 0xfc ;
if ( V_8 -> V_13 & V_21 )
F_3 ( V_8 -> V_22 , ( 0x80000000 | ( V_11 << 16 ) |
( V_3 << 8 ) | V_12 | V_10 ) ) ;
else
F_4 ( V_8 -> V_22 , ( 0x80000000 | ( V_11 << 16 ) |
( V_3 << 8 ) | V_12 | V_10 ) ) ;
V_9 = V_8 -> V_9 + ( V_4 & 3 ) ;
switch ( V_5 ) {
case 1 :
* V_6 = F_5 ( V_9 ) ;
break;
case 2 :
* V_6 = F_6 ( V_9 ) ;
break;
default:
* V_6 = F_7 ( V_9 ) ;
break;
}
return V_23 ;
}
static int
F_8 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
volatile void T_2 * V_9 ;
T_3 V_10 = 0 ;
T_1 V_11 , V_12 ;
if ( V_8 -> V_13 & V_14 ) {
if ( V_2 -> V_15 != V_8 -> V_16 )
return V_17 ;
if ( V_3 != 0 )
return V_17 ;
}
if ( V_8 -> V_13 & V_18 )
if ( V_2 -> V_15 != V_8 -> V_16 )
V_10 = 1 ;
V_11 = ( V_2 -> V_15 == V_8 -> V_16 ) ?
V_8 -> V_19 : V_2 -> V_15 ;
if ( V_8 -> V_13 & V_20 )
V_12 = ( ( V_4 & 0xf00 ) << 16 ) | ( V_4 & 0xfc ) ;
else
V_12 = V_4 & 0xfc ;
if ( V_8 -> V_13 & V_21 )
F_3 ( V_8 -> V_22 , ( 0x80000000 | ( V_11 << 16 ) |
( V_3 << 8 ) | V_12 | V_10 ) ) ;
else
F_4 ( V_8 -> V_22 , ( 0x80000000 | ( V_11 << 16 ) |
( V_3 << 8 ) | V_12 | V_10 ) ) ;
if ( V_8 -> V_13 & V_24 )
if ( ( V_4 == V_25 ) &&
( V_2 -> V_15 == V_8 -> V_16 ) )
V_6 &= 0xffffff00 ;
if ( ( V_8 -> V_13 & V_26 ) &&
V_4 == V_27 ) {
V_6 = 0 ;
}
V_9 = V_8 -> V_9 + ( V_4 & 3 ) ;
switch ( V_5 ) {
case 1 :
F_9 ( V_9 , V_6 ) ;
break;
case 2 :
F_10 ( V_9 , V_6 ) ;
break;
default:
F_4 ( V_9 , V_6 ) ;
break;
}
return V_23 ;
}
void T_4
F_11 ( struct V_7 * V_8 ,
T_5 V_22 ,
T_5 V_9 , T_1 V_28 )
{
T_5 V_29 = V_22 & V_30 ;
void T_2 * V_31 ;
V_31 = F_12 ( V_29 , V_32 ) ;
V_8 -> V_22 = V_31 + ( V_22 & ~ V_30 ) ;
if ( ( V_9 & V_30 ) != V_29 )
V_31 = F_12 ( V_9 & V_30 , V_32 ) ;
V_8 -> V_9 = V_31 + ( V_9 & ~ V_30 ) ;
V_8 -> V_33 = & V_34 ;
V_8 -> V_13 = V_28 ;
}
