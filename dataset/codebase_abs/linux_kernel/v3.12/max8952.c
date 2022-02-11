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
static struct V_19 * F_12 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 = V_21 -> V_25 ;
int V_4 ;
int V_26 ;
V_22 = F_13 ( V_21 , sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 ) {
F_14 ( V_21 , L_1 ) ;
return NULL ;
}
V_22 -> V_16 = F_15 ( V_24 , L_2 , 0 ) ;
V_22 -> V_17 = F_15 ( V_24 , L_2 , 1 ) ;
V_22 -> V_28 = F_15 ( V_24 , L_3 , 0 ) ;
if ( F_16 ( V_24 , L_4 , & V_22 -> V_29 ) )
F_17 ( V_21 , L_5 ) ;
V_4 = F_18 ( V_24 , L_6 ,
V_22 -> V_12 , F_19 ( V_22 -> V_12 ) ) ;
if ( V_4 ) {
F_14 ( V_21 , L_7 ) ;
return NULL ;
}
for ( V_26 = 0 ; V_26 < F_19 ( V_22 -> V_12 ) ; ++ V_26 ) {
if ( V_22 -> V_12 [ V_26 ] < 770000 || V_22 -> V_12 [ V_26 ] > 1400000 ) {
F_14 ( V_21 , L_8 , V_26 ) ;
return NULL ;
}
V_22 -> V_12 [ V_26 ] = ( V_22 -> V_12 [ V_26 ] - 770000 ) / 10000 ;
}
if ( F_16 ( V_24 , L_9 , & V_22 -> V_30 ) )
F_17 ( V_21 , L_10 ) ;
if ( F_16 ( V_24 , L_11 , & V_22 -> V_31 ) )
F_17 ( V_21 , L_12 ) ;
V_22 -> V_32 = F_20 ( V_21 , V_24 ) ;
if ( ! V_22 -> V_32 ) {
F_14 ( V_21 , L_13 ) ;
return NULL ;
}
return V_22 ;
}
static struct V_19 * F_12 ( struct V_20 * V_21 )
{
return NULL ;
}
static int F_21 ( struct V_33 * V_5 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 = F_22 ( V_5 -> V_21 . V_38 ) ;
struct V_19 * V_11 = F_23 ( & V_5 -> V_21 ) ;
struct V_39 V_40 = { } ;
struct V_1 * V_2 ;
int V_4 = 0 , V_41 = 0 ;
if ( V_5 -> V_21 . V_25 )
V_11 = F_12 ( & V_5 -> V_21 ) ;
if ( ! V_11 ) {
F_14 ( & V_5 -> V_21 , L_14 ) ;
return - V_10 ;
}
if ( ! F_24 ( V_37 , V_42 ) )
return - V_43 ;
V_2 = F_13 ( & V_5 -> V_21 , sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_21 = & V_5 -> V_21 ;
V_2 -> V_11 = V_11 ;
V_40 . V_21 = V_2 -> V_21 ;
V_40 . V_45 = V_11 -> V_32 ;
V_40 . V_46 = V_2 ;
V_40 . V_25 = V_5 -> V_21 . V_25 ;
V_40 . V_47 = V_11 -> V_28 ;
if ( V_11 -> V_32 -> V_48 . V_49 )
V_40 . V_50 |= V_51 ;
V_2 -> V_8 = F_25 ( & V_52 , & V_40 ) ;
if ( F_26 ( V_2 -> V_8 ) ) {
V_4 = F_27 ( V_2 -> V_8 ) ;
F_14 ( V_2 -> V_21 , L_15 , V_4 ) ;
return V_4 ;
}
V_2 -> V_14 = V_11 -> V_29 & 0x1 ;
V_2 -> V_15 = ( V_11 -> V_29 >> 1 ) & 0x1 ;
if ( F_10 ( V_11 -> V_16 ) &&
F_10 ( V_11 -> V_17 ) ) {
if ( ! F_28 ( V_11 -> V_16 , L_16 ) )
F_29 ( V_11 -> V_16 ,
( V_11 -> V_29 ) & 0x1 ) ;
else
V_41 = 1 ;
if ( ! F_28 ( V_11 -> V_17 , L_17 ) )
F_29 ( V_11 -> V_17 ,
( V_11 -> V_29 >> 1 ) & 0x1 ) ;
else {
if ( ! V_41 )
F_30 ( V_11 -> V_16 ) ;
V_41 = 2 ;
}
} else
V_41 = 3 ;
if ( V_41 ) {
F_17 ( V_2 -> V_21 , L_18
L_19 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_11 -> V_16 = - 1 ;
V_11 -> V_17 = - 1 ;
F_3 ( V_2 , V_53 , 0x60 ) ;
F_14 ( V_2 -> V_21 , L_20
L_21 ) ;
} else {
F_3 ( V_2 , V_53 , 0x0 ) ;
}
F_3 ( V_2 , V_54 ,
( F_1 ( V_2 ,
V_54 ) & 0xC0 ) |
( V_11 -> V_12 [ 0 ] & 0x3F ) ) ;
F_3 ( V_2 , V_55 ,
( F_1 ( V_2 ,
V_55 ) & 0xC0 ) |
( V_11 -> V_12 [ 1 ] & 0x3F ) ) ;
F_3 ( V_2 , V_56 ,
( F_1 ( V_2 ,
V_56 ) & 0xC0 ) |
( V_11 -> V_12 [ 2 ] & 0x3F ) ) ;
F_3 ( V_2 , V_57 ,
( F_1 ( V_2 ,
V_57 ) & 0xC0 ) |
( V_11 -> V_12 [ 3 ] & 0x3F ) ) ;
F_3 ( V_2 , V_58 ,
( F_1 ( V_2 , V_58 ) & 0x3F ) |
( ( V_11 -> V_30 & 0x3 ) << 6 ) ) ;
F_3 ( V_2 , V_59 ,
( F_1 ( V_2 , V_59 ) & 0x1F ) |
( ( V_11 -> V_31 & 0x7 ) << 5 ) ) ;
F_31 ( V_5 , V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_33 * V_5 )
{
struct V_1 * V_2 = F_33 ( V_5 ) ;
struct V_19 * V_11 = V_2 -> V_11 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_34 ( V_8 ) ;
F_30 ( V_11 -> V_16 ) ;
F_30 ( V_11 -> V_17 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_60 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_60 ) ;
}
