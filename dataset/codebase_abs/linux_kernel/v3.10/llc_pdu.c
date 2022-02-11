void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 ) -> V_4 |= V_3 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
T_1 V_3 ;
struct V_6 * V_7 ;
F_4 ( V_2 , & V_3 ) ;
V_7 = F_5 ( V_2 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
V_7 -> V_10 = ( V_7 -> V_10 & 0xFE ) | V_5 ;
break;
case V_11 :
V_7 -> V_12 |= ( V_7 -> V_12 & 0xEF ) | ( V_5 << 4 ) ;
break;
}
}
void F_6 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_3 ;
struct V_6 * V_7 ;
F_4 ( V_2 , & V_3 ) ;
V_7 = F_5 ( V_2 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
* V_13 = V_7 -> V_10 & V_14 ;
break;
case V_11 :
* V_13 = ( V_7 -> V_12 & V_15 ) >> 4 ;
break;
}
}
void F_7 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_12 |= V_18 ;
V_7 -> V_12 |= ( ( V_16 & 1 ) << 4 ) & V_15 ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_19 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_8 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= ( V_16 & V_21 ) ;
V_7 -> V_12 |= ( V_19 << 1 ) & 0xFE ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_22 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= V_16 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_23 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= V_16 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_24 ;
V_7 -> V_10 = V_16 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_12 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_12 |= V_25 ;
V_7 -> V_12 |= ( ( V_16 & 1 ) << 4 ) & V_15 ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_17 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_12 |= V_27 ;
V_7 -> V_12 |= ( ( V_26 & 1 ) << 4 ) & V_15 ;
}
void F_14 ( struct V_1 * V_2 , struct V_6 * V_28 ,
T_1 V_26 , T_1 V_29 , T_1 V_30 , T_1 V_31 )
{
struct V_32 * V_33 ;
T_1 V_34 = 0 ;
T_1 * V_35 ;
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_12 |= V_36 ;
V_7 -> V_12 |= ( ( V_26 & 1 ) << 4 ) & V_15 ;
V_33 = (struct V_32 * ) & V_7 -> V_10 ;
V_35 = ( T_1 * ) & V_28 -> V_12 ;
F_15 ( V_33 , V_35 ) ;
F_16 ( V_33 , V_29 ) ;
F_17 ( V_33 , V_30 ) ;
V_34 = F_18 ( V_28 ) ;
F_19 ( V_33 , V_34 ) ;
F_20 ( V_33 , V_31 ) ;
F_21 ( V_33 , V_31 ) ;
F_22 ( V_33 , V_31 ) ;
F_23 ( V_33 , V_31 ) ;
F_24 ( V_33 , V_31 ) ;
F_25 ( V_2 , sizeof( struct V_32 ) ) ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_37 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= V_26 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_38 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= V_26 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_20 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
V_7 -> V_12 = V_9 ;
V_7 -> V_12 |= V_39 ;
V_7 -> V_10 = 0 ;
V_7 -> V_10 |= V_26 & V_14 ;
V_7 -> V_12 &= 0x0F ;
V_7 -> V_10 |= ( V_20 << 1 ) & 0xFE ;
}
void F_29 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_17 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_12 |= V_40 ;
V_7 -> V_12 |= ( ( V_26 & 1 ) << 4 ) & V_15 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * type )
{
struct V_17 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_12 & 1 ) {
if ( ( V_7 -> V_12 & V_11 ) == V_11 )
* type = V_11 ;
else
* type = V_9 ;
} else
* type = V_8 ;
}
static T_1 F_18 ( struct V_6 * V_7 )
{
T_1 V_3 ;
T_1 V_13 = 0 ;
if ( V_7 -> V_12 & 1 ) {
if ( ( V_7 -> V_12 & V_11 ) == V_11 )
V_3 = V_11 ;
else
V_3 = V_9 ;
} else
V_3 = V_8 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
V_13 = V_7 -> V_10 & V_14 ;
break;
case V_11 :
V_13 = ( V_7 -> V_12 & V_15 ) >> 4 ;
break;
}
return V_13 ;
}
