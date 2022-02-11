static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( V_2 -> V_8 == F_3 ( V_9 ) ) {
if ( F_4 ( V_2 , 0 ) < 0 )
goto V_10;
V_7 = V_2 -> V_11 + 2 * V_12 ;
V_7 [ 0 ] = 0x60 | V_6 -> V_13 -> V_14 -> V_15 ;
V_7 [ 1 ] = V_6 -> V_13 -> V_15 << 3 ;
if ( V_7 [ 2 ] & 0x10 ) {
V_7 [ 1 ] |= 0x01 ;
V_7 [ 2 ] &= ~ 0x10 ;
}
} else {
if ( F_4 ( V_2 , V_16 ) < 0 )
goto V_10;
F_5 ( V_2 , V_16 ) ;
memmove ( V_2 -> V_11 , V_2 -> V_11 + V_16 , 2 * V_12 ) ;
V_7 = V_2 -> V_11 + 2 * V_12 ;
V_7 [ 0 ] = 0x40 | V_6 -> V_13 -> V_14 -> V_15 ;
V_7 [ 1 ] = V_6 -> V_13 -> V_15 << 3 ;
V_7 [ 2 ] = 0x00 ;
V_7 [ 3 ] = 0x00 ;
}
return V_2 ;
V_10:
F_6 ( V_2 ) ;
return NULL ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_17 * V_18 ,
struct V_3 * V_19 )
{
struct V_20 * V_21 = V_4 -> V_22 ;
struct V_23 * V_14 ;
T_1 * V_7 ;
int V_24 ;
int V_25 ;
if ( F_8 ( ! F_9 ( V_2 , V_16 ) ) )
goto V_26;
V_7 = V_2 -> V_11 - 2 ;
if ( ( V_7 [ 0 ] & 0xc0 ) != 0x00 && ( V_7 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_26;
V_24 = V_7 [ 0 ] & 0x1f ;
V_25 = ( V_7 [ 1 ] >> 3 ) & 0x1f ;
if ( V_24 >= V_27 )
goto V_26;
V_14 = V_21 -> V_14 [ V_24 ] ;
if ( ! V_14 )
goto V_26;
if ( V_25 >= V_14 -> V_28 || ! V_14 -> V_29 [ V_25 ] . V_30 )
goto V_26;
if ( V_7 [ 0 ] & 0x20 ) {
T_1 V_31 [ 4 ] ;
V_31 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_31 [ 1 ] = V_9 & 0xff ;
V_31 [ 2 ] = V_7 [ 2 ] & ~ 0x10 ;
V_31 [ 3 ] = V_7 [ 3 ] ;
if ( V_7 [ 1 ] & 0x01 )
V_31 [ 2 ] |= 0x10 ;
if ( V_2 -> V_32 == V_33 ) {
T_2 V_34 = V_2 -> V_35 ;
V_34 = F_10 ( V_34 , F_11 ( V_31 + 2 , 2 , 0 ) ) ;
V_34 = F_12 ( V_34 , F_11 ( V_7 + 2 , 2 , 0 ) ) ;
V_2 -> V_35 = V_34 ;
}
memcpy ( V_7 , V_31 , V_16 ) ;
} else {
F_13 ( V_2 , V_16 ) ;
memmove ( V_2 -> V_11 - V_36 ,
V_2 -> V_11 - V_36 - V_16 ,
2 * V_12 ) ;
}
V_2 -> V_4 = V_14 -> V_29 [ V_25 ] . V_30 ;
return V_2 ;
V_26:
return NULL ;
}
