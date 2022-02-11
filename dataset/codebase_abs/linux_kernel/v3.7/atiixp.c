static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
unsigned long V_5 ;
int V_6 = ( V_2 -> V_7 ^ 1 ) * 8 ;
T_3 V_8 ;
T_4 V_9 ;
const T_5 V_10 = V_2 -> V_11 - V_12 ;
F_3 ( & V_13 , V_5 ) ;
F_4 ( V_4 , V_14 , & V_9 ) ;
V_9 &= ~ ( 0x07 << ( V_2 -> V_7 * 4 ) ) ;
V_9 |= ( V_10 << ( V_2 -> V_7 * 4 ) ) ;
F_5 ( V_4 , V_14 , V_9 ) ;
F_6 ( V_4 , V_15 , & V_8 ) ;
V_8 &= ~ ( 0xff << V_6 ) ;
V_8 |= ( V_16 [ V_10 ] . V_17 << V_6 ) |
( V_16 [ V_10 ] . V_18 << ( V_6 + 4 ) ) ;
F_7 ( V_4 , V_15 , V_8 ) ;
F_8 ( & V_13 , V_5 ) ;
}
static void F_9 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
unsigned long V_5 ;
int V_6 = ( V_2 -> V_7 ^ 1 ) * 8 ;
T_3 V_19 ;
T_4 V_20 ;
T_4 V_21 = 0 ;
const T_5 V_22 = V_2 -> V_23 ;
F_3 ( & V_13 , V_5 ) ;
F_4 ( V_4 , V_24 , & V_21 ) ;
if ( V_22 >= V_25 ) {
F_4 ( V_4 , V_26 , & V_20 ) ;
V_20 &= ~ ( 0x07 << ( V_2 -> V_7 * 4 ) ) ;
V_20 |= ( ( V_22 & 0x07 ) << ( V_2 -> V_7 * 4 ) ) ;
F_5 ( V_4 , V_26 , V_20 ) ;
V_21 |= ( 1 << V_2 -> V_7 ) ;
} else if ( V_22 >= V_27 ) {
T_5 V_28 = V_22 & 0x03 ;
F_6 ( V_4 , V_29 , & V_19 ) ;
V_19 &= ~ ( 0xff << V_6 ) ;
V_19 |= ( V_30 [ V_28 ] . V_17 << V_6 ) |
( V_30 [ V_28 ] . V_18 << ( V_6 + 4 ) ) ;
F_7 ( V_4 , V_29 , V_19 ) ;
V_21 &= ~ ( 1 << V_2 -> V_7 ) ;
}
F_5 ( V_4 , V_24 , V_21 ) ;
F_8 ( & V_13 , V_5 ) ;
}
static T_5 F_10 ( T_1 * V_1 )
{
struct V_3 * V_31 = F_2 ( V_1 -> V_4 ) ;
T_5 V_32 = 0 , V_33 = V_1 -> V_34 ;
F_11 ( V_31 , V_26 + V_33 , & V_32 ) ;
if ( ( V_32 & 0x07 ) >= 0x04 || ( V_32 & 0x70 ) >= 0x40 )
return V_35 ;
else
return V_36 ;
}
static int T_6 F_12 ( struct V_3 * V_4 , const struct V_37 * V_38 )
{
return F_13 ( V_4 , & V_39 [ V_38 -> V_40 ] , NULL ) ;
}
static int T_7 F_14 ( void )
{
return F_15 ( & V_41 ) ;
}
static void T_8 F_16 ( void )
{
F_17 ( & V_41 ) ;
}
