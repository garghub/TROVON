static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
T_3 V_5 ;
T_4 V_6 ;
const T_5 V_7 = V_2 -> V_8 - V_9 ;
static const T_5 V_10 [] = { 0x3f , 0x3c , 0x1b , 0x12 , 0x0a } ;
F_3 ( V_4 , 0x40 , & V_5 ) ;
F_4 ( V_4 , 0x44 , & V_6 ) ;
V_5 |= 0x4000 ;
V_5 &= V_2 -> V_11 ? 0xc006 : 0xc060 ;
if ( V_2 -> V_12 == V_13 )
V_5 |= 0x0004 << ( V_2 -> V_11 * 4 ) ;
if ( F_5 ( V_2 , V_7 ) )
V_5 |= 0x0002 << ( V_2 -> V_11 * 4 ) ;
V_6 &= V_2 -> V_11 ? 0x00003f00 : 0x000fc000 ;
V_6 |= V_10 [ V_7 ] << ( V_2 -> V_11 * 6 + 8 ) ;
F_6 ( V_4 , 0x40 , V_5 ) ;
F_7 ( V_4 , 0x44 , V_6 ) ;
}
static void F_8 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
int V_14 = 3 << ( V_2 -> V_11 * 4 ) ;
int V_15 = 1 << V_2 -> V_11 ;
int V_16 = 0 ;
T_5 V_17 , V_18 ;
const T_5 V_19 = V_2 -> V_20 ;
F_9 ( V_4 , 0x48 , & V_17 ) ;
F_9 ( V_4 , 0x4a , & V_18 ) ;
if ( V_19 >= V_21 ) {
T_5 V_22 = V_19 - V_21 ;
V_16 = V_22 << ( V_2 -> V_11 * 4 ) ;
F_10 ( V_4 , 0x48 , V_17 | V_15 ) ;
V_18 &= ~ V_14 ;
F_10 ( V_4 , 0x4a , V_18 | V_16 ) ;
} else {
const T_5 V_23 [] = { 0 , 3 , 4 } ;
F_10 ( V_4 , 0x48 , V_17 & ~ V_15 ) ;
F_10 ( V_4 , 0x4a , V_18 & ~ V_14 ) ;
V_2 -> V_8 =
V_23 [ V_19 - V_24 ] + V_9 ;
F_1 ( V_1 , V_2 ) ;
}
}
static int F_11 ( struct V_3 * V_4 , const struct V_25 * V_26 )
{
if ( ( V_4 -> V_27 >> 8 ) != V_28 )
return - V_29 ;
return F_12 ( V_4 , & V_30 , NULL ) ;
}
static int T_6 F_13 ( void )
{
return F_14 ( & V_31 ) ;
}
static void T_7 F_15 ( void )
{
F_16 ( & V_31 ) ;
}
