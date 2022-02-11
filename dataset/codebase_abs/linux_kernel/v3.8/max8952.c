static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 , V_3 ) ;
if ( V_4 > 0 )
V_4 &= 0xff ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_6 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) != 0 )
return - V_10 ;
return ( V_2 -> V_11 -> V_12 [ V_9 ] * 10 + 770 ) * 1000 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
T_1 V_13 = 0 ;
if ( V_2 -> V_14 )
V_13 += 1 ;
if ( V_2 -> V_15 )
V_13 += 2 ;
return V_13 ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( ! F_10 ( V_2 -> V_11 -> V_16 ) ||
! F_10 ( V_2 -> V_11 -> V_17 ) ) {
return - V_18 ;
}
V_2 -> V_14 = V_9 & 0x1 ;
V_2 -> V_15 = ( V_9 >> 1 ) & 0x1 ;
F_11 ( V_2 -> V_11 -> V_16 , V_2 -> V_14 ) ;
F_11 ( V_2 -> V_11 -> V_17 , V_2 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_5 ,
const struct V_20 * V_21 )
{
struct V_22 * V_23 = F_13 ( V_5 -> V_24 . V_25 ) ;
struct V_26 * V_11 = V_5 -> V_24 . V_27 ;
struct V_28 V_29 = { } ;
struct V_1 * V_2 ;
int V_4 = 0 , V_30 = 0 ;
if ( ! V_11 ) {
F_14 ( & V_5 -> V_24 , L_1 ) ;
return - V_10 ;
}
if ( ! F_15 ( V_23 , V_31 ) )
return - V_32 ;
V_2 = F_16 ( & V_5 -> V_24 , sizeof( struct V_1 ) ,
V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_24 = & V_5 -> V_24 ;
V_2 -> V_11 = V_11 ;
V_29 . V_24 = V_2 -> V_24 ;
V_29 . V_35 = & V_11 -> V_36 ;
V_29 . V_37 = V_2 ;
V_29 . V_38 = V_11 -> V_39 ;
if ( V_11 -> V_36 . V_40 . V_41 )
V_29 . V_42 |= V_43 ;
V_2 -> V_8 = F_17 ( & V_44 , & V_29 ) ;
if ( F_18 ( V_2 -> V_8 ) ) {
V_4 = F_19 ( V_2 -> V_8 ) ;
F_14 ( V_2 -> V_24 , L_2 , V_4 ) ;
return V_4 ;
}
V_2 -> V_14 = V_11 -> V_45 & 0x1 ;
V_2 -> V_15 = ( V_11 -> V_45 >> 1 ) & 0x1 ;
if ( F_10 ( V_11 -> V_16 ) &&
F_10 ( V_11 -> V_17 ) ) {
if ( ! F_20 ( V_11 -> V_16 , L_3 ) )
F_21 ( V_11 -> V_16 ,
( V_11 -> V_45 ) & 0x1 ) ;
else
V_30 = 1 ;
if ( ! F_20 ( V_11 -> V_17 , L_4 ) )
F_21 ( V_11 -> V_17 ,
( V_11 -> V_45 >> 1 ) & 0x1 ) ;
else {
if ( ! V_30 )
F_22 ( V_11 -> V_16 ) ;
V_30 = 2 ;
}
} else
V_30 = 3 ;
if ( V_30 ) {
F_23 ( V_2 -> V_24 , L_5
L_6 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_11 -> V_16 = - 1 ;
V_11 -> V_17 = - 1 ;
F_3 ( V_2 , V_46 , 0x60 ) ;
F_14 ( V_2 -> V_24 , L_7
L_8 ) ;
} else {
F_3 ( V_2 , V_46 , 0x0 ) ;
}
F_3 ( V_2 , V_47 ,
( F_1 ( V_2 ,
V_47 ) & 0xC0 ) |
( V_11 -> V_12 [ 0 ] & 0x3F ) ) ;
F_3 ( V_2 , V_48 ,
( F_1 ( V_2 ,
V_48 ) & 0xC0 ) |
( V_11 -> V_12 [ 1 ] & 0x3F ) ) ;
F_3 ( V_2 , V_49 ,
( F_1 ( V_2 ,
V_49 ) & 0xC0 ) |
( V_11 -> V_12 [ 2 ] & 0x3F ) ) ;
F_3 ( V_2 , V_50 ,
( F_1 ( V_2 ,
V_50 ) & 0xC0 ) |
( V_11 -> V_12 [ 3 ] & 0x3F ) ) ;
F_3 ( V_2 , V_51 ,
( F_1 ( V_2 , V_51 ) & 0x3F ) |
( ( V_11 -> V_52 & 0x3 ) << 6 ) ) ;
F_3 ( V_2 , V_53 ,
( F_1 ( V_2 , V_53 ) & 0x1F ) |
( ( V_11 -> V_54 & 0x7 ) << 5 ) ) ;
F_24 ( V_5 , V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_19 * V_5 )
{
struct V_1 * V_2 = F_26 ( V_5 ) ;
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_27 ( V_8 ) ;
F_22 ( V_11 -> V_16 ) ;
F_22 ( V_11 -> V_17 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_55 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_55 ) ;
}
