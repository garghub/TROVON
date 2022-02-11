static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( V_2 -> V_8 == F_3 ( V_9 ) ) {
if ( F_4 ( V_2 , V_10 ) < 0 )
return NULL ;
F_5 ( V_2 , V_10 ) ;
memmove ( V_2 -> V_11 , V_2 -> V_11 + V_10 , 2 * V_12 ) ;
V_7 = V_2 -> V_11 + 2 * V_12 ;
V_7 [ 0 ] = ( V_13 >> 8 ) & 0xff ;
V_7 [ 1 ] = V_13 & 0xff ;
V_7 [ 2 ] = 0x00 ;
V_7 [ 3 ] = 0x00 ;
V_7 [ 4 ] = 0x60 | V_6 -> V_14 -> V_15 -> V_16 ;
V_7 [ 5 ] = V_6 -> V_14 -> V_16 << 3 ;
if ( V_7 [ 6 ] & 0x10 ) {
V_7 [ 5 ] |= 0x01 ;
V_7 [ 6 ] &= ~ 0x10 ;
}
} else {
if ( F_4 ( V_2 , V_17 ) < 0 )
return NULL ;
F_5 ( V_2 , V_17 ) ;
memmove ( V_2 -> V_11 , V_2 -> V_11 + V_17 , 2 * V_12 ) ;
V_7 = V_2 -> V_11 + 2 * V_12 ;
V_7 [ 0 ] = ( V_13 >> 8 ) & 0xff ;
V_7 [ 1 ] = V_13 & 0xff ;
V_7 [ 2 ] = 0x00 ;
V_7 [ 3 ] = 0x00 ;
V_7 [ 4 ] = 0x40 | V_6 -> V_14 -> V_15 -> V_16 ;
V_7 [ 5 ] = V_6 -> V_14 -> V_16 << 3 ;
V_7 [ 6 ] = 0x00 ;
V_7 [ 7 ] = 0x00 ;
}
return V_2 ;
}
static struct V_1 * F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_18 * V_19 ,
struct V_3 * V_20 )
{
struct V_21 * V_22 = V_4 -> V_23 ;
struct V_24 * V_15 ;
T_1 * V_7 ;
int V_25 ;
int V_26 ;
if ( F_7 ( ! F_8 ( V_2 , V_17 ) ) )
return NULL ;
V_7 = V_2 -> V_11 + 2 ;
if ( ( V_7 [ 0 ] & 0xc0 ) != 0x00 && ( V_7 [ 0 ] & 0xc0 ) != 0xc0 )
return NULL ;
V_25 = V_7 [ 0 ] & 0x1f ;
V_26 = ( V_7 [ 1 ] >> 3 ) & 0x1f ;
if ( V_25 >= V_27 )
return NULL ;
V_15 = V_22 -> V_15 [ V_25 ] ;
if ( ! V_15 )
return NULL ;
if ( V_26 >= V_15 -> V_28 || ! V_15 -> V_29 [ V_26 ] . V_30 )
return NULL ;
if ( V_7 [ 0 ] & 0x20 ) {
T_1 V_31 [ 4 ] ;
V_31 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_31 [ 1 ] = V_9 & 0xff ;
V_31 [ 2 ] = V_7 [ 2 ] & ~ 0x10 ;
V_31 [ 3 ] = V_7 [ 3 ] ;
if ( V_7 [ 1 ] & 0x01 )
V_31 [ 2 ] |= 0x10 ;
F_9 ( V_2 , V_10 ) ;
if ( V_2 -> V_32 == V_33 ) {
T_2 V_34 = V_2 -> V_35 ;
V_34 = F_10 ( V_34 , F_11 ( V_31 + 2 , 2 , 0 ) ) ;
V_34 = F_12 ( V_34 , F_11 ( V_7 + 2 , 2 , 0 ) ) ;
V_2 -> V_35 = V_34 ;
}
memcpy ( V_7 , V_31 , V_10 ) ;
memmove ( V_2 -> V_11 - V_36 ,
V_2 -> V_11 - V_36 - V_10 ,
2 * V_12 ) ;
} else {
F_9 ( V_2 , V_17 ) ;
memmove ( V_2 -> V_11 - V_36 ,
V_2 -> V_11 - V_36 - V_17 ,
2 * V_12 ) ;
}
V_2 -> V_4 = V_15 -> V_29 [ V_26 ] . V_30 ;
return V_2 ;
}
