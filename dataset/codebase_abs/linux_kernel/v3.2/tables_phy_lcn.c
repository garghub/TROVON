T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 type , V_4 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
switch ( type ) {
case V_6 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_8 ) & 0xFF ;
break;
case V_9 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_8 ) ;
break;
case V_10 :
F_3 ( V_2 , V_7 , V_3 ) ;
V_4 = F_4 ( V_2 , V_8 ) ;
V_4 |= ( F_4 ( V_2 , V_11 ) << 16 ) ;
break;
default:
F_2 ( 1 ) ;
V_4 = 0 ;
}
return V_4 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_12 , void * V_13 )
{
T_1 type ;
T_2 * V_14 = V_13 ;
unsigned int V_15 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
switch ( type ) {
case V_6 :
* V_14 = F_4 ( V_2 ,
V_8 ) & 0xFF ;
V_14 ++ ;
break;
case V_9 :
* ( ( V_16 * ) V_14 ) = F_4 ( V_2 ,
V_8 ) ;
V_14 += 2 ;
break;
case V_10 :
* ( ( T_1 * ) V_14 ) = F_4 ( V_2 ,
V_8 ) ;
* ( ( T_1 * ) V_14 ) |= ( F_4 ( V_2 ,
V_11 ) << 16 ) ;
V_14 += 4 ;
break;
default:
F_2 ( 1 ) ;
}
}
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 type ;
type = V_3 & V_5 ;
V_3 &= 0xFFFF ;
switch ( type ) {
case V_6 :
F_2 ( V_4 & ~ 0xFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_9 :
F_2 ( V_4 & ~ 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_10 :
F_3 ( V_2 , V_7 , V_3 ) ;
F_3 ( V_2 , V_11 , V_4 >> 16 ) ;
F_3 ( V_2 , V_8 , V_4 & 0xFFFF ) ;
break;
default:
F_2 ( 1 ) ;
}
return;
}
void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_12 , const void * V_13 )
{
T_1 type , V_4 ;
const T_2 * V_14 = V_13 ;
unsigned int V_15 ;
type = V_3 & V_5 ;
V_3 &= ~ V_5 ;
F_2 ( V_3 > 0xFFFF ) ;
F_3 ( V_2 , V_7 , V_3 ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
switch ( type ) {
case V_6 :
V_4 = * V_14 ;
V_14 ++ ;
F_2 ( V_4 & ~ 0xFF ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_9 :
V_4 = * ( ( V_16 * ) V_14 ) ;
V_14 += 2 ;
F_2 ( V_4 & ~ 0xFFFF ) ;
F_3 ( V_2 , V_8 , V_4 ) ;
break;
case V_10 :
V_4 = * ( ( T_1 * ) V_14 ) ;
V_14 += 4 ;
F_3 ( V_2 , V_11 ,
V_4 >> 16 ) ;
F_3 ( V_2 , V_8 ,
V_4 & 0xFFFF ) ;
break;
default:
F_2 ( 1 ) ;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , F_10 ( 0x02 , 0 ) , V_17 ) ;
F_9 ( V_2 , F_10 ( 0x01 , 0 ) , V_18 ) ;
F_9 ( V_2 , F_11 ( 0x0b , 0 ) , V_19 ) ;
F_9 ( V_2 , F_11 ( 0x0c , 0 ) , V_20 ) ;
F_9 ( V_2 , F_11 ( 0x0d , 0 ) , V_21 ) ;
F_9 ( V_2 , F_10 ( 0x0e , 0 ) , V_22 ) ;
F_9 ( V_2 , F_10 ( 0x0f , 0 ) , V_23 ) ;
F_9 ( V_2 , F_10 ( 0x10 , 0 ) , V_24 ) ;
F_9 ( V_2 , F_10 ( 0x11 , 0 ) , V_25 ) ;
F_9 ( V_2 , F_11 ( 0x12 , 0 ) , V_26 ) ;
F_9 ( V_2 , F_10 ( 0x14 , 0 ) , V_27 ) ;
F_9 ( V_2 , F_10 ( 0x17 , 0 ) , V_28 ) ;
F_9 ( V_2 , F_10 ( 0x00 , 0 ) , V_29 ) ;
F_9 ( V_2 , F_11 ( 0x18 , 0 ) , V_30 ) ;
}
void F_12 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
T_1 V_15 ;
T_1 V_33 ;
V_16 V_34 = 0x70 ;
if ( V_2 -> V_2 -> V_35 -> V_36 & V_37 )
V_34 = 0x10 ;
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
V_33 = ( ( V_34 << 24 ) |
( V_32 [ V_15 ] . V_39 << 16 ) |
( V_32 [ V_15 ] . V_40 << 8 ) |
V_32 [ V_15 ] . V_41 ) ;
F_6 ( V_2 , F_11 ( 0x7 , 0xc0 + V_15 ) , V_33 ) ;
V_33 = F_1 ( V_2 , F_11 ( 0x7 , 0x140 + V_15 ) ) ;
V_33 &= 0x000fffff ;
V_33 |= ( ( V_32 [ V_15 ] . V_42 << 28 ) |
( V_32 [ V_15 ] . V_43 << 20 ) ) ;
F_6 ( V_2 , F_11 ( 0x7 , 0x140 + V_15 ) , V_33 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_44 , V_45 ;
T_2 V_15 ;
for ( V_15 = 0 ; V_15 < 128 ; V_15 ++ ) {
V_44 = F_1 ( V_2 , F_11 ( 0x7 , 0x140 + V_15 ) ) ;
V_44 >>= 20 ;
V_45 = F_1 ( V_2 , F_11 ( 0x7 , 0xc0 + V_15 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
int V_15 ;
T_1 V_46 ;
for ( V_15 = 0 ; V_15 < 128 ; V_15 ++ ) {
V_46 = F_1 ( V_2 , F_11 ( 0x7 , 0x240 + V_15 ) ) ;
F_6 ( V_2 , F_11 ( 0x7 , 0x240 + V_15 ) , V_46 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_15 ;
for ( V_15 = 0 ; V_15 < 0x80 ; V_15 ++ )
F_6 ( V_2 , F_11 ( 0x18 , V_15 ) , 0x80000 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_2 -> V_35 ;
F_8 ( V_2 ) ;
if ( F_17 ( V_2 -> V_49 ) == V_50 ) {
if ( V_48 -> V_36 & V_37 )
F_12 ( V_2 ,
V_51 ) ;
else
F_18 ( V_2 -> V_49 ,
L_1 ) ;
}
if ( V_48 -> V_36 & V_37 &&
! ( V_48 -> V_52 & V_53 ) )
F_7 ( V_2 , F_10 ( 0xf , 0 ) ,
F_19 ( V_54 ) ,
V_54 ) ;
else
F_18 ( V_2 -> V_49 , L_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
}
