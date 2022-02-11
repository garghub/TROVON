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
return V_2 -> V_13 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( F_10 ( V_2 -> V_11 -> V_14 ) )
F_11 ( V_2 -> V_11 -> V_14 , 1 ) ;
V_2 -> V_13 = true ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( F_10 ( V_2 -> V_11 -> V_14 ) )
F_11 ( V_2 -> V_11 -> V_14 , 0 ) ;
else
return - V_15 ;
V_2 -> V_13 = false ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
T_1 V_16 = 0 ;
if ( V_2 -> V_17 )
V_16 += 1 ;
if ( V_2 -> V_18 )
V_16 += 2 ;
return V_16 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_9 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( ! F_10 ( V_2 -> V_11 -> V_19 ) ||
! F_10 ( V_2 -> V_11 -> V_20 ) ) {
return - V_15 ;
}
V_2 -> V_17 = V_9 & 0x1 ;
V_2 -> V_18 = ( V_9 >> 1 ) & 0x1 ;
F_11 ( V_2 -> V_11 -> V_19 , V_2 -> V_17 ) ;
F_11 ( V_2 -> V_11 -> V_20 , V_2 -> V_18 ) ;
return 0 ;
}
static int T_2 F_15 ( struct V_21 * V_5 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 = F_16 ( V_5 -> V_26 . V_27 ) ;
struct V_28 * V_11 = V_5 -> V_26 . V_29 ;
struct V_30 V_31 = { } ;
struct V_1 * V_2 ;
int V_4 = 0 , V_32 = 0 ;
if ( ! V_11 ) {
F_17 ( & V_5 -> V_26 , L_1 ) ;
return - V_10 ;
}
if ( ! F_18 ( V_25 , V_33 ) )
return - V_34 ;
V_2 = F_19 ( & V_5 -> V_26 , sizeof( struct V_1 ) ,
V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = & V_5 -> V_26 ;
V_2 -> V_11 = V_11 ;
V_31 . V_26 = V_2 -> V_26 ;
V_31 . V_37 = & V_11 -> V_38 ;
V_31 . V_39 = V_2 ;
V_2 -> V_8 = F_20 ( & V_40 , & V_31 ) ;
if ( F_21 ( V_2 -> V_8 ) ) {
V_4 = F_22 ( V_2 -> V_8 ) ;
F_17 ( V_2 -> V_26 , L_2 , V_4 ) ;
return V_4 ;
}
V_2 -> V_13 = ! ! ( V_11 -> V_38 . V_41 . V_42 ) ;
V_2 -> V_17 = V_11 -> V_43 & 0x1 ;
V_2 -> V_18 = ( V_11 -> V_43 >> 1 ) & 0x1 ;
if ( F_10 ( V_11 -> V_14 ) ) {
if ( ! F_23 ( V_11 -> V_14 , L_3 ) )
F_24 ( V_11 -> V_14 , V_2 -> V_13 ) ;
else
V_32 = 1 ;
} else
V_32 = 2 ;
if ( V_32 ) {
F_25 ( V_2 -> V_26 , L_4
L_5 ) ;
V_2 -> V_13 = 1 ;
V_11 -> V_14 = - 1 ;
}
V_32 = 0 ;
if ( F_10 ( V_11 -> V_19 ) &&
F_10 ( V_11 -> V_20 ) ) {
if ( ! F_23 ( V_11 -> V_19 , L_6 ) )
F_24 ( V_11 -> V_19 ,
( V_11 -> V_43 ) & 0x1 ) ;
else
V_32 = 1 ;
if ( ! F_23 ( V_11 -> V_20 , L_7 ) )
F_24 ( V_11 -> V_20 ,
( V_11 -> V_43 >> 1 ) & 0x1 ) ;
else {
if ( ! V_32 )
F_26 ( V_11 -> V_19 ) ;
V_32 = 2 ;
}
} else
V_32 = 3 ;
if ( V_32 ) {
F_27 ( V_2 -> V_26 , L_8
L_9 ) ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_11 -> V_19 = - 1 ;
V_11 -> V_20 = - 1 ;
F_3 ( V_2 , V_44 , 0x60 ) ;
F_17 ( V_2 -> V_26 , L_10
L_11 ) ;
} else {
F_3 ( V_2 , V_44 , 0x0 ) ;
}
F_3 ( V_2 , V_45 ,
( F_1 ( V_2 ,
V_45 ) & 0xC0 ) |
( V_11 -> V_12 [ 0 ] & 0x3F ) ) ;
F_3 ( V_2 , V_46 ,
( F_1 ( V_2 ,
V_46 ) & 0xC0 ) |
( V_11 -> V_12 [ 1 ] & 0x3F ) ) ;
F_3 ( V_2 , V_47 ,
( F_1 ( V_2 ,
V_47 ) & 0xC0 ) |
( V_11 -> V_12 [ 2 ] & 0x3F ) ) ;
F_3 ( V_2 , V_48 ,
( F_1 ( V_2 ,
V_48 ) & 0xC0 ) |
( V_11 -> V_12 [ 3 ] & 0x3F ) ) ;
F_3 ( V_2 , V_49 ,
( F_1 ( V_2 , V_49 ) & 0x3F ) |
( ( V_11 -> V_50 & 0x3 ) << 6 ) ) ;
F_3 ( V_2 , V_51 ,
( F_1 ( V_2 , V_51 ) & 0x1F ) |
( ( V_11 -> V_52 & 0x7 ) << 5 ) ) ;
F_28 ( V_5 , V_2 ) ;
return 0 ;
}
static int T_3 F_29 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_30 ( V_5 ) ;
struct V_28 * V_11 = V_2 -> V_11 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_31 ( V_8 ) ;
F_26 ( V_11 -> V_19 ) ;
F_26 ( V_11 -> V_20 ) ;
F_26 ( V_11 -> V_14 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_53 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_53 ) ;
}
