static inline int F_1 ( T_1 V_1 )
{
return V_1 == 0x00 || V_1 == 0xFF ;
}
static T_2 F_2 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
static const bool V_6 [ 8 ]
= { true , true , true , false , true , false , false , false } ;
static const T_1 V_7 [ 8 ] = { 0 , 1 , 2 , 2 , 3 , 3 , 3 , 3 } ;
T_2 V_8 ;
T_2 V_9 = ( T_2 ) - 1 ;
T_3 V_10 = V_3 -> V_11 ;
T_3 V_12 ;
T_3 V_13 ;
T_3 V_14 ;
T_1 V_1 ;
if ( V_5 <= 4 )
return 0 ;
V_5 -= 4 ;
for ( V_8 = 0 ; V_8 < V_5 ; ++ V_8 ) {
if ( ( V_4 [ V_8 ] & 0xFE ) != 0xE8 )
continue;
V_9 = V_8 - V_9 ;
if ( V_9 > 3 ) {
V_10 = 0 ;
} else {
V_10 = ( V_10 << ( V_9 - 1 ) ) & 7 ;
if ( V_10 != 0 ) {
V_1 = V_4 [ V_8 + 4 - V_7 [ V_10 ] ] ;
if ( ! V_6 [ V_10 ]
|| F_1 ( V_1 ) ) {
V_9 = V_8 ;
V_10 = ( V_10 << 1 ) | 1 ;
continue;
}
}
}
V_9 = V_8 ;
if ( F_1 ( V_4 [ V_8 + 4 ] ) ) {
V_12 = F_3 ( V_4 + V_8 + 1 ) ;
while ( true ) {
V_13 = V_12 - ( V_3 -> V_15 + ( T_3 ) V_8 + 5 ) ;
if ( V_10 == 0 )
break;
V_14 = V_7 [ V_10 ] * 8 ;
V_1 = ( T_1 ) ( V_13 >> ( 24 - V_14 ) ) ;
if ( ! F_1 ( V_1 ) )
break;
V_12 = V_13 ^ ( ( ( T_3 ) 1 << ( 32 - V_14 ) ) - 1 ) ;
}
V_13 &= 0x01FFFFFF ;
V_13 |= ( T_3 ) 0 - ( V_13 & 0x01000000 ) ;
F_4 ( V_13 , V_4 + V_8 + 1 ) ;
V_8 += 4 ;
} else {
V_10 = ( V_10 << 1 ) | 1 ;
}
}
V_9 = V_8 - V_9 ;
V_3 -> V_11 = V_9 > 3 ? 0 : V_10 << ( V_9 - 1 ) ;
return V_8 ;
}
static T_2 F_5 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
T_2 V_8 ;
T_3 V_16 ;
for ( V_8 = 0 ; V_8 + 4 <= V_5 ; V_8 += 4 ) {
V_16 = F_6 ( V_4 + V_8 ) ;
if ( ( V_16 & 0xFC000003 ) == 0x48000001 ) {
V_16 &= 0x03FFFFFC ;
V_16 -= V_3 -> V_15 + ( T_3 ) V_8 ;
V_16 &= 0x03FFFFFC ;
V_16 |= 0x48000001 ;
F_7 ( V_16 , V_4 + V_8 ) ;
}
}
return V_8 ;
}
static T_2 F_8 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
static const T_1 V_17 [ 32 ] = {
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
4 , 4 , 6 , 6 , 0 , 0 , 7 , 7 ,
4 , 4 , 0 , 0 , 4 , 4 , 0 , 0
} ;
T_2 V_8 ;
T_2 V_14 ;
T_3 V_18 ;
T_3 V_19 ;
T_3 V_20 ;
T_3 V_21 ;
T_3 V_22 ;
T_3 V_23 ;
T_4 V_16 ;
T_4 V_24 ;
for ( V_8 = 0 ; V_8 + 16 <= V_5 ; V_8 += 16 ) {
V_23 = V_17 [ V_4 [ V_8 ] & 0x1F ] ;
for ( V_18 = 0 , V_19 = 5 ; V_18 < 3 ; ++ V_18 , V_19 += 41 ) {
if ( ( ( V_23 >> V_18 ) & 1 ) == 0 )
continue;
V_20 = V_19 >> 3 ;
V_21 = V_19 & 7 ;
V_16 = 0 ;
for ( V_14 = 0 ; V_14 < 6 ; ++ V_14 )
V_16 |= ( T_4 ) ( V_4 [ V_8 + V_14 + V_20 ] )
<< ( 8 * V_14 ) ;
V_24 = V_16 >> V_21 ;
if ( ( ( V_24 >> 37 ) & 0x0F ) == 0x05
&& ( ( V_24 >> 9 ) & 0x07 ) == 0 ) {
V_22 = ( V_24 >> 13 ) & 0x0FFFFF ;
V_22 |= ( ( T_3 ) ( V_24 >> 36 ) & 1 ) << 20 ;
V_22 <<= 4 ;
V_22 -= V_3 -> V_15 + ( T_3 ) V_8 ;
V_22 >>= 4 ;
V_24 &= ~ ( ( T_4 ) 0x8FFFFF << 13 ) ;
V_24 |= ( T_4 ) ( V_22 & 0x0FFFFF ) << 13 ;
V_24 |= ( T_4 ) ( V_22 & 0x100000 )
<< ( 36 - 20 ) ;
V_16 &= ( 1 << V_21 ) - 1 ;
V_16 |= V_24 << V_21 ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ )
V_4 [ V_8 + V_14 + V_20 ]
= ( T_1 ) ( V_16 >> ( 8 * V_14 ) ) ;
}
}
}
return V_8 ;
}
static T_2 F_9 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
T_2 V_8 ;
T_3 V_22 ;
for ( V_8 = 0 ; V_8 + 4 <= V_5 ; V_8 += 4 ) {
if ( V_4 [ V_8 + 3 ] == 0xEB ) {
V_22 = ( T_3 ) V_4 [ V_8 ] | ( ( T_3 ) V_4 [ V_8 + 1 ] << 8 )
| ( ( T_3 ) V_4 [ V_8 + 2 ] << 16 ) ;
V_22 <<= 2 ;
V_22 -= V_3 -> V_15 + ( T_3 ) V_8 + 8 ;
V_22 >>= 2 ;
V_4 [ V_8 ] = ( T_1 ) V_22 ;
V_4 [ V_8 + 1 ] = ( T_1 ) ( V_22 >> 8 ) ;
V_4 [ V_8 + 2 ] = ( T_1 ) ( V_22 >> 16 ) ;
}
}
return V_8 ;
}
static T_2 F_10 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
T_2 V_8 ;
T_3 V_22 ;
for ( V_8 = 0 ; V_8 + 4 <= V_5 ; V_8 += 2 ) {
if ( ( V_4 [ V_8 + 1 ] & 0xF8 ) == 0xF0
&& ( V_4 [ V_8 + 3 ] & 0xF8 ) == 0xF8 ) {
V_22 = ( ( ( T_3 ) V_4 [ V_8 + 1 ] & 0x07 ) << 19 )
| ( ( T_3 ) V_4 [ V_8 ] << 11 )
| ( ( ( T_3 ) V_4 [ V_8 + 3 ] & 0x07 ) << 8 )
| ( T_3 ) V_4 [ V_8 + 2 ] ;
V_22 <<= 1 ;
V_22 -= V_3 -> V_15 + ( T_3 ) V_8 + 4 ;
V_22 >>= 1 ;
V_4 [ V_8 + 1 ] = ( T_1 ) ( 0xF0 | ( ( V_22 >> 19 ) & 0x07 ) ) ;
V_4 [ V_8 ] = ( T_1 ) ( V_22 >> 11 ) ;
V_4 [ V_8 + 3 ] = ( T_1 ) ( 0xF8 | ( ( V_22 >> 8 ) & 0x07 ) ) ;
V_4 [ V_8 + 2 ] = ( T_1 ) V_22 ;
V_8 += 2 ;
}
}
return V_8 ;
}
static T_2 F_11 ( struct V_2 * V_3 , T_1 * V_4 , T_2 V_5 )
{
T_2 V_8 ;
T_3 V_16 ;
for ( V_8 = 0 ; V_8 + 4 <= V_5 ; V_8 += 4 ) {
V_16 = F_6 ( V_4 + V_8 ) ;
if ( ( V_16 >> 22 ) == 0x100 || ( V_16 >> 22 ) == 0x1FF ) {
V_16 <<= 2 ;
V_16 -= V_3 -> V_15 + ( T_3 ) V_8 ;
V_16 >>= 2 ;
V_16 = ( ( T_3 ) 0x40000000 - ( V_16 & 0x400000 ) )
| 0x40000000 | ( V_16 & 0x3FFFFF ) ;
F_7 ( V_16 , V_4 + V_8 ) ;
}
}
return V_8 ;
}
static void F_12 ( struct V_2 * V_3 ,
T_1 * V_4 , T_2 * V_15 , T_2 V_5 )
{
T_2 V_25 ;
V_4 += * V_15 ;
V_5 -= * V_15 ;
switch ( V_3 -> type ) {
#ifdef F_13
case V_26 :
V_25 = F_2 ( V_3 , V_4 , V_5 ) ;
break;
#endif
#ifdef F_14
case V_27 :
V_25 = F_5 ( V_3 , V_4 , V_5 ) ;
break;
#endif
#ifdef F_15
case V_28 :
V_25 = F_8 ( V_3 , V_4 , V_5 ) ;
break;
#endif
#ifdef F_16
case V_29 :
V_25 = F_9 ( V_3 , V_4 , V_5 ) ;
break;
#endif
#ifdef F_17
case V_30 :
V_25 = F_10 ( V_3 , V_4 , V_5 ) ;
break;
#endif
#ifdef F_18
case V_31 :
V_25 = F_11 ( V_3 , V_4 , V_5 ) ;
break;
#endif
default:
V_25 = 0 ;
break;
}
* V_15 += V_25 ;
V_3 -> V_15 += V_25 ;
}
static void F_19 ( struct V_2 * V_3 , struct V_32 * V_1 )
{
T_2 V_33 ;
V_33 = F_20 ( T_2 , V_3 -> V_34 . V_25 , V_1 -> V_35 - V_1 -> V_36 ) ;
memcpy ( V_1 -> V_37 + V_1 -> V_36 , V_3 -> V_34 . V_4 , V_33 ) ;
V_1 -> V_36 += V_33 ;
V_3 -> V_34 . V_25 -= V_33 ;
V_3 -> V_34 . V_5 -= V_33 ;
memmove ( V_3 -> V_34 . V_4 , V_3 -> V_34 . V_4 + V_33 , V_3 -> V_34 . V_5 ) ;
}
T_5 enum V_38 F_21 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
struct V_32 * V_1 )
{
T_2 V_41 ;
if ( V_3 -> V_34 . V_25 > 0 ) {
F_19 ( V_3 , V_1 ) ;
if ( V_3 -> V_34 . V_25 > 0 )
return V_42 ;
if ( V_3 -> V_43 == V_44 )
return V_44 ;
}
if ( V_3 -> V_34 . V_5 < V_1 -> V_35 - V_1 -> V_36 ) {
V_41 = V_1 -> V_36 ;
memcpy ( V_1 -> V_37 + V_1 -> V_36 , V_3 -> V_34 . V_4 , V_3 -> V_34 . V_5 ) ;
V_1 -> V_36 += V_3 -> V_34 . V_5 ;
V_3 -> V_43 = F_22 ( V_40 , V_1 ) ;
if ( V_3 -> V_43 != V_44
&& ( V_3 -> V_43 != V_42 || V_3 -> V_45 ) )
return V_3 -> V_43 ;
F_12 ( V_3 , V_1 -> V_37 , & V_41 , V_1 -> V_36 ) ;
if ( V_3 -> V_43 == V_44 )
return V_44 ;
V_3 -> V_34 . V_5 = V_1 -> V_36 - V_41 ;
V_1 -> V_36 -= V_3 -> V_34 . V_5 ;
memcpy ( V_3 -> V_34 . V_4 , V_1 -> V_37 + V_1 -> V_36 , V_3 -> V_34 . V_5 ) ;
}
if ( V_3 -> V_34 . V_5 > 0 ) {
V_3 -> V_37 = V_1 -> V_37 ;
V_3 -> V_36 = V_1 -> V_36 ;
V_3 -> V_35 = V_1 -> V_35 ;
V_1 -> V_37 = V_3 -> V_34 . V_4 ;
V_1 -> V_36 = V_3 -> V_34 . V_5 ;
V_1 -> V_35 = sizeof( V_3 -> V_34 . V_4 ) ;
V_3 -> V_43 = F_22 ( V_40 , V_1 ) ;
V_3 -> V_34 . V_5 = V_1 -> V_36 ;
V_1 -> V_37 = V_3 -> V_37 ;
V_1 -> V_36 = V_3 -> V_36 ;
V_1 -> V_35 = V_3 -> V_35 ;
if ( V_3 -> V_43 != V_42 && V_3 -> V_43 != V_44 )
return V_3 -> V_43 ;
F_12 ( V_3 , V_3 -> V_34 . V_4 , & V_3 -> V_34 . V_25 , V_3 -> V_34 . V_5 ) ;
if ( V_3 -> V_43 == V_44 )
V_3 -> V_34 . V_25 = V_3 -> V_34 . V_5 ;
F_19 ( V_3 , V_1 ) ;
if ( V_3 -> V_34 . V_25 > 0 )
return V_42 ;
}
return V_3 -> V_43 ;
}
T_5 struct V_2 * F_23 ( bool V_45 )
{
struct V_2 * V_3 = F_24 ( sizeof( * V_3 ) , V_46 ) ;
if ( V_3 != NULL )
V_3 -> V_45 = V_45 ;
return V_3 ;
}
T_5 enum V_38 F_25 ( struct V_2 * V_3 , T_1 V_47 )
{
switch ( V_47 ) {
#ifdef F_13
case V_26 :
#endif
#ifdef F_14
case V_27 :
#endif
#ifdef F_15
case V_28 :
#endif
#ifdef F_16
case V_29 :
#endif
#ifdef F_17
case V_30 :
#endif
#ifdef F_18
case V_31 :
#endif
break;
default:
return V_48 ;
}
V_3 -> type = V_47 ;
V_3 -> V_43 = V_42 ;
V_3 -> V_15 = 0 ;
V_3 -> V_11 = 0 ;
V_3 -> V_34 . V_25 = 0 ;
V_3 -> V_34 . V_5 = 0 ;
return V_42 ;
}
