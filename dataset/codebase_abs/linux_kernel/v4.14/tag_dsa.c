static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( V_2 -> V_8 == F_3 ( V_9 ) ) {
if ( F_4 ( V_2 , 0 ) < 0 )
return NULL ;
V_7 = V_2 -> V_10 + 2 * V_11 ;
V_7 [ 0 ] = 0x60 | V_6 -> V_12 -> V_13 -> V_14 ;
V_7 [ 1 ] = V_6 -> V_12 -> V_14 << 3 ;
if ( V_7 [ 2 ] & 0x10 ) {
V_7 [ 1 ] |= 0x01 ;
V_7 [ 2 ] &= ~ 0x10 ;
}
} else {
if ( F_4 ( V_2 , V_15 ) < 0 )
return NULL ;
F_5 ( V_2 , V_15 ) ;
memmove ( V_2 -> V_10 , V_2 -> V_10 + V_15 , 2 * V_11 ) ;
V_7 = V_2 -> V_10 + 2 * V_11 ;
V_7 [ 0 ] = 0x40 | V_6 -> V_12 -> V_13 -> V_14 ;
V_7 [ 1 ] = V_6 -> V_12 -> V_14 << 3 ;
V_7 [ 2 ] = 0x00 ;
V_7 [ 3 ] = 0x00 ;
}
return V_2 ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_13 ;
T_1 * V_7 ;
int V_22 ;
int V_23 ;
if ( F_7 ( ! F_8 ( V_2 , V_15 ) ) )
return NULL ;
V_7 = V_2 -> V_10 - 2 ;
if ( ( V_7 [ 0 ] & 0xc0 ) != 0x00 && ( V_7 [ 0 ] & 0xc0 ) != 0xc0 )
return NULL ;
V_22 = V_7 [ 0 ] & 0x1f ;
V_23 = ( V_7 [ 1 ] >> 3 ) & 0x1f ;
if ( V_22 >= V_24 )
return NULL ;
V_13 = V_19 -> V_13 [ V_22 ] ;
if ( ! V_13 )
return NULL ;
if ( V_23 >= V_13 -> V_25 || ! V_13 -> V_26 [ V_23 ] . V_27 )
return NULL ;
if ( V_7 [ 0 ] & 0x20 ) {
T_1 V_28 [ 4 ] ;
V_28 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_28 [ 1 ] = V_9 & 0xff ;
V_28 [ 2 ] = V_7 [ 2 ] & ~ 0x10 ;
V_28 [ 3 ] = V_7 [ 3 ] ;
if ( V_7 [ 1 ] & 0x01 )
V_28 [ 2 ] |= 0x10 ;
if ( V_2 -> V_29 == V_30 ) {
T_2 V_31 = V_2 -> V_32 ;
V_31 = F_9 ( V_31 , F_10 ( V_28 + 2 , 2 , 0 ) ) ;
V_31 = F_11 ( V_31 , F_10 ( V_7 + 2 , 2 , 0 ) ) ;
V_2 -> V_32 = V_31 ;
}
memcpy ( V_7 , V_28 , V_15 ) ;
} else {
F_12 ( V_2 , V_15 ) ;
memmove ( V_2 -> V_10 - V_33 ,
V_2 -> V_10 - V_33 - V_15 ,
2 * V_11 ) ;
}
V_2 -> V_4 = V_13 -> V_26 [ V_23 ] . V_27 ;
return V_2 ;
}
